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
int vf3_tenpp_survey_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c035d94u: goto P_0c035d94;
case 0x0c035d96u: goto P_0c035d96;
case 0x0c035d98u: goto P_0c035d98;
case 0x0c035d9au: goto P_0c035d9a;
case 0x0c035d9cu: goto P_0c035d9c;
case 0x0c035d9eu: goto P_0c035d9e;
case 0x0c035da0u: goto P_0c035da0;
case 0x0c035da2u: goto P_0c035da2;
case 0x0c035da4u: goto P_0c035da4;
case 0x0c035da6u: goto P_0c035da6;
case 0x0c035da8u: goto P_0c035da8;
case 0x0c035daau: goto P_0c035daa;
case 0x0c035dacu: goto P_0c035dac;
case 0x0c035daeu: goto P_0c035dae;
case 0x0c035db0u: goto P_0c035db0;
case 0x0c035db2u: goto P_0c035db2;
case 0x0c035db4u: goto P_0c035db4;
case 0x0c035db6u: goto P_0c035db6;
case 0x0c035db8u: goto P_0c035db8;
case 0x0c035dbau: goto P_0c035dba;
case 0x0c035dbcu: goto P_0c035dbc;
case 0x0c035dbeu: goto P_0c035dbe;
case 0x0c035dc0u: goto P_0c035dc0;
case 0x0c035dc2u: goto P_0c035dc2;
case 0x0c035dc4u: goto P_0c035dc4;
case 0x0c035dc6u: goto P_0c035dc6;
case 0x0c035dc8u: goto P_0c035dc8;
case 0x0c035dcau: goto P_0c035dca;
case 0x0c035dccu: goto P_0c035dcc;
case 0x0c035dceu: goto P_0c035dce;
case 0x0c035dd0u: goto P_0c035dd0;
case 0x0c035dd2u: goto P_0c035dd2;
case 0x0c035dd4u: goto P_0c035dd4;
case 0x0c035dd6u: goto P_0c035dd6;
case 0x0c035dd8u: goto P_0c035dd8;
case 0x0c035ddau: goto P_0c035dda;
case 0x0c035ddcu: goto P_0c035ddc;
case 0x0c035ddeu: goto P_0c035dde;
case 0x0c035de0u: goto P_0c035de0;
case 0x0c035de2u: goto P_0c035de2;
case 0x0c035de4u: goto P_0c035de4;
case 0x0c035de6u: goto P_0c035de6;
case 0x0c035de8u: goto P_0c035de8;
case 0x0c035deau: goto P_0c035dea;
case 0x0c035decu: goto P_0c035dec;
case 0x0c035deeu: goto P_0c035dee;
case 0x0c035df0u: goto P_0c035df0;
case 0x0c035df2u: goto P_0c035df2;
case 0x0c035df4u: goto P_0c035df4;
case 0x0c035df6u: goto P_0c035df6;
case 0x0c035df8u: goto P_0c035df8;
case 0x0c035dfau: goto P_0c035dfa;
case 0x0c035dfcu: goto P_0c035dfc;
case 0x0c035dfeu: goto P_0c035dfe;
case 0x0c035e00u: goto P_0c035e00;
case 0x0c035e02u: goto P_0c035e02;
case 0x0c035e04u: goto P_0c035e04;
case 0x0c035e06u: goto P_0c035e06;
case 0x0c035e08u: goto P_0c035e08;
case 0x0c035e0au: goto P_0c035e0a;
case 0x0c035e0cu: goto P_0c035e0c;
case 0x0c035e0eu: goto P_0c035e0e;
case 0x0c035e10u: goto P_0c035e10;
case 0x0c035e12u: goto P_0c035e12;
case 0x0c035e14u: goto P_0c035e14;
case 0x0c035e16u: goto P_0c035e16;
case 0x0c035e18u: goto P_0c035e18;
case 0x0c035e1au: goto P_0c035e1a;
case 0x0c035e1cu: goto P_0c035e1c;
case 0x0c035e1eu: goto P_0c035e1e;
case 0x0c035e20u: goto P_0c035e20;
case 0x0c035e22u: goto P_0c035e22;
case 0x0c035e24u: goto P_0c035e24;
case 0x0c035e26u: goto P_0c035e26;
case 0x0c035e28u: goto P_0c035e28;
case 0x0c035e2au: goto P_0c035e2a;
case 0x0c035e2cu: goto P_0c035e2c;
case 0x0c035e2eu: goto P_0c035e2e;
case 0x0c035e30u: goto P_0c035e30;
case 0x0c035e32u: goto P_0c035e32;
case 0x0c035e34u: goto P_0c035e34;
case 0x0c035e36u: goto P_0c035e36;
case 0x0c035e38u: goto P_0c035e38;
case 0x0c035e3au: goto P_0c035e3a;
case 0x0c035e3cu: goto P_0c035e3c;
case 0x0c035e3eu: goto P_0c035e3e;
case 0x0c035e40u: goto P_0c035e40;
case 0x0c035e42u: goto P_0c035e42;
case 0x0c035e44u: goto P_0c035e44;
case 0x0c035e46u: goto P_0c035e46;
case 0x0c035e48u: goto P_0c035e48;
case 0x0c035e4au: goto P_0c035e4a;
case 0x0c035e4cu: goto P_0c035e4c;
case 0x0c035e4eu: goto P_0c035e4e;
case 0x0c035e50u: goto P_0c035e50;
case 0x0c035e52u: goto P_0c035e52;
case 0x0c035e54u: goto P_0c035e54;
case 0x0c035e56u: goto P_0c035e56;
case 0x0c035e58u: goto P_0c035e58;
case 0x0c035e5au: goto P_0c035e5a;
case 0x0c035e5cu: goto P_0c035e5c;
case 0x0c035e5eu: goto P_0c035e5e;
case 0x0c035e60u: goto P_0c035e60;
case 0x0c035e62u: goto P_0c035e62;
case 0x0c035e64u: goto P_0c035e64;
case 0x0c035e66u: goto P_0c035e66;
case 0x0c035e68u: goto P_0c035e68;
case 0x0c035e6au: goto P_0c035e6a;
case 0x0c035e6cu: goto P_0c035e6c;
case 0x0c035e6eu: goto P_0c035e6e;
case 0x0c035e70u: goto P_0c035e70;
case 0x0c035e72u: goto P_0c035e72;
case 0x0c035e74u: goto P_0c035e74;
case 0x0c035e76u: goto P_0c035e76;
case 0x0c035e78u: goto P_0c035e78;
case 0x0c035e7au: goto P_0c035e7a;
case 0x0c035e7cu: goto P_0c035e7c;
case 0x0c035e7eu: goto P_0c035e7e;
case 0x0c035e80u: goto P_0c035e80;
case 0x0c035e82u: goto P_0c035e82;
case 0x0c035e84u: goto P_0c035e84;
case 0x0c035e86u: goto P_0c035e86;
case 0x0c035e88u: goto P_0c035e88;
case 0x0c035e8au: goto P_0c035e8a;
case 0x0c035e8cu: goto P_0c035e8c;
case 0x0c035e8eu: goto P_0c035e8e;
case 0x0c036356u: goto P_0c036356;
case 0x0c036358u: goto P_0c036358;
case 0x0c03635au: goto P_0c03635a;
case 0x0c03635cu: goto P_0c03635c;
case 0x0c03635eu: goto P_0c03635e;
case 0x0c036360u: goto P_0c036360;
case 0x0c036362u: goto P_0c036362;
case 0x0c036364u: goto P_0c036364;
case 0x0c036366u: goto P_0c036366;
case 0x0c036368u: goto P_0c036368;
case 0x0c03636au: goto P_0c03636a;
case 0x0c03636cu: goto P_0c03636c;
case 0x0c03636eu: goto P_0c03636e;
case 0x0c036370u: goto P_0c036370;
case 0x0c036372u: goto P_0c036372;
case 0x0c036374u: goto P_0c036374;
case 0x0c036376u: goto P_0c036376;
case 0x0c036378u: goto P_0c036378;
case 0x0c03637au: goto P_0c03637a;
case 0x0c03637cu: goto P_0c03637c;
case 0x0c03637eu: goto P_0c03637e;
case 0x0c036380u: goto P_0c036380;
case 0x0c036382u: goto P_0c036382;
case 0x0c036384u: goto P_0c036384;
case 0x0c036386u: goto P_0c036386;
case 0x0c036388u: goto P_0c036388;
case 0x0c03638au: goto P_0c03638a;
case 0x0c03638cu: goto P_0c03638c;
case 0x0c03638eu: goto P_0c03638e;
case 0x0c036390u: goto P_0c036390;
case 0x0c036392u: goto P_0c036392;
case 0x0c036394u: goto P_0c036394;
case 0x0c036396u: goto P_0c036396;
case 0x0c036398u: goto P_0c036398;
case 0x0c03639au: goto P_0c03639a;
case 0x0c03639cu: goto P_0c03639c;
case 0x0c03639eu: goto P_0c03639e;
case 0x0c0363a0u: goto P_0c0363a0;
case 0x0c0363a2u: goto P_0c0363a2;
case 0x0c0363a4u: goto P_0c0363a4;
case 0x0c0363a6u: goto P_0c0363a6;
case 0x0c0363a8u: goto P_0c0363a8;
case 0x0c0363aau: goto P_0c0363aa;
case 0x0c0363acu: goto P_0c0363ac;
case 0x0c0363aeu: goto P_0c0363ae;
case 0x0c0363b0u: goto P_0c0363b0;
case 0x0c0363b2u: goto P_0c0363b2;
case 0x0c0363b4u: goto P_0c0363b4;
case 0x0c0363b6u: goto P_0c0363b6;
case 0x0c0363b8u: goto P_0c0363b8;
case 0x0c0363bau: goto P_0c0363ba;
case 0x0c0363bcu: goto P_0c0363bc;
case 0x0c0363beu: goto P_0c0363be;
case 0x0c0363c0u: goto P_0c0363c0;
case 0x0c0363c2u: goto P_0c0363c2;
case 0x0c0363c4u: goto P_0c0363c4;
case 0x0c03709cu: goto P_0c03709c;
case 0x0c03709eu: goto P_0c03709e;
case 0x0c0370a0u: goto P_0c0370a0;
case 0x0c0370a2u: goto P_0c0370a2;
case 0x0c0370a4u: goto P_0c0370a4;
case 0x0c0370a6u: goto P_0c0370a6;
case 0x0c0370a8u: goto P_0c0370a8;
case 0x0c0370aau: goto P_0c0370aa;
case 0x0c0370acu: goto P_0c0370ac;
case 0x0c0370aeu: goto P_0c0370ae;
case 0x0c0370b0u: goto P_0c0370b0;
case 0x0c0370b2u: goto P_0c0370b2;
case 0x0c0370b4u: goto P_0c0370b4;
case 0x0c0370b6u: goto P_0c0370b6;
case 0x0c0370b8u: goto P_0c0370b8;
case 0x0c0370bau: goto P_0c0370ba;
case 0x0c0370bcu: goto P_0c0370bc;
case 0x0c03866cu: goto P_0c03866c;
case 0x0c03866eu: goto P_0c03866e;
case 0x0c038670u: goto P_0c038670;
case 0x0c038672u: goto P_0c038672;
case 0x0c038674u: goto P_0c038674;
case 0x0c038676u: goto P_0c038676;
case 0x0c038678u: goto P_0c038678;
case 0x0c03867au: goto P_0c03867a;
case 0x0c03867cu: goto P_0c03867c;
case 0x0c03867eu: goto P_0c03867e;
case 0x0c038680u: goto P_0c038680;
case 0x0c038682u: goto P_0c038682;
case 0x0c038684u: goto P_0c038684;
case 0x0c038686u: goto P_0c038686;
case 0x0c038688u: goto P_0c038688;
case 0x0c03868au: goto P_0c03868a;
case 0x0c03868cu: goto P_0c03868c;
case 0x0c03868eu: goto P_0c03868e;
case 0x0c038690u: goto P_0c038690;
case 0x0c038692u: goto P_0c038692;
case 0x0c038694u: goto P_0c038694;
case 0x0c038696u: goto P_0c038696;
case 0x0c038698u: goto P_0c038698;
case 0x0c03869au: goto P_0c03869a;
case 0x0c03869cu: goto P_0c03869c;
case 0x0c03869eu: goto P_0c03869e;
case 0x0c0386a0u: goto P_0c0386a0;
case 0x0c0386a2u: goto P_0c0386a2;
case 0x0c0386a4u: goto P_0c0386a4;
case 0x0c0386a6u: goto P_0c0386a6;
case 0x0c0386a8u: goto P_0c0386a8;
case 0x0c0386aau: goto P_0c0386aa;
case 0x0c0386acu: goto P_0c0386ac;
case 0x0c0386aeu: goto P_0c0386ae;
case 0x0c0386b0u: goto P_0c0386b0;
case 0x0c0386b2u: goto P_0c0386b2;
case 0x0c0386c0u: goto P_0c0386c0;
case 0x0c0386c2u: goto P_0c0386c2;
case 0x0c0386c4u: goto P_0c0386c4;
case 0x0c0386c6u: goto P_0c0386c6;
case 0x0c0386c8u: goto P_0c0386c8;
case 0x0c0386cau: goto P_0c0386ca;
case 0x0c0386ccu: goto P_0c0386cc;
case 0x0c0386ceu: goto P_0c0386ce;
case 0x0c0386d0u: goto P_0c0386d0;
case 0x0c0386d2u: goto P_0c0386d2;
case 0x0c0386d4u: goto P_0c0386d4;
case 0x0c0386d6u: goto P_0c0386d6;
case 0x0c0386d8u: goto P_0c0386d8;
case 0x0c0386dau: goto P_0c0386da;
case 0x0c0386e0u: goto P_0c0386e0;
case 0x0c0386e2u: goto P_0c0386e2;
case 0x0c0386e4u: goto P_0c0386e4;
case 0x0c0386e6u: goto P_0c0386e6;
case 0x0c0386e8u: goto P_0c0386e8;
case 0x0c0386eau: goto P_0c0386ea;
case 0x0c0386ecu: goto P_0c0386ec;
case 0x0c0386eeu: goto P_0c0386ee;
case 0x0c0386f0u: goto P_0c0386f0;
case 0x0c0386f2u: goto P_0c0386f2;
case 0x0c0386f4u: goto P_0c0386f4;
case 0x0c0386f6u: goto P_0c0386f6;
case 0x0c0386f8u: goto P_0c0386f8;
case 0x0c0386fau: goto P_0c0386fa;
case 0x0c0386fcu: goto P_0c0386fc;
case 0x0c0386feu: goto P_0c0386fe;
case 0x0c038700u: goto P_0c038700;
case 0x0c038702u: goto P_0c038702;
case 0x0c038704u: goto P_0c038704;
case 0x0c038706u: goto P_0c038706;
case 0x0c038708u: goto P_0c038708;
case 0x0c03870au: goto P_0c03870a;
case 0x0c03870cu: goto P_0c03870c;
case 0x0c03870eu: goto P_0c03870e;
case 0x0c038710u: goto P_0c038710;
case 0x0c038712u: goto P_0c038712;
case 0x0c038714u: goto P_0c038714;
case 0x0c038716u: goto P_0c038716;
case 0x0c038718u: goto P_0c038718;
case 0x0c038720u: goto P_0c038720;
case 0x0c038722u: goto P_0c038722;
case 0x0c038724u: goto P_0c038724;
case 0x0c038726u: goto P_0c038726;
case 0x0c038728u: goto P_0c038728;
case 0x0c03872au: goto P_0c03872a;
case 0x0c03872cu: goto P_0c03872c;
case 0x0c03872eu: goto P_0c03872e;
case 0x0c038730u: goto P_0c038730;
case 0x0c038732u: goto P_0c038732;
case 0x0c038734u: goto P_0c038734;
case 0x0c038736u: goto P_0c038736;
case 0x0c038738u: goto P_0c038738;
case 0x0c03873au: goto P_0c03873a;
case 0x0c03873cu: goto P_0c03873c;
case 0x0c03873eu: goto P_0c03873e;
case 0x0c038740u: goto P_0c038740;
case 0x0c038742u: goto P_0c038742;
case 0x0c038744u: goto P_0c038744;
case 0x0c038746u: goto P_0c038746;
case 0x0c038748u: goto P_0c038748;
case 0x0c03874au: goto P_0c03874a;
case 0x0c03874cu: goto P_0c03874c;
case 0x0c03874eu: goto P_0c03874e;
case 0x0c038750u: goto P_0c038750;
case 0x0c038752u: goto P_0c038752;
case 0x0c038a80u: goto P_0c038a80;
case 0x0c038a82u: goto P_0c038a82;
case 0x0c038a84u: goto P_0c038a84;
case 0x0c038a86u: goto P_0c038a86;
case 0x0c038a88u: goto P_0c038a88;
case 0x0c038a8au: goto P_0c038a8a;
case 0x0c038a8cu: goto P_0c038a8c;
case 0x0c038a8eu: goto P_0c038a8e;
case 0x0c038a90u: goto P_0c038a90;
case 0x0c038a92u: goto P_0c038a92;
case 0x0c038a94u: goto P_0c038a94;
case 0x0c038a96u: goto P_0c038a96;
case 0x0c038a98u: goto P_0c038a98;
case 0x0c038a9au: goto P_0c038a9a;
case 0x0c038a9cu: goto P_0c038a9c;
case 0x0c038a9eu: goto P_0c038a9e;
case 0x0c038aa0u: goto P_0c038aa0;
case 0x0c038aa2u: goto P_0c038aa2;
case 0x0c038aa4u: goto P_0c038aa4;
case 0x0c038aa6u: goto P_0c038aa6;
case 0x0c038aa8u: goto P_0c038aa8;
case 0x0c038aaau: goto P_0c038aaa;
case 0x0c038aacu: goto P_0c038aac;
case 0x0c038aaeu: goto P_0c038aae;
case 0x0c038ab0u: goto P_0c038ab0;
case 0x0c038ab2u: goto P_0c038ab2;
case 0x0c038ab4u: goto P_0c038ab4;
case 0x0c038ab6u: goto P_0c038ab6;
case 0x0c038ab8u: goto P_0c038ab8;
case 0x0c038abau: goto P_0c038aba;
case 0x0c038abcu: goto P_0c038abc;
case 0x0c038abeu: goto P_0c038abe;
case 0x0c038ac0u: goto P_0c038ac0;
case 0x0c038ac2u: goto P_0c038ac2;
case 0x0c038ac4u: goto P_0c038ac4;
case 0x0c038ac6u: goto P_0c038ac6;
case 0x0c038ac8u: goto P_0c038ac8;
case 0x0c038acau: goto P_0c038aca;
case 0x0c038accu: goto P_0c038acc;
case 0x0c038aceu: goto P_0c038ace;
case 0x0c038ad0u: goto P_0c038ad0;
case 0x0c038ad2u: goto P_0c038ad2;
case 0x0c038ad4u: goto P_0c038ad4;
case 0x0c038ad6u: goto P_0c038ad6;
case 0x0c038ad8u: goto P_0c038ad8;
case 0x0c038adau: goto P_0c038ada;
case 0x0c038adcu: goto P_0c038adc;
case 0x0c038adeu: goto P_0c038ade;
case 0x0c038ae0u: goto P_0c038ae0;
case 0x0c038ae2u: goto P_0c038ae2;
case 0x0c038ae4u: goto P_0c038ae4;
case 0x0c038ae6u: goto P_0c038ae6;
case 0x0c038ae8u: goto P_0c038ae8;
case 0x0c038aeau: goto P_0c038aea;
case 0x0c038aecu: goto P_0c038aec;
case 0x0c038aeeu: goto P_0c038aee;
case 0x0c038af0u: goto P_0c038af0;
case 0x0c038bc4u: goto P_0c038bc4;
case 0x0c038bc6u: goto P_0c038bc6;
case 0x0c038bc8u: goto P_0c038bc8;
case 0x0c038bcau: goto P_0c038bca;
case 0x0c038bccu: goto P_0c038bcc;
case 0x0c038bceu: goto P_0c038bce;
case 0x0c038bd0u: goto P_0c038bd0;
case 0x0c038bd2u: goto P_0c038bd2;
case 0x0c038bd4u: goto P_0c038bd4;
case 0x0c038bd6u: goto P_0c038bd6;
case 0x0c038bd8u: goto P_0c038bd8;
case 0x0c038bdau: goto P_0c038bda;
case 0x0c038bdcu: goto P_0c038bdc;
case 0x0c038bdeu: goto P_0c038bde;
case 0x0c038be0u: goto P_0c038be0;
case 0x0c038be2u: goto P_0c038be2;
case 0x0c038be4u: goto P_0c038be4;
case 0x0c038be6u: goto P_0c038be6;
case 0x0c038eaeu: goto P_0c038eae;
case 0x0c038eb0u: goto P_0c038eb0;
case 0x0c038eb2u: goto P_0c038eb2;
case 0x0c038eb4u: goto P_0c038eb4;
case 0x0c038eb6u: goto P_0c038eb6;
case 0x0c038eb8u: goto P_0c038eb8;
case 0x0c038ebau: goto P_0c038eba;
case 0x0c038ebcu: goto P_0c038ebc;
case 0x0c038ebeu: goto P_0c038ebe;
case 0x0c038ec0u: goto P_0c038ec0;
case 0x0c038ec2u: goto P_0c038ec2;
case 0x0c038ec4u: goto P_0c038ec4;
case 0x0c038ec6u: goto P_0c038ec6;
case 0x0c038ec8u: goto P_0c038ec8;
case 0x0c038ecau: goto P_0c038eca;
case 0x0c038eccu: goto P_0c038ecc;
case 0x0c038eceu: goto P_0c038ece;
case 0x0c038ed0u: goto P_0c038ed0;
case 0x0c038ed2u: goto P_0c038ed2;
case 0x0c038ed4u: goto P_0c038ed4;
case 0x0c038ed6u: goto P_0c038ed6;
case 0x0c038ed8u: goto P_0c038ed8;
case 0x0c038edau: goto P_0c038eda;
case 0x0c038edcu: goto P_0c038edc;
case 0x0c038edeu: goto P_0c038ede;
case 0x0c038ee0u: goto P_0c038ee0;
case 0x0c038ee2u: goto P_0c038ee2;
case 0x0c038ee4u: goto P_0c038ee4;
case 0x0c038ee6u: goto P_0c038ee6;
case 0x0c038ee8u: goto P_0c038ee8;
case 0x0c038eeau: goto P_0c038eea;
case 0x0c038eecu: goto P_0c038eec;
case 0x0c038eeeu: goto P_0c038eee;
case 0x0c038ef0u: goto P_0c038ef0;
case 0x0c038ef2u: goto P_0c038ef2;
case 0x0c038ef4u: goto P_0c038ef4;
case 0x0c038ef6u: goto P_0c038ef6;
case 0x0c038ef8u: goto P_0c038ef8;
case 0x0c038efau: goto P_0c038efa;
case 0x0c038efcu: goto P_0c038efc;
case 0x0c038efeu: goto P_0c038efe;
case 0x0c038f00u: goto P_0c038f00;
case 0x0c038f02u: goto P_0c038f02;
case 0x0c038f04u: goto P_0c038f04;
case 0x0c038f06u: goto P_0c038f06;
case 0x0c038f08u: goto P_0c038f08;
case 0x0c038f0au: goto P_0c038f0a;
case 0x0c038f0cu: goto P_0c038f0c;
case 0x0c038f0eu: goto P_0c038f0e;
case 0x0c038f10u: goto P_0c038f10;
case 0x0c038f12u: goto P_0c038f12;
case 0x0c038f14u: goto P_0c038f14;
case 0x0c038f16u: goto P_0c038f16;
case 0x0c038f18u: goto P_0c038f18;
case 0x0c038f1au: goto P_0c038f1a;
case 0x0c038f1cu: goto P_0c038f1c;
case 0x0c038f1eu: goto P_0c038f1e;
case 0x0c038f20u: goto P_0c038f20;
case 0x0c038f22u: goto P_0c038f22;
case 0x0c038f24u: goto P_0c038f24;
case 0x0c038f26u: goto P_0c038f26;
case 0x0c038f28u: goto P_0c038f28;
case 0x0c038f2au: goto P_0c038f2a;
case 0x0c038f2cu: goto P_0c038f2c;
case 0x0c038f2eu: goto P_0c038f2e;
case 0x0c038f30u: goto P_0c038f30;
case 0x0c038f32u: goto P_0c038f32;
case 0x0c038f34u: goto P_0c038f34;
case 0x0c038f36u: goto P_0c038f36;
case 0x0c038f38u: goto P_0c038f38;
case 0x0c038f4eu: goto P_0c038f4e;
case 0x0c038f50u: goto P_0c038f50;
case 0x0c038f52u: goto P_0c038f52;
case 0x0c038f54u: goto P_0c038f54;
case 0x0c038f56u: goto P_0c038f56;
case 0x0c038f58u: goto P_0c038f58;
case 0x0c038f5au: goto P_0c038f5a;
case 0x0c038f5cu: goto P_0c038f5c;
case 0x0c038f5eu: goto P_0c038f5e;
case 0x0c038f60u: goto P_0c038f60;
case 0x0c038f62u: goto P_0c038f62;
case 0x0c038f64u: goto P_0c038f64;
case 0x0c038f66u: goto P_0c038f66;
case 0x0c038f68u: goto P_0c038f68;
case 0x0c038f6au: goto P_0c038f6a;
case 0x0c038f6cu: goto P_0c038f6c;
case 0x0c038f6eu: goto P_0c038f6e;
case 0x0c038f70u: goto P_0c038f70;
case 0x0c038f72u: goto P_0c038f72;
case 0x0c038f74u: goto P_0c038f74;
case 0x0c038f76u: goto P_0c038f76;
case 0x0c038f78u: goto P_0c038f78;
case 0x0c038f7au: goto P_0c038f7a;
case 0x0c038f7cu: goto P_0c038f7c;
case 0x0c038f7eu: goto P_0c038f7e;
case 0x0c038f80u: goto P_0c038f80;
case 0x0c038f82u: goto P_0c038f82;
case 0x0c038f84u: goto P_0c038f84;
case 0x0c038f86u: goto P_0c038f86;
case 0x0c038f88u: goto P_0c038f88;
case 0x0c038f8au: goto P_0c038f8a;
case 0x0c038f8cu: goto P_0c038f8c;
case 0x0c038f8eu: goto P_0c038f8e;
case 0x0c038f90u: goto P_0c038f90;
case 0x0c038f92u: goto P_0c038f92;
case 0x0c038f94u: goto P_0c038f94;
case 0x0c038f96u: goto P_0c038f96;
case 0x0c038f98u: goto P_0c038f98;
case 0x0c038f9au: goto P_0c038f9a;
case 0x0c038f9cu: goto P_0c038f9c;
case 0x0c038f9eu: goto P_0c038f9e;
case 0x0c038fa0u: goto P_0c038fa0;
case 0x0c038fa2u: goto P_0c038fa2;
case 0x0c038fa4u: goto P_0c038fa4;
case 0x0c038fa6u: goto P_0c038fa6;
case 0x0c038fa8u: goto P_0c038fa8;
case 0x0c038faau: goto P_0c038faa;
case 0x0c038facu: goto P_0c038fac;
case 0x0c038faeu: goto P_0c038fae;
case 0x0c038fb0u: goto P_0c038fb0;
case 0x0c038fb2u: goto P_0c038fb2;
case 0x0c038fb4u: goto P_0c038fb4;
case 0x0c038fb6u: goto P_0c038fb6;
case 0x0c038fb8u: goto P_0c038fb8;
case 0x0c038fbau: goto P_0c038fba;
case 0x0c038fbcu: goto P_0c038fbc;
case 0x0c038fbeu: goto P_0c038fbe;
case 0x0c038fc0u: goto P_0c038fc0;
case 0x0c038fc2u: goto P_0c038fc2;
case 0x0c038fc4u: goto P_0c038fc4;
case 0x0c038fc6u: goto P_0c038fc6;
case 0x0c038fc8u: goto P_0c038fc8;
case 0x0c038fcau: goto P_0c038fca;
case 0x0c038fccu: goto P_0c038fcc;
case 0x0c038fceu: goto P_0c038fce;
case 0x0c038fd0u: goto P_0c038fd0;
case 0x0c038fd2u: goto P_0c038fd2;
case 0x0c038fd4u: goto P_0c038fd4;
case 0x0c038fd6u: goto P_0c038fd6;
case 0x0c03b874u: goto P_0c03b874;
case 0x0c03b876u: goto P_0c03b876;
case 0x0c03b878u: goto P_0c03b878;
case 0x0c03b87au: goto P_0c03b87a;
case 0x0c03b87cu: goto P_0c03b87c;
case 0x0c03b87eu: goto P_0c03b87e;
case 0x0c03b880u: goto P_0c03b880;
case 0x0c03b882u: goto P_0c03b882;
case 0x0c03b884u: goto P_0c03b884;
case 0x0c03b886u: goto P_0c03b886;
case 0x0c03b888u: goto P_0c03b888;
case 0x0c03b88au: goto P_0c03b88a;
case 0x0c03b88cu: goto P_0c03b88c;
case 0x0c03b88eu: goto P_0c03b88e;
case 0x0c03b890u: goto P_0c03b890;
case 0x0c03b892u: goto P_0c03b892;
case 0x0c03b894u: goto P_0c03b894;
case 0x0c03b896u: goto P_0c03b896;
case 0x0c03b898u: goto P_0c03b898;
case 0x0c03b89au: goto P_0c03b89a;
case 0x0c03b89cu: goto P_0c03b89c;
case 0x0c03b89eu: goto P_0c03b89e;
case 0x0c03b8a0u: goto P_0c03b8a0;
case 0x0c03b8a2u: goto P_0c03b8a2;
case 0x0c03b8a4u: goto P_0c03b8a4;
case 0x0c03b8a6u: goto P_0c03b8a6;
case 0x0c03b8a8u: goto P_0c03b8a8;
case 0x0c03b8aau: goto P_0c03b8aa;
case 0x0c03b8acu: goto P_0c03b8ac;
case 0x0c03b8aeu: goto P_0c03b8ae;
case 0x0c03b8b0u: goto P_0c03b8b0;
case 0x0c03b8b2u: goto P_0c03b8b2;
case 0x0c03b8b4u: goto P_0c03b8b4;
case 0x0c03b8b6u: goto P_0c03b8b6;
case 0x0c03b8b8u: goto P_0c03b8b8;
case 0x0c03e620u: goto P_0c03e620;
case 0x0c03e622u: goto P_0c03e622;
case 0x0c03e624u: goto P_0c03e624;
case 0x0c03e626u: goto P_0c03e626;
case 0x0c03e628u: goto P_0c03e628;
case 0x0c03e62au: goto P_0c03e62a;
case 0x0c03e62cu: goto P_0c03e62c;
case 0x0c03e62eu: goto P_0c03e62e;
case 0x0c03e630u: goto P_0c03e630;
case 0x0c03e632u: goto P_0c03e632;
case 0x0c03e634u: goto P_0c03e634;
case 0x0c03e636u: goto P_0c03e636;
case 0x0c03e638u: goto P_0c03e638;
case 0x0c03e63au: goto P_0c03e63a;
case 0x0c03e63cu: goto P_0c03e63c;
case 0x0c03e63eu: goto P_0c03e63e;
case 0x0c03e640u: goto P_0c03e640;
case 0x0c03e642u: goto P_0c03e642;
case 0x0c03e644u: goto P_0c03e644;
case 0x0c03e646u: goto P_0c03e646;
case 0x0c03e648u: goto P_0c03e648;
case 0x0c03e64au: goto P_0c03e64a;
case 0x0c03e64cu: goto P_0c03e64c;
case 0x0c03e64eu: goto P_0c03e64e;
case 0x0c03e650u: goto P_0c03e650;
case 0x0c03e652u: goto P_0c03e652;
case 0x0c03e654u: goto P_0c03e654;
case 0x0c03e656u: goto P_0c03e656;
case 0x0c03e658u: goto P_0c03e658;
case 0x0c03e65au: goto P_0c03e65a;
case 0x0c03e65cu: goto P_0c03e65c;
case 0x0c03e65eu: goto P_0c03e65e;
case 0x0c03e660u: goto P_0c03e660;
case 0x0c03e662u: goto P_0c03e662;
case 0x0c03e664u: goto P_0c03e664;
case 0x0c03ea22u: goto P_0c03ea22;
case 0x0c03ea24u: goto P_0c03ea24;
case 0x0c03ea26u: goto P_0c03ea26;
case 0x0c03ea28u: goto P_0c03ea28;
case 0x0c03ea2au: goto P_0c03ea2a;
case 0x0c03ea2cu: goto P_0c03ea2c;
case 0x0c03ea2eu: goto P_0c03ea2e;
case 0x0c03ea30u: goto P_0c03ea30;
case 0x0c03ea32u: goto P_0c03ea32;
case 0x0c03ea34u: goto P_0c03ea34;
case 0x0c03ea36u: goto P_0c03ea36;
case 0x0c03ea38u: goto P_0c03ea38;
case 0x0c03ea3au: goto P_0c03ea3a;
case 0x0c03ea3cu: goto P_0c03ea3c;
case 0x0c03ea3eu: goto P_0c03ea3e;
case 0x0c03ea40u: goto P_0c03ea40;
case 0x0c03ea42u: goto P_0c03ea42;
case 0x0c03ea44u: goto P_0c03ea44;
case 0x0c03ea46u: goto P_0c03ea46;
case 0x0c03ea48u: goto P_0c03ea48;
case 0x0c03ea4au: goto P_0c03ea4a;
case 0x0c03ea4cu: goto P_0c03ea4c;
case 0x0c03ea4eu: goto P_0c03ea4e;
case 0x0c03ea50u: goto P_0c03ea50;
case 0x0c03ea52u: goto P_0c03ea52;
case 0x0c03ea54u: goto P_0c03ea54;
case 0x0c03ea56u: goto P_0c03ea56;
case 0x0c03ea58u: goto P_0c03ea58;
case 0x0c03ea5au: goto P_0c03ea5a;
case 0x0c03ea5cu: goto P_0c03ea5c;
case 0x0c03ea5eu: goto P_0c03ea5e;
case 0x0c03ea60u: goto P_0c03ea60;
case 0x0c03ea62u: goto P_0c03ea62;
case 0x0c03ea64u: goto P_0c03ea64;
case 0x0c03ea66u: goto P_0c03ea66;
case 0x0c03ea68u: goto P_0c03ea68;
case 0x0c03ea6au: goto P_0c03ea6a;
case 0x0c03ea6cu: goto P_0c03ea6c;
case 0x0c03ea6eu: goto P_0c03ea6e;
case 0x0c03ea70u: goto P_0c03ea70;
case 0x0c03ea72u: goto P_0c03ea72;
case 0x0c03ea74u: goto P_0c03ea74;
case 0x0c03ea76u: goto P_0c03ea76;
case 0x0c03ea78u: goto P_0c03ea78;
case 0x0c03ea7au: goto P_0c03ea7a;
case 0x0c03ea7cu: goto P_0c03ea7c;
case 0x0c03ea7eu: goto P_0c03ea7e;
case 0x0c03ea80u: goto P_0c03ea80;
case 0x0c03ea82u: goto P_0c03ea82;
case 0x0c03ea84u: goto P_0c03ea84;
case 0x0c03ea86u: goto P_0c03ea86;
case 0x0c03ea88u: goto P_0c03ea88;
case 0x0c03ea8au: goto P_0c03ea8a;
case 0x0c03ea8cu: goto P_0c03ea8c;
case 0x0c03ea8eu: goto P_0c03ea8e;
case 0x0c03ea90u: goto P_0c03ea90;
case 0x0c03ea92u: goto P_0c03ea92;
case 0x0c03ea94u: goto P_0c03ea94;
case 0x0c03ea96u: goto P_0c03ea96;
case 0x0c03ea98u: goto P_0c03ea98;
case 0x0c03ea9au: goto P_0c03ea9a;
case 0x0c03ea9cu: goto P_0c03ea9c;
case 0x0c03ea9eu: goto P_0c03ea9e;
case 0x0c03eaa0u: goto P_0c03eaa0;
case 0x0c03eaa2u: goto P_0c03eaa2;
case 0x0c03eaa4u: goto P_0c03eaa4;
case 0x0c03eaa6u: goto P_0c03eaa6;
case 0x0c03eaa8u: goto P_0c03eaa8;
case 0x0c03eaaau: goto P_0c03eaaa;
case 0x0c03eaacu: goto P_0c03eaac;
case 0x0c03eaaeu: goto P_0c03eaae;
case 0x0c03eab0u: goto P_0c03eab0;
case 0x0c03eab2u: goto P_0c03eab2;
case 0x0c03eab4u: goto P_0c03eab4;
case 0x0c03eab6u: goto P_0c03eab6;
case 0x0c03eab8u: goto P_0c03eab8;
case 0x0c03eabau: goto P_0c03eaba;
case 0x0c03eabcu: goto P_0c03eabc;
case 0x0c03eabeu: goto P_0c03eabe;
case 0x0c03eac0u: goto P_0c03eac0;
case 0x0c03eac2u: goto P_0c03eac2;
case 0x0c03eac4u: goto P_0c03eac4;
case 0x0c03eac6u: goto P_0c03eac6;
case 0x0c03eac8u: goto P_0c03eac8;
case 0x0c03eacau: goto P_0c03eaca;
case 0x0c03eaccu: goto P_0c03eacc;
case 0x0c03eaceu: goto P_0c03eace;
case 0x0c03f2d0u: goto P_0c03f2d0;
case 0x0c03f2d2u: goto P_0c03f2d2;
case 0x0c03f2d4u: goto P_0c03f2d4;
case 0x0c03f2d6u: goto P_0c03f2d6;
case 0x0c03f2d8u: goto P_0c03f2d8;
case 0x0c03f2dau: goto P_0c03f2da;
case 0x0c03f2dcu: goto P_0c03f2dc;
case 0x0c03f2deu: goto P_0c03f2de;
case 0x0c03f524u: goto P_0c03f524;
case 0x0c03f526u: goto P_0c03f526;
case 0x0c03f528u: goto P_0c03f528;
case 0x0c03f52au: goto P_0c03f52a;
case 0x0c03f52cu: goto P_0c03f52c;
case 0x0c03f52eu: goto P_0c03f52e;
case 0x0c03f530u: goto P_0c03f530;
case 0x0c03f532u: goto P_0c03f532;
case 0x0c03f534u: goto P_0c03f534;
case 0x0c03f536u: goto P_0c03f536;
case 0x0c03f538u: goto P_0c03f538;
case 0x0c03f53au: goto P_0c03f53a;
case 0x0c03f53cu: goto P_0c03f53c;
case 0x0c03f53eu: goto P_0c03f53e;
case 0x0c03f540u: goto P_0c03f540;
case 0x0c03f542u: goto P_0c03f542;
case 0x0c03f544u: goto P_0c03f544;
case 0x0c03f546u: goto P_0c03f546;
case 0x0c03f548u: goto P_0c03f548;
case 0x0c03f54au: goto P_0c03f54a;
case 0x0c03f54cu: goto P_0c03f54c;
case 0x0c03f54eu: goto P_0c03f54e;
case 0x0c03f550u: goto P_0c03f550;
case 0x0c03f552u: goto P_0c03f552;
case 0x0c03f554u: goto P_0c03f554;
case 0x0c03f556u: goto P_0c03f556;
case 0x0c03f558u: goto P_0c03f558;
case 0x0c03f55au: goto P_0c03f55a;
case 0x0c03f55cu: goto P_0c03f55c;
case 0x0c03f55eu: goto P_0c03f55e;
case 0x0c03f560u: goto P_0c03f560;
case 0x0c03f562u: goto P_0c03f562;
case 0x0c03f564u: goto P_0c03f564;
case 0x0c03f566u: goto P_0c03f566;
case 0x0c03f568u: goto P_0c03f568;
case 0x0c03f56au: goto P_0c03f56a;
case 0x0c03f570u: goto P_0c03f570;
case 0x0c03f572u: goto P_0c03f572;
case 0x0c03f574u: goto P_0c03f574;
case 0x0c03f576u: goto P_0c03f576;
case 0x0c03f578u: goto P_0c03f578;
case 0x0c03f57au: goto P_0c03f57a;
case 0x0c03f57cu: goto P_0c03f57c;
case 0x0c03f57eu: goto P_0c03f57e;
case 0x0c03f580u: goto P_0c03f580;
case 0x0c03f582u: goto P_0c03f582;
case 0x0c03f584u: goto P_0c03f584;
case 0x0c03f586u: goto P_0c03f586;
case 0x0c03f588u: goto P_0c03f588;
case 0x0c03f58au: goto P_0c03f58a;
case 0x0c03f58cu: goto P_0c03f58c;
case 0x0c03f58eu: goto P_0c03f58e;
case 0x0c03f590u: goto P_0c03f590;
case 0x0c03f592u: goto P_0c03f592;
case 0x0c03f594u: goto P_0c03f594;
case 0x0c03f596u: goto P_0c03f596;
case 0x0c03f598u: goto P_0c03f598;
case 0x0c043ac6u: goto P_0c043ac6;
case 0x0c043ac8u: goto P_0c043ac8;
case 0x0c043acau: goto P_0c043aca;
case 0x0c043accu: goto P_0c043acc;
case 0x0c043aceu: goto P_0c043ace;
case 0x0c043ad0u: goto P_0c043ad0;
case 0x0c043ad2u: goto P_0c043ad2;
case 0x0c043ad4u: goto P_0c043ad4;
case 0x0c043ad6u: goto P_0c043ad6;
case 0x0c043ad8u: goto P_0c043ad8;
case 0x0c043adau: goto P_0c043ada;
case 0x0c043adcu: goto P_0c043adc;
case 0x0c043adeu: goto P_0c043ade;
case 0x0c043ae0u: goto P_0c043ae0;
case 0x0c043ae2u: goto P_0c043ae2;
case 0x0c043ae4u: goto P_0c043ae4;
case 0x0c043ae6u: goto P_0c043ae6;
case 0x0c043ae8u: goto P_0c043ae8;
case 0x0c043aeau: goto P_0c043aea;
case 0x0c043aecu: goto P_0c043aec;
case 0x0c043aeeu: goto P_0c043aee;
case 0x0c043af0u: goto P_0c043af0;
case 0x0c043af2u: goto P_0c043af2;
case 0x0c043af4u: goto P_0c043af4;
case 0x0c043af6u: goto P_0c043af6;
case 0x0c043af8u: goto P_0c043af8;
case 0x0c043afau: goto P_0c043afa;
case 0x0c043afcu: goto P_0c043afc;
case 0x0c043afeu: goto P_0c043afe;
case 0x0c043b00u: goto P_0c043b00;
case 0x0c043b02u: goto P_0c043b02;
case 0x0c043b04u: goto P_0c043b04;
case 0x0c043b06u: goto P_0c043b06;
case 0x0c043b08u: goto P_0c043b08;
case 0x0c043b0au: goto P_0c043b0a;
case 0x0c043b0cu: goto P_0c043b0c;
case 0x0c043b0eu: goto P_0c043b0e;
case 0x0c043b10u: goto P_0c043b10;
case 0x0c043b12u: goto P_0c043b12;
case 0x0c043b14u: goto P_0c043b14;
case 0x0c043b16u: goto P_0c043b16;
case 0x0c043b18u: goto P_0c043b18;
case 0x0c043b1au: goto P_0c043b1a;
case 0x0c043b1cu: goto P_0c043b1c;
case 0x0c043b1eu: goto P_0c043b1e;
case 0x0c043b20u: goto P_0c043b20;
case 0x0c043b22u: goto P_0c043b22;
case 0x0c043b24u: goto P_0c043b24;
case 0x0c043b26u: goto P_0c043b26;
case 0x0c043b28u: goto P_0c043b28;
case 0x0c043b2au: goto P_0c043b2a;
case 0x0c043b2cu: goto P_0c043b2c;
case 0x0c043b2eu: goto P_0c043b2e;
case 0x0c043b30u: goto P_0c043b30;
case 0x0c043b32u: goto P_0c043b32;
case 0x0c043b34u: goto P_0c043b34;
case 0x0c043b36u: goto P_0c043b36;
case 0x0c043b38u: goto P_0c043b38;
case 0x0c043b3au: goto P_0c043b3a;
case 0x0c043b3cu: goto P_0c043b3c;
case 0x0c043b3eu: goto P_0c043b3e;
case 0x0c043b40u: goto P_0c043b40;
case 0x0c043b42u: goto P_0c043b42;
case 0x0c043b44u: goto P_0c043b44;
case 0x0c043b46u: goto P_0c043b46;
case 0x0c043b48u: goto P_0c043b48;
case 0x0c043b4au: goto P_0c043b4a;
case 0x0c043b4cu: goto P_0c043b4c;
case 0x0c043b4eu: goto P_0c043b4e;
case 0x0c043b50u: goto P_0c043b50;
case 0x0c043b52u: goto P_0c043b52;
case 0x0c043b54u: goto P_0c043b54;
case 0x0c043b56u: goto P_0c043b56;
case 0x0c043b58u: goto P_0c043b58;
case 0x0c043b5au: goto P_0c043b5a;
case 0x0c043b5cu: goto P_0c043b5c;
case 0x0c043b5eu: goto P_0c043b5e;
case 0x0c043b60u: goto P_0c043b60;
case 0x0c043b62u: goto P_0c043b62;
case 0x0c043b64u: goto P_0c043b64;
case 0x0c043b66u: goto P_0c043b66;
case 0x0c043b68u: goto P_0c043b68;
case 0x0c044a74u: goto P_0c044a74;
case 0x0c044a76u: goto P_0c044a76;
case 0x0c044a78u: goto P_0c044a78;
case 0x0c044a7au: goto P_0c044a7a;
case 0x0c044a7cu: goto P_0c044a7c;
case 0x0c044a7eu: goto P_0c044a7e;
case 0x0c044a80u: goto P_0c044a80;
case 0x0c044a82u: goto P_0c044a82;
case 0x0c04596cu: goto P_0c04596c;
case 0x0c04596eu: goto P_0c04596e;
case 0x0c045970u: goto P_0c045970;
case 0x0c045972u: goto P_0c045972;
case 0x0c045974u: goto P_0c045974;
case 0x0c045976u: goto P_0c045976;
case 0x0c045978u: goto P_0c045978;
case 0x0c04597au: goto P_0c04597a;
case 0x0c04597cu: goto P_0c04597c;
case 0x0c04597eu: goto P_0c04597e;
case 0x0c045980u: goto P_0c045980;
case 0x0c045982u: goto P_0c045982;
case 0x0c045984u: goto P_0c045984;
case 0x0c045986u: goto P_0c045986;
case 0x0c045988u: goto P_0c045988;
case 0x0c04598au: goto P_0c04598a;
case 0x0c04598cu: goto P_0c04598c;
case 0x0c04598eu: goto P_0c04598e;
case 0x0c045990u: goto P_0c045990;
case 0x0c045992u: goto P_0c045992;
case 0x0c045994u: goto P_0c045994;
case 0x0c045996u: goto P_0c045996;
case 0x0c045998u: goto P_0c045998;
case 0x0c04599au: goto P_0c04599a;
case 0x0c04599cu: goto P_0c04599c;
case 0x0c04599eu: goto P_0c04599e;
case 0x0c0459a0u: goto P_0c0459a0;
case 0x0c0459a2u: goto P_0c0459a2;
case 0x0c0459a4u: goto P_0c0459a4;
case 0x0c0459a6u: goto P_0c0459a6;
case 0x0c0459a8u: goto P_0c0459a8;
case 0x0c0459aau: goto P_0c0459aa;
case 0x0c0459acu: goto P_0c0459ac;
case 0x0c0459aeu: goto P_0c0459ae;
case 0x0c0459b0u: goto P_0c0459b0;
case 0x0c0459b2u: goto P_0c0459b2;
case 0x0c0459b4u: goto P_0c0459b4;
case 0x0c0459b6u: goto P_0c0459b6;
case 0x0c0459b8u: goto P_0c0459b8;
case 0x0c045f34u: goto P_0c045f34;
case 0x0c045f36u: goto P_0c045f36;
case 0x0c045f38u: goto P_0c045f38;
case 0x0c045f3au: goto P_0c045f3a;
case 0x0c045f3cu: goto P_0c045f3c;
case 0x0c045f3eu: goto P_0c045f3e;
case 0x0c045f40u: goto P_0c045f40;
case 0x0c045f42u: goto P_0c045f42;
case 0x0c045f44u: goto P_0c045f44;
case 0x0c045f46u: goto P_0c045f46;
case 0x0c045f48u: goto P_0c045f48;
case 0x0c045f4au: goto P_0c045f4a;
case 0x0c045f4cu: goto P_0c045f4c;
case 0x0c045f4eu: goto P_0c045f4e;
case 0x0c045f50u: goto P_0c045f50;
case 0x0c045f52u: goto P_0c045f52;
case 0x0c045f54u: goto P_0c045f54;
case 0x0c045f56u: goto P_0c045f56;
case 0x0c045f58u: goto P_0c045f58;
case 0x0c045f5au: goto P_0c045f5a;
case 0x0c045f5cu: goto P_0c045f5c;
case 0x0c045f7eu: goto P_0c045f7e;
case 0x0c045f80u: goto P_0c045f80;
case 0x0c045f82u: goto P_0c045f82;
case 0x0c045f84u: goto P_0c045f84;
case 0x0c045f86u: goto P_0c045f86;
case 0x0c045f88u: goto P_0c045f88;
case 0x0c045f8au: goto P_0c045f8a;
case 0x0c045f8cu: goto P_0c045f8c;
case 0x0c045f8eu: goto P_0c045f8e;
case 0x0c045f90u: goto P_0c045f90;
case 0x0c045f92u: goto P_0c045f92;
case 0x0c045f94u: goto P_0c045f94;
case 0x0c045f96u: goto P_0c045f96;
case 0x0c045f98u: goto P_0c045f98;
case 0x0c045f9au: goto P_0c045f9a;
case 0x0c045f9cu: goto P_0c045f9c;
case 0x0c045f9eu: goto P_0c045f9e;
case 0x0c045fa0u: goto P_0c045fa0;
case 0x0c045fa2u: goto P_0c045fa2;
case 0x0c045fa4u: goto P_0c045fa4;
case 0x0c045fa6u: goto P_0c045fa6;
case 0x0c045fa8u: goto P_0c045fa8;
case 0x0c045faau: goto P_0c045faa;
case 0x0c045facu: goto P_0c045fac;
case 0x0c045faeu: goto P_0c045fae;
case 0x0c045fb0u: goto P_0c045fb0;
case 0x0c045fb2u: goto P_0c045fb2;
case 0x0c045fb4u: goto P_0c045fb4;
case 0x0c045fb6u: goto P_0c045fb6;
case 0x0c045fb8u: goto P_0c045fb8;
case 0x0c045fbau: goto P_0c045fba;
case 0x0c045fbcu: goto P_0c045fbc;
case 0x0c045fbeu: goto P_0c045fbe;
case 0x0c045fc0u: goto P_0c045fc0;
case 0x0c045fc2u: goto P_0c045fc2;
case 0x0c045fc4u: goto P_0c045fc4;
case 0x0c045fc6u: goto P_0c045fc6;
case 0x0c045fc8u: goto P_0c045fc8;
case 0x0c045fcau: goto P_0c045fca;
case 0x0c045fccu: goto P_0c045fcc;
case 0x0c045fceu: goto P_0c045fce;
case 0x0c045fd0u: goto P_0c045fd0;
case 0x0c045fd2u: goto P_0c045fd2;
case 0x0c045fd4u: goto P_0c045fd4;
case 0x0c045fd6u: goto P_0c045fd6;
case 0x0c045fd8u: goto P_0c045fd8;
case 0x0c045fdau: goto P_0c045fda;
case 0x0c045fdcu: goto P_0c045fdc;
case 0x0c045fdeu: goto P_0c045fde;
case 0x0c045fe0u: goto P_0c045fe0;
case 0x0c045fe2u: goto P_0c045fe2;
case 0x0c045fe4u: goto P_0c045fe4;
case 0x0c045fe6u: goto P_0c045fe6;
case 0x0c045fe8u: goto P_0c045fe8;
case 0x0c045feau: goto P_0c045fea;
case 0x0c045fecu: goto P_0c045fec;
case 0x0c045feeu: goto P_0c045fee;
case 0x0c045ff0u: goto P_0c045ff0;
case 0x0c045ff2u: goto P_0c045ff2;
case 0x0c045ff4u: goto P_0c045ff4;
case 0x0c045ff6u: goto P_0c045ff6;
case 0x0c045ff8u: goto P_0c045ff8;
case 0x0c045ffau: goto P_0c045ffa;
case 0x0c045ffcu: goto P_0c045ffc;
case 0x0c045ffeu: goto P_0c045ffe;
case 0x0c046180u: goto P_0c046180;
case 0x0c046182u: goto P_0c046182;
case 0x0c046184u: goto P_0c046184;
case 0x0c046186u: goto P_0c046186;
case 0x0c046188u: goto P_0c046188;
case 0x0c04618au: goto P_0c04618a;
case 0x0c04618cu: goto P_0c04618c;
case 0x0c04618eu: goto P_0c04618e;
case 0x0c046190u: goto P_0c046190;
case 0x0c046192u: goto P_0c046192;
case 0x0c046194u: goto P_0c046194;
case 0x0c046196u: goto P_0c046196;
case 0x0c046198u: goto P_0c046198;
case 0x0c04619au: goto P_0c04619a;
case 0x0c04619cu: goto P_0c04619c;
case 0x0c04619eu: goto P_0c04619e;
case 0x0c0461a0u: goto P_0c0461a0;
case 0x0c0461a2u: goto P_0c0461a2;
case 0x0c0461a4u: goto P_0c0461a4;
case 0x0c0461a6u: goto P_0c0461a6;
case 0x0c0461a8u: goto P_0c0461a8;
case 0x0c0461aau: goto P_0c0461aa;
case 0x0c0461acu: goto P_0c0461ac;
case 0x0c0461aeu: goto P_0c0461ae;
case 0x0c0461b0u: goto P_0c0461b0;
case 0x0c0461b2u: goto P_0c0461b2;
case 0x0c0461b4u: goto P_0c0461b4;
case 0x0c0461b6u: goto P_0c0461b6;
case 0x0c0461b8u: goto P_0c0461b8;
case 0x0c0461bau: goto P_0c0461ba;
case 0x0c0461bcu: goto P_0c0461bc;
case 0x0c0461beu: goto P_0c0461be;
case 0x0c0461c0u: goto P_0c0461c0;
case 0x0c0461c2u: goto P_0c0461c2;
case 0x0c0461c4u: goto P_0c0461c4;
case 0x0c0461c6u: goto P_0c0461c6;
case 0x0c0461c8u: goto P_0c0461c8;
case 0x0c0461cau: goto P_0c0461ca;
case 0x0c0461ccu: goto P_0c0461cc;
case 0x0c0461ceu: goto P_0c0461ce;
case 0x0c0461d0u: goto P_0c0461d0;
case 0x0c0461d2u: goto P_0c0461d2;
case 0x0c04621cu: goto P_0c04621c;
case 0x0c04621eu: goto P_0c04621e;
case 0x0c046220u: goto P_0c046220;
case 0x0c046222u: goto P_0c046222;
case 0x0c046224u: goto P_0c046224;
case 0x0c046226u: goto P_0c046226;
case 0x0c046228u: goto P_0c046228;
case 0x0c04622au: goto P_0c04622a;
case 0x0c04622cu: goto P_0c04622c;
case 0x0c04622eu: goto P_0c04622e;
case 0x0c046230u: goto P_0c046230;
case 0x0c046232u: goto P_0c046232;
case 0x0c046234u: goto P_0c046234;
case 0x0c046236u: goto P_0c046236;
case 0x0c046238u: goto P_0c046238;
case 0x0c04623au: goto P_0c04623a;
case 0x0c04623cu: goto P_0c04623c;
case 0x0c04623eu: goto P_0c04623e;
case 0x0c046240u: goto P_0c046240;
case 0x0c046242u: goto P_0c046242;
case 0x0c046244u: goto P_0c046244;
case 0x0c046246u: goto P_0c046246;
case 0x0c046248u: goto P_0c046248;
case 0x0c04624au: goto P_0c04624a;
case 0x0c04624cu: goto P_0c04624c;
case 0x0c04624eu: goto P_0c04624e;
case 0x0c046250u: goto P_0c046250;
case 0x0c046252u: goto P_0c046252;
case 0x0c046254u: goto P_0c046254;
case 0x0c046256u: goto P_0c046256;
case 0x0c046258u: goto P_0c046258;
case 0x0c04625au: goto P_0c04625a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c035d94: /* original 2fe6, guest PC 0x0c035d94 */
if(!s->budget--) { s->failed_pc=0x0c035d94u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c035d96;
P_0c035d96: /* original 2fd6, guest PC 0x0c035d96 */
if(!s->budget--) { s->failed_pc=0x0c035d96u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c035d98;
P_0c035d98: /* original 2fc6, guest PC 0x0c035d98 */
if(!s->budget--) { s->failed_pc=0x0c035d98u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c035d9a;
P_0c035d9a: /* original 2fb6, guest PC 0x0c035d9a */
if(!s->budget--) { s->failed_pc=0x0c035d9au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c035d9c;
P_0c035d9c: /* original 2fa6, guest PC 0x0c035d9c */
if(!s->budget--) { s->failed_pc=0x0c035d9cu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c035d9e;
P_0c035d9e: /* original 2f96, guest PC 0x0c035d9e */
if(!s->budget--) { s->failed_pc=0x0c035d9eu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c035da0;
P_0c035da0: /* original 2f86, guest PC 0x0c035da0 */
if(!s->budget--) { s->failed_pc=0x0c035da0u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c035da2;
P_0c035da2: /* original de44, guest PC 0x0c035da2 */
if(!s->budget--) { s->failed_pc=0x0c035da2u; return 0; }
r[14]=read(ram,0x0c035eb4u,4);
goto P_0c035da4;
P_0c035da4: /* original d344, guest PC 0x0c035da4 */
if(!s->budget--) { s->failed_pc=0x0c035da4u; return 0; }
r[3]=read(ram,0x0c035eb8u,4);
goto P_0c035da6;
P_0c035da6: /* original 4f22, guest PC 0x0c035da6 */
if(!s->budget--) { s->failed_pc=0x0c035da6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035da8;
P_0c035da8: /* original 6233, guest PC 0x0c035da8 */
if(!s->budget--) { s->failed_pc=0x0c035da8u; return 0; }
r[2]=r[3];
goto P_0c035daa;
P_0c035daa: /* original 2e32, guest PC 0x0c035daa */
if(!s->budget--) { s->failed_pc=0x0c035daau; return 0; }
write(ram,r[14],r[3],4);
goto P_0c035dac;
P_0c035dac: /* original 907a, guest PC 0x0c035dac */
if(!s->budget--) { s->failed_pc=0x0c035dacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035ea4u,2);
goto P_0c035dae;
P_0c035dae: /* original 0246, guest PC 0x0c035dae */
if(!s->budget--) { s->failed_pc=0x0c035daeu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c035db0;
P_0c035db0: /* original 7004, guest PC 0x0c035db0 */
if(!s->budget--) { s->failed_pc=0x0c035db0u; return 0; }
r[0]+=0x00000004u;
goto P_0c035db2;
P_0c035db2: /* original 63e2, guest PC 0x0c035db2 */
if(!s->budget--) { s->failed_pc=0x0c035db2u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035db4;
P_0c035db4: /* original 0366, guest PC 0x0c035db4 */
if(!s->budget--) { s->failed_pc=0x0c035db4u; return 0; }
write(ram,r[3]+r[0],r[6],4);
goto P_0c035db6;
P_0c035db6: /* original 70fc, guest PC 0x0c035db6 */
if(!s->budget--) { s->failed_pc=0x0c035db6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c035db8;
P_0c035db8: /* original 63e2, guest PC 0x0c035db8 */
if(!s->budget--) { s->failed_pc=0x0c035db8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035dba;
P_0c035dba: /* original e61f, guest PC 0x0c035dba */
if(!s->budget--) { s->failed_pc=0x0c035dbau; return 0; }
r[6]=0x0000001fu;
goto P_0c035dbc;
P_0c035dbc: /* original 023e, guest PC 0x0c035dbc */
if(!s->budget--) { s->failed_pc=0x0c035dbcu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035dbe;
P_0c035dbe: /* original 2268, guest PC 0x0c035dbe */
if(!s->budget--) { s->failed_pc=0x0c035dbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c035dc0;
P_0c035dc0: /* original 8d09, guest PC 0x0c035dc0 */
if(!s->budget--) { s->failed_pc=0x0c035dc0u; return 0; }
cond=r[17]&1u;
r[5]=0xffffffe0u;
if(cond) { goto P_0c035dd6; }
goto P_0c035dc4;
P_0c035dc2: /* original e5e0, guest PC 0x0c035dc2 */
if(!s->budget--) { s->failed_pc=0x0c035dc2u; return 0; }
r[5]=0xffffffe0u;
goto P_0c035dc4;
P_0c035dc4: /* original 906e, guest PC 0x0c035dc4 */
if(!s->budget--) { s->failed_pc=0x0c035dc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035ea4u,2);
goto P_0c035dc6;
P_0c035dc6: /* original 61e2, guest PC 0x0c035dc6 */
if(!s->budget--) { s->failed_pc=0x0c035dc6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c035dc8;
P_0c035dc8: /* original 031e, guest PC 0x0c035dc8 */
if(!s->budget--) { s->failed_pc=0x0c035dc8u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c035dca;
P_0c035dca: /* original 7320, guest PC 0x0c035dca */
if(!s->budget--) { s->failed_pc=0x0c035dcau; return 0; }
r[3]+=0x00000020u;
goto P_0c035dcc;
P_0c035dcc: /* original 0136, guest PC 0x0c035dcc */
if(!s->budget--) { s->failed_pc=0x0c035dccu; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c035dce;
P_0c035dce: /* original 63e2, guest PC 0x0c035dce */
if(!s->budget--) { s->failed_pc=0x0c035dceu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035dd0;
P_0c035dd0: /* original 023e, guest PC 0x0c035dd0 */
if(!s->budget--) { s->failed_pc=0x0c035dd0u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035dd2;
P_0c035dd2: /* original 2259, guest PC 0x0c035dd2 */
if(!s->budget--) { s->failed_pc=0x0c035dd2u; return 0; }
r[2]&=r[5];
goto P_0c035dd4;
P_0c035dd4: /* original 0326, guest PC 0x0c035dd4 */
if(!s->budget--) { s->failed_pc=0x0c035dd4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c035dd6;
P_0c035dd6: /* original 9066, guest PC 0x0c035dd6 */
if(!s->budget--) { s->failed_pc=0x0c035dd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035ea6u,2);
goto P_0c035dd8;
P_0c035dd8: /* original 64e2, guest PC 0x0c035dd8 */
if(!s->budget--) { s->failed_pc=0x0c035dd8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c035dda;
P_0c035dda: /* original 034e, guest PC 0x0c035dda */
if(!s->budget--) { s->failed_pc=0x0c035ddau; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c035ddc;
P_0c035ddc: /* original 2638, guest PC 0x0c035ddc */
if(!s->budget--) { s->failed_pc=0x0c035ddcu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c035dde;
P_0c035dde: /* original 8906, guest PC 0x0c035dde */
if(!s->budget--) { s->failed_pc=0x0c035ddeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035dee; }
goto P_0c035de0;
P_0c035de0: /* original 034e, guest PC 0x0c035de0 */
if(!s->budget--) { s->failed_pc=0x0c035de0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c035de2;
P_0c035de2: /* original 7320, guest PC 0x0c035de2 */
if(!s->budget--) { s->failed_pc=0x0c035de2u; return 0; }
r[3]+=0x00000020u;
goto P_0c035de4;
P_0c035de4: /* original 0436, guest PC 0x0c035de4 */
if(!s->budget--) { s->failed_pc=0x0c035de4u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c035de6;
P_0c035de6: /* original 63e2, guest PC 0x0c035de6 */
if(!s->budget--) { s->failed_pc=0x0c035de6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035de8;
P_0c035de8: /* original 023e, guest PC 0x0c035de8 */
if(!s->budget--) { s->failed_pc=0x0c035de8u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035dea;
P_0c035dea: /* original 2259, guest PC 0x0c035dea */
if(!s->budget--) { s->failed_pc=0x0c035deau; return 0; }
r[2]&=r[5];
goto P_0c035dec;
P_0c035dec: /* original 0326, guest PC 0x0c035dec */
if(!s->budget--) { s->failed_pc=0x0c035decu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c035dee;
P_0c035dee: /* original 63e2, guest PC 0x0c035dee */
if(!s->budget--) { s->failed_pc=0x0c035deeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035df0;
P_0c035df0: /* original d132, guest PC 0x0c035df0 */
if(!s->budget--) { s->failed_pc=0x0c035df0u; return 0; }
r[1]=read(ram,0x0c035ebcu,4);
goto P_0c035df2;
P_0c035df2: /* original 023e, guest PC 0x0c035df2 */
if(!s->budget--) { s->failed_pc=0x0c035df2u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035df4;
P_0c035df4: /* original 70fc, guest PC 0x0c035df4 */
if(!s->budget--) { s->failed_pc=0x0c035df4u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c035df6;
P_0c035df6: /* original 2122, guest PC 0x0c035df6 */
if(!s->budget--) { s->failed_pc=0x0c035df6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c035df8;
P_0c035df8: /* original 63e2, guest PC 0x0c035df8 */
if(!s->budget--) { s->failed_pc=0x0c035df8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035dfa;
P_0c035dfa: /* original d431, guest PC 0x0c035dfa */
if(!s->budget--) { s->failed_pc=0x0c035dfau; return 0; }
r[4]=read(ram,0x0c035ec0u,4);
goto P_0c035dfc;
P_0c035dfc: /* original 023e, guest PC 0x0c035dfc */
if(!s->budget--) { s->failed_pc=0x0c035dfcu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035dfe;
P_0c035dfe: /* original 224b, guest PC 0x0c035dfe */
if(!s->budget--) { s->failed_pc=0x0c035dfeu; return 0; }
r[2]|=r[4];
goto P_0c035e00;
P_0c035e00: /* original 0326, guest PC 0x0c035e00 */
if(!s->budget--) { s->failed_pc=0x0c035e00u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c035e02;
P_0c035e02: /* original 7004, guest PC 0x0c035e02 */
if(!s->budget--) { s->failed_pc=0x0c035e02u; return 0; }
r[0]+=0x00000004u;
goto P_0c035e04;
P_0c035e04: /* original 63e2, guest PC 0x0c035e04 */
if(!s->budget--) { s->failed_pc=0x0c035e04u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035e06;
P_0c035e06: /* original 023e, guest PC 0x0c035e06 */
if(!s->budget--) { s->failed_pc=0x0c035e06u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035e08;
P_0c035e08: /* original 224b, guest PC 0x0c035e08 */
if(!s->budget--) { s->failed_pc=0x0c035e08u; return 0; }
r[2]|=r[4];
goto P_0c035e0a;
P_0c035e0a: /* original 0326, guest PC 0x0c035e0a */
if(!s->budget--) { s->failed_pc=0x0c035e0au; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c035e0c;
P_0c035e0c: /* original d32d, guest PC 0x0c035e0c */
if(!s->budget--) { s->failed_pc=0x0c035e0cu; return 0; }
r[3]=read(ram,0x0c035ec4u,4);
goto P_0c035e0e;
P_0c035e0e: /* original 430b, guest PC 0x0c035e0e */
if(!s->budget--) { s->failed_pc=0x0c035e0eu; return 0; }
target=r[3];
r[16]=0x0c035e12u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035e12u) { target=s->pc; goto dispatch; }
goto P_0c035e12;
P_0c035e10: /* original 0009, guest PC 0x0c035e10 */
if(!s->budget--) { s->failed_pc=0x0c035e10u; return 0; }
goto P_0c035e12;
P_0c035e12: /* original d42d, guest PC 0x0c035e12 */
if(!s->budget--) { s->failed_pc=0x0c035e12u; return 0; }
r[4]=read(ram,0x0c035ec8u,4);
goto P_0c035e14;
P_0c035e14: /* original e900, guest PC 0x0c035e14 */
if(!s->budget--) { s->failed_pc=0x0c035e14u; return 0; }
r[9]=0x00000000u;
goto P_0c035e16;
P_0c035e16: /* original d82d, guest PC 0x0c035e16 */
if(!s->budget--) { s->failed_pc=0x0c035e16u; return 0; }
r[8]=read(ram,0x0c035eccu,4);
goto P_0c035e18;
P_0c035e18: /* original ea04, guest PC 0x0c035e18 */
if(!s->budget--) { s->failed_pc=0x0c035e18u; return 0; }
r[10]=0x00000004u;
goto P_0c035e1a;
P_0c035e1a: /* original 6c43, guest PC 0x0c035e1a */
if(!s->budget--) { s->failed_pc=0x0c035e1au; return 0; }
r[12]=r[4];
goto P_0c035e1c;
P_0c035e1c: /* original 6b93, guest PC 0x0c035e1c */
if(!s->budget--) { s->failed_pc=0x0c035e1cu; return 0; }
r[11]=r[9];
goto P_0c035e1e;
P_0c035e1e: /* original 6d43, guest PC 0x0c035e1e */
if(!s->budget--) { s->failed_pc=0x0c035e1eu; return 0; }
r[13]=r[4];
goto P_0c035e20;
P_0c035e20: /* original 9242, guest PC 0x0c035e20 */
if(!s->budget--) { s->failed_pc=0x0c035e20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035ea8u,2);
goto P_0c035e22;
P_0c035e22: /* original 60e2, guest PC 0x0c035e22 */
if(!s->budget--) { s->failed_pc=0x0c035e22u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c035e24;
P_0c035e24: /* original 63c2, guest PC 0x0c035e24 */
if(!s->budget--) { s->failed_pc=0x0c035e24u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c035e26;
P_0c035e26: /* original 320c, guest PC 0x0c035e26 */
if(!s->budget--) { s->failed_pc=0x0c035e26u; return 0; }
r[2]+=r[0];
goto P_0c035e28;
P_0c035e28: /* original 323c, guest PC 0x0c035e28 */
if(!s->budget--) { s->failed_pc=0x0c035e28u; return 0; }
r[2]+=r[3];
goto P_0c035e2a;
P_0c035e2a: /* original 6120, guest PC 0x0c035e2a */
if(!s->budget--) { s->failed_pc=0x0c035e2au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c035e2c;
P_0c035e2c: /* original 2118, guest PC 0x0c035e2c */
if(!s->budget--) { s->failed_pc=0x0c035e2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c035e2e;
P_0c035e2e: /* original 8901, guest PC 0x0c035e2e */
if(!s->budget--) { s->failed_pc=0x0c035e2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035e34; }
goto P_0c035e30;
P_0c035e30: /* original 480b, guest PC 0x0c035e30 */
if(!s->budget--) { s->failed_pc=0x0c035e30u; return 0; }
target=r[8];
r[16]=0x0c035e34u;
tmp=read(ram,r[13],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035e34u) { target=s->pc; goto dispatch; }
goto P_0c035e34;
P_0c035e32: /* original 64d2, guest PC 0x0c035e32 */
if(!s->budget--) { s->failed_pc=0x0c035e32u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c035e34;
P_0c035e34: /* original 7b01, guest PC 0x0c035e34 */
if(!s->budget--) { s->failed_pc=0x0c035e34u; return 0; }
r[11]+=0x00000001u;
goto P_0c035e36;
P_0c035e36: /* original 3ba3, guest PC 0x0c035e36 */
if(!s->budget--) { s->failed_pc=0x0c035e36u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[10])!=0);
goto P_0c035e38;
P_0c035e38: /* original 7d04, guest PC 0x0c035e38 */
if(!s->budget--) { s->failed_pc=0x0c035e38u; return 0; }
r[13]+=0x00000004u;
goto P_0c035e3a;
P_0c035e3a: /* original 8ff1, guest PC 0x0c035e3a */
if(!s->budget--) { s->failed_pc=0x0c035e3au; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c035e20; }
goto P_0c035e3e;
P_0c035e3c: /* original 7c04, guest PC 0x0c035e3c */
if(!s->budget--) { s->failed_pc=0x0c035e3cu; return 0; }
r[12]+=0x00000004u;
goto P_0c035e3e;
P_0c035e3e: /* original d224, guest PC 0x0c035e3e */
if(!s->budget--) { s->failed_pc=0x0c035e3eu; return 0; }
r[2]=read(ram,0x0c035ed0u,4);
goto P_0c035e40;
P_0c035e40: /* original 420b, guest PC 0x0c035e40 */
if(!s->budget--) { s->failed_pc=0x0c035e40u; return 0; }
target=r[2];
r[16]=0x0c035e44u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035e44u) { target=s->pc; goto dispatch; }
goto P_0c035e44;
P_0c035e42: /* original 0009, guest PC 0x0c035e42 */
if(!s->budget--) { s->failed_pc=0x0c035e42u; return 0; }
goto P_0c035e44;
P_0c035e44: /* original 9031, guest PC 0x0c035e44 */
if(!s->budget--) { s->failed_pc=0x0c035e44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035eaau,2);
goto P_0c035e46;
P_0c035e46: /* original e401, guest PC 0x0c035e46 */
if(!s->budget--) { s->failed_pc=0x0c035e46u; return 0; }
r[4]=0x00000001u;
goto P_0c035e48;
P_0c035e48: /* original 63e2, guest PC 0x0c035e48 */
if(!s->budget--) { s->failed_pc=0x0c035e48u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035e4a;
P_0c035e4a: /* original 0346, guest PC 0x0c035e4a */
if(!s->budget--) { s->failed_pc=0x0c035e4au; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c035e4c;
P_0c035e4c: /* original 902e, guest PC 0x0c035e4c */
if(!s->budget--) { s->failed_pc=0x0c035e4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035eacu,2);
goto P_0c035e4e;
P_0c035e4e: /* original 63e2, guest PC 0x0c035e4e */
if(!s->budget--) { s->failed_pc=0x0c035e4eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035e50;
P_0c035e50: /* original d120, guest PC 0x0c035e50 */
if(!s->budget--) { s->failed_pc=0x0c035e50u; return 0; }
r[1]=read(ram,0x0c035ed4u,4);
goto P_0c035e52;
P_0c035e52: /* original 023e, guest PC 0x0c035e52 */
if(!s->budget--) { s->failed_pc=0x0c035e52u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035e54;
P_0c035e54: /* original 902b, guest PC 0x0c035e54 */
if(!s->budget--) { s->failed_pc=0x0c035e54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035eaeu,2);
goto P_0c035e56;
P_0c035e56: /* original 0216, guest PC 0x0c035e56 */
if(!s->budget--) { s->failed_pc=0x0c035e56u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c035e58;
P_0c035e58: /* original 9028, guest PC 0x0c035e58 */
if(!s->budget--) { s->failed_pc=0x0c035e58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035eacu,2);
goto P_0c035e5a;
P_0c035e5a: /* original 63e2, guest PC 0x0c035e5a */
if(!s->budget--) { s->failed_pc=0x0c035e5au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035e5c;
P_0c035e5c: /* original 023e, guest PC 0x0c035e5c */
if(!s->budget--) { s->failed_pc=0x0c035e5cu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035e5e;
P_0c035e5e: /* original 1294, guest PC 0x0c035e5e */
if(!s->budget--) { s->failed_pc=0x0c035e5eu; return 0; }
write(ram,r[2]+16,r[9],4);
goto P_0c035e60;
P_0c035e60: /* original 63e2, guest PC 0x0c035e60 */
if(!s->budget--) { s->failed_pc=0x0c035e60u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035e62;
P_0c035e62: /* original 023e, guest PC 0x0c035e62 */
if(!s->budget--) { s->failed_pc=0x0c035e62u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035e64;
P_0c035e64: /* original 70dc, guest PC 0x0c035e64 */
if(!s->budget--) { s->failed_pc=0x0c035e64u; return 0; }
r[0]+=0xffffffdcu;
goto P_0c035e66;
P_0c035e66: /* original 6133, guest PC 0x0c035e66 */
if(!s->budget--) { s->failed_pc=0x0c035e66u; return 0; }
r[1]=r[3];
goto P_0c035e68;
P_0c035e68: /* original 033e, guest PC 0x0c035e68 */
if(!s->budget--) { s->failed_pc=0x0c035e68u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c035e6a;
P_0c035e6a: /* original 70f0, guest PC 0x0c035e6a */
if(!s->budget--) { s->failed_pc=0x0c035e6au; return 0; }
r[0]+=0xfffffff0u;
goto P_0c035e6c;
P_0c035e6c: /* original 011e, guest PC 0x0c035e6c */
if(!s->budget--) { s->failed_pc=0x0c035e6cu; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c035e6e;
P_0c035e6e: /* original 901f, guest PC 0x0c035e6e */
if(!s->budget--) { s->failed_pc=0x0c035e6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035eb0u,2);
goto P_0c035e70;
P_0c035e70: /* original 213b, guest PC 0x0c035e70 */
if(!s->budget--) { s->failed_pc=0x0c035e70u; return 0; }
r[1]|=r[3];
goto P_0c035e72;
P_0c035e72: /* original 0216, guest PC 0x0c035e72 */
if(!s->budget--) { s->failed_pc=0x0c035e72u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c035e74;
P_0c035e74: /* original 901a, guest PC 0x0c035e74 */
if(!s->budget--) { s->failed_pc=0x0c035e74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c035eacu,2);
goto P_0c035e76;
P_0c035e76: /* original 63e2, guest PC 0x0c035e76 */
if(!s->budget--) { s->failed_pc=0x0c035e76u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035e78;
P_0c035e78: /* original 023e, guest PC 0x0c035e78 */
if(!s->budget--) { s->failed_pc=0x0c035e78u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c035e7a;
P_0c035e7a: /* original 1245, guest PC 0x0c035e7a */
if(!s->budget--) { s->failed_pc=0x0c035e7au; return 0; }
write(ram,r[2]+20,r[4],4);
goto P_0c035e7c;
P_0c035e7c: /* original 4f26, guest PC 0x0c035e7c */
if(!s->budget--) { s->failed_pc=0x0c035e7cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035e7e;
P_0c035e7e: /* original 6093, guest PC 0x0c035e7e */
if(!s->budget--) { s->failed_pc=0x0c035e7eu; return 0; }
r[0]=r[9];
goto P_0c035e80;
P_0c035e80: /* original 68f6, guest PC 0x0c035e80 */
if(!s->budget--) { s->failed_pc=0x0c035e80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c035e82;
P_0c035e82: /* original 69f6, guest PC 0x0c035e82 */
if(!s->budget--) { s->failed_pc=0x0c035e82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c035e84;
P_0c035e84: /* original 6af6, guest PC 0x0c035e84 */
if(!s->budget--) { s->failed_pc=0x0c035e84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035e86;
P_0c035e86: /* original 6bf6, guest PC 0x0c035e86 */
if(!s->budget--) { s->failed_pc=0x0c035e86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035e88;
P_0c035e88: /* original 6cf6, guest PC 0x0c035e88 */
if(!s->budget--) { s->failed_pc=0x0c035e88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035e8a;
P_0c035e8a: /* original 6df6, guest PC 0x0c035e8a */
if(!s->budget--) { s->failed_pc=0x0c035e8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c035e8c;
P_0c035e8c: /* original 000b, guest PC 0x0c035e8c */
if(!s->budget--) { s->failed_pc=0x0c035e8cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035e8e: /* original 6ef6, guest PC 0x0c035e8e */
if(!s->budget--) { s->failed_pc=0x0c035e8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c035e90u,s,ram);
P_0c036356: /* original 4f22, guest PC 0x0c036356 */
if(!s->budget--) { s->failed_pc=0x0c036356u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036358;
P_0c036358: /* original da26, guest PC 0x0c036358 */
if(!s->budget--) { s->failed_pc=0x0c036358u; return 0; }
r[10]=read(ram,0x0c0363f4u,4);
goto P_0c03635a;
P_0c03635a: /* original a027, guest PC 0x0c03635a */
if(!s->budget--) { s->failed_pc=0x0c03635au; return 0; }
r[14]=r[8];
goto P_0c0363ac;
P_0c03635c: /* original 6e83, guest PC 0x0c03635c */
if(!s->budget--) { s->failed_pc=0x0c03635cu; return 0; }
r[14]=r[8];
goto P_0c03635e;
P_0c03635e: /* original d026, guest PC 0x0c03635e */
if(!s->budget--) { s->failed_pc=0x0c03635eu; return 0; }
r[0]=read(ram,0x0c0363f8u,4);
goto P_0c036360;
P_0c036360: /* original 63e3, guest PC 0x0c036360 */
if(!s->budget--) { s->failed_pc=0x0c036360u; return 0; }
r[3]=r[14];
goto P_0c036362;
P_0c036362: /* original 4308, guest PC 0x0c036362 */
if(!s->budget--) { s->failed_pc=0x0c036362u; return 0; }
r[3]<<=2;
goto P_0c036364;
P_0c036364: /* original 913e, guest PC 0x0c036364 */
if(!s->budget--) { s->failed_pc=0x0c036364u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0363e4u,2);
goto P_0c036366;
P_0c036366: /* original 023e, guest PC 0x0c036366 */
if(!s->budget--) { s->failed_pc=0x0c036366u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c036368;
P_0c036368: /* original 60a2, guest PC 0x0c036368 */
if(!s->budget--) { s->failed_pc=0x0c036368u; return 0; }
tmp=read(ram,r[10],4);
r[0]=tmp;
goto P_0c03636a;
P_0c03636a: /* original 310c, guest PC 0x0c03636a */
if(!s->budget--) { s->failed_pc=0x0c03636au; return 0; }
r[1]+=r[0];
goto P_0c03636c;
P_0c03636c: /* original 321c, guest PC 0x0c03636c */
if(!s->budget--) { s->failed_pc=0x0c03636cu; return 0; }
r[2]+=r[1];
goto P_0c03636e;
P_0c03636e: /* original 6320, guest PC 0x0c03636e */
if(!s->budget--) { s->failed_pc=0x0c03636eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c036370;
P_0c036370: /* original 2338, guest PC 0x0c036370 */
if(!s->budget--) { s->failed_pc=0x0c036370u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c036372;
P_0c036372: /* original 891a, guest PC 0x0c036372 */
if(!s->budget--) { s->failed_pc=0x0c036372u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0363aa; }
goto P_0c036374;
P_0c036374: /* original d221, guest PC 0x0c036374 */
if(!s->budget--) { s->failed_pc=0x0c036374u; return 0; }
r[2]=read(ram,0x0c0363fcu,4);
goto P_0c036376;
P_0c036376: /* original 420b, guest PC 0x0c036376 */
if(!s->budget--) { s->failed_pc=0x0c036376u; return 0; }
target=r[2];
r[16]=0x0c03637au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03637au) { target=s->pc; goto dispatch; }
goto P_0c03637a;
P_0c036378: /* original 64e3, guest PC 0x0c036378 */
if(!s->budget--) { s->failed_pc=0x0c036378u; return 0; }
r[4]=r[14];
goto P_0c03637a;
P_0c03637a: /* original 63e3, guest PC 0x0c03637a */
if(!s->budget--) { s->failed_pc=0x0c03637au; return 0; }
r[3]=r[14];
goto P_0c03637c;
P_0c03637c: /* original 64e3, guest PC 0x0c03637c */
if(!s->budget--) { s->failed_pc=0x0c03637cu; return 0; }
r[4]=r[14];
goto P_0c03637e;
P_0c03637e: /* original 4308, guest PC 0x0c03637e */
if(!s->budget--) { s->failed_pc=0x0c03637eu; return 0; }
r[3]<<=2;
goto P_0c036380;
P_0c036380: /* original 6b83, guest PC 0x0c036380 */
if(!s->budget--) { s->failed_pc=0x0c036380u; return 0; }
r[11]=r[8];
goto P_0c036382;
P_0c036382: /* original 4400, guest PC 0x0c036382 */
if(!s->budget--) { s->failed_pc=0x0c036382u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c036384;
P_0c036384: /* original 343c, guest PC 0x0c036384 */
if(!s->budget--) { s->failed_pc=0x0c036384u; return 0; }
r[4]+=r[3];
goto P_0c036386;
P_0c036386: /* original 6c43, guest PC 0x0c036386 */
if(!s->budget--) { s->failed_pc=0x0c036386u; return 0; }
r[12]=r[4];
goto P_0c036388;
P_0c036388: /* original 6d43, guest PC 0x0c036388 */
if(!s->budget--) { s->failed_pc=0x0c036388u; return 0; }
r[13]=r[4];
goto P_0c03638a;
P_0c03638a: /* original 932b, guest PC 0x0c03638a */
if(!s->budget--) { s->failed_pc=0x0c03638au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0363e4u,2);
goto P_0c03638c;
P_0c03638c: /* original 60a2, guest PC 0x0c03638c */
if(!s->budget--) { s->failed_pc=0x0c03638cu; return 0; }
tmp=read(ram,r[10],4);
r[0]=tmp;
goto P_0c03638e;
P_0c03638e: /* original 330c, guest PC 0x0c03638e */
if(!s->budget--) { s->failed_pc=0x0c03638eu; return 0; }
r[3]+=r[0];
goto P_0c036390;
P_0c036390: /* original 33cc, guest PC 0x0c036390 */
if(!s->budget--) { s->failed_pc=0x0c036390u; return 0; }
r[3]+=r[12];
goto P_0c036392;
P_0c036392: /* original 6230, guest PC 0x0c036392 */
if(!s->budget--) { s->failed_pc=0x0c036392u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c036394;
P_0c036394: /* original 2228, guest PC 0x0c036394 */
if(!s->budget--) { s->failed_pc=0x0c036394u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c036396;
P_0c036396: /* original 8903, guest PC 0x0c036396 */
if(!s->budget--) { s->failed_pc=0x0c036396u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0363a0; }
goto P_0c036398;
P_0c036398: /* original d319, guest PC 0x0c036398 */
if(!s->budget--) { s->failed_pc=0x0c036398u; return 0; }
r[3]=read(ram,0x0c036400u,4);
goto P_0c03639a;
P_0c03639a: /* original 65e3, guest PC 0x0c03639a */
if(!s->budget--) { s->failed_pc=0x0c03639au; return 0; }
r[5]=r[14];
goto P_0c03639c;
P_0c03639c: /* original 430b, guest PC 0x0c03639c */
if(!s->budget--) { s->failed_pc=0x0c03639cu; return 0; }
target=r[3];
r[16]=0x0c0363a0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0363a0u) { target=s->pc; goto dispatch; }
goto P_0c0363a0;
P_0c03639e: /* original 64d3, guest PC 0x0c03639e */
if(!s->budget--) { s->failed_pc=0x0c03639eu; return 0; }
r[4]=r[13];
goto P_0c0363a0;
P_0c0363a0: /* original 7b01, guest PC 0x0c0363a0 */
if(!s->budget--) { s->failed_pc=0x0c0363a0u; return 0; }
r[11]+=0x00000001u;
goto P_0c0363a2;
P_0c0363a2: /* original 3b93, guest PC 0x0c0363a2 */
if(!s->budget--) { s->failed_pc=0x0c0363a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[9])!=0);
goto P_0c0363a4;
P_0c0363a4: /* original 7d01, guest PC 0x0c0363a4 */
if(!s->budget--) { s->failed_pc=0x0c0363a4u; return 0; }
r[13]+=0x00000001u;
goto P_0c0363a6;
P_0c0363a6: /* original 8ff0, guest PC 0x0c0363a6 */
if(!s->budget--) { s->failed_pc=0x0c0363a6u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c03638a; }
goto P_0c0363aa;
P_0c0363a8: /* original 7c01, guest PC 0x0c0363a8 */
if(!s->budget--) { s->failed_pc=0x0c0363a8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0363aa;
P_0c0363aa: /* original 7e01, guest PC 0x0c0363aa */
if(!s->budget--) { s->failed_pc=0x0c0363aau; return 0; }
r[14]+=0x00000001u;
goto P_0c0363ac;
P_0c0363ac: /* original e304, guest PC 0x0c0363ac */
if(!s->budget--) { s->failed_pc=0x0c0363acu; return 0; }
r[3]=0x00000004u;
goto P_0c0363ae;
P_0c0363ae: /* original 3e33, guest PC 0x0c0363ae */
if(!s->budget--) { s->failed_pc=0x0c0363aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0363b0;
P_0c0363b0: /* original 8bd5, guest PC 0x0c0363b0 */
if(!s->budget--) { s->failed_pc=0x0c0363b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03635e; }
goto P_0c0363b2;
P_0c0363b2: /* original 4f26, guest PC 0x0c0363b2 */
if(!s->budget--) { s->failed_pc=0x0c0363b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0363b4;
P_0c0363b4: /* original e000, guest PC 0x0c0363b4 */
if(!s->budget--) { s->failed_pc=0x0c0363b4u; return 0; }
r[0]=0x00000000u;
goto P_0c0363b6;
P_0c0363b6: /* original 68f6, guest PC 0x0c0363b6 */
if(!s->budget--) { s->failed_pc=0x0c0363b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0363b8;
P_0c0363b8: /* original 69f6, guest PC 0x0c0363b8 */
if(!s->budget--) { s->failed_pc=0x0c0363b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0363ba;
P_0c0363ba: /* original 6af6, guest PC 0x0c0363ba */
if(!s->budget--) { s->failed_pc=0x0c0363bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0363bc;
P_0c0363bc: /* original 6bf6, guest PC 0x0c0363bc */
if(!s->budget--) { s->failed_pc=0x0c0363bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0363be;
P_0c0363be: /* original 6cf6, guest PC 0x0c0363be */
if(!s->budget--) { s->failed_pc=0x0c0363beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0363c0;
P_0c0363c0: /* original 6df6, guest PC 0x0c0363c0 */
if(!s->budget--) { s->failed_pc=0x0c0363c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0363c2;
P_0c0363c2: /* original 000b, guest PC 0x0c0363c2 */
if(!s->budget--) { s->failed_pc=0x0c0363c2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0363c4: /* original 6ef6, guest PC 0x0c0363c4 */
if(!s->budget--) { s->failed_pc=0x0c0363c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0363c6u,s,ram);
P_0c03709c: /* original 0602, guest PC 0x0c03709c */
if(!s->budget--) { s->failed_pc=0x0c03709cu; return 0; }
r[6]=r[17];
goto P_0c03709e;
P_0c03709e: /* original 931d, guest PC 0x0c03709e */
if(!s->budget--) { s->failed_pc=0x0c03709eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0370dcu,2);
goto P_0c0370a0;
P_0c0370a0: /* original 236b, guest PC 0x0c0370a0 */
if(!s->budget--) { s->failed_pc=0x0c0370a0u; return 0; }
r[3]|=r[6];
goto P_0c0370a2;
P_0c0370a2: /* original 430e, guest PC 0x0c0370a2 */
if(!s->budget--) { s->failed_pc=0x0c0370a2u; return 0; }
r[17]=r[3];
goto P_0c0370a4;
P_0c0370a4: /* original 931b, guest PC 0x0c0370a4 */
if(!s->budget--) { s->failed_pc=0x0c0370a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0370deu,2);
goto P_0c0370a6;
P_0c0370a6: /* original 0222, guest PC 0x0c0370a6 */
if(!s->budget--) { s->failed_pc=0x0c0370a6u; return 0; }
s->failed_pc=0x0c0370a6u; return 0;
goto P_0c0370a8;
P_0c0370a8: /* original 343c, guest PC 0x0c0370a8 */
if(!s->budget--) { s->failed_pc=0x0c0370a8u; return 0; }
r[4]+=r[3];
goto P_0c0370aa;
P_0c0370aa: /* original 4409, guest PC 0x0c0370aa */
if(!s->budget--) { s->failed_pc=0x0c0370aau; return 0; }
r[4]>>=2;
goto P_0c0370ac;
P_0c0370ac: /* original 4401, guest PC 0x0c0370ac */
if(!s->budget--) { s->failed_pc=0x0c0370acu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0370ae;
P_0c0370ae: /* original 324c, guest PC 0x0c0370ae */
if(!s->budget--) { s->failed_pc=0x0c0370aeu; return 0; }
r[2]+=r[4];
goto P_0c0370b0;
P_0c0370b0: /* original 9416, guest PC 0x0c0370b0 */
if(!s->budget--) { s->failed_pc=0x0c0370b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0370e0u,2);
goto P_0c0370b2;
P_0c0370b2: /* original 342c, guest PC 0x0c0370b2 */
if(!s->budget--) { s->failed_pc=0x0c0370b2u; return 0; }
r[4]+=r[2];
goto P_0c0370b4;
P_0c0370b4: /* original 6042, guest PC 0x0c0370b4 */
if(!s->budget--) { s->failed_pc=0x0c0370b4u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0370b6;
P_0c0370b6: /* original 2452, guest PC 0x0c0370b6 */
if(!s->budget--) { s->failed_pc=0x0c0370b6u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0370b8;
P_0c0370b8: /* original 460e, guest PC 0x0c0370b8 */
if(!s->budget--) { s->failed_pc=0x0c0370b8u; return 0; }
r[17]=r[6];
goto P_0c0370ba;
P_0c0370ba: /* original 000b, guest PC 0x0c0370ba */
if(!s->budget--) { s->failed_pc=0x0c0370bau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0370bc: /* original 0009, guest PC 0x0c0370bc */
if(!s->budget--) { s->failed_pc=0x0c0370bcu; return 0; }
return vf3_matrix_family(0x0c0370beu,s,ram);
P_0c03866c: /* original 4f22, guest PC 0x0c03866c */
if(!s->budget--) { s->failed_pc=0x0c03866cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03866e;
P_0c03866e: /* original 7d01, guest PC 0x0c03866e */
if(!s->budget--) { s->failed_pc=0x0c03866eu; return 0; }
r[13]+=0x00000001u;
goto P_0c038670;
P_0c038670: /* original 4f12, guest PC 0x0c038670 */
if(!s->budget--) { s->failed_pc=0x0c038670u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c038672;
P_0c038672: /* original 7ffc, guest PC 0x0c038672 */
if(!s->budget--) { s->failed_pc=0x0c038672u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c038674;
P_0c038674: /* original 2f42, guest PC 0x0c038674 */
if(!s->budget--) { s->failed_pc=0x0c038674u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c038676;
P_0c038676: /* original b1eb, guest PC 0x0c038676 */
if(!s->budget--) { s->failed_pc=0x0c038676u; return 0; }
target=0x0c038a50u; r[16]=0x0c03867au;
r[5]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03867au) { target=s->pc; goto dispatch; }
goto P_0c03867a;
P_0c038678: /* original 65d3, guest PC 0x0c038678 */
if(!s->budget--) { s->failed_pc=0x0c038678u; return 0; }
r[5]=r[13];
goto P_0c03867a;
P_0c03867a: /* original e43c, guest PC 0x0c03867a */
if(!s->budget--) { s->failed_pc=0x0c03867au; return 0; }
r[4]=0x0000003cu;
goto P_0c03867c;
P_0c03867c: /* original 63f2, guest PC 0x0c03867c */
if(!s->budget--) { s->failed_pc=0x0c03867cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c03867e;
P_0c03867e: /* original 0d47, guest PC 0x0c03867e */
if(!s->budget--) { s->failed_pc=0x0c03867eu; return 0; }
r[19]=r[13]*r[4];
goto P_0c038680;
P_0c038680: /* original d66d, guest PC 0x0c038680 */
if(!s->budget--) { s->failed_pc=0x0c038680u; return 0; }
r[6]=read(ram,0x0c038838u,4);
goto P_0c038682;
P_0c038682: /* original 61e3, guest PC 0x0c038682 */
if(!s->budget--) { s->failed_pc=0x0c038682u; return 0; }
r[1]=r[14];
goto P_0c038684;
P_0c038684: /* original 711f, guest PC 0x0c038684 */
if(!s->budget--) { s->failed_pc=0x0c038684u; return 0; }
r[1]+=0x0000001fu;
goto P_0c038686;
P_0c038686: /* original 041a, guest PC 0x0c038686 */
if(!s->budget--) { s->failed_pc=0x0c038686u; return 0; }
r[4]=r[19];
goto P_0c038688;
P_0c038688: /* original 343c, guest PC 0x0c038688 */
if(!s->budget--) { s->failed_pc=0x0c038688u; return 0; }
r[4]+=r[3];
goto P_0c03868a;
P_0c03868a: /* original 63e3, guest PC 0x0c03868a */
if(!s->budget--) { s->failed_pc=0x0c03868au; return 0; }
r[3]=r[14];
goto P_0c03868c;
P_0c03868c: /* original 4308, guest PC 0x0c03868c */
if(!s->budget--) { s->failed_pc=0x0c03868cu; return 0; }
r[3]<<=2;
goto P_0c03868e;
P_0c03868e: /* original 4300, guest PC 0x0c03868e */
if(!s->budget--) { s->failed_pc=0x0c03868eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c038690;
P_0c038690: /* original 7408, guest PC 0x0c038690 */
if(!s->budget--) { s->failed_pc=0x0c038690u; return 0; }
r[4]+=0x00000008u;
goto P_0c038692;
P_0c038692: /* original 334c, guest PC 0x0c038692 */
if(!s->budget--) { s->failed_pc=0x0c038692u; return 0; }
r[3]+=r[4];
goto P_0c038694;
P_0c038694: /* original 2642, guest PC 0x0c038694 */
if(!s->budget--) { s->failed_pc=0x0c038694u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c038696;
P_0c038696: /* original dd69, guest PC 0x0c038696 */
if(!s->budget--) { s->failed_pc=0x0c038696u; return 0; }
r[13]=read(ram,0x0c03883cu,4);
goto P_0c038698;
P_0c038698: /* original 2d32, guest PC 0x0c038698 */
if(!s->budget--) { s->failed_pc=0x0c038698u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c03869a;
P_0c03869a: /* original d36a, guest PC 0x0c03869a */
if(!s->budget--) { s->failed_pc=0x0c03869au; return 0; }
r[3]=read(ram,0x0c038844u,4);
goto P_0c03869c;
P_0c03869c: /* original db68, guest PC 0x0c03869c */
if(!s->budget--) { s->failed_pc=0x0c03869cu; return 0; }
r[11]=read(ram,0x0c038840u,4);
goto P_0c03869e;
P_0c03869e: /* original 430b, guest PC 0x0c03869e */
if(!s->budget--) { s->failed_pc=0x0c03869eu; return 0; }
target=r[3];
r[16]=0x0c0386a2u;
r[0]=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0386a2u) { target=s->pc; goto dispatch; }
goto P_0c0386a2;
P_0c0386a0: /* original e020, guest PC 0x0c0386a0 */
if(!s->budget--) { s->failed_pc=0x0c0386a0u; return 0; }
r[0]=0x00000020u;
goto P_0c0386a2;
P_0c0386a2: /* original 2b02, guest PC 0x0c0386a2 */
if(!s->budget--) { s->failed_pc=0x0c0386a2u; return 0; }
write(ram,r[11],r[0],4);
goto P_0c0386a4;
P_0c0386a4: /* original 7eff, guest PC 0x0c0386a4 */
if(!s->budget--) { s->failed_pc=0x0c0386a4u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0386a6;
P_0c0386a6: /* original d068, guest PC 0x0c0386a6 */
if(!s->budget--) { s->failed_pc=0x0c0386a6u; return 0; }
r[0]=read(ram,0x0c038848u,4);
goto P_0c0386a8;
P_0c0386a8: /* original e400, guest PC 0x0c0386a8 */
if(!s->budget--) { s->failed_pc=0x0c0386a8u; return 0; }
r[4]=0x00000000u;
goto P_0c0386aa;
P_0c0386aa: /* original 20e2, guest PC 0x0c0386aa */
if(!s->budget--) { s->failed_pc=0x0c0386aau; return 0; }
write(ram,r[0],r[14],4);
goto P_0c0386ac;
P_0c0386ac: /* original eeff, guest PC 0x0c0386ac */
if(!s->budget--) { s->failed_pc=0x0c0386acu; return 0; }
r[14]=0xffffffffu;
goto P_0c0386ae;
P_0c0386ae: /* original 67e3, guest PC 0x0c0386ae */
if(!s->budget--) { s->failed_pc=0x0c0386aeu; return 0; }
r[7]=r[14];
goto P_0c0386b0;
P_0c0386b0: /* original a00e, guest PC 0x0c0386b0 */
if(!s->budget--) { s->failed_pc=0x0c0386b0u; return 0; }
r[5]=0xfffffff8u;
goto P_0c0386d0;
P_0c0386b2: /* original e5f8, guest PC 0x0c0386b2 */
if(!s->budget--) { s->failed_pc=0x0c0386b2u; return 0; }
r[5]=0xfffffff8u;
return vf3_matrix_family(0x0c0386b4u,s,ram);
P_0c0386c0: /* original 6362, guest PC 0x0c0386c0 */
if(!s->budget--) { s->failed_pc=0x0c0386c0u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c0386c2;
P_0c0386c2: /* original 7701, guest PC 0x0c0386c2 */
if(!s->budget--) { s->failed_pc=0x0c0386c2u; return 0; }
r[7]+=0x00000001u;
goto P_0c0386c4;
P_0c0386c4: /* original 335c, guest PC 0x0c0386c4 */
if(!s->budget--) { s->failed_pc=0x0c0386c4u; return 0; }
r[3]+=r[5];
goto P_0c0386c6;
P_0c0386c6: /* original 2342, guest PC 0x0c0386c6 */
if(!s->budget--) { s->failed_pc=0x0c0386c6u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0386c8;
P_0c0386c8: /* original 6262, guest PC 0x0c0386c8 */
if(!s->budget--) { s->failed_pc=0x0c0386c8u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0386ca;
P_0c0386ca: /* original 325c, guest PC 0x0c0386ca */
if(!s->budget--) { s->failed_pc=0x0c0386cau; return 0; }
r[2]+=r[5];
goto P_0c0386cc;
P_0c0386cc: /* original 7508, guest PC 0x0c0386cc */
if(!s->budget--) { s->failed_pc=0x0c0386ccu; return 0; }
r[5]+=0x00000008u;
goto P_0c0386ce;
P_0c0386ce: /* original 12e1, guest PC 0x0c0386ce */
if(!s->budget--) { s->failed_pc=0x0c0386ceu; return 0; }
write(ram,r[2]+4,r[14],4);
goto P_0c0386d0;
P_0c0386d0: /* original 6302, guest PC 0x0c0386d0 */
if(!s->budget--) { s->failed_pc=0x0c0386d0u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0386d2;
P_0c0386d2: /* original 3733, guest PC 0x0c0386d2 */
if(!s->budget--) { s->failed_pc=0x0c0386d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[3])!=0);
goto P_0c0386d4;
P_0c0386d4: /* original 8bf4, guest PC 0x0c0386d4 */
if(!s->budget--) { s->failed_pc=0x0c0386d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0386c0; }
goto P_0c0386d6;
P_0c0386d6: /* original 6643, guest PC 0x0c0386d6 */
if(!s->budget--) { s->failed_pc=0x0c0386d6u; return 0; }
r[6]=r[4];
goto P_0c0386d8;
P_0c0386d8: /* original a006, guest PC 0x0c0386d8 */
if(!s->budget--) { s->failed_pc=0x0c0386d8u; return 0; }
r[5]=r[4];
goto P_0c0386e8;
P_0c0386da: /* original 6543, guest PC 0x0c0386da */
if(!s->budget--) { s->failed_pc=0x0c0386dau; return 0; }
r[5]=r[4];
return vf3_matrix_family(0x0c0386dcu,s,ram);
P_0c0386e0: /* original 60d2, guest PC 0x0c0386e0 */
if(!s->budget--) { s->failed_pc=0x0c0386e0u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0386e2;
P_0c0386e2: /* original 7601, guest PC 0x0c0386e2 */
if(!s->budget--) { s->failed_pc=0x0c0386e2u; return 0; }
r[6]+=0x00000001u;
goto P_0c0386e4;
P_0c0386e4: /* original 0546, guest PC 0x0c0386e4 */
if(!s->budget--) { s->failed_pc=0x0c0386e4u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0386e6;
P_0c0386e6: /* original 7504, guest PC 0x0c0386e6 */
if(!s->budget--) { s->failed_pc=0x0c0386e6u; return 0; }
r[5]+=0x00000004u;
goto P_0c0386e8;
P_0c0386e8: /* original 62b2, guest PC 0x0c0386e8 */
if(!s->budget--) { s->failed_pc=0x0c0386e8u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0386ea;
P_0c0386ea: /* original 3623, guest PC 0x0c0386ea */
if(!s->budget--) { s->failed_pc=0x0c0386eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[2])!=0);
goto P_0c0386ec;
P_0c0386ec: /* original 8bf8, guest PC 0x0c0386ec */
if(!s->budget--) { s->failed_pc=0x0c0386ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0386e0; }
goto P_0c0386ee;
P_0c0386ee: /* original 7f04, guest PC 0x0c0386ee */
if(!s->budget--) { s->failed_pc=0x0c0386eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0386f0;
P_0c0386f0: /* original d156, guest PC 0x0c0386f0 */
if(!s->budget--) { s->failed_pc=0x0c0386f0u; return 0; }
r[1]=read(ram,0x0c03884cu,4);
goto P_0c0386f2;
P_0c0386f2: /* original 4f16, guest PC 0x0c0386f2 */
if(!s->budget--) { s->failed_pc=0x0c0386f2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0386f4;
P_0c0386f4: /* original 2142, guest PC 0x0c0386f4 */
if(!s->budget--) { s->failed_pc=0x0c0386f4u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0386f6;
P_0c0386f6: /* original 4f26, guest PC 0x0c0386f6 */
if(!s->budget--) { s->failed_pc=0x0c0386f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0386f8;
P_0c0386f8: /* original 6bf6, guest PC 0x0c0386f8 */
if(!s->budget--) { s->failed_pc=0x0c0386f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0386fa;
P_0c0386fa: /* original 6df6, guest PC 0x0c0386fa */
if(!s->budget--) { s->failed_pc=0x0c0386fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0386fc;
P_0c0386fc: /* original 000b, guest PC 0x0c0386fc */
if(!s->budget--) { s->failed_pc=0x0c0386fcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0386fe: /* original 6ef6, guest PC 0x0c0386fe */
if(!s->budget--) { s->failed_pc=0x0c0386feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c038700;
P_0c038700: /* original 4f22, guest PC 0x0c038700 */
if(!s->budget--) { s->failed_pc=0x0c038700u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038702;
P_0c038702: /* original b21d, guest PC 0x0c038702 */
if(!s->budget--) { s->failed_pc=0x0c038702u; return 0; }
target=0x0c038b40u; r[16]=0x0c038706u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038706u) { target=s->pc; goto dispatch; }
goto P_0c038706;
P_0c038704: /* original 0009, guest PC 0x0c038704 */
if(!s->budget--) { s->failed_pc=0x0c038704u; return 0; }
goto P_0c038706;
P_0c038706: /* original d050, guest PC 0x0c038706 */
if(!s->budget--) { s->failed_pc=0x0c038706u; return 0; }
r[0]=read(ram,0x0c038848u,4);
goto P_0c038708;
P_0c038708: /* original 6202, guest PC 0x0c038708 */
if(!s->budget--) { s->failed_pc=0x0c038708u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c03870a;
P_0c03870a: /* original 2228, guest PC 0x0c03870a */
if(!s->budget--) { s->failed_pc=0x0c03870au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03870c;
P_0c03870c: /* original 891f, guest PC 0x0c03870c */
if(!s->budget--) { s->failed_pc=0x0c03870cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03874e; }
goto P_0c03870e;
P_0c03870e: /* original d64a, guest PC 0x0c03870e */
if(!s->budget--) { s->failed_pc=0x0c03870eu; return 0; }
r[6]=read(ram,0x0c038838u,4);
goto P_0c038710;
P_0c038710: /* original e1ff, guest PC 0x0c038710 */
if(!s->budget--) { s->failed_pc=0x0c038710u; return 0; }
r[1]=0xffffffffu;
goto P_0c038712;
P_0c038712: /* original e400, guest PC 0x0c038712 */
if(!s->budget--) { s->failed_pc=0x0c038712u; return 0; }
r[4]=0x00000000u;
goto P_0c038714;
P_0c038714: /* original 6713, guest PC 0x0c038714 */
if(!s->budget--) { s->failed_pc=0x0c038714u; return 0; }
r[7]=r[1];
goto P_0c038716;
P_0c038716: /* original a00b, guest PC 0x0c038716 */
if(!s->budget--) { s->failed_pc=0x0c038716u; return 0; }
r[5]=0xfffffff8u;
goto P_0c038730;
P_0c038718: /* original e5f8, guest PC 0x0c038718 */
if(!s->budget--) { s->failed_pc=0x0c038718u; return 0; }
r[5]=0xfffffff8u;
return vf3_matrix_family(0x0c03871au,s,ram);
P_0c038720: /* original 6262, guest PC 0x0c038720 */
if(!s->budget--) { s->failed_pc=0x0c038720u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c038722;
P_0c038722: /* original 7701, guest PC 0x0c038722 */
if(!s->budget--) { s->failed_pc=0x0c038722u; return 0; }
r[7]+=0x00000001u;
goto P_0c038724;
P_0c038724: /* original 325c, guest PC 0x0c038724 */
if(!s->budget--) { s->failed_pc=0x0c038724u; return 0; }
r[2]+=r[5];
goto P_0c038726;
P_0c038726: /* original 2242, guest PC 0x0c038726 */
if(!s->budget--) { s->failed_pc=0x0c038726u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c038728;
P_0c038728: /* original 6362, guest PC 0x0c038728 */
if(!s->budget--) { s->failed_pc=0x0c038728u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c03872a;
P_0c03872a: /* original 335c, guest PC 0x0c03872a */
if(!s->budget--) { s->failed_pc=0x0c03872au; return 0; }
r[3]+=r[5];
goto P_0c03872c;
P_0c03872c: /* original 7508, guest PC 0x0c03872c */
if(!s->budget--) { s->failed_pc=0x0c03872cu; return 0; }
r[5]+=0x00000008u;
goto P_0c03872e;
P_0c03872e: /* original 1311, guest PC 0x0c03872e */
if(!s->budget--) { s->failed_pc=0x0c03872eu; return 0; }
write(ram,r[3]+4,r[1],4);
goto P_0c038730;
P_0c038730: /* original 6202, guest PC 0x0c038730 */
if(!s->budget--) { s->failed_pc=0x0c038730u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c038732;
P_0c038732: /* original 3723, guest PC 0x0c038732 */
if(!s->budget--) { s->failed_pc=0x0c038732u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[2])!=0);
goto P_0c038734;
P_0c038734: /* original 8bf4, guest PC 0x0c038734 */
if(!s->budget--) { s->failed_pc=0x0c038734u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038720; }
goto P_0c038736;
P_0c038736: /* original d742, guest PC 0x0c038736 */
if(!s->budget--) { s->failed_pc=0x0c038736u; return 0; }
r[7]=read(ram,0x0c038840u,4);
goto P_0c038738;
P_0c038738: /* original 6643, guest PC 0x0c038738 */
if(!s->budget--) { s->failed_pc=0x0c038738u; return 0; }
r[6]=r[4];
goto P_0c03873a;
P_0c03873a: /* original d140, guest PC 0x0c03873a */
if(!s->budget--) { s->failed_pc=0x0c03873au; return 0; }
r[1]=read(ram,0x0c03883cu,4);
goto P_0c03873c;
P_0c03873c: /* original a004, guest PC 0x0c03873c */
if(!s->budget--) { s->failed_pc=0x0c03873cu; return 0; }
r[5]=r[4];
goto P_0c038748;
P_0c03873e: /* original 6543, guest PC 0x0c03873e */
if(!s->budget--) { s->failed_pc=0x0c03873eu; return 0; }
r[5]=r[4];
goto P_0c038740;
P_0c038740: /* original 6012, guest PC 0x0c038740 */
if(!s->budget--) { s->failed_pc=0x0c038740u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c038742;
P_0c038742: /* original 7601, guest PC 0x0c038742 */
if(!s->budget--) { s->failed_pc=0x0c038742u; return 0; }
r[6]+=0x00000001u;
goto P_0c038744;
P_0c038744: /* original 0546, guest PC 0x0c038744 */
if(!s->budget--) { s->failed_pc=0x0c038744u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c038746;
P_0c038746: /* original 7504, guest PC 0x0c038746 */
if(!s->budget--) { s->failed_pc=0x0c038746u; return 0; }
r[5]+=0x00000004u;
goto P_0c038748;
P_0c038748: /* original 6372, guest PC 0x0c038748 */
if(!s->budget--) { s->failed_pc=0x0c038748u; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c03874a;
P_0c03874a: /* original 3633, guest PC 0x0c03874a */
if(!s->budget--) { s->failed_pc=0x0c03874au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c03874c;
P_0c03874c: /* original 8bf8, guest PC 0x0c03874c */
if(!s->budget--) { s->failed_pc=0x0c03874cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038740; }
goto P_0c03874e;
P_0c03874e: /* original 4f26, guest PC 0x0c03874e */
if(!s->budget--) { s->failed_pc=0x0c03874eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038750;
P_0c038750: /* original 000b, guest PC 0x0c038750 */
if(!s->budget--) { s->failed_pc=0x0c038750u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c038752: /* original 0009, guest PC 0x0c038752 */
if(!s->budget--) { s->failed_pc=0x0c038752u; return 0; }
return vf3_matrix_family(0x0c038754u,s,ram);
P_0c038a80: /* original 2fe6, guest PC 0x0c038a80 */
if(!s->budget--) { s->failed_pc=0x0c038a80u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c038a82;
P_0c038a82: /* original 6e43, guest PC 0x0c038a82 */
if(!s->budget--) { s->failed_pc=0x0c038a82u; return 0; }
r[14]=r[4];
goto P_0c038a84;
P_0c038a84: /* original 2fd6, guest PC 0x0c038a84 */
if(!s->budget--) { s->failed_pc=0x0c038a84u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c038a86;
P_0c038a86: /* original 6d43, guest PC 0x0c038a86 */
if(!s->budget--) { s->failed_pc=0x0c038a86u; return 0; }
r[13]=r[4];
goto P_0c038a88;
P_0c038a88: /* original 2f86, guest PC 0x0c038a88 */
if(!s->budget--) { s->failed_pc=0x0c038a88u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c038a8a;
P_0c038a8a: /* original 4f22, guest PC 0x0c038a8a */
if(!s->budget--) { s->failed_pc=0x0c038a8au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038a8c;
P_0c038a8c: /* original 7ffc, guest PC 0x0c038a8c */
if(!s->budget--) { s->failed_pc=0x0c038a8cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c038a8e;
P_0c038a8e: /* original bf7f, guest PC 0x0c038a8e */
if(!s->budget--) { s->failed_pc=0x0c038a8eu; return 0; }
target=0x0c038990u; r[16]=0x0c038a92u;
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038a92u) { target=s->pc; goto dispatch; }
goto P_0c038a92;
P_0c038a90: /* original 54e3, guest PC 0x0c038a90 */
if(!s->budget--) { s->failed_pc=0x0c038a90u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c038a92;
P_0c038a92: /* original 4008, guest PC 0x0c038a92 */
if(!s->budget--) { s->failed_pc=0x0c038a92u; return 0; }
r[0]<<=2;
goto P_0c038a94;
P_0c038a94: /* original 4000, guest PC 0x0c038a94 */
if(!s->budget--) { s->failed_pc=0x0c038a94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c038a96;
P_0c038a96: /* original e3f8, guest PC 0x0c038a96 */
if(!s->budget--) { s->failed_pc=0x0c038a96u; return 0; }
r[3]=0xfffffff8u;
goto P_0c038a98;
P_0c038a98: /* original 2f02, guest PC 0x0c038a98 */
if(!s->budget--) { s->failed_pc=0x0c038a98u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c038a9a;
P_0c038a9a: /* original 2039, guest PC 0x0c038a9a */
if(!s->budget--) { s->failed_pc=0x0c038a9au; return 0; }
r[0]&=r[3];
goto P_0c038a9c;
P_0c038a9c: /* original 6803, guest PC 0x0c038a9c */
if(!s->budget--) { s->failed_pc=0x0c038a9cu; return 0; }
r[8]=r[0];
goto P_0c038a9e;
P_0c038a9e: /* original bf77, guest PC 0x0c038a9e */
if(!s->budget--) { s->failed_pc=0x0c038a9eu; return 0; }
target=0x0c038990u; r[16]=0x0c038aa2u;
r[4]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038aa2u) { target=s->pc; goto dispatch; }
goto P_0c038aa2;
P_0c038aa0: /* original 54e4, guest PC 0x0c038aa0 */
if(!s->budget--) { s->failed_pc=0x0c038aa0u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c038aa2;
P_0c038aa2: /* original 6483, guest PC 0x0c038aa2 */
if(!s->budget--) { s->failed_pc=0x0c038aa2u; return 0; }
r[4]=r[8];
goto P_0c038aa4;
P_0c038aa4: /* original 240b, guest PC 0x0c038aa4 */
if(!s->budget--) { s->failed_pc=0x0c038aa4u; return 0; }
r[4]|=r[0];
goto P_0c038aa6;
P_0c038aa6: /* original 1d4c, guest PC 0x0c038aa6 */
if(!s->budget--) { s->failed_pc=0x0c038aa6u; return 0; }
write(ram,r[13]+48,r[4],4);
goto P_0c038aa8;
P_0c038aa8: /* original e001, guest PC 0x0c038aa8 */
if(!s->budget--) { s->failed_pc=0x0c038aa8u; return 0; }
r[0]=0x00000001u;
goto P_0c038aaa;
P_0c038aaa: /* original 54e6, guest PC 0x0c038aaa */
if(!s->budget--) { s->failed_pc=0x0c038aaau; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c038aac;
P_0c038aac: /* original e308, guest PC 0x0c038aac */
if(!s->budget--) { s->failed_pc=0x0c038aacu; return 0; }
r[3]=0x00000008u;
goto P_0c038aae;
P_0c038aae: /* original e21b, guest PC 0x0c038aae */
if(!s->budget--) { s->failed_pc=0x0c038aaeu; return 0; }
r[2]=0x0000001bu;
goto P_0c038ab0;
P_0c038ab0: /* original 51e2, guest PC 0x0c038ab0 */
if(!s->budget--) { s->failed_pc=0x0c038ab0u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c038ab2;
P_0c038ab2: /* original 2049, guest PC 0x0c038ab2 */
if(!s->budget--) { s->failed_pc=0x0c038ab2u; return 0; }
r[0]&=r[4];
goto P_0c038ab4;
P_0c038ab4: /* original 2349, guest PC 0x0c038ab4 */
if(!s->budget--) { s->failed_pc=0x0c038ab4u; return 0; }
r[3]&=r[4];
goto P_0c038ab6;
P_0c038ab6: /* original c901, guest PC 0x0c038ab6 */
if(!s->budget--) { s->failed_pc=0x0c038ab6u; return 0; }
r[0]&=1u;
goto P_0c038ab8;
P_0c038ab8: /* original 432d, guest PC 0x0c038ab8 */
if(!s->budget--) { s->failed_pc=0x0c038ab8u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c038aba;
P_0c038aba: /* original 4005, guest PC 0x0c038aba */
if(!s->budget--) { s->failed_pc=0x0c038abau; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c038abc;
P_0c038abc: /* original 203b, guest PC 0x0c038abc */
if(!s->budget--) { s->failed_pc=0x0c038abcu; return 0; }
r[0]|=r[3];
goto P_0c038abe;
P_0c038abe: /* original d313, guest PC 0x0c038abe */
if(!s->budget--) { s->failed_pc=0x0c038abeu; return 0; }
r[3]=read(ram,0x0c038b0cu,4);
goto P_0c038ac0;
P_0c038ac0: /* original 2139, guest PC 0x0c038ac0 */
if(!s->budget--) { s->failed_pc=0x0c038ac0u; return 0; }
r[1]&=r[3];
goto P_0c038ac2;
P_0c038ac2: /* original 201b, guest PC 0x0c038ac2 */
if(!s->budget--) { s->failed_pc=0x0c038ac2u; return 0; }
r[0]|=r[1];
goto P_0c038ac4;
P_0c038ac4: /* original 6103, guest PC 0x0c038ac4 */
if(!s->budget--) { s->failed_pc=0x0c038ac4u; return 0; }
r[1]=r[0];
goto P_0c038ac6;
P_0c038ac6: /* original 6047, guest PC 0x0c038ac6 */
if(!s->budget--) { s->failed_pc=0x0c038ac6u; return 0; }
r[0]=~r[4];
goto P_0c038ac8;
P_0c038ac8: /* original c904, guest PC 0x0c038ac8 */
if(!s->budget--) { s->failed_pc=0x0c038ac8u; return 0; }
r[0]&=4u;
goto P_0c038aca;
P_0c038aca: /* original 4028, guest PC 0x0c038aca */
if(!s->budget--) { s->failed_pc=0x0c038acau; return 0; }
r[0]<<=16;
goto P_0c038acc;
P_0c038acc: /* original 4018, guest PC 0x0c038acc */
if(!s->budget--) { s->failed_pc=0x0c038accu; return 0; }
r[0]<<=8;
goto P_0c038ace;
P_0c038ace: /* original 210b, guest PC 0x0c038ace */
if(!s->budget--) { s->failed_pc=0x0c038aceu; return 0; }
r[1]|=r[0];
goto P_0c038ad0;
P_0c038ad0: /* original e010, guest PC 0x0c038ad0 */
if(!s->budget--) { s->failed_pc=0x0c038ad0u; return 0; }
r[0]=0x00000010u;
goto P_0c038ad2;
P_0c038ad2: /* original e315, guest PC 0x0c038ad2 */
if(!s->budget--) { s->failed_pc=0x0c038ad2u; return 0; }
r[3]=0x00000015u;
goto P_0c038ad4;
P_0c038ad4: /* original 2049, guest PC 0x0c038ad4 */
if(!s->budget--) { s->failed_pc=0x0c038ad4u; return 0; }
r[0]&=r[4];
goto P_0c038ad6;
P_0c038ad6: /* original 403d, guest PC 0x0c038ad6 */
if(!s->budget--) { s->failed_pc=0x0c038ad6u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c038ad8;
P_0c038ad8: /* original 210b, guest PC 0x0c038ad8 */
if(!s->budget--) { s->failed_pc=0x0c038ad8u; return 0; }
r[1]|=r[0];
goto P_0c038ada;
P_0c038ada: /* original 50e7, guest PC 0x0c038ada */
if(!s->budget--) { s->failed_pc=0x0c038adau; return 0; }
r[0]=read(ram,r[14]+28,4);
goto P_0c038adc;
P_0c038adc: /* original 6413, guest PC 0x0c038adc */
if(!s->budget--) { s->failed_pc=0x0c038adcu; return 0; }
r[4]=r[1];
goto P_0c038ade;
P_0c038ade: /* original 4009, guest PC 0x0c038ade */
if(!s->budget--) { s->failed_pc=0x0c038adeu; return 0; }
r[0]>>=2;
goto P_0c038ae0;
P_0c038ae0: /* original 4001, guest PC 0x0c038ae0 */
if(!s->budget--) { s->failed_pc=0x0c038ae0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c038ae2;
P_0c038ae2: /* original 7f04, guest PC 0x0c038ae2 */
if(!s->budget--) { s->failed_pc=0x0c038ae2u; return 0; }
r[15]+=0x00000004u;
goto P_0c038ae4;
P_0c038ae4: /* original 4f26, guest PC 0x0c038ae4 */
if(!s->budget--) { s->failed_pc=0x0c038ae4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038ae6;
P_0c038ae6: /* original 240b, guest PC 0x0c038ae6 */
if(!s->budget--) { s->failed_pc=0x0c038ae6u; return 0; }
r[4]|=r[0];
goto P_0c038ae8;
P_0c038ae8: /* original 1d4d, guest PC 0x0c038ae8 */
if(!s->budget--) { s->failed_pc=0x0c038ae8u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c038aea;
P_0c038aea: /* original 68f6, guest PC 0x0c038aea */
if(!s->budget--) { s->failed_pc=0x0c038aeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c038aec;
P_0c038aec: /* original 6df6, guest PC 0x0c038aec */
if(!s->budget--) { s->failed_pc=0x0c038aecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c038aee;
P_0c038aee: /* original 000b, guest PC 0x0c038aee */
if(!s->budget--) { s->failed_pc=0x0c038aeeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c038af0: /* original 6ef6, guest PC 0x0c038af0 */
if(!s->budget--) { s->failed_pc=0x0c038af0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c038af2u,s,ram);
P_0c038bc4: /* original 4f22, guest PC 0x0c038bc4 */
if(!s->budget--) { s->failed_pc=0x0c038bc4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038bc6;
P_0c038bc6: /* original 85e1, guest PC 0x0c038bc6 */
if(!s->budget--) { s->failed_pc=0x0c038bc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c038bc8;
P_0c038bc8: /* original d411, guest PC 0x0c038bc8 */
if(!s->budget--) { s->failed_pc=0x0c038bc8u; return 0; }
r[4]=read(ram,0x0c038c10u,4);
goto P_0c038bca;
P_0c038bca: /* original d317, guest PC 0x0c038bca */
if(!s->budget--) { s->failed_pc=0x0c038bcau; return 0; }
r[3]=read(ram,0x0c038c28u,4);
goto P_0c038bcc;
P_0c038bcc: /* original 6603, guest PC 0x0c038bcc */
if(!s->budget--) { s->failed_pc=0x0c038bccu; return 0; }
r[6]=r[0];
goto P_0c038bce;
P_0c038bce: /* original 57e1, guest PC 0x0c038bce */
if(!s->budget--) { s->failed_pc=0x0c038bceu; return 0; }
r[7]=read(ram,r[14]+4,4);
goto P_0c038bd0;
P_0c038bd0: /* original 430b, guest PC 0x0c038bd0 */
if(!s->budget--) { s->failed_pc=0x0c038bd0u; return 0; }
target=r[3];
r[16]=0x0c038bd4u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038bd4u) { target=s->pc; goto dispatch; }
goto P_0c038bd4;
P_0c038bd2: /* original 65e1, guest PC 0x0c038bd2 */
if(!s->budget--) { s->failed_pc=0x0c038bd2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
goto P_0c038bd4;
P_0c038bd4: /* original d40e, guest PC 0x0c038bd4 */
if(!s->budget--) { s->failed_pc=0x0c038bd4u; return 0; }
r[4]=read(ram,0x0c038c10u,4);
goto P_0c038bd6;
P_0c038bd6: /* original e700, guest PC 0x0c038bd6 */
if(!s->budget--) { s->failed_pc=0x0c038bd6u; return 0; }
r[7]=0x00000000u;
goto P_0c038bd8;
P_0c038bd8: /* original d214, guest PC 0x0c038bd8 */
if(!s->budget--) { s->failed_pc=0x0c038bd8u; return 0; }
r[2]=read(ram,0x0c038c2cu,4);
goto P_0c038bda;
P_0c038bda: /* original 6673, guest PC 0x0c038bda */
if(!s->budget--) { s->failed_pc=0x0c038bdau; return 0; }
r[6]=r[7];
goto P_0c038bdc;
P_0c038bdc: /* original 420b, guest PC 0x0c038bdc */
if(!s->budget--) { s->failed_pc=0x0c038bdcu; return 0; }
target=r[2];
r[16]=0x0c038be0u;
r[5]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038be0u) { target=s->pc; goto dispatch; }
goto P_0c038be0;
P_0c038bde: /* original 55e2, guest PC 0x0c038bde */
if(!s->budget--) { s->failed_pc=0x0c038bdeu; return 0; }
r[5]=read(ram,r[14]+8,4);
goto P_0c038be0;
P_0c038be0: /* original 4f26, guest PC 0x0c038be0 */
if(!s->budget--) { s->failed_pc=0x0c038be0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038be2;
P_0c038be2: /* original d40b, guest PC 0x0c038be2 */
if(!s->budget--) { s->failed_pc=0x0c038be2u; return 0; }
r[4]=read(ram,0x0c038c10u,4);
goto P_0c038be4;
P_0c038be4: /* original af4c, guest PC 0x0c038be4 */
if(!s->budget--) { s->failed_pc=0x0c038be4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c038a80;
P_0c038be6: /* original 6ef6, guest PC 0x0c038be6 */
if(!s->budget--) { s->failed_pc=0x0c038be6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c038be8u,s,ram);
P_0c038eae: /* original 4f22, guest PC 0x0c038eae */
if(!s->budget--) { s->failed_pc=0x0c038eaeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038eb0;
P_0c038eb0: /* original e206, guest PC 0x0c038eb0 */
if(!s->budget--) { s->failed_pc=0x0c038eb0u; return 0; }
r[2]=0x00000006u;
goto P_0c038eb2;
P_0c038eb2: /* original 1e41, guest PC 0x0c038eb2 */
if(!s->budget--) { s->failed_pc=0x0c038eb2u; return 0; }
write(ram,r[14]+4,r[4],4);
goto P_0c038eb4;
P_0c038eb4: /* original e601, guest PC 0x0c038eb4 */
if(!s->budget--) { s->failed_pc=0x0c038eb4u; return 0; }
r[6]=0x00000001u;
goto P_0c038eb6;
P_0c038eb6: /* original 1e42, guest PC 0x0c038eb6 */
if(!s->budget--) { s->failed_pc=0x0c038eb6u; return 0; }
write(ram,r[14]+8,r[4],4);
goto P_0c038eb8;
P_0c038eb8: /* original e504, guest PC 0x0c038eb8 */
if(!s->budget--) { s->failed_pc=0x0c038eb8u; return 0; }
r[5]=0x00000004u;
goto P_0c038eba;
P_0c038eba: /* original 1e63, guest PC 0x0c038eba */
if(!s->budget--) { s->failed_pc=0x0c038ebau; return 0; }
write(ram,r[14]+12,r[6],4);
goto P_0c038ebc;
P_0c038ebc: /* original 0e46, guest PC 0x0c038ebc */
if(!s->budget--) { s->failed_pc=0x0c038ebcu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ebe;
P_0c038ebe: /* original 1e44, guest PC 0x0c038ebe */
if(!s->budget--) { s->failed_pc=0x0c038ebeu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c038ec0;
P_0c038ec0: /* original 1e55, guest PC 0x0c038ec0 */
if(!s->budget--) { s->failed_pc=0x0c038ec0u; return 0; }
write(ram,r[14]+20,r[5],4);
goto P_0c038ec2;
P_0c038ec2: /* original 1e46, guest PC 0x0c038ec2 */
if(!s->budget--) { s->failed_pc=0x0c038ec2u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c038ec4;
P_0c038ec4: /* original 1e47, guest PC 0x0c038ec4 */
if(!s->budget--) { s->failed_pc=0x0c038ec4u; return 0; }
write(ram,r[14]+28,r[4],4);
goto P_0c038ec6;
P_0c038ec6: /* original 1e68, guest PC 0x0c038ec6 */
if(!s->budget--) { s->failed_pc=0x0c038ec6u; return 0; }
write(ram,r[14]+32,r[6],4);
goto P_0c038ec8;
P_0c038ec8: /* original 1e49, guest PC 0x0c038ec8 */
if(!s->budget--) { s->failed_pc=0x0c038ec8u; return 0; }
write(ram,r[14]+36,r[4],4);
goto P_0c038eca;
P_0c038eca: /* original 1e4a, guest PC 0x0c038eca */
if(!s->budget--) { s->failed_pc=0x0c038ecau; return 0; }
write(ram,r[14]+40,r[4],4);
goto P_0c038ecc;
P_0c038ecc: /* original 1e3b, guest PC 0x0c038ecc */
if(!s->budget--) { s->failed_pc=0x0c038eccu; return 0; }
write(ram,r[14]+44,r[3],4);
goto P_0c038ece;
P_0c038ece: /* original e302, guest PC 0x0c038ece */
if(!s->budget--) { s->failed_pc=0x0c038eceu; return 0; }
r[3]=0x00000002u;
goto P_0c038ed0;
P_0c038ed0: /* original 1e2c, guest PC 0x0c038ed0 */
if(!s->budget--) { s->failed_pc=0x0c038ed0u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c038ed2;
P_0c038ed2: /* original 1e4d, guest PC 0x0c038ed2 */
if(!s->budget--) { s->failed_pc=0x0c038ed2u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c038ed4;
P_0c038ed4: /* original 1e4e, guest PC 0x0c038ed4 */
if(!s->budget--) { s->failed_pc=0x0c038ed4u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c038ed6;
P_0c038ed6: /* original 1e3f, guest PC 0x0c038ed6 */
if(!s->budget--) { s->failed_pc=0x0c038ed6u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c038ed8;
P_0c038ed8: /* original 0e46, guest PC 0x0c038ed8 */
if(!s->budget--) { s->failed_pc=0x0c038ed8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038eda;
P_0c038eda: /* original e044, guest PC 0x0c038eda */
if(!s->budget--) { s->failed_pc=0x0c038edau; return 0; }
r[0]=0x00000044u;
goto P_0c038edc;
P_0c038edc: /* original 0e46, guest PC 0x0c038edc */
if(!s->budget--) { s->failed_pc=0x0c038edcu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ede;
P_0c038ede: /* original e048, guest PC 0x0c038ede */
if(!s->budget--) { s->failed_pc=0x0c038edeu; return 0; }
r[0]=0x00000048u;
goto P_0c038ee0;
P_0c038ee0: /* original 0e46, guest PC 0x0c038ee0 */
if(!s->budget--) { s->failed_pc=0x0c038ee0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ee2;
P_0c038ee2: /* original e04c, guest PC 0x0c038ee2 */
if(!s->budget--) { s->failed_pc=0x0c038ee2u; return 0; }
r[0]=0x0000004cu;
goto P_0c038ee4;
P_0c038ee4: /* original 0e46, guest PC 0x0c038ee4 */
if(!s->budget--) { s->failed_pc=0x0c038ee4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ee6;
P_0c038ee6: /* original e050, guest PC 0x0c038ee6 */
if(!s->budget--) { s->failed_pc=0x0c038ee6u; return 0; }
r[0]=0x00000050u;
goto P_0c038ee8;
P_0c038ee8: /* original 0e46, guest PC 0x0c038ee8 */
if(!s->budget--) { s->failed_pc=0x0c038ee8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038eea;
P_0c038eea: /* original e054, guest PC 0x0c038eea */
if(!s->budget--) { s->failed_pc=0x0c038eeau; return 0; }
r[0]=0x00000054u;
goto P_0c038eec;
P_0c038eec: /* original 0e46, guest PC 0x0c038eec */
if(!s->budget--) { s->failed_pc=0x0c038eecu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038eee;
P_0c038eee: /* original e058, guest PC 0x0c038eee */
if(!s->budget--) { s->failed_pc=0x0c038eeeu; return 0; }
r[0]=0x00000058u;
goto P_0c038ef0;
P_0c038ef0: /* original 0e46, guest PC 0x0c038ef0 */
if(!s->budget--) { s->failed_pc=0x0c038ef0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038ef2;
P_0c038ef2: /* original e05c, guest PC 0x0c038ef2 */
if(!s->budget--) { s->failed_pc=0x0c038ef2u; return 0; }
r[0]=0x0000005cu;
goto P_0c038ef4;
P_0c038ef4: /* original 0e56, guest PC 0x0c038ef4 */
if(!s->budget--) { s->failed_pc=0x0c038ef4u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c038ef6;
P_0c038ef6: /* original e060, guest PC 0x0c038ef6 */
if(!s->budget--) { s->failed_pc=0x0c038ef6u; return 0; }
r[0]=0x00000060u;
goto P_0c038ef8;
P_0c038ef8: /* original e303, guest PC 0x0c038ef8 */
if(!s->budget--) { s->failed_pc=0x0c038ef8u; return 0; }
r[3]=0x00000003u;
goto P_0c038efa;
P_0c038efa: /* original 0e36, guest PC 0x0c038efa */
if(!s->budget--) { s->failed_pc=0x0c038efau; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c038efc;
P_0c038efc: /* original e06c, guest PC 0x0c038efc */
if(!s->budget--) { s->failed_pc=0x0c038efcu; return 0; }
r[0]=0x0000006cu;
goto P_0c038efe;
P_0c038efe: /* original 0e46, guest PC 0x0c038efe */
if(!s->budget--) { s->failed_pc=0x0c038efeu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f00;
P_0c038f00: /* original e064, guest PC 0x0c038f00 */
if(!s->budget--) { s->failed_pc=0x0c038f00u; return 0; }
r[0]=0x00000064u;
goto P_0c038f02;
P_0c038f02: /* original 0e46, guest PC 0x0c038f02 */
if(!s->budget--) { s->failed_pc=0x0c038f02u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f04;
P_0c038f04: /* original e068, guest PC 0x0c038f04 */
if(!s->budget--) { s->failed_pc=0x0c038f04u; return 0; }
r[0]=0x00000068u;
goto P_0c038f06;
P_0c038f06: /* original 0e46, guest PC 0x0c038f06 */
if(!s->budget--) { s->failed_pc=0x0c038f06u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f08;
P_0c038f08: /* original e070, guest PC 0x0c038f08 */
if(!s->budget--) { s->failed_pc=0x0c038f08u; return 0; }
r[0]=0x00000070u;
goto P_0c038f0a;
P_0c038f0a: /* original f49d, guest PC 0x0c038f0a */
if(!s->budget--) { s->failed_pc=0x0c038f0au; return 0; }
fr[4]=0x3f800000u;
goto P_0c038f0c;
P_0c038f0c: /* original fe47, guest PC 0x0c038f0c */
if(!s->budget--) { s->failed_pc=0x0c038f0cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f0e;
P_0c038f0e: /* original e074, guest PC 0x0c038f0e */
if(!s->budget--) { s->failed_pc=0x0c038f0eu; return 0; }
r[0]=0x00000074u;
goto P_0c038f10;
P_0c038f10: /* original fe47, guest PC 0x0c038f10 */
if(!s->budget--) { s->failed_pc=0x0c038f10u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f12;
P_0c038f12: /* original e078, guest PC 0x0c038f12 */
if(!s->budget--) { s->failed_pc=0x0c038f12u; return 0; }
r[0]=0x00000078u;
goto P_0c038f14;
P_0c038f14: /* original fe47, guest PC 0x0c038f14 */
if(!s->budget--) { s->failed_pc=0x0c038f14u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f16;
P_0c038f16: /* original e07c, guest PC 0x0c038f16 */
if(!s->budget--) { s->failed_pc=0x0c038f16u; return 0; }
r[0]=0x0000007cu;
goto P_0c038f18;
P_0c038f18: /* original fe47, guest PC 0x0c038f18 */
if(!s->budget--) { s->failed_pc=0x0c038f18u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f1a;
P_0c038f1a: /* original 7004, guest PC 0x0c038f1a */
if(!s->budget--) { s->failed_pc=0x0c038f1au; return 0; }
r[0]+=0x00000004u;
goto P_0c038f1c;
P_0c038f1c: /* original fe47, guest PC 0x0c038f1c */
if(!s->budget--) { s->failed_pc=0x0c038f1cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f1e;
P_0c038f1e: /* original 7004, guest PC 0x0c038f1e */
if(!s->budget--) { s->failed_pc=0x0c038f1eu; return 0; }
r[0]+=0x00000004u;
goto P_0c038f20;
P_0c038f20: /* original fe47, guest PC 0x0c038f20 */
if(!s->budget--) { s->failed_pc=0x0c038f20u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f22;
P_0c038f22: /* original 7004, guest PC 0x0c038f22 */
if(!s->budget--) { s->failed_pc=0x0c038f22u; return 0; }
r[0]+=0x00000004u;
goto P_0c038f24;
P_0c038f24: /* original fe47, guest PC 0x0c038f24 */
if(!s->budget--) { s->failed_pc=0x0c038f24u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f26;
P_0c038f26: /* original 7004, guest PC 0x0c038f26 */
if(!s->budget--) { s->failed_pc=0x0c038f26u; return 0; }
r[0]+=0x00000004u;
goto P_0c038f28;
P_0c038f28: /* original fe47, guest PC 0x0c038f28 */
if(!s->budget--) { s->failed_pc=0x0c038f28u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038f2a;
P_0c038f2a: /* original d378, guest PC 0x0c038f2a */
if(!s->budget--) { s->failed_pc=0x0c038f2au; return 0; }
r[3]=read(ram,0x0c03910cu,4);
goto P_0c038f2c;
P_0c038f2c: /* original 430b, guest PC 0x0c038f2c */
if(!s->budget--) { s->failed_pc=0x0c038f2cu; return 0; }
target=r[3];
r[16]=0x0c038f30u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038f30u) { target=s->pc; goto dispatch; }
goto P_0c038f30;
P_0c038f2e: /* original 64e3, guest PC 0x0c038f2e */
if(!s->budget--) { s->failed_pc=0x0c038f2eu; return 0; }
r[4]=r[14];
goto P_0c038f30;
P_0c038f30: /* original 4f26, guest PC 0x0c038f30 */
if(!s->budget--) { s->failed_pc=0x0c038f30u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038f32;
P_0c038f32: /* original d277, guest PC 0x0c038f32 */
if(!s->budget--) { s->failed_pc=0x0c038f32u; return 0; }
r[2]=read(ram,0x0c039110u,4);
goto P_0c038f34;
P_0c038f34: /* original 64e3, guest PC 0x0c038f34 */
if(!s->budget--) { s->failed_pc=0x0c038f34u; return 0; }
r[4]=r[14];
goto P_0c038f36;
P_0c038f36: /* original 422b, guest PC 0x0c038f36 */
if(!s->budget--) { s->failed_pc=0x0c038f36u; return 0; }
target=r[2];
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
P_0c038f38: /* original 6ef6, guest PC 0x0c038f38 */
if(!s->budget--) { s->failed_pc=0x0c038f38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c038f3au,s,ram);
P_0c038f4e: /* original 4f22, guest PC 0x0c038f4e */
if(!s->budget--) { s->failed_pc=0x0c038f4eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038f50;
P_0c038f50: /* original e20b, guest PC 0x0c038f50 */
if(!s->budget--) { s->failed_pc=0x0c038f50u; return 0; }
r[2]=0x0000000bu;
goto P_0c038f52;
P_0c038f52: /* original 1e41, guest PC 0x0c038f52 */
if(!s->budget--) { s->failed_pc=0x0c038f52u; return 0; }
write(ram,r[14]+4,r[4],4);
goto P_0c038f54;
P_0c038f54: /* original e501, guest PC 0x0c038f54 */
if(!s->budget--) { s->failed_pc=0x0c038f54u; return 0; }
r[5]=0x00000001u;
goto P_0c038f56;
P_0c038f56: /* original 1e42, guest PC 0x0c038f56 */
if(!s->budget--) { s->failed_pc=0x0c038f56u; return 0; }
write(ram,r[14]+8,r[4],4);
goto P_0c038f58;
P_0c038f58: /* original e604, guest PC 0x0c038f58 */
if(!s->budget--) { s->failed_pc=0x0c038f58u; return 0; }
r[6]=0x00000004u;
goto P_0c038f5a;
P_0c038f5a: /* original 1e43, guest PC 0x0c038f5a */
if(!s->budget--) { s->failed_pc=0x0c038f5au; return 0; }
write(ram,r[14]+12,r[4],4);
goto P_0c038f5c;
P_0c038f5c: /* original 0e46, guest PC 0x0c038f5c */
if(!s->budget--) { s->failed_pc=0x0c038f5cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f5e;
P_0c038f5e: /* original 1e44, guest PC 0x0c038f5e */
if(!s->budget--) { s->failed_pc=0x0c038f5eu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c038f60;
P_0c038f60: /* original 1e65, guest PC 0x0c038f60 */
if(!s->budget--) { s->failed_pc=0x0c038f60u; return 0; }
write(ram,r[14]+20,r[6],4);
goto P_0c038f62;
P_0c038f62: /* original 1e46, guest PC 0x0c038f62 */
if(!s->budget--) { s->failed_pc=0x0c038f62u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c038f64;
P_0c038f64: /* original 1e47, guest PC 0x0c038f64 */
if(!s->budget--) { s->failed_pc=0x0c038f64u; return 0; }
write(ram,r[14]+28,r[4],4);
goto P_0c038f66;
P_0c038f66: /* original 1e58, guest PC 0x0c038f66 */
if(!s->budget--) { s->failed_pc=0x0c038f66u; return 0; }
write(ram,r[14]+32,r[5],4);
goto P_0c038f68;
P_0c038f68: /* original 1e49, guest PC 0x0c038f68 */
if(!s->budget--) { s->failed_pc=0x0c038f68u; return 0; }
write(ram,r[14]+36,r[4],4);
goto P_0c038f6a;
P_0c038f6a: /* original 1e4a, guest PC 0x0c038f6a */
if(!s->budget--) { s->failed_pc=0x0c038f6au; return 0; }
write(ram,r[14]+40,r[4],4);
goto P_0c038f6c;
P_0c038f6c: /* original 1e3b, guest PC 0x0c038f6c */
if(!s->budget--) { s->failed_pc=0x0c038f6cu; return 0; }
write(ram,r[14]+44,r[3],4);
goto P_0c038f6e;
P_0c038f6e: /* original e302, guest PC 0x0c038f6e */
if(!s->budget--) { s->failed_pc=0x0c038f6eu; return 0; }
r[3]=0x00000002u;
goto P_0c038f70;
P_0c038f70: /* original 1e2c, guest PC 0x0c038f70 */
if(!s->budget--) { s->failed_pc=0x0c038f70u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c038f72;
P_0c038f72: /* original 1e4d, guest PC 0x0c038f72 */
if(!s->budget--) { s->failed_pc=0x0c038f72u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c038f74;
P_0c038f74: /* original 1e4e, guest PC 0x0c038f74 */
if(!s->budget--) { s->failed_pc=0x0c038f74u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c038f76;
P_0c038f76: /* original 1e3f, guest PC 0x0c038f76 */
if(!s->budget--) { s->failed_pc=0x0c038f76u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c038f78;
P_0c038f78: /* original 0e46, guest PC 0x0c038f78 */
if(!s->budget--) { s->failed_pc=0x0c038f78u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f7a;
P_0c038f7a: /* original e044, guest PC 0x0c038f7a */
if(!s->budget--) { s->failed_pc=0x0c038f7au; return 0; }
r[0]=0x00000044u;
goto P_0c038f7c;
P_0c038f7c: /* original 0e46, guest PC 0x0c038f7c */
if(!s->budget--) { s->failed_pc=0x0c038f7cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f7e;
P_0c038f7e: /* original e048, guest PC 0x0c038f7e */
if(!s->budget--) { s->failed_pc=0x0c038f7eu; return 0; }
r[0]=0x00000048u;
goto P_0c038f80;
P_0c038f80: /* original 0e56, guest PC 0x0c038f80 */
if(!s->budget--) { s->failed_pc=0x0c038f80u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c038f82;
P_0c038f82: /* original e04c, guest PC 0x0c038f82 */
if(!s->budget--) { s->failed_pc=0x0c038f82u; return 0; }
r[0]=0x0000004cu;
goto P_0c038f84;
P_0c038f84: /* original 0e46, guest PC 0x0c038f84 */
if(!s->budget--) { s->failed_pc=0x0c038f84u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f86;
P_0c038f86: /* original e050, guest PC 0x0c038f86 */
if(!s->budget--) { s->failed_pc=0x0c038f86u; return 0; }
r[0]=0x00000050u;
goto P_0c038f88;
P_0c038f88: /* original 0e46, guest PC 0x0c038f88 */
if(!s->budget--) { s->failed_pc=0x0c038f88u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f8a;
P_0c038f8a: /* original e054, guest PC 0x0c038f8a */
if(!s->budget--) { s->failed_pc=0x0c038f8au; return 0; }
r[0]=0x00000054u;
goto P_0c038f8c;
P_0c038f8c: /* original 0e46, guest PC 0x0c038f8c */
if(!s->budget--) { s->failed_pc=0x0c038f8cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f8e;
P_0c038f8e: /* original e058, guest PC 0x0c038f8e */
if(!s->budget--) { s->failed_pc=0x0c038f8eu; return 0; }
r[0]=0x00000058u;
goto P_0c038f90;
P_0c038f90: /* original 0e46, guest PC 0x0c038f90 */
if(!s->budget--) { s->failed_pc=0x0c038f90u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f92;
P_0c038f92: /* original e05c, guest PC 0x0c038f92 */
if(!s->budget--) { s->failed_pc=0x0c038f92u; return 0; }
r[0]=0x0000005cu;
goto P_0c038f94;
P_0c038f94: /* original 0e66, guest PC 0x0c038f94 */
if(!s->budget--) { s->failed_pc=0x0c038f94u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c038f96;
P_0c038f96: /* original e060, guest PC 0x0c038f96 */
if(!s->budget--) { s->failed_pc=0x0c038f96u; return 0; }
r[0]=0x00000060u;
goto P_0c038f98;
P_0c038f98: /* original 0e56, guest PC 0x0c038f98 */
if(!s->budget--) { s->failed_pc=0x0c038f98u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c038f9a;
P_0c038f9a: /* original e06c, guest PC 0x0c038f9a */
if(!s->budget--) { s->failed_pc=0x0c038f9au; return 0; }
r[0]=0x0000006cu;
goto P_0c038f9c;
P_0c038f9c: /* original 0e46, guest PC 0x0c038f9c */
if(!s->budget--) { s->failed_pc=0x0c038f9cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038f9e;
P_0c038f9e: /* original e064, guest PC 0x0c038f9e */
if(!s->budget--) { s->failed_pc=0x0c038f9eu; return 0; }
r[0]=0x00000064u;
goto P_0c038fa0;
P_0c038fa0: /* original 0e46, guest PC 0x0c038fa0 */
if(!s->budget--) { s->failed_pc=0x0c038fa0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038fa2;
P_0c038fa2: /* original e068, guest PC 0x0c038fa2 */
if(!s->budget--) { s->failed_pc=0x0c038fa2u; return 0; }
r[0]=0x00000068u;
goto P_0c038fa4;
P_0c038fa4: /* original 0e46, guest PC 0x0c038fa4 */
if(!s->budget--) { s->failed_pc=0x0c038fa4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038fa6;
P_0c038fa6: /* original e070, guest PC 0x0c038fa6 */
if(!s->budget--) { s->failed_pc=0x0c038fa6u; return 0; }
r[0]=0x00000070u;
goto P_0c038fa8;
P_0c038fa8: /* original f49d, guest PC 0x0c038fa8 */
if(!s->budget--) { s->failed_pc=0x0c038fa8u; return 0; }
fr[4]=0x3f800000u;
goto P_0c038faa;
P_0c038faa: /* original fe47, guest PC 0x0c038faa */
if(!s->budget--) { s->failed_pc=0x0c038faau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fac;
P_0c038fac: /* original e074, guest PC 0x0c038fac */
if(!s->budget--) { s->failed_pc=0x0c038facu; return 0; }
r[0]=0x00000074u;
goto P_0c038fae;
P_0c038fae: /* original fe47, guest PC 0x0c038fae */
if(!s->budget--) { s->failed_pc=0x0c038faeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fb0;
P_0c038fb0: /* original e078, guest PC 0x0c038fb0 */
if(!s->budget--) { s->failed_pc=0x0c038fb0u; return 0; }
r[0]=0x00000078u;
goto P_0c038fb2;
P_0c038fb2: /* original fe47, guest PC 0x0c038fb2 */
if(!s->budget--) { s->failed_pc=0x0c038fb2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fb4;
P_0c038fb4: /* original e07c, guest PC 0x0c038fb4 */
if(!s->budget--) { s->failed_pc=0x0c038fb4u; return 0; }
r[0]=0x0000007cu;
goto P_0c038fb6;
P_0c038fb6: /* original fe47, guest PC 0x0c038fb6 */
if(!s->budget--) { s->failed_pc=0x0c038fb6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fb8;
P_0c038fb8: /* original 7004, guest PC 0x0c038fb8 */
if(!s->budget--) { s->failed_pc=0x0c038fb8u; return 0; }
r[0]+=0x00000004u;
goto P_0c038fba;
P_0c038fba: /* original fe47, guest PC 0x0c038fba */
if(!s->budget--) { s->failed_pc=0x0c038fbau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fbc;
P_0c038fbc: /* original 7004, guest PC 0x0c038fbc */
if(!s->budget--) { s->failed_pc=0x0c038fbcu; return 0; }
r[0]+=0x00000004u;
goto P_0c038fbe;
P_0c038fbe: /* original fe47, guest PC 0x0c038fbe */
if(!s->budget--) { s->failed_pc=0x0c038fbeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fc0;
P_0c038fc0: /* original 7004, guest PC 0x0c038fc0 */
if(!s->budget--) { s->failed_pc=0x0c038fc0u; return 0; }
r[0]+=0x00000004u;
goto P_0c038fc2;
P_0c038fc2: /* original fe47, guest PC 0x0c038fc2 */
if(!s->budget--) { s->failed_pc=0x0c038fc2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fc4;
P_0c038fc4: /* original 7004, guest PC 0x0c038fc4 */
if(!s->budget--) { s->failed_pc=0x0c038fc4u; return 0; }
r[0]+=0x00000004u;
goto P_0c038fc6;
P_0c038fc6: /* original fe47, guest PC 0x0c038fc6 */
if(!s->budget--) { s->failed_pc=0x0c038fc6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038fc8;
P_0c038fc8: /* original d350, guest PC 0x0c038fc8 */
if(!s->budget--) { s->failed_pc=0x0c038fc8u; return 0; }
r[3]=read(ram,0x0c03910cu,4);
goto P_0c038fca;
P_0c038fca: /* original 430b, guest PC 0x0c038fca */
if(!s->budget--) { s->failed_pc=0x0c038fcau; return 0; }
target=r[3];
r[16]=0x0c038fceu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038fceu) { target=s->pc; goto dispatch; }
goto P_0c038fce;
P_0c038fcc: /* original 64e3, guest PC 0x0c038fcc */
if(!s->budget--) { s->failed_pc=0x0c038fccu; return 0; }
r[4]=r[14];
goto P_0c038fce;
P_0c038fce: /* original 4f26, guest PC 0x0c038fce */
if(!s->budget--) { s->failed_pc=0x0c038fceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038fd0;
P_0c038fd0: /* original d250, guest PC 0x0c038fd0 */
if(!s->budget--) { s->failed_pc=0x0c038fd0u; return 0; }
r[2]=read(ram,0x0c039114u,4);
goto P_0c038fd2;
P_0c038fd2: /* original 64e3, guest PC 0x0c038fd2 */
if(!s->budget--) { s->failed_pc=0x0c038fd2u; return 0; }
r[4]=r[14];
goto P_0c038fd4;
P_0c038fd4: /* original 422b, guest PC 0x0c038fd4 */
if(!s->budget--) { s->failed_pc=0x0c038fd4u; return 0; }
target=r[2];
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
P_0c038fd6: /* original 6ef6, guest PC 0x0c038fd6 */
if(!s->budget--) { s->failed_pc=0x0c038fd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c038fd8u,s,ram);
P_0c03b874: /* original 4f22, guest PC 0x0c03b874 */
if(!s->budget--) { s->failed_pc=0x0c03b874u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b876;
P_0c03b876: /* original 7ff4, guest PC 0x0c03b876 */
if(!s->budget--) { s->failed_pc=0x0c03b876u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c03b878;
P_0c03b878: /* original 2f42, guest PC 0x0c03b878 */
if(!s->budget--) { s->failed_pc=0x0c03b878u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03b87a;
P_0c03b87a: /* original 1f51, guest PC 0x0c03b87a */
if(!s->budget--) { s->failed_pc=0x0c03b87au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c03b87c;
P_0c03b87c: /* original de11, guest PC 0x0c03b87c */
if(!s->budget--) { s->failed_pc=0x0c03b87cu; return 0; }
r[14]=read(ram,0x0c03b8c4u,4);
goto P_0c03b87e;
P_0c03b87e: /* original d512, guest PC 0x0c03b87e */
if(!s->budget--) { s->failed_pc=0x0c03b87eu; return 0; }
r[5]=read(ram,0x0c03b8c8u,4);
goto P_0c03b880;
P_0c03b880: /* original 64e3, guest PC 0x0c03b880 */
if(!s->budget--) { s->failed_pc=0x0c03b880u; return 0; }
r[4]=r[14];
goto P_0c03b882;
P_0c03b882: /* original bfd5, guest PC 0x0c03b882 */
if(!s->budget--) { s->failed_pc=0x0c03b882u; return 0; }
target=0x0c03b830u; r[16]=0x0c03b886u;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b886u) { target=s->pc; goto dispatch; }
goto P_0c03b886;
P_0c03b884: /* original 7418, guest PC 0x0c03b884 */
if(!s->budget--) { s->failed_pc=0x0c03b884u; return 0; }
r[4]+=0x00000018u;
goto P_0c03b886;
P_0c03b886: /* original d511, guest PC 0x0c03b886 */
if(!s->budget--) { s->failed_pc=0x0c03b886u; return 0; }
r[5]=read(ram,0x0c03b8ccu,4);
goto P_0c03b888;
P_0c03b888: /* original 64e3, guest PC 0x0c03b888 */
if(!s->budget--) { s->failed_pc=0x0c03b888u; return 0; }
r[4]=r[14];
goto P_0c03b88a;
P_0c03b88a: /* original e603, guest PC 0x0c03b88a */
if(!s->budget--) { s->failed_pc=0x0c03b88au; return 0; }
r[6]=0x00000003u;
goto P_0c03b88c;
P_0c03b88c: /* original bfd0, guest PC 0x0c03b88c */
if(!s->budget--) { s->failed_pc=0x0c03b88cu; return 0; }
target=0x0c03b830u; r[16]=0x0c03b890u;
r[4]+=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b890u) { target=s->pc; goto dispatch; }
goto P_0c03b890;
P_0c03b88e: /* original 7424, guest PC 0x0c03b88e */
if(!s->budget--) { s->failed_pc=0x0c03b88eu; return 0; }
r[4]+=0x00000024u;
goto P_0c03b890;
P_0c03b890: /* original 56f1, guest PC 0x0c03b890 */
if(!s->budget--) { s->failed_pc=0x0c03b890u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c03b892;
P_0c03b892: /* original 64e3, guest PC 0x0c03b892 */
if(!s->budget--) { s->failed_pc=0x0c03b892u; return 0; }
r[4]=r[14];
goto P_0c03b894;
P_0c03b894: /* original 65f2, guest PC 0x0c03b894 */
if(!s->budget--) { s->failed_pc=0x0c03b894u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03b896;
P_0c03b896: /* original 740c, guest PC 0x0c03b896 */
if(!s->budget--) { s->failed_pc=0x0c03b896u; return 0; }
r[4]+=0x0000000cu;
goto P_0c03b898;
P_0c03b898: /* original 7601, guest PC 0x0c03b898 */
if(!s->budget--) { s->failed_pc=0x0c03b898u; return 0; }
r[6]+=0x00000001u;
goto P_0c03b89a;
P_0c03b89a: /* original bfc9, guest PC 0x0c03b89a */
if(!s->budget--) { s->failed_pc=0x0c03b89au; return 0; }
target=0x0c03b830u; r[16]=0x0c03b89eu;
write(ram,r[15]+8,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b89eu) { target=s->pc; goto dispatch; }
goto P_0c03b89e;
P_0c03b89c: /* original 1f42, guest PC 0x0c03b89c */
if(!s->budget--) { s->failed_pc=0x0c03b89cu; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c03b89e;
P_0c03b89e: /* original d30c, guest PC 0x0c03b89e */
if(!s->budget--) { s->failed_pc=0x0c03b89eu; return 0; }
r[3]=read(ram,0x0c03b8d0u,4);
goto P_0c03b8a0;
P_0c03b8a0: /* original e201, guest PC 0x0c03b8a0 */
if(!s->budget--) { s->failed_pc=0x0c03b8a0u; return 0; }
r[2]=0x00000001u;
goto P_0c03b8a2;
P_0c03b8a2: /* original 6403, guest PC 0x0c03b8a2 */
if(!s->budget--) { s->failed_pc=0x0c03b8a2u; return 0; }
r[4]=r[0];
goto P_0c03b8a4;
P_0c03b8a4: /* original 61e3, guest PC 0x0c03b8a4 */
if(!s->budget--) { s->failed_pc=0x0c03b8a4u; return 0; }
r[1]=r[14];
goto P_0c03b8a6;
P_0c03b8a6: /* original 2320, guest PC 0x0c03b8a6 */
if(!s->budget--) { s->failed_pc=0x0c03b8a6u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c03b8a8;
P_0c03b8a8: /* original d30a, guest PC 0x0c03b8a8 */
if(!s->budget--) { s->failed_pc=0x0c03b8a8u; return 0; }
r[3]=read(ram,0x0c03b8d4u,4);
goto P_0c03b8aa;
P_0c03b8aa: /* original 52f2, guest PC 0x0c03b8aa */
if(!s->budget--) { s->failed_pc=0x0c03b8aau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c03b8ac;
P_0c03b8ac: /* original 430b, guest PC 0x0c03b8ac */
if(!s->budget--) { s->failed_pc=0x0c03b8acu; return 0; }
target=r[3];
r[16]=0x0c03b8b0u;
r[0]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b8b0u) { target=s->pc; goto dispatch; }
goto P_0c03b8b0;
P_0c03b8ae: /* original e00c, guest PC 0x0c03b8ae */
if(!s->budget--) { s->failed_pc=0x0c03b8aeu; return 0; }
r[0]=0x0000000cu;
goto P_0c03b8b0;
P_0c03b8b0: /* original 7f0c, guest PC 0x0c03b8b0 */
if(!s->budget--) { s->failed_pc=0x0c03b8b0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c03b8b2;
P_0c03b8b2: /* original 6043, guest PC 0x0c03b8b2 */
if(!s->budget--) { s->failed_pc=0x0c03b8b2u; return 0; }
r[0]=r[4];
goto P_0c03b8b4;
P_0c03b8b4: /* original 4f26, guest PC 0x0c03b8b4 */
if(!s->budget--) { s->failed_pc=0x0c03b8b4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b8b6;
P_0c03b8b6: /* original 000b, guest PC 0x0c03b8b6 */
if(!s->budget--) { s->failed_pc=0x0c03b8b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b8b8: /* original 6ef6, guest PC 0x0c03b8b8 */
if(!s->budget--) { s->failed_pc=0x0c03b8b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03b8bau,s,ram);
P_0c03e620: /* original 4f22, guest PC 0x0c03e620 */
if(!s->budget--) { s->failed_pc=0x0c03e620u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e622;
P_0c03e622: /* original d646, guest PC 0x0c03e622 */
if(!s->budget--) { s->failed_pc=0x0c03e622u; return 0; }
r[6]=read(ram,0x0c03e73cu,4);
goto P_0c03e624;
P_0c03e624: /* original e400, guest PC 0x0c03e624 */
if(!s->budget--) { s->failed_pc=0x0c03e624u; return 0; }
r[4]=0x00000000u;
goto P_0c03e626;
P_0c03e626: /* original d546, guest PC 0x0c03e626 */
if(!s->budget--) { s->failed_pc=0x0c03e626u; return 0; }
r[5]=read(ram,0x0c03e740u,4);
goto P_0c03e628;
P_0c03e628: /* original e710, guest PC 0x0c03e628 */
if(!s->budget--) { s->failed_pc=0x0c03e628u; return 0; }
r[7]=0x00000010u;
goto P_0c03e62a;
P_0c03e62a: /* original 4f12, guest PC 0x0c03e62a */
if(!s->budget--) { s->failed_pc=0x0c03e62au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e62c;
P_0c03e62c: /* original 9183, guest PC 0x0c03e62c */
if(!s->budget--) { s->failed_pc=0x0c03e62cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e736u,2);
goto P_0c03e62e;
P_0c03e62e: /* original 9082, guest PC 0x0c03e62e */
if(!s->budget--) { s->failed_pc=0x0c03e62eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e736u,2);
goto P_0c03e630;
P_0c03e630: /* original 241f, guest PC 0x0c03e630 */
if(!s->budget--) { s->failed_pc=0x0c03e630u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[1]);
goto P_0c03e632;
P_0c03e632: /* original d344, guest PC 0x0c03e632 */
if(!s->budget--) { s->failed_pc=0x0c03e632u; return 0; }
r[3]=read(ram,0x0c03e744u,4);
goto P_0c03e634;
P_0c03e634: /* original 011a, guest PC 0x0c03e634 */
if(!s->budget--) { s->failed_pc=0x0c03e634u; return 0; }
r[1]=r[19];
goto P_0c03e636;
P_0c03e636: /* original 611f, guest PC 0x0c03e636 */
if(!s->budget--) { s->failed_pc=0x0c03e636u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c03e638;
P_0c03e638: /* original 316c, guest PC 0x0c03e638 */
if(!s->budget--) { s->failed_pc=0x0c03e638u; return 0; }
r[1]+=r[6];
goto P_0c03e63a;
P_0c03e63a: /* original 430b, guest PC 0x0c03e63a */
if(!s->budget--) { s->failed_pc=0x0c03e63au; return 0; }
target=r[3];
r[16]=0x0c03e63eu;
r[2]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e63eu) { target=s->pc; goto dispatch; }
goto P_0c03e63e;
P_0c03e63c: /* original 6253, guest PC 0x0c03e63c */
if(!s->budget--) { s->failed_pc=0x0c03e63cu; return 0; }
r[2]=r[5];
goto P_0c03e63e;
P_0c03e63e: /* original 917a, guest PC 0x0c03e63e */
if(!s->budget--) { s->failed_pc=0x0c03e63eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e736u,2);
goto P_0c03e640;
P_0c03e640: /* original 7401, guest PC 0x0c03e640 */
if(!s->budget--) { s->failed_pc=0x0c03e640u; return 0; }
r[4]+=0x00000001u;
goto P_0c03e642;
P_0c03e642: /* original 9078, guest PC 0x0c03e642 */
if(!s->budget--) { s->failed_pc=0x0c03e642u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e736u,2);
goto P_0c03e644;
P_0c03e644: /* original 241f, guest PC 0x0c03e644 */
if(!s->budget--) { s->failed_pc=0x0c03e644u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[1]);
goto P_0c03e646;
P_0c03e646: /* original d33f, guest PC 0x0c03e646 */
if(!s->budget--) { s->failed_pc=0x0c03e646u; return 0; }
r[3]=read(ram,0x0c03e744u,4);
goto P_0c03e648;
P_0c03e648: /* original 011a, guest PC 0x0c03e648 */
if(!s->budget--) { s->failed_pc=0x0c03e648u; return 0; }
r[1]=r[19];
goto P_0c03e64a;
P_0c03e64a: /* original 611f, guest PC 0x0c03e64a */
if(!s->budget--) { s->failed_pc=0x0c03e64au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c03e64c;
P_0c03e64c: /* original 316c, guest PC 0x0c03e64c */
if(!s->budget--) { s->failed_pc=0x0c03e64cu; return 0; }
r[1]+=r[6];
goto P_0c03e64e;
P_0c03e64e: /* original 430b, guest PC 0x0c03e64e */
if(!s->budget--) { s->failed_pc=0x0c03e64eu; return 0; }
target=r[3];
r[16]=0x0c03e652u;
r[2]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e652u) { target=s->pc; goto dispatch; }
goto P_0c03e652;
P_0c03e650: /* original 6253, guest PC 0x0c03e650 */
if(!s->budget--) { s->failed_pc=0x0c03e650u; return 0; }
r[2]=r[5];
goto P_0c03e652;
P_0c03e652: /* original 7401, guest PC 0x0c03e652 */
if(!s->budget--) { s->failed_pc=0x0c03e652u; return 0; }
r[4]+=0x00000001u;
goto P_0c03e654;
P_0c03e654: /* original 3473, guest PC 0x0c03e654 */
if(!s->budget--) { s->failed_pc=0x0c03e654u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c03e656;
P_0c03e656: /* original 8be9, guest PC 0x0c03e656 */
if(!s->budget--) { s->failed_pc=0x0c03e656u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e62c; }
goto P_0c03e658;
P_0c03e658: /* original 4f16, guest PC 0x0c03e658 */
if(!s->budget--) { s->failed_pc=0x0c03e658u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e65a;
P_0c03e65a: /* original d23b, guest PC 0x0c03e65a */
if(!s->budget--) { s->failed_pc=0x0c03e65au; return 0; }
r[2]=read(ram,0x0c03e748u,4);
goto P_0c03e65c;
P_0c03e65c: /* original e300, guest PC 0x0c03e65c */
if(!s->budget--) { s->failed_pc=0x0c03e65cu; return 0; }
r[3]=0x00000000u;
goto P_0c03e65e;
P_0c03e65e: /* original 4f26, guest PC 0x0c03e65e */
if(!s->budget--) { s->failed_pc=0x0c03e65eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e660;
P_0c03e660: /* original 2232, guest PC 0x0c03e660 */
if(!s->budget--) { s->failed_pc=0x0c03e660u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03e662;
P_0c03e662: /* original 000b, guest PC 0x0c03e662 */
if(!s->budget--) { s->failed_pc=0x0c03e662u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03e664: /* original 0009, guest PC 0x0c03e664 */
if(!s->budget--) { s->failed_pc=0x0c03e664u; return 0; }
return vf3_matrix_family(0x0c03e666u,s,ram);
P_0c03ea22: /* original 4f22, guest PC 0x0c03ea22 */
if(!s->budget--) { s->failed_pc=0x0c03ea22u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ea24;
P_0c03ea24: /* original d92c, guest PC 0x0c03ea24 */
if(!s->budget--) { s->failed_pc=0x0c03ea24u; return 0; }
r[9]=read(ram,0x0c03ead8u,4);
goto P_0c03ea26;
P_0c03ea26: /* original da2d, guest PC 0x0c03ea26 */
if(!s->budget--) { s->failed_pc=0x0c03ea26u; return 0; }
r[10]=read(ram,0x0c03eadcu,4);
goto P_0c03ea28;
P_0c03ea28: /* original 4f12, guest PC 0x0c03ea28 */
if(!s->budget--) { s->failed_pc=0x0c03ea28u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03ea2a;
P_0c03ea2a: /* original db2d, guest PC 0x0c03ea2a */
if(!s->budget--) { s->failed_pc=0x0c03ea2au; return 0; }
r[11]=read(ram,0x0c03eae0u,4);
goto P_0c03ea2c;
P_0c03ea2c: /* original d829, guest PC 0x0c03ea2c */
if(!s->budget--) { s->failed_pc=0x0c03ea2cu; return 0; }
r[8]=read(ram,0x0c03ead4u,4);
goto P_0c03ea2e;
P_0c03ea2e: /* original 9d4f, guest PC 0x0c03ea2e */
if(!s->budget--) { s->failed_pc=0x0c03ea2eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03ead0u,2);
goto P_0c03ea30;
P_0c03ea30: /* original 60e3, guest PC 0x0c03ea30 */
if(!s->budget--) { s->failed_pc=0x0c03ea30u; return 0; }
r[0]=r[14];
goto P_0c03ea32;
P_0c03ea32: /* original 4008, guest PC 0x0c03ea32 */
if(!s->budget--) { s->failed_pc=0x0c03ea32u; return 0; }
r[0]<<=2;
goto P_0c03ea34;
P_0c03ea34: /* original 64e3, guest PC 0x0c03ea34 */
if(!s->budget--) { s->failed_pc=0x0c03ea34u; return 0; }
r[4]=r[14];
goto P_0c03ea36;
P_0c03ea36: /* original 2edf, guest PC 0x0c03ea36 */
if(!s->budget--) { s->failed_pc=0x0c03ea36u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c03ea38;
P_0c03ea38: /* original 4408, guest PC 0x0c03ea38 */
if(!s->budget--) { s->failed_pc=0x0c03ea38u; return 0; }
r[4]<<=2;
goto P_0c03ea3a;
P_0c03ea3a: /* original 6583, guest PC 0x0c03ea3a */
if(!s->budget--) { s->failed_pc=0x0c03ea3au; return 0; }
r[5]=r[8];
goto P_0c03ea3c;
P_0c03ea3c: /* original 4408, guest PC 0x0c03ea3c */
if(!s->budget--) { s->failed_pc=0x0c03ea3cu; return 0; }
r[4]<<=2;
goto P_0c03ea3e;
P_0c03ea3e: /* original 349c, guest PC 0x0c03ea3e */
if(!s->budget--) { s->failed_pc=0x0c03ea3eu; return 0; }
r[4]+=r[9];
goto P_0c03ea40;
P_0c03ea40: /* original 0d1a, guest PC 0x0c03ea40 */
if(!s->budget--) { s->failed_pc=0x0c03ea40u; return 0; }
r[13]=r[19];
goto P_0c03ea42;
P_0c03ea42: /* original 6ddf, guest PC 0x0c03ea42 */
if(!s->budget--) { s->failed_pc=0x0c03ea42u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c03ea44;
P_0c03ea44: /* original 3dac, guest PC 0x0c03ea44 */
if(!s->budget--) { s->failed_pc=0x0c03ea44u; return 0; }
r[13]+=r[10];
goto P_0c03ea46;
P_0c03ea46: /* original 63d1, guest PC 0x0c03ea46 */
if(!s->budget--) { s->failed_pc=0x0c03ea46u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c03ea48;
P_0c03ea48: /* original 0b36, guest PC 0x0c03ea48 */
if(!s->budget--) { s->failed_pc=0x0c03ea48u; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c03ea4a;
P_0c03ea4a: /* original e014, guest PC 0x0c03ea4a */
if(!s->budget--) { s->failed_pc=0x0c03ea4au; return 0; }
r[0]=0x00000014u;
goto P_0c03ea4c;
P_0c03ea4c: /* original f3d6, guest PC 0x0c03ea4c */
if(!s->budget--) { s->failed_pc=0x0c03ea4cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea4e;
P_0c03ea4e: /* original e018, guest PC 0x0c03ea4e */
if(!s->budget--) { s->failed_pc=0x0c03ea4eu; return 0; }
r[0]=0x00000018u;
goto P_0c03ea50;
P_0c03ea50: /* original f43a, guest PC 0x0c03ea50 */
if(!s->budget--) { s->failed_pc=0x0c03ea50u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c03ea52;
P_0c03ea52: /* original f3d6, guest PC 0x0c03ea52 */
if(!s->budget--) { s->failed_pc=0x0c03ea52u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea54;
P_0c03ea54: /* original e004, guest PC 0x0c03ea54 */
if(!s->budget--) { s->failed_pc=0x0c03ea54u; return 0; }
r[0]=0x00000004u;
goto P_0c03ea56;
P_0c03ea56: /* original f437, guest PC 0x0c03ea56 */
if(!s->budget--) { s->failed_pc=0x0c03ea56u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03ea58;
P_0c03ea58: /* original e01c, guest PC 0x0c03ea58 */
if(!s->budget--) { s->failed_pc=0x0c03ea58u; return 0; }
r[0]=0x0000001cu;
goto P_0c03ea5a;
P_0c03ea5a: /* original f3d6, guest PC 0x0c03ea5a */
if(!s->budget--) { s->failed_pc=0x0c03ea5au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea5c;
P_0c03ea5c: /* original e008, guest PC 0x0c03ea5c */
if(!s->budget--) { s->failed_pc=0x0c03ea5cu; return 0; }
r[0]=0x00000008u;
goto P_0c03ea5e;
P_0c03ea5e: /* original f437, guest PC 0x0c03ea5e */
if(!s->budget--) { s->failed_pc=0x0c03ea5eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03ea60;
P_0c03ea60: /* original e020, guest PC 0x0c03ea60 */
if(!s->budget--) { s->failed_pc=0x0c03ea60u; return 0; }
r[0]=0x00000020u;
goto P_0c03ea62;
P_0c03ea62: /* original f3d6, guest PC 0x0c03ea62 */
if(!s->budget--) { s->failed_pc=0x0c03ea62u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea64;
P_0c03ea64: /* original e00c, guest PC 0x0c03ea64 */
if(!s->budget--) { s->failed_pc=0x0c03ea64u; return 0; }
r[0]=0x0000000cu;
goto P_0c03ea66;
P_0c03ea66: /* original f437, guest PC 0x0c03ea66 */
if(!s->budget--) { s->failed_pc=0x0c03ea66u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03ea68;
P_0c03ea68: /* original befa, guest PC 0x0c03ea68 */
if(!s->budget--) { s->failed_pc=0x0c03ea68u; return 0; }
target=0x0c03e860u; r[16]=0x0c03ea6cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ea6cu) { target=s->pc; goto dispatch; }
goto P_0c03ea6c;
P_0c03ea6a: /* original 64e3, guest PC 0x0c03ea6a */
if(!s->budget--) { s->failed_pc=0x0c03ea6au; return 0; }
r[4]=r[14];
goto P_0c03ea6c;
P_0c03ea6c: /* original 2dc1, guest PC 0x0c03ea6c */
if(!s->budget--) { s->failed_pc=0x0c03ea6cu; return 0; }
write(ram,r[13],r[12],2);
goto P_0c03ea6e;
P_0c03ea6e: /* original 7e01, guest PC 0x0c03ea6e */
if(!s->budget--) { s->failed_pc=0x0c03ea6eu; return 0; }
r[14]+=0x00000001u;
goto P_0c03ea70;
P_0c03ea70: /* original 9d2e, guest PC 0x0c03ea70 */
if(!s->budget--) { s->failed_pc=0x0c03ea70u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03ead0u,2);
goto P_0c03ea72;
P_0c03ea72: /* original 60e3, guest PC 0x0c03ea72 */
if(!s->budget--) { s->failed_pc=0x0c03ea72u; return 0; }
r[0]=r[14];
goto P_0c03ea74;
P_0c03ea74: /* original 4008, guest PC 0x0c03ea74 */
if(!s->budget--) { s->failed_pc=0x0c03ea74u; return 0; }
r[0]<<=2;
goto P_0c03ea76;
P_0c03ea76: /* original 64e3, guest PC 0x0c03ea76 */
if(!s->budget--) { s->failed_pc=0x0c03ea76u; return 0; }
r[4]=r[14];
goto P_0c03ea78;
P_0c03ea78: /* original 2edf, guest PC 0x0c03ea78 */
if(!s->budget--) { s->failed_pc=0x0c03ea78u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c03ea7a;
P_0c03ea7a: /* original 4408, guest PC 0x0c03ea7a */
if(!s->budget--) { s->failed_pc=0x0c03ea7au; return 0; }
r[4]<<=2;
goto P_0c03ea7c;
P_0c03ea7c: /* original 6583, guest PC 0x0c03ea7c */
if(!s->budget--) { s->failed_pc=0x0c03ea7cu; return 0; }
r[5]=r[8];
goto P_0c03ea7e;
P_0c03ea7e: /* original 4408, guest PC 0x0c03ea7e */
if(!s->budget--) { s->failed_pc=0x0c03ea7eu; return 0; }
r[4]<<=2;
goto P_0c03ea80;
P_0c03ea80: /* original 349c, guest PC 0x0c03ea80 */
if(!s->budget--) { s->failed_pc=0x0c03ea80u; return 0; }
r[4]+=r[9];
goto P_0c03ea82;
P_0c03ea82: /* original 0d1a, guest PC 0x0c03ea82 */
if(!s->budget--) { s->failed_pc=0x0c03ea82u; return 0; }
r[13]=r[19];
goto P_0c03ea84;
P_0c03ea84: /* original 6ddf, guest PC 0x0c03ea84 */
if(!s->budget--) { s->failed_pc=0x0c03ea84u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c03ea86;
P_0c03ea86: /* original 3dac, guest PC 0x0c03ea86 */
if(!s->budget--) { s->failed_pc=0x0c03ea86u; return 0; }
r[13]+=r[10];
goto P_0c03ea88;
P_0c03ea88: /* original 63d1, guest PC 0x0c03ea88 */
if(!s->budget--) { s->failed_pc=0x0c03ea88u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c03ea8a;
P_0c03ea8a: /* original 0b36, guest PC 0x0c03ea8a */
if(!s->budget--) { s->failed_pc=0x0c03ea8au; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c03ea8c;
P_0c03ea8c: /* original e014, guest PC 0x0c03ea8c */
if(!s->budget--) { s->failed_pc=0x0c03ea8cu; return 0; }
r[0]=0x00000014u;
goto P_0c03ea8e;
P_0c03ea8e: /* original f3d6, guest PC 0x0c03ea8e */
if(!s->budget--) { s->failed_pc=0x0c03ea8eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea90;
P_0c03ea90: /* original e018, guest PC 0x0c03ea90 */
if(!s->budget--) { s->failed_pc=0x0c03ea90u; return 0; }
r[0]=0x00000018u;
goto P_0c03ea92;
P_0c03ea92: /* original f43a, guest PC 0x0c03ea92 */
if(!s->budget--) { s->failed_pc=0x0c03ea92u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c03ea94;
P_0c03ea94: /* original f3d6, guest PC 0x0c03ea94 */
if(!s->budget--) { s->failed_pc=0x0c03ea94u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea96;
P_0c03ea96: /* original e004, guest PC 0x0c03ea96 */
if(!s->budget--) { s->failed_pc=0x0c03ea96u; return 0; }
r[0]=0x00000004u;
goto P_0c03ea98;
P_0c03ea98: /* original f437, guest PC 0x0c03ea98 */
if(!s->budget--) { s->failed_pc=0x0c03ea98u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03ea9a;
P_0c03ea9a: /* original e01c, guest PC 0x0c03ea9a */
if(!s->budget--) { s->failed_pc=0x0c03ea9au; return 0; }
r[0]=0x0000001cu;
goto P_0c03ea9c;
P_0c03ea9c: /* original f3d6, guest PC 0x0c03ea9c */
if(!s->budget--) { s->failed_pc=0x0c03ea9cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea9e;
P_0c03ea9e: /* original e008, guest PC 0x0c03ea9e */
if(!s->budget--) { s->failed_pc=0x0c03ea9eu; return 0; }
r[0]=0x00000008u;
goto P_0c03eaa0;
P_0c03eaa0: /* original f437, guest PC 0x0c03eaa0 */
if(!s->budget--) { s->failed_pc=0x0c03eaa0u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03eaa2;
P_0c03eaa2: /* original e020, guest PC 0x0c03eaa2 */
if(!s->budget--) { s->failed_pc=0x0c03eaa2u; return 0; }
r[0]=0x00000020u;
goto P_0c03eaa4;
P_0c03eaa4: /* original f3d6, guest PC 0x0c03eaa4 */
if(!s->budget--) { s->failed_pc=0x0c03eaa4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03eaa6;
P_0c03eaa6: /* original e00c, guest PC 0x0c03eaa6 */
if(!s->budget--) { s->failed_pc=0x0c03eaa6u; return 0; }
r[0]=0x0000000cu;
goto P_0c03eaa8;
P_0c03eaa8: /* original f437, guest PC 0x0c03eaa8 */
if(!s->budget--) { s->failed_pc=0x0c03eaa8u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03eaaa;
P_0c03eaaa: /* original bed9, guest PC 0x0c03eaaa */
if(!s->budget--) { s->failed_pc=0x0c03eaaau; return 0; }
target=0x0c03e860u; r[16]=0x0c03eaaeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03eaaeu) { target=s->pc; goto dispatch; }
goto P_0c03eaae;
P_0c03eaac: /* original 64e3, guest PC 0x0c03eaac */
if(!s->budget--) { s->failed_pc=0x0c03eaacu; return 0; }
r[4]=r[14];
goto P_0c03eaae;
P_0c03eaae: /* original e210, guest PC 0x0c03eaae */
if(!s->budget--) { s->failed_pc=0x0c03eaaeu; return 0; }
r[2]=0x00000010u;
goto P_0c03eab0;
P_0c03eab0: /* original 7e01, guest PC 0x0c03eab0 */
if(!s->budget--) { s->failed_pc=0x0c03eab0u; return 0; }
r[14]+=0x00000001u;
goto P_0c03eab2;
P_0c03eab2: /* original 3e23, guest PC 0x0c03eab2 */
if(!s->budget--) { s->failed_pc=0x0c03eab2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c03eab4;
P_0c03eab4: /* original 8fbb, guest PC 0x0c03eab4 */
if(!s->budget--) { s->failed_pc=0x0c03eab4u; return 0; }
cond=r[17]&1u;
write(ram,r[13],r[12],2);
if(!cond) { goto P_0c03ea2e; }
goto P_0c03eab8;
P_0c03eab6: /* original 2dc1, guest PC 0x0c03eab6 */
if(!s->budget--) { s->failed_pc=0x0c03eab6u; return 0; }
write(ram,r[13],r[12],2);
goto P_0c03eab8;
P_0c03eab8: /* original 4f16, guest PC 0x0c03eab8 */
if(!s->budget--) { s->failed_pc=0x0c03eab8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03eaba;
P_0c03eaba: /* original d10a, guest PC 0x0c03eaba */
if(!s->budget--) { s->failed_pc=0x0c03eabau; return 0; }
r[1]=read(ram,0x0c03eae4u,4);
goto P_0c03eabc;
P_0c03eabc: /* original 4f26, guest PC 0x0c03eabc */
if(!s->budget--) { s->failed_pc=0x0c03eabcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03eabe;
P_0c03eabe: /* original 21c2, guest PC 0x0c03eabe */
if(!s->budget--) { s->failed_pc=0x0c03eabeu; return 0; }
write(ram,r[1],r[12],4);
goto P_0c03eac0;
P_0c03eac0: /* original 68f6, guest PC 0x0c03eac0 */
if(!s->budget--) { s->failed_pc=0x0c03eac0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03eac2;
P_0c03eac2: /* original 69f6, guest PC 0x0c03eac2 */
if(!s->budget--) { s->failed_pc=0x0c03eac2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03eac4;
P_0c03eac4: /* original 6af6, guest PC 0x0c03eac4 */
if(!s->budget--) { s->failed_pc=0x0c03eac4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03eac6;
P_0c03eac6: /* original 6bf6, guest PC 0x0c03eac6 */
if(!s->budget--) { s->failed_pc=0x0c03eac6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03eac8;
P_0c03eac8: /* original 6cf6, guest PC 0x0c03eac8 */
if(!s->budget--) { s->failed_pc=0x0c03eac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03eaca;
P_0c03eaca: /* original 6df6, guest PC 0x0c03eaca */
if(!s->budget--) { s->failed_pc=0x0c03eacau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03eacc;
P_0c03eacc: /* original 000b, guest PC 0x0c03eacc */
if(!s->budget--) { s->failed_pc=0x0c03eaccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03eace: /* original 6ef6, guest PC 0x0c03eace */
if(!s->budget--) { s->failed_pc=0x0c03eaceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03ead0u,s,ram);
P_0c03f2d0: /* original 2fe6, guest PC 0x0c03f2d0 */
if(!s->budget--) { s->failed_pc=0x0c03f2d0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c03f2d2;
P_0c03f2d2: /* original 2fd6, guest PC 0x0c03f2d2 */
if(!s->budget--) { s->failed_pc=0x0c03f2d2u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c03f2d4;
P_0c03f2d4: /* original 2fc6, guest PC 0x0c03f2d4 */
if(!s->budget--) { s->failed_pc=0x0c03f2d4u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c03f2d6;
P_0c03f2d6: /* original 2fb6, guest PC 0x0c03f2d6 */
if(!s->budget--) { s->failed_pc=0x0c03f2d6u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c03f2d8;
P_0c03f2d8: /* original 2fa6, guest PC 0x0c03f2d8 */
if(!s->budget--) { s->failed_pc=0x0c03f2d8u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c03f2da;
P_0c03f2da: /* original 2f96, guest PC 0x0c03f2da */
if(!s->budget--) { s->failed_pc=0x0c03f2dau; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c03f2dc;
P_0c03f2dc: /* original 2f86, guest PC 0x0c03f2dc */
if(!s->budget--) { s->failed_pc=0x0c03f2dcu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c03f2de;
P_0c03f2de: /* original 6342, guest PC 0x0c03f2de */
if(!s->budget--) { s->failed_pc=0x0c03f2deu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
return vf3_matrix_family(0x0c03f2e0u,s,ram);
P_0c03f524: /* original 4f22, guest PC 0x0c03f524 */
if(!s->budget--) { s->failed_pc=0x0c03f524u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f526;
P_0c03f526: /* original 711f, guest PC 0x0c03f526 */
if(!s->budget--) { s->failed_pc=0x0c03f526u; return 0; }
r[1]+=0x0000001fu;
goto P_0c03f528;
P_0c03f528: /* original 2b62, guest PC 0x0c03f528 */
if(!s->budget--) { s->failed_pc=0x0c03f528u; return 0; }
write(ram,r[11],r[6],4);
goto P_0c03f52a;
P_0c03f52a: /* original d799, guest PC 0x0c03f52a */
if(!s->budget--) { s->failed_pc=0x0c03f52au; return 0; }
r[7]=read(ram,0x0c03f790u,4);
goto P_0c03f52c;
P_0c03f52c: /* original ee20, guest PC 0x0c03f52c */
if(!s->budget--) { s->failed_pc=0x0c03f52cu; return 0; }
r[14]=0x00000020u;
goto P_0c03f52e;
P_0c03f52e: /* original 2742, guest PC 0x0c03f52e */
if(!s->budget--) { s->failed_pc=0x0c03f52eu; return 0; }
write(ram,r[7],r[4],4);
goto P_0c03f530;
P_0c03f530: /* original e4fc, guest PC 0x0c03f530 */
if(!s->budget--) { s->failed_pc=0x0c03f530u; return 0; }
r[4]=0xfffffffcu;
goto P_0c03f532;
P_0c03f532: /* original dc98, guest PC 0x0c03f532 */
if(!s->budget--) { s->failed_pc=0x0c03f532u; return 0; }
r[12]=read(ram,0x0c03f794u,4);
goto P_0c03f534;
P_0c03f534: /* original 2439, guest PC 0x0c03f534 */
if(!s->budget--) { s->failed_pc=0x0c03f534u; return 0; }
r[4]&=r[3];
goto P_0c03f536;
P_0c03f536: /* original 2c42, guest PC 0x0c03f536 */
if(!s->budget--) { s->failed_pc=0x0c03f536u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c03f538;
P_0c03f538: /* original 60e3, guest PC 0x0c03f538 */
if(!s->budget--) { s->failed_pc=0x0c03f538u; return 0; }
r[0]=r[14];
goto P_0c03f53a;
P_0c03f53a: /* original 0009, guest PC 0x0c03f53a */
if(!s->budget--) { s->failed_pc=0x0c03f53au; return 0; }
goto P_0c03f53c;
P_0c03f53c: /* original d396, guest PC 0x0c03f53c */
if(!s->budget--) { s->failed_pc=0x0c03f53cu; return 0; }
r[3]=read(ram,0x0c03f798u,4);
goto P_0c03f53e;
P_0c03f53e: /* original 430b, guest PC 0x0c03f53e */
if(!s->budget--) { s->failed_pc=0x0c03f53eu; return 0; }
target=r[3];
r[16]=0x0c03f542u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f542u) { target=s->pc; goto dispatch; }
goto P_0c03f542;
P_0c03f540: /* original 0009, guest PC 0x0c03f540 */
if(!s->budget--) { s->failed_pc=0x0c03f540u; return 0; }
goto P_0c03f542;
P_0c03f542: /* original 4008, guest PC 0x0c03f542 */
if(!s->budget--) { s->failed_pc=0x0c03f542u; return 0; }
r[0]<<=2;
goto P_0c03f544;
P_0c03f544: /* original d295, guest PC 0x0c03f544 */
if(!s->budget--) { s->failed_pc=0x0c03f544u; return 0; }
r[2]=read(ram,0x0c03f79cu,4);
goto P_0c03f546;
P_0c03f546: /* original 304c, guest PC 0x0c03f546 */
if(!s->budget--) { s->failed_pc=0x0c03f546u; return 0; }
r[0]+=r[4];
goto P_0c03f548;
P_0c03f548: /* original 4515, guest PC 0x0c03f548 */
if(!s->budget--) { s->failed_pc=0x0c03f548u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c03f54a;
P_0c03f54a: /* original e4fc, guest PC 0x0c03f54a */
if(!s->budget--) { s->failed_pc=0x0c03f54au; return 0; }
r[4]=0xfffffffcu;
goto P_0c03f54c;
P_0c03f54c: /* original 7003, guest PC 0x0c03f54c */
if(!s->budget--) { s->failed_pc=0x0c03f54cu; return 0; }
r[0]+=0x00000003u;
goto P_0c03f54e;
P_0c03f54e: /* original 2409, guest PC 0x0c03f54e */
if(!s->budget--) { s->failed_pc=0x0c03f54eu; return 0; }
r[4]&=r[0];
goto P_0c03f550;
P_0c03f550: /* original e600, guest PC 0x0c03f550 */
if(!s->budget--) { s->failed_pc=0x0c03f550u; return 0; }
r[6]=0x00000000u;
goto P_0c03f552;
P_0c03f552: /* original 2242, guest PC 0x0c03f552 */
if(!s->budget--) { s->failed_pc=0x0c03f552u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c03f554;
P_0c03f554: /* original 6463, guest PC 0x0c03f554 */
if(!s->budget--) { s->failed_pc=0x0c03f554u; return 0; }
r[4]=r[6];
goto P_0c03f556;
P_0c03f556: /* original 6d63, guest PC 0x0c03f556 */
if(!s->budget--) { s->failed_pc=0x0c03f556u; return 0; }
r[13]=r[6];
goto P_0c03f558;
P_0c03f558: /* original 8f06, guest PC 0x0c03f558 */
if(!s->budget--) { s->failed_pc=0x0c03f558u; return 0; }
cond=r[17]&1u;
r[1]=0xffffffffu;
if(!cond) { goto P_0c03f568; }
goto P_0c03f55c;
P_0c03f55a: /* original e1ff, guest PC 0x0c03f55a */
if(!s->budget--) { s->failed_pc=0x0c03f55au; return 0; }
r[1]=0xffffffffu;
goto P_0c03f55c;
P_0c03f55c: /* original 6072, guest PC 0x0c03f55c */
if(!s->budget--) { s->failed_pc=0x0c03f55cu; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03f55e;
P_0c03f55e: /* original 7d01, guest PC 0x0c03f55e */
if(!s->budget--) { s->failed_pc=0x0c03f55eu; return 0; }
r[13]+=0x00000001u;
goto P_0c03f560;
P_0c03f560: /* original 3d53, guest PC 0x0c03f560 */
if(!s->budget--) { s->failed_pc=0x0c03f560u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[5])!=0);
goto P_0c03f562;
P_0c03f562: /* original 0415, guest PC 0x0c03f562 */
if(!s->budget--) { s->failed_pc=0x0c03f562u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c03f564;
P_0c03f564: /* original 8ffa, guest PC 0x0c03f564 */
if(!s->budget--) { s->failed_pc=0x0c03f564u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000002u;
if(!cond) { goto P_0c03f55c; }
goto P_0c03f568;
P_0c03f566: /* original 7402, guest PC 0x0c03f566 */
if(!s->budget--) { s->failed_pc=0x0c03f566u; return 0; }
r[4]+=0x00000002u;
goto P_0c03f568;
P_0c03f568: /* original a008, guest PC 0x0c03f568 */
if(!s->budget--) { s->failed_pc=0x0c03f568u; return 0; }
r[4]=r[6];
goto P_0c03f57c;
P_0c03f56a: /* original 6463, guest PC 0x0c03f56a */
if(!s->budget--) { s->failed_pc=0x0c03f56au; return 0; }
r[4]=r[6];
return vf3_matrix_family(0x0c03f56cu,s,ram);
P_0c03f570: /* original 6043, guest PC 0x0c03f570 */
if(!s->budget--) { s->failed_pc=0x0c03f570u; return 0; }
r[0]=r[4];
goto P_0c03f572;
P_0c03f572: /* original 0009, guest PC 0x0c03f572 */
if(!s->budget--) { s->failed_pc=0x0c03f572u; return 0; }
goto P_0c03f574;
P_0c03f574: /* original 63c2, guest PC 0x0c03f574 */
if(!s->budget--) { s->failed_pc=0x0c03f574u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f576;
P_0c03f576: /* original 4008, guest PC 0x0c03f576 */
if(!s->budget--) { s->failed_pc=0x0c03f576u; return 0; }
r[0]<<=2;
goto P_0c03f578;
P_0c03f578: /* original 7401, guest PC 0x0c03f578 */
if(!s->budget--) { s->failed_pc=0x0c03f578u; return 0; }
r[4]+=0x00000001u;
goto P_0c03f57a;
P_0c03f57a: /* original 0366, guest PC 0x0c03f57a */
if(!s->budget--) { s->failed_pc=0x0c03f57au; return 0; }
write(ram,r[3]+r[0],r[6],4);
goto P_0c03f57c;
P_0c03f57c: /* original 61b2, guest PC 0x0c03f57c */
if(!s->budget--) { s->failed_pc=0x0c03f57cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c03f57e;
P_0c03f57e: /* original 711f, guest PC 0x0c03f57e */
if(!s->budget--) { s->failed_pc=0x0c03f57eu; return 0; }
r[1]+=0x0000001fu;
goto P_0c03f580;
P_0c03f580: /* original 60e3, guest PC 0x0c03f580 */
if(!s->budget--) { s->failed_pc=0x0c03f580u; return 0; }
r[0]=r[14];
goto P_0c03f582;
P_0c03f582: /* original 0009, guest PC 0x0c03f582 */
if(!s->budget--) { s->failed_pc=0x0c03f582u; return 0; }
goto P_0c03f584;
P_0c03f584: /* original d384, guest PC 0x0c03f584 */
if(!s->budget--) { s->failed_pc=0x0c03f584u; return 0; }
r[3]=read(ram,0x0c03f798u,4);
goto P_0c03f586;
P_0c03f586: /* original 430b, guest PC 0x0c03f586 */
if(!s->budget--) { s->failed_pc=0x0c03f586u; return 0; }
target=r[3];
r[16]=0x0c03f58au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f58au) { target=s->pc; goto dispatch; }
goto P_0c03f58a;
P_0c03f588: /* original 0009, guest PC 0x0c03f588 */
if(!s->budget--) { s->failed_pc=0x0c03f588u; return 0; }
goto P_0c03f58a;
P_0c03f58a: /* original 3403, guest PC 0x0c03f58a */
if(!s->budget--) { s->failed_pc=0x0c03f58au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c03f58c;
P_0c03f58c: /* original 8bf0, guest PC 0x0c03f58c */
if(!s->budget--) { s->failed_pc=0x0c03f58cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f570; }
goto P_0c03f58e;
P_0c03f58e: /* original 4f26, guest PC 0x0c03f58e */
if(!s->budget--) { s->failed_pc=0x0c03f58eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f590;
P_0c03f590: /* original 6bf6, guest PC 0x0c03f590 */
if(!s->budget--) { s->failed_pc=0x0c03f590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f592;
P_0c03f592: /* original 6cf6, guest PC 0x0c03f592 */
if(!s->budget--) { s->failed_pc=0x0c03f592u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f594;
P_0c03f594: /* original 6df6, guest PC 0x0c03f594 */
if(!s->budget--) { s->failed_pc=0x0c03f594u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f596;
P_0c03f596: /* original 000b, guest PC 0x0c03f596 */
if(!s->budget--) { s->failed_pc=0x0c03f596u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f598: /* original 6ef6, guest PC 0x0c03f598 */
if(!s->budget--) { s->failed_pc=0x0c03f598u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f59au,s,ram);
P_0c043ac6: /* original 4f22, guest PC 0x0c043ac6 */
if(!s->budget--) { s->failed_pc=0x0c043ac6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043ac8;
P_0c043ac8: /* original 4009, guest PC 0x0c043ac8 */
if(!s->budget--) { s->failed_pc=0x0c043ac8u; return 0; }
r[0]>>=2;
goto P_0c043aca;
P_0c043aca: /* original 4009, guest PC 0x0c043aca */
if(!s->budget--) { s->failed_pc=0x0c043acau; return 0; }
r[0]>>=2;
goto P_0c043acc;
P_0c043acc: /* original c90f, guest PC 0x0c043acc */
if(!s->budget--) { s->failed_pc=0x0c043accu; return 0; }
r[0]&=15u;
goto P_0c043ace;
P_0c043ace: /* original 7ff4, guest PC 0x0c043ace */
if(!s->budget--) { s->failed_pc=0x0c043aceu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c043ad0;
P_0c043ad0: /* original 1f41, guest PC 0x0c043ad0 */
if(!s->budget--) { s->failed_pc=0x0c043ad0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c043ad2;
P_0c043ad2: /* original 2f52, guest PC 0x0c043ad2 */
if(!s->budget--) { s->failed_pc=0x0c043ad2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c043ad4;
P_0c043ad4: /* original 1f02, guest PC 0x0c043ad4 */
if(!s->budget--) { s->failed_pc=0x0c043ad4u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c043ad6;
P_0c043ad6: /* original 0002, guest PC 0x0c043ad6 */
if(!s->budget--) { s->failed_pc=0x0c043ad6u; return 0; }
r[0]=r[17];
goto P_0c043ad8;
P_0c043ad8: /* original 9347, guest PC 0x0c043ad8 */
if(!s->budget--) { s->failed_pc=0x0c043ad8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043b6au,2);
goto P_0c043ada;
P_0c043ada: /* original 2039, guest PC 0x0c043ada */
if(!s->budget--) { s->failed_pc=0x0c043adau; return 0; }
r[0]&=r[3];
goto P_0c043adc;
P_0c043adc: /* original cbf0, guest PC 0x0c043adc */
if(!s->budget--) { s->failed_pc=0x0c043adcu; return 0; }
r[0]|=240u;
goto P_0c043ade;
P_0c043ade: /* original 400e, guest PC 0x0c043ade */
if(!s->budget--) { s->failed_pc=0x0c043adeu; return 0; }
r[17]=r[0];
goto P_0c043ae0;
P_0c043ae0: /* original d529, guest PC 0x0c043ae0 */
if(!s->budget--) { s->failed_pc=0x0c043ae0u; return 0; }
r[5]=read(ram,0x0c043b88u,4);
goto P_0c043ae2;
P_0c043ae2: /* original e700, guest PC 0x0c043ae2 */
if(!s->budget--) { s->failed_pc=0x0c043ae2u; return 0; }
r[7]=0x00000000u;
goto P_0c043ae4;
P_0c043ae4: /* original 9442, guest PC 0x0c043ae4 */
if(!s->budget--) { s->failed_pc=0x0c043ae4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043b6cu,2);
goto P_0c043ae6;
P_0c043ae6: /* original de27, guest PC 0x0c043ae6 */
if(!s->budget--) { s->failed_pc=0x0c043ae6u; return 0; }
r[14]=read(ram,0x0c043b84u,4);
goto P_0c043ae8;
P_0c043ae8: /* original dc24, guest PC 0x0c043ae8 */
if(!s->budget--) { s->failed_pc=0x0c043ae8u; return 0; }
r[12]=read(ram,0x0c043b7cu,4);
goto P_0c043aea;
P_0c043aea: /* original dd25, guest PC 0x0c043aea */
if(!s->budget--) { s->failed_pc=0x0c043aeau; return 0; }
r[13]=read(ram,0x0c043b80u,4);
goto P_0c043aec;
P_0c043aec: /* original 4c0b, guest PC 0x0c043aec */
if(!s->budget--) { s->failed_pc=0x0c043aecu; return 0; }
target=r[12];
r[16]=0x0c043af0u;
tmp=read(ram,r[13],4);
r[6]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043af0u) { target=s->pc; goto dispatch; }
goto P_0c043af0;
P_0c043aee: /* original 66d2, guest PC 0x0c043aee */
if(!s->budget--) { s->failed_pc=0x0c043aeeu; return 0; }
tmp=read(ram,r[13],4);
r[6]=tmp;
goto P_0c043af0;
P_0c043af0: /* original 2e02, guest PC 0x0c043af0 */
if(!s->budget--) { s->failed_pc=0x0c043af0u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c043af2;
P_0c043af2: /* original e700, guest PC 0x0c043af2 */
if(!s->budget--) { s->failed_pc=0x0c043af2u; return 0; }
r[7]=0x00000000u;
goto P_0c043af4;
P_0c043af4: /* original d525, guest PC 0x0c043af4 */
if(!s->budget--) { s->failed_pc=0x0c043af4u; return 0; }
r[5]=read(ram,0x0c043b8cu,4);
goto P_0c043af6;
P_0c043af6: /* original 943a, guest PC 0x0c043af6 */
if(!s->budget--) { s->failed_pc=0x0c043af6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043b6eu,2);
goto P_0c043af8;
P_0c043af8: /* original 4c0b, guest PC 0x0c043af8 */
if(!s->budget--) { s->failed_pc=0x0c043af8u; return 0; }
target=r[12];
r[16]=0x0c043afcu;
r[6]=read(ram,r[13]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043afcu) { target=s->pc; goto dispatch; }
goto P_0c043afc;
P_0c043afa: /* original 56d1, guest PC 0x0c043afa */
if(!s->budget--) { s->failed_pc=0x0c043afau; return 0; }
r[6]=read(ram,r[13]+4,4);
goto P_0c043afc;
P_0c043afc: /* original 1e01, guest PC 0x0c043afc */
if(!s->budget--) { s->failed_pc=0x0c043afcu; return 0; }
write(ram,r[14]+4,r[0],4);
goto P_0c043afe;
P_0c043afe: /* original e700, guest PC 0x0c043afe */
if(!s->budget--) { s->failed_pc=0x0c043afeu; return 0; }
r[7]=0x00000000u;
goto P_0c043b00;
P_0c043b00: /* original d523, guest PC 0x0c043b00 */
if(!s->budget--) { s->failed_pc=0x0c043b00u; return 0; }
r[5]=read(ram,0x0c043b90u,4);
goto P_0c043b02;
P_0c043b02: /* original 9434, guest PC 0x0c043b02 */
if(!s->budget--) { s->failed_pc=0x0c043b02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043b6eu,2);
goto P_0c043b04;
P_0c043b04: /* original 4c0b, guest PC 0x0c043b04 */
if(!s->budget--) { s->failed_pc=0x0c043b04u; return 0; }
target=r[12];
r[16]=0x0c043b08u;
r[6]=read(ram,r[13]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043b08u) { target=s->pc; goto dispatch; }
goto P_0c043b08;
P_0c043b06: /* original 56d2, guest PC 0x0c043b06 */
if(!s->budget--) { s->failed_pc=0x0c043b06u; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c043b08;
P_0c043b08: /* original 1e02, guest PC 0x0c043b08 */
if(!s->budget--) { s->failed_pc=0x0c043b08u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c043b0a;
P_0c043b0a: /* original e700, guest PC 0x0c043b0a */
if(!s->budget--) { s->failed_pc=0x0c043b0au; return 0; }
r[7]=0x00000000u;
goto P_0c043b0c;
P_0c043b0c: /* original d521, guest PC 0x0c043b0c */
if(!s->budget--) { s->failed_pc=0x0c043b0cu; return 0; }
r[5]=read(ram,0x0c043b94u,4);
goto P_0c043b0e;
P_0c043b0e: /* original 942f, guest PC 0x0c043b0e */
if(!s->budget--) { s->failed_pc=0x0c043b0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043b70u,2);
goto P_0c043b10;
P_0c043b10: /* original 4c0b, guest PC 0x0c043b10 */
if(!s->budget--) { s->failed_pc=0x0c043b10u; return 0; }
target=r[12];
r[16]=0x0c043b14u;
r[6]=read(ram,r[13]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043b14u) { target=s->pc; goto dispatch; }
goto P_0c043b14;
P_0c043b12: /* original 56d3, guest PC 0x0c043b12 */
if(!s->budget--) { s->failed_pc=0x0c043b12u; return 0; }
r[6]=read(ram,r[13]+12,4);
goto P_0c043b14;
P_0c043b14: /* original 1e03, guest PC 0x0c043b14 */
if(!s->budget--) { s->failed_pc=0x0c043b14u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c043b16;
P_0c043b16: /* original e200, guest PC 0x0c043b16 */
if(!s->budget--) { s->failed_pc=0x0c043b16u; return 0; }
r[2]=0x00000000u;
goto P_0c043b18;
P_0c043b18: /* original d31f, guest PC 0x0c043b18 */
if(!s->budget--) { s->failed_pc=0x0c043b18u; return 0; }
r[3]=read(ram,0x0c043b98u,4);
goto P_0c043b1a;
P_0c043b1a: /* original 6523, guest PC 0x0c043b1a */
if(!s->budget--) { s->failed_pc=0x0c043b1au; return 0; }
r[5]=r[2];
goto P_0c043b1c;
P_0c043b1c: /* original 2322, guest PC 0x0c043b1c */
if(!s->budget--) { s->failed_pc=0x0c043b1cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c043b1e;
P_0c043b1e: /* original d01f, guest PC 0x0c043b1e */
if(!s->budget--) { s->failed_pc=0x0c043b1eu; return 0; }
r[0]=read(ram,0x0c043b9cu,4);
goto P_0c043b20;
P_0c043b20: /* original 2022, guest PC 0x0c043b20 */
if(!s->budget--) { s->failed_pc=0x0c043b20u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c043b22;
P_0c043b22: /* original de1f, guest PC 0x0c043b22 */
if(!s->budget--) { s->failed_pc=0x0c043b22u; return 0; }
r[14]=read(ram,0x0c043ba0u,4);
goto P_0c043b24;
P_0c043b24: /* original d41f, guest PC 0x0c043b24 */
if(!s->budget--) { s->failed_pc=0x0c043b24u; return 0; }
r[4]=read(ram,0x0c043ba4u,4);
goto P_0c043b26;
P_0c043b26: /* original 4e0b, guest PC 0x0c043b26 */
if(!s->budget--) { s->failed_pc=0x0c043b26u; return 0; }
target=r[14];
r[16]=0x0c043b2au;
r[6]=0x00000038u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043b2au) { target=s->pc; goto dispatch; }
goto P_0c043b2a;
P_0c043b28: /* original e638, guest PC 0x0c043b28 */
if(!s->budget--) { s->failed_pc=0x0c043b28u; return 0; }
r[6]=0x00000038u;
goto P_0c043b2a;
P_0c043b2a: /* original d412, guest PC 0x0c043b2a */
if(!s->budget--) { s->failed_pc=0x0c043b2au; return 0; }
r[4]=read(ram,0x0c043b74u,4);
goto P_0c043b2c;
P_0c043b2c: /* original 9621, guest PC 0x0c043b2c */
if(!s->budget--) { s->failed_pc=0x0c043b2cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043b72u,2);
goto P_0c043b2e;
P_0c043b2e: /* original 4e0b, guest PC 0x0c043b2e */
if(!s->budget--) { s->failed_pc=0x0c043b2eu; return 0; }
target=r[14];
r[16]=0x0c043b32u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043b32u) { target=s->pc; goto dispatch; }
goto P_0c043b32;
P_0c043b30: /* original e500, guest PC 0x0c043b30 */
if(!s->budget--) { s->failed_pc=0x0c043b30u; return 0; }
r[5]=0x00000000u;
goto P_0c043b32;
P_0c043b32: /* original d41d, guest PC 0x0c043b32 */
if(!s->budget--) { s->failed_pc=0x0c043b32u; return 0; }
r[4]=read(ram,0x0c043ba8u,4);
goto P_0c043b34;
P_0c043b34: /* original 961d, guest PC 0x0c043b34 */
if(!s->budget--) { s->failed_pc=0x0c043b34u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043b72u,2);
goto P_0c043b36;
P_0c043b36: /* original 4e0b, guest PC 0x0c043b36 */
if(!s->budget--) { s->failed_pc=0x0c043b36u; return 0; }
target=r[14];
r[16]=0x0c043b3au;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043b3au) { target=s->pc; goto dispatch; }
goto P_0c043b3a;
P_0c043b38: /* original e500, guest PC 0x0c043b38 */
if(!s->budget--) { s->failed_pc=0x0c043b38u; return 0; }
r[5]=0x00000000u;
goto P_0c043b3a;
P_0c043b3a: /* original d71c, guest PC 0x0c043b3a */
if(!s->budget--) { s->failed_pc=0x0c043b3au; return 0; }
r[7]=read(ram,0x0c043bacu,4);
goto P_0c043b3c;
P_0c043b3c: /* original d31c, guest PC 0x0c043b3c */
if(!s->budget--) { s->failed_pc=0x0c043b3cu; return 0; }
r[3]=read(ram,0x0c043bb0u,4);
goto P_0c043b3e;
P_0c043b3e: /* original 66f2, guest PC 0x0c043b3e */
if(!s->budget--) { s->failed_pc=0x0c043b3eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c043b40;
P_0c043b40: /* original 6573, guest PC 0x0c043b40 */
if(!s->budget--) { s->failed_pc=0x0c043b40u; return 0; }
r[5]=r[7];
goto P_0c043b42;
P_0c043b42: /* original 430b, guest PC 0x0c043b42 */
if(!s->budget--) { s->failed_pc=0x0c043b42u; return 0; }
target=r[3];
r[16]=0x0c043b46u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043b46u) { target=s->pc; goto dispatch; }
goto P_0c043b46;
P_0c043b44: /* original 54f1, guest PC 0x0c043b44 */
if(!s->budget--) { s->failed_pc=0x0c043b44u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c043b46;
P_0c043b46: /* original bf99, guest PC 0x0c043b46 */
if(!s->budget--) { s->failed_pc=0x0c043b46u; return 0; }
target=0x0c043a7cu; r[16]=0x0c043b4au;
write(ram,r[15],r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043b4au) { target=s->pc; goto dispatch; }
goto P_0c043b4a;
P_0c043b48: /* original 2f02, guest PC 0x0c043b48 */
if(!s->budget--) { s->failed_pc=0x0c043b48u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c043b4a;
P_0c043b4a: /* original 50f2, guest PC 0x0c043b4a */
if(!s->budget--) { s->failed_pc=0x0c043b4au; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c043b4c;
P_0c043b4c: /* original 0202, guest PC 0x0c043b4c */
if(!s->budget--) { s->failed_pc=0x0c043b4cu; return 0; }
r[2]=r[17];
goto P_0c043b4e;
P_0c043b4e: /* original 930c, guest PC 0x0c043b4e */
if(!s->budget--) { s->failed_pc=0x0c043b4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043b6au,2);
goto P_0c043b50;
P_0c043b50: /* original c90f, guest PC 0x0c043b50 */
if(!s->budget--) { s->failed_pc=0x0c043b50u; return 0; }
r[0]&=15u;
goto P_0c043b52;
P_0c043b52: /* original 4008, guest PC 0x0c043b52 */
if(!s->budget--) { s->failed_pc=0x0c043b52u; return 0; }
r[0]<<=2;
goto P_0c043b54;
P_0c043b54: /* original 2239, guest PC 0x0c043b54 */
if(!s->budget--) { s->failed_pc=0x0c043b54u; return 0; }
r[2]&=r[3];
goto P_0c043b56;
P_0c043b56: /* original 4008, guest PC 0x0c043b56 */
if(!s->budget--) { s->failed_pc=0x0c043b56u; return 0; }
r[0]<<=2;
goto P_0c043b58;
P_0c043b58: /* original 202b, guest PC 0x0c043b58 */
if(!s->budget--) { s->failed_pc=0x0c043b58u; return 0; }
r[0]|=r[2];
goto P_0c043b5a;
P_0c043b5a: /* original 400e, guest PC 0x0c043b5a */
if(!s->budget--) { s->failed_pc=0x0c043b5au; return 0; }
r[17]=r[0];
goto P_0c043b5c;
P_0c043b5c: /* original 60f2, guest PC 0x0c043b5c */
if(!s->budget--) { s->failed_pc=0x0c043b5cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c043b5e;
P_0c043b5e: /* original 7f0c, guest PC 0x0c043b5e */
if(!s->budget--) { s->failed_pc=0x0c043b5eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c043b60;
P_0c043b60: /* original 4f26, guest PC 0x0c043b60 */
if(!s->budget--) { s->failed_pc=0x0c043b60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043b62;
P_0c043b62: /* original 6cf6, guest PC 0x0c043b62 */
if(!s->budget--) { s->failed_pc=0x0c043b62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043b64;
P_0c043b64: /* original 6df6, guest PC 0x0c043b64 */
if(!s->budget--) { s->failed_pc=0x0c043b64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043b66;
P_0c043b66: /* original 000b, guest PC 0x0c043b66 */
if(!s->budget--) { s->failed_pc=0x0c043b66u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043b68: /* original 6ef6, guest PC 0x0c043b68 */
if(!s->budget--) { s->failed_pc=0x0c043b68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c043b6au,s,ram);
P_0c044a74: /* original 2fe6, guest PC 0x0c044a74 */
if(!s->budget--) { s->failed_pc=0x0c044a74u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c044a76;
P_0c044a76: /* original 2fd6, guest PC 0x0c044a76 */
if(!s->budget--) { s->failed_pc=0x0c044a76u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c044a78;
P_0c044a78: /* original ed00, guest PC 0x0c044a78 */
if(!s->budget--) { s->failed_pc=0x0c044a78u; return 0; }
r[13]=0x00000000u;
goto P_0c044a7a;
P_0c044a7a: /* original 2fc6, guest PC 0x0c044a7a */
if(!s->budget--) { s->failed_pc=0x0c044a7au; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c044a7c;
P_0c044a7c: /* original 2fb6, guest PC 0x0c044a7c */
if(!s->budget--) { s->failed_pc=0x0c044a7cu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c044a7e;
P_0c044a7e: /* original de65, guest PC 0x0c044a7e */
if(!s->budget--) { s->failed_pc=0x0c044a7eu; return 0; }
r[14]=read(ram,0x0c044c14u,4);
goto P_0c044a80;
P_0c044a80: /* original 90b3, guest PC 0x0c044a80 */
if(!s->budget--) { s->failed_pc=0x0c044a80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044beau,2);
goto P_0c044a82;
P_0c044a82: /* original 63e2, guest PC 0x0c044a82 */
if(!s->budget--) { s->failed_pc=0x0c044a82u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
return vf3_matrix_family(0x0c044a84u,s,ram);
P_0c04596c: /* original 4f22, guest PC 0x0c04596c */
if(!s->budget--) { s->failed_pc=0x0c04596cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04596e;
P_0c04596e: /* original 6e43, guest PC 0x0c04596e */
if(!s->budget--) { s->failed_pc=0x0c04596eu; return 0; }
r[14]=r[4];
goto P_0c045970;
P_0c045970: /* original b2c0, guest PC 0x0c045970 */
if(!s->budget--) { s->failed_pc=0x0c045970u; return 0; }
target=0x0c045ef4u; r[16]=0x0c045974u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045974u) { target=s->pc; goto dispatch; }
goto P_0c045974;
P_0c045972: /* original e500, guest PC 0x0c045972 */
if(!s->budget--) { s->failed_pc=0x0c045972u; return 0; }
r[5]=0x00000000u;
goto P_0c045974;
P_0c045974: /* original 62e3, guest PC 0x0c045974 */
if(!s->budget--) { s->failed_pc=0x0c045974u; return 0; }
r[2]=r[14];
goto P_0c045976;
P_0c045976: /* original e46e, guest PC 0x0c045976 */
if(!s->budget--) { s->failed_pc=0x0c045976u; return 0; }
r[4]=0x0000006eu;
goto P_0c045978;
P_0c045978: /* original e015, guest PC 0x0c045978 */
if(!s->budget--) { s->failed_pc=0x0c045978u; return 0; }
r[0]=0x00000015u;
goto P_0c04597a;
P_0c04597a: /* original 7214, guest PC 0x0c04597a */
if(!s->budget--) { s->failed_pc=0x0c04597au; return 0; }
r[2]+=0x00000014u;
goto P_0c04597c;
P_0c04597c: /* original e328, guest PC 0x0c04597c */
if(!s->budget--) { s->failed_pc=0x0c04597cu; return 0; }
r[3]=0x00000028u;
goto P_0c04597e;
P_0c04597e: /* original 2230, guest PC 0x0c04597e */
if(!s->budget--) { s->failed_pc=0x0c04597eu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c045980;
P_0c045980: /* original e36f, guest PC 0x0c045980 */
if(!s->budget--) { s->failed_pc=0x0c045980u; return 0; }
r[3]=0x0000006fu;
goto P_0c045982;
P_0c045982: /* original 0e44, guest PC 0x0c045982 */
if(!s->budget--) { s->failed_pc=0x0c045982u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c045984;
P_0c045984: /* original e016, guest PC 0x0c045984 */
if(!s->budget--) { s->failed_pc=0x0c045984u; return 0; }
r[0]=0x00000016u;
goto P_0c045986;
P_0c045986: /* original 0e34, guest PC 0x0c045986 */
if(!s->budget--) { s->failed_pc=0x0c045986u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c045988;
P_0c045988: /* original e017, guest PC 0x0c045988 */
if(!s->budget--) { s->failed_pc=0x0c045988u; return 0; }
r[0]=0x00000017u;
goto P_0c04598a;
P_0c04598a: /* original 0e44, guest PC 0x0c04598a */
if(!s->budget--) { s->failed_pc=0x0c04598au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c04598c;
P_0c04598c: /* original e018, guest PC 0x0c04598c */
if(!s->budget--) { s->failed_pc=0x0c04598cu; return 0; }
r[0]=0x00000018u;
goto P_0c04598e;
P_0c04598e: /* original e365, guest PC 0x0c04598e */
if(!s->budget--) { s->failed_pc=0x0c04598eu; return 0; }
r[3]=0x00000065u;
goto P_0c045990;
P_0c045990: /* original 64e3, guest PC 0x0c045990 */
if(!s->budget--) { s->failed_pc=0x0c045990u; return 0; }
r[4]=r[14];
goto P_0c045992;
P_0c045992: /* original 0e34, guest PC 0x0c045992 */
if(!s->budget--) { s->failed_pc=0x0c045992u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c045994;
P_0c045994: /* original e019, guest PC 0x0c045994 */
if(!s->budget--) { s->failed_pc=0x0c045994u; return 0; }
r[0]=0x00000019u;
goto P_0c045996;
P_0c045996: /* original e229, guest PC 0x0c045996 */
if(!s->budget--) { s->failed_pc=0x0c045996u; return 0; }
r[2]=0x00000029u;
goto P_0c045998;
P_0c045998: /* original e61f, guest PC 0x0c045998 */
if(!s->budget--) { s->failed_pc=0x0c045998u; return 0; }
r[6]=0x0000001fu;
goto P_0c04599a;
P_0c04599a: /* original 0e24, guest PC 0x0c04599a */
if(!s->budget--) { s->failed_pc=0x0c04599au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c04599c;
P_0c04599c: /* original 741a, guest PC 0x0c04599c */
if(!s->budget--) { s->failed_pc=0x0c04599cu; return 0; }
r[4]+=0x0000001au;
goto P_0c04599e;
P_0c04599e: /* original e506, guest PC 0x0c04599e */
if(!s->budget--) { s->failed_pc=0x0c04599eu; return 0; }
r[5]=0x00000006u;
goto P_0c0459a0;
P_0c0459a0: /* original e720, guest PC 0x0c0459a0 */
if(!s->budget--) { s->failed_pc=0x0c0459a0u; return 0; }
r[7]=0x00000020u;
goto P_0c0459a2;
P_0c0459a2: /* original 7501, guest PC 0x0c0459a2 */
if(!s->budget--) { s->failed_pc=0x0c0459a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0459a4;
P_0c0459a4: /* original 2470, guest PC 0x0c0459a4 */
if(!s->budget--) { s->failed_pc=0x0c0459a4u; return 0; }
write(ram,r[4],r[7],1);
goto P_0c0459a6;
P_0c0459a6: /* original 3563, guest PC 0x0c0459a6 */
if(!s->budget--) { s->failed_pc=0x0c0459a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0459a8;
P_0c0459a8: /* original 8ffb, guest PC 0x0c0459a8 */
if(!s->budget--) { s->failed_pc=0x0c0459a8u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c0459a2; }
goto P_0c0459ac;
P_0c0459aa: /* original 7401, guest PC 0x0c0459aa */
if(!s->budget--) { s->failed_pc=0x0c0459aau; return 0; }
r[4]+=0x00000001u;
goto P_0c0459ac;
P_0c0459ac: /* original 4f26, guest PC 0x0c0459ac */
if(!s->budget--) { s->failed_pc=0x0c0459acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0459ae;
P_0c0459ae: /* original e033, guest PC 0x0c0459ae */
if(!s->budget--) { s->failed_pc=0x0c0459aeu; return 0; }
r[0]=0x00000033u;
goto P_0c0459b0;
P_0c0459b0: /* original e200, guest PC 0x0c0459b0 */
if(!s->budget--) { s->failed_pc=0x0c0459b0u; return 0; }
r[2]=0x00000000u;
goto P_0c0459b2;
P_0c0459b2: /* original 0e24, guest PC 0x0c0459b2 */
if(!s->budget--) { s->failed_pc=0x0c0459b2u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0459b4;
P_0c0459b4: /* original 6023, guest PC 0x0c0459b4 */
if(!s->budget--) { s->failed_pc=0x0c0459b4u; return 0; }
r[0]=r[2];
goto P_0c0459b6;
P_0c0459b6: /* original 000b, guest PC 0x0c0459b6 */
if(!s->budget--) { s->failed_pc=0x0c0459b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0459b8: /* original 6ef6, guest PC 0x0c0459b8 */
if(!s->budget--) { s->failed_pc=0x0c0459b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0459bau,s,ram);
P_0c045f34: /* original d439, guest PC 0x0c045f34 */
if(!s->budget--) { s->failed_pc=0x0c045f34u; return 0; }
r[4]=read(ram,0x0c04601cu,4);
goto P_0c045f36;
P_0c045f36: /* original e500, guest PC 0x0c045f36 */
if(!s->budget--) { s->failed_pc=0x0c045f36u; return 0; }
r[5]=0x00000000u;
goto P_0c045f38;
P_0c045f38: /* original e70d, guest PC 0x0c045f38 */
if(!s->budget--) { s->failed_pc=0x0c045f38u; return 0; }
r[7]=0x0000000du;
goto P_0c045f3a;
P_0c045f3a: /* original 6653, guest PC 0x0c045f3a */
if(!s->budget--) { s->failed_pc=0x0c045f3au; return 0; }
r[6]=r[5];
goto P_0c045f3c;
P_0c045f3c: /* original 7601, guest PC 0x0c045f3c */
if(!s->budget--) { s->failed_pc=0x0c045f3cu; return 0; }
r[6]+=0x00000001u;
goto P_0c045f3e;
P_0c045f3e: /* original 2452, guest PC 0x0c045f3e */
if(!s->budget--) { s->failed_pc=0x0c045f3eu; return 0; }
write(ram,r[4],r[5],4);
goto P_0c045f40;
P_0c045f40: /* original 3673, guest PC 0x0c045f40 */
if(!s->budget--) { s->failed_pc=0x0c045f40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c045f42;
P_0c045f42: /* original 8ffb, guest PC 0x0c045f42 */
if(!s->budget--) { s->failed_pc=0x0c045f42u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c045f3c; }
goto P_0c045f46;
P_0c045f44: /* original 7404, guest PC 0x0c045f44 */
if(!s->budget--) { s->failed_pc=0x0c045f44u; return 0; }
r[4]+=0x00000004u;
goto P_0c045f46;
P_0c045f46: /* original d237, guest PC 0x0c045f46 */
if(!s->budget--) { s->failed_pc=0x0c045f46u; return 0; }
r[2]=read(ram,0x0c046024u,4);
goto P_0c045f48;
P_0c045f48: /* original d435, guest PC 0x0c045f48 */
if(!s->budget--) { s->failed_pc=0x0c045f48u; return 0; }
r[4]=read(ram,0x0c046020u,4);
goto P_0c045f4a;
P_0c045f4a: /* original 2242, guest PC 0x0c045f4a */
if(!s->budget--) { s->failed_pc=0x0c045f4au; return 0; }
write(ram,r[2],r[4],4);
goto P_0c045f4c;
P_0c045f4c: /* original 9664, guest PC 0x0c045f4c */
if(!s->budget--) { s->failed_pc=0x0c045f4cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c046018u,2);
goto P_0c045f4e;
P_0c045f4e: /* original 6343, guest PC 0x0c045f4e */
if(!s->budget--) { s->failed_pc=0x0c045f4eu; return 0; }
r[3]=r[4];
goto P_0c045f50;
P_0c045f50: /* original 7310, guest PC 0x0c045f50 */
if(!s->budget--) { s->failed_pc=0x0c045f50u; return 0; }
r[3]+=0x00000010u;
goto P_0c045f52;
P_0c045f52: /* original 4610, guest PC 0x0c045f52 */
if(!s->budget--) { s->failed_pc=0x0c045f52u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c045f54;
P_0c045f54: /* original 1431, guest PC 0x0c045f54 */
if(!s->budget--) { s->failed_pc=0x0c045f54u; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c045f56;
P_0c045f56: /* original 8ffa, guest PC 0x0c045f56 */
if(!s->budget--) { s->failed_pc=0x0c045f56u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000010u;
if(!cond) { goto P_0c045f4e; }
goto P_0c045f5a;
P_0c045f58: /* original 7410, guest PC 0x0c045f58 */
if(!s->budget--) { s->failed_pc=0x0c045f58u; return 0; }
r[4]+=0x00000010u;
goto P_0c045f5a;
P_0c045f5a: /* original 000b, guest PC 0x0c045f5a */
if(!s->budget--) { s->failed_pc=0x0c045f5au; return 0; }
target=r[16];
write(ram,r[4]+4,r[5],4);
s->pc=target; return ram->oob==0;
P_0c045f5c: /* original 1451, guest PC 0x0c045f5c */
if(!s->budget--) { s->failed_pc=0x0c045f5cu; return 0; }
write(ram,r[4]+4,r[5],4);
return vf3_matrix_family(0x0c045f5eu,s,ram);
P_0c045f7e: /* original d52a, guest PC 0x0c045f7e */
if(!s->budget--) { s->failed_pc=0x0c045f7eu; return 0; }
r[5]=read(ram,0x0c046028u,4);
goto P_0c045f80;
P_0c045f80: /* original e70d, guest PC 0x0c045f80 */
if(!s->budget--) { s->failed_pc=0x0c045f80u; return 0; }
r[7]=0x0000000du;
goto P_0c045f82;
P_0c045f82: /* original e600, guest PC 0x0c045f82 */
if(!s->budget--) { s->failed_pc=0x0c045f82u; return 0; }
r[6]=0x00000000u;
goto P_0c045f84;
P_0c045f84: /* original 6351, guest PC 0x0c045f84 */
if(!s->budget--) { s->failed_pc=0x0c045f84u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[3]=tmp;
goto P_0c045f86;
P_0c045f86: /* original 624f, guest PC 0x0c045f86 */
if(!s->budget--) { s->failed_pc=0x0c045f86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c045f88;
P_0c045f88: /* original 3320, guest PC 0x0c045f88 */
if(!s->budget--) { s->failed_pc=0x0c045f88u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c045f8a;
P_0c045f8a: /* original 8b01, guest PC 0x0c045f8a */
if(!s->budget--) { s->failed_pc=0x0c045f8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045f90; }
goto P_0c045f8c;
P_0c045f8c: /* original 000b, guest PC 0x0c045f8c */
if(!s->budget--) { s->failed_pc=0x0c045f8cu; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c045f8e: /* original 6053, guest PC 0x0c045f8e */
if(!s->budget--) { s->failed_pc=0x0c045f8eu; return 0; }
r[0]=r[5];
goto P_0c045f90;
P_0c045f90: /* original 7601, guest PC 0x0c045f90 */
if(!s->budget--) { s->failed_pc=0x0c045f90u; return 0; }
r[6]+=0x00000001u;
goto P_0c045f92;
P_0c045f92: /* original 3672, guest PC 0x0c045f92 */
if(!s->budget--) { s->failed_pc=0x0c045f92u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c045f94;
P_0c045f94: /* original 8ff6, guest PC 0x0c045f94 */
if(!s->budget--) { s->failed_pc=0x0c045f94u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000008u;
if(!cond) { goto P_0c045f84; }
goto P_0c045f98;
P_0c045f96: /* original 7508, guest PC 0x0c045f96 */
if(!s->budget--) { s->failed_pc=0x0c045f96u; return 0; }
r[5]+=0x00000008u;
goto P_0c045f98;
P_0c045f98: /* original e000, guest PC 0x0c045f98 */
if(!s->budget--) { s->failed_pc=0x0c045f98u; return 0; }
r[0]=0x00000000u;
goto P_0c045f9a;
P_0c045f9a: /* original 000b, guest PC 0x0c045f9a */
if(!s->budget--) { s->failed_pc=0x0c045f9au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045f9c: /* original 0009, guest PC 0x0c045f9c */
if(!s->budget--) { s->failed_pc=0x0c045f9cu; return 0; }
goto P_0c045f9e;
P_0c045f9e: /* original 2fe6, guest PC 0x0c045f9e */
if(!s->budget--) { s->failed_pc=0x0c045f9eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c045fa0;
P_0c045fa0: /* original d320, guest PC 0x0c045fa0 */
if(!s->budget--) { s->failed_pc=0x0c045fa0u; return 0; }
r[3]=read(ram,0x0c046024u,4);
goto P_0c045fa2;
P_0c045fa2: /* original 6e32, guest PC 0x0c045fa2 */
if(!s->budget--) { s->failed_pc=0x0c045fa2u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c045fa4;
P_0c045fa4: /* original 2ee8, guest PC 0x0c045fa4 */
if(!s->budget--) { s->failed_pc=0x0c045fa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c045fa6;
P_0c045fa6: /* original 8b02, guest PC 0x0c045fa6 */
if(!s->budget--) { s->failed_pc=0x0c045fa6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045fae; }
goto P_0c045fa8;
P_0c045fa8: /* original e000, guest PC 0x0c045fa8 */
if(!s->budget--) { s->failed_pc=0x0c045fa8u; return 0; }
r[0]=0x00000000u;
goto P_0c045faa;
P_0c045faa: /* original 000b, guest PC 0x0c045faa */
if(!s->budget--) { s->failed_pc=0x0c045faau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045fac: /* original 6ef6, guest PC 0x0c045fac */
if(!s->budget--) { s->failed_pc=0x0c045facu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c045fae;
P_0c045fae: /* original d21d, guest PC 0x0c045fae */
if(!s->budget--) { s->failed_pc=0x0c045faeu; return 0; }
r[2]=read(ram,0x0c046024u,4);
goto P_0c045fb0;
P_0c045fb0: /* original 2668, guest PC 0x0c045fb0 */
if(!s->budget--) { s->failed_pc=0x0c045fb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c045fb2;
P_0c045fb2: /* original 53e1, guest PC 0x0c045fb2 */
if(!s->budget--) { s->failed_pc=0x0c045fb2u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c045fb4;
P_0c045fb4: /* original 8f01, guest PC 0x0c045fb4 */
if(!s->budget--) { s->failed_pc=0x0c045fb4u; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[3],4);
if(!cond) { goto P_0c045fba; }
goto P_0c045fb8;
P_0c045fb6: /* original 2232, guest PC 0x0c045fb6 */
if(!s->budget--) { s->failed_pc=0x0c045fb6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c045fb8;
P_0c045fb8: /* original e601, guest PC 0x0c045fb8 */
if(!s->budget--) { s->failed_pc=0x0c045fb8u; return 0; }
r[6]=0x00000001u;
goto P_0c045fba;
P_0c045fba: /* original d31c, guest PC 0x0c045fba */
if(!s->budget--) { s->failed_pc=0x0c045fbau; return 0; }
r[3]=read(ram,0x0c04602cu,4);
goto P_0c045fbc;
P_0c045fbc: /* original 3632, guest PC 0x0c045fbc */
if(!s->budget--) { s->failed_pc=0x0c045fbcu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[3])!=0);
goto P_0c045fbe;
P_0c045fbe: /* original 8f01, guest PC 0x0c045fbe */
if(!s->budget--) { s->failed_pc=0x0c045fbeu; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[5],4);
if(!cond) { goto P_0c045fc4; }
goto P_0c045fc2;
P_0c045fc0: /* original 2e52, guest PC 0x0c045fc0 */
if(!s->budget--) { s->failed_pc=0x0c045fc0u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c045fc2;
P_0c045fc2: /* original d61b, guest PC 0x0c045fc2 */
if(!s->budget--) { s->failed_pc=0x0c045fc2u; return 0; }
r[6]=read(ram,0x0c046030u,4);
goto P_0c045fc4;
P_0c045fc4: /* original e300, guest PC 0x0c045fc4 */
if(!s->budget--) { s->failed_pc=0x0c045fc4u; return 0; }
r[3]=0x00000000u;
goto P_0c045fc6;
P_0c045fc6: /* original 6243, guest PC 0x0c045fc6 */
if(!s->budget--) { s->failed_pc=0x0c045fc6u; return 0; }
r[2]=r[4];
goto P_0c045fc8;
P_0c045fc8: /* original 1e31, guest PC 0x0c045fc8 */
if(!s->budget--) { s->failed_pc=0x0c045fc8u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c045fca;
P_0c045fca: /* original 4228, guest PC 0x0c045fca */
if(!s->budget--) { s->failed_pc=0x0c045fcau; return 0; }
r[2]<<=16;
goto P_0c045fcc;
P_0c045fcc: /* original 1e72, guest PC 0x0c045fcc */
if(!s->budget--) { s->failed_pc=0x0c045fccu; return 0; }
write(ram,r[14]+8,r[7],4);
goto P_0c045fce;
P_0c045fce: /* original 6743, guest PC 0x0c045fce */
if(!s->budget--) { s->failed_pc=0x0c045fceu; return 0; }
r[7]=r[4];
goto P_0c045fd0;
P_0c045fd0: /* original 4708, guest PC 0x0c045fd0 */
if(!s->budget--) { s->failed_pc=0x0c045fd0u; return 0; }
r[7]<<=2;
goto P_0c045fd2;
P_0c045fd2: /* original 226b, guest PC 0x0c045fd2 */
if(!s->budget--) { s->failed_pc=0x0c045fd2u; return 0; }
r[2]|=r[6];
goto P_0c045fd4;
P_0c045fd4: /* original 1e23, guest PC 0x0c045fd4 */
if(!s->budget--) { s->failed_pc=0x0c045fd4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c045fd6;
P_0c045fd6: /* original d311, guest PC 0x0c045fd6 */
if(!s->budget--) { s->failed_pc=0x0c045fd6u; return 0; }
r[3]=read(ram,0x0c04601cu,4);
goto P_0c045fd8;
P_0c045fd8: /* original 373c, guest PC 0x0c045fd8 */
if(!s->budget--) { s->failed_pc=0x0c045fd8u; return 0; }
r[7]+=r[3];
goto P_0c045fda;
P_0c045fda: /* original 6572, guest PC 0x0c045fda */
if(!s->budget--) { s->failed_pc=0x0c045fdau; return 0; }
tmp=read(ram,r[7],4);
r[5]=tmp;
goto P_0c045fdc;
P_0c045fdc: /* original 2558, guest PC 0x0c045fdc */
if(!s->budget--) { s->failed_pc=0x0c045fdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c045fde;
P_0c045fde: /* original 8b02, guest PC 0x0c045fde */
if(!s->budget--) { s->failed_pc=0x0c045fdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045fe6; }
goto P_0c045fe0;
P_0c045fe0: /* original a00b, guest PC 0x0c045fe0 */
if(!s->budget--) { s->failed_pc=0x0c045fe0u; return 0; }
write(ram,r[7],r[14],4);
goto P_0c045ffa;
P_0c045fe2: /* original 27e2, guest PC 0x0c045fe2 */
if(!s->budget--) { s->failed_pc=0x0c045fe2u; return 0; }
write(ram,r[7],r[14],4);
goto P_0c045fe4;
P_0c045fe4: /* original 5551, guest PC 0x0c045fe4 */
if(!s->budget--) { s->failed_pc=0x0c045fe4u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c045fe6;
P_0c045fe6: /* original 5353, guest PC 0x0c045fe6 */
if(!s->budget--) { s->failed_pc=0x0c045fe6u; return 0; }
r[3]=read(ram,r[5]+12,4);
goto P_0c045fe8;
P_0c045fe8: /* original 633d, guest PC 0x0c045fe8 */
if(!s->budget--) { s->failed_pc=0x0c045fe8u; return 0; }
r[3]=r[3]&65535u;
goto P_0c045fea;
P_0c045fea: /* original 3362, guest PC 0x0c045fea */
if(!s->budget--) { s->failed_pc=0x0c045feau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c045fec;
P_0c045fec: /* original 8902, guest PC 0x0c045fec */
if(!s->budget--) { s->failed_pc=0x0c045fecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045ff4; }
goto P_0c045fee;
P_0c045fee: /* original 5351, guest PC 0x0c045fee */
if(!s->budget--) { s->failed_pc=0x0c045feeu; return 0; }
r[3]=read(ram,r[5]+4,4);
goto P_0c045ff0;
P_0c045ff0: /* original 2338, guest PC 0x0c045ff0 */
if(!s->budget--) { s->failed_pc=0x0c045ff0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c045ff2;
P_0c045ff2: /* original 8bf7, guest PC 0x0c045ff2 */
if(!s->budget--) { s->failed_pc=0x0c045ff2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045fe4; }
goto P_0c045ff4;
P_0c045ff4: /* original 5351, guest PC 0x0c045ff4 */
if(!s->budget--) { s->failed_pc=0x0c045ff4u; return 0; }
r[3]=read(ram,r[5]+4,4);
goto P_0c045ff6;
P_0c045ff6: /* original 1e31, guest PC 0x0c045ff6 */
if(!s->budget--) { s->failed_pc=0x0c045ff6u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c045ff8;
P_0c045ff8: /* original 15e1, guest PC 0x0c045ff8 */
if(!s->budget--) { s->failed_pc=0x0c045ff8u; return 0; }
write(ram,r[5]+4,r[14],4);
goto P_0c045ffa;
P_0c045ffa: /* original 50e3, guest PC 0x0c045ffa */
if(!s->budget--) { s->failed_pc=0x0c045ffau; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c045ffc;
P_0c045ffc: /* original 000b, guest PC 0x0c045ffc */
if(!s->budget--) { s->failed_pc=0x0c045ffcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045ffe: /* original 6ef6, guest PC 0x0c045ffe */
if(!s->budget--) { s->failed_pc=0x0c045ffeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046000u,s,ram);
P_0c046180: /* original 0002, guest PC 0x0c046180 */
if(!s->budget--) { s->failed_pc=0x0c046180u; return 0; }
r[0]=r[17];
goto P_0c046182;
P_0c046182: /* original 4f22, guest PC 0x0c046182 */
if(!s->budget--) { s->failed_pc=0x0c046182u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046184;
P_0c046184: /* original 4009, guest PC 0x0c046184 */
if(!s->budget--) { s->failed_pc=0x0c046184u; return 0; }
r[0]>>=2;
goto P_0c046186;
P_0c046186: /* original 4009, guest PC 0x0c046186 */
if(!s->budget--) { s->failed_pc=0x0c046186u; return 0; }
r[0]>>=2;
goto P_0c046188;
P_0c046188: /* original c90f, guest PC 0x0c046188 */
if(!s->budget--) { s->failed_pc=0x0c046188u; return 0; }
r[0]&=15u;
goto P_0c04618a;
P_0c04618a: /* original 7ffc, guest PC 0x0c04618a */
if(!s->budget--) { s->failed_pc=0x0c04618au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04618c;
P_0c04618c: /* original 2f02, guest PC 0x0c04618c */
if(!s->budget--) { s->failed_pc=0x0c04618cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c04618e;
P_0c04618e: /* original 0002, guest PC 0x0c04618e */
if(!s->budget--) { s->failed_pc=0x0c04618eu; return 0; }
r[0]=r[17];
goto P_0c046190;
P_0c046190: /* original 9320, guest PC 0x0c046190 */
if(!s->budget--) { s->failed_pc=0x0c046190u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461d4u,2);
goto P_0c046192;
P_0c046192: /* original 2039, guest PC 0x0c046192 */
if(!s->budget--) { s->failed_pc=0x0c046192u; return 0; }
r[0]&=r[3];
goto P_0c046194;
P_0c046194: /* original cbe0, guest PC 0x0c046194 */
if(!s->budget--) { s->failed_pc=0x0c046194u; return 0; }
r[0]|=224u;
goto P_0c046196;
P_0c046196: /* original 400e, guest PC 0x0c046196 */
if(!s->budget--) { s->failed_pc=0x0c046196u; return 0; }
r[17]=r[0];
goto P_0c046198;
P_0c046198: /* original becc, guest PC 0x0c046198 */
if(!s->budget--) { s->failed_pc=0x0c046198u; return 0; }
target=0x0c045f34u; r[16]=0x0c04619cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04619cu) { target=s->pc; goto dispatch; }
goto P_0c04619c;
P_0c04619a: /* original 0009, guest PC 0x0c04619a */
if(!s->budget--) { s->failed_pc=0x0c04619au; return 0; }
goto P_0c04619c;
P_0c04619c: /* original d31b, guest PC 0x0c04619c */
if(!s->budget--) { s->failed_pc=0x0c04619cu; return 0; }
r[3]=read(ram,0x0c04620cu,4);
goto P_0c04619e;
P_0c04619e: /* original 941d, guest PC 0x0c04619e */
if(!s->budget--) { s->failed_pc=0x0c04619eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461dcu,2);
goto P_0c0461a0;
P_0c0461a0: /* original d519, guest PC 0x0c0461a0 */
if(!s->budget--) { s->failed_pc=0x0c0461a0u; return 0; }
r[5]=read(ram,0x0c046208u,4);
goto P_0c0461a2;
P_0c0461a2: /* original 430b, guest PC 0x0c0461a2 */
if(!s->budget--) { s->failed_pc=0x0c0461a2u; return 0; }
target=r[3];
r[16]=0x0c0461a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0461a6u) { target=s->pc; goto dispatch; }
goto P_0c0461a6;
P_0c0461a4: /* original 0009, guest PC 0x0c0461a4 */
if(!s->budget--) { s->failed_pc=0x0c0461a4u; return 0; }
goto P_0c0461a6;
P_0c0461a6: /* original d21b, guest PC 0x0c0461a6 */
if(!s->budget--) { s->failed_pc=0x0c0461a6u; return 0; }
r[2]=read(ram,0x0c046214u,4);
goto P_0c0461a8;
P_0c0461a8: /* original d419, guest PC 0x0c0461a8 */
if(!s->budget--) { s->failed_pc=0x0c0461a8u; return 0; }
r[4]=read(ram,0x0c046210u,4);
goto P_0c0461aa;
P_0c0461aa: /* original 420b, guest PC 0x0c0461aa */
if(!s->budget--) { s->failed_pc=0x0c0461aau; return 0; }
target=r[2];
r[16]=0x0c0461aeu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0461aeu) { target=s->pc; goto dispatch; }
goto P_0c0461ae;
P_0c0461ac: /* original e500, guest PC 0x0c0461ac */
if(!s->budget--) { s->failed_pc=0x0c0461acu; return 0; }
r[5]=0x00000000u;
goto P_0c0461ae;
P_0c0461ae: /* original 2008, guest PC 0x0c0461ae */
if(!s->budget--) { s->failed_pc=0x0c0461aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0461b0;
P_0c0461b0: /* original 8900, guest PC 0x0c0461b0 */
if(!s->budget--) { s->failed_pc=0x0c0461b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0461b4; }
goto P_0c0461b2;
P_0c0461b2: /* original c331, guest PC 0x0c0461b2 */
if(!s->budget--) { s->failed_pc=0x0c0461b2u; return 0; }
s->failed_pc=0x0c0461b2u; return 0;
goto P_0c0461b4;
P_0c0461b4: /* original d318, guest PC 0x0c0461b4 */
if(!s->budget--) { s->failed_pc=0x0c0461b4u; return 0; }
r[3]=read(ram,0x0c046218u,4);
goto P_0c0461b6;
P_0c0461b6: /* original e200, guest PC 0x0c0461b6 */
if(!s->budget--) { s->failed_pc=0x0c0461b6u; return 0; }
r[2]=0x00000000u;
goto P_0c0461b8;
P_0c0461b8: /* original 0102, guest PC 0x0c0461b8 */
if(!s->budget--) { s->failed_pc=0x0c0461b8u; return 0; }
r[1]=r[17];
goto P_0c0461ba;
P_0c0461ba: /* original 2322, guest PC 0x0c0461ba */
if(!s->budget--) { s->failed_pc=0x0c0461bau; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0461bc;
P_0c0461bc: /* original 60f2, guest PC 0x0c0461bc */
if(!s->budget--) { s->failed_pc=0x0c0461bcu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0461be;
P_0c0461be: /* original 9209, guest PC 0x0c0461be */
if(!s->budget--) { s->failed_pc=0x0c0461beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461d4u,2);
goto P_0c0461c0;
P_0c0461c0: /* original c90f, guest PC 0x0c0461c0 */
if(!s->budget--) { s->failed_pc=0x0c0461c0u; return 0; }
r[0]&=15u;
goto P_0c0461c2;
P_0c0461c2: /* original 4008, guest PC 0x0c0461c2 */
if(!s->budget--) { s->failed_pc=0x0c0461c2u; return 0; }
r[0]<<=2;
goto P_0c0461c4;
P_0c0461c4: /* original 2129, guest PC 0x0c0461c4 */
if(!s->budget--) { s->failed_pc=0x0c0461c4u; return 0; }
r[1]&=r[2];
goto P_0c0461c6;
P_0c0461c6: /* original 4008, guest PC 0x0c0461c6 */
if(!s->budget--) { s->failed_pc=0x0c0461c6u; return 0; }
r[0]<<=2;
goto P_0c0461c8;
P_0c0461c8: /* original 201b, guest PC 0x0c0461c8 */
if(!s->budget--) { s->failed_pc=0x0c0461c8u; return 0; }
r[0]|=r[1];
goto P_0c0461ca;
P_0c0461ca: /* original 400e, guest PC 0x0c0461ca */
if(!s->budget--) { s->failed_pc=0x0c0461cau; return 0; }
r[17]=r[0];
goto P_0c0461cc;
P_0c0461cc: /* original 7f04, guest PC 0x0c0461cc */
if(!s->budget--) { s->failed_pc=0x0c0461ccu; return 0; }
r[15]+=0x00000004u;
goto P_0c0461ce;
P_0c0461ce: /* original 4f26, guest PC 0x0c0461ce */
if(!s->budget--) { s->failed_pc=0x0c0461ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0461d0;
P_0c0461d0: /* original 000b, guest PC 0x0c0461d0 */
if(!s->budget--) { s->failed_pc=0x0c0461d0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0461d2: /* original 0009, guest PC 0x0c0461d2 */
if(!s->budget--) { s->failed_pc=0x0c0461d2u; return 0; }
return vf3_matrix_family(0x0c0461d4u,s,ram);
P_0c04621c: /* original 0002, guest PC 0x0c04621c */
if(!s->budget--) { s->failed_pc=0x0c04621cu; return 0; }
r[0]=r[17];
goto P_0c04621e;
P_0c04621e: /* original 2fe6, guest PC 0x0c04621e */
if(!s->budget--) { s->failed_pc=0x0c04621eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c046220;
P_0c046220: /* original 4f22, guest PC 0x0c046220 */
if(!s->budget--) { s->failed_pc=0x0c046220u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046222;
P_0c046222: /* original 4009, guest PC 0x0c046222 */
if(!s->budget--) { s->failed_pc=0x0c046222u; return 0; }
r[0]>>=2;
goto P_0c046224;
P_0c046224: /* original 4009, guest PC 0x0c046224 */
if(!s->budget--) { s->failed_pc=0x0c046224u; return 0; }
r[0]>>=2;
goto P_0c046226;
P_0c046226: /* original 7fec, guest PC 0x0c046226 */
if(!s->budget--) { s->failed_pc=0x0c046226u; return 0; }
r[15]+=0xffffffecu;
goto P_0c046228;
P_0c046228: /* original c90f, guest PC 0x0c046228 */
if(!s->budget--) { s->failed_pc=0x0c046228u; return 0; }
r[0]&=15u;
goto P_0c04622a;
P_0c04622a: /* original 2f41, guest PC 0x0c04622a */
if(!s->budget--) { s->failed_pc=0x0c04622au; return 0; }
write(ram,r[15],r[4],2);
goto P_0c04622c;
P_0c04622c: /* original 1f51, guest PC 0x0c04622c */
if(!s->budget--) { s->failed_pc=0x0c04622cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04622e;
P_0c04622e: /* original 1f63, guest PC 0x0c04622e */
if(!s->budget--) { s->failed_pc=0x0c04622eu; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c046230;
P_0c046230: /* original 1f72, guest PC 0x0c046230 */
if(!s->budget--) { s->failed_pc=0x0c046230u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c046232;
P_0c046232: /* original 1f04, guest PC 0x0c046232 */
if(!s->budget--) { s->failed_pc=0x0c046232u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c046234;
P_0c046234: /* original 0002, guest PC 0x0c046234 */
if(!s->budget--) { s->failed_pc=0x0c046234u; return 0; }
r[0]=r[17];
goto P_0c046236;
P_0c046236: /* original 9336, guest PC 0x0c046236 */
if(!s->budget--) { s->failed_pc=0x0c046236u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0462a6u,2);
goto P_0c046238;
P_0c046238: /* original 2039, guest PC 0x0c046238 */
if(!s->budget--) { s->failed_pc=0x0c046238u; return 0; }
r[0]&=r[3];
goto P_0c04623a;
P_0c04623a: /* original cbe0, guest PC 0x0c04623a */
if(!s->budget--) { s->failed_pc=0x0c04623au; return 0; }
r[0]|=224u;
goto P_0c04623c;
P_0c04623c: /* original 400e, guest PC 0x0c04623c */
if(!s->budget--) { s->failed_pc=0x0c04623cu; return 0; }
r[17]=r[0];
goto P_0c04623e;
P_0c04623e: /* original d41a, guest PC 0x0c04623e */
if(!s->budget--) { s->failed_pc=0x0c04623eu; return 0; }
r[4]=read(ram,0x0c0462a8u,4);
goto P_0c046240;
P_0c046240: /* original 6242, guest PC 0x0c046240 */
if(!s->budget--) { s->failed_pc=0x0c046240u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c046242;
P_0c046242: /* original 2228, guest PC 0x0c046242 */
if(!s->budget--) { s->failed_pc=0x0c046242u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c046244;
P_0c046244: /* original 8902, guest PC 0x0c046244 */
if(!s->budget--) { s->failed_pc=0x0c046244u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04624c; }
goto P_0c046246;
P_0c046246: /* original e300, guest PC 0x0c046246 */
if(!s->budget--) { s->failed_pc=0x0c046246u; return 0; }
r[3]=0x00000000u;
goto P_0c046248;
P_0c046248: /* original bf9a, guest PC 0x0c046248 */
if(!s->budget--) { s->failed_pc=0x0c046248u; return 0; }
target=0x0c046180u; r[16]=0x0c04624cu;
write(ram,r[4],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04624cu) { target=s->pc; goto dispatch; }
goto P_0c04624c;
P_0c04624a: /* original 2432, guest PC 0x0c04624a */
if(!s->budget--) { s->failed_pc=0x0c04624au; return 0; }
write(ram,r[4],r[3],4);
goto P_0c04624c;
P_0c04624c: /* original 51f1, guest PC 0x0c04624c */
if(!s->budget--) { s->failed_pc=0x0c04624cu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c04624e;
P_0c04624e: /* original 2118, guest PC 0x0c04624e */
if(!s->budget--) { s->failed_pc=0x0c04624eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c046250;
P_0c046250: /* original 8b04, guest PC 0x0c046250 */
if(!s->budget--) { s->failed_pc=0x0c046250u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c04625cu,s,ram); }
goto P_0c046252;
P_0c046252: /* original 7f14, guest PC 0x0c046252 */
if(!s->budget--) { s->failed_pc=0x0c046252u; return 0; }
r[15]+=0x00000014u;
goto P_0c046254;
P_0c046254: /* original 4f26, guest PC 0x0c046254 */
if(!s->budget--) { s->failed_pc=0x0c046254u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046256;
P_0c046256: /* original e000, guest PC 0x0c046256 */
if(!s->budget--) { s->failed_pc=0x0c046256u; return 0; }
r[0]=0x00000000u;
goto P_0c046258;
P_0c046258: /* original 000b, guest PC 0x0c046258 */
if(!s->budget--) { s->failed_pc=0x0c046258u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04625a: /* original 6ef6, guest PC 0x0c04625a */
if(!s->budget--) { s->failed_pc=0x0c04625au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04625cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
