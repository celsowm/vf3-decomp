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
int vf3_away_batch216_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
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
case 0x0c091e4cu: goto P_0c091e4c;
case 0x0c091e4eu: goto P_0c091e4e;
case 0x0c091e50u: goto P_0c091e50;
case 0x0c091e52u: goto P_0c091e52;
case 0x0c091e54u: goto P_0c091e54;
case 0x0c091e56u: goto P_0c091e56;
case 0x0c091e58u: goto P_0c091e58;
case 0x0c091e5au: goto P_0c091e5a;
case 0x0c091e5cu: goto P_0c091e5c;
case 0x0c091e5eu: goto P_0c091e5e;
case 0x0c091e60u: goto P_0c091e60;
case 0x0c09553cu: goto P_0c09553c;
case 0x0c09553eu: goto P_0c09553e;
case 0x0c095540u: goto P_0c095540;
case 0x0c095542u: goto P_0c095542;
case 0x0c095544u: goto P_0c095544;
case 0x0c095546u: goto P_0c095546;
case 0x0c095548u: goto P_0c095548;
case 0x0c09554au: goto P_0c09554a;
case 0x0c09554cu: goto P_0c09554c;
case 0x0c09554eu: goto P_0c09554e;
case 0x0c095550u: goto P_0c095550;
case 0x0c095552u: goto P_0c095552;
case 0x0c095554u: goto P_0c095554;
case 0x0c095556u: goto P_0c095556;
case 0x0c095558u: goto P_0c095558;
case 0x0c09555au: goto P_0c09555a;
case 0x0c09555cu: goto P_0c09555c;
case 0x0c09555eu: goto P_0c09555e;
case 0x0c095560u: goto P_0c095560;
case 0x0c095562u: goto P_0c095562;
case 0x0c095564u: goto P_0c095564;
case 0x0c095566u: goto P_0c095566;
case 0x0c095568u: goto P_0c095568;
case 0x0c09556au: goto P_0c09556a;
case 0x0c09556cu: goto P_0c09556c;
case 0x0c09556eu: goto P_0c09556e;
case 0x0c095570u: goto P_0c095570;
case 0x0c095572u: goto P_0c095572;
case 0x0c095574u: goto P_0c095574;
case 0x0c095576u: goto P_0c095576;
case 0x0c095578u: goto P_0c095578;
case 0x0c09557au: goto P_0c09557a;
case 0x0c09557cu: goto P_0c09557c;
case 0x0c09557eu: goto P_0c09557e;
case 0x0c095580u: goto P_0c095580;
case 0x0c095582u: goto P_0c095582;
case 0x0c0ae29cu: goto P_0c0ae29c;
case 0x0c0ae29eu: goto P_0c0ae29e;
case 0x0c0ae2a0u: goto P_0c0ae2a0;
case 0x0c0ae2a2u: goto P_0c0ae2a2;
case 0x0c0ae2a4u: goto P_0c0ae2a4;
case 0x0c0ae2a6u: goto P_0c0ae2a6;
case 0x0c0ae2a8u: goto P_0c0ae2a8;
case 0x0c0ae2aau: goto P_0c0ae2aa;
case 0x0c0ae2acu: goto P_0c0ae2ac;
case 0x0c0ae2aeu: goto P_0c0ae2ae;
case 0x0c0ae2b0u: goto P_0c0ae2b0;
case 0x0c0ae2b2u: goto P_0c0ae2b2;
case 0x0c0ae2b4u: goto P_0c0ae2b4;
case 0x0c0ae2b6u: goto P_0c0ae2b6;
case 0x0c0ae2b8u: goto P_0c0ae2b8;
case 0x0c0ae2bau: goto P_0c0ae2ba;
case 0x0c0ae2bcu: goto P_0c0ae2bc;
case 0x0c0ae2beu: goto P_0c0ae2be;
case 0x0c0ae2c0u: goto P_0c0ae2c0;
case 0x0c0ae2c2u: goto P_0c0ae2c2;
case 0x0c0ae2c4u: goto P_0c0ae2c4;
case 0x0c0ae2c6u: goto P_0c0ae2c6;
case 0x0c0ae2c8u: goto P_0c0ae2c8;
case 0x0c0ae2cau: goto P_0c0ae2ca;
case 0x0c0ae2ccu: goto P_0c0ae2cc;
case 0x0c0ae2ceu: goto P_0c0ae2ce;
case 0x0c0ae2d0u: goto P_0c0ae2d0;
case 0x0c0ae2d2u: goto P_0c0ae2d2;
case 0x0c0ae2d4u: goto P_0c0ae2d4;
case 0x0c0ae2d6u: goto P_0c0ae2d6;
case 0x0c0ae2d8u: goto P_0c0ae2d8;
case 0x0c0ae2dau: goto P_0c0ae2da;
case 0x0c0aea5cu: goto P_0c0aea5c;
case 0x0c0aea5eu: goto P_0c0aea5e;
case 0x0c0aea60u: goto P_0c0aea60;
case 0x0c0aea62u: goto P_0c0aea62;
case 0x0c0aea64u: goto P_0c0aea64;
case 0x0c0aea66u: goto P_0c0aea66;
case 0x0c0aea68u: goto P_0c0aea68;
case 0x0c0aea6au: goto P_0c0aea6a;
case 0x0c0aea6cu: goto P_0c0aea6c;
case 0x0c0aea6eu: goto P_0c0aea6e;
case 0x0c0aea70u: goto P_0c0aea70;
case 0x0c0aea72u: goto P_0c0aea72;
case 0x0c0aea74u: goto P_0c0aea74;
case 0x0c0aea76u: goto P_0c0aea76;
case 0x0c0aea78u: goto P_0c0aea78;
case 0x0c0aea7au: goto P_0c0aea7a;
case 0x0c0aea7cu: goto P_0c0aea7c;
case 0x0c0aea7eu: goto P_0c0aea7e;
case 0x0c0aea80u: goto P_0c0aea80;
case 0x0c0aea82u: goto P_0c0aea82;
case 0x0c0aea84u: goto P_0c0aea84;
case 0x0c0aea86u: goto P_0c0aea86;
case 0x0c0aea88u: goto P_0c0aea88;
case 0x0c0aea8au: goto P_0c0aea8a;
case 0x0c0aea8cu: goto P_0c0aea8c;
case 0x0c0aea8eu: goto P_0c0aea8e;
case 0x0c0aea90u: goto P_0c0aea90;
case 0x0c0aea92u: goto P_0c0aea92;
case 0x0c0aea94u: goto P_0c0aea94;
case 0x0c0aea96u: goto P_0c0aea96;
case 0x0c0aea98u: goto P_0c0aea98;
case 0x0c0aea9au: goto P_0c0aea9a;
case 0x0c0aea9cu: goto P_0c0aea9c;
case 0x0c0aea9eu: goto P_0c0aea9e;
case 0x0c0aeaa0u: goto P_0c0aeaa0;
case 0x0c0aeaa2u: goto P_0c0aeaa2;
case 0x0c0aeaa4u: goto P_0c0aeaa4;
case 0x0c0aeaa6u: goto P_0c0aeaa6;
case 0x0c0aeaa8u: goto P_0c0aeaa8;
case 0x0c0aeaaau: goto P_0c0aeaaa;
case 0x0c0aeaacu: goto P_0c0aeaac;
case 0x0c0aeaaeu: goto P_0c0aeaae;
case 0x0c0aeab0u: goto P_0c0aeab0;
case 0x0c0aeab2u: goto P_0c0aeab2;
case 0x0c0aeab4u: goto P_0c0aeab4;
case 0x0c0aeab6u: goto P_0c0aeab6;
case 0x0c0aeab8u: goto P_0c0aeab8;
case 0x0c0aeabau: goto P_0c0aeaba;
case 0x0c0aeabcu: goto P_0c0aeabc;
case 0x0c0aeabeu: goto P_0c0aeabe;
case 0x0c0aeac0u: goto P_0c0aeac0;
case 0x0c0aeac2u: goto P_0c0aeac2;
case 0x0c0aeac4u: goto P_0c0aeac4;
case 0x0c0aeac6u: goto P_0c0aeac6;
case 0x0c0aeac8u: goto P_0c0aeac8;
case 0x0c0aeacau: goto P_0c0aeaca;
case 0x0c0aeaccu: goto P_0c0aeacc;
case 0x0c0aeaceu: goto P_0c0aeace;
case 0x0c0aead0u: goto P_0c0aead0;
case 0x0c0aead2u: goto P_0c0aead2;
case 0x0c0aead4u: goto P_0c0aead4;
case 0x0c0aead6u: goto P_0c0aead6;
case 0x0c0aead8u: goto P_0c0aead8;
case 0x0c0aeadau: goto P_0c0aeada;
case 0x0c0aeadcu: goto P_0c0aeadc;
case 0x0c0aeadeu: goto P_0c0aeade;
case 0x0c0aeae0u: goto P_0c0aeae0;
case 0x0c0aeb00u: goto P_0c0aeb00;
case 0x0c0aeb02u: goto P_0c0aeb02;
case 0x0c0aeb04u: goto P_0c0aeb04;
case 0x0c0aeb06u: goto P_0c0aeb06;
case 0x0c0aeb08u: goto P_0c0aeb08;
case 0x0c0aeb0au: goto P_0c0aeb0a;
case 0x0c0aeb0cu: goto P_0c0aeb0c;
case 0x0c0aeb0eu: goto P_0c0aeb0e;
case 0x0c0aeb10u: goto P_0c0aeb10;
case 0x0c0aeb12u: goto P_0c0aeb12;
case 0x0c0aeb14u: goto P_0c0aeb14;
case 0x0c0aeb16u: goto P_0c0aeb16;
case 0x0c0aeb18u: goto P_0c0aeb18;
case 0x0c0aeb1au: goto P_0c0aeb1a;
case 0x0c0aeb1cu: goto P_0c0aeb1c;
case 0x0c0aeb1eu: goto P_0c0aeb1e;
case 0x0c0aeb20u: goto P_0c0aeb20;
case 0x0c0aeb22u: goto P_0c0aeb22;
case 0x0c0aeb24u: goto P_0c0aeb24;
case 0x0c0aeb26u: goto P_0c0aeb26;
case 0x0c0aeb28u: goto P_0c0aeb28;
case 0x0c0aeb2au: goto P_0c0aeb2a;
case 0x0c0aeb2cu: goto P_0c0aeb2c;
case 0x0c0aeb2eu: goto P_0c0aeb2e;
case 0x0c0aeb30u: goto P_0c0aeb30;
case 0x0c0aeb32u: goto P_0c0aeb32;
case 0x0c0aeb34u: goto P_0c0aeb34;
case 0x0c0aeb36u: goto P_0c0aeb36;
case 0x0c0aeb38u: goto P_0c0aeb38;
case 0x0c0aeb3au: goto P_0c0aeb3a;
case 0x0c0aeb3cu: goto P_0c0aeb3c;
case 0x0c0aeb3eu: goto P_0c0aeb3e;
case 0x0c0aeb40u: goto P_0c0aeb40;
case 0x0c0aeb42u: goto P_0c0aeb42;
case 0x0c0aeb44u: goto P_0c0aeb44;
case 0x0c0aeb46u: goto P_0c0aeb46;
case 0x0c0aeb48u: goto P_0c0aeb48;
case 0x0c0aeb4au: goto P_0c0aeb4a;
case 0x0c0aeb74u: goto P_0c0aeb74;
case 0x0c0aeb76u: goto P_0c0aeb76;
case 0x0c0aeb78u: goto P_0c0aeb78;
case 0x0c0aeb7au: goto P_0c0aeb7a;
case 0x0c0aeb7cu: goto P_0c0aeb7c;
case 0x0c0aeb7eu: goto P_0c0aeb7e;
case 0x0c0aeb80u: goto P_0c0aeb80;
case 0x0c0aeb82u: goto P_0c0aeb82;
case 0x0c0aeb84u: goto P_0c0aeb84;
case 0x0c0aeb86u: goto P_0c0aeb86;
case 0x0c0aeb88u: goto P_0c0aeb88;
case 0x0c0aeb8au: goto P_0c0aeb8a;
case 0x0c0aeb8cu: goto P_0c0aeb8c;
case 0x0c0aeb8eu: goto P_0c0aeb8e;
case 0x0c0aeb90u: goto P_0c0aeb90;
case 0x0c0aeb92u: goto P_0c0aeb92;
case 0x0c0aeb94u: goto P_0c0aeb94;
case 0x0c0aeb96u: goto P_0c0aeb96;
case 0x0c0aeb98u: goto P_0c0aeb98;
case 0x0c0aeb9au: goto P_0c0aeb9a;
case 0x0c0aeb9cu: goto P_0c0aeb9c;
case 0x0c0aeb9eu: goto P_0c0aeb9e;
case 0x0c0aeba0u: goto P_0c0aeba0;
case 0x0c0aeba2u: goto P_0c0aeba2;
case 0x0c0aeba4u: goto P_0c0aeba4;
case 0x0c0aeba6u: goto P_0c0aeba6;
case 0x0c0aeba8u: goto P_0c0aeba8;
case 0x0c0aebaau: goto P_0c0aebaa;
case 0x0c0aebacu: goto P_0c0aebac;
case 0x0c0aebaeu: goto P_0c0aebae;
case 0x0c0aebb0u: goto P_0c0aebb0;
case 0x0c0aebb2u: goto P_0c0aebb2;
case 0x0c0aebb4u: goto P_0c0aebb4;
case 0x0c0aebb6u: goto P_0c0aebb6;
case 0x0c0aebb8u: goto P_0c0aebb8;
case 0x0c0aebbau: goto P_0c0aebba;
case 0x0c0aebbcu: goto P_0c0aebbc;
case 0x0c0aebbeu: goto P_0c0aebbe;
case 0x0c0aebc0u: goto P_0c0aebc0;
case 0x0c0aebc2u: goto P_0c0aebc2;
case 0x0c0aebc4u: goto P_0c0aebc4;
case 0x0c0aebc6u: goto P_0c0aebc6;
case 0x0c0aebc8u: goto P_0c0aebc8;
case 0x0c0aebcau: goto P_0c0aebca;
case 0x0c0aebccu: goto P_0c0aebcc;
case 0x0c0aebceu: goto P_0c0aebce;
case 0x0c0aebd0u: goto P_0c0aebd0;
case 0x0c0aebd2u: goto P_0c0aebd2;
case 0x0c0aebd4u: goto P_0c0aebd4;
case 0x0c0aebd6u: goto P_0c0aebd6;
case 0x0c0aebd8u: goto P_0c0aebd8;
case 0x0c0aebdau: goto P_0c0aebda;
case 0x0c0aebdcu: goto P_0c0aebdc;
case 0x0c0aebdeu: goto P_0c0aebde;
case 0x0c0aebe0u: goto P_0c0aebe0;
case 0x0c0aebe2u: goto P_0c0aebe2;
case 0x0c0aebe4u: goto P_0c0aebe4;
case 0x0c0aebe6u: goto P_0c0aebe6;
case 0x0c0aebe8u: goto P_0c0aebe8;
case 0x0c0aebeau: goto P_0c0aebea;
case 0x0c0aebecu: goto P_0c0aebec;
case 0x0c0aebeeu: goto P_0c0aebee;
case 0x0c0aebf0u: goto P_0c0aebf0;
case 0x0c0aebf2u: goto P_0c0aebf2;
case 0x0c0aebf4u: goto P_0c0aebf4;
case 0x0c0aebf6u: goto P_0c0aebf6;
case 0x0c0aebf8u: goto P_0c0aebf8;
case 0x0c0aebfau: goto P_0c0aebfa;
case 0x0c0aebfcu: goto P_0c0aebfc;
case 0x0c0aebfeu: goto P_0c0aebfe;
case 0x0c0aec00u: goto P_0c0aec00;
case 0x0c0aec02u: goto P_0c0aec02;
case 0x0c0aec04u: goto P_0c0aec04;
case 0x0c0aec06u: goto P_0c0aec06;
case 0x0c0aec08u: goto P_0c0aec08;
case 0x0c0aec0au: goto P_0c0aec0a;
case 0x0c0aec0cu: goto P_0c0aec0c;
case 0x0c0aec34u: goto P_0c0aec34;
case 0x0c0aec36u: goto P_0c0aec36;
case 0x0c0aec38u: goto P_0c0aec38;
case 0x0c0aec3au: goto P_0c0aec3a;
case 0x0c0aec3cu: goto P_0c0aec3c;
case 0x0c0aec3eu: goto P_0c0aec3e;
case 0x0c0aec40u: goto P_0c0aec40;
case 0x0c0aec42u: goto P_0c0aec42;
case 0x0c0aec44u: goto P_0c0aec44;
case 0x0c0aec46u: goto P_0c0aec46;
case 0x0c0aec48u: goto P_0c0aec48;
case 0x0c0aec4au: goto P_0c0aec4a;
case 0x0c0aec4cu: goto P_0c0aec4c;
case 0x0c0aec4eu: goto P_0c0aec4e;
case 0x0c0aec50u: goto P_0c0aec50;
case 0x0c0aec52u: goto P_0c0aec52;
case 0x0c0aec54u: goto P_0c0aec54;
case 0x0c0aec56u: goto P_0c0aec56;
case 0x0c0aec58u: goto P_0c0aec58;
case 0x0c0aec5au: goto P_0c0aec5a;
case 0x0c0aec5cu: goto P_0c0aec5c;
case 0x0c0aec5eu: goto P_0c0aec5e;
case 0x0c0aec60u: goto P_0c0aec60;
case 0x0c0aec62u: goto P_0c0aec62;
case 0x0c0aec64u: goto P_0c0aec64;
case 0x0c0aec66u: goto P_0c0aec66;
case 0x0c0aec68u: goto P_0c0aec68;
case 0x0c0aec6au: goto P_0c0aec6a;
case 0x0c0aec6cu: goto P_0c0aec6c;
case 0x0c0aec6eu: goto P_0c0aec6e;
case 0x0c0aec70u: goto P_0c0aec70;
case 0x0c0aec72u: goto P_0c0aec72;
case 0x0c0aec74u: goto P_0c0aec74;
case 0x0c0af728u: goto P_0c0af728;
case 0x0c0af72au: goto P_0c0af72a;
case 0x0c0af72cu: goto P_0c0af72c;
case 0x0c0af72eu: goto P_0c0af72e;
case 0x0c0af730u: goto P_0c0af730;
case 0x0c0af732u: goto P_0c0af732;
case 0x0c0af734u: goto P_0c0af734;
case 0x0c0af736u: goto P_0c0af736;
case 0x0c0af738u: goto P_0c0af738;
case 0x0c0af73au: goto P_0c0af73a;
case 0x0c0af73cu: goto P_0c0af73c;
case 0x0c0af73eu: goto P_0c0af73e;
case 0x0c0af740u: goto P_0c0af740;
case 0x0c0af742u: goto P_0c0af742;
case 0x0c0af744u: goto P_0c0af744;
case 0x0c0af746u: goto P_0c0af746;
case 0x0c0af748u: goto P_0c0af748;
case 0x0c0af74au: goto P_0c0af74a;
case 0x0c0af74cu: goto P_0c0af74c;
case 0x0c0af74eu: goto P_0c0af74e;
case 0x0c0af750u: goto P_0c0af750;
case 0x0c0af752u: goto P_0c0af752;
case 0x0c0af754u: goto P_0c0af754;
case 0x0c0af756u: goto P_0c0af756;
case 0x0c0af758u: goto P_0c0af758;
case 0x0c0af75au: goto P_0c0af75a;
case 0x0c0af75cu: goto P_0c0af75c;
case 0x0c0af75eu: goto P_0c0af75e;
case 0x0c0af760u: goto P_0c0af760;
case 0x0c0af762u: goto P_0c0af762;
case 0x0c0af764u: goto P_0c0af764;
case 0x0c0af766u: goto P_0c0af766;
case 0x0c0af768u: goto P_0c0af768;
case 0x0c0af76au: goto P_0c0af76a;
case 0x0c0af76cu: goto P_0c0af76c;
case 0x0c0af76eu: goto P_0c0af76e;
case 0x0c0af770u: goto P_0c0af770;
case 0x0c0af772u: goto P_0c0af772;
case 0x0c0af774u: goto P_0c0af774;
case 0x0c0af776u: goto P_0c0af776;
case 0x0c0af778u: goto P_0c0af778;
case 0x0c0af77au: goto P_0c0af77a;
case 0x0c0af77cu: goto P_0c0af77c;
case 0x0c0af77eu: goto P_0c0af77e;
case 0x0c0af780u: goto P_0c0af780;
case 0x0c0af782u: goto P_0c0af782;
case 0x0c0af784u: goto P_0c0af784;
case 0x0c0af786u: goto P_0c0af786;
case 0x0c0af788u: goto P_0c0af788;
case 0x0c0af78au: goto P_0c0af78a;
case 0x0c0af78cu: goto P_0c0af78c;
case 0x0c0af78eu: goto P_0c0af78e;
case 0x0c0af790u: goto P_0c0af790;
case 0x0c0af792u: goto P_0c0af792;
case 0x0c0af794u: goto P_0c0af794;
case 0x0c0af796u: goto P_0c0af796;
case 0x0c0af798u: goto P_0c0af798;
case 0x0c0af79au: goto P_0c0af79a;
case 0x0c0af79cu: goto P_0c0af79c;
case 0x0c0af79eu: goto P_0c0af79e;
case 0x0c0af7a0u: goto P_0c0af7a0;
case 0x0c0af7a2u: goto P_0c0af7a2;
case 0x0c0af7a4u: goto P_0c0af7a4;
case 0x0c0af7a6u: goto P_0c0af7a6;
case 0x0c0af7a8u: goto P_0c0af7a8;
case 0x0c0af7aau: goto P_0c0af7aa;
case 0x0c0af7acu: goto P_0c0af7ac;
case 0x0c0af7aeu: goto P_0c0af7ae;
case 0x0c0af7b0u: goto P_0c0af7b0;
case 0x0c0af7b2u: goto P_0c0af7b2;
case 0x0c0af7b4u: goto P_0c0af7b4;
case 0x0c0af7b6u: goto P_0c0af7b6;
case 0x0c0af7b8u: goto P_0c0af7b8;
case 0x0c0af7bau: goto P_0c0af7ba;
case 0x0c0af7bcu: goto P_0c0af7bc;
case 0x0c0af7beu: goto P_0c0af7be;
case 0x0c0af7c0u: goto P_0c0af7c0;
case 0x0c0af7c2u: goto P_0c0af7c2;
case 0x0c0af7c4u: goto P_0c0af7c4;
case 0x0c0af7c6u: goto P_0c0af7c6;
case 0x0c0af7c8u: goto P_0c0af7c8;
case 0x0c0af7cau: goto P_0c0af7ca;
case 0x0c0af7ccu: goto P_0c0af7cc;
case 0x0c0af7ceu: goto P_0c0af7ce;
case 0x0c0af7d0u: goto P_0c0af7d0;
case 0x0c0af7d2u: goto P_0c0af7d2;
case 0x0c0af7d4u: goto P_0c0af7d4;
case 0x0c0af7d6u: goto P_0c0af7d6;
case 0x0c0af7d8u: goto P_0c0af7d8;
case 0x0c0af7dau: goto P_0c0af7da;
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
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
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
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
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
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
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
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
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
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c091e4c: /* original 6653, guest PC 0x0c091e4c */
if(!s->budget--) { s->failed_pc=0x0c091e4cu; return 0; }
r[6]=r[5];
goto P_0c091e4e;
P_0c091e4e: /* original a003, guest PC 0x0c091e4e */
if(!s->budget--) { s->failed_pc=0x0c091e4eu; return 0; }
r[5]=0x0000001au;
goto P_0c091e58;
P_0c091e50: /* original e51a, guest PC 0x0c091e50 */
if(!s->budget--) { s->failed_pc=0x0c091e50u; return 0; }
r[5]=0x0000001au;
goto P_0c091e52;
P_0c091e52: /* original 6345, guest PC 0x0c091e52 */
if(!s->budget--) { s->failed_pc=0x0c091e52u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]+=2;
r[3]=tmp;
goto P_0c091e54;
P_0c091e54: /* original 2631, guest PC 0x0c091e54 */
if(!s->budget--) { s->failed_pc=0x0c091e54u; return 0; }
write(ram,r[6],r[3],2);
goto P_0c091e56;
P_0c091e56: /* original 7602, guest PC 0x0c091e56 */
if(!s->budget--) { s->failed_pc=0x0c091e56u; return 0; }
r[6]+=0x00000002u;
goto P_0c091e58;
P_0c091e58: /* original 4515, guest PC 0x0c091e58 */
if(!s->budget--) { s->failed_pc=0x0c091e58u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c091e5a;
P_0c091e5a: /* original 8dfa, guest PC 0x0c091e5a */
if(!s->budget--) { s->failed_pc=0x0c091e5au; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c091e52; }
goto P_0c091e5e;
P_0c091e5c: /* original 75ff, guest PC 0x0c091e5c */
if(!s->budget--) { s->failed_pc=0x0c091e5cu; return 0; }
r[5]+=0xffffffffu;
goto P_0c091e5e;
P_0c091e5e: /* original 000b, guest PC 0x0c091e5e */
if(!s->budget--) { s->failed_pc=0x0c091e5eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c091e60: /* original 0009, guest PC 0x0c091e60 */
if(!s->budget--) { s->failed_pc=0x0c091e60u; return 0; }
if(!vf3_matrix_family(0x0c091e62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091e62u; return 0; } return 1;
P_0c09553c: /* original fffb, guest PC 0x0c09553c */
if(!s->budget--) { s->failed_pc=0x0c09553cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09553e;
P_0c09553e: /* original 4f22, guest PC 0x0c09553e */
if(!s->budget--) { s->failed_pc=0x0c09553eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095540;
P_0c095540: /* original 7ff0, guest PC 0x0c095540 */
if(!s->budget--) { s->failed_pc=0x0c095540u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c095542;
P_0c095542: /* original 1f42, guest PC 0x0c095542 */
if(!s->budget--) { s->failed_pc=0x0c095542u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c095544;
P_0c095544: /* original 2f52, guest PC 0x0c095544 */
if(!s->budget--) { s->failed_pc=0x0c095544u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c095546;
P_0c095546: /* original 1f61, guest PC 0x0c095546 */
if(!s->budget--) { s->failed_pc=0x0c095546u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c095548;
P_0c095548: /* original 54f2, guest PC 0x0c095548 */
if(!s->budget--) { s->failed_pc=0x0c095548u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09554a;
P_0c09554a: /* original d369, guest PC 0x0c09554a */
if(!s->budget--) { s->failed_pc=0x0c09554au; return 0; }
r[3]=read(ram,0x0c0956f0u,4);
goto P_0c09554c;
P_0c09554c: /* original 644f, guest PC 0x0c09554c */
if(!s->budget--) { s->failed_pc=0x0c09554cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09554e;
P_0c09554e: /* original 430b, guest PC 0x0c09554e */
if(!s->budget--) { s->failed_pc=0x0c09554eu; return 0; }
target=r[3];
r[16]=code_base|0x0c095552u;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095552u) { target=s->pc; goto dispatch; }
goto P_0c095552;
P_0c095550: /* original 1f43, guest PC 0x0c095550 */
if(!s->budget--) { s->failed_pc=0x0c095550u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c095552;
P_0c095552: /* original d368, guest PC 0x0c095552 */
if(!s->budget--) { s->failed_pc=0x0c095552u; return 0; }
r[3]=read(ram,0x0c0956f4u,4);
goto P_0c095554;
P_0c095554: /* original ff0c, guest PC 0x0c095554 */
if(!s->budget--) { s->failed_pc=0x0c095554u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c095556;
P_0c095556: /* original 430b, guest PC 0x0c095556 */
if(!s->budget--) { s->failed_pc=0x0c095556u; return 0; }
target=r[3];
r[16]=code_base|0x0c09555au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09555au) { target=s->pc; goto dispatch; }
goto P_0c09555a;
P_0c095558: /* original 54f3, guest PC 0x0c095558 */
if(!s->budget--) { s->failed_pc=0x0c095558u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09555a;
P_0c09555a: /* original 62f2, guest PC 0x0c09555a */
if(!s->budget--) { s->failed_pc=0x0c09555au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09555c;
P_0c09555c: /* original f70c, guest PC 0x0c09555c */
if(!s->budget--) { s->failed_pc=0x0c09555cu; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c09555e;
P_0c09555e: /* original f628, guest PC 0x0c09555e */
if(!s->budget--) { s->failed_pc=0x0c09555eu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c095560;
P_0c095560: /* original 53f1, guest PC 0x0c095560 */
if(!s->budget--) { s->failed_pc=0x0c095560u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c095562;
P_0c095562: /* original f762, guest PC 0x0c095562 */
if(!s->budget--) { s->failed_pc=0x0c095562u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c095564;
P_0c095564: /* original f40c, guest PC 0x0c095564 */
if(!s->budget--) { s->failed_pc=0x0c095564u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c095566;
P_0c095566: /* original f538, guest PC 0x0c095566 */
if(!s->budget--) { s->failed_pc=0x0c095566u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c095568;
P_0c095568: /* original 6323, guest PC 0x0c095568 */
if(!s->budget--) { s->failed_pc=0x0c095568u; return 0; }
r[3]=r[2];
goto P_0c09556a;
P_0c09556a: /* original f05c, guest PC 0x0c09556a */
if(!s->budget--) { s->failed_pc=0x0c09556au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09556c;
P_0c09556c: /* original f452, guest PC 0x0c09556c */
if(!s->budget--) { s->failed_pc=0x0c09556cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09556e;
P_0c09556e: /* original f7fe, guest PC 0x0c09556e */
if(!s->budget--) { s->failed_pc=0x0c09556eu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[15],fr[7],r[18]);
goto P_0c095570;
P_0c095570: /* original ff62, guest PC 0x0c095570 */
if(!s->budget--) { s->failed_pc=0x0c095570u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c095572;
P_0c095572: /* original f57c, guest PC 0x0c095572 */
if(!s->budget--) { s->failed_pc=0x0c095572u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c095574;
P_0c095574: /* original f35a, guest PC 0x0c095574 */
if(!s->budget--) { s->failed_pc=0x0c095574u; return 0; }
vf3_matrix_store(s,ram,5,r[3]);
goto P_0c095576;
P_0c095576: /* original f4f1, guest PC 0x0c095576 */
if(!s->budget--) { s->failed_pc=0x0c095576u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c095578;
P_0c095578: /* original 53f1, guest PC 0x0c095578 */
if(!s->budget--) { s->failed_pc=0x0c095578u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09557a;
P_0c09557a: /* original 7f10, guest PC 0x0c09557a */
if(!s->budget--) { s->failed_pc=0x0c09557au; return 0; }
r[15]+=0x00000010u;
goto P_0c09557c;
P_0c09557c: /* original 4f26, guest PC 0x0c09557c */
if(!s->budget--) { s->failed_pc=0x0c09557cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09557e;
P_0c09557e: /* original f34a, guest PC 0x0c09557e */
if(!s->budget--) { s->failed_pc=0x0c09557eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c095580;
P_0c095580: /* original 000b, guest PC 0x0c095580 */
if(!s->budget--) { s->failed_pc=0x0c095580u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c095582: /* original fff9, guest PC 0x0c095582 */
if(!s->budget--) { s->failed_pc=0x0c095582u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c095584u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095584u; return 0; } return 1;
P_0c0ae29c: /* original 5762, guest PC 0x0c0ae29c */
if(!s->budget--) { s->failed_pc=0x0c0ae29cu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae29e;
P_0c0ae29e: /* original 7ffc, guest PC 0x0c0ae29e */
if(!s->budget--) { s->failed_pc=0x0c0ae29eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae2a0;
P_0c0ae2a0: /* original 6770, guest PC 0x0c0ae2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0ae2a2;
P_0c0ae2a2: /* original 677c, guest PC 0x0c0ae2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae2a4;
P_0c0ae2a4: /* original 2778, guest PC 0x0c0ae2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0ae2a6;
P_0c0ae2a6: /* original 8910, guest PC 0x0c0ae2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2ca; }
goto P_0c0ae2a8;
P_0c0ae2a8: /* original 5362, guest PC 0x0c0ae2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a8u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2aa;
P_0c0ae2aa: /* original 2f32, guest PC 0x0c0ae2aa */
if(!s->budget--) { s->failed_pc=0x0c0ae2aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae2ac;
P_0c0ae2ac: /* original 62f2, guest PC 0x0c0ae2ac */
if(!s->budget--) { s->failed_pc=0x0c0ae2acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ae2ae;
P_0c0ae2ae: /* original 8432, guest PC 0x0c0ae2ae */
if(!s->budget--) { s->failed_pc=0x0c0ae2aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0ae2b0;
P_0c0ae2b0: /* original 7201, guest PC 0x0c0ae2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae2b2;
P_0c0ae2b2: /* original d315, guest PC 0x0c0ae2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b2u; return 0; }
r[3]=read(ram,0x0c0ae308u,4);
goto P_0c0ae2b4;
P_0c0ae2b4: /* original 600c, guest PC 0x0c0ae2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae2b6;
P_0c0ae2b6: /* original 6220, guest PC 0x0c0ae2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0ae2b8;
P_0c0ae2b8: /* original 4018, guest PC 0x0c0ae2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b8u; return 0; }
r[0]<<=8;
goto P_0c0ae2ba;
P_0c0ae2ba: /* original 622c, guest PC 0x0c0ae2ba */
if(!s->budget--) { s->failed_pc=0x0c0ae2bau; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae2bc;
P_0c0ae2bc: /* original 2039, guest PC 0x0c0ae2bc */
if(!s->budget--) { s->failed_pc=0x0c0ae2bcu; return 0; }
r[0]&=r[3];
goto P_0c0ae2be;
P_0c0ae2be: /* original 202b, guest PC 0x0c0ae2be */
if(!s->budget--) { s->failed_pc=0x0c0ae2beu; return 0; }
r[0]|=r[2];
goto P_0c0ae2c0;
P_0c0ae2c0: /* original 6103, guest PC 0x0c0ae2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c0u; return 0; }
r[1]=r[0];
goto P_0c0ae2c2;
P_0c0ae2c2: /* original 1601, guest PC 0x0c0ae2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c2u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0ae2c4;
P_0c0ae2c4: /* original 6262, guest PC 0x0c0ae2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c4u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae2c6;
P_0c0ae2c6: /* original 3212, guest PC 0x0c0ae2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c0ae2c8;
P_0c0ae2c8: /* original 8902, guest PC 0x0c0ae2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2d0; }
goto P_0c0ae2ca;
P_0c0ae2ca: /* original d310, guest PC 0x0c0ae2ca */
if(!s->budget--) { s->failed_pc=0x0c0ae2cau; return 0; }
r[3]=read(ram,0x0c0ae30cu,4);
goto P_0c0ae2cc;
P_0c0ae2cc: /* original 432b, guest PC 0x0c0ae2cc */
if(!s->budget--) { s->failed_pc=0x0c0ae2ccu; return 0; }
target=r[3];
r[15]+=0x00000004u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0af728u: goto P_0c0af728;
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
P_0c0ae2ce: /* original 7f04, guest PC 0x0c0ae2ce */
if(!s->budget--) { s->failed_pc=0x0c0ae2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae2d0;
P_0c0ae2d0: /* original d00f, guest PC 0x0c0ae2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d0u; return 0; }
r[0]=read(ram,0x0c0ae310u,4);
goto P_0c0ae2d2;
P_0c0ae2d2: /* original 4708, guest PC 0x0c0ae2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d2u; return 0; }
r[7]<<=2;
goto P_0c0ae2d4;
P_0c0ae2d4: /* original 027e, guest PC 0x0c0ae2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d4u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c0ae2d6;
P_0c0ae2d6: /* original 2f22, guest PC 0x0c0ae2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae2d8;
P_0c0ae2d8: /* original 422b, guest PC 0x0c0ae2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ae2da: /* original 7f04, guest PC 0x0c0ae2da */
if(!s->budget--) { s->failed_pc=0x0c0ae2dau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ae2dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae2dcu; return 0; } return 1;
P_0c0aea5c: /* original 2fe6, guest PC 0x0c0aea5c */
if(!s->budget--) { s->failed_pc=0x0c0aea5cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aea5e;
P_0c0aea5e: /* original 6e43, guest PC 0x0c0aea5e */
if(!s->budget--) { s->failed_pc=0x0c0aea5eu; return 0; }
r[14]=r[4];
goto P_0c0aea60;
P_0c0aea60: /* original 2fd6, guest PC 0x0c0aea60 */
if(!s->budget--) { s->failed_pc=0x0c0aea60u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aea62;
P_0c0aea62: /* original 6d63, guest PC 0x0c0aea62 */
if(!s->budget--) { s->failed_pc=0x0c0aea62u; return 0; }
r[13]=r[6];
goto P_0c0aea64;
P_0c0aea64: /* original 2fc6, guest PC 0x0c0aea64 */
if(!s->budget--) { s->failed_pc=0x0c0aea64u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aea66;
P_0c0aea66: /* original e054, guest PC 0x0c0aea66 */
if(!s->budget--) { s->failed_pc=0x0c0aea66u; return 0; }
r[0]=0x00000054u;
goto P_0c0aea68;
P_0c0aea68: /* original 4f22, guest PC 0x0c0aea68 */
if(!s->budget--) { s->failed_pc=0x0c0aea68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aea6a;
P_0c0aea6a: /* original 7ffc, guest PC 0x0c0aea6a */
if(!s->budget--) { s->failed_pc=0x0c0aea6au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aea6c;
P_0c0aea6c: /* original 2f52, guest PC 0x0c0aea6c */
if(!s->budget--) { s->failed_pc=0x0c0aea6cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aea6e;
P_0c0aea6e: /* original 54d2, guest PC 0x0c0aea6e */
if(!s->budget--) { s->failed_pc=0x0c0aea6eu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0aea70;
P_0c0aea70: /* original 05ee, guest PC 0x0c0aea70 */
if(!s->budget--) { s->failed_pc=0x0c0aea70u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aea72;
P_0c0aea72: /* original 7403, guest PC 0x0c0aea72 */
if(!s->budget--) { s->failed_pc=0x0c0aea72u; return 0; }
r[4]+=0x00000003u;
goto P_0c0aea74;
P_0c0aea74: /* original dc1b, guest PC 0x0c0aea74 */
if(!s->budget--) { s->failed_pc=0x0c0aea74u; return 0; }
r[12]=read(ram,0x0c0aeae4u,4);
goto P_0c0aea76;
P_0c0aea76: /* original 6440, guest PC 0x0c0aea76 */
if(!s->budget--) { s->failed_pc=0x0c0aea76u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0aea78;
P_0c0aea78: /* original 644c, guest PC 0x0c0aea78 */
if(!s->budget--) { s->failed_pc=0x0c0aea78u; return 0; }
r[4]=r[4]&255u;
goto P_0c0aea7a;
P_0c0aea7a: /* original 6043, guest PC 0x0c0aea7a */
if(!s->budget--) { s->failed_pc=0x0c0aea7au; return 0; }
r[0]=r[4];
goto P_0c0aea7c;
P_0c0aea7c: /* original 880a, guest PC 0x0c0aea7c */
if(!s->budget--) { s->failed_pc=0x0c0aea7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0aea7e;
P_0c0aea7e: /* original 891c, guest PC 0x0c0aea7e */
if(!s->budget--) { s->failed_pc=0x0c0aea7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aeaba; }
goto P_0c0aea80;
P_0c0aea80: /* original 6043, guest PC 0x0c0aea80 */
if(!s->budget--) { s->failed_pc=0x0c0aea80u; return 0; }
r[0]=r[4];
goto P_0c0aea82;
P_0c0aea82: /* original 880b, guest PC 0x0c0aea82 */
if(!s->budget--) { s->failed_pc=0x0c0aea82u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0aea84;
P_0c0aea84: /* original 891f, guest PC 0x0c0aea84 */
if(!s->budget--) { s->failed_pc=0x0c0aea84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aeac6; }
goto P_0c0aea86;
P_0c0aea86: /* original 6043, guest PC 0x0c0aea86 */
if(!s->budget--) { s->failed_pc=0x0c0aea86u; return 0; }
r[0]=r[4];
goto P_0c0aea88;
P_0c0aea88: /* original 880c, guest PC 0x0c0aea88 */
if(!s->budget--) { s->failed_pc=0x0c0aea88u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0aea8a;
P_0c0aea8a: /* original 8923, guest PC 0x0c0aea8a */
if(!s->budget--) { s->failed_pc=0x0c0aea8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aead4; }
goto P_0c0aea8c;
P_0c0aea8c: /* original 6043, guest PC 0x0c0aea8c */
if(!s->budget--) { s->failed_pc=0x0c0aea8cu; return 0; }
r[0]=r[4];
goto P_0c0aea8e;
P_0c0aea8e: /* original 880d, guest PC 0x0c0aea8e */
if(!s->budget--) { s->failed_pc=0x0c0aea8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0aea90;
P_0c0aea90: /* original 8936, guest PC 0x0c0aea90 */
if(!s->budget--) { s->failed_pc=0x0c0aea90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aeb00; }
goto P_0c0aea92;
P_0c0aea92: /* original 6043, guest PC 0x0c0aea92 */
if(!s->budget--) { s->failed_pc=0x0c0aea92u; return 0; }
r[0]=r[4];
goto P_0c0aea94;
P_0c0aea94: /* original 8808, guest PC 0x0c0aea94 */
if(!s->budget--) { s->failed_pc=0x0c0aea94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0aea96;
P_0c0aea96: /* original 8b0d, guest PC 0x0c0aea96 */
if(!s->budget--) { s->failed_pc=0x0c0aea96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeab4; }
goto P_0c0aea98;
P_0c0aea98: /* original 6453, guest PC 0x0c0aea98 */
if(!s->budget--) { s->failed_pc=0x0c0aea98u; return 0; }
r[4]=r[5];
goto P_0c0aea9a;
P_0c0aea9a: /* original 7428, guest PC 0x0c0aea9a */
if(!s->budget--) { s->failed_pc=0x0c0aea9au; return 0; }
r[4]+=0x00000028u;
goto P_0c0aea9c;
P_0c0aea9c: /* original 8441, guest PC 0x0c0aea9c */
if(!s->budget--) { s->failed_pc=0x0c0aea9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0aea9e;
P_0c0aea9e: /* original d416, guest PC 0x0c0aea9e */
if(!s->budget--) { s->failed_pc=0x0c0aea9eu; return 0; }
r[4]=read(ram,0x0c0aeaf8u,4);
goto P_0c0aeaa0;
P_0c0aeaa0: /* original 600c, guest PC 0x0c0aeaa0 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeaa2;
P_0c0aeaa2: /* original 4018, guest PC 0x0c0aeaa2 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa2u; return 0; }
r[0]<<=8;
goto P_0c0aeaa4;
P_0c0aeaa4: /* original 2409, guest PC 0x0c0aeaa4 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa4u; return 0; }
r[4]&=r[0];
goto P_0c0aeaa6;
P_0c0aeaa6: /* original e028, guest PC 0x0c0aeaa6 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa6u; return 0; }
r[0]=0x00000028u;
goto P_0c0aeaa8;
P_0c0aeaa8: /* original 035c, guest PC 0x0c0aeaa8 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0aeaaa;
P_0c0aeaaa: /* original 633c, guest PC 0x0c0aeaaa */
if(!s->budget--) { s->failed_pc=0x0c0aeaaau; return 0; }
r[3]=r[3]&255u;
goto P_0c0aeaac;
P_0c0aeaac: /* original 243b, guest PC 0x0c0aeaac */
if(!s->budget--) { s->failed_pc=0x0c0aeaacu; return 0; }
r[4]|=r[3];
goto P_0c0aeaae;
P_0c0aeaae: /* original 6043, guest PC 0x0c0aeaae */
if(!s->budget--) { s->failed_pc=0x0c0aeaaeu; return 0; }
r[0]=r[4];
goto P_0c0aeab0;
P_0c0aeab0: /* original 88ff, guest PC 0x0c0aeab0 */
if(!s->budget--) { s->failed_pc=0x0c0aeab0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0aeab2;
P_0c0aeab2: /* original 8b39, guest PC 0x0c0aeab2 */
if(!s->budget--) { s->failed_pc=0x0c0aeab2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeb28; }
goto P_0c0aeab4;
P_0c0aeab4: /* original e022, guest PC 0x0c0aeab4 */
if(!s->budget--) { s->failed_pc=0x0c0aeab4u; return 0; }
r[0]=0x00000022u;
goto P_0c0aeab6;
P_0c0aeab6: /* original a037, guest PC 0x0c0aeab6 */
if(!s->budget--) { s->failed_pc=0x0c0aeab6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeb28;
P_0c0aeab8: /* original 045d, guest PC 0x0c0aeab8 */
if(!s->budget--) { s->failed_pc=0x0c0aeab8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeaba;
P_0c0aeaba: /* original d210, guest PC 0x0c0aeaba */
if(!s->budget--) { s->failed_pc=0x0c0aeabau; return 0; }
r[2]=read(ram,0x0c0aeafcu,4);
goto P_0c0aeabc;
P_0c0aeabc: /* original 420b, guest PC 0x0c0aeabc */
if(!s->budget--) { s->failed_pc=0x0c0aeabcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0aeac0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aeac0u) { target=s->pc; goto dispatch; }
goto P_0c0aeac0;
P_0c0aeabe: /* original 64e3, guest PC 0x0c0aeabe */
if(!s->budget--) { s->failed_pc=0x0c0aeabeu; return 0; }
r[4]=r[14];
goto P_0c0aeac0;
P_0c0aeac0: /* original 6503, guest PC 0x0c0aeac0 */
if(!s->budget--) { s->failed_pc=0x0c0aeac0u; return 0; }
r[5]=r[0];
goto P_0c0aeac2;
P_0c0aeac2: /* original a005, guest PC 0x0c0aeac2 */
if(!s->budget--) { s->failed_pc=0x0c0aeac2u; return 0; }
r[0]=0x0000002au;
goto P_0c0aead0;
P_0c0aeac4: /* original e02a, guest PC 0x0c0aeac4 */
if(!s->budget--) { s->failed_pc=0x0c0aeac4u; return 0; }
r[0]=0x0000002au;
goto P_0c0aeac6;
P_0c0aeac6: /* original d20d, guest PC 0x0c0aeac6 */
if(!s->budget--) { s->failed_pc=0x0c0aeac6u; return 0; }
r[2]=read(ram,0x0c0aeafcu,4);
goto P_0c0aeac8;
P_0c0aeac8: /* original 420b, guest PC 0x0c0aeac8 */
if(!s->budget--) { s->failed_pc=0x0c0aeac8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aeaccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aeaccu) { target=s->pc; goto dispatch; }
goto P_0c0aeacc;
P_0c0aeaca: /* original 64e3, guest PC 0x0c0aeaca */
if(!s->budget--) { s->failed_pc=0x0c0aeacau; return 0; }
r[4]=r[14];
goto P_0c0aeacc;
P_0c0aeacc: /* original 6503, guest PC 0x0c0aeacc */
if(!s->budget--) { s->failed_pc=0x0c0aeaccu; return 0; }
r[5]=r[0];
goto P_0c0aeace;
P_0c0aeace: /* original e02c, guest PC 0x0c0aeace */
if(!s->budget--) { s->failed_pc=0x0c0aeaceu; return 0; }
r[0]=0x0000002cu;
goto P_0c0aead0;
P_0c0aead0: /* original a01c, guest PC 0x0c0aead0 */
if(!s->budget--) { s->failed_pc=0x0c0aead0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeb0c;
P_0c0aead2: /* original 045d, guest PC 0x0c0aead2 */
if(!s->budget--) { s->failed_pc=0x0c0aead2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aead4;
P_0c0aead4: /* original d309, guest PC 0x0c0aead4 */
if(!s->budget--) { s->failed_pc=0x0c0aead4u; return 0; }
r[3]=read(ram,0x0c0aeafcu,4);
goto P_0c0aead6;
P_0c0aead6: /* original 430b, guest PC 0x0c0aead6 */
if(!s->budget--) { s->failed_pc=0x0c0aead6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aeadau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aeadau) { target=s->pc; goto dispatch; }
goto P_0c0aeada;
P_0c0aead8: /* original 64e3, guest PC 0x0c0aead8 */
if(!s->budget--) { s->failed_pc=0x0c0aead8u; return 0; }
r[4]=r[14];
goto P_0c0aeada;
P_0c0aeada: /* original 6503, guest PC 0x0c0aeada */
if(!s->budget--) { s->failed_pc=0x0c0aeadau; return 0; }
r[5]=r[0];
goto P_0c0aeadc;
P_0c0aeadc: /* original e02e, guest PC 0x0c0aeadc */
if(!s->budget--) { s->failed_pc=0x0c0aeadcu; return 0; }
r[0]=0x0000002eu;
goto P_0c0aeade;
P_0c0aeade: /* original a015, guest PC 0x0c0aeade */
if(!s->budget--) { s->failed_pc=0x0c0aeadeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeb0c;
P_0c0aeae0: /* original 045d, guest PC 0x0c0aeae0 */
if(!s->budget--) { s->failed_pc=0x0c0aeae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
if(!vf3_matrix_family(0x0c0aeae2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aeae2u; return 0; } return 1;
P_0c0aeb00: /* original d245, guest PC 0x0c0aeb00 */
if(!s->budget--) { s->failed_pc=0x0c0aeb00u; return 0; }
r[2]=read(ram,0x0c0aec18u,4);
goto P_0c0aeb02;
P_0c0aeb02: /* original 420b, guest PC 0x0c0aeb02 */
if(!s->budget--) { s->failed_pc=0x0c0aeb02u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aeb06u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aeb06u) { target=s->pc; goto dispatch; }
goto P_0c0aeb06;
P_0c0aeb04: /* original 64e3, guest PC 0x0c0aeb04 */
if(!s->budget--) { s->failed_pc=0x0c0aeb04u; return 0; }
r[4]=r[14];
goto P_0c0aeb06;
P_0c0aeb06: /* original 6503, guest PC 0x0c0aeb06 */
if(!s->budget--) { s->failed_pc=0x0c0aeb06u; return 0; }
r[5]=r[0];
goto P_0c0aeb08;
P_0c0aeb08: /* original e030, guest PC 0x0c0aeb08 */
if(!s->budget--) { s->failed_pc=0x0c0aeb08u; return 0; }
r[0]=0x00000030u;
goto P_0c0aeb0a;
P_0c0aeb0a: /* original 045d, guest PC 0x0c0aeb0a */
if(!s->budget--) { s->failed_pc=0x0c0aeb0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeb0c;
P_0c0aeb0c: /* original e054, guest PC 0x0c0aeb0c */
if(!s->budget--) { s->failed_pc=0x0c0aeb0cu; return 0; }
r[0]=0x00000054u;
goto P_0c0aeb0e;
P_0c0aeb0e: /* original 05ee, guest PC 0x0c0aeb0e */
if(!s->budget--) { s->failed_pc=0x0c0aeb0eu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aeb10;
P_0c0aeb10: /* original 7044, guest PC 0x0c0aeb10 */
if(!s->budget--) { s->failed_pc=0x0c0aeb10u; return 0; }
r[0]+=0x00000044u;
goto P_0c0aeb12;
P_0c0aeb12: /* original 07ce, guest PC 0x0c0aeb12 */
if(!s->budget--) { s->failed_pc=0x0c0aeb12u; return 0; }
r[7]=read(ram,r[12]+r[0],4);
goto P_0c0aeb14;
P_0c0aeb14: /* original e061, guest PC 0x0c0aeb14 */
if(!s->budget--) { s->failed_pc=0x0c0aeb14u; return 0; }
r[0]=0x00000061u;
goto P_0c0aeb16;
P_0c0aeb16: /* original 06ec, guest PC 0x0c0aeb16 */
if(!s->budget--) { s->failed_pc=0x0c0aeb16u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0aeb18;
P_0c0aeb18: /* original 606c, guest PC 0x0c0aeb18 */
if(!s->budget--) { s->failed_pc=0x0c0aeb18u; return 0; }
r[0]=r[6]&255u;
goto P_0c0aeb1a;
P_0c0aeb1a: /* original 8803, guest PC 0x0c0aeb1a */
if(!s->budget--) { s->failed_pc=0x0c0aeb1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0aeb1c;
P_0c0aeb1c: /* original 8f04, guest PC 0x0c0aeb1c */
if(!s->budget--) { s->failed_pc=0x0c0aeb1cu; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(!cond) { goto P_0c0aeb28; }
goto P_0c0aeb20;
P_0c0aeb1e: /* original 6603, guest PC 0x0c0aeb1e */
if(!s->budget--) { s->failed_pc=0x0c0aeb1eu; return 0; }
r[6]=r[0];
goto P_0c0aeb20;
P_0c0aeb20: /* original d33e, guest PC 0x0c0aeb20 */
if(!s->budget--) { s->failed_pc=0x0c0aeb20u; return 0; }
r[3]=read(ram,0x0c0aec1cu,4);
goto P_0c0aeb22;
P_0c0aeb22: /* original 476c, guest PC 0x0c0aeb22 */
if(!s->budget--) { s->failed_pc=0x0c0aeb22u; return 0; }
r[7]=(r[6]&0x80000000u)?((r[6]&31u)?(uint32_t)((int32_t)r[7]>>((-r[6])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[6]&31u);
goto P_0c0aeb24;
P_0c0aeb24: /* original 2738, guest PC 0x0c0aeb24 */
if(!s->budget--) { s->failed_pc=0x0c0aeb24u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0aeb26;
P_0c0aeb26: /* original 8bc5, guest PC 0x0c0aeb26 */
if(!s->budget--) { s->failed_pc=0x0c0aeb26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeab4; }
goto P_0c0aeb28;
P_0c0aeb28: /* original 9071, guest PC 0x0c0aeb28 */
if(!s->budget--) { s->failed_pc=0x0c0aeb28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aec0eu,2);
goto P_0c0aeb2a;
P_0c0aeb2a: /* original 02ce, guest PC 0x0c0aeb2a */
if(!s->budget--) { s->failed_pc=0x0c0aeb2au; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0aeb2c;
P_0c0aeb2c: /* original 2228, guest PC 0x0c0aeb2c */
if(!s->budget--) { s->failed_pc=0x0c0aeb2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0aeb2e;
P_0c0aeb2e: /* original 8b01, guest PC 0x0c0aeb2e */
if(!s->budget--) { s->failed_pc=0x0c0aeb2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeb34; }
goto P_0c0aeb30;
P_0c0aeb30: /* original 906e, guest PC 0x0c0aeb30 */
if(!s->budget--) { s->failed_pc=0x0c0aeb30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aec10u,2);
goto P_0c0aeb32;
P_0c0aeb32: /* original 0e45, guest PC 0x0c0aeb32 */
if(!s->budget--) { s->failed_pc=0x0c0aeb32u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0aeb34;
P_0c0aeb34: /* original 53d2, guest PC 0x0c0aeb34 */
if(!s->budget--) { s->failed_pc=0x0c0aeb34u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aeb36;
P_0c0aeb36: /* original 66d3, guest PC 0x0c0aeb36 */
if(!s->budget--) { s->failed_pc=0x0c0aeb36u; return 0; }
r[6]=r[13];
goto P_0c0aeb38;
P_0c0aeb38: /* original 64e3, guest PC 0x0c0aeb38 */
if(!s->budget--) { s->failed_pc=0x0c0aeb38u; return 0; }
r[4]=r[14];
goto P_0c0aeb3a;
P_0c0aeb3a: /* original 7304, guest PC 0x0c0aeb3a */
if(!s->budget--) { s->failed_pc=0x0c0aeb3au; return 0; }
r[3]+=0x00000004u;
goto P_0c0aeb3c;
P_0c0aeb3c: /* original 1d32, guest PC 0x0c0aeb3c */
if(!s->budget--) { s->failed_pc=0x0c0aeb3cu; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0aeb3e;
P_0c0aeb3e: /* original 65f2, guest PC 0x0c0aeb3e */
if(!s->budget--) { s->failed_pc=0x0c0aeb3eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aeb40;
P_0c0aeb40: /* original 7f04, guest PC 0x0c0aeb40 */
if(!s->budget--) { s->failed_pc=0x0c0aeb40u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aeb42;
P_0c0aeb42: /* original 4f26, guest PC 0x0c0aeb42 */
if(!s->budget--) { s->failed_pc=0x0c0aeb42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aeb44;
P_0c0aeb44: /* original 6cf6, guest PC 0x0c0aeb44 */
if(!s->budget--) { s->failed_pc=0x0c0aeb44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aeb46;
P_0c0aeb46: /* original 6df6, guest PC 0x0c0aeb46 */
if(!s->budget--) { s->failed_pc=0x0c0aeb46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aeb48;
P_0c0aeb48: /* original aba8, guest PC 0x0c0aeb48 */
if(!s->budget--) { s->failed_pc=0x0c0aeb48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae29c;
P_0c0aeb4a: /* original 6ef6, guest PC 0x0c0aeb4a */
if(!s->budget--) { s->failed_pc=0x0c0aeb4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aeb4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aeb4cu; return 0; } return 1;
P_0c0aeb74: /* original 2fe6, guest PC 0x0c0aeb74 */
if(!s->budget--) { s->failed_pc=0x0c0aeb74u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aeb76;
P_0c0aeb76: /* original 2fd6, guest PC 0x0c0aeb76 */
if(!s->budget--) { s->failed_pc=0x0c0aeb76u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aeb78;
P_0c0aeb78: /* original 2fc6, guest PC 0x0c0aeb78 */
if(!s->budget--) { s->failed_pc=0x0c0aeb78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aeb7a;
P_0c0aeb7a: /* original 6c43, guest PC 0x0c0aeb7a */
if(!s->budget--) { s->failed_pc=0x0c0aeb7au; return 0; }
r[12]=r[4];
goto P_0c0aeb7c;
P_0c0aeb7c: /* original 2fb6, guest PC 0x0c0aeb7c */
if(!s->budget--) { s->failed_pc=0x0c0aeb7cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aeb7e;
P_0c0aeb7e: /* original 6b63, guest PC 0x0c0aeb7e */
if(!s->budget--) { s->failed_pc=0x0c0aeb7eu; return 0; }
r[11]=r[6];
goto P_0c0aeb80;
P_0c0aeb80: /* original 4f22, guest PC 0x0c0aeb80 */
if(!s->budget--) { s->failed_pc=0x0c0aeb80u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aeb82;
P_0c0aeb82: /* original 7ff4, guest PC 0x0c0aeb82 */
if(!s->budget--) { s->failed_pc=0x0c0aeb82u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0aeb84;
P_0c0aeb84: /* original 1f51, guest PC 0x0c0aeb84 */
if(!s->budget--) { s->failed_pc=0x0c0aeb84u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0aeb86;
P_0c0aeb86: /* original 54b2, guest PC 0x0c0aeb86 */
if(!s->budget--) { s->failed_pc=0x0c0aeb86u; return 0; }
r[4]=read(ram,r[11]+8,4);
goto P_0c0aeb88;
P_0c0aeb88: /* original d325, guest PC 0x0c0aeb88 */
if(!s->budget--) { s->failed_pc=0x0c0aeb88u; return 0; }
r[3]=read(ram,0x0c0aec20u,4);
goto P_0c0aeb8a;
P_0c0aeb8a: /* original 8443, guest PC 0x0c0aeb8a */
if(!s->budget--) { s->failed_pc=0x0c0aeb8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0aeb8c;
P_0c0aeb8c: /* original 650c, guest PC 0x0c0aeb8c */
if(!s->budget--) { s->failed_pc=0x0c0aeb8cu; return 0; }
r[5]=r[0]&255u;
goto P_0c0aeb8e;
P_0c0aeb8e: /* original 8444, guest PC 0x0c0aeb8e */
if(!s->budget--) { s->failed_pc=0x0c0aeb8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0aeb90;
P_0c0aeb90: /* original 2558, guest PC 0x0c0aeb90 */
if(!s->budget--) { s->failed_pc=0x0c0aeb90u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0aeb92;
P_0c0aeb92: /* original 6d0c, guest PC 0x0c0aeb92 */
if(!s->budget--) { s->failed_pc=0x0c0aeb92u; return 0; }
r[13]=r[0]&255u;
goto P_0c0aeb94;
P_0c0aeb94: /* original 8446, guest PC 0x0c0aeb94 */
if(!s->budget--) { s->failed_pc=0x0c0aeb94u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0aeb96;
P_0c0aeb96: /* original 600c, guest PC 0x0c0aeb96 */
if(!s->budget--) { s->failed_pc=0x0c0aeb96u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeb98;
P_0c0aeb98: /* original 4018, guest PC 0x0c0aeb98 */
if(!s->budget--) { s->failed_pc=0x0c0aeb98u; return 0; }
r[0]<<=8;
goto P_0c0aeb9a;
P_0c0aeb9a: /* original 2039, guest PC 0x0c0aeb9a */
if(!s->budget--) { s->failed_pc=0x0c0aeb9au; return 0; }
r[0]&=r[3];
goto P_0c0aeb9c;
P_0c0aeb9c: /* original 6203, guest PC 0x0c0aeb9c */
if(!s->budget--) { s->failed_pc=0x0c0aeb9cu; return 0; }
r[2]=r[0];
goto P_0c0aeb9e;
P_0c0aeb9e: /* original 8445, guest PC 0x0c0aeb9e */
if(!s->budget--) { s->failed_pc=0x0c0aeb9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c0aeba0;
P_0c0aeba0: /* original 600c, guest PC 0x0c0aeba0 */
if(!s->budget--) { s->failed_pc=0x0c0aeba0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeba2;
P_0c0aeba2: /* original 220b, guest PC 0x0c0aeba2 */
if(!s->budget--) { s->failed_pc=0x0c0aeba2u; return 0; }
r[2]|=r[0];
goto P_0c0aeba4;
P_0c0aeba4: /* original 2f22, guest PC 0x0c0aeba4 */
if(!s->budget--) { s->failed_pc=0x0c0aeba4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aeba6;
P_0c0aeba6: /* original 64c2, guest PC 0x0c0aeba6 */
if(!s->budget--) { s->failed_pc=0x0c0aeba6u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0aeba8;
P_0c0aeba8: /* original 9e33, guest PC 0x0c0aeba8 */
if(!s->budget--) { s->failed_pc=0x0c0aeba8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aec12u,2);
goto P_0c0aebaa;
P_0c0aebaa: /* original 8f03, guest PC 0x0c0aebaa */
if(!s->budget--) { s->failed_pc=0x0c0aebaau; return 0; }
cond=r[17]&1u;
r[14]+=r[12];
if(!cond) { goto P_0c0aebb4; }
goto P_0c0aebae;
P_0c0aebac: /* original 3ecc, guest PC 0x0c0aebac */
if(!s->budget--) { s->failed_pc=0x0c0aebacu; return 0; }
r[14]+=r[12];
goto P_0c0aebae;
P_0c0aebae: /* original d11d, guest PC 0x0c0aebae */
if(!s->budget--) { s->failed_pc=0x0c0aebaeu; return 0; }
r[1]=read(ram,0x0c0aec24u,4);
goto P_0c0aebb0;
P_0c0aebb0: /* original 2148, guest PC 0x0c0aebb0 */
if(!s->budget--) { s->failed_pc=0x0c0aebb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0aebb2;
P_0c0aebb2: /* original 8904, guest PC 0x0c0aebb2 */
if(!s->budget--) { s->failed_pc=0x0c0aebb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aebbe; }
goto P_0c0aebb4;
P_0c0aebb4: /* original 2558, guest PC 0x0c0aebb4 */
if(!s->budget--) { s->failed_pc=0x0c0aebb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0aebb6;
P_0c0aebb6: /* original 8904, guest PC 0x0c0aebb6 */
if(!s->budget--) { s->failed_pc=0x0c0aebb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aebc2; }
goto P_0c0aebb8;
P_0c0aebb8: /* original d21a, guest PC 0x0c0aebb8 */
if(!s->budget--) { s->failed_pc=0x0c0aebb8u; return 0; }
r[2]=read(ram,0x0c0aec24u,4);
goto P_0c0aebba;
P_0c0aebba: /* original 2248, guest PC 0x0c0aebba */
if(!s->budget--) { s->failed_pc=0x0c0aebbau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0aebbc;
P_0c0aebbc: /* original 8901, guest PC 0x0c0aebbc */
if(!s->budget--) { s->failed_pc=0x0c0aebbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aebc2; }
goto P_0c0aebbe;
P_0c0aebbe: /* original 9e29, guest PC 0x0c0aebbe */
if(!s->budget--) { s->failed_pc=0x0c0aebbeu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aec14u,2);
goto P_0c0aebc0;
P_0c0aebc0: /* original 3ecc, guest PC 0x0c0aebc0 */
if(!s->budget--) { s->failed_pc=0x0c0aebc0u; return 0; }
r[14]+=r[12];
goto P_0c0aebc2;
P_0c0aebc2: /* original d219, guest PC 0x0c0aebc2 */
if(!s->budget--) { s->failed_pc=0x0c0aebc2u; return 0; }
r[2]=read(ram,0x0c0aec28u,4);
goto P_0c0aebc4;
P_0c0aebc4: /* original 64e3, guest PC 0x0c0aebc4 */
if(!s->budget--) { s->failed_pc=0x0c0aebc4u; return 0; }
r[4]=r[14];
goto P_0c0aebc6;
P_0c0aebc6: /* original 65e3, guest PC 0x0c0aebc6 */
if(!s->budget--) { s->failed_pc=0x0c0aebc6u; return 0; }
r[5]=r[14];
goto P_0c0aebc8;
P_0c0aebc8: /* original 420b, guest PC 0x0c0aebc8 */
if(!s->budget--) { s->failed_pc=0x0c0aebc8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aebccu;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aebccu) { target=s->pc; goto dispatch; }
goto P_0c0aebcc;
P_0c0aebca: /* original 7468, guest PC 0x0c0aebca */
if(!s->budget--) { s->failed_pc=0x0c0aebcau; return 0; }
r[4]+=0x00000068u;
goto P_0c0aebcc;
P_0c0aebcc: /* original 63f2, guest PC 0x0c0aebcc */
if(!s->budget--) { s->failed_pc=0x0c0aebccu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0aebce;
P_0c0aebce: /* original 435a, guest PC 0x0c0aebce */
if(!s->budget--) { s->failed_pc=0x0c0aebceu; return 0; }
r[53]=r[3];
goto P_0c0aebd0;
P_0c0aebd0: /* original 4311, guest PC 0x0c0aebd0 */
if(!s->budget--) { s->failed_pc=0x0c0aebd0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0aebd2;
P_0c0aebd2: /* original 8d04, guest PC 0x0c0aebd2 */
if(!s->budget--) { s->failed_pc=0x0c0aebd2u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0aebde; }
goto P_0c0aebd6;
P_0c0aebd4: /* original f32d, guest PC 0x0c0aebd4 */
if(!s->budget--) { s->failed_pc=0x0c0aebd4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0aebd6;
P_0c0aebd6: /* original d215, guest PC 0x0c0aebd6 */
if(!s->budget--) { s->failed_pc=0x0c0aebd6u; return 0; }
r[2]=read(ram,0x0c0aec2cu,4);
goto P_0c0aebd8;
P_0c0aebd8: /* original 425a, guest PC 0x0c0aebd8 */
if(!s->budget--) { s->failed_pc=0x0c0aebd8u; return 0; }
r[53]=r[2];
goto P_0c0aebda;
P_0c0aebda: /* original f20d, guest PC 0x0c0aebda */
if(!s->budget--) { s->failed_pc=0x0c0aebdau; return 0; }
fr[2]=r[53];
goto P_0c0aebdc;
P_0c0aebdc: /* original f320, guest PC 0x0c0aebdc */
if(!s->budget--) { s->failed_pc=0x0c0aebdcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0aebde;
P_0c0aebde: /* original f29d, guest PC 0x0c0aebde */
if(!s->budget--) { s->failed_pc=0x0c0aebdeu; return 0; }
fr[2]=0x3f800000u;
goto P_0c0aebe0;
P_0c0aebe0: /* original f233, guest PC 0x0c0aebe0 */
if(!s->budget--) { s->failed_pc=0x0c0aebe0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0aebe2;
P_0c0aebe2: /* original 9018, guest PC 0x0c0aebe2 */
if(!s->budget--) { s->failed_pc=0x0c0aebe2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aec16u,2);
goto P_0c0aebe4;
P_0c0aebe4: /* original e31f, guest PC 0x0c0aebe4 */
if(!s->budget--) { s->failed_pc=0x0c0aebe4u; return 0; }
r[3]=0x0000001fu;
goto P_0c0aebe6;
P_0c0aebe6: /* original 3d36, guest PC 0x0c0aebe6 */
if(!s->budget--) { s->failed_pc=0x0c0aebe6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[3])!=0);
goto P_0c0aebe8;
P_0c0aebe8: /* original fe27, guest PC 0x0c0aebe8 */
if(!s->budget--) { s->failed_pc=0x0c0aebe8u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0aebea;
P_0c0aebea: /* original 70fc, guest PC 0x0c0aebea */
if(!s->budget--) { s->failed_pc=0x0c0aebeau; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0aebec;
P_0c0aebec: /* original f38d, guest PC 0x0c0aebec */
if(!s->budget--) { s->failed_pc=0x0c0aebecu; return 0; }
fr[3]=0;
goto P_0c0aebee;
P_0c0aebee: /* original 8f21, guest PC 0x0c0aebee */
if(!s->budget--) { s->failed_pc=0x0c0aebeeu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[14]+r[0]);
if(!cond) { goto P_0c0aec34; }
goto P_0c0aebf2;
P_0c0aebf0: /* original fe37, guest PC 0x0c0aebf0 */
if(!s->budget--) { s->failed_pc=0x0c0aebf0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0aebf2;
P_0c0aebf2: /* original d00f, guest PC 0x0c0aebf2 */
if(!s->budget--) { s->failed_pc=0x0c0aebf2u; return 0; }
r[0]=read(ram,0x0c0aec30u,4);
goto P_0c0aebf4;
P_0c0aebf4: /* original 7de0, guest PC 0x0c0aebf4 */
if(!s->budget--) { s->failed_pc=0x0c0aebf4u; return 0; }
r[13]+=0xffffffe0u;
goto P_0c0aebf6;
P_0c0aebf6: /* original 4d08, guest PC 0x0c0aebf6 */
if(!s->budget--) { s->failed_pc=0x0c0aebf6u; return 0; }
r[13]<<=2;
goto P_0c0aebf8;
P_0c0aebf8: /* original 62e3, guest PC 0x0c0aebf8 */
if(!s->budget--) { s->failed_pc=0x0c0aebf8u; return 0; }
r[2]=r[14];
goto P_0c0aebfa;
P_0c0aebfa: /* original 01de, guest PC 0x0c0aebfa */
if(!s->budget--) { s->failed_pc=0x0c0aebfau; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c0aebfc;
P_0c0aebfc: /* original 7234, guest PC 0x0c0aebfc */
if(!s->budget--) { s->failed_pc=0x0c0aebfcu; return 0; }
r[2]+=0x00000034u;
goto P_0c0aebfe;
P_0c0aebfe: /* original 6523, guest PC 0x0c0aebfe */
if(!s->budget--) { s->failed_pc=0x0c0aebfeu; return 0; }
r[5]=r[2];
goto P_0c0aec00;
P_0c0aec00: /* original 1f12, guest PC 0x0c0aec00 */
if(!s->budget--) { s->failed_pc=0x0c0aec00u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0aec02;
P_0c0aec02: /* original 2f22, guest PC 0x0c0aec02 */
if(!s->budget--) { s->failed_pc=0x0c0aec02u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aec04;
P_0c0aec04: /* original d108, guest PC 0x0c0aec04 */
if(!s->budget--) { s->failed_pc=0x0c0aec04u; return 0; }
r[1]=read(ram,0x0c0aec28u,4);
goto P_0c0aec06;
P_0c0aec06: /* original 410b, guest PC 0x0c0aec06 */
if(!s->budget--) { s->failed_pc=0x0c0aec06u; return 0; }
target=r[1];
r[16]=code_base|0x0c0aec0au;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aec0au) { target=s->pc; goto dispatch; }
goto P_0c0aec0a;
P_0c0aec08: /* original 54f2, guest PC 0x0c0aec08 */
if(!s->budget--) { s->failed_pc=0x0c0aec08u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0aec0a;
P_0c0aec0a: /* original a027, guest PC 0x0c0aec0a */
if(!s->budget--) { s->failed_pc=0x0c0aec0au; return 0; }
goto P_0c0aec5c;
P_0c0aec0c: /* original 0009, guest PC 0x0c0aec0c */
if(!s->budget--) { s->failed_pc=0x0c0aec0cu; return 0; }
if(!vf3_matrix_family(0x0c0aec0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aec0eu; return 0; } return 1;
P_0c0aec34: /* original 4d5a, guest PC 0x0c0aec34 */
if(!s->budget--) { s->failed_pc=0x0c0aec34u; return 0; }
r[53]=r[13];
goto P_0c0aec36;
P_0c0aec36: /* original 4d11, guest PC 0x0c0aec36 */
if(!s->budget--) { s->failed_pc=0x0c0aec36u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c0aec38;
P_0c0aec38: /* original 8d04, guest PC 0x0c0aec38 */
if(!s->budget--) { s->failed_pc=0x0c0aec38u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0aec44; }
goto P_0c0aec3c;
P_0c0aec3a: /* original f32d, guest PC 0x0c0aec3a */
if(!s->budget--) { s->failed_pc=0x0c0aec3au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0aec3c;
P_0c0aec3c: /* original d237, guest PC 0x0c0aec3c */
if(!s->budget--) { s->failed_pc=0x0c0aec3cu; return 0; }
r[2]=read(ram,0x0c0aed1cu,4);
goto P_0c0aec3e;
P_0c0aec3e: /* original 425a, guest PC 0x0c0aec3e */
if(!s->budget--) { s->failed_pc=0x0c0aec3eu; return 0; }
r[53]=r[2];
goto P_0c0aec40;
P_0c0aec40: /* original f20d, guest PC 0x0c0aec40 */
if(!s->budget--) { s->failed_pc=0x0c0aec40u; return 0; }
fr[2]=r[53];
goto P_0c0aec42;
P_0c0aec42: /* original f320, guest PC 0x0c0aec42 */
if(!s->budget--) { s->failed_pc=0x0c0aec42u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0aec44;
P_0c0aec44: /* original c736, guest PC 0x0c0aec44 */
if(!s->budget--) { s->failed_pc=0x0c0aec44u; return 0; }
r[0]=code_base|0x000aed20u;
goto P_0c0aec46;
P_0c0aec46: /* original f43c, guest PC 0x0c0aec46 */
if(!s->budget--) { s->failed_pc=0x0c0aec46u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0aec48;
P_0c0aec48: /* original f208, guest PC 0x0c0aec48 */
if(!s->budget--) { s->failed_pc=0x0c0aec48u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0aec4a;
P_0c0aec4a: /* original 66e3, guest PC 0x0c0aec4a */
if(!s->budget--) { s->failed_pc=0x0c0aec4au; return 0; }
r[6]=r[14];
goto P_0c0aec4c;
P_0c0aec4c: /* original 905f, guest PC 0x0c0aec4c */
if(!s->budget--) { s->failed_pc=0x0c0aec4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aed0eu,2);
goto P_0c0aec4e;
P_0c0aec4e: /* original 7634, guest PC 0x0c0aec4e */
if(!s->budget--) { s->failed_pc=0x0c0aec4eu; return 0; }
r[6]+=0x00000034u;
goto P_0c0aec50;
P_0c0aec50: /* original f423, guest PC 0x0c0aec50 */
if(!s->budget--) { s->failed_pc=0x0c0aec50u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0aec52;
P_0c0aec52: /* original d234, guest PC 0x0c0aec52 */
if(!s->budget--) { s->failed_pc=0x0c0aec52u; return 0; }
r[2]=read(ram,0x0c0aed24u,4);
goto P_0c0aec54;
P_0c0aec54: /* original 05ee, guest PC 0x0c0aec54 */
if(!s->budget--) { s->failed_pc=0x0c0aec54u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aec56;
P_0c0aec56: /* original 70fc, guest PC 0x0c0aec56 */
if(!s->budget--) { s->failed_pc=0x0c0aec56u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0aec58;
P_0c0aec58: /* original 420b, guest PC 0x0c0aec58 */
if(!s->budget--) { s->failed_pc=0x0c0aec58u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aec5cu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aec5cu) { target=s->pc; goto dispatch; }
goto P_0c0aec5c;
P_0c0aec5a: /* original 04ee, guest PC 0x0c0aec5a */
if(!s->budget--) { s->failed_pc=0x0c0aec5au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aec5c;
P_0c0aec5c: /* original 53b2, guest PC 0x0c0aec5c */
if(!s->budget--) { s->failed_pc=0x0c0aec5cu; return 0; }
r[3]=read(ram,r[11]+8,4);
goto P_0c0aec5e;
P_0c0aec5e: /* original 66b3, guest PC 0x0c0aec5e */
if(!s->budget--) { s->failed_pc=0x0c0aec5eu; return 0; }
r[6]=r[11];
goto P_0c0aec60;
P_0c0aec60: /* original 64c3, guest PC 0x0c0aec60 */
if(!s->budget--) { s->failed_pc=0x0c0aec60u; return 0; }
r[4]=r[12];
goto P_0c0aec62;
P_0c0aec62: /* original 7307, guest PC 0x0c0aec62 */
if(!s->budget--) { s->failed_pc=0x0c0aec62u; return 0; }
r[3]+=0x00000007u;
goto P_0c0aec64;
P_0c0aec64: /* original 1b32, guest PC 0x0c0aec64 */
if(!s->budget--) { s->failed_pc=0x0c0aec64u; return 0; }
write(ram,r[11]+8,r[3],4);
goto P_0c0aec66;
P_0c0aec66: /* original 55f1, guest PC 0x0c0aec66 */
if(!s->budget--) { s->failed_pc=0x0c0aec66u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0aec68;
P_0c0aec68: /* original 7f0c, guest PC 0x0c0aec68 */
if(!s->budget--) { s->failed_pc=0x0c0aec68u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0aec6a;
P_0c0aec6a: /* original 4f26, guest PC 0x0c0aec6a */
if(!s->budget--) { s->failed_pc=0x0c0aec6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aec6c;
P_0c0aec6c: /* original 6bf6, guest PC 0x0c0aec6c */
if(!s->budget--) { s->failed_pc=0x0c0aec6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0aec6e;
P_0c0aec6e: /* original 6cf6, guest PC 0x0c0aec6e */
if(!s->budget--) { s->failed_pc=0x0c0aec6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aec70;
P_0c0aec70: /* original 6df6, guest PC 0x0c0aec70 */
if(!s->budget--) { s->failed_pc=0x0c0aec70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aec72;
P_0c0aec72: /* original ab13, guest PC 0x0c0aec72 */
if(!s->budget--) { s->failed_pc=0x0c0aec72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae29c;
P_0c0aec74: /* original 6ef6, guest PC 0x0c0aec74 */
if(!s->budget--) { s->failed_pc=0x0c0aec74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aec76u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aec76u; return 0; } return 1;
P_0c0af728: /* original 2fe6, guest PC 0x0c0af728 */
if(!s->budget--) { s->failed_pc=0x0c0af728u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72a;
P_0c0af72a: /* original 6e43, guest PC 0x0c0af72a */
if(!s->budget--) { s->failed_pc=0x0c0af72au; return 0; }
r[14]=r[4];
goto P_0c0af72c;
P_0c0af72c: /* original 2fd6, guest PC 0x0c0af72c */
if(!s->budget--) { s->failed_pc=0x0c0af72cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72e;
P_0c0af72e: /* original 6d63, guest PC 0x0c0af72e */
if(!s->budget--) { s->failed_pc=0x0c0af72eu; return 0; }
r[13]=r[6];
goto P_0c0af730;
P_0c0af730: /* original 53d2, guest PC 0x0c0af730 */
if(!s->budget--) { s->failed_pc=0x0c0af730u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0af732;
P_0c0af732: /* original 907a, guest PC 0x0c0af732 */
if(!s->budget--) { s->failed_pc=0x0c0af732u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82au,2);
goto P_0c0af734;
P_0c0af734: /* original 4f22, guest PC 0x0c0af734 */
if(!s->budget--) { s->failed_pc=0x0c0af734u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af736;
P_0c0af736: /* original d441, guest PC 0x0c0af736 */
if(!s->budget--) { s->failed_pc=0x0c0af736u; return 0; }
r[4]=read(ram,0x0c0af83cu,4);
goto P_0c0af738;
P_0c0af738: /* original 0e36, guest PC 0x0c0af738 */
if(!s->budget--) { s->failed_pc=0x0c0af738u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0af73a;
P_0c0af73a: /* original 9377, guest PC 0x0c0af73a */
if(!s->budget--) { s->failed_pc=0x0c0af73au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82cu,2);
goto P_0c0af73c;
P_0c0af73c: /* original 7ff8, guest PC 0x0c0af73c */
if(!s->budget--) { s->failed_pc=0x0c0af73cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0af73e;
P_0c0af73e: /* original 52d3, guest PC 0x0c0af73e */
if(!s->budget--) { s->failed_pc=0x0c0af73eu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af740;
P_0c0af740: /* original 2238, guest PC 0x0c0af740 */
if(!s->budget--) { s->failed_pc=0x0c0af740u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0af742;
P_0c0af742: /* original 890e, guest PC 0x0c0af742 */
if(!s->budget--) { s->failed_pc=0x0c0af742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af762; }
goto P_0c0af744;
P_0c0af744: /* original 51d3, guest PC 0x0c0af744 */
if(!s->budget--) { s->failed_pc=0x0c0af744u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af746;
P_0c0af746: /* original 9372, guest PC 0x0c0af746 */
if(!s->budget--) { s->failed_pc=0x0c0af746u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82eu,2);
goto P_0c0af748;
P_0c0af748: /* original 2139, guest PC 0x0c0af748 */
if(!s->budget--) { s->failed_pc=0x0c0af748u; return 0; }
r[1]&=r[3];
goto P_0c0af74a;
P_0c0af74a: /* original 1d13, guest PC 0x0c0af74a */
if(!s->budget--) { s->failed_pc=0x0c0af74au; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af74c;
P_0c0af74c: /* original d53c, guest PC 0x0c0af74c */
if(!s->budget--) { s->failed_pc=0x0c0af74cu; return 0; }
r[5]=read(ram,0x0c0af840u,4);
goto P_0c0af74e;
P_0c0af74e: /* original 5241, guest PC 0x0c0af74e */
if(!s->budget--) { s->failed_pc=0x0c0af74eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0af750;
P_0c0af750: /* original 2258, guest PC 0x0c0af750 */
if(!s->budget--) { s->failed_pc=0x0c0af750u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0af752;
P_0c0af752: /* original 8b06, guest PC 0x0c0af752 */
if(!s->budget--) { s->failed_pc=0x0c0af752u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af754;
P_0c0af754: /* original 6342, guest PC 0x0c0af754 */
if(!s->budget--) { s->failed_pc=0x0c0af754u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0af756;
P_0c0af756: /* original 2538, guest PC 0x0c0af756 */
if(!s->budget--) { s->failed_pc=0x0c0af756u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0af758;
P_0c0af758: /* original 8b03, guest PC 0x0c0af758 */
if(!s->budget--) { s->failed_pc=0x0c0af758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af75a;
P_0c0af75a: /* original 85ef, guest PC 0x0c0af75a */
if(!s->budget--) { s->failed_pc=0x0c0af75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af75c;
P_0c0af75c: /* original 9368, guest PC 0x0c0af75c */
if(!s->budget--) { s->failed_pc=0x0c0af75cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af830u,2);
goto P_0c0af75e;
P_0c0af75e: /* original 303c, guest PC 0x0c0af75e */
if(!s->budget--) { s->failed_pc=0x0c0af75eu; return 0; }
r[0]+=r[3];
goto P_0c0af760;
P_0c0af760: /* original 81ef, guest PC 0x0c0af760 */
if(!s->budget--) { s->failed_pc=0x0c0af760u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0af762;
P_0c0af762: /* original 53d4, guest PC 0x0c0af762 */
if(!s->budget--) { s->failed_pc=0x0c0af762u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0af764;
P_0c0af764: /* original d437, guest PC 0x0c0af764 */
if(!s->budget--) { s->failed_pc=0x0c0af764u; return 0; }
r[4]=read(ram,0x0c0af844u,4);
goto P_0c0af766;
P_0c0af766: /* original 2348, guest PC 0x0c0af766 */
if(!s->budget--) { s->failed_pc=0x0c0af766u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af768;
P_0c0af768: /* original 8903, guest PC 0x0c0af768 */
if(!s->budget--) { s->failed_pc=0x0c0af768u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af772; }
goto P_0c0af76a;
P_0c0af76a: /* original 52d3, guest PC 0x0c0af76a */
if(!s->budget--) { s->failed_pc=0x0c0af76au; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af76c;
P_0c0af76c: /* original d336, guest PC 0x0c0af76c */
if(!s->budget--) { s->failed_pc=0x0c0af76cu; return 0; }
r[3]=read(ram,0x0c0af848u,4);
goto P_0c0af76e;
P_0c0af76e: /* original 223b, guest PC 0x0c0af76e */
if(!s->budget--) { s->failed_pc=0x0c0af76eu; return 0; }
r[2]|=r[3];
goto P_0c0af770;
P_0c0af770: /* original 1d23, guest PC 0x0c0af770 */
if(!s->budget--) { s->failed_pc=0x0c0af770u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af772;
P_0c0af772: /* original 51d3, guest PC 0x0c0af772 */
if(!s->budget--) { s->failed_pc=0x0c0af772u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af774;
P_0c0af774: /* original 2418, guest PC 0x0c0af774 */
if(!s->budget--) { s->failed_pc=0x0c0af774u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0af776;
P_0c0af776: /* original 891e, guest PC 0x0c0af776 */
if(!s->budget--) { s->failed_pc=0x0c0af776u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7b6; }
goto P_0c0af778;
P_0c0af778: /* original d334, guest PC 0x0c0af778 */
if(!s->budget--) { s->failed_pc=0x0c0af778u; return 0; }
r[3]=read(ram,0x0c0af84cu,4);
goto P_0c0af77a;
P_0c0af77a: /* original 65f3, guest PC 0x0c0af77a */
if(!s->budget--) { s->failed_pc=0x0c0af77au; return 0; }
r[5]=r[15];
goto P_0c0af77c;
P_0c0af77c: /* original 52d3, guest PC 0x0c0af77c */
if(!s->budget--) { s->failed_pc=0x0c0af77cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af77e;
P_0c0af77e: /* original 66f3, guest PC 0x0c0af77e */
if(!s->budget--) { s->failed_pc=0x0c0af77eu; return 0; }
r[6]=r[15];
goto P_0c0af780;
P_0c0af780: /* original 2239, guest PC 0x0c0af780 */
if(!s->budget--) { s->failed_pc=0x0c0af780u; return 0; }
r[2]&=r[3];
goto P_0c0af782;
P_0c0af782: /* original 1d23, guest PC 0x0c0af782 */
if(!s->budget--) { s->failed_pc=0x0c0af782u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af784;
P_0c0af784: /* original 85ef, guest PC 0x0c0af784 */
if(!s->budget--) { s->failed_pc=0x0c0af784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af786;
P_0c0af786: /* original 640d, guest PC 0x0c0af786 */
if(!s->budget--) { s->failed_pc=0x0c0af786u; return 0; }
r[4]=r[0]&65535u;
goto P_0c0af788;
P_0c0af788: /* original 9053, guest PC 0x0c0af788 */
if(!s->budget--) { s->failed_pc=0x0c0af788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af832u,2);
goto P_0c0af78a;
P_0c0af78a: /* original f3e6, guest PC 0x0c0af78a */
if(!s->budget--) { s->failed_pc=0x0c0af78au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af78c;
P_0c0af78c: /* original e004, guest PC 0x0c0af78c */
if(!s->budget--) { s->failed_pc=0x0c0af78cu; return 0; }
r[0]=0x00000004u;
goto P_0c0af78e;
P_0c0af78e: /* original ff37, guest PC 0x0c0af78e */
if(!s->budget--) { s->failed_pc=0x0c0af78eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0af790;
P_0c0af790: /* original 9050, guest PC 0x0c0af790 */
if(!s->budget--) { s->failed_pc=0x0c0af790u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af834u,2);
goto P_0c0af792;
P_0c0af792: /* original f3e6, guest PC 0x0c0af792 */
if(!s->budget--) { s->failed_pc=0x0c0af792u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af794;
P_0c0af794: /* original ff3a, guest PC 0x0c0af794 */
if(!s->budget--) { s->failed_pc=0x0c0af794u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0af796;
P_0c0af796: /* original d22e, guest PC 0x0c0af796 */
if(!s->budget--) { s->failed_pc=0x0c0af796u; return 0; }
r[2]=read(ram,0x0c0af850u,4);
goto P_0c0af798;
P_0c0af798: /* original 420b, guest PC 0x0c0af798 */
if(!s->budget--) { s->failed_pc=0x0c0af798u; return 0; }
target=r[2];
r[16]=code_base|0x0c0af79cu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af79cu) { target=s->pc; goto dispatch; }
goto P_0c0af79c;
P_0c0af79a: /* original 7504, guest PC 0x0c0af79a */
if(!s->budget--) { s->failed_pc=0x0c0af79au; return 0; }
r[5]+=0x00000004u;
goto P_0c0af79c;
P_0c0af79c: /* original 904b, guest PC 0x0c0af79c */
if(!s->budget--) { s->failed_pc=0x0c0af79cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af836u,2);
goto P_0c0af79e;
P_0c0af79e: /* original f2f8, guest PC 0x0c0af79e */
if(!s->budget--) { s->failed_pc=0x0c0af79eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0af7a0;
P_0c0af7a0: /* original f5e6, guest PC 0x0c0af7a0 */
if(!s->budget--) { s->failed_pc=0x0c0af7a0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0af7a2;
P_0c0af7a2: /* original 7008, guest PC 0x0c0af7a2 */
if(!s->budget--) { s->failed_pc=0x0c0af7a2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0af7a4;
P_0c0af7a4: /* original f4e6, guest PC 0x0c0af7a4 */
if(!s->budget--) { s->failed_pc=0x0c0af7a4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0af7a6;
P_0c0af7a6: /* original e004, guest PC 0x0c0af7a6 */
if(!s->budget--) { s->failed_pc=0x0c0af7a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0af7a8;
P_0c0af7a8: /* original f3f6, guest PC 0x0c0af7a8 */
if(!s->budget--) { s->failed_pc=0x0c0af7a8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af7aa;
P_0c0af7aa: /* original e010, guest PC 0x0c0af7aa */
if(!s->budget--) { s->failed_pc=0x0c0af7aau; return 0; }
r[0]=0x00000010u;
goto P_0c0af7ac;
P_0c0af7ac: /* original f421, guest PC 0x0c0af7ac */
if(!s->budget--) { s->failed_pc=0x0c0af7acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0af7ae;
P_0c0af7ae: /* original f531, guest PC 0x0c0af7ae */
if(!s->budget--) { s->failed_pc=0x0c0af7aeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0af7b0;
P_0c0af7b0: /* original fe57, guest PC 0x0c0af7b0 */
if(!s->budget--) { s->failed_pc=0x0c0af7b0u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0af7b2;
P_0c0af7b2: /* original e018, guest PC 0x0c0af7b2 */
if(!s->budget--) { s->failed_pc=0x0c0af7b2u; return 0; }
r[0]=0x00000018u;
goto P_0c0af7b4;
P_0c0af7b4: /* original fe47, guest PC 0x0c0af7b4 */
if(!s->budget--) { s->failed_pc=0x0c0af7b4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0af7b6;
P_0c0af7b6: /* original d327, guest PC 0x0c0af7b6 */
if(!s->budget--) { s->failed_pc=0x0c0af7b6u; return 0; }
r[3]=read(ram,0x0c0af854u,4);
goto P_0c0af7b8;
P_0c0af7b8: /* original 64e2, guest PC 0x0c0af7b8 */
if(!s->budget--) { s->failed_pc=0x0c0af7b8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0af7ba;
P_0c0af7ba: /* original 2348, guest PC 0x0c0af7ba */
if(!s->budget--) { s->failed_pc=0x0c0af7bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af7bc;
P_0c0af7bc: /* original 8906, guest PC 0x0c0af7bc */
if(!s->budget--) { s->failed_pc=0x0c0af7bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7cc; }
goto P_0c0af7be;
P_0c0af7be: /* original d226, guest PC 0x0c0af7be */
if(!s->budget--) { s->failed_pc=0x0c0af7beu; return 0; }
r[2]=read(ram,0x0c0af858u,4);
goto P_0c0af7c0;
P_0c0af7c0: /* original 2429, guest PC 0x0c0af7c0 */
if(!s->budget--) { s->failed_pc=0x0c0af7c0u; return 0; }
r[4]&=r[2];
goto P_0c0af7c2;
P_0c0af7c2: /* original 2e42, guest PC 0x0c0af7c2 */
if(!s->budget--) { s->failed_pc=0x0c0af7c2u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0af7c4;
P_0c0af7c4: /* original d325, guest PC 0x0c0af7c4 */
if(!s->budget--) { s->failed_pc=0x0c0af7c4u; return 0; }
r[3]=read(ram,0x0c0af85cu,4);
goto P_0c0af7c6;
P_0c0af7c6: /* original 51d3, guest PC 0x0c0af7c6 */
if(!s->budget--) { s->failed_pc=0x0c0af7c6u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af7c8;
P_0c0af7c8: /* original 213b, guest PC 0x0c0af7c8 */
if(!s->budget--) { s->failed_pc=0x0c0af7c8u; return 0; }
r[1]|=r[3];
goto P_0c0af7ca;
P_0c0af7ca: /* original 1d13, guest PC 0x0c0af7ca */
if(!s->budget--) { s->failed_pc=0x0c0af7cau; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af7cc;
P_0c0af7cc: /* original 7f08, guest PC 0x0c0af7cc */
if(!s->budget--) { s->failed_pc=0x0c0af7ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c0af7ce;
P_0c0af7ce: /* original 52d3, guest PC 0x0c0af7ce */
if(!s->budget--) { s->failed_pc=0x0c0af7ceu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af7d0;
P_0c0af7d0: /* original 4f26, guest PC 0x0c0af7d0 */
if(!s->budget--) { s->failed_pc=0x0c0af7d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af7d2;
P_0c0af7d2: /* original e048, guest PC 0x0c0af7d2 */
if(!s->budget--) { s->failed_pc=0x0c0af7d2u; return 0; }
r[0]=0x00000048u;
goto P_0c0af7d4;
P_0c0af7d4: /* original 0e26, guest PC 0x0c0af7d4 */
if(!s->budget--) { s->failed_pc=0x0c0af7d4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0af7d6;
P_0c0af7d6: /* original 6df6, guest PC 0x0c0af7d6 */
if(!s->budget--) { s->failed_pc=0x0c0af7d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af7d8;
P_0c0af7d8: /* original 000b, guest PC 0x0c0af7d8 */
if(!s->budget--) { s->failed_pc=0x0c0af7d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af7da: /* original 6ef6, guest PC 0x0c0af7da */
if(!s->budget--) { s->failed_pc=0x0c0af7dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af7dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af7dcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
