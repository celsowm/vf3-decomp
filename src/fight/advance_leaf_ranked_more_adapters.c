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
int vf3_advance_leaf_ranked_more_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c03b450u: goto P_0c03b450;
case 0x0c03b452u: goto P_0c03b452;
case 0x0c03b454u: goto P_0c03b454;
case 0x0c03b456u: goto P_0c03b456;
case 0x0c03b458u: goto P_0c03b458;
case 0x0c03b45au: goto P_0c03b45a;
case 0x0c03b45cu: goto P_0c03b45c;
case 0x0c03b45eu: goto P_0c03b45e;
case 0x0c03b460u: goto P_0c03b460;
case 0x0c03b462u: goto P_0c03b462;
case 0x0c03b464u: goto P_0c03b464;
case 0x0c03b466u: goto P_0c03b466;
case 0x0c069624u: goto P_0c069624;
case 0x0c069626u: goto P_0c069626;
case 0x0c069628u: goto P_0c069628;
case 0x0c06962au: goto P_0c06962a;
case 0x0c06962cu: goto P_0c06962c;
case 0x0c06962eu: goto P_0c06962e;
case 0x0c069630u: goto P_0c069630;
case 0x0c069632u: goto P_0c069632;
case 0x0c069634u: goto P_0c069634;
case 0x0c069636u: goto P_0c069636;
case 0x0c069638u: goto P_0c069638;
case 0x0c06963au: goto P_0c06963a;
case 0x0c06963cu: goto P_0c06963c;
case 0x0c06963eu: goto P_0c06963e;
case 0x0c069640u: goto P_0c069640;
case 0x0c069642u: goto P_0c069642;
case 0x0c069644u: goto P_0c069644;
case 0x0c069646u: goto P_0c069646;
case 0x0c069648u: goto P_0c069648;
case 0x0c06964au: goto P_0c06964a;
case 0x0c06964cu: goto P_0c06964c;
case 0x0c06964eu: goto P_0c06964e;
case 0x0c069650u: goto P_0c069650;
case 0x0c069652u: goto P_0c069652;
case 0x0c069654u: goto P_0c069654;
case 0x0c069656u: goto P_0c069656;
case 0x0c069658u: goto P_0c069658;
case 0x0c06965au: goto P_0c06965a;
case 0x0c06965cu: goto P_0c06965c;
case 0x0c06965eu: goto P_0c06965e;
case 0x0c069660u: goto P_0c069660;
case 0x0c069662u: goto P_0c069662;
case 0x0c069664u: goto P_0c069664;
case 0x0c069666u: goto P_0c069666;
case 0x0c069668u: goto P_0c069668;
case 0x0c06966au: goto P_0c06966a;
case 0x0c06966cu: goto P_0c06966c;
case 0x0c06966eu: goto P_0c06966e;
case 0x0c069670u: goto P_0c069670;
case 0x0c069672u: goto P_0c069672;
case 0x0c069674u: goto P_0c069674;
case 0x0c069676u: goto P_0c069676;
case 0x0c069678u: goto P_0c069678;
case 0x0c06967au: goto P_0c06967a;
case 0x0c06967cu: goto P_0c06967c;
case 0x0c06967eu: goto P_0c06967e;
case 0x0c069680u: goto P_0c069680;
case 0x0c069682u: goto P_0c069682;
case 0x0c069684u: goto P_0c069684;
case 0x0c069686u: goto P_0c069686;
case 0x0c069688u: goto P_0c069688;
case 0x0c06968au: goto P_0c06968a;
case 0x0c06968cu: goto P_0c06968c;
case 0x0c06968eu: goto P_0c06968e;
case 0x0c069690u: goto P_0c069690;
case 0x0c069692u: goto P_0c069692;
case 0x0c069694u: goto P_0c069694;
case 0x0c069696u: goto P_0c069696;
case 0x0c069698u: goto P_0c069698;
case 0x0c06969au: goto P_0c06969a;
case 0x0c06969cu: goto P_0c06969c;
case 0x0c06e8c4u: goto P_0c06e8c4;
case 0x0c06e8c6u: goto P_0c06e8c6;
case 0x0c06e8c8u: goto P_0c06e8c8;
case 0x0c06e8cau: goto P_0c06e8ca;
case 0x0c06e8ccu: goto P_0c06e8cc;
case 0x0c06e8ceu: goto P_0c06e8ce;
case 0x0c06e8d0u: goto P_0c06e8d0;
case 0x0c06e8d2u: goto P_0c06e8d2;
case 0x0c06e8d4u: goto P_0c06e8d4;
case 0x0c06e8d6u: goto P_0c06e8d6;
case 0x0c06e8d8u: goto P_0c06e8d8;
case 0x0c06e8dau: goto P_0c06e8da;
case 0x0c06e8dcu: goto P_0c06e8dc;
case 0x0c06e8deu: goto P_0c06e8de;
case 0x0c06e8e0u: goto P_0c06e8e0;
case 0x0c06e8e2u: goto P_0c06e8e2;
case 0x0c06e8e4u: goto P_0c06e8e4;
case 0x0c06e8e6u: goto P_0c06e8e6;
case 0x0c06e8e8u: goto P_0c06e8e8;
case 0x0c06e8eau: goto P_0c06e8ea;
case 0x0c06e8ecu: goto P_0c06e8ec;
case 0x0c06e8eeu: goto P_0c06e8ee;
case 0x0c06e8f0u: goto P_0c06e8f0;
case 0x0c06e8f2u: goto P_0c06e8f2;
case 0x0c06e8f4u: goto P_0c06e8f4;
case 0x0c06e8f6u: goto P_0c06e8f6;
case 0x0c06e8f8u: goto P_0c06e8f8;
case 0x0c06e8fau: goto P_0c06e8fa;
case 0x0c06e8fcu: goto P_0c06e8fc;
case 0x0c06e8feu: goto P_0c06e8fe;
case 0x0c06e900u: goto P_0c06e900;
case 0x0c06e902u: goto P_0c06e902;
case 0x0c06e904u: goto P_0c06e904;
case 0x0c06e906u: goto P_0c06e906;
case 0x0c06e908u: goto P_0c06e908;
case 0x0c06e90au: goto P_0c06e90a;
case 0x0c06e90cu: goto P_0c06e90c;
case 0x0c06e90eu: goto P_0c06e90e;
case 0x0c06e910u: goto P_0c06e910;
case 0x0c06e912u: goto P_0c06e912;
case 0x0c06e914u: goto P_0c06e914;
case 0x0c06e916u: goto P_0c06e916;
case 0x0c06e918u: goto P_0c06e918;
case 0x0c06e91au: goto P_0c06e91a;
case 0x0c06e91cu: goto P_0c06e91c;
case 0x0c06e91eu: goto P_0c06e91e;
case 0x0c06e920u: goto P_0c06e920;
case 0x0c06e922u: goto P_0c06e922;
case 0x0c06e924u: goto P_0c06e924;
case 0x0c06e926u: goto P_0c06e926;
case 0x0c06e928u: goto P_0c06e928;
case 0x0c06e92au: goto P_0c06e92a;
case 0x0c06e92cu: goto P_0c06e92c;
case 0x0c06e92eu: goto P_0c06e92e;
case 0x0c06e930u: goto P_0c06e930;
case 0x0c06e932u: goto P_0c06e932;
case 0x0c06e934u: goto P_0c06e934;
case 0x0c06e936u: goto P_0c06e936;
case 0x0c06e938u: goto P_0c06e938;
case 0x0c06e93au: goto P_0c06e93a;
case 0x0c06e93cu: goto P_0c06e93c;
case 0x0c06e93eu: goto P_0c06e93e;
case 0x0c06e940u: goto P_0c06e940;
case 0x0c06e964u: goto P_0c06e964;
case 0x0c06e966u: goto P_0c06e966;
case 0x0c06e968u: goto P_0c06e968;
case 0x0c06e96au: goto P_0c06e96a;
case 0x0c06e96cu: goto P_0c06e96c;
case 0x0c06e96eu: goto P_0c06e96e;
case 0x0c06e970u: goto P_0c06e970;
case 0x0c06e972u: goto P_0c06e972;
case 0x0c06e974u: goto P_0c06e974;
case 0x0c06e976u: goto P_0c06e976;
case 0x0c06e978u: goto P_0c06e978;
case 0x0c06e97au: goto P_0c06e97a;
case 0x0c06e97cu: goto P_0c06e97c;
case 0x0c06e97eu: goto P_0c06e97e;
case 0x0c06e980u: goto P_0c06e980;
case 0x0c06e982u: goto P_0c06e982;
case 0x0c06e984u: goto P_0c06e984;
case 0x0c06e986u: goto P_0c06e986;
case 0x0c06e988u: goto P_0c06e988;
case 0x0c06e98au: goto P_0c06e98a;
case 0x0c06e98cu: goto P_0c06e98c;
case 0x0c06e98eu: goto P_0c06e98e;
case 0x0c06e990u: goto P_0c06e990;
case 0x0c06e992u: goto P_0c06e992;
case 0x0c06e994u: goto P_0c06e994;
case 0x0c06e996u: goto P_0c06e996;
case 0x0c06e998u: goto P_0c06e998;
case 0x0c06e99au: goto P_0c06e99a;
case 0x0c06e99cu: goto P_0c06e99c;
case 0x0c06e99eu: goto P_0c06e99e;
case 0x0c06e9a0u: goto P_0c06e9a0;
case 0x0c06e9a2u: goto P_0c06e9a2;
case 0x0c06e9a4u: goto P_0c06e9a4;
case 0x0c06e9a6u: goto P_0c06e9a6;
case 0x0c06e9a8u: goto P_0c06e9a8;
case 0x0c06e9aau: goto P_0c06e9aa;
case 0x0c06e9acu: goto P_0c06e9ac;
case 0x0c06e9aeu: goto P_0c06e9ae;
case 0x0c06e9b0u: goto P_0c06e9b0;
case 0x0c06e9b2u: goto P_0c06e9b2;
case 0x0c06e9b4u: goto P_0c06e9b4;
case 0x0c06e9b6u: goto P_0c06e9b6;
case 0x0c06e9b8u: goto P_0c06e9b8;
case 0x0c06e9bau: goto P_0c06e9ba;
case 0x0c06e9bcu: goto P_0c06e9bc;
case 0x0c06e9beu: goto P_0c06e9be;
case 0x0c06e9c0u: goto P_0c06e9c0;
case 0x0c06e9c2u: goto P_0c06e9c2;
case 0x0c06e9c4u: goto P_0c06e9c4;
case 0x0c06e9c6u: goto P_0c06e9c6;
case 0x0c06e9c8u: goto P_0c06e9c8;
case 0x0c06e9cau: goto P_0c06e9ca;
case 0x0c06e9ccu: goto P_0c06e9cc;
case 0x0c06e9ceu: goto P_0c06e9ce;
case 0x0c06e9d0u: goto P_0c06e9d0;
case 0x0c06e9d2u: goto P_0c06e9d2;
case 0x0c06e9d4u: goto P_0c06e9d4;
case 0x0c06e9d6u: goto P_0c06e9d6;
case 0x0c06e9d8u: goto P_0c06e9d8;
case 0x0c06e9dau: goto P_0c06e9da;
case 0x0c06e9dcu: goto P_0c06e9dc;
case 0x0c06e9deu: goto P_0c06e9de;
case 0x0c06e9e0u: goto P_0c06e9e0;
case 0x0c06e9e2u: goto P_0c06e9e2;
case 0x0c06e9e4u: goto P_0c06e9e4;
case 0x0c06e9e6u: goto P_0c06e9e6;
case 0x0c06e9e8u: goto P_0c06e9e8;
case 0x0c06e9eau: goto P_0c06e9ea;
case 0x0c06e9ecu: goto P_0c06e9ec;
case 0x0c06e9eeu: goto P_0c06e9ee;
case 0x0c06e9f0u: goto P_0c06e9f0;
case 0x0c06e9f2u: goto P_0c06e9f2;
case 0x0c06e9f4u: goto P_0c06e9f4;
case 0x0c06e9f6u: goto P_0c06e9f6;
case 0x0c06e9f8u: goto P_0c06e9f8;
case 0x0c06e9fau: goto P_0c06e9fa;
case 0x0c06e9fcu: goto P_0c06e9fc;
case 0x0c06e9feu: goto P_0c06e9fe;
case 0x0c06ea00u: goto P_0c06ea00;
case 0x0c06ea02u: goto P_0c06ea02;
case 0x0c06ea04u: goto P_0c06ea04;
case 0x0c06ea06u: goto P_0c06ea06;
case 0x0c06ea08u: goto P_0c06ea08;
case 0x0c06ea0au: goto P_0c06ea0a;
case 0x0c06ea0cu: goto P_0c06ea0c;
case 0x0c06ea0eu: goto P_0c06ea0e;
case 0x0c06ea10u: goto P_0c06ea10;
case 0x0c06ea12u: goto P_0c06ea12;
case 0x0c06ea14u: goto P_0c06ea14;
case 0x0c06ea16u: goto P_0c06ea16;
case 0x0c06ea18u: goto P_0c06ea18;
case 0x0c06ea1au: goto P_0c06ea1a;
case 0x0c06ea1cu: goto P_0c06ea1c;
case 0x0c06ea1eu: goto P_0c06ea1e;
case 0x0c06ea20u: goto P_0c06ea20;
case 0x0c06ea22u: goto P_0c06ea22;
case 0x0c06ea24u: goto P_0c06ea24;
case 0x0c06ea26u: goto P_0c06ea26;
case 0x0c06ea28u: goto P_0c06ea28;
case 0x0c06ea2au: goto P_0c06ea2a;
case 0x0c06ea2cu: goto P_0c06ea2c;
case 0x0c06ea2eu: goto P_0c06ea2e;
case 0x0c06ea30u: goto P_0c06ea30;
case 0x0c06ea32u: goto P_0c06ea32;
case 0x0c06ea34u: goto P_0c06ea34;
case 0x0c06ea36u: goto P_0c06ea36;
case 0x0c06ea38u: goto P_0c06ea38;
case 0x0c06ea3au: goto P_0c06ea3a;
case 0x0c06ea3cu: goto P_0c06ea3c;
case 0x0c06ea3eu: goto P_0c06ea3e;
case 0x0c06ea40u: goto P_0c06ea40;
case 0x0c06ea42u: goto P_0c06ea42;
case 0x0c06ea44u: goto P_0c06ea44;
case 0x0c06ea46u: goto P_0c06ea46;
case 0x0c06ea48u: goto P_0c06ea48;
case 0x0c06ea4au: goto P_0c06ea4a;
case 0x0c06ea4cu: goto P_0c06ea4c;
case 0x0c06ea4eu: goto P_0c06ea4e;
case 0x0c06ea50u: goto P_0c06ea50;
case 0x0c06ea52u: goto P_0c06ea52;
case 0x0c06ea54u: goto P_0c06ea54;
case 0x0c06ea56u: goto P_0c06ea56;
case 0x0c06ea58u: goto P_0c06ea58;
case 0x0c06ea5au: goto P_0c06ea5a;
case 0x0c06ea5cu: goto P_0c06ea5c;
case 0x0c06ea5eu: goto P_0c06ea5e;
case 0x0c06ea60u: goto P_0c06ea60;
case 0x0c06ea62u: goto P_0c06ea62;
case 0x0c06ea64u: goto P_0c06ea64;
case 0x0c06ea66u: goto P_0c06ea66;
case 0x0c06ea68u: goto P_0c06ea68;
case 0x0c06ea6au: goto P_0c06ea6a;
case 0x0c06ea6cu: goto P_0c06ea6c;
case 0x0c06ea6eu: goto P_0c06ea6e;
case 0x0c06ea70u: goto P_0c06ea70;
case 0x0c06ea72u: goto P_0c06ea72;
case 0x0c06ea74u: goto P_0c06ea74;
case 0x0c06ea76u: goto P_0c06ea76;
case 0x0c06ea78u: goto P_0c06ea78;
case 0x0c06ea7au: goto P_0c06ea7a;
case 0x0c06ea7cu: goto P_0c06ea7c;
case 0x0c06ea7eu: goto P_0c06ea7e;
case 0x0c06ea80u: goto P_0c06ea80;
case 0x0c06ea82u: goto P_0c06ea82;
case 0x0c06ea84u: goto P_0c06ea84;
case 0x0c06ea86u: goto P_0c06ea86;
case 0x0c06ea88u: goto P_0c06ea88;
case 0x0c06ea8au: goto P_0c06ea8a;
case 0x0c06ea8cu: goto P_0c06ea8c;
case 0x0c06ea8eu: goto P_0c06ea8e;
case 0x0c06ea90u: goto P_0c06ea90;
case 0x0c06ea92u: goto P_0c06ea92;
case 0x0c06ea94u: goto P_0c06ea94;
case 0x0c0876f2u: goto P_0c0876f2;
case 0x0c0876f4u: goto P_0c0876f4;
case 0x0c0876f6u: goto P_0c0876f6;
case 0x0c0876f8u: goto P_0c0876f8;
case 0x0c0876fau: goto P_0c0876fa;
case 0x0c0876fcu: goto P_0c0876fc;
case 0x0c0876feu: goto P_0c0876fe;
case 0x0c087700u: goto P_0c087700;
case 0x0c087702u: goto P_0c087702;
case 0x0c087704u: goto P_0c087704;
case 0x0c087706u: goto P_0c087706;
case 0x0c087708u: goto P_0c087708;
case 0x0c08770au: goto P_0c08770a;
case 0x0c08770cu: goto P_0c08770c;
case 0x0c08770eu: goto P_0c08770e;
case 0x0c087710u: goto P_0c087710;
case 0x0c087712u: goto P_0c087712;
case 0x0c087714u: goto P_0c087714;
case 0x0c087716u: goto P_0c087716;
case 0x0c087718u: goto P_0c087718;
case 0x0c08771au: goto P_0c08771a;
case 0x0c08771cu: goto P_0c08771c;
case 0x0c08771eu: goto P_0c08771e;
case 0x0c087720u: goto P_0c087720;
case 0x0c087722u: goto P_0c087722;
case 0x0c087724u: goto P_0c087724;
case 0x0c087726u: goto P_0c087726;
case 0x0c087728u: goto P_0c087728;
case 0x0c08772au: goto P_0c08772a;
case 0x0c08772cu: goto P_0c08772c;
case 0x0c08772eu: goto P_0c08772e;
case 0x0c087730u: goto P_0c087730;
case 0x0c087732u: goto P_0c087732;
case 0x0c08d158u: goto P_0c08d158;
case 0x0c08d15au: goto P_0c08d15a;
case 0x0c08d15cu: goto P_0c08d15c;
case 0x0c08d15eu: goto P_0c08d15e;
case 0x0c08d160u: goto P_0c08d160;
case 0x0c08d162u: goto P_0c08d162;
case 0x0c08d164u: goto P_0c08d164;
case 0x0c08d166u: goto P_0c08d166;
case 0x0c08d168u: goto P_0c08d168;
case 0x0c08d16au: goto P_0c08d16a;
case 0x0c08d16cu: goto P_0c08d16c;
case 0x0c08d16eu: goto P_0c08d16e;
case 0x0c08d170u: goto P_0c08d170;
case 0x0c08d172u: goto P_0c08d172;
case 0x0c08d174u: goto P_0c08d174;
case 0x0c08d176u: goto P_0c08d176;
case 0x0c08d178u: goto P_0c08d178;
case 0x0c08d17au: goto P_0c08d17a;
case 0x0c08d17cu: goto P_0c08d17c;
case 0x0c08d17eu: goto P_0c08d17e;
case 0x0c08d180u: goto P_0c08d180;
case 0x0c08d182u: goto P_0c08d182;
case 0x0c08d184u: goto P_0c08d184;
case 0x0c08d186u: goto P_0c08d186;
case 0x0c08d188u: goto P_0c08d188;
case 0x0c08d18au: goto P_0c08d18a;
case 0x0c08d18cu: goto P_0c08d18c;
case 0x0c08d18eu: goto P_0c08d18e;
case 0x0c08d190u: goto P_0c08d190;
case 0x0c08d406u: goto P_0c08d406;
case 0x0c08d408u: goto P_0c08d408;
case 0x0c08d40au: goto P_0c08d40a;
case 0x0c08d40cu: goto P_0c08d40c;
case 0x0c08d40eu: goto P_0c08d40e;
case 0x0c08d410u: goto P_0c08d410;
case 0x0c08d412u: goto P_0c08d412;
case 0x0c08d414u: goto P_0c08d414;
case 0x0c08d416u: goto P_0c08d416;
case 0x0c08d418u: goto P_0c08d418;
case 0x0c08d41au: goto P_0c08d41a;
case 0x0c08d41cu: goto P_0c08d41c;
case 0x0c08d41eu: goto P_0c08d41e;
case 0x0c08d420u: goto P_0c08d420;
case 0x0c08d422u: goto P_0c08d422;
case 0x0c08d424u: goto P_0c08d424;
case 0x0c08d426u: goto P_0c08d426;
case 0x0c08d428u: goto P_0c08d428;
case 0x0c08d42au: goto P_0c08d42a;
case 0x0c08d42cu: goto P_0c08d42c;
case 0x0c08d42eu: goto P_0c08d42e;
case 0x0c08d430u: goto P_0c08d430;
case 0x0c08d432u: goto P_0c08d432;
case 0x0c08d434u: goto P_0c08d434;
case 0x0c08d436u: goto P_0c08d436;
case 0x0c08d438u: goto P_0c08d438;
case 0x0c08d43au: goto P_0c08d43a;
case 0x0c08d43cu: goto P_0c08d43c;
case 0x0c08d43eu: goto P_0c08d43e;
case 0x0c08d440u: goto P_0c08d440;
case 0x0c08d442u: goto P_0c08d442;
case 0x0c08d444u: goto P_0c08d444;
case 0x0c08d446u: goto P_0c08d446;
case 0x0c08d448u: goto P_0c08d448;
case 0x0c08d44au: goto P_0c08d44a;
case 0x0c09d5aeu: goto P_0c09d5ae;
case 0x0c09d5b0u: goto P_0c09d5b0;
case 0x0c09d5b2u: goto P_0c09d5b2;
case 0x0c09d5b4u: goto P_0c09d5b4;
case 0x0c09d5b6u: goto P_0c09d5b6;
case 0x0c09d5b8u: goto P_0c09d5b8;
case 0x0c09d5bau: goto P_0c09d5ba;
case 0x0c09d5bcu: goto P_0c09d5bc;
case 0x0c09d5beu: goto P_0c09d5be;
case 0x0c09d5c0u: goto P_0c09d5c0;
case 0x0c09d5c2u: goto P_0c09d5c2;
case 0x0c09d5c4u: goto P_0c09d5c4;
case 0x0c09d5c6u: goto P_0c09d5c6;
case 0x0c09d5c8u: goto P_0c09d5c8;
case 0x0c09d5cau: goto P_0c09d5ca;
case 0x0c09d5ccu: goto P_0c09d5cc;
case 0x0c09d5ceu: goto P_0c09d5ce;
case 0x0c09d5d0u: goto P_0c09d5d0;
case 0x0c09d5d2u: goto P_0c09d5d2;
case 0x0c09d5d4u: goto P_0c09d5d4;
case 0x0c09d5d6u: goto P_0c09d5d6;
case 0x0c09d5d8u: goto P_0c09d5d8;
case 0x0c09d5dau: goto P_0c09d5da;
case 0x0c09d5dcu: goto P_0c09d5dc;
case 0x0c09d5deu: goto P_0c09d5de;
case 0x0c09d5e0u: goto P_0c09d5e0;
case 0x0c09d5e2u: goto P_0c09d5e2;
case 0x0c09d5e4u: goto P_0c09d5e4;
case 0x0c09d5e6u: goto P_0c09d5e6;
case 0x0c09d5e8u: goto P_0c09d5e8;
case 0x0c09d5eau: goto P_0c09d5ea;
case 0x0c09d5ecu: goto P_0c09d5ec;
case 0x0c09d5eeu: goto P_0c09d5ee;
case 0x0c09d5f0u: goto P_0c09d5f0;
case 0x0c09d5f2u: goto P_0c09d5f2;
case 0x0c09d5f4u: goto P_0c09d5f4;
case 0x0c09d5f6u: goto P_0c09d5f6;
case 0x0c09d5f8u: goto P_0c09d5f8;
case 0x0c09d5fau: goto P_0c09d5fa;
case 0x0c09d5fcu: goto P_0c09d5fc;
case 0x0c09d5feu: goto P_0c09d5fe;
case 0x0c09d600u: goto P_0c09d600;
case 0x0c09d602u: goto P_0c09d602;
case 0x0c09d604u: goto P_0c09d604;
case 0x0c09d606u: goto P_0c09d606;
case 0x0c09d608u: goto P_0c09d608;
case 0x0c09d60au: goto P_0c09d60a;
case 0x0c09d60cu: goto P_0c09d60c;
case 0x0c09d60eu: goto P_0c09d60e;
case 0x0c09d610u: goto P_0c09d610;
case 0x0c09d612u: goto P_0c09d612;
case 0x0c09d614u: goto P_0c09d614;
case 0x0c09d616u: goto P_0c09d616;
case 0x0c09d618u: goto P_0c09d618;
case 0x0c09d61au: goto P_0c09d61a;
case 0x0c09d61cu: goto P_0c09d61c;
case 0x0c09d61eu: goto P_0c09d61e;
case 0x0c09d620u: goto P_0c09d620;
case 0x0c09d622u: goto P_0c09d622;
case 0x0c09d624u: goto P_0c09d624;
case 0x0c09d626u: goto P_0c09d626;
case 0x0c09d628u: goto P_0c09d628;
case 0x0c09d62au: goto P_0c09d62a;
case 0x0c09d62cu: goto P_0c09d62c;
case 0x0c09d62eu: goto P_0c09d62e;
case 0x0c09d630u: goto P_0c09d630;
case 0x0c09d632u: goto P_0c09d632;
case 0x0c09d634u: goto P_0c09d634;
case 0x0c09d636u: goto P_0c09d636;
case 0x0c09d638u: goto P_0c09d638;
case 0x0c09d63au: goto P_0c09d63a;
case 0x0c09d63cu: goto P_0c09d63c;
case 0x0c09d63eu: goto P_0c09d63e;
case 0x0c09d640u: goto P_0c09d640;
case 0x0c09d642u: goto P_0c09d642;
case 0x0c09d644u: goto P_0c09d644;
case 0x0c09d646u: goto P_0c09d646;
case 0x0c09d648u: goto P_0c09d648;
case 0x0c09d64au: goto P_0c09d64a;
case 0x0c09d64cu: goto P_0c09d64c;
case 0x0c09d64eu: goto P_0c09d64e;
case 0x0c09d650u: goto P_0c09d650;
case 0x0c09d652u: goto P_0c09d652;
case 0x0c09d654u: goto P_0c09d654;
case 0x0c09d656u: goto P_0c09d656;
case 0x0c09d658u: goto P_0c09d658;
case 0x0c09d65au: goto P_0c09d65a;
case 0x0c09d65cu: goto P_0c09d65c;
case 0x0c09d65eu: goto P_0c09d65e;
case 0x0c09d660u: goto P_0c09d660;
case 0x0c09d662u: goto P_0c09d662;
case 0x0c09efceu: goto P_0c09efce;
case 0x0c09efd0u: goto P_0c09efd0;
case 0x0c09efd2u: goto P_0c09efd2;
case 0x0c09efd4u: goto P_0c09efd4;
case 0x0c09efd6u: goto P_0c09efd6;
case 0x0c09efd8u: goto P_0c09efd8;
case 0x0c09efdau: goto P_0c09efda;
case 0x0c09efdcu: goto P_0c09efdc;
case 0x0c09efdeu: goto P_0c09efde;
case 0x0c09efe0u: goto P_0c09efe0;
case 0x0c09efe2u: goto P_0c09efe2;
case 0x0c09efe4u: goto P_0c09efe4;
case 0x0c09f1acu: goto P_0c09f1ac;
case 0x0c09f1aeu: goto P_0c09f1ae;
case 0x0c09f1b0u: goto P_0c09f1b0;
case 0x0c09f1b2u: goto P_0c09f1b2;
case 0x0c09f1b4u: goto P_0c09f1b4;
case 0x0c09f1b6u: goto P_0c09f1b6;
case 0x0c09f1b8u: goto P_0c09f1b8;
case 0x0c09f1bau: goto P_0c09f1ba;
case 0x0c09f1bcu: goto P_0c09f1bc;
case 0x0c09f1beu: goto P_0c09f1be;
case 0x0c09f1c0u: goto P_0c09f1c0;
case 0x0c09f1c2u: goto P_0c09f1c2;
case 0x0c09f1c4u: goto P_0c09f1c4;
case 0x0c09f1c6u: goto P_0c09f1c6;
case 0x0c09f1c8u: goto P_0c09f1c8;
case 0x0c09f1cau: goto P_0c09f1ca;
case 0x0c09f1ccu: goto P_0c09f1cc;
case 0x0c09f1ceu: goto P_0c09f1ce;
case 0x0c09f1d0u: goto P_0c09f1d0;
case 0x0c09f1d2u: goto P_0c09f1d2;
case 0x0c09f1d4u: goto P_0c09f1d4;
case 0x0c09f1d6u: goto P_0c09f1d6;
case 0x0c09f1d8u: goto P_0c09f1d8;
case 0x0c09f1dau: goto P_0c09f1da;
case 0x0c09f1dcu: goto P_0c09f1dc;
case 0x0c09f1deu: goto P_0c09f1de;
case 0x0c09f1e0u: goto P_0c09f1e0;
case 0x0c09f1e2u: goto P_0c09f1e2;
case 0x0c09f1e4u: goto P_0c09f1e4;
case 0x0c09f1e6u: goto P_0c09f1e6;
case 0x0c09f1e8u: goto P_0c09f1e8;
case 0x0c09f1eau: goto P_0c09f1ea;
case 0x0c09f1ecu: goto P_0c09f1ec;
case 0x0c09f1eeu: goto P_0c09f1ee;
case 0x0c09f1f0u: goto P_0c09f1f0;
case 0x0c09f1f2u: goto P_0c09f1f2;
case 0x0c09f1f4u: goto P_0c09f1f4;
case 0x0c09f1f6u: goto P_0c09f1f6;
case 0x0c09f1f8u: goto P_0c09f1f8;
case 0x0c09f1fau: goto P_0c09f1fa;
case 0x0c09f1fcu: goto P_0c09f1fc;
case 0x0c09f1feu: goto P_0c09f1fe;
case 0x0c09f200u: goto P_0c09f200;
case 0x0c09f202u: goto P_0c09f202;
case 0x0c09f204u: goto P_0c09f204;
case 0x0c09f206u: goto P_0c09f206;
case 0x0c09f208u: goto P_0c09f208;
case 0x0c09f20au: goto P_0c09f20a;
case 0x0c09f20cu: goto P_0c09f20c;
case 0x0c09f20eu: goto P_0c09f20e;
case 0x0c09f210u: goto P_0c09f210;
case 0x0c09f212u: goto P_0c09f212;
case 0x0c09f214u: goto P_0c09f214;
case 0x0c09f216u: goto P_0c09f216;
case 0x0c09f218u: goto P_0c09f218;
case 0x0c09f21au: goto P_0c09f21a;
case 0x0c09f21cu: goto P_0c09f21c;
case 0x0c09f21eu: goto P_0c09f21e;
case 0x0c09f220u: goto P_0c09f220;
case 0x0c09f222u: goto P_0c09f222;
case 0x0c09f224u: goto P_0c09f224;
case 0x0c09f226u: goto P_0c09f226;
case 0x0c09f228u: goto P_0c09f228;
case 0x0c09f22au: goto P_0c09f22a;
case 0x0c09f22cu: goto P_0c09f22c;
case 0x0c09f22eu: goto P_0c09f22e;
case 0x0c09f230u: goto P_0c09f230;
case 0x0c09f232u: goto P_0c09f232;
case 0x0c09f234u: goto P_0c09f234;
case 0x0c09f236u: goto P_0c09f236;
case 0x0c09f238u: goto P_0c09f238;
case 0x0c09f23au: goto P_0c09f23a;
case 0x0c09f23cu: goto P_0c09f23c;
case 0x0c09f23eu: goto P_0c09f23e;
case 0x0c09f240u: goto P_0c09f240;
case 0x0c09f242u: goto P_0c09f242;
case 0x0c09f244u: goto P_0c09f244;
case 0x0c09f246u: goto P_0c09f246;
case 0x0c09f248u: goto P_0c09f248;
case 0x0c09f24au: goto P_0c09f24a;
case 0x0c09f24cu: goto P_0c09f24c;
case 0x0c09f24eu: goto P_0c09f24e;
case 0x0c09f250u: goto P_0c09f250;
case 0x0c09f268u: goto P_0c09f268;
case 0x0c09f26au: goto P_0c09f26a;
case 0x0c09f26cu: goto P_0c09f26c;
case 0x0c09f26eu: goto P_0c09f26e;
case 0x0c09f270u: goto P_0c09f270;
case 0x0c09f272u: goto P_0c09f272;
case 0x0c09f274u: goto P_0c09f274;
case 0x0c09f276u: goto P_0c09f276;
case 0x0c09f278u: goto P_0c09f278;
case 0x0c09f27au: goto P_0c09f27a;
case 0x0c09f27cu: goto P_0c09f27c;
case 0x0c09f27eu: goto P_0c09f27e;
case 0x0c09f280u: goto P_0c09f280;
case 0x0c09f282u: goto P_0c09f282;
case 0x0c09f284u: goto P_0c09f284;
case 0x0c09f286u: goto P_0c09f286;
case 0x0c09f288u: goto P_0c09f288;
case 0x0c09f28au: goto P_0c09f28a;
case 0x0c09f28cu: goto P_0c09f28c;
case 0x0c09f28eu: goto P_0c09f28e;
case 0x0c09f290u: goto P_0c09f290;
case 0x0c09f292u: goto P_0c09f292;
case 0x0c09f294u: goto P_0c09f294;
case 0x0c09f296u: goto P_0c09f296;
case 0x0c09f298u: goto P_0c09f298;
case 0x0c09f29au: goto P_0c09f29a;
case 0x0c09f29cu: goto P_0c09f29c;
case 0x0c09f29eu: goto P_0c09f29e;
case 0x0c09f2a0u: goto P_0c09f2a0;
case 0x0c09f2a2u: goto P_0c09f2a2;
case 0x0c09f2a4u: goto P_0c09f2a4;
case 0x0c09f2a6u: goto P_0c09f2a6;
case 0x0c09f2a8u: goto P_0c09f2a8;
case 0x0c09f2aau: goto P_0c09f2aa;
case 0x0c09f2acu: goto P_0c09f2ac;
case 0x0c09f2aeu: goto P_0c09f2ae;
case 0x0c09f2b0u: goto P_0c09f2b0;
case 0x0c09f2b2u: goto P_0c09f2b2;
case 0x0c09f2b4u: goto P_0c09f2b4;
case 0x0c09f2b6u: goto P_0c09f2b6;
case 0x0c09f2b8u: goto P_0c09f2b8;
case 0x0c09f2bau: goto P_0c09f2ba;
case 0x0c09f2bcu: goto P_0c09f2bc;
case 0x0c09f2beu: goto P_0c09f2be;
case 0x0c09f2c0u: goto P_0c09f2c0;
case 0x0c09f2c2u: goto P_0c09f2c2;
case 0x0c09f2c4u: goto P_0c09f2c4;
case 0x0c09f2c6u: goto P_0c09f2c6;
case 0x0c09f2c8u: goto P_0c09f2c8;
case 0x0c09f2cau: goto P_0c09f2ca;
case 0x0c09f2ccu: goto P_0c09f2cc;
case 0x0c09f2ceu: goto P_0c09f2ce;
case 0x0c09f2d0u: goto P_0c09f2d0;
case 0x0c09f2d2u: goto P_0c09f2d2;
case 0x0c09f2d4u: goto P_0c09f2d4;
case 0x0c09f2d6u: goto P_0c09f2d6;
case 0x0c09f2d8u: goto P_0c09f2d8;
case 0x0c09f2dau: goto P_0c09f2da;
case 0x0c09f2dcu: goto P_0c09f2dc;
case 0x0c09f2deu: goto P_0c09f2de;
case 0x0c09f2e0u: goto P_0c09f2e0;
case 0x0c09f2e2u: goto P_0c09f2e2;
case 0x0c09f2e4u: goto P_0c09f2e4;
case 0x0c09f2e6u: goto P_0c09f2e6;
case 0x0c09f2e8u: goto P_0c09f2e8;
case 0x0c09f2eau: goto P_0c09f2ea;
case 0x0c09f2ecu: goto P_0c09f2ec;
case 0x0c09f2eeu: goto P_0c09f2ee;
case 0x0c09f2f0u: goto P_0c09f2f0;
case 0x0c09f2f2u: goto P_0c09f2f2;
case 0x0c09f2f4u: goto P_0c09f2f4;
case 0x0c09f2f6u: goto P_0c09f2f6;
case 0x0c09f2f8u: goto P_0c09f2f8;
case 0x0c09f2fau: goto P_0c09f2fa;
case 0x0c09f2fcu: goto P_0c09f2fc;
case 0x0c09f2feu: goto P_0c09f2fe;
case 0x0c09f300u: goto P_0c09f300;
case 0x0c09f302u: goto P_0c09f302;
case 0x0c09f304u: goto P_0c09f304;
case 0x0c09f306u: goto P_0c09f306;
case 0x0c09f308u: goto P_0c09f308;
case 0x0c09f30au: goto P_0c09f30a;
case 0x0c09f30cu: goto P_0c09f30c;
case 0x0c09f30eu: goto P_0c09f30e;
case 0x0c09f310u: goto P_0c09f310;
case 0x0c09f312u: goto P_0c09f312;
case 0x0c09f314u: goto P_0c09f314;
case 0x0c09f316u: goto P_0c09f316;
case 0x0c09f318u: goto P_0c09f318;
case 0x0c09f31au: goto P_0c09f31a;
case 0x0c09f31cu: goto P_0c09f31c;
case 0x0c09f31eu: goto P_0c09f31e;
case 0x0c09f320u: goto P_0c09f320;
case 0x0c09f322u: goto P_0c09f322;
case 0x0c09f324u: goto P_0c09f324;
case 0x0c09f326u: goto P_0c09f326;
case 0x0c09f328u: goto P_0c09f328;
case 0x0c09f32au: goto P_0c09f32a;
case 0x0c09f32cu: goto P_0c09f32c;
case 0x0c09f32eu: goto P_0c09f32e;
case 0x0c09f330u: goto P_0c09f330;
case 0x0c09f332u: goto P_0c09f332;
case 0x0c09f334u: goto P_0c09f334;
case 0x0c0ac192u: goto P_0c0ac192;
case 0x0c0ac194u: goto P_0c0ac194;
case 0x0c0ac196u: goto P_0c0ac196;
case 0x0c0ac198u: goto P_0c0ac198;
case 0x0c0ac19au: goto P_0c0ac19a;
case 0x0c0ac19cu: goto P_0c0ac19c;
case 0x0c0ac19eu: goto P_0c0ac19e;
case 0x0c0ac1a0u: goto P_0c0ac1a0;
case 0x0c0ac1a2u: goto P_0c0ac1a2;
case 0x0c0ac1a4u: goto P_0c0ac1a4;
case 0x0c0ac1a6u: goto P_0c0ac1a6;
case 0x0c0ac1a8u: goto P_0c0ac1a8;
case 0x0c0ac1aau: goto P_0c0ac1aa;
case 0x0c0ac1acu: goto P_0c0ac1ac;
case 0x0c0ac1aeu: goto P_0c0ac1ae;
case 0x0c0ac1b0u: goto P_0c0ac1b0;
case 0x0c0ac1b2u: goto P_0c0ac1b2;
case 0x0c0ac1b4u: goto P_0c0ac1b4;
case 0x0c0ac1b6u: goto P_0c0ac1b6;
case 0x0c0ac1b8u: goto P_0c0ac1b8;
case 0x0c0ac1bau: goto P_0c0ac1ba;
case 0x0c0ac1bcu: goto P_0c0ac1bc;
case 0x0c0ac1beu: goto P_0c0ac1be;
case 0x0c0ac1c0u: goto P_0c0ac1c0;
case 0x0c0ac1c2u: goto P_0c0ac1c2;
case 0x0c0ac1c4u: goto P_0c0ac1c4;
case 0x0c0ac1c6u: goto P_0c0ac1c6;
case 0x0c0ac1c8u: goto P_0c0ac1c8;
case 0x0c0ac1cau: goto P_0c0ac1ca;
case 0x0c0ac1ccu: goto P_0c0ac1cc;
case 0x0c0ac1ceu: goto P_0c0ac1ce;
case 0x0c0ac1d0u: goto P_0c0ac1d0;
case 0x0c0ac1d2u: goto P_0c0ac1d2;
case 0x0c0ac1d4u: goto P_0c0ac1d4;
case 0x0c0ac1d6u: goto P_0c0ac1d6;
case 0x0c0ac1d8u: goto P_0c0ac1d8;
case 0x0c0ac1dau: goto P_0c0ac1da;
case 0x0c0ac1dcu: goto P_0c0ac1dc;
case 0x0c0ac1deu: goto P_0c0ac1de;
case 0x0c0ac1e0u: goto P_0c0ac1e0;
case 0x0c0ac1e2u: goto P_0c0ac1e2;
case 0x0c0ac1e4u: goto P_0c0ac1e4;
case 0x0c0ac1e6u: goto P_0c0ac1e6;
case 0x0c0ac1e8u: goto P_0c0ac1e8;
case 0x0c0ac1eau: goto P_0c0ac1ea;
case 0x0c0ac1ecu: goto P_0c0ac1ec;
case 0x0c0ac1eeu: goto P_0c0ac1ee;
case 0x0c0ac1f0u: goto P_0c0ac1f0;
case 0x0c0ac1f2u: goto P_0c0ac1f2;
case 0x0c0ac1f4u: goto P_0c0ac1f4;
case 0x0c0ac1f6u: goto P_0c0ac1f6;
case 0x0c0ac1f8u: goto P_0c0ac1f8;
case 0x0c0ac1fau: goto P_0c0ac1fa;
case 0x0c0ac1fcu: goto P_0c0ac1fc;
case 0x0c0ac1feu: goto P_0c0ac1fe;
case 0x0c0ac200u: goto P_0c0ac200;
case 0x0c0ac202u: goto P_0c0ac202;
case 0x0c0ac204u: goto P_0c0ac204;
case 0x0c0ac206u: goto P_0c0ac206;
case 0x0c0ac208u: goto P_0c0ac208;
case 0x0c0ac20au: goto P_0c0ac20a;
case 0x0c0ac20cu: goto P_0c0ac20c;
case 0x0c0ac20eu: goto P_0c0ac20e;
case 0x0c0ac210u: goto P_0c0ac210;
case 0x0c0ac212u: goto P_0c0ac212;
case 0x0c0ac214u: goto P_0c0ac214;
case 0x0c0ac216u: goto P_0c0ac216;
case 0x0c0ac218u: goto P_0c0ac218;
case 0x0c0ac21au: goto P_0c0ac21a;
case 0x0c0ac21cu: goto P_0c0ac21c;
case 0x0c0ac21eu: goto P_0c0ac21e;
case 0x0c0ac220u: goto P_0c0ac220;
case 0x0c0ac222u: goto P_0c0ac222;
case 0x0c0ac224u: goto P_0c0ac224;
case 0x0c0ac226u: goto P_0c0ac226;
case 0x0c0ac228u: goto P_0c0ac228;
case 0x0c0ad112u: goto P_0c0ad112;
case 0x0c0ad114u: goto P_0c0ad114;
case 0x0c0ad116u: goto P_0c0ad116;
case 0x0c0ad118u: goto P_0c0ad118;
case 0x0c0ad11au: goto P_0c0ad11a;
case 0x0c0ad11cu: goto P_0c0ad11c;
case 0x0c0ad11eu: goto P_0c0ad11e;
case 0x0c0ad120u: goto P_0c0ad120;
case 0x0c0ad122u: goto P_0c0ad122;
case 0x0c0ad124u: goto P_0c0ad124;
case 0x0c0ad126u: goto P_0c0ad126;
case 0x0c0ad128u: goto P_0c0ad128;
case 0x0c0ad12au: goto P_0c0ad12a;
case 0x0c0ad12cu: goto P_0c0ad12c;
case 0x0c0ad12eu: goto P_0c0ad12e;
case 0x0c0ad164u: goto P_0c0ad164;
case 0x0c0ad166u: goto P_0c0ad166;
case 0x0c0ad168u: goto P_0c0ad168;
case 0x0c0ad16au: goto P_0c0ad16a;
case 0x0c0ad16cu: goto P_0c0ad16c;
case 0x0c0ad16eu: goto P_0c0ad16e;
case 0x0c0ad170u: goto P_0c0ad170;
case 0x0c0ad172u: goto P_0c0ad172;
case 0x0c0ad174u: goto P_0c0ad174;
case 0x0c0ad176u: goto P_0c0ad176;
case 0x0c0ad1aau: goto P_0c0ad1aa;
case 0x0c0ad1acu: goto P_0c0ad1ac;
case 0x0c0ad1aeu: goto P_0c0ad1ae;
case 0x0c0ad1b0u: goto P_0c0ad1b0;
case 0x0c0ad1b2u: goto P_0c0ad1b2;
case 0x0c0ad1b4u: goto P_0c0ad1b4;
case 0x0c0ad1b6u: goto P_0c0ad1b6;
case 0x0c0ad1b8u: goto P_0c0ad1b8;
case 0x0c0ad1bau: goto P_0c0ad1ba;
case 0x0c0ad1bcu: goto P_0c0ad1bc;
case 0x0c0ad1beu: goto P_0c0ad1be;
case 0x0c0ad1c0u: goto P_0c0ad1c0;
case 0x0c0ad1c2u: goto P_0c0ad1c2;
case 0x0c0ad1c4u: goto P_0c0ad1c4;
case 0x0c0ad1c6u: goto P_0c0ad1c6;
case 0x0c0ad1c8u: goto P_0c0ad1c8;
case 0x0c0ad1cau: goto P_0c0ad1ca;
case 0x0c0ad1ccu: goto P_0c0ad1cc;
case 0x0c0ad1ceu: goto P_0c0ad1ce;
case 0x0c0ad1d0u: goto P_0c0ad1d0;
case 0x0c0ad1d2u: goto P_0c0ad1d2;
case 0x0c0ad1d4u: goto P_0c0ad1d4;
case 0x0c0ad1d6u: goto P_0c0ad1d6;
case 0x0c0ad1d8u: goto P_0c0ad1d8;
case 0x0c0ad1dau: goto P_0c0ad1da;
case 0x0c0ad1dcu: goto P_0c0ad1dc;
case 0x0c0ad1deu: goto P_0c0ad1de;
case 0x0c0ad1e0u: goto P_0c0ad1e0;
case 0x0c0ad1e2u: goto P_0c0ad1e2;
case 0x0c0ad1e4u: goto P_0c0ad1e4;
case 0x0c0ad1e6u: goto P_0c0ad1e6;
case 0x0c0ad1e8u: goto P_0c0ad1e8;
case 0x0c0ad1eau: goto P_0c0ad1ea;
case 0x0c0ad1ecu: goto P_0c0ad1ec;
case 0x0c0ad1eeu: goto P_0c0ad1ee;
case 0x0c0ad1f0u: goto P_0c0ad1f0;
case 0x0c0ad1f2u: goto P_0c0ad1f2;
case 0x0c0ad1f4u: goto P_0c0ad1f4;
case 0x0c0ad1f6u: goto P_0c0ad1f6;
case 0x0c0ad1f8u: goto P_0c0ad1f8;
case 0x0c0ad1fau: goto P_0c0ad1fa;
case 0x0c0ad1fcu: goto P_0c0ad1fc;
case 0x0c0ad1feu: goto P_0c0ad1fe;
case 0x0c0ad200u: goto P_0c0ad200;
case 0x0c0ad202u: goto P_0c0ad202;
case 0x0c0ad204u: goto P_0c0ad204;
case 0x0c0ad206u: goto P_0c0ad206;
case 0x0c0ad208u: goto P_0c0ad208;
case 0x0c0ad20au: goto P_0c0ad20a;
case 0x0c0ad20cu: goto P_0c0ad20c;
case 0x0c0ad20eu: goto P_0c0ad20e;
case 0x0c0ad210u: goto P_0c0ad210;
case 0x0c0ad212u: goto P_0c0ad212;
case 0x0c0ad214u: goto P_0c0ad214;
case 0x0c0ad216u: goto P_0c0ad216;
case 0x0c0ad218u: goto P_0c0ad218;
case 0x0c0ad21au: goto P_0c0ad21a;
case 0x0c0ad21cu: goto P_0c0ad21c;
case 0x0c0ad21eu: goto P_0c0ad21e;
case 0x0c0ad220u: goto P_0c0ad220;
case 0x0c0ad222u: goto P_0c0ad222;
case 0x0c0ad224u: goto P_0c0ad224;
case 0x0c0ad226u: goto P_0c0ad226;
case 0x0c0ad228u: goto P_0c0ad228;
case 0x0c0ad22au: goto P_0c0ad22a;
case 0x0c0ad22cu: goto P_0c0ad22c;
case 0x0c0ad22eu: goto P_0c0ad22e;
case 0x0c0ad230u: goto P_0c0ad230;
case 0x0c0ad232u: goto P_0c0ad232;
case 0x0c0ad234u: goto P_0c0ad234;
case 0x0c0ad236u: goto P_0c0ad236;
case 0x0c0ad238u: goto P_0c0ad238;
case 0x0c0ad26cu: goto P_0c0ad26c;
case 0x0c0ad26eu: goto P_0c0ad26e;
case 0x0c0ad270u: goto P_0c0ad270;
case 0x0c0ad272u: goto P_0c0ad272;
case 0x0c0ad274u: goto P_0c0ad274;
case 0x0c0ad276u: goto P_0c0ad276;
case 0x0c0ad278u: goto P_0c0ad278;
case 0x0c0ad27au: goto P_0c0ad27a;
case 0x0c0ad27cu: goto P_0c0ad27c;
case 0x0c0ad27eu: goto P_0c0ad27e;
case 0x0c0ad280u: goto P_0c0ad280;
case 0x0c0ad282u: goto P_0c0ad282;
case 0x0c0ad284u: goto P_0c0ad284;
case 0x0c0ad286u: goto P_0c0ad286;
case 0x0c0ad288u: goto P_0c0ad288;
case 0x0c0ad28au: goto P_0c0ad28a;
case 0x0c0ad28cu: goto P_0c0ad28c;
case 0x0c0ad28eu: goto P_0c0ad28e;
case 0x0c0ad290u: goto P_0c0ad290;
case 0x0c0ad292u: goto P_0c0ad292;
case 0x0c0ad294u: goto P_0c0ad294;
case 0x0c0ad296u: goto P_0c0ad296;
case 0x0c0ad298u: goto P_0c0ad298;
case 0x0c0ad29au: goto P_0c0ad29a;
case 0x0c0ad29cu: goto P_0c0ad29c;
case 0x0c0ad29eu: goto P_0c0ad29e;
case 0x0c0ad2a0u: goto P_0c0ad2a0;
case 0x0c0ad2a2u: goto P_0c0ad2a2;
case 0x0c0ad2a4u: goto P_0c0ad2a4;
case 0x0c0ad2a6u: goto P_0c0ad2a6;
case 0x0c0ad2a8u: goto P_0c0ad2a8;
case 0x0c0ad2aau: goto P_0c0ad2aa;
case 0x0c0ad2acu: goto P_0c0ad2ac;
case 0x0c0ad2aeu: goto P_0c0ad2ae;
case 0x0c0ad2b0u: goto P_0c0ad2b0;
case 0x0c0ad2b2u: goto P_0c0ad2b2;
case 0x0c0ad2b4u: goto P_0c0ad2b4;
case 0x0c0ad2b6u: goto P_0c0ad2b6;
case 0x0c0ad2b8u: goto P_0c0ad2b8;
case 0x0c0ad2bau: goto P_0c0ad2ba;
case 0x0c0ad2bcu: goto P_0c0ad2bc;
case 0x0c0ad2beu: goto P_0c0ad2be;
case 0x0c0ad2c0u: goto P_0c0ad2c0;
case 0x0c0ad2c2u: goto P_0c0ad2c2;
case 0x0c0ad2c4u: goto P_0c0ad2c4;
case 0x0c0ad2c6u: goto P_0c0ad2c6;
case 0x0c0ad2c8u: goto P_0c0ad2c8;
case 0x0c0ad2cau: goto P_0c0ad2ca;
case 0x0c0ad2ccu: goto P_0c0ad2cc;
case 0x0c0ad2ceu: goto P_0c0ad2ce;
case 0x0c0ad2d0u: goto P_0c0ad2d0;
case 0x0c0ad2d2u: goto P_0c0ad2d2;
case 0x0c0ad2d4u: goto P_0c0ad2d4;
case 0x0c0ad2d6u: goto P_0c0ad2d6;
case 0x0c0ad2d8u: goto P_0c0ad2d8;
case 0x0c0ad2dau: goto P_0c0ad2da;
case 0x0c0ad2dcu: goto P_0c0ad2dc;
case 0x0c0ad2deu: goto P_0c0ad2de;
case 0x0c0ad2e0u: goto P_0c0ad2e0;
case 0x0c0ad2e2u: goto P_0c0ad2e2;
case 0x0c0ad2e4u: goto P_0c0ad2e4;
case 0x0c0ad2e6u: goto P_0c0ad2e6;
case 0x0c0ad2e8u: goto P_0c0ad2e8;
case 0x0c0ad2eau: goto P_0c0ad2ea;
case 0x0c0ad2ecu: goto P_0c0ad2ec;
case 0x0c0ad2eeu: goto P_0c0ad2ee;
case 0x0c0ad2f0u: goto P_0c0ad2f0;
case 0x0c0ad2f2u: goto P_0c0ad2f2;
case 0x0c0ad2f4u: goto P_0c0ad2f4;
case 0x0c0ad2f6u: goto P_0c0ad2f6;
case 0x0c0ad2f8u: goto P_0c0ad2f8;
case 0x0c0ad2fau: goto P_0c0ad2fa;
case 0x0c0ad2fcu: goto P_0c0ad2fc;
case 0x0c0ad2feu: goto P_0c0ad2fe;
case 0x0c0ad300u: goto P_0c0ad300;
case 0x0c0ad302u: goto P_0c0ad302;
case 0x0c0ad304u: goto P_0c0ad304;
case 0x0c0ad306u: goto P_0c0ad306;
case 0x0c0ad308u: goto P_0c0ad308;
case 0x0c0ad30au: goto P_0c0ad30a;
case 0x0c0ad30cu: goto P_0c0ad30c;
case 0x0c0ad30eu: goto P_0c0ad30e;
case 0x0c0ad310u: goto P_0c0ad310;
case 0x0c0ad312u: goto P_0c0ad312;
case 0x0c0ad314u: goto P_0c0ad314;
case 0x0c0ad316u: goto P_0c0ad316;
case 0x0c0ad318u: goto P_0c0ad318;
case 0x0c0ad31au: goto P_0c0ad31a;
case 0x0c0ad31cu: goto P_0c0ad31c;
case 0x0c0ad31eu: goto P_0c0ad31e;
case 0x0c0ad320u: goto P_0c0ad320;
case 0x0c0ad322u: goto P_0c0ad322;
case 0x0c0ad324u: goto P_0c0ad324;
case 0x0c0ad326u: goto P_0c0ad326;
case 0x0c0ad328u: goto P_0c0ad328;
case 0x0c0ad32au: goto P_0c0ad32a;
case 0x0c0ad32cu: goto P_0c0ad32c;
case 0x0c0ad32eu: goto P_0c0ad32e;
case 0x0c0ad330u: goto P_0c0ad330;
case 0x0c0ad332u: goto P_0c0ad332;
case 0x0c0ad334u: goto P_0c0ad334;
case 0x0c0ad336u: goto P_0c0ad336;
case 0x0c0ad338u: goto P_0c0ad338;
case 0x0c0ad33au: goto P_0c0ad33a;
case 0x0c0ad33cu: goto P_0c0ad33c;
case 0x0c0ad33eu: goto P_0c0ad33e;
case 0x0c0ad340u: goto P_0c0ad340;
case 0x0c0ad342u: goto P_0c0ad342;
case 0x0c0ad344u: goto P_0c0ad344;
case 0x0c0ad346u: goto P_0c0ad346;
case 0x0c0ad348u: goto P_0c0ad348;
case 0x0c0ad34au: goto P_0c0ad34a;
case 0x0c0ad34cu: goto P_0c0ad34c;
case 0x0c0ad34eu: goto P_0c0ad34e;
case 0x0c0ad350u: goto P_0c0ad350;
case 0x0c0ad352u: goto P_0c0ad352;
case 0x0c0ad390u: goto P_0c0ad390;
case 0x0c0ad392u: goto P_0c0ad392;
case 0x0c0ad394u: goto P_0c0ad394;
case 0x0c0ad396u: goto P_0c0ad396;
case 0x0c0ad398u: goto P_0c0ad398;
case 0x0c0ad39au: goto P_0c0ad39a;
case 0x0c0ad39cu: goto P_0c0ad39c;
case 0x0c0ad39eu: goto P_0c0ad39e;
case 0x0c0ad3a0u: goto P_0c0ad3a0;
case 0x0c0ad3a2u: goto P_0c0ad3a2;
case 0x0c0ad3a4u: goto P_0c0ad3a4;
case 0x0c0ad3a6u: goto P_0c0ad3a6;
case 0x0c0ad3a8u: goto P_0c0ad3a8;
case 0x0c0ad3aau: goto P_0c0ad3aa;
case 0x0c0ad3acu: goto P_0c0ad3ac;
case 0x0c0ad3aeu: goto P_0c0ad3ae;
case 0x0c0ad3b0u: goto P_0c0ad3b0;
case 0x0c0ad3b2u: goto P_0c0ad3b2;
case 0x0c0ad3b4u: goto P_0c0ad3b4;
case 0x0c0ad3b6u: goto P_0c0ad3b6;
case 0x0c0ad3b8u: goto P_0c0ad3b8;
case 0x0c0ad3bau: goto P_0c0ad3ba;
case 0x0c0ad3bcu: goto P_0c0ad3bc;
case 0x0c0ad3beu: goto P_0c0ad3be;
case 0x0c0ad3c0u: goto P_0c0ad3c0;
case 0x0c0ad3c2u: goto P_0c0ad3c2;
case 0x0c0ad3c4u: goto P_0c0ad3c4;
case 0x0c0ad3c6u: goto P_0c0ad3c6;
case 0x0c0ad3c8u: goto P_0c0ad3c8;
case 0x0c0ad3cau: goto P_0c0ad3ca;
case 0x0c0ad3ccu: goto P_0c0ad3cc;
case 0x0c0ad3ceu: goto P_0c0ad3ce;
case 0x0c0ad3d0u: goto P_0c0ad3d0;
case 0x0c0ad3d2u: goto P_0c0ad3d2;
case 0x0c0ad3d4u: goto P_0c0ad3d4;
case 0x0c0ad3d6u: goto P_0c0ad3d6;
case 0x0c0ad3d8u: goto P_0c0ad3d8;
case 0x0c0ad3dau: goto P_0c0ad3da;
case 0x0c0ad3dcu: goto P_0c0ad3dc;
case 0x0c0ad3deu: goto P_0c0ad3de;
case 0x0c0ad3e0u: goto P_0c0ad3e0;
case 0x0c0ad3e2u: goto P_0c0ad3e2;
case 0x0c0ad3e4u: goto P_0c0ad3e4;
case 0x0c0ad3e6u: goto P_0c0ad3e6;
case 0x0c0ad3e8u: goto P_0c0ad3e8;
case 0x0c0ad3eau: goto P_0c0ad3ea;
case 0x0c0ad3ecu: goto P_0c0ad3ec;
case 0x0c0ad3eeu: goto P_0c0ad3ee;
case 0x0c0ad3f0u: goto P_0c0ad3f0;
case 0x0c0ad3f2u: goto P_0c0ad3f2;
case 0x0c0ad3f4u: goto P_0c0ad3f4;
case 0x0c0ad3f6u: goto P_0c0ad3f6;
case 0x0c0ad3f8u: goto P_0c0ad3f8;
case 0x0c0ad3fau: goto P_0c0ad3fa;
case 0x0c0ad3fcu: goto P_0c0ad3fc;
case 0x0c0ad3feu: goto P_0c0ad3fe;
case 0x0c0ad400u: goto P_0c0ad400;
case 0x0c0ad402u: goto P_0c0ad402;
case 0x0c0ad404u: goto P_0c0ad404;
case 0x0c0ad406u: goto P_0c0ad406;
case 0x0c0ad408u: goto P_0c0ad408;
case 0x0c0ad40au: goto P_0c0ad40a;
case 0x0c0ad40cu: goto P_0c0ad40c;
case 0x0c0ad40eu: goto P_0c0ad40e;
case 0x0c0ad410u: goto P_0c0ad410;
case 0x0c0ad412u: goto P_0c0ad412;
case 0x0c0ad414u: goto P_0c0ad414;
case 0x0c0ad416u: goto P_0c0ad416;
case 0x0c0ad418u: goto P_0c0ad418;
case 0x0c0ad41au: goto P_0c0ad41a;
case 0x0c0ad41cu: goto P_0c0ad41c;
case 0x0c0ad41eu: goto P_0c0ad41e;
case 0x0c0ad420u: goto P_0c0ad420;
case 0x0c0ad422u: goto P_0c0ad422;
case 0x0c0ad424u: goto P_0c0ad424;
case 0x0c0ad426u: goto P_0c0ad426;
case 0x0c0ad428u: goto P_0c0ad428;
case 0x0c0ad42au: goto P_0c0ad42a;
case 0x0c0ad42cu: goto P_0c0ad42c;
case 0x0c0ad42eu: goto P_0c0ad42e;
case 0x0c0ad430u: goto P_0c0ad430;
case 0x0c0ad432u: goto P_0c0ad432;
case 0x0c0ad434u: goto P_0c0ad434;
case 0x0c0ad436u: goto P_0c0ad436;
case 0x0c0ad438u: goto P_0c0ad438;
case 0x0c0ad43au: goto P_0c0ad43a;
case 0x0c0ad43cu: goto P_0c0ad43c;
case 0x0c0ad43eu: goto P_0c0ad43e;
case 0x0c0ad440u: goto P_0c0ad440;
case 0x0c0ad442u: goto P_0c0ad442;
case 0x0c0ad444u: goto P_0c0ad444;
case 0x0c0ad446u: goto P_0c0ad446;
case 0x0c0ad448u: goto P_0c0ad448;
case 0x0c0ad44au: goto P_0c0ad44a;
case 0x0c0ad44cu: goto P_0c0ad44c;
case 0x0c0ad44eu: goto P_0c0ad44e;
case 0x0c0ad450u: goto P_0c0ad450;
case 0x0c0ad452u: goto P_0c0ad452;
case 0x0c0ad454u: goto P_0c0ad454;
case 0x0c0ad456u: goto P_0c0ad456;
case 0x0c0ad458u: goto P_0c0ad458;
case 0x0c0ad45au: goto P_0c0ad45a;
case 0x0c0ad45cu: goto P_0c0ad45c;
case 0x0c0ad45eu: goto P_0c0ad45e;
case 0x0c0ad460u: goto P_0c0ad460;
case 0x0c0ad462u: goto P_0c0ad462;
case 0x0c0ad464u: goto P_0c0ad464;
case 0x0c0ad466u: goto P_0c0ad466;
case 0x0c0ad468u: goto P_0c0ad468;
case 0x0c0ad46au: goto P_0c0ad46a;
case 0x0c0ad46cu: goto P_0c0ad46c;
case 0x0c0ad46eu: goto P_0c0ad46e;
case 0x0c0ad470u: goto P_0c0ad470;
case 0x0c0ad472u: goto P_0c0ad472;
case 0x0c0ad474u: goto P_0c0ad474;
case 0x0c0ad476u: goto P_0c0ad476;
case 0x0c0ad478u: goto P_0c0ad478;
case 0x0c0ad47au: goto P_0c0ad47a;
case 0x0c0ad47cu: goto P_0c0ad47c;
case 0x0c0ad47eu: goto P_0c0ad47e;
case 0x0c0ad480u: goto P_0c0ad480;
case 0x0c0ad482u: goto P_0c0ad482;
case 0x0c0ad484u: goto P_0c0ad484;
case 0x0c0ad486u: goto P_0c0ad486;
case 0x0c0ad488u: goto P_0c0ad488;
case 0x0c0ad48au: goto P_0c0ad48a;
case 0x0c0ad48cu: goto P_0c0ad48c;
case 0x0c0ad48eu: goto P_0c0ad48e;
case 0x0c0ad490u: goto P_0c0ad490;
case 0x0c0ad492u: goto P_0c0ad492;
case 0x0c0ad494u: goto P_0c0ad494;
case 0x0c0ad496u: goto P_0c0ad496;
case 0x0c0ad498u: goto P_0c0ad498;
case 0x0c0ad49au: goto P_0c0ad49a;
case 0x0c0ad49cu: goto P_0c0ad49c;
case 0x0c0ad49eu: goto P_0c0ad49e;
case 0x0c0ad4a0u: goto P_0c0ad4a0;
case 0x0c0ad4a2u: goto P_0c0ad4a2;
case 0x0c0ad4a4u: goto P_0c0ad4a4;
case 0x0c0ad4a6u: goto P_0c0ad4a6;
case 0x0c0ad4a8u: goto P_0c0ad4a8;
case 0x0c0ad4aau: goto P_0c0ad4aa;
case 0x0c0ad4acu: goto P_0c0ad4ac;
case 0x0c0ad4aeu: goto P_0c0ad4ae;
case 0x0c0ad4b0u: goto P_0c0ad4b0;
case 0x0c0ad4b2u: goto P_0c0ad4b2;
case 0x0c0ad4b4u: goto P_0c0ad4b4;
case 0x0c0ad4b6u: goto P_0c0ad4b6;
case 0x0c0ad4b8u: goto P_0c0ad4b8;
case 0x0c0ad4bau: goto P_0c0ad4ba;
case 0x0c0ad4bcu: goto P_0c0ad4bc;
case 0x0c0ad4beu: goto P_0c0ad4be;
case 0x0c0ad4c0u: goto P_0c0ad4c0;
case 0x0c0ad4c2u: goto P_0c0ad4c2;
case 0x0c0ad4c4u: goto P_0c0ad4c4;
case 0x0c0ad4c6u: goto P_0c0ad4c6;
case 0x0c0ad4c8u: goto P_0c0ad4c8;
case 0x0c0ad4cau: goto P_0c0ad4ca;
case 0x0c0ad4ccu: goto P_0c0ad4cc;
case 0x0c0ad4ceu: goto P_0c0ad4ce;
case 0x0c0ad4d0u: goto P_0c0ad4d0;
case 0x0c0ad4d2u: goto P_0c0ad4d2;
case 0x0c0ad4d4u: goto P_0c0ad4d4;
case 0x0c0ad4d6u: goto P_0c0ad4d6;
case 0x0c0ad4d8u: goto P_0c0ad4d8;
case 0x0c0ad4dau: goto P_0c0ad4da;
case 0x0c0ad4dcu: goto P_0c0ad4dc;
case 0x0c0ad524u: goto P_0c0ad524;
case 0x0c0ad526u: goto P_0c0ad526;
case 0x0c0ad528u: goto P_0c0ad528;
case 0x0c0ad52au: goto P_0c0ad52a;
case 0x0c0ad52cu: goto P_0c0ad52c;
case 0x0c0ad52eu: goto P_0c0ad52e;
case 0x0c0ad530u: goto P_0c0ad530;
case 0x0c0ad532u: goto P_0c0ad532;
case 0x0c0ad534u: goto P_0c0ad534;
case 0x0c0ad536u: goto P_0c0ad536;
case 0x0c0ad538u: goto P_0c0ad538;
case 0x0c0ad53au: goto P_0c0ad53a;
case 0x0c0ad53cu: goto P_0c0ad53c;
case 0x0c0ad53eu: goto P_0c0ad53e;
case 0x0c0ad540u: goto P_0c0ad540;
case 0x0c0ad542u: goto P_0c0ad542;
case 0x0c0ad544u: goto P_0c0ad544;
case 0x0c0ad546u: goto P_0c0ad546;
case 0x0c0ad548u: goto P_0c0ad548;
case 0x0c0ad54au: goto P_0c0ad54a;
case 0x0c0ad54cu: goto P_0c0ad54c;
case 0x0c0ad54eu: goto P_0c0ad54e;
case 0x0c0ad550u: goto P_0c0ad550;
case 0x0c0ad552u: goto P_0c0ad552;
case 0x0c0ad554u: goto P_0c0ad554;
case 0x0c0ad556u: goto P_0c0ad556;
case 0x0c0ad558u: goto P_0c0ad558;
case 0x0c0ad55au: goto P_0c0ad55a;
case 0x0c0ad55cu: goto P_0c0ad55c;
case 0x0c0ad55eu: goto P_0c0ad55e;
case 0x0c0ad560u: goto P_0c0ad560;
case 0x0c0ad562u: goto P_0c0ad562;
case 0x0c0ad564u: goto P_0c0ad564;
case 0x0c0ad566u: goto P_0c0ad566;
case 0x0c0ad568u: goto P_0c0ad568;
case 0x0c0ad56au: goto P_0c0ad56a;
case 0x0c0ad56cu: goto P_0c0ad56c;
case 0x0c0ad56eu: goto P_0c0ad56e;
case 0x0c0ad570u: goto P_0c0ad570;
case 0x0c0ad572u: goto P_0c0ad572;
case 0x0c0ad574u: goto P_0c0ad574;
case 0x0c0ad576u: goto P_0c0ad576;
case 0x0c0ad578u: goto P_0c0ad578;
case 0x0c0ad57au: goto P_0c0ad57a;
case 0x0c0ad57cu: goto P_0c0ad57c;
case 0x0c0ad57eu: goto P_0c0ad57e;
case 0x0c0ad580u: goto P_0c0ad580;
case 0x0c0ad582u: goto P_0c0ad582;
case 0x0c0ad584u: goto P_0c0ad584;
case 0x0c0ad586u: goto P_0c0ad586;
case 0x0c0ad588u: goto P_0c0ad588;
case 0x0c0ca338u: goto P_0c0ca338;
case 0x0c0ca33au: goto P_0c0ca33a;
case 0x0c0ca33cu: goto P_0c0ca33c;
case 0x0c0ca33eu: goto P_0c0ca33e;
case 0x0c0ca340u: goto P_0c0ca340;
case 0x0c0ca342u: goto P_0c0ca342;
case 0x0c0ca344u: goto P_0c0ca344;
case 0x0c0ca346u: goto P_0c0ca346;
case 0x0c0ca348u: goto P_0c0ca348;
case 0x0c0ca34au: goto P_0c0ca34a;
case 0x0c0ca34cu: goto P_0c0ca34c;
case 0x0c0ca34eu: goto P_0c0ca34e;
case 0x0c0ca350u: goto P_0c0ca350;
case 0x0c0ca352u: goto P_0c0ca352;
case 0x0c0ca354u: goto P_0c0ca354;
case 0x0c0ca356u: goto P_0c0ca356;
case 0x0c0ca358u: goto P_0c0ca358;
case 0x0c0ca35au: goto P_0c0ca35a;
case 0x0c0ca35cu: goto P_0c0ca35c;
case 0x0c0ca35eu: goto P_0c0ca35e;
case 0x0c0ca360u: goto P_0c0ca360;
case 0x0c0ca362u: goto P_0c0ca362;
case 0x0c0ca364u: goto P_0c0ca364;
case 0x0c0ca366u: goto P_0c0ca366;
case 0x0c0ca368u: goto P_0c0ca368;
case 0x0c0ca36au: goto P_0c0ca36a;
case 0x0c0ca36cu: goto P_0c0ca36c;
case 0x0c0ca36eu: goto P_0c0ca36e;
case 0x0c0ca370u: goto P_0c0ca370;
case 0x0c0ca372u: goto P_0c0ca372;
case 0x0c0ca374u: goto P_0c0ca374;
case 0x0c0ca376u: goto P_0c0ca376;
case 0x0c0ca378u: goto P_0c0ca378;
case 0x0c0ca37au: goto P_0c0ca37a;
case 0x0c0ca37cu: goto P_0c0ca37c;
case 0x0c0ca37eu: goto P_0c0ca37e;
case 0x0c0ca380u: goto P_0c0ca380;
case 0x0c0ca382u: goto P_0c0ca382;
case 0x0c0ca384u: goto P_0c0ca384;
case 0x0c0ca386u: goto P_0c0ca386;
case 0x0c0ca388u: goto P_0c0ca388;
case 0x0c0ca38au: goto P_0c0ca38a;
case 0x0c0ca38cu: goto P_0c0ca38c;
case 0x0c0ca38eu: goto P_0c0ca38e;
case 0x0c0ca390u: goto P_0c0ca390;
case 0x0c0ca392u: goto P_0c0ca392;
case 0x0c0ca394u: goto P_0c0ca394;
case 0x0c0ca396u: goto P_0c0ca396;
case 0x0c0ca398u: goto P_0c0ca398;
case 0x0c0ca39au: goto P_0c0ca39a;
case 0x0c0ca39cu: goto P_0c0ca39c;
case 0x0c0ca39eu: goto P_0c0ca39e;
case 0x0c0ca3a0u: goto P_0c0ca3a0;
case 0x0c0ca3a2u: goto P_0c0ca3a2;
case 0x0c0ca3a4u: goto P_0c0ca3a4;
case 0x0c0ca3a6u: goto P_0c0ca3a6;
case 0x0c0ca3a8u: goto P_0c0ca3a8;
case 0x0c0ca3aau: goto P_0c0ca3aa;
case 0x0c0ca3acu: goto P_0c0ca3ac;
case 0x0c0ca3aeu: goto P_0c0ca3ae;
case 0x0c0ca3b0u: goto P_0c0ca3b0;
case 0x0c0ca3b2u: goto P_0c0ca3b2;
case 0x0c0ca3b4u: goto P_0c0ca3b4;
case 0x0c0ca3b6u: goto P_0c0ca3b6;
case 0x0c0ca3b8u: goto P_0c0ca3b8;
case 0x0c0ca3bau: goto P_0c0ca3ba;
case 0x0c0ca3bcu: goto P_0c0ca3bc;
case 0x0c0ca3beu: goto P_0c0ca3be;
case 0x0c0ca3c0u: goto P_0c0ca3c0;
case 0x0c0ca3c2u: goto P_0c0ca3c2;
case 0x0c0ca3c4u: goto P_0c0ca3c4;
case 0x0c0ca3c6u: goto P_0c0ca3c6;
case 0x0c0ca3c8u: goto P_0c0ca3c8;
case 0x0c0ca3cau: goto P_0c0ca3ca;
case 0x0c0ca3ccu: goto P_0c0ca3cc;
case 0x0c0ca3ceu: goto P_0c0ca3ce;
case 0x0c0ca3d0u: goto P_0c0ca3d0;
case 0x0c0ca3d2u: goto P_0c0ca3d2;
case 0x0c0ca3d4u: goto P_0c0ca3d4;
case 0x0c0ca3d6u: goto P_0c0ca3d6;
case 0x0c0ca3d8u: goto P_0c0ca3d8;
case 0x0c0ca3dau: goto P_0c0ca3da;
case 0x0c0ca3dcu: goto P_0c0ca3dc;
case 0x0c0ca3deu: goto P_0c0ca3de;
case 0x0c0ca3e0u: goto P_0c0ca3e0;
case 0x0c0ca3e2u: goto P_0c0ca3e2;
case 0x0c0ca3e4u: goto P_0c0ca3e4;
case 0x0c0ca3e6u: goto P_0c0ca3e6;
case 0x0c0ca3e8u: goto P_0c0ca3e8;
case 0x0c0ca3eau: goto P_0c0ca3ea;
case 0x0c0ca3ecu: goto P_0c0ca3ec;
case 0x0c0ca3eeu: goto P_0c0ca3ee;
case 0x0c0ca3f0u: goto P_0c0ca3f0;
case 0x0c0ca3f2u: goto P_0c0ca3f2;
case 0x0c0ca3f4u: goto P_0c0ca3f4;
case 0x0c0ca3f6u: goto P_0c0ca3f6;
case 0x0c0ca3f8u: goto P_0c0ca3f8;
case 0x0c0ca3fau: goto P_0c0ca3fa;
case 0x0c0ca3fcu: goto P_0c0ca3fc;
case 0x0c0ca3feu: goto P_0c0ca3fe;
case 0x0c0ca400u: goto P_0c0ca400;
case 0x0c0ca402u: goto P_0c0ca402;
case 0x0c0ca404u: goto P_0c0ca404;
case 0x0c0ca406u: goto P_0c0ca406;
case 0x0c0ca408u: goto P_0c0ca408;
case 0x0c0ca40au: goto P_0c0ca40a;
case 0x0c0ca40cu: goto P_0c0ca40c;
case 0x0c0ca40eu: goto P_0c0ca40e;
case 0x0c0ca410u: goto P_0c0ca410;
case 0x0c0ca412u: goto P_0c0ca412;
case 0x0c0ca414u: goto P_0c0ca414;
case 0x0c0ca416u: goto P_0c0ca416;
case 0x0c0ca418u: goto P_0c0ca418;
case 0x0c0ca41au: goto P_0c0ca41a;
case 0x0c0ca41cu: goto P_0c0ca41c;
case 0x0c0ca41eu: goto P_0c0ca41e;
case 0x0c0ca420u: goto P_0c0ca420;
case 0x0c0ca422u: goto P_0c0ca422;
case 0x0c0ca424u: goto P_0c0ca424;
case 0x0c0ca448u: goto P_0c0ca448;
case 0x0c0ca44au: goto P_0c0ca44a;
case 0x0c0ca44cu: goto P_0c0ca44c;
case 0x0c0ca44eu: goto P_0c0ca44e;
case 0x0c0ca450u: goto P_0c0ca450;
case 0x0c0ca452u: goto P_0c0ca452;
case 0x0c0ca454u: goto P_0c0ca454;
case 0x0c0ca456u: goto P_0c0ca456;
case 0x0c0ca458u: goto P_0c0ca458;
case 0x0c0ca45au: goto P_0c0ca45a;
case 0x0c0ca45cu: goto P_0c0ca45c;
case 0x0c0ca45eu: goto P_0c0ca45e;
case 0x0c0ca460u: goto P_0c0ca460;
case 0x0c0ca462u: goto P_0c0ca462;
case 0x0c0ca464u: goto P_0c0ca464;
case 0x0c0ca466u: goto P_0c0ca466;
case 0x0c0ca468u: goto P_0c0ca468;
case 0x0c0ca46au: goto P_0c0ca46a;
case 0x0c0ca46cu: goto P_0c0ca46c;
case 0x0c0ca46eu: goto P_0c0ca46e;
case 0x0c0ca470u: goto P_0c0ca470;
case 0x0c0ca472u: goto P_0c0ca472;
case 0x0c0ca474u: goto P_0c0ca474;
case 0x0c0ca476u: goto P_0c0ca476;
case 0x0c0ca478u: goto P_0c0ca478;
case 0x0c0ca47au: goto P_0c0ca47a;
case 0x0c0ca47cu: goto P_0c0ca47c;
case 0x0c0ca47eu: goto P_0c0ca47e;
case 0x0c0ca480u: goto P_0c0ca480;
case 0x0c0ca482u: goto P_0c0ca482;
case 0x0c0ca484u: goto P_0c0ca484;
case 0x0c0ca486u: goto P_0c0ca486;
case 0x0c0ca488u: goto P_0c0ca488;
case 0x0c0ca48au: goto P_0c0ca48a;
case 0x0c0ca48cu: goto P_0c0ca48c;
case 0x0c0ca48eu: goto P_0c0ca48e;
case 0x0c0ca490u: goto P_0c0ca490;
case 0x0c0ca492u: goto P_0c0ca492;
case 0x0c0ca494u: goto P_0c0ca494;
case 0x0c0ca496u: goto P_0c0ca496;
case 0x0c0ca498u: goto P_0c0ca498;
case 0x0c0ca49au: goto P_0c0ca49a;
case 0x0c0ca49cu: goto P_0c0ca49c;
case 0x0c0ca49eu: goto P_0c0ca49e;
case 0x0c0ca4a0u: goto P_0c0ca4a0;
case 0x0c0ca4a2u: goto P_0c0ca4a2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03a158u,s,ram);
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=0x0c03a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=0x0c03a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=0x0c03a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=0x0c03a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=0x0c03a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
return vf3_matrix_family(0x0c03a74cu,s,ram);
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
return vf3_matrix_family(0x0c03a758u,s,ram);
P_0c03b450: /* original f449, guest PC 0x0c03b450 */
if(!s->budget--) { s->failed_pc=0x0c03b450u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03b452;
P_0c03b452: /* original f549, guest PC 0x0c03b452 */
if(!s->budget--) { s->failed_pc=0x0c03b452u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03b454;
P_0c03b454: /* original f649, guest PC 0x0c03b454 */
if(!s->budget--) { s->failed_pc=0x0c03b454u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03b456;
P_0c03b456: /* original f79d, guest PC 0x0c03b456 */
if(!s->budget--) { s->failed_pc=0x0c03b456u; return 0; }
fr[7]=0x3f800000u;
goto P_0c03b458;
P_0c03b458: /* original f5fd, guest PC 0x0c03b458 */
if(!s->budget--) { s->failed_pc=0x0c03b458u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03b45a;
P_0c03b45a: /* original 750c, guest PC 0x0c03b45a */
if(!s->budget--) { s->failed_pc=0x0c03b45au; return 0; }
r[5]+=0x0000000cu;
goto P_0c03b45c;
P_0c03b45c: /* original f56b, guest PC 0x0c03b45c */
if(!s->budget--) { s->failed_pc=0x0c03b45cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c03b45e;
P_0c03b45e: /* original f55b, guest PC 0x0c03b45e */
if(!s->budget--) { s->failed_pc=0x0c03b45eu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c03b460;
P_0c03b460: /* original f54b, guest PC 0x0c03b460 */
if(!s->budget--) { s->failed_pc=0x0c03b460u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c03b462;
P_0c03b462: /* original 0009, guest PC 0x0c03b462 */
if(!s->budget--) { s->failed_pc=0x0c03b462u; return 0; }
goto P_0c03b464;
P_0c03b464: /* original 000b, guest PC 0x0c03b464 */
if(!s->budget--) { s->failed_pc=0x0c03b464u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03b466: /* original 0009, guest PC 0x0c03b466 */
if(!s->budget--) { s->failed_pc=0x0c03b466u; return 0; }
return vf3_matrix_family(0x0c03b468u,s,ram);
P_0c069624: /* original f38d, guest PC 0x0c069624 */
if(!s->budget--) { s->failed_pc=0x0c069624u; return 0; }
fr[3]=0;
goto P_0c069626;
P_0c069626: /* original f534, guest PC 0x0c069626 */
if(!s->budget--) { s->failed_pc=0x0c069626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c069628;
P_0c069628: /* original 8b03, guest PC 0x0c069628 */
if(!s->budget--) { s->failed_pc=0x0c069628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962a;
P_0c06962a: /* original f434, guest PC 0x0c06962a */
if(!s->budget--) { s->failed_pc=0x0c06962au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06962c;
P_0c06962c: /* original 8b01, guest PC 0x0c06962c */
if(!s->budget--) { s->failed_pc=0x0c06962cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962e;
P_0c06962e: /* original 000b, guest PC 0x0c06962e */
if(!s->budget--) { s->failed_pc=0x0c06962eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c069630: /* original e000, guest PC 0x0c069630 */
if(!s->budget--) { s->failed_pc=0x0c069630u; return 0; }
r[0]=0x00000000u;
goto P_0c069632;
P_0c069632: /* original f38d, guest PC 0x0c069632 */
if(!s->budget--) { s->failed_pc=0x0c069632u; return 0; }
fr[3]=0;
goto P_0c069634;
P_0c069634: /* original f355, guest PC 0x0c069634 */
if(!s->budget--) { s->failed_pc=0x0c069634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c069636;
P_0c069636: /* original 8f03, guest PC 0x0c069636 */
if(!s->budget--) { s->failed_pc=0x0c069636u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c069640; }
goto P_0c06963a;
P_0c069638: /* original f38d, guest PC 0x0c069638 */
if(!s->budget--) { s->failed_pc=0x0c069638u; return 0; }
fr[3]=0;
goto P_0c06963a;
P_0c06963a: /* original f65c, guest PC 0x0c06963a */
if(!s->budget--) { s->failed_pc=0x0c06963au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c06963c;
P_0c06963c: /* original a001, guest PC 0x0c06963c */
if(!s->budget--) { s->failed_pc=0x0c06963cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069642;
P_0c06963e: /* original f64d, guest PC 0x0c06963e */
if(!s->budget--) { s->failed_pc=0x0c06963eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069640;
P_0c069640: /* original f65c, guest PC 0x0c069640 */
if(!s->budget--) { s->failed_pc=0x0c069640u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c069642;
P_0c069642: /* original f345, guest PC 0x0c069642 */
if(!s->budget--) { s->failed_pc=0x0c069642u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069644;
P_0c069644: /* original 8b02, guest PC 0x0c069644 */
if(!s->budget--) { s->failed_pc=0x0c069644u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06964c; }
goto P_0c069646;
P_0c069646: /* original f74c, guest PC 0x0c069646 */
if(!s->budget--) { s->failed_pc=0x0c069646u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069648;
P_0c069648: /* original a001, guest PC 0x0c069648 */
if(!s->budget--) { s->failed_pc=0x0c069648u; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964e;
P_0c06964a: /* original f74d, guest PC 0x0c06964a */
if(!s->budget--) { s->failed_pc=0x0c06964au; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964c;
P_0c06964c: /* original f74c, guest PC 0x0c06964c */
if(!s->budget--) { s->failed_pc=0x0c06964cu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06964e;
P_0c06964e: /* original f675, guest PC 0x0c06964e */
if(!s->budget--) { s->failed_pc=0x0c06964eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c069650;
P_0c069650: /* original 8b02, guest PC 0x0c069650 */
if(!s->budget--) { s->failed_pc=0x0c069650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069658; }
goto P_0c069652;
P_0c069652: /* original f87c, guest PC 0x0c069652 */
if(!s->budget--) { s->failed_pc=0x0c069652u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c069654;
P_0c069654: /* original a002, guest PC 0x0c069654 */
if(!s->budget--) { s->failed_pc=0x0c069654u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c06965c;
P_0c069656: /* original f863, guest PC 0x0c069656 */
if(!s->budget--) { s->failed_pc=0x0c069656u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c069658;
P_0c069658: /* original f86c, guest PC 0x0c069658 */
if(!s->budget--) { s->failed_pc=0x0c069658u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06965a;
P_0c06965a: /* original f873, guest PC 0x0c06965a */
if(!s->budget--) { s->failed_pc=0x0c06965au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'/');
goto P_0c06965c;
P_0c06965c: /* original c711, guest PC 0x0c06965c */
if(!s->budget--) { s->failed_pc=0x0c06965cu; return 0; }
r[0]=0x0c0696a4u;
goto P_0c06965e;
P_0c06965e: /* original f28c, guest PC 0x0c06965e */
if(!s->budget--) { s->failed_pc=0x0c06965eu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c069660;
P_0c069660: /* original f308, guest PC 0x0c069660 */
if(!s->budget--) { s->failed_pc=0x0c069660u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069662;
P_0c069662: /* original d011, guest PC 0x0c069662 */
if(!s->budget--) { s->failed_pc=0x0c069662u; return 0; }
r[0]=read(ram,0x0c0696a8u,4);
goto P_0c069664;
P_0c069664: /* original f232, guest PC 0x0c069664 */
if(!s->budget--) { s->failed_pc=0x0c069664u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c069666;
P_0c069666: /* original f23d, guest PC 0x0c069666 */
if(!s->budget--) { s->failed_pc=0x0c069666u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c069668;
P_0c069668: /* original 045a, guest PC 0x0c069668 */
if(!s->budget--) { s->failed_pc=0x0c069668u; return 0; }
r[4]=r[53];
goto P_0c06966a;
P_0c06966a: /* original 4400, guest PC 0x0c06966a */
if(!s->budget--) { s->failed_pc=0x0c06966au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06966c;
P_0c06966c: /* original f765, guest PC 0x0c06966c */
if(!s->budget--) { s->failed_pc=0x0c06966cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c06966e;
P_0c06966e: /* original 8f03, guest PC 0x0c06966e */
if(!s->budget--) { s->failed_pc=0x0c06966eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!cond) { goto P_0c069678; }
goto P_0c069672;
P_0c069670: /* original 044d, guest PC 0x0c069670 */
if(!s->budget--) { s->failed_pc=0x0c069670u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c069672;
P_0c069672: /* original 9214, guest PC 0x0c069672 */
if(!s->budget--) { s->failed_pc=0x0c069672u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06969eu,2);
goto P_0c069674;
P_0c069674: /* original 3248, guest PC 0x0c069674 */
if(!s->budget--) { s->failed_pc=0x0c069674u; return 0; }
r[2]-=r[4];
goto P_0c069676;
P_0c069676: /* original 6423, guest PC 0x0c069676 */
if(!s->budget--) { s->failed_pc=0x0c069676u; return 0; }
r[4]=r[2];
goto P_0c069678;
P_0c069678: /* original f38d, guest PC 0x0c069678 */
if(!s->budget--) { s->failed_pc=0x0c069678u; return 0; }
fr[3]=0;
goto P_0c06967a;
P_0c06967a: /* original f355, guest PC 0x0c06967a */
if(!s->budget--) { s->failed_pc=0x0c06967au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c06967c;
P_0c06967c: /* original 8904, guest PC 0x0c06967c */
if(!s->budget--) { s->failed_pc=0x0c06967cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069688; }
goto P_0c06967e;
P_0c06967e: /* original f38d, guest PC 0x0c06967e */
if(!s->budget--) { s->failed_pc=0x0c06967eu; return 0; }
fr[3]=0;
goto P_0c069680;
P_0c069680: /* original f345, guest PC 0x0c069680 */
if(!s->budget--) { s->failed_pc=0x0c069680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069682;
P_0c069682: /* original 8b09, guest PC 0x0c069682 */
if(!s->budget--) { s->failed_pc=0x0c069682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069698; }
goto P_0c069684;
P_0c069684: /* original a008, guest PC 0x0c069684 */
if(!s->budget--) { s->failed_pc=0x0c069684u; return 0; }
r[4]=0u-r[4];
goto P_0c069698;
P_0c069686: /* original 644b, guest PC 0x0c069686 */
if(!s->budget--) { s->failed_pc=0x0c069686u; return 0; }
r[4]=0u-r[4];
goto P_0c069688;
P_0c069688: /* original f345, guest PC 0x0c069688 */
if(!s->budget--) { s->failed_pc=0x0c069688u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06968a;
P_0c06968a: /* original 8903, guest PC 0x0c06968a */
if(!s->budget--) { s->failed_pc=0x0c06968au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069694; }
goto P_0c06968c;
P_0c06968c: /* original d207, guest PC 0x0c06968c */
if(!s->budget--) { s->failed_pc=0x0c06968cu; return 0; }
r[2]=read(ram,0x0c0696acu,4);
goto P_0c06968e;
P_0c06968e: /* original 3248, guest PC 0x0c06968e */
if(!s->budget--) { s->failed_pc=0x0c06968eu; return 0; }
r[2]-=r[4];
goto P_0c069690;
P_0c069690: /* original a002, guest PC 0x0c069690 */
if(!s->budget--) { s->failed_pc=0x0c069690u; return 0; }
r[4]=r[2];
goto P_0c069698;
P_0c069692: /* original 6423, guest PC 0x0c069692 */
if(!s->budget--) { s->failed_pc=0x0c069692u; return 0; }
r[4]=r[2];
goto P_0c069694;
P_0c069694: /* original 9104, guest PC 0x0c069694 */
if(!s->budget--) { s->failed_pc=0x0c069694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0696a0u,2);
goto P_0c069696;
P_0c069696: /* original 341c, guest PC 0x0c069696 */
if(!s->budget--) { s->failed_pc=0x0c069696u; return 0; }
r[4]+=r[1];
goto P_0c069698;
P_0c069698: /* original 6043, guest PC 0x0c069698 */
if(!s->budget--) { s->failed_pc=0x0c069698u; return 0; }
r[0]=r[4];
goto P_0c06969a;
P_0c06969a: /* original 000b, guest PC 0x0c06969a */
if(!s->budget--) { s->failed_pc=0x0c06969au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06969c: /* original 0009, guest PC 0x0c06969c */
if(!s->budget--) { s->failed_pc=0x0c06969cu; return 0; }
return vf3_matrix_family(0x0c06969eu,s,ram);
P_0c06e8c4: /* original fffb, guest PC 0x0c06e8c4 */
if(!s->budget--) { s->failed_pc=0x0c06e8c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06e8c6;
P_0c06e8c6: /* original ffeb, guest PC 0x0c06e8c6 */
if(!s->budget--) { s->failed_pc=0x0c06e8c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06e8c8;
P_0c06e8c8: /* original ffdb, guest PC 0x0c06e8c8 */
if(!s->budget--) { s->failed_pc=0x0c06e8c8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06e8ca;
P_0c06e8ca: /* original ffcb, guest PC 0x0c06e8ca */
if(!s->budget--) { s->failed_pc=0x0c06e8cau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06e8cc;
P_0c06e8cc: /* original 4f22, guest PC 0x0c06e8cc */
if(!s->budget--) { s->failed_pc=0x0c06e8ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06e8ce;
P_0c06e8ce: /* original fe5c, guest PC 0x0c06e8ce */
if(!s->budget--) { s->failed_pc=0x0c06e8ceu; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c06e8d0;
P_0c06e8d0: /* original ff4c, guest PC 0x0c06e8d0 */
if(!s->budget--) { s->failed_pc=0x0c06e8d0u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c06e8d2;
P_0c06e8d2: /* original 7fd0, guest PC 0x0c06e8d2 */
if(!s->budget--) { s->failed_pc=0x0c06e8d2u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c06e8d4;
P_0c06e8d4: /* original 1f44, guest PC 0x0c06e8d4 */
if(!s->budget--) { s->failed_pc=0x0c06e8d4u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c06e8d6;
P_0c06e8d6: /* original e40f, guest PC 0x0c06e8d6 */
if(!s->budget--) { s->failed_pc=0x0c06e8d6u; return 0; }
r[4]=0x0000000fu;
goto P_0c06e8d8;
P_0c06e8d8: /* original 1f57, guest PC 0x0c06e8d8 */
if(!s->budget--) { s->failed_pc=0x0c06e8d8u; return 0; }
write(ram,r[15]+28,r[5],4);
goto P_0c06e8da;
P_0c06e8da: /* original 1f65, guest PC 0x0c06e8da */
if(!s->budget--) { s->failed_pc=0x0c06e8dau; return 0; }
write(ram,r[15]+20,r[6],4);
goto P_0c06e8dc;
P_0c06e8dc: /* original 1f76, guest PC 0x0c06e8dc */
if(!s->budget--) { s->failed_pc=0x0c06e8dcu; return 0; }
write(ram,r[15]+24,r[7],4);
goto P_0c06e8de;
P_0c06e8de: /* original d21d, guest PC 0x0c06e8de */
if(!s->budget--) { s->failed_pc=0x0c06e8deu; return 0; }
r[2]=read(ram,0x0c06e954u,4);
goto P_0c06e8e0;
P_0c06e8e0: /* original d31b, guest PC 0x0c06e8e0 */
if(!s->budget--) { s->failed_pc=0x0c06e8e0u; return 0; }
r[3]=read(ram,0x0c06e950u,4);
goto P_0c06e8e2;
P_0c06e8e2: /* original 6020, guest PC 0x0c06e8e2 */
if(!s->budget--) { s->failed_pc=0x0c06e8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c06e8e4;
P_0c06e8e4: /* original 600c, guest PC 0x0c06e8e4 */
if(!s->budget--) { s->failed_pc=0x0c06e8e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c06e8e6;
P_0c06e8e6: /* original 2409, guest PC 0x0c06e8e6 */
if(!s->budget--) { s->failed_pc=0x0c06e8e6u; return 0; }
r[4]&=r[0];
goto P_0c06e8e8;
P_0c06e8e8: /* original 6043, guest PC 0x0c06e8e8 */
if(!s->budget--) { s->failed_pc=0x0c06e8e8u; return 0; }
r[0]=r[4];
goto P_0c06e8ea;
P_0c06e8ea: /* original 880f, guest PC 0x0c06e8ea */
if(!s->budget--) { s->failed_pc=0x0c06e8eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c06e8ec;
P_0c06e8ec: /* original 8f15, guest PC 0x0c06e8ec */
if(!s->budget--) { s->failed_pc=0x0c06e8ecu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!cond) { goto P_0c06e91a; }
goto P_0c06e8f0;
P_0c06e8ee: /* original 6532, guest PC 0x0c06e8ee */
if(!s->budget--) { s->failed_pc=0x0c06e8eeu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06e8f0;
P_0c06e8f0: /* original f3fc, guest PC 0x0c06e8f0 */
if(!s->budget--) { s->failed_pc=0x0c06e8f0u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c06e8f2;
P_0c06e8f2: /* original f3f2, guest PC 0x0c06e8f2 */
if(!s->budget--) { s->failed_pc=0x0c06e8f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06e8f4;
P_0c06e8f4: /* original f0ec, guest PC 0x0c06e8f4 */
if(!s->budget--) { s->failed_pc=0x0c06e8f4u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c06e8f6;
P_0c06e8f6: /* original c718, guest PC 0x0c06e8f6 */
if(!s->budget--) { s->failed_pc=0x0c06e8f6u; return 0; }
r[0]=0x0c06e958u;
goto P_0c06e8f8;
P_0c06e8f8: /* original f508, guest PC 0x0c06e8f8 */
if(!s->budget--) { s->failed_pc=0x0c06e8f8u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06e8fa;
P_0c06e8fa: /* original c718, guest PC 0x0c06e8fa */
if(!s->budget--) { s->failed_pc=0x0c06e8fau; return 0; }
r[0]=0x0c06e95cu;
goto P_0c06e8fc;
P_0c06e8fc: /* original f208, guest PC 0x0c06e8fc */
if(!s->budget--) { s->failed_pc=0x0c06e8fcu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c06e8fe;
P_0c06e8fe: /* original f3ee, guest PC 0x0c06e8fe */
if(!s->budget--) { s->failed_pc=0x0c06e8feu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c06e900;
P_0c06e900: /* original f43c, guest PC 0x0c06e900 */
if(!s->budget--) { s->failed_pc=0x0c06e900u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e902;
P_0c06e902: /* original f245, guest PC 0x0c06e902 */
if(!s->budget--) { s->failed_pc=0x0c06e902u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06e904;
P_0c06e904: /* original 8f02, guest PC 0x0c06e904 */
if(!s->budget--) { s->failed_pc=0x0c06e904u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,15);
if(!cond) { goto P_0c06e90c; }
goto P_0c06e908;
P_0c06e906: /* original fdfc, guest PC 0x0c06e906 */
if(!s->budget--) { s->failed_pc=0x0c06e906u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c06e908;
P_0c06e908: /* original a001, guest PC 0x0c06e908 */
if(!s->budget--) { s->failed_pc=0x0c06e908u; return 0; }
fr[4]=0;
goto P_0c06e90e;
P_0c06e90a: /* original f48d, guest PC 0x0c06e90a */
if(!s->budget--) { s->failed_pc=0x0c06e90au; return 0; }
fr[4]=0;
goto P_0c06e90c;
P_0c06e90c: /* original f47d, guest PC 0x0c06e90c */
if(!s->budget--) { s->failed_pc=0x0c06e90cu; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c06e90e;
P_0c06e90e: /* original fd42, guest PC 0x0c06e90e */
if(!s->budget--) { s->failed_pc=0x0c06e90eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c06e910;
P_0c06e910: /* original fcec, guest PC 0x0c06e910 */
if(!s->budget--) { s->failed_pc=0x0c06e910u; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c06e912;
P_0c06e912: /* original fc42, guest PC 0x0c06e912 */
if(!s->budget--) { s->failed_pc=0x0c06e912u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
goto P_0c06e914;
P_0c06e914: /* original fd52, guest PC 0x0c06e914 */
if(!s->budget--) { s->failed_pc=0x0c06e914u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'*');
goto P_0c06e916;
P_0c06e916: /* original a083, guest PC 0x0c06e916 */
if(!s->budget--) { s->failed_pc=0x0c06e916u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[5],r[18],'*');
goto P_0c06ea20;
P_0c06e918: /* original fc52, guest PC 0x0c06e918 */
if(!s->budget--) { s->failed_pc=0x0c06e918u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[5],r[18],'*');
goto P_0c06e91a;
P_0c06e91a: /* original 9016, guest PC 0x0c06e91a */
if(!s->budget--) { s->failed_pc=0x0c06e91au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e94au,2);
goto P_0c06e91c;
P_0c06e91c: /* original f39d, guest PC 0x0c06e91c */
if(!s->budget--) { s->failed_pc=0x0c06e91cu; return 0; }
fr[3]=0x3f800000u;
goto P_0c06e91e;
P_0c06e91e: /* original 045e, guest PC 0x0c06e91e */
if(!s->budget--) { s->failed_pc=0x0c06e91eu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c06e920;
P_0c06e920: /* original c70f, guest PC 0x0c06e920 */
if(!s->budget--) { s->failed_pc=0x0c06e920u; return 0; }
r[0]=0x0c06e960u;
goto P_0c06e922;
P_0c06e922: /* original f908, guest PC 0x0c06e922 */
if(!s->budget--) { s->failed_pc=0x0c06e922u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c06e924;
P_0c06e924: /* original e020, guest PC 0x0c06e924 */
if(!s->budget--) { s->failed_pc=0x0c06e924u; return 0; }
r[0]=0x00000020u;
goto P_0c06e926;
P_0c06e926: /* original f48d, guest PC 0x0c06e926 */
if(!s->budget--) { s->failed_pc=0x0c06e926u; return 0; }
fr[4]=0;
goto P_0c06e928;
P_0c06e928: /* original fc4c, guest PC 0x0c06e928 */
if(!s->budget--) { s->failed_pc=0x0c06e928u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c06e92a;
P_0c06e92a: /* original fd4c, guest PC 0x0c06e92a */
if(!s->budget--) { s->failed_pc=0x0c06e92au; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c06e92c;
P_0c06e92c: /* original ff37, guest PC 0x0c06e92c */
if(!s->budget--) { s->failed_pc=0x0c06e92cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e92e;
P_0c06e92e: /* original e02c, guest PC 0x0c06e92e */
if(!s->budget--) { s->failed_pc=0x0c06e92eu; return 0; }
r[0]=0x0000002cu;
goto P_0c06e930;
P_0c06e930: /* original 6546, guest PC 0x0c06e930 */
if(!s->budget--) { s->failed_pc=0x0c06e930u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[5]=tmp;
goto P_0c06e932;
P_0c06e932: /* original f649, guest PC 0x0c06e932 */
if(!s->budget--) { s->failed_pc=0x0c06e932u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e934;
P_0c06e934: /* original f549, guest PC 0x0c06e934 */
if(!s->budget--) { s->failed_pc=0x0c06e934u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e936;
P_0c06e936: /* original f349, guest PC 0x0c06e936 */
if(!s->budget--) { s->failed_pc=0x0c06e936u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e938;
P_0c06e938: /* original ff37, guest PC 0x0c06e938 */
if(!s->budget--) { s->failed_pc=0x0c06e938u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e93a;
P_0c06e93a: /* original e028, guest PC 0x0c06e93a */
if(!s->budget--) { s->failed_pc=0x0c06e93au; return 0; }
r[0]=0x00000028u;
goto P_0c06e93c;
P_0c06e93c: /* original f349, guest PC 0x0c06e93c */
if(!s->budget--) { s->failed_pc=0x0c06e93cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e93e;
P_0c06e93e: /* original a06d, guest PC 0x0c06e93e */
if(!s->budget--) { s->failed_pc=0x0c06e93eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06ea1c;
P_0c06e940: /* original ff37, guest PC 0x0c06e940 */
if(!s->budget--) { s->failed_pc=0x0c06e940u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
return vf3_matrix_family(0x0c06e942u,s,ram);
P_0c06e964: /* original e02c, guest PC 0x0c06e964 */
if(!s->budget--) { s->failed_pc=0x0c06e964u; return 0; }
r[0]=0x0000002cu;
goto P_0c06e966;
P_0c06e966: /* original fb6c, guest PC 0x0c06e966 */
if(!s->budget--) { s->failed_pc=0x0c06e966u; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c06e968;
P_0c06e968: /* original f6f6, guest PC 0x0c06e968 */
if(!s->budget--) { s->failed_pc=0x0c06e968u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c06e96a;
P_0c06e96a: /* original e028, guest PC 0x0c06e96a */
if(!s->budget--) { s->failed_pc=0x0c06e96au; return 0; }
r[0]=0x00000028u;
goto P_0c06e96c;
P_0c06e96c: /* original f4fc, guest PC 0x0c06e96c */
if(!s->budget--) { s->failed_pc=0x0c06e96cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06e96e;
P_0c06e96e: /* original f4b1, guest PC 0x0c06e96e */
if(!s->budget--) { s->failed_pc=0x0c06e96eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'-');
goto P_0c06e970;
P_0c06e970: /* original f86c, guest PC 0x0c06e970 */
if(!s->budget--) { s->failed_pc=0x0c06e970u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06e972;
P_0c06e972: /* original f8b1, guest PC 0x0c06e972 */
if(!s->budget--) { s->failed_pc=0x0c06e972u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'-');
goto P_0c06e974;
P_0c06e974: /* original fa5c, guest PC 0x0c06e974 */
if(!s->budget--) { s->failed_pc=0x0c06e974u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c06e976;
P_0c06e976: /* original f5f6, guest PC 0x0c06e976 */
if(!s->budget--) { s->failed_pc=0x0c06e976u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c06e978;
P_0c06e978: /* original e024, guest PC 0x0c06e978 */
if(!s->budget--) { s->failed_pc=0x0c06e978u; return 0; }
r[0]=0x00000024u;
goto P_0c06e97a;
P_0c06e97a: /* original f3ec, guest PC 0x0c06e97a */
if(!s->budget--) { s->failed_pc=0x0c06e97au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c06e97c;
P_0c06e97c: /* original f3a1, guest PC 0x0c06e97c */
if(!s->budget--) { s->failed_pc=0x0c06e97cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c06e97e;
P_0c06e97e: /* original f75c, guest PC 0x0c06e97e */
if(!s->budget--) { s->failed_pc=0x0c06e97eu; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c06e980;
P_0c06e980: /* original f7a1, guest PC 0x0c06e980 */
if(!s->budget--) { s->failed_pc=0x0c06e980u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c06e982;
P_0c06e982: /* original ff37, guest PC 0x0c06e982 */
if(!s->budget--) { s->failed_pc=0x0c06e982u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e984;
P_0c06e984: /* original e00c, guest PC 0x0c06e984 */
if(!s->budget--) { s->failed_pc=0x0c06e984u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e986;
P_0c06e986: /* original f24c, guest PC 0x0c06e986 */
if(!s->budget--) { s->failed_pc=0x0c06e986u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06e988;
P_0c06e988: /* original f48c, guest PC 0x0c06e988 */
if(!s->budget--) { s->failed_pc=0x0c06e988u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c06e98a;
P_0c06e98a: /* original f422, guest PC 0x0c06e98a */
if(!s->budget--) { s->failed_pc=0x0c06e98au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c06e98c;
P_0c06e98c: /* original f07c, guest PC 0x0c06e98c */
if(!s->budget--) { s->failed_pc=0x0c06e98cu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06e98e;
P_0c06e98e: /* original f14c, guest PC 0x0c06e98e */
if(!s->budget--) { s->failed_pc=0x0c06e98eu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c06e990;
P_0c06e990: /* original f13e, guest PC 0x0c06e990 */
if(!s->budget--) { s->failed_pc=0x0c06e990u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c06e992;
P_0c06e992: /* original f38c, guest PC 0x0c06e992 */
if(!s->budget--) { s->failed_pc=0x0c06e992u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c06e994;
P_0c06e994: /* original f382, guest PC 0x0c06e994 */
if(!s->budget--) { s->failed_pc=0x0c06e994u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c06e996;
P_0c06e996: /* original f41c, guest PC 0x0c06e996 */
if(!s->budget--) { s->failed_pc=0x0c06e996u; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c06e998;
P_0c06e998: /* original f37e, guest PC 0x0c06e998 */
if(!s->budget--) { s->failed_pc=0x0c06e998u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c06e99a;
P_0c06e99a: /* original f433, guest PC 0x0c06e99a */
if(!s->budget--) { s->failed_pc=0x0c06e99au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c06e99c;
P_0c06e99c: /* original ff37, guest PC 0x0c06e99c */
if(!s->budget--) { s->failed_pc=0x0c06e99cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e99e;
P_0c06e99e: /* original f249, guest PC 0x0c06e99e */
if(!s->budget--) { s->failed_pc=0x0c06e99eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e9a0;
P_0c06e9a0: /* original e02c, guest PC 0x0c06e9a0 */
if(!s->budget--) { s->failed_pc=0x0c06e9a0u; return 0; }
r[0]=0x0000002cu;
goto P_0c06e9a2;
P_0c06e9a2: /* original ff27, guest PC 0x0c06e9a2 */
if(!s->budget--) { s->failed_pc=0x0c06e9a2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e9a4;
P_0c06e9a4: /* original f249, guest PC 0x0c06e9a4 */
if(!s->budget--) { s->failed_pc=0x0c06e9a4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e9a6;
P_0c06e9a6: /* original e028, guest PC 0x0c06e9a6 */
if(!s->budget--) { s->failed_pc=0x0c06e9a6u; return 0; }
r[0]=0x00000028u;
goto P_0c06e9a8;
P_0c06e9a8: /* original ff27, guest PC 0x0c06e9a8 */
if(!s->budget--) { s->failed_pc=0x0c06e9a8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e9aa;
P_0c06e9aa: /* original f28d, guest PC 0x0c06e9aa */
if(!s->budget--) { s->failed_pc=0x0c06e9aau; return 0; }
fr[2]=0;
goto P_0c06e9ac;
P_0c06e9ac: /* original f245, guest PC 0x0c06e9ac */
if(!s->budget--) { s->failed_pc=0x0c06e9acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06e9ae;
P_0c06e9ae: /* original 891f, guest PC 0x0c06e9ae */
if(!s->budget--) { s->failed_pc=0x0c06e9aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e9f0; }
goto P_0c06e9b0;
P_0c06e9b0: /* original e020, guest PC 0x0c06e9b0 */
if(!s->budget--) { s->failed_pc=0x0c06e9b0u; return 0; }
r[0]=0x00000020u;
goto P_0c06e9b2;
P_0c06e9b2: /* original f2f6, guest PC 0x0c06e9b2 */
if(!s->budget--) { s->failed_pc=0x0c06e9b2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e9b4;
P_0c06e9b4: /* original f425, guest PC 0x0c06e9b4 */
if(!s->budget--) { s->failed_pc=0x0c06e9b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c06e9b6;
P_0c06e9b6: /* original 891b, guest PC 0x0c06e9b6 */
if(!s->budget--) { s->failed_pc=0x0c06e9b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e9f0; }
goto P_0c06e9b8;
P_0c06e9b8: /* original f742, guest PC 0x0c06e9b8 */
if(!s->budget--) { s->failed_pc=0x0c06e9b8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c06e9ba;
P_0c06e9ba: /* original c737, guest PC 0x0c06e9ba */
if(!s->budget--) { s->failed_pc=0x0c06e9bau; return 0; }
r[0]=0x0c06ea98u;
goto P_0c06e9bc;
P_0c06e9bc: /* original f842, guest PC 0x0c06e9bc */
if(!s->budget--) { s->failed_pc=0x0c06e9bcu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c06e9be;
P_0c06e9be: /* original f37c, guest PC 0x0c06e9be */
if(!s->budget--) { s->failed_pc=0x0c06e9beu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06e9c0;
P_0c06e9c0: /* original f3a0, guest PC 0x0c06e9c0 */
if(!s->budget--) { s->failed_pc=0x0c06e9c0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'+');
goto P_0c06e9c2;
P_0c06e9c2: /* original f8b0, guest PC 0x0c06e9c2 */
if(!s->budget--) { s->failed_pc=0x0c06e9c2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'+');
goto P_0c06e9c4;
P_0c06e9c4: /* original ff3a, guest PC 0x0c06e9c4 */
if(!s->budget--) { s->failed_pc=0x0c06e9c4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06e9c6;
P_0c06e9c6: /* original f7fc, guest PC 0x0c06e9c6 */
if(!s->budget--) { s->failed_pc=0x0c06e9c6u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c06e9c8;
P_0c06e9c8: /* original f781, guest PC 0x0c06e9c8 */
if(!s->budget--) { s->failed_pc=0x0c06e9c8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'-');
goto P_0c06e9ca;
P_0c06e9ca: /* original f4ec, guest PC 0x0c06e9ca */
if(!s->budget--) { s->failed_pc=0x0c06e9cau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06e9cc;
P_0c06e9cc: /* original f431, guest PC 0x0c06e9cc */
if(!s->budget--) { s->failed_pc=0x0c06e9ccu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c06e9ce;
P_0c06e9ce: /* original f308, guest PC 0x0c06e9ce */
if(!s->budget--) { s->failed_pc=0x0c06e9ceu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06e9d0;
P_0c06e9d0: /* original f772, guest PC 0x0c06e9d0 */
if(!s->budget--) { s->failed_pc=0x0c06e9d0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'*');
goto P_0c06e9d2;
P_0c06e9d2: /* original f442, guest PC 0x0c06e9d2 */
if(!s->budget--) { s->failed_pc=0x0c06e9d2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06e9d4;
P_0c06e9d4: /* original f470, guest PC 0x0c06e9d4 */
if(!s->budget--) { s->failed_pc=0x0c06e9d4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c06e9d6;
P_0c06e9d6: /* original f345, guest PC 0x0c06e9d6 */
if(!s->budget--) { s->failed_pc=0x0c06e9d6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06e9d8;
P_0c06e9d8: /* original 8b01, guest PC 0x0c06e9d8 */
if(!s->budget--) { s->failed_pc=0x0c06e9d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e9de; }
goto P_0c06e9da;
P_0c06e9da: /* original a002, guest PC 0x0c06e9da */
if(!s->budget--) { s->failed_pc=0x0c06e9dau; return 0; }
fr[7]=0;
goto P_0c06e9e2;
P_0c06e9dc: /* original f78d, guest PC 0x0c06e9dc */
if(!s->budget--) { s->failed_pc=0x0c06e9dcu; return 0; }
fr[7]=0;
goto P_0c06e9de;
P_0c06e9de: /* original f74c, guest PC 0x0c06e9de */
if(!s->budget--) { s->failed_pc=0x0c06e9deu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06e9e0;
P_0c06e9e0: /* original f77d, guest PC 0x0c06e9e0 */
if(!s->budget--) { s->failed_pc=0x0c06e9e0u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c06e9e2;
P_0c06e9e2: /* original f472, guest PC 0x0c06e9e2 */
if(!s->budget--) { s->failed_pc=0x0c06e9e2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c06e9e4;
P_0c06e9e4: /* original f945, guest PC 0x0c06e9e4 */
if(!s->budget--) { s->failed_pc=0x0c06e9e4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c06e9e6;
P_0c06e9e6: /* original 8b18, guest PC 0x0c06e9e6 */
if(!s->budget--) { s->failed_pc=0x0c06e9e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea1a; }
goto P_0c06e9e8;
P_0c06e9e8: /* original fd8c, guest PC 0x0c06e9e8 */
if(!s->budget--) { s->failed_pc=0x0c06e9e8u; return 0; }
vf3_matrix_move(s,13,8);
goto P_0c06e9ea;
P_0c06e9ea: /* original f94c, guest PC 0x0c06e9ea */
if(!s->budget--) { s->failed_pc=0x0c06e9eau; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c06e9ec;
P_0c06e9ec: /* original a015, guest PC 0x0c06e9ec */
if(!s->budget--) { s->failed_pc=0x0c06e9ecu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
goto P_0c06ea1a;
P_0c06e9ee: /* original fcf8, guest PC 0x0c06e9ee */
if(!s->budget--) { s->failed_pc=0x0c06e9eeu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
goto P_0c06e9f0;
P_0c06e9f0: /* original f4ec, guest PC 0x0c06e9f0 */
if(!s->budget--) { s->failed_pc=0x0c06e9f0u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06e9f2;
P_0c06e9f2: /* original f451, guest PC 0x0c06e9f2 */
if(!s->budget--) { s->failed_pc=0x0c06e9f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c06e9f4;
P_0c06e9f4: /* original f7fc, guest PC 0x0c06e9f4 */
if(!s->budget--) { s->failed_pc=0x0c06e9f4u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c06e9f6;
P_0c06e9f6: /* original f761, guest PC 0x0c06e9f6 */
if(!s->budget--) { s->failed_pc=0x0c06e9f6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c06e9f8;
P_0c06e9f8: /* original c727, guest PC 0x0c06e9f8 */
if(!s->budget--) { s->failed_pc=0x0c06e9f8u; return 0; }
r[0]=0x0c06ea98u;
goto P_0c06e9fa;
P_0c06e9fa: /* original f308, guest PC 0x0c06e9fa */
if(!s->budget--) { s->failed_pc=0x0c06e9fau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06e9fc;
P_0c06e9fc: /* original f442, guest PC 0x0c06e9fc */
if(!s->budget--) { s->failed_pc=0x0c06e9fcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06e9fe;
P_0c06e9fe: /* original f772, guest PC 0x0c06e9fe */
if(!s->budget--) { s->failed_pc=0x0c06e9feu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'*');
goto P_0c06ea00;
P_0c06ea00: /* original f470, guest PC 0x0c06ea00 */
if(!s->budget--) { s->failed_pc=0x0c06ea00u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c06ea02;
P_0c06ea02: /* original f345, guest PC 0x0c06ea02 */
if(!s->budget--) { s->failed_pc=0x0c06ea02u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06ea04;
P_0c06ea04: /* original 8b01, guest PC 0x0c06ea04 */
if(!s->budget--) { s->failed_pc=0x0c06ea04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea0a; }
goto P_0c06ea06;
P_0c06ea06: /* original a002, guest PC 0x0c06ea06 */
if(!s->budget--) { s->failed_pc=0x0c06ea06u; return 0; }
fr[7]=0;
goto P_0c06ea0e;
P_0c06ea08: /* original f78d, guest PC 0x0c06ea08 */
if(!s->budget--) { s->failed_pc=0x0c06ea08u; return 0; }
fr[7]=0;
goto P_0c06ea0a;
P_0c06ea0a: /* original f74c, guest PC 0x0c06ea0a */
if(!s->budget--) { s->failed_pc=0x0c06ea0au; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06ea0c;
P_0c06ea0c: /* original f77d, guest PC 0x0c06ea0c */
if(!s->budget--) { s->failed_pc=0x0c06ea0cu; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c06ea0e;
P_0c06ea0e: /* original f472, guest PC 0x0c06ea0e */
if(!s->budget--) { s->failed_pc=0x0c06ea0eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c06ea10;
P_0c06ea10: /* original f945, guest PC 0x0c06ea10 */
if(!s->budget--) { s->failed_pc=0x0c06ea10u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c06ea12;
P_0c06ea12: /* original 8b02, guest PC 0x0c06ea12 */
if(!s->budget--) { s->failed_pc=0x0c06ea12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea1a; }
goto P_0c06ea14;
P_0c06ea14: /* original fc5c, guest PC 0x0c06ea14 */
if(!s->budget--) { s->failed_pc=0x0c06ea14u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c06ea16;
P_0c06ea16: /* original fd6c, guest PC 0x0c06ea16 */
if(!s->budget--) { s->failed_pc=0x0c06ea16u; return 0; }
vf3_matrix_move(s,13,6);
goto P_0c06ea18;
P_0c06ea18: /* original f94c, guest PC 0x0c06ea18 */
if(!s->budget--) { s->failed_pc=0x0c06ea18u; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c06ea1a;
P_0c06ea1a: /* original 75ff, guest PC 0x0c06ea1a */
if(!s->budget--) { s->failed_pc=0x0c06ea1au; return 0; }
r[5]+=0xffffffffu;
goto P_0c06ea1c;
P_0c06ea1c: /* original 2558, guest PC 0x0c06ea1c */
if(!s->budget--) { s->failed_pc=0x0c06ea1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06ea1e;
P_0c06ea1e: /* original 8ba1, guest PC 0x0c06ea1e */
if(!s->budget--) { s->failed_pc=0x0c06ea1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e964; }
goto P_0c06ea20;
P_0c06ea20: /* original f3ec, guest PC 0x0c06ea20 */
if(!s->budget--) { s->failed_pc=0x0c06ea20u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c06ea22;
P_0c06ea22: /* original f3c1, guest PC 0x0c06ea22 */
if(!s->budget--) { s->failed_pc=0x0c06ea22u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'-');
goto P_0c06ea24;
P_0c06ea24: /* original e008, guest PC 0x0c06ea24 */
if(!s->budget--) { s->failed_pc=0x0c06ea24u; return 0; }
r[0]=0x00000008u;
goto P_0c06ea26;
P_0c06ea26: /* original ff37, guest PC 0x0c06ea26 */
if(!s->budget--) { s->failed_pc=0x0c06ea26u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06ea28;
P_0c06ea28: /* original e004, guest PC 0x0c06ea28 */
if(!s->budget--) { s->failed_pc=0x0c06ea28u; return 0; }
r[0]=0x00000004u;
goto P_0c06ea2a;
P_0c06ea2a: /* original f2fc, guest PC 0x0c06ea2a */
if(!s->budget--) { s->failed_pc=0x0c06ea2au; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c06ea2c;
P_0c06ea2c: /* original f2d1, guest PC 0x0c06ea2c */
if(!s->budget--) { s->failed_pc=0x0c06ea2cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'-');
goto P_0c06ea2e;
P_0c06ea2e: /* original f53c, guest PC 0x0c06ea2e */
if(!s->budget--) { s->failed_pc=0x0c06ea2eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c06ea30;
P_0c06ea30: /* original ff27, guest PC 0x0c06ea30 */
if(!s->budget--) { s->failed_pc=0x0c06ea30u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06ea32;
P_0c06ea32: /* original d31a, guest PC 0x0c06ea32 */
if(!s->budget--) { s->failed_pc=0x0c06ea32u; return 0; }
r[3]=read(ram,0x0c06ea9cu,4);
goto P_0c06ea34;
P_0c06ea34: /* original 430b, guest PC 0x0c06ea34 */
if(!s->budget--) { s->failed_pc=0x0c06ea34u; return 0; }
target=r[3];
r[16]=0x0c06ea38u;
vf3_matrix_move(s,4,2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ea38u) { target=s->pc; goto dispatch; }
goto P_0c06ea38;
P_0c06ea36: /* original f42c, guest PC 0x0c06ea36 */
if(!s->budget--) { s->failed_pc=0x0c06ea36u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06ea38;
P_0c06ea38: /* original 640f, guest PC 0x0c06ea38 */
if(!s->budget--) { s->failed_pc=0x0c06ea38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c06ea3a;
P_0c06ea3a: /* original f4fc, guest PC 0x0c06ea3a */
if(!s->budget--) { s->failed_pc=0x0c06ea3au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06ea3c;
P_0c06ea3c: /* original e004, guest PC 0x0c06ea3c */
if(!s->budget--) { s->failed_pc=0x0c06ea3cu; return 0; }
r[0]=0x00000004u;
goto P_0c06ea3e;
P_0c06ea3e: /* original f3f6, guest PC 0x0c06ea3e */
if(!s->budget--) { s->failed_pc=0x0c06ea3eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06ea40;
P_0c06ea40: /* original e008, guest PC 0x0c06ea40 */
if(!s->budget--) { s->failed_pc=0x0c06ea40u; return 0; }
r[0]=0x00000008u;
goto P_0c06ea42;
P_0c06ea42: /* original f0f6, guest PC 0x0c06ea42 */
if(!s->budget--) { s->failed_pc=0x0c06ea42u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c06ea44;
P_0c06ea44: /* original f432, guest PC 0x0c06ea44 */
if(!s->budget--) { s->failed_pc=0x0c06ea44u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06ea46;
P_0c06ea46: /* original f24c, guest PC 0x0c06ea46 */
if(!s->budget--) { s->failed_pc=0x0c06ea46u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06ea48;
P_0c06ea48: /* original f2ee, guest PC 0x0c06ea48 */
if(!s->budget--) { s->failed_pc=0x0c06ea48u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[14],fr[2],r[18]);
goto P_0c06ea4a;
P_0c06ea4a: /* original f42c, guest PC 0x0c06ea4a */
if(!s->budget--) { s->failed_pc=0x0c06ea4au; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06ea4c;
P_0c06ea4c: /* original f28d, guest PC 0x0c06ea4c */
if(!s->budget--) { s->failed_pc=0x0c06ea4cu; return 0; }
fr[2]=0;
goto P_0c06ea4e;
P_0c06ea4e: /* original f245, guest PC 0x0c06ea4e */
if(!s->budget--) { s->failed_pc=0x0c06ea4eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06ea50;
P_0c06ea50: /* original 8d03, guest PC 0x0c06ea50 */
if(!s->budget--) { s->failed_pc=0x0c06ea50u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,13);
if(cond) { goto P_0c06ea5a; }
goto P_0c06ea54;
P_0c06ea52: /* original f5dc, guest PC 0x0c06ea52 */
if(!s->budget--) { s->failed_pc=0x0c06ea52u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c06ea54;
P_0c06ea54: /* original d212, guest PC 0x0c06ea54 */
if(!s->budget--) { s->failed_pc=0x0c06ea54u; return 0; }
r[2]=read(ram,0x0c06eaa0u,4);
goto P_0c06ea56;
P_0c06ea56: /* original 224a, guest PC 0x0c06ea56 */
if(!s->budget--) { s->failed_pc=0x0c06ea56u; return 0; }
r[2]^=r[4];
goto P_0c06ea58;
P_0c06ea58: /* original 642f, guest PC 0x0c06ea58 */
if(!s->budget--) { s->failed_pc=0x0c06ea58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c06ea5a;
P_0c06ea5a: /* original f4cc, guest PC 0x0c06ea5a */
if(!s->budget--) { s->failed_pc=0x0c06ea5au; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c06ea5c;
P_0c06ea5c: /* original f4e1, guest PC 0x0c06ea5c */
if(!s->budget--) { s->failed_pc=0x0c06ea5cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c06ea5e;
P_0c06ea5e: /* original f5f1, guest PC 0x0c06ea5e */
if(!s->budget--) { s->failed_pc=0x0c06ea5eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c06ea60;
P_0c06ea60: /* original c70d, guest PC 0x0c06ea60 */
if(!s->budget--) { s->failed_pc=0x0c06ea60u; return 0; }
r[0]=0x0c06ea98u;
goto P_0c06ea62;
P_0c06ea62: /* original f308, guest PC 0x0c06ea62 */
if(!s->budget--) { s->failed_pc=0x0c06ea62u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06ea64;
P_0c06ea64: /* original f442, guest PC 0x0c06ea64 */
if(!s->budget--) { s->failed_pc=0x0c06ea64u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06ea66;
P_0c06ea66: /* original f552, guest PC 0x0c06ea66 */
if(!s->budget--) { s->failed_pc=0x0c06ea66u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[5],r[18],'*');
goto P_0c06ea68;
P_0c06ea68: /* original f450, guest PC 0x0c06ea68 */
if(!s->budget--) { s->failed_pc=0x0c06ea68u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c06ea6a;
P_0c06ea6a: /* original f345, guest PC 0x0c06ea6a */
if(!s->budget--) { s->failed_pc=0x0c06ea6au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06ea6c;
P_0c06ea6c: /* original 8b01, guest PC 0x0c06ea6c */
if(!s->budget--) { s->failed_pc=0x0c06ea6cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea72; }
goto P_0c06ea6e;
P_0c06ea6e: /* original a002, guest PC 0x0c06ea6e */
if(!s->budget--) { s->failed_pc=0x0c06ea6eu; return 0; }
fr[5]=0;
goto P_0c06ea76;
P_0c06ea70: /* original f58d, guest PC 0x0c06ea70 */
if(!s->budget--) { s->failed_pc=0x0c06ea70u; return 0; }
fr[5]=0;
goto P_0c06ea72;
P_0c06ea72: /* original f54c, guest PC 0x0c06ea72 */
if(!s->budget--) { s->failed_pc=0x0c06ea72u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c06ea74;
P_0c06ea74: /* original f57d, guest PC 0x0c06ea74 */
if(!s->budget--) { s->failed_pc=0x0c06ea74u; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c06ea76;
P_0c06ea76: /* original 53f4, guest PC 0x0c06ea76 */
if(!s->budget--) { s->failed_pc=0x0c06ea76u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c06ea78;
P_0c06ea78: /* original f452, guest PC 0x0c06ea78 */
if(!s->budget--) { s->failed_pc=0x0c06ea78u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c06ea7a;
P_0c06ea7a: /* original f3da, guest PC 0x0c06ea7a */
if(!s->budget--) { s->failed_pc=0x0c06ea7au; return 0; }
vf3_matrix_store(s,ram,13,r[3]);
goto P_0c06ea7c;
P_0c06ea7c: /* original 53f7, guest PC 0x0c06ea7c */
if(!s->budget--) { s->failed_pc=0x0c06ea7cu; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c06ea7e;
P_0c06ea7e: /* original f3ca, guest PC 0x0c06ea7e */
if(!s->budget--) { s->failed_pc=0x0c06ea7eu; return 0; }
vf3_matrix_store(s,ram,12,r[3]);
goto P_0c06ea80;
P_0c06ea80: /* original 53f5, guest PC 0x0c06ea80 */
if(!s->budget--) { s->failed_pc=0x0c06ea80u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c06ea82;
P_0c06ea82: /* original f34a, guest PC 0x0c06ea82 */
if(!s->budget--) { s->failed_pc=0x0c06ea82u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c06ea84;
P_0c06ea84: /* original 53f6, guest PC 0x0c06ea84 */
if(!s->budget--) { s->failed_pc=0x0c06ea84u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c06ea86;
P_0c06ea86: /* original 7f30, guest PC 0x0c06ea86 */
if(!s->budget--) { s->failed_pc=0x0c06ea86u; return 0; }
r[15]+=0x00000030u;
goto P_0c06ea88;
P_0c06ea88: /* original 4f26, guest PC 0x0c06ea88 */
if(!s->budget--) { s->failed_pc=0x0c06ea88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ea8a;
P_0c06ea8a: /* original 2342, guest PC 0x0c06ea8a */
if(!s->budget--) { s->failed_pc=0x0c06ea8au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06ea8c;
P_0c06ea8c: /* original fcf9, guest PC 0x0c06ea8c */
if(!s->budget--) { s->failed_pc=0x0c06ea8cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea8e;
P_0c06ea8e: /* original fdf9, guest PC 0x0c06ea8e */
if(!s->budget--) { s->failed_pc=0x0c06ea8eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea90;
P_0c06ea90: /* original fef9, guest PC 0x0c06ea90 */
if(!s->budget--) { s->failed_pc=0x0c06ea90u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea92;
P_0c06ea92: /* original 000b, guest PC 0x0c06ea92 */
if(!s->budget--) { s->failed_pc=0x0c06ea92u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c06ea94: /* original fff9, guest PC 0x0c06ea94 */
if(!s->budget--) { s->failed_pc=0x0c06ea94u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c06ea96u,s,ram);
P_0c0876f2: /* original 4f22, guest PC 0x0c0876f2 */
if(!s->budget--) { s->failed_pc=0x0c0876f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0876f4;
P_0c0876f4: /* original e018, guest PC 0x0c0876f4 */
if(!s->budget--) { s->failed_pc=0x0c0876f4u; return 0; }
r[0]=0x00000018u;
goto P_0c0876f6;
P_0c0876f6: /* original 7fdc, guest PC 0x0c0876f6 */
if(!s->budget--) { s->failed_pc=0x0c0876f6u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c0876f8;
P_0c0876f8: /* original 1f42, guest PC 0x0c0876f8 */
if(!s->budget--) { s->failed_pc=0x0c0876f8u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0876fa;
P_0c0876fa: /* original 64f3, guest PC 0x0c0876fa */
if(!s->budget--) { s->failed_pc=0x0c0876fau; return 0; }
r[4]=r[15];
goto P_0c0876fc;
P_0c0876fc: /* original 1f51, guest PC 0x0c0876fc */
if(!s->budget--) { s->failed_pc=0x0c0876fcu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0876fe;
P_0c0876fe: /* original 65f3, guest PC 0x0c0876fe */
if(!s->budget--) { s->failed_pc=0x0c0876feu; return 0; }
r[5]=r[15];
goto P_0c087700;
P_0c087700: /* original 2f62, guest PC 0x0c087700 */
if(!s->budget--) { s->failed_pc=0x0c087700u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c087702;
P_0c087702: /* original 750c, guest PC 0x0c087702 */
if(!s->budget--) { s->failed_pc=0x0c087702u; return 0; }
r[5]+=0x0000000cu;
goto P_0c087704;
P_0c087704: /* original ff47, guest PC 0x0c087704 */
if(!s->budget--) { s->failed_pc=0x0c087704u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c087706;
P_0c087706: /* original e01c, guest PC 0x0c087706 */
if(!s->budget--) { s->failed_pc=0x0c087706u; return 0; }
r[0]=0x0000001cu;
goto P_0c087708;
P_0c087708: /* original ff57, guest PC 0x0c087708 */
if(!s->budget--) { s->failed_pc=0x0c087708u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c08770a;
P_0c08770a: /* original e020, guest PC 0x0c08770a */
if(!s->budget--) { s->failed_pc=0x0c08770au; return 0; }
r[0]=0x00000020u;
goto P_0c08770c;
P_0c08770c: /* original ff67, guest PC 0x0c08770c */
if(!s->budget--) { s->failed_pc=0x0c08770cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08770e;
P_0c08770e: /* original d321, guest PC 0x0c08770e */
if(!s->budget--) { s->failed_pc=0x0c08770eu; return 0; }
r[3]=read(ram,0x0c087794u,4);
goto P_0c087710;
P_0c087710: /* original 430b, guest PC 0x0c087710 */
if(!s->budget--) { s->failed_pc=0x0c087710u; return 0; }
target=r[3];
r[16]=0x0c087714u;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087714u) { target=s->pc; goto dispatch; }
goto P_0c087714;
P_0c087712: /* original 7418, guest PC 0x0c087712 */
if(!s->budget--) { s->failed_pc=0x0c087712u; return 0; }
r[4]+=0x00000018u;
goto P_0c087714;
P_0c087714: /* original e00c, guest PC 0x0c087714 */
if(!s->budget--) { s->failed_pc=0x0c087714u; return 0; }
r[0]=0x0000000cu;
goto P_0c087716;
P_0c087716: /* original 52f2, guest PC 0x0c087716 */
if(!s->budget--) { s->failed_pc=0x0c087716u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c087718;
P_0c087718: /* original f3f6, guest PC 0x0c087718 */
if(!s->budget--) { s->failed_pc=0x0c087718u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08771a;
P_0c08771a: /* original e010, guest PC 0x0c08771a */
if(!s->budget--) { s->failed_pc=0x0c08771au; return 0; }
r[0]=0x00000010u;
goto P_0c08771c;
P_0c08771c: /* original f23a, guest PC 0x0c08771c */
if(!s->budget--) { s->failed_pc=0x0c08771cu; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c08771e;
P_0c08771e: /* original f3f6, guest PC 0x0c08771e */
if(!s->budget--) { s->failed_pc=0x0c08771eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087720;
P_0c087720: /* original e014, guest PC 0x0c087720 */
if(!s->budget--) { s->failed_pc=0x0c087720u; return 0; }
r[0]=0x00000014u;
goto P_0c087722;
P_0c087722: /* original 53f1, guest PC 0x0c087722 */
if(!s->budget--) { s->failed_pc=0x0c087722u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c087724;
P_0c087724: /* original f33a, guest PC 0x0c087724 */
if(!s->budget--) { s->failed_pc=0x0c087724u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087726;
P_0c087726: /* original f3f6, guest PC 0x0c087726 */
if(!s->budget--) { s->failed_pc=0x0c087726u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087728;
P_0c087728: /* original 63f2, guest PC 0x0c087728 */
if(!s->budget--) { s->failed_pc=0x0c087728u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08772a;
P_0c08772a: /* original 7f24, guest PC 0x0c08772a */
if(!s->budget--) { s->failed_pc=0x0c08772au; return 0; }
r[15]+=0x00000024u;
goto P_0c08772c;
P_0c08772c: /* original 4f26, guest PC 0x0c08772c */
if(!s->budget--) { s->failed_pc=0x0c08772cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08772e;
P_0c08772e: /* original f33a, guest PC 0x0c08772e */
if(!s->budget--) { s->failed_pc=0x0c08772eu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087730;
P_0c087730: /* original 000b, guest PC 0x0c087730 */
if(!s->budget--) { s->failed_pc=0x0c087730u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087732: /* original 0009, guest PC 0x0c087732 */
if(!s->budget--) { s->failed_pc=0x0c087732u; return 0; }
return vf3_matrix_family(0x0c087734u,s,ram);
P_0c08d158: /* original d335, guest PC 0x0c08d158 */
if(!s->budget--) { s->failed_pc=0x0c08d158u; return 0; }
r[3]=read(ram,0x0c08d230u,4);
goto P_0c08d15a;
P_0c08d15a: /* original 7ffc, guest PC 0x0c08d15a */
if(!s->budget--) { s->failed_pc=0x0c08d15au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08d15c;
P_0c08d15c: /* original 554d, guest PC 0x0c08d15c */
if(!s->budget--) { s->failed_pc=0x0c08d15cu; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c08d15e;
P_0c08d15e: /* original e040, guest PC 0x0c08d15e */
if(!s->budget--) { s->failed_pc=0x0c08d15eu; return 0; }
r[0]=0x00000040u;
goto P_0c08d160;
P_0c08d160: /* original d732, guest PC 0x0c08d160 */
if(!s->budget--) { s->failed_pc=0x0c08d160u; return 0; }
r[7]=read(ram,0x0c08d22cu,4);
goto P_0c08d162;
P_0c08d162: /* original 4508, guest PC 0x0c08d162 */
if(!s->budget--) { s->failed_pc=0x0c08d162u; return 0; }
r[5]<<=2;
goto P_0c08d164;
P_0c08d164: /* original 064e, guest PC 0x0c08d164 */
if(!s->budget--) { s->failed_pc=0x0c08d164u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c08d166;
P_0c08d166: /* original 2f32, guest PC 0x0c08d166 */
if(!s->budget--) { s->failed_pc=0x0c08d166u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08d168;
P_0c08d168: /* original 335c, guest PC 0x0c08d168 */
if(!s->budget--) { s->failed_pc=0x0c08d168u; return 0; }
r[3]+=r[5];
goto P_0c08d16a;
P_0c08d16a: /* original 375c, guest PC 0x0c08d16a */
if(!s->budget--) { s->failed_pc=0x0c08d16au; return 0; }
r[7]+=r[5];
goto P_0c08d16c;
P_0c08d16c: /* original 6232, guest PC 0x0c08d16c */
if(!s->budget--) { s->failed_pc=0x0c08d16cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c08d16e;
P_0c08d16e: /* original 6772, guest PC 0x0c08d16e */
if(!s->budget--) { s->failed_pc=0x0c08d16eu; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c08d170;
P_0c08d170: /* original e040, guest PC 0x0c08d170 */
if(!s->budget--) { s->failed_pc=0x0c08d170u; return 0; }
r[0]=0x00000040u;
goto P_0c08d172;
P_0c08d172: /* original 6323, guest PC 0x0c08d172 */
if(!s->budget--) { s->failed_pc=0x0c08d172u; return 0; }
r[3]=r[2];
goto P_0c08d174;
P_0c08d174: /* original 336c, guest PC 0x0c08d174 */
if(!s->budget--) { s->failed_pc=0x0c08d174u; return 0; }
r[3]+=r[6];
goto P_0c08d176;
P_0c08d176: /* original 376c, guest PC 0x0c08d176 */
if(!s->budget--) { s->failed_pc=0x0c08d176u; return 0; }
r[7]+=r[6];
goto P_0c08d178;
P_0c08d178: /* original 2f22, guest PC 0x0c08d178 */
if(!s->budget--) { s->failed_pc=0x0c08d178u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d17a;
P_0c08d17a: /* original 6230, guest PC 0x0c08d17a */
if(!s->budget--) { s->failed_pc=0x0c08d17au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c08d17c;
P_0c08d17c: /* original 6770, guest PC 0x0c08d17c */
if(!s->budget--) { s->failed_pc=0x0c08d17cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c08d17e;
P_0c08d17e: /* original 622c, guest PC 0x0c08d17e */
if(!s->budget--) { s->failed_pc=0x0c08d17eu; return 0; }
r[2]=r[2]&255u;
goto P_0c08d180;
P_0c08d180: /* original 677c, guest PC 0x0c08d180 */
if(!s->budget--) { s->failed_pc=0x0c08d180u; return 0; }
r[7]=r[7]&255u;
goto P_0c08d182;
P_0c08d182: /* original 2f22, guest PC 0x0c08d182 */
if(!s->budget--) { s->failed_pc=0x0c08d182u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d184;
P_0c08d184: /* original 145d, guest PC 0x0c08d184 */
if(!s->budget--) { s->failed_pc=0x0c08d184u; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c08d186;
P_0c08d186: /* original 0466, guest PC 0x0c08d186 */
if(!s->budget--) { s->failed_pc=0x0c08d186u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c08d188;
P_0c08d188: /* original 147e, guest PC 0x0c08d188 */
if(!s->budget--) { s->failed_pc=0x0c08d188u; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c08d18a;
P_0c08d18a: /* original 63f2, guest PC 0x0c08d18a */
if(!s->budget--) { s->failed_pc=0x0c08d18au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08d18c;
P_0c08d18c: /* original 143f, guest PC 0x0c08d18c */
if(!s->budget--) { s->failed_pc=0x0c08d18cu; return 0; }
write(ram,r[4]+60,r[3],4);
goto P_0c08d18e;
P_0c08d18e: /* original 000b, guest PC 0x0c08d18e */
if(!s->budget--) { s->failed_pc=0x0c08d18eu; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c08d190: /* original 7f04, guest PC 0x0c08d190 */
if(!s->budget--) { s->failed_pc=0x0c08d190u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c08d192u,s,ram);
P_0c08d406: /* original 4f22, guest PC 0x0c08d406 */
if(!s->budget--) { s->failed_pc=0x0c08d406u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d408;
P_0c08d408: /* original 8801, guest PC 0x0c08d408 */
if(!s->budget--) { s->failed_pc=0x0c08d408u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d40a;
P_0c08d40a: /* original 8d1b, guest PC 0x0c08d40a */
if(!s->budget--) { s->failed_pc=0x0c08d40au; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08d444; }
goto P_0c08d40e;
P_0c08d40c: /* original 6d53, guest PC 0x0c08d40c */
if(!s->budget--) { s->failed_pc=0x0c08d40cu; return 0; }
r[13]=r[5];
goto P_0c08d40e;
P_0c08d40e: /* original 60d2, guest PC 0x0c08d40e */
if(!s->budget--) { s->failed_pc=0x0c08d40eu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08d410;
P_0c08d410: /* original cb01, guest PC 0x0c08d410 */
if(!s->budget--) { s->failed_pc=0x0c08d410u; return 0; }
r[0]|=1u;
goto P_0c08d412;
P_0c08d412: /* original 2d02, guest PC 0x0c08d412 */
if(!s->budget--) { s->failed_pc=0x0c08d412u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08d414;
P_0c08d414: /* original e028, guest PC 0x0c08d414 */
if(!s->budget--) { s->failed_pc=0x0c08d414u; return 0; }
r[0]=0x00000028u;
goto P_0c08d416;
P_0c08d416: /* original 921b, guest PC 0x0c08d416 */
if(!s->budget--) { s->failed_pc=0x0c08d416u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d450u,2);
goto P_0c08d418;
P_0c08d418: /* original 0e25, guest PC 0x0c08d418 */
if(!s->budget--) { s->failed_pc=0x0c08d418u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08d41a;
P_0c08d41a: /* original e200, guest PC 0x0c08d41a */
if(!s->budget--) { s->failed_pc=0x0c08d41au; return 0; }
r[2]=0x00000000u;
goto P_0c08d41c;
P_0c08d41c: /* original 03ed, guest PC 0x0c08d41c */
if(!s->budget--) { s->failed_pc=0x0c08d41cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08d41e;
P_0c08d41e: /* original e040, guest PC 0x0c08d41e */
if(!s->budget--) { s->failed_pc=0x0c08d41eu; return 0; }
r[0]=0x00000040u;
goto P_0c08d420;
P_0c08d420: /* original 633d, guest PC 0x0c08d420 */
if(!s->budget--) { s->failed_pc=0x0c08d420u; return 0; }
r[3]=r[3]&65535u;
goto P_0c08d422;
P_0c08d422: /* original 1d3d, guest PC 0x0c08d422 */
if(!s->budget--) { s->failed_pc=0x0c08d422u; return 0; }
write(ram,r[13]+52,r[3],4);
goto P_0c08d424;
P_0c08d424: /* original 0d26, guest PC 0x0c08d424 */
if(!s->budget--) { s->failed_pc=0x0c08d424u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c08d426;
P_0c08d426: /* original be97, guest PC 0x0c08d426 */
if(!s->budget--) { s->failed_pc=0x0c08d426u; return 0; }
target=0x0c08d158u; r[16]=0x0c08d42au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08d42au) { target=s->pc; goto dispatch; }
goto P_0c08d42a;
P_0c08d428: /* original 64d3, guest PC 0x0c08d428 */
if(!s->budget--) { s->failed_pc=0x0c08d428u; return 0; }
r[4]=r[13];
goto P_0c08d42a;
P_0c08d42a: /* original e200, guest PC 0x0c08d42a */
if(!s->budget--) { s->failed_pc=0x0c08d42au; return 0; }
r[2]=0x00000000u;
goto P_0c08d42c;
P_0c08d42c: /* original 54de, guest PC 0x0c08d42c */
if(!s->budget--) { s->failed_pc=0x0c08d42cu; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c08d42e;
P_0c08d42e: /* original e02c, guest PC 0x0c08d42e */
if(!s->budget--) { s->failed_pc=0x0c08d42eu; return 0; }
r[0]=0x0000002cu;
goto P_0c08d430;
P_0c08d430: /* original 55df, guest PC 0x0c08d430 */
if(!s->budget--) { s->failed_pc=0x0c08d430u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c08d432;
P_0c08d432: /* original 0e24, guest PC 0x0c08d432 */
if(!s->budget--) { s->failed_pc=0x0c08d432u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08d434;
P_0c08d434: /* original e02d, guest PC 0x0c08d434 */
if(!s->budget--) { s->failed_pc=0x0c08d434u; return 0; }
r[0]=0x0000002du;
goto P_0c08d436;
P_0c08d436: /* original 0e44, guest PC 0x0c08d436 */
if(!s->budget--) { s->failed_pc=0x0c08d436u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08d438;
P_0c08d438: /* original 6053, guest PC 0x0c08d438 */
if(!s->budget--) { s->failed_pc=0x0c08d438u; return 0; }
r[0]=r[5];
goto P_0c08d43a;
P_0c08d43a: /* original 81ea, guest PC 0x0c08d43a */
if(!s->budget--) { s->failed_pc=0x0c08d43au; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08d43c;
P_0c08d43c: /* original e048, guest PC 0x0c08d43c */
if(!s->budget--) { s->failed_pc=0x0c08d43cu; return 0; }
r[0]=0x00000048u;
goto P_0c08d43e;
P_0c08d43e: /* original 03ec, guest PC 0x0c08d43e */
if(!s->budget--) { s->failed_pc=0x0c08d43eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08d440;
P_0c08d440: /* original 7301, guest PC 0x0c08d440 */
if(!s->budget--) { s->failed_pc=0x0c08d440u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d442;
P_0c08d442: /* original 0e34, guest PC 0x0c08d442 */
if(!s->budget--) { s->failed_pc=0x0c08d442u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08d444;
P_0c08d444: /* original 4f26, guest PC 0x0c08d444 */
if(!s->budget--) { s->failed_pc=0x0c08d444u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d446;
P_0c08d446: /* original 6df6, guest PC 0x0c08d446 */
if(!s->budget--) { s->failed_pc=0x0c08d446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d448;
P_0c08d448: /* original 000b, guest PC 0x0c08d448 */
if(!s->budget--) { s->failed_pc=0x0c08d448u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d44a: /* original 6ef6, guest PC 0x0c08d44a */
if(!s->budget--) { s->failed_pc=0x0c08d44au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d44cu,s,ram);
P_0c09d5ae: /* original 6543, guest PC 0x0c09d5ae */
if(!s->budget--) { s->failed_pc=0x0c09d5aeu; return 0; }
r[5]=r[4];
goto P_0c09d5b0;
P_0c09d5b0: /* original e03c, guest PC 0x0c09d5b0 */
if(!s->budget--) { s->failed_pc=0x0c09d5b0u; return 0; }
r[0]=0x0000003cu;
goto P_0c09d5b2;
P_0c09d5b2: /* original 7ffc, guest PC 0x0c09d5b2 */
if(!s->budget--) { s->failed_pc=0x0c09d5b2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09d5b4;
P_0c09d5b4: /* original 2f42, guest PC 0x0c09d5b4 */
if(!s->budget--) { s->failed_pc=0x0c09d5b4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d5b6;
P_0c09d5b6: /* original 055d, guest PC 0x0c09d5b6 */
if(!s->budget--) { s->failed_pc=0x0c09d5b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c09d5b8;
P_0c09d5b8: /* original 655d, guest PC 0x0c09d5b8 */
if(!s->budget--) { s->failed_pc=0x0c09d5b8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09d5ba;
P_0c09d5ba: /* original a000, guest PC 0x0c09d5ba */
if(!s->budget--) { s->failed_pc=0x0c09d5bau; return 0; }
r[15]+=0x00000004u;
goto P_0c09d5be;
P_0c09d5bc: /* original 7f04, guest PC 0x0c09d5bc */
if(!s->budget--) { s->failed_pc=0x0c09d5bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c09d5be;
P_0c09d5be: /* original 75ff, guest PC 0x0c09d5be */
if(!s->budget--) { s->failed_pc=0x0c09d5beu; return 0; }
r[5]+=0xffffffffu;
goto P_0c09d5c0;
P_0c09d5c0: /* original d346, guest PC 0x0c09d5c0 */
if(!s->budget--) { s->failed_pc=0x0c09d5c0u; return 0; }
r[3]=read(ram,0x0c09d6dcu,4);
goto P_0c09d5c2;
P_0c09d5c2: /* original 6253, guest PC 0x0c09d5c2 */
if(!s->budget--) { s->failed_pc=0x0c09d5c2u; return 0; }
r[2]=r[5];
goto P_0c09d5c4;
P_0c09d5c4: /* original 4500, guest PC 0x0c09d5c4 */
if(!s->budget--) { s->failed_pc=0x0c09d5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c09d5c6;
P_0c09d5c6: /* original 6632, guest PC 0x0c09d5c6 */
if(!s->budget--) { s->failed_pc=0x0c09d5c6u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c09d5c8;
P_0c09d5c8: /* original 352c, guest PC 0x0c09d5c8 */
if(!s->budget--) { s->failed_pc=0x0c09d5c8u; return 0; }
r[5]+=r[2];
goto P_0c09d5ca;
P_0c09d5ca: /* original 4508, guest PC 0x0c09d5ca */
if(!s->budget--) { s->failed_pc=0x0c09d5cau; return 0; }
r[5]<<=2;
goto P_0c09d5cc;
P_0c09d5cc: /* original 356c, guest PC 0x0c09d5cc */
if(!s->budget--) { s->failed_pc=0x0c09d5ccu; return 0; }
r[5]+=r[6];
goto P_0c09d5ce;
P_0c09d5ce: /* original 5151, guest PC 0x0c09d5ce */
if(!s->budget--) { s->failed_pc=0x0c09d5ceu; return 0; }
r[1]=read(ram,r[5]+4,4);
goto P_0c09d5d0;
P_0c09d5d0: /* original 7ff8, guest PC 0x0c09d5d0 */
if(!s->budget--) { s->failed_pc=0x0c09d5d0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09d5d2;
P_0c09d5d2: /* original 6752, guest PC 0x0c09d5d2 */
if(!s->budget--) { s->failed_pc=0x0c09d5d2u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c09d5d4;
P_0c09d5d4: /* original 316c, guest PC 0x0c09d5d4 */
if(!s->budget--) { s->failed_pc=0x0c09d5d4u; return 0; }
r[1]+=r[6];
goto P_0c09d5d6;
P_0c09d5d6: /* original 376c, guest PC 0x0c09d5d6 */
if(!s->budget--) { s->failed_pc=0x0c09d5d6u; return 0; }
r[7]+=r[6];
goto P_0c09d5d8;
P_0c09d5d8: /* original 2f12, guest PC 0x0c09d5d8 */
if(!s->budget--) { s->failed_pc=0x0c09d5d8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c09d5da;
P_0c09d5da: /* original 5252, guest PC 0x0c09d5da */
if(!s->budget--) { s->failed_pc=0x0c09d5dau; return 0; }
r[2]=read(ram,r[5]+8,4);
goto P_0c09d5dc;
P_0c09d5dc: /* original e104, guest PC 0x0c09d5dc */
if(!s->budget--) { s->failed_pc=0x0c09d5dcu; return 0; }
r[1]=0x00000004u;
goto P_0c09d5de;
P_0c09d5de: /* original 362c, guest PC 0x0c09d5de */
if(!s->budget--) { s->failed_pc=0x0c09d5deu; return 0; }
r[6]+=r[2];
goto P_0c09d5e0;
P_0c09d5e0: /* original 1f61, guest PC 0x0c09d5e0 */
if(!s->budget--) { s->failed_pc=0x0c09d5e0u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c09d5e2;
P_0c09d5e2: /* original 6673, guest PC 0x0c09d5e2 */
if(!s->budget--) { s->failed_pc=0x0c09d5e2u; return 0; }
r[6]=r[7];
goto P_0c09d5e4;
P_0c09d5e4: /* original 9073, guest PC 0x0c09d5e4 */
if(!s->budget--) { s->failed_pc=0x0c09d5e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6ceu,2);
goto P_0c09d5e6;
P_0c09d5e6: /* original 7602, guest PC 0x0c09d5e6 */
if(!s->budget--) { s->failed_pc=0x0c09d5e6u; return 0; }
r[6]+=0x00000002u;
goto P_0c09d5e8;
P_0c09d5e8: /* original 6571, guest PC 0x0c09d5e8 */
if(!s->budget--) { s->failed_pc=0x0c09d5e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[5]=tmp;
goto P_0c09d5ea;
P_0c09d5ea: /* original 024c, guest PC 0x0c09d5ea */
if(!s->budget--) { s->failed_pc=0x0c09d5eau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09d5ec;
P_0c09d5ec: /* original 701d, guest PC 0x0c09d5ec */
if(!s->budget--) { s->failed_pc=0x0c09d5ecu; return 0; }
r[0]+=0x0000001du;
goto P_0c09d5ee;
P_0c09d5ee: /* original 655d, guest PC 0x0c09d5ee */
if(!s->budget--) { s->failed_pc=0x0c09d5eeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c09d5f0;
P_0c09d5f0: /* original 0424, guest PC 0x0c09d5f0 */
if(!s->budget--) { s->failed_pc=0x0c09d5f0u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09d5f2;
P_0c09d5f2: /* original e2f4, guest PC 0x0c09d5f2 */
if(!s->budget--) { s->failed_pc=0x0c09d5f2u; return 0; }
r[2]=0xfffffff4u;
goto P_0c09d5f4;
P_0c09d5f4: /* original 452c, guest PC 0x0c09d5f4 */
if(!s->budget--) { s->failed_pc=0x0c09d5f4u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c09d5f6;
P_0c09d5f6: /* original 70e3, guest PC 0x0c09d5f6 */
if(!s->budget--) { s->failed_pc=0x0c09d5f6u; return 0; }
r[0]+=0xffffffe3u;
goto P_0c09d5f8;
P_0c09d5f8: /* original 2519, guest PC 0x0c09d5f8 */
if(!s->budget--) { s->failed_pc=0x0c09d5f8u; return 0; }
r[5]&=r[1];
goto P_0c09d5fa;
P_0c09d5fa: /* original 0454, guest PC 0x0c09d5fa */
if(!s->budget--) { s->failed_pc=0x0c09d5fau; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c09d5fc;
P_0c09d5fc: /* original 9068, guest PC 0x0c09d5fc */
if(!s->budget--) { s->failed_pc=0x0c09d5fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6d0u,2);
goto P_0c09d5fe;
P_0c09d5fe: /* original 044e, guest PC 0x0c09d5fe */
if(!s->budget--) { s->failed_pc=0x0c09d5feu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09d600;
P_0c09d600: /* original 6563, guest PC 0x0c09d600 */
if(!s->budget--) { s->failed_pc=0x0c09d600u; return 0; }
r[5]=r[6];
goto P_0c09d602;
P_0c09d602: /* original 750f, guest PC 0x0c09d602 */
if(!s->budget--) { s->failed_pc=0x0c09d602u; return 0; }
r[5]+=0x0000000fu;
goto P_0c09d604;
P_0c09d604: /* original 53f1, guest PC 0x0c09d604 */
if(!s->budget--) { s->failed_pc=0x0c09d604u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d606;
P_0c09d606: /* original e110, guest PC 0x0c09d606 */
if(!s->budget--) { s->failed_pc=0x0c09d606u; return 0; }
r[1]=0x00000010u;
goto P_0c09d608;
P_0c09d608: /* original 1432, guest PC 0x0c09d608 */
if(!s->budget--) { s->failed_pc=0x0c09d608u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c09d60a;
P_0c09d60a: /* original 62f2, guest PC 0x0c09d60a */
if(!s->budget--) { s->failed_pc=0x0c09d60au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09d60c;
P_0c09d60c: /* original 1421, guest PC 0x0c09d60c */
if(!s->budget--) { s->failed_pc=0x0c09d60cu; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c09d60e;
P_0c09d60e: /* original 6263, guest PC 0x0c09d60e */
if(!s->budget--) { s->failed_pc=0x0c09d60eu; return 0; }
r[2]=r[6];
goto P_0c09d610;
P_0c09d610: /* original e600, guest PC 0x0c09d610 */
if(!s->budget--) { s->failed_pc=0x0c09d610u; return 0; }
r[6]=0x00000000u;
goto P_0c09d612;
P_0c09d612: /* original 2452, guest PC 0x0c09d612 */
if(!s->budget--) { s->failed_pc=0x0c09d612u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c09d614;
P_0c09d614: /* original 6563, guest PC 0x0c09d614 */
if(!s->budget--) { s->failed_pc=0x0c09d614u; return 0; }
r[5]=r[6];
goto P_0c09d616;
P_0c09d616: /* original 6763, guest PC 0x0c09d616 */
if(!s->budget--) { s->failed_pc=0x0c09d616u; return 0; }
r[7]=r[6];
goto P_0c09d618;
P_0c09d618: /* original 6624, guest PC 0x0c09d618 */
if(!s->budget--) { s->failed_pc=0x0c09d618u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[6]=tmp;
goto P_0c09d61a;
P_0c09d61a: /* original 6343, guest PC 0x0c09d61a */
if(!s->budget--) { s->failed_pc=0x0c09d61au; return 0; }
r[3]=r[4];
goto P_0c09d61c;
P_0c09d61c: /* original 730c, guest PC 0x0c09d61c */
if(!s->budget--) { s->failed_pc=0x0c09d61cu; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d61e;
P_0c09d61e: /* original 666c, guest PC 0x0c09d61e */
if(!s->budget--) { s->failed_pc=0x0c09d61eu; return 0; }
r[6]=r[6]&255u;
goto P_0c09d620;
P_0c09d620: /* original 6063, guest PC 0x0c09d620 */
if(!s->budget--) { s->failed_pc=0x0c09d620u; return 0; }
r[0]=r[6];
goto P_0c09d622;
P_0c09d622: /* original 4009, guest PC 0x0c09d622 */
if(!s->budget--) { s->failed_pc=0x0c09d622u; return 0; }
r[0]>>=2;
goto P_0c09d624;
P_0c09d624: /* original 4009, guest PC 0x0c09d624 */
if(!s->budget--) { s->failed_pc=0x0c09d624u; return 0; }
r[0]>>=2;
goto P_0c09d626;
P_0c09d626: /* original 4009, guest PC 0x0c09d626 */
if(!s->budget--) { s->failed_pc=0x0c09d626u; return 0; }
r[0]>>=2;
goto P_0c09d628;
P_0c09d628: /* original c903, guest PC 0x0c09d628 */
if(!s->budget--) { s->failed_pc=0x0c09d628u; return 0; }
r[0]&=3u;
goto P_0c09d62a;
P_0c09d62a: /* original 335c, guest PC 0x0c09d62a */
if(!s->budget--) { s->failed_pc=0x0c09d62au; return 0; }
r[3]+=r[5];
goto P_0c09d62c;
P_0c09d62c: /* original 2300, guest PC 0x0c09d62c */
if(!s->budget--) { s->failed_pc=0x0c09d62cu; return 0; }
write(ram,r[3],r[0],1);
goto P_0c09d62e;
P_0c09d62e: /* original 6063, guest PC 0x0c09d62e */
if(!s->budget--) { s->failed_pc=0x0c09d62eu; return 0; }
r[0]=r[6];
goto P_0c09d630;
P_0c09d630: /* original 4009, guest PC 0x0c09d630 */
if(!s->budget--) { s->failed_pc=0x0c09d630u; return 0; }
r[0]>>=2;
goto P_0c09d632;
P_0c09d632: /* original 6343, guest PC 0x0c09d632 */
if(!s->budget--) { s->failed_pc=0x0c09d632u; return 0; }
r[3]=r[4];
goto P_0c09d634;
P_0c09d634: /* original 4009, guest PC 0x0c09d634 */
if(!s->budget--) { s->failed_pc=0x0c09d634u; return 0; }
r[0]>>=2;
goto P_0c09d636;
P_0c09d636: /* original 730c, guest PC 0x0c09d636 */
if(!s->budget--) { s->failed_pc=0x0c09d636u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d638;
P_0c09d638: /* original c903, guest PC 0x0c09d638 */
if(!s->budget--) { s->failed_pc=0x0c09d638u; return 0; }
r[0]&=3u;
goto P_0c09d63a;
P_0c09d63a: /* original 335c, guest PC 0x0c09d63a */
if(!s->budget--) { s->failed_pc=0x0c09d63au; return 0; }
r[3]+=r[5];
goto P_0c09d63c;
P_0c09d63c: /* original 8031, guest PC 0x0c09d63c */
if(!s->budget--) { s->failed_pc=0x0c09d63cu; return 0; }
write(ram,r[3]+1,r[0],1);
goto P_0c09d63e;
P_0c09d63e: /* original 6063, guest PC 0x0c09d63e */
if(!s->budget--) { s->failed_pc=0x0c09d63eu; return 0; }
r[0]=r[6];
goto P_0c09d640;
P_0c09d640: /* original 6343, guest PC 0x0c09d640 */
if(!s->budget--) { s->failed_pc=0x0c09d640u; return 0; }
r[3]=r[4];
goto P_0c09d642;
P_0c09d642: /* original 4009, guest PC 0x0c09d642 */
if(!s->budget--) { s->failed_pc=0x0c09d642u; return 0; }
r[0]>>=2;
goto P_0c09d644;
P_0c09d644: /* original 730c, guest PC 0x0c09d644 */
if(!s->budget--) { s->failed_pc=0x0c09d644u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d646;
P_0c09d646: /* original c903, guest PC 0x0c09d646 */
if(!s->budget--) { s->failed_pc=0x0c09d646u; return 0; }
r[0]&=3u;
goto P_0c09d648;
P_0c09d648: /* original 335c, guest PC 0x0c09d648 */
if(!s->budget--) { s->failed_pc=0x0c09d648u; return 0; }
r[3]+=r[5];
goto P_0c09d64a;
P_0c09d64a: /* original 8032, guest PC 0x0c09d64a */
if(!s->budget--) { s->failed_pc=0x0c09d64au; return 0; }
write(ram,r[3]+2,r[0],1);
goto P_0c09d64c;
P_0c09d64c: /* original 6343, guest PC 0x0c09d64c */
if(!s->budget--) { s->failed_pc=0x0c09d64cu; return 0; }
r[3]=r[4];
goto P_0c09d64e;
P_0c09d64e: /* original e003, guest PC 0x0c09d64e */
if(!s->budget--) { s->failed_pc=0x0c09d64eu; return 0; }
r[0]=0x00000003u;
goto P_0c09d650;
P_0c09d650: /* original 730c, guest PC 0x0c09d650 */
if(!s->budget--) { s->failed_pc=0x0c09d650u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d652;
P_0c09d652: /* original 2069, guest PC 0x0c09d652 */
if(!s->budget--) { s->failed_pc=0x0c09d652u; return 0; }
r[0]&=r[6];
goto P_0c09d654;
P_0c09d654: /* original 335c, guest PC 0x0c09d654 */
if(!s->budget--) { s->failed_pc=0x0c09d654u; return 0; }
r[3]+=r[5];
goto P_0c09d656;
P_0c09d656: /* original 8033, guest PC 0x0c09d656 */
if(!s->budget--) { s->failed_pc=0x0c09d656u; return 0; }
write(ram,r[3]+3,r[0],1);
goto P_0c09d658;
P_0c09d658: /* original 7701, guest PC 0x0c09d658 */
if(!s->budget--) { s->failed_pc=0x0c09d658u; return 0; }
r[7]+=0x00000001u;
goto P_0c09d65a;
P_0c09d65a: /* original 3712, guest PC 0x0c09d65a */
if(!s->budget--) { s->failed_pc=0x0c09d65au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[1])!=0);
goto P_0c09d65c;
P_0c09d65c: /* original 8fdc, guest PC 0x0c09d65c */
if(!s->budget--) { s->failed_pc=0x0c09d65cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c09d618; }
goto P_0c09d660;
P_0c09d65e: /* original 7504, guest PC 0x0c09d65e */
if(!s->budget--) { s->failed_pc=0x0c09d65eu; return 0; }
r[5]+=0x00000004u;
goto P_0c09d660;
P_0c09d660: /* original 000b, guest PC 0x0c09d660 */
if(!s->budget--) { s->failed_pc=0x0c09d660u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c09d662: /* original 7f08, guest PC 0x0c09d662 */
if(!s->budget--) { s->failed_pc=0x0c09d662u; return 0; }
r[15]+=0x00000008u;
return vf3_matrix_family(0x0c09d664u,s,ram);
P_0c09efce: /* original 933f, guest PC 0x0c09efce */
if(!s->budget--) { s->failed_pc=0x0c09efceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f050u,2);
goto P_0c09efd0;
P_0c09efd0: /* original e042, guest PC 0x0c09efd0 */
if(!s->budget--) { s->failed_pc=0x0c09efd0u; return 0; }
r[0]=0x00000042u;
goto P_0c09efd2;
P_0c09efd2: /* original 0435, guest PC 0x0c09efd2 */
if(!s->budget--) { s->failed_pc=0x0c09efd2u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efd4;
P_0c09efd4: /* original a000, guest PC 0x0c09efd4 */
if(!s->budget--) { s->failed_pc=0x0c09efd4u; return 0; }
goto P_0c09efd8;
P_0c09efd6: /* original 0009, guest PC 0x0c09efd6 */
if(!s->budget--) { s->failed_pc=0x0c09efd6u; return 0; }
goto P_0c09efd8;
P_0c09efd8: /* original e03e, guest PC 0x0c09efd8 */
if(!s->budget--) { s->failed_pc=0x0c09efd8u; return 0; }
r[0]=0x0000003eu;
goto P_0c09efda;
P_0c09efda: /* original e301, guest PC 0x0c09efda */
if(!s->budget--) { s->failed_pc=0x0c09efdau; return 0; }
r[3]=0x00000001u;
goto P_0c09efdc;
P_0c09efdc: /* original 0435, guest PC 0x0c09efdc */
if(!s->budget--) { s->failed_pc=0x0c09efdcu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efde;
P_0c09efde: /* original e040, guest PC 0x0c09efde */
if(!s->budget--) { s->failed_pc=0x0c09efdeu; return 0; }
r[0]=0x00000040u;
goto P_0c09efe0;
P_0c09efe0: /* original e200, guest PC 0x0c09efe0 */
if(!s->budget--) { s->failed_pc=0x0c09efe0u; return 0; }
r[2]=0x00000000u;
goto P_0c09efe2;
P_0c09efe2: /* original 000b, guest PC 0x0c09efe2 */
if(!s->budget--) { s->failed_pc=0x0c09efe2u; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c09efe4: /* original 0425, guest PC 0x0c09efe4 */
if(!s->budget--) { s->failed_pc=0x0c09efe4u; return 0; }
write(ram,r[4]+r[0],r[2],2);
return vf3_matrix_family(0x0c09efe6u,s,ram);
P_0c09f1ac: /* original e048, guest PC 0x0c09f1ac */
if(!s->budget--) { s->failed_pc=0x0c09f1acu; return 0; }
r[0]=0x00000048u;
goto P_0c09f1ae;
P_0c09f1ae: /* original 2fe6, guest PC 0x0c09f1ae */
if(!s->budget--) { s->failed_pc=0x0c09f1aeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b0;
P_0c09f1b0: /* original 2fd6, guest PC 0x0c09f1b0 */
if(!s->budget--) { s->failed_pc=0x0c09f1b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b2;
P_0c09f1b2: /* original e304, guest PC 0x0c09f1b2 */
if(!s->budget--) { s->failed_pc=0x0c09f1b2u; return 0; }
r[3]=0x00000004u;
goto P_0c09f1b4;
P_0c09f1b4: /* original 2fc6, guest PC 0x0c09f1b4 */
if(!s->budget--) { s->failed_pc=0x0c09f1b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b6;
P_0c09f1b6: /* original e520, guest PC 0x0c09f1b6 */
if(!s->budget--) { s->failed_pc=0x0c09f1b6u; return 0; }
r[5]=0x00000020u;
goto P_0c09f1b8;
P_0c09f1b8: /* original 2fb6, guest PC 0x0c09f1b8 */
if(!s->budget--) { s->failed_pc=0x0c09f1b8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1ba;
P_0c09f1ba: /* original e210, guest PC 0x0c09f1ba */
if(!s->budget--) { s->failed_pc=0x0c09f1bau; return 0; }
r[2]=0x00000010u;
goto P_0c09f1bc;
P_0c09f1bc: /* original 2fa6, guest PC 0x0c09f1bc */
if(!s->budget--) { s->failed_pc=0x0c09f1bcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1be;
P_0c09f1be: /* original e700, guest PC 0x0c09f1be */
if(!s->budget--) { s->failed_pc=0x0c09f1beu; return 0; }
r[7]=0x00000000u;
goto P_0c09f1c0;
P_0c09f1c0: /* original 2f96, guest PC 0x0c09f1c0 */
if(!s->budget--) { s->failed_pc=0x0c09f1c0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1c2;
P_0c09f1c2: /* original 2f86, guest PC 0x0c09f1c2 */
if(!s->budget--) { s->failed_pc=0x0c09f1c2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1c4;
P_0c09f1c4: /* original 064e, guest PC 0x0c09f1c4 */
if(!s->budget--) { s->failed_pc=0x0c09f1c4u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c09f1c6;
P_0c09f1c6: /* original 7fec, guest PC 0x0c09f1c6 */
if(!s->budget--) { s->failed_pc=0x0c09f1c6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c09f1c8;
P_0c09f1c8: /* original 2f32, guest PC 0x0c09f1c8 */
if(!s->budget--) { s->failed_pc=0x0c09f1c8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f1ca;
P_0c09f1ca: /* original 9042, guest PC 0x0c09f1ca */
if(!s->budget--) { s->failed_pc=0x0c09f1cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f252u,2);
goto P_0c09f1cc;
P_0c09f1cc: /* original dc23, guest PC 0x0c09f1cc */
if(!s->budget--) { s->failed_pc=0x0c09f1ccu; return 0; }
r[12]=read(ram,0x0c09f25cu,4);
goto P_0c09f1ce;
P_0c09f1ce: /* original 0e4c, guest PC 0x0c09f1ce */
if(!s->budget--) { s->failed_pc=0x0c09f1ceu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f1d0;
P_0c09f1d0: /* original db21, guest PC 0x0c09f1d0 */
if(!s->budget--) { s->failed_pc=0x0c09f1d0u; return 0; }
r[11]=read(ram,0x0c09f258u,4);
goto P_0c09f1d2;
P_0c09f1d2: /* original 6eec, guest PC 0x0c09f1d2 */
if(!s->budget--) { s->failed_pc=0x0c09f1d2u; return 0; }
r[14]=r[14]&255u;
goto P_0c09f1d4;
P_0c09f1d4: /* original 60e3, guest PC 0x0c09f1d4 */
if(!s->budget--) { s->failed_pc=0x0c09f1d4u; return 0; }
r[0]=r[14];
goto P_0c09f1d6;
P_0c09f1d6: /* original 4001, guest PC 0x0c09f1d6 */
if(!s->budget--) { s->failed_pc=0x0c09f1d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c09f1d8;
P_0c09f1d8: /* original 6303, guest PC 0x0c09f1d8 */
if(!s->budget--) { s->failed_pc=0x0c09f1d8u; return 0; }
r[3]=r[0];
goto P_0c09f1da;
P_0c09f1da: /* original 60e3, guest PC 0x0c09f1da */
if(!s->budget--) { s->failed_pc=0x0c09f1dau; return 0; }
r[0]=r[14];
goto P_0c09f1dc;
P_0c09f1dc: /* original c901, guest PC 0x0c09f1dc */
if(!s->budget--) { s->failed_pc=0x0c09f1dcu; return 0; }
r[0]&=1u;
goto P_0c09f1de;
P_0c09f1de: /* original 4005, guest PC 0x0c09f1de */
if(!s->budget--) { s->failed_pc=0x0c09f1deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c09f1e0;
P_0c09f1e0: /* original 203b, guest PC 0x0c09f1e0 */
if(!s->budget--) { s->failed_pc=0x0c09f1e0u; return 0; }
r[0]|=r[3];
goto P_0c09f1e2;
P_0c09f1e2: /* original 2509, guest PC 0x0c09f1e2 */
if(!s->budget--) { s->failed_pc=0x0c09f1e2u; return 0; }
r[5]&=r[0];
goto P_0c09f1e4;
P_0c09f1e4: /* original 9036, guest PC 0x0c09f1e4 */
if(!s->budget--) { s->failed_pc=0x0c09f1e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f254u,2);
goto P_0c09f1e6;
P_0c09f1e6: /* original 252b, guest PC 0x0c09f1e6 */
if(!s->budget--) { s->failed_pc=0x0c09f1e6u; return 0; }
r[5]|=r[2];
goto P_0c09f1e8;
P_0c09f1e8: /* original 034c, guest PC 0x0c09f1e8 */
if(!s->budget--) { s->failed_pc=0x0c09f1e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f1ea;
P_0c09f1ea: /* original 633c, guest PC 0x0c09f1ea */
if(!s->budget--) { s->failed_pc=0x0c09f1eau; return 0; }
r[3]=r[3]&255u;
goto P_0c09f1ec;
P_0c09f1ec: /* original 6853, guest PC 0x0c09f1ec */
if(!s->budget--) { s->failed_pc=0x0c09f1ecu; return 0; }
r[8]=r[5];
goto P_0c09f1ee;
P_0c09f1ee: /* original 1f31, guest PC 0x0c09f1ee */
if(!s->budget--) { s->failed_pc=0x0c09f1eeu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f1f0;
P_0c09f1f0: /* original 61f2, guest PC 0x0c09f1f0 */
if(!s->budget--) { s->failed_pc=0x0c09f1f0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c09f1f2;
P_0c09f1f2: /* original e902, guest PC 0x0c09f1f2 */
if(!s->budget--) { s->failed_pc=0x0c09f1f2u; return 0; }
r[9]=0x00000002u;
goto P_0c09f1f4;
P_0c09f1f4: /* original 2168, guest PC 0x0c09f1f4 */
if(!s->budget--) { s->failed_pc=0x0c09f1f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[6])==0)!=0);
goto P_0c09f1f6;
P_0c09f1f6: /* original 8f2a, guest PC 0x0c09f1f6 */
if(!s->budget--) { s->failed_pc=0x0c09f1f6u; return 0; }
cond=r[17]&1u;
r[8]|=r[9];
if(!cond) { goto P_0c09f24e; }
goto P_0c09f1fa;
P_0c09f1f8: /* original 289b, guest PC 0x0c09f1f8 */
if(!s->budget--) { s->failed_pc=0x0c09f1f8u; return 0; }
r[8]|=r[9];
goto P_0c09f1fa;
P_0c09f1fa: /* original 53f1, guest PC 0x0c09f1fa */
if(!s->budget--) { s->failed_pc=0x0c09f1fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f1fc;
P_0c09f1fc: /* original 2338, guest PC 0x0c09f1fc */
if(!s->budget--) { s->failed_pc=0x0c09f1fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f1fe;
P_0c09f1fe: /* original 8b26, guest PC 0x0c09f1fe */
if(!s->budget--) { s->failed_pc=0x0c09f1feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f24e; }
goto P_0c09f200;
P_0c09f200: /* original d217, guest PC 0x0c09f200 */
if(!s->budget--) { s->failed_pc=0x0c09f200u; return 0; }
r[2]=read(ram,0x0c09f260u,4);
goto P_0c09f202;
P_0c09f202: /* original 2769, guest PC 0x0c09f202 */
if(!s->budget--) { s->failed_pc=0x0c09f202u; return 0; }
r[7]&=r[6];
goto P_0c09f204;
P_0c09f204: /* original 2b69, guest PC 0x0c09f204 */
if(!s->budget--) { s->failed_pc=0x0c09f204u; return 0; }
r[11]&=r[6];
goto P_0c09f206;
P_0c09f206: /* original 6323, guest PC 0x0c09f206 */
if(!s->budget--) { s->failed_pc=0x0c09f206u; return 0; }
r[3]=r[2];
goto P_0c09f208;
P_0c09f208: /* original 2f22, guest PC 0x0c09f208 */
if(!s->budget--) { s->failed_pc=0x0c09f208u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09f20a;
P_0c09f20a: /* original 9d24, guest PC 0x0c09f20a */
if(!s->budget--) { s->failed_pc=0x0c09f20au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f256u,2);
goto P_0c09f20c;
P_0c09f20c: /* original 2369, guest PC 0x0c09f20c */
if(!s->budget--) { s->failed_pc=0x0c09f20cu; return 0; }
r[3]&=r[6];
goto P_0c09f20e;
P_0c09f20e: /* original da15, guest PC 0x0c09f20e */
if(!s->budget--) { s->failed_pc=0x0c09f20eu; return 0; }
r[10]=read(ram,0x0c09f264u,4);
goto P_0c09f210;
P_0c09f210: /* original 2c69, guest PC 0x0c09f210 */
if(!s->budget--) { s->failed_pc=0x0c09f210u; return 0; }
r[12]&=r[6];
goto P_0c09f212;
P_0c09f212: /* original 2d69, guest PC 0x0c09f212 */
if(!s->budget--) { s->failed_pc=0x0c09f212u; return 0; }
r[13]&=r[6];
goto P_0c09f214;
P_0c09f214: /* original 1f31, guest PC 0x0c09f214 */
if(!s->budget--) { s->failed_pc=0x0c09f214u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f216;
P_0c09f216: /* original 62f2, guest PC 0x0c09f216 */
if(!s->budget--) { s->failed_pc=0x0c09f216u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f218;
P_0c09f218: /* original 26a9, guest PC 0x0c09f218 */
if(!s->budget--) { s->failed_pc=0x0c09f218u; return 0; }
r[6]&=r[10];
goto P_0c09f21a;
P_0c09f21a: /* original 3320, guest PC 0x0c09f21a */
if(!s->budget--) { s->failed_pc=0x0c09f21au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09f21c;
P_0c09f21c: /* original 0029, guest PC 0x0c09f21c */
if(!s->budget--) { s->failed_pc=0x0c09f21cu; return 0; }
r[0]=r[17]&1u;
goto P_0c09f21e;
P_0c09f21e: /* original 36a0, guest PC 0x0c09f21e */
if(!s->budget--) { s->failed_pc=0x0c09f21eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[10])!=0);
goto P_0c09f220;
P_0c09f220: /* original ca01, guest PC 0x0c09f220 */
if(!s->budget--) { s->failed_pc=0x0c09f220u; return 0; }
r[0]^=1u;
goto P_0c09f222;
P_0c09f222: /* original 2f02, guest PC 0x0c09f222 */
if(!s->budget--) { s->failed_pc=0x0c09f222u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09f224;
P_0c09f224: /* original 0029, guest PC 0x0c09f224 */
if(!s->budget--) { s->failed_pc=0x0c09f224u; return 0; }
r[0]=r[17]&1u;
goto P_0c09f226;
P_0c09f226: /* original ca01, guest PC 0x0c09f226 */
if(!s->budget--) { s->failed_pc=0x0c09f226u; return 0; }
r[0]^=1u;
goto P_0c09f228;
P_0c09f228: /* original 1fb2, guest PC 0x0c09f228 */
if(!s->budget--) { s->failed_pc=0x0c09f228u; return 0; }
write(ram,r[15]+8,r[11],4);
goto P_0c09f22a;
P_0c09f22a: /* original 1fc3, guest PC 0x0c09f22a */
if(!s->budget--) { s->failed_pc=0x0c09f22au; return 0; }
write(ram,r[15]+12,r[12],4);
goto P_0c09f22c;
P_0c09f22c: /* original 1f04, guest PC 0x0c09f22c */
if(!s->budget--) { s->failed_pc=0x0c09f22cu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c09f22e;
P_0c09f22e: /* original 1fd1, guest PC 0x0c09f22e */
if(!s->budget--) { s->failed_pc=0x0c09f22eu; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c09f230;
P_0c09f230: /* original 62f2, guest PC 0x0c09f230 */
if(!s->budget--) { s->failed_pc=0x0c09f230u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f232;
P_0c09f232: /* original 2228, guest PC 0x0c09f232 */
if(!s->budget--) { s->failed_pc=0x0c09f232u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f234;
P_0c09f234: /* original 8d08, guest PC 0x0c09f234 */
if(!s->budget--) { s->failed_pc=0x0c09f234u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c09f248; }
goto P_0c09f238;
P_0c09f236: /* original e601, guest PC 0x0c09f236 */
if(!s->budget--) { s->failed_pc=0x0c09f236u; return 0; }
r[6]=0x00000001u;
goto P_0c09f238;
P_0c09f238: /* original 53f2, guest PC 0x0c09f238 */
if(!s->budget--) { s->failed_pc=0x0c09f238u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f23a;
P_0c09f23a: /* original 2338, guest PC 0x0c09f23a */
if(!s->budget--) { s->failed_pc=0x0c09f23au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f23c;
P_0c09f23c: /* original 8b14, guest PC 0x0c09f23c */
if(!s->budget--) { s->failed_pc=0x0c09f23cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f268; }
goto P_0c09f23e;
P_0c09f23e: /* original 2778, guest PC 0x0c09f23e */
if(!s->budget--) { s->failed_pc=0x0c09f23eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f240;
P_0c09f240: /* original 8b03, guest PC 0x0c09f240 */
if(!s->budget--) { s->failed_pc=0x0c09f240u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f24a; }
goto P_0c09f242;
P_0c09f242: /* original 52f3, guest PC 0x0c09f242 */
if(!s->budget--) { s->failed_pc=0x0c09f242u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c09f244;
P_0c09f244: /* original 2228, guest PC 0x0c09f244 */
if(!s->budget--) { s->failed_pc=0x0c09f244u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f246;
P_0c09f246: /* original 8b15, guest PC 0x0c09f246 */
if(!s->budget--) { s->failed_pc=0x0c09f246u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f274; }
goto P_0c09f248;
P_0c09f248: /* original 6583, guest PC 0x0c09f248 */
if(!s->budget--) { s->failed_pc=0x0c09f248u; return 0; }
r[5]=r[8];
goto P_0c09f24a;
P_0c09f24a: /* original a014, guest PC 0x0c09f24a */
if(!s->budget--) { s->failed_pc=0x0c09f24au; return 0; }
r[5]|=r[6];
goto P_0c09f276;
P_0c09f24c: /* original 256b, guest PC 0x0c09f24c */
if(!s->budget--) { s->failed_pc=0x0c09f24cu; return 0; }
r[5]|=r[6];
goto P_0c09f24e;
P_0c09f24e: /* original a012, guest PC 0x0c09f24e */
if(!s->budget--) { s->failed_pc=0x0c09f24eu; return 0; }
r[5]=r[8];
goto P_0c09f276;
P_0c09f250: /* original 6583, guest PC 0x0c09f250 */
if(!s->budget--) { s->failed_pc=0x0c09f250u; return 0; }
r[5]=r[8];
return vf3_matrix_family(0x0c09f252u,s,ram);
P_0c09f268: /* original e048, guest PC 0x0c09f268 */
if(!s->budget--) { s->failed_pc=0x0c09f268u; return 0; }
r[0]=0x00000048u;
goto P_0c09f26a;
P_0c09f26a: /* original d335, guest PC 0x0c09f26a */
if(!s->budget--) { s->failed_pc=0x0c09f26au; return 0; }
r[3]=read(ram,0x0c09f340u,4);
goto P_0c09f26c;
P_0c09f26c: /* original 024e, guest PC 0x0c09f26c */
if(!s->budget--) { s->failed_pc=0x0c09f26cu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c09f26e;
P_0c09f26e: /* original 2238, guest PC 0x0c09f26e */
if(!s->budget--) { s->failed_pc=0x0c09f26eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09f270;
P_0c09f270: /* original 8b00, guest PC 0x0c09f270 */
if(!s->budget--) { s->failed_pc=0x0c09f270u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f274; }
goto P_0c09f272;
P_0c09f272: /* original 256b, guest PC 0x0c09f272 */
if(!s->budget--) { s->failed_pc=0x0c09f272u; return 0; }
r[5]|=r[6];
goto P_0c09f274;
P_0c09f274: /* original 259b, guest PC 0x0c09f274 */
if(!s->budget--) { s->failed_pc=0x0c09f274u; return 0; }
r[5]|=r[9];
goto P_0c09f276;
P_0c09f276: /* original 905e, guest PC 0x0c09f276 */
if(!s->budget--) { s->failed_pc=0x0c09f276u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f336u,2);
goto P_0c09f278;
P_0c09f278: /* original e30f, guest PC 0x0c09f278 */
if(!s->budget--) { s->failed_pc=0x0c09f278u; return 0; }
r[3]=0x0000000fu;
goto P_0c09f27a;
P_0c09f27a: /* original e208, guest PC 0x0c09f27a */
if(!s->budget--) { s->failed_pc=0x0c09f27au; return 0; }
r[2]=0x00000008u;
goto P_0c09f27c;
P_0c09f27c: /* original 0d4d, guest PC 0x0c09f27c */
if(!s->budget--) { s->failed_pc=0x0c09f27cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f27e;
P_0c09f27e: /* original e03e, guest PC 0x0c09f27e */
if(!s->budget--) { s->failed_pc=0x0c09f27eu; return 0; }
r[0]=0x0000003eu;
goto P_0c09f280;
P_0c09f280: /* original 064d, guest PC 0x0c09f280 */
if(!s->budget--) { s->failed_pc=0x0c09f280u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f282;
P_0c09f282: /* original 6ddd, guest PC 0x0c09f282 */
if(!s->budget--) { s->failed_pc=0x0c09f282u; return 0; }
r[13]=r[13]&65535u;
goto P_0c09f284;
P_0c09f284: /* original 67d3, guest PC 0x0c09f284 */
if(!s->budget--) { s->failed_pc=0x0c09f284u; return 0; }
r[7]=r[13];
goto P_0c09f286;
P_0c09f286: /* original 666d, guest PC 0x0c09f286 */
if(!s->budget--) { s->failed_pc=0x0c09f286u; return 0; }
r[6]=r[6]&65535u;
goto P_0c09f288;
P_0c09f288: /* original 3768, guest PC 0x0c09f288 */
if(!s->budget--) { s->failed_pc=0x0c09f288u; return 0; }
r[7]-=r[6];
goto P_0c09f28a;
P_0c09f28a: /* original 3732, guest PC 0x0c09f28a */
if(!s->budget--) { s->failed_pc=0x0c09f28au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[3])!=0);
goto P_0c09f28c;
P_0c09f28c: /* original 0029, guest PC 0x0c09f28c */
if(!s->budget--) { s->failed_pc=0x0c09f28cu; return 0; }
r[0]=r[17]&1u;
goto P_0c09f28e;
P_0c09f28e: /* original 3726, guest PC 0x0c09f28e */
if(!s->budget--) { s->failed_pc=0x0c09f28eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[2])!=0);
goto P_0c09f290;
P_0c09f290: /* original 1f02, guest PC 0x0c09f290 */
if(!s->budget--) { s->failed_pc=0x0c09f290u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c09f292;
P_0c09f292: /* original 0029, guest PC 0x0c09f292 */
if(!s->budget--) { s->failed_pc=0x0c09f292u; return 0; }
r[0]=r[17]&1u;
goto P_0c09f294;
P_0c09f294: /* original 1f03, guest PC 0x0c09f294 */
if(!s->budget--) { s->failed_pc=0x0c09f294u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c09f296;
P_0c09f296: /* original 6763, guest PC 0x0c09f296 */
if(!s->budget--) { s->failed_pc=0x0c09f296u; return 0; }
r[7]=r[6];
goto P_0c09f298;
P_0c09f298: /* original 53f1, guest PC 0x0c09f298 */
if(!s->budget--) { s->failed_pc=0x0c09f298u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f29a;
P_0c09f29a: /* original 2338, guest PC 0x0c09f29a */
if(!s->budget--) { s->failed_pc=0x0c09f29au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f29c;
P_0c09f29c: /* original 8f02, guest PC 0x0c09f29c */
if(!s->budget--) { s->failed_pc=0x0c09f29cu; return 0; }
cond=r[17]&1u;
r[7]+=0x0000000eu;
if(!cond) { goto P_0c09f2a4; }
goto P_0c09f2a0;
P_0c09f29e: /* original 770e, guest PC 0x0c09f29e */
if(!s->budget--) { s->failed_pc=0x0c09f29eu; return 0; }
r[7]+=0x0000000eu;
goto P_0c09f2a0;
P_0c09f2a0: /* original 6763, guest PC 0x0c09f2a0 */
if(!s->budget--) { s->failed_pc=0x0c09f2a0u; return 0; }
r[7]=r[6];
goto P_0c09f2a2;
P_0c09f2a2: /* original 7707, guest PC 0x0c09f2a2 */
if(!s->budget--) { s->failed_pc=0x0c09f2a2u; return 0; }
r[7]+=0x00000007u;
goto P_0c09f2a4;
P_0c09f2a4: /* original 6cd3, guest PC 0x0c09f2a4 */
if(!s->budget--) { s->failed_pc=0x0c09f2a4u; return 0; }
r[12]=r[13];
goto P_0c09f2a6;
P_0c09f2a6: /* original 7cf9, guest PC 0x0c09f2a6 */
if(!s->budget--) { s->failed_pc=0x0c09f2a6u; return 0; }
r[12]+=0xfffffff9u;
goto P_0c09f2a8;
P_0c09f2a8: /* original 2fc2, guest PC 0x0c09f2a8 */
if(!s->budget--) { s->failed_pc=0x0c09f2a8u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c09f2aa;
P_0c09f2aa: /* original 53f4, guest PC 0x0c09f2aa */
if(!s->budget--) { s->failed_pc=0x0c09f2aau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c09f2ac;
P_0c09f2ac: /* original 2338, guest PC 0x0c09f2ac */
if(!s->budget--) { s->failed_pc=0x0c09f2acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f2ae;
P_0c09f2ae: /* original 8b02, guest PC 0x0c09f2ae */
if(!s->budget--) { s->failed_pc=0x0c09f2aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f2b6; }
goto P_0c09f2b0;
P_0c09f2b0: /* original 6cf2, guest PC 0x0c09f2b0 */
if(!s->budget--) { s->failed_pc=0x0c09f2b0u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c09f2b2;
P_0c09f2b2: /* original 6763, guest PC 0x0c09f2b2 */
if(!s->budget--) { s->failed_pc=0x0c09f2b2u; return 0; }
r[7]=r[6];
goto P_0c09f2b4;
P_0c09f2b4: /* original 7701, guest PC 0x0c09f2b4 */
if(!s->budget--) { s->failed_pc=0x0c09f2b4u; return 0; }
r[7]+=0x00000001u;
goto P_0c09f2b6;
P_0c09f2b6: /* original 53f2, guest PC 0x0c09f2b6 */
if(!s->budget--) { s->failed_pc=0x0c09f2b6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f2b8;
P_0c09f2b8: /* original 2338, guest PC 0x0c09f2b8 */
if(!s->budget--) { s->failed_pc=0x0c09f2b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f2ba;
P_0c09f2ba: /* original 8b07, guest PC 0x0c09f2ba */
if(!s->budget--) { s->failed_pc=0x0c09f2bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f2cc; }
goto P_0c09f2bc;
P_0c09f2bc: /* original 52f3, guest PC 0x0c09f2bc */
if(!s->budget--) { s->failed_pc=0x0c09f2bcu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c09f2be;
P_0c09f2be: /* original 6c73, guest PC 0x0c09f2be */
if(!s->budget--) { s->failed_pc=0x0c09f2beu; return 0; }
r[12]=r[7];
goto P_0c09f2c0;
P_0c09f2c0: /* original 2228, guest PC 0x0c09f2c0 */
if(!s->budget--) { s->failed_pc=0x0c09f2c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f2c2;
P_0c09f2c2: /* original 8f03, guest PC 0x0c09f2c2 */
if(!s->budget--) { s->failed_pc=0x0c09f2c2u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c09f2cc; }
goto P_0c09f2c6;
P_0c09f2c4: /* original 7c01, guest PC 0x0c09f2c4 */
if(!s->budget--) { s->failed_pc=0x0c09f2c4u; return 0; }
r[12]+=0x00000001u;
goto P_0c09f2c6;
P_0c09f2c6: /* original 6cd3, guest PC 0x0c09f2c6 */
if(!s->budget--) { s->failed_pc=0x0c09f2c6u; return 0; }
r[12]=r[13];
goto P_0c09f2c8;
P_0c09f2c8: /* original 7c01, guest PC 0x0c09f2c8 */
if(!s->budget--) { s->failed_pc=0x0c09f2c8u; return 0; }
r[12]+=0x00000001u;
goto P_0c09f2ca;
P_0c09f2ca: /* original 67d3, guest PC 0x0c09f2ca */
if(!s->budget--) { s->failed_pc=0x0c09f2cau; return 0; }
r[7]=r[13];
goto P_0c09f2cc;
P_0c09f2cc: /* original 9034, guest PC 0x0c09f2cc */
if(!s->budget--) { s->failed_pc=0x0c09f2ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f338u,2);
goto P_0c09f2ce;
P_0c09f2ce: /* original e200, guest PC 0x0c09f2ce */
if(!s->budget--) { s->failed_pc=0x0c09f2ceu; return 0; }
r[2]=0x00000000u;
goto P_0c09f2d0;
P_0c09f2d0: /* original 76ff, guest PC 0x0c09f2d0 */
if(!s->budget--) { s->failed_pc=0x0c09f2d0u; return 0; }
r[6]+=0xffffffffu;
goto P_0c09f2d2;
P_0c09f2d2: /* original 0424, guest PC 0x0c09f2d2 */
if(!s->budget--) { s->failed_pc=0x0c09f2d2u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09f2d4;
P_0c09f2d4: /* original 70f0, guest PC 0x0c09f2d4 */
if(!s->budget--) { s->failed_pc=0x0c09f2d4u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c09f2d6;
P_0c09f2d6: /* original 0475, guest PC 0x0c09f2d6 */
if(!s->budget--) { s->failed_pc=0x0c09f2d6u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c09f2d8;
P_0c09f2d8: /* original 7002, guest PC 0x0c09f2d8 */
if(!s->budget--) { s->failed_pc=0x0c09f2d8u; return 0; }
r[0]+=0x00000002u;
goto P_0c09f2da;
P_0c09f2da: /* original 04c5, guest PC 0x0c09f2da */
if(!s->budget--) { s->failed_pc=0x0c09f2dau; return 0; }
write(ram,r[4]+r[0],r[12],2);
goto P_0c09f2dc;
P_0c09f2dc: /* original 7002, guest PC 0x0c09f2dc */
if(!s->budget--) { s->failed_pc=0x0c09f2dcu; return 0; }
r[0]+=0x00000002u;
goto P_0c09f2de;
P_0c09f2de: /* original 0465, guest PC 0x0c09f2de */
if(!s->budget--) { s->failed_pc=0x0c09f2deu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c09f2e0;
P_0c09f2e0: /* original e04c, guest PC 0x0c09f2e0 */
if(!s->budget--) { s->failed_pc=0x0c09f2e0u; return 0; }
r[0]=0x0000004cu;
goto P_0c09f2e2;
P_0c09f2e2: /* original d318, guest PC 0x0c09f2e2 */
if(!s->budget--) { s->failed_pc=0x0c09f2e2u; return 0; }
r[3]=read(ram,0x0c09f344u,4);
goto P_0c09f2e4;
P_0c09f2e4: /* original 29e9, guest PC 0x0c09f2e4 */
if(!s->budget--) { s->failed_pc=0x0c09f2e4u; return 0; }
r[9]&=r[14];
goto P_0c09f2e6;
P_0c09f2e6: /* original 064e, guest PC 0x0c09f2e6 */
if(!s->budget--) { s->failed_pc=0x0c09f2e6u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c09f2e8;
P_0c09f2e8: /* original 2369, guest PC 0x0c09f2e8 */
if(!s->budget--) { s->failed_pc=0x0c09f2e8u; return 0; }
r[3]&=r[6];
goto P_0c09f2ea;
P_0c09f2ea: /* original 1f31, guest PC 0x0c09f2ea */
if(!s->budget--) { s->failed_pc=0x0c09f2eau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f2ec;
P_0c09f2ec: /* original d716, guest PC 0x0c09f2ec */
if(!s->budget--) { s->failed_pc=0x0c09f2ecu; return 0; }
r[7]=read(ram,0x0c09f348u,4);
goto P_0c09f2ee;
P_0c09f2ee: /* original 2f92, guest PC 0x0c09f2ee */
if(!s->budget--) { s->failed_pc=0x0c09f2eeu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c09f2f0;
P_0c09f2f0: /* original d216, guest PC 0x0c09f2f0 */
if(!s->budget--) { s->failed_pc=0x0c09f2f0u; return 0; }
r[2]=read(ram,0x0c09f34cu,4);
goto P_0c09f2f2;
P_0c09f2f2: /* original 2769, guest PC 0x0c09f2f2 */
if(!s->budget--) { s->failed_pc=0x0c09f2f2u; return 0; }
r[7]&=r[6];
goto P_0c09f2f4;
P_0c09f2f4: /* original 1f31, guest PC 0x0c09f2f4 */
if(!s->budget--) { s->failed_pc=0x0c09f2f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f2f6;
P_0c09f2f6: /* original 2629, guest PC 0x0c09f2f6 */
if(!s->budget--) { s->failed_pc=0x0c09f2f6u; return 0; }
r[6]&=r[2];
goto P_0c09f2f8;
P_0c09f2f8: /* original 1f64, guest PC 0x0c09f2f8 */
if(!s->budget--) { s->failed_pc=0x0c09f2f8u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c09f2fa;
P_0c09f2fa: /* original 53f1, guest PC 0x0c09f2fa */
if(!s->budget--) { s->failed_pc=0x0c09f2fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f2fc;
P_0c09f2fc: /* original 961d, guest PC 0x0c09f2fc */
if(!s->budget--) { s->failed_pc=0x0c09f2fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33au,2);
goto P_0c09f2fe;
P_0c09f2fe: /* original 2338, guest PC 0x0c09f2fe */
if(!s->budget--) { s->failed_pc=0x0c09f2feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f300;
P_0c09f300: /* original 8900, guest PC 0x0c09f300 */
if(!s->budget--) { s->failed_pc=0x0c09f300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f304; }
goto P_0c09f302;
P_0c09f302: /* original 2569, guest PC 0x0c09f302 */
if(!s->budget--) { s->failed_pc=0x0c09f302u; return 0; }
r[5]&=r[6];
goto P_0c09f304;
P_0c09f304: /* original 2778, guest PC 0x0c09f304 */
if(!s->budget--) { s->failed_pc=0x0c09f304u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f306;
P_0c09f306: /* original 8901, guest PC 0x0c09f306 */
if(!s->budget--) { s->failed_pc=0x0c09f306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f30c; }
goto P_0c09f308;
P_0c09f308: /* original 9218, guest PC 0x0c09f308 */
if(!s->budget--) { s->failed_pc=0x0c09f308u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33cu,2);
goto P_0c09f30a;
P_0c09f30a: /* original 2529, guest PC 0x0c09f30a */
if(!s->budget--) { s->failed_pc=0x0c09f30au; return 0; }
r[5]&=r[2];
goto P_0c09f30c;
P_0c09f30c: /* original 63f2, guest PC 0x0c09f30c */
if(!s->budget--) { s->failed_pc=0x0c09f30cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09f30e;
P_0c09f30e: /* original 2338, guest PC 0x0c09f30e */
if(!s->budget--) { s->failed_pc=0x0c09f30eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f310;
P_0c09f310: /* original 8b00, guest PC 0x0c09f310 */
if(!s->budget--) { s->failed_pc=0x0c09f310u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f314; }
goto P_0c09f312;
P_0c09f312: /* original 2569, guest PC 0x0c09f312 */
if(!s->budget--) { s->failed_pc=0x0c09f312u; return 0; }
r[5]&=r[6];
goto P_0c09f314;
P_0c09f314: /* original 52f4, guest PC 0x0c09f314 */
if(!s->budget--) { s->failed_pc=0x0c09f314u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c09f316;
P_0c09f316: /* original 2228, guest PC 0x0c09f316 */
if(!s->budget--) { s->failed_pc=0x0c09f316u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f318;
P_0c09f318: /* original 8901, guest PC 0x0c09f318 */
if(!s->budget--) { s->failed_pc=0x0c09f318u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f31e; }
goto P_0c09f31a;
P_0c09f31a: /* original e204, guest PC 0x0c09f31a */
if(!s->budget--) { s->failed_pc=0x0c09f31au; return 0; }
r[2]=0x00000004u;
goto P_0c09f31c;
P_0c09f31c: /* original 252b, guest PC 0x0c09f31c */
if(!s->budget--) { s->failed_pc=0x0c09f31cu; return 0; }
r[5]|=r[2];
goto P_0c09f31e;
P_0c09f31e: /* original 7f14, guest PC 0x0c09f31e */
if(!s->budget--) { s->failed_pc=0x0c09f31eu; return 0; }
r[15]+=0x00000014u;
goto P_0c09f320;
P_0c09f320: /* original 900d, guest PC 0x0c09f320 */
if(!s->budget--) { s->failed_pc=0x0c09f320u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33eu,2);
goto P_0c09f322;
P_0c09f322: /* original 0454, guest PC 0x0c09f322 */
if(!s->budget--) { s->failed_pc=0x0c09f322u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c09f324;
P_0c09f324: /* original 68f6, guest PC 0x0c09f324 */
if(!s->budget--) { s->failed_pc=0x0c09f324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09f326;
P_0c09f326: /* original d30a, guest PC 0x0c09f326 */
if(!s->budget--) { s->failed_pc=0x0c09f326u; return 0; }
r[3]=read(ram,0x0c09f350u,4);
goto P_0c09f328;
P_0c09f328: /* original 69f6, guest PC 0x0c09f328 */
if(!s->budget--) { s->failed_pc=0x0c09f328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09f32a;
P_0c09f32a: /* original 6af6, guest PC 0x0c09f32a */
if(!s->budget--) { s->failed_pc=0x0c09f32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09f32c;
P_0c09f32c: /* original 6bf6, guest PC 0x0c09f32c */
if(!s->budget--) { s->failed_pc=0x0c09f32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09f32e;
P_0c09f32e: /* original 6cf6, guest PC 0x0c09f32e */
if(!s->budget--) { s->failed_pc=0x0c09f32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f330;
P_0c09f330: /* original 6df6, guest PC 0x0c09f330 */
if(!s->budget--) { s->failed_pc=0x0c09f330u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f332;
P_0c09f332: /* original 432b, guest PC 0x0c09f332 */
if(!s->budget--) { s->failed_pc=0x0c09f332u; return 0; }
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
P_0c09f334: /* original 6ef6, guest PC 0x0c09f334 */
if(!s->budget--) { s->failed_pc=0x0c09f334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09f336u,s,ram);
P_0c0ac192: /* original 4f22, guest PC 0x0c0ac192 */
if(!s->budget--) { s->failed_pc=0x0c0ac192u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac194;
P_0c0ac194: /* original 7ffc, guest PC 0x0c0ac194 */
if(!s->budget--) { s->failed_pc=0x0c0ac194u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ac196;
P_0c0ac196: /* original 2f52, guest PC 0x0c0ac196 */
if(!s->budget--) { s->failed_pc=0x0c0ac196u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ac198;
P_0c0ac198: /* original 02ee, guest PC 0x0c0ac198 */
if(!s->budget--) { s->failed_pc=0x0c0ac198u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac19a;
P_0c0ac19a: /* original d33e, guest PC 0x0c0ac19a */
if(!s->budget--) { s->failed_pc=0x0c0ac19au; return 0; }
r[3]=read(ram,0x0c0ac294u,4);
goto P_0c0ac19c;
P_0c0ac19c: /* original 2239, guest PC 0x0c0ac19c */
if(!s->budget--) { s->failed_pc=0x0c0ac19cu; return 0; }
r[2]&=r[3];
goto P_0c0ac19e;
P_0c0ac19e: /* original 0e26, guest PC 0x0c0ac19e */
if(!s->budget--) { s->failed_pc=0x0c0ac19eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ac1a0;
P_0c0ac1a0: /* original 9075, guest PC 0x0c0ac1a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac28eu,2);
goto P_0c0ac1a2;
P_0c0ac1a2: /* original d23d, guest PC 0x0c0ac1a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a2u; return 0; }
r[2]=read(ram,0x0c0ac298u,4);
goto P_0c0ac1a4;
P_0c0ac1a4: /* original 04ed, guest PC 0x0c0ac1a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1a6;
P_0c0ac1a6: /* original e048, guest PC 0x0c0ac1a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a6u; return 0; }
r[0]=0x00000048u;
goto P_0c0ac1a8;
P_0c0ac1a8: /* original 01ee, guest PC 0x0c0ac1a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a8u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0ac1aa;
P_0c0ac1aa: /* original 2128, guest PC 0x0c0ac1aa */
if(!s->budget--) { s->failed_pc=0x0c0ac1aau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ac1ac;
P_0c0ac1ac: /* original 8d02, guest PC 0x0c0ac1ac */
if(!s->budget--) { s->failed_pc=0x0c0ac1acu; return 0; }
cond=r[17]&1u;
r[4]=r[4]&65535u;
if(cond) { goto P_0c0ac1b4; }
goto P_0c0ac1b0;
P_0c0ac1ae: /* original 644d, guest PC 0x0c0ac1ae */
if(!s->budget--) { s->failed_pc=0x0c0ac1aeu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ac1b0;
P_0c0ac1b0: /* original d33a, guest PC 0x0c0ac1b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b0u; return 0; }
r[3]=read(ram,0x0c0ac29cu,4);
goto P_0c0ac1b2;
P_0c0ac1b2: /* original 243a, guest PC 0x0c0ac1b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b2u; return 0; }
r[4]^=r[3];
goto P_0c0ac1b4;
P_0c0ac1b4: /* original 6043, guest PC 0x0c0ac1b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b4u; return 0; }
r[0]=r[4];
goto P_0c0ac1b6;
P_0c0ac1b6: /* original 81ef, guest PC 0x0c0ac1b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b6u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ac1b8;
P_0c0ac1b8: /* original 65f2, guest PC 0x0c0ac1b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ac1ba;
P_0c0ac1ba: /* original 6552, guest PC 0x0c0ac1ba */
if(!s->budget--) { s->failed_pc=0x0c0ac1bau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ac1bc;
P_0c0ac1bc: /* original 655d, guest PC 0x0c0ac1bc */
if(!s->budget--) { s->failed_pc=0x0c0ac1bcu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac1be;
P_0c0ac1be: /* original b7a8, guest PC 0x0c0ac1be */
if(!s->budget--) { s->failed_pc=0x0c0ac1beu; return 0; }
target=0x0c0ad112u; r[16]=0x0c0ac1c2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac1c2u) { target=s->pc; goto dispatch; }
goto P_0c0ac1c2;
P_0c0ac1c0: /* original 64e3, guest PC 0x0c0ac1c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c0u; return 0; }
r[4]=r[14];
goto P_0c0ac1c2;
P_0c0ac1c2: /* original 65f2, guest PC 0x0c0ac1c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ac1c4;
P_0c0ac1c4: /* original 7f04, guest PC 0x0c0ac1c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ac1c6;
P_0c0ac1c6: /* original 4f26, guest PC 0x0c0ac1c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac1c8;
P_0c0ac1c8: /* original 64e3, guest PC 0x0c0ac1c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c8u; return 0; }
r[4]=r[14];
goto P_0c0ac1ca;
P_0c0ac1ca: /* original a000, guest PC 0x0c0ac1ca */
if(!s->budget--) { s->failed_pc=0x0c0ac1cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac1ce;
P_0c0ac1cc: /* original 6ef6, guest PC 0x0c0ac1cc */
if(!s->budget--) { s->failed_pc=0x0c0ac1ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac1ce;
P_0c0ac1ce: /* original e304, guest PC 0x0c0ac1ce */
if(!s->budget--) { s->failed_pc=0x0c0ac1ceu; return 0; }
r[3]=0x00000004u;
goto P_0c0ac1d0;
P_0c0ac1d0: /* original e062, guest PC 0x0c0ac1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d0u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac1d2;
P_0c0ac1d2: /* original 6233, guest PC 0x0c0ac1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d2u; return 0; }
r[2]=r[3];
goto P_0c0ac1d4;
P_0c0ac1d4: /* original 1531, guest PC 0x0c0ac1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d4u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c0ac1d6;
P_0c0ac1d6: /* original a000, guest PC 0x0c0ac1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d6u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ac1da;
P_0c0ac1d8: /* original 0424, guest PC 0x0c0ac1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d8u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ac1da;
P_0c0ac1da: /* original 2fe6, guest PC 0x0c0ac1da */
if(!s->budget--) { s->failed_pc=0x0c0ac1dau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac1dc;
P_0c0ac1dc: /* original e03e, guest PC 0x0c0ac1dc */
if(!s->budget--) { s->failed_pc=0x0c0ac1dcu; return 0; }
r[0]=0x0000003eu;
goto P_0c0ac1de;
P_0c0ac1de: /* original 6e43, guest PC 0x0c0ac1de */
if(!s->budget--) { s->failed_pc=0x0c0ac1deu; return 0; }
r[14]=r[4];
goto P_0c0ac1e0;
P_0c0ac1e0: /* original 03ed, guest PC 0x0c0ac1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1e2;
P_0c0ac1e2: /* original 9055, guest PC 0x0c0ac1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac290u,2);
goto P_0c0ac1e4;
P_0c0ac1e4: /* original 4f22, guest PC 0x0c0ac1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac1e6;
P_0c0ac1e6: /* original 02ed, guest PC 0x0c0ac1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1e8;
P_0c0ac1e8: /* original 3322, guest PC 0x0c0ac1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ac1ea;
P_0c0ac1ea: /* original 8b1b, guest PC 0x0c0ac1ea */
if(!s->budget--) { s->failed_pc=0x0c0ac1eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac224; }
goto P_0c0ac1ec;
P_0c0ac1ec: /* original e048, guest PC 0x0c0ac1ec */
if(!s->budget--) { s->failed_pc=0x0c0ac1ecu; return 0; }
r[0]=0x00000048u;
goto P_0c0ac1ee;
P_0c0ac1ee: /* original d32c, guest PC 0x0c0ac1ee */
if(!s->budget--) { s->failed_pc=0x0c0ac1eeu; return 0; }
r[3]=read(ram,0x0c0ac2a0u,4);
goto P_0c0ac1f0;
P_0c0ac1f0: /* original 02ee, guest PC 0x0c0ac1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac1f2;
P_0c0ac1f2: /* original 2238, guest PC 0x0c0ac1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac1f4;
P_0c0ac1f4: /* original 8908, guest PC 0x0c0ac1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac208; }
goto P_0c0ac1f6;
P_0c0ac1f6: /* original 61e2, guest PC 0x0c0ac1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac1f8;
P_0c0ac1f8: /* original e000, guest PC 0x0c0ac1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f8u; return 0; }
r[0]=0x00000000u;
goto P_0c0ac1fa;
P_0c0ac1fa: /* original d22a, guest PC 0x0c0ac1fa */
if(!s->budget--) { s->failed_pc=0x0c0ac1fau; return 0; }
r[2]=read(ram,0x0c0ac2a4u,4);
goto P_0c0ac1fc;
P_0c0ac1fc: /* original 4f26, guest PC 0x0c0ac1fc */
if(!s->budget--) { s->failed_pc=0x0c0ac1fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac1fe;
P_0c0ac1fe: /* original 2129, guest PC 0x0c0ac1fe */
if(!s->budget--) { s->failed_pc=0x0c0ac1feu; return 0; }
r[1]&=r[2];
goto P_0c0ac200;
P_0c0ac200: /* original 2e12, guest PC 0x0c0ac200 */
if(!s->budget--) { s->failed_pc=0x0c0ac200u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ac202;
P_0c0ac202: /* original 1e0e, guest PC 0x0c0ac202 */
if(!s->budget--) { s->failed_pc=0x0c0ac202u; return 0; }
write(ram,r[14]+56,r[0],4);
goto P_0c0ac204;
P_0c0ac204: /* original 000b, guest PC 0x0c0ac204 */
if(!s->budget--) { s->failed_pc=0x0c0ac204u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac206: /* original 6ef6, guest PC 0x0c0ac206 */
if(!s->budget--) { s->failed_pc=0x0c0ac206u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac208;
P_0c0ac208: /* original 61e2, guest PC 0x0c0ac208 */
if(!s->budget--) { s->failed_pc=0x0c0ac208u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac20a;
P_0c0ac20a: /* original d224, guest PC 0x0c0ac20a */
if(!s->budget--) { s->failed_pc=0x0c0ac20au; return 0; }
r[2]=read(ram,0x0c0ac29cu,4);
goto P_0c0ac20c;
P_0c0ac20c: /* original 2128, guest PC 0x0c0ac20c */
if(!s->budget--) { s->failed_pc=0x0c0ac20cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ac20e;
P_0c0ac20e: /* original 8907, guest PC 0x0c0ac20e */
if(!s->budget--) { s->failed_pc=0x0c0ac20eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac220; }
goto P_0c0ac210;
P_0c0ac210: /* original d125, guest PC 0x0c0ac210 */
if(!s->budget--) { s->failed_pc=0x0c0ac210u; return 0; }
r[1]=read(ram,0x0c0ac2a8u,4);
goto P_0c0ac212;
P_0c0ac212: /* original 410b, guest PC 0x0c0ac212 */
if(!s->budget--) { s->failed_pc=0x0c0ac212u; return 0; }
target=r[1];
r[16]=0x0c0ac216u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac216u) { target=s->pc; goto dispatch; }
goto P_0c0ac216;
P_0c0ac214: /* original 64e3, guest PC 0x0c0ac214 */
if(!s->budget--) { s->failed_pc=0x0c0ac214u; return 0; }
r[4]=r[14];
goto P_0c0ac216;
P_0c0ac216: /* original 4f26, guest PC 0x0c0ac216 */
if(!s->budget--) { s->failed_pc=0x0c0ac216u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac218;
P_0c0ac218: /* original d324, guest PC 0x0c0ac218 */
if(!s->budget--) { s->failed_pc=0x0c0ac218u; return 0; }
r[3]=read(ram,0x0c0ac2acu,4);
goto P_0c0ac21a;
P_0c0ac21a: /* original 1e3d, guest PC 0x0c0ac21a */
if(!s->budget--) { s->failed_pc=0x0c0ac21au; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0ac21c;
P_0c0ac21c: /* original 000b, guest PC 0x0c0ac21c */
if(!s->budget--) { s->failed_pc=0x0c0ac21cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac21e: /* original 6ef6, guest PC 0x0c0ac21e */
if(!s->budget--) { s->failed_pc=0x0c0ac21eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac220;
P_0c0ac220: /* original d123, guest PC 0x0c0ac220 */
if(!s->budget--) { s->failed_pc=0x0c0ac220u; return 0; }
r[1]=read(ram,0x0c0ac2b0u,4);
goto P_0c0ac222;
P_0c0ac222: /* original 1e1d, guest PC 0x0c0ac222 */
if(!s->budget--) { s->failed_pc=0x0c0ac222u; return 0; }
write(ram,r[14]+52,r[1],4);
goto P_0c0ac224;
P_0c0ac224: /* original 4f26, guest PC 0x0c0ac224 */
if(!s->budget--) { s->failed_pc=0x0c0ac224u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac226;
P_0c0ac226: /* original 000b, guest PC 0x0c0ac226 */
if(!s->budget--) { s->failed_pc=0x0c0ac226u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac228: /* original 6ef6, guest PC 0x0c0ac228 */
if(!s->budget--) { s->failed_pc=0x0c0ac228u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac22au,s,ram);
P_0c0ad112: /* original 2fe6, guest PC 0x0c0ad112 */
if(!s->budget--) { s->failed_pc=0x0c0ad112u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad114;
P_0c0ad114: /* original 6e43, guest PC 0x0c0ad114 */
if(!s->budget--) { s->failed_pc=0x0c0ad114u; return 0; }
r[14]=r[4];
goto P_0c0ad116;
P_0c0ad116: /* original 4f22, guest PC 0x0c0ad116 */
if(!s->budget--) { s->failed_pc=0x0c0ad116u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad118;
P_0c0ad118: /* original 7ffc, guest PC 0x0c0ad118 */
if(!s->budget--) { s->failed_pc=0x0c0ad118u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad11a;
P_0c0ad11a: /* original 2f52, guest PC 0x0c0ad11a */
if(!s->budget--) { s->failed_pc=0x0c0ad11au; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ad11c;
P_0c0ad11c: /* original 900c, guest PC 0x0c0ad11c */
if(!s->budget--) { s->failed_pc=0x0c0ad11cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad138u,2);
goto P_0c0ad11e;
P_0c0ad11e: /* original 03ec, guest PC 0x0c0ad11e */
if(!s->budget--) { s->failed_pc=0x0c0ad11eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ad120;
P_0c0ad120: /* original 633c, guest PC 0x0c0ad120 */
if(!s->budget--) { s->failed_pc=0x0c0ad120u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad122;
P_0c0ad122: /* original 4315, guest PC 0x0c0ad122 */
if(!s->budget--) { s->failed_pc=0x0c0ad122u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0ad124;
P_0c0ad124: /* original 891e, guest PC 0x0c0ad124 */
if(!s->budget--) { s->failed_pc=0x0c0ad124u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad164; }
goto P_0c0ad126;
P_0c0ad126: /* original d30e, guest PC 0x0c0ad126 */
if(!s->budget--) { s->failed_pc=0x0c0ad126u; return 0; }
r[3]=read(ram,0x0c0ad160u,4);
goto P_0c0ad128;
P_0c0ad128: /* original 430b, guest PC 0x0c0ad128 */
if(!s->budget--) { s->failed_pc=0x0c0ad128u; return 0; }
target=r[3];
r[16]=0x0c0ad12cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ad12cu) { target=s->pc; goto dispatch; }
goto P_0c0ad12c;
P_0c0ad12a: /* original 64e3, guest PC 0x0c0ad12a */
if(!s->budget--) { s->failed_pc=0x0c0ad12au; return 0; }
r[4]=r[14];
goto P_0c0ad12c;
P_0c0ad12c: /* original a01d, guest PC 0x0c0ad12c */
if(!s->budget--) { s->failed_pc=0x0c0ad12cu; return 0; }
goto P_0c0ad16a;
P_0c0ad12e: /* original 0009, guest PC 0x0c0ad12e */
if(!s->budget--) { s->failed_pc=0x0c0ad12eu; return 0; }
return vf3_matrix_family(0x0c0ad130u,s,ram);
P_0c0ad164: /* original d338, guest PC 0x0c0ad164 */
if(!s->budget--) { s->failed_pc=0x0c0ad164u; return 0; }
r[3]=read(ram,0x0c0ad248u,4);
goto P_0c0ad166;
P_0c0ad166: /* original 430b, guest PC 0x0c0ad166 */
if(!s->budget--) { s->failed_pc=0x0c0ad166u; return 0; }
target=r[3];
r[16]=0x0c0ad16au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ad16au) { target=s->pc; goto dispatch; }
goto P_0c0ad16a;
P_0c0ad168: /* original 64e3, guest PC 0x0c0ad168 */
if(!s->budget--) { s->failed_pc=0x0c0ad168u; return 0; }
r[4]=r[14];
goto P_0c0ad16a;
P_0c0ad16a: /* original 65f2, guest PC 0x0c0ad16a */
if(!s->budget--) { s->failed_pc=0x0c0ad16au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ad16c;
P_0c0ad16c: /* original 7f04, guest PC 0x0c0ad16c */
if(!s->budget--) { s->failed_pc=0x0c0ad16cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ad16e;
P_0c0ad16e: /* original 4f26, guest PC 0x0c0ad16e */
if(!s->budget--) { s->failed_pc=0x0c0ad16eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad170;
P_0c0ad170: /* original e601, guest PC 0x0c0ad170 */
if(!s->budget--) { s->failed_pc=0x0c0ad170u; return 0; }
r[6]=0x00000001u;
goto P_0c0ad172;
P_0c0ad172: /* original 64e3, guest PC 0x0c0ad172 */
if(!s->budget--) { s->failed_pc=0x0c0ad172u; return 0; }
r[4]=r[14];
goto P_0c0ad174;
P_0c0ad174: /* original a019, guest PC 0x0c0ad174 */
if(!s->budget--) { s->failed_pc=0x0c0ad174u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad1aa;
P_0c0ad176: /* original 6ef6, guest PC 0x0c0ad176 */
if(!s->budget--) { s->failed_pc=0x0c0ad176u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ad178u,s,ram);
P_0c0ad1aa: /* original 2fe6, guest PC 0x0c0ad1aa */
if(!s->budget--) { s->failed_pc=0x0c0ad1aau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1ac;
P_0c0ad1ac: /* original 6e43, guest PC 0x0c0ad1ac */
if(!s->budget--) { s->failed_pc=0x0c0ad1acu; return 0; }
r[14]=r[4];
goto P_0c0ad1ae;
P_0c0ad1ae: /* original 2fd6, guest PC 0x0c0ad1ae */
if(!s->budget--) { s->failed_pc=0x0c0ad1aeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b0;
P_0c0ad1b0: /* original 2fc6, guest PC 0x0c0ad1b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b2;
P_0c0ad1b2: /* original 2fb6, guest PC 0x0c0ad1b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b4;
P_0c0ad1b4: /* original 2fa6, guest PC 0x0c0ad1b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad1b6;
P_0c0ad1b6: /* original 84e4, guest PC 0x0c0ad1b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0ad1b8;
P_0c0ad1b8: /* original 4f22, guest PC 0x0c0ad1b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad1ba;
P_0c0ad1ba: /* original d425, guest PC 0x0c0ad1ba */
if(!s->budget--) { s->failed_pc=0x0c0ad1bau; return 0; }
r[4]=read(ram,0x0c0ad250u,4);
goto P_0c0ad1bc;
P_0c0ad1bc: /* original 2008, guest PC 0x0c0ad1bc */
if(!s->budget--) { s->failed_pc=0x0c0ad1bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0ad1be;
P_0c0ad1be: /* original 8f02, guest PC 0x0c0ad1be */
if(!s->budget--) { s->failed_pc=0x0c0ad1beu; return 0; }
cond=r[17]&1u;
r[0]=0x00000048u;
if(!cond) { goto P_0c0ad1c6; }
goto P_0c0ad1c2;
P_0c0ad1c0: /* original e048, guest PC 0x0c0ad1c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c0u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad1c2;
P_0c0ad1c2: /* original a001, guest PC 0x0c0ad1c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c2u; return 0; }
r[12]=read(ram,r[4]+20,4);
goto P_0c0ad1c8;
P_0c0ad1c4: /* original 5c45, guest PC 0x0c0ad1c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c4u; return 0; }
r[12]=read(ram,r[4]+20,4);
goto P_0c0ad1c6;
P_0c0ad1c6: /* original 5c44, guest PC 0x0c0ad1c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c6u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c0ad1c8;
P_0c0ad1c8: /* original 04ee, guest PC 0x0c0ad1c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1c8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ad1ca;
P_0c0ad1ca: /* original ed00, guest PC 0x0c0ad1ca */
if(!s->budget--) { s->failed_pc=0x0c0ad1cau; return 0; }
r[13]=0x00000000u;
goto P_0c0ad1cc;
P_0c0ad1cc: /* original 9036, guest PC 0x0c0ad1cc */
if(!s->budget--) { s->failed_pc=0x0c0ad1ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad23cu,2);
goto P_0c0ad1ce;
P_0c0ad1ce: /* original 2558, guest PC 0x0c0ad1ce */
if(!s->budget--) { s->failed_pc=0x0c0ad1ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ad1d0;
P_0c0ad1d0: /* original f38d, guest PC 0x0c0ad1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d0u; return 0; }
fr[3]=0;
goto P_0c0ad1d2;
P_0c0ad1d2: /* original fe37, guest PC 0x0c0ad1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad1d4;
P_0c0ad1d4: /* original 7066, guest PC 0x0c0ad1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d4u; return 0; }
r[0]+=0x00000066u;
goto P_0c0ad1d6;
P_0c0ad1d6: /* original 0ed4, guest PC 0x0c0ad1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0ad1d8;
P_0c0ad1d8: /* original 8f08, guest PC 0x0c0ad1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1d8u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[7]=tmp;
if(!cond) { goto P_0c0ad1ec; }
goto P_0c0ad1dc;
P_0c0ad1da: /* original 67e2, guest PC 0x0c0ad1da */
if(!s->budget--) { s->failed_pc=0x0c0ad1dau; return 0; }
tmp=read(ram,r[14],4);
r[7]=tmp;
goto P_0c0ad1dc;
P_0c0ad1dc: /* original e048, guest PC 0x0c0ad1dc */
if(!s->budget--) { s->failed_pc=0x0c0ad1dcu; return 0; }
r[0]=0x00000048u;
goto P_0c0ad1de;
P_0c0ad1de: /* original d31d, guest PC 0x0c0ad1de */
if(!s->budget--) { s->failed_pc=0x0c0ad1deu; return 0; }
r[3]=read(ram,0x0c0ad254u,4);
goto P_0c0ad1e0;
P_0c0ad1e0: /* original 02ee, guest PC 0x0c0ad1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ad1e2;
P_0c0ad1e2: /* original 2239, guest PC 0x0c0ad1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e2u; return 0; }
r[2]&=r[3];
goto P_0c0ad1e4;
P_0c0ad1e4: /* original 0e26, guest PC 0x0c0ad1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ad1e6;
P_0c0ad1e6: /* original e03c, guest PC 0x0c0ad1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e6u; return 0; }
r[0]=0x0000003cu;
goto P_0c0ad1e8;
P_0c0ad1e8: /* original a0ad, guest PC 0x0c0ad1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1e8u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad346;
P_0c0ad1ea: /* original 0e55, guest PC 0x0c0ad1ea */
if(!s->budget--) { s->failed_pc=0x0c0ad1eau; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad1ec;
P_0c0ad1ec: /* original d31a, guest PC 0x0c0ad1ec */
if(!s->budget--) { s->failed_pc=0x0c0ad1ecu; return 0; }
r[3]=read(ram,0x0c0ad258u,4);
goto P_0c0ad1ee;
P_0c0ad1ee: /* original e2ef, guest PC 0x0c0ad1ee */
if(!s->budget--) { s->failed_pc=0x0c0ad1eeu; return 0; }
r[2]=0xffffffefu;
goto P_0c0ad1f0;
P_0c0ad1f0: /* original 273b, guest PC 0x0c0ad1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f0u; return 0; }
r[7]|=r[3];
goto P_0c0ad1f2;
P_0c0ad1f2: /* original 2729, guest PC 0x0c0ad1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f2u; return 0; }
r[7]&=r[2];
goto P_0c0ad1f4;
P_0c0ad1f4: /* original 2e72, guest PC 0x0c0ad1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f4u; return 0; }
write(ram,r[14],r[7],4);
goto P_0c0ad1f6;
P_0c0ad1f6: /* original 9122, guest PC 0x0c0ad1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad23eu,2);
goto P_0c0ad1f8;
P_0c0ad1f8: /* original 2158, guest PC 0x0c0ad1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad1f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c0ad1fa;
P_0c0ad1fa: /* original 8d04, guest PC 0x0c0ad1fa */
if(!s->budget--) { s->failed_pc=0x0c0ad1fau; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c0ad206; }
goto P_0c0ad1fe;
P_0c0ad1fc: /* original e701, guest PC 0x0c0ad1fc */
if(!s->budget--) { s->failed_pc=0x0c0ad1fcu; return 0; }
r[7]=0x00000001u;
goto P_0c0ad1fe;
P_0c0ad1fe: /* original 901f, guest PC 0x0c0ad1fe */
if(!s->budget--) { s->failed_pc=0x0c0ad1feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad240u,2);
goto P_0c0ad200;
P_0c0ad200: /* original 0e74, guest PC 0x0c0ad200 */
if(!s->budget--) { s->failed_pc=0x0c0ad200u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0ad202;
P_0c0ad202: /* original d316, guest PC 0x0c0ad202 */
if(!s->budget--) { s->failed_pc=0x0c0ad202u; return 0; }
r[3]=read(ram,0x0c0ad25cu,4);
goto P_0c0ad204;
P_0c0ad204: /* original 2439, guest PC 0x0c0ad204 */
if(!s->budget--) { s->failed_pc=0x0c0ad204u; return 0; }
r[4]&=r[3];
goto P_0c0ad206;
P_0c0ad206: /* original 6243, guest PC 0x0c0ad206 */
if(!s->budget--) { s->failed_pc=0x0c0ad206u; return 0; }
r[2]=r[4];
goto P_0c0ad208;
P_0c0ad208: /* original 2278, guest PC 0x0c0ad208 */
if(!s->budget--) { s->failed_pc=0x0c0ad208u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0ad20a;
P_0c0ad20a: /* original 8902, guest PC 0x0c0ad20a */
if(!s->budget--) { s->failed_pc=0x0c0ad20au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad212; }
goto P_0c0ad20c;
P_0c0ad20c: /* original 60e2, guest PC 0x0c0ad20c */
if(!s->budget--) { s->failed_pc=0x0c0ad20cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0ad20e;
P_0c0ad20e: /* original cb04, guest PC 0x0c0ad20e */
if(!s->budget--) { s->failed_pc=0x0c0ad20eu; return 0; }
r[0]|=4u;
goto P_0c0ad210;
P_0c0ad210: /* original 2e02, guest PC 0x0c0ad210 */
if(!s->budget--) { s->failed_pc=0x0c0ad210u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0ad212;
P_0c0ad212: /* original 9216, guest PC 0x0c0ad212 */
if(!s->budget--) { s->failed_pc=0x0c0ad212u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad242u,2);
goto P_0c0ad214;
P_0c0ad214: /* original 2258, guest PC 0x0c0ad214 */
if(!s->budget--) { s->failed_pc=0x0c0ad214u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0ad216;
P_0c0ad216: /* original 8903, guest PC 0x0c0ad216 */
if(!s->budget--) { s->failed_pc=0x0c0ad216u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad220; }
goto P_0c0ad218;
P_0c0ad218: /* original 9012, guest PC 0x0c0ad218 */
if(!s->budget--) { s->failed_pc=0x0c0ad218u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad240u,2);
goto P_0c0ad21a;
P_0c0ad21a: /* original 0e74, guest PC 0x0c0ad21a */
if(!s->budget--) { s->failed_pc=0x0c0ad21au; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0ad21c;
P_0c0ad21c: /* original d310, guest PC 0x0c0ad21c */
if(!s->budget--) { s->failed_pc=0x0c0ad21cu; return 0; }
r[3]=read(ram,0x0c0ad260u,4);
goto P_0c0ad21e;
P_0c0ad21e: /* original 2439, guest PC 0x0c0ad21e */
if(!s->budget--) { s->failed_pc=0x0c0ad21eu; return 0; }
r[4]&=r[3];
goto P_0c0ad220;
P_0c0ad220: /* original d710, guest PC 0x0c0ad220 */
if(!s->budget--) { s->failed_pc=0x0c0ad220u; return 0; }
r[7]=read(ram,0x0c0ad264u,4);
goto P_0c0ad222;
P_0c0ad222: /* original 6243, guest PC 0x0c0ad222 */
if(!s->budget--) { s->failed_pc=0x0c0ad222u; return 0; }
r[2]=r[4];
goto P_0c0ad224;
P_0c0ad224: /* original 2278, guest PC 0x0c0ad224 */
if(!s->budget--) { s->failed_pc=0x0c0ad224u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0ad226;
P_0c0ad226: /* original 8926, guest PC 0x0c0ad226 */
if(!s->budget--) { s->failed_pc=0x0c0ad226u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad276; }
goto P_0c0ad228;
P_0c0ad228: /* original 6063, guest PC 0x0c0ad228 */
if(!s->budget--) { s->failed_pc=0x0c0ad228u; return 0; }
r[0]=r[6];
goto P_0c0ad22a;
P_0c0ad22a: /* original 8801, guest PC 0x0c0ad22a */
if(!s->budget--) { s->failed_pc=0x0c0ad22au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ad22c;
P_0c0ad22c: /* original 8b1e, guest PC 0x0c0ad22c */
if(!s->budget--) { s->failed_pc=0x0c0ad22cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad26c; }
goto P_0c0ad22e;
P_0c0ad22e: /* original d30e, guest PC 0x0c0ad22e */
if(!s->budget--) { s->failed_pc=0x0c0ad22eu; return 0; }
r[3]=read(ram,0x0c0ad268u,4);
goto P_0c0ad230;
P_0c0ad230: /* original 2348, guest PC 0x0c0ad230 */
if(!s->budget--) { s->failed_pc=0x0c0ad230u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ad232;
P_0c0ad232: /* original 891b, guest PC 0x0c0ad232 */
if(!s->budget--) { s->failed_pc=0x0c0ad232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad26c; }
goto P_0c0ad234;
P_0c0ad234: /* original 9006, guest PC 0x0c0ad234 */
if(!s->budget--) { s->failed_pc=0x0c0ad234u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad244u,2);
goto P_0c0ad236;
P_0c0ad236: /* original a01d, guest PC 0x0c0ad236 */
if(!s->budget--) { s->failed_pc=0x0c0ad236u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad274;
P_0c0ad238: /* original 00ed, guest PC 0x0c0ad238 */
if(!s->budget--) { s->failed_pc=0x0c0ad238u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
return vf3_matrix_family(0x0c0ad23au,s,ram);
P_0c0ad26c: /* original 9072, guest PC 0x0c0ad26c */
if(!s->budget--) { s->failed_pc=0x0c0ad26cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad354u,2);
goto P_0c0ad26e;
P_0c0ad26e: /* original 03ed, guest PC 0x0c0ad26e */
if(!s->budget--) { s->failed_pc=0x0c0ad26eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad270;
P_0c0ad270: /* original 85ef, guest PC 0x0c0ad270 */
if(!s->budget--) { s->failed_pc=0x0c0ad270u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0ad272;
P_0c0ad272: /* original 303c, guest PC 0x0c0ad272 */
if(!s->budget--) { s->failed_pc=0x0c0ad272u; return 0; }
r[0]+=r[3];
goto P_0c0ad274;
P_0c0ad274: /* original 81ef, guest PC 0x0c0ad274 */
if(!s->budget--) { s->failed_pc=0x0c0ad274u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ad276;
P_0c0ad276: /* original da3e, guest PC 0x0c0ad276 */
if(!s->budget--) { s->failed_pc=0x0c0ad276u; return 0; }
r[10]=read(ram,0x0c0ad370u,4);
goto P_0c0ad278;
P_0c0ad278: /* original 2a49, guest PC 0x0c0ad278 */
if(!s->budget--) { s->failed_pc=0x0c0ad278u; return 0; }
r[10]&=r[4];
goto P_0c0ad27a;
P_0c0ad27a: /* original 2aa8, guest PC 0x0c0ad27a */
if(!s->budget--) { s->failed_pc=0x0c0ad27au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ad27c;
P_0c0ad27c: /* original 8907, guest PC 0x0c0ad27c */
if(!s->budget--) { s->failed_pc=0x0c0ad27cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad28e; }
goto P_0c0ad27e;
P_0c0ad27e: /* original 906a, guest PC 0x0c0ad27e */
if(!s->budget--) { s->failed_pc=0x0c0ad27eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad356u,2);
goto P_0c0ad280;
P_0c0ad280: /* original f3e6, guest PC 0x0c0ad280 */
if(!s->budget--) { s->failed_pc=0x0c0ad280u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ad282;
P_0c0ad282: /* original e010, guest PC 0x0c0ad282 */
if(!s->budget--) { s->failed_pc=0x0c0ad282u; return 0; }
r[0]=0x00000010u;
goto P_0c0ad284;
P_0c0ad284: /* original fe37, guest PC 0x0c0ad284 */
if(!s->budget--) { s->failed_pc=0x0c0ad284u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad286;
P_0c0ad286: /* original 9067, guest PC 0x0c0ad286 */
if(!s->budget--) { s->failed_pc=0x0c0ad286u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad358u,2);
goto P_0c0ad288;
P_0c0ad288: /* original f3e6, guest PC 0x0c0ad288 */
if(!s->budget--) { s->failed_pc=0x0c0ad288u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ad28a;
P_0c0ad28a: /* original e018, guest PC 0x0c0ad28a */
if(!s->budget--) { s->failed_pc=0x0c0ad28au; return 0; }
r[0]=0x00000018u;
goto P_0c0ad28c;
P_0c0ad28c: /* original fe37, guest PC 0x0c0ad28c */
if(!s->budget--) { s->failed_pc=0x0c0ad28cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ad28e;
P_0c0ad28e: /* original 9164, guest PC 0x0c0ad28e */
if(!s->budget--) { s->failed_pc=0x0c0ad28eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35au,2);
goto P_0c0ad290;
P_0c0ad290: /* original e014, guest PC 0x0c0ad290 */
if(!s->budget--) { s->failed_pc=0x0c0ad290u; return 0; }
r[0]=0x00000014u;
goto P_0c0ad292;
P_0c0ad292: /* original f2e6, guest PC 0x0c0ad292 */
if(!s->budget--) { s->failed_pc=0x0c0ad292u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ad294;
P_0c0ad294: /* original 31ec, guest PC 0x0c0ad294 */
if(!s->budget--) { s->failed_pc=0x0c0ad294u; return 0; }
r[1]+=r[14];
goto P_0c0ad296;
P_0c0ad296: /* original 9361, guest PC 0x0c0ad296 */
if(!s->budget--) { s->failed_pc=0x0c0ad296u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35cu,2);
goto P_0c0ad298;
P_0c0ad298: /* original f318, guest PC 0x0c0ad298 */
if(!s->budget--) { s->failed_pc=0x0c0ad298u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0ad29a;
P_0c0ad29a: /* original 2438, guest PC 0x0c0ad29a */
if(!s->budget--) { s->failed_pc=0x0c0ad29au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0ad29c;
P_0c0ad29c: /* original f230, guest PC 0x0c0ad29c */
if(!s->budget--) { s->failed_pc=0x0c0ad29cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0ad29e;
P_0c0ad29e: /* original 8d03, guest PC 0x0c0ad29e */
if(!s->budget--) { s->failed_pc=0x0c0ad29eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[14]+r[0]);
if(cond) { goto P_0c0ad2a8; }
goto P_0c0ad2a2;
P_0c0ad2a0: /* original fe27, guest PC 0x0c0ad2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a0u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0ad2a2;
P_0c0ad2a2: /* original 61e2, guest PC 0x0c0ad2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a2u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ad2a4;
P_0c0ad2a4: /* original 217a, guest PC 0x0c0ad2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a4u; return 0; }
r[1]^=r[7];
goto P_0c0ad2a6;
P_0c0ad2a6: /* original 2e12, guest PC 0x0c0ad2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a6u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ad2a8;
P_0c0ad2a8: /* original db32, guest PC 0x0c0ad2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2a8u; return 0; }
r[11]=read(ram,0x0c0ad374u,4);
goto P_0c0ad2aa;
P_0c0ad2aa: /* original 2b59, guest PC 0x0c0ad2aa */
if(!s->budget--) { s->failed_pc=0x0c0ad2aau; return 0; }
r[11]&=r[5];
goto P_0c0ad2ac;
P_0c0ad2ac: /* original 2bb8, guest PC 0x0c0ad2ac */
if(!s->budget--) { s->failed_pc=0x0c0ad2acu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0ad2ae;
P_0c0ad2ae: /* original 8902, guest PC 0x0c0ad2ae */
if(!s->budget--) { s->failed_pc=0x0c0ad2aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2b6; }
goto P_0c0ad2b0;
P_0c0ad2b0: /* original 62e2, guest PC 0x0c0ad2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ad2b2;
P_0c0ad2b2: /* original 227a, guest PC 0x0c0ad2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b2u; return 0; }
r[2]^=r[7];
goto P_0c0ad2b4;
P_0c0ad2b4: /* original 2e22, guest PC 0x0c0ad2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b4u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ad2b6;
P_0c0ad2b6: /* original 9352, guest PC 0x0c0ad2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35eu,2);
goto P_0c0ad2b8;
P_0c0ad2b8: /* original e03c, guest PC 0x0c0ad2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2b8u; return 0; }
r[0]=0x0000003cu;
goto P_0c0ad2ba;
P_0c0ad2ba: /* original 2539, guest PC 0x0c0ad2ba */
if(!s->budget--) { s->failed_pc=0x0c0ad2bau; return 0; }
r[5]&=r[3];
goto P_0c0ad2bc;
P_0c0ad2bc: /* original 0e55, guest PC 0x0c0ad2bc */
if(!s->budget--) { s->failed_pc=0x0c0ad2bcu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad2be;
P_0c0ad2be: /* original 65c3, guest PC 0x0c0ad2be */
if(!s->budget--) { s->failed_pc=0x0c0ad2beu; return 0; }
r[5]=r[12];
goto P_0c0ad2c0;
P_0c0ad2c0: /* original 06ed, guest PC 0x0c0ad2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad2c2;
P_0c0ad2c2: /* original 666d, guest PC 0x0c0ad2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c2u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0ad2c4;
P_0c0ad2c4: /* original b064, guest PC 0x0c0ad2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c4u; return 0; }
target=0x0c0ad390u; r[16]=0x0c0ad2c8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ad2c8u) { target=s->pc; goto dispatch; }
goto P_0c0ad2c8;
P_0c0ad2c6: /* original 64e3, guest PC 0x0c0ad2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c6u; return 0; }
r[4]=r[14];
goto P_0c0ad2c8;
P_0c0ad2c8: /* original d32b, guest PC 0x0c0ad2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2c8u; return 0; }
r[3]=read(ram,0x0c0ad378u,4);
goto P_0c0ad2ca;
P_0c0ad2ca: /* original 430b, guest PC 0x0c0ad2ca */
if(!s->budget--) { s->failed_pc=0x0c0ad2cau; return 0; }
target=r[3];
r[16]=0x0c0ad2ceu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ad2ceu) { target=s->pc; goto dispatch; }
goto P_0c0ad2ce;
P_0c0ad2cc: /* original 64e3, guest PC 0x0c0ad2cc */
if(!s->budget--) { s->failed_pc=0x0c0ad2ccu; return 0; }
r[4]=r[14];
goto P_0c0ad2ce;
P_0c0ad2ce: /* original d22b, guest PC 0x0c0ad2ce */
if(!s->budget--) { s->failed_pc=0x0c0ad2ceu; return 0; }
r[2]=read(ram,0x0c0ad37cu,4);
goto P_0c0ad2d0;
P_0c0ad2d0: /* original 420b, guest PC 0x0c0ad2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d0u; return 0; }
target=r[2];
r[16]=0x0c0ad2d4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ad2d4u) { target=s->pc; goto dispatch; }
goto P_0c0ad2d4;
P_0c0ad2d2: /* original 64e3, guest PC 0x0c0ad2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d2u; return 0; }
r[4]=r[14];
goto P_0c0ad2d4;
P_0c0ad2d4: /* original 2bb8, guest PC 0x0c0ad2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0ad2d6;
P_0c0ad2d6: /* original e048, guest PC 0x0c0ad2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d6u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad2d8;
P_0c0ad2d8: /* original 8d02, guest PC 0x0c0ad2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2d8u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0ad2e0; }
goto P_0c0ad2dc;
P_0c0ad2da: /* original 04ee, guest PC 0x0c0ad2da */
if(!s->budget--) { s->failed_pc=0x0c0ad2dau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ad2dc;
P_0c0ad2dc: /* original 923e, guest PC 0x0c0ad2dc */
if(!s->budget--) { s->failed_pc=0x0c0ad2dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad35cu,2);
goto P_0c0ad2de;
P_0c0ad2de: /* original 242a, guest PC 0x0c0ad2de */
if(!s->budget--) { s->failed_pc=0x0c0ad2deu; return 0; }
r[4]^=r[2];
goto P_0c0ad2e0;
P_0c0ad2e0: /* original 2aa8, guest PC 0x0c0ad2e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ad2e2;
P_0c0ad2e2: /* original 8901, guest PC 0x0c0ad2e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2e8; }
goto P_0c0ad2e4;
P_0c0ad2e4: /* original d126, guest PC 0x0c0ad2e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e4u; return 0; }
r[1]=read(ram,0x0c0ad380u,4);
goto P_0c0ad2e6;
P_0c0ad2e6: /* original 241b, guest PC 0x0c0ad2e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e6u; return 0; }
r[4]|=r[1];
goto P_0c0ad2e8;
P_0c0ad2e8: /* original d626, guest PC 0x0c0ad2e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2e8u; return 0; }
r[6]=read(ram,0x0c0ad384u,4);
goto P_0c0ad2ea;
P_0c0ad2ea: /* original 2649, guest PC 0x0c0ad2ea */
if(!s->budget--) { s->failed_pc=0x0c0ad2eau; return 0; }
r[6]&=r[4];
goto P_0c0ad2ec;
P_0c0ad2ec: /* original 2668, guest PC 0x0c0ad2ec */
if(!s->budget--) { s->failed_pc=0x0c0ad2ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad2ee;
P_0c0ad2ee: /* original 8905, guest PC 0x0c0ad2ee */
if(!s->budget--) { s->failed_pc=0x0c0ad2eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad2fc; }
goto P_0c0ad2f0;
P_0c0ad2f0: /* original 9036, guest PC 0x0c0ad2f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad360u,2);
goto P_0c0ad2f2;
P_0c0ad2f2: /* original 02ed, guest PC 0x0c0ad2f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad2f4;
P_0c0ad2f4: /* original 7201, guest PC 0x0c0ad2f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f4u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ad2f6;
P_0c0ad2f6: /* original 0e25, guest PC 0x0c0ad2f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0ad2f8;
P_0c0ad2f8: /* original 70d6, guest PC 0x0c0ad2f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad2f8u; return 0; }
r[0]+=0xffffffd6u;
goto P_0c0ad2fa;
P_0c0ad2fa: /* original 0ed6, guest PC 0x0c0ad2fa */
if(!s->budget--) { s->failed_pc=0x0c0ad2fau; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad2fc;
P_0c0ad2fc: /* original 9331, guest PC 0x0c0ad2fc */
if(!s->budget--) { s->failed_pc=0x0c0ad2fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad362u,2);
goto P_0c0ad2fe;
P_0c0ad2fe: /* original 2348, guest PC 0x0c0ad2fe */
if(!s->budget--) { s->failed_pc=0x0c0ad2feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ad300;
P_0c0ad300: /* original 8904, guest PC 0x0c0ad300 */
if(!s->budget--) { s->failed_pc=0x0c0ad300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad30c; }
goto P_0c0ad302;
P_0c0ad302: /* original 902f, guest PC 0x0c0ad302 */
if(!s->budget--) { s->failed_pc=0x0c0ad302u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad364u,2);
goto P_0c0ad304;
P_0c0ad304: /* original 00ed, guest PC 0x0c0ad304 */
if(!s->budget--) { s->failed_pc=0x0c0ad304u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad306;
P_0c0ad306: /* original 81ef, guest PC 0x0c0ad306 */
if(!s->budget--) { s->failed_pc=0x0c0ad306u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ad308;
P_0c0ad308: /* original 902d, guest PC 0x0c0ad308 */
if(!s->budget--) { s->failed_pc=0x0c0ad308u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad366u,2);
goto P_0c0ad30a;
P_0c0ad30a: /* original 0ed6, guest PC 0x0c0ad30a */
if(!s->budget--) { s->failed_pc=0x0c0ad30au; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad30c;
P_0c0ad30c: /* original 902c, guest PC 0x0c0ad30c */
if(!s->budget--) { s->failed_pc=0x0c0ad30cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad368u,2);
goto P_0c0ad30e;
P_0c0ad30e: /* original 05ed, guest PC 0x0c0ad30e */
if(!s->budget--) { s->failed_pc=0x0c0ad30eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ad310;
P_0c0ad310: /* original 0ed5, guest PC 0x0c0ad310 */
if(!s->budget--) { s->failed_pc=0x0c0ad310u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0ad312;
P_0c0ad312: /* original 62e2, guest PC 0x0c0ad312 */
if(!s->budget--) { s->failed_pc=0x0c0ad312u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ad314;
P_0c0ad314: /* original d31c, guest PC 0x0c0ad314 */
if(!s->budget--) { s->failed_pc=0x0c0ad314u; return 0; }
r[3]=read(ram,0x0c0ad388u,4);
goto P_0c0ad316;
P_0c0ad316: /* original 2238, guest PC 0x0c0ad316 */
if(!s->budget--) { s->failed_pc=0x0c0ad316u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ad318;
P_0c0ad318: /* original 8b0a, guest PC 0x0c0ad318 */
if(!s->budget--) { s->failed_pc=0x0c0ad318u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad330; }
goto P_0c0ad31a;
P_0c0ad31a: /* original 2668, guest PC 0x0c0ad31a */
if(!s->budget--) { s->failed_pc=0x0c0ad31au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad31c;
P_0c0ad31c: /* original 8908, guest PC 0x0c0ad31c */
if(!s->budget--) { s->failed_pc=0x0c0ad31cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad330; }
goto P_0c0ad31e;
P_0c0ad31e: /* original 2558, guest PC 0x0c0ad31e */
if(!s->budget--) { s->failed_pc=0x0c0ad31eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ad320;
P_0c0ad320: /* original 8906, guest PC 0x0c0ad320 */
if(!s->budget--) { s->failed_pc=0x0c0ad320u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad330; }
goto P_0c0ad322;
P_0c0ad322: /* original 9022, guest PC 0x0c0ad322 */
if(!s->budget--) { s->failed_pc=0x0c0ad322u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36au,2);
goto P_0c0ad324;
P_0c0ad324: /* original 0e55, guest PC 0x0c0ad324 */
if(!s->budget--) { s->failed_pc=0x0c0ad324u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ad326;
P_0c0ad326: /* original 7008, guest PC 0x0c0ad326 */
if(!s->budget--) { s->failed_pc=0x0c0ad326u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ad328;
P_0c0ad328: /* original 03ee, guest PC 0x0c0ad328 */
if(!s->budget--) { s->failed_pc=0x0c0ad328u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0ad32a;
P_0c0ad32a: /* original 70fc, guest PC 0x0c0ad32a */
if(!s->budget--) { s->failed_pc=0x0c0ad32au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ad32c;
P_0c0ad32c: /* original a002, guest PC 0x0c0ad32c */
if(!s->budget--) { s->failed_pc=0x0c0ad32cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ad334;
P_0c0ad32e: /* original 0e36, guest PC 0x0c0ad32e */
if(!s->budget--) { s->failed_pc=0x0c0ad32eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ad330;
P_0c0ad330: /* original 901b, guest PC 0x0c0ad330 */
if(!s->budget--) { s->failed_pc=0x0c0ad330u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36au,2);
goto P_0c0ad332;
P_0c0ad332: /* original 0ed5, guest PC 0x0c0ad332 */
if(!s->budget--) { s->failed_pc=0x0c0ad332u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0ad334;
P_0c0ad334: /* original d515, guest PC 0x0c0ad334 */
if(!s->budget--) { s->failed_pc=0x0c0ad334u; return 0; }
r[5]=read(ram,0x0c0ad38cu,4);
goto P_0c0ad336;
P_0c0ad336: /* original 2548, guest PC 0x0c0ad336 */
if(!s->budget--) { s->failed_pc=0x0c0ad336u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c0ad338;
P_0c0ad338: /* original 8903, guest PC 0x0c0ad338 */
if(!s->budget--) { s->failed_pc=0x0c0ad338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad342; }
goto P_0c0ad33a;
P_0c0ad33a: /* original 9017, guest PC 0x0c0ad33a */
if(!s->budget--) { s->failed_pc=0x0c0ad33au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad36cu,2);
goto P_0c0ad33c;
P_0c0ad33c: /* original 0ed6, guest PC 0x0c0ad33c */
if(!s->budget--) { s->failed_pc=0x0c0ad33cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad33e;
P_0c0ad33e: /* original 7004, guest PC 0x0c0ad33e */
if(!s->budget--) { s->failed_pc=0x0c0ad33eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ad340;
P_0c0ad340: /* original 0ed6, guest PC 0x0c0ad340 */
if(!s->budget--) { s->failed_pc=0x0c0ad340u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0ad342;
P_0c0ad342: /* original e048, guest PC 0x0c0ad342 */
if(!s->budget--) { s->failed_pc=0x0c0ad342u; return 0; }
r[0]=0x00000048u;
goto P_0c0ad344;
P_0c0ad344: /* original 0e46, guest PC 0x0c0ad344 */
if(!s->budget--) { s->failed_pc=0x0c0ad344u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ad346;
P_0c0ad346: /* original 4f26, guest PC 0x0c0ad346 */
if(!s->budget--) { s->failed_pc=0x0c0ad346u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad348;
P_0c0ad348: /* original 6af6, guest PC 0x0c0ad348 */
if(!s->budget--) { s->failed_pc=0x0c0ad348u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ad34a;
P_0c0ad34a: /* original 6bf6, guest PC 0x0c0ad34a */
if(!s->budget--) { s->failed_pc=0x0c0ad34au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ad34c;
P_0c0ad34c: /* original 6cf6, guest PC 0x0c0ad34c */
if(!s->budget--) { s->failed_pc=0x0c0ad34cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad34e;
P_0c0ad34e: /* original 6df6, guest PC 0x0c0ad34e */
if(!s->budget--) { s->failed_pc=0x0c0ad34eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad350;
P_0c0ad350: /* original 000b, guest PC 0x0c0ad350 */
if(!s->budget--) { s->failed_pc=0x0c0ad350u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ad352: /* original 6ef6, guest PC 0x0c0ad352 */
if(!s->budget--) { s->failed_pc=0x0c0ad352u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ad354u,s,ram);
P_0c0ad390: /* original 2fe6, guest PC 0x0c0ad390 */
if(!s->budget--) { s->failed_pc=0x0c0ad390u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad392;
P_0c0ad392: /* original e700, guest PC 0x0c0ad392 */
if(!s->budget--) { s->failed_pc=0x0c0ad392u; return 0; }
r[7]=0x00000000u;
goto P_0c0ad394;
P_0c0ad394: /* original 2fd6, guest PC 0x0c0ad394 */
if(!s->budget--) { s->failed_pc=0x0c0ad394u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad396;
P_0c0ad396: /* original 2fc6, guest PC 0x0c0ad396 */
if(!s->budget--) { s->failed_pc=0x0c0ad396u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad398;
P_0c0ad398: /* original dd5a, guest PC 0x0c0ad398 */
if(!s->budget--) { s->failed_pc=0x0c0ad398u; return 0; }
r[13]=read(ram,0x0c0ad504u,4);
goto P_0c0ad39a;
P_0c0ad39a: /* original 7ff8, guest PC 0x0c0ad39a */
if(!s->budget--) { s->failed_pc=0x0c0ad39au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ad39c;
P_0c0ad39c: /* original 909f, guest PC 0x0c0ad39c */
if(!s->budget--) { s->failed_pc=0x0c0ad39cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4deu,2);
goto P_0c0ad39e;
P_0c0ad39e: /* original 0ede, guest PC 0x0c0ad39e */
if(!s->budget--) { s->failed_pc=0x0c0ad39eu; return 0; }
r[14]=read(ram,r[13]+r[0],4);
goto P_0c0ad3a0;
P_0c0ad3a0: /* original 70fc, guest PC 0x0c0ad3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a0u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ad3a2;
P_0c0ad3a2: /* original 0cde, guest PC 0x0c0ad3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a2u; return 0; }
r[12]=read(ram,r[13]+r[0],4);
goto P_0c0ad3a4;
P_0c0ad3a4: /* original 909c, guest PC 0x0c0ad3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e0u,2);
goto P_0c0ad3a6;
P_0c0ad3a6: /* original 0475, guest PC 0x0c0ad3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a6u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0ad3a8;
P_0c0ad3a8: /* original 7028, guest PC 0x0c0ad3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3a8u; return 0; }
r[0]+=0x00000028u;
goto P_0c0ad3aa;
P_0c0ad3aa: /* original 0475, guest PC 0x0c0ad3aa */
if(!s->budget--) { s->failed_pc=0x0c0ad3aau; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0ad3ac;
P_0c0ad3ac: /* original e063, guest PC 0x0c0ad3ac */
if(!s->budget--) { s->failed_pc=0x0c0ad3acu; return 0; }
r[0]=0x00000063u;
goto P_0c0ad3ae;
P_0c0ad3ae: /* original 0474, guest PC 0x0c0ad3ae */
if(!s->budget--) { s->failed_pc=0x0c0ad3aeu; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3b0;
P_0c0ad3b0: /* original 9097, guest PC 0x0c0ad3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e2u,2);
goto P_0c0ad3b2;
P_0c0ad3b2: /* original 0475, guest PC 0x0c0ad3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b2u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0ad3b4;
P_0c0ad3b4: /* original 7022, guest PC 0x0c0ad3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b4u; return 0; }
r[0]+=0x00000022u;
goto P_0c0ad3b6;
P_0c0ad3b6: /* original 0476, guest PC 0x0c0ad3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b6u; return 0; }
write(ram,r[4]+r[0],r[7],4);
goto P_0c0ad3b8;
P_0c0ad3b8: /* original 702c, guest PC 0x0c0ad3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3b8u; return 0; }
r[0]+=0x0000002cu;
goto P_0c0ad3ba;
P_0c0ad3ba: /* original 0474, guest PC 0x0c0ad3ba */
if(!s->budget--) { s->failed_pc=0x0c0ad3bau; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3bc;
P_0c0ad3bc: /* original 7001, guest PC 0x0c0ad3bc */
if(!s->budget--) { s->failed_pc=0x0c0ad3bcu; return 0; }
r[0]+=0x00000001u;
goto P_0c0ad3be;
P_0c0ad3be: /* original 0474, guest PC 0x0c0ad3be */
if(!s->budget--) { s->failed_pc=0x0c0ad3beu; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3c0;
P_0c0ad3c0: /* original 701b, guest PC 0x0c0ad3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c0u; return 0; }
r[0]+=0x0000001bu;
goto P_0c0ad3c2;
P_0c0ad3c2: /* original f48d, guest PC 0x0c0ad3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c2u; return 0; }
fr[4]=0;
goto P_0c0ad3c4;
P_0c0ad3c4: /* original f447, guest PC 0x0c0ad3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad3c6;
P_0c0ad3c6: /* original 908d, guest PC 0x0c0ad3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e4u,2);
goto P_0c0ad3c8;
P_0c0ad3c8: /* original f447, guest PC 0x0c0ad3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3c8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad3ca;
P_0c0ad3ca: /* original 908c, guest PC 0x0c0ad3ca */
if(!s->budget--) { s->failed_pc=0x0c0ad3cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e6u,2);
goto P_0c0ad3cc;
P_0c0ad3cc: /* original 0474, guest PC 0x0c0ad3cc */
if(!s->budget--) { s->failed_pc=0x0c0ad3ccu; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3ce;
P_0c0ad3ce: /* original 908b, guest PC 0x0c0ad3ce */
if(!s->budget--) { s->failed_pc=0x0c0ad3ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4e8u,2);
goto P_0c0ad3d0;
P_0c0ad3d0: /* original 2668, guest PC 0x0c0ad3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad3d2;
P_0c0ad3d2: /* original 8f02, guest PC 0x0c0ad3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d2u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[7],1);
if(!cond) { goto P_0c0ad3da; }
goto P_0c0ad3d6;
P_0c0ad3d4: /* original 0474, guest PC 0x0c0ad3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d4u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ad3d6;
P_0c0ad3d6: /* original a0ca, guest PC 0x0c0ad3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d6u; return 0; }
goto P_0c0ad56e;
P_0c0ad3d8: /* original 0009, guest PC 0x0c0ad3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3d8u; return 0; }
goto P_0c0ad3da;
P_0c0ad3da: /* original 6263, guest PC 0x0c0ad3da */
if(!s->budget--) { s->failed_pc=0x0c0ad3dau; return 0; }
r[2]=r[6];
goto P_0c0ad3dc;
P_0c0ad3dc: /* original 72ff, guest PC 0x0c0ad3dc */
if(!s->budget--) { s->failed_pc=0x0c0ad3dcu; return 0; }
r[2]+=0xffffffffu;
goto P_0c0ad3de;
P_0c0ad3de: /* original 6323, guest PC 0x0c0ad3de */
if(!s->budget--) { s->failed_pc=0x0c0ad3deu; return 0; }
r[3]=r[2];
goto P_0c0ad3e0;
P_0c0ad3e0: /* original 4200, guest PC 0x0c0ad3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0ad3e2;
P_0c0ad3e2: /* original 323c, guest PC 0x0c0ad3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e2u; return 0; }
r[2]+=r[3];
goto P_0c0ad3e4;
P_0c0ad3e4: /* original 4208, guest PC 0x0c0ad3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e4u; return 0; }
r[2]<<=2;
goto P_0c0ad3e6;
P_0c0ad3e6: /* original 32ec, guest PC 0x0c0ad3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e6u; return 0; }
r[2]+=r[14];
goto P_0c0ad3e8;
P_0c0ad3e8: /* original 6122, guest PC 0x0c0ad3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3e8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0ad3ea;
P_0c0ad3ea: /* original 2118, guest PC 0x0c0ad3ea */
if(!s->budget--) { s->failed_pc=0x0c0ad3eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0ad3ec;
P_0c0ad3ec: /* original 8b07, guest PC 0x0c0ad3ec */
if(!s->budget--) { s->failed_pc=0x0c0ad3ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad3fe; }
goto P_0c0ad3ee;
P_0c0ad3ee: /* original e054, guest PC 0x0c0ad3ee */
if(!s->budget--) { s->failed_pc=0x0c0ad3eeu; return 0; }
r[0]=0x00000054u;
goto P_0c0ad3f0;
P_0c0ad3f0: /* original d245, guest PC 0x0c0ad3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f0u; return 0; }
r[2]=read(ram,0x0c0ad508u,4);
goto P_0c0ad3f2;
P_0c0ad3f2: /* original 064e, guest PC 0x0c0ad3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f2u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c0ad3f4;
P_0c0ad3f4: /* original e03c, guest PC 0x0c0ad3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f4u; return 0; }
r[0]=0x0000003cu;
goto P_0c0ad3f6;
P_0c0ad3f6: /* original 5362, guest PC 0x0c0ad3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f6u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ad3f8;
P_0c0ad3f8: /* original 6631, guest PC 0x0c0ad3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad3f8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[6]=tmp;
goto P_0c0ad3fa;
P_0c0ad3fa: /* original 142e, guest PC 0x0c0ad3fa */
if(!s->budget--) { s->failed_pc=0x0c0ad3fau; return 0; }
write(ram,r[4]+56,r[2],4);
goto P_0c0ad3fc;
P_0c0ad3fc: /* original 0465, guest PC 0x0c0ad3fc */
if(!s->budget--) { s->failed_pc=0x0c0ad3fcu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0ad3fe;
P_0c0ad3fe: /* original 9074, guest PC 0x0c0ad3fe */
if(!s->budget--) { s->failed_pc=0x0c0ad3feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4eau,2);
goto P_0c0ad400;
P_0c0ad400: /* original f447, guest PC 0x0c0ad400 */
if(!s->budget--) { s->failed_pc=0x0c0ad400u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad402;
P_0c0ad402: /* original 6063, guest PC 0x0c0ad402 */
if(!s->budget--) { s->failed_pc=0x0c0ad402u; return 0; }
r[0]=r[6];
goto P_0c0ad404;
P_0c0ad404: /* original 70ff, guest PC 0x0c0ad404 */
if(!s->budget--) { s->failed_pc=0x0c0ad404u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0ad406;
P_0c0ad406: /* original 2f02, guest PC 0x0c0ad406 */
if(!s->budget--) { s->failed_pc=0x0c0ad406u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0ad408;
P_0c0ad408: /* original 4008, guest PC 0x0c0ad408 */
if(!s->budget--) { s->failed_pc=0x0c0ad408u; return 0; }
r[0]<<=2;
goto P_0c0ad40a;
P_0c0ad40a: /* original 63f2, guest PC 0x0c0ad40a */
if(!s->budget--) { s->failed_pc=0x0c0ad40au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ad40c;
P_0c0ad40c: /* original 07ce, guest PC 0x0c0ad40c */
if(!s->budget--) { s->failed_pc=0x0c0ad40cu; return 0; }
r[7]=read(ram,r[12]+r[0],4);
goto P_0c0ad40e;
P_0c0ad40e: /* original 6233, guest PC 0x0c0ad40e */
if(!s->budget--) { s->failed_pc=0x0c0ad40eu; return 0; }
r[2]=r[3];
goto P_0c0ad410;
P_0c0ad410: /* original 4300, guest PC 0x0c0ad410 */
if(!s->budget--) { s->failed_pc=0x0c0ad410u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0ad412;
P_0c0ad412: /* original 332c, guest PC 0x0c0ad412 */
if(!s->budget--) { s->failed_pc=0x0c0ad412u; return 0; }
r[3]+=r[2];
goto P_0c0ad414;
P_0c0ad414: /* original 4308, guest PC 0x0c0ad414 */
if(!s->budget--) { s->failed_pc=0x0c0ad414u; return 0; }
r[3]<<=2;
goto P_0c0ad416;
P_0c0ad416: /* original 33ec, guest PC 0x0c0ad416 */
if(!s->budget--) { s->failed_pc=0x0c0ad416u; return 0; }
r[3]+=r[14];
goto P_0c0ad418;
P_0c0ad418: /* original 6232, guest PC 0x0c0ad418 */
if(!s->budget--) { s->failed_pc=0x0c0ad418u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0ad41a;
P_0c0ad41a: /* original 37cc, guest PC 0x0c0ad41a */
if(!s->budget--) { s->failed_pc=0x0c0ad41au; return 0; }
r[7]+=r[12];
goto P_0c0ad41c;
P_0c0ad41c: /* original dc3b, guest PC 0x0c0ad41c */
if(!s->budget--) { s->failed_pc=0x0c0ad41cu; return 0; }
r[12]=read(ram,0x0c0ad50cu,4);
goto P_0c0ad41e;
P_0c0ad41e: /* original 32ec, guest PC 0x0c0ad41e */
if(!s->budget--) { s->failed_pc=0x0c0ad41eu; return 0; }
r[2]+=r[14];
goto P_0c0ad420;
P_0c0ad420: /* original 1f21, guest PC 0x0c0ad420 */
if(!s->budget--) { s->failed_pc=0x0c0ad420u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0ad422;
P_0c0ad422: /* original 8421, guest PC 0x0c0ad422 */
if(!s->budget--) { s->failed_pc=0x0c0ad422u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+1,1);
goto P_0c0ad424;
P_0c0ad424: /* original 6320, guest PC 0x0c0ad424 */
if(!s->budget--) { s->failed_pc=0x0c0ad424u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0ad426;
P_0c0ad426: /* original 600c, guest PC 0x0c0ad426 */
if(!s->budget--) { s->failed_pc=0x0c0ad426u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad428;
P_0c0ad428: /* original 9160, guest PC 0x0c0ad428 */
if(!s->budget--) { s->failed_pc=0x0c0ad428u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4ecu,2);
goto P_0c0ad42a;
P_0c0ad42a: /* original 4018, guest PC 0x0c0ad42a */
if(!s->budget--) { s->failed_pc=0x0c0ad42au; return 0; }
r[0]<<=8;
goto P_0c0ad42c;
P_0c0ad42c: /* original 20c9, guest PC 0x0c0ad42c */
if(!s->budget--) { s->failed_pc=0x0c0ad42cu; return 0; }
r[0]&=r[12];
goto P_0c0ad42e;
P_0c0ad42e: /* original 6e03, guest PC 0x0c0ad42e */
if(!s->budget--) { s->failed_pc=0x0c0ad42eu; return 0; }
r[14]=r[0];
goto P_0c0ad430;
P_0c0ad430: /* original 905d, guest PC 0x0c0ad430 */
if(!s->budget--) { s->failed_pc=0x0c0ad430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4eeu,2);
goto P_0c0ad432;
P_0c0ad432: /* original 633c, guest PC 0x0c0ad432 */
if(!s->budget--) { s->failed_pc=0x0c0ad432u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad434;
P_0c0ad434: /* original 2e3b, guest PC 0x0c0ad434 */
if(!s->budget--) { s->failed_pc=0x0c0ad434u; return 0; }
r[14]|=r[3];
goto P_0c0ad436;
P_0c0ad436: /* original 034d, guest PC 0x0c0ad436 */
if(!s->budget--) { s->failed_pc=0x0c0ad436u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad438;
P_0c0ad438: /* original 905a, guest PC 0x0c0ad438 */
if(!s->budget--) { s->failed_pc=0x0c0ad438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f0u,2);
goto P_0c0ad43a;
P_0c0ad43a: /* original 2e19, guest PC 0x0c0ad43a */
if(!s->budget--) { s->failed_pc=0x0c0ad43au; return 0; }
r[14]&=r[1];
goto P_0c0ad43c;
P_0c0ad43c: /* original 0435, guest PC 0x0c0ad43c */
if(!s->budget--) { s->failed_pc=0x0c0ad43cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad43e;
P_0c0ad43e: /* original 9058, guest PC 0x0c0ad43e */
if(!s->budget--) { s->failed_pc=0x0c0ad43eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f2u,2);
goto P_0c0ad440;
P_0c0ad440: /* original 04e5, guest PC 0x0c0ad440 */
if(!s->budget--) { s->failed_pc=0x0c0ad440u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0ad442;
P_0c0ad442: /* original 700e, guest PC 0x0c0ad442 */
if(!s->budget--) { s->failed_pc=0x0c0ad442u; return 0; }
r[0]+=0x0000000eu;
goto P_0c0ad444;
P_0c0ad444: /* original 04e5, guest PC 0x0c0ad444 */
if(!s->budget--) { s->failed_pc=0x0c0ad444u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0ad446;
P_0c0ad446: /* original 7002, guest PC 0x0c0ad446 */
if(!s->budget--) { s->failed_pc=0x0c0ad446u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ad448;
P_0c0ad448: /* original 04e5, guest PC 0x0c0ad448 */
if(!s->budget--) { s->failed_pc=0x0c0ad448u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0ad44a;
P_0c0ad44a: /* original 70f4, guest PC 0x0c0ad44a */
if(!s->budget--) { s->failed_pc=0x0c0ad44au; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0ad44c;
P_0c0ad44c: /* original 034e, guest PC 0x0c0ad44c */
if(!s->budget--) { s->failed_pc=0x0c0ad44cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0ad44e;
P_0c0ad44e: /* original 9051, guest PC 0x0c0ad44e */
if(!s->budget--) { s->failed_pc=0x0c0ad44eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f4u,2);
goto P_0c0ad450;
P_0c0ad450: /* original 0436, guest PC 0x0c0ad450 */
if(!s->budget--) { s->failed_pc=0x0c0ad450u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0ad452;
P_0c0ad452: /* original 8473, guest PC 0x0c0ad452 */
if(!s->budget--) { s->failed_pc=0x0c0ad452u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+3,1);
goto P_0c0ad454;
P_0c0ad454: /* original de2e, guest PC 0x0c0ad454 */
if(!s->budget--) { s->failed_pc=0x0c0ad454u; return 0; }
r[14]=read(ram,0x0c0ad510u,4);
goto P_0c0ad456;
P_0c0ad456: /* original 600c, guest PC 0x0c0ad456 */
if(!s->budget--) { s->failed_pc=0x0c0ad456u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad458;
P_0c0ad458: /* original d32e, guest PC 0x0c0ad458 */
if(!s->budget--) { s->failed_pc=0x0c0ad458u; return 0; }
r[3]=read(ram,0x0c0ad514u,4);
goto P_0c0ad45a;
P_0c0ad45a: /* original 4028, guest PC 0x0c0ad45a */
if(!s->budget--) { s->failed_pc=0x0c0ad45au; return 0; }
r[0]<<=16;
goto P_0c0ad45c;
P_0c0ad45c: /* original 6270, guest PC 0x0c0ad45c */
if(!s->budget--) { s->failed_pc=0x0c0ad45cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[2]=tmp;
goto P_0c0ad45e;
P_0c0ad45e: /* original 4018, guest PC 0x0c0ad45e */
if(!s->budget--) { s->failed_pc=0x0c0ad45eu; return 0; }
r[0]<<=8;
goto P_0c0ad460;
P_0c0ad460: /* original 2e09, guest PC 0x0c0ad460 */
if(!s->budget--) { s->failed_pc=0x0c0ad460u; return 0; }
r[14]&=r[0];
goto P_0c0ad462;
P_0c0ad462: /* original 8472, guest PC 0x0c0ad462 */
if(!s->budget--) { s->failed_pc=0x0c0ad462u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+2,1);
goto P_0c0ad464;
P_0c0ad464: /* original 622c, guest PC 0x0c0ad464 */
if(!s->budget--) { s->failed_pc=0x0c0ad464u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ad466;
P_0c0ad466: /* original 600c, guest PC 0x0c0ad466 */
if(!s->budget--) { s->failed_pc=0x0c0ad466u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad468;
P_0c0ad468: /* original 4028, guest PC 0x0c0ad468 */
if(!s->budget--) { s->failed_pc=0x0c0ad468u; return 0; }
r[0]<<=16;
goto P_0c0ad46a;
P_0c0ad46a: /* original 2039, guest PC 0x0c0ad46a */
if(!s->budget--) { s->failed_pc=0x0c0ad46au; return 0; }
r[0]&=r[3];
goto P_0c0ad46c;
P_0c0ad46c: /* original 2e0b, guest PC 0x0c0ad46c */
if(!s->budget--) { s->failed_pc=0x0c0ad46cu; return 0; }
r[14]|=r[0];
goto P_0c0ad46e;
P_0c0ad46e: /* original 8471, guest PC 0x0c0ad46e */
if(!s->budget--) { s->failed_pc=0x0c0ad46eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c0ad470;
P_0c0ad470: /* original 600c, guest PC 0x0c0ad470 */
if(!s->budget--) { s->failed_pc=0x0c0ad470u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad472;
P_0c0ad472: /* original 4018, guest PC 0x0c0ad472 */
if(!s->budget--) { s->failed_pc=0x0c0ad472u; return 0; }
r[0]<<=8;
goto P_0c0ad474;
P_0c0ad474: /* original 20c9, guest PC 0x0c0ad474 */
if(!s->budget--) { s->failed_pc=0x0c0ad474u; return 0; }
r[0]&=r[12];
goto P_0c0ad476;
P_0c0ad476: /* original 2e0b, guest PC 0x0c0ad476 */
if(!s->budget--) { s->failed_pc=0x0c0ad476u; return 0; }
r[14]|=r[0];
goto P_0c0ad478;
P_0c0ad478: /* original 903d, guest PC 0x0c0ad478 */
if(!s->budget--) { s->failed_pc=0x0c0ad478u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f6u,2);
goto P_0c0ad47a;
P_0c0ad47a: /* original 2e2b, guest PC 0x0c0ad47a */
if(!s->budget--) { s->failed_pc=0x0c0ad47au; return 0; }
r[14]|=r[2];
goto P_0c0ad47c;
P_0c0ad47c: /* original 04e6, guest PC 0x0c0ad47c */
if(!s->budget--) { s->failed_pc=0x0c0ad47cu; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0ad47e;
P_0c0ad47e: /* original 923b, guest PC 0x0c0ad47e */
if(!s->budget--) { s->failed_pc=0x0c0ad47eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4f8u,2);
goto P_0c0ad480;
P_0c0ad480: /* original d325, guest PC 0x0c0ad480 */
if(!s->budget--) { s->failed_pc=0x0c0ad480u; return 0; }
r[3]=read(ram,0x0c0ad518u,4);
goto P_0c0ad482;
P_0c0ad482: /* original 2e29, guest PC 0x0c0ad482 */
if(!s->budget--) { s->failed_pc=0x0c0ad482u; return 0; }
r[14]&=r[2];
goto P_0c0ad484;
P_0c0ad484: /* original 23e8, guest PC 0x0c0ad484 */
if(!s->budget--) { s->failed_pc=0x0c0ad484u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0ad486;
P_0c0ad486: /* original 8902, guest PC 0x0c0ad486 */
if(!s->budget--) { s->failed_pc=0x0c0ad486u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad48e; }
goto P_0c0ad488;
P_0c0ad488: /* original 9038, guest PC 0x0c0ad488 */
if(!s->budget--) { s->failed_pc=0x0c0ad488u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4fcu,2);
goto P_0c0ad48a;
P_0c0ad48a: /* original 9236, guest PC 0x0c0ad48a */
if(!s->budget--) { s->failed_pc=0x0c0ad48au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4fau,2);
goto P_0c0ad48c;
P_0c0ad48c: /* original 0425, guest PC 0x0c0ad48c */
if(!s->budget--) { s->failed_pc=0x0c0ad48cu; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0ad48e;
P_0c0ad48e: /* original 9336, guest PC 0x0c0ad48e */
if(!s->budget--) { s->failed_pc=0x0c0ad48eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad4feu,2);
goto P_0c0ad490;
P_0c0ad490: /* original 23e8, guest PC 0x0c0ad490 */
if(!s->budget--) { s->failed_pc=0x0c0ad490u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0ad492;
P_0c0ad492: /* original 8d02, guest PC 0x0c0ad492 */
if(!s->budget--) { s->failed_pc=0x0c0ad492u; return 0; }
cond=r[17]&1u;
r[3]=r[6]&65535u;
if(cond) { goto P_0c0ad49a; }
goto P_0c0ad496;
P_0c0ad494: /* original 636d, guest PC 0x0c0ad494 */
if(!s->budget--) { s->failed_pc=0x0c0ad494u; return 0; }
r[3]=r[6]&65535u;
goto P_0c0ad496;
P_0c0ad496: /* original d121, guest PC 0x0c0ad496 */
if(!s->budget--) { s->failed_pc=0x0c0ad496u; return 0; }
r[1]=read(ram,0x0c0ad51cu,4);
goto P_0c0ad498;
P_0c0ad498: /* original 2e19, guest PC 0x0c0ad498 */
if(!s->budget--) { s->failed_pc=0x0c0ad498u; return 0; }
r[14]&=r[1];
goto P_0c0ad49a;
P_0c0ad49a: /* original e048, guest PC 0x0c0ad49a */
if(!s->budget--) { s->failed_pc=0x0c0ad49au; return 0; }
r[0]=0x00000048u;
goto P_0c0ad49c;
P_0c0ad49c: /* original 2f32, guest PC 0x0c0ad49c */
if(!s->budget--) { s->failed_pc=0x0c0ad49cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ad49e;
P_0c0ad49e: /* original 922f, guest PC 0x0c0ad49e */
if(!s->budget--) { s->failed_pc=0x0c0ad49eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad500u,2);
goto P_0c0ad4a0;
P_0c0ad4a0: /* original 04e6, guest PC 0x0c0ad4a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a0u; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0ad4a2;
P_0c0ad4a2: /* original 847b, guest PC 0x0c0ad4a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+11,1);
goto P_0c0ad4a4;
P_0c0ad4a4: /* original 3320, guest PC 0x0c0ad4a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0ad4a6;
P_0c0ad4a6: /* original de1a, guest PC 0x0c0ad4a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a6u; return 0; }
r[14]=read(ram,0x0c0ad510u,4);
goto P_0c0ad4a8;
P_0c0ad4a8: /* original 600c, guest PC 0x0c0ad4a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad4a8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad4aa;
P_0c0ad4aa: /* original d31a, guest PC 0x0c0ad4aa */
if(!s->budget--) { s->failed_pc=0x0c0ad4aau; return 0; }
r[3]=read(ram,0x0c0ad514u,4);
goto P_0c0ad4ac;
P_0c0ad4ac: /* original 4028, guest PC 0x0c0ad4ac */
if(!s->budget--) { s->failed_pc=0x0c0ad4acu; return 0; }
r[0]<<=16;
goto P_0c0ad4ae;
P_0c0ad4ae: /* original d21c, guest PC 0x0c0ad4ae */
if(!s->budget--) { s->failed_pc=0x0c0ad4aeu; return 0; }
r[2]=read(ram,0x0c0ad520u,4);
goto P_0c0ad4b0;
P_0c0ad4b0: /* original 4018, guest PC 0x0c0ad4b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b0u; return 0; }
r[0]<<=8;
goto P_0c0ad4b2;
P_0c0ad4b2: /* original 51d1, guest PC 0x0c0ad4b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b2u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0ad4b4;
P_0c0ad4b4: /* original 2e09, guest PC 0x0c0ad4b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b4u; return 0; }
r[14]&=r[0];
goto P_0c0ad4b6;
P_0c0ad4b6: /* original 847a, guest PC 0x0c0ad4b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+10,1);
goto P_0c0ad4b8;
P_0c0ad4b8: /* original 2128, guest PC 0x0c0ad4b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad4b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ad4ba;
P_0c0ad4ba: /* original 600c, guest PC 0x0c0ad4ba */
if(!s->budget--) { s->failed_pc=0x0c0ad4bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad4bc;
P_0c0ad4bc: /* original 4028, guest PC 0x0c0ad4bc */
if(!s->budget--) { s->failed_pc=0x0c0ad4bcu; return 0; }
r[0]<<=16;
goto P_0c0ad4be;
P_0c0ad4be: /* original 2039, guest PC 0x0c0ad4be */
if(!s->budget--) { s->failed_pc=0x0c0ad4beu; return 0; }
r[0]&=r[3];
goto P_0c0ad4c0;
P_0c0ad4c0: /* original 2e0b, guest PC 0x0c0ad4c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c0u; return 0; }
r[14]|=r[0];
goto P_0c0ad4c2;
P_0c0ad4c2: /* original 8479, guest PC 0x0c0ad4c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+9,1);
goto P_0c0ad4c4;
P_0c0ad4c4: /* original 600c, guest PC 0x0c0ad4c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad4c6;
P_0c0ad4c6: /* original 4018, guest PC 0x0c0ad4c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c6u; return 0; }
r[0]<<=8;
goto P_0c0ad4c8;
P_0c0ad4c8: /* original 20c9, guest PC 0x0c0ad4c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad4c8u; return 0; }
r[0]&=r[12];
goto P_0c0ad4ca;
P_0c0ad4ca: /* original 2e0b, guest PC 0x0c0ad4ca */
if(!s->budget--) { s->failed_pc=0x0c0ad4cau; return 0; }
r[14]|=r[0];
goto P_0c0ad4cc;
P_0c0ad4cc: /* original 8478, guest PC 0x0c0ad4cc */
if(!s->budget--) { s->failed_pc=0x0c0ad4ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+8,1);
goto P_0c0ad4ce;
P_0c0ad4ce: /* original 600c, guest PC 0x0c0ad4ce */
if(!s->budget--) { s->failed_pc=0x0c0ad4ceu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad4d0;
P_0c0ad4d0: /* original 2e0b, guest PC 0x0c0ad4d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d0u; return 0; }
r[14]|=r[0];
goto P_0c0ad4d2;
P_0c0ad4d2: /* original 892c, guest PC 0x0c0ad4d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad52e; }
goto P_0c0ad4d4;
P_0c0ad4d4: /* original 6063, guest PC 0x0c0ad4d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d4u; return 0; }
r[0]=r[6];
goto P_0c0ad4d6;
P_0c0ad4d6: /* original 8840, guest PC 0x0c0ad4d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0ad4d8;
P_0c0ad4d8: /* original 8927, guest PC 0x0c0ad4d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad4d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad52a; }
goto P_0c0ad4da;
P_0c0ad4da: /* original a023, guest PC 0x0c0ad4da */
if(!s->budget--) { s->failed_pc=0x0c0ad4dau; return 0; }
goto P_0c0ad524;
P_0c0ad4dc: /* original 0009, guest PC 0x0c0ad4dc */
if(!s->budget--) { s->failed_pc=0x0c0ad4dcu; return 0; }
return vf3_matrix_family(0x0c0ad4deu,s,ram);
P_0c0ad524: /* original 9033, guest PC 0x0c0ad524 */
if(!s->budget--) { s->failed_pc=0x0c0ad524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad58eu,2);
goto P_0c0ad526;
P_0c0ad526: /* original 3600, guest PC 0x0c0ad526 */
if(!s->budget--) { s->failed_pc=0x0c0ad526u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[0])!=0);
goto P_0c0ad528;
P_0c0ad528: /* original 8b01, guest PC 0x0c0ad528 */
if(!s->budget--) { s->failed_pc=0x0c0ad528u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad52e; }
goto P_0c0ad52a;
P_0c0ad52a: /* original d21b, guest PC 0x0c0ad52a */
if(!s->budget--) { s->failed_pc=0x0c0ad52au; return 0; }
r[2]=read(ram,0x0c0ad598u,4);
goto P_0c0ad52c;
P_0c0ad52c: /* original 2e2b, guest PC 0x0c0ad52c */
if(!s->budget--) { s->failed_pc=0x0c0ad52cu; return 0; }
r[14]|=r[2];
goto P_0c0ad52e;
P_0c0ad52e: /* original 902f, guest PC 0x0c0ad52e */
if(!s->budget--) { s->failed_pc=0x0c0ad52eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad590u,2);
goto P_0c0ad530;
P_0c0ad530: /* original 04e6, guest PC 0x0c0ad530 */
if(!s->budget--) { s->failed_pc=0x0c0ad530u; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0ad532;
P_0c0ad532: /* original e04c, guest PC 0x0c0ad532 */
if(!s->budget--) { s->failed_pc=0x0c0ad532u; return 0; }
r[0]=0x0000004cu;
goto P_0c0ad534;
P_0c0ad534: /* original 04e6, guest PC 0x0c0ad534 */
if(!s->budget--) { s->failed_pc=0x0c0ad534u; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c0ad536;
P_0c0ad536: /* original 8475, guest PC 0x0c0ad536 */
if(!s->budget--) { s->failed_pc=0x0c0ad536u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+5,1);
goto P_0c0ad538;
P_0c0ad538: /* original 600c, guest PC 0x0c0ad538 */
if(!s->budget--) { s->failed_pc=0x0c0ad538u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad53a;
P_0c0ad53a: /* original 4018, guest PC 0x0c0ad53a */
if(!s->budget--) { s->failed_pc=0x0c0ad53au; return 0; }
r[0]<<=8;
goto P_0c0ad53c;
P_0c0ad53c: /* original 20c9, guest PC 0x0c0ad53c */
if(!s->budget--) { s->failed_pc=0x0c0ad53cu; return 0; }
r[0]&=r[12];
goto P_0c0ad53e;
P_0c0ad53e: /* original 6303, guest PC 0x0c0ad53e */
if(!s->budget--) { s->failed_pc=0x0c0ad53eu; return 0; }
r[3]=r[0];
goto P_0c0ad540;
P_0c0ad540: /* original 8474, guest PC 0x0c0ad540 */
if(!s->budget--) { s->failed_pc=0x0c0ad540u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+4,1);
goto P_0c0ad542;
P_0c0ad542: /* original 600c, guest PC 0x0c0ad542 */
if(!s->budget--) { s->failed_pc=0x0c0ad542u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad544;
P_0c0ad544: /* original 230b, guest PC 0x0c0ad544 */
if(!s->budget--) { s->failed_pc=0x0c0ad544u; return 0; }
r[3]|=r[0];
goto P_0c0ad546;
P_0c0ad546: /* original 9024, guest PC 0x0c0ad546 */
if(!s->budget--) { s->failed_pc=0x0c0ad546u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad592u,2);
goto P_0c0ad548;
P_0c0ad548: /* original 0435, guest PC 0x0c0ad548 */
if(!s->budget--) { s->failed_pc=0x0c0ad548u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad54a;
P_0c0ad54a: /* original 8477, guest PC 0x0c0ad54a */
if(!s->budget--) { s->failed_pc=0x0c0ad54au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+7,1);
goto P_0c0ad54c;
P_0c0ad54c: /* original 600c, guest PC 0x0c0ad54c */
if(!s->budget--) { s->failed_pc=0x0c0ad54cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad54e;
P_0c0ad54e: /* original 4018, guest PC 0x0c0ad54e */
if(!s->budget--) { s->failed_pc=0x0c0ad54eu; return 0; }
r[0]<<=8;
goto P_0c0ad550;
P_0c0ad550: /* original 20c9, guest PC 0x0c0ad550 */
if(!s->budget--) { s->failed_pc=0x0c0ad550u; return 0; }
r[0]&=r[12];
goto P_0c0ad552;
P_0c0ad552: /* original 6303, guest PC 0x0c0ad552 */
if(!s->budget--) { s->failed_pc=0x0c0ad552u; return 0; }
r[3]=r[0];
goto P_0c0ad554;
P_0c0ad554: /* original 8476, guest PC 0x0c0ad554 */
if(!s->budget--) { s->failed_pc=0x0c0ad554u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+6,1);
goto P_0c0ad556;
P_0c0ad556: /* original 770c, guest PC 0x0c0ad556 */
if(!s->budget--) { s->failed_pc=0x0c0ad556u; return 0; }
r[7]+=0x0000000cu;
goto P_0c0ad558;
P_0c0ad558: /* original 600c, guest PC 0x0c0ad558 */
if(!s->budget--) { s->failed_pc=0x0c0ad558u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad55a;
P_0c0ad55a: /* original 6673, guest PC 0x0c0ad55a */
if(!s->budget--) { s->failed_pc=0x0c0ad55au; return 0; }
r[6]=r[7];
goto P_0c0ad55c;
P_0c0ad55c: /* original 230b, guest PC 0x0c0ad55c */
if(!s->budget--) { s->failed_pc=0x0c0ad55cu; return 0; }
r[3]|=r[0];
goto P_0c0ad55e;
P_0c0ad55e: /* original 9019, guest PC 0x0c0ad55e */
if(!s->budget--) { s->failed_pc=0x0c0ad55eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad594u,2);
goto P_0c0ad560;
P_0c0ad560: /* original 0435, guest PC 0x0c0ad560 */
if(!s->budget--) { s->failed_pc=0x0c0ad560u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad562;
P_0c0ad562: /* original 2f72, guest PC 0x0c0ad562 */
if(!s->budget--) { s->failed_pc=0x0c0ad562u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0ad564;
P_0c0ad564: /* original 7f08, guest PC 0x0c0ad564 */
if(!s->budget--) { s->failed_pc=0x0c0ad564u; return 0; }
r[15]+=0x00000008u;
goto P_0c0ad566;
P_0c0ad566: /* original 6cf6, guest PC 0x0c0ad566 */
if(!s->budget--) { s->failed_pc=0x0c0ad566u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad568;
P_0c0ad568: /* original 6df6, guest PC 0x0c0ad568 */
if(!s->budget--) { s->failed_pc=0x0c0ad568u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad56a;
P_0c0ad56a: /* original a005, guest PC 0x0c0ad56a */
if(!s->budget--) { s->failed_pc=0x0c0ad56au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad578;
P_0c0ad56c: /* original 6ef6, guest PC 0x0c0ad56c */
if(!s->budget--) { s->failed_pc=0x0c0ad56cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad56e;
P_0c0ad56e: /* original 7f08, guest PC 0x0c0ad56e */
if(!s->budget--) { s->failed_pc=0x0c0ad56eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0ad570;
P_0c0ad570: /* original 6cf6, guest PC 0x0c0ad570 */
if(!s->budget--) { s->failed_pc=0x0c0ad570u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad572;
P_0c0ad572: /* original 6df6, guest PC 0x0c0ad572 */
if(!s->budget--) { s->failed_pc=0x0c0ad572u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad574;
P_0c0ad574: /* original 000b, guest PC 0x0c0ad574 */
if(!s->budget--) { s->failed_pc=0x0c0ad574u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ad576: /* original 6ef6, guest PC 0x0c0ad576 */
if(!s->budget--) { s->failed_pc=0x0c0ad576u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ad578;
P_0c0ad578: /* original 6360, guest PC 0x0c0ad578 */
if(!s->budget--) { s->failed_pc=0x0c0ad578u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0ad57a;
P_0c0ad57a: /* original 7ffc, guest PC 0x0c0ad57a */
if(!s->budget--) { s->failed_pc=0x0c0ad57au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad57c;
P_0c0ad57c: /* original d007, guest PC 0x0c0ad57c */
if(!s->budget--) { s->failed_pc=0x0c0ad57cu; return 0; }
r[0]=read(ram,0x0c0ad59cu,4);
goto P_0c0ad57e;
P_0c0ad57e: /* original 633c, guest PC 0x0c0ad57e */
if(!s->budget--) { s->failed_pc=0x0c0ad57eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad580;
P_0c0ad580: /* original 4308, guest PC 0x0c0ad580 */
if(!s->budget--) { s->failed_pc=0x0c0ad580u; return 0; }
r[3]<<=2;
goto P_0c0ad582;
P_0c0ad582: /* original 023e, guest PC 0x0c0ad582 */
if(!s->budget--) { s->failed_pc=0x0c0ad582u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0ad584;
P_0c0ad584: /* original 2f22, guest PC 0x0c0ad584 */
if(!s->budget--) { s->failed_pc=0x0c0ad584u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad586;
P_0c0ad586: /* original 422b, guest PC 0x0c0ad586 */
if(!s->budget--) { s->failed_pc=0x0c0ad586u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ad588: /* original 7f04, guest PC 0x0c0ad588 */
if(!s->budget--) { s->failed_pc=0x0c0ad588u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0ad58au,s,ram);
P_0c0ca338: /* original 9075, guest PC 0x0c0ca338 */
if(!s->budget--) { s->failed_pc=0x0c0ca338u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca426u,2);
goto P_0c0ca33a;
P_0c0ca33a: /* original f358, guest PC 0x0c0ca33a */
if(!s->budget--) { s->failed_pc=0x0c0ca33au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c0ca33c;
P_0c0ca33c: /* original f437, guest PC 0x0c0ca33c */
if(!s->budget--) { s->failed_pc=0x0c0ca33cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0ca33e;
P_0c0ca33e: /* original e004, guest PC 0x0c0ca33e */
if(!s->budget--) { s->failed_pc=0x0c0ca33eu; return 0; }
r[0]=0x00000004u;
goto P_0c0ca340;
P_0c0ca340: /* original f356, guest PC 0x0c0ca340 */
if(!s->budget--) { s->failed_pc=0x0c0ca340u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0ca342;
P_0c0ca342: /* original 9071, guest PC 0x0c0ca342 */
if(!s->budget--) { s->failed_pc=0x0c0ca342u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca428u,2);
goto P_0c0ca344;
P_0c0ca344: /* original f34d, guest PC 0x0c0ca344 */
if(!s->budget--) { s->failed_pc=0x0c0ca344u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0ca346;
P_0c0ca346: /* original f437, guest PC 0x0c0ca346 */
if(!s->budget--) { s->failed_pc=0x0c0ca346u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0ca348;
P_0c0ca348: /* original 000b, guest PC 0x0c0ca348 */
if(!s->budget--) { s->failed_pc=0x0c0ca348u; return 0; }
target=r[16];
r[0]=read(ram,r[5]+8,4);
s->pc=target; return ram->oob==0;
P_0c0ca34a: /* original 5052, guest PC 0x0c0ca34a */
if(!s->budget--) { s->failed_pc=0x0c0ca34au; return 0; }
r[0]=read(ram,r[5]+8,4);
goto P_0c0ca34c;
P_0c0ca34c: /* original 906d, guest PC 0x0c0ca34c */
if(!s->budget--) { s->failed_pc=0x0c0ca34cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca42au,2);
goto P_0c0ca34e;
P_0c0ca34e: /* original 4f22, guest PC 0x0c0ca34e */
if(!s->budget--) { s->failed_pc=0x0c0ca34eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca350;
P_0c0ca350: /* original 004e, guest PC 0x0c0ca350 */
if(!s->budget--) { s->failed_pc=0x0c0ca350u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c0ca352;
P_0c0ca352: /* original c820, guest PC 0x0c0ca352 */
if(!s->budget--) { s->failed_pc=0x0c0ca352u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0ca354;
P_0c0ca354: /* original 7ff0, guest PC 0x0c0ca354 */
if(!s->budget--) { s->failed_pc=0x0c0ca354u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0ca356;
P_0c0ca356: /* original 8b03, guest PC 0x0c0ca356 */
if(!s->budget--) { s->failed_pc=0x0c0ca356u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca360; }
goto P_0c0ca358;
P_0c0ca358: /* original 6242, guest PC 0x0c0ca358 */
if(!s->budget--) { s->failed_pc=0x0c0ca358u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ca35a;
P_0c0ca35a: /* original 9367, guest PC 0x0c0ca35a */
if(!s->budget--) { s->failed_pc=0x0c0ca35au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca42cu,2);
goto P_0c0ca35c;
P_0c0ca35c: /* original 2238, guest PC 0x0c0ca35c */
if(!s->budget--) { s->failed_pc=0x0c0ca35cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ca35e;
P_0c0ca35e: /* original 8904, guest PC 0x0c0ca35e */
if(!s->budget--) { s->failed_pc=0x0c0ca35eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ca36a; }
goto P_0c0ca360;
P_0c0ca360: /* original 65f3, guest PC 0x0c0ca360 */
if(!s->budget--) { s->failed_pc=0x0c0ca360u; return 0; }
r[5]=r[15];
goto P_0c0ca362;
P_0c0ca362: /* original b012, guest PC 0x0c0ca362 */
if(!s->budget--) { s->failed_pc=0x0c0ca362u; return 0; }
target=0x0c0ca38au; r[16]=0x0c0ca366u;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca366u) { target=s->pc; goto dispatch; }
goto P_0c0ca366;
P_0c0ca364: /* original 7504, guest PC 0x0c0ca364 */
if(!s->budget--) { s->failed_pc=0x0c0ca364u; return 0; }
r[5]+=0x00000004u;
goto P_0c0ca366;
P_0c0ca366: /* original a00b, guest PC 0x0c0ca366 */
if(!s->budget--) { s->failed_pc=0x0c0ca366u; return 0; }
goto P_0c0ca380;
P_0c0ca368: /* original 0009, guest PC 0x0c0ca368 */
if(!s->budget--) { s->failed_pc=0x0c0ca368u; return 0; }
goto P_0c0ca36a;
P_0c0ca36a: /* original d332, guest PC 0x0c0ca36a */
if(!s->budget--) { s->failed_pc=0x0c0ca36au; return 0; }
r[3]=read(ram,0x0c0ca434u,4);
goto P_0c0ca36c;
P_0c0ca36c: /* original 65f3, guest PC 0x0c0ca36c */
if(!s->budget--) { s->failed_pc=0x0c0ca36cu; return 0; }
r[5]=r[15];
goto P_0c0ca36e;
P_0c0ca36e: /* original d132, guest PC 0x0c0ca36e */
if(!s->budget--) { s->failed_pc=0x0c0ca36eu; return 0; }
r[1]=read(ram,0x0c0ca438u,4);
goto P_0c0ca370;
P_0c0ca370: /* original 6030, guest PC 0x0c0ca370 */
if(!s->budget--) { s->failed_pc=0x0c0ca370u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0ca372;
P_0c0ca372: /* original 600c, guest PC 0x0c0ca372 */
if(!s->budget--) { s->failed_pc=0x0c0ca372u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ca374;
P_0c0ca374: /* original c90f, guest PC 0x0c0ca374 */
if(!s->budget--) { s->failed_pc=0x0c0ca374u; return 0; }
r[0]&=15u;
goto P_0c0ca376;
P_0c0ca376: /* original 4008, guest PC 0x0c0ca376 */
if(!s->budget--) { s->failed_pc=0x0c0ca376u; return 0; }
r[0]<<=2;
goto P_0c0ca378;
P_0c0ca378: /* original 021e, guest PC 0x0c0ca378 */
if(!s->budget--) { s->failed_pc=0x0c0ca378u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c0ca37a;
P_0c0ca37a: /* original 2f22, guest PC 0x0c0ca37a */
if(!s->budget--) { s->failed_pc=0x0c0ca37au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ca37c;
P_0c0ca37c: /* original 420b, guest PC 0x0c0ca37c */
if(!s->budget--) { s->failed_pc=0x0c0ca37cu; return 0; }
target=r[2];
r[16]=0x0c0ca380u;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca380u) { target=s->pc; goto dispatch; }
goto P_0c0ca380;
P_0c0ca37e: /* original 7504, guest PC 0x0c0ca37e */
if(!s->budget--) { s->failed_pc=0x0c0ca37eu; return 0; }
r[5]+=0x00000004u;
goto P_0c0ca380;
P_0c0ca380: /* original 50f3, guest PC 0x0c0ca380 */
if(!s->budget--) { s->failed_pc=0x0c0ca380u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0ca382;
P_0c0ca382: /* original 7f10, guest PC 0x0c0ca382 */
if(!s->budget--) { s->failed_pc=0x0c0ca382u; return 0; }
r[15]+=0x00000010u;
goto P_0c0ca384;
P_0c0ca384: /* original 4f26, guest PC 0x0c0ca384 */
if(!s->budget--) { s->failed_pc=0x0c0ca384u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca386;
P_0c0ca386: /* original 000b, guest PC 0x0c0ca386 */
if(!s->budget--) { s->failed_pc=0x0c0ca386u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca388: /* original 0009, guest PC 0x0c0ca388 */
if(!s->budget--) { s->failed_pc=0x0c0ca388u; return 0; }
goto P_0c0ca38a;
P_0c0ca38a: /* original 2fe6, guest PC 0x0c0ca38a */
if(!s->budget--) { s->failed_pc=0x0c0ca38au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca38c;
P_0c0ca38c: /* original 6e43, guest PC 0x0c0ca38c */
if(!s->budget--) { s->failed_pc=0x0c0ca38cu; return 0; }
r[14]=r[4];
goto P_0c0ca38e;
P_0c0ca38e: /* original 2fd6, guest PC 0x0c0ca38e */
if(!s->budget--) { s->failed_pc=0x0c0ca38eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca390;
P_0c0ca390: /* original 6d53, guest PC 0x0c0ca390 */
if(!s->budget--) { s->failed_pc=0x0c0ca390u; return 0; }
r[13]=r[5];
goto P_0c0ca392;
P_0c0ca392: /* original 2fc6, guest PC 0x0c0ca392 */
if(!s->budget--) { s->failed_pc=0x0c0ca392u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca394;
P_0c0ca394: /* original e600, guest PC 0x0c0ca394 */
if(!s->budget--) { s->failed_pc=0x0c0ca394u; return 0; }
r[6]=0x00000000u;
goto P_0c0ca396;
P_0c0ca396: /* original 2fb6, guest PC 0x0c0ca396 */
if(!s->budget--) { s->failed_pc=0x0c0ca396u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca398;
P_0c0ca398: /* original ec1c, guest PC 0x0c0ca398 */
if(!s->budget--) { s->failed_pc=0x0c0ca398u; return 0; }
r[12]=0x0000001cu;
goto P_0c0ca39a;
P_0c0ca39a: /* original fffb, guest PC 0x0c0ca39a */
if(!s->budget--) { s->failed_pc=0x0c0ca39au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ca39c;
P_0c0ca39c: /* original ffeb, guest PC 0x0c0ca39c */
if(!s->budget--) { s->failed_pc=0x0c0ca39cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0ca39e;
P_0c0ca39e: /* original 9046, guest PC 0x0c0ca39e */
if(!s->budget--) { s->failed_pc=0x0c0ca39eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca42eu,2);
goto P_0c0ca3a0;
P_0c0ca3a0: /* original 4f22, guest PC 0x0c0ca3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca3a2;
P_0c0ca3a2: /* original 0bee, guest PC 0x0c0ca3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a2u; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c0ca3a4;
P_0c0ca3a4: /* original 70bc, guest PC 0x0c0ca3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a4u; return 0; }
r[0]+=0xffffffbcu;
goto P_0c0ca3a6;
P_0c0ca3a6: /* original 04ee, guest PC 0x0c0ca3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ca3a8;
P_0c0ca3a8: /* original d524, guest PC 0x0c0ca3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a8u; return 0; }
r[5]=read(ram,0x0c0ca43cu,4);
goto P_0c0ca3aa;
P_0c0ca3aa: /* original 7fec, guest PC 0x0c0ca3aa */
if(!s->budget--) { s->failed_pc=0x0c0ca3aau; return 0; }
r[15]+=0xffffffecu;
goto P_0c0ca3ac;
P_0c0ca3ac: /* original 1f44, guest PC 0x0c0ca3ac */
if(!s->budget--) { s->failed_pc=0x0c0ca3acu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c0ca3ae;
P_0c0ca3ae: /* original 6753, guest PC 0x0c0ca3ae */
if(!s->budget--) { s->failed_pc=0x0c0ca3aeu; return 0; }
r[7]=r[5];
goto P_0c0ca3b0;
P_0c0ca3b0: /* original 6353, guest PC 0x0c0ca3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b0u; return 0; }
r[3]=r[5];
goto P_0c0ca3b2;
P_0c0ca3b2: /* original 23b8, guest PC 0x0c0ca3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0ca3b4;
P_0c0ca3b4: /* original 8b12, guest PC 0x0c0ca3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca3dc; }
goto P_0c0ca3b6;
P_0c0ca3b6: /* original 7601, guest PC 0x0c0ca3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b6u; return 0; }
r[6]+=0x00000001u;
goto P_0c0ca3b8;
P_0c0ca3b8: /* original 4521, guest PC 0x0c0ca3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0ca3ba;
P_0c0ca3ba: /* original 36c3, guest PC 0x0c0ca3ba */
if(!s->budget--) { s->failed_pc=0x0c0ca3bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[12])!=0);
goto P_0c0ca3bc;
P_0c0ca3bc: /* original 8ff8, guest PC 0x0c0ca3bc */
if(!s->budget--) { s->failed_pc=0x0c0ca3bcu; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c0ca3b0; }
goto P_0c0ca3c0;
P_0c0ca3be: /* original 740c, guest PC 0x0c0ca3be */
if(!s->budget--) { s->failed_pc=0x0c0ca3beu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0ca3c0;
P_0c0ca3c0: /* original 9036, guest PC 0x0c0ca3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca430u,2);
goto P_0c0ca3c2;
P_0c0ca3c2: /* original e61a, guest PC 0x0c0ca3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c2u; return 0; }
r[6]=0x0000001au;
goto P_0c0ca3c4;
P_0c0ca3c4: /* original e500, guest PC 0x0c0ca3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c4u; return 0; }
r[5]=0x00000000u;
goto P_0c0ca3c6;
P_0c0ca3c6: /* original 02ee, guest PC 0x0c0ca3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ca3c8;
P_0c0ca3c8: /* original 2f22, guest PC 0x0c0ca3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ca3ca;
P_0c0ca3ca: /* original 54f4, guest PC 0x0c0ca3ca */
if(!s->budget--) { s->failed_pc=0x0c0ca3cau; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c0ca3cc;
P_0c0ca3cc: /* original 63f2, guest PC 0x0c0ca3cc */
if(!s->budget--) { s->failed_pc=0x0c0ca3ccu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca3ce;
P_0c0ca3ce: /* original 2378, guest PC 0x0c0ca3ce */
if(!s->budget--) { s->failed_pc=0x0c0ca3ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0ca3d0;
P_0c0ca3d0: /* original 8b04, guest PC 0x0c0ca3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca3dc; }
goto P_0c0ca3d2;
P_0c0ca3d2: /* original 7501, guest PC 0x0c0ca3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0ca3d4;
P_0c0ca3d4: /* original 4721, guest PC 0x0c0ca3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]=(uint32_t)((int32_t)r[7]>>1);
goto P_0c0ca3d6;
P_0c0ca3d6: /* original 3563, guest PC 0x0c0ca3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0ca3d8;
P_0c0ca3d8: /* original 8ff8, guest PC 0x0c0ca3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d8u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c0ca3cc; }
goto P_0c0ca3dc;
P_0c0ca3da: /* original 740c, guest PC 0x0c0ca3da */
if(!s->budget--) { s->failed_pc=0x0c0ca3dau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0ca3dc;
P_0c0ca3dc: /* original d315, guest PC 0x0c0ca3dc */
if(!s->budget--) { s->failed_pc=0x0c0ca3dcu; return 0; }
r[3]=read(ram,0x0c0ca434u,4);
goto P_0c0ca3de;
P_0c0ca3de: /* original e008, guest PC 0x0c0ca3de */
if(!s->budget--) { s->failed_pc=0x0c0ca3deu; return 0; }
r[0]=0x00000008u;
goto P_0c0ca3e0;
P_0c0ca3e0: /* original ff46, guest PC 0x0c0ca3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e0u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c0ca3e2;
P_0c0ca3e2: /* original 6030, guest PC 0x0c0ca3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0ca3e4;
P_0c0ca3e4: /* original 9c25, guest PC 0x0c0ca3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca432u,2);
goto P_0c0ca3e6;
P_0c0ca3e6: /* original 600c, guest PC 0x0c0ca3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ca3e8;
P_0c0ca3e8: /* original fe48, guest PC 0x0c0ca3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e8u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
goto P_0c0ca3ea;
P_0c0ca3ea: /* original c90f, guest PC 0x0c0ca3ea */
if(!s->budget--) { s->failed_pc=0x0c0ca3eau; return 0; }
r[0]&=15u;
goto P_0c0ca3ec;
P_0c0ca3ec: /* original ff4d, guest PC 0x0c0ca3ec */
if(!s->budget--) { s->failed_pc=0x0c0ca3ecu; return 0; }
fr[15]^=0x80000000u;
goto P_0c0ca3ee;
P_0c0ca3ee: /* original 880f, guest PC 0x0c0ca3ee */
if(!s->budget--) { s->failed_pc=0x0c0ca3eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0ca3f0;
P_0c0ca3f0: /* original 8d2a, guest PC 0x0c0ca3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f0u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c0ca448; }
goto P_0c0ca3f4;
P_0c0ca3f2: /* original 2f02, guest PC 0x0c0ca3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0ca3f4;
P_0c0ca3f4: /* original 64f3, guest PC 0x0c0ca3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f4u; return 0; }
r[4]=r[15];
goto P_0c0ca3f6;
P_0c0ca3f6: /* original 65f3, guest PC 0x0c0ca3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f6u; return 0; }
r[5]=r[15];
goto P_0c0ca3f8;
P_0c0ca3f8: /* original d111, guest PC 0x0c0ca3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f8u; return 0; }
r[1]=read(ram,0x0c0ca440u,4);
goto P_0c0ca3fa;
P_0c0ca3fa: /* original 66f3, guest PC 0x0c0ca3fa */
if(!s->budget--) { s->failed_pc=0x0c0ca3fau; return 0; }
r[6]=r[15];
goto P_0c0ca3fc;
P_0c0ca3fc: /* original 7404, guest PC 0x0c0ca3fc */
if(!s->budget--) { s->failed_pc=0x0c0ca3fcu; return 0; }
r[4]+=0x00000004u;
goto P_0c0ca3fe;
P_0c0ca3fe: /* original f5fc, guest PC 0x0c0ca3fe */
if(!s->budget--) { s->failed_pc=0x0c0ca3feu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0ca400;
P_0c0ca400: /* original 67f3, guest PC 0x0c0ca400 */
if(!s->budget--) { s->failed_pc=0x0c0ca400u; return 0; }
r[7]=r[15];
goto P_0c0ca402;
P_0c0ca402: /* original 760c, guest PC 0x0c0ca402 */
if(!s->budget--) { s->failed_pc=0x0c0ca402u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0ca404;
P_0c0ca404: /* original 7508, guest PC 0x0c0ca404 */
if(!s->budget--) { s->failed_pc=0x0c0ca404u; return 0; }
r[5]+=0x00000008u;
goto P_0c0ca406;
P_0c0ca406: /* original 410b, guest PC 0x0c0ca406 */
if(!s->budget--) { s->failed_pc=0x0c0ca406u; return 0; }
target=r[1];
r[16]=0x0c0ca40au;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca40au) { target=s->pc; goto dispatch; }
goto P_0c0ca40a;
P_0c0ca408: /* original f4ec, guest PC 0x0c0ca408 */
if(!s->budget--) { s->failed_pc=0x0c0ca408u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0ca40a;
P_0c0ca40a: /* original 63f2, guest PC 0x0c0ca40a */
if(!s->budget--) { s->failed_pc=0x0c0ca40au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca40c;
P_0c0ca40c: /* original d40d, guest PC 0x0c0ca40c */
if(!s->budget--) { s->failed_pc=0x0c0ca40cu; return 0; }
r[4]=read(ram,0x0c0ca444u,4);
goto P_0c0ca40e;
P_0c0ca40e: /* original 633b, guest PC 0x0c0ca40e */
if(!s->budget--) { s->failed_pc=0x0c0ca40eu; return 0; }
r[3]=0u-r[3];
goto P_0c0ca410;
P_0c0ca410: /* original 4311, guest PC 0x0c0ca410 */
if(!s->budget--) { s->failed_pc=0x0c0ca410u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0ca412;
P_0c0ca412: /* original 8d04, guest PC 0x0c0ca412 */
if(!s->budget--) { s->failed_pc=0x0c0ca412u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c0ca41e; }
goto P_0c0ca416;
P_0c0ca414: /* original 2f32, guest PC 0x0c0ca414 */
if(!s->budget--) { s->failed_pc=0x0c0ca414u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca416;
P_0c0ca416: /* original 61f2, guest PC 0x0c0ca416 */
if(!s->budget--) { s->failed_pc=0x0c0ca416u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0ca418;
P_0c0ca418: /* original 314c, guest PC 0x0c0ca418 */
if(!s->budget--) { s->failed_pc=0x0c0ca418u; return 0; }
r[1]+=r[4];
goto P_0c0ca41a;
P_0c0ca41a: /* original a01d, guest PC 0x0c0ca41a */
if(!s->budget--) { s->failed_pc=0x0c0ca41au; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ca458;
P_0c0ca41c: /* original 2f12, guest PC 0x0c0ca41c */
if(!s->budget--) { s->failed_pc=0x0c0ca41cu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ca41e;
P_0c0ca41e: /* original 62f2, guest PC 0x0c0ca41e */
if(!s->budget--) { s->failed_pc=0x0c0ca41eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ca420;
P_0c0ca420: /* original 3248, guest PC 0x0c0ca420 */
if(!s->budget--) { s->failed_pc=0x0c0ca420u; return 0; }
r[2]-=r[4];
goto P_0c0ca422;
P_0c0ca422: /* original a019, guest PC 0x0c0ca422 */
if(!s->budget--) { s->failed_pc=0x0c0ca422u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ca458;
P_0c0ca424: /* original 2f22, guest PC 0x0c0ca424 */
if(!s->budget--) { s->failed_pc=0x0c0ca424u; return 0; }
write(ram,r[15],r[2],4);
return vf3_matrix_family(0x0c0ca426u,s,ram);
P_0c0ca448: /* original d249, guest PC 0x0c0ca448 */
if(!s->budget--) { s->failed_pc=0x0c0ca448u; return 0; }
r[2]=read(ram,0x0c0ca570u,4);
goto P_0c0ca44a;
P_0c0ca44a: /* original f5ec, guest PC 0x0c0ca44a */
if(!s->budget--) { s->failed_pc=0x0c0ca44au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0ca44c;
P_0c0ca44c: /* original 420b, guest PC 0x0c0ca44c */
if(!s->budget--) { s->failed_pc=0x0c0ca44cu; return 0; }
target=r[2];
r[16]=0x0c0ca450u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca450u) { target=s->pc; goto dispatch; }
goto P_0c0ca450;
P_0c0ca44e: /* original f4fc, guest PC 0x0c0ca44e */
if(!s->budget--) { s->failed_pc=0x0c0ca44eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ca450;
P_0c0ca450: /* original 600f, guest PC 0x0c0ca450 */
if(!s->budget--) { s->failed_pc=0x0c0ca450u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0ca452;
P_0c0ca452: /* original 6303, guest PC 0x0c0ca452 */
if(!s->budget--) { s->failed_pc=0x0c0ca452u; return 0; }
r[3]=r[0];
goto P_0c0ca454;
P_0c0ca454: /* original 33c8, guest PC 0x0c0ca454 */
if(!s->budget--) { s->failed_pc=0x0c0ca454u; return 0; }
r[3]-=r[12];
goto P_0c0ca456;
P_0c0ca456: /* original 2f32, guest PC 0x0c0ca456 */
if(!s->budget--) { s->failed_pc=0x0c0ca456u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca458;
P_0c0ca458: /* original 64f2, guest PC 0x0c0ca458 */
if(!s->budget--) { s->failed_pc=0x0c0ca458u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0ca45a;
P_0c0ca45a: /* original d346, guest PC 0x0c0ca45a */
if(!s->budget--) { s->failed_pc=0x0c0ca45au; return 0; }
r[3]=read(ram,0x0c0ca574u,4);
goto P_0c0ca45c;
P_0c0ca45c: /* original 34cc, guest PC 0x0c0ca45c */
if(!s->budget--) { s->failed_pc=0x0c0ca45cu; return 0; }
r[4]+=r[12];
goto P_0c0ca45e;
P_0c0ca45e: /* original 430b, guest PC 0x0c0ca45e */
if(!s->budget--) { s->failed_pc=0x0c0ca45eu; return 0; }
target=r[3];
r[16]=0x0c0ca462u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca462u) { target=s->pc; goto dispatch; }
goto P_0c0ca462;
P_0c0ca460: /* original 644f, guest PC 0x0c0ca460 */
if(!s->budget--) { s->failed_pc=0x0c0ca460u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ca462;
P_0c0ca462: /* original e008, guest PC 0x0c0ca462 */
if(!s->budget--) { s->failed_pc=0x0c0ca462u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca464;
P_0c0ca464: /* original ff07, guest PC 0x0c0ca464 */
if(!s->budget--) { s->failed_pc=0x0c0ca464u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ca466;
P_0c0ca466: /* original 64f2, guest PC 0x0c0ca466 */
if(!s->budget--) { s->failed_pc=0x0c0ca466u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0ca468;
P_0c0ca468: /* original d343, guest PC 0x0c0ca468 */
if(!s->budget--) { s->failed_pc=0x0c0ca468u; return 0; }
r[3]=read(ram,0x0c0ca578u,4);
goto P_0c0ca46a;
P_0c0ca46a: /* original 34cc, guest PC 0x0c0ca46a */
if(!s->budget--) { s->failed_pc=0x0c0ca46au; return 0; }
r[4]+=r[12];
goto P_0c0ca46c;
P_0c0ca46c: /* original 430b, guest PC 0x0c0ca46c */
if(!s->budget--) { s->failed_pc=0x0c0ca46cu; return 0; }
target=r[3];
r[16]=0x0c0ca470u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca470u) { target=s->pc; goto dispatch; }
goto P_0c0ca470;
P_0c0ca46e: /* original 644f, guest PC 0x0c0ca46e */
if(!s->budget--) { s->failed_pc=0x0c0ca46eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ca470;
P_0c0ca470: /* original e004, guest PC 0x0c0ca470 */
if(!s->budget--) { s->failed_pc=0x0c0ca470u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca472;
P_0c0ca472: /* original 65d3, guest PC 0x0c0ca472 */
if(!s->budget--) { s->failed_pc=0x0c0ca472u; return 0; }
r[5]=r[13];
goto P_0c0ca474;
P_0c0ca474: /* original ff07, guest PC 0x0c0ca474 */
if(!s->budget--) { s->failed_pc=0x0c0ca474u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ca476;
P_0c0ca476: /* original c741, guest PC 0x0c0ca476 */
if(!s->budget--) { s->failed_pc=0x0c0ca476u; return 0; }
r[0]=0x0c0ca57cu;
goto P_0c0ca478;
P_0c0ca478: /* original f408, guest PC 0x0c0ca478 */
if(!s->budget--) { s->failed_pc=0x0c0ca478u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ca47a;
P_0c0ca47a: /* original e008, guest PC 0x0c0ca47a */
if(!s->budget--) { s->failed_pc=0x0c0ca47au; return 0; }
r[0]=0x00000008u;
goto P_0c0ca47c;
P_0c0ca47c: /* original f30c, guest PC 0x0c0ca47c */
if(!s->budget--) { s->failed_pc=0x0c0ca47cu; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0ca47e;
P_0c0ca47e: /* original f342, guest PC 0x0c0ca47e */
if(!s->budget--) { s->failed_pc=0x0c0ca47eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0ca480;
P_0c0ca480: /* original fd3a, guest PC 0x0c0ca480 */
if(!s->budget--) { s->failed_pc=0x0c0ca480u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c0ca482;
P_0c0ca482: /* original f3f6, guest PC 0x0c0ca482 */
if(!s->budget--) { s->failed_pc=0x0c0ca482u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca484;
P_0c0ca484: /* original e004, guest PC 0x0c0ca484 */
if(!s->budget--) { s->failed_pc=0x0c0ca484u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca486;
P_0c0ca486: /* original f342, guest PC 0x0c0ca486 */
if(!s->budget--) { s->failed_pc=0x0c0ca486u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0ca488;
P_0c0ca488: /* original fd37, guest PC 0x0c0ca488 */
if(!s->budget--) { s->failed_pc=0x0c0ca488u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0ca48a;
P_0c0ca48a: /* original 63f2, guest PC 0x0c0ca48a */
if(!s->budget--) { s->failed_pc=0x0c0ca48au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca48c;
P_0c0ca48c: /* original 1d32, guest PC 0x0c0ca48c */
if(!s->budget--) { s->failed_pc=0x0c0ca48cu; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0ca48e;
P_0c0ca48e: /* original bf53, guest PC 0x0c0ca48e */
if(!s->budget--) { s->failed_pc=0x0c0ca48eu; return 0; }
target=0x0c0ca338u; r[16]=0x0c0ca492u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca492u) { target=s->pc; goto dispatch; }
goto P_0c0ca492;
P_0c0ca490: /* original 64e3, guest PC 0x0c0ca490 */
if(!s->budget--) { s->failed_pc=0x0c0ca490u; return 0; }
r[4]=r[14];
goto P_0c0ca492;
P_0c0ca492: /* original 7f14, guest PC 0x0c0ca492 */
if(!s->budget--) { s->failed_pc=0x0c0ca492u; return 0; }
r[15]+=0x00000014u;
goto P_0c0ca494;
P_0c0ca494: /* original 4f26, guest PC 0x0c0ca494 */
if(!s->budget--) { s->failed_pc=0x0c0ca494u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca496;
P_0c0ca496: /* original fef9, guest PC 0x0c0ca496 */
if(!s->budget--) { s->failed_pc=0x0c0ca496u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca498;
P_0c0ca498: /* original fff9, guest PC 0x0c0ca498 */
if(!s->budget--) { s->failed_pc=0x0c0ca498u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca49a;
P_0c0ca49a: /* original 6bf6, guest PC 0x0c0ca49a */
if(!s->budget--) { s->failed_pc=0x0c0ca49au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ca49c;
P_0c0ca49c: /* original 6cf6, guest PC 0x0c0ca49c */
if(!s->budget--) { s->failed_pc=0x0c0ca49cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ca49e;
P_0c0ca49e: /* original 6df6, guest PC 0x0c0ca49e */
if(!s->budget--) { s->failed_pc=0x0c0ca49eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ca4a0;
P_0c0ca4a0: /* original 000b, guest PC 0x0c0ca4a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca4a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ca4a2: /* original 6ef6, guest PC 0x0c0ca4a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca4a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ca4a4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03a140u,0x0c03a142u,0x0c03a144u,0x0c03a146u,0x0c03a148u,0x0c03a14au,0x0c03a14cu,0x0c03a14eu,0x0c03a150u,0x0c03a152u,0x0c03a154u,0x0c03a156u,0x0c03a6e0u,0x0c03a6e2u,0x0c03a6e4u,0x0c03a6e6u,
0x0c03a6e8u,0x0c03a6eau,0x0c03a6ecu,0x0c03a6eeu,0x0c03a6f0u,0x0c03a6f2u,0x0c03a6f4u,0x0c03a6f6u,0x0c03a6f8u,0x0c03a6fau,0x0c03a6fcu,0x0c03a6feu,0x0c03a700u,0x0c03a702u,0x0c03a704u,0x0c03a706u,
0x0c03a708u,0x0c03a70au,0x0c03a70cu,0x0c03a70eu,0x0c03a710u,0x0c03a712u,0x0c03a714u,0x0c03a716u,0x0c03a718u,0x0c03a71au,0x0c03a71cu,0x0c03a71eu,0x0c03a720u,0x0c03a722u,0x0c03a724u,0x0c03a726u,
0x0c03a728u,0x0c03a72au,0x0c03a72cu,0x0c03a72eu,0x0c03a730u,0x0c03a732u,0x0c03a734u,0x0c03a736u,0x0c03a738u,0x0c03a73au,0x0c03a73cu,0x0c03a73eu,0x0c03a740u,0x0c03a742u,0x0c03a744u,0x0c03a746u,
0x0c03a748u,0x0c03a74au,0x0c03a750u,0x0c03a752u,0x0c03a754u,0x0c03a756u,0x0c03b450u,0x0c03b452u,0x0c03b454u,0x0c03b456u,0x0c03b458u,0x0c03b45au,0x0c03b45cu,0x0c03b45eu,0x0c03b460u,0x0c03b462u,
0x0c03b464u,0x0c03b466u,0x0c069624u,0x0c069626u,0x0c069628u,0x0c06962au,0x0c06962cu,0x0c06962eu,0x0c069630u,0x0c069632u,0x0c069634u,0x0c069636u,0x0c069638u,0x0c06963au,0x0c06963cu,0x0c06963eu,
0x0c069640u,0x0c069642u,0x0c069644u,0x0c069646u,0x0c069648u,0x0c06964au,0x0c06964cu,0x0c06964eu,0x0c069650u,0x0c069652u,0x0c069654u,0x0c069656u,0x0c069658u,0x0c06965au,0x0c06965cu,0x0c06965eu,
0x0c069660u,0x0c069662u,0x0c069664u,0x0c069666u,0x0c069668u,0x0c06966au,0x0c06966cu,0x0c06966eu,0x0c069670u,0x0c069672u,0x0c069674u,0x0c069676u,0x0c069678u,0x0c06967au,0x0c06967cu,0x0c06967eu,
0x0c069680u,0x0c069682u,0x0c069684u,0x0c069686u,0x0c069688u,0x0c06968au,0x0c06968cu,0x0c06968eu,0x0c069690u,0x0c069692u,0x0c069694u,0x0c069696u,0x0c069698u,0x0c06969au,0x0c06969cu,0x0c06e8c4u,
0x0c06e8c6u,0x0c06e8c8u,0x0c06e8cau,0x0c06e8ccu,0x0c06e8ceu,0x0c06e8d0u,0x0c06e8d2u,0x0c06e8d4u,0x0c06e8d6u,0x0c06e8d8u,0x0c06e8dau,0x0c06e8dcu,0x0c06e8deu,0x0c06e8e0u,0x0c06e8e2u,0x0c06e8e4u,
0x0c06e8e6u,0x0c06e8e8u,0x0c06e8eau,0x0c06e8ecu,0x0c06e8eeu,0x0c06e8f0u,0x0c06e8f2u,0x0c06e8f4u,0x0c06e8f6u,0x0c06e8f8u,0x0c06e8fau,0x0c06e8fcu,0x0c06e8feu,0x0c06e900u,0x0c06e902u,0x0c06e904u,
0x0c06e906u,0x0c06e908u,0x0c06e90au,0x0c06e90cu,0x0c06e90eu,0x0c06e910u,0x0c06e912u,0x0c06e914u,0x0c06e916u,0x0c06e918u,0x0c06e91au,0x0c06e91cu,0x0c06e91eu,0x0c06e920u,0x0c06e922u,0x0c06e924u,
0x0c06e926u,0x0c06e928u,0x0c06e92au,0x0c06e92cu,0x0c06e92eu,0x0c06e930u,0x0c06e932u,0x0c06e934u,0x0c06e936u,0x0c06e938u,0x0c06e93au,0x0c06e93cu,0x0c06e93eu,0x0c06e940u,0x0c06e964u,0x0c06e966u,
0x0c06e968u,0x0c06e96au,0x0c06e96cu,0x0c06e96eu,0x0c06e970u,0x0c06e972u,0x0c06e974u,0x0c06e976u,0x0c06e978u,0x0c06e97au,0x0c06e97cu,0x0c06e97eu,0x0c06e980u,0x0c06e982u,0x0c06e984u,0x0c06e986u,
0x0c06e988u,0x0c06e98au,0x0c06e98cu,0x0c06e98eu,0x0c06e990u,0x0c06e992u,0x0c06e994u,0x0c06e996u,0x0c06e998u,0x0c06e99au,0x0c06e99cu,0x0c06e99eu,0x0c06e9a0u,0x0c06e9a2u,0x0c06e9a4u,0x0c06e9a6u,
0x0c06e9a8u,0x0c06e9aau,0x0c06e9acu,0x0c06e9aeu,0x0c06e9b0u,0x0c06e9b2u,0x0c06e9b4u,0x0c06e9b6u,0x0c06e9b8u,0x0c06e9bau,0x0c06e9bcu,0x0c06e9beu,0x0c06e9c0u,0x0c06e9c2u,0x0c06e9c4u,0x0c06e9c6u,
0x0c06e9c8u,0x0c06e9cau,0x0c06e9ccu,0x0c06e9ceu,0x0c06e9d0u,0x0c06e9d2u,0x0c06e9d4u,0x0c06e9d6u,0x0c06e9d8u,0x0c06e9dau,0x0c06e9dcu,0x0c06e9deu,0x0c06e9e0u,0x0c06e9e2u,0x0c06e9e4u,0x0c06e9e6u,
0x0c06e9e8u,0x0c06e9eau,0x0c06e9ecu,0x0c06e9eeu,0x0c06e9f0u,0x0c06e9f2u,0x0c06e9f4u,0x0c06e9f6u,0x0c06e9f8u,0x0c06e9fau,0x0c06e9fcu,0x0c06e9feu,0x0c06ea00u,0x0c06ea02u,0x0c06ea04u,0x0c06ea06u,
0x0c06ea08u,0x0c06ea0au,0x0c06ea0cu,0x0c06ea0eu,0x0c06ea10u,0x0c06ea12u,0x0c06ea14u,0x0c06ea16u,0x0c06ea18u,0x0c06ea1au,0x0c06ea1cu,0x0c06ea1eu,0x0c06ea20u,0x0c06ea22u,0x0c06ea24u,0x0c06ea26u,
0x0c06ea28u,0x0c06ea2au,0x0c06ea2cu,0x0c06ea2eu,0x0c06ea30u,0x0c06ea32u,0x0c06ea34u,0x0c06ea36u,0x0c06ea38u,0x0c06ea3au,0x0c06ea3cu,0x0c06ea3eu,0x0c06ea40u,0x0c06ea42u,0x0c06ea44u,0x0c06ea46u,
0x0c06ea48u,0x0c06ea4au,0x0c06ea4cu,0x0c06ea4eu,0x0c06ea50u,0x0c06ea52u,0x0c06ea54u,0x0c06ea56u,0x0c06ea58u,0x0c06ea5au,0x0c06ea5cu,0x0c06ea5eu,0x0c06ea60u,0x0c06ea62u,0x0c06ea64u,0x0c06ea66u,
0x0c06ea68u,0x0c06ea6au,0x0c06ea6cu,0x0c06ea6eu,0x0c06ea70u,0x0c06ea72u,0x0c06ea74u,0x0c06ea76u,0x0c06ea78u,0x0c06ea7au,0x0c06ea7cu,0x0c06ea7eu,0x0c06ea80u,0x0c06ea82u,0x0c06ea84u,0x0c06ea86u,
0x0c06ea88u,0x0c06ea8au,0x0c06ea8cu,0x0c06ea8eu,0x0c06ea90u,0x0c06ea92u,0x0c06ea94u,0x0c0876f2u,0x0c0876f4u,0x0c0876f6u,0x0c0876f8u,0x0c0876fau,0x0c0876fcu,0x0c0876feu,0x0c087700u,0x0c087702u,
0x0c087704u,0x0c087706u,0x0c087708u,0x0c08770au,0x0c08770cu,0x0c08770eu,0x0c087710u,0x0c087712u,0x0c087714u,0x0c087716u,0x0c087718u,0x0c08771au,0x0c08771cu,0x0c08771eu,0x0c087720u,0x0c087722u,
0x0c087724u,0x0c087726u,0x0c087728u,0x0c08772au,0x0c08772cu,0x0c08772eu,0x0c087730u,0x0c087732u,0x0c08d158u,0x0c08d15au,0x0c08d15cu,0x0c08d15eu,0x0c08d160u,0x0c08d162u,0x0c08d164u,0x0c08d166u,
0x0c08d168u,0x0c08d16au,0x0c08d16cu,0x0c08d16eu,0x0c08d170u,0x0c08d172u,0x0c08d174u,0x0c08d176u,0x0c08d178u,0x0c08d17au,0x0c08d17cu,0x0c08d17eu,0x0c08d180u,0x0c08d182u,0x0c08d184u,0x0c08d186u,
0x0c08d188u,0x0c08d18au,0x0c08d18cu,0x0c08d18eu,0x0c08d190u,0x0c08d406u,0x0c08d408u,0x0c08d40au,0x0c08d40cu,0x0c08d40eu,0x0c08d410u,0x0c08d412u,0x0c08d414u,0x0c08d416u,0x0c08d418u,0x0c08d41au,
0x0c08d41cu,0x0c08d41eu,0x0c08d420u,0x0c08d422u,0x0c08d424u,0x0c08d426u,0x0c08d428u,0x0c08d42au,0x0c08d42cu,0x0c08d42eu,0x0c08d430u,0x0c08d432u,0x0c08d434u,0x0c08d436u,0x0c08d438u,0x0c08d43au,
0x0c08d43cu,0x0c08d43eu,0x0c08d440u,0x0c08d442u,0x0c08d444u,0x0c08d446u,0x0c08d448u,0x0c08d44au,0x0c09d5aeu,0x0c09d5b0u,0x0c09d5b2u,0x0c09d5b4u,0x0c09d5b6u,0x0c09d5b8u,0x0c09d5bau,0x0c09d5bcu,
0x0c09d5beu,0x0c09d5c0u,0x0c09d5c2u,0x0c09d5c4u,0x0c09d5c6u,0x0c09d5c8u,0x0c09d5cau,0x0c09d5ccu,0x0c09d5ceu,0x0c09d5d0u,0x0c09d5d2u,0x0c09d5d4u,0x0c09d5d6u,0x0c09d5d8u,0x0c09d5dau,0x0c09d5dcu,
0x0c09d5deu,0x0c09d5e0u,0x0c09d5e2u,0x0c09d5e4u,0x0c09d5e6u,0x0c09d5e8u,0x0c09d5eau,0x0c09d5ecu,0x0c09d5eeu,0x0c09d5f0u,0x0c09d5f2u,0x0c09d5f4u,0x0c09d5f6u,0x0c09d5f8u,0x0c09d5fau,0x0c09d5fcu,
0x0c09d5feu,0x0c09d600u,0x0c09d602u,0x0c09d604u,0x0c09d606u,0x0c09d608u,0x0c09d60au,0x0c09d60cu,0x0c09d60eu,0x0c09d610u,0x0c09d612u,0x0c09d614u,0x0c09d616u,0x0c09d618u,0x0c09d61au,0x0c09d61cu,
0x0c09d61eu,0x0c09d620u,0x0c09d622u,0x0c09d624u,0x0c09d626u,0x0c09d628u,0x0c09d62au,0x0c09d62cu,0x0c09d62eu,0x0c09d630u,0x0c09d632u,0x0c09d634u,0x0c09d636u,0x0c09d638u,0x0c09d63au,0x0c09d63cu,
0x0c09d63eu,0x0c09d640u,0x0c09d642u,0x0c09d644u,0x0c09d646u,0x0c09d648u,0x0c09d64au,0x0c09d64cu,0x0c09d64eu,0x0c09d650u,0x0c09d652u,0x0c09d654u,0x0c09d656u,0x0c09d658u,0x0c09d65au,0x0c09d65cu,
0x0c09d65eu,0x0c09d660u,0x0c09d662u,0x0c09efceu,0x0c09efd0u,0x0c09efd2u,0x0c09efd4u,0x0c09efd6u,0x0c09efd8u,0x0c09efdau,0x0c09efdcu,0x0c09efdeu,0x0c09efe0u,0x0c09efe2u,0x0c09efe4u,0x0c09f1acu,
0x0c09f1aeu,0x0c09f1b0u,0x0c09f1b2u,0x0c09f1b4u,0x0c09f1b6u,0x0c09f1b8u,0x0c09f1bau,0x0c09f1bcu,0x0c09f1beu,0x0c09f1c0u,0x0c09f1c2u,0x0c09f1c4u,0x0c09f1c6u,0x0c09f1c8u,0x0c09f1cau,0x0c09f1ccu,
0x0c09f1ceu,0x0c09f1d0u,0x0c09f1d2u,0x0c09f1d4u,0x0c09f1d6u,0x0c09f1d8u,0x0c09f1dau,0x0c09f1dcu,0x0c09f1deu,0x0c09f1e0u,0x0c09f1e2u,0x0c09f1e4u,0x0c09f1e6u,0x0c09f1e8u,0x0c09f1eau,0x0c09f1ecu,
0x0c09f1eeu,0x0c09f1f0u,0x0c09f1f2u,0x0c09f1f4u,0x0c09f1f6u,0x0c09f1f8u,0x0c09f1fau,0x0c09f1fcu,0x0c09f1feu,0x0c09f200u,0x0c09f202u,0x0c09f204u,0x0c09f206u,0x0c09f208u,0x0c09f20au,0x0c09f20cu,
0x0c09f20eu,0x0c09f210u,0x0c09f212u,0x0c09f214u,0x0c09f216u,0x0c09f218u,0x0c09f21au,0x0c09f21cu,0x0c09f21eu,0x0c09f220u,0x0c09f222u,0x0c09f224u,0x0c09f226u,0x0c09f228u,0x0c09f22au,0x0c09f22cu,
0x0c09f22eu,0x0c09f230u,0x0c09f232u,0x0c09f234u,0x0c09f236u,0x0c09f238u,0x0c09f23au,0x0c09f23cu,0x0c09f23eu,0x0c09f240u,0x0c09f242u,0x0c09f244u,0x0c09f246u,0x0c09f248u,0x0c09f24au,0x0c09f24cu,
0x0c09f24eu,0x0c09f250u,0x0c09f268u,0x0c09f26au,0x0c09f26cu,0x0c09f26eu,0x0c09f270u,0x0c09f272u,0x0c09f274u,0x0c09f276u,0x0c09f278u,0x0c09f27au,0x0c09f27cu,0x0c09f27eu,0x0c09f280u,0x0c09f282u,
0x0c09f284u,0x0c09f286u,0x0c09f288u,0x0c09f28au,0x0c09f28cu,0x0c09f28eu,0x0c09f290u,0x0c09f292u,0x0c09f294u,0x0c09f296u,0x0c09f298u,0x0c09f29au,0x0c09f29cu,0x0c09f29eu,0x0c09f2a0u,0x0c09f2a2u,
0x0c09f2a4u,0x0c09f2a6u,0x0c09f2a8u,0x0c09f2aau,0x0c09f2acu,0x0c09f2aeu,0x0c09f2b0u,0x0c09f2b2u,0x0c09f2b4u,0x0c09f2b6u,0x0c09f2b8u,0x0c09f2bau,0x0c09f2bcu,0x0c09f2beu,0x0c09f2c0u,0x0c09f2c2u,
0x0c09f2c4u,0x0c09f2c6u,0x0c09f2c8u,0x0c09f2cau,0x0c09f2ccu,0x0c09f2ceu,0x0c09f2d0u,0x0c09f2d2u,0x0c09f2d4u,0x0c09f2d6u,0x0c09f2d8u,0x0c09f2dau,0x0c09f2dcu,0x0c09f2deu,0x0c09f2e0u,0x0c09f2e2u,
0x0c09f2e4u,0x0c09f2e6u,0x0c09f2e8u,0x0c09f2eau,0x0c09f2ecu,0x0c09f2eeu,0x0c09f2f0u,0x0c09f2f2u,0x0c09f2f4u,0x0c09f2f6u,0x0c09f2f8u,0x0c09f2fau,0x0c09f2fcu,0x0c09f2feu,0x0c09f300u,0x0c09f302u,
0x0c09f304u,0x0c09f306u,0x0c09f308u,0x0c09f30au,0x0c09f30cu,0x0c09f30eu,0x0c09f310u,0x0c09f312u,0x0c09f314u,0x0c09f316u,0x0c09f318u,0x0c09f31au,0x0c09f31cu,0x0c09f31eu,0x0c09f320u,0x0c09f322u,
0x0c09f324u,0x0c09f326u,0x0c09f328u,0x0c09f32au,0x0c09f32cu,0x0c09f32eu,0x0c09f330u,0x0c09f332u,0x0c09f334u,0x0c0ac192u,0x0c0ac194u,0x0c0ac196u,0x0c0ac198u,0x0c0ac19au,0x0c0ac19cu,0x0c0ac19eu,
0x0c0ac1a0u,0x0c0ac1a2u,0x0c0ac1a4u,0x0c0ac1a6u,0x0c0ac1a8u,0x0c0ac1aau,0x0c0ac1acu,0x0c0ac1aeu,0x0c0ac1b0u,0x0c0ac1b2u,0x0c0ac1b4u,0x0c0ac1b6u,0x0c0ac1b8u,0x0c0ac1bau,0x0c0ac1bcu,0x0c0ac1beu,
0x0c0ac1c0u,0x0c0ac1c2u,0x0c0ac1c4u,0x0c0ac1c6u,0x0c0ac1c8u,0x0c0ac1cau,0x0c0ac1ccu,0x0c0ac1ceu,0x0c0ac1d0u,0x0c0ac1d2u,0x0c0ac1d4u,0x0c0ac1d6u,0x0c0ac1d8u,0x0c0ac1dau,0x0c0ac1dcu,0x0c0ac1deu,
0x0c0ac1e0u,0x0c0ac1e2u,0x0c0ac1e4u,0x0c0ac1e6u,0x0c0ac1e8u,0x0c0ac1eau,0x0c0ac1ecu,0x0c0ac1eeu,0x0c0ac1f0u,0x0c0ac1f2u,0x0c0ac1f4u,0x0c0ac1f6u,0x0c0ac1f8u,0x0c0ac1fau,0x0c0ac1fcu,0x0c0ac1feu,
0x0c0ac200u,0x0c0ac202u,0x0c0ac204u,0x0c0ac206u,0x0c0ac208u,0x0c0ac20au,0x0c0ac20cu,0x0c0ac20eu,0x0c0ac210u,0x0c0ac212u,0x0c0ac214u,0x0c0ac216u,0x0c0ac218u,0x0c0ac21au,0x0c0ac21cu,0x0c0ac21eu,
0x0c0ac220u,0x0c0ac222u,0x0c0ac224u,0x0c0ac226u,0x0c0ac228u,0x0c0ad112u,0x0c0ad114u,0x0c0ad116u,0x0c0ad118u,0x0c0ad11au,0x0c0ad11cu,0x0c0ad11eu,0x0c0ad120u,0x0c0ad122u,0x0c0ad124u,0x0c0ad126u,
0x0c0ad128u,0x0c0ad12au,0x0c0ad12cu,0x0c0ad12eu,0x0c0ad164u,0x0c0ad166u,0x0c0ad168u,0x0c0ad16au,0x0c0ad16cu,0x0c0ad16eu,0x0c0ad170u,0x0c0ad172u,0x0c0ad174u,0x0c0ad176u,0x0c0ad1aau,0x0c0ad1acu,
0x0c0ad1aeu,0x0c0ad1b0u,0x0c0ad1b2u,0x0c0ad1b4u,0x0c0ad1b6u,0x0c0ad1b8u,0x0c0ad1bau,0x0c0ad1bcu,0x0c0ad1beu,0x0c0ad1c0u,0x0c0ad1c2u,0x0c0ad1c4u,0x0c0ad1c6u,0x0c0ad1c8u,0x0c0ad1cau,0x0c0ad1ccu,
0x0c0ad1ceu,0x0c0ad1d0u,0x0c0ad1d2u,0x0c0ad1d4u,0x0c0ad1d6u,0x0c0ad1d8u,0x0c0ad1dau,0x0c0ad1dcu,0x0c0ad1deu,0x0c0ad1e0u,0x0c0ad1e2u,0x0c0ad1e4u,0x0c0ad1e6u,0x0c0ad1e8u,0x0c0ad1eau,0x0c0ad1ecu,
0x0c0ad1eeu,0x0c0ad1f0u,0x0c0ad1f2u,0x0c0ad1f4u,0x0c0ad1f6u,0x0c0ad1f8u,0x0c0ad1fau,0x0c0ad1fcu,0x0c0ad1feu,0x0c0ad200u,0x0c0ad202u,0x0c0ad204u,0x0c0ad206u,0x0c0ad208u,0x0c0ad20au,0x0c0ad20cu,
0x0c0ad20eu,0x0c0ad210u,0x0c0ad212u,0x0c0ad214u,0x0c0ad216u,0x0c0ad218u,0x0c0ad21au,0x0c0ad21cu,0x0c0ad21eu,0x0c0ad220u,0x0c0ad222u,0x0c0ad224u,0x0c0ad226u,0x0c0ad228u,0x0c0ad22au,0x0c0ad22cu,
0x0c0ad22eu,0x0c0ad230u,0x0c0ad232u,0x0c0ad234u,0x0c0ad236u,0x0c0ad238u,0x0c0ad26cu,0x0c0ad26eu,0x0c0ad270u,0x0c0ad272u,0x0c0ad274u,0x0c0ad276u,0x0c0ad278u,0x0c0ad27au,0x0c0ad27cu,0x0c0ad27eu,
0x0c0ad280u,0x0c0ad282u,0x0c0ad284u,0x0c0ad286u,0x0c0ad288u,0x0c0ad28au,0x0c0ad28cu,0x0c0ad28eu,0x0c0ad290u,0x0c0ad292u,0x0c0ad294u,0x0c0ad296u,0x0c0ad298u,0x0c0ad29au,0x0c0ad29cu,0x0c0ad29eu,
0x0c0ad2a0u,0x0c0ad2a2u,0x0c0ad2a4u,0x0c0ad2a6u,0x0c0ad2a8u,0x0c0ad2aau,0x0c0ad2acu,0x0c0ad2aeu,0x0c0ad2b0u,0x0c0ad2b2u,0x0c0ad2b4u,0x0c0ad2b6u,0x0c0ad2b8u,0x0c0ad2bau,0x0c0ad2bcu,0x0c0ad2beu,
0x0c0ad2c0u,0x0c0ad2c2u,0x0c0ad2c4u,0x0c0ad2c6u,0x0c0ad2c8u,0x0c0ad2cau,0x0c0ad2ccu,0x0c0ad2ceu,0x0c0ad2d0u,0x0c0ad2d2u,0x0c0ad2d4u,0x0c0ad2d6u,0x0c0ad2d8u,0x0c0ad2dau,0x0c0ad2dcu,0x0c0ad2deu,
0x0c0ad2e0u,0x0c0ad2e2u,0x0c0ad2e4u,0x0c0ad2e6u,0x0c0ad2e8u,0x0c0ad2eau,0x0c0ad2ecu,0x0c0ad2eeu,0x0c0ad2f0u,0x0c0ad2f2u,0x0c0ad2f4u,0x0c0ad2f6u,0x0c0ad2f8u,0x0c0ad2fau,0x0c0ad2fcu,0x0c0ad2feu,
0x0c0ad300u,0x0c0ad302u,0x0c0ad304u,0x0c0ad306u,0x0c0ad308u,0x0c0ad30au,0x0c0ad30cu,0x0c0ad30eu,0x0c0ad310u,0x0c0ad312u,0x0c0ad314u,0x0c0ad316u,0x0c0ad318u,0x0c0ad31au,0x0c0ad31cu,0x0c0ad31eu,
0x0c0ad320u,0x0c0ad322u,0x0c0ad324u,0x0c0ad326u,0x0c0ad328u,0x0c0ad32au,0x0c0ad32cu,0x0c0ad32eu,0x0c0ad330u,0x0c0ad332u,0x0c0ad334u,0x0c0ad336u,0x0c0ad338u,0x0c0ad33au,0x0c0ad33cu,0x0c0ad33eu,
0x0c0ad340u,0x0c0ad342u,0x0c0ad344u,0x0c0ad346u,0x0c0ad348u,0x0c0ad34au,0x0c0ad34cu,0x0c0ad34eu,0x0c0ad350u,0x0c0ad352u,0x0c0ad390u,0x0c0ad392u,0x0c0ad394u,0x0c0ad396u,0x0c0ad398u,0x0c0ad39au,
0x0c0ad39cu,0x0c0ad39eu,0x0c0ad3a0u,0x0c0ad3a2u,0x0c0ad3a4u,0x0c0ad3a6u,0x0c0ad3a8u,0x0c0ad3aau,0x0c0ad3acu,0x0c0ad3aeu,0x0c0ad3b0u,0x0c0ad3b2u,0x0c0ad3b4u,0x0c0ad3b6u,0x0c0ad3b8u,0x0c0ad3bau,
0x0c0ad3bcu,0x0c0ad3beu,0x0c0ad3c0u,0x0c0ad3c2u,0x0c0ad3c4u,0x0c0ad3c6u,0x0c0ad3c8u,0x0c0ad3cau,0x0c0ad3ccu,0x0c0ad3ceu,0x0c0ad3d0u,0x0c0ad3d2u,0x0c0ad3d4u,0x0c0ad3d6u,0x0c0ad3d8u,0x0c0ad3dau,
0x0c0ad3dcu,0x0c0ad3deu,0x0c0ad3e0u,0x0c0ad3e2u,0x0c0ad3e4u,0x0c0ad3e6u,0x0c0ad3e8u,0x0c0ad3eau,0x0c0ad3ecu,0x0c0ad3eeu,0x0c0ad3f0u,0x0c0ad3f2u,0x0c0ad3f4u,0x0c0ad3f6u,0x0c0ad3f8u,0x0c0ad3fau,
0x0c0ad3fcu,0x0c0ad3feu,0x0c0ad400u,0x0c0ad402u,0x0c0ad404u,0x0c0ad406u,0x0c0ad408u,0x0c0ad40au,0x0c0ad40cu,0x0c0ad40eu,0x0c0ad410u,0x0c0ad412u,0x0c0ad414u,0x0c0ad416u,0x0c0ad418u,0x0c0ad41au,
0x0c0ad41cu,0x0c0ad41eu,0x0c0ad420u,0x0c0ad422u,0x0c0ad424u,0x0c0ad426u,0x0c0ad428u,0x0c0ad42au,0x0c0ad42cu,0x0c0ad42eu,0x0c0ad430u,0x0c0ad432u,0x0c0ad434u,0x0c0ad436u,0x0c0ad438u,0x0c0ad43au,
0x0c0ad43cu,0x0c0ad43eu,0x0c0ad440u,0x0c0ad442u,0x0c0ad444u,0x0c0ad446u,0x0c0ad448u,0x0c0ad44au,0x0c0ad44cu,0x0c0ad44eu,0x0c0ad450u,0x0c0ad452u,0x0c0ad454u,0x0c0ad456u,0x0c0ad458u,0x0c0ad45au,
0x0c0ad45cu,0x0c0ad45eu,0x0c0ad460u,0x0c0ad462u,0x0c0ad464u,0x0c0ad466u,0x0c0ad468u,0x0c0ad46au,0x0c0ad46cu,0x0c0ad46eu,0x0c0ad470u,0x0c0ad472u,0x0c0ad474u,0x0c0ad476u,0x0c0ad478u,0x0c0ad47au,
0x0c0ad47cu,0x0c0ad47eu,0x0c0ad480u,0x0c0ad482u,0x0c0ad484u,0x0c0ad486u,0x0c0ad488u,0x0c0ad48au,0x0c0ad48cu,0x0c0ad48eu,0x0c0ad490u,0x0c0ad492u,0x0c0ad494u,0x0c0ad496u,0x0c0ad498u,0x0c0ad49au,
0x0c0ad49cu,0x0c0ad49eu,0x0c0ad4a0u,0x0c0ad4a2u,0x0c0ad4a4u,0x0c0ad4a6u,0x0c0ad4a8u,0x0c0ad4aau,0x0c0ad4acu,0x0c0ad4aeu,0x0c0ad4b0u,0x0c0ad4b2u,0x0c0ad4b4u,0x0c0ad4b6u,0x0c0ad4b8u,0x0c0ad4bau,
0x0c0ad4bcu,0x0c0ad4beu,0x0c0ad4c0u,0x0c0ad4c2u,0x0c0ad4c4u,0x0c0ad4c6u,0x0c0ad4c8u,0x0c0ad4cau,0x0c0ad4ccu,0x0c0ad4ceu,0x0c0ad4d0u,0x0c0ad4d2u,0x0c0ad4d4u,0x0c0ad4d6u,0x0c0ad4d8u,0x0c0ad4dau,
0x0c0ad4dcu,0x0c0ad524u,0x0c0ad526u,0x0c0ad528u,0x0c0ad52au,0x0c0ad52cu,0x0c0ad52eu,0x0c0ad530u,0x0c0ad532u,0x0c0ad534u,0x0c0ad536u,0x0c0ad538u,0x0c0ad53au,0x0c0ad53cu,0x0c0ad53eu,0x0c0ad540u,
0x0c0ad542u,0x0c0ad544u,0x0c0ad546u,0x0c0ad548u,0x0c0ad54au,0x0c0ad54cu,0x0c0ad54eu,0x0c0ad550u,0x0c0ad552u,0x0c0ad554u,0x0c0ad556u,0x0c0ad558u,0x0c0ad55au,0x0c0ad55cu,0x0c0ad55eu,0x0c0ad560u,
0x0c0ad562u,0x0c0ad564u,0x0c0ad566u,0x0c0ad568u,0x0c0ad56au,0x0c0ad56cu,0x0c0ad56eu,0x0c0ad570u,0x0c0ad572u,0x0c0ad574u,0x0c0ad576u,0x0c0ad578u,0x0c0ad57au,0x0c0ad57cu,0x0c0ad57eu,0x0c0ad580u,
0x0c0ad582u,0x0c0ad584u,0x0c0ad586u,0x0c0ad588u,0x0c0ca338u,0x0c0ca33au,0x0c0ca33cu,0x0c0ca33eu,0x0c0ca340u,0x0c0ca342u,0x0c0ca344u,0x0c0ca346u,0x0c0ca348u,0x0c0ca34au,0x0c0ca34cu,0x0c0ca34eu,
0x0c0ca350u,0x0c0ca352u,0x0c0ca354u,0x0c0ca356u,0x0c0ca358u,0x0c0ca35au,0x0c0ca35cu,0x0c0ca35eu,0x0c0ca360u,0x0c0ca362u,0x0c0ca364u,0x0c0ca366u,0x0c0ca368u,0x0c0ca36au,0x0c0ca36cu,0x0c0ca36eu,
0x0c0ca370u,0x0c0ca372u,0x0c0ca374u,0x0c0ca376u,0x0c0ca378u,0x0c0ca37au,0x0c0ca37cu,0x0c0ca37eu,0x0c0ca380u,0x0c0ca382u,0x0c0ca384u,0x0c0ca386u,0x0c0ca388u,0x0c0ca38au,0x0c0ca38cu,0x0c0ca38eu,
0x0c0ca390u,0x0c0ca392u,0x0c0ca394u,0x0c0ca396u,0x0c0ca398u,0x0c0ca39au,0x0c0ca39cu,0x0c0ca39eu,0x0c0ca3a0u,0x0c0ca3a2u,0x0c0ca3a4u,0x0c0ca3a6u,0x0c0ca3a8u,0x0c0ca3aau,0x0c0ca3acu,0x0c0ca3aeu,
0x0c0ca3b0u,0x0c0ca3b2u,0x0c0ca3b4u,0x0c0ca3b6u,0x0c0ca3b8u,0x0c0ca3bau,0x0c0ca3bcu,0x0c0ca3beu,0x0c0ca3c0u,0x0c0ca3c2u,0x0c0ca3c4u,0x0c0ca3c6u,0x0c0ca3c8u,0x0c0ca3cau,0x0c0ca3ccu,0x0c0ca3ceu,
0x0c0ca3d0u,0x0c0ca3d2u,0x0c0ca3d4u,0x0c0ca3d6u,0x0c0ca3d8u,0x0c0ca3dau,0x0c0ca3dcu,0x0c0ca3deu,0x0c0ca3e0u,0x0c0ca3e2u,0x0c0ca3e4u,0x0c0ca3e6u,0x0c0ca3e8u,0x0c0ca3eau,0x0c0ca3ecu,0x0c0ca3eeu,
0x0c0ca3f0u,0x0c0ca3f2u,0x0c0ca3f4u,0x0c0ca3f6u,0x0c0ca3f8u,0x0c0ca3fau,0x0c0ca3fcu,0x0c0ca3feu,0x0c0ca400u,0x0c0ca402u,0x0c0ca404u,0x0c0ca406u,0x0c0ca408u,0x0c0ca40au,0x0c0ca40cu,0x0c0ca40eu,
0x0c0ca410u,0x0c0ca412u,0x0c0ca414u,0x0c0ca416u,0x0c0ca418u,0x0c0ca41au,0x0c0ca41cu,0x0c0ca41eu,0x0c0ca420u,0x0c0ca422u,0x0c0ca424u,0x0c0ca448u,0x0c0ca44au,0x0c0ca44cu,0x0c0ca44eu,0x0c0ca450u,
0x0c0ca452u,0x0c0ca454u,0x0c0ca456u,0x0c0ca458u,0x0c0ca45au,0x0c0ca45cu,0x0c0ca45eu,0x0c0ca460u,0x0c0ca462u,0x0c0ca464u,0x0c0ca466u,0x0c0ca468u,0x0c0ca46au,0x0c0ca46cu,0x0c0ca46eu,0x0c0ca470u,
0x0c0ca472u,0x0c0ca474u,0x0c0ca476u,0x0c0ca478u,0x0c0ca47au,0x0c0ca47cu,0x0c0ca47eu,0x0c0ca480u,0x0c0ca482u,0x0c0ca484u,0x0c0ca486u,0x0c0ca488u,0x0c0ca48au,0x0c0ca48cu,0x0c0ca48eu,0x0c0ca490u,
0x0c0ca492u,0x0c0ca494u,0x0c0ca496u,0x0c0ca498u,0x0c0ca49au,0x0c0ca49cu,0x0c0ca49eu,0x0c0ca4a0u,0x0c0ca4a2u,
};
int vf3_advance_leaf_ranked_more_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
