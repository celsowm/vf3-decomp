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
int vf3_seventh_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03b530u: goto P_0c03b530;
case 0x0c03b532u: goto P_0c03b532;
case 0x0c03b534u: goto P_0c03b534;
case 0x0c03b536u: goto P_0c03b536;
case 0x0c03b538u: goto P_0c03b538;
case 0x0c03b53au: goto P_0c03b53a;
case 0x0c03b53cu: goto P_0c03b53c;
case 0x0c03b53eu: goto P_0c03b53e;
case 0x0c03b540u: goto P_0c03b540;
case 0x0c03b542u: goto P_0c03b542;
case 0x0c03b550u: goto P_0c03b550;
case 0x0c03b552u: goto P_0c03b552;
case 0x0c03b554u: goto P_0c03b554;
case 0x0c03b556u: goto P_0c03b556;
case 0x0c03b558u: goto P_0c03b558;
case 0x0c03b560u: goto P_0c03b560;
case 0x0c03b562u: goto P_0c03b562;
case 0x0c03b564u: goto P_0c03b564;
case 0x0c03b566u: goto P_0c03b566;
case 0x0c03b568u: goto P_0c03b568;
case 0x0c03b56au: goto P_0c03b56a;
case 0x0c03b56cu: goto P_0c03b56c;
case 0x0c03b56eu: goto P_0c03b56e;
case 0x0c03b570u: goto P_0c03b570;
case 0x0c03b572u: goto P_0c03b572;
case 0x0c03c4a0u: goto P_0c03c4a0;
case 0x0c03c4a2u: goto P_0c03c4a2;
case 0x0c03c4a4u: goto P_0c03c4a4;
case 0x0c03c4a6u: goto P_0c03c4a6;
case 0x0c03c4a8u: goto P_0c03c4a8;
case 0x0c03c4aau: goto P_0c03c4aa;
case 0x0c03c4acu: goto P_0c03c4ac;
case 0x0c03c4aeu: goto P_0c03c4ae;
case 0x0c03c4b0u: goto P_0c03c4b0;
case 0x0c03c4b2u: goto P_0c03c4b2;
case 0x0c03c4b4u: goto P_0c03c4b4;
case 0x0c03c4b6u: goto P_0c03c4b6;
case 0x0c03c4b8u: goto P_0c03c4b8;
case 0x0c03c4bau: goto P_0c03c4ba;
case 0x0c03c4bcu: goto P_0c03c4bc;
case 0x0c03c4beu: goto P_0c03c4be;
case 0x0c03c4c0u: goto P_0c03c4c0;
case 0x0c03c4c2u: goto P_0c03c4c2;
case 0x0c03c4c4u: goto P_0c03c4c4;
case 0x0c03c4c6u: goto P_0c03c4c6;
case 0x0c03c4c8u: goto P_0c03c4c8;
case 0x0c03c4cau: goto P_0c03c4ca;
case 0x0c03c4ccu: goto P_0c03c4cc;
case 0x0c03c4ceu: goto P_0c03c4ce;
case 0x0c03c4d0u: goto P_0c03c4d0;
case 0x0c03c4d2u: goto P_0c03c4d2;
case 0x0c03c4d4u: goto P_0c03c4d4;
case 0x0c03c4d6u: goto P_0c03c4d6;
case 0x0c03c4d8u: goto P_0c03c4d8;
case 0x0c03c4dau: goto P_0c03c4da;
case 0x0c03c4dcu: goto P_0c03c4dc;
case 0x0c03c4deu: goto P_0c03c4de;
case 0x0c042d7cu: goto P_0c042d7c;
case 0x0c042d7eu: goto P_0c042d7e;
case 0x0c042d80u: goto P_0c042d80;
case 0x0c042d82u: goto P_0c042d82;
case 0x0c042d84u: goto P_0c042d84;
case 0x0c042d86u: goto P_0c042d86;
case 0x0c042d88u: goto P_0c042d88;
case 0x0c042d8au: goto P_0c042d8a;
case 0x0c042d8cu: goto P_0c042d8c;
case 0x0c042d8eu: goto P_0c042d8e;
case 0x0c042d90u: goto P_0c042d90;
case 0x0c042d92u: goto P_0c042d92;
case 0x0c042d94u: goto P_0c042d94;
case 0x0c042d96u: goto P_0c042d96;
case 0x0c042d98u: goto P_0c042d98;
case 0x0c042d9au: goto P_0c042d9a;
case 0x0c042d9cu: goto P_0c042d9c;
case 0x0c042d9eu: goto P_0c042d9e;
case 0x0c042da0u: goto P_0c042da0;
case 0x0c042da2u: goto P_0c042da2;
case 0x0c042da4u: goto P_0c042da4;
case 0x0c042da6u: goto P_0c042da6;
case 0x0c042da8u: goto P_0c042da8;
case 0x0c042daau: goto P_0c042daa;
case 0x0c042dacu: goto P_0c042dac;
case 0x0c042daeu: goto P_0c042dae;
case 0x0c042db0u: goto P_0c042db0;
case 0x0c042db2u: goto P_0c042db2;
case 0x0c042db4u: goto P_0c042db4;
case 0x0c042db6u: goto P_0c042db6;
case 0x0c042db8u: goto P_0c042db8;
case 0x0c042dbau: goto P_0c042dba;
case 0x0c042dbcu: goto P_0c042dbc;
case 0x0c042dbeu: goto P_0c042dbe;
case 0x0c042dc0u: goto P_0c042dc0;
case 0x0c042dc2u: goto P_0c042dc2;
case 0x0c042dc4u: goto P_0c042dc4;
case 0x0c042dc6u: goto P_0c042dc6;
case 0x0c042dc8u: goto P_0c042dc8;
case 0x0c042dcau: goto P_0c042dca;
case 0x0c042dccu: goto P_0c042dcc;
case 0x0c042dceu: goto P_0c042dce;
case 0x0c042dd0u: goto P_0c042dd0;
case 0x0c042dd2u: goto P_0c042dd2;
case 0x0c042dd4u: goto P_0c042dd4;
case 0x0c042dd6u: goto P_0c042dd6;
case 0x0c042dd8u: goto P_0c042dd8;
case 0x0c042ddau: goto P_0c042dda;
case 0x0c042ddcu: goto P_0c042ddc;
case 0x0c042ddeu: goto P_0c042dde;
case 0x0c042de0u: goto P_0c042de0;
case 0x0c042de2u: goto P_0c042de2;
case 0x0c042de4u: goto P_0c042de4;
case 0x0c042de6u: goto P_0c042de6;
case 0x0c042de8u: goto P_0c042de8;
case 0x0c042deau: goto P_0c042dea;
case 0x0c042decu: goto P_0c042dec;
case 0x0c042deeu: goto P_0c042dee;
case 0x0c042df0u: goto P_0c042df0;
case 0x0c042df2u: goto P_0c042df2;
case 0x0c042df4u: goto P_0c042df4;
case 0x0c042df6u: goto P_0c042df6;
case 0x0c042df8u: goto P_0c042df8;
case 0x0c042dfau: goto P_0c042dfa;
case 0x0c042dfcu: goto P_0c042dfc;
case 0x0c042dfeu: goto P_0c042dfe;
case 0x0c042e00u: goto P_0c042e00;
case 0x0c042e02u: goto P_0c042e02;
case 0x0c042e04u: goto P_0c042e04;
case 0x0c042e06u: goto P_0c042e06;
case 0x0c042e08u: goto P_0c042e08;
case 0x0c042e0au: goto P_0c042e0a;
case 0x0c042e0cu: goto P_0c042e0c;
case 0x0c042e0eu: goto P_0c042e0e;
case 0x0c042e10u: goto P_0c042e10;
case 0x0c042e12u: goto P_0c042e12;
case 0x0c042e14u: goto P_0c042e14;
case 0x0c042e16u: goto P_0c042e16;
case 0x0c042e18u: goto P_0c042e18;
case 0x0c042e1au: goto P_0c042e1a;
case 0x0c042e1cu: goto P_0c042e1c;
case 0x0c042e1eu: goto P_0c042e1e;
case 0x0c042e20u: goto P_0c042e20;
case 0x0c042e22u: goto P_0c042e22;
case 0x0c042e24u: goto P_0c042e24;
case 0x0c042e26u: goto P_0c042e26;
case 0x0c042e28u: goto P_0c042e28;
case 0x0c042e2au: goto P_0c042e2a;
case 0x0c042e2cu: goto P_0c042e2c;
case 0x0c042e2eu: goto P_0c042e2e;
case 0x0c042e30u: goto P_0c042e30;
case 0x0c042e32u: goto P_0c042e32;
case 0x0c042e34u: goto P_0c042e34;
case 0x0c042e36u: goto P_0c042e36;
case 0x0c042e38u: goto P_0c042e38;
case 0x0c042e3au: goto P_0c042e3a;
case 0x0c068d54u: goto P_0c068d54;
case 0x0c068d56u: goto P_0c068d56;
case 0x0c068d58u: goto P_0c068d58;
case 0x0c068d5au: goto P_0c068d5a;
case 0x0c068d5cu: goto P_0c068d5c;
case 0x0c068d5eu: goto P_0c068d5e;
case 0x0c068d60u: goto P_0c068d60;
case 0x0c068d62u: goto P_0c068d62;
case 0x0c068d64u: goto P_0c068d64;
case 0x0c068d66u: goto P_0c068d66;
case 0x0c068d68u: goto P_0c068d68;
case 0x0c068d6au: goto P_0c068d6a;
case 0x0c068d6cu: goto P_0c068d6c;
case 0x0c068d6eu: goto P_0c068d6e;
case 0x0c068d70u: goto P_0c068d70;
case 0x0c068d72u: goto P_0c068d72;
case 0x0c068d74u: goto P_0c068d74;
case 0x0c068d76u: goto P_0c068d76;
case 0x0c068d78u: goto P_0c068d78;
case 0x0c068d7au: goto P_0c068d7a;
case 0x0c068d7cu: goto P_0c068d7c;
case 0x0c068d7eu: goto P_0c068d7e;
case 0x0c068d80u: goto P_0c068d80;
case 0x0c068d82u: goto P_0c068d82;
case 0x0c068d84u: goto P_0c068d84;
case 0x0c068d86u: goto P_0c068d86;
case 0x0c068d88u: goto P_0c068d88;
case 0x0c068d8au: goto P_0c068d8a;
case 0x0c068d8cu: goto P_0c068d8c;
case 0x0c068d8eu: goto P_0c068d8e;
case 0x0c068d90u: goto P_0c068d90;
case 0x0c068d92u: goto P_0c068d92;
case 0x0c068d94u: goto P_0c068d94;
case 0x0c068d96u: goto P_0c068d96;
case 0x0c068d98u: goto P_0c068d98;
case 0x0c068d9au: goto P_0c068d9a;
case 0x0c068d9cu: goto P_0c068d9c;
case 0x0c068d9eu: goto P_0c068d9e;
case 0x0c068da0u: goto P_0c068da0;
case 0x0c068da2u: goto P_0c068da2;
case 0x0c068da4u: goto P_0c068da4;
case 0x0c068da6u: goto P_0c068da6;
case 0x0c068da8u: goto P_0c068da8;
case 0x0c068daau: goto P_0c068daa;
case 0x0c068dacu: goto P_0c068dac;
case 0x0c068daeu: goto P_0c068dae;
case 0x0c068db0u: goto P_0c068db0;
case 0x0c068db2u: goto P_0c068db2;
case 0x0c068db4u: goto P_0c068db4;
case 0x0c068db6u: goto P_0c068db6;
case 0x0c068db8u: goto P_0c068db8;
case 0x0c068dbau: goto P_0c068dba;
case 0x0c068dbcu: goto P_0c068dbc;
case 0x0c068dbeu: goto P_0c068dbe;
case 0x0c068dc0u: goto P_0c068dc0;
case 0x0c068dc2u: goto P_0c068dc2;
case 0x0c068dc4u: goto P_0c068dc4;
case 0x0c068dc6u: goto P_0c068dc6;
case 0x0c068dc8u: goto P_0c068dc8;
case 0x0c068dcau: goto P_0c068dca;
case 0x0c068dccu: goto P_0c068dcc;
case 0x0c068dceu: goto P_0c068dce;
case 0x0c068dd0u: goto P_0c068dd0;
case 0x0c068dd2u: goto P_0c068dd2;
case 0x0c068dd4u: goto P_0c068dd4;
case 0x0c068dd6u: goto P_0c068dd6;
case 0x0c068dd8u: goto P_0c068dd8;
case 0x0c068ddau: goto P_0c068dda;
case 0x0c068ddcu: goto P_0c068ddc;
case 0x0c068ddeu: goto P_0c068dde;
case 0x0c068de0u: goto P_0c068de0;
case 0x0c068de2u: goto P_0c068de2;
case 0x0c068de4u: goto P_0c068de4;
case 0x0c068de6u: goto P_0c068de6;
case 0x0c068de8u: goto P_0c068de8;
case 0x0c068deau: goto P_0c068dea;
case 0x0c068decu: goto P_0c068dec;
case 0x0c068deeu: goto P_0c068dee;
case 0x0c068df0u: goto P_0c068df0;
case 0x0c068df2u: goto P_0c068df2;
case 0x0c068df4u: goto P_0c068df4;
case 0x0c068df6u: goto P_0c068df6;
case 0x0c068df8u: goto P_0c068df8;
case 0x0c068dfau: goto P_0c068dfa;
case 0x0c068dfcu: goto P_0c068dfc;
case 0x0c068dfeu: goto P_0c068dfe;
case 0x0c068e00u: goto P_0c068e00;
case 0x0c068e02u: goto P_0c068e02;
case 0x0c068e04u: goto P_0c068e04;
case 0x0c068e06u: goto P_0c068e06;
case 0x0c068e08u: goto P_0c068e08;
case 0x0c068e0au: goto P_0c068e0a;
case 0x0c068e0cu: goto P_0c068e0c;
case 0x0c068f92u: goto P_0c068f92;
case 0x0c068f94u: goto P_0c068f94;
case 0x0c068f96u: goto P_0c068f96;
case 0x0c068f98u: goto P_0c068f98;
case 0x0c068f9au: goto P_0c068f9a;
case 0x0c068f9cu: goto P_0c068f9c;
case 0x0c068f9eu: goto P_0c068f9e;
case 0x0c068fa0u: goto P_0c068fa0;
case 0x0c068fa2u: goto P_0c068fa2;
case 0x0c068fa4u: goto P_0c068fa4;
case 0x0c068fa6u: goto P_0c068fa6;
case 0x0c068fa8u: goto P_0c068fa8;
case 0x0c068faau: goto P_0c068faa;
case 0x0c068facu: goto P_0c068fac;
case 0x0c068faeu: goto P_0c068fae;
case 0x0c068fb0u: goto P_0c068fb0;
case 0x0c068fb2u: goto P_0c068fb2;
case 0x0c068fb4u: goto P_0c068fb4;
case 0x0c068fb6u: goto P_0c068fb6;
case 0x0c068fb8u: goto P_0c068fb8;
case 0x0c068fbau: goto P_0c068fba;
case 0x0c068fbcu: goto P_0c068fbc;
case 0x0c068fbeu: goto P_0c068fbe;
case 0x0c068fc0u: goto P_0c068fc0;
case 0x0c068fc2u: goto P_0c068fc2;
case 0x0c068fc4u: goto P_0c068fc4;
case 0x0c068fc6u: goto P_0c068fc6;
case 0x0c068fe4u: goto P_0c068fe4;
case 0x0c068fe6u: goto P_0c068fe6;
case 0x0c068fe8u: goto P_0c068fe8;
case 0x0c068feau: goto P_0c068fea;
case 0x0c068fecu: goto P_0c068fec;
case 0x0c068feeu: goto P_0c068fee;
case 0x0c068ff0u: goto P_0c068ff0;
case 0x0c068ff2u: goto P_0c068ff2;
case 0x0c068ff4u: goto P_0c068ff4;
case 0x0c068ff6u: goto P_0c068ff6;
case 0x0c068ff8u: goto P_0c068ff8;
case 0x0c068ffau: goto P_0c068ffa;
case 0x0c068ffcu: goto P_0c068ffc;
case 0x0c068ffeu: goto P_0c068ffe;
case 0x0c069000u: goto P_0c069000;
case 0x0c069002u: goto P_0c069002;
case 0x0c069004u: goto P_0c069004;
case 0x0c069006u: goto P_0c069006;
case 0x0c069008u: goto P_0c069008;
case 0x0c06900au: goto P_0c06900a;
case 0x0c06900cu: goto P_0c06900c;
case 0x0c06900eu: goto P_0c06900e;
case 0x0c069010u: goto P_0c069010;
case 0x0c069012u: goto P_0c069012;
case 0x0c069014u: goto P_0c069014;
case 0x0c069016u: goto P_0c069016;
case 0x0c069018u: goto P_0c069018;
case 0x0c06901au: goto P_0c06901a;
case 0x0c06901cu: goto P_0c06901c;
case 0x0c06901eu: goto P_0c06901e;
case 0x0c069020u: goto P_0c069020;
case 0x0c069022u: goto P_0c069022;
case 0x0c069024u: goto P_0c069024;
case 0x0c069026u: goto P_0c069026;
case 0x0c069028u: goto P_0c069028;
case 0x0c06902au: goto P_0c06902a;
case 0x0c06902cu: goto P_0c06902c;
case 0x0c06902eu: goto P_0c06902e;
case 0x0c069030u: goto P_0c069030;
case 0x0c069032u: goto P_0c069032;
case 0x0c069034u: goto P_0c069034;
case 0x0c069036u: goto P_0c069036;
case 0x0c069038u: goto P_0c069038;
case 0x0c06903au: goto P_0c06903a;
case 0x0c06903cu: goto P_0c06903c;
case 0x0c06903eu: goto P_0c06903e;
case 0x0c069040u: goto P_0c069040;
case 0x0c069042u: goto P_0c069042;
case 0x0c069044u: goto P_0c069044;
case 0x0c069046u: goto P_0c069046;
case 0x0c069048u: goto P_0c069048;
case 0x0c06904au: goto P_0c06904a;
case 0x0c06904cu: goto P_0c06904c;
case 0x0c06904eu: goto P_0c06904e;
case 0x0c069050u: goto P_0c069050;
case 0x0c069052u: goto P_0c069052;
case 0x0c069054u: goto P_0c069054;
case 0x0c069056u: goto P_0c069056;
case 0x0c069058u: goto P_0c069058;
case 0x0c06905au: goto P_0c06905a;
case 0x0c06905cu: goto P_0c06905c;
case 0x0c06905eu: goto P_0c06905e;
case 0x0c069060u: goto P_0c069060;
case 0x0c069062u: goto P_0c069062;
case 0x0c069064u: goto P_0c069064;
case 0x0c069066u: goto P_0c069066;
case 0x0c069068u: goto P_0c069068;
case 0x0c06906au: goto P_0c06906a;
case 0x0c06906cu: goto P_0c06906c;
case 0x0c06906eu: goto P_0c06906e;
case 0x0c069070u: goto P_0c069070;
case 0x0c069072u: goto P_0c069072;
case 0x0c069074u: goto P_0c069074;
case 0x0c069076u: goto P_0c069076;
case 0x0c069078u: goto P_0c069078;
case 0x0c06907au: goto P_0c06907a;
case 0x0c06907cu: goto P_0c06907c;
case 0x0c06907eu: goto P_0c06907e;
case 0x0c069080u: goto P_0c069080;
case 0x0c069082u: goto P_0c069082;
case 0x0c069084u: goto P_0c069084;
case 0x0c069086u: goto P_0c069086;
case 0x0c069088u: goto P_0c069088;
case 0x0c06908au: goto P_0c06908a;
case 0x0c06908cu: goto P_0c06908c;
case 0x0c06908eu: goto P_0c06908e;
case 0x0c069090u: goto P_0c069090;
case 0x0c069092u: goto P_0c069092;
case 0x0c069094u: goto P_0c069094;
case 0x0c069096u: goto P_0c069096;
case 0x0c069098u: goto P_0c069098;
case 0x0c06909au: goto P_0c06909a;
case 0x0c06909cu: goto P_0c06909c;
case 0x0c06909eu: goto P_0c06909e;
case 0x0c0690a0u: goto P_0c0690a0;
case 0x0c0690a2u: goto P_0c0690a2;
case 0x0c0690a4u: goto P_0c0690a4;
case 0x0c0690a6u: goto P_0c0690a6;
case 0x0c0690a8u: goto P_0c0690a8;
case 0x0c0690aau: goto P_0c0690aa;
case 0x0c0690acu: goto P_0c0690ac;
case 0x0c0690aeu: goto P_0c0690ae;
case 0x0c0690b0u: goto P_0c0690b0;
case 0x0c0690b2u: goto P_0c0690b2;
case 0x0c0690b4u: goto P_0c0690b4;
case 0x0c0690b6u: goto P_0c0690b6;
case 0x0c0690b8u: goto P_0c0690b8;
case 0x0c0690bau: goto P_0c0690ba;
case 0x0c0690bcu: goto P_0c0690bc;
case 0x0c0690beu: goto P_0c0690be;
case 0x0c0690c0u: goto P_0c0690c0;
case 0x0c0690c2u: goto P_0c0690c2;
case 0x0c0690c4u: goto P_0c0690c4;
case 0x0c0690c6u: goto P_0c0690c6;
case 0x0c0690c8u: goto P_0c0690c8;
case 0x0c0690cau: goto P_0c0690ca;
case 0x0c0690ccu: goto P_0c0690cc;
case 0x0c0690ceu: goto P_0c0690ce;
case 0x0c0690d0u: goto P_0c0690d0;
case 0x0c0690d2u: goto P_0c0690d2;
case 0x0c0690d4u: goto P_0c0690d4;
case 0x0c0690d6u: goto P_0c0690d6;
case 0x0c0690d8u: goto P_0c0690d8;
case 0x0c0690dau: goto P_0c0690da;
case 0x0c0690dcu: goto P_0c0690dc;
case 0x0c0690deu: goto P_0c0690de;
case 0x0c0690e0u: goto P_0c0690e0;
case 0x0c0690e2u: goto P_0c0690e2;
case 0x0c0690e4u: goto P_0c0690e4;
case 0x0c0690e6u: goto P_0c0690e6;
case 0x0c0690e8u: goto P_0c0690e8;
case 0x0c0690eau: goto P_0c0690ea;
case 0x0c0690ecu: goto P_0c0690ec;
case 0x0c0690eeu: goto P_0c0690ee;
case 0x0c0690f0u: goto P_0c0690f0;
case 0x0c0690f2u: goto P_0c0690f2;
case 0x0c0690f4u: goto P_0c0690f4;
case 0x0c0690f6u: goto P_0c0690f6;
case 0x0c0690f8u: goto P_0c0690f8;
case 0x0c0690fau: goto P_0c0690fa;
case 0x0c0690fcu: goto P_0c0690fc;
case 0x0c0690feu: goto P_0c0690fe;
case 0x0c069100u: goto P_0c069100;
case 0x0c069102u: goto P_0c069102;
case 0x0c069104u: goto P_0c069104;
case 0x0c069106u: goto P_0c069106;
case 0x0c069108u: goto P_0c069108;
case 0x0c06910au: goto P_0c06910a;
case 0x0c06910cu: goto P_0c06910c;
case 0x0c06910eu: goto P_0c06910e;
case 0x0c069110u: goto P_0c069110;
case 0x0c069112u: goto P_0c069112;
case 0x0c069114u: goto P_0c069114;
case 0x0c06911cu: goto P_0c06911c;
case 0x0c06911eu: goto P_0c06911e;
case 0x0c069120u: goto P_0c069120;
case 0x0c069122u: goto P_0c069122;
case 0x0c069124u: goto P_0c069124;
case 0x0c069126u: goto P_0c069126;
case 0x0c069128u: goto P_0c069128;
case 0x0c06912au: goto P_0c06912a;
case 0x0c06912cu: goto P_0c06912c;
case 0x0c06912eu: goto P_0c06912e;
case 0x0c069130u: goto P_0c069130;
case 0x0c069132u: goto P_0c069132;
case 0x0c069134u: goto P_0c069134;
case 0x0c069136u: goto P_0c069136;
case 0x0c069138u: goto P_0c069138;
case 0x0c06913au: goto P_0c06913a;
case 0x0c06913cu: goto P_0c06913c;
case 0x0c06913eu: goto P_0c06913e;
case 0x0c069140u: goto P_0c069140;
case 0x0c069142u: goto P_0c069142;
case 0x0c069144u: goto P_0c069144;
case 0x0c069146u: goto P_0c069146;
case 0x0c069148u: goto P_0c069148;
case 0x0c06914au: goto P_0c06914a;
case 0x0c06914cu: goto P_0c06914c;
case 0x0c06914eu: goto P_0c06914e;
case 0x0c069150u: goto P_0c069150;
case 0x0c069152u: goto P_0c069152;
case 0x0c069154u: goto P_0c069154;
case 0x0c069156u: goto P_0c069156;
case 0x0c069158u: goto P_0c069158;
case 0x0c06915au: goto P_0c06915a;
case 0x0c06915cu: goto P_0c06915c;
case 0x0c06915eu: goto P_0c06915e;
case 0x0c069160u: goto P_0c069160;
case 0x0c069162u: goto P_0c069162;
case 0x0c069164u: goto P_0c069164;
case 0x0c069166u: goto P_0c069166;
case 0x0c069168u: goto P_0c069168;
case 0x0c06916au: goto P_0c06916a;
case 0x0c06916cu: goto P_0c06916c;
case 0x0c06916eu: goto P_0c06916e;
case 0x0c069170u: goto P_0c069170;
case 0x0c069172u: goto P_0c069172;
case 0x0c069174u: goto P_0c069174;
case 0x0c069176u: goto P_0c069176;
case 0x0c069178u: goto P_0c069178;
case 0x0c06917au: goto P_0c06917a;
case 0x0c06917cu: goto P_0c06917c;
case 0x0c06917eu: goto P_0c06917e;
case 0x0c069180u: goto P_0c069180;
case 0x0c069182u: goto P_0c069182;
case 0x0c069184u: goto P_0c069184;
case 0x0c069186u: goto P_0c069186;
case 0x0c069188u: goto P_0c069188;
case 0x0c06918au: goto P_0c06918a;
case 0x0c06918cu: goto P_0c06918c;
case 0x0c06918eu: goto P_0c06918e;
case 0x0c069190u: goto P_0c069190;
case 0x0c069192u: goto P_0c069192;
case 0x0c069194u: goto P_0c069194;
case 0x0c069196u: goto P_0c069196;
case 0x0c069198u: goto P_0c069198;
case 0x0c06919au: goto P_0c06919a;
case 0x0c06919cu: goto P_0c06919c;
case 0x0c06919eu: goto P_0c06919e;
case 0x0c0691a0u: goto P_0c0691a0;
case 0x0c0691a2u: goto P_0c0691a2;
case 0x0c0691a4u: goto P_0c0691a4;
case 0x0c0691a6u: goto P_0c0691a6;
case 0x0c0691a8u: goto P_0c0691a8;
case 0x0c0691aau: goto P_0c0691aa;
case 0x0c0691acu: goto P_0c0691ac;
case 0x0c0691aeu: goto P_0c0691ae;
case 0x0c0691b0u: goto P_0c0691b0;
case 0x0c0691b2u: goto P_0c0691b2;
case 0x0c0691b4u: goto P_0c0691b4;
case 0x0c0691b6u: goto P_0c0691b6;
case 0x0c0691b8u: goto P_0c0691b8;
case 0x0c0691bau: goto P_0c0691ba;
case 0x0c0691bcu: goto P_0c0691bc;
case 0x0c0691beu: goto P_0c0691be;
case 0x0c0691c0u: goto P_0c0691c0;
case 0x0c0691c2u: goto P_0c0691c2;
case 0x0c0691c4u: goto P_0c0691c4;
case 0x0c0691c6u: goto P_0c0691c6;
case 0x0c0691c8u: goto P_0c0691c8;
case 0x0c0691cau: goto P_0c0691ca;
case 0x0c0691ccu: goto P_0c0691cc;
case 0x0c0691ceu: goto P_0c0691ce;
case 0x0c0691d0u: goto P_0c0691d0;
case 0x0c0691d2u: goto P_0c0691d2;
case 0x0c0691d4u: goto P_0c0691d4;
case 0x0c0691d6u: goto P_0c0691d6;
case 0x0c0691d8u: goto P_0c0691d8;
case 0x0c0691dau: goto P_0c0691da;
case 0x0c0691dcu: goto P_0c0691dc;
case 0x0c0691deu: goto P_0c0691de;
case 0x0c0691e0u: goto P_0c0691e0;
case 0x0c0691e2u: goto P_0c0691e2;
case 0x0c0691e4u: goto P_0c0691e4;
case 0x0c0691e6u: goto P_0c0691e6;
case 0x0c0691e8u: goto P_0c0691e8;
case 0x0c0691eau: goto P_0c0691ea;
case 0x0c0691ecu: goto P_0c0691ec;
case 0x0c0691eeu: goto P_0c0691ee;
case 0x0c0691f0u: goto P_0c0691f0;
case 0x0c0691f2u: goto P_0c0691f2;
case 0x0c0691f4u: goto P_0c0691f4;
case 0x0c0691f6u: goto P_0c0691f6;
case 0x0c0691f8u: goto P_0c0691f8;
case 0x0c0691fau: goto P_0c0691fa;
case 0x0c0691fcu: goto P_0c0691fc;
case 0x0c0691feu: goto P_0c0691fe;
case 0x0c069200u: goto P_0c069200;
case 0x0c069202u: goto P_0c069202;
case 0x0c069204u: goto P_0c069204;
case 0x0c069206u: goto P_0c069206;
case 0x0c069208u: goto P_0c069208;
case 0x0c06920au: goto P_0c06920a;
case 0x0c06920cu: goto P_0c06920c;
case 0x0c06920eu: goto P_0c06920e;
case 0x0c069210u: goto P_0c069210;
case 0x0c069212u: goto P_0c069212;
case 0x0c069214u: goto P_0c069214;
case 0x0c069216u: goto P_0c069216;
case 0x0c069218u: goto P_0c069218;
case 0x0c06921au: goto P_0c06921a;
case 0x0c06921cu: goto P_0c06921c;
case 0x0c06923cu: goto P_0c06923c;
case 0x0c06923eu: goto P_0c06923e;
case 0x0c069240u: goto P_0c069240;
case 0x0c069242u: goto P_0c069242;
case 0x0c069244u: goto P_0c069244;
case 0x0c069246u: goto P_0c069246;
case 0x0c069248u: goto P_0c069248;
case 0x0c06924au: goto P_0c06924a;
case 0x0c06924cu: goto P_0c06924c;
case 0x0c06924eu: goto P_0c06924e;
case 0x0c069250u: goto P_0c069250;
case 0x0c069252u: goto P_0c069252;
case 0x0c069254u: goto P_0c069254;
case 0x0c069256u: goto P_0c069256;
case 0x0c069258u: goto P_0c069258;
case 0x0c06925au: goto P_0c06925a;
case 0x0c06925cu: goto P_0c06925c;
case 0x0c06925eu: goto P_0c06925e;
case 0x0c069260u: goto P_0c069260;
case 0x0c069262u: goto P_0c069262;
case 0x0c069264u: goto P_0c069264;
case 0x0c069266u: goto P_0c069266;
case 0x0c069268u: goto P_0c069268;
case 0x0c06926au: goto P_0c06926a;
case 0x0c06926cu: goto P_0c06926c;
case 0x0c06926eu: goto P_0c06926e;
case 0x0c069270u: goto P_0c069270;
case 0x0c069272u: goto P_0c069272;
case 0x0c069274u: goto P_0c069274;
case 0x0c069276u: goto P_0c069276;
case 0x0c069278u: goto P_0c069278;
case 0x0c06927au: goto P_0c06927a;
case 0x0c06927cu: goto P_0c06927c;
case 0x0c06927eu: goto P_0c06927e;
case 0x0c069280u: goto P_0c069280;
case 0x0c069282u: goto P_0c069282;
case 0x0c069284u: goto P_0c069284;
case 0x0c069286u: goto P_0c069286;
case 0x0c069288u: goto P_0c069288;
case 0x0c06928au: goto P_0c06928a;
case 0x0c06928cu: goto P_0c06928c;
case 0x0c06928eu: goto P_0c06928e;
case 0x0c069290u: goto P_0c069290;
case 0x0c069292u: goto P_0c069292;
case 0x0c069294u: goto P_0c069294;
case 0x0c069296u: goto P_0c069296;
case 0x0c069298u: goto P_0c069298;
case 0x0c06929au: goto P_0c06929a;
case 0x0c06929cu: goto P_0c06929c;
case 0x0c06929eu: goto P_0c06929e;
case 0x0c0692a0u: goto P_0c0692a0;
case 0x0c0692a2u: goto P_0c0692a2;
case 0x0c0692a4u: goto P_0c0692a4;
case 0x0c06f6aeu: goto P_0c06f6ae;
case 0x0c06f6b0u: goto P_0c06f6b0;
case 0x0c06f6b2u: goto P_0c06f6b2;
case 0x0c06f6b4u: goto P_0c06f6b4;
case 0x0c06f6b6u: goto P_0c06f6b6;
case 0x0c06f6b8u: goto P_0c06f6b8;
case 0x0c06f6bau: goto P_0c06f6ba;
case 0x0c06f6bcu: goto P_0c06f6bc;
case 0x0c06f6beu: goto P_0c06f6be;
case 0x0c06f6c0u: goto P_0c06f6c0;
case 0x0c06f6c2u: goto P_0c06f6c2;
case 0x0c06f6c4u: goto P_0c06f6c4;
case 0x0c06f6c6u: goto P_0c06f6c6;
case 0x0c06f6c8u: goto P_0c06f6c8;
case 0x0c06f6cau: goto P_0c06f6ca;
case 0x0c06f6ccu: goto P_0c06f6cc;
case 0x0c06f6ceu: goto P_0c06f6ce;
case 0x0c06f6d0u: goto P_0c06f6d0;
case 0x0c06f6e0u: goto P_0c06f6e0;
case 0x0c06f6e2u: goto P_0c06f6e2;
case 0x0c06f6e4u: goto P_0c06f6e4;
case 0x0c06f6e6u: goto P_0c06f6e6;
case 0x0c06f6e8u: goto P_0c06f6e8;
case 0x0c06f6eau: goto P_0c06f6ea;
case 0x0c06f6ecu: goto P_0c06f6ec;
case 0x0c06f6eeu: goto P_0c06f6ee;
case 0x0c06f6f0u: goto P_0c06f6f0;
case 0x0c06f6f2u: goto P_0c06f6f2;
case 0x0c06f6f4u: goto P_0c06f6f4;
case 0x0c06f6f6u: goto P_0c06f6f6;
case 0x0c06f6f8u: goto P_0c06f6f8;
case 0x0c06f6fau: goto P_0c06f6fa;
case 0x0c06f6fcu: goto P_0c06f6fc;
case 0x0c06f6feu: goto P_0c06f6fe;
case 0x0c06f700u: goto P_0c06f700;
case 0x0c06f702u: goto P_0c06f702;
case 0x0c06f704u: goto P_0c06f704;
case 0x0c06f706u: goto P_0c06f706;
case 0x0c06f708u: goto P_0c06f708;
case 0x0c06f70au: goto P_0c06f70a;
case 0x0c06f70cu: goto P_0c06f70c;
case 0x0c06f70eu: goto P_0c06f70e;
case 0x0c06f710u: goto P_0c06f710;
case 0x0c06f712u: goto P_0c06f712;
case 0x0c06f714u: goto P_0c06f714;
case 0x0c06f716u: goto P_0c06f716;
case 0x0c06f718u: goto P_0c06f718;
case 0x0c06f71au: goto P_0c06f71a;
case 0x0c06f71cu: goto P_0c06f71c;
case 0x0c06f71eu: goto P_0c06f71e;
case 0x0c06f720u: goto P_0c06f720;
case 0x0c06f722u: goto P_0c06f722;
case 0x0c06f724u: goto P_0c06f724;
case 0x0c06f726u: goto P_0c06f726;
case 0x0c06f728u: goto P_0c06f728;
case 0x0c06f72au: goto P_0c06f72a;
case 0x0c06f72cu: goto P_0c06f72c;
case 0x0c06f72eu: goto P_0c06f72e;
case 0x0c06f730u: goto P_0c06f730;
case 0x0c06f732u: goto P_0c06f732;
case 0x0c06f734u: goto P_0c06f734;
case 0x0c06f740u: goto P_0c06f740;
case 0x0c06f742u: goto P_0c06f742;
case 0x0c06f744u: goto P_0c06f744;
case 0x0c06f746u: goto P_0c06f746;
case 0x0c06f748u: goto P_0c06f748;
case 0x0c06f74au: goto P_0c06f74a;
case 0x0c06f74cu: goto P_0c06f74c;
case 0x0c06f74eu: goto P_0c06f74e;
case 0x0c06f750u: goto P_0c06f750;
case 0x0c06f752u: goto P_0c06f752;
case 0x0c06f754u: goto P_0c06f754;
case 0x0c06f756u: goto P_0c06f756;
case 0x0c06f758u: goto P_0c06f758;
case 0x0c06f75au: goto P_0c06f75a;
case 0x0c06f75cu: goto P_0c06f75c;
case 0x0c06f75eu: goto P_0c06f75e;
case 0x0c06f760u: goto P_0c06f760;
case 0x0c06f762u: goto P_0c06f762;
case 0x0c06f764u: goto P_0c06f764;
case 0x0c06f766u: goto P_0c06f766;
case 0x0c06f768u: goto P_0c06f768;
case 0x0c06f76au: goto P_0c06f76a;
case 0x0c06f76cu: goto P_0c06f76c;
case 0x0c06f76eu: goto P_0c06f76e;
case 0x0c06f770u: goto P_0c06f770;
case 0x0c06f772u: goto P_0c06f772;
case 0x0c06f774u: goto P_0c06f774;
case 0x0c06f776u: goto P_0c06f776;
case 0x0c06f778u: goto P_0c06f778;
case 0x0c06f77au: goto P_0c06f77a;
case 0x0c06f77cu: goto P_0c06f77c;
case 0x0c06f77eu: goto P_0c06f77e;
case 0x0c06f780u: goto P_0c06f780;
case 0x0c06f782u: goto P_0c06f782;
case 0x0c06f784u: goto P_0c06f784;
case 0x0c06f786u: goto P_0c06f786;
case 0x0c06f788u: goto P_0c06f788;
case 0x0c06f78au: goto P_0c06f78a;
case 0x0c06f78cu: goto P_0c06f78c;
case 0x0c06f78eu: goto P_0c06f78e;
case 0x0c06f790u: goto P_0c06f790;
case 0x0c06f792u: goto P_0c06f792;
case 0x0c06f794u: goto P_0c06f794;
case 0x0c06f796u: goto P_0c06f796;
case 0x0c06f798u: goto P_0c06f798;
case 0x0c06f79au: goto P_0c06f79a;
case 0x0c06f79cu: goto P_0c06f79c;
case 0x0c06f79eu: goto P_0c06f79e;
case 0x0c06f7a0u: goto P_0c06f7a0;
case 0x0c06f7a2u: goto P_0c06f7a2;
case 0x0c06f7a4u: goto P_0c06f7a4;
case 0x0c06f7a6u: goto P_0c06f7a6;
case 0x0c06f7a8u: goto P_0c06f7a8;
case 0x0c06f7aau: goto P_0c06f7aa;
case 0x0c06f7acu: goto P_0c06f7ac;
case 0x0c06f7aeu: goto P_0c06f7ae;
case 0x0c06f7b0u: goto P_0c06f7b0;
case 0x0c06f7b2u: goto P_0c06f7b2;
case 0x0c06f7b4u: goto P_0c06f7b4;
case 0x0c06f7b6u: goto P_0c06f7b6;
case 0x0c06f7b8u: goto P_0c06f7b8;
case 0x0c06f7bau: goto P_0c06f7ba;
case 0x0c06f7bcu: goto P_0c06f7bc;
case 0x0c06f7beu: goto P_0c06f7be;
case 0x0c06f7c0u: goto P_0c06f7c0;
case 0x0c06f7c2u: goto P_0c06f7c2;
case 0x0c06f7c4u: goto P_0c06f7c4;
case 0x0c06f7c6u: goto P_0c06f7c6;
case 0x0c06f7c8u: goto P_0c06f7c8;
case 0x0c06f7cau: goto P_0c06f7ca;
case 0x0c06f7ccu: goto P_0c06f7cc;
case 0x0c06f7ceu: goto P_0c06f7ce;
case 0x0c06f7d0u: goto P_0c06f7d0;
case 0x0c06f7d2u: goto P_0c06f7d2;
case 0x0c06f7d4u: goto P_0c06f7d4;
case 0x0c06f7d6u: goto P_0c06f7d6;
case 0x0c06f7d8u: goto P_0c06f7d8;
case 0x0c06f7dau: goto P_0c06f7da;
case 0x0c06f7dcu: goto P_0c06f7dc;
case 0x0c06f7deu: goto P_0c06f7de;
case 0x0c06f7e0u: goto P_0c06f7e0;
case 0x0c06f7e2u: goto P_0c06f7e2;
case 0x0c06f7e4u: goto P_0c06f7e4;
case 0x0c06f7e6u: goto P_0c06f7e6;
case 0x0c06f7e8u: goto P_0c06f7e8;
case 0x0c06f7eau: goto P_0c06f7ea;
case 0x0c06f7ecu: goto P_0c06f7ec;
case 0x0c06f7eeu: goto P_0c06f7ee;
case 0x0c06f7f0u: goto P_0c06f7f0;
case 0x0c06f7f2u: goto P_0c06f7f2;
case 0x0c06f7f4u: goto P_0c06f7f4;
case 0x0c06f7f6u: goto P_0c06f7f6;
case 0x0c06f7f8u: goto P_0c06f7f8;
case 0x0c06f7fau: goto P_0c06f7fa;
case 0x0c06f7fcu: goto P_0c06f7fc;
case 0x0c06f7feu: goto P_0c06f7fe;
case 0x0c06f800u: goto P_0c06f800;
case 0x0c06f802u: goto P_0c06f802;
case 0x0c06f804u: goto P_0c06f804;
case 0x0c06f806u: goto P_0c06f806;
case 0x0c06f808u: goto P_0c06f808;
case 0x0c06f80au: goto P_0c06f80a;
case 0x0c06f80cu: goto P_0c06f80c;
case 0x0c06f80eu: goto P_0c06f80e;
case 0x0c06f810u: goto P_0c06f810;
case 0x0c06f812u: goto P_0c06f812;
case 0x0c06f814u: goto P_0c06f814;
case 0x0c06f816u: goto P_0c06f816;
case 0x0c06f818u: goto P_0c06f818;
case 0x0c06f81au: goto P_0c06f81a;
case 0x0c06f81cu: goto P_0c06f81c;
case 0x0c06f81eu: goto P_0c06f81e;
case 0x0c06f820u: goto P_0c06f820;
case 0x0c06f822u: goto P_0c06f822;
case 0x0c06f824u: goto P_0c06f824;
case 0x0c06f826u: goto P_0c06f826;
case 0x0c06f828u: goto P_0c06f828;
case 0x0c06f82au: goto P_0c06f82a;
case 0x0c06f82cu: goto P_0c06f82c;
case 0x0c06f82eu: goto P_0c06f82e;
case 0x0c06f830u: goto P_0c06f830;
case 0x0c06f832u: goto P_0c06f832;
case 0x0c06f834u: goto P_0c06f834;
case 0x0c06f836u: goto P_0c06f836;
case 0x0c06f838u: goto P_0c06f838;
case 0x0c06f83au: goto P_0c06f83a;
case 0x0c06f83cu: goto P_0c06f83c;
case 0x0c06f83eu: goto P_0c06f83e;
case 0x0c06f840u: goto P_0c06f840;
case 0x0c06f842u: goto P_0c06f842;
case 0x0c06f844u: goto P_0c06f844;
case 0x0c06f846u: goto P_0c06f846;
case 0x0c06f848u: goto P_0c06f848;
case 0x0c06f84au: goto P_0c06f84a;
case 0x0c06f84cu: goto P_0c06f84c;
case 0x0c06f84eu: goto P_0c06f84e;
case 0x0c06f850u: goto P_0c06f850;
case 0x0c06f852u: goto P_0c06f852;
case 0x0c06f854u: goto P_0c06f854;
case 0x0c06f856u: goto P_0c06f856;
case 0x0c06f858u: goto P_0c06f858;
case 0x0c06f85au: goto P_0c06f85a;
case 0x0c06f85cu: goto P_0c06f85c;
case 0x0c06f85eu: goto P_0c06f85e;
case 0x0c06f860u: goto P_0c06f860;
case 0x0c06f862u: goto P_0c06f862;
case 0x0c06f864u: goto P_0c06f864;
case 0x0c06f866u: goto P_0c06f866;
case 0x0c06f868u: goto P_0c06f868;
case 0x0c06f86au: goto P_0c06f86a;
case 0x0c06f86cu: goto P_0c06f86c;
case 0x0c06f86eu: goto P_0c06f86e;
case 0x0c06f870u: goto P_0c06f870;
case 0x0c06f872u: goto P_0c06f872;
case 0x0c06f874u: goto P_0c06f874;
case 0x0c06f876u: goto P_0c06f876;
case 0x0c06f878u: goto P_0c06f878;
case 0x0c06f87au: goto P_0c06f87a;
case 0x0c06f87cu: goto P_0c06f87c;
case 0x0c06f87eu: goto P_0c06f87e;
case 0x0c06f880u: goto P_0c06f880;
case 0x0c06f882u: goto P_0c06f882;
case 0x0c06f884u: goto P_0c06f884;
case 0x0c06f886u: goto P_0c06f886;
case 0x0c06f888u: goto P_0c06f888;
case 0x0c06f88au: goto P_0c06f88a;
case 0x0c06f88cu: goto P_0c06f88c;
case 0x0c06f88eu: goto P_0c06f88e;
case 0x0c06f890u: goto P_0c06f890;
case 0x0c06f892u: goto P_0c06f892;
case 0x0c06f894u: goto P_0c06f894;
case 0x0c06f896u: goto P_0c06f896;
case 0x0c06f898u: goto P_0c06f898;
case 0x0c06f89au: goto P_0c06f89a;
case 0x0c06f89cu: goto P_0c06f89c;
case 0x0c06f89eu: goto P_0c06f89e;
case 0x0c06f8a0u: goto P_0c06f8a0;
case 0x0c06f8a2u: goto P_0c06f8a2;
case 0x0c06f8a4u: goto P_0c06f8a4;
case 0x0c06f8a6u: goto P_0c06f8a6;
case 0x0c06f8a8u: goto P_0c06f8a8;
case 0x0c06f8aau: goto P_0c06f8aa;
case 0x0c06f8acu: goto P_0c06f8ac;
case 0x0c06f8aeu: goto P_0c06f8ae;
case 0x0c06f8b0u: goto P_0c06f8b0;
case 0x0c06f8b2u: goto P_0c06f8b2;
case 0x0c06f8b4u: goto P_0c06f8b4;
case 0x0c06f8b6u: goto P_0c06f8b6;
case 0x0c06f8b8u: goto P_0c06f8b8;
case 0x0c06f8bau: goto P_0c06f8ba;
case 0x0c06f8bcu: goto P_0c06f8bc;
case 0x0c06f8beu: goto P_0c06f8be;
case 0x0c06f8c0u: goto P_0c06f8c0;
case 0x0c06f8c2u: goto P_0c06f8c2;
case 0x0c06f8c4u: goto P_0c06f8c4;
case 0x0c06f8c6u: goto P_0c06f8c6;
case 0x0c06f8c8u: goto P_0c06f8c8;
case 0x0c06f8cau: goto P_0c06f8ca;
case 0x0c06f8ccu: goto P_0c06f8cc;
case 0x0c06f8ceu: goto P_0c06f8ce;
case 0x0c06f8d0u: goto P_0c06f8d0;
case 0x0c06f8d2u: goto P_0c06f8d2;
case 0x0c06f8d4u: goto P_0c06f8d4;
case 0x0c06f8d6u: goto P_0c06f8d6;
case 0x0c06f8d8u: goto P_0c06f8d8;
case 0x0c06f8dau: goto P_0c06f8da;
case 0x0c06f8dcu: goto P_0c06f8dc;
case 0x0c06f8deu: goto P_0c06f8de;
case 0x0c06f8e0u: goto P_0c06f8e0;
case 0x0c06f8e2u: goto P_0c06f8e2;
case 0x0c06f8e4u: goto P_0c06f8e4;
case 0x0c06f8e6u: goto P_0c06f8e6;
case 0x0c06f8e8u: goto P_0c06f8e8;
case 0x0c06f8eau: goto P_0c06f8ea;
case 0x0c06f8ecu: goto P_0c06f8ec;
case 0x0c06f8eeu: goto P_0c06f8ee;
case 0x0c06f8f0u: goto P_0c06f8f0;
case 0x0c06f8f2u: goto P_0c06f8f2;
case 0x0c06f8f4u: goto P_0c06f8f4;
case 0x0c06f8f6u: goto P_0c06f8f6;
case 0x0c06f8f8u: goto P_0c06f8f8;
case 0x0c06f8fau: goto P_0c06f8fa;
case 0x0c06f8fcu: goto P_0c06f8fc;
case 0x0c06f8feu: goto P_0c06f8fe;
case 0x0c06f900u: goto P_0c06f900;
case 0x0c06f902u: goto P_0c06f902;
case 0x0c06f904u: goto P_0c06f904;
case 0x0c06f906u: goto P_0c06f906;
case 0x0c06f908u: goto P_0c06f908;
case 0x0c06f90au: goto P_0c06f90a;
case 0x0c06f90cu: goto P_0c06f90c;
case 0x0c06f90eu: goto P_0c06f90e;
case 0x0c06f910u: goto P_0c06f910;
case 0x0c06f912u: goto P_0c06f912;
case 0x0c06f914u: goto P_0c06f914;
case 0x0c06f916u: goto P_0c06f916;
case 0x0c06f918u: goto P_0c06f918;
case 0x0c06f91au: goto P_0c06f91a;
case 0x0c06f91cu: goto P_0c06f91c;
case 0x0c06f91eu: goto P_0c06f91e;
case 0x0c06f920u: goto P_0c06f920;
case 0x0c06f922u: goto P_0c06f922;
case 0x0c06f924u: goto P_0c06f924;
case 0x0c06f926u: goto P_0c06f926;
case 0x0c06f928u: goto P_0c06f928;
case 0x0c06f92au: goto P_0c06f92a;
case 0x0c06f92cu: goto P_0c06f92c;
case 0x0c06f92eu: goto P_0c06f92e;
case 0x0c06f930u: goto P_0c06f930;
case 0x0c06f932u: goto P_0c06f932;
case 0x0c06f934u: goto P_0c06f934;
case 0x0c06f936u: goto P_0c06f936;
case 0x0c06f938u: goto P_0c06f938;
case 0x0c06f93au: goto P_0c06f93a;
case 0x0c06f93cu: goto P_0c06f93c;
case 0x0c06f93eu: goto P_0c06f93e;
case 0x0c06f940u: goto P_0c06f940;
case 0x0c06f942u: goto P_0c06f942;
case 0x0c06f944u: goto P_0c06f944;
case 0x0c06f946u: goto P_0c06f946;
case 0x0c06f948u: goto P_0c06f948;
case 0x0c06f94au: goto P_0c06f94a;
case 0x0c06f94cu: goto P_0c06f94c;
case 0x0c06f94eu: goto P_0c06f94e;
case 0x0c06f950u: goto P_0c06f950;
case 0x0c06f952u: goto P_0c06f952;
case 0x0c06f954u: goto P_0c06f954;
case 0x0c06f956u: goto P_0c06f956;
case 0x0c06f958u: goto P_0c06f958;
case 0x0c06f95au: goto P_0c06f95a;
case 0x0c06f95cu: goto P_0c06f95c;
case 0x0c06f95eu: goto P_0c06f95e;
case 0x0c06f960u: goto P_0c06f960;
case 0x0c06f962u: goto P_0c06f962;
case 0x0c06f964u: goto P_0c06f964;
case 0x0c06f966u: goto P_0c06f966;
case 0x0c06f968u: goto P_0c06f968;
case 0x0c06f96au: goto P_0c06f96a;
case 0x0c06f96cu: goto P_0c06f96c;
case 0x0c06f96eu: goto P_0c06f96e;
case 0x0c06f970u: goto P_0c06f970;
case 0x0c06f972u: goto P_0c06f972;
case 0x0c06f974u: goto P_0c06f974;
case 0x0c06f976u: goto P_0c06f976;
case 0x0c06f978u: goto P_0c06f978;
case 0x0c06f97au: goto P_0c06f97a;
case 0x0c06f97cu: goto P_0c06f97c;
case 0x0c06f97eu: goto P_0c06f97e;
case 0x0c06f980u: goto P_0c06f980;
case 0x0c06f982u: goto P_0c06f982;
case 0x0c06f984u: goto P_0c06f984;
case 0x0c06f986u: goto P_0c06f986;
case 0x0c06f988u: goto P_0c06f988;
case 0x0c06f98au: goto P_0c06f98a;
case 0x0c06f98cu: goto P_0c06f98c;
case 0x0c06f98eu: goto P_0c06f98e;
case 0x0c06f990u: goto P_0c06f990;
case 0x0c070008u: goto P_0c070008;
case 0x0c07000au: goto P_0c07000a;
case 0x0c07000cu: goto P_0c07000c;
case 0x0c07000eu: goto P_0c07000e;
case 0x0c070010u: goto P_0c070010;
case 0x0c070012u: goto P_0c070012;
case 0x0c070014u: goto P_0c070014;
case 0x0c070016u: goto P_0c070016;
case 0x0c070018u: goto P_0c070018;
case 0x0c07001au: goto P_0c07001a;
case 0x0c07001cu: goto P_0c07001c;
case 0x0c07001eu: goto P_0c07001e;
case 0x0c070020u: goto P_0c070020;
case 0x0c070022u: goto P_0c070022;
case 0x0c070024u: goto P_0c070024;
case 0x0c070026u: goto P_0c070026;
case 0x0c070028u: goto P_0c070028;
case 0x0c07002au: goto P_0c07002a;
case 0x0c07002cu: goto P_0c07002c;
case 0x0c07002eu: goto P_0c07002e;
case 0x0c070030u: goto P_0c070030;
case 0x0c070032u: goto P_0c070032;
case 0x0c070034u: goto P_0c070034;
case 0x0c070036u: goto P_0c070036;
case 0x0c070038u: goto P_0c070038;
case 0x0c07003au: goto P_0c07003a;
case 0x0c07003cu: goto P_0c07003c;
case 0x0c07003eu: goto P_0c07003e;
case 0x0c070040u: goto P_0c070040;
case 0x0c070042u: goto P_0c070042;
case 0x0c070044u: goto P_0c070044;
case 0x0c070046u: goto P_0c070046;
case 0x0c070048u: goto P_0c070048;
case 0x0c07004au: goto P_0c07004a;
case 0x0c07004cu: goto P_0c07004c;
case 0x0c07004eu: goto P_0c07004e;
case 0x0c070050u: goto P_0c070050;
case 0x0c070052u: goto P_0c070052;
case 0x0c070054u: goto P_0c070054;
case 0x0c070056u: goto P_0c070056;
case 0x0c070058u: goto P_0c070058;
case 0x0c07005au: goto P_0c07005a;
case 0x0c07005cu: goto P_0c07005c;
case 0x0c07005eu: goto P_0c07005e;
case 0x0c070060u: goto P_0c070060;
case 0x0c070088u: goto P_0c070088;
case 0x0c07008au: goto P_0c07008a;
case 0x0c07008cu: goto P_0c07008c;
case 0x0c07008eu: goto P_0c07008e;
case 0x0c070090u: goto P_0c070090;
case 0x0c070092u: goto P_0c070092;
case 0x0c070094u: goto P_0c070094;
case 0x0c070096u: goto P_0c070096;
case 0x0c070098u: goto P_0c070098;
case 0x0c07009au: goto P_0c07009a;
case 0x0c07009cu: goto P_0c07009c;
case 0x0c07009eu: goto P_0c07009e;
case 0x0c0700a0u: goto P_0c0700a0;
case 0x0c0700a2u: goto P_0c0700a2;
case 0x0c0700a4u: goto P_0c0700a4;
case 0x0c0700a6u: goto P_0c0700a6;
case 0x0c0700a8u: goto P_0c0700a8;
case 0x0c0700aau: goto P_0c0700aa;
case 0x0c0700acu: goto P_0c0700ac;
case 0x0c0700aeu: goto P_0c0700ae;
case 0x0c0700b0u: goto P_0c0700b0;
case 0x0c0700b2u: goto P_0c0700b2;
case 0x0c0700b4u: goto P_0c0700b4;
case 0x0c0700b6u: goto P_0c0700b6;
case 0x0c0700b8u: goto P_0c0700b8;
case 0x0c0700bau: goto P_0c0700ba;
case 0x0c0700bcu: goto P_0c0700bc;
case 0x0c0700beu: goto P_0c0700be;
case 0x0c0700c0u: goto P_0c0700c0;
case 0x0c0700c2u: goto P_0c0700c2;
case 0x0c0700c4u: goto P_0c0700c4;
case 0x0c0700c6u: goto P_0c0700c6;
case 0x0c0700c8u: goto P_0c0700c8;
case 0x0c0700cau: goto P_0c0700ca;
case 0x0c0700ccu: goto P_0c0700cc;
case 0x0c0700ceu: goto P_0c0700ce;
case 0x0c0700d0u: goto P_0c0700d0;
case 0x0c0700d2u: goto P_0c0700d2;
case 0x0c0700d4u: goto P_0c0700d4;
case 0x0c0700d6u: goto P_0c0700d6;
case 0x0c0700d8u: goto P_0c0700d8;
case 0x0c0700dau: goto P_0c0700da;
case 0x0c0700dcu: goto P_0c0700dc;
case 0x0c0700deu: goto P_0c0700de;
case 0x0c0700e0u: goto P_0c0700e0;
case 0x0c0700e2u: goto P_0c0700e2;
case 0x0c0700e4u: goto P_0c0700e4;
case 0x0c0700e6u: goto P_0c0700e6;
case 0x0c0700e8u: goto P_0c0700e8;
case 0x0c0700eau: goto P_0c0700ea;
case 0x0c0700ecu: goto P_0c0700ec;
case 0x0c0700eeu: goto P_0c0700ee;
case 0x0c0700f0u: goto P_0c0700f0;
case 0x0c0700f2u: goto P_0c0700f2;
case 0x0c0700f4u: goto P_0c0700f4;
case 0x0c0700f6u: goto P_0c0700f6;
case 0x0c0700f8u: goto P_0c0700f8;
case 0x0c0700fau: goto P_0c0700fa;
case 0x0c070108u: goto P_0c070108;
case 0x0c07010au: goto P_0c07010a;
case 0x0c07010cu: goto P_0c07010c;
case 0x0c07010eu: goto P_0c07010e;
case 0x0c070110u: goto P_0c070110;
case 0x0c070112u: goto P_0c070112;
case 0x0c070114u: goto P_0c070114;
case 0x0c070116u: goto P_0c070116;
case 0x0c070118u: goto P_0c070118;
case 0x0c07011au: goto P_0c07011a;
case 0x0c07011cu: goto P_0c07011c;
case 0x0c07011eu: goto P_0c07011e;
case 0x0c070120u: goto P_0c070120;
case 0x0c070122u: goto P_0c070122;
case 0x0c070124u: goto P_0c070124;
case 0x0c070126u: goto P_0c070126;
case 0x0c070128u: goto P_0c070128;
case 0x0c07012au: goto P_0c07012a;
case 0x0c07012cu: goto P_0c07012c;
case 0x0c07012eu: goto P_0c07012e;
case 0x0c070130u: goto P_0c070130;
case 0x0c070132u: goto P_0c070132;
case 0x0c070134u: goto P_0c070134;
case 0x0c070136u: goto P_0c070136;
case 0x0c070138u: goto P_0c070138;
case 0x0c07013au: goto P_0c07013a;
case 0x0c07013cu: goto P_0c07013c;
case 0x0c07013eu: goto P_0c07013e;
case 0x0c070140u: goto P_0c070140;
case 0x0c070142u: goto P_0c070142;
case 0x0c070144u: goto P_0c070144;
case 0x0c070146u: goto P_0c070146;
case 0x0c070148u: goto P_0c070148;
case 0x0c07014au: goto P_0c07014a;
case 0x0c07014cu: goto P_0c07014c;
case 0x0c07014eu: goto P_0c07014e;
case 0x0c070154u: goto P_0c070154;
case 0x0c070156u: goto P_0c070156;
case 0x0c070158u: goto P_0c070158;
case 0x0c07015au: goto P_0c07015a;
case 0x0c07015cu: goto P_0c07015c;
case 0x0c07015eu: goto P_0c07015e;
case 0x0c070160u: goto P_0c070160;
case 0x0c070162u: goto P_0c070162;
case 0x0c070164u: goto P_0c070164;
case 0x0c070166u: goto P_0c070166;
case 0x0c070168u: goto P_0c070168;
case 0x0c07016au: goto P_0c07016a;
case 0x0c07016cu: goto P_0c07016c;
case 0x0c07016eu: goto P_0c07016e;
case 0x0c070170u: goto P_0c070170;
case 0x0c070172u: goto P_0c070172;
case 0x0c070174u: goto P_0c070174;
case 0x0c070176u: goto P_0c070176;
case 0x0c070178u: goto P_0c070178;
case 0x0c07017au: goto P_0c07017a;
case 0x0c07017cu: goto P_0c07017c;
case 0x0c07017eu: goto P_0c07017e;
case 0x0c070180u: goto P_0c070180;
case 0x0c070182u: goto P_0c070182;
case 0x0c070184u: goto P_0c070184;
case 0x0c070186u: goto P_0c070186;
case 0x0c070188u: goto P_0c070188;
case 0x0c07018au: goto P_0c07018a;
case 0x0c07018cu: goto P_0c07018c;
case 0x0c07018eu: goto P_0c07018e;
case 0x0c070190u: goto P_0c070190;
case 0x0c070192u: goto P_0c070192;
case 0x0c070194u: goto P_0c070194;
case 0x0c070196u: goto P_0c070196;
case 0x0c070198u: goto P_0c070198;
case 0x0c07019au: goto P_0c07019a;
case 0x0c0701a0u: goto P_0c0701a0;
case 0x0c0701a2u: goto P_0c0701a2;
case 0x0c0701a4u: goto P_0c0701a4;
case 0x0c0701a6u: goto P_0c0701a6;
case 0x0c0701a8u: goto P_0c0701a8;
case 0x0c0701aau: goto P_0c0701aa;
case 0x0c0701acu: goto P_0c0701ac;
case 0x0c0701aeu: goto P_0c0701ae;
case 0x0c0701b0u: goto P_0c0701b0;
case 0x0c0701b2u: goto P_0c0701b2;
case 0x0c0701b4u: goto P_0c0701b4;
case 0x0c0701b6u: goto P_0c0701b6;
case 0x0c0701b8u: goto P_0c0701b8;
case 0x0c0701bau: goto P_0c0701ba;
case 0x0c0701bcu: goto P_0c0701bc;
case 0x0c0701beu: goto P_0c0701be;
case 0x0c0701c0u: goto P_0c0701c0;
case 0x0c0701c2u: goto P_0c0701c2;
case 0x0c0701c4u: goto P_0c0701c4;
case 0x0c0701c6u: goto P_0c0701c6;
case 0x0c0701c8u: goto P_0c0701c8;
case 0x0c0701cau: goto P_0c0701ca;
case 0x0c0701ccu: goto P_0c0701cc;
case 0x0c0701ceu: goto P_0c0701ce;
case 0x0c0701d0u: goto P_0c0701d0;
case 0x0c0701d2u: goto P_0c0701d2;
case 0x0c0701d4u: goto P_0c0701d4;
case 0x0c0701d6u: goto P_0c0701d6;
case 0x0c0701d8u: goto P_0c0701d8;
case 0x0c0701dau: goto P_0c0701da;
case 0x0c0701e4u: goto P_0c0701e4;
case 0x0c0701e6u: goto P_0c0701e6;
case 0x0c0701e8u: goto P_0c0701e8;
case 0x0c0701eau: goto P_0c0701ea;
case 0x0c0701ecu: goto P_0c0701ec;
case 0x0c0701eeu: goto P_0c0701ee;
case 0x0c0701f0u: goto P_0c0701f0;
case 0x0c0701f2u: goto P_0c0701f2;
case 0x0c0701f4u: goto P_0c0701f4;
case 0x0c0701f6u: goto P_0c0701f6;
case 0x0c0701f8u: goto P_0c0701f8;
case 0x0c0701fau: goto P_0c0701fa;
case 0x0c0701fcu: goto P_0c0701fc;
case 0x0c0701feu: goto P_0c0701fe;
case 0x0c070200u: goto P_0c070200;
case 0x0c070202u: goto P_0c070202;
case 0x0c070204u: goto P_0c070204;
case 0x0c070206u: goto P_0c070206;
case 0x0c070208u: goto P_0c070208;
case 0x0c07020au: goto P_0c07020a;
case 0x0c07020cu: goto P_0c07020c;
case 0x0c07020eu: goto P_0c07020e;
case 0x0c070210u: goto P_0c070210;
case 0x0c070212u: goto P_0c070212;
case 0x0c070214u: goto P_0c070214;
case 0x0c070216u: goto P_0c070216;
case 0x0c070218u: goto P_0c070218;
case 0x0c07021au: goto P_0c07021a;
case 0x0c07021cu: goto P_0c07021c;
case 0x0c07021eu: goto P_0c07021e;
case 0x0c070220u: goto P_0c070220;
case 0x0c070222u: goto P_0c070222;
case 0x0c070224u: goto P_0c070224;
case 0x0c070226u: goto P_0c070226;
case 0x0c070228u: goto P_0c070228;
case 0x0c07022au: goto P_0c07022a;
case 0x0c07022cu: goto P_0c07022c;
case 0x0c07022eu: goto P_0c07022e;
case 0x0c070230u: goto P_0c070230;
case 0x0c070232u: goto P_0c070232;
case 0x0c070234u: goto P_0c070234;
case 0x0c070236u: goto P_0c070236;
case 0x0c070238u: goto P_0c070238;
case 0x0c070240u: goto P_0c070240;
case 0x0c070242u: goto P_0c070242;
case 0x0c070244u: goto P_0c070244;
case 0x0c070246u: goto P_0c070246;
case 0x0c070248u: goto P_0c070248;
case 0x0c07024au: goto P_0c07024a;
case 0x0c07024cu: goto P_0c07024c;
case 0x0c07024eu: goto P_0c07024e;
case 0x0c070250u: goto P_0c070250;
case 0x0c070252u: goto P_0c070252;
case 0x0c070254u: goto P_0c070254;
case 0x0c070256u: goto P_0c070256;
case 0x0c070258u: goto P_0c070258;
case 0x0c07025au: goto P_0c07025a;
case 0x0c07025cu: goto P_0c07025c;
case 0x0c07025eu: goto P_0c07025e;
case 0x0c070260u: goto P_0c070260;
case 0x0c070262u: goto P_0c070262;
case 0x0c070264u: goto P_0c070264;
case 0x0c070266u: goto P_0c070266;
case 0x0c070268u: goto P_0c070268;
case 0x0c07026au: goto P_0c07026a;
case 0x0c07026cu: goto P_0c07026c;
case 0x0c07026eu: goto P_0c07026e;
case 0x0c070270u: goto P_0c070270;
case 0x0c070272u: goto P_0c070272;
case 0x0c070274u: goto P_0c070274;
case 0x0c070276u: goto P_0c070276;
case 0x0c070278u: goto P_0c070278;
case 0x0c07027au: goto P_0c07027a;
case 0x0c07027cu: goto P_0c07027c;
case 0x0c07027eu: goto P_0c07027e;
case 0x0c070280u: goto P_0c070280;
case 0x0c070282u: goto P_0c070282;
case 0x0c070284u: goto P_0c070284;
case 0x0c070286u: goto P_0c070286;
case 0x0c070288u: goto P_0c070288;
case 0x0c07028au: goto P_0c07028a;
case 0x0c07028cu: goto P_0c07028c;
case 0x0c07028eu: goto P_0c07028e;
case 0x0c070290u: goto P_0c070290;
case 0x0c070292u: goto P_0c070292;
case 0x0c070294u: goto P_0c070294;
case 0x0c070296u: goto P_0c070296;
case 0x0c070298u: goto P_0c070298;
case 0x0c07029au: goto P_0c07029a;
case 0x0c07029cu: goto P_0c07029c;
case 0x0c07029eu: goto P_0c07029e;
case 0x0c0702a0u: goto P_0c0702a0;
case 0x0c0702a2u: goto P_0c0702a2;
case 0x0c0702a4u: goto P_0c0702a4;
case 0x0c0702a6u: goto P_0c0702a6;
case 0x0c0702a8u: goto P_0c0702a8;
case 0x0c0702aau: goto P_0c0702aa;
case 0x0c0702acu: goto P_0c0702ac;
case 0x0c0702aeu: goto P_0c0702ae;
case 0x0c0702b0u: goto P_0c0702b0;
case 0x0c0702b2u: goto P_0c0702b2;
case 0x0c0702b4u: goto P_0c0702b4;
case 0x0c0702b6u: goto P_0c0702b6;
case 0x0c0702b8u: goto P_0c0702b8;
case 0x0c0702bau: goto P_0c0702ba;
case 0x0c0702bcu: goto P_0c0702bc;
case 0x0c0702beu: goto P_0c0702be;
case 0x0c0702c0u: goto P_0c0702c0;
case 0x0c0702c2u: goto P_0c0702c2;
case 0x0c0702c4u: goto P_0c0702c4;
case 0x0c0702c6u: goto P_0c0702c6;
case 0x0c0702c8u: goto P_0c0702c8;
case 0x0c0702cau: goto P_0c0702ca;
case 0x0c0702ccu: goto P_0c0702cc;
case 0x0c0702ceu: goto P_0c0702ce;
case 0x0c0702d0u: goto P_0c0702d0;
case 0x0c0702d2u: goto P_0c0702d2;
case 0x0c0702d4u: goto P_0c0702d4;
case 0x0c0702d6u: goto P_0c0702d6;
case 0x0c0702d8u: goto P_0c0702d8;
case 0x0c0702dau: goto P_0c0702da;
case 0x0c0702dcu: goto P_0c0702dc;
case 0x0c0702deu: goto P_0c0702de;
case 0x0c0702e0u: goto P_0c0702e0;
case 0x0c0702e2u: goto P_0c0702e2;
case 0x0c0702e4u: goto P_0c0702e4;
case 0x0c0702e6u: goto P_0c0702e6;
case 0x0c0702e8u: goto P_0c0702e8;
case 0x0c0702eau: goto P_0c0702ea;
case 0x0c0702ecu: goto P_0c0702ec;
case 0x0c0702eeu: goto P_0c0702ee;
case 0x0c0702f0u: goto P_0c0702f0;
case 0x0c0702f2u: goto P_0c0702f2;
case 0x0c0702f4u: goto P_0c0702f4;
case 0x0c0702f6u: goto P_0c0702f6;
case 0x0c0702f8u: goto P_0c0702f8;
case 0x0c0702fau: goto P_0c0702fa;
case 0x0c0702fcu: goto P_0c0702fc;
case 0x0c0702feu: goto P_0c0702fe;
case 0x0c070300u: goto P_0c070300;
case 0x0c070302u: goto P_0c070302;
case 0x0c070304u: goto P_0c070304;
case 0x0c070306u: goto P_0c070306;
case 0x0c070308u: goto P_0c070308;
case 0x0c07030au: goto P_0c07030a;
case 0x0c07030cu: goto P_0c07030c;
case 0x0c07030eu: goto P_0c07030e;
case 0x0c070310u: goto P_0c070310;
case 0x0c070312u: goto P_0c070312;
case 0x0c070314u: goto P_0c070314;
case 0x0c070316u: goto P_0c070316;
case 0x0c070318u: goto P_0c070318;
case 0x0c07031au: goto P_0c07031a;
case 0x0c07031cu: goto P_0c07031c;
case 0x0c07031eu: goto P_0c07031e;
case 0x0c070320u: goto P_0c070320;
case 0x0c070322u: goto P_0c070322;
case 0x0c070324u: goto P_0c070324;
case 0x0c070326u: goto P_0c070326;
case 0x0c070328u: goto P_0c070328;
case 0x0c07032au: goto P_0c07032a;
case 0x0c07032cu: goto P_0c07032c;
case 0x0c07032eu: goto P_0c07032e;
case 0x0c070330u: goto P_0c070330;
case 0x0c070332u: goto P_0c070332;
case 0x0c070334u: goto P_0c070334;
case 0x0c070336u: goto P_0c070336;
case 0x0c070338u: goto P_0c070338;
case 0x0c07033au: goto P_0c07033a;
case 0x0c07033cu: goto P_0c07033c;
case 0x0c070344u: goto P_0c070344;
case 0x0c070346u: goto P_0c070346;
case 0x0c070348u: goto P_0c070348;
case 0x0c07034au: goto P_0c07034a;
case 0x0c07034cu: goto P_0c07034c;
case 0x0c07034eu: goto P_0c07034e;
case 0x0c070350u: goto P_0c070350;
case 0x0c070352u: goto P_0c070352;
case 0x0c070354u: goto P_0c070354;
case 0x0c070356u: goto P_0c070356;
case 0x0c070358u: goto P_0c070358;
case 0x0c07035au: goto P_0c07035a;
case 0x0c07035cu: goto P_0c07035c;
case 0x0c07035eu: goto P_0c07035e;
case 0x0c070360u: goto P_0c070360;
case 0x0c070362u: goto P_0c070362;
case 0x0c070364u: goto P_0c070364;
case 0x0c070366u: goto P_0c070366;
case 0x0c070368u: goto P_0c070368;
case 0x0c07036au: goto P_0c07036a;
case 0x0c07036cu: goto P_0c07036c;
case 0x0c07036eu: goto P_0c07036e;
case 0x0c070370u: goto P_0c070370;
case 0x0c070372u: goto P_0c070372;
case 0x0c070374u: goto P_0c070374;
case 0x0c070376u: goto P_0c070376;
case 0x0c070378u: goto P_0c070378;
case 0x0c07037au: goto P_0c07037a;
case 0x0c07037cu: goto P_0c07037c;
case 0x0c07037eu: goto P_0c07037e;
case 0x0c070380u: goto P_0c070380;
case 0x0c070382u: goto P_0c070382;
case 0x0c070384u: goto P_0c070384;
case 0x0c070386u: goto P_0c070386;
case 0x0c070388u: goto P_0c070388;
case 0x0c070390u: goto P_0c070390;
case 0x0c070392u: goto P_0c070392;
case 0x0c070394u: goto P_0c070394;
case 0x0c070396u: goto P_0c070396;
case 0x0c070398u: goto P_0c070398;
case 0x0c07039au: goto P_0c07039a;
case 0x0c07039cu: goto P_0c07039c;
case 0x0c07039eu: goto P_0c07039e;
case 0x0c0703a0u: goto P_0c0703a0;
case 0x0c0703a2u: goto P_0c0703a2;
case 0x0c0703a4u: goto P_0c0703a4;
case 0x0c0703a6u: goto P_0c0703a6;
case 0x0c0703a8u: goto P_0c0703a8;
case 0x0c0703aau: goto P_0c0703aa;
case 0x0c0703acu: goto P_0c0703ac;
case 0x0c0703aeu: goto P_0c0703ae;
case 0x0c0703b0u: goto P_0c0703b0;
case 0x0c0703b2u: goto P_0c0703b2;
case 0x0c0703b4u: goto P_0c0703b4;
case 0x0c0703b6u: goto P_0c0703b6;
case 0x0c0703b8u: goto P_0c0703b8;
case 0x0c0703bau: goto P_0c0703ba;
case 0x0c0703bcu: goto P_0c0703bc;
case 0x0c0703beu: goto P_0c0703be;
case 0x0c0703c0u: goto P_0c0703c0;
case 0x0c0703c2u: goto P_0c0703c2;
case 0x0c0703c4u: goto P_0c0703c4;
case 0x0c0703c6u: goto P_0c0703c6;
case 0x0c0703c8u: goto P_0c0703c8;
case 0x0c0703cau: goto P_0c0703ca;
case 0x0c0703ccu: goto P_0c0703cc;
case 0x0c0703d8u: goto P_0c0703d8;
case 0x0c0703dau: goto P_0c0703da;
case 0x0c0703dcu: goto P_0c0703dc;
case 0x0c0703deu: goto P_0c0703de;
case 0x0c0703e0u: goto P_0c0703e0;
case 0x0c0703e2u: goto P_0c0703e2;
case 0x0c0703e4u: goto P_0c0703e4;
case 0x0c0703e6u: goto P_0c0703e6;
case 0x0c0703e8u: goto P_0c0703e8;
case 0x0c0703eau: goto P_0c0703ea;
case 0x0c0703ecu: goto P_0c0703ec;
case 0x0c0703eeu: goto P_0c0703ee;
case 0x0c0703f0u: goto P_0c0703f0;
case 0x0c0703f2u: goto P_0c0703f2;
case 0x0c0703f4u: goto P_0c0703f4;
case 0x0c0703f6u: goto P_0c0703f6;
case 0x0c0703f8u: goto P_0c0703f8;
case 0x0c0703fau: goto P_0c0703fa;
case 0x0c0703fcu: goto P_0c0703fc;
case 0x0c0703feu: goto P_0c0703fe;
case 0x0c070400u: goto P_0c070400;
case 0x0c070402u: goto P_0c070402;
case 0x0c070404u: goto P_0c070404;
case 0x0c070406u: goto P_0c070406;
case 0x0c070408u: goto P_0c070408;
case 0x0c07040au: goto P_0c07040a;
case 0x0c07040cu: goto P_0c07040c;
case 0x0c070418u: goto P_0c070418;
case 0x0c07041au: goto P_0c07041a;
case 0x0c07041cu: goto P_0c07041c;
case 0x0c07041eu: goto P_0c07041e;
case 0x0c070420u: goto P_0c070420;
case 0x0c070422u: goto P_0c070422;
case 0x0c070424u: goto P_0c070424;
case 0x0c070426u: goto P_0c070426;
case 0x0c070428u: goto P_0c070428;
case 0x0c07042au: goto P_0c07042a;
case 0x0c07042cu: goto P_0c07042c;
case 0x0c07042eu: goto P_0c07042e;
case 0x0c070430u: goto P_0c070430;
case 0x0c070432u: goto P_0c070432;
case 0x0c070434u: goto P_0c070434;
case 0x0c070436u: goto P_0c070436;
case 0x0c070438u: goto P_0c070438;
case 0x0c07043au: goto P_0c07043a;
case 0x0c07043cu: goto P_0c07043c;
case 0x0c07043eu: goto P_0c07043e;
case 0x0c070440u: goto P_0c070440;
case 0x0c070442u: goto P_0c070442;
case 0x0c070444u: goto P_0c070444;
case 0x0c070446u: goto P_0c070446;
case 0x0c070448u: goto P_0c070448;
case 0x0c07044au: goto P_0c07044a;
case 0x0c07044cu: goto P_0c07044c;
case 0x0c07044eu: goto P_0c07044e;
case 0x0c070450u: goto P_0c070450;
case 0x0c070452u: goto P_0c070452;
case 0x0c070454u: goto P_0c070454;
case 0x0c070456u: goto P_0c070456;
case 0x0c070458u: goto P_0c070458;
case 0x0c07045au: goto P_0c07045a;
case 0x0c07045cu: goto P_0c07045c;
case 0x0c07045eu: goto P_0c07045e;
case 0x0c070460u: goto P_0c070460;
case 0x0c070462u: goto P_0c070462;
case 0x0c070464u: goto P_0c070464;
case 0x0c070466u: goto P_0c070466;
case 0x0c070468u: goto P_0c070468;
case 0x0c07046au: goto P_0c07046a;
case 0x0c07046cu: goto P_0c07046c;
case 0x0c07046eu: goto P_0c07046e;
case 0x0c070470u: goto P_0c070470;
case 0x0c070472u: goto P_0c070472;
case 0x0c070474u: goto P_0c070474;
case 0x0c070476u: goto P_0c070476;
case 0x0c070478u: goto P_0c070478;
case 0x0c07047au: goto P_0c07047a;
case 0x0c07047cu: goto P_0c07047c;
case 0x0c07047eu: goto P_0c07047e;
case 0x0c070480u: goto P_0c070480;
case 0x0c070482u: goto P_0c070482;
case 0x0c070484u: goto P_0c070484;
case 0x0c070486u: goto P_0c070486;
case 0x0c070488u: goto P_0c070488;
case 0x0c07048au: goto P_0c07048a;
case 0x0c07048cu: goto P_0c07048c;
case 0x0c07048eu: goto P_0c07048e;
case 0x0c070490u: goto P_0c070490;
case 0x0c070492u: goto P_0c070492;
case 0x0c070494u: goto P_0c070494;
case 0x0c070496u: goto P_0c070496;
case 0x0c070498u: goto P_0c070498;
case 0x0c07049au: goto P_0c07049a;
case 0x0c07049cu: goto P_0c07049c;
case 0x0c07049eu: goto P_0c07049e;
case 0x0c0704a0u: goto P_0c0704a0;
case 0x0c0704a2u: goto P_0c0704a2;
case 0x0c0704a4u: goto P_0c0704a4;
case 0x0c0704a6u: goto P_0c0704a6;
case 0x0c0704a8u: goto P_0c0704a8;
case 0x0c0704aau: goto P_0c0704aa;
case 0x0c0704acu: goto P_0c0704ac;
case 0x0c0704aeu: goto P_0c0704ae;
case 0x0c0704b0u: goto P_0c0704b0;
case 0x0c0704b2u: goto P_0c0704b2;
case 0x0c0704b4u: goto P_0c0704b4;
case 0x0c0704b6u: goto P_0c0704b6;
case 0x0c0704b8u: goto P_0c0704b8;
case 0x0c0704bau: goto P_0c0704ba;
case 0x0c0704bcu: goto P_0c0704bc;
case 0x0c0704beu: goto P_0c0704be;
case 0x0c0704c0u: goto P_0c0704c0;
case 0x0c0704c2u: goto P_0c0704c2;
case 0x0c0704c4u: goto P_0c0704c4;
case 0x0c0704c6u: goto P_0c0704c6;
case 0x0c0704c8u: goto P_0c0704c8;
case 0x0c0704cau: goto P_0c0704ca;
case 0x0c0704ccu: goto P_0c0704cc;
case 0x0c0704ceu: goto P_0c0704ce;
case 0x0c0704d0u: goto P_0c0704d0;
case 0x0c0704d2u: goto P_0c0704d2;
case 0x0c0704d4u: goto P_0c0704d4;
case 0x0c0704d6u: goto P_0c0704d6;
case 0x0c0704dcu: goto P_0c0704dc;
case 0x0c0704deu: goto P_0c0704de;
case 0x0c0704e0u: goto P_0c0704e0;
case 0x0c0704e2u: goto P_0c0704e2;
case 0x0c0704e4u: goto P_0c0704e4;
case 0x0c0704e6u: goto P_0c0704e6;
case 0x0c0704e8u: goto P_0c0704e8;
case 0x0c0704eau: goto P_0c0704ea;
case 0x0c0704ecu: goto P_0c0704ec;
case 0x0c0704eeu: goto P_0c0704ee;
case 0x0c0704f0u: goto P_0c0704f0;
case 0x0c0704f2u: goto P_0c0704f2;
case 0x0c0704f4u: goto P_0c0704f4;
case 0x0c0704f6u: goto P_0c0704f6;
case 0x0c0704f8u: goto P_0c0704f8;
case 0x0c0704fau: goto P_0c0704fa;
case 0x0c0704fcu: goto P_0c0704fc;
case 0x0c0704feu: goto P_0c0704fe;
case 0x0c070500u: goto P_0c070500;
case 0x0c070502u: goto P_0c070502;
case 0x0c070504u: goto P_0c070504;
case 0x0c070506u: goto P_0c070506;
case 0x0c070508u: goto P_0c070508;
case 0x0c07050au: goto P_0c07050a;
case 0x0c07050cu: goto P_0c07050c;
case 0x0c07050eu: goto P_0c07050e;
case 0x0c070510u: goto P_0c070510;
case 0x0c070512u: goto P_0c070512;
case 0x0c070514u: goto P_0c070514;
case 0x0c070516u: goto P_0c070516;
case 0x0c070518u: goto P_0c070518;
case 0x0c07051au: goto P_0c07051a;
case 0x0c07051cu: goto P_0c07051c;
case 0x0c07051eu: goto P_0c07051e;
case 0x0c070520u: goto P_0c070520;
case 0x0c070522u: goto P_0c070522;
case 0x0c070528u: goto P_0c070528;
case 0x0c07052au: goto P_0c07052a;
case 0x0c07052cu: goto P_0c07052c;
case 0x0c07052eu: goto P_0c07052e;
case 0x0c070530u: goto P_0c070530;
case 0x0c070532u: goto P_0c070532;
case 0x0c070534u: goto P_0c070534;
case 0x0c070536u: goto P_0c070536;
case 0x0c070538u: goto P_0c070538;
case 0x0c07053au: goto P_0c07053a;
case 0x0c07053cu: goto P_0c07053c;
case 0x0c07053eu: goto P_0c07053e;
case 0x0c070540u: goto P_0c070540;
case 0x0c070542u: goto P_0c070542;
case 0x0c070544u: goto P_0c070544;
case 0x0c070546u: goto P_0c070546;
case 0x0c070548u: goto P_0c070548;
case 0x0c07054au: goto P_0c07054a;
case 0x0c07054cu: goto P_0c07054c;
case 0x0c07054eu: goto P_0c07054e;
case 0x0c070550u: goto P_0c070550;
case 0x0c070552u: goto P_0c070552;
case 0x0c070554u: goto P_0c070554;
case 0x0c070556u: goto P_0c070556;
case 0x0c070558u: goto P_0c070558;
case 0x0c07055au: goto P_0c07055a;
case 0x0c07055cu: goto P_0c07055c;
case 0x0c07055eu: goto P_0c07055e;
case 0x0c070560u: goto P_0c070560;
case 0x0c070562u: goto P_0c070562;
case 0x0c070564u: goto P_0c070564;
case 0x0c070566u: goto P_0c070566;
case 0x0c070568u: goto P_0c070568;
case 0x0c07056au: goto P_0c07056a;
case 0x0c07056cu: goto P_0c07056c;
case 0x0c07056eu: goto P_0c07056e;
case 0x0c070574u: goto P_0c070574;
case 0x0c070576u: goto P_0c070576;
case 0x0c070578u: goto P_0c070578;
case 0x0c07057au: goto P_0c07057a;
case 0x0c07057cu: goto P_0c07057c;
case 0x0c07057eu: goto P_0c07057e;
case 0x0c070580u: goto P_0c070580;
case 0x0c070582u: goto P_0c070582;
case 0x0c070584u: goto P_0c070584;
case 0x0c070586u: goto P_0c070586;
case 0x0c070588u: goto P_0c070588;
case 0x0c07058au: goto P_0c07058a;
case 0x0c07058cu: goto P_0c07058c;
case 0x0c07058eu: goto P_0c07058e;
case 0x0c070590u: goto P_0c070590;
case 0x0c070592u: goto P_0c070592;
case 0x0c070594u: goto P_0c070594;
case 0x0c070596u: goto P_0c070596;
case 0x0c070598u: goto P_0c070598;
case 0x0c07059au: goto P_0c07059a;
case 0x0c07059cu: goto P_0c07059c;
case 0x0c07059eu: goto P_0c07059e;
case 0x0c0705a0u: goto P_0c0705a0;
case 0x0c0705a2u: goto P_0c0705a2;
case 0x0c0705a4u: goto P_0c0705a4;
case 0x0c0705a6u: goto P_0c0705a6;
case 0x0c0705a8u: goto P_0c0705a8;
case 0x0c0705aau: goto P_0c0705aa;
case 0x0c0705acu: goto P_0c0705ac;
case 0x0c0705b8u: goto P_0c0705b8;
case 0x0c0705bau: goto P_0c0705ba;
case 0x0c0705bcu: goto P_0c0705bc;
case 0x0c0705beu: goto P_0c0705be;
case 0x0c0705c0u: goto P_0c0705c0;
case 0x0c0705c2u: goto P_0c0705c2;
case 0x0c0705c4u: goto P_0c0705c4;
case 0x0c0705c6u: goto P_0c0705c6;
case 0x0c0705c8u: goto P_0c0705c8;
case 0x0c0705cau: goto P_0c0705ca;
case 0x0c0705ccu: goto P_0c0705cc;
case 0x0c0705ceu: goto P_0c0705ce;
case 0x0c0705d0u: goto P_0c0705d0;
case 0x0c0705d2u: goto P_0c0705d2;
case 0x0c0705d4u: goto P_0c0705d4;
case 0x0c0705d6u: goto P_0c0705d6;
case 0x0c0705d8u: goto P_0c0705d8;
case 0x0c070878u: goto P_0c070878;
case 0x0c07087au: goto P_0c07087a;
case 0x0c07087cu: goto P_0c07087c;
case 0x0c07087eu: goto P_0c07087e;
case 0x0c070880u: goto P_0c070880;
case 0x0c070882u: goto P_0c070882;
case 0x0c070884u: goto P_0c070884;
case 0x0c070886u: goto P_0c070886;
case 0x0c070888u: goto P_0c070888;
case 0x0c07088au: goto P_0c07088a;
case 0x0c07088cu: goto P_0c07088c;
case 0x0c07088eu: goto P_0c07088e;
case 0x0c070890u: goto P_0c070890;
case 0x0c070892u: goto P_0c070892;
case 0x0c070898u: goto P_0c070898;
case 0x0c07089au: goto P_0c07089a;
case 0x0c07089cu: goto P_0c07089c;
case 0x0c07089eu: goto P_0c07089e;
case 0x0c0708a0u: goto P_0c0708a0;
case 0x0c0708a2u: goto P_0c0708a2;
case 0x0c0708a4u: goto P_0c0708a4;
case 0x0c0708a6u: goto P_0c0708a6;
case 0x0c0708a8u: goto P_0c0708a8;
case 0x0c0708aau: goto P_0c0708aa;
case 0x0c0708acu: goto P_0c0708ac;
case 0x0c0708aeu: goto P_0c0708ae;
case 0x0c0708b0u: goto P_0c0708b0;
case 0x0c0708b2u: goto P_0c0708b2;
case 0x0c0708b4u: goto P_0c0708b4;
case 0x0c0708b6u: goto P_0c0708b6;
case 0x0c0708b8u: goto P_0c0708b8;
case 0x0c0708bau: goto P_0c0708ba;
case 0x0c0708bcu: goto P_0c0708bc;
case 0x0c0708beu: goto P_0c0708be;
case 0x0c0708c0u: goto P_0c0708c0;
case 0x0c0708c2u: goto P_0c0708c2;
case 0x0c0708c4u: goto P_0c0708c4;
case 0x0c0708c6u: goto P_0c0708c6;
case 0x0c0708c8u: goto P_0c0708c8;
case 0x0c0708cau: goto P_0c0708ca;
case 0x0c0708ccu: goto P_0c0708cc;
case 0x0c0708ceu: goto P_0c0708ce;
case 0x0c0708d0u: goto P_0c0708d0;
case 0x0c0708d2u: goto P_0c0708d2;
case 0x0c0708d4u: goto P_0c0708d4;
case 0x0c0708d6u: goto P_0c0708d6;
case 0x0c0708d8u: goto P_0c0708d8;
case 0x0c0708dau: goto P_0c0708da;
case 0x0c0708dcu: goto P_0c0708dc;
case 0x0c0708deu: goto P_0c0708de;
case 0x0c0708e0u: goto P_0c0708e0;
case 0x0c0708e8u: goto P_0c0708e8;
case 0x0c0708eau: goto P_0c0708ea;
case 0x0c0708ecu: goto P_0c0708ec;
case 0x0c0708eeu: goto P_0c0708ee;
case 0x0c0708f0u: goto P_0c0708f0;
case 0x0c0708f2u: goto P_0c0708f2;
case 0x0c0708f4u: goto P_0c0708f4;
case 0x0c0708f6u: goto P_0c0708f6;
case 0x0c0708f8u: goto P_0c0708f8;
case 0x0c0708fau: goto P_0c0708fa;
case 0x0c0708fcu: goto P_0c0708fc;
case 0x0c0708feu: goto P_0c0708fe;
case 0x0c070900u: goto P_0c070900;
case 0x0c070902u: goto P_0c070902;
case 0x0c070904u: goto P_0c070904;
case 0x0c070906u: goto P_0c070906;
case 0x0c070908u: goto P_0c070908;
case 0x0c07090au: goto P_0c07090a;
case 0x0c07090cu: goto P_0c07090c;
case 0x0c07090eu: goto P_0c07090e;
case 0x0c070910u: goto P_0c070910;
case 0x0c070912u: goto P_0c070912;
case 0x0c070914u: goto P_0c070914;
case 0x0c070916u: goto P_0c070916;
case 0x0c070918u: goto P_0c070918;
case 0x0c07091au: goto P_0c07091a;
case 0x0c07091cu: goto P_0c07091c;
case 0x0c07091eu: goto P_0c07091e;
case 0x0c070920u: goto P_0c070920;
case 0x0c070922u: goto P_0c070922;
case 0x0c070924u: goto P_0c070924;
case 0x0c070926u: goto P_0c070926;
case 0x0c070928u: goto P_0c070928;
case 0x0c07092au: goto P_0c07092a;
case 0x0c07092cu: goto P_0c07092c;
case 0x0c070934u: goto P_0c070934;
case 0x0c070936u: goto P_0c070936;
case 0x0c070938u: goto P_0c070938;
case 0x0c07093au: goto P_0c07093a;
case 0x0c07093cu: goto P_0c07093c;
case 0x0c07093eu: goto P_0c07093e;
case 0x0c070940u: goto P_0c070940;
case 0x0c070942u: goto P_0c070942;
case 0x0c070944u: goto P_0c070944;
case 0x0c070946u: goto P_0c070946;
case 0x0c070948u: goto P_0c070948;
case 0x0c07094au: goto P_0c07094a;
case 0x0c07094cu: goto P_0c07094c;
case 0x0c07094eu: goto P_0c07094e;
case 0x0c070950u: goto P_0c070950;
case 0x0c070952u: goto P_0c070952;
case 0x0c070954u: goto P_0c070954;
case 0x0c070956u: goto P_0c070956;
case 0x0c070958u: goto P_0c070958;
case 0x0c07095au: goto P_0c07095a;
case 0x0c07095cu: goto P_0c07095c;
case 0x0c07095eu: goto P_0c07095e;
case 0x0c070960u: goto P_0c070960;
case 0x0c070962u: goto P_0c070962;
case 0x0c070964u: goto P_0c070964;
case 0x0c070966u: goto P_0c070966;
case 0x0c070968u: goto P_0c070968;
case 0x0c07096au: goto P_0c07096a;
case 0x0c07096cu: goto P_0c07096c;
case 0x0c07096eu: goto P_0c07096e;
case 0x0c070970u: goto P_0c070970;
case 0x0c07097cu: goto P_0c07097c;
case 0x0c07097eu: goto P_0c07097e;
case 0x0c070980u: goto P_0c070980;
case 0x0c070982u: goto P_0c070982;
case 0x0c070984u: goto P_0c070984;
case 0x0c070986u: goto P_0c070986;
case 0x0c070988u: goto P_0c070988;
case 0x0c07098au: goto P_0c07098a;
case 0x0c07098cu: goto P_0c07098c;
case 0x0c07098eu: goto P_0c07098e;
case 0x0c070990u: goto P_0c070990;
case 0x0c070992u: goto P_0c070992;
case 0x0c070994u: goto P_0c070994;
case 0x0c070996u: goto P_0c070996;
case 0x0c070998u: goto P_0c070998;
case 0x0c07099au: goto P_0c07099a;
case 0x0c07099cu: goto P_0c07099c;
case 0x0c07099eu: goto P_0c07099e;
case 0x0c0709a0u: goto P_0c0709a0;
case 0x0c0709a2u: goto P_0c0709a2;
case 0x0c0709a4u: goto P_0c0709a4;
case 0x0c0709a6u: goto P_0c0709a6;
case 0x0c0709a8u: goto P_0c0709a8;
case 0x0c0709aau: goto P_0c0709aa;
case 0x0c0709acu: goto P_0c0709ac;
case 0x0c0709aeu: goto P_0c0709ae;
case 0x0c0709b0u: goto P_0c0709b0;
case 0x0c0709bcu: goto P_0c0709bc;
case 0x0c0709beu: goto P_0c0709be;
case 0x0c0709c0u: goto P_0c0709c0;
case 0x0c0709c2u: goto P_0c0709c2;
case 0x0c0709c4u: goto P_0c0709c4;
case 0x0c0709c6u: goto P_0c0709c6;
case 0x0c0709c8u: goto P_0c0709c8;
case 0x0c0709cau: goto P_0c0709ca;
case 0x0c0709ccu: goto P_0c0709cc;
case 0x0c0709ceu: goto P_0c0709ce;
case 0x0c0709d0u: goto P_0c0709d0;
case 0x0c0709d2u: goto P_0c0709d2;
case 0x0c0709d4u: goto P_0c0709d4;
case 0x0c0709d6u: goto P_0c0709d6;
case 0x0c0709d8u: goto P_0c0709d8;
case 0x0c0709dau: goto P_0c0709da;
case 0x0c0709dcu: goto P_0c0709dc;
case 0x0c0709deu: goto P_0c0709de;
case 0x0c0709e0u: goto P_0c0709e0;
case 0x0c0709e2u: goto P_0c0709e2;
case 0x0c0709e4u: goto P_0c0709e4;
case 0x0c0709e6u: goto P_0c0709e6;
case 0x0c0709e8u: goto P_0c0709e8;
case 0x0c0709eau: goto P_0c0709ea;
case 0x0c0709ecu: goto P_0c0709ec;
case 0x0c0709eeu: goto P_0c0709ee;
case 0x0c0709f0u: goto P_0c0709f0;
case 0x0c0709f2u: goto P_0c0709f2;
case 0x0c0709f4u: goto P_0c0709f4;
case 0x0c0709f6u: goto P_0c0709f6;
case 0x0c0709f8u: goto P_0c0709f8;
case 0x0c0709fau: goto P_0c0709fa;
case 0x0c0709fcu: goto P_0c0709fc;
case 0x0c0709feu: goto P_0c0709fe;
case 0x0c070a00u: goto P_0c070a00;
case 0x0c070a02u: goto P_0c070a02;
case 0x0c070a04u: goto P_0c070a04;
case 0x0c070a06u: goto P_0c070a06;
case 0x0c070a08u: goto P_0c070a08;
case 0x0c070a0au: goto P_0c070a0a;
case 0x0c070a0cu: goto P_0c070a0c;
case 0x0c070a0eu: goto P_0c070a0e;
case 0x0c070a10u: goto P_0c070a10;
case 0x0c070a12u: goto P_0c070a12;
case 0x0c070a14u: goto P_0c070a14;
case 0x0c070a16u: goto P_0c070a16;
case 0x0c070a18u: goto P_0c070a18;
case 0x0c070a1au: goto P_0c070a1a;
case 0x0c070a1cu: goto P_0c070a1c;
case 0x0c070a1eu: goto P_0c070a1e;
case 0x0c070a20u: goto P_0c070a20;
case 0x0c070a22u: goto P_0c070a22;
case 0x0c070a24u: goto P_0c070a24;
case 0x0c070a26u: goto P_0c070a26;
case 0x0c070a28u: goto P_0c070a28;
case 0x0c070a2au: goto P_0c070a2a;
case 0x0c070a2cu: goto P_0c070a2c;
case 0x0c070a2eu: goto P_0c070a2e;
case 0x0c070a30u: goto P_0c070a30;
case 0x0c070a32u: goto P_0c070a32;
case 0x0c070a34u: goto P_0c070a34;
case 0x0c070a36u: goto P_0c070a36;
case 0x0c070a38u: goto P_0c070a38;
case 0x0c070a3au: goto P_0c070a3a;
case 0x0c070a3cu: goto P_0c070a3c;
case 0x0c070a3eu: goto P_0c070a3e;
case 0x0c070a40u: goto P_0c070a40;
case 0x0c070a42u: goto P_0c070a42;
case 0x0c070a44u: goto P_0c070a44;
case 0x0c070a46u: goto P_0c070a46;
case 0x0c070a48u: goto P_0c070a48;
case 0x0c070a4au: goto P_0c070a4a;
case 0x0c070a4cu: goto P_0c070a4c;
case 0x0c070a4eu: goto P_0c070a4e;
case 0x0c070a50u: goto P_0c070a50;
case 0x0c070a52u: goto P_0c070a52;
case 0x0c070a54u: goto P_0c070a54;
case 0x0c070a56u: goto P_0c070a56;
case 0x0c070a58u: goto P_0c070a58;
case 0x0c070a5au: goto P_0c070a5a;
case 0x0c070a5cu: goto P_0c070a5c;
case 0x0c070a5eu: goto P_0c070a5e;
case 0x0c070a60u: goto P_0c070a60;
case 0x0c070a62u: goto P_0c070a62;
case 0x0c070a64u: goto P_0c070a64;
case 0x0c070a66u: goto P_0c070a66;
case 0x0c070a68u: goto P_0c070a68;
case 0x0c070a6au: goto P_0c070a6a;
case 0x0c070a6cu: goto P_0c070a6c;
case 0x0c070a6eu: goto P_0c070a6e;
case 0x0c070a70u: goto P_0c070a70;
case 0x0c070a72u: goto P_0c070a72;
case 0x0c070a74u: goto P_0c070a74;
case 0x0c070a76u: goto P_0c070a76;
case 0x0c070a78u: goto P_0c070a78;
case 0x0c070a7au: goto P_0c070a7a;
case 0x0c070a7cu: goto P_0c070a7c;
case 0x0c070a7eu: goto P_0c070a7e;
case 0x0c070a80u: goto P_0c070a80;
case 0x0c070a82u: goto P_0c070a82;
case 0x0c070a84u: goto P_0c070a84;
case 0x0c070a86u: goto P_0c070a86;
case 0x0c070a88u: goto P_0c070a88;
case 0x0c070a8au: goto P_0c070a8a;
case 0x0c070a8cu: goto P_0c070a8c;
case 0x0c070a8eu: goto P_0c070a8e;
case 0x0c070a90u: goto P_0c070a90;
case 0x0c070a92u: goto P_0c070a92;
case 0x0c070a94u: goto P_0c070a94;
case 0x0c070a96u: goto P_0c070a96;
case 0x0c070a98u: goto P_0c070a98;
case 0x0c070a9au: goto P_0c070a9a;
case 0x0c070a9cu: goto P_0c070a9c;
case 0x0c070a9eu: goto P_0c070a9e;
case 0x0c070aa0u: goto P_0c070aa0;
case 0x0c070aa2u: goto P_0c070aa2;
case 0x0c070aa4u: goto P_0c070aa4;
case 0x0c070aa6u: goto P_0c070aa6;
case 0x0c070aa8u: goto P_0c070aa8;
case 0x0c070aaau: goto P_0c070aaa;
case 0x0c070aacu: goto P_0c070aac;
case 0x0c070aaeu: goto P_0c070aae;
case 0x0c070ab0u: goto P_0c070ab0;
case 0x0c070ab2u: goto P_0c070ab2;
case 0x0c070ab4u: goto P_0c070ab4;
case 0x0c070abcu: goto P_0c070abc;
case 0x0c070abeu: goto P_0c070abe;
case 0x0c070ac0u: goto P_0c070ac0;
case 0x0c070ac2u: goto P_0c070ac2;
case 0x0c070ac4u: goto P_0c070ac4;
case 0x0c070ac6u: goto P_0c070ac6;
case 0x0c070ac8u: goto P_0c070ac8;
case 0x0c070acau: goto P_0c070aca;
case 0x0c070accu: goto P_0c070acc;
case 0x0c070aceu: goto P_0c070ace;
case 0x0c070ad0u: goto P_0c070ad0;
case 0x0c070ad2u: goto P_0c070ad2;
case 0x0c070ad4u: goto P_0c070ad4;
case 0x0c070ad6u: goto P_0c070ad6;
case 0x0c070ad8u: goto P_0c070ad8;
case 0x0c070adau: goto P_0c070ada;
case 0x0c070adcu: goto P_0c070adc;
case 0x0c070adeu: goto P_0c070ade;
case 0x0c070ae0u: goto P_0c070ae0;
case 0x0c070ae2u: goto P_0c070ae2;
case 0x0c070ae4u: goto P_0c070ae4;
case 0x0c070ae6u: goto P_0c070ae6;
case 0x0c070ae8u: goto P_0c070ae8;
case 0x0c070aeau: goto P_0c070aea;
case 0x0c070aecu: goto P_0c070aec;
case 0x0c070aeeu: goto P_0c070aee;
case 0x0c070af0u: goto P_0c070af0;
case 0x0c070af2u: goto P_0c070af2;
case 0x0c070af4u: goto P_0c070af4;
case 0x0c070af6u: goto P_0c070af6;
case 0x0c070af8u: goto P_0c070af8;
case 0x0c070afau: goto P_0c070afa;
case 0x0c070afcu: goto P_0c070afc;
case 0x0c070afeu: goto P_0c070afe;
case 0x0c070b00u: goto P_0c070b00;
case 0x0c070b08u: goto P_0c070b08;
case 0x0c070b0au: goto P_0c070b0a;
case 0x0c070b0cu: goto P_0c070b0c;
case 0x0c070b0eu: goto P_0c070b0e;
case 0x0c070b10u: goto P_0c070b10;
case 0x0c070b12u: goto P_0c070b12;
case 0x0c070b14u: goto P_0c070b14;
case 0x0c070b16u: goto P_0c070b16;
case 0x0c070b18u: goto P_0c070b18;
case 0x0c070b1au: goto P_0c070b1a;
case 0x0c070b1cu: goto P_0c070b1c;
case 0x0c070b1eu: goto P_0c070b1e;
case 0x0c070b20u: goto P_0c070b20;
case 0x0c070b22u: goto P_0c070b22;
case 0x0c070b24u: goto P_0c070b24;
case 0x0c070b26u: goto P_0c070b26;
case 0x0c070b28u: goto P_0c070b28;
case 0x0c070b2au: goto P_0c070b2a;
case 0x0c070b2cu: goto P_0c070b2c;
case 0x0c070b2eu: goto P_0c070b2e;
case 0x0c070b30u: goto P_0c070b30;
case 0x0c070b32u: goto P_0c070b32;
case 0x0c070b34u: goto P_0c070b34;
case 0x0c070b36u: goto P_0c070b36;
case 0x0c070b38u: goto P_0c070b38;
case 0x0c070b3au: goto P_0c070b3a;
case 0x0c070b3cu: goto P_0c070b3c;
case 0x0c070b3eu: goto P_0c070b3e;
case 0x0c070b40u: goto P_0c070b40;
case 0x0c070b42u: goto P_0c070b42;
case 0x0c070b44u: goto P_0c070b44;
case 0x0c070b50u: goto P_0c070b50;
case 0x0c070b52u: goto P_0c070b52;
case 0x0c070b54u: goto P_0c070b54;
case 0x0c070b56u: goto P_0c070b56;
case 0x0c070b58u: goto P_0c070b58;
case 0x0c070b5au: goto P_0c070b5a;
case 0x0c070b5cu: goto P_0c070b5c;
case 0x0c070b5eu: goto P_0c070b5e;
case 0x0c070b60u: goto P_0c070b60;
case 0x0c070b62u: goto P_0c070b62;
case 0x0c070b64u: goto P_0c070b64;
case 0x0c070b66u: goto P_0c070b66;
case 0x0c070b68u: goto P_0c070b68;
case 0x0c070b6au: goto P_0c070b6a;
case 0x0c070b6cu: goto P_0c070b6c;
case 0x0c070b6eu: goto P_0c070b6e;
case 0x0c070b70u: goto P_0c070b70;
case 0x0c070b72u: goto P_0c070b72;
case 0x0c070b74u: goto P_0c070b74;
case 0x0c070b76u: goto P_0c070b76;
case 0x0c070b78u: goto P_0c070b78;
case 0x0c070b7au: goto P_0c070b7a;
case 0x0c070b7cu: goto P_0c070b7c;
case 0x0c070b7eu: goto P_0c070b7e;
case 0x0c070b80u: goto P_0c070b80;
case 0x0c070b82u: goto P_0c070b82;
case 0x0c070b84u: goto P_0c070b84;
case 0x0c070b90u: goto P_0c070b90;
case 0x0c070b92u: goto P_0c070b92;
case 0x0c070b94u: goto P_0c070b94;
case 0x0c070b96u: goto P_0c070b96;
case 0x0c070b98u: goto P_0c070b98;
case 0x0c070b9au: goto P_0c070b9a;
case 0x0c070b9cu: goto P_0c070b9c;
case 0x0c070b9eu: goto P_0c070b9e;
case 0x0c070ba0u: goto P_0c070ba0;
case 0x0c070ba2u: goto P_0c070ba2;
case 0x0c070ba4u: goto P_0c070ba4;
case 0x0c070ba6u: goto P_0c070ba6;
case 0x0c070ba8u: goto P_0c070ba8;
case 0x0c070baau: goto P_0c070baa;
case 0x0c070bacu: goto P_0c070bac;
case 0x0c070baeu: goto P_0c070bae;
case 0x0c070bb0u: goto P_0c070bb0;
case 0x0c070bb2u: goto P_0c070bb2;
case 0x0c070bb4u: goto P_0c070bb4;
case 0x0c070bb6u: goto P_0c070bb6;
case 0x0c070bb8u: goto P_0c070bb8;
case 0x0c070bbau: goto P_0c070bba;
case 0x0c070bbcu: goto P_0c070bbc;
case 0x0c070bbeu: goto P_0c070bbe;
case 0x0c070bc0u: goto P_0c070bc0;
case 0x0c070bc2u: goto P_0c070bc2;
case 0x0c070bc4u: goto P_0c070bc4;
case 0x0c070bc6u: goto P_0c070bc6;
case 0x0c070bc8u: goto P_0c070bc8;
case 0x0c070bcau: goto P_0c070bca;
case 0x0c070bccu: goto P_0c070bcc;
case 0x0c070bceu: goto P_0c070bce;
case 0x0c070bd0u: goto P_0c070bd0;
case 0x0c070bd2u: goto P_0c070bd2;
case 0x0c070bd4u: goto P_0c070bd4;
case 0x0c070bd6u: goto P_0c070bd6;
case 0x0c070bd8u: goto P_0c070bd8;
case 0x0c070bdau: goto P_0c070bda;
case 0x0c070bdcu: goto P_0c070bdc;
case 0x0c070bdeu: goto P_0c070bde;
case 0x0c070be0u: goto P_0c070be0;
case 0x0c070be2u: goto P_0c070be2;
case 0x0c070be4u: goto P_0c070be4;
case 0x0c070be6u: goto P_0c070be6;
case 0x0c070be8u: goto P_0c070be8;
case 0x0c070beau: goto P_0c070bea;
case 0x0c070becu: goto P_0c070bec;
case 0x0c070beeu: goto P_0c070bee;
case 0x0c070bf0u: goto P_0c070bf0;
case 0x0c070bf2u: goto P_0c070bf2;
case 0x0c070bf4u: goto P_0c070bf4;
case 0x0c070bf6u: goto P_0c070bf6;
case 0x0c070bf8u: goto P_0c070bf8;
case 0x0c070bfau: goto P_0c070bfa;
case 0x0c070bfcu: goto P_0c070bfc;
case 0x0c070bfeu: goto P_0c070bfe;
case 0x0c070c00u: goto P_0c070c00;
case 0x0c070c02u: goto P_0c070c02;
case 0x0c070c04u: goto P_0c070c04;
case 0x0c070c06u: goto P_0c070c06;
case 0x0c070c08u: goto P_0c070c08;
case 0x0c070c0au: goto P_0c070c0a;
case 0x0c070c0cu: goto P_0c070c0c;
case 0x0c070c0eu: goto P_0c070c0e;
case 0x0c070c10u: goto P_0c070c10;
case 0x0c070c12u: goto P_0c070c12;
case 0x0c070c14u: goto P_0c070c14;
case 0x0c070c16u: goto P_0c070c16;
case 0x0c070c18u: goto P_0c070c18;
case 0x0c070c1au: goto P_0c070c1a;
case 0x0c070c1cu: goto P_0c070c1c;
case 0x0c070c1eu: goto P_0c070c1e;
case 0x0c070c20u: goto P_0c070c20;
case 0x0c070c22u: goto P_0c070c22;
case 0x0c070c24u: goto P_0c070c24;
case 0x0c070c26u: goto P_0c070c26;
case 0x0c070c28u: goto P_0c070c28;
case 0x0c070c2au: goto P_0c070c2a;
case 0x0c070c2cu: goto P_0c070c2c;
case 0x0c070c2eu: goto P_0c070c2e;
case 0x0c070c30u: goto P_0c070c30;
case 0x0c070c32u: goto P_0c070c32;
case 0x0c070c34u: goto P_0c070c34;
case 0x0c070c36u: goto P_0c070c36;
case 0x0c070c38u: goto P_0c070c38;
case 0x0c070c3au: goto P_0c070c3a;
case 0x0c070c3cu: goto P_0c070c3c;
case 0x0c070c3eu: goto P_0c070c3e;
case 0x0c070c40u: goto P_0c070c40;
case 0x0c070c42u: goto P_0c070c42;
case 0x0c070c44u: goto P_0c070c44;
case 0x0c070c46u: goto P_0c070c46;
case 0x0c070c48u: goto P_0c070c48;
case 0x0c070c4au: goto P_0c070c4a;
case 0x0c070c4cu: goto P_0c070c4c;
case 0x0c070c4eu: goto P_0c070c4e;
case 0x0c070c50u: goto P_0c070c50;
case 0x0c070c52u: goto P_0c070c52;
case 0x0c070c54u: goto P_0c070c54;
case 0x0c070c56u: goto P_0c070c56;
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
case 0x0c070dd6u: goto P_0c070dd6;
case 0x0c070dd8u: goto P_0c070dd8;
case 0x0c070ddau: goto P_0c070dda;
case 0x0c070ddcu: goto P_0c070ddc;
case 0x0c070ddeu: goto P_0c070dde;
case 0x0c070de0u: goto P_0c070de0;
case 0x0c070de2u: goto P_0c070de2;
case 0x0c070de4u: goto P_0c070de4;
case 0x0c070de6u: goto P_0c070de6;
case 0x0c070de8u: goto P_0c070de8;
case 0x0c070df4u: goto P_0c070df4;
case 0x0c070df6u: goto P_0c070df6;
case 0x0c070df8u: goto P_0c070df8;
case 0x0c070dfau: goto P_0c070dfa;
case 0x0c070dfcu: goto P_0c070dfc;
case 0x0c070dfeu: goto P_0c070dfe;
case 0x0c070e00u: goto P_0c070e00;
case 0x0c070e02u: goto P_0c070e02;
case 0x0c070e04u: goto P_0c070e04;
case 0x0c070e06u: goto P_0c070e06;
case 0x0c070e08u: goto P_0c070e08;
case 0x0c070e0au: goto P_0c070e0a;
case 0x0c070e0cu: goto P_0c070e0c;
case 0x0c070e0eu: goto P_0c070e0e;
case 0x0c070e10u: goto P_0c070e10;
case 0x0c070e12u: goto P_0c070e12;
case 0x0c070e14u: goto P_0c070e14;
case 0x0c070e16u: goto P_0c070e16;
case 0x0c070e18u: goto P_0c070e18;
case 0x0c070e1au: goto P_0c070e1a;
case 0x0c070e1cu: goto P_0c070e1c;
case 0x0c070e1eu: goto P_0c070e1e;
case 0x0c070e20u: goto P_0c070e20;
case 0x0c070e22u: goto P_0c070e22;
case 0x0c070e24u: goto P_0c070e24;
case 0x0c070e26u: goto P_0c070e26;
case 0x0c070e28u: goto P_0c070e28;
case 0x0c070e2au: goto P_0c070e2a;
case 0x0c070e2cu: goto P_0c070e2c;
case 0x0c070e2eu: goto P_0c070e2e;
case 0x0c070e30u: goto P_0c070e30;
case 0x0c070e32u: goto P_0c070e32;
case 0x0c070e34u: goto P_0c070e34;
case 0x0c070e36u: goto P_0c070e36;
case 0x0c070e38u: goto P_0c070e38;
case 0x0c070e3au: goto P_0c070e3a;
case 0x0c070e3cu: goto P_0c070e3c;
case 0x0c070e3eu: goto P_0c070e3e;
case 0x0c070e40u: goto P_0c070e40;
case 0x0c070e42u: goto P_0c070e42;
case 0x0c070e44u: goto P_0c070e44;
case 0x0c070e46u: goto P_0c070e46;
case 0x0c070e48u: goto P_0c070e48;
case 0x0c070e4au: goto P_0c070e4a;
case 0x0c070e4cu: goto P_0c070e4c;
case 0x0c070e4eu: goto P_0c070e4e;
case 0x0c070e50u: goto P_0c070e50;
case 0x0c070e52u: goto P_0c070e52;
case 0x0c070e54u: goto P_0c070e54;
case 0x0c070e56u: goto P_0c070e56;
case 0x0c070e58u: goto P_0c070e58;
case 0x0c070e5au: goto P_0c070e5a;
case 0x0c070e5cu: goto P_0c070e5c;
case 0x0c070e5eu: goto P_0c070e5e;
case 0x0c070e60u: goto P_0c070e60;
case 0x0c070e62u: goto P_0c070e62;
case 0x0c070e64u: goto P_0c070e64;
case 0x0c070e66u: goto P_0c070e66;
case 0x0c070e68u: goto P_0c070e68;
case 0x0c070e6au: goto P_0c070e6a;
case 0x0c070e6cu: goto P_0c070e6c;
case 0x0c070e6eu: goto P_0c070e6e;
case 0x0c070e70u: goto P_0c070e70;
case 0x0c070e72u: goto P_0c070e72;
case 0x0c070e74u: goto P_0c070e74;
case 0x0c070e76u: goto P_0c070e76;
case 0x0c070e78u: goto P_0c070e78;
case 0x0c070e7au: goto P_0c070e7a;
case 0x0c070e7cu: goto P_0c070e7c;
case 0x0c070e7eu: goto P_0c070e7e;
case 0x0c070e80u: goto P_0c070e80;
case 0x0c070e82u: goto P_0c070e82;
case 0x0c070e84u: goto P_0c070e84;
case 0x0c070e86u: goto P_0c070e86;
case 0x0c070e88u: goto P_0c070e88;
case 0x0c070e8au: goto P_0c070e8a;
case 0x0c070e8cu: goto P_0c070e8c;
case 0x0c070e8eu: goto P_0c070e8e;
case 0x0c070e90u: goto P_0c070e90;
case 0x0c070e92u: goto P_0c070e92;
case 0x0c070e94u: goto P_0c070e94;
case 0x0c070e96u: goto P_0c070e96;
case 0x0c070e98u: goto P_0c070e98;
case 0x0c070e9au: goto P_0c070e9a;
case 0x0c070e9cu: goto P_0c070e9c;
case 0x0c070e9eu: goto P_0c070e9e;
case 0x0c070ea0u: goto P_0c070ea0;
case 0x0c070ea2u: goto P_0c070ea2;
case 0x0c070ea4u: goto P_0c070ea4;
case 0x0c070ea6u: goto P_0c070ea6;
case 0x0c070ea8u: goto P_0c070ea8;
case 0x0c070eaau: goto P_0c070eaa;
case 0x0c070eacu: goto P_0c070eac;
case 0x0c070eaeu: goto P_0c070eae;
case 0x0c070eb0u: goto P_0c070eb0;
case 0x0c070eb2u: goto P_0c070eb2;
case 0x0c070eb4u: goto P_0c070eb4;
case 0x0c070eb6u: goto P_0c070eb6;
case 0x0c070eb8u: goto P_0c070eb8;
case 0x0c070ebau: goto P_0c070eba;
case 0x0c070ebcu: goto P_0c070ebc;
case 0x0c070ebeu: goto P_0c070ebe;
case 0x0c070ec0u: goto P_0c070ec0;
case 0x0c070ec2u: goto P_0c070ec2;
case 0x0c070ec4u: goto P_0c070ec4;
case 0x0c070ec6u: goto P_0c070ec6;
case 0x0c070ec8u: goto P_0c070ec8;
case 0x0c070ecau: goto P_0c070eca;
case 0x0c070eccu: goto P_0c070ecc;
case 0x0c070eceu: goto P_0c070ece;
case 0x0c070ed0u: goto P_0c070ed0;
case 0x0c070ed2u: goto P_0c070ed2;
case 0x0c070ed4u: goto P_0c070ed4;
case 0x0c070ed6u: goto P_0c070ed6;
case 0x0c070ed8u: goto P_0c070ed8;
case 0x0c070edau: goto P_0c070eda;
case 0x0c070edcu: goto P_0c070edc;
case 0x0c070edeu: goto P_0c070ede;
case 0x0c070ee0u: goto P_0c070ee0;
case 0x0c070ee2u: goto P_0c070ee2;
case 0x0c070ee4u: goto P_0c070ee4;
case 0x0c070ee6u: goto P_0c070ee6;
case 0x0c070ee8u: goto P_0c070ee8;
case 0x0c070eeau: goto P_0c070eea;
case 0x0c070eecu: goto P_0c070eec;
case 0x0c070eeeu: goto P_0c070eee;
case 0x0c070ef4u: goto P_0c070ef4;
case 0x0c070ef6u: goto P_0c070ef6;
case 0x0c070ef8u: goto P_0c070ef8;
case 0x0c070efau: goto P_0c070efa;
case 0x0c070efcu: goto P_0c070efc;
case 0x0c070efeu: goto P_0c070efe;
case 0x0c070f00u: goto P_0c070f00;
case 0x0c070f02u: goto P_0c070f02;
case 0x0c070f04u: goto P_0c070f04;
case 0x0c070f06u: goto P_0c070f06;
case 0x0c070f08u: goto P_0c070f08;
case 0x0c070f0au: goto P_0c070f0a;
case 0x0c070f0cu: goto P_0c070f0c;
case 0x0c070f0eu: goto P_0c070f0e;
case 0x0c070f10u: goto P_0c070f10;
case 0x0c070f12u: goto P_0c070f12;
case 0x0c070f14u: goto P_0c070f14;
case 0x0c070f16u: goto P_0c070f16;
case 0x0c070f18u: goto P_0c070f18;
case 0x0c070f1au: goto P_0c070f1a;
case 0x0c070f1cu: goto P_0c070f1c;
case 0x0c070f1eu: goto P_0c070f1e;
case 0x0c070f20u: goto P_0c070f20;
case 0x0c070f22u: goto P_0c070f22;
case 0x0c070f24u: goto P_0c070f24;
case 0x0c070f26u: goto P_0c070f26;
case 0x0c070f28u: goto P_0c070f28;
case 0x0c070f2au: goto P_0c070f2a;
case 0x0c070f2cu: goto P_0c070f2c;
case 0x0c070f2eu: goto P_0c070f2e;
case 0x0c070f30u: goto P_0c070f30;
case 0x0c070f32u: goto P_0c070f32;
case 0x0c070f34u: goto P_0c070f34;
case 0x0c070f36u: goto P_0c070f36;
case 0x0c070f38u: goto P_0c070f38;
case 0x0c070f3au: goto P_0c070f3a;
case 0x0c070f40u: goto P_0c070f40;
case 0x0c070f42u: goto P_0c070f42;
case 0x0c070f44u: goto P_0c070f44;
case 0x0c070f46u: goto P_0c070f46;
case 0x0c070f48u: goto P_0c070f48;
case 0x0c070f4au: goto P_0c070f4a;
case 0x0c070f4cu: goto P_0c070f4c;
case 0x0c070f4eu: goto P_0c070f4e;
case 0x0c070f50u: goto P_0c070f50;
case 0x0c070f52u: goto P_0c070f52;
case 0x0c070f54u: goto P_0c070f54;
case 0x0c070f56u: goto P_0c070f56;
case 0x0c070f58u: goto P_0c070f58;
case 0x0c070f5au: goto P_0c070f5a;
case 0x0c070f5cu: goto P_0c070f5c;
case 0x0c070f5eu: goto P_0c070f5e;
case 0x0c070f60u: goto P_0c070f60;
case 0x0c070f62u: goto P_0c070f62;
case 0x0c070f64u: goto P_0c070f64;
case 0x0c070f66u: goto P_0c070f66;
case 0x0c070f68u: goto P_0c070f68;
case 0x0c070f6au: goto P_0c070f6a;
case 0x0c070f6cu: goto P_0c070f6c;
case 0x0c070f6eu: goto P_0c070f6e;
case 0x0c070f70u: goto P_0c070f70;
case 0x0c070f72u: goto P_0c070f72;
case 0x0c070f74u: goto P_0c070f74;
case 0x0c070f76u: goto P_0c070f76;
case 0x0c070f78u: goto P_0c070f78;
case 0x0c070f84u: goto P_0c070f84;
case 0x0c070f86u: goto P_0c070f86;
case 0x0c070f88u: goto P_0c070f88;
case 0x0c070f8au: goto P_0c070f8a;
case 0x0c070f8cu: goto P_0c070f8c;
case 0x0c070f8eu: goto P_0c070f8e;
case 0x0c070f90u: goto P_0c070f90;
case 0x0c070f92u: goto P_0c070f92;
case 0x0c070f94u: goto P_0c070f94;
case 0x0c070f96u: goto P_0c070f96;
case 0x0c070f98u: goto P_0c070f98;
case 0x0c070f9au: goto P_0c070f9a;
case 0x0c070f9cu: goto P_0c070f9c;
case 0x0c070f9eu: goto P_0c070f9e;
case 0x0c070fa0u: goto P_0c070fa0;
case 0x0c070fa2u: goto P_0c070fa2;
case 0x0c070fa4u: goto P_0c070fa4;
case 0x0c071070u: goto P_0c071070;
case 0x0c071072u: goto P_0c071072;
case 0x0c071074u: goto P_0c071074;
case 0x0c071076u: goto P_0c071076;
case 0x0c071078u: goto P_0c071078;
case 0x0c07107au: goto P_0c07107a;
case 0x0c07107cu: goto P_0c07107c;
case 0x0c07107eu: goto P_0c07107e;
case 0x0c071080u: goto P_0c071080;
case 0x0c071082u: goto P_0c071082;
case 0x0c071084u: goto P_0c071084;
case 0x0c071086u: goto P_0c071086;
case 0x0c071088u: goto P_0c071088;
case 0x0c07108au: goto P_0c07108a;
case 0x0c07108cu: goto P_0c07108c;
case 0x0c07108eu: goto P_0c07108e;
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
case 0x0c071400u: goto P_0c071400;
case 0x0c071402u: goto P_0c071402;
case 0x0c071404u: goto P_0c071404;
case 0x0c071406u: goto P_0c071406;
case 0x0c071408u: goto P_0c071408;
case 0x0c07140au: goto P_0c07140a;
case 0x0c071410u: goto P_0c071410;
case 0x0c071412u: goto P_0c071412;
case 0x0c071414u: goto P_0c071414;
case 0x0c071416u: goto P_0c071416;
case 0x0c071418u: goto P_0c071418;
case 0x0c07141au: goto P_0c07141a;
case 0x0c07141cu: goto P_0c07141c;
case 0x0c07141eu: goto P_0c07141e;
case 0x0c071420u: goto P_0c071420;
case 0x0c071422u: goto P_0c071422;
case 0x0c071424u: goto P_0c071424;
case 0x0c071426u: goto P_0c071426;
case 0x0c071428u: goto P_0c071428;
case 0x0c07142au: goto P_0c07142a;
case 0x0c07142cu: goto P_0c07142c;
case 0x0c07142eu: goto P_0c07142e;
case 0x0c071430u: goto P_0c071430;
case 0x0c071432u: goto P_0c071432;
case 0x0c071434u: goto P_0c071434;
case 0x0c071436u: goto P_0c071436;
case 0x0c071438u: goto P_0c071438;
case 0x0c07143au: goto P_0c07143a;
case 0x0c07143cu: goto P_0c07143c;
case 0x0c07143eu: goto P_0c07143e;
case 0x0c071440u: goto P_0c071440;
case 0x0c071442u: goto P_0c071442;
case 0x0c071444u: goto P_0c071444;
case 0x0c071446u: goto P_0c071446;
case 0x0c071448u: goto P_0c071448;
case 0x0c07144au: goto P_0c07144a;
case 0x0c07144cu: goto P_0c07144c;
case 0x0c07144eu: goto P_0c07144e;
case 0x0c071450u: goto P_0c071450;
case 0x0c071452u: goto P_0c071452;
case 0x0c071454u: goto P_0c071454;
case 0x0c071456u: goto P_0c071456;
case 0x0c07145cu: goto P_0c07145c;
case 0x0c07145eu: goto P_0c07145e;
case 0x0c071460u: goto P_0c071460;
case 0x0c071462u: goto P_0c071462;
case 0x0c071464u: goto P_0c071464;
case 0x0c071466u: goto P_0c071466;
case 0x0c071468u: goto P_0c071468;
case 0x0c07146au: goto P_0c07146a;
case 0x0c07146cu: goto P_0c07146c;
case 0x0c07146eu: goto P_0c07146e;
case 0x0c071470u: goto P_0c071470;
case 0x0c071472u: goto P_0c071472;
case 0x0c071474u: goto P_0c071474;
case 0x0c071476u: goto P_0c071476;
case 0x0c071478u: goto P_0c071478;
case 0x0c07147au: goto P_0c07147a;
case 0x0c07147cu: goto P_0c07147c;
case 0x0c07147eu: goto P_0c07147e;
case 0x0c071480u: goto P_0c071480;
case 0x0c071482u: goto P_0c071482;
case 0x0c071484u: goto P_0c071484;
case 0x0c071486u: goto P_0c071486;
case 0x0c071488u: goto P_0c071488;
case 0x0c07148au: goto P_0c07148a;
case 0x0c07148cu: goto P_0c07148c;
case 0x0c07148eu: goto P_0c07148e;
case 0x0c071490u: goto P_0c071490;
case 0x0c071492u: goto P_0c071492;
case 0x0c071494u: goto P_0c071494;
case 0x0c071496u: goto P_0c071496;
case 0x0c071498u: goto P_0c071498;
case 0x0c07149au: goto P_0c07149a;
case 0x0c07149cu: goto P_0c07149c;
case 0x0c07149eu: goto P_0c07149e;
case 0x0c0714a0u: goto P_0c0714a0;
case 0x0c0714a8u: goto P_0c0714a8;
case 0x0c0714aau: goto P_0c0714aa;
case 0x0c0714acu: goto P_0c0714ac;
case 0x0c0714aeu: goto P_0c0714ae;
case 0x0c0714b0u: goto P_0c0714b0;
case 0x0c0714b2u: goto P_0c0714b2;
case 0x0c0714b4u: goto P_0c0714b4;
case 0x0c0714b6u: goto P_0c0714b6;
case 0x0c0714b8u: goto P_0c0714b8;
case 0x0c0714bau: goto P_0c0714ba;
case 0x0c0714bcu: goto P_0c0714bc;
case 0x0c0714beu: goto P_0c0714be;
case 0x0c0714c0u: goto P_0c0714c0;
case 0x0c0714c2u: goto P_0c0714c2;
case 0x0c0714c4u: goto P_0c0714c4;
case 0x0c0714c6u: goto P_0c0714c6;
case 0x0c0714c8u: goto P_0c0714c8;
case 0x0c0714cau: goto P_0c0714ca;
case 0x0c0714ccu: goto P_0c0714cc;
case 0x0c0714ceu: goto P_0c0714ce;
case 0x0c0714d0u: goto P_0c0714d0;
case 0x0c0714d2u: goto P_0c0714d2;
case 0x0c0714d4u: goto P_0c0714d4;
case 0x0c0714d6u: goto P_0c0714d6;
case 0x0c0714d8u: goto P_0c0714d8;
case 0x0c0714dau: goto P_0c0714da;
case 0x0c0714dcu: goto P_0c0714dc;
case 0x0c0714deu: goto P_0c0714de;
case 0x0c0714e0u: goto P_0c0714e0;
case 0x0c0714ecu: goto P_0c0714ec;
case 0x0c0714eeu: goto P_0c0714ee;
case 0x0c0714f0u: goto P_0c0714f0;
case 0x0c0714f2u: goto P_0c0714f2;
case 0x0c0714f4u: goto P_0c0714f4;
case 0x0c0714f6u: goto P_0c0714f6;
case 0x0c0714f8u: goto P_0c0714f8;
case 0x0c0714fau: goto P_0c0714fa;
case 0x0c0714fcu: goto P_0c0714fc;
case 0x0c0714feu: goto P_0c0714fe;
case 0x0c071500u: goto P_0c071500;
case 0x0c071502u: goto P_0c071502;
case 0x0c071504u: goto P_0c071504;
case 0x0c071506u: goto P_0c071506;
case 0x0c071508u: goto P_0c071508;
case 0x0c07150au: goto P_0c07150a;
case 0x0c07150cu: goto P_0c07150c;
case 0x0c0715b0u: goto P_0c0715b0;
case 0x0c0715b2u: goto P_0c0715b2;
case 0x0c0715b4u: goto P_0c0715b4;
case 0x0c0715b6u: goto P_0c0715b6;
case 0x0c0715b8u: goto P_0c0715b8;
case 0x0c0715bau: goto P_0c0715ba;
case 0x0c0715bcu: goto P_0c0715bc;
case 0x0c0715beu: goto P_0c0715be;
case 0x0c0715c0u: goto P_0c0715c0;
case 0x0c0715c2u: goto P_0c0715c2;
case 0x0c0715c4u: goto P_0c0715c4;
case 0x0c0715c6u: goto P_0c0715c6;
case 0x0c0715c8u: goto P_0c0715c8;
case 0x0c0715cau: goto P_0c0715ca;
case 0x0c0715ccu: goto P_0c0715cc;
case 0x0c0715ceu: goto P_0c0715ce;
case 0x0c0715d0u: goto P_0c0715d0;
case 0x0c0715d2u: goto P_0c0715d2;
case 0x0c0715d4u: goto P_0c0715d4;
case 0x0c0715d6u: goto P_0c0715d6;
case 0x0c0715d8u: goto P_0c0715d8;
case 0x0c0715dau: goto P_0c0715da;
case 0x0c0715dcu: goto P_0c0715dc;
case 0x0c0715deu: goto P_0c0715de;
case 0x0c0715e0u: goto P_0c0715e0;
case 0x0c0715e2u: goto P_0c0715e2;
case 0x0c0715e4u: goto P_0c0715e4;
case 0x0c0715e6u: goto P_0c0715e6;
case 0x0c0715e8u: goto P_0c0715e8;
case 0x0c0715eau: goto P_0c0715ea;
case 0x0c0715ecu: goto P_0c0715ec;
case 0x0c0715eeu: goto P_0c0715ee;
case 0x0c0715f0u: goto P_0c0715f0;
case 0x0c0715f2u: goto P_0c0715f2;
case 0x0c0715f4u: goto P_0c0715f4;
case 0x0c0715f6u: goto P_0c0715f6;
case 0x0c0715f8u: goto P_0c0715f8;
case 0x0c0715fau: goto P_0c0715fa;
case 0x0c0715fcu: goto P_0c0715fc;
case 0x0c0715feu: goto P_0c0715fe;
case 0x0c071600u: goto P_0c071600;
case 0x0c071602u: goto P_0c071602;
case 0x0c071604u: goto P_0c071604;
case 0x0c071606u: goto P_0c071606;
case 0x0c071608u: goto P_0c071608;
case 0x0c07160au: goto P_0c07160a;
case 0x0c07160cu: goto P_0c07160c;
case 0x0c07160eu: goto P_0c07160e;
case 0x0c071610u: goto P_0c071610;
case 0x0c071612u: goto P_0c071612;
case 0x0c071614u: goto P_0c071614;
case 0x0c071616u: goto P_0c071616;
case 0x0c071618u: goto P_0c071618;
case 0x0c07161au: goto P_0c07161a;
case 0x0c07161cu: goto P_0c07161c;
case 0x0c07161eu: goto P_0c07161e;
case 0x0c071620u: goto P_0c071620;
case 0x0c071622u: goto P_0c071622;
case 0x0c071624u: goto P_0c071624;
case 0x0c07162cu: goto P_0c07162c;
case 0x0c07162eu: goto P_0c07162e;
case 0x0c071630u: goto P_0c071630;
case 0x0c071632u: goto P_0c071632;
case 0x0c071634u: goto P_0c071634;
case 0x0c071636u: goto P_0c071636;
case 0x0c071638u: goto P_0c071638;
case 0x0c07163au: goto P_0c07163a;
case 0x0c07163cu: goto P_0c07163c;
case 0x0c07163eu: goto P_0c07163e;
case 0x0c071640u: goto P_0c071640;
case 0x0c071642u: goto P_0c071642;
case 0x0c071644u: goto P_0c071644;
case 0x0c071646u: goto P_0c071646;
case 0x0c071648u: goto P_0c071648;
case 0x0c07164au: goto P_0c07164a;
case 0x0c07164cu: goto P_0c07164c;
case 0x0c07164eu: goto P_0c07164e;
case 0x0c071650u: goto P_0c071650;
case 0x0c071652u: goto P_0c071652;
case 0x0c071654u: goto P_0c071654;
case 0x0c071656u: goto P_0c071656;
case 0x0c071658u: goto P_0c071658;
case 0x0c07165au: goto P_0c07165a;
case 0x0c07165cu: goto P_0c07165c;
case 0x0c07165eu: goto P_0c07165e;
case 0x0c071660u: goto P_0c071660;
case 0x0c071662u: goto P_0c071662;
case 0x0c071664u: goto P_0c071664;
case 0x0c071666u: goto P_0c071666;
case 0x0c071668u: goto P_0c071668;
case 0x0c07166au: goto P_0c07166a;
case 0x0c07166cu: goto P_0c07166c;
case 0x0c07166eu: goto P_0c07166e;
case 0x0c071670u: goto P_0c071670;
case 0x0c071672u: goto P_0c071672;
case 0x0c071674u: goto P_0c071674;
case 0x0c071676u: goto P_0c071676;
case 0x0c071678u: goto P_0c071678;
case 0x0c07167au: goto P_0c07167a;
case 0x0c07167cu: goto P_0c07167c;
case 0x0c07167eu: goto P_0c07167e;
case 0x0c071680u: goto P_0c071680;
case 0x0c071682u: goto P_0c071682;
case 0x0c071684u: goto P_0c071684;
case 0x0c071686u: goto P_0c071686;
case 0x0c071688u: goto P_0c071688;
case 0x0c07168au: goto P_0c07168a;
case 0x0c07168cu: goto P_0c07168c;
case 0x0c07168eu: goto P_0c07168e;
case 0x0c071690u: goto P_0c071690;
case 0x0c071692u: goto P_0c071692;
case 0x0c071694u: goto P_0c071694;
case 0x0c071696u: goto P_0c071696;
case 0x0c071698u: goto P_0c071698;
case 0x0c07169au: goto P_0c07169a;
case 0x0c07169cu: goto P_0c07169c;
case 0x0c07169eu: goto P_0c07169e;
case 0x0c0716a0u: goto P_0c0716a0;
case 0x0c0716a2u: goto P_0c0716a2;
case 0x0c0716a4u: goto P_0c0716a4;
case 0x0c0716a6u: goto P_0c0716a6;
case 0x0c0716a8u: goto P_0c0716a8;
case 0x0c0716aau: goto P_0c0716aa;
case 0x0c0716acu: goto P_0c0716ac;
case 0x0c0716aeu: goto P_0c0716ae;
case 0x0c0716b0u: goto P_0c0716b0;
case 0x0c0716b2u: goto P_0c0716b2;
case 0x0c0716b4u: goto P_0c0716b4;
case 0x0c0716b6u: goto P_0c0716b6;
case 0x0c0716b8u: goto P_0c0716b8;
case 0x0c0716bau: goto P_0c0716ba;
case 0x0c0716bcu: goto P_0c0716bc;
case 0x0c0716beu: goto P_0c0716be;
case 0x0c0716c0u: goto P_0c0716c0;
case 0x0c0716c2u: goto P_0c0716c2;
case 0x0c0716c4u: goto P_0c0716c4;
case 0x0c0716c6u: goto P_0c0716c6;
case 0x0c0716c8u: goto P_0c0716c8;
case 0x0c0716cau: goto P_0c0716ca;
case 0x0c0716ccu: goto P_0c0716cc;
case 0x0c0716ceu: goto P_0c0716ce;
case 0x0c0716d0u: goto P_0c0716d0;
case 0x0c0716d2u: goto P_0c0716d2;
case 0x0c0716d4u: goto P_0c0716d4;
case 0x0c0716d6u: goto P_0c0716d6;
case 0x0c0716d8u: goto P_0c0716d8;
case 0x0c0716dau: goto P_0c0716da;
case 0x0c0716dcu: goto P_0c0716dc;
case 0x0c0716deu: goto P_0c0716de;
case 0x0c0716e0u: goto P_0c0716e0;
case 0x0c0716e2u: goto P_0c0716e2;
case 0x0c0716e4u: goto P_0c0716e4;
case 0x0c0716e6u: goto P_0c0716e6;
case 0x0c0716e8u: goto P_0c0716e8;
case 0x0c0716eau: goto P_0c0716ea;
case 0x0c0716ecu: goto P_0c0716ec;
case 0x0c0716eeu: goto P_0c0716ee;
case 0x0c0716f0u: goto P_0c0716f0;
case 0x0c0716f2u: goto P_0c0716f2;
case 0x0c0716f4u: goto P_0c0716f4;
case 0x0c0716f6u: goto P_0c0716f6;
case 0x0c0716f8u: goto P_0c0716f8;
case 0x0c0716fau: goto P_0c0716fa;
case 0x0c071704u: goto P_0c071704;
case 0x0c071706u: goto P_0c071706;
case 0x0c071708u: goto P_0c071708;
case 0x0c07170au: goto P_0c07170a;
case 0x0c07170cu: goto P_0c07170c;
case 0x0c07170eu: goto P_0c07170e;
case 0x0c071710u: goto P_0c071710;
case 0x0c071712u: goto P_0c071712;
case 0x0c071714u: goto P_0c071714;
case 0x0c071716u: goto P_0c071716;
case 0x0c071718u: goto P_0c071718;
case 0x0c07171au: goto P_0c07171a;
case 0x0c07171cu: goto P_0c07171c;
case 0x0c07171eu: goto P_0c07171e;
case 0x0c071720u: goto P_0c071720;
case 0x0c071722u: goto P_0c071722;
case 0x0c071724u: goto P_0c071724;
case 0x0c071726u: goto P_0c071726;
case 0x0c071728u: goto P_0c071728;
case 0x0c07172au: goto P_0c07172a;
case 0x0c07172cu: goto P_0c07172c;
case 0x0c07172eu: goto P_0c07172e;
case 0x0c071730u: goto P_0c071730;
case 0x0c071732u: goto P_0c071732;
case 0x0c071734u: goto P_0c071734;
case 0x0c071736u: goto P_0c071736;
case 0x0c071738u: goto P_0c071738;
case 0x0c07173au: goto P_0c07173a;
case 0x0c07173cu: goto P_0c07173c;
case 0x0c07173eu: goto P_0c07173e;
case 0x0c071740u: goto P_0c071740;
case 0x0c071742u: goto P_0c071742;
case 0x0c071744u: goto P_0c071744;
case 0x0c071746u: goto P_0c071746;
case 0x0c071748u: goto P_0c071748;
case 0x0c07174au: goto P_0c07174a;
case 0x0c07174cu: goto P_0c07174c;
case 0x0c07174eu: goto P_0c07174e;
case 0x0c071750u: goto P_0c071750;
case 0x0c071752u: goto P_0c071752;
case 0x0c071754u: goto P_0c071754;
case 0x0c071756u: goto P_0c071756;
case 0x0c071758u: goto P_0c071758;
case 0x0c07175au: goto P_0c07175a;
case 0x0c07175cu: goto P_0c07175c;
case 0x0c07175eu: goto P_0c07175e;
case 0x0c071760u: goto P_0c071760;
case 0x0c071762u: goto P_0c071762;
case 0x0c071764u: goto P_0c071764;
case 0x0c071766u: goto P_0c071766;
case 0x0c071768u: goto P_0c071768;
case 0x0c07176au: goto P_0c07176a;
case 0x0c07176cu: goto P_0c07176c;
case 0x0c07176eu: goto P_0c07176e;
case 0x0c071770u: goto P_0c071770;
case 0x0c071772u: goto P_0c071772;
case 0x0c071774u: goto P_0c071774;
case 0x0c071776u: goto P_0c071776;
case 0x0c071778u: goto P_0c071778;
case 0x0c07177au: goto P_0c07177a;
case 0x0c07177cu: goto P_0c07177c;
case 0x0c07177eu: goto P_0c07177e;
case 0x0c071780u: goto P_0c071780;
case 0x0c071782u: goto P_0c071782;
case 0x0c071784u: goto P_0c071784;
case 0x0c071786u: goto P_0c071786;
case 0x0c071788u: goto P_0c071788;
case 0x0c07178au: goto P_0c07178a;
case 0x0c07178cu: goto P_0c07178c;
case 0x0c07178eu: goto P_0c07178e;
case 0x0c071790u: goto P_0c071790;
case 0x0c071792u: goto P_0c071792;
case 0x0c071794u: goto P_0c071794;
case 0x0c071796u: goto P_0c071796;
case 0x0c071798u: goto P_0c071798;
case 0x0c07179au: goto P_0c07179a;
case 0x0c07179cu: goto P_0c07179c;
case 0x0c07179eu: goto P_0c07179e;
case 0x0c0717a0u: goto P_0c0717a0;
case 0x0c0717a2u: goto P_0c0717a2;
case 0x0c0717a4u: goto P_0c0717a4;
case 0x0c0717a6u: goto P_0c0717a6;
case 0x0c0717a8u: goto P_0c0717a8;
case 0x0c0717aau: goto P_0c0717aa;
case 0x0c0717acu: goto P_0c0717ac;
case 0x0c0717aeu: goto P_0c0717ae;
case 0x0c0717b0u: goto P_0c0717b0;
case 0x0c0717b2u: goto P_0c0717b2;
case 0x0c0717b4u: goto P_0c0717b4;
case 0x0c0717b6u: goto P_0c0717b6;
case 0x0c0717b8u: goto P_0c0717b8;
case 0x0c0717bau: goto P_0c0717ba;
case 0x0c0717bcu: goto P_0c0717bc;
case 0x0c0717beu: goto P_0c0717be;
case 0x0c0717c0u: goto P_0c0717c0;
case 0x0c0717c2u: goto P_0c0717c2;
case 0x0c0717c4u: goto P_0c0717c4;
case 0x0c0717c6u: goto P_0c0717c6;
case 0x0c0717c8u: goto P_0c0717c8;
case 0x0c0717cau: goto P_0c0717ca;
case 0x0c0717ccu: goto P_0c0717cc;
case 0x0c0717ceu: goto P_0c0717ce;
case 0x0c0717d0u: goto P_0c0717d0;
case 0x0c0717d2u: goto P_0c0717d2;
case 0x0c0717d4u: goto P_0c0717d4;
case 0x0c0717d6u: goto P_0c0717d6;
case 0x0c0717d8u: goto P_0c0717d8;
case 0x0c0717dau: goto P_0c0717da;
case 0x0c0717dcu: goto P_0c0717dc;
case 0x0c0717deu: goto P_0c0717de;
case 0x0c0717e0u: goto P_0c0717e0;
case 0x0c0717e2u: goto P_0c0717e2;
case 0x0c0717e4u: goto P_0c0717e4;
case 0x0c0717e6u: goto P_0c0717e6;
case 0x0c0717e8u: goto P_0c0717e8;
case 0x0c0717eau: goto P_0c0717ea;
case 0x0c0717ecu: goto P_0c0717ec;
case 0x0c0717eeu: goto P_0c0717ee;
case 0x0c0717f0u: goto P_0c0717f0;
case 0x0c0717f2u: goto P_0c0717f2;
case 0x0c0717f4u: goto P_0c0717f4;
case 0x0c0717f6u: goto P_0c0717f6;
case 0x0c0717f8u: goto P_0c0717f8;
case 0x0c0717fau: goto P_0c0717fa;
case 0x0c0717fcu: goto P_0c0717fc;
case 0x0c0717feu: goto P_0c0717fe;
case 0x0c071800u: goto P_0c071800;
case 0x0c071802u: goto P_0c071802;
case 0x0c071804u: goto P_0c071804;
case 0x0c071806u: goto P_0c071806;
case 0x0c071808u: goto P_0c071808;
case 0x0c07180au: goto P_0c07180a;
case 0x0c07180cu: goto P_0c07180c;
case 0x0c07180eu: goto P_0c07180e;
case 0x0c071810u: goto P_0c071810;
case 0x0c071812u: goto P_0c071812;
case 0x0c071814u: goto P_0c071814;
case 0x0c071816u: goto P_0c071816;
case 0x0c071818u: goto P_0c071818;
case 0x0c07181au: goto P_0c07181a;
case 0x0c07181cu: goto P_0c07181c;
case 0x0c07181eu: goto P_0c07181e;
case 0x0c071820u: goto P_0c071820;
case 0x0c071822u: goto P_0c071822;
case 0x0c071824u: goto P_0c071824;
case 0x0c071826u: goto P_0c071826;
case 0x0c071828u: goto P_0c071828;
case 0x0c07182au: goto P_0c07182a;
case 0x0c07182cu: goto P_0c07182c;
case 0x0c07182eu: goto P_0c07182e;
case 0x0c071830u: goto P_0c071830;
case 0x0c071832u: goto P_0c071832;
case 0x0c071834u: goto P_0c071834;
case 0x0c071836u: goto P_0c071836;
case 0x0c071838u: goto P_0c071838;
case 0x0c07183au: goto P_0c07183a;
case 0x0c07183cu: goto P_0c07183c;
case 0x0c07183eu: goto P_0c07183e;
case 0x0c071840u: goto P_0c071840;
case 0x0c071842u: goto P_0c071842;
case 0x0c071844u: goto P_0c071844;
case 0x0c071846u: goto P_0c071846;
case 0x0c071848u: goto P_0c071848;
case 0x0c07184au: goto P_0c07184a;
case 0x0c07184cu: goto P_0c07184c;
case 0x0c07184eu: goto P_0c07184e;
case 0x0c071850u: goto P_0c071850;
case 0x0c071852u: goto P_0c071852;
case 0x0c071854u: goto P_0c071854;
case 0x0c071856u: goto P_0c071856;
case 0x0c071858u: goto P_0c071858;
case 0x0c07185au: goto P_0c07185a;
case 0x0c07185cu: goto P_0c07185c;
case 0x0c07185eu: goto P_0c07185e;
case 0x0c071860u: goto P_0c071860;
case 0x0c071862u: goto P_0c071862;
case 0x0c071864u: goto P_0c071864;
case 0x0c071866u: goto P_0c071866;
case 0x0c071868u: goto P_0c071868;
case 0x0c07186au: goto P_0c07186a;
case 0x0c07186cu: goto P_0c07186c;
case 0x0c07186eu: goto P_0c07186e;
case 0x0c071870u: goto P_0c071870;
case 0x0c071878u: goto P_0c071878;
case 0x0c07187au: goto P_0c07187a;
case 0x0c07187cu: goto P_0c07187c;
case 0x0c07187eu: goto P_0c07187e;
case 0x0c071880u: goto P_0c071880;
case 0x0c071882u: goto P_0c071882;
case 0x0c071884u: goto P_0c071884;
case 0x0c071886u: goto P_0c071886;
case 0x0c071888u: goto P_0c071888;
case 0x0c07188au: goto P_0c07188a;
case 0x0c07188cu: goto P_0c07188c;
case 0x0c07188eu: goto P_0c07188e;
case 0x0c071890u: goto P_0c071890;
case 0x0c071892u: goto P_0c071892;
case 0x0c071894u: goto P_0c071894;
case 0x0c071896u: goto P_0c071896;
case 0x0c071898u: goto P_0c071898;
case 0x0c07189au: goto P_0c07189a;
case 0x0c07189cu: goto P_0c07189c;
case 0x0c07189eu: goto P_0c07189e;
case 0x0c0718a0u: goto P_0c0718a0;
case 0x0c0718a2u: goto P_0c0718a2;
case 0x0c0718a4u: goto P_0c0718a4;
case 0x0c0718a6u: goto P_0c0718a6;
case 0x0c0718a8u: goto P_0c0718a8;
case 0x0c0718aau: goto P_0c0718aa;
case 0x0c0718acu: goto P_0c0718ac;
case 0x0c0718aeu: goto P_0c0718ae;
case 0x0c0718b0u: goto P_0c0718b0;
case 0x0c0718b2u: goto P_0c0718b2;
case 0x0c0718b4u: goto P_0c0718b4;
case 0x0c0718b6u: goto P_0c0718b6;
case 0x0c0718b8u: goto P_0c0718b8;
case 0x0c0718bau: goto P_0c0718ba;
case 0x0c0718bcu: goto P_0c0718bc;
case 0x0c0718beu: goto P_0c0718be;
case 0x0c0718c0u: goto P_0c0718c0;
case 0x0c0718c2u: goto P_0c0718c2;
case 0x0c0718c4u: goto P_0c0718c4;
case 0x0c0718c6u: goto P_0c0718c6;
case 0x0c0718c8u: goto P_0c0718c8;
case 0x0c0718cau: goto P_0c0718ca;
case 0x0c0718ccu: goto P_0c0718cc;
case 0x0c0718ceu: goto P_0c0718ce;
case 0x0c0718d0u: goto P_0c0718d0;
case 0x0c0718d2u: goto P_0c0718d2;
case 0x0c0718d4u: goto P_0c0718d4;
case 0x0c0718d6u: goto P_0c0718d6;
case 0x0c0718d8u: goto P_0c0718d8;
case 0x0c0718dau: goto P_0c0718da;
case 0x0c0718dcu: goto P_0c0718dc;
case 0x0c0718deu: goto P_0c0718de;
case 0x0c0718e0u: goto P_0c0718e0;
case 0x0c0718e2u: goto P_0c0718e2;
case 0x0c0718e4u: goto P_0c0718e4;
case 0x0c0718e6u: goto P_0c0718e6;
case 0x0c0718e8u: goto P_0c0718e8;
case 0x0c0718eau: goto P_0c0718ea;
case 0x0c0718ecu: goto P_0c0718ec;
case 0x0c0718eeu: goto P_0c0718ee;
case 0x0c0718f0u: goto P_0c0718f0;
case 0x0c0718f2u: goto P_0c0718f2;
case 0x0c0718f4u: goto P_0c0718f4;
case 0x0c0718f6u: goto P_0c0718f6;
case 0x0c0718f8u: goto P_0c0718f8;
case 0x0c0718fau: goto P_0c0718fa;
case 0x0c0718fcu: goto P_0c0718fc;
case 0x0c0718feu: goto P_0c0718fe;
case 0x0c071900u: goto P_0c071900;
case 0x0c071902u: goto P_0c071902;
case 0x0c071904u: goto P_0c071904;
case 0x0c071906u: goto P_0c071906;
case 0x0c071908u: goto P_0c071908;
case 0x0c07190au: goto P_0c07190a;
case 0x0c07190cu: goto P_0c07190c;
case 0x0c07190eu: goto P_0c07190e;
case 0x0c071910u: goto P_0c071910;
case 0x0c071912u: goto P_0c071912;
case 0x0c071914u: goto P_0c071914;
case 0x0c071916u: goto P_0c071916;
case 0x0c071918u: goto P_0c071918;
case 0x0c07191au: goto P_0c07191a;
case 0x0c07191cu: goto P_0c07191c;
case 0x0c07191eu: goto P_0c07191e;
case 0x0c071920u: goto P_0c071920;
case 0x0c071922u: goto P_0c071922;
case 0x0c071924u: goto P_0c071924;
case 0x0c071926u: goto P_0c071926;
case 0x0c071928u: goto P_0c071928;
case 0x0c07192au: goto P_0c07192a;
case 0x0c071930u: goto P_0c071930;
case 0x0c071932u: goto P_0c071932;
case 0x0c071934u: goto P_0c071934;
case 0x0c071936u: goto P_0c071936;
case 0x0c071938u: goto P_0c071938;
case 0x0c07193au: goto P_0c07193a;
case 0x0c07193cu: goto P_0c07193c;
case 0x0c07193eu: goto P_0c07193e;
case 0x0c071940u: goto P_0c071940;
case 0x0c071942u: goto P_0c071942;
case 0x0c071944u: goto P_0c071944;
case 0x0c071946u: goto P_0c071946;
case 0x0c071948u: goto P_0c071948;
case 0x0c07194au: goto P_0c07194a;
case 0x0c07194cu: goto P_0c07194c;
case 0x0c07194eu: goto P_0c07194e;
case 0x0c071950u: goto P_0c071950;
case 0x0c071952u: goto P_0c071952;
case 0x0c071954u: goto P_0c071954;
case 0x0c071956u: goto P_0c071956;
case 0x0c071958u: goto P_0c071958;
case 0x0c07195au: goto P_0c07195a;
case 0x0c07195cu: goto P_0c07195c;
case 0x0c07195eu: goto P_0c07195e;
case 0x0c071960u: goto P_0c071960;
case 0x0c071962u: goto P_0c071962;
case 0x0c071964u: goto P_0c071964;
case 0x0c071966u: goto P_0c071966;
case 0x0c071968u: goto P_0c071968;
case 0x0c07196au: goto P_0c07196a;
case 0x0c07196cu: goto P_0c07196c;
case 0x0c07196eu: goto P_0c07196e;
case 0x0c071970u: goto P_0c071970;
case 0x0c071972u: goto P_0c071972;
case 0x0c071974u: goto P_0c071974;
case 0x0c071976u: goto P_0c071976;
case 0x0c071978u: goto P_0c071978;
case 0x0c07197au: goto P_0c07197a;
case 0x0c07197cu: goto P_0c07197c;
case 0x0c07197eu: goto P_0c07197e;
case 0x0c071980u: goto P_0c071980;
case 0x0c071982u: goto P_0c071982;
case 0x0c071984u: goto P_0c071984;
case 0x0c071986u: goto P_0c071986;
case 0x0c071988u: goto P_0c071988;
case 0x0c07198au: goto P_0c07198a;
case 0x0c07198cu: goto P_0c07198c;
case 0x0c07198eu: goto P_0c07198e;
case 0x0c071990u: goto P_0c071990;
case 0x0c071992u: goto P_0c071992;
case 0x0c071994u: goto P_0c071994;
case 0x0c071996u: goto P_0c071996;
case 0x0c071998u: goto P_0c071998;
case 0x0c07199au: goto P_0c07199a;
case 0x0c07199cu: goto P_0c07199c;
case 0x0c07199eu: goto P_0c07199e;
case 0x0c0719a0u: goto P_0c0719a0;
case 0x0c0719a2u: goto P_0c0719a2;
case 0x0c0719a4u: goto P_0c0719a4;
case 0x0c0719a6u: goto P_0c0719a6;
case 0x0c0719a8u: goto P_0c0719a8;
case 0x0c0719aau: goto P_0c0719aa;
case 0x0c0719acu: goto P_0c0719ac;
case 0x0c0719aeu: goto P_0c0719ae;
case 0x0c0719b0u: goto P_0c0719b0;
case 0x0c0719b2u: goto P_0c0719b2;
case 0x0c0719b4u: goto P_0c0719b4;
case 0x0c0719b6u: goto P_0c0719b6;
case 0x0c0719b8u: goto P_0c0719b8;
case 0x0c0719bau: goto P_0c0719ba;
case 0x0c0719bcu: goto P_0c0719bc;
case 0x0c0719beu: goto P_0c0719be;
case 0x0c0719c0u: goto P_0c0719c0;
case 0x0c0719c2u: goto P_0c0719c2;
case 0x0c0719c4u: goto P_0c0719c4;
case 0x0c0719c6u: goto P_0c0719c6;
case 0x0c0719c8u: goto P_0c0719c8;
case 0x0c0719cau: goto P_0c0719ca;
case 0x0c0719ccu: goto P_0c0719cc;
case 0x0c0719ceu: goto P_0c0719ce;
case 0x0c0719d0u: goto P_0c0719d0;
case 0x0c0719d2u: goto P_0c0719d2;
case 0x0c0719d4u: goto P_0c0719d4;
case 0x0c0719d6u: goto P_0c0719d6;
case 0x0c0719d8u: goto P_0c0719d8;
case 0x0c0719dau: goto P_0c0719da;
case 0x0c0719dcu: goto P_0c0719dc;
case 0x0c0719deu: goto P_0c0719de;
case 0x0c0719e0u: goto P_0c0719e0;
case 0x0c0719e2u: goto P_0c0719e2;
case 0x0c0719e4u: goto P_0c0719e4;
case 0x0c0719e6u: goto P_0c0719e6;
case 0x0c0719e8u: goto P_0c0719e8;
case 0x0c0719eau: goto P_0c0719ea;
case 0x0c0719ecu: goto P_0c0719ec;
case 0x0c0719eeu: goto P_0c0719ee;
case 0x0c0719f0u: goto P_0c0719f0;
case 0x0c0719f2u: goto P_0c0719f2;
case 0x0c0719f4u: goto P_0c0719f4;
case 0x0c0719f6u: goto P_0c0719f6;
case 0x0c0719f8u: goto P_0c0719f8;
case 0x0c0719fau: goto P_0c0719fa;
case 0x0c0719fcu: goto P_0c0719fc;
case 0x0c0719feu: goto P_0c0719fe;
case 0x0c071a00u: goto P_0c071a00;
case 0x0c071a02u: goto P_0c071a02;
case 0x0c071a04u: goto P_0c071a04;
case 0x0c071a06u: goto P_0c071a06;
case 0x0c071a08u: goto P_0c071a08;
case 0x0c071a0au: goto P_0c071a0a;
case 0x0c071a0cu: goto P_0c071a0c;
case 0x0c071a0eu: goto P_0c071a0e;
case 0x0c071a10u: goto P_0c071a10;
case 0x0c071a12u: goto P_0c071a12;
case 0x0c071a14u: goto P_0c071a14;
case 0x0c071a16u: goto P_0c071a16;
case 0x0c071a18u: goto P_0c071a18;
case 0x0c071a1au: goto P_0c071a1a;
case 0x0c071a1cu: goto P_0c071a1c;
case 0x0c071a1eu: goto P_0c071a1e;
case 0x0c071a20u: goto P_0c071a20;
case 0x0c071a22u: goto P_0c071a22;
case 0x0c071a24u: goto P_0c071a24;
case 0x0c071a26u: goto P_0c071a26;
case 0x0c071a28u: goto P_0c071a28;
case 0x0c071a2au: goto P_0c071a2a;
case 0x0c071a2cu: goto P_0c071a2c;
case 0x0c071a2eu: goto P_0c071a2e;
case 0x0c071a30u: goto P_0c071a30;
case 0x0c071a32u: goto P_0c071a32;
case 0x0c071a34u: goto P_0c071a34;
case 0x0c071a36u: goto P_0c071a36;
case 0x0c071a38u: goto P_0c071a38;
case 0x0c071a3au: goto P_0c071a3a;
case 0x0c071a3cu: goto P_0c071a3c;
case 0x0c071a3eu: goto P_0c071a3e;
case 0x0c071a40u: goto P_0c071a40;
case 0x0c071a42u: goto P_0c071a42;
case 0x0c071a44u: goto P_0c071a44;
case 0x0c071a46u: goto P_0c071a46;
case 0x0c071a48u: goto P_0c071a48;
case 0x0c071a4au: goto P_0c071a4a;
case 0x0c071a4cu: goto P_0c071a4c;
case 0x0c071a4eu: goto P_0c071a4e;
case 0x0c071a50u: goto P_0c071a50;
case 0x0c071a52u: goto P_0c071a52;
case 0x0c071a54u: goto P_0c071a54;
case 0x0c071a56u: goto P_0c071a56;
case 0x0c071a58u: goto P_0c071a58;
case 0x0c071a5au: goto P_0c071a5a;
case 0x0c071a5cu: goto P_0c071a5c;
case 0x0c071a5eu: goto P_0c071a5e;
case 0x0c071a60u: goto P_0c071a60;
case 0x0c071a62u: goto P_0c071a62;
case 0x0c071a64u: goto P_0c071a64;
case 0x0c071a66u: goto P_0c071a66;
case 0x0c071a68u: goto P_0c071a68;
case 0x0c071a6au: goto P_0c071a6a;
case 0x0c071a6cu: goto P_0c071a6c;
case 0x0c071a6eu: goto P_0c071a6e;
case 0x0c071a70u: goto P_0c071a70;
case 0x0c071a72u: goto P_0c071a72;
case 0x0c071a74u: goto P_0c071a74;
case 0x0c071a76u: goto P_0c071a76;
case 0x0c071a78u: goto P_0c071a78;
case 0x0c071a7au: goto P_0c071a7a;
case 0x0c071a7cu: goto P_0c071a7c;
case 0x0c071a7eu: goto P_0c071a7e;
case 0x0c071a80u: goto P_0c071a80;
case 0x0c071a82u: goto P_0c071a82;
case 0x0c071a84u: goto P_0c071a84;
case 0x0c071a86u: goto P_0c071a86;
case 0x0c071a88u: goto P_0c071a88;
case 0x0c071a8au: goto P_0c071a8a;
case 0x0c071a8cu: goto P_0c071a8c;
case 0x0c071a8eu: goto P_0c071a8e;
case 0x0c071a90u: goto P_0c071a90;
case 0x0c071a92u: goto P_0c071a92;
case 0x0c071a94u: goto P_0c071a94;
case 0x0c071a96u: goto P_0c071a96;
case 0x0c071a98u: goto P_0c071a98;
case 0x0c071a9au: goto P_0c071a9a;
case 0x0c071a9cu: goto P_0c071a9c;
case 0x0c071a9eu: goto P_0c071a9e;
case 0x0c071aa4u: goto P_0c071aa4;
case 0x0c071aa6u: goto P_0c071aa6;
case 0x0c071aa8u: goto P_0c071aa8;
case 0x0c071aaau: goto P_0c071aaa;
case 0x0c071aacu: goto P_0c071aac;
case 0x0c071aaeu: goto P_0c071aae;
case 0x0c071ab0u: goto P_0c071ab0;
case 0x0c071ab2u: goto P_0c071ab2;
case 0x0c071ab4u: goto P_0c071ab4;
case 0x0c071ab6u: goto P_0c071ab6;
case 0x0c071ab8u: goto P_0c071ab8;
case 0x0c071abau: goto P_0c071aba;
case 0x0c071abcu: goto P_0c071abc;
case 0x0c071abeu: goto P_0c071abe;
case 0x0c071ac0u: goto P_0c071ac0;
case 0x0c071ac2u: goto P_0c071ac2;
case 0x0c071ac4u: goto P_0c071ac4;
case 0x0c071ac6u: goto P_0c071ac6;
case 0x0c071ac8u: goto P_0c071ac8;
case 0x0c071acau: goto P_0c071aca;
case 0x0c071accu: goto P_0c071acc;
case 0x0c071aceu: goto P_0c071ace;
case 0x0c071ad0u: goto P_0c071ad0;
case 0x0c071ad2u: goto P_0c071ad2;
case 0x0c071ad4u: goto P_0c071ad4;
case 0x0c071ad6u: goto P_0c071ad6;
case 0x0c071ad8u: goto P_0c071ad8;
case 0x0c071adau: goto P_0c071ada;
case 0x0c071adcu: goto P_0c071adc;
case 0x0c071adeu: goto P_0c071ade;
case 0x0c071ae0u: goto P_0c071ae0;
case 0x0c071ae2u: goto P_0c071ae2;
case 0x0c071ae4u: goto P_0c071ae4;
case 0x0c071ae6u: goto P_0c071ae6;
case 0x0c071ae8u: goto P_0c071ae8;
case 0x0c071aeau: goto P_0c071aea;
case 0x0c071aecu: goto P_0c071aec;
case 0x0c071aeeu: goto P_0c071aee;
case 0x0c071af0u: goto P_0c071af0;
case 0x0c071af2u: goto P_0c071af2;
case 0x0c071af4u: goto P_0c071af4;
case 0x0c071af6u: goto P_0c071af6;
case 0x0c071af8u: goto P_0c071af8;
case 0x0c071afau: goto P_0c071afa;
case 0x0c071afcu: goto P_0c071afc;
case 0x0c071afeu: goto P_0c071afe;
case 0x0c071b00u: goto P_0c071b00;
case 0x0c071b02u: goto P_0c071b02;
case 0x0c071b04u: goto P_0c071b04;
case 0x0c071b06u: goto P_0c071b06;
case 0x0c071b08u: goto P_0c071b08;
case 0x0c071b0au: goto P_0c071b0a;
case 0x0c071b0cu: goto P_0c071b0c;
case 0x0c071b0eu: goto P_0c071b0e;
case 0x0c071b10u: goto P_0c071b10;
case 0x0c071b12u: goto P_0c071b12;
case 0x0c071b14u: goto P_0c071b14;
case 0x0c071b16u: goto P_0c071b16;
case 0x0c071b18u: goto P_0c071b18;
case 0x0c071b1au: goto P_0c071b1a;
case 0x0c071b1cu: goto P_0c071b1c;
case 0x0c071b1eu: goto P_0c071b1e;
case 0x0c071b20u: goto P_0c071b20;
case 0x0c071b22u: goto P_0c071b22;
case 0x0c071b24u: goto P_0c071b24;
case 0x0c071b26u: goto P_0c071b26;
case 0x0c071b28u: goto P_0c071b28;
case 0x0c071b2au: goto P_0c071b2a;
case 0x0c071b2cu: goto P_0c071b2c;
case 0x0c071b2eu: goto P_0c071b2e;
case 0x0c071b30u: goto P_0c071b30;
case 0x0c071b32u: goto P_0c071b32;
case 0x0c071b34u: goto P_0c071b34;
case 0x0c071b36u: goto P_0c071b36;
case 0x0c071b38u: goto P_0c071b38;
case 0x0c071b3au: goto P_0c071b3a;
case 0x0c071b3cu: goto P_0c071b3c;
case 0x0c071b3eu: goto P_0c071b3e;
case 0x0c071b40u: goto P_0c071b40;
case 0x0c071b42u: goto P_0c071b42;
case 0x0c071b44u: goto P_0c071b44;
case 0x0c071b46u: goto P_0c071b46;
case 0x0c071b48u: goto P_0c071b48;
case 0x0c071b4au: goto P_0c071b4a;
case 0x0c071b4cu: goto P_0c071b4c;
case 0x0c071b4eu: goto P_0c071b4e;
case 0x0c071b50u: goto P_0c071b50;
case 0x0c071b52u: goto P_0c071b52;
case 0x0c071b54u: goto P_0c071b54;
case 0x0c071b56u: goto P_0c071b56;
case 0x0c071b58u: goto P_0c071b58;
case 0x0c071b5au: goto P_0c071b5a;
case 0x0c071b5cu: goto P_0c071b5c;
case 0x0c071b5eu: goto P_0c071b5e;
case 0x0c071b60u: goto P_0c071b60;
case 0x0c071b62u: goto P_0c071b62;
case 0x0c071b64u: goto P_0c071b64;
case 0x0c071b66u: goto P_0c071b66;
case 0x0c071b68u: goto P_0c071b68;
case 0x0c071b6au: goto P_0c071b6a;
case 0x0c071b6cu: goto P_0c071b6c;
case 0x0c071b6eu: goto P_0c071b6e;
case 0x0c071b70u: goto P_0c071b70;
case 0x0c071b72u: goto P_0c071b72;
case 0x0c071b74u: goto P_0c071b74;
case 0x0c071b76u: goto P_0c071b76;
case 0x0c071b78u: goto P_0c071b78;
case 0x0c071b7au: goto P_0c071b7a;
case 0x0c071b7cu: goto P_0c071b7c;
case 0x0c071b7eu: goto P_0c071b7e;
case 0x0c071b80u: goto P_0c071b80;
case 0x0c071b82u: goto P_0c071b82;
case 0x0c071b84u: goto P_0c071b84;
case 0x0c071b86u: goto P_0c071b86;
case 0x0c071b88u: goto P_0c071b88;
case 0x0c071b8au: goto P_0c071b8a;
case 0x0c071b8cu: goto P_0c071b8c;
case 0x0c071b8eu: goto P_0c071b8e;
case 0x0c071b90u: goto P_0c071b90;
case 0x0c071b92u: goto P_0c071b92;
case 0x0c071b94u: goto P_0c071b94;
case 0x0c071b96u: goto P_0c071b96;
case 0x0c071b98u: goto P_0c071b98;
case 0x0c071b9au: goto P_0c071b9a;
case 0x0c071b9cu: goto P_0c071b9c;
case 0x0c071b9eu: goto P_0c071b9e;
case 0x0c071ba0u: goto P_0c071ba0;
case 0x0c071ba2u: goto P_0c071ba2;
case 0x0c071ba4u: goto P_0c071ba4;
case 0x0c071ba6u: goto P_0c071ba6;
case 0x0c071ba8u: goto P_0c071ba8;
case 0x0c071baau: goto P_0c071baa;
case 0x0c071bacu: goto P_0c071bac;
case 0x0c071baeu: goto P_0c071bae;
case 0x0c071bb0u: goto P_0c071bb0;
case 0x0c071bb2u: goto P_0c071bb2;
case 0x0c071bb4u: goto P_0c071bb4;
case 0x0c071bb6u: goto P_0c071bb6;
case 0x0c071bb8u: goto P_0c071bb8;
case 0x0c071bbau: goto P_0c071bba;
case 0x0c071bbcu: goto P_0c071bbc;
case 0x0c071bbeu: goto P_0c071bbe;
case 0x0c071bc0u: goto P_0c071bc0;
case 0x0c071bc2u: goto P_0c071bc2;
case 0x0c071bc4u: goto P_0c071bc4;
case 0x0c071bc6u: goto P_0c071bc6;
case 0x0c071bc8u: goto P_0c071bc8;
case 0x0c071bcau: goto P_0c071bca;
case 0x0c071bccu: goto P_0c071bcc;
case 0x0c071bceu: goto P_0c071bce;
case 0x0c071bd0u: goto P_0c071bd0;
case 0x0c071bd2u: goto P_0c071bd2;
case 0x0c071bd4u: goto P_0c071bd4;
case 0x0c071bd6u: goto P_0c071bd6;
case 0x0c071bd8u: goto P_0c071bd8;
case 0x0c071bdau: goto P_0c071bda;
case 0x0c071bdcu: goto P_0c071bdc;
case 0x0c071bdeu: goto P_0c071bde;
case 0x0c071be0u: goto P_0c071be0;
case 0x0c071be2u: goto P_0c071be2;
case 0x0c071be4u: goto P_0c071be4;
case 0x0c071be6u: goto P_0c071be6;
case 0x0c071be8u: goto P_0c071be8;
case 0x0c071beau: goto P_0c071bea;
case 0x0c071becu: goto P_0c071bec;
case 0x0c071beeu: goto P_0c071bee;
case 0x0c071bf0u: goto P_0c071bf0;
case 0x0c071bf2u: goto P_0c071bf2;
case 0x0c071bf4u: goto P_0c071bf4;
case 0x0c071bf6u: goto P_0c071bf6;
case 0x0c071bf8u: goto P_0c071bf8;
case 0x0c071bfau: goto P_0c071bfa;
case 0x0c071bfcu: goto P_0c071bfc;
case 0x0c071bfeu: goto P_0c071bfe;
case 0x0c071c00u: goto P_0c071c00;
case 0x0c071c02u: goto P_0c071c02;
case 0x0c071c04u: goto P_0c071c04;
case 0x0c071c06u: goto P_0c071c06;
case 0x0c071c08u: goto P_0c071c08;
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
case 0x0c072b02u: goto P_0c072b02;
case 0x0c072b04u: goto P_0c072b04;
case 0x0c072b06u: goto P_0c072b06;
case 0x0c072b08u: goto P_0c072b08;
case 0x0c072b0au: goto P_0c072b0a;
case 0x0c072b0cu: goto P_0c072b0c;
case 0x0c072b0eu: goto P_0c072b0e;
case 0x0c072b10u: goto P_0c072b10;
case 0x0c072b12u: goto P_0c072b12;
case 0x0c072b14u: goto P_0c072b14;
case 0x0c072b16u: goto P_0c072b16;
case 0x0c072b18u: goto P_0c072b18;
case 0x0c072b1au: goto P_0c072b1a;
case 0x0c072b1cu: goto P_0c072b1c;
case 0x0c072b1eu: goto P_0c072b1e;
case 0x0c072b20u: goto P_0c072b20;
case 0x0c072b22u: goto P_0c072b22;
case 0x0c072b24u: goto P_0c072b24;
case 0x0c072b26u: goto P_0c072b26;
case 0x0c072b28u: goto P_0c072b28;
case 0x0c072b2au: goto P_0c072b2a;
case 0x0c072b2cu: goto P_0c072b2c;
case 0x0c072b2eu: goto P_0c072b2e;
case 0x0c072b30u: goto P_0c072b30;
case 0x0c072b32u: goto P_0c072b32;
case 0x0c072b34u: goto P_0c072b34;
case 0x0c072b36u: goto P_0c072b36;
case 0x0c072b38u: goto P_0c072b38;
case 0x0c072b3au: goto P_0c072b3a;
case 0x0c072b3cu: goto P_0c072b3c;
case 0x0c072b3eu: goto P_0c072b3e;
case 0x0c0aa744u: goto P_0c0aa744;
case 0x0c0aa746u: goto P_0c0aa746;
case 0x0c0aa748u: goto P_0c0aa748;
case 0x0c0aa74au: goto P_0c0aa74a;
case 0x0c0aa74cu: goto P_0c0aa74c;
case 0x0c0aa74eu: goto P_0c0aa74e;
case 0x0c0aa750u: goto P_0c0aa750;
case 0x0c0aa752u: goto P_0c0aa752;
case 0x0c0aa754u: goto P_0c0aa754;
case 0x0c0aa756u: goto P_0c0aa756;
case 0x0c0aa758u: goto P_0c0aa758;
case 0x0c0aa75au: goto P_0c0aa75a;
case 0x0c0aa75cu: goto P_0c0aa75c;
case 0x0c0aa75eu: goto P_0c0aa75e;
case 0x0c0aa760u: goto P_0c0aa760;
case 0x0c0aa762u: goto P_0c0aa762;
case 0x0c0aa764u: goto P_0c0aa764;
case 0x0c0aa766u: goto P_0c0aa766;
case 0x0c0aa768u: goto P_0c0aa768;
case 0x0c0aa76au: goto P_0c0aa76a;
case 0x0c0aa76cu: goto P_0c0aa76c;
case 0x0c0aa76eu: goto P_0c0aa76e;
case 0x0c0aa770u: goto P_0c0aa770;
case 0x0c0aa772u: goto P_0c0aa772;
case 0x0c0aa774u: goto P_0c0aa774;
case 0x0c0aa776u: goto P_0c0aa776;
case 0x0c0aa778u: goto P_0c0aa778;
case 0x0c0aa77au: goto P_0c0aa77a;
case 0x0c0aa77cu: goto P_0c0aa77c;
case 0x0c0aa77eu: goto P_0c0aa77e;
case 0x0c0aa780u: goto P_0c0aa780;
case 0x0c0aa782u: goto P_0c0aa782;
case 0x0c0aa784u: goto P_0c0aa784;
case 0x0c0aa786u: goto P_0c0aa786;
case 0x0c0aa788u: goto P_0c0aa788;
case 0x0c0aa78au: goto P_0c0aa78a;
case 0x0c0aa78cu: goto P_0c0aa78c;
case 0x0c0aa78eu: goto P_0c0aa78e;
case 0x0c0aa790u: goto P_0c0aa790;
case 0x0c0aa792u: goto P_0c0aa792;
case 0x0c0aa794u: goto P_0c0aa794;
case 0x0c0aa796u: goto P_0c0aa796;
case 0x0c0aa798u: goto P_0c0aa798;
case 0x0c0aa79au: goto P_0c0aa79a;
case 0x0c0aa79cu: goto P_0c0aa79c;
case 0x0c0aa79eu: goto P_0c0aa79e;
case 0x0c0aa7a0u: goto P_0c0aa7a0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03b530: /* original 2448, guest PC 0x0c03b530 */
if(!s->budget--) { s->failed_pc=0x0c03b530u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03b532;
P_0c03b532: /* original 2fe6, guest PC 0x0c03b532 */
if(!s->budget--) { s->failed_pc=0x0c03b532u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c03b534;
P_0c03b534: /* original 8f0c, guest PC 0x0c03b534 */
if(!s->budget--) { s->failed_pc=0x0c03b534u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(!cond) { goto P_0c03b550; }
goto P_0c03b538;
P_0c03b536: /* original 6e53, guest PC 0x0c03b536 */
if(!s->budget--) { s->failed_pc=0x0c03b536u; return 0; }
r[14]=r[5];
goto P_0c03b538;
P_0c03b538: /* original 2ee8, guest PC 0x0c03b538 */
if(!s->budget--) { s->failed_pc=0x0c03b538u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c03b53a;
P_0c03b53a: /* original 8919, guest PC 0x0c03b53a */
if(!s->budget--) { s->failed_pc=0x0c03b53au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03b570; }
goto P_0c03b53c;
P_0c03b53c: /* original d31c, guest PC 0x0c03b53c */
if(!s->budget--) { s->failed_pc=0x0c03b53cu; return 0; }
r[3]=read(ram,0x0c03b5b0u,4);
goto P_0c03b53e;
P_0c03b53e: /* original 64e3, guest PC 0x0c03b53e */
if(!s->budget--) { s->failed_pc=0x0c03b53eu; return 0; }
r[4]=r[14];
goto P_0c03b540;
P_0c03b540: /* original 432b, guest PC 0x0c03b540 */
if(!s->budget--) { s->failed_pc=0x0c03b540u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c03b542: /* original 6ef6, guest PC 0x0c03b542 */
if(!s->budget--) { s->failed_pc=0x0c03b542u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03b544u,s,ram);
P_0c03b550: /* original 2ee8, guest PC 0x0c03b550 */
if(!s->budget--) { s->failed_pc=0x0c03b550u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c03b552;
P_0c03b552: /* original 8b05, guest PC 0x0c03b552 */
if(!s->budget--) { s->failed_pc=0x0c03b552u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03b560; }
goto P_0c03b554;
P_0c03b554: /* original d314, guest PC 0x0c03b554 */
if(!s->budget--) { s->failed_pc=0x0c03b554u; return 0; }
r[3]=read(ram,0x0c03b5a8u,4);
goto P_0c03b556;
P_0c03b556: /* original 432b, guest PC 0x0c03b556 */
if(!s->budget--) { s->failed_pc=0x0c03b556u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c03b558: /* original 6ef6, guest PC 0x0c03b558 */
if(!s->budget--) { s->failed_pc=0x0c03b558u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03b55au,s,ram);
P_0c03b560: /* original 6543, guest PC 0x0c03b560 */
if(!s->budget--) { s->failed_pc=0x0c03b560u; return 0; }
r[5]=r[4];
goto P_0c03b562;
P_0c03b562: /* original e410, guest PC 0x0c03b562 */
if(!s->budget--) { s->failed_pc=0x0c03b562u; return 0; }
r[4]=0x00000010u;
goto P_0c03b564;
P_0c03b564: /* original 66e3, guest PC 0x0c03b564 */
if(!s->budget--) { s->failed_pc=0x0c03b564u; return 0; }
r[6]=r[14];
goto P_0c03b566;
P_0c03b566: /* original f369, guest PC 0x0c03b566 */
if(!s->budget--) { s->failed_pc=0x0c03b566u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c03b568;
P_0c03b568: /* original 4410, guest PC 0x0c03b568 */
if(!s->budget--) { s->failed_pc=0x0c03b568u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c03b56a;
P_0c03b56a: /* original f53a, guest PC 0x0c03b56a */
if(!s->budget--) { s->failed_pc=0x0c03b56au; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c03b56c;
P_0c03b56c: /* original 8ffb, guest PC 0x0c03b56c */
if(!s->budget--) { s->failed_pc=0x0c03b56cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c03b566; }
goto P_0c03b570;
P_0c03b56e: /* original 7504, guest PC 0x0c03b56e */
if(!s->budget--) { s->failed_pc=0x0c03b56eu; return 0; }
r[5]+=0x00000004u;
goto P_0c03b570;
P_0c03b570: /* original 000b, guest PC 0x0c03b570 */
if(!s->budget--) { s->failed_pc=0x0c03b570u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b572: /* original 6ef6, guest PC 0x0c03b572 */
if(!s->budget--) { s->failed_pc=0x0c03b572u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03b574u,s,ram);
P_0c03c4a0: /* original d30f, guest PC 0x0c03c4a0 */
if(!s->budget--) { s->failed_pc=0x0c03c4a0u; return 0; }
r[3]=read(ram,0x0c03c4e0u,4);
goto P_0c03c4a2;
P_0c03c4a2: /* original 4415, guest PC 0x0c03c4a2 */
if(!s->budget--) { s->failed_pc=0x0c03c4a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c03c4a4;
P_0c03c4a4: /* original 8900, guest PC 0x0c03c4a4 */
if(!s->budget--) { s->failed_pc=0x0c03c4a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03c4a8; }
goto P_0c03c4a6;
P_0c03c4a6: /* original e401, guest PC 0x0c03c4a6 */
if(!s->budget--) { s->failed_pc=0x0c03c4a6u; return 0; }
r[4]=0x00000001u;
goto P_0c03c4a8;
P_0c03c4a8: /* original 6635, guest PC 0x0c03c4a8 */
if(!s->budget--) { s->failed_pc=0x0c03c4a8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]+=2;
r[6]=tmp;
goto P_0c03c4aa;
P_0c03c4aa: /* original f3fd, guest PC 0x0c03c4aa */
if(!s->budget--) { s->failed_pc=0x0c03c4aau; return 0; }
r[18]^=0x100000u;
goto P_0c03c4ac;
P_0c03c4ac: /* original 6231, guest PC 0x0c03c4ac */
if(!s->budget--) { s->failed_pc=0x0c03c4acu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c03c4ae;
P_0c03c4ae: /* original 73fe, guest PC 0x0c03c4ae */
if(!s->budget--) { s->failed_pc=0x0c03c4aeu; return 0; }
r[3]+=0xfffffffeu;
goto P_0c03c4b0;
P_0c03c4b0: /* original 3643, guest PC 0x0c03c4b0 */
if(!s->budget--) { s->failed_pc=0x0c03c4b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c03c4b2;
P_0c03c4b2: /* original 3648, guest PC 0x0c03c4b2 */
if(!s->budget--) { s->failed_pc=0x0c03c4b2u; return 0; }
r[6]-=r[4];
goto P_0c03c4b4;
P_0c03c4b4: /* original 8900, guest PC 0x0c03c4b4 */
if(!s->budget--) { s->failed_pc=0x0c03c4b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03c4b8; }
goto P_0c03c4b6;
P_0c03c4b6: /* original e600, guest PC 0x0c03c4b6 */
if(!s->budget--) { s->failed_pc=0x0c03c4b6u; return 0; }
r[6]=0x00000000u;
goto P_0c03c4b8;
P_0c03c4b8: /* original 0029, guest PC 0x0c03c4b8 */
if(!s->budget--) { s->failed_pc=0x0c03c4b8u; return 0; }
r[0]=r[17]&1u;
goto P_0c03c4ba;
P_0c03c4ba: /* original 5731, guest PC 0x0c03c4ba */
if(!s->budget--) { s->failed_pc=0x0c03c4bau; return 0; }
r[7]=read(ram,r[3]+4,4);
goto P_0c03c4bc;
P_0c03c4bc: /* original 6463, guest PC 0x0c03c4bc */
if(!s->budget--) { s->failed_pc=0x0c03c4bcu; return 0; }
r[4]=r[6];
goto P_0c03c4be;
P_0c03c4be: /* original 4418, guest PC 0x0c03c4be */
if(!s->budget--) { s->failed_pc=0x0c03c4beu; return 0; }
r[4]<<=8;
goto P_0c03c4c0;
P_0c03c4c0: /* original 3623, guest PC 0x0c03c4c0 */
if(!s->budget--) { s->failed_pc=0x0c03c4c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[2])!=0);
goto P_0c03c4c2;
P_0c03c4c2: /* original 4409, guest PC 0x0c03c4c2 */
if(!s->budget--) { s->failed_pc=0x0c03c4c2u; return 0; }
r[4]>>=2;
goto P_0c03c4c4;
P_0c03c4c4: /* original 2361, guest PC 0x0c03c4c4 */
if(!s->budget--) { s->failed_pc=0x0c03c4c4u; return 0; }
write(ram,r[3],r[6],2);
goto P_0c03c4c6;
P_0c03c4c6: /* original 374c, guest PC 0x0c03c4c6 */
if(!s->budget--) { s->failed_pc=0x0c03c4c6u; return 0; }
r[7]+=r[4];
goto P_0c03c4c8;
P_0c03c4c8: /* original 8900, guest PC 0x0c03c4c8 */
if(!s->budget--) { s->failed_pc=0x0c03c4c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03c4cc; }
goto P_0c03c4ca;
P_0c03c4ca: /* original 1372, guest PC 0x0c03c4ca */
if(!s->budget--) { s->failed_pc=0x0c03c4cau; return 0; }
write(ram,r[3]+8,r[7],4);
goto P_0c03c4cc;
P_0c03c4cc: /* original f179, guest PC 0x0c03c4cc */
if(!s->budget--) { s->failed_pc=0x0c03c4ccu; return 0; }
vf3_matrix_load(s,ram,1,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03c4ce;
P_0c03c4ce: /* original f379, guest PC 0x0c03c4ce */
if(!s->budget--) { s->failed_pc=0x0c03c4ceu; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03c4d0;
P_0c03c4d0: /* original f579, guest PC 0x0c03c4d0 */
if(!s->budget--) { s->failed_pc=0x0c03c4d0u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03c4d2;
P_0c03c4d2: /* original f779, guest PC 0x0c03c4d2 */
if(!s->budget--) { s->failed_pc=0x0c03c4d2u; return 0; }
vf3_matrix_load(s,ram,7,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03c4d4;
P_0c03c4d4: /* original f979, guest PC 0x0c03c4d4 */
if(!s->budget--) { s->failed_pc=0x0c03c4d4u; return 0; }
vf3_matrix_load(s,ram,9,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03c4d6;
P_0c03c4d6: /* original fb79, guest PC 0x0c03c4d6 */
if(!s->budget--) { s->failed_pc=0x0c03c4d6u; return 0; }
vf3_matrix_load(s,ram,11,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03c4d8;
P_0c03c4d8: /* original fd79, guest PC 0x0c03c4d8 */
if(!s->budget--) { s->failed_pc=0x0c03c4d8u; return 0; }
vf3_matrix_load(s,ram,13,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03c4da;
P_0c03c4da: /* original ff79, guest PC 0x0c03c4da */
if(!s->budget--) { s->failed_pc=0x0c03c4dau; return 0; }
vf3_matrix_load(s,ram,15,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03c4dc;
P_0c03c4dc: /* original 000b, guest PC 0x0c03c4dc */
if(!s->budget--) { s->failed_pc=0x0c03c4dcu; return 0; }
target=r[16];
r[18]^=0x100000u;
s->pc=target; return ram->oob==0;
P_0c03c4de: /* original f3fd, guest PC 0x0c03c4de */
if(!s->budget--) { s->failed_pc=0x0c03c4deu; return 0; }
r[18]^=0x100000u;
return vf3_matrix_family(0x0c03c4e0u,s,ram);
P_0c042d7c: /* original 2008, guest PC 0x0c042d7c */
if(!s->budget--) { s->failed_pc=0x0c042d7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042d7e;
P_0c042d7e: /* original 2f26, guest PC 0x0c042d7e */
if(!s->budget--) { s->failed_pc=0x0c042d7eu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c042d80;
P_0c042d80: /* original 8d56, guest PC 0x0c042d80 */
if(!s->budget--) { s->failed_pc=0x0c042d80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042e30; }
goto P_0c042d84;
P_0c042d82: /* original 0009, guest PC 0x0c042d82 */
if(!s->budget--) { s->failed_pc=0x0c042d82u; return 0; }
goto P_0c042d84;
P_0c042d84: /* original 2f36, guest PC 0x0c042d84 */
if(!s->budget--) { s->failed_pc=0x0c042d84u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c042d86;
P_0c042d86: /* original e200, guest PC 0x0c042d86 */
if(!s->budget--) { s->failed_pc=0x0c042d86u; return 0; }
r[2]=0x00000000u;
goto P_0c042d88;
P_0c042d88: /* original 2f46, guest PC 0x0c042d88 */
if(!s->budget--) { s->failed_pc=0x0c042d88u; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c042d8a;
P_0c042d8a: /* original 2127, guest PC 0x0c042d8a */
if(!s->budget--) { s->failed_pc=0x0c042d8au; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042d8c;
P_0c042d8c: /* original 0429, guest PC 0x0c042d8c */
if(!s->budget--) { s->failed_pc=0x0c042d8cu; return 0; }
r[4]=r[17]&1u;
goto P_0c042d8e;
P_0c042d8e: /* original 333a, guest PC 0x0c042d8e */
if(!s->budget--) { s->failed_pc=0x0c042d8eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d90;
P_0c042d90: /* original 312a, guest PC 0x0c042d90 */
if(!s->budget--) { s->failed_pc=0x0c042d90u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d92;
P_0c042d92: /* original 2307, guest PC 0x0c042d92 */
if(!s->budget--) { s->failed_pc=0x0c042d92u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042d94;
P_0c042d94: /* original 4124, guest PC 0x0c042d94 */
if(!s->budget--) { s->failed_pc=0x0c042d94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d96;
P_0c042d96: /* original 3304, guest PC 0x0c042d96 */
if(!s->budget--) { s->failed_pc=0x0c042d96u; return 0; }
divide_step(s,3,0);
goto P_0c042d98;
P_0c042d98: /* original 4124, guest PC 0x0c042d98 */
if(!s->budget--) { s->failed_pc=0x0c042d98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9a;
P_0c042d9a: /* original 3304, guest PC 0x0c042d9a */
if(!s->budget--) { s->failed_pc=0x0c042d9au; return 0; }
divide_step(s,3,0);
goto P_0c042d9c;
P_0c042d9c: /* original 4124, guest PC 0x0c042d9c */
if(!s->budget--) { s->failed_pc=0x0c042d9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9e;
P_0c042d9e: /* original 3304, guest PC 0x0c042d9e */
if(!s->budget--) { s->failed_pc=0x0c042d9eu; return 0; }
divide_step(s,3,0);
goto P_0c042da0;
P_0c042da0: /* original 4124, guest PC 0x0c042da0 */
if(!s->budget--) { s->failed_pc=0x0c042da0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da2;
P_0c042da2: /* original 3304, guest PC 0x0c042da2 */
if(!s->budget--) { s->failed_pc=0x0c042da2u; return 0; }
divide_step(s,3,0);
goto P_0c042da4;
P_0c042da4: /* original 4124, guest PC 0x0c042da4 */
if(!s->budget--) { s->failed_pc=0x0c042da4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da6;
P_0c042da6: /* original 3304, guest PC 0x0c042da6 */
if(!s->budget--) { s->failed_pc=0x0c042da6u; return 0; }
divide_step(s,3,0);
goto P_0c042da8;
P_0c042da8: /* original 4124, guest PC 0x0c042da8 */
if(!s->budget--) { s->failed_pc=0x0c042da8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042daa;
P_0c042daa: /* original 3304, guest PC 0x0c042daa */
if(!s->budget--) { s->failed_pc=0x0c042daau; return 0; }
divide_step(s,3,0);
goto P_0c042dac;
P_0c042dac: /* original 4124, guest PC 0x0c042dac */
if(!s->budget--) { s->failed_pc=0x0c042dacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dae;
P_0c042dae: /* original 3304, guest PC 0x0c042dae */
if(!s->budget--) { s->failed_pc=0x0c042daeu; return 0; }
divide_step(s,3,0);
goto P_0c042db0;
P_0c042db0: /* original 4124, guest PC 0x0c042db0 */
if(!s->budget--) { s->failed_pc=0x0c042db0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db2;
P_0c042db2: /* original 3304, guest PC 0x0c042db2 */
if(!s->budget--) { s->failed_pc=0x0c042db2u; return 0; }
divide_step(s,3,0);
goto P_0c042db4;
P_0c042db4: /* original 4124, guest PC 0x0c042db4 */
if(!s->budget--) { s->failed_pc=0x0c042db4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db6;
P_0c042db6: /* original 3304, guest PC 0x0c042db6 */
if(!s->budget--) { s->failed_pc=0x0c042db6u; return 0; }
divide_step(s,3,0);
goto P_0c042db8;
P_0c042db8: /* original 4124, guest PC 0x0c042db8 */
if(!s->budget--) { s->failed_pc=0x0c042db8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dba;
P_0c042dba: /* original 3304, guest PC 0x0c042dba */
if(!s->budget--) { s->failed_pc=0x0c042dbau; return 0; }
divide_step(s,3,0);
goto P_0c042dbc;
P_0c042dbc: /* original 4124, guest PC 0x0c042dbc */
if(!s->budget--) { s->failed_pc=0x0c042dbcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dbe;
P_0c042dbe: /* original 3304, guest PC 0x0c042dbe */
if(!s->budget--) { s->failed_pc=0x0c042dbeu; return 0; }
divide_step(s,3,0);
goto P_0c042dc0;
P_0c042dc0: /* original 4124, guest PC 0x0c042dc0 */
if(!s->budget--) { s->failed_pc=0x0c042dc0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc2;
P_0c042dc2: /* original 3304, guest PC 0x0c042dc2 */
if(!s->budget--) { s->failed_pc=0x0c042dc2u; return 0; }
divide_step(s,3,0);
goto P_0c042dc4;
P_0c042dc4: /* original 4124, guest PC 0x0c042dc4 */
if(!s->budget--) { s->failed_pc=0x0c042dc4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc6;
P_0c042dc6: /* original 3304, guest PC 0x0c042dc6 */
if(!s->budget--) { s->failed_pc=0x0c042dc6u; return 0; }
divide_step(s,3,0);
goto P_0c042dc8;
P_0c042dc8: /* original 4124, guest PC 0x0c042dc8 */
if(!s->budget--) { s->failed_pc=0x0c042dc8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dca;
P_0c042dca: /* original 3304, guest PC 0x0c042dca */
if(!s->budget--) { s->failed_pc=0x0c042dcau; return 0; }
divide_step(s,3,0);
goto P_0c042dcc;
P_0c042dcc: /* original 4124, guest PC 0x0c042dcc */
if(!s->budget--) { s->failed_pc=0x0c042dccu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dce;
P_0c042dce: /* original 3304, guest PC 0x0c042dce */
if(!s->budget--) { s->failed_pc=0x0c042dceu; return 0; }
divide_step(s,3,0);
goto P_0c042dd0;
P_0c042dd0: /* original 4124, guest PC 0x0c042dd0 */
if(!s->budget--) { s->failed_pc=0x0c042dd0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd2;
P_0c042dd2: /* original 3304, guest PC 0x0c042dd2 */
if(!s->budget--) { s->failed_pc=0x0c042dd2u; return 0; }
divide_step(s,3,0);
goto P_0c042dd4;
P_0c042dd4: /* original 4124, guest PC 0x0c042dd4 */
if(!s->budget--) { s->failed_pc=0x0c042dd4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd6;
P_0c042dd6: /* original 3304, guest PC 0x0c042dd6 */
if(!s->budget--) { s->failed_pc=0x0c042dd6u; return 0; }
divide_step(s,3,0);
goto P_0c042dd8;
P_0c042dd8: /* original 4124, guest PC 0x0c042dd8 */
if(!s->budget--) { s->failed_pc=0x0c042dd8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dda;
P_0c042dda: /* original 3304, guest PC 0x0c042dda */
if(!s->budget--) { s->failed_pc=0x0c042ddau; return 0; }
divide_step(s,3,0);
goto P_0c042ddc;
P_0c042ddc: /* original 4124, guest PC 0x0c042ddc */
if(!s->budget--) { s->failed_pc=0x0c042ddcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dde;
P_0c042dde: /* original 3304, guest PC 0x0c042dde */
if(!s->budget--) { s->failed_pc=0x0c042ddeu; return 0; }
divide_step(s,3,0);
goto P_0c042de0;
P_0c042de0: /* original 4124, guest PC 0x0c042de0 */
if(!s->budget--) { s->failed_pc=0x0c042de0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de2;
P_0c042de2: /* original 3304, guest PC 0x0c042de2 */
if(!s->budget--) { s->failed_pc=0x0c042de2u; return 0; }
divide_step(s,3,0);
goto P_0c042de4;
P_0c042de4: /* original 4124, guest PC 0x0c042de4 */
if(!s->budget--) { s->failed_pc=0x0c042de4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de6;
P_0c042de6: /* original 3304, guest PC 0x0c042de6 */
if(!s->budget--) { s->failed_pc=0x0c042de6u; return 0; }
divide_step(s,3,0);
goto P_0c042de8;
P_0c042de8: /* original 4124, guest PC 0x0c042de8 */
if(!s->budget--) { s->failed_pc=0x0c042de8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dea;
P_0c042dea: /* original 3304, guest PC 0x0c042dea */
if(!s->budget--) { s->failed_pc=0x0c042deau; return 0; }
divide_step(s,3,0);
goto P_0c042dec;
P_0c042dec: /* original 4124, guest PC 0x0c042dec */
if(!s->budget--) { s->failed_pc=0x0c042decu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dee;
P_0c042dee: /* original 3304, guest PC 0x0c042dee */
if(!s->budget--) { s->failed_pc=0x0c042deeu; return 0; }
divide_step(s,3,0);
goto P_0c042df0;
P_0c042df0: /* original 4124, guest PC 0x0c042df0 */
if(!s->budget--) { s->failed_pc=0x0c042df0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df2;
P_0c042df2: /* original 3304, guest PC 0x0c042df2 */
if(!s->budget--) { s->failed_pc=0x0c042df2u; return 0; }
divide_step(s,3,0);
goto P_0c042df4;
P_0c042df4: /* original 4124, guest PC 0x0c042df4 */
if(!s->budget--) { s->failed_pc=0x0c042df4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df6;
P_0c042df6: /* original 3304, guest PC 0x0c042df6 */
if(!s->budget--) { s->failed_pc=0x0c042df6u; return 0; }
divide_step(s,3,0);
goto P_0c042df8;
P_0c042df8: /* original 4124, guest PC 0x0c042df8 */
if(!s->budget--) { s->failed_pc=0x0c042df8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfa;
P_0c042dfa: /* original 3304, guest PC 0x0c042dfa */
if(!s->budget--) { s->failed_pc=0x0c042dfau; return 0; }
divide_step(s,3,0);
goto P_0c042dfc;
P_0c042dfc: /* original 4124, guest PC 0x0c042dfc */
if(!s->budget--) { s->failed_pc=0x0c042dfcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfe;
P_0c042dfe: /* original 3304, guest PC 0x0c042dfe */
if(!s->budget--) { s->failed_pc=0x0c042dfeu; return 0; }
divide_step(s,3,0);
goto P_0c042e00;
P_0c042e00: /* original 4124, guest PC 0x0c042e00 */
if(!s->budget--) { s->failed_pc=0x0c042e00u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e02;
P_0c042e02: /* original 3304, guest PC 0x0c042e02 */
if(!s->budget--) { s->failed_pc=0x0c042e02u; return 0; }
divide_step(s,3,0);
goto P_0c042e04;
P_0c042e04: /* original 4124, guest PC 0x0c042e04 */
if(!s->budget--) { s->failed_pc=0x0c042e04u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e06;
P_0c042e06: /* original 3304, guest PC 0x0c042e06 */
if(!s->budget--) { s->failed_pc=0x0c042e06u; return 0; }
divide_step(s,3,0);
goto P_0c042e08;
P_0c042e08: /* original 4124, guest PC 0x0c042e08 */
if(!s->budget--) { s->failed_pc=0x0c042e08u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0a;
P_0c042e0a: /* original 3304, guest PC 0x0c042e0a */
if(!s->budget--) { s->failed_pc=0x0c042e0au; return 0; }
divide_step(s,3,0);
goto P_0c042e0c;
P_0c042e0c: /* original 4124, guest PC 0x0c042e0c */
if(!s->budget--) { s->failed_pc=0x0c042e0cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0e;
P_0c042e0e: /* original 3304, guest PC 0x0c042e0e */
if(!s->budget--) { s->failed_pc=0x0c042e0eu; return 0; }
divide_step(s,3,0);
goto P_0c042e10;
P_0c042e10: /* original 4124, guest PC 0x0c042e10 */
if(!s->budget--) { s->failed_pc=0x0c042e10u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e12;
P_0c042e12: /* original 3304, guest PC 0x0c042e12 */
if(!s->budget--) { s->failed_pc=0x0c042e12u; return 0; }
divide_step(s,3,0);
goto P_0c042e14;
P_0c042e14: /* original 2327, guest PC 0x0c042e14 */
if(!s->budget--) { s->failed_pc=0x0c042e14u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[2]>>31)<<9)|(((r[3]^r[2])>>31)&1u);
goto P_0c042e16;
P_0c042e16: /* original 0229, guest PC 0x0c042e16 */
if(!s->budget--) { s->failed_pc=0x0c042e16u; return 0; }
r[2]=r[17]&1u;
goto P_0c042e18;
P_0c042e18: /* original 224a, guest PC 0x0c042e18 */
if(!s->budget--) { s->failed_pc=0x0c042e18u; return 0; }
r[2]^=r[4];
goto P_0c042e1a;
P_0c042e1a: /* original 4225, guest PC 0x0c042e1a */
if(!s->budget--) { s->failed_pc=0x0c042e1au; return 0; }
tmp=r[2]&1u; r[2]=(r[2]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e1c;
P_0c042e1c: /* original 8b02, guest PC 0x0c042e1c */
if(!s->budget--) { s->failed_pc=0x0c042e1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042e24; }
goto P_0c042e1e;
P_0c042e1e: /* original 2307, guest PC 0x0c042e1e */
if(!s->budget--) { s->failed_pc=0x0c042e1eu; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042e20;
P_0c042e20: /* original 4321, guest PC 0x0c042e20 */
if(!s->budget--) { s->failed_pc=0x0c042e20u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c042e22;
P_0c042e22: /* original 3304, guest PC 0x0c042e22 */
if(!s->budget--) { s->failed_pc=0x0c042e22u; return 0; }
divide_step(s,3,0);
goto P_0c042e24;
P_0c042e24: /* original 334c, guest PC 0x0c042e24 */
if(!s->budget--) { s->failed_pc=0x0c042e24u; return 0; }
r[3]+=r[4];
goto P_0c042e26;
P_0c042e26: /* original 6033, guest PC 0x0c042e26 */
if(!s->budget--) { s->failed_pc=0x0c042e26u; return 0; }
r[0]=r[3];
goto P_0c042e28;
P_0c042e28: /* original 64f6, guest PC 0x0c042e28 */
if(!s->budget--) { s->failed_pc=0x0c042e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042e2a;
P_0c042e2a: /* original 63f6, guest PC 0x0c042e2a */
if(!s->budget--) { s->failed_pc=0x0c042e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042e2c;
P_0c042e2c: /* original 000b, guest PC 0x0c042e2c */
if(!s->budget--) { s->failed_pc=0x0c042e2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e2e: /* original 62f6, guest PC 0x0c042e2e */
if(!s->budget--) { s->failed_pc=0x0c042e2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042e30;
P_0c042e30: /* original d102, guest PC 0x0c042e30 */
if(!s->budget--) { s->failed_pc=0x0c042e30u; return 0; }
r[1]=read(ram,0x0c042e3cu,4);
goto P_0c042e32;
P_0c042e32: /* original d203, guest PC 0x0c042e32 */
if(!s->budget--) { s->failed_pc=0x0c042e32u; return 0; }
r[2]=read(ram,0x0c042e40u,4);
goto P_0c042e34;
P_0c042e34: /* original e000, guest PC 0x0c042e34 */
if(!s->budget--) { s->failed_pc=0x0c042e34u; return 0; }
r[0]=0x00000000u;
goto P_0c042e36;
P_0c042e36: /* original 2122, guest PC 0x0c042e36 */
if(!s->budget--) { s->failed_pc=0x0c042e36u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042e38;
P_0c042e38: /* original 000b, guest PC 0x0c042e38 */
if(!s->budget--) { s->failed_pc=0x0c042e38u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e3a: /* original 62f6, guest PC 0x0c042e3a */
if(!s->budget--) { s->failed_pc=0x0c042e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
return vf3_matrix_family(0x0c042e3cu,s,ram);
P_0c068d54: /* original 6043, guest PC 0x0c068d54 */
if(!s->budget--) { s->failed_pc=0x0c068d54u; return 0; }
r[0]=r[4];
goto P_0c068d56;
P_0c068d56: /* original 8802, guest PC 0x0c068d56 */
if(!s->budget--) { s->failed_pc=0x0c068d56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c068d58;
P_0c068d58: /* original 8902, guest PC 0x0c068d58 */
if(!s->budget--) { s->failed_pc=0x0c068d58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068d60; }
goto P_0c068d5a;
P_0c068d5a: /* original 6043, guest PC 0x0c068d5a */
if(!s->budget--) { s->failed_pc=0x0c068d5au; return 0; }
r[0]=r[4];
goto P_0c068d5c;
P_0c068d5c: /* original 8807, guest PC 0x0c068d5c */
if(!s->budget--) { s->failed_pc=0x0c068d5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c068d5e;
P_0c068d5e: /* original 8b08, guest PC 0x0c068d5e */
if(!s->budget--) { s->failed_pc=0x0c068d5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068d72; }
goto P_0c068d60;
P_0c068d60: /* original c73b, guest PC 0x0c068d60 */
if(!s->budget--) { s->failed_pc=0x0c068d60u; return 0; }
r[0]=0x0c068e50u;
goto P_0c068d62;
P_0c068d62: /* original f358, guest PC 0x0c068d62 */
if(!s->budget--) { s->failed_pc=0x0c068d62u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c068d64;
P_0c068d64: /* original f408, guest PC 0x0c068d64 */
if(!s->budget--) { s->failed_pc=0x0c068d64u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068d66;
P_0c068d66: /* original f342, guest PC 0x0c068d66 */
if(!s->budget--) { s->failed_pc=0x0c068d66u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c068d68;
P_0c068d68: /* original f53a, guest PC 0x0c068d68 */
if(!s->budget--) { s->failed_pc=0x0c068d68u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c068d6a;
P_0c068d6a: /* original f268, guest PC 0x0c068d6a */
if(!s->budget--) { s->failed_pc=0x0c068d6au; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c068d6c;
P_0c068d6c: /* original f242, guest PC 0x0c068d6c */
if(!s->budget--) { s->failed_pc=0x0c068d6cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c068d6e;
P_0c068d6e: /* original 000b, guest PC 0x0c068d6e */
if(!s->budget--) { s->failed_pc=0x0c068d6eu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[6]);
s->pc=target; return ram->oob==0;
P_0c068d70: /* original f62a, guest PC 0x0c068d70 */
if(!s->budget--) { s->failed_pc=0x0c068d70u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c068d72;
P_0c068d72: /* original 880d, guest PC 0x0c068d72 */
if(!s->budget--) { s->failed_pc=0x0c068d72u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c068d74;
P_0c068d74: /* original 8b34, guest PC 0x0c068d74 */
if(!s->budget--) { s->failed_pc=0x0c068d74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068de0; }
goto P_0c068d76;
P_0c068d76: /* original c737, guest PC 0x0c068d76 */
if(!s->budget--) { s->failed_pc=0x0c068d76u; return 0; }
r[0]=0x0c068e54u;
goto P_0c068d78;
P_0c068d78: /* original f458, guest PC 0x0c068d78 */
if(!s->budget--) { s->failed_pc=0x0c068d78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c068d7a;
P_0c068d7a: /* original f508, guest PC 0x0c068d7a */
if(!s->budget--) { s->failed_pc=0x0c068d7au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c068d7c;
P_0c068d7c: /* original f452, guest PC 0x0c068d7c */
if(!s->budget--) { s->failed_pc=0x0c068d7cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c068d7e;
P_0c068d7e: /* original f35c, guest PC 0x0c068d7e */
if(!s->budget--) { s->failed_pc=0x0c068d7eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068d80;
P_0c068d80: /* original f568, guest PC 0x0c068d80 */
if(!s->budget--) { s->failed_pc=0x0c068d80u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c068d82;
P_0c068d82: /* original f532, guest PC 0x0c068d82 */
if(!s->budget--) { s->failed_pc=0x0c068d82u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c068d84;
P_0c068d84: /* original f43d, guest PC 0x0c068d84 */
if(!s->budget--) { s->failed_pc=0x0c068d84u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c068d86;
P_0c068d86: /* original 045a, guest PC 0x0c068d86 */
if(!s->budget--) { s->failed_pc=0x0c068d86u; return 0; }
r[4]=r[53];
goto P_0c068d88;
P_0c068d88: /* original f53d, guest PC 0x0c068d88 */
if(!s->budget--) { s->failed_pc=0x0c068d88u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c068d8a;
P_0c068d8a: /* original 2448, guest PC 0x0c068d8a */
if(!s->budget--) { s->failed_pc=0x0c068d8au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c068d8c;
P_0c068d8c: /* original 8d13, guest PC 0x0c068d8c */
if(!s->budget--) { s->failed_pc=0x0c068d8cu; return 0; }
cond=r[17]&1u;
r[7]=r[53];
if(cond) { goto P_0c068db6; }
goto P_0c068d90;
P_0c068d8e: /* original 075a, guest PC 0x0c068d8e */
if(!s->budget--) { s->failed_pc=0x0c068d8eu; return 0; }
r[7]=r[53];
goto P_0c068d90;
P_0c068d90: /* original e201, guest PC 0x0c068d90 */
if(!s->budget--) { s->failed_pc=0x0c068d90u; return 0; }
r[2]=0x00000001u;
goto P_0c068d92;
P_0c068d92: /* original 2248, guest PC 0x0c068d92 */
if(!s->budget--) { s->failed_pc=0x0c068d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c068d94;
P_0c068d94: /* original 8905, guest PC 0x0c068d94 */
if(!s->budget--) { s->failed_pc=0x0c068d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068da2; }
goto P_0c068d96;
P_0c068d96: /* original d130, guest PC 0x0c068d96 */
if(!s->budget--) { s->failed_pc=0x0c068d96u; return 0; }
r[1]=read(ram,0x0c068e58u,4);
goto P_0c068d98;
P_0c068d98: /* original 2148, guest PC 0x0c068d98 */
if(!s->budget--) { s->failed_pc=0x0c068d98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c068d9a;
P_0c068d9a: /* original 8901, guest PC 0x0c068d9a */
if(!s->budget--) { s->failed_pc=0x0c068d9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068da0; }
goto P_0c068d9c;
P_0c068d9c: /* original a001, guest PC 0x0c068d9c */
if(!s->budget--) { s->failed_pc=0x0c068d9cu; return 0; }
r[4]+=0xffffffffu;
goto P_0c068da2;
P_0c068d9e: /* original 74ff, guest PC 0x0c068d9e */
if(!s->budget--) { s->failed_pc=0x0c068d9eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c068da0;
P_0c068da0: /* original 7401, guest PC 0x0c068da0 */
if(!s->budget--) { s->failed_pc=0x0c068da0u; return 0; }
r[4]+=0x00000001u;
goto P_0c068da2;
P_0c068da2: /* original 6343, guest PC 0x0c068da2 */
if(!s->budget--) { s->failed_pc=0x0c068da2u; return 0; }
r[3]=r[4];
goto P_0c068da4;
P_0c068da4: /* original 4408, guest PC 0x0c068da4 */
if(!s->budget--) { s->failed_pc=0x0c068da4u; return 0; }
r[4]<<=2;
goto P_0c068da6;
P_0c068da6: /* original 343c, guest PC 0x0c068da6 */
if(!s->budget--) { s->failed_pc=0x0c068da6u; return 0; }
r[4]+=r[3];
goto P_0c068da8;
P_0c068da8: /* original f258, guest PC 0x0c068da8 */
if(!s->budget--) { s->failed_pc=0x0c068da8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c068daa;
P_0c068daa: /* original 4400, guest PC 0x0c068daa */
if(!s->budget--) { s->failed_pc=0x0c068daau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c068dac;
P_0c068dac: /* original 445a, guest PC 0x0c068dac */
if(!s->budget--) { s->failed_pc=0x0c068dacu; return 0; }
r[53]=r[4];
goto P_0c068dae;
P_0c068dae: /* original f32d, guest PC 0x0c068dae */
if(!s->budget--) { s->failed_pc=0x0c068daeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068db0;
P_0c068db0: /* original f43c, guest PC 0x0c068db0 */
if(!s->budget--) { s->failed_pc=0x0c068db0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c068db2;
P_0c068db2: /* original f241, guest PC 0x0c068db2 */
if(!s->budget--) { s->failed_pc=0x0c068db2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c068db4;
P_0c068db4: /* original f52a, guest PC 0x0c068db4 */
if(!s->budget--) { s->failed_pc=0x0c068db4u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c068db6;
P_0c068db6: /* original 2778, guest PC 0x0c068db6 */
if(!s->budget--) { s->failed_pc=0x0c068db6u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c068db8;
P_0c068db8: /* original 8912, guest PC 0x0c068db8 */
if(!s->budget--) { s->failed_pc=0x0c068db8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068de0; }
goto P_0c068dba;
P_0c068dba: /* original e201, guest PC 0x0c068dba */
if(!s->budget--) { s->failed_pc=0x0c068dbau; return 0; }
r[2]=0x00000001u;
goto P_0c068dbc;
P_0c068dbc: /* original 2278, guest PC 0x0c068dbc */
if(!s->budget--) { s->failed_pc=0x0c068dbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c068dbe;
P_0c068dbe: /* original 8905, guest PC 0x0c068dbe */
if(!s->budget--) { s->failed_pc=0x0c068dbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068dcc; }
goto P_0c068dc0;
P_0c068dc0: /* original d125, guest PC 0x0c068dc0 */
if(!s->budget--) { s->failed_pc=0x0c068dc0u; return 0; }
r[1]=read(ram,0x0c068e58u,4);
goto P_0c068dc2;
P_0c068dc2: /* original 2178, guest PC 0x0c068dc2 */
if(!s->budget--) { s->failed_pc=0x0c068dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[7])==0)!=0);
goto P_0c068dc4;
P_0c068dc4: /* original 8901, guest PC 0x0c068dc4 */
if(!s->budget--) { s->failed_pc=0x0c068dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068dca; }
goto P_0c068dc6;
P_0c068dc6: /* original a001, guest PC 0x0c068dc6 */
if(!s->budget--) { s->failed_pc=0x0c068dc6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c068dcc;
P_0c068dc8: /* original 77ff, guest PC 0x0c068dc8 */
if(!s->budget--) { s->failed_pc=0x0c068dc8u; return 0; }
r[7]+=0xffffffffu;
goto P_0c068dca;
P_0c068dca: /* original 7701, guest PC 0x0c068dca */
if(!s->budget--) { s->failed_pc=0x0c068dcau; return 0; }
r[7]+=0x00000001u;
goto P_0c068dcc;
P_0c068dcc: /* original 6373, guest PC 0x0c068dcc */
if(!s->budget--) { s->failed_pc=0x0c068dccu; return 0; }
r[3]=r[7];
goto P_0c068dce;
P_0c068dce: /* original 4708, guest PC 0x0c068dce */
if(!s->budget--) { s->failed_pc=0x0c068dceu; return 0; }
r[7]<<=2;
goto P_0c068dd0;
P_0c068dd0: /* original 373c, guest PC 0x0c068dd0 */
if(!s->budget--) { s->failed_pc=0x0c068dd0u; return 0; }
r[7]+=r[3];
goto P_0c068dd2;
P_0c068dd2: /* original f268, guest PC 0x0c068dd2 */
if(!s->budget--) { s->failed_pc=0x0c068dd2u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c068dd4;
P_0c068dd4: /* original 4700, guest PC 0x0c068dd4 */
if(!s->budget--) { s->failed_pc=0x0c068dd4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c068dd6;
P_0c068dd6: /* original 475a, guest PC 0x0c068dd6 */
if(!s->budget--) { s->failed_pc=0x0c068dd6u; return 0; }
r[53]=r[7];
goto P_0c068dd8;
P_0c068dd8: /* original f32d, guest PC 0x0c068dd8 */
if(!s->budget--) { s->failed_pc=0x0c068dd8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068dda;
P_0c068dda: /* original f43c, guest PC 0x0c068dda */
if(!s->budget--) { s->failed_pc=0x0c068ddau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c068ddc;
P_0c068ddc: /* original f241, guest PC 0x0c068ddc */
if(!s->budget--) { s->failed_pc=0x0c068ddcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c068dde;
P_0c068dde: /* original f62a, guest PC 0x0c068dde */
if(!s->budget--) { s->failed_pc=0x0c068ddeu; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c068de0;
P_0c068de0: /* original 000b, guest PC 0x0c068de0 */
if(!s->budget--) { s->failed_pc=0x0c068de0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068de2: /* original 0009, guest PC 0x0c068de2 */
if(!s->budget--) { s->failed_pc=0x0c068de2u; return 0; }
goto P_0c068de4;
P_0c068de4: /* original c71d, guest PC 0x0c068de4 */
if(!s->budget--) { s->failed_pc=0x0c068de4u; return 0; }
r[0]=0x0c068e5cu;
goto P_0c068de6;
P_0c068de6: /* original f45d, guest PC 0x0c068de6 */
if(!s->budget--) { s->failed_pc=0x0c068de6u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c068de8;
P_0c068de8: /* original f608, guest PC 0x0c068de8 */
if(!s->budget--) { s->failed_pc=0x0c068de8u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c068dea;
P_0c068dea: /* original f55d, guest PC 0x0c068dea */
if(!s->budget--) { s->failed_pc=0x0c068deau; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c068dec;
P_0c068dec: /* original f465, guest PC 0x0c068dec */
if(!s->budget--) { s->failed_pc=0x0c068decu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c068dee;
P_0c068dee: /* original 8d02, guest PC 0x0c068dee */
if(!s->budget--) { s->failed_pc=0x0c068deeu; return 0; }
cond=r[17]&1u;
fr[7]=0;
if(cond) { goto P_0c068df6; }
goto P_0c068df2;
P_0c068df0: /* original f78d, guest PC 0x0c068df0 */
if(!s->budget--) { s->failed_pc=0x0c068df0u; return 0; }
fr[7]=0;
goto P_0c068df2;
P_0c068df2: /* original f565, guest PC 0x0c068df2 */
if(!s->budget--) { s->failed_pc=0x0c068df2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c068df4;
P_0c068df4: /* original 8b02, guest PC 0x0c068df4 */
if(!s->budget--) { s->failed_pc=0x0c068df4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068dfc; }
goto P_0c068df6;
P_0c068df6: /* original c71a, guest PC 0x0c068df6 */
if(!s->budget--) { s->failed_pc=0x0c068df6u; return 0; }
r[0]=0x0c068e60u;
goto P_0c068df8;
P_0c068df8: /* original a001, guest PC 0x0c068df8 */
if(!s->budget--) { s->failed_pc=0x0c068df8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068dfe;
P_0c068dfa: /* original f408, guest PC 0x0c068dfa */
if(!s->budget--) { s->failed_pc=0x0c068dfau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068dfc;
P_0c068dfc: /* original f47c, guest PC 0x0c068dfc */
if(!s->budget--) { s->failed_pc=0x0c068dfcu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c068dfe;
P_0c068dfe: /* original e008, guest PC 0x0c068dfe */
if(!s->budget--) { s->failed_pc=0x0c068dfeu; return 0; }
r[0]=0x00000008u;
goto P_0c068e00;
P_0c068e00: /* original f477, guest PC 0x0c068e00 */
if(!s->budget--) { s->failed_pc=0x0c068e00u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c068e02;
P_0c068e02: /* original e004, guest PC 0x0c068e02 */
if(!s->budget--) { s->failed_pc=0x0c068e02u; return 0; }
r[0]=0x00000004u;
goto P_0c068e04;
P_0c068e04: /* original f47a, guest PC 0x0c068e04 */
if(!s->budget--) { s->failed_pc=0x0c068e04u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c068e06;
P_0c068e06: /* original f39d, guest PC 0x0c068e06 */
if(!s->budget--) { s->failed_pc=0x0c068e06u; return 0; }
fr[3]=0x3f800000u;
goto P_0c068e08;
P_0c068e08: /* original f437, guest PC 0x0c068e08 */
if(!s->budget--) { s->failed_pc=0x0c068e08u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c068e0a;
P_0c068e0a: /* original 000b, guest PC 0x0c068e0a */
if(!s->budget--) { s->failed_pc=0x0c068e0au; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c068e0c: /* original f04c, guest PC 0x0c068e0c */
if(!s->budget--) { s->failed_pc=0x0c068e0cu; return 0; }
vf3_matrix_move(s,0,4);
return vf3_matrix_family(0x0c068e0eu,s,ram);
P_0c068f92: /* original f35c, guest PC 0x0c068f92 */
if(!s->budget--) { s->failed_pc=0x0c068f92u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068f94;
P_0c068f94: /* original f861, guest PC 0x0c068f94 */
if(!s->budget--) { s->failed_pc=0x0c068f94u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c068f96;
P_0c068f96: /* original f57c, guest PC 0x0c068f96 */
if(!s->budget--) { s->failed_pc=0x0c068f96u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c068f98;
P_0c068f98: /* original f531, guest PC 0x0c068f98 */
if(!s->budget--) { s->failed_pc=0x0c068f98u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c068f9a;
P_0c068f9a: /* original f34c, guest PC 0x0c068f9a */
if(!s->budget--) { s->failed_pc=0x0c068f9au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c068f9c;
P_0c068f9c: /* original f46c, guest PC 0x0c068f9c */
if(!s->budget--) { s->failed_pc=0x0c068f9cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c068f9e;
P_0c068f9e: /* original f431, guest PC 0x0c068f9e */
if(!s->budget--) { s->failed_pc=0x0c068f9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c068fa0;
P_0c068fa0: /* original f69c, guest PC 0x0c068fa0 */
if(!s->budget--) { s->failed_pc=0x0c068fa0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c068fa2;
P_0c068fa2: /* original f671, guest PC 0x0c068fa2 */
if(!s->budget--) { s->failed_pc=0x0c068fa2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c068fa4;
P_0c068fa4: /* original f582, guest PC 0x0c068fa4 */
if(!s->budget--) { s->failed_pc=0x0c068fa4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c068fa6;
P_0c068fa6: /* original f28d, guest PC 0x0c068fa6 */
if(!s->budget--) { s->failed_pc=0x0c068fa6u; return 0; }
fr[2]=0;
goto P_0c068fa8;
P_0c068fa8: /* original f462, guest PC 0x0c068fa8 */
if(!s->budget--) { s->failed_pc=0x0c068fa8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c068faa;
P_0c068faa: /* original f34c, guest PC 0x0c068faa */
if(!s->budget--) { s->failed_pc=0x0c068faau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c068fac;
P_0c068fac: /* original f45c, guest PC 0x0c068fac */
if(!s->budget--) { s->failed_pc=0x0c068facu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c068fae;
P_0c068fae: /* original f431, guest PC 0x0c068fae */
if(!s->budget--) { s->failed_pc=0x0c068faeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c068fb0;
P_0c068fb0: /* original f425, guest PC 0x0c068fb0 */
if(!s->budget--) { s->failed_pc=0x0c068fb0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c068fb2;
P_0c068fb2: /* original 8b01, guest PC 0x0c068fb2 */
if(!s->budget--) { s->failed_pc=0x0c068fb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068fb8; }
goto P_0c068fb4;
P_0c068fb4: /* original 000b, guest PC 0x0c068fb4 */
if(!s->budget--) { s->failed_pc=0x0c068fb4u; return 0; }
target=r[16];
r[0]=0x00000002u;
s->pc=target; return ram->oob==0;
P_0c068fb6: /* original e002, guest PC 0x0c068fb6 */
if(!s->budget--) { s->failed_pc=0x0c068fb6u; return 0; }
r[0]=0x00000002u;
goto P_0c068fb8;
P_0c068fb8: /* original f38d, guest PC 0x0c068fb8 */
if(!s->budget--) { s->failed_pc=0x0c068fb8u; return 0; }
fr[3]=0;
goto P_0c068fba;
P_0c068fba: /* original f434, guest PC 0x0c068fba */
if(!s->budget--) { s->failed_pc=0x0c068fbau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c068fbc;
P_0c068fbc: /* original 8b01, guest PC 0x0c068fbc */
if(!s->budget--) { s->failed_pc=0x0c068fbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068fc2; }
goto P_0c068fbe;
P_0c068fbe: /* original 000b, guest PC 0x0c068fbe */
if(!s->budget--) { s->failed_pc=0x0c068fbeu; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c068fc0: /* original e001, guest PC 0x0c068fc0 */
if(!s->budget--) { s->failed_pc=0x0c068fc0u; return 0; }
r[0]=0x00000001u;
goto P_0c068fc2;
P_0c068fc2: /* original e004, guest PC 0x0c068fc2 */
if(!s->budget--) { s->failed_pc=0x0c068fc2u; return 0; }
r[0]=0x00000004u;
goto P_0c068fc4;
P_0c068fc4: /* original 000b, guest PC 0x0c068fc4 */
if(!s->budget--) { s->failed_pc=0x0c068fc4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068fc6: /* original 0009, guest PC 0x0c068fc6 */
if(!s->budget--) { s->failed_pc=0x0c068fc6u; return 0; }
return vf3_matrix_family(0x0c068fc8u,s,ram);
P_0c068fe4: /* original 2fe6, guest PC 0x0c068fe4 */
if(!s->budget--) { s->failed_pc=0x0c068fe4u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c068fe6;
P_0c068fe6: /* original 2fd6, guest PC 0x0c068fe6 */
if(!s->budget--) { s->failed_pc=0x0c068fe6u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c068fe8;
P_0c068fe8: /* original 2fc6, guest PC 0x0c068fe8 */
if(!s->budget--) { s->failed_pc=0x0c068fe8u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c068fea;
P_0c068fea: /* original 2fb6, guest PC 0x0c068fea */
if(!s->budget--) { s->failed_pc=0x0c068feau; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c068fec;
P_0c068fec: /* original 2fa6, guest PC 0x0c068fec */
if(!s->budget--) { s->failed_pc=0x0c068fecu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c068fee;
P_0c068fee: /* original 2f96, guest PC 0x0c068fee */
if(!s->budget--) { s->failed_pc=0x0c068feeu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c068ff0;
P_0c068ff0: /* original fffb, guest PC 0x0c068ff0 */
if(!s->budget--) { s->failed_pc=0x0c068ff0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c068ff2;
P_0c068ff2: /* original ffeb, guest PC 0x0c068ff2 */
if(!s->budget--) { s->failed_pc=0x0c068ff2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c068ff4;
P_0c068ff4: /* original d348, guest PC 0x0c068ff4 */
if(!s->budget--) { s->failed_pc=0x0c068ff4u; return 0; }
r[3]=read(ram,0x0c069118u,4);
goto P_0c068ff6;
P_0c068ff6: /* original 4f22, guest PC 0x0c068ff6 */
if(!s->budget--) { s->failed_pc=0x0c068ff6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068ff8;
P_0c068ff8: /* original 6742, guest PC 0x0c068ff8 */
if(!s->budget--) { s->failed_pc=0x0c068ff8u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c068ffa;
P_0c068ffa: /* original 5541, guest PC 0x0c068ffa */
if(!s->budget--) { s->failed_pc=0x0c068ffau; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c068ffc;
P_0c068ffc: /* original e401, guest PC 0x0c068ffc */
if(!s->budget--) { s->failed_pc=0x0c068ffcu; return 0; }
r[4]=0x00000001u;
goto P_0c068ffe;
P_0c068ffe: /* original 6632, guest PC 0x0c068ffe */
if(!s->budget--) { s->failed_pc=0x0c068ffeu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c069000;
P_0c069000: /* original 2748, guest PC 0x0c069000 */
if(!s->budget--) { s->failed_pc=0x0c069000u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[4])==0)!=0);
goto P_0c069002;
P_0c069002: /* original 7ffc, guest PC 0x0c069002 */
if(!s->budget--) { s->failed_pc=0x0c069002u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c069004;
P_0c069004: /* original 8d02, guest PC 0x0c069004 */
if(!s->budget--) { s->failed_pc=0x0c069004u; return 0; }
cond=r[17]&1u;
r[5]+=r[6];
if(cond) { goto P_0c06900c; }
goto P_0c069008;
P_0c069006: /* original 356c, guest PC 0x0c069006 */
if(!s->budget--) { s->failed_pc=0x0c069006u; return 0; }
r[5]+=r[6];
goto P_0c069008;
P_0c069008: /* original a07a, guest PC 0x0c069008 */
if(!s->budget--) { s->failed_pc=0x0c069008u; return 0; }
r[0]=0x00000001u;
goto P_0c069100;
P_0c06900a: /* original e001, guest PC 0x0c06900a */
if(!s->budget--) { s->failed_pc=0x0c06900au; return 0; }
r[0]=0x00000001u;
goto P_0c06900c;
P_0c06900c: /* original e018, guest PC 0x0c06900c */
if(!s->budget--) { s->failed_pc=0x0c06900cu; return 0; }
r[0]=0x00000018u;
goto P_0c06900e;
P_0c06900e: /* original fe4c, guest PC 0x0c06900e */
if(!s->budget--) { s->failed_pc=0x0c06900eu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c069010;
P_0c069010: /* original 6752, guest PC 0x0c069010 */
if(!s->budget--) { s->failed_pc=0x0c069010u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c069012;
P_0c069012: /* original 2749, guest PC 0x0c069012 */
if(!s->budget--) { s->failed_pc=0x0c069012u; return 0; }
r[7]&=r[4];
goto P_0c069014;
P_0c069014: /* original 2f72, guest PC 0x0c069014 */
if(!s->budget--) { s->failed_pc=0x0c069014u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c069016;
P_0c069016: /* original f456, guest PC 0x0c069016 */
if(!s->budget--) { s->failed_pc=0x0c069016u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c069018;
P_0c069018: /* original f38d, guest PC 0x0c069018 */
if(!s->budget--) { s->failed_pc=0x0c069018u; return 0; }
fr[3]=0;
goto P_0c06901a;
P_0c06901a: /* original f434, guest PC 0x0c06901a */
if(!s->budget--) { s->failed_pc=0x0c06901au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06901c;
P_0c06901c: /* original 8d6f, guest PC 0x0c06901c */
if(!s->budget--) { s->failed_pc=0x0c06901cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,5);
if(cond) { goto P_0c0690fe; }
goto P_0c069020;
P_0c06901e: /* original ff5c, guest PC 0x0c06901e */
if(!s->budget--) { s->failed_pc=0x0c06901eu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c069020;
P_0c069020: /* original 5451, guest PC 0x0c069020 */
if(!s->budget--) { s->failed_pc=0x0c069020u; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c069022;
P_0c069022: /* original e008, guest PC 0x0c069022 */
if(!s->budget--) { s->failed_pc=0x0c069022u; return 0; }
r[0]=0x00000008u;
goto P_0c069024;
P_0c069024: /* original f5fc, guest PC 0x0c069024 */
if(!s->budget--) { s->failed_pc=0x0c069024u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069026;
P_0c069026: /* original 346c, guest PC 0x0c069026 */
if(!s->budget--) { s->failed_pc=0x0c069026u; return 0; }
r[4]+=r[6];
goto P_0c069028;
P_0c069028: /* original 6d43, guest PC 0x0c069028 */
if(!s->budget--) { s->failed_pc=0x0c069028u; return 0; }
r[13]=r[4];
goto P_0c06902a;
P_0c06902a: /* original 5452, guest PC 0x0c06902a */
if(!s->budget--) { s->failed_pc=0x0c06902au; return 0; }
r[4]=read(ram,r[5]+8,4);
goto P_0c06902c;
P_0c06902c: /* original f6d8, guest PC 0x0c06902c */
if(!s->budget--) { s->failed_pc=0x0c06902cu; return 0; }
vf3_matrix_load(s,ram,6,r[13]);
goto P_0c06902e;
P_0c06902e: /* original 346c, guest PC 0x0c06902e */
if(!s->budget--) { s->failed_pc=0x0c06902eu; return 0; }
r[4]+=r[6];
goto P_0c069030;
P_0c069030: /* original f7d6, guest PC 0x0c069030 */
if(!s->budget--) { s->failed_pc=0x0c069030u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c069032;
P_0c069032: /* original 6b43, guest PC 0x0c069032 */
if(!s->budget--) { s->failed_pc=0x0c069032u; return 0; }
r[11]=r[4];
goto P_0c069034;
P_0c069034: /* original 5453, guest PC 0x0c069034 */
if(!s->budget--) { s->failed_pc=0x0c069034u; return 0; }
r[4]=read(ram,r[5]+12,4);
goto P_0c069036;
P_0c069036: /* original f8b8, guest PC 0x0c069036 */
if(!s->budget--) { s->failed_pc=0x0c069036u; return 0; }
vf3_matrix_load(s,ram,8,r[11]);
goto P_0c069038;
P_0c069038: /* original 346c, guest PC 0x0c069038 */
if(!s->budget--) { s->failed_pc=0x0c069038u; return 0; }
r[4]+=r[6];
goto P_0c06903a;
P_0c06903a: /* original f9b6, guest PC 0x0c06903a */
if(!s->budget--) { s->failed_pc=0x0c06903au; return 0; }
vf3_matrix_load(s,ram,9,r[11]+r[0]);
goto P_0c06903c;
P_0c06903c: /* original 6c43, guest PC 0x0c06903c */
if(!s->budget--) { s->failed_pc=0x0c06903cu; return 0; }
r[12]=r[4];
goto P_0c06903e;
P_0c06903e: /* original 5454, guest PC 0x0c06903e */
if(!s->budget--) { s->failed_pc=0x0c06903eu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c069040;
P_0c069040: /* original 346c, guest PC 0x0c069040 */
if(!s->budget--) { s->failed_pc=0x0c069040u; return 0; }
r[4]+=r[6];
goto P_0c069042;
P_0c069042: /* original 6a43, guest PC 0x0c069042 */
if(!s->budget--) { s->failed_pc=0x0c069042u; return 0; }
r[10]=r[4];
goto P_0c069044;
P_0c069044: /* original bfa5, guest PC 0x0c069044 */
if(!s->budget--) { s->failed_pc=0x0c069044u; return 0; }
target=0x0c068f92u; r[16]=0x0c069048u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c069048u) { target=s->pc; goto dispatch; }
goto P_0c069048;
P_0c069046: /* original f4ec, guest PC 0x0c069046 */
if(!s->budget--) { s->failed_pc=0x0c069046u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c069048;
P_0c069048: /* original 6e03, guest PC 0x0c069048 */
if(!s->budget--) { s->failed_pc=0x0c069048u; return 0; }
r[14]=r[0];
goto P_0c06904a;
P_0c06904a: /* original e008, guest PC 0x0c06904a */
if(!s->budget--) { s->failed_pc=0x0c06904au; return 0; }
r[0]=0x00000008u;
goto P_0c06904c;
P_0c06904c: /* original f7b6, guest PC 0x0c06904c */
if(!s->budget--) { s->failed_pc=0x0c06904cu; return 0; }
vf3_matrix_load(s,ram,7,r[11]+r[0]);
goto P_0c06904e;
P_0c06904e: /* original f6b8, guest PC 0x0c06904e */
if(!s->budget--) { s->failed_pc=0x0c06904eu; return 0; }
vf3_matrix_load(s,ram,6,r[11]);
goto P_0c069050;
P_0c069050: /* original f9c6, guest PC 0x0c069050 */
if(!s->budget--) { s->failed_pc=0x0c069050u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c069052;
P_0c069052: /* original f8c8, guest PC 0x0c069052 */
if(!s->budget--) { s->failed_pc=0x0c069052u; return 0; }
vf3_matrix_load(s,ram,8,r[12]);
goto P_0c069054;
P_0c069054: /* original f5fc, guest PC 0x0c069054 */
if(!s->budget--) { s->failed_pc=0x0c069054u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069056;
P_0c069056: /* original bf9c, guest PC 0x0c069056 */
if(!s->budget--) { s->failed_pc=0x0c069056u; return 0; }
target=0x0c068f92u; r[16]=0x0c06905au;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06905au) { target=s->pc; goto dispatch; }
goto P_0c06905a;
P_0c069058: /* original f4ec, guest PC 0x0c069058 */
if(!s->budget--) { s->failed_pc=0x0c069058u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06905a;
P_0c06905a: /* original 6903, guest PC 0x0c06905a */
if(!s->budget--) { s->failed_pc=0x0c06905au; return 0; }
r[9]=r[0];
goto P_0c06905c;
P_0c06905c: /* original e008, guest PC 0x0c06905c */
if(!s->budget--) { s->failed_pc=0x0c06905cu; return 0; }
r[0]=0x00000008u;
goto P_0c06905e;
P_0c06905e: /* original f7c6, guest PC 0x0c06905e */
if(!s->budget--) { s->failed_pc=0x0c06905eu; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c069060;
P_0c069060: /* original f6c8, guest PC 0x0c069060 */
if(!s->budget--) { s->failed_pc=0x0c069060u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c069062;
P_0c069062: /* original f9d6, guest PC 0x0c069062 */
if(!s->budget--) { s->failed_pc=0x0c069062u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c069064;
P_0c069064: /* original f8d8, guest PC 0x0c069064 */
if(!s->budget--) { s->failed_pc=0x0c069064u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c069066;
P_0c069066: /* original f5fc, guest PC 0x0c069066 */
if(!s->budget--) { s->failed_pc=0x0c069066u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069068;
P_0c069068: /* original bf93, guest PC 0x0c069068 */
if(!s->budget--) { s->failed_pc=0x0c069068u; return 0; }
target=0x0c068f92u; r[16]=0x0c06906cu;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06906cu) { target=s->pc; goto dispatch; }
goto P_0c06906c;
P_0c06906a: /* original f4ec, guest PC 0x0c06906a */
if(!s->budget--) { s->failed_pc=0x0c06906au; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06906c;
P_0c06906c: /* original 6b03, guest PC 0x0c06906c */
if(!s->budget--) { s->failed_pc=0x0c06906cu; return 0; }
r[11]=r[0];
goto P_0c06906e;
P_0c06906e: /* original e008, guest PC 0x0c06906e */
if(!s->budget--) { s->failed_pc=0x0c06906eu; return 0; }
r[0]=0x00000008u;
goto P_0c069070;
P_0c069070: /* original f7c6, guest PC 0x0c069070 */
if(!s->budget--) { s->failed_pc=0x0c069070u; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c069072;
P_0c069072: /* original f6c8, guest PC 0x0c069072 */
if(!s->budget--) { s->failed_pc=0x0c069072u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c069074;
P_0c069074: /* original f9a6, guest PC 0x0c069074 */
if(!s->budget--) { s->failed_pc=0x0c069074u; return 0; }
vf3_matrix_load(s,ram,9,r[10]+r[0]);
goto P_0c069076;
P_0c069076: /* original f8a8, guest PC 0x0c069076 */
if(!s->budget--) { s->failed_pc=0x0c069076u; return 0; }
vf3_matrix_load(s,ram,8,r[10]);
goto P_0c069078;
P_0c069078: /* original f5fc, guest PC 0x0c069078 */
if(!s->budget--) { s->failed_pc=0x0c069078u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06907a;
P_0c06907a: /* original bf8a, guest PC 0x0c06907a */
if(!s->budget--) { s->failed_pc=0x0c06907au; return 0; }
target=0x0c068f92u; r[16]=0x0c06907eu;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06907eu) { target=s->pc; goto dispatch; }
goto P_0c06907e;
P_0c06907c: /* original f4ec, guest PC 0x0c06907c */
if(!s->budget--) { s->failed_pc=0x0c06907cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06907e;
P_0c06907e: /* original 6c03, guest PC 0x0c06907e */
if(!s->budget--) { s->failed_pc=0x0c06907eu; return 0; }
r[12]=r[0];
goto P_0c069080;
P_0c069080: /* original e008, guest PC 0x0c069080 */
if(!s->budget--) { s->failed_pc=0x0c069080u; return 0; }
r[0]=0x00000008u;
goto P_0c069082;
P_0c069082: /* original f7a6, guest PC 0x0c069082 */
if(!s->budget--) { s->failed_pc=0x0c069082u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c069084;
P_0c069084: /* original f6a8, guest PC 0x0c069084 */
if(!s->budget--) { s->failed_pc=0x0c069084u; return 0; }
vf3_matrix_load(s,ram,6,r[10]);
goto P_0c069086;
P_0c069086: /* original f9d6, guest PC 0x0c069086 */
if(!s->budget--) { s->failed_pc=0x0c069086u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c069088;
P_0c069088: /* original f8d8, guest PC 0x0c069088 */
if(!s->budget--) { s->failed_pc=0x0c069088u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c06908a;
P_0c06908a: /* original f5fc, guest PC 0x0c06908a */
if(!s->budget--) { s->failed_pc=0x0c06908au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06908c;
P_0c06908c: /* original bf81, guest PC 0x0c06908c */
if(!s->budget--) { s->failed_pc=0x0c06908cu; return 0; }
target=0x0c068f92u; r[16]=0x0c069090u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c069090u) { target=s->pc; goto dispatch; }
goto P_0c069090;
P_0c06908e: /* original f4ec, guest PC 0x0c06908e */
if(!s->budget--) { s->failed_pc=0x0c06908eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c069090;
P_0c069090: /* original 6293, guest PC 0x0c069090 */
if(!s->budget--) { s->failed_pc=0x0c069090u; return 0; }
r[2]=r[9];
goto P_0c069092;
P_0c069092: /* original e402, guest PC 0x0c069092 */
if(!s->budget--) { s->failed_pc=0x0c069092u; return 0; }
r[4]=0x00000002u;
goto P_0c069094;
P_0c069094: /* original e504, guest PC 0x0c069094 */
if(!s->budget--) { s->failed_pc=0x0c069094u; return 0; }
r[5]=0x00000004u;
goto P_0c069096;
P_0c069096: /* original 6303, guest PC 0x0c069096 */
if(!s->budget--) { s->failed_pc=0x0c069096u; return 0; }
r[3]=r[0];
goto P_0c069098;
P_0c069098: /* original 2249, guest PC 0x0c069098 */
if(!s->budget--) { s->failed_pc=0x0c069098u; return 0; }
r[2]&=r[4];
goto P_0c06909a;
P_0c06909a: /* original 6603, guest PC 0x0c06909a */
if(!s->budget--) { s->failed_pc=0x0c06909au; return 0; }
r[6]=r[0];
goto P_0c06909c;
P_0c06909c: /* original 2959, guest PC 0x0c06909c */
if(!s->budget--) { s->failed_pc=0x0c06909cu; return 0; }
r[9]&=r[5];
goto P_0c06909e;
P_0c06909e: /* original 2e2b, guest PC 0x0c06909e */
if(!s->budget--) { s->failed_pc=0x0c06909eu; return 0; }
r[14]|=r[2];
goto P_0c0690a0;
P_0c0690a0: /* original 2349, guest PC 0x0c0690a0 */
if(!s->budget--) { s->failed_pc=0x0c0690a0u; return 0; }
r[3]&=r[4];
goto P_0c0690a2;
P_0c0690a2: /* original 2e9b, guest PC 0x0c0690a2 */
if(!s->budget--) { s->failed_pc=0x0c0690a2u; return 0; }
r[14]|=r[9];
goto P_0c0690a4;
P_0c0690a4: /* original 62e3, guest PC 0x0c0690a4 */
if(!s->budget--) { s->failed_pc=0x0c0690a4u; return 0; }
r[2]=r[14];
goto P_0c0690a6;
P_0c0690a6: /* original 2c3b, guest PC 0x0c0690a6 */
if(!s->budget--) { s->failed_pc=0x0c0690a6u; return 0; }
r[12]|=r[3];
goto P_0c0690a8;
P_0c0690a8: /* original 2249, guest PC 0x0c0690a8 */
if(!s->budget--) { s->failed_pc=0x0c0690a8u; return 0; }
r[2]&=r[4];
goto P_0c0690aa;
P_0c0690aa: /* original 63e3, guest PC 0x0c0690aa */
if(!s->budget--) { s->failed_pc=0x0c0690aau; return 0; }
r[3]=r[14];
goto P_0c0690ac;
P_0c0690ac: /* original 2659, guest PC 0x0c0690ac */
if(!s->budget--) { s->failed_pc=0x0c0690acu; return 0; }
r[6]&=r[5];
goto P_0c0690ae;
P_0c0690ae: /* original 2359, guest PC 0x0c0690ae */
if(!s->budget--) { s->failed_pc=0x0c0690aeu; return 0; }
r[3]&=r[5];
goto P_0c0690b0;
P_0c0690b0: /* original 2b2b, guest PC 0x0c0690b0 */
if(!s->budget--) { s->failed_pc=0x0c0690b0u; return 0; }
r[11]|=r[2];
goto P_0c0690b2;
P_0c0690b2: /* original 2b3b, guest PC 0x0c0690b2 */
if(!s->budget--) { s->failed_pc=0x0c0690b2u; return 0; }
r[11]|=r[3];
goto P_0c0690b4;
P_0c0690b4: /* original 2c6b, guest PC 0x0c0690b4 */
if(!s->budget--) { s->failed_pc=0x0c0690b4u; return 0; }
r[12]|=r[6];
goto P_0c0690b6;
P_0c0690b6: /* original 66b3, guest PC 0x0c0690b6 */
if(!s->budget--) { s->failed_pc=0x0c0690b6u; return 0; }
r[6]=r[11];
goto P_0c0690b8;
P_0c0690b8: /* original 2659, guest PC 0x0c0690b8 */
if(!s->budget--) { s->failed_pc=0x0c0690b8u; return 0; }
r[6]&=r[5];
goto P_0c0690ba;
P_0c0690ba: /* original 2668, guest PC 0x0c0690ba */
if(!s->budget--) { s->failed_pc=0x0c0690bau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690bc;
P_0c0690bc: /* original 8b02, guest PC 0x0c0690bc */
if(!s->budget--) { s->failed_pc=0x0c0690bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690c4; }
goto P_0c0690be;
P_0c0690be: /* original 63b3, guest PC 0x0c0690be */
if(!s->budget--) { s->failed_pc=0x0c0690beu; return 0; }
r[3]=r[11];
goto P_0c0690c0;
P_0c0690c0: /* original 2348, guest PC 0x0c0690c0 */
if(!s->budget--) { s->failed_pc=0x0c0690c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0690c2;
P_0c0690c2: /* original 8b04, guest PC 0x0c0690c2 */
if(!s->budget--) { s->failed_pc=0x0c0690c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690ce; }
goto P_0c0690c4;
P_0c0690c4: /* original 2668, guest PC 0x0c0690c4 */
if(!s->budget--) { s->failed_pc=0x0c0690c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690c6;
P_0c0690c6: /* original 8904, guest PC 0x0c0690c6 */
if(!s->budget--) { s->failed_pc=0x0c0690c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0690d2; }
goto P_0c0690c8;
P_0c0690c8: /* original 62b3, guest PC 0x0c0690c8 */
if(!s->budget--) { s->failed_pc=0x0c0690c8u; return 0; }
r[2]=r[11];
goto P_0c0690ca;
P_0c0690ca: /* original 2248, guest PC 0x0c0690ca */
if(!s->budget--) { s->failed_pc=0x0c0690cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0690cc;
P_0c0690cc: /* original 8b01, guest PC 0x0c0690cc */
if(!s->budget--) { s->failed_pc=0x0c0690ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690d2; }
goto P_0c0690ce;
P_0c0690ce: /* original a017, guest PC 0x0c0690ce */
if(!s->budget--) { s->failed_pc=0x0c0690ceu; return 0; }
r[0]=0x00000002u;
goto P_0c069100;
P_0c0690d0: /* original e002, guest PC 0x0c0690d0 */
if(!s->budget--) { s->failed_pc=0x0c0690d0u; return 0; }
r[0]=0x00000002u;
goto P_0c0690d2;
P_0c0690d2: /* original 62f2, guest PC 0x0c0690d2 */
if(!s->budget--) { s->failed_pc=0x0c0690d2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0690d4;
P_0c0690d4: /* original 2228, guest PC 0x0c0690d4 */
if(!s->budget--) { s->failed_pc=0x0c0690d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0690d6;
P_0c0690d6: /* original 8b12, guest PC 0x0c0690d6 */
if(!s->budget--) { s->failed_pc=0x0c0690d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fe; }
goto P_0c0690d8;
P_0c0690d8: /* original 62c3, guest PC 0x0c0690d8 */
if(!s->budget--) { s->failed_pc=0x0c0690d8u; return 0; }
r[2]=r[12];
goto P_0c0690da;
P_0c0690da: /* original 2249, guest PC 0x0c0690da */
if(!s->budget--) { s->failed_pc=0x0c0690dau; return 0; }
r[2]&=r[4];
goto P_0c0690dc;
P_0c0690dc: /* original 2c59, guest PC 0x0c0690dc */
if(!s->budget--) { s->failed_pc=0x0c0690dcu; return 0; }
r[12]&=r[5];
goto P_0c0690de;
P_0c0690de: /* original 2e2b, guest PC 0x0c0690de */
if(!s->budget--) { s->failed_pc=0x0c0690deu; return 0; }
r[14]|=r[2];
goto P_0c0690e0;
P_0c0690e0: /* original 2ecb, guest PC 0x0c0690e0 */
if(!s->budget--) { s->failed_pc=0x0c0690e0u; return 0; }
r[14]|=r[12];
goto P_0c0690e2;
P_0c0690e2: /* original 66e3, guest PC 0x0c0690e2 */
if(!s->budget--) { s->failed_pc=0x0c0690e2u; return 0; }
r[6]=r[14];
goto P_0c0690e4;
P_0c0690e4: /* original 2659, guest PC 0x0c0690e4 */
if(!s->budget--) { s->failed_pc=0x0c0690e4u; return 0; }
r[6]&=r[5];
goto P_0c0690e6;
P_0c0690e6: /* original 2668, guest PC 0x0c0690e6 */
if(!s->budget--) { s->failed_pc=0x0c0690e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690e8;
P_0c0690e8: /* original 8b02, guest PC 0x0c0690e8 */
if(!s->budget--) { s->failed_pc=0x0c0690e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690f0; }
goto P_0c0690ea;
P_0c0690ea: /* original 62e3, guest PC 0x0c0690ea */
if(!s->budget--) { s->failed_pc=0x0c0690eau; return 0; }
r[2]=r[14];
goto P_0c0690ec;
P_0c0690ec: /* original 2248, guest PC 0x0c0690ec */
if(!s->budget--) { s->failed_pc=0x0c0690ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0690ee;
P_0c0690ee: /* original 8b04, guest PC 0x0c0690ee */
if(!s->budget--) { s->failed_pc=0x0c0690eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fa; }
goto P_0c0690f0;
P_0c0690f0: /* original 2668, guest PC 0x0c0690f0 */
if(!s->budget--) { s->failed_pc=0x0c0690f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690f2;
P_0c0690f2: /* original 8904, guest PC 0x0c0690f2 */
if(!s->budget--) { s->failed_pc=0x0c0690f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0690fe; }
goto P_0c0690f4;
P_0c0690f4: /* original 63e3, guest PC 0x0c0690f4 */
if(!s->budget--) { s->failed_pc=0x0c0690f4u; return 0; }
r[3]=r[14];
goto P_0c0690f6;
P_0c0690f6: /* original 2348, guest PC 0x0c0690f6 */
if(!s->budget--) { s->failed_pc=0x0c0690f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0690f8;
P_0c0690f8: /* original 8b01, guest PC 0x0c0690f8 */
if(!s->budget--) { s->failed_pc=0x0c0690f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fe; }
goto P_0c0690fa;
P_0c0690fa: /* original a001, guest PC 0x0c0690fa */
if(!s->budget--) { s->failed_pc=0x0c0690fau; return 0; }
r[0]=0x00000004u;
goto P_0c069100;
P_0c0690fc: /* original e004, guest PC 0x0c0690fc */
if(!s->budget--) { s->failed_pc=0x0c0690fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0690fe;
P_0c0690fe: /* original e000, guest PC 0x0c0690fe */
if(!s->budget--) { s->failed_pc=0x0c0690feu; return 0; }
r[0]=0x00000000u;
goto P_0c069100;
P_0c069100: /* original 7f04, guest PC 0x0c069100 */
if(!s->budget--) { s->failed_pc=0x0c069100u; return 0; }
r[15]+=0x00000004u;
goto P_0c069102;
P_0c069102: /* original 4f26, guest PC 0x0c069102 */
if(!s->budget--) { s->failed_pc=0x0c069102u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c069104;
P_0c069104: /* original fef9, guest PC 0x0c069104 */
if(!s->budget--) { s->failed_pc=0x0c069104u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069106;
P_0c069106: /* original fff9, guest PC 0x0c069106 */
if(!s->budget--) { s->failed_pc=0x0c069106u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069108;
P_0c069108: /* original 69f6, guest PC 0x0c069108 */
if(!s->budget--) { s->failed_pc=0x0c069108u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06910a;
P_0c06910a: /* original 6af6, guest PC 0x0c06910a */
if(!s->budget--) { s->failed_pc=0x0c06910au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06910c;
P_0c06910c: /* original 6bf6, guest PC 0x0c06910c */
if(!s->budget--) { s->failed_pc=0x0c06910cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06910e;
P_0c06910e: /* original 6cf6, guest PC 0x0c06910e */
if(!s->budget--) { s->failed_pc=0x0c06910eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c069110;
P_0c069110: /* original 6df6, guest PC 0x0c069110 */
if(!s->budget--) { s->failed_pc=0x0c069110u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c069112;
P_0c069112: /* original 000b, guest PC 0x0c069112 */
if(!s->budget--) { s->failed_pc=0x0c069112u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c069114: /* original 6ef6, guest PC 0x0c069114 */
if(!s->budget--) { s->failed_pc=0x0c069114u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c069116u,s,ram);
P_0c06911c: /* original 2fe6, guest PC 0x0c06911c */
if(!s->budget--) { s->failed_pc=0x0c06911cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c06911e;
P_0c06911e: /* original e004, guest PC 0x0c06911e */
if(!s->budget--) { s->failed_pc=0x0c06911eu; return 0; }
r[0]=0x00000004u;
goto P_0c069120;
P_0c069120: /* original 2fd6, guest PC 0x0c069120 */
if(!s->budget--) { s->failed_pc=0x0c069120u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c069122;
P_0c069122: /* original 6d43, guest PC 0x0c069122 */
if(!s->budget--) { s->failed_pc=0x0c069122u; return 0; }
r[13]=r[4];
goto P_0c069124;
P_0c069124: /* original 2fc6, guest PC 0x0c069124 */
if(!s->budget--) { s->failed_pc=0x0c069124u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c069126;
P_0c069126: /* original ec0f, guest PC 0x0c069126 */
if(!s->budget--) { s->failed_pc=0x0c069126u; return 0; }
r[12]=0x0000000fu;
goto P_0c069128;
P_0c069128: /* original 2fb6, guest PC 0x0c069128 */
if(!s->budget--) { s->failed_pc=0x0c069128u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c06912a;
P_0c06912a: /* original 4f22, guest PC 0x0c06912a */
if(!s->budget--) { s->failed_pc=0x0c06912au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06912c;
P_0c06912c: /* original 7fe0, guest PC 0x0c06912c */
if(!s->budget--) { s->failed_pc=0x0c06912cu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c06912e;
P_0c06912e: /* original 66f3, guest PC 0x0c06912e */
if(!s->budget--) { s->failed_pc=0x0c06912eu; return 0; }
r[6]=r[15];
goto P_0c069130;
P_0c069130: /* original 7604, guest PC 0x0c069130 */
if(!s->budget--) { s->failed_pc=0x0c069130u; return 0; }
r[6]+=0x00000004u;
goto P_0c069132;
P_0c069132: /* original 65f3, guest PC 0x0c069132 */
if(!s->budget--) { s->failed_pc=0x0c069132u; return 0; }
r[5]=r[15];
goto P_0c069134;
P_0c069134: /* original ff4a, guest PC 0x0c069134 */
if(!s->budget--) { s->failed_pc=0x0c069134u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c069136;
P_0c069136: /* original f54d, guest PC 0x0c069136 */
if(!s->budget--) { s->failed_pc=0x0c069136u; return 0; }
fr[5]^=0x80000000u;
goto P_0c069138;
P_0c069138: /* original ff57, guest PC 0x0c069138 */
if(!s->budget--) { s->failed_pc=0x0c069138u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c06913a;
P_0c06913a: /* original d339, guest PC 0x0c06913a */
if(!s->budget--) { s->failed_pc=0x0c06913au; return 0; }
r[3]=read(ram,0x0c069220u,4);
goto P_0c06913c;
P_0c06913c: /* original 6030, guest PC 0x0c06913c */
if(!s->budget--) { s->failed_pc=0x0c06913cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c06913e;
P_0c06913e: /* original 600c, guest PC 0x0c06913e */
if(!s->budget--) { s->failed_pc=0x0c06913eu; return 0; }
r[0]=r[0]&255u;
goto P_0c069140;
P_0c069140: /* original 2c09, guest PC 0x0c069140 */
if(!s->budget--) { s->failed_pc=0x0c069140u; return 0; }
r[12]&=r[0];
goto P_0c069142;
P_0c069142: /* original be07, guest PC 0x0c069142 */
if(!s->budget--) { s->failed_pc=0x0c069142u; return 0; }
target=0x0c068d54u; r[16]=0x0c069146u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c069146u) { target=s->pc; goto dispatch; }
goto P_0c069146;
P_0c069144: /* original 64c3, guest PC 0x0c069144 */
if(!s->budget--) { s->failed_pc=0x0c069144u; return 0; }
r[4]=r[12];
goto P_0c069146;
P_0c069146: /* original 906a, guest PC 0x0c069146 */
if(!s->budget--) { s->failed_pc=0x0c069146u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06921eu,2);
goto P_0c069148;
P_0c069148: /* original d536, guest PC 0x0c069148 */
if(!s->budget--) { s->failed_pc=0x0c069148u; return 0; }
r[5]=read(ram,0x0c069224u,4);
goto P_0c06914a;
P_0c06914a: /* original 035e, guest PC 0x0c06914a */
if(!s->budget--) { s->failed_pc=0x0c06914au; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c06914c;
P_0c06914c: /* original 2338, guest PC 0x0c06914c */
if(!s->budget--) { s->failed_pc=0x0c06914cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06914e;
P_0c06914e: /* original 8b06, guest PC 0x0c06914e */
if(!s->budget--) { s->failed_pc=0x0c06914eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06915e; }
goto P_0c069150;
P_0c069150: /* original e004, guest PC 0x0c069150 */
if(!s->budget--) { s->failed_pc=0x0c069150u; return 0; }
r[0]=0x00000004u;
goto P_0c069152;
P_0c069152: /* original 64d3, guest PC 0x0c069152 */
if(!s->budget--) { s->failed_pc=0x0c069152u; return 0; }
r[4]=r[13];
goto P_0c069154;
P_0c069154: /* original f5f6, guest PC 0x0c069154 */
if(!s->budget--) { s->failed_pc=0x0c069154u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c069156;
P_0c069156: /* original be45, guest PC 0x0c069156 */
if(!s->budget--) { s->failed_pc=0x0c069156u; return 0; }
target=0x0c068de4u; r[16]=0x0c06915au;
vf3_matrix_load(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06915au) { target=s->pc; goto dispatch; }
goto P_0c06915a;
P_0c069158: /* original f4f8, guest PC 0x0c069158 */
if(!s->budget--) { s->failed_pc=0x0c069158u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c06915a;
P_0c06915a: /* original a09d, guest PC 0x0c06915a */
if(!s->budget--) { s->failed_pc=0x0c06915au; return 0; }
r[0]=0x00000000u;
goto P_0c069298;
P_0c06915c: /* original e000, guest PC 0x0c06915c */
if(!s->budget--) { s->failed_pc=0x0c06915cu; return 0; }
r[0]=0x00000000u;
goto P_0c06915e;
P_0c06915e: /* original c732, guest PC 0x0c06915e */
if(!s->budget--) { s->failed_pc=0x0c06915eu; return 0; }
r[0]=0x0c069228u;
goto P_0c069160;
P_0c069160: /* original f3f8, guest PC 0x0c069160 */
if(!s->budget--) { s->failed_pc=0x0c069160u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c069162;
P_0c069162: /* original f408, guest PC 0x0c069162 */
if(!s->budget--) { s->failed_pc=0x0c069162u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c069164;
P_0c069164: /* original f435, guest PC 0x0c069164 */
if(!s->budget--) { s->failed_pc=0x0c069164u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c069166;
P_0c069166: /* original 8b0b, guest PC 0x0c069166 */
if(!s->budget--) { s->failed_pc=0x0c069166u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069180; }
goto P_0c069168;
P_0c069168: /* original e004, guest PC 0x0c069168 */
if(!s->budget--) { s->failed_pc=0x0c069168u; return 0; }
r[0]=0x00000004u;
goto P_0c06916a;
P_0c06916a: /* original f2f6, guest PC 0x0c06916a */
if(!s->budget--) { s->failed_pc=0x0c06916au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06916c;
P_0c06916c: /* original f425, guest PC 0x0c06916c */
if(!s->budget--) { s->failed_pc=0x0c06916cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c06916e;
P_0c06916e: /* original 8b07, guest PC 0x0c06916e */
if(!s->budget--) { s->failed_pc=0x0c06916eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069180; }
goto P_0c069170;
P_0c069170: /* original c72e, guest PC 0x0c069170 */
if(!s->budget--) { s->failed_pc=0x0c069170u; return 0; }
r[0]=0x0c06922cu;
goto P_0c069172;
P_0c069172: /* original f108, guest PC 0x0c069172 */
if(!s->budget--) { s->failed_pc=0x0c069172u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c069174;
P_0c069174: /* original f315, guest PC 0x0c069174 */
if(!s->budget--) { s->failed_pc=0x0c069174u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c069176;
P_0c069176: /* original 8b03, guest PC 0x0c069176 */
if(!s->budget--) { s->failed_pc=0x0c069176u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069180; }
goto P_0c069178;
P_0c069178: /* original c72c, guest PC 0x0c069178 */
if(!s->budget--) { s->failed_pc=0x0c069178u; return 0; }
r[0]=0x0c06922cu;
goto P_0c06917a;
P_0c06917a: /* original f308, guest PC 0x0c06917a */
if(!s->budget--) { s->failed_pc=0x0c06917au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06917c;
P_0c06917c: /* original f235, guest PC 0x0c06917c */
if(!s->budget--) { s->failed_pc=0x0c06917cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c06917e;
P_0c06917e: /* original 8901, guest PC 0x0c06917e */
if(!s->budget--) { s->failed_pc=0x0c06917eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069184; }
goto P_0c069180;
P_0c069180: /* original a05d, guest PC 0x0c069180 */
if(!s->budget--) { s->failed_pc=0x0c069180u; return 0; }
r[14]=0x00000001u;
goto P_0c06923e;
P_0c069182: /* original ee01, guest PC 0x0c069182 */
if(!s->budget--) { s->failed_pc=0x0c069182u; return 0; }
r[14]=0x00000001u;
goto P_0c069184;
P_0c069184: /* original c72a, guest PC 0x0c069184 */
if(!s->budget--) { s->failed_pc=0x0c069184u; return 0; }
r[0]=0x0c069230u;
goto P_0c069186;
P_0c069186: /* original f3f8, guest PC 0x0c069186 */
if(!s->budget--) { s->failed_pc=0x0c069186u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c069188;
P_0c069188: /* original f408, guest PC 0x0c069188 */
if(!s->budget--) { s->failed_pc=0x0c069188u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06918a;
P_0c06918a: /* original e018, guest PC 0x0c06918a */
if(!s->budget--) { s->failed_pc=0x0c06918au; return 0; }
r[0]=0x00000018u;
goto P_0c06918c;
P_0c06918c: /* original ff37, guest PC 0x0c06918c */
if(!s->budget--) { s->failed_pc=0x0c06918cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06918e;
P_0c06918e: /* original e004, guest PC 0x0c06918e */
if(!s->budget--) { s->failed_pc=0x0c06918eu; return 0; }
r[0]=0x00000004u;
goto P_0c069190;
P_0c069190: /* original f3f6, guest PC 0x0c069190 */
if(!s->budget--) { s->failed_pc=0x0c069190u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069192;
P_0c069192: /* original e014, guest PC 0x0c069192 */
if(!s->budget--) { s->failed_pc=0x0c069192u; return 0; }
r[0]=0x00000014u;
goto P_0c069194;
P_0c069194: /* original e71f, guest PC 0x0c069194 */
if(!s->budget--) { s->failed_pc=0x0c069194u; return 0; }
r[7]=0x0000001fu;
goto P_0c069196;
P_0c069196: /* original ff37, guest PC 0x0c069196 */
if(!s->budget--) { s->failed_pc=0x0c069196u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069198;
P_0c069198: /* original e018, guest PC 0x0c069198 */
if(!s->budget--) { s->failed_pc=0x0c069198u; return 0; }
r[0]=0x00000018u;
goto P_0c06919a;
P_0c06919a: /* original f3f6, guest PC 0x0c06919a */
if(!s->budget--) { s->failed_pc=0x0c06919au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06919c;
P_0c06919c: /* original e014, guest PC 0x0c06919c */
if(!s->budget--) { s->failed_pc=0x0c06919cu; return 0; }
r[0]=0x00000014u;
goto P_0c06919e;
P_0c06919e: /* original f54c, guest PC 0x0c06919e */
if(!s->budget--) { s->failed_pc=0x0c06919eu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0691a0;
P_0c0691a0: /* original f530, guest PC 0x0c0691a0 */
if(!s->budget--) { s->failed_pc=0x0c0691a0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0691a2;
P_0c0691a2: /* original f2f6, guest PC 0x0c0691a2 */
if(!s->budget--) { s->failed_pc=0x0c0691a2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0691a4;
P_0c0691a4: /* original e01c, guest PC 0x0c0691a4 */
if(!s->budget--) { s->failed_pc=0x0c0691a4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0691a6;
P_0c0691a6: /* original f420, guest PC 0x0c0691a6 */
if(!s->budget--) { s->failed_pc=0x0c0691a6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c0691a8;
P_0c0691a8: /* original f53d, guest PC 0x0c0691a8 */
if(!s->budget--) { s->failed_pc=0x0c0691a8u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c0691aa;
P_0c0691aa: /* original ff47, guest PC 0x0c0691aa */
if(!s->budget--) { s->failed_pc=0x0c0691aau; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0691ac;
P_0c0691ac: /* original f14c, guest PC 0x0c0691ac */
if(!s->budget--) { s->failed_pc=0x0c0691acu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0691ae;
P_0c0691ae: /* original 045a, guest PC 0x0c0691ae */
if(!s->budget--) { s->failed_pc=0x0c0691aeu; return 0; }
r[4]=r[53];
goto P_0c0691b0;
P_0c0691b0: /* original f13d, guest PC 0x0c0691b0 */
if(!s->budget--) { s->failed_pc=0x0c0691b0u; return 0; }
r[53]=truncate_float(fr[1]);
goto P_0c0691b2;
P_0c0691b2: /* original 9034, guest PC 0x0c0691b2 */
if(!s->budget--) { s->failed_pc=0x0c0691b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06921eu,2);
goto P_0c0691b4;
P_0c0691b4: /* original 2479, guest PC 0x0c0691b4 */
if(!s->budget--) { s->failed_pc=0x0c0691b4u; return 0; }
r[4]&=r[7];
goto P_0c0691b6;
P_0c0691b6: /* original 065a, guest PC 0x0c0691b6 */
if(!s->budget--) { s->failed_pc=0x0c0691b6u; return 0; }
r[6]=r[53];
goto P_0c0691b8;
P_0c0691b8: /* original 2679, guest PC 0x0c0691b8 */
if(!s->budget--) { s->failed_pc=0x0c0691b8u; return 0; }
r[6]&=r[7];
goto P_0c0691ba;
P_0c0691ba: /* original 4608, guest PC 0x0c0691ba */
if(!s->budget--) { s->failed_pc=0x0c0691bau; return 0; }
r[6]<<=2;
goto P_0c0691bc;
P_0c0691bc: /* original 4608, guest PC 0x0c0691bc */
if(!s->budget--) { s->failed_pc=0x0c0691bcu; return 0; }
r[6]<<=2;
goto P_0c0691be;
P_0c0691be: /* original 4600, guest PC 0x0c0691be */
if(!s->budget--) { s->failed_pc=0x0c0691beu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0691c0;
P_0c0691c0: /* original 246b, guest PC 0x0c0691c0 */
if(!s->budget--) { s->failed_pc=0x0c0691c0u; return 0; }
r[4]|=r[6];
goto P_0c0691c2;
P_0c0691c2: /* original 4408, guest PC 0x0c0691c2 */
if(!s->budget--) { s->failed_pc=0x0c0691c2u; return 0; }
r[4]<<=2;
goto P_0c0691c4;
P_0c0691c4: /* original 035e, guest PC 0x0c0691c4 */
if(!s->budget--) { s->failed_pc=0x0c0691c4u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0691c6;
P_0c0691c6: /* original 343c, guest PC 0x0c0691c6 */
if(!s->budget--) { s->failed_pc=0x0c0691c6u; return 0; }
r[4]+=r[3];
goto P_0c0691c8;
P_0c0691c8: /* original 6442, guest PC 0x0c0691c8 */
if(!s->budget--) { s->failed_pc=0x0c0691c8u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0691ca;
P_0c0691ca: /* original 6043, guest PC 0x0c0691ca */
if(!s->budget--) { s->failed_pc=0x0c0691cau; return 0; }
r[0]=r[4];
goto P_0c0691cc;
P_0c0691cc: /* original 88ff, guest PC 0x0c0691cc */
if(!s->budget--) { s->failed_pc=0x0c0691ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0691ce;
P_0c0691ce: /* original 8935, guest PC 0x0c0691ce */
if(!s->budget--) { s->failed_pc=0x0c0691ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06923c; }
goto P_0c0691d0;
P_0c0691d0: /* original db18, guest PC 0x0c0691d0 */
if(!s->budget--) { s->failed_pc=0x0c0691d0u; return 0; }
r[11]=read(ram,0x0c069234u,4);
goto P_0c0691d2;
P_0c0691d2: /* original 63b2, guest PC 0x0c0691d2 */
if(!s->budget--) { s->failed_pc=0x0c0691d2u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c0691d4;
P_0c0691d4: /* original 343c, guest PC 0x0c0691d4 */
if(!s->budget--) { s->failed_pc=0x0c0691d4u; return 0; }
r[4]+=r[3];
goto P_0c0691d6;
P_0c0691d6: /* original 6e43, guest PC 0x0c0691d6 */
if(!s->budget--) { s->failed_pc=0x0c0691d6u; return 0; }
r[14]=r[4];
goto P_0c0691d8;
P_0c0691d8: /* original 60e2, guest PC 0x0c0691d8 */
if(!s->budget--) { s->failed_pc=0x0c0691d8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0691da;
P_0c0691da: /* original 88ff, guest PC 0x0c0691da */
if(!s->budget--) { s->failed_pc=0x0c0691dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0691dc;
P_0c0691dc: /* original 892e, guest PC 0x0c0691dc */
if(!s->budget--) { s->failed_pc=0x0c0691dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06923c; }
goto P_0c0691de;
P_0c0691de: /* original e014, guest PC 0x0c0691de */
if(!s->budget--) { s->failed_pc=0x0c0691deu; return 0; }
r[0]=0x00000014u;
goto P_0c0691e0;
P_0c0691e0: /* original f5f6, guest PC 0x0c0691e0 */
if(!s->budget--) { s->failed_pc=0x0c0691e0u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0691e2;
P_0c0691e2: /* original e018, guest PC 0x0c0691e2 */
if(!s->budget--) { s->failed_pc=0x0c0691e2u; return 0; }
r[0]=0x00000018u;
goto P_0c0691e4;
P_0c0691e4: /* original f4f6, guest PC 0x0c0691e4 */
if(!s->budget--) { s->failed_pc=0x0c0691e4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0691e6;
P_0c0691e6: /* original befd, guest PC 0x0c0691e6 */
if(!s->budget--) { s->failed_pc=0x0c0691e6u; return 0; }
target=0x0c068fe4u; r[16]=0x0c0691eau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0691eau) { target=s->pc; goto dispatch; }
goto P_0c0691ea;
P_0c0691e8: /* original 64e3, guest PC 0x0c0691e8 */
if(!s->budget--) { s->failed_pc=0x0c0691e8u; return 0; }
r[4]=r[14];
goto P_0c0691ea;
P_0c0691ea: /* original 6403, guest PC 0x0c0691ea */
if(!s->budget--) { s->failed_pc=0x0c0691eau; return 0; }
r[4]=r[0];
goto P_0c0691ec;
P_0c0691ec: /* original 2448, guest PC 0x0c0691ec */
if(!s->budget--) { s->failed_pc=0x0c0691ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0691ee;
P_0c0691ee: /* original 8914, guest PC 0x0c0691ee */
if(!s->budget--) { s->failed_pc=0x0c0691eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06921a; }
goto P_0c0691f0;
P_0c0691f0: /* original 63b2, guest PC 0x0c0691f0 */
if(!s->budget--) { s->failed_pc=0x0c0691f0u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c0691f2;
P_0c0691f2: /* original e014, guest PC 0x0c0691f2 */
if(!s->budget--) { s->failed_pc=0x0c0691f2u; return 0; }
r[0]=0x00000014u;
goto P_0c0691f4;
P_0c0691f4: /* original 54e1, guest PC 0x0c0691f4 */
if(!s->budget--) { s->failed_pc=0x0c0691f4u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0691f6;
P_0c0691f6: /* original d510, guest PC 0x0c0691f6 */
if(!s->budget--) { s->failed_pc=0x0c0691f6u; return 0; }
r[5]=read(ram,0x0c069238u,4);
goto P_0c0691f8;
P_0c0691f8: /* original 343c, guest PC 0x0c0691f8 */
if(!s->budget--) { s->failed_pc=0x0c0691f8u; return 0; }
r[4]+=r[3];
goto P_0c0691fa;
P_0c0691fa: /* original f446, guest PC 0x0c0691fa */
if(!s->budget--) { s->failed_pc=0x0c0691fau; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0691fc;
P_0c0691fc: /* original e018, guest PC 0x0c0691fc */
if(!s->budget--) { s->failed_pc=0x0c0691fcu; return 0; }
r[0]=0x00000018u;
goto P_0c0691fe;
P_0c0691fe: /* original f546, guest PC 0x0c0691fe */
if(!s->budget--) { s->failed_pc=0x0c0691feu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c069200;
P_0c069200: /* original e01c, guest PC 0x0c069200 */
if(!s->budget--) { s->failed_pc=0x0c069200u; return 0; }
r[0]=0x0000001cu;
goto P_0c069202;
P_0c069202: /* original f646, guest PC 0x0c069202 */
if(!s->budget--) { s->failed_pc=0x0c069202u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c069204;
P_0c069204: /* original e00c, guest PC 0x0c069204 */
if(!s->budget--) { s->failed_pc=0x0c069204u; return 0; }
r[0]=0x0000000cu;
goto P_0c069206;
P_0c069206: /* original 6442, guest PC 0x0c069206 */
if(!s->budget--) { s->failed_pc=0x0c069206u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c069208;
P_0c069208: /* original ff47, guest PC 0x0c069208 */
if(!s->budget--) { s->failed_pc=0x0c069208u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c06920a;
P_0c06920a: /* original e010, guest PC 0x0c06920a */
if(!s->budget--) { s->failed_pc=0x0c06920au; return 0; }
r[0]=0x00000010u;
goto P_0c06920c;
P_0c06920c: /* original 4400, guest PC 0x0c06920c */
if(!s->budget--) { s->failed_pc=0x0c06920cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06920e;
P_0c06920e: /* original ff57, guest PC 0x0c06920e */
if(!s->budget--) { s->failed_pc=0x0c06920eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c069210;
P_0c069210: /* original 2459, guest PC 0x0c069210 */
if(!s->budget--) { s->failed_pc=0x0c069210u; return 0; }
r[4]&=r[5];
goto P_0c069212;
P_0c069212: /* original e008, guest PC 0x0c069212 */
if(!s->budget--) { s->failed_pc=0x0c069212u; return 0; }
r[0]=0x00000008u;
goto P_0c069214;
P_0c069214: /* original 6e43, guest PC 0x0c069214 */
if(!s->budget--) { s->failed_pc=0x0c069214u; return 0; }
r[14]=r[4];
goto P_0c069216;
P_0c069216: /* original a01a, guest PC 0x0c069216 */
if(!s->budget--) { s->failed_pc=0x0c069216u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c06924e;
P_0c069218: /* original ff67, guest PC 0x0c069218 */
if(!s->budget--) { s->failed_pc=0x0c069218u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c06921a;
P_0c06921a: /* original afdd, guest PC 0x0c06921a */
if(!s->budget--) { s->failed_pc=0x0c06921au; return 0; }
r[14]+=0x00000008u;
goto P_0c0691d8;
P_0c06921c: /* original 7e08, guest PC 0x0c06921c */
if(!s->budget--) { s->failed_pc=0x0c06921cu; return 0; }
r[14]+=0x00000008u;
return vf3_matrix_family(0x0c06921eu,s,ram);
P_0c06923c: /* original ee02, guest PC 0x0c06923c */
if(!s->budget--) { s->failed_pc=0x0c06923cu; return 0; }
r[14]=0x00000002u;
goto P_0c06923e;
P_0c06923e: /* original e010, guest PC 0x0c06923e */
if(!s->budget--) { s->failed_pc=0x0c06923eu; return 0; }
r[0]=0x00000010u;
goto P_0c069240;
P_0c069240: /* original f39d, guest PC 0x0c069240 */
if(!s->budget--) { s->failed_pc=0x0c069240u; return 0; }
fr[3]=0x3f800000u;
goto P_0c069242;
P_0c069242: /* original ff37, guest PC 0x0c069242 */
if(!s->budget--) { s->failed_pc=0x0c069242u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069244;
P_0c069244: /* original e008, guest PC 0x0c069244 */
if(!s->budget--) { s->failed_pc=0x0c069244u; return 0; }
r[0]=0x00000008u;
goto P_0c069246;
P_0c069246: /* original f38d, guest PC 0x0c069246 */
if(!s->budget--) { s->failed_pc=0x0c069246u; return 0; }
fr[3]=0;
goto P_0c069248;
P_0c069248: /* original ff37, guest PC 0x0c069248 */
if(!s->budget--) { s->failed_pc=0x0c069248u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06924a;
P_0c06924a: /* original e00c, guest PC 0x0c06924a */
if(!s->budget--) { s->failed_pc=0x0c06924au; return 0; }
r[0]=0x0000000cu;
goto P_0c06924c;
P_0c06924c: /* original ff37, guest PC 0x0c06924c */
if(!s->budget--) { s->failed_pc=0x0c06924cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06924e;
P_0c06924e: /* original 60c3, guest PC 0x0c06924e */
if(!s->budget--) { s->failed_pc=0x0c06924eu; return 0; }
r[0]=r[12];
goto P_0c069250;
P_0c069250: /* original 880d, guest PC 0x0c069250 */
if(!s->budget--) { s->failed_pc=0x0c069250u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c069252;
P_0c069252: /* original 8b02, guest PC 0x0c069252 */
if(!s->budget--) { s->failed_pc=0x0c069252u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06925a; }
goto P_0c069254;
P_0c069254: /* original e204, guest PC 0x0c069254 */
if(!s->budget--) { s->failed_pc=0x0c069254u; return 0; }
r[2]=0x00000004u;
goto P_0c069256;
P_0c069256: /* original a013, guest PC 0x0c069256 */
if(!s->budget--) { s->failed_pc=0x0c069256u; return 0; }
r[14]|=r[2];
goto P_0c069280;
P_0c069258: /* original 2e2b, guest PC 0x0c069258 */
if(!s->budget--) { s->failed_pc=0x0c069258u; return 0; }
r[14]|=r[2];
goto P_0c06925a;
P_0c06925a: /* original 880b, guest PC 0x0c06925a */
if(!s->budget--) { s->failed_pc=0x0c06925au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c06925c;
P_0c06925c: /* original 8b10, guest PC 0x0c06925c */
if(!s->budget--) { s->failed_pc=0x0c06925cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069280; }
goto P_0c06925e;
P_0c06925e: /* original 63f3, guest PC 0x0c06925e */
if(!s->budget--) { s->failed_pc=0x0c06925eu; return 0; }
r[3]=r[15];
goto P_0c069260;
P_0c069260: /* original 7308, guest PC 0x0c069260 */
if(!s->budget--) { s->failed_pc=0x0c069260u; return 0; }
r[3]+=0x00000008u;
goto P_0c069262;
P_0c069262: /* original 2f36, guest PC 0x0c069262 */
if(!s->budget--) { s->failed_pc=0x0c069262u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c069264;
P_0c069264: /* original 62f3, guest PC 0x0c069264 */
if(!s->budget--) { s->failed_pc=0x0c069264u; return 0; }
r[2]=r[15];
goto P_0c069266;
P_0c069266: /* original 7214, guest PC 0x0c069266 */
if(!s->budget--) { s->failed_pc=0x0c069266u; return 0; }
r[2]+=0x00000014u;
goto P_0c069268;
P_0c069268: /* original 2f26, guest PC 0x0c069268 */
if(!s->budget--) { s->failed_pc=0x0c069268u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c06926a;
P_0c06926a: /* original 65f3, guest PC 0x0c06926a */
if(!s->budget--) { s->failed_pc=0x0c06926au; return 0; }
r[5]=r[15];
goto P_0c06926c;
P_0c06926c: /* original d344, guest PC 0x0c06926c */
if(!s->budget--) { s->failed_pc=0x0c06926cu; return 0; }
r[3]=read(ram,0x0c069380u,4);
goto P_0c06926e;
P_0c06926e: /* original 66f3, guest PC 0x0c06926e */
if(!s->budget--) { s->failed_pc=0x0c06926eu; return 0; }
r[6]=r[15];
goto P_0c069270;
P_0c069270: /* original 67f3, guest PC 0x0c069270 */
if(!s->budget--) { s->failed_pc=0x0c069270u; return 0; }
r[7]=r[15];
goto P_0c069272;
P_0c069272: /* original 64f3, guest PC 0x0c069272 */
if(!s->budget--) { s->failed_pc=0x0c069272u; return 0; }
r[4]=r[15];
goto P_0c069274;
P_0c069274: /* original 7524, guest PC 0x0c069274 */
if(!s->budget--) { s->failed_pc=0x0c069274u; return 0; }
r[5]+=0x00000024u;
goto P_0c069276;
P_0c069276: /* original 761c, guest PC 0x0c069276 */
if(!s->budget--) { s->failed_pc=0x0c069276u; return 0; }
r[6]+=0x0000001cu;
goto P_0c069278;
P_0c069278: /* original 7714, guest PC 0x0c069278 */
if(!s->budget--) { s->failed_pc=0x0c069278u; return 0; }
r[7]+=0x00000014u;
goto P_0c06927a;
P_0c06927a: /* original 430b, guest PC 0x0c06927a */
if(!s->budget--) { s->failed_pc=0x0c06927au; return 0; }
target=r[3];
r[16]=0x0c06927eu;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06927eu) { target=s->pc; goto dispatch; }
goto P_0c06927e;
P_0c06927c: /* original 7420, guest PC 0x0c06927c */
if(!s->budget--) { s->failed_pc=0x0c06927cu; return 0; }
r[4]+=0x00000020u;
goto P_0c06927e;
P_0c06927e: /* original 7f08, guest PC 0x0c06927e */
if(!s->budget--) { s->failed_pc=0x0c06927eu; return 0; }
r[15]+=0x00000008u;
goto P_0c069280;
P_0c069280: /* original e00c, guest PC 0x0c069280 */
if(!s->budget--) { s->failed_pc=0x0c069280u; return 0; }
r[0]=0x0000000cu;
goto P_0c069282;
P_0c069282: /* original f3f6, guest PC 0x0c069282 */
if(!s->budget--) { s->failed_pc=0x0c069282u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069284;
P_0c069284: /* original e010, guest PC 0x0c069284 */
if(!s->budget--) { s->failed_pc=0x0c069284u; return 0; }
r[0]=0x00000010u;
goto P_0c069286;
P_0c069286: /* original fd3a, guest PC 0x0c069286 */
if(!s->budget--) { s->failed_pc=0x0c069286u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c069288;
P_0c069288: /* original f3f6, guest PC 0x0c069288 */
if(!s->budget--) { s->failed_pc=0x0c069288u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06928a;
P_0c06928a: /* original e004, guest PC 0x0c06928a */
if(!s->budget--) { s->failed_pc=0x0c06928au; return 0; }
r[0]=0x00000004u;
goto P_0c06928c;
P_0c06928c: /* original fd37, guest PC 0x0c06928c */
if(!s->budget--) { s->failed_pc=0x0c06928cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c06928e;
P_0c06928e: /* original e008, guest PC 0x0c06928e */
if(!s->budget--) { s->failed_pc=0x0c06928eu; return 0; }
r[0]=0x00000008u;
goto P_0c069290;
P_0c069290: /* original f3f6, guest PC 0x0c069290 */
if(!s->budget--) { s->failed_pc=0x0c069290u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069292;
P_0c069292: /* original e008, guest PC 0x0c069292 */
if(!s->budget--) { s->failed_pc=0x0c069292u; return 0; }
r[0]=0x00000008u;
goto P_0c069294;
P_0c069294: /* original fd37, guest PC 0x0c069294 */
if(!s->budget--) { s->failed_pc=0x0c069294u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c069296;
P_0c069296: /* original 60e3, guest PC 0x0c069296 */
if(!s->budget--) { s->failed_pc=0x0c069296u; return 0; }
r[0]=r[14];
goto P_0c069298;
P_0c069298: /* original 7f20, guest PC 0x0c069298 */
if(!s->budget--) { s->failed_pc=0x0c069298u; return 0; }
r[15]+=0x00000020u;
goto P_0c06929a;
P_0c06929a: /* original 4f26, guest PC 0x0c06929a */
if(!s->budget--) { s->failed_pc=0x0c06929au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06929c;
P_0c06929c: /* original 6bf6, guest PC 0x0c06929c */
if(!s->budget--) { s->failed_pc=0x0c06929cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06929e;
P_0c06929e: /* original 6cf6, guest PC 0x0c06929e */
if(!s->budget--) { s->failed_pc=0x0c06929eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0692a0;
P_0c0692a0: /* original 6df6, guest PC 0x0c0692a0 */
if(!s->budget--) { s->failed_pc=0x0c0692a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0692a2;
P_0c0692a2: /* original 000b, guest PC 0x0c0692a2 */
if(!s->budget--) { s->failed_pc=0x0c0692a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0692a4: /* original 6ef6, guest PC 0x0c0692a4 */
if(!s->budget--) { s->failed_pc=0x0c0692a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0692a6u,s,ram);
P_0c06f6ae: /* original c70a, guest PC 0x0c06f6ae */
if(!s->budget--) { s->failed_pc=0x0c06f6aeu; return 0; }
r[0]=0x0c06f6d8u;
goto P_0c06f6b0;
P_0c06f6b0: /* original f308, guest PC 0x0c06f6b0 */
if(!s->budget--) { s->failed_pc=0x0c06f6b0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06f6b2;
P_0c06f6b2: /* original fd30, guest PC 0x0c06f6b2 */
if(!s->budget--) { s->failed_pc=0x0c06f6b2u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c06f6b4;
P_0c06f6b4: /* original fdc5, guest PC 0x0c06f6b4 */
if(!s->budget--) { s->failed_pc=0x0c06f6b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[12]))!=0);
goto P_0c06f6b6;
P_0c06f6b6: /* original 8f01, guest PC 0x0c06f6b6 */
if(!s->budget--) { s->failed_pc=0x0c06f6b6u; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c06f6bc; }
goto P_0c06f6ba;
P_0c06f6b8: /* original e900, guest PC 0x0c06f6b8 */
if(!s->budget--) { s->failed_pc=0x0c06f6b8u; return 0; }
r[9]=0x00000000u;
goto P_0c06f6ba;
P_0c06f6ba: /* original fdcc, guest PC 0x0c06f6ba */
if(!s->budget--) { s->failed_pc=0x0c06f6bau; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c06f6bc;
P_0c06f6bc: /* original 4a15, guest PC 0x0c06f6bc */
if(!s->budget--) { s->failed_pc=0x0c06f6bcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c06f6be;
P_0c06f6be: /* original 8902, guest PC 0x0c06f6be */
if(!s->budget--) { s->failed_pc=0x0c06f6beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f6c6; }
goto P_0c06f6c0;
P_0c06f6c0: /* original d206, guest PC 0x0c06f6c0 */
if(!s->budget--) { s->failed_pc=0x0c06f6c0u; return 0; }
r[2]=read(ram,0x0c06f6dcu,4);
goto P_0c06f6c2;
P_0c06f6c2: /* original 422b, guest PC 0x0c06f6c2 */
if(!s->budget--) { s->failed_pc=0x0c06f6c2u; return 0; }
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
P_0c06f6c4: /* original 0009, guest PC 0x0c06f6c4 */
if(!s->budget--) { s->failed_pc=0x0c06f6c4u; return 0; }
goto P_0c06f6c6;
P_0c06f6c6: /* original 64f3, guest PC 0x0c06f6c6 */
if(!s->budget--) { s->failed_pc=0x0c06f6c6u; return 0; }
r[4]=r[15];
goto P_0c06f6c8;
P_0c06f6c8: /* original 7438, guest PC 0x0c06f6c8 */
if(!s->budget--) { s->failed_pc=0x0c06f6c8u; return 0; }
r[4]+=0x00000038u;
goto P_0c06f6ca;
P_0c06f6ca: /* original 66c3, guest PC 0x0c06f6ca */
if(!s->budget--) { s->failed_pc=0x0c06f6cau; return 0; }
r[6]=r[12];
goto P_0c06f6cc;
P_0c06f6cc: /* original 65d3, guest PC 0x0c06f6cc */
if(!s->budget--) { s->failed_pc=0x0c06f6ccu; return 0; }
r[5]=r[13];
goto P_0c06f6ce;
P_0c06f6ce: /* original a007, guest PC 0x0c06f6ce */
if(!s->budget--) { s->failed_pc=0x0c06f6ceu; return 0; }
goto P_0c06f6e0;
P_0c06f6d0: /* original 0009, guest PC 0x0c06f6d0 */
if(!s->budget--) { s->failed_pc=0x0c06f6d0u; return 0; }
return vf3_matrix_family(0x0c06f6d2u,s,ram);
P_0c06f6e0: /* original f059, guest PC 0x0c06f6e0 */
if(!s->budget--) { s->failed_pc=0x0c06f6e0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f6e2;
P_0c06f6e2: /* original f369, guest PC 0x0c06f6e2 */
if(!s->budget--) { s->failed_pc=0x0c06f6e2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f6e4;
P_0c06f6e4: /* original f159, guest PC 0x0c06f6e4 */
if(!s->budget--) { s->failed_pc=0x0c06f6e4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f6e6;
P_0c06f6e6: /* original f469, guest PC 0x0c06f6e6 */
if(!s->budget--) { s->failed_pc=0x0c06f6e6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f6e8;
P_0c06f6e8: /* original f031, guest PC 0x0c06f6e8 */
if(!s->budget--) { s->failed_pc=0x0c06f6e8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06f6ea;
P_0c06f6ea: /* original f258, guest PC 0x0c06f6ea */
if(!s->budget--) { s->failed_pc=0x0c06f6eau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c06f6ec;
P_0c06f6ec: /* original f568, guest PC 0x0c06f6ec */
if(!s->budget--) { s->failed_pc=0x0c06f6ecu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c06f6ee;
P_0c06f6ee: /* original f141, guest PC 0x0c06f6ee */
if(!s->budget--) { s->failed_pc=0x0c06f6eeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c06f6f0;
P_0c06f6f0: /* original f251, guest PC 0x0c06f6f0 */
if(!s->budget--) { s->failed_pc=0x0c06f6f0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c06f6f2;
P_0c06f6f2: /* original 7408, guest PC 0x0c06f6f2 */
if(!s->budget--) { s->failed_pc=0x0c06f6f2u; return 0; }
r[4]+=0x00000008u;
goto P_0c06f6f4;
P_0c06f6f4: /* original f42a, guest PC 0x0c06f6f4 */
if(!s->budget--) { s->failed_pc=0x0c06f6f4u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f6f6;
P_0c06f6f6: /* original f41b, guest PC 0x0c06f6f6 */
if(!s->budget--) { s->failed_pc=0x0c06f6f6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f6f8;
P_0c06f6f8: /* original f40b, guest PC 0x0c06f6f8 */
if(!s->budget--) { s->failed_pc=0x0c06f6f8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f6fa;
P_0c06f6fa: /* original 0009, guest PC 0x0c06f6fa */
if(!s->budget--) { s->failed_pc=0x0c06f6fau; return 0; }
goto P_0c06f6fc;
P_0c06f6fc: /* original 64f3, guest PC 0x0c06f6fc */
if(!s->budget--) { s->failed_pc=0x0c06f6fcu; return 0; }
r[4]=r[15];
goto P_0c06f6fe;
P_0c06f6fe: /* original 7438, guest PC 0x0c06f6fe */
if(!s->budget--) { s->failed_pc=0x0c06f6feu; return 0; }
r[4]+=0x00000038u;
goto P_0c06f700;
P_0c06f700: /* original f049, guest PC 0x0c06f700 */
if(!s->budget--) { s->failed_pc=0x0c06f700u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f702;
P_0c06f702: /* original f149, guest PC 0x0c06f702 */
if(!s->budget--) { s->failed_pc=0x0c06f702u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f704;
P_0c06f704: /* original f249, guest PC 0x0c06f704 */
if(!s->budget--) { s->failed_pc=0x0c06f704u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f706;
P_0c06f706: /* original f38d, guest PC 0x0c06f706 */
if(!s->budget--) { s->failed_pc=0x0c06f706u; return 0; }
fr[3]=0;
goto P_0c06f708;
P_0c06f708: /* original f0ed, guest PC 0x0c06f708 */
if(!s->budget--) { s->failed_pc=0x0c06f708u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f70a;
P_0c06f70a: /* original f03c, guest PC 0x0c06f70a */
if(!s->budget--) { s->failed_pc=0x0c06f70au; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c06f70c;
P_0c06f70c: /* original f06d, guest PC 0x0c06f70c */
if(!s->budget--) { s->failed_pc=0x0c06f70cu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c06f70e;
P_0c06f70e: /* original 0009, guest PC 0x0c06f70e */
if(!s->budget--) { s->failed_pc=0x0c06f70eu; return 0; }
goto P_0c06f710;
P_0c06f710: /* original c709, guest PC 0x0c06f710 */
if(!s->budget--) { s->failed_pc=0x0c06f710u; return 0; }
r[0]=0x0c06f738u;
goto P_0c06f712;
P_0c06f712: /* original f308, guest PC 0x0c06f712 */
if(!s->budget--) { s->failed_pc=0x0c06f712u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06f714;
P_0c06f714: /* original f305, guest PC 0x0c06f714 */
if(!s->budget--) { s->failed_pc=0x0c06f714u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[0]))!=0);
goto P_0c06f716;
P_0c06f716: /* original 8b07, guest PC 0x0c06f716 */
if(!s->budget--) { s->failed_pc=0x0c06f716u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f728; }
goto P_0c06f718;
P_0c06f718: /* original e038, guest PC 0x0c06f718 */
if(!s->budget--) { s->failed_pc=0x0c06f718u; return 0; }
r[0]=0x00000038u;
goto P_0c06f71a;
P_0c06f71a: /* original ffe7, guest PC 0x0c06f71a */
if(!s->budget--) { s->failed_pc=0x0c06f71au; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c06f71c;
P_0c06f71c: /* original e03c, guest PC 0x0c06f71c */
if(!s->budget--) { s->failed_pc=0x0c06f71cu; return 0; }
r[0]=0x0000003cu;
goto P_0c06f71e;
P_0c06f71e: /* original fff7, guest PC 0x0c06f71e */
if(!s->budget--) { s->failed_pc=0x0c06f71eu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f720;
P_0c06f720: /* original e040, guest PC 0x0c06f720 */
if(!s->budget--) { s->failed_pc=0x0c06f720u; return 0; }
r[0]=0x00000040u;
goto P_0c06f722;
P_0c06f722: /* original d306, guest PC 0x0c06f722 */
if(!s->budget--) { s->failed_pc=0x0c06f722u; return 0; }
r[3]=read(ram,0x0c06f73cu,4);
goto P_0c06f724;
P_0c06f724: /* original 432b, guest PC 0x0c06f724 */
if(!s->budget--) { s->failed_pc=0x0c06f724u; return 0; }
target=r[3];
vf3_matrix_store(s,ram,15,r[15]+r[0]);
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
P_0c06f726: /* original fff7, guest PC 0x0c06f726 */
if(!s->budget--) { s->failed_pc=0x0c06f726u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f728;
P_0c06f728: /* original 64f3, guest PC 0x0c06f728 */
if(!s->budget--) { s->failed_pc=0x0c06f728u; return 0; }
r[4]=r[15];
goto P_0c06f72a;
P_0c06f72a: /* original 65f3, guest PC 0x0c06f72a */
if(!s->budget--) { s->failed_pc=0x0c06f72au; return 0; }
r[5]=r[15];
goto P_0c06f72c;
P_0c06f72c: /* original 7438, guest PC 0x0c06f72c */
if(!s->budget--) { s->failed_pc=0x0c06f72cu; return 0; }
r[4]+=0x00000038u;
goto P_0c06f72e;
P_0c06f72e: /* original f4ec, guest PC 0x0c06f72e */
if(!s->budget--) { s->failed_pc=0x0c06f72eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06f730;
P_0c06f730: /* original 7538, guest PC 0x0c06f730 */
if(!s->budget--) { s->failed_pc=0x0c06f730u; return 0; }
r[5]+=0x00000038u;
goto P_0c06f732;
P_0c06f732: /* original a005, guest PC 0x0c06f732 */
if(!s->budget--) { s->failed_pc=0x0c06f732u; return 0; }
goto P_0c06f740;
P_0c06f734: /* original 0009, guest PC 0x0c06f734 */
if(!s->budget--) { s->failed_pc=0x0c06f734u; return 0; }
return vf3_matrix_family(0x0c06f736u,s,ram);
P_0c06f740: /* original f059, guest PC 0x0c06f740 */
if(!s->budget--) { s->failed_pc=0x0c06f740u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f742;
P_0c06f742: /* original f159, guest PC 0x0c06f742 */
if(!s->budget--) { s->failed_pc=0x0c06f742u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f744;
P_0c06f744: /* original f259, guest PC 0x0c06f744 */
if(!s->budget--) { s->failed_pc=0x0c06f744u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f746;
P_0c06f746: /* original f38d, guest PC 0x0c06f746 */
if(!s->budget--) { s->failed_pc=0x0c06f746u; return 0; }
fr[3]=0;
goto P_0c06f748;
P_0c06f748: /* original f0ed, guest PC 0x0c06f748 */
if(!s->budget--) { s->failed_pc=0x0c06f748u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f74a;
P_0c06f74a: /* original f37d, guest PC 0x0c06f74a */
if(!s->budget--) { s->failed_pc=0x0c06f74au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f74c;
P_0c06f74c: /* original f342, guest PC 0x0c06f74c */
if(!s->budget--) { s->failed_pc=0x0c06f74cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f74e;
P_0c06f74e: /* original 740c, guest PC 0x0c06f74e */
if(!s->budget--) { s->failed_pc=0x0c06f74eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f750;
P_0c06f750: /* original f232, guest PC 0x0c06f750 */
if(!s->budget--) { s->failed_pc=0x0c06f750u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f752;
P_0c06f752: /* original f132, guest PC 0x0c06f752 */
if(!s->budget--) { s->failed_pc=0x0c06f752u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f754;
P_0c06f754: /* original f032, guest PC 0x0c06f754 */
if(!s->budget--) { s->failed_pc=0x0c06f754u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f756;
P_0c06f756: /* original f42b, guest PC 0x0c06f756 */
if(!s->budget--) { s->failed_pc=0x0c06f756u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f758;
P_0c06f758: /* original f41b, guest PC 0x0c06f758 */
if(!s->budget--) { s->failed_pc=0x0c06f758u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f75a;
P_0c06f75a: /* original f40b, guest PC 0x0c06f75a */
if(!s->budget--) { s->failed_pc=0x0c06f75au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f75c;
P_0c06f75c: /* original 65f3, guest PC 0x0c06f75c */
if(!s->budget--) { s->failed_pc=0x0c06f75cu; return 0; }
r[5]=r[15];
goto P_0c06f75e;
P_0c06f75e: /* original 64d3, guest PC 0x0c06f75e */
if(!s->budget--) { s->failed_pc=0x0c06f75eu; return 0; }
r[4]=r[13];
goto P_0c06f760;
P_0c06f760: /* original 7538, guest PC 0x0c06f760 */
if(!s->budget--) { s->failed_pc=0x0c06f760u; return 0; }
r[5]+=0x00000038u;
goto P_0c06f762;
P_0c06f762: /* original 66c3, guest PC 0x0c06f762 */
if(!s->budget--) { s->failed_pc=0x0c06f762u; return 0; }
r[6]=r[12];
goto P_0c06f764;
P_0c06f764: /* original f059, guest PC 0x0c06f764 */
if(!s->budget--) { s->failed_pc=0x0c06f764u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f766;
P_0c06f766: /* original f369, guest PC 0x0c06f766 */
if(!s->budget--) { s->failed_pc=0x0c06f766u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f768;
P_0c06f768: /* original f159, guest PC 0x0c06f768 */
if(!s->budget--) { s->failed_pc=0x0c06f768u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f76a;
P_0c06f76a: /* original f469, guest PC 0x0c06f76a */
if(!s->budget--) { s->failed_pc=0x0c06f76au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f76c;
P_0c06f76c: /* original f259, guest PC 0x0c06f76c */
if(!s->budget--) { s->failed_pc=0x0c06f76cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f76e;
P_0c06f76e: /* original f569, guest PC 0x0c06f76e */
if(!s->budget--) { s->failed_pc=0x0c06f76eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f770;
P_0c06f770: /* original 740c, guest PC 0x0c06f770 */
if(!s->budget--) { s->failed_pc=0x0c06f770u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f772;
P_0c06f772: /* original f030, guest PC 0x0c06f772 */
if(!s->budget--) { s->failed_pc=0x0c06f772u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f774;
P_0c06f774: /* original f250, guest PC 0x0c06f774 */
if(!s->budget--) { s->failed_pc=0x0c06f774u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f776;
P_0c06f776: /* original f140, guest PC 0x0c06f776 */
if(!s->budget--) { s->failed_pc=0x0c06f776u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f778;
P_0c06f778: /* original f42b, guest PC 0x0c06f778 */
if(!s->budget--) { s->failed_pc=0x0c06f778u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f77a;
P_0c06f77a: /* original f41b, guest PC 0x0c06f77a */
if(!s->budget--) { s->failed_pc=0x0c06f77au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f77c;
P_0c06f77c: /* original f40b, guest PC 0x0c06f77c */
if(!s->budget--) { s->failed_pc=0x0c06f77cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f77e;
P_0c06f77e: /* original 0009, guest PC 0x0c06f77e */
if(!s->budget--) { s->failed_pc=0x0c06f77eu; return 0; }
goto P_0c06f780;
P_0c06f780: /* original 65f3, guest PC 0x0c06f780 */
if(!s->budget--) { s->failed_pc=0x0c06f780u; return 0; }
r[5]=r[15];
goto P_0c06f782;
P_0c06f782: /* original 64d3, guest PC 0x0c06f782 */
if(!s->budget--) { s->failed_pc=0x0c06f782u; return 0; }
r[4]=r[13];
goto P_0c06f784;
P_0c06f784: /* original 7550, guest PC 0x0c06f784 */
if(!s->budget--) { s->failed_pc=0x0c06f784u; return 0; }
r[5]+=0x00000050u;
goto P_0c06f786;
P_0c06f786: /* original f449, guest PC 0x0c06f786 */
if(!s->budget--) { s->failed_pc=0x0c06f786u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f788;
P_0c06f788: /* original f549, guest PC 0x0c06f788 */
if(!s->budget--) { s->failed_pc=0x0c06f788u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f78a;
P_0c06f78a: /* original f648, guest PC 0x0c06f78a */
if(!s->budget--) { s->failed_pc=0x0c06f78au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c06f78c;
P_0c06f78c: /* original f79d, guest PC 0x0c06f78c */
if(!s->budget--) { s->failed_pc=0x0c06f78cu; return 0; }
fr[7]=0x3f800000u;
goto P_0c06f78e;
P_0c06f78e: /* original f5fd, guest PC 0x0c06f78e */
if(!s->budget--) { s->failed_pc=0x0c06f78eu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06f790;
P_0c06f790: /* original 750c, guest PC 0x0c06f790 */
if(!s->budget--) { s->failed_pc=0x0c06f790u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f792;
P_0c06f792: /* original f56b, guest PC 0x0c06f792 */
if(!s->budget--) { s->failed_pc=0x0c06f792u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06f794;
P_0c06f794: /* original f55b, guest PC 0x0c06f794 */
if(!s->budget--) { s->failed_pc=0x0c06f794u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06f796;
P_0c06f796: /* original f54b, guest PC 0x0c06f796 */
if(!s->budget--) { s->failed_pc=0x0c06f796u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06f798;
P_0c06f798: /* original 64f3, guest PC 0x0c06f798 */
if(!s->budget--) { s->failed_pc=0x0c06f798u; return 0; }
r[4]=r[15];
goto P_0c06f79a;
P_0c06f79a: /* original 65f3, guest PC 0x0c06f79a */
if(!s->budget--) { s->failed_pc=0x0c06f79au; return 0; }
r[5]=r[15];
goto P_0c06f79c;
P_0c06f79c: /* original 745c, guest PC 0x0c06f79c */
if(!s->budget--) { s->failed_pc=0x0c06f79cu; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f79e;
P_0c06f79e: /* original 66d3, guest PC 0x0c06f79e */
if(!s->budget--) { s->failed_pc=0x0c06f79eu; return 0; }
r[6]=r[13];
goto P_0c06f7a0;
P_0c06f7a0: /* original 7550, guest PC 0x0c06f7a0 */
if(!s->budget--) { s->failed_pc=0x0c06f7a0u; return 0; }
r[5]+=0x00000050u;
goto P_0c06f7a2;
P_0c06f7a2: /* original f059, guest PC 0x0c06f7a2 */
if(!s->budget--) { s->failed_pc=0x0c06f7a2u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a4;
P_0c06f7a4: /* original f369, guest PC 0x0c06f7a4 */
if(!s->budget--) { s->failed_pc=0x0c06f7a4u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a6;
P_0c06f7a6: /* original f159, guest PC 0x0c06f7a6 */
if(!s->budget--) { s->failed_pc=0x0c06f7a6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a8;
P_0c06f7a8: /* original f469, guest PC 0x0c06f7a8 */
if(!s->budget--) { s->failed_pc=0x0c06f7a8u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7aa;
P_0c06f7aa: /* original f031, guest PC 0x0c06f7aa */
if(!s->budget--) { s->failed_pc=0x0c06f7aau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06f7ac;
P_0c06f7ac: /* original f258, guest PC 0x0c06f7ac */
if(!s->budget--) { s->failed_pc=0x0c06f7acu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c06f7ae;
P_0c06f7ae: /* original f568, guest PC 0x0c06f7ae */
if(!s->budget--) { s->failed_pc=0x0c06f7aeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c06f7b0;
P_0c06f7b0: /* original f141, guest PC 0x0c06f7b0 */
if(!s->budget--) { s->failed_pc=0x0c06f7b0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c06f7b2;
P_0c06f7b2: /* original f251, guest PC 0x0c06f7b2 */
if(!s->budget--) { s->failed_pc=0x0c06f7b2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c06f7b4;
P_0c06f7b4: /* original 7408, guest PC 0x0c06f7b4 */
if(!s->budget--) { s->failed_pc=0x0c06f7b4u; return 0; }
r[4]+=0x00000008u;
goto P_0c06f7b6;
P_0c06f7b6: /* original f42a, guest PC 0x0c06f7b6 */
if(!s->budget--) { s->failed_pc=0x0c06f7b6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f7b8;
P_0c06f7b8: /* original f41b, guest PC 0x0c06f7b8 */
if(!s->budget--) { s->failed_pc=0x0c06f7b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f7ba;
P_0c06f7ba: /* original f40b, guest PC 0x0c06f7ba */
if(!s->budget--) { s->failed_pc=0x0c06f7bau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f7bc;
P_0c06f7bc: /* original 64f3, guest PC 0x0c06f7bc */
if(!s->budget--) { s->failed_pc=0x0c06f7bcu; return 0; }
r[4]=r[15];
goto P_0c06f7be;
P_0c06f7be: /* original 65f3, guest PC 0x0c06f7be */
if(!s->budget--) { s->failed_pc=0x0c06f7beu; return 0; }
r[5]=r[15];
goto P_0c06f7c0;
P_0c06f7c0: /* original 745c, guest PC 0x0c06f7c0 */
if(!s->budget--) { s->failed_pc=0x0c06f7c0u; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f7c2;
P_0c06f7c2: /* original f4dc, guest PC 0x0c06f7c2 */
if(!s->budget--) { s->failed_pc=0x0c06f7c2u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06f7c4;
P_0c06f7c4: /* original 755c, guest PC 0x0c06f7c4 */
if(!s->budget--) { s->failed_pc=0x0c06f7c4u; return 0; }
r[5]+=0x0000005cu;
goto P_0c06f7c6;
P_0c06f7c6: /* original f059, guest PC 0x0c06f7c6 */
if(!s->budget--) { s->failed_pc=0x0c06f7c6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7c8;
P_0c06f7c8: /* original f159, guest PC 0x0c06f7c8 */
if(!s->budget--) { s->failed_pc=0x0c06f7c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7ca;
P_0c06f7ca: /* original f259, guest PC 0x0c06f7ca */
if(!s->budget--) { s->failed_pc=0x0c06f7cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7cc;
P_0c06f7cc: /* original 740c, guest PC 0x0c06f7cc */
if(!s->budget--) { s->failed_pc=0x0c06f7ccu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f7ce;
P_0c06f7ce: /* original f242, guest PC 0x0c06f7ce */
if(!s->budget--) { s->failed_pc=0x0c06f7ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c06f7d0;
P_0c06f7d0: /* original f142, guest PC 0x0c06f7d0 */
if(!s->budget--) { s->failed_pc=0x0c06f7d0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c06f7d2;
P_0c06f7d2: /* original f042, guest PC 0x0c06f7d2 */
if(!s->budget--) { s->failed_pc=0x0c06f7d2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c06f7d4;
P_0c06f7d4: /* original f42b, guest PC 0x0c06f7d4 */
if(!s->budget--) { s->failed_pc=0x0c06f7d4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f7d6;
P_0c06f7d6: /* original f41b, guest PC 0x0c06f7d6 */
if(!s->budget--) { s->failed_pc=0x0c06f7d6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f7d8;
P_0c06f7d8: /* original f40b, guest PC 0x0c06f7d8 */
if(!s->budget--) { s->failed_pc=0x0c06f7d8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f7da;
P_0c06f7da: /* original 0009, guest PC 0x0c06f7da */
if(!s->budget--) { s->failed_pc=0x0c06f7dau; return 0; }
goto P_0c06f7dc;
P_0c06f7dc: /* original 64f3, guest PC 0x0c06f7dc */
if(!s->budget--) { s->failed_pc=0x0c06f7dcu; return 0; }
r[4]=r[15];
goto P_0c06f7de;
P_0c06f7de: /* original 745c, guest PC 0x0c06f7de */
if(!s->budget--) { s->failed_pc=0x0c06f7deu; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f7e0;
P_0c06f7e0: /* original f049, guest PC 0x0c06f7e0 */
if(!s->budget--) { s->failed_pc=0x0c06f7e0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e2;
P_0c06f7e2: /* original f149, guest PC 0x0c06f7e2 */
if(!s->budget--) { s->failed_pc=0x0c06f7e2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e4;
P_0c06f7e4: /* original f249, guest PC 0x0c06f7e4 */
if(!s->budget--) { s->failed_pc=0x0c06f7e4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e6;
P_0c06f7e6: /* original f38d, guest PC 0x0c06f7e6 */
if(!s->budget--) { s->failed_pc=0x0c06f7e6u; return 0; }
fr[3]=0;
goto P_0c06f7e8;
P_0c06f7e8: /* original f0ed, guest PC 0x0c06f7e8 */
if(!s->budget--) { s->failed_pc=0x0c06f7e8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f7ea;
P_0c06f7ea: /* original f03c, guest PC 0x0c06f7ea */
if(!s->budget--) { s->failed_pc=0x0c06f7eau; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c06f7ec;
P_0c06f7ec: /* original f06d, guest PC 0x0c06f7ec */
if(!s->budget--) { s->failed_pc=0x0c06f7ecu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c06f7ee;
P_0c06f7ee: /* original 0009, guest PC 0x0c06f7ee */
if(!s->budget--) { s->failed_pc=0x0c06f7eeu; return 0; }
goto P_0c06f7f0;
P_0c06f7f0: /* original 65f3, guest PC 0x0c06f7f0 */
if(!s->budget--) { s->failed_pc=0x0c06f7f0u; return 0; }
r[5]=r[15];
goto P_0c06f7f2;
P_0c06f7f2: /* original 64f3, guest PC 0x0c06f7f2 */
if(!s->budget--) { s->failed_pc=0x0c06f7f2u; return 0; }
r[4]=r[15];
goto P_0c06f7f4;
P_0c06f7f4: /* original 66f3, guest PC 0x0c06f7f4 */
if(!s->budget--) { s->failed_pc=0x0c06f7f4u; return 0; }
r[6]=r[15];
goto P_0c06f7f6;
P_0c06f7f6: /* original 7444, guest PC 0x0c06f7f6 */
if(!s->budget--) { s->failed_pc=0x0c06f7f6u; return 0; }
r[4]+=0x00000044u;
goto P_0c06f7f8;
P_0c06f7f8: /* original 7668, guest PC 0x0c06f7f8 */
if(!s->budget--) { s->failed_pc=0x0c06f7f8u; return 0; }
r[6]+=0x00000068u;
goto P_0c06f7fa;
P_0c06f7fa: /* original 755c, guest PC 0x0c06f7fa */
if(!s->budget--) { s->failed_pc=0x0c06f7fau; return 0; }
r[5]+=0x0000005cu;
goto P_0c06f7fc;
P_0c06f7fc: /* original f059, guest PC 0x0c06f7fc */
if(!s->budget--) { s->failed_pc=0x0c06f7fcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7fe;
P_0c06f7fe: /* original f369, guest PC 0x0c06f7fe */
if(!s->budget--) { s->failed_pc=0x0c06f7feu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f800;
P_0c06f800: /* original f159, guest PC 0x0c06f800 */
if(!s->budget--) { s->failed_pc=0x0c06f800u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f802;
P_0c06f802: /* original f469, guest PC 0x0c06f802 */
if(!s->budget--) { s->failed_pc=0x0c06f802u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f804;
P_0c06f804: /* original f259, guest PC 0x0c06f804 */
if(!s->budget--) { s->failed_pc=0x0c06f804u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f806;
P_0c06f806: /* original f569, guest PC 0x0c06f806 */
if(!s->budget--) { s->failed_pc=0x0c06f806u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f808;
P_0c06f808: /* original 740c, guest PC 0x0c06f808 */
if(!s->budget--) { s->failed_pc=0x0c06f808u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f80a;
P_0c06f80a: /* original f030, guest PC 0x0c06f80a */
if(!s->budget--) { s->failed_pc=0x0c06f80au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f80c;
P_0c06f80c: /* original f250, guest PC 0x0c06f80c */
if(!s->budget--) { s->failed_pc=0x0c06f80cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f80e;
P_0c06f80e: /* original f140, guest PC 0x0c06f80e */
if(!s->budget--) { s->failed_pc=0x0c06f80eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f810;
P_0c06f810: /* original f42b, guest PC 0x0c06f810 */
if(!s->budget--) { s->failed_pc=0x0c06f810u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f812;
P_0c06f812: /* original f41b, guest PC 0x0c06f812 */
if(!s->budget--) { s->failed_pc=0x0c06f812u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f814;
P_0c06f814: /* original f40b, guest PC 0x0c06f814 */
if(!s->budget--) { s->failed_pc=0x0c06f814u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f816;
P_0c06f816: /* original 0009, guest PC 0x0c06f816 */
if(!s->budget--) { s->failed_pc=0x0c06f816u; return 0; }
goto P_0c06f818;
P_0c06f818: /* original e038, guest PC 0x0c06f818 */
if(!s->budget--) { s->failed_pc=0x0c06f818u; return 0; }
r[0]=0x00000038u;
goto P_0c06f81a;
P_0c06f81a: /* original 65f3, guest PC 0x0c06f81a */
if(!s->budget--) { s->failed_pc=0x0c06f81au; return 0; }
r[5]=r[15];
goto P_0c06f81c;
P_0c06f81c: /* original f3f6, guest PC 0x0c06f81c */
if(!s->budget--) { s->failed_pc=0x0c06f81cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f81e;
P_0c06f81e: /* original e02c, guest PC 0x0c06f81e */
if(!s->budget--) { s->failed_pc=0x0c06f81eu; return 0; }
r[0]=0x0000002cu;
goto P_0c06f820;
P_0c06f820: /* original 64f3, guest PC 0x0c06f820 */
if(!s->budget--) { s->failed_pc=0x0c06f820u; return 0; }
r[4]=r[15];
goto P_0c06f822;
P_0c06f822: /* original 742c, guest PC 0x0c06f822 */
if(!s->budget--) { s->failed_pc=0x0c06f822u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f824;
P_0c06f824: /* original ff37, guest PC 0x0c06f824 */
if(!s->budget--) { s->failed_pc=0x0c06f824u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f826;
P_0c06f826: /* original e03c, guest PC 0x0c06f826 */
if(!s->budget--) { s->failed_pc=0x0c06f826u; return 0; }
r[0]=0x0000003cu;
goto P_0c06f828;
P_0c06f828: /* original f3f6, guest PC 0x0c06f828 */
if(!s->budget--) { s->failed_pc=0x0c06f828u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f82a;
P_0c06f82a: /* original e030, guest PC 0x0c06f82a */
if(!s->budget--) { s->failed_pc=0x0c06f82au; return 0; }
r[0]=0x00000030u;
goto P_0c06f82c;
P_0c06f82c: /* original 7544, guest PC 0x0c06f82c */
if(!s->budget--) { s->failed_pc=0x0c06f82cu; return 0; }
r[5]+=0x00000044u;
goto P_0c06f82e;
P_0c06f82e: /* original ff37, guest PC 0x0c06f82e */
if(!s->budget--) { s->failed_pc=0x0c06f82eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f830;
P_0c06f830: /* original e040, guest PC 0x0c06f830 */
if(!s->budget--) { s->failed_pc=0x0c06f830u; return 0; }
r[0]=0x00000040u;
goto P_0c06f832;
P_0c06f832: /* original f3f6, guest PC 0x0c06f832 */
if(!s->budget--) { s->failed_pc=0x0c06f832u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f834;
P_0c06f834: /* original e034, guest PC 0x0c06f834 */
if(!s->budget--) { s->failed_pc=0x0c06f834u; return 0; }
r[0]=0x00000034u;
goto P_0c06f836;
P_0c06f836: /* original ff37, guest PC 0x0c06f836 */
if(!s->budget--) { s->failed_pc=0x0c06f836u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f838;
P_0c06f838: /* original f049, guest PC 0x0c06f838 */
if(!s->budget--) { s->failed_pc=0x0c06f838u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83a;
P_0c06f83a: /* original f149, guest PC 0x0c06f83a */
if(!s->budget--) { s->failed_pc=0x0c06f83au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83c;
P_0c06f83c: /* original f249, guest PC 0x0c06f83c */
if(!s->budget--) { s->failed_pc=0x0c06f83cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83e;
P_0c06f83e: /* original f38d, guest PC 0x0c06f83e */
if(!s->budget--) { s->failed_pc=0x0c06f83eu; return 0; }
fr[3]=0;
goto P_0c06f840;
P_0c06f840: /* original f459, guest PC 0x0c06f840 */
if(!s->budget--) { s->failed_pc=0x0c06f840u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f842;
P_0c06f842: /* original f559, guest PC 0x0c06f842 */
if(!s->budget--) { s->failed_pc=0x0c06f842u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f844;
P_0c06f844: /* original f659, guest PC 0x0c06f844 */
if(!s->budget--) { s->failed_pc=0x0c06f844u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f846;
P_0c06f846: /* original f78d, guest PC 0x0c06f846 */
if(!s->budget--) { s->failed_pc=0x0c06f846u; return 0; }
fr[7]=0;
goto P_0c06f848;
P_0c06f848: /* original f4ed, guest PC 0x0c06f848 */
if(!s->budget--) { s->failed_pc=0x0c06f848u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c06f84a;
P_0c06f84a: /* original f07c, guest PC 0x0c06f84a */
if(!s->budget--) { s->failed_pc=0x0c06f84au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06f84c;
P_0c06f84c: /* original 64f3, guest PC 0x0c06f84c */
if(!s->budget--) { s->failed_pc=0x0c06f84cu; return 0; }
r[4]=r[15];
goto P_0c06f84e;
P_0c06f84e: /* original 65f3, guest PC 0x0c06f84e */
if(!s->budget--) { s->failed_pc=0x0c06f84eu; return 0; }
r[5]=r[15];
goto P_0c06f850;
P_0c06f850: /* original 7420, guest PC 0x0c06f850 */
if(!s->budget--) { s->failed_pc=0x0c06f850u; return 0; }
r[4]+=0x00000020u;
goto P_0c06f852;
P_0c06f852: /* original f40c, guest PC 0x0c06f852 */
if(!s->budget--) { s->failed_pc=0x0c06f852u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06f854;
P_0c06f854: /* original 752c, guest PC 0x0c06f854 */
if(!s->budget--) { s->failed_pc=0x0c06f854u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f856;
P_0c06f856: /* original f059, guest PC 0x0c06f856 */
if(!s->budget--) { s->failed_pc=0x0c06f856u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f858;
P_0c06f858: /* original f159, guest PC 0x0c06f858 */
if(!s->budget--) { s->failed_pc=0x0c06f858u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f85a;
P_0c06f85a: /* original f259, guest PC 0x0c06f85a */
if(!s->budget--) { s->failed_pc=0x0c06f85au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f85c;
P_0c06f85c: /* original f38d, guest PC 0x0c06f85c */
if(!s->budget--) { s->failed_pc=0x0c06f85cu; return 0; }
fr[3]=0;
goto P_0c06f85e;
P_0c06f85e: /* original f0ed, guest PC 0x0c06f85e */
if(!s->budget--) { s->failed_pc=0x0c06f85eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f860;
P_0c06f860: /* original f37d, guest PC 0x0c06f860 */
if(!s->budget--) { s->failed_pc=0x0c06f860u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f862;
P_0c06f862: /* original f342, guest PC 0x0c06f862 */
if(!s->budget--) { s->failed_pc=0x0c06f862u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f864;
P_0c06f864: /* original 740c, guest PC 0x0c06f864 */
if(!s->budget--) { s->failed_pc=0x0c06f864u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f866;
P_0c06f866: /* original f232, guest PC 0x0c06f866 */
if(!s->budget--) { s->failed_pc=0x0c06f866u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f868;
P_0c06f868: /* original f132, guest PC 0x0c06f868 */
if(!s->budget--) { s->failed_pc=0x0c06f868u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f86a;
P_0c06f86a: /* original f032, guest PC 0x0c06f86a */
if(!s->budget--) { s->failed_pc=0x0c06f86au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f86c;
P_0c06f86c: /* original f42b, guest PC 0x0c06f86c */
if(!s->budget--) { s->failed_pc=0x0c06f86cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f86e;
P_0c06f86e: /* original f41b, guest PC 0x0c06f86e */
if(!s->budget--) { s->failed_pc=0x0c06f86eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f870;
P_0c06f870: /* original f40b, guest PC 0x0c06f870 */
if(!s->budget--) { s->failed_pc=0x0c06f870u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f872;
P_0c06f872: /* original 0009, guest PC 0x0c06f872 */
if(!s->budget--) { s->failed_pc=0x0c06f872u; return 0; }
goto P_0c06f874;
P_0c06f874: /* original 64f3, guest PC 0x0c06f874 */
if(!s->budget--) { s->failed_pc=0x0c06f874u; return 0; }
r[4]=r[15];
goto P_0c06f876;
P_0c06f876: /* original 65f3, guest PC 0x0c06f876 */
if(!s->budget--) { s->failed_pc=0x0c06f876u; return 0; }
r[5]=r[15];
goto P_0c06f878;
P_0c06f878: /* original 7444, guest PC 0x0c06f878 */
if(!s->budget--) { s->failed_pc=0x0c06f878u; return 0; }
r[4]+=0x00000044u;
goto P_0c06f87a;
P_0c06f87a: /* original 7520, guest PC 0x0c06f87a */
if(!s->budget--) { s->failed_pc=0x0c06f87au; return 0; }
r[5]+=0x00000020u;
goto P_0c06f87c;
P_0c06f87c: /* original f049, guest PC 0x0c06f87c */
if(!s->budget--) { s->failed_pc=0x0c06f87cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f87e;
P_0c06f87e: /* original f359, guest PC 0x0c06f87e */
if(!s->budget--) { s->failed_pc=0x0c06f87eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f880;
P_0c06f880: /* original f149, guest PC 0x0c06f880 */
if(!s->budget--) { s->failed_pc=0x0c06f880u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f882;
P_0c06f882: /* original f459, guest PC 0x0c06f882 */
if(!s->budget--) { s->failed_pc=0x0c06f882u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f884;
P_0c06f884: /* original f249, guest PC 0x0c06f884 */
if(!s->budget--) { s->failed_pc=0x0c06f884u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f886;
P_0c06f886: /* original f559, guest PC 0x0c06f886 */
if(!s->budget--) { s->failed_pc=0x0c06f886u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f888;
P_0c06f888: /* original f031, guest PC 0x0c06f888 */
if(!s->budget--) { s->failed_pc=0x0c06f888u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06f88a;
P_0c06f88a: /* original f251, guest PC 0x0c06f88a */
if(!s->budget--) { s->failed_pc=0x0c06f88au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c06f88c;
P_0c06f88c: /* original f141, guest PC 0x0c06f88c */
if(!s->budget--) { s->failed_pc=0x0c06f88cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c06f88e;
P_0c06f88e: /* original f42b, guest PC 0x0c06f88e */
if(!s->budget--) { s->failed_pc=0x0c06f88eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f890;
P_0c06f890: /* original f41b, guest PC 0x0c06f890 */
if(!s->budget--) { s->failed_pc=0x0c06f890u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f892;
P_0c06f892: /* original f40b, guest PC 0x0c06f892 */
if(!s->budget--) { s->failed_pc=0x0c06f892u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f894;
P_0c06f894: /* original 65f3, guest PC 0x0c06f894 */
if(!s->budget--) { s->failed_pc=0x0c06f894u; return 0; }
r[5]=r[15];
goto P_0c06f896;
P_0c06f896: /* original 64f3, guest PC 0x0c06f896 */
if(!s->budget--) { s->failed_pc=0x0c06f896u; return 0; }
r[4]=r[15];
goto P_0c06f898;
P_0c06f898: /* original 66f3, guest PC 0x0c06f898 */
if(!s->budget--) { s->failed_pc=0x0c06f898u; return 0; }
r[6]=r[15];
goto P_0c06f89a;
P_0c06f89a: /* original 742c, guest PC 0x0c06f89a */
if(!s->budget--) { s->failed_pc=0x0c06f89au; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f89c;
P_0c06f89c: /* original 7644, guest PC 0x0c06f89c */
if(!s->budget--) { s->failed_pc=0x0c06f89cu; return 0; }
r[6]+=0x00000044u;
goto P_0c06f89e;
P_0c06f89e: /* original 7538, guest PC 0x0c06f89e */
if(!s->budget--) { s->failed_pc=0x0c06f89eu; return 0; }
r[5]+=0x00000038u;
goto P_0c06f8a0;
P_0c06f8a0: /* original f059, guest PC 0x0c06f8a0 */
if(!s->budget--) { s->failed_pc=0x0c06f8a0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a2;
P_0c06f8a2: /* original f369, guest PC 0x0c06f8a2 */
if(!s->budget--) { s->failed_pc=0x0c06f8a2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a4;
P_0c06f8a4: /* original f159, guest PC 0x0c06f8a4 */
if(!s->budget--) { s->failed_pc=0x0c06f8a4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a6;
P_0c06f8a6: /* original f469, guest PC 0x0c06f8a6 */
if(!s->budget--) { s->failed_pc=0x0c06f8a6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a8;
P_0c06f8a8: /* original f259, guest PC 0x0c06f8a8 */
if(!s->budget--) { s->failed_pc=0x0c06f8a8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8aa;
P_0c06f8aa: /* original f569, guest PC 0x0c06f8aa */
if(!s->budget--) { s->failed_pc=0x0c06f8aau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ac;
P_0c06f8ac: /* original 740c, guest PC 0x0c06f8ac */
if(!s->budget--) { s->failed_pc=0x0c06f8acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8ae;
P_0c06f8ae: /* original f030, guest PC 0x0c06f8ae */
if(!s->budget--) { s->failed_pc=0x0c06f8aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8b0;
P_0c06f8b0: /* original f250, guest PC 0x0c06f8b0 */
if(!s->budget--) { s->failed_pc=0x0c06f8b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f8b2;
P_0c06f8b2: /* original f140, guest PC 0x0c06f8b2 */
if(!s->budget--) { s->failed_pc=0x0c06f8b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f8b4;
P_0c06f8b4: /* original f42b, guest PC 0x0c06f8b4 */
if(!s->budget--) { s->failed_pc=0x0c06f8b4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8b6;
P_0c06f8b6: /* original f41b, guest PC 0x0c06f8b6 */
if(!s->budget--) { s->failed_pc=0x0c06f8b6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8b8;
P_0c06f8b8: /* original f40b, guest PC 0x0c06f8b8 */
if(!s->budget--) { s->failed_pc=0x0c06f8b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8ba;
P_0c06f8ba: /* original 0009, guest PC 0x0c06f8ba */
if(!s->budget--) { s->failed_pc=0x0c06f8bau; return 0; }
goto P_0c06f8bc;
P_0c06f8bc: /* original 64f3, guest PC 0x0c06f8bc */
if(!s->budget--) { s->failed_pc=0x0c06f8bcu; return 0; }
r[4]=r[15];
goto P_0c06f8be;
P_0c06f8be: /* original 65f3, guest PC 0x0c06f8be */
if(!s->budget--) { s->failed_pc=0x0c06f8beu; return 0; }
r[5]=r[15];
goto P_0c06f8c0;
P_0c06f8c0: /* original 742c, guest PC 0x0c06f8c0 */
if(!s->budget--) { s->failed_pc=0x0c06f8c0u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f8c2;
P_0c06f8c2: /* original f4ec, guest PC 0x0c06f8c2 */
if(!s->budget--) { s->failed_pc=0x0c06f8c2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06f8c4;
P_0c06f8c4: /* original 752c, guest PC 0x0c06f8c4 */
if(!s->budget--) { s->failed_pc=0x0c06f8c4u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f8c6;
P_0c06f8c6: /* original f059, guest PC 0x0c06f8c6 */
if(!s->budget--) { s->failed_pc=0x0c06f8c6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8c8;
P_0c06f8c8: /* original f159, guest PC 0x0c06f8c8 */
if(!s->budget--) { s->failed_pc=0x0c06f8c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ca;
P_0c06f8ca: /* original f259, guest PC 0x0c06f8ca */
if(!s->budget--) { s->failed_pc=0x0c06f8cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8cc;
P_0c06f8cc: /* original f38d, guest PC 0x0c06f8cc */
if(!s->budget--) { s->failed_pc=0x0c06f8ccu; return 0; }
fr[3]=0;
goto P_0c06f8ce;
P_0c06f8ce: /* original f0ed, guest PC 0x0c06f8ce */
if(!s->budget--) { s->failed_pc=0x0c06f8ceu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f8d0;
P_0c06f8d0: /* original f37d, guest PC 0x0c06f8d0 */
if(!s->budget--) { s->failed_pc=0x0c06f8d0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f8d2;
P_0c06f8d2: /* original f342, guest PC 0x0c06f8d2 */
if(!s->budget--) { s->failed_pc=0x0c06f8d2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f8d4;
P_0c06f8d4: /* original 740c, guest PC 0x0c06f8d4 */
if(!s->budget--) { s->failed_pc=0x0c06f8d4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8d6;
P_0c06f8d6: /* original f232, guest PC 0x0c06f8d6 */
if(!s->budget--) { s->failed_pc=0x0c06f8d6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f8d8;
P_0c06f8d8: /* original f132, guest PC 0x0c06f8d8 */
if(!s->budget--) { s->failed_pc=0x0c06f8d8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f8da;
P_0c06f8da: /* original f032, guest PC 0x0c06f8da */
if(!s->budget--) { s->failed_pc=0x0c06f8dau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f8dc;
P_0c06f8dc: /* original f42b, guest PC 0x0c06f8dc */
if(!s->budget--) { s->failed_pc=0x0c06f8dcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8de;
P_0c06f8de: /* original f41b, guest PC 0x0c06f8de */
if(!s->budget--) { s->failed_pc=0x0c06f8deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8e0;
P_0c06f8e0: /* original f40b, guest PC 0x0c06f8e0 */
if(!s->budget--) { s->failed_pc=0x0c06f8e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8e2;
P_0c06f8e2: /* original 0009, guest PC 0x0c06f8e2 */
if(!s->budget--) { s->failed_pc=0x0c06f8e2u; return 0; }
goto P_0c06f8e4;
P_0c06f8e4: /* original 64f3, guest PC 0x0c06f8e4 */
if(!s->budget--) { s->failed_pc=0x0c06f8e4u; return 0; }
r[4]=r[15];
goto P_0c06f8e6;
P_0c06f8e6: /* original 66f3, guest PC 0x0c06f8e6 */
if(!s->budget--) { s->failed_pc=0x0c06f8e6u; return 0; }
r[6]=r[15];
goto P_0c06f8e8;
P_0c06f8e8: /* original 7450, guest PC 0x0c06f8e8 */
if(!s->budget--) { s->failed_pc=0x0c06f8e8u; return 0; }
r[4]+=0x00000050u;
goto P_0c06f8ea;
P_0c06f8ea: /* original 65c3, guest PC 0x0c06f8ea */
if(!s->budget--) { s->failed_pc=0x0c06f8eau; return 0; }
r[5]=r[12];
goto P_0c06f8ec;
P_0c06f8ec: /* original 762c, guest PC 0x0c06f8ec */
if(!s->budget--) { s->failed_pc=0x0c06f8ecu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f8ee;
P_0c06f8ee: /* original f059, guest PC 0x0c06f8ee */
if(!s->budget--) { s->failed_pc=0x0c06f8eeu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f0;
P_0c06f8f0: /* original f369, guest PC 0x0c06f8f0 */
if(!s->budget--) { s->failed_pc=0x0c06f8f0u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f2;
P_0c06f8f2: /* original f159, guest PC 0x0c06f8f2 */
if(!s->budget--) { s->failed_pc=0x0c06f8f2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f4;
P_0c06f8f4: /* original f469, guest PC 0x0c06f8f4 */
if(!s->budget--) { s->failed_pc=0x0c06f8f4u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f6;
P_0c06f8f6: /* original f259, guest PC 0x0c06f8f6 */
if(!s->budget--) { s->failed_pc=0x0c06f8f6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f8;
P_0c06f8f8: /* original f569, guest PC 0x0c06f8f8 */
if(!s->budget--) { s->failed_pc=0x0c06f8f8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8fa;
P_0c06f8fa: /* original 740c, guest PC 0x0c06f8fa */
if(!s->budget--) { s->failed_pc=0x0c06f8fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8fc;
P_0c06f8fc: /* original f030, guest PC 0x0c06f8fc */
if(!s->budget--) { s->failed_pc=0x0c06f8fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8fe;
P_0c06f8fe: /* original f250, guest PC 0x0c06f8fe */
if(!s->budget--) { s->failed_pc=0x0c06f8feu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f900;
P_0c06f900: /* original f140, guest PC 0x0c06f900 */
if(!s->budget--) { s->failed_pc=0x0c06f900u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f902;
P_0c06f902: /* original f42b, guest PC 0x0c06f902 */
if(!s->budget--) { s->failed_pc=0x0c06f902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f904;
P_0c06f904: /* original f41b, guest PC 0x0c06f904 */
if(!s->budget--) { s->failed_pc=0x0c06f904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f906;
P_0c06f906: /* original f40b, guest PC 0x0c06f906 */
if(!s->budget--) { s->failed_pc=0x0c06f906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f908;
P_0c06f908: /* original 66f3, guest PC 0x0c06f908 */
if(!s->budget--) { s->failed_pc=0x0c06f908u; return 0; }
r[6]=r[15];
goto P_0c06f90a;
P_0c06f90a: /* original 64d3, guest PC 0x0c06f90a */
if(!s->budget--) { s->failed_pc=0x0c06f90au; return 0; }
r[4]=r[13];
goto P_0c06f90c;
P_0c06f90c: /* original 65c3, guest PC 0x0c06f90c */
if(!s->budget--) { s->failed_pc=0x0c06f90cu; return 0; }
r[5]=r[12];
goto P_0c06f90e;
P_0c06f90e: /* original 762c, guest PC 0x0c06f90e */
if(!s->budget--) { s->failed_pc=0x0c06f90eu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f910;
P_0c06f910: /* original f059, guest PC 0x0c06f910 */
if(!s->budget--) { s->failed_pc=0x0c06f910u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f912;
P_0c06f912: /* original f369, guest PC 0x0c06f912 */
if(!s->budget--) { s->failed_pc=0x0c06f912u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f914;
P_0c06f914: /* original f159, guest PC 0x0c06f914 */
if(!s->budget--) { s->failed_pc=0x0c06f914u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f916;
P_0c06f916: /* original f469, guest PC 0x0c06f916 */
if(!s->budget--) { s->failed_pc=0x0c06f916u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f918;
P_0c06f918: /* original f259, guest PC 0x0c06f918 */
if(!s->budget--) { s->failed_pc=0x0c06f918u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91a;
P_0c06f91a: /* original f569, guest PC 0x0c06f91a */
if(!s->budget--) { s->failed_pc=0x0c06f91au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91c;
P_0c06f91c: /* original 740c, guest PC 0x0c06f91c */
if(!s->budget--) { s->failed_pc=0x0c06f91cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f91e;
P_0c06f91e: /* original f030, guest PC 0x0c06f91e */
if(!s->budget--) { s->failed_pc=0x0c06f91eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f920;
P_0c06f920: /* original f250, guest PC 0x0c06f920 */
if(!s->budget--) { s->failed_pc=0x0c06f920u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f922;
P_0c06f922: /* original f140, guest PC 0x0c06f922 */
if(!s->budget--) { s->failed_pc=0x0c06f922u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f924;
P_0c06f924: /* original f42b, guest PC 0x0c06f924 */
if(!s->budget--) { s->failed_pc=0x0c06f924u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f926;
P_0c06f926: /* original f41b, guest PC 0x0c06f926 */
if(!s->budget--) { s->failed_pc=0x0c06f926u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f928;
P_0c06f928: /* original f40b, guest PC 0x0c06f928 */
if(!s->budget--) { s->failed_pc=0x0c06f928u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f92a;
P_0c06f92a: /* original 0009, guest PC 0x0c06f92a */
if(!s->budget--) { s->failed_pc=0x0c06f92au; return 0; }
goto P_0c06f92c;
P_0c06f92c: /* original 7901, guest PC 0x0c06f92c */
if(!s->budget--) { s->failed_pc=0x0c06f92cu; return 0; }
r[9]+=0x00000001u;
goto P_0c06f92e;
P_0c06f92e: /* original 39a3, guest PC 0x0c06f92e */
if(!s->budget--) { s->failed_pc=0x0c06f92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[10])!=0);
goto P_0c06f930;
P_0c06f930: /* original 7d18, guest PC 0x0c06f930 */
if(!s->budget--) { s->failed_pc=0x0c06f930u; return 0; }
r[13]+=0x00000018u;
goto P_0c06f932;
P_0c06f932: /* original 8d03, guest PC 0x0c06f932 */
if(!s->budget--) { s->failed_pc=0x0c06f932u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000018u;
if(cond) { goto P_0c06f93c; }
goto P_0c06f936;
P_0c06f934: /* original 7c18, guest PC 0x0c06f934 */
if(!s->budget--) { s->failed_pc=0x0c06f934u; return 0; }
r[12]+=0x00000018u;
goto P_0c06f936;
P_0c06f936: /* original d234, guest PC 0x0c06f936 */
if(!s->budget--) { s->failed_pc=0x0c06f936u; return 0; }
r[2]=read(ram,0x0c06fa08u,4);
goto P_0c06f938;
P_0c06f938: /* original 422b, guest PC 0x0c06f938 */
if(!s->budget--) { s->failed_pc=0x0c06f938u; return 0; }
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
P_0c06f93a: /* original 0009, guest PC 0x0c06f93a */
if(!s->budget--) { s->failed_pc=0x0c06f93au; return 0; }
goto P_0c06f93c;
P_0c06f93c: /* original d333, guest PC 0x0c06f93c */
if(!s->budget--) { s->failed_pc=0x0c06f93cu; return 0; }
r[3]=read(ram,0x0c06fa0cu,4);
goto P_0c06f93e;
P_0c06f93e: /* original 65e3, guest PC 0x0c06f93e */
if(!s->budget--) { s->failed_pc=0x0c06f93eu; return 0; }
r[5]=r[14];
goto P_0c06f940;
P_0c06f940: /* original 6783, guest PC 0x0c06f940 */
if(!s->budget--) { s->failed_pc=0x0c06f940u; return 0; }
r[7]=r[8];
goto P_0c06f942;
P_0c06f942: /* original 66d3, guest PC 0x0c06f942 */
if(!s->budget--) { s->failed_pc=0x0c06f942u; return 0; }
r[6]=r[13];
goto P_0c06f944;
P_0c06f944: /* original 430b, guest PC 0x0c06f944 */
if(!s->budget--) { s->failed_pc=0x0c06f944u; return 0; }
target=r[3];
r[16]=0x0c06f948u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f948u) { target=s->pc; goto dispatch; }
goto P_0c06f948;
P_0c06f946: /* original 64b3, guest PC 0x0c06f946 */
if(!s->budget--) { s->failed_pc=0x0c06f946u; return 0; }
r[4]=r[11];
goto P_0c06f948;
P_0c06f948: /* original 7801, guest PC 0x0c06f948 */
if(!s->budget--) { s->failed_pc=0x0c06f948u; return 0; }
r[8]+=0x00000001u;
goto P_0c06f94a;
P_0c06f94a: /* original 52f1, guest PC 0x0c06f94a */
if(!s->budget--) { s->failed_pc=0x0c06f94au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06f94c;
P_0c06f94c: /* original 3823, guest PC 0x0c06f94c */
if(!s->budget--) { s->failed_pc=0x0c06f94cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c06f94e;
P_0c06f94e: /* original 8902, guest PC 0x0c06f94e */
if(!s->budget--) { s->failed_pc=0x0c06f94eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f956; }
goto P_0c06f950;
P_0c06f950: /* original d32f, guest PC 0x0c06f950 */
if(!s->budget--) { s->failed_pc=0x0c06f950u; return 0; }
r[3]=read(ram,0x0c06fa10u,4);
goto P_0c06f952;
P_0c06f952: /* original 432b, guest PC 0x0c06f952 */
if(!s->budget--) { s->failed_pc=0x0c06f952u; return 0; }
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
P_0c06f954: /* original 0009, guest PC 0x0c06f954 */
if(!s->budget--) { s->failed_pc=0x0c06f954u; return 0; }
goto P_0c06f956;
P_0c06f956: /* original d22f, guest PC 0x0c06f956 */
if(!s->budget--) { s->failed_pc=0x0c06f956u; return 0; }
r[2]=read(ram,0x0c06fa14u,4);
goto P_0c06f958;
P_0c06f958: /* original 420b, guest PC 0x0c06f958 */
if(!s->budget--) { s->failed_pc=0x0c06f958u; return 0; }
target=r[2];
r[16]=0x0c06f95cu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f95cu) { target=s->pc; goto dispatch; }
goto P_0c06f95c;
P_0c06f95a: /* original e401, guest PC 0x0c06f95a */
if(!s->budget--) { s->failed_pc=0x0c06f95au; return 0; }
r[4]=0x00000001u;
goto P_0c06f95c;
P_0c06f95c: /* original d32e, guest PC 0x0c06f95c */
if(!s->budget--) { s->failed_pc=0x0c06f95cu; return 0; }
r[3]=read(ram,0x0c06fa18u,4);
goto P_0c06f95e;
P_0c06f95e: /* original 430b, guest PC 0x0c06f95e */
if(!s->budget--) { s->failed_pc=0x0c06f95eu; return 0; }
target=r[3];
r[16]=0x0c06f962u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f962u) { target=s->pc; goto dispatch; }
goto P_0c06f962;
P_0c06f960: /* original 64e3, guest PC 0x0c06f960 */
if(!s->budget--) { s->failed_pc=0x0c06f960u; return 0; }
r[4]=r[14];
goto P_0c06f962;
P_0c06f962: /* original d22e, guest PC 0x0c06f962 */
if(!s->budget--) { s->failed_pc=0x0c06f962u; return 0; }
r[2]=read(ram,0x0c06fa1cu,4);
goto P_0c06f964;
P_0c06f964: /* original 65e3, guest PC 0x0c06f964 */
if(!s->budget--) { s->failed_pc=0x0c06f964u; return 0; }
r[5]=r[14];
goto P_0c06f966;
P_0c06f966: /* original 420b, guest PC 0x0c06f966 */
if(!s->budget--) { s->failed_pc=0x0c06f966u; return 0; }
target=r[2];
r[16]=0x0c06f96au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f96au) { target=s->pc; goto dispatch; }
goto P_0c06f96a;
P_0c06f968: /* original 64b3, guest PC 0x0c06f968 */
if(!s->budget--) { s->failed_pc=0x0c06f968u; return 0; }
r[4]=r[11];
goto P_0c06f96a;
P_0c06f96a: /* original d32d, guest PC 0x0c06f96a */
if(!s->budget--) { s->failed_pc=0x0c06f96au; return 0; }
r[3]=read(ram,0x0c06fa20u,4);
goto P_0c06f96c;
P_0c06f96c: /* original 64e3, guest PC 0x0c06f96c */
if(!s->budget--) { s->failed_pc=0x0c06f96cu; return 0; }
r[4]=r[14];
goto P_0c06f96e;
P_0c06f96e: /* original 65f2, guest PC 0x0c06f96e */
if(!s->budget--) { s->failed_pc=0x0c06f96eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06f970;
P_0c06f970: /* original 430b, guest PC 0x0c06f970 */
if(!s->budget--) { s->failed_pc=0x0c06f970u; return 0; }
target=r[3];
r[16]=0x0c06f974u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f974u) { target=s->pc; goto dispatch; }
goto P_0c06f974;
P_0c06f972: /* original 7410, guest PC 0x0c06f972 */
if(!s->budget--) { s->failed_pc=0x0c06f972u; return 0; }
r[4]+=0x00000010u;
goto P_0c06f974;
P_0c06f974: /* original 7f74, guest PC 0x0c06f974 */
if(!s->budget--) { s->failed_pc=0x0c06f974u; return 0; }
r[15]+=0x00000074u;
goto P_0c06f976;
P_0c06f976: /* original 4f16, guest PC 0x0c06f976 */
if(!s->budget--) { s->failed_pc=0x0c06f976u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f978;
P_0c06f978: /* original 4f26, guest PC 0x0c06f978 */
if(!s->budget--) { s->failed_pc=0x0c06f978u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f97a;
P_0c06f97a: /* original fcf9, guest PC 0x0c06f97a */
if(!s->budget--) { s->failed_pc=0x0c06f97au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97c;
P_0c06f97c: /* original fdf9, guest PC 0x0c06f97c */
if(!s->budget--) { s->failed_pc=0x0c06f97cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97e;
P_0c06f97e: /* original fef9, guest PC 0x0c06f97e */
if(!s->budget--) { s->failed_pc=0x0c06f97eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f980;
P_0c06f980: /* original fff9, guest PC 0x0c06f980 */
if(!s->budget--) { s->failed_pc=0x0c06f980u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f982;
P_0c06f982: /* original 68f6, guest PC 0x0c06f982 */
if(!s->budget--) { s->failed_pc=0x0c06f982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06f984;
P_0c06f984: /* original 69f6, guest PC 0x0c06f984 */
if(!s->budget--) { s->failed_pc=0x0c06f984u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06f986;
P_0c06f986: /* original 6af6, guest PC 0x0c06f986 */
if(!s->budget--) { s->failed_pc=0x0c06f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f988;
P_0c06f988: /* original 6bf6, guest PC 0x0c06f988 */
if(!s->budget--) { s->failed_pc=0x0c06f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f98a;
P_0c06f98a: /* original 6cf6, guest PC 0x0c06f98a */
if(!s->budget--) { s->failed_pc=0x0c06f98au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f98c;
P_0c06f98c: /* original 6df6, guest PC 0x0c06f98c */
if(!s->budget--) { s->failed_pc=0x0c06f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f98e;
P_0c06f98e: /* original 000b, guest PC 0x0c06f98e */
if(!s->budget--) { s->failed_pc=0x0c06f98eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f990: /* original 6ef6, guest PC 0x0c06f990 */
if(!s->budget--) { s->failed_pc=0x0c06f990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06f992u,s,ram);
P_0c070008: /* original 2fe6, guest PC 0x0c070008 */
if(!s->budget--) { s->failed_pc=0x0c070008u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07000a;
P_0c07000a: /* original e058, guest PC 0x0c07000a */
if(!s->budget--) { s->failed_pc=0x0c07000au; return 0; }
r[0]=0x00000058u;
goto P_0c07000c;
P_0c07000c: /* original 2fd6, guest PC 0x0c07000c */
if(!s->budget--) { s->failed_pc=0x0c07000cu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c07000e;
P_0c07000e: /* original e300, guest PC 0x0c07000e */
if(!s->budget--) { s->failed_pc=0x0c07000eu; return 0; }
r[3]=0x00000000u;
goto P_0c070010;
P_0c070010: /* original 2fc6, guest PC 0x0c070010 */
if(!s->budget--) { s->failed_pc=0x0c070010u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c070012;
P_0c070012: /* original 2fb6, guest PC 0x0c070012 */
if(!s->budget--) { s->failed_pc=0x0c070012u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c070014;
P_0c070014: /* original 2fa6, guest PC 0x0c070014 */
if(!s->budget--) { s->failed_pc=0x0c070014u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c070016;
P_0c070016: /* original 2f96, guest PC 0x0c070016 */
if(!s->budget--) { s->failed_pc=0x0c070016u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c070018;
P_0c070018: /* original 2f86, guest PC 0x0c070018 */
if(!s->budget--) { s->failed_pc=0x0c070018u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c07001a;
P_0c07001a: /* original fffb, guest PC 0x0c07001a */
if(!s->budget--) { s->failed_pc=0x0c07001au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07001c;
P_0c07001c: /* original ffeb, guest PC 0x0c07001c */
if(!s->budget--) { s->failed_pc=0x0c07001cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c07001e;
P_0c07001e: /* original ffdb, guest PC 0x0c07001e */
if(!s->budget--) { s->failed_pc=0x0c07001eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c070020;
P_0c070020: /* original ffcb, guest PC 0x0c070020 */
if(!s->budget--) { s->failed_pc=0x0c070020u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c070022;
P_0c070022: /* original 4f22, guest PC 0x0c070022 */
if(!s->budget--) { s->failed_pc=0x0c070022u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c070024;
P_0c070024: /* original 7fa4, guest PC 0x0c070024 */
if(!s->budget--) { s->failed_pc=0x0c070024u; return 0; }
r[15]+=0xffffffa4u;
goto P_0c070026;
P_0c070026: /* original 1f3a, guest PC 0x0c070026 */
if(!s->budget--) { s->failed_pc=0x0c070026u; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c070028;
P_0c070028: /* original 0e5e, guest PC 0x0c070028 */
if(!s->budget--) { s->failed_pc=0x0c070028u; return 0; }
r[14]=read(ram,r[5]+r[0],4);
goto P_0c07002a;
P_0c07002a: /* original e060, guest PC 0x0c07002a */
if(!s->budget--) { s->failed_pc=0x0c07002au; return 0; }
r[0]=0x00000060u;
goto P_0c07002c;
P_0c07002c: /* original 63e3, guest PC 0x0c07002c */
if(!s->budget--) { s->failed_pc=0x0c07002cu; return 0; }
r[3]=r[14];
goto P_0c07002e;
P_0c07002e: /* original 4321, guest PC 0x0c07002e */
if(!s->budget--) { s->failed_pc=0x0c07002eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c070030;
P_0c070030: /* original 2f32, guest PC 0x0c070030 */
if(!s->budget--) { s->failed_pc=0x0c070030u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c070032;
P_0c070032: /* original 61e3, guest PC 0x0c070032 */
if(!s->budget--) { s->failed_pc=0x0c070032u; return 0; }
r[1]=r[14];
goto P_0c070034;
P_0c070034: /* original fd56, guest PC 0x0c070034 */
if(!s->budget--) { s->failed_pc=0x0c070034u; return 0; }
vf3_matrix_load(s,ram,13,r[5]+r[0]);
goto P_0c070036;
P_0c070036: /* original 7048, guest PC 0x0c070036 */
if(!s->budget--) { s->failed_pc=0x0c070036u; return 0; }
r[0]+=0x00000048u;
goto P_0c070038;
P_0c070038: /* original fe56, guest PC 0x0c070038 */
if(!s->budget--) { s->failed_pc=0x0c070038u; return 0; }
vf3_matrix_load(s,ram,14,r[5]+r[0]);
goto P_0c07003a;
P_0c07003a: /* original 7004, guest PC 0x0c07003a */
if(!s->budget--) { s->failed_pc=0x0c07003au; return 0; }
r[0]+=0x00000004u;
goto P_0c07003c;
P_0c07003c: /* original d311, guest PC 0x0c07003c */
if(!s->budget--) { s->failed_pc=0x0c07003cu; return 0; }
r[3]=read(ram,0x0c070084u,4);
goto P_0c07003e;
P_0c07003e: /* original ff56, guest PC 0x0c07003e */
if(!s->budget--) { s->failed_pc=0x0c07003eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]+r[0]);
goto P_0c070040;
P_0c070040: /* original 430b, guest PC 0x0c070040 */
if(!s->budget--) { s->failed_pc=0x0c070040u; return 0; }
target=r[3];
r[16]=0x0c070044u;
r[0]=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c070044u) { target=s->pc; goto dispatch; }
goto P_0c070044;
P_0c070042: /* original e002, guest PC 0x0c070042 */
if(!s->budget--) { s->failed_pc=0x0c070042u; return 0; }
r[0]=0x00000002u;
goto P_0c070044;
P_0c070044: /* original 2008, guest PC 0x0c070044 */
if(!s->budget--) { s->failed_pc=0x0c070044u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c070046;
P_0c070046: /* original 891f, guest PC 0x0c070046 */
if(!s->budget--) { s->failed_pc=0x0c070046u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070088; }
goto P_0c070048;
P_0c070048: /* original 61f2, guest PC 0x0c070048 */
if(!s->budget--) { s->failed_pc=0x0c070048u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07004a;
P_0c07004a: /* original 6863, guest PC 0x0c07004a */
if(!s->budget--) { s->failed_pc=0x0c07004au; return 0; }
r[8]=r[6];
goto P_0c07004c;
P_0c07004c: /* original 7101, guest PC 0x0c07004c */
if(!s->budget--) { s->failed_pc=0x0c07004cu; return 0; }
r[1]+=0x00000001u;
goto P_0c07004e;
P_0c07004e: /* original 6313, guest PC 0x0c07004e */
if(!s->budget--) { s->failed_pc=0x0c07004eu; return 0; }
r[3]=r[1];
goto P_0c070050;
P_0c070050: /* original 4100, guest PC 0x0c070050 */
if(!s->budget--) { s->failed_pc=0x0c070050u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c070052;
P_0c070052: /* original 313c, guest PC 0x0c070052 */
if(!s->budget--) { s->failed_pc=0x0c070052u; return 0; }
r[1]+=r[3];
goto P_0c070054;
P_0c070054: /* original 4108, guest PC 0x0c070054 */
if(!s->budget--) { s->failed_pc=0x0c070054u; return 0; }
r[1]<<=2;
goto P_0c070056;
P_0c070056: /* original 4100, guest PC 0x0c070056 */
if(!s->budget--) { s->failed_pc=0x0c070056u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c070058;
P_0c070058: /* original 3818, guest PC 0x0c070058 */
if(!s->budget--) { s->failed_pc=0x0c070058u; return 0; }
r[8]-=r[1];
goto P_0c07005a;
P_0c07005a: /* original 6e83, guest PC 0x0c07005a */
if(!s->budget--) { s->failed_pc=0x0c07005au; return 0; }
r[14]=r[8];
goto P_0c07005c;
P_0c07005c: /* original 1f81, guest PC 0x0c07005c */
if(!s->budget--) { s->failed_pc=0x0c07005cu; return 0; }
write(ram,r[15]+4,r[8],4);
goto P_0c07005e;
P_0c07005e: /* original a028, guest PC 0x0c07005e */
if(!s->budget--) { s->failed_pc=0x0c07005eu; return 0; }
r[13]=r[8];
goto P_0c0700b2;
P_0c070060: /* original 6d83, guest PC 0x0c070060 */
if(!s->budget--) { s->failed_pc=0x0c070060u; return 0; }
r[13]=r[8];
return vf3_matrix_family(0x0c070062u,s,ram);
P_0c070088: /* original 62f2, guest PC 0x0c070088 */
if(!s->budget--) { s->failed_pc=0x0c070088u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07008a;
P_0c07008a: /* original 6863, guest PC 0x0c07008a */
if(!s->budget--) { s->failed_pc=0x0c07008au; return 0; }
r[8]=r[6];
goto P_0c07008c;
P_0c07008c: /* original 6323, guest PC 0x0c07008c */
if(!s->budget--) { s->failed_pc=0x0c07008cu; return 0; }
r[3]=r[2];
goto P_0c07008e;
P_0c07008e: /* original 4200, guest PC 0x0c07008e */
if(!s->budget--) { s->failed_pc=0x0c07008eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c070090;
P_0c070090: /* original 323c, guest PC 0x0c070090 */
if(!s->budget--) { s->failed_pc=0x0c070090u; return 0; }
r[2]+=r[3];
goto P_0c070092;
P_0c070092: /* original 63f2, guest PC 0x0c070092 */
if(!s->budget--) { s->failed_pc=0x0c070092u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c070094;
P_0c070094: /* original 4208, guest PC 0x0c070094 */
if(!s->budget--) { s->failed_pc=0x0c070094u; return 0; }
r[2]<<=2;
goto P_0c070096;
P_0c070096: /* original 4200, guest PC 0x0c070096 */
if(!s->budget--) { s->failed_pc=0x0c070096u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c070098;
P_0c070098: /* original 7301, guest PC 0x0c070098 */
if(!s->budget--) { s->failed_pc=0x0c070098u; return 0; }
r[3]+=0x00000001u;
goto P_0c07009a;
P_0c07009a: /* original 3828, guest PC 0x0c07009a */
if(!s->budget--) { s->failed_pc=0x0c07009au; return 0; }
r[8]-=r[2];
goto P_0c07009c;
P_0c07009c: /* original 6233, guest PC 0x0c07009c */
if(!s->budget--) { s->failed_pc=0x0c07009cu; return 0; }
r[2]=r[3];
goto P_0c07009e;
P_0c07009e: /* original 4300, guest PC 0x0c07009e */
if(!s->budget--) { s->failed_pc=0x0c07009eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0700a0;
P_0c0700a0: /* original 6e83, guest PC 0x0c0700a0 */
if(!s->budget--) { s->failed_pc=0x0c0700a0u; return 0; }
r[14]=r[8];
goto P_0c0700a2;
P_0c0700a2: /* original 332c, guest PC 0x0c0700a2 */
if(!s->budget--) { s->failed_pc=0x0c0700a2u; return 0; }
r[3]+=r[2];
goto P_0c0700a4;
P_0c0700a4: /* original 4308, guest PC 0x0c0700a4 */
if(!s->budget--) { s->failed_pc=0x0c0700a4u; return 0; }
r[3]<<=2;
goto P_0c0700a6;
P_0c0700a6: /* original 4300, guest PC 0x0c0700a6 */
if(!s->budget--) { s->failed_pc=0x0c0700a6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0700a8;
P_0c0700a8: /* original 3638, guest PC 0x0c0700a8 */
if(!s->budget--) { s->failed_pc=0x0c0700a8u; return 0; }
r[6]-=r[3];
goto P_0c0700aa;
P_0c0700aa: /* original e301, guest PC 0x0c0700aa */
if(!s->budget--) { s->failed_pc=0x0c0700aau; return 0; }
r[3]=0x00000001u;
goto P_0c0700ac;
P_0c0700ac: /* original 6d63, guest PC 0x0c0700ac */
if(!s->budget--) { s->failed_pc=0x0c0700acu; return 0; }
r[13]=r[6];
goto P_0c0700ae;
P_0c0700ae: /* original 1f61, guest PC 0x0c0700ae */
if(!s->budget--) { s->failed_pc=0x0c0700aeu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0700b0;
P_0c0700b0: /* original 1f3a, guest PC 0x0c0700b0 */
if(!s->budget--) { s->failed_pc=0x0c0700b0u; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c0700b2;
P_0c0700b2: /* original 9924, guest PC 0x0c0700b2 */
if(!s->budget--) { s->failed_pc=0x0c0700b2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0700feu,2);
goto P_0c0700b4;
P_0c0700b4: /* original 6b53, guest PC 0x0c0700b4 */
if(!s->budget--) { s->failed_pc=0x0c0700b4u; return 0; }
r[11]=r[5];
goto P_0c0700b6;
P_0c0700b6: /* original 9c23, guest PC 0x0c0700b6 */
if(!s->budget--) { s->failed_pc=0x0c0700b6u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c070100u,2);
goto P_0c0700b8;
P_0c0700b8: /* original e304, guest PC 0x0c0700b8 */
if(!s->budget--) { s->failed_pc=0x0c0700b8u; return 0; }
r[3]=0x00000004u;
goto P_0c0700ba;
P_0c0700ba: /* original 9a1f, guest PC 0x0c0700ba */
if(!s->budget--) { s->failed_pc=0x0c0700bau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0700fcu,2);
goto P_0c0700bc;
P_0c0700bc: /* original 395c, guest PC 0x0c0700bc */
if(!s->budget--) { s->failed_pc=0x0c0700bcu; return 0; }
r[9]+=r[5];
goto P_0c0700be;
P_0c0700be: /* original 3c5c, guest PC 0x0c0700be */
if(!s->budget--) { s->failed_pc=0x0c0700beu; return 0; }
r[12]+=r[5];
goto P_0c0700c0;
P_0c0700c0: /* original 3a5c, guest PC 0x0c0700c0 */
if(!s->budget--) { s->failed_pc=0x0c0700c0u; return 0; }
r[10]+=r[5];
goto P_0c0700c2;
P_0c0700c2: /* original 657f, guest PC 0x0c0700c2 */
if(!s->budget--) { s->failed_pc=0x0c0700c2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c0700c4;
P_0c0700c4: /* original 3537, guest PC 0x0c0700c4 */
if(!s->budget--) { s->failed_pc=0x0c0700c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[3])!=0);
goto P_0c0700c6;
P_0c0700c6: /* original 8d08, guest PC 0x0c0700c6 */
if(!s->budget--) { s->failed_pc=0x0c0700c6u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000074u;
if(cond) { goto P_0c0700da; }
goto P_0c0700ca;
P_0c0700c8: /* original 7b74, guest PC 0x0c0700c8 */
if(!s->budget--) { s->failed_pc=0x0c0700c8u; return 0; }
r[11]+=0x00000074u;
goto P_0c0700ca;
P_0c0700ca: /* original e061, guest PC 0x0c0700ca */
if(!s->budget--) { s->failed_pc=0x0c0700cau; return 0; }
r[0]=0x00000061u;
goto P_0c0700cc;
P_0c0700cc: /* original 004c, guest PC 0x0c0700cc */
if(!s->budget--) { s->failed_pc=0x0c0700ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0700ce;
P_0c0700ce: /* original 600c, guest PC 0x0c0700ce */
if(!s->budget--) { s->failed_pc=0x0c0700ceu; return 0; }
r[0]=r[0]&255u;
goto P_0c0700d0;
P_0c0700d0: /* original 8804, guest PC 0x0c0700d0 */
if(!s->budget--) { s->failed_pc=0x0c0700d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0700d2;
P_0c0700d2: /* original 8b02, guest PC 0x0c0700d2 */
if(!s->budget--) { s->failed_pc=0x0c0700d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0700da; }
goto P_0c0700d4;
P_0c0700d4: /* original d20b, guest PC 0x0c0700d4 */
if(!s->budget--) { s->failed_pc=0x0c0700d4u; return 0; }
r[2]=read(ram,0x0c070104u,4);
goto P_0c0700d6;
P_0c0700d6: /* original 422b, guest PC 0x0c0700d6 */
if(!s->budget--) { s->failed_pc=0x0c0700d6u; return 0; }
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
P_0c0700d8: /* original 0009, guest PC 0x0c0700d8 */
if(!s->budget--) { s->failed_pc=0x0c0700d8u; return 0; }
goto P_0c0700da;
P_0c0700da: /* original e303, guest PC 0x0c0700da */
if(!s->budget--) { s->failed_pc=0x0c0700dau; return 0; }
r[3]=0x00000003u;
goto P_0c0700dc;
P_0c0700dc: /* original 3537, guest PC 0x0c0700dc */
if(!s->budget--) { s->failed_pc=0x0c0700dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[3])!=0);
goto P_0c0700de;
P_0c0700de: /* original 8907, guest PC 0x0c0700de */
if(!s->budget--) { s->failed_pc=0x0c0700deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0700f0; }
goto P_0c0700e0;
P_0c0700e0: /* original e060, guest PC 0x0c0700e0 */
if(!s->budget--) { s->failed_pc=0x0c0700e0u; return 0; }
r[0]=0x00000060u;
goto P_0c0700e2;
P_0c0700e2: /* original 004c, guest PC 0x0c0700e2 */
if(!s->budget--) { s->failed_pc=0x0c0700e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0700e4;
P_0c0700e4: /* original 600c, guest PC 0x0c0700e4 */
if(!s->budget--) { s->failed_pc=0x0c0700e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0700e6;
P_0c0700e6: /* original 8808, guest PC 0x0c0700e6 */
if(!s->budget--) { s->failed_pc=0x0c0700e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0700e8;
P_0c0700e8: /* original 8b02, guest PC 0x0c0700e8 */
if(!s->budget--) { s->failed_pc=0x0c0700e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0700f0; }
goto P_0c0700ea;
P_0c0700ea: /* original d206, guest PC 0x0c0700ea */
if(!s->budget--) { s->failed_pc=0x0c0700eau; return 0; }
r[2]=read(ram,0x0c070104u,4);
goto P_0c0700ec;
P_0c0700ec: /* original 422b, guest PC 0x0c0700ec */
if(!s->budget--) { s->failed_pc=0x0c0700ecu; return 0; }
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
P_0c0700ee: /* original 0009, guest PC 0x0c0700ee */
if(!s->budget--) { s->failed_pc=0x0c0700eeu; return 0; }
goto P_0c0700f0;
P_0c0700f0: /* original 64f3, guest PC 0x0c0700f0 */
if(!s->budget--) { s->failed_pc=0x0c0700f0u; return 0; }
r[4]=r[15];
goto P_0c0700f2;
P_0c0700f2: /* original 7444, guest PC 0x0c0700f2 */
if(!s->budget--) { s->failed_pc=0x0c0700f2u; return 0; }
r[4]+=0x00000044u;
goto P_0c0700f4;
P_0c0700f4: /* original 66a3, guest PC 0x0c0700f4 */
if(!s->budget--) { s->failed_pc=0x0c0700f4u; return 0; }
r[6]=r[10];
goto P_0c0700f6;
P_0c0700f6: /* original 65e3, guest PC 0x0c0700f6 */
if(!s->budget--) { s->failed_pc=0x0c0700f6u; return 0; }
r[5]=r[14];
goto P_0c0700f8;
P_0c0700f8: /* original a006, guest PC 0x0c0700f8 */
if(!s->budget--) { s->failed_pc=0x0c0700f8u; return 0; }
goto P_0c070108;
P_0c0700fa: /* original 0009, guest PC 0x0c0700fa */
if(!s->budget--) { s->failed_pc=0x0c0700fau; return 0; }
return vf3_matrix_family(0x0c0700fcu,s,ram);
P_0c070108: /* original f059, guest PC 0x0c070108 */
if(!s->budget--) { s->failed_pc=0x0c070108u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07010a;
P_0c07010a: /* original f369, guest PC 0x0c07010a */
if(!s->budget--) { s->failed_pc=0x0c07010au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07010c;
P_0c07010c: /* original f159, guest PC 0x0c07010c */
if(!s->budget--) { s->failed_pc=0x0c07010cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07010e;
P_0c07010e: /* original f469, guest PC 0x0c07010e */
if(!s->budget--) { s->failed_pc=0x0c07010eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070110;
P_0c070110: /* original f031, guest PC 0x0c070110 */
if(!s->budget--) { s->failed_pc=0x0c070110u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070112;
P_0c070112: /* original f258, guest PC 0x0c070112 */
if(!s->budget--) { s->failed_pc=0x0c070112u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070114;
P_0c070114: /* original f568, guest PC 0x0c070114 */
if(!s->budget--) { s->failed_pc=0x0c070114u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070116;
P_0c070116: /* original f141, guest PC 0x0c070116 */
if(!s->budget--) { s->failed_pc=0x0c070116u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070118;
P_0c070118: /* original f251, guest PC 0x0c070118 */
if(!s->budget--) { s->failed_pc=0x0c070118u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07011a;
P_0c07011a: /* original 7408, guest PC 0x0c07011a */
if(!s->budget--) { s->failed_pc=0x0c07011au; return 0; }
r[4]+=0x00000008u;
goto P_0c07011c;
P_0c07011c: /* original f42a, guest PC 0x0c07011c */
if(!s->budget--) { s->failed_pc=0x0c07011cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07011e;
P_0c07011e: /* original f41b, guest PC 0x0c07011e */
if(!s->budget--) { s->failed_pc=0x0c07011eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070120;
P_0c070120: /* original f40b, guest PC 0x0c070120 */
if(!s->budget--) { s->failed_pc=0x0c070120u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070122;
P_0c070122: /* original 0009, guest PC 0x0c070122 */
if(!s->budget--) { s->failed_pc=0x0c070122u; return 0; }
goto P_0c070124;
P_0c070124: /* original 64f3, guest PC 0x0c070124 */
if(!s->budget--) { s->failed_pc=0x0c070124u; return 0; }
r[4]=r[15];
goto P_0c070126;
P_0c070126: /* original 7444, guest PC 0x0c070126 */
if(!s->budget--) { s->failed_pc=0x0c070126u; return 0; }
r[4]+=0x00000044u;
goto P_0c070128;
P_0c070128: /* original f049, guest PC 0x0c070128 */
if(!s->budget--) { s->failed_pc=0x0c070128u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07012a;
P_0c07012a: /* original f149, guest PC 0x0c07012a */
if(!s->budget--) { s->failed_pc=0x0c07012au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07012c;
P_0c07012c: /* original f249, guest PC 0x0c07012c */
if(!s->budget--) { s->failed_pc=0x0c07012cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07012e;
P_0c07012e: /* original f38d, guest PC 0x0c07012e */
if(!s->budget--) { s->failed_pc=0x0c07012eu; return 0; }
fr[3]=0;
goto P_0c070130;
P_0c070130: /* original f0ed, guest PC 0x0c070130 */
if(!s->budget--) { s->failed_pc=0x0c070130u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070132;
P_0c070132: /* original f03c, guest PC 0x0c070132 */
if(!s->budget--) { s->failed_pc=0x0c070132u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070134;
P_0c070134: /* original f06d, guest PC 0x0c070134 */
if(!s->budget--) { s->failed_pc=0x0c070134u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070136;
P_0c070136: /* original 0009, guest PC 0x0c070136 */
if(!s->budget--) { s->failed_pc=0x0c070136u; return 0; }
goto P_0c070138;
P_0c070138: /* original f38d, guest PC 0x0c070138 */
if(!s->budget--) { s->failed_pc=0x0c070138u; return 0; }
fr[3]=0;
goto P_0c07013a;
P_0c07013a: /* original fc0c, guest PC 0x0c07013a */
if(!s->budget--) { s->failed_pc=0x0c07013au; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c07013c;
P_0c07013c: /* original fc35, guest PC 0x0c07013c */
if(!s->budget--) { s->failed_pc=0x0c07013cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c07013e;
P_0c07013e: /* original 8902, guest PC 0x0c07013e */
if(!s->budget--) { s->failed_pc=0x0c07013eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070146; }
goto P_0c070140;
P_0c070140: /* original d303, guest PC 0x0c070140 */
if(!s->budget--) { s->failed_pc=0x0c070140u; return 0; }
r[3]=read(ram,0x0c070150u,4);
goto P_0c070142;
P_0c070142: /* original 432b, guest PC 0x0c070142 */
if(!s->budget--) { s->failed_pc=0x0c070142u; return 0; }
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
P_0c070144: /* original 0009, guest PC 0x0c070144 */
if(!s->budget--) { s->failed_pc=0x0c070144u; return 0; }
goto P_0c070146;
P_0c070146: /* original 64f3, guest PC 0x0c070146 */
if(!s->budget--) { s->failed_pc=0x0c070146u; return 0; }
r[4]=r[15];
goto P_0c070148;
P_0c070148: /* original 7444, guest PC 0x0c070148 */
if(!s->budget--) { s->failed_pc=0x0c070148u; return 0; }
r[4]+=0x00000044u;
goto P_0c07014a;
P_0c07014a: /* original 65b3, guest PC 0x0c07014a */
if(!s->budget--) { s->failed_pc=0x0c07014au; return 0; }
r[5]=r[11];
goto P_0c07014c;
P_0c07014c: /* original a002, guest PC 0x0c07014c */
if(!s->budget--) { s->failed_pc=0x0c07014cu; return 0; }
goto P_0c070154;
P_0c07014e: /* original 0009, guest PC 0x0c07014e */
if(!s->budget--) { s->failed_pc=0x0c07014eu; return 0; }
return vf3_matrix_family(0x0c070150u,s,ram);
P_0c070154: /* original f049, guest PC 0x0c070154 */
if(!s->budget--) { s->failed_pc=0x0c070154u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070156;
P_0c070156: /* original f549, guest PC 0x0c070156 */
if(!s->budget--) { s->failed_pc=0x0c070156u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070158;
P_0c070158: /* original f648, guest PC 0x0c070158 */
if(!s->budget--) { s->failed_pc=0x0c070158u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07015a;
P_0c07015a: /* original f859, guest PC 0x0c07015a */
if(!s->budget--) { s->failed_pc=0x0c07015au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07015c;
P_0c07015c: /* original f959, guest PC 0x0c07015c */
if(!s->budget--) { s->failed_pc=0x0c07015cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07015e;
P_0c07015e: /* original fa58, guest PC 0x0c07015e */
if(!s->budget--) { s->failed_pc=0x0c07015eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070160;
P_0c070160: /* original f35c, guest PC 0x0c070160 */
if(!s->budget--) { s->failed_pc=0x0c070160u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070162;
P_0c070162: /* original f382, guest PC 0x0c070162 */
if(!s->budget--) { s->failed_pc=0x0c070162u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070164;
P_0c070164: /* original f20c, guest PC 0x0c070164 */
if(!s->budget--) { s->failed_pc=0x0c070164u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070166;
P_0c070166: /* original f2a2, guest PC 0x0c070166 */
if(!s->budget--) { s->failed_pc=0x0c070166u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070168;
P_0c070168: /* original f16c, guest PC 0x0c070168 */
if(!s->budget--) { s->failed_pc=0x0c070168u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07016a;
P_0c07016a: /* original f192, guest PC 0x0c07016a */
if(!s->budget--) { s->failed_pc=0x0c07016au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07016c;
P_0c07016c: /* original f34d, guest PC 0x0c07016c */
if(!s->budget--) { s->failed_pc=0x0c07016cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c07016e;
P_0c07016e: /* original f39e, guest PC 0x0c07016e */
if(!s->budget--) { s->failed_pc=0x0c07016eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070170;
P_0c070170: /* original f24d, guest PC 0x0c070170 */
if(!s->budget--) { s->failed_pc=0x0c070170u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070172;
P_0c070172: /* original f06c, guest PC 0x0c070172 */
if(!s->budget--) { s->failed_pc=0x0c070172u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070174;
P_0c070174: /* original f28e, guest PC 0x0c070174 */
if(!s->budget--) { s->failed_pc=0x0c070174u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070176;
P_0c070176: /* original f14d, guest PC 0x0c070176 */
if(!s->budget--) { s->failed_pc=0x0c070176u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070178;
P_0c070178: /* original f05c, guest PC 0x0c070178 */
if(!s->budget--) { s->failed_pc=0x0c070178u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07017a;
P_0c07017a: /* original f1ae, guest PC 0x0c07017a */
if(!s->budget--) { s->failed_pc=0x0c07017au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07017c;
P_0c07017c: /* original f08d, guest PC 0x0c07017c */
if(!s->budget--) { s->failed_pc=0x0c07017cu; return 0; }
fr[0]=0;
goto P_0c07017e;
P_0c07017e: /* original f0ed, guest PC 0x0c07017e */
if(!s->budget--) { s->failed_pc=0x0c07017eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070180;
P_0c070180: /* original f03c, guest PC 0x0c070180 */
if(!s->budget--) { s->failed_pc=0x0c070180u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070182;
P_0c070182: /* original f06d, guest PC 0x0c070182 */
if(!s->budget--) { s->failed_pc=0x0c070182u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070184;
P_0c070184: /* original ff05, guest PC 0x0c070184 */
if(!s->budget--) { s->failed_pc=0x0c070184u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070186;
P_0c070186: /* original e00c, guest PC 0x0c070186 */
if(!s->budget--) { s->failed_pc=0x0c070186u; return 0; }
r[0]=0x0000000cu;
goto P_0c070188;
P_0c070188: /* original 8d03, guest PC 0x0c070188 */
if(!s->budget--) { s->failed_pc=0x0c070188u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070192; }
goto P_0c07018c;
P_0c07018a: /* original ff07, guest PC 0x0c07018a */
if(!s->budget--) { s->failed_pc=0x0c07018au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c07018c;
P_0c07018c: /* original d303, guest PC 0x0c07018c */
if(!s->budget--) { s->failed_pc=0x0c07018cu; return 0; }
r[3]=read(ram,0x0c07019cu,4);
goto P_0c07018e;
P_0c07018e: /* original 432b, guest PC 0x0c07018e */
if(!s->budget--) { s->failed_pc=0x0c07018eu; return 0; }
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
P_0c070190: /* original 0009, guest PC 0x0c070190 */
if(!s->budget--) { s->failed_pc=0x0c070190u; return 0; }
goto P_0c070192;
P_0c070192: /* original 64f3, guest PC 0x0c070192 */
if(!s->budget--) { s->failed_pc=0x0c070192u; return 0; }
r[4]=r[15];
goto P_0c070194;
P_0c070194: /* original 7444, guest PC 0x0c070194 */
if(!s->budget--) { s->failed_pc=0x0c070194u; return 0; }
r[4]+=0x00000044u;
goto P_0c070196;
P_0c070196: /* original 65b3, guest PC 0x0c070196 */
if(!s->budget--) { s->failed_pc=0x0c070196u; return 0; }
r[5]=r[11];
goto P_0c070198;
P_0c070198: /* original a002, guest PC 0x0c070198 */
if(!s->budget--) { s->failed_pc=0x0c070198u; return 0; }
goto P_0c0701a0;
P_0c07019a: /* original 0009, guest PC 0x0c07019a */
if(!s->budget--) { s->failed_pc=0x0c07019au; return 0; }
return vf3_matrix_family(0x0c07019cu,s,ram);
P_0c0701a0: /* original f049, guest PC 0x0c0701a0 */
if(!s->budget--) { s->failed_pc=0x0c0701a0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0701a2;
P_0c0701a2: /* original f149, guest PC 0x0c0701a2 */
if(!s->budget--) { s->failed_pc=0x0c0701a2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0701a4;
P_0c0701a4: /* original f249, guest PC 0x0c0701a4 */
if(!s->budget--) { s->failed_pc=0x0c0701a4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0701a6;
P_0c0701a6: /* original f38d, guest PC 0x0c0701a6 */
if(!s->budget--) { s->failed_pc=0x0c0701a6u; return 0; }
fr[3]=0;
goto P_0c0701a8;
P_0c0701a8: /* original f459, guest PC 0x0c0701a8 */
if(!s->budget--) { s->failed_pc=0x0c0701a8u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701aa;
P_0c0701aa: /* original f559, guest PC 0x0c0701aa */
if(!s->budget--) { s->failed_pc=0x0c0701aau; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701ac;
P_0c0701ac: /* original f659, guest PC 0x0c0701ac */
if(!s->budget--) { s->failed_pc=0x0c0701acu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701ae;
P_0c0701ae: /* original f78d, guest PC 0x0c0701ae */
if(!s->budget--) { s->failed_pc=0x0c0701aeu; return 0; }
fr[7]=0;
goto P_0c0701b0;
P_0c0701b0: /* original f4ed, guest PC 0x0c0701b0 */
if(!s->budget--) { s->failed_pc=0x0c0701b0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0701b2;
P_0c0701b2: /* original f07c, guest PC 0x0c0701b2 */
if(!s->budget--) { s->failed_pc=0x0c0701b2u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0701b4;
P_0c0701b4: /* original f38d, guest PC 0x0c0701b4 */
if(!s->budget--) { s->failed_pc=0x0c0701b4u; return 0; }
fr[3]=0;
goto P_0c0701b6;
P_0c0701b6: /* original f40c, guest PC 0x0c0701b6 */
if(!s->budget--) { s->failed_pc=0x0c0701b6u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0701b8;
P_0c0701b8: /* original f345, guest PC 0x0c0701b8 */
if(!s->budget--) { s->failed_pc=0x0c0701b8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0701ba;
P_0c0701ba: /* original 8902, guest PC 0x0c0701ba */
if(!s->budget--) { s->failed_pc=0x0c0701bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0701c2; }
goto P_0c0701bc;
P_0c0701bc: /* original d307, guest PC 0x0c0701bc */
if(!s->budget--) { s->failed_pc=0x0c0701bcu; return 0; }
r[3]=read(ram,0x0c0701dcu,4);
goto P_0c0701be;
P_0c0701be: /* original 432b, guest PC 0x0c0701be */
if(!s->budget--) { s->failed_pc=0x0c0701beu; return 0; }
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
P_0c0701c0: /* original 0009, guest PC 0x0c0701c0 */
if(!s->budget--) { s->failed_pc=0x0c0701c0u; return 0; }
goto P_0c0701c2;
P_0c0701c2: /* original ffc5, guest PC 0x0c0701c2 */
if(!s->budget--) { s->failed_pc=0x0c0701c2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c0701c4;
P_0c0701c4: /* original 8902, guest PC 0x0c0701c4 */
if(!s->budget--) { s->failed_pc=0x0c0701c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0701cc; }
goto P_0c0701c6;
P_0c0701c6: /* original d206, guest PC 0x0c0701c6 */
if(!s->budget--) { s->failed_pc=0x0c0701c6u; return 0; }
r[2]=read(ram,0x0c0701e0u,4);
goto P_0c0701c8;
P_0c0701c8: /* original 422b, guest PC 0x0c0701c8 */
if(!s->budget--) { s->failed_pc=0x0c0701c8u; return 0; }
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
P_0c0701ca: /* original 0009, guest PC 0x0c0701ca */
if(!s->budget--) { s->failed_pc=0x0c0701cau; return 0; }
goto P_0c0701cc;
P_0c0701cc: /* original f4cc, guest PC 0x0c0701cc */
if(!s->budget--) { s->failed_pc=0x0c0701ccu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c0701ce;
P_0c0701ce: /* original f4f1, guest PC 0x0c0701ce */
if(!s->budget--) { s->failed_pc=0x0c0701ceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0701d0;
P_0c0701d0: /* original 64f3, guest PC 0x0c0701d0 */
if(!s->budget--) { s->failed_pc=0x0c0701d0u; return 0; }
r[4]=r[15];
goto P_0c0701d2;
P_0c0701d2: /* original 65f3, guest PC 0x0c0701d2 */
if(!s->budget--) { s->failed_pc=0x0c0701d2u; return 0; }
r[5]=r[15];
goto P_0c0701d4;
P_0c0701d4: /* original 7444, guest PC 0x0c0701d4 */
if(!s->budget--) { s->failed_pc=0x0c0701d4u; return 0; }
r[4]+=0x00000044u;
goto P_0c0701d6;
P_0c0701d6: /* original 7544, guest PC 0x0c0701d6 */
if(!s->budget--) { s->failed_pc=0x0c0701d6u; return 0; }
r[5]+=0x00000044u;
goto P_0c0701d8;
P_0c0701d8: /* original a004, guest PC 0x0c0701d8 */
if(!s->budget--) { s->failed_pc=0x0c0701d8u; return 0; }
goto P_0c0701e4;
P_0c0701da: /* original 0009, guest PC 0x0c0701da */
if(!s->budget--) { s->failed_pc=0x0c0701dau; return 0; }
return vf3_matrix_family(0x0c0701dcu,s,ram);
P_0c0701e4: /* original f059, guest PC 0x0c0701e4 */
if(!s->budget--) { s->failed_pc=0x0c0701e4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701e6;
P_0c0701e6: /* original f159, guest PC 0x0c0701e6 */
if(!s->budget--) { s->failed_pc=0x0c0701e6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701e8;
P_0c0701e8: /* original f259, guest PC 0x0c0701e8 */
if(!s->budget--) { s->failed_pc=0x0c0701e8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0701ea;
P_0c0701ea: /* original f38d, guest PC 0x0c0701ea */
if(!s->budget--) { s->failed_pc=0x0c0701eau; return 0; }
fr[3]=0;
goto P_0c0701ec;
P_0c0701ec: /* original f0ed, guest PC 0x0c0701ec */
if(!s->budget--) { s->failed_pc=0x0c0701ecu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0701ee;
P_0c0701ee: /* original f37d, guest PC 0x0c0701ee */
if(!s->budget--) { s->failed_pc=0x0c0701eeu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0701f0;
P_0c0701f0: /* original f342, guest PC 0x0c0701f0 */
if(!s->budget--) { s->failed_pc=0x0c0701f0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0701f2;
P_0c0701f2: /* original 740c, guest PC 0x0c0701f2 */
if(!s->budget--) { s->failed_pc=0x0c0701f2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0701f4;
P_0c0701f4: /* original f232, guest PC 0x0c0701f4 */
if(!s->budget--) { s->failed_pc=0x0c0701f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0701f6;
P_0c0701f6: /* original f132, guest PC 0x0c0701f6 */
if(!s->budget--) { s->failed_pc=0x0c0701f6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0701f8;
P_0c0701f8: /* original f032, guest PC 0x0c0701f8 */
if(!s->budget--) { s->failed_pc=0x0c0701f8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0701fa;
P_0c0701fa: /* original f42b, guest PC 0x0c0701fa */
if(!s->budget--) { s->failed_pc=0x0c0701fau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0701fc;
P_0c0701fc: /* original f41b, guest PC 0x0c0701fc */
if(!s->budget--) { s->failed_pc=0x0c0701fcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0701fe;
P_0c0701fe: /* original f40b, guest PC 0x0c0701fe */
if(!s->budget--) { s->failed_pc=0x0c0701feu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070200;
P_0c070200: /* original 65f3, guest PC 0x0c070200 */
if(!s->budget--) { s->failed_pc=0x0c070200u; return 0; }
r[5]=r[15];
goto P_0c070202;
P_0c070202: /* original 64e3, guest PC 0x0c070202 */
if(!s->budget--) { s->failed_pc=0x0c070202u; return 0; }
r[4]=r[14];
goto P_0c070204;
P_0c070204: /* original 7544, guest PC 0x0c070204 */
if(!s->budget--) { s->failed_pc=0x0c070204u; return 0; }
r[5]+=0x00000044u;
goto P_0c070206;
P_0c070206: /* original f049, guest PC 0x0c070206 */
if(!s->budget--) { s->failed_pc=0x0c070206u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070208;
P_0c070208: /* original f359, guest PC 0x0c070208 */
if(!s->budget--) { s->failed_pc=0x0c070208u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07020a;
P_0c07020a: /* original f149, guest PC 0x0c07020a */
if(!s->budget--) { s->failed_pc=0x0c07020au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07020c;
P_0c07020c: /* original f459, guest PC 0x0c07020c */
if(!s->budget--) { s->failed_pc=0x0c07020cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07020e;
P_0c07020e: /* original f249, guest PC 0x0c07020e */
if(!s->budget--) { s->failed_pc=0x0c07020eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070210;
P_0c070210: /* original f559, guest PC 0x0c070210 */
if(!s->budget--) { s->failed_pc=0x0c070210u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070212;
P_0c070212: /* original f030, guest PC 0x0c070212 */
if(!s->budget--) { s->failed_pc=0x0c070212u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070214;
P_0c070214: /* original f250, guest PC 0x0c070214 */
if(!s->budget--) { s->failed_pc=0x0c070214u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070216;
P_0c070216: /* original f140, guest PC 0x0c070216 */
if(!s->budget--) { s->failed_pc=0x0c070216u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070218;
P_0c070218: /* original f42b, guest PC 0x0c070218 */
if(!s->budget--) { s->failed_pc=0x0c070218u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07021a;
P_0c07021a: /* original f41b, guest PC 0x0c07021a */
if(!s->budget--) { s->failed_pc=0x0c07021au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07021c;
P_0c07021c: /* original f40b, guest PC 0x0c07021c */
if(!s->budget--) { s->failed_pc=0x0c07021cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07021e;
P_0c07021e: /* original 0009, guest PC 0x0c07021e */
if(!s->budget--) { s->failed_pc=0x0c07021eu; return 0; }
goto P_0c070220;
P_0c070220: /* original d306, guest PC 0x0c070220 */
if(!s->budget--) { s->failed_pc=0x0c070220u; return 0; }
r[3]=read(ram,0x0c07023cu,4);
goto P_0c070222;
P_0c070222: /* original 432b, guest PC 0x0c070222 */
if(!s->budget--) { s->failed_pc=0x0c070222u; return 0; }
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
P_0c070224: /* original 0009, guest PC 0x0c070224 */
if(!s->budget--) { s->failed_pc=0x0c070224u; return 0; }
goto P_0c070226;
P_0c070226: /* original fe45, guest PC 0x0c070226 */
if(!s->budget--) { s->failed_pc=0x0c070226u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c070228;
P_0c070228: /* original 8902, guest PC 0x0c070228 */
if(!s->budget--) { s->failed_pc=0x0c070228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070230; }
goto P_0c07022a;
P_0c07022a: /* original d204, guest PC 0x0c07022a */
if(!s->budget--) { s->failed_pc=0x0c07022au; return 0; }
r[2]=read(ram,0x0c07023cu,4);
goto P_0c07022c;
P_0c07022c: /* original 422b, guest PC 0x0c07022c */
if(!s->budget--) { s->failed_pc=0x0c07022cu; return 0; }
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
P_0c07022e: /* original 0009, guest PC 0x0c07022e */
if(!s->budget--) { s->failed_pc=0x0c07022eu; return 0; }
goto P_0c070230;
P_0c070230: /* original 64f3, guest PC 0x0c070230 */
if(!s->budget--) { s->failed_pc=0x0c070230u; return 0; }
r[4]=r[15];
goto P_0c070232;
P_0c070232: /* original 7438, guest PC 0x0c070232 */
if(!s->budget--) { s->failed_pc=0x0c070232u; return 0; }
r[4]+=0x00000038u;
goto P_0c070234;
P_0c070234: /* original 65b3, guest PC 0x0c070234 */
if(!s->budget--) { s->failed_pc=0x0c070234u; return 0; }
r[5]=r[11];
goto P_0c070236;
P_0c070236: /* original a003, guest PC 0x0c070236 */
if(!s->budget--) { s->failed_pc=0x0c070236u; return 0; }
goto P_0c070240;
P_0c070238: /* original 0009, guest PC 0x0c070238 */
if(!s->budget--) { s->failed_pc=0x0c070238u; return 0; }
return vf3_matrix_family(0x0c07023au,s,ram);
P_0c070240: /* original f059, guest PC 0x0c070240 */
if(!s->budget--) { s->failed_pc=0x0c070240u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070242;
P_0c070242: /* original f159, guest PC 0x0c070242 */
if(!s->budget--) { s->failed_pc=0x0c070242u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070244;
P_0c070244: /* original f259, guest PC 0x0c070244 */
if(!s->budget--) { s->failed_pc=0x0c070244u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070246;
P_0c070246: /* original 740c, guest PC 0x0c070246 */
if(!s->budget--) { s->failed_pc=0x0c070246u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070248;
P_0c070248: /* original f242, guest PC 0x0c070248 */
if(!s->budget--) { s->failed_pc=0x0c070248u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c07024a;
P_0c07024a: /* original f142, guest PC 0x0c07024a */
if(!s->budget--) { s->failed_pc=0x0c07024au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c07024c;
P_0c07024c: /* original f042, guest PC 0x0c07024c */
if(!s->budget--) { s->failed_pc=0x0c07024cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c07024e;
P_0c07024e: /* original f42b, guest PC 0x0c07024e */
if(!s->budget--) { s->failed_pc=0x0c07024eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070250;
P_0c070250: /* original f41b, guest PC 0x0c070250 */
if(!s->budget--) { s->failed_pc=0x0c070250u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070252;
P_0c070252: /* original f40b, guest PC 0x0c070252 */
if(!s->budget--) { s->failed_pc=0x0c070252u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070254;
P_0c070254: /* original 65f3, guest PC 0x0c070254 */
if(!s->budget--) { s->failed_pc=0x0c070254u; return 0; }
r[5]=r[15];
goto P_0c070256;
P_0c070256: /* original 64f3, guest PC 0x0c070256 */
if(!s->budget--) { s->failed_pc=0x0c070256u; return 0; }
r[4]=r[15];
goto P_0c070258;
P_0c070258: /* original 66f3, guest PC 0x0c070258 */
if(!s->budget--) { s->failed_pc=0x0c070258u; return 0; }
r[6]=r[15];
goto P_0c07025a;
P_0c07025a: /* original 7438, guest PC 0x0c07025a */
if(!s->budget--) { s->failed_pc=0x0c07025au; return 0; }
r[4]+=0x00000038u;
goto P_0c07025c;
P_0c07025c: /* original 7638, guest PC 0x0c07025c */
if(!s->budget--) { s->failed_pc=0x0c07025cu; return 0; }
r[6]+=0x00000038u;
goto P_0c07025e;
P_0c07025e: /* original 7544, guest PC 0x0c07025e */
if(!s->budget--) { s->failed_pc=0x0c07025eu; return 0; }
r[5]+=0x00000044u;
goto P_0c070260;
P_0c070260: /* original f059, guest PC 0x0c070260 */
if(!s->budget--) { s->failed_pc=0x0c070260u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070262;
P_0c070262: /* original f369, guest PC 0x0c070262 */
if(!s->budget--) { s->failed_pc=0x0c070262u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070264;
P_0c070264: /* original f159, guest PC 0x0c070264 */
if(!s->budget--) { s->failed_pc=0x0c070264u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070266;
P_0c070266: /* original f469, guest PC 0x0c070266 */
if(!s->budget--) { s->failed_pc=0x0c070266u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070268;
P_0c070268: /* original f031, guest PC 0x0c070268 */
if(!s->budget--) { s->failed_pc=0x0c070268u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07026a;
P_0c07026a: /* original f258, guest PC 0x0c07026a */
if(!s->budget--) { s->failed_pc=0x0c07026au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c07026c;
P_0c07026c: /* original f568, guest PC 0x0c07026c */
if(!s->budget--) { s->failed_pc=0x0c07026cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c07026e;
P_0c07026e: /* original f141, guest PC 0x0c07026e */
if(!s->budget--) { s->failed_pc=0x0c07026eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070270;
P_0c070270: /* original f251, guest PC 0x0c070270 */
if(!s->budget--) { s->failed_pc=0x0c070270u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070272;
P_0c070272: /* original 7408, guest PC 0x0c070272 */
if(!s->budget--) { s->failed_pc=0x0c070272u; return 0; }
r[4]+=0x00000008u;
goto P_0c070274;
P_0c070274: /* original f42a, guest PC 0x0c070274 */
if(!s->budget--) { s->failed_pc=0x0c070274u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070276;
P_0c070276: /* original f41b, guest PC 0x0c070276 */
if(!s->budget--) { s->failed_pc=0x0c070276u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070278;
P_0c070278: /* original f40b, guest PC 0x0c070278 */
if(!s->budget--) { s->failed_pc=0x0c070278u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07027a;
P_0c07027a: /* original 0009, guest PC 0x0c07027a */
if(!s->budget--) { s->failed_pc=0x0c07027au; return 0; }
goto P_0c07027c;
P_0c07027c: /* original e00c, guest PC 0x0c07027c */
if(!s->budget--) { s->failed_pc=0x0c07027cu; return 0; }
r[0]=0x0000000cu;
goto P_0c07027e;
P_0c07027e: /* original f4fc, guest PC 0x0c07027e */
if(!s->budget--) { s->failed_pc=0x0c07027eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070280;
P_0c070280: /* original f3f6, guest PC 0x0c070280 */
if(!s->budget--) { s->failed_pc=0x0c070280u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070282;
P_0c070282: /* original 64f3, guest PC 0x0c070282 */
if(!s->budget--) { s->failed_pc=0x0c070282u; return 0; }
r[4]=r[15];
goto P_0c070284;
P_0c070284: /* original 65f3, guest PC 0x0c070284 */
if(!s->budget--) { s->failed_pc=0x0c070284u; return 0; }
r[5]=r[15];
goto P_0c070286;
P_0c070286: /* original 7438, guest PC 0x0c070286 */
if(!s->budget--) { s->failed_pc=0x0c070286u; return 0; }
r[4]+=0x00000038u;
goto P_0c070288;
P_0c070288: /* original f431, guest PC 0x0c070288 */
if(!s->budget--) { s->failed_pc=0x0c070288u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c07028a;
P_0c07028a: /* original 7538, guest PC 0x0c07028a */
if(!s->budget--) { s->failed_pc=0x0c07028au; return 0; }
r[5]+=0x00000038u;
goto P_0c07028c;
P_0c07028c: /* original f059, guest PC 0x0c07028c */
if(!s->budget--) { s->failed_pc=0x0c07028cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07028e;
P_0c07028e: /* original f159, guest PC 0x0c07028e */
if(!s->budget--) { s->failed_pc=0x0c07028eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070290;
P_0c070290: /* original f259, guest PC 0x0c070290 */
if(!s->budget--) { s->failed_pc=0x0c070290u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070292;
P_0c070292: /* original f38d, guest PC 0x0c070292 */
if(!s->budget--) { s->failed_pc=0x0c070292u; return 0; }
fr[3]=0;
goto P_0c070294;
P_0c070294: /* original f0ed, guest PC 0x0c070294 */
if(!s->budget--) { s->failed_pc=0x0c070294u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070296;
P_0c070296: /* original f37d, guest PC 0x0c070296 */
if(!s->budget--) { s->failed_pc=0x0c070296u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070298;
P_0c070298: /* original f342, guest PC 0x0c070298 */
if(!s->budget--) { s->failed_pc=0x0c070298u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07029a;
P_0c07029a: /* original 740c, guest PC 0x0c07029a */
if(!s->budget--) { s->failed_pc=0x0c07029au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07029c;
P_0c07029c: /* original f232, guest PC 0x0c07029c */
if(!s->budget--) { s->failed_pc=0x0c07029cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07029e;
P_0c07029e: /* original f132, guest PC 0x0c07029e */
if(!s->budget--) { s->failed_pc=0x0c07029eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0702a0;
P_0c0702a0: /* original f032, guest PC 0x0c0702a0 */
if(!s->budget--) { s->failed_pc=0x0c0702a0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0702a2;
P_0c0702a2: /* original f42b, guest PC 0x0c0702a2 */
if(!s->budget--) { s->failed_pc=0x0c0702a2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702a4;
P_0c0702a4: /* original f41b, guest PC 0x0c0702a4 */
if(!s->budget--) { s->failed_pc=0x0c0702a4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702a6;
P_0c0702a6: /* original f40b, guest PC 0x0c0702a6 */
if(!s->budget--) { s->failed_pc=0x0c0702a6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702a8;
P_0c0702a8: /* original 64f3, guest PC 0x0c0702a8 */
if(!s->budget--) { s->failed_pc=0x0c0702a8u; return 0; }
r[4]=r[15];
goto P_0c0702aa;
P_0c0702aa: /* original 65f3, guest PC 0x0c0702aa */
if(!s->budget--) { s->failed_pc=0x0c0702aau; return 0; }
r[5]=r[15];
goto P_0c0702ac;
P_0c0702ac: /* original 7444, guest PC 0x0c0702ac */
if(!s->budget--) { s->failed_pc=0x0c0702acu; return 0; }
r[4]+=0x00000044u;
goto P_0c0702ae;
P_0c0702ae: /* original 7538, guest PC 0x0c0702ae */
if(!s->budget--) { s->failed_pc=0x0c0702aeu; return 0; }
r[5]+=0x00000038u;
goto P_0c0702b0;
P_0c0702b0: /* original f049, guest PC 0x0c0702b0 */
if(!s->budget--) { s->failed_pc=0x0c0702b0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b2;
P_0c0702b2: /* original f359, guest PC 0x0c0702b2 */
if(!s->budget--) { s->failed_pc=0x0c0702b2u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b4;
P_0c0702b4: /* original f149, guest PC 0x0c0702b4 */
if(!s->budget--) { s->failed_pc=0x0c0702b4u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b6;
P_0c0702b6: /* original f459, guest PC 0x0c0702b6 */
if(!s->budget--) { s->failed_pc=0x0c0702b6u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b8;
P_0c0702b8: /* original f249, guest PC 0x0c0702b8 */
if(!s->budget--) { s->failed_pc=0x0c0702b8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702ba;
P_0c0702ba: /* original f559, guest PC 0x0c0702ba */
if(!s->budget--) { s->failed_pc=0x0c0702bau; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702bc;
P_0c0702bc: /* original f030, guest PC 0x0c0702bc */
if(!s->budget--) { s->failed_pc=0x0c0702bcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0702be;
P_0c0702be: /* original f250, guest PC 0x0c0702be */
if(!s->budget--) { s->failed_pc=0x0c0702beu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0702c0;
P_0c0702c0: /* original f140, guest PC 0x0c0702c0 */
if(!s->budget--) { s->failed_pc=0x0c0702c0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0702c2;
P_0c0702c2: /* original f42b, guest PC 0x0c0702c2 */
if(!s->budget--) { s->failed_pc=0x0c0702c2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702c4;
P_0c0702c4: /* original f41b, guest PC 0x0c0702c4 */
if(!s->budget--) { s->failed_pc=0x0c0702c4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702c6;
P_0c0702c6: /* original f40b, guest PC 0x0c0702c6 */
if(!s->budget--) { s->failed_pc=0x0c0702c6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702c8;
P_0c0702c8: /* original 65f3, guest PC 0x0c0702c8 */
if(!s->budget--) { s->failed_pc=0x0c0702c8u; return 0; }
r[5]=r[15];
goto P_0c0702ca;
P_0c0702ca: /* original 64e3, guest PC 0x0c0702ca */
if(!s->budget--) { s->failed_pc=0x0c0702cau; return 0; }
r[4]=r[14];
goto P_0c0702cc;
P_0c0702cc: /* original 7544, guest PC 0x0c0702cc */
if(!s->budget--) { s->failed_pc=0x0c0702ccu; return 0; }
r[5]+=0x00000044u;
goto P_0c0702ce;
P_0c0702ce: /* original 66a3, guest PC 0x0c0702ce */
if(!s->budget--) { s->failed_pc=0x0c0702ceu; return 0; }
r[6]=r[10];
goto P_0c0702d0;
P_0c0702d0: /* original f059, guest PC 0x0c0702d0 */
if(!s->budget--) { s->failed_pc=0x0c0702d0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d2;
P_0c0702d2: /* original f369, guest PC 0x0c0702d2 */
if(!s->budget--) { s->failed_pc=0x0c0702d2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d4;
P_0c0702d4: /* original f159, guest PC 0x0c0702d4 */
if(!s->budget--) { s->failed_pc=0x0c0702d4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d6;
P_0c0702d6: /* original f469, guest PC 0x0c0702d6 */
if(!s->budget--) { s->failed_pc=0x0c0702d6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d8;
P_0c0702d8: /* original f259, guest PC 0x0c0702d8 */
if(!s->budget--) { s->failed_pc=0x0c0702d8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702da;
P_0c0702da: /* original f569, guest PC 0x0c0702da */
if(!s->budget--) { s->failed_pc=0x0c0702dau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702dc;
P_0c0702dc: /* original 740c, guest PC 0x0c0702dc */
if(!s->budget--) { s->failed_pc=0x0c0702dcu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0702de;
P_0c0702de: /* original f030, guest PC 0x0c0702de */
if(!s->budget--) { s->failed_pc=0x0c0702deu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0702e0;
P_0c0702e0: /* original f250, guest PC 0x0c0702e0 */
if(!s->budget--) { s->failed_pc=0x0c0702e0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0702e2;
P_0c0702e2: /* original f140, guest PC 0x0c0702e2 */
if(!s->budget--) { s->failed_pc=0x0c0702e2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0702e4;
P_0c0702e4: /* original f42b, guest PC 0x0c0702e4 */
if(!s->budget--) { s->failed_pc=0x0c0702e4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702e6;
P_0c0702e6: /* original f41b, guest PC 0x0c0702e6 */
if(!s->budget--) { s->failed_pc=0x0c0702e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702e8;
P_0c0702e8: /* original f40b, guest PC 0x0c0702e8 */
if(!s->budget--) { s->failed_pc=0x0c0702e8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702ea;
P_0c0702ea: /* original 0009, guest PC 0x0c0702ea */
if(!s->budget--) { s->failed_pc=0x0c0702eau; return 0; }
goto P_0c0702ec;
P_0c0702ec: /* original 64f3, guest PC 0x0c0702ec */
if(!s->budget--) { s->failed_pc=0x0c0702ecu; return 0; }
r[4]=r[15];
goto P_0c0702ee;
P_0c0702ee: /* original 7444, guest PC 0x0c0702ee */
if(!s->budget--) { s->failed_pc=0x0c0702eeu; return 0; }
r[4]+=0x00000044u;
goto P_0c0702f0;
P_0c0702f0: /* original 6693, guest PC 0x0c0702f0 */
if(!s->budget--) { s->failed_pc=0x0c0702f0u; return 0; }
r[6]=r[9];
goto P_0c0702f2;
P_0c0702f2: /* original 65e3, guest PC 0x0c0702f2 */
if(!s->budget--) { s->failed_pc=0x0c0702f2u; return 0; }
r[5]=r[14];
goto P_0c0702f4;
P_0c0702f4: /* original f059, guest PC 0x0c0702f4 */
if(!s->budget--) { s->failed_pc=0x0c0702f4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702f6;
P_0c0702f6: /* original f369, guest PC 0x0c0702f6 */
if(!s->budget--) { s->failed_pc=0x0c0702f6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702f8;
P_0c0702f8: /* original f159, guest PC 0x0c0702f8 */
if(!s->budget--) { s->failed_pc=0x0c0702f8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702fa;
P_0c0702fa: /* original f469, guest PC 0x0c0702fa */
if(!s->budget--) { s->failed_pc=0x0c0702fau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702fc;
P_0c0702fc: /* original f031, guest PC 0x0c0702fc */
if(!s->budget--) { s->failed_pc=0x0c0702fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0702fe;
P_0c0702fe: /* original f258, guest PC 0x0c0702fe */
if(!s->budget--) { s->failed_pc=0x0c0702feu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070300;
P_0c070300: /* original f568, guest PC 0x0c070300 */
if(!s->budget--) { s->failed_pc=0x0c070300u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070302;
P_0c070302: /* original f141, guest PC 0x0c070302 */
if(!s->budget--) { s->failed_pc=0x0c070302u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070304;
P_0c070304: /* original f251, guest PC 0x0c070304 */
if(!s->budget--) { s->failed_pc=0x0c070304u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070306;
P_0c070306: /* original 7408, guest PC 0x0c070306 */
if(!s->budget--) { s->failed_pc=0x0c070306u; return 0; }
r[4]+=0x00000008u;
goto P_0c070308;
P_0c070308: /* original f42a, guest PC 0x0c070308 */
if(!s->budget--) { s->failed_pc=0x0c070308u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07030a;
P_0c07030a: /* original f41b, guest PC 0x0c07030a */
if(!s->budget--) { s->failed_pc=0x0c07030au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07030c;
P_0c07030c: /* original f40b, guest PC 0x0c07030c */
if(!s->budget--) { s->failed_pc=0x0c07030cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07030e;
P_0c07030e: /* original 0009, guest PC 0x0c07030e */
if(!s->budget--) { s->failed_pc=0x0c07030eu; return 0; }
goto P_0c070310;
P_0c070310: /* original 64f3, guest PC 0x0c070310 */
if(!s->budget--) { s->failed_pc=0x0c070310u; return 0; }
r[4]=r[15];
goto P_0c070312;
P_0c070312: /* original 7444, guest PC 0x0c070312 */
if(!s->budget--) { s->failed_pc=0x0c070312u; return 0; }
r[4]+=0x00000044u;
goto P_0c070314;
P_0c070314: /* original f049, guest PC 0x0c070314 */
if(!s->budget--) { s->failed_pc=0x0c070314u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070316;
P_0c070316: /* original f149, guest PC 0x0c070316 */
if(!s->budget--) { s->failed_pc=0x0c070316u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070318;
P_0c070318: /* original f249, guest PC 0x0c070318 */
if(!s->budget--) { s->failed_pc=0x0c070318u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07031a;
P_0c07031a: /* original f38d, guest PC 0x0c07031a */
if(!s->budget--) { s->failed_pc=0x0c07031au; return 0; }
fr[3]=0;
goto P_0c07031c;
P_0c07031c: /* original f0ed, guest PC 0x0c07031c */
if(!s->budget--) { s->failed_pc=0x0c07031cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07031e;
P_0c07031e: /* original f03c, guest PC 0x0c07031e */
if(!s->budget--) { s->failed_pc=0x0c07031eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070320;
P_0c070320: /* original f06d, guest PC 0x0c070320 */
if(!s->budget--) { s->failed_pc=0x0c070320u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070322;
P_0c070322: /* original 0009, guest PC 0x0c070322 */
if(!s->budget--) { s->failed_pc=0x0c070322u; return 0; }
goto P_0c070324;
P_0c070324: /* original f38d, guest PC 0x0c070324 */
if(!s->budget--) { s->failed_pc=0x0c070324u; return 0; }
fr[3]=0;
goto P_0c070326;
P_0c070326: /* original f035, guest PC 0x0c070326 */
if(!s->budget--) { s->failed_pc=0x0c070326u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070328;
P_0c070328: /* original e014, guest PC 0x0c070328 */
if(!s->budget--) { s->failed_pc=0x0c070328u; return 0; }
r[0]=0x00000014u;
goto P_0c07032a;
P_0c07032a: /* original 8d03, guest PC 0x0c07032a */
if(!s->budget--) { s->failed_pc=0x0c07032au; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070334; }
goto P_0c07032e;
P_0c07032c: /* original ff07, guest PC 0x0c07032c */
if(!s->budget--) { s->failed_pc=0x0c07032cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c07032e;
P_0c07032e: /* original d304, guest PC 0x0c07032e */
if(!s->budget--) { s->failed_pc=0x0c07032eu; return 0; }
r[3]=read(ram,0x0c070340u,4);
goto P_0c070330;
P_0c070330: /* original 432b, guest PC 0x0c070330 */
if(!s->budget--) { s->failed_pc=0x0c070330u; return 0; }
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
P_0c070332: /* original 0009, guest PC 0x0c070332 */
if(!s->budget--) { s->failed_pc=0x0c070332u; return 0; }
goto P_0c070334;
P_0c070334: /* original 64f3, guest PC 0x0c070334 */
if(!s->budget--) { s->failed_pc=0x0c070334u; return 0; }
r[4]=r[15];
goto P_0c070336;
P_0c070336: /* original 7444, guest PC 0x0c070336 */
if(!s->budget--) { s->failed_pc=0x0c070336u; return 0; }
r[4]+=0x00000044u;
goto P_0c070338;
P_0c070338: /* original 65c3, guest PC 0x0c070338 */
if(!s->budget--) { s->failed_pc=0x0c070338u; return 0; }
r[5]=r[12];
goto P_0c07033a;
P_0c07033a: /* original a003, guest PC 0x0c07033a */
if(!s->budget--) { s->failed_pc=0x0c07033au; return 0; }
goto P_0c070344;
P_0c07033c: /* original 0009, guest PC 0x0c07033c */
if(!s->budget--) { s->failed_pc=0x0c07033cu; return 0; }
return vf3_matrix_family(0x0c07033eu,s,ram);
P_0c070344: /* original f049, guest PC 0x0c070344 */
if(!s->budget--) { s->failed_pc=0x0c070344u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070346;
P_0c070346: /* original f549, guest PC 0x0c070346 */
if(!s->budget--) { s->failed_pc=0x0c070346u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070348;
P_0c070348: /* original f648, guest PC 0x0c070348 */
if(!s->budget--) { s->failed_pc=0x0c070348u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07034a;
P_0c07034a: /* original f859, guest PC 0x0c07034a */
if(!s->budget--) { s->failed_pc=0x0c07034au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07034c;
P_0c07034c: /* original f959, guest PC 0x0c07034c */
if(!s->budget--) { s->failed_pc=0x0c07034cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07034e;
P_0c07034e: /* original fa58, guest PC 0x0c07034e */
if(!s->budget--) { s->failed_pc=0x0c07034eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070350;
P_0c070350: /* original f35c, guest PC 0x0c070350 */
if(!s->budget--) { s->failed_pc=0x0c070350u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070352;
P_0c070352: /* original f382, guest PC 0x0c070352 */
if(!s->budget--) { s->failed_pc=0x0c070352u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070354;
P_0c070354: /* original f20c, guest PC 0x0c070354 */
if(!s->budget--) { s->failed_pc=0x0c070354u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070356;
P_0c070356: /* original f2a2, guest PC 0x0c070356 */
if(!s->budget--) { s->failed_pc=0x0c070356u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070358;
P_0c070358: /* original f16c, guest PC 0x0c070358 */
if(!s->budget--) { s->failed_pc=0x0c070358u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07035a;
P_0c07035a: /* original f192, guest PC 0x0c07035a */
if(!s->budget--) { s->failed_pc=0x0c07035au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07035c;
P_0c07035c: /* original f34d, guest PC 0x0c07035c */
if(!s->budget--) { s->failed_pc=0x0c07035cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c07035e;
P_0c07035e: /* original f39e, guest PC 0x0c07035e */
if(!s->budget--) { s->failed_pc=0x0c07035eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070360;
P_0c070360: /* original f24d, guest PC 0x0c070360 */
if(!s->budget--) { s->failed_pc=0x0c070360u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070362;
P_0c070362: /* original f06c, guest PC 0x0c070362 */
if(!s->budget--) { s->failed_pc=0x0c070362u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070364;
P_0c070364: /* original f28e, guest PC 0x0c070364 */
if(!s->budget--) { s->failed_pc=0x0c070364u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070366;
P_0c070366: /* original f14d, guest PC 0x0c070366 */
if(!s->budget--) { s->failed_pc=0x0c070366u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070368;
P_0c070368: /* original f05c, guest PC 0x0c070368 */
if(!s->budget--) { s->failed_pc=0x0c070368u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07036a;
P_0c07036a: /* original f1ae, guest PC 0x0c07036a */
if(!s->budget--) { s->failed_pc=0x0c07036au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07036c;
P_0c07036c: /* original f08d, guest PC 0x0c07036c */
if(!s->budget--) { s->failed_pc=0x0c07036cu; return 0; }
fr[0]=0;
goto P_0c07036e;
P_0c07036e: /* original f0ed, guest PC 0x0c07036e */
if(!s->budget--) { s->failed_pc=0x0c07036eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070370;
P_0c070370: /* original f03c, guest PC 0x0c070370 */
if(!s->budget--) { s->failed_pc=0x0c070370u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070372;
P_0c070372: /* original f06d, guest PC 0x0c070372 */
if(!s->budget--) { s->failed_pc=0x0c070372u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070374;
P_0c070374: /* original fc0c, guest PC 0x0c070374 */
if(!s->budget--) { s->failed_pc=0x0c070374u; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070376;
P_0c070376: /* original ffc5, guest PC 0x0c070376 */
if(!s->budget--) { s->failed_pc=0x0c070376u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070378;
P_0c070378: /* original 8902, guest PC 0x0c070378 */
if(!s->budget--) { s->failed_pc=0x0c070378u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070380; }
goto P_0c07037a;
P_0c07037a: /* original d304, guest PC 0x0c07037a */
if(!s->budget--) { s->failed_pc=0x0c07037au; return 0; }
r[3]=read(ram,0x0c07038cu,4);
goto P_0c07037c;
P_0c07037c: /* original 432b, guest PC 0x0c07037c */
if(!s->budget--) { s->failed_pc=0x0c07037cu; return 0; }
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
P_0c07037e: /* original 0009, guest PC 0x0c07037e */
if(!s->budget--) { s->failed_pc=0x0c07037eu; return 0; }
goto P_0c070380;
P_0c070380: /* original 64f3, guest PC 0x0c070380 */
if(!s->budget--) { s->failed_pc=0x0c070380u; return 0; }
r[4]=r[15];
goto P_0c070382;
P_0c070382: /* original 7444, guest PC 0x0c070382 */
if(!s->budget--) { s->failed_pc=0x0c070382u; return 0; }
r[4]+=0x00000044u;
goto P_0c070384;
P_0c070384: /* original 65c3, guest PC 0x0c070384 */
if(!s->budget--) { s->failed_pc=0x0c070384u; return 0; }
r[5]=r[12];
goto P_0c070386;
P_0c070386: /* original a003, guest PC 0x0c070386 */
if(!s->budget--) { s->failed_pc=0x0c070386u; return 0; }
goto P_0c070390;
P_0c070388: /* original 0009, guest PC 0x0c070388 */
if(!s->budget--) { s->failed_pc=0x0c070388u; return 0; }
return vf3_matrix_family(0x0c07038au,s,ram);
P_0c070390: /* original f049, guest PC 0x0c070390 */
if(!s->budget--) { s->failed_pc=0x0c070390u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070392;
P_0c070392: /* original f149, guest PC 0x0c070392 */
if(!s->budget--) { s->failed_pc=0x0c070392u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070394;
P_0c070394: /* original f249, guest PC 0x0c070394 */
if(!s->budget--) { s->failed_pc=0x0c070394u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070396;
P_0c070396: /* original f38d, guest PC 0x0c070396 */
if(!s->budget--) { s->failed_pc=0x0c070396u; return 0; }
fr[3]=0;
goto P_0c070398;
P_0c070398: /* original f459, guest PC 0x0c070398 */
if(!s->budget--) { s->failed_pc=0x0c070398u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039a;
P_0c07039a: /* original f559, guest PC 0x0c07039a */
if(!s->budget--) { s->failed_pc=0x0c07039au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039c;
P_0c07039c: /* original f659, guest PC 0x0c07039c */
if(!s->budget--) { s->failed_pc=0x0c07039cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039e;
P_0c07039e: /* original f78d, guest PC 0x0c07039e */
if(!s->budget--) { s->failed_pc=0x0c07039eu; return 0; }
fr[7]=0;
goto P_0c0703a0;
P_0c0703a0: /* original f4ed, guest PC 0x0c0703a0 */
if(!s->budget--) { s->failed_pc=0x0c0703a0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0703a2;
P_0c0703a2: /* original f07c, guest PC 0x0c0703a2 */
if(!s->budget--) { s->failed_pc=0x0c0703a2u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0703a4;
P_0c0703a4: /* original f38d, guest PC 0x0c0703a4 */
if(!s->budget--) { s->failed_pc=0x0c0703a4u; return 0; }
fr[3]=0;
goto P_0c0703a6;
P_0c0703a6: /* original f40c, guest PC 0x0c0703a6 */
if(!s->budget--) { s->failed_pc=0x0c0703a6u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0703a8;
P_0c0703a8: /* original f345, guest PC 0x0c0703a8 */
if(!s->budget--) { s->failed_pc=0x0c0703a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0703aa;
P_0c0703aa: /* original 8902, guest PC 0x0c0703aa */
if(!s->budget--) { s->failed_pc=0x0c0703aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0703b2; }
goto P_0c0703ac;
P_0c0703ac: /* original d308, guest PC 0x0c0703ac */
if(!s->budget--) { s->failed_pc=0x0c0703acu; return 0; }
r[3]=read(ram,0x0c0703d0u,4);
goto P_0c0703ae;
P_0c0703ae: /* original 432b, guest PC 0x0c0703ae */
if(!s->budget--) { s->failed_pc=0x0c0703aeu; return 0; }
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
P_0c0703b0: /* original 0009, guest PC 0x0c0703b0 */
if(!s->budget--) { s->failed_pc=0x0c0703b0u; return 0; }
goto P_0c0703b2;
P_0c0703b2: /* original e014, guest PC 0x0c0703b2 */
if(!s->budget--) { s->failed_pc=0x0c0703b2u; return 0; }
r[0]=0x00000014u;
goto P_0c0703b4;
P_0c0703b4: /* original f3f6, guest PC 0x0c0703b4 */
if(!s->budget--) { s->failed_pc=0x0c0703b4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0703b6;
P_0c0703b6: /* original ff35, guest PC 0x0c0703b6 */
if(!s->budget--) { s->failed_pc=0x0c0703b6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0703b8;
P_0c0703b8: /* original 8902, guest PC 0x0c0703b8 */
if(!s->budget--) { s->failed_pc=0x0c0703b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0703c0; }
goto P_0c0703ba;
P_0c0703ba: /* original d306, guest PC 0x0c0703ba */
if(!s->budget--) { s->failed_pc=0x0c0703bau; return 0; }
r[3]=read(ram,0x0c0703d4u,4);
goto P_0c0703bc;
P_0c0703bc: /* original 432b, guest PC 0x0c0703bc */
if(!s->budget--) { s->failed_pc=0x0c0703bcu; return 0; }
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
P_0c0703be: /* original 0009, guest PC 0x0c0703be */
if(!s->budget--) { s->failed_pc=0x0c0703beu; return 0; }
goto P_0c0703c0;
P_0c0703c0: /* original 64f3, guest PC 0x0c0703c0 */
if(!s->budget--) { s->failed_pc=0x0c0703c0u; return 0; }
r[4]=r[15];
goto P_0c0703c2;
P_0c0703c2: /* original 65f3, guest PC 0x0c0703c2 */
if(!s->budget--) { s->failed_pc=0x0c0703c2u; return 0; }
r[5]=r[15];
goto P_0c0703c4;
P_0c0703c4: /* original 7444, guest PC 0x0c0703c4 */
if(!s->budget--) { s->failed_pc=0x0c0703c4u; return 0; }
r[4]+=0x00000044u;
goto P_0c0703c6;
P_0c0703c6: /* original f4fc, guest PC 0x0c0703c6 */
if(!s->budget--) { s->failed_pc=0x0c0703c6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0703c8;
P_0c0703c8: /* original 7544, guest PC 0x0c0703c8 */
if(!s->budget--) { s->failed_pc=0x0c0703c8u; return 0; }
r[5]+=0x00000044u;
goto P_0c0703ca;
P_0c0703ca: /* original a005, guest PC 0x0c0703ca */
if(!s->budget--) { s->failed_pc=0x0c0703cau; return 0; }
goto P_0c0703d8;
P_0c0703cc: /* original 0009, guest PC 0x0c0703cc */
if(!s->budget--) { s->failed_pc=0x0c0703ccu; return 0; }
return vf3_matrix_family(0x0c0703ceu,s,ram);
P_0c0703d8: /* original f059, guest PC 0x0c0703d8 */
if(!s->budget--) { s->failed_pc=0x0c0703d8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703da;
P_0c0703da: /* original f159, guest PC 0x0c0703da */
if(!s->budget--) { s->failed_pc=0x0c0703dau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703dc;
P_0c0703dc: /* original f259, guest PC 0x0c0703dc */
if(!s->budget--) { s->failed_pc=0x0c0703dcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703de;
P_0c0703de: /* original f38d, guest PC 0x0c0703de */
if(!s->budget--) { s->failed_pc=0x0c0703deu; return 0; }
fr[3]=0;
goto P_0c0703e0;
P_0c0703e0: /* original f0ed, guest PC 0x0c0703e0 */
if(!s->budget--) { s->failed_pc=0x0c0703e0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0703e2;
P_0c0703e2: /* original f37d, guest PC 0x0c0703e2 */
if(!s->budget--) { s->failed_pc=0x0c0703e2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0703e4;
P_0c0703e4: /* original f342, guest PC 0x0c0703e4 */
if(!s->budget--) { s->failed_pc=0x0c0703e4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0703e6;
P_0c0703e6: /* original 740c, guest PC 0x0c0703e6 */
if(!s->budget--) { s->failed_pc=0x0c0703e6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0703e8;
P_0c0703e8: /* original f232, guest PC 0x0c0703e8 */
if(!s->budget--) { s->failed_pc=0x0c0703e8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0703ea;
P_0c0703ea: /* original f132, guest PC 0x0c0703ea */
if(!s->budget--) { s->failed_pc=0x0c0703eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0703ec;
P_0c0703ec: /* original f032, guest PC 0x0c0703ec */
if(!s->budget--) { s->failed_pc=0x0c0703ecu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0703ee;
P_0c0703ee: /* original f42b, guest PC 0x0c0703ee */
if(!s->budget--) { s->failed_pc=0x0c0703eeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0703f0;
P_0c0703f0: /* original f41b, guest PC 0x0c0703f0 */
if(!s->budget--) { s->failed_pc=0x0c0703f0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0703f2;
P_0c0703f2: /* original f40b, guest PC 0x0c0703f2 */
if(!s->budget--) { s->failed_pc=0x0c0703f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0703f4;
P_0c0703f4: /* original d306, guest PC 0x0c0703f4 */
if(!s->budget--) { s->failed_pc=0x0c0703f4u; return 0; }
r[3]=read(ram,0x0c070410u,4);
goto P_0c0703f6;
P_0c0703f6: /* original 432b, guest PC 0x0c0703f6 */
if(!s->budget--) { s->failed_pc=0x0c0703f6u; return 0; }
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
P_0c0703f8: /* original 0009, guest PC 0x0c0703f8 */
if(!s->budget--) { s->failed_pc=0x0c0703f8u; return 0; }
goto P_0c0703fa;
P_0c0703fa: /* original fe45, guest PC 0x0c0703fa */
if(!s->budget--) { s->failed_pc=0x0c0703fau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0703fc;
P_0c0703fc: /* original 8902, guest PC 0x0c0703fc */
if(!s->budget--) { s->failed_pc=0x0c0703fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070404; }
goto P_0c0703fe;
P_0c0703fe: /* original d305, guest PC 0x0c0703fe */
if(!s->budget--) { s->failed_pc=0x0c0703feu; return 0; }
r[3]=read(ram,0x0c070414u,4);
goto P_0c070400;
P_0c070400: /* original 432b, guest PC 0x0c070400 */
if(!s->budget--) { s->failed_pc=0x0c070400u; return 0; }
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
P_0c070402: /* original 0009, guest PC 0x0c070402 */
if(!s->budget--) { s->failed_pc=0x0c070402u; return 0; }
goto P_0c070404;
P_0c070404: /* original 64f3, guest PC 0x0c070404 */
if(!s->budget--) { s->failed_pc=0x0c070404u; return 0; }
r[4]=r[15];
goto P_0c070406;
P_0c070406: /* original 7438, guest PC 0x0c070406 */
if(!s->budget--) { s->failed_pc=0x0c070406u; return 0; }
r[4]+=0x00000038u;
goto P_0c070408;
P_0c070408: /* original 65c3, guest PC 0x0c070408 */
if(!s->budget--) { s->failed_pc=0x0c070408u; return 0; }
r[5]=r[12];
goto P_0c07040a;
P_0c07040a: /* original a005, guest PC 0x0c07040a */
if(!s->budget--) { s->failed_pc=0x0c07040au; return 0; }
goto P_0c070418;
P_0c07040c: /* original 0009, guest PC 0x0c07040c */
if(!s->budget--) { s->failed_pc=0x0c07040cu; return 0; }
return vf3_matrix_family(0x0c07040eu,s,ram);
P_0c070418: /* original f059, guest PC 0x0c070418 */
if(!s->budget--) { s->failed_pc=0x0c070418u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07041a;
P_0c07041a: /* original f159, guest PC 0x0c07041a */
if(!s->budget--) { s->failed_pc=0x0c07041au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07041c;
P_0c07041c: /* original f259, guest PC 0x0c07041c */
if(!s->budget--) { s->failed_pc=0x0c07041cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07041e;
P_0c07041e: /* original 740c, guest PC 0x0c07041e */
if(!s->budget--) { s->failed_pc=0x0c07041eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070420;
P_0c070420: /* original f242, guest PC 0x0c070420 */
if(!s->budget--) { s->failed_pc=0x0c070420u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070422;
P_0c070422: /* original f142, guest PC 0x0c070422 */
if(!s->budget--) { s->failed_pc=0x0c070422u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070424;
P_0c070424: /* original f042, guest PC 0x0c070424 */
if(!s->budget--) { s->failed_pc=0x0c070424u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070426;
P_0c070426: /* original f42b, guest PC 0x0c070426 */
if(!s->budget--) { s->failed_pc=0x0c070426u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070428;
P_0c070428: /* original f41b, guest PC 0x0c070428 */
if(!s->budget--) { s->failed_pc=0x0c070428u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07042a;
P_0c07042a: /* original f40b, guest PC 0x0c07042a */
if(!s->budget--) { s->failed_pc=0x0c07042au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07042c;
P_0c07042c: /* original 65f3, guest PC 0x0c07042c */
if(!s->budget--) { s->failed_pc=0x0c07042cu; return 0; }
r[5]=r[15];
goto P_0c07042e;
P_0c07042e: /* original 64f3, guest PC 0x0c07042e */
if(!s->budget--) { s->failed_pc=0x0c07042eu; return 0; }
r[4]=r[15];
goto P_0c070430;
P_0c070430: /* original 66f3, guest PC 0x0c070430 */
if(!s->budget--) { s->failed_pc=0x0c070430u; return 0; }
r[6]=r[15];
goto P_0c070432;
P_0c070432: /* original 7438, guest PC 0x0c070432 */
if(!s->budget--) { s->failed_pc=0x0c070432u; return 0; }
r[4]+=0x00000038u;
goto P_0c070434;
P_0c070434: /* original 7638, guest PC 0x0c070434 */
if(!s->budget--) { s->failed_pc=0x0c070434u; return 0; }
r[6]+=0x00000038u;
goto P_0c070436;
P_0c070436: /* original 7544, guest PC 0x0c070436 */
if(!s->budget--) { s->failed_pc=0x0c070436u; return 0; }
r[5]+=0x00000044u;
goto P_0c070438;
P_0c070438: /* original f059, guest PC 0x0c070438 */
if(!s->budget--) { s->failed_pc=0x0c070438u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07043a;
P_0c07043a: /* original f369, guest PC 0x0c07043a */
if(!s->budget--) { s->failed_pc=0x0c07043au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07043c;
P_0c07043c: /* original f159, guest PC 0x0c07043c */
if(!s->budget--) { s->failed_pc=0x0c07043cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07043e;
P_0c07043e: /* original f469, guest PC 0x0c07043e */
if(!s->budget--) { s->failed_pc=0x0c07043eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070440;
P_0c070440: /* original f031, guest PC 0x0c070440 */
if(!s->budget--) { s->failed_pc=0x0c070440u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070442;
P_0c070442: /* original f258, guest PC 0x0c070442 */
if(!s->budget--) { s->failed_pc=0x0c070442u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070444;
P_0c070444: /* original f568, guest PC 0x0c070444 */
if(!s->budget--) { s->failed_pc=0x0c070444u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070446;
P_0c070446: /* original f141, guest PC 0x0c070446 */
if(!s->budget--) { s->failed_pc=0x0c070446u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070448;
P_0c070448: /* original f251, guest PC 0x0c070448 */
if(!s->budget--) { s->failed_pc=0x0c070448u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07044a;
P_0c07044a: /* original 7408, guest PC 0x0c07044a */
if(!s->budget--) { s->failed_pc=0x0c07044au; return 0; }
r[4]+=0x00000008u;
goto P_0c07044c;
P_0c07044c: /* original f42a, guest PC 0x0c07044c */
if(!s->budget--) { s->failed_pc=0x0c07044cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07044e;
P_0c07044e: /* original f41b, guest PC 0x0c07044e */
if(!s->budget--) { s->failed_pc=0x0c07044eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070450;
P_0c070450: /* original f40b, guest PC 0x0c070450 */
if(!s->budget--) { s->failed_pc=0x0c070450u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070452;
P_0c070452: /* original 0009, guest PC 0x0c070452 */
if(!s->budget--) { s->failed_pc=0x0c070452u; return 0; }
goto P_0c070454;
P_0c070454: /* original f4fc, guest PC 0x0c070454 */
if(!s->budget--) { s->failed_pc=0x0c070454u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070456;
P_0c070456: /* original f4c1, guest PC 0x0c070456 */
if(!s->budget--) { s->failed_pc=0x0c070456u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c070458;
P_0c070458: /* original 64f3, guest PC 0x0c070458 */
if(!s->budget--) { s->failed_pc=0x0c070458u; return 0; }
r[4]=r[15];
goto P_0c07045a;
P_0c07045a: /* original 65f3, guest PC 0x0c07045a */
if(!s->budget--) { s->failed_pc=0x0c07045au; return 0; }
r[5]=r[15];
goto P_0c07045c;
P_0c07045c: /* original 7438, guest PC 0x0c07045c */
if(!s->budget--) { s->failed_pc=0x0c07045cu; return 0; }
r[4]+=0x00000038u;
goto P_0c07045e;
P_0c07045e: /* original 7538, guest PC 0x0c07045e */
if(!s->budget--) { s->failed_pc=0x0c07045eu; return 0; }
r[5]+=0x00000038u;
goto P_0c070460;
P_0c070460: /* original f059, guest PC 0x0c070460 */
if(!s->budget--) { s->failed_pc=0x0c070460u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070462;
P_0c070462: /* original f159, guest PC 0x0c070462 */
if(!s->budget--) { s->failed_pc=0x0c070462u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070464;
P_0c070464: /* original f259, guest PC 0x0c070464 */
if(!s->budget--) { s->failed_pc=0x0c070464u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070466;
P_0c070466: /* original f38d, guest PC 0x0c070466 */
if(!s->budget--) { s->failed_pc=0x0c070466u; return 0; }
fr[3]=0;
goto P_0c070468;
P_0c070468: /* original f0ed, guest PC 0x0c070468 */
if(!s->budget--) { s->failed_pc=0x0c070468u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07046a;
P_0c07046a: /* original f37d, guest PC 0x0c07046a */
if(!s->budget--) { s->failed_pc=0x0c07046au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07046c;
P_0c07046c: /* original f342, guest PC 0x0c07046c */
if(!s->budget--) { s->failed_pc=0x0c07046cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07046e;
P_0c07046e: /* original 740c, guest PC 0x0c07046e */
if(!s->budget--) { s->failed_pc=0x0c07046eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070470;
P_0c070470: /* original f232, guest PC 0x0c070470 */
if(!s->budget--) { s->failed_pc=0x0c070470u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070472;
P_0c070472: /* original f132, guest PC 0x0c070472 */
if(!s->budget--) { s->failed_pc=0x0c070472u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070474;
P_0c070474: /* original f032, guest PC 0x0c070474 */
if(!s->budget--) { s->failed_pc=0x0c070474u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070476;
P_0c070476: /* original f42b, guest PC 0x0c070476 */
if(!s->budget--) { s->failed_pc=0x0c070476u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070478;
P_0c070478: /* original f41b, guest PC 0x0c070478 */
if(!s->budget--) { s->failed_pc=0x0c070478u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07047a;
P_0c07047a: /* original f40b, guest PC 0x0c07047a */
if(!s->budget--) { s->failed_pc=0x0c07047au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07047c;
P_0c07047c: /* original 64f3, guest PC 0x0c07047c */
if(!s->budget--) { s->failed_pc=0x0c07047cu; return 0; }
r[4]=r[15];
goto P_0c07047e;
P_0c07047e: /* original 65f3, guest PC 0x0c07047e */
if(!s->budget--) { s->failed_pc=0x0c07047eu; return 0; }
r[5]=r[15];
goto P_0c070480;
P_0c070480: /* original 7444, guest PC 0x0c070480 */
if(!s->budget--) { s->failed_pc=0x0c070480u; return 0; }
r[4]+=0x00000044u;
goto P_0c070482;
P_0c070482: /* original 7538, guest PC 0x0c070482 */
if(!s->budget--) { s->failed_pc=0x0c070482u; return 0; }
r[5]+=0x00000038u;
goto P_0c070484;
P_0c070484: /* original f049, guest PC 0x0c070484 */
if(!s->budget--) { s->failed_pc=0x0c070484u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070486;
P_0c070486: /* original f359, guest PC 0x0c070486 */
if(!s->budget--) { s->failed_pc=0x0c070486u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070488;
P_0c070488: /* original f149, guest PC 0x0c070488 */
if(!s->budget--) { s->failed_pc=0x0c070488u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07048a;
P_0c07048a: /* original f459, guest PC 0x0c07048a */
if(!s->budget--) { s->failed_pc=0x0c07048au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07048c;
P_0c07048c: /* original f249, guest PC 0x0c07048c */
if(!s->budget--) { s->failed_pc=0x0c07048cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07048e;
P_0c07048e: /* original f559, guest PC 0x0c07048e */
if(!s->budget--) { s->failed_pc=0x0c07048eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070490;
P_0c070490: /* original f030, guest PC 0x0c070490 */
if(!s->budget--) { s->failed_pc=0x0c070490u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070492;
P_0c070492: /* original f250, guest PC 0x0c070492 */
if(!s->budget--) { s->failed_pc=0x0c070492u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070494;
P_0c070494: /* original f140, guest PC 0x0c070494 */
if(!s->budget--) { s->failed_pc=0x0c070494u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070496;
P_0c070496: /* original f42b, guest PC 0x0c070496 */
if(!s->budget--) { s->failed_pc=0x0c070496u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070498;
P_0c070498: /* original f41b, guest PC 0x0c070498 */
if(!s->budget--) { s->failed_pc=0x0c070498u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07049a;
P_0c07049a: /* original f40b, guest PC 0x0c07049a */
if(!s->budget--) { s->failed_pc=0x0c07049au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07049c;
P_0c07049c: /* original 65f3, guest PC 0x0c07049c */
if(!s->budget--) { s->failed_pc=0x0c07049cu; return 0; }
r[5]=r[15];
goto P_0c07049e;
P_0c07049e: /* original 64e3, guest PC 0x0c07049e */
if(!s->budget--) { s->failed_pc=0x0c07049eu; return 0; }
r[4]=r[14];
goto P_0c0704a0;
P_0c0704a0: /* original 7544, guest PC 0x0c0704a0 */
if(!s->budget--) { s->failed_pc=0x0c0704a0u; return 0; }
r[5]+=0x00000044u;
goto P_0c0704a2;
P_0c0704a2: /* original 6693, guest PC 0x0c0704a2 */
if(!s->budget--) { s->failed_pc=0x0c0704a2u; return 0; }
r[6]=r[9];
goto P_0c0704a4;
P_0c0704a4: /* original f059, guest PC 0x0c0704a4 */
if(!s->budget--) { s->failed_pc=0x0c0704a4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704a6;
P_0c0704a6: /* original f369, guest PC 0x0c0704a6 */
if(!s->budget--) { s->failed_pc=0x0c0704a6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704a8;
P_0c0704a8: /* original f159, guest PC 0x0c0704a8 */
if(!s->budget--) { s->failed_pc=0x0c0704a8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704aa;
P_0c0704aa: /* original f469, guest PC 0x0c0704aa */
if(!s->budget--) { s->failed_pc=0x0c0704aau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704ac;
P_0c0704ac: /* original f259, guest PC 0x0c0704ac */
if(!s->budget--) { s->failed_pc=0x0c0704acu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704ae;
P_0c0704ae: /* original f569, guest PC 0x0c0704ae */
if(!s->budget--) { s->failed_pc=0x0c0704aeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704b0;
P_0c0704b0: /* original 740c, guest PC 0x0c0704b0 */
if(!s->budget--) { s->failed_pc=0x0c0704b0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0704b2;
P_0c0704b2: /* original f030, guest PC 0x0c0704b2 */
if(!s->budget--) { s->failed_pc=0x0c0704b2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0704b4;
P_0c0704b4: /* original f250, guest PC 0x0c0704b4 */
if(!s->budget--) { s->failed_pc=0x0c0704b4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0704b6;
P_0c0704b6: /* original f140, guest PC 0x0c0704b6 */
if(!s->budget--) { s->failed_pc=0x0c0704b6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0704b8;
P_0c0704b8: /* original f42b, guest PC 0x0c0704b8 */
if(!s->budget--) { s->failed_pc=0x0c0704b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0704ba;
P_0c0704ba: /* original f41b, guest PC 0x0c0704ba */
if(!s->budget--) { s->failed_pc=0x0c0704bau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0704bc;
P_0c0704bc: /* original f40b, guest PC 0x0c0704bc */
if(!s->budget--) { s->failed_pc=0x0c0704bcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0704be;
P_0c0704be: /* original 0009, guest PC 0x0c0704be */
if(!s->budget--) { s->failed_pc=0x0c0704beu; return 0; }
goto P_0c0704c0;
P_0c0704c0: /* original 50fa, guest PC 0x0c0704c0 */
if(!s->budget--) { s->failed_pc=0x0c0704c0u; return 0; }
r[0]=read(ram,r[15]+40,4);
goto P_0c0704c2;
P_0c0704c2: /* original 8801, guest PC 0x0c0704c2 */
if(!s->budget--) { s->failed_pc=0x0c0704c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0704c4;
P_0c0704c4: /* original 8902, guest PC 0x0c0704c4 */
if(!s->budget--) { s->failed_pc=0x0c0704c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0704cc; }
goto P_0c0704c6;
P_0c0704c6: /* original d304, guest PC 0x0c0704c6 */
if(!s->budget--) { s->failed_pc=0x0c0704c6u; return 0; }
r[3]=read(ram,0x0c0704d8u,4);
goto P_0c0704c8;
P_0c0704c8: /* original 432b, guest PC 0x0c0704c8 */
if(!s->budget--) { s->failed_pc=0x0c0704c8u; return 0; }
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
P_0c0704ca: /* original 0009, guest PC 0x0c0704ca */
if(!s->budget--) { s->failed_pc=0x0c0704cau; return 0; }
goto P_0c0704cc;
P_0c0704cc: /* original 64f3, guest PC 0x0c0704cc */
if(!s->budget--) { s->failed_pc=0x0c0704ccu; return 0; }
r[4]=r[15];
goto P_0c0704ce;
P_0c0704ce: /* original 7444, guest PC 0x0c0704ce */
if(!s->budget--) { s->failed_pc=0x0c0704ceu; return 0; }
r[4]+=0x00000044u;
goto P_0c0704d0;
P_0c0704d0: /* original 66a3, guest PC 0x0c0704d0 */
if(!s->budget--) { s->failed_pc=0x0c0704d0u; return 0; }
r[6]=r[10];
goto P_0c0704d2;
P_0c0704d2: /* original 65d3, guest PC 0x0c0704d2 */
if(!s->budget--) { s->failed_pc=0x0c0704d2u; return 0; }
r[5]=r[13];
goto P_0c0704d4;
P_0c0704d4: /* original a002, guest PC 0x0c0704d4 */
if(!s->budget--) { s->failed_pc=0x0c0704d4u; return 0; }
goto P_0c0704dc;
P_0c0704d6: /* original 0009, guest PC 0x0c0704d6 */
if(!s->budget--) { s->failed_pc=0x0c0704d6u; return 0; }
return vf3_matrix_family(0x0c0704d8u,s,ram);
P_0c0704dc: /* original f059, guest PC 0x0c0704dc */
if(!s->budget--) { s->failed_pc=0x0c0704dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704de;
P_0c0704de: /* original f369, guest PC 0x0c0704de */
if(!s->budget--) { s->failed_pc=0x0c0704deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e0;
P_0c0704e0: /* original f159, guest PC 0x0c0704e0 */
if(!s->budget--) { s->failed_pc=0x0c0704e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e2;
P_0c0704e2: /* original f469, guest PC 0x0c0704e2 */
if(!s->budget--) { s->failed_pc=0x0c0704e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e4;
P_0c0704e4: /* original f031, guest PC 0x0c0704e4 */
if(!s->budget--) { s->failed_pc=0x0c0704e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0704e6;
P_0c0704e6: /* original f258, guest PC 0x0c0704e6 */
if(!s->budget--) { s->failed_pc=0x0c0704e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0704e8;
P_0c0704e8: /* original f568, guest PC 0x0c0704e8 */
if(!s->budget--) { s->failed_pc=0x0c0704e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0704ea;
P_0c0704ea: /* original f141, guest PC 0x0c0704ea */
if(!s->budget--) { s->failed_pc=0x0c0704eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0704ec;
P_0c0704ec: /* original f251, guest PC 0x0c0704ec */
if(!s->budget--) { s->failed_pc=0x0c0704ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0704ee;
P_0c0704ee: /* original 7408, guest PC 0x0c0704ee */
if(!s->budget--) { s->failed_pc=0x0c0704eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0704f0;
P_0c0704f0: /* original f42a, guest PC 0x0c0704f0 */
if(!s->budget--) { s->failed_pc=0x0c0704f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0704f2;
P_0c0704f2: /* original f41b, guest PC 0x0c0704f2 */
if(!s->budget--) { s->failed_pc=0x0c0704f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0704f4;
P_0c0704f4: /* original f40b, guest PC 0x0c0704f4 */
if(!s->budget--) { s->failed_pc=0x0c0704f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0704f6;
P_0c0704f6: /* original 0009, guest PC 0x0c0704f6 */
if(!s->budget--) { s->failed_pc=0x0c0704f6u; return 0; }
goto P_0c0704f8;
P_0c0704f8: /* original 64f3, guest PC 0x0c0704f8 */
if(!s->budget--) { s->failed_pc=0x0c0704f8u; return 0; }
r[4]=r[15];
goto P_0c0704fa;
P_0c0704fa: /* original 7444, guest PC 0x0c0704fa */
if(!s->budget--) { s->failed_pc=0x0c0704fau; return 0; }
r[4]+=0x00000044u;
goto P_0c0704fc;
P_0c0704fc: /* original f049, guest PC 0x0c0704fc */
if(!s->budget--) { s->failed_pc=0x0c0704fcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0704fe;
P_0c0704fe: /* original f149, guest PC 0x0c0704fe */
if(!s->budget--) { s->failed_pc=0x0c0704feu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070500;
P_0c070500: /* original f249, guest PC 0x0c070500 */
if(!s->budget--) { s->failed_pc=0x0c070500u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070502;
P_0c070502: /* original f38d, guest PC 0x0c070502 */
if(!s->budget--) { s->failed_pc=0x0c070502u; return 0; }
fr[3]=0;
goto P_0c070504;
P_0c070504: /* original f0ed, guest PC 0x0c070504 */
if(!s->budget--) { s->failed_pc=0x0c070504u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070506;
P_0c070506: /* original f03c, guest PC 0x0c070506 */
if(!s->budget--) { s->failed_pc=0x0c070506u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070508;
P_0c070508: /* original f06d, guest PC 0x0c070508 */
if(!s->budget--) { s->failed_pc=0x0c070508u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07050a;
P_0c07050a: /* original 0009, guest PC 0x0c07050a */
if(!s->budget--) { s->failed_pc=0x0c07050au; return 0; }
goto P_0c07050c;
P_0c07050c: /* original f38d, guest PC 0x0c07050c */
if(!s->budget--) { s->failed_pc=0x0c07050cu; return 0; }
fr[3]=0;
goto P_0c07050e;
P_0c07050e: /* original fc0c, guest PC 0x0c07050e */
if(!s->budget--) { s->failed_pc=0x0c07050eu; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070510;
P_0c070510: /* original fc35, guest PC 0x0c070510 */
if(!s->budget--) { s->failed_pc=0x0c070510u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070512;
P_0c070512: /* original 8902, guest PC 0x0c070512 */
if(!s->budget--) { s->failed_pc=0x0c070512u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07051a; }
goto P_0c070514;
P_0c070514: /* original d303, guest PC 0x0c070514 */
if(!s->budget--) { s->failed_pc=0x0c070514u; return 0; }
r[3]=read(ram,0x0c070524u,4);
goto P_0c070516;
P_0c070516: /* original 432b, guest PC 0x0c070516 */
if(!s->budget--) { s->failed_pc=0x0c070516u; return 0; }
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
P_0c070518: /* original 0009, guest PC 0x0c070518 */
if(!s->budget--) { s->failed_pc=0x0c070518u; return 0; }
goto P_0c07051a;
P_0c07051a: /* original 64f3, guest PC 0x0c07051a */
if(!s->budget--) { s->failed_pc=0x0c07051au; return 0; }
r[4]=r[15];
goto P_0c07051c;
P_0c07051c: /* original 7444, guest PC 0x0c07051c */
if(!s->budget--) { s->failed_pc=0x0c07051cu; return 0; }
r[4]+=0x00000044u;
goto P_0c07051e;
P_0c07051e: /* original 65b3, guest PC 0x0c07051e */
if(!s->budget--) { s->failed_pc=0x0c07051eu; return 0; }
r[5]=r[11];
goto P_0c070520;
P_0c070520: /* original a002, guest PC 0x0c070520 */
if(!s->budget--) { s->failed_pc=0x0c070520u; return 0; }
goto P_0c070528;
P_0c070522: /* original 0009, guest PC 0x0c070522 */
if(!s->budget--) { s->failed_pc=0x0c070522u; return 0; }
return vf3_matrix_family(0x0c070524u,s,ram);
P_0c070528: /* original f049, guest PC 0x0c070528 */
if(!s->budget--) { s->failed_pc=0x0c070528u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07052a;
P_0c07052a: /* original f549, guest PC 0x0c07052a */
if(!s->budget--) { s->failed_pc=0x0c07052au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07052c;
P_0c07052c: /* original f648, guest PC 0x0c07052c */
if(!s->budget--) { s->failed_pc=0x0c07052cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07052e;
P_0c07052e: /* original f859, guest PC 0x0c07052e */
if(!s->budget--) { s->failed_pc=0x0c07052eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070530;
P_0c070530: /* original f959, guest PC 0x0c070530 */
if(!s->budget--) { s->failed_pc=0x0c070530u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070532;
P_0c070532: /* original fa58, guest PC 0x0c070532 */
if(!s->budget--) { s->failed_pc=0x0c070532u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070534;
P_0c070534: /* original f35c, guest PC 0x0c070534 */
if(!s->budget--) { s->failed_pc=0x0c070534u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070536;
P_0c070536: /* original f382, guest PC 0x0c070536 */
if(!s->budget--) { s->failed_pc=0x0c070536u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070538;
P_0c070538: /* original f20c, guest PC 0x0c070538 */
if(!s->budget--) { s->failed_pc=0x0c070538u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07053a;
P_0c07053a: /* original f2a2, guest PC 0x0c07053a */
if(!s->budget--) { s->failed_pc=0x0c07053au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07053c;
P_0c07053c: /* original f16c, guest PC 0x0c07053c */
if(!s->budget--) { s->failed_pc=0x0c07053cu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07053e;
P_0c07053e: /* original f192, guest PC 0x0c07053e */
if(!s->budget--) { s->failed_pc=0x0c07053eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070540;
P_0c070540: /* original f34d, guest PC 0x0c070540 */
if(!s->budget--) { s->failed_pc=0x0c070540u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070542;
P_0c070542: /* original f39e, guest PC 0x0c070542 */
if(!s->budget--) { s->failed_pc=0x0c070542u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070544;
P_0c070544: /* original f24d, guest PC 0x0c070544 */
if(!s->budget--) { s->failed_pc=0x0c070544u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070546;
P_0c070546: /* original f06c, guest PC 0x0c070546 */
if(!s->budget--) { s->failed_pc=0x0c070546u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070548;
P_0c070548: /* original f28e, guest PC 0x0c070548 */
if(!s->budget--) { s->failed_pc=0x0c070548u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07054a;
P_0c07054a: /* original f14d, guest PC 0x0c07054a */
if(!s->budget--) { s->failed_pc=0x0c07054au; return 0; }
fr[1]^=0x80000000u;
goto P_0c07054c;
P_0c07054c: /* original f05c, guest PC 0x0c07054c */
if(!s->budget--) { s->failed_pc=0x0c07054cu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07054e;
P_0c07054e: /* original f1ae, guest PC 0x0c07054e */
if(!s->budget--) { s->failed_pc=0x0c07054eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070550;
P_0c070550: /* original f08d, guest PC 0x0c070550 */
if(!s->budget--) { s->failed_pc=0x0c070550u; return 0; }
fr[0]=0;
goto P_0c070552;
P_0c070552: /* original f0ed, guest PC 0x0c070552 */
if(!s->budget--) { s->failed_pc=0x0c070552u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070554;
P_0c070554: /* original f03c, guest PC 0x0c070554 */
if(!s->budget--) { s->failed_pc=0x0c070554u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070556;
P_0c070556: /* original f06d, guest PC 0x0c070556 */
if(!s->budget--) { s->failed_pc=0x0c070556u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070558;
P_0c070558: /* original ff05, guest PC 0x0c070558 */
if(!s->budget--) { s->failed_pc=0x0c070558u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c07055a;
P_0c07055a: /* original e010, guest PC 0x0c07055a */
if(!s->budget--) { s->failed_pc=0x0c07055au; return 0; }
r[0]=0x00000010u;
goto P_0c07055c;
P_0c07055c: /* original 8d03, guest PC 0x0c07055c */
if(!s->budget--) { s->failed_pc=0x0c07055cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070566; }
goto P_0c070560;
P_0c07055e: /* original ff07, guest PC 0x0c07055e */
if(!s->budget--) { s->failed_pc=0x0c07055eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070560;
P_0c070560: /* original d303, guest PC 0x0c070560 */
if(!s->budget--) { s->failed_pc=0x0c070560u; return 0; }
r[3]=read(ram,0x0c070570u,4);
goto P_0c070562;
P_0c070562: /* original 432b, guest PC 0x0c070562 */
if(!s->budget--) { s->failed_pc=0x0c070562u; return 0; }
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
P_0c070564: /* original 0009, guest PC 0x0c070564 */
if(!s->budget--) { s->failed_pc=0x0c070564u; return 0; }
goto P_0c070566;
P_0c070566: /* original 64f3, guest PC 0x0c070566 */
if(!s->budget--) { s->failed_pc=0x0c070566u; return 0; }
r[4]=r[15];
goto P_0c070568;
P_0c070568: /* original 7444, guest PC 0x0c070568 */
if(!s->budget--) { s->failed_pc=0x0c070568u; return 0; }
r[4]+=0x00000044u;
goto P_0c07056a;
P_0c07056a: /* original 65b3, guest PC 0x0c07056a */
if(!s->budget--) { s->failed_pc=0x0c07056au; return 0; }
r[5]=r[11];
goto P_0c07056c;
P_0c07056c: /* original a002, guest PC 0x0c07056c */
if(!s->budget--) { s->failed_pc=0x0c07056cu; return 0; }
goto P_0c070574;
P_0c07056e: /* original 0009, guest PC 0x0c07056e */
if(!s->budget--) { s->failed_pc=0x0c07056eu; return 0; }
return vf3_matrix_family(0x0c070570u,s,ram);
P_0c070574: /* original f049, guest PC 0x0c070574 */
if(!s->budget--) { s->failed_pc=0x0c070574u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070576;
P_0c070576: /* original f149, guest PC 0x0c070576 */
if(!s->budget--) { s->failed_pc=0x0c070576u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070578;
P_0c070578: /* original f249, guest PC 0x0c070578 */
if(!s->budget--) { s->failed_pc=0x0c070578u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07057a;
P_0c07057a: /* original f38d, guest PC 0x0c07057a */
if(!s->budget--) { s->failed_pc=0x0c07057au; return 0; }
fr[3]=0;
goto P_0c07057c;
P_0c07057c: /* original f459, guest PC 0x0c07057c */
if(!s->budget--) { s->failed_pc=0x0c07057cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07057e;
P_0c07057e: /* original f559, guest PC 0x0c07057e */
if(!s->budget--) { s->failed_pc=0x0c07057eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070580;
P_0c070580: /* original f659, guest PC 0x0c070580 */
if(!s->budget--) { s->failed_pc=0x0c070580u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070582;
P_0c070582: /* original f78d, guest PC 0x0c070582 */
if(!s->budget--) { s->failed_pc=0x0c070582u; return 0; }
fr[7]=0;
goto P_0c070584;
P_0c070584: /* original f4ed, guest PC 0x0c070584 */
if(!s->budget--) { s->failed_pc=0x0c070584u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070586;
P_0c070586: /* original f07c, guest PC 0x0c070586 */
if(!s->budget--) { s->failed_pc=0x0c070586u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070588;
P_0c070588: /* original f38d, guest PC 0x0c070588 */
if(!s->budget--) { s->failed_pc=0x0c070588u; return 0; }
fr[3]=0;
goto P_0c07058a;
P_0c07058a: /* original f40c, guest PC 0x0c07058a */
if(!s->budget--) { s->failed_pc=0x0c07058au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c07058c;
P_0c07058c: /* original f345, guest PC 0x0c07058c */
if(!s->budget--) { s->failed_pc=0x0c07058cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c07058e;
P_0c07058e: /* original 8902, guest PC 0x0c07058e */
if(!s->budget--) { s->failed_pc=0x0c07058eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070596; }
goto P_0c070590;
P_0c070590: /* original d307, guest PC 0x0c070590 */
if(!s->budget--) { s->failed_pc=0x0c070590u; return 0; }
r[3]=read(ram,0x0c0705b0u,4);
goto P_0c070592;
P_0c070592: /* original 432b, guest PC 0x0c070592 */
if(!s->budget--) { s->failed_pc=0x0c070592u; return 0; }
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
P_0c070594: /* original 0009, guest PC 0x0c070594 */
if(!s->budget--) { s->failed_pc=0x0c070594u; return 0; }
goto P_0c070596;
P_0c070596: /* original ffc5, guest PC 0x0c070596 */
if(!s->budget--) { s->failed_pc=0x0c070596u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070598;
P_0c070598: /* original 8902, guest PC 0x0c070598 */
if(!s->budget--) { s->failed_pc=0x0c070598u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0705a0; }
goto P_0c07059a;
P_0c07059a: /* original d206, guest PC 0x0c07059a */
if(!s->budget--) { s->failed_pc=0x0c07059au; return 0; }
r[2]=read(ram,0x0c0705b4u,4);
goto P_0c07059c;
P_0c07059c: /* original 422b, guest PC 0x0c07059c */
if(!s->budget--) { s->failed_pc=0x0c07059cu; return 0; }
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
P_0c07059e: /* original 0009, guest PC 0x0c07059e */
if(!s->budget--) { s->failed_pc=0x0c07059eu; return 0; }
goto P_0c0705a0;
P_0c0705a0: /* original 64f3, guest PC 0x0c0705a0 */
if(!s->budget--) { s->failed_pc=0x0c0705a0u; return 0; }
r[4]=r[15];
goto P_0c0705a2;
P_0c0705a2: /* original 65f3, guest PC 0x0c0705a2 */
if(!s->budget--) { s->failed_pc=0x0c0705a2u; return 0; }
r[5]=r[15];
goto P_0c0705a4;
P_0c0705a4: /* original 7444, guest PC 0x0c0705a4 */
if(!s->budget--) { s->failed_pc=0x0c0705a4u; return 0; }
r[4]+=0x00000044u;
goto P_0c0705a6;
P_0c0705a6: /* original f4fc, guest PC 0x0c0705a6 */
if(!s->budget--) { s->failed_pc=0x0c0705a6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0705a8;
P_0c0705a8: /* original 7544, guest PC 0x0c0705a8 */
if(!s->budget--) { s->failed_pc=0x0c0705a8u; return 0; }
r[5]+=0x00000044u;
goto P_0c0705aa;
P_0c0705aa: /* original a005, guest PC 0x0c0705aa */
if(!s->budget--) { s->failed_pc=0x0c0705aau; return 0; }
goto P_0c0705b8;
P_0c0705ac: /* original 0009, guest PC 0x0c0705ac */
if(!s->budget--) { s->failed_pc=0x0c0705acu; return 0; }
return vf3_matrix_family(0x0c0705aeu,s,ram);
P_0c0705b8: /* original f059, guest PC 0x0c0705b8 */
if(!s->budget--) { s->failed_pc=0x0c0705b8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705ba;
P_0c0705ba: /* original f159, guest PC 0x0c0705ba */
if(!s->budget--) { s->failed_pc=0x0c0705bau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705bc;
P_0c0705bc: /* original f259, guest PC 0x0c0705bc */
if(!s->budget--) { s->failed_pc=0x0c0705bcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705be;
P_0c0705be: /* original f38d, guest PC 0x0c0705be */
if(!s->budget--) { s->failed_pc=0x0c0705beu; return 0; }
fr[3]=0;
goto P_0c0705c0;
P_0c0705c0: /* original f0ed, guest PC 0x0c0705c0 */
if(!s->budget--) { s->failed_pc=0x0c0705c0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0705c2;
P_0c0705c2: /* original f37d, guest PC 0x0c0705c2 */
if(!s->budget--) { s->failed_pc=0x0c0705c2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0705c4;
P_0c0705c4: /* original f342, guest PC 0x0c0705c4 */
if(!s->budget--) { s->failed_pc=0x0c0705c4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0705c6;
P_0c0705c6: /* original 740c, guest PC 0x0c0705c6 */
if(!s->budget--) { s->failed_pc=0x0c0705c6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0705c8;
P_0c0705c8: /* original f232, guest PC 0x0c0705c8 */
if(!s->budget--) { s->failed_pc=0x0c0705c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0705ca;
P_0c0705ca: /* original f132, guest PC 0x0c0705ca */
if(!s->budget--) { s->failed_pc=0x0c0705cau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0705cc;
P_0c0705cc: /* original f032, guest PC 0x0c0705cc */
if(!s->budget--) { s->failed_pc=0x0c0705ccu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0705ce;
P_0c0705ce: /* original f42b, guest PC 0x0c0705ce */
if(!s->budget--) { s->failed_pc=0x0c0705ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0705d0;
P_0c0705d0: /* original f41b, guest PC 0x0c0705d0 */
if(!s->budget--) { s->failed_pc=0x0c0705d0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0705d2;
P_0c0705d2: /* original f40b, guest PC 0x0c0705d2 */
if(!s->budget--) { s->failed_pc=0x0c0705d2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0705d4;
P_0c0705d4: /* original d206, guest PC 0x0c0705d4 */
if(!s->budget--) { s->failed_pc=0x0c0705d4u; return 0; }
r[2]=read(ram,0x0c0705f0u,4);
goto P_0c0705d6;
P_0c0705d6: /* original 422b, guest PC 0x0c0705d6 */
if(!s->budget--) { s->failed_pc=0x0c0705d6u; return 0; }
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
P_0c0705d8: /* original 0009, guest PC 0x0c0705d8 */
if(!s->budget--) { s->failed_pc=0x0c0705d8u; return 0; }
return vf3_matrix_family(0x0c0705dau,s,ram);
P_0c070878: /* original 63f2, guest PC 0x0c070878 */
if(!s->budget--) { s->failed_pc=0x0c070878u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07087a;
P_0c07087a: /* original 7ee8, guest PC 0x0c07087a */
if(!s->budget--) { s->failed_pc=0x0c07087au; return 0; }
r[14]+=0xffffffe8u;
goto P_0c07087c;
P_0c07087c: /* original 4315, guest PC 0x0c07087c */
if(!s->budget--) { s->failed_pc=0x0c07087cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07087e;
P_0c07087e: /* original 8d03, guest PC 0x0c07087e */
if(!s->budget--) { s->failed_pc=0x0c07087eu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000018u;
if(cond) { goto P_0c070888; }
goto P_0c070882;
P_0c070880: /* original 7d18, guest PC 0x0c070880 */
if(!s->budget--) { s->failed_pc=0x0c070880u; return 0; }
r[13]+=0x00000018u;
goto P_0c070882;
P_0c070882: /* original d204, guest PC 0x0c070882 */
if(!s->budget--) { s->failed_pc=0x0c070882u; return 0; }
r[2]=read(ram,0x0c070894u,4);
goto P_0c070884;
P_0c070884: /* original 422b, guest PC 0x0c070884 */
if(!s->budget--) { s->failed_pc=0x0c070884u; return 0; }
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
P_0c070886: /* original 0009, guest PC 0x0c070886 */
if(!s->budget--) { s->failed_pc=0x0c070886u; return 0; }
goto P_0c070888;
P_0c070888: /* original 64f3, guest PC 0x0c070888 */
if(!s->budget--) { s->failed_pc=0x0c070888u; return 0; }
r[4]=r[15];
goto P_0c07088a;
P_0c07088a: /* original 7444, guest PC 0x0c07088a */
if(!s->budget--) { s->failed_pc=0x0c07088au; return 0; }
r[4]+=0x00000044u;
goto P_0c07088c;
P_0c07088c: /* original 66a3, guest PC 0x0c07088c */
if(!s->budget--) { s->failed_pc=0x0c07088cu; return 0; }
r[6]=r[10];
goto P_0c07088e;
P_0c07088e: /* original 65e3, guest PC 0x0c07088e */
if(!s->budget--) { s->failed_pc=0x0c07088eu; return 0; }
r[5]=r[14];
goto P_0c070890;
P_0c070890: /* original a002, guest PC 0x0c070890 */
if(!s->budget--) { s->failed_pc=0x0c070890u; return 0; }
goto P_0c070898;
P_0c070892: /* original 0009, guest PC 0x0c070892 */
if(!s->budget--) { s->failed_pc=0x0c070892u; return 0; }
return vf3_matrix_family(0x0c070894u,s,ram);
P_0c070898: /* original f059, guest PC 0x0c070898 */
if(!s->budget--) { s->failed_pc=0x0c070898u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07089a;
P_0c07089a: /* original f369, guest PC 0x0c07089a */
if(!s->budget--) { s->failed_pc=0x0c07089au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07089c;
P_0c07089c: /* original f159, guest PC 0x0c07089c */
if(!s->budget--) { s->failed_pc=0x0c07089cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07089e;
P_0c07089e: /* original f469, guest PC 0x0c07089e */
if(!s->budget--) { s->failed_pc=0x0c07089eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0708a0;
P_0c0708a0: /* original f031, guest PC 0x0c0708a0 */
if(!s->budget--) { s->failed_pc=0x0c0708a0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0708a2;
P_0c0708a2: /* original f258, guest PC 0x0c0708a2 */
if(!s->budget--) { s->failed_pc=0x0c0708a2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0708a4;
P_0c0708a4: /* original f568, guest PC 0x0c0708a4 */
if(!s->budget--) { s->failed_pc=0x0c0708a4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0708a6;
P_0c0708a6: /* original f141, guest PC 0x0c0708a6 */
if(!s->budget--) { s->failed_pc=0x0c0708a6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0708a8;
P_0c0708a8: /* original f251, guest PC 0x0c0708a8 */
if(!s->budget--) { s->failed_pc=0x0c0708a8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0708aa;
P_0c0708aa: /* original 7408, guest PC 0x0c0708aa */
if(!s->budget--) { s->failed_pc=0x0c0708aau; return 0; }
r[4]+=0x00000008u;
goto P_0c0708ac;
P_0c0708ac: /* original f42a, guest PC 0x0c0708ac */
if(!s->budget--) { s->failed_pc=0x0c0708acu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0708ae;
P_0c0708ae: /* original f41b, guest PC 0x0c0708ae */
if(!s->budget--) { s->failed_pc=0x0c0708aeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0708b0;
P_0c0708b0: /* original f40b, guest PC 0x0c0708b0 */
if(!s->budget--) { s->failed_pc=0x0c0708b0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0708b2;
P_0c0708b2: /* original 0009, guest PC 0x0c0708b2 */
if(!s->budget--) { s->failed_pc=0x0c0708b2u; return 0; }
goto P_0c0708b4;
P_0c0708b4: /* original 64f3, guest PC 0x0c0708b4 */
if(!s->budget--) { s->failed_pc=0x0c0708b4u; return 0; }
r[4]=r[15];
goto P_0c0708b6;
P_0c0708b6: /* original 7444, guest PC 0x0c0708b6 */
if(!s->budget--) { s->failed_pc=0x0c0708b6u; return 0; }
r[4]+=0x00000044u;
goto P_0c0708b8;
P_0c0708b8: /* original f049, guest PC 0x0c0708b8 */
if(!s->budget--) { s->failed_pc=0x0c0708b8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708ba;
P_0c0708ba: /* original f149, guest PC 0x0c0708ba */
if(!s->budget--) { s->failed_pc=0x0c0708bau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708bc;
P_0c0708bc: /* original f249, guest PC 0x0c0708bc */
if(!s->budget--) { s->failed_pc=0x0c0708bcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708be;
P_0c0708be: /* original f38d, guest PC 0x0c0708be */
if(!s->budget--) { s->failed_pc=0x0c0708beu; return 0; }
fr[3]=0;
goto P_0c0708c0;
P_0c0708c0: /* original f0ed, guest PC 0x0c0708c0 */
if(!s->budget--) { s->failed_pc=0x0c0708c0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0708c2;
P_0c0708c2: /* original f03c, guest PC 0x0c0708c2 */
if(!s->budget--) { s->failed_pc=0x0c0708c2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0708c4;
P_0c0708c4: /* original f06d, guest PC 0x0c0708c4 */
if(!s->budget--) { s->failed_pc=0x0c0708c4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c0708c6;
P_0c0708c6: /* original 0009, guest PC 0x0c0708c6 */
if(!s->budget--) { s->failed_pc=0x0c0708c6u; return 0; }
goto P_0c0708c8;
P_0c0708c8: /* original f38d, guest PC 0x0c0708c8 */
if(!s->budget--) { s->failed_pc=0x0c0708c8u; return 0; }
fr[3]=0;
goto P_0c0708ca;
P_0c0708ca: /* original f035, guest PC 0x0c0708ca */
if(!s->budget--) { s->failed_pc=0x0c0708cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0708cc;
P_0c0708cc: /* original e018, guest PC 0x0c0708cc */
if(!s->budget--) { s->failed_pc=0x0c0708ccu; return 0; }
r[0]=0x00000018u;
goto P_0c0708ce;
P_0c0708ce: /* original 8d03, guest PC 0x0c0708ce */
if(!s->budget--) { s->failed_pc=0x0c0708ceu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c0708d8; }
goto P_0c0708d2;
P_0c0708d0: /* original ff07, guest PC 0x0c0708d0 */
if(!s->budget--) { s->failed_pc=0x0c0708d0u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0708d2;
P_0c0708d2: /* original d304, guest PC 0x0c0708d2 */
if(!s->budget--) { s->failed_pc=0x0c0708d2u; return 0; }
r[3]=read(ram,0x0c0708e4u,4);
goto P_0c0708d4;
P_0c0708d4: /* original 432b, guest PC 0x0c0708d4 */
if(!s->budget--) { s->failed_pc=0x0c0708d4u; return 0; }
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
P_0c0708d6: /* original 0009, guest PC 0x0c0708d6 */
if(!s->budget--) { s->failed_pc=0x0c0708d6u; return 0; }
goto P_0c0708d8;
P_0c0708d8: /* original 64f3, guest PC 0x0c0708d8 */
if(!s->budget--) { s->failed_pc=0x0c0708d8u; return 0; }
r[4]=r[15];
goto P_0c0708da;
P_0c0708da: /* original 7444, guest PC 0x0c0708da */
if(!s->budget--) { s->failed_pc=0x0c0708dau; return 0; }
r[4]+=0x00000044u;
goto P_0c0708dc;
P_0c0708dc: /* original 65b3, guest PC 0x0c0708dc */
if(!s->budget--) { s->failed_pc=0x0c0708dcu; return 0; }
r[5]=r[11];
goto P_0c0708de;
P_0c0708de: /* original a003, guest PC 0x0c0708de */
if(!s->budget--) { s->failed_pc=0x0c0708deu; return 0; }
goto P_0c0708e8;
P_0c0708e0: /* original 0009, guest PC 0x0c0708e0 */
if(!s->budget--) { s->failed_pc=0x0c0708e0u; return 0; }
return vf3_matrix_family(0x0c0708e2u,s,ram);
P_0c0708e8: /* original f049, guest PC 0x0c0708e8 */
if(!s->budget--) { s->failed_pc=0x0c0708e8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708ea;
P_0c0708ea: /* original f549, guest PC 0x0c0708ea */
if(!s->budget--) { s->failed_pc=0x0c0708eau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0708ec;
P_0c0708ec: /* original f648, guest PC 0x0c0708ec */
if(!s->budget--) { s->failed_pc=0x0c0708ecu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0708ee;
P_0c0708ee: /* original f859, guest PC 0x0c0708ee */
if(!s->budget--) { s->failed_pc=0x0c0708eeu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0708f0;
P_0c0708f0: /* original f959, guest PC 0x0c0708f0 */
if(!s->budget--) { s->failed_pc=0x0c0708f0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0708f2;
P_0c0708f2: /* original fa58, guest PC 0x0c0708f2 */
if(!s->budget--) { s->failed_pc=0x0c0708f2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0708f4;
P_0c0708f4: /* original f35c, guest PC 0x0c0708f4 */
if(!s->budget--) { s->failed_pc=0x0c0708f4u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0708f6;
P_0c0708f6: /* original f382, guest PC 0x0c0708f6 */
if(!s->budget--) { s->failed_pc=0x0c0708f6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0708f8;
P_0c0708f8: /* original f20c, guest PC 0x0c0708f8 */
if(!s->budget--) { s->failed_pc=0x0c0708f8u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0708fa;
P_0c0708fa: /* original f2a2, guest PC 0x0c0708fa */
if(!s->budget--) { s->failed_pc=0x0c0708fau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0708fc;
P_0c0708fc: /* original f16c, guest PC 0x0c0708fc */
if(!s->budget--) { s->failed_pc=0x0c0708fcu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0708fe;
P_0c0708fe: /* original f192, guest PC 0x0c0708fe */
if(!s->budget--) { s->failed_pc=0x0c0708feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070900;
P_0c070900: /* original f34d, guest PC 0x0c070900 */
if(!s->budget--) { s->failed_pc=0x0c070900u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070902;
P_0c070902: /* original f39e, guest PC 0x0c070902 */
if(!s->budget--) { s->failed_pc=0x0c070902u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070904;
P_0c070904: /* original f24d, guest PC 0x0c070904 */
if(!s->budget--) { s->failed_pc=0x0c070904u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070906;
P_0c070906: /* original f06c, guest PC 0x0c070906 */
if(!s->budget--) { s->failed_pc=0x0c070906u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070908;
P_0c070908: /* original f28e, guest PC 0x0c070908 */
if(!s->budget--) { s->failed_pc=0x0c070908u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07090a;
P_0c07090a: /* original f14d, guest PC 0x0c07090a */
if(!s->budget--) { s->failed_pc=0x0c07090au; return 0; }
fr[1]^=0x80000000u;
goto P_0c07090c;
P_0c07090c: /* original f05c, guest PC 0x0c07090c */
if(!s->budget--) { s->failed_pc=0x0c07090cu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07090e;
P_0c07090e: /* original f1ae, guest PC 0x0c07090e */
if(!s->budget--) { s->failed_pc=0x0c07090eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070910;
P_0c070910: /* original f08d, guest PC 0x0c070910 */
if(!s->budget--) { s->failed_pc=0x0c070910u; return 0; }
fr[0]=0;
goto P_0c070912;
P_0c070912: /* original f0ed, guest PC 0x0c070912 */
if(!s->budget--) { s->failed_pc=0x0c070912u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070914;
P_0c070914: /* original f03c, guest PC 0x0c070914 */
if(!s->budget--) { s->failed_pc=0x0c070914u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070916;
P_0c070916: /* original f06d, guest PC 0x0c070916 */
if(!s->budget--) { s->failed_pc=0x0c070916u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070918;
P_0c070918: /* original fc0c, guest PC 0x0c070918 */
if(!s->budget--) { s->failed_pc=0x0c070918u; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c07091a;
P_0c07091a: /* original ffc5, guest PC 0x0c07091a */
if(!s->budget--) { s->failed_pc=0x0c07091au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c07091c;
P_0c07091c: /* original 8902, guest PC 0x0c07091c */
if(!s->budget--) { s->failed_pc=0x0c07091cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070924; }
goto P_0c07091e;
P_0c07091e: /* original d304, guest PC 0x0c07091e */
if(!s->budget--) { s->failed_pc=0x0c07091eu; return 0; }
r[3]=read(ram,0x0c070930u,4);
goto P_0c070920;
P_0c070920: /* original 432b, guest PC 0x0c070920 */
if(!s->budget--) { s->failed_pc=0x0c070920u; return 0; }
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
P_0c070922: /* original 0009, guest PC 0x0c070922 */
if(!s->budget--) { s->failed_pc=0x0c070922u; return 0; }
goto P_0c070924;
P_0c070924: /* original 64f3, guest PC 0x0c070924 */
if(!s->budget--) { s->failed_pc=0x0c070924u; return 0; }
r[4]=r[15];
goto P_0c070926;
P_0c070926: /* original 7444, guest PC 0x0c070926 */
if(!s->budget--) { s->failed_pc=0x0c070926u; return 0; }
r[4]+=0x00000044u;
goto P_0c070928;
P_0c070928: /* original 65b3, guest PC 0x0c070928 */
if(!s->budget--) { s->failed_pc=0x0c070928u; return 0; }
r[5]=r[11];
goto P_0c07092a;
P_0c07092a: /* original a003, guest PC 0x0c07092a */
if(!s->budget--) { s->failed_pc=0x0c07092au; return 0; }
goto P_0c070934;
P_0c07092c: /* original 0009, guest PC 0x0c07092c */
if(!s->budget--) { s->failed_pc=0x0c07092cu; return 0; }
return vf3_matrix_family(0x0c07092eu,s,ram);
P_0c070934: /* original f049, guest PC 0x0c070934 */
if(!s->budget--) { s->failed_pc=0x0c070934u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070936;
P_0c070936: /* original f149, guest PC 0x0c070936 */
if(!s->budget--) { s->failed_pc=0x0c070936u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070938;
P_0c070938: /* original f249, guest PC 0x0c070938 */
if(!s->budget--) { s->failed_pc=0x0c070938u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07093a;
P_0c07093a: /* original f38d, guest PC 0x0c07093a */
if(!s->budget--) { s->failed_pc=0x0c07093au; return 0; }
fr[3]=0;
goto P_0c07093c;
P_0c07093c: /* original f459, guest PC 0x0c07093c */
if(!s->budget--) { s->failed_pc=0x0c07093cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07093e;
P_0c07093e: /* original f559, guest PC 0x0c07093e */
if(!s->budget--) { s->failed_pc=0x0c07093eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070940;
P_0c070940: /* original f659, guest PC 0x0c070940 */
if(!s->budget--) { s->failed_pc=0x0c070940u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070942;
P_0c070942: /* original f78d, guest PC 0x0c070942 */
if(!s->budget--) { s->failed_pc=0x0c070942u; return 0; }
fr[7]=0;
goto P_0c070944;
P_0c070944: /* original f4ed, guest PC 0x0c070944 */
if(!s->budget--) { s->failed_pc=0x0c070944u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070946;
P_0c070946: /* original f07c, guest PC 0x0c070946 */
if(!s->budget--) { s->failed_pc=0x0c070946u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070948;
P_0c070948: /* original f38d, guest PC 0x0c070948 */
if(!s->budget--) { s->failed_pc=0x0c070948u; return 0; }
fr[3]=0;
goto P_0c07094a;
P_0c07094a: /* original f40c, guest PC 0x0c07094a */
if(!s->budget--) { s->failed_pc=0x0c07094au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c07094c;
P_0c07094c: /* original f345, guest PC 0x0c07094c */
if(!s->budget--) { s->failed_pc=0x0c07094cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c07094e;
P_0c07094e: /* original 8902, guest PC 0x0c07094e */
if(!s->budget--) { s->failed_pc=0x0c07094eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070956; }
goto P_0c070950;
P_0c070950: /* original d308, guest PC 0x0c070950 */
if(!s->budget--) { s->failed_pc=0x0c070950u; return 0; }
r[3]=read(ram,0x0c070974u,4);
goto P_0c070952;
P_0c070952: /* original 432b, guest PC 0x0c070952 */
if(!s->budget--) { s->failed_pc=0x0c070952u; return 0; }
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
P_0c070954: /* original 0009, guest PC 0x0c070954 */
if(!s->budget--) { s->failed_pc=0x0c070954u; return 0; }
goto P_0c070956;
P_0c070956: /* original e018, guest PC 0x0c070956 */
if(!s->budget--) { s->failed_pc=0x0c070956u; return 0; }
r[0]=0x00000018u;
goto P_0c070958;
P_0c070958: /* original f3f6, guest PC 0x0c070958 */
if(!s->budget--) { s->failed_pc=0x0c070958u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c07095a;
P_0c07095a: /* original ff35, guest PC 0x0c07095a */
if(!s->budget--) { s->failed_pc=0x0c07095au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c07095c;
P_0c07095c: /* original 8902, guest PC 0x0c07095c */
if(!s->budget--) { s->failed_pc=0x0c07095cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070964; }
goto P_0c07095e;
P_0c07095e: /* original d306, guest PC 0x0c07095e */
if(!s->budget--) { s->failed_pc=0x0c07095eu; return 0; }
r[3]=read(ram,0x0c070978u,4);
goto P_0c070960;
P_0c070960: /* original 432b, guest PC 0x0c070960 */
if(!s->budget--) { s->failed_pc=0x0c070960u; return 0; }
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
P_0c070962: /* original 0009, guest PC 0x0c070962 */
if(!s->budget--) { s->failed_pc=0x0c070962u; return 0; }
goto P_0c070964;
P_0c070964: /* original 64f3, guest PC 0x0c070964 */
if(!s->budget--) { s->failed_pc=0x0c070964u; return 0; }
r[4]=r[15];
goto P_0c070966;
P_0c070966: /* original 65f3, guest PC 0x0c070966 */
if(!s->budget--) { s->failed_pc=0x0c070966u; return 0; }
r[5]=r[15];
goto P_0c070968;
P_0c070968: /* original 7444, guest PC 0x0c070968 */
if(!s->budget--) { s->failed_pc=0x0c070968u; return 0; }
r[4]+=0x00000044u;
goto P_0c07096a;
P_0c07096a: /* original f4fc, guest PC 0x0c07096a */
if(!s->budget--) { s->failed_pc=0x0c07096au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c07096c;
P_0c07096c: /* original 7544, guest PC 0x0c07096c */
if(!s->budget--) { s->failed_pc=0x0c07096cu; return 0; }
r[5]+=0x00000044u;
goto P_0c07096e;
P_0c07096e: /* original a005, guest PC 0x0c07096e */
if(!s->budget--) { s->failed_pc=0x0c07096eu; return 0; }
goto P_0c07097c;
P_0c070970: /* original 0009, guest PC 0x0c070970 */
if(!s->budget--) { s->failed_pc=0x0c070970u; return 0; }
return vf3_matrix_family(0x0c070972u,s,ram);
P_0c07097c: /* original f059, guest PC 0x0c07097c */
if(!s->budget--) { s->failed_pc=0x0c07097cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07097e;
P_0c07097e: /* original f159, guest PC 0x0c07097e */
if(!s->budget--) { s->failed_pc=0x0c07097eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070980;
P_0c070980: /* original f259, guest PC 0x0c070980 */
if(!s->budget--) { s->failed_pc=0x0c070980u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070982;
P_0c070982: /* original f38d, guest PC 0x0c070982 */
if(!s->budget--) { s->failed_pc=0x0c070982u; return 0; }
fr[3]=0;
goto P_0c070984;
P_0c070984: /* original f0ed, guest PC 0x0c070984 */
if(!s->budget--) { s->failed_pc=0x0c070984u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070986;
P_0c070986: /* original f37d, guest PC 0x0c070986 */
if(!s->budget--) { s->failed_pc=0x0c070986u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070988;
P_0c070988: /* original f342, guest PC 0x0c070988 */
if(!s->budget--) { s->failed_pc=0x0c070988u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07098a;
P_0c07098a: /* original 740c, guest PC 0x0c07098a */
if(!s->budget--) { s->failed_pc=0x0c07098au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07098c;
P_0c07098c: /* original f232, guest PC 0x0c07098c */
if(!s->budget--) { s->failed_pc=0x0c07098cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07098e;
P_0c07098e: /* original f132, guest PC 0x0c07098e */
if(!s->budget--) { s->failed_pc=0x0c07098eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070990;
P_0c070990: /* original f032, guest PC 0x0c070990 */
if(!s->budget--) { s->failed_pc=0x0c070990u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070992;
P_0c070992: /* original f42b, guest PC 0x0c070992 */
if(!s->budget--) { s->failed_pc=0x0c070992u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070994;
P_0c070994: /* original f41b, guest PC 0x0c070994 */
if(!s->budget--) { s->failed_pc=0x0c070994u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070996;
P_0c070996: /* original f40b, guest PC 0x0c070996 */
if(!s->budget--) { s->failed_pc=0x0c070996u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070998;
P_0c070998: /* original d306, guest PC 0x0c070998 */
if(!s->budget--) { s->failed_pc=0x0c070998u; return 0; }
r[3]=read(ram,0x0c0709b4u,4);
goto P_0c07099a;
P_0c07099a: /* original 432b, guest PC 0x0c07099a */
if(!s->budget--) { s->failed_pc=0x0c07099au; return 0; }
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
P_0c07099c: /* original 0009, guest PC 0x0c07099c */
if(!s->budget--) { s->failed_pc=0x0c07099cu; return 0; }
goto P_0c07099e;
P_0c07099e: /* original fe45, guest PC 0x0c07099e */
if(!s->budget--) { s->failed_pc=0x0c07099eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0709a0;
P_0c0709a0: /* original 8902, guest PC 0x0c0709a0 */
if(!s->budget--) { s->failed_pc=0x0c0709a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0709a8; }
goto P_0c0709a2;
P_0c0709a2: /* original d305, guest PC 0x0c0709a2 */
if(!s->budget--) { s->failed_pc=0x0c0709a2u; return 0; }
r[3]=read(ram,0x0c0709b8u,4);
goto P_0c0709a4;
P_0c0709a4: /* original 432b, guest PC 0x0c0709a4 */
if(!s->budget--) { s->failed_pc=0x0c0709a4u; return 0; }
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
P_0c0709a6: /* original 0009, guest PC 0x0c0709a6 */
if(!s->budget--) { s->failed_pc=0x0c0709a6u; return 0; }
goto P_0c0709a8;
P_0c0709a8: /* original 64f3, guest PC 0x0c0709a8 */
if(!s->budget--) { s->failed_pc=0x0c0709a8u; return 0; }
r[4]=r[15];
goto P_0c0709aa;
P_0c0709aa: /* original 7438, guest PC 0x0c0709aa */
if(!s->budget--) { s->failed_pc=0x0c0709aau; return 0; }
r[4]+=0x00000038u;
goto P_0c0709ac;
P_0c0709ac: /* original 65b3, guest PC 0x0c0709ac */
if(!s->budget--) { s->failed_pc=0x0c0709acu; return 0; }
r[5]=r[11];
goto P_0c0709ae;
P_0c0709ae: /* original a005, guest PC 0x0c0709ae */
if(!s->budget--) { s->failed_pc=0x0c0709aeu; return 0; }
goto P_0c0709bc;
P_0c0709b0: /* original 0009, guest PC 0x0c0709b0 */
if(!s->budget--) { s->failed_pc=0x0c0709b0u; return 0; }
return vf3_matrix_family(0x0c0709b2u,s,ram);
P_0c0709bc: /* original f059, guest PC 0x0c0709bc */
if(!s->budget--) { s->failed_pc=0x0c0709bcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709be;
P_0c0709be: /* original f159, guest PC 0x0c0709be */
if(!s->budget--) { s->failed_pc=0x0c0709beu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709c0;
P_0c0709c0: /* original f259, guest PC 0x0c0709c0 */
if(!s->budget--) { s->failed_pc=0x0c0709c0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709c2;
P_0c0709c2: /* original 740c, guest PC 0x0c0709c2 */
if(!s->budget--) { s->failed_pc=0x0c0709c2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0709c4;
P_0c0709c4: /* original f242, guest PC 0x0c0709c4 */
if(!s->budget--) { s->failed_pc=0x0c0709c4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0709c6;
P_0c0709c6: /* original f142, guest PC 0x0c0709c6 */
if(!s->budget--) { s->failed_pc=0x0c0709c6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0709c8;
P_0c0709c8: /* original f042, guest PC 0x0c0709c8 */
if(!s->budget--) { s->failed_pc=0x0c0709c8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0709ca;
P_0c0709ca: /* original f42b, guest PC 0x0c0709ca */
if(!s->budget--) { s->failed_pc=0x0c0709cau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0709cc;
P_0c0709cc: /* original f41b, guest PC 0x0c0709cc */
if(!s->budget--) { s->failed_pc=0x0c0709ccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0709ce;
P_0c0709ce: /* original f40b, guest PC 0x0c0709ce */
if(!s->budget--) { s->failed_pc=0x0c0709ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0709d0;
P_0c0709d0: /* original 65f3, guest PC 0x0c0709d0 */
if(!s->budget--) { s->failed_pc=0x0c0709d0u; return 0; }
r[5]=r[15];
goto P_0c0709d2;
P_0c0709d2: /* original 64f3, guest PC 0x0c0709d2 */
if(!s->budget--) { s->failed_pc=0x0c0709d2u; return 0; }
r[4]=r[15];
goto P_0c0709d4;
P_0c0709d4: /* original 66f3, guest PC 0x0c0709d4 */
if(!s->budget--) { s->failed_pc=0x0c0709d4u; return 0; }
r[6]=r[15];
goto P_0c0709d6;
P_0c0709d6: /* original 7438, guest PC 0x0c0709d6 */
if(!s->budget--) { s->failed_pc=0x0c0709d6u; return 0; }
r[4]+=0x00000038u;
goto P_0c0709d8;
P_0c0709d8: /* original 7638, guest PC 0x0c0709d8 */
if(!s->budget--) { s->failed_pc=0x0c0709d8u; return 0; }
r[6]+=0x00000038u;
goto P_0c0709da;
P_0c0709da: /* original 7544, guest PC 0x0c0709da */
if(!s->budget--) { s->failed_pc=0x0c0709dau; return 0; }
r[5]+=0x00000044u;
goto P_0c0709dc;
P_0c0709dc: /* original f059, guest PC 0x0c0709dc */
if(!s->budget--) { s->failed_pc=0x0c0709dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709de;
P_0c0709de: /* original f369, guest PC 0x0c0709de */
if(!s->budget--) { s->failed_pc=0x0c0709deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e0;
P_0c0709e0: /* original f159, guest PC 0x0c0709e0 */
if(!s->budget--) { s->failed_pc=0x0c0709e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e2;
P_0c0709e2: /* original f469, guest PC 0x0c0709e2 */
if(!s->budget--) { s->failed_pc=0x0c0709e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e4;
P_0c0709e4: /* original f031, guest PC 0x0c0709e4 */
if(!s->budget--) { s->failed_pc=0x0c0709e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0709e6;
P_0c0709e6: /* original f258, guest PC 0x0c0709e6 */
if(!s->budget--) { s->failed_pc=0x0c0709e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0709e8;
P_0c0709e8: /* original f568, guest PC 0x0c0709e8 */
if(!s->budget--) { s->failed_pc=0x0c0709e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0709ea;
P_0c0709ea: /* original f141, guest PC 0x0c0709ea */
if(!s->budget--) { s->failed_pc=0x0c0709eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0709ec;
P_0c0709ec: /* original f251, guest PC 0x0c0709ec */
if(!s->budget--) { s->failed_pc=0x0c0709ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0709ee;
P_0c0709ee: /* original 7408, guest PC 0x0c0709ee */
if(!s->budget--) { s->failed_pc=0x0c0709eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0709f0;
P_0c0709f0: /* original f42a, guest PC 0x0c0709f0 */
if(!s->budget--) { s->failed_pc=0x0c0709f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0709f2;
P_0c0709f2: /* original f41b, guest PC 0x0c0709f2 */
if(!s->budget--) { s->failed_pc=0x0c0709f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0709f4;
P_0c0709f4: /* original f40b, guest PC 0x0c0709f4 */
if(!s->budget--) { s->failed_pc=0x0c0709f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0709f6;
P_0c0709f6: /* original 0009, guest PC 0x0c0709f6 */
if(!s->budget--) { s->failed_pc=0x0c0709f6u; return 0; }
goto P_0c0709f8;
P_0c0709f8: /* original f4fc, guest PC 0x0c0709f8 */
if(!s->budget--) { s->failed_pc=0x0c0709f8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0709fa;
P_0c0709fa: /* original f4c1, guest PC 0x0c0709fa */
if(!s->budget--) { s->failed_pc=0x0c0709fau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c0709fc;
P_0c0709fc: /* original 64f3, guest PC 0x0c0709fc */
if(!s->budget--) { s->failed_pc=0x0c0709fcu; return 0; }
r[4]=r[15];
goto P_0c0709fe;
P_0c0709fe: /* original 65f3, guest PC 0x0c0709fe */
if(!s->budget--) { s->failed_pc=0x0c0709feu; return 0; }
r[5]=r[15];
goto P_0c070a00;
P_0c070a00: /* original 7438, guest PC 0x0c070a00 */
if(!s->budget--) { s->failed_pc=0x0c070a00u; return 0; }
r[4]+=0x00000038u;
goto P_0c070a02;
P_0c070a02: /* original 7538, guest PC 0x0c070a02 */
if(!s->budget--) { s->failed_pc=0x0c070a02u; return 0; }
r[5]+=0x00000038u;
goto P_0c070a04;
P_0c070a04: /* original f059, guest PC 0x0c070a04 */
if(!s->budget--) { s->failed_pc=0x0c070a04u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a06;
P_0c070a06: /* original f159, guest PC 0x0c070a06 */
if(!s->budget--) { s->failed_pc=0x0c070a06u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a08;
P_0c070a08: /* original f259, guest PC 0x0c070a08 */
if(!s->budget--) { s->failed_pc=0x0c070a08u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a0a;
P_0c070a0a: /* original f38d, guest PC 0x0c070a0a */
if(!s->budget--) { s->failed_pc=0x0c070a0au; return 0; }
fr[3]=0;
goto P_0c070a0c;
P_0c070a0c: /* original f0ed, guest PC 0x0c070a0c */
if(!s->budget--) { s->failed_pc=0x0c070a0cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070a0e;
P_0c070a0e: /* original f37d, guest PC 0x0c070a0e */
if(!s->budget--) { s->failed_pc=0x0c070a0eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070a10;
P_0c070a10: /* original f342, guest PC 0x0c070a10 */
if(!s->budget--) { s->failed_pc=0x0c070a10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070a12;
P_0c070a12: /* original 740c, guest PC 0x0c070a12 */
if(!s->budget--) { s->failed_pc=0x0c070a12u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070a14;
P_0c070a14: /* original f232, guest PC 0x0c070a14 */
if(!s->budget--) { s->failed_pc=0x0c070a14u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070a16;
P_0c070a16: /* original f132, guest PC 0x0c070a16 */
if(!s->budget--) { s->failed_pc=0x0c070a16u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070a18;
P_0c070a18: /* original f032, guest PC 0x0c070a18 */
if(!s->budget--) { s->failed_pc=0x0c070a18u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070a1a;
P_0c070a1a: /* original f42b, guest PC 0x0c070a1a */
if(!s->budget--) { s->failed_pc=0x0c070a1au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a1c;
P_0c070a1c: /* original f41b, guest PC 0x0c070a1c */
if(!s->budget--) { s->failed_pc=0x0c070a1cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a1e;
P_0c070a1e: /* original f40b, guest PC 0x0c070a1e */
if(!s->budget--) { s->failed_pc=0x0c070a1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a20;
P_0c070a20: /* original 64f3, guest PC 0x0c070a20 */
if(!s->budget--) { s->failed_pc=0x0c070a20u; return 0; }
r[4]=r[15];
goto P_0c070a22;
P_0c070a22: /* original 65f3, guest PC 0x0c070a22 */
if(!s->budget--) { s->failed_pc=0x0c070a22u; return 0; }
r[5]=r[15];
goto P_0c070a24;
P_0c070a24: /* original 7444, guest PC 0x0c070a24 */
if(!s->budget--) { s->failed_pc=0x0c070a24u; return 0; }
r[4]+=0x00000044u;
goto P_0c070a26;
P_0c070a26: /* original 7538, guest PC 0x0c070a26 */
if(!s->budget--) { s->failed_pc=0x0c070a26u; return 0; }
r[5]+=0x00000038u;
goto P_0c070a28;
P_0c070a28: /* original f049, guest PC 0x0c070a28 */
if(!s->budget--) { s->failed_pc=0x0c070a28u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2a;
P_0c070a2a: /* original f359, guest PC 0x0c070a2a */
if(!s->budget--) { s->failed_pc=0x0c070a2au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2c;
P_0c070a2c: /* original f149, guest PC 0x0c070a2c */
if(!s->budget--) { s->failed_pc=0x0c070a2cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2e;
P_0c070a2e: /* original f459, guest PC 0x0c070a2e */
if(!s->budget--) { s->failed_pc=0x0c070a2eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a30;
P_0c070a30: /* original f249, guest PC 0x0c070a30 */
if(!s->budget--) { s->failed_pc=0x0c070a30u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a32;
P_0c070a32: /* original f559, guest PC 0x0c070a32 */
if(!s->budget--) { s->failed_pc=0x0c070a32u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a34;
P_0c070a34: /* original f030, guest PC 0x0c070a34 */
if(!s->budget--) { s->failed_pc=0x0c070a34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070a36;
P_0c070a36: /* original f250, guest PC 0x0c070a36 */
if(!s->budget--) { s->failed_pc=0x0c070a36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070a38;
P_0c070a38: /* original f140, guest PC 0x0c070a38 */
if(!s->budget--) { s->failed_pc=0x0c070a38u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070a3a;
P_0c070a3a: /* original f42b, guest PC 0x0c070a3a */
if(!s->budget--) { s->failed_pc=0x0c070a3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a3c;
P_0c070a3c: /* original f41b, guest PC 0x0c070a3c */
if(!s->budget--) { s->failed_pc=0x0c070a3cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a3e;
P_0c070a3e: /* original f40b, guest PC 0x0c070a3e */
if(!s->budget--) { s->failed_pc=0x0c070a3eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a40;
P_0c070a40: /* original 65f3, guest PC 0x0c070a40 */
if(!s->budget--) { s->failed_pc=0x0c070a40u; return 0; }
r[5]=r[15];
goto P_0c070a42;
P_0c070a42: /* original 64e3, guest PC 0x0c070a42 */
if(!s->budget--) { s->failed_pc=0x0c070a42u; return 0; }
r[4]=r[14];
goto P_0c070a44;
P_0c070a44: /* original 7544, guest PC 0x0c070a44 */
if(!s->budget--) { s->failed_pc=0x0c070a44u; return 0; }
r[5]+=0x00000044u;
goto P_0c070a46;
P_0c070a46: /* original 66a3, guest PC 0x0c070a46 */
if(!s->budget--) { s->failed_pc=0x0c070a46u; return 0; }
r[6]=r[10];
goto P_0c070a48;
P_0c070a48: /* original f059, guest PC 0x0c070a48 */
if(!s->budget--) { s->failed_pc=0x0c070a48u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4a;
P_0c070a4a: /* original f369, guest PC 0x0c070a4a */
if(!s->budget--) { s->failed_pc=0x0c070a4au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4c;
P_0c070a4c: /* original f159, guest PC 0x0c070a4c */
if(!s->budget--) { s->failed_pc=0x0c070a4cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4e;
P_0c070a4e: /* original f469, guest PC 0x0c070a4e */
if(!s->budget--) { s->failed_pc=0x0c070a4eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a50;
P_0c070a50: /* original f259, guest PC 0x0c070a50 */
if(!s->budget--) { s->failed_pc=0x0c070a50u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a52;
P_0c070a52: /* original f569, guest PC 0x0c070a52 */
if(!s->budget--) { s->failed_pc=0x0c070a52u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a54;
P_0c070a54: /* original 740c, guest PC 0x0c070a54 */
if(!s->budget--) { s->failed_pc=0x0c070a54u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070a56;
P_0c070a56: /* original f030, guest PC 0x0c070a56 */
if(!s->budget--) { s->failed_pc=0x0c070a56u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070a58;
P_0c070a58: /* original f250, guest PC 0x0c070a58 */
if(!s->budget--) { s->failed_pc=0x0c070a58u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070a5a;
P_0c070a5a: /* original f140, guest PC 0x0c070a5a */
if(!s->budget--) { s->failed_pc=0x0c070a5au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070a5c;
P_0c070a5c: /* original f42b, guest PC 0x0c070a5c */
if(!s->budget--) { s->failed_pc=0x0c070a5cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a5e;
P_0c070a5e: /* original f41b, guest PC 0x0c070a5e */
if(!s->budget--) { s->failed_pc=0x0c070a5eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a60;
P_0c070a60: /* original f40b, guest PC 0x0c070a60 */
if(!s->budget--) { s->failed_pc=0x0c070a60u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a62;
P_0c070a62: /* original 0009, guest PC 0x0c070a62 */
if(!s->budget--) { s->failed_pc=0x0c070a62u; return 0; }
goto P_0c070a64;
P_0c070a64: /* original 64f3, guest PC 0x0c070a64 */
if(!s->budget--) { s->failed_pc=0x0c070a64u; return 0; }
r[4]=r[15];
goto P_0c070a66;
P_0c070a66: /* original 7444, guest PC 0x0c070a66 */
if(!s->budget--) { s->failed_pc=0x0c070a66u; return 0; }
r[4]+=0x00000044u;
goto P_0c070a68;
P_0c070a68: /* original 6693, guest PC 0x0c070a68 */
if(!s->budget--) { s->failed_pc=0x0c070a68u; return 0; }
r[6]=r[9];
goto P_0c070a6a;
P_0c070a6a: /* original 65e3, guest PC 0x0c070a6a */
if(!s->budget--) { s->failed_pc=0x0c070a6au; return 0; }
r[5]=r[14];
goto P_0c070a6c;
P_0c070a6c: /* original f059, guest PC 0x0c070a6c */
if(!s->budget--) { s->failed_pc=0x0c070a6cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a6e;
P_0c070a6e: /* original f369, guest PC 0x0c070a6e */
if(!s->budget--) { s->failed_pc=0x0c070a6eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a70;
P_0c070a70: /* original f159, guest PC 0x0c070a70 */
if(!s->budget--) { s->failed_pc=0x0c070a70u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a72;
P_0c070a72: /* original f469, guest PC 0x0c070a72 */
if(!s->budget--) { s->failed_pc=0x0c070a72u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a74;
P_0c070a74: /* original f031, guest PC 0x0c070a74 */
if(!s->budget--) { s->failed_pc=0x0c070a74u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070a76;
P_0c070a76: /* original f258, guest PC 0x0c070a76 */
if(!s->budget--) { s->failed_pc=0x0c070a76u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070a78;
P_0c070a78: /* original f568, guest PC 0x0c070a78 */
if(!s->budget--) { s->failed_pc=0x0c070a78u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070a7a;
P_0c070a7a: /* original f141, guest PC 0x0c070a7a */
if(!s->budget--) { s->failed_pc=0x0c070a7au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070a7c;
P_0c070a7c: /* original f251, guest PC 0x0c070a7c */
if(!s->budget--) { s->failed_pc=0x0c070a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070a7e;
P_0c070a7e: /* original 7408, guest PC 0x0c070a7e */
if(!s->budget--) { s->failed_pc=0x0c070a7eu; return 0; }
r[4]+=0x00000008u;
goto P_0c070a80;
P_0c070a80: /* original f42a, guest PC 0x0c070a80 */
if(!s->budget--) { s->failed_pc=0x0c070a80u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a82;
P_0c070a82: /* original f41b, guest PC 0x0c070a82 */
if(!s->budget--) { s->failed_pc=0x0c070a82u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a84;
P_0c070a84: /* original f40b, guest PC 0x0c070a84 */
if(!s->budget--) { s->failed_pc=0x0c070a84u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a86;
P_0c070a86: /* original 0009, guest PC 0x0c070a86 */
if(!s->budget--) { s->failed_pc=0x0c070a86u; return 0; }
goto P_0c070a88;
P_0c070a88: /* original 64f3, guest PC 0x0c070a88 */
if(!s->budget--) { s->failed_pc=0x0c070a88u; return 0; }
r[4]=r[15];
goto P_0c070a8a;
P_0c070a8a: /* original 7444, guest PC 0x0c070a8a */
if(!s->budget--) { s->failed_pc=0x0c070a8au; return 0; }
r[4]+=0x00000044u;
goto P_0c070a8c;
P_0c070a8c: /* original f049, guest PC 0x0c070a8c */
if(!s->budget--) { s->failed_pc=0x0c070a8cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a8e;
P_0c070a8e: /* original f149, guest PC 0x0c070a8e */
if(!s->budget--) { s->failed_pc=0x0c070a8eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a90;
P_0c070a90: /* original f249, guest PC 0x0c070a90 */
if(!s->budget--) { s->failed_pc=0x0c070a90u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a92;
P_0c070a92: /* original f38d, guest PC 0x0c070a92 */
if(!s->budget--) { s->failed_pc=0x0c070a92u; return 0; }
fr[3]=0;
goto P_0c070a94;
P_0c070a94: /* original f0ed, guest PC 0x0c070a94 */
if(!s->budget--) { s->failed_pc=0x0c070a94u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070a96;
P_0c070a96: /* original f03c, guest PC 0x0c070a96 */
if(!s->budget--) { s->failed_pc=0x0c070a96u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070a98;
P_0c070a98: /* original f06d, guest PC 0x0c070a98 */
if(!s->budget--) { s->failed_pc=0x0c070a98u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070a9a;
P_0c070a9a: /* original 0009, guest PC 0x0c070a9a */
if(!s->budget--) { s->failed_pc=0x0c070a9au; return 0; }
goto P_0c070a9c;
P_0c070a9c: /* original f38d, guest PC 0x0c070a9c */
if(!s->budget--) { s->failed_pc=0x0c070a9cu; return 0; }
fr[3]=0;
goto P_0c070a9e;
P_0c070a9e: /* original f035, guest PC 0x0c070a9e */
if(!s->budget--) { s->failed_pc=0x0c070a9eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070aa0;
P_0c070aa0: /* original e020, guest PC 0x0c070aa0 */
if(!s->budget--) { s->failed_pc=0x0c070aa0u; return 0; }
r[0]=0x00000020u;
goto P_0c070aa2;
P_0c070aa2: /* original 8d03, guest PC 0x0c070aa2 */
if(!s->budget--) { s->failed_pc=0x0c070aa2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070aac; }
goto P_0c070aa6;
P_0c070aa4: /* original ff07, guest PC 0x0c070aa4 */
if(!s->budget--) { s->failed_pc=0x0c070aa4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070aa6;
P_0c070aa6: /* original d304, guest PC 0x0c070aa6 */
if(!s->budget--) { s->failed_pc=0x0c070aa6u; return 0; }
r[3]=read(ram,0x0c070ab8u,4);
goto P_0c070aa8;
P_0c070aa8: /* original 432b, guest PC 0x0c070aa8 */
if(!s->budget--) { s->failed_pc=0x0c070aa8u; return 0; }
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
P_0c070aaa: /* original 0009, guest PC 0x0c070aaa */
if(!s->budget--) { s->failed_pc=0x0c070aaau; return 0; }
goto P_0c070aac;
P_0c070aac: /* original 64f3, guest PC 0x0c070aac */
if(!s->budget--) { s->failed_pc=0x0c070aacu; return 0; }
r[4]=r[15];
goto P_0c070aae;
P_0c070aae: /* original 7444, guest PC 0x0c070aae */
if(!s->budget--) { s->failed_pc=0x0c070aaeu; return 0; }
r[4]+=0x00000044u;
goto P_0c070ab0;
P_0c070ab0: /* original 65c3, guest PC 0x0c070ab0 */
if(!s->budget--) { s->failed_pc=0x0c070ab0u; return 0; }
r[5]=r[12];
goto P_0c070ab2;
P_0c070ab2: /* original a003, guest PC 0x0c070ab2 */
if(!s->budget--) { s->failed_pc=0x0c070ab2u; return 0; }
goto P_0c070abc;
P_0c070ab4: /* original 0009, guest PC 0x0c070ab4 */
if(!s->budget--) { s->failed_pc=0x0c070ab4u; return 0; }
return vf3_matrix_family(0x0c070ab6u,s,ram);
P_0c070abc: /* original f049, guest PC 0x0c070abc */
if(!s->budget--) { s->failed_pc=0x0c070abcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070abe;
P_0c070abe: /* original f549, guest PC 0x0c070abe */
if(!s->budget--) { s->failed_pc=0x0c070abeu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac0;
P_0c070ac0: /* original f648, guest PC 0x0c070ac0 */
if(!s->budget--) { s->failed_pc=0x0c070ac0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070ac2;
P_0c070ac2: /* original f859, guest PC 0x0c070ac2 */
if(!s->budget--) { s->failed_pc=0x0c070ac2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac4;
P_0c070ac4: /* original f959, guest PC 0x0c070ac4 */
if(!s->budget--) { s->failed_pc=0x0c070ac4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac6;
P_0c070ac6: /* original fa58, guest PC 0x0c070ac6 */
if(!s->budget--) { s->failed_pc=0x0c070ac6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070ac8;
P_0c070ac8: /* original f35c, guest PC 0x0c070ac8 */
if(!s->budget--) { s->failed_pc=0x0c070ac8u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070aca;
P_0c070aca: /* original f382, guest PC 0x0c070aca */
if(!s->budget--) { s->failed_pc=0x0c070acau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070acc;
P_0c070acc: /* original f20c, guest PC 0x0c070acc */
if(!s->budget--) { s->failed_pc=0x0c070accu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070ace;
P_0c070ace: /* original f2a2, guest PC 0x0c070ace */
if(!s->budget--) { s->failed_pc=0x0c070aceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070ad0;
P_0c070ad0: /* original f16c, guest PC 0x0c070ad0 */
if(!s->budget--) { s->failed_pc=0x0c070ad0u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070ad2;
P_0c070ad2: /* original f192, guest PC 0x0c070ad2 */
if(!s->budget--) { s->failed_pc=0x0c070ad2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070ad4;
P_0c070ad4: /* original f34d, guest PC 0x0c070ad4 */
if(!s->budget--) { s->failed_pc=0x0c070ad4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070ad6;
P_0c070ad6: /* original f39e, guest PC 0x0c070ad6 */
if(!s->budget--) { s->failed_pc=0x0c070ad6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070ad8;
P_0c070ad8: /* original f24d, guest PC 0x0c070ad8 */
if(!s->budget--) { s->failed_pc=0x0c070ad8u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070ada;
P_0c070ada: /* original f06c, guest PC 0x0c070ada */
if(!s->budget--) { s->failed_pc=0x0c070adau; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070adc;
P_0c070adc: /* original f28e, guest PC 0x0c070adc */
if(!s->budget--) { s->failed_pc=0x0c070adcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070ade;
P_0c070ade: /* original f14d, guest PC 0x0c070ade */
if(!s->budget--) { s->failed_pc=0x0c070adeu; return 0; }
fr[1]^=0x80000000u;
goto P_0c070ae0;
P_0c070ae0: /* original f05c, guest PC 0x0c070ae0 */
if(!s->budget--) { s->failed_pc=0x0c070ae0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070ae2;
P_0c070ae2: /* original f1ae, guest PC 0x0c070ae2 */
if(!s->budget--) { s->failed_pc=0x0c070ae2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070ae4;
P_0c070ae4: /* original f08d, guest PC 0x0c070ae4 */
if(!s->budget--) { s->failed_pc=0x0c070ae4u; return 0; }
fr[0]=0;
goto P_0c070ae6;
P_0c070ae6: /* original f0ed, guest PC 0x0c070ae6 */
if(!s->budget--) { s->failed_pc=0x0c070ae6u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070ae8;
P_0c070ae8: /* original f03c, guest PC 0x0c070ae8 */
if(!s->budget--) { s->failed_pc=0x0c070ae8u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070aea;
P_0c070aea: /* original f06d, guest PC 0x0c070aea */
if(!s->budget--) { s->failed_pc=0x0c070aeau; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070aec;
P_0c070aec: /* original fc0c, guest PC 0x0c070aec */
if(!s->budget--) { s->failed_pc=0x0c070aecu; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070aee;
P_0c070aee: /* original ffc5, guest PC 0x0c070aee */
if(!s->budget--) { s->failed_pc=0x0c070aeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070af0;
P_0c070af0: /* original 8902, guest PC 0x0c070af0 */
if(!s->budget--) { s->failed_pc=0x0c070af0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070af8; }
goto P_0c070af2;
P_0c070af2: /* original d304, guest PC 0x0c070af2 */
if(!s->budget--) { s->failed_pc=0x0c070af2u; return 0; }
r[3]=read(ram,0x0c070b04u,4);
goto P_0c070af4;
P_0c070af4: /* original 432b, guest PC 0x0c070af4 */
if(!s->budget--) { s->failed_pc=0x0c070af4u; return 0; }
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
P_0c070af6: /* original 0009, guest PC 0x0c070af6 */
if(!s->budget--) { s->failed_pc=0x0c070af6u; return 0; }
goto P_0c070af8;
P_0c070af8: /* original 64f3, guest PC 0x0c070af8 */
if(!s->budget--) { s->failed_pc=0x0c070af8u; return 0; }
r[4]=r[15];
goto P_0c070afa;
P_0c070afa: /* original 7444, guest PC 0x0c070afa */
if(!s->budget--) { s->failed_pc=0x0c070afau; return 0; }
r[4]+=0x00000044u;
goto P_0c070afc;
P_0c070afc: /* original 65c3, guest PC 0x0c070afc */
if(!s->budget--) { s->failed_pc=0x0c070afcu; return 0; }
r[5]=r[12];
goto P_0c070afe;
P_0c070afe: /* original a003, guest PC 0x0c070afe */
if(!s->budget--) { s->failed_pc=0x0c070afeu; return 0; }
goto P_0c070b08;
P_0c070b00: /* original 0009, guest PC 0x0c070b00 */
if(!s->budget--) { s->failed_pc=0x0c070b00u; return 0; }
return vf3_matrix_family(0x0c070b02u,s,ram);
P_0c070b08: /* original f049, guest PC 0x0c070b08 */
if(!s->budget--) { s->failed_pc=0x0c070b08u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0a;
P_0c070b0a: /* original f149, guest PC 0x0c070b0a */
if(!s->budget--) { s->failed_pc=0x0c070b0au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0c;
P_0c070b0c: /* original f249, guest PC 0x0c070b0c */
if(!s->budget--) { s->failed_pc=0x0c070b0cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0e;
P_0c070b0e: /* original f38d, guest PC 0x0c070b0e */
if(!s->budget--) { s->failed_pc=0x0c070b0eu; return 0; }
fr[3]=0;
goto P_0c070b10;
P_0c070b10: /* original f459, guest PC 0x0c070b10 */
if(!s->budget--) { s->failed_pc=0x0c070b10u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b12;
P_0c070b12: /* original f559, guest PC 0x0c070b12 */
if(!s->budget--) { s->failed_pc=0x0c070b12u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b14;
P_0c070b14: /* original f659, guest PC 0x0c070b14 */
if(!s->budget--) { s->failed_pc=0x0c070b14u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b16;
P_0c070b16: /* original f78d, guest PC 0x0c070b16 */
if(!s->budget--) { s->failed_pc=0x0c070b16u; return 0; }
fr[7]=0;
goto P_0c070b18;
P_0c070b18: /* original f4ed, guest PC 0x0c070b18 */
if(!s->budget--) { s->failed_pc=0x0c070b18u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070b1a;
P_0c070b1a: /* original f07c, guest PC 0x0c070b1a */
if(!s->budget--) { s->failed_pc=0x0c070b1au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070b1c;
P_0c070b1c: /* original f38d, guest PC 0x0c070b1c */
if(!s->budget--) { s->failed_pc=0x0c070b1cu; return 0; }
fr[3]=0;
goto P_0c070b1e;
P_0c070b1e: /* original f40c, guest PC 0x0c070b1e */
if(!s->budget--) { s->failed_pc=0x0c070b1eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070b20;
P_0c070b20: /* original f345, guest PC 0x0c070b20 */
if(!s->budget--) { s->failed_pc=0x0c070b20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070b22;
P_0c070b22: /* original 8902, guest PC 0x0c070b22 */
if(!s->budget--) { s->failed_pc=0x0c070b22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070b2a; }
goto P_0c070b24;
P_0c070b24: /* original d308, guest PC 0x0c070b24 */
if(!s->budget--) { s->failed_pc=0x0c070b24u; return 0; }
r[3]=read(ram,0x0c070b48u,4);
goto P_0c070b26;
P_0c070b26: /* original 432b, guest PC 0x0c070b26 */
if(!s->budget--) { s->failed_pc=0x0c070b26u; return 0; }
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
P_0c070b28: /* original 0009, guest PC 0x0c070b28 */
if(!s->budget--) { s->failed_pc=0x0c070b28u; return 0; }
goto P_0c070b2a;
P_0c070b2a: /* original e020, guest PC 0x0c070b2a */
if(!s->budget--) { s->failed_pc=0x0c070b2au; return 0; }
r[0]=0x00000020u;
goto P_0c070b2c;
P_0c070b2c: /* original f3f6, guest PC 0x0c070b2c */
if(!s->budget--) { s->failed_pc=0x0c070b2cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070b2e;
P_0c070b2e: /* original ff35, guest PC 0x0c070b2e */
if(!s->budget--) { s->failed_pc=0x0c070b2eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c070b30;
P_0c070b30: /* original 8902, guest PC 0x0c070b30 */
if(!s->budget--) { s->failed_pc=0x0c070b30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070b38; }
goto P_0c070b32;
P_0c070b32: /* original d306, guest PC 0x0c070b32 */
if(!s->budget--) { s->failed_pc=0x0c070b32u; return 0; }
r[3]=read(ram,0x0c070b4cu,4);
goto P_0c070b34;
P_0c070b34: /* original 432b, guest PC 0x0c070b34 */
if(!s->budget--) { s->failed_pc=0x0c070b34u; return 0; }
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
P_0c070b36: /* original 0009, guest PC 0x0c070b36 */
if(!s->budget--) { s->failed_pc=0x0c070b36u; return 0; }
goto P_0c070b38;
P_0c070b38: /* original 64f3, guest PC 0x0c070b38 */
if(!s->budget--) { s->failed_pc=0x0c070b38u; return 0; }
r[4]=r[15];
goto P_0c070b3a;
P_0c070b3a: /* original 65f3, guest PC 0x0c070b3a */
if(!s->budget--) { s->failed_pc=0x0c070b3au; return 0; }
r[5]=r[15];
goto P_0c070b3c;
P_0c070b3c: /* original 7444, guest PC 0x0c070b3c */
if(!s->budget--) { s->failed_pc=0x0c070b3cu; return 0; }
r[4]+=0x00000044u;
goto P_0c070b3e;
P_0c070b3e: /* original f4fc, guest PC 0x0c070b3e */
if(!s->budget--) { s->failed_pc=0x0c070b3eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070b40;
P_0c070b40: /* original 7544, guest PC 0x0c070b40 */
if(!s->budget--) { s->failed_pc=0x0c070b40u; return 0; }
r[5]+=0x00000044u;
goto P_0c070b42;
P_0c070b42: /* original a005, guest PC 0x0c070b42 */
if(!s->budget--) { s->failed_pc=0x0c070b42u; return 0; }
goto P_0c070b50;
P_0c070b44: /* original 0009, guest PC 0x0c070b44 */
if(!s->budget--) { s->failed_pc=0x0c070b44u; return 0; }
return vf3_matrix_family(0x0c070b46u,s,ram);
P_0c070b50: /* original f059, guest PC 0x0c070b50 */
if(!s->budget--) { s->failed_pc=0x0c070b50u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b52;
P_0c070b52: /* original f159, guest PC 0x0c070b52 */
if(!s->budget--) { s->failed_pc=0x0c070b52u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b54;
P_0c070b54: /* original f259, guest PC 0x0c070b54 */
if(!s->budget--) { s->failed_pc=0x0c070b54u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b56;
P_0c070b56: /* original f38d, guest PC 0x0c070b56 */
if(!s->budget--) { s->failed_pc=0x0c070b56u; return 0; }
fr[3]=0;
goto P_0c070b58;
P_0c070b58: /* original f0ed, guest PC 0x0c070b58 */
if(!s->budget--) { s->failed_pc=0x0c070b58u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070b5a;
P_0c070b5a: /* original f37d, guest PC 0x0c070b5a */
if(!s->budget--) { s->failed_pc=0x0c070b5au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070b5c;
P_0c070b5c: /* original f342, guest PC 0x0c070b5c */
if(!s->budget--) { s->failed_pc=0x0c070b5cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070b5e;
P_0c070b5e: /* original 740c, guest PC 0x0c070b5e */
if(!s->budget--) { s->failed_pc=0x0c070b5eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070b60;
P_0c070b60: /* original f232, guest PC 0x0c070b60 */
if(!s->budget--) { s->failed_pc=0x0c070b60u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070b62;
P_0c070b62: /* original f132, guest PC 0x0c070b62 */
if(!s->budget--) { s->failed_pc=0x0c070b62u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070b64;
P_0c070b64: /* original f032, guest PC 0x0c070b64 */
if(!s->budget--) { s->failed_pc=0x0c070b64u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070b66;
P_0c070b66: /* original f42b, guest PC 0x0c070b66 */
if(!s->budget--) { s->failed_pc=0x0c070b66u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070b68;
P_0c070b68: /* original f41b, guest PC 0x0c070b68 */
if(!s->budget--) { s->failed_pc=0x0c070b68u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070b6a;
P_0c070b6a: /* original f40b, guest PC 0x0c070b6a */
if(!s->budget--) { s->failed_pc=0x0c070b6au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070b6c;
P_0c070b6c: /* original d306, guest PC 0x0c070b6c */
if(!s->budget--) { s->failed_pc=0x0c070b6cu; return 0; }
r[3]=read(ram,0x0c070b88u,4);
goto P_0c070b6e;
P_0c070b6e: /* original 432b, guest PC 0x0c070b6e */
if(!s->budget--) { s->failed_pc=0x0c070b6eu; return 0; }
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
P_0c070b70: /* original 0009, guest PC 0x0c070b70 */
if(!s->budget--) { s->failed_pc=0x0c070b70u; return 0; }
goto P_0c070b72;
P_0c070b72: /* original fe45, guest PC 0x0c070b72 */
if(!s->budget--) { s->failed_pc=0x0c070b72u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c070b74;
P_0c070b74: /* original 8902, guest PC 0x0c070b74 */
if(!s->budget--) { s->failed_pc=0x0c070b74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070b7c; }
goto P_0c070b76;
P_0c070b76: /* original d305, guest PC 0x0c070b76 */
if(!s->budget--) { s->failed_pc=0x0c070b76u; return 0; }
r[3]=read(ram,0x0c070b8cu,4);
goto P_0c070b78;
P_0c070b78: /* original 432b, guest PC 0x0c070b78 */
if(!s->budget--) { s->failed_pc=0x0c070b78u; return 0; }
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
P_0c070b7a: /* original 0009, guest PC 0x0c070b7a */
if(!s->budget--) { s->failed_pc=0x0c070b7au; return 0; }
goto P_0c070b7c;
P_0c070b7c: /* original 64f3, guest PC 0x0c070b7c */
if(!s->budget--) { s->failed_pc=0x0c070b7cu; return 0; }
r[4]=r[15];
goto P_0c070b7e;
P_0c070b7e: /* original 7438, guest PC 0x0c070b7e */
if(!s->budget--) { s->failed_pc=0x0c070b7eu; return 0; }
r[4]+=0x00000038u;
goto P_0c070b80;
P_0c070b80: /* original 65c3, guest PC 0x0c070b80 */
if(!s->budget--) { s->failed_pc=0x0c070b80u; return 0; }
r[5]=r[12];
goto P_0c070b82;
P_0c070b82: /* original a005, guest PC 0x0c070b82 */
if(!s->budget--) { s->failed_pc=0x0c070b82u; return 0; }
goto P_0c070b90;
P_0c070b84: /* original 0009, guest PC 0x0c070b84 */
if(!s->budget--) { s->failed_pc=0x0c070b84u; return 0; }
return vf3_matrix_family(0x0c070b86u,s,ram);
P_0c070b90: /* original f059, guest PC 0x0c070b90 */
if(!s->budget--) { s->failed_pc=0x0c070b90u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b92;
P_0c070b92: /* original f159, guest PC 0x0c070b92 */
if(!s->budget--) { s->failed_pc=0x0c070b92u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b94;
P_0c070b94: /* original f259, guest PC 0x0c070b94 */
if(!s->budget--) { s->failed_pc=0x0c070b94u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b96;
P_0c070b96: /* original 740c, guest PC 0x0c070b96 */
if(!s->budget--) { s->failed_pc=0x0c070b96u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070b98;
P_0c070b98: /* original f242, guest PC 0x0c070b98 */
if(!s->budget--) { s->failed_pc=0x0c070b98u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070b9a;
P_0c070b9a: /* original f142, guest PC 0x0c070b9a */
if(!s->budget--) { s->failed_pc=0x0c070b9au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070b9c;
P_0c070b9c: /* original f042, guest PC 0x0c070b9c */
if(!s->budget--) { s->failed_pc=0x0c070b9cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070b9e;
P_0c070b9e: /* original f42b, guest PC 0x0c070b9e */
if(!s->budget--) { s->failed_pc=0x0c070b9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ba0;
P_0c070ba0: /* original f41b, guest PC 0x0c070ba0 */
if(!s->budget--) { s->failed_pc=0x0c070ba0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ba2;
P_0c070ba2: /* original f40b, guest PC 0x0c070ba2 */
if(!s->budget--) { s->failed_pc=0x0c070ba2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ba4;
P_0c070ba4: /* original 65f3, guest PC 0x0c070ba4 */
if(!s->budget--) { s->failed_pc=0x0c070ba4u; return 0; }
r[5]=r[15];
goto P_0c070ba6;
P_0c070ba6: /* original 64f3, guest PC 0x0c070ba6 */
if(!s->budget--) { s->failed_pc=0x0c070ba6u; return 0; }
r[4]=r[15];
goto P_0c070ba8;
P_0c070ba8: /* original 66f3, guest PC 0x0c070ba8 */
if(!s->budget--) { s->failed_pc=0x0c070ba8u; return 0; }
r[6]=r[15];
goto P_0c070baa;
P_0c070baa: /* original 7438, guest PC 0x0c070baa */
if(!s->budget--) { s->failed_pc=0x0c070baau; return 0; }
r[4]+=0x00000038u;
goto P_0c070bac;
P_0c070bac: /* original 7638, guest PC 0x0c070bac */
if(!s->budget--) { s->failed_pc=0x0c070bacu; return 0; }
r[6]+=0x00000038u;
goto P_0c070bae;
P_0c070bae: /* original 7544, guest PC 0x0c070bae */
if(!s->budget--) { s->failed_pc=0x0c070baeu; return 0; }
r[5]+=0x00000044u;
goto P_0c070bb0;
P_0c070bb0: /* original f059, guest PC 0x0c070bb0 */
if(!s->budget--) { s->failed_pc=0x0c070bb0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb2;
P_0c070bb2: /* original f369, guest PC 0x0c070bb2 */
if(!s->budget--) { s->failed_pc=0x0c070bb2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb4;
P_0c070bb4: /* original f159, guest PC 0x0c070bb4 */
if(!s->budget--) { s->failed_pc=0x0c070bb4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb6;
P_0c070bb6: /* original f469, guest PC 0x0c070bb6 */
if(!s->budget--) { s->failed_pc=0x0c070bb6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb8;
P_0c070bb8: /* original f031, guest PC 0x0c070bb8 */
if(!s->budget--) { s->failed_pc=0x0c070bb8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070bba;
P_0c070bba: /* original f258, guest PC 0x0c070bba */
if(!s->budget--) { s->failed_pc=0x0c070bbau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070bbc;
P_0c070bbc: /* original f568, guest PC 0x0c070bbc */
if(!s->budget--) { s->failed_pc=0x0c070bbcu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070bbe;
P_0c070bbe: /* original f141, guest PC 0x0c070bbe */
if(!s->budget--) { s->failed_pc=0x0c070bbeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070bc0;
P_0c070bc0: /* original f251, guest PC 0x0c070bc0 */
if(!s->budget--) { s->failed_pc=0x0c070bc0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070bc2;
P_0c070bc2: /* original 7408, guest PC 0x0c070bc2 */
if(!s->budget--) { s->failed_pc=0x0c070bc2u; return 0; }
r[4]+=0x00000008u;
goto P_0c070bc4;
P_0c070bc4: /* original f42a, guest PC 0x0c070bc4 */
if(!s->budget--) { s->failed_pc=0x0c070bc4u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070bc6;
P_0c070bc6: /* original f41b, guest PC 0x0c070bc6 */
if(!s->budget--) { s->failed_pc=0x0c070bc6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070bc8;
P_0c070bc8: /* original f40b, guest PC 0x0c070bc8 */
if(!s->budget--) { s->failed_pc=0x0c070bc8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070bca;
P_0c070bca: /* original 0009, guest PC 0x0c070bca */
if(!s->budget--) { s->failed_pc=0x0c070bcau; return 0; }
goto P_0c070bcc;
P_0c070bcc: /* original f4fc, guest PC 0x0c070bcc */
if(!s->budget--) { s->failed_pc=0x0c070bccu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070bce;
P_0c070bce: /* original f4c1, guest PC 0x0c070bce */
if(!s->budget--) { s->failed_pc=0x0c070bceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c070bd0;
P_0c070bd0: /* original 64f3, guest PC 0x0c070bd0 */
if(!s->budget--) { s->failed_pc=0x0c070bd0u; return 0; }
r[4]=r[15];
goto P_0c070bd2;
P_0c070bd2: /* original 65f3, guest PC 0x0c070bd2 */
if(!s->budget--) { s->failed_pc=0x0c070bd2u; return 0; }
r[5]=r[15];
goto P_0c070bd4;
P_0c070bd4: /* original 7438, guest PC 0x0c070bd4 */
if(!s->budget--) { s->failed_pc=0x0c070bd4u; return 0; }
r[4]+=0x00000038u;
goto P_0c070bd6;
P_0c070bd6: /* original 7538, guest PC 0x0c070bd6 */
if(!s->budget--) { s->failed_pc=0x0c070bd6u; return 0; }
r[5]+=0x00000038u;
goto P_0c070bd8;
P_0c070bd8: /* original f059, guest PC 0x0c070bd8 */
if(!s->budget--) { s->failed_pc=0x0c070bd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bda;
P_0c070bda: /* original f159, guest PC 0x0c070bda */
if(!s->budget--) { s->failed_pc=0x0c070bdau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bdc;
P_0c070bdc: /* original f259, guest PC 0x0c070bdc */
if(!s->budget--) { s->failed_pc=0x0c070bdcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bde;
P_0c070bde: /* original f38d, guest PC 0x0c070bde */
if(!s->budget--) { s->failed_pc=0x0c070bdeu; return 0; }
fr[3]=0;
goto P_0c070be0;
P_0c070be0: /* original f0ed, guest PC 0x0c070be0 */
if(!s->budget--) { s->failed_pc=0x0c070be0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070be2;
P_0c070be2: /* original f37d, guest PC 0x0c070be2 */
if(!s->budget--) { s->failed_pc=0x0c070be2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070be4;
P_0c070be4: /* original f342, guest PC 0x0c070be4 */
if(!s->budget--) { s->failed_pc=0x0c070be4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070be6;
P_0c070be6: /* original 740c, guest PC 0x0c070be6 */
if(!s->budget--) { s->failed_pc=0x0c070be6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070be8;
P_0c070be8: /* original f232, guest PC 0x0c070be8 */
if(!s->budget--) { s->failed_pc=0x0c070be8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070bea;
P_0c070bea: /* original f132, guest PC 0x0c070bea */
if(!s->budget--) { s->failed_pc=0x0c070beau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070bec;
P_0c070bec: /* original f032, guest PC 0x0c070bec */
if(!s->budget--) { s->failed_pc=0x0c070becu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070bee;
P_0c070bee: /* original f42b, guest PC 0x0c070bee */
if(!s->budget--) { s->failed_pc=0x0c070beeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070bf0;
P_0c070bf0: /* original f41b, guest PC 0x0c070bf0 */
if(!s->budget--) { s->failed_pc=0x0c070bf0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070bf2;
P_0c070bf2: /* original f40b, guest PC 0x0c070bf2 */
if(!s->budget--) { s->failed_pc=0x0c070bf2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070bf4;
P_0c070bf4: /* original 64f3, guest PC 0x0c070bf4 */
if(!s->budget--) { s->failed_pc=0x0c070bf4u; return 0; }
r[4]=r[15];
goto P_0c070bf6;
P_0c070bf6: /* original 65f3, guest PC 0x0c070bf6 */
if(!s->budget--) { s->failed_pc=0x0c070bf6u; return 0; }
r[5]=r[15];
goto P_0c070bf8;
P_0c070bf8: /* original 7444, guest PC 0x0c070bf8 */
if(!s->budget--) { s->failed_pc=0x0c070bf8u; return 0; }
r[4]+=0x00000044u;
goto P_0c070bfa;
P_0c070bfa: /* original 7538, guest PC 0x0c070bfa */
if(!s->budget--) { s->failed_pc=0x0c070bfau; return 0; }
r[5]+=0x00000038u;
goto P_0c070bfc;
P_0c070bfc: /* original f049, guest PC 0x0c070bfc */
if(!s->budget--) { s->failed_pc=0x0c070bfcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070bfe;
P_0c070bfe: /* original f359, guest PC 0x0c070bfe */
if(!s->budget--) { s->failed_pc=0x0c070bfeu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c00;
P_0c070c00: /* original f149, guest PC 0x0c070c00 */
if(!s->budget--) { s->failed_pc=0x0c070c00u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c02;
P_0c070c02: /* original f459, guest PC 0x0c070c02 */
if(!s->budget--) { s->failed_pc=0x0c070c02u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c04;
P_0c070c04: /* original f249, guest PC 0x0c070c04 */
if(!s->budget--) { s->failed_pc=0x0c070c04u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c06;
P_0c070c06: /* original f559, guest PC 0x0c070c06 */
if(!s->budget--) { s->failed_pc=0x0c070c06u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c08;
P_0c070c08: /* original f030, guest PC 0x0c070c08 */
if(!s->budget--) { s->failed_pc=0x0c070c08u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070c0a;
P_0c070c0a: /* original f250, guest PC 0x0c070c0a */
if(!s->budget--) { s->failed_pc=0x0c070c0au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070c0c;
P_0c070c0c: /* original f140, guest PC 0x0c070c0c */
if(!s->budget--) { s->failed_pc=0x0c070c0cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070c0e;
P_0c070c0e: /* original f42b, guest PC 0x0c070c0e */
if(!s->budget--) { s->failed_pc=0x0c070c0eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c10;
P_0c070c10: /* original f41b, guest PC 0x0c070c10 */
if(!s->budget--) { s->failed_pc=0x0c070c10u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c12;
P_0c070c12: /* original f40b, guest PC 0x0c070c12 */
if(!s->budget--) { s->failed_pc=0x0c070c12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c14;
P_0c070c14: /* original 65f3, guest PC 0x0c070c14 */
if(!s->budget--) { s->failed_pc=0x0c070c14u; return 0; }
r[5]=r[15];
goto P_0c070c16;
P_0c070c16: /* original 64e3, guest PC 0x0c070c16 */
if(!s->budget--) { s->failed_pc=0x0c070c16u; return 0; }
r[4]=r[14];
goto P_0c070c18;
P_0c070c18: /* original 7544, guest PC 0x0c070c18 */
if(!s->budget--) { s->failed_pc=0x0c070c18u; return 0; }
r[5]+=0x00000044u;
goto P_0c070c1a;
P_0c070c1a: /* original 6693, guest PC 0x0c070c1a */
if(!s->budget--) { s->failed_pc=0x0c070c1au; return 0; }
r[6]=r[9];
goto P_0c070c1c;
P_0c070c1c: /* original f059, guest PC 0x0c070c1c */
if(!s->budget--) { s->failed_pc=0x0c070c1cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c1e;
P_0c070c1e: /* original f369, guest PC 0x0c070c1e */
if(!s->budget--) { s->failed_pc=0x0c070c1eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c20;
P_0c070c20: /* original f159, guest PC 0x0c070c20 */
if(!s->budget--) { s->failed_pc=0x0c070c20u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c22;
P_0c070c22: /* original f469, guest PC 0x0c070c22 */
if(!s->budget--) { s->failed_pc=0x0c070c22u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c24;
P_0c070c24: /* original f259, guest PC 0x0c070c24 */
if(!s->budget--) { s->failed_pc=0x0c070c24u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c26;
P_0c070c26: /* original f569, guest PC 0x0c070c26 */
if(!s->budget--) { s->failed_pc=0x0c070c26u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c28;
P_0c070c28: /* original 740c, guest PC 0x0c070c28 */
if(!s->budget--) { s->failed_pc=0x0c070c28u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070c2a;
P_0c070c2a: /* original f030, guest PC 0x0c070c2a */
if(!s->budget--) { s->failed_pc=0x0c070c2au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070c2c;
P_0c070c2c: /* original f250, guest PC 0x0c070c2c */
if(!s->budget--) { s->failed_pc=0x0c070c2cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070c2e;
P_0c070c2e: /* original f140, guest PC 0x0c070c2e */
if(!s->budget--) { s->failed_pc=0x0c070c2eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070c30;
P_0c070c30: /* original f42b, guest PC 0x0c070c30 */
if(!s->budget--) { s->failed_pc=0x0c070c30u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c32;
P_0c070c32: /* original f41b, guest PC 0x0c070c32 */
if(!s->budget--) { s->failed_pc=0x0c070c32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c34;
P_0c070c34: /* original f40b, guest PC 0x0c070c34 */
if(!s->budget--) { s->failed_pc=0x0c070c34u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c36;
P_0c070c36: /* original 0009, guest PC 0x0c070c36 */
if(!s->budget--) { s->failed_pc=0x0c070c36u; return 0; }
goto P_0c070c38;
P_0c070c38: /* original 64f3, guest PC 0x0c070c38 */
if(!s->budget--) { s->failed_pc=0x0c070c38u; return 0; }
r[4]=r[15];
goto P_0c070c3a;
P_0c070c3a: /* original 742c, guest PC 0x0c070c3a */
if(!s->budget--) { s->failed_pc=0x0c070c3au; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c3c;
P_0c070c3c: /* original 6683, guest PC 0x0c070c3c */
if(!s->budget--) { s->failed_pc=0x0c070c3cu; return 0; }
r[6]=r[8];
goto P_0c070c3e;
P_0c070c3e: /* original 65e3, guest PC 0x0c070c3e */
if(!s->budget--) { s->failed_pc=0x0c070c3eu; return 0; }
r[5]=r[14];
goto P_0c070c40;
P_0c070c40: /* original f059, guest PC 0x0c070c40 */
if(!s->budget--) { s->failed_pc=0x0c070c40u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c42;
P_0c070c42: /* original f369, guest PC 0x0c070c42 */
if(!s->budget--) { s->failed_pc=0x0c070c42u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c44;
P_0c070c44: /* original f159, guest PC 0x0c070c44 */
if(!s->budget--) { s->failed_pc=0x0c070c44u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c46;
P_0c070c46: /* original f469, guest PC 0x0c070c46 */
if(!s->budget--) { s->failed_pc=0x0c070c46u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c48;
P_0c070c48: /* original f031, guest PC 0x0c070c48 */
if(!s->budget--) { s->failed_pc=0x0c070c48u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070c4a;
P_0c070c4a: /* original f258, guest PC 0x0c070c4a */
if(!s->budget--) { s->failed_pc=0x0c070c4au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070c4c;
P_0c070c4c: /* original f568, guest PC 0x0c070c4c */
if(!s->budget--) { s->failed_pc=0x0c070c4cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070c4e;
P_0c070c4e: /* original f141, guest PC 0x0c070c4e */
if(!s->budget--) { s->failed_pc=0x0c070c4eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070c50;
P_0c070c50: /* original f251, guest PC 0x0c070c50 */
if(!s->budget--) { s->failed_pc=0x0c070c50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070c52;
P_0c070c52: /* original 7408, guest PC 0x0c070c52 */
if(!s->budget--) { s->failed_pc=0x0c070c52u; return 0; }
r[4]+=0x00000008u;
goto P_0c070c54;
P_0c070c54: /* original f42a, guest PC 0x0c070c54 */
if(!s->budget--) { s->failed_pc=0x0c070c54u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c56;
P_0c070c56: /* original f41b, guest PC 0x0c070c56 */
if(!s->budget--) { s->failed_pc=0x0c070c56u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c58;
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
goto P_0c070dd6;
P_0c070dd6: /* original fe45, guest PC 0x0c070dd6 */
if(!s->budget--) { s->failed_pc=0x0c070dd6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c070dd8;
P_0c070dd8: /* original 8902, guest PC 0x0c070dd8 */
if(!s->budget--) { s->failed_pc=0x0c070dd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070de0; }
goto P_0c070dda;
P_0c070dda: /* original d205, guest PC 0x0c070dda */
if(!s->budget--) { s->failed_pc=0x0c070ddau; return 0; }
r[2]=read(ram,0x0c070df0u,4);
goto P_0c070ddc;
P_0c070ddc: /* original 422b, guest PC 0x0c070ddc */
if(!s->budget--) { s->failed_pc=0x0c070ddcu; return 0; }
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
P_0c070dde: /* original 0009, guest PC 0x0c070dde */
if(!s->budget--) { s->failed_pc=0x0c070ddeu; return 0; }
goto P_0c070de0;
P_0c070de0: /* original 64f3, guest PC 0x0c070de0 */
if(!s->budget--) { s->failed_pc=0x0c070de0u; return 0; }
r[4]=r[15];
goto P_0c070de2;
P_0c070de2: /* original 7438, guest PC 0x0c070de2 */
if(!s->budget--) { s->failed_pc=0x0c070de2u; return 0; }
r[4]+=0x00000038u;
goto P_0c070de4;
P_0c070de4: /* original 65b3, guest PC 0x0c070de4 */
if(!s->budget--) { s->failed_pc=0x0c070de4u; return 0; }
r[5]=r[11];
goto P_0c070de6;
P_0c070de6: /* original a005, guest PC 0x0c070de6 */
if(!s->budget--) { s->failed_pc=0x0c070de6u; return 0; }
goto P_0c070df4;
P_0c070de8: /* original 0009, guest PC 0x0c070de8 */
if(!s->budget--) { s->failed_pc=0x0c070de8u; return 0; }
return vf3_matrix_family(0x0c070deau,s,ram);
P_0c070df4: /* original f059, guest PC 0x0c070df4 */
if(!s->budget--) { s->failed_pc=0x0c070df4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070df6;
P_0c070df6: /* original f159, guest PC 0x0c070df6 */
if(!s->budget--) { s->failed_pc=0x0c070df6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070df8;
P_0c070df8: /* original f259, guest PC 0x0c070df8 */
if(!s->budget--) { s->failed_pc=0x0c070df8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070dfa;
P_0c070dfa: /* original 740c, guest PC 0x0c070dfa */
if(!s->budget--) { s->failed_pc=0x0c070dfau; return 0; }
r[4]+=0x0000000cu;
goto P_0c070dfc;
P_0c070dfc: /* original f242, guest PC 0x0c070dfc */
if(!s->budget--) { s->failed_pc=0x0c070dfcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070dfe;
P_0c070dfe: /* original f142, guest PC 0x0c070dfe */
if(!s->budget--) { s->failed_pc=0x0c070dfeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070e00;
P_0c070e00: /* original f042, guest PC 0x0c070e00 */
if(!s->budget--) { s->failed_pc=0x0c070e00u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070e02;
P_0c070e02: /* original f42b, guest PC 0x0c070e02 */
if(!s->budget--) { s->failed_pc=0x0c070e02u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e04;
P_0c070e04: /* original f41b, guest PC 0x0c070e04 */
if(!s->budget--) { s->failed_pc=0x0c070e04u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e06;
P_0c070e06: /* original f40b, guest PC 0x0c070e06 */
if(!s->budget--) { s->failed_pc=0x0c070e06u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e08;
P_0c070e08: /* original 65f3, guest PC 0x0c070e08 */
if(!s->budget--) { s->failed_pc=0x0c070e08u; return 0; }
r[5]=r[15];
goto P_0c070e0a;
P_0c070e0a: /* original 64f3, guest PC 0x0c070e0a */
if(!s->budget--) { s->failed_pc=0x0c070e0au; return 0; }
r[4]=r[15];
goto P_0c070e0c;
P_0c070e0c: /* original 66f3, guest PC 0x0c070e0c */
if(!s->budget--) { s->failed_pc=0x0c070e0cu; return 0; }
r[6]=r[15];
goto P_0c070e0e;
P_0c070e0e: /* original 7438, guest PC 0x0c070e0e */
if(!s->budget--) { s->failed_pc=0x0c070e0eu; return 0; }
r[4]+=0x00000038u;
goto P_0c070e10;
P_0c070e10: /* original 7638, guest PC 0x0c070e10 */
if(!s->budget--) { s->failed_pc=0x0c070e10u; return 0; }
r[6]+=0x00000038u;
goto P_0c070e12;
P_0c070e12: /* original 7544, guest PC 0x0c070e12 */
if(!s->budget--) { s->failed_pc=0x0c070e12u; return 0; }
r[5]+=0x00000044u;
goto P_0c070e14;
P_0c070e14: /* original f059, guest PC 0x0c070e14 */
if(!s->budget--) { s->failed_pc=0x0c070e14u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e16;
P_0c070e16: /* original f369, guest PC 0x0c070e16 */
if(!s->budget--) { s->failed_pc=0x0c070e16u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e18;
P_0c070e18: /* original f159, guest PC 0x0c070e18 */
if(!s->budget--) { s->failed_pc=0x0c070e18u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e1a;
P_0c070e1a: /* original f469, guest PC 0x0c070e1a */
if(!s->budget--) { s->failed_pc=0x0c070e1au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e1c;
P_0c070e1c: /* original f031, guest PC 0x0c070e1c */
if(!s->budget--) { s->failed_pc=0x0c070e1cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070e1e;
P_0c070e1e: /* original f258, guest PC 0x0c070e1e */
if(!s->budget--) { s->failed_pc=0x0c070e1eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070e20;
P_0c070e20: /* original f568, guest PC 0x0c070e20 */
if(!s->budget--) { s->failed_pc=0x0c070e20u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070e22;
P_0c070e22: /* original f141, guest PC 0x0c070e22 */
if(!s->budget--) { s->failed_pc=0x0c070e22u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070e24;
P_0c070e24: /* original f251, guest PC 0x0c070e24 */
if(!s->budget--) { s->failed_pc=0x0c070e24u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070e26;
P_0c070e26: /* original 7408, guest PC 0x0c070e26 */
if(!s->budget--) { s->failed_pc=0x0c070e26u; return 0; }
r[4]+=0x00000008u;
goto P_0c070e28;
P_0c070e28: /* original f42a, guest PC 0x0c070e28 */
if(!s->budget--) { s->failed_pc=0x0c070e28u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e2a;
P_0c070e2a: /* original f41b, guest PC 0x0c070e2a */
if(!s->budget--) { s->failed_pc=0x0c070e2au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e2c;
P_0c070e2c: /* original f40b, guest PC 0x0c070e2c */
if(!s->budget--) { s->failed_pc=0x0c070e2cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e2e;
P_0c070e2e: /* original 0009, guest PC 0x0c070e2e */
if(!s->budget--) { s->failed_pc=0x0c070e2eu; return 0; }
goto P_0c070e30;
P_0c070e30: /* original e01c, guest PC 0x0c070e30 */
if(!s->budget--) { s->failed_pc=0x0c070e30u; return 0; }
r[0]=0x0000001cu;
goto P_0c070e32;
P_0c070e32: /* original f4fc, guest PC 0x0c070e32 */
if(!s->budget--) { s->failed_pc=0x0c070e32u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070e34;
P_0c070e34: /* original f3f6, guest PC 0x0c070e34 */
if(!s->budget--) { s->failed_pc=0x0c070e34u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070e36;
P_0c070e36: /* original 64f3, guest PC 0x0c070e36 */
if(!s->budget--) { s->failed_pc=0x0c070e36u; return 0; }
r[4]=r[15];
goto P_0c070e38;
P_0c070e38: /* original 65f3, guest PC 0x0c070e38 */
if(!s->budget--) { s->failed_pc=0x0c070e38u; return 0; }
r[5]=r[15];
goto P_0c070e3a;
P_0c070e3a: /* original 7438, guest PC 0x0c070e3a */
if(!s->budget--) { s->failed_pc=0x0c070e3au; return 0; }
r[4]+=0x00000038u;
goto P_0c070e3c;
P_0c070e3c: /* original f431, guest PC 0x0c070e3c */
if(!s->budget--) { s->failed_pc=0x0c070e3cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c070e3e;
P_0c070e3e: /* original 7538, guest PC 0x0c070e3e */
if(!s->budget--) { s->failed_pc=0x0c070e3eu; return 0; }
r[5]+=0x00000038u;
goto P_0c070e40;
P_0c070e40: /* original f059, guest PC 0x0c070e40 */
if(!s->budget--) { s->failed_pc=0x0c070e40u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e42;
P_0c070e42: /* original f159, guest PC 0x0c070e42 */
if(!s->budget--) { s->failed_pc=0x0c070e42u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e44;
P_0c070e44: /* original f259, guest PC 0x0c070e44 */
if(!s->budget--) { s->failed_pc=0x0c070e44u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e46;
P_0c070e46: /* original f38d, guest PC 0x0c070e46 */
if(!s->budget--) { s->failed_pc=0x0c070e46u; return 0; }
fr[3]=0;
goto P_0c070e48;
P_0c070e48: /* original f0ed, guest PC 0x0c070e48 */
if(!s->budget--) { s->failed_pc=0x0c070e48u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070e4a;
P_0c070e4a: /* original f37d, guest PC 0x0c070e4a */
if(!s->budget--) { s->failed_pc=0x0c070e4au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070e4c;
P_0c070e4c: /* original f342, guest PC 0x0c070e4c */
if(!s->budget--) { s->failed_pc=0x0c070e4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070e4e;
P_0c070e4e: /* original 740c, guest PC 0x0c070e4e */
if(!s->budget--) { s->failed_pc=0x0c070e4eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070e50;
P_0c070e50: /* original f232, guest PC 0x0c070e50 */
if(!s->budget--) { s->failed_pc=0x0c070e50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070e52;
P_0c070e52: /* original f132, guest PC 0x0c070e52 */
if(!s->budget--) { s->failed_pc=0x0c070e52u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070e54;
P_0c070e54: /* original f032, guest PC 0x0c070e54 */
if(!s->budget--) { s->failed_pc=0x0c070e54u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070e56;
P_0c070e56: /* original f42b, guest PC 0x0c070e56 */
if(!s->budget--) { s->failed_pc=0x0c070e56u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e58;
P_0c070e58: /* original f41b, guest PC 0x0c070e58 */
if(!s->budget--) { s->failed_pc=0x0c070e58u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e5a;
P_0c070e5a: /* original f40b, guest PC 0x0c070e5a */
if(!s->budget--) { s->failed_pc=0x0c070e5au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e5c;
P_0c070e5c: /* original 64f3, guest PC 0x0c070e5c */
if(!s->budget--) { s->failed_pc=0x0c070e5cu; return 0; }
r[4]=r[15];
goto P_0c070e5e;
P_0c070e5e: /* original 65f3, guest PC 0x0c070e5e */
if(!s->budget--) { s->failed_pc=0x0c070e5eu; return 0; }
r[5]=r[15];
goto P_0c070e60;
P_0c070e60: /* original 7444, guest PC 0x0c070e60 */
if(!s->budget--) { s->failed_pc=0x0c070e60u; return 0; }
r[4]+=0x00000044u;
goto P_0c070e62;
P_0c070e62: /* original 7538, guest PC 0x0c070e62 */
if(!s->budget--) { s->failed_pc=0x0c070e62u; return 0; }
r[5]+=0x00000038u;
goto P_0c070e64;
P_0c070e64: /* original f049, guest PC 0x0c070e64 */
if(!s->budget--) { s->failed_pc=0x0c070e64u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e66;
P_0c070e66: /* original f359, guest PC 0x0c070e66 */
if(!s->budget--) { s->failed_pc=0x0c070e66u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e68;
P_0c070e68: /* original f149, guest PC 0x0c070e68 */
if(!s->budget--) { s->failed_pc=0x0c070e68u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6a;
P_0c070e6a: /* original f459, guest PC 0x0c070e6a */
if(!s->budget--) { s->failed_pc=0x0c070e6au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6c;
P_0c070e6c: /* original f249, guest PC 0x0c070e6c */
if(!s->budget--) { s->failed_pc=0x0c070e6cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6e;
P_0c070e6e: /* original f559, guest PC 0x0c070e6e */
if(!s->budget--) { s->failed_pc=0x0c070e6eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e70;
P_0c070e70: /* original f030, guest PC 0x0c070e70 */
if(!s->budget--) { s->failed_pc=0x0c070e70u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070e72;
P_0c070e72: /* original f250, guest PC 0x0c070e72 */
if(!s->budget--) { s->failed_pc=0x0c070e72u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070e74;
P_0c070e74: /* original f140, guest PC 0x0c070e74 */
if(!s->budget--) { s->failed_pc=0x0c070e74u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070e76;
P_0c070e76: /* original f42b, guest PC 0x0c070e76 */
if(!s->budget--) { s->failed_pc=0x0c070e76u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e78;
P_0c070e78: /* original f41b, guest PC 0x0c070e78 */
if(!s->budget--) { s->failed_pc=0x0c070e78u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e7a;
P_0c070e7a: /* original f40b, guest PC 0x0c070e7a */
if(!s->budget--) { s->failed_pc=0x0c070e7au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e7c;
P_0c070e7c: /* original 65f3, guest PC 0x0c070e7c */
if(!s->budget--) { s->failed_pc=0x0c070e7cu; return 0; }
r[5]=r[15];
goto P_0c070e7e;
P_0c070e7e: /* original 64d3, guest PC 0x0c070e7e */
if(!s->budget--) { s->failed_pc=0x0c070e7eu; return 0; }
r[4]=r[13];
goto P_0c070e80;
P_0c070e80: /* original 7544, guest PC 0x0c070e80 */
if(!s->budget--) { s->failed_pc=0x0c070e80u; return 0; }
r[5]+=0x00000044u;
goto P_0c070e82;
P_0c070e82: /* original 66a3, guest PC 0x0c070e82 */
if(!s->budget--) { s->failed_pc=0x0c070e82u; return 0; }
r[6]=r[10];
goto P_0c070e84;
P_0c070e84: /* original f059, guest PC 0x0c070e84 */
if(!s->budget--) { s->failed_pc=0x0c070e84u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e86;
P_0c070e86: /* original f369, guest PC 0x0c070e86 */
if(!s->budget--) { s->failed_pc=0x0c070e86u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e88;
P_0c070e88: /* original f159, guest PC 0x0c070e88 */
if(!s->budget--) { s->failed_pc=0x0c070e88u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8a;
P_0c070e8a: /* original f469, guest PC 0x0c070e8a */
if(!s->budget--) { s->failed_pc=0x0c070e8au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8c;
P_0c070e8c: /* original f259, guest PC 0x0c070e8c */
if(!s->budget--) { s->failed_pc=0x0c070e8cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8e;
P_0c070e8e: /* original f569, guest PC 0x0c070e8e */
if(!s->budget--) { s->failed_pc=0x0c070e8eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e90;
P_0c070e90: /* original 740c, guest PC 0x0c070e90 */
if(!s->budget--) { s->failed_pc=0x0c070e90u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070e92;
P_0c070e92: /* original f030, guest PC 0x0c070e92 */
if(!s->budget--) { s->failed_pc=0x0c070e92u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070e94;
P_0c070e94: /* original f250, guest PC 0x0c070e94 */
if(!s->budget--) { s->failed_pc=0x0c070e94u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070e96;
P_0c070e96: /* original f140, guest PC 0x0c070e96 */
if(!s->budget--) { s->failed_pc=0x0c070e96u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070e98;
P_0c070e98: /* original f42b, guest PC 0x0c070e98 */
if(!s->budget--) { s->failed_pc=0x0c070e98u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e9a;
P_0c070e9a: /* original f41b, guest PC 0x0c070e9a */
if(!s->budget--) { s->failed_pc=0x0c070e9au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e9c;
P_0c070e9c: /* original f40b, guest PC 0x0c070e9c */
if(!s->budget--) { s->failed_pc=0x0c070e9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e9e;
P_0c070e9e: /* original 0009, guest PC 0x0c070e9e */
if(!s->budget--) { s->failed_pc=0x0c070e9eu; return 0; }
goto P_0c070ea0;
P_0c070ea0: /* original 64f3, guest PC 0x0c070ea0 */
if(!s->budget--) { s->failed_pc=0x0c070ea0u; return 0; }
r[4]=r[15];
goto P_0c070ea2;
P_0c070ea2: /* original 7444, guest PC 0x0c070ea2 */
if(!s->budget--) { s->failed_pc=0x0c070ea2u; return 0; }
r[4]+=0x00000044u;
goto P_0c070ea4;
P_0c070ea4: /* original 6693, guest PC 0x0c070ea4 */
if(!s->budget--) { s->failed_pc=0x0c070ea4u; return 0; }
r[6]=r[9];
goto P_0c070ea6;
P_0c070ea6: /* original 65d3, guest PC 0x0c070ea6 */
if(!s->budget--) { s->failed_pc=0x0c070ea6u; return 0; }
r[5]=r[13];
goto P_0c070ea8;
P_0c070ea8: /* original f059, guest PC 0x0c070ea8 */
if(!s->budget--) { s->failed_pc=0x0c070ea8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070eaa;
P_0c070eaa: /* original f369, guest PC 0x0c070eaa */
if(!s->budget--) { s->failed_pc=0x0c070eaau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070eac;
P_0c070eac: /* original f159, guest PC 0x0c070eac */
if(!s->budget--) { s->failed_pc=0x0c070eacu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070eae;
P_0c070eae: /* original f469, guest PC 0x0c070eae */
if(!s->budget--) { s->failed_pc=0x0c070eaeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070eb0;
P_0c070eb0: /* original f031, guest PC 0x0c070eb0 */
if(!s->budget--) { s->failed_pc=0x0c070eb0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070eb2;
P_0c070eb2: /* original f258, guest PC 0x0c070eb2 */
if(!s->budget--) { s->failed_pc=0x0c070eb2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070eb4;
P_0c070eb4: /* original f568, guest PC 0x0c070eb4 */
if(!s->budget--) { s->failed_pc=0x0c070eb4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070eb6;
P_0c070eb6: /* original f141, guest PC 0x0c070eb6 */
if(!s->budget--) { s->failed_pc=0x0c070eb6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070eb8;
P_0c070eb8: /* original f251, guest PC 0x0c070eb8 */
if(!s->budget--) { s->failed_pc=0x0c070eb8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070eba;
P_0c070eba: /* original 7408, guest PC 0x0c070eba */
if(!s->budget--) { s->failed_pc=0x0c070ebau; return 0; }
r[4]+=0x00000008u;
goto P_0c070ebc;
P_0c070ebc: /* original f42a, guest PC 0x0c070ebc */
if(!s->budget--) { s->failed_pc=0x0c070ebcu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ebe;
P_0c070ebe: /* original f41b, guest PC 0x0c070ebe */
if(!s->budget--) { s->failed_pc=0x0c070ebeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ec0;
P_0c070ec0: /* original f40b, guest PC 0x0c070ec0 */
if(!s->budget--) { s->failed_pc=0x0c070ec0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ec2;
P_0c070ec2: /* original 0009, guest PC 0x0c070ec2 */
if(!s->budget--) { s->failed_pc=0x0c070ec2u; return 0; }
goto P_0c070ec4;
P_0c070ec4: /* original 64f3, guest PC 0x0c070ec4 */
if(!s->budget--) { s->failed_pc=0x0c070ec4u; return 0; }
r[4]=r[15];
goto P_0c070ec6;
P_0c070ec6: /* original 7444, guest PC 0x0c070ec6 */
if(!s->budget--) { s->failed_pc=0x0c070ec6u; return 0; }
r[4]+=0x00000044u;
goto P_0c070ec8;
P_0c070ec8: /* original f049, guest PC 0x0c070ec8 */
if(!s->budget--) { s->failed_pc=0x0c070ec8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070eca;
P_0c070eca: /* original f149, guest PC 0x0c070eca */
if(!s->budget--) { s->failed_pc=0x0c070ecau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ecc;
P_0c070ecc: /* original f249, guest PC 0x0c070ecc */
if(!s->budget--) { s->failed_pc=0x0c070eccu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ece;
P_0c070ece: /* original f38d, guest PC 0x0c070ece */
if(!s->budget--) { s->failed_pc=0x0c070eceu; return 0; }
fr[3]=0;
goto P_0c070ed0;
P_0c070ed0: /* original f0ed, guest PC 0x0c070ed0 */
if(!s->budget--) { s->failed_pc=0x0c070ed0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070ed2;
P_0c070ed2: /* original f03c, guest PC 0x0c070ed2 */
if(!s->budget--) { s->failed_pc=0x0c070ed2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070ed4;
P_0c070ed4: /* original f06d, guest PC 0x0c070ed4 */
if(!s->budget--) { s->failed_pc=0x0c070ed4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070ed6;
P_0c070ed6: /* original 0009, guest PC 0x0c070ed6 */
if(!s->budget--) { s->failed_pc=0x0c070ed6u; return 0; }
goto P_0c070ed8;
P_0c070ed8: /* original f38d, guest PC 0x0c070ed8 */
if(!s->budget--) { s->failed_pc=0x0c070ed8u; return 0; }
fr[3]=0;
goto P_0c070eda;
P_0c070eda: /* original fc0c, guest PC 0x0c070eda */
if(!s->budget--) { s->failed_pc=0x0c070edau; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070edc;
P_0c070edc: /* original fc35, guest PC 0x0c070edc */
if(!s->budget--) { s->failed_pc=0x0c070edcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070ede;
P_0c070ede: /* original 8902, guest PC 0x0c070ede */
if(!s->budget--) { s->failed_pc=0x0c070edeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070ee6; }
goto P_0c070ee0;
P_0c070ee0: /* original d303, guest PC 0x0c070ee0 */
if(!s->budget--) { s->failed_pc=0x0c070ee0u; return 0; }
r[3]=read(ram,0x0c070ef0u,4);
goto P_0c070ee2;
P_0c070ee2: /* original 432b, guest PC 0x0c070ee2 */
if(!s->budget--) { s->failed_pc=0x0c070ee2u; return 0; }
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
P_0c070ee4: /* original 0009, guest PC 0x0c070ee4 */
if(!s->budget--) { s->failed_pc=0x0c070ee4u; return 0; }
goto P_0c070ee6;
P_0c070ee6: /* original 64f3, guest PC 0x0c070ee6 */
if(!s->budget--) { s->failed_pc=0x0c070ee6u; return 0; }
r[4]=r[15];
goto P_0c070ee8;
P_0c070ee8: /* original 7444, guest PC 0x0c070ee8 */
if(!s->budget--) { s->failed_pc=0x0c070ee8u; return 0; }
r[4]+=0x00000044u;
goto P_0c070eea;
P_0c070eea: /* original 65c3, guest PC 0x0c070eea */
if(!s->budget--) { s->failed_pc=0x0c070eeau; return 0; }
r[5]=r[12];
goto P_0c070eec;
P_0c070eec: /* original a002, guest PC 0x0c070eec */
if(!s->budget--) { s->failed_pc=0x0c070eecu; return 0; }
goto P_0c070ef4;
P_0c070eee: /* original 0009, guest PC 0x0c070eee */
if(!s->budget--) { s->failed_pc=0x0c070eeeu; return 0; }
return vf3_matrix_family(0x0c070ef0u,s,ram);
P_0c070ef4: /* original f049, guest PC 0x0c070ef4 */
if(!s->budget--) { s->failed_pc=0x0c070ef4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ef6;
P_0c070ef6: /* original f549, guest PC 0x0c070ef6 */
if(!s->budget--) { s->failed_pc=0x0c070ef6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ef8;
P_0c070ef8: /* original f648, guest PC 0x0c070ef8 */
if(!s->budget--) { s->failed_pc=0x0c070ef8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070efa;
P_0c070efa: /* original f859, guest PC 0x0c070efa */
if(!s->budget--) { s->failed_pc=0x0c070efau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070efc;
P_0c070efc: /* original f959, guest PC 0x0c070efc */
if(!s->budget--) { s->failed_pc=0x0c070efcu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070efe;
P_0c070efe: /* original fa58, guest PC 0x0c070efe */
if(!s->budget--) { s->failed_pc=0x0c070efeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070f00;
P_0c070f00: /* original f35c, guest PC 0x0c070f00 */
if(!s->budget--) { s->failed_pc=0x0c070f00u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070f02;
P_0c070f02: /* original f382, guest PC 0x0c070f02 */
if(!s->budget--) { s->failed_pc=0x0c070f02u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070f04;
P_0c070f04: /* original f20c, guest PC 0x0c070f04 */
if(!s->budget--) { s->failed_pc=0x0c070f04u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070f06;
P_0c070f06: /* original f2a2, guest PC 0x0c070f06 */
if(!s->budget--) { s->failed_pc=0x0c070f06u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070f08;
P_0c070f08: /* original f16c, guest PC 0x0c070f08 */
if(!s->budget--) { s->failed_pc=0x0c070f08u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070f0a;
P_0c070f0a: /* original f192, guest PC 0x0c070f0a */
if(!s->budget--) { s->failed_pc=0x0c070f0au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070f0c;
P_0c070f0c: /* original f34d, guest PC 0x0c070f0c */
if(!s->budget--) { s->failed_pc=0x0c070f0cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c070f0e;
P_0c070f0e: /* original f39e, guest PC 0x0c070f0e */
if(!s->budget--) { s->failed_pc=0x0c070f0eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070f10;
P_0c070f10: /* original f24d, guest PC 0x0c070f10 */
if(!s->budget--) { s->failed_pc=0x0c070f10u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070f12;
P_0c070f12: /* original f06c, guest PC 0x0c070f12 */
if(!s->budget--) { s->failed_pc=0x0c070f12u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070f14;
P_0c070f14: /* original f28e, guest PC 0x0c070f14 */
if(!s->budget--) { s->failed_pc=0x0c070f14u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070f16;
P_0c070f16: /* original f14d, guest PC 0x0c070f16 */
if(!s->budget--) { s->failed_pc=0x0c070f16u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070f18;
P_0c070f18: /* original f05c, guest PC 0x0c070f18 */
if(!s->budget--) { s->failed_pc=0x0c070f18u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070f1a;
P_0c070f1a: /* original f1ae, guest PC 0x0c070f1a */
if(!s->budget--) { s->failed_pc=0x0c070f1au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070f1c;
P_0c070f1c: /* original f08d, guest PC 0x0c070f1c */
if(!s->budget--) { s->failed_pc=0x0c070f1cu; return 0; }
fr[0]=0;
goto P_0c070f1e;
P_0c070f1e: /* original f0ed, guest PC 0x0c070f1e */
if(!s->budget--) { s->failed_pc=0x0c070f1eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070f20;
P_0c070f20: /* original f03c, guest PC 0x0c070f20 */
if(!s->budget--) { s->failed_pc=0x0c070f20u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070f22;
P_0c070f22: /* original f06d, guest PC 0x0c070f22 */
if(!s->budget--) { s->failed_pc=0x0c070f22u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070f24;
P_0c070f24: /* original ff05, guest PC 0x0c070f24 */
if(!s->budget--) { s->failed_pc=0x0c070f24u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070f26;
P_0c070f26: /* original e024, guest PC 0x0c070f26 */
if(!s->budget--) { s->failed_pc=0x0c070f26u; return 0; }
r[0]=0x00000024u;
goto P_0c070f28;
P_0c070f28: /* original 8d03, guest PC 0x0c070f28 */
if(!s->budget--) { s->failed_pc=0x0c070f28u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070f32; }
goto P_0c070f2c;
P_0c070f2a: /* original ff07, guest PC 0x0c070f2a */
if(!s->budget--) { s->failed_pc=0x0c070f2au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070f2c;
P_0c070f2c: /* original d303, guest PC 0x0c070f2c */
if(!s->budget--) { s->failed_pc=0x0c070f2cu; return 0; }
r[3]=read(ram,0x0c070f3cu,4);
goto P_0c070f2e;
P_0c070f2e: /* original 432b, guest PC 0x0c070f2e */
if(!s->budget--) { s->failed_pc=0x0c070f2eu; return 0; }
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
P_0c070f30: /* original 0009, guest PC 0x0c070f30 */
if(!s->budget--) { s->failed_pc=0x0c070f30u; return 0; }
goto P_0c070f32;
P_0c070f32: /* original 64f3, guest PC 0x0c070f32 */
if(!s->budget--) { s->failed_pc=0x0c070f32u; return 0; }
r[4]=r[15];
goto P_0c070f34;
P_0c070f34: /* original 7444, guest PC 0x0c070f34 */
if(!s->budget--) { s->failed_pc=0x0c070f34u; return 0; }
r[4]+=0x00000044u;
goto P_0c070f36;
P_0c070f36: /* original 65c3, guest PC 0x0c070f36 */
if(!s->budget--) { s->failed_pc=0x0c070f36u; return 0; }
r[5]=r[12];
goto P_0c070f38;
P_0c070f38: /* original a002, guest PC 0x0c070f38 */
if(!s->budget--) { s->failed_pc=0x0c070f38u; return 0; }
goto P_0c070f40;
P_0c070f3a: /* original 0009, guest PC 0x0c070f3a */
if(!s->budget--) { s->failed_pc=0x0c070f3au; return 0; }
return vf3_matrix_family(0x0c070f3cu,s,ram);
P_0c070f40: /* original f049, guest PC 0x0c070f40 */
if(!s->budget--) { s->failed_pc=0x0c070f40u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f42;
P_0c070f42: /* original f149, guest PC 0x0c070f42 */
if(!s->budget--) { s->failed_pc=0x0c070f42u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f44;
P_0c070f44: /* original f249, guest PC 0x0c070f44 */
if(!s->budget--) { s->failed_pc=0x0c070f44u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f46;
P_0c070f46: /* original f38d, guest PC 0x0c070f46 */
if(!s->budget--) { s->failed_pc=0x0c070f46u; return 0; }
fr[3]=0;
goto P_0c070f48;
P_0c070f48: /* original f459, guest PC 0x0c070f48 */
if(!s->budget--) { s->failed_pc=0x0c070f48u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4a;
P_0c070f4a: /* original f559, guest PC 0x0c070f4a */
if(!s->budget--) { s->failed_pc=0x0c070f4au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4c;
P_0c070f4c: /* original f659, guest PC 0x0c070f4c */
if(!s->budget--) { s->failed_pc=0x0c070f4cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4e;
P_0c070f4e: /* original f78d, guest PC 0x0c070f4e */
if(!s->budget--) { s->failed_pc=0x0c070f4eu; return 0; }
fr[7]=0;
goto P_0c070f50;
P_0c070f50: /* original f4ed, guest PC 0x0c070f50 */
if(!s->budget--) { s->failed_pc=0x0c070f50u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070f52;
P_0c070f52: /* original f07c, guest PC 0x0c070f52 */
if(!s->budget--) { s->failed_pc=0x0c070f52u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070f54;
P_0c070f54: /* original f38d, guest PC 0x0c070f54 */
if(!s->budget--) { s->failed_pc=0x0c070f54u; return 0; }
fr[3]=0;
goto P_0c070f56;
P_0c070f56: /* original f40c, guest PC 0x0c070f56 */
if(!s->budget--) { s->failed_pc=0x0c070f56u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070f58;
P_0c070f58: /* original f345, guest PC 0x0c070f58 */
if(!s->budget--) { s->failed_pc=0x0c070f58u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070f5a;
P_0c070f5a: /* original 8902, guest PC 0x0c070f5a */
if(!s->budget--) { s->failed_pc=0x0c070f5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070f62; }
goto P_0c070f5c;
P_0c070f5c: /* original d307, guest PC 0x0c070f5c */
if(!s->budget--) { s->failed_pc=0x0c070f5cu; return 0; }
r[3]=read(ram,0x0c070f7cu,4);
goto P_0c070f5e;
P_0c070f5e: /* original 432b, guest PC 0x0c070f5e */
if(!s->budget--) { s->failed_pc=0x0c070f5eu; return 0; }
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
P_0c070f60: /* original 0009, guest PC 0x0c070f60 */
if(!s->budget--) { s->failed_pc=0x0c070f60u; return 0; }
goto P_0c070f62;
P_0c070f62: /* original ffc5, guest PC 0x0c070f62 */
if(!s->budget--) { s->failed_pc=0x0c070f62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070f64;
P_0c070f64: /* original 8902, guest PC 0x0c070f64 */
if(!s->budget--) { s->failed_pc=0x0c070f64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070f6c; }
goto P_0c070f66;
P_0c070f66: /* original d206, guest PC 0x0c070f66 */
if(!s->budget--) { s->failed_pc=0x0c070f66u; return 0; }
r[2]=read(ram,0x0c070f80u,4);
goto P_0c070f68;
P_0c070f68: /* original 422b, guest PC 0x0c070f68 */
if(!s->budget--) { s->failed_pc=0x0c070f68u; return 0; }
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
P_0c070f6a: /* original 0009, guest PC 0x0c070f6a */
if(!s->budget--) { s->failed_pc=0x0c070f6au; return 0; }
goto P_0c070f6c;
P_0c070f6c: /* original 64f3, guest PC 0x0c070f6c */
if(!s->budget--) { s->failed_pc=0x0c070f6cu; return 0; }
r[4]=r[15];
goto P_0c070f6e;
P_0c070f6e: /* original 65f3, guest PC 0x0c070f6e */
if(!s->budget--) { s->failed_pc=0x0c070f6eu; return 0; }
r[5]=r[15];
goto P_0c070f70;
P_0c070f70: /* original 7444, guest PC 0x0c070f70 */
if(!s->budget--) { s->failed_pc=0x0c070f70u; return 0; }
r[4]+=0x00000044u;
goto P_0c070f72;
P_0c070f72: /* original f4fc, guest PC 0x0c070f72 */
if(!s->budget--) { s->failed_pc=0x0c070f72u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070f74;
P_0c070f74: /* original 7544, guest PC 0x0c070f74 */
if(!s->budget--) { s->failed_pc=0x0c070f74u; return 0; }
r[5]+=0x00000044u;
goto P_0c070f76;
P_0c070f76: /* original a005, guest PC 0x0c070f76 */
if(!s->budget--) { s->failed_pc=0x0c070f76u; return 0; }
goto P_0c070f84;
P_0c070f78: /* original 0009, guest PC 0x0c070f78 */
if(!s->budget--) { s->failed_pc=0x0c070f78u; return 0; }
return vf3_matrix_family(0x0c070f7au,s,ram);
P_0c070f84: /* original f059, guest PC 0x0c070f84 */
if(!s->budget--) { s->failed_pc=0x0c070f84u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f86;
P_0c070f86: /* original f159, guest PC 0x0c070f86 */
if(!s->budget--) { s->failed_pc=0x0c070f86u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f88;
P_0c070f88: /* original f259, guest PC 0x0c070f88 */
if(!s->budget--) { s->failed_pc=0x0c070f88u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f8a;
P_0c070f8a: /* original f38d, guest PC 0x0c070f8a */
if(!s->budget--) { s->failed_pc=0x0c070f8au; return 0; }
fr[3]=0;
goto P_0c070f8c;
P_0c070f8c: /* original f0ed, guest PC 0x0c070f8c */
if(!s->budget--) { s->failed_pc=0x0c070f8cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070f8e;
P_0c070f8e: /* original f37d, guest PC 0x0c070f8e */
if(!s->budget--) { s->failed_pc=0x0c070f8eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070f90;
P_0c070f90: /* original f342, guest PC 0x0c070f90 */
if(!s->budget--) { s->failed_pc=0x0c070f90u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070f92;
P_0c070f92: /* original 740c, guest PC 0x0c070f92 */
if(!s->budget--) { s->failed_pc=0x0c070f92u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070f94;
P_0c070f94: /* original f232, guest PC 0x0c070f94 */
if(!s->budget--) { s->failed_pc=0x0c070f94u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070f96;
P_0c070f96: /* original f132, guest PC 0x0c070f96 */
if(!s->budget--) { s->failed_pc=0x0c070f96u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070f98;
P_0c070f98: /* original f032, guest PC 0x0c070f98 */
if(!s->budget--) { s->failed_pc=0x0c070f98u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070f9a;
P_0c070f9a: /* original f42b, guest PC 0x0c070f9a */
if(!s->budget--) { s->failed_pc=0x0c070f9au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070f9c;
P_0c070f9c: /* original f41b, guest PC 0x0c070f9c */
if(!s->budget--) { s->failed_pc=0x0c070f9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070f9e;
P_0c070f9e: /* original f40b, guest PC 0x0c070f9e */
if(!s->budget--) { s->failed_pc=0x0c070f9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070fa0;
P_0c070fa0: /* original d206, guest PC 0x0c070fa0 */
if(!s->budget--) { s->failed_pc=0x0c070fa0u; return 0; }
r[2]=read(ram,0x0c070fbcu,4);
goto P_0c070fa2;
P_0c070fa2: /* original 422b, guest PC 0x0c070fa2 */
if(!s->budget--) { s->failed_pc=0x0c070fa2u; return 0; }
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
P_0c070fa4: /* original 0009, guest PC 0x0c070fa4 */
if(!s->budget--) { s->failed_pc=0x0c070fa4u; return 0; }
return vf3_matrix_family(0x0c070fa6u,s,ram);
P_0c071070: /* original 64f3, guest PC 0x0c071070 */
if(!s->budget--) { s->failed_pc=0x0c071070u; return 0; }
r[4]=r[15];
goto P_0c071072;
P_0c071072: /* original 56f1, guest PC 0x0c071072 */
if(!s->budget--) { s->failed_pc=0x0c071072u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c071074;
P_0c071074: /* original 742c, guest PC 0x0c071074 */
if(!s->budget--) { s->failed_pc=0x0c071074u; return 0; }
r[4]+=0x0000002cu;
goto P_0c071076;
P_0c071076: /* original 65d3, guest PC 0x0c071076 */
if(!s->budget--) { s->failed_pc=0x0c071076u; return 0; }
r[5]=r[13];
goto P_0c071078;
P_0c071078: /* original f059, guest PC 0x0c071078 */
if(!s->budget--) { s->failed_pc=0x0c071078u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07107a;
P_0c07107a: /* original f369, guest PC 0x0c07107a */
if(!s->budget--) { s->failed_pc=0x0c07107au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07107c;
P_0c07107c: /* original f159, guest PC 0x0c07107c */
if(!s->budget--) { s->failed_pc=0x0c07107cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07107e;
P_0c07107e: /* original f469, guest PC 0x0c07107e */
if(!s->budget--) { s->failed_pc=0x0c07107eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071080;
P_0c071080: /* original f031, guest PC 0x0c071080 */
if(!s->budget--) { s->failed_pc=0x0c071080u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071082;
P_0c071082: /* original f258, guest PC 0x0c071082 */
if(!s->budget--) { s->failed_pc=0x0c071082u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071084;
P_0c071084: /* original f568, guest PC 0x0c071084 */
if(!s->budget--) { s->failed_pc=0x0c071084u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071086;
P_0c071086: /* original f141, guest PC 0x0c071086 */
if(!s->budget--) { s->failed_pc=0x0c071086u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071088;
P_0c071088: /* original f251, guest PC 0x0c071088 */
if(!s->budget--) { s->failed_pc=0x0c071088u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07108a;
P_0c07108a: /* original 7408, guest PC 0x0c07108a */
if(!s->budget--) { s->failed_pc=0x0c07108au; return 0; }
r[4]+=0x00000008u;
goto P_0c07108c;
P_0c07108c: /* original f42a, guest PC 0x0c07108c */
if(!s->budget--) { s->failed_pc=0x0c07108cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07108e;
P_0c07108e: /* original f41b, guest PC 0x0c07108e */
if(!s->budget--) { s->failed_pc=0x0c07108eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071090;
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
P_0c071400: /* original 64f3, guest PC 0x0c071400 */
if(!s->budget--) { s->failed_pc=0x0c071400u; return 0; }
r[4]=r[15];
goto P_0c071402;
P_0c071402: /* original 741c, guest PC 0x0c071402 */
if(!s->budget--) { s->failed_pc=0x0c071402u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071404;
P_0c071404: /* original 66b3, guest PC 0x0c071404 */
if(!s->budget--) { s->failed_pc=0x0c071404u; return 0; }
r[6]=r[11];
goto P_0c071406;
P_0c071406: /* original 65e3, guest PC 0x0c071406 */
if(!s->budget--) { s->failed_pc=0x0c071406u; return 0; }
r[5]=r[14];
goto P_0c071408;
P_0c071408: /* original a002, guest PC 0x0c071408 */
if(!s->budget--) { s->failed_pc=0x0c071408u; return 0; }
goto P_0c071410;
P_0c07140a: /* original 0009, guest PC 0x0c07140a */
if(!s->budget--) { s->failed_pc=0x0c07140au; return 0; }
return vf3_matrix_family(0x0c07140cu,s,ram);
P_0c071410: /* original f059, guest PC 0x0c071410 */
if(!s->budget--) { s->failed_pc=0x0c071410u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071412;
P_0c071412: /* original f369, guest PC 0x0c071412 */
if(!s->budget--) { s->failed_pc=0x0c071412u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071414;
P_0c071414: /* original f159, guest PC 0x0c071414 */
if(!s->budget--) { s->failed_pc=0x0c071414u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071416;
P_0c071416: /* original f469, guest PC 0x0c071416 */
if(!s->budget--) { s->failed_pc=0x0c071416u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071418;
P_0c071418: /* original f031, guest PC 0x0c071418 */
if(!s->budget--) { s->failed_pc=0x0c071418u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07141a;
P_0c07141a: /* original f258, guest PC 0x0c07141a */
if(!s->budget--) { s->failed_pc=0x0c07141au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c07141c;
P_0c07141c: /* original f568, guest PC 0x0c07141c */
if(!s->budget--) { s->failed_pc=0x0c07141cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c07141e;
P_0c07141e: /* original f141, guest PC 0x0c07141e */
if(!s->budget--) { s->failed_pc=0x0c07141eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071420;
P_0c071420: /* original f251, guest PC 0x0c071420 */
if(!s->budget--) { s->failed_pc=0x0c071420u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071422;
P_0c071422: /* original 7408, guest PC 0x0c071422 */
if(!s->budget--) { s->failed_pc=0x0c071422u; return 0; }
r[4]+=0x00000008u;
goto P_0c071424;
P_0c071424: /* original f42a, guest PC 0x0c071424 */
if(!s->budget--) { s->failed_pc=0x0c071424u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071426;
P_0c071426: /* original f41b, guest PC 0x0c071426 */
if(!s->budget--) { s->failed_pc=0x0c071426u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071428;
P_0c071428: /* original f40b, guest PC 0x0c071428 */
if(!s->budget--) { s->failed_pc=0x0c071428u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07142a;
P_0c07142a: /* original 0009, guest PC 0x0c07142a */
if(!s->budget--) { s->failed_pc=0x0c07142au; return 0; }
goto P_0c07142c;
P_0c07142c: /* original 64f3, guest PC 0x0c07142c */
if(!s->budget--) { s->failed_pc=0x0c07142cu; return 0; }
r[4]=r[15];
goto P_0c07142e;
P_0c07142e: /* original 741c, guest PC 0x0c07142e */
if(!s->budget--) { s->failed_pc=0x0c07142eu; return 0; }
r[4]+=0x0000001cu;
goto P_0c071430;
P_0c071430: /* original f049, guest PC 0x0c071430 */
if(!s->budget--) { s->failed_pc=0x0c071430u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071432;
P_0c071432: /* original f149, guest PC 0x0c071432 */
if(!s->budget--) { s->failed_pc=0x0c071432u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071434;
P_0c071434: /* original f249, guest PC 0x0c071434 */
if(!s->budget--) { s->failed_pc=0x0c071434u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071436;
P_0c071436: /* original f38d, guest PC 0x0c071436 */
if(!s->budget--) { s->failed_pc=0x0c071436u; return 0; }
fr[3]=0;
goto P_0c071438;
P_0c071438: /* original f0ed, guest PC 0x0c071438 */
if(!s->budget--) { s->failed_pc=0x0c071438u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07143a;
P_0c07143a: /* original f03c, guest PC 0x0c07143a */
if(!s->budget--) { s->failed_pc=0x0c07143au; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c07143c;
P_0c07143c: /* original f06d, guest PC 0x0c07143c */
if(!s->budget--) { s->failed_pc=0x0c07143cu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07143e;
P_0c07143e: /* original 0009, guest PC 0x0c07143e */
if(!s->budget--) { s->failed_pc=0x0c07143eu; return 0; }
goto P_0c071440;
P_0c071440: /* original f38d, guest PC 0x0c071440 */
if(!s->budget--) { s->failed_pc=0x0c071440u; return 0; }
fr[3]=0;
goto P_0c071442;
P_0c071442: /* original fd0c, guest PC 0x0c071442 */
if(!s->budget--) { s->failed_pc=0x0c071442u; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c071444;
P_0c071444: /* original fd35, guest PC 0x0c071444 */
if(!s->budget--) { s->failed_pc=0x0c071444u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[3]))!=0);
goto P_0c071446;
P_0c071446: /* original 8902, guest PC 0x0c071446 */
if(!s->budget--) { s->failed_pc=0x0c071446u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07144e; }
goto P_0c071448;
P_0c071448: /* original d303, guest PC 0x0c071448 */
if(!s->budget--) { s->failed_pc=0x0c071448u; return 0; }
r[3]=read(ram,0x0c071458u,4);
goto P_0c07144a;
P_0c07144a: /* original 432b, guest PC 0x0c07144a */
if(!s->budget--) { s->failed_pc=0x0c07144au; return 0; }
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
P_0c07144c: /* original 0009, guest PC 0x0c07144c */
if(!s->budget--) { s->failed_pc=0x0c07144cu; return 0; }
goto P_0c07144e;
P_0c07144e: /* original 64f3, guest PC 0x0c07144e */
if(!s->budget--) { s->failed_pc=0x0c07144eu; return 0; }
r[4]=r[15];
goto P_0c071450;
P_0c071450: /* original 741c, guest PC 0x0c071450 */
if(!s->budget--) { s->failed_pc=0x0c071450u; return 0; }
r[4]+=0x0000001cu;
goto P_0c071452;
P_0c071452: /* original 65d3, guest PC 0x0c071452 */
if(!s->budget--) { s->failed_pc=0x0c071452u; return 0; }
r[5]=r[13];
goto P_0c071454;
P_0c071454: /* original a002, guest PC 0x0c071454 */
if(!s->budget--) { s->failed_pc=0x0c071454u; return 0; }
goto P_0c07145c;
P_0c071456: /* original 0009, guest PC 0x0c071456 */
if(!s->budget--) { s->failed_pc=0x0c071456u; return 0; }
return vf3_matrix_family(0x0c071458u,s,ram);
P_0c07145c: /* original f049, guest PC 0x0c07145c */
if(!s->budget--) { s->failed_pc=0x0c07145cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07145e;
P_0c07145e: /* original f549, guest PC 0x0c07145e */
if(!s->budget--) { s->failed_pc=0x0c07145eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071460;
P_0c071460: /* original f648, guest PC 0x0c071460 */
if(!s->budget--) { s->failed_pc=0x0c071460u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071462;
P_0c071462: /* original f859, guest PC 0x0c071462 */
if(!s->budget--) { s->failed_pc=0x0c071462u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071464;
P_0c071464: /* original f959, guest PC 0x0c071464 */
if(!s->budget--) { s->failed_pc=0x0c071464u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071466;
P_0c071466: /* original fa58, guest PC 0x0c071466 */
if(!s->budget--) { s->failed_pc=0x0c071466u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071468;
P_0c071468: /* original f35c, guest PC 0x0c071468 */
if(!s->budget--) { s->failed_pc=0x0c071468u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c07146a;
P_0c07146a: /* original f382, guest PC 0x0c07146a */
if(!s->budget--) { s->failed_pc=0x0c07146au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07146c;
P_0c07146c: /* original f20c, guest PC 0x0c07146c */
if(!s->budget--) { s->failed_pc=0x0c07146cu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07146e;
P_0c07146e: /* original f2a2, guest PC 0x0c07146e */
if(!s->budget--) { s->failed_pc=0x0c07146eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071470;
P_0c071470: /* original f16c, guest PC 0x0c071470 */
if(!s->budget--) { s->failed_pc=0x0c071470u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071472;
P_0c071472: /* original f192, guest PC 0x0c071472 */
if(!s->budget--) { s->failed_pc=0x0c071472u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071474;
P_0c071474: /* original f34d, guest PC 0x0c071474 */
if(!s->budget--) { s->failed_pc=0x0c071474u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071476;
P_0c071476: /* original f39e, guest PC 0x0c071476 */
if(!s->budget--) { s->failed_pc=0x0c071476u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071478;
P_0c071478: /* original f24d, guest PC 0x0c071478 */
if(!s->budget--) { s->failed_pc=0x0c071478u; return 0; }
fr[2]^=0x80000000u;
goto P_0c07147a;
P_0c07147a: /* original f06c, guest PC 0x0c07147a */
if(!s->budget--) { s->failed_pc=0x0c07147au; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07147c;
P_0c07147c: /* original f28e, guest PC 0x0c07147c */
if(!s->budget--) { s->failed_pc=0x0c07147cu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07147e;
P_0c07147e: /* original f14d, guest PC 0x0c07147e */
if(!s->budget--) { s->failed_pc=0x0c07147eu; return 0; }
fr[1]^=0x80000000u;
goto P_0c071480;
P_0c071480: /* original f05c, guest PC 0x0c071480 */
if(!s->budget--) { s->failed_pc=0x0c071480u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071482;
P_0c071482: /* original f1ae, guest PC 0x0c071482 */
if(!s->budget--) { s->failed_pc=0x0c071482u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071484;
P_0c071484: /* original f08d, guest PC 0x0c071484 */
if(!s->budget--) { s->failed_pc=0x0c071484u; return 0; }
fr[0]=0;
goto P_0c071486;
P_0c071486: /* original f0ed, guest PC 0x0c071486 */
if(!s->budget--) { s->failed_pc=0x0c071486u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071488;
P_0c071488: /* original f03c, guest PC 0x0c071488 */
if(!s->budget--) { s->failed_pc=0x0c071488u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c07148a;
P_0c07148a: /* original f06d, guest PC 0x0c07148a */
if(!s->budget--) { s->failed_pc=0x0c07148au; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07148c;
P_0c07148c: /* original fe0c, guest PC 0x0c07148c */
if(!s->budget--) { s->failed_pc=0x0c07148cu; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c07148e;
P_0c07148e: /* original ffe5, guest PC 0x0c07148e */
if(!s->budget--) { s->failed_pc=0x0c07148eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c071490;
P_0c071490: /* original 8902, guest PC 0x0c071490 */
if(!s->budget--) { s->failed_pc=0x0c071490u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071498; }
goto P_0c071492;
P_0c071492: /* original d304, guest PC 0x0c071492 */
if(!s->budget--) { s->failed_pc=0x0c071492u; return 0; }
r[3]=read(ram,0x0c0714a4u,4);
goto P_0c071494;
P_0c071494: /* original 432b, guest PC 0x0c071494 */
if(!s->budget--) { s->failed_pc=0x0c071494u; return 0; }
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
P_0c071496: /* original 0009, guest PC 0x0c071496 */
if(!s->budget--) { s->failed_pc=0x0c071496u; return 0; }
goto P_0c071498;
P_0c071498: /* original 64f3, guest PC 0x0c071498 */
if(!s->budget--) { s->failed_pc=0x0c071498u; return 0; }
r[4]=r[15];
goto P_0c07149a;
P_0c07149a: /* original 741c, guest PC 0x0c07149a */
if(!s->budget--) { s->failed_pc=0x0c07149au; return 0; }
r[4]+=0x0000001cu;
goto P_0c07149c;
P_0c07149c: /* original 65d3, guest PC 0x0c07149c */
if(!s->budget--) { s->failed_pc=0x0c07149cu; return 0; }
r[5]=r[13];
goto P_0c07149e;
P_0c07149e: /* original a003, guest PC 0x0c07149e */
if(!s->budget--) { s->failed_pc=0x0c07149eu; return 0; }
goto P_0c0714a8;
P_0c0714a0: /* original 0009, guest PC 0x0c0714a0 */
if(!s->budget--) { s->failed_pc=0x0c0714a0u; return 0; }
return vf3_matrix_family(0x0c0714a2u,s,ram);
P_0c0714a8: /* original f049, guest PC 0x0c0714a8 */
if(!s->budget--) { s->failed_pc=0x0c0714a8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714aa;
P_0c0714aa: /* original f149, guest PC 0x0c0714aa */
if(!s->budget--) { s->failed_pc=0x0c0714aau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ac;
P_0c0714ac: /* original f249, guest PC 0x0c0714ac */
if(!s->budget--) { s->failed_pc=0x0c0714acu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ae;
P_0c0714ae: /* original f38d, guest PC 0x0c0714ae */
if(!s->budget--) { s->failed_pc=0x0c0714aeu; return 0; }
fr[3]=0;
goto P_0c0714b0;
P_0c0714b0: /* original f459, guest PC 0x0c0714b0 */
if(!s->budget--) { s->failed_pc=0x0c0714b0u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b2;
P_0c0714b2: /* original f559, guest PC 0x0c0714b2 */
if(!s->budget--) { s->failed_pc=0x0c0714b2u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b4;
P_0c0714b4: /* original f659, guest PC 0x0c0714b4 */
if(!s->budget--) { s->failed_pc=0x0c0714b4u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714b6;
P_0c0714b6: /* original f78d, guest PC 0x0c0714b6 */
if(!s->budget--) { s->failed_pc=0x0c0714b6u; return 0; }
fr[7]=0;
goto P_0c0714b8;
P_0c0714b8: /* original f4ed, guest PC 0x0c0714b8 */
if(!s->budget--) { s->failed_pc=0x0c0714b8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0714ba;
P_0c0714ba: /* original f07c, guest PC 0x0c0714ba */
if(!s->budget--) { s->failed_pc=0x0c0714bau; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0714bc;
P_0c0714bc: /* original f38d, guest PC 0x0c0714bc */
if(!s->budget--) { s->failed_pc=0x0c0714bcu; return 0; }
fr[3]=0;
goto P_0c0714be;
P_0c0714be: /* original f40c, guest PC 0x0c0714be */
if(!s->budget--) { s->failed_pc=0x0c0714beu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0714c0;
P_0c0714c0: /* original f345, guest PC 0x0c0714c0 */
if(!s->budget--) { s->failed_pc=0x0c0714c0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0714c2;
P_0c0714c2: /* original 8902, guest PC 0x0c0714c2 */
if(!s->budget--) { s->failed_pc=0x0c0714c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0714ca; }
goto P_0c0714c4;
P_0c0714c4: /* original d307, guest PC 0x0c0714c4 */
if(!s->budget--) { s->failed_pc=0x0c0714c4u; return 0; }
r[3]=read(ram,0x0c0714e4u,4);
goto P_0c0714c6;
P_0c0714c6: /* original 432b, guest PC 0x0c0714c6 */
if(!s->budget--) { s->failed_pc=0x0c0714c6u; return 0; }
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
P_0c0714c8: /* original 0009, guest PC 0x0c0714c8 */
if(!s->budget--) { s->failed_pc=0x0c0714c8u; return 0; }
goto P_0c0714ca;
P_0c0714ca: /* original ffd5, guest PC 0x0c0714ca */
if(!s->budget--) { s->failed_pc=0x0c0714cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[13]))!=0);
goto P_0c0714cc;
P_0c0714cc: /* original 8902, guest PC 0x0c0714cc */
if(!s->budget--) { s->failed_pc=0x0c0714ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0714d4; }
goto P_0c0714ce;
P_0c0714ce: /* original d206, guest PC 0x0c0714ce */
if(!s->budget--) { s->failed_pc=0x0c0714ceu; return 0; }
r[2]=read(ram,0x0c0714e8u,4);
goto P_0c0714d0;
P_0c0714d0: /* original 422b, guest PC 0x0c0714d0 */
if(!s->budget--) { s->failed_pc=0x0c0714d0u; return 0; }
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
P_0c0714d2: /* original 0009, guest PC 0x0c0714d2 */
if(!s->budget--) { s->failed_pc=0x0c0714d2u; return 0; }
goto P_0c0714d4;
P_0c0714d4: /* original 64f3, guest PC 0x0c0714d4 */
if(!s->budget--) { s->failed_pc=0x0c0714d4u; return 0; }
r[4]=r[15];
goto P_0c0714d6;
P_0c0714d6: /* original 65f3, guest PC 0x0c0714d6 */
if(!s->budget--) { s->failed_pc=0x0c0714d6u; return 0; }
r[5]=r[15];
goto P_0c0714d8;
P_0c0714d8: /* original 741c, guest PC 0x0c0714d8 */
if(!s->budget--) { s->failed_pc=0x0c0714d8u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0714da;
P_0c0714da: /* original f4fc, guest PC 0x0c0714da */
if(!s->budget--) { s->failed_pc=0x0c0714dau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0714dc;
P_0c0714dc: /* original 751c, guest PC 0x0c0714dc */
if(!s->budget--) { s->failed_pc=0x0c0714dcu; return 0; }
r[5]+=0x0000001cu;
goto P_0c0714de;
P_0c0714de: /* original a005, guest PC 0x0c0714de */
if(!s->budget--) { s->failed_pc=0x0c0714deu; return 0; }
goto P_0c0714ec;
P_0c0714e0: /* original 0009, guest PC 0x0c0714e0 */
if(!s->budget--) { s->failed_pc=0x0c0714e0u; return 0; }
return vf3_matrix_family(0x0c0714e2u,s,ram);
P_0c0714ec: /* original f059, guest PC 0x0c0714ec */
if(!s->budget--) { s->failed_pc=0x0c0714ecu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714ee;
P_0c0714ee: /* original f159, guest PC 0x0c0714ee */
if(!s->budget--) { s->failed_pc=0x0c0714eeu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714f0;
P_0c0714f0: /* original f259, guest PC 0x0c0714f0 */
if(!s->budget--) { s->failed_pc=0x0c0714f0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0714f2;
P_0c0714f2: /* original f38d, guest PC 0x0c0714f2 */
if(!s->budget--) { s->failed_pc=0x0c0714f2u; return 0; }
fr[3]=0;
goto P_0c0714f4;
P_0c0714f4: /* original f0ed, guest PC 0x0c0714f4 */
if(!s->budget--) { s->failed_pc=0x0c0714f4u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0714f6;
P_0c0714f6: /* original f37d, guest PC 0x0c0714f6 */
if(!s->budget--) { s->failed_pc=0x0c0714f6u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0714f8;
P_0c0714f8: /* original f342, guest PC 0x0c0714f8 */
if(!s->budget--) { s->failed_pc=0x0c0714f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0714fa;
P_0c0714fa: /* original 740c, guest PC 0x0c0714fa */
if(!s->budget--) { s->failed_pc=0x0c0714fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0714fc;
P_0c0714fc: /* original f232, guest PC 0x0c0714fc */
if(!s->budget--) { s->failed_pc=0x0c0714fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0714fe;
P_0c0714fe: /* original f132, guest PC 0x0c0714fe */
if(!s->budget--) { s->failed_pc=0x0c0714feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071500;
P_0c071500: /* original f032, guest PC 0x0c071500 */
if(!s->budget--) { s->failed_pc=0x0c071500u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071502;
P_0c071502: /* original f42b, guest PC 0x0c071502 */
if(!s->budget--) { s->failed_pc=0x0c071502u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071504;
P_0c071504: /* original f41b, guest PC 0x0c071504 */
if(!s->budget--) { s->failed_pc=0x0c071504u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071506;
P_0c071506: /* original f40b, guest PC 0x0c071506 */
if(!s->budget--) { s->failed_pc=0x0c071506u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071508;
P_0c071508: /* original d206, guest PC 0x0c071508 */
if(!s->budget--) { s->failed_pc=0x0c071508u; return 0; }
r[2]=read(ram,0x0c071524u,4);
goto P_0c07150a;
P_0c07150a: /* original 422b, guest PC 0x0c07150a */
if(!s->budget--) { s->failed_pc=0x0c07150au; return 0; }
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
P_0c07150c: /* original 0009, guest PC 0x0c07150c */
if(!s->budget--) { s->failed_pc=0x0c07150cu; return 0; }
return vf3_matrix_family(0x0c07150eu,s,ram);
P_0c0715b0: /* original 65f3, guest PC 0x0c0715b0 */
if(!s->budget--) { s->failed_pc=0x0c0715b0u; return 0; }
r[5]=r[15];
goto P_0c0715b2;
P_0c0715b2: /* original 64e3, guest PC 0x0c0715b2 */
if(!s->budget--) { s->failed_pc=0x0c0715b2u; return 0; }
r[4]=r[14];
goto P_0c0715b4;
P_0c0715b4: /* original 751c, guest PC 0x0c0715b4 */
if(!s->budget--) { s->failed_pc=0x0c0715b4u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0715b6;
P_0c0715b6: /* original 66b3, guest PC 0x0c0715b6 */
if(!s->budget--) { s->failed_pc=0x0c0715b6u; return 0; }
r[6]=r[11];
goto P_0c0715b8;
P_0c0715b8: /* original f059, guest PC 0x0c0715b8 */
if(!s->budget--) { s->failed_pc=0x0c0715b8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715ba;
P_0c0715ba: /* original f369, guest PC 0x0c0715ba */
if(!s->budget--) { s->failed_pc=0x0c0715bau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715bc;
P_0c0715bc: /* original f159, guest PC 0x0c0715bc */
if(!s->budget--) { s->failed_pc=0x0c0715bcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715be;
P_0c0715be: /* original f469, guest PC 0x0c0715be */
if(!s->budget--) { s->failed_pc=0x0c0715beu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715c0;
P_0c0715c0: /* original f259, guest PC 0x0c0715c0 */
if(!s->budget--) { s->failed_pc=0x0c0715c0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715c2;
P_0c0715c2: /* original f569, guest PC 0x0c0715c2 */
if(!s->budget--) { s->failed_pc=0x0c0715c2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715c4;
P_0c0715c4: /* original 740c, guest PC 0x0c0715c4 */
if(!s->budget--) { s->failed_pc=0x0c0715c4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0715c6;
P_0c0715c6: /* original f030, guest PC 0x0c0715c6 */
if(!s->budget--) { s->failed_pc=0x0c0715c6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0715c8;
P_0c0715c8: /* original f250, guest PC 0x0c0715c8 */
if(!s->budget--) { s->failed_pc=0x0c0715c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0715ca;
P_0c0715ca: /* original f140, guest PC 0x0c0715ca */
if(!s->budget--) { s->failed_pc=0x0c0715cau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0715cc;
P_0c0715cc: /* original f42b, guest PC 0x0c0715cc */
if(!s->budget--) { s->failed_pc=0x0c0715ccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0715ce;
P_0c0715ce: /* original f41b, guest PC 0x0c0715ce */
if(!s->budget--) { s->failed_pc=0x0c0715ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0715d0;
P_0c0715d0: /* original f40b, guest PC 0x0c0715d0 */
if(!s->budget--) { s->failed_pc=0x0c0715d0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0715d2;
P_0c0715d2: /* original 0009, guest PC 0x0c0715d2 */
if(!s->budget--) { s->failed_pc=0x0c0715d2u; return 0; }
goto P_0c0715d4;
P_0c0715d4: /* original 64f3, guest PC 0x0c0715d4 */
if(!s->budget--) { s->failed_pc=0x0c0715d4u; return 0; }
r[4]=r[15];
goto P_0c0715d6;
P_0c0715d6: /* original 7404, guest PC 0x0c0715d6 */
if(!s->budget--) { s->failed_pc=0x0c0715d6u; return 0; }
r[4]+=0x00000004u;
goto P_0c0715d8;
P_0c0715d8: /* original 66c3, guest PC 0x0c0715d8 */
if(!s->budget--) { s->failed_pc=0x0c0715d8u; return 0; }
r[6]=r[12];
goto P_0c0715da;
P_0c0715da: /* original 65e3, guest PC 0x0c0715da */
if(!s->budget--) { s->failed_pc=0x0c0715dau; return 0; }
r[5]=r[14];
goto P_0c0715dc;
P_0c0715dc: /* original f059, guest PC 0x0c0715dc */
if(!s->budget--) { s->failed_pc=0x0c0715dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715de;
P_0c0715de: /* original f369, guest PC 0x0c0715de */
if(!s->budget--) { s->failed_pc=0x0c0715deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715e0;
P_0c0715e0: /* original f159, guest PC 0x0c0715e0 */
if(!s->budget--) { s->failed_pc=0x0c0715e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0715e2;
P_0c0715e2: /* original f469, guest PC 0x0c0715e2 */
if(!s->budget--) { s->failed_pc=0x0c0715e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0715e4;
P_0c0715e4: /* original f031, guest PC 0x0c0715e4 */
if(!s->budget--) { s->failed_pc=0x0c0715e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0715e6;
P_0c0715e6: /* original f258, guest PC 0x0c0715e6 */
if(!s->budget--) { s->failed_pc=0x0c0715e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0715e8;
P_0c0715e8: /* original f568, guest PC 0x0c0715e8 */
if(!s->budget--) { s->failed_pc=0x0c0715e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0715ea;
P_0c0715ea: /* original f141, guest PC 0x0c0715ea */
if(!s->budget--) { s->failed_pc=0x0c0715eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0715ec;
P_0c0715ec: /* original f251, guest PC 0x0c0715ec */
if(!s->budget--) { s->failed_pc=0x0c0715ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0715ee;
P_0c0715ee: /* original 7408, guest PC 0x0c0715ee */
if(!s->budget--) { s->failed_pc=0x0c0715eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0715f0;
P_0c0715f0: /* original f42a, guest PC 0x0c0715f0 */
if(!s->budget--) { s->failed_pc=0x0c0715f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0715f2;
P_0c0715f2: /* original f41b, guest PC 0x0c0715f2 */
if(!s->budget--) { s->failed_pc=0x0c0715f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0715f4;
P_0c0715f4: /* original f40b, guest PC 0x0c0715f4 */
if(!s->budget--) { s->failed_pc=0x0c0715f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0715f6;
P_0c0715f6: /* original 0009, guest PC 0x0c0715f6 */
if(!s->budget--) { s->failed_pc=0x0c0715f6u; return 0; }
goto P_0c0715f8;
P_0c0715f8: /* original 64f3, guest PC 0x0c0715f8 */
if(!s->budget--) { s->failed_pc=0x0c0715f8u; return 0; }
r[4]=r[15];
goto P_0c0715fa;
P_0c0715fa: /* original 7404, guest PC 0x0c0715fa */
if(!s->budget--) { s->failed_pc=0x0c0715fau; return 0; }
r[4]+=0x00000004u;
goto P_0c0715fc;
P_0c0715fc: /* original f049, guest PC 0x0c0715fc */
if(!s->budget--) { s->failed_pc=0x0c0715fcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0715fe;
P_0c0715fe: /* original f149, guest PC 0x0c0715fe */
if(!s->budget--) { s->failed_pc=0x0c0715feu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071600;
P_0c071600: /* original f249, guest PC 0x0c071600 */
if(!s->budget--) { s->failed_pc=0x0c071600u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071602;
P_0c071602: /* original f38d, guest PC 0x0c071602 */
if(!s->budget--) { s->failed_pc=0x0c071602u; return 0; }
fr[3]=0;
goto P_0c071604;
P_0c071604: /* original f0ed, guest PC 0x0c071604 */
if(!s->budget--) { s->failed_pc=0x0c071604u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071606;
P_0c071606: /* original f03c, guest PC 0x0c071606 */
if(!s->budget--) { s->failed_pc=0x0c071606u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c071608;
P_0c071608: /* original f06d, guest PC 0x0c071608 */
if(!s->budget--) { s->failed_pc=0x0c071608u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07160a;
P_0c07160a: /* original 0009, guest PC 0x0c07160a */
if(!s->budget--) { s->failed_pc=0x0c07160au; return 0; }
goto P_0c07160c;
P_0c07160c: /* original f38d, guest PC 0x0c07160c */
if(!s->budget--) { s->failed_pc=0x0c07160cu; return 0; }
fr[3]=0;
goto P_0c07160e;
P_0c07160e: /* original f035, guest PC 0x0c07160e */
if(!s->budget--) { s->failed_pc=0x0c07160eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c071610;
P_0c071610: /* original 8902, guest PC 0x0c071610 */
if(!s->budget--) { s->failed_pc=0x0c071610u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c071618; }
goto P_0c071612;
P_0c071612: /* original d305, guest PC 0x0c071612 */
if(!s->budget--) { s->failed_pc=0x0c071612u; return 0; }
r[3]=read(ram,0x0c071628u,4);
goto P_0c071614;
P_0c071614: /* original 432b, guest PC 0x0c071614 */
if(!s->budget--) { s->failed_pc=0x0c071614u; return 0; }
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
P_0c071616: /* original 0009, guest PC 0x0c071616 */
if(!s->budget--) { s->failed_pc=0x0c071616u; return 0; }
goto P_0c071618;
P_0c071618: /* original 64f3, guest PC 0x0c071618 */
if(!s->budget--) { s->failed_pc=0x0c071618u; return 0; }
r[4]=r[15];
goto P_0c07161a;
P_0c07161a: /* original 65f3, guest PC 0x0c07161a */
if(!s->budget--) { s->failed_pc=0x0c07161au; return 0; }
r[5]=r[15];
goto P_0c07161c;
P_0c07161c: /* original f4f8, guest PC 0x0c07161c */
if(!s->budget--) { s->failed_pc=0x0c07161cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c07161e;
P_0c07161e: /* original 7404, guest PC 0x0c07161e */
if(!s->budget--) { s->failed_pc=0x0c07161eu; return 0; }
r[4]+=0x00000004u;
goto P_0c071620;
P_0c071620: /* original 7504, guest PC 0x0c071620 */
if(!s->budget--) { s->failed_pc=0x0c071620u; return 0; }
r[5]+=0x00000004u;
goto P_0c071622;
P_0c071622: /* original a003, guest PC 0x0c071622 */
if(!s->budget--) { s->failed_pc=0x0c071622u; return 0; }
goto P_0c07162c;
P_0c071624: /* original 0009, guest PC 0x0c071624 */
if(!s->budget--) { s->failed_pc=0x0c071624u; return 0; }
return vf3_matrix_family(0x0c071626u,s,ram);
P_0c07162c: /* original f059, guest PC 0x0c07162c */
if(!s->budget--) { s->failed_pc=0x0c07162cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07162e;
P_0c07162e: /* original f159, guest PC 0x0c07162e */
if(!s->budget--) { s->failed_pc=0x0c07162eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071630;
P_0c071630: /* original f259, guest PC 0x0c071630 */
if(!s->budget--) { s->failed_pc=0x0c071630u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071632;
P_0c071632: /* original f38d, guest PC 0x0c071632 */
if(!s->budget--) { s->failed_pc=0x0c071632u; return 0; }
fr[3]=0;
goto P_0c071634;
P_0c071634: /* original f0ed, guest PC 0x0c071634 */
if(!s->budget--) { s->failed_pc=0x0c071634u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071636;
P_0c071636: /* original f37d, guest PC 0x0c071636 */
if(!s->budget--) { s->failed_pc=0x0c071636u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071638;
P_0c071638: /* original f342, guest PC 0x0c071638 */
if(!s->budget--) { s->failed_pc=0x0c071638u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07163a;
P_0c07163a: /* original 740c, guest PC 0x0c07163a */
if(!s->budget--) { s->failed_pc=0x0c07163au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07163c;
P_0c07163c: /* original f232, guest PC 0x0c07163c */
if(!s->budget--) { s->failed_pc=0x0c07163cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07163e;
P_0c07163e: /* original f132, guest PC 0x0c07163e */
if(!s->budget--) { s->failed_pc=0x0c07163eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071640;
P_0c071640: /* original f032, guest PC 0x0c071640 */
if(!s->budget--) { s->failed_pc=0x0c071640u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071642;
P_0c071642: /* original f42b, guest PC 0x0c071642 */
if(!s->budget--) { s->failed_pc=0x0c071642u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071644;
P_0c071644: /* original f41b, guest PC 0x0c071644 */
if(!s->budget--) { s->failed_pc=0x0c071644u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071646;
P_0c071646: /* original f40b, guest PC 0x0c071646 */
if(!s->budget--) { s->failed_pc=0x0c071646u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071648;
P_0c071648: /* original 66f3, guest PC 0x0c071648 */
if(!s->budget--) { s->failed_pc=0x0c071648u; return 0; }
r[6]=r[15];
goto P_0c07164a;
P_0c07164a: /* original 64e3, guest PC 0x0c07164a */
if(!s->budget--) { s->failed_pc=0x0c07164au; return 0; }
r[4]=r[14];
goto P_0c07164c;
P_0c07164c: /* original 65c3, guest PC 0x0c07164c */
if(!s->budget--) { s->failed_pc=0x0c07164cu; return 0; }
r[5]=r[12];
goto P_0c07164e;
P_0c07164e: /* original 7604, guest PC 0x0c07164e */
if(!s->budget--) { s->failed_pc=0x0c07164eu; return 0; }
r[6]+=0x00000004u;
goto P_0c071650;
P_0c071650: /* original f059, guest PC 0x0c071650 */
if(!s->budget--) { s->failed_pc=0x0c071650u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071652;
P_0c071652: /* original f369, guest PC 0x0c071652 */
if(!s->budget--) { s->failed_pc=0x0c071652u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071654;
P_0c071654: /* original f159, guest PC 0x0c071654 */
if(!s->budget--) { s->failed_pc=0x0c071654u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071656;
P_0c071656: /* original f469, guest PC 0x0c071656 */
if(!s->budget--) { s->failed_pc=0x0c071656u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071658;
P_0c071658: /* original f259, guest PC 0x0c071658 */
if(!s->budget--) { s->failed_pc=0x0c071658u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07165a;
P_0c07165a: /* original f569, guest PC 0x0c07165a */
if(!s->budget--) { s->failed_pc=0x0c07165au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07165c;
P_0c07165c: /* original 740c, guest PC 0x0c07165c */
if(!s->budget--) { s->failed_pc=0x0c07165cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c07165e;
P_0c07165e: /* original f030, guest PC 0x0c07165e */
if(!s->budget--) { s->failed_pc=0x0c07165eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071660;
P_0c071660: /* original f250, guest PC 0x0c071660 */
if(!s->budget--) { s->failed_pc=0x0c071660u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071662;
P_0c071662: /* original f140, guest PC 0x0c071662 */
if(!s->budget--) { s->failed_pc=0x0c071662u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071664;
P_0c071664: /* original f42b, guest PC 0x0c071664 */
if(!s->budget--) { s->failed_pc=0x0c071664u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071666;
P_0c071666: /* original f41b, guest PC 0x0c071666 */
if(!s->budget--) { s->failed_pc=0x0c071666u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071668;
P_0c071668: /* original f40b, guest PC 0x0c071668 */
if(!s->budget--) { s->failed_pc=0x0c071668u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07166a;
P_0c07166a: /* original 0009, guest PC 0x0c07166a */
if(!s->budget--) { s->failed_pc=0x0c07166au; return 0; }
goto P_0c07166c;
P_0c07166c: /* original 79ff, guest PC 0x0c07166c */
if(!s->budget--) { s->failed_pc=0x0c07166cu; return 0; }
r[9]+=0xffffffffu;
goto P_0c07166e;
P_0c07166e: /* original 39a7, guest PC 0x0c07166e */
if(!s->budget--) { s->failed_pc=0x0c07166eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>(int32_t)r[10])!=0);
goto P_0c071670;
P_0c071670: /* original 7c18, guest PC 0x0c071670 */
if(!s->budget--) { s->failed_pc=0x0c071670u; return 0; }
r[12]+=0x00000018u;
goto P_0c071672;
P_0c071672: /* original 8f03, guest PC 0x0c071672 */
if(!s->budget--) { s->failed_pc=0x0c071672u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c07167c; }
goto P_0c071676;
P_0c071674: /* original 7e18, guest PC 0x0c071674 */
if(!s->budget--) { s->failed_pc=0x0c071674u; return 0; }
r[14]+=0x00000018u;
goto P_0c071676;
P_0c071676: /* original d321, guest PC 0x0c071676 */
if(!s->budget--) { s->failed_pc=0x0c071676u; return 0; }
r[3]=read(ram,0x0c0716fcu,4);
goto P_0c071678;
P_0c071678: /* original 432b, guest PC 0x0c071678 */
if(!s->budget--) { s->failed_pc=0x0c071678u; return 0; }
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
P_0c07167a: /* original 0009, guest PC 0x0c07167a */
if(!s->budget--) { s->failed_pc=0x0c07167au; return 0; }
goto P_0c07167c;
P_0c07167c: /* original 7f34, guest PC 0x0c07167c */
if(!s->budget--) { s->failed_pc=0x0c07167cu; return 0; }
r[15]+=0x00000034u;
goto P_0c07167e;
P_0c07167e: /* original fcf9, guest PC 0x0c07167e */
if(!s->budget--) { s->failed_pc=0x0c07167eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071680;
P_0c071680: /* original fdf9, guest PC 0x0c071680 */
if(!s->budget--) { s->failed_pc=0x0c071680u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071682;
P_0c071682: /* original fef9, guest PC 0x0c071682 */
if(!s->budget--) { s->failed_pc=0x0c071682u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071684;
P_0c071684: /* original fff9, guest PC 0x0c071684 */
if(!s->budget--) { s->failed_pc=0x0c071684u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071686;
P_0c071686: /* original 69f6, guest PC 0x0c071686 */
if(!s->budget--) { s->failed_pc=0x0c071686u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c071688;
P_0c071688: /* original 6af6, guest PC 0x0c071688 */
if(!s->budget--) { s->failed_pc=0x0c071688u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07168a;
P_0c07168a: /* original 6bf6, guest PC 0x0c07168a */
if(!s->budget--) { s->failed_pc=0x0c07168au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07168c;
P_0c07168c: /* original 6cf6, guest PC 0x0c07168c */
if(!s->budget--) { s->failed_pc=0x0c07168cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07168e;
P_0c07168e: /* original 6df6, guest PC 0x0c07168e */
if(!s->budget--) { s->failed_pc=0x0c07168eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c071690;
P_0c071690: /* original 000b, guest PC 0x0c071690 */
if(!s->budget--) { s->failed_pc=0x0c071690u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c071692: /* original 6ef6, guest PC 0x0c071692 */
if(!s->budget--) { s->failed_pc=0x0c071692u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c071694;
P_0c071694: /* original 2fe6, guest PC 0x0c071694 */
if(!s->budget--) { s->failed_pc=0x0c071694u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c071696;
P_0c071696: /* original e058, guest PC 0x0c071696 */
if(!s->budget--) { s->failed_pc=0x0c071696u; return 0; }
r[0]=0x00000058u;
goto P_0c071698;
P_0c071698: /* original 2fd6, guest PC 0x0c071698 */
if(!s->budget--) { s->failed_pc=0x0c071698u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c07169a;
P_0c07169a: /* original 2fc6, guest PC 0x0c07169a */
if(!s->budget--) { s->failed_pc=0x0c07169au; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c07169c;
P_0c07169c: /* original 2fb6, guest PC 0x0c07169c */
if(!s->budget--) { s->failed_pc=0x0c07169cu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07169e;
P_0c07169e: /* original 2fa6, guest PC 0x0c07169e */
if(!s->budget--) { s->failed_pc=0x0c07169eu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0716a0;
P_0c0716a0: /* original 2f96, guest PC 0x0c0716a0 */
if(!s->budget--) { s->failed_pc=0x0c0716a0u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0716a2;
P_0c0716a2: /* original 2f86, guest PC 0x0c0716a2 */
if(!s->budget--) { s->failed_pc=0x0c0716a2u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0716a4;
P_0c0716a4: /* original 054e, guest PC 0x0c0716a4 */
if(!s->budget--) { s->failed_pc=0x0c0716a4u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0716a6;
P_0c0716a6: /* original e05c, guest PC 0x0c0716a6 */
if(!s->budget--) { s->failed_pc=0x0c0716a6u; return 0; }
r[0]=0x0000005cu;
goto P_0c0716a8;
P_0c0716a8: /* original 034e, guest PC 0x0c0716a8 */
if(!s->budget--) { s->failed_pc=0x0c0716a8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0716aa;
P_0c0716aa: /* original 7fa0, guest PC 0x0c0716aa */
if(!s->budget--) { s->failed_pc=0x0c0716aau; return 0; }
r[15]+=0xffffffa0u;
goto P_0c0716ac;
P_0c0716ac: /* original 6253, guest PC 0x0c0716ac */
if(!s->budget--) { s->failed_pc=0x0c0716acu; return 0; }
r[2]=r[5];
goto P_0c0716ae;
P_0c0716ae: /* original 1f33, guest PC 0x0c0716ae */
if(!s->budget--) { s->failed_pc=0x0c0716aeu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0716b0;
P_0c0716b0: /* original 6353, guest PC 0x0c0716b0 */
if(!s->budget--) { s->failed_pc=0x0c0716b0u; return 0; }
r[3]=r[5];
goto P_0c0716b2;
P_0c0716b2: /* original 4300, guest PC 0x0c0716b2 */
if(!s->budget--) { s->failed_pc=0x0c0716b2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0716b4;
P_0c0716b4: /* original 5441, guest PC 0x0c0716b4 */
if(!s->budget--) { s->failed_pc=0x0c0716b4u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0716b6;
P_0c0716b6: /* original 332c, guest PC 0x0c0716b6 */
if(!s->budget--) { s->failed_pc=0x0c0716b6u; return 0; }
r[3]+=r[2];
goto P_0c0716b8;
P_0c0716b8: /* original 6b43, guest PC 0x0c0716b8 */
if(!s->budget--) { s->failed_pc=0x0c0716b8u; return 0; }
r[11]=r[4];
goto P_0c0716ba;
P_0c0716ba: /* original 4308, guest PC 0x0c0716ba */
if(!s->budget--) { s->failed_pc=0x0c0716bau; return 0; }
r[3]<<=2;
goto P_0c0716bc;
P_0c0716bc: /* original 7b18, guest PC 0x0c0716bc */
if(!s->budget--) { s->failed_pc=0x0c0716bcu; return 0; }
r[11]+=0x00000018u;
goto P_0c0716be;
P_0c0716be: /* original 6843, guest PC 0x0c0716be */
if(!s->budget--) { s->failed_pc=0x0c0716beu; return 0; }
r[8]=r[4];
goto P_0c0716c0;
P_0c0716c0: /* original 4300, guest PC 0x0c0716c0 */
if(!s->budget--) { s->failed_pc=0x0c0716c0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0716c2;
P_0c0716c2: /* original 6eb3, guest PC 0x0c0716c2 */
if(!s->budget--) { s->failed_pc=0x0c0716c2u; return 0; }
r[14]=r[11];
goto P_0c0716c4;
P_0c0716c4: /* original 334c, guest PC 0x0c0716c4 */
if(!s->budget--) { s->failed_pc=0x0c0716c4u; return 0; }
r[3]+=r[4];
goto P_0c0716c6;
P_0c0716c6: /* original 2f32, guest PC 0x0c0716c6 */
if(!s->budget--) { s->failed_pc=0x0c0716c6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0716c8;
P_0c0716c8: /* original 75ff, guest PC 0x0c0716c8 */
if(!s->budget--) { s->failed_pc=0x0c0716c8u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0716ca;
P_0c0716ca: /* original 7b18, guest PC 0x0c0716ca */
if(!s->budget--) { s->failed_pc=0x0c0716cau; return 0; }
r[11]+=0x00000018u;
goto P_0c0716cc;
P_0c0716cc: /* original 1f41, guest PC 0x0c0716cc */
if(!s->budget--) { s->failed_pc=0x0c0716ccu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0716ce;
P_0c0716ce: /* original 62f2, guest PC 0x0c0716ce */
if(!s->budget--) { s->failed_pc=0x0c0716ceu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0716d0;
P_0c0716d0: /* original 7218, guest PC 0x0c0716d0 */
if(!s->budget--) { s->failed_pc=0x0c0716d0u; return 0; }
r[2]+=0x00000018u;
goto P_0c0716d2;
P_0c0716d2: /* original 2f22, guest PC 0x0c0716d2 */
if(!s->budget--) { s->failed_pc=0x0c0716d2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0716d4;
P_0c0716d4: /* original 6af3, guest PC 0x0c0716d4 */
if(!s->budget--) { s->failed_pc=0x0c0716d4u; return 0; }
r[10]=r[15];
goto P_0c0716d6;
P_0c0716d6: /* original e901, guest PC 0x0c0716d6 */
if(!s->budget--) { s->failed_pc=0x0c0716d6u; return 0; }
r[9]=0x00000001u;
goto P_0c0716d8;
P_0c0716d8: /* original 6353, guest PC 0x0c0716d8 */
if(!s->budget--) { s->failed_pc=0x0c0716d8u; return 0; }
r[3]=r[5];
goto P_0c0716da;
P_0c0716da: /* original 6df3, guest PC 0x0c0716da */
if(!s->budget--) { s->failed_pc=0x0c0716dau; return 0; }
r[13]=r[15];
goto P_0c0716dc;
P_0c0716dc: /* original 1f55, guest PC 0x0c0716dc */
if(!s->budget--) { s->failed_pc=0x0c0716dcu; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c0716de;
P_0c0716de: /* original 3397, guest PC 0x0c0716de */
if(!s->budget--) { s->failed_pc=0x0c0716deu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[9])!=0);
goto P_0c0716e0;
P_0c0716e0: /* original 1f52, guest PC 0x0c0716e0 */
if(!s->budget--) { s->failed_pc=0x0c0716e0u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0716e2;
P_0c0716e2: /* original 7d30, guest PC 0x0c0716e2 */
if(!s->budget--) { s->failed_pc=0x0c0716e2u; return 0; }
r[13]+=0x00000030u;
goto P_0c0716e4;
P_0c0716e4: /* original 7a3c, guest PC 0x0c0716e4 */
if(!s->budget--) { s->failed_pc=0x0c0716e4u; return 0; }
r[10]+=0x0000003cu;
goto P_0c0716e6;
P_0c0716e6: /* original 6cf3, guest PC 0x0c0716e6 */
if(!s->budget--) { s->failed_pc=0x0c0716e6u; return 0; }
r[12]=r[15];
goto P_0c0716e8;
P_0c0716e8: /* original 8d03, guest PC 0x0c0716e8 */
if(!s->budget--) { s->failed_pc=0x0c0716e8u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000048u;
if(cond) { goto P_0c0716f2; }
goto P_0c0716ec;
P_0c0716ea: /* original 7c48, guest PC 0x0c0716ea */
if(!s->budget--) { s->failed_pc=0x0c0716eau; return 0; }
r[12]+=0x00000048u;
goto P_0c0716ec;
P_0c0716ec: /* original d104, guest PC 0x0c0716ec */
if(!s->budget--) { s->failed_pc=0x0c0716ecu; return 0; }
r[1]=read(ram,0x0c071700u,4);
goto P_0c0716ee;
P_0c0716ee: /* original 412b, guest PC 0x0c0716ee */
if(!s->budget--) { s->failed_pc=0x0c0716eeu; return 0; }
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
P_0c0716f0: /* original 0009, guest PC 0x0c0716f0 */
if(!s->budget--) { s->failed_pc=0x0c0716f0u; return 0; }
goto P_0c0716f2;
P_0c0716f2: /* original 55f1, guest PC 0x0c0716f2 */
if(!s->budget--) { s->failed_pc=0x0c0716f2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0716f4;
P_0c0716f4: /* original 64d3, guest PC 0x0c0716f4 */
if(!s->budget--) { s->failed_pc=0x0c0716f4u; return 0; }
r[4]=r[13];
goto P_0c0716f6;
P_0c0716f6: /* original 66e3, guest PC 0x0c0716f6 */
if(!s->budget--) { s->failed_pc=0x0c0716f6u; return 0; }
r[6]=r[14];
goto P_0c0716f8;
P_0c0716f8: /* original a004, guest PC 0x0c0716f8 */
if(!s->budget--) { s->failed_pc=0x0c0716f8u; return 0; }
goto P_0c071704;
P_0c0716fa: /* original 0009, guest PC 0x0c0716fa */
if(!s->budget--) { s->failed_pc=0x0c0716fau; return 0; }
return vf3_matrix_family(0x0c0716fcu,s,ram);
P_0c071704: /* original f059, guest PC 0x0c071704 */
if(!s->budget--) { s->failed_pc=0x0c071704u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071706;
P_0c071706: /* original f369, guest PC 0x0c071706 */
if(!s->budget--) { s->failed_pc=0x0c071706u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071708;
P_0c071708: /* original f159, guest PC 0x0c071708 */
if(!s->budget--) { s->failed_pc=0x0c071708u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07170a;
P_0c07170a: /* original f469, guest PC 0x0c07170a */
if(!s->budget--) { s->failed_pc=0x0c07170au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07170c;
P_0c07170c: /* original f031, guest PC 0x0c07170c */
if(!s->budget--) { s->failed_pc=0x0c07170cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07170e;
P_0c07170e: /* original f258, guest PC 0x0c07170e */
if(!s->budget--) { s->failed_pc=0x0c07170eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071710;
P_0c071710: /* original f568, guest PC 0x0c071710 */
if(!s->budget--) { s->failed_pc=0x0c071710u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071712;
P_0c071712: /* original f141, guest PC 0x0c071712 */
if(!s->budget--) { s->failed_pc=0x0c071712u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071714;
P_0c071714: /* original f251, guest PC 0x0c071714 */
if(!s->budget--) { s->failed_pc=0x0c071714u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071716;
P_0c071716: /* original 7408, guest PC 0x0c071716 */
if(!s->budget--) { s->failed_pc=0x0c071716u; return 0; }
r[4]+=0x00000008u;
goto P_0c071718;
P_0c071718: /* original f42a, guest PC 0x0c071718 */
if(!s->budget--) { s->failed_pc=0x0c071718u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07171a;
P_0c07171a: /* original f41b, guest PC 0x0c07171a */
if(!s->budget--) { s->failed_pc=0x0c07171au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07171c;
P_0c07171c: /* original f40b, guest PC 0x0c07171c */
if(!s->budget--) { s->failed_pc=0x0c07171cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07171e;
P_0c07171e: /* original 0009, guest PC 0x0c07171e */
if(!s->budget--) { s->failed_pc=0x0c07171eu; return 0; }
goto P_0c071720;
P_0c071720: /* original 64a3, guest PC 0x0c071720 */
if(!s->budget--) { s->failed_pc=0x0c071720u; return 0; }
r[4]=r[10];
goto P_0c071722;
P_0c071722: /* original 65b3, guest PC 0x0c071722 */
if(!s->budget--) { s->failed_pc=0x0c071722u; return 0; }
r[5]=r[11];
goto P_0c071724;
P_0c071724: /* original 66e3, guest PC 0x0c071724 */
if(!s->budget--) { s->failed_pc=0x0c071724u; return 0; }
r[6]=r[14];
goto P_0c071726;
P_0c071726: /* original f059, guest PC 0x0c071726 */
if(!s->budget--) { s->failed_pc=0x0c071726u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071728;
P_0c071728: /* original f369, guest PC 0x0c071728 */
if(!s->budget--) { s->failed_pc=0x0c071728u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07172a;
P_0c07172a: /* original f159, guest PC 0x0c07172a */
if(!s->budget--) { s->failed_pc=0x0c07172au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07172c;
P_0c07172c: /* original f469, guest PC 0x0c07172c */
if(!s->budget--) { s->failed_pc=0x0c07172cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07172e;
P_0c07172e: /* original f031, guest PC 0x0c07172e */
if(!s->budget--) { s->failed_pc=0x0c07172eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071730;
P_0c071730: /* original f258, guest PC 0x0c071730 */
if(!s->budget--) { s->failed_pc=0x0c071730u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071732;
P_0c071732: /* original f568, guest PC 0x0c071732 */
if(!s->budget--) { s->failed_pc=0x0c071732u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071734;
P_0c071734: /* original f141, guest PC 0x0c071734 */
if(!s->budget--) { s->failed_pc=0x0c071734u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071736;
P_0c071736: /* original f251, guest PC 0x0c071736 */
if(!s->budget--) { s->failed_pc=0x0c071736u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071738;
P_0c071738: /* original 7408, guest PC 0x0c071738 */
if(!s->budget--) { s->failed_pc=0x0c071738u; return 0; }
r[4]+=0x00000008u;
goto P_0c07173a;
P_0c07173a: /* original f42a, guest PC 0x0c07173a */
if(!s->budget--) { s->failed_pc=0x0c07173au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07173c;
P_0c07173c: /* original f41b, guest PC 0x0c07173c */
if(!s->budget--) { s->failed_pc=0x0c07173cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07173e;
P_0c07173e: /* original f40b, guest PC 0x0c07173e */
if(!s->budget--) { s->failed_pc=0x0c07173eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071740;
P_0c071740: /* original 65f2, guest PC 0x0c071740 */
if(!s->budget--) { s->failed_pc=0x0c071740u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071742;
P_0c071742: /* original 64c3, guest PC 0x0c071742 */
if(!s->budget--) { s->failed_pc=0x0c071742u; return 0; }
r[4]=r[12];
goto P_0c071744;
P_0c071744: /* original 66e3, guest PC 0x0c071744 */
if(!s->budget--) { s->failed_pc=0x0c071744u; return 0; }
r[6]=r[14];
goto P_0c071746;
P_0c071746: /* original f059, guest PC 0x0c071746 */
if(!s->budget--) { s->failed_pc=0x0c071746u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071748;
P_0c071748: /* original f369, guest PC 0x0c071748 */
if(!s->budget--) { s->failed_pc=0x0c071748u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07174a;
P_0c07174a: /* original f159, guest PC 0x0c07174a */
if(!s->budget--) { s->failed_pc=0x0c07174au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07174c;
P_0c07174c: /* original f469, guest PC 0x0c07174c */
if(!s->budget--) { s->failed_pc=0x0c07174cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07174e;
P_0c07174e: /* original f031, guest PC 0x0c07174e */
if(!s->budget--) { s->failed_pc=0x0c07174eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071750;
P_0c071750: /* original f258, guest PC 0x0c071750 */
if(!s->budget--) { s->failed_pc=0x0c071750u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071752;
P_0c071752: /* original f568, guest PC 0x0c071752 */
if(!s->budget--) { s->failed_pc=0x0c071752u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071754;
P_0c071754: /* original f141, guest PC 0x0c071754 */
if(!s->budget--) { s->failed_pc=0x0c071754u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071756;
P_0c071756: /* original f251, guest PC 0x0c071756 */
if(!s->budget--) { s->failed_pc=0x0c071756u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071758;
P_0c071758: /* original 7408, guest PC 0x0c071758 */
if(!s->budget--) { s->failed_pc=0x0c071758u; return 0; }
r[4]+=0x00000008u;
goto P_0c07175a;
P_0c07175a: /* original f42a, guest PC 0x0c07175a */
if(!s->budget--) { s->failed_pc=0x0c07175au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07175c;
P_0c07175c: /* original f41b, guest PC 0x0c07175c */
if(!s->budget--) { s->failed_pc=0x0c07175cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07175e;
P_0c07175e: /* original f40b, guest PC 0x0c07175e */
if(!s->budget--) { s->failed_pc=0x0c07175eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071760;
P_0c071760: /* original 66f3, guest PC 0x0c071760 */
if(!s->budget--) { s->failed_pc=0x0c071760u; return 0; }
r[6]=r[15];
goto P_0c071762;
P_0c071762: /* original 64c3, guest PC 0x0c071762 */
if(!s->budget--) { s->failed_pc=0x0c071762u; return 0; }
r[4]=r[12];
goto P_0c071764;
P_0c071764: /* original 65d3, guest PC 0x0c071764 */
if(!s->budget--) { s->failed_pc=0x0c071764u; return 0; }
r[5]=r[13];
goto P_0c071766;
P_0c071766: /* original 7624, guest PC 0x0c071766 */
if(!s->budget--) { s->failed_pc=0x0c071766u; return 0; }
r[6]+=0x00000024u;
goto P_0c071768;
P_0c071768: /* original f049, guest PC 0x0c071768 */
if(!s->budget--) { s->failed_pc=0x0c071768u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07176a;
P_0c07176a: /* original f549, guest PC 0x0c07176a */
if(!s->budget--) { s->failed_pc=0x0c07176au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07176c;
P_0c07176c: /* original f648, guest PC 0x0c07176c */
if(!s->budget--) { s->failed_pc=0x0c07176cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07176e;
P_0c07176e: /* original f859, guest PC 0x0c07176e */
if(!s->budget--) { s->failed_pc=0x0c07176eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071770;
P_0c071770: /* original f959, guest PC 0x0c071770 */
if(!s->budget--) { s->failed_pc=0x0c071770u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071772;
P_0c071772: /* original fa58, guest PC 0x0c071772 */
if(!s->budget--) { s->failed_pc=0x0c071772u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071774;
P_0c071774: /* original 760c, guest PC 0x0c071774 */
if(!s->budget--) { s->failed_pc=0x0c071774u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071776;
P_0c071776: /* original f35c, guest PC 0x0c071776 */
if(!s->budget--) { s->failed_pc=0x0c071776u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071778;
P_0c071778: /* original f382, guest PC 0x0c071778 */
if(!s->budget--) { s->failed_pc=0x0c071778u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07177a;
P_0c07177a: /* original f20c, guest PC 0x0c07177a */
if(!s->budget--) { s->failed_pc=0x0c07177au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07177c;
P_0c07177c: /* original f2a2, guest PC 0x0c07177c */
if(!s->budget--) { s->failed_pc=0x0c07177cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07177e;
P_0c07177e: /* original f16c, guest PC 0x0c07177e */
if(!s->budget--) { s->failed_pc=0x0c07177eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071780;
P_0c071780: /* original f192, guest PC 0x0c071780 */
if(!s->budget--) { s->failed_pc=0x0c071780u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071782;
P_0c071782: /* original f34d, guest PC 0x0c071782 */
if(!s->budget--) { s->failed_pc=0x0c071782u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071784;
P_0c071784: /* original f39e, guest PC 0x0c071784 */
if(!s->budget--) { s->failed_pc=0x0c071784u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071786;
P_0c071786: /* original f24d, guest PC 0x0c071786 */
if(!s->budget--) { s->failed_pc=0x0c071786u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071788;
P_0c071788: /* original f06c, guest PC 0x0c071788 */
if(!s->budget--) { s->failed_pc=0x0c071788u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07178a;
P_0c07178a: /* original f28e, guest PC 0x0c07178a */
if(!s->budget--) { s->failed_pc=0x0c07178au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07178c;
P_0c07178c: /* original f14d, guest PC 0x0c07178c */
if(!s->budget--) { s->failed_pc=0x0c07178cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c07178e;
P_0c07178e: /* original f63b, guest PC 0x0c07178e */
if(!s->budget--) { s->failed_pc=0x0c07178eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071790;
P_0c071790: /* original f05c, guest PC 0x0c071790 */
if(!s->budget--) { s->failed_pc=0x0c071790u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071792;
P_0c071792: /* original f1ae, guest PC 0x0c071792 */
if(!s->budget--) { s->failed_pc=0x0c071792u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071794;
P_0c071794: /* original f62b, guest PC 0x0c071794 */
if(!s->budget--) { s->failed_pc=0x0c071794u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071796;
P_0c071796: /* original f61b, guest PC 0x0c071796 */
if(!s->budget--) { s->failed_pc=0x0c071796u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071798;
P_0c071798: /* original 66f3, guest PC 0x0c071798 */
if(!s->budget--) { s->failed_pc=0x0c071798u; return 0; }
r[6]=r[15];
goto P_0c07179a;
P_0c07179a: /* original 64a3, guest PC 0x0c07179a */
if(!s->budget--) { s->failed_pc=0x0c07179au; return 0; }
r[4]=r[10];
goto P_0c07179c;
P_0c07179c: /* original 65c3, guest PC 0x0c07179c */
if(!s->budget--) { s->failed_pc=0x0c07179cu; return 0; }
r[5]=r[12];
goto P_0c07179e;
P_0c07179e: /* original 7618, guest PC 0x0c07179e */
if(!s->budget--) { s->failed_pc=0x0c07179eu; return 0; }
r[6]+=0x00000018u;
goto P_0c0717a0;
P_0c0717a0: /* original f049, guest PC 0x0c0717a0 */
if(!s->budget--) { s->failed_pc=0x0c0717a0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0717a2;
P_0c0717a2: /* original f549, guest PC 0x0c0717a2 */
if(!s->budget--) { s->failed_pc=0x0c0717a2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0717a4;
P_0c0717a4: /* original f648, guest PC 0x0c0717a4 */
if(!s->budget--) { s->failed_pc=0x0c0717a4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0717a6;
P_0c0717a6: /* original f859, guest PC 0x0c0717a6 */
if(!s->budget--) { s->failed_pc=0x0c0717a6u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0717a8;
P_0c0717a8: /* original f959, guest PC 0x0c0717a8 */
if(!s->budget--) { s->failed_pc=0x0c0717a8u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0717aa;
P_0c0717aa: /* original fa58, guest PC 0x0c0717aa */
if(!s->budget--) { s->failed_pc=0x0c0717aau; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0717ac;
P_0c0717ac: /* original 760c, guest PC 0x0c0717ac */
if(!s->budget--) { s->failed_pc=0x0c0717acu; return 0; }
r[6]+=0x0000000cu;
goto P_0c0717ae;
P_0c0717ae: /* original f35c, guest PC 0x0c0717ae */
if(!s->budget--) { s->failed_pc=0x0c0717aeu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0717b0;
P_0c0717b0: /* original f382, guest PC 0x0c0717b0 */
if(!s->budget--) { s->failed_pc=0x0c0717b0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0717b2;
P_0c0717b2: /* original f20c, guest PC 0x0c0717b2 */
if(!s->budget--) { s->failed_pc=0x0c0717b2u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0717b4;
P_0c0717b4: /* original f2a2, guest PC 0x0c0717b4 */
if(!s->budget--) { s->failed_pc=0x0c0717b4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0717b6;
P_0c0717b6: /* original f16c, guest PC 0x0c0717b6 */
if(!s->budget--) { s->failed_pc=0x0c0717b6u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0717b8;
P_0c0717b8: /* original f192, guest PC 0x0c0717b8 */
if(!s->budget--) { s->failed_pc=0x0c0717b8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0717ba;
P_0c0717ba: /* original f34d, guest PC 0x0c0717ba */
if(!s->budget--) { s->failed_pc=0x0c0717bau; return 0; }
fr[3]^=0x80000000u;
goto P_0c0717bc;
P_0c0717bc: /* original f39e, guest PC 0x0c0717bc */
if(!s->budget--) { s->failed_pc=0x0c0717bcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0717be;
P_0c0717be: /* original f24d, guest PC 0x0c0717be */
if(!s->budget--) { s->failed_pc=0x0c0717beu; return 0; }
fr[2]^=0x80000000u;
goto P_0c0717c0;
P_0c0717c0: /* original f06c, guest PC 0x0c0717c0 */
if(!s->budget--) { s->failed_pc=0x0c0717c0u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0717c2;
P_0c0717c2: /* original f28e, guest PC 0x0c0717c2 */
if(!s->budget--) { s->failed_pc=0x0c0717c2u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0717c4;
P_0c0717c4: /* original f14d, guest PC 0x0c0717c4 */
if(!s->budget--) { s->failed_pc=0x0c0717c4u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0717c6;
P_0c0717c6: /* original f63b, guest PC 0x0c0717c6 */
if(!s->budget--) { s->failed_pc=0x0c0717c6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0717c8;
P_0c0717c8: /* original f05c, guest PC 0x0c0717c8 */
if(!s->budget--) { s->failed_pc=0x0c0717c8u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0717ca;
P_0c0717ca: /* original f1ae, guest PC 0x0c0717ca */
if(!s->budget--) { s->failed_pc=0x0c0717cau; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0717cc;
P_0c0717cc: /* original f62b, guest PC 0x0c0717cc */
if(!s->budget--) { s->failed_pc=0x0c0717ccu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0717ce;
P_0c0717ce: /* original f61b, guest PC 0x0c0717ce */
if(!s->budget--) { s->failed_pc=0x0c0717ceu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0717d0;
P_0c0717d0: /* original 64f3, guest PC 0x0c0717d0 */
if(!s->budget--) { s->failed_pc=0x0c0717d0u; return 0; }
r[4]=r[15];
goto P_0c0717d2;
P_0c0717d2: /* original 7424, guest PC 0x0c0717d2 */
if(!s->budget--) { s->failed_pc=0x0c0717d2u; return 0; }
r[4]+=0x00000024u;
goto P_0c0717d4;
P_0c0717d4: /* original f049, guest PC 0x0c0717d4 */
if(!s->budget--) { s->failed_pc=0x0c0717d4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0717d6;
P_0c0717d6: /* original f149, guest PC 0x0c0717d6 */
if(!s->budget--) { s->failed_pc=0x0c0717d6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0717d8;
P_0c0717d8: /* original f249, guest PC 0x0c0717d8 */
if(!s->budget--) { s->failed_pc=0x0c0717d8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0717da;
P_0c0717da: /* original f38d, guest PC 0x0c0717da */
if(!s->budget--) { s->failed_pc=0x0c0717dau; return 0; }
fr[3]=0;
goto P_0c0717dc;
P_0c0717dc: /* original f0ed, guest PC 0x0c0717dc */
if(!s->budget--) { s->failed_pc=0x0c0717dcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0717de;
P_0c0717de: /* original f37d, guest PC 0x0c0717de */
if(!s->budget--) { s->failed_pc=0x0c0717deu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0717e0;
P_0c0717e0: /* original f232, guest PC 0x0c0717e0 */
if(!s->budget--) { s->failed_pc=0x0c0717e0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0717e2;
P_0c0717e2: /* original f132, guest PC 0x0c0717e2 */
if(!s->budget--) { s->failed_pc=0x0c0717e2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0717e4;
P_0c0717e4: /* original f032, guest PC 0x0c0717e4 */
if(!s->budget--) { s->failed_pc=0x0c0717e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0717e6;
P_0c0717e6: /* original f42b, guest PC 0x0c0717e6 */
if(!s->budget--) { s->failed_pc=0x0c0717e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0717e8;
P_0c0717e8: /* original f41b, guest PC 0x0c0717e8 */
if(!s->budget--) { s->failed_pc=0x0c0717e8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0717ea;
P_0c0717ea: /* original f40b, guest PC 0x0c0717ea */
if(!s->budget--) { s->failed_pc=0x0c0717eau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0717ec;
P_0c0717ec: /* original 64f3, guest PC 0x0c0717ec */
if(!s->budget--) { s->failed_pc=0x0c0717ecu; return 0; }
r[4]=r[15];
goto P_0c0717ee;
P_0c0717ee: /* original 7418, guest PC 0x0c0717ee */
if(!s->budget--) { s->failed_pc=0x0c0717eeu; return 0; }
r[4]+=0x00000018u;
goto P_0c0717f0;
P_0c0717f0: /* original f049, guest PC 0x0c0717f0 */
if(!s->budget--) { s->failed_pc=0x0c0717f0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0717f2;
P_0c0717f2: /* original f149, guest PC 0x0c0717f2 */
if(!s->budget--) { s->failed_pc=0x0c0717f2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0717f4;
P_0c0717f4: /* original f249, guest PC 0x0c0717f4 */
if(!s->budget--) { s->failed_pc=0x0c0717f4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0717f6;
P_0c0717f6: /* original f38d, guest PC 0x0c0717f6 */
if(!s->budget--) { s->failed_pc=0x0c0717f6u; return 0; }
fr[3]=0;
goto P_0c0717f8;
P_0c0717f8: /* original f0ed, guest PC 0x0c0717f8 */
if(!s->budget--) { s->failed_pc=0x0c0717f8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0717fa;
P_0c0717fa: /* original f37d, guest PC 0x0c0717fa */
if(!s->budget--) { s->failed_pc=0x0c0717fau; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0717fc;
P_0c0717fc: /* original f232, guest PC 0x0c0717fc */
if(!s->budget--) { s->failed_pc=0x0c0717fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0717fe;
P_0c0717fe: /* original f132, guest PC 0x0c0717fe */
if(!s->budget--) { s->failed_pc=0x0c0717feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071800;
P_0c071800: /* original f032, guest PC 0x0c071800 */
if(!s->budget--) { s->failed_pc=0x0c071800u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071802;
P_0c071802: /* original f42b, guest PC 0x0c071802 */
if(!s->budget--) { s->failed_pc=0x0c071802u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071804;
P_0c071804: /* original f41b, guest PC 0x0c071804 */
if(!s->budget--) { s->failed_pc=0x0c071804u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071806;
P_0c071806: /* original f40b, guest PC 0x0c071806 */
if(!s->budget--) { s->failed_pc=0x0c071806u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071808;
P_0c071808: /* original 65f3, guest PC 0x0c071808 */
if(!s->budget--) { s->failed_pc=0x0c071808u; return 0; }
r[5]=r[15];
goto P_0c07180a;
P_0c07180a: /* original 64e3, guest PC 0x0c07180a */
if(!s->budget--) { s->failed_pc=0x0c07180au; return 0; }
r[4]=r[14];
goto P_0c07180c;
P_0c07180c: /* original 66f3, guest PC 0x0c07180c */
if(!s->budget--) { s->failed_pc=0x0c07180cu; return 0; }
r[6]=r[15];
goto P_0c07180e;
P_0c07180e: /* original 740c, guest PC 0x0c07180e */
if(!s->budget--) { s->failed_pc=0x0c07180eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071810;
P_0c071810: /* original 7618, guest PC 0x0c071810 */
if(!s->budget--) { s->failed_pc=0x0c071810u; return 0; }
r[6]+=0x00000018u;
goto P_0c071812;
P_0c071812: /* original 7524, guest PC 0x0c071812 */
if(!s->budget--) { s->failed_pc=0x0c071812u; return 0; }
r[5]+=0x00000024u;
goto P_0c071814;
P_0c071814: /* original f059, guest PC 0x0c071814 */
if(!s->budget--) { s->failed_pc=0x0c071814u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071816;
P_0c071816: /* original f369, guest PC 0x0c071816 */
if(!s->budget--) { s->failed_pc=0x0c071816u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071818;
P_0c071818: /* original f159, guest PC 0x0c071818 */
if(!s->budget--) { s->failed_pc=0x0c071818u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07181a;
P_0c07181a: /* original f469, guest PC 0x0c07181a */
if(!s->budget--) { s->failed_pc=0x0c07181au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07181c;
P_0c07181c: /* original f259, guest PC 0x0c07181c */
if(!s->budget--) { s->failed_pc=0x0c07181cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07181e;
P_0c07181e: /* original f569, guest PC 0x0c07181e */
if(!s->budget--) { s->failed_pc=0x0c07181eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071820;
P_0c071820: /* original 740c, guest PC 0x0c071820 */
if(!s->budget--) { s->failed_pc=0x0c071820u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071822;
P_0c071822: /* original f030, guest PC 0x0c071822 */
if(!s->budget--) { s->failed_pc=0x0c071822u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071824;
P_0c071824: /* original f250, guest PC 0x0c071824 */
if(!s->budget--) { s->failed_pc=0x0c071824u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071826;
P_0c071826: /* original f140, guest PC 0x0c071826 */
if(!s->budget--) { s->failed_pc=0x0c071826u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071828;
P_0c071828: /* original f42b, guest PC 0x0c071828 */
if(!s->budget--) { s->failed_pc=0x0c071828u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07182a;
P_0c07182a: /* original f41b, guest PC 0x0c07182a */
if(!s->budget--) { s->failed_pc=0x0c07182au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07182c;
P_0c07182c: /* original f40b, guest PC 0x0c07182c */
if(!s->budget--) { s->failed_pc=0x0c07182cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07182e;
P_0c07182e: /* original 0009, guest PC 0x0c07182e */
if(!s->budget--) { s->failed_pc=0x0c07182eu; return 0; }
goto P_0c071830;
P_0c071830: /* original 64e3, guest PC 0x0c071830 */
if(!s->budget--) { s->failed_pc=0x0c071830u; return 0; }
r[4]=r[14];
goto P_0c071832;
P_0c071832: /* original 740c, guest PC 0x0c071832 */
if(!s->budget--) { s->failed_pc=0x0c071832u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071834;
P_0c071834: /* original f049, guest PC 0x0c071834 */
if(!s->budget--) { s->failed_pc=0x0c071834u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071836;
P_0c071836: /* original f149, guest PC 0x0c071836 */
if(!s->budget--) { s->failed_pc=0x0c071836u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071838;
P_0c071838: /* original f249, guest PC 0x0c071838 */
if(!s->budget--) { s->failed_pc=0x0c071838u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07183a;
P_0c07183a: /* original f38d, guest PC 0x0c07183a */
if(!s->budget--) { s->failed_pc=0x0c07183au; return 0; }
fr[3]=0;
goto P_0c07183c;
P_0c07183c: /* original f0ed, guest PC 0x0c07183c */
if(!s->budget--) { s->failed_pc=0x0c07183cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07183e;
P_0c07183e: /* original f37d, guest PC 0x0c07183e */
if(!s->budget--) { s->failed_pc=0x0c07183eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071840;
P_0c071840: /* original f232, guest PC 0x0c071840 */
if(!s->budget--) { s->failed_pc=0x0c071840u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071842;
P_0c071842: /* original f132, guest PC 0x0c071842 */
if(!s->budget--) { s->failed_pc=0x0c071842u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071844;
P_0c071844: /* original f032, guest PC 0x0c071844 */
if(!s->budget--) { s->failed_pc=0x0c071844u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071846;
P_0c071846: /* original f42b, guest PC 0x0c071846 */
if(!s->budget--) { s->failed_pc=0x0c071846u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071848;
P_0c071848: /* original f41b, guest PC 0x0c071848 */
if(!s->budget--) { s->failed_pc=0x0c071848u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07184a;
P_0c07184a: /* original f40b, guest PC 0x0c07184a */
if(!s->budget--) { s->failed_pc=0x0c07184au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07184c;
P_0c07184c: /* original 1fe1, guest PC 0x0c07184c */
if(!s->budget--) { s->failed_pc=0x0c07184cu; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c07184e;
P_0c07184e: /* original 6eb3, guest PC 0x0c07184e */
if(!s->budget--) { s->failed_pc=0x0c07184eu; return 0; }
r[14]=r[11];
goto P_0c071850;
P_0c071850: /* original 63f2, guest PC 0x0c071850 */
if(!s->budget--) { s->failed_pc=0x0c071850u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071852;
P_0c071852: /* original 7b18, guest PC 0x0c071852 */
if(!s->budget--) { s->failed_pc=0x0c071852u; return 0; }
r[11]+=0x00000018u;
goto P_0c071854;
P_0c071854: /* original 7318, guest PC 0x0c071854 */
if(!s->budget--) { s->failed_pc=0x0c071854u; return 0; }
r[3]+=0x00000018u;
goto P_0c071856;
P_0c071856: /* original 2f32, guest PC 0x0c071856 */
if(!s->budget--) { s->failed_pc=0x0c071856u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c071858;
P_0c071858: /* original 52f2, guest PC 0x0c071858 */
if(!s->budget--) { s->failed_pc=0x0c071858u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07185a;
P_0c07185a: /* original 72ff, guest PC 0x0c07185a */
if(!s->budget--) { s->failed_pc=0x0c07185au; return 0; }
r[2]+=0xffffffffu;
goto P_0c07185c;
P_0c07185c: /* original 3297, guest PC 0x0c07185c */
if(!s->budget--) { s->failed_pc=0x0c07185cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[9])!=0);
goto P_0c07185e;
P_0c07185e: /* original 8f03, guest PC 0x0c07185e */
if(!s->budget--) { s->failed_pc=0x0c07185eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(!cond) { goto P_0c071868; }
goto P_0c071862;
P_0c071860: /* original 1f22, guest PC 0x0c071860 */
if(!s->budget--) { s->failed_pc=0x0c071860u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c071862;
P_0c071862: /* original d104, guest PC 0x0c071862 */
if(!s->budget--) { s->failed_pc=0x0c071862u; return 0; }
r[1]=read(ram,0x0c071874u,4);
goto P_0c071864;
P_0c071864: /* original 412b, guest PC 0x0c071864 */
if(!s->budget--) { s->failed_pc=0x0c071864u; return 0; }
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
P_0c071866: /* original 0009, guest PC 0x0c071866 */
if(!s->budget--) { s->failed_pc=0x0c071866u; return 0; }
goto P_0c071868;
P_0c071868: /* original 55f1, guest PC 0x0c071868 */
if(!s->budget--) { s->failed_pc=0x0c071868u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07186a;
P_0c07186a: /* original 64d3, guest PC 0x0c07186a */
if(!s->budget--) { s->failed_pc=0x0c07186au; return 0; }
r[4]=r[13];
goto P_0c07186c;
P_0c07186c: /* original 66e3, guest PC 0x0c07186c */
if(!s->budget--) { s->failed_pc=0x0c07186cu; return 0; }
r[6]=r[14];
goto P_0c07186e;
P_0c07186e: /* original a003, guest PC 0x0c07186e */
if(!s->budget--) { s->failed_pc=0x0c07186eu; return 0; }
goto P_0c071878;
P_0c071870: /* original 0009, guest PC 0x0c071870 */
if(!s->budget--) { s->failed_pc=0x0c071870u; return 0; }
return vf3_matrix_family(0x0c071872u,s,ram);
P_0c071878: /* original f059, guest PC 0x0c071878 */
if(!s->budget--) { s->failed_pc=0x0c071878u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07187a;
P_0c07187a: /* original f369, guest PC 0x0c07187a */
if(!s->budget--) { s->failed_pc=0x0c07187au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07187c;
P_0c07187c: /* original f159, guest PC 0x0c07187c */
if(!s->budget--) { s->failed_pc=0x0c07187cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07187e;
P_0c07187e: /* original f469, guest PC 0x0c07187e */
if(!s->budget--) { s->failed_pc=0x0c07187eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071880;
P_0c071880: /* original f031, guest PC 0x0c071880 */
if(!s->budget--) { s->failed_pc=0x0c071880u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071882;
P_0c071882: /* original f258, guest PC 0x0c071882 */
if(!s->budget--) { s->failed_pc=0x0c071882u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071884;
P_0c071884: /* original f568, guest PC 0x0c071884 */
if(!s->budget--) { s->failed_pc=0x0c071884u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071886;
P_0c071886: /* original f141, guest PC 0x0c071886 */
if(!s->budget--) { s->failed_pc=0x0c071886u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071888;
P_0c071888: /* original f251, guest PC 0x0c071888 */
if(!s->budget--) { s->failed_pc=0x0c071888u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07188a;
P_0c07188a: /* original 7408, guest PC 0x0c07188a */
if(!s->budget--) { s->failed_pc=0x0c07188au; return 0; }
r[4]+=0x00000008u;
goto P_0c07188c;
P_0c07188c: /* original f42a, guest PC 0x0c07188c */
if(!s->budget--) { s->failed_pc=0x0c07188cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07188e;
P_0c07188e: /* original f41b, guest PC 0x0c07188e */
if(!s->budget--) { s->failed_pc=0x0c07188eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071890;
P_0c071890: /* original f40b, guest PC 0x0c071890 */
if(!s->budget--) { s->failed_pc=0x0c071890u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071892;
P_0c071892: /* original 0009, guest PC 0x0c071892 */
if(!s->budget--) { s->failed_pc=0x0c071892u; return 0; }
goto P_0c071894;
P_0c071894: /* original 65f2, guest PC 0x0c071894 */
if(!s->budget--) { s->failed_pc=0x0c071894u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071896;
P_0c071896: /* original 64a3, guest PC 0x0c071896 */
if(!s->budget--) { s->failed_pc=0x0c071896u; return 0; }
r[4]=r[10];
goto P_0c071898;
P_0c071898: /* original 66e3, guest PC 0x0c071898 */
if(!s->budget--) { s->failed_pc=0x0c071898u; return 0; }
r[6]=r[14];
goto P_0c07189a;
P_0c07189a: /* original f059, guest PC 0x0c07189a */
if(!s->budget--) { s->failed_pc=0x0c07189au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07189c;
P_0c07189c: /* original f369, guest PC 0x0c07189c */
if(!s->budget--) { s->failed_pc=0x0c07189cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07189e;
P_0c07189e: /* original f159, guest PC 0x0c07189e */
if(!s->budget--) { s->failed_pc=0x0c07189eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718a0;
P_0c0718a0: /* original f469, guest PC 0x0c0718a0 */
if(!s->budget--) { s->failed_pc=0x0c0718a0u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0718a2;
P_0c0718a2: /* original f031, guest PC 0x0c0718a2 */
if(!s->budget--) { s->failed_pc=0x0c0718a2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0718a4;
P_0c0718a4: /* original f258, guest PC 0x0c0718a4 */
if(!s->budget--) { s->failed_pc=0x0c0718a4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0718a6;
P_0c0718a6: /* original f568, guest PC 0x0c0718a6 */
if(!s->budget--) { s->failed_pc=0x0c0718a6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0718a8;
P_0c0718a8: /* original f141, guest PC 0x0c0718a8 */
if(!s->budget--) { s->failed_pc=0x0c0718a8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0718aa;
P_0c0718aa: /* original f251, guest PC 0x0c0718aa */
if(!s->budget--) { s->failed_pc=0x0c0718aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0718ac;
P_0c0718ac: /* original 7408, guest PC 0x0c0718ac */
if(!s->budget--) { s->failed_pc=0x0c0718acu; return 0; }
r[4]+=0x00000008u;
goto P_0c0718ae;
P_0c0718ae: /* original f42a, guest PC 0x0c0718ae */
if(!s->budget--) { s->failed_pc=0x0c0718aeu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0718b0;
P_0c0718b0: /* original f41b, guest PC 0x0c0718b0 */
if(!s->budget--) { s->failed_pc=0x0c0718b0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0718b2;
P_0c0718b2: /* original f40b, guest PC 0x0c0718b2 */
if(!s->budget--) { s->failed_pc=0x0c0718b2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0718b4;
P_0c0718b4: /* original 66e3, guest PC 0x0c0718b4 */
if(!s->budget--) { s->failed_pc=0x0c0718b4u; return 0; }
r[6]=r[14];
goto P_0c0718b6;
P_0c0718b6: /* original 64a3, guest PC 0x0c0718b6 */
if(!s->budget--) { s->failed_pc=0x0c0718b6u; return 0; }
r[4]=r[10];
goto P_0c0718b8;
P_0c0718b8: /* original 65d3, guest PC 0x0c0718b8 */
if(!s->budget--) { s->failed_pc=0x0c0718b8u; return 0; }
r[5]=r[13];
goto P_0c0718ba;
P_0c0718ba: /* original 760c, guest PC 0x0c0718ba */
if(!s->budget--) { s->failed_pc=0x0c0718bau; return 0; }
r[6]+=0x0000000cu;
goto P_0c0718bc;
P_0c0718bc: /* original f049, guest PC 0x0c0718bc */
if(!s->budget--) { s->failed_pc=0x0c0718bcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718be;
P_0c0718be: /* original f549, guest PC 0x0c0718be */
if(!s->budget--) { s->failed_pc=0x0c0718beu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c0;
P_0c0718c0: /* original f648, guest PC 0x0c0718c0 */
if(!s->budget--) { s->failed_pc=0x0c0718c0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0718c2;
P_0c0718c2: /* original f859, guest PC 0x0c0718c2 */
if(!s->budget--) { s->failed_pc=0x0c0718c2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c4;
P_0c0718c4: /* original f959, guest PC 0x0c0718c4 */
if(!s->budget--) { s->failed_pc=0x0c0718c4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c6;
P_0c0718c6: /* original fa58, guest PC 0x0c0718c6 */
if(!s->budget--) { s->failed_pc=0x0c0718c6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0718c8;
P_0c0718c8: /* original 760c, guest PC 0x0c0718c8 */
if(!s->budget--) { s->failed_pc=0x0c0718c8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0718ca;
P_0c0718ca: /* original f35c, guest PC 0x0c0718ca */
if(!s->budget--) { s->failed_pc=0x0c0718cau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0718cc;
P_0c0718cc: /* original f382, guest PC 0x0c0718cc */
if(!s->budget--) { s->failed_pc=0x0c0718ccu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0718ce;
P_0c0718ce: /* original f20c, guest PC 0x0c0718ce */
if(!s->budget--) { s->failed_pc=0x0c0718ceu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0718d0;
P_0c0718d0: /* original f2a2, guest PC 0x0c0718d0 */
if(!s->budget--) { s->failed_pc=0x0c0718d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0718d2;
P_0c0718d2: /* original f16c, guest PC 0x0c0718d2 */
if(!s->budget--) { s->failed_pc=0x0c0718d2u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0718d4;
P_0c0718d4: /* original f192, guest PC 0x0c0718d4 */
if(!s->budget--) { s->failed_pc=0x0c0718d4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0718d6;
P_0c0718d6: /* original f34d, guest PC 0x0c0718d6 */
if(!s->budget--) { s->failed_pc=0x0c0718d6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0718d8;
P_0c0718d8: /* original f39e, guest PC 0x0c0718d8 */
if(!s->budget--) { s->failed_pc=0x0c0718d8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0718da;
P_0c0718da: /* original f24d, guest PC 0x0c0718da */
if(!s->budget--) { s->failed_pc=0x0c0718dau; return 0; }
fr[2]^=0x80000000u;
goto P_0c0718dc;
P_0c0718dc: /* original f06c, guest PC 0x0c0718dc */
if(!s->budget--) { s->failed_pc=0x0c0718dcu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0718de;
P_0c0718de: /* original f28e, guest PC 0x0c0718de */
if(!s->budget--) { s->failed_pc=0x0c0718deu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0718e0;
P_0c0718e0: /* original f14d, guest PC 0x0c0718e0 */
if(!s->budget--) { s->failed_pc=0x0c0718e0u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0718e2;
P_0c0718e2: /* original f63b, guest PC 0x0c0718e2 */
if(!s->budget--) { s->failed_pc=0x0c0718e2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0718e4;
P_0c0718e4: /* original f05c, guest PC 0x0c0718e4 */
if(!s->budget--) { s->failed_pc=0x0c0718e4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0718e6;
P_0c0718e6: /* original f1ae, guest PC 0x0c0718e6 */
if(!s->budget--) { s->failed_pc=0x0c0718e6u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0718e8;
P_0c0718e8: /* original f62b, guest PC 0x0c0718e8 */
if(!s->budget--) { s->failed_pc=0x0c0718e8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0718ea;
P_0c0718ea: /* original f61b, guest PC 0x0c0718ea */
if(!s->budget--) { s->failed_pc=0x0c0718eau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0718ec;
P_0c0718ec: /* original 64e3, guest PC 0x0c0718ec */
if(!s->budget--) { s->failed_pc=0x0c0718ecu; return 0; }
r[4]=r[14];
goto P_0c0718ee;
P_0c0718ee: /* original 740c, guest PC 0x0c0718ee */
if(!s->budget--) { s->failed_pc=0x0c0718eeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0718f0;
P_0c0718f0: /* original f049, guest PC 0x0c0718f0 */
if(!s->budget--) { s->failed_pc=0x0c0718f0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f2;
P_0c0718f2: /* original f149, guest PC 0x0c0718f2 */
if(!s->budget--) { s->failed_pc=0x0c0718f2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f4;
P_0c0718f4: /* original f249, guest PC 0x0c0718f4 */
if(!s->budget--) { s->failed_pc=0x0c0718f4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f6;
P_0c0718f6: /* original f38d, guest PC 0x0c0718f6 */
if(!s->budget--) { s->failed_pc=0x0c0718f6u; return 0; }
fr[3]=0;
goto P_0c0718f8;
P_0c0718f8: /* original f0ed, guest PC 0x0c0718f8 */
if(!s->budget--) { s->failed_pc=0x0c0718f8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0718fa;
P_0c0718fa: /* original f37d, guest PC 0x0c0718fa */
if(!s->budget--) { s->failed_pc=0x0c0718fau; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0718fc;
P_0c0718fc: /* original f232, guest PC 0x0c0718fc */
if(!s->budget--) { s->failed_pc=0x0c0718fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0718fe;
P_0c0718fe: /* original f132, guest PC 0x0c0718fe */
if(!s->budget--) { s->failed_pc=0x0c0718feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071900;
P_0c071900: /* original f032, guest PC 0x0c071900 */
if(!s->budget--) { s->failed_pc=0x0c071900u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071902;
P_0c071902: /* original f42b, guest PC 0x0c071902 */
if(!s->budget--) { s->failed_pc=0x0c071902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071904;
P_0c071904: /* original f41b, guest PC 0x0c071904 */
if(!s->budget--) { s->failed_pc=0x0c071904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071906;
P_0c071906: /* original f40b, guest PC 0x0c071906 */
if(!s->budget--) { s->failed_pc=0x0c071906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071908;
P_0c071908: /* original 61f3, guest PC 0x0c071908 */
if(!s->budget--) { s->failed_pc=0x0c071908u; return 0; }
r[1]=r[15];
goto P_0c07190a;
P_0c07190a: /* original 7154, guest PC 0x0c07190a */
if(!s->budget--) { s->failed_pc=0x0c07190au; return 0; }
r[1]+=0x00000054u;
goto P_0c07190c;
P_0c07190c: /* original 62f2, guest PC 0x0c07190c */
if(!s->budget--) { s->failed_pc=0x0c07190cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07190e;
P_0c07190e: /* original 6eb3, guest PC 0x0c07190e */
if(!s->budget--) { s->failed_pc=0x0c07190eu; return 0; }
r[14]=r[11];
goto P_0c071910;
P_0c071910: /* original 7218, guest PC 0x0c071910 */
if(!s->budget--) { s->failed_pc=0x0c071910u; return 0; }
r[2]+=0x00000018u;
goto P_0c071912;
P_0c071912: /* original 2f22, guest PC 0x0c071912 */
if(!s->budget--) { s->failed_pc=0x0c071912u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c071914;
P_0c071914: /* original 53f3, guest PC 0x0c071914 */
if(!s->budget--) { s->failed_pc=0x0c071914u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c071916;
P_0c071916: /* original 73ff, guest PC 0x0c071916 */
if(!s->budget--) { s->failed_pc=0x0c071916u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071918;
P_0c071918: /* original 1f34, guest PC 0x0c071918 */
if(!s->budget--) { s->failed_pc=0x0c071918u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07191a;
P_0c07191a: /* original 1f13, guest PC 0x0c07191a */
if(!s->budget--) { s->failed_pc=0x0c07191au; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07191c;
P_0c07191c: /* original d103, guest PC 0x0c07191c */
if(!s->budget--) { s->failed_pc=0x0c07191cu; return 0; }
r[1]=read(ram,0x0c07192cu,4);
goto P_0c07191e;
P_0c07191e: /* original 412b, guest PC 0x0c07191e */
if(!s->budget--) { s->failed_pc=0x0c07191eu; return 0; }
target=r[1];
r[11]+=0x00000018u;
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
P_0c071920: /* original 7b18, guest PC 0x0c071920 */
if(!s->budget--) { s->failed_pc=0x0c071920u; return 0; }
r[11]+=0x00000018u;
goto P_0c071922;
P_0c071922: /* original 64d3, guest PC 0x0c071922 */
if(!s->budget--) { s->failed_pc=0x0c071922u; return 0; }
r[4]=r[13];
goto P_0c071924;
P_0c071924: /* original 65b3, guest PC 0x0c071924 */
if(!s->budget--) { s->failed_pc=0x0c071924u; return 0; }
r[5]=r[11];
goto P_0c071926;
P_0c071926: /* original 66e3, guest PC 0x0c071926 */
if(!s->budget--) { s->failed_pc=0x0c071926u; return 0; }
r[6]=r[14];
goto P_0c071928;
P_0c071928: /* original a002, guest PC 0x0c071928 */
if(!s->budget--) { s->failed_pc=0x0c071928u; return 0; }
goto P_0c071930;
P_0c07192a: /* original 0009, guest PC 0x0c07192a */
if(!s->budget--) { s->failed_pc=0x0c07192au; return 0; }
return vf3_matrix_family(0x0c07192cu,s,ram);
P_0c071930: /* original f059, guest PC 0x0c071930 */
if(!s->budget--) { s->failed_pc=0x0c071930u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071932;
P_0c071932: /* original f369, guest PC 0x0c071932 */
if(!s->budget--) { s->failed_pc=0x0c071932u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071934;
P_0c071934: /* original f159, guest PC 0x0c071934 */
if(!s->budget--) { s->failed_pc=0x0c071934u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071936;
P_0c071936: /* original f469, guest PC 0x0c071936 */
if(!s->budget--) { s->failed_pc=0x0c071936u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071938;
P_0c071938: /* original f031, guest PC 0x0c071938 */
if(!s->budget--) { s->failed_pc=0x0c071938u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07193a;
P_0c07193a: /* original f258, guest PC 0x0c07193a */
if(!s->budget--) { s->failed_pc=0x0c07193au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c07193c;
P_0c07193c: /* original f568, guest PC 0x0c07193c */
if(!s->budget--) { s->failed_pc=0x0c07193cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c07193e;
P_0c07193e: /* original f141, guest PC 0x0c07193e */
if(!s->budget--) { s->failed_pc=0x0c07193eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071940;
P_0c071940: /* original f251, guest PC 0x0c071940 */
if(!s->budget--) { s->failed_pc=0x0c071940u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071942;
P_0c071942: /* original 7408, guest PC 0x0c071942 */
if(!s->budget--) { s->failed_pc=0x0c071942u; return 0; }
r[4]+=0x00000008u;
goto P_0c071944;
P_0c071944: /* original f42a, guest PC 0x0c071944 */
if(!s->budget--) { s->failed_pc=0x0c071944u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071946;
P_0c071946: /* original f41b, guest PC 0x0c071946 */
if(!s->budget--) { s->failed_pc=0x0c071946u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071948;
P_0c071948: /* original f40b, guest PC 0x0c071948 */
if(!s->budget--) { s->failed_pc=0x0c071948u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07194a;
P_0c07194a: /* original 0009, guest PC 0x0c07194a */
if(!s->budget--) { s->failed_pc=0x0c07194au; return 0; }
goto P_0c07194c;
P_0c07194c: /* original 65f2, guest PC 0x0c07194c */
if(!s->budget--) { s->failed_pc=0x0c07194cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c07194e;
P_0c07194e: /* original 64a3, guest PC 0x0c07194e */
if(!s->budget--) { s->failed_pc=0x0c07194eu; return 0; }
r[4]=r[10];
goto P_0c071950;
P_0c071950: /* original 66e3, guest PC 0x0c071950 */
if(!s->budget--) { s->failed_pc=0x0c071950u; return 0; }
r[6]=r[14];
goto P_0c071952;
P_0c071952: /* original f059, guest PC 0x0c071952 */
if(!s->budget--) { s->failed_pc=0x0c071952u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071954;
P_0c071954: /* original f369, guest PC 0x0c071954 */
if(!s->budget--) { s->failed_pc=0x0c071954u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071956;
P_0c071956: /* original f159, guest PC 0x0c071956 */
if(!s->budget--) { s->failed_pc=0x0c071956u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071958;
P_0c071958: /* original f469, guest PC 0x0c071958 */
if(!s->budget--) { s->failed_pc=0x0c071958u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07195a;
P_0c07195a: /* original f031, guest PC 0x0c07195a */
if(!s->budget--) { s->failed_pc=0x0c07195au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07195c;
P_0c07195c: /* original f258, guest PC 0x0c07195c */
if(!s->budget--) { s->failed_pc=0x0c07195cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c07195e;
P_0c07195e: /* original f568, guest PC 0x0c07195e */
if(!s->budget--) { s->failed_pc=0x0c07195eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071960;
P_0c071960: /* original f141, guest PC 0x0c071960 */
if(!s->budget--) { s->failed_pc=0x0c071960u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071962;
P_0c071962: /* original f251, guest PC 0x0c071962 */
if(!s->budget--) { s->failed_pc=0x0c071962u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071964;
P_0c071964: /* original 7408, guest PC 0x0c071964 */
if(!s->budget--) { s->failed_pc=0x0c071964u; return 0; }
r[4]+=0x00000008u;
goto P_0c071966;
P_0c071966: /* original f42a, guest PC 0x0c071966 */
if(!s->budget--) { s->failed_pc=0x0c071966u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071968;
P_0c071968: /* original f41b, guest PC 0x0c071968 */
if(!s->budget--) { s->failed_pc=0x0c071968u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07196a;
P_0c07196a: /* original f40b, guest PC 0x0c07196a */
if(!s->budget--) { s->failed_pc=0x0c07196au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07196c;
P_0c07196c: /* original 64c3, guest PC 0x0c07196c */
if(!s->budget--) { s->failed_pc=0x0c07196cu; return 0; }
r[4]=r[12];
goto P_0c07196e;
P_0c07196e: /* original 6583, guest PC 0x0c07196e */
if(!s->budget--) { s->failed_pc=0x0c07196eu; return 0; }
r[5]=r[8];
goto P_0c071970;
P_0c071970: /* original 66e3, guest PC 0x0c071970 */
if(!s->budget--) { s->failed_pc=0x0c071970u; return 0; }
r[6]=r[14];
goto P_0c071972;
P_0c071972: /* original f059, guest PC 0x0c071972 */
if(!s->budget--) { s->failed_pc=0x0c071972u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071974;
P_0c071974: /* original f369, guest PC 0x0c071974 */
if(!s->budget--) { s->failed_pc=0x0c071974u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071976;
P_0c071976: /* original f159, guest PC 0x0c071976 */
if(!s->budget--) { s->failed_pc=0x0c071976u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071978;
P_0c071978: /* original f469, guest PC 0x0c071978 */
if(!s->budget--) { s->failed_pc=0x0c071978u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07197a;
P_0c07197a: /* original f031, guest PC 0x0c07197a */
if(!s->budget--) { s->failed_pc=0x0c07197au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07197c;
P_0c07197c: /* original f258, guest PC 0x0c07197c */
if(!s->budget--) { s->failed_pc=0x0c07197cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c07197e;
P_0c07197e: /* original f568, guest PC 0x0c07197e */
if(!s->budget--) { s->failed_pc=0x0c07197eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071980;
P_0c071980: /* original f141, guest PC 0x0c071980 */
if(!s->budget--) { s->failed_pc=0x0c071980u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071982;
P_0c071982: /* original f251, guest PC 0x0c071982 */
if(!s->budget--) { s->failed_pc=0x0c071982u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071984;
P_0c071984: /* original 7408, guest PC 0x0c071984 */
if(!s->budget--) { s->failed_pc=0x0c071984u; return 0; }
r[4]+=0x00000008u;
goto P_0c071986;
P_0c071986: /* original f42a, guest PC 0x0c071986 */
if(!s->budget--) { s->failed_pc=0x0c071986u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071988;
P_0c071988: /* original f41b, guest PC 0x0c071988 */
if(!s->budget--) { s->failed_pc=0x0c071988u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07198a;
P_0c07198a: /* original f40b, guest PC 0x0c07198a */
if(!s->budget--) { s->failed_pc=0x0c07198au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07198c;
P_0c07198c: /* original 66f3, guest PC 0x0c07198c */
if(!s->budget--) { s->failed_pc=0x0c07198cu; return 0; }
r[6]=r[15];
goto P_0c07198e;
P_0c07198e: /* original 64d3, guest PC 0x0c07198e */
if(!s->budget--) { s->failed_pc=0x0c07198eu; return 0; }
r[4]=r[13];
goto P_0c071990;
P_0c071990: /* original 65a3, guest PC 0x0c071990 */
if(!s->budget--) { s->failed_pc=0x0c071990u; return 0; }
r[5]=r[10];
goto P_0c071992;
P_0c071992: /* original 7624, guest PC 0x0c071992 */
if(!s->budget--) { s->failed_pc=0x0c071992u; return 0; }
r[6]+=0x00000024u;
goto P_0c071994;
P_0c071994: /* original f049, guest PC 0x0c071994 */
if(!s->budget--) { s->failed_pc=0x0c071994u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071996;
P_0c071996: /* original f549, guest PC 0x0c071996 */
if(!s->budget--) { s->failed_pc=0x0c071996u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071998;
P_0c071998: /* original f648, guest PC 0x0c071998 */
if(!s->budget--) { s->failed_pc=0x0c071998u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07199a;
P_0c07199a: /* original f859, guest PC 0x0c07199a */
if(!s->budget--) { s->failed_pc=0x0c07199au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07199c;
P_0c07199c: /* original f959, guest PC 0x0c07199c */
if(!s->budget--) { s->failed_pc=0x0c07199cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07199e;
P_0c07199e: /* original fa58, guest PC 0x0c07199e */
if(!s->budget--) { s->failed_pc=0x0c07199eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0719a0;
P_0c0719a0: /* original 760c, guest PC 0x0c0719a0 */
if(!s->budget--) { s->failed_pc=0x0c0719a0u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0719a2;
P_0c0719a2: /* original f35c, guest PC 0x0c0719a2 */
if(!s->budget--) { s->failed_pc=0x0c0719a2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0719a4;
P_0c0719a4: /* original f382, guest PC 0x0c0719a4 */
if(!s->budget--) { s->failed_pc=0x0c0719a4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0719a6;
P_0c0719a6: /* original f20c, guest PC 0x0c0719a6 */
if(!s->budget--) { s->failed_pc=0x0c0719a6u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0719a8;
P_0c0719a8: /* original f2a2, guest PC 0x0c0719a8 */
if(!s->budget--) { s->failed_pc=0x0c0719a8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0719aa;
P_0c0719aa: /* original f16c, guest PC 0x0c0719aa */
if(!s->budget--) { s->failed_pc=0x0c0719aau; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0719ac;
P_0c0719ac: /* original f192, guest PC 0x0c0719ac */
if(!s->budget--) { s->failed_pc=0x0c0719acu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0719ae;
P_0c0719ae: /* original f34d, guest PC 0x0c0719ae */
if(!s->budget--) { s->failed_pc=0x0c0719aeu; return 0; }
fr[3]^=0x80000000u;
goto P_0c0719b0;
P_0c0719b0: /* original f39e, guest PC 0x0c0719b0 */
if(!s->budget--) { s->failed_pc=0x0c0719b0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0719b2;
P_0c0719b2: /* original f24d, guest PC 0x0c0719b2 */
if(!s->budget--) { s->failed_pc=0x0c0719b2u; return 0; }
fr[2]^=0x80000000u;
goto P_0c0719b4;
P_0c0719b4: /* original f06c, guest PC 0x0c0719b4 */
if(!s->budget--) { s->failed_pc=0x0c0719b4u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0719b6;
P_0c0719b6: /* original f28e, guest PC 0x0c0719b6 */
if(!s->budget--) { s->failed_pc=0x0c0719b6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0719b8;
P_0c0719b8: /* original f14d, guest PC 0x0c0719b8 */
if(!s->budget--) { s->failed_pc=0x0c0719b8u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0719ba;
P_0c0719ba: /* original f63b, guest PC 0x0c0719ba */
if(!s->budget--) { s->failed_pc=0x0c0719bau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0719bc;
P_0c0719bc: /* original f05c, guest PC 0x0c0719bc */
if(!s->budget--) { s->failed_pc=0x0c0719bcu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0719be;
P_0c0719be: /* original f1ae, guest PC 0x0c0719be */
if(!s->budget--) { s->failed_pc=0x0c0719beu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0719c0;
P_0c0719c0: /* original f62b, guest PC 0x0c0719c0 */
if(!s->budget--) { s->failed_pc=0x0c0719c0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0719c2;
P_0c0719c2: /* original f61b, guest PC 0x0c0719c2 */
if(!s->budget--) { s->failed_pc=0x0c0719c2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0719c4;
P_0c0719c4: /* original 66f3, guest PC 0x0c0719c4 */
if(!s->budget--) { s->failed_pc=0x0c0719c4u; return 0; }
r[6]=r[15];
goto P_0c0719c6;
P_0c0719c6: /* original 64c3, guest PC 0x0c0719c6 */
if(!s->budget--) { s->failed_pc=0x0c0719c6u; return 0; }
r[4]=r[12];
goto P_0c0719c8;
P_0c0719c8: /* original 65d3, guest PC 0x0c0719c8 */
if(!s->budget--) { s->failed_pc=0x0c0719c8u; return 0; }
r[5]=r[13];
goto P_0c0719ca;
P_0c0719ca: /* original 7618, guest PC 0x0c0719ca */
if(!s->budget--) { s->failed_pc=0x0c0719cau; return 0; }
r[6]+=0x00000018u;
goto P_0c0719cc;
P_0c0719cc: /* original f049, guest PC 0x0c0719cc */
if(!s->budget--) { s->failed_pc=0x0c0719ccu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0719ce;
P_0c0719ce: /* original f549, guest PC 0x0c0719ce */
if(!s->budget--) { s->failed_pc=0x0c0719ceu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0719d0;
P_0c0719d0: /* original f648, guest PC 0x0c0719d0 */
if(!s->budget--) { s->failed_pc=0x0c0719d0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0719d2;
P_0c0719d2: /* original f859, guest PC 0x0c0719d2 */
if(!s->budget--) { s->failed_pc=0x0c0719d2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0719d4;
P_0c0719d4: /* original f959, guest PC 0x0c0719d4 */
if(!s->budget--) { s->failed_pc=0x0c0719d4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0719d6;
P_0c0719d6: /* original fa58, guest PC 0x0c0719d6 */
if(!s->budget--) { s->failed_pc=0x0c0719d6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0719d8;
P_0c0719d8: /* original 760c, guest PC 0x0c0719d8 */
if(!s->budget--) { s->failed_pc=0x0c0719d8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0719da;
P_0c0719da: /* original f35c, guest PC 0x0c0719da */
if(!s->budget--) { s->failed_pc=0x0c0719dau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0719dc;
P_0c0719dc: /* original f382, guest PC 0x0c0719dc */
if(!s->budget--) { s->failed_pc=0x0c0719dcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0719de;
P_0c0719de: /* original f20c, guest PC 0x0c0719de */
if(!s->budget--) { s->failed_pc=0x0c0719deu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0719e0;
P_0c0719e0: /* original f2a2, guest PC 0x0c0719e0 */
if(!s->budget--) { s->failed_pc=0x0c0719e0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0719e2;
P_0c0719e2: /* original f16c, guest PC 0x0c0719e2 */
if(!s->budget--) { s->failed_pc=0x0c0719e2u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0719e4;
P_0c0719e4: /* original f192, guest PC 0x0c0719e4 */
if(!s->budget--) { s->failed_pc=0x0c0719e4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0719e6;
P_0c0719e6: /* original f34d, guest PC 0x0c0719e6 */
if(!s->budget--) { s->failed_pc=0x0c0719e6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0719e8;
P_0c0719e8: /* original f39e, guest PC 0x0c0719e8 */
if(!s->budget--) { s->failed_pc=0x0c0719e8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0719ea;
P_0c0719ea: /* original f24d, guest PC 0x0c0719ea */
if(!s->budget--) { s->failed_pc=0x0c0719eau; return 0; }
fr[2]^=0x80000000u;
goto P_0c0719ec;
P_0c0719ec: /* original f06c, guest PC 0x0c0719ec */
if(!s->budget--) { s->failed_pc=0x0c0719ecu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0719ee;
P_0c0719ee: /* original f28e, guest PC 0x0c0719ee */
if(!s->budget--) { s->failed_pc=0x0c0719eeu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0719f0;
P_0c0719f0: /* original f14d, guest PC 0x0c0719f0 */
if(!s->budget--) { s->failed_pc=0x0c0719f0u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0719f2;
P_0c0719f2: /* original f63b, guest PC 0x0c0719f2 */
if(!s->budget--) { s->failed_pc=0x0c0719f2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0719f4;
P_0c0719f4: /* original f05c, guest PC 0x0c0719f4 */
if(!s->budget--) { s->failed_pc=0x0c0719f4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0719f6;
P_0c0719f6: /* original f1ae, guest PC 0x0c0719f6 */
if(!s->budget--) { s->failed_pc=0x0c0719f6u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0719f8;
P_0c0719f8: /* original f62b, guest PC 0x0c0719f8 */
if(!s->budget--) { s->failed_pc=0x0c0719f8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0719fa;
P_0c0719fa: /* original f61b, guest PC 0x0c0719fa */
if(!s->budget--) { s->failed_pc=0x0c0719fau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0719fc;
P_0c0719fc: /* original 64f3, guest PC 0x0c0719fc */
if(!s->budget--) { s->failed_pc=0x0c0719fcu; return 0; }
r[4]=r[15];
goto P_0c0719fe;
P_0c0719fe: /* original 7424, guest PC 0x0c0719fe */
if(!s->budget--) { s->failed_pc=0x0c0719feu; return 0; }
r[4]+=0x00000024u;
goto P_0c071a00;
P_0c071a00: /* original f049, guest PC 0x0c071a00 */
if(!s->budget--) { s->failed_pc=0x0c071a00u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a02;
P_0c071a02: /* original f149, guest PC 0x0c071a02 */
if(!s->budget--) { s->failed_pc=0x0c071a02u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a04;
P_0c071a04: /* original f249, guest PC 0x0c071a04 */
if(!s->budget--) { s->failed_pc=0x0c071a04u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a06;
P_0c071a06: /* original f38d, guest PC 0x0c071a06 */
if(!s->budget--) { s->failed_pc=0x0c071a06u; return 0; }
fr[3]=0;
goto P_0c071a08;
P_0c071a08: /* original f0ed, guest PC 0x0c071a08 */
if(!s->budget--) { s->failed_pc=0x0c071a08u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071a0a;
P_0c071a0a: /* original f37d, guest PC 0x0c071a0a */
if(!s->budget--) { s->failed_pc=0x0c071a0au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071a0c;
P_0c071a0c: /* original f232, guest PC 0x0c071a0c */
if(!s->budget--) { s->failed_pc=0x0c071a0cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071a0e;
P_0c071a0e: /* original f132, guest PC 0x0c071a0e */
if(!s->budget--) { s->failed_pc=0x0c071a0eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071a10;
P_0c071a10: /* original f032, guest PC 0x0c071a10 */
if(!s->budget--) { s->failed_pc=0x0c071a10u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071a12;
P_0c071a12: /* original f42b, guest PC 0x0c071a12 */
if(!s->budget--) { s->failed_pc=0x0c071a12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071a14;
P_0c071a14: /* original f41b, guest PC 0x0c071a14 */
if(!s->budget--) { s->failed_pc=0x0c071a14u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071a16;
P_0c071a16: /* original f40b, guest PC 0x0c071a16 */
if(!s->budget--) { s->failed_pc=0x0c071a16u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071a18;
P_0c071a18: /* original 64f3, guest PC 0x0c071a18 */
if(!s->budget--) { s->failed_pc=0x0c071a18u; return 0; }
r[4]=r[15];
goto P_0c071a1a;
P_0c071a1a: /* original 7418, guest PC 0x0c071a1a */
if(!s->budget--) { s->failed_pc=0x0c071a1au; return 0; }
r[4]+=0x00000018u;
goto P_0c071a1c;
P_0c071a1c: /* original f049, guest PC 0x0c071a1c */
if(!s->budget--) { s->failed_pc=0x0c071a1cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a1e;
P_0c071a1e: /* original f149, guest PC 0x0c071a1e */
if(!s->budget--) { s->failed_pc=0x0c071a1eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a20;
P_0c071a20: /* original f249, guest PC 0x0c071a20 */
if(!s->budget--) { s->failed_pc=0x0c071a20u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a22;
P_0c071a22: /* original f38d, guest PC 0x0c071a22 */
if(!s->budget--) { s->failed_pc=0x0c071a22u; return 0; }
fr[3]=0;
goto P_0c071a24;
P_0c071a24: /* original f0ed, guest PC 0x0c071a24 */
if(!s->budget--) { s->failed_pc=0x0c071a24u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071a26;
P_0c071a26: /* original f37d, guest PC 0x0c071a26 */
if(!s->budget--) { s->failed_pc=0x0c071a26u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071a28;
P_0c071a28: /* original f232, guest PC 0x0c071a28 */
if(!s->budget--) { s->failed_pc=0x0c071a28u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071a2a;
P_0c071a2a: /* original f132, guest PC 0x0c071a2a */
if(!s->budget--) { s->failed_pc=0x0c071a2au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071a2c;
P_0c071a2c: /* original f032, guest PC 0x0c071a2c */
if(!s->budget--) { s->failed_pc=0x0c071a2cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071a2e;
P_0c071a2e: /* original f42b, guest PC 0x0c071a2e */
if(!s->budget--) { s->failed_pc=0x0c071a2eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071a30;
P_0c071a30: /* original f41b, guest PC 0x0c071a30 */
if(!s->budget--) { s->failed_pc=0x0c071a30u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071a32;
P_0c071a32: /* original f40b, guest PC 0x0c071a32 */
if(!s->budget--) { s->failed_pc=0x0c071a32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071a34;
P_0c071a34: /* original 65f3, guest PC 0x0c071a34 */
if(!s->budget--) { s->failed_pc=0x0c071a34u; return 0; }
r[5]=r[15];
goto P_0c071a36;
P_0c071a36: /* original 64e3, guest PC 0x0c071a36 */
if(!s->budget--) { s->failed_pc=0x0c071a36u; return 0; }
r[4]=r[14];
goto P_0c071a38;
P_0c071a38: /* original 66f3, guest PC 0x0c071a38 */
if(!s->budget--) { s->failed_pc=0x0c071a38u; return 0; }
r[6]=r[15];
goto P_0c071a3a;
P_0c071a3a: /* original 740c, guest PC 0x0c071a3a */
if(!s->budget--) { s->failed_pc=0x0c071a3au; return 0; }
r[4]+=0x0000000cu;
goto P_0c071a3c;
P_0c071a3c: /* original 7618, guest PC 0x0c071a3c */
if(!s->budget--) { s->failed_pc=0x0c071a3cu; return 0; }
r[6]+=0x00000018u;
goto P_0c071a3e;
P_0c071a3e: /* original 7524, guest PC 0x0c071a3e */
if(!s->budget--) { s->failed_pc=0x0c071a3eu; return 0; }
r[5]+=0x00000024u;
goto P_0c071a40;
P_0c071a40: /* original f059, guest PC 0x0c071a40 */
if(!s->budget--) { s->failed_pc=0x0c071a40u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071a42;
P_0c071a42: /* original f369, guest PC 0x0c071a42 */
if(!s->budget--) { s->failed_pc=0x0c071a42u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071a44;
P_0c071a44: /* original f159, guest PC 0x0c071a44 */
if(!s->budget--) { s->failed_pc=0x0c071a44u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071a46;
P_0c071a46: /* original f469, guest PC 0x0c071a46 */
if(!s->budget--) { s->failed_pc=0x0c071a46u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071a48;
P_0c071a48: /* original f259, guest PC 0x0c071a48 */
if(!s->budget--) { s->failed_pc=0x0c071a48u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071a4a;
P_0c071a4a: /* original f569, guest PC 0x0c071a4a */
if(!s->budget--) { s->failed_pc=0x0c071a4au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071a4c;
P_0c071a4c: /* original 740c, guest PC 0x0c071a4c */
if(!s->budget--) { s->failed_pc=0x0c071a4cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071a4e;
P_0c071a4e: /* original f030, guest PC 0x0c071a4e */
if(!s->budget--) { s->failed_pc=0x0c071a4eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071a50;
P_0c071a50: /* original f250, guest PC 0x0c071a50 */
if(!s->budget--) { s->failed_pc=0x0c071a50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071a52;
P_0c071a52: /* original f140, guest PC 0x0c071a52 */
if(!s->budget--) { s->failed_pc=0x0c071a52u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071a54;
P_0c071a54: /* original f42b, guest PC 0x0c071a54 */
if(!s->budget--) { s->failed_pc=0x0c071a54u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071a56;
P_0c071a56: /* original f41b, guest PC 0x0c071a56 */
if(!s->budget--) { s->failed_pc=0x0c071a56u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071a58;
P_0c071a58: /* original f40b, guest PC 0x0c071a58 */
if(!s->budget--) { s->failed_pc=0x0c071a58u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071a5a;
P_0c071a5a: /* original 0009, guest PC 0x0c071a5a */
if(!s->budget--) { s->failed_pc=0x0c071a5au; return 0; }
goto P_0c071a5c;
P_0c071a5c: /* original 64e3, guest PC 0x0c071a5c */
if(!s->budget--) { s->failed_pc=0x0c071a5cu; return 0; }
r[4]=r[14];
goto P_0c071a5e;
P_0c071a5e: /* original 740c, guest PC 0x0c071a5e */
if(!s->budget--) { s->failed_pc=0x0c071a5eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071a60;
P_0c071a60: /* original f049, guest PC 0x0c071a60 */
if(!s->budget--) { s->failed_pc=0x0c071a60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a62;
P_0c071a62: /* original f149, guest PC 0x0c071a62 */
if(!s->budget--) { s->failed_pc=0x0c071a62u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a64;
P_0c071a64: /* original f249, guest PC 0x0c071a64 */
if(!s->budget--) { s->failed_pc=0x0c071a64u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071a66;
P_0c071a66: /* original f38d, guest PC 0x0c071a66 */
if(!s->budget--) { s->failed_pc=0x0c071a66u; return 0; }
fr[3]=0;
goto P_0c071a68;
P_0c071a68: /* original f0ed, guest PC 0x0c071a68 */
if(!s->budget--) { s->failed_pc=0x0c071a68u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071a6a;
P_0c071a6a: /* original f37d, guest PC 0x0c071a6a */
if(!s->budget--) { s->failed_pc=0x0c071a6au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071a6c;
P_0c071a6c: /* original f232, guest PC 0x0c071a6c */
if(!s->budget--) { s->failed_pc=0x0c071a6cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071a6e;
P_0c071a6e: /* original f132, guest PC 0x0c071a6e */
if(!s->budget--) { s->failed_pc=0x0c071a6eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071a70;
P_0c071a70: /* original f032, guest PC 0x0c071a70 */
if(!s->budget--) { s->failed_pc=0x0c071a70u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071a72;
P_0c071a72: /* original f42b, guest PC 0x0c071a72 */
if(!s->budget--) { s->failed_pc=0x0c071a72u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071a74;
P_0c071a74: /* original f41b, guest PC 0x0c071a74 */
if(!s->budget--) { s->failed_pc=0x0c071a74u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071a76;
P_0c071a76: /* original f40b, guest PC 0x0c071a76 */
if(!s->budget--) { s->failed_pc=0x0c071a76u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071a78;
P_0c071a78: /* original 1fe1, guest PC 0x0c071a78 */
if(!s->budget--) { s->failed_pc=0x0c071a78u; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c071a7a;
P_0c071a7a: /* original 6eb3, guest PC 0x0c071a7a */
if(!s->budget--) { s->failed_pc=0x0c071a7au; return 0; }
r[14]=r[11];
goto P_0c071a7c;
P_0c071a7c: /* original 63f2, guest PC 0x0c071a7c */
if(!s->budget--) { s->failed_pc=0x0c071a7cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071a7e;
P_0c071a7e: /* original 7b18, guest PC 0x0c071a7e */
if(!s->budget--) { s->failed_pc=0x0c071a7eu; return 0; }
r[11]+=0x00000018u;
goto P_0c071a80;
P_0c071a80: /* original 7318, guest PC 0x0c071a80 */
if(!s->budget--) { s->failed_pc=0x0c071a80u; return 0; }
r[3]+=0x00000018u;
goto P_0c071a82;
P_0c071a82: /* original 2f32, guest PC 0x0c071a82 */
if(!s->budget--) { s->failed_pc=0x0c071a82u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c071a84;
P_0c071a84: /* original 52f5, guest PC 0x0c071a84 */
if(!s->budget--) { s->failed_pc=0x0c071a84u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c071a86;
P_0c071a86: /* original 6123, guest PC 0x0c071a86 */
if(!s->budget--) { s->failed_pc=0x0c071a86u; return 0; }
r[1]=r[2];
goto P_0c071a88;
P_0c071a88: /* original 3197, guest PC 0x0c071a88 */
if(!s->budget--) { s->failed_pc=0x0c071a88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[9])!=0);
goto P_0c071a8a;
P_0c071a8a: /* original 1f22, guest PC 0x0c071a8a */
if(!s->budget--) { s->failed_pc=0x0c071a8au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c071a8c;
P_0c071a8c: /* original 8d03, guest PC 0x0c071a8c */
if(!s->budget--) { s->failed_pc=0x0c071a8cu; return 0; }
cond=r[17]&1u;
r[8]+=0x00000018u;
if(cond) { goto P_0c071a96; }
goto P_0c071a90;
P_0c071a8e: /* original 7818, guest PC 0x0c071a8e */
if(!s->budget--) { s->failed_pc=0x0c071a8eu; return 0; }
r[8]+=0x00000018u;
goto P_0c071a90;
P_0c071a90: /* original d203, guest PC 0x0c071a90 */
if(!s->budget--) { s->failed_pc=0x0c071a90u; return 0; }
r[2]=read(ram,0x0c071aa0u,4);
goto P_0c071a92;
P_0c071a92: /* original 422b, guest PC 0x0c071a92 */
if(!s->budget--) { s->failed_pc=0x0c071a92u; return 0; }
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
P_0c071a94: /* original 0009, guest PC 0x0c071a94 */
if(!s->budget--) { s->failed_pc=0x0c071a94u; return 0; }
goto P_0c071a96;
P_0c071a96: /* original 55f1, guest PC 0x0c071a96 */
if(!s->budget--) { s->failed_pc=0x0c071a96u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c071a98;
P_0c071a98: /* original 64d3, guest PC 0x0c071a98 */
if(!s->budget--) { s->failed_pc=0x0c071a98u; return 0; }
r[4]=r[13];
goto P_0c071a9a;
P_0c071a9a: /* original 66e3, guest PC 0x0c071a9a */
if(!s->budget--) { s->failed_pc=0x0c071a9au; return 0; }
r[6]=r[14];
goto P_0c071a9c;
P_0c071a9c: /* original a002, guest PC 0x0c071a9c */
if(!s->budget--) { s->failed_pc=0x0c071a9cu; return 0; }
goto P_0c071aa4;
P_0c071a9e: /* original 0009, guest PC 0x0c071a9e */
if(!s->budget--) { s->failed_pc=0x0c071a9eu; return 0; }
return vf3_matrix_family(0x0c071aa0u,s,ram);
P_0c071aa4: /* original f059, guest PC 0x0c071aa4 */
if(!s->budget--) { s->failed_pc=0x0c071aa4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071aa6;
P_0c071aa6: /* original f369, guest PC 0x0c071aa6 */
if(!s->budget--) { s->failed_pc=0x0c071aa6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aa8;
P_0c071aa8: /* original f159, guest PC 0x0c071aa8 */
if(!s->budget--) { s->failed_pc=0x0c071aa8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071aaa;
P_0c071aaa: /* original f469, guest PC 0x0c071aaa */
if(!s->budget--) { s->failed_pc=0x0c071aaau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aac;
P_0c071aac: /* original f031, guest PC 0x0c071aac */
if(!s->budget--) { s->failed_pc=0x0c071aacu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071aae;
P_0c071aae: /* original f258, guest PC 0x0c071aae */
if(!s->budget--) { s->failed_pc=0x0c071aaeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071ab0;
P_0c071ab0: /* original f568, guest PC 0x0c071ab0 */
if(!s->budget--) { s->failed_pc=0x0c071ab0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071ab2;
P_0c071ab2: /* original f141, guest PC 0x0c071ab2 */
if(!s->budget--) { s->failed_pc=0x0c071ab2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071ab4;
P_0c071ab4: /* original f251, guest PC 0x0c071ab4 */
if(!s->budget--) { s->failed_pc=0x0c071ab4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071ab6;
P_0c071ab6: /* original 7408, guest PC 0x0c071ab6 */
if(!s->budget--) { s->failed_pc=0x0c071ab6u; return 0; }
r[4]+=0x00000008u;
goto P_0c071ab8;
P_0c071ab8: /* original f42a, guest PC 0x0c071ab8 */
if(!s->budget--) { s->failed_pc=0x0c071ab8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071aba;
P_0c071aba: /* original f41b, guest PC 0x0c071aba */
if(!s->budget--) { s->failed_pc=0x0c071abau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071abc;
P_0c071abc: /* original f40b, guest PC 0x0c071abc */
if(!s->budget--) { s->failed_pc=0x0c071abcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071abe;
P_0c071abe: /* original 0009, guest PC 0x0c071abe */
if(!s->budget--) { s->failed_pc=0x0c071abeu; return 0; }
goto P_0c071ac0;
P_0c071ac0: /* original 64a3, guest PC 0x0c071ac0 */
if(!s->budget--) { s->failed_pc=0x0c071ac0u; return 0; }
r[4]=r[10];
goto P_0c071ac2;
P_0c071ac2: /* original 65b3, guest PC 0x0c071ac2 */
if(!s->budget--) { s->failed_pc=0x0c071ac2u; return 0; }
r[5]=r[11];
goto P_0c071ac4;
P_0c071ac4: /* original 66e3, guest PC 0x0c071ac4 */
if(!s->budget--) { s->failed_pc=0x0c071ac4u; return 0; }
r[6]=r[14];
goto P_0c071ac6;
P_0c071ac6: /* original f059, guest PC 0x0c071ac6 */
if(!s->budget--) { s->failed_pc=0x0c071ac6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ac8;
P_0c071ac8: /* original f369, guest PC 0x0c071ac8 */
if(!s->budget--) { s->failed_pc=0x0c071ac8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aca;
P_0c071aca: /* original f159, guest PC 0x0c071aca */
if(!s->budget--) { s->failed_pc=0x0c071acau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071acc;
P_0c071acc: /* original f469, guest PC 0x0c071acc */
if(!s->budget--) { s->failed_pc=0x0c071accu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ace;
P_0c071ace: /* original f031, guest PC 0x0c071ace */
if(!s->budget--) { s->failed_pc=0x0c071aceu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071ad0;
P_0c071ad0: /* original f258, guest PC 0x0c071ad0 */
if(!s->budget--) { s->failed_pc=0x0c071ad0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071ad2;
P_0c071ad2: /* original f568, guest PC 0x0c071ad2 */
if(!s->budget--) { s->failed_pc=0x0c071ad2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071ad4;
P_0c071ad4: /* original f141, guest PC 0x0c071ad4 */
if(!s->budget--) { s->failed_pc=0x0c071ad4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071ad6;
P_0c071ad6: /* original f251, guest PC 0x0c071ad6 */
if(!s->budget--) { s->failed_pc=0x0c071ad6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071ad8;
P_0c071ad8: /* original 7408, guest PC 0x0c071ad8 */
if(!s->budget--) { s->failed_pc=0x0c071ad8u; return 0; }
r[4]+=0x00000008u;
goto P_0c071ada;
P_0c071ada: /* original f42a, guest PC 0x0c071ada */
if(!s->budget--) { s->failed_pc=0x0c071adau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071adc;
P_0c071adc: /* original f41b, guest PC 0x0c071adc */
if(!s->budget--) { s->failed_pc=0x0c071adcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071ade;
P_0c071ade: /* original f40b, guest PC 0x0c071ade */
if(!s->budget--) { s->failed_pc=0x0c071adeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071ae0;
P_0c071ae0: /* original 65f2, guest PC 0x0c071ae0 */
if(!s->budget--) { s->failed_pc=0x0c071ae0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071ae2;
P_0c071ae2: /* original 64c3, guest PC 0x0c071ae2 */
if(!s->budget--) { s->failed_pc=0x0c071ae2u; return 0; }
r[4]=r[12];
goto P_0c071ae4;
P_0c071ae4: /* original 66e3, guest PC 0x0c071ae4 */
if(!s->budget--) { s->failed_pc=0x0c071ae4u; return 0; }
r[6]=r[14];
goto P_0c071ae6;
P_0c071ae6: /* original f059, guest PC 0x0c071ae6 */
if(!s->budget--) { s->failed_pc=0x0c071ae6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ae8;
P_0c071ae8: /* original f369, guest PC 0x0c071ae8 */
if(!s->budget--) { s->failed_pc=0x0c071ae8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aea;
P_0c071aea: /* original f159, guest PC 0x0c071aea */
if(!s->budget--) { s->failed_pc=0x0c071aeau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071aec;
P_0c071aec: /* original f469, guest PC 0x0c071aec */
if(!s->budget--) { s->failed_pc=0x0c071aecu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071aee;
P_0c071aee: /* original f031, guest PC 0x0c071aee */
if(!s->budget--) { s->failed_pc=0x0c071aeeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071af0;
P_0c071af0: /* original f258, guest PC 0x0c071af0 */
if(!s->budget--) { s->failed_pc=0x0c071af0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071af2;
P_0c071af2: /* original f568, guest PC 0x0c071af2 */
if(!s->budget--) { s->failed_pc=0x0c071af2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071af4;
P_0c071af4: /* original f141, guest PC 0x0c071af4 */
if(!s->budget--) { s->failed_pc=0x0c071af4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071af6;
P_0c071af6: /* original f251, guest PC 0x0c071af6 */
if(!s->budget--) { s->failed_pc=0x0c071af6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071af8;
P_0c071af8: /* original 7408, guest PC 0x0c071af8 */
if(!s->budget--) { s->failed_pc=0x0c071af8u; return 0; }
r[4]+=0x00000008u;
goto P_0c071afa;
P_0c071afa: /* original f42a, guest PC 0x0c071afa */
if(!s->budget--) { s->failed_pc=0x0c071afau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071afc;
P_0c071afc: /* original f41b, guest PC 0x0c071afc */
if(!s->budget--) { s->failed_pc=0x0c071afcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071afe;
P_0c071afe: /* original f40b, guest PC 0x0c071afe */
if(!s->budget--) { s->failed_pc=0x0c071afeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071b00;
P_0c071b00: /* original 54f3, guest PC 0x0c071b00 */
if(!s->budget--) { s->failed_pc=0x0c071b00u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c071b02;
P_0c071b02: /* original 6583, guest PC 0x0c071b02 */
if(!s->budget--) { s->failed_pc=0x0c071b02u; return 0; }
r[5]=r[8];
goto P_0c071b04;
P_0c071b04: /* original 66e3, guest PC 0x0c071b04 */
if(!s->budget--) { s->failed_pc=0x0c071b04u; return 0; }
r[6]=r[14];
goto P_0c071b06;
P_0c071b06: /* original f059, guest PC 0x0c071b06 */
if(!s->budget--) { s->failed_pc=0x0c071b06u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b08;
P_0c071b08: /* original f369, guest PC 0x0c071b08 */
if(!s->budget--) { s->failed_pc=0x0c071b08u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071b0a;
P_0c071b0a: /* original f159, guest PC 0x0c071b0a */
if(!s->budget--) { s->failed_pc=0x0c071b0au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b0c;
P_0c071b0c: /* original f469, guest PC 0x0c071b0c */
if(!s->budget--) { s->failed_pc=0x0c071b0cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071b0e;
P_0c071b0e: /* original f031, guest PC 0x0c071b0e */
if(!s->budget--) { s->failed_pc=0x0c071b0eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071b10;
P_0c071b10: /* original f258, guest PC 0x0c071b10 */
if(!s->budget--) { s->failed_pc=0x0c071b10u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071b12;
P_0c071b12: /* original f568, guest PC 0x0c071b12 */
if(!s->budget--) { s->failed_pc=0x0c071b12u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071b14;
P_0c071b14: /* original f141, guest PC 0x0c071b14 */
if(!s->budget--) { s->failed_pc=0x0c071b14u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071b16;
P_0c071b16: /* original f251, guest PC 0x0c071b16 */
if(!s->budget--) { s->failed_pc=0x0c071b16u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071b18;
P_0c071b18: /* original 7408, guest PC 0x0c071b18 */
if(!s->budget--) { s->failed_pc=0x0c071b18u; return 0; }
r[4]+=0x00000008u;
goto P_0c071b1a;
P_0c071b1a: /* original f42a, guest PC 0x0c071b1a */
if(!s->budget--) { s->failed_pc=0x0c071b1au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071b1c;
P_0c071b1c: /* original f41b, guest PC 0x0c071b1c */
if(!s->budget--) { s->failed_pc=0x0c071b1cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071b1e;
P_0c071b1e: /* original f40b, guest PC 0x0c071b1e */
if(!s->budget--) { s->failed_pc=0x0c071b1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071b20;
P_0c071b20: /* original 66f3, guest PC 0x0c071b20 */
if(!s->budget--) { s->failed_pc=0x0c071b20u; return 0; }
r[6]=r[15];
goto P_0c071b22;
P_0c071b22: /* original 64c3, guest PC 0x0c071b22 */
if(!s->budget--) { s->failed_pc=0x0c071b22u; return 0; }
r[4]=r[12];
goto P_0c071b24;
P_0c071b24: /* original 65d3, guest PC 0x0c071b24 */
if(!s->budget--) { s->failed_pc=0x0c071b24u; return 0; }
r[5]=r[13];
goto P_0c071b26;
P_0c071b26: /* original 7624, guest PC 0x0c071b26 */
if(!s->budget--) { s->failed_pc=0x0c071b26u; return 0; }
r[6]+=0x00000024u;
goto P_0c071b28;
P_0c071b28: /* original f049, guest PC 0x0c071b28 */
if(!s->budget--) { s->failed_pc=0x0c071b28u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b2a;
P_0c071b2a: /* original f549, guest PC 0x0c071b2a */
if(!s->budget--) { s->failed_pc=0x0c071b2au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b2c;
P_0c071b2c: /* original f648, guest PC 0x0c071b2c */
if(!s->budget--) { s->failed_pc=0x0c071b2cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071b2e;
P_0c071b2e: /* original f859, guest PC 0x0c071b2e */
if(!s->budget--) { s->failed_pc=0x0c071b2eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b30;
P_0c071b30: /* original f959, guest PC 0x0c071b30 */
if(!s->budget--) { s->failed_pc=0x0c071b30u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b32;
P_0c071b32: /* original fa58, guest PC 0x0c071b32 */
if(!s->budget--) { s->failed_pc=0x0c071b32u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071b34;
P_0c071b34: /* original 760c, guest PC 0x0c071b34 */
if(!s->budget--) { s->failed_pc=0x0c071b34u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071b36;
P_0c071b36: /* original f35c, guest PC 0x0c071b36 */
if(!s->budget--) { s->failed_pc=0x0c071b36u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071b38;
P_0c071b38: /* original f382, guest PC 0x0c071b38 */
if(!s->budget--) { s->failed_pc=0x0c071b38u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071b3a;
P_0c071b3a: /* original f20c, guest PC 0x0c071b3a */
if(!s->budget--) { s->failed_pc=0x0c071b3au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071b3c;
P_0c071b3c: /* original f2a2, guest PC 0x0c071b3c */
if(!s->budget--) { s->failed_pc=0x0c071b3cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071b3e;
P_0c071b3e: /* original f16c, guest PC 0x0c071b3e */
if(!s->budget--) { s->failed_pc=0x0c071b3eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071b40;
P_0c071b40: /* original f192, guest PC 0x0c071b40 */
if(!s->budget--) { s->failed_pc=0x0c071b40u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071b42;
P_0c071b42: /* original f34d, guest PC 0x0c071b42 */
if(!s->budget--) { s->failed_pc=0x0c071b42u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071b44;
P_0c071b44: /* original f39e, guest PC 0x0c071b44 */
if(!s->budget--) { s->failed_pc=0x0c071b44u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071b46;
P_0c071b46: /* original f24d, guest PC 0x0c071b46 */
if(!s->budget--) { s->failed_pc=0x0c071b46u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071b48;
P_0c071b48: /* original f06c, guest PC 0x0c071b48 */
if(!s->budget--) { s->failed_pc=0x0c071b48u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071b4a;
P_0c071b4a: /* original f28e, guest PC 0x0c071b4a */
if(!s->budget--) { s->failed_pc=0x0c071b4au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071b4c;
P_0c071b4c: /* original f14d, guest PC 0x0c071b4c */
if(!s->budget--) { s->failed_pc=0x0c071b4cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c071b4e;
P_0c071b4e: /* original f63b, guest PC 0x0c071b4e */
if(!s->budget--) { s->failed_pc=0x0c071b4eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071b50;
P_0c071b50: /* original f05c, guest PC 0x0c071b50 */
if(!s->budget--) { s->failed_pc=0x0c071b50u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071b52;
P_0c071b52: /* original f1ae, guest PC 0x0c071b52 */
if(!s->budget--) { s->failed_pc=0x0c071b52u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071b54;
P_0c071b54: /* original f62b, guest PC 0x0c071b54 */
if(!s->budget--) { s->failed_pc=0x0c071b54u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071b56;
P_0c071b56: /* original f61b, guest PC 0x0c071b56 */
if(!s->budget--) { s->failed_pc=0x0c071b56u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071b58;
P_0c071b58: /* original 54f3, guest PC 0x0c071b58 */
if(!s->budget--) { s->failed_pc=0x0c071b58u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c071b5a;
P_0c071b5a: /* original 66f3, guest PC 0x0c071b5a */
if(!s->budget--) { s->failed_pc=0x0c071b5au; return 0; }
r[6]=r[15];
goto P_0c071b5c;
P_0c071b5c: /* original 65a3, guest PC 0x0c071b5c */
if(!s->budget--) { s->failed_pc=0x0c071b5cu; return 0; }
r[5]=r[10];
goto P_0c071b5e;
P_0c071b5e: /* original 7618, guest PC 0x0c071b5e */
if(!s->budget--) { s->failed_pc=0x0c071b5eu; return 0; }
r[6]+=0x00000018u;
goto P_0c071b60;
P_0c071b60: /* original f049, guest PC 0x0c071b60 */
if(!s->budget--) { s->failed_pc=0x0c071b60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b62;
P_0c071b62: /* original f549, guest PC 0x0c071b62 */
if(!s->budget--) { s->failed_pc=0x0c071b62u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b64;
P_0c071b64: /* original f648, guest PC 0x0c071b64 */
if(!s->budget--) { s->failed_pc=0x0c071b64u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071b66;
P_0c071b66: /* original f859, guest PC 0x0c071b66 */
if(!s->budget--) { s->failed_pc=0x0c071b66u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b68;
P_0c071b68: /* original f959, guest PC 0x0c071b68 */
if(!s->budget--) { s->failed_pc=0x0c071b68u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071b6a;
P_0c071b6a: /* original fa58, guest PC 0x0c071b6a */
if(!s->budget--) { s->failed_pc=0x0c071b6au; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071b6c;
P_0c071b6c: /* original 760c, guest PC 0x0c071b6c */
if(!s->budget--) { s->failed_pc=0x0c071b6cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071b6e;
P_0c071b6e: /* original f35c, guest PC 0x0c071b6e */
if(!s->budget--) { s->failed_pc=0x0c071b6eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071b70;
P_0c071b70: /* original f382, guest PC 0x0c071b70 */
if(!s->budget--) { s->failed_pc=0x0c071b70u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071b72;
P_0c071b72: /* original f20c, guest PC 0x0c071b72 */
if(!s->budget--) { s->failed_pc=0x0c071b72u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071b74;
P_0c071b74: /* original f2a2, guest PC 0x0c071b74 */
if(!s->budget--) { s->failed_pc=0x0c071b74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071b76;
P_0c071b76: /* original f16c, guest PC 0x0c071b76 */
if(!s->budget--) { s->failed_pc=0x0c071b76u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071b78;
P_0c071b78: /* original f192, guest PC 0x0c071b78 */
if(!s->budget--) { s->failed_pc=0x0c071b78u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071b7a;
P_0c071b7a: /* original f34d, guest PC 0x0c071b7a */
if(!s->budget--) { s->failed_pc=0x0c071b7au; return 0; }
fr[3]^=0x80000000u;
goto P_0c071b7c;
P_0c071b7c: /* original f39e, guest PC 0x0c071b7c */
if(!s->budget--) { s->failed_pc=0x0c071b7cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071b7e;
P_0c071b7e: /* original f24d, guest PC 0x0c071b7e */
if(!s->budget--) { s->failed_pc=0x0c071b7eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c071b80;
P_0c071b80: /* original f06c, guest PC 0x0c071b80 */
if(!s->budget--) { s->failed_pc=0x0c071b80u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071b82;
P_0c071b82: /* original f28e, guest PC 0x0c071b82 */
if(!s->budget--) { s->failed_pc=0x0c071b82u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071b84;
P_0c071b84: /* original f14d, guest PC 0x0c071b84 */
if(!s->budget--) { s->failed_pc=0x0c071b84u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071b86;
P_0c071b86: /* original f63b, guest PC 0x0c071b86 */
if(!s->budget--) { s->failed_pc=0x0c071b86u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071b88;
P_0c071b88: /* original f05c, guest PC 0x0c071b88 */
if(!s->budget--) { s->failed_pc=0x0c071b88u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071b8a;
P_0c071b8a: /* original f1ae, guest PC 0x0c071b8a */
if(!s->budget--) { s->failed_pc=0x0c071b8au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071b8c;
P_0c071b8c: /* original f62b, guest PC 0x0c071b8c */
if(!s->budget--) { s->failed_pc=0x0c071b8cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071b8e;
P_0c071b8e: /* original f61b, guest PC 0x0c071b8e */
if(!s->budget--) { s->failed_pc=0x0c071b8eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071b90;
P_0c071b90: /* original 64f3, guest PC 0x0c071b90 */
if(!s->budget--) { s->failed_pc=0x0c071b90u; return 0; }
r[4]=r[15];
goto P_0c071b92;
P_0c071b92: /* original 7424, guest PC 0x0c071b92 */
if(!s->budget--) { s->failed_pc=0x0c071b92u; return 0; }
r[4]+=0x00000024u;
goto P_0c071b94;
P_0c071b94: /* original f049, guest PC 0x0c071b94 */
if(!s->budget--) { s->failed_pc=0x0c071b94u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b96;
P_0c071b96: /* original f149, guest PC 0x0c071b96 */
if(!s->budget--) { s->failed_pc=0x0c071b96u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b98;
P_0c071b98: /* original f249, guest PC 0x0c071b98 */
if(!s->budget--) { s->failed_pc=0x0c071b98u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071b9a;
P_0c071b9a: /* original f38d, guest PC 0x0c071b9a */
if(!s->budget--) { s->failed_pc=0x0c071b9au; return 0; }
fr[3]=0;
goto P_0c071b9c;
P_0c071b9c: /* original f0ed, guest PC 0x0c071b9c */
if(!s->budget--) { s->failed_pc=0x0c071b9cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071b9e;
P_0c071b9e: /* original f37d, guest PC 0x0c071b9e */
if(!s->budget--) { s->failed_pc=0x0c071b9eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071ba0;
P_0c071ba0: /* original f232, guest PC 0x0c071ba0 */
if(!s->budget--) { s->failed_pc=0x0c071ba0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071ba2;
P_0c071ba2: /* original f132, guest PC 0x0c071ba2 */
if(!s->budget--) { s->failed_pc=0x0c071ba2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071ba4;
P_0c071ba4: /* original f032, guest PC 0x0c071ba4 */
if(!s->budget--) { s->failed_pc=0x0c071ba4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071ba6;
P_0c071ba6: /* original f42b, guest PC 0x0c071ba6 */
if(!s->budget--) { s->failed_pc=0x0c071ba6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071ba8;
P_0c071ba8: /* original f41b, guest PC 0x0c071ba8 */
if(!s->budget--) { s->failed_pc=0x0c071ba8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071baa;
P_0c071baa: /* original f40b, guest PC 0x0c071baa */
if(!s->budget--) { s->failed_pc=0x0c071baau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071bac;
P_0c071bac: /* original 64f3, guest PC 0x0c071bac */
if(!s->budget--) { s->failed_pc=0x0c071bacu; return 0; }
r[4]=r[15];
goto P_0c071bae;
P_0c071bae: /* original 7418, guest PC 0x0c071bae */
if(!s->budget--) { s->failed_pc=0x0c071baeu; return 0; }
r[4]+=0x00000018u;
goto P_0c071bb0;
P_0c071bb0: /* original f049, guest PC 0x0c071bb0 */
if(!s->budget--) { s->failed_pc=0x0c071bb0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bb2;
P_0c071bb2: /* original f149, guest PC 0x0c071bb2 */
if(!s->budget--) { s->failed_pc=0x0c071bb2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bb4;
P_0c071bb4: /* original f249, guest PC 0x0c071bb4 */
if(!s->budget--) { s->failed_pc=0x0c071bb4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bb6;
P_0c071bb6: /* original f38d, guest PC 0x0c071bb6 */
if(!s->budget--) { s->failed_pc=0x0c071bb6u; return 0; }
fr[3]=0;
goto P_0c071bb8;
P_0c071bb8: /* original f0ed, guest PC 0x0c071bb8 */
if(!s->budget--) { s->failed_pc=0x0c071bb8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071bba;
P_0c071bba: /* original f37d, guest PC 0x0c071bba */
if(!s->budget--) { s->failed_pc=0x0c071bbau; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071bbc;
P_0c071bbc: /* original f232, guest PC 0x0c071bbc */
if(!s->budget--) { s->failed_pc=0x0c071bbcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071bbe;
P_0c071bbe: /* original f132, guest PC 0x0c071bbe */
if(!s->budget--) { s->failed_pc=0x0c071bbeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071bc0;
P_0c071bc0: /* original f032, guest PC 0x0c071bc0 */
if(!s->budget--) { s->failed_pc=0x0c071bc0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071bc2;
P_0c071bc2: /* original f42b, guest PC 0x0c071bc2 */
if(!s->budget--) { s->failed_pc=0x0c071bc2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071bc4;
P_0c071bc4: /* original f41b, guest PC 0x0c071bc4 */
if(!s->budget--) { s->failed_pc=0x0c071bc4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071bc6;
P_0c071bc6: /* original f40b, guest PC 0x0c071bc6 */
if(!s->budget--) { s->failed_pc=0x0c071bc6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071bc8;
P_0c071bc8: /* original 65f3, guest PC 0x0c071bc8 */
if(!s->budget--) { s->failed_pc=0x0c071bc8u; return 0; }
r[5]=r[15];
goto P_0c071bca;
P_0c071bca: /* original 64e3, guest PC 0x0c071bca */
if(!s->budget--) { s->failed_pc=0x0c071bcau; return 0; }
r[4]=r[14];
goto P_0c071bcc;
P_0c071bcc: /* original 66f3, guest PC 0x0c071bcc */
if(!s->budget--) { s->failed_pc=0x0c071bccu; return 0; }
r[6]=r[15];
goto P_0c071bce;
P_0c071bce: /* original 740c, guest PC 0x0c071bce */
if(!s->budget--) { s->failed_pc=0x0c071bceu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071bd0;
P_0c071bd0: /* original 7618, guest PC 0x0c071bd0 */
if(!s->budget--) { s->failed_pc=0x0c071bd0u; return 0; }
r[6]+=0x00000018u;
goto P_0c071bd2;
P_0c071bd2: /* original 7524, guest PC 0x0c071bd2 */
if(!s->budget--) { s->failed_pc=0x0c071bd2u; return 0; }
r[5]+=0x00000024u;
goto P_0c071bd4;
P_0c071bd4: /* original f059, guest PC 0x0c071bd4 */
if(!s->budget--) { s->failed_pc=0x0c071bd4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071bd6;
P_0c071bd6: /* original f369, guest PC 0x0c071bd6 */
if(!s->budget--) { s->failed_pc=0x0c071bd6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071bd8;
P_0c071bd8: /* original f159, guest PC 0x0c071bd8 */
if(!s->budget--) { s->failed_pc=0x0c071bd8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071bda;
P_0c071bda: /* original f469, guest PC 0x0c071bda */
if(!s->budget--) { s->failed_pc=0x0c071bdau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071bdc;
P_0c071bdc: /* original f259, guest PC 0x0c071bdc */
if(!s->budget--) { s->failed_pc=0x0c071bdcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071bde;
P_0c071bde: /* original f569, guest PC 0x0c071bde */
if(!s->budget--) { s->failed_pc=0x0c071bdeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071be0;
P_0c071be0: /* original 740c, guest PC 0x0c071be0 */
if(!s->budget--) { s->failed_pc=0x0c071be0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071be2;
P_0c071be2: /* original f030, guest PC 0x0c071be2 */
if(!s->budget--) { s->failed_pc=0x0c071be2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071be4;
P_0c071be4: /* original f250, guest PC 0x0c071be4 */
if(!s->budget--) { s->failed_pc=0x0c071be4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071be6;
P_0c071be6: /* original f140, guest PC 0x0c071be6 */
if(!s->budget--) { s->failed_pc=0x0c071be6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071be8;
P_0c071be8: /* original f42b, guest PC 0x0c071be8 */
if(!s->budget--) { s->failed_pc=0x0c071be8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071bea;
P_0c071bea: /* original f41b, guest PC 0x0c071bea */
if(!s->budget--) { s->failed_pc=0x0c071beau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071bec;
P_0c071bec: /* original f40b, guest PC 0x0c071bec */
if(!s->budget--) { s->failed_pc=0x0c071becu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071bee;
P_0c071bee: /* original 0009, guest PC 0x0c071bee */
if(!s->budget--) { s->failed_pc=0x0c071beeu; return 0; }
goto P_0c071bf0;
P_0c071bf0: /* original 64e3, guest PC 0x0c071bf0 */
if(!s->budget--) { s->failed_pc=0x0c071bf0u; return 0; }
r[4]=r[14];
goto P_0c071bf2;
P_0c071bf2: /* original 740c, guest PC 0x0c071bf2 */
if(!s->budget--) { s->failed_pc=0x0c071bf2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071bf4;
P_0c071bf4: /* original f049, guest PC 0x0c071bf4 */
if(!s->budget--) { s->failed_pc=0x0c071bf4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bf6;
P_0c071bf6: /* original f149, guest PC 0x0c071bf6 */
if(!s->budget--) { s->failed_pc=0x0c071bf6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bf8;
P_0c071bf8: /* original f249, guest PC 0x0c071bf8 */
if(!s->budget--) { s->failed_pc=0x0c071bf8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071bfa;
P_0c071bfa: /* original f38d, guest PC 0x0c071bfa */
if(!s->budget--) { s->failed_pc=0x0c071bfau; return 0; }
fr[3]=0;
goto P_0c071bfc;
P_0c071bfc: /* original f0ed, guest PC 0x0c071bfc */
if(!s->budget--) { s->failed_pc=0x0c071bfcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071bfe;
P_0c071bfe: /* original f37d, guest PC 0x0c071bfe */
if(!s->budget--) { s->failed_pc=0x0c071bfeu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071c00;
P_0c071c00: /* original f232, guest PC 0x0c071c00 */
if(!s->budget--) { s->failed_pc=0x0c071c00u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071c02;
P_0c071c02: /* original f132, guest PC 0x0c071c02 */
if(!s->budget--) { s->failed_pc=0x0c071c02u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071c04;
P_0c071c04: /* original f032, guest PC 0x0c071c04 */
if(!s->budget--) { s->failed_pc=0x0c071c04u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071c06;
P_0c071c06: /* original f42b, guest PC 0x0c071c06 */
if(!s->budget--) { s->failed_pc=0x0c071c06u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071c08;
P_0c071c08: /* original f41b, guest PC 0x0c071c08 */
if(!s->budget--) { s->failed_pc=0x0c071c08u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071c0a;
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
P_0c072b02: /* original 6752, guest PC 0x0c072b02 */
if(!s->budget--) { s->failed_pc=0x0c072b02u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c072b04;
P_0c072b04: /* original 5451, guest PC 0x0c072b04 */
if(!s->budget--) { s->failed_pc=0x0c072b04u; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c072b06;
P_0c072b06: /* original 4715, guest PC 0x0c072b06 */
if(!s->budget--) { s->failed_pc=0x0c072b06u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c072b08;
P_0c072b08: /* original 8f18, guest PC 0x0c072b08 */
if(!s->budget--) { s->failed_pc=0x0c072b08u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[5]+8,4);
if(!cond) { goto P_0c072b3c; }
goto P_0c072b0c;
P_0c072b0a: /* original 5652, guest PC 0x0c072b0a */
if(!s->budget--) { s->failed_pc=0x0c072b0au; return 0; }
r[6]=read(ram,r[5]+8,4);
goto P_0c072b0c;
P_0c072b0c: /* original f349, guest PC 0x0c072b0c */
if(!s->budget--) { s->failed_pc=0x0c072b0cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072b0e;
P_0c072b0e: /* original 77ff, guest PC 0x0c072b0e */
if(!s->budget--) { s->failed_pc=0x0c072b0eu; return 0; }
r[7]+=0xffffffffu;
goto P_0c072b10;
P_0c072b10: /* original 4715, guest PC 0x0c072b10 */
if(!s->budget--) { s->failed_pc=0x0c072b10u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c072b12;
P_0c072b12: /* original f63a, guest PC 0x0c072b12 */
if(!s->budget--) { s->failed_pc=0x0c072b12u; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072b14;
P_0c072b14: /* original 7604, guest PC 0x0c072b14 */
if(!s->budget--) { s->failed_pc=0x0c072b14u; return 0; }
r[6]+=0x00000004u;
goto P_0c072b16;
P_0c072b16: /* original f349, guest PC 0x0c072b16 */
if(!s->budget--) { s->failed_pc=0x0c072b16u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072b18;
P_0c072b18: /* original f63a, guest PC 0x0c072b18 */
if(!s->budget--) { s->failed_pc=0x0c072b18u; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072b1a;
P_0c072b1a: /* original 7604, guest PC 0x0c072b1a */
if(!s->budget--) { s->failed_pc=0x0c072b1au; return 0; }
r[6]+=0x00000004u;
goto P_0c072b1c;
P_0c072b1c: /* original f349, guest PC 0x0c072b1c */
if(!s->budget--) { s->failed_pc=0x0c072b1cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072b1e;
P_0c072b1e: /* original f63a, guest PC 0x0c072b1e */
if(!s->budget--) { s->failed_pc=0x0c072b1eu; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072b20;
P_0c072b20: /* original 7604, guest PC 0x0c072b20 */
if(!s->budget--) { s->failed_pc=0x0c072b20u; return 0; }
r[6]+=0x00000004u;
goto P_0c072b22;
P_0c072b22: /* original f349, guest PC 0x0c072b22 */
if(!s->budget--) { s->failed_pc=0x0c072b22u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072b24;
P_0c072b24: /* original f34d, guest PC 0x0c072b24 */
if(!s->budget--) { s->failed_pc=0x0c072b24u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072b26;
P_0c072b26: /* original f63a, guest PC 0x0c072b26 */
if(!s->budget--) { s->failed_pc=0x0c072b26u; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072b28;
P_0c072b28: /* original 7604, guest PC 0x0c072b28 */
if(!s->budget--) { s->failed_pc=0x0c072b28u; return 0; }
r[6]+=0x00000004u;
goto P_0c072b2a;
P_0c072b2a: /* original f349, guest PC 0x0c072b2a */
if(!s->budget--) { s->failed_pc=0x0c072b2au; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072b2c;
P_0c072b2c: /* original f34d, guest PC 0x0c072b2c */
if(!s->budget--) { s->failed_pc=0x0c072b2cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c072b2e;
P_0c072b2e: /* original f63a, guest PC 0x0c072b2e */
if(!s->budget--) { s->failed_pc=0x0c072b2eu; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072b30;
P_0c072b30: /* original 7604, guest PC 0x0c072b30 */
if(!s->budget--) { s->failed_pc=0x0c072b30u; return 0; }
r[6]+=0x00000004u;
goto P_0c072b32;
P_0c072b32: /* original f349, guest PC 0x0c072b32 */
if(!s->budget--) { s->failed_pc=0x0c072b32u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072b34;
P_0c072b34: /* original f34d, guest PC 0x0c072b34 */
if(!s->budget--) { s->failed_pc=0x0c072b34u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072b36;
P_0c072b36: /* original f63a, guest PC 0x0c072b36 */
if(!s->budget--) { s->failed_pc=0x0c072b36u; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072b38;
P_0c072b38: /* original 8de8, guest PC 0x0c072b38 */
if(!s->budget--) { s->failed_pc=0x0c072b38u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(cond) { goto P_0c072b0c; }
goto P_0c072b3c;
P_0c072b3a: /* original 7604, guest PC 0x0c072b3a */
if(!s->budget--) { s->failed_pc=0x0c072b3au; return 0; }
r[6]+=0x00000004u;
goto P_0c072b3c;
P_0c072b3c: /* original 000b, guest PC 0x0c072b3c */
if(!s->budget--) { s->failed_pc=0x0c072b3cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c072b3e: /* original 0009, guest PC 0x0c072b3e */
if(!s->budget--) { s->failed_pc=0x0c072b3eu; return 0; }
return vf3_matrix_family(0x0c072b40u,s,ram);
P_0c0aa744: /* original 4f22, guest PC 0x0c0aa744 */
if(!s->budget--) { s->failed_pc=0x0c0aa744u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa746;
P_0c0aa746: /* original d338, guest PC 0x0c0aa746 */
if(!s->budget--) { s->failed_pc=0x0c0aa746u; return 0; }
r[3]=read(ram,0x0c0aa828u,4);
goto P_0c0aa748;
P_0c0aa748: /* original 7ff0, guest PC 0x0c0aa748 */
if(!s->budget--) { s->failed_pc=0x0c0aa748u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0aa74a;
P_0c0aa74a: /* original 2f32, guest PC 0x0c0aa74a */
if(!s->budget--) { s->failed_pc=0x0c0aa74au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aa74c;
P_0c0aa74c: /* original 64f3, guest PC 0x0c0aa74c */
if(!s->budget--) { s->failed_pc=0x0c0aa74cu; return 0; }
r[4]=r[15];
goto P_0c0aa74e;
P_0c0aa74e: /* original 9063, guest PC 0x0c0aa74e */
if(!s->budget--) { s->failed_pc=0x0c0aa74eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa818u,2);
goto P_0c0aa750;
P_0c0aa750: /* original 7404, guest PC 0x0c0aa750 */
if(!s->budget--) { s->failed_pc=0x0c0aa750u; return 0; }
r[4]+=0x00000004u;
goto P_0c0aa752;
P_0c0aa752: /* original d336, guest PC 0x0c0aa752 */
if(!s->budget--) { s->failed_pc=0x0c0aa752u; return 0; }
r[3]=read(ram,0x0c0aa82cu,4);
goto P_0c0aa754;
P_0c0aa754: /* original f5e6, guest PC 0x0c0aa754 */
if(!s->budget--) { s->failed_pc=0x0c0aa754u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0aa756;
P_0c0aa756: /* original 70f8, guest PC 0x0c0aa756 */
if(!s->budget--) { s->failed_pc=0x0c0aa756u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0aa758;
P_0c0aa758: /* original 430b, guest PC 0x0c0aa758 */
if(!s->budget--) { s->failed_pc=0x0c0aa758u; return 0; }
target=r[3];
r[16]=0x0c0aa75cu;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aa75cu) { target=s->pc; goto dispatch; }
goto P_0c0aa75c;
P_0c0aa75a: /* original f4e6, guest PC 0x0c0aa75a */
if(!s->budget--) { s->failed_pc=0x0c0aa75au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0aa75c;
P_0c0aa75c: /* original e004, guest PC 0x0c0aa75c */
if(!s->budget--) { s->failed_pc=0x0c0aa75cu; return 0; }
r[0]=0x00000004u;
goto P_0c0aa75e;
P_0c0aa75e: /* original f5f6, guest PC 0x0c0aa75e */
if(!s->budget--) { s->failed_pc=0x0c0aa75eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0aa760;
P_0c0aa760: /* original e00c, guest PC 0x0c0aa760 */
if(!s->budget--) { s->failed_pc=0x0c0aa760u; return 0; }
r[0]=0x0000000cu;
goto P_0c0aa762;
P_0c0aa762: /* original f7f6, guest PC 0x0c0aa762 */
if(!s->budget--) { s->failed_pc=0x0c0aa762u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0aa764;
P_0c0aa764: /* original e024, guest PC 0x0c0aa764 */
if(!s->budget--) { s->failed_pc=0x0c0aa764u; return 0; }
r[0]=0x00000024u;
goto P_0c0aa766;
P_0c0aa766: /* original f8e6, guest PC 0x0c0aa766 */
if(!s->budget--) { s->failed_pc=0x0c0aa766u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0aa768;
P_0c0aa768: /* original e02c, guest PC 0x0c0aa768 */
if(!s->budget--) { s->failed_pc=0x0c0aa768u; return 0; }
r[0]=0x0000002cu;
goto P_0c0aa76a;
P_0c0aa76a: /* original f4e6, guest PC 0x0c0aa76a */
if(!s->budget--) { s->failed_pc=0x0c0aa76au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0aa76c;
P_0c0aa76c: /* original e11c, guest PC 0x0c0aa76c */
if(!s->budget--) { s->failed_pc=0x0c0aa76cu; return 0; }
r[1]=0x0000001cu;
goto P_0c0aa76e;
P_0c0aa76e: /* original 60f2, guest PC 0x0c0aa76e */
if(!s->budget--) { s->failed_pc=0x0c0aa76eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0aa770;
P_0c0aa770: /* original 001c, guest PC 0x0c0aa770 */
if(!s->budget--) { s->failed_pc=0x0c0aa770u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0aa772;
P_0c0aa772: /* original 600c, guest PC 0x0c0aa772 */
if(!s->budget--) { s->failed_pc=0x0c0aa772u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa774;
P_0c0aa774: /* original c90f, guest PC 0x0c0aa774 */
if(!s->budget--) { s->failed_pc=0x0c0aa774u; return 0; }
r[0]&=15u;
goto P_0c0aa776;
P_0c0aa776: /* original 8809, guest PC 0x0c0aa776 */
if(!s->budget--) { s->failed_pc=0x0c0aa776u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0aa778;
P_0c0aa778: /* original 8d03, guest PC 0x0c0aa778 */
if(!s->budget--) { s->failed_pc=0x0c0aa778u; return 0; }
cond=r[17]&1u;
fr[7]^=0x80000000u;
if(cond) { goto P_0c0aa782; }
goto P_0c0aa77c;
P_0c0aa77a: /* original f74d, guest PC 0x0c0aa77a */
if(!s->budget--) { s->failed_pc=0x0c0aa77au; return 0; }
fr[7]^=0x80000000u;
goto P_0c0aa77c;
P_0c0aa77c: /* original c72c, guest PC 0x0c0aa77c */
if(!s->budget--) { s->failed_pc=0x0c0aa77cu; return 0; }
r[0]=0x0c0aa830u;
goto P_0c0aa77e;
P_0c0aa77e: /* original a002, guest PC 0x0c0aa77e */
if(!s->budget--) { s->failed_pc=0x0c0aa77eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0aa786;
P_0c0aa780: /* original f608, guest PC 0x0c0aa780 */
if(!s->budget--) { s->failed_pc=0x0c0aa780u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0aa782;
P_0c0aa782: /* original c72c, guest PC 0x0c0aa782 */
if(!s->budget--) { s->failed_pc=0x0c0aa782u; return 0; }
r[0]=0x0c0aa834u;
goto P_0c0aa784;
P_0c0aa784: /* original f608, guest PC 0x0c0aa784 */
if(!s->budget--) { s->failed_pc=0x0c0aa784u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0aa786;
P_0c0aa786: /* original f37c, guest PC 0x0c0aa786 */
if(!s->budget--) { s->failed_pc=0x0c0aa786u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0aa788;
P_0c0aa788: /* original f562, guest PC 0x0c0aa788 */
if(!s->budget--) { s->failed_pc=0x0c0aa788u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0aa78a;
P_0c0aa78a: /* original f76c, guest PC 0x0c0aa78a */
if(!s->budget--) { s->failed_pc=0x0c0aa78au; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c0aa78c;
P_0c0aa78c: /* original f732, guest PC 0x0c0aa78c */
if(!s->budget--) { s->failed_pc=0x0c0aa78cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0aa78e;
P_0c0aa78e: /* original 7f10, guest PC 0x0c0aa78e */
if(!s->budget--) { s->failed_pc=0x0c0aa78eu; return 0; }
r[15]+=0x00000010u;
goto P_0c0aa790;
P_0c0aa790: /* original e024, guest PC 0x0c0aa790 */
if(!s->budget--) { s->failed_pc=0x0c0aa790u; return 0; }
r[0]=0x00000024u;
goto P_0c0aa792;
P_0c0aa792: /* original f850, guest PC 0x0c0aa792 */
if(!s->budget--) { s->failed_pc=0x0c0aa792u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'+');
goto P_0c0aa794;
P_0c0aa794: /* original f470, guest PC 0x0c0aa794 */
if(!s->budget--) { s->failed_pc=0x0c0aa794u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c0aa796;
P_0c0aa796: /* original 4f26, guest PC 0x0c0aa796 */
if(!s->budget--) { s->failed_pc=0x0c0aa796u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa798;
P_0c0aa798: /* original fe87, guest PC 0x0c0aa798 */
if(!s->budget--) { s->failed_pc=0x0c0aa798u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c0aa79a;
P_0c0aa79a: /* original e02c, guest PC 0x0c0aa79a */
if(!s->budget--) { s->failed_pc=0x0c0aa79au; return 0; }
r[0]=0x0000002cu;
goto P_0c0aa79c;
P_0c0aa79c: /* original fe47, guest PC 0x0c0aa79c */
if(!s->budget--) { s->failed_pc=0x0c0aa79cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0aa79e;
P_0c0aa79e: /* original 000b, guest PC 0x0c0aa79e */
if(!s->budget--) { s->failed_pc=0x0c0aa79eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aa7a0: /* original 6ef6, guest PC 0x0c0aa7a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aa7a2u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03b530u,0x0c03b532u,0x0c03b534u,0x0c03b536u,0x0c03b538u,0x0c03b53au,0x0c03b53cu,0x0c03b53eu,0x0c03b540u,0x0c03b542u,0x0c03b550u,0x0c03b552u,0x0c03b554u,0x0c03b556u,0x0c03b558u,0x0c03b560u,
0x0c03b562u,0x0c03b564u,0x0c03b566u,0x0c03b568u,0x0c03b56au,0x0c03b56cu,0x0c03b56eu,0x0c03b570u,0x0c03b572u,0x0c03c4a0u,0x0c03c4a2u,0x0c03c4a4u,0x0c03c4a6u,0x0c03c4a8u,0x0c03c4aau,0x0c03c4acu,
0x0c03c4aeu,0x0c03c4b0u,0x0c03c4b2u,0x0c03c4b4u,0x0c03c4b6u,0x0c03c4b8u,0x0c03c4bau,0x0c03c4bcu,0x0c03c4beu,0x0c03c4c0u,0x0c03c4c2u,0x0c03c4c4u,0x0c03c4c6u,0x0c03c4c8u,0x0c03c4cau,0x0c03c4ccu,
0x0c03c4ceu,0x0c03c4d0u,0x0c03c4d2u,0x0c03c4d4u,0x0c03c4d6u,0x0c03c4d8u,0x0c03c4dau,0x0c03c4dcu,0x0c03c4deu,0x0c042d7cu,0x0c042d7eu,0x0c042d80u,0x0c042d82u,0x0c042d84u,0x0c042d86u,0x0c042d88u,
0x0c042d8au,0x0c042d8cu,0x0c042d8eu,0x0c042d90u,0x0c042d92u,0x0c042d94u,0x0c042d96u,0x0c042d98u,0x0c042d9au,0x0c042d9cu,0x0c042d9eu,0x0c042da0u,0x0c042da2u,0x0c042da4u,0x0c042da6u,0x0c042da8u,
0x0c042daau,0x0c042dacu,0x0c042daeu,0x0c042db0u,0x0c042db2u,0x0c042db4u,0x0c042db6u,0x0c042db8u,0x0c042dbau,0x0c042dbcu,0x0c042dbeu,0x0c042dc0u,0x0c042dc2u,0x0c042dc4u,0x0c042dc6u,0x0c042dc8u,
0x0c042dcau,0x0c042dccu,0x0c042dceu,0x0c042dd0u,0x0c042dd2u,0x0c042dd4u,0x0c042dd6u,0x0c042dd8u,0x0c042ddau,0x0c042ddcu,0x0c042ddeu,0x0c042de0u,0x0c042de2u,0x0c042de4u,0x0c042de6u,0x0c042de8u,
0x0c042deau,0x0c042decu,0x0c042deeu,0x0c042df0u,0x0c042df2u,0x0c042df4u,0x0c042df6u,0x0c042df8u,0x0c042dfau,0x0c042dfcu,0x0c042dfeu,0x0c042e00u,0x0c042e02u,0x0c042e04u,0x0c042e06u,0x0c042e08u,
0x0c042e0au,0x0c042e0cu,0x0c042e0eu,0x0c042e10u,0x0c042e12u,0x0c042e14u,0x0c042e16u,0x0c042e18u,0x0c042e1au,0x0c042e1cu,0x0c042e1eu,0x0c042e20u,0x0c042e22u,0x0c042e24u,0x0c042e26u,0x0c042e28u,
0x0c042e2au,0x0c042e2cu,0x0c042e2eu,0x0c042e30u,0x0c042e32u,0x0c042e34u,0x0c042e36u,0x0c042e38u,0x0c042e3au,0x0c068d54u,0x0c068d56u,0x0c068d58u,0x0c068d5au,0x0c068d5cu,0x0c068d5eu,0x0c068d60u,
0x0c068d62u,0x0c068d64u,0x0c068d66u,0x0c068d68u,0x0c068d6au,0x0c068d6cu,0x0c068d6eu,0x0c068d70u,0x0c068d72u,0x0c068d74u,0x0c068d76u,0x0c068d78u,0x0c068d7au,0x0c068d7cu,0x0c068d7eu,0x0c068d80u,
0x0c068d82u,0x0c068d84u,0x0c068d86u,0x0c068d88u,0x0c068d8au,0x0c068d8cu,0x0c068d8eu,0x0c068d90u,0x0c068d92u,0x0c068d94u,0x0c068d96u,0x0c068d98u,0x0c068d9au,0x0c068d9cu,0x0c068d9eu,0x0c068da0u,
0x0c068da2u,0x0c068da4u,0x0c068da6u,0x0c068da8u,0x0c068daau,0x0c068dacu,0x0c068daeu,0x0c068db0u,0x0c068db2u,0x0c068db4u,0x0c068db6u,0x0c068db8u,0x0c068dbau,0x0c068dbcu,0x0c068dbeu,0x0c068dc0u,
0x0c068dc2u,0x0c068dc4u,0x0c068dc6u,0x0c068dc8u,0x0c068dcau,0x0c068dccu,0x0c068dceu,0x0c068dd0u,0x0c068dd2u,0x0c068dd4u,0x0c068dd6u,0x0c068dd8u,0x0c068ddau,0x0c068ddcu,0x0c068ddeu,0x0c068de0u,
0x0c068de2u,0x0c068de4u,0x0c068de6u,0x0c068de8u,0x0c068deau,0x0c068decu,0x0c068deeu,0x0c068df0u,0x0c068df2u,0x0c068df4u,0x0c068df6u,0x0c068df8u,0x0c068dfau,0x0c068dfcu,0x0c068dfeu,0x0c068e00u,
0x0c068e02u,0x0c068e04u,0x0c068e06u,0x0c068e08u,0x0c068e0au,0x0c068e0cu,0x0c068f92u,0x0c068f94u,0x0c068f96u,0x0c068f98u,0x0c068f9au,0x0c068f9cu,0x0c068f9eu,0x0c068fa0u,0x0c068fa2u,0x0c068fa4u,
0x0c068fa6u,0x0c068fa8u,0x0c068faau,0x0c068facu,0x0c068faeu,0x0c068fb0u,0x0c068fb2u,0x0c068fb4u,0x0c068fb6u,0x0c068fb8u,0x0c068fbau,0x0c068fbcu,0x0c068fbeu,0x0c068fc0u,0x0c068fc2u,0x0c068fc4u,
0x0c068fc6u,0x0c068fe4u,0x0c068fe6u,0x0c068fe8u,0x0c068feau,0x0c068fecu,0x0c068feeu,0x0c068ff0u,0x0c068ff2u,0x0c068ff4u,0x0c068ff6u,0x0c068ff8u,0x0c068ffau,0x0c068ffcu,0x0c068ffeu,0x0c069000u,
0x0c069002u,0x0c069004u,0x0c069006u,0x0c069008u,0x0c06900au,0x0c06900cu,0x0c06900eu,0x0c069010u,0x0c069012u,0x0c069014u,0x0c069016u,0x0c069018u,0x0c06901au,0x0c06901cu,0x0c06901eu,0x0c069020u,
0x0c069022u,0x0c069024u,0x0c069026u,0x0c069028u,0x0c06902au,0x0c06902cu,0x0c06902eu,0x0c069030u,0x0c069032u,0x0c069034u,0x0c069036u,0x0c069038u,0x0c06903au,0x0c06903cu,0x0c06903eu,0x0c069040u,
0x0c069042u,0x0c069044u,0x0c069046u,0x0c069048u,0x0c06904au,0x0c06904cu,0x0c06904eu,0x0c069050u,0x0c069052u,0x0c069054u,0x0c069056u,0x0c069058u,0x0c06905au,0x0c06905cu,0x0c06905eu,0x0c069060u,
0x0c069062u,0x0c069064u,0x0c069066u,0x0c069068u,0x0c06906au,0x0c06906cu,0x0c06906eu,0x0c069070u,0x0c069072u,0x0c069074u,0x0c069076u,0x0c069078u,0x0c06907au,0x0c06907cu,0x0c06907eu,0x0c069080u,
0x0c069082u,0x0c069084u,0x0c069086u,0x0c069088u,0x0c06908au,0x0c06908cu,0x0c06908eu,0x0c069090u,0x0c069092u,0x0c069094u,0x0c069096u,0x0c069098u,0x0c06909au,0x0c06909cu,0x0c06909eu,0x0c0690a0u,
0x0c0690a2u,0x0c0690a4u,0x0c0690a6u,0x0c0690a8u,0x0c0690aau,0x0c0690acu,0x0c0690aeu,0x0c0690b0u,0x0c0690b2u,0x0c0690b4u,0x0c0690b6u,0x0c0690b8u,0x0c0690bau,0x0c0690bcu,0x0c0690beu,0x0c0690c0u,
0x0c0690c2u,0x0c0690c4u,0x0c0690c6u,0x0c0690c8u,0x0c0690cau,0x0c0690ccu,0x0c0690ceu,0x0c0690d0u,0x0c0690d2u,0x0c0690d4u,0x0c0690d6u,0x0c0690d8u,0x0c0690dau,0x0c0690dcu,0x0c0690deu,0x0c0690e0u,
0x0c0690e2u,0x0c0690e4u,0x0c0690e6u,0x0c0690e8u,0x0c0690eau,0x0c0690ecu,0x0c0690eeu,0x0c0690f0u,0x0c0690f2u,0x0c0690f4u,0x0c0690f6u,0x0c0690f8u,0x0c0690fau,0x0c0690fcu,0x0c0690feu,0x0c069100u,
0x0c069102u,0x0c069104u,0x0c069106u,0x0c069108u,0x0c06910au,0x0c06910cu,0x0c06910eu,0x0c069110u,0x0c069112u,0x0c069114u,0x0c06911cu,0x0c06911eu,0x0c069120u,0x0c069122u,0x0c069124u,0x0c069126u,
0x0c069128u,0x0c06912au,0x0c06912cu,0x0c06912eu,0x0c069130u,0x0c069132u,0x0c069134u,0x0c069136u,0x0c069138u,0x0c06913au,0x0c06913cu,0x0c06913eu,0x0c069140u,0x0c069142u,0x0c069144u,0x0c069146u,
0x0c069148u,0x0c06914au,0x0c06914cu,0x0c06914eu,0x0c069150u,0x0c069152u,0x0c069154u,0x0c069156u,0x0c069158u,0x0c06915au,0x0c06915cu,0x0c06915eu,0x0c069160u,0x0c069162u,0x0c069164u,0x0c069166u,
0x0c069168u,0x0c06916au,0x0c06916cu,0x0c06916eu,0x0c069170u,0x0c069172u,0x0c069174u,0x0c069176u,0x0c069178u,0x0c06917au,0x0c06917cu,0x0c06917eu,0x0c069180u,0x0c069182u,0x0c069184u,0x0c069186u,
0x0c069188u,0x0c06918au,0x0c06918cu,0x0c06918eu,0x0c069190u,0x0c069192u,0x0c069194u,0x0c069196u,0x0c069198u,0x0c06919au,0x0c06919cu,0x0c06919eu,0x0c0691a0u,0x0c0691a2u,0x0c0691a4u,0x0c0691a6u,
0x0c0691a8u,0x0c0691aau,0x0c0691acu,0x0c0691aeu,0x0c0691b0u,0x0c0691b2u,0x0c0691b4u,0x0c0691b6u,0x0c0691b8u,0x0c0691bau,0x0c0691bcu,0x0c0691beu,0x0c0691c0u,0x0c0691c2u,0x0c0691c4u,0x0c0691c6u,
0x0c0691c8u,0x0c0691cau,0x0c0691ccu,0x0c0691ceu,0x0c0691d0u,0x0c0691d2u,0x0c0691d4u,0x0c0691d6u,0x0c0691d8u,0x0c0691dau,0x0c0691dcu,0x0c0691deu,0x0c0691e0u,0x0c0691e2u,0x0c0691e4u,0x0c0691e6u,
0x0c0691e8u,0x0c0691eau,0x0c0691ecu,0x0c0691eeu,0x0c0691f0u,0x0c0691f2u,0x0c0691f4u,0x0c0691f6u,0x0c0691f8u,0x0c0691fau,0x0c0691fcu,0x0c0691feu,0x0c069200u,0x0c069202u,0x0c069204u,0x0c069206u,
0x0c069208u,0x0c06920au,0x0c06920cu,0x0c06920eu,0x0c069210u,0x0c069212u,0x0c069214u,0x0c069216u,0x0c069218u,0x0c06921au,0x0c06921cu,0x0c06923cu,0x0c06923eu,0x0c069240u,0x0c069242u,0x0c069244u,
0x0c069246u,0x0c069248u,0x0c06924au,0x0c06924cu,0x0c06924eu,0x0c069250u,0x0c069252u,0x0c069254u,0x0c069256u,0x0c069258u,0x0c06925au,0x0c06925cu,0x0c06925eu,0x0c069260u,0x0c069262u,0x0c069264u,
0x0c069266u,0x0c069268u,0x0c06926au,0x0c06926cu,0x0c06926eu,0x0c069270u,0x0c069272u,0x0c069274u,0x0c069276u,0x0c069278u,0x0c06927au,0x0c06927cu,0x0c06927eu,0x0c069280u,0x0c069282u,0x0c069284u,
0x0c069286u,0x0c069288u,0x0c06928au,0x0c06928cu,0x0c06928eu,0x0c069290u,0x0c069292u,0x0c069294u,0x0c069296u,0x0c069298u,0x0c06929au,0x0c06929cu,0x0c06929eu,0x0c0692a0u,0x0c0692a2u,0x0c0692a4u,
0x0c06f6aeu,0x0c06f6b0u,0x0c06f6b2u,0x0c06f6b4u,0x0c06f6b6u,0x0c06f6b8u,0x0c06f6bau,0x0c06f6bcu,0x0c06f6beu,0x0c06f6c0u,0x0c06f6c2u,0x0c06f6c4u,0x0c06f6c6u,0x0c06f6c8u,0x0c06f6cau,0x0c06f6ccu,
0x0c06f6ceu,0x0c06f6d0u,0x0c06f6e0u,0x0c06f6e2u,0x0c06f6e4u,0x0c06f6e6u,0x0c06f6e8u,0x0c06f6eau,0x0c06f6ecu,0x0c06f6eeu,0x0c06f6f0u,0x0c06f6f2u,0x0c06f6f4u,0x0c06f6f6u,0x0c06f6f8u,0x0c06f6fau,
0x0c06f6fcu,0x0c06f6feu,0x0c06f700u,0x0c06f702u,0x0c06f704u,0x0c06f706u,0x0c06f708u,0x0c06f70au,0x0c06f70cu,0x0c06f70eu,0x0c06f710u,0x0c06f712u,0x0c06f714u,0x0c06f716u,0x0c06f718u,0x0c06f71au,
0x0c06f71cu,0x0c06f71eu,0x0c06f720u,0x0c06f722u,0x0c06f724u,0x0c06f726u,0x0c06f728u,0x0c06f72au,0x0c06f72cu,0x0c06f72eu,0x0c06f730u,0x0c06f732u,0x0c06f734u,0x0c06f740u,0x0c06f742u,0x0c06f744u,
0x0c06f746u,0x0c06f748u,0x0c06f74au,0x0c06f74cu,0x0c06f74eu,0x0c06f750u,0x0c06f752u,0x0c06f754u,0x0c06f756u,0x0c06f758u,0x0c06f75au,0x0c06f75cu,0x0c06f75eu,0x0c06f760u,0x0c06f762u,0x0c06f764u,
0x0c06f766u,0x0c06f768u,0x0c06f76au,0x0c06f76cu,0x0c06f76eu,0x0c06f770u,0x0c06f772u,0x0c06f774u,0x0c06f776u,0x0c06f778u,0x0c06f77au,0x0c06f77cu,0x0c06f77eu,0x0c06f780u,0x0c06f782u,0x0c06f784u,
0x0c06f786u,0x0c06f788u,0x0c06f78au,0x0c06f78cu,0x0c06f78eu,0x0c06f790u,0x0c06f792u,0x0c06f794u,0x0c06f796u,0x0c06f798u,0x0c06f79au,0x0c06f79cu,0x0c06f79eu,0x0c06f7a0u,0x0c06f7a2u,0x0c06f7a4u,
0x0c06f7a6u,0x0c06f7a8u,0x0c06f7aau,0x0c06f7acu,0x0c06f7aeu,0x0c06f7b0u,0x0c06f7b2u,0x0c06f7b4u,0x0c06f7b6u,0x0c06f7b8u,0x0c06f7bau,0x0c06f7bcu,0x0c06f7beu,0x0c06f7c0u,0x0c06f7c2u,0x0c06f7c4u,
0x0c06f7c6u,0x0c06f7c8u,0x0c06f7cau,0x0c06f7ccu,0x0c06f7ceu,0x0c06f7d0u,0x0c06f7d2u,0x0c06f7d4u,0x0c06f7d6u,0x0c06f7d8u,0x0c06f7dau,0x0c06f7dcu,0x0c06f7deu,0x0c06f7e0u,0x0c06f7e2u,0x0c06f7e4u,
0x0c06f7e6u,0x0c06f7e8u,0x0c06f7eau,0x0c06f7ecu,0x0c06f7eeu,0x0c06f7f0u,0x0c06f7f2u,0x0c06f7f4u,0x0c06f7f6u,0x0c06f7f8u,0x0c06f7fau,0x0c06f7fcu,0x0c06f7feu,0x0c06f800u,0x0c06f802u,0x0c06f804u,
0x0c06f806u,0x0c06f808u,0x0c06f80au,0x0c06f80cu,0x0c06f80eu,0x0c06f810u,0x0c06f812u,0x0c06f814u,0x0c06f816u,0x0c06f818u,0x0c06f81au,0x0c06f81cu,0x0c06f81eu,0x0c06f820u,0x0c06f822u,0x0c06f824u,
0x0c06f826u,0x0c06f828u,0x0c06f82au,0x0c06f82cu,0x0c06f82eu,0x0c06f830u,0x0c06f832u,0x0c06f834u,0x0c06f836u,0x0c06f838u,0x0c06f83au,0x0c06f83cu,0x0c06f83eu,0x0c06f840u,0x0c06f842u,0x0c06f844u,
0x0c06f846u,0x0c06f848u,0x0c06f84au,0x0c06f84cu,0x0c06f84eu,0x0c06f850u,0x0c06f852u,0x0c06f854u,0x0c06f856u,0x0c06f858u,0x0c06f85au,0x0c06f85cu,0x0c06f85eu,0x0c06f860u,0x0c06f862u,0x0c06f864u,
0x0c06f866u,0x0c06f868u,0x0c06f86au,0x0c06f86cu,0x0c06f86eu,0x0c06f870u,0x0c06f872u,0x0c06f874u,0x0c06f876u,0x0c06f878u,0x0c06f87au,0x0c06f87cu,0x0c06f87eu,0x0c06f880u,0x0c06f882u,0x0c06f884u,
0x0c06f886u,0x0c06f888u,0x0c06f88au,0x0c06f88cu,0x0c06f88eu,0x0c06f890u,0x0c06f892u,0x0c06f894u,0x0c06f896u,0x0c06f898u,0x0c06f89au,0x0c06f89cu,0x0c06f89eu,0x0c06f8a0u,0x0c06f8a2u,0x0c06f8a4u,
0x0c06f8a6u,0x0c06f8a8u,0x0c06f8aau,0x0c06f8acu,0x0c06f8aeu,0x0c06f8b0u,0x0c06f8b2u,0x0c06f8b4u,0x0c06f8b6u,0x0c06f8b8u,0x0c06f8bau,0x0c06f8bcu,0x0c06f8beu,0x0c06f8c0u,0x0c06f8c2u,0x0c06f8c4u,
0x0c06f8c6u,0x0c06f8c8u,0x0c06f8cau,0x0c06f8ccu,0x0c06f8ceu,0x0c06f8d0u,0x0c06f8d2u,0x0c06f8d4u,0x0c06f8d6u,0x0c06f8d8u,0x0c06f8dau,0x0c06f8dcu,0x0c06f8deu,0x0c06f8e0u,0x0c06f8e2u,0x0c06f8e4u,
0x0c06f8e6u,0x0c06f8e8u,0x0c06f8eau,0x0c06f8ecu,0x0c06f8eeu,0x0c06f8f0u,0x0c06f8f2u,0x0c06f8f4u,0x0c06f8f6u,0x0c06f8f8u,0x0c06f8fau,0x0c06f8fcu,0x0c06f8feu,0x0c06f900u,0x0c06f902u,0x0c06f904u,
0x0c06f906u,0x0c06f908u,0x0c06f90au,0x0c06f90cu,0x0c06f90eu,0x0c06f910u,0x0c06f912u,0x0c06f914u,0x0c06f916u,0x0c06f918u,0x0c06f91au,0x0c06f91cu,0x0c06f91eu,0x0c06f920u,0x0c06f922u,0x0c06f924u,
0x0c06f926u,0x0c06f928u,0x0c06f92au,0x0c06f92cu,0x0c06f92eu,0x0c06f930u,0x0c06f932u,0x0c06f934u,0x0c06f936u,0x0c06f938u,0x0c06f93au,0x0c06f93cu,0x0c06f93eu,0x0c06f940u,0x0c06f942u,0x0c06f944u,
0x0c06f946u,0x0c06f948u,0x0c06f94au,0x0c06f94cu,0x0c06f94eu,0x0c06f950u,0x0c06f952u,0x0c06f954u,0x0c06f956u,0x0c06f958u,0x0c06f95au,0x0c06f95cu,0x0c06f95eu,0x0c06f960u,0x0c06f962u,0x0c06f964u,
0x0c06f966u,0x0c06f968u,0x0c06f96au,0x0c06f96cu,0x0c06f96eu,0x0c06f970u,0x0c06f972u,0x0c06f974u,0x0c06f976u,0x0c06f978u,0x0c06f97au,0x0c06f97cu,0x0c06f97eu,0x0c06f980u,0x0c06f982u,0x0c06f984u,
0x0c06f986u,0x0c06f988u,0x0c06f98au,0x0c06f98cu,0x0c06f98eu,0x0c06f990u,0x0c070008u,0x0c07000au,0x0c07000cu,0x0c07000eu,0x0c070010u,0x0c070012u,0x0c070014u,0x0c070016u,0x0c070018u,0x0c07001au,
0x0c07001cu,0x0c07001eu,0x0c070020u,0x0c070022u,0x0c070024u,0x0c070026u,0x0c070028u,0x0c07002au,0x0c07002cu,0x0c07002eu,0x0c070030u,0x0c070032u,0x0c070034u,0x0c070036u,0x0c070038u,0x0c07003au,
0x0c07003cu,0x0c07003eu,0x0c070040u,0x0c070042u,0x0c070044u,0x0c070046u,0x0c070048u,0x0c07004au,0x0c07004cu,0x0c07004eu,0x0c070050u,0x0c070052u,0x0c070054u,0x0c070056u,0x0c070058u,0x0c07005au,
0x0c07005cu,0x0c07005eu,0x0c070060u,0x0c070088u,0x0c07008au,0x0c07008cu,0x0c07008eu,0x0c070090u,0x0c070092u,0x0c070094u,0x0c070096u,0x0c070098u,0x0c07009au,0x0c07009cu,0x0c07009eu,0x0c0700a0u,
0x0c0700a2u,0x0c0700a4u,0x0c0700a6u,0x0c0700a8u,0x0c0700aau,0x0c0700acu,0x0c0700aeu,0x0c0700b0u,0x0c0700b2u,0x0c0700b4u,0x0c0700b6u,0x0c0700b8u,0x0c0700bau,0x0c0700bcu,0x0c0700beu,0x0c0700c0u,
0x0c0700c2u,0x0c0700c4u,0x0c0700c6u,0x0c0700c8u,0x0c0700cau,0x0c0700ccu,0x0c0700ceu,0x0c0700d0u,0x0c0700d2u,0x0c0700d4u,0x0c0700d6u,0x0c0700d8u,0x0c0700dau,0x0c0700dcu,0x0c0700deu,0x0c0700e0u,
0x0c0700e2u,0x0c0700e4u,0x0c0700e6u,0x0c0700e8u,0x0c0700eau,0x0c0700ecu,0x0c0700eeu,0x0c0700f0u,0x0c0700f2u,0x0c0700f4u,0x0c0700f6u,0x0c0700f8u,0x0c0700fau,0x0c070108u,0x0c07010au,0x0c07010cu,
0x0c07010eu,0x0c070110u,0x0c070112u,0x0c070114u,0x0c070116u,0x0c070118u,0x0c07011au,0x0c07011cu,0x0c07011eu,0x0c070120u,0x0c070122u,0x0c070124u,0x0c070126u,0x0c070128u,0x0c07012au,0x0c07012cu,
0x0c07012eu,0x0c070130u,0x0c070132u,0x0c070134u,0x0c070136u,0x0c070138u,0x0c07013au,0x0c07013cu,0x0c07013eu,0x0c070140u,0x0c070142u,0x0c070144u,0x0c070146u,0x0c070148u,0x0c07014au,0x0c07014cu,
0x0c07014eu,0x0c070154u,0x0c070156u,0x0c070158u,0x0c07015au,0x0c07015cu,0x0c07015eu,0x0c070160u,0x0c070162u,0x0c070164u,0x0c070166u,0x0c070168u,0x0c07016au,0x0c07016cu,0x0c07016eu,0x0c070170u,
0x0c070172u,0x0c070174u,0x0c070176u,0x0c070178u,0x0c07017au,0x0c07017cu,0x0c07017eu,0x0c070180u,0x0c070182u,0x0c070184u,0x0c070186u,0x0c070188u,0x0c07018au,0x0c07018cu,0x0c07018eu,0x0c070190u,
0x0c070192u,0x0c070194u,0x0c070196u,0x0c070198u,0x0c07019au,0x0c0701a0u,0x0c0701a2u,0x0c0701a4u,0x0c0701a6u,0x0c0701a8u,0x0c0701aau,0x0c0701acu,0x0c0701aeu,0x0c0701b0u,0x0c0701b2u,0x0c0701b4u,
0x0c0701b6u,0x0c0701b8u,0x0c0701bau,0x0c0701bcu,0x0c0701beu,0x0c0701c0u,0x0c0701c2u,0x0c0701c4u,0x0c0701c6u,0x0c0701c8u,0x0c0701cau,0x0c0701ccu,0x0c0701ceu,0x0c0701d0u,0x0c0701d2u,0x0c0701d4u,
0x0c0701d6u,0x0c0701d8u,0x0c0701dau,0x0c0701e4u,0x0c0701e6u,0x0c0701e8u,0x0c0701eau,0x0c0701ecu,0x0c0701eeu,0x0c0701f0u,0x0c0701f2u,0x0c0701f4u,0x0c0701f6u,0x0c0701f8u,0x0c0701fau,0x0c0701fcu,
0x0c0701feu,0x0c070200u,0x0c070202u,0x0c070204u,0x0c070206u,0x0c070208u,0x0c07020au,0x0c07020cu,0x0c07020eu,0x0c070210u,0x0c070212u,0x0c070214u,0x0c070216u,0x0c070218u,0x0c07021au,0x0c07021cu,
0x0c07021eu,0x0c070220u,0x0c070222u,0x0c070224u,0x0c070226u,0x0c070228u,0x0c07022au,0x0c07022cu,0x0c07022eu,0x0c070230u,0x0c070232u,0x0c070234u,0x0c070236u,0x0c070238u,0x0c070240u,0x0c070242u,
0x0c070244u,0x0c070246u,0x0c070248u,0x0c07024au,0x0c07024cu,0x0c07024eu,0x0c070250u,0x0c070252u,0x0c070254u,0x0c070256u,0x0c070258u,0x0c07025au,0x0c07025cu,0x0c07025eu,0x0c070260u,0x0c070262u,
0x0c070264u,0x0c070266u,0x0c070268u,0x0c07026au,0x0c07026cu,0x0c07026eu,0x0c070270u,0x0c070272u,0x0c070274u,0x0c070276u,0x0c070278u,0x0c07027au,0x0c07027cu,0x0c07027eu,0x0c070280u,0x0c070282u,
0x0c070284u,0x0c070286u,0x0c070288u,0x0c07028au,0x0c07028cu,0x0c07028eu,0x0c070290u,0x0c070292u,0x0c070294u,0x0c070296u,0x0c070298u,0x0c07029au,0x0c07029cu,0x0c07029eu,0x0c0702a0u,0x0c0702a2u,
0x0c0702a4u,0x0c0702a6u,0x0c0702a8u,0x0c0702aau,0x0c0702acu,0x0c0702aeu,0x0c0702b0u,0x0c0702b2u,0x0c0702b4u,0x0c0702b6u,0x0c0702b8u,0x0c0702bau,0x0c0702bcu,0x0c0702beu,0x0c0702c0u,0x0c0702c2u,
0x0c0702c4u,0x0c0702c6u,0x0c0702c8u,0x0c0702cau,0x0c0702ccu,0x0c0702ceu,0x0c0702d0u,0x0c0702d2u,0x0c0702d4u,0x0c0702d6u,0x0c0702d8u,0x0c0702dau,0x0c0702dcu,0x0c0702deu,0x0c0702e0u,0x0c0702e2u,
0x0c0702e4u,0x0c0702e6u,0x0c0702e8u,0x0c0702eau,0x0c0702ecu,0x0c0702eeu,0x0c0702f0u,0x0c0702f2u,0x0c0702f4u,0x0c0702f6u,0x0c0702f8u,0x0c0702fau,0x0c0702fcu,0x0c0702feu,0x0c070300u,0x0c070302u,
0x0c070304u,0x0c070306u,0x0c070308u,0x0c07030au,0x0c07030cu,0x0c07030eu,0x0c070310u,0x0c070312u,0x0c070314u,0x0c070316u,0x0c070318u,0x0c07031au,0x0c07031cu,0x0c07031eu,0x0c070320u,0x0c070322u,
0x0c070324u,0x0c070326u,0x0c070328u,0x0c07032au,0x0c07032cu,0x0c07032eu,0x0c070330u,0x0c070332u,0x0c070334u,0x0c070336u,0x0c070338u,0x0c07033au,0x0c07033cu,0x0c070344u,0x0c070346u,0x0c070348u,
0x0c07034au,0x0c07034cu,0x0c07034eu,0x0c070350u,0x0c070352u,0x0c070354u,0x0c070356u,0x0c070358u,0x0c07035au,0x0c07035cu,0x0c07035eu,0x0c070360u,0x0c070362u,0x0c070364u,0x0c070366u,0x0c070368u,
0x0c07036au,0x0c07036cu,0x0c07036eu,0x0c070370u,0x0c070372u,0x0c070374u,0x0c070376u,0x0c070378u,0x0c07037au,0x0c07037cu,0x0c07037eu,0x0c070380u,0x0c070382u,0x0c070384u,0x0c070386u,0x0c070388u,
0x0c070390u,0x0c070392u,0x0c070394u,0x0c070396u,0x0c070398u,0x0c07039au,0x0c07039cu,0x0c07039eu,0x0c0703a0u,0x0c0703a2u,0x0c0703a4u,0x0c0703a6u,0x0c0703a8u,0x0c0703aau,0x0c0703acu,0x0c0703aeu,
0x0c0703b0u,0x0c0703b2u,0x0c0703b4u,0x0c0703b6u,0x0c0703b8u,0x0c0703bau,0x0c0703bcu,0x0c0703beu,0x0c0703c0u,0x0c0703c2u,0x0c0703c4u,0x0c0703c6u,0x0c0703c8u,0x0c0703cau,0x0c0703ccu,0x0c0703d8u,
0x0c0703dau,0x0c0703dcu,0x0c0703deu,0x0c0703e0u,0x0c0703e2u,0x0c0703e4u,0x0c0703e6u,0x0c0703e8u,0x0c0703eau,0x0c0703ecu,0x0c0703eeu,0x0c0703f0u,0x0c0703f2u,0x0c0703f4u,0x0c0703f6u,0x0c0703f8u,
0x0c0703fau,0x0c0703fcu,0x0c0703feu,0x0c070400u,0x0c070402u,0x0c070404u,0x0c070406u,0x0c070408u,0x0c07040au,0x0c07040cu,0x0c070418u,0x0c07041au,0x0c07041cu,0x0c07041eu,0x0c070420u,0x0c070422u,
0x0c070424u,0x0c070426u,0x0c070428u,0x0c07042au,0x0c07042cu,0x0c07042eu,0x0c070430u,0x0c070432u,0x0c070434u,0x0c070436u,0x0c070438u,0x0c07043au,0x0c07043cu,0x0c07043eu,0x0c070440u,0x0c070442u,
0x0c070444u,0x0c070446u,0x0c070448u,0x0c07044au,0x0c07044cu,0x0c07044eu,0x0c070450u,0x0c070452u,0x0c070454u,0x0c070456u,0x0c070458u,0x0c07045au,0x0c07045cu,0x0c07045eu,0x0c070460u,0x0c070462u,
0x0c070464u,0x0c070466u,0x0c070468u,0x0c07046au,0x0c07046cu,0x0c07046eu,0x0c070470u,0x0c070472u,0x0c070474u,0x0c070476u,0x0c070478u,0x0c07047au,0x0c07047cu,0x0c07047eu,0x0c070480u,0x0c070482u,
0x0c070484u,0x0c070486u,0x0c070488u,0x0c07048au,0x0c07048cu,0x0c07048eu,0x0c070490u,0x0c070492u,0x0c070494u,0x0c070496u,0x0c070498u,0x0c07049au,0x0c07049cu,0x0c07049eu,0x0c0704a0u,0x0c0704a2u,
0x0c0704a4u,0x0c0704a6u,0x0c0704a8u,0x0c0704aau,0x0c0704acu,0x0c0704aeu,0x0c0704b0u,0x0c0704b2u,0x0c0704b4u,0x0c0704b6u,0x0c0704b8u,0x0c0704bau,0x0c0704bcu,0x0c0704beu,0x0c0704c0u,0x0c0704c2u,
0x0c0704c4u,0x0c0704c6u,0x0c0704c8u,0x0c0704cau,0x0c0704ccu,0x0c0704ceu,0x0c0704d0u,0x0c0704d2u,0x0c0704d4u,0x0c0704d6u,0x0c0704dcu,0x0c0704deu,0x0c0704e0u,0x0c0704e2u,0x0c0704e4u,0x0c0704e6u,
0x0c0704e8u,0x0c0704eau,0x0c0704ecu,0x0c0704eeu,0x0c0704f0u,0x0c0704f2u,0x0c0704f4u,0x0c0704f6u,0x0c0704f8u,0x0c0704fau,0x0c0704fcu,0x0c0704feu,0x0c070500u,0x0c070502u,0x0c070504u,0x0c070506u,
0x0c070508u,0x0c07050au,0x0c07050cu,0x0c07050eu,0x0c070510u,0x0c070512u,0x0c070514u,0x0c070516u,0x0c070518u,0x0c07051au,0x0c07051cu,0x0c07051eu,0x0c070520u,0x0c070522u,0x0c070528u,0x0c07052au,
0x0c07052cu,0x0c07052eu,0x0c070530u,0x0c070532u,0x0c070534u,0x0c070536u,0x0c070538u,0x0c07053au,0x0c07053cu,0x0c07053eu,0x0c070540u,0x0c070542u,0x0c070544u,0x0c070546u,0x0c070548u,0x0c07054au,
0x0c07054cu,0x0c07054eu,0x0c070550u,0x0c070552u,0x0c070554u,0x0c070556u,0x0c070558u,0x0c07055au,0x0c07055cu,0x0c07055eu,0x0c070560u,0x0c070562u,0x0c070564u,0x0c070566u,0x0c070568u,0x0c07056au,
0x0c07056cu,0x0c07056eu,0x0c070574u,0x0c070576u,0x0c070578u,0x0c07057au,0x0c07057cu,0x0c07057eu,0x0c070580u,0x0c070582u,0x0c070584u,0x0c070586u,0x0c070588u,0x0c07058au,0x0c07058cu,0x0c07058eu,
0x0c070590u,0x0c070592u,0x0c070594u,0x0c070596u,0x0c070598u,0x0c07059au,0x0c07059cu,0x0c07059eu,0x0c0705a0u,0x0c0705a2u,0x0c0705a4u,0x0c0705a6u,0x0c0705a8u,0x0c0705aau,0x0c0705acu,0x0c0705b8u,
0x0c0705bau,0x0c0705bcu,0x0c0705beu,0x0c0705c0u,0x0c0705c2u,0x0c0705c4u,0x0c0705c6u,0x0c0705c8u,0x0c0705cau,0x0c0705ccu,0x0c0705ceu,0x0c0705d0u,0x0c0705d2u,0x0c0705d4u,0x0c0705d6u,0x0c0705d8u,
0x0c070878u,0x0c07087au,0x0c07087cu,0x0c07087eu,0x0c070880u,0x0c070882u,0x0c070884u,0x0c070886u,0x0c070888u,0x0c07088au,0x0c07088cu,0x0c07088eu,0x0c070890u,0x0c070892u,0x0c070898u,0x0c07089au,
0x0c07089cu,0x0c07089eu,0x0c0708a0u,0x0c0708a2u,0x0c0708a4u,0x0c0708a6u,0x0c0708a8u,0x0c0708aau,0x0c0708acu,0x0c0708aeu,0x0c0708b0u,0x0c0708b2u,0x0c0708b4u,0x0c0708b6u,0x0c0708b8u,0x0c0708bau,
0x0c0708bcu,0x0c0708beu,0x0c0708c0u,0x0c0708c2u,0x0c0708c4u,0x0c0708c6u,0x0c0708c8u,0x0c0708cau,0x0c0708ccu,0x0c0708ceu,0x0c0708d0u,0x0c0708d2u,0x0c0708d4u,0x0c0708d6u,0x0c0708d8u,0x0c0708dau,
0x0c0708dcu,0x0c0708deu,0x0c0708e0u,0x0c0708e8u,0x0c0708eau,0x0c0708ecu,0x0c0708eeu,0x0c0708f0u,0x0c0708f2u,0x0c0708f4u,0x0c0708f6u,0x0c0708f8u,0x0c0708fau,0x0c0708fcu,0x0c0708feu,0x0c070900u,
0x0c070902u,0x0c070904u,0x0c070906u,0x0c070908u,0x0c07090au,0x0c07090cu,0x0c07090eu,0x0c070910u,0x0c070912u,0x0c070914u,0x0c070916u,0x0c070918u,0x0c07091au,0x0c07091cu,0x0c07091eu,0x0c070920u,
0x0c070922u,0x0c070924u,0x0c070926u,0x0c070928u,0x0c07092au,0x0c07092cu,0x0c070934u,0x0c070936u,0x0c070938u,0x0c07093au,0x0c07093cu,0x0c07093eu,0x0c070940u,0x0c070942u,0x0c070944u,0x0c070946u,
0x0c070948u,0x0c07094au,0x0c07094cu,0x0c07094eu,0x0c070950u,0x0c070952u,0x0c070954u,0x0c070956u,0x0c070958u,0x0c07095au,0x0c07095cu,0x0c07095eu,0x0c070960u,0x0c070962u,0x0c070964u,0x0c070966u,
0x0c070968u,0x0c07096au,0x0c07096cu,0x0c07096eu,0x0c070970u,0x0c07097cu,0x0c07097eu,0x0c070980u,0x0c070982u,0x0c070984u,0x0c070986u,0x0c070988u,0x0c07098au,0x0c07098cu,0x0c07098eu,0x0c070990u,
0x0c070992u,0x0c070994u,0x0c070996u,0x0c070998u,0x0c07099au,0x0c07099cu,0x0c07099eu,0x0c0709a0u,0x0c0709a2u,0x0c0709a4u,0x0c0709a6u,0x0c0709a8u,0x0c0709aau,0x0c0709acu,0x0c0709aeu,0x0c0709b0u,
0x0c0709bcu,0x0c0709beu,0x0c0709c0u,0x0c0709c2u,0x0c0709c4u,0x0c0709c6u,0x0c0709c8u,0x0c0709cau,0x0c0709ccu,0x0c0709ceu,0x0c0709d0u,0x0c0709d2u,0x0c0709d4u,0x0c0709d6u,0x0c0709d8u,0x0c0709dau,
0x0c0709dcu,0x0c0709deu,0x0c0709e0u,0x0c0709e2u,0x0c0709e4u,0x0c0709e6u,0x0c0709e8u,0x0c0709eau,0x0c0709ecu,0x0c0709eeu,0x0c0709f0u,0x0c0709f2u,0x0c0709f4u,0x0c0709f6u,0x0c0709f8u,0x0c0709fau,
0x0c0709fcu,0x0c0709feu,0x0c070a00u,0x0c070a02u,0x0c070a04u,0x0c070a06u,0x0c070a08u,0x0c070a0au,0x0c070a0cu,0x0c070a0eu,0x0c070a10u,0x0c070a12u,0x0c070a14u,0x0c070a16u,0x0c070a18u,0x0c070a1au,
0x0c070a1cu,0x0c070a1eu,0x0c070a20u,0x0c070a22u,0x0c070a24u,0x0c070a26u,0x0c070a28u,0x0c070a2au,0x0c070a2cu,0x0c070a2eu,0x0c070a30u,0x0c070a32u,0x0c070a34u,0x0c070a36u,0x0c070a38u,0x0c070a3au,
0x0c070a3cu,0x0c070a3eu,0x0c070a40u,0x0c070a42u,0x0c070a44u,0x0c070a46u,0x0c070a48u,0x0c070a4au,0x0c070a4cu,0x0c070a4eu,0x0c070a50u,0x0c070a52u,0x0c070a54u,0x0c070a56u,0x0c070a58u,0x0c070a5au,
0x0c070a5cu,0x0c070a5eu,0x0c070a60u,0x0c070a62u,0x0c070a64u,0x0c070a66u,0x0c070a68u,0x0c070a6au,0x0c070a6cu,0x0c070a6eu,0x0c070a70u,0x0c070a72u,0x0c070a74u,0x0c070a76u,0x0c070a78u,0x0c070a7au,
0x0c070a7cu,0x0c070a7eu,0x0c070a80u,0x0c070a82u,0x0c070a84u,0x0c070a86u,0x0c070a88u,0x0c070a8au,0x0c070a8cu,0x0c070a8eu,0x0c070a90u,0x0c070a92u,0x0c070a94u,0x0c070a96u,0x0c070a98u,0x0c070a9au,
0x0c070a9cu,0x0c070a9eu,0x0c070aa0u,0x0c070aa2u,0x0c070aa4u,0x0c070aa6u,0x0c070aa8u,0x0c070aaau,0x0c070aacu,0x0c070aaeu,0x0c070ab0u,0x0c070ab2u,0x0c070ab4u,0x0c070abcu,0x0c070abeu,0x0c070ac0u,
0x0c070ac2u,0x0c070ac4u,0x0c070ac6u,0x0c070ac8u,0x0c070acau,0x0c070accu,0x0c070aceu,0x0c070ad0u,0x0c070ad2u,0x0c070ad4u,0x0c070ad6u,0x0c070ad8u,0x0c070adau,0x0c070adcu,0x0c070adeu,0x0c070ae0u,
0x0c070ae2u,0x0c070ae4u,0x0c070ae6u,0x0c070ae8u,0x0c070aeau,0x0c070aecu,0x0c070aeeu,0x0c070af0u,0x0c070af2u,0x0c070af4u,0x0c070af6u,0x0c070af8u,0x0c070afau,0x0c070afcu,0x0c070afeu,0x0c070b00u,
0x0c070b08u,0x0c070b0au,0x0c070b0cu,0x0c070b0eu,0x0c070b10u,0x0c070b12u,0x0c070b14u,0x0c070b16u,0x0c070b18u,0x0c070b1au,0x0c070b1cu,0x0c070b1eu,0x0c070b20u,0x0c070b22u,0x0c070b24u,0x0c070b26u,
0x0c070b28u,0x0c070b2au,0x0c070b2cu,0x0c070b2eu,0x0c070b30u,0x0c070b32u,0x0c070b34u,0x0c070b36u,0x0c070b38u,0x0c070b3au,0x0c070b3cu,0x0c070b3eu,0x0c070b40u,0x0c070b42u,0x0c070b44u,0x0c070b50u,
0x0c070b52u,0x0c070b54u,0x0c070b56u,0x0c070b58u,0x0c070b5au,0x0c070b5cu,0x0c070b5eu,0x0c070b60u,0x0c070b62u,0x0c070b64u,0x0c070b66u,0x0c070b68u,0x0c070b6au,0x0c070b6cu,0x0c070b6eu,0x0c070b70u,
0x0c070b72u,0x0c070b74u,0x0c070b76u,0x0c070b78u,0x0c070b7au,0x0c070b7cu,0x0c070b7eu,0x0c070b80u,0x0c070b82u,0x0c070b84u,0x0c070b90u,0x0c070b92u,0x0c070b94u,0x0c070b96u,0x0c070b98u,0x0c070b9au,
0x0c070b9cu,0x0c070b9eu,0x0c070ba0u,0x0c070ba2u,0x0c070ba4u,0x0c070ba6u,0x0c070ba8u,0x0c070baau,0x0c070bacu,0x0c070baeu,0x0c070bb0u,0x0c070bb2u,0x0c070bb4u,0x0c070bb6u,0x0c070bb8u,0x0c070bbau,
0x0c070bbcu,0x0c070bbeu,0x0c070bc0u,0x0c070bc2u,0x0c070bc4u,0x0c070bc6u,0x0c070bc8u,0x0c070bcau,0x0c070bccu,0x0c070bceu,0x0c070bd0u,0x0c070bd2u,0x0c070bd4u,0x0c070bd6u,0x0c070bd8u,0x0c070bdau,
0x0c070bdcu,0x0c070bdeu,0x0c070be0u,0x0c070be2u,0x0c070be4u,0x0c070be6u,0x0c070be8u,0x0c070beau,0x0c070becu,0x0c070beeu,0x0c070bf0u,0x0c070bf2u,0x0c070bf4u,0x0c070bf6u,0x0c070bf8u,0x0c070bfau,
0x0c070bfcu,0x0c070bfeu,0x0c070c00u,0x0c070c02u,0x0c070c04u,0x0c070c06u,0x0c070c08u,0x0c070c0au,0x0c070c0cu,0x0c070c0eu,0x0c070c10u,0x0c070c12u,0x0c070c14u,0x0c070c16u,0x0c070c18u,0x0c070c1au,
0x0c070c1cu,0x0c070c1eu,0x0c070c20u,0x0c070c22u,0x0c070c24u,0x0c070c26u,0x0c070c28u,0x0c070c2au,0x0c070c2cu,0x0c070c2eu,0x0c070c30u,0x0c070c32u,0x0c070c34u,0x0c070c36u,0x0c070c38u,0x0c070c3au,
0x0c070c3cu,0x0c070c3eu,0x0c070c40u,0x0c070c42u,0x0c070c44u,0x0c070c46u,0x0c070c48u,0x0c070c4au,0x0c070c4cu,0x0c070c4eu,0x0c070c50u,0x0c070c52u,0x0c070c54u,0x0c070c56u,0x0c070c58u,0x0c070c5au,
0x0c070c5cu,0x0c070c5eu,0x0c070c60u,0x0c070c62u,0x0c070c64u,0x0c070c66u,0x0c070c68u,0x0c070c6au,0x0c070c6cu,0x0c070c6eu,0x0c070c70u,0x0c070c72u,0x0c070c74u,0x0c070c76u,0x0c070c78u,0x0c070c7au,
0x0c070c7cu,0x0c070c7eu,0x0c070c80u,0x0c070c82u,0x0c070c84u,0x0c070c86u,0x0c070c88u,0x0c070c90u,0x0c070c92u,0x0c070c94u,0x0c070c96u,0x0c070c98u,0x0c070c9au,0x0c070c9cu,0x0c070c9eu,0x0c070ca0u,
0x0c070ca2u,0x0c070ca4u,0x0c070ca6u,0x0c070ca8u,0x0c070caau,0x0c070cacu,0x0c070caeu,0x0c070cb0u,0x0c070cb2u,0x0c070cb4u,0x0c070cb6u,0x0c070cb8u,0x0c070cbau,0x0c070cbcu,0x0c070cbeu,0x0c070cc0u,
0x0c070cc2u,0x0c070cc4u,0x0c070cc6u,0x0c070cc8u,0x0c070ccau,0x0c070cccu,0x0c070cceu,0x0c070cd0u,0x0c070cd2u,0x0c070cd4u,0x0c070cd6u,0x0c070cd8u,0x0c070cdau,0x0c070cdcu,0x0c070cdeu,0x0c070ce0u,
0x0c070ce2u,0x0c070ce4u,0x0c070ce6u,0x0c070ce8u,0x0c070ceau,0x0c070cecu,0x0c070ceeu,0x0c070cf0u,0x0c070cf2u,0x0c070cf4u,0x0c070cf6u,0x0c070cf8u,0x0c070cfau,0x0c070cfcu,0x0c070cfeu,0x0c070d00u,
0x0c070d02u,0x0c070d04u,0x0c070d06u,0x0c070d08u,0x0c070d0au,0x0c070d0cu,0x0c070d0eu,0x0c070d10u,0x0c070d12u,0x0c070d14u,0x0c070d16u,0x0c070d18u,0x0c070d1au,0x0c070d1cu,0x0c070d1eu,0x0c070d24u,
0x0c070d26u,0x0c070d28u,0x0c070d2au,0x0c070d2cu,0x0c070d2eu,0x0c070d30u,0x0c070d32u,0x0c070d34u,0x0c070d36u,0x0c070d38u,0x0c070d3au,0x0c070d3cu,0x0c070d3eu,0x0c070d40u,0x0c070d42u,0x0c070d44u,
0x0c070d46u,0x0c070d48u,0x0c070d4au,0x0c070d4cu,0x0c070d4eu,0x0c070d50u,0x0c070d52u,0x0c070d54u,0x0c070d56u,0x0c070d58u,0x0c070d5au,0x0c070d5cu,0x0c070d5eu,0x0c070d60u,0x0c070d62u,0x0c070d64u,
0x0c070d66u,0x0c070d68u,0x0c070d6au,0x0c070d70u,0x0c070d72u,0x0c070d74u,0x0c070d76u,0x0c070d78u,0x0c070d7au,0x0c070d7cu,0x0c070d7eu,0x0c070d80u,0x0c070d82u,0x0c070d84u,0x0c070d86u,0x0c070d88u,
0x0c070d8au,0x0c070d8cu,0x0c070d8eu,0x0c070d90u,0x0c070d92u,0x0c070d94u,0x0c070d96u,0x0c070d98u,0x0c070d9au,0x0c070d9cu,0x0c070d9eu,0x0c070da0u,0x0c070da2u,0x0c070da4u,0x0c070da6u,0x0c070da8u,
0x0c070db4u,0x0c070db6u,0x0c070db8u,0x0c070dbau,0x0c070dbcu,0x0c070dbeu,0x0c070dc0u,0x0c070dc2u,0x0c070dc4u,0x0c070dc6u,0x0c070dc8u,0x0c070dcau,0x0c070dccu,0x0c070dceu,0x0c070dd0u,0x0c070dd2u,
0x0c070dd4u,0x0c070dd6u,0x0c070dd8u,0x0c070ddau,0x0c070ddcu,0x0c070ddeu,0x0c070de0u,0x0c070de2u,0x0c070de4u,0x0c070de6u,0x0c070de8u,0x0c070df4u,0x0c070df6u,0x0c070df8u,0x0c070dfau,0x0c070dfcu,
0x0c070dfeu,0x0c070e00u,0x0c070e02u,0x0c070e04u,0x0c070e06u,0x0c070e08u,0x0c070e0au,0x0c070e0cu,0x0c070e0eu,0x0c070e10u,0x0c070e12u,0x0c070e14u,0x0c070e16u,0x0c070e18u,0x0c070e1au,0x0c070e1cu,
0x0c070e1eu,0x0c070e20u,0x0c070e22u,0x0c070e24u,0x0c070e26u,0x0c070e28u,0x0c070e2au,0x0c070e2cu,0x0c070e2eu,0x0c070e30u,0x0c070e32u,0x0c070e34u,0x0c070e36u,0x0c070e38u,0x0c070e3au,0x0c070e3cu,
0x0c070e3eu,0x0c070e40u,0x0c070e42u,0x0c070e44u,0x0c070e46u,0x0c070e48u,0x0c070e4au,0x0c070e4cu,0x0c070e4eu,0x0c070e50u,0x0c070e52u,0x0c070e54u,0x0c070e56u,0x0c070e58u,0x0c070e5au,0x0c070e5cu,
0x0c070e5eu,0x0c070e60u,0x0c070e62u,0x0c070e64u,0x0c070e66u,0x0c070e68u,0x0c070e6au,0x0c070e6cu,0x0c070e6eu,0x0c070e70u,0x0c070e72u,0x0c070e74u,0x0c070e76u,0x0c070e78u,0x0c070e7au,0x0c070e7cu,
0x0c070e7eu,0x0c070e80u,0x0c070e82u,0x0c070e84u,0x0c070e86u,0x0c070e88u,0x0c070e8au,0x0c070e8cu,0x0c070e8eu,0x0c070e90u,0x0c070e92u,0x0c070e94u,0x0c070e96u,0x0c070e98u,0x0c070e9au,0x0c070e9cu,
0x0c070e9eu,0x0c070ea0u,0x0c070ea2u,0x0c070ea4u,0x0c070ea6u,0x0c070ea8u,0x0c070eaau,0x0c070eacu,0x0c070eaeu,0x0c070eb0u,0x0c070eb2u,0x0c070eb4u,0x0c070eb6u,0x0c070eb8u,0x0c070ebau,0x0c070ebcu,
0x0c070ebeu,0x0c070ec0u,0x0c070ec2u,0x0c070ec4u,0x0c070ec6u,0x0c070ec8u,0x0c070ecau,0x0c070eccu,0x0c070eceu,0x0c070ed0u,0x0c070ed2u,0x0c070ed4u,0x0c070ed6u,0x0c070ed8u,0x0c070edau,0x0c070edcu,
0x0c070edeu,0x0c070ee0u,0x0c070ee2u,0x0c070ee4u,0x0c070ee6u,0x0c070ee8u,0x0c070eeau,0x0c070eecu,0x0c070eeeu,0x0c070ef4u,0x0c070ef6u,0x0c070ef8u,0x0c070efau,0x0c070efcu,0x0c070efeu,0x0c070f00u,
0x0c070f02u,0x0c070f04u,0x0c070f06u,0x0c070f08u,0x0c070f0au,0x0c070f0cu,0x0c070f0eu,0x0c070f10u,0x0c070f12u,0x0c070f14u,0x0c070f16u,0x0c070f18u,0x0c070f1au,0x0c070f1cu,0x0c070f1eu,0x0c070f20u,
0x0c070f22u,0x0c070f24u,0x0c070f26u,0x0c070f28u,0x0c070f2au,0x0c070f2cu,0x0c070f2eu,0x0c070f30u,0x0c070f32u,0x0c070f34u,0x0c070f36u,0x0c070f38u,0x0c070f3au,0x0c070f40u,0x0c070f42u,0x0c070f44u,
0x0c070f46u,0x0c070f48u,0x0c070f4au,0x0c070f4cu,0x0c070f4eu,0x0c070f50u,0x0c070f52u,0x0c070f54u,0x0c070f56u,0x0c070f58u,0x0c070f5au,0x0c070f5cu,0x0c070f5eu,0x0c070f60u,0x0c070f62u,0x0c070f64u,
0x0c070f66u,0x0c070f68u,0x0c070f6au,0x0c070f6cu,0x0c070f6eu,0x0c070f70u,0x0c070f72u,0x0c070f74u,0x0c070f76u,0x0c070f78u,0x0c070f84u,0x0c070f86u,0x0c070f88u,0x0c070f8au,0x0c070f8cu,0x0c070f8eu,
0x0c070f90u,0x0c070f92u,0x0c070f94u,0x0c070f96u,0x0c070f98u,0x0c070f9au,0x0c070f9cu,0x0c070f9eu,0x0c070fa0u,0x0c070fa2u,0x0c070fa4u,0x0c071070u,0x0c071072u,0x0c071074u,0x0c071076u,0x0c071078u,
0x0c07107au,0x0c07107cu,0x0c07107eu,0x0c071080u,0x0c071082u,0x0c071084u,0x0c071086u,0x0c071088u,0x0c07108au,0x0c07108cu,0x0c07108eu,0x0c071090u,0x0c071092u,0x0c071094u,0x0c071096u,0x0c071098u,
0x0c07109au,0x0c07109cu,0x0c07109eu,0x0c0710a0u,0x0c0710a2u,0x0c0710a4u,0x0c0710a6u,0x0c0710a8u,0x0c0710aau,0x0c0710acu,0x0c0710aeu,0x0c0710b0u,0x0c0710b2u,0x0c0710b4u,0x0c0710b6u,0x0c0710b8u,
0x0c0710bau,0x0c0710bcu,0x0c0710beu,0x0c0710c0u,0x0c0710c8u,0x0c0710cau,0x0c0710ccu,0x0c0710ceu,0x0c0710d0u,0x0c0710d2u,0x0c0710d4u,0x0c0710d6u,0x0c0710d8u,0x0c0710dau,0x0c0710dcu,0x0c0710deu,
0x0c0710e0u,0x0c0710e2u,0x0c0710e4u,0x0c0710e6u,0x0c0710e8u,0x0c0710eau,0x0c0710ecu,0x0c0710eeu,0x0c0710f0u,0x0c0710f2u,0x0c0710f4u,0x0c0710f6u,0x0c0710f8u,0x0c0710fau,0x0c0710fcu,0x0c0710feu,
0x0c071100u,0x0c071102u,0x0c071104u,0x0c071106u,0x0c071108u,0x0c07110au,0x0c07110cu,0x0c07110eu,0x0c071110u,0x0c071112u,0x0c071114u,0x0c071116u,0x0c071118u,0x0c07111au,0x0c07111cu,0x0c07111eu,
0x0c071120u,0x0c071122u,0x0c071124u,0x0c071126u,0x0c071128u,0x0c07112au,0x0c07112cu,0x0c07112eu,0x0c071130u,0x0c071132u,0x0c071134u,0x0c071136u,0x0c071138u,0x0c07113au,0x0c07113cu,0x0c07113eu,
0x0c071400u,0x0c071402u,0x0c071404u,0x0c071406u,0x0c071408u,0x0c07140au,0x0c071410u,0x0c071412u,0x0c071414u,0x0c071416u,0x0c071418u,0x0c07141au,0x0c07141cu,0x0c07141eu,0x0c071420u,0x0c071422u,
0x0c071424u,0x0c071426u,0x0c071428u,0x0c07142au,0x0c07142cu,0x0c07142eu,0x0c071430u,0x0c071432u,0x0c071434u,0x0c071436u,0x0c071438u,0x0c07143au,0x0c07143cu,0x0c07143eu,0x0c071440u,0x0c071442u,
0x0c071444u,0x0c071446u,0x0c071448u,0x0c07144au,0x0c07144cu,0x0c07144eu,0x0c071450u,0x0c071452u,0x0c071454u,0x0c071456u,0x0c07145cu,0x0c07145eu,0x0c071460u,0x0c071462u,0x0c071464u,0x0c071466u,
0x0c071468u,0x0c07146au,0x0c07146cu,0x0c07146eu,0x0c071470u,0x0c071472u,0x0c071474u,0x0c071476u,0x0c071478u,0x0c07147au,0x0c07147cu,0x0c07147eu,0x0c071480u,0x0c071482u,0x0c071484u,0x0c071486u,
0x0c071488u,0x0c07148au,0x0c07148cu,0x0c07148eu,0x0c071490u,0x0c071492u,0x0c071494u,0x0c071496u,0x0c071498u,0x0c07149au,0x0c07149cu,0x0c07149eu,0x0c0714a0u,0x0c0714a8u,0x0c0714aau,0x0c0714acu,
0x0c0714aeu,0x0c0714b0u,0x0c0714b2u,0x0c0714b4u,0x0c0714b6u,0x0c0714b8u,0x0c0714bau,0x0c0714bcu,0x0c0714beu,0x0c0714c0u,0x0c0714c2u,0x0c0714c4u,0x0c0714c6u,0x0c0714c8u,0x0c0714cau,0x0c0714ccu,
0x0c0714ceu,0x0c0714d0u,0x0c0714d2u,0x0c0714d4u,0x0c0714d6u,0x0c0714d8u,0x0c0714dau,0x0c0714dcu,0x0c0714deu,0x0c0714e0u,0x0c0714ecu,0x0c0714eeu,0x0c0714f0u,0x0c0714f2u,0x0c0714f4u,0x0c0714f6u,
0x0c0714f8u,0x0c0714fau,0x0c0714fcu,0x0c0714feu,0x0c071500u,0x0c071502u,0x0c071504u,0x0c071506u,0x0c071508u,0x0c07150au,0x0c07150cu,0x0c0715b0u,0x0c0715b2u,0x0c0715b4u,0x0c0715b6u,0x0c0715b8u,
0x0c0715bau,0x0c0715bcu,0x0c0715beu,0x0c0715c0u,0x0c0715c2u,0x0c0715c4u,0x0c0715c6u,0x0c0715c8u,0x0c0715cau,0x0c0715ccu,0x0c0715ceu,0x0c0715d0u,0x0c0715d2u,0x0c0715d4u,0x0c0715d6u,0x0c0715d8u,
0x0c0715dau,0x0c0715dcu,0x0c0715deu,0x0c0715e0u,0x0c0715e2u,0x0c0715e4u,0x0c0715e6u,0x0c0715e8u,0x0c0715eau,0x0c0715ecu,0x0c0715eeu,0x0c0715f0u,0x0c0715f2u,0x0c0715f4u,0x0c0715f6u,0x0c0715f8u,
0x0c0715fau,0x0c0715fcu,0x0c0715feu,0x0c071600u,0x0c071602u,0x0c071604u,0x0c071606u,0x0c071608u,0x0c07160au,0x0c07160cu,0x0c07160eu,0x0c071610u,0x0c071612u,0x0c071614u,0x0c071616u,0x0c071618u,
0x0c07161au,0x0c07161cu,0x0c07161eu,0x0c071620u,0x0c071622u,0x0c071624u,0x0c07162cu,0x0c07162eu,0x0c071630u,0x0c071632u,0x0c071634u,0x0c071636u,0x0c071638u,0x0c07163au,0x0c07163cu,0x0c07163eu,
0x0c071640u,0x0c071642u,0x0c071644u,0x0c071646u,0x0c071648u,0x0c07164au,0x0c07164cu,0x0c07164eu,0x0c071650u,0x0c071652u,0x0c071654u,0x0c071656u,0x0c071658u,0x0c07165au,0x0c07165cu,0x0c07165eu,
0x0c071660u,0x0c071662u,0x0c071664u,0x0c071666u,0x0c071668u,0x0c07166au,0x0c07166cu,0x0c07166eu,0x0c071670u,0x0c071672u,0x0c071674u,0x0c071676u,0x0c071678u,0x0c07167au,0x0c07167cu,0x0c07167eu,
0x0c071680u,0x0c071682u,0x0c071684u,0x0c071686u,0x0c071688u,0x0c07168au,0x0c07168cu,0x0c07168eu,0x0c071690u,0x0c071692u,0x0c071694u,0x0c071696u,0x0c071698u,0x0c07169au,0x0c07169cu,0x0c07169eu,
0x0c0716a0u,0x0c0716a2u,0x0c0716a4u,0x0c0716a6u,0x0c0716a8u,0x0c0716aau,0x0c0716acu,0x0c0716aeu,0x0c0716b0u,0x0c0716b2u,0x0c0716b4u,0x0c0716b6u,0x0c0716b8u,0x0c0716bau,0x0c0716bcu,0x0c0716beu,
0x0c0716c0u,0x0c0716c2u,0x0c0716c4u,0x0c0716c6u,0x0c0716c8u,0x0c0716cau,0x0c0716ccu,0x0c0716ceu,0x0c0716d0u,0x0c0716d2u,0x0c0716d4u,0x0c0716d6u,0x0c0716d8u,0x0c0716dau,0x0c0716dcu,0x0c0716deu,
0x0c0716e0u,0x0c0716e2u,0x0c0716e4u,0x0c0716e6u,0x0c0716e8u,0x0c0716eau,0x0c0716ecu,0x0c0716eeu,0x0c0716f0u,0x0c0716f2u,0x0c0716f4u,0x0c0716f6u,0x0c0716f8u,0x0c0716fau,0x0c071704u,0x0c071706u,
0x0c071708u,0x0c07170au,0x0c07170cu,0x0c07170eu,0x0c071710u,0x0c071712u,0x0c071714u,0x0c071716u,0x0c071718u,0x0c07171au,0x0c07171cu,0x0c07171eu,0x0c071720u,0x0c071722u,0x0c071724u,0x0c071726u,
0x0c071728u,0x0c07172au,0x0c07172cu,0x0c07172eu,0x0c071730u,0x0c071732u,0x0c071734u,0x0c071736u,0x0c071738u,0x0c07173au,0x0c07173cu,0x0c07173eu,0x0c071740u,0x0c071742u,0x0c071744u,0x0c071746u,
0x0c071748u,0x0c07174au,0x0c07174cu,0x0c07174eu,0x0c071750u,0x0c071752u,0x0c071754u,0x0c071756u,0x0c071758u,0x0c07175au,0x0c07175cu,0x0c07175eu,0x0c071760u,0x0c071762u,0x0c071764u,0x0c071766u,
0x0c071768u,0x0c07176au,0x0c07176cu,0x0c07176eu,0x0c071770u,0x0c071772u,0x0c071774u,0x0c071776u,0x0c071778u,0x0c07177au,0x0c07177cu,0x0c07177eu,0x0c071780u,0x0c071782u,0x0c071784u,0x0c071786u,
0x0c071788u,0x0c07178au,0x0c07178cu,0x0c07178eu,0x0c071790u,0x0c071792u,0x0c071794u,0x0c071796u,0x0c071798u,0x0c07179au,0x0c07179cu,0x0c07179eu,0x0c0717a0u,0x0c0717a2u,0x0c0717a4u,0x0c0717a6u,
0x0c0717a8u,0x0c0717aau,0x0c0717acu,0x0c0717aeu,0x0c0717b0u,0x0c0717b2u,0x0c0717b4u,0x0c0717b6u,0x0c0717b8u,0x0c0717bau,0x0c0717bcu,0x0c0717beu,0x0c0717c0u,0x0c0717c2u,0x0c0717c4u,0x0c0717c6u,
0x0c0717c8u,0x0c0717cau,0x0c0717ccu,0x0c0717ceu,0x0c0717d0u,0x0c0717d2u,0x0c0717d4u,0x0c0717d6u,0x0c0717d8u,0x0c0717dau,0x0c0717dcu,0x0c0717deu,0x0c0717e0u,0x0c0717e2u,0x0c0717e4u,0x0c0717e6u,
0x0c0717e8u,0x0c0717eau,0x0c0717ecu,0x0c0717eeu,0x0c0717f0u,0x0c0717f2u,0x0c0717f4u,0x0c0717f6u,0x0c0717f8u,0x0c0717fau,0x0c0717fcu,0x0c0717feu,0x0c071800u,0x0c071802u,0x0c071804u,0x0c071806u,
0x0c071808u,0x0c07180au,0x0c07180cu,0x0c07180eu,0x0c071810u,0x0c071812u,0x0c071814u,0x0c071816u,0x0c071818u,0x0c07181au,0x0c07181cu,0x0c07181eu,0x0c071820u,0x0c071822u,0x0c071824u,0x0c071826u,
0x0c071828u,0x0c07182au,0x0c07182cu,0x0c07182eu,0x0c071830u,0x0c071832u,0x0c071834u,0x0c071836u,0x0c071838u,0x0c07183au,0x0c07183cu,0x0c07183eu,0x0c071840u,0x0c071842u,0x0c071844u,0x0c071846u,
0x0c071848u,0x0c07184au,0x0c07184cu,0x0c07184eu,0x0c071850u,0x0c071852u,0x0c071854u,0x0c071856u,0x0c071858u,0x0c07185au,0x0c07185cu,0x0c07185eu,0x0c071860u,0x0c071862u,0x0c071864u,0x0c071866u,
0x0c071868u,0x0c07186au,0x0c07186cu,0x0c07186eu,0x0c071870u,0x0c071878u,0x0c07187au,0x0c07187cu,0x0c07187eu,0x0c071880u,0x0c071882u,0x0c071884u,0x0c071886u,0x0c071888u,0x0c07188au,0x0c07188cu,
0x0c07188eu,0x0c071890u,0x0c071892u,0x0c071894u,0x0c071896u,0x0c071898u,0x0c07189au,0x0c07189cu,0x0c07189eu,0x0c0718a0u,0x0c0718a2u,0x0c0718a4u,0x0c0718a6u,0x0c0718a8u,0x0c0718aau,0x0c0718acu,
0x0c0718aeu,0x0c0718b0u,0x0c0718b2u,0x0c0718b4u,0x0c0718b6u,0x0c0718b8u,0x0c0718bau,0x0c0718bcu,0x0c0718beu,0x0c0718c0u,0x0c0718c2u,0x0c0718c4u,0x0c0718c6u,0x0c0718c8u,0x0c0718cau,0x0c0718ccu,
0x0c0718ceu,0x0c0718d0u,0x0c0718d2u,0x0c0718d4u,0x0c0718d6u,0x0c0718d8u,0x0c0718dau,0x0c0718dcu,0x0c0718deu,0x0c0718e0u,0x0c0718e2u,0x0c0718e4u,0x0c0718e6u,0x0c0718e8u,0x0c0718eau,0x0c0718ecu,
0x0c0718eeu,0x0c0718f0u,0x0c0718f2u,0x0c0718f4u,0x0c0718f6u,0x0c0718f8u,0x0c0718fau,0x0c0718fcu,0x0c0718feu,0x0c071900u,0x0c071902u,0x0c071904u,0x0c071906u,0x0c071908u,0x0c07190au,0x0c07190cu,
0x0c07190eu,0x0c071910u,0x0c071912u,0x0c071914u,0x0c071916u,0x0c071918u,0x0c07191au,0x0c07191cu,0x0c07191eu,0x0c071920u,0x0c071922u,0x0c071924u,0x0c071926u,0x0c071928u,0x0c07192au,0x0c071930u,
0x0c071932u,0x0c071934u,0x0c071936u,0x0c071938u,0x0c07193au,0x0c07193cu,0x0c07193eu,0x0c071940u,0x0c071942u,0x0c071944u,0x0c071946u,0x0c071948u,0x0c07194au,0x0c07194cu,0x0c07194eu,0x0c071950u,
0x0c071952u,0x0c071954u,0x0c071956u,0x0c071958u,0x0c07195au,0x0c07195cu,0x0c07195eu,0x0c071960u,0x0c071962u,0x0c071964u,0x0c071966u,0x0c071968u,0x0c07196au,0x0c07196cu,0x0c07196eu,0x0c071970u,
0x0c071972u,0x0c071974u,0x0c071976u,0x0c071978u,0x0c07197au,0x0c07197cu,0x0c07197eu,0x0c071980u,0x0c071982u,0x0c071984u,0x0c071986u,0x0c071988u,0x0c07198au,0x0c07198cu,0x0c07198eu,0x0c071990u,
0x0c071992u,0x0c071994u,0x0c071996u,0x0c071998u,0x0c07199au,0x0c07199cu,0x0c07199eu,0x0c0719a0u,0x0c0719a2u,0x0c0719a4u,0x0c0719a6u,0x0c0719a8u,0x0c0719aau,0x0c0719acu,0x0c0719aeu,0x0c0719b0u,
0x0c0719b2u,0x0c0719b4u,0x0c0719b6u,0x0c0719b8u,0x0c0719bau,0x0c0719bcu,0x0c0719beu,0x0c0719c0u,0x0c0719c2u,0x0c0719c4u,0x0c0719c6u,0x0c0719c8u,0x0c0719cau,0x0c0719ccu,0x0c0719ceu,0x0c0719d0u,
0x0c0719d2u,0x0c0719d4u,0x0c0719d6u,0x0c0719d8u,0x0c0719dau,0x0c0719dcu,0x0c0719deu,0x0c0719e0u,0x0c0719e2u,0x0c0719e4u,0x0c0719e6u,0x0c0719e8u,0x0c0719eau,0x0c0719ecu,0x0c0719eeu,0x0c0719f0u,
0x0c0719f2u,0x0c0719f4u,0x0c0719f6u,0x0c0719f8u,0x0c0719fau,0x0c0719fcu,0x0c0719feu,0x0c071a00u,0x0c071a02u,0x0c071a04u,0x0c071a06u,0x0c071a08u,0x0c071a0au,0x0c071a0cu,0x0c071a0eu,0x0c071a10u,
0x0c071a12u,0x0c071a14u,0x0c071a16u,0x0c071a18u,0x0c071a1au,0x0c071a1cu,0x0c071a1eu,0x0c071a20u,0x0c071a22u,0x0c071a24u,0x0c071a26u,0x0c071a28u,0x0c071a2au,0x0c071a2cu,0x0c071a2eu,0x0c071a30u,
0x0c071a32u,0x0c071a34u,0x0c071a36u,0x0c071a38u,0x0c071a3au,0x0c071a3cu,0x0c071a3eu,0x0c071a40u,0x0c071a42u,0x0c071a44u,0x0c071a46u,0x0c071a48u,0x0c071a4au,0x0c071a4cu,0x0c071a4eu,0x0c071a50u,
0x0c071a52u,0x0c071a54u,0x0c071a56u,0x0c071a58u,0x0c071a5au,0x0c071a5cu,0x0c071a5eu,0x0c071a60u,0x0c071a62u,0x0c071a64u,0x0c071a66u,0x0c071a68u,0x0c071a6au,0x0c071a6cu,0x0c071a6eu,0x0c071a70u,
0x0c071a72u,0x0c071a74u,0x0c071a76u,0x0c071a78u,0x0c071a7au,0x0c071a7cu,0x0c071a7eu,0x0c071a80u,0x0c071a82u,0x0c071a84u,0x0c071a86u,0x0c071a88u,0x0c071a8au,0x0c071a8cu,0x0c071a8eu,0x0c071a90u,
0x0c071a92u,0x0c071a94u,0x0c071a96u,0x0c071a98u,0x0c071a9au,0x0c071a9cu,0x0c071a9eu,0x0c071aa4u,0x0c071aa6u,0x0c071aa8u,0x0c071aaau,0x0c071aacu,0x0c071aaeu,0x0c071ab0u,0x0c071ab2u,0x0c071ab4u,
0x0c071ab6u,0x0c071ab8u,0x0c071abau,0x0c071abcu,0x0c071abeu,0x0c071ac0u,0x0c071ac2u,0x0c071ac4u,0x0c071ac6u,0x0c071ac8u,0x0c071acau,0x0c071accu,0x0c071aceu,0x0c071ad0u,0x0c071ad2u,0x0c071ad4u,
0x0c071ad6u,0x0c071ad8u,0x0c071adau,0x0c071adcu,0x0c071adeu,0x0c071ae0u,0x0c071ae2u,0x0c071ae4u,0x0c071ae6u,0x0c071ae8u,0x0c071aeau,0x0c071aecu,0x0c071aeeu,0x0c071af0u,0x0c071af2u,0x0c071af4u,
0x0c071af6u,0x0c071af8u,0x0c071afau,0x0c071afcu,0x0c071afeu,0x0c071b00u,0x0c071b02u,0x0c071b04u,0x0c071b06u,0x0c071b08u,0x0c071b0au,0x0c071b0cu,0x0c071b0eu,0x0c071b10u,0x0c071b12u,0x0c071b14u,
0x0c071b16u,0x0c071b18u,0x0c071b1au,0x0c071b1cu,0x0c071b1eu,0x0c071b20u,0x0c071b22u,0x0c071b24u,0x0c071b26u,0x0c071b28u,0x0c071b2au,0x0c071b2cu,0x0c071b2eu,0x0c071b30u,0x0c071b32u,0x0c071b34u,
0x0c071b36u,0x0c071b38u,0x0c071b3au,0x0c071b3cu,0x0c071b3eu,0x0c071b40u,0x0c071b42u,0x0c071b44u,0x0c071b46u,0x0c071b48u,0x0c071b4au,0x0c071b4cu,0x0c071b4eu,0x0c071b50u,0x0c071b52u,0x0c071b54u,
0x0c071b56u,0x0c071b58u,0x0c071b5au,0x0c071b5cu,0x0c071b5eu,0x0c071b60u,0x0c071b62u,0x0c071b64u,0x0c071b66u,0x0c071b68u,0x0c071b6au,0x0c071b6cu,0x0c071b6eu,0x0c071b70u,0x0c071b72u,0x0c071b74u,
0x0c071b76u,0x0c071b78u,0x0c071b7au,0x0c071b7cu,0x0c071b7eu,0x0c071b80u,0x0c071b82u,0x0c071b84u,0x0c071b86u,0x0c071b88u,0x0c071b8au,0x0c071b8cu,0x0c071b8eu,0x0c071b90u,0x0c071b92u,0x0c071b94u,
0x0c071b96u,0x0c071b98u,0x0c071b9au,0x0c071b9cu,0x0c071b9eu,0x0c071ba0u,0x0c071ba2u,0x0c071ba4u,0x0c071ba6u,0x0c071ba8u,0x0c071baau,0x0c071bacu,0x0c071baeu,0x0c071bb0u,0x0c071bb2u,0x0c071bb4u,
0x0c071bb6u,0x0c071bb8u,0x0c071bbau,0x0c071bbcu,0x0c071bbeu,0x0c071bc0u,0x0c071bc2u,0x0c071bc4u,0x0c071bc6u,0x0c071bc8u,0x0c071bcau,0x0c071bccu,0x0c071bceu,0x0c071bd0u,0x0c071bd2u,0x0c071bd4u,
0x0c071bd6u,0x0c071bd8u,0x0c071bdau,0x0c071bdcu,0x0c071bdeu,0x0c071be0u,0x0c071be2u,0x0c071be4u,0x0c071be6u,0x0c071be8u,0x0c071beau,0x0c071becu,0x0c071beeu,0x0c071bf0u,0x0c071bf2u,0x0c071bf4u,
0x0c071bf6u,0x0c071bf8u,0x0c071bfau,0x0c071bfcu,0x0c071bfeu,0x0c071c00u,0x0c071c02u,0x0c071c04u,0x0c071c06u,0x0c071c08u,0x0c071c0au,0x0c071c0cu,0x0c071c0eu,0x0c071c10u,0x0c071c12u,0x0c071c14u,
0x0c071c16u,0x0c071c18u,0x0c071c1au,0x0c071c1cu,0x0c071c1eu,0x0c071c20u,0x0c071c22u,0x0c071c24u,0x0c071c26u,0x0c071c28u,0x0c071c2au,0x0c071c2cu,0x0c071c2eu,0x0c071c30u,0x0c071c32u,0x0c071c38u,
0x0c071c3au,0x0c071c3cu,0x0c071c3eu,0x0c071c40u,0x0c071c42u,0x0c071c44u,0x0c071c46u,0x0c071c48u,0x0c071c4au,0x0c071c4cu,0x0c071c4eu,0x0c071c50u,0x0c071c52u,0x0c071c54u,0x0c071c56u,0x0c071c58u,
0x0c071c5au,0x0c071c5cu,0x0c071c5eu,0x0c071c60u,0x0c071c62u,0x0c071c64u,0x0c071c66u,0x0c071c68u,0x0c071c6au,0x0c071c6cu,0x0c071c6eu,0x0c071c70u,0x0c071c72u,0x0c071c74u,0x0c071c76u,0x0c071c78u,
0x0c071c7au,0x0c071c7cu,0x0c071c7eu,0x0c071c80u,0x0c071c82u,0x0c071c84u,0x0c071c86u,0x0c071c88u,0x0c071c8au,0x0c071c8cu,0x0c071c8eu,0x0c071c90u,0x0c071c92u,0x0c071c94u,0x0c071c96u,0x0c071c98u,
0x0c071c9au,0x0c071c9cu,0x0c071c9eu,0x0c071ca0u,0x0c071ca2u,0x0c071ca4u,0x0c071ca6u,0x0c071ca8u,0x0c071caau,0x0c071cacu,0x0c071caeu,0x0c071cb0u,0x0c071cb2u,0x0c071cb4u,0x0c071cb6u,0x0c071cb8u,
0x0c071cbau,0x0c071cbcu,0x0c071cbeu,0x0c071cc0u,0x0c071cc2u,0x0c071cc4u,0x0c071cc6u,0x0c071cc8u,0x0c071ccau,0x0c071cccu,0x0c071cceu,0x0c071cd0u,0x0c071cd2u,0x0c071cd4u,0x0c071cd6u,0x0c071cd8u,
0x0c071cdau,0x0c071cdcu,0x0c071cdeu,0x0c071ce0u,0x0c071ce2u,0x0c071ce4u,0x0c071ce6u,0x0c071ce8u,0x0c071ceau,0x0c071cecu,0x0c071ceeu,0x0c071cf0u,0x0c071cf2u,0x0c071cf4u,0x0c071cf6u,0x0c071cf8u,
0x0c071cfau,0x0c071cfcu,0x0c071cfeu,0x0c071d00u,0x0c071d02u,0x0c071d04u,0x0c071d06u,0x0c071d08u,0x0c071d0au,0x0c071d0cu,0x0c071d0eu,0x0c071d10u,0x0c071d12u,0x0c071d14u,0x0c071d16u,0x0c071d18u,
0x0c071d1au,0x0c071d1cu,0x0c071d1eu,0x0c071d20u,0x0c071d22u,0x0c071d24u,0x0c071d26u,0x0c071d28u,0x0c071d2au,0x0c071d2cu,0x0c071d2eu,0x0c071d30u,0x0c071d32u,0x0c071d34u,0x0c071d36u,0x0c071d38u,
0x0c071d3au,0x0c071d3cu,0x0c071d3eu,0x0c071d40u,0x0c071d42u,0x0c071d44u,0x0c071d46u,0x0c071d48u,0x0c071d4au,0x0c071d4cu,0x0c071d4eu,0x0c071d50u,0x0c071d52u,0x0c071d54u,0x0c071d56u,0x0c071d58u,
0x0c071d5au,0x0c071d5cu,0x0c071d5eu,0x0c071d60u,0x0c071d62u,0x0c071d64u,0x0c071d66u,0x0c071d68u,0x0c071d6au,0x0c071d6cu,0x0c071d6eu,0x0c071d70u,0x0c071d72u,0x0c071d74u,0x0c071d76u,0x0c071d78u,
0x0c071d7au,0x0c071d7cu,0x0c071d7eu,0x0c071d80u,0x0c071d82u,0x0c071d84u,0x0c071d86u,0x0c071d88u,0x0c071d8au,0x0c071d8cu,0x0c071d8eu,0x0c071d90u,0x0c071d92u,0x0c071d94u,0x0c071d96u,0x0c071d98u,
0x0c071d9au,0x0c071d9cu,0x0c071d9eu,0x0c071da0u,0x0c071da2u,0x0c071da4u,0x0c071da6u,0x0c071dacu,0x0c071daeu,0x0c071db0u,0x0c071db2u,0x0c071db4u,0x0c071db6u,0x0c071db8u,0x0c071dbau,0x0c071dbcu,
0x0c071dbeu,0x0c071dc0u,0x0c071dc2u,0x0c071dc4u,0x0c071dc6u,0x0c071dc8u,0x0c071dcau,0x0c071dccu,0x0c071dceu,0x0c071dd0u,0x0c071dd2u,0x0c071dd4u,0x0c071dd6u,0x0c071dd8u,0x0c071ddau,0x0c071ddcu,
0x0c071ddeu,0x0c071de0u,0x0c071de2u,0x0c071de4u,0x0c071de6u,0x0c071de8u,0x0c071deau,0x0c071decu,0x0c071deeu,0x0c071df0u,0x0c071df2u,0x0c071df4u,0x0c071df6u,0x0c071df8u,0x0c071dfau,0x0c071dfcu,
0x0c071dfeu,0x0c071e00u,0x0c071e02u,0x0c071e04u,0x0c071e06u,0x0c071e08u,0x0c071e0au,0x0c071e0cu,0x0c071e0eu,0x0c071e10u,0x0c071e12u,0x0c071e14u,0x0c071e16u,0x0c071e18u,0x0c071e1au,0x0c071e1cu,
0x0c071e1eu,0x0c071e20u,0x0c071e22u,0x0c071e24u,0x0c071e26u,0x0c071e28u,0x0c071e2au,0x0c071e2cu,0x0c071e2eu,0x0c071e30u,0x0c071e32u,0x0c071e34u,0x0c071e36u,0x0c071e38u,0x0c071e3au,0x0c071e3cu,
0x0c071e3eu,0x0c071e40u,0x0c071e42u,0x0c071e44u,0x0c071e46u,0x0c071e48u,0x0c071e4au,0x0c071e4cu,0x0c071e4eu,0x0c071e50u,0x0c071e52u,0x0c071e54u,0x0c071e56u,0x0c071e58u,0x0c071e5au,0x0c071e5cu,
0x0c071e64u,0x0c071e66u,0x0c071e68u,0x0c071e6au,0x0c071e6cu,0x0c071e6eu,0x0c071e70u,0x0c071e72u,0x0c071e74u,0x0c071e76u,0x0c071e78u,0x0c071e7au,0x0c071e7cu,0x0c071e7eu,0x0c071e80u,0x0c071e82u,
0x0c071e84u,0x0c071e86u,0x0c071e88u,0x0c071e8au,0x0c071e8cu,0x0c071e8eu,0x0c071e90u,0x0c071e92u,0x0c071e94u,0x0c071e96u,0x0c071e98u,0x0c071e9au,0x0c071e9cu,0x0c071e9eu,0x0c071ea0u,0x0c071ea2u,
0x0c071ea4u,0x0c071ea6u,0x0c071ea8u,0x0c071eaau,0x0c071eacu,0x0c071eaeu,0x0c071eb0u,0x0c071eb2u,0x0c071eb4u,0x0c071eb6u,0x0c071eb8u,0x0c071ebau,0x0c071ebcu,0x0c071ebeu,0x0c071ec0u,0x0c071ec2u,
0x0c071ec4u,0x0c071ec6u,0x0c071ec8u,0x0c071ecau,0x0c071eccu,0x0c071eceu,0x0c071ed0u,0x0c071ed2u,0x0c071ed4u,0x0c071ed6u,0x0c071ed8u,0x0c071edau,0x0c071edcu,0x0c071edeu,0x0c071ee0u,0x0c071ee2u,
0x0c071ee4u,0x0c071ee6u,0x0c071ee8u,0x0c071eeau,0x0c071eecu,0x0c071eeeu,0x0c071ef0u,0x0c071ef2u,0x0c071ef4u,0x0c071ef6u,0x0c071ef8u,0x0c071efau,0x0c071efcu,0x0c071efeu,0x0c071f00u,0x0c071f02u,
0x0c071f04u,0x0c071f06u,0x0c071f08u,0x0c071f0au,0x0c071f0cu,0x0c071f0eu,0x0c071f10u,0x0c071f12u,0x0c071f14u,0x0c071f16u,0x0c071f18u,0x0c071f1au,0x0c071f1cu,0x0c071f1eu,0x0c071f20u,0x0c071f22u,
0x0c071f24u,0x0c071f26u,0x0c071f28u,0x0c071f2au,0x0c071f2cu,0x0c071f2eu,0x0c071f30u,0x0c071f32u,0x0c071f34u,0x0c071f36u,0x0c071f38u,0x0c071f3au,0x0c071f3cu,0x0c071f3eu,0x0c071f40u,0x0c071f42u,
0x0c071f44u,0x0c071f46u,0x0c071f48u,0x0c071f4au,0x0c071f4cu,0x0c071f4eu,0x0c071f50u,0x0c071f52u,0x0c071f54u,0x0c071f56u,0x0c071f58u,0x0c071f5au,0x0c071f5cu,0x0c071f5eu,0x0c071f60u,0x0c071f62u,
0x0c071f64u,0x0c071f66u,0x0c071f68u,0x0c071f6au,0x0c071f6cu,0x0c071f6eu,0x0c071f70u,0x0c071f72u,0x0c071f74u,0x0c071f76u,0x0c071f78u,0x0c071f7au,0x0c071f7cu,0x0c071f7eu,0x0c071f80u,0x0c071f82u,
0x0c071f84u,0x0c071f86u,0x0c071f88u,0x0c071f8au,0x0c071f8cu,0x0c071f8eu,0x0c071f90u,0x0c071f92u,0x0c071f94u,0x0c071f96u,0x0c071f98u,0x0c071f9au,0x0c071f9cu,0x0c071f9eu,0x0c071fa0u,0x0c071fa2u,
0x0c071fa4u,0x0c071fa6u,0x0c071fa8u,0x0c071faau,0x0c071facu,0x0c071faeu,0x0c071fb0u,0x0c071fb2u,0x0c071fb4u,0x0c071fb6u,0x0c071fb8u,0x0c071fbau,0x0c071fbcu,0x0c071fbeu,0x0c071fc0u,0x0c071fc2u,
0x0c071fc4u,0x0c071fc6u,0x0c071fc8u,0x0c071fcau,0x0c071fccu,0x0c071fd4u,0x0c071fd6u,0x0c071fd8u,0x0c071fdau,0x0c071fdcu,0x0c071fdeu,0x0c071fe0u,0x0c071fe2u,0x0c071fe4u,0x0c071fe6u,0x0c071fe8u,
0x0c071feau,0x0c071fecu,0x0c071feeu,0x0c071ff0u,0x0c071ff2u,0x0c071ff4u,0x0c071ff6u,0x0c071ff8u,0x0c071ffau,0x0c071ffcu,0x0c071ffeu,0x0c072000u,0x0c072002u,0x0c072004u,0x0c072006u,0x0c072008u,
0x0c07200au,0x0c07200cu,0x0c07200eu,0x0c072010u,0x0c072012u,0x0c072014u,0x0c072016u,0x0c072018u,0x0c07201au,0x0c07201cu,0x0c07201eu,0x0c072020u,0x0c072022u,0x0c072024u,0x0c072026u,0x0c072028u,
0x0c07202au,0x0c07202cu,0x0c07202eu,0x0c072030u,0x0c072032u,0x0c072034u,0x0c072036u,0x0c072038u,0x0c07203au,0x0c07203cu,0x0c07203eu,0x0c072040u,0x0c072042u,0x0c072044u,0x0c072046u,0x0c072048u,
0x0c07204au,0x0c07204cu,0x0c07204eu,0x0c072050u,0x0c072052u,0x0c072054u,0x0c072056u,0x0c072058u,0x0c07205au,0x0c07205cu,0x0c07205eu,0x0c072060u,0x0c072062u,0x0c072064u,0x0c072066u,0x0c072068u,
0x0c07206au,0x0c07206cu,0x0c07206eu,0x0c072070u,0x0c072072u,0x0c072074u,0x0c072b02u,0x0c072b04u,0x0c072b06u,0x0c072b08u,0x0c072b0au,0x0c072b0cu,0x0c072b0eu,0x0c072b10u,0x0c072b12u,0x0c072b14u,
0x0c072b16u,0x0c072b18u,0x0c072b1au,0x0c072b1cu,0x0c072b1eu,0x0c072b20u,0x0c072b22u,0x0c072b24u,0x0c072b26u,0x0c072b28u,0x0c072b2au,0x0c072b2cu,0x0c072b2eu,0x0c072b30u,0x0c072b32u,0x0c072b34u,
0x0c072b36u,0x0c072b38u,0x0c072b3au,0x0c072b3cu,0x0c072b3eu,0x0c0aa744u,0x0c0aa746u,0x0c0aa748u,0x0c0aa74au,0x0c0aa74cu,0x0c0aa74eu,0x0c0aa750u,0x0c0aa752u,0x0c0aa754u,0x0c0aa756u,0x0c0aa758u,
0x0c0aa75au,0x0c0aa75cu,0x0c0aa75eu,0x0c0aa760u,0x0c0aa762u,0x0c0aa764u,0x0c0aa766u,0x0c0aa768u,0x0c0aa76au,0x0c0aa76cu,0x0c0aa76eu,0x0c0aa770u,0x0c0aa772u,0x0c0aa774u,0x0c0aa776u,0x0c0aa778u,
0x0c0aa77au,0x0c0aa77cu,0x0c0aa77eu,0x0c0aa780u,0x0c0aa782u,0x0c0aa784u,0x0c0aa786u,0x0c0aa788u,0x0c0aa78au,0x0c0aa78cu,0x0c0aa78eu,0x0c0aa790u,0x0c0aa792u,0x0c0aa794u,0x0c0aa796u,0x0c0aa798u,
0x0c0aa79au,0x0c0aa79cu,0x0c0aa79eu,0x0c0aa7a0u,
};
int vf3_seventh_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
