/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_seventh_c4_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0365d4u: goto P_0c0365d4;
case 0x0c0365d6u: goto P_0c0365d6;
case 0x0c0365d8u: goto P_0c0365d8;
case 0x0c0365dau: goto P_0c0365da;
case 0x0c0365dcu: goto P_0c0365dc;
case 0x0c0365deu: goto P_0c0365de;
case 0x0c0365e0u: goto P_0c0365e0;
case 0x0c0365e2u: goto P_0c0365e2;
case 0x0c0365e4u: goto P_0c0365e4;
case 0x0c0365e6u: goto P_0c0365e6;
case 0x0c0365e8u: goto P_0c0365e8;
case 0x0c0365eau: goto P_0c0365ea;
case 0x0c0365ecu: goto P_0c0365ec;
case 0x0c0365eeu: goto P_0c0365ee;
case 0x0c0365f0u: goto P_0c0365f0;
case 0x0c0365f2u: goto P_0c0365f2;
case 0x0c0365f4u: goto P_0c0365f4;
case 0x0c0365f6u: goto P_0c0365f6;
case 0x0c0365f8u: goto P_0c0365f8;
case 0x0c0365fau: goto P_0c0365fa;
case 0x0c0365fcu: goto P_0c0365fc;
case 0x0c0365feu: goto P_0c0365fe;
case 0x0c036600u: goto P_0c036600;
case 0x0c03665eu: goto P_0c03665e;
case 0x0c036660u: goto P_0c036660;
case 0x0c036662u: goto P_0c036662;
case 0x0c036664u: goto P_0c036664;
case 0x0c036666u: goto P_0c036666;
case 0x0c036668u: goto P_0c036668;
case 0x0c03666au: goto P_0c03666a;
case 0x0c03666cu: goto P_0c03666c;
case 0x0c038760u: goto P_0c038760;
case 0x0c038762u: goto P_0c038762;
case 0x0c038764u: goto P_0c038764;
case 0x0c03f690u: goto P_0c03f690;
case 0x0c03f692u: goto P_0c03f692;
case 0x0c03f694u: goto P_0c03f694;
case 0x0c03f696u: goto P_0c03f696;
case 0x0c03f698u: goto P_0c03f698;
case 0x0c03f69au: goto P_0c03f69a;
case 0x0c03f69cu: goto P_0c03f69c;
case 0x0c03f69eu: goto P_0c03f69e;
case 0x0c03f6a0u: goto P_0c03f6a0;
case 0x0c03f6a2u: goto P_0c03f6a2;
case 0x0c03f6a4u: goto P_0c03f6a4;
case 0x0c03f6a6u: goto P_0c03f6a6;
case 0x0c03f6a8u: goto P_0c03f6a8;
case 0x0c03f6aau: goto P_0c03f6aa;
case 0x0c03f6acu: goto P_0c03f6ac;
case 0x0c03f6aeu: goto P_0c03f6ae;
case 0x0c03f6b0u: goto P_0c03f6b0;
case 0x0c03f6b2u: goto P_0c03f6b2;
case 0x0c03f6b4u: goto P_0c03f6b4;
case 0x0c03f6b6u: goto P_0c03f6b6;
case 0x0c03f6b8u: goto P_0c03f6b8;
case 0x0c03f6c0u: goto P_0c03f6c0;
case 0x0c03f6c2u: goto P_0c03f6c2;
case 0x0c03f6c4u: goto P_0c03f6c4;
case 0x0c03f6c6u: goto P_0c03f6c6;
case 0x0c03f6c8u: goto P_0c03f6c8;
case 0x0c03f6cau: goto P_0c03f6ca;
case 0x0c03f6ccu: goto P_0c03f6cc;
case 0x0c03f6ceu: goto P_0c03f6ce;
case 0x0c03f6d0u: goto P_0c03f6d0;
case 0x0c03f6d2u: goto P_0c03f6d2;
case 0x0c03f6d4u: goto P_0c03f6d4;
case 0x0c03f6d6u: goto P_0c03f6d6;
case 0x0c03f6d8u: goto P_0c03f6d8;
case 0x0c03f6dau: goto P_0c03f6da;
case 0x0c03f6dcu: goto P_0c03f6dc;
case 0x0c03f6deu: goto P_0c03f6de;
case 0x0c03f6e0u: goto P_0c03f6e0;
case 0x0c03f6e2u: goto P_0c03f6e2;
case 0x0c03f6e4u: goto P_0c03f6e4;
case 0x0c03f6e6u: goto P_0c03f6e6;
case 0x0c03f6e8u: goto P_0c03f6e8;
case 0x0c03f6eau: goto P_0c03f6ea;
case 0x0c03f6ecu: goto P_0c03f6ec;
case 0x0c03f6eeu: goto P_0c03f6ee;
case 0x0c03f6f0u: goto P_0c03f6f0;
case 0x0c03f6f2u: goto P_0c03f6f2;
case 0x0c03f6f4u: goto P_0c03f6f4;
case 0x0c03f6f6u: goto P_0c03f6f6;
case 0x0c03f6f8u: goto P_0c03f6f8;
case 0x0c03f6fau: goto P_0c03f6fa;
case 0x0c03f6fcu: goto P_0c03f6fc;
case 0x0c03f6feu: goto P_0c03f6fe;
case 0x0c03f700u: goto P_0c03f700;
case 0x0c03f702u: goto P_0c03f702;
case 0x0c03f704u: goto P_0c03f704;
case 0x0c03f706u: goto P_0c03f706;
case 0x0c03f708u: goto P_0c03f708;
case 0x0c03f70au: goto P_0c03f70a;
case 0x0c03f70cu: goto P_0c03f70c;
case 0x0c03f70eu: goto P_0c03f70e;
case 0x0c03f710u: goto P_0c03f710;
case 0x0c03f712u: goto P_0c03f712;
case 0x0c03f714u: goto P_0c03f714;
case 0x0c03f716u: goto P_0c03f716;
case 0x0c03f718u: goto P_0c03f718;
case 0x0c03f71au: goto P_0c03f71a;
case 0x0c03f71cu: goto P_0c03f71c;
case 0x0c03f71eu: goto P_0c03f71e;
case 0x0c03f720u: goto P_0c03f720;
case 0x0c03f722u: goto P_0c03f722;
case 0x0c03f724u: goto P_0c03f724;
case 0x0c03f726u: goto P_0c03f726;
case 0x0c03f728u: goto P_0c03f728;
case 0x0c03f72au: goto P_0c03f72a;
case 0x0c03f72cu: goto P_0c03f72c;
case 0x0c03f72eu: goto P_0c03f72e;
case 0x0c03f730u: goto P_0c03f730;
case 0x0c03f732u: goto P_0c03f732;
case 0x0c03f734u: goto P_0c03f734;
case 0x0c03f736u: goto P_0c03f736;
case 0x0c03f738u: goto P_0c03f738;
case 0x0c03f73au: goto P_0c03f73a;
case 0x0c03f73cu: goto P_0c03f73c;
case 0x0c03f73eu: goto P_0c03f73e;
case 0x0c03f740u: goto P_0c03f740;
case 0x0c03f742u: goto P_0c03f742;
case 0x0c03f744u: goto P_0c03f744;
case 0x0c03f746u: goto P_0c03f746;
case 0x0c03f748u: goto P_0c03f748;
case 0x0c03f74au: goto P_0c03f74a;
case 0x0c03f74cu: goto P_0c03f74c;
case 0x0c03f74eu: goto P_0c03f74e;
case 0x0c03f750u: goto P_0c03f750;
case 0x0c03f752u: goto P_0c03f752;
case 0x0c03f754u: goto P_0c03f754;
case 0x0c03f756u: goto P_0c03f756;
case 0x0c03f758u: goto P_0c03f758;
case 0x0c03f75au: goto P_0c03f75a;
case 0x0c03f75cu: goto P_0c03f75c;
case 0x0c03f75eu: goto P_0c03f75e;
case 0x0c03f760u: goto P_0c03f760;
case 0x0c03f762u: goto P_0c03f762;
case 0x0c03f764u: goto P_0c03f764;
case 0x0c03fda0u: goto P_0c03fda0;
case 0x0c03fda2u: goto P_0c03fda2;
case 0x0c03fda4u: goto P_0c03fda4;
case 0x0c03fda6u: goto P_0c03fda6;
case 0x0c03fda8u: goto P_0c03fda8;
case 0x0c03fdaau: goto P_0c03fdaa;
case 0x0c03fdacu: goto P_0c03fdac;
case 0x0c03fdaeu: goto P_0c03fdae;
case 0x0c03fdb0u: goto P_0c03fdb0;
case 0x0c03fdb2u: goto P_0c03fdb2;
case 0x0c03fdb4u: goto P_0c03fdb4;
case 0x0c03fdb6u: goto P_0c03fdb6;
case 0x0c03fdb8u: goto P_0c03fdb8;
case 0x0c03fdbau: goto P_0c03fdba;
case 0x0c03fdbcu: goto P_0c03fdbc;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c042f3au: goto P_0c042f3a;
case 0x0c042f3cu: goto P_0c042f3c;
case 0x0c042f3eu: goto P_0c042f3e;
case 0x0c042f40u: goto P_0c042f40;
case 0x0c042f42u: goto P_0c042f42;
case 0x0c042f44u: goto P_0c042f44;
case 0x0c042f46u: goto P_0c042f46;
case 0x0c042f48u: goto P_0c042f48;
case 0x0c042f4au: goto P_0c042f4a;
case 0x0c042f4cu: goto P_0c042f4c;
case 0x0c042f4eu: goto P_0c042f4e;
case 0x0c042f50u: goto P_0c042f50;
case 0x0c042f52u: goto P_0c042f52;
case 0x0c042f54u: goto P_0c042f54;
case 0x0c042f56u: goto P_0c042f56;
case 0x0c042f58u: goto P_0c042f58;
case 0x0c042f5au: goto P_0c042f5a;
case 0x0c043eb8u: goto P_0c043eb8;
case 0x0c043ebau: goto P_0c043eba;
case 0x0c043ebcu: goto P_0c043ebc;
case 0x0c043ebeu: goto P_0c043ebe;
case 0x0c043ec0u: goto P_0c043ec0;
case 0x0c043ec2u: goto P_0c043ec2;
case 0x0c043ec4u: goto P_0c043ec4;
case 0x0c043ec6u: goto P_0c043ec6;
case 0x0c043ec8u: goto P_0c043ec8;
case 0x0c043ecau: goto P_0c043eca;
case 0x0c043eccu: goto P_0c043ecc;
case 0x0c043eceu: goto P_0c043ece;
case 0x0c043ed0u: goto P_0c043ed0;
case 0x0c043ed2u: goto P_0c043ed2;
case 0x0c043ed4u: goto P_0c043ed4;
case 0x0c043ed6u: goto P_0c043ed6;
case 0x0c043ed8u: goto P_0c043ed8;
case 0x0c0441aau: goto P_0c0441aa;
case 0x0c0441acu: goto P_0c0441ac;
case 0x0c0441aeu: goto P_0c0441ae;
case 0x0c053cecu: goto P_0c053cec;
case 0x0c053ceeu: goto P_0c053cee;
case 0x0c053cf0u: goto P_0c053cf0;
case 0x0c053cf2u: goto P_0c053cf2;
case 0x0c053cf4u: goto P_0c053cf4;
case 0x0c053cf6u: goto P_0c053cf6;
case 0x0c053cf8u: goto P_0c053cf8;
case 0x0c053cfau: goto P_0c053cfa;
case 0x0c053cfcu: goto P_0c053cfc;
case 0x0c053cfeu: goto P_0c053cfe;
case 0x0c053d00u: goto P_0c053d00;
case 0x0c053d02u: goto P_0c053d02;
case 0x0c053d04u: goto P_0c053d04;
case 0x0c053d06u: goto P_0c053d06;
case 0x0c053d08u: goto P_0c053d08;
case 0x0c053d0au: goto P_0c053d0a;
case 0x0c053d0cu: goto P_0c053d0c;
case 0x0c053d0eu: goto P_0c053d0e;
case 0x0c053d10u: goto P_0c053d10;
case 0x0c053d12u: goto P_0c053d12;
case 0x0c053d14u: goto P_0c053d14;
case 0x0c053d16u: goto P_0c053d16;
case 0x0c053d18u: goto P_0c053d18;
case 0x0c053d1au: goto P_0c053d1a;
case 0x0c053d1cu: goto P_0c053d1c;
case 0x0c053d1eu: goto P_0c053d1e;
case 0x0c053d20u: goto P_0c053d20;
case 0x0c053d22u: goto P_0c053d22;
case 0x0c053d24u: goto P_0c053d24;
case 0x0c053d26u: goto P_0c053d26;
case 0x0c053d28u: goto P_0c053d28;
case 0x0c053d2au: goto P_0c053d2a;
case 0x0c053d2cu: goto P_0c053d2c;
case 0x0c053d2eu: goto P_0c053d2e;
case 0x0c05ece2u: goto P_0c05ece2;
case 0x0c05ece4u: goto P_0c05ece4;
case 0x0c05ece6u: goto P_0c05ece6;
case 0x0c05ece8u: goto P_0c05ece8;
case 0x0c05eceau: goto P_0c05ecea;
case 0x0c05ececu: goto P_0c05ecec;
case 0x0c05eceeu: goto P_0c05ecee;
case 0x0c05ecf0u: goto P_0c05ecf0;
case 0x0c05ecf2u: goto P_0c05ecf2;
case 0x0c05ecf4u: goto P_0c05ecf4;
case 0x0c05ecf6u: goto P_0c05ecf6;
case 0x0c05ecf8u: goto P_0c05ecf8;
case 0x0c05ecfau: goto P_0c05ecfa;
case 0x0c05ecfcu: goto P_0c05ecfc;
case 0x0c05ecfeu: goto P_0c05ecfe;
case 0x0c05ed00u: goto P_0c05ed00;
case 0x0c05ed02u: goto P_0c05ed02;
case 0x0c05ed04u: goto P_0c05ed04;
case 0x0c061596u: goto P_0c061596;
case 0x0c061598u: goto P_0c061598;
case 0x0c06159au: goto P_0c06159a;
case 0x0c06159cu: goto P_0c06159c;
case 0x0c06159eu: goto P_0c06159e;
case 0x0c0615a0u: goto P_0c0615a0;
case 0x0c0615a2u: goto P_0c0615a2;
case 0x0c0615a4u: goto P_0c0615a4;
case 0x0c0615a6u: goto P_0c0615a6;
case 0x0c0615a8u: goto P_0c0615a8;
case 0x0c0615aau: goto P_0c0615aa;
case 0x0c0615acu: goto P_0c0615ac;
case 0x0c0615aeu: goto P_0c0615ae;
case 0x0c0615b0u: goto P_0c0615b0;
case 0x0c0615b2u: goto P_0c0615b2;
case 0x0c0615b4u: goto P_0c0615b4;
case 0x0c0615b6u: goto P_0c0615b6;
case 0x0c0615b8u: goto P_0c0615b8;
case 0x0c0615bau: goto P_0c0615ba;
case 0x0c0615bcu: goto P_0c0615bc;
case 0x0c0615beu: goto P_0c0615be;
case 0x0c0615c0u: goto P_0c0615c0;
case 0x0c0615c2u: goto P_0c0615c2;
case 0x0c0615c4u: goto P_0c0615c4;
case 0x0c0615c6u: goto P_0c0615c6;
case 0x0c0615c8u: goto P_0c0615c8;
case 0x0c0615cau: goto P_0c0615ca;
case 0x0c0615ccu: goto P_0c0615cc;
case 0x0c0615ceu: goto P_0c0615ce;
case 0x0c0615d0u: goto P_0c0615d0;
case 0x0c0615d2u: goto P_0c0615d2;
case 0x0c0615d4u: goto P_0c0615d4;
case 0x0c0615d6u: goto P_0c0615d6;
case 0x0c0615d8u: goto P_0c0615d8;
case 0x0c0615dau: goto P_0c0615da;
case 0x0c0615dcu: goto P_0c0615dc;
case 0x0c0615deu: goto P_0c0615de;
case 0x0c061608u: goto P_0c061608;
case 0x0c06160au: goto P_0c06160a;
case 0x0c06160cu: goto P_0c06160c;
case 0x0c06160eu: goto P_0c06160e;
case 0x0c061610u: goto P_0c061610;
case 0x0c061612u: goto P_0c061612;
case 0x0c061614u: goto P_0c061614;
case 0x0c061616u: goto P_0c061616;
case 0x0c061618u: goto P_0c061618;
case 0x0c06161au: goto P_0c06161a;
case 0x0c06161cu: goto P_0c06161c;
case 0x0c06161eu: goto P_0c06161e;
case 0x0c061620u: goto P_0c061620;
case 0x0c061622u: goto P_0c061622;
case 0x0c061624u: goto P_0c061624;
case 0x0c061626u: goto P_0c061626;
case 0x0c061628u: goto P_0c061628;
case 0x0c06162au: goto P_0c06162a;
case 0x0c06162cu: goto P_0c06162c;
case 0x0c06162eu: goto P_0c06162e;
case 0x0c061630u: goto P_0c061630;
case 0x0c061632u: goto P_0c061632;
case 0x0c061634u: goto P_0c061634;
case 0x0c061636u: goto P_0c061636;
case 0x0c061638u: goto P_0c061638;
case 0x0c06163au: goto P_0c06163a;
case 0x0c06163cu: goto P_0c06163c;
case 0x0c06163eu: goto P_0c06163e;
case 0x0c061640u: goto P_0c061640;
case 0x0c061642u: goto P_0c061642;
case 0x0c061674u: goto P_0c061674;
case 0x0c061676u: goto P_0c061676;
case 0x0c061678u: goto P_0c061678;
case 0x0c06167au: goto P_0c06167a;
case 0x0c06167cu: goto P_0c06167c;
case 0x0c06167eu: goto P_0c06167e;
case 0x0c061680u: goto P_0c061680;
case 0x0c061682u: goto P_0c061682;
case 0x0c061684u: goto P_0c061684;
case 0x0c061686u: goto P_0c061686;
case 0x0c061688u: goto P_0c061688;
case 0x0c06168au: goto P_0c06168a;
case 0x0c06168cu: goto P_0c06168c;
case 0x0c06168eu: goto P_0c06168e;
case 0x0c061690u: goto P_0c061690;
case 0x0c061692u: goto P_0c061692;
case 0x0c061694u: goto P_0c061694;
case 0x0c061696u: goto P_0c061696;
case 0x0c061698u: goto P_0c061698;
case 0x0c06169au: goto P_0c06169a;
case 0x0c06169cu: goto P_0c06169c;
case 0x0c06169eu: goto P_0c06169e;
case 0x0c0616a0u: goto P_0c0616a0;
case 0x0c0616a2u: goto P_0c0616a2;
case 0x0c0616a4u: goto P_0c0616a4;
case 0x0c0616a6u: goto P_0c0616a6;
case 0x0c0616a8u: goto P_0c0616a8;
case 0x0c0616aau: goto P_0c0616aa;
case 0x0c0616acu: goto P_0c0616ac;
case 0x0c0616aeu: goto P_0c0616ae;
case 0x0c0616b0u: goto P_0c0616b0;
case 0x0c0616b2u: goto P_0c0616b2;
case 0x0c0616b4u: goto P_0c0616b4;
case 0x0c0616b6u: goto P_0c0616b6;
case 0x0c0616b8u: goto P_0c0616b8;
case 0x0c0616bau: goto P_0c0616ba;
case 0x0c0616bcu: goto P_0c0616bc;
case 0x0c0616beu: goto P_0c0616be;
case 0x0c0616c0u: goto P_0c0616c0;
case 0x0c0616c2u: goto P_0c0616c2;
case 0x0c0616c4u: goto P_0c0616c4;
case 0x0c0616c6u: goto P_0c0616c6;
case 0x0c0616c8u: goto P_0c0616c8;
case 0x0c0616cau: goto P_0c0616ca;
case 0x0c0616ccu: goto P_0c0616cc;
case 0x0c0616ceu: goto P_0c0616ce;
case 0x0c0616d0u: goto P_0c0616d0;
case 0x0c0616d2u: goto P_0c0616d2;
case 0x0c0616d4u: goto P_0c0616d4;
case 0x0c0616d6u: goto P_0c0616d6;
case 0x0c0616d8u: goto P_0c0616d8;
case 0x0c0616dau: goto P_0c0616da;
case 0x0c0616dcu: goto P_0c0616dc;
case 0x0c0616deu: goto P_0c0616de;
case 0x0c0616e0u: goto P_0c0616e0;
case 0x0c0616e2u: goto P_0c0616e2;
case 0x0c0616e4u: goto P_0c0616e4;
case 0x0c0616e6u: goto P_0c0616e6;
case 0x0c0616e8u: goto P_0c0616e8;
case 0x0c0616eau: goto P_0c0616ea;
case 0x0c0616ecu: goto P_0c0616ec;
case 0x0c0616eeu: goto P_0c0616ee;
case 0x0c0616f0u: goto P_0c0616f0;
case 0x0c0616f2u: goto P_0c0616f2;
case 0x0c0616f4u: goto P_0c0616f4;
case 0x0c0616f6u: goto P_0c0616f6;
case 0x0c0616f8u: goto P_0c0616f8;
case 0x0c0616fau: goto P_0c0616fa;
case 0x0c0616fcu: goto P_0c0616fc;
case 0x0c0616feu: goto P_0c0616fe;
case 0x0c061700u: goto P_0c061700;
case 0x0c061702u: goto P_0c061702;
case 0x0c061704u: goto P_0c061704;
case 0x0c061706u: goto P_0c061706;
case 0x0c061708u: goto P_0c061708;
case 0x0c06170au: goto P_0c06170a;
case 0x0c06170cu: goto P_0c06170c;
case 0x0c06170eu: goto P_0c06170e;
case 0x0c061710u: goto P_0c061710;
case 0x0c061712u: goto P_0c061712;
case 0x0c061714u: goto P_0c061714;
case 0x0c061716u: goto P_0c061716;
case 0x0c061718u: goto P_0c061718;
case 0x0c06171au: goto P_0c06171a;
case 0x0c06171cu: goto P_0c06171c;
case 0x0c06171eu: goto P_0c06171e;
case 0x0c061720u: goto P_0c061720;
case 0x0c061722u: goto P_0c061722;
case 0x0c061724u: goto P_0c061724;
case 0x0c061726u: goto P_0c061726;
case 0x0c061728u: goto P_0c061728;
case 0x0c06172au: goto P_0c06172a;
case 0x0c06172cu: goto P_0c06172c;
case 0x0c06172eu: goto P_0c06172e;
case 0x0c061730u: goto P_0c061730;
case 0x0c061732u: goto P_0c061732;
case 0x0c061734u: goto P_0c061734;
case 0x0c061736u: goto P_0c061736;
case 0x0c061738u: goto P_0c061738;
case 0x0c06173au: goto P_0c06173a;
case 0x0c06173cu: goto P_0c06173c;
case 0x0c06173eu: goto P_0c06173e;
case 0x0c061740u: goto P_0c061740;
case 0x0c061742u: goto P_0c061742;
case 0x0c061744u: goto P_0c061744;
case 0x0c061746u: goto P_0c061746;
case 0x0c06233eu: goto P_0c06233e;
case 0x0c062340u: goto P_0c062340;
case 0x0c062342u: goto P_0c062342;
case 0x0c062344u: goto P_0c062344;
case 0x0c062346u: goto P_0c062346;
case 0x0c062348u: goto P_0c062348;
case 0x0c06234au: goto P_0c06234a;
case 0x0c06234cu: goto P_0c06234c;
case 0x0c06234eu: goto P_0c06234e;
case 0x0c062350u: goto P_0c062350;
case 0x0c062352u: goto P_0c062352;
case 0x0c062354u: goto P_0c062354;
case 0x0c062356u: goto P_0c062356;
case 0x0c062358u: goto P_0c062358;
case 0x0c06235au: goto P_0c06235a;
case 0x0c06235cu: goto P_0c06235c;
case 0x0c06235eu: goto P_0c06235e;
case 0x0c062360u: goto P_0c062360;
case 0x0c062362u: goto P_0c062362;
case 0x0c062364u: goto P_0c062364;
case 0x0c062366u: goto P_0c062366;
case 0x0c062368u: goto P_0c062368;
case 0x0c06236au: goto P_0c06236a;
case 0x0c06236cu: goto P_0c06236c;
case 0x0c06236eu: goto P_0c06236e;
case 0x0c062370u: goto P_0c062370;
case 0x0c062372u: goto P_0c062372;
case 0x0c062374u: goto P_0c062374;
case 0x0c062376u: goto P_0c062376;
case 0x0c062378u: goto P_0c062378;
case 0x0c06237au: goto P_0c06237a;
case 0x0c062390u: goto P_0c062390;
case 0x0c062392u: goto P_0c062392;
case 0x0c062394u: goto P_0c062394;
case 0x0c062396u: goto P_0c062396;
case 0x0c062398u: goto P_0c062398;
case 0x0c06239au: goto P_0c06239a;
case 0x0c06239cu: goto P_0c06239c;
case 0x0c06239eu: goto P_0c06239e;
case 0x0c0623a0u: goto P_0c0623a0;
case 0x0c0623a2u: goto P_0c0623a2;
case 0x0c0623a4u: goto P_0c0623a4;
case 0x0c0623a6u: goto P_0c0623a6;
case 0x0c0623a8u: goto P_0c0623a8;
case 0x0c0623aau: goto P_0c0623aa;
case 0x0c0623acu: goto P_0c0623ac;
case 0x0c0623aeu: goto P_0c0623ae;
case 0x0c0623b0u: goto P_0c0623b0;
case 0x0c0623b2u: goto P_0c0623b2;
case 0x0c0623b4u: goto P_0c0623b4;
case 0x0c0623b6u: goto P_0c0623b6;
case 0x0c0623b8u: goto P_0c0623b8;
case 0x0c0623bau: goto P_0c0623ba;
case 0x0c0623bcu: goto P_0c0623bc;
case 0x0c0623beu: goto P_0c0623be;
case 0x0c0623c0u: goto P_0c0623c0;
case 0x0c0623c2u: goto P_0c0623c2;
case 0x0c0623c4u: goto P_0c0623c4;
case 0x0c0623c6u: goto P_0c0623c6;
case 0x0c0623c8u: goto P_0c0623c8;
case 0x0c0623cau: goto P_0c0623ca;
case 0x0c0623ccu: goto P_0c0623cc;
case 0x0c0623ceu: goto P_0c0623ce;
case 0x0c0623d0u: goto P_0c0623d0;
case 0x0c0623d2u: goto P_0c0623d2;
case 0x0c0623d4u: goto P_0c0623d4;
case 0x0c0623d6u: goto P_0c0623d6;
case 0x0c0623d8u: goto P_0c0623d8;
case 0x0c0623dau: goto P_0c0623da;
case 0x0c0623dcu: goto P_0c0623dc;
case 0x0c0623deu: goto P_0c0623de;
case 0x0c0623e0u: goto P_0c0623e0;
case 0x0c0623e2u: goto P_0c0623e2;
case 0x0c0623e4u: goto P_0c0623e4;
case 0x0c0623e6u: goto P_0c0623e6;
case 0x0c0623e8u: goto P_0c0623e8;
case 0x0c0623eau: goto P_0c0623ea;
case 0x0c0623ecu: goto P_0c0623ec;
case 0x0c0623eeu: goto P_0c0623ee;
case 0x0c0623f0u: goto P_0c0623f0;
case 0x0c0623f2u: goto P_0c0623f2;
case 0x0c0623f4u: goto P_0c0623f4;
case 0x0c0623f6u: goto P_0c0623f6;
case 0x0c0623f8u: goto P_0c0623f8;
case 0x0c0623fau: goto P_0c0623fa;
case 0x0c0623fcu: goto P_0c0623fc;
case 0x0c0623feu: goto P_0c0623fe;
case 0x0c062400u: goto P_0c062400;
case 0x0c062402u: goto P_0c062402;
case 0x0c062404u: goto P_0c062404;
case 0x0c062406u: goto P_0c062406;
case 0x0c062408u: goto P_0c062408;
case 0x0c06240au: goto P_0c06240a;
case 0x0c06240cu: goto P_0c06240c;
case 0x0c06240eu: goto P_0c06240e;
case 0x0c062410u: goto P_0c062410;
case 0x0c062412u: goto P_0c062412;
case 0x0c062414u: goto P_0c062414;
case 0x0c062416u: goto P_0c062416;
case 0x0c062418u: goto P_0c062418;
case 0x0c06241au: goto P_0c06241a;
case 0x0c06241cu: goto P_0c06241c;
case 0x0c06241eu: goto P_0c06241e;
case 0x0c062420u: goto P_0c062420;
case 0x0c062422u: goto P_0c062422;
case 0x0c062424u: goto P_0c062424;
case 0x0c062426u: goto P_0c062426;
case 0x0c062428u: goto P_0c062428;
case 0x0c06242au: goto P_0c06242a;
case 0x0c06242cu: goto P_0c06242c;
case 0x0c06242eu: goto P_0c06242e;
case 0x0c062430u: goto P_0c062430;
case 0x0c062432u: goto P_0c062432;
case 0x0c062434u: goto P_0c062434;
case 0x0c062436u: goto P_0c062436;
case 0x0c062438u: goto P_0c062438;
case 0x0c06243au: goto P_0c06243a;
case 0x0c06243cu: goto P_0c06243c;
case 0x0c06243eu: goto P_0c06243e;
case 0x0c062440u: goto P_0c062440;
case 0x0c062442u: goto P_0c062442;
case 0x0c062444u: goto P_0c062444;
case 0x0c062446u: goto P_0c062446;
case 0x0c062448u: goto P_0c062448;
case 0x0c06244au: goto P_0c06244a;
case 0x0c06244cu: goto P_0c06244c;
case 0x0c06244eu: goto P_0c06244e;
case 0x0c062450u: goto P_0c062450;
case 0x0c062452u: goto P_0c062452;
case 0x0c062454u: goto P_0c062454;
case 0x0c062456u: goto P_0c062456;
case 0x0c062458u: goto P_0c062458;
case 0x0c06245au: goto P_0c06245a;
case 0x0c06245cu: goto P_0c06245c;
case 0x0c06245eu: goto P_0c06245e;
case 0x0c062460u: goto P_0c062460;
case 0x0c062462u: goto P_0c062462;
case 0x0c062464u: goto P_0c062464;
case 0x0c062466u: goto P_0c062466;
case 0x0c062468u: goto P_0c062468;
case 0x0c06246au: goto P_0c06246a;
case 0x0c06246cu: goto P_0c06246c;
case 0x0c06246eu: goto P_0c06246e;
case 0x0c062470u: goto P_0c062470;
case 0x0c062472u: goto P_0c062472;
case 0x0c062474u: goto P_0c062474;
case 0x0c062476u: goto P_0c062476;
case 0x0c062478u: goto P_0c062478;
case 0x0c06247au: goto P_0c06247a;
case 0x0c06247cu: goto P_0c06247c;
case 0x0c06247eu: goto P_0c06247e;
case 0x0c062480u: goto P_0c062480;
case 0x0c062482u: goto P_0c062482;
case 0x0c062484u: goto P_0c062484;
case 0x0c062486u: goto P_0c062486;
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c070c58u: goto P_0c070c58;
case 0x0c070c5au: goto P_0c070c5a;
case 0x0c070c5cu: goto P_0c070c5c;
case 0x0c070c5eu: goto P_0c070c5e;
case 0x0c070c60u: goto P_0c070c60;
case 0x0c070c62u: goto P_0c070c62;
case 0x0c070c64u: goto P_0c070c64;
case 0x0c070c66u: goto P_0c070c66;
case 0x0c070c68u: goto P_0c070c68;
case 0x0c070c6au: goto P_0c070c6a;
case 0x0c070c6cu: goto P_0c070c6c;
case 0x0c070c6eu: goto P_0c070c6e;
case 0x0c070c70u: goto P_0c070c70;
case 0x0c070c72u: goto P_0c070c72;
case 0x0c070c74u: goto P_0c070c74;
case 0x0c070c76u: goto P_0c070c76;
case 0x0c070c78u: goto P_0c070c78;
case 0x0c070c7au: goto P_0c070c7a;
case 0x0c070c7cu: goto P_0c070c7c;
case 0x0c070c7eu: goto P_0c070c7e;
case 0x0c070c80u: goto P_0c070c80;
case 0x0c070c82u: goto P_0c070c82;
case 0x0c070c84u: goto P_0c070c84;
case 0x0c070c86u: goto P_0c070c86;
case 0x0c070c88u: goto P_0c070c88;
case 0x0c070c90u: goto P_0c070c90;
case 0x0c070c92u: goto P_0c070c92;
case 0x0c070c94u: goto P_0c070c94;
case 0x0c070c96u: goto P_0c070c96;
case 0x0c070c98u: goto P_0c070c98;
case 0x0c070c9au: goto P_0c070c9a;
case 0x0c070c9cu: goto P_0c070c9c;
case 0x0c070c9eu: goto P_0c070c9e;
case 0x0c070ca0u: goto P_0c070ca0;
case 0x0c070ca2u: goto P_0c070ca2;
case 0x0c070ca4u: goto P_0c070ca4;
case 0x0c070ca6u: goto P_0c070ca6;
case 0x0c070ca8u: goto P_0c070ca8;
case 0x0c070caau: goto P_0c070caa;
case 0x0c070cacu: goto P_0c070cac;
case 0x0c070caeu: goto P_0c070cae;
case 0x0c070cb0u: goto P_0c070cb0;
case 0x0c070cb2u: goto P_0c070cb2;
case 0x0c070cb4u: goto P_0c070cb4;
case 0x0c070cb6u: goto P_0c070cb6;
case 0x0c070cb8u: goto P_0c070cb8;
case 0x0c070cbau: goto P_0c070cba;
case 0x0c070cbcu: goto P_0c070cbc;
case 0x0c070cbeu: goto P_0c070cbe;
case 0x0c070cc0u: goto P_0c070cc0;
case 0x0c070cc2u: goto P_0c070cc2;
case 0x0c070cc4u: goto P_0c070cc4;
case 0x0c070cc6u: goto P_0c070cc6;
case 0x0c070cc8u: goto P_0c070cc8;
case 0x0c070ccau: goto P_0c070cca;
case 0x0c070cccu: goto P_0c070ccc;
case 0x0c070cceu: goto P_0c070cce;
case 0x0c070cd0u: goto P_0c070cd0;
case 0x0c070cd2u: goto P_0c070cd2;
case 0x0c070cd4u: goto P_0c070cd4;
case 0x0c070cd6u: goto P_0c070cd6;
case 0x0c070cd8u: goto P_0c070cd8;
case 0x0c070cdau: goto P_0c070cda;
case 0x0c070cdcu: goto P_0c070cdc;
case 0x0c070cdeu: goto P_0c070cde;
case 0x0c070ce0u: goto P_0c070ce0;
case 0x0c070ce2u: goto P_0c070ce2;
case 0x0c070ce4u: goto P_0c070ce4;
case 0x0c070ce6u: goto P_0c070ce6;
case 0x0c070ce8u: goto P_0c070ce8;
case 0x0c070ceau: goto P_0c070cea;
case 0x0c070cecu: goto P_0c070cec;
case 0x0c070ceeu: goto P_0c070cee;
case 0x0c070cf0u: goto P_0c070cf0;
case 0x0c070cf2u: goto P_0c070cf2;
case 0x0c070cf4u: goto P_0c070cf4;
case 0x0c070cf6u: goto P_0c070cf6;
case 0x0c070cf8u: goto P_0c070cf8;
case 0x0c070cfau: goto P_0c070cfa;
case 0x0c070cfcu: goto P_0c070cfc;
case 0x0c070cfeu: goto P_0c070cfe;
case 0x0c070d00u: goto P_0c070d00;
case 0x0c070d02u: goto P_0c070d02;
case 0x0c070d04u: goto P_0c070d04;
case 0x0c070d06u: goto P_0c070d06;
case 0x0c070d08u: goto P_0c070d08;
case 0x0c070d0au: goto P_0c070d0a;
case 0x0c070d0cu: goto P_0c070d0c;
case 0x0c070d0eu: goto P_0c070d0e;
case 0x0c070d10u: goto P_0c070d10;
case 0x0c070d12u: goto P_0c070d12;
case 0x0c070d14u: goto P_0c070d14;
case 0x0c070d16u: goto P_0c070d16;
case 0x0c070d18u: goto P_0c070d18;
case 0x0c070d1au: goto P_0c070d1a;
case 0x0c070d1cu: goto P_0c070d1c;
case 0x0c070d1eu: goto P_0c070d1e;
case 0x0c070d24u: goto P_0c070d24;
case 0x0c070d26u: goto P_0c070d26;
case 0x0c070d28u: goto P_0c070d28;
case 0x0c070d2au: goto P_0c070d2a;
case 0x0c070d2cu: goto P_0c070d2c;
case 0x0c070d2eu: goto P_0c070d2e;
case 0x0c070d30u: goto P_0c070d30;
case 0x0c070d32u: goto P_0c070d32;
case 0x0c070d34u: goto P_0c070d34;
case 0x0c070d36u: goto P_0c070d36;
case 0x0c070d38u: goto P_0c070d38;
case 0x0c070d3au: goto P_0c070d3a;
case 0x0c070d3cu: goto P_0c070d3c;
case 0x0c070d3eu: goto P_0c070d3e;
case 0x0c070d40u: goto P_0c070d40;
case 0x0c070d42u: goto P_0c070d42;
case 0x0c070d44u: goto P_0c070d44;
case 0x0c070d46u: goto P_0c070d46;
case 0x0c070d48u: goto P_0c070d48;
case 0x0c070d4au: goto P_0c070d4a;
case 0x0c070d4cu: goto P_0c070d4c;
case 0x0c070d4eu: goto P_0c070d4e;
case 0x0c070d50u: goto P_0c070d50;
case 0x0c070d52u: goto P_0c070d52;
case 0x0c070d54u: goto P_0c070d54;
case 0x0c070d56u: goto P_0c070d56;
case 0x0c070d58u: goto P_0c070d58;
case 0x0c070d5au: goto P_0c070d5a;
case 0x0c070d5cu: goto P_0c070d5c;
case 0x0c070d5eu: goto P_0c070d5e;
case 0x0c070d60u: goto P_0c070d60;
case 0x0c070d62u: goto P_0c070d62;
case 0x0c070d64u: goto P_0c070d64;
case 0x0c070d66u: goto P_0c070d66;
case 0x0c070d68u: goto P_0c070d68;
case 0x0c070d6au: goto P_0c070d6a;
case 0x0c070d70u: goto P_0c070d70;
case 0x0c070d72u: goto P_0c070d72;
case 0x0c070d74u: goto P_0c070d74;
case 0x0c070d76u: goto P_0c070d76;
case 0x0c070d78u: goto P_0c070d78;
case 0x0c070d7au: goto P_0c070d7a;
case 0x0c070d7cu: goto P_0c070d7c;
case 0x0c070d7eu: goto P_0c070d7e;
case 0x0c070d80u: goto P_0c070d80;
case 0x0c070d82u: goto P_0c070d82;
case 0x0c070d84u: goto P_0c070d84;
case 0x0c070d86u: goto P_0c070d86;
case 0x0c070d88u: goto P_0c070d88;
case 0x0c070d8au: goto P_0c070d8a;
case 0x0c070d8cu: goto P_0c070d8c;
case 0x0c070d8eu: goto P_0c070d8e;
case 0x0c070d90u: goto P_0c070d90;
case 0x0c070d92u: goto P_0c070d92;
case 0x0c070d94u: goto P_0c070d94;
case 0x0c070d96u: goto P_0c070d96;
case 0x0c070d98u: goto P_0c070d98;
case 0x0c070d9au: goto P_0c070d9a;
case 0x0c070d9cu: goto P_0c070d9c;
case 0x0c070d9eu: goto P_0c070d9e;
case 0x0c070da0u: goto P_0c070da0;
case 0x0c070da2u: goto P_0c070da2;
case 0x0c070da4u: goto P_0c070da4;
case 0x0c070da6u: goto P_0c070da6;
case 0x0c070da8u: goto P_0c070da8;
case 0x0c070db4u: goto P_0c070db4;
case 0x0c070db6u: goto P_0c070db6;
case 0x0c070db8u: goto P_0c070db8;
case 0x0c070dbau: goto P_0c070dba;
case 0x0c070dbcu: goto P_0c070dbc;
case 0x0c070dbeu: goto P_0c070dbe;
case 0x0c070dc0u: goto P_0c070dc0;
case 0x0c070dc2u: goto P_0c070dc2;
case 0x0c070dc4u: goto P_0c070dc4;
case 0x0c070dc6u: goto P_0c070dc6;
case 0x0c070dc8u: goto P_0c070dc8;
case 0x0c070dcau: goto P_0c070dca;
case 0x0c070dccu: goto P_0c070dcc;
case 0x0c070dceu: goto P_0c070dce;
case 0x0c070dd0u: goto P_0c070dd0;
case 0x0c070dd2u: goto P_0c070dd2;
case 0x0c070dd4u: goto P_0c070dd4;
case 0x0c071090u: goto P_0c071090;
case 0x0c071092u: goto P_0c071092;
case 0x0c071094u: goto P_0c071094;
case 0x0c071096u: goto P_0c071096;
case 0x0c071098u: goto P_0c071098;
case 0x0c07109au: goto P_0c07109a;
case 0x0c07109cu: goto P_0c07109c;
case 0x0c07109eu: goto P_0c07109e;
case 0x0c0710a0u: goto P_0c0710a0;
case 0x0c0710a2u: goto P_0c0710a2;
case 0x0c0710a4u: goto P_0c0710a4;
case 0x0c0710a6u: goto P_0c0710a6;
case 0x0c0710a8u: goto P_0c0710a8;
case 0x0c0710aau: goto P_0c0710aa;
case 0x0c0710acu: goto P_0c0710ac;
case 0x0c0710aeu: goto P_0c0710ae;
case 0x0c0710b0u: goto P_0c0710b0;
case 0x0c0710b2u: goto P_0c0710b2;
case 0x0c0710b4u: goto P_0c0710b4;
case 0x0c0710b6u: goto P_0c0710b6;
case 0x0c0710b8u: goto P_0c0710b8;
case 0x0c0710bau: goto P_0c0710ba;
case 0x0c0710bcu: goto P_0c0710bc;
case 0x0c0710beu: goto P_0c0710be;
case 0x0c0710c0u: goto P_0c0710c0;
case 0x0c0710c8u: goto P_0c0710c8;
case 0x0c0710cau: goto P_0c0710ca;
case 0x0c0710ccu: goto P_0c0710cc;
case 0x0c0710ceu: goto P_0c0710ce;
case 0x0c0710d0u: goto P_0c0710d0;
case 0x0c0710d2u: goto P_0c0710d2;
case 0x0c0710d4u: goto P_0c0710d4;
case 0x0c0710d6u: goto P_0c0710d6;
case 0x0c0710d8u: goto P_0c0710d8;
case 0x0c0710dau: goto P_0c0710da;
case 0x0c0710dcu: goto P_0c0710dc;
case 0x0c0710deu: goto P_0c0710de;
case 0x0c0710e0u: goto P_0c0710e0;
case 0x0c0710e2u: goto P_0c0710e2;
case 0x0c0710e4u: goto P_0c0710e4;
case 0x0c0710e6u: goto P_0c0710e6;
case 0x0c0710e8u: goto P_0c0710e8;
case 0x0c0710eau: goto P_0c0710ea;
case 0x0c0710ecu: goto P_0c0710ec;
case 0x0c0710eeu: goto P_0c0710ee;
case 0x0c0710f0u: goto P_0c0710f0;
case 0x0c0710f2u: goto P_0c0710f2;
case 0x0c0710f4u: goto P_0c0710f4;
case 0x0c0710f6u: goto P_0c0710f6;
case 0x0c0710f8u: goto P_0c0710f8;
case 0x0c0710fau: goto P_0c0710fa;
case 0x0c0710fcu: goto P_0c0710fc;
case 0x0c0710feu: goto P_0c0710fe;
case 0x0c071100u: goto P_0c071100;
case 0x0c071102u: goto P_0c071102;
case 0x0c071104u: goto P_0c071104;
case 0x0c071106u: goto P_0c071106;
case 0x0c071108u: goto P_0c071108;
case 0x0c07110au: goto P_0c07110a;
case 0x0c07110cu: goto P_0c07110c;
case 0x0c07110eu: goto P_0c07110e;
case 0x0c071110u: goto P_0c071110;
case 0x0c071112u: goto P_0c071112;
case 0x0c071114u: goto P_0c071114;
case 0x0c071116u: goto P_0c071116;
case 0x0c071118u: goto P_0c071118;
case 0x0c07111au: goto P_0c07111a;
case 0x0c07111cu: goto P_0c07111c;
case 0x0c07111eu: goto P_0c07111e;
case 0x0c071120u: goto P_0c071120;
case 0x0c071122u: goto P_0c071122;
case 0x0c071124u: goto P_0c071124;
case 0x0c071126u: goto P_0c071126;
case 0x0c071128u: goto P_0c071128;
case 0x0c07112au: goto P_0c07112a;
case 0x0c07112cu: goto P_0c07112c;
case 0x0c07112eu: goto P_0c07112e;
case 0x0c071130u: goto P_0c071130;
case 0x0c071132u: goto P_0c071132;
case 0x0c071134u: goto P_0c071134;
case 0x0c071136u: goto P_0c071136;
case 0x0c071138u: goto P_0c071138;
case 0x0c07113au: goto P_0c07113a;
case 0x0c07113cu: goto P_0c07113c;
case 0x0c07113eu: goto P_0c07113e;
case 0x0c071c0au: goto P_0c071c0a;
case 0x0c071c0cu: goto P_0c071c0c;
case 0x0c071c0eu: goto P_0c071c0e;
case 0x0c071c10u: goto P_0c071c10;
case 0x0c071c12u: goto P_0c071c12;
case 0x0c071c14u: goto P_0c071c14;
case 0x0c071c16u: goto P_0c071c16;
case 0x0c071c18u: goto P_0c071c18;
case 0x0c071c1au: goto P_0c071c1a;
case 0x0c071c1cu: goto P_0c071c1c;
case 0x0c071c1eu: goto P_0c071c1e;
case 0x0c071c20u: goto P_0c071c20;
case 0x0c071c22u: goto P_0c071c22;
case 0x0c071c24u: goto P_0c071c24;
case 0x0c071c26u: goto P_0c071c26;
case 0x0c071c28u: goto P_0c071c28;
case 0x0c071c2au: goto P_0c071c2a;
case 0x0c071c2cu: goto P_0c071c2c;
case 0x0c071c2eu: goto P_0c071c2e;
case 0x0c071c30u: goto P_0c071c30;
case 0x0c071c32u: goto P_0c071c32;
case 0x0c071c38u: goto P_0c071c38;
case 0x0c071c3au: goto P_0c071c3a;
case 0x0c071c3cu: goto P_0c071c3c;
case 0x0c071c3eu: goto P_0c071c3e;
case 0x0c071c40u: goto P_0c071c40;
case 0x0c071c42u: goto P_0c071c42;
case 0x0c071c44u: goto P_0c071c44;
case 0x0c071c46u: goto P_0c071c46;
case 0x0c071c48u: goto P_0c071c48;
case 0x0c071c4au: goto P_0c071c4a;
case 0x0c071c4cu: goto P_0c071c4c;
case 0x0c071c4eu: goto P_0c071c4e;
case 0x0c071c50u: goto P_0c071c50;
case 0x0c071c52u: goto P_0c071c52;
case 0x0c071c54u: goto P_0c071c54;
case 0x0c071c56u: goto P_0c071c56;
case 0x0c071c58u: goto P_0c071c58;
case 0x0c071c5au: goto P_0c071c5a;
case 0x0c071c5cu: goto P_0c071c5c;
case 0x0c071c5eu: goto P_0c071c5e;
case 0x0c071c60u: goto P_0c071c60;
case 0x0c071c62u: goto P_0c071c62;
case 0x0c071c64u: goto P_0c071c64;
case 0x0c071c66u: goto P_0c071c66;
case 0x0c071c68u: goto P_0c071c68;
case 0x0c071c6au: goto P_0c071c6a;
case 0x0c071c6cu: goto P_0c071c6c;
case 0x0c071c6eu: goto P_0c071c6e;
case 0x0c071c70u: goto P_0c071c70;
case 0x0c071c72u: goto P_0c071c72;
case 0x0c071c74u: goto P_0c071c74;
case 0x0c071c76u: goto P_0c071c76;
case 0x0c071c78u: goto P_0c071c78;
case 0x0c071c7au: goto P_0c071c7a;
case 0x0c071c7cu: goto P_0c071c7c;
case 0x0c071c7eu: goto P_0c071c7e;
case 0x0c071c80u: goto P_0c071c80;
case 0x0c071c82u: goto P_0c071c82;
case 0x0c071c84u: goto P_0c071c84;
case 0x0c071c86u: goto P_0c071c86;
case 0x0c071c88u: goto P_0c071c88;
case 0x0c071c8au: goto P_0c071c8a;
case 0x0c071c8cu: goto P_0c071c8c;
case 0x0c071c8eu: goto P_0c071c8e;
case 0x0c071c90u: goto P_0c071c90;
case 0x0c071c92u: goto P_0c071c92;
case 0x0c071c94u: goto P_0c071c94;
case 0x0c071c96u: goto P_0c071c96;
case 0x0c071c98u: goto P_0c071c98;
case 0x0c071c9au: goto P_0c071c9a;
case 0x0c071c9cu: goto P_0c071c9c;
case 0x0c071c9eu: goto P_0c071c9e;
case 0x0c071ca0u: goto P_0c071ca0;
case 0x0c071ca2u: goto P_0c071ca2;
case 0x0c071ca4u: goto P_0c071ca4;
case 0x0c071ca6u: goto P_0c071ca6;
case 0x0c071ca8u: goto P_0c071ca8;
case 0x0c071caau: goto P_0c071caa;
case 0x0c071cacu: goto P_0c071cac;
case 0x0c071caeu: goto P_0c071cae;
case 0x0c071cb0u: goto P_0c071cb0;
case 0x0c071cb2u: goto P_0c071cb2;
case 0x0c071cb4u: goto P_0c071cb4;
case 0x0c071cb6u: goto P_0c071cb6;
case 0x0c071cb8u: goto P_0c071cb8;
case 0x0c071cbau: goto P_0c071cba;
case 0x0c071cbcu: goto P_0c071cbc;
case 0x0c071cbeu: goto P_0c071cbe;
case 0x0c071cc0u: goto P_0c071cc0;
case 0x0c071cc2u: goto P_0c071cc2;
case 0x0c071cc4u: goto P_0c071cc4;
case 0x0c071cc6u: goto P_0c071cc6;
case 0x0c071cc8u: goto P_0c071cc8;
case 0x0c071ccau: goto P_0c071cca;
case 0x0c071cccu: goto P_0c071ccc;
case 0x0c071cceu: goto P_0c071cce;
case 0x0c071cd0u: goto P_0c071cd0;
case 0x0c071cd2u: goto P_0c071cd2;
case 0x0c071cd4u: goto P_0c071cd4;
case 0x0c071cd6u: goto P_0c071cd6;
case 0x0c071cd8u: goto P_0c071cd8;
case 0x0c071cdau: goto P_0c071cda;
case 0x0c071cdcu: goto P_0c071cdc;
case 0x0c071cdeu: goto P_0c071cde;
case 0x0c071ce0u: goto P_0c071ce0;
case 0x0c071ce2u: goto P_0c071ce2;
case 0x0c071ce4u: goto P_0c071ce4;
case 0x0c071ce6u: goto P_0c071ce6;
case 0x0c071ce8u: goto P_0c071ce8;
case 0x0c071ceau: goto P_0c071cea;
case 0x0c071cecu: goto P_0c071cec;
case 0x0c071ceeu: goto P_0c071cee;
case 0x0c071cf0u: goto P_0c071cf0;
case 0x0c071cf2u: goto P_0c071cf2;
case 0x0c071cf4u: goto P_0c071cf4;
case 0x0c071cf6u: goto P_0c071cf6;
case 0x0c071cf8u: goto P_0c071cf8;
case 0x0c071cfau: goto P_0c071cfa;
case 0x0c071cfcu: goto P_0c071cfc;
case 0x0c071cfeu: goto P_0c071cfe;
case 0x0c071d00u: goto P_0c071d00;
case 0x0c071d02u: goto P_0c071d02;
case 0x0c071d04u: goto P_0c071d04;
case 0x0c071d06u: goto P_0c071d06;
case 0x0c071d08u: goto P_0c071d08;
case 0x0c071d0au: goto P_0c071d0a;
case 0x0c071d0cu: goto P_0c071d0c;
case 0x0c071d0eu: goto P_0c071d0e;
case 0x0c071d10u: goto P_0c071d10;
case 0x0c071d12u: goto P_0c071d12;
case 0x0c071d14u: goto P_0c071d14;
case 0x0c071d16u: goto P_0c071d16;
case 0x0c071d18u: goto P_0c071d18;
case 0x0c071d1au: goto P_0c071d1a;
case 0x0c071d1cu: goto P_0c071d1c;
case 0x0c071d1eu: goto P_0c071d1e;
case 0x0c071d20u: goto P_0c071d20;
case 0x0c071d22u: goto P_0c071d22;
case 0x0c071d24u: goto P_0c071d24;
case 0x0c071d26u: goto P_0c071d26;
case 0x0c071d28u: goto P_0c071d28;
case 0x0c071d2au: goto P_0c071d2a;
case 0x0c071d2cu: goto P_0c071d2c;
case 0x0c071d2eu: goto P_0c071d2e;
case 0x0c071d30u: goto P_0c071d30;
case 0x0c071d32u: goto P_0c071d32;
case 0x0c071d34u: goto P_0c071d34;
case 0x0c071d36u: goto P_0c071d36;
case 0x0c071d38u: goto P_0c071d38;
case 0x0c071d3au: goto P_0c071d3a;
case 0x0c071d3cu: goto P_0c071d3c;
case 0x0c071d3eu: goto P_0c071d3e;
case 0x0c071d40u: goto P_0c071d40;
case 0x0c071d42u: goto P_0c071d42;
case 0x0c071d44u: goto P_0c071d44;
case 0x0c071d46u: goto P_0c071d46;
case 0x0c071d48u: goto P_0c071d48;
case 0x0c071d4au: goto P_0c071d4a;
case 0x0c071d4cu: goto P_0c071d4c;
case 0x0c071d4eu: goto P_0c071d4e;
case 0x0c071d50u: goto P_0c071d50;
case 0x0c071d52u: goto P_0c071d52;
case 0x0c071d54u: goto P_0c071d54;
case 0x0c071d56u: goto P_0c071d56;
case 0x0c071d58u: goto P_0c071d58;
case 0x0c071d5au: goto P_0c071d5a;
case 0x0c071d5cu: goto P_0c071d5c;
case 0x0c071d5eu: goto P_0c071d5e;
case 0x0c071d60u: goto P_0c071d60;
case 0x0c071d62u: goto P_0c071d62;
case 0x0c071d64u: goto P_0c071d64;
case 0x0c071d66u: goto P_0c071d66;
case 0x0c071d68u: goto P_0c071d68;
case 0x0c071d6au: goto P_0c071d6a;
case 0x0c071d6cu: goto P_0c071d6c;
case 0x0c071d6eu: goto P_0c071d6e;
case 0x0c071d70u: goto P_0c071d70;
case 0x0c071d72u: goto P_0c071d72;
case 0x0c071d74u: goto P_0c071d74;
case 0x0c071d76u: goto P_0c071d76;
case 0x0c071d78u: goto P_0c071d78;
case 0x0c071d7au: goto P_0c071d7a;
case 0x0c071d7cu: goto P_0c071d7c;
case 0x0c071d7eu: goto P_0c071d7e;
case 0x0c071d80u: goto P_0c071d80;
case 0x0c071d82u: goto P_0c071d82;
case 0x0c071d84u: goto P_0c071d84;
case 0x0c071d86u: goto P_0c071d86;
case 0x0c071d88u: goto P_0c071d88;
case 0x0c071d8au: goto P_0c071d8a;
case 0x0c071d8cu: goto P_0c071d8c;
case 0x0c071d8eu: goto P_0c071d8e;
case 0x0c071d90u: goto P_0c071d90;
case 0x0c071d92u: goto P_0c071d92;
case 0x0c071d94u: goto P_0c071d94;
case 0x0c071d96u: goto P_0c071d96;
case 0x0c071d98u: goto P_0c071d98;
case 0x0c071d9au: goto P_0c071d9a;
case 0x0c071d9cu: goto P_0c071d9c;
case 0x0c071d9eu: goto P_0c071d9e;
case 0x0c071da0u: goto P_0c071da0;
case 0x0c071da2u: goto P_0c071da2;
case 0x0c071da4u: goto P_0c071da4;
case 0x0c071da6u: goto P_0c071da6;
case 0x0c071dacu: goto P_0c071dac;
case 0x0c071daeu: goto P_0c071dae;
case 0x0c071db0u: goto P_0c071db0;
case 0x0c071db2u: goto P_0c071db2;
case 0x0c071db4u: goto P_0c071db4;
case 0x0c071db6u: goto P_0c071db6;
case 0x0c071db8u: goto P_0c071db8;
case 0x0c071dbau: goto P_0c071dba;
case 0x0c071dbcu: goto P_0c071dbc;
case 0x0c071dbeu: goto P_0c071dbe;
case 0x0c071dc0u: goto P_0c071dc0;
case 0x0c071dc2u: goto P_0c071dc2;
case 0x0c071dc4u: goto P_0c071dc4;
case 0x0c071dc6u: goto P_0c071dc6;
case 0x0c071dc8u: goto P_0c071dc8;
case 0x0c071dcau: goto P_0c071dca;
case 0x0c071dccu: goto P_0c071dcc;
case 0x0c071dceu: goto P_0c071dce;
case 0x0c071dd0u: goto P_0c071dd0;
case 0x0c071dd2u: goto P_0c071dd2;
case 0x0c071dd4u: goto P_0c071dd4;
case 0x0c071dd6u: goto P_0c071dd6;
case 0x0c071dd8u: goto P_0c071dd8;
case 0x0c071ddau: goto P_0c071dda;
case 0x0c071ddcu: goto P_0c071ddc;
case 0x0c071ddeu: goto P_0c071dde;
case 0x0c071de0u: goto P_0c071de0;
case 0x0c071de2u: goto P_0c071de2;
case 0x0c071de4u: goto P_0c071de4;
case 0x0c071de6u: goto P_0c071de6;
case 0x0c071de8u: goto P_0c071de8;
case 0x0c071deau: goto P_0c071dea;
case 0x0c071decu: goto P_0c071dec;
case 0x0c071deeu: goto P_0c071dee;
case 0x0c071df0u: goto P_0c071df0;
case 0x0c071df2u: goto P_0c071df2;
case 0x0c071df4u: goto P_0c071df4;
case 0x0c071df6u: goto P_0c071df6;
case 0x0c071df8u: goto P_0c071df8;
case 0x0c071dfau: goto P_0c071dfa;
case 0x0c071dfcu: goto P_0c071dfc;
case 0x0c071dfeu: goto P_0c071dfe;
case 0x0c071e00u: goto P_0c071e00;
case 0x0c071e02u: goto P_0c071e02;
case 0x0c071e04u: goto P_0c071e04;
case 0x0c071e06u: goto P_0c071e06;
case 0x0c071e08u: goto P_0c071e08;
case 0x0c071e0au: goto P_0c071e0a;
case 0x0c071e0cu: goto P_0c071e0c;
case 0x0c071e0eu: goto P_0c071e0e;
case 0x0c071e10u: goto P_0c071e10;
case 0x0c071e12u: goto P_0c071e12;
case 0x0c071e14u: goto P_0c071e14;
case 0x0c071e16u: goto P_0c071e16;
case 0x0c071e18u: goto P_0c071e18;
case 0x0c071e1au: goto P_0c071e1a;
case 0x0c071e1cu: goto P_0c071e1c;
case 0x0c071e1eu: goto P_0c071e1e;
case 0x0c071e20u: goto P_0c071e20;
case 0x0c071e22u: goto P_0c071e22;
case 0x0c071e24u: goto P_0c071e24;
case 0x0c071e26u: goto P_0c071e26;
case 0x0c071e28u: goto P_0c071e28;
case 0x0c071e2au: goto P_0c071e2a;
case 0x0c071e2cu: goto P_0c071e2c;
case 0x0c071e2eu: goto P_0c071e2e;
case 0x0c071e30u: goto P_0c071e30;
case 0x0c071e32u: goto P_0c071e32;
case 0x0c071e34u: goto P_0c071e34;
case 0x0c071e36u: goto P_0c071e36;
case 0x0c071e38u: goto P_0c071e38;
case 0x0c071e3au: goto P_0c071e3a;
case 0x0c071e3cu: goto P_0c071e3c;
case 0x0c071e3eu: goto P_0c071e3e;
case 0x0c071e40u: goto P_0c071e40;
case 0x0c071e42u: goto P_0c071e42;
case 0x0c071e44u: goto P_0c071e44;
case 0x0c071e46u: goto P_0c071e46;
case 0x0c071e48u: goto P_0c071e48;
case 0x0c071e4au: goto P_0c071e4a;
case 0x0c071e4cu: goto P_0c071e4c;
case 0x0c071e4eu: goto P_0c071e4e;
case 0x0c071e50u: goto P_0c071e50;
case 0x0c071e52u: goto P_0c071e52;
case 0x0c071e54u: goto P_0c071e54;
case 0x0c071e56u: goto P_0c071e56;
case 0x0c071e58u: goto P_0c071e58;
case 0x0c071e5au: goto P_0c071e5a;
case 0x0c071e5cu: goto P_0c071e5c;
case 0x0c071e64u: goto P_0c071e64;
case 0x0c071e66u: goto P_0c071e66;
case 0x0c071e68u: goto P_0c071e68;
case 0x0c071e6au: goto P_0c071e6a;
case 0x0c071e6cu: goto P_0c071e6c;
case 0x0c071e6eu: goto P_0c071e6e;
case 0x0c071e70u: goto P_0c071e70;
case 0x0c071e72u: goto P_0c071e72;
case 0x0c071e74u: goto P_0c071e74;
case 0x0c071e76u: goto P_0c071e76;
case 0x0c071e78u: goto P_0c071e78;
case 0x0c071e7au: goto P_0c071e7a;
case 0x0c071e7cu: goto P_0c071e7c;
case 0x0c071e7eu: goto P_0c071e7e;
case 0x0c071e80u: goto P_0c071e80;
case 0x0c071e82u: goto P_0c071e82;
case 0x0c071e84u: goto P_0c071e84;
case 0x0c071e86u: goto P_0c071e86;
case 0x0c071e88u: goto P_0c071e88;
case 0x0c071e8au: goto P_0c071e8a;
case 0x0c071e8cu: goto P_0c071e8c;
case 0x0c071e8eu: goto P_0c071e8e;
case 0x0c071e90u: goto P_0c071e90;
case 0x0c071e92u: goto P_0c071e92;
case 0x0c071e94u: goto P_0c071e94;
case 0x0c071e96u: goto P_0c071e96;
case 0x0c071e98u: goto P_0c071e98;
case 0x0c071e9au: goto P_0c071e9a;
case 0x0c071e9cu: goto P_0c071e9c;
case 0x0c071e9eu: goto P_0c071e9e;
case 0x0c071ea0u: goto P_0c071ea0;
case 0x0c071ea2u: goto P_0c071ea2;
case 0x0c071ea4u: goto P_0c071ea4;
case 0x0c071ea6u: goto P_0c071ea6;
case 0x0c071ea8u: goto P_0c071ea8;
case 0x0c071eaau: goto P_0c071eaa;
case 0x0c071eacu: goto P_0c071eac;
case 0x0c071eaeu: goto P_0c071eae;
case 0x0c071eb0u: goto P_0c071eb0;
case 0x0c071eb2u: goto P_0c071eb2;
case 0x0c071eb4u: goto P_0c071eb4;
case 0x0c071eb6u: goto P_0c071eb6;
case 0x0c071eb8u: goto P_0c071eb8;
case 0x0c071ebau: goto P_0c071eba;
case 0x0c071ebcu: goto P_0c071ebc;
case 0x0c071ebeu: goto P_0c071ebe;
case 0x0c071ec0u: goto P_0c071ec0;
case 0x0c071ec2u: goto P_0c071ec2;
case 0x0c071ec4u: goto P_0c071ec4;
case 0x0c071ec6u: goto P_0c071ec6;
case 0x0c071ec8u: goto P_0c071ec8;
case 0x0c071ecau: goto P_0c071eca;
case 0x0c071eccu: goto P_0c071ecc;
case 0x0c071eceu: goto P_0c071ece;
case 0x0c071ed0u: goto P_0c071ed0;
case 0x0c071ed2u: goto P_0c071ed2;
case 0x0c071ed4u: goto P_0c071ed4;
case 0x0c071ed6u: goto P_0c071ed6;
case 0x0c071ed8u: goto P_0c071ed8;
case 0x0c071edau: goto P_0c071eda;
case 0x0c071edcu: goto P_0c071edc;
case 0x0c071edeu: goto P_0c071ede;
case 0x0c071ee0u: goto P_0c071ee0;
case 0x0c071ee2u: goto P_0c071ee2;
case 0x0c071ee4u: goto P_0c071ee4;
case 0x0c071ee6u: goto P_0c071ee6;
case 0x0c071ee8u: goto P_0c071ee8;
case 0x0c071eeau: goto P_0c071eea;
case 0x0c071eecu: goto P_0c071eec;
case 0x0c071eeeu: goto P_0c071eee;
case 0x0c071ef0u: goto P_0c071ef0;
case 0x0c071ef2u: goto P_0c071ef2;
case 0x0c071ef4u: goto P_0c071ef4;
case 0x0c071ef6u: goto P_0c071ef6;
case 0x0c071ef8u: goto P_0c071ef8;
case 0x0c071efau: goto P_0c071efa;
case 0x0c071efcu: goto P_0c071efc;
case 0x0c071efeu: goto P_0c071efe;
case 0x0c071f00u: goto P_0c071f00;
case 0x0c071f02u: goto P_0c071f02;
case 0x0c071f04u: goto P_0c071f04;
case 0x0c071f06u: goto P_0c071f06;
case 0x0c071f08u: goto P_0c071f08;
case 0x0c071f0au: goto P_0c071f0a;
case 0x0c071f0cu: goto P_0c071f0c;
case 0x0c071f0eu: goto P_0c071f0e;
case 0x0c071f10u: goto P_0c071f10;
case 0x0c071f12u: goto P_0c071f12;
case 0x0c071f14u: goto P_0c071f14;
case 0x0c071f16u: goto P_0c071f16;
case 0x0c071f18u: goto P_0c071f18;
case 0x0c071f1au: goto P_0c071f1a;
case 0x0c071f1cu: goto P_0c071f1c;
case 0x0c071f1eu: goto P_0c071f1e;
case 0x0c071f20u: goto P_0c071f20;
case 0x0c071f22u: goto P_0c071f22;
case 0x0c071f24u: goto P_0c071f24;
case 0x0c071f26u: goto P_0c071f26;
case 0x0c071f28u: goto P_0c071f28;
case 0x0c071f2au: goto P_0c071f2a;
case 0x0c071f2cu: goto P_0c071f2c;
case 0x0c071f2eu: goto P_0c071f2e;
case 0x0c071f30u: goto P_0c071f30;
case 0x0c071f32u: goto P_0c071f32;
case 0x0c071f34u: goto P_0c071f34;
case 0x0c071f36u: goto P_0c071f36;
case 0x0c071f38u: goto P_0c071f38;
case 0x0c071f3au: goto P_0c071f3a;
case 0x0c071f3cu: goto P_0c071f3c;
case 0x0c071f3eu: goto P_0c071f3e;
case 0x0c071f40u: goto P_0c071f40;
case 0x0c071f42u: goto P_0c071f42;
case 0x0c071f44u: goto P_0c071f44;
case 0x0c071f46u: goto P_0c071f46;
case 0x0c071f48u: goto P_0c071f48;
case 0x0c071f4au: goto P_0c071f4a;
case 0x0c071f4cu: goto P_0c071f4c;
case 0x0c071f4eu: goto P_0c071f4e;
case 0x0c071f50u: goto P_0c071f50;
case 0x0c071f52u: goto P_0c071f52;
case 0x0c071f54u: goto P_0c071f54;
case 0x0c071f56u: goto P_0c071f56;
case 0x0c071f58u: goto P_0c071f58;
case 0x0c071f5au: goto P_0c071f5a;
case 0x0c071f5cu: goto P_0c071f5c;
case 0x0c071f5eu: goto P_0c071f5e;
case 0x0c071f60u: goto P_0c071f60;
case 0x0c071f62u: goto P_0c071f62;
case 0x0c071f64u: goto P_0c071f64;
case 0x0c071f66u: goto P_0c071f66;
case 0x0c071f68u: goto P_0c071f68;
case 0x0c071f6au: goto P_0c071f6a;
case 0x0c071f6cu: goto P_0c071f6c;
case 0x0c071f6eu: goto P_0c071f6e;
case 0x0c071f70u: goto P_0c071f70;
case 0x0c071f72u: goto P_0c071f72;
case 0x0c071f74u: goto P_0c071f74;
case 0x0c071f76u: goto P_0c071f76;
case 0x0c071f78u: goto P_0c071f78;
case 0x0c071f7au: goto P_0c071f7a;
case 0x0c071f7cu: goto P_0c071f7c;
case 0x0c071f7eu: goto P_0c071f7e;
case 0x0c071f80u: goto P_0c071f80;
case 0x0c071f82u: goto P_0c071f82;
case 0x0c071f84u: goto P_0c071f84;
case 0x0c071f86u: goto P_0c071f86;
case 0x0c071f88u: goto P_0c071f88;
case 0x0c071f8au: goto P_0c071f8a;
case 0x0c071f8cu: goto P_0c071f8c;
case 0x0c071f8eu: goto P_0c071f8e;
case 0x0c071f90u: goto P_0c071f90;
case 0x0c071f92u: goto P_0c071f92;
case 0x0c071f94u: goto P_0c071f94;
case 0x0c071f96u: goto P_0c071f96;
case 0x0c071f98u: goto P_0c071f98;
case 0x0c071f9au: goto P_0c071f9a;
case 0x0c071f9cu: goto P_0c071f9c;
case 0x0c071f9eu: goto P_0c071f9e;
case 0x0c071fa0u: goto P_0c071fa0;
case 0x0c071fa2u: goto P_0c071fa2;
case 0x0c071fa4u: goto P_0c071fa4;
case 0x0c071fa6u: goto P_0c071fa6;
case 0x0c071fa8u: goto P_0c071fa8;
case 0x0c071faau: goto P_0c071faa;
case 0x0c071facu: goto P_0c071fac;
case 0x0c071faeu: goto P_0c071fae;
case 0x0c071fb0u: goto P_0c071fb0;
case 0x0c071fb2u: goto P_0c071fb2;
case 0x0c071fb4u: goto P_0c071fb4;
case 0x0c071fb6u: goto P_0c071fb6;
case 0x0c071fb8u: goto P_0c071fb8;
case 0x0c071fbau: goto P_0c071fba;
case 0x0c071fbcu: goto P_0c071fbc;
case 0x0c071fbeu: goto P_0c071fbe;
case 0x0c071fc0u: goto P_0c071fc0;
case 0x0c071fc2u: goto P_0c071fc2;
case 0x0c071fc4u: goto P_0c071fc4;
case 0x0c071fc6u: goto P_0c071fc6;
case 0x0c071fc8u: goto P_0c071fc8;
case 0x0c071fcau: goto P_0c071fca;
case 0x0c071fccu: goto P_0c071fcc;
case 0x0c071fd4u: goto P_0c071fd4;
case 0x0c071fd6u: goto P_0c071fd6;
case 0x0c071fd8u: goto P_0c071fd8;
case 0x0c071fdau: goto P_0c071fda;
case 0x0c071fdcu: goto P_0c071fdc;
case 0x0c071fdeu: goto P_0c071fde;
case 0x0c071fe0u: goto P_0c071fe0;
case 0x0c071fe2u: goto P_0c071fe2;
case 0x0c071fe4u: goto P_0c071fe4;
case 0x0c071fe6u: goto P_0c071fe6;
case 0x0c071fe8u: goto P_0c071fe8;
case 0x0c071feau: goto P_0c071fea;
case 0x0c071fecu: goto P_0c071fec;
case 0x0c071feeu: goto P_0c071fee;
case 0x0c071ff0u: goto P_0c071ff0;
case 0x0c071ff2u: goto P_0c071ff2;
case 0x0c071ff4u: goto P_0c071ff4;
case 0x0c071ff6u: goto P_0c071ff6;
case 0x0c071ff8u: goto P_0c071ff8;
case 0x0c071ffau: goto P_0c071ffa;
case 0x0c071ffcu: goto P_0c071ffc;
case 0x0c071ffeu: goto P_0c071ffe;
case 0x0c072000u: goto P_0c072000;
case 0x0c072002u: goto P_0c072002;
case 0x0c072004u: goto P_0c072004;
case 0x0c072006u: goto P_0c072006;
case 0x0c072008u: goto P_0c072008;
case 0x0c07200au: goto P_0c07200a;
case 0x0c07200cu: goto P_0c07200c;
case 0x0c07200eu: goto P_0c07200e;
case 0x0c072010u: goto P_0c072010;
case 0x0c072012u: goto P_0c072012;
case 0x0c072014u: goto P_0c072014;
case 0x0c072016u: goto P_0c072016;
case 0x0c072018u: goto P_0c072018;
case 0x0c07201au: goto P_0c07201a;
case 0x0c07201cu: goto P_0c07201c;
case 0x0c07201eu: goto P_0c07201e;
case 0x0c072020u: goto P_0c072020;
case 0x0c072022u: goto P_0c072022;
case 0x0c072024u: goto P_0c072024;
case 0x0c072026u: goto P_0c072026;
case 0x0c072028u: goto P_0c072028;
case 0x0c07202au: goto P_0c07202a;
case 0x0c07202cu: goto P_0c07202c;
case 0x0c07202eu: goto P_0c07202e;
case 0x0c072030u: goto P_0c072030;
case 0x0c072032u: goto P_0c072032;
case 0x0c072034u: goto P_0c072034;
case 0x0c072036u: goto P_0c072036;
case 0x0c072038u: goto P_0c072038;
case 0x0c07203au: goto P_0c07203a;
case 0x0c07203cu: goto P_0c07203c;
case 0x0c07203eu: goto P_0c07203e;
case 0x0c072040u: goto P_0c072040;
case 0x0c072042u: goto P_0c072042;
case 0x0c072044u: goto P_0c072044;
case 0x0c072046u: goto P_0c072046;
case 0x0c072048u: goto P_0c072048;
case 0x0c07204au: goto P_0c07204a;
case 0x0c07204cu: goto P_0c07204c;
case 0x0c07204eu: goto P_0c07204e;
case 0x0c072050u: goto P_0c072050;
case 0x0c072052u: goto P_0c072052;
case 0x0c072054u: goto P_0c072054;
case 0x0c072056u: goto P_0c072056;
case 0x0c072058u: goto P_0c072058;
case 0x0c07205au: goto P_0c07205a;
case 0x0c07205cu: goto P_0c07205c;
case 0x0c07205eu: goto P_0c07205e;
case 0x0c072060u: goto P_0c072060;
case 0x0c072062u: goto P_0c072062;
case 0x0c072064u: goto P_0c072064;
case 0x0c072066u: goto P_0c072066;
case 0x0c072068u: goto P_0c072068;
case 0x0c07206au: goto P_0c07206a;
case 0x0c07206cu: goto P_0c07206c;
case 0x0c07206eu: goto P_0c07206e;
case 0x0c072070u: goto P_0c072070;
case 0x0c072072u: goto P_0c072072;
case 0x0c072074u: goto P_0c072074;
case 0x0c07ab14u: goto P_0c07ab14;
case 0x0c07ab16u: goto P_0c07ab16;
case 0x0c07ab18u: goto P_0c07ab18;
case 0x0c07ab1au: goto P_0c07ab1a;
case 0x0c07ab1cu: goto P_0c07ab1c;
case 0x0c07ab1eu: goto P_0c07ab1e;
case 0x0c07ab20u: goto P_0c07ab20;
case 0x0c07ab22u: goto P_0c07ab22;
case 0x0c07ab24u: goto P_0c07ab24;
case 0x0c07ab26u: goto P_0c07ab26;
case 0x0c07ab28u: goto P_0c07ab28;
case 0x0c07ab2au: goto P_0c07ab2a;
case 0x0c07ab2cu: goto P_0c07ab2c;
case 0x0c07ab2eu: goto P_0c07ab2e;
case 0x0c07ab30u: goto P_0c07ab30;
case 0x0c07ab32u: goto P_0c07ab32;
case 0x0c07ab34u: goto P_0c07ab34;
case 0x0c07ab36u: goto P_0c07ab36;
case 0x0c07ab38u: goto P_0c07ab38;
case 0x0c07ab3au: goto P_0c07ab3a;
case 0x0c07ab3cu: goto P_0c07ab3c;
case 0x0c07ab3eu: goto P_0c07ab3e;
case 0x0c07ab40u: goto P_0c07ab40;
case 0x0c07ab42u: goto P_0c07ab42;
case 0x0c07ab44u: goto P_0c07ab44;
case 0x0c07ab46u: goto P_0c07ab46;
case 0x0c07ab48u: goto P_0c07ab48;
case 0x0c07ab4au: goto P_0c07ab4a;
case 0x0c07ab4cu: goto P_0c07ab4c;
case 0x0c07ab4eu: goto P_0c07ab4e;
case 0x0c07ab50u: goto P_0c07ab50;
case 0x0c07ab52u: goto P_0c07ab52;
case 0x0c07ab54u: goto P_0c07ab54;
case 0x0c07ab56u: goto P_0c07ab56;
case 0x0c07ab58u: goto P_0c07ab58;
case 0x0c07ab5au: goto P_0c07ab5a;
case 0x0c07ab5cu: goto P_0c07ab5c;
case 0x0c07ab5eu: goto P_0c07ab5e;
case 0x0c07ab60u: goto P_0c07ab60;
case 0x0c07ab62u: goto P_0c07ab62;
case 0x0c07ab64u: goto P_0c07ab64;
case 0x0c07ab66u: goto P_0c07ab66;
case 0x0c07ab68u: goto P_0c07ab68;
case 0x0c07ab6au: goto P_0c07ab6a;
case 0x0c07ab6cu: goto P_0c07ab6c;
case 0x0c07ab6eu: goto P_0c07ab6e;
case 0x0c07ab70u: goto P_0c07ab70;
case 0x0c07ab72u: goto P_0c07ab72;
case 0x0c07ab74u: goto P_0c07ab74;
case 0x0c07ab76u: goto P_0c07ab76;
case 0x0c07ab78u: goto P_0c07ab78;
case 0x0c07ab7au: goto P_0c07ab7a;
case 0x0c07ab7cu: goto P_0c07ab7c;
case 0x0c07ab7eu: goto P_0c07ab7e;
case 0x0c07ab80u: goto P_0c07ab80;
case 0x0c07ab82u: goto P_0c07ab82;
case 0x0c07ab84u: goto P_0c07ab84;
case 0x0c07ab94u: goto P_0c07ab94;
case 0x0c07ab96u: goto P_0c07ab96;
case 0x0c07ab98u: goto P_0c07ab98;
case 0x0c07ab9au: goto P_0c07ab9a;
case 0x0c07ab9cu: goto P_0c07ab9c;
case 0x0c07ab9eu: goto P_0c07ab9e;
case 0x0c07aba0u: goto P_0c07aba0;
case 0x0c07aba2u: goto P_0c07aba2;
case 0x0c07aba4u: goto P_0c07aba4;
case 0x0c07aba6u: goto P_0c07aba6;
case 0x0c07aba8u: goto P_0c07aba8;
case 0x0c07abaau: goto P_0c07abaa;
case 0x0c07abacu: goto P_0c07abac;
case 0x0c07abaeu: goto P_0c07abae;
case 0x0c07abb0u: goto P_0c07abb0;
case 0x0c07abb2u: goto P_0c07abb2;
case 0x0c07abb4u: goto P_0c07abb4;
case 0x0c07abb6u: goto P_0c07abb6;
case 0x0c07abb8u: goto P_0c07abb8;
case 0x0c07abbau: goto P_0c07abba;
case 0x0c07abbcu: goto P_0c07abbc;
case 0x0c07abbeu: goto P_0c07abbe;
case 0x0c07abc0u: goto P_0c07abc0;
case 0x0c07abc2u: goto P_0c07abc2;
case 0x0c07abc4u: goto P_0c07abc4;
case 0x0c07abc6u: goto P_0c07abc6;
case 0x0c07abc8u: goto P_0c07abc8;
case 0x0c07abcau: goto P_0c07abca;
case 0x0c07abccu: goto P_0c07abcc;
case 0x0c07abceu: goto P_0c07abce;
case 0x0c07abd0u: goto P_0c07abd0;
case 0x0c07abd2u: goto P_0c07abd2;
case 0x0c07abd4u: goto P_0c07abd4;
case 0x0c07abd6u: goto P_0c07abd6;
case 0x0c07abd8u: goto P_0c07abd8;
case 0x0c07abdau: goto P_0c07abda;
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
case 0x0c07b5f0u: goto P_0c07b5f0;
case 0x0c07b5f2u: goto P_0c07b5f2;
case 0x0c07b5f4u: goto P_0c07b5f4;
case 0x0c07b5f6u: goto P_0c07b5f6;
case 0x0c07b5f8u: goto P_0c07b5f8;
case 0x0c07b5fau: goto P_0c07b5fa;
case 0x0c07b5fcu: goto P_0c07b5fc;
case 0x0c07b5feu: goto P_0c07b5fe;
case 0x0c07b600u: goto P_0c07b600;
case 0x0c07b602u: goto P_0c07b602;
case 0x0c07b604u: goto P_0c07b604;
case 0x0c07b606u: goto P_0c07b606;
case 0x0c07b608u: goto P_0c07b608;
case 0x0c07b60au: goto P_0c07b60a;
case 0x0c07b60cu: goto P_0c07b60c;
case 0x0c07b60eu: goto P_0c07b60e;
case 0x0c07b610u: goto P_0c07b610;
case 0x0c07b612u: goto P_0c07b612;
case 0x0c07b614u: goto P_0c07b614;
case 0x0c07b616u: goto P_0c07b616;
case 0x0c07b618u: goto P_0c07b618;
case 0x0c07b61au: goto P_0c07b61a;
case 0x0c07b61cu: goto P_0c07b61c;
case 0x0c07b61eu: goto P_0c07b61e;
case 0x0c07b620u: goto P_0c07b620;
case 0x0c07b622u: goto P_0c07b622;
case 0x0c07b624u: goto P_0c07b624;
case 0x0c07b626u: goto P_0c07b626;
case 0x0c07b628u: goto P_0c07b628;
case 0x0c07b62au: goto P_0c07b62a;
case 0x0c07b62cu: goto P_0c07b62c;
case 0x0c07b62eu: goto P_0c07b62e;
case 0x0c07b630u: goto P_0c07b630;
case 0x0c07b632u: goto P_0c07b632;
case 0x0c07b634u: goto P_0c07b634;
case 0x0c07b636u: goto P_0c07b636;
case 0x0c07b638u: goto P_0c07b638;
case 0x0c07b63au: goto P_0c07b63a;
case 0x0c07b63cu: goto P_0c07b63c;
case 0x0c07b63eu: goto P_0c07b63e;
case 0x0c07b640u: goto P_0c07b640;
case 0x0c07b642u: goto P_0c07b642;
case 0x0c07b644u: goto P_0c07b644;
case 0x0c07b646u: goto P_0c07b646;
case 0x0c07b648u: goto P_0c07b648;
case 0x0c07b64au: goto P_0c07b64a;
case 0x0c07b64cu: goto P_0c07b64c;
case 0x0c07b64eu: goto P_0c07b64e;
case 0x0c07b650u: goto P_0c07b650;
case 0x0c07b652u: goto P_0c07b652;
case 0x0c07b654u: goto P_0c07b654;
case 0x0c07b656u: goto P_0c07b656;
case 0x0c07b658u: goto P_0c07b658;
case 0x0c07b65au: goto P_0c07b65a;
case 0x0c07b65cu: goto P_0c07b65c;
case 0x0c07b65eu: goto P_0c07b65e;
case 0x0c07b660u: goto P_0c07b660;
case 0x0c07b662u: goto P_0c07b662;
case 0x0c07b664u: goto P_0c07b664;
case 0x0c07b666u: goto P_0c07b666;
case 0x0c07b668u: goto P_0c07b668;
case 0x0c07b66au: goto P_0c07b66a;
case 0x0c07b66cu: goto P_0c07b66c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0365d4: /* original e22c, guest PC 0x0c0365d4 */
if(!s->budget--) { s->failed_pc=0x0c0365d4u; return 0; }
r[2]=0x0000002cu;
goto P_0c0365d6;
P_0c0365d6: /* original d31b, guest PC 0x0c0365d6 */
if(!s->budget--) { s->failed_pc=0x0c0365d6u; return 0; }
r[3]=read(ram,0x0c036644u,4);
goto P_0c0365d8;
P_0c0365d8: /* original 4f12, guest PC 0x0c0365d8 */
if(!s->budget--) { s->failed_pc=0x0c0365d8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0365da;
P_0c0365da: /* original 242f, guest PC 0x0c0365da */
if(!s->budget--) { s->failed_pc=0x0c0365dau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[2]);
goto P_0c0365dc;
P_0c0365dc: /* original 6032, guest PC 0x0c0365dc */
if(!s->budget--) { s->failed_pc=0x0c0365dcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0365de;
P_0c0365de: /* original 7028, guest PC 0x0c0365de */
if(!s->budget--) { s->failed_pc=0x0c0365deu; return 0; }
r[0]+=0x00000028u;
goto P_0c0365e0;
P_0c0365e0: /* original 041a, guest PC 0x0c0365e0 */
if(!s->budget--) { s->failed_pc=0x0c0365e0u; return 0; }
r[4]=r[19];
goto P_0c0365e2;
P_0c0365e2: /* original 644f, guest PC 0x0c0365e2 */
if(!s->budget--) { s->failed_pc=0x0c0365e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0365e4;
P_0c0365e4: /* original 304c, guest PC 0x0c0365e4 */
if(!s->budget--) { s->failed_pc=0x0c0365e4u; return 0; }
r[0]+=r[4];
goto P_0c0365e6;
P_0c0365e6: /* original 000b, guest PC 0x0c0365e6 */
if(!s->budget--) { s->failed_pc=0x0c0365e6u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0365e8: /* original 4f16, guest PC 0x0c0365e8 */
if(!s->budget--) { s->failed_pc=0x0c0365e8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0365ea;
P_0c0365ea: /* original e278, guest PC 0x0c0365ea */
if(!s->budget--) { s->failed_pc=0x0c0365eau; return 0; }
r[2]=0x00000078u;
goto P_0c0365ec;
P_0c0365ec: /* original d315, guest PC 0x0c0365ec */
if(!s->budget--) { s->failed_pc=0x0c0365ecu; return 0; }
r[3]=read(ram,0x0c036644u,4);
goto P_0c0365ee;
P_0c0365ee: /* original 4f12, guest PC 0x0c0365ee */
if(!s->budget--) { s->failed_pc=0x0c0365eeu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0365f0;
P_0c0365f0: /* original 242f, guest PC 0x0c0365f0 */
if(!s->budget--) { s->failed_pc=0x0c0365f0u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[2]);
goto P_0c0365f2;
P_0c0365f2: /* original 911f, guest PC 0x0c0365f2 */
if(!s->budget--) { s->failed_pc=0x0c0365f2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036634u,2);
goto P_0c0365f4;
P_0c0365f4: /* original 6032, guest PC 0x0c0365f4 */
if(!s->budget--) { s->failed_pc=0x0c0365f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0365f6;
P_0c0365f6: /* original 041a, guest PC 0x0c0365f6 */
if(!s->budget--) { s->failed_pc=0x0c0365f6u; return 0; }
r[4]=r[19];
goto P_0c0365f8;
P_0c0365f8: /* original 301c, guest PC 0x0c0365f8 */
if(!s->budget--) { s->failed_pc=0x0c0365f8u; return 0; }
r[0]+=r[1];
goto P_0c0365fa;
P_0c0365fa: /* original 644f, guest PC 0x0c0365fa */
if(!s->budget--) { s->failed_pc=0x0c0365fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0365fc;
P_0c0365fc: /* original 304c, guest PC 0x0c0365fc */
if(!s->budget--) { s->failed_pc=0x0c0365fcu; return 0; }
r[0]+=r[4];
goto P_0c0365fe;
P_0c0365fe: /* original 000b, guest PC 0x0c0365fe */
if(!s->budget--) { s->failed_pc=0x0c0365feu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c036600: /* original 4f16, guest PC 0x0c036600 */
if(!s->budget--) { s->failed_pc=0x0c036600u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c036602u,s,ram);
P_0c03665e: /* original 4f22, guest PC 0x0c03665e */
if(!s->budget--) { s->failed_pc=0x0c03665eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036660;
P_0c036660: /* original bfb8, guest PC 0x0c036660 */
if(!s->budget--) { s->failed_pc=0x0c036660u; return 0; }
target=0x0c0365d4u; r[16]=0x0c036664u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036664u) { target=s->pc; goto dispatch; }
goto P_0c036664;
P_0c036662: /* original 0009, guest PC 0x0c036662 */
if(!s->budget--) { s->failed_pc=0x0c036662u; return 0; }
goto P_0c036664;
P_0c036664: /* original 4f26, guest PC 0x0c036664 */
if(!s->budget--) { s->failed_pc=0x0c036664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036666;
P_0c036666: /* original 6403, guest PC 0x0c036666 */
if(!s->budget--) { s->failed_pc=0x0c036666u; return 0; }
r[4]=r[0];
goto P_0c036668;
P_0c036668: /* original 844c, guest PC 0x0c036668 */
if(!s->budget--) { s->failed_pc=0x0c036668u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+12,1);
goto P_0c03666a;
P_0c03666a: /* original 000b, guest PC 0x0c03666a */
if(!s->budget--) { s->failed_pc=0x0c03666au; return 0; }
target=r[16];
r[0]=r[0]&255u;
s->pc=target; return ram->oob==0;
P_0c03666c: /* original 600c, guest PC 0x0c03666c */
if(!s->budget--) { s->failed_pc=0x0c03666cu; return 0; }
r[0]=r[0]&255u;
return vf3_matrix_family(0x0c03666eu,s,ram);
P_0c038760: /* original d23a, guest PC 0x0c038760 */
if(!s->budget--) { s->failed_pc=0x0c038760u; return 0; }
r[2]=read(ram,0x0c03884cu,4);
goto P_0c038762;
P_0c038762: /* original 000b, guest PC 0x0c038762 */
if(!s->budget--) { s->failed_pc=0x0c038762u; return 0; }
target=r[16];
write(ram,r[2],r[4],4);
s->pc=target; return ram->oob==0;
P_0c038764: /* original 2242, guest PC 0x0c038764 */
if(!s->budget--) { s->failed_pc=0x0c038764u; return 0; }
write(ram,r[2],r[4],4);
return vf3_matrix_family(0x0c038766u,s,ram);
P_0c03f690: /* original 2fe6, guest PC 0x0c03f690 */
if(!s->budget--) { s->failed_pc=0x0c03f690u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c03f692;
P_0c03f692: /* original e300, guest PC 0x0c03f692 */
if(!s->budget--) { s->failed_pc=0x0c03f692u; return 0; }
r[3]=0x00000000u;
goto P_0c03f694;
P_0c03f694: /* original 2fd6, guest PC 0x0c03f694 */
if(!s->budget--) { s->failed_pc=0x0c03f694u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c03f696;
P_0c03f696: /* original edff, guest PC 0x0c03f696 */
if(!s->budget--) { s->failed_pc=0x0c03f696u; return 0; }
r[13]=0xffffffffu;
goto P_0c03f698;
P_0c03f698: /* original 2fc6, guest PC 0x0c03f698 */
if(!s->budget--) { s->failed_pc=0x0c03f698u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c03f69a;
P_0c03f69a: /* original 2fb6, guest PC 0x0c03f69a */
if(!s->budget--) { s->failed_pc=0x0c03f69au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c03f69c;
P_0c03f69c: /* original 2fa6, guest PC 0x0c03f69c */
if(!s->budget--) { s->failed_pc=0x0c03f69cu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c03f69e;
P_0c03f69e: /* original 2f96, guest PC 0x0c03f69e */
if(!s->budget--) { s->failed_pc=0x0c03f69eu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c03f6a0;
P_0c03f6a0: /* original 2f86, guest PC 0x0c03f6a0 */
if(!s->budget--) { s->failed_pc=0x0c03f6a0u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c03f6a2;
P_0c03f6a2: /* original 4f22, guest PC 0x0c03f6a2 */
if(!s->budget--) { s->failed_pc=0x0c03f6a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f6a4;
P_0c03f6a4: /* original 4f12, guest PC 0x0c03f6a4 */
if(!s->budget--) { s->failed_pc=0x0c03f6a4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f6a6;
P_0c03f6a6: /* original 7ff0, guest PC 0x0c03f6a6 */
if(!s->budget--) { s->failed_pc=0x0c03f6a6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03f6a8;
P_0c03f6a8: /* original 1f33, guest PC 0x0c03f6a8 */
if(!s->budget--) { s->failed_pc=0x0c03f6a8u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c03f6aa;
P_0c03f6aa: /* original de3d, guest PC 0x0c03f6aa */
if(!s->budget--) { s->failed_pc=0x0c03f6aau; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f6ac;
P_0c03f6ac: /* original d838, guest PC 0x0c03f6ac */
if(!s->budget--) { s->failed_pc=0x0c03f6acu; return 0; }
r[8]=read(ram,0x0c03f790u,4);
goto P_0c03f6ae;
P_0c03f6ae: /* original dc3f, guest PC 0x0c03f6ae */
if(!s->budget--) { s->failed_pc=0x0c03f6aeu; return 0; }
r[12]=read(ram,0x0c03f7acu,4);
goto P_0c03f6b0;
P_0c03f6b0: /* original 2f42, guest PC 0x0c03f6b0 */
if(!s->budget--) { s->failed_pc=0x0c03f6b0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03f6b2;
P_0c03f6b2: /* original d23c, guest PC 0x0c03f6b2 */
if(!s->budget--) { s->failed_pc=0x0c03f6b2u; return 0; }
r[2]=read(ram,0x0c03f7a4u,4);
goto P_0c03f6b4;
P_0c03f6b4: /* original 6322, guest PC 0x0c03f6b4 */
if(!s->budget--) { s->failed_pc=0x0c03f6b4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f6b6;
P_0c03f6b6: /* original a046, guest PC 0x0c03f6b6 */
if(!s->budget--) { s->failed_pc=0x0c03f6b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03f746;
P_0c03f6b8: /* original 1f31, guest PC 0x0c03f6b8 */
if(!s->budget--) { s->failed_pc=0x0c03f6b8u; return 0; }
write(ram,r[15]+4,r[3],4);
return vf3_matrix_family(0x0c03f6bau,s,ram);
P_0c03f6c0: /* original 59f1, guest PC 0x0c03f6c0 */
if(!s->budget--) { s->failed_pc=0x0c03f6c0u; return 0; }
r[9]=read(ram,r[15]+4,4);
goto P_0c03f6c2;
P_0c03f6c2: /* original e200, guest PC 0x0c03f6c2 */
if(!s->budget--) { s->failed_pc=0x0c03f6c2u; return 0; }
r[2]=0x00000000u;
goto P_0c03f6c4;
P_0c03f6c4: /* original 63e2, guest PC 0x0c03f6c4 */
if(!s->budget--) { s->failed_pc=0x0c03f6c4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f6c6;
P_0c03f6c6: /* original 6b93, guest PC 0x0c03f6c6 */
if(!s->budget--) { s->failed_pc=0x0c03f6c6u; return 0; }
r[11]=r[9];
goto P_0c03f6c8;
P_0c03f6c8: /* original 4b08, guest PC 0x0c03f6c8 */
if(!s->budget--) { s->failed_pc=0x0c03f6c8u; return 0; }
r[11]<<=2;
goto P_0c03f6ca;
P_0c03f6ca: /* original 4b00, guest PC 0x0c03f6ca */
if(!s->budget--) { s->failed_pc=0x0c03f6cau; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c03f6cc;
P_0c03f6cc: /* original 33bc, guest PC 0x0c03f6cc */
if(!s->budget--) { s->failed_pc=0x0c03f6ccu; return 0; }
r[3]+=r[11];
goto P_0c03f6ce;
P_0c03f6ce: /* original 6132, guest PC 0x0c03f6ce */
if(!s->budget--) { s->failed_pc=0x0c03f6ceu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c03f6d0;
P_0c03f6d0: /* original 3126, guest PC 0x0c03f6d0 */
if(!s->budget--) { s->failed_pc=0x0c03f6d0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c03f6d2;
P_0c03f6d2: /* original 8b32, guest PC 0x0c03f6d2 */
if(!s->budget--) { s->failed_pc=0x0c03f6d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f73a; }
goto P_0c03f6d4;
P_0c03f6d4: /* original 60e2, guest PC 0x0c03f6d4 */
if(!s->budget--) { s->failed_pc=0x0c03f6d4u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03f6d6;
P_0c03f6d6: /* original 30bc, guest PC 0x0c03f6d6 */
if(!s->budget--) { s->failed_pc=0x0c03f6d6u; return 0; }
r[0]+=r[11];
goto P_0c03f6d8;
P_0c03f6d8: /* original 6302, guest PC 0x0c03f6d8 */
if(!s->budget--) { s->failed_pc=0x0c03f6d8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c03f6da;
P_0c03f6da: /* original 73ff, guest PC 0x0c03f6da */
if(!s->budget--) { s->failed_pc=0x0c03f6dau; return 0; }
r[3]+=0xffffffffu;
goto P_0c03f6dc;
P_0c03f6dc: /* original 2032, guest PC 0x0c03f6dc */
if(!s->budget--) { s->failed_pc=0x0c03f6dcu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c03f6de;
P_0c03f6de: /* original 61e2, guest PC 0x0c03f6de */
if(!s->budget--) { s->failed_pc=0x0c03f6deu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f6e0;
P_0c03f6e0: /* original 31bc, guest PC 0x0c03f6e0 */
if(!s->budget--) { s->failed_pc=0x0c03f6e0u; return 0; }
r[1]+=r[11];
goto P_0c03f6e2;
P_0c03f6e2: /* original 6312, guest PC 0x0c03f6e2 */
if(!s->budget--) { s->failed_pc=0x0c03f6e2u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c03f6e4;
P_0c03f6e4: /* original 2338, guest PC 0x0c03f6e4 */
if(!s->budget--) { s->failed_pc=0x0c03f6e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f6e6;
P_0c03f6e6: /* original 8b28, guest PC 0x0c03f6e6 */
if(!s->budget--) { s->failed_pc=0x0c03f6e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f73a; }
goto P_0c03f6e8;
P_0c03f6e8: /* original 63e2, guest PC 0x0c03f6e8 */
if(!s->budget--) { s->failed_pc=0x0c03f6e8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f6ea;
P_0c03f6ea: /* original 33bc, guest PC 0x0c03f6ea */
if(!s->budget--) { s->failed_pc=0x0c03f6eau; return 0; }
r[3]+=r[11];
goto P_0c03f6ec;
P_0c03f6ec: /* original 5131, guest PC 0x0c03f6ec */
if(!s->budget--) { s->failed_pc=0x0c03f6ecu; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c03f6ee;
P_0c03f6ee: /* original e33c, guest PC 0x0c03f6ee */
if(!s->budget--) { s->failed_pc=0x0c03f6eeu; return 0; }
r[3]=0x0000003cu;
goto P_0c03f6f0;
P_0c03f6f0: /* original 0137, guest PC 0x0c03f6f0 */
if(!s->budget--) { s->failed_pc=0x0c03f6f0u; return 0; }
r[19]=r[1]*r[3];
goto P_0c03f6f2;
P_0c03f6f2: /* original 1f12, guest PC 0x0c03f6f2 */
if(!s->budget--) { s->failed_pc=0x0c03f6f2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c03f6f4;
P_0c03f6f4: /* original 61c2, guest PC 0x0c03f6f4 */
if(!s->budget--) { s->failed_pc=0x0c03f6f4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c03f6f6;
P_0c03f6f6: /* original 0a1a, guest PC 0x0c03f6f6 */
if(!s->budget--) { s->failed_pc=0x0c03f6f6u; return 0; }
r[10]=r[19];
goto P_0c03f6f8;
P_0c03f6f8: /* original 31ac, guest PC 0x0c03f6f8 */
if(!s->budget--) { s->failed_pc=0x0c03f6f8u; return 0; }
r[1]+=r[10];
goto P_0c03f6fa;
P_0c03f6fa: /* original 501a, guest PC 0x0c03f6fa */
if(!s->budget--) { s->failed_pc=0x0c03f6fau; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c03f6fc;
P_0c03f6fc: /* original 2008, guest PC 0x0c03f6fc */
if(!s->budget--) { s->failed_pc=0x0c03f6fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f6fe;
P_0c03f6fe: /* original 8b08, guest PC 0x0c03f6fe */
if(!s->budget--) { s->failed_pc=0x0c03f6feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f712; }
goto P_0c03f700;
P_0c03f700: /* original d12d, guest PC 0x0c03f700 */
if(!s->budget--) { s->failed_pc=0x0c03f700u; return 0; }
r[1]=read(ram,0x0c03f7b8u,4);
goto P_0c03f702;
P_0c03f702: /* original 64c2, guest PC 0x0c03f702 */
if(!s->budget--) { s->failed_pc=0x0c03f702u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c03f704;
P_0c03f704: /* original 410b, guest PC 0x0c03f704 */
if(!s->budget--) { s->failed_pc=0x0c03f704u; return 0; }
target=r[1];
r[16]=0x0c03f708u;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f708u) { target=s->pc; goto dispatch; }
goto P_0c03f708;
P_0c03f706: /* original 34ac, guest PC 0x0c03f706 */
if(!s->budget--) { s->failed_pc=0x0c03f706u; return 0; }
r[4]+=r[10];
goto P_0c03f708;
P_0c03f708: /* original 6403, guest PC 0x0c03f708 */
if(!s->budget--) { s->failed_pc=0x0c03f708u; return 0; }
r[4]=r[0];
goto P_0c03f70a;
P_0c03f70a: /* original 2448, guest PC 0x0c03f70a */
if(!s->budget--) { s->failed_pc=0x0c03f70au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f70c;
P_0c03f70c: /* original 8901, guest PC 0x0c03f70c */
if(!s->budget--) { s->failed_pc=0x0c03f70cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f712; }
goto P_0c03f70e;
P_0c03f70e: /* original e201, guest PC 0x0c03f70e */
if(!s->budget--) { s->failed_pc=0x0c03f70eu; return 0; }
r[2]=0x00000001u;
goto P_0c03f710;
P_0c03f710: /* original 1f23, guest PC 0x0c03f710 */
if(!s->budget--) { s->failed_pc=0x0c03f710u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c03f712;
P_0c03f712: /* original 63c2, guest PC 0x0c03f712 */
if(!s->budget--) { s->failed_pc=0x0c03f712u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f714;
P_0c03f714: /* original e200, guest PC 0x0c03f714 */
if(!s->budget--) { s->failed_pc=0x0c03f714u; return 0; }
r[2]=0x00000000u;
goto P_0c03f716;
P_0c03f716: /* original 33ac, guest PC 0x0c03f716 */
if(!s->budget--) { s->failed_pc=0x0c03f716u; return 0; }
r[3]+=r[10];
goto P_0c03f718;
P_0c03f718: /* original 132b, guest PC 0x0c03f718 */
if(!s->budget--) { s->failed_pc=0x0c03f718u; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c03f71a;
P_0c03f71a: /* original 63c2, guest PC 0x0c03f71a */
if(!s->budget--) { s->failed_pc=0x0c03f71au; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f71c;
P_0c03f71c: /* original 33ac, guest PC 0x0c03f71c */
if(!s->budget--) { s->failed_pc=0x0c03f71cu; return 0; }
r[3]+=r[10];
goto P_0c03f71e;
P_0c03f71e: /* original 13de, guest PC 0x0c03f71e */
if(!s->budget--) { s->failed_pc=0x0c03f71eu; return 0; }
write(ram,r[3]+56,r[13],4);
goto P_0c03f720;
P_0c03f720: /* original d326, guest PC 0x0c03f720 */
if(!s->budget--) { s->failed_pc=0x0c03f720u; return 0; }
r[3]=read(ram,0x0c03f7bcu,4);
goto P_0c03f722;
P_0c03f722: /* original 430b, guest PC 0x0c03f722 */
if(!s->budget--) { s->failed_pc=0x0c03f722u; return 0; }
target=r[3];
r[16]=0x0c03f726u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f726u) { target=s->pc; goto dispatch; }
goto P_0c03f726;
P_0c03f724: /* original 54f2, guest PC 0x0c03f724 */
if(!s->budget--) { s->failed_pc=0x0c03f724u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c03f726;
P_0c03f726: /* original 6082, guest PC 0x0c03f726 */
if(!s->budget--) { s->failed_pc=0x0c03f726u; return 0; }
tmp=read(ram,r[8],4);
r[0]=tmp;
goto P_0c03f728;
P_0c03f728: /* original 6a93, guest PC 0x0c03f728 */
if(!s->budget--) { s->failed_pc=0x0c03f728u; return 0; }
r[10]=r[9];
goto P_0c03f72a;
P_0c03f72a: /* original 4a00, guest PC 0x0c03f72a */
if(!s->budget--) { s->failed_pc=0x0c03f72au; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c03f72c;
P_0c03f72c: /* original b338, guest PC 0x0c03f72c */
if(!s->budget--) { s->failed_pc=0x0c03f72cu; return 0; }
target=0x0c03fda0u; r[16]=0x0c03f730u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f730u) { target=s->pc; goto dispatch; }
goto P_0c03f730;
P_0c03f72e: /* original 04ad, guest PC 0x0c03f72e */
if(!s->budget--) { s->failed_pc=0x0c03f72eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c03f730;
P_0c03f730: /* original 62e2, guest PC 0x0c03f730 */
if(!s->budget--) { s->failed_pc=0x0c03f730u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f732;
P_0c03f732: /* original 32bc, guest PC 0x0c03f732 */
if(!s->budget--) { s->failed_pc=0x0c03f732u; return 0; }
r[2]+=r[11];
goto P_0c03f734;
P_0c03f734: /* original 12d1, guest PC 0x0c03f734 */
if(!s->budget--) { s->failed_pc=0x0c03f734u; return 0; }
write(ram,r[2]+4,r[13],4);
goto P_0c03f736;
P_0c03f736: /* original 6082, guest PC 0x0c03f736 */
if(!s->budget--) { s->failed_pc=0x0c03f736u; return 0; }
tmp=read(ram,r[8],4);
r[0]=tmp;
goto P_0c03f738;
P_0c03f738: /* original 0ad5, guest PC 0x0c03f738 */
if(!s->budget--) { s->failed_pc=0x0c03f738u; return 0; }
write(ram,r[10]+r[0],r[13],2);
goto P_0c03f73a;
P_0c03f73a: /* original 63f2, guest PC 0x0c03f73a */
if(!s->budget--) { s->failed_pc=0x0c03f73au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c03f73c;
P_0c03f73c: /* original 7310, guest PC 0x0c03f73c */
if(!s->budget--) { s->failed_pc=0x0c03f73cu; return 0; }
r[3]+=0x00000010u;
goto P_0c03f73e;
P_0c03f73e: /* original 2f32, guest PC 0x0c03f73e */
if(!s->budget--) { s->failed_pc=0x0c03f73eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f740;
P_0c03f740: /* original 52f1, guest PC 0x0c03f740 */
if(!s->budget--) { s->failed_pc=0x0c03f740u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c03f742;
P_0c03f742: /* original 7201, guest PC 0x0c03f742 */
if(!s->budget--) { s->failed_pc=0x0c03f742u; return 0; }
r[2]+=0x00000001u;
goto P_0c03f744;
P_0c03f744: /* original 1f21, guest PC 0x0c03f744 */
if(!s->budget--) { s->failed_pc=0x0c03f744u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03f746;
P_0c03f746: /* original 60f2, guest PC 0x0c03f746 */
if(!s->budget--) { s->failed_pc=0x0c03f746u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f748;
P_0c03f748: /* original 5001, guest PC 0x0c03f748 */
if(!s->budget--) { s->failed_pc=0x0c03f748u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c03f74a;
P_0c03f74a: /* original 88ff, guest PC 0x0c03f74a */
if(!s->budget--) { s->failed_pc=0x0c03f74au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f74c;
P_0c03f74c: /* original 8bb8, guest PC 0x0c03f74c */
if(!s->budget--) { s->failed_pc=0x0c03f74cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f6c0; }
goto P_0c03f74e;
P_0c03f74e: /* original 50f3, guest PC 0x0c03f74e */
if(!s->budget--) { s->failed_pc=0x0c03f74eu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c03f750;
P_0c03f750: /* original 7f10, guest PC 0x0c03f750 */
if(!s->budget--) { s->failed_pc=0x0c03f750u; return 0; }
r[15]+=0x00000010u;
goto P_0c03f752;
P_0c03f752: /* original 4f16, guest PC 0x0c03f752 */
if(!s->budget--) { s->failed_pc=0x0c03f752u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f754;
P_0c03f754: /* original 4f26, guest PC 0x0c03f754 */
if(!s->budget--) { s->failed_pc=0x0c03f754u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f756;
P_0c03f756: /* original 68f6, guest PC 0x0c03f756 */
if(!s->budget--) { s->failed_pc=0x0c03f756u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f758;
P_0c03f758: /* original 69f6, guest PC 0x0c03f758 */
if(!s->budget--) { s->failed_pc=0x0c03f758u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f75a;
P_0c03f75a: /* original 6af6, guest PC 0x0c03f75a */
if(!s->budget--) { s->failed_pc=0x0c03f75au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f75c;
P_0c03f75c: /* original 6bf6, guest PC 0x0c03f75c */
if(!s->budget--) { s->failed_pc=0x0c03f75cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f75e;
P_0c03f75e: /* original 6cf6, guest PC 0x0c03f75e */
if(!s->budget--) { s->failed_pc=0x0c03f75eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f760;
P_0c03f760: /* original 6df6, guest PC 0x0c03f760 */
if(!s->budget--) { s->failed_pc=0x0c03f760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f762;
P_0c03f762: /* original 000b, guest PC 0x0c03f762 */
if(!s->budget--) { s->failed_pc=0x0c03f762u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f764: /* original 6ef6, guest PC 0x0c03f764 */
if(!s->budget--) { s->failed_pc=0x0c03f764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f766u,s,ram);
P_0c03fda0: /* original e31f, guest PC 0x0c03fda0 */
if(!s->budget--) { s->failed_pc=0x0c03fda0u; return 0; }
r[3]=0x0000001fu;
goto P_0c03fda2;
P_0c03fda2: /* original d208, guest PC 0x0c03fda2 */
if(!s->budget--) { s->failed_pc=0x0c03fda2u; return 0; }
r[2]=read(ram,0x0c03fdc4u,4);
goto P_0c03fda4;
P_0c03fda4: /* original e501, guest PC 0x0c03fda4 */
if(!s->budget--) { s->failed_pc=0x0c03fda4u; return 0; }
r[5]=0x00000001u;
goto P_0c03fda6;
P_0c03fda6: /* original 2349, guest PC 0x0c03fda6 */
if(!s->budget--) { s->failed_pc=0x0c03fda6u; return 0; }
r[3]&=r[4];
goto P_0c03fda8;
P_0c03fda8: /* original 6022, guest PC 0x0c03fda8 */
if(!s->budget--) { s->failed_pc=0x0c03fda8u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c03fdaa;
P_0c03fdaa: /* original 453c, guest PC 0x0c03fdaa */
if(!s->budget--) { s->failed_pc=0x0c03fdaau; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c03fdac;
P_0c03fdac: /* original e3fb, guest PC 0x0c03fdac */
if(!s->budget--) { s->failed_pc=0x0c03fdacu; return 0; }
r[3]=0xfffffffbu;
goto P_0c03fdae;
P_0c03fdae: /* original 443c, guest PC 0x0c03fdae */
if(!s->budget--) { s->failed_pc=0x0c03fdaeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c03fdb0;
P_0c03fdb0: /* original 6343, guest PC 0x0c03fdb0 */
if(!s->budget--) { s->failed_pc=0x0c03fdb0u; return 0; }
r[3]=r[4];
goto P_0c03fdb2;
P_0c03fdb2: /* original 4308, guest PC 0x0c03fdb2 */
if(!s->budget--) { s->failed_pc=0x0c03fdb2u; return 0; }
r[3]<<=2;
goto P_0c03fdb4;
P_0c03fdb4: /* original 013e, guest PC 0x0c03fdb4 */
if(!s->budget--) { s->failed_pc=0x0c03fdb4u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c03fdb6;
P_0c03fdb6: /* original 6557, guest PC 0x0c03fdb6 */
if(!s->budget--) { s->failed_pc=0x0c03fdb6u; return 0; }
r[5]=~r[5];
goto P_0c03fdb8;
P_0c03fdb8: /* original 2159, guest PC 0x0c03fdb8 */
if(!s->budget--) { s->failed_pc=0x0c03fdb8u; return 0; }
r[1]&=r[5];
goto P_0c03fdba;
P_0c03fdba: /* original 000b, guest PC 0x0c03fdba */
if(!s->budget--) { s->failed_pc=0x0c03fdbau; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[1],4);
s->pc=target; return ram->oob==0;
P_0c03fdbc: /* original 0316, guest PC 0x0c03fdbc */
if(!s->budget--) { s->failed_pc=0x0c03fdbcu; return 0; }
write(ram,r[3]+r[0],r[1],4);
return vf3_matrix_family(0x0c03fdbeu,s,ram);
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
return vf3_matrix_family(0x0c042f08u,s,ram);
P_0c042f3a: /* original 5326, guest PC 0x0c042f3a */
if(!s->budget--) { s->failed_pc=0x0c042f3au; return 0; }
r[3]=read(ram,r[2]+24,4);
goto P_0c042f3c;
P_0c042f3c: /* original 1107, guest PC 0x0c042f3c */
if(!s->budget--) { s->failed_pc=0x0c042f3cu; return 0; }
write(ram,r[1]+28,r[0],4);
goto P_0c042f3e;
P_0c042f3e: /* original 5025, guest PC 0x0c042f3e */
if(!s->budget--) { s->failed_pc=0x0c042f3eu; return 0; }
r[0]=read(ram,r[2]+20,4);
goto P_0c042f40;
P_0c042f40: /* original 1136, guest PC 0x0c042f40 */
if(!s->budget--) { s->failed_pc=0x0c042f40u; return 0; }
write(ram,r[1]+24,r[3],4);
goto P_0c042f42;
P_0c042f42: /* original 5324, guest PC 0x0c042f42 */
if(!s->budget--) { s->failed_pc=0x0c042f42u; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c042f44;
P_0c042f44: /* original 1105, guest PC 0x0c042f44 */
if(!s->budget--) { s->failed_pc=0x0c042f44u; return 0; }
write(ram,r[1]+20,r[0],4);
goto P_0c042f46;
P_0c042f46: /* original 5023, guest PC 0x0c042f46 */
if(!s->budget--) { s->failed_pc=0x0c042f46u; return 0; }
r[0]=read(ram,r[2]+12,4);
goto P_0c042f48;
P_0c042f48: /* original 1134, guest PC 0x0c042f48 */
if(!s->budget--) { s->failed_pc=0x0c042f48u; return 0; }
write(ram,r[1]+16,r[3],4);
goto P_0c042f4a;
P_0c042f4a: /* original 5322, guest PC 0x0c042f4a */
if(!s->budget--) { s->failed_pc=0x0c042f4au; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c042f4c;
P_0c042f4c: /* original 1103, guest PC 0x0c042f4c */
if(!s->budget--) { s->failed_pc=0x0c042f4cu; return 0; }
write(ram,r[1]+12,r[0],4);
goto P_0c042f4e;
P_0c042f4e: /* original 5021, guest PC 0x0c042f4e */
if(!s->budget--) { s->failed_pc=0x0c042f4eu; return 0; }
r[0]=read(ram,r[2]+4,4);
goto P_0c042f50;
P_0c042f50: /* original 1132, guest PC 0x0c042f50 */
if(!s->budget--) { s->failed_pc=0x0c042f50u; return 0; }
write(ram,r[1]+8,r[3],4);
goto P_0c042f52;
P_0c042f52: /* original 6322, guest PC 0x0c042f52 */
if(!s->budget--) { s->failed_pc=0x0c042f52u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c042f54;
P_0c042f54: /* original 1101, guest PC 0x0c042f54 */
if(!s->budget--) { s->failed_pc=0x0c042f54u; return 0; }
write(ram,r[1]+4,r[0],4);
goto P_0c042f56;
P_0c042f56: /* original 2132, guest PC 0x0c042f56 */
if(!s->budget--) { s->failed_pc=0x0c042f56u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c042f58;
P_0c042f58: /* original 000b, guest PC 0x0c042f58 */
if(!s->budget--) { s->failed_pc=0x0c042f58u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042f5a: /* original 63f6, guest PC 0x0c042f5a */
if(!s->budget--) { s->failed_pc=0x0c042f5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
return vf3_matrix_family(0x0c042f5cu,s,ram);
P_0c043eb8: /* original 6043, guest PC 0x0c043eb8 */
if(!s->budget--) { s->failed_pc=0x0c043eb8u; return 0; }
r[0]=r[4];
goto P_0c043eba;
P_0c043eba: /* original 4000, guest PC 0x0c043eba */
if(!s->budget--) { s->failed_pc=0x0c043ebau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043ebc;
P_0c043ebc: /* original 6343, guest PC 0x0c043ebc */
if(!s->budget--) { s->failed_pc=0x0c043ebcu; return 0; }
r[3]=r[4];
goto P_0c043ebe;
P_0c043ebe: /* original 303c, guest PC 0x0c043ebe */
if(!s->budget--) { s->failed_pc=0x0c043ebeu; return 0; }
r[0]+=r[3];
goto P_0c043ec0;
P_0c043ec0: /* original 4008, guest PC 0x0c043ec0 */
if(!s->budget--) { s->failed_pc=0x0c043ec0u; return 0; }
r[0]<<=2;
goto P_0c043ec2;
P_0c043ec2: /* original d218, guest PC 0x0c043ec2 */
if(!s->budget--) { s->failed_pc=0x0c043ec2u; return 0; }
r[2]=read(ram,0x0c043f24u,4);
goto P_0c043ec4;
P_0c043ec4: /* original 4000, guest PC 0x0c043ec4 */
if(!s->budget--) { s->failed_pc=0x0c043ec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043ec6;
P_0c043ec6: /* original 600f, guest PC 0x0c043ec6 */
if(!s->budget--) { s->failed_pc=0x0c043ec6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c043ec8;
P_0c043ec8: /* original 000b, guest PC 0x0c043ec8 */
if(!s->budget--) { s->failed_pc=0x0c043ec8u; return 0; }
target=r[16];
r[0]+=r[2];
s->pc=target; return ram->oob==0;
P_0c043eca: /* original 302c, guest PC 0x0c043eca */
if(!s->budget--) { s->failed_pc=0x0c043ecau; return 0; }
r[0]+=r[2];
goto P_0c043ecc;
P_0c043ecc: /* original 4f22, guest PC 0x0c043ecc */
if(!s->budget--) { s->failed_pc=0x0c043eccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043ece;
P_0c043ece: /* original d317, guest PC 0x0c043ece */
if(!s->budget--) { s->failed_pc=0x0c043eceu; return 0; }
r[3]=read(ram,0x0c043f2cu,4);
goto P_0c043ed0;
P_0c043ed0: /* original 430b, guest PC 0x0c043ed0 */
if(!s->budget--) { s->failed_pc=0x0c043ed0u; return 0; }
target=r[3];
r[16]=0x0c043ed4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043ed4u) { target=s->pc; goto dispatch; }
goto P_0c043ed4;
P_0c043ed2: /* original 0009, guest PC 0x0c043ed2 */
if(!s->budget--) { s->failed_pc=0x0c043ed2u; return 0; }
goto P_0c043ed4;
P_0c043ed4: /* original 4f26, guest PC 0x0c043ed4 */
if(!s->budget--) { s->failed_pc=0x0c043ed4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043ed6;
P_0c043ed6: /* original 000b, guest PC 0x0c043ed6 */
if(!s->budget--) { s->failed_pc=0x0c043ed6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043ed8: /* original 0009, guest PC 0x0c043ed8 */
if(!s->budget--) { s->failed_pc=0x0c043ed8u; return 0; }
return vf3_matrix_family(0x0c043edau,s,ram);
P_0c0441aa: /* original d33f, guest PC 0x0c0441aa */
if(!s->budget--) { s->failed_pc=0x0c0441aau; return 0; }
r[3]=read(ram,0x0c0442a8u,4);
goto P_0c0441ac;
P_0c0441ac: /* original 432b, guest PC 0x0c0441ac */
if(!s->budget--) { s->failed_pc=0x0c0441acu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0441ae: /* original 0009, guest PC 0x0c0441ae */
if(!s->budget--) { s->failed_pc=0x0c0441aeu; return 0; }
return vf3_matrix_family(0x0c0441b0u,s,ram);
P_0c053cec: /* original 4f22, guest PC 0x0c053cec */
if(!s->budget--) { s->failed_pc=0x0c053cecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053cee;
P_0c053cee: /* original 0eee, guest PC 0x0c053cee */
if(!s->budget--) { s->failed_pc=0x0c053ceeu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c053cf0;
P_0c053cf0: /* original d315, guest PC 0x0c053cf0 */
if(!s->budget--) { s->failed_pc=0x0c053cf0u; return 0; }
r[3]=read(ram,0x0c053d48u,4);
goto P_0c053cf2;
P_0c053cf2: /* original 7ff8, guest PC 0x0c053cf2 */
if(!s->budget--) { s->failed_pc=0x0c053cf2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053cf4;
P_0c053cf4: /* original 430b, guest PC 0x0c053cf4 */
if(!s->budget--) { s->failed_pc=0x0c053cf4u; return 0; }
target=r[3];
r[16]=0x0c053cf8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053cf8u) { target=s->pc; goto dispatch; }
goto P_0c053cf8;
P_0c053cf6: /* original 64e3, guest PC 0x0c053cf6 */
if(!s->budget--) { s->failed_pc=0x0c053cf6u; return 0; }
r[4]=r[14];
goto P_0c053cf8;
P_0c053cf8: /* original 1f01, guest PC 0x0c053cf8 */
if(!s->budget--) { s->failed_pc=0x0c053cf8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c053cfa;
P_0c053cfa: /* original d314, guest PC 0x0c053cfa */
if(!s->budget--) { s->failed_pc=0x0c053cfau; return 0; }
r[3]=read(ram,0x0c053d4cu,4);
goto P_0c053cfc;
P_0c053cfc: /* original 430b, guest PC 0x0c053cfc */
if(!s->budget--) { s->failed_pc=0x0c053cfcu; return 0; }
target=r[3];
r[16]=0x0c053d00u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053d00u) { target=s->pc; goto dispatch; }
goto P_0c053d00;
P_0c053cfe: /* original 64e3, guest PC 0x0c053cfe */
if(!s->budget--) { s->failed_pc=0x0c053cfeu; return 0; }
r[4]=r[14];
goto P_0c053d00;
P_0c053d00: /* original 2f02, guest PC 0x0c053d00 */
if(!s->budget--) { s->failed_pc=0x0c053d00u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053d02;
P_0c053d02: /* original 53f1, guest PC 0x0c053d02 */
if(!s->budget--) { s->failed_pc=0x0c053d02u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053d04;
P_0c053d04: /* original 6230, guest PC 0x0c053d04 */
if(!s->budget--) { s->failed_pc=0x0c053d04u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c053d06;
P_0c053d06: /* original 2228, guest PC 0x0c053d06 */
if(!s->budget--) { s->failed_pc=0x0c053d06u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c053d08;
P_0c053d08: /* original 8908, guest PC 0x0c053d08 */
if(!s->budget--) { s->failed_pc=0x0c053d08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053d1c; }
goto P_0c053d0a;
P_0c053d0a: /* original d311, guest PC 0x0c053d0a */
if(!s->budget--) { s->failed_pc=0x0c053d0au; return 0; }
r[3]=read(ram,0x0c053d50u,4);
goto P_0c053d0c;
P_0c053d0c: /* original 430b, guest PC 0x0c053d0c */
if(!s->budget--) { s->failed_pc=0x0c053d0cu; return 0; }
target=r[3];
r[16]=0x0c053d10u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053d10u) { target=s->pc; goto dispatch; }
goto P_0c053d10;
P_0c053d0e: /* original 64e3, guest PC 0x0c053d0e */
if(!s->budget--) { s->failed_pc=0x0c053d0eu; return 0; }
r[4]=r[14];
goto P_0c053d10;
P_0c053d10: /* original 2008, guest PC 0x0c053d10 */
if(!s->budget--) { s->failed_pc=0x0c053d10u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c053d12;
P_0c053d12: /* original 8b03, guest PC 0x0c053d12 */
if(!s->budget--) { s->failed_pc=0x0c053d12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053d1c; }
goto P_0c053d14;
P_0c053d14: /* original 60f2, guest PC 0x0c053d14 */
if(!s->budget--) { s->failed_pc=0x0c053d14u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c053d16;
P_0c053d16: /* original 6002, guest PC 0x0c053d16 */
if(!s->budget--) { s->failed_pc=0x0c053d16u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c053d18;
P_0c053d18: /* original c802, guest PC 0x0c053d18 */
if(!s->budget--) { s->failed_pc=0x0c053d18u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c053d1a;
P_0c053d1a: /* original 8b04, guest PC 0x0c053d1a */
if(!s->budget--) { s->failed_pc=0x0c053d1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053d26; }
goto P_0c053d1c;
P_0c053d1c: /* original 7f08, guest PC 0x0c053d1c */
if(!s->budget--) { s->failed_pc=0x0c053d1cu; return 0; }
r[15]+=0x00000008u;
goto P_0c053d1e;
P_0c053d1e: /* original 4f26, guest PC 0x0c053d1e */
if(!s->budget--) { s->failed_pc=0x0c053d1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053d20;
P_0c053d20: /* original e000, guest PC 0x0c053d20 */
if(!s->budget--) { s->failed_pc=0x0c053d20u; return 0; }
r[0]=0x00000000u;
goto P_0c053d22;
P_0c053d22: /* original 000b, guest PC 0x0c053d22 */
if(!s->budget--) { s->failed_pc=0x0c053d22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053d24: /* original 6ef6, guest PC 0x0c053d24 */
if(!s->budget--) { s->failed_pc=0x0c053d24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c053d26;
P_0c053d26: /* original e001, guest PC 0x0c053d26 */
if(!s->budget--) { s->failed_pc=0x0c053d26u; return 0; }
r[0]=0x00000001u;
goto P_0c053d28;
P_0c053d28: /* original 7f08, guest PC 0x0c053d28 */
if(!s->budget--) { s->failed_pc=0x0c053d28u; return 0; }
r[15]+=0x00000008u;
goto P_0c053d2a;
P_0c053d2a: /* original 4f26, guest PC 0x0c053d2a */
if(!s->budget--) { s->failed_pc=0x0c053d2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053d2c;
P_0c053d2c: /* original 000b, guest PC 0x0c053d2c */
if(!s->budget--) { s->failed_pc=0x0c053d2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053d2e: /* original 6ef6, guest PC 0x0c053d2e */
if(!s->budget--) { s->failed_pc=0x0c053d2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c053d30u,s,ram);
P_0c05ece2: /* original 2fe6, guest PC 0x0c05ece2 */
if(!s->budget--) { s->failed_pc=0x0c05ece2u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c05ece4;
P_0c05ece4: /* original 4f22, guest PC 0x0c05ece4 */
if(!s->budget--) { s->failed_pc=0x0c05ece4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ece6;
P_0c05ece6: /* original 6e43, guest PC 0x0c05ece6 */
if(!s->budget--) { s->failed_pc=0x0c05ece6u; return 0; }
r[14]=r[4];
goto P_0c05ece8;
P_0c05ece8: /* original 60e2, guest PC 0x0c05ece8 */
if(!s->budget--) { s->failed_pc=0x0c05ece8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05ecea;
P_0c05ecea: /* original 600d, guest PC 0x0c05ecea */
if(!s->budget--) { s->failed_pc=0x0c05eceau; return 0; }
r[0]=r[0]&65535u;
goto P_0c05ecec;
P_0c05ecec: /* original 8803, guest PC 0x0c05ecec */
if(!s->budget--) { s->failed_pc=0x0c05ececu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05ecee;
P_0c05ecee: /* original 8b04, guest PC 0x0c05ecee */
if(!s->budget--) { s->failed_pc=0x0c05eceeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ecfa; }
goto P_0c05ecf0;
P_0c05ecf0: /* original d20f, guest PC 0x0c05ecf0 */
if(!s->budget--) { s->failed_pc=0x0c05ecf0u; return 0; }
r[2]=read(ram,0x0c05ed30u,4);
goto P_0c05ecf2;
P_0c05ecf2: /* original 420b, guest PC 0x0c05ecf2 */
if(!s->budget--) { s->failed_pc=0x0c05ecf2u; return 0; }
target=r[2];
r[16]=0x0c05ecf6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ecf6u) { target=s->pc; goto dispatch; }
goto P_0c05ecf6;
P_0c05ecf4: /* original 64e3, guest PC 0x0c05ecf4 */
if(!s->budget--) { s->failed_pc=0x0c05ecf4u; return 0; }
r[4]=r[14];
goto P_0c05ecf6;
P_0c05ecf6: /* original a003, guest PC 0x0c05ecf6 */
if(!s->budget--) { s->failed_pc=0x0c05ecf6u; return 0; }
goto P_0c05ed00;
P_0c05ecf8: /* original 0009, guest PC 0x0c05ecf8 */
if(!s->budget--) { s->failed_pc=0x0c05ecf8u; return 0; }
goto P_0c05ecfa;
P_0c05ecfa: /* original d20e, guest PC 0x0c05ecfa */
if(!s->budget--) { s->failed_pc=0x0c05ecfau; return 0; }
r[2]=read(ram,0x0c05ed34u,4);
goto P_0c05ecfc;
P_0c05ecfc: /* original 420b, guest PC 0x0c05ecfc */
if(!s->budget--) { s->failed_pc=0x0c05ecfcu; return 0; }
target=r[2];
r[16]=0x0c05ed00u;
r[4]=read(ram,r[14]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ed00u) { target=s->pc; goto dispatch; }
goto P_0c05ed00;
P_0c05ecfe: /* original 54e7, guest PC 0x0c05ecfe */
if(!s->budget--) { s->failed_pc=0x0c05ecfeu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05ed00;
P_0c05ed00: /* original 4f26, guest PC 0x0c05ed00 */
if(!s->budget--) { s->failed_pc=0x0c05ed00u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ed02;
P_0c05ed02: /* original 000b, guest PC 0x0c05ed02 */
if(!s->budget--) { s->failed_pc=0x0c05ed02u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05ed04: /* original 6ef6, guest PC 0x0c05ed04 */
if(!s->budget--) { s->failed_pc=0x0c05ed04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05ed06u,s,ram);
P_0c061596: /* original 2fe6, guest PC 0x0c061596 */
if(!s->budget--) { s->failed_pc=0x0c061596u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c061598;
P_0c061598: /* original 2fd6, guest PC 0x0c061598 */
if(!s->budget--) { s->failed_pc=0x0c061598u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c06159a;
P_0c06159a: /* original 6d43, guest PC 0x0c06159a */
if(!s->budget--) { s->failed_pc=0x0c06159au; return 0; }
r[13]=r[4];
goto P_0c06159c;
P_0c06159c: /* original 4f22, guest PC 0x0c06159c */
if(!s->budget--) { s->failed_pc=0x0c06159cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06159e;
P_0c06159e: /* original 7ff8, guest PC 0x0c06159e */
if(!s->budget--) { s->failed_pc=0x0c06159eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0615a0;
P_0c0615a0: /* original b6cd, guest PC 0x0c0615a0 */
if(!s->budget--) { s->failed_pc=0x0c0615a0u; return 0; }
target=0x0c06233eu; r[16]=0x0c0615a4u;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0615a4u) { target=s->pc; goto dispatch; }
goto P_0c0615a4;
P_0c0615a2: /* original 65f3, guest PC 0x0c0615a2 */
if(!s->budget--) { s->failed_pc=0x0c0615a2u; return 0; }
r[5]=r[15];
goto P_0c0615a4;
P_0c0615a4: /* original 6e03, guest PC 0x0c0615a4 */
if(!s->budget--) { s->failed_pc=0x0c0615a4u; return 0; }
r[14]=r[0];
goto P_0c0615a6;
P_0c0615a6: /* original 2ee8, guest PC 0x0c0615a6 */
if(!s->budget--) { s->failed_pc=0x0c0615a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0615a8;
P_0c0615a8: /* original 8b01, guest PC 0x0c0615a8 */
if(!s->budget--) { s->failed_pc=0x0c0615a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0615ae; }
goto P_0c0615aa;
P_0c0615aa: /* original a046, guest PC 0x0c0615aa */
if(!s->budget--) { s->failed_pc=0x0c0615aau; return 0; }
r[0]=0x00000007u;
goto P_0c06163a;
P_0c0615ac: /* original e007, guest PC 0x0c0615ac */
if(!s->budget--) { s->failed_pc=0x0c0615acu; return 0; }
r[0]=0x00000007u;
goto P_0c0615ae;
P_0c0615ae: /* original 60e1, guest PC 0x0c0615ae */
if(!s->budget--) { s->failed_pc=0x0c0615aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0615b0;
P_0c0615b0: /* original 600d, guest PC 0x0c0615b0 */
if(!s->budget--) { s->failed_pc=0x0c0615b0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0615b2;
P_0c0615b2: /* original c802, guest PC 0x0c0615b2 */
if(!s->budget--) { s->failed_pc=0x0c0615b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0615b4;
P_0c0615b4: /* original 893b, guest PC 0x0c0615b4 */
if(!s->budget--) { s->failed_pc=0x0c0615b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06162e; }
goto P_0c0615b6;
P_0c0615b6: /* original d20c, guest PC 0x0c0615b6 */
if(!s->budget--) { s->failed_pc=0x0c0615b6u; return 0; }
r[2]=read(ram,0x0c0615e8u,4);
goto P_0c0615b8;
P_0c0615b8: /* original 63f1, guest PC 0x0c0615b8 */
if(!s->budget--) { s->failed_pc=0x0c0615b8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0615ba;
P_0c0615ba: /* original 2338, guest PC 0x0c0615ba */
if(!s->budget--) { s->failed_pc=0x0c0615bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0615bc;
P_0c0615bc: /* original 8f03, guest PC 0x0c0615bc */
if(!s->budget--) { s->failed_pc=0x0c0615bcu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!cond) { goto P_0c0615c6; }
goto P_0c0615c0;
P_0c0615be: /* original 6522, guest PC 0x0c0615be */
if(!s->budget--) { s->failed_pc=0x0c0615beu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0615c0;
P_0c0615c0: /* original 6453, guest PC 0x0c0615c0 */
if(!s->budget--) { s->failed_pc=0x0c0615c0u; return 0; }
r[4]=r[5];
goto P_0c0615c2;
P_0c0615c2: /* original a002, guest PC 0x0c0615c2 */
if(!s->budget--) { s->failed_pc=0x0c0615c2u; return 0; }
r[4]+=r[13];
goto P_0c0615ca;
P_0c0615c4: /* original 34dc, guest PC 0x0c0615c4 */
if(!s->budget--) { s->failed_pc=0x0c0615c4u; return 0; }
r[4]+=r[13];
goto P_0c0615c6;
P_0c0615c6: /* original 64d3, guest PC 0x0c0615c6 */
if(!s->budget--) { s->failed_pc=0x0c0615c6u; return 0; }
r[4]=r[13];
goto P_0c0615c8;
P_0c0615c8: /* original 3458, guest PC 0x0c0615c8 */
if(!s->budget--) { s->failed_pc=0x0c0615c8u; return 0; }
r[4]-=r[5];
goto P_0c0615ca;
P_0c0615ca: /* original 65f3, guest PC 0x0c0615ca */
if(!s->budget--) { s->failed_pc=0x0c0615cau; return 0; }
r[5]=r[15];
goto P_0c0615cc;
P_0c0615cc: /* original b6b7, guest PC 0x0c0615cc */
if(!s->budget--) { s->failed_pc=0x0c0615ccu; return 0; }
target=0x0c06233eu; r[16]=0x0c0615d0u;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0615d0u) { target=s->pc; goto dispatch; }
goto P_0c0615d0;
P_0c0615ce: /* original 7504, guest PC 0x0c0615ce */
if(!s->budget--) { s->failed_pc=0x0c0615ceu; return 0; }
r[5]+=0x00000004u;
goto P_0c0615d0;
P_0c0615d0: /* original 6d03, guest PC 0x0c0615d0 */
if(!s->budget--) { s->failed_pc=0x0c0615d0u; return 0; }
r[13]=r[0];
goto P_0c0615d2;
P_0c0615d2: /* original 2dd8, guest PC 0x0c0615d2 */
if(!s->budget--) { s->failed_pc=0x0c0615d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0615d4;
P_0c0615d4: /* original 8b18, guest PC 0x0c0615d4 */
if(!s->budget--) { s->failed_pc=0x0c0615d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061608; }
goto P_0c0615d6;
P_0c0615d6: /* original 65e3, guest PC 0x0c0615d6 */
if(!s->budget--) { s->failed_pc=0x0c0615d6u; return 0; }
r[5]=r[14];
goto P_0c0615d8;
P_0c0615d8: /* original b6da, guest PC 0x0c0615d8 */
if(!s->budget--) { s->failed_pc=0x0c0615d8u; return 0; }
target=0x0c062390u; r[16]=0x0c0615dcu;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0615dcu) { target=s->pc; goto dispatch; }
goto P_0c0615dc;
P_0c0615da: /* original 64f1, guest PC 0x0c0615da */
if(!s->budget--) { s->failed_pc=0x0c0615dau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c0615dc;
P_0c0615dc: /* original a02d, guest PC 0x0c0615dc */
if(!s->budget--) { s->failed_pc=0x0c0615dcu; return 0; }
r[0]=0x00000000u;
goto P_0c06163a;
P_0c0615de: /* original e000, guest PC 0x0c0615de */
if(!s->budget--) { s->failed_pc=0x0c0615deu; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c0615e0u,s,ram);
P_0c061608: /* original 60d1, guest PC 0x0c061608 */
if(!s->budget--) { s->failed_pc=0x0c061608u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c06160a;
P_0c06160a: /* original 600d, guest PC 0x0c06160a */
if(!s->budget--) { s->failed_pc=0x0c06160au; return 0; }
r[0]=r[0]&65535u;
goto P_0c06160c;
P_0c06160c: /* original c804, guest PC 0x0c06160c */
if(!s->budget--) { s->failed_pc=0x0c06160cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c06160e;
P_0c06160e: /* original 8905, guest PC 0x0c06160e */
if(!s->budget--) { s->failed_pc=0x0c06160eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06161c; }
goto P_0c061610;
P_0c061610: /* original d34d, guest PC 0x0c061610 */
if(!s->budget--) { s->failed_pc=0x0c061610u; return 0; }
r[3]=read(ram,0x0c061748u,4);
goto P_0c061612;
P_0c061612: /* original 62e1, guest PC 0x0c061612 */
if(!s->budget--) { s->failed_pc=0x0c061612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c061614;
P_0c061614: /* original 2239, guest PC 0x0c061614 */
if(!s->budget--) { s->failed_pc=0x0c061614u; return 0; }
r[2]&=r[3];
goto P_0c061616;
P_0c061616: /* original 2e21, guest PC 0x0c061616 */
if(!s->budget--) { s->failed_pc=0x0c061616u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c061618;
P_0c061618: /* original a00d, guest PC 0x0c061618 */
if(!s->budget--) { s->failed_pc=0x0c061618u; return 0; }
r[4]=0x00000000u;
goto P_0c061636;
P_0c06161a: /* original e400, guest PC 0x0c06161a */
if(!s->budget--) { s->failed_pc=0x0c06161au; return 0; }
r[4]=0x00000000u;
goto P_0c06161c;
P_0c06161c: /* original 65e3, guest PC 0x0c06161c */
if(!s->budget--) { s->failed_pc=0x0c06161cu; return 0; }
r[5]=r[14];
goto P_0c06161e;
P_0c06161e: /* original b6b7, guest PC 0x0c06161e */
if(!s->budget--) { s->failed_pc=0x0c06161eu; return 0; }
target=0x0c062390u; r[16]=0x0c061622u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061622u) { target=s->pc; goto dispatch; }
goto P_0c061622;
P_0c061620: /* original 64f1, guest PC 0x0c061620 */
if(!s->budget--) { s->failed_pc=0x0c061620u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c061622;
P_0c061622: /* original 65d3, guest PC 0x0c061622 */
if(!s->budget--) { s->failed_pc=0x0c061622u; return 0; }
r[5]=r[13];
goto P_0c061624;
P_0c061624: /* original 85f2, guest PC 0x0c061624 */
if(!s->budget--) { s->failed_pc=0x0c061624u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c061626;
P_0c061626: /* original b6b3, guest PC 0x0c061626 */
if(!s->budget--) { s->failed_pc=0x0c061626u; return 0; }
target=0x0c062390u; r[16]=0x0c06162au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06162au) { target=s->pc; goto dispatch; }
goto P_0c06162a;
P_0c061628: /* original 6403, guest PC 0x0c061628 */
if(!s->budget--) { s->failed_pc=0x0c061628u; return 0; }
r[4]=r[0];
goto P_0c06162a;
P_0c06162a: /* original a004, guest PC 0x0c06162a */
if(!s->budget--) { s->failed_pc=0x0c06162au; return 0; }
r[4]=r[0];
goto P_0c061636;
P_0c06162c: /* original 6403, guest PC 0x0c06162c */
if(!s->budget--) { s->failed_pc=0x0c06162cu; return 0; }
r[4]=r[0];
goto P_0c06162e;
P_0c06162e: /* original 65e3, guest PC 0x0c06162e */
if(!s->budget--) { s->failed_pc=0x0c06162eu; return 0; }
r[5]=r[14];
goto P_0c061630;
P_0c061630: /* original b6ae, guest PC 0x0c061630 */
if(!s->budget--) { s->failed_pc=0x0c061630u; return 0; }
target=0x0c062390u; r[16]=0x0c061634u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061634u) { target=s->pc; goto dispatch; }
goto P_0c061634;
P_0c061632: /* original 64f1, guest PC 0x0c061632 */
if(!s->budget--) { s->failed_pc=0x0c061632u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c061634;
P_0c061634: /* original 6403, guest PC 0x0c061634 */
if(!s->budget--) { s->failed_pc=0x0c061634u; return 0; }
r[4]=r[0];
goto P_0c061636;
P_0c061636: /* original 6043, guest PC 0x0c061636 */
if(!s->budget--) { s->failed_pc=0x0c061636u; return 0; }
r[0]=r[4];
goto P_0c061638;
P_0c061638: /* original 0009, guest PC 0x0c061638 */
if(!s->budget--) { s->failed_pc=0x0c061638u; return 0; }
goto P_0c06163a;
P_0c06163a: /* original 7f08, guest PC 0x0c06163a */
if(!s->budget--) { s->failed_pc=0x0c06163au; return 0; }
r[15]+=0x00000008u;
goto P_0c06163c;
P_0c06163c: /* original 4f26, guest PC 0x0c06163c */
if(!s->budget--) { s->failed_pc=0x0c06163cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06163e;
P_0c06163e: /* original 6df6, guest PC 0x0c06163e */
if(!s->budget--) { s->failed_pc=0x0c06163eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061640;
P_0c061640: /* original 000b, guest PC 0x0c061640 */
if(!s->budget--) { s->failed_pc=0x0c061640u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061642: /* original 6ef6, guest PC 0x0c061642 */
if(!s->budget--) { s->failed_pc=0x0c061642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c061644u,s,ram);
P_0c061674: /* original 2fe6, guest PC 0x0c061674 */
if(!s->budget--) { s->failed_pc=0x0c061674u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c061676;
P_0c061676: /* original 6543, guest PC 0x0c061676 */
if(!s->budget--) { s->failed_pc=0x0c061676u; return 0; }
r[5]=r[4];
goto P_0c061678;
P_0c061678: /* original d335, guest PC 0x0c061678 */
if(!s->budget--) { s->failed_pc=0x0c061678u; return 0; }
r[3]=read(ram,0x0c061750u,4);
goto P_0c06167a;
P_0c06167a: /* original 2fd6, guest PC 0x0c06167a */
if(!s->budget--) { s->failed_pc=0x0c06167au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c06167c;
P_0c06167c: /* original 2fc6, guest PC 0x0c06167c */
if(!s->budget--) { s->failed_pc=0x0c06167cu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c06167e;
P_0c06167e: /* original 6d43, guest PC 0x0c06167e */
if(!s->budget--) { s->failed_pc=0x0c06167eu; return 0; }
r[13]=r[4];
goto P_0c061680;
P_0c061680: /* original 2fb6, guest PC 0x0c061680 */
if(!s->budget--) { s->failed_pc=0x0c061680u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c061682;
P_0c061682: /* original 4f22, guest PC 0x0c061682 */
if(!s->budget--) { s->failed_pc=0x0c061682u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c061684;
P_0c061684: /* original 7fec, guest PC 0x0c061684 */
if(!s->budget--) { s->failed_pc=0x0c061684u; return 0; }
r[15]+=0xffffffecu;
goto P_0c061686;
P_0c061686: /* original 430b, guest PC 0x0c061686 */
if(!s->budget--) { s->failed_pc=0x0c061686u; return 0; }
target=r[3];
r[16]=0x0c06168au;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06168au) { target=s->pc; goto dispatch; }
goto P_0c06168a;
P_0c061688: /* original 64f3, guest PC 0x0c061688 */
if(!s->budget--) { s->failed_pc=0x0c061688u; return 0; }
r[4]=r[15];
goto P_0c06168a;
P_0c06168a: /* original ee00, guest PC 0x0c06168a */
if(!s->budget--) { s->failed_pc=0x0c06168au; return 0; }
r[14]=0x00000000u;
goto P_0c06168c;
P_0c06168c: /* original d231, guest PC 0x0c06168c */
if(!s->budget--) { s->failed_pc=0x0c06168cu; return 0; }
r[2]=read(ram,0x0c061754u,4);
goto P_0c06168e;
P_0c06168e: /* original 6422, guest PC 0x0c06168e */
if(!s->budget--) { s->failed_pc=0x0c06168eu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c061690;
P_0c061690: /* original 2448, guest PC 0x0c061690 */
if(!s->budget--) { s->failed_pc=0x0c061690u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061692;
P_0c061692: /* original 8d27, guest PC 0x0c061692 */
if(!s->budget--) { s->failed_pc=0x0c061692u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[15]+16,4);
if(cond) { goto P_0c0616e4; }
goto P_0c061696;
P_0c061694: /* original 56f4, guest PC 0x0c061694 */
if(!s->budget--) { s->failed_pc=0x0c061694u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c061696;
P_0c061696: /* original db30, guest PC 0x0c061696 */
if(!s->budget--) { s->failed_pc=0x0c061696u; return 0; }
r[11]=read(ram,0x0c061758u,4);
goto P_0c061698;
P_0c061698: /* original 6241, guest PC 0x0c061698 */
if(!s->budget--) { s->failed_pc=0x0c061698u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c06169a;
P_0c06169a: /* original 622d, guest PC 0x0c06169a */
if(!s->budget--) { s->failed_pc=0x0c06169au; return 0; }
r[2]=r[2]&65535u;
goto P_0c06169c;
P_0c06169c: /* original 63f2, guest PC 0x0c06169c */
if(!s->budget--) { s->failed_pc=0x0c06169cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06169e;
P_0c06169e: /* original 22b9, guest PC 0x0c06169e */
if(!s->budget--) { s->failed_pc=0x0c06169eu; return 0; }
r[2]&=r[11];
goto P_0c0616a0;
P_0c0616a0: /* original 3230, guest PC 0x0c0616a0 */
if(!s->budget--) { s->failed_pc=0x0c0616a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0616a2;
P_0c0616a2: /* original 8b1a, guest PC 0x0c0616a2 */
if(!s->budget--) { s->failed_pc=0x0c0616a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616da; }
goto P_0c0616a4;
P_0c0616a4: /* original a017, guest PC 0x0c0616a4 */
if(!s->budget--) { s->failed_pc=0x0c0616a4u; return 0; }
r[5]=0x00000000u;
goto P_0c0616d6;
P_0c0616a6: /* original e500, guest PC 0x0c0616a6 */
if(!s->budget--) { s->failed_pc=0x0c0616a6u; return 0; }
r[5]=0x00000000u;
goto P_0c0616a8;
P_0c0616a8: /* original 6253, guest PC 0x0c0616a8 */
if(!s->budget--) { s->failed_pc=0x0c0616a8u; return 0; }
r[2]=r[5];
goto P_0c0616aa;
P_0c0616aa: /* original 4208, guest PC 0x0c0616aa */
if(!s->budget--) { s->failed_pc=0x0c0616aau; return 0; }
r[2]<<=2;
goto P_0c0616ac;
P_0c0616ac: /* original 6343, guest PC 0x0c0616ac */
if(!s->budget--) { s->failed_pc=0x0c0616acu; return 0; }
r[3]=r[4];
goto P_0c0616ae;
P_0c0616ae: /* original 730c, guest PC 0x0c0616ae */
if(!s->budget--) { s->failed_pc=0x0c0616aeu; return 0; }
r[3]+=0x0000000cu;
goto P_0c0616b0;
P_0c0616b0: /* original 323c, guest PC 0x0c0616b0 */
if(!s->budget--) { s->failed_pc=0x0c0616b0u; return 0; }
r[2]+=r[3];
goto P_0c0616b2;
P_0c0616b2: /* original 6122, guest PC 0x0c0616b2 */
if(!s->budget--) { s->failed_pc=0x0c0616b2u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0616b4;
P_0c0616b4: /* original 2118, guest PC 0x0c0616b4 */
if(!s->budget--) { s->failed_pc=0x0c0616b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0616b6;
P_0c0616b6: /* original 890d, guest PC 0x0c0616b6 */
if(!s->budget--) { s->failed_pc=0x0c0616b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0616d4; }
goto P_0c0616b8;
P_0c0616b8: /* original 57f1, guest PC 0x0c0616b8 */
if(!s->budget--) { s->failed_pc=0x0c0616b8u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0616ba;
P_0c0616ba: /* original 4709, guest PC 0x0c0616ba */
if(!s->budget--) { s->failed_pc=0x0c0616bau; return 0; }
r[7]>>=2;
goto P_0c0616bc;
P_0c0616bc: /* original 0577, guest PC 0x0c0616bc */
if(!s->budget--) { s->failed_pc=0x0c0616bcu; return 0; }
r[19]=r[5]*r[7];
goto P_0c0616be;
P_0c0616be: /* original 071a, guest PC 0x0c0616be */
if(!s->budget--) { s->failed_pc=0x0c0616beu; return 0; }
r[7]=r[19];
goto P_0c0616c0;
P_0c0616c0: /* original 5342, guest PC 0x0c0616c0 */
if(!s->budget--) { s->failed_pc=0x0c0616c0u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0616c2;
P_0c0616c2: /* original 4708, guest PC 0x0c0616c2 */
if(!s->budget--) { s->failed_pc=0x0c0616c2u; return 0; }
r[7]<<=2;
goto P_0c0616c4;
P_0c0616c4: /* original 52d7, guest PC 0x0c0616c4 */
if(!s->budget--) { s->failed_pc=0x0c0616c4u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c0616c6;
P_0c0616c6: /* original 373c, guest PC 0x0c0616c6 */
if(!s->budget--) { s->failed_pc=0x0c0616c6u; return 0; }
r[7]+=r[3];
goto P_0c0616c8;
P_0c0616c8: /* original 3720, guest PC 0x0c0616c8 */
if(!s->budget--) { s->failed_pc=0x0c0616c8u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c0616ca;
P_0c0616ca: /* original 8b03, guest PC 0x0c0616ca */
if(!s->budget--) { s->failed_pc=0x0c0616cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616d4; }
goto P_0c0616cc;
P_0c0616cc: /* original 6e43, guest PC 0x0c0616cc */
if(!s->budget--) { s->failed_pc=0x0c0616ccu; return 0; }
r[14]=r[4];
goto P_0c0616ce;
P_0c0616ce: /* original 6c53, guest PC 0x0c0616ce */
if(!s->budget--) { s->failed_pc=0x0c0616ceu; return 0; }
r[12]=r[5];
goto P_0c0616d0;
P_0c0616d0: /* original 6563, guest PC 0x0c0616d0 */
if(!s->budget--) { s->failed_pc=0x0c0616d0u; return 0; }
r[5]=r[6];
goto P_0c0616d2;
P_0c0616d2: /* original e400, guest PC 0x0c0616d2 */
if(!s->budget--) { s->failed_pc=0x0c0616d2u; return 0; }
r[4]=0x00000000u;
goto P_0c0616d4;
P_0c0616d4: /* original 7501, guest PC 0x0c0616d4 */
if(!s->budget--) { s->failed_pc=0x0c0616d4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0616d6;
P_0c0616d6: /* original 3562, guest PC 0x0c0616d6 */
if(!s->budget--) { s->failed_pc=0x0c0616d6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c0616d8;
P_0c0616d8: /* original 8be6, guest PC 0x0c0616d8 */
if(!s->budget--) { s->failed_pc=0x0c0616d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616a8; }
goto P_0c0616da;
P_0c0616da: /* original 2ee8, guest PC 0x0c0616da */
if(!s->budget--) { s->failed_pc=0x0c0616dau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0616dc;
P_0c0616dc: /* original 8b00, guest PC 0x0c0616dc */
if(!s->budget--) { s->failed_pc=0x0c0616dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616e0; }
goto P_0c0616de;
P_0c0616de: /* original 5441, guest PC 0x0c0616de */
if(!s->budget--) { s->failed_pc=0x0c0616deu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0616e0;
P_0c0616e0: /* original 2448, guest PC 0x0c0616e0 */
if(!s->budget--) { s->failed_pc=0x0c0616e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0616e2;
P_0c0616e2: /* original 8bd9, guest PC 0x0c0616e2 */
if(!s->budget--) { s->failed_pc=0x0c0616e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061698; }
goto P_0c0616e4;
P_0c0616e4: /* original 2ee8, guest PC 0x0c0616e4 */
if(!s->budget--) { s->failed_pc=0x0c0616e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0616e6;
P_0c0616e6: /* original 8927, guest PC 0x0c0616e6 */
if(!s->budget--) { s->failed_pc=0x0c0616e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061738; }
goto P_0c0616e8;
P_0c0616e8: /* original 4c08, guest PC 0x0c0616e8 */
if(!s->budget--) { s->failed_pc=0x0c0616e8u; return 0; }
r[12]<<=2;
goto P_0c0616ea;
P_0c0616ea: /* original 62e3, guest PC 0x0c0616ea */
if(!s->budget--) { s->failed_pc=0x0c0616eau; return 0; }
r[2]=r[14];
goto P_0c0616ec;
P_0c0616ec: /* original 720c, guest PC 0x0c0616ec */
if(!s->budget--) { s->failed_pc=0x0c0616ecu; return 0; }
r[2]+=0x0000000cu;
goto P_0c0616ee;
P_0c0616ee: /* original 3c2c, guest PC 0x0c0616ee */
if(!s->budget--) { s->failed_pc=0x0c0616eeu; return 0; }
r[12]+=r[2];
goto P_0c0616f0;
P_0c0616f0: /* original e300, guest PC 0x0c0616f0 */
if(!s->budget--) { s->failed_pc=0x0c0616f0u; return 0; }
r[3]=0x00000000u;
goto P_0c0616f2;
P_0c0616f2: /* original 6533, guest PC 0x0c0616f2 */
if(!s->budget--) { s->failed_pc=0x0c0616f2u; return 0; }
r[5]=r[3];
goto P_0c0616f4;
P_0c0616f4: /* original 2c32, guest PC 0x0c0616f4 */
if(!s->budget--) { s->failed_pc=0x0c0616f4u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c0616f6;
P_0c0616f6: /* original a00a, guest PC 0x0c0616f6 */
if(!s->budget--) { s->failed_pc=0x0c0616f6u; return 0; }
r[4]=r[3];
goto P_0c06170e;
P_0c0616f8: /* original 6433, guest PC 0x0c0616f8 */
if(!s->budget--) { s->failed_pc=0x0c0616f8u; return 0; }
r[4]=r[3];
goto P_0c0616fa;
P_0c0616fa: /* original 6343, guest PC 0x0c0616fa */
if(!s->budget--) { s->failed_pc=0x0c0616fau; return 0; }
r[3]=r[4];
goto P_0c0616fc;
P_0c0616fc: /* original 4308, guest PC 0x0c0616fc */
if(!s->budget--) { s->failed_pc=0x0c0616fcu; return 0; }
r[3]<<=2;
goto P_0c0616fe;
P_0c0616fe: /* original 62e3, guest PC 0x0c0616fe */
if(!s->budget--) { s->failed_pc=0x0c0616feu; return 0; }
r[2]=r[14];
goto P_0c061700;
P_0c061700: /* original 720c, guest PC 0x0c061700 */
if(!s->budget--) { s->failed_pc=0x0c061700u; return 0; }
r[2]+=0x0000000cu;
goto P_0c061702;
P_0c061702: /* original 332c, guest PC 0x0c061702 */
if(!s->budget--) { s->failed_pc=0x0c061702u; return 0; }
r[3]+=r[2];
goto P_0c061704;
P_0c061704: /* original 6132, guest PC 0x0c061704 */
if(!s->budget--) { s->failed_pc=0x0c061704u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c061706;
P_0c061706: /* original 2118, guest PC 0x0c061706 */
if(!s->budget--) { s->failed_pc=0x0c061706u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c061708;
P_0c061708: /* original 8d01, guest PC 0x0c061708 */
if(!s->budget--) { s->failed_pc=0x0c061708u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c06170e; }
goto P_0c06170c;
P_0c06170a: /* original 7401, guest PC 0x0c06170a */
if(!s->budget--) { s->failed_pc=0x0c06170au; return 0; }
r[4]+=0x00000001u;
goto P_0c06170c;
P_0c06170c: /* original e501, guest PC 0x0c06170c */
if(!s->budget--) { s->failed_pc=0x0c06170cu; return 0; }
r[5]=0x00000001u;
goto P_0c06170e;
P_0c06170e: /* original 53f4, guest PC 0x0c06170e */
if(!s->budget--) { s->failed_pc=0x0c06170eu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c061710;
P_0c061710: /* original 3432, guest PC 0x0c061710 */
if(!s->budget--) { s->failed_pc=0x0c061710u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c061712;
P_0c061712: /* original 8bf2, guest PC 0x0c061712 */
if(!s->budget--) { s->failed_pc=0x0c061712u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616fa; }
goto P_0c061714;
P_0c061714: /* original 2558, guest PC 0x0c061714 */
if(!s->budget--) { s->failed_pc=0x0c061714u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c061716;
P_0c061716: /* original 8b0d, guest PC 0x0c061716 */
if(!s->budget--) { s->failed_pc=0x0c061716u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061734; }
goto P_0c061718;
P_0c061718: /* original bf3d, guest PC 0x0c061718 */
if(!s->budget--) { s->failed_pc=0x0c061718u; return 0; }
target=0x0c061596u; r[16]=0x0c06171cu;
r[4]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06171cu) { target=s->pc; goto dispatch; }
goto P_0c06171c;
P_0c06171a: /* original 54e2, guest PC 0x0c06171a */
if(!s->budget--) { s->failed_pc=0x0c06171au; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c06171c;
P_0c06171c: /* original 6403, guest PC 0x0c06171c */
if(!s->budget--) { s->failed_pc=0x0c06171cu; return 0; }
r[4]=r[0];
goto P_0c06171e;
P_0c06171e: /* original 2448, guest PC 0x0c06171e */
if(!s->budget--) { s->failed_pc=0x0c06171eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061720;
P_0c061720: /* original 8901, guest PC 0x0c061720 */
if(!s->budget--) { s->failed_pc=0x0c061720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061726; }
goto P_0c061722;
P_0c061722: /* original a00a, guest PC 0x0c061722 */
if(!s->budget--) { s->failed_pc=0x0c061722u; return 0; }
r[0]=r[4];
goto P_0c06173a;
P_0c061724: /* original 6043, guest PC 0x0c061724 */
if(!s->budget--) { s->failed_pc=0x0c061724u; return 0; }
r[0]=r[4];
goto P_0c061726;
P_0c061726: /* original d40b, guest PC 0x0c061726 */
if(!s->budget--) { s->failed_pc=0x0c061726u; return 0; }
r[4]=read(ram,0x0c061754u,4);
goto P_0c061728;
P_0c061728: /* original d30c, guest PC 0x0c061728 */
if(!s->budget--) { s->failed_pc=0x0c061728u; return 0; }
r[3]=read(ram,0x0c06175cu,4);
goto P_0c06172a;
P_0c06172a: /* original 430b, guest PC 0x0c06172a */
if(!s->budget--) { s->failed_pc=0x0c06172au; return 0; }
target=r[3];
r[16]=0x0c06172eu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06172eu) { target=s->pc; goto dispatch; }
goto P_0c06172e;
P_0c06172c: /* original 65e3, guest PC 0x0c06172c */
if(!s->budget--) { s->failed_pc=0x0c06172cu; return 0; }
r[5]=r[14];
goto P_0c06172e;
P_0c06172e: /* original d20c, guest PC 0x0c06172e */
if(!s->budget--) { s->failed_pc=0x0c06172eu; return 0; }
r[2]=read(ram,0x0c061760u,4);
goto P_0c061730;
P_0c061730: /* original 420b, guest PC 0x0c061730 */
if(!s->budget--) { s->failed_pc=0x0c061730u; return 0; }
target=r[2];
r[16]=0x0c061734u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061734u) { target=s->pc; goto dispatch; }
goto P_0c061734;
P_0c061732: /* original 64e3, guest PC 0x0c061732 */
if(!s->budget--) { s->failed_pc=0x0c061732u; return 0; }
r[4]=r[14];
goto P_0c061734;
P_0c061734: /* original a001, guest PC 0x0c061734 */
if(!s->budget--) { s->failed_pc=0x0c061734u; return 0; }
r[0]=0x00000000u;
goto P_0c06173a;
P_0c061736: /* original e000, guest PC 0x0c061736 */
if(!s->budget--) { s->failed_pc=0x0c061736u; return 0; }
r[0]=0x00000000u;
goto P_0c061738;
P_0c061738: /* original e007, guest PC 0x0c061738 */
if(!s->budget--) { s->failed_pc=0x0c061738u; return 0; }
r[0]=0x00000007u;
goto P_0c06173a;
P_0c06173a: /* original 7f14, guest PC 0x0c06173a */
if(!s->budget--) { s->failed_pc=0x0c06173au; return 0; }
r[15]+=0x00000014u;
goto P_0c06173c;
P_0c06173c: /* original 4f26, guest PC 0x0c06173c */
if(!s->budget--) { s->failed_pc=0x0c06173cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06173e;
P_0c06173e: /* original 6bf6, guest PC 0x0c06173e */
if(!s->budget--) { s->failed_pc=0x0c06173eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c061740;
P_0c061740: /* original 6cf6, guest PC 0x0c061740 */
if(!s->budget--) { s->failed_pc=0x0c061740u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061742;
P_0c061742: /* original 6df6, guest PC 0x0c061742 */
if(!s->budget--) { s->failed_pc=0x0c061742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061744;
P_0c061744: /* original 000b, guest PC 0x0c061744 */
if(!s->budget--) { s->failed_pc=0x0c061744u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061746: /* original 6ef6, guest PC 0x0c061746 */
if(!s->budget--) { s->failed_pc=0x0c061746u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c061748u,s,ram);
P_0c06233e: /* original d213, guest PC 0x0c06233e */
if(!s->budget--) { s->failed_pc=0x0c06233eu; return 0; }
r[2]=read(ram,0x0c06238cu,4);
goto P_0c062340;
P_0c062340: /* original 6322, guest PC 0x0c062340 */
if(!s->budget--) { s->failed_pc=0x0c062340u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c062342;
P_0c062342: /* original 3433, guest PC 0x0c062342 */
if(!s->budget--) { s->failed_pc=0x0c062342u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c062344;
P_0c062344: /* original 8d03, guest PC 0x0c062344 */
if(!s->budget--) { s->failed_pc=0x0c062344u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c06234e; }
goto P_0c062348;
P_0c062346: /* original e600, guest PC 0x0c062346 */
if(!s->budget--) { s->failed_pc=0x0c062346u; return 0; }
r[6]=0x00000000u;
goto P_0c062348;
P_0c062348: /* original e000, guest PC 0x0c062348 */
if(!s->budget--) { s->failed_pc=0x0c062348u; return 0; }
r[0]=0x00000000u;
goto P_0c06234a;
P_0c06234a: /* original a002, guest PC 0x0c06234a */
if(!s->budget--) { s->failed_pc=0x0c06234au; return 0; }
write(ram,r[5],r[0],2);
goto P_0c062352;
P_0c06234c: /* original 2501, guest PC 0x0c06234c */
if(!s->budget--) { s->failed_pc=0x0c06234cu; return 0; }
write(ram,r[5],r[0],2);
goto P_0c06234e;
P_0c06234e: /* original e101, guest PC 0x0c06234e */
if(!s->budget--) { s->failed_pc=0x0c06234eu; return 0; }
r[1]=0x00000001u;
goto P_0c062350;
P_0c062350: /* original 2511, guest PC 0x0c062350 */
if(!s->budget--) { s->failed_pc=0x0c062350u; return 0; }
write(ram,r[5],r[1],2);
goto P_0c062352;
P_0c062352: /* original 6350, guest PC 0x0c062352 */
if(!s->budget--) { s->failed_pc=0x0c062352u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c062354;
P_0c062354: /* original d00b, guest PC 0x0c062354 */
if(!s->budget--) { s->failed_pc=0x0c062354u; return 0; }
r[0]=read(ram,0x0c062384u,4);
goto P_0c062356;
P_0c062356: /* original 6233, guest PC 0x0c062356 */
if(!s->budget--) { s->failed_pc=0x0c062356u; return 0; }
r[2]=r[3];
goto P_0c062358;
P_0c062358: /* original 4308, guest PC 0x0c062358 */
if(!s->budget--) { s->failed_pc=0x0c062358u; return 0; }
r[3]<<=2;
goto P_0c06235a;
P_0c06235a: /* original 332c, guest PC 0x0c06235a */
if(!s->budget--) { s->failed_pc=0x0c06235au; return 0; }
r[3]+=r[2];
goto P_0c06235c;
P_0c06235c: /* original 4308, guest PC 0x0c06235c */
if(!s->budget--) { s->failed_pc=0x0c06235cu; return 0; }
r[3]<<=2;
goto P_0c06235e;
P_0c06235e: /* original 633e, guest PC 0x0c06235e */
if(!s->budget--) { s->failed_pc=0x0c06235eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c062360;
P_0c062360: /* original 053e, guest PC 0x0c062360 */
if(!s->budget--) { s->failed_pc=0x0c062360u; return 0; }
r[5]=read(ram,r[3]+r[0],4);
goto P_0c062362;
P_0c062362: /* original 2558, guest PC 0x0c062362 */
if(!s->budget--) { s->failed_pc=0x0c062362u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c062364;
P_0c062364: /* original 8908, guest PC 0x0c062364 */
if(!s->budget--) { s->failed_pc=0x0c062364u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062378; }
goto P_0c062366;
P_0c062366: /* original 5153, guest PC 0x0c062366 */
if(!s->budget--) { s->failed_pc=0x0c062366u; return 0; }
r[1]=read(ram,r[5]+12,4);
goto P_0c062368;
P_0c062368: /* original 3140, guest PC 0x0c062368 */
if(!s->budget--) { s->failed_pc=0x0c062368u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c06236a;
P_0c06236a: /* original 8b02, guest PC 0x0c06236a */
if(!s->budget--) { s->failed_pc=0x0c06236au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062372; }
goto P_0c06236c;
P_0c06236c: /* original 6653, guest PC 0x0c06236c */
if(!s->budget--) { s->failed_pc=0x0c06236cu; return 0; }
r[6]=r[5];
goto P_0c06236e;
P_0c06236e: /* original a001, guest PC 0x0c06236e */
if(!s->budget--) { s->failed_pc=0x0c06236eu; return 0; }
r[5]=0x00000000u;
goto P_0c062374;
P_0c062370: /* original e500, guest PC 0x0c062370 */
if(!s->budget--) { s->failed_pc=0x0c062370u; return 0; }
r[5]=0x00000000u;
goto P_0c062372;
P_0c062372: /* original 5552, guest PC 0x0c062372 */
if(!s->budget--) { s->failed_pc=0x0c062372u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c062374;
P_0c062374: /* original 2558, guest PC 0x0c062374 */
if(!s->budget--) { s->failed_pc=0x0c062374u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c062376;
P_0c062376: /* original 8bf6, guest PC 0x0c062376 */
if(!s->budget--) { s->failed_pc=0x0c062376u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062366; }
goto P_0c062378;
P_0c062378: /* original 000b, guest PC 0x0c062378 */
if(!s->budget--) { s->failed_pc=0x0c062378u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c06237a: /* original 6063, guest PC 0x0c06237a */
if(!s->budget--) { s->failed_pc=0x0c06237au; return 0; }
r[0]=r[6];
return vf3_matrix_family(0x0c06237cu,s,ram);
P_0c062390: /* original 2fe6, guest PC 0x0c062390 */
if(!s->budget--) { s->failed_pc=0x0c062390u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c062392;
P_0c062392: /* original 6e53, guest PC 0x0c062392 */
if(!s->budget--) { s->failed_pc=0x0c062392u; return 0; }
r[14]=r[5];
goto P_0c062394;
P_0c062394: /* original d33d, guest PC 0x0c062394 */
if(!s->budget--) { s->failed_pc=0x0c062394u; return 0; }
r[3]=read(ram,0x0c06248cu,4);
goto P_0c062396;
P_0c062396: /* original 66e3, guest PC 0x0c062396 */
if(!s->budget--) { s->failed_pc=0x0c062396u; return 0; }
r[6]=r[14];
goto P_0c062398;
P_0c062398: /* original 2fd6, guest PC 0x0c062398 */
if(!s->budget--) { s->failed_pc=0x0c062398u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c06239a;
P_0c06239a: /* original 2fc6, guest PC 0x0c06239a */
if(!s->budget--) { s->failed_pc=0x0c06239au; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c06239c;
P_0c06239c: /* original 2fb6, guest PC 0x0c06239c */
if(!s->budget--) { s->failed_pc=0x0c06239cu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c06239e;
P_0c06239e: /* original 6c43, guest PC 0x0c06239e */
if(!s->budget--) { s->failed_pc=0x0c06239eu; return 0; }
r[12]=r[4];
goto P_0c0623a0;
P_0c0623a0: /* original 2fa6, guest PC 0x0c0623a0 */
if(!s->budget--) { s->failed_pc=0x0c0623a0u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0623a2;
P_0c0623a2: /* original 6ac3, guest PC 0x0c0623a2 */
if(!s->budget--) { s->failed_pc=0x0c0623a2u; return 0; }
r[10]=r[12];
goto P_0c0623a4;
P_0c0623a4: /* original 4f22, guest PC 0x0c0623a4 */
if(!s->budget--) { s->failed_pc=0x0c0623a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0623a6;
P_0c0623a6: /* original 4a08, guest PC 0x0c0623a6 */
if(!s->budget--) { s->failed_pc=0x0c0623a6u; return 0; }
r[10]<<=2;
goto P_0c0623a8;
P_0c0623a8: /* original db37, guest PC 0x0c0623a8 */
if(!s->budget--) { s->failed_pc=0x0c0623a8u; return 0; }
r[11]=read(ram,0x0c062488u,4);
goto P_0c0623aa;
P_0c0623aa: /* original 7ffc, guest PC 0x0c0623aa */
if(!s->budget--) { s->failed_pc=0x0c0623aau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0623ac;
P_0c0623ac: /* original 62e1, guest PC 0x0c0623ac */
if(!s->budget--) { s->failed_pc=0x0c0623acu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0623ae;
P_0c0623ae: /* original 2239, guest PC 0x0c0623ae */
if(!s->budget--) { s->failed_pc=0x0c0623aeu; return 0; }
r[2]&=r[3];
goto P_0c0623b0;
P_0c0623b0: /* original 2e21, guest PC 0x0c0623b0 */
if(!s->budget--) { s->failed_pc=0x0c0623b0u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c0623b2;
P_0c0623b2: /* original 62c3, guest PC 0x0c0623b2 */
if(!s->budget--) { s->failed_pc=0x0c0623b2u; return 0; }
r[2]=r[12];
goto P_0c0623b4;
P_0c0623b4: /* original 3a2c, guest PC 0x0c0623b4 */
if(!s->budget--) { s->failed_pc=0x0c0623b4u; return 0; }
r[10]+=r[2];
goto P_0c0623b6;
P_0c0623b6: /* original 4a08, guest PC 0x0c0623b6 */
if(!s->budget--) { s->failed_pc=0x0c0623b6u; return 0; }
r[10]<<=2;
goto P_0c0623b8;
P_0c0623b8: /* original 6aae, guest PC 0x0c0623b8 */
if(!s->budget--) { s->failed_pc=0x0c0623b8u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c0623ba;
P_0c0623ba: /* original 3abc, guest PC 0x0c0623ba */
if(!s->budget--) { s->failed_pc=0x0c0623bau; return 0; }
r[10]+=r[11];
goto P_0c0623bc;
P_0c0623bc: /* original 65a3, guest PC 0x0c0623bc */
if(!s->budget--) { s->failed_pc=0x0c0623bcu; return 0; }
r[5]=r[10];
goto P_0c0623be;
P_0c0623be: /* original 7504, guest PC 0x0c0623be */
if(!s->budget--) { s->failed_pc=0x0c0623beu; return 0; }
r[5]+=0x00000004u;
goto P_0c0623c0;
P_0c0623c0: /* original b0b0, guest PC 0x0c0623c0 */
if(!s->budget--) { s->failed_pc=0x0c0623c0u; return 0; }
target=0x0c062524u; r[16]=0x0c0623c4u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0623c4u) { target=s->pc; goto dispatch; }
goto P_0c0623c4;
P_0c0623c2: /* original 64a3, guest PC 0x0c0623c2 */
if(!s->budget--) { s->failed_pc=0x0c0623c2u; return 0; }
r[4]=r[10];
goto P_0c0623c4;
P_0c0623c4: /* original 53e4, guest PC 0x0c0623c4 */
if(!s->budget--) { s->failed_pc=0x0c0623c4u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0623c6;
P_0c0623c6: /* original 52a4, guest PC 0x0c0623c6 */
if(!s->budget--) { s->failed_pc=0x0c0623c6u; return 0; }
r[2]=read(ram,r[10]+16,4);
goto P_0c0623c8;
P_0c0623c8: /* original 323c, guest PC 0x0c0623c8 */
if(!s->budget--) { s->failed_pc=0x0c0623c8u; return 0; }
r[2]+=r[3];
goto P_0c0623ca;
P_0c0623ca: /* original 1a24, guest PC 0x0c0623ca */
if(!s->budget--) { s->failed_pc=0x0c0623cau; return 0; }
write(ram,r[10]+16,r[2],4);
goto P_0c0623cc;
P_0c0623cc: /* original 54a2, guest PC 0x0c0623cc */
if(!s->budget--) { s->failed_pc=0x0c0623ccu; return 0; }
r[4]=read(ram,r[10]+8,4);
goto P_0c0623ce;
P_0c0623ce: /* original 2448, guest PC 0x0c0623ce */
if(!s->budget--) { s->failed_pc=0x0c0623ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0623d0;
P_0c0623d0: /* original 8d10, guest PC 0x0c0623d0 */
if(!s->budget--) { s->failed_pc=0x0c0623d0u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c0623f4; }
goto P_0c0623d4;
P_0c0623d2: /* original ed00, guest PC 0x0c0623d2 */
if(!s->budget--) { s->failed_pc=0x0c0623d2u; return 0; }
r[13]=0x00000000u;
goto P_0c0623d4;
P_0c0623d4: /* original 5543, guest PC 0x0c0623d4 */
if(!s->budget--) { s->failed_pc=0x0c0623d4u; return 0; }
r[5]=read(ram,r[4]+12,4);
goto P_0c0623d6;
P_0c0623d6: /* original 56e3, guest PC 0x0c0623d6 */
if(!s->budget--) { s->failed_pc=0x0c0623d6u; return 0; }
r[6]=read(ram,r[14]+12,4);
goto P_0c0623d8;
P_0c0623d8: /* original 52e4, guest PC 0x0c0623d8 */
if(!s->budget--) { s->failed_pc=0x0c0623d8u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0623da;
P_0c0623da: /* original 326c, guest PC 0x0c0623da */
if(!s->budget--) { s->failed_pc=0x0c0623dau; return 0; }
r[2]+=r[6];
goto P_0c0623dc;
P_0c0623dc: /* original 3520, guest PC 0x0c0623dc */
if(!s->budget--) { s->failed_pc=0x0c0623dcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[2])!=0);
goto P_0c0623de;
P_0c0623de: /* original 8903, guest PC 0x0c0623de */
if(!s->budget--) { s->failed_pc=0x0c0623deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0623e8; }
goto P_0c0623e0;
P_0c0623e0: /* original 5244, guest PC 0x0c0623e0 */
if(!s->budget--) { s->failed_pc=0x0c0623e0u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0623e2;
P_0c0623e2: /* original 325c, guest PC 0x0c0623e2 */
if(!s->budget--) { s->failed_pc=0x0c0623e2u; return 0; }
r[2]+=r[5];
goto P_0c0623e4;
P_0c0623e4: /* original 3620, guest PC 0x0c0623e4 */
if(!s->budget--) { s->failed_pc=0x0c0623e4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[2])!=0);
goto P_0c0623e6;
P_0c0623e6: /* original 8b02, guest PC 0x0c0623e6 */
if(!s->budget--) { s->failed_pc=0x0c0623e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0623ee; }
goto P_0c0623e8;
P_0c0623e8: /* original 6d43, guest PC 0x0c0623e8 */
if(!s->budget--) { s->failed_pc=0x0c0623e8u; return 0; }
r[13]=r[4];
goto P_0c0623ea;
P_0c0623ea: /* original a001, guest PC 0x0c0623ea */
if(!s->budget--) { s->failed_pc=0x0c0623eau; return 0; }
r[4]=0x00000000u;
goto P_0c0623f0;
P_0c0623ec: /* original e400, guest PC 0x0c0623ec */
if(!s->budget--) { s->failed_pc=0x0c0623ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0623ee;
P_0c0623ee: /* original 5442, guest PC 0x0c0623ee */
if(!s->budget--) { s->failed_pc=0x0c0623eeu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c0623f0;
P_0c0623f0: /* original 2448, guest PC 0x0c0623f0 */
if(!s->budget--) { s->failed_pc=0x0c0623f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0623f2;
P_0c0623f2: /* original 8bef, guest PC 0x0c0623f2 */
if(!s->budget--) { s->failed_pc=0x0c0623f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0623d4; }
goto P_0c0623f4;
P_0c0623f4: /* original 2dd8, guest PC 0x0c0623f4 */
if(!s->budget--) { s->failed_pc=0x0c0623f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0623f6;
P_0c0623f6: /* original 8931, guest PC 0x0c0623f6 */
if(!s->budget--) { s->failed_pc=0x0c0623f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06245c; }
goto P_0c0623f8;
P_0c0623f8: /* original 6ac3, guest PC 0x0c0623f8 */
if(!s->budget--) { s->failed_pc=0x0c0623f8u; return 0; }
r[10]=r[12];
goto P_0c0623fa;
P_0c0623fa: /* original 63c3, guest PC 0x0c0623fa */
if(!s->budget--) { s->failed_pc=0x0c0623fau; return 0; }
r[3]=r[12];
goto P_0c0623fc;
P_0c0623fc: /* original 4a08, guest PC 0x0c0623fc */
if(!s->budget--) { s->failed_pc=0x0c0623fcu; return 0; }
r[10]<<=2;
goto P_0c0623fe;
P_0c0623fe: /* original 3a3c, guest PC 0x0c0623fe */
if(!s->budget--) { s->failed_pc=0x0c0623feu; return 0; }
r[10]+=r[3];
goto P_0c062400;
P_0c062400: /* original 4a08, guest PC 0x0c062400 */
if(!s->budget--) { s->failed_pc=0x0c062400u; return 0; }
r[10]<<=2;
goto P_0c062402;
P_0c062402: /* original 6aae, guest PC 0x0c062402 */
if(!s->budget--) { s->failed_pc=0x0c062402u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c062404;
P_0c062404: /* original 3abc, guest PC 0x0c062404 */
if(!s->budget--) { s->failed_pc=0x0c062404u; return 0; }
r[10]+=r[11];
goto P_0c062406;
P_0c062406: /* original 53e4, guest PC 0x0c062406 */
if(!s->budget--) { s->failed_pc=0x0c062406u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062408;
P_0c062408: /* original 52e3, guest PC 0x0c062408 */
if(!s->budget--) { s->failed_pc=0x0c062408u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06240a;
P_0c06240a: /* original 323c, guest PC 0x0c06240a */
if(!s->budget--) { s->failed_pc=0x0c06240au; return 0; }
r[2]+=r[3];
goto P_0c06240c;
P_0c06240c: /* original 51d3, guest PC 0x0c06240c */
if(!s->budget--) { s->failed_pc=0x0c06240cu; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c06240e;
P_0c06240e: /* original 3120, guest PC 0x0c06240e */
if(!s->budget--) { s->failed_pc=0x0c06240eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c062410;
P_0c062410: /* original 8b01, guest PC 0x0c062410 */
if(!s->budget--) { s->failed_pc=0x0c062410u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062416; }
goto P_0c062412;
P_0c062412: /* original 52e3, guest PC 0x0c062412 */
if(!s->budget--) { s->failed_pc=0x0c062412u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062414;
P_0c062414: /* original 1d23, guest PC 0x0c062414 */
if(!s->budget--) { s->failed_pc=0x0c062414u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c062416;
P_0c062416: /* original 53e4, guest PC 0x0c062416 */
if(!s->budget--) { s->failed_pc=0x0c062416u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062418;
P_0c062418: /* original 51d4, guest PC 0x0c062418 */
if(!s->budget--) { s->failed_pc=0x0c062418u; return 0; }
r[1]=read(ram,r[13]+16,4);
goto P_0c06241a;
P_0c06241a: /* original 313c, guest PC 0x0c06241a */
if(!s->budget--) { s->failed_pc=0x0c06241au; return 0; }
r[1]+=r[3];
goto P_0c06241c;
P_0c06241c: /* original 1d14, guest PC 0x0c06241c */
if(!s->budget--) { s->failed_pc=0x0c06241cu; return 0; }
write(ram,r[13]+16,r[1],4);
goto P_0c06241e;
P_0c06241e: /* original b04c, guest PC 0x0c06241e */
if(!s->budget--) { s->failed_pc=0x0c06241eu; return 0; }
target=0x0c0624bau; r[16]=0x0c062422u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062422u) { target=s->pc; goto dispatch; }
goto P_0c062422;
P_0c062420: /* original 64e3, guest PC 0x0c062420 */
if(!s->budget--) { s->failed_pc=0x0c062420u; return 0; }
r[4]=r[14];
goto P_0c062422;
P_0c062422: /* original 66d3, guest PC 0x0c062422 */
if(!s->budget--) { s->failed_pc=0x0c062422u; return 0; }
r[6]=r[13];
goto P_0c062424;
P_0c062424: /* original 65a3, guest PC 0x0c062424 */
if(!s->budget--) { s->failed_pc=0x0c062424u; return 0; }
r[5]=r[10];
goto P_0c062426;
P_0c062426: /* original 750c, guest PC 0x0c062426 */
if(!s->budget--) { s->failed_pc=0x0c062426u; return 0; }
r[5]+=0x0000000cu;
goto P_0c062428;
P_0c062428: /* original 64a3, guest PC 0x0c062428 */
if(!s->budget--) { s->failed_pc=0x0c062428u; return 0; }
r[4]=r[10];
goto P_0c06242a;
P_0c06242a: /* original b07b, guest PC 0x0c06242a */
if(!s->budget--) { s->failed_pc=0x0c06242au; return 0; }
target=0x0c062524u; r[16]=0x0c06242eu;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06242eu) { target=s->pc; goto dispatch; }
goto P_0c06242e;
P_0c06242c: /* original 7408, guest PC 0x0c06242c */
if(!s->budget--) { s->failed_pc=0x0c06242cu; return 0; }
r[4]+=0x00000008u;
goto P_0c06242e;
P_0c06242e: /* original 6ed3, guest PC 0x0c06242e */
if(!s->budget--) { s->failed_pc=0x0c06242eu; return 0; }
r[14]=r[13];
goto P_0c062430;
P_0c062430: /* original 54a2, guest PC 0x0c062430 */
if(!s->budget--) { s->failed_pc=0x0c062430u; return 0; }
r[4]=read(ram,r[10]+8,4);
goto P_0c062432;
P_0c062432: /* original 2448, guest PC 0x0c062432 */
if(!s->budget--) { s->failed_pc=0x0c062432u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062434;
P_0c062434: /* original 8d10, guest PC 0x0c062434 */
if(!s->budget--) { s->failed_pc=0x0c062434u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c062458; }
goto P_0c062438;
P_0c062436: /* original ed00, guest PC 0x0c062436 */
if(!s->budget--) { s->failed_pc=0x0c062436u; return 0; }
r[13]=0x00000000u;
goto P_0c062438;
P_0c062438: /* original 5643, guest PC 0x0c062438 */
if(!s->budget--) { s->failed_pc=0x0c062438u; return 0; }
r[6]=read(ram,r[4]+12,4);
goto P_0c06243a;
P_0c06243a: /* original 55e3, guest PC 0x0c06243a */
if(!s->budget--) { s->failed_pc=0x0c06243au; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c06243c;
P_0c06243c: /* original 52e4, guest PC 0x0c06243c */
if(!s->budget--) { s->failed_pc=0x0c06243cu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c06243e;
P_0c06243e: /* original 325c, guest PC 0x0c06243e */
if(!s->budget--) { s->failed_pc=0x0c06243eu; return 0; }
r[2]+=r[5];
goto P_0c062440;
P_0c062440: /* original 3620, guest PC 0x0c062440 */
if(!s->budget--) { s->failed_pc=0x0c062440u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[2])!=0);
goto P_0c062442;
P_0c062442: /* original 8903, guest PC 0x0c062442 */
if(!s->budget--) { s->failed_pc=0x0c062442u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06244c; }
goto P_0c062444;
P_0c062444: /* original 5244, guest PC 0x0c062444 */
if(!s->budget--) { s->failed_pc=0x0c062444u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c062446;
P_0c062446: /* original 326c, guest PC 0x0c062446 */
if(!s->budget--) { s->failed_pc=0x0c062446u; return 0; }
r[2]+=r[6];
goto P_0c062448;
P_0c062448: /* original 3520, guest PC 0x0c062448 */
if(!s->budget--) { s->failed_pc=0x0c062448u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[2])!=0);
goto P_0c06244a;
P_0c06244a: /* original 8b02, guest PC 0x0c06244a */
if(!s->budget--) { s->failed_pc=0x0c06244au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062452; }
goto P_0c06244c;
P_0c06244c: /* original 6d43, guest PC 0x0c06244c */
if(!s->budget--) { s->failed_pc=0x0c06244cu; return 0; }
r[13]=r[4];
goto P_0c06244e;
P_0c06244e: /* original a001, guest PC 0x0c06244e */
if(!s->budget--) { s->failed_pc=0x0c06244eu; return 0; }
r[4]=0x00000000u;
goto P_0c062454;
P_0c062450: /* original e400, guest PC 0x0c062450 */
if(!s->budget--) { s->failed_pc=0x0c062450u; return 0; }
r[4]=0x00000000u;
goto P_0c062452;
P_0c062452: /* original 5442, guest PC 0x0c062452 */
if(!s->budget--) { s->failed_pc=0x0c062452u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c062454;
P_0c062454: /* original 2448, guest PC 0x0c062454 */
if(!s->budget--) { s->failed_pc=0x0c062454u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062456;
P_0c062456: /* original 8bef, guest PC 0x0c062456 */
if(!s->budget--) { s->failed_pc=0x0c062456u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062438; }
goto P_0c062458;
P_0c062458: /* original 2dd8, guest PC 0x0c062458 */
if(!s->budget--) { s->failed_pc=0x0c062458u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c06245a;
P_0c06245a: /* original 8bd4, guest PC 0x0c06245a */
if(!s->budget--) { s->failed_pc=0x0c06245au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062406; }
goto P_0c06245c;
P_0c06245c: /* original 66e3, guest PC 0x0c06245c */
if(!s->budget--) { s->failed_pc=0x0c06245cu; return 0; }
r[6]=r[14];
goto P_0c06245e;
P_0c06245e: /* original 65c3, guest PC 0x0c06245e */
if(!s->budget--) { s->failed_pc=0x0c06245eu; return 0; }
r[5]=r[12];
goto P_0c062460;
P_0c062460: /* original 63c3, guest PC 0x0c062460 */
if(!s->budget--) { s->failed_pc=0x0c062460u; return 0; }
r[3]=r[12];
goto P_0c062462;
P_0c062462: /* original 4508, guest PC 0x0c062462 */
if(!s->budget--) { s->failed_pc=0x0c062462u; return 0; }
r[5]<<=2;
goto P_0c062464;
P_0c062464: /* original 353c, guest PC 0x0c062464 */
if(!s->budget--) { s->failed_pc=0x0c062464u; return 0; }
r[5]+=r[3];
goto P_0c062466;
P_0c062466: /* original 4508, guest PC 0x0c062466 */
if(!s->budget--) { s->failed_pc=0x0c062466u; return 0; }
r[5]<<=2;
goto P_0c062468;
P_0c062468: /* original 655e, guest PC 0x0c062468 */
if(!s->budget--) { s->failed_pc=0x0c062468u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c06246a;
P_0c06246a: /* original 35bc, guest PC 0x0c06246a */
if(!s->budget--) { s->failed_pc=0x0c06246au; return 0; }
r[5]+=r[11];
goto P_0c06246c;
P_0c06246c: /* original 2f52, guest PC 0x0c06246c */
if(!s->budget--) { s->failed_pc=0x0c06246cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c06246e;
P_0c06246e: /* original 750c, guest PC 0x0c06246e */
if(!s->budget--) { s->failed_pc=0x0c06246eu; return 0; }
r[5]+=0x0000000cu;
goto P_0c062470;
P_0c062470: /* original 64f2, guest PC 0x0c062470 */
if(!s->budget--) { s->failed_pc=0x0c062470u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c062472;
P_0c062472: /* original b037, guest PC 0x0c062472 */
if(!s->budget--) { s->failed_pc=0x0c062472u; return 0; }
target=0x0c0624e4u; r[16]=0x0c062476u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062476u) { target=s->pc; goto dispatch; }
goto P_0c062476;
P_0c062474: /* original 7408, guest PC 0x0c062474 */
if(!s->budget--) { s->failed_pc=0x0c062474u; return 0; }
r[4]+=0x00000008u;
goto P_0c062476;
P_0c062476: /* original e000, guest PC 0x0c062476 */
if(!s->budget--) { s->failed_pc=0x0c062476u; return 0; }
r[0]=0x00000000u;
goto P_0c062478;
P_0c062478: /* original 7f04, guest PC 0x0c062478 */
if(!s->budget--) { s->failed_pc=0x0c062478u; return 0; }
r[15]+=0x00000004u;
goto P_0c06247a;
P_0c06247a: /* original 4f26, guest PC 0x0c06247a */
if(!s->budget--) { s->failed_pc=0x0c06247au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06247c;
P_0c06247c: /* original 6af6, guest PC 0x0c06247c */
if(!s->budget--) { s->failed_pc=0x0c06247cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06247e;
P_0c06247e: /* original 6bf6, guest PC 0x0c06247e */
if(!s->budget--) { s->failed_pc=0x0c06247eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c062480;
P_0c062480: /* original 6cf6, guest PC 0x0c062480 */
if(!s->budget--) { s->failed_pc=0x0c062480u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c062482;
P_0c062482: /* original 6df6, guest PC 0x0c062482 */
if(!s->budget--) { s->failed_pc=0x0c062482u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062484;
P_0c062484: /* original 000b, guest PC 0x0c062484 */
if(!s->budget--) { s->failed_pc=0x0c062484u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c062486: /* original 6ef6, guest PC 0x0c062486 */
if(!s->budget--) { s->failed_pc=0x0c062486u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c062488u,s,ram);
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
return vf3_matrix_family(0x0c062c4eu,s,ram);
P_0c070c58: /* original f40b, guest PC 0x0c070c58 */
if(!s->budget--) { s->failed_pc=0x0c070c58u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c5a;
P_0c070c5a: /* original 0009, guest PC 0x0c070c5a */
if(!s->budget--) { s->failed_pc=0x0c070c5au; return 0; }
goto P_0c070c5c;
P_0c070c5c: /* original 64f3, guest PC 0x0c070c5c */
if(!s->budget--) { s->failed_pc=0x0c070c5cu; return 0; }
r[4]=r[15];
goto P_0c070c5e;
P_0c070c5e: /* original 742c, guest PC 0x0c070c5e */
if(!s->budget--) { s->failed_pc=0x0c070c5eu; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c60;
P_0c070c60: /* original f049, guest PC 0x0c070c60 */
if(!s->budget--) { s->failed_pc=0x0c070c60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c62;
P_0c070c62: /* original f149, guest PC 0x0c070c62 */
if(!s->budget--) { s->failed_pc=0x0c070c62u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c64;
P_0c070c64: /* original f249, guest PC 0x0c070c64 */
if(!s->budget--) { s->failed_pc=0x0c070c64u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c66;
P_0c070c66: /* original f38d, guest PC 0x0c070c66 */
if(!s->budget--) { s->failed_pc=0x0c070c66u; return 0; }
fr[3]=0;
goto P_0c070c68;
P_0c070c68: /* original f0ed, guest PC 0x0c070c68 */
if(!s->budget--) { s->failed_pc=0x0c070c68u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070c6a;
P_0c070c6a: /* original f03c, guest PC 0x0c070c6a */
if(!s->budget--) { s->failed_pc=0x0c070c6au; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070c6c;
P_0c070c6c: /* original f06d, guest PC 0x0c070c6c */
if(!s->budget--) { s->failed_pc=0x0c070c6cu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070c6e;
P_0c070c6e: /* original 0009, guest PC 0x0c070c6e */
if(!s->budget--) { s->failed_pc=0x0c070c6eu; return 0; }
goto P_0c070c70;
P_0c070c70: /* original f38d, guest PC 0x0c070c70 */
if(!s->budget--) { s->failed_pc=0x0c070c70u; return 0; }
fr[3]=0;
goto P_0c070c72;
P_0c070c72: /* original f035, guest PC 0x0c070c72 */
if(!s->budget--) { s->failed_pc=0x0c070c72u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070c74;
P_0c070c74: /* original 8902, guest PC 0x0c070c74 */
if(!s->budget--) { s->failed_pc=0x0c070c74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070c7c; }
goto P_0c070c76;
P_0c070c76: /* original d305, guest PC 0x0c070c76 */
if(!s->budget--) { s->failed_pc=0x0c070c76u; return 0; }
r[3]=read(ram,0x0c070c8cu,4);
goto P_0c070c78;
P_0c070c78: /* original 432b, guest PC 0x0c070c78 */
if(!s->budget--) { s->failed_pc=0x0c070c78u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070c7a: /* original 0009, guest PC 0x0c070c7a */
if(!s->budget--) { s->failed_pc=0x0c070c7au; return 0; }
goto P_0c070c7c;
P_0c070c7c: /* original 64f3, guest PC 0x0c070c7c */
if(!s->budget--) { s->failed_pc=0x0c070c7cu; return 0; }
r[4]=r[15];
goto P_0c070c7e;
P_0c070c7e: /* original 65f3, guest PC 0x0c070c7e */
if(!s->budget--) { s->failed_pc=0x0c070c7eu; return 0; }
r[5]=r[15];
goto P_0c070c80;
P_0c070c80: /* original 742c, guest PC 0x0c070c80 */
if(!s->budget--) { s->failed_pc=0x0c070c80u; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c82;
P_0c070c82: /* original f4dc, guest PC 0x0c070c82 */
if(!s->budget--) { s->failed_pc=0x0c070c82u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c070c84;
P_0c070c84: /* original 752c, guest PC 0x0c070c84 */
if(!s->budget--) { s->failed_pc=0x0c070c84u; return 0; }
r[5]+=0x0000002cu;
goto P_0c070c86;
P_0c070c86: /* original a003, guest PC 0x0c070c86 */
if(!s->budget--) { s->failed_pc=0x0c070c86u; return 0; }
goto P_0c070c90;
P_0c070c88: /* original 0009, guest PC 0x0c070c88 */
if(!s->budget--) { s->failed_pc=0x0c070c88u; return 0; }
return vf3_matrix_family(0x0c070c8au,s,ram);
P_0c070c90: /* original f059, guest PC 0x0c070c90 */
if(!s->budget--) { s->failed_pc=0x0c070c90u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c92;
P_0c070c92: /* original f159, guest PC 0x0c070c92 */
if(!s->budget--) { s->failed_pc=0x0c070c92u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c94;
P_0c070c94: /* original f259, guest PC 0x0c070c94 */
if(!s->budget--) { s->failed_pc=0x0c070c94u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c96;
P_0c070c96: /* original f38d, guest PC 0x0c070c96 */
if(!s->budget--) { s->failed_pc=0x0c070c96u; return 0; }
fr[3]=0;
goto P_0c070c98;
P_0c070c98: /* original f0ed, guest PC 0x0c070c98 */
if(!s->budget--) { s->failed_pc=0x0c070c98u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070c9a;
P_0c070c9a: /* original f37d, guest PC 0x0c070c9a */
if(!s->budget--) { s->failed_pc=0x0c070c9au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070c9c;
P_0c070c9c: /* original f342, guest PC 0x0c070c9c */
if(!s->budget--) { s->failed_pc=0x0c070c9cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070c9e;
P_0c070c9e: /* original 740c, guest PC 0x0c070c9e */
if(!s->budget--) { s->failed_pc=0x0c070c9eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070ca0;
P_0c070ca0: /* original f232, guest PC 0x0c070ca0 */
if(!s->budget--) { s->failed_pc=0x0c070ca0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070ca2;
P_0c070ca2: /* original f132, guest PC 0x0c070ca2 */
if(!s->budget--) { s->failed_pc=0x0c070ca2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070ca4;
P_0c070ca4: /* original f032, guest PC 0x0c070ca4 */
if(!s->budget--) { s->failed_pc=0x0c070ca4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070ca6;
P_0c070ca6: /* original f42b, guest PC 0x0c070ca6 */
if(!s->budget--) { s->failed_pc=0x0c070ca6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ca8;
P_0c070ca8: /* original f41b, guest PC 0x0c070ca8 */
if(!s->budget--) { s->failed_pc=0x0c070ca8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070caa;
P_0c070caa: /* original f40b, guest PC 0x0c070caa */
if(!s->budget--) { s->failed_pc=0x0c070caau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cac;
P_0c070cac: /* original 66f3, guest PC 0x0c070cac */
if(!s->budget--) { s->failed_pc=0x0c070cacu; return 0; }
r[6]=r[15];
goto P_0c070cae;
P_0c070cae: /* original 64e3, guest PC 0x0c070cae */
if(!s->budget--) { s->failed_pc=0x0c070caeu; return 0; }
r[4]=r[14];
goto P_0c070cb0;
P_0c070cb0: /* original 6583, guest PC 0x0c070cb0 */
if(!s->budget--) { s->failed_pc=0x0c070cb0u; return 0; }
r[5]=r[8];
goto P_0c070cb2;
P_0c070cb2: /* original 762c, guest PC 0x0c070cb2 */
if(!s->budget--) { s->failed_pc=0x0c070cb2u; return 0; }
r[6]+=0x0000002cu;
goto P_0c070cb4;
P_0c070cb4: /* original f059, guest PC 0x0c070cb4 */
if(!s->budget--) { s->failed_pc=0x0c070cb4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cb6;
P_0c070cb6: /* original f369, guest PC 0x0c070cb6 */
if(!s->budget--) { s->failed_pc=0x0c070cb6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cb8;
P_0c070cb8: /* original f159, guest PC 0x0c070cb8 */
if(!s->budget--) { s->failed_pc=0x0c070cb8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cba;
P_0c070cba: /* original f469, guest PC 0x0c070cba */
if(!s->budget--) { s->failed_pc=0x0c070cbau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cbc;
P_0c070cbc: /* original f259, guest PC 0x0c070cbc */
if(!s->budget--) { s->failed_pc=0x0c070cbcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cbe;
P_0c070cbe: /* original f569, guest PC 0x0c070cbe */
if(!s->budget--) { s->failed_pc=0x0c070cbeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cc0;
P_0c070cc0: /* original 740c, guest PC 0x0c070cc0 */
if(!s->budget--) { s->failed_pc=0x0c070cc0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070cc2;
P_0c070cc2: /* original f030, guest PC 0x0c070cc2 */
if(!s->budget--) { s->failed_pc=0x0c070cc2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070cc4;
P_0c070cc4: /* original f250, guest PC 0x0c070cc4 */
if(!s->budget--) { s->failed_pc=0x0c070cc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070cc6;
P_0c070cc6: /* original f140, guest PC 0x0c070cc6 */
if(!s->budget--) { s->failed_pc=0x0c070cc6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070cc8;
P_0c070cc8: /* original f42b, guest PC 0x0c070cc8 */
if(!s->budget--) { s->failed_pc=0x0c070cc8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070cca;
P_0c070cca: /* original f41b, guest PC 0x0c070cca */
if(!s->budget--) { s->failed_pc=0x0c070ccau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ccc;
P_0c070ccc: /* original f40b, guest PC 0x0c070ccc */
if(!s->budget--) { s->failed_pc=0x0c070cccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cce;
P_0c070cce: /* original 0009, guest PC 0x0c070cce */
if(!s->budget--) { s->failed_pc=0x0c070cceu; return 0; }
goto P_0c070cd0;
P_0c070cd0: /* original 64f3, guest PC 0x0c070cd0 */
if(!s->budget--) { s->failed_pc=0x0c070cd0u; return 0; }
r[4]=r[15];
goto P_0c070cd2;
P_0c070cd2: /* original 7444, guest PC 0x0c070cd2 */
if(!s->budget--) { s->failed_pc=0x0c070cd2u; return 0; }
r[4]+=0x00000044u;
goto P_0c070cd4;
P_0c070cd4: /* original 66a3, guest PC 0x0c070cd4 */
if(!s->budget--) { s->failed_pc=0x0c070cd4u; return 0; }
r[6]=r[10];
goto P_0c070cd6;
P_0c070cd6: /* original 65d3, guest PC 0x0c070cd6 */
if(!s->budget--) { s->failed_pc=0x0c070cd6u; return 0; }
r[5]=r[13];
goto P_0c070cd8;
P_0c070cd8: /* original f059, guest PC 0x0c070cd8 */
if(!s->budget--) { s->failed_pc=0x0c070cd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cda;
P_0c070cda: /* original f369, guest PC 0x0c070cda */
if(!s->budget--) { s->failed_pc=0x0c070cdau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cdc;
P_0c070cdc: /* original f159, guest PC 0x0c070cdc */
if(!s->budget--) { s->failed_pc=0x0c070cdcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cde;
P_0c070cde: /* original f469, guest PC 0x0c070cde */
if(!s->budget--) { s->failed_pc=0x0c070cdeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070ce0;
P_0c070ce0: /* original f031, guest PC 0x0c070ce0 */
if(!s->budget--) { s->failed_pc=0x0c070ce0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070ce2;
P_0c070ce2: /* original f258, guest PC 0x0c070ce2 */
if(!s->budget--) { s->failed_pc=0x0c070ce2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070ce4;
P_0c070ce4: /* original f568, guest PC 0x0c070ce4 */
if(!s->budget--) { s->failed_pc=0x0c070ce4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070ce6;
P_0c070ce6: /* original f141, guest PC 0x0c070ce6 */
if(!s->budget--) { s->failed_pc=0x0c070ce6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070ce8;
P_0c070ce8: /* original f251, guest PC 0x0c070ce8 */
if(!s->budget--) { s->failed_pc=0x0c070ce8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070cea;
P_0c070cea: /* original 7408, guest PC 0x0c070cea */
if(!s->budget--) { s->failed_pc=0x0c070ceau; return 0; }
r[4]+=0x00000008u;
goto P_0c070cec;
P_0c070cec: /* original f42a, guest PC 0x0c070cec */
if(!s->budget--) { s->failed_pc=0x0c070cecu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070cee;
P_0c070cee: /* original f41b, guest PC 0x0c070cee */
if(!s->budget--) { s->failed_pc=0x0c070ceeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070cf0;
P_0c070cf0: /* original f40b, guest PC 0x0c070cf0 */
if(!s->budget--) { s->failed_pc=0x0c070cf0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cf2;
P_0c070cf2: /* original 0009, guest PC 0x0c070cf2 */
if(!s->budget--) { s->failed_pc=0x0c070cf2u; return 0; }
goto P_0c070cf4;
P_0c070cf4: /* original 64f3, guest PC 0x0c070cf4 */
if(!s->budget--) { s->failed_pc=0x0c070cf4u; return 0; }
r[4]=r[15];
goto P_0c070cf6;
P_0c070cf6: /* original 7444, guest PC 0x0c070cf6 */
if(!s->budget--) { s->failed_pc=0x0c070cf6u; return 0; }
r[4]+=0x00000044u;
goto P_0c070cf8;
P_0c070cf8: /* original f049, guest PC 0x0c070cf8 */
if(!s->budget--) { s->failed_pc=0x0c070cf8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfa;
P_0c070cfa: /* original f149, guest PC 0x0c070cfa */
if(!s->budget--) { s->failed_pc=0x0c070cfau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfc;
P_0c070cfc: /* original f249, guest PC 0x0c070cfc */
if(!s->budget--) { s->failed_pc=0x0c070cfcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfe;
P_0c070cfe: /* original f38d, guest PC 0x0c070cfe */
if(!s->budget--) { s->failed_pc=0x0c070cfeu; return 0; }
fr[3]=0;
goto P_0c070d00;
P_0c070d00: /* original f0ed, guest PC 0x0c070d00 */
if(!s->budget--) { s->failed_pc=0x0c070d00u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070d02;
P_0c070d02: /* original f03c, guest PC 0x0c070d02 */
if(!s->budget--) { s->failed_pc=0x0c070d02u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070d04;
P_0c070d04: /* original f06d, guest PC 0x0c070d04 */
if(!s->budget--) { s->failed_pc=0x0c070d04u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070d06;
P_0c070d06: /* original 0009, guest PC 0x0c070d06 */
if(!s->budget--) { s->failed_pc=0x0c070d06u; return 0; }
goto P_0c070d08;
P_0c070d08: /* original f38d, guest PC 0x0c070d08 */
if(!s->budget--) { s->failed_pc=0x0c070d08u; return 0; }
fr[3]=0;
goto P_0c070d0a;
P_0c070d0a: /* original fc0c, guest PC 0x0c070d0a */
if(!s->budget--) { s->failed_pc=0x0c070d0au; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070d0c;
P_0c070d0c: /* original fc35, guest PC 0x0c070d0c */
if(!s->budget--) { s->failed_pc=0x0c070d0cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070d0e;
P_0c070d0e: /* original 8902, guest PC 0x0c070d0e */
if(!s->budget--) { s->failed_pc=0x0c070d0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d16; }
goto P_0c070d10;
P_0c070d10: /* original d303, guest PC 0x0c070d10 */
if(!s->budget--) { s->failed_pc=0x0c070d10u; return 0; }
r[3]=read(ram,0x0c070d20u,4);
goto P_0c070d12;
P_0c070d12: /* original 432b, guest PC 0x0c070d12 */
if(!s->budget--) { s->failed_pc=0x0c070d12u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070d14: /* original 0009, guest PC 0x0c070d14 */
if(!s->budget--) { s->failed_pc=0x0c070d14u; return 0; }
goto P_0c070d16;
P_0c070d16: /* original 64f3, guest PC 0x0c070d16 */
if(!s->budget--) { s->failed_pc=0x0c070d16u; return 0; }
r[4]=r[15];
goto P_0c070d18;
P_0c070d18: /* original 7444, guest PC 0x0c070d18 */
if(!s->budget--) { s->failed_pc=0x0c070d18u; return 0; }
r[4]+=0x00000044u;
goto P_0c070d1a;
P_0c070d1a: /* original 65b3, guest PC 0x0c070d1a */
if(!s->budget--) { s->failed_pc=0x0c070d1au; return 0; }
r[5]=r[11];
goto P_0c070d1c;
P_0c070d1c: /* original a002, guest PC 0x0c070d1c */
if(!s->budget--) { s->failed_pc=0x0c070d1cu; return 0; }
goto P_0c070d24;
P_0c070d1e: /* original 0009, guest PC 0x0c070d1e */
if(!s->budget--) { s->failed_pc=0x0c070d1eu; return 0; }
return vf3_matrix_family(0x0c070d20u,s,ram);
P_0c070d24: /* original f049, guest PC 0x0c070d24 */
if(!s->budget--) { s->failed_pc=0x0c070d24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d26;
P_0c070d26: /* original f549, guest PC 0x0c070d26 */
if(!s->budget--) { s->failed_pc=0x0c070d26u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d28;
P_0c070d28: /* original f648, guest PC 0x0c070d28 */
if(!s->budget--) { s->failed_pc=0x0c070d28u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070d2a;
P_0c070d2a: /* original f859, guest PC 0x0c070d2a */
if(!s->budget--) { s->failed_pc=0x0c070d2au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d2c;
P_0c070d2c: /* original f959, guest PC 0x0c070d2c */
if(!s->budget--) { s->failed_pc=0x0c070d2cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d2e;
P_0c070d2e: /* original fa58, guest PC 0x0c070d2e */
if(!s->budget--) { s->failed_pc=0x0c070d2eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070d30;
P_0c070d30: /* original f35c, guest PC 0x0c070d30 */
if(!s->budget--) { s->failed_pc=0x0c070d30u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070d32;
P_0c070d32: /* original f382, guest PC 0x0c070d32 */
if(!s->budget--) { s->failed_pc=0x0c070d32u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070d34;
P_0c070d34: /* original f20c, guest PC 0x0c070d34 */
if(!s->budget--) { s->failed_pc=0x0c070d34u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070d36;
P_0c070d36: /* original f2a2, guest PC 0x0c070d36 */
if(!s->budget--) { s->failed_pc=0x0c070d36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070d38;
P_0c070d38: /* original f16c, guest PC 0x0c070d38 */
if(!s->budget--) { s->failed_pc=0x0c070d38u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070d3a;
P_0c070d3a: /* original f192, guest PC 0x0c070d3a */
if(!s->budget--) { s->failed_pc=0x0c070d3au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070d3c;
P_0c070d3c: /* original f34d, guest PC 0x0c070d3c */
if(!s->budget--) { s->failed_pc=0x0c070d3cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c070d3e;
P_0c070d3e: /* original f39e, guest PC 0x0c070d3e */
if(!s->budget--) { s->failed_pc=0x0c070d3eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070d40;
P_0c070d40: /* original f24d, guest PC 0x0c070d40 */
if(!s->budget--) { s->failed_pc=0x0c070d40u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070d42;
P_0c070d42: /* original f06c, guest PC 0x0c070d42 */
if(!s->budget--) { s->failed_pc=0x0c070d42u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070d44;
P_0c070d44: /* original f28e, guest PC 0x0c070d44 */
if(!s->budget--) { s->failed_pc=0x0c070d44u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070d46;
P_0c070d46: /* original f14d, guest PC 0x0c070d46 */
if(!s->budget--) { s->failed_pc=0x0c070d46u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070d48;
P_0c070d48: /* original f05c, guest PC 0x0c070d48 */
if(!s->budget--) { s->failed_pc=0x0c070d48u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070d4a;
P_0c070d4a: /* original f1ae, guest PC 0x0c070d4a */
if(!s->budget--) { s->failed_pc=0x0c070d4au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070d4c;
P_0c070d4c: /* original f08d, guest PC 0x0c070d4c */
if(!s->budget--) { s->failed_pc=0x0c070d4cu; return 0; }
fr[0]=0;
goto P_0c070d4e;
P_0c070d4e: /* original f0ed, guest PC 0x0c070d4e */
if(!s->budget--) { s->failed_pc=0x0c070d4eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070d50;
P_0c070d50: /* original f03c, guest PC 0x0c070d50 */
if(!s->budget--) { s->failed_pc=0x0c070d50u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070d52;
P_0c070d52: /* original f06d, guest PC 0x0c070d52 */
if(!s->budget--) { s->failed_pc=0x0c070d52u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070d54;
P_0c070d54: /* original ff05, guest PC 0x0c070d54 */
if(!s->budget--) { s->failed_pc=0x0c070d54u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070d56;
P_0c070d56: /* original e01c, guest PC 0x0c070d56 */
if(!s->budget--) { s->failed_pc=0x0c070d56u; return 0; }
r[0]=0x0000001cu;
goto P_0c070d58;
P_0c070d58: /* original 8d03, guest PC 0x0c070d58 */
if(!s->budget--) { s->failed_pc=0x0c070d58u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070d62; }
goto P_0c070d5c;
P_0c070d5a: /* original ff07, guest PC 0x0c070d5a */
if(!s->budget--) { s->failed_pc=0x0c070d5au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070d5c;
P_0c070d5c: /* original d303, guest PC 0x0c070d5c */
if(!s->budget--) { s->failed_pc=0x0c070d5cu; return 0; }
r[3]=read(ram,0x0c070d6cu,4);
goto P_0c070d5e;
P_0c070d5e: /* original 432b, guest PC 0x0c070d5e */
if(!s->budget--) { s->failed_pc=0x0c070d5eu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070d60: /* original 0009, guest PC 0x0c070d60 */
if(!s->budget--) { s->failed_pc=0x0c070d60u; return 0; }
goto P_0c070d62;
P_0c070d62: /* original 64f3, guest PC 0x0c070d62 */
if(!s->budget--) { s->failed_pc=0x0c070d62u; return 0; }
r[4]=r[15];
goto P_0c070d64;
P_0c070d64: /* original 7444, guest PC 0x0c070d64 */
if(!s->budget--) { s->failed_pc=0x0c070d64u; return 0; }
r[4]+=0x00000044u;
goto P_0c070d66;
P_0c070d66: /* original 65b3, guest PC 0x0c070d66 */
if(!s->budget--) { s->failed_pc=0x0c070d66u; return 0; }
r[5]=r[11];
goto P_0c070d68;
P_0c070d68: /* original a002, guest PC 0x0c070d68 */
if(!s->budget--) { s->failed_pc=0x0c070d68u; return 0; }
goto P_0c070d70;
P_0c070d6a: /* original 0009, guest PC 0x0c070d6a */
if(!s->budget--) { s->failed_pc=0x0c070d6au; return 0; }
return vf3_matrix_family(0x0c070d6cu,s,ram);
P_0c070d70: /* original f049, guest PC 0x0c070d70 */
if(!s->budget--) { s->failed_pc=0x0c070d70u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d72;
P_0c070d72: /* original f149, guest PC 0x0c070d72 */
if(!s->budget--) { s->failed_pc=0x0c070d72u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d74;
P_0c070d74: /* original f249, guest PC 0x0c070d74 */
if(!s->budget--) { s->failed_pc=0x0c070d74u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d76;
P_0c070d76: /* original f38d, guest PC 0x0c070d76 */
if(!s->budget--) { s->failed_pc=0x0c070d76u; return 0; }
fr[3]=0;
goto P_0c070d78;
P_0c070d78: /* original f459, guest PC 0x0c070d78 */
if(!s->budget--) { s->failed_pc=0x0c070d78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7a;
P_0c070d7a: /* original f559, guest PC 0x0c070d7a */
if(!s->budget--) { s->failed_pc=0x0c070d7au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7c;
P_0c070d7c: /* original f659, guest PC 0x0c070d7c */
if(!s->budget--) { s->failed_pc=0x0c070d7cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7e;
P_0c070d7e: /* original f78d, guest PC 0x0c070d7e */
if(!s->budget--) { s->failed_pc=0x0c070d7eu; return 0; }
fr[7]=0;
goto P_0c070d80;
P_0c070d80: /* original f4ed, guest PC 0x0c070d80 */
if(!s->budget--) { s->failed_pc=0x0c070d80u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070d82;
P_0c070d82: /* original f07c, guest PC 0x0c070d82 */
if(!s->budget--) { s->failed_pc=0x0c070d82u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070d84;
P_0c070d84: /* original f38d, guest PC 0x0c070d84 */
if(!s->budget--) { s->failed_pc=0x0c070d84u; return 0; }
fr[3]=0;
goto P_0c070d86;
P_0c070d86: /* original f40c, guest PC 0x0c070d86 */
if(!s->budget--) { s->failed_pc=0x0c070d86u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070d88;
P_0c070d88: /* original f345, guest PC 0x0c070d88 */
if(!s->budget--) { s->failed_pc=0x0c070d88u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070d8a;
P_0c070d8a: /* original 8902, guest PC 0x0c070d8a */
if(!s->budget--) { s->failed_pc=0x0c070d8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d92; }
goto P_0c070d8c;
P_0c070d8c: /* original d307, guest PC 0x0c070d8c */
if(!s->budget--) { s->failed_pc=0x0c070d8cu; return 0; }
r[3]=read(ram,0x0c070dacu,4);
goto P_0c070d8e;
P_0c070d8e: /* original 432b, guest PC 0x0c070d8e */
if(!s->budget--) { s->failed_pc=0x0c070d8eu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070d90: /* original 0009, guest PC 0x0c070d90 */
if(!s->budget--) { s->failed_pc=0x0c070d90u; return 0; }
goto P_0c070d92;
P_0c070d92: /* original ffc5, guest PC 0x0c070d92 */
if(!s->budget--) { s->failed_pc=0x0c070d92u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070d94;
P_0c070d94: /* original 8902, guest PC 0x0c070d94 */
if(!s->budget--) { s->failed_pc=0x0c070d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d9c; }
goto P_0c070d96;
P_0c070d96: /* original d206, guest PC 0x0c070d96 */
if(!s->budget--) { s->failed_pc=0x0c070d96u; return 0; }
r[2]=read(ram,0x0c070db0u,4);
goto P_0c070d98;
P_0c070d98: /* original 422b, guest PC 0x0c070d98 */
if(!s->budget--) { s->failed_pc=0x0c070d98u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070d9a: /* original 0009, guest PC 0x0c070d9a */
if(!s->budget--) { s->failed_pc=0x0c070d9au; return 0; }
goto P_0c070d9c;
P_0c070d9c: /* original 64f3, guest PC 0x0c070d9c */
if(!s->budget--) { s->failed_pc=0x0c070d9cu; return 0; }
r[4]=r[15];
goto P_0c070d9e;
P_0c070d9e: /* original 65f3, guest PC 0x0c070d9e */
if(!s->budget--) { s->failed_pc=0x0c070d9eu; return 0; }
r[5]=r[15];
goto P_0c070da0;
P_0c070da0: /* original 7444, guest PC 0x0c070da0 */
if(!s->budget--) { s->failed_pc=0x0c070da0u; return 0; }
r[4]+=0x00000044u;
goto P_0c070da2;
P_0c070da2: /* original f4fc, guest PC 0x0c070da2 */
if(!s->budget--) { s->failed_pc=0x0c070da2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070da4;
P_0c070da4: /* original 7544, guest PC 0x0c070da4 */
if(!s->budget--) { s->failed_pc=0x0c070da4u; return 0; }
r[5]+=0x00000044u;
goto P_0c070da6;
P_0c070da6: /* original a005, guest PC 0x0c070da6 */
if(!s->budget--) { s->failed_pc=0x0c070da6u; return 0; }
goto P_0c070db4;
P_0c070da8: /* original 0009, guest PC 0x0c070da8 */
if(!s->budget--) { s->failed_pc=0x0c070da8u; return 0; }
return vf3_matrix_family(0x0c070daau,s,ram);
P_0c070db4: /* original f059, guest PC 0x0c070db4 */
if(!s->budget--) { s->failed_pc=0x0c070db4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070db6;
P_0c070db6: /* original f159, guest PC 0x0c070db6 */
if(!s->budget--) { s->failed_pc=0x0c070db6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070db8;
P_0c070db8: /* original f259, guest PC 0x0c070db8 */
if(!s->budget--) { s->failed_pc=0x0c070db8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070dba;
P_0c070dba: /* original f38d, guest PC 0x0c070dba */
if(!s->budget--) { s->failed_pc=0x0c070dbau; return 0; }
fr[3]=0;
goto P_0c070dbc;
P_0c070dbc: /* original f0ed, guest PC 0x0c070dbc */
if(!s->budget--) { s->failed_pc=0x0c070dbcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070dbe;
P_0c070dbe: /* original f37d, guest PC 0x0c070dbe */
if(!s->budget--) { s->failed_pc=0x0c070dbeu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070dc0;
P_0c070dc0: /* original f342, guest PC 0x0c070dc0 */
if(!s->budget--) { s->failed_pc=0x0c070dc0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070dc2;
P_0c070dc2: /* original 740c, guest PC 0x0c070dc2 */
if(!s->budget--) { s->failed_pc=0x0c070dc2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070dc4;
P_0c070dc4: /* original f232, guest PC 0x0c070dc4 */
if(!s->budget--) { s->failed_pc=0x0c070dc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070dc6;
P_0c070dc6: /* original f132, guest PC 0x0c070dc6 */
if(!s->budget--) { s->failed_pc=0x0c070dc6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070dc8;
P_0c070dc8: /* original f032, guest PC 0x0c070dc8 */
if(!s->budget--) { s->failed_pc=0x0c070dc8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070dca;
P_0c070dca: /* original f42b, guest PC 0x0c070dca */
if(!s->budget--) { s->failed_pc=0x0c070dcau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070dcc;
P_0c070dcc: /* original f41b, guest PC 0x0c070dcc */
if(!s->budget--) { s->failed_pc=0x0c070dccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070dce;
P_0c070dce: /* original f40b, guest PC 0x0c070dce */
if(!s->budget--) { s->failed_pc=0x0c070dceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070dd0;
P_0c070dd0: /* original d206, guest PC 0x0c070dd0 */
if(!s->budget--) { s->failed_pc=0x0c070dd0u; return 0; }
r[2]=read(ram,0x0c070decu,4);
goto P_0c070dd2;
P_0c070dd2: /* original 422b, guest PC 0x0c070dd2 */
if(!s->budget--) { s->failed_pc=0x0c070dd2u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070dd4: /* original 0009, guest PC 0x0c070dd4 */
if(!s->budget--) { s->failed_pc=0x0c070dd4u; return 0; }
return vf3_matrix_family(0x0c070dd6u,s,ram);
P_0c071090: /* original f40b, guest PC 0x0c071090 */
if(!s->budget--) { s->failed_pc=0x0c071090u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071092;
P_0c071092: /* original 0009, guest PC 0x0c071092 */
if(!s->budget--) { s->failed_pc=0x0c071092u; return 0; }
goto P_0c071094;
P_0c071094: /* original 64f3, guest PC 0x0c071094 */
if(!s->budget--) { s->failed_pc=0x0c071094u; return 0; }
r[4]=r[15];
goto P_0c071096;
P_0c071096: /* original 742c, guest PC 0x0c071096 */
if(!s->budget--) { s->failed_pc=0x0c071096u; return 0; }
r[4]+=0x0000002cu;
goto P_0c071098;
P_0c071098: /* original f049, guest PC 0x0c071098 */
if(!s->budget--) { s->failed_pc=0x0c071098u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109a;
P_0c07109a: /* original f149, guest PC 0x0c07109a */
if(!s->budget--) { s->failed_pc=0x0c07109au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109c;
P_0c07109c: /* original f249, guest PC 0x0c07109c */
if(!s->budget--) { s->failed_pc=0x0c07109cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109e;
P_0c07109e: /* original f38d, guest PC 0x0c07109e */
if(!s->budget--) { s->failed_pc=0x0c07109eu; return 0; }
fr[3]=0;
goto P_0c0710a0;
P_0c0710a0: /* original f0ed, guest PC 0x0c0710a0 */
if(!s->budget--) { s->failed_pc=0x0c0710a0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0710a2;
P_0c0710a2: /* original f03c, guest PC 0x0c0710a2 */
if(!s->budget--) { s->failed_pc=0x0c0710a2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0710a4;
P_0c0710a4: /* original f06d, guest PC 0x0c0710a4 */
if(!s->budget--) { s->failed_pc=0x0c0710a4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c0710a6;
P_0c0710a6: /* original 0009, guest PC 0x0c0710a6 */
if(!s->budget--) { s->failed_pc=0x0c0710a6u; return 0; }
goto P_0c0710a8;
P_0c0710a8: /* original f38d, guest PC 0x0c0710a8 */
if(!s->budget--) { s->failed_pc=0x0c0710a8u; return 0; }
fr[3]=0;
goto P_0c0710aa;
P_0c0710aa: /* original f035, guest PC 0x0c0710aa */
if(!s->budget--) { s->failed_pc=0x0c0710aau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0710ac;
P_0c0710ac: /* original 8902, guest PC 0x0c0710ac */
if(!s->budget--) { s->failed_pc=0x0c0710acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0710b4; }
goto P_0c0710ae;
P_0c0710ae: /* original d305, guest PC 0x0c0710ae */
if(!s->budget--) { s->failed_pc=0x0c0710aeu; return 0; }
r[3]=read(ram,0x0c0710c4u,4);
goto P_0c0710b0;
P_0c0710b0: /* original 432b, guest PC 0x0c0710b0 */
if(!s->budget--) { s->failed_pc=0x0c0710b0u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0710b2: /* original 0009, guest PC 0x0c0710b2 */
if(!s->budget--) { s->failed_pc=0x0c0710b2u; return 0; }
goto P_0c0710b4;
P_0c0710b4: /* original 64f3, guest PC 0x0c0710b4 */
if(!s->budget--) { s->failed_pc=0x0c0710b4u; return 0; }
r[4]=r[15];
goto P_0c0710b6;
P_0c0710b6: /* original 65f3, guest PC 0x0c0710b6 */
if(!s->budget--) { s->failed_pc=0x0c0710b6u; return 0; }
r[5]=r[15];
goto P_0c0710b8;
P_0c0710b8: /* original 742c, guest PC 0x0c0710b8 */
if(!s->budget--) { s->failed_pc=0x0c0710b8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0710ba;
P_0c0710ba: /* original f4dc, guest PC 0x0c0710ba */
if(!s->budget--) { s->failed_pc=0x0c0710bau; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0710bc;
P_0c0710bc: /* original 752c, guest PC 0x0c0710bc */
if(!s->budget--) { s->failed_pc=0x0c0710bcu; return 0; }
r[5]+=0x0000002cu;
goto P_0c0710be;
P_0c0710be: /* original a003, guest PC 0x0c0710be */
if(!s->budget--) { s->failed_pc=0x0c0710beu; return 0; }
goto P_0c0710c8;
P_0c0710c0: /* original 0009, guest PC 0x0c0710c0 */
if(!s->budget--) { s->failed_pc=0x0c0710c0u; return 0; }
return vf3_matrix_family(0x0c0710c2u,s,ram);
P_0c0710c8: /* original f059, guest PC 0x0c0710c8 */
if(!s->budget--) { s->failed_pc=0x0c0710c8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ca;
P_0c0710ca: /* original f159, guest PC 0x0c0710ca */
if(!s->budget--) { s->failed_pc=0x0c0710cau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710cc;
P_0c0710cc: /* original f259, guest PC 0x0c0710cc */
if(!s->budget--) { s->failed_pc=0x0c0710ccu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ce;
P_0c0710ce: /* original f38d, guest PC 0x0c0710ce */
if(!s->budget--) { s->failed_pc=0x0c0710ceu; return 0; }
fr[3]=0;
goto P_0c0710d0;
P_0c0710d0: /* original f0ed, guest PC 0x0c0710d0 */
if(!s->budget--) { s->failed_pc=0x0c0710d0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0710d2;
P_0c0710d2: /* original f37d, guest PC 0x0c0710d2 */
if(!s->budget--) { s->failed_pc=0x0c0710d2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0710d4;
P_0c0710d4: /* original f342, guest PC 0x0c0710d4 */
if(!s->budget--) { s->failed_pc=0x0c0710d4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0710d6;
P_0c0710d6: /* original 740c, guest PC 0x0c0710d6 */
if(!s->budget--) { s->failed_pc=0x0c0710d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0710d8;
P_0c0710d8: /* original f232, guest PC 0x0c0710d8 */
if(!s->budget--) { s->failed_pc=0x0c0710d8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0710da;
P_0c0710da: /* original f132, guest PC 0x0c0710da */
if(!s->budget--) { s->failed_pc=0x0c0710dau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0710dc;
P_0c0710dc: /* original f032, guest PC 0x0c0710dc */
if(!s->budget--) { s->failed_pc=0x0c0710dcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0710de;
P_0c0710de: /* original f42b, guest PC 0x0c0710de */
if(!s->budget--) { s->failed_pc=0x0c0710deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0710e0;
P_0c0710e0: /* original f41b, guest PC 0x0c0710e0 */
if(!s->budget--) { s->failed_pc=0x0c0710e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0710e2;
P_0c0710e2: /* original f40b, guest PC 0x0c0710e2 */
if(!s->budget--) { s->failed_pc=0x0c0710e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0710e4;
P_0c0710e4: /* original 55f1, guest PC 0x0c0710e4 */
if(!s->budget--) { s->failed_pc=0x0c0710e4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0710e6;
P_0c0710e6: /* original 66f3, guest PC 0x0c0710e6 */
if(!s->budget--) { s->failed_pc=0x0c0710e6u; return 0; }
r[6]=r[15];
goto P_0c0710e8;
P_0c0710e8: /* original 64d3, guest PC 0x0c0710e8 */
if(!s->budget--) { s->failed_pc=0x0c0710e8u; return 0; }
r[4]=r[13];
goto P_0c0710ea;
P_0c0710ea: /* original 762c, guest PC 0x0c0710ea */
if(!s->budget--) { s->failed_pc=0x0c0710eau; return 0; }
r[6]+=0x0000002cu;
goto P_0c0710ec;
P_0c0710ec: /* original f059, guest PC 0x0c0710ec */
if(!s->budget--) { s->failed_pc=0x0c0710ecu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ee;
P_0c0710ee: /* original f369, guest PC 0x0c0710ee */
if(!s->budget--) { s->failed_pc=0x0c0710eeu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f0;
P_0c0710f0: /* original f159, guest PC 0x0c0710f0 */
if(!s->budget--) { s->failed_pc=0x0c0710f0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f2;
P_0c0710f2: /* original f469, guest PC 0x0c0710f2 */
if(!s->budget--) { s->failed_pc=0x0c0710f2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f4;
P_0c0710f4: /* original f259, guest PC 0x0c0710f4 */
if(!s->budget--) { s->failed_pc=0x0c0710f4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f6;
P_0c0710f6: /* original f569, guest PC 0x0c0710f6 */
if(!s->budget--) { s->failed_pc=0x0c0710f6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f8;
P_0c0710f8: /* original 740c, guest PC 0x0c0710f8 */
if(!s->budget--) { s->failed_pc=0x0c0710f8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0710fa;
P_0c0710fa: /* original f030, guest PC 0x0c0710fa */
if(!s->budget--) { s->failed_pc=0x0c0710fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0710fc;
P_0c0710fc: /* original f250, guest PC 0x0c0710fc */
if(!s->budget--) { s->failed_pc=0x0c0710fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0710fe;
P_0c0710fe: /* original f140, guest PC 0x0c0710fe */
if(!s->budget--) { s->failed_pc=0x0c0710feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071100;
P_0c071100: /* original f42b, guest PC 0x0c071100 */
if(!s->budget--) { s->failed_pc=0x0c071100u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071102;
P_0c071102: /* original f41b, guest PC 0x0c071102 */
if(!s->budget--) { s->failed_pc=0x0c071102u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071104;
P_0c071104: /* original f40b, guest PC 0x0c071104 */
if(!s->budget--) { s->failed_pc=0x0c071104u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071106;
P_0c071106: /* original 0009, guest PC 0x0c071106 */
if(!s->budget--) { s->failed_pc=0x0c071106u; return 0; }
goto P_0c071108;
P_0c071108: /* original 52f1, guest PC 0x0c071108 */
if(!s->budget--) { s->failed_pc=0x0c071108u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07110a;
P_0c07110a: /* original 7d18, guest PC 0x0c07110a */
if(!s->budget--) { s->failed_pc=0x0c07110au; return 0; }
r[13]+=0x00000018u;
goto P_0c07110c;
P_0c07110c: /* original 78e8, guest PC 0x0c07110c */
if(!s->budget--) { s->failed_pc=0x0c07110cu; return 0; }
r[8]+=0xffffffe8u;
goto P_0c07110e;
P_0c07110e: /* original 7218, guest PC 0x0c07110e */
if(!s->budget--) { s->failed_pc=0x0c07110eu; return 0; }
r[2]+=0x00000018u;
goto P_0c071110;
P_0c071110: /* original 1f21, guest PC 0x0c071110 */
if(!s->budget--) { s->failed_pc=0x0c071110u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c071112;
P_0c071112: /* original 7ee8, guest PC 0x0c071112 */
if(!s->budget--) { s->failed_pc=0x0c071112u; return 0; }
r[14]+=0xffffffe8u;
goto P_0c071114;
P_0c071114: /* original 63f2, guest PC 0x0c071114 */
if(!s->budget--) { s->failed_pc=0x0c071114u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071116;
P_0c071116: /* original 73ff, guest PC 0x0c071116 */
if(!s->budget--) { s->failed_pc=0x0c071116u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071118;
P_0c071118: /* original 4315, guest PC 0x0c071118 */
if(!s->budget--) { s->failed_pc=0x0c071118u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07111a;
P_0c07111a: /* original 8f03, guest PC 0x0c07111a */
if(!s->budget--) { s->failed_pc=0x0c07111au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c071124; }
goto P_0c07111e;
P_0c07111c: /* original 2f32, guest PC 0x0c07111c */
if(!s->budget--) { s->failed_pc=0x0c07111cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07111e;
P_0c07111e: /* original d11d, guest PC 0x0c07111e */
if(!s->budget--) { s->failed_pc=0x0c07111eu; return 0; }
r[1]=read(ram,0x0c071194u,4);
goto P_0c071120;
P_0c071120: /* original 412b, guest PC 0x0c071120 */
if(!s->budget--) { s->failed_pc=0x0c071120u; return 0; }
target=r[1];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071122: /* original 0009, guest PC 0x0c071122 */
if(!s->budget--) { s->failed_pc=0x0c071122u; return 0; }
goto P_0c071124;
P_0c071124: /* original 7f5c, guest PC 0x0c071124 */
if(!s->budget--) { s->failed_pc=0x0c071124u; return 0; }
r[15]+=0x0000005cu;
goto P_0c071126;
P_0c071126: /* original 4f26, guest PC 0x0c071126 */
if(!s->budget--) { s->failed_pc=0x0c071126u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c071128;
P_0c071128: /* original fcf9, guest PC 0x0c071128 */
if(!s->budget--) { s->failed_pc=0x0c071128u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112a;
P_0c07112a: /* original fdf9, guest PC 0x0c07112a */
if(!s->budget--) { s->failed_pc=0x0c07112au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112c;
P_0c07112c: /* original fef9, guest PC 0x0c07112c */
if(!s->budget--) { s->failed_pc=0x0c07112cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112e;
P_0c07112e: /* original fff9, guest PC 0x0c07112e */
if(!s->budget--) { s->failed_pc=0x0c07112eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071130;
P_0c071130: /* original 68f6, guest PC 0x0c071130 */
if(!s->budget--) { s->failed_pc=0x0c071130u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c071132;
P_0c071132: /* original 69f6, guest PC 0x0c071132 */
if(!s->budget--) { s->failed_pc=0x0c071132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c071134;
P_0c071134: /* original 6af6, guest PC 0x0c071134 */
if(!s->budget--) { s->failed_pc=0x0c071134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c071136;
P_0c071136: /* original 6bf6, guest PC 0x0c071136 */
if(!s->budget--) { s->failed_pc=0x0c071136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c071138;
P_0c071138: /* original 6cf6, guest PC 0x0c071138 */
if(!s->budget--) { s->failed_pc=0x0c071138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07113a;
P_0c07113a: /* original 6df6, guest PC 0x0c07113a */
if(!s->budget--) { s->failed_pc=0x0c07113au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07113c;
P_0c07113c: /* original 000b, guest PC 0x0c07113c */
if(!s->budget--) { s->failed_pc=0x0c07113cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07113e: /* original 6ef6, guest PC 0x0c07113e */
if(!s->budget--) { s->failed_pc=0x0c07113eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c071140u,s,ram);
P_0c071c0a: /* original f40b, guest PC 0x0c071c0a */
if(!s->budget--) { s->failed_pc=0x0c071c0au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071c0c;
P_0c071c0c: /* original 1fe1, guest PC 0x0c071c0c */
if(!s->budget--) { s->failed_pc=0x0c071c0cu; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c071c0e;
P_0c071c0e: /* original 6eb3, guest PC 0x0c071c0e */
if(!s->budget--) { s->failed_pc=0x0c071c0eu; return 0; }
r[14]=r[11];
goto P_0c071c10;
P_0c071c10: /* original 63f2, guest PC 0x0c071c10 */
if(!s->budget--) { s->failed_pc=0x0c071c10u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071c12;
P_0c071c12: /* original 7b18, guest PC 0x0c071c12 */
if(!s->budget--) { s->failed_pc=0x0c071c12u; return 0; }
r[11]+=0x00000018u;
goto P_0c071c14;
P_0c071c14: /* original 7818, guest PC 0x0c071c14 */
if(!s->budget--) { s->failed_pc=0x0c071c14u; return 0; }
r[8]+=0x00000018u;
goto P_0c071c16;
P_0c071c16: /* original 7318, guest PC 0x0c071c16 */
if(!s->budget--) { s->failed_pc=0x0c071c16u; return 0; }
r[3]+=0x00000018u;
goto P_0c071c18;
P_0c071c18: /* original 2f32, guest PC 0x0c071c18 */
if(!s->budget--) { s->failed_pc=0x0c071c18u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c071c1a;
P_0c071c1a: /* original 52f2, guest PC 0x0c071c1a */
if(!s->budget--) { s->failed_pc=0x0c071c1au; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c071c1c;
P_0c071c1c: /* original 72ff, guest PC 0x0c071c1c */
if(!s->budget--) { s->failed_pc=0x0c071c1cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c071c1e;
P_0c071c1e: /* original 3297, guest PC 0x0c071c1e */
if(!s->budget--) { s->failed_pc=0x0c071c1eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[9])!=0);
goto P_0c071c20;
P_0c071c20: /* original 8f03, guest PC 0x0c071c20 */
if(!s->budget--) { s->failed_pc=0x0c071c20u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(!cond) { goto P_0c071c2a; }
goto P_0c071c24;
P_0c071c22: /* original 1f22, guest PC 0x0c071c22 */
if(!s->budget--) { s->failed_pc=0x0c071c22u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c071c24;
P_0c071c24: /* original d103, guest PC 0x0c071c24 */
if(!s->budget--) { s->failed_pc=0x0c071c24u; return 0; }
r[1]=read(ram,0x0c071c34u,4);
goto P_0c071c26;
P_0c071c26: /* original 412b, guest PC 0x0c071c26 */
if(!s->budget--) { s->failed_pc=0x0c071c26u; return 0; }
target=r[1];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071c28: /* original 0009, guest PC 0x0c071c28 */
if(!s->budget--) { s->failed_pc=0x0c071c28u; return 0; }
goto P_0c071c2a;
P_0c071c2a: /* original 55f1, guest PC 0x0c071c2a */
if(!s->budget--) { s->failed_pc=0x0c071c2au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c071c2c;
P_0c071c2c: /* original 64d3, guest PC 0x0c071c2c */
if(!s->budget--) { s->failed_pc=0x0c071c2cu; return 0; }
r[4]=r[13];
goto P_0c071c2e;
P_0c071c2e: /* original 66e3, guest PC 0x0c071c2e */
if(!s->budget--) { s->failed_pc=0x0c071c2eu; return 0; }
r[6]=r[14];
goto P_0c071c30;
P_0c071c30: /* original a002, guest PC 0x0c071c30 */
if(!s->budget--) { s->failed_pc=0x0c071c30u; return 0; }
goto P_0c071c38;
P_0c071c32: /* original 0009, guest PC 0x0c071c32 */
if(!s->budget--) { s->failed_pc=0x0c071c32u; return 0; }
return vf3_matrix_family(0x0c071c34u,s,ram);
P_0c071c38: /* original f059, guest PC 0x0c071c38 */
if(!s->budget--) { s->failed_pc=0x0c071c38u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c3a;
P_0c071c3a: /* original f369, guest PC 0x0c071c3a */
if(!s->budget--) { s->failed_pc=0x0c071c3au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c3c;
P_0c071c3c: /* original f159, guest PC 0x0c071c3c */
if(!s->budget--) { s->failed_pc=0x0c071c3cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c3e;
P_0c071c3e: /* original f469, guest PC 0x0c071c3e */
if(!s->budget--) { s->failed_pc=0x0c071c3eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c40;
P_0c071c40: /* original f031, guest PC 0x0c071c40 */
if(!s->budget--) { s->failed_pc=0x0c071c40u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071c42;
P_0c071c42: /* original f258, guest PC 0x0c071c42 */
if(!s->budget--) { s->failed_pc=0x0c071c42u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071c44;
P_0c071c44: /* original f568, guest PC 0x0c071c44 */
if(!s->budget--) { s->failed_pc=0x0c071c44u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071c46;
P_0c071c46: /* original f141, guest PC 0x0c071c46 */
if(!s->budget--) { s->failed_pc=0x0c071c46u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071c48;
P_0c071c48: /* original f251, guest PC 0x0c071c48 */
if(!s->budget--) { s->failed_pc=0x0c071c48u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071c4a;
P_0c071c4a: /* original 7408, guest PC 0x0c071c4a */
if(!s->budget--) { s->failed_pc=0x0c071c4au; return 0; }
r[4]+=0x00000008u;
goto P_0c071c4c;
P_0c071c4c: /* original f42a, guest PC 0x0c071c4c */
if(!s->budget--) { s->failed_pc=0x0c071c4cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071c4e;
P_0c071c4e: /* original f41b, guest PC 0x0c071c4e */
if(!s->budget--) { s->failed_pc=0x0c071c4eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071c50;
P_0c071c50: /* original f40b, guest PC 0x0c071c50 */
if(!s->budget--) { s->failed_pc=0x0c071c50u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071c52;
P_0c071c52: /* original 0009, guest PC 0x0c071c52 */
if(!s->budget--) { s->failed_pc=0x0c071c52u; return 0; }
goto P_0c071c54;
P_0c071c54: /* original 65f2, guest PC 0x0c071c54 */
if(!s->budget--) { s->failed_pc=0x0c071c54u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071c56;
P_0c071c56: /* original 64a3, guest PC 0x0c071c56 */
if(!s->budget--) { s->failed_pc=0x0c071c56u; return 0; }
r[4]=r[10];
goto P_0c071c58;
P_0c071c58: /* original 66e3, guest PC 0x0c071c58 */
if(!s->budget--) { s->failed_pc=0x0c071c58u; return 0; }
r[6]=r[14];
goto P_0c071c5a;
P_0c071c5a: /* original f059, guest PC 0x0c071c5a */
if(!s->budget--) { s->failed_pc=0x0c071c5au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c5c;
P_0c071c5c: /* original f369, guest PC 0x0c071c5c */
if(!s->budget--) { s->failed_pc=0x0c071c5cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c5e;
P_0c071c5e: /* original f159, guest PC 0x0c071c5e */
if(!s->budget--) { s->failed_pc=0x0c071c5eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c60;
P_0c071c60: /* original f469, guest PC 0x0c071c60 */
if(!s->budget--) { s->failed_pc=0x0c071c60u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c62;
P_0c071c62: /* original f031, guest PC 0x0c071c62 */
if(!s->budget--) { s->failed_pc=0x0c071c62u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071c64;
P_0c071c64: /* original f258, guest PC 0x0c071c64 */
if(!s->budget--) { s->failed_pc=0x0c071c64u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071c66;
P_0c071c66: /* original f568, guest PC 0x0c071c66 */
if(!s->budget--) { s->failed_pc=0x0c071c66u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071c68;
P_0c071c68: /* original f141, guest PC 0x0c071c68 */
if(!s->budget--) { s->failed_pc=0x0c071c68u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071c6a;
P_0c071c6a: /* original f251, guest PC 0x0c071c6a */
if(!s->budget--) { s->failed_pc=0x0c071c6au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071c6c;
P_0c071c6c: /* original 7408, guest PC 0x0c071c6c */
if(!s->budget--) { s->failed_pc=0x0c071c6cu; return 0; }
r[4]+=0x00000008u;
goto P_0c071c6e;
P_0c071c6e: /* original f42a, guest PC 0x0c071c6e */
if(!s->budget--) { s->failed_pc=0x0c071c6eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071c70;
P_0c071c70: /* original f41b, guest PC 0x0c071c70 */
if(!s->budget--) { s->failed_pc=0x0c071c70u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071c72;
P_0c071c72: /* original f40b, guest PC 0x0c071c72 */
if(!s->budget--) { s->failed_pc=0x0c071c72u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071c74;
P_0c071c74: /* original 64c3, guest PC 0x0c071c74 */
if(!s->budget--) { s->failed_pc=0x0c071c74u; return 0; }
r[4]=r[12];
goto P_0c071c76;
P_0c071c76: /* original 6583, guest PC 0x0c071c76 */
if(!s->budget--) { s->failed_pc=0x0c071c76u; return 0; }
r[5]=r[8];
goto P_0c071c78;
P_0c071c78: /* original 66e3, guest PC 0x0c071c78 */
if(!s->budget--) { s->failed_pc=0x0c071c78u; return 0; }
r[6]=r[14];
goto P_0c071c7a;
P_0c071c7a: /* original f059, guest PC 0x0c071c7a */
if(!s->budget--) { s->failed_pc=0x0c071c7au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c7c;
P_0c071c7c: /* original f369, guest PC 0x0c071c7c */
if(!s->budget--) { s->failed_pc=0x0c071c7cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c7e;
P_0c071c7e: /* original f159, guest PC 0x0c071c7e */
if(!s->budget--) { s->failed_pc=0x0c071c7eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071c80;
P_0c071c80: /* original f469, guest PC 0x0c071c80 */
if(!s->budget--) { s->failed_pc=0x0c071c80u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071c82;
P_0c071c82: /* original f031, guest PC 0x0c071c82 */
if(!s->budget--) { s->failed_pc=0x0c071c82u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071c84;
P_0c071c84: /* original f258, guest PC 0x0c071c84 */
if(!s->budget--) { s->failed_pc=0x0c071c84u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071c86;
P_0c071c86: /* original f568, guest PC 0x0c071c86 */
if(!s->budget--) { s->failed_pc=0x0c071c86u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071c88;
P_0c071c88: /* original f141, guest PC 0x0c071c88 */
if(!s->budget--) { s->failed_pc=0x0c071c88u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071c8a;
P_0c071c8a: /* original f251, guest PC 0x0c071c8a */
if(!s->budget--) { s->failed_pc=0x0c071c8au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071c8c;
P_0c071c8c: /* original 7408, guest PC 0x0c071c8c */
if(!s->budget--) { s->failed_pc=0x0c071c8cu; return 0; }
r[4]+=0x00000008u;
goto P_0c071c8e;
P_0c071c8e: /* original f42a, guest PC 0x0c071c8e */
if(!s->budget--) { s->failed_pc=0x0c071c8eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071c90;
P_0c071c90: /* original f41b, guest PC 0x0c071c90 */
if(!s->budget--) { s->failed_pc=0x0c071c90u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071c92;
P_0c071c92: /* original f40b, guest PC 0x0c071c92 */
if(!s->budget--) { s->failed_pc=0x0c071c92u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071c94;
P_0c071c94: /* original 66f3, guest PC 0x0c071c94 */
if(!s->budget--) { s->failed_pc=0x0c071c94u; return 0; }
r[6]=r[15];
goto P_0c071c96;
P_0c071c96: /* original 64d3, guest PC 0x0c071c96 */
if(!s->budget--) { s->failed_pc=0x0c071c96u; return 0; }
r[4]=r[13];
goto P_0c071c98;
P_0c071c98: /* original 65c3, guest PC 0x0c071c98 */
if(!s->budget--) { s->failed_pc=0x0c071c98u; return 0; }
r[5]=r[12];
goto P_0c071c9a;
P_0c071c9a: /* original 7624, guest PC 0x0c071c9a */
if(!s->budget--) { s->failed_pc=0x0c071c9au; return 0; }
r[6]+=0x00000024u;
goto P_0c071c9c;
P_0c071c9c: /* original f049, guest PC 0x0c071c9c */
if(!s->budget--) { s->failed_pc=0x0c071c9cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071c9e;
P_0c071c9e: /* original f549, guest PC 0x0c071c9e */
if(!s->budget--) { s->failed_pc=0x0c071c9eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071ca0;
P_0c071ca0: /* original f648, guest PC 0x0c071ca0 */
if(!s->budget--) { s->failed_pc=0x0c071ca0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071ca2;
P_0c071ca2: /* original f859, guest PC 0x0c071ca2 */
if(!s->budget--) { s->failed_pc=0x0c071ca2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ca4;
P_0c071ca4: /* original f959, guest PC 0x0c071ca4 */
if(!s->budget--) { s->failed_pc=0x0c071ca4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ca6;
P_0c071ca6: /* original fa58, guest PC 0x0c071ca6 */
if(!s->budget--) { s->failed_pc=0x0c071ca6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071ca8;
P_0c071ca8: /* original 760c, guest PC 0x0c071ca8 */
if(!s->budget--) { s->failed_pc=0x0c071ca8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071caa;
P_0c071caa: /* original f35c, guest PC 0x0c071caa */
if(!s->budget--) { s->failed_pc=0x0c071caau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071cac;
P_0c071cac: /* original f382, guest PC 0x0c071cac */
if(!s->budget--) { s->failed_pc=0x0c071cacu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071cae;
P_0c071cae: /* original f20c, guest PC 0x0c071cae */
if(!s->budget--) { s->failed_pc=0x0c071caeu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071cb0;
P_0c071cb0: /* original f2a2, guest PC 0x0c071cb0 */
if(!s->budget--) { s->failed_pc=0x0c071cb0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071cb2;
P_0c071cb2: /* original f16c, guest PC 0x0c071cb2 */
if(!s->budget--) { s->failed_pc=0x0c071cb2u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071cb4;
P_0c071cb4: /* original f192, guest PC 0x0c071cb4 */
if(!s->budget--) { s->failed_pc=0x0c071cb4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071cb6;
P_0c071cb6: /* original f34d, guest PC 0x0c071cb6 */
if(!s->budget--) { s->failed_pc=0x0c071cb6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071cb8;
P_0c071cb8: /* original f39e, guest PC 0x0c071cb8 */
if(!s->budget--) { s->failed_pc=0x0c071cb8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071cba;
P_0c071cba: /* original f24d, guest PC 0x0c071cba */
if(!s->budget--) { s->failed_pc=0x0c071cbau; return 0; }
fr[2]^=0x80000000u;
goto P_0c071cbc;
P_0c071cbc: /* original f06c, guest PC 0x0c071cbc */
if(!s->budget--) { s->failed_pc=0x0c071cbcu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071cbe;
P_0c071cbe: /* original f28e, guest PC 0x0c071cbe */
if(!s->budget--) { s->failed_pc=0x0c071cbeu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071cc0;
P_0c071cc0: /* original f14d, guest PC 0x0c071cc0 */
if(!s->budget--) { s->failed_pc=0x0c071cc0u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071cc2;
P_0c071cc2: /* original f63b, guest PC 0x0c071cc2 */
if(!s->budget--) { s->failed_pc=0x0c071cc2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071cc4;
P_0c071cc4: /* original f05c, guest PC 0x0c071cc4 */
if(!s->budget--) { s->failed_pc=0x0c071cc4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071cc6;
P_0c071cc6: /* original f1ae, guest PC 0x0c071cc6 */
if(!s->budget--) { s->failed_pc=0x0c071cc6u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071cc8;
P_0c071cc8: /* original f62b, guest PC 0x0c071cc8 */
if(!s->budget--) { s->failed_pc=0x0c071cc8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071cca;
P_0c071cca: /* original f61b, guest PC 0x0c071cca */
if(!s->budget--) { s->failed_pc=0x0c071ccau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071ccc;
P_0c071ccc: /* original 66f3, guest PC 0x0c071ccc */
if(!s->budget--) { s->failed_pc=0x0c071cccu; return 0; }
r[6]=r[15];
goto P_0c071cce;
P_0c071cce: /* original 64a3, guest PC 0x0c071cce */
if(!s->budget--) { s->failed_pc=0x0c071cceu; return 0; }
r[4]=r[10];
goto P_0c071cd0;
P_0c071cd0: /* original 65d3, guest PC 0x0c071cd0 */
if(!s->budget--) { s->failed_pc=0x0c071cd0u; return 0; }
r[5]=r[13];
goto P_0c071cd2;
P_0c071cd2: /* original 7618, guest PC 0x0c071cd2 */
if(!s->budget--) { s->failed_pc=0x0c071cd2u; return 0; }
r[6]+=0x00000018u;
goto P_0c071cd4;
P_0c071cd4: /* original f049, guest PC 0x0c071cd4 */
if(!s->budget--) { s->failed_pc=0x0c071cd4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071cd6;
P_0c071cd6: /* original f549, guest PC 0x0c071cd6 */
if(!s->budget--) { s->failed_pc=0x0c071cd6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071cd8;
P_0c071cd8: /* original f648, guest PC 0x0c071cd8 */
if(!s->budget--) { s->failed_pc=0x0c071cd8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071cda;
P_0c071cda: /* original f859, guest PC 0x0c071cda */
if(!s->budget--) { s->failed_pc=0x0c071cdau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071cdc;
P_0c071cdc: /* original f959, guest PC 0x0c071cdc */
if(!s->budget--) { s->failed_pc=0x0c071cdcu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071cde;
P_0c071cde: /* original fa58, guest PC 0x0c071cde */
if(!s->budget--) { s->failed_pc=0x0c071cdeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071ce0;
P_0c071ce0: /* original 760c, guest PC 0x0c071ce0 */
if(!s->budget--) { s->failed_pc=0x0c071ce0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071ce2;
P_0c071ce2: /* original f35c, guest PC 0x0c071ce2 */
if(!s->budget--) { s->failed_pc=0x0c071ce2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071ce4;
P_0c071ce4: /* original f382, guest PC 0x0c071ce4 */
if(!s->budget--) { s->failed_pc=0x0c071ce4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071ce6;
P_0c071ce6: /* original f20c, guest PC 0x0c071ce6 */
if(!s->budget--) { s->failed_pc=0x0c071ce6u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071ce8;
P_0c071ce8: /* original f2a2, guest PC 0x0c071ce8 */
if(!s->budget--) { s->failed_pc=0x0c071ce8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071cea;
P_0c071cea: /* original f16c, guest PC 0x0c071cea */
if(!s->budget--) { s->failed_pc=0x0c071ceau; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071cec;
P_0c071cec: /* original f192, guest PC 0x0c071cec */
if(!s->budget--) { s->failed_pc=0x0c071cecu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071cee;
P_0c071cee: /* original f34d, guest PC 0x0c071cee */
if(!s->budget--) { s->failed_pc=0x0c071ceeu; return 0; }
fr[3]^=0x80000000u;
goto P_0c071cf0;
P_0c071cf0: /* original f39e, guest PC 0x0c071cf0 */
if(!s->budget--) { s->failed_pc=0x0c071cf0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071cf2;
P_0c071cf2: /* original f24d, guest PC 0x0c071cf2 */
if(!s->budget--) { s->failed_pc=0x0c071cf2u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071cf4;
P_0c071cf4: /* original f06c, guest PC 0x0c071cf4 */
if(!s->budget--) { s->failed_pc=0x0c071cf4u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071cf6;
P_0c071cf6: /* original f28e, guest PC 0x0c071cf6 */
if(!s->budget--) { s->failed_pc=0x0c071cf6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071cf8;
P_0c071cf8: /* original f14d, guest PC 0x0c071cf8 */
if(!s->budget--) { s->failed_pc=0x0c071cf8u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071cfa;
P_0c071cfa: /* original f63b, guest PC 0x0c071cfa */
if(!s->budget--) { s->failed_pc=0x0c071cfau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071cfc;
P_0c071cfc: /* original f05c, guest PC 0x0c071cfc */
if(!s->budget--) { s->failed_pc=0x0c071cfcu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071cfe;
P_0c071cfe: /* original f1ae, guest PC 0x0c071cfe */
if(!s->budget--) { s->failed_pc=0x0c071cfeu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071d00;
P_0c071d00: /* original f62b, guest PC 0x0c071d00 */
if(!s->budget--) { s->failed_pc=0x0c071d00u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071d02;
P_0c071d02: /* original f61b, guest PC 0x0c071d02 */
if(!s->budget--) { s->failed_pc=0x0c071d02u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071d04;
P_0c071d04: /* original 64f3, guest PC 0x0c071d04 */
if(!s->budget--) { s->failed_pc=0x0c071d04u; return 0; }
r[4]=r[15];
goto P_0c071d06;
P_0c071d06: /* original 7424, guest PC 0x0c071d06 */
if(!s->budget--) { s->failed_pc=0x0c071d06u; return 0; }
r[4]+=0x00000024u;
goto P_0c071d08;
P_0c071d08: /* original f049, guest PC 0x0c071d08 */
if(!s->budget--) { s->failed_pc=0x0c071d08u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d0a;
P_0c071d0a: /* original f149, guest PC 0x0c071d0a */
if(!s->budget--) { s->failed_pc=0x0c071d0au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d0c;
P_0c071d0c: /* original f249, guest PC 0x0c071d0c */
if(!s->budget--) { s->failed_pc=0x0c071d0cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d0e;
P_0c071d0e: /* original f38d, guest PC 0x0c071d0e */
if(!s->budget--) { s->failed_pc=0x0c071d0eu; return 0; }
fr[3]=0;
goto P_0c071d10;
P_0c071d10: /* original f0ed, guest PC 0x0c071d10 */
if(!s->budget--) { s->failed_pc=0x0c071d10u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071d12;
P_0c071d12: /* original f37d, guest PC 0x0c071d12 */
if(!s->budget--) { s->failed_pc=0x0c071d12u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071d14;
P_0c071d14: /* original f232, guest PC 0x0c071d14 */
if(!s->budget--) { s->failed_pc=0x0c071d14u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071d16;
P_0c071d16: /* original f132, guest PC 0x0c071d16 */
if(!s->budget--) { s->failed_pc=0x0c071d16u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071d18;
P_0c071d18: /* original f032, guest PC 0x0c071d18 */
if(!s->budget--) { s->failed_pc=0x0c071d18u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071d1a;
P_0c071d1a: /* original f42b, guest PC 0x0c071d1a */
if(!s->budget--) { s->failed_pc=0x0c071d1au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071d1c;
P_0c071d1c: /* original f41b, guest PC 0x0c071d1c */
if(!s->budget--) { s->failed_pc=0x0c071d1cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071d1e;
P_0c071d1e: /* original f40b, guest PC 0x0c071d1e */
if(!s->budget--) { s->failed_pc=0x0c071d1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071d20;
P_0c071d20: /* original 64f3, guest PC 0x0c071d20 */
if(!s->budget--) { s->failed_pc=0x0c071d20u; return 0; }
r[4]=r[15];
goto P_0c071d22;
P_0c071d22: /* original 7418, guest PC 0x0c071d22 */
if(!s->budget--) { s->failed_pc=0x0c071d22u; return 0; }
r[4]+=0x00000018u;
goto P_0c071d24;
P_0c071d24: /* original f049, guest PC 0x0c071d24 */
if(!s->budget--) { s->failed_pc=0x0c071d24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d26;
P_0c071d26: /* original f149, guest PC 0x0c071d26 */
if(!s->budget--) { s->failed_pc=0x0c071d26u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d28;
P_0c071d28: /* original f249, guest PC 0x0c071d28 */
if(!s->budget--) { s->failed_pc=0x0c071d28u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d2a;
P_0c071d2a: /* original f38d, guest PC 0x0c071d2a */
if(!s->budget--) { s->failed_pc=0x0c071d2au; return 0; }
fr[3]=0;
goto P_0c071d2c;
P_0c071d2c: /* original f0ed, guest PC 0x0c071d2c */
if(!s->budget--) { s->failed_pc=0x0c071d2cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071d2e;
P_0c071d2e: /* original f37d, guest PC 0x0c071d2e */
if(!s->budget--) { s->failed_pc=0x0c071d2eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071d30;
P_0c071d30: /* original f232, guest PC 0x0c071d30 */
if(!s->budget--) { s->failed_pc=0x0c071d30u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071d32;
P_0c071d32: /* original f132, guest PC 0x0c071d32 */
if(!s->budget--) { s->failed_pc=0x0c071d32u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071d34;
P_0c071d34: /* original f032, guest PC 0x0c071d34 */
if(!s->budget--) { s->failed_pc=0x0c071d34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071d36;
P_0c071d36: /* original f42b, guest PC 0x0c071d36 */
if(!s->budget--) { s->failed_pc=0x0c071d36u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071d38;
P_0c071d38: /* original f41b, guest PC 0x0c071d38 */
if(!s->budget--) { s->failed_pc=0x0c071d38u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071d3a;
P_0c071d3a: /* original f40b, guest PC 0x0c071d3a */
if(!s->budget--) { s->failed_pc=0x0c071d3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071d3c;
P_0c071d3c: /* original 65f3, guest PC 0x0c071d3c */
if(!s->budget--) { s->failed_pc=0x0c071d3cu; return 0; }
r[5]=r[15];
goto P_0c071d3e;
P_0c071d3e: /* original 64e3, guest PC 0x0c071d3e */
if(!s->budget--) { s->failed_pc=0x0c071d3eu; return 0; }
r[4]=r[14];
goto P_0c071d40;
P_0c071d40: /* original 66f3, guest PC 0x0c071d40 */
if(!s->budget--) { s->failed_pc=0x0c071d40u; return 0; }
r[6]=r[15];
goto P_0c071d42;
P_0c071d42: /* original 740c, guest PC 0x0c071d42 */
if(!s->budget--) { s->failed_pc=0x0c071d42u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071d44;
P_0c071d44: /* original 7618, guest PC 0x0c071d44 */
if(!s->budget--) { s->failed_pc=0x0c071d44u; return 0; }
r[6]+=0x00000018u;
goto P_0c071d46;
P_0c071d46: /* original 7524, guest PC 0x0c071d46 */
if(!s->budget--) { s->failed_pc=0x0c071d46u; return 0; }
r[5]+=0x00000024u;
goto P_0c071d48;
P_0c071d48: /* original f059, guest PC 0x0c071d48 */
if(!s->budget--) { s->failed_pc=0x0c071d48u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071d4a;
P_0c071d4a: /* original f369, guest PC 0x0c071d4a */
if(!s->budget--) { s->failed_pc=0x0c071d4au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071d4c;
P_0c071d4c: /* original f159, guest PC 0x0c071d4c */
if(!s->budget--) { s->failed_pc=0x0c071d4cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071d4e;
P_0c071d4e: /* original f469, guest PC 0x0c071d4e */
if(!s->budget--) { s->failed_pc=0x0c071d4eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071d50;
P_0c071d50: /* original f259, guest PC 0x0c071d50 */
if(!s->budget--) { s->failed_pc=0x0c071d50u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071d52;
P_0c071d52: /* original f569, guest PC 0x0c071d52 */
if(!s->budget--) { s->failed_pc=0x0c071d52u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071d54;
P_0c071d54: /* original 740c, guest PC 0x0c071d54 */
if(!s->budget--) { s->failed_pc=0x0c071d54u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071d56;
P_0c071d56: /* original f030, guest PC 0x0c071d56 */
if(!s->budget--) { s->failed_pc=0x0c071d56u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071d58;
P_0c071d58: /* original f250, guest PC 0x0c071d58 */
if(!s->budget--) { s->failed_pc=0x0c071d58u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071d5a;
P_0c071d5a: /* original f140, guest PC 0x0c071d5a */
if(!s->budget--) { s->failed_pc=0x0c071d5au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071d5c;
P_0c071d5c: /* original f42b, guest PC 0x0c071d5c */
if(!s->budget--) { s->failed_pc=0x0c071d5cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071d5e;
P_0c071d5e: /* original f41b, guest PC 0x0c071d5e */
if(!s->budget--) { s->failed_pc=0x0c071d5eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071d60;
P_0c071d60: /* original f40b, guest PC 0x0c071d60 */
if(!s->budget--) { s->failed_pc=0x0c071d60u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071d62;
P_0c071d62: /* original 0009, guest PC 0x0c071d62 */
if(!s->budget--) { s->failed_pc=0x0c071d62u; return 0; }
goto P_0c071d64;
P_0c071d64: /* original 64e3, guest PC 0x0c071d64 */
if(!s->budget--) { s->failed_pc=0x0c071d64u; return 0; }
r[4]=r[14];
goto P_0c071d66;
P_0c071d66: /* original 740c, guest PC 0x0c071d66 */
if(!s->budget--) { s->failed_pc=0x0c071d66u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071d68;
P_0c071d68: /* original f049, guest PC 0x0c071d68 */
if(!s->budget--) { s->failed_pc=0x0c071d68u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d6a;
P_0c071d6a: /* original f149, guest PC 0x0c071d6a */
if(!s->budget--) { s->failed_pc=0x0c071d6au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d6c;
P_0c071d6c: /* original f249, guest PC 0x0c071d6c */
if(!s->budget--) { s->failed_pc=0x0c071d6cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071d6e;
P_0c071d6e: /* original f38d, guest PC 0x0c071d6e */
if(!s->budget--) { s->failed_pc=0x0c071d6eu; return 0; }
fr[3]=0;
goto P_0c071d70;
P_0c071d70: /* original f0ed, guest PC 0x0c071d70 */
if(!s->budget--) { s->failed_pc=0x0c071d70u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071d72;
P_0c071d72: /* original f37d, guest PC 0x0c071d72 */
if(!s->budget--) { s->failed_pc=0x0c071d72u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071d74;
P_0c071d74: /* original f232, guest PC 0x0c071d74 */
if(!s->budget--) { s->failed_pc=0x0c071d74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071d76;
P_0c071d76: /* original f132, guest PC 0x0c071d76 */
if(!s->budget--) { s->failed_pc=0x0c071d76u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071d78;
P_0c071d78: /* original f032, guest PC 0x0c071d78 */
if(!s->budget--) { s->failed_pc=0x0c071d78u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071d7a;
P_0c071d7a: /* original f42b, guest PC 0x0c071d7a */
if(!s->budget--) { s->failed_pc=0x0c071d7au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071d7c;
P_0c071d7c: /* original f41b, guest PC 0x0c071d7c */
if(!s->budget--) { s->failed_pc=0x0c071d7cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071d7e;
P_0c071d7e: /* original f40b, guest PC 0x0c071d7e */
if(!s->budget--) { s->failed_pc=0x0c071d7eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071d80;
P_0c071d80: /* original 63f2, guest PC 0x0c071d80 */
if(!s->budget--) { s->failed_pc=0x0c071d80u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071d82;
P_0c071d82: /* original 6eb3, guest PC 0x0c071d82 */
if(!s->budget--) { s->failed_pc=0x0c071d82u; return 0; }
r[14]=r[11];
goto P_0c071d84;
P_0c071d84: /* original 7b18, guest PC 0x0c071d84 */
if(!s->budget--) { s->failed_pc=0x0c071d84u; return 0; }
r[11]+=0x00000018u;
goto P_0c071d86;
P_0c071d86: /* original 7318, guest PC 0x0c071d86 */
if(!s->budget--) { s->failed_pc=0x0c071d86u; return 0; }
r[3]+=0x00000018u;
goto P_0c071d88;
P_0c071d88: /* original 2f32, guest PC 0x0c071d88 */
if(!s->budget--) { s->failed_pc=0x0c071d88u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c071d8a;
P_0c071d8a: /* original 7818, guest PC 0x0c071d8a */
if(!s->budget--) { s->failed_pc=0x0c071d8au; return 0; }
r[8]+=0x00000018u;
goto P_0c071d8c;
P_0c071d8c: /* original 52f4, guest PC 0x0c071d8c */
if(!s->budget--) { s->failed_pc=0x0c071d8cu; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c071d8e;
P_0c071d8e: /* original 72ff, guest PC 0x0c071d8e */
if(!s->budget--) { s->failed_pc=0x0c071d8eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c071d90;
P_0c071d90: /* original 1f24, guest PC 0x0c071d90 */
if(!s->budget--) { s->failed_pc=0x0c071d90u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c071d92;
P_0c071d92: /* original 53f4, guest PC 0x0c071d92 */
if(!s->budget--) { s->failed_pc=0x0c071d92u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c071d94;
P_0c071d94: /* original 3397, guest PC 0x0c071d94 */
if(!s->budget--) { s->failed_pc=0x0c071d94u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[9])!=0);
goto P_0c071d96;
P_0c071d96: /* original 8b02, guest PC 0x0c071d96 */
if(!s->budget--) { s->failed_pc=0x0c071d96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c071d9e; }
goto P_0c071d98;
P_0c071d98: /* original d203, guest PC 0x0c071d98 */
if(!s->budget--) { s->failed_pc=0x0c071d98u; return 0; }
r[2]=read(ram,0x0c071da8u,4);
goto P_0c071d9a;
P_0c071d9a: /* original 422b, guest PC 0x0c071d9a */
if(!s->budget--) { s->failed_pc=0x0c071d9au; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071d9c: /* original 0009, guest PC 0x0c071d9c */
if(!s->budget--) { s->failed_pc=0x0c071d9cu; return 0; }
goto P_0c071d9e;
P_0c071d9e: /* original 64d3, guest PC 0x0c071d9e */
if(!s->budget--) { s->failed_pc=0x0c071d9eu; return 0; }
r[4]=r[13];
goto P_0c071da0;
P_0c071da0: /* original 65b3, guest PC 0x0c071da0 */
if(!s->budget--) { s->failed_pc=0x0c071da0u; return 0; }
r[5]=r[11];
goto P_0c071da2;
P_0c071da2: /* original 66e3, guest PC 0x0c071da2 */
if(!s->budget--) { s->failed_pc=0x0c071da2u; return 0; }
r[6]=r[14];
goto P_0c071da4;
P_0c071da4: /* original a002, guest PC 0x0c071da4 */
if(!s->budget--) { s->failed_pc=0x0c071da4u; return 0; }
goto P_0c071dac;
P_0c071da6: /* original 0009, guest PC 0x0c071da6 */
if(!s->budget--) { s->failed_pc=0x0c071da6u; return 0; }
return vf3_matrix_family(0x0c071da8u,s,ram);
P_0c071dac: /* original f059, guest PC 0x0c071dac */
if(!s->budget--) { s->failed_pc=0x0c071dacu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dae;
P_0c071dae: /* original f369, guest PC 0x0c071dae */
if(!s->budget--) { s->failed_pc=0x0c071daeu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071db0;
P_0c071db0: /* original f159, guest PC 0x0c071db0 */
if(!s->budget--) { s->failed_pc=0x0c071db0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071db2;
P_0c071db2: /* original f469, guest PC 0x0c071db2 */
if(!s->budget--) { s->failed_pc=0x0c071db2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071db4;
P_0c071db4: /* original f031, guest PC 0x0c071db4 */
if(!s->budget--) { s->failed_pc=0x0c071db4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071db6;
P_0c071db6: /* original f258, guest PC 0x0c071db6 */
if(!s->budget--) { s->failed_pc=0x0c071db6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071db8;
P_0c071db8: /* original f568, guest PC 0x0c071db8 */
if(!s->budget--) { s->failed_pc=0x0c071db8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071dba;
P_0c071dba: /* original f141, guest PC 0x0c071dba */
if(!s->budget--) { s->failed_pc=0x0c071dbau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071dbc;
P_0c071dbc: /* original f251, guest PC 0x0c071dbc */
if(!s->budget--) { s->failed_pc=0x0c071dbcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071dbe;
P_0c071dbe: /* original 7408, guest PC 0x0c071dbe */
if(!s->budget--) { s->failed_pc=0x0c071dbeu; return 0; }
r[4]+=0x00000008u;
goto P_0c071dc0;
P_0c071dc0: /* original f42a, guest PC 0x0c071dc0 */
if(!s->budget--) { s->failed_pc=0x0c071dc0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071dc2;
P_0c071dc2: /* original f41b, guest PC 0x0c071dc2 */
if(!s->budget--) { s->failed_pc=0x0c071dc2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071dc4;
P_0c071dc4: /* original f40b, guest PC 0x0c071dc4 */
if(!s->budget--) { s->failed_pc=0x0c071dc4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071dc6;
P_0c071dc6: /* original 0009, guest PC 0x0c071dc6 */
if(!s->budget--) { s->failed_pc=0x0c071dc6u; return 0; }
goto P_0c071dc8;
P_0c071dc8: /* original 64a3, guest PC 0x0c071dc8 */
if(!s->budget--) { s->failed_pc=0x0c071dc8u; return 0; }
r[4]=r[10];
goto P_0c071dca;
P_0c071dca: /* original 6583, guest PC 0x0c071dca */
if(!s->budget--) { s->failed_pc=0x0c071dcau; return 0; }
r[5]=r[8];
goto P_0c071dcc;
P_0c071dcc: /* original 66e3, guest PC 0x0c071dcc */
if(!s->budget--) { s->failed_pc=0x0c071dccu; return 0; }
r[6]=r[14];
goto P_0c071dce;
P_0c071dce: /* original f059, guest PC 0x0c071dce */
if(!s->budget--) { s->failed_pc=0x0c071dceu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd0;
P_0c071dd0: /* original f369, guest PC 0x0c071dd0 */
if(!s->budget--) { s->failed_pc=0x0c071dd0u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd2;
P_0c071dd2: /* original f159, guest PC 0x0c071dd2 */
if(!s->budget--) { s->failed_pc=0x0c071dd2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd4;
P_0c071dd4: /* original f469, guest PC 0x0c071dd4 */
if(!s->budget--) { s->failed_pc=0x0c071dd4u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd6;
P_0c071dd6: /* original f031, guest PC 0x0c071dd6 */
if(!s->budget--) { s->failed_pc=0x0c071dd6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071dd8;
P_0c071dd8: /* original f258, guest PC 0x0c071dd8 */
if(!s->budget--) { s->failed_pc=0x0c071dd8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071dda;
P_0c071dda: /* original f568, guest PC 0x0c071dda */
if(!s->budget--) { s->failed_pc=0x0c071ddau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071ddc;
P_0c071ddc: /* original f141, guest PC 0x0c071ddc */
if(!s->budget--) { s->failed_pc=0x0c071ddcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071dde;
P_0c071dde: /* original f251, guest PC 0x0c071dde */
if(!s->budget--) { s->failed_pc=0x0c071ddeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071de0;
P_0c071de0: /* original 7408, guest PC 0x0c071de0 */
if(!s->budget--) { s->failed_pc=0x0c071de0u; return 0; }
r[4]+=0x00000008u;
goto P_0c071de2;
P_0c071de2: /* original f42a, guest PC 0x0c071de2 */
if(!s->budget--) { s->failed_pc=0x0c071de2u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071de4;
P_0c071de4: /* original f41b, guest PC 0x0c071de4 */
if(!s->budget--) { s->failed_pc=0x0c071de4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071de6;
P_0c071de6: /* original f40b, guest PC 0x0c071de6 */
if(!s->budget--) { s->failed_pc=0x0c071de6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071de8;
P_0c071de8: /* original 66e3, guest PC 0x0c071de8 */
if(!s->budget--) { s->failed_pc=0x0c071de8u; return 0; }
r[6]=r[14];
goto P_0c071dea;
P_0c071dea: /* original 64a3, guest PC 0x0c071dea */
if(!s->budget--) { s->failed_pc=0x0c071deau; return 0; }
r[4]=r[10];
goto P_0c071dec;
P_0c071dec: /* original 65d3, guest PC 0x0c071dec */
if(!s->budget--) { s->failed_pc=0x0c071decu; return 0; }
r[5]=r[13];
goto P_0c071dee;
P_0c071dee: /* original 760c, guest PC 0x0c071dee */
if(!s->budget--) { s->failed_pc=0x0c071deeu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071df0;
P_0c071df0: /* original f049, guest PC 0x0c071df0 */
if(!s->budget--) { s->failed_pc=0x0c071df0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071df2;
P_0c071df2: /* original f549, guest PC 0x0c071df2 */
if(!s->budget--) { s->failed_pc=0x0c071df2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071df4;
P_0c071df4: /* original f648, guest PC 0x0c071df4 */
if(!s->budget--) { s->failed_pc=0x0c071df4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071df6;
P_0c071df6: /* original f859, guest PC 0x0c071df6 */
if(!s->budget--) { s->failed_pc=0x0c071df6u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071df8;
P_0c071df8: /* original f959, guest PC 0x0c071df8 */
if(!s->budget--) { s->failed_pc=0x0c071df8u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dfa;
P_0c071dfa: /* original fa58, guest PC 0x0c071dfa */
if(!s->budget--) { s->failed_pc=0x0c071dfau; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071dfc;
P_0c071dfc: /* original 760c, guest PC 0x0c071dfc */
if(!s->budget--) { s->failed_pc=0x0c071dfcu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071dfe;
P_0c071dfe: /* original f35c, guest PC 0x0c071dfe */
if(!s->budget--) { s->failed_pc=0x0c071dfeu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071e00;
P_0c071e00: /* original f382, guest PC 0x0c071e00 */
if(!s->budget--) { s->failed_pc=0x0c071e00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071e02;
P_0c071e02: /* original f20c, guest PC 0x0c071e02 */
if(!s->budget--) { s->failed_pc=0x0c071e02u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071e04;
P_0c071e04: /* original f2a2, guest PC 0x0c071e04 */
if(!s->budget--) { s->failed_pc=0x0c071e04u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071e06;
P_0c071e06: /* original f16c, guest PC 0x0c071e06 */
if(!s->budget--) { s->failed_pc=0x0c071e06u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071e08;
P_0c071e08: /* original f192, guest PC 0x0c071e08 */
if(!s->budget--) { s->failed_pc=0x0c071e08u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071e0a;
P_0c071e0a: /* original f34d, guest PC 0x0c071e0a */
if(!s->budget--) { s->failed_pc=0x0c071e0au; return 0; }
fr[3]^=0x80000000u;
goto P_0c071e0c;
P_0c071e0c: /* original f39e, guest PC 0x0c071e0c */
if(!s->budget--) { s->failed_pc=0x0c071e0cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071e0e;
P_0c071e0e: /* original f24d, guest PC 0x0c071e0e */
if(!s->budget--) { s->failed_pc=0x0c071e0eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c071e10;
P_0c071e10: /* original f06c, guest PC 0x0c071e10 */
if(!s->budget--) { s->failed_pc=0x0c071e10u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071e12;
P_0c071e12: /* original f28e, guest PC 0x0c071e12 */
if(!s->budget--) { s->failed_pc=0x0c071e12u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071e14;
P_0c071e14: /* original f14d, guest PC 0x0c071e14 */
if(!s->budget--) { s->failed_pc=0x0c071e14u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071e16;
P_0c071e16: /* original f63b, guest PC 0x0c071e16 */
if(!s->budget--) { s->failed_pc=0x0c071e16u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071e18;
P_0c071e18: /* original f05c, guest PC 0x0c071e18 */
if(!s->budget--) { s->failed_pc=0x0c071e18u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071e1a;
P_0c071e1a: /* original f1ae, guest PC 0x0c071e1a */
if(!s->budget--) { s->failed_pc=0x0c071e1au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071e1c;
P_0c071e1c: /* original f62b, guest PC 0x0c071e1c */
if(!s->budget--) { s->failed_pc=0x0c071e1cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071e1e;
P_0c071e1e: /* original f61b, guest PC 0x0c071e1e */
if(!s->budget--) { s->failed_pc=0x0c071e1eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071e20;
P_0c071e20: /* original 64e3, guest PC 0x0c071e20 */
if(!s->budget--) { s->failed_pc=0x0c071e20u; return 0; }
r[4]=r[14];
goto P_0c071e22;
P_0c071e22: /* original 740c, guest PC 0x0c071e22 */
if(!s->budget--) { s->failed_pc=0x0c071e22u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071e24;
P_0c071e24: /* original f049, guest PC 0x0c071e24 */
if(!s->budget--) { s->failed_pc=0x0c071e24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e26;
P_0c071e26: /* original f149, guest PC 0x0c071e26 */
if(!s->budget--) { s->failed_pc=0x0c071e26u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e28;
P_0c071e28: /* original f249, guest PC 0x0c071e28 */
if(!s->budget--) { s->failed_pc=0x0c071e28u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e2a;
P_0c071e2a: /* original f38d, guest PC 0x0c071e2a */
if(!s->budget--) { s->failed_pc=0x0c071e2au; return 0; }
fr[3]=0;
goto P_0c071e2c;
P_0c071e2c: /* original f0ed, guest PC 0x0c071e2c */
if(!s->budget--) { s->failed_pc=0x0c071e2cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071e2e;
P_0c071e2e: /* original f37d, guest PC 0x0c071e2e */
if(!s->budget--) { s->failed_pc=0x0c071e2eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071e30;
P_0c071e30: /* original f232, guest PC 0x0c071e30 */
if(!s->budget--) { s->failed_pc=0x0c071e30u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071e32;
P_0c071e32: /* original f132, guest PC 0x0c071e32 */
if(!s->budget--) { s->failed_pc=0x0c071e32u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071e34;
P_0c071e34: /* original f032, guest PC 0x0c071e34 */
if(!s->budget--) { s->failed_pc=0x0c071e34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071e36;
P_0c071e36: /* original f42b, guest PC 0x0c071e36 */
if(!s->budget--) { s->failed_pc=0x0c071e36u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e38;
P_0c071e38: /* original f41b, guest PC 0x0c071e38 */
if(!s->budget--) { s->failed_pc=0x0c071e38u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e3a;
P_0c071e3a: /* original f40b, guest PC 0x0c071e3a */
if(!s->budget--) { s->failed_pc=0x0c071e3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071e3c;
P_0c071e3c: /* original 2fe2, guest PC 0x0c071e3c */
if(!s->budget--) { s->failed_pc=0x0c071e3cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c071e3e;
P_0c071e3e: /* original 6eb3, guest PC 0x0c071e3e */
if(!s->budget--) { s->failed_pc=0x0c071e3eu; return 0; }
r[14]=r[11];
goto P_0c071e40;
P_0c071e40: /* original 53f5, guest PC 0x0c071e40 */
if(!s->budget--) { s->failed_pc=0x0c071e40u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c071e42;
P_0c071e42: /* original 7b18, guest PC 0x0c071e42 */
if(!s->budget--) { s->failed_pc=0x0c071e42u; return 0; }
r[11]+=0x00000018u;
goto P_0c071e44;
P_0c071e44: /* original 6233, guest PC 0x0c071e44 */
if(!s->budget--) { s->failed_pc=0x0c071e44u; return 0; }
r[2]=r[3];
goto P_0c071e46;
P_0c071e46: /* original 3297, guest PC 0x0c071e46 */
if(!s->budget--) { s->failed_pc=0x0c071e46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[9])!=0);
goto P_0c071e48;
P_0c071e48: /* original 1f31, guest PC 0x0c071e48 */
if(!s->budget--) { s->failed_pc=0x0c071e48u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c071e4a;
P_0c071e4a: /* original 8d03, guest PC 0x0c071e4a */
if(!s->budget--) { s->failed_pc=0x0c071e4au; return 0; }
cond=r[17]&1u;
r[8]+=0x00000018u;
if(cond) { goto P_0c071e54; }
goto P_0c071e4e;
P_0c071e4c: /* original 7818, guest PC 0x0c071e4c */
if(!s->budget--) { s->failed_pc=0x0c071e4cu; return 0; }
r[8]+=0x00000018u;
goto P_0c071e4e;
P_0c071e4e: /* original d304, guest PC 0x0c071e4e */
if(!s->budget--) { s->failed_pc=0x0c071e4eu; return 0; }
r[3]=read(ram,0x0c071e60u,4);
goto P_0c071e50;
P_0c071e50: /* original 432b, guest PC 0x0c071e50 */
if(!s->budget--) { s->failed_pc=0x0c071e50u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071e52: /* original 0009, guest PC 0x0c071e52 */
if(!s->budget--) { s->failed_pc=0x0c071e52u; return 0; }
goto P_0c071e54;
P_0c071e54: /* original 65f2, guest PC 0x0c071e54 */
if(!s->budget--) { s->failed_pc=0x0c071e54u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071e56;
P_0c071e56: /* original 64d3, guest PC 0x0c071e56 */
if(!s->budget--) { s->failed_pc=0x0c071e56u; return 0; }
r[4]=r[13];
goto P_0c071e58;
P_0c071e58: /* original 66e3, guest PC 0x0c071e58 */
if(!s->budget--) { s->failed_pc=0x0c071e58u; return 0; }
r[6]=r[14];
goto P_0c071e5a;
P_0c071e5a: /* original a003, guest PC 0x0c071e5a */
if(!s->budget--) { s->failed_pc=0x0c071e5au; return 0; }
goto P_0c071e64;
P_0c071e5c: /* original 0009, guest PC 0x0c071e5c */
if(!s->budget--) { s->failed_pc=0x0c071e5cu; return 0; }
return vf3_matrix_family(0x0c071e5eu,s,ram);
P_0c071e64: /* original f059, guest PC 0x0c071e64 */
if(!s->budget--) { s->failed_pc=0x0c071e64u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e66;
P_0c071e66: /* original f369, guest PC 0x0c071e66 */
if(!s->budget--) { s->failed_pc=0x0c071e66u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e68;
P_0c071e68: /* original f159, guest PC 0x0c071e68 */
if(!s->budget--) { s->failed_pc=0x0c071e68u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e6a;
P_0c071e6a: /* original f469, guest PC 0x0c071e6a */
if(!s->budget--) { s->failed_pc=0x0c071e6au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e6c;
P_0c071e6c: /* original f031, guest PC 0x0c071e6c */
if(!s->budget--) { s->failed_pc=0x0c071e6cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071e6e;
P_0c071e6e: /* original f258, guest PC 0x0c071e6e */
if(!s->budget--) { s->failed_pc=0x0c071e6eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071e70;
P_0c071e70: /* original f568, guest PC 0x0c071e70 */
if(!s->budget--) { s->failed_pc=0x0c071e70u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071e72;
P_0c071e72: /* original f141, guest PC 0x0c071e72 */
if(!s->budget--) { s->failed_pc=0x0c071e72u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071e74;
P_0c071e74: /* original f251, guest PC 0x0c071e74 */
if(!s->budget--) { s->failed_pc=0x0c071e74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071e76;
P_0c071e76: /* original 7408, guest PC 0x0c071e76 */
if(!s->budget--) { s->failed_pc=0x0c071e76u; return 0; }
r[4]+=0x00000008u;
goto P_0c071e78;
P_0c071e78: /* original f42a, guest PC 0x0c071e78 */
if(!s->budget--) { s->failed_pc=0x0c071e78u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e7a;
P_0c071e7a: /* original f41b, guest PC 0x0c071e7a */
if(!s->budget--) { s->failed_pc=0x0c071e7au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e7c;
P_0c071e7c: /* original f40b, guest PC 0x0c071e7c */
if(!s->budget--) { s->failed_pc=0x0c071e7cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071e7e;
P_0c071e7e: /* original 0009, guest PC 0x0c071e7e */
if(!s->budget--) { s->failed_pc=0x0c071e7eu; return 0; }
goto P_0c071e80;
P_0c071e80: /* original 64a3, guest PC 0x0c071e80 */
if(!s->budget--) { s->failed_pc=0x0c071e80u; return 0; }
r[4]=r[10];
goto P_0c071e82;
P_0c071e82: /* original 65b3, guest PC 0x0c071e82 */
if(!s->budget--) { s->failed_pc=0x0c071e82u; return 0; }
r[5]=r[11];
goto P_0c071e84;
P_0c071e84: /* original 66e3, guest PC 0x0c071e84 */
if(!s->budget--) { s->failed_pc=0x0c071e84u; return 0; }
r[6]=r[14];
goto P_0c071e86;
P_0c071e86: /* original f059, guest PC 0x0c071e86 */
if(!s->budget--) { s->failed_pc=0x0c071e86u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e88;
P_0c071e88: /* original f369, guest PC 0x0c071e88 */
if(!s->budget--) { s->failed_pc=0x0c071e88u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8a;
P_0c071e8a: /* original f159, guest PC 0x0c071e8a */
if(!s->budget--) { s->failed_pc=0x0c071e8au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8c;
P_0c071e8c: /* original f469, guest PC 0x0c071e8c */
if(!s->budget--) { s->failed_pc=0x0c071e8cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8e;
P_0c071e8e: /* original f031, guest PC 0x0c071e8e */
if(!s->budget--) { s->failed_pc=0x0c071e8eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071e90;
P_0c071e90: /* original f258, guest PC 0x0c071e90 */
if(!s->budget--) { s->failed_pc=0x0c071e90u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071e92;
P_0c071e92: /* original f568, guest PC 0x0c071e92 */
if(!s->budget--) { s->failed_pc=0x0c071e92u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071e94;
P_0c071e94: /* original f141, guest PC 0x0c071e94 */
if(!s->budget--) { s->failed_pc=0x0c071e94u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071e96;
P_0c071e96: /* original f251, guest PC 0x0c071e96 */
if(!s->budget--) { s->failed_pc=0x0c071e96u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071e98;
P_0c071e98: /* original 7408, guest PC 0x0c071e98 */
if(!s->budget--) { s->failed_pc=0x0c071e98u; return 0; }
r[4]+=0x00000008u;
goto P_0c071e9a;
P_0c071e9a: /* original f42a, guest PC 0x0c071e9a */
if(!s->budget--) { s->failed_pc=0x0c071e9au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e9c;
P_0c071e9c: /* original f41b, guest PC 0x0c071e9c */
if(!s->budget--) { s->failed_pc=0x0c071e9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e9e;
P_0c071e9e: /* original f40b, guest PC 0x0c071e9e */
if(!s->budget--) { s->failed_pc=0x0c071e9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071ea0;
P_0c071ea0: /* original 64c3, guest PC 0x0c071ea0 */
if(!s->budget--) { s->failed_pc=0x0c071ea0u; return 0; }
r[4]=r[12];
goto P_0c071ea2;
P_0c071ea2: /* original 6583, guest PC 0x0c071ea2 */
if(!s->budget--) { s->failed_pc=0x0c071ea2u; return 0; }
r[5]=r[8];
goto P_0c071ea4;
P_0c071ea4: /* original 66e3, guest PC 0x0c071ea4 */
if(!s->budget--) { s->failed_pc=0x0c071ea4u; return 0; }
r[6]=r[14];
goto P_0c071ea6;
P_0c071ea6: /* original f059, guest PC 0x0c071ea6 */
if(!s->budget--) { s->failed_pc=0x0c071ea6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ea8;
P_0c071ea8: /* original f369, guest PC 0x0c071ea8 */
if(!s->budget--) { s->failed_pc=0x0c071ea8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071eaa;
P_0c071eaa: /* original f159, guest PC 0x0c071eaa */
if(!s->budget--) { s->failed_pc=0x0c071eaau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071eac;
P_0c071eac: /* original f469, guest PC 0x0c071eac */
if(!s->budget--) { s->failed_pc=0x0c071eacu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071eae;
P_0c071eae: /* original f031, guest PC 0x0c071eae */
if(!s->budget--) { s->failed_pc=0x0c071eaeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071eb0;
P_0c071eb0: /* original f258, guest PC 0x0c071eb0 */
if(!s->budget--) { s->failed_pc=0x0c071eb0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071eb2;
P_0c071eb2: /* original f568, guest PC 0x0c071eb2 */
if(!s->budget--) { s->failed_pc=0x0c071eb2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071eb4;
P_0c071eb4: /* original f141, guest PC 0x0c071eb4 */
if(!s->budget--) { s->failed_pc=0x0c071eb4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071eb6;
P_0c071eb6: /* original f251, guest PC 0x0c071eb6 */
if(!s->budget--) { s->failed_pc=0x0c071eb6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071eb8;
P_0c071eb8: /* original 7408, guest PC 0x0c071eb8 */
if(!s->budget--) { s->failed_pc=0x0c071eb8u; return 0; }
r[4]+=0x00000008u;
goto P_0c071eba;
P_0c071eba: /* original f42a, guest PC 0x0c071eba */
if(!s->budget--) { s->failed_pc=0x0c071ebau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071ebc;
P_0c071ebc: /* original f41b, guest PC 0x0c071ebc */
if(!s->budget--) { s->failed_pc=0x0c071ebcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071ebe;
P_0c071ebe: /* original f40b, guest PC 0x0c071ebe */
if(!s->budget--) { s->failed_pc=0x0c071ebeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071ec0;
P_0c071ec0: /* original 66f3, guest PC 0x0c071ec0 */
if(!s->budget--) { s->failed_pc=0x0c071ec0u; return 0; }
r[6]=r[15];
goto P_0c071ec2;
P_0c071ec2: /* original 64c3, guest PC 0x0c071ec2 */
if(!s->budget--) { s->failed_pc=0x0c071ec2u; return 0; }
r[4]=r[12];
goto P_0c071ec4;
P_0c071ec4: /* original 65a3, guest PC 0x0c071ec4 */
if(!s->budget--) { s->failed_pc=0x0c071ec4u; return 0; }
r[5]=r[10];
goto P_0c071ec6;
P_0c071ec6: /* original 7624, guest PC 0x0c071ec6 */
if(!s->budget--) { s->failed_pc=0x0c071ec6u; return 0; }
r[6]+=0x00000024u;
goto P_0c071ec8;
P_0c071ec8: /* original f049, guest PC 0x0c071ec8 */
if(!s->budget--) { s->failed_pc=0x0c071ec8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071eca;
P_0c071eca: /* original f549, guest PC 0x0c071eca */
if(!s->budget--) { s->failed_pc=0x0c071ecau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071ecc;
P_0c071ecc: /* original f648, guest PC 0x0c071ecc */
if(!s->budget--) { s->failed_pc=0x0c071eccu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071ece;
P_0c071ece: /* original f859, guest PC 0x0c071ece */
if(!s->budget--) { s->failed_pc=0x0c071eceu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ed0;
P_0c071ed0: /* original f959, guest PC 0x0c071ed0 */
if(!s->budget--) { s->failed_pc=0x0c071ed0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ed2;
P_0c071ed2: /* original fa58, guest PC 0x0c071ed2 */
if(!s->budget--) { s->failed_pc=0x0c071ed2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071ed4;
P_0c071ed4: /* original 760c, guest PC 0x0c071ed4 */
if(!s->budget--) { s->failed_pc=0x0c071ed4u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071ed6;
P_0c071ed6: /* original f35c, guest PC 0x0c071ed6 */
if(!s->budget--) { s->failed_pc=0x0c071ed6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071ed8;
P_0c071ed8: /* original f382, guest PC 0x0c071ed8 */
if(!s->budget--) { s->failed_pc=0x0c071ed8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071eda;
P_0c071eda: /* original f20c, guest PC 0x0c071eda */
if(!s->budget--) { s->failed_pc=0x0c071edau; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071edc;
P_0c071edc: /* original f2a2, guest PC 0x0c071edc */
if(!s->budget--) { s->failed_pc=0x0c071edcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071ede;
P_0c071ede: /* original f16c, guest PC 0x0c071ede */
if(!s->budget--) { s->failed_pc=0x0c071edeu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071ee0;
P_0c071ee0: /* original f192, guest PC 0x0c071ee0 */
if(!s->budget--) { s->failed_pc=0x0c071ee0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071ee2;
P_0c071ee2: /* original f34d, guest PC 0x0c071ee2 */
if(!s->budget--) { s->failed_pc=0x0c071ee2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071ee4;
P_0c071ee4: /* original f39e, guest PC 0x0c071ee4 */
if(!s->budget--) { s->failed_pc=0x0c071ee4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071ee6;
P_0c071ee6: /* original f24d, guest PC 0x0c071ee6 */
if(!s->budget--) { s->failed_pc=0x0c071ee6u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071ee8;
P_0c071ee8: /* original f06c, guest PC 0x0c071ee8 */
if(!s->budget--) { s->failed_pc=0x0c071ee8u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071eea;
P_0c071eea: /* original f28e, guest PC 0x0c071eea */
if(!s->budget--) { s->failed_pc=0x0c071eeau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071eec;
P_0c071eec: /* original f14d, guest PC 0x0c071eec */
if(!s->budget--) { s->failed_pc=0x0c071eecu; return 0; }
fr[1]^=0x80000000u;
goto P_0c071eee;
P_0c071eee: /* original f63b, guest PC 0x0c071eee */
if(!s->budget--) { s->failed_pc=0x0c071eeeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071ef0;
P_0c071ef0: /* original f05c, guest PC 0x0c071ef0 */
if(!s->budget--) { s->failed_pc=0x0c071ef0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071ef2;
P_0c071ef2: /* original f1ae, guest PC 0x0c071ef2 */
if(!s->budget--) { s->failed_pc=0x0c071ef2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071ef4;
P_0c071ef4: /* original f62b, guest PC 0x0c071ef4 */
if(!s->budget--) { s->failed_pc=0x0c071ef4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071ef6;
P_0c071ef6: /* original f61b, guest PC 0x0c071ef6 */
if(!s->budget--) { s->failed_pc=0x0c071ef6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071ef8;
P_0c071ef8: /* original 66f3, guest PC 0x0c071ef8 */
if(!s->budget--) { s->failed_pc=0x0c071ef8u; return 0; }
r[6]=r[15];
goto P_0c071efa;
P_0c071efa: /* original 64d3, guest PC 0x0c071efa */
if(!s->budget--) { s->failed_pc=0x0c071efau; return 0; }
r[4]=r[13];
goto P_0c071efc;
P_0c071efc: /* original 65c3, guest PC 0x0c071efc */
if(!s->budget--) { s->failed_pc=0x0c071efcu; return 0; }
r[5]=r[12];
goto P_0c071efe;
P_0c071efe: /* original 7618, guest PC 0x0c071efe */
if(!s->budget--) { s->failed_pc=0x0c071efeu; return 0; }
r[6]+=0x00000018u;
goto P_0c071f00;
P_0c071f00: /* original f049, guest PC 0x0c071f00 */
if(!s->budget--) { s->failed_pc=0x0c071f00u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f02;
P_0c071f02: /* original f549, guest PC 0x0c071f02 */
if(!s->budget--) { s->failed_pc=0x0c071f02u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f04;
P_0c071f04: /* original f648, guest PC 0x0c071f04 */
if(!s->budget--) { s->failed_pc=0x0c071f04u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071f06;
P_0c071f06: /* original f859, guest PC 0x0c071f06 */
if(!s->budget--) { s->failed_pc=0x0c071f06u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f08;
P_0c071f08: /* original f959, guest PC 0x0c071f08 */
if(!s->budget--) { s->failed_pc=0x0c071f08u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f0a;
P_0c071f0a: /* original fa58, guest PC 0x0c071f0a */
if(!s->budget--) { s->failed_pc=0x0c071f0au; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071f0c;
P_0c071f0c: /* original 760c, guest PC 0x0c071f0c */
if(!s->budget--) { s->failed_pc=0x0c071f0cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071f0e;
P_0c071f0e: /* original f35c, guest PC 0x0c071f0e */
if(!s->budget--) { s->failed_pc=0x0c071f0eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071f10;
P_0c071f10: /* original f382, guest PC 0x0c071f10 */
if(!s->budget--) { s->failed_pc=0x0c071f10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071f12;
P_0c071f12: /* original f20c, guest PC 0x0c071f12 */
if(!s->budget--) { s->failed_pc=0x0c071f12u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071f14;
P_0c071f14: /* original f2a2, guest PC 0x0c071f14 */
if(!s->budget--) { s->failed_pc=0x0c071f14u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071f16;
P_0c071f16: /* original f16c, guest PC 0x0c071f16 */
if(!s->budget--) { s->failed_pc=0x0c071f16u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071f18;
P_0c071f18: /* original f192, guest PC 0x0c071f18 */
if(!s->budget--) { s->failed_pc=0x0c071f18u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071f1a;
P_0c071f1a: /* original f34d, guest PC 0x0c071f1a */
if(!s->budget--) { s->failed_pc=0x0c071f1au; return 0; }
fr[3]^=0x80000000u;
goto P_0c071f1c;
P_0c071f1c: /* original f39e, guest PC 0x0c071f1c */
if(!s->budget--) { s->failed_pc=0x0c071f1cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071f1e;
P_0c071f1e: /* original f24d, guest PC 0x0c071f1e */
if(!s->budget--) { s->failed_pc=0x0c071f1eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c071f20;
P_0c071f20: /* original f06c, guest PC 0x0c071f20 */
if(!s->budget--) { s->failed_pc=0x0c071f20u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071f22;
P_0c071f22: /* original f28e, guest PC 0x0c071f22 */
if(!s->budget--) { s->failed_pc=0x0c071f22u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071f24;
P_0c071f24: /* original f14d, guest PC 0x0c071f24 */
if(!s->budget--) { s->failed_pc=0x0c071f24u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071f26;
P_0c071f26: /* original f63b, guest PC 0x0c071f26 */
if(!s->budget--) { s->failed_pc=0x0c071f26u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071f28;
P_0c071f28: /* original f05c, guest PC 0x0c071f28 */
if(!s->budget--) { s->failed_pc=0x0c071f28u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071f2a;
P_0c071f2a: /* original f1ae, guest PC 0x0c071f2a */
if(!s->budget--) { s->failed_pc=0x0c071f2au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071f2c;
P_0c071f2c: /* original f62b, guest PC 0x0c071f2c */
if(!s->budget--) { s->failed_pc=0x0c071f2cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071f2e;
P_0c071f2e: /* original f61b, guest PC 0x0c071f2e */
if(!s->budget--) { s->failed_pc=0x0c071f2eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071f30;
P_0c071f30: /* original 64f3, guest PC 0x0c071f30 */
if(!s->budget--) { s->failed_pc=0x0c071f30u; return 0; }
r[4]=r[15];
goto P_0c071f32;
P_0c071f32: /* original 7424, guest PC 0x0c071f32 */
if(!s->budget--) { s->failed_pc=0x0c071f32u; return 0; }
r[4]+=0x00000024u;
goto P_0c071f34;
P_0c071f34: /* original f049, guest PC 0x0c071f34 */
if(!s->budget--) { s->failed_pc=0x0c071f34u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f36;
P_0c071f36: /* original f149, guest PC 0x0c071f36 */
if(!s->budget--) { s->failed_pc=0x0c071f36u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f38;
P_0c071f38: /* original f249, guest PC 0x0c071f38 */
if(!s->budget--) { s->failed_pc=0x0c071f38u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f3a;
P_0c071f3a: /* original f38d, guest PC 0x0c071f3a */
if(!s->budget--) { s->failed_pc=0x0c071f3au; return 0; }
fr[3]=0;
goto P_0c071f3c;
P_0c071f3c: /* original f0ed, guest PC 0x0c071f3c */
if(!s->budget--) { s->failed_pc=0x0c071f3cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f3e;
P_0c071f3e: /* original f37d, guest PC 0x0c071f3e */
if(!s->budget--) { s->failed_pc=0x0c071f3eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071f40;
P_0c071f40: /* original f232, guest PC 0x0c071f40 */
if(!s->budget--) { s->failed_pc=0x0c071f40u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071f42;
P_0c071f42: /* original f132, guest PC 0x0c071f42 */
if(!s->budget--) { s->failed_pc=0x0c071f42u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071f44;
P_0c071f44: /* original f032, guest PC 0x0c071f44 */
if(!s->budget--) { s->failed_pc=0x0c071f44u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071f46;
P_0c071f46: /* original f42b, guest PC 0x0c071f46 */
if(!s->budget--) { s->failed_pc=0x0c071f46u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f48;
P_0c071f48: /* original f41b, guest PC 0x0c071f48 */
if(!s->budget--) { s->failed_pc=0x0c071f48u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f4a;
P_0c071f4a: /* original f40b, guest PC 0x0c071f4a */
if(!s->budget--) { s->failed_pc=0x0c071f4au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f4c;
P_0c071f4c: /* original 64f3, guest PC 0x0c071f4c */
if(!s->budget--) { s->failed_pc=0x0c071f4cu; return 0; }
r[4]=r[15];
goto P_0c071f4e;
P_0c071f4e: /* original 7418, guest PC 0x0c071f4e */
if(!s->budget--) { s->failed_pc=0x0c071f4eu; return 0; }
r[4]+=0x00000018u;
goto P_0c071f50;
P_0c071f50: /* original f049, guest PC 0x0c071f50 */
if(!s->budget--) { s->failed_pc=0x0c071f50u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f52;
P_0c071f52: /* original f149, guest PC 0x0c071f52 */
if(!s->budget--) { s->failed_pc=0x0c071f52u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f54;
P_0c071f54: /* original f249, guest PC 0x0c071f54 */
if(!s->budget--) { s->failed_pc=0x0c071f54u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f56;
P_0c071f56: /* original f38d, guest PC 0x0c071f56 */
if(!s->budget--) { s->failed_pc=0x0c071f56u; return 0; }
fr[3]=0;
goto P_0c071f58;
P_0c071f58: /* original f0ed, guest PC 0x0c071f58 */
if(!s->budget--) { s->failed_pc=0x0c071f58u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f5a;
P_0c071f5a: /* original f37d, guest PC 0x0c071f5a */
if(!s->budget--) { s->failed_pc=0x0c071f5au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071f5c;
P_0c071f5c: /* original f232, guest PC 0x0c071f5c */
if(!s->budget--) { s->failed_pc=0x0c071f5cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071f5e;
P_0c071f5e: /* original f132, guest PC 0x0c071f5e */
if(!s->budget--) { s->failed_pc=0x0c071f5eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071f60;
P_0c071f60: /* original f032, guest PC 0x0c071f60 */
if(!s->budget--) { s->failed_pc=0x0c071f60u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071f62;
P_0c071f62: /* original f42b, guest PC 0x0c071f62 */
if(!s->budget--) { s->failed_pc=0x0c071f62u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f64;
P_0c071f64: /* original f41b, guest PC 0x0c071f64 */
if(!s->budget--) { s->failed_pc=0x0c071f64u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f66;
P_0c071f66: /* original f40b, guest PC 0x0c071f66 */
if(!s->budget--) { s->failed_pc=0x0c071f66u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f68;
P_0c071f68: /* original 65f3, guest PC 0x0c071f68 */
if(!s->budget--) { s->failed_pc=0x0c071f68u; return 0; }
r[5]=r[15];
goto P_0c071f6a;
P_0c071f6a: /* original 64e3, guest PC 0x0c071f6a */
if(!s->budget--) { s->failed_pc=0x0c071f6au; return 0; }
r[4]=r[14];
goto P_0c071f6c;
P_0c071f6c: /* original 66f3, guest PC 0x0c071f6c */
if(!s->budget--) { s->failed_pc=0x0c071f6cu; return 0; }
r[6]=r[15];
goto P_0c071f6e;
P_0c071f6e: /* original 740c, guest PC 0x0c071f6e */
if(!s->budget--) { s->failed_pc=0x0c071f6eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f70;
P_0c071f70: /* original 7618, guest PC 0x0c071f70 */
if(!s->budget--) { s->failed_pc=0x0c071f70u; return 0; }
r[6]+=0x00000018u;
goto P_0c071f72;
P_0c071f72: /* original 7524, guest PC 0x0c071f72 */
if(!s->budget--) { s->failed_pc=0x0c071f72u; return 0; }
r[5]+=0x00000024u;
goto P_0c071f74;
P_0c071f74: /* original f059, guest PC 0x0c071f74 */
if(!s->budget--) { s->failed_pc=0x0c071f74u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f76;
P_0c071f76: /* original f369, guest PC 0x0c071f76 */
if(!s->budget--) { s->failed_pc=0x0c071f76u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f78;
P_0c071f78: /* original f159, guest PC 0x0c071f78 */
if(!s->budget--) { s->failed_pc=0x0c071f78u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7a;
P_0c071f7a: /* original f469, guest PC 0x0c071f7a */
if(!s->budget--) { s->failed_pc=0x0c071f7au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7c;
P_0c071f7c: /* original f259, guest PC 0x0c071f7c */
if(!s->budget--) { s->failed_pc=0x0c071f7cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7e;
P_0c071f7e: /* original f569, guest PC 0x0c071f7e */
if(!s->budget--) { s->failed_pc=0x0c071f7eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f80;
P_0c071f80: /* original 740c, guest PC 0x0c071f80 */
if(!s->budget--) { s->failed_pc=0x0c071f80u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f82;
P_0c071f82: /* original f030, guest PC 0x0c071f82 */
if(!s->budget--) { s->failed_pc=0x0c071f82u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071f84;
P_0c071f84: /* original f250, guest PC 0x0c071f84 */
if(!s->budget--) { s->failed_pc=0x0c071f84u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071f86;
P_0c071f86: /* original f140, guest PC 0x0c071f86 */
if(!s->budget--) { s->failed_pc=0x0c071f86u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071f88;
P_0c071f88: /* original f42b, guest PC 0x0c071f88 */
if(!s->budget--) { s->failed_pc=0x0c071f88u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f8a;
P_0c071f8a: /* original f41b, guest PC 0x0c071f8a */
if(!s->budget--) { s->failed_pc=0x0c071f8au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f8c;
P_0c071f8c: /* original f40b, guest PC 0x0c071f8c */
if(!s->budget--) { s->failed_pc=0x0c071f8cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f8e;
P_0c071f8e: /* original 0009, guest PC 0x0c071f8e */
if(!s->budget--) { s->failed_pc=0x0c071f8eu; return 0; }
goto P_0c071f90;
P_0c071f90: /* original 64e3, guest PC 0x0c071f90 */
if(!s->budget--) { s->failed_pc=0x0c071f90u; return 0; }
r[4]=r[14];
goto P_0c071f92;
P_0c071f92: /* original 740c, guest PC 0x0c071f92 */
if(!s->budget--) { s->failed_pc=0x0c071f92u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f94;
P_0c071f94: /* original f049, guest PC 0x0c071f94 */
if(!s->budget--) { s->failed_pc=0x0c071f94u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f96;
P_0c071f96: /* original f149, guest PC 0x0c071f96 */
if(!s->budget--) { s->failed_pc=0x0c071f96u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f98;
P_0c071f98: /* original f249, guest PC 0x0c071f98 */
if(!s->budget--) { s->failed_pc=0x0c071f98u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f9a;
P_0c071f9a: /* original f38d, guest PC 0x0c071f9a */
if(!s->budget--) { s->failed_pc=0x0c071f9au; return 0; }
fr[3]=0;
goto P_0c071f9c;
P_0c071f9c: /* original f0ed, guest PC 0x0c071f9c */
if(!s->budget--) { s->failed_pc=0x0c071f9cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f9e;
P_0c071f9e: /* original f37d, guest PC 0x0c071f9e */
if(!s->budget--) { s->failed_pc=0x0c071f9eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071fa0;
P_0c071fa0: /* original f232, guest PC 0x0c071fa0 */
if(!s->budget--) { s->failed_pc=0x0c071fa0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071fa2;
P_0c071fa2: /* original f132, guest PC 0x0c071fa2 */
if(!s->budget--) { s->failed_pc=0x0c071fa2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071fa4;
P_0c071fa4: /* original f032, guest PC 0x0c071fa4 */
if(!s->budget--) { s->failed_pc=0x0c071fa4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071fa6;
P_0c071fa6: /* original f42b, guest PC 0x0c071fa6 */
if(!s->budget--) { s->failed_pc=0x0c071fa6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071fa8;
P_0c071fa8: /* original f41b, guest PC 0x0c071fa8 */
if(!s->budget--) { s->failed_pc=0x0c071fa8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071faa;
P_0c071faa: /* original f40b, guest PC 0x0c071faa */
if(!s->budget--) { s->failed_pc=0x0c071faau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071fac;
P_0c071fac: /* original 2fe2, guest PC 0x0c071fac */
if(!s->budget--) { s->failed_pc=0x0c071facu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c071fae;
P_0c071fae: /* original 6eb3, guest PC 0x0c071fae */
if(!s->budget--) { s->failed_pc=0x0c071faeu; return 0; }
r[14]=r[11];
goto P_0c071fb0;
P_0c071fb0: /* original 53f1, guest PC 0x0c071fb0 */
if(!s->budget--) { s->failed_pc=0x0c071fb0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c071fb2;
P_0c071fb2: /* original 7b18, guest PC 0x0c071fb2 */
if(!s->budget--) { s->failed_pc=0x0c071fb2u; return 0; }
r[11]+=0x00000018u;
goto P_0c071fb4;
P_0c071fb4: /* original 7818, guest PC 0x0c071fb4 */
if(!s->budget--) { s->failed_pc=0x0c071fb4u; return 0; }
r[8]+=0x00000018u;
goto P_0c071fb6;
P_0c071fb6: /* original 73ff, guest PC 0x0c071fb6 */
if(!s->budget--) { s->failed_pc=0x0c071fb6u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071fb8;
P_0c071fb8: /* original 3397, guest PC 0x0c071fb8 */
if(!s->budget--) { s->failed_pc=0x0c071fb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[9])!=0);
goto P_0c071fba;
P_0c071fba: /* original 8f03, guest PC 0x0c071fba */
if(!s->budget--) { s->failed_pc=0x0c071fbau; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c071fc4; }
goto P_0c071fbe;
P_0c071fbc: /* original 1f31, guest PC 0x0c071fbc */
if(!s->budget--) { s->failed_pc=0x0c071fbcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c071fbe;
P_0c071fbe: /* original d204, guest PC 0x0c071fbe */
if(!s->budget--) { s->failed_pc=0x0c071fbeu; return 0; }
r[2]=read(ram,0x0c071fd0u,4);
goto P_0c071fc0;
P_0c071fc0: /* original 422b, guest PC 0x0c071fc0 */
if(!s->budget--) { s->failed_pc=0x0c071fc0u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071fc2: /* original 0009, guest PC 0x0c071fc2 */
if(!s->budget--) { s->failed_pc=0x0c071fc2u; return 0; }
goto P_0c071fc4;
P_0c071fc4: /* original 65f2, guest PC 0x0c071fc4 */
if(!s->budget--) { s->failed_pc=0x0c071fc4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071fc6;
P_0c071fc6: /* original 64d3, guest PC 0x0c071fc6 */
if(!s->budget--) { s->failed_pc=0x0c071fc6u; return 0; }
r[4]=r[13];
goto P_0c071fc8;
P_0c071fc8: /* original 66e3, guest PC 0x0c071fc8 */
if(!s->budget--) { s->failed_pc=0x0c071fc8u; return 0; }
r[6]=r[14];
goto P_0c071fca;
P_0c071fca: /* original a003, guest PC 0x0c071fca */
if(!s->budget--) { s->failed_pc=0x0c071fcau; return 0; }
goto P_0c071fd4;
P_0c071fcc: /* original 0009, guest PC 0x0c071fcc */
if(!s->budget--) { s->failed_pc=0x0c071fccu; return 0; }
return vf3_matrix_family(0x0c071fceu,s,ram);
P_0c071fd4: /* original f059, guest PC 0x0c071fd4 */
if(!s->budget--) { s->failed_pc=0x0c071fd4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071fd6;
P_0c071fd6: /* original f369, guest PC 0x0c071fd6 */
if(!s->budget--) { s->failed_pc=0x0c071fd6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071fd8;
P_0c071fd8: /* original f159, guest PC 0x0c071fd8 */
if(!s->budget--) { s->failed_pc=0x0c071fd8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071fda;
P_0c071fda: /* original f469, guest PC 0x0c071fda */
if(!s->budget--) { s->failed_pc=0x0c071fdau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071fdc;
P_0c071fdc: /* original f031, guest PC 0x0c071fdc */
if(!s->budget--) { s->failed_pc=0x0c071fdcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071fde;
P_0c071fde: /* original f258, guest PC 0x0c071fde */
if(!s->budget--) { s->failed_pc=0x0c071fdeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071fe0;
P_0c071fe0: /* original f568, guest PC 0x0c071fe0 */
if(!s->budget--) { s->failed_pc=0x0c071fe0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071fe2;
P_0c071fe2: /* original f141, guest PC 0x0c071fe2 */
if(!s->budget--) { s->failed_pc=0x0c071fe2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071fe4;
P_0c071fe4: /* original f251, guest PC 0x0c071fe4 */
if(!s->budget--) { s->failed_pc=0x0c071fe4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071fe6;
P_0c071fe6: /* original 7408, guest PC 0x0c071fe6 */
if(!s->budget--) { s->failed_pc=0x0c071fe6u; return 0; }
r[4]+=0x00000008u;
goto P_0c071fe8;
P_0c071fe8: /* original f42a, guest PC 0x0c071fe8 */
if(!s->budget--) { s->failed_pc=0x0c071fe8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071fea;
P_0c071fea: /* original f41b, guest PC 0x0c071fea */
if(!s->budget--) { s->failed_pc=0x0c071feau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071fec;
P_0c071fec: /* original f40b, guest PC 0x0c071fec */
if(!s->budget--) { s->failed_pc=0x0c071fecu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071fee;
P_0c071fee: /* original 0009, guest PC 0x0c071fee */
if(!s->budget--) { s->failed_pc=0x0c071feeu; return 0; }
goto P_0c071ff0;
P_0c071ff0: /* original 64a3, guest PC 0x0c071ff0 */
if(!s->budget--) { s->failed_pc=0x0c071ff0u; return 0; }
r[4]=r[10];
goto P_0c071ff2;
P_0c071ff2: /* original 6583, guest PC 0x0c071ff2 */
if(!s->budget--) { s->failed_pc=0x0c071ff2u; return 0; }
r[5]=r[8];
goto P_0c071ff4;
P_0c071ff4: /* original 66e3, guest PC 0x0c071ff4 */
if(!s->budget--) { s->failed_pc=0x0c071ff4u; return 0; }
r[6]=r[14];
goto P_0c071ff6;
P_0c071ff6: /* original f059, guest PC 0x0c071ff6 */
if(!s->budget--) { s->failed_pc=0x0c071ff6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ff8;
P_0c071ff8: /* original f369, guest PC 0x0c071ff8 */
if(!s->budget--) { s->failed_pc=0x0c071ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffa;
P_0c071ffa: /* original f159, guest PC 0x0c071ffa */
if(!s->budget--) { s->failed_pc=0x0c071ffau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffc;
P_0c071ffc: /* original f469, guest PC 0x0c071ffc */
if(!s->budget--) { s->failed_pc=0x0c071ffcu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffe;
P_0c071ffe: /* original f031, guest PC 0x0c071ffe */
if(!s->budget--) { s->failed_pc=0x0c071ffeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072000;
P_0c072000: /* original f258, guest PC 0x0c072000 */
if(!s->budget--) { s->failed_pc=0x0c072000u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072002;
P_0c072002: /* original f568, guest PC 0x0c072002 */
if(!s->budget--) { s->failed_pc=0x0c072002u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072004;
P_0c072004: /* original f141, guest PC 0x0c072004 */
if(!s->budget--) { s->failed_pc=0x0c072004u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072006;
P_0c072006: /* original f251, guest PC 0x0c072006 */
if(!s->budget--) { s->failed_pc=0x0c072006u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072008;
P_0c072008: /* original 7408, guest PC 0x0c072008 */
if(!s->budget--) { s->failed_pc=0x0c072008u; return 0; }
r[4]+=0x00000008u;
goto P_0c07200a;
P_0c07200a: /* original f42a, guest PC 0x0c07200a */
if(!s->budget--) { s->failed_pc=0x0c07200au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07200c;
P_0c07200c: /* original f41b, guest PC 0x0c07200c */
if(!s->budget--) { s->failed_pc=0x0c07200cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07200e;
P_0c07200e: /* original f40b, guest PC 0x0c07200e */
if(!s->budget--) { s->failed_pc=0x0c07200eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072010;
P_0c072010: /* original 66e3, guest PC 0x0c072010 */
if(!s->budget--) { s->failed_pc=0x0c072010u; return 0; }
r[6]=r[14];
goto P_0c072012;
P_0c072012: /* original 64d3, guest PC 0x0c072012 */
if(!s->budget--) { s->failed_pc=0x0c072012u; return 0; }
r[4]=r[13];
goto P_0c072014;
P_0c072014: /* original 65a3, guest PC 0x0c072014 */
if(!s->budget--) { s->failed_pc=0x0c072014u; return 0; }
r[5]=r[10];
goto P_0c072016;
P_0c072016: /* original 760c, guest PC 0x0c072016 */
if(!s->budget--) { s->failed_pc=0x0c072016u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072018;
P_0c072018: /* original f049, guest PC 0x0c072018 */
if(!s->budget--) { s->failed_pc=0x0c072018u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07201a;
P_0c07201a: /* original f549, guest PC 0x0c07201a */
if(!s->budget--) { s->failed_pc=0x0c07201au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07201c;
P_0c07201c: /* original f648, guest PC 0x0c07201c */
if(!s->budget--) { s->failed_pc=0x0c07201cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07201e;
P_0c07201e: /* original f859, guest PC 0x0c07201e */
if(!s->budget--) { s->failed_pc=0x0c07201eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072020;
P_0c072020: /* original f959, guest PC 0x0c072020 */
if(!s->budget--) { s->failed_pc=0x0c072020u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072022;
P_0c072022: /* original fa58, guest PC 0x0c072022 */
if(!s->budget--) { s->failed_pc=0x0c072022u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072024;
P_0c072024: /* original 760c, guest PC 0x0c072024 */
if(!s->budget--) { s->failed_pc=0x0c072024u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072026;
P_0c072026: /* original f35c, guest PC 0x0c072026 */
if(!s->budget--) { s->failed_pc=0x0c072026u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072028;
P_0c072028: /* original f382, guest PC 0x0c072028 */
if(!s->budget--) { s->failed_pc=0x0c072028u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07202a;
P_0c07202a: /* original f20c, guest PC 0x0c07202a */
if(!s->budget--) { s->failed_pc=0x0c07202au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07202c;
P_0c07202c: /* original f2a2, guest PC 0x0c07202c */
if(!s->budget--) { s->failed_pc=0x0c07202cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07202e;
P_0c07202e: /* original f16c, guest PC 0x0c07202e */
if(!s->budget--) { s->failed_pc=0x0c07202eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072030;
P_0c072030: /* original f192, guest PC 0x0c072030 */
if(!s->budget--) { s->failed_pc=0x0c072030u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072032;
P_0c072032: /* original f34d, guest PC 0x0c072032 */
if(!s->budget--) { s->failed_pc=0x0c072032u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072034;
P_0c072034: /* original f39e, guest PC 0x0c072034 */
if(!s->budget--) { s->failed_pc=0x0c072034u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c072036;
P_0c072036: /* original f24d, guest PC 0x0c072036 */
if(!s->budget--) { s->failed_pc=0x0c072036u; return 0; }
fr[2]^=0x80000000u;
goto P_0c072038;
P_0c072038: /* original f06c, guest PC 0x0c072038 */
if(!s->budget--) { s->failed_pc=0x0c072038u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07203a;
P_0c07203a: /* original f28e, guest PC 0x0c07203a */
if(!s->budget--) { s->failed_pc=0x0c07203au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07203c;
P_0c07203c: /* original f14d, guest PC 0x0c07203c */
if(!s->budget--) { s->failed_pc=0x0c07203cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c07203e;
P_0c07203e: /* original f63b, guest PC 0x0c07203e */
if(!s->budget--) { s->failed_pc=0x0c07203eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072040;
P_0c072040: /* original f05c, guest PC 0x0c072040 */
if(!s->budget--) { s->failed_pc=0x0c072040u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072042;
P_0c072042: /* original f1ae, guest PC 0x0c072042 */
if(!s->budget--) { s->failed_pc=0x0c072042u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072044;
P_0c072044: /* original f62b, guest PC 0x0c072044 */
if(!s->budget--) { s->failed_pc=0x0c072044u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c072046;
P_0c072046: /* original f61b, guest PC 0x0c072046 */
if(!s->budget--) { s->failed_pc=0x0c072046u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072048;
P_0c072048: /* original 64e3, guest PC 0x0c072048 */
if(!s->budget--) { s->failed_pc=0x0c072048u; return 0; }
r[4]=r[14];
goto P_0c07204a;
P_0c07204a: /* original 740c, guest PC 0x0c07204a */
if(!s->budget--) { s->failed_pc=0x0c07204au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07204c;
P_0c07204c: /* original f049, guest PC 0x0c07204c */
if(!s->budget--) { s->failed_pc=0x0c07204cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07204e;
P_0c07204e: /* original f149, guest PC 0x0c07204e */
if(!s->budget--) { s->failed_pc=0x0c07204eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072050;
P_0c072050: /* original f249, guest PC 0x0c072050 */
if(!s->budget--) { s->failed_pc=0x0c072050u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072052;
P_0c072052: /* original f38d, guest PC 0x0c072052 */
if(!s->budget--) { s->failed_pc=0x0c072052u; return 0; }
fr[3]=0;
goto P_0c072054;
P_0c072054: /* original f0ed, guest PC 0x0c072054 */
if(!s->budget--) { s->failed_pc=0x0c072054u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072056;
P_0c072056: /* original f37d, guest PC 0x0c072056 */
if(!s->budget--) { s->failed_pc=0x0c072056u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072058;
P_0c072058: /* original f232, guest PC 0x0c072058 */
if(!s->budget--) { s->failed_pc=0x0c072058u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07205a;
P_0c07205a: /* original f132, guest PC 0x0c07205a */
if(!s->budget--) { s->failed_pc=0x0c07205au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c07205c;
P_0c07205c: /* original f032, guest PC 0x0c07205c */
if(!s->budget--) { s->failed_pc=0x0c07205cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07205e;
P_0c07205e: /* original f42b, guest PC 0x0c07205e */
if(!s->budget--) { s->failed_pc=0x0c07205eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072060;
P_0c072060: /* original f41b, guest PC 0x0c072060 */
if(!s->budget--) { s->failed_pc=0x0c072060u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072062;
P_0c072062: /* original f40b, guest PC 0x0c072062 */
if(!s->budget--) { s->failed_pc=0x0c072062u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072064;
P_0c072064: /* original 7f60, guest PC 0x0c072064 */
if(!s->budget--) { s->failed_pc=0x0c072064u; return 0; }
r[15]+=0x00000060u;
goto P_0c072066;
P_0c072066: /* original 68f6, guest PC 0x0c072066 */
if(!s->budget--) { s->failed_pc=0x0c072066u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072068;
P_0c072068: /* original 69f6, guest PC 0x0c072068 */
if(!s->budget--) { s->failed_pc=0x0c072068u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07206a;
P_0c07206a: /* original 6af6, guest PC 0x0c07206a */
if(!s->budget--) { s->failed_pc=0x0c07206au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07206c;
P_0c07206c: /* original 6bf6, guest PC 0x0c07206c */
if(!s->budget--) { s->failed_pc=0x0c07206cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07206e;
P_0c07206e: /* original 6cf6, guest PC 0x0c07206e */
if(!s->budget--) { s->failed_pc=0x0c07206eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072070;
P_0c072070: /* original 6df6, guest PC 0x0c072070 */
if(!s->budget--) { s->failed_pc=0x0c072070u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072072;
P_0c072072: /* original 000b, guest PC 0x0c072072 */
if(!s->budget--) { s->failed_pc=0x0c072072u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072074: /* original 6ef6, guest PC 0x0c072074 */
if(!s->budget--) { s->failed_pc=0x0c072074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c072076u,s,ram);
P_0c07ab14: /* original 4f22, guest PC 0x0c07ab14 */
if(!s->budget--) { s->failed_pc=0x0c07ab14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ab16;
P_0c07ab16: /* original b54b, guest PC 0x0c07ab16 */
if(!s->budget--) { s->failed_pc=0x0c07ab16u; return 0; }
target=0x0c07b5b0u; r[16]=0x0c07ab1au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab1au) { target=s->pc; goto dispatch; }
goto P_0c07ab1a;
P_0c07ab18: /* original 0009, guest PC 0x0c07ab18 */
if(!s->budget--) { s->failed_pc=0x0c07ab18u; return 0; }
goto P_0c07ab1a;
P_0c07ab1a: /* original 6403, guest PC 0x0c07ab1a */
if(!s->budget--) { s->failed_pc=0x0c07ab1au; return 0; }
r[4]=r[0];
goto P_0c07ab1c;
P_0c07ab1c: /* original 614d, guest PC 0x0c07ab1c */
if(!s->budget--) { s->failed_pc=0x0c07ab1cu; return 0; }
r[1]=r[4]&65535u;
goto P_0c07ab1e;
P_0c07ab1e: /* original 6013, guest PC 0x0c07ab1e */
if(!s->budget--) { s->failed_pc=0x0c07ab1eu; return 0; }
r[0]=r[1];
goto P_0c07ab20;
P_0c07ab20: /* original 880f, guest PC 0x0c07ab20 */
if(!s->budget--) { s->failed_pc=0x0c07ab20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c07ab22;
P_0c07ab22: /* original 8b03, guest PC 0x0c07ab22 */
if(!s->budget--) { s->failed_pc=0x0c07ab22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab2c; }
goto P_0c07ab24;
P_0c07ab24: /* original b564, guest PC 0x0c07ab24 */
if(!s->budget--) { s->failed_pc=0x0c07ab24u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab28u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab28u) { target=s->pc; goto dispatch; }
goto P_0c07ab28;
P_0c07ab26: /* original 0009, guest PC 0x0c07ab26 */
if(!s->budget--) { s->failed_pc=0x0c07ab26u; return 0; }
goto P_0c07ab28;
P_0c07ab28: /* original a024, guest PC 0x0c07ab28 */
if(!s->budget--) { s->failed_pc=0x0c07ab28u; return 0; }
r[4]=0x00000024u;
goto P_0c07ab74;
P_0c07ab2a: /* original e424, guest PC 0x0c07ab2a */
if(!s->budget--) { s->failed_pc=0x0c07ab2au; return 0; }
r[4]=0x00000024u;
goto P_0c07ab2c;
P_0c07ab2c: /* original 8808, guest PC 0x0c07ab2c */
if(!s->budget--) { s->failed_pc=0x0c07ab2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07ab2e;
P_0c07ab2e: /* original 8902, guest PC 0x0c07ab2e */
if(!s->budget--) { s->failed_pc=0x0c07ab2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ab36; }
goto P_0c07ab30;
P_0c07ab30: /* original 6013, guest PC 0x0c07ab30 */
if(!s->budget--) { s->failed_pc=0x0c07ab30u; return 0; }
r[0]=r[1];
goto P_0c07ab32;
P_0c07ab32: /* original 8809, guest PC 0x0c07ab32 */
if(!s->budget--) { s->failed_pc=0x0c07ab32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07ab34;
P_0c07ab34: /* original 8b03, guest PC 0x0c07ab34 */
if(!s->budget--) { s->failed_pc=0x0c07ab34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab3e; }
goto P_0c07ab36;
P_0c07ab36: /* original b55b, guest PC 0x0c07ab36 */
if(!s->budget--) { s->failed_pc=0x0c07ab36u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab3au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab3au) { target=s->pc; goto dispatch; }
goto P_0c07ab3a;
P_0c07ab38: /* original 0009, guest PC 0x0c07ab38 */
if(!s->budget--) { s->failed_pc=0x0c07ab38u; return 0; }
goto P_0c07ab3a;
P_0c07ab3a: /* original a011, guest PC 0x0c07ab3a */
if(!s->budget--) { s->failed_pc=0x0c07ab3au; return 0; }
r[4]=0x00000005u;
goto P_0c07ab60;
P_0c07ab3c: /* original e405, guest PC 0x0c07ab3c */
if(!s->budget--) { s->failed_pc=0x0c07ab3cu; return 0; }
r[4]=0x00000005u;
goto P_0c07ab3e;
P_0c07ab3e: /* original 880a, guest PC 0x0c07ab3e */
if(!s->budget--) { s->failed_pc=0x0c07ab3eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c07ab40;
P_0c07ab40: /* original 8902, guest PC 0x0c07ab40 */
if(!s->budget--) { s->failed_pc=0x0c07ab40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ab48; }
goto P_0c07ab42;
P_0c07ab42: /* original 6013, guest PC 0x0c07ab42 */
if(!s->budget--) { s->failed_pc=0x0c07ab42u; return 0; }
r[0]=r[1];
goto P_0c07ab44;
P_0c07ab44: /* original 880b, guest PC 0x0c07ab44 */
if(!s->budget--) { s->failed_pc=0x0c07ab44u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c07ab46;
P_0c07ab46: /* original 8b04, guest PC 0x0c07ab46 */
if(!s->budget--) { s->failed_pc=0x0c07ab46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab52; }
goto P_0c07ab48;
P_0c07ab48: /* original b552, guest PC 0x0c07ab48 */
if(!s->budget--) { s->failed_pc=0x0c07ab48u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab4cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab4cu) { target=s->pc; goto dispatch; }
goto P_0c07ab4c;
P_0c07ab4a: /* original 0009, guest PC 0x0c07ab4a */
if(!s->budget--) { s->failed_pc=0x0c07ab4au; return 0; }
goto P_0c07ab4c;
P_0c07ab4c: /* original e406, guest PC 0x0c07ab4c */
if(!s->budget--) { s->failed_pc=0x0c07ab4cu; return 0; }
r[4]=0x00000006u;
goto P_0c07ab4e;
P_0c07ab4e: /* original a011, guest PC 0x0c07ab4e */
if(!s->budget--) { s->failed_pc=0x0c07ab4eu; return 0; }
goto P_0c07ab74;
P_0c07ab50: /* original 0009, guest PC 0x0c07ab50 */
if(!s->budget--) { s->failed_pc=0x0c07ab50u; return 0; }
goto P_0c07ab52;
P_0c07ab52: /* original 8812, guest PC 0x0c07ab52 */
if(!s->budget--) { s->failed_pc=0x0c07ab52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c07ab54;
P_0c07ab54: /* original 8b06, guest PC 0x0c07ab54 */
if(!s->budget--) { s->failed_pc=0x0c07ab54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab64; }
goto P_0c07ab56;
P_0c07ab56: /* original b54b, guest PC 0x0c07ab56 */
if(!s->budget--) { s->failed_pc=0x0c07ab56u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab5au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab5au) { target=s->pc; goto dispatch; }
goto P_0c07ab5a;
P_0c07ab58: /* original 0009, guest PC 0x0c07ab58 */
if(!s->budget--) { s->failed_pc=0x0c07ab58u; return 0; }
goto P_0c07ab5a;
P_0c07ab5a: /* original b549, guest PC 0x0c07ab5a */
if(!s->budget--) { s->failed_pc=0x0c07ab5au; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab5eu;
r[4]=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab5eu) { target=s->pc; goto dispatch; }
goto P_0c07ab5e;
P_0c07ab5c: /* original e423, guest PC 0x0c07ab5c */
if(!s->budget--) { s->failed_pc=0x0c07ab5cu; return 0; }
r[4]=0x00000023u;
goto P_0c07ab5e;
P_0c07ab5e: /* original 943d, guest PC 0x0c07ab5e */
if(!s->budget--) { s->failed_pc=0x0c07ab5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07abdcu,2);
goto P_0c07ab60;
P_0c07ab60: /* original a546, guest PC 0x0c07ab60 */
if(!s->budget--) { s->failed_pc=0x0c07ab60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b5f0;
P_0c07ab62: /* original 4f26, guest PC 0x0c07ab62 */
if(!s->budget--) { s->failed_pc=0x0c07ab62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ab64;
P_0c07ab64: /* original 6013, guest PC 0x0c07ab64 */
if(!s->budget--) { s->failed_pc=0x0c07ab64u; return 0; }
r[0]=r[1];
goto P_0c07ab66;
P_0c07ab66: /* original 8813, guest PC 0x0c07ab66 */
if(!s->budget--) { s->failed_pc=0x0c07ab66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c07ab68;
P_0c07ab68: /* original 8b06, guest PC 0x0c07ab68 */
if(!s->budget--) { s->failed_pc=0x0c07ab68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab78; }
goto P_0c07ab6a;
P_0c07ab6a: /* original b541, guest PC 0x0c07ab6a */
if(!s->budget--) { s->failed_pc=0x0c07ab6au; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab6eu) { target=s->pc; goto dispatch; }
goto P_0c07ab6e;
P_0c07ab6c: /* original 0009, guest PC 0x0c07ab6c */
if(!s->budget--) { s->failed_pc=0x0c07ab6cu; return 0; }
goto P_0c07ab6e;
P_0c07ab6e: /* original b53f, guest PC 0x0c07ab6e */
if(!s->budget--) { s->failed_pc=0x0c07ab6eu; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab72u;
r[4]=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab72u) { target=s->pc; goto dispatch; }
goto P_0c07ab72;
P_0c07ab70: /* original e423, guest PC 0x0c07ab70 */
if(!s->budget--) { s->failed_pc=0x0c07ab70u; return 0; }
r[4]=0x00000023u;
goto P_0c07ab72;
P_0c07ab72: /* original e418, guest PC 0x0c07ab72 */
if(!s->budget--) { s->failed_pc=0x0c07ab72u; return 0; }
r[4]=0x00000018u;
goto P_0c07ab74;
P_0c07ab74: /* original a53c, guest PC 0x0c07ab74 */
if(!s->budget--) { s->failed_pc=0x0c07ab74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b5f0;
P_0c07ab76: /* original 4f26, guest PC 0x0c07ab76 */
if(!s->budget--) { s->failed_pc=0x0c07ab76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ab78;
P_0c07ab78: /* original 8814, guest PC 0x0c07ab78 */
if(!s->budget--) { s->failed_pc=0x0c07ab78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c07ab7a;
P_0c07ab7a: /* original 8b02, guest PC 0x0c07ab7a */
if(!s->budget--) { s->failed_pc=0x0c07ab7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab82; }
goto P_0c07ab7c;
P_0c07ab7c: /* original b538, guest PC 0x0c07ab7c */
if(!s->budget--) { s->failed_pc=0x0c07ab7cu; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab80u) { target=s->pc; goto dispatch; }
goto P_0c07ab80;
P_0c07ab7e: /* original 0009, guest PC 0x0c07ab7e */
if(!s->budget--) { s->failed_pc=0x0c07ab7eu; return 0; }
goto P_0c07ab80;
P_0c07ab80: /* original e422, guest PC 0x0c07ab80 */
if(!s->budget--) { s->failed_pc=0x0c07ab80u; return 0; }
r[4]=0x00000022u;
goto P_0c07ab82;
P_0c07ab82: /* original a535, guest PC 0x0c07ab82 */
if(!s->budget--) { s->failed_pc=0x0c07ab82u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b5f0;
P_0c07ab84: /* original 4f26, guest PC 0x0c07ab84 */
if(!s->budget--) { s->failed_pc=0x0c07ab84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c07ab86u,s,ram);
P_0c07ab94: /* original 4f22, guest PC 0x0c07ab94 */
if(!s->budget--) { s->failed_pc=0x0c07ab94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ab96;
P_0c07ab96: /* original dc13, guest PC 0x0c07ab96 */
if(!s->budget--) { s->failed_pc=0x0c07ab96u; return 0; }
r[12]=read(ram,0x0c07abe4u,4);
goto P_0c07ab98;
P_0c07ab98: /* original da11, guest PC 0x0c07ab98 */
if(!s->budget--) { s->failed_pc=0x0c07ab98u; return 0; }
r[10]=read(ram,0x0c07abe0u,4);
goto P_0c07ab9a;
P_0c07ab9a: /* original a015, guest PC 0x0c07ab9a */
if(!s->budget--) { s->failed_pc=0x0c07ab9au; return 0; }
r[14]=0x0000000au;
goto P_0c07abc8;
P_0c07ab9c: /* original ee0a, guest PC 0x0c07ab9c */
if(!s->budget--) { s->failed_pc=0x0c07ab9cu; return 0; }
r[14]=0x0000000au;
goto P_0c07ab9e;
P_0c07ab9e: /* original 64ed, guest PC 0x0c07ab9e */
if(!s->budget--) { s->failed_pc=0x0c07ab9eu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07aba0;
P_0c07aba0: /* original 6043, guest PC 0x0c07aba0 */
if(!s->budget--) { s->failed_pc=0x0c07aba0u; return 0; }
r[0]=r[4];
goto P_0c07aba2;
P_0c07aba2: /* original 8805, guest PC 0x0c07aba2 */
if(!s->budget--) { s->failed_pc=0x0c07aba2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07aba4;
P_0c07aba4: /* original 890f, guest PC 0x0c07aba4 */
if(!s->budget--) { s->failed_pc=0x0c07aba4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07abc6; }
goto P_0c07aba6;
P_0c07aba6: /* original 6043, guest PC 0x0c07aba6 */
if(!s->budget--) { s->failed_pc=0x0c07aba6u; return 0; }
r[0]=r[4];
goto P_0c07aba8;
P_0c07aba8: /* original 8808, guest PC 0x0c07aba8 */
if(!s->budget--) { s->failed_pc=0x0c07aba8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07abaa;
P_0c07abaa: /* original 890c, guest PC 0x0c07abaa */
if(!s->budget--) { s->failed_pc=0x0c07abaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07abc6; }
goto P_0c07abac;
P_0c07abac: /* original 6043, guest PC 0x0c07abac */
if(!s->budget--) { s->failed_pc=0x0c07abacu; return 0; }
r[0]=r[4];
goto P_0c07abae;
P_0c07abae: /* original 8809, guest PC 0x0c07abae */
if(!s->budget--) { s->failed_pc=0x0c07abaeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07abb0;
P_0c07abb0: /* original 8909, guest PC 0x0c07abb0 */
if(!s->budget--) { s->failed_pc=0x0c07abb0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07abc6; }
goto P_0c07abb2;
P_0c07abb2: /* original 64ed, guest PC 0x0c07abb2 */
if(!s->budget--) { s->failed_pc=0x0c07abb2u; return 0; }
r[4]=r[14]&65535u;
goto P_0c07abb4;
P_0c07abb4: /* original 4400, guest PC 0x0c07abb4 */
if(!s->budget--) { s->failed_pc=0x0c07abb4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07abb6;
P_0c07abb6: /* original 34ac, guest PC 0x0c07abb6 */
if(!s->budget--) { s->failed_pc=0x0c07abb6u; return 0; }
r[4]+=r[10];
goto P_0c07abb8;
P_0c07abb8: /* original 6341, guest PC 0x0c07abb8 */
if(!s->budget--) { s->failed_pc=0x0c07abb8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07abba;
P_0c07abba: /* original 633d, guest PC 0x0c07abba */
if(!s->budget--) { s->failed_pc=0x0c07abbau; return 0; }
r[3]=r[3]&65535u;
goto P_0c07abbc;
P_0c07abbc: /* original 33c0, guest PC 0x0c07abbc */
if(!s->budget--) { s->failed_pc=0x0c07abbcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[12])!=0);
goto P_0c07abbe;
P_0c07abbe: /* original 8b00, guest PC 0x0c07abbe */
if(!s->budget--) { s->failed_pc=0x0c07abbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07abc2; }
goto P_0c07abc0;
P_0c07abc0: /* original 24d1, guest PC 0x0c07abc0 */
if(!s->budget--) { s->failed_pc=0x0c07abc0u; return 0; }
write(ram,r[4],r[13],2);
goto P_0c07abc2;
P_0c07abc2: /* original bfa7, guest PC 0x0c07abc2 */
if(!s->budget--) { s->failed_pc=0x0c07abc2u; return 0; }
target=0x0c07ab14u; r[16]=0x0c07abc6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07abc6u) { target=s->pc; goto dispatch; }
goto P_0c07abc6;
P_0c07abc4: /* original 64e3, guest PC 0x0c07abc4 */
if(!s->budget--) { s->failed_pc=0x0c07abc4u; return 0; }
r[4]=r[14];
goto P_0c07abc6;
P_0c07abc6: /* original 7e01, guest PC 0x0c07abc6 */
if(!s->budget--) { s->failed_pc=0x0c07abc6u; return 0; }
r[14]+=0x00000001u;
goto P_0c07abc8;
P_0c07abc8: /* original 62ed, guest PC 0x0c07abc8 */
if(!s->budget--) { s->failed_pc=0x0c07abc8u; return 0; }
r[2]=r[14]&65535u;
goto P_0c07abca;
P_0c07abca: /* original 32b7, guest PC 0x0c07abca */
if(!s->budget--) { s->failed_pc=0x0c07abcau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[11])!=0);
goto P_0c07abcc;
P_0c07abcc: /* original 8be7, guest PC 0x0c07abcc */
if(!s->budget--) { s->failed_pc=0x0c07abccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab9e; }
goto P_0c07abce;
P_0c07abce: /* original 4f26, guest PC 0x0c07abce */
if(!s->budget--) { s->failed_pc=0x0c07abceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07abd0;
P_0c07abd0: /* original 6af6, guest PC 0x0c07abd0 */
if(!s->budget--) { s->failed_pc=0x0c07abd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07abd2;
P_0c07abd2: /* original 6bf6, guest PC 0x0c07abd2 */
if(!s->budget--) { s->failed_pc=0x0c07abd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07abd4;
P_0c07abd4: /* original 6cf6, guest PC 0x0c07abd4 */
if(!s->budget--) { s->failed_pc=0x0c07abd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07abd6;
P_0c07abd6: /* original 6df6, guest PC 0x0c07abd6 */
if(!s->budget--) { s->failed_pc=0x0c07abd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07abd8;
P_0c07abd8: /* original 000b, guest PC 0x0c07abd8 */
if(!s->budget--) { s->failed_pc=0x0c07abd8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07abda: /* original 6ef6, guest PC 0x0c07abda */
if(!s->budget--) { s->failed_pc=0x0c07abdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07abdcu,s,ram);
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c07b5ceu,s,ram);
P_0c07b5f0: /* original 2fe6, guest PC 0x0c07b5f0 */
if(!s->budget--) { s->failed_pc=0x0c07b5f0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07b5f2;
P_0c07b5f2: /* original 2fd6, guest PC 0x0c07b5f2 */
if(!s->budget--) { s->failed_pc=0x0c07b5f2u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c07b5f4;
P_0c07b5f4: /* original 6d43, guest PC 0x0c07b5f4 */
if(!s->budget--) { s->failed_pc=0x0c07b5f4u; return 0; }
r[13]=r[4];
goto P_0c07b5f6;
P_0c07b5f6: /* original 2fc6, guest PC 0x0c07b5f6 */
if(!s->budget--) { s->failed_pc=0x0c07b5f6u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c07b5f8;
P_0c07b5f8: /* original 4f22, guest PC 0x0c07b5f8 */
if(!s->budget--) { s->failed_pc=0x0c07b5f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b5fa;
P_0c07b5fa: /* original d22a, guest PC 0x0c07b5fa */
if(!s->budget--) { s->failed_pc=0x0c07b5fau; return 0; }
r[2]=read(ram,0x0c07b6a4u,4);
goto P_0c07b5fc;
P_0c07b5fc: /* original d32a, guest PC 0x0c07b5fc */
if(!s->budget--) { s->failed_pc=0x0c07b5fcu; return 0; }
r[3]=read(ram,0x0c07b6a8u,4);
goto P_0c07b5fe;
P_0c07b5fe: /* original 7fe0, guest PC 0x0c07b5fe */
if(!s->budget--) { s->failed_pc=0x0c07b5feu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07b600;
P_0c07b600: /* original 61f3, guest PC 0x0c07b600 */
if(!s->budget--) { s->failed_pc=0x0c07b600u; return 0; }
r[1]=r[15];
goto P_0c07b602;
P_0c07b602: /* original 430b, guest PC 0x0c07b602 */
if(!s->budget--) { s->failed_pc=0x0c07b602u; return 0; }
target=r[3];
r[16]=0x0c07b606u;
r[0]=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b606u) { target=s->pc; goto dispatch; }
goto P_0c07b606;
P_0c07b604: /* original e020, guest PC 0x0c07b604 */
if(!s->budget--) { s->failed_pc=0x0c07b604u; return 0; }
r[0]=0x00000020u;
goto P_0c07b606;
P_0c07b606: /* original 9149, guest PC 0x0c07b606 */
if(!s->budget--) { s->failed_pc=0x0c07b606u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69cu,2);
goto P_0c07b608;
P_0c07b608: /* original 6edd, guest PC 0x0c07b608 */
if(!s->budget--) { s->failed_pc=0x0c07b608u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b60a;
P_0c07b60a: /* original 21e8, guest PC 0x0c07b60a */
if(!s->budget--) { s->failed_pc=0x0c07b60au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c07b60c;
P_0c07b60c: /* original 8b29, guest PC 0x0c07b60c */
if(!s->budget--) { s->failed_pc=0x0c07b60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b60e;
P_0c07b60e: /* original d227, guest PC 0x0c07b60e */
if(!s->budget--) { s->failed_pc=0x0c07b60eu; return 0; }
r[2]=read(ram,0x0c07b6acu,4);
goto P_0c07b610;
P_0c07b610: /* original 22e8, guest PC 0x0c07b610 */
if(!s->budget--) { s->failed_pc=0x0c07b610u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c07b612;
P_0c07b612: /* original 8b26, guest PC 0x0c07b612 */
if(!s->budget--) { s->failed_pc=0x0c07b612u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b614;
P_0c07b614: /* original 60e3, guest PC 0x0c07b614 */
if(!s->budget--) { s->failed_pc=0x0c07b614u; return 0; }
r[0]=r[14];
goto P_0c07b616;
P_0c07b616: /* original dc26, guest PC 0x0c07b616 */
if(!s->budget--) { s->failed_pc=0x0c07b616u; return 0; }
r[12]=read(ram,0x0c07b6b0u,4);
goto P_0c07b618;
P_0c07b618: /* original 8807, guest PC 0x0c07b618 */
if(!s->budget--) { s->failed_pc=0x0c07b618u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c07b61a;
P_0c07b61a: /* original 8b02, guest PC 0x0c07b61a */
if(!s->budget--) { s->failed_pc=0x0c07b61au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b622; }
goto P_0c07b61c;
P_0c07b61c: /* original 953f, guest PC 0x0c07b61c */
if(!s->budget--) { s->failed_pc=0x0c07b61cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b61e;
P_0c07b61e: /* original 4c0b, guest PC 0x0c07b61e */
if(!s->budget--) { s->failed_pc=0x0c07b61eu; return 0; }
target=r[12];
r[16]=0x0c07b622u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b622u) { target=s->pc; goto dispatch; }
goto P_0c07b622;
P_0c07b620: /* original e401, guest PC 0x0c07b620 */
if(!s->budget--) { s->failed_pc=0x0c07b620u; return 0; }
r[4]=0x00000001u;
goto P_0c07b622;
P_0c07b622: /* original 60e3, guest PC 0x0c07b622 */
if(!s->budget--) { s->failed_pc=0x0c07b622u; return 0; }
r[0]=r[14];
goto P_0c07b624;
P_0c07b624: /* original 8805, guest PC 0x0c07b624 */
if(!s->budget--) { s->failed_pc=0x0c07b624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07b626;
P_0c07b626: /* original 8b02, guest PC 0x0c07b626 */
if(!s->budget--) { s->failed_pc=0x0c07b626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b62e; }
goto P_0c07b628;
P_0c07b628: /* original 953a, guest PC 0x0c07b628 */
if(!s->budget--) { s->failed_pc=0x0c07b628u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b6a0u,2);
goto P_0c07b62a;
P_0c07b62a: /* original 4c0b, guest PC 0x0c07b62a */
if(!s->budget--) { s->failed_pc=0x0c07b62au; return 0; }
target=r[12];
r[16]=0x0c07b62eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b62eu) { target=s->pc; goto dispatch; }
goto P_0c07b62e;
P_0c07b62c: /* original e401, guest PC 0x0c07b62c */
if(!s->budget--) { s->failed_pc=0x0c07b62cu; return 0; }
r[4]=0x00000001u;
goto P_0c07b62e;
P_0c07b62e: /* original d021, guest PC 0x0c07b62e */
if(!s->budget--) { s->failed_pc=0x0c07b62eu; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b630;
P_0c07b630: /* original 64dd, guest PC 0x0c07b630 */
if(!s->budget--) { s->failed_pc=0x0c07b630u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b632;
P_0c07b632: /* original 4400, guest PC 0x0c07b632 */
if(!s->budget--) { s->failed_pc=0x0c07b632u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b634;
P_0c07b634: /* original 044d, guest PC 0x0c07b634 */
if(!s->budget--) { s->failed_pc=0x0c07b634u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07b636;
P_0c07b636: /* original 644d, guest PC 0x0c07b636 */
if(!s->budget--) { s->failed_pc=0x0c07b636u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b638;
P_0c07b638: /* original 2448, guest PC 0x0c07b638 */
if(!s->budget--) { s->failed_pc=0x0c07b638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b63a;
P_0c07b63a: /* original 8912, guest PC 0x0c07b63a */
if(!s->budget--) { s->failed_pc=0x0c07b63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b63c;
P_0c07b63c: /* original d21e, guest PC 0x0c07b63c */
if(!s->budget--) { s->failed_pc=0x0c07b63cu; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b63e;
P_0c07b63e: /* original 3420, guest PC 0x0c07b63e */
if(!s->budget--) { s->failed_pc=0x0c07b63eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07b640;
P_0c07b640: /* original 890f, guest PC 0x0c07b640 */
if(!s->budget--) { s->failed_pc=0x0c07b640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b642;
P_0c07b642: /* original d21e, guest PC 0x0c07b642 */
if(!s->budget--) { s->failed_pc=0x0c07b642u; return 0; }
r[2]=read(ram,0x0c07b6bcu,4);
goto P_0c07b644;
P_0c07b644: /* original 420b, guest PC 0x0c07b644 */
if(!s->budget--) { s->failed_pc=0x0c07b644u; return 0; }
target=r[2];
r[16]=0x0c07b648u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b648u) { target=s->pc; goto dispatch; }
goto P_0c07b648;
P_0c07b646: /* original 0009, guest PC 0x0c07b646 */
if(!s->budget--) { s->failed_pc=0x0c07b646u; return 0; }
goto P_0c07b648;
P_0c07b648: /* original d31d, guest PC 0x0c07b648 */
if(!s->budget--) { s->failed_pc=0x0c07b648u; return 0; }
r[3]=read(ram,0x0c07b6c0u,4);
goto P_0c07b64a;
P_0c07b64a: /* original 430b, guest PC 0x0c07b64a */
if(!s->budget--) { s->failed_pc=0x0c07b64au; return 0; }
target=r[3];
r[16]=0x0c07b64eu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b64eu) { target=s->pc; goto dispatch; }
goto P_0c07b64e;
P_0c07b64c: /* original 64f3, guest PC 0x0c07b64c */
if(!s->budget--) { s->failed_pc=0x0c07b64cu; return 0; }
r[4]=r[15];
goto P_0c07b64e;
P_0c07b64e: /* original 2008, guest PC 0x0c07b64e */
if(!s->budget--) { s->failed_pc=0x0c07b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b650;
P_0c07b650: /* original 8902, guest PC 0x0c07b650 */
if(!s->budget--) { s->failed_pc=0x0c07b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b658; }
goto P_0c07b652;
P_0c07b652: /* original 9524, guest PC 0x0c07b652 */
if(!s->budget--) { s->failed_pc=0x0c07b652u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b654;
P_0c07b654: /* original 4c0b, guest PC 0x0c07b654 */
if(!s->budget--) { s->failed_pc=0x0c07b654u; return 0; }
target=r[12];
r[16]=0x0c07b658u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b658u) { target=s->pc; goto dispatch; }
goto P_0c07b658;
P_0c07b656: /* original e401, guest PC 0x0c07b656 */
if(!s->budget--) { s->failed_pc=0x0c07b656u; return 0; }
r[4]=0x00000001u;
goto P_0c07b658;
P_0c07b658: /* original d016, guest PC 0x0c07b658 */
if(!s->budget--) { s->failed_pc=0x0c07b658u; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b65a;
P_0c07b65a: /* original 6ddd, guest PC 0x0c07b65a */
if(!s->budget--) { s->failed_pc=0x0c07b65au; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b65c;
P_0c07b65c: /* original e300, guest PC 0x0c07b65c */
if(!s->budget--) { s->failed_pc=0x0c07b65cu; return 0; }
r[3]=0x00000000u;
goto P_0c07b65e;
P_0c07b65e: /* original 4d00, guest PC 0x0c07b65e */
if(!s->budget--) { s->failed_pc=0x0c07b65eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b660;
P_0c07b660: /* original 0d35, guest PC 0x0c07b660 */
if(!s->budget--) { s->failed_pc=0x0c07b660u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b662;
P_0c07b662: /* original 7f20, guest PC 0x0c07b662 */
if(!s->budget--) { s->failed_pc=0x0c07b662u; return 0; }
r[15]+=0x00000020u;
goto P_0c07b664;
P_0c07b664: /* original 4f26, guest PC 0x0c07b664 */
if(!s->budget--) { s->failed_pc=0x0c07b664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b666;
P_0c07b666: /* original 6cf6, guest PC 0x0c07b666 */
if(!s->budget--) { s->failed_pc=0x0c07b666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b668;
P_0c07b668: /* original 6df6, guest PC 0x0c07b668 */
if(!s->budget--) { s->failed_pc=0x0c07b668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b66a;
P_0c07b66a: /* original 000b, guest PC 0x0c07b66a */
if(!s->budget--) { s->failed_pc=0x0c07b66au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b66c: /* original 6ef6, guest PC 0x0c07b66c */
if(!s->budget--) { s->failed_pc=0x0c07b66cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07b66eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0365d4u,0x0c0365d6u,0x0c0365d8u,0x0c0365dau,0x0c0365dcu,0x0c0365deu,0x0c0365e0u,0x0c0365e2u,0x0c0365e4u,0x0c0365e6u,0x0c0365e8u,0x0c0365eau,0x0c0365ecu,0x0c0365eeu,0x0c0365f0u,0x0c0365f2u,
0x0c0365f4u,0x0c0365f6u,0x0c0365f8u,0x0c0365fau,0x0c0365fcu,0x0c0365feu,0x0c036600u,0x0c03665eu,0x0c036660u,0x0c036662u,0x0c036664u,0x0c036666u,0x0c036668u,0x0c03666au,0x0c03666cu,0x0c038760u,
0x0c038762u,0x0c038764u,0x0c03f690u,0x0c03f692u,0x0c03f694u,0x0c03f696u,0x0c03f698u,0x0c03f69au,0x0c03f69cu,0x0c03f69eu,0x0c03f6a0u,0x0c03f6a2u,0x0c03f6a4u,0x0c03f6a6u,0x0c03f6a8u,0x0c03f6aau,
0x0c03f6acu,0x0c03f6aeu,0x0c03f6b0u,0x0c03f6b2u,0x0c03f6b4u,0x0c03f6b6u,0x0c03f6b8u,0x0c03f6c0u,0x0c03f6c2u,0x0c03f6c4u,0x0c03f6c6u,0x0c03f6c8u,0x0c03f6cau,0x0c03f6ccu,0x0c03f6ceu,0x0c03f6d0u,
0x0c03f6d2u,0x0c03f6d4u,0x0c03f6d6u,0x0c03f6d8u,0x0c03f6dau,0x0c03f6dcu,0x0c03f6deu,0x0c03f6e0u,0x0c03f6e2u,0x0c03f6e4u,0x0c03f6e6u,0x0c03f6e8u,0x0c03f6eau,0x0c03f6ecu,0x0c03f6eeu,0x0c03f6f0u,
0x0c03f6f2u,0x0c03f6f4u,0x0c03f6f6u,0x0c03f6f8u,0x0c03f6fau,0x0c03f6fcu,0x0c03f6feu,0x0c03f700u,0x0c03f702u,0x0c03f704u,0x0c03f706u,0x0c03f708u,0x0c03f70au,0x0c03f70cu,0x0c03f70eu,0x0c03f710u,
0x0c03f712u,0x0c03f714u,0x0c03f716u,0x0c03f718u,0x0c03f71au,0x0c03f71cu,0x0c03f71eu,0x0c03f720u,0x0c03f722u,0x0c03f724u,0x0c03f726u,0x0c03f728u,0x0c03f72au,0x0c03f72cu,0x0c03f72eu,0x0c03f730u,
0x0c03f732u,0x0c03f734u,0x0c03f736u,0x0c03f738u,0x0c03f73au,0x0c03f73cu,0x0c03f73eu,0x0c03f740u,0x0c03f742u,0x0c03f744u,0x0c03f746u,0x0c03f748u,0x0c03f74au,0x0c03f74cu,0x0c03f74eu,0x0c03f750u,
0x0c03f752u,0x0c03f754u,0x0c03f756u,0x0c03f758u,0x0c03f75au,0x0c03f75cu,0x0c03f75eu,0x0c03f760u,0x0c03f762u,0x0c03f764u,0x0c03fda0u,0x0c03fda2u,0x0c03fda4u,0x0c03fda6u,0x0c03fda8u,0x0c03fdaau,
0x0c03fdacu,0x0c03fdaeu,0x0c03fdb0u,0x0c03fdb2u,0x0c03fdb4u,0x0c03fdb6u,0x0c03fdb8u,0x0c03fdbau,0x0c03fdbcu,0x0c042efcu,0x0c042efeu,0x0c042f00u,0x0c042f02u,0x0c042f04u,0x0c042f06u,0x0c042f3au,
0x0c042f3cu,0x0c042f3eu,0x0c042f40u,0x0c042f42u,0x0c042f44u,0x0c042f46u,0x0c042f48u,0x0c042f4au,0x0c042f4cu,0x0c042f4eu,0x0c042f50u,0x0c042f52u,0x0c042f54u,0x0c042f56u,0x0c042f58u,0x0c042f5au,
0x0c043eb8u,0x0c043ebau,0x0c043ebcu,0x0c043ebeu,0x0c043ec0u,0x0c043ec2u,0x0c043ec4u,0x0c043ec6u,0x0c043ec8u,0x0c043ecau,0x0c043eccu,0x0c043eceu,0x0c043ed0u,0x0c043ed2u,0x0c043ed4u,0x0c043ed6u,
0x0c043ed8u,0x0c0441aau,0x0c0441acu,0x0c0441aeu,0x0c053cecu,0x0c053ceeu,0x0c053cf0u,0x0c053cf2u,0x0c053cf4u,0x0c053cf6u,0x0c053cf8u,0x0c053cfau,0x0c053cfcu,0x0c053cfeu,0x0c053d00u,0x0c053d02u,
0x0c053d04u,0x0c053d06u,0x0c053d08u,0x0c053d0au,0x0c053d0cu,0x0c053d0eu,0x0c053d10u,0x0c053d12u,0x0c053d14u,0x0c053d16u,0x0c053d18u,0x0c053d1au,0x0c053d1cu,0x0c053d1eu,0x0c053d20u,0x0c053d22u,
0x0c053d24u,0x0c053d26u,0x0c053d28u,0x0c053d2au,0x0c053d2cu,0x0c053d2eu,0x0c05ece2u,0x0c05ece4u,0x0c05ece6u,0x0c05ece8u,0x0c05eceau,0x0c05ececu,0x0c05eceeu,0x0c05ecf0u,0x0c05ecf2u,0x0c05ecf4u,
0x0c05ecf6u,0x0c05ecf8u,0x0c05ecfau,0x0c05ecfcu,0x0c05ecfeu,0x0c05ed00u,0x0c05ed02u,0x0c05ed04u,0x0c061596u,0x0c061598u,0x0c06159au,0x0c06159cu,0x0c06159eu,0x0c0615a0u,0x0c0615a2u,0x0c0615a4u,
0x0c0615a6u,0x0c0615a8u,0x0c0615aau,0x0c0615acu,0x0c0615aeu,0x0c0615b0u,0x0c0615b2u,0x0c0615b4u,0x0c0615b6u,0x0c0615b8u,0x0c0615bau,0x0c0615bcu,0x0c0615beu,0x0c0615c0u,0x0c0615c2u,0x0c0615c4u,
0x0c0615c6u,0x0c0615c8u,0x0c0615cau,0x0c0615ccu,0x0c0615ceu,0x0c0615d0u,0x0c0615d2u,0x0c0615d4u,0x0c0615d6u,0x0c0615d8u,0x0c0615dau,0x0c0615dcu,0x0c0615deu,0x0c061608u,0x0c06160au,0x0c06160cu,
0x0c06160eu,0x0c061610u,0x0c061612u,0x0c061614u,0x0c061616u,0x0c061618u,0x0c06161au,0x0c06161cu,0x0c06161eu,0x0c061620u,0x0c061622u,0x0c061624u,0x0c061626u,0x0c061628u,0x0c06162au,0x0c06162cu,
0x0c06162eu,0x0c061630u,0x0c061632u,0x0c061634u,0x0c061636u,0x0c061638u,0x0c06163au,0x0c06163cu,0x0c06163eu,0x0c061640u,0x0c061642u,0x0c061674u,0x0c061676u,0x0c061678u,0x0c06167au,0x0c06167cu,
0x0c06167eu,0x0c061680u,0x0c061682u,0x0c061684u,0x0c061686u,0x0c061688u,0x0c06168au,0x0c06168cu,0x0c06168eu,0x0c061690u,0x0c061692u,0x0c061694u,0x0c061696u,0x0c061698u,0x0c06169au,0x0c06169cu,
0x0c06169eu,0x0c0616a0u,0x0c0616a2u,0x0c0616a4u,0x0c0616a6u,0x0c0616a8u,0x0c0616aau,0x0c0616acu,0x0c0616aeu,0x0c0616b0u,0x0c0616b2u,0x0c0616b4u,0x0c0616b6u,0x0c0616b8u,0x0c0616bau,0x0c0616bcu,
0x0c0616beu,0x0c0616c0u,0x0c0616c2u,0x0c0616c4u,0x0c0616c6u,0x0c0616c8u,0x0c0616cau,0x0c0616ccu,0x0c0616ceu,0x0c0616d0u,0x0c0616d2u,0x0c0616d4u,0x0c0616d6u,0x0c0616d8u,0x0c0616dau,0x0c0616dcu,
0x0c0616deu,0x0c0616e0u,0x0c0616e2u,0x0c0616e4u,0x0c0616e6u,0x0c0616e8u,0x0c0616eau,0x0c0616ecu,0x0c0616eeu,0x0c0616f0u,0x0c0616f2u,0x0c0616f4u,0x0c0616f6u,0x0c0616f8u,0x0c0616fau,0x0c0616fcu,
0x0c0616feu,0x0c061700u,0x0c061702u,0x0c061704u,0x0c061706u,0x0c061708u,0x0c06170au,0x0c06170cu,0x0c06170eu,0x0c061710u,0x0c061712u,0x0c061714u,0x0c061716u,0x0c061718u,0x0c06171au,0x0c06171cu,
0x0c06171eu,0x0c061720u,0x0c061722u,0x0c061724u,0x0c061726u,0x0c061728u,0x0c06172au,0x0c06172cu,0x0c06172eu,0x0c061730u,0x0c061732u,0x0c061734u,0x0c061736u,0x0c061738u,0x0c06173au,0x0c06173cu,
0x0c06173eu,0x0c061740u,0x0c061742u,0x0c061744u,0x0c061746u,0x0c06233eu,0x0c062340u,0x0c062342u,0x0c062344u,0x0c062346u,0x0c062348u,0x0c06234au,0x0c06234cu,0x0c06234eu,0x0c062350u,0x0c062352u,
0x0c062354u,0x0c062356u,0x0c062358u,0x0c06235au,0x0c06235cu,0x0c06235eu,0x0c062360u,0x0c062362u,0x0c062364u,0x0c062366u,0x0c062368u,0x0c06236au,0x0c06236cu,0x0c06236eu,0x0c062370u,0x0c062372u,
0x0c062374u,0x0c062376u,0x0c062378u,0x0c06237au,0x0c062390u,0x0c062392u,0x0c062394u,0x0c062396u,0x0c062398u,0x0c06239au,0x0c06239cu,0x0c06239eu,0x0c0623a0u,0x0c0623a2u,0x0c0623a4u,0x0c0623a6u,
0x0c0623a8u,0x0c0623aau,0x0c0623acu,0x0c0623aeu,0x0c0623b0u,0x0c0623b2u,0x0c0623b4u,0x0c0623b6u,0x0c0623b8u,0x0c0623bau,0x0c0623bcu,0x0c0623beu,0x0c0623c0u,0x0c0623c2u,0x0c0623c4u,0x0c0623c6u,
0x0c0623c8u,0x0c0623cau,0x0c0623ccu,0x0c0623ceu,0x0c0623d0u,0x0c0623d2u,0x0c0623d4u,0x0c0623d6u,0x0c0623d8u,0x0c0623dau,0x0c0623dcu,0x0c0623deu,0x0c0623e0u,0x0c0623e2u,0x0c0623e4u,0x0c0623e6u,
0x0c0623e8u,0x0c0623eau,0x0c0623ecu,0x0c0623eeu,0x0c0623f0u,0x0c0623f2u,0x0c0623f4u,0x0c0623f6u,0x0c0623f8u,0x0c0623fau,0x0c0623fcu,0x0c0623feu,0x0c062400u,0x0c062402u,0x0c062404u,0x0c062406u,
0x0c062408u,0x0c06240au,0x0c06240cu,0x0c06240eu,0x0c062410u,0x0c062412u,0x0c062414u,0x0c062416u,0x0c062418u,0x0c06241au,0x0c06241cu,0x0c06241eu,0x0c062420u,0x0c062422u,0x0c062424u,0x0c062426u,
0x0c062428u,0x0c06242au,0x0c06242cu,0x0c06242eu,0x0c062430u,0x0c062432u,0x0c062434u,0x0c062436u,0x0c062438u,0x0c06243au,0x0c06243cu,0x0c06243eu,0x0c062440u,0x0c062442u,0x0c062444u,0x0c062446u,
0x0c062448u,0x0c06244au,0x0c06244cu,0x0c06244eu,0x0c062450u,0x0c062452u,0x0c062454u,0x0c062456u,0x0c062458u,0x0c06245au,0x0c06245cu,0x0c06245eu,0x0c062460u,0x0c062462u,0x0c062464u,0x0c062466u,
0x0c062468u,0x0c06246au,0x0c06246cu,0x0c06246eu,0x0c062470u,0x0c062472u,0x0c062474u,0x0c062476u,0x0c062478u,0x0c06247au,0x0c06247cu,0x0c06247eu,0x0c062480u,0x0c062482u,0x0c062484u,0x0c062486u,
0x0c062c24u,0x0c062c26u,0x0c062c28u,0x0c062c2au,0x0c062c2cu,0x0c062c2eu,0x0c062c30u,0x0c062c32u,0x0c062c34u,0x0c062c36u,0x0c062c38u,0x0c062c3au,0x0c062c3cu,0x0c062c3eu,0x0c062c40u,0x0c062c42u,
0x0c062c44u,0x0c062c46u,0x0c062c48u,0x0c062c4au,0x0c062c4cu,0x0c070c58u,0x0c070c5au,0x0c070c5cu,0x0c070c5eu,0x0c070c60u,0x0c070c62u,0x0c070c64u,0x0c070c66u,0x0c070c68u,0x0c070c6au,0x0c070c6cu,
0x0c070c6eu,0x0c070c70u,0x0c070c72u,0x0c070c74u,0x0c070c76u,0x0c070c78u,0x0c070c7au,0x0c070c7cu,0x0c070c7eu,0x0c070c80u,0x0c070c82u,0x0c070c84u,0x0c070c86u,0x0c070c88u,0x0c070c90u,0x0c070c92u,
0x0c070c94u,0x0c070c96u,0x0c070c98u,0x0c070c9au,0x0c070c9cu,0x0c070c9eu,0x0c070ca0u,0x0c070ca2u,0x0c070ca4u,0x0c070ca6u,0x0c070ca8u,0x0c070caau,0x0c070cacu,0x0c070caeu,0x0c070cb0u,0x0c070cb2u,
0x0c070cb4u,0x0c070cb6u,0x0c070cb8u,0x0c070cbau,0x0c070cbcu,0x0c070cbeu,0x0c070cc0u,0x0c070cc2u,0x0c070cc4u,0x0c070cc6u,0x0c070cc8u,0x0c070ccau,0x0c070cccu,0x0c070cceu,0x0c070cd0u,0x0c070cd2u,
0x0c070cd4u,0x0c070cd6u,0x0c070cd8u,0x0c070cdau,0x0c070cdcu,0x0c070cdeu,0x0c070ce0u,0x0c070ce2u,0x0c070ce4u,0x0c070ce6u,0x0c070ce8u,0x0c070ceau,0x0c070cecu,0x0c070ceeu,0x0c070cf0u,0x0c070cf2u,
0x0c070cf4u,0x0c070cf6u,0x0c070cf8u,0x0c070cfau,0x0c070cfcu,0x0c070cfeu,0x0c070d00u,0x0c070d02u,0x0c070d04u,0x0c070d06u,0x0c070d08u,0x0c070d0au,0x0c070d0cu,0x0c070d0eu,0x0c070d10u,0x0c070d12u,
0x0c070d14u,0x0c070d16u,0x0c070d18u,0x0c070d1au,0x0c070d1cu,0x0c070d1eu,0x0c070d24u,0x0c070d26u,0x0c070d28u,0x0c070d2au,0x0c070d2cu,0x0c070d2eu,0x0c070d30u,0x0c070d32u,0x0c070d34u,0x0c070d36u,
0x0c070d38u,0x0c070d3au,0x0c070d3cu,0x0c070d3eu,0x0c070d40u,0x0c070d42u,0x0c070d44u,0x0c070d46u,0x0c070d48u,0x0c070d4au,0x0c070d4cu,0x0c070d4eu,0x0c070d50u,0x0c070d52u,0x0c070d54u,0x0c070d56u,
0x0c070d58u,0x0c070d5au,0x0c070d5cu,0x0c070d5eu,0x0c070d60u,0x0c070d62u,0x0c070d64u,0x0c070d66u,0x0c070d68u,0x0c070d6au,0x0c070d70u,0x0c070d72u,0x0c070d74u,0x0c070d76u,0x0c070d78u,0x0c070d7au,
0x0c070d7cu,0x0c070d7eu,0x0c070d80u,0x0c070d82u,0x0c070d84u,0x0c070d86u,0x0c070d88u,0x0c070d8au,0x0c070d8cu,0x0c070d8eu,0x0c070d90u,0x0c070d92u,0x0c070d94u,0x0c070d96u,0x0c070d98u,0x0c070d9au,
0x0c070d9cu,0x0c070d9eu,0x0c070da0u,0x0c070da2u,0x0c070da4u,0x0c070da6u,0x0c070da8u,0x0c070db4u,0x0c070db6u,0x0c070db8u,0x0c070dbau,0x0c070dbcu,0x0c070dbeu,0x0c070dc0u,0x0c070dc2u,0x0c070dc4u,
0x0c070dc6u,0x0c070dc8u,0x0c070dcau,0x0c070dccu,0x0c070dceu,0x0c070dd0u,0x0c070dd2u,0x0c070dd4u,0x0c071090u,0x0c071092u,0x0c071094u,0x0c071096u,0x0c071098u,0x0c07109au,0x0c07109cu,0x0c07109eu,
0x0c0710a0u,0x0c0710a2u,0x0c0710a4u,0x0c0710a6u,0x0c0710a8u,0x0c0710aau,0x0c0710acu,0x0c0710aeu,0x0c0710b0u,0x0c0710b2u,0x0c0710b4u,0x0c0710b6u,0x0c0710b8u,0x0c0710bau,0x0c0710bcu,0x0c0710beu,
0x0c0710c0u,0x0c0710c8u,0x0c0710cau,0x0c0710ccu,0x0c0710ceu,0x0c0710d0u,0x0c0710d2u,0x0c0710d4u,0x0c0710d6u,0x0c0710d8u,0x0c0710dau,0x0c0710dcu,0x0c0710deu,0x0c0710e0u,0x0c0710e2u,0x0c0710e4u,
0x0c0710e6u,0x0c0710e8u,0x0c0710eau,0x0c0710ecu,0x0c0710eeu,0x0c0710f0u,0x0c0710f2u,0x0c0710f4u,0x0c0710f6u,0x0c0710f8u,0x0c0710fau,0x0c0710fcu,0x0c0710feu,0x0c071100u,0x0c071102u,0x0c071104u,
0x0c071106u,0x0c071108u,0x0c07110au,0x0c07110cu,0x0c07110eu,0x0c071110u,0x0c071112u,0x0c071114u,0x0c071116u,0x0c071118u,0x0c07111au,0x0c07111cu,0x0c07111eu,0x0c071120u,0x0c071122u,0x0c071124u,
0x0c071126u,0x0c071128u,0x0c07112au,0x0c07112cu,0x0c07112eu,0x0c071130u,0x0c071132u,0x0c071134u,0x0c071136u,0x0c071138u,0x0c07113au,0x0c07113cu,0x0c07113eu,0x0c071c0au,0x0c071c0cu,0x0c071c0eu,
0x0c071c10u,0x0c071c12u,0x0c071c14u,0x0c071c16u,0x0c071c18u,0x0c071c1au,0x0c071c1cu,0x0c071c1eu,0x0c071c20u,0x0c071c22u,0x0c071c24u,0x0c071c26u,0x0c071c28u,0x0c071c2au,0x0c071c2cu,0x0c071c2eu,
0x0c071c30u,0x0c071c32u,0x0c071c38u,0x0c071c3au,0x0c071c3cu,0x0c071c3eu,0x0c071c40u,0x0c071c42u,0x0c071c44u,0x0c071c46u,0x0c071c48u,0x0c071c4au,0x0c071c4cu,0x0c071c4eu,0x0c071c50u,0x0c071c52u,
0x0c071c54u,0x0c071c56u,0x0c071c58u,0x0c071c5au,0x0c071c5cu,0x0c071c5eu,0x0c071c60u,0x0c071c62u,0x0c071c64u,0x0c071c66u,0x0c071c68u,0x0c071c6au,0x0c071c6cu,0x0c071c6eu,0x0c071c70u,0x0c071c72u,
0x0c071c74u,0x0c071c76u,0x0c071c78u,0x0c071c7au,0x0c071c7cu,0x0c071c7eu,0x0c071c80u,0x0c071c82u,0x0c071c84u,0x0c071c86u,0x0c071c88u,0x0c071c8au,0x0c071c8cu,0x0c071c8eu,0x0c071c90u,0x0c071c92u,
0x0c071c94u,0x0c071c96u,0x0c071c98u,0x0c071c9au,0x0c071c9cu,0x0c071c9eu,0x0c071ca0u,0x0c071ca2u,0x0c071ca4u,0x0c071ca6u,0x0c071ca8u,0x0c071caau,0x0c071cacu,0x0c071caeu,0x0c071cb0u,0x0c071cb2u,
0x0c071cb4u,0x0c071cb6u,0x0c071cb8u,0x0c071cbau,0x0c071cbcu,0x0c071cbeu,0x0c071cc0u,0x0c071cc2u,0x0c071cc4u,0x0c071cc6u,0x0c071cc8u,0x0c071ccau,0x0c071cccu,0x0c071cceu,0x0c071cd0u,0x0c071cd2u,
0x0c071cd4u,0x0c071cd6u,0x0c071cd8u,0x0c071cdau,0x0c071cdcu,0x0c071cdeu,0x0c071ce0u,0x0c071ce2u,0x0c071ce4u,0x0c071ce6u,0x0c071ce8u,0x0c071ceau,0x0c071cecu,0x0c071ceeu,0x0c071cf0u,0x0c071cf2u,
0x0c071cf4u,0x0c071cf6u,0x0c071cf8u,0x0c071cfau,0x0c071cfcu,0x0c071cfeu,0x0c071d00u,0x0c071d02u,0x0c071d04u,0x0c071d06u,0x0c071d08u,0x0c071d0au,0x0c071d0cu,0x0c071d0eu,0x0c071d10u,0x0c071d12u,
0x0c071d14u,0x0c071d16u,0x0c071d18u,0x0c071d1au,0x0c071d1cu,0x0c071d1eu,0x0c071d20u,0x0c071d22u,0x0c071d24u,0x0c071d26u,0x0c071d28u,0x0c071d2au,0x0c071d2cu,0x0c071d2eu,0x0c071d30u,0x0c071d32u,
0x0c071d34u,0x0c071d36u,0x0c071d38u,0x0c071d3au,0x0c071d3cu,0x0c071d3eu,0x0c071d40u,0x0c071d42u,0x0c071d44u,0x0c071d46u,0x0c071d48u,0x0c071d4au,0x0c071d4cu,0x0c071d4eu,0x0c071d50u,0x0c071d52u,
0x0c071d54u,0x0c071d56u,0x0c071d58u,0x0c071d5au,0x0c071d5cu,0x0c071d5eu,0x0c071d60u,0x0c071d62u,0x0c071d64u,0x0c071d66u,0x0c071d68u,0x0c071d6au,0x0c071d6cu,0x0c071d6eu,0x0c071d70u,0x0c071d72u,
0x0c071d74u,0x0c071d76u,0x0c071d78u,0x0c071d7au,0x0c071d7cu,0x0c071d7eu,0x0c071d80u,0x0c071d82u,0x0c071d84u,0x0c071d86u,0x0c071d88u,0x0c071d8au,0x0c071d8cu,0x0c071d8eu,0x0c071d90u,0x0c071d92u,
0x0c071d94u,0x0c071d96u,0x0c071d98u,0x0c071d9au,0x0c071d9cu,0x0c071d9eu,0x0c071da0u,0x0c071da2u,0x0c071da4u,0x0c071da6u,0x0c071dacu,0x0c071daeu,0x0c071db0u,0x0c071db2u,0x0c071db4u,0x0c071db6u,
0x0c071db8u,0x0c071dbau,0x0c071dbcu,0x0c071dbeu,0x0c071dc0u,0x0c071dc2u,0x0c071dc4u,0x0c071dc6u,0x0c071dc8u,0x0c071dcau,0x0c071dccu,0x0c071dceu,0x0c071dd0u,0x0c071dd2u,0x0c071dd4u,0x0c071dd6u,
0x0c071dd8u,0x0c071ddau,0x0c071ddcu,0x0c071ddeu,0x0c071de0u,0x0c071de2u,0x0c071de4u,0x0c071de6u,0x0c071de8u,0x0c071deau,0x0c071decu,0x0c071deeu,0x0c071df0u,0x0c071df2u,0x0c071df4u,0x0c071df6u,
0x0c071df8u,0x0c071dfau,0x0c071dfcu,0x0c071dfeu,0x0c071e00u,0x0c071e02u,0x0c071e04u,0x0c071e06u,0x0c071e08u,0x0c071e0au,0x0c071e0cu,0x0c071e0eu,0x0c071e10u,0x0c071e12u,0x0c071e14u,0x0c071e16u,
0x0c071e18u,0x0c071e1au,0x0c071e1cu,0x0c071e1eu,0x0c071e20u,0x0c071e22u,0x0c071e24u,0x0c071e26u,0x0c071e28u,0x0c071e2au,0x0c071e2cu,0x0c071e2eu,0x0c071e30u,0x0c071e32u,0x0c071e34u,0x0c071e36u,
0x0c071e38u,0x0c071e3au,0x0c071e3cu,0x0c071e3eu,0x0c071e40u,0x0c071e42u,0x0c071e44u,0x0c071e46u,0x0c071e48u,0x0c071e4au,0x0c071e4cu,0x0c071e4eu,0x0c071e50u,0x0c071e52u,0x0c071e54u,0x0c071e56u,
0x0c071e58u,0x0c071e5au,0x0c071e5cu,0x0c071e64u,0x0c071e66u,0x0c071e68u,0x0c071e6au,0x0c071e6cu,0x0c071e6eu,0x0c071e70u,0x0c071e72u,0x0c071e74u,0x0c071e76u,0x0c071e78u,0x0c071e7au,0x0c071e7cu,
0x0c071e7eu,0x0c071e80u,0x0c071e82u,0x0c071e84u,0x0c071e86u,0x0c071e88u,0x0c071e8au,0x0c071e8cu,0x0c071e8eu,0x0c071e90u,0x0c071e92u,0x0c071e94u,0x0c071e96u,0x0c071e98u,0x0c071e9au,0x0c071e9cu,
0x0c071e9eu,0x0c071ea0u,0x0c071ea2u,0x0c071ea4u,0x0c071ea6u,0x0c071ea8u,0x0c071eaau,0x0c071eacu,0x0c071eaeu,0x0c071eb0u,0x0c071eb2u,0x0c071eb4u,0x0c071eb6u,0x0c071eb8u,0x0c071ebau,0x0c071ebcu,
0x0c071ebeu,0x0c071ec0u,0x0c071ec2u,0x0c071ec4u,0x0c071ec6u,0x0c071ec8u,0x0c071ecau,0x0c071eccu,0x0c071eceu,0x0c071ed0u,0x0c071ed2u,0x0c071ed4u,0x0c071ed6u,0x0c071ed8u,0x0c071edau,0x0c071edcu,
0x0c071edeu,0x0c071ee0u,0x0c071ee2u,0x0c071ee4u,0x0c071ee6u,0x0c071ee8u,0x0c071eeau,0x0c071eecu,0x0c071eeeu,0x0c071ef0u,0x0c071ef2u,0x0c071ef4u,0x0c071ef6u,0x0c071ef8u,0x0c071efau,0x0c071efcu,
0x0c071efeu,0x0c071f00u,0x0c071f02u,0x0c071f04u,0x0c071f06u,0x0c071f08u,0x0c071f0au,0x0c071f0cu,0x0c071f0eu,0x0c071f10u,0x0c071f12u,0x0c071f14u,0x0c071f16u,0x0c071f18u,0x0c071f1au,0x0c071f1cu,
0x0c071f1eu,0x0c071f20u,0x0c071f22u,0x0c071f24u,0x0c071f26u,0x0c071f28u,0x0c071f2au,0x0c071f2cu,0x0c071f2eu,0x0c071f30u,0x0c071f32u,0x0c071f34u,0x0c071f36u,0x0c071f38u,0x0c071f3au,0x0c071f3cu,
0x0c071f3eu,0x0c071f40u,0x0c071f42u,0x0c071f44u,0x0c071f46u,0x0c071f48u,0x0c071f4au,0x0c071f4cu,0x0c071f4eu,0x0c071f50u,0x0c071f52u,0x0c071f54u,0x0c071f56u,0x0c071f58u,0x0c071f5au,0x0c071f5cu,
0x0c071f5eu,0x0c071f60u,0x0c071f62u,0x0c071f64u,0x0c071f66u,0x0c071f68u,0x0c071f6au,0x0c071f6cu,0x0c071f6eu,0x0c071f70u,0x0c071f72u,0x0c071f74u,0x0c071f76u,0x0c071f78u,0x0c071f7au,0x0c071f7cu,
0x0c071f7eu,0x0c071f80u,0x0c071f82u,0x0c071f84u,0x0c071f86u,0x0c071f88u,0x0c071f8au,0x0c071f8cu,0x0c071f8eu,0x0c071f90u,0x0c071f92u,0x0c071f94u,0x0c071f96u,0x0c071f98u,0x0c071f9au,0x0c071f9cu,
0x0c071f9eu,0x0c071fa0u,0x0c071fa2u,0x0c071fa4u,0x0c071fa6u,0x0c071fa8u,0x0c071faau,0x0c071facu,0x0c071faeu,0x0c071fb0u,0x0c071fb2u,0x0c071fb4u,0x0c071fb6u,0x0c071fb8u,0x0c071fbau,0x0c071fbcu,
0x0c071fbeu,0x0c071fc0u,0x0c071fc2u,0x0c071fc4u,0x0c071fc6u,0x0c071fc8u,0x0c071fcau,0x0c071fccu,0x0c071fd4u,0x0c071fd6u,0x0c071fd8u,0x0c071fdau,0x0c071fdcu,0x0c071fdeu,0x0c071fe0u,0x0c071fe2u,
0x0c071fe4u,0x0c071fe6u,0x0c071fe8u,0x0c071feau,0x0c071fecu,0x0c071feeu,0x0c071ff0u,0x0c071ff2u,0x0c071ff4u,0x0c071ff6u,0x0c071ff8u,0x0c071ffau,0x0c071ffcu,0x0c071ffeu,0x0c072000u,0x0c072002u,
0x0c072004u,0x0c072006u,0x0c072008u,0x0c07200au,0x0c07200cu,0x0c07200eu,0x0c072010u,0x0c072012u,0x0c072014u,0x0c072016u,0x0c072018u,0x0c07201au,0x0c07201cu,0x0c07201eu,0x0c072020u,0x0c072022u,
0x0c072024u,0x0c072026u,0x0c072028u,0x0c07202au,0x0c07202cu,0x0c07202eu,0x0c072030u,0x0c072032u,0x0c072034u,0x0c072036u,0x0c072038u,0x0c07203au,0x0c07203cu,0x0c07203eu,0x0c072040u,0x0c072042u,
0x0c072044u,0x0c072046u,0x0c072048u,0x0c07204au,0x0c07204cu,0x0c07204eu,0x0c072050u,0x0c072052u,0x0c072054u,0x0c072056u,0x0c072058u,0x0c07205au,0x0c07205cu,0x0c07205eu,0x0c072060u,0x0c072062u,
0x0c072064u,0x0c072066u,0x0c072068u,0x0c07206au,0x0c07206cu,0x0c07206eu,0x0c072070u,0x0c072072u,0x0c072074u,0x0c07ab14u,0x0c07ab16u,0x0c07ab18u,0x0c07ab1au,0x0c07ab1cu,0x0c07ab1eu,0x0c07ab20u,
0x0c07ab22u,0x0c07ab24u,0x0c07ab26u,0x0c07ab28u,0x0c07ab2au,0x0c07ab2cu,0x0c07ab2eu,0x0c07ab30u,0x0c07ab32u,0x0c07ab34u,0x0c07ab36u,0x0c07ab38u,0x0c07ab3au,0x0c07ab3cu,0x0c07ab3eu,0x0c07ab40u,
0x0c07ab42u,0x0c07ab44u,0x0c07ab46u,0x0c07ab48u,0x0c07ab4au,0x0c07ab4cu,0x0c07ab4eu,0x0c07ab50u,0x0c07ab52u,0x0c07ab54u,0x0c07ab56u,0x0c07ab58u,0x0c07ab5au,0x0c07ab5cu,0x0c07ab5eu,0x0c07ab60u,
0x0c07ab62u,0x0c07ab64u,0x0c07ab66u,0x0c07ab68u,0x0c07ab6au,0x0c07ab6cu,0x0c07ab6eu,0x0c07ab70u,0x0c07ab72u,0x0c07ab74u,0x0c07ab76u,0x0c07ab78u,0x0c07ab7au,0x0c07ab7cu,0x0c07ab7eu,0x0c07ab80u,
0x0c07ab82u,0x0c07ab84u,0x0c07ab94u,0x0c07ab96u,0x0c07ab98u,0x0c07ab9au,0x0c07ab9cu,0x0c07ab9eu,0x0c07aba0u,0x0c07aba2u,0x0c07aba4u,0x0c07aba6u,0x0c07aba8u,0x0c07abaau,0x0c07abacu,0x0c07abaeu,
0x0c07abb0u,0x0c07abb2u,0x0c07abb4u,0x0c07abb6u,0x0c07abb8u,0x0c07abbau,0x0c07abbcu,0x0c07abbeu,0x0c07abc0u,0x0c07abc2u,0x0c07abc4u,0x0c07abc6u,0x0c07abc8u,0x0c07abcau,0x0c07abccu,0x0c07abceu,
0x0c07abd0u,0x0c07abd2u,0x0c07abd4u,0x0c07abd6u,0x0c07abd8u,0x0c07abdau,0x0c07b5b0u,0x0c07b5b2u,0x0c07b5b4u,0x0c07b5b6u,0x0c07b5b8u,0x0c07b5bau,0x0c07b5bcu,0x0c07b5beu,0x0c07b5c0u,0x0c07b5c2u,
0x0c07b5c4u,0x0c07b5c6u,0x0c07b5c8u,0x0c07b5cau,0x0c07b5ccu,0x0c07b5f0u,0x0c07b5f2u,0x0c07b5f4u,0x0c07b5f6u,0x0c07b5f8u,0x0c07b5fau,0x0c07b5fcu,0x0c07b5feu,0x0c07b600u,0x0c07b602u,0x0c07b604u,
0x0c07b606u,0x0c07b608u,0x0c07b60au,0x0c07b60cu,0x0c07b60eu,0x0c07b610u,0x0c07b612u,0x0c07b614u,0x0c07b616u,0x0c07b618u,0x0c07b61au,0x0c07b61cu,0x0c07b61eu,0x0c07b620u,0x0c07b622u,0x0c07b624u,
0x0c07b626u,0x0c07b628u,0x0c07b62au,0x0c07b62cu,0x0c07b62eu,0x0c07b630u,0x0c07b632u,0x0c07b634u,0x0c07b636u,0x0c07b638u,0x0c07b63au,0x0c07b63cu,0x0c07b63eu,0x0c07b640u,0x0c07b642u,0x0c07b644u,
0x0c07b646u,0x0c07b648u,0x0c07b64au,0x0c07b64cu,0x0c07b64eu,0x0c07b650u,0x0c07b652u,0x0c07b654u,0x0c07b656u,0x0c07b658u,0x0c07b65au,0x0c07b65cu,0x0c07b65eu,0x0c07b660u,0x0c07b662u,0x0c07b664u,
0x0c07b666u,0x0c07b668u,0x0c07b66au,0x0c07b66cu,
};
int vf3_seventh_c4_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
