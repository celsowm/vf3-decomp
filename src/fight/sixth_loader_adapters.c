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
int vf3_sixth_loader_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b38d0u: goto P_0c0b38d0;
case 0x0c0b38d2u: goto P_0c0b38d2;
case 0x0c0b38d4u: goto P_0c0b38d4;
case 0x0c0b38d6u: goto P_0c0b38d6;
case 0x0c0b38d8u: goto P_0c0b38d8;
case 0x0c0b38dau: goto P_0c0b38da;
case 0x0c0b38dcu: goto P_0c0b38dc;
case 0x0c0b38deu: goto P_0c0b38de;
case 0x0c0b38e0u: goto P_0c0b38e0;
case 0x0c0b38e2u: goto P_0c0b38e2;
case 0x0c0b38e4u: goto P_0c0b38e4;
case 0x0c0b38e6u: goto P_0c0b38e6;
case 0x0c0b38e8u: goto P_0c0b38e8;
case 0x0c0b38eau: goto P_0c0b38ea;
case 0x0c0b38ecu: goto P_0c0b38ec;
case 0x0c0b38eeu: goto P_0c0b38ee;
case 0x0c0b38f0u: goto P_0c0b38f0;
case 0x0c0b38f2u: goto P_0c0b38f2;
case 0x0c0b38f4u: goto P_0c0b38f4;
case 0x0c0b38f6u: goto P_0c0b38f6;
case 0x0c0b38f8u: goto P_0c0b38f8;
case 0x0c0b38fau: goto P_0c0b38fa;
case 0x0c0b38fcu: goto P_0c0b38fc;
case 0x0c0b38feu: goto P_0c0b38fe;
case 0x0c0b3900u: goto P_0c0b3900;
case 0x0c0b3902u: goto P_0c0b3902;
case 0x0c0b3904u: goto P_0c0b3904;
case 0x0c0b3906u: goto P_0c0b3906;
case 0x0c0b3908u: goto P_0c0b3908;
case 0x0c0b390au: goto P_0c0b390a;
case 0x0c0b390cu: goto P_0c0b390c;
case 0x0c0b390eu: goto P_0c0b390e;
case 0x0c0b3910u: goto P_0c0b3910;
case 0x0c0b3912u: goto P_0c0b3912;
case 0x0c0b3914u: goto P_0c0b3914;
case 0x0c0b3916u: goto P_0c0b3916;
case 0x0c0b3918u: goto P_0c0b3918;
case 0x0c0b391au: goto P_0c0b391a;
case 0x0c0b391cu: goto P_0c0b391c;
case 0x0c0b391eu: goto P_0c0b391e;
case 0x0c0b3920u: goto P_0c0b3920;
case 0x0c0b3922u: goto P_0c0b3922;
case 0x0c0b3924u: goto P_0c0b3924;
case 0x0c0b3926u: goto P_0c0b3926;
case 0x0c0b3928u: goto P_0c0b3928;
case 0x0c0b392au: goto P_0c0b392a;
case 0x0c0b392cu: goto P_0c0b392c;
case 0x0c0b392eu: goto P_0c0b392e;
case 0x0c0b3930u: goto P_0c0b3930;
case 0x0c0b3932u: goto P_0c0b3932;
case 0x0c0b3934u: goto P_0c0b3934;
case 0x0c0b3936u: goto P_0c0b3936;
case 0x0c0b3938u: goto P_0c0b3938;
case 0x0c0b393au: goto P_0c0b393a;
case 0x0c0b393cu: goto P_0c0b393c;
case 0x0c0b393eu: goto P_0c0b393e;
case 0x0c0b3940u: goto P_0c0b3940;
case 0x0c0b3942u: goto P_0c0b3942;
case 0x0c0b3944u: goto P_0c0b3944;
case 0x0c0b3946u: goto P_0c0b3946;
case 0x0c0b3948u: goto P_0c0b3948;
case 0x0c0b394au: goto P_0c0b394a;
case 0x0c0b394cu: goto P_0c0b394c;
case 0x0c0b394eu: goto P_0c0b394e;
case 0x0c0b3950u: goto P_0c0b3950;
case 0x0c0b3952u: goto P_0c0b3952;
case 0x0c0b3954u: goto P_0c0b3954;
case 0x0c0b3956u: goto P_0c0b3956;
case 0x0c0b3958u: goto P_0c0b3958;
case 0x0c0b395au: goto P_0c0b395a;
case 0x0c0b395cu: goto P_0c0b395c;
case 0x0c0b395eu: goto P_0c0b395e;
case 0x0c0b3960u: goto P_0c0b3960;
case 0x0c0b3962u: goto P_0c0b3962;
case 0x0c0b3964u: goto P_0c0b3964;
case 0x0c0b3966u: goto P_0c0b3966;
case 0x0c0b3968u: goto P_0c0b3968;
case 0x0c0b396au: goto P_0c0b396a;
case 0x0c0b396cu: goto P_0c0b396c;
case 0x0c0b396eu: goto P_0c0b396e;
case 0x0c0b3970u: goto P_0c0b3970;
case 0x0c0b3972u: goto P_0c0b3972;
case 0x0c0b3974u: goto P_0c0b3974;
case 0x0c0b3976u: goto P_0c0b3976;
case 0x0c0b3978u: goto P_0c0b3978;
case 0x0c0b397au: goto P_0c0b397a;
case 0x0c0b397cu: goto P_0c0b397c;
case 0x0c0b397eu: goto P_0c0b397e;
case 0x0c0b3980u: goto P_0c0b3980;
case 0x0c0b3982u: goto P_0c0b3982;
case 0x0c0b3984u: goto P_0c0b3984;
case 0x0c0b3986u: goto P_0c0b3986;
case 0x0c0b3988u: goto P_0c0b3988;
case 0x0c0b398au: goto P_0c0b398a;
case 0x0c0b398cu: goto P_0c0b398c;
case 0x0c0b398eu: goto P_0c0b398e;
case 0x0c0b3990u: goto P_0c0b3990;
case 0x0c0b3992u: goto P_0c0b3992;
case 0x0c0b3994u: goto P_0c0b3994;
case 0x0c0b3996u: goto P_0c0b3996;
case 0x0c0b3998u: goto P_0c0b3998;
case 0x0c0b399au: goto P_0c0b399a;
case 0x0c0b399cu: goto P_0c0b399c;
case 0x0c0b399eu: goto P_0c0b399e;
case 0x0c0b39a0u: goto P_0c0b39a0;
case 0x0c0b39a2u: goto P_0c0b39a2;
case 0x0c0b39a4u: goto P_0c0b39a4;
case 0x0c0b39a6u: goto P_0c0b39a6;
case 0x0c0b39a8u: goto P_0c0b39a8;
case 0x0c0b39aau: goto P_0c0b39aa;
case 0x0c0b39acu: goto P_0c0b39ac;
case 0x0c0b39aeu: goto P_0c0b39ae;
case 0x0c0b39b0u: goto P_0c0b39b0;
case 0x0c0b39b2u: goto P_0c0b39b2;
case 0x0c0b39b4u: goto P_0c0b39b4;
case 0x0c0b39b6u: goto P_0c0b39b6;
case 0x0c0b39b8u: goto P_0c0b39b8;
case 0x0c0b39bau: goto P_0c0b39ba;
case 0x0c0b39bcu: goto P_0c0b39bc;
case 0x0c0b39beu: goto P_0c0b39be;
case 0x0c0b39c0u: goto P_0c0b39c0;
case 0x0c0b39c2u: goto P_0c0b39c2;
case 0x0c0b39c4u: goto P_0c0b39c4;
case 0x0c0b39c6u: goto P_0c0b39c6;
case 0x0c0b39c8u: goto P_0c0b39c8;
case 0x0c0b39cau: goto P_0c0b39ca;
case 0x0c0b39ccu: goto P_0c0b39cc;
case 0x0c0b39ceu: goto P_0c0b39ce;
case 0x0c0b39d0u: goto P_0c0b39d0;
case 0x0c0b39d2u: goto P_0c0b39d2;
case 0x0c0b39d4u: goto P_0c0b39d4;
case 0x0c0b39d6u: goto P_0c0b39d6;
case 0x0c0b39d8u: goto P_0c0b39d8;
case 0x0c0b39dau: goto P_0c0b39da;
case 0x0c0b39dcu: goto P_0c0b39dc;
case 0x0c0b39deu: goto P_0c0b39de;
case 0x0c0b39e0u: goto P_0c0b39e0;
case 0x0c0b39e2u: goto P_0c0b39e2;
case 0x0c0b39e4u: goto P_0c0b39e4;
case 0x0c0b39e6u: goto P_0c0b39e6;
case 0x0c0b39e8u: goto P_0c0b39e8;
case 0x0c0b39eau: goto P_0c0b39ea;
case 0x0c0b39ecu: goto P_0c0b39ec;
case 0x0c0b39eeu: goto P_0c0b39ee;
case 0x0c0b39f0u: goto P_0c0b39f0;
case 0x0c0b39f2u: goto P_0c0b39f2;
case 0x0c0b39f4u: goto P_0c0b39f4;
case 0x0c0b39f6u: goto P_0c0b39f6;
case 0x0c0b39f8u: goto P_0c0b39f8;
case 0x0c0b39fau: goto P_0c0b39fa;
case 0x0c0b39fcu: goto P_0c0b39fc;
case 0x0c0b39feu: goto P_0c0b39fe;
case 0x0c0b3a00u: goto P_0c0b3a00;
case 0x0c0b3a02u: goto P_0c0b3a02;
case 0x0c0b3a04u: goto P_0c0b3a04;
case 0x0c0b3a06u: goto P_0c0b3a06;
case 0x0c0b3a08u: goto P_0c0b3a08;
case 0x0c0b3a0au: goto P_0c0b3a0a;
case 0x0c0b3a0cu: goto P_0c0b3a0c;
case 0x0c0b3a0eu: goto P_0c0b3a0e;
case 0x0c0b3a10u: goto P_0c0b3a10;
case 0x0c0b3a12u: goto P_0c0b3a12;
case 0x0c0b3a14u: goto P_0c0b3a14;
case 0x0c0b3a16u: goto P_0c0b3a16;
case 0x0c0b588eu: goto P_0c0b588e;
case 0x0c0b5890u: goto P_0c0b5890;
case 0x0c0b5892u: goto P_0c0b5892;
case 0x0c0b5894u: goto P_0c0b5894;
case 0x0c0b5896u: goto P_0c0b5896;
case 0x0c0b5898u: goto P_0c0b5898;
case 0x0c0b589au: goto P_0c0b589a;
case 0x0c0b589cu: goto P_0c0b589c;
case 0x0c0b589eu: goto P_0c0b589e;
case 0x0c0b58a0u: goto P_0c0b58a0;
case 0x0c0b58a2u: goto P_0c0b58a2;
case 0x0c0b58a4u: goto P_0c0b58a4;
case 0x0c0b58a6u: goto P_0c0b58a6;
case 0x0c0b58a8u: goto P_0c0b58a8;
case 0x0c0b58aau: goto P_0c0b58aa;
case 0x0c0b58acu: goto P_0c0b58ac;
case 0x0c0b58aeu: goto P_0c0b58ae;
case 0x0c0b58b0u: goto P_0c0b58b0;
case 0x0c0b58b2u: goto P_0c0b58b2;
case 0x0c0b58b4u: goto P_0c0b58b4;
case 0x0c0b58b6u: goto P_0c0b58b6;
case 0x0c0b58b8u: goto P_0c0b58b8;
case 0x0c0b58bau: goto P_0c0b58ba;
case 0x0c0b58bcu: goto P_0c0b58bc;
case 0x0c0b58beu: goto P_0c0b58be;
case 0x0c0b58c0u: goto P_0c0b58c0;
case 0x0c0b58c2u: goto P_0c0b58c2;
case 0x0c0b58c4u: goto P_0c0b58c4;
case 0x0c0b58c6u: goto P_0c0b58c6;
case 0x0c0b58c8u: goto P_0c0b58c8;
case 0x0c0b58cau: goto P_0c0b58ca;
case 0x0c0b58ccu: goto P_0c0b58cc;
case 0x0c0b58ceu: goto P_0c0b58ce;
case 0x0c0b58d0u: goto P_0c0b58d0;
case 0x0c0b58d2u: goto P_0c0b58d2;
case 0x0c0b58d4u: goto P_0c0b58d4;
case 0x0c0b58d6u: goto P_0c0b58d6;
case 0x0c0b58d8u: goto P_0c0b58d8;
case 0x0c0b58dau: goto P_0c0b58da;
case 0x0c0b58dcu: goto P_0c0b58dc;
case 0x0c0b58deu: goto P_0c0b58de;
case 0x0c0b58e0u: goto P_0c0b58e0;
case 0x0c0b58e2u: goto P_0c0b58e2;
case 0x0c0b58e4u: goto P_0c0b58e4;
case 0x0c0b58e6u: goto P_0c0b58e6;
case 0x0c0b58e8u: goto P_0c0b58e8;
case 0x0c0b58eau: goto P_0c0b58ea;
case 0x0c0b58ecu: goto P_0c0b58ec;
case 0x0c0b58eeu: goto P_0c0b58ee;
case 0x0c0b58f0u: goto P_0c0b58f0;
case 0x0c0b58f2u: goto P_0c0b58f2;
case 0x0c0b58f4u: goto P_0c0b58f4;
case 0x0c0b58f6u: goto P_0c0b58f6;
case 0x0c0b58f8u: goto P_0c0b58f8;
case 0x0c0b58fau: goto P_0c0b58fa;
case 0x0c0b58fcu: goto P_0c0b58fc;
case 0x0c0b58feu: goto P_0c0b58fe;
case 0x0c0b5900u: goto P_0c0b5900;
case 0x0c0b5902u: goto P_0c0b5902;
case 0x0c0b5904u: goto P_0c0b5904;
case 0x0c0b5906u: goto P_0c0b5906;
case 0x0c0b5908u: goto P_0c0b5908;
case 0x0c0b590au: goto P_0c0b590a;
case 0x0c0b590cu: goto P_0c0b590c;
case 0x0c0b590eu: goto P_0c0b590e;
case 0x0c0b5910u: goto P_0c0b5910;
case 0x0c0b5912u: goto P_0c0b5912;
case 0x0c0b5914u: goto P_0c0b5914;
case 0x0c0b5916u: goto P_0c0b5916;
case 0x0c0b5918u: goto P_0c0b5918;
case 0x0c0b591au: goto P_0c0b591a;
case 0x0c0b591cu: goto P_0c0b591c;
case 0x0c0b591eu: goto P_0c0b591e;
case 0x0c0b5920u: goto P_0c0b5920;
case 0x0c0b5922u: goto P_0c0b5922;
case 0x0c0b5924u: goto P_0c0b5924;
case 0x0c0b5926u: goto P_0c0b5926;
case 0x0c0b5928u: goto P_0c0b5928;
case 0x0c0b592au: goto P_0c0b592a;
case 0x0c0b592cu: goto P_0c0b592c;
case 0x0c0b592eu: goto P_0c0b592e;
case 0x0c0b5930u: goto P_0c0b5930;
case 0x0c0b5932u: goto P_0c0b5932;
case 0x0c0b5934u: goto P_0c0b5934;
case 0x0c0b5936u: goto P_0c0b5936;
case 0x0c0b5938u: goto P_0c0b5938;
case 0x0c0b593au: goto P_0c0b593a;
case 0x0c0b593cu: goto P_0c0b593c;
case 0x0c0b593eu: goto P_0c0b593e;
case 0x0c0b5940u: goto P_0c0b5940;
case 0x0c0b5942u: goto P_0c0b5942;
case 0x0c0b5944u: goto P_0c0b5944;
case 0x0c0b5946u: goto P_0c0b5946;
case 0x0c0b5948u: goto P_0c0b5948;
case 0x0c0b594au: goto P_0c0b594a;
case 0x0c0b594cu: goto P_0c0b594c;
case 0x0c0b594eu: goto P_0c0b594e;
case 0x0c0b5950u: goto P_0c0b5950;
case 0x0c0b5952u: goto P_0c0b5952;
case 0x0c0b5954u: goto P_0c0b5954;
case 0x0c0b5956u: goto P_0c0b5956;
case 0x0c0b5958u: goto P_0c0b5958;
case 0x0c0b595au: goto P_0c0b595a;
case 0x0c0b595cu: goto P_0c0b595c;
case 0x0c0b595eu: goto P_0c0b595e;
case 0x0c0b5960u: goto P_0c0b5960;
case 0x0c0b5962u: goto P_0c0b5962;
case 0x0c0b5964u: goto P_0c0b5964;
case 0x0c0b5966u: goto P_0c0b5966;
case 0x0c0b5968u: goto P_0c0b5968;
case 0x0c0b596au: goto P_0c0b596a;
case 0x0c0b596cu: goto P_0c0b596c;
case 0x0c0b596eu: goto P_0c0b596e;
case 0x0c0b5970u: goto P_0c0b5970;
case 0x0c0b5972u: goto P_0c0b5972;
case 0x0c0b5974u: goto P_0c0b5974;
case 0x0c0b5976u: goto P_0c0b5976;
case 0x0c0b5978u: goto P_0c0b5978;
case 0x0c0b597au: goto P_0c0b597a;
case 0x0c0b597cu: goto P_0c0b597c;
case 0x0c0b597eu: goto P_0c0b597e;
case 0x0c0b5980u: goto P_0c0b5980;
case 0x0c0b5982u: goto P_0c0b5982;
case 0x0c0b5984u: goto P_0c0b5984;
case 0x0c0b5986u: goto P_0c0b5986;
case 0x0c0b5988u: goto P_0c0b5988;
case 0x0c0b598au: goto P_0c0b598a;
case 0x0c0b598cu: goto P_0c0b598c;
case 0x0c0b598eu: goto P_0c0b598e;
case 0x0c0b5990u: goto P_0c0b5990;
case 0x0c0b5992u: goto P_0c0b5992;
case 0x0c0b5994u: goto P_0c0b5994;
case 0x0c0b5996u: goto P_0c0b5996;
case 0x0c0b5998u: goto P_0c0b5998;
case 0x0c0b599au: goto P_0c0b599a;
case 0x0c0b599cu: goto P_0c0b599c;
case 0x0c0b599eu: goto P_0c0b599e;
case 0x0c0b59a0u: goto P_0c0b59a0;
case 0x0c0b59a2u: goto P_0c0b59a2;
case 0x0c0b59a4u: goto P_0c0b59a4;
case 0x0c0b59a6u: goto P_0c0b59a6;
case 0x0c0b59a8u: goto P_0c0b59a8;
case 0x0c0b59aau: goto P_0c0b59aa;
case 0x0c0b59acu: goto P_0c0b59ac;
case 0x0c0b59aeu: goto P_0c0b59ae;
case 0x0c0b59b0u: goto P_0c0b59b0;
case 0x0c0b59b2u: goto P_0c0b59b2;
case 0x0c0b59b4u: goto P_0c0b59b4;
case 0x0c0b59b6u: goto P_0c0b59b6;
case 0x0c0b59b8u: goto P_0c0b59b8;
case 0x0c0b59bau: goto P_0c0b59ba;
case 0x0c0b59bcu: goto P_0c0b59bc;
case 0x0c0b59beu: goto P_0c0b59be;
case 0x0c0b59c0u: goto P_0c0b59c0;
case 0x0c0b59c2u: goto P_0c0b59c2;
case 0x0c0b59c4u: goto P_0c0b59c4;
case 0x0c0b59c6u: goto P_0c0b59c6;
case 0x0c0b59c8u: goto P_0c0b59c8;
case 0x0c0b59cau: goto P_0c0b59ca;
case 0x0c0b59ccu: goto P_0c0b59cc;
case 0x0c0b59ceu: goto P_0c0b59ce;
case 0x0c0b59d0u: goto P_0c0b59d0;
case 0x0c0b59d2u: goto P_0c0b59d2;
case 0x0c0b59d4u: goto P_0c0b59d4;
case 0x0c0b59d6u: goto P_0c0b59d6;
case 0x0c0b59d8u: goto P_0c0b59d8;
case 0x0c0b59dau: goto P_0c0b59da;
case 0x0c0b59dcu: goto P_0c0b59dc;
case 0x0c0b59deu: goto P_0c0b59de;
case 0x0c0b59e0u: goto P_0c0b59e0;
case 0x0c0b59e2u: goto P_0c0b59e2;
case 0x0c0b59e4u: goto P_0c0b59e4;
case 0x0c0b5a54u: goto P_0c0b5a54;
case 0x0c0b5a56u: goto P_0c0b5a56;
case 0x0c0b5a58u: goto P_0c0b5a58;
case 0x0c0b5a5au: goto P_0c0b5a5a;
case 0x0c0b5a5cu: goto P_0c0b5a5c;
case 0x0c0b5a5eu: goto P_0c0b5a5e;
case 0x0c0b5a60u: goto P_0c0b5a60;
case 0x0c0b5a62u: goto P_0c0b5a62;
case 0x0c0b5a64u: goto P_0c0b5a64;
case 0x0c0b5a66u: goto P_0c0b5a66;
case 0x0c0b5a68u: goto P_0c0b5a68;
case 0x0c0b5a6au: goto P_0c0b5a6a;
case 0x0c0b5a6cu: goto P_0c0b5a6c;
case 0x0c0b5a6eu: goto P_0c0b5a6e;
case 0x0c0b5a70u: goto P_0c0b5a70;
case 0x0c0b5a72u: goto P_0c0b5a72;
case 0x0c0b5a74u: goto P_0c0b5a74;
case 0x0c0b5a76u: goto P_0c0b5a76;
case 0x0c0b5a78u: goto P_0c0b5a78;
case 0x0c0b5a7au: goto P_0c0b5a7a;
case 0x0c0b5a7cu: goto P_0c0b5a7c;
case 0x0c0b5a7eu: goto P_0c0b5a7e;
case 0x0c0b5a80u: goto P_0c0b5a80;
case 0x0c0b5a82u: goto P_0c0b5a82;
case 0x0c0b5a84u: goto P_0c0b5a84;
case 0x0c0b5a86u: goto P_0c0b5a86;
case 0x0c0b5a88u: goto P_0c0b5a88;
case 0x0c0b5a8au: goto P_0c0b5a8a;
case 0x0c0b5a8cu: goto P_0c0b5a8c;
case 0x0c0b5a8eu: goto P_0c0b5a8e;
case 0x0c0b5a90u: goto P_0c0b5a90;
case 0x0c0b5a92u: goto P_0c0b5a92;
case 0x0c0b5a94u: goto P_0c0b5a94;
case 0x0c0b5a96u: goto P_0c0b5a96;
case 0x0c0b5a98u: goto P_0c0b5a98;
case 0x0c0b5a9au: goto P_0c0b5a9a;
case 0x0c0b5a9cu: goto P_0c0b5a9c;
case 0x0c0b5a9eu: goto P_0c0b5a9e;
case 0x0c0b5aa0u: goto P_0c0b5aa0;
case 0x0c0b5aa2u: goto P_0c0b5aa2;
case 0x0c0b5aa4u: goto P_0c0b5aa4;
case 0x0c0b5aa6u: goto P_0c0b5aa6;
case 0x0c0b5aa8u: goto P_0c0b5aa8;
case 0x0c0b5aaau: goto P_0c0b5aaa;
case 0x0c0b5aacu: goto P_0c0b5aac;
case 0x0c0b5aaeu: goto P_0c0b5aae;
case 0x0c0b5ab0u: goto P_0c0b5ab0;
case 0x0c0b5ab2u: goto P_0c0b5ab2;
case 0x0c0b5ab4u: goto P_0c0b5ab4;
case 0x0c0b5ab6u: goto P_0c0b5ab6;
case 0x0c0b5ab8u: goto P_0c0b5ab8;
case 0x0c0b5abau: goto P_0c0b5aba;
case 0x0c0b5abcu: goto P_0c0b5abc;
case 0x0c0b5abeu: goto P_0c0b5abe;
case 0x0c0b5ac0u: goto P_0c0b5ac0;
case 0x0c0b5ac2u: goto P_0c0b5ac2;
case 0x0c0b5ac4u: goto P_0c0b5ac4;
case 0x0c0b5ac6u: goto P_0c0b5ac6;
case 0x0c0b5ac8u: goto P_0c0b5ac8;
case 0x0c0b5acau: goto P_0c0b5aca;
case 0x0c0b5accu: goto P_0c0b5acc;
case 0x0c0b5aceu: goto P_0c0b5ace;
case 0x0c0b5ad0u: goto P_0c0b5ad0;
case 0x0c0b5ad2u: goto P_0c0b5ad2;
case 0x0c0b5ad4u: goto P_0c0b5ad4;
case 0x0c0b5ad6u: goto P_0c0b5ad6;
case 0x0c0b5ad8u: goto P_0c0b5ad8;
case 0x0c0b5adau: goto P_0c0b5ada;
case 0x0c0b5adcu: goto P_0c0b5adc;
case 0x0c0b5adeu: goto P_0c0b5ade;
case 0x0c0b5ae0u: goto P_0c0b5ae0;
case 0x0c0b5ae2u: goto P_0c0b5ae2;
case 0x0c0b5ae4u: goto P_0c0b5ae4;
case 0x0c0b5ae6u: goto P_0c0b5ae6;
case 0x0c0b5ae8u: goto P_0c0b5ae8;
case 0x0c0b5aeau: goto P_0c0b5aea;
case 0x0c0b5aecu: goto P_0c0b5aec;
case 0x0c0b5aeeu: goto P_0c0b5aee;
case 0x0c0b5af0u: goto P_0c0b5af0;
case 0x0c0b5af2u: goto P_0c0b5af2;
case 0x0c0b5af4u: goto P_0c0b5af4;
case 0x0c0b5af6u: goto P_0c0b5af6;
case 0x0c0b5af8u: goto P_0c0b5af8;
case 0x0c0b5afau: goto P_0c0b5afa;
case 0x0c0b5afcu: goto P_0c0b5afc;
case 0x0c0b5afeu: goto P_0c0b5afe;
case 0x0c0b5b00u: goto P_0c0b5b00;
case 0x0c0b5b02u: goto P_0c0b5b02;
case 0x0c0b5b04u: goto P_0c0b5b04;
case 0x0c0b5b06u: goto P_0c0b5b06;
case 0x0c0b5b08u: goto P_0c0b5b08;
case 0x0c0b5b0au: goto P_0c0b5b0a;
case 0x0c0b5b0cu: goto P_0c0b5b0c;
case 0x0c0b5b0eu: goto P_0c0b5b0e;
case 0x0c0b5b10u: goto P_0c0b5b10;
case 0x0c0b5b12u: goto P_0c0b5b12;
case 0x0c0b5b14u: goto P_0c0b5b14;
case 0x0c0b5b16u: goto P_0c0b5b16;
case 0x0c0b5b18u: goto P_0c0b5b18;
case 0x0c0b5b1au: goto P_0c0b5b1a;
case 0x0c0b5b1cu: goto P_0c0b5b1c;
case 0x0c0b5b1eu: goto P_0c0b5b1e;
case 0x0c0b5b20u: goto P_0c0b5b20;
case 0x0c0b5b22u: goto P_0c0b5b22;
case 0x0c0b5b24u: goto P_0c0b5b24;
case 0x0c0b5b26u: goto P_0c0b5b26;
case 0x0c0b5b28u: goto P_0c0b5b28;
case 0x0c0b5b2au: goto P_0c0b5b2a;
case 0x0c0b5b2cu: goto P_0c0b5b2c;
case 0x0c0b5b2eu: goto P_0c0b5b2e;
case 0x0c0b5b30u: goto P_0c0b5b30;
case 0x0c0b5b32u: goto P_0c0b5b32;
case 0x0c0b5b34u: goto P_0c0b5b34;
case 0x0c0b5b36u: goto P_0c0b5b36;
case 0x0c0b5b38u: goto P_0c0b5b38;
case 0x0c0b5b3au: goto P_0c0b5b3a;
case 0x0c0b5b3cu: goto P_0c0b5b3c;
case 0x0c0b5b3eu: goto P_0c0b5b3e;
case 0x0c0b5b40u: goto P_0c0b5b40;
case 0x0c0b5b42u: goto P_0c0b5b42;
case 0x0c0b5b44u: goto P_0c0b5b44;
case 0x0c0b5b46u: goto P_0c0b5b46;
case 0x0c0b5b48u: goto P_0c0b5b48;
case 0x0c0b5b4au: goto P_0c0b5b4a;
case 0x0c0b5b4cu: goto P_0c0b5b4c;
case 0x0c0b5b4eu: goto P_0c0b5b4e;
case 0x0c0b5b50u: goto P_0c0b5b50;
case 0x0c0b5b52u: goto P_0c0b5b52;
case 0x0c0b5b54u: goto P_0c0b5b54;
case 0x0c0b5b56u: goto P_0c0b5b56;
case 0x0c0b5b58u: goto P_0c0b5b58;
case 0x0c0b5b5au: goto P_0c0b5b5a;
case 0x0c0b5b5cu: goto P_0c0b5b5c;
case 0x0c0b5b5eu: goto P_0c0b5b5e;
case 0x0c0b5b60u: goto P_0c0b5b60;
case 0x0c0b5b62u: goto P_0c0b5b62;
case 0x0c0b5b64u: goto P_0c0b5b64;
case 0x0c0b5b66u: goto P_0c0b5b66;
case 0x0c0b5b68u: goto P_0c0b5b68;
case 0x0c0b5b6au: goto P_0c0b5b6a;
case 0x0c0b5b6cu: goto P_0c0b5b6c;
case 0x0c0b5b6eu: goto P_0c0b5b6e;
case 0x0c0b5b70u: goto P_0c0b5b70;
case 0x0c0b5b72u: goto P_0c0b5b72;
case 0x0c0b5b74u: goto P_0c0b5b74;
case 0x0c0b5b76u: goto P_0c0b5b76;
case 0x0c0b5b78u: goto P_0c0b5b78;
case 0x0c0b5b7au: goto P_0c0b5b7a;
case 0x0c0b5b7cu: goto P_0c0b5b7c;
case 0x0c0b5b7eu: goto P_0c0b5b7e;
case 0x0c0b5b80u: goto P_0c0b5b80;
case 0x0c0b5b82u: goto P_0c0b5b82;
case 0x0c0b5b84u: goto P_0c0b5b84;
case 0x0c0b5b86u: goto P_0c0b5b86;
case 0x0c0b5b88u: goto P_0c0b5b88;
case 0x0c0b5b8au: goto P_0c0b5b8a;
case 0x0c0b5b8cu: goto P_0c0b5b8c;
case 0x0c0b5b8eu: goto P_0c0b5b8e;
case 0x0c0b5b90u: goto P_0c0b5b90;
case 0x0c0b5b92u: goto P_0c0b5b92;
case 0x0c0b5b94u: goto P_0c0b5b94;
case 0x0c0b5b96u: goto P_0c0b5b96;
case 0x0c0b5b98u: goto P_0c0b5b98;
case 0x0c0b5b9au: goto P_0c0b5b9a;
case 0x0c0b5b9cu: goto P_0c0b5b9c;
case 0x0c0b5b9eu: goto P_0c0b5b9e;
case 0x0c0b5ba0u: goto P_0c0b5ba0;
case 0x0c0b5ba2u: goto P_0c0b5ba2;
case 0x0c0b5ba4u: goto P_0c0b5ba4;
case 0x0c0b5ba6u: goto P_0c0b5ba6;
case 0x0c0b5ba8u: goto P_0c0b5ba8;
case 0x0c0b5baau: goto P_0c0b5baa;
case 0x0c0b5bacu: goto P_0c0b5bac;
case 0x0c0b5c26u: goto P_0c0b5c26;
case 0x0c0b5c28u: goto P_0c0b5c28;
case 0x0c0b5c2au: goto P_0c0b5c2a;
case 0x0c0b5c2cu: goto P_0c0b5c2c;
case 0x0c0b5c2eu: goto P_0c0b5c2e;
case 0x0c0b5c30u: goto P_0c0b5c30;
case 0x0c0b5c32u: goto P_0c0b5c32;
case 0x0c0b5c34u: goto P_0c0b5c34;
case 0x0c0b5c36u: goto P_0c0b5c36;
case 0x0c0b5c38u: goto P_0c0b5c38;
case 0x0c0b5c3au: goto P_0c0b5c3a;
case 0x0c0b5c3cu: goto P_0c0b5c3c;
case 0x0c0b5c3eu: goto P_0c0b5c3e;
case 0x0c0b5c40u: goto P_0c0b5c40;
case 0x0c0b5c42u: goto P_0c0b5c42;
case 0x0c0b5c44u: goto P_0c0b5c44;
case 0x0c0b5c46u: goto P_0c0b5c46;
case 0x0c0b5c48u: goto P_0c0b5c48;
case 0x0c0b5c4au: goto P_0c0b5c4a;
case 0x0c0b5c4cu: goto P_0c0b5c4c;
case 0x0c0b5c4eu: goto P_0c0b5c4e;
case 0x0c0b5c50u: goto P_0c0b5c50;
case 0x0c0b5c52u: goto P_0c0b5c52;
case 0x0c0b5c54u: goto P_0c0b5c54;
case 0x0c0b5c56u: goto P_0c0b5c56;
case 0x0c0b5c58u: goto P_0c0b5c58;
case 0x0c0b5c5au: goto P_0c0b5c5a;
case 0x0c0b5c5cu: goto P_0c0b5c5c;
case 0x0c0b5c5eu: goto P_0c0b5c5e;
case 0x0c0b5c60u: goto P_0c0b5c60;
case 0x0c0b5c62u: goto P_0c0b5c62;
case 0x0c0b5c64u: goto P_0c0b5c64;
case 0x0c0b5c66u: goto P_0c0b5c66;
case 0x0c0b5c68u: goto P_0c0b5c68;
case 0x0c0b5c6au: goto P_0c0b5c6a;
case 0x0c0b5c6cu: goto P_0c0b5c6c;
case 0x0c0b5c6eu: goto P_0c0b5c6e;
case 0x0c0b5c70u: goto P_0c0b5c70;
case 0x0c0b5c72u: goto P_0c0b5c72;
case 0x0c0b5c74u: goto P_0c0b5c74;
case 0x0c0b5c76u: goto P_0c0b5c76;
case 0x0c0b5c78u: goto P_0c0b5c78;
case 0x0c0b5c7au: goto P_0c0b5c7a;
case 0x0c0b5c7cu: goto P_0c0b5c7c;
case 0x0c0b5c7eu: goto P_0c0b5c7e;
case 0x0c0b5c80u: goto P_0c0b5c80;
case 0x0c0b5c82u: goto P_0c0b5c82;
case 0x0c0b5c84u: goto P_0c0b5c84;
case 0x0c0b5c86u: goto P_0c0b5c86;
case 0x0c0b5c88u: goto P_0c0b5c88;
case 0x0c0b5c8au: goto P_0c0b5c8a;
case 0x0c0b5c8cu: goto P_0c0b5c8c;
case 0x0c0b9700u: goto P_0c0b9700;
case 0x0c0b9702u: goto P_0c0b9702;
case 0x0c0b9704u: goto P_0c0b9704;
case 0x0c0b9706u: goto P_0c0b9706;
case 0x0c0b9708u: goto P_0c0b9708;
case 0x0c0b970au: goto P_0c0b970a;
case 0x0c0b970cu: goto P_0c0b970c;
case 0x0c0b970eu: goto P_0c0b970e;
case 0x0c0b9710u: goto P_0c0b9710;
case 0x0c0b9712u: goto P_0c0b9712;
case 0x0c0b9714u: goto P_0c0b9714;
case 0x0c0b9716u: goto P_0c0b9716;
case 0x0c0b9718u: goto P_0c0b9718;
case 0x0c0b971au: goto P_0c0b971a;
case 0x0c0b971cu: goto P_0c0b971c;
case 0x0c0b971eu: goto P_0c0b971e;
case 0x0c0b9720u: goto P_0c0b9720;
case 0x0c0b9722u: goto P_0c0b9722;
case 0x0c0b9724u: goto P_0c0b9724;
case 0x0c0b9726u: goto P_0c0b9726;
case 0x0c0b9728u: goto P_0c0b9728;
case 0x0c0b972au: goto P_0c0b972a;
case 0x0c0b972cu: goto P_0c0b972c;
case 0x0c0b972eu: goto P_0c0b972e;
case 0x0c0b9730u: goto P_0c0b9730;
case 0x0c0b9732u: goto P_0c0b9732;
case 0x0c0b9734u: goto P_0c0b9734;
case 0x0c0b9736u: goto P_0c0b9736;
case 0x0c0b9738u: goto P_0c0b9738;
case 0x0c0b973au: goto P_0c0b973a;
case 0x0c0b973cu: goto P_0c0b973c;
case 0x0c0b973eu: goto P_0c0b973e;
case 0x0c0b9740u: goto P_0c0b9740;
case 0x0c0b9742u: goto P_0c0b9742;
case 0x0c0b9744u: goto P_0c0b9744;
case 0x0c0b9746u: goto P_0c0b9746;
case 0x0c0b9748u: goto P_0c0b9748;
case 0x0c0b974au: goto P_0c0b974a;
case 0x0c0b974cu: goto P_0c0b974c;
case 0x0c0b974eu: goto P_0c0b974e;
case 0x0c0b9750u: goto P_0c0b9750;
case 0x0c0b9752u: goto P_0c0b9752;
case 0x0c0b9754u: goto P_0c0b9754;
case 0x0c0b9756u: goto P_0c0b9756;
case 0x0c0b9758u: goto P_0c0b9758;
case 0x0c0b975au: goto P_0c0b975a;
case 0x0c0b975cu: goto P_0c0b975c;
case 0x0c0b975eu: goto P_0c0b975e;
case 0x0c0b9760u: goto P_0c0b9760;
case 0x0c0b9762u: goto P_0c0b9762;
case 0x0c0b9764u: goto P_0c0b9764;
case 0x0c0b9766u: goto P_0c0b9766;
case 0x0c0b9768u: goto P_0c0b9768;
case 0x0c0b976au: goto P_0c0b976a;
case 0x0c0b976cu: goto P_0c0b976c;
case 0x0c0b976eu: goto P_0c0b976e;
case 0x0c0b9770u: goto P_0c0b9770;
case 0x0c0b9772u: goto P_0c0b9772;
case 0x0c0b9774u: goto P_0c0b9774;
case 0x0c0b9776u: goto P_0c0b9776;
case 0x0c0b9778u: goto P_0c0b9778;
case 0x0c0b977au: goto P_0c0b977a;
case 0x0c0b977cu: goto P_0c0b977c;
case 0x0c0b977eu: goto P_0c0b977e;
case 0x0c0b9780u: goto P_0c0b9780;
case 0x0c0b9782u: goto P_0c0b9782;
case 0x0c0b9784u: goto P_0c0b9784;
case 0x0c0b9786u: goto P_0c0b9786;
case 0x0c0b9788u: goto P_0c0b9788;
case 0x0c0b978au: goto P_0c0b978a;
case 0x0c0b978cu: goto P_0c0b978c;
case 0x0c0b978eu: goto P_0c0b978e;
case 0x0c0b9790u: goto P_0c0b9790;
case 0x0c0b9792u: goto P_0c0b9792;
case 0x0c0b9794u: goto P_0c0b9794;
case 0x0c0b9796u: goto P_0c0b9796;
case 0x0c0b9798u: goto P_0c0b9798;
case 0x0c0b979au: goto P_0c0b979a;
case 0x0c0b979cu: goto P_0c0b979c;
case 0x0c0b979eu: goto P_0c0b979e;
case 0x0c0b97a0u: goto P_0c0b97a0;
case 0x0c0b97a2u: goto P_0c0b97a2;
case 0x0c0b97a4u: goto P_0c0b97a4;
case 0x0c0b97a6u: goto P_0c0b97a6;
case 0x0c0b97a8u: goto P_0c0b97a8;
case 0x0c0b97aau: goto P_0c0b97aa;
case 0x0c0b97acu: goto P_0c0b97ac;
case 0x0c0b97aeu: goto P_0c0b97ae;
case 0x0c0b97b0u: goto P_0c0b97b0;
case 0x0c0b97b2u: goto P_0c0b97b2;
case 0x0c0b97b4u: goto P_0c0b97b4;
case 0x0c0b97b6u: goto P_0c0b97b6;
case 0x0c0b97b8u: goto P_0c0b97b8;
case 0x0c0b97bau: goto P_0c0b97ba;
case 0x0c0b97bcu: goto P_0c0b97bc;
case 0x0c0b97beu: goto P_0c0b97be;
case 0x0c0b97c0u: goto P_0c0b97c0;
case 0x0c0b97c2u: goto P_0c0b97c2;
case 0x0c0b97c4u: goto P_0c0b97c4;
case 0x0c0b97c6u: goto P_0c0b97c6;
case 0x0c0b97c8u: goto P_0c0b97c8;
case 0x0c0b97cau: goto P_0c0b97ca;
case 0x0c0b97ccu: goto P_0c0b97cc;
case 0x0c0b97ceu: goto P_0c0b97ce;
case 0x0c0b97d0u: goto P_0c0b97d0;
case 0x0c0b97d2u: goto P_0c0b97d2;
case 0x0c0b97d4u: goto P_0c0b97d4;
case 0x0c0b97d6u: goto P_0c0b97d6;
case 0x0c0b97d8u: goto P_0c0b97d8;
case 0x0c0b97dau: goto P_0c0b97da;
case 0x0c0b97dcu: goto P_0c0b97dc;
case 0x0c0b97deu: goto P_0c0b97de;
case 0x0c0b97e0u: goto P_0c0b97e0;
case 0x0c0b97e2u: goto P_0c0b97e2;
case 0x0c0b97e4u: goto P_0c0b97e4;
case 0x0c0b97e6u: goto P_0c0b97e6;
case 0x0c0b97e8u: goto P_0c0b97e8;
case 0x0c0b97eau: goto P_0c0b97ea;
case 0x0c0b97ecu: goto P_0c0b97ec;
case 0x0c0b97eeu: goto P_0c0b97ee;
case 0x0c0b97f0u: goto P_0c0b97f0;
case 0x0c0b97f2u: goto P_0c0b97f2;
case 0x0c0b97f4u: goto P_0c0b97f4;
case 0x0c0b97f6u: goto P_0c0b97f6;
case 0x0c0b97f8u: goto P_0c0b97f8;
case 0x0c0b97fau: goto P_0c0b97fa;
case 0x0c0b97fcu: goto P_0c0b97fc;
case 0x0c0b97feu: goto P_0c0b97fe;
case 0x0c0b9800u: goto P_0c0b9800;
case 0x0c0b9802u: goto P_0c0b9802;
case 0x0c0b9804u: goto P_0c0b9804;
case 0x0c0b9806u: goto P_0c0b9806;
case 0x0c0b9808u: goto P_0c0b9808;
case 0x0c0b980au: goto P_0c0b980a;
case 0x0c0b980cu: goto P_0c0b980c;
case 0x0c0b980eu: goto P_0c0b980e;
case 0x0c0b9810u: goto P_0c0b9810;
case 0x0c0b9812u: goto P_0c0b9812;
case 0x0c0b9814u: goto P_0c0b9814;
case 0x0c0b9816u: goto P_0c0b9816;
case 0x0c0b9818u: goto P_0c0b9818;
case 0x0c0b981au: goto P_0c0b981a;
case 0x0c0b981cu: goto P_0c0b981c;
case 0x0c0b981eu: goto P_0c0b981e;
case 0x0c0b9820u: goto P_0c0b9820;
case 0x0c0b9822u: goto P_0c0b9822;
case 0x0c0b9824u: goto P_0c0b9824;
case 0x0c0b9826u: goto P_0c0b9826;
case 0x0c0b9828u: goto P_0c0b9828;
case 0x0c0b982au: goto P_0c0b982a;
case 0x0c0b982cu: goto P_0c0b982c;
case 0x0c0b982eu: goto P_0c0b982e;
case 0x0c0b9830u: goto P_0c0b9830;
case 0x0c0b9832u: goto P_0c0b9832;
case 0x0c0b9834u: goto P_0c0b9834;
case 0x0c0b9836u: goto P_0c0b9836;
case 0x0c0b9838u: goto P_0c0b9838;
case 0x0c0b983au: goto P_0c0b983a;
case 0x0c0b983cu: goto P_0c0b983c;
case 0x0c0b983eu: goto P_0c0b983e;
case 0x0c0b9840u: goto P_0c0b9840;
case 0x0c0b9842u: goto P_0c0b9842;
case 0x0c0b9844u: goto P_0c0b9844;
case 0x0c0b9846u: goto P_0c0b9846;
case 0x0c0bbde2u: goto P_0c0bbde2;
case 0x0c0bbde4u: goto P_0c0bbde4;
case 0x0c0bbde6u: goto P_0c0bbde6;
case 0x0c0bbde8u: goto P_0c0bbde8;
case 0x0c0bbdeau: goto P_0c0bbdea;
case 0x0c0bbdecu: goto P_0c0bbdec;
case 0x0c0bbdeeu: goto P_0c0bbdee;
case 0x0c0bbdf0u: goto P_0c0bbdf0;
case 0x0c0bbdf2u: goto P_0c0bbdf2;
case 0x0c0bbdf4u: goto P_0c0bbdf4;
case 0x0c0bbdf6u: goto P_0c0bbdf6;
case 0x0c0bbdf8u: goto P_0c0bbdf8;
case 0x0c0bbdfau: goto P_0c0bbdfa;
case 0x0c0bbdfcu: goto P_0c0bbdfc;
case 0x0c0bbdfeu: goto P_0c0bbdfe;
case 0x0c0bbe00u: goto P_0c0bbe00;
case 0x0c0bbe02u: goto P_0c0bbe02;
case 0x0c0bbe04u: goto P_0c0bbe04;
case 0x0c0bbe06u: goto P_0c0bbe06;
case 0x0c0bbe08u: goto P_0c0bbe08;
case 0x0c0bbe0au: goto P_0c0bbe0a;
case 0x0c0bbe0cu: goto P_0c0bbe0c;
case 0x0c0bbe0eu: goto P_0c0bbe0e;
case 0x0c0bbe10u: goto P_0c0bbe10;
case 0x0c0bbe12u: goto P_0c0bbe12;
case 0x0c0bbe14u: goto P_0c0bbe14;
case 0x0c0bbe16u: goto P_0c0bbe16;
case 0x0c0bbe18u: goto P_0c0bbe18;
case 0x0c0bbe1au: goto P_0c0bbe1a;
case 0x0c0bbe1cu: goto P_0c0bbe1c;
case 0x0c0bbe1eu: goto P_0c0bbe1e;
case 0x0c0bbe20u: goto P_0c0bbe20;
case 0x0c0bbe22u: goto P_0c0bbe22;
case 0x0c0bbe24u: goto P_0c0bbe24;
case 0x0c0bbe26u: goto P_0c0bbe26;
case 0x0c0bbe28u: goto P_0c0bbe28;
case 0x0c0bbe2au: goto P_0c0bbe2a;
case 0x0c0bbe2cu: goto P_0c0bbe2c;
case 0x0c0bbe2eu: goto P_0c0bbe2e;
case 0x0c0bbe30u: goto P_0c0bbe30;
case 0x0c0bbe32u: goto P_0c0bbe32;
case 0x0c0bbe34u: goto P_0c0bbe34;
case 0x0c0bbe36u: goto P_0c0bbe36;
case 0x0c0bbe38u: goto P_0c0bbe38;
case 0x0c0bbe3au: goto P_0c0bbe3a;
case 0x0c0bbe3cu: goto P_0c0bbe3c;
case 0x0c0bbe3eu: goto P_0c0bbe3e;
case 0x0c0bbe40u: goto P_0c0bbe40;
case 0x0c0bbe42u: goto P_0c0bbe42;
case 0x0c0bbe44u: goto P_0c0bbe44;
case 0x0c0bbe46u: goto P_0c0bbe46;
case 0x0c0bbe48u: goto P_0c0bbe48;
case 0x0c0bbe4au: goto P_0c0bbe4a;
case 0x0c0bbe4cu: goto P_0c0bbe4c;
case 0x0c0bbe4eu: goto P_0c0bbe4e;
case 0x0c0bbe50u: goto P_0c0bbe50;
case 0x0c0bbe52u: goto P_0c0bbe52;
case 0x0c0bbe54u: goto P_0c0bbe54;
case 0x0c0bbe56u: goto P_0c0bbe56;
case 0x0c0bbe58u: goto P_0c0bbe58;
case 0x0c0bbe5au: goto P_0c0bbe5a;
case 0x0c0bbe5cu: goto P_0c0bbe5c;
case 0x0c0bbe5eu: goto P_0c0bbe5e;
case 0x0c0bbe60u: goto P_0c0bbe60;
case 0x0c0bbe62u: goto P_0c0bbe62;
case 0x0c0bbe64u: goto P_0c0bbe64;
case 0x0c0bbe66u: goto P_0c0bbe66;
case 0x0c0bbe68u: goto P_0c0bbe68;
case 0x0c0bbe6au: goto P_0c0bbe6a;
case 0x0c0bbe6cu: goto P_0c0bbe6c;
case 0x0c0bbe6eu: goto P_0c0bbe6e;
case 0x0c0bbe70u: goto P_0c0bbe70;
case 0x0c0bbe72u: goto P_0c0bbe72;
case 0x0c0bbe74u: goto P_0c0bbe74;
case 0x0c0bbe76u: goto P_0c0bbe76;
case 0x0c0bbe78u: goto P_0c0bbe78;
case 0x0c0bbe7au: goto P_0c0bbe7a;
case 0x0c0bbe7cu: goto P_0c0bbe7c;
case 0x0c0bbe7eu: goto P_0c0bbe7e;
case 0x0c0bbe80u: goto P_0c0bbe80;
case 0x0c0bbe82u: goto P_0c0bbe82;
case 0x0c0bbe84u: goto P_0c0bbe84;
case 0x0c0bbe86u: goto P_0c0bbe86;
case 0x0c0bbe88u: goto P_0c0bbe88;
case 0x0c0bbe8au: goto P_0c0bbe8a;
case 0x0c0bbe8cu: goto P_0c0bbe8c;
case 0x0c0bbe8eu: goto P_0c0bbe8e;
case 0x0c0bbe90u: goto P_0c0bbe90;
case 0x0c0bbe92u: goto P_0c0bbe92;
case 0x0c0bbe94u: goto P_0c0bbe94;
case 0x0c0bbe96u: goto P_0c0bbe96;
case 0x0c0bbe98u: goto P_0c0bbe98;
case 0x0c0bbe9au: goto P_0c0bbe9a;
case 0x0c0bbe9cu: goto P_0c0bbe9c;
case 0x0c0bbe9eu: goto P_0c0bbe9e;
case 0x0c0bbea0u: goto P_0c0bbea0;
case 0x0c0bbea2u: goto P_0c0bbea2;
case 0x0c0bbea4u: goto P_0c0bbea4;
case 0x0c0bbea6u: goto P_0c0bbea6;
case 0x0c0bbea8u: goto P_0c0bbea8;
case 0x0c0bbeaau: goto P_0c0bbeaa;
case 0x0c0bbeacu: goto P_0c0bbeac;
case 0x0c0bbeaeu: goto P_0c0bbeae;
case 0x0c0bbeb0u: goto P_0c0bbeb0;
case 0x0c0bbeb2u: goto P_0c0bbeb2;
case 0x0c0bbeb4u: goto P_0c0bbeb4;
case 0x0c0bbeb6u: goto P_0c0bbeb6;
case 0x0c0bbeb8u: goto P_0c0bbeb8;
case 0x0c0bbebau: goto P_0c0bbeba;
case 0x0c0bbebcu: goto P_0c0bbebc;
case 0x0c0bbebeu: goto P_0c0bbebe;
case 0x0c0bbec0u: goto P_0c0bbec0;
case 0x0c0bbec2u: goto P_0c0bbec2;
case 0x0c0bbec4u: goto P_0c0bbec4;
case 0x0c0bbec6u: goto P_0c0bbec6;
case 0x0c0bbec8u: goto P_0c0bbec8;
case 0x0c0bbecau: goto P_0c0bbeca;
case 0x0c0bbeccu: goto P_0c0bbecc;
case 0x0c0bbeceu: goto P_0c0bbece;
case 0x0c0bbed0u: goto P_0c0bbed0;
case 0x0c0bbed2u: goto P_0c0bbed2;
case 0x0c0bbed4u: goto P_0c0bbed4;
case 0x0c0bbed6u: goto P_0c0bbed6;
case 0x0c0bbed8u: goto P_0c0bbed8;
case 0x0c0bbedau: goto P_0c0bbeda;
case 0x0c0bbedcu: goto P_0c0bbedc;
case 0x0c0bbedeu: goto P_0c0bbede;
case 0x0c0bbee0u: goto P_0c0bbee0;
case 0x0c0bbee2u: goto P_0c0bbee2;
case 0x0c0bbee4u: goto P_0c0bbee4;
case 0x0c0bbee6u: goto P_0c0bbee6;
case 0x0c0bbee8u: goto P_0c0bbee8;
case 0x0c0bbeeau: goto P_0c0bbeea;
case 0x0c0bbeecu: goto P_0c0bbeec;
case 0x0c0bbeeeu: goto P_0c0bbeee;
case 0x0c0bbef0u: goto P_0c0bbef0;
case 0x0c0bbef2u: goto P_0c0bbef2;
case 0x0c0bbef4u: goto P_0c0bbef4;
case 0x0c0bbef6u: goto P_0c0bbef6;
case 0x0c0bbef8u: goto P_0c0bbef8;
case 0x0c0bbefau: goto P_0c0bbefa;
case 0x0c0bbefcu: goto P_0c0bbefc;
case 0x0c0bbefeu: goto P_0c0bbefe;
case 0x0c0bbf00u: goto P_0c0bbf00;
case 0x0c0bbf02u: goto P_0c0bbf02;
case 0x0c0bbf04u: goto P_0c0bbf04;
case 0x0c0bbf06u: goto P_0c0bbf06;
case 0x0c0bbf08u: goto P_0c0bbf08;
case 0x0c0bbf0au: goto P_0c0bbf0a;
case 0x0c0bbf0cu: goto P_0c0bbf0c;
case 0x0c0bbf0eu: goto P_0c0bbf0e;
case 0x0c0bbf10u: goto P_0c0bbf10;
case 0x0c0bbf12u: goto P_0c0bbf12;
case 0x0c0bbf14u: goto P_0c0bbf14;
case 0x0c0bbf16u: goto P_0c0bbf16;
case 0x0c0bbf18u: goto P_0c0bbf18;
case 0x0c0bbf1au: goto P_0c0bbf1a;
case 0x0c0bbf1cu: goto P_0c0bbf1c;
case 0x0c0bbf1eu: goto P_0c0bbf1e;
case 0x0c0bbf20u: goto P_0c0bbf20;
case 0x0c0bbf22u: goto P_0c0bbf22;
case 0x0c0bbf24u: goto P_0c0bbf24;
case 0x0c0bbf26u: goto P_0c0bbf26;
case 0x0c0bbf28u: goto P_0c0bbf28;
case 0x0c0bbf2au: goto P_0c0bbf2a;
case 0x0c0bbf2cu: goto P_0c0bbf2c;
case 0x0c0bbf2eu: goto P_0c0bbf2e;
case 0x0c0bbf30u: goto P_0c0bbf30;
case 0x0c0bbf32u: goto P_0c0bbf32;
case 0x0c0bbf34u: goto P_0c0bbf34;
case 0x0c0bbf36u: goto P_0c0bbf36;
case 0x0c0bbf38u: goto P_0c0bbf38;
case 0x0c0bbfa8u: goto P_0c0bbfa8;
case 0x0c0bbfaau: goto P_0c0bbfaa;
case 0x0c0bbfacu: goto P_0c0bbfac;
case 0x0c0bbfaeu: goto P_0c0bbfae;
case 0x0c0bbfb0u: goto P_0c0bbfb0;
case 0x0c0bbfb2u: goto P_0c0bbfb2;
case 0x0c0bbfb4u: goto P_0c0bbfb4;
case 0x0c0bbfb6u: goto P_0c0bbfb6;
case 0x0c0bbfb8u: goto P_0c0bbfb8;
case 0x0c0bbfbau: goto P_0c0bbfba;
case 0x0c0bbfbcu: goto P_0c0bbfbc;
case 0x0c0bbfbeu: goto P_0c0bbfbe;
case 0x0c0bbfc0u: goto P_0c0bbfc0;
case 0x0c0bbfc2u: goto P_0c0bbfc2;
case 0x0c0bbfc4u: goto P_0c0bbfc4;
case 0x0c0bbfc6u: goto P_0c0bbfc6;
case 0x0c0bbfc8u: goto P_0c0bbfc8;
case 0x0c0bbfcau: goto P_0c0bbfca;
case 0x0c0bbfccu: goto P_0c0bbfcc;
case 0x0c0bbfceu: goto P_0c0bbfce;
case 0x0c0bbfd0u: goto P_0c0bbfd0;
case 0x0c0bbfd2u: goto P_0c0bbfd2;
case 0x0c0bbfd4u: goto P_0c0bbfd4;
case 0x0c0bbfd6u: goto P_0c0bbfd6;
case 0x0c0bbfd8u: goto P_0c0bbfd8;
case 0x0c0bbfdau: goto P_0c0bbfda;
case 0x0c0bbfdcu: goto P_0c0bbfdc;
case 0x0c0bbfdeu: goto P_0c0bbfde;
case 0x0c0bbfe0u: goto P_0c0bbfe0;
case 0x0c0bbfe2u: goto P_0c0bbfe2;
case 0x0c0bbfe4u: goto P_0c0bbfe4;
case 0x0c0bbfe6u: goto P_0c0bbfe6;
case 0x0c0bbfe8u: goto P_0c0bbfe8;
case 0x0c0bbfeau: goto P_0c0bbfea;
case 0x0c0bbfecu: goto P_0c0bbfec;
case 0x0c0bbfeeu: goto P_0c0bbfee;
case 0x0c0bbff0u: goto P_0c0bbff0;
case 0x0c0bbff2u: goto P_0c0bbff2;
case 0x0c0bbff4u: goto P_0c0bbff4;
case 0x0c0bbff6u: goto P_0c0bbff6;
case 0x0c0bbff8u: goto P_0c0bbff8;
case 0x0c0bbffau: goto P_0c0bbffa;
case 0x0c0bbffcu: goto P_0c0bbffc;
case 0x0c0bbffeu: goto P_0c0bbffe;
case 0x0c0bc000u: goto P_0c0bc000;
case 0x0c0bc002u: goto P_0c0bc002;
case 0x0c0bc004u: goto P_0c0bc004;
case 0x0c0bc006u: goto P_0c0bc006;
case 0x0c0bc008u: goto P_0c0bc008;
case 0x0c0bc00au: goto P_0c0bc00a;
case 0x0c0bc00cu: goto P_0c0bc00c;
case 0x0c0bc00eu: goto P_0c0bc00e;
case 0x0c0bc010u: goto P_0c0bc010;
case 0x0c0bc012u: goto P_0c0bc012;
case 0x0c0bc014u: goto P_0c0bc014;
case 0x0c0bc016u: goto P_0c0bc016;
case 0x0c0bc018u: goto P_0c0bc018;
case 0x0c0bc01au: goto P_0c0bc01a;
case 0x0c0bc01cu: goto P_0c0bc01c;
case 0x0c0bc01eu: goto P_0c0bc01e;
case 0x0c0bc020u: goto P_0c0bc020;
case 0x0c0bc022u: goto P_0c0bc022;
case 0x0c0bc024u: goto P_0c0bc024;
case 0x0c0bc026u: goto P_0c0bc026;
case 0x0c0bc028u: goto P_0c0bc028;
case 0x0c0bc02au: goto P_0c0bc02a;
case 0x0c0bc02cu: goto P_0c0bc02c;
case 0x0c0bc02eu: goto P_0c0bc02e;
case 0x0c0bc030u: goto P_0c0bc030;
case 0x0c0bc032u: goto P_0c0bc032;
case 0x0c0bc034u: goto P_0c0bc034;
case 0x0c0bc036u: goto P_0c0bc036;
case 0x0c0bc038u: goto P_0c0bc038;
case 0x0c0bc03au: goto P_0c0bc03a;
case 0x0c0bc03cu: goto P_0c0bc03c;
case 0x0c0bc03eu: goto P_0c0bc03e;
case 0x0c0bc040u: goto P_0c0bc040;
case 0x0c0bc042u: goto P_0c0bc042;
case 0x0c0bc044u: goto P_0c0bc044;
case 0x0c0bc046u: goto P_0c0bc046;
case 0x0c0bc048u: goto P_0c0bc048;
case 0x0c0bc04au: goto P_0c0bc04a;
case 0x0c0bc04cu: goto P_0c0bc04c;
case 0x0c0bc04eu: goto P_0c0bc04e;
case 0x0c0bc050u: goto P_0c0bc050;
case 0x0c0bc052u: goto P_0c0bc052;
case 0x0c0bc054u: goto P_0c0bc054;
case 0x0c0bc056u: goto P_0c0bc056;
case 0x0c0bc058u: goto P_0c0bc058;
case 0x0c0bc05au: goto P_0c0bc05a;
case 0x0c0bc05cu: goto P_0c0bc05c;
case 0x0c0bc05eu: goto P_0c0bc05e;
case 0x0c0bc060u: goto P_0c0bc060;
case 0x0c0bc062u: goto P_0c0bc062;
case 0x0c0bc064u: goto P_0c0bc064;
case 0x0c0bc066u: goto P_0c0bc066;
case 0x0c0bc068u: goto P_0c0bc068;
case 0x0c0bc06au: goto P_0c0bc06a;
case 0x0c0bc06cu: goto P_0c0bc06c;
case 0x0c0bc06eu: goto P_0c0bc06e;
case 0x0c0bc070u: goto P_0c0bc070;
case 0x0c0bc072u: goto P_0c0bc072;
case 0x0c0bc074u: goto P_0c0bc074;
case 0x0c0bc076u: goto P_0c0bc076;
case 0x0c0bc078u: goto P_0c0bc078;
case 0x0c0bc07au: goto P_0c0bc07a;
case 0x0c0bc07cu: goto P_0c0bc07c;
case 0x0c0bc07eu: goto P_0c0bc07e;
case 0x0c0bc080u: goto P_0c0bc080;
case 0x0c0bc082u: goto P_0c0bc082;
case 0x0c0bc084u: goto P_0c0bc084;
case 0x0c0bc086u: goto P_0c0bc086;
case 0x0c0bc088u: goto P_0c0bc088;
case 0x0c0bc08au: goto P_0c0bc08a;
case 0x0c0bc08cu: goto P_0c0bc08c;
case 0x0c0bc08eu: goto P_0c0bc08e;
case 0x0c0bc090u: goto P_0c0bc090;
case 0x0c0bc092u: goto P_0c0bc092;
case 0x0c0bc094u: goto P_0c0bc094;
case 0x0c0bc096u: goto P_0c0bc096;
case 0x0c0bc098u: goto P_0c0bc098;
case 0x0c0bc09au: goto P_0c0bc09a;
case 0x0c0bc09cu: goto P_0c0bc09c;
case 0x0c0bc09eu: goto P_0c0bc09e;
case 0x0c0bc0a0u: goto P_0c0bc0a0;
case 0x0c0bc0a2u: goto P_0c0bc0a2;
case 0x0c0bc0a4u: goto P_0c0bc0a4;
case 0x0c0bc0a6u: goto P_0c0bc0a6;
case 0x0c0bc0a8u: goto P_0c0bc0a8;
case 0x0c0bc0aau: goto P_0c0bc0aa;
case 0x0c0bc0acu: goto P_0c0bc0ac;
case 0x0c0bc0aeu: goto P_0c0bc0ae;
case 0x0c0bc0b0u: goto P_0c0bc0b0;
case 0x0c0bc0b2u: goto P_0c0bc0b2;
case 0x0c0bc0b4u: goto P_0c0bc0b4;
case 0x0c0bc0b6u: goto P_0c0bc0b6;
case 0x0c0bc0b8u: goto P_0c0bc0b8;
case 0x0c0bc0bau: goto P_0c0bc0ba;
case 0x0c0bc0bcu: goto P_0c0bc0bc;
case 0x0c0bc0beu: goto P_0c0bc0be;
case 0x0c0bc0c0u: goto P_0c0bc0c0;
case 0x0c0bc0c2u: goto P_0c0bc0c2;
case 0x0c0bc0c4u: goto P_0c0bc0c4;
case 0x0c0bc0c6u: goto P_0c0bc0c6;
case 0x0c0bc0c8u: goto P_0c0bc0c8;
case 0x0c0bc0cau: goto P_0c0bc0ca;
case 0x0c0bc0ccu: goto P_0c0bc0cc;
case 0x0c0bc0ceu: goto P_0c0bc0ce;
case 0x0c0bc0d0u: goto P_0c0bc0d0;
case 0x0c0bc0d2u: goto P_0c0bc0d2;
case 0x0c0bc0d4u: goto P_0c0bc0d4;
case 0x0c0bc0d6u: goto P_0c0bc0d6;
case 0x0c0bc0d8u: goto P_0c0bc0d8;
case 0x0c0bc0dau: goto P_0c0bc0da;
case 0x0c0bc0dcu: goto P_0c0bc0dc;
case 0x0c0bc0deu: goto P_0c0bc0de;
case 0x0c0bc0e0u: goto P_0c0bc0e0;
case 0x0c0bc0e2u: goto P_0c0bc0e2;
case 0x0c0bc0e4u: goto P_0c0bc0e4;
case 0x0c0bc0e6u: goto P_0c0bc0e6;
case 0x0c0bc0e8u: goto P_0c0bc0e8;
case 0x0c0bc0eau: goto P_0c0bc0ea;
case 0x0c0bc0ecu: goto P_0c0bc0ec;
case 0x0c0bc0eeu: goto P_0c0bc0ee;
case 0x0c0bc0f0u: goto P_0c0bc0f0;
case 0x0c0bc0f2u: goto P_0c0bc0f2;
case 0x0c0bc0f4u: goto P_0c0bc0f4;
case 0x0c0bc0f6u: goto P_0c0bc0f6;
case 0x0c0bc0f8u: goto P_0c0bc0f8;
case 0x0c0bc0fau: goto P_0c0bc0fa;
case 0x0c0bc0fcu: goto P_0c0bc0fc;
case 0x0c0bc0feu: goto P_0c0bc0fe;
case 0x0c0bc100u: goto P_0c0bc100;
case 0x0c0bc17au: goto P_0c0bc17a;
case 0x0c0bc17cu: goto P_0c0bc17c;
case 0x0c0bc17eu: goto P_0c0bc17e;
case 0x0c0bc180u: goto P_0c0bc180;
case 0x0c0bc182u: goto P_0c0bc182;
case 0x0c0bc184u: goto P_0c0bc184;
case 0x0c0bc186u: goto P_0c0bc186;
case 0x0c0bc188u: goto P_0c0bc188;
case 0x0c0bc18au: goto P_0c0bc18a;
case 0x0c0bc18cu: goto P_0c0bc18c;
case 0x0c0bc18eu: goto P_0c0bc18e;
case 0x0c0bc190u: goto P_0c0bc190;
case 0x0c0bc192u: goto P_0c0bc192;
case 0x0c0bc194u: goto P_0c0bc194;
case 0x0c0bc196u: goto P_0c0bc196;
case 0x0c0bc198u: goto P_0c0bc198;
case 0x0c0bc19au: goto P_0c0bc19a;
case 0x0c0bc19cu: goto P_0c0bc19c;
case 0x0c0bc19eu: goto P_0c0bc19e;
case 0x0c0bc1a0u: goto P_0c0bc1a0;
case 0x0c0bc1a2u: goto P_0c0bc1a2;
case 0x0c0bc1a4u: goto P_0c0bc1a4;
case 0x0c0bc1a6u: goto P_0c0bc1a6;
case 0x0c0bc1a8u: goto P_0c0bc1a8;
case 0x0c0bc1aau: goto P_0c0bc1aa;
case 0x0c0bc1acu: goto P_0c0bc1ac;
case 0x0c0bc1aeu: goto P_0c0bc1ae;
case 0x0c0bc1b0u: goto P_0c0bc1b0;
case 0x0c0bc1b2u: goto P_0c0bc1b2;
case 0x0c0bc1b4u: goto P_0c0bc1b4;
case 0x0c0bc1b6u: goto P_0c0bc1b6;
case 0x0c0bc1b8u: goto P_0c0bc1b8;
case 0x0c0bc1bau: goto P_0c0bc1ba;
case 0x0c0bc1bcu: goto P_0c0bc1bc;
case 0x0c0bc1beu: goto P_0c0bc1be;
case 0x0c0bc1c0u: goto P_0c0bc1c0;
case 0x0c0bc1c2u: goto P_0c0bc1c2;
case 0x0c0bc1c4u: goto P_0c0bc1c4;
case 0x0c0bc1c6u: goto P_0c0bc1c6;
case 0x0c0bc1c8u: goto P_0c0bc1c8;
case 0x0c0bc1cau: goto P_0c0bc1ca;
case 0x0c0bc1ccu: goto P_0c0bc1cc;
case 0x0c0bc1ceu: goto P_0c0bc1ce;
case 0x0c0bc1d0u: goto P_0c0bc1d0;
case 0x0c0bc1d2u: goto P_0c0bc1d2;
case 0x0c0bc1d4u: goto P_0c0bc1d4;
case 0x0c0bc1d6u: goto P_0c0bc1d6;
case 0x0c0bc1d8u: goto P_0c0bc1d8;
case 0x0c0bc1dau: goto P_0c0bc1da;
case 0x0c0bc1dcu: goto P_0c0bc1dc;
case 0x0c0bc1deu: goto P_0c0bc1de;
case 0x0c0bc1e0u: goto P_0c0bc1e0;
case 0x0c0bc1e2u: goto P_0c0bc1e2;
case 0x0c0bc1e4u: goto P_0c0bc1e4;
case 0x0c0bc1e6u: goto P_0c0bc1e6;
case 0x0c0bc1e8u: goto P_0c0bc1e8;
case 0x0c0bc1eau: goto P_0c0bc1ea;
case 0x0c0bc1ecu: goto P_0c0bc1ec;
case 0x0c0bc1eeu: goto P_0c0bc1ee;
case 0x0c0bc1f0u: goto P_0c0bc1f0;
case 0x0c0bc1f2u: goto P_0c0bc1f2;
case 0x0c0bc1f4u: goto P_0c0bc1f4;
case 0x0c0bc1f6u: goto P_0c0bc1f6;
case 0x0c0bc1f8u: goto P_0c0bc1f8;
case 0x0c0bc1fau: goto P_0c0bc1fa;
case 0x0c0bc1fcu: goto P_0c0bc1fc;
case 0x0c0bc1feu: goto P_0c0bc1fe;
case 0x0c0bc200u: goto P_0c0bc200;
case 0x0c0bc202u: goto P_0c0bc202;
case 0x0c0bc204u: goto P_0c0bc204;
case 0x0c0bc206u: goto P_0c0bc206;
case 0x0c0bc208u: goto P_0c0bc208;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b38d0: /* original 4f22, guest PC 0x0c0b38d0 */
if(!s->budget--) { s->failed_pc=0x0c0b38d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b38d2;
P_0c0b38d2: /* original 94a1, guest PC 0x0c0b38d2 */
if(!s->budget--) { s->failed_pc=0x0c0b38d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a18u,2);
goto P_0c0b38d4;
P_0c0b38d4: /* original de6b, guest PC 0x0c0b38d4 */
if(!s->budget--) { s->failed_pc=0x0c0b38d4u; return 0; }
r[14]=read(ram,0x0c0b3a84u,4);
goto P_0c0b38d6;
P_0c0b38d6: /* original 4e0b, guest PC 0x0c0b38d6 */
if(!s->budget--) { s->failed_pc=0x0c0b38d6u; return 0; }
target=r[14];
r[16]=0x0c0b38dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b38dau) { target=s->pc; goto dispatch; }
goto P_0c0b38da;
P_0c0b38d8: /* original 0009, guest PC 0x0c0b38d8 */
if(!s->budget--) { s->failed_pc=0x0c0b38d8u; return 0; }
goto P_0c0b38da;
P_0c0b38da: /* original 949e, guest PC 0x0c0b38da */
if(!s->budget--) { s->failed_pc=0x0c0b38dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a1au,2);
goto P_0c0b38dc;
P_0c0b38dc: /* original 4e0b, guest PC 0x0c0b38dc */
if(!s->budget--) { s->failed_pc=0x0c0b38dcu; return 0; }
target=r[14];
r[16]=0x0c0b38e0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b38e0u) { target=s->pc; goto dispatch; }
goto P_0c0b38e0;
P_0c0b38de: /* original 0009, guest PC 0x0c0b38de */
if(!s->budget--) { s->failed_pc=0x0c0b38deu; return 0; }
goto P_0c0b38e0;
P_0c0b38e0: /* original 949c, guest PC 0x0c0b38e0 */
if(!s->budget--) { s->failed_pc=0x0c0b38e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a1cu,2);
goto P_0c0b38e2;
P_0c0b38e2: /* original 4e0b, guest PC 0x0c0b38e2 */
if(!s->budget--) { s->failed_pc=0x0c0b38e2u; return 0; }
target=r[14];
r[16]=0x0c0b38e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b38e6u) { target=s->pc; goto dispatch; }
goto P_0c0b38e6;
P_0c0b38e4: /* original 0009, guest PC 0x0c0b38e4 */
if(!s->budget--) { s->failed_pc=0x0c0b38e4u; return 0; }
goto P_0c0b38e6;
P_0c0b38e6: /* original 949a, guest PC 0x0c0b38e6 */
if(!s->budget--) { s->failed_pc=0x0c0b38e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a1eu,2);
goto P_0c0b38e8;
P_0c0b38e8: /* original 4e0b, guest PC 0x0c0b38e8 */
if(!s->budget--) { s->failed_pc=0x0c0b38e8u; return 0; }
target=r[14];
r[16]=0x0c0b38ecu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b38ecu) { target=s->pc; goto dispatch; }
goto P_0c0b38ec;
P_0c0b38ea: /* original 0009, guest PC 0x0c0b38ea */
if(!s->budget--) { s->failed_pc=0x0c0b38eau; return 0; }
goto P_0c0b38ec;
P_0c0b38ec: /* original 9498, guest PC 0x0c0b38ec */
if(!s->budget--) { s->failed_pc=0x0c0b38ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a20u,2);
goto P_0c0b38ee;
P_0c0b38ee: /* original 4e0b, guest PC 0x0c0b38ee */
if(!s->budget--) { s->failed_pc=0x0c0b38eeu; return 0; }
target=r[14];
r[16]=0x0c0b38f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b38f2u) { target=s->pc; goto dispatch; }
goto P_0c0b38f2;
P_0c0b38f0: /* original 0009, guest PC 0x0c0b38f0 */
if(!s->budget--) { s->failed_pc=0x0c0b38f0u; return 0; }
goto P_0c0b38f2;
P_0c0b38f2: /* original 9496, guest PC 0x0c0b38f2 */
if(!s->budget--) { s->failed_pc=0x0c0b38f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a22u,2);
goto P_0c0b38f4;
P_0c0b38f4: /* original 4e0b, guest PC 0x0c0b38f4 */
if(!s->budget--) { s->failed_pc=0x0c0b38f4u; return 0; }
target=r[14];
r[16]=0x0c0b38f8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b38f8u) { target=s->pc; goto dispatch; }
goto P_0c0b38f8;
P_0c0b38f6: /* original 0009, guest PC 0x0c0b38f6 */
if(!s->budget--) { s->failed_pc=0x0c0b38f6u; return 0; }
goto P_0c0b38f8;
P_0c0b38f8: /* original 9494, guest PC 0x0c0b38f8 */
if(!s->budget--) { s->failed_pc=0x0c0b38f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a24u,2);
goto P_0c0b38fa;
P_0c0b38fa: /* original 4e0b, guest PC 0x0c0b38fa */
if(!s->budget--) { s->failed_pc=0x0c0b38fau; return 0; }
target=r[14];
r[16]=0x0c0b38feu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b38feu) { target=s->pc; goto dispatch; }
goto P_0c0b38fe;
P_0c0b38fc: /* original 0009, guest PC 0x0c0b38fc */
if(!s->budget--) { s->failed_pc=0x0c0b38fcu; return 0; }
goto P_0c0b38fe;
P_0c0b38fe: /* original 9492, guest PC 0x0c0b38fe */
if(!s->budget--) { s->failed_pc=0x0c0b38feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a26u,2);
goto P_0c0b3900;
P_0c0b3900: /* original 4e0b, guest PC 0x0c0b3900 */
if(!s->budget--) { s->failed_pc=0x0c0b3900u; return 0; }
target=r[14];
r[16]=0x0c0b3904u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3904u) { target=s->pc; goto dispatch; }
goto P_0c0b3904;
P_0c0b3902: /* original 0009, guest PC 0x0c0b3902 */
if(!s->budget--) { s->failed_pc=0x0c0b3902u; return 0; }
goto P_0c0b3904;
P_0c0b3904: /* original 9490, guest PC 0x0c0b3904 */
if(!s->budget--) { s->failed_pc=0x0c0b3904u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a28u,2);
goto P_0c0b3906;
P_0c0b3906: /* original 4e0b, guest PC 0x0c0b3906 */
if(!s->budget--) { s->failed_pc=0x0c0b3906u; return 0; }
target=r[14];
r[16]=0x0c0b390au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b390au) { target=s->pc; goto dispatch; }
goto P_0c0b390a;
P_0c0b3908: /* original 0009, guest PC 0x0c0b3908 */
if(!s->budget--) { s->failed_pc=0x0c0b3908u; return 0; }
goto P_0c0b390a;
P_0c0b390a: /* original 948e, guest PC 0x0c0b390a */
if(!s->budget--) { s->failed_pc=0x0c0b390au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a2au,2);
goto P_0c0b390c;
P_0c0b390c: /* original 4e0b, guest PC 0x0c0b390c */
if(!s->budget--) { s->failed_pc=0x0c0b390cu; return 0; }
target=r[14];
r[16]=0x0c0b3910u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3910u) { target=s->pc; goto dispatch; }
goto P_0c0b3910;
P_0c0b390e: /* original 0009, guest PC 0x0c0b390e */
if(!s->budget--) { s->failed_pc=0x0c0b390eu; return 0; }
goto P_0c0b3910;
P_0c0b3910: /* original 948c, guest PC 0x0c0b3910 */
if(!s->budget--) { s->failed_pc=0x0c0b3910u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a2cu,2);
goto P_0c0b3912;
P_0c0b3912: /* original 4e0b, guest PC 0x0c0b3912 */
if(!s->budget--) { s->failed_pc=0x0c0b3912u; return 0; }
target=r[14];
r[16]=0x0c0b3916u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3916u) { target=s->pc; goto dispatch; }
goto P_0c0b3916;
P_0c0b3914: /* original 0009, guest PC 0x0c0b3914 */
if(!s->budget--) { s->failed_pc=0x0c0b3914u; return 0; }
goto P_0c0b3916;
P_0c0b3916: /* original 948a, guest PC 0x0c0b3916 */
if(!s->budget--) { s->failed_pc=0x0c0b3916u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a2eu,2);
goto P_0c0b3918;
P_0c0b3918: /* original 4e0b, guest PC 0x0c0b3918 */
if(!s->budget--) { s->failed_pc=0x0c0b3918u; return 0; }
target=r[14];
r[16]=0x0c0b391cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b391cu) { target=s->pc; goto dispatch; }
goto P_0c0b391c;
P_0c0b391a: /* original 0009, guest PC 0x0c0b391a */
if(!s->budget--) { s->failed_pc=0x0c0b391au; return 0; }
goto P_0c0b391c;
P_0c0b391c: /* original 9488, guest PC 0x0c0b391c */
if(!s->budget--) { s->failed_pc=0x0c0b391cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a30u,2);
goto P_0c0b391e;
P_0c0b391e: /* original 4e0b, guest PC 0x0c0b391e */
if(!s->budget--) { s->failed_pc=0x0c0b391eu; return 0; }
target=r[14];
r[16]=0x0c0b3922u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3922u) { target=s->pc; goto dispatch; }
goto P_0c0b3922;
P_0c0b3920: /* original 0009, guest PC 0x0c0b3920 */
if(!s->budget--) { s->failed_pc=0x0c0b3920u; return 0; }
goto P_0c0b3922;
P_0c0b3922: /* original 9486, guest PC 0x0c0b3922 */
if(!s->budget--) { s->failed_pc=0x0c0b3922u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a32u,2);
goto P_0c0b3924;
P_0c0b3924: /* original 4e0b, guest PC 0x0c0b3924 */
if(!s->budget--) { s->failed_pc=0x0c0b3924u; return 0; }
target=r[14];
r[16]=0x0c0b3928u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3928u) { target=s->pc; goto dispatch; }
goto P_0c0b3928;
P_0c0b3926: /* original 0009, guest PC 0x0c0b3926 */
if(!s->budget--) { s->failed_pc=0x0c0b3926u; return 0; }
goto P_0c0b3928;
P_0c0b3928: /* original 9484, guest PC 0x0c0b3928 */
if(!s->budget--) { s->failed_pc=0x0c0b3928u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a34u,2);
goto P_0c0b392a;
P_0c0b392a: /* original 4e0b, guest PC 0x0c0b392a */
if(!s->budget--) { s->failed_pc=0x0c0b392au; return 0; }
target=r[14];
r[16]=0x0c0b392eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b392eu) { target=s->pc; goto dispatch; }
goto P_0c0b392e;
P_0c0b392c: /* original 0009, guest PC 0x0c0b392c */
if(!s->budget--) { s->failed_pc=0x0c0b392cu; return 0; }
goto P_0c0b392e;
P_0c0b392e: /* original 9482, guest PC 0x0c0b392e */
if(!s->budget--) { s->failed_pc=0x0c0b392eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a36u,2);
goto P_0c0b3930;
P_0c0b3930: /* original 4e0b, guest PC 0x0c0b3930 */
if(!s->budget--) { s->failed_pc=0x0c0b3930u; return 0; }
target=r[14];
r[16]=0x0c0b3934u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3934u) { target=s->pc; goto dispatch; }
goto P_0c0b3934;
P_0c0b3932: /* original 0009, guest PC 0x0c0b3932 */
if(!s->budget--) { s->failed_pc=0x0c0b3932u; return 0; }
goto P_0c0b3934;
P_0c0b3934: /* original 9480, guest PC 0x0c0b3934 */
if(!s->budget--) { s->failed_pc=0x0c0b3934u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a38u,2);
goto P_0c0b3936;
P_0c0b3936: /* original 4e0b, guest PC 0x0c0b3936 */
if(!s->budget--) { s->failed_pc=0x0c0b3936u; return 0; }
target=r[14];
r[16]=0x0c0b393au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b393au) { target=s->pc; goto dispatch; }
goto P_0c0b393a;
P_0c0b3938: /* original 0009, guest PC 0x0c0b3938 */
if(!s->budget--) { s->failed_pc=0x0c0b3938u; return 0; }
goto P_0c0b393a;
P_0c0b393a: /* original 947e, guest PC 0x0c0b393a */
if(!s->budget--) { s->failed_pc=0x0c0b393au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a3au,2);
goto P_0c0b393c;
P_0c0b393c: /* original 4e0b, guest PC 0x0c0b393c */
if(!s->budget--) { s->failed_pc=0x0c0b393cu; return 0; }
target=r[14];
r[16]=0x0c0b3940u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3940u) { target=s->pc; goto dispatch; }
goto P_0c0b3940;
P_0c0b393e: /* original 0009, guest PC 0x0c0b393e */
if(!s->budget--) { s->failed_pc=0x0c0b393eu; return 0; }
goto P_0c0b3940;
P_0c0b3940: /* original 947c, guest PC 0x0c0b3940 */
if(!s->budget--) { s->failed_pc=0x0c0b3940u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a3cu,2);
goto P_0c0b3942;
P_0c0b3942: /* original 4e0b, guest PC 0x0c0b3942 */
if(!s->budget--) { s->failed_pc=0x0c0b3942u; return 0; }
target=r[14];
r[16]=0x0c0b3946u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3946u) { target=s->pc; goto dispatch; }
goto P_0c0b3946;
P_0c0b3944: /* original 0009, guest PC 0x0c0b3944 */
if(!s->budget--) { s->failed_pc=0x0c0b3944u; return 0; }
goto P_0c0b3946;
P_0c0b3946: /* original 947a, guest PC 0x0c0b3946 */
if(!s->budget--) { s->failed_pc=0x0c0b3946u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a3eu,2);
goto P_0c0b3948;
P_0c0b3948: /* original 4e0b, guest PC 0x0c0b3948 */
if(!s->budget--) { s->failed_pc=0x0c0b3948u; return 0; }
target=r[14];
r[16]=0x0c0b394cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b394cu) { target=s->pc; goto dispatch; }
goto P_0c0b394c;
P_0c0b394a: /* original 0009, guest PC 0x0c0b394a */
if(!s->budget--) { s->failed_pc=0x0c0b394au; return 0; }
goto P_0c0b394c;
P_0c0b394c: /* original 9478, guest PC 0x0c0b394c */
if(!s->budget--) { s->failed_pc=0x0c0b394cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a40u,2);
goto P_0c0b394e;
P_0c0b394e: /* original 4e0b, guest PC 0x0c0b394e */
if(!s->budget--) { s->failed_pc=0x0c0b394eu; return 0; }
target=r[14];
r[16]=0x0c0b3952u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3952u) { target=s->pc; goto dispatch; }
goto P_0c0b3952;
P_0c0b3950: /* original 0009, guest PC 0x0c0b3950 */
if(!s->budget--) { s->failed_pc=0x0c0b3950u; return 0; }
goto P_0c0b3952;
P_0c0b3952: /* original 9476, guest PC 0x0c0b3952 */
if(!s->budget--) { s->failed_pc=0x0c0b3952u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a42u,2);
goto P_0c0b3954;
P_0c0b3954: /* original 4e0b, guest PC 0x0c0b3954 */
if(!s->budget--) { s->failed_pc=0x0c0b3954u; return 0; }
target=r[14];
r[16]=0x0c0b3958u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3958u) { target=s->pc; goto dispatch; }
goto P_0c0b3958;
P_0c0b3956: /* original 0009, guest PC 0x0c0b3956 */
if(!s->budget--) { s->failed_pc=0x0c0b3956u; return 0; }
goto P_0c0b3958;
P_0c0b3958: /* original 9474, guest PC 0x0c0b3958 */
if(!s->budget--) { s->failed_pc=0x0c0b3958u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a44u,2);
goto P_0c0b395a;
P_0c0b395a: /* original 4e0b, guest PC 0x0c0b395a */
if(!s->budget--) { s->failed_pc=0x0c0b395au; return 0; }
target=r[14];
r[16]=0x0c0b395eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b395eu) { target=s->pc; goto dispatch; }
goto P_0c0b395e;
P_0c0b395c: /* original 0009, guest PC 0x0c0b395c */
if(!s->budget--) { s->failed_pc=0x0c0b395cu; return 0; }
goto P_0c0b395e;
P_0c0b395e: /* original 9472, guest PC 0x0c0b395e */
if(!s->budget--) { s->failed_pc=0x0c0b395eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a46u,2);
goto P_0c0b3960;
P_0c0b3960: /* original 4e0b, guest PC 0x0c0b3960 */
if(!s->budget--) { s->failed_pc=0x0c0b3960u; return 0; }
target=r[14];
r[16]=0x0c0b3964u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3964u) { target=s->pc; goto dispatch; }
goto P_0c0b3964;
P_0c0b3962: /* original 0009, guest PC 0x0c0b3962 */
if(!s->budget--) { s->failed_pc=0x0c0b3962u; return 0; }
goto P_0c0b3964;
P_0c0b3964: /* original 9470, guest PC 0x0c0b3964 */
if(!s->budget--) { s->failed_pc=0x0c0b3964u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a48u,2);
goto P_0c0b3966;
P_0c0b3966: /* original 4e0b, guest PC 0x0c0b3966 */
if(!s->budget--) { s->failed_pc=0x0c0b3966u; return 0; }
target=r[14];
r[16]=0x0c0b396au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b396au) { target=s->pc; goto dispatch; }
goto P_0c0b396a;
P_0c0b3968: /* original 0009, guest PC 0x0c0b3968 */
if(!s->budget--) { s->failed_pc=0x0c0b3968u; return 0; }
goto P_0c0b396a;
P_0c0b396a: /* original 946e, guest PC 0x0c0b396a */
if(!s->budget--) { s->failed_pc=0x0c0b396au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a4au,2);
goto P_0c0b396c;
P_0c0b396c: /* original 4e0b, guest PC 0x0c0b396c */
if(!s->budget--) { s->failed_pc=0x0c0b396cu; return 0; }
target=r[14];
r[16]=0x0c0b3970u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3970u) { target=s->pc; goto dispatch; }
goto P_0c0b3970;
P_0c0b396e: /* original 0009, guest PC 0x0c0b396e */
if(!s->budget--) { s->failed_pc=0x0c0b396eu; return 0; }
goto P_0c0b3970;
P_0c0b3970: /* original 946c, guest PC 0x0c0b3970 */
if(!s->budget--) { s->failed_pc=0x0c0b3970u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a4cu,2);
goto P_0c0b3972;
P_0c0b3972: /* original 4e0b, guest PC 0x0c0b3972 */
if(!s->budget--) { s->failed_pc=0x0c0b3972u; return 0; }
target=r[14];
r[16]=0x0c0b3976u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3976u) { target=s->pc; goto dispatch; }
goto P_0c0b3976;
P_0c0b3974: /* original 0009, guest PC 0x0c0b3974 */
if(!s->budget--) { s->failed_pc=0x0c0b3974u; return 0; }
goto P_0c0b3976;
P_0c0b3976: /* original 946a, guest PC 0x0c0b3976 */
if(!s->budget--) { s->failed_pc=0x0c0b3976u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a4eu,2);
goto P_0c0b3978;
P_0c0b3978: /* original 4e0b, guest PC 0x0c0b3978 */
if(!s->budget--) { s->failed_pc=0x0c0b3978u; return 0; }
target=r[14];
r[16]=0x0c0b397cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b397cu) { target=s->pc; goto dispatch; }
goto P_0c0b397c;
P_0c0b397a: /* original 0009, guest PC 0x0c0b397a */
if(!s->budget--) { s->failed_pc=0x0c0b397au; return 0; }
goto P_0c0b397c;
P_0c0b397c: /* original 9468, guest PC 0x0c0b397c */
if(!s->budget--) { s->failed_pc=0x0c0b397cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a50u,2);
goto P_0c0b397e;
P_0c0b397e: /* original 4e0b, guest PC 0x0c0b397e */
if(!s->budget--) { s->failed_pc=0x0c0b397eu; return 0; }
target=r[14];
r[16]=0x0c0b3982u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3982u) { target=s->pc; goto dispatch; }
goto P_0c0b3982;
P_0c0b3980: /* original 0009, guest PC 0x0c0b3980 */
if(!s->budget--) { s->failed_pc=0x0c0b3980u; return 0; }
goto P_0c0b3982;
P_0c0b3982: /* original 9466, guest PC 0x0c0b3982 */
if(!s->budget--) { s->failed_pc=0x0c0b3982u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a52u,2);
goto P_0c0b3984;
P_0c0b3984: /* original 4e0b, guest PC 0x0c0b3984 */
if(!s->budget--) { s->failed_pc=0x0c0b3984u; return 0; }
target=r[14];
r[16]=0x0c0b3988u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3988u) { target=s->pc; goto dispatch; }
goto P_0c0b3988;
P_0c0b3986: /* original 0009, guest PC 0x0c0b3986 */
if(!s->budget--) { s->failed_pc=0x0c0b3986u; return 0; }
goto P_0c0b3988;
P_0c0b3988: /* original 9464, guest PC 0x0c0b3988 */
if(!s->budget--) { s->failed_pc=0x0c0b3988u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a54u,2);
goto P_0c0b398a;
P_0c0b398a: /* original 4e0b, guest PC 0x0c0b398a */
if(!s->budget--) { s->failed_pc=0x0c0b398au; return 0; }
target=r[14];
r[16]=0x0c0b398eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b398eu) { target=s->pc; goto dispatch; }
goto P_0c0b398e;
P_0c0b398c: /* original 0009, guest PC 0x0c0b398c */
if(!s->budget--) { s->failed_pc=0x0c0b398cu; return 0; }
goto P_0c0b398e;
P_0c0b398e: /* original 9462, guest PC 0x0c0b398e */
if(!s->budget--) { s->failed_pc=0x0c0b398eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a56u,2);
goto P_0c0b3990;
P_0c0b3990: /* original 4e0b, guest PC 0x0c0b3990 */
if(!s->budget--) { s->failed_pc=0x0c0b3990u; return 0; }
target=r[14];
r[16]=0x0c0b3994u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3994u) { target=s->pc; goto dispatch; }
goto P_0c0b3994;
P_0c0b3992: /* original 0009, guest PC 0x0c0b3992 */
if(!s->budget--) { s->failed_pc=0x0c0b3992u; return 0; }
goto P_0c0b3994;
P_0c0b3994: /* original 9460, guest PC 0x0c0b3994 */
if(!s->budget--) { s->failed_pc=0x0c0b3994u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a58u,2);
goto P_0c0b3996;
P_0c0b3996: /* original 4e0b, guest PC 0x0c0b3996 */
if(!s->budget--) { s->failed_pc=0x0c0b3996u; return 0; }
target=r[14];
r[16]=0x0c0b399au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b399au) { target=s->pc; goto dispatch; }
goto P_0c0b399a;
P_0c0b3998: /* original 0009, guest PC 0x0c0b3998 */
if(!s->budget--) { s->failed_pc=0x0c0b3998u; return 0; }
goto P_0c0b399a;
P_0c0b399a: /* original 945e, guest PC 0x0c0b399a */
if(!s->budget--) { s->failed_pc=0x0c0b399au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a5au,2);
goto P_0c0b399c;
P_0c0b399c: /* original 4e0b, guest PC 0x0c0b399c */
if(!s->budget--) { s->failed_pc=0x0c0b399cu; return 0; }
target=r[14];
r[16]=0x0c0b39a0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39a0u) { target=s->pc; goto dispatch; }
goto P_0c0b39a0;
P_0c0b399e: /* original 0009, guest PC 0x0c0b399e */
if(!s->budget--) { s->failed_pc=0x0c0b399eu; return 0; }
goto P_0c0b39a0;
P_0c0b39a0: /* original 945c, guest PC 0x0c0b39a0 */
if(!s->budget--) { s->failed_pc=0x0c0b39a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a5cu,2);
goto P_0c0b39a2;
P_0c0b39a2: /* original 4e0b, guest PC 0x0c0b39a2 */
if(!s->budget--) { s->failed_pc=0x0c0b39a2u; return 0; }
target=r[14];
r[16]=0x0c0b39a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39a6u) { target=s->pc; goto dispatch; }
goto P_0c0b39a6;
P_0c0b39a4: /* original 0009, guest PC 0x0c0b39a4 */
if(!s->budget--) { s->failed_pc=0x0c0b39a4u; return 0; }
goto P_0c0b39a6;
P_0c0b39a6: /* original 945a, guest PC 0x0c0b39a6 */
if(!s->budget--) { s->failed_pc=0x0c0b39a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a5eu,2);
goto P_0c0b39a8;
P_0c0b39a8: /* original 4e0b, guest PC 0x0c0b39a8 */
if(!s->budget--) { s->failed_pc=0x0c0b39a8u; return 0; }
target=r[14];
r[16]=0x0c0b39acu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39acu) { target=s->pc; goto dispatch; }
goto P_0c0b39ac;
P_0c0b39aa: /* original 0009, guest PC 0x0c0b39aa */
if(!s->budget--) { s->failed_pc=0x0c0b39aau; return 0; }
goto P_0c0b39ac;
P_0c0b39ac: /* original 9458, guest PC 0x0c0b39ac */
if(!s->budget--) { s->failed_pc=0x0c0b39acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a60u,2);
goto P_0c0b39ae;
P_0c0b39ae: /* original 4e0b, guest PC 0x0c0b39ae */
if(!s->budget--) { s->failed_pc=0x0c0b39aeu; return 0; }
target=r[14];
r[16]=0x0c0b39b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39b2u) { target=s->pc; goto dispatch; }
goto P_0c0b39b2;
P_0c0b39b0: /* original 0009, guest PC 0x0c0b39b0 */
if(!s->budget--) { s->failed_pc=0x0c0b39b0u; return 0; }
goto P_0c0b39b2;
P_0c0b39b2: /* original 9456, guest PC 0x0c0b39b2 */
if(!s->budget--) { s->failed_pc=0x0c0b39b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a62u,2);
goto P_0c0b39b4;
P_0c0b39b4: /* original 4e0b, guest PC 0x0c0b39b4 */
if(!s->budget--) { s->failed_pc=0x0c0b39b4u; return 0; }
target=r[14];
r[16]=0x0c0b39b8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39b8u) { target=s->pc; goto dispatch; }
goto P_0c0b39b8;
P_0c0b39b6: /* original 0009, guest PC 0x0c0b39b6 */
if(!s->budget--) { s->failed_pc=0x0c0b39b6u; return 0; }
goto P_0c0b39b8;
P_0c0b39b8: /* original 9454, guest PC 0x0c0b39b8 */
if(!s->budget--) { s->failed_pc=0x0c0b39b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a64u,2);
goto P_0c0b39ba;
P_0c0b39ba: /* original 4e0b, guest PC 0x0c0b39ba */
if(!s->budget--) { s->failed_pc=0x0c0b39bau; return 0; }
target=r[14];
r[16]=0x0c0b39beu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39beu) { target=s->pc; goto dispatch; }
goto P_0c0b39be;
P_0c0b39bc: /* original 0009, guest PC 0x0c0b39bc */
if(!s->budget--) { s->failed_pc=0x0c0b39bcu; return 0; }
goto P_0c0b39be;
P_0c0b39be: /* original 9452, guest PC 0x0c0b39be */
if(!s->budget--) { s->failed_pc=0x0c0b39beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a66u,2);
goto P_0c0b39c0;
P_0c0b39c0: /* original 4e0b, guest PC 0x0c0b39c0 */
if(!s->budget--) { s->failed_pc=0x0c0b39c0u; return 0; }
target=r[14];
r[16]=0x0c0b39c4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39c4u) { target=s->pc; goto dispatch; }
goto P_0c0b39c4;
P_0c0b39c2: /* original 0009, guest PC 0x0c0b39c2 */
if(!s->budget--) { s->failed_pc=0x0c0b39c2u; return 0; }
goto P_0c0b39c4;
P_0c0b39c4: /* original 9450, guest PC 0x0c0b39c4 */
if(!s->budget--) { s->failed_pc=0x0c0b39c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a68u,2);
goto P_0c0b39c6;
P_0c0b39c6: /* original 4e0b, guest PC 0x0c0b39c6 */
if(!s->budget--) { s->failed_pc=0x0c0b39c6u; return 0; }
target=r[14];
r[16]=0x0c0b39cau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39cau) { target=s->pc; goto dispatch; }
goto P_0c0b39ca;
P_0c0b39c8: /* original 0009, guest PC 0x0c0b39c8 */
if(!s->budget--) { s->failed_pc=0x0c0b39c8u; return 0; }
goto P_0c0b39ca;
P_0c0b39ca: /* original 944e, guest PC 0x0c0b39ca */
if(!s->budget--) { s->failed_pc=0x0c0b39cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a6au,2);
goto P_0c0b39cc;
P_0c0b39cc: /* original 4e0b, guest PC 0x0c0b39cc */
if(!s->budget--) { s->failed_pc=0x0c0b39ccu; return 0; }
target=r[14];
r[16]=0x0c0b39d0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39d0u) { target=s->pc; goto dispatch; }
goto P_0c0b39d0;
P_0c0b39ce: /* original 0009, guest PC 0x0c0b39ce */
if(!s->budget--) { s->failed_pc=0x0c0b39ceu; return 0; }
goto P_0c0b39d0;
P_0c0b39d0: /* original 944c, guest PC 0x0c0b39d0 */
if(!s->budget--) { s->failed_pc=0x0c0b39d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a6cu,2);
goto P_0c0b39d2;
P_0c0b39d2: /* original 4e0b, guest PC 0x0c0b39d2 */
if(!s->budget--) { s->failed_pc=0x0c0b39d2u; return 0; }
target=r[14];
r[16]=0x0c0b39d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39d6u) { target=s->pc; goto dispatch; }
goto P_0c0b39d6;
P_0c0b39d4: /* original 0009, guest PC 0x0c0b39d4 */
if(!s->budget--) { s->failed_pc=0x0c0b39d4u; return 0; }
goto P_0c0b39d6;
P_0c0b39d6: /* original 944a, guest PC 0x0c0b39d6 */
if(!s->budget--) { s->failed_pc=0x0c0b39d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a6eu,2);
goto P_0c0b39d8;
P_0c0b39d8: /* original 4e0b, guest PC 0x0c0b39d8 */
if(!s->budget--) { s->failed_pc=0x0c0b39d8u; return 0; }
target=r[14];
r[16]=0x0c0b39dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39dcu) { target=s->pc; goto dispatch; }
goto P_0c0b39dc;
P_0c0b39da: /* original 0009, guest PC 0x0c0b39da */
if(!s->budget--) { s->failed_pc=0x0c0b39dau; return 0; }
goto P_0c0b39dc;
P_0c0b39dc: /* original 9448, guest PC 0x0c0b39dc */
if(!s->budget--) { s->failed_pc=0x0c0b39dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a70u,2);
goto P_0c0b39de;
P_0c0b39de: /* original 4e0b, guest PC 0x0c0b39de */
if(!s->budget--) { s->failed_pc=0x0c0b39deu; return 0; }
target=r[14];
r[16]=0x0c0b39e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39e2u) { target=s->pc; goto dispatch; }
goto P_0c0b39e2;
P_0c0b39e0: /* original 0009, guest PC 0x0c0b39e0 */
if(!s->budget--) { s->failed_pc=0x0c0b39e0u; return 0; }
goto P_0c0b39e2;
P_0c0b39e2: /* original 9446, guest PC 0x0c0b39e2 */
if(!s->budget--) { s->failed_pc=0x0c0b39e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a72u,2);
goto P_0c0b39e4;
P_0c0b39e4: /* original 4e0b, guest PC 0x0c0b39e4 */
if(!s->budget--) { s->failed_pc=0x0c0b39e4u; return 0; }
target=r[14];
r[16]=0x0c0b39e8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39e8u) { target=s->pc; goto dispatch; }
goto P_0c0b39e8;
P_0c0b39e6: /* original 0009, guest PC 0x0c0b39e6 */
if(!s->budget--) { s->failed_pc=0x0c0b39e6u; return 0; }
goto P_0c0b39e8;
P_0c0b39e8: /* original 9444, guest PC 0x0c0b39e8 */
if(!s->budget--) { s->failed_pc=0x0c0b39e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a74u,2);
goto P_0c0b39ea;
P_0c0b39ea: /* original 4e0b, guest PC 0x0c0b39ea */
if(!s->budget--) { s->failed_pc=0x0c0b39eau; return 0; }
target=r[14];
r[16]=0x0c0b39eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39eeu) { target=s->pc; goto dispatch; }
goto P_0c0b39ee;
P_0c0b39ec: /* original 0009, guest PC 0x0c0b39ec */
if(!s->budget--) { s->failed_pc=0x0c0b39ecu; return 0; }
goto P_0c0b39ee;
P_0c0b39ee: /* original 9442, guest PC 0x0c0b39ee */
if(!s->budget--) { s->failed_pc=0x0c0b39eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a76u,2);
goto P_0c0b39f0;
P_0c0b39f0: /* original 4e0b, guest PC 0x0c0b39f0 */
if(!s->budget--) { s->failed_pc=0x0c0b39f0u; return 0; }
target=r[14];
r[16]=0x0c0b39f4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39f4u) { target=s->pc; goto dispatch; }
goto P_0c0b39f4;
P_0c0b39f2: /* original 0009, guest PC 0x0c0b39f2 */
if(!s->budget--) { s->failed_pc=0x0c0b39f2u; return 0; }
goto P_0c0b39f4;
P_0c0b39f4: /* original 9440, guest PC 0x0c0b39f4 */
if(!s->budget--) { s->failed_pc=0x0c0b39f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a78u,2);
goto P_0c0b39f6;
P_0c0b39f6: /* original 4e0b, guest PC 0x0c0b39f6 */
if(!s->budget--) { s->failed_pc=0x0c0b39f6u; return 0; }
target=r[14];
r[16]=0x0c0b39fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b39fau) { target=s->pc; goto dispatch; }
goto P_0c0b39fa;
P_0c0b39f8: /* original 0009, guest PC 0x0c0b39f8 */
if(!s->budget--) { s->failed_pc=0x0c0b39f8u; return 0; }
goto P_0c0b39fa;
P_0c0b39fa: /* original 943e, guest PC 0x0c0b39fa */
if(!s->budget--) { s->failed_pc=0x0c0b39fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a7au,2);
goto P_0c0b39fc;
P_0c0b39fc: /* original 4e0b, guest PC 0x0c0b39fc */
if(!s->budget--) { s->failed_pc=0x0c0b39fcu; return 0; }
target=r[14];
r[16]=0x0c0b3a00u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3a00u) { target=s->pc; goto dispatch; }
goto P_0c0b3a00;
P_0c0b39fe: /* original 0009, guest PC 0x0c0b39fe */
if(!s->budget--) { s->failed_pc=0x0c0b39feu; return 0; }
goto P_0c0b3a00;
P_0c0b3a00: /* original 943c, guest PC 0x0c0b3a00 */
if(!s->budget--) { s->failed_pc=0x0c0b3a00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a7cu,2);
goto P_0c0b3a02;
P_0c0b3a02: /* original 4e0b, guest PC 0x0c0b3a02 */
if(!s->budget--) { s->failed_pc=0x0c0b3a02u; return 0; }
target=r[14];
r[16]=0x0c0b3a06u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3a06u) { target=s->pc; goto dispatch; }
goto P_0c0b3a06;
P_0c0b3a04: /* original 0009, guest PC 0x0c0b3a04 */
if(!s->budget--) { s->failed_pc=0x0c0b3a04u; return 0; }
goto P_0c0b3a06;
P_0c0b3a06: /* original 943a, guest PC 0x0c0b3a06 */
if(!s->budget--) { s->failed_pc=0x0c0b3a06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a7eu,2);
goto P_0c0b3a08;
P_0c0b3a08: /* original 4e0b, guest PC 0x0c0b3a08 */
if(!s->budget--) { s->failed_pc=0x0c0b3a08u; return 0; }
target=r[14];
r[16]=0x0c0b3a0cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3a0cu) { target=s->pc; goto dispatch; }
goto P_0c0b3a0c;
P_0c0b3a0a: /* original 0009, guest PC 0x0c0b3a0a */
if(!s->budget--) { s->failed_pc=0x0c0b3a0au; return 0; }
goto P_0c0b3a0c;
P_0c0b3a0c: /* original 9438, guest PC 0x0c0b3a0c */
if(!s->budget--) { s->failed_pc=0x0c0b3a0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3a80u,2);
goto P_0c0b3a0e;
P_0c0b3a0e: /* original 4e0b, guest PC 0x0c0b3a0e */
if(!s->budget--) { s->failed_pc=0x0c0b3a0eu; return 0; }
target=r[14];
r[16]=0x0c0b3a12u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b3a12u) { target=s->pc; goto dispatch; }
goto P_0c0b3a12;
P_0c0b3a10: /* original 0009, guest PC 0x0c0b3a10 */
if(!s->budget--) { s->failed_pc=0x0c0b3a10u; return 0; }
goto P_0c0b3a12;
P_0c0b3a12: /* original 4f26, guest PC 0x0c0b3a12 */
if(!s->budget--) { s->failed_pc=0x0c0b3a12u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b3a14;
P_0c0b3a14: /* original 000b, guest PC 0x0c0b3a14 */
if(!s->budget--) { s->failed_pc=0x0c0b3a14u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b3a16: /* original 6ef6, guest PC 0x0c0b3a16 */
if(!s->budget--) { s->failed_pc=0x0c0b3a16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0b3a18u,s,ram);
P_0c0b588e: /* original 4f22, guest PC 0x0c0b588e */
if(!s->budget--) { s->failed_pc=0x0c0b588eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b5890;
P_0c0b5890: /* original 5d44, guest PC 0x0c0b5890 */
if(!s->budget--) { s->failed_pc=0x0c0b5890u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b5892;
P_0c0b5892: /* original 94a8, guest PC 0x0c0b5892 */
if(!s->budget--) { s->failed_pc=0x0c0b5892u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59e6u,2);
goto P_0c0b5894;
P_0c0b5894: /* original de6e, guest PC 0x0c0b5894 */
if(!s->budget--) { s->failed_pc=0x0c0b5894u; return 0; }
r[14]=read(ram,0x0c0b5a50u,4);
goto P_0c0b5896;
P_0c0b5896: /* original 7ff8, guest PC 0x0c0b5896 */
if(!s->budget--) { s->failed_pc=0x0c0b5896u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b5898;
P_0c0b5898: /* original 4e0b, guest PC 0x0c0b5898 */
if(!s->budget--) { s->failed_pc=0x0c0b5898u; return 0; }
target=r[14];
r[16]=0x0c0b589cu;
tmp=read(ram,r[13],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b589cu) { target=s->pc; goto dispatch; }
goto P_0c0b589c;
P_0c0b589a: /* original 65d2, guest PC 0x0c0b589a */
if(!s->budget--) { s->failed_pc=0x0c0b589au; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b589c;
P_0c0b589c: /* original 94a4, guest PC 0x0c0b589c */
if(!s->budget--) { s->failed_pc=0x0c0b589cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59e8u,2);
goto P_0c0b589e;
P_0c0b589e: /* original 4e0b, guest PC 0x0c0b589e */
if(!s->budget--) { s->failed_pc=0x0c0b589eu; return 0; }
target=r[14];
r[16]=0x0c0b58a2u;
r[5]=read(ram,r[13]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58a2u) { target=s->pc; goto dispatch; }
goto P_0c0b58a2;
P_0c0b58a0: /* original 55d1, guest PC 0x0c0b58a0 */
if(!s->budget--) { s->failed_pc=0x0c0b58a0u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b58a2;
P_0c0b58a2: /* original 94a2, guest PC 0x0c0b58a2 */
if(!s->budget--) { s->failed_pc=0x0c0b58a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59eau,2);
goto P_0c0b58a4;
P_0c0b58a4: /* original 4e0b, guest PC 0x0c0b58a4 */
if(!s->budget--) { s->failed_pc=0x0c0b58a4u; return 0; }
target=r[14];
r[16]=0x0c0b58a8u;
r[5]=read(ram,r[13]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58a8u) { target=s->pc; goto dispatch; }
goto P_0c0b58a8;
P_0c0b58a6: /* original 55d2, guest PC 0x0c0b58a6 */
if(!s->budget--) { s->failed_pc=0x0c0b58a6u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b58a8;
P_0c0b58a8: /* original 94a0, guest PC 0x0c0b58a8 */
if(!s->budget--) { s->failed_pc=0x0c0b58a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59ecu,2);
goto P_0c0b58aa;
P_0c0b58aa: /* original 4e0b, guest PC 0x0c0b58aa */
if(!s->budget--) { s->failed_pc=0x0c0b58aau; return 0; }
target=r[14];
r[16]=0x0c0b58aeu;
r[5]=read(ram,r[13]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58aeu) { target=s->pc; goto dispatch; }
goto P_0c0b58ae;
P_0c0b58ac: /* original 55d3, guest PC 0x0c0b58ac */
if(!s->budget--) { s->failed_pc=0x0c0b58acu; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b58ae;
P_0c0b58ae: /* original 949e, guest PC 0x0c0b58ae */
if(!s->budget--) { s->failed_pc=0x0c0b58aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59eeu,2);
goto P_0c0b58b0;
P_0c0b58b0: /* original 4e0b, guest PC 0x0c0b58b0 */
if(!s->budget--) { s->failed_pc=0x0c0b58b0u; return 0; }
target=r[14];
r[16]=0x0c0b58b4u;
r[5]=read(ram,r[13]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58b4u) { target=s->pc; goto dispatch; }
goto P_0c0b58b4;
P_0c0b58b2: /* original 55d4, guest PC 0x0c0b58b2 */
if(!s->budget--) { s->failed_pc=0x0c0b58b2u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b58b4;
P_0c0b58b4: /* original 949c, guest PC 0x0c0b58b4 */
if(!s->budget--) { s->failed_pc=0x0c0b58b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f0u,2);
goto P_0c0b58b6;
P_0c0b58b6: /* original 4e0b, guest PC 0x0c0b58b6 */
if(!s->budget--) { s->failed_pc=0x0c0b58b6u; return 0; }
target=r[14];
r[16]=0x0c0b58bau;
r[5]=read(ram,r[13]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58bau) { target=s->pc; goto dispatch; }
goto P_0c0b58ba;
P_0c0b58b8: /* original 55d5, guest PC 0x0c0b58b8 */
if(!s->budget--) { s->failed_pc=0x0c0b58b8u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b58ba;
P_0c0b58ba: /* original 949a, guest PC 0x0c0b58ba */
if(!s->budget--) { s->failed_pc=0x0c0b58bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f2u,2);
goto P_0c0b58bc;
P_0c0b58bc: /* original 4e0b, guest PC 0x0c0b58bc */
if(!s->budget--) { s->failed_pc=0x0c0b58bcu; return 0; }
target=r[14];
r[16]=0x0c0b58c0u;
r[5]=read(ram,r[13]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58c0u) { target=s->pc; goto dispatch; }
goto P_0c0b58c0;
P_0c0b58be: /* original 55d6, guest PC 0x0c0b58be */
if(!s->budget--) { s->failed_pc=0x0c0b58beu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b58c0;
P_0c0b58c0: /* original 9498, guest PC 0x0c0b58c0 */
if(!s->budget--) { s->failed_pc=0x0c0b58c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f4u,2);
goto P_0c0b58c2;
P_0c0b58c2: /* original 4e0b, guest PC 0x0c0b58c2 */
if(!s->budget--) { s->failed_pc=0x0c0b58c2u; return 0; }
target=r[14];
r[16]=0x0c0b58c6u;
r[5]=read(ram,r[13]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58c6u) { target=s->pc; goto dispatch; }
goto P_0c0b58c6;
P_0c0b58c4: /* original 55d7, guest PC 0x0c0b58c4 */
if(!s->budget--) { s->failed_pc=0x0c0b58c4u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b58c6;
P_0c0b58c6: /* original 9496, guest PC 0x0c0b58c6 */
if(!s->budget--) { s->failed_pc=0x0c0b58c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f6u,2);
goto P_0c0b58c8;
P_0c0b58c8: /* original 4e0b, guest PC 0x0c0b58c8 */
if(!s->budget--) { s->failed_pc=0x0c0b58c8u; return 0; }
target=r[14];
r[16]=0x0c0b58ccu;
r[5]=read(ram,r[13]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58ccu) { target=s->pc; goto dispatch; }
goto P_0c0b58cc;
P_0c0b58ca: /* original 55d8, guest PC 0x0c0b58ca */
if(!s->budget--) { s->failed_pc=0x0c0b58cau; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b58cc;
P_0c0b58cc: /* original 9494, guest PC 0x0c0b58cc */
if(!s->budget--) { s->failed_pc=0x0c0b58ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59f8u,2);
goto P_0c0b58ce;
P_0c0b58ce: /* original 4e0b, guest PC 0x0c0b58ce */
if(!s->budget--) { s->failed_pc=0x0c0b58ceu; return 0; }
target=r[14];
r[16]=0x0c0b58d2u;
r[5]=read(ram,r[13]+36,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58d2u) { target=s->pc; goto dispatch; }
goto P_0c0b58d2;
P_0c0b58d0: /* original 55d9, guest PC 0x0c0b58d0 */
if(!s->budget--) { s->failed_pc=0x0c0b58d0u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b58d2;
P_0c0b58d2: /* original 9492, guest PC 0x0c0b58d2 */
if(!s->budget--) { s->failed_pc=0x0c0b58d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59fau,2);
goto P_0c0b58d4;
P_0c0b58d4: /* original 4e0b, guest PC 0x0c0b58d4 */
if(!s->budget--) { s->failed_pc=0x0c0b58d4u; return 0; }
target=r[14];
r[16]=0x0c0b58d8u;
r[5]=read(ram,r[13]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58d8u) { target=s->pc; goto dispatch; }
goto P_0c0b58d8;
P_0c0b58d6: /* original 55da, guest PC 0x0c0b58d6 */
if(!s->budget--) { s->failed_pc=0x0c0b58d6u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b58d8;
P_0c0b58d8: /* original 9490, guest PC 0x0c0b58d8 */
if(!s->budget--) { s->failed_pc=0x0c0b58d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59fcu,2);
goto P_0c0b58da;
P_0c0b58da: /* original 4e0b, guest PC 0x0c0b58da */
if(!s->budget--) { s->failed_pc=0x0c0b58dau; return 0; }
target=r[14];
r[16]=0x0c0b58deu;
r[5]=read(ram,r[13]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58deu) { target=s->pc; goto dispatch; }
goto P_0c0b58de;
P_0c0b58dc: /* original 55db, guest PC 0x0c0b58dc */
if(!s->budget--) { s->failed_pc=0x0c0b58dcu; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b58de;
P_0c0b58de: /* original 948e, guest PC 0x0c0b58de */
if(!s->budget--) { s->failed_pc=0x0c0b58deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b59feu,2);
goto P_0c0b58e0;
P_0c0b58e0: /* original 4e0b, guest PC 0x0c0b58e0 */
if(!s->budget--) { s->failed_pc=0x0c0b58e0u; return 0; }
target=r[14];
r[16]=0x0c0b58e4u;
r[5]=read(ram,r[13]+48,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58e4u) { target=s->pc; goto dispatch; }
goto P_0c0b58e4;
P_0c0b58e2: /* original 55dc, guest PC 0x0c0b58e2 */
if(!s->budget--) { s->failed_pc=0x0c0b58e2u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b58e4;
P_0c0b58e4: /* original 948c, guest PC 0x0c0b58e4 */
if(!s->budget--) { s->failed_pc=0x0c0b58e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a00u,2);
goto P_0c0b58e6;
P_0c0b58e6: /* original 4e0b, guest PC 0x0c0b58e6 */
if(!s->budget--) { s->failed_pc=0x0c0b58e6u; return 0; }
target=r[14];
r[16]=0x0c0b58eau;
r[5]=read(ram,r[13]+52,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58eau) { target=s->pc; goto dispatch; }
goto P_0c0b58ea;
P_0c0b58e8: /* original 55dd, guest PC 0x0c0b58e8 */
if(!s->budget--) { s->failed_pc=0x0c0b58e8u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b58ea;
P_0c0b58ea: /* original 948a, guest PC 0x0c0b58ea */
if(!s->budget--) { s->failed_pc=0x0c0b58eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a02u,2);
goto P_0c0b58ec;
P_0c0b58ec: /* original 4e0b, guest PC 0x0c0b58ec */
if(!s->budget--) { s->failed_pc=0x0c0b58ecu; return 0; }
target=r[14];
r[16]=0x0c0b58f0u;
r[5]=read(ram,r[13]+56,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58f0u) { target=s->pc; goto dispatch; }
goto P_0c0b58f0;
P_0c0b58ee: /* original 55de, guest PC 0x0c0b58ee */
if(!s->budget--) { s->failed_pc=0x0c0b58eeu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b58f0;
P_0c0b58f0: /* original 9488, guest PC 0x0c0b58f0 */
if(!s->budget--) { s->failed_pc=0x0c0b58f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a04u,2);
goto P_0c0b58f2;
P_0c0b58f2: /* original 4e0b, guest PC 0x0c0b58f2 */
if(!s->budget--) { s->failed_pc=0x0c0b58f2u; return 0; }
target=r[14];
r[16]=0x0c0b58f6u;
r[5]=read(ram,r[13]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58f6u) { target=s->pc; goto dispatch; }
goto P_0c0b58f6;
P_0c0b58f4: /* original 55df, guest PC 0x0c0b58f4 */
if(!s->budget--) { s->failed_pc=0x0c0b58f4u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b58f6;
P_0c0b58f6: /* original 9486, guest PC 0x0c0b58f6 */
if(!s->budget--) { s->failed_pc=0x0c0b58f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a06u,2);
goto P_0c0b58f8;
P_0c0b58f8: /* original e040, guest PC 0x0c0b58f8 */
if(!s->budget--) { s->failed_pc=0x0c0b58f8u; return 0; }
r[0]=0x00000040u;
goto P_0c0b58fa;
P_0c0b58fa: /* original 4e0b, guest PC 0x0c0b58fa */
if(!s->budget--) { s->failed_pc=0x0c0b58fau; return 0; }
target=r[14];
r[16]=0x0c0b58feu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b58feu) { target=s->pc; goto dispatch; }
goto P_0c0b58fe;
P_0c0b58fc: /* original 05de, guest PC 0x0c0b58fc */
if(!s->budget--) { s->failed_pc=0x0c0b58fcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b58fe;
P_0c0b58fe: /* original 9483, guest PC 0x0c0b58fe */
if(!s->budget--) { s->failed_pc=0x0c0b58feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a08u,2);
goto P_0c0b5900;
P_0c0b5900: /* original e044, guest PC 0x0c0b5900 */
if(!s->budget--) { s->failed_pc=0x0c0b5900u; return 0; }
r[0]=0x00000044u;
goto P_0c0b5902;
P_0c0b5902: /* original 4e0b, guest PC 0x0c0b5902 */
if(!s->budget--) { s->failed_pc=0x0c0b5902u; return 0; }
target=r[14];
r[16]=0x0c0b5906u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5906u) { target=s->pc; goto dispatch; }
goto P_0c0b5906;
P_0c0b5904: /* original 05de, guest PC 0x0c0b5904 */
if(!s->budget--) { s->failed_pc=0x0c0b5904u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5906;
P_0c0b5906: /* original 9480, guest PC 0x0c0b5906 */
if(!s->budget--) { s->failed_pc=0x0c0b5906u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a0au,2);
goto P_0c0b5908;
P_0c0b5908: /* original e048, guest PC 0x0c0b5908 */
if(!s->budget--) { s->failed_pc=0x0c0b5908u; return 0; }
r[0]=0x00000048u;
goto P_0c0b590a;
P_0c0b590a: /* original 4e0b, guest PC 0x0c0b590a */
if(!s->budget--) { s->failed_pc=0x0c0b590au; return 0; }
target=r[14];
r[16]=0x0c0b590eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b590eu) { target=s->pc; goto dispatch; }
goto P_0c0b590e;
P_0c0b590c: /* original 05de, guest PC 0x0c0b590c */
if(!s->budget--) { s->failed_pc=0x0c0b590cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b590e;
P_0c0b590e: /* original 947d, guest PC 0x0c0b590e */
if(!s->budget--) { s->failed_pc=0x0c0b590eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a0cu,2);
goto P_0c0b5910;
P_0c0b5910: /* original e04c, guest PC 0x0c0b5910 */
if(!s->budget--) { s->failed_pc=0x0c0b5910u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b5912;
P_0c0b5912: /* original 4e0b, guest PC 0x0c0b5912 */
if(!s->budget--) { s->failed_pc=0x0c0b5912u; return 0; }
target=r[14];
r[16]=0x0c0b5916u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5916u) { target=s->pc; goto dispatch; }
goto P_0c0b5916;
P_0c0b5914: /* original 05de, guest PC 0x0c0b5914 */
if(!s->budget--) { s->failed_pc=0x0c0b5914u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5916;
P_0c0b5916: /* original 947a, guest PC 0x0c0b5916 */
if(!s->budget--) { s->failed_pc=0x0c0b5916u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a0eu,2);
goto P_0c0b5918;
P_0c0b5918: /* original e050, guest PC 0x0c0b5918 */
if(!s->budget--) { s->failed_pc=0x0c0b5918u; return 0; }
r[0]=0x00000050u;
goto P_0c0b591a;
P_0c0b591a: /* original 4e0b, guest PC 0x0c0b591a */
if(!s->budget--) { s->failed_pc=0x0c0b591au; return 0; }
target=r[14];
r[16]=0x0c0b591eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b591eu) { target=s->pc; goto dispatch; }
goto P_0c0b591e;
P_0c0b591c: /* original 05de, guest PC 0x0c0b591c */
if(!s->budget--) { s->failed_pc=0x0c0b591cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b591e;
P_0c0b591e: /* original 9477, guest PC 0x0c0b591e */
if(!s->budget--) { s->failed_pc=0x0c0b591eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a10u,2);
goto P_0c0b5920;
P_0c0b5920: /* original e054, guest PC 0x0c0b5920 */
if(!s->budget--) { s->failed_pc=0x0c0b5920u; return 0; }
r[0]=0x00000054u;
goto P_0c0b5922;
P_0c0b5922: /* original 4e0b, guest PC 0x0c0b5922 */
if(!s->budget--) { s->failed_pc=0x0c0b5922u; return 0; }
target=r[14];
r[16]=0x0c0b5926u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5926u) { target=s->pc; goto dispatch; }
goto P_0c0b5926;
P_0c0b5924: /* original 05de, guest PC 0x0c0b5924 */
if(!s->budget--) { s->failed_pc=0x0c0b5924u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5926;
P_0c0b5926: /* original 9474, guest PC 0x0c0b5926 */
if(!s->budget--) { s->failed_pc=0x0c0b5926u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a12u,2);
goto P_0c0b5928;
P_0c0b5928: /* original e058, guest PC 0x0c0b5928 */
if(!s->budget--) { s->failed_pc=0x0c0b5928u; return 0; }
r[0]=0x00000058u;
goto P_0c0b592a;
P_0c0b592a: /* original 4e0b, guest PC 0x0c0b592a */
if(!s->budget--) { s->failed_pc=0x0c0b592au; return 0; }
target=r[14];
r[16]=0x0c0b592eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b592eu) { target=s->pc; goto dispatch; }
goto P_0c0b592e;
P_0c0b592c: /* original 05de, guest PC 0x0c0b592c */
if(!s->budget--) { s->failed_pc=0x0c0b592cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b592e;
P_0c0b592e: /* original 9471, guest PC 0x0c0b592e */
if(!s->budget--) { s->failed_pc=0x0c0b592eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a14u,2);
goto P_0c0b5930;
P_0c0b5930: /* original e05c, guest PC 0x0c0b5930 */
if(!s->budget--) { s->failed_pc=0x0c0b5930u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b5932;
P_0c0b5932: /* original 4e0b, guest PC 0x0c0b5932 */
if(!s->budget--) { s->failed_pc=0x0c0b5932u; return 0; }
target=r[14];
r[16]=0x0c0b5936u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5936u) { target=s->pc; goto dispatch; }
goto P_0c0b5936;
P_0c0b5934: /* original 05de, guest PC 0x0c0b5934 */
if(!s->budget--) { s->failed_pc=0x0c0b5934u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5936;
P_0c0b5936: /* original 946e, guest PC 0x0c0b5936 */
if(!s->budget--) { s->failed_pc=0x0c0b5936u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a16u,2);
goto P_0c0b5938;
P_0c0b5938: /* original e060, guest PC 0x0c0b5938 */
if(!s->budget--) { s->failed_pc=0x0c0b5938u; return 0; }
r[0]=0x00000060u;
goto P_0c0b593a;
P_0c0b593a: /* original 4e0b, guest PC 0x0c0b593a */
if(!s->budget--) { s->failed_pc=0x0c0b593au; return 0; }
target=r[14];
r[16]=0x0c0b593eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b593eu) { target=s->pc; goto dispatch; }
goto P_0c0b593e;
P_0c0b593c: /* original 05de, guest PC 0x0c0b593c */
if(!s->budget--) { s->failed_pc=0x0c0b593cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b593e;
P_0c0b593e: /* original 946b, guest PC 0x0c0b593e */
if(!s->budget--) { s->failed_pc=0x0c0b593eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a18u,2);
goto P_0c0b5940;
P_0c0b5940: /* original e064, guest PC 0x0c0b5940 */
if(!s->budget--) { s->failed_pc=0x0c0b5940u; return 0; }
r[0]=0x00000064u;
goto P_0c0b5942;
P_0c0b5942: /* original 4e0b, guest PC 0x0c0b5942 */
if(!s->budget--) { s->failed_pc=0x0c0b5942u; return 0; }
target=r[14];
r[16]=0x0c0b5946u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5946u) { target=s->pc; goto dispatch; }
goto P_0c0b5946;
P_0c0b5944: /* original 05de, guest PC 0x0c0b5944 */
if(!s->budget--) { s->failed_pc=0x0c0b5944u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5946;
P_0c0b5946: /* original 9468, guest PC 0x0c0b5946 */
if(!s->budget--) { s->failed_pc=0x0c0b5946u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a1au,2);
goto P_0c0b5948;
P_0c0b5948: /* original e068, guest PC 0x0c0b5948 */
if(!s->budget--) { s->failed_pc=0x0c0b5948u; return 0; }
r[0]=0x00000068u;
goto P_0c0b594a;
P_0c0b594a: /* original 4e0b, guest PC 0x0c0b594a */
if(!s->budget--) { s->failed_pc=0x0c0b594au; return 0; }
target=r[14];
r[16]=0x0c0b594eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b594eu) { target=s->pc; goto dispatch; }
goto P_0c0b594e;
P_0c0b594c: /* original 05de, guest PC 0x0c0b594c */
if(!s->budget--) { s->failed_pc=0x0c0b594cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b594e;
P_0c0b594e: /* original 9465, guest PC 0x0c0b594e */
if(!s->budget--) { s->failed_pc=0x0c0b594eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a1cu,2);
goto P_0c0b5950;
P_0c0b5950: /* original e06c, guest PC 0x0c0b5950 */
if(!s->budget--) { s->failed_pc=0x0c0b5950u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b5952;
P_0c0b5952: /* original 4e0b, guest PC 0x0c0b5952 */
if(!s->budget--) { s->failed_pc=0x0c0b5952u; return 0; }
target=r[14];
r[16]=0x0c0b5956u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5956u) { target=s->pc; goto dispatch; }
goto P_0c0b5956;
P_0c0b5954: /* original 05de, guest PC 0x0c0b5954 */
if(!s->budget--) { s->failed_pc=0x0c0b5954u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5956;
P_0c0b5956: /* original 9462, guest PC 0x0c0b5956 */
if(!s->budget--) { s->failed_pc=0x0c0b5956u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a1eu,2);
goto P_0c0b5958;
P_0c0b5958: /* original e070, guest PC 0x0c0b5958 */
if(!s->budget--) { s->failed_pc=0x0c0b5958u; return 0; }
r[0]=0x00000070u;
goto P_0c0b595a;
P_0c0b595a: /* original 4e0b, guest PC 0x0c0b595a */
if(!s->budget--) { s->failed_pc=0x0c0b595au; return 0; }
target=r[14];
r[16]=0x0c0b595eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b595eu) { target=s->pc; goto dispatch; }
goto P_0c0b595e;
P_0c0b595c: /* original 05de, guest PC 0x0c0b595c */
if(!s->budget--) { s->failed_pc=0x0c0b595cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b595e;
P_0c0b595e: /* original 945f, guest PC 0x0c0b595e */
if(!s->budget--) { s->failed_pc=0x0c0b595eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a20u,2);
goto P_0c0b5960;
P_0c0b5960: /* original e074, guest PC 0x0c0b5960 */
if(!s->budget--) { s->failed_pc=0x0c0b5960u; return 0; }
r[0]=0x00000074u;
goto P_0c0b5962;
P_0c0b5962: /* original 4e0b, guest PC 0x0c0b5962 */
if(!s->budget--) { s->failed_pc=0x0c0b5962u; return 0; }
target=r[14];
r[16]=0x0c0b5966u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5966u) { target=s->pc; goto dispatch; }
goto P_0c0b5966;
P_0c0b5964: /* original 05de, guest PC 0x0c0b5964 */
if(!s->budget--) { s->failed_pc=0x0c0b5964u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5966;
P_0c0b5966: /* original 945c, guest PC 0x0c0b5966 */
if(!s->budget--) { s->failed_pc=0x0c0b5966u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a22u,2);
goto P_0c0b5968;
P_0c0b5968: /* original e078, guest PC 0x0c0b5968 */
if(!s->budget--) { s->failed_pc=0x0c0b5968u; return 0; }
r[0]=0x00000078u;
goto P_0c0b596a;
P_0c0b596a: /* original 4e0b, guest PC 0x0c0b596a */
if(!s->budget--) { s->failed_pc=0x0c0b596au; return 0; }
target=r[14];
r[16]=0x0c0b596eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b596eu) { target=s->pc; goto dispatch; }
goto P_0c0b596e;
P_0c0b596c: /* original 05de, guest PC 0x0c0b596c */
if(!s->budget--) { s->failed_pc=0x0c0b596cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b596e;
P_0c0b596e: /* original 9459, guest PC 0x0c0b596e */
if(!s->budget--) { s->failed_pc=0x0c0b596eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a24u,2);
goto P_0c0b5970;
P_0c0b5970: /* original e07c, guest PC 0x0c0b5970 */
if(!s->budget--) { s->failed_pc=0x0c0b5970u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b5972;
P_0c0b5972: /* original 4e0b, guest PC 0x0c0b5972 */
if(!s->budget--) { s->failed_pc=0x0c0b5972u; return 0; }
target=r[14];
r[16]=0x0c0b5976u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5976u) { target=s->pc; goto dispatch; }
goto P_0c0b5976;
P_0c0b5974: /* original 05de, guest PC 0x0c0b5974 */
if(!s->budget--) { s->failed_pc=0x0c0b5974u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5976;
P_0c0b5976: /* original 9457, guest PC 0x0c0b5976 */
if(!s->budget--) { s->failed_pc=0x0c0b5976u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a28u,2);
goto P_0c0b5978;
P_0c0b5978: /* original 9055, guest PC 0x0c0b5978 */
if(!s->budget--) { s->failed_pc=0x0c0b5978u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a26u,2);
goto P_0c0b597a;
P_0c0b597a: /* original 4e0b, guest PC 0x0c0b597a */
if(!s->budget--) { s->failed_pc=0x0c0b597au; return 0; }
target=r[14];
r[16]=0x0c0b597eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b597eu) { target=s->pc; goto dispatch; }
goto P_0c0b597e;
P_0c0b597c: /* original 05de, guest PC 0x0c0b597c */
if(!s->budget--) { s->failed_pc=0x0c0b597cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b597e;
P_0c0b597e: /* original 9554, guest PC 0x0c0b597e */
if(!s->budget--) { s->failed_pc=0x0c0b597eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a2au,2);
goto P_0c0b5980;
P_0c0b5980: /* original 35dc, guest PC 0x0c0b5980 */
if(!s->budget--) { s->failed_pc=0x0c0b5980u; return 0; }
r[5]+=r[13];
goto P_0c0b5982;
P_0c0b5982: /* original 2f52, guest PC 0x0c0b5982 */
if(!s->budget--) { s->failed_pc=0x0c0b5982u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5984;
P_0c0b5984: /* original 9452, guest PC 0x0c0b5984 */
if(!s->budget--) { s->failed_pc=0x0c0b5984u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a2cu,2);
goto P_0c0b5986;
P_0c0b5986: /* original 4e0b, guest PC 0x0c0b5986 */
if(!s->budget--) { s->failed_pc=0x0c0b5986u; return 0; }
target=r[14];
r[16]=0x0c0b598au;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b598au) { target=s->pc; goto dispatch; }
goto P_0c0b598a;
P_0c0b5988: /* original 6552, guest PC 0x0c0b5988 */
if(!s->budget--) { s->failed_pc=0x0c0b5988u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b598a;
P_0c0b598a: /* original 9550, guest PC 0x0c0b598a */
if(!s->budget--) { s->failed_pc=0x0c0b598au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a2eu,2);
goto P_0c0b598c;
P_0c0b598c: /* original 35dc, guest PC 0x0c0b598c */
if(!s->budget--) { s->failed_pc=0x0c0b598cu; return 0; }
r[5]+=r[13];
goto P_0c0b598e;
P_0c0b598e: /* original 1f51, guest PC 0x0c0b598e */
if(!s->budget--) { s->failed_pc=0x0c0b598eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b5990;
P_0c0b5990: /* original 944e, guest PC 0x0c0b5990 */
if(!s->budget--) { s->failed_pc=0x0c0b5990u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a30u,2);
goto P_0c0b5992;
P_0c0b5992: /* original 4e0b, guest PC 0x0c0b5992 */
if(!s->budget--) { s->failed_pc=0x0c0b5992u; return 0; }
target=r[14];
r[16]=0x0c0b5996u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5996u) { target=s->pc; goto dispatch; }
goto P_0c0b5996;
P_0c0b5994: /* original 6552, guest PC 0x0c0b5994 */
if(!s->budget--) { s->failed_pc=0x0c0b5994u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5996;
P_0c0b5996: /* original 944d, guest PC 0x0c0b5996 */
if(!s->budget--) { s->failed_pc=0x0c0b5996u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a34u,2);
goto P_0c0b5998;
P_0c0b5998: /* original 904b, guest PC 0x0c0b5998 */
if(!s->budget--) { s->failed_pc=0x0c0b5998u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a32u,2);
goto P_0c0b599a;
P_0c0b599a: /* original 4e0b, guest PC 0x0c0b599a */
if(!s->budget--) { s->failed_pc=0x0c0b599au; return 0; }
target=r[14];
r[16]=0x0c0b599eu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b599eu) { target=s->pc; goto dispatch; }
goto P_0c0b599e;
P_0c0b599c: /* original 05de, guest PC 0x0c0b599c */
if(!s->budget--) { s->failed_pc=0x0c0b599cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b599e;
P_0c0b599e: /* original 944b, guest PC 0x0c0b599e */
if(!s->budget--) { s->failed_pc=0x0c0b599eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a38u,2);
goto P_0c0b59a0;
P_0c0b59a0: /* original 9049, guest PC 0x0c0b59a0 */
if(!s->budget--) { s->failed_pc=0x0c0b59a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a36u,2);
goto P_0c0b59a2;
P_0c0b59a2: /* original 4e0b, guest PC 0x0c0b59a2 */
if(!s->budget--) { s->failed_pc=0x0c0b59a2u; return 0; }
target=r[14];
r[16]=0x0c0b59a6u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59a6u) { target=s->pc; goto dispatch; }
goto P_0c0b59a6;
P_0c0b59a4: /* original 05de, guest PC 0x0c0b59a4 */
if(!s->budget--) { s->failed_pc=0x0c0b59a4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b59a6;
P_0c0b59a6: /* original 9948, guest PC 0x0c0b59a6 */
if(!s->budget--) { s->failed_pc=0x0c0b59a6u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a3au,2);
goto P_0c0b59a8;
P_0c0b59a8: /* original 9448, guest PC 0x0c0b59a8 */
if(!s->budget--) { s->failed_pc=0x0c0b59a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a3cu,2);
goto P_0c0b59aa;
P_0c0b59aa: /* original 39dc, guest PC 0x0c0b59aa */
if(!s->budget--) { s->failed_pc=0x0c0b59aau; return 0; }
r[9]+=r[13];
goto P_0c0b59ac;
P_0c0b59ac: /* original 4e0b, guest PC 0x0c0b59ac */
if(!s->budget--) { s->failed_pc=0x0c0b59acu; return 0; }
target=r[14];
r[16]=0x0c0b59b0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59b0u) { target=s->pc; goto dispatch; }
goto P_0c0b59b0;
P_0c0b59ae: /* original 6592, guest PC 0x0c0b59ae */
if(!s->budget--) { s->failed_pc=0x0c0b59aeu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b59b0;
P_0c0b59b0: /* original 9445, guest PC 0x0c0b59b0 */
if(!s->budget--) { s->failed_pc=0x0c0b59b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a3eu,2);
goto P_0c0b59b2;
P_0c0b59b2: /* original 4e0b, guest PC 0x0c0b59b2 */
if(!s->budget--) { s->failed_pc=0x0c0b59b2u; return 0; }
target=r[14];
r[16]=0x0c0b59b6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59b6u) { target=s->pc; goto dispatch; }
goto P_0c0b59b6;
P_0c0b59b4: /* original 6592, guest PC 0x0c0b59b4 */
if(!s->budget--) { s->failed_pc=0x0c0b59b4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b59b6;
P_0c0b59b6: /* original 9443, guest PC 0x0c0b59b6 */
if(!s->budget--) { s->failed_pc=0x0c0b59b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a40u,2);
goto P_0c0b59b8;
P_0c0b59b8: /* original 4e0b, guest PC 0x0c0b59b8 */
if(!s->budget--) { s->failed_pc=0x0c0b59b8u; return 0; }
target=r[14];
r[16]=0x0c0b59bcu;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59bcu) { target=s->pc; goto dispatch; }
goto P_0c0b59bc;
P_0c0b59ba: /* original 6592, guest PC 0x0c0b59ba */
if(!s->budget--) { s->failed_pc=0x0c0b59bau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b59bc;
P_0c0b59bc: /* original 9441, guest PC 0x0c0b59bc */
if(!s->budget--) { s->failed_pc=0x0c0b59bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a42u,2);
goto P_0c0b59be;
P_0c0b59be: /* original 4e0b, guest PC 0x0c0b59be */
if(!s->budget--) { s->failed_pc=0x0c0b59beu; return 0; }
target=r[14];
r[16]=0x0c0b59c2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59c2u) { target=s->pc; goto dispatch; }
goto P_0c0b59c2;
P_0c0b59c0: /* original 6592, guest PC 0x0c0b59c0 */
if(!s->budget--) { s->failed_pc=0x0c0b59c0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b59c2;
P_0c0b59c2: /* original 9c3f, guest PC 0x0c0b59c2 */
if(!s->budget--) { s->failed_pc=0x0c0b59c2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a44u,2);
goto P_0c0b59c4;
P_0c0b59c4: /* original 943f, guest PC 0x0c0b59c4 */
if(!s->budget--) { s->failed_pc=0x0c0b59c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a46u,2);
goto P_0c0b59c6;
P_0c0b59c6: /* original 3cdc, guest PC 0x0c0b59c6 */
if(!s->budget--) { s->failed_pc=0x0c0b59c6u; return 0; }
r[12]+=r[13];
goto P_0c0b59c8;
P_0c0b59c8: /* original 4e0b, guest PC 0x0c0b59c8 */
if(!s->budget--) { s->failed_pc=0x0c0b59c8u; return 0; }
target=r[14];
r[16]=0x0c0b59ccu;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59ccu) { target=s->pc; goto dispatch; }
goto P_0c0b59cc;
P_0c0b59ca: /* original 65c2, guest PC 0x0c0b59ca */
if(!s->budget--) { s->failed_pc=0x0c0b59cau; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b59cc;
P_0c0b59cc: /* original 943c, guest PC 0x0c0b59cc */
if(!s->budget--) { s->failed_pc=0x0c0b59ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a48u,2);
goto P_0c0b59ce;
P_0c0b59ce: /* original 4e0b, guest PC 0x0c0b59ce */
if(!s->budget--) { s->failed_pc=0x0c0b59ceu; return 0; }
target=r[14];
r[16]=0x0c0b59d2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59d2u) { target=s->pc; goto dispatch; }
goto P_0c0b59d2;
P_0c0b59d0: /* original 65c2, guest PC 0x0c0b59d0 */
if(!s->budget--) { s->failed_pc=0x0c0b59d0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b59d2;
P_0c0b59d2: /* original 943a, guest PC 0x0c0b59d2 */
if(!s->budget--) { s->failed_pc=0x0c0b59d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a4au,2);
goto P_0c0b59d4;
P_0c0b59d4: /* original 4e0b, guest PC 0x0c0b59d4 */
if(!s->budget--) { s->failed_pc=0x0c0b59d4u; return 0; }
target=r[14];
r[16]=0x0c0b59d8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59d8u) { target=s->pc; goto dispatch; }
goto P_0c0b59d8;
P_0c0b59d6: /* original 65c2, guest PC 0x0c0b59d6 */
if(!s->budget--) { s->failed_pc=0x0c0b59d6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b59d8;
P_0c0b59d8: /* original 9438, guest PC 0x0c0b59d8 */
if(!s->budget--) { s->failed_pc=0x0c0b59d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a4cu,2);
goto P_0c0b59da;
P_0c0b59da: /* original 4e0b, guest PC 0x0c0b59da */
if(!s->budget--) { s->failed_pc=0x0c0b59dau; return 0; }
target=r[14];
r[16]=0x0c0b59deu;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b59deu) { target=s->pc; goto dispatch; }
goto P_0c0b59de;
P_0c0b59dc: /* original 65c2, guest PC 0x0c0b59dc */
if(!s->budget--) { s->failed_pc=0x0c0b59dcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b59de;
P_0c0b59de: /* original 9b36, guest PC 0x0c0b59de */
if(!s->budget--) { s->failed_pc=0x0c0b59deu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5a4eu,2);
goto P_0c0b59e0;
P_0c0b59e0: /* original 3bdc, guest PC 0x0c0b59e0 */
if(!s->budget--) { s->failed_pc=0x0c0b59e0u; return 0; }
r[11]+=r[13];
goto P_0c0b59e2;
P_0c0b59e2: /* original a037, guest PC 0x0c0b59e2 */
if(!s->budget--) { s->failed_pc=0x0c0b59e2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5a54;
P_0c0b59e4: /* original 65b2, guest PC 0x0c0b59e4 */
if(!s->budget--) { s->failed_pc=0x0c0b59e4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
return vf3_matrix_family(0x0c0b59e6u,s,ram);
P_0c0b5a54: /* original 94ab, guest PC 0x0c0b5a54 */
if(!s->budget--) { s->failed_pc=0x0c0b5a54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5baeu,2);
goto P_0c0b5a56;
P_0c0b5a56: /* original 4e0b, guest PC 0x0c0b5a56 */
if(!s->budget--) { s->failed_pc=0x0c0b5a56u; return 0; }
target=r[14];
r[16]=0x0c0b5a5au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a5au) { target=s->pc; goto dispatch; }
goto P_0c0b5a5a;
P_0c0b5a58: /* original 0009, guest PC 0x0c0b5a58 */
if(!s->budget--) { s->failed_pc=0x0c0b5a58u; return 0; }
goto P_0c0b5a5a;
P_0c0b5a5a: /* original 94a9, guest PC 0x0c0b5a5a */
if(!s->budget--) { s->failed_pc=0x0c0b5a5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb0u,2);
goto P_0c0b5a5c;
P_0c0b5a5c: /* original 4e0b, guest PC 0x0c0b5a5c */
if(!s->budget--) { s->failed_pc=0x0c0b5a5cu; return 0; }
target=r[14];
r[16]=0x0c0b5a60u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a60u) { target=s->pc; goto dispatch; }
goto P_0c0b5a60;
P_0c0b5a5e: /* original 65b2, guest PC 0x0c0b5a5e */
if(!s->budget--) { s->failed_pc=0x0c0b5a5eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5a60;
P_0c0b5a60: /* original 94a7, guest PC 0x0c0b5a60 */
if(!s->budget--) { s->failed_pc=0x0c0b5a60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb2u,2);
goto P_0c0b5a62;
P_0c0b5a62: /* original 4e0b, guest PC 0x0c0b5a62 */
if(!s->budget--) { s->failed_pc=0x0c0b5a62u; return 0; }
target=r[14];
r[16]=0x0c0b5a66u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a66u) { target=s->pc; goto dispatch; }
goto P_0c0b5a66;
P_0c0b5a64: /* original 65b2, guest PC 0x0c0b5a64 */
if(!s->budget--) { s->failed_pc=0x0c0b5a64u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5a66;
P_0c0b5a66: /* original 94a5, guest PC 0x0c0b5a66 */
if(!s->budget--) { s->failed_pc=0x0c0b5a66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb4u,2);
goto P_0c0b5a68;
P_0c0b5a68: /* original 4e0b, guest PC 0x0c0b5a68 */
if(!s->budget--) { s->failed_pc=0x0c0b5a68u; return 0; }
target=r[14];
r[16]=0x0c0b5a6cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a6cu) { target=s->pc; goto dispatch; }
goto P_0c0b5a6c;
P_0c0b5a6a: /* original 65b2, guest PC 0x0c0b5a6a */
if(!s->budget--) { s->failed_pc=0x0c0b5a6au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5a6c;
P_0c0b5a6c: /* original 9aa3, guest PC 0x0c0b5a6c */
if(!s->budget--) { s->failed_pc=0x0c0b5a6cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb6u,2);
goto P_0c0b5a6e;
P_0c0b5a6e: /* original 94a3, guest PC 0x0c0b5a6e */
if(!s->budget--) { s->failed_pc=0x0c0b5a6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bb8u,2);
goto P_0c0b5a70;
P_0c0b5a70: /* original 3adc, guest PC 0x0c0b5a70 */
if(!s->budget--) { s->failed_pc=0x0c0b5a70u; return 0; }
r[10]+=r[13];
goto P_0c0b5a72;
P_0c0b5a72: /* original 4e0b, guest PC 0x0c0b5a72 */
if(!s->budget--) { s->failed_pc=0x0c0b5a72u; return 0; }
target=r[14];
r[16]=0x0c0b5a76u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a76u) { target=s->pc; goto dispatch; }
goto P_0c0b5a76;
P_0c0b5a74: /* original 65a2, guest PC 0x0c0b5a74 */
if(!s->budget--) { s->failed_pc=0x0c0b5a74u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5a76;
P_0c0b5a76: /* original 94a0, guest PC 0x0c0b5a76 */
if(!s->budget--) { s->failed_pc=0x0c0b5a76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bbau,2);
goto P_0c0b5a78;
P_0c0b5a78: /* original 4e0b, guest PC 0x0c0b5a78 */
if(!s->budget--) { s->failed_pc=0x0c0b5a78u; return 0; }
target=r[14];
r[16]=0x0c0b5a7cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a7cu) { target=s->pc; goto dispatch; }
goto P_0c0b5a7c;
P_0c0b5a7a: /* original 65a2, guest PC 0x0c0b5a7a */
if(!s->budget--) { s->failed_pc=0x0c0b5a7au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5a7c;
P_0c0b5a7c: /* original 949e, guest PC 0x0c0b5a7c */
if(!s->budget--) { s->failed_pc=0x0c0b5a7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bbcu,2);
goto P_0c0b5a7e;
P_0c0b5a7e: /* original 4e0b, guest PC 0x0c0b5a7e */
if(!s->budget--) { s->failed_pc=0x0c0b5a7eu; return 0; }
target=r[14];
r[16]=0x0c0b5a82u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a82u) { target=s->pc; goto dispatch; }
goto P_0c0b5a82;
P_0c0b5a80: /* original 65a2, guest PC 0x0c0b5a80 */
if(!s->budget--) { s->failed_pc=0x0c0b5a80u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5a82;
P_0c0b5a82: /* original 949c, guest PC 0x0c0b5a82 */
if(!s->budget--) { s->failed_pc=0x0c0b5a82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bbeu,2);
goto P_0c0b5a84;
P_0c0b5a84: /* original 4e0b, guest PC 0x0c0b5a84 */
if(!s->budget--) { s->failed_pc=0x0c0b5a84u; return 0; }
target=r[14];
r[16]=0x0c0b5a88u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a88u) { target=s->pc; goto dispatch; }
goto P_0c0b5a88;
P_0c0b5a86: /* original 65a2, guest PC 0x0c0b5a86 */
if(!s->budget--) { s->failed_pc=0x0c0b5a86u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5a88;
P_0c0b5a88: /* original 949a, guest PC 0x0c0b5a88 */
if(!s->budget--) { s->failed_pc=0x0c0b5a88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc0u,2);
goto P_0c0b5a8a;
P_0c0b5a8a: /* original 65f2, guest PC 0x0c0b5a8a */
if(!s->budget--) { s->failed_pc=0x0c0b5a8au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5a8c;
P_0c0b5a8c: /* original 4e0b, guest PC 0x0c0b5a8c */
if(!s->budget--) { s->failed_pc=0x0c0b5a8cu; return 0; }
target=r[14];
r[16]=0x0c0b5a90u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a90u) { target=s->pc; goto dispatch; }
goto P_0c0b5a90;
P_0c0b5a8e: /* original 6552, guest PC 0x0c0b5a8e */
if(!s->budget--) { s->failed_pc=0x0c0b5a8eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5a90;
P_0c0b5a90: /* original 9497, guest PC 0x0c0b5a90 */
if(!s->budget--) { s->failed_pc=0x0c0b5a90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc2u,2);
goto P_0c0b5a92;
P_0c0b5a92: /* original 55f1, guest PC 0x0c0b5a92 */
if(!s->budget--) { s->failed_pc=0x0c0b5a92u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b5a94;
P_0c0b5a94: /* original 4e0b, guest PC 0x0c0b5a94 */
if(!s->budget--) { s->failed_pc=0x0c0b5a94u; return 0; }
target=r[14];
r[16]=0x0c0b5a98u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a98u) { target=s->pc; goto dispatch; }
goto P_0c0b5a98;
P_0c0b5a96: /* original 6552, guest PC 0x0c0b5a96 */
if(!s->budget--) { s->failed_pc=0x0c0b5a96u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5a98;
P_0c0b5a98: /* original 9494, guest PC 0x0c0b5a98 */
if(!s->budget--) { s->failed_pc=0x0c0b5a98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc4u,2);
goto P_0c0b5a9a;
P_0c0b5a9a: /* original 4e0b, guest PC 0x0c0b5a9a */
if(!s->budget--) { s->failed_pc=0x0c0b5a9au; return 0; }
target=r[14];
r[16]=0x0c0b5a9eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5a9eu) { target=s->pc; goto dispatch; }
goto P_0c0b5a9e;
P_0c0b5a9c: /* original 6592, guest PC 0x0c0b5a9c */
if(!s->budget--) { s->failed_pc=0x0c0b5a9cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5a9e;
P_0c0b5a9e: /* original 9492, guest PC 0x0c0b5a9e */
if(!s->budget--) { s->failed_pc=0x0c0b5a9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc6u,2);
goto P_0c0b5aa0;
P_0c0b5aa0: /* original 4e0b, guest PC 0x0c0b5aa0 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa0u; return 0; }
target=r[14];
r[16]=0x0c0b5aa4u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5aa4u) { target=s->pc; goto dispatch; }
goto P_0c0b5aa4;
P_0c0b5aa2: /* original 6592, guest PC 0x0c0b5aa2 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5aa4;
P_0c0b5aa4: /* original 9490, guest PC 0x0c0b5aa4 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bc8u,2);
goto P_0c0b5aa6;
P_0c0b5aa6: /* original 4e0b, guest PC 0x0c0b5aa6 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa6u; return 0; }
target=r[14];
r[16]=0x0c0b5aaau;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5aaau) { target=s->pc; goto dispatch; }
goto P_0c0b5aaa;
P_0c0b5aa8: /* original 6592, guest PC 0x0c0b5aa8 */
if(!s->budget--) { s->failed_pc=0x0c0b5aa8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5aaa;
P_0c0b5aaa: /* original 948e, guest PC 0x0c0b5aaa */
if(!s->budget--) { s->failed_pc=0x0c0b5aaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bcau,2);
goto P_0c0b5aac;
P_0c0b5aac: /* original 4e0b, guest PC 0x0c0b5aac */
if(!s->budget--) { s->failed_pc=0x0c0b5aacu; return 0; }
target=r[14];
r[16]=0x0c0b5ab0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ab0u) { target=s->pc; goto dispatch; }
goto P_0c0b5ab0;
P_0c0b5aae: /* original 6592, guest PC 0x0c0b5aae */
if(!s->budget--) { s->failed_pc=0x0c0b5aaeu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b5ab0;
P_0c0b5ab0: /* original 948c, guest PC 0x0c0b5ab0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bccu,2);
goto P_0c0b5ab2;
P_0c0b5ab2: /* original 4e0b, guest PC 0x0c0b5ab2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab2u; return 0; }
target=r[14];
r[16]=0x0c0b5ab6u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ab6u) { target=s->pc; goto dispatch; }
goto P_0c0b5ab6;
P_0c0b5ab4: /* original 65c2, guest PC 0x0c0b5ab4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab4u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5ab6;
P_0c0b5ab6: /* original 948a, guest PC 0x0c0b5ab6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bceu,2);
goto P_0c0b5ab8;
P_0c0b5ab8: /* original 4e0b, guest PC 0x0c0b5ab8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ab8u; return 0; }
target=r[14];
r[16]=0x0c0b5abcu;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5abcu) { target=s->pc; goto dispatch; }
goto P_0c0b5abc;
P_0c0b5aba: /* original 65c2, guest PC 0x0c0b5aba */
if(!s->budget--) { s->failed_pc=0x0c0b5abau; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5abc;
P_0c0b5abc: /* original 9488, guest PC 0x0c0b5abc */
if(!s->budget--) { s->failed_pc=0x0c0b5abcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd0u,2);
goto P_0c0b5abe;
P_0c0b5abe: /* original 4e0b, guest PC 0x0c0b5abe */
if(!s->budget--) { s->failed_pc=0x0c0b5abeu; return 0; }
target=r[14];
r[16]=0x0c0b5ac2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ac2u) { target=s->pc; goto dispatch; }
goto P_0c0b5ac2;
P_0c0b5ac0: /* original 65c2, guest PC 0x0c0b5ac0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5ac2;
P_0c0b5ac2: /* original 9486, guest PC 0x0c0b5ac2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd2u,2);
goto P_0c0b5ac4;
P_0c0b5ac4: /* original 4e0b, guest PC 0x0c0b5ac4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac4u; return 0; }
target=r[14];
r[16]=0x0c0b5ac8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ac8u) { target=s->pc; goto dispatch; }
goto P_0c0b5ac8;
P_0c0b5ac6: /* original 65c2, guest PC 0x0c0b5ac6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b5ac8;
P_0c0b5ac8: /* original 9484, guest PC 0x0c0b5ac8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ac8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd4u,2);
goto P_0c0b5aca;
P_0c0b5aca: /* original 4e0b, guest PC 0x0c0b5aca */
if(!s->budget--) { s->failed_pc=0x0c0b5acau; return 0; }
target=r[14];
r[16]=0x0c0b5aceu;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5aceu) { target=s->pc; goto dispatch; }
goto P_0c0b5ace;
P_0c0b5acc: /* original 65b2, guest PC 0x0c0b5acc */
if(!s->budget--) { s->failed_pc=0x0c0b5accu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5ace;
P_0c0b5ace: /* original 9482, guest PC 0x0c0b5ace */
if(!s->budget--) { s->failed_pc=0x0c0b5aceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd6u,2);
goto P_0c0b5ad0;
P_0c0b5ad0: /* original 4e0b, guest PC 0x0c0b5ad0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad0u; return 0; }
target=r[14];
r[16]=0x0c0b5ad4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ad4u) { target=s->pc; goto dispatch; }
goto P_0c0b5ad4;
P_0c0b5ad2: /* original 65b2, guest PC 0x0c0b5ad2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5ad4;
P_0c0b5ad4: /* original 9480, guest PC 0x0c0b5ad4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bd8u,2);
goto P_0c0b5ad6;
P_0c0b5ad6: /* original 4e0b, guest PC 0x0c0b5ad6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad6u; return 0; }
target=r[14];
r[16]=0x0c0b5adau;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5adau) { target=s->pc; goto dispatch; }
goto P_0c0b5ada;
P_0c0b5ad8: /* original 65b2, guest PC 0x0c0b5ad8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ad8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5ada;
P_0c0b5ada: /* original 947e, guest PC 0x0c0b5ada */
if(!s->budget--) { s->failed_pc=0x0c0b5adau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bdau,2);
goto P_0c0b5adc;
P_0c0b5adc: /* original 4e0b, guest PC 0x0c0b5adc */
if(!s->budget--) { s->failed_pc=0x0c0b5adcu; return 0; }
target=r[14];
r[16]=0x0c0b5ae0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ae0u) { target=s->pc; goto dispatch; }
goto P_0c0b5ae0;
P_0c0b5ade: /* original 65b2, guest PC 0x0c0b5ade */
if(!s->budget--) { s->failed_pc=0x0c0b5adeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b5ae0;
P_0c0b5ae0: /* original 947c, guest PC 0x0c0b5ae0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bdcu,2);
goto P_0c0b5ae2;
P_0c0b5ae2: /* original 4e0b, guest PC 0x0c0b5ae2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae2u; return 0; }
target=r[14];
r[16]=0x0c0b5ae6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ae6u) { target=s->pc; goto dispatch; }
goto P_0c0b5ae6;
P_0c0b5ae4: /* original 65a2, guest PC 0x0c0b5ae4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5ae6;
P_0c0b5ae6: /* original 947a, guest PC 0x0c0b5ae6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bdeu,2);
goto P_0c0b5ae8;
P_0c0b5ae8: /* original 4e0b, guest PC 0x0c0b5ae8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ae8u; return 0; }
target=r[14];
r[16]=0x0c0b5aecu;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5aecu) { target=s->pc; goto dispatch; }
goto P_0c0b5aec;
P_0c0b5aea: /* original 65a2, guest PC 0x0c0b5aea */
if(!s->budget--) { s->failed_pc=0x0c0b5aeau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5aec;
P_0c0b5aec: /* original 9478, guest PC 0x0c0b5aec */
if(!s->budget--) { s->failed_pc=0x0c0b5aecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be0u,2);
goto P_0c0b5aee;
P_0c0b5aee: /* original 4e0b, guest PC 0x0c0b5aee */
if(!s->budget--) { s->failed_pc=0x0c0b5aeeu; return 0; }
target=r[14];
r[16]=0x0c0b5af2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5af2u) { target=s->pc; goto dispatch; }
goto P_0c0b5af2;
P_0c0b5af0: /* original 65a2, guest PC 0x0c0b5af0 */
if(!s->budget--) { s->failed_pc=0x0c0b5af0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5af2;
P_0c0b5af2: /* original 9476, guest PC 0x0c0b5af2 */
if(!s->budget--) { s->failed_pc=0x0c0b5af2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be2u,2);
goto P_0c0b5af4;
P_0c0b5af4: /* original 4e0b, guest PC 0x0c0b5af4 */
if(!s->budget--) { s->failed_pc=0x0c0b5af4u; return 0; }
target=r[14];
r[16]=0x0c0b5af8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5af8u) { target=s->pc; goto dispatch; }
goto P_0c0b5af8;
P_0c0b5af6: /* original 65a2, guest PC 0x0c0b5af6 */
if(!s->budget--) { s->failed_pc=0x0c0b5af6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b5af8;
P_0c0b5af8: /* original 9574, guest PC 0x0c0b5af8 */
if(!s->budget--) { s->failed_pc=0x0c0b5af8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be4u,2);
goto P_0c0b5afa;
P_0c0b5afa: /* original 35dc, guest PC 0x0c0b5afa */
if(!s->budget--) { s->failed_pc=0x0c0b5afau; return 0; }
r[5]+=r[13];
goto P_0c0b5afc;
P_0c0b5afc: /* original 2f52, guest PC 0x0c0b5afc */
if(!s->budget--) { s->failed_pc=0x0c0b5afcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5afe;
P_0c0b5afe: /* original 9472, guest PC 0x0c0b5afe */
if(!s->budget--) { s->failed_pc=0x0c0b5afeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be6u,2);
goto P_0c0b5b00;
P_0c0b5b00: /* original 4e0b, guest PC 0x0c0b5b00 */
if(!s->budget--) { s->failed_pc=0x0c0b5b00u; return 0; }
target=r[14];
r[16]=0x0c0b5b04u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b04u) { target=s->pc; goto dispatch; }
goto P_0c0b5b04;
P_0c0b5b02: /* original 6552, guest PC 0x0c0b5b02 */
if(!s->budget--) { s->failed_pc=0x0c0b5b02u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b04;
P_0c0b5b04: /* original 9470, guest PC 0x0c0b5b04 */
if(!s->budget--) { s->failed_pc=0x0c0b5b04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5be8u,2);
goto P_0c0b5b06;
P_0c0b5b06: /* original 65f2, guest PC 0x0c0b5b06 */
if(!s->budget--) { s->failed_pc=0x0c0b5b06u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b08;
P_0c0b5b08: /* original 4e0b, guest PC 0x0c0b5b08 */
if(!s->budget--) { s->failed_pc=0x0c0b5b08u; return 0; }
target=r[14];
r[16]=0x0c0b5b0cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b0cu) { target=s->pc; goto dispatch; }
goto P_0c0b5b0c;
P_0c0b5b0a: /* original 6552, guest PC 0x0c0b5b0a */
if(!s->budget--) { s->failed_pc=0x0c0b5b0au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b0c;
P_0c0b5b0c: /* original 956d, guest PC 0x0c0b5b0c */
if(!s->budget--) { s->failed_pc=0x0c0b5b0cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5beau,2);
goto P_0c0b5b0e;
P_0c0b5b0e: /* original 35dc, guest PC 0x0c0b5b0e */
if(!s->budget--) { s->failed_pc=0x0c0b5b0eu; return 0; }
r[5]+=r[13];
goto P_0c0b5b10;
P_0c0b5b10: /* original 2f52, guest PC 0x0c0b5b10 */
if(!s->budget--) { s->failed_pc=0x0c0b5b10u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b12;
P_0c0b5b12: /* original 946b, guest PC 0x0c0b5b12 */
if(!s->budget--) { s->failed_pc=0x0c0b5b12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5becu,2);
goto P_0c0b5b14;
P_0c0b5b14: /* original 4e0b, guest PC 0x0c0b5b14 */
if(!s->budget--) { s->failed_pc=0x0c0b5b14u; return 0; }
target=r[14];
r[16]=0x0c0b5b18u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b18u) { target=s->pc; goto dispatch; }
goto P_0c0b5b18;
P_0c0b5b16: /* original 6552, guest PC 0x0c0b5b16 */
if(!s->budget--) { s->failed_pc=0x0c0b5b16u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b18;
P_0c0b5b18: /* original 9469, guest PC 0x0c0b5b18 */
if(!s->budget--) { s->failed_pc=0x0c0b5b18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5beeu,2);
goto P_0c0b5b1a;
P_0c0b5b1a: /* original 65f2, guest PC 0x0c0b5b1a */
if(!s->budget--) { s->failed_pc=0x0c0b5b1au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b1c;
P_0c0b5b1c: /* original 4e0b, guest PC 0x0c0b5b1c */
if(!s->budget--) { s->failed_pc=0x0c0b5b1cu; return 0; }
target=r[14];
r[16]=0x0c0b5b20u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b20u) { target=s->pc; goto dispatch; }
goto P_0c0b5b20;
P_0c0b5b1e: /* original 6552, guest PC 0x0c0b5b1e */
if(!s->budget--) { s->failed_pc=0x0c0b5b1eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b20;
P_0c0b5b20: /* original 9467, guest PC 0x0c0b5b20 */
if(!s->budget--) { s->failed_pc=0x0c0b5b20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf2u,2);
goto P_0c0b5b22;
P_0c0b5b22: /* original 9065, guest PC 0x0c0b5b22 */
if(!s->budget--) { s->failed_pc=0x0c0b5b22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf0u,2);
goto P_0c0b5b24;
P_0c0b5b24: /* original 4e0b, guest PC 0x0c0b5b24 */
if(!s->budget--) { s->failed_pc=0x0c0b5b24u; return 0; }
target=r[14];
r[16]=0x0c0b5b28u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b28u) { target=s->pc; goto dispatch; }
goto P_0c0b5b28;
P_0c0b5b26: /* original 05de, guest PC 0x0c0b5b26 */
if(!s->budget--) { s->failed_pc=0x0c0b5b26u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b28;
P_0c0b5b28: /* original 9564, guest PC 0x0c0b5b28 */
if(!s->budget--) { s->failed_pc=0x0c0b5b28u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf4u,2);
goto P_0c0b5b2a;
P_0c0b5b2a: /* original 35dc, guest PC 0x0c0b5b2a */
if(!s->budget--) { s->failed_pc=0x0c0b5b2au; return 0; }
r[5]+=r[13];
goto P_0c0b5b2c;
P_0c0b5b2c: /* original 2f52, guest PC 0x0c0b5b2c */
if(!s->budget--) { s->failed_pc=0x0c0b5b2cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b2e;
P_0c0b5b2e: /* original 9462, guest PC 0x0c0b5b2e */
if(!s->budget--) { s->failed_pc=0x0c0b5b2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf6u,2);
goto P_0c0b5b30;
P_0c0b5b30: /* original 4e0b, guest PC 0x0c0b5b30 */
if(!s->budget--) { s->failed_pc=0x0c0b5b30u; return 0; }
target=r[14];
r[16]=0x0c0b5b34u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b34u) { target=s->pc; goto dispatch; }
goto P_0c0b5b34;
P_0c0b5b32: /* original 6552, guest PC 0x0c0b5b32 */
if(!s->budget--) { s->failed_pc=0x0c0b5b32u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b34;
P_0c0b5b34: /* original 9460, guest PC 0x0c0b5b34 */
if(!s->budget--) { s->failed_pc=0x0c0b5b34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bf8u,2);
goto P_0c0b5b36;
P_0c0b5b36: /* original 65f2, guest PC 0x0c0b5b36 */
if(!s->budget--) { s->failed_pc=0x0c0b5b36u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b38;
P_0c0b5b38: /* original 4e0b, guest PC 0x0c0b5b38 */
if(!s->budget--) { s->failed_pc=0x0c0b5b38u; return 0; }
target=r[14];
r[16]=0x0c0b5b3cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b3cu) { target=s->pc; goto dispatch; }
goto P_0c0b5b3c;
P_0c0b5b3a: /* original 6552, guest PC 0x0c0b5b3a */
if(!s->budget--) { s->failed_pc=0x0c0b5b3au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b3c;
P_0c0b5b3c: /* original 945e, guest PC 0x0c0b5b3c */
if(!s->budget--) { s->failed_pc=0x0c0b5b3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bfcu,2);
goto P_0c0b5b3e;
P_0c0b5b3e: /* original 905c, guest PC 0x0c0b5b3e */
if(!s->budget--) { s->failed_pc=0x0c0b5b3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bfau,2);
goto P_0c0b5b40;
P_0c0b5b40: /* original 4e0b, guest PC 0x0c0b5b40 */
if(!s->budget--) { s->failed_pc=0x0c0b5b40u; return 0; }
target=r[14];
r[16]=0x0c0b5b44u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b44u) { target=s->pc; goto dispatch; }
goto P_0c0b5b44;
P_0c0b5b42: /* original 05de, guest PC 0x0c0b5b42 */
if(!s->budget--) { s->failed_pc=0x0c0b5b42u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b44;
P_0c0b5b44: /* original 955b, guest PC 0x0c0b5b44 */
if(!s->budget--) { s->failed_pc=0x0c0b5b44u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5bfeu,2);
goto P_0c0b5b46;
P_0c0b5b46: /* original 35dc, guest PC 0x0c0b5b46 */
if(!s->budget--) { s->failed_pc=0x0c0b5b46u; return 0; }
r[5]+=r[13];
goto P_0c0b5b48;
P_0c0b5b48: /* original 2f52, guest PC 0x0c0b5b48 */
if(!s->budget--) { s->failed_pc=0x0c0b5b48u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b4a;
P_0c0b5b4a: /* original 9459, guest PC 0x0c0b5b4a */
if(!s->budget--) { s->failed_pc=0x0c0b5b4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c00u,2);
goto P_0c0b5b4c;
P_0c0b5b4c: /* original 4e0b, guest PC 0x0c0b5b4c */
if(!s->budget--) { s->failed_pc=0x0c0b5b4cu; return 0; }
target=r[14];
r[16]=0x0c0b5b50u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b50u) { target=s->pc; goto dispatch; }
goto P_0c0b5b50;
P_0c0b5b4e: /* original 6552, guest PC 0x0c0b5b4e */
if(!s->budget--) { s->failed_pc=0x0c0b5b4eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b50;
P_0c0b5b50: /* original 9457, guest PC 0x0c0b5b50 */
if(!s->budget--) { s->failed_pc=0x0c0b5b50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c02u,2);
goto P_0c0b5b52;
P_0c0b5b52: /* original 65f2, guest PC 0x0c0b5b52 */
if(!s->budget--) { s->failed_pc=0x0c0b5b52u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b54;
P_0c0b5b54: /* original 4e0b, guest PC 0x0c0b5b54 */
if(!s->budget--) { s->failed_pc=0x0c0b5b54u; return 0; }
target=r[14];
r[16]=0x0c0b5b58u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b58u) { target=s->pc; goto dispatch; }
goto P_0c0b5b58;
P_0c0b5b56: /* original 6552, guest PC 0x0c0b5b56 */
if(!s->budget--) { s->failed_pc=0x0c0b5b56u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b58;
P_0c0b5b58: /* original 9455, guest PC 0x0c0b5b58 */
if(!s->budget--) { s->failed_pc=0x0c0b5b58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c06u,2);
goto P_0c0b5b5a;
P_0c0b5b5a: /* original 9053, guest PC 0x0c0b5b5a */
if(!s->budget--) { s->failed_pc=0x0c0b5b5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c04u,2);
goto P_0c0b5b5c;
P_0c0b5b5c: /* original 4e0b, guest PC 0x0c0b5b5c */
if(!s->budget--) { s->failed_pc=0x0c0b5b5cu; return 0; }
target=r[14];
r[16]=0x0c0b5b60u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b60u) { target=s->pc; goto dispatch; }
goto P_0c0b5b60;
P_0c0b5b5e: /* original 05de, guest PC 0x0c0b5b5e */
if(!s->budget--) { s->failed_pc=0x0c0b5b5eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b60;
P_0c0b5b60: /* original 9552, guest PC 0x0c0b5b60 */
if(!s->budget--) { s->failed_pc=0x0c0b5b60u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c08u,2);
goto P_0c0b5b62;
P_0c0b5b62: /* original 35dc, guest PC 0x0c0b5b62 */
if(!s->budget--) { s->failed_pc=0x0c0b5b62u; return 0; }
r[5]+=r[13];
goto P_0c0b5b64;
P_0c0b5b64: /* original 2f52, guest PC 0x0c0b5b64 */
if(!s->budget--) { s->failed_pc=0x0c0b5b64u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b66;
P_0c0b5b66: /* original 9450, guest PC 0x0c0b5b66 */
if(!s->budget--) { s->failed_pc=0x0c0b5b66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c0au,2);
goto P_0c0b5b68;
P_0c0b5b68: /* original 4e0b, guest PC 0x0c0b5b68 */
if(!s->budget--) { s->failed_pc=0x0c0b5b68u; return 0; }
target=r[14];
r[16]=0x0c0b5b6cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b6cu) { target=s->pc; goto dispatch; }
goto P_0c0b5b6c;
P_0c0b5b6a: /* original 6552, guest PC 0x0c0b5b6a */
if(!s->budget--) { s->failed_pc=0x0c0b5b6au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b6c;
P_0c0b5b6c: /* original 944e, guest PC 0x0c0b5b6c */
if(!s->budget--) { s->failed_pc=0x0c0b5b6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c0cu,2);
goto P_0c0b5b6e;
P_0c0b5b6e: /* original 65f2, guest PC 0x0c0b5b6e */
if(!s->budget--) { s->failed_pc=0x0c0b5b6eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b70;
P_0c0b5b70: /* original 4e0b, guest PC 0x0c0b5b70 */
if(!s->budget--) { s->failed_pc=0x0c0b5b70u; return 0; }
target=r[14];
r[16]=0x0c0b5b74u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b74u) { target=s->pc; goto dispatch; }
goto P_0c0b5b74;
P_0c0b5b72: /* original 6552, guest PC 0x0c0b5b72 */
if(!s->budget--) { s->failed_pc=0x0c0b5b72u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b74;
P_0c0b5b74: /* original 954b, guest PC 0x0c0b5b74 */
if(!s->budget--) { s->failed_pc=0x0c0b5b74u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c0eu,2);
goto P_0c0b5b76;
P_0c0b5b76: /* original 35dc, guest PC 0x0c0b5b76 */
if(!s->budget--) { s->failed_pc=0x0c0b5b76u; return 0; }
r[5]+=r[13];
goto P_0c0b5b78;
P_0c0b5b78: /* original 2f52, guest PC 0x0c0b5b78 */
if(!s->budget--) { s->failed_pc=0x0c0b5b78u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b5b7a;
P_0c0b5b7a: /* original 9449, guest PC 0x0c0b5b7a */
if(!s->budget--) { s->failed_pc=0x0c0b5b7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c10u,2);
goto P_0c0b5b7c;
P_0c0b5b7c: /* original 4e0b, guest PC 0x0c0b5b7c */
if(!s->budget--) { s->failed_pc=0x0c0b5b7cu; return 0; }
target=r[14];
r[16]=0x0c0b5b80u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b80u) { target=s->pc; goto dispatch; }
goto P_0c0b5b80;
P_0c0b5b7e: /* original 6552, guest PC 0x0c0b5b7e */
if(!s->budget--) { s->failed_pc=0x0c0b5b7eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b80;
P_0c0b5b80: /* original 9447, guest PC 0x0c0b5b80 */
if(!s->budget--) { s->failed_pc=0x0c0b5b80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c12u,2);
goto P_0c0b5b82;
P_0c0b5b82: /* original 65f2, guest PC 0x0c0b5b82 */
if(!s->budget--) { s->failed_pc=0x0c0b5b82u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b5b84;
P_0c0b5b84: /* original 4e0b, guest PC 0x0c0b5b84 */
if(!s->budget--) { s->failed_pc=0x0c0b5b84u; return 0; }
target=r[14];
r[16]=0x0c0b5b88u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b88u) { target=s->pc; goto dispatch; }
goto P_0c0b5b88;
P_0c0b5b86: /* original 6552, guest PC 0x0c0b5b86 */
if(!s->budget--) { s->failed_pc=0x0c0b5b86u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b5b88;
P_0c0b5b88: /* original 9445, guest PC 0x0c0b5b88 */
if(!s->budget--) { s->failed_pc=0x0c0b5b88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c16u,2);
goto P_0c0b5b8a;
P_0c0b5b8a: /* original 9043, guest PC 0x0c0b5b8a */
if(!s->budget--) { s->failed_pc=0x0c0b5b8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c14u,2);
goto P_0c0b5b8c;
P_0c0b5b8c: /* original 4e0b, guest PC 0x0c0b5b8c */
if(!s->budget--) { s->failed_pc=0x0c0b5b8cu; return 0; }
target=r[14];
r[16]=0x0c0b5b90u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b90u) { target=s->pc; goto dispatch; }
goto P_0c0b5b90;
P_0c0b5b8e: /* original 05de, guest PC 0x0c0b5b8e */
if(!s->budget--) { s->failed_pc=0x0c0b5b8eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b90;
P_0c0b5b90: /* original 9443, guest PC 0x0c0b5b90 */
if(!s->budget--) { s->failed_pc=0x0c0b5b90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c1au,2);
goto P_0c0b5b92;
P_0c0b5b92: /* original 9041, guest PC 0x0c0b5b92 */
if(!s->budget--) { s->failed_pc=0x0c0b5b92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c18u,2);
goto P_0c0b5b94;
P_0c0b5b94: /* original 4e0b, guest PC 0x0c0b5b94 */
if(!s->budget--) { s->failed_pc=0x0c0b5b94u; return 0; }
target=r[14];
r[16]=0x0c0b5b98u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5b98u) { target=s->pc; goto dispatch; }
goto P_0c0b5b98;
P_0c0b5b96: /* original 05de, guest PC 0x0c0b5b96 */
if(!s->budget--) { s->failed_pc=0x0c0b5b96u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5b98;
P_0c0b5b98: /* original 9441, guest PC 0x0c0b5b98 */
if(!s->budget--) { s->failed_pc=0x0c0b5b98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c1eu,2);
goto P_0c0b5b9a;
P_0c0b5b9a: /* original 903f, guest PC 0x0c0b5b9a */
if(!s->budget--) { s->failed_pc=0x0c0b5b9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c1cu,2);
goto P_0c0b5b9c;
P_0c0b5b9c: /* original 4e0b, guest PC 0x0c0b5b9c */
if(!s->budget--) { s->failed_pc=0x0c0b5b9cu; return 0; }
target=r[14];
r[16]=0x0c0b5ba0u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ba0u) { target=s->pc; goto dispatch; }
goto P_0c0b5ba0;
P_0c0b5b9e: /* original 05de, guest PC 0x0c0b5b9e */
if(!s->budget--) { s->failed_pc=0x0c0b5b9eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5ba0;
P_0c0b5ba0: /* original 943f, guest PC 0x0c0b5ba0 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c22u,2);
goto P_0c0b5ba2;
P_0c0b5ba2: /* original 903d, guest PC 0x0c0b5ba2 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c20u,2);
goto P_0c0b5ba4;
P_0c0b5ba4: /* original 4e0b, guest PC 0x0c0b5ba4 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba4u; return 0; }
target=r[14];
r[16]=0x0c0b5ba8u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5ba8u) { target=s->pc; goto dispatch; }
goto P_0c0b5ba8;
P_0c0b5ba6: /* original 05de, guest PC 0x0c0b5ba6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5ba8;
P_0c0b5ba8: /* original 903c, guest PC 0x0c0b5ba8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ba8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c24u,2);
goto P_0c0b5baa;
P_0c0b5baa: /* original a03c, guest PC 0x0c0b5baa */
if(!s->budget--) { s->failed_pc=0x0c0b5baau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c26;
P_0c0b5bac: /* original 05de, guest PC 0x0c0b5bac */
if(!s->budget--) { s->failed_pc=0x0c0b5bacu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
return vf3_matrix_family(0x0c0b5baeu,s,ram);
P_0c0b5c26: /* original 9432, guest PC 0x0c0b5c26 */
if(!s->budget--) { s->failed_pc=0x0c0b5c26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c8eu,2);
goto P_0c0b5c28;
P_0c0b5c28: /* original 4e0b, guest PC 0x0c0b5c28 */
if(!s->budget--) { s->failed_pc=0x0c0b5c28u; return 0; }
target=r[14];
r[16]=0x0c0b5c2cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c2cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c2c;
P_0c0b5c2a: /* original 0009, guest PC 0x0c0b5c2a */
if(!s->budget--) { s->failed_pc=0x0c0b5c2au; return 0; }
goto P_0c0b5c2c;
P_0c0b5c2c: /* original 9431, guest PC 0x0c0b5c2c */
if(!s->budget--) { s->failed_pc=0x0c0b5c2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c92u,2);
goto P_0c0b5c2e;
P_0c0b5c2e: /* original 902f, guest PC 0x0c0b5c2e */
if(!s->budget--) { s->failed_pc=0x0c0b5c2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c90u,2);
goto P_0c0b5c30;
P_0c0b5c30: /* original 4e0b, guest PC 0x0c0b5c30 */
if(!s->budget--) { s->failed_pc=0x0c0b5c30u; return 0; }
target=r[14];
r[16]=0x0c0b5c34u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c34u) { target=s->pc; goto dispatch; }
goto P_0c0b5c34;
P_0c0b5c32: /* original 05de, guest PC 0x0c0b5c32 */
if(!s->budget--) { s->failed_pc=0x0c0b5c32u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c34;
P_0c0b5c34: /* original 942f, guest PC 0x0c0b5c34 */
if(!s->budget--) { s->failed_pc=0x0c0b5c34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c96u,2);
goto P_0c0b5c36;
P_0c0b5c36: /* original 902d, guest PC 0x0c0b5c36 */
if(!s->budget--) { s->failed_pc=0x0c0b5c36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c94u,2);
goto P_0c0b5c38;
P_0c0b5c38: /* original 4e0b, guest PC 0x0c0b5c38 */
if(!s->budget--) { s->failed_pc=0x0c0b5c38u; return 0; }
target=r[14];
r[16]=0x0c0b5c3cu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c3cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c3c;
P_0c0b5c3a: /* original 05de, guest PC 0x0c0b5c3a */
if(!s->budget--) { s->failed_pc=0x0c0b5c3au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c3c;
P_0c0b5c3c: /* original 942d, guest PC 0x0c0b5c3c */
if(!s->budget--) { s->failed_pc=0x0c0b5c3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c9au,2);
goto P_0c0b5c3e;
P_0c0b5c3e: /* original 902b, guest PC 0x0c0b5c3e */
if(!s->budget--) { s->failed_pc=0x0c0b5c3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c98u,2);
goto P_0c0b5c40;
P_0c0b5c40: /* original 4e0b, guest PC 0x0c0b5c40 */
if(!s->budget--) { s->failed_pc=0x0c0b5c40u; return 0; }
target=r[14];
r[16]=0x0c0b5c44u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c44u) { target=s->pc; goto dispatch; }
goto P_0c0b5c44;
P_0c0b5c42: /* original 05de, guest PC 0x0c0b5c42 */
if(!s->budget--) { s->failed_pc=0x0c0b5c42u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c44;
P_0c0b5c44: /* original 942b, guest PC 0x0c0b5c44 */
if(!s->budget--) { s->failed_pc=0x0c0b5c44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c9eu,2);
goto P_0c0b5c46;
P_0c0b5c46: /* original 9029, guest PC 0x0c0b5c46 */
if(!s->budget--) { s->failed_pc=0x0c0b5c46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5c9cu,2);
goto P_0c0b5c48;
P_0c0b5c48: /* original 4e0b, guest PC 0x0c0b5c48 */
if(!s->budget--) { s->failed_pc=0x0c0b5c48u; return 0; }
target=r[14];
r[16]=0x0c0b5c4cu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c4cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c4c;
P_0c0b5c4a: /* original 05de, guest PC 0x0c0b5c4a */
if(!s->budget--) { s->failed_pc=0x0c0b5c4au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c4c;
P_0c0b5c4c: /* original 9429, guest PC 0x0c0b5c4c */
if(!s->budget--) { s->failed_pc=0x0c0b5c4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca2u,2);
goto P_0c0b5c4e;
P_0c0b5c4e: /* original 9027, guest PC 0x0c0b5c4e */
if(!s->budget--) { s->failed_pc=0x0c0b5c4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca0u,2);
goto P_0c0b5c50;
P_0c0b5c50: /* original 4e0b, guest PC 0x0c0b5c50 */
if(!s->budget--) { s->failed_pc=0x0c0b5c50u; return 0; }
target=r[14];
r[16]=0x0c0b5c54u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c54u) { target=s->pc; goto dispatch; }
goto P_0c0b5c54;
P_0c0b5c52: /* original 05de, guest PC 0x0c0b5c52 */
if(!s->budget--) { s->failed_pc=0x0c0b5c52u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c54;
P_0c0b5c54: /* original 9427, guest PC 0x0c0b5c54 */
if(!s->budget--) { s->failed_pc=0x0c0b5c54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca6u,2);
goto P_0c0b5c56;
P_0c0b5c56: /* original 9025, guest PC 0x0c0b5c56 */
if(!s->budget--) { s->failed_pc=0x0c0b5c56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca4u,2);
goto P_0c0b5c58;
P_0c0b5c58: /* original 4e0b, guest PC 0x0c0b5c58 */
if(!s->budget--) { s->failed_pc=0x0c0b5c58u; return 0; }
target=r[14];
r[16]=0x0c0b5c5cu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c5cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c5c;
P_0c0b5c5a: /* original 05de, guest PC 0x0c0b5c5a */
if(!s->budget--) { s->failed_pc=0x0c0b5c5au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c5c;
P_0c0b5c5c: /* original 9425, guest PC 0x0c0b5c5c */
if(!s->budget--) { s->failed_pc=0x0c0b5c5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5caau,2);
goto P_0c0b5c5e;
P_0c0b5c5e: /* original 9023, guest PC 0x0c0b5c5e */
if(!s->budget--) { s->failed_pc=0x0c0b5c5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5ca8u,2);
goto P_0c0b5c60;
P_0c0b5c60: /* original 4e0b, guest PC 0x0c0b5c60 */
if(!s->budget--) { s->failed_pc=0x0c0b5c60u; return 0; }
target=r[14];
r[16]=0x0c0b5c64u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c64u) { target=s->pc; goto dispatch; }
goto P_0c0b5c64;
P_0c0b5c62: /* original 05de, guest PC 0x0c0b5c62 */
if(!s->budget--) { s->failed_pc=0x0c0b5c62u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c64;
P_0c0b5c64: /* original 9423, guest PC 0x0c0b5c64 */
if(!s->budget--) { s->failed_pc=0x0c0b5c64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5caeu,2);
goto P_0c0b5c66;
P_0c0b5c66: /* original 9021, guest PC 0x0c0b5c66 */
if(!s->budget--) { s->failed_pc=0x0c0b5c66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cacu,2);
goto P_0c0b5c68;
P_0c0b5c68: /* original 4e0b, guest PC 0x0c0b5c68 */
if(!s->budget--) { s->failed_pc=0x0c0b5c68u; return 0; }
target=r[14];
r[16]=0x0c0b5c6cu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c6cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c6c;
P_0c0b5c6a: /* original 05de, guest PC 0x0c0b5c6a */
if(!s->budget--) { s->failed_pc=0x0c0b5c6au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c6c;
P_0c0b5c6c: /* original 9421, guest PC 0x0c0b5c6c */
if(!s->budget--) { s->failed_pc=0x0c0b5c6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cb2u,2);
goto P_0c0b5c6e;
P_0c0b5c6e: /* original 901f, guest PC 0x0c0b5c6e */
if(!s->budget--) { s->failed_pc=0x0c0b5c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cb0u,2);
goto P_0c0b5c70;
P_0c0b5c70: /* original 4e0b, guest PC 0x0c0b5c70 */
if(!s->budget--) { s->failed_pc=0x0c0b5c70u; return 0; }
target=r[14];
r[16]=0x0c0b5c74u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c74u) { target=s->pc; goto dispatch; }
goto P_0c0b5c74;
P_0c0b5c72: /* original 05de, guest PC 0x0c0b5c72 */
if(!s->budget--) { s->failed_pc=0x0c0b5c72u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c74;
P_0c0b5c74: /* original 941f, guest PC 0x0c0b5c74 */
if(!s->budget--) { s->failed_pc=0x0c0b5c74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cb6u,2);
goto P_0c0b5c76;
P_0c0b5c76: /* original 901d, guest PC 0x0c0b5c76 */
if(!s->budget--) { s->failed_pc=0x0c0b5c76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b5cb4u,2);
goto P_0c0b5c78;
P_0c0b5c78: /* original 4e0b, guest PC 0x0c0b5c78 */
if(!s->budget--) { s->failed_pc=0x0c0b5c78u; return 0; }
target=r[14];
r[16]=0x0c0b5c7cu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b5c7cu) { target=s->pc; goto dispatch; }
goto P_0c0b5c7c;
P_0c0b5c7a: /* original 05de, guest PC 0x0c0b5c7a */
if(!s->budget--) { s->failed_pc=0x0c0b5c7au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b5c7c;
P_0c0b5c7c: /* original 7f08, guest PC 0x0c0b5c7c */
if(!s->budget--) { s->failed_pc=0x0c0b5c7cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0b5c7e;
P_0c0b5c7e: /* original 4f26, guest PC 0x0c0b5c7e */
if(!s->budget--) { s->failed_pc=0x0c0b5c7eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b5c80;
P_0c0b5c80: /* original 69f6, guest PC 0x0c0b5c80 */
if(!s->budget--) { s->failed_pc=0x0c0b5c80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b5c82;
P_0c0b5c82: /* original 6af6, guest PC 0x0c0b5c82 */
if(!s->budget--) { s->failed_pc=0x0c0b5c82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b5c84;
P_0c0b5c84: /* original 6bf6, guest PC 0x0c0b5c84 */
if(!s->budget--) { s->failed_pc=0x0c0b5c84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b5c86;
P_0c0b5c86: /* original 6cf6, guest PC 0x0c0b5c86 */
if(!s->budget--) { s->failed_pc=0x0c0b5c86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b5c88;
P_0c0b5c88: /* original 6df6, guest PC 0x0c0b5c88 */
if(!s->budget--) { s->failed_pc=0x0c0b5c88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b5c8a;
P_0c0b5c8a: /* original 000b, guest PC 0x0c0b5c8a */
if(!s->budget--) { s->failed_pc=0x0c0b5c8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b5c8c: /* original 6ef6, guest PC 0x0c0b5c8c */
if(!s->budget--) { s->failed_pc=0x0c0b5c8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0b5c8eu,s,ram);
P_0c0b9700: /* original 4f22, guest PC 0x0c0b9700 */
if(!s->budget--) { s->failed_pc=0x0c0b9700u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b9702;
P_0c0b9702: /* original 94a1, guest PC 0x0c0b9702 */
if(!s->budget--) { s->failed_pc=0x0c0b9702u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9848u,2);
goto P_0c0b9704;
P_0c0b9704: /* original de6b, guest PC 0x0c0b9704 */
if(!s->budget--) { s->failed_pc=0x0c0b9704u; return 0; }
r[14]=read(ram,0x0c0b98b4u,4);
goto P_0c0b9706;
P_0c0b9706: /* original 4e0b, guest PC 0x0c0b9706 */
if(!s->budget--) { s->failed_pc=0x0c0b9706u; return 0; }
target=r[14];
r[16]=0x0c0b970au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b970au) { target=s->pc; goto dispatch; }
goto P_0c0b970a;
P_0c0b9708: /* original 0009, guest PC 0x0c0b9708 */
if(!s->budget--) { s->failed_pc=0x0c0b9708u; return 0; }
goto P_0c0b970a;
P_0c0b970a: /* original 949e, guest PC 0x0c0b970a */
if(!s->budget--) { s->failed_pc=0x0c0b970au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b984au,2);
goto P_0c0b970c;
P_0c0b970c: /* original 4e0b, guest PC 0x0c0b970c */
if(!s->budget--) { s->failed_pc=0x0c0b970cu; return 0; }
target=r[14];
r[16]=0x0c0b9710u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9710u) { target=s->pc; goto dispatch; }
goto P_0c0b9710;
P_0c0b970e: /* original 0009, guest PC 0x0c0b970e */
if(!s->budget--) { s->failed_pc=0x0c0b970eu; return 0; }
goto P_0c0b9710;
P_0c0b9710: /* original 949c, guest PC 0x0c0b9710 */
if(!s->budget--) { s->failed_pc=0x0c0b9710u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b984cu,2);
goto P_0c0b9712;
P_0c0b9712: /* original 4e0b, guest PC 0x0c0b9712 */
if(!s->budget--) { s->failed_pc=0x0c0b9712u; return 0; }
target=r[14];
r[16]=0x0c0b9716u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9716u) { target=s->pc; goto dispatch; }
goto P_0c0b9716;
P_0c0b9714: /* original 0009, guest PC 0x0c0b9714 */
if(!s->budget--) { s->failed_pc=0x0c0b9714u; return 0; }
goto P_0c0b9716;
P_0c0b9716: /* original 949a, guest PC 0x0c0b9716 */
if(!s->budget--) { s->failed_pc=0x0c0b9716u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b984eu,2);
goto P_0c0b9718;
P_0c0b9718: /* original 4e0b, guest PC 0x0c0b9718 */
if(!s->budget--) { s->failed_pc=0x0c0b9718u; return 0; }
target=r[14];
r[16]=0x0c0b971cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b971cu) { target=s->pc; goto dispatch; }
goto P_0c0b971c;
P_0c0b971a: /* original 0009, guest PC 0x0c0b971a */
if(!s->budget--) { s->failed_pc=0x0c0b971au; return 0; }
goto P_0c0b971c;
P_0c0b971c: /* original 9498, guest PC 0x0c0b971c */
if(!s->budget--) { s->failed_pc=0x0c0b971cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9850u,2);
goto P_0c0b971e;
P_0c0b971e: /* original 4e0b, guest PC 0x0c0b971e */
if(!s->budget--) { s->failed_pc=0x0c0b971eu; return 0; }
target=r[14];
r[16]=0x0c0b9722u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9722u) { target=s->pc; goto dispatch; }
goto P_0c0b9722;
P_0c0b9720: /* original 0009, guest PC 0x0c0b9720 */
if(!s->budget--) { s->failed_pc=0x0c0b9720u; return 0; }
goto P_0c0b9722;
P_0c0b9722: /* original 9496, guest PC 0x0c0b9722 */
if(!s->budget--) { s->failed_pc=0x0c0b9722u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9852u,2);
goto P_0c0b9724;
P_0c0b9724: /* original 4e0b, guest PC 0x0c0b9724 */
if(!s->budget--) { s->failed_pc=0x0c0b9724u; return 0; }
target=r[14];
r[16]=0x0c0b9728u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9728u) { target=s->pc; goto dispatch; }
goto P_0c0b9728;
P_0c0b9726: /* original 0009, guest PC 0x0c0b9726 */
if(!s->budget--) { s->failed_pc=0x0c0b9726u; return 0; }
goto P_0c0b9728;
P_0c0b9728: /* original 9494, guest PC 0x0c0b9728 */
if(!s->budget--) { s->failed_pc=0x0c0b9728u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9854u,2);
goto P_0c0b972a;
P_0c0b972a: /* original 4e0b, guest PC 0x0c0b972a */
if(!s->budget--) { s->failed_pc=0x0c0b972au; return 0; }
target=r[14];
r[16]=0x0c0b972eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b972eu) { target=s->pc; goto dispatch; }
goto P_0c0b972e;
P_0c0b972c: /* original 0009, guest PC 0x0c0b972c */
if(!s->budget--) { s->failed_pc=0x0c0b972cu; return 0; }
goto P_0c0b972e;
P_0c0b972e: /* original 9492, guest PC 0x0c0b972e */
if(!s->budget--) { s->failed_pc=0x0c0b972eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9856u,2);
goto P_0c0b9730;
P_0c0b9730: /* original 4e0b, guest PC 0x0c0b9730 */
if(!s->budget--) { s->failed_pc=0x0c0b9730u; return 0; }
target=r[14];
r[16]=0x0c0b9734u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9734u) { target=s->pc; goto dispatch; }
goto P_0c0b9734;
P_0c0b9732: /* original 0009, guest PC 0x0c0b9732 */
if(!s->budget--) { s->failed_pc=0x0c0b9732u; return 0; }
goto P_0c0b9734;
P_0c0b9734: /* original 9490, guest PC 0x0c0b9734 */
if(!s->budget--) { s->failed_pc=0x0c0b9734u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9858u,2);
goto P_0c0b9736;
P_0c0b9736: /* original 4e0b, guest PC 0x0c0b9736 */
if(!s->budget--) { s->failed_pc=0x0c0b9736u; return 0; }
target=r[14];
r[16]=0x0c0b973au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b973au) { target=s->pc; goto dispatch; }
goto P_0c0b973a;
P_0c0b9738: /* original 0009, guest PC 0x0c0b9738 */
if(!s->budget--) { s->failed_pc=0x0c0b9738u; return 0; }
goto P_0c0b973a;
P_0c0b973a: /* original 948e, guest PC 0x0c0b973a */
if(!s->budget--) { s->failed_pc=0x0c0b973au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b985au,2);
goto P_0c0b973c;
P_0c0b973c: /* original 4e0b, guest PC 0x0c0b973c */
if(!s->budget--) { s->failed_pc=0x0c0b973cu; return 0; }
target=r[14];
r[16]=0x0c0b9740u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9740u) { target=s->pc; goto dispatch; }
goto P_0c0b9740;
P_0c0b973e: /* original 0009, guest PC 0x0c0b973e */
if(!s->budget--) { s->failed_pc=0x0c0b973eu; return 0; }
goto P_0c0b9740;
P_0c0b9740: /* original 948c, guest PC 0x0c0b9740 */
if(!s->budget--) { s->failed_pc=0x0c0b9740u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b985cu,2);
goto P_0c0b9742;
P_0c0b9742: /* original 4e0b, guest PC 0x0c0b9742 */
if(!s->budget--) { s->failed_pc=0x0c0b9742u; return 0; }
target=r[14];
r[16]=0x0c0b9746u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9746u) { target=s->pc; goto dispatch; }
goto P_0c0b9746;
P_0c0b9744: /* original 0009, guest PC 0x0c0b9744 */
if(!s->budget--) { s->failed_pc=0x0c0b9744u; return 0; }
goto P_0c0b9746;
P_0c0b9746: /* original 948a, guest PC 0x0c0b9746 */
if(!s->budget--) { s->failed_pc=0x0c0b9746u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b985eu,2);
goto P_0c0b9748;
P_0c0b9748: /* original 4e0b, guest PC 0x0c0b9748 */
if(!s->budget--) { s->failed_pc=0x0c0b9748u; return 0; }
target=r[14];
r[16]=0x0c0b974cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b974cu) { target=s->pc; goto dispatch; }
goto P_0c0b974c;
P_0c0b974a: /* original 0009, guest PC 0x0c0b974a */
if(!s->budget--) { s->failed_pc=0x0c0b974au; return 0; }
goto P_0c0b974c;
P_0c0b974c: /* original 9488, guest PC 0x0c0b974c */
if(!s->budget--) { s->failed_pc=0x0c0b974cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9860u,2);
goto P_0c0b974e;
P_0c0b974e: /* original 4e0b, guest PC 0x0c0b974e */
if(!s->budget--) { s->failed_pc=0x0c0b974eu; return 0; }
target=r[14];
r[16]=0x0c0b9752u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9752u) { target=s->pc; goto dispatch; }
goto P_0c0b9752;
P_0c0b9750: /* original 0009, guest PC 0x0c0b9750 */
if(!s->budget--) { s->failed_pc=0x0c0b9750u; return 0; }
goto P_0c0b9752;
P_0c0b9752: /* original 9486, guest PC 0x0c0b9752 */
if(!s->budget--) { s->failed_pc=0x0c0b9752u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9862u,2);
goto P_0c0b9754;
P_0c0b9754: /* original 4e0b, guest PC 0x0c0b9754 */
if(!s->budget--) { s->failed_pc=0x0c0b9754u; return 0; }
target=r[14];
r[16]=0x0c0b9758u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9758u) { target=s->pc; goto dispatch; }
goto P_0c0b9758;
P_0c0b9756: /* original 0009, guest PC 0x0c0b9756 */
if(!s->budget--) { s->failed_pc=0x0c0b9756u; return 0; }
goto P_0c0b9758;
P_0c0b9758: /* original 9484, guest PC 0x0c0b9758 */
if(!s->budget--) { s->failed_pc=0x0c0b9758u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9864u,2);
goto P_0c0b975a;
P_0c0b975a: /* original 4e0b, guest PC 0x0c0b975a */
if(!s->budget--) { s->failed_pc=0x0c0b975au; return 0; }
target=r[14];
r[16]=0x0c0b975eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b975eu) { target=s->pc; goto dispatch; }
goto P_0c0b975e;
P_0c0b975c: /* original 0009, guest PC 0x0c0b975c */
if(!s->budget--) { s->failed_pc=0x0c0b975cu; return 0; }
goto P_0c0b975e;
P_0c0b975e: /* original 9482, guest PC 0x0c0b975e */
if(!s->budget--) { s->failed_pc=0x0c0b975eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9866u,2);
goto P_0c0b9760;
P_0c0b9760: /* original 4e0b, guest PC 0x0c0b9760 */
if(!s->budget--) { s->failed_pc=0x0c0b9760u; return 0; }
target=r[14];
r[16]=0x0c0b9764u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9764u) { target=s->pc; goto dispatch; }
goto P_0c0b9764;
P_0c0b9762: /* original 0009, guest PC 0x0c0b9762 */
if(!s->budget--) { s->failed_pc=0x0c0b9762u; return 0; }
goto P_0c0b9764;
P_0c0b9764: /* original 9480, guest PC 0x0c0b9764 */
if(!s->budget--) { s->failed_pc=0x0c0b9764u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9868u,2);
goto P_0c0b9766;
P_0c0b9766: /* original 4e0b, guest PC 0x0c0b9766 */
if(!s->budget--) { s->failed_pc=0x0c0b9766u; return 0; }
target=r[14];
r[16]=0x0c0b976au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b976au) { target=s->pc; goto dispatch; }
goto P_0c0b976a;
P_0c0b9768: /* original 0009, guest PC 0x0c0b9768 */
if(!s->budget--) { s->failed_pc=0x0c0b9768u; return 0; }
goto P_0c0b976a;
P_0c0b976a: /* original 947e, guest PC 0x0c0b976a */
if(!s->budget--) { s->failed_pc=0x0c0b976au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b986au,2);
goto P_0c0b976c;
P_0c0b976c: /* original 4e0b, guest PC 0x0c0b976c */
if(!s->budget--) { s->failed_pc=0x0c0b976cu; return 0; }
target=r[14];
r[16]=0x0c0b9770u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9770u) { target=s->pc; goto dispatch; }
goto P_0c0b9770;
P_0c0b976e: /* original 0009, guest PC 0x0c0b976e */
if(!s->budget--) { s->failed_pc=0x0c0b976eu; return 0; }
goto P_0c0b9770;
P_0c0b9770: /* original 947c, guest PC 0x0c0b9770 */
if(!s->budget--) { s->failed_pc=0x0c0b9770u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b986cu,2);
goto P_0c0b9772;
P_0c0b9772: /* original 4e0b, guest PC 0x0c0b9772 */
if(!s->budget--) { s->failed_pc=0x0c0b9772u; return 0; }
target=r[14];
r[16]=0x0c0b9776u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9776u) { target=s->pc; goto dispatch; }
goto P_0c0b9776;
P_0c0b9774: /* original 0009, guest PC 0x0c0b9774 */
if(!s->budget--) { s->failed_pc=0x0c0b9774u; return 0; }
goto P_0c0b9776;
P_0c0b9776: /* original 947a, guest PC 0x0c0b9776 */
if(!s->budget--) { s->failed_pc=0x0c0b9776u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b986eu,2);
goto P_0c0b9778;
P_0c0b9778: /* original 4e0b, guest PC 0x0c0b9778 */
if(!s->budget--) { s->failed_pc=0x0c0b9778u; return 0; }
target=r[14];
r[16]=0x0c0b977cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b977cu) { target=s->pc; goto dispatch; }
goto P_0c0b977c;
P_0c0b977a: /* original 0009, guest PC 0x0c0b977a */
if(!s->budget--) { s->failed_pc=0x0c0b977au; return 0; }
goto P_0c0b977c;
P_0c0b977c: /* original 9478, guest PC 0x0c0b977c */
if(!s->budget--) { s->failed_pc=0x0c0b977cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9870u,2);
goto P_0c0b977e;
P_0c0b977e: /* original 4e0b, guest PC 0x0c0b977e */
if(!s->budget--) { s->failed_pc=0x0c0b977eu; return 0; }
target=r[14];
r[16]=0x0c0b9782u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9782u) { target=s->pc; goto dispatch; }
goto P_0c0b9782;
P_0c0b9780: /* original 0009, guest PC 0x0c0b9780 */
if(!s->budget--) { s->failed_pc=0x0c0b9780u; return 0; }
goto P_0c0b9782;
P_0c0b9782: /* original 9476, guest PC 0x0c0b9782 */
if(!s->budget--) { s->failed_pc=0x0c0b9782u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9872u,2);
goto P_0c0b9784;
P_0c0b9784: /* original 4e0b, guest PC 0x0c0b9784 */
if(!s->budget--) { s->failed_pc=0x0c0b9784u; return 0; }
target=r[14];
r[16]=0x0c0b9788u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9788u) { target=s->pc; goto dispatch; }
goto P_0c0b9788;
P_0c0b9786: /* original 0009, guest PC 0x0c0b9786 */
if(!s->budget--) { s->failed_pc=0x0c0b9786u; return 0; }
goto P_0c0b9788;
P_0c0b9788: /* original 9474, guest PC 0x0c0b9788 */
if(!s->budget--) { s->failed_pc=0x0c0b9788u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9874u,2);
goto P_0c0b978a;
P_0c0b978a: /* original 4e0b, guest PC 0x0c0b978a */
if(!s->budget--) { s->failed_pc=0x0c0b978au; return 0; }
target=r[14];
r[16]=0x0c0b978eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b978eu) { target=s->pc; goto dispatch; }
goto P_0c0b978e;
P_0c0b978c: /* original 0009, guest PC 0x0c0b978c */
if(!s->budget--) { s->failed_pc=0x0c0b978cu; return 0; }
goto P_0c0b978e;
P_0c0b978e: /* original 9472, guest PC 0x0c0b978e */
if(!s->budget--) { s->failed_pc=0x0c0b978eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9876u,2);
goto P_0c0b9790;
P_0c0b9790: /* original 4e0b, guest PC 0x0c0b9790 */
if(!s->budget--) { s->failed_pc=0x0c0b9790u; return 0; }
target=r[14];
r[16]=0x0c0b9794u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9794u) { target=s->pc; goto dispatch; }
goto P_0c0b9794;
P_0c0b9792: /* original 0009, guest PC 0x0c0b9792 */
if(!s->budget--) { s->failed_pc=0x0c0b9792u; return 0; }
goto P_0c0b9794;
P_0c0b9794: /* original 9470, guest PC 0x0c0b9794 */
if(!s->budget--) { s->failed_pc=0x0c0b9794u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9878u,2);
goto P_0c0b9796;
P_0c0b9796: /* original 4e0b, guest PC 0x0c0b9796 */
if(!s->budget--) { s->failed_pc=0x0c0b9796u; return 0; }
target=r[14];
r[16]=0x0c0b979au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b979au) { target=s->pc; goto dispatch; }
goto P_0c0b979a;
P_0c0b9798: /* original 0009, guest PC 0x0c0b9798 */
if(!s->budget--) { s->failed_pc=0x0c0b9798u; return 0; }
goto P_0c0b979a;
P_0c0b979a: /* original 946e, guest PC 0x0c0b979a */
if(!s->budget--) { s->failed_pc=0x0c0b979au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b987au,2);
goto P_0c0b979c;
P_0c0b979c: /* original 4e0b, guest PC 0x0c0b979c */
if(!s->budget--) { s->failed_pc=0x0c0b979cu; return 0; }
target=r[14];
r[16]=0x0c0b97a0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97a0u) { target=s->pc; goto dispatch; }
goto P_0c0b97a0;
P_0c0b979e: /* original 0009, guest PC 0x0c0b979e */
if(!s->budget--) { s->failed_pc=0x0c0b979eu; return 0; }
goto P_0c0b97a0;
P_0c0b97a0: /* original 946c, guest PC 0x0c0b97a0 */
if(!s->budget--) { s->failed_pc=0x0c0b97a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b987cu,2);
goto P_0c0b97a2;
P_0c0b97a2: /* original 4e0b, guest PC 0x0c0b97a2 */
if(!s->budget--) { s->failed_pc=0x0c0b97a2u; return 0; }
target=r[14];
r[16]=0x0c0b97a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97a6u) { target=s->pc; goto dispatch; }
goto P_0c0b97a6;
P_0c0b97a4: /* original 0009, guest PC 0x0c0b97a4 */
if(!s->budget--) { s->failed_pc=0x0c0b97a4u; return 0; }
goto P_0c0b97a6;
P_0c0b97a6: /* original 946a, guest PC 0x0c0b97a6 */
if(!s->budget--) { s->failed_pc=0x0c0b97a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b987eu,2);
goto P_0c0b97a8;
P_0c0b97a8: /* original 4e0b, guest PC 0x0c0b97a8 */
if(!s->budget--) { s->failed_pc=0x0c0b97a8u; return 0; }
target=r[14];
r[16]=0x0c0b97acu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97acu) { target=s->pc; goto dispatch; }
goto P_0c0b97ac;
P_0c0b97aa: /* original 0009, guest PC 0x0c0b97aa */
if(!s->budget--) { s->failed_pc=0x0c0b97aau; return 0; }
goto P_0c0b97ac;
P_0c0b97ac: /* original 9468, guest PC 0x0c0b97ac */
if(!s->budget--) { s->failed_pc=0x0c0b97acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9880u,2);
goto P_0c0b97ae;
P_0c0b97ae: /* original 4e0b, guest PC 0x0c0b97ae */
if(!s->budget--) { s->failed_pc=0x0c0b97aeu; return 0; }
target=r[14];
r[16]=0x0c0b97b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97b2u) { target=s->pc; goto dispatch; }
goto P_0c0b97b2;
P_0c0b97b0: /* original 0009, guest PC 0x0c0b97b0 */
if(!s->budget--) { s->failed_pc=0x0c0b97b0u; return 0; }
goto P_0c0b97b2;
P_0c0b97b2: /* original 9466, guest PC 0x0c0b97b2 */
if(!s->budget--) { s->failed_pc=0x0c0b97b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9882u,2);
goto P_0c0b97b4;
P_0c0b97b4: /* original 4e0b, guest PC 0x0c0b97b4 */
if(!s->budget--) { s->failed_pc=0x0c0b97b4u; return 0; }
target=r[14];
r[16]=0x0c0b97b8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97b8u) { target=s->pc; goto dispatch; }
goto P_0c0b97b8;
P_0c0b97b6: /* original 0009, guest PC 0x0c0b97b6 */
if(!s->budget--) { s->failed_pc=0x0c0b97b6u; return 0; }
goto P_0c0b97b8;
P_0c0b97b8: /* original 9464, guest PC 0x0c0b97b8 */
if(!s->budget--) { s->failed_pc=0x0c0b97b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9884u,2);
goto P_0c0b97ba;
P_0c0b97ba: /* original 4e0b, guest PC 0x0c0b97ba */
if(!s->budget--) { s->failed_pc=0x0c0b97bau; return 0; }
target=r[14];
r[16]=0x0c0b97beu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97beu) { target=s->pc; goto dispatch; }
goto P_0c0b97be;
P_0c0b97bc: /* original 0009, guest PC 0x0c0b97bc */
if(!s->budget--) { s->failed_pc=0x0c0b97bcu; return 0; }
goto P_0c0b97be;
P_0c0b97be: /* original 9462, guest PC 0x0c0b97be */
if(!s->budget--) { s->failed_pc=0x0c0b97beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9886u,2);
goto P_0c0b97c0;
P_0c0b97c0: /* original 4e0b, guest PC 0x0c0b97c0 */
if(!s->budget--) { s->failed_pc=0x0c0b97c0u; return 0; }
target=r[14];
r[16]=0x0c0b97c4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97c4u) { target=s->pc; goto dispatch; }
goto P_0c0b97c4;
P_0c0b97c2: /* original 0009, guest PC 0x0c0b97c2 */
if(!s->budget--) { s->failed_pc=0x0c0b97c2u; return 0; }
goto P_0c0b97c4;
P_0c0b97c4: /* original 9460, guest PC 0x0c0b97c4 */
if(!s->budget--) { s->failed_pc=0x0c0b97c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9888u,2);
goto P_0c0b97c6;
P_0c0b97c6: /* original 4e0b, guest PC 0x0c0b97c6 */
if(!s->budget--) { s->failed_pc=0x0c0b97c6u; return 0; }
target=r[14];
r[16]=0x0c0b97cau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97cau) { target=s->pc; goto dispatch; }
goto P_0c0b97ca;
P_0c0b97c8: /* original 0009, guest PC 0x0c0b97c8 */
if(!s->budget--) { s->failed_pc=0x0c0b97c8u; return 0; }
goto P_0c0b97ca;
P_0c0b97ca: /* original 945e, guest PC 0x0c0b97ca */
if(!s->budget--) { s->failed_pc=0x0c0b97cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b988au,2);
goto P_0c0b97cc;
P_0c0b97cc: /* original 4e0b, guest PC 0x0c0b97cc */
if(!s->budget--) { s->failed_pc=0x0c0b97ccu; return 0; }
target=r[14];
r[16]=0x0c0b97d0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97d0u) { target=s->pc; goto dispatch; }
goto P_0c0b97d0;
P_0c0b97ce: /* original 0009, guest PC 0x0c0b97ce */
if(!s->budget--) { s->failed_pc=0x0c0b97ceu; return 0; }
goto P_0c0b97d0;
P_0c0b97d0: /* original 945c, guest PC 0x0c0b97d0 */
if(!s->budget--) { s->failed_pc=0x0c0b97d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b988cu,2);
goto P_0c0b97d2;
P_0c0b97d2: /* original 4e0b, guest PC 0x0c0b97d2 */
if(!s->budget--) { s->failed_pc=0x0c0b97d2u; return 0; }
target=r[14];
r[16]=0x0c0b97d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97d6u) { target=s->pc; goto dispatch; }
goto P_0c0b97d6;
P_0c0b97d4: /* original 0009, guest PC 0x0c0b97d4 */
if(!s->budget--) { s->failed_pc=0x0c0b97d4u; return 0; }
goto P_0c0b97d6;
P_0c0b97d6: /* original 945a, guest PC 0x0c0b97d6 */
if(!s->budget--) { s->failed_pc=0x0c0b97d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b988eu,2);
goto P_0c0b97d8;
P_0c0b97d8: /* original 4e0b, guest PC 0x0c0b97d8 */
if(!s->budget--) { s->failed_pc=0x0c0b97d8u; return 0; }
target=r[14];
r[16]=0x0c0b97dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97dcu) { target=s->pc; goto dispatch; }
goto P_0c0b97dc;
P_0c0b97da: /* original 0009, guest PC 0x0c0b97da */
if(!s->budget--) { s->failed_pc=0x0c0b97dau; return 0; }
goto P_0c0b97dc;
P_0c0b97dc: /* original 9458, guest PC 0x0c0b97dc */
if(!s->budget--) { s->failed_pc=0x0c0b97dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9890u,2);
goto P_0c0b97de;
P_0c0b97de: /* original 4e0b, guest PC 0x0c0b97de */
if(!s->budget--) { s->failed_pc=0x0c0b97deu; return 0; }
target=r[14];
r[16]=0x0c0b97e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97e2u) { target=s->pc; goto dispatch; }
goto P_0c0b97e2;
P_0c0b97e0: /* original 0009, guest PC 0x0c0b97e0 */
if(!s->budget--) { s->failed_pc=0x0c0b97e0u; return 0; }
goto P_0c0b97e2;
P_0c0b97e2: /* original 9456, guest PC 0x0c0b97e2 */
if(!s->budget--) { s->failed_pc=0x0c0b97e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9892u,2);
goto P_0c0b97e4;
P_0c0b97e4: /* original 4e0b, guest PC 0x0c0b97e4 */
if(!s->budget--) { s->failed_pc=0x0c0b97e4u; return 0; }
target=r[14];
r[16]=0x0c0b97e8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97e8u) { target=s->pc; goto dispatch; }
goto P_0c0b97e8;
P_0c0b97e6: /* original 0009, guest PC 0x0c0b97e6 */
if(!s->budget--) { s->failed_pc=0x0c0b97e6u; return 0; }
goto P_0c0b97e8;
P_0c0b97e8: /* original 9454, guest PC 0x0c0b97e8 */
if(!s->budget--) { s->failed_pc=0x0c0b97e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9894u,2);
goto P_0c0b97ea;
P_0c0b97ea: /* original 4e0b, guest PC 0x0c0b97ea */
if(!s->budget--) { s->failed_pc=0x0c0b97eau; return 0; }
target=r[14];
r[16]=0x0c0b97eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97eeu) { target=s->pc; goto dispatch; }
goto P_0c0b97ee;
P_0c0b97ec: /* original 0009, guest PC 0x0c0b97ec */
if(!s->budget--) { s->failed_pc=0x0c0b97ecu; return 0; }
goto P_0c0b97ee;
P_0c0b97ee: /* original 9452, guest PC 0x0c0b97ee */
if(!s->budget--) { s->failed_pc=0x0c0b97eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9896u,2);
goto P_0c0b97f0;
P_0c0b97f0: /* original 4e0b, guest PC 0x0c0b97f0 */
if(!s->budget--) { s->failed_pc=0x0c0b97f0u; return 0; }
target=r[14];
r[16]=0x0c0b97f4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97f4u) { target=s->pc; goto dispatch; }
goto P_0c0b97f4;
P_0c0b97f2: /* original 0009, guest PC 0x0c0b97f2 */
if(!s->budget--) { s->failed_pc=0x0c0b97f2u; return 0; }
goto P_0c0b97f4;
P_0c0b97f4: /* original 9450, guest PC 0x0c0b97f4 */
if(!s->budget--) { s->failed_pc=0x0c0b97f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9898u,2);
goto P_0c0b97f6;
P_0c0b97f6: /* original 4e0b, guest PC 0x0c0b97f6 */
if(!s->budget--) { s->failed_pc=0x0c0b97f6u; return 0; }
target=r[14];
r[16]=0x0c0b97fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b97fau) { target=s->pc; goto dispatch; }
goto P_0c0b97fa;
P_0c0b97f8: /* original 0009, guest PC 0x0c0b97f8 */
if(!s->budget--) { s->failed_pc=0x0c0b97f8u; return 0; }
goto P_0c0b97fa;
P_0c0b97fa: /* original 944e, guest PC 0x0c0b97fa */
if(!s->budget--) { s->failed_pc=0x0c0b97fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b989au,2);
goto P_0c0b97fc;
P_0c0b97fc: /* original 4e0b, guest PC 0x0c0b97fc */
if(!s->budget--) { s->failed_pc=0x0c0b97fcu; return 0; }
target=r[14];
r[16]=0x0c0b9800u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9800u) { target=s->pc; goto dispatch; }
goto P_0c0b9800;
P_0c0b97fe: /* original 0009, guest PC 0x0c0b97fe */
if(!s->budget--) { s->failed_pc=0x0c0b97feu; return 0; }
goto P_0c0b9800;
P_0c0b9800: /* original 944c, guest PC 0x0c0b9800 */
if(!s->budget--) { s->failed_pc=0x0c0b9800u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b989cu,2);
goto P_0c0b9802;
P_0c0b9802: /* original 4e0b, guest PC 0x0c0b9802 */
if(!s->budget--) { s->failed_pc=0x0c0b9802u; return 0; }
target=r[14];
r[16]=0x0c0b9806u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9806u) { target=s->pc; goto dispatch; }
goto P_0c0b9806;
P_0c0b9804: /* original 0009, guest PC 0x0c0b9804 */
if(!s->budget--) { s->failed_pc=0x0c0b9804u; return 0; }
goto P_0c0b9806;
P_0c0b9806: /* original 944a, guest PC 0x0c0b9806 */
if(!s->budget--) { s->failed_pc=0x0c0b9806u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b989eu,2);
goto P_0c0b9808;
P_0c0b9808: /* original 4e0b, guest PC 0x0c0b9808 */
if(!s->budget--) { s->failed_pc=0x0c0b9808u; return 0; }
target=r[14];
r[16]=0x0c0b980cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b980cu) { target=s->pc; goto dispatch; }
goto P_0c0b980c;
P_0c0b980a: /* original 0009, guest PC 0x0c0b980a */
if(!s->budget--) { s->failed_pc=0x0c0b980au; return 0; }
goto P_0c0b980c;
P_0c0b980c: /* original 9448, guest PC 0x0c0b980c */
if(!s->budget--) { s->failed_pc=0x0c0b980cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98a0u,2);
goto P_0c0b980e;
P_0c0b980e: /* original 4e0b, guest PC 0x0c0b980e */
if(!s->budget--) { s->failed_pc=0x0c0b980eu; return 0; }
target=r[14];
r[16]=0x0c0b9812u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9812u) { target=s->pc; goto dispatch; }
goto P_0c0b9812;
P_0c0b9810: /* original 0009, guest PC 0x0c0b9810 */
if(!s->budget--) { s->failed_pc=0x0c0b9810u; return 0; }
goto P_0c0b9812;
P_0c0b9812: /* original 9446, guest PC 0x0c0b9812 */
if(!s->budget--) { s->failed_pc=0x0c0b9812u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98a2u,2);
goto P_0c0b9814;
P_0c0b9814: /* original 4e0b, guest PC 0x0c0b9814 */
if(!s->budget--) { s->failed_pc=0x0c0b9814u; return 0; }
target=r[14];
r[16]=0x0c0b9818u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9818u) { target=s->pc; goto dispatch; }
goto P_0c0b9818;
P_0c0b9816: /* original 0009, guest PC 0x0c0b9816 */
if(!s->budget--) { s->failed_pc=0x0c0b9816u; return 0; }
goto P_0c0b9818;
P_0c0b9818: /* original 9444, guest PC 0x0c0b9818 */
if(!s->budget--) { s->failed_pc=0x0c0b9818u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98a4u,2);
goto P_0c0b981a;
P_0c0b981a: /* original 4e0b, guest PC 0x0c0b981a */
if(!s->budget--) { s->failed_pc=0x0c0b981au; return 0; }
target=r[14];
r[16]=0x0c0b981eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b981eu) { target=s->pc; goto dispatch; }
goto P_0c0b981e;
P_0c0b981c: /* original 0009, guest PC 0x0c0b981c */
if(!s->budget--) { s->failed_pc=0x0c0b981cu; return 0; }
goto P_0c0b981e;
P_0c0b981e: /* original 9442, guest PC 0x0c0b981e */
if(!s->budget--) { s->failed_pc=0x0c0b981eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98a6u,2);
goto P_0c0b9820;
P_0c0b9820: /* original 4e0b, guest PC 0x0c0b9820 */
if(!s->budget--) { s->failed_pc=0x0c0b9820u; return 0; }
target=r[14];
r[16]=0x0c0b9824u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9824u) { target=s->pc; goto dispatch; }
goto P_0c0b9824;
P_0c0b9822: /* original 0009, guest PC 0x0c0b9822 */
if(!s->budget--) { s->failed_pc=0x0c0b9822u; return 0; }
goto P_0c0b9824;
P_0c0b9824: /* original 9440, guest PC 0x0c0b9824 */
if(!s->budget--) { s->failed_pc=0x0c0b9824u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98a8u,2);
goto P_0c0b9826;
P_0c0b9826: /* original 4e0b, guest PC 0x0c0b9826 */
if(!s->budget--) { s->failed_pc=0x0c0b9826u; return 0; }
target=r[14];
r[16]=0x0c0b982au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b982au) { target=s->pc; goto dispatch; }
goto P_0c0b982a;
P_0c0b9828: /* original 0009, guest PC 0x0c0b9828 */
if(!s->budget--) { s->failed_pc=0x0c0b9828u; return 0; }
goto P_0c0b982a;
P_0c0b982a: /* original 943e, guest PC 0x0c0b982a */
if(!s->budget--) { s->failed_pc=0x0c0b982au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98aau,2);
goto P_0c0b982c;
P_0c0b982c: /* original 4e0b, guest PC 0x0c0b982c */
if(!s->budget--) { s->failed_pc=0x0c0b982cu; return 0; }
target=r[14];
r[16]=0x0c0b9830u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9830u) { target=s->pc; goto dispatch; }
goto P_0c0b9830;
P_0c0b982e: /* original 0009, guest PC 0x0c0b982e */
if(!s->budget--) { s->failed_pc=0x0c0b982eu; return 0; }
goto P_0c0b9830;
P_0c0b9830: /* original 943c, guest PC 0x0c0b9830 */
if(!s->budget--) { s->failed_pc=0x0c0b9830u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98acu,2);
goto P_0c0b9832;
P_0c0b9832: /* original 4e0b, guest PC 0x0c0b9832 */
if(!s->budget--) { s->failed_pc=0x0c0b9832u; return 0; }
target=r[14];
r[16]=0x0c0b9836u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9836u) { target=s->pc; goto dispatch; }
goto P_0c0b9836;
P_0c0b9834: /* original 0009, guest PC 0x0c0b9834 */
if(!s->budget--) { s->failed_pc=0x0c0b9834u; return 0; }
goto P_0c0b9836;
P_0c0b9836: /* original 943a, guest PC 0x0c0b9836 */
if(!s->budget--) { s->failed_pc=0x0c0b9836u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98aeu,2);
goto P_0c0b9838;
P_0c0b9838: /* original 4e0b, guest PC 0x0c0b9838 */
if(!s->budget--) { s->failed_pc=0x0c0b9838u; return 0; }
target=r[14];
r[16]=0x0c0b983cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b983cu) { target=s->pc; goto dispatch; }
goto P_0c0b983c;
P_0c0b983a: /* original 0009, guest PC 0x0c0b983a */
if(!s->budget--) { s->failed_pc=0x0c0b983au; return 0; }
goto P_0c0b983c;
P_0c0b983c: /* original 9438, guest PC 0x0c0b983c */
if(!s->budget--) { s->failed_pc=0x0c0b983cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b98b0u,2);
goto P_0c0b983e;
P_0c0b983e: /* original 4e0b, guest PC 0x0c0b983e */
if(!s->budget--) { s->failed_pc=0x0c0b983eu; return 0; }
target=r[14];
r[16]=0x0c0b9842u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b9842u) { target=s->pc; goto dispatch; }
goto P_0c0b9842;
P_0c0b9840: /* original 0009, guest PC 0x0c0b9840 */
if(!s->budget--) { s->failed_pc=0x0c0b9840u; return 0; }
goto P_0c0b9842;
P_0c0b9842: /* original 4f26, guest PC 0x0c0b9842 */
if(!s->budget--) { s->failed_pc=0x0c0b9842u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b9844;
P_0c0b9844: /* original 000b, guest PC 0x0c0b9844 */
if(!s->budget--) { s->failed_pc=0x0c0b9844u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b9846: /* original 6ef6, guest PC 0x0c0b9846 */
if(!s->budget--) { s->failed_pc=0x0c0b9846u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0b9848u,s,ram);
P_0c0bbde2: /* original 4f22, guest PC 0x0c0bbde2 */
if(!s->budget--) { s->failed_pc=0x0c0bbde2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bbde4;
P_0c0bbde4: /* original 5d44, guest PC 0x0c0bbde4 */
if(!s->budget--) { s->failed_pc=0x0c0bbde4u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0bbde6;
P_0c0bbde6: /* original 94a8, guest PC 0x0c0bbde6 */
if(!s->budget--) { s->failed_pc=0x0c0bbde6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf3au,2);
goto P_0c0bbde8;
P_0c0bbde8: /* original de6e, guest PC 0x0c0bbde8 */
if(!s->budget--) { s->failed_pc=0x0c0bbde8u; return 0; }
r[14]=read(ram,0x0c0bbfa4u,4);
goto P_0c0bbdea;
P_0c0bbdea: /* original 7ff8, guest PC 0x0c0bbdea */
if(!s->budget--) { s->failed_pc=0x0c0bbdeau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0bbdec;
P_0c0bbdec: /* original 4e0b, guest PC 0x0c0bbdec */
if(!s->budget--) { s->failed_pc=0x0c0bbdecu; return 0; }
target=r[14];
r[16]=0x0c0bbdf0u;
tmp=read(ram,r[13],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbdf0u) { target=s->pc; goto dispatch; }
goto P_0c0bbdf0;
P_0c0bbdee: /* original 65d2, guest PC 0x0c0bbdee */
if(!s->budget--) { s->failed_pc=0x0c0bbdeeu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0bbdf0;
P_0c0bbdf0: /* original 94a4, guest PC 0x0c0bbdf0 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf3cu,2);
goto P_0c0bbdf2;
P_0c0bbdf2: /* original 4e0b, guest PC 0x0c0bbdf2 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf2u; return 0; }
target=r[14];
r[16]=0x0c0bbdf6u;
r[5]=read(ram,r[13]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbdf6u) { target=s->pc; goto dispatch; }
goto P_0c0bbdf6;
P_0c0bbdf4: /* original 55d1, guest PC 0x0c0bbdf4 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf4u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0bbdf6;
P_0c0bbdf6: /* original 94a2, guest PC 0x0c0bbdf6 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf3eu,2);
goto P_0c0bbdf8;
P_0c0bbdf8: /* original 4e0b, guest PC 0x0c0bbdf8 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf8u; return 0; }
target=r[14];
r[16]=0x0c0bbdfcu;
r[5]=read(ram,r[13]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbdfcu) { target=s->pc; goto dispatch; }
goto P_0c0bbdfc;
P_0c0bbdfa: /* original 55d2, guest PC 0x0c0bbdfa */
if(!s->budget--) { s->failed_pc=0x0c0bbdfau; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0bbdfc;
P_0c0bbdfc: /* original 94a0, guest PC 0x0c0bbdfc */
if(!s->budget--) { s->failed_pc=0x0c0bbdfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf40u,2);
goto P_0c0bbdfe;
P_0c0bbdfe: /* original 4e0b, guest PC 0x0c0bbdfe */
if(!s->budget--) { s->failed_pc=0x0c0bbdfeu; return 0; }
target=r[14];
r[16]=0x0c0bbe02u;
r[5]=read(ram,r[13]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe02u) { target=s->pc; goto dispatch; }
goto P_0c0bbe02;
P_0c0bbe00: /* original 55d3, guest PC 0x0c0bbe00 */
if(!s->budget--) { s->failed_pc=0x0c0bbe00u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0bbe02;
P_0c0bbe02: /* original 949e, guest PC 0x0c0bbe02 */
if(!s->budget--) { s->failed_pc=0x0c0bbe02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf42u,2);
goto P_0c0bbe04;
P_0c0bbe04: /* original 4e0b, guest PC 0x0c0bbe04 */
if(!s->budget--) { s->failed_pc=0x0c0bbe04u; return 0; }
target=r[14];
r[16]=0x0c0bbe08u;
r[5]=read(ram,r[13]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe08u) { target=s->pc; goto dispatch; }
goto P_0c0bbe08;
P_0c0bbe06: /* original 55d4, guest PC 0x0c0bbe06 */
if(!s->budget--) { s->failed_pc=0x0c0bbe06u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0bbe08;
P_0c0bbe08: /* original 949c, guest PC 0x0c0bbe08 */
if(!s->budget--) { s->failed_pc=0x0c0bbe08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf44u,2);
goto P_0c0bbe0a;
P_0c0bbe0a: /* original 4e0b, guest PC 0x0c0bbe0a */
if(!s->budget--) { s->failed_pc=0x0c0bbe0au; return 0; }
target=r[14];
r[16]=0x0c0bbe0eu;
r[5]=read(ram,r[13]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe0eu) { target=s->pc; goto dispatch; }
goto P_0c0bbe0e;
P_0c0bbe0c: /* original 55d5, guest PC 0x0c0bbe0c */
if(!s->budget--) { s->failed_pc=0x0c0bbe0cu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0bbe0e;
P_0c0bbe0e: /* original 949a, guest PC 0x0c0bbe0e */
if(!s->budget--) { s->failed_pc=0x0c0bbe0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf46u,2);
goto P_0c0bbe10;
P_0c0bbe10: /* original 4e0b, guest PC 0x0c0bbe10 */
if(!s->budget--) { s->failed_pc=0x0c0bbe10u; return 0; }
target=r[14];
r[16]=0x0c0bbe14u;
r[5]=read(ram,r[13]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe14u) { target=s->pc; goto dispatch; }
goto P_0c0bbe14;
P_0c0bbe12: /* original 55d6, guest PC 0x0c0bbe12 */
if(!s->budget--) { s->failed_pc=0x0c0bbe12u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0bbe14;
P_0c0bbe14: /* original 9498, guest PC 0x0c0bbe14 */
if(!s->budget--) { s->failed_pc=0x0c0bbe14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf48u,2);
goto P_0c0bbe16;
P_0c0bbe16: /* original 4e0b, guest PC 0x0c0bbe16 */
if(!s->budget--) { s->failed_pc=0x0c0bbe16u; return 0; }
target=r[14];
r[16]=0x0c0bbe1au;
r[5]=read(ram,r[13]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe1au) { target=s->pc; goto dispatch; }
goto P_0c0bbe1a;
P_0c0bbe18: /* original 55d7, guest PC 0x0c0bbe18 */
if(!s->budget--) { s->failed_pc=0x0c0bbe18u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0bbe1a;
P_0c0bbe1a: /* original 9496, guest PC 0x0c0bbe1a */
if(!s->budget--) { s->failed_pc=0x0c0bbe1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf4au,2);
goto P_0c0bbe1c;
P_0c0bbe1c: /* original 4e0b, guest PC 0x0c0bbe1c */
if(!s->budget--) { s->failed_pc=0x0c0bbe1cu; return 0; }
target=r[14];
r[16]=0x0c0bbe20u;
r[5]=read(ram,r[13]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe20u) { target=s->pc; goto dispatch; }
goto P_0c0bbe20;
P_0c0bbe1e: /* original 55d8, guest PC 0x0c0bbe1e */
if(!s->budget--) { s->failed_pc=0x0c0bbe1eu; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0bbe20;
P_0c0bbe20: /* original 9494, guest PC 0x0c0bbe20 */
if(!s->budget--) { s->failed_pc=0x0c0bbe20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf4cu,2);
goto P_0c0bbe22;
P_0c0bbe22: /* original 4e0b, guest PC 0x0c0bbe22 */
if(!s->budget--) { s->failed_pc=0x0c0bbe22u; return 0; }
target=r[14];
r[16]=0x0c0bbe26u;
r[5]=read(ram,r[13]+36,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe26u) { target=s->pc; goto dispatch; }
goto P_0c0bbe26;
P_0c0bbe24: /* original 55d9, guest PC 0x0c0bbe24 */
if(!s->budget--) { s->failed_pc=0x0c0bbe24u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0bbe26;
P_0c0bbe26: /* original 9492, guest PC 0x0c0bbe26 */
if(!s->budget--) { s->failed_pc=0x0c0bbe26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf4eu,2);
goto P_0c0bbe28;
P_0c0bbe28: /* original 4e0b, guest PC 0x0c0bbe28 */
if(!s->budget--) { s->failed_pc=0x0c0bbe28u; return 0; }
target=r[14];
r[16]=0x0c0bbe2cu;
r[5]=read(ram,r[13]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe2cu) { target=s->pc; goto dispatch; }
goto P_0c0bbe2c;
P_0c0bbe2a: /* original 55da, guest PC 0x0c0bbe2a */
if(!s->budget--) { s->failed_pc=0x0c0bbe2au; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0bbe2c;
P_0c0bbe2c: /* original 9490, guest PC 0x0c0bbe2c */
if(!s->budget--) { s->failed_pc=0x0c0bbe2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf50u,2);
goto P_0c0bbe2e;
P_0c0bbe2e: /* original 4e0b, guest PC 0x0c0bbe2e */
if(!s->budget--) { s->failed_pc=0x0c0bbe2eu; return 0; }
target=r[14];
r[16]=0x0c0bbe32u;
r[5]=read(ram,r[13]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe32u) { target=s->pc; goto dispatch; }
goto P_0c0bbe32;
P_0c0bbe30: /* original 55db, guest PC 0x0c0bbe30 */
if(!s->budget--) { s->failed_pc=0x0c0bbe30u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0bbe32;
P_0c0bbe32: /* original 948e, guest PC 0x0c0bbe32 */
if(!s->budget--) { s->failed_pc=0x0c0bbe32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf52u,2);
goto P_0c0bbe34;
P_0c0bbe34: /* original 4e0b, guest PC 0x0c0bbe34 */
if(!s->budget--) { s->failed_pc=0x0c0bbe34u; return 0; }
target=r[14];
r[16]=0x0c0bbe38u;
r[5]=read(ram,r[13]+48,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe38u) { target=s->pc; goto dispatch; }
goto P_0c0bbe38;
P_0c0bbe36: /* original 55dc, guest PC 0x0c0bbe36 */
if(!s->budget--) { s->failed_pc=0x0c0bbe36u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0bbe38;
P_0c0bbe38: /* original 948c, guest PC 0x0c0bbe38 */
if(!s->budget--) { s->failed_pc=0x0c0bbe38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf54u,2);
goto P_0c0bbe3a;
P_0c0bbe3a: /* original 4e0b, guest PC 0x0c0bbe3a */
if(!s->budget--) { s->failed_pc=0x0c0bbe3au; return 0; }
target=r[14];
r[16]=0x0c0bbe3eu;
r[5]=read(ram,r[13]+52,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe3eu) { target=s->pc; goto dispatch; }
goto P_0c0bbe3e;
P_0c0bbe3c: /* original 55dd, guest PC 0x0c0bbe3c */
if(!s->budget--) { s->failed_pc=0x0c0bbe3cu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0bbe3e;
P_0c0bbe3e: /* original 948a, guest PC 0x0c0bbe3e */
if(!s->budget--) { s->failed_pc=0x0c0bbe3eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf56u,2);
goto P_0c0bbe40;
P_0c0bbe40: /* original 4e0b, guest PC 0x0c0bbe40 */
if(!s->budget--) { s->failed_pc=0x0c0bbe40u; return 0; }
target=r[14];
r[16]=0x0c0bbe44u;
r[5]=read(ram,r[13]+56,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe44u) { target=s->pc; goto dispatch; }
goto P_0c0bbe44;
P_0c0bbe42: /* original 55de, guest PC 0x0c0bbe42 */
if(!s->budget--) { s->failed_pc=0x0c0bbe42u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0bbe44;
P_0c0bbe44: /* original 9488, guest PC 0x0c0bbe44 */
if(!s->budget--) { s->failed_pc=0x0c0bbe44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf58u,2);
goto P_0c0bbe46;
P_0c0bbe46: /* original 4e0b, guest PC 0x0c0bbe46 */
if(!s->budget--) { s->failed_pc=0x0c0bbe46u; return 0; }
target=r[14];
r[16]=0x0c0bbe4au;
r[5]=read(ram,r[13]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe4au) { target=s->pc; goto dispatch; }
goto P_0c0bbe4a;
P_0c0bbe48: /* original 55df, guest PC 0x0c0bbe48 */
if(!s->budget--) { s->failed_pc=0x0c0bbe48u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0bbe4a;
P_0c0bbe4a: /* original 9486, guest PC 0x0c0bbe4a */
if(!s->budget--) { s->failed_pc=0x0c0bbe4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf5au,2);
goto P_0c0bbe4c;
P_0c0bbe4c: /* original e040, guest PC 0x0c0bbe4c */
if(!s->budget--) { s->failed_pc=0x0c0bbe4cu; return 0; }
r[0]=0x00000040u;
goto P_0c0bbe4e;
P_0c0bbe4e: /* original 4e0b, guest PC 0x0c0bbe4e */
if(!s->budget--) { s->failed_pc=0x0c0bbe4eu; return 0; }
target=r[14];
r[16]=0x0c0bbe52u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe52u) { target=s->pc; goto dispatch; }
goto P_0c0bbe52;
P_0c0bbe50: /* original 05de, guest PC 0x0c0bbe50 */
if(!s->budget--) { s->failed_pc=0x0c0bbe50u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe52;
P_0c0bbe52: /* original 9483, guest PC 0x0c0bbe52 */
if(!s->budget--) { s->failed_pc=0x0c0bbe52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf5cu,2);
goto P_0c0bbe54;
P_0c0bbe54: /* original e044, guest PC 0x0c0bbe54 */
if(!s->budget--) { s->failed_pc=0x0c0bbe54u; return 0; }
r[0]=0x00000044u;
goto P_0c0bbe56;
P_0c0bbe56: /* original 4e0b, guest PC 0x0c0bbe56 */
if(!s->budget--) { s->failed_pc=0x0c0bbe56u; return 0; }
target=r[14];
r[16]=0x0c0bbe5au;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe5au) { target=s->pc; goto dispatch; }
goto P_0c0bbe5a;
P_0c0bbe58: /* original 05de, guest PC 0x0c0bbe58 */
if(!s->budget--) { s->failed_pc=0x0c0bbe58u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe5a;
P_0c0bbe5a: /* original 9480, guest PC 0x0c0bbe5a */
if(!s->budget--) { s->failed_pc=0x0c0bbe5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf5eu,2);
goto P_0c0bbe5c;
P_0c0bbe5c: /* original e048, guest PC 0x0c0bbe5c */
if(!s->budget--) { s->failed_pc=0x0c0bbe5cu; return 0; }
r[0]=0x00000048u;
goto P_0c0bbe5e;
P_0c0bbe5e: /* original 4e0b, guest PC 0x0c0bbe5e */
if(!s->budget--) { s->failed_pc=0x0c0bbe5eu; return 0; }
target=r[14];
r[16]=0x0c0bbe62u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe62u) { target=s->pc; goto dispatch; }
goto P_0c0bbe62;
P_0c0bbe60: /* original 05de, guest PC 0x0c0bbe60 */
if(!s->budget--) { s->failed_pc=0x0c0bbe60u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe62;
P_0c0bbe62: /* original 947d, guest PC 0x0c0bbe62 */
if(!s->budget--) { s->failed_pc=0x0c0bbe62u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf60u,2);
goto P_0c0bbe64;
P_0c0bbe64: /* original e04c, guest PC 0x0c0bbe64 */
if(!s->budget--) { s->failed_pc=0x0c0bbe64u; return 0; }
r[0]=0x0000004cu;
goto P_0c0bbe66;
P_0c0bbe66: /* original 4e0b, guest PC 0x0c0bbe66 */
if(!s->budget--) { s->failed_pc=0x0c0bbe66u; return 0; }
target=r[14];
r[16]=0x0c0bbe6au;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe6au) { target=s->pc; goto dispatch; }
goto P_0c0bbe6a;
P_0c0bbe68: /* original 05de, guest PC 0x0c0bbe68 */
if(!s->budget--) { s->failed_pc=0x0c0bbe68u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe6a;
P_0c0bbe6a: /* original 947a, guest PC 0x0c0bbe6a */
if(!s->budget--) { s->failed_pc=0x0c0bbe6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf62u,2);
goto P_0c0bbe6c;
P_0c0bbe6c: /* original e050, guest PC 0x0c0bbe6c */
if(!s->budget--) { s->failed_pc=0x0c0bbe6cu; return 0; }
r[0]=0x00000050u;
goto P_0c0bbe6e;
P_0c0bbe6e: /* original 4e0b, guest PC 0x0c0bbe6e */
if(!s->budget--) { s->failed_pc=0x0c0bbe6eu; return 0; }
target=r[14];
r[16]=0x0c0bbe72u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe72u) { target=s->pc; goto dispatch; }
goto P_0c0bbe72;
P_0c0bbe70: /* original 05de, guest PC 0x0c0bbe70 */
if(!s->budget--) { s->failed_pc=0x0c0bbe70u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe72;
P_0c0bbe72: /* original 9477, guest PC 0x0c0bbe72 */
if(!s->budget--) { s->failed_pc=0x0c0bbe72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf64u,2);
goto P_0c0bbe74;
P_0c0bbe74: /* original e054, guest PC 0x0c0bbe74 */
if(!s->budget--) { s->failed_pc=0x0c0bbe74u; return 0; }
r[0]=0x00000054u;
goto P_0c0bbe76;
P_0c0bbe76: /* original 4e0b, guest PC 0x0c0bbe76 */
if(!s->budget--) { s->failed_pc=0x0c0bbe76u; return 0; }
target=r[14];
r[16]=0x0c0bbe7au;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe7au) { target=s->pc; goto dispatch; }
goto P_0c0bbe7a;
P_0c0bbe78: /* original 05de, guest PC 0x0c0bbe78 */
if(!s->budget--) { s->failed_pc=0x0c0bbe78u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe7a;
P_0c0bbe7a: /* original 9474, guest PC 0x0c0bbe7a */
if(!s->budget--) { s->failed_pc=0x0c0bbe7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf66u,2);
goto P_0c0bbe7c;
P_0c0bbe7c: /* original e058, guest PC 0x0c0bbe7c */
if(!s->budget--) { s->failed_pc=0x0c0bbe7cu; return 0; }
r[0]=0x00000058u;
goto P_0c0bbe7e;
P_0c0bbe7e: /* original 4e0b, guest PC 0x0c0bbe7e */
if(!s->budget--) { s->failed_pc=0x0c0bbe7eu; return 0; }
target=r[14];
r[16]=0x0c0bbe82u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe82u) { target=s->pc; goto dispatch; }
goto P_0c0bbe82;
P_0c0bbe80: /* original 05de, guest PC 0x0c0bbe80 */
if(!s->budget--) { s->failed_pc=0x0c0bbe80u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe82;
P_0c0bbe82: /* original 9471, guest PC 0x0c0bbe82 */
if(!s->budget--) { s->failed_pc=0x0c0bbe82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf68u,2);
goto P_0c0bbe84;
P_0c0bbe84: /* original e05c, guest PC 0x0c0bbe84 */
if(!s->budget--) { s->failed_pc=0x0c0bbe84u; return 0; }
r[0]=0x0000005cu;
goto P_0c0bbe86;
P_0c0bbe86: /* original 4e0b, guest PC 0x0c0bbe86 */
if(!s->budget--) { s->failed_pc=0x0c0bbe86u; return 0; }
target=r[14];
r[16]=0x0c0bbe8au;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe8au) { target=s->pc; goto dispatch; }
goto P_0c0bbe8a;
P_0c0bbe88: /* original 05de, guest PC 0x0c0bbe88 */
if(!s->budget--) { s->failed_pc=0x0c0bbe88u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe8a;
P_0c0bbe8a: /* original 946e, guest PC 0x0c0bbe8a */
if(!s->budget--) { s->failed_pc=0x0c0bbe8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf6au,2);
goto P_0c0bbe8c;
P_0c0bbe8c: /* original e060, guest PC 0x0c0bbe8c */
if(!s->budget--) { s->failed_pc=0x0c0bbe8cu; return 0; }
r[0]=0x00000060u;
goto P_0c0bbe8e;
P_0c0bbe8e: /* original 4e0b, guest PC 0x0c0bbe8e */
if(!s->budget--) { s->failed_pc=0x0c0bbe8eu; return 0; }
target=r[14];
r[16]=0x0c0bbe92u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe92u) { target=s->pc; goto dispatch; }
goto P_0c0bbe92;
P_0c0bbe90: /* original 05de, guest PC 0x0c0bbe90 */
if(!s->budget--) { s->failed_pc=0x0c0bbe90u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe92;
P_0c0bbe92: /* original 946b, guest PC 0x0c0bbe92 */
if(!s->budget--) { s->failed_pc=0x0c0bbe92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf6cu,2);
goto P_0c0bbe94;
P_0c0bbe94: /* original e064, guest PC 0x0c0bbe94 */
if(!s->budget--) { s->failed_pc=0x0c0bbe94u; return 0; }
r[0]=0x00000064u;
goto P_0c0bbe96;
P_0c0bbe96: /* original 4e0b, guest PC 0x0c0bbe96 */
if(!s->budget--) { s->failed_pc=0x0c0bbe96u; return 0; }
target=r[14];
r[16]=0x0c0bbe9au;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbe9au) { target=s->pc; goto dispatch; }
goto P_0c0bbe9a;
P_0c0bbe98: /* original 05de, guest PC 0x0c0bbe98 */
if(!s->budget--) { s->failed_pc=0x0c0bbe98u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe9a;
P_0c0bbe9a: /* original 9468, guest PC 0x0c0bbe9a */
if(!s->budget--) { s->failed_pc=0x0c0bbe9au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf6eu,2);
goto P_0c0bbe9c;
P_0c0bbe9c: /* original e068, guest PC 0x0c0bbe9c */
if(!s->budget--) { s->failed_pc=0x0c0bbe9cu; return 0; }
r[0]=0x00000068u;
goto P_0c0bbe9e;
P_0c0bbe9e: /* original 4e0b, guest PC 0x0c0bbe9e */
if(!s->budget--) { s->failed_pc=0x0c0bbe9eu; return 0; }
target=r[14];
r[16]=0x0c0bbea2u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbea2u) { target=s->pc; goto dispatch; }
goto P_0c0bbea2;
P_0c0bbea0: /* original 05de, guest PC 0x0c0bbea0 */
if(!s->budget--) { s->failed_pc=0x0c0bbea0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbea2;
P_0c0bbea2: /* original 9465, guest PC 0x0c0bbea2 */
if(!s->budget--) { s->failed_pc=0x0c0bbea2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf70u,2);
goto P_0c0bbea4;
P_0c0bbea4: /* original e06c, guest PC 0x0c0bbea4 */
if(!s->budget--) { s->failed_pc=0x0c0bbea4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0bbea6;
P_0c0bbea6: /* original 4e0b, guest PC 0x0c0bbea6 */
if(!s->budget--) { s->failed_pc=0x0c0bbea6u; return 0; }
target=r[14];
r[16]=0x0c0bbeaau;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbeaau) { target=s->pc; goto dispatch; }
goto P_0c0bbeaa;
P_0c0bbea8: /* original 05de, guest PC 0x0c0bbea8 */
if(!s->budget--) { s->failed_pc=0x0c0bbea8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbeaa;
P_0c0bbeaa: /* original 9462, guest PC 0x0c0bbeaa */
if(!s->budget--) { s->failed_pc=0x0c0bbeaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf72u,2);
goto P_0c0bbeac;
P_0c0bbeac: /* original e070, guest PC 0x0c0bbeac */
if(!s->budget--) { s->failed_pc=0x0c0bbeacu; return 0; }
r[0]=0x00000070u;
goto P_0c0bbeae;
P_0c0bbeae: /* original 4e0b, guest PC 0x0c0bbeae */
if(!s->budget--) { s->failed_pc=0x0c0bbeaeu; return 0; }
target=r[14];
r[16]=0x0c0bbeb2u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbeb2u) { target=s->pc; goto dispatch; }
goto P_0c0bbeb2;
P_0c0bbeb0: /* original 05de, guest PC 0x0c0bbeb0 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbeb2;
P_0c0bbeb2: /* original 945f, guest PC 0x0c0bbeb2 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf74u,2);
goto P_0c0bbeb4;
P_0c0bbeb4: /* original e074, guest PC 0x0c0bbeb4 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb4u; return 0; }
r[0]=0x00000074u;
goto P_0c0bbeb6;
P_0c0bbeb6: /* original 4e0b, guest PC 0x0c0bbeb6 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb6u; return 0; }
target=r[14];
r[16]=0x0c0bbebau;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbebau) { target=s->pc; goto dispatch; }
goto P_0c0bbeba;
P_0c0bbeb8: /* original 05de, guest PC 0x0c0bbeb8 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbeba;
P_0c0bbeba: /* original 945c, guest PC 0x0c0bbeba */
if(!s->budget--) { s->failed_pc=0x0c0bbebau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf76u,2);
goto P_0c0bbebc;
P_0c0bbebc: /* original e078, guest PC 0x0c0bbebc */
if(!s->budget--) { s->failed_pc=0x0c0bbebcu; return 0; }
r[0]=0x00000078u;
goto P_0c0bbebe;
P_0c0bbebe: /* original 4e0b, guest PC 0x0c0bbebe */
if(!s->budget--) { s->failed_pc=0x0c0bbebeu; return 0; }
target=r[14];
r[16]=0x0c0bbec2u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbec2u) { target=s->pc; goto dispatch; }
goto P_0c0bbec2;
P_0c0bbec0: /* original 05de, guest PC 0x0c0bbec0 */
if(!s->budget--) { s->failed_pc=0x0c0bbec0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbec2;
P_0c0bbec2: /* original 9459, guest PC 0x0c0bbec2 */
if(!s->budget--) { s->failed_pc=0x0c0bbec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf78u,2);
goto P_0c0bbec4;
P_0c0bbec4: /* original e07c, guest PC 0x0c0bbec4 */
if(!s->budget--) { s->failed_pc=0x0c0bbec4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0bbec6;
P_0c0bbec6: /* original 4e0b, guest PC 0x0c0bbec6 */
if(!s->budget--) { s->failed_pc=0x0c0bbec6u; return 0; }
target=r[14];
r[16]=0x0c0bbecau;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbecau) { target=s->pc; goto dispatch; }
goto P_0c0bbeca;
P_0c0bbec8: /* original 05de, guest PC 0x0c0bbec8 */
if(!s->budget--) { s->failed_pc=0x0c0bbec8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbeca;
P_0c0bbeca: /* original 9457, guest PC 0x0c0bbeca */
if(!s->budget--) { s->failed_pc=0x0c0bbecau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf7cu,2);
goto P_0c0bbecc;
P_0c0bbecc: /* original 9055, guest PC 0x0c0bbecc */
if(!s->budget--) { s->failed_pc=0x0c0bbeccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf7au,2);
goto P_0c0bbece;
P_0c0bbece: /* original 4e0b, guest PC 0x0c0bbece */
if(!s->budget--) { s->failed_pc=0x0c0bbeceu; return 0; }
target=r[14];
r[16]=0x0c0bbed2u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbed2u) { target=s->pc; goto dispatch; }
goto P_0c0bbed2;
P_0c0bbed0: /* original 05de, guest PC 0x0c0bbed0 */
if(!s->budget--) { s->failed_pc=0x0c0bbed0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbed2;
P_0c0bbed2: /* original 9554, guest PC 0x0c0bbed2 */
if(!s->budget--) { s->failed_pc=0x0c0bbed2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf7eu,2);
goto P_0c0bbed4;
P_0c0bbed4: /* original 35dc, guest PC 0x0c0bbed4 */
if(!s->budget--) { s->failed_pc=0x0c0bbed4u; return 0; }
r[5]+=r[13];
goto P_0c0bbed6;
P_0c0bbed6: /* original 2f52, guest PC 0x0c0bbed6 */
if(!s->budget--) { s->failed_pc=0x0c0bbed6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bbed8;
P_0c0bbed8: /* original 9452, guest PC 0x0c0bbed8 */
if(!s->budget--) { s->failed_pc=0x0c0bbed8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf80u,2);
goto P_0c0bbeda;
P_0c0bbeda: /* original 4e0b, guest PC 0x0c0bbeda */
if(!s->budget--) { s->failed_pc=0x0c0bbedau; return 0; }
target=r[14];
r[16]=0x0c0bbedeu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbedeu) { target=s->pc; goto dispatch; }
goto P_0c0bbede;
P_0c0bbedc: /* original 6552, guest PC 0x0c0bbedc */
if(!s->budget--) { s->failed_pc=0x0c0bbedcu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bbede;
P_0c0bbede: /* original 9550, guest PC 0x0c0bbede */
if(!s->budget--) { s->failed_pc=0x0c0bbedeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf82u,2);
goto P_0c0bbee0;
P_0c0bbee0: /* original 35dc, guest PC 0x0c0bbee0 */
if(!s->budget--) { s->failed_pc=0x0c0bbee0u; return 0; }
r[5]+=r[13];
goto P_0c0bbee2;
P_0c0bbee2: /* original 1f51, guest PC 0x0c0bbee2 */
if(!s->budget--) { s->failed_pc=0x0c0bbee2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0bbee4;
P_0c0bbee4: /* original 944e, guest PC 0x0c0bbee4 */
if(!s->budget--) { s->failed_pc=0x0c0bbee4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf84u,2);
goto P_0c0bbee6;
P_0c0bbee6: /* original 4e0b, guest PC 0x0c0bbee6 */
if(!s->budget--) { s->failed_pc=0x0c0bbee6u; return 0; }
target=r[14];
r[16]=0x0c0bbeeau;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbeeau) { target=s->pc; goto dispatch; }
goto P_0c0bbeea;
P_0c0bbee8: /* original 6552, guest PC 0x0c0bbee8 */
if(!s->budget--) { s->failed_pc=0x0c0bbee8u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bbeea;
P_0c0bbeea: /* original 944d, guest PC 0x0c0bbeea */
if(!s->budget--) { s->failed_pc=0x0c0bbeeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf88u,2);
goto P_0c0bbeec;
P_0c0bbeec: /* original 904b, guest PC 0x0c0bbeec */
if(!s->budget--) { s->failed_pc=0x0c0bbeecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf86u,2);
goto P_0c0bbeee;
P_0c0bbeee: /* original 4e0b, guest PC 0x0c0bbeee */
if(!s->budget--) { s->failed_pc=0x0c0bbeeeu; return 0; }
target=r[14];
r[16]=0x0c0bbef2u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbef2u) { target=s->pc; goto dispatch; }
goto P_0c0bbef2;
P_0c0bbef0: /* original 05de, guest PC 0x0c0bbef0 */
if(!s->budget--) { s->failed_pc=0x0c0bbef0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbef2;
P_0c0bbef2: /* original 944b, guest PC 0x0c0bbef2 */
if(!s->budget--) { s->failed_pc=0x0c0bbef2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf8cu,2);
goto P_0c0bbef4;
P_0c0bbef4: /* original 9049, guest PC 0x0c0bbef4 */
if(!s->budget--) { s->failed_pc=0x0c0bbef4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf8au,2);
goto P_0c0bbef6;
P_0c0bbef6: /* original 4e0b, guest PC 0x0c0bbef6 */
if(!s->budget--) { s->failed_pc=0x0c0bbef6u; return 0; }
target=r[14];
r[16]=0x0c0bbefau;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbefau) { target=s->pc; goto dispatch; }
goto P_0c0bbefa;
P_0c0bbef8: /* original 05de, guest PC 0x0c0bbef8 */
if(!s->budget--) { s->failed_pc=0x0c0bbef8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbefa;
P_0c0bbefa: /* original 9948, guest PC 0x0c0bbefa */
if(!s->budget--) { s->failed_pc=0x0c0bbefau; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf8eu,2);
goto P_0c0bbefc;
P_0c0bbefc: /* original 9448, guest PC 0x0c0bbefc */
if(!s->budget--) { s->failed_pc=0x0c0bbefcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf90u,2);
goto P_0c0bbefe;
P_0c0bbefe: /* original 39dc, guest PC 0x0c0bbefe */
if(!s->budget--) { s->failed_pc=0x0c0bbefeu; return 0; }
r[9]+=r[13];
goto P_0c0bbf00;
P_0c0bbf00: /* original 4e0b, guest PC 0x0c0bbf00 */
if(!s->budget--) { s->failed_pc=0x0c0bbf00u; return 0; }
target=r[14];
r[16]=0x0c0bbf04u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbf04u) { target=s->pc; goto dispatch; }
goto P_0c0bbf04;
P_0c0bbf02: /* original 6592, guest PC 0x0c0bbf02 */
if(!s->budget--) { s->failed_pc=0x0c0bbf02u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbf04;
P_0c0bbf04: /* original 9445, guest PC 0x0c0bbf04 */
if(!s->budget--) { s->failed_pc=0x0c0bbf04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf92u,2);
goto P_0c0bbf06;
P_0c0bbf06: /* original 4e0b, guest PC 0x0c0bbf06 */
if(!s->budget--) { s->failed_pc=0x0c0bbf06u; return 0; }
target=r[14];
r[16]=0x0c0bbf0au;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbf0au) { target=s->pc; goto dispatch; }
goto P_0c0bbf0a;
P_0c0bbf08: /* original 6592, guest PC 0x0c0bbf08 */
if(!s->budget--) { s->failed_pc=0x0c0bbf08u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbf0a;
P_0c0bbf0a: /* original 9443, guest PC 0x0c0bbf0a */
if(!s->budget--) { s->failed_pc=0x0c0bbf0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf94u,2);
goto P_0c0bbf0c;
P_0c0bbf0c: /* original 4e0b, guest PC 0x0c0bbf0c */
if(!s->budget--) { s->failed_pc=0x0c0bbf0cu; return 0; }
target=r[14];
r[16]=0x0c0bbf10u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbf10u) { target=s->pc; goto dispatch; }
goto P_0c0bbf10;
P_0c0bbf0e: /* original 6592, guest PC 0x0c0bbf0e */
if(!s->budget--) { s->failed_pc=0x0c0bbf0eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbf10;
P_0c0bbf10: /* original 9441, guest PC 0x0c0bbf10 */
if(!s->budget--) { s->failed_pc=0x0c0bbf10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf96u,2);
goto P_0c0bbf12;
P_0c0bbf12: /* original 4e0b, guest PC 0x0c0bbf12 */
if(!s->budget--) { s->failed_pc=0x0c0bbf12u; return 0; }
target=r[14];
r[16]=0x0c0bbf16u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbf16u) { target=s->pc; goto dispatch; }
goto P_0c0bbf16;
P_0c0bbf14: /* original 6592, guest PC 0x0c0bbf14 */
if(!s->budget--) { s->failed_pc=0x0c0bbf14u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbf16;
P_0c0bbf16: /* original 9c3f, guest PC 0x0c0bbf16 */
if(!s->budget--) { s->failed_pc=0x0c0bbf16u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf98u,2);
goto P_0c0bbf18;
P_0c0bbf18: /* original 943f, guest PC 0x0c0bbf18 */
if(!s->budget--) { s->failed_pc=0x0c0bbf18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf9au,2);
goto P_0c0bbf1a;
P_0c0bbf1a: /* original 3cdc, guest PC 0x0c0bbf1a */
if(!s->budget--) { s->failed_pc=0x0c0bbf1au; return 0; }
r[12]+=r[13];
goto P_0c0bbf1c;
P_0c0bbf1c: /* original 4e0b, guest PC 0x0c0bbf1c */
if(!s->budget--) { s->failed_pc=0x0c0bbf1cu; return 0; }
target=r[14];
r[16]=0x0c0bbf20u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbf20u) { target=s->pc; goto dispatch; }
goto P_0c0bbf20;
P_0c0bbf1e: /* original 65c2, guest PC 0x0c0bbf1e */
if(!s->budget--) { s->failed_pc=0x0c0bbf1eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bbf20;
P_0c0bbf20: /* original 943c, guest PC 0x0c0bbf20 */
if(!s->budget--) { s->failed_pc=0x0c0bbf20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf9cu,2);
goto P_0c0bbf22;
P_0c0bbf22: /* original 4e0b, guest PC 0x0c0bbf22 */
if(!s->budget--) { s->failed_pc=0x0c0bbf22u; return 0; }
target=r[14];
r[16]=0x0c0bbf26u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbf26u) { target=s->pc; goto dispatch; }
goto P_0c0bbf26;
P_0c0bbf24: /* original 65c2, guest PC 0x0c0bbf24 */
if(!s->budget--) { s->failed_pc=0x0c0bbf24u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bbf26;
P_0c0bbf26: /* original 943a, guest PC 0x0c0bbf26 */
if(!s->budget--) { s->failed_pc=0x0c0bbf26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf9eu,2);
goto P_0c0bbf28;
P_0c0bbf28: /* original 4e0b, guest PC 0x0c0bbf28 */
if(!s->budget--) { s->failed_pc=0x0c0bbf28u; return 0; }
target=r[14];
r[16]=0x0c0bbf2cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbf2cu) { target=s->pc; goto dispatch; }
goto P_0c0bbf2c;
P_0c0bbf2a: /* original 65c2, guest PC 0x0c0bbf2a */
if(!s->budget--) { s->failed_pc=0x0c0bbf2au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bbf2c;
P_0c0bbf2c: /* original 9438, guest PC 0x0c0bbf2c */
if(!s->budget--) { s->failed_pc=0x0c0bbf2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbfa0u,2);
goto P_0c0bbf2e;
P_0c0bbf2e: /* original 4e0b, guest PC 0x0c0bbf2e */
if(!s->budget--) { s->failed_pc=0x0c0bbf2eu; return 0; }
target=r[14];
r[16]=0x0c0bbf32u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbf32u) { target=s->pc; goto dispatch; }
goto P_0c0bbf32;
P_0c0bbf30: /* original 65c2, guest PC 0x0c0bbf30 */
if(!s->budget--) { s->failed_pc=0x0c0bbf30u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bbf32;
P_0c0bbf32: /* original 9b36, guest PC 0x0c0bbf32 */
if(!s->budget--) { s->failed_pc=0x0c0bbf32u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbfa2u,2);
goto P_0c0bbf34;
P_0c0bbf34: /* original 3bdc, guest PC 0x0c0bbf34 */
if(!s->budget--) { s->failed_pc=0x0c0bbf34u; return 0; }
r[11]+=r[13];
goto P_0c0bbf36;
P_0c0bbf36: /* original a037, guest PC 0x0c0bbf36 */
if(!s->budget--) { s->failed_pc=0x0c0bbf36u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bbfa8;
P_0c0bbf38: /* original 65b2, guest PC 0x0c0bbf38 */
if(!s->budget--) { s->failed_pc=0x0c0bbf38u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
return vf3_matrix_family(0x0c0bbf3au,s,ram);
P_0c0bbfa8: /* original 94ab, guest PC 0x0c0bbfa8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfa8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc102u,2);
goto P_0c0bbfaa;
P_0c0bbfaa: /* original 4e0b, guest PC 0x0c0bbfaa */
if(!s->budget--) { s->failed_pc=0x0c0bbfaau; return 0; }
target=r[14];
r[16]=0x0c0bbfaeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfaeu) { target=s->pc; goto dispatch; }
goto P_0c0bbfae;
P_0c0bbfac: /* original 0009, guest PC 0x0c0bbfac */
if(!s->budget--) { s->failed_pc=0x0c0bbfacu; return 0; }
goto P_0c0bbfae;
P_0c0bbfae: /* original 94a9, guest PC 0x0c0bbfae */
if(!s->budget--) { s->failed_pc=0x0c0bbfaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc104u,2);
goto P_0c0bbfb0;
P_0c0bbfb0: /* original 4e0b, guest PC 0x0c0bbfb0 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb0u; return 0; }
target=r[14];
r[16]=0x0c0bbfb4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfb4u) { target=s->pc; goto dispatch; }
goto P_0c0bbfb4;
P_0c0bbfb2: /* original 65b2, guest PC 0x0c0bbfb2 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bbfb4;
P_0c0bbfb4: /* original 94a7, guest PC 0x0c0bbfb4 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc106u,2);
goto P_0c0bbfb6;
P_0c0bbfb6: /* original 4e0b, guest PC 0x0c0bbfb6 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb6u; return 0; }
target=r[14];
r[16]=0x0c0bbfbau;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfbau) { target=s->pc; goto dispatch; }
goto P_0c0bbfba;
P_0c0bbfb8: /* original 65b2, guest PC 0x0c0bbfb8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bbfba;
P_0c0bbfba: /* original 94a5, guest PC 0x0c0bbfba */
if(!s->budget--) { s->failed_pc=0x0c0bbfbau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc108u,2);
goto P_0c0bbfbc;
P_0c0bbfbc: /* original 4e0b, guest PC 0x0c0bbfbc */
if(!s->budget--) { s->failed_pc=0x0c0bbfbcu; return 0; }
target=r[14];
r[16]=0x0c0bbfc0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfc0u) { target=s->pc; goto dispatch; }
goto P_0c0bbfc0;
P_0c0bbfbe: /* original 65b2, guest PC 0x0c0bbfbe */
if(!s->budget--) { s->failed_pc=0x0c0bbfbeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bbfc0;
P_0c0bbfc0: /* original 9aa3, guest PC 0x0c0bbfc0 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc10au,2);
goto P_0c0bbfc2;
P_0c0bbfc2: /* original 94a3, guest PC 0x0c0bbfc2 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc10cu,2);
goto P_0c0bbfc4;
P_0c0bbfc4: /* original 3adc, guest PC 0x0c0bbfc4 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc4u; return 0; }
r[10]+=r[13];
goto P_0c0bbfc6;
P_0c0bbfc6: /* original 4e0b, guest PC 0x0c0bbfc6 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc6u; return 0; }
target=r[14];
r[16]=0x0c0bbfcau;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfcau) { target=s->pc; goto dispatch; }
goto P_0c0bbfca;
P_0c0bbfc8: /* original 65a2, guest PC 0x0c0bbfc8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc8u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bbfca;
P_0c0bbfca: /* original 94a0, guest PC 0x0c0bbfca */
if(!s->budget--) { s->failed_pc=0x0c0bbfcau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc10eu,2);
goto P_0c0bbfcc;
P_0c0bbfcc: /* original 4e0b, guest PC 0x0c0bbfcc */
if(!s->budget--) { s->failed_pc=0x0c0bbfccu; return 0; }
target=r[14];
r[16]=0x0c0bbfd0u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfd0u) { target=s->pc; goto dispatch; }
goto P_0c0bbfd0;
P_0c0bbfce: /* original 65a2, guest PC 0x0c0bbfce */
if(!s->budget--) { s->failed_pc=0x0c0bbfceu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bbfd0;
P_0c0bbfd0: /* original 949e, guest PC 0x0c0bbfd0 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc110u,2);
goto P_0c0bbfd2;
P_0c0bbfd2: /* original 4e0b, guest PC 0x0c0bbfd2 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd2u; return 0; }
target=r[14];
r[16]=0x0c0bbfd6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfd6u) { target=s->pc; goto dispatch; }
goto P_0c0bbfd6;
P_0c0bbfd4: /* original 65a2, guest PC 0x0c0bbfd4 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bbfd6;
P_0c0bbfd6: /* original 949c, guest PC 0x0c0bbfd6 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc112u,2);
goto P_0c0bbfd8;
P_0c0bbfd8: /* original 4e0b, guest PC 0x0c0bbfd8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd8u; return 0; }
target=r[14];
r[16]=0x0c0bbfdcu;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfdcu) { target=s->pc; goto dispatch; }
goto P_0c0bbfdc;
P_0c0bbfda: /* original 65a2, guest PC 0x0c0bbfda */
if(!s->budget--) { s->failed_pc=0x0c0bbfdau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bbfdc;
P_0c0bbfdc: /* original 949a, guest PC 0x0c0bbfdc */
if(!s->budget--) { s->failed_pc=0x0c0bbfdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc114u,2);
goto P_0c0bbfde;
P_0c0bbfde: /* original 65f2, guest PC 0x0c0bbfde */
if(!s->budget--) { s->failed_pc=0x0c0bbfdeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bbfe0;
P_0c0bbfe0: /* original 4e0b, guest PC 0x0c0bbfe0 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe0u; return 0; }
target=r[14];
r[16]=0x0c0bbfe4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfe4u) { target=s->pc; goto dispatch; }
goto P_0c0bbfe4;
P_0c0bbfe2: /* original 6552, guest PC 0x0c0bbfe2 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bbfe4;
P_0c0bbfe4: /* original 9497, guest PC 0x0c0bbfe4 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc116u,2);
goto P_0c0bbfe6;
P_0c0bbfe6: /* original 55f1, guest PC 0x0c0bbfe6 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0bbfe8;
P_0c0bbfe8: /* original 4e0b, guest PC 0x0c0bbfe8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe8u; return 0; }
target=r[14];
r[16]=0x0c0bbfecu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbfecu) { target=s->pc; goto dispatch; }
goto P_0c0bbfec;
P_0c0bbfea: /* original 6552, guest PC 0x0c0bbfea */
if(!s->budget--) { s->failed_pc=0x0c0bbfeau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bbfec;
P_0c0bbfec: /* original 9494, guest PC 0x0c0bbfec */
if(!s->budget--) { s->failed_pc=0x0c0bbfecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc118u,2);
goto P_0c0bbfee;
P_0c0bbfee: /* original 4e0b, guest PC 0x0c0bbfee */
if(!s->budget--) { s->failed_pc=0x0c0bbfeeu; return 0; }
target=r[14];
r[16]=0x0c0bbff2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbff2u) { target=s->pc; goto dispatch; }
goto P_0c0bbff2;
P_0c0bbff0: /* original 6592, guest PC 0x0c0bbff0 */
if(!s->budget--) { s->failed_pc=0x0c0bbff0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbff2;
P_0c0bbff2: /* original 9492, guest PC 0x0c0bbff2 */
if(!s->budget--) { s->failed_pc=0x0c0bbff2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc11au,2);
goto P_0c0bbff4;
P_0c0bbff4: /* original 4e0b, guest PC 0x0c0bbff4 */
if(!s->budget--) { s->failed_pc=0x0c0bbff4u; return 0; }
target=r[14];
r[16]=0x0c0bbff8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbff8u) { target=s->pc; goto dispatch; }
goto P_0c0bbff8;
P_0c0bbff6: /* original 6592, guest PC 0x0c0bbff6 */
if(!s->budget--) { s->failed_pc=0x0c0bbff6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbff8;
P_0c0bbff8: /* original 9490, guest PC 0x0c0bbff8 */
if(!s->budget--) { s->failed_pc=0x0c0bbff8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc11cu,2);
goto P_0c0bbffa;
P_0c0bbffa: /* original 4e0b, guest PC 0x0c0bbffa */
if(!s->budget--) { s->failed_pc=0x0c0bbffau; return 0; }
target=r[14];
r[16]=0x0c0bbffeu;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bbffeu) { target=s->pc; goto dispatch; }
goto P_0c0bbffe;
P_0c0bbffc: /* original 6592, guest PC 0x0c0bbffc */
if(!s->budget--) { s->failed_pc=0x0c0bbffcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbffe;
P_0c0bbffe: /* original 948e, guest PC 0x0c0bbffe */
if(!s->budget--) { s->failed_pc=0x0c0bbffeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc11eu,2);
goto P_0c0bc000;
P_0c0bc000: /* original 4e0b, guest PC 0x0c0bc000 */
if(!s->budget--) { s->failed_pc=0x0c0bc000u; return 0; }
target=r[14];
r[16]=0x0c0bc004u;
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc004u) { target=s->pc; goto dispatch; }
goto P_0c0bc004;
P_0c0bc002: /* original 6592, guest PC 0x0c0bc002 */
if(!s->budget--) { s->failed_pc=0x0c0bc002u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc004;
P_0c0bc004: /* original 948c, guest PC 0x0c0bc004 */
if(!s->budget--) { s->failed_pc=0x0c0bc004u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc120u,2);
goto P_0c0bc006;
P_0c0bc006: /* original 4e0b, guest PC 0x0c0bc006 */
if(!s->budget--) { s->failed_pc=0x0c0bc006u; return 0; }
target=r[14];
r[16]=0x0c0bc00au;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc00au) { target=s->pc; goto dispatch; }
goto P_0c0bc00a;
P_0c0bc008: /* original 65c2, guest PC 0x0c0bc008 */
if(!s->budget--) { s->failed_pc=0x0c0bc008u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc00a;
P_0c0bc00a: /* original 948a, guest PC 0x0c0bc00a */
if(!s->budget--) { s->failed_pc=0x0c0bc00au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc122u,2);
goto P_0c0bc00c;
P_0c0bc00c: /* original 4e0b, guest PC 0x0c0bc00c */
if(!s->budget--) { s->failed_pc=0x0c0bc00cu; return 0; }
target=r[14];
r[16]=0x0c0bc010u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc010u) { target=s->pc; goto dispatch; }
goto P_0c0bc010;
P_0c0bc00e: /* original 65c2, guest PC 0x0c0bc00e */
if(!s->budget--) { s->failed_pc=0x0c0bc00eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc010;
P_0c0bc010: /* original 9488, guest PC 0x0c0bc010 */
if(!s->budget--) { s->failed_pc=0x0c0bc010u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc124u,2);
goto P_0c0bc012;
P_0c0bc012: /* original 4e0b, guest PC 0x0c0bc012 */
if(!s->budget--) { s->failed_pc=0x0c0bc012u; return 0; }
target=r[14];
r[16]=0x0c0bc016u;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc016u) { target=s->pc; goto dispatch; }
goto P_0c0bc016;
P_0c0bc014: /* original 65c2, guest PC 0x0c0bc014 */
if(!s->budget--) { s->failed_pc=0x0c0bc014u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc016;
P_0c0bc016: /* original 9486, guest PC 0x0c0bc016 */
if(!s->budget--) { s->failed_pc=0x0c0bc016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc126u,2);
goto P_0c0bc018;
P_0c0bc018: /* original 4e0b, guest PC 0x0c0bc018 */
if(!s->budget--) { s->failed_pc=0x0c0bc018u; return 0; }
target=r[14];
r[16]=0x0c0bc01cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc01cu) { target=s->pc; goto dispatch; }
goto P_0c0bc01c;
P_0c0bc01a: /* original 65c2, guest PC 0x0c0bc01a */
if(!s->budget--) { s->failed_pc=0x0c0bc01au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc01c;
P_0c0bc01c: /* original 9484, guest PC 0x0c0bc01c */
if(!s->budget--) { s->failed_pc=0x0c0bc01cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc128u,2);
goto P_0c0bc01e;
P_0c0bc01e: /* original 4e0b, guest PC 0x0c0bc01e */
if(!s->budget--) { s->failed_pc=0x0c0bc01eu; return 0; }
target=r[14];
r[16]=0x0c0bc022u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc022u) { target=s->pc; goto dispatch; }
goto P_0c0bc022;
P_0c0bc020: /* original 65b2, guest PC 0x0c0bc020 */
if(!s->budget--) { s->failed_pc=0x0c0bc020u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc022;
P_0c0bc022: /* original 9482, guest PC 0x0c0bc022 */
if(!s->budget--) { s->failed_pc=0x0c0bc022u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc12au,2);
goto P_0c0bc024;
P_0c0bc024: /* original 4e0b, guest PC 0x0c0bc024 */
if(!s->budget--) { s->failed_pc=0x0c0bc024u; return 0; }
target=r[14];
r[16]=0x0c0bc028u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc028u) { target=s->pc; goto dispatch; }
goto P_0c0bc028;
P_0c0bc026: /* original 65b2, guest PC 0x0c0bc026 */
if(!s->budget--) { s->failed_pc=0x0c0bc026u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc028;
P_0c0bc028: /* original 9480, guest PC 0x0c0bc028 */
if(!s->budget--) { s->failed_pc=0x0c0bc028u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc12cu,2);
goto P_0c0bc02a;
P_0c0bc02a: /* original 4e0b, guest PC 0x0c0bc02a */
if(!s->budget--) { s->failed_pc=0x0c0bc02au; return 0; }
target=r[14];
r[16]=0x0c0bc02eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc02eu) { target=s->pc; goto dispatch; }
goto P_0c0bc02e;
P_0c0bc02c: /* original 65b2, guest PC 0x0c0bc02c */
if(!s->budget--) { s->failed_pc=0x0c0bc02cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc02e;
P_0c0bc02e: /* original 947e, guest PC 0x0c0bc02e */
if(!s->budget--) { s->failed_pc=0x0c0bc02eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc12eu,2);
goto P_0c0bc030;
P_0c0bc030: /* original 4e0b, guest PC 0x0c0bc030 */
if(!s->budget--) { s->failed_pc=0x0c0bc030u; return 0; }
target=r[14];
r[16]=0x0c0bc034u;
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc034u) { target=s->pc; goto dispatch; }
goto P_0c0bc034;
P_0c0bc032: /* original 65b2, guest PC 0x0c0bc032 */
if(!s->budget--) { s->failed_pc=0x0c0bc032u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc034;
P_0c0bc034: /* original 947c, guest PC 0x0c0bc034 */
if(!s->budget--) { s->failed_pc=0x0c0bc034u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc130u,2);
goto P_0c0bc036;
P_0c0bc036: /* original 4e0b, guest PC 0x0c0bc036 */
if(!s->budget--) { s->failed_pc=0x0c0bc036u; return 0; }
target=r[14];
r[16]=0x0c0bc03au;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc03au) { target=s->pc; goto dispatch; }
goto P_0c0bc03a;
P_0c0bc038: /* original 65a2, guest PC 0x0c0bc038 */
if(!s->budget--) { s->failed_pc=0x0c0bc038u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc03a;
P_0c0bc03a: /* original 947a, guest PC 0x0c0bc03a */
if(!s->budget--) { s->failed_pc=0x0c0bc03au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc132u,2);
goto P_0c0bc03c;
P_0c0bc03c: /* original 4e0b, guest PC 0x0c0bc03c */
if(!s->budget--) { s->failed_pc=0x0c0bc03cu; return 0; }
target=r[14];
r[16]=0x0c0bc040u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc040u) { target=s->pc; goto dispatch; }
goto P_0c0bc040;
P_0c0bc03e: /* original 65a2, guest PC 0x0c0bc03e */
if(!s->budget--) { s->failed_pc=0x0c0bc03eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc040;
P_0c0bc040: /* original 9478, guest PC 0x0c0bc040 */
if(!s->budget--) { s->failed_pc=0x0c0bc040u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc134u,2);
goto P_0c0bc042;
P_0c0bc042: /* original 4e0b, guest PC 0x0c0bc042 */
if(!s->budget--) { s->failed_pc=0x0c0bc042u; return 0; }
target=r[14];
r[16]=0x0c0bc046u;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc046u) { target=s->pc; goto dispatch; }
goto P_0c0bc046;
P_0c0bc044: /* original 65a2, guest PC 0x0c0bc044 */
if(!s->budget--) { s->failed_pc=0x0c0bc044u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc046;
P_0c0bc046: /* original 9476, guest PC 0x0c0bc046 */
if(!s->budget--) { s->failed_pc=0x0c0bc046u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc136u,2);
goto P_0c0bc048;
P_0c0bc048: /* original 4e0b, guest PC 0x0c0bc048 */
if(!s->budget--) { s->failed_pc=0x0c0bc048u; return 0; }
target=r[14];
r[16]=0x0c0bc04cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc04cu) { target=s->pc; goto dispatch; }
goto P_0c0bc04c;
P_0c0bc04a: /* original 65a2, guest PC 0x0c0bc04a */
if(!s->budget--) { s->failed_pc=0x0c0bc04au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc04c;
P_0c0bc04c: /* original 9574, guest PC 0x0c0bc04c */
if(!s->budget--) { s->failed_pc=0x0c0bc04cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc138u,2);
goto P_0c0bc04e;
P_0c0bc04e: /* original 35dc, guest PC 0x0c0bc04e */
if(!s->budget--) { s->failed_pc=0x0c0bc04eu; return 0; }
r[5]+=r[13];
goto P_0c0bc050;
P_0c0bc050: /* original 2f52, guest PC 0x0c0bc050 */
if(!s->budget--) { s->failed_pc=0x0c0bc050u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc052;
P_0c0bc052: /* original 9472, guest PC 0x0c0bc052 */
if(!s->budget--) { s->failed_pc=0x0c0bc052u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc13au,2);
goto P_0c0bc054;
P_0c0bc054: /* original 4e0b, guest PC 0x0c0bc054 */
if(!s->budget--) { s->failed_pc=0x0c0bc054u; return 0; }
target=r[14];
r[16]=0x0c0bc058u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc058u) { target=s->pc; goto dispatch; }
goto P_0c0bc058;
P_0c0bc056: /* original 6552, guest PC 0x0c0bc056 */
if(!s->budget--) { s->failed_pc=0x0c0bc056u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc058;
P_0c0bc058: /* original 9470, guest PC 0x0c0bc058 */
if(!s->budget--) { s->failed_pc=0x0c0bc058u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc13cu,2);
goto P_0c0bc05a;
P_0c0bc05a: /* original 65f2, guest PC 0x0c0bc05a */
if(!s->budget--) { s->failed_pc=0x0c0bc05au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc05c;
P_0c0bc05c: /* original 4e0b, guest PC 0x0c0bc05c */
if(!s->budget--) { s->failed_pc=0x0c0bc05cu; return 0; }
target=r[14];
r[16]=0x0c0bc060u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc060u) { target=s->pc; goto dispatch; }
goto P_0c0bc060;
P_0c0bc05e: /* original 6552, guest PC 0x0c0bc05e */
if(!s->budget--) { s->failed_pc=0x0c0bc05eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc060;
P_0c0bc060: /* original 956d, guest PC 0x0c0bc060 */
if(!s->budget--) { s->failed_pc=0x0c0bc060u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc13eu,2);
goto P_0c0bc062;
P_0c0bc062: /* original 35dc, guest PC 0x0c0bc062 */
if(!s->budget--) { s->failed_pc=0x0c0bc062u; return 0; }
r[5]+=r[13];
goto P_0c0bc064;
P_0c0bc064: /* original 2f52, guest PC 0x0c0bc064 */
if(!s->budget--) { s->failed_pc=0x0c0bc064u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc066;
P_0c0bc066: /* original 946b, guest PC 0x0c0bc066 */
if(!s->budget--) { s->failed_pc=0x0c0bc066u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc140u,2);
goto P_0c0bc068;
P_0c0bc068: /* original 4e0b, guest PC 0x0c0bc068 */
if(!s->budget--) { s->failed_pc=0x0c0bc068u; return 0; }
target=r[14];
r[16]=0x0c0bc06cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc06cu) { target=s->pc; goto dispatch; }
goto P_0c0bc06c;
P_0c0bc06a: /* original 6552, guest PC 0x0c0bc06a */
if(!s->budget--) { s->failed_pc=0x0c0bc06au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc06c;
P_0c0bc06c: /* original 9469, guest PC 0x0c0bc06c */
if(!s->budget--) { s->failed_pc=0x0c0bc06cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc142u,2);
goto P_0c0bc06e;
P_0c0bc06e: /* original 65f2, guest PC 0x0c0bc06e */
if(!s->budget--) { s->failed_pc=0x0c0bc06eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc070;
P_0c0bc070: /* original 4e0b, guest PC 0x0c0bc070 */
if(!s->budget--) { s->failed_pc=0x0c0bc070u; return 0; }
target=r[14];
r[16]=0x0c0bc074u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc074u) { target=s->pc; goto dispatch; }
goto P_0c0bc074;
P_0c0bc072: /* original 6552, guest PC 0x0c0bc072 */
if(!s->budget--) { s->failed_pc=0x0c0bc072u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc074;
P_0c0bc074: /* original 9467, guest PC 0x0c0bc074 */
if(!s->budget--) { s->failed_pc=0x0c0bc074u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc146u,2);
goto P_0c0bc076;
P_0c0bc076: /* original 9065, guest PC 0x0c0bc076 */
if(!s->budget--) { s->failed_pc=0x0c0bc076u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc144u,2);
goto P_0c0bc078;
P_0c0bc078: /* original 4e0b, guest PC 0x0c0bc078 */
if(!s->budget--) { s->failed_pc=0x0c0bc078u; return 0; }
target=r[14];
r[16]=0x0c0bc07cu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc07cu) { target=s->pc; goto dispatch; }
goto P_0c0bc07c;
P_0c0bc07a: /* original 05de, guest PC 0x0c0bc07a */
if(!s->budget--) { s->failed_pc=0x0c0bc07au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc07c;
P_0c0bc07c: /* original 9564, guest PC 0x0c0bc07c */
if(!s->budget--) { s->failed_pc=0x0c0bc07cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc148u,2);
goto P_0c0bc07e;
P_0c0bc07e: /* original 35dc, guest PC 0x0c0bc07e */
if(!s->budget--) { s->failed_pc=0x0c0bc07eu; return 0; }
r[5]+=r[13];
goto P_0c0bc080;
P_0c0bc080: /* original 2f52, guest PC 0x0c0bc080 */
if(!s->budget--) { s->failed_pc=0x0c0bc080u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc082;
P_0c0bc082: /* original 9462, guest PC 0x0c0bc082 */
if(!s->budget--) { s->failed_pc=0x0c0bc082u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc14au,2);
goto P_0c0bc084;
P_0c0bc084: /* original 4e0b, guest PC 0x0c0bc084 */
if(!s->budget--) { s->failed_pc=0x0c0bc084u; return 0; }
target=r[14];
r[16]=0x0c0bc088u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc088u) { target=s->pc; goto dispatch; }
goto P_0c0bc088;
P_0c0bc086: /* original 6552, guest PC 0x0c0bc086 */
if(!s->budget--) { s->failed_pc=0x0c0bc086u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc088;
P_0c0bc088: /* original 9460, guest PC 0x0c0bc088 */
if(!s->budget--) { s->failed_pc=0x0c0bc088u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc14cu,2);
goto P_0c0bc08a;
P_0c0bc08a: /* original 65f2, guest PC 0x0c0bc08a */
if(!s->budget--) { s->failed_pc=0x0c0bc08au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc08c;
P_0c0bc08c: /* original 4e0b, guest PC 0x0c0bc08c */
if(!s->budget--) { s->failed_pc=0x0c0bc08cu; return 0; }
target=r[14];
r[16]=0x0c0bc090u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc090u) { target=s->pc; goto dispatch; }
goto P_0c0bc090;
P_0c0bc08e: /* original 6552, guest PC 0x0c0bc08e */
if(!s->budget--) { s->failed_pc=0x0c0bc08eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc090;
P_0c0bc090: /* original 945e, guest PC 0x0c0bc090 */
if(!s->budget--) { s->failed_pc=0x0c0bc090u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc150u,2);
goto P_0c0bc092;
P_0c0bc092: /* original 905c, guest PC 0x0c0bc092 */
if(!s->budget--) { s->failed_pc=0x0c0bc092u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc14eu,2);
goto P_0c0bc094;
P_0c0bc094: /* original 4e0b, guest PC 0x0c0bc094 */
if(!s->budget--) { s->failed_pc=0x0c0bc094u; return 0; }
target=r[14];
r[16]=0x0c0bc098u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc098u) { target=s->pc; goto dispatch; }
goto P_0c0bc098;
P_0c0bc096: /* original 05de, guest PC 0x0c0bc096 */
if(!s->budget--) { s->failed_pc=0x0c0bc096u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc098;
P_0c0bc098: /* original 955b, guest PC 0x0c0bc098 */
if(!s->budget--) { s->failed_pc=0x0c0bc098u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc152u,2);
goto P_0c0bc09a;
P_0c0bc09a: /* original 35dc, guest PC 0x0c0bc09a */
if(!s->budget--) { s->failed_pc=0x0c0bc09au; return 0; }
r[5]+=r[13];
goto P_0c0bc09c;
P_0c0bc09c: /* original 2f52, guest PC 0x0c0bc09c */
if(!s->budget--) { s->failed_pc=0x0c0bc09cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc09e;
P_0c0bc09e: /* original 9459, guest PC 0x0c0bc09e */
if(!s->budget--) { s->failed_pc=0x0c0bc09eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc154u,2);
goto P_0c0bc0a0;
P_0c0bc0a0: /* original 4e0b, guest PC 0x0c0bc0a0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a0u; return 0; }
target=r[14];
r[16]=0x0c0bc0a4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0a4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0a4;
P_0c0bc0a2: /* original 6552, guest PC 0x0c0bc0a2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0a4;
P_0c0bc0a4: /* original 9457, guest PC 0x0c0bc0a4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc156u,2);
goto P_0c0bc0a6;
P_0c0bc0a6: /* original 65f2, guest PC 0x0c0bc0a6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc0a8;
P_0c0bc0a8: /* original 4e0b, guest PC 0x0c0bc0a8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a8u; return 0; }
target=r[14];
r[16]=0x0c0bc0acu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0acu) { target=s->pc; goto dispatch; }
goto P_0c0bc0ac;
P_0c0bc0aa: /* original 6552, guest PC 0x0c0bc0aa */
if(!s->budget--) { s->failed_pc=0x0c0bc0aau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0ac;
P_0c0bc0ac: /* original 9455, guest PC 0x0c0bc0ac */
if(!s->budget--) { s->failed_pc=0x0c0bc0acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc15au,2);
goto P_0c0bc0ae;
P_0c0bc0ae: /* original 9053, guest PC 0x0c0bc0ae */
if(!s->budget--) { s->failed_pc=0x0c0bc0aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc158u,2);
goto P_0c0bc0b0;
P_0c0bc0b0: /* original 4e0b, guest PC 0x0c0bc0b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b0u; return 0; }
target=r[14];
r[16]=0x0c0bc0b4u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0b4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0b4;
P_0c0bc0b2: /* original 05de, guest PC 0x0c0bc0b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0b4;
P_0c0bc0b4: /* original 9552, guest PC 0x0c0bc0b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc15cu,2);
goto P_0c0bc0b6;
P_0c0bc0b6: /* original 35dc, guest PC 0x0c0bc0b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b6u; return 0; }
r[5]+=r[13];
goto P_0c0bc0b8;
P_0c0bc0b8: /* original 2f52, guest PC 0x0c0bc0b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc0ba;
P_0c0bc0ba: /* original 9450, guest PC 0x0c0bc0ba */
if(!s->budget--) { s->failed_pc=0x0c0bc0bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc15eu,2);
goto P_0c0bc0bc;
P_0c0bc0bc: /* original 4e0b, guest PC 0x0c0bc0bc */
if(!s->budget--) { s->failed_pc=0x0c0bc0bcu; return 0; }
target=r[14];
r[16]=0x0c0bc0c0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0c0u) { target=s->pc; goto dispatch; }
goto P_0c0bc0c0;
P_0c0bc0be: /* original 6552, guest PC 0x0c0bc0be */
if(!s->budget--) { s->failed_pc=0x0c0bc0beu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0c0;
P_0c0bc0c0: /* original 944e, guest PC 0x0c0bc0c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc160u,2);
goto P_0c0bc0c2;
P_0c0bc0c2: /* original 65f2, guest PC 0x0c0bc0c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc0c4;
P_0c0bc0c4: /* original 4e0b, guest PC 0x0c0bc0c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c4u; return 0; }
target=r[14];
r[16]=0x0c0bc0c8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0c8u) { target=s->pc; goto dispatch; }
goto P_0c0bc0c8;
P_0c0bc0c6: /* original 6552, guest PC 0x0c0bc0c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0c8;
P_0c0bc0c8: /* original 954b, guest PC 0x0c0bc0c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc162u,2);
goto P_0c0bc0ca;
P_0c0bc0ca: /* original 35dc, guest PC 0x0c0bc0ca */
if(!s->budget--) { s->failed_pc=0x0c0bc0cau; return 0; }
r[5]+=r[13];
goto P_0c0bc0cc;
P_0c0bc0cc: /* original 2f52, guest PC 0x0c0bc0cc */
if(!s->budget--) { s->failed_pc=0x0c0bc0ccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc0ce;
P_0c0bc0ce: /* original 9449, guest PC 0x0c0bc0ce */
if(!s->budget--) { s->failed_pc=0x0c0bc0ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc164u,2);
goto P_0c0bc0d0;
P_0c0bc0d0: /* original 4e0b, guest PC 0x0c0bc0d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d0u; return 0; }
target=r[14];
r[16]=0x0c0bc0d4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0d4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0d4;
P_0c0bc0d2: /* original 6552, guest PC 0x0c0bc0d2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0d4;
P_0c0bc0d4: /* original 9447, guest PC 0x0c0bc0d4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc166u,2);
goto P_0c0bc0d6;
P_0c0bc0d6: /* original 65f2, guest PC 0x0c0bc0d6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc0d8;
P_0c0bc0d8: /* original 4e0b, guest PC 0x0c0bc0d8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d8u; return 0; }
target=r[14];
r[16]=0x0c0bc0dcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0dcu) { target=s->pc; goto dispatch; }
goto P_0c0bc0dc;
P_0c0bc0da: /* original 6552, guest PC 0x0c0bc0da */
if(!s->budget--) { s->failed_pc=0x0c0bc0dau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0dc;
P_0c0bc0dc: /* original 9445, guest PC 0x0c0bc0dc */
if(!s->budget--) { s->failed_pc=0x0c0bc0dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc16au,2);
goto P_0c0bc0de;
P_0c0bc0de: /* original 9043, guest PC 0x0c0bc0de */
if(!s->budget--) { s->failed_pc=0x0c0bc0deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc168u,2);
goto P_0c0bc0e0;
P_0c0bc0e0: /* original 4e0b, guest PC 0x0c0bc0e0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e0u; return 0; }
target=r[14];
r[16]=0x0c0bc0e4u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0e4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0e4;
P_0c0bc0e2: /* original 05de, guest PC 0x0c0bc0e2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0e4;
P_0c0bc0e4: /* original 9443, guest PC 0x0c0bc0e4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc16eu,2);
goto P_0c0bc0e6;
P_0c0bc0e6: /* original 9041, guest PC 0x0c0bc0e6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc16cu,2);
goto P_0c0bc0e8;
P_0c0bc0e8: /* original 4e0b, guest PC 0x0c0bc0e8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e8u; return 0; }
target=r[14];
r[16]=0x0c0bc0ecu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0ecu) { target=s->pc; goto dispatch; }
goto P_0c0bc0ec;
P_0c0bc0ea: /* original 05de, guest PC 0x0c0bc0ea */
if(!s->budget--) { s->failed_pc=0x0c0bc0eau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0ec;
P_0c0bc0ec: /* original 9441, guest PC 0x0c0bc0ec */
if(!s->budget--) { s->failed_pc=0x0c0bc0ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc172u,2);
goto P_0c0bc0ee;
P_0c0bc0ee: /* original 903f, guest PC 0x0c0bc0ee */
if(!s->budget--) { s->failed_pc=0x0c0bc0eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc170u,2);
goto P_0c0bc0f0;
P_0c0bc0f0: /* original 4e0b, guest PC 0x0c0bc0f0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f0u; return 0; }
target=r[14];
r[16]=0x0c0bc0f4u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0f4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0f4;
P_0c0bc0f2: /* original 05de, guest PC 0x0c0bc0f2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0f4;
P_0c0bc0f4: /* original 943f, guest PC 0x0c0bc0f4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc176u,2);
goto P_0c0bc0f6;
P_0c0bc0f6: /* original 903d, guest PC 0x0c0bc0f6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc174u,2);
goto P_0c0bc0f8;
P_0c0bc0f8: /* original 4e0b, guest PC 0x0c0bc0f8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f8u; return 0; }
target=r[14];
r[16]=0x0c0bc0fcu;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc0fcu) { target=s->pc; goto dispatch; }
goto P_0c0bc0fc;
P_0c0bc0fa: /* original 05de, guest PC 0x0c0bc0fa */
if(!s->budget--) { s->failed_pc=0x0c0bc0fau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0fc;
P_0c0bc0fc: /* original 903c, guest PC 0x0c0bc0fc */
if(!s->budget--) { s->failed_pc=0x0c0bc0fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc178u,2);
goto P_0c0bc0fe;
P_0c0bc0fe: /* original a03c, guest PC 0x0c0bc0fe */
if(!s->budget--) { s->failed_pc=0x0c0bc0feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc17a;
P_0c0bc100: /* original 05de, guest PC 0x0c0bc100 */
if(!s->budget--) { s->failed_pc=0x0c0bc100u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
return vf3_matrix_family(0x0c0bc102u,s,ram);
P_0c0bc17a: /* original 9446, guest PC 0x0c0bc17a */
if(!s->budget--) { s->failed_pc=0x0c0bc17au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc20au,2);
goto P_0c0bc17c;
P_0c0bc17c: /* original 4e0b, guest PC 0x0c0bc17c */
if(!s->budget--) { s->failed_pc=0x0c0bc17cu; return 0; }
target=r[14];
r[16]=0x0c0bc180u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc180u) { target=s->pc; goto dispatch; }
goto P_0c0bc180;
P_0c0bc17e: /* original 0009, guest PC 0x0c0bc17e */
if(!s->budget--) { s->failed_pc=0x0c0bc17eu; return 0; }
goto P_0c0bc180;
P_0c0bc180: /* original 9445, guest PC 0x0c0bc180 */
if(!s->budget--) { s->failed_pc=0x0c0bc180u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc20eu,2);
goto P_0c0bc182;
P_0c0bc182: /* original 9043, guest PC 0x0c0bc182 */
if(!s->budget--) { s->failed_pc=0x0c0bc182u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc20cu,2);
goto P_0c0bc184;
P_0c0bc184: /* original 4e0b, guest PC 0x0c0bc184 */
if(!s->budget--) { s->failed_pc=0x0c0bc184u; return 0; }
target=r[14];
r[16]=0x0c0bc188u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc188u) { target=s->pc; goto dispatch; }
goto P_0c0bc188;
P_0c0bc186: /* original 05de, guest PC 0x0c0bc186 */
if(!s->budget--) { s->failed_pc=0x0c0bc186u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc188;
P_0c0bc188: /* original 9443, guest PC 0x0c0bc188 */
if(!s->budget--) { s->failed_pc=0x0c0bc188u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc212u,2);
goto P_0c0bc18a;
P_0c0bc18a: /* original 9041, guest PC 0x0c0bc18a */
if(!s->budget--) { s->failed_pc=0x0c0bc18au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc210u,2);
goto P_0c0bc18c;
P_0c0bc18c: /* original 4e0b, guest PC 0x0c0bc18c */
if(!s->budget--) { s->failed_pc=0x0c0bc18cu; return 0; }
target=r[14];
r[16]=0x0c0bc190u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc190u) { target=s->pc; goto dispatch; }
goto P_0c0bc190;
P_0c0bc18e: /* original 05de, guest PC 0x0c0bc18e */
if(!s->budget--) { s->failed_pc=0x0c0bc18eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc190;
P_0c0bc190: /* original 9441, guest PC 0x0c0bc190 */
if(!s->budget--) { s->failed_pc=0x0c0bc190u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc216u,2);
goto P_0c0bc192;
P_0c0bc192: /* original 903f, guest PC 0x0c0bc192 */
if(!s->budget--) { s->failed_pc=0x0c0bc192u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc214u,2);
goto P_0c0bc194;
P_0c0bc194: /* original 4e0b, guest PC 0x0c0bc194 */
if(!s->budget--) { s->failed_pc=0x0c0bc194u; return 0; }
target=r[14];
r[16]=0x0c0bc198u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc198u) { target=s->pc; goto dispatch; }
goto P_0c0bc198;
P_0c0bc196: /* original 05de, guest PC 0x0c0bc196 */
if(!s->budget--) { s->failed_pc=0x0c0bc196u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc198;
P_0c0bc198: /* original 943f, guest PC 0x0c0bc198 */
if(!s->budget--) { s->failed_pc=0x0c0bc198u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc21au,2);
goto P_0c0bc19a;
P_0c0bc19a: /* original 903d, guest PC 0x0c0bc19a */
if(!s->budget--) { s->failed_pc=0x0c0bc19au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc218u,2);
goto P_0c0bc19c;
P_0c0bc19c: /* original 4e0b, guest PC 0x0c0bc19c */
if(!s->budget--) { s->failed_pc=0x0c0bc19cu; return 0; }
target=r[14];
r[16]=0x0c0bc1a0u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1a0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1a0;
P_0c0bc19e: /* original 05de, guest PC 0x0c0bc19e */
if(!s->budget--) { s->failed_pc=0x0c0bc19eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1a0;
P_0c0bc1a0: /* original 943d, guest PC 0x0c0bc1a0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc21eu,2);
goto P_0c0bc1a2;
P_0c0bc1a2: /* original 903b, guest PC 0x0c0bc1a2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc21cu,2);
goto P_0c0bc1a4;
P_0c0bc1a4: /* original 4e0b, guest PC 0x0c0bc1a4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a4u; return 0; }
target=r[14];
r[16]=0x0c0bc1a8u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1a8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1a8;
P_0c0bc1a6: /* original 05de, guest PC 0x0c0bc1a6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1a8;
P_0c0bc1a8: /* original 943b, guest PC 0x0c0bc1a8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc222u,2);
goto P_0c0bc1aa;
P_0c0bc1aa: /* original 9039, guest PC 0x0c0bc1aa */
if(!s->budget--) { s->failed_pc=0x0c0bc1aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc220u,2);
goto P_0c0bc1ac;
P_0c0bc1ac: /* original 4e0b, guest PC 0x0c0bc1ac */
if(!s->budget--) { s->failed_pc=0x0c0bc1acu; return 0; }
target=r[14];
r[16]=0x0c0bc1b0u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1b0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1b0;
P_0c0bc1ae: /* original 05de, guest PC 0x0c0bc1ae */
if(!s->budget--) { s->failed_pc=0x0c0bc1aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1b0;
P_0c0bc1b0: /* original 9439, guest PC 0x0c0bc1b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc226u,2);
goto P_0c0bc1b2;
P_0c0bc1b2: /* original 9037, guest PC 0x0c0bc1b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc224u,2);
goto P_0c0bc1b4;
P_0c0bc1b4: /* original 4e0b, guest PC 0x0c0bc1b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b4u; return 0; }
target=r[14];
r[16]=0x0c0bc1b8u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1b8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1b8;
P_0c0bc1b6: /* original 05de, guest PC 0x0c0bc1b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1b8;
P_0c0bc1b8: /* original 9437, guest PC 0x0c0bc1b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc22au,2);
goto P_0c0bc1ba;
P_0c0bc1ba: /* original 9035, guest PC 0x0c0bc1ba */
if(!s->budget--) { s->failed_pc=0x0c0bc1bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc228u,2);
goto P_0c0bc1bc;
P_0c0bc1bc: /* original 4e0b, guest PC 0x0c0bc1bc */
if(!s->budget--) { s->failed_pc=0x0c0bc1bcu; return 0; }
target=r[14];
r[16]=0x0c0bc1c0u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1c0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1c0;
P_0c0bc1be: /* original 05de, guest PC 0x0c0bc1be */
if(!s->budget--) { s->failed_pc=0x0c0bc1beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1c0;
P_0c0bc1c0: /* original 9435, guest PC 0x0c0bc1c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc22eu,2);
goto P_0c0bc1c2;
P_0c0bc1c2: /* original 9033, guest PC 0x0c0bc1c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc22cu,2);
goto P_0c0bc1c4;
P_0c0bc1c4: /* original 4e0b, guest PC 0x0c0bc1c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c4u; return 0; }
target=r[14];
r[16]=0x0c0bc1c8u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1c8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1c8;
P_0c0bc1c6: /* original 05de, guest PC 0x0c0bc1c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1c8;
P_0c0bc1c8: /* original 9433, guest PC 0x0c0bc1c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc232u,2);
goto P_0c0bc1ca;
P_0c0bc1ca: /* original 9031, guest PC 0x0c0bc1ca */
if(!s->budget--) { s->failed_pc=0x0c0bc1cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc230u,2);
goto P_0c0bc1cc;
P_0c0bc1cc: /* original 4e0b, guest PC 0x0c0bc1cc */
if(!s->budget--) { s->failed_pc=0x0c0bc1ccu; return 0; }
target=r[14];
r[16]=0x0c0bc1d0u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1d0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1d0;
P_0c0bc1ce: /* original 05de, guest PC 0x0c0bc1ce */
if(!s->budget--) { s->failed_pc=0x0c0bc1ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1d0;
P_0c0bc1d0: /* original 9431, guest PC 0x0c0bc1d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc236u,2);
goto P_0c0bc1d2;
P_0c0bc1d2: /* original 902f, guest PC 0x0c0bc1d2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc234u,2);
goto P_0c0bc1d4;
P_0c0bc1d4: /* original 4e0b, guest PC 0x0c0bc1d4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d4u; return 0; }
target=r[14];
r[16]=0x0c0bc1d8u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1d8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1d8;
P_0c0bc1d6: /* original 05de, guest PC 0x0c0bc1d6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1d8;
P_0c0bc1d8: /* original 942f, guest PC 0x0c0bc1d8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc23au,2);
goto P_0c0bc1da;
P_0c0bc1da: /* original 902d, guest PC 0x0c0bc1da */
if(!s->budget--) { s->failed_pc=0x0c0bc1dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc238u,2);
goto P_0c0bc1dc;
P_0c0bc1dc: /* original 4e0b, guest PC 0x0c0bc1dc */
if(!s->budget--) { s->failed_pc=0x0c0bc1dcu; return 0; }
target=r[14];
r[16]=0x0c0bc1e0u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1e0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1e0;
P_0c0bc1de: /* original 05de, guest PC 0x0c0bc1de */
if(!s->budget--) { s->failed_pc=0x0c0bc1deu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1e0;
P_0c0bc1e0: /* original 942d, guest PC 0x0c0bc1e0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc23eu,2);
goto P_0c0bc1e2;
P_0c0bc1e2: /* original 902b, guest PC 0x0c0bc1e2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc23cu,2);
goto P_0c0bc1e4;
P_0c0bc1e4: /* original 4e0b, guest PC 0x0c0bc1e4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e4u; return 0; }
target=r[14];
r[16]=0x0c0bc1e8u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1e8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1e8;
P_0c0bc1e6: /* original 05de, guest PC 0x0c0bc1e6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1e8;
P_0c0bc1e8: /* original 942b, guest PC 0x0c0bc1e8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc242u,2);
goto P_0c0bc1ea;
P_0c0bc1ea: /* original 9029, guest PC 0x0c0bc1ea */
if(!s->budget--) { s->failed_pc=0x0c0bc1eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc240u,2);
goto P_0c0bc1ec;
P_0c0bc1ec: /* original 4e0b, guest PC 0x0c0bc1ec */
if(!s->budget--) { s->failed_pc=0x0c0bc1ecu; return 0; }
target=r[14];
r[16]=0x0c0bc1f0u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1f0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1f0;
P_0c0bc1ee: /* original 05de, guest PC 0x0c0bc1ee */
if(!s->budget--) { s->failed_pc=0x0c0bc1eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1f0;
P_0c0bc1f0: /* original 9429, guest PC 0x0c0bc1f0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc246u,2);
goto P_0c0bc1f2;
P_0c0bc1f2: /* original 9027, guest PC 0x0c0bc1f2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc244u,2);
goto P_0c0bc1f4;
P_0c0bc1f4: /* original 4e0b, guest PC 0x0c0bc1f4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f4u; return 0; }
target=r[14];
r[16]=0x0c0bc1f8u;
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bc1f8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1f8;
P_0c0bc1f6: /* original 05de, guest PC 0x0c0bc1f6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1f8;
P_0c0bc1f8: /* original 7f08, guest PC 0x0c0bc1f8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0bc1fa;
P_0c0bc1fa: /* original 4f26, guest PC 0x0c0bc1fa */
if(!s->budget--) { s->failed_pc=0x0c0bc1fau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bc1fc;
P_0c0bc1fc: /* original 69f6, guest PC 0x0c0bc1fc */
if(!s->budget--) { s->failed_pc=0x0c0bc1fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bc1fe;
P_0c0bc1fe: /* original 6af6, guest PC 0x0c0bc1fe */
if(!s->budget--) { s->failed_pc=0x0c0bc1feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bc200;
P_0c0bc200: /* original 6bf6, guest PC 0x0c0bc200 */
if(!s->budget--) { s->failed_pc=0x0c0bc200u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bc202;
P_0c0bc202: /* original 6cf6, guest PC 0x0c0bc202 */
if(!s->budget--) { s->failed_pc=0x0c0bc202u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bc204;
P_0c0bc204: /* original 6df6, guest PC 0x0c0bc204 */
if(!s->budget--) { s->failed_pc=0x0c0bc204u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bc206;
P_0c0bc206: /* original 000b, guest PC 0x0c0bc206 */
if(!s->budget--) { s->failed_pc=0x0c0bc206u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bc208: /* original 6ef6, guest PC 0x0c0bc208 */
if(!s->budget--) { s->failed_pc=0x0c0bc208u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0bc20au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0b38d0u,0x0c0b38d2u,0x0c0b38d4u,0x0c0b38d6u,0x0c0b38d8u,0x0c0b38dau,0x0c0b38dcu,0x0c0b38deu,0x0c0b38e0u,0x0c0b38e2u,0x0c0b38e4u,0x0c0b38e6u,0x0c0b38e8u,0x0c0b38eau,0x0c0b38ecu,0x0c0b38eeu,
0x0c0b38f0u,0x0c0b38f2u,0x0c0b38f4u,0x0c0b38f6u,0x0c0b38f8u,0x0c0b38fau,0x0c0b38fcu,0x0c0b38feu,0x0c0b3900u,0x0c0b3902u,0x0c0b3904u,0x0c0b3906u,0x0c0b3908u,0x0c0b390au,0x0c0b390cu,0x0c0b390eu,
0x0c0b3910u,0x0c0b3912u,0x0c0b3914u,0x0c0b3916u,0x0c0b3918u,0x0c0b391au,0x0c0b391cu,0x0c0b391eu,0x0c0b3920u,0x0c0b3922u,0x0c0b3924u,0x0c0b3926u,0x0c0b3928u,0x0c0b392au,0x0c0b392cu,0x0c0b392eu,
0x0c0b3930u,0x0c0b3932u,0x0c0b3934u,0x0c0b3936u,0x0c0b3938u,0x0c0b393au,0x0c0b393cu,0x0c0b393eu,0x0c0b3940u,0x0c0b3942u,0x0c0b3944u,0x0c0b3946u,0x0c0b3948u,0x0c0b394au,0x0c0b394cu,0x0c0b394eu,
0x0c0b3950u,0x0c0b3952u,0x0c0b3954u,0x0c0b3956u,0x0c0b3958u,0x0c0b395au,0x0c0b395cu,0x0c0b395eu,0x0c0b3960u,0x0c0b3962u,0x0c0b3964u,0x0c0b3966u,0x0c0b3968u,0x0c0b396au,0x0c0b396cu,0x0c0b396eu,
0x0c0b3970u,0x0c0b3972u,0x0c0b3974u,0x0c0b3976u,0x0c0b3978u,0x0c0b397au,0x0c0b397cu,0x0c0b397eu,0x0c0b3980u,0x0c0b3982u,0x0c0b3984u,0x0c0b3986u,0x0c0b3988u,0x0c0b398au,0x0c0b398cu,0x0c0b398eu,
0x0c0b3990u,0x0c0b3992u,0x0c0b3994u,0x0c0b3996u,0x0c0b3998u,0x0c0b399au,0x0c0b399cu,0x0c0b399eu,0x0c0b39a0u,0x0c0b39a2u,0x0c0b39a4u,0x0c0b39a6u,0x0c0b39a8u,0x0c0b39aau,0x0c0b39acu,0x0c0b39aeu,
0x0c0b39b0u,0x0c0b39b2u,0x0c0b39b4u,0x0c0b39b6u,0x0c0b39b8u,0x0c0b39bau,0x0c0b39bcu,0x0c0b39beu,0x0c0b39c0u,0x0c0b39c2u,0x0c0b39c4u,0x0c0b39c6u,0x0c0b39c8u,0x0c0b39cau,0x0c0b39ccu,0x0c0b39ceu,
0x0c0b39d0u,0x0c0b39d2u,0x0c0b39d4u,0x0c0b39d6u,0x0c0b39d8u,0x0c0b39dau,0x0c0b39dcu,0x0c0b39deu,0x0c0b39e0u,0x0c0b39e2u,0x0c0b39e4u,0x0c0b39e6u,0x0c0b39e8u,0x0c0b39eau,0x0c0b39ecu,0x0c0b39eeu,
0x0c0b39f0u,0x0c0b39f2u,0x0c0b39f4u,0x0c0b39f6u,0x0c0b39f8u,0x0c0b39fau,0x0c0b39fcu,0x0c0b39feu,0x0c0b3a00u,0x0c0b3a02u,0x0c0b3a04u,0x0c0b3a06u,0x0c0b3a08u,0x0c0b3a0au,0x0c0b3a0cu,0x0c0b3a0eu,
0x0c0b3a10u,0x0c0b3a12u,0x0c0b3a14u,0x0c0b3a16u,0x0c0b588eu,0x0c0b5890u,0x0c0b5892u,0x0c0b5894u,0x0c0b5896u,0x0c0b5898u,0x0c0b589au,0x0c0b589cu,0x0c0b589eu,0x0c0b58a0u,0x0c0b58a2u,0x0c0b58a4u,
0x0c0b58a6u,0x0c0b58a8u,0x0c0b58aau,0x0c0b58acu,0x0c0b58aeu,0x0c0b58b0u,0x0c0b58b2u,0x0c0b58b4u,0x0c0b58b6u,0x0c0b58b8u,0x0c0b58bau,0x0c0b58bcu,0x0c0b58beu,0x0c0b58c0u,0x0c0b58c2u,0x0c0b58c4u,
0x0c0b58c6u,0x0c0b58c8u,0x0c0b58cau,0x0c0b58ccu,0x0c0b58ceu,0x0c0b58d0u,0x0c0b58d2u,0x0c0b58d4u,0x0c0b58d6u,0x0c0b58d8u,0x0c0b58dau,0x0c0b58dcu,0x0c0b58deu,0x0c0b58e0u,0x0c0b58e2u,0x0c0b58e4u,
0x0c0b58e6u,0x0c0b58e8u,0x0c0b58eau,0x0c0b58ecu,0x0c0b58eeu,0x0c0b58f0u,0x0c0b58f2u,0x0c0b58f4u,0x0c0b58f6u,0x0c0b58f8u,0x0c0b58fau,0x0c0b58fcu,0x0c0b58feu,0x0c0b5900u,0x0c0b5902u,0x0c0b5904u,
0x0c0b5906u,0x0c0b5908u,0x0c0b590au,0x0c0b590cu,0x0c0b590eu,0x0c0b5910u,0x0c0b5912u,0x0c0b5914u,0x0c0b5916u,0x0c0b5918u,0x0c0b591au,0x0c0b591cu,0x0c0b591eu,0x0c0b5920u,0x0c0b5922u,0x0c0b5924u,
0x0c0b5926u,0x0c0b5928u,0x0c0b592au,0x0c0b592cu,0x0c0b592eu,0x0c0b5930u,0x0c0b5932u,0x0c0b5934u,0x0c0b5936u,0x0c0b5938u,0x0c0b593au,0x0c0b593cu,0x0c0b593eu,0x0c0b5940u,0x0c0b5942u,0x0c0b5944u,
0x0c0b5946u,0x0c0b5948u,0x0c0b594au,0x0c0b594cu,0x0c0b594eu,0x0c0b5950u,0x0c0b5952u,0x0c0b5954u,0x0c0b5956u,0x0c0b5958u,0x0c0b595au,0x0c0b595cu,0x0c0b595eu,0x0c0b5960u,0x0c0b5962u,0x0c0b5964u,
0x0c0b5966u,0x0c0b5968u,0x0c0b596au,0x0c0b596cu,0x0c0b596eu,0x0c0b5970u,0x0c0b5972u,0x0c0b5974u,0x0c0b5976u,0x0c0b5978u,0x0c0b597au,0x0c0b597cu,0x0c0b597eu,0x0c0b5980u,0x0c0b5982u,0x0c0b5984u,
0x0c0b5986u,0x0c0b5988u,0x0c0b598au,0x0c0b598cu,0x0c0b598eu,0x0c0b5990u,0x0c0b5992u,0x0c0b5994u,0x0c0b5996u,0x0c0b5998u,0x0c0b599au,0x0c0b599cu,0x0c0b599eu,0x0c0b59a0u,0x0c0b59a2u,0x0c0b59a4u,
0x0c0b59a6u,0x0c0b59a8u,0x0c0b59aau,0x0c0b59acu,0x0c0b59aeu,0x0c0b59b0u,0x0c0b59b2u,0x0c0b59b4u,0x0c0b59b6u,0x0c0b59b8u,0x0c0b59bau,0x0c0b59bcu,0x0c0b59beu,0x0c0b59c0u,0x0c0b59c2u,0x0c0b59c4u,
0x0c0b59c6u,0x0c0b59c8u,0x0c0b59cau,0x0c0b59ccu,0x0c0b59ceu,0x0c0b59d0u,0x0c0b59d2u,0x0c0b59d4u,0x0c0b59d6u,0x0c0b59d8u,0x0c0b59dau,0x0c0b59dcu,0x0c0b59deu,0x0c0b59e0u,0x0c0b59e2u,0x0c0b59e4u,
0x0c0b5a54u,0x0c0b5a56u,0x0c0b5a58u,0x0c0b5a5au,0x0c0b5a5cu,0x0c0b5a5eu,0x0c0b5a60u,0x0c0b5a62u,0x0c0b5a64u,0x0c0b5a66u,0x0c0b5a68u,0x0c0b5a6au,0x0c0b5a6cu,0x0c0b5a6eu,0x0c0b5a70u,0x0c0b5a72u,
0x0c0b5a74u,0x0c0b5a76u,0x0c0b5a78u,0x0c0b5a7au,0x0c0b5a7cu,0x0c0b5a7eu,0x0c0b5a80u,0x0c0b5a82u,0x0c0b5a84u,0x0c0b5a86u,0x0c0b5a88u,0x0c0b5a8au,0x0c0b5a8cu,0x0c0b5a8eu,0x0c0b5a90u,0x0c0b5a92u,
0x0c0b5a94u,0x0c0b5a96u,0x0c0b5a98u,0x0c0b5a9au,0x0c0b5a9cu,0x0c0b5a9eu,0x0c0b5aa0u,0x0c0b5aa2u,0x0c0b5aa4u,0x0c0b5aa6u,0x0c0b5aa8u,0x0c0b5aaau,0x0c0b5aacu,0x0c0b5aaeu,0x0c0b5ab0u,0x0c0b5ab2u,
0x0c0b5ab4u,0x0c0b5ab6u,0x0c0b5ab8u,0x0c0b5abau,0x0c0b5abcu,0x0c0b5abeu,0x0c0b5ac0u,0x0c0b5ac2u,0x0c0b5ac4u,0x0c0b5ac6u,0x0c0b5ac8u,0x0c0b5acau,0x0c0b5accu,0x0c0b5aceu,0x0c0b5ad0u,0x0c0b5ad2u,
0x0c0b5ad4u,0x0c0b5ad6u,0x0c0b5ad8u,0x0c0b5adau,0x0c0b5adcu,0x0c0b5adeu,0x0c0b5ae0u,0x0c0b5ae2u,0x0c0b5ae4u,0x0c0b5ae6u,0x0c0b5ae8u,0x0c0b5aeau,0x0c0b5aecu,0x0c0b5aeeu,0x0c0b5af0u,0x0c0b5af2u,
0x0c0b5af4u,0x0c0b5af6u,0x0c0b5af8u,0x0c0b5afau,0x0c0b5afcu,0x0c0b5afeu,0x0c0b5b00u,0x0c0b5b02u,0x0c0b5b04u,0x0c0b5b06u,0x0c0b5b08u,0x0c0b5b0au,0x0c0b5b0cu,0x0c0b5b0eu,0x0c0b5b10u,0x0c0b5b12u,
0x0c0b5b14u,0x0c0b5b16u,0x0c0b5b18u,0x0c0b5b1au,0x0c0b5b1cu,0x0c0b5b1eu,0x0c0b5b20u,0x0c0b5b22u,0x0c0b5b24u,0x0c0b5b26u,0x0c0b5b28u,0x0c0b5b2au,0x0c0b5b2cu,0x0c0b5b2eu,0x0c0b5b30u,0x0c0b5b32u,
0x0c0b5b34u,0x0c0b5b36u,0x0c0b5b38u,0x0c0b5b3au,0x0c0b5b3cu,0x0c0b5b3eu,0x0c0b5b40u,0x0c0b5b42u,0x0c0b5b44u,0x0c0b5b46u,0x0c0b5b48u,0x0c0b5b4au,0x0c0b5b4cu,0x0c0b5b4eu,0x0c0b5b50u,0x0c0b5b52u,
0x0c0b5b54u,0x0c0b5b56u,0x0c0b5b58u,0x0c0b5b5au,0x0c0b5b5cu,0x0c0b5b5eu,0x0c0b5b60u,0x0c0b5b62u,0x0c0b5b64u,0x0c0b5b66u,0x0c0b5b68u,0x0c0b5b6au,0x0c0b5b6cu,0x0c0b5b6eu,0x0c0b5b70u,0x0c0b5b72u,
0x0c0b5b74u,0x0c0b5b76u,0x0c0b5b78u,0x0c0b5b7au,0x0c0b5b7cu,0x0c0b5b7eu,0x0c0b5b80u,0x0c0b5b82u,0x0c0b5b84u,0x0c0b5b86u,0x0c0b5b88u,0x0c0b5b8au,0x0c0b5b8cu,0x0c0b5b8eu,0x0c0b5b90u,0x0c0b5b92u,
0x0c0b5b94u,0x0c0b5b96u,0x0c0b5b98u,0x0c0b5b9au,0x0c0b5b9cu,0x0c0b5b9eu,0x0c0b5ba0u,0x0c0b5ba2u,0x0c0b5ba4u,0x0c0b5ba6u,0x0c0b5ba8u,0x0c0b5baau,0x0c0b5bacu,0x0c0b5c26u,0x0c0b5c28u,0x0c0b5c2au,
0x0c0b5c2cu,0x0c0b5c2eu,0x0c0b5c30u,0x0c0b5c32u,0x0c0b5c34u,0x0c0b5c36u,0x0c0b5c38u,0x0c0b5c3au,0x0c0b5c3cu,0x0c0b5c3eu,0x0c0b5c40u,0x0c0b5c42u,0x0c0b5c44u,0x0c0b5c46u,0x0c0b5c48u,0x0c0b5c4au,
0x0c0b5c4cu,0x0c0b5c4eu,0x0c0b5c50u,0x0c0b5c52u,0x0c0b5c54u,0x0c0b5c56u,0x0c0b5c58u,0x0c0b5c5au,0x0c0b5c5cu,0x0c0b5c5eu,0x0c0b5c60u,0x0c0b5c62u,0x0c0b5c64u,0x0c0b5c66u,0x0c0b5c68u,0x0c0b5c6au,
0x0c0b5c6cu,0x0c0b5c6eu,0x0c0b5c70u,0x0c0b5c72u,0x0c0b5c74u,0x0c0b5c76u,0x0c0b5c78u,0x0c0b5c7au,0x0c0b5c7cu,0x0c0b5c7eu,0x0c0b5c80u,0x0c0b5c82u,0x0c0b5c84u,0x0c0b5c86u,0x0c0b5c88u,0x0c0b5c8au,
0x0c0b5c8cu,0x0c0b9700u,0x0c0b9702u,0x0c0b9704u,0x0c0b9706u,0x0c0b9708u,0x0c0b970au,0x0c0b970cu,0x0c0b970eu,0x0c0b9710u,0x0c0b9712u,0x0c0b9714u,0x0c0b9716u,0x0c0b9718u,0x0c0b971au,0x0c0b971cu,
0x0c0b971eu,0x0c0b9720u,0x0c0b9722u,0x0c0b9724u,0x0c0b9726u,0x0c0b9728u,0x0c0b972au,0x0c0b972cu,0x0c0b972eu,0x0c0b9730u,0x0c0b9732u,0x0c0b9734u,0x0c0b9736u,0x0c0b9738u,0x0c0b973au,0x0c0b973cu,
0x0c0b973eu,0x0c0b9740u,0x0c0b9742u,0x0c0b9744u,0x0c0b9746u,0x0c0b9748u,0x0c0b974au,0x0c0b974cu,0x0c0b974eu,0x0c0b9750u,0x0c0b9752u,0x0c0b9754u,0x0c0b9756u,0x0c0b9758u,0x0c0b975au,0x0c0b975cu,
0x0c0b975eu,0x0c0b9760u,0x0c0b9762u,0x0c0b9764u,0x0c0b9766u,0x0c0b9768u,0x0c0b976au,0x0c0b976cu,0x0c0b976eu,0x0c0b9770u,0x0c0b9772u,0x0c0b9774u,0x0c0b9776u,0x0c0b9778u,0x0c0b977au,0x0c0b977cu,
0x0c0b977eu,0x0c0b9780u,0x0c0b9782u,0x0c0b9784u,0x0c0b9786u,0x0c0b9788u,0x0c0b978au,0x0c0b978cu,0x0c0b978eu,0x0c0b9790u,0x0c0b9792u,0x0c0b9794u,0x0c0b9796u,0x0c0b9798u,0x0c0b979au,0x0c0b979cu,
0x0c0b979eu,0x0c0b97a0u,0x0c0b97a2u,0x0c0b97a4u,0x0c0b97a6u,0x0c0b97a8u,0x0c0b97aau,0x0c0b97acu,0x0c0b97aeu,0x0c0b97b0u,0x0c0b97b2u,0x0c0b97b4u,0x0c0b97b6u,0x0c0b97b8u,0x0c0b97bau,0x0c0b97bcu,
0x0c0b97beu,0x0c0b97c0u,0x0c0b97c2u,0x0c0b97c4u,0x0c0b97c6u,0x0c0b97c8u,0x0c0b97cau,0x0c0b97ccu,0x0c0b97ceu,0x0c0b97d0u,0x0c0b97d2u,0x0c0b97d4u,0x0c0b97d6u,0x0c0b97d8u,0x0c0b97dau,0x0c0b97dcu,
0x0c0b97deu,0x0c0b97e0u,0x0c0b97e2u,0x0c0b97e4u,0x0c0b97e6u,0x0c0b97e8u,0x0c0b97eau,0x0c0b97ecu,0x0c0b97eeu,0x0c0b97f0u,0x0c0b97f2u,0x0c0b97f4u,0x0c0b97f6u,0x0c0b97f8u,0x0c0b97fau,0x0c0b97fcu,
0x0c0b97feu,0x0c0b9800u,0x0c0b9802u,0x0c0b9804u,0x0c0b9806u,0x0c0b9808u,0x0c0b980au,0x0c0b980cu,0x0c0b980eu,0x0c0b9810u,0x0c0b9812u,0x0c0b9814u,0x0c0b9816u,0x0c0b9818u,0x0c0b981au,0x0c0b981cu,
0x0c0b981eu,0x0c0b9820u,0x0c0b9822u,0x0c0b9824u,0x0c0b9826u,0x0c0b9828u,0x0c0b982au,0x0c0b982cu,0x0c0b982eu,0x0c0b9830u,0x0c0b9832u,0x0c0b9834u,0x0c0b9836u,0x0c0b9838u,0x0c0b983au,0x0c0b983cu,
0x0c0b983eu,0x0c0b9840u,0x0c0b9842u,0x0c0b9844u,0x0c0b9846u,0x0c0bbde2u,0x0c0bbde4u,0x0c0bbde6u,0x0c0bbde8u,0x0c0bbdeau,0x0c0bbdecu,0x0c0bbdeeu,0x0c0bbdf0u,0x0c0bbdf2u,0x0c0bbdf4u,0x0c0bbdf6u,
0x0c0bbdf8u,0x0c0bbdfau,0x0c0bbdfcu,0x0c0bbdfeu,0x0c0bbe00u,0x0c0bbe02u,0x0c0bbe04u,0x0c0bbe06u,0x0c0bbe08u,0x0c0bbe0au,0x0c0bbe0cu,0x0c0bbe0eu,0x0c0bbe10u,0x0c0bbe12u,0x0c0bbe14u,0x0c0bbe16u,
0x0c0bbe18u,0x0c0bbe1au,0x0c0bbe1cu,0x0c0bbe1eu,0x0c0bbe20u,0x0c0bbe22u,0x0c0bbe24u,0x0c0bbe26u,0x0c0bbe28u,0x0c0bbe2au,0x0c0bbe2cu,0x0c0bbe2eu,0x0c0bbe30u,0x0c0bbe32u,0x0c0bbe34u,0x0c0bbe36u,
0x0c0bbe38u,0x0c0bbe3au,0x0c0bbe3cu,0x0c0bbe3eu,0x0c0bbe40u,0x0c0bbe42u,0x0c0bbe44u,0x0c0bbe46u,0x0c0bbe48u,0x0c0bbe4au,0x0c0bbe4cu,0x0c0bbe4eu,0x0c0bbe50u,0x0c0bbe52u,0x0c0bbe54u,0x0c0bbe56u,
0x0c0bbe58u,0x0c0bbe5au,0x0c0bbe5cu,0x0c0bbe5eu,0x0c0bbe60u,0x0c0bbe62u,0x0c0bbe64u,0x0c0bbe66u,0x0c0bbe68u,0x0c0bbe6au,0x0c0bbe6cu,0x0c0bbe6eu,0x0c0bbe70u,0x0c0bbe72u,0x0c0bbe74u,0x0c0bbe76u,
0x0c0bbe78u,0x0c0bbe7au,0x0c0bbe7cu,0x0c0bbe7eu,0x0c0bbe80u,0x0c0bbe82u,0x0c0bbe84u,0x0c0bbe86u,0x0c0bbe88u,0x0c0bbe8au,0x0c0bbe8cu,0x0c0bbe8eu,0x0c0bbe90u,0x0c0bbe92u,0x0c0bbe94u,0x0c0bbe96u,
0x0c0bbe98u,0x0c0bbe9au,0x0c0bbe9cu,0x0c0bbe9eu,0x0c0bbea0u,0x0c0bbea2u,0x0c0bbea4u,0x0c0bbea6u,0x0c0bbea8u,0x0c0bbeaau,0x0c0bbeacu,0x0c0bbeaeu,0x0c0bbeb0u,0x0c0bbeb2u,0x0c0bbeb4u,0x0c0bbeb6u,
0x0c0bbeb8u,0x0c0bbebau,0x0c0bbebcu,0x0c0bbebeu,0x0c0bbec0u,0x0c0bbec2u,0x0c0bbec4u,0x0c0bbec6u,0x0c0bbec8u,0x0c0bbecau,0x0c0bbeccu,0x0c0bbeceu,0x0c0bbed0u,0x0c0bbed2u,0x0c0bbed4u,0x0c0bbed6u,
0x0c0bbed8u,0x0c0bbedau,0x0c0bbedcu,0x0c0bbedeu,0x0c0bbee0u,0x0c0bbee2u,0x0c0bbee4u,0x0c0bbee6u,0x0c0bbee8u,0x0c0bbeeau,0x0c0bbeecu,0x0c0bbeeeu,0x0c0bbef0u,0x0c0bbef2u,0x0c0bbef4u,0x0c0bbef6u,
0x0c0bbef8u,0x0c0bbefau,0x0c0bbefcu,0x0c0bbefeu,0x0c0bbf00u,0x0c0bbf02u,0x0c0bbf04u,0x0c0bbf06u,0x0c0bbf08u,0x0c0bbf0au,0x0c0bbf0cu,0x0c0bbf0eu,0x0c0bbf10u,0x0c0bbf12u,0x0c0bbf14u,0x0c0bbf16u,
0x0c0bbf18u,0x0c0bbf1au,0x0c0bbf1cu,0x0c0bbf1eu,0x0c0bbf20u,0x0c0bbf22u,0x0c0bbf24u,0x0c0bbf26u,0x0c0bbf28u,0x0c0bbf2au,0x0c0bbf2cu,0x0c0bbf2eu,0x0c0bbf30u,0x0c0bbf32u,0x0c0bbf34u,0x0c0bbf36u,
0x0c0bbf38u,0x0c0bbfa8u,0x0c0bbfaau,0x0c0bbfacu,0x0c0bbfaeu,0x0c0bbfb0u,0x0c0bbfb2u,0x0c0bbfb4u,0x0c0bbfb6u,0x0c0bbfb8u,0x0c0bbfbau,0x0c0bbfbcu,0x0c0bbfbeu,0x0c0bbfc0u,0x0c0bbfc2u,0x0c0bbfc4u,
0x0c0bbfc6u,0x0c0bbfc8u,0x0c0bbfcau,0x0c0bbfccu,0x0c0bbfceu,0x0c0bbfd0u,0x0c0bbfd2u,0x0c0bbfd4u,0x0c0bbfd6u,0x0c0bbfd8u,0x0c0bbfdau,0x0c0bbfdcu,0x0c0bbfdeu,0x0c0bbfe0u,0x0c0bbfe2u,0x0c0bbfe4u,
0x0c0bbfe6u,0x0c0bbfe8u,0x0c0bbfeau,0x0c0bbfecu,0x0c0bbfeeu,0x0c0bbff0u,0x0c0bbff2u,0x0c0bbff4u,0x0c0bbff6u,0x0c0bbff8u,0x0c0bbffau,0x0c0bbffcu,0x0c0bbffeu,0x0c0bc000u,0x0c0bc002u,0x0c0bc004u,
0x0c0bc006u,0x0c0bc008u,0x0c0bc00au,0x0c0bc00cu,0x0c0bc00eu,0x0c0bc010u,0x0c0bc012u,0x0c0bc014u,0x0c0bc016u,0x0c0bc018u,0x0c0bc01au,0x0c0bc01cu,0x0c0bc01eu,0x0c0bc020u,0x0c0bc022u,0x0c0bc024u,
0x0c0bc026u,0x0c0bc028u,0x0c0bc02au,0x0c0bc02cu,0x0c0bc02eu,0x0c0bc030u,0x0c0bc032u,0x0c0bc034u,0x0c0bc036u,0x0c0bc038u,0x0c0bc03au,0x0c0bc03cu,0x0c0bc03eu,0x0c0bc040u,0x0c0bc042u,0x0c0bc044u,
0x0c0bc046u,0x0c0bc048u,0x0c0bc04au,0x0c0bc04cu,0x0c0bc04eu,0x0c0bc050u,0x0c0bc052u,0x0c0bc054u,0x0c0bc056u,0x0c0bc058u,0x0c0bc05au,0x0c0bc05cu,0x0c0bc05eu,0x0c0bc060u,0x0c0bc062u,0x0c0bc064u,
0x0c0bc066u,0x0c0bc068u,0x0c0bc06au,0x0c0bc06cu,0x0c0bc06eu,0x0c0bc070u,0x0c0bc072u,0x0c0bc074u,0x0c0bc076u,0x0c0bc078u,0x0c0bc07au,0x0c0bc07cu,0x0c0bc07eu,0x0c0bc080u,0x0c0bc082u,0x0c0bc084u,
0x0c0bc086u,0x0c0bc088u,0x0c0bc08au,0x0c0bc08cu,0x0c0bc08eu,0x0c0bc090u,0x0c0bc092u,0x0c0bc094u,0x0c0bc096u,0x0c0bc098u,0x0c0bc09au,0x0c0bc09cu,0x0c0bc09eu,0x0c0bc0a0u,0x0c0bc0a2u,0x0c0bc0a4u,
0x0c0bc0a6u,0x0c0bc0a8u,0x0c0bc0aau,0x0c0bc0acu,0x0c0bc0aeu,0x0c0bc0b0u,0x0c0bc0b2u,0x0c0bc0b4u,0x0c0bc0b6u,0x0c0bc0b8u,0x0c0bc0bau,0x0c0bc0bcu,0x0c0bc0beu,0x0c0bc0c0u,0x0c0bc0c2u,0x0c0bc0c4u,
0x0c0bc0c6u,0x0c0bc0c8u,0x0c0bc0cau,0x0c0bc0ccu,0x0c0bc0ceu,0x0c0bc0d0u,0x0c0bc0d2u,0x0c0bc0d4u,0x0c0bc0d6u,0x0c0bc0d8u,0x0c0bc0dau,0x0c0bc0dcu,0x0c0bc0deu,0x0c0bc0e0u,0x0c0bc0e2u,0x0c0bc0e4u,
0x0c0bc0e6u,0x0c0bc0e8u,0x0c0bc0eau,0x0c0bc0ecu,0x0c0bc0eeu,0x0c0bc0f0u,0x0c0bc0f2u,0x0c0bc0f4u,0x0c0bc0f6u,0x0c0bc0f8u,0x0c0bc0fau,0x0c0bc0fcu,0x0c0bc0feu,0x0c0bc100u,0x0c0bc17au,0x0c0bc17cu,
0x0c0bc17eu,0x0c0bc180u,0x0c0bc182u,0x0c0bc184u,0x0c0bc186u,0x0c0bc188u,0x0c0bc18au,0x0c0bc18cu,0x0c0bc18eu,0x0c0bc190u,0x0c0bc192u,0x0c0bc194u,0x0c0bc196u,0x0c0bc198u,0x0c0bc19au,0x0c0bc19cu,
0x0c0bc19eu,0x0c0bc1a0u,0x0c0bc1a2u,0x0c0bc1a4u,0x0c0bc1a6u,0x0c0bc1a8u,0x0c0bc1aau,0x0c0bc1acu,0x0c0bc1aeu,0x0c0bc1b0u,0x0c0bc1b2u,0x0c0bc1b4u,0x0c0bc1b6u,0x0c0bc1b8u,0x0c0bc1bau,0x0c0bc1bcu,
0x0c0bc1beu,0x0c0bc1c0u,0x0c0bc1c2u,0x0c0bc1c4u,0x0c0bc1c6u,0x0c0bc1c8u,0x0c0bc1cau,0x0c0bc1ccu,0x0c0bc1ceu,0x0c0bc1d0u,0x0c0bc1d2u,0x0c0bc1d4u,0x0c0bc1d6u,0x0c0bc1d8u,0x0c0bc1dau,0x0c0bc1dcu,
0x0c0bc1deu,0x0c0bc1e0u,0x0c0bc1e2u,0x0c0bc1e4u,0x0c0bc1e6u,0x0c0bc1e8u,0x0c0bc1eau,0x0c0bc1ecu,0x0c0bc1eeu,0x0c0bc1f0u,0x0c0bc1f2u,0x0c0bc1f4u,0x0c0bc1f6u,0x0c0bc1f8u,0x0c0bc1fau,0x0c0bc1fcu,
0x0c0bc1feu,0x0c0bc200u,0x0c0bc202u,0x0c0bc204u,0x0c0bc206u,0x0c0bc208u,
};
int vf3_sixth_loader_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
