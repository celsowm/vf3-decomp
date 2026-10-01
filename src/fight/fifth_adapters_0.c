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
int vf3_fifth_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c035518u: goto P_0c035518;
case 0x0c03551au: goto P_0c03551a;
case 0x0c03551cu: goto P_0c03551c;
case 0x0c03551eu: goto P_0c03551e;
case 0x0c035520u: goto P_0c035520;
case 0x0c035522u: goto P_0c035522;
case 0x0c035524u: goto P_0c035524;
case 0x0c035526u: goto P_0c035526;
case 0x0c035528u: goto P_0c035528;
case 0x0c03552au: goto P_0c03552a;
case 0x0c03552cu: goto P_0c03552c;
case 0x0c03552eu: goto P_0c03552e;
case 0x0c035530u: goto P_0c035530;
case 0x0c035532u: goto P_0c035532;
case 0x0c035534u: goto P_0c035534;
case 0x0c035536u: goto P_0c035536;
case 0x0c035538u: goto P_0c035538;
case 0x0c03553au: goto P_0c03553a;
case 0x0c03553cu: goto P_0c03553c;
case 0x0c03553eu: goto P_0c03553e;
case 0x0c035540u: goto P_0c035540;
case 0x0c035542u: goto P_0c035542;
case 0x0c035544u: goto P_0c035544;
case 0x0c035546u: goto P_0c035546;
case 0x0c035548u: goto P_0c035548;
case 0x0c03554au: goto P_0c03554a;
case 0x0c03554cu: goto P_0c03554c;
case 0x0c03554eu: goto P_0c03554e;
case 0x0c035550u: goto P_0c035550;
case 0x0c035552u: goto P_0c035552;
case 0x0c035554u: goto P_0c035554;
case 0x0c035556u: goto P_0c035556;
case 0x0c035558u: goto P_0c035558;
case 0x0c03555au: goto P_0c03555a;
case 0x0c03555cu: goto P_0c03555c;
case 0x0c03555eu: goto P_0c03555e;
case 0x0c035560u: goto P_0c035560;
case 0x0c035562u: goto P_0c035562;
case 0x0c035564u: goto P_0c035564;
case 0x0c035566u: goto P_0c035566;
case 0x0c035568u: goto P_0c035568;
case 0x0c03556au: goto P_0c03556a;
case 0x0c03556cu: goto P_0c03556c;
case 0x0c03556eu: goto P_0c03556e;
case 0x0c035570u: goto P_0c035570;
case 0x0c035572u: goto P_0c035572;
case 0x0c035574u: goto P_0c035574;
case 0x0c035576u: goto P_0c035576;
case 0x0c035578u: goto P_0c035578;
case 0x0c03557au: goto P_0c03557a;
case 0x0c03557cu: goto P_0c03557c;
case 0x0c03557eu: goto P_0c03557e;
case 0x0c035580u: goto P_0c035580;
case 0x0c035582u: goto P_0c035582;
case 0x0c035584u: goto P_0c035584;
case 0x0c035586u: goto P_0c035586;
case 0x0c035588u: goto P_0c035588;
case 0x0c03558au: goto P_0c03558a;
case 0x0c03558cu: goto P_0c03558c;
case 0x0c03628au: goto P_0c03628a;
case 0x0c03628cu: goto P_0c03628c;
case 0x0c03628eu: goto P_0c03628e;
case 0x0c036290u: goto P_0c036290;
case 0x0c036292u: goto P_0c036292;
case 0x0c036294u: goto P_0c036294;
case 0x0c036296u: goto P_0c036296;
case 0x0c036298u: goto P_0c036298;
case 0x0c03629au: goto P_0c03629a;
case 0x0c03629cu: goto P_0c03629c;
case 0x0c03629eu: goto P_0c03629e;
case 0x0c0362a0u: goto P_0c0362a0;
case 0x0c0362a2u: goto P_0c0362a2;
case 0x0c0362a4u: goto P_0c0362a4;
case 0x0c0362a6u: goto P_0c0362a6;
case 0x0c0362a8u: goto P_0c0362a8;
case 0x0c0362aau: goto P_0c0362aa;
case 0x0c0362acu: goto P_0c0362ac;
case 0x0c0362aeu: goto P_0c0362ae;
case 0x0c0362b0u: goto P_0c0362b0;
case 0x0c0362b2u: goto P_0c0362b2;
case 0x0c0362b4u: goto P_0c0362b4;
case 0x0c0362b6u: goto P_0c0362b6;
case 0x0c0362b8u: goto P_0c0362b8;
case 0x0c0362bau: goto P_0c0362ba;
case 0x0c0362bcu: goto P_0c0362bc;
case 0x0c0362beu: goto P_0c0362be;
case 0x0c0362c0u: goto P_0c0362c0;
case 0x0c0362c2u: goto P_0c0362c2;
case 0x0c0362c4u: goto P_0c0362c4;
case 0x0c0362f8u: goto P_0c0362f8;
case 0x0c0362fau: goto P_0c0362fa;
case 0x0c0362fcu: goto P_0c0362fc;
case 0x0c0362feu: goto P_0c0362fe;
case 0x0c036300u: goto P_0c036300;
case 0x0c036302u: goto P_0c036302;
case 0x0c036304u: goto P_0c036304;
case 0x0c036306u: goto P_0c036306;
case 0x0c036308u: goto P_0c036308;
case 0x0c03630au: goto P_0c03630a;
case 0x0c03630cu: goto P_0c03630c;
case 0x0c03630eu: goto P_0c03630e;
case 0x0c036310u: goto P_0c036310;
case 0x0c036312u: goto P_0c036312;
case 0x0c036314u: goto P_0c036314;
case 0x0c036316u: goto P_0c036316;
case 0x0c036318u: goto P_0c036318;
case 0x0c03631au: goto P_0c03631a;
case 0x0c03631cu: goto P_0c03631c;
case 0x0c038fe4u: goto P_0c038fe4;
case 0x0c038fe6u: goto P_0c038fe6;
case 0x0c038fe8u: goto P_0c038fe8;
case 0x0c038feau: goto P_0c038fea;
case 0x0c038fecu: goto P_0c038fec;
case 0x0c038feeu: goto P_0c038fee;
case 0x0c038ff0u: goto P_0c038ff0;
case 0x0c038ff2u: goto P_0c038ff2;
case 0x0c038ff4u: goto P_0c038ff4;
case 0x0c038ff6u: goto P_0c038ff6;
case 0x0c038ff8u: goto P_0c038ff8;
case 0x0c038ffau: goto P_0c038ffa;
case 0x0c038ffcu: goto P_0c038ffc;
case 0x0c038ffeu: goto P_0c038ffe;
case 0x0c039000u: goto P_0c039000;
case 0x0c039002u: goto P_0c039002;
case 0x0c039004u: goto P_0c039004;
case 0x0c039006u: goto P_0c039006;
case 0x0c039008u: goto P_0c039008;
case 0x0c03900au: goto P_0c03900a;
case 0x0c03900cu: goto P_0c03900c;
case 0x0c03900eu: goto P_0c03900e;
case 0x0c039010u: goto P_0c039010;
case 0x0c039012u: goto P_0c039012;
case 0x0c039014u: goto P_0c039014;
case 0x0c039016u: goto P_0c039016;
case 0x0c039018u: goto P_0c039018;
case 0x0c03901au: goto P_0c03901a;
case 0x0c03901cu: goto P_0c03901c;
case 0x0c03901eu: goto P_0c03901e;
case 0x0c039020u: goto P_0c039020;
case 0x0c039022u: goto P_0c039022;
case 0x0c039024u: goto P_0c039024;
case 0x0c039030u: goto P_0c039030;
case 0x0c039032u: goto P_0c039032;
case 0x0c039034u: goto P_0c039034;
case 0x0c039036u: goto P_0c039036;
case 0x0c039038u: goto P_0c039038;
case 0x0c03903au: goto P_0c03903a;
case 0x0c03903cu: goto P_0c03903c;
case 0x0c03903eu: goto P_0c03903e;
case 0x0c039040u: goto P_0c039040;
case 0x0c039042u: goto P_0c039042;
case 0x0c039044u: goto P_0c039044;
case 0x0c039046u: goto P_0c039046;
case 0x0c039048u: goto P_0c039048;
case 0x0c03904au: goto P_0c03904a;
case 0x0c03904cu: goto P_0c03904c;
case 0x0c03904eu: goto P_0c03904e;
case 0x0c039050u: goto P_0c039050;
case 0x0c039052u: goto P_0c039052;
case 0x0c039054u: goto P_0c039054;
case 0x0c039056u: goto P_0c039056;
case 0x0c039058u: goto P_0c039058;
case 0x0c03905au: goto P_0c03905a;
case 0x0c03905cu: goto P_0c03905c;
case 0x0c03905eu: goto P_0c03905e;
case 0x0c039060u: goto P_0c039060;
case 0x0c039062u: goto P_0c039062;
case 0x0c039064u: goto P_0c039064;
case 0x0c039066u: goto P_0c039066;
case 0x0c039068u: goto P_0c039068;
case 0x0c03906au: goto P_0c03906a;
case 0x0c03906cu: goto P_0c03906c;
case 0x0c03906eu: goto P_0c03906e;
case 0x0c039070u: goto P_0c039070;
case 0x0c039072u: goto P_0c039072;
case 0x0c039074u: goto P_0c039074;
case 0x0c039076u: goto P_0c039076;
case 0x0c039078u: goto P_0c039078;
case 0x0c03907au: goto P_0c03907a;
case 0x0c03907cu: goto P_0c03907c;
case 0x0c03907eu: goto P_0c03907e;
case 0x0c03e442u: goto P_0c03e442;
case 0x0c03e444u: goto P_0c03e444;
case 0x0c03e446u: goto P_0c03e446;
case 0x0c03e448u: goto P_0c03e448;
case 0x0c03e44au: goto P_0c03e44a;
case 0x0c03e44cu: goto P_0c03e44c;
case 0x0c03e44eu: goto P_0c03e44e;
case 0x0c03e450u: goto P_0c03e450;
case 0x0c03e452u: goto P_0c03e452;
case 0x0c03e454u: goto P_0c03e454;
case 0x0c03e456u: goto P_0c03e456;
case 0x0c03e458u: goto P_0c03e458;
case 0x0c03e45au: goto P_0c03e45a;
case 0x0c03e45cu: goto P_0c03e45c;
case 0x0c03e45eu: goto P_0c03e45e;
case 0x0c03e460u: goto P_0c03e460;
case 0x0c03e462u: goto P_0c03e462;
case 0x0c03e464u: goto P_0c03e464;
case 0x0c03e466u: goto P_0c03e466;
case 0x0c03e468u: goto P_0c03e468;
case 0x0c03e46au: goto P_0c03e46a;
case 0x0c03e46cu: goto P_0c03e46c;
case 0x0c03e46eu: goto P_0c03e46e;
case 0x0c03e470u: goto P_0c03e470;
case 0x0c03e472u: goto P_0c03e472;
case 0x0c03e474u: goto P_0c03e474;
case 0x0c03e476u: goto P_0c03e476;
case 0x0c03e478u: goto P_0c03e478;
case 0x0c03e47au: goto P_0c03e47a;
case 0x0c03e47cu: goto P_0c03e47c;
case 0x0c03e47eu: goto P_0c03e47e;
case 0x0c03e480u: goto P_0c03e480;
case 0x0c03e482u: goto P_0c03e482;
case 0x0c03e484u: goto P_0c03e484;
case 0x0c03e486u: goto P_0c03e486;
case 0x0c03e488u: goto P_0c03e488;
case 0x0c03e48au: goto P_0c03e48a;
case 0x0c03e48cu: goto P_0c03e48c;
case 0x0c03e48eu: goto P_0c03e48e;
case 0x0c03e490u: goto P_0c03e490;
case 0x0c03e492u: goto P_0c03e492;
case 0x0c03e494u: goto P_0c03e494;
case 0x0c03e496u: goto P_0c03e496;
case 0x0c03e498u: goto P_0c03e498;
case 0x0c03e49au: goto P_0c03e49a;
case 0x0c03e49cu: goto P_0c03e49c;
case 0x0c03e49eu: goto P_0c03e49e;
case 0x0c03e4a0u: goto P_0c03e4a0;
case 0x0c03e4a2u: goto P_0c03e4a2;
case 0x0c03e4a4u: goto P_0c03e4a4;
case 0x0c03e4a6u: goto P_0c03e4a6;
case 0x0c03e4a8u: goto P_0c03e4a8;
case 0x0c03e4aau: goto P_0c03e4aa;
case 0x0c03e4acu: goto P_0c03e4ac;
case 0x0c03e4aeu: goto P_0c03e4ae;
case 0x0c03e4b0u: goto P_0c03e4b0;
case 0x0c03e4b2u: goto P_0c03e4b2;
case 0x0c03e4b4u: goto P_0c03e4b4;
case 0x0c03e4b6u: goto P_0c03e4b6;
case 0x0c03e4b8u: goto P_0c03e4b8;
case 0x0c03e4bau: goto P_0c03e4ba;
case 0x0c03e4bcu: goto P_0c03e4bc;
case 0x0c03e4beu: goto P_0c03e4be;
case 0x0c03e4c0u: goto P_0c03e4c0;
case 0x0c03e4c2u: goto P_0c03e4c2;
case 0x0c03e4c4u: goto P_0c03e4c4;
case 0x0c03e4c6u: goto P_0c03e4c6;
case 0x0c03e4c8u: goto P_0c03e4c8;
case 0x0c03e4cau: goto P_0c03e4ca;
case 0x0c03e4ccu: goto P_0c03e4cc;
case 0x0c03e4ceu: goto P_0c03e4ce;
case 0x0c03e4d0u: goto P_0c03e4d0;
case 0x0c03e4d2u: goto P_0c03e4d2;
case 0x0c03e4d4u: goto P_0c03e4d4;
case 0x0c03e4d6u: goto P_0c03e4d6;
case 0x0c03e4d8u: goto P_0c03e4d8;
case 0x0c03e4dau: goto P_0c03e4da;
case 0x0c03e4dcu: goto P_0c03e4dc;
case 0x0c03e4deu: goto P_0c03e4de;
case 0x0c03e4e0u: goto P_0c03e4e0;
case 0x0c03e4e2u: goto P_0c03e4e2;
case 0x0c03e4e4u: goto P_0c03e4e4;
case 0x0c03e4e6u: goto P_0c03e4e6;
case 0x0c03e4e8u: goto P_0c03e4e8;
case 0x0c03e4eau: goto P_0c03e4ea;
case 0x0c03e4ecu: goto P_0c03e4ec;
case 0x0c03e4eeu: goto P_0c03e4ee;
case 0x0c03e4f0u: goto P_0c03e4f0;
case 0x0c03e4f2u: goto P_0c03e4f2;
case 0x0c03e4f4u: goto P_0c03e4f4;
case 0x0c03e4f6u: goto P_0c03e4f6;
case 0x0c03f040u: goto P_0c03f040;
case 0x0c03f042u: goto P_0c03f042;
case 0x0c03f044u: goto P_0c03f044;
case 0x0c03f046u: goto P_0c03f046;
case 0x0c03f048u: goto P_0c03f048;
case 0x0c03f04au: goto P_0c03f04a;
case 0x0c03f04cu: goto P_0c03f04c;
case 0x0c03f04eu: goto P_0c03f04e;
case 0x0c03f050u: goto P_0c03f050;
case 0x0c03f052u: goto P_0c03f052;
case 0x0c03f054u: goto P_0c03f054;
case 0x0c03f056u: goto P_0c03f056;
case 0x0c03f058u: goto P_0c03f058;
case 0x0c03f05au: goto P_0c03f05a;
case 0x0c03f05cu: goto P_0c03f05c;
case 0x0c03f05eu: goto P_0c03f05e;
case 0x0c03f060u: goto P_0c03f060;
case 0x0c03f062u: goto P_0c03f062;
case 0x0c03f064u: goto P_0c03f064;
case 0x0c03f066u: goto P_0c03f066;
case 0x0c03f068u: goto P_0c03f068;
case 0x0c03f06au: goto P_0c03f06a;
case 0x0c03f06cu: goto P_0c03f06c;
case 0x0c03f06eu: goto P_0c03f06e;
case 0x0c03f070u: goto P_0c03f070;
case 0x0c03f072u: goto P_0c03f072;
case 0x0c03f074u: goto P_0c03f074;
case 0x0c03f076u: goto P_0c03f076;
case 0x0c03f078u: goto P_0c03f078;
case 0x0c03f07au: goto P_0c03f07a;
case 0x0c03f07cu: goto P_0c03f07c;
case 0x0c03f080u: goto P_0c03f080;
case 0x0c03f082u: goto P_0c03f082;
case 0x0c03f084u: goto P_0c03f084;
case 0x0c03f086u: goto P_0c03f086;
case 0x0c03f088u: goto P_0c03f088;
case 0x0c03f08au: goto P_0c03f08a;
case 0x0c03f08cu: goto P_0c03f08c;
case 0x0c03f08eu: goto P_0c03f08e;
case 0x0c03f090u: goto P_0c03f090;
case 0x0c03f092u: goto P_0c03f092;
case 0x0c03f094u: goto P_0c03f094;
case 0x0c03f096u: goto P_0c03f096;
case 0x0c03f098u: goto P_0c03f098;
case 0x0c03f09au: goto P_0c03f09a;
case 0x0c03f2e0u: goto P_0c03f2e0;
case 0x0c03f2e2u: goto P_0c03f2e2;
case 0x0c03f2e4u: goto P_0c03f2e4;
case 0x0c03f2e6u: goto P_0c03f2e6;
case 0x0c03f2e8u: goto P_0c03f2e8;
case 0x0c03f2eau: goto P_0c03f2ea;
case 0x0c03f2ecu: goto P_0c03f2ec;
case 0x0c03f2eeu: goto P_0c03f2ee;
case 0x0c03f2f0u: goto P_0c03f2f0;
case 0x0c03f350u: goto P_0c03f350;
case 0x0c03f352u: goto P_0c03f352;
case 0x0c03f354u: goto P_0c03f354;
case 0x0c03f356u: goto P_0c03f356;
case 0x0c03f358u: goto P_0c03f358;
case 0x0c03f35au: goto P_0c03f35a;
case 0x0c03f35cu: goto P_0c03f35c;
case 0x0c03f35eu: goto P_0c03f35e;
case 0x0c03f360u: goto P_0c03f360;
case 0x0c03f362u: goto P_0c03f362;
case 0x0c03f364u: goto P_0c03f364;
case 0x0c03f366u: goto P_0c03f366;
case 0x0c03f368u: goto P_0c03f368;
case 0x0c03f36au: goto P_0c03f36a;
case 0x0c03f36cu: goto P_0c03f36c;
case 0x0c03f36eu: goto P_0c03f36e;
case 0x0c03f370u: goto P_0c03f370;
case 0x0c03f372u: goto P_0c03f372;
case 0x0c03f374u: goto P_0c03f374;
case 0x0c03f376u: goto P_0c03f376;
case 0x0c03f378u: goto P_0c03f378;
case 0x0c03f37au: goto P_0c03f37a;
case 0x0c03f37cu: goto P_0c03f37c;
case 0x0c03f37eu: goto P_0c03f37e;
case 0x0c03f380u: goto P_0c03f380;
case 0x0c03f390u: goto P_0c03f390;
case 0x0c03f392u: goto P_0c03f392;
case 0x0c03f394u: goto P_0c03f394;
case 0x0c03f396u: goto P_0c03f396;
case 0x0c03f398u: goto P_0c03f398;
case 0x0c03f39au: goto P_0c03f39a;
case 0x0c03f39cu: goto P_0c03f39c;
case 0x0c03f39eu: goto P_0c03f39e;
case 0x0c03f3a0u: goto P_0c03f3a0;
case 0x0c03f3a2u: goto P_0c03f3a2;
case 0x0c03f3b0u: goto P_0c03f3b0;
case 0x0c03f3b2u: goto P_0c03f3b2;
case 0x0c03f3b4u: goto P_0c03f3b4;
case 0x0c03f3b6u: goto P_0c03f3b6;
case 0x0c03f3b8u: goto P_0c03f3b8;
case 0x0c03f3bau: goto P_0c03f3ba;
case 0x0c03f3bcu: goto P_0c03f3bc;
case 0x0c03f3beu: goto P_0c03f3be;
case 0x0c03f3c0u: goto P_0c03f3c0;
case 0x0c03f3c2u: goto P_0c03f3c2;
case 0x0c03f3c4u: goto P_0c03f3c4;
case 0x0c03f3c6u: goto P_0c03f3c6;
case 0x0c03f3c8u: goto P_0c03f3c8;
case 0x0c03f3cau: goto P_0c03f3ca;
case 0x0c03f3ccu: goto P_0c03f3cc;
case 0x0c03f3ceu: goto P_0c03f3ce;
case 0x0c03f3d0u: goto P_0c03f3d0;
case 0x0c03f3d2u: goto P_0c03f3d2;
case 0x0c03f3d4u: goto P_0c03f3d4;
case 0x0c03f3d6u: goto P_0c03f3d6;
case 0x0c03f3d8u: goto P_0c03f3d8;
case 0x0c03f3dau: goto P_0c03f3da;
case 0x0c03f3f0u: goto P_0c03f3f0;
case 0x0c03f3f2u: goto P_0c03f3f2;
case 0x0c03f3f4u: goto P_0c03f3f4;
case 0x0c03f3f6u: goto P_0c03f3f6;
case 0x0c03f3f8u: goto P_0c03f3f8;
case 0x0c03f3fau: goto P_0c03f3fa;
case 0x0c03f3fcu: goto P_0c03f3fc;
case 0x0c03f3feu: goto P_0c03f3fe;
case 0x0c03f400u: goto P_0c03f400;
case 0x0c03f402u: goto P_0c03f402;
case 0x0c03f404u: goto P_0c03f404;
case 0x0c03f406u: goto P_0c03f406;
case 0x0c03f410u: goto P_0c03f410;
case 0x0c03f412u: goto P_0c03f412;
case 0x0c03f414u: goto P_0c03f414;
case 0x0c03f416u: goto P_0c03f416;
case 0x0c03f418u: goto P_0c03f418;
case 0x0c03f41au: goto P_0c03f41a;
case 0x0c03f41cu: goto P_0c03f41c;
case 0x0c03f41eu: goto P_0c03f41e;
case 0x0c03f420u: goto P_0c03f420;
case 0x0c03f422u: goto P_0c03f422;
case 0x0c03f424u: goto P_0c03f424;
case 0x0c03f426u: goto P_0c03f426;
case 0x0c03f428u: goto P_0c03f428;
case 0x0c03f42au: goto P_0c03f42a;
case 0x0c03f42cu: goto P_0c03f42c;
case 0x0c03f42eu: goto P_0c03f42e;
case 0x0c03f430u: goto P_0c03f430;
case 0x0c03f432u: goto P_0c03f432;
case 0x0c03f434u: goto P_0c03f434;
case 0x0c03f436u: goto P_0c03f436;
case 0x0c03f438u: goto P_0c03f438;
case 0x0c03f43au: goto P_0c03f43a;
case 0x0c03f43cu: goto P_0c03f43c;
case 0x0c03f43eu: goto P_0c03f43e;
case 0x0c03f440u: goto P_0c03f440;
case 0x0c03f442u: goto P_0c03f442;
case 0x0c03f444u: goto P_0c03f444;
case 0x0c03f446u: goto P_0c03f446;
case 0x0c03f448u: goto P_0c03f448;
case 0x0c03f44au: goto P_0c03f44a;
case 0x0c03f44cu: goto P_0c03f44c;
case 0x0c03f44eu: goto P_0c03f44e;
case 0x0c03f450u: goto P_0c03f450;
case 0x0c03f452u: goto P_0c03f452;
case 0x0c03f454u: goto P_0c03f454;
case 0x0c03f456u: goto P_0c03f456;
case 0x0c03f458u: goto P_0c03f458;
case 0x0c03f45au: goto P_0c03f45a;
case 0x0c03f45cu: goto P_0c03f45c;
case 0x0c03f45eu: goto P_0c03f45e;
case 0x0c03f460u: goto P_0c03f460;
case 0x0c03f462u: goto P_0c03f462;
case 0x0c03f464u: goto P_0c03f464;
case 0x0c03f466u: goto P_0c03f466;
case 0x0c03f468u: goto P_0c03f468;
case 0x0c03f46au: goto P_0c03f46a;
case 0x0c03f46cu: goto P_0c03f46c;
case 0x0c03f46eu: goto P_0c03f46e;
case 0x0c03f470u: goto P_0c03f470;
case 0x0c03f472u: goto P_0c03f472;
case 0x0c03f474u: goto P_0c03f474;
case 0x0c03f476u: goto P_0c03f476;
case 0x0c03f478u: goto P_0c03f478;
case 0x0c03f47au: goto P_0c03f47a;
case 0x0c03f47cu: goto P_0c03f47c;
case 0x0c03f47eu: goto P_0c03f47e;
case 0x0c03f480u: goto P_0c03f480;
case 0x0c03f482u: goto P_0c03f482;
case 0x0c03f484u: goto P_0c03f484;
case 0x0c03f486u: goto P_0c03f486;
case 0x0c03f488u: goto P_0c03f488;
case 0x0c03f48au: goto P_0c03f48a;
case 0x0c03f48cu: goto P_0c03f48c;
case 0x0c03f48eu: goto P_0c03f48e;
case 0x0c03f490u: goto P_0c03f490;
case 0x0c03f492u: goto P_0c03f492;
case 0x0c03f494u: goto P_0c03f494;
case 0x0c03f496u: goto P_0c03f496;
case 0x0c03f498u: goto P_0c03f498;
case 0x0c03f49au: goto P_0c03f49a;
case 0x0c03f49cu: goto P_0c03f49c;
case 0x0c03f49eu: goto P_0c03f49e;
case 0x0c03f4a0u: goto P_0c03f4a0;
case 0x0c03f4a2u: goto P_0c03f4a2;
case 0x0c03f4a4u: goto P_0c03f4a4;
case 0x0c03f4a6u: goto P_0c03f4a6;
case 0x0c03f4a8u: goto P_0c03f4a8;
case 0x0c03f4aau: goto P_0c03f4aa;
case 0x0c03f4acu: goto P_0c03f4ac;
case 0x0c03f4aeu: goto P_0c03f4ae;
case 0x0c03f4b0u: goto P_0c03f4b0;
case 0x0c03f4b2u: goto P_0c03f4b2;
case 0x0c03f4b4u: goto P_0c03f4b4;
case 0x0c03f4b6u: goto P_0c03f4b6;
case 0x0c03f4b8u: goto P_0c03f4b8;
case 0x0c03f4bau: goto P_0c03f4ba;
case 0x0c03f4bcu: goto P_0c03f4bc;
case 0x0c03f4beu: goto P_0c03f4be;
case 0x0c03f4c0u: goto P_0c03f4c0;
case 0x0c03f4c2u: goto P_0c03f4c2;
case 0x0c03f4c4u: goto P_0c03f4c4;
case 0x0c03f4c6u: goto P_0c03f4c6;
case 0x0c03f4c8u: goto P_0c03f4c8;
case 0x0c03f4cau: goto P_0c03f4ca;
case 0x0c03f4ccu: goto P_0c03f4cc;
case 0x0c03f4ceu: goto P_0c03f4ce;
case 0x0c03f4d0u: goto P_0c03f4d0;
case 0x0c03f4d2u: goto P_0c03f4d2;
case 0x0c03f4d4u: goto P_0c03f4d4;
case 0x0c03f4d6u: goto P_0c03f4d6;
case 0x0c03f4d8u: goto P_0c03f4d8;
case 0x0c03f4dau: goto P_0c03f4da;
case 0x0c03f4dcu: goto P_0c03f4dc;
case 0x0c03fd02u: goto P_0c03fd02;
case 0x0c03fd04u: goto P_0c03fd04;
case 0x0c03fd06u: goto P_0c03fd06;
case 0x0c03fd08u: goto P_0c03fd08;
case 0x0c03fd0au: goto P_0c03fd0a;
case 0x0c03fd10u: goto P_0c03fd10;
case 0x0c03fd12u: goto P_0c03fd12;
case 0x0c03fd14u: goto P_0c03fd14;
case 0x0c03fd16u: goto P_0c03fd16;
case 0x0c03fd18u: goto P_0c03fd18;
case 0x0c03fd1au: goto P_0c03fd1a;
case 0x0c03fd1cu: goto P_0c03fd1c;
case 0x0c03fd1eu: goto P_0c03fd1e;
case 0x0c03fd20u: goto P_0c03fd20;
case 0x0c03fd22u: goto P_0c03fd22;
case 0x0c03fd24u: goto P_0c03fd24;
case 0x0c03fd26u: goto P_0c03fd26;
case 0x0c03fd28u: goto P_0c03fd28;
case 0x0c03fd2au: goto P_0c03fd2a;
case 0x0c03fd2cu: goto P_0c03fd2c;
case 0x0c03fd2eu: goto P_0c03fd2e;
case 0x0c03fd30u: goto P_0c03fd30;
case 0x0c03fd32u: goto P_0c03fd32;
case 0x0c03fd34u: goto P_0c03fd34;
case 0x0c03fd36u: goto P_0c03fd36;
case 0x0c03fd38u: goto P_0c03fd38;
case 0x0c03fd3au: goto P_0c03fd3a;
case 0x0c03fd3cu: goto P_0c03fd3c;
case 0x0c03fd3eu: goto P_0c03fd3e;
case 0x0c03fd40u: goto P_0c03fd40;
case 0x0c03fd42u: goto P_0c03fd42;
case 0x0c03fd44u: goto P_0c03fd44;
case 0x0c03fd70u: goto P_0c03fd70;
case 0x0c03fd72u: goto P_0c03fd72;
case 0x0c03fd74u: goto P_0c03fd74;
case 0x0c03fd76u: goto P_0c03fd76;
case 0x0c03fd78u: goto P_0c03fd78;
case 0x0c03fd7au: goto P_0c03fd7a;
case 0x0c03fd7cu: goto P_0c03fd7c;
case 0x0c03fd7eu: goto P_0c03fd7e;
case 0x0c03fd80u: goto P_0c03fd80;
case 0x0c03fd82u: goto P_0c03fd82;
case 0x0c03fd84u: goto P_0c03fd84;
case 0x0c03fd86u: goto P_0c03fd86;
case 0x0c03fd88u: goto P_0c03fd88;
case 0x0c03fd8au: goto P_0c03fd8a;
case 0x0c03fd8cu: goto P_0c03fd8c;
case 0x0c03fd8eu: goto P_0c03fd8e;
case 0x0c03fd90u: goto P_0c03fd90;
case 0x0c03fd92u: goto P_0c03fd92;
case 0x0c03fd94u: goto P_0c03fd94;
case 0x0c040154u: goto P_0c040154;
case 0x0c040156u: goto P_0c040156;
case 0x0c040158u: goto P_0c040158;
case 0x0c04015au: goto P_0c04015a;
case 0x0c04015cu: goto P_0c04015c;
case 0x0c04015eu: goto P_0c04015e;
case 0x0c040160u: goto P_0c040160;
case 0x0c040162u: goto P_0c040162;
case 0x0c040164u: goto P_0c040164;
case 0x0c040166u: goto P_0c040166;
case 0x0c040168u: goto P_0c040168;
case 0x0c04016au: goto P_0c04016a;
case 0x0c04016cu: goto P_0c04016c;
case 0x0c04016eu: goto P_0c04016e;
case 0x0c040174u: goto P_0c040174;
case 0x0c040176u: goto P_0c040176;
case 0x0c040178u: goto P_0c040178;
case 0x0c04017au: goto P_0c04017a;
case 0x0c04017cu: goto P_0c04017c;
case 0x0c04017eu: goto P_0c04017e;
case 0x0c040180u: goto P_0c040180;
case 0x0c040182u: goto P_0c040182;
case 0x0c040184u: goto P_0c040184;
case 0x0c040186u: goto P_0c040186;
case 0x0c040188u: goto P_0c040188;
case 0x0c04018au: goto P_0c04018a;
case 0x0c04018cu: goto P_0c04018c;
case 0x0c04018eu: goto P_0c04018e;
case 0x0c040190u: goto P_0c040190;
case 0x0c040192u: goto P_0c040192;
case 0x0c040194u: goto P_0c040194;
case 0x0c040196u: goto P_0c040196;
case 0x0c040198u: goto P_0c040198;
case 0x0c04019au: goto P_0c04019a;
case 0x0c04019cu: goto P_0c04019c;
case 0x0c04019eu: goto P_0c04019e;
case 0x0c0401a0u: goto P_0c0401a0;
case 0x0c0401a2u: goto P_0c0401a2;
case 0x0c0401a4u: goto P_0c0401a4;
case 0x0c0401a6u: goto P_0c0401a6;
case 0x0c0401a8u: goto P_0c0401a8;
case 0x0c0401aau: goto P_0c0401aa;
case 0x0c0401acu: goto P_0c0401ac;
case 0x0c0401aeu: goto P_0c0401ae;
case 0x0c0401b0u: goto P_0c0401b0;
case 0x0c0401b2u: goto P_0c0401b2;
case 0x0c0401b4u: goto P_0c0401b4;
case 0x0c0401b6u: goto P_0c0401b6;
case 0x0c0401b8u: goto P_0c0401b8;
case 0x0c0401bau: goto P_0c0401ba;
case 0x0c0401bcu: goto P_0c0401bc;
case 0x0c0401beu: goto P_0c0401be;
case 0x0c0401c0u: goto P_0c0401c0;
case 0x0c0401c2u: goto P_0c0401c2;
case 0x0c0401c4u: goto P_0c0401c4;
case 0x0c0401c6u: goto P_0c0401c6;
case 0x0c0401c8u: goto P_0c0401c8;
case 0x0c0401cau: goto P_0c0401ca;
case 0x0c0401ccu: goto P_0c0401cc;
case 0x0c0401ceu: goto P_0c0401ce;
case 0x0c0401d0u: goto P_0c0401d0;
case 0x0c0401d2u: goto P_0c0401d2;
case 0x0c0401d4u: goto P_0c0401d4;
case 0x0c0401d6u: goto P_0c0401d6;
case 0x0c0401d8u: goto P_0c0401d8;
case 0x0c0401dau: goto P_0c0401da;
case 0x0c0401dcu: goto P_0c0401dc;
case 0x0c0401deu: goto P_0c0401de;
case 0x0c0401e0u: goto P_0c0401e0;
case 0x0c0401e2u: goto P_0c0401e2;
case 0x0c0401e4u: goto P_0c0401e4;
case 0x0c0401e6u: goto P_0c0401e6;
case 0x0c0401e8u: goto P_0c0401e8;
case 0x0c0401eau: goto P_0c0401ea;
case 0x0c0401ecu: goto P_0c0401ec;
case 0x0c0401eeu: goto P_0c0401ee;
case 0x0c0401f0u: goto P_0c0401f0;
case 0x0c0401f2u: goto P_0c0401f2;
case 0x0c0401f4u: goto P_0c0401f4;
case 0x0c0401f6u: goto P_0c0401f6;
case 0x0c0401f8u: goto P_0c0401f8;
case 0x0c0401fau: goto P_0c0401fa;
case 0x0c0401fcu: goto P_0c0401fc;
case 0x0c0401feu: goto P_0c0401fe;
case 0x0c040200u: goto P_0c040200;
case 0x0c040202u: goto P_0c040202;
case 0x0c040204u: goto P_0c040204;
case 0x0c040206u: goto P_0c040206;
case 0x0c040222u: goto P_0c040222;
case 0x0c040224u: goto P_0c040224;
case 0x0c040226u: goto P_0c040226;
case 0x0c040228u: goto P_0c040228;
case 0x0c04022au: goto P_0c04022a;
case 0x0c04022cu: goto P_0c04022c;
case 0x0c04022eu: goto P_0c04022e;
case 0x0c040230u: goto P_0c040230;
case 0x0c040232u: goto P_0c040232;
case 0x0c040234u: goto P_0c040234;
case 0x0c040236u: goto P_0c040236;
case 0x0c040238u: goto P_0c040238;
case 0x0c04023au: goto P_0c04023a;
case 0x0c04023cu: goto P_0c04023c;
case 0x0c04023eu: goto P_0c04023e;
case 0x0c040240u: goto P_0c040240;
case 0x0c040242u: goto P_0c040242;
case 0x0c040244u: goto P_0c040244;
case 0x0c040246u: goto P_0c040246;
case 0x0c040248u: goto P_0c040248;
case 0x0c04024au: goto P_0c04024a;
case 0x0c04024cu: goto P_0c04024c;
case 0x0c04024eu: goto P_0c04024e;
case 0x0c040250u: goto P_0c040250;
case 0x0c040252u: goto P_0c040252;
case 0x0c040254u: goto P_0c040254;
case 0x0c040256u: goto P_0c040256;
case 0x0c040258u: goto P_0c040258;
case 0x0c04025au: goto P_0c04025a;
case 0x0c04025cu: goto P_0c04025c;
case 0x0c04025eu: goto P_0c04025e;
case 0x0c040260u: goto P_0c040260;
case 0x0c040262u: goto P_0c040262;
case 0x0c040264u: goto P_0c040264;
case 0x0c040266u: goto P_0c040266;
case 0x0c040268u: goto P_0c040268;
case 0x0c04026au: goto P_0c04026a;
case 0x0c04026cu: goto P_0c04026c;
case 0x0c04026eu: goto P_0c04026e;
case 0x0c040270u: goto P_0c040270;
case 0x0c040272u: goto P_0c040272;
case 0x0c040274u: goto P_0c040274;
case 0x0c040276u: goto P_0c040276;
case 0x0c040288u: goto P_0c040288;
case 0x0c04028au: goto P_0c04028a;
case 0x0c04028cu: goto P_0c04028c;
case 0x0c04028eu: goto P_0c04028e;
case 0x0c040290u: goto P_0c040290;
case 0x0c040292u: goto P_0c040292;
case 0x0c040294u: goto P_0c040294;
case 0x0c040296u: goto P_0c040296;
case 0x0c040298u: goto P_0c040298;
case 0x0c04029au: goto P_0c04029a;
case 0x0c04029cu: goto P_0c04029c;
case 0x0c04029eu: goto P_0c04029e;
case 0x0c0402a0u: goto P_0c0402a0;
case 0x0c0402a2u: goto P_0c0402a2;
case 0x0c0402a4u: goto P_0c0402a4;
case 0x0c0402a6u: goto P_0c0402a6;
case 0x0c0402a8u: goto P_0c0402a8;
case 0x0c0402aau: goto P_0c0402aa;
case 0x0c0402acu: goto P_0c0402ac;
case 0x0c0402aeu: goto P_0c0402ae;
case 0x0c0402b0u: goto P_0c0402b0;
case 0x0c0402b2u: goto P_0c0402b2;
case 0x0c0402b4u: goto P_0c0402b4;
case 0x0c0402b6u: goto P_0c0402b6;
case 0x0c0402b8u: goto P_0c0402b8;
case 0x0c0402bau: goto P_0c0402ba;
case 0x0c0402bcu: goto P_0c0402bc;
case 0x0c0402beu: goto P_0c0402be;
case 0x0c0402c0u: goto P_0c0402c0;
case 0x0c0402c2u: goto P_0c0402c2;
case 0x0c0402c4u: goto P_0c0402c4;
case 0x0c0402c6u: goto P_0c0402c6;
case 0x0c0402c8u: goto P_0c0402c8;
case 0x0c0402cau: goto P_0c0402ca;
case 0x0c0402ccu: goto P_0c0402cc;
case 0x0c0402ceu: goto P_0c0402ce;
case 0x0c0402d0u: goto P_0c0402d0;
case 0x0c0402d2u: goto P_0c0402d2;
case 0x0c0402d4u: goto P_0c0402d4;
case 0x0c0402d6u: goto P_0c0402d6;
case 0x0c0402d8u: goto P_0c0402d8;
case 0x0c0402dau: goto P_0c0402da;
case 0x0c0402dcu: goto P_0c0402dc;
case 0x0c0402deu: goto P_0c0402de;
case 0x0c0402e0u: goto P_0c0402e0;
case 0x0c0402e2u: goto P_0c0402e2;
case 0x0c0402e4u: goto P_0c0402e4;
case 0x0c0402e6u: goto P_0c0402e6;
case 0x0c0402e8u: goto P_0c0402e8;
case 0x0c0402eau: goto P_0c0402ea;
case 0x0c0402ecu: goto P_0c0402ec;
case 0x0c0402eeu: goto P_0c0402ee;
case 0x0c0402f0u: goto P_0c0402f0;
case 0x0c0402f2u: goto P_0c0402f2;
case 0x0c0402f4u: goto P_0c0402f4;
case 0x0c0402f6u: goto P_0c0402f6;
case 0x0c0402f8u: goto P_0c0402f8;
case 0x0c040308u: goto P_0c040308;
case 0x0c04030au: goto P_0c04030a;
case 0x0c04030cu: goto P_0c04030c;
case 0x0c04030eu: goto P_0c04030e;
case 0x0c040310u: goto P_0c040310;
case 0x0c040312u: goto P_0c040312;
case 0x0c040314u: goto P_0c040314;
case 0x0c040316u: goto P_0c040316;
case 0x0c040318u: goto P_0c040318;
case 0x0c04031au: goto P_0c04031a;
case 0x0c04031cu: goto P_0c04031c;
case 0x0c04031eu: goto P_0c04031e;
case 0x0c040320u: goto P_0c040320;
case 0x0c040322u: goto P_0c040322;
case 0x0c040324u: goto P_0c040324;
case 0x0c040326u: goto P_0c040326;
case 0x0c040328u: goto P_0c040328;
case 0x0c04032au: goto P_0c04032a;
case 0x0c04032cu: goto P_0c04032c;
case 0x0c04032eu: goto P_0c04032e;
case 0x0c040330u: goto P_0c040330;
case 0x0c040332u: goto P_0c040332;
case 0x0c040334u: goto P_0c040334;
case 0x0c040336u: goto P_0c040336;
case 0x0c040338u: goto P_0c040338;
case 0x0c04033au: goto P_0c04033a;
case 0x0c04033cu: goto P_0c04033c;
case 0x0c04033eu: goto P_0c04033e;
case 0x0c040340u: goto P_0c040340;
case 0x0c040342u: goto P_0c040342;
case 0x0c040344u: goto P_0c040344;
case 0x0c040346u: goto P_0c040346;
case 0x0c040348u: goto P_0c040348;
case 0x0c04034au: goto P_0c04034a;
case 0x0c04034cu: goto P_0c04034c;
case 0x0c04034eu: goto P_0c04034e;
case 0x0c040350u: goto P_0c040350;
case 0x0c040352u: goto P_0c040352;
case 0x0c040354u: goto P_0c040354;
case 0x0c040356u: goto P_0c040356;
case 0x0c040358u: goto P_0c040358;
case 0x0c04035au: goto P_0c04035a;
case 0x0c04035cu: goto P_0c04035c;
case 0x0c04035eu: goto P_0c04035e;
case 0x0c040360u: goto P_0c040360;
case 0x0c040362u: goto P_0c040362;
case 0x0c0406b8u: goto P_0c0406b8;
case 0x0c0406bau: goto P_0c0406ba;
case 0x0c0406bcu: goto P_0c0406bc;
case 0x0c0406beu: goto P_0c0406be;
case 0x0c0406c0u: goto P_0c0406c0;
case 0x0c0406c2u: goto P_0c0406c2;
case 0x0c0406c4u: goto P_0c0406c4;
case 0x0c0406c6u: goto P_0c0406c6;
case 0x0c0406c8u: goto P_0c0406c8;
case 0x0c0406cau: goto P_0c0406ca;
case 0x0c0406ccu: goto P_0c0406cc;
case 0x0c0406ceu: goto P_0c0406ce;
case 0x0c0406d0u: goto P_0c0406d0;
case 0x0c0406d2u: goto P_0c0406d2;
case 0x0c0406d4u: goto P_0c0406d4;
case 0x0c0406d6u: goto P_0c0406d6;
case 0x0c0406d8u: goto P_0c0406d8;
case 0x0c0406dau: goto P_0c0406da;
case 0x0c0406dcu: goto P_0c0406dc;
case 0x0c0406deu: goto P_0c0406de;
case 0x0c0406e0u: goto P_0c0406e0;
case 0x0c0406e2u: goto P_0c0406e2;
case 0x0c0406e4u: goto P_0c0406e4;
case 0x0c0406e6u: goto P_0c0406e6;
case 0x0c0406e8u: goto P_0c0406e8;
case 0x0c0406eau: goto P_0c0406ea;
case 0x0c0406ecu: goto P_0c0406ec;
case 0x0c0406eeu: goto P_0c0406ee;
case 0x0c0406f0u: goto P_0c0406f0;
case 0x0c0406f2u: goto P_0c0406f2;
case 0x0c0406f4u: goto P_0c0406f4;
case 0x0c0406f6u: goto P_0c0406f6;
case 0x0c0406f8u: goto P_0c0406f8;
case 0x0c0406fau: goto P_0c0406fa;
case 0x0c0406fcu: goto P_0c0406fc;
case 0x0c0406feu: goto P_0c0406fe;
case 0x0c040700u: goto P_0c040700;
case 0x0c040702u: goto P_0c040702;
case 0x0c040704u: goto P_0c040704;
case 0x0c040706u: goto P_0c040706;
case 0x0c040708u: goto P_0c040708;
case 0x0c04070au: goto P_0c04070a;
case 0x0c040714u: goto P_0c040714;
case 0x0c040716u: goto P_0c040716;
case 0x0c040718u: goto P_0c040718;
case 0x0c04071au: goto P_0c04071a;
case 0x0c04071cu: goto P_0c04071c;
case 0x0c04071eu: goto P_0c04071e;
case 0x0c040720u: goto P_0c040720;
case 0x0c040722u: goto P_0c040722;
case 0x0c040724u: goto P_0c040724;
case 0x0c040726u: goto P_0c040726;
case 0x0c040728u: goto P_0c040728;
case 0x0c04072au: goto P_0c04072a;
case 0x0c04072cu: goto P_0c04072c;
case 0x0c04072eu: goto P_0c04072e;
case 0x0c040730u: goto P_0c040730;
case 0x0c040732u: goto P_0c040732;
case 0x0c040734u: goto P_0c040734;
case 0x0c040736u: goto P_0c040736;
case 0x0c040738u: goto P_0c040738;
case 0x0c04073au: goto P_0c04073a;
case 0x0c04073cu: goto P_0c04073c;
case 0x0c04073eu: goto P_0c04073e;
case 0x0c040740u: goto P_0c040740;
case 0x0c040742u: goto P_0c040742;
case 0x0c040744u: goto P_0c040744;
case 0x0c040746u: goto P_0c040746;
case 0x0c040748u: goto P_0c040748;
case 0x0c04074au: goto P_0c04074a;
case 0x0c04074cu: goto P_0c04074c;
case 0x0c04074eu: goto P_0c04074e;
case 0x0c040750u: goto P_0c040750;
case 0x0c040752u: goto P_0c040752;
case 0x0c040754u: goto P_0c040754;
case 0x0c040756u: goto P_0c040756;
case 0x0c040758u: goto P_0c040758;
case 0x0c04075au: goto P_0c04075a;
case 0x0c04075cu: goto P_0c04075c;
case 0x0c04075eu: goto P_0c04075e;
case 0x0c040760u: goto P_0c040760;
case 0x0c040762u: goto P_0c040762;
case 0x0c040764u: goto P_0c040764;
case 0x0c040766u: goto P_0c040766;
case 0x0c040768u: goto P_0c040768;
case 0x0c04076au: goto P_0c04076a;
case 0x0c04076cu: goto P_0c04076c;
case 0x0c04076eu: goto P_0c04076e;
case 0x0c040770u: goto P_0c040770;
case 0x0c040772u: goto P_0c040772;
case 0x0c040774u: goto P_0c040774;
case 0x0c040776u: goto P_0c040776;
case 0x0c040778u: goto P_0c040778;
case 0x0c04077au: goto P_0c04077a;
case 0x0c04077cu: goto P_0c04077c;
case 0x0c04077eu: goto P_0c04077e;
case 0x0c040780u: goto P_0c040780;
case 0x0c040782u: goto P_0c040782;
case 0x0c040784u: goto P_0c040784;
case 0x0c040786u: goto P_0c040786;
case 0x0c040788u: goto P_0c040788;
case 0x0c04078au: goto P_0c04078a;
case 0x0c04078cu: goto P_0c04078c;
case 0x0c04078eu: goto P_0c04078e;
case 0x0c040790u: goto P_0c040790;
case 0x0c040792u: goto P_0c040792;
case 0x0c040794u: goto P_0c040794;
case 0x0c040796u: goto P_0c040796;
case 0x0c040798u: goto P_0c040798;
case 0x0c04079au: goto P_0c04079a;
case 0x0c04079cu: goto P_0c04079c;
case 0x0c04079eu: goto P_0c04079e;
case 0x0c0407b0u: goto P_0c0407b0;
case 0x0c0407b2u: goto P_0c0407b2;
case 0x0c0407b4u: goto P_0c0407b4;
case 0x0c0407b6u: goto P_0c0407b6;
case 0x0c0407b8u: goto P_0c0407b8;
case 0x0c0407bau: goto P_0c0407ba;
case 0x0c0407bcu: goto P_0c0407bc;
case 0x0c0407beu: goto P_0c0407be;
case 0x0c0407c0u: goto P_0c0407c0;
case 0x0c0407c2u: goto P_0c0407c2;
case 0x0c0407c4u: goto P_0c0407c4;
case 0x0c0407c6u: goto P_0c0407c6;
case 0x0c0407c8u: goto P_0c0407c8;
case 0x0c040b7eu: goto P_0c040b7e;
case 0x0c040b80u: goto P_0c040b80;
case 0x0c040b82u: goto P_0c040b82;
case 0x0c040b84u: goto P_0c040b84;
case 0x0c040b86u: goto P_0c040b86;
case 0x0c040b88u: goto P_0c040b88;
case 0x0c040b8au: goto P_0c040b8a;
case 0x0c040b8cu: goto P_0c040b8c;
case 0x0c040b8eu: goto P_0c040b8e;
case 0x0c040b90u: goto P_0c040b90;
case 0x0c040b92u: goto P_0c040b92;
case 0x0c040b94u: goto P_0c040b94;
case 0x0c040b96u: goto P_0c040b96;
case 0x0c040b98u: goto P_0c040b98;
case 0x0c040b9au: goto P_0c040b9a;
case 0x0c040b9cu: goto P_0c040b9c;
case 0x0c040b9eu: goto P_0c040b9e;
case 0x0c040ba0u: goto P_0c040ba0;
case 0x0c040ba2u: goto P_0c040ba2;
case 0x0c040ba4u: goto P_0c040ba4;
case 0x0c040ba6u: goto P_0c040ba6;
case 0x0c040ba8u: goto P_0c040ba8;
case 0x0c040baau: goto P_0c040baa;
case 0x0c040bacu: goto P_0c040bac;
case 0x0c040baeu: goto P_0c040bae;
case 0x0c040bb0u: goto P_0c040bb0;
case 0x0c040bb2u: goto P_0c040bb2;
case 0x0c040bb4u: goto P_0c040bb4;
case 0x0c040bb6u: goto P_0c040bb6;
case 0x0c040bb8u: goto P_0c040bb8;
case 0x0c040bbau: goto P_0c040bba;
case 0x0c040bbcu: goto P_0c040bbc;
case 0x0c040bbeu: goto P_0c040bbe;
case 0x0c040bc0u: goto P_0c040bc0;
case 0x0c040bc2u: goto P_0c040bc2;
case 0x0c040bc4u: goto P_0c040bc4;
case 0x0c040bc6u: goto P_0c040bc6;
case 0x0c040bc8u: goto P_0c040bc8;
case 0x0c040bcau: goto P_0c040bca;
case 0x0c040bccu: goto P_0c040bcc;
case 0x0c040bceu: goto P_0c040bce;
case 0x0c040bd0u: goto P_0c040bd0;
case 0x0c040bd2u: goto P_0c040bd2;
case 0x0c040bd4u: goto P_0c040bd4;
case 0x0c040bd6u: goto P_0c040bd6;
case 0x0c040bd8u: goto P_0c040bd8;
case 0x0c040bdau: goto P_0c040bda;
case 0x0c040bdcu: goto P_0c040bdc;
case 0x0c040bdeu: goto P_0c040bde;
case 0x0c040be0u: goto P_0c040be0;
case 0x0c040be2u: goto P_0c040be2;
case 0x0c040be4u: goto P_0c040be4;
case 0x0c040be6u: goto P_0c040be6;
case 0x0c040be8u: goto P_0c040be8;
case 0x0c040beau: goto P_0c040bea;
case 0x0c040becu: goto P_0c040bec;
case 0x0c040beeu: goto P_0c040bee;
case 0x0c040bf0u: goto P_0c040bf0;
case 0x0c040bf2u: goto P_0c040bf2;
case 0x0c040bf4u: goto P_0c040bf4;
case 0x0c040bf6u: goto P_0c040bf6;
case 0x0c040c10u: goto P_0c040c10;
case 0x0c040c12u: goto P_0c040c12;
case 0x0c040c14u: goto P_0c040c14;
case 0x0c040c16u: goto P_0c040c16;
case 0x0c040c18u: goto P_0c040c18;
case 0x0c040c1au: goto P_0c040c1a;
case 0x0c040c1cu: goto P_0c040c1c;
case 0x0c040c1eu: goto P_0c040c1e;
case 0x0c040c20u: goto P_0c040c20;
case 0x0c040c22u: goto P_0c040c22;
case 0x0c040c24u: goto P_0c040c24;
case 0x0c040c26u: goto P_0c040c26;
case 0x0c040c28u: goto P_0c040c28;
case 0x0c040c2au: goto P_0c040c2a;
case 0x0c040c2cu: goto P_0c040c2c;
case 0x0c040c2eu: goto P_0c040c2e;
case 0x0c040c30u: goto P_0c040c30;
case 0x0c040c32u: goto P_0c040c32;
case 0x0c040c34u: goto P_0c040c34;
case 0x0c040c36u: goto P_0c040c36;
case 0x0c040c38u: goto P_0c040c38;
case 0x0c040c3au: goto P_0c040c3a;
case 0x0c040c3cu: goto P_0c040c3c;
case 0x0c040c3eu: goto P_0c040c3e;
case 0x0c040c40u: goto P_0c040c40;
case 0x0c040c42u: goto P_0c040c42;
case 0x0c040c44u: goto P_0c040c44;
case 0x0c040c46u: goto P_0c040c46;
case 0x0c040c48u: goto P_0c040c48;
case 0x0c040c4au: goto P_0c040c4a;
case 0x0c040c4cu: goto P_0c040c4c;
case 0x0c040c4eu: goto P_0c040c4e;
case 0x0c040c50u: goto P_0c040c50;
case 0x0c040c52u: goto P_0c040c52;
case 0x0c040c54u: goto P_0c040c54;
case 0x0c040c56u: goto P_0c040c56;
case 0x0c040c58u: goto P_0c040c58;
case 0x0c040c5au: goto P_0c040c5a;
case 0x0c040c5cu: goto P_0c040c5c;
case 0x0c040c5eu: goto P_0c040c5e;
case 0x0c040c60u: goto P_0c040c60;
case 0x0c040c62u: goto P_0c040c62;
case 0x0c040c64u: goto P_0c040c64;
case 0x0c040c66u: goto P_0c040c66;
case 0x0c040c68u: goto P_0c040c68;
case 0x0c040c6au: goto P_0c040c6a;
case 0x0c040c6cu: goto P_0c040c6c;
case 0x0c040c6eu: goto P_0c040c6e;
case 0x0c040c70u: goto P_0c040c70;
case 0x0c040c72u: goto P_0c040c72;
case 0x0c040c74u: goto P_0c040c74;
case 0x0c040c76u: goto P_0c040c76;
case 0x0c0431eau: goto P_0c0431ea;
case 0x0c0431ecu: goto P_0c0431ec;
case 0x0c0431eeu: goto P_0c0431ee;
case 0x0c0431f0u: goto P_0c0431f0;
case 0x0c0431f2u: goto P_0c0431f2;
case 0x0c0431f4u: goto P_0c0431f4;
case 0x0c0431f6u: goto P_0c0431f6;
case 0x0c0431f8u: goto P_0c0431f8;
case 0x0c0431fau: goto P_0c0431fa;
case 0x0c0431fcu: goto P_0c0431fc;
case 0x0c0431feu: goto P_0c0431fe;
case 0x0c043200u: goto P_0c043200;
case 0x0c043202u: goto P_0c043202;
case 0x0c043204u: goto P_0c043204;
case 0x0c043206u: goto P_0c043206;
case 0x0c043208u: goto P_0c043208;
case 0x0c04320au: goto P_0c04320a;
case 0x0c04320cu: goto P_0c04320c;
case 0x0c04320eu: goto P_0c04320e;
case 0x0c043210u: goto P_0c043210;
case 0x0c043212u: goto P_0c043212;
case 0x0c043214u: goto P_0c043214;
case 0x0c043216u: goto P_0c043216;
case 0x0c043218u: goto P_0c043218;
case 0x0c04321au: goto P_0c04321a;
case 0x0c04321cu: goto P_0c04321c;
case 0x0c04321eu: goto P_0c04321e;
case 0x0c043220u: goto P_0c043220;
case 0x0c043222u: goto P_0c043222;
case 0x0c043224u: goto P_0c043224;
case 0x0c043226u: goto P_0c043226;
case 0x0c043228u: goto P_0c043228;
case 0x0c04322au: goto P_0c04322a;
case 0x0c04322cu: goto P_0c04322c;
case 0x0c04322eu: goto P_0c04322e;
case 0x0c043230u: goto P_0c043230;
case 0x0c043232u: goto P_0c043232;
case 0x0c043234u: goto P_0c043234;
case 0x0c043236u: goto P_0c043236;
case 0x0c043238u: goto P_0c043238;
case 0x0c04323au: goto P_0c04323a;
case 0x0c04323cu: goto P_0c04323c;
case 0x0c04323eu: goto P_0c04323e;
case 0x0c043240u: goto P_0c043240;
case 0x0c043242u: goto P_0c043242;
case 0x0c043244u: goto P_0c043244;
case 0x0c043246u: goto P_0c043246;
case 0x0c043248u: goto P_0c043248;
case 0x0c04324au: goto P_0c04324a;
case 0x0c04324cu: goto P_0c04324c;
case 0x0c04324eu: goto P_0c04324e;
case 0x0c043250u: goto P_0c043250;
case 0x0c043252u: goto P_0c043252;
case 0x0c043254u: goto P_0c043254;
case 0x0c043256u: goto P_0c043256;
case 0x0c043258u: goto P_0c043258;
case 0x0c04325au: goto P_0c04325a;
case 0x0c04325cu: goto P_0c04325c;
case 0x0c04325eu: goto P_0c04325e;
case 0x0c043260u: goto P_0c043260;
case 0x0c043262u: goto P_0c043262;
case 0x0c043264u: goto P_0c043264;
case 0x0c043266u: goto P_0c043266;
case 0x0c043268u: goto P_0c043268;
case 0x0c0432e2u: goto P_0c0432e2;
case 0x0c0432e4u: goto P_0c0432e4;
case 0x0c0432e6u: goto P_0c0432e6;
case 0x0c0432e8u: goto P_0c0432e8;
case 0x0c0432eau: goto P_0c0432ea;
case 0x0c0432ecu: goto P_0c0432ec;
case 0x0c0432eeu: goto P_0c0432ee;
case 0x0c0432f0u: goto P_0c0432f0;
case 0x0c0432f2u: goto P_0c0432f2;
case 0x0c0432f4u: goto P_0c0432f4;
case 0x0c0432f6u: goto P_0c0432f6;
case 0x0c0432f8u: goto P_0c0432f8;
case 0x0c0432fau: goto P_0c0432fa;
case 0x0c0432fcu: goto P_0c0432fc;
case 0x0c0432feu: goto P_0c0432fe;
case 0x0c043300u: goto P_0c043300;
case 0x0c043302u: goto P_0c043302;
case 0x0c043304u: goto P_0c043304;
case 0x0c043306u: goto P_0c043306;
case 0x0c043308u: goto P_0c043308;
case 0x0c04330au: goto P_0c04330a;
case 0x0c04330cu: goto P_0c04330c;
case 0x0c04330eu: goto P_0c04330e;
case 0x0c043310u: goto P_0c043310;
case 0x0c043312u: goto P_0c043312;
case 0x0c043314u: goto P_0c043314;
case 0x0c043316u: goto P_0c043316;
case 0x0c043318u: goto P_0c043318;
case 0x0c04331au: goto P_0c04331a;
case 0x0c04331cu: goto P_0c04331c;
case 0x0c04331eu: goto P_0c04331e;
case 0x0c043320u: goto P_0c043320;
case 0x0c043322u: goto P_0c043322;
case 0x0c043324u: goto P_0c043324;
case 0x0c043344u: goto P_0c043344;
case 0x0c043346u: goto P_0c043346;
case 0x0c043348u: goto P_0c043348;
case 0x0c04334au: goto P_0c04334a;
case 0x0c04334cu: goto P_0c04334c;
case 0x0c04334eu: goto P_0c04334e;
case 0x0c043350u: goto P_0c043350;
case 0x0c043352u: goto P_0c043352;
case 0x0c043354u: goto P_0c043354;
case 0x0c043356u: goto P_0c043356;
case 0x0c043358u: goto P_0c043358;
case 0x0c04335au: goto P_0c04335a;
case 0x0c04335cu: goto P_0c04335c;
case 0x0c0433aeu: goto P_0c0433ae;
case 0x0c0433b0u: goto P_0c0433b0;
case 0x0c0433b2u: goto P_0c0433b2;
case 0x0c0433b4u: goto P_0c0433b4;
case 0x0c0433b6u: goto P_0c0433b6;
case 0x0c0433b8u: goto P_0c0433b8;
case 0x0c0433bau: goto P_0c0433ba;
case 0x0c04363eu: goto P_0c04363e;
case 0x0c043640u: goto P_0c043640;
case 0x0c043642u: goto P_0c043642;
case 0x0c043644u: goto P_0c043644;
case 0x0c043646u: goto P_0c043646;
case 0x0c043648u: goto P_0c043648;
case 0x0c04364au: goto P_0c04364a;
case 0x0c04364cu: goto P_0c04364c;
case 0x0c04364eu: goto P_0c04364e;
case 0x0c043650u: goto P_0c043650;
case 0x0c043652u: goto P_0c043652;
case 0x0c043654u: goto P_0c043654;
case 0x0c043656u: goto P_0c043656;
case 0x0c043658u: goto P_0c043658;
case 0x0c04365au: goto P_0c04365a;
case 0x0c04365cu: goto P_0c04365c;
case 0x0c04365eu: goto P_0c04365e;
case 0x0c043660u: goto P_0c043660;
case 0x0c043662u: goto P_0c043662;
case 0x0c043664u: goto P_0c043664;
case 0x0c043666u: goto P_0c043666;
case 0x0c043668u: goto P_0c043668;
case 0x0c04366au: goto P_0c04366a;
case 0x0c04366cu: goto P_0c04366c;
case 0x0c04366eu: goto P_0c04366e;
case 0x0c043670u: goto P_0c043670;
case 0x0c043672u: goto P_0c043672;
case 0x0c043674u: goto P_0c043674;
case 0x0c043676u: goto P_0c043676;
case 0x0c043678u: goto P_0c043678;
case 0x0c04367au: goto P_0c04367a;
case 0x0c04367cu: goto P_0c04367c;
case 0x0c04367eu: goto P_0c04367e;
case 0x0c043680u: goto P_0c043680;
case 0x0c043682u: goto P_0c043682;
case 0x0c043684u: goto P_0c043684;
case 0x0c043686u: goto P_0c043686;
case 0x0c043688u: goto P_0c043688;
case 0x0c04368au: goto P_0c04368a;
case 0x0c04368cu: goto P_0c04368c;
case 0x0c04368eu: goto P_0c04368e;
case 0x0c043690u: goto P_0c043690;
case 0x0c043692u: goto P_0c043692;
case 0x0c043694u: goto P_0c043694;
case 0x0c043696u: goto P_0c043696;
case 0x0c043698u: goto P_0c043698;
case 0x0c04369au: goto P_0c04369a;
case 0x0c04369cu: goto P_0c04369c;
case 0x0c04369eu: goto P_0c04369e;
case 0x0c0436a0u: goto P_0c0436a0;
case 0x0c0436a2u: goto P_0c0436a2;
case 0x0c0436a4u: goto P_0c0436a4;
case 0x0c0436a6u: goto P_0c0436a6;
case 0x0c0436a8u: goto P_0c0436a8;
case 0x0c0436aau: goto P_0c0436aa;
case 0x0c0436acu: goto P_0c0436ac;
case 0x0c0436aeu: goto P_0c0436ae;
case 0x0c0436b0u: goto P_0c0436b0;
case 0x0c0436b2u: goto P_0c0436b2;
case 0x0c0436b4u: goto P_0c0436b4;
case 0x0c0436b6u: goto P_0c0436b6;
case 0x0c0436b8u: goto P_0c0436b8;
case 0x0c0436bau: goto P_0c0436ba;
case 0x0c0436bcu: goto P_0c0436bc;
case 0x0c0436beu: goto P_0c0436be;
case 0x0c0436c0u: goto P_0c0436c0;
case 0x0c0436c2u: goto P_0c0436c2;
case 0x0c0436c4u: goto P_0c0436c4;
case 0x0c0436c6u: goto P_0c0436c6;
case 0x0c0437aeu: goto P_0c0437ae;
case 0x0c0437b0u: goto P_0c0437b0;
case 0x0c0437b2u: goto P_0c0437b2;
case 0x0c0437b4u: goto P_0c0437b4;
case 0x0c0437b6u: goto P_0c0437b6;
case 0x0c0437b8u: goto P_0c0437b8;
case 0x0c0437bau: goto P_0c0437ba;
case 0x0c0437bcu: goto P_0c0437bc;
case 0x0c0437beu: goto P_0c0437be;
case 0x0c0437c0u: goto P_0c0437c0;
case 0x0c0437c2u: goto P_0c0437c2;
case 0x0c0437c4u: goto P_0c0437c4;
case 0x0c0437c6u: goto P_0c0437c6;
case 0x0c0437c8u: goto P_0c0437c8;
case 0x0c0437cau: goto P_0c0437ca;
case 0x0c0437ccu: goto P_0c0437cc;
case 0x0c0437ceu: goto P_0c0437ce;
case 0x0c0437d0u: goto P_0c0437d0;
case 0x0c0437d2u: goto P_0c0437d2;
case 0x0c0437d4u: goto P_0c0437d4;
case 0x0c0437d6u: goto P_0c0437d6;
case 0x0c0437d8u: goto P_0c0437d8;
case 0x0c0437dau: goto P_0c0437da;
case 0x0c0437dcu: goto P_0c0437dc;
case 0x0c0437deu: goto P_0c0437de;
case 0x0c0437e0u: goto P_0c0437e0;
case 0x0c0437e2u: goto P_0c0437e2;
case 0x0c0437e4u: goto P_0c0437e4;
case 0x0c0437e6u: goto P_0c0437e6;
case 0x0c0437e8u: goto P_0c0437e8;
case 0x0c0437eau: goto P_0c0437ea;
case 0x0c0437ecu: goto P_0c0437ec;
case 0x0c0437eeu: goto P_0c0437ee;
case 0x0c0437f0u: goto P_0c0437f0;
case 0x0c0437f2u: goto P_0c0437f2;
case 0x0c0437f4u: goto P_0c0437f4;
case 0x0c0437f8u: goto P_0c0437f8;
case 0x0c0437fau: goto P_0c0437fa;
case 0x0c0437fcu: goto P_0c0437fc;
case 0x0c0437feu: goto P_0c0437fe;
case 0x0c043800u: goto P_0c043800;
case 0x0c043802u: goto P_0c043802;
case 0x0c043804u: goto P_0c043804;
case 0x0c043806u: goto P_0c043806;
case 0x0c043808u: goto P_0c043808;
case 0x0c04380au: goto P_0c04380a;
case 0x0c04380cu: goto P_0c04380c;
case 0x0c04380eu: goto P_0c04380e;
case 0x0c043810u: goto P_0c043810;
case 0x0c043812u: goto P_0c043812;
case 0x0c0460eau: goto P_0c0460ea;
case 0x0c0460ecu: goto P_0c0460ec;
case 0x0c0460eeu: goto P_0c0460ee;
case 0x0c0460f0u: goto P_0c0460f0;
case 0x0c0460f2u: goto P_0c0460f2;
case 0x0c0460f4u: goto P_0c0460f4;
case 0x0c0460f6u: goto P_0c0460f6;
case 0x0c0460f8u: goto P_0c0460f8;
case 0x0c0460fau: goto P_0c0460fa;
case 0x0c0460fcu: goto P_0c0460fc;
case 0x0c0460feu: goto P_0c0460fe;
case 0x0c046100u: goto P_0c046100;
case 0x0c046102u: goto P_0c046102;
case 0x0c046104u: goto P_0c046104;
case 0x0c046106u: goto P_0c046106;
case 0x0c046108u: goto P_0c046108;
case 0x0c04610au: goto P_0c04610a;
case 0x0c04610cu: goto P_0c04610c;
case 0x0c04610eu: goto P_0c04610e;
case 0x0c046110u: goto P_0c046110;
case 0x0c046112u: goto P_0c046112;
case 0x0c046114u: goto P_0c046114;
case 0x0c046116u: goto P_0c046116;
case 0x0c046118u: goto P_0c046118;
case 0x0c04611au: goto P_0c04611a;
case 0x0c04611cu: goto P_0c04611c;
case 0x0c04611eu: goto P_0c04611e;
case 0x0c046120u: goto P_0c046120;
case 0x0c046122u: goto P_0c046122;
case 0x0c046124u: goto P_0c046124;
case 0x0c046126u: goto P_0c046126;
case 0x0c046128u: goto P_0c046128;
case 0x0c04612au: goto P_0c04612a;
case 0x0c04612cu: goto P_0c04612c;
case 0x0c04612eu: goto P_0c04612e;
case 0x0c046130u: goto P_0c046130;
case 0x0c046132u: goto P_0c046132;
case 0x0c046134u: goto P_0c046134;
case 0x0c046136u: goto P_0c046136;
case 0x0c046138u: goto P_0c046138;
case 0x0c04613au: goto P_0c04613a;
case 0x0c04613cu: goto P_0c04613c;
case 0x0c04613eu: goto P_0c04613e;
case 0x0c046140u: goto P_0c046140;
case 0x0c046142u: goto P_0c046142;
case 0x0c046144u: goto P_0c046144;
case 0x0c046146u: goto P_0c046146;
case 0x0c046148u: goto P_0c046148;
case 0x0c04614au: goto P_0c04614a;
case 0x0c04614cu: goto P_0c04614c;
case 0x0c04614eu: goto P_0c04614e;
case 0x0c046150u: goto P_0c046150;
case 0x0c046152u: goto P_0c046152;
case 0x0c046154u: goto P_0c046154;
case 0x0c046156u: goto P_0c046156;
case 0x0c046158u: goto P_0c046158;
case 0x0c04615au: goto P_0c04615a;
case 0x0c04615cu: goto P_0c04615c;
case 0x0c04615eu: goto P_0c04615e;
case 0x0c046160u: goto P_0c046160;
case 0x0c046162u: goto P_0c046162;
case 0x0c046164u: goto P_0c046164;
case 0x0c046166u: goto P_0c046166;
case 0x0c046168u: goto P_0c046168;
case 0x0c04616au: goto P_0c04616a;
case 0x0c04616cu: goto P_0c04616c;
case 0x0c04616eu: goto P_0c04616e;
case 0x0c046170u: goto P_0c046170;
case 0x0c046172u: goto P_0c046172;
case 0x0c046174u: goto P_0c046174;
case 0x0c046176u: goto P_0c046176;
case 0x0c046178u: goto P_0c046178;
case 0x0c04617au: goto P_0c04617a;
case 0x0c04617cu: goto P_0c04617c;
case 0x0c04617eu: goto P_0c04617e;
case 0x0c047340u: goto P_0c047340;
case 0x0c047342u: goto P_0c047342;
case 0x0c047344u: goto P_0c047344;
case 0x0c047346u: goto P_0c047346;
case 0x0c047348u: goto P_0c047348;
case 0x0c04734au: goto P_0c04734a;
case 0x0c04734cu: goto P_0c04734c;
case 0x0c04734eu: goto P_0c04734e;
case 0x0c047350u: goto P_0c047350;
case 0x0c047352u: goto P_0c047352;
case 0x0c047354u: goto P_0c047354;
case 0x0c047356u: goto P_0c047356;
case 0x0c047358u: goto P_0c047358;
case 0x0c04735au: goto P_0c04735a;
case 0x0c04735cu: goto P_0c04735c;
case 0x0c047360u: goto P_0c047360;
case 0x0c047362u: goto P_0c047362;
case 0x0c047364u: goto P_0c047364;
case 0x0c047366u: goto P_0c047366;
case 0x0c047368u: goto P_0c047368;
case 0x0c04736au: goto P_0c04736a;
case 0x0c04736cu: goto P_0c04736c;
case 0x0c04736eu: goto P_0c04736e;
case 0x0c047370u: goto P_0c047370;
case 0x0c047372u: goto P_0c047372;
case 0x0c047374u: goto P_0c047374;
case 0x0c047376u: goto P_0c047376;
case 0x0c047378u: goto P_0c047378;
case 0x0c04737au: goto P_0c04737a;
case 0x0c04737cu: goto P_0c04737c;
case 0x0c04737eu: goto P_0c04737e;
case 0x0c047380u: goto P_0c047380;
case 0x0c047382u: goto P_0c047382;
case 0x0c047384u: goto P_0c047384;
case 0x0c047386u: goto P_0c047386;
case 0x0c047388u: goto P_0c047388;
case 0x0c047390u: goto P_0c047390;
case 0x0c047392u: goto P_0c047392;
case 0x0c047394u: goto P_0c047394;
case 0x0c047396u: goto P_0c047396;
case 0x0c047398u: goto P_0c047398;
case 0x0c04739au: goto P_0c04739a;
case 0x0c04739cu: goto P_0c04739c;
case 0x0c04739eu: goto P_0c04739e;
case 0x0c0473a0u: goto P_0c0473a0;
case 0x0c0473a2u: goto P_0c0473a2;
case 0x0c0473a4u: goto P_0c0473a4;
case 0x0c0473a6u: goto P_0c0473a6;
case 0x0c0473a8u: goto P_0c0473a8;
case 0x0c0473aau: goto P_0c0473aa;
case 0x0c0473acu: goto P_0c0473ac;
case 0x0c0482f0u: goto P_0c0482f0;
case 0x0c0482f2u: goto P_0c0482f2;
case 0x0c0482f4u: goto P_0c0482f4;
case 0x0c0482f6u: goto P_0c0482f6;
case 0x0c0482f8u: goto P_0c0482f8;
case 0x0c0482fau: goto P_0c0482fa;
case 0x0c0482fcu: goto P_0c0482fc;
case 0x0c0482feu: goto P_0c0482fe;
case 0x0c048300u: goto P_0c048300;
case 0x0c048302u: goto P_0c048302;
case 0x0c048304u: goto P_0c048304;
case 0x0c048306u: goto P_0c048306;
case 0x0c048308u: goto P_0c048308;
case 0x0c04830au: goto P_0c04830a;
case 0x0c04830cu: goto P_0c04830c;
case 0x0c04830eu: goto P_0c04830e;
case 0x0c048310u: goto P_0c048310;
case 0x0c048312u: goto P_0c048312;
case 0x0c048314u: goto P_0c048314;
case 0x0c048316u: goto P_0c048316;
case 0x0c048318u: goto P_0c048318;
case 0x0c04831au: goto P_0c04831a;
case 0x0c04831cu: goto P_0c04831c;
case 0x0c04831eu: goto P_0c04831e;
case 0x0c048320u: goto P_0c048320;
case 0x0c048322u: goto P_0c048322;
case 0x0c048324u: goto P_0c048324;
case 0x0c048326u: goto P_0c048326;
case 0x0c048328u: goto P_0c048328;
case 0x0c04832au: goto P_0c04832a;
case 0x0c04832cu: goto P_0c04832c;
case 0x0c04832eu: goto P_0c04832e;
case 0x0c048330u: goto P_0c048330;
case 0x0c048332u: goto P_0c048332;
case 0x0c048334u: goto P_0c048334;
case 0x0c048336u: goto P_0c048336;
case 0x0c048338u: goto P_0c048338;
case 0x0c04833au: goto P_0c04833a;
case 0x0c04833cu: goto P_0c04833c;
case 0x0c04833eu: goto P_0c04833e;
case 0x0c048340u: goto P_0c048340;
case 0x0c048342u: goto P_0c048342;
case 0x0c048344u: goto P_0c048344;
case 0x0c048346u: goto P_0c048346;
case 0x0c048348u: goto P_0c048348;
case 0x0c04834au: goto P_0c04834a;
case 0x0c04834cu: goto P_0c04834c;
case 0x0c04834eu: goto P_0c04834e;
case 0x0c048350u: goto P_0c048350;
case 0x0c048352u: goto P_0c048352;
case 0x0c048354u: goto P_0c048354;
case 0x0c048356u: goto P_0c048356;
case 0x0c048358u: goto P_0c048358;
case 0x0c04835au: goto P_0c04835a;
case 0x0c04835cu: goto P_0c04835c;
case 0x0c04835eu: goto P_0c04835e;
case 0x0c048360u: goto P_0c048360;
case 0x0c048362u: goto P_0c048362;
case 0x0c048364u: goto P_0c048364;
case 0x0c048366u: goto P_0c048366;
case 0x0c048368u: goto P_0c048368;
case 0x0c04836au: goto P_0c04836a;
case 0x0c04836cu: goto P_0c04836c;
case 0x0c04836eu: goto P_0c04836e;
case 0x0c048370u: goto P_0c048370;
case 0x0c048372u: goto P_0c048372;
case 0x0c048374u: goto P_0c048374;
case 0x0c048376u: goto P_0c048376;
case 0x0c048378u: goto P_0c048378;
case 0x0c04837au: goto P_0c04837a;
case 0x0c04837cu: goto P_0c04837c;
case 0x0c04837eu: goto P_0c04837e;
case 0x0c048380u: goto P_0c048380;
case 0x0c048382u: goto P_0c048382;
case 0x0c048384u: goto P_0c048384;
case 0x0c048386u: goto P_0c048386;
case 0x0c048388u: goto P_0c048388;
case 0x0c04838au: goto P_0c04838a;
case 0x0c04838cu: goto P_0c04838c;
case 0x0c04838eu: goto P_0c04838e;
case 0x0c048390u: goto P_0c048390;
case 0x0c048392u: goto P_0c048392;
case 0x0c048394u: goto P_0c048394;
case 0x0c048396u: goto P_0c048396;
case 0x0c048398u: goto P_0c048398;
case 0x0c04839au: goto P_0c04839a;
case 0x0c04839cu: goto P_0c04839c;
case 0x0c0483a0u: goto P_0c0483a0;
case 0x0c0483a2u: goto P_0c0483a2;
case 0x0c0483a4u: goto P_0c0483a4;
case 0x0c0483a6u: goto P_0c0483a6;
case 0x0c0483a8u: goto P_0c0483a8;
case 0x0c0483aau: goto P_0c0483aa;
case 0x0c0483acu: goto P_0c0483ac;
case 0x0c0483aeu: goto P_0c0483ae;
case 0x0c0483b0u: goto P_0c0483b0;
case 0x0c0483b2u: goto P_0c0483b2;
case 0x0c0483b4u: goto P_0c0483b4;
case 0x0c0483b6u: goto P_0c0483b6;
case 0x0c0483b8u: goto P_0c0483b8;
case 0x0c0483bau: goto P_0c0483ba;
case 0x0c0483bcu: goto P_0c0483bc;
case 0x0c0483beu: goto P_0c0483be;
case 0x0c0483c0u: goto P_0c0483c0;
case 0x0c0483c2u: goto P_0c0483c2;
case 0x0c0483c4u: goto P_0c0483c4;
case 0x0c0483c6u: goto P_0c0483c6;
case 0x0c0483c8u: goto P_0c0483c8;
case 0x0c0483cau: goto P_0c0483ca;
case 0x0c0483ccu: goto P_0c0483cc;
case 0x0c0483ceu: goto P_0c0483ce;
case 0x0c0483d0u: goto P_0c0483d0;
case 0x0c0483d2u: goto P_0c0483d2;
case 0x0c0483d4u: goto P_0c0483d4;
case 0x0c0483d6u: goto P_0c0483d6;
case 0x0c0483d8u: goto P_0c0483d8;
case 0x0c0483dau: goto P_0c0483da;
case 0x0c0483dcu: goto P_0c0483dc;
case 0x0c0483deu: goto P_0c0483de;
case 0x0c0483e0u: goto P_0c0483e0;
case 0x0c0483e2u: goto P_0c0483e2;
case 0x0c0483e4u: goto P_0c0483e4;
case 0x0c0483e6u: goto P_0c0483e6;
case 0x0c0483e8u: goto P_0c0483e8;
case 0x0c0483eau: goto P_0c0483ea;
case 0x0c0483ecu: goto P_0c0483ec;
case 0x0c0483eeu: goto P_0c0483ee;
case 0x0c0483f0u: goto P_0c0483f0;
case 0x0c0483f2u: goto P_0c0483f2;
case 0x0c0483f4u: goto P_0c0483f4;
case 0x0c0483f6u: goto P_0c0483f6;
case 0x0c0483f8u: goto P_0c0483f8;
case 0x0c0483fau: goto P_0c0483fa;
case 0x0c0483fcu: goto P_0c0483fc;
case 0x0c0483feu: goto P_0c0483fe;
case 0x0c048400u: goto P_0c048400;
case 0x0c048402u: goto P_0c048402;
case 0x0c048404u: goto P_0c048404;
case 0x0c048408u: goto P_0c048408;
case 0x0c04840au: goto P_0c04840a;
case 0x0c04840cu: goto P_0c04840c;
case 0x0c04840eu: goto P_0c04840e;
case 0x0c048410u: goto P_0c048410;
case 0x0c048412u: goto P_0c048412;
case 0x0c048414u: goto P_0c048414;
case 0x0c048416u: goto P_0c048416;
case 0x0c048418u: goto P_0c048418;
case 0x0c04841au: goto P_0c04841a;
case 0x0c04841cu: goto P_0c04841c;
case 0x0c04841eu: goto P_0c04841e;
case 0x0c048420u: goto P_0c048420;
case 0x0c048422u: goto P_0c048422;
case 0x0c048424u: goto P_0c048424;
case 0x0c048426u: goto P_0c048426;
case 0x0c048428u: goto P_0c048428;
case 0x0c04842au: goto P_0c04842a;
case 0x0c04842cu: goto P_0c04842c;
case 0x0c04842eu: goto P_0c04842e;
case 0x0c048430u: goto P_0c048430;
case 0x0c048432u: goto P_0c048432;
case 0x0c048434u: goto P_0c048434;
case 0x0c048436u: goto P_0c048436;
case 0x0c048438u: goto P_0c048438;
case 0x0c04843au: goto P_0c04843a;
case 0x0c04843cu: goto P_0c04843c;
case 0x0c04843eu: goto P_0c04843e;
case 0x0c048440u: goto P_0c048440;
case 0x0c048442u: goto P_0c048442;
case 0x0c048444u: goto P_0c048444;
case 0x0c048446u: goto P_0c048446;
case 0x0c048448u: goto P_0c048448;
case 0x0c04844au: goto P_0c04844a;
case 0x0c04844cu: goto P_0c04844c;
case 0x0c04844eu: goto P_0c04844e;
case 0x0c048450u: goto P_0c048450;
case 0x0c048452u: goto P_0c048452;
case 0x0c048454u: goto P_0c048454;
case 0x0c048456u: goto P_0c048456;
case 0x0c048458u: goto P_0c048458;
case 0x0c04845au: goto P_0c04845a;
case 0x0c04845cu: goto P_0c04845c;
case 0x0c04845eu: goto P_0c04845e;
case 0x0c048460u: goto P_0c048460;
case 0x0c048462u: goto P_0c048462;
case 0x0c048464u: goto P_0c048464;
case 0x0c048466u: goto P_0c048466;
case 0x0c048468u: goto P_0c048468;
case 0x0c04846au: goto P_0c04846a;
case 0x0c04846cu: goto P_0c04846c;
case 0x0c04846eu: goto P_0c04846e;
case 0x0c048470u: goto P_0c048470;
case 0x0c048472u: goto P_0c048472;
case 0x0c048474u: goto P_0c048474;
case 0x0c048476u: goto P_0c048476;
case 0x0c048478u: goto P_0c048478;
case 0x0c04847au: goto P_0c04847a;
case 0x0c04847cu: goto P_0c04847c;
case 0x0c04847eu: goto P_0c04847e;
case 0x0c048480u: goto P_0c048480;
case 0x0c048482u: goto P_0c048482;
case 0x0c048484u: goto P_0c048484;
case 0x0c048486u: goto P_0c048486;
case 0x0c048488u: goto P_0c048488;
case 0x0c04848au: goto P_0c04848a;
case 0x0c04848cu: goto P_0c04848c;
case 0x0c04848eu: goto P_0c04848e;
case 0x0c048490u: goto P_0c048490;
case 0x0c048492u: goto P_0c048492;
case 0x0c048494u: goto P_0c048494;
case 0x0c048496u: goto P_0c048496;
case 0x0c048498u: goto P_0c048498;
case 0x0c04849au: goto P_0c04849a;
case 0x0c04849cu: goto P_0c04849c;
case 0x0c04849eu: goto P_0c04849e;
case 0x0c0484a0u: goto P_0c0484a0;
case 0x0c0484a2u: goto P_0c0484a2;
case 0x0c0484a4u: goto P_0c0484a4;
case 0x0c0484a8u: goto P_0c0484a8;
case 0x0c0484aau: goto P_0c0484aa;
case 0x0c0484acu: goto P_0c0484ac;
case 0x0c0484aeu: goto P_0c0484ae;
case 0x0c0484b0u: goto P_0c0484b0;
case 0x0c0484b2u: goto P_0c0484b2;
case 0x0c0484b4u: goto P_0c0484b4;
case 0x0c0484b6u: goto P_0c0484b6;
case 0x0c0484b8u: goto P_0c0484b8;
case 0x0c0484bau: goto P_0c0484ba;
case 0x0c0484bcu: goto P_0c0484bc;
case 0x0c0484beu: goto P_0c0484be;
case 0x0c0484c0u: goto P_0c0484c0;
case 0x0c0484c4u: goto P_0c0484c4;
case 0x0c0484c6u: goto P_0c0484c6;
case 0x0c0484c8u: goto P_0c0484c8;
case 0x0c0484cau: goto P_0c0484ca;
case 0x0c0484ccu: goto P_0c0484cc;
case 0x0c0484ceu: goto P_0c0484ce;
case 0x0c0484d0u: goto P_0c0484d0;
case 0x0c0484d2u: goto P_0c0484d2;
case 0x0c0484d4u: goto P_0c0484d4;
case 0x0c0484d6u: goto P_0c0484d6;
case 0x0c0484d8u: goto P_0c0484d8;
case 0x0c0484dau: goto P_0c0484da;
case 0x0c0484dcu: goto P_0c0484dc;
case 0x0c0484deu: goto P_0c0484de;
case 0x0c0484e0u: goto P_0c0484e0;
case 0x0c0484e2u: goto P_0c0484e2;
case 0x0c0484e4u: goto P_0c0484e4;
case 0x0c0484e6u: goto P_0c0484e6;
case 0x0c0484e8u: goto P_0c0484e8;
case 0x0c0484eau: goto P_0c0484ea;
case 0x0c0484ecu: goto P_0c0484ec;
case 0x0c0484eeu: goto P_0c0484ee;
case 0x0c0484f0u: goto P_0c0484f0;
case 0x0c0484f4u: goto P_0c0484f4;
case 0x0c0484f6u: goto P_0c0484f6;
case 0x0c0484f8u: goto P_0c0484f8;
case 0x0c0484fau: goto P_0c0484fa;
case 0x0c0484fcu: goto P_0c0484fc;
case 0x0c0484feu: goto P_0c0484fe;
case 0x0c048500u: goto P_0c048500;
case 0x0c048502u: goto P_0c048502;
case 0x0c048504u: goto P_0c048504;
case 0x0c048506u: goto P_0c048506;
case 0x0c048508u: goto P_0c048508;
case 0x0c04850au: goto P_0c04850a;
case 0x0c04850cu: goto P_0c04850c;
case 0x0c04850eu: goto P_0c04850e;
case 0x0c048510u: goto P_0c048510;
case 0x0c048512u: goto P_0c048512;
case 0x0c048514u: goto P_0c048514;
case 0x0c048516u: goto P_0c048516;
case 0x0c048518u: goto P_0c048518;
case 0x0c04851au: goto P_0c04851a;
case 0x0c04851cu: goto P_0c04851c;
case 0x0c04851eu: goto P_0c04851e;
case 0x0c048520u: goto P_0c048520;
case 0x0c048522u: goto P_0c048522;
case 0x0c048524u: goto P_0c048524;
case 0x0c048526u: goto P_0c048526;
case 0x0c048528u: goto P_0c048528;
case 0x0c04852au: goto P_0c04852a;
case 0x0c04852cu: goto P_0c04852c;
case 0x0c04852eu: goto P_0c04852e;
case 0x0c048530u: goto P_0c048530;
case 0x0c048532u: goto P_0c048532;
case 0x0c048534u: goto P_0c048534;
case 0x0c048536u: goto P_0c048536;
case 0x0c048538u: goto P_0c048538;
case 0x0c04853au: goto P_0c04853a;
case 0x0c04853cu: goto P_0c04853c;
case 0x0c04853eu: goto P_0c04853e;
case 0x0c048540u: goto P_0c048540;
case 0x0c048542u: goto P_0c048542;
case 0x0c048544u: goto P_0c048544;
case 0x0c048546u: goto P_0c048546;
case 0x0c048548u: goto P_0c048548;
case 0x0c04854au: goto P_0c04854a;
case 0x0c04854cu: goto P_0c04854c;
case 0x0c04854eu: goto P_0c04854e;
case 0x0c048550u: goto P_0c048550;
case 0x0c048552u: goto P_0c048552;
case 0x0c048554u: goto P_0c048554;
case 0x0c048556u: goto P_0c048556;
case 0x0c048558u: goto P_0c048558;
case 0x0c04855au: goto P_0c04855a;
case 0x0c04855cu: goto P_0c04855c;
case 0x0c04855eu: goto P_0c04855e;
case 0x0c048560u: goto P_0c048560;
case 0x0c04856cu: goto P_0c04856c;
case 0x0c04856eu: goto P_0c04856e;
case 0x0c048570u: goto P_0c048570;
case 0x0c048572u: goto P_0c048572;
case 0x0c048574u: goto P_0c048574;
case 0x0c048576u: goto P_0c048576;
case 0x0c048578u: goto P_0c048578;
case 0x0c04857au: goto P_0c04857a;
case 0x0c04857cu: goto P_0c04857c;
case 0x0c04857eu: goto P_0c04857e;
case 0x0c048580u: goto P_0c048580;
case 0x0c048582u: goto P_0c048582;
case 0x0c048584u: goto P_0c048584;
case 0x0c048586u: goto P_0c048586;
case 0x0c048588u: goto P_0c048588;
case 0x0c04858au: goto P_0c04858a;
case 0x0c04858cu: goto P_0c04858c;
case 0x0c04858eu: goto P_0c04858e;
case 0x0c048590u: goto P_0c048590;
case 0x0c048592u: goto P_0c048592;
case 0x0c048594u: goto P_0c048594;
case 0x0c048596u: goto P_0c048596;
case 0x0c048598u: goto P_0c048598;
case 0x0c04859cu: goto P_0c04859c;
case 0x0c04859eu: goto P_0c04859e;
case 0x0c0485a0u: goto P_0c0485a0;
case 0x0c0485a2u: goto P_0c0485a2;
case 0x0c0485a4u: goto P_0c0485a4;
case 0x0c0485a6u: goto P_0c0485a6;
case 0x0c0485a8u: goto P_0c0485a8;
case 0x0c0485aau: goto P_0c0485aa;
case 0x0c0485acu: goto P_0c0485ac;
case 0x0c0485aeu: goto P_0c0485ae;
case 0x0c0485b0u: goto P_0c0485b0;
case 0x0c0485b2u: goto P_0c0485b2;
case 0x0c0485b4u: goto P_0c0485b4;
case 0x0c0485b6u: goto P_0c0485b6;
case 0x0c0485b8u: goto P_0c0485b8;
case 0x0c0485bcu: goto P_0c0485bc;
case 0x0c0485beu: goto P_0c0485be;
case 0x0c048dacu: goto P_0c048dac;
case 0x0c048daeu: goto P_0c048dae;
case 0x0c048e32u: goto P_0c048e32;
case 0x0c048e34u: goto P_0c048e34;
case 0x0c048e36u: goto P_0c048e36;
case 0x0c048e38u: goto P_0c048e38;
case 0x0c048e3au: goto P_0c048e3a;
case 0x0c048e3cu: goto P_0c048e3c;
case 0x0c048e3eu: goto P_0c048e3e;
case 0x0c048e40u: goto P_0c048e40;
case 0x0c048e42u: goto P_0c048e42;
case 0x0c048e44u: goto P_0c048e44;
case 0x0c048e46u: goto P_0c048e46;
case 0x0c048e48u: goto P_0c048e48;
case 0x0c048e4au: goto P_0c048e4a;
case 0x0c048e4cu: goto P_0c048e4c;
case 0x0c048e4eu: goto P_0c048e4e;
case 0x0c048e50u: goto P_0c048e50;
case 0x0c04bf3cu: goto P_0c04bf3c;
case 0x0c04bf3eu: goto P_0c04bf3e;
case 0x0c04bf40u: goto P_0c04bf40;
case 0x0c04bf42u: goto P_0c04bf42;
case 0x0c04bf44u: goto P_0c04bf44;
case 0x0c04bf46u: goto P_0c04bf46;
case 0x0c04bf48u: goto P_0c04bf48;
case 0x0c04bf4au: goto P_0c04bf4a;
case 0x0c04bf4cu: goto P_0c04bf4c;
case 0x0c04bf4eu: goto P_0c04bf4e;
case 0x0c04bf50u: goto P_0c04bf50;
case 0x0c04bf52u: goto P_0c04bf52;
case 0x0c04bf54u: goto P_0c04bf54;
case 0x0c04bf56u: goto P_0c04bf56;
case 0x0c04bf58u: goto P_0c04bf58;
case 0x0c04bf5au: goto P_0c04bf5a;
case 0x0c04bf5cu: goto P_0c04bf5c;
case 0x0c04bf5eu: goto P_0c04bf5e;
case 0x0c04bf60u: goto P_0c04bf60;
case 0x0c04bf62u: goto P_0c04bf62;
case 0x0c04bf64u: goto P_0c04bf64;
case 0x0c04bf66u: goto P_0c04bf66;
case 0x0c04bf68u: goto P_0c04bf68;
case 0x0c04bf6au: goto P_0c04bf6a;
case 0x0c04bf6cu: goto P_0c04bf6c;
case 0x0c04bf6eu: goto P_0c04bf6e;
case 0x0c04bf70u: goto P_0c04bf70;
case 0x0c04bf72u: goto P_0c04bf72;
case 0x0c04bf74u: goto P_0c04bf74;
case 0x0c04bf76u: goto P_0c04bf76;
case 0x0c04bf78u: goto P_0c04bf78;
case 0x0c04bf7au: goto P_0c04bf7a;
case 0x0c04bf7cu: goto P_0c04bf7c;
case 0x0c04bf7eu: goto P_0c04bf7e;
case 0x0c04bf80u: goto P_0c04bf80;
case 0x0c04bf82u: goto P_0c04bf82;
case 0x0c04bf84u: goto P_0c04bf84;
case 0x0c04bf86u: goto P_0c04bf86;
case 0x0c04bf88u: goto P_0c04bf88;
case 0x0c04bf8au: goto P_0c04bf8a;
case 0x0c04bf8cu: goto P_0c04bf8c;
case 0x0c04bf8eu: goto P_0c04bf8e;
case 0x0c04bf90u: goto P_0c04bf90;
case 0x0c04bf92u: goto P_0c04bf92;
case 0x0c04bf94u: goto P_0c04bf94;
case 0x0c04bf96u: goto P_0c04bf96;
case 0x0c04bf98u: goto P_0c04bf98;
case 0x0c04bf9au: goto P_0c04bf9a;
case 0x0c04bf9cu: goto P_0c04bf9c;
case 0x0c04bf9eu: goto P_0c04bf9e;
case 0x0c04bfa0u: goto P_0c04bfa0;
case 0x0c04bfa2u: goto P_0c04bfa2;
case 0x0c04bfa4u: goto P_0c04bfa4;
case 0x0c04bfa6u: goto P_0c04bfa6;
case 0x0c04bfa8u: goto P_0c04bfa8;
case 0x0c04bfaau: goto P_0c04bfaa;
case 0x0c04bfacu: goto P_0c04bfac;
case 0x0c04bfaeu: goto P_0c04bfae;
case 0x0c04bfb0u: goto P_0c04bfb0;
case 0x0c04bfb2u: goto P_0c04bfb2;
case 0x0c04bfb4u: goto P_0c04bfb4;
case 0x0c04bfb6u: goto P_0c04bfb6;
case 0x0c04bfb8u: goto P_0c04bfb8;
case 0x0c04bfbau: goto P_0c04bfba;
case 0x0c04bfbcu: goto P_0c04bfbc;
case 0x0c04bfbeu: goto P_0c04bfbe;
case 0x0c04bfc0u: goto P_0c04bfc0;
case 0x0c04bfc2u: goto P_0c04bfc2;
case 0x0c04bfc4u: goto P_0c04bfc4;
case 0x0c04bfc6u: goto P_0c04bfc6;
case 0x0c04bfc8u: goto P_0c04bfc8;
case 0x0c04bfcau: goto P_0c04bfca;
case 0x0c04bfccu: goto P_0c04bfcc;
case 0x0c04bfceu: goto P_0c04bfce;
case 0x0c04bfd0u: goto P_0c04bfd0;
case 0x0c04bfd2u: goto P_0c04bfd2;
case 0x0c04bfd4u: goto P_0c04bfd4;
case 0x0c04bfd6u: goto P_0c04bfd6;
case 0x0c04bfd8u: goto P_0c04bfd8;
case 0x0c04bfdau: goto P_0c04bfda;
case 0x0c04bfdcu: goto P_0c04bfdc;
case 0x0c04bfdeu: goto P_0c04bfde;
case 0x0c04bfe0u: goto P_0c04bfe0;
case 0x0c04bfe2u: goto P_0c04bfe2;
case 0x0c04bfe4u: goto P_0c04bfe4;
case 0x0c04bfe6u: goto P_0c04bfe6;
case 0x0c051f8eu: goto P_0c051f8e;
case 0x0c051f90u: goto P_0c051f90;
case 0x0c051f92u: goto P_0c051f92;
case 0x0c051f94u: goto P_0c051f94;
case 0x0c051f96u: goto P_0c051f96;
case 0x0c051f98u: goto P_0c051f98;
case 0x0c051f9au: goto P_0c051f9a;
case 0x0c051f9cu: goto P_0c051f9c;
case 0x0c051f9eu: goto P_0c051f9e;
case 0x0c051fa0u: goto P_0c051fa0;
case 0x0c051fa2u: goto P_0c051fa2;
case 0x0c051fa4u: goto P_0c051fa4;
case 0x0c051fa6u: goto P_0c051fa6;
case 0x0c051fa8u: goto P_0c051fa8;
case 0x0c051faau: goto P_0c051faa;
case 0x0c051facu: goto P_0c051fac;
case 0x0c051faeu: goto P_0c051fae;
case 0x0c051fb0u: goto P_0c051fb0;
case 0x0c051fb2u: goto P_0c051fb2;
case 0x0c051fb4u: goto P_0c051fb4;
case 0x0c051fb6u: goto P_0c051fb6;
case 0x0c051fb8u: goto P_0c051fb8;
case 0x0c051fbau: goto P_0c051fba;
case 0x0c051fbcu: goto P_0c051fbc;
case 0x0c051fbeu: goto P_0c051fbe;
case 0x0c051fc0u: goto P_0c051fc0;
case 0x0c051fc2u: goto P_0c051fc2;
case 0x0c051fc4u: goto P_0c051fc4;
case 0x0c051fc6u: goto P_0c051fc6;
case 0x0c051fc8u: goto P_0c051fc8;
case 0x0c051fcau: goto P_0c051fca;
case 0x0c051fccu: goto P_0c051fcc;
case 0x0c051fceu: goto P_0c051fce;
case 0x0c051fd0u: goto P_0c051fd0;
case 0x0c051fd2u: goto P_0c051fd2;
case 0x0c051fd4u: goto P_0c051fd4;
case 0x0c051fe0u: goto P_0c051fe0;
case 0x0c051fe2u: goto P_0c051fe2;
case 0x0c051fe4u: goto P_0c051fe4;
case 0x0c051fe6u: goto P_0c051fe6;
case 0x0c051fe8u: goto P_0c051fe8;
case 0x0c051feau: goto P_0c051fea;
case 0x0c051fecu: goto P_0c051fec;
case 0x0c051feeu: goto P_0c051fee;
case 0x0c051ff0u: goto P_0c051ff0;
case 0x0c051ff2u: goto P_0c051ff2;
case 0x0c051ff4u: goto P_0c051ff4;
case 0x0c051ff6u: goto P_0c051ff6;
case 0x0c051ff8u: goto P_0c051ff8;
case 0x0c051ffau: goto P_0c051ffa;
case 0x0c051ffcu: goto P_0c051ffc;
case 0x0c051ffeu: goto P_0c051ffe;
case 0x0c052000u: goto P_0c052000;
case 0x0c052002u: goto P_0c052002;
case 0x0c052004u: goto P_0c052004;
case 0x0c052006u: goto P_0c052006;
case 0x0c052008u: goto P_0c052008;
case 0x0c05200au: goto P_0c05200a;
case 0x0c05200cu: goto P_0c05200c;
case 0x0c05200eu: goto P_0c05200e;
case 0x0c052010u: goto P_0c052010;
case 0x0c052012u: goto P_0c052012;
case 0x0c052014u: goto P_0c052014;
case 0x0c052016u: goto P_0c052016;
case 0x0c052018u: goto P_0c052018;
case 0x0c05201au: goto P_0c05201a;
case 0x0c05201cu: goto P_0c05201c;
case 0x0c05201eu: goto P_0c05201e;
case 0x0c052020u: goto P_0c052020;
case 0x0c052022u: goto P_0c052022;
case 0x0c052024u: goto P_0c052024;
case 0x0c052026u: goto P_0c052026;
case 0x0c052028u: goto P_0c052028;
case 0x0c052034u: goto P_0c052034;
case 0x0c052036u: goto P_0c052036;
case 0x0c052038u: goto P_0c052038;
case 0x0c05203au: goto P_0c05203a;
case 0x0c05203cu: goto P_0c05203c;
case 0x0c05203eu: goto P_0c05203e;
case 0x0c052040u: goto P_0c052040;
case 0x0c052042u: goto P_0c052042;
case 0x0c052044u: goto P_0c052044;
case 0x0c052046u: goto P_0c052046;
case 0x0c052048u: goto P_0c052048;
case 0x0c05204au: goto P_0c05204a;
case 0x0c05204cu: goto P_0c05204c;
case 0x0c05204eu: goto P_0c05204e;
case 0x0c052050u: goto P_0c052050;
case 0x0c052052u: goto P_0c052052;
case 0x0c052054u: goto P_0c052054;
case 0x0c052056u: goto P_0c052056;
case 0x0c052058u: goto P_0c052058;
case 0x0c05205au: goto P_0c05205a;
case 0x0c05205cu: goto P_0c05205c;
case 0x0c05205eu: goto P_0c05205e;
case 0x0c052060u: goto P_0c052060;
case 0x0c052062u: goto P_0c052062;
case 0x0c052064u: goto P_0c052064;
case 0x0c052066u: goto P_0c052066;
case 0x0c052068u: goto P_0c052068;
case 0x0c05206au: goto P_0c05206a;
case 0x0c05206cu: goto P_0c05206c;
case 0x0c05206eu: goto P_0c05206e;
case 0x0c052070u: goto P_0c052070;
case 0x0c052078u: goto P_0c052078;
case 0x0c05207au: goto P_0c05207a;
case 0x0c05207cu: goto P_0c05207c;
case 0x0c05207eu: goto P_0c05207e;
case 0x0c052080u: goto P_0c052080;
case 0x0c052082u: goto P_0c052082;
case 0x0c052084u: goto P_0c052084;
case 0x0c052086u: goto P_0c052086;
case 0x0c052088u: goto P_0c052088;
case 0x0c05208au: goto P_0c05208a;
case 0x0c05208cu: goto P_0c05208c;
case 0x0c05208eu: goto P_0c05208e;
case 0x0c052090u: goto P_0c052090;
case 0x0c052092u: goto P_0c052092;
case 0x0c052094u: goto P_0c052094;
case 0x0c052096u: goto P_0c052096;
case 0x0c052098u: goto P_0c052098;
case 0x0c05209au: goto P_0c05209a;
case 0x0c05209cu: goto P_0c05209c;
case 0x0c05209eu: goto P_0c05209e;
case 0x0c0520a0u: goto P_0c0520a0;
case 0x0c0520a2u: goto P_0c0520a2;
case 0x0c0520a4u: goto P_0c0520a4;
case 0x0c0520a6u: goto P_0c0520a6;
case 0x0c0520a8u: goto P_0c0520a8;
case 0x0c0520aau: goto P_0c0520aa;
case 0x0c0520acu: goto P_0c0520ac;
case 0x0c0520aeu: goto P_0c0520ae;
case 0x0c0520b0u: goto P_0c0520b0;
case 0x0c0520b2u: goto P_0c0520b2;
case 0x0c0520b4u: goto P_0c0520b4;
case 0x0c0520b6u: goto P_0c0520b6;
case 0x0c0520b8u: goto P_0c0520b8;
case 0x0c0520bau: goto P_0c0520ba;
case 0x0c0520bcu: goto P_0c0520bc;
case 0x0c0520beu: goto P_0c0520be;
case 0x0c0520c0u: goto P_0c0520c0;
case 0x0c0520c2u: goto P_0c0520c2;
case 0x0c0520c4u: goto P_0c0520c4;
case 0x0c0520c6u: goto P_0c0520c6;
case 0x0c0520c8u: goto P_0c0520c8;
case 0x0c0520cau: goto P_0c0520ca;
case 0x0c0520ccu: goto P_0c0520cc;
case 0x0c0520ceu: goto P_0c0520ce;
case 0x0c0520d0u: goto P_0c0520d0;
case 0x0c0520d2u: goto P_0c0520d2;
case 0x0c0520d4u: goto P_0c0520d4;
case 0x0c0520d6u: goto P_0c0520d6;
case 0x0c0520d8u: goto P_0c0520d8;
case 0x0c0520dau: goto P_0c0520da;
case 0x0c0520dcu: goto P_0c0520dc;
case 0x0c0520deu: goto P_0c0520de;
case 0x0c0520e0u: goto P_0c0520e0;
case 0x0c0520e2u: goto P_0c0520e2;
case 0x0c0520e4u: goto P_0c0520e4;
case 0x0c0520e6u: goto P_0c0520e6;
case 0x0c0520e8u: goto P_0c0520e8;
case 0x0c0520f4u: goto P_0c0520f4;
case 0x0c0520f6u: goto P_0c0520f6;
case 0x0c0520f8u: goto P_0c0520f8;
case 0x0c0520fau: goto P_0c0520fa;
case 0x0c0520fcu: goto P_0c0520fc;
case 0x0c0520feu: goto P_0c0520fe;
case 0x0c052100u: goto P_0c052100;
case 0x0c052102u: goto P_0c052102;
case 0x0c052104u: goto P_0c052104;
case 0x0c052106u: goto P_0c052106;
case 0x0c052108u: goto P_0c052108;
case 0x0c05210au: goto P_0c05210a;
case 0x0c05210cu: goto P_0c05210c;
case 0x0c05210eu: goto P_0c05210e;
case 0x0c052110u: goto P_0c052110;
case 0x0c052112u: goto P_0c052112;
case 0x0c052114u: goto P_0c052114;
case 0x0c052116u: goto P_0c052116;
case 0x0c052118u: goto P_0c052118;
case 0x0c05211au: goto P_0c05211a;
case 0x0c05211cu: goto P_0c05211c;
case 0x0c05211eu: goto P_0c05211e;
case 0x0c052120u: goto P_0c052120;
case 0x0c052122u: goto P_0c052122;
case 0x0c052124u: goto P_0c052124;
case 0x0c052126u: goto P_0c052126;
case 0x0c052128u: goto P_0c052128;
case 0x0c05212au: goto P_0c05212a;
case 0x0c05212cu: goto P_0c05212c;
case 0x0c05212eu: goto P_0c05212e;
case 0x0c052130u: goto P_0c052130;
case 0x0c052132u: goto P_0c052132;
case 0x0c052134u: goto P_0c052134;
case 0x0c052136u: goto P_0c052136;
case 0x0c052138u: goto P_0c052138;
case 0x0c05213au: goto P_0c05213a;
case 0x0c05213cu: goto P_0c05213c;
case 0x0c05213eu: goto P_0c05213e;
case 0x0c052140u: goto P_0c052140;
case 0x0c052142u: goto P_0c052142;
case 0x0c052144u: goto P_0c052144;
case 0x0c052146u: goto P_0c052146;
case 0x0c052148u: goto P_0c052148;
case 0x0c05214au: goto P_0c05214a;
case 0x0c05214cu: goto P_0c05214c;
case 0x0c05214eu: goto P_0c05214e;
case 0x0c052150u: goto P_0c052150;
case 0x0c052152u: goto P_0c052152;
case 0x0c052154u: goto P_0c052154;
case 0x0c052156u: goto P_0c052156;
case 0x0c052158u: goto P_0c052158;
case 0x0c05215au: goto P_0c05215a;
case 0x0c05215cu: goto P_0c05215c;
case 0x0c05215eu: goto P_0c05215e;
case 0x0c052160u: goto P_0c052160;
case 0x0c052162u: goto P_0c052162;
case 0x0c052164u: goto P_0c052164;
case 0x0c052166u: goto P_0c052166;
case 0x0c052168u: goto P_0c052168;
case 0x0c05216au: goto P_0c05216a;
case 0x0c05216cu: goto P_0c05216c;
case 0x0c05216eu: goto P_0c05216e;
case 0x0c052170u: goto P_0c052170;
case 0x0c052172u: goto P_0c052172;
case 0x0c052174u: goto P_0c052174;
case 0x0c052176u: goto P_0c052176;
case 0x0c052178u: goto P_0c052178;
case 0x0c05217au: goto P_0c05217a;
case 0x0c05217cu: goto P_0c05217c;
case 0x0c05217eu: goto P_0c05217e;
case 0x0c052180u: goto P_0c052180;
case 0x0c052182u: goto P_0c052182;
case 0x0c052184u: goto P_0c052184;
case 0x0c052186u: goto P_0c052186;
case 0x0c052188u: goto P_0c052188;
case 0x0c05218au: goto P_0c05218a;
case 0x0c05218cu: goto P_0c05218c;
case 0x0c05218eu: goto P_0c05218e;
case 0x0c052190u: goto P_0c052190;
case 0x0c052192u: goto P_0c052192;
case 0x0c052194u: goto P_0c052194;
case 0x0c052196u: goto P_0c052196;
case 0x0c052198u: goto P_0c052198;
case 0x0c05219au: goto P_0c05219a;
case 0x0c05219cu: goto P_0c05219c;
case 0x0c05219eu: goto P_0c05219e;
case 0x0c0521a0u: goto P_0c0521a0;
case 0x0c0521a2u: goto P_0c0521a2;
case 0x0c0521a4u: goto P_0c0521a4;
case 0x0c0521a6u: goto P_0c0521a6;
case 0x0c0521a8u: goto P_0c0521a8;
case 0x0c052200u: goto P_0c052200;
case 0x0c052202u: goto P_0c052202;
case 0x0c052204u: goto P_0c052204;
case 0x0c052206u: goto P_0c052206;
case 0x0c052208u: goto P_0c052208;
case 0x0c05220au: goto P_0c05220a;
case 0x0c05220cu: goto P_0c05220c;
case 0x0c05220eu: goto P_0c05220e;
case 0x0c052210u: goto P_0c052210;
case 0x0c052212u: goto P_0c052212;
case 0x0c052214u: goto P_0c052214;
case 0x0c052216u: goto P_0c052216;
case 0x0c052218u: goto P_0c052218;
case 0x0c05221au: goto P_0c05221a;
case 0x0c05221cu: goto P_0c05221c;
case 0x0c05221eu: goto P_0c05221e;
case 0x0c052220u: goto P_0c052220;
case 0x0c052222u: goto P_0c052222;
case 0x0c052224u: goto P_0c052224;
case 0x0c052226u: goto P_0c052226;
case 0x0c052228u: goto P_0c052228;
case 0x0c05222au: goto P_0c05222a;
case 0x0c05222cu: goto P_0c05222c;
case 0x0c05222eu: goto P_0c05222e;
case 0x0c052230u: goto P_0c052230;
case 0x0c052232u: goto P_0c052232;
case 0x0c052234u: goto P_0c052234;
case 0x0c052236u: goto P_0c052236;
case 0x0c052238u: goto P_0c052238;
case 0x0c05223au: goto P_0c05223a;
case 0x0c05223cu: goto P_0c05223c;
case 0x0c05223eu: goto P_0c05223e;
case 0x0c052240u: goto P_0c052240;
case 0x0c052242u: goto P_0c052242;
case 0x0c052244u: goto P_0c052244;
case 0x0c052246u: goto P_0c052246;
case 0x0c052248u: goto P_0c052248;
case 0x0c05224au: goto P_0c05224a;
case 0x0c05224cu: goto P_0c05224c;
case 0x0c05224eu: goto P_0c05224e;
case 0x0c052250u: goto P_0c052250;
case 0x0c052252u: goto P_0c052252;
case 0x0c052254u: goto P_0c052254;
case 0x0c052256u: goto P_0c052256;
case 0x0c052258u: goto P_0c052258;
case 0x0c05225au: goto P_0c05225a;
case 0x0c05225cu: goto P_0c05225c;
case 0x0c05225eu: goto P_0c05225e;
case 0x0c052260u: goto P_0c052260;
case 0x0c052262u: goto P_0c052262;
case 0x0c052264u: goto P_0c052264;
case 0x0c052266u: goto P_0c052266;
case 0x0c052268u: goto P_0c052268;
case 0x0c05226au: goto P_0c05226a;
case 0x0c05226cu: goto P_0c05226c;
case 0x0c05226eu: goto P_0c05226e;
case 0x0c0537a0u: goto P_0c0537a0;
case 0x0c0537a2u: goto P_0c0537a2;
case 0x0c0537a4u: goto P_0c0537a4;
case 0x0c0537a6u: goto P_0c0537a6;
case 0x0c0537a8u: goto P_0c0537a8;
case 0x0c0537aau: goto P_0c0537aa;
case 0x0c0537acu: goto P_0c0537ac;
case 0x0c0537aeu: goto P_0c0537ae;
case 0x0c0537b0u: goto P_0c0537b0;
case 0x0c0537b2u: goto P_0c0537b2;
case 0x0c0537b4u: goto P_0c0537b4;
case 0x0c0537b6u: goto P_0c0537b6;
case 0x0c0537b8u: goto P_0c0537b8;
case 0x0c0537bau: goto P_0c0537ba;
case 0x0c0537bcu: goto P_0c0537bc;
case 0x0c0537beu: goto P_0c0537be;
case 0x0c0537c0u: goto P_0c0537c0;
case 0x0c0537c2u: goto P_0c0537c2;
case 0x0c0537c4u: goto P_0c0537c4;
case 0x0c0537c6u: goto P_0c0537c6;
case 0x0c0537c8u: goto P_0c0537c8;
case 0x0c0537cau: goto P_0c0537ca;
case 0x0c0537ccu: goto P_0c0537cc;
case 0x0c0537ceu: goto P_0c0537ce;
case 0x0c0537d0u: goto P_0c0537d0;
case 0x0c0537d2u: goto P_0c0537d2;
case 0x0c0537d4u: goto P_0c0537d4;
case 0x0c0537d6u: goto P_0c0537d6;
case 0x0c0537d8u: goto P_0c0537d8;
case 0x0c0537dau: goto P_0c0537da;
case 0x0c0537dcu: goto P_0c0537dc;
case 0x0c0537deu: goto P_0c0537de;
case 0x0c0537e0u: goto P_0c0537e0;
case 0x0c0537e2u: goto P_0c0537e2;
case 0x0c0537e4u: goto P_0c0537e4;
case 0x0c0537e6u: goto P_0c0537e6;
case 0x0c0537e8u: goto P_0c0537e8;
case 0x0c0537eau: goto P_0c0537ea;
case 0x0c0537ecu: goto P_0c0537ec;
case 0x0c0537eeu: goto P_0c0537ee;
case 0x0c0537f0u: goto P_0c0537f0;
case 0x0c0537f2u: goto P_0c0537f2;
case 0x0c0537f4u: goto P_0c0537f4;
case 0x0c0537f6u: goto P_0c0537f6;
case 0x0c0537f8u: goto P_0c0537f8;
case 0x0c0537fau: goto P_0c0537fa;
case 0x0c0537fcu: goto P_0c0537fc;
case 0x0c0537feu: goto P_0c0537fe;
case 0x0c053800u: goto P_0c053800;
case 0x0c053802u: goto P_0c053802;
case 0x0c053804u: goto P_0c053804;
case 0x0c053806u: goto P_0c053806;
case 0x0c053808u: goto P_0c053808;
case 0x0c05380au: goto P_0c05380a;
case 0x0c05380cu: goto P_0c05380c;
case 0x0c05380eu: goto P_0c05380e;
case 0x0c053810u: goto P_0c053810;
case 0x0c053812u: goto P_0c053812;
case 0x0c053814u: goto P_0c053814;
case 0x0c053816u: goto P_0c053816;
case 0x0c053818u: goto P_0c053818;
case 0x0c05381au: goto P_0c05381a;
case 0x0c05381cu: goto P_0c05381c;
case 0x0c05381eu: goto P_0c05381e;
case 0x0c053820u: goto P_0c053820;
case 0x0c053822u: goto P_0c053822;
case 0x0c053824u: goto P_0c053824;
case 0x0c053826u: goto P_0c053826;
case 0x0c053828u: goto P_0c053828;
case 0x0c05382au: goto P_0c05382a;
case 0x0c05382cu: goto P_0c05382c;
case 0x0c05382eu: goto P_0c05382e;
case 0x0c053830u: goto P_0c053830;
case 0x0c053832u: goto P_0c053832;
case 0x0c053834u: goto P_0c053834;
case 0x0c053836u: goto P_0c053836;
case 0x0c053838u: goto P_0c053838;
case 0x0c05383au: goto P_0c05383a;
case 0x0c05383cu: goto P_0c05383c;
case 0x0c05383eu: goto P_0c05383e;
case 0x0c053840u: goto P_0c053840;
case 0x0c053842u: goto P_0c053842;
case 0x0c053844u: goto P_0c053844;
case 0x0c053846u: goto P_0c053846;
case 0x0c053848u: goto P_0c053848;
case 0x0c05384au: goto P_0c05384a;
case 0x0c05384cu: goto P_0c05384c;
case 0x0c05384eu: goto P_0c05384e;
case 0x0c053850u: goto P_0c053850;
case 0x0c053852u: goto P_0c053852;
case 0x0c053854u: goto P_0c053854;
case 0x0c053856u: goto P_0c053856;
case 0x0c053858u: goto P_0c053858;
case 0x0c05385au: goto P_0c05385a;
case 0x0c0538a8u: goto P_0c0538a8;
case 0x0c0538aau: goto P_0c0538aa;
case 0x0c0538acu: goto P_0c0538ac;
case 0x0c0538aeu: goto P_0c0538ae;
case 0x0c0538b0u: goto P_0c0538b0;
case 0x0c0538b2u: goto P_0c0538b2;
case 0x0c0538b4u: goto P_0c0538b4;
case 0x0c0538b6u: goto P_0c0538b6;
case 0x0c0538b8u: goto P_0c0538b8;
case 0x0c0538bau: goto P_0c0538ba;
case 0x0c0538bcu: goto P_0c0538bc;
case 0x0c0538beu: goto P_0c0538be;
case 0x0c0538c0u: goto P_0c0538c0;
case 0x0c0538c2u: goto P_0c0538c2;
case 0x0c0538c4u: goto P_0c0538c4;
case 0x0c0538c6u: goto P_0c0538c6;
case 0x0c0538c8u: goto P_0c0538c8;
case 0x0c0538cau: goto P_0c0538ca;
case 0x0c0538ccu: goto P_0c0538cc;
case 0x0c0538ceu: goto P_0c0538ce;
case 0x0c0538d0u: goto P_0c0538d0;
case 0x0c0538d2u: goto P_0c0538d2;
case 0x0c0538d4u: goto P_0c0538d4;
case 0x0c0538d6u: goto P_0c0538d6;
case 0x0c0538d8u: goto P_0c0538d8;
case 0x0c0538dau: goto P_0c0538da;
case 0x0c0538dcu: goto P_0c0538dc;
case 0x0c0538deu: goto P_0c0538de;
case 0x0c0538e0u: goto P_0c0538e0;
case 0x0c0538e2u: goto P_0c0538e2;
case 0x0c0538e4u: goto P_0c0538e4;
case 0x0c0538e6u: goto P_0c0538e6;
case 0x0c0538e8u: goto P_0c0538e8;
case 0x0c0538eau: goto P_0c0538ea;
case 0x0c0538ecu: goto P_0c0538ec;
case 0x0c0538eeu: goto P_0c0538ee;
case 0x0c0538f0u: goto P_0c0538f0;
case 0x0c0538f2u: goto P_0c0538f2;
case 0x0c0538f4u: goto P_0c0538f4;
case 0x0c0538f6u: goto P_0c0538f6;
case 0x0c0538f8u: goto P_0c0538f8;
case 0x0c0538fau: goto P_0c0538fa;
case 0x0c0538fcu: goto P_0c0538fc;
case 0x0c0538feu: goto P_0c0538fe;
case 0x0c053900u: goto P_0c053900;
case 0x0c053902u: goto P_0c053902;
case 0x0c053904u: goto P_0c053904;
case 0x0c053906u: goto P_0c053906;
case 0x0c053908u: goto P_0c053908;
case 0x0c05390au: goto P_0c05390a;
case 0x0c05390cu: goto P_0c05390c;
case 0x0c05390eu: goto P_0c05390e;
case 0x0c053910u: goto P_0c053910;
case 0x0c053912u: goto P_0c053912;
case 0x0c053914u: goto P_0c053914;
case 0x0c053916u: goto P_0c053916;
case 0x0c053918u: goto P_0c053918;
case 0x0c05391au: goto P_0c05391a;
case 0x0c05391cu: goto P_0c05391c;
case 0x0c05391eu: goto P_0c05391e;
case 0x0c053920u: goto P_0c053920;
case 0x0c053922u: goto P_0c053922;
case 0x0c053924u: goto P_0c053924;
case 0x0c053926u: goto P_0c053926;
case 0x0c053928u: goto P_0c053928;
case 0x0c05392au: goto P_0c05392a;
case 0x0c05392cu: goto P_0c05392c;
case 0x0c05392eu: goto P_0c05392e;
case 0x0c053930u: goto P_0c053930;
case 0x0c053932u: goto P_0c053932;
case 0x0c053934u: goto P_0c053934;
case 0x0c053936u: goto P_0c053936;
case 0x0c053938u: goto P_0c053938;
case 0x0c05393au: goto P_0c05393a;
case 0x0c05393cu: goto P_0c05393c;
case 0x0c05393eu: goto P_0c05393e;
case 0x0c053940u: goto P_0c053940;
case 0x0c053942u: goto P_0c053942;
case 0x0c053944u: goto P_0c053944;
case 0x0c053946u: goto P_0c053946;
case 0x0c053948u: goto P_0c053948;
case 0x0c05394au: goto P_0c05394a;
case 0x0c05394cu: goto P_0c05394c;
case 0x0c05394eu: goto P_0c05394e;
case 0x0c053950u: goto P_0c053950;
case 0x0c053952u: goto P_0c053952;
case 0x0c053954u: goto P_0c053954;
case 0x0c053956u: goto P_0c053956;
case 0x0c053958u: goto P_0c053958;
case 0x0c05395au: goto P_0c05395a;
case 0x0c05395cu: goto P_0c05395c;
case 0x0c05395eu: goto P_0c05395e;
case 0x0c053960u: goto P_0c053960;
case 0x0c053962u: goto P_0c053962;
case 0x0c053964u: goto P_0c053964;
case 0x0c053966u: goto P_0c053966;
case 0x0c055666u: goto P_0c055666;
case 0x0c055668u: goto P_0c055668;
case 0x0c05566au: goto P_0c05566a;
case 0x0c05566cu: goto P_0c05566c;
case 0x0c05566eu: goto P_0c05566e;
case 0x0c055670u: goto P_0c055670;
case 0x0c055672u: goto P_0c055672;
case 0x0c055674u: goto P_0c055674;
case 0x0c055676u: goto P_0c055676;
case 0x0c055678u: goto P_0c055678;
case 0x0c05567au: goto P_0c05567a;
case 0x0c05567cu: goto P_0c05567c;
case 0x0c05567eu: goto P_0c05567e;
case 0x0c055680u: goto P_0c055680;
case 0x0c055682u: goto P_0c055682;
case 0x0c055684u: goto P_0c055684;
case 0x0c055686u: goto P_0c055686;
case 0x0c055688u: goto P_0c055688;
case 0x0c05568au: goto P_0c05568a;
case 0x0c05568cu: goto P_0c05568c;
case 0x0c05568eu: goto P_0c05568e;
case 0x0c055690u: goto P_0c055690;
case 0x0c055692u: goto P_0c055692;
case 0x0c055694u: goto P_0c055694;
case 0x0c0556a0u: goto P_0c0556a0;
case 0x0c0556a2u: goto P_0c0556a2;
case 0x0c0556a4u: goto P_0c0556a4;
case 0x0c0556a6u: goto P_0c0556a6;
case 0x0c0556a8u: goto P_0c0556a8;
case 0x0c0556aau: goto P_0c0556aa;
case 0x0c0556acu: goto P_0c0556ac;
case 0x0c0556aeu: goto P_0c0556ae;
case 0x0c0556b0u: goto P_0c0556b0;
case 0x0c0556b2u: goto P_0c0556b2;
case 0x0c0556b4u: goto P_0c0556b4;
case 0x0c0556b6u: goto P_0c0556b6;
case 0x0c0556b8u: goto P_0c0556b8;
case 0x0c0556bau: goto P_0c0556ba;
case 0x0c0556bcu: goto P_0c0556bc;
case 0x0c0556beu: goto P_0c0556be;
case 0x0c0556c0u: goto P_0c0556c0;
case 0x0c0556c2u: goto P_0c0556c2;
case 0x0c0556c4u: goto P_0c0556c4;
case 0x0c0556c6u: goto P_0c0556c6;
case 0x0c0556c8u: goto P_0c0556c8;
case 0x0c0556cau: goto P_0c0556ca;
case 0x0c0556ccu: goto P_0c0556cc;
case 0x0c0556ceu: goto P_0c0556ce;
case 0x0c0556d0u: goto P_0c0556d0;
case 0x0c0556d2u: goto P_0c0556d2;
case 0x0c0556d4u: goto P_0c0556d4;
case 0x0c0556d6u: goto P_0c0556d6;
case 0x0c0556d8u: goto P_0c0556d8;
case 0x0c0556dau: goto P_0c0556da;
case 0x0c0556dcu: goto P_0c0556dc;
case 0x0c0556deu: goto P_0c0556de;
case 0x0c0556e0u: goto P_0c0556e0;
case 0x0c0556e2u: goto P_0c0556e2;
case 0x0c0556e4u: goto P_0c0556e4;
case 0x0c0556e6u: goto P_0c0556e6;
case 0x0c0556e8u: goto P_0c0556e8;
case 0x0c0556eau: goto P_0c0556ea;
case 0x0c0556ecu: goto P_0c0556ec;
case 0x0c0556eeu: goto P_0c0556ee;
case 0x0c0556f0u: goto P_0c0556f0;
case 0x0c0556f2u: goto P_0c0556f2;
case 0x0c0556f4u: goto P_0c0556f4;
case 0x0c0556f6u: goto P_0c0556f6;
case 0x0c0556f8u: goto P_0c0556f8;
case 0x0c0556fau: goto P_0c0556fa;
case 0x0c055704u: goto P_0c055704;
case 0x0c055706u: goto P_0c055706;
case 0x0c055708u: goto P_0c055708;
case 0x0c05570au: goto P_0c05570a;
case 0x0c05570cu: goto P_0c05570c;
case 0x0c05570eu: goto P_0c05570e;
case 0x0c055710u: goto P_0c055710;
case 0x0c055712u: goto P_0c055712;
case 0x0c055714u: goto P_0c055714;
case 0x0c055716u: goto P_0c055716;
case 0x0c055718u: goto P_0c055718;
case 0x0c05571au: goto P_0c05571a;
case 0x0c05571cu: goto P_0c05571c;
case 0x0c05571eu: goto P_0c05571e;
case 0x0c055720u: goto P_0c055720;
case 0x0c055722u: goto P_0c055722;
case 0x0c055724u: goto P_0c055724;
case 0x0c055726u: goto P_0c055726;
case 0x0c055728u: goto P_0c055728;
case 0x0c05572au: goto P_0c05572a;
case 0x0c05572cu: goto P_0c05572c;
case 0x0c05572eu: goto P_0c05572e;
case 0x0c055730u: goto P_0c055730;
case 0x0c055732u: goto P_0c055732;
case 0x0c055734u: goto P_0c055734;
case 0x0c055736u: goto P_0c055736;
case 0x0c055738u: goto P_0c055738;
case 0x0c05573au: goto P_0c05573a;
case 0x0c05573cu: goto P_0c05573c;
case 0x0c05573eu: goto P_0c05573e;
case 0x0c055740u: goto P_0c055740;
case 0x0c055742u: goto P_0c055742;
case 0x0c055744u: goto P_0c055744;
case 0x0c055746u: goto P_0c055746;
case 0x0c055748u: goto P_0c055748;
case 0x0c05574au: goto P_0c05574a;
case 0x0c05574cu: goto P_0c05574c;
case 0x0c05574eu: goto P_0c05574e;
case 0x0c055750u: goto P_0c055750;
case 0x0c055752u: goto P_0c055752;
case 0x0c055754u: goto P_0c055754;
case 0x0c055756u: goto P_0c055756;
case 0x0c055758u: goto P_0c055758;
case 0x0c05575au: goto P_0c05575a;
case 0x0c05575cu: goto P_0c05575c;
case 0x0c05575eu: goto P_0c05575e;
case 0x0c055760u: goto P_0c055760;
case 0x0c055762u: goto P_0c055762;
case 0x0c055764u: goto P_0c055764;
case 0x0c055766u: goto P_0c055766;
case 0x0c055768u: goto P_0c055768;
case 0x0c05576au: goto P_0c05576a;
case 0x0c05576cu: goto P_0c05576c;
case 0x0c05576eu: goto P_0c05576e;
case 0x0c055770u: goto P_0c055770;
case 0x0c055772u: goto P_0c055772;
case 0x0c055774u: goto P_0c055774;
case 0x0c055776u: goto P_0c055776;
case 0x0c055778u: goto P_0c055778;
case 0x0c05577au: goto P_0c05577a;
case 0x0c05577cu: goto P_0c05577c;
case 0x0c05577eu: goto P_0c05577e;
case 0x0c055780u: goto P_0c055780;
case 0x0c055782u: goto P_0c055782;
case 0x0c055784u: goto P_0c055784;
case 0x0c055786u: goto P_0c055786;
case 0x0c055788u: goto P_0c055788;
case 0x0c05578au: goto P_0c05578a;
case 0x0c05578cu: goto P_0c05578c;
case 0x0c05578eu: goto P_0c05578e;
case 0x0c055790u: goto P_0c055790;
case 0x0c055792u: goto P_0c055792;
case 0x0c055794u: goto P_0c055794;
case 0x0c055796u: goto P_0c055796;
case 0x0c055798u: goto P_0c055798;
case 0x0c05579au: goto P_0c05579a;
case 0x0c0557a0u: goto P_0c0557a0;
case 0x0c0557a2u: goto P_0c0557a2;
case 0x0c0557a4u: goto P_0c0557a4;
case 0x0c0557a6u: goto P_0c0557a6;
case 0x0c0557a8u: goto P_0c0557a8;
case 0x0c0557aau: goto P_0c0557aa;
case 0x0c0558f4u: goto P_0c0558f4;
case 0x0c0558f6u: goto P_0c0558f6;
case 0x0c0558f8u: goto P_0c0558f8;
case 0x0c0558fau: goto P_0c0558fa;
case 0x0c0558fcu: goto P_0c0558fc;
case 0x0c0558feu: goto P_0c0558fe;
case 0x0c055900u: goto P_0c055900;
case 0x0c055902u: goto P_0c055902;
case 0x0c055904u: goto P_0c055904;
case 0x0c055906u: goto P_0c055906;
case 0x0c055908u: goto P_0c055908;
case 0x0c05590au: goto P_0c05590a;
case 0x0c05590cu: goto P_0c05590c;
case 0x0c05590eu: goto P_0c05590e;
case 0x0c055910u: goto P_0c055910;
case 0x0c055912u: goto P_0c055912;
case 0x0c055914u: goto P_0c055914;
case 0x0c055916u: goto P_0c055916;
case 0x0c055918u: goto P_0c055918;
case 0x0c05591au: goto P_0c05591a;
case 0x0c05591cu: goto P_0c05591c;
case 0x0c05591eu: goto P_0c05591e;
case 0x0c055920u: goto P_0c055920;
case 0x0c055922u: goto P_0c055922;
case 0x0c055924u: goto P_0c055924;
case 0x0c055926u: goto P_0c055926;
case 0x0c055928u: goto P_0c055928;
case 0x0c05592au: goto P_0c05592a;
case 0x0c05592cu: goto P_0c05592c;
case 0x0c05592eu: goto P_0c05592e;
case 0x0c055930u: goto P_0c055930;
case 0x0c055932u: goto P_0c055932;
case 0x0c055934u: goto P_0c055934;
case 0x0c055936u: goto P_0c055936;
case 0x0c055938u: goto P_0c055938;
case 0x0c05593au: goto P_0c05593a;
case 0x0c05593cu: goto P_0c05593c;
case 0x0c05593eu: goto P_0c05593e;
case 0x0c055940u: goto P_0c055940;
case 0x0c055942u: goto P_0c055942;
case 0x0c055944u: goto P_0c055944;
case 0x0c055946u: goto P_0c055946;
case 0x0c055948u: goto P_0c055948;
case 0x0c05594au: goto P_0c05594a;
case 0x0c05594cu: goto P_0c05594c;
case 0x0c05594eu: goto P_0c05594e;
case 0x0c055950u: goto P_0c055950;
case 0x0c055952u: goto P_0c055952;
case 0x0c055954u: goto P_0c055954;
case 0x0c055956u: goto P_0c055956;
case 0x0c055958u: goto P_0c055958;
case 0x0c05595au: goto P_0c05595a;
case 0x0c05595cu: goto P_0c05595c;
case 0x0c05595eu: goto P_0c05595e;
case 0x0c055960u: goto P_0c055960;
case 0x0c055962u: goto P_0c055962;
case 0x0c055964u: goto P_0c055964;
case 0x0c055966u: goto P_0c055966;
case 0x0c055968u: goto P_0c055968;
case 0x0c05596au: goto P_0c05596a;
case 0x0c05596cu: goto P_0c05596c;
case 0x0c05596eu: goto P_0c05596e;
case 0x0c055970u: goto P_0c055970;
case 0x0c055972u: goto P_0c055972;
case 0x0c055974u: goto P_0c055974;
case 0x0c055976u: goto P_0c055976;
case 0x0c055978u: goto P_0c055978;
case 0x0c05597au: goto P_0c05597a;
case 0x0c05597cu: goto P_0c05597c;
case 0x0c05597eu: goto P_0c05597e;
case 0x0c055980u: goto P_0c055980;
case 0x0c055982u: goto P_0c055982;
case 0x0c055984u: goto P_0c055984;
case 0x0c055986u: goto P_0c055986;
case 0x0c055988u: goto P_0c055988;
case 0x0c055bfcu: goto P_0c055bfc;
case 0x0c055bfeu: goto P_0c055bfe;
case 0x0c055c00u: goto P_0c055c00;
case 0x0c055c02u: goto P_0c055c02;
case 0x0c055c04u: goto P_0c055c04;
case 0x0c055c06u: goto P_0c055c06;
case 0x0c055c08u: goto P_0c055c08;
case 0x0c055c0au: goto P_0c055c0a;
case 0x0c055c0cu: goto P_0c055c0c;
case 0x0c055c0eu: goto P_0c055c0e;
case 0x0c055c10u: goto P_0c055c10;
case 0x0c055c12u: goto P_0c055c12;
case 0x0c055c14u: goto P_0c055c14;
case 0x0c055c16u: goto P_0c055c16;
case 0x0c055c18u: goto P_0c055c18;
case 0x0c055c1au: goto P_0c055c1a;
case 0x0c055c1cu: goto P_0c055c1c;
case 0x0c055c1eu: goto P_0c055c1e;
case 0x0c055c20u: goto P_0c055c20;
case 0x0c055c22u: goto P_0c055c22;
case 0x0c055c24u: goto P_0c055c24;
case 0x0c055c26u: goto P_0c055c26;
case 0x0c055c28u: goto P_0c055c28;
case 0x0c055c2au: goto P_0c055c2a;
case 0x0c055c2cu: goto P_0c055c2c;
case 0x0c055c2eu: goto P_0c055c2e;
case 0x0c055c30u: goto P_0c055c30;
case 0x0c055c32u: goto P_0c055c32;
case 0x0c055c34u: goto P_0c055c34;
case 0x0c055c36u: goto P_0c055c36;
case 0x0c055c38u: goto P_0c055c38;
case 0x0c055c3au: goto P_0c055c3a;
case 0x0c055c3cu: goto P_0c055c3c;
case 0x0c055c3eu: goto P_0c055c3e;
case 0x0c055c40u: goto P_0c055c40;
case 0x0c055c42u: goto P_0c055c42;
case 0x0c055c44u: goto P_0c055c44;
case 0x0c055c46u: goto P_0c055c46;
case 0x0c055c48u: goto P_0c055c48;
case 0x0c055c4au: goto P_0c055c4a;
case 0x0c055c4cu: goto P_0c055c4c;
case 0x0c055c4eu: goto P_0c055c4e;
case 0x0c055c50u: goto P_0c055c50;
case 0x0c055c52u: goto P_0c055c52;
case 0x0c055c54u: goto P_0c055c54;
case 0x0c055c56u: goto P_0c055c56;
case 0x0c055c58u: goto P_0c055c58;
case 0x0c055c5au: goto P_0c055c5a;
case 0x0c055c5cu: goto P_0c055c5c;
case 0x0c0568a2u: goto P_0c0568a2;
case 0x0c0568a4u: goto P_0c0568a4;
case 0x0c0568a6u: goto P_0c0568a6;
case 0x0c0568a8u: goto P_0c0568a8;
case 0x0c0568aau: goto P_0c0568aa;
case 0x0c0568acu: goto P_0c0568ac;
case 0x0c0568aeu: goto P_0c0568ae;
case 0x0c0568b0u: goto P_0c0568b0;
case 0x0c0568b2u: goto P_0c0568b2;
case 0x0c0568b4u: goto P_0c0568b4;
case 0x0c0568b6u: goto P_0c0568b6;
case 0x0c0568b8u: goto P_0c0568b8;
case 0x0c0568bau: goto P_0c0568ba;
case 0x0c0568bcu: goto P_0c0568bc;
case 0x0c0568beu: goto P_0c0568be;
case 0x0c0568c0u: goto P_0c0568c0;
case 0x0c0568c2u: goto P_0c0568c2;
case 0x0c0568c4u: goto P_0c0568c4;
case 0x0c0568d8u: goto P_0c0568d8;
case 0x0c0568dau: goto P_0c0568da;
case 0x0c0568dcu: goto P_0c0568dc;
case 0x0c0568deu: goto P_0c0568de;
case 0x0c0568e0u: goto P_0c0568e0;
case 0x0c0568e2u: goto P_0c0568e2;
case 0x0c0568e4u: goto P_0c0568e4;
case 0x0c0568e6u: goto P_0c0568e6;
case 0x0c0568e8u: goto P_0c0568e8;
case 0x0c0568eau: goto P_0c0568ea;
case 0x0c0568ecu: goto P_0c0568ec;
case 0x0c0568eeu: goto P_0c0568ee;
case 0x0c0568f0u: goto P_0c0568f0;
case 0x0c0568f2u: goto P_0c0568f2;
case 0x0c0568f4u: goto P_0c0568f4;
case 0x0c0568f6u: goto P_0c0568f6;
case 0x0c0568f8u: goto P_0c0568f8;
case 0x0c0568fau: goto P_0c0568fa;
case 0x0c0568fcu: goto P_0c0568fc;
case 0x0c0568feu: goto P_0c0568fe;
case 0x0c056900u: goto P_0c056900;
case 0x0c056902u: goto P_0c056902;
case 0x0c056904u: goto P_0c056904;
case 0x0c056906u: goto P_0c056906;
case 0x0c056908u: goto P_0c056908;
case 0x0c05690au: goto P_0c05690a;
case 0x0c05690cu: goto P_0c05690c;
case 0x0c05690eu: goto P_0c05690e;
case 0x0c056910u: goto P_0c056910;
case 0x0c056912u: goto P_0c056912;
case 0x0c056914u: goto P_0c056914;
case 0x0c056916u: goto P_0c056916;
case 0x0c056918u: goto P_0c056918;
case 0x0c05691au: goto P_0c05691a;
case 0x0c05691cu: goto P_0c05691c;
case 0x0c05691eu: goto P_0c05691e;
case 0x0c056920u: goto P_0c056920;
case 0x0c056922u: goto P_0c056922;
case 0x0c056924u: goto P_0c056924;
case 0x0c056926u: goto P_0c056926;
case 0x0c056928u: goto P_0c056928;
case 0x0c05692au: goto P_0c05692a;
case 0x0c05692cu: goto P_0c05692c;
case 0x0c05692eu: goto P_0c05692e;
case 0x0c056930u: goto P_0c056930;
case 0x0c056932u: goto P_0c056932;
case 0x0c056934u: goto P_0c056934;
case 0x0c056936u: goto P_0c056936;
case 0x0c056938u: goto P_0c056938;
case 0x0c05693au: goto P_0c05693a;
case 0x0c05693cu: goto P_0c05693c;
case 0x0c05693eu: goto P_0c05693e;
case 0x0c056940u: goto P_0c056940;
case 0x0c056942u: goto P_0c056942;
case 0x0c056944u: goto P_0c056944;
case 0x0c056946u: goto P_0c056946;
case 0x0c056948u: goto P_0c056948;
case 0x0c05694au: goto P_0c05694a;
case 0x0c05694cu: goto P_0c05694c;
case 0x0c05694eu: goto P_0c05694e;
case 0x0c056950u: goto P_0c056950;
case 0x0c056952u: goto P_0c056952;
case 0x0c056954u: goto P_0c056954;
case 0x0c056956u: goto P_0c056956;
case 0x0c056958u: goto P_0c056958;
case 0x0c05695au: goto P_0c05695a;
case 0x0c05695cu: goto P_0c05695c;
case 0x0c05695eu: goto P_0c05695e;
case 0x0c056960u: goto P_0c056960;
case 0x0c056962u: goto P_0c056962;
case 0x0c056964u: goto P_0c056964;
case 0x0c056966u: goto P_0c056966;
case 0x0c056968u: goto P_0c056968;
case 0x0c05696au: goto P_0c05696a;
case 0x0c05696cu: goto P_0c05696c;
case 0x0c05696eu: goto P_0c05696e;
case 0x0c056970u: goto P_0c056970;
case 0x0c056972u: goto P_0c056972;
case 0x0c056974u: goto P_0c056974;
case 0x0c056976u: goto P_0c056976;
case 0x0c056978u: goto P_0c056978;
case 0x0c05697au: goto P_0c05697a;
case 0x0c05697cu: goto P_0c05697c;
case 0x0c05697eu: goto P_0c05697e;
case 0x0c056980u: goto P_0c056980;
case 0x0c056982u: goto P_0c056982;
case 0x0c056984u: goto P_0c056984;
case 0x0c056986u: goto P_0c056986;
case 0x0c056988u: goto P_0c056988;
case 0x0c05698au: goto P_0c05698a;
case 0x0c05698cu: goto P_0c05698c;
case 0x0c05698eu: goto P_0c05698e;
case 0x0c056990u: goto P_0c056990;
case 0x0c056992u: goto P_0c056992;
case 0x0c056994u: goto P_0c056994;
case 0x0c056996u: goto P_0c056996;
case 0x0c056998u: goto P_0c056998;
case 0x0c05699au: goto P_0c05699a;
case 0x0c05699cu: goto P_0c05699c;
case 0x0c05699eu: goto P_0c05699e;
case 0x0c0569a0u: goto P_0c0569a0;
case 0x0c0569a2u: goto P_0c0569a2;
case 0x0c0569a4u: goto P_0c0569a4;
case 0x0c0569a6u: goto P_0c0569a6;
case 0x0c0569a8u: goto P_0c0569a8;
case 0x0c0569aau: goto P_0c0569aa;
case 0x0c0569acu: goto P_0c0569ac;
case 0x0c0569aeu: goto P_0c0569ae;
case 0x0c0569b0u: goto P_0c0569b0;
case 0x0c0569b2u: goto P_0c0569b2;
case 0x0c0569b4u: goto P_0c0569b4;
case 0x0c0569b6u: goto P_0c0569b6;
case 0x0c0569b8u: goto P_0c0569b8;
case 0x0c0569bau: goto P_0c0569ba;
case 0x0c0569bcu: goto P_0c0569bc;
case 0x0c0569beu: goto P_0c0569be;
case 0x0c0569c0u: goto P_0c0569c0;
case 0x0c0569c2u: goto P_0c0569c2;
case 0x0c0569c4u: goto P_0c0569c4;
case 0x0c0569c6u: goto P_0c0569c6;
case 0x0c0569c8u: goto P_0c0569c8;
case 0x0c0569cau: goto P_0c0569ca;
case 0x0c0569ccu: goto P_0c0569cc;
case 0x0c0569ceu: goto P_0c0569ce;
case 0x0c0569d0u: goto P_0c0569d0;
case 0x0c0569d2u: goto P_0c0569d2;
case 0x0c0569d4u: goto P_0c0569d4;
case 0x0c0569d6u: goto P_0c0569d6;
case 0x0c0569d8u: goto P_0c0569d8;
case 0x0c0569dau: goto P_0c0569da;
case 0x0c0569dcu: goto P_0c0569dc;
case 0x0c0569deu: goto P_0c0569de;
case 0x0c0569e0u: goto P_0c0569e0;
case 0x0c0569e2u: goto P_0c0569e2;
case 0x0c0569e4u: goto P_0c0569e4;
case 0x0c0569e6u: goto P_0c0569e6;
case 0x0c0569e8u: goto P_0c0569e8;
case 0x0c0569eau: goto P_0c0569ea;
case 0x0c0569ecu: goto P_0c0569ec;
case 0x0c0569eeu: goto P_0c0569ee;
case 0x0c0569f0u: goto P_0c0569f0;
case 0x0c0569f2u: goto P_0c0569f2;
case 0x0c0569f4u: goto P_0c0569f4;
case 0x0c0569f6u: goto P_0c0569f6;
case 0x0c0569f8u: goto P_0c0569f8;
case 0x0c0569fau: goto P_0c0569fa;
case 0x0c0569fcu: goto P_0c0569fc;
case 0x0c0569feu: goto P_0c0569fe;
case 0x0c056a00u: goto P_0c056a00;
case 0x0c056a02u: goto P_0c056a02;
case 0x0c056a04u: goto P_0c056a04;
case 0x0c056a06u: goto P_0c056a06;
case 0x0c056a08u: goto P_0c056a08;
case 0x0c056a0au: goto P_0c056a0a;
case 0x0c056a0cu: goto P_0c056a0c;
case 0x0c056a0eu: goto P_0c056a0e;
case 0x0c056a10u: goto P_0c056a10;
case 0x0c056a12u: goto P_0c056a12;
case 0x0c056a14u: goto P_0c056a14;
case 0x0c056a16u: goto P_0c056a16;
case 0x0c056a18u: goto P_0c056a18;
case 0x0c056a1au: goto P_0c056a1a;
case 0x0c056a1cu: goto P_0c056a1c;
case 0x0c056a1eu: goto P_0c056a1e;
case 0x0c056a20u: goto P_0c056a20;
case 0x0c056a22u: goto P_0c056a22;
case 0x0c056a24u: goto P_0c056a24;
case 0x0c056a26u: goto P_0c056a26;
case 0x0c056a28u: goto P_0c056a28;
case 0x0c056a2au: goto P_0c056a2a;
case 0x0c056a2cu: goto P_0c056a2c;
case 0x0c056a2eu: goto P_0c056a2e;
case 0x0c056a30u: goto P_0c056a30;
case 0x0c056a32u: goto P_0c056a32;
case 0x0c056a34u: goto P_0c056a34;
case 0x0c056a36u: goto P_0c056a36;
case 0x0c056a38u: goto P_0c056a38;
case 0x0c056a3au: goto P_0c056a3a;
case 0x0c056a3cu: goto P_0c056a3c;
case 0x0c056a3eu: goto P_0c056a3e;
case 0x0c056a40u: goto P_0c056a40;
case 0x0c056a42u: goto P_0c056a42;
case 0x0c056a44u: goto P_0c056a44;
case 0x0c056a46u: goto P_0c056a46;
case 0x0c056a48u: goto P_0c056a48;
case 0x0c056a4au: goto P_0c056a4a;
case 0x0c056a4cu: goto P_0c056a4c;
case 0x0c056a54u: goto P_0c056a54;
case 0x0c056a56u: goto P_0c056a56;
case 0x0c056a58u: goto P_0c056a58;
case 0x0c056a5au: goto P_0c056a5a;
case 0x0c056a5cu: goto P_0c056a5c;
case 0x0c056a5eu: goto P_0c056a5e;
case 0x0c056a60u: goto P_0c056a60;
case 0x0c056a62u: goto P_0c056a62;
case 0x0c056a64u: goto P_0c056a64;
case 0x0c056a66u: goto P_0c056a66;
case 0x0c064246u: goto P_0c064246;
case 0x0c064248u: goto P_0c064248;
case 0x0c06424au: goto P_0c06424a;
case 0x0c06424cu: goto P_0c06424c;
case 0x0c06424eu: goto P_0c06424e;
case 0x0c064250u: goto P_0c064250;
case 0x0c064252u: goto P_0c064252;
case 0x0c064254u: goto P_0c064254;
case 0x0c064256u: goto P_0c064256;
case 0x0c064258u: goto P_0c064258;
case 0x0c06425au: goto P_0c06425a;
case 0x0c06425cu: goto P_0c06425c;
case 0x0c06425eu: goto P_0c06425e;
case 0x0c064260u: goto P_0c064260;
case 0x0c064262u: goto P_0c064262;
case 0x0c064264u: goto P_0c064264;
case 0x0c064266u: goto P_0c064266;
case 0x0c064268u: goto P_0c064268;
case 0x0c06426au: goto P_0c06426a;
case 0x0c06426cu: goto P_0c06426c;
case 0x0c06426eu: goto P_0c06426e;
case 0x0c064270u: goto P_0c064270;
case 0x0c064272u: goto P_0c064272;
case 0x0c064274u: goto P_0c064274;
case 0x0c064276u: goto P_0c064276;
case 0x0c064278u: goto P_0c064278;
case 0x0c06427au: goto P_0c06427a;
case 0x0c06427cu: goto P_0c06427c;
case 0x0c06427eu: goto P_0c06427e;
case 0x0c064280u: goto P_0c064280;
case 0x0c064282u: goto P_0c064282;
case 0x0c064284u: goto P_0c064284;
case 0x0c064286u: goto P_0c064286;
case 0x0c064288u: goto P_0c064288;
case 0x0c06428au: goto P_0c06428a;
case 0x0c06428cu: goto P_0c06428c;
case 0x0c06428eu: goto P_0c06428e;
case 0x0c064290u: goto P_0c064290;
case 0x0c064292u: goto P_0c064292;
case 0x0c064294u: goto P_0c064294;
case 0x0c064296u: goto P_0c064296;
case 0x0c064298u: goto P_0c064298;
case 0x0c06429au: goto P_0c06429a;
case 0x0c06429cu: goto P_0c06429c;
case 0x0c06429eu: goto P_0c06429e;
case 0x0c0642a0u: goto P_0c0642a0;
case 0x0c0642a2u: goto P_0c0642a2;
case 0x0c0642a4u: goto P_0c0642a4;
case 0x0c0642a6u: goto P_0c0642a6;
case 0x0c0642a8u: goto P_0c0642a8;
case 0x0c0642aau: goto P_0c0642aa;
case 0x0c0642acu: goto P_0c0642ac;
case 0x0c0642aeu: goto P_0c0642ae;
case 0x0c0642b0u: goto P_0c0642b0;
case 0x0c0642b2u: goto P_0c0642b2;
case 0x0c0642b4u: goto P_0c0642b4;
case 0x0c0642b6u: goto P_0c0642b6;
case 0x0c0642b8u: goto P_0c0642b8;
case 0x0c0642bau: goto P_0c0642ba;
case 0x0c0642bcu: goto P_0c0642bc;
case 0x0c0642beu: goto P_0c0642be;
case 0x0c0642c0u: goto P_0c0642c0;
case 0x0c0642c2u: goto P_0c0642c2;
case 0x0c0642c4u: goto P_0c0642c4;
case 0x0c0642c6u: goto P_0c0642c6;
case 0x0c0642c8u: goto P_0c0642c8;
case 0x0c0642cau: goto P_0c0642ca;
case 0x0c064314u: goto P_0c064314;
case 0x0c064316u: goto P_0c064316;
case 0x0c064318u: goto P_0c064318;
case 0x0c06431au: goto P_0c06431a;
case 0x0c06431cu: goto P_0c06431c;
case 0x0c06431eu: goto P_0c06431e;
case 0x0c064320u: goto P_0c064320;
case 0x0c064322u: goto P_0c064322;
case 0x0c064324u: goto P_0c064324;
case 0x0c064326u: goto P_0c064326;
case 0x0c064328u: goto P_0c064328;
case 0x0c06432au: goto P_0c06432a;
case 0x0c06432cu: goto P_0c06432c;
case 0x0c06432eu: goto P_0c06432e;
case 0x0c064330u: goto P_0c064330;
case 0x0c064332u: goto P_0c064332;
case 0x0c064334u: goto P_0c064334;
case 0x0c064336u: goto P_0c064336;
case 0x0c064338u: goto P_0c064338;
case 0x0c06433au: goto P_0c06433a;
case 0x0c06433cu: goto P_0c06433c;
case 0x0c06433eu: goto P_0c06433e;
case 0x0c064340u: goto P_0c064340;
case 0x0c064342u: goto P_0c064342;
case 0x0c064344u: goto P_0c064344;
case 0x0c064346u: goto P_0c064346;
case 0x0c064348u: goto P_0c064348;
case 0x0c06434au: goto P_0c06434a;
case 0x0c06434cu: goto P_0c06434c;
case 0x0c06434eu: goto P_0c06434e;
case 0x0c064350u: goto P_0c064350;
case 0x0c064352u: goto P_0c064352;
case 0x0c064354u: goto P_0c064354;
case 0x0c064356u: goto P_0c064356;
case 0x0c064358u: goto P_0c064358;
case 0x0c06435au: goto P_0c06435a;
case 0x0c06435cu: goto P_0c06435c;
case 0x0c06435eu: goto P_0c06435e;
case 0x0c064360u: goto P_0c064360;
case 0x0c064362u: goto P_0c064362;
case 0x0c064364u: goto P_0c064364;
case 0x0c064366u: goto P_0c064366;
case 0x0c064368u: goto P_0c064368;
case 0x0c06436au: goto P_0c06436a;
case 0x0c06436cu: goto P_0c06436c;
case 0x0c06436eu: goto P_0c06436e;
case 0x0c064370u: goto P_0c064370;
case 0x0c064372u: goto P_0c064372;
case 0x0c064374u: goto P_0c064374;
case 0x0c064376u: goto P_0c064376;
case 0x0c064378u: goto P_0c064378;
case 0x0c06437au: goto P_0c06437a;
case 0x0c06437cu: goto P_0c06437c;
case 0x0c06437eu: goto P_0c06437e;
case 0x0c064380u: goto P_0c064380;
case 0x0c064382u: goto P_0c064382;
case 0x0c064384u: goto P_0c064384;
case 0x0c064386u: goto P_0c064386;
case 0x0c064388u: goto P_0c064388;
case 0x0c06438au: goto P_0c06438a;
case 0x0c06438cu: goto P_0c06438c;
case 0x0c06438eu: goto P_0c06438e;
case 0x0c064390u: goto P_0c064390;
case 0x0c064392u: goto P_0c064392;
case 0x0c064394u: goto P_0c064394;
case 0x0c064396u: goto P_0c064396;
case 0x0c064398u: goto P_0c064398;
case 0x0c06439au: goto P_0c06439a;
case 0x0c06439cu: goto P_0c06439c;
case 0x0c06439eu: goto P_0c06439e;
case 0x0c0643a0u: goto P_0c0643a0;
case 0x0c0643a2u: goto P_0c0643a2;
case 0x0c0643a4u: goto P_0c0643a4;
case 0x0c0643a6u: goto P_0c0643a6;
case 0x0c0643a8u: goto P_0c0643a8;
case 0x0c0643aau: goto P_0c0643aa;
case 0x0c0643acu: goto P_0c0643ac;
case 0x0c0643aeu: goto P_0c0643ae;
case 0x0c0643b0u: goto P_0c0643b0;
case 0x0c0643b2u: goto P_0c0643b2;
case 0x0c0643b4u: goto P_0c0643b4;
case 0x0c0643b6u: goto P_0c0643b6;
case 0x0c0643b8u: goto P_0c0643b8;
case 0x0c0643bau: goto P_0c0643ba;
case 0x0c0643bcu: goto P_0c0643bc;
case 0x0c0643beu: goto P_0c0643be;
case 0x0c0643c0u: goto P_0c0643c0;
case 0x0c0643c2u: goto P_0c0643c2;
case 0x0c0643c4u: goto P_0c0643c4;
case 0x0c0643c6u: goto P_0c0643c6;
case 0x0c0643c8u: goto P_0c0643c8;
case 0x0c0643cau: goto P_0c0643ca;
case 0x0c0643ccu: goto P_0c0643cc;
case 0x0c0643ceu: goto P_0c0643ce;
case 0x0c0643d0u: goto P_0c0643d0;
case 0x0c0643d2u: goto P_0c0643d2;
case 0x0c0643d4u: goto P_0c0643d4;
case 0x0c0643d6u: goto P_0c0643d6;
case 0x0c0643d8u: goto P_0c0643d8;
case 0x0c0643dau: goto P_0c0643da;
case 0x0c0643dcu: goto P_0c0643dc;
case 0x0c0643deu: goto P_0c0643de;
case 0x0c0643e0u: goto P_0c0643e0;
case 0x0c0643e2u: goto P_0c0643e2;
case 0x0c0643e4u: goto P_0c0643e4;
case 0x0c0643e6u: goto P_0c0643e6;
case 0x0c0643e8u: goto P_0c0643e8;
case 0x0c0643eau: goto P_0c0643ea;
case 0x0c0643ecu: goto P_0c0643ec;
case 0x0c0643eeu: goto P_0c0643ee;
case 0x0c0643f0u: goto P_0c0643f0;
case 0x0c0643f2u: goto P_0c0643f2;
case 0x0c0643f4u: goto P_0c0643f4;
case 0x0c0643f6u: goto P_0c0643f6;
case 0x0c0643f8u: goto P_0c0643f8;
case 0x0c0643fau: goto P_0c0643fa;
case 0x0c0643fcu: goto P_0c0643fc;
case 0x0c0643feu: goto P_0c0643fe;
case 0x0c064400u: goto P_0c064400;
case 0x0c064402u: goto P_0c064402;
case 0x0c064404u: goto P_0c064404;
case 0x0c064406u: goto P_0c064406;
case 0x0c064408u: goto P_0c064408;
case 0x0c06440au: goto P_0c06440a;
case 0x0c06440cu: goto P_0c06440c;
case 0x0c06440eu: goto P_0c06440e;
case 0x0c064410u: goto P_0c064410;
case 0x0c064412u: goto P_0c064412;
case 0x0c064414u: goto P_0c064414;
case 0x0c064416u: goto P_0c064416;
case 0x0c064418u: goto P_0c064418;
case 0x0c06444cu: goto P_0c06444c;
case 0x0c06444eu: goto P_0c06444e;
case 0x0c064450u: goto P_0c064450;
case 0x0c064452u: goto P_0c064452;
case 0x0c064454u: goto P_0c064454;
case 0x0c064456u: goto P_0c064456;
case 0x0c064458u: goto P_0c064458;
case 0x0c06445au: goto P_0c06445a;
case 0x0c06445cu: goto P_0c06445c;
case 0x0c06445eu: goto P_0c06445e;
case 0x0c064460u: goto P_0c064460;
case 0x0c064462u: goto P_0c064462;
case 0x0c064464u: goto P_0c064464;
case 0x0c064466u: goto P_0c064466;
case 0x0c064468u: goto P_0c064468;
case 0x0c06446au: goto P_0c06446a;
case 0x0c06446cu: goto P_0c06446c;
case 0x0c06446eu: goto P_0c06446e;
case 0x0c064470u: goto P_0c064470;
case 0x0c064472u: goto P_0c064472;
case 0x0c064474u: goto P_0c064474;
case 0x0c064476u: goto P_0c064476;
case 0x0c064478u: goto P_0c064478;
case 0x0c06447au: goto P_0c06447a;
case 0x0c06447cu: goto P_0c06447c;
case 0x0c06447eu: goto P_0c06447e;
case 0x0c064480u: goto P_0c064480;
case 0x0c064482u: goto P_0c064482;
case 0x0c064484u: goto P_0c064484;
case 0x0c064486u: goto P_0c064486;
case 0x0c064488u: goto P_0c064488;
case 0x0c06448au: goto P_0c06448a;
case 0x0c06448cu: goto P_0c06448c;
case 0x0c06448eu: goto P_0c06448e;
case 0x0c064490u: goto P_0c064490;
case 0x0c064492u: goto P_0c064492;
case 0x0c064494u: goto P_0c064494;
case 0x0c064496u: goto P_0c064496;
case 0x0c064498u: goto P_0c064498;
case 0x0c06449au: goto P_0c06449a;
case 0x0c06449cu: goto P_0c06449c;
case 0x0c06449eu: goto P_0c06449e;
case 0x0c0644a0u: goto P_0c0644a0;
case 0x0c0644a2u: goto P_0c0644a2;
case 0x0c0644a4u: goto P_0c0644a4;
case 0x0c0644a6u: goto P_0c0644a6;
case 0x0c0644a8u: goto P_0c0644a8;
case 0x0c0644aau: goto P_0c0644aa;
case 0x0c0644acu: goto P_0c0644ac;
case 0x0c0644aeu: goto P_0c0644ae;
case 0x0c0644b0u: goto P_0c0644b0;
case 0x0c0644b2u: goto P_0c0644b2;
case 0x0c0644b4u: goto P_0c0644b4;
case 0x0c0644b6u: goto P_0c0644b6;
case 0x0c0644b8u: goto P_0c0644b8;
case 0x0c0644bau: goto P_0c0644ba;
default: return vf3_matrix_family(target,s,ram);
}
P_0c035518: /* original 4f22, guest PC 0x0c035518 */
if(!s->budget--) { s->failed_pc=0x0c035518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03551a;
P_0c03551a: /* original d333, guest PC 0x0c03551a */
if(!s->budget--) { s->failed_pc=0x0c03551au; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c03551c;
P_0c03551c: /* original 6d32, guest PC 0x0c03551c */
if(!s->budget--) { s->failed_pc=0x0c03551cu; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c03551e;
P_0c03551e: /* original 9c61, guest PC 0x0c03551e */
if(!s->budget--) { s->failed_pc=0x0c03551eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0355e4u,2);
goto P_0c035520;
P_0c035520: /* original da32, guest PC 0x0c035520 */
if(!s->budget--) { s->failed_pc=0x0c035520u; return 0; }
r[10]=read(ram,0x0c0355ecu,4);
goto P_0c035522;
P_0c035522: /* original 5be6, guest PC 0x0c035522 */
if(!s->budget--) { s->failed_pc=0x0c035522u; return 0; }
r[11]=read(ram,r[14]+24,4);
goto P_0c035524;
P_0c035524: /* original 60e2, guest PC 0x0c035524 */
if(!s->budget--) { s->failed_pc=0x0c035524u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c035526;
P_0c035526: /* original 5009, guest PC 0x0c035526 */
if(!s->budget--) { s->failed_pc=0x0c035526u; return 0; }
r[0]=read(ram,r[0]+36,4);
goto P_0c035528;
P_0c035528: /* original 8802, guest PC 0x0c035528 */
if(!s->budget--) { s->failed_pc=0x0c035528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03552a;
P_0c03552a: /* original 8901, guest PC 0x0c03552a */
if(!s->budget--) { s->failed_pc=0x0c03552au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035530; }
goto P_0c03552c;
P_0c03552c: /* original 4a0b, guest PC 0x0c03552c */
if(!s->budget--) { s->failed_pc=0x0c03552cu; return 0; }
target=r[10];
r[16]=0x0c035530u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035530u) { target=s->pc; goto dispatch; }
goto P_0c035530;
P_0c03552e: /* original 0009, guest PC 0x0c03552e */
if(!s->budget--) { s->failed_pc=0x0c03552eu; return 0; }
goto P_0c035530;
P_0c035530: /* original b276, guest PC 0x0c035530 */
if(!s->budget--) { s->failed_pc=0x0c035530u; return 0; }
target=0x0c035a20u; r[16]=0x0c035534u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035534u) { target=s->pc; goto dispatch; }
goto P_0c035534;
P_0c035532: /* original 64e3, guest PC 0x0c035532 */
if(!s->budget--) { s->failed_pc=0x0c035532u; return 0; }
r[4]=r[14];
goto P_0c035534;
P_0c035534: /* original 8800, guest PC 0x0c035534 */
if(!s->budget--) { s->failed_pc=0x0c035534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c035536;
P_0c035536: /* original 8d0e, guest PC 0x0c035536 */
if(!s->budget--) { s->failed_pc=0x0c035536u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c035556; }
goto P_0c03553a;
P_0c035538: /* original 6403, guest PC 0x0c035538 */
if(!s->budget--) { s->failed_pc=0x0c035538u; return 0; }
r[4]=r[0];
goto P_0c03553a;
P_0c03553a: /* original 8801, guest PC 0x0c03553a */
if(!s->budget--) { s->failed_pc=0x0c03553au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03553c;
P_0c03553c: /* original 890d, guest PC 0x0c03553c */
if(!s->budget--) { s->failed_pc=0x0c03553cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555a; }
goto P_0c03553e;
P_0c03553e: /* original 8802, guest PC 0x0c03553e */
if(!s->budget--) { s->failed_pc=0x0c03553eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035540;
P_0c035540: /* original 890d, guest PC 0x0c035540 */
if(!s->budget--) { s->failed_pc=0x0c035540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035542;
P_0c035542: /* original 8803, guest PC 0x0c035542 */
if(!s->budget--) { s->failed_pc=0x0c035542u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c035544;
P_0c035544: /* original 890b, guest PC 0x0c035544 */
if(!s->budget--) { s->failed_pc=0x0c035544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035546;
P_0c035546: /* original 8804, guest PC 0x0c035546 */
if(!s->budget--) { s->failed_pc=0x0c035546u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c035548;
P_0c035548: /* original 8909, guest PC 0x0c035548 */
if(!s->budget--) { s->failed_pc=0x0c035548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c03554a;
P_0c03554a: /* original 8805, guest PC 0x0c03554a */
if(!s->budget--) { s->failed_pc=0x0c03554au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03554c;
P_0c03554c: /* original 890d, guest PC 0x0c03554c */
if(!s->budget--) { s->failed_pc=0x0c03554cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c03554e;
P_0c03554e: /* original 8806, guest PC 0x0c03554e */
if(!s->budget--) { s->failed_pc=0x0c03554eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c035550;
P_0c035550: /* original 890b, guest PC 0x0c035550 */
if(!s->budget--) { s->failed_pc=0x0c035550u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c035552;
P_0c035552: /* original a00d, guest PC 0x0c035552 */
if(!s->budget--) { s->failed_pc=0x0c035552u; return 0; }
goto P_0c035570;
P_0c035554: /* original 0009, guest PC 0x0c035554 */
if(!s->budget--) { s->failed_pc=0x0c035554u; return 0; }
goto P_0c035556;
P_0c035556: /* original a013, guest PC 0x0c035556 */
if(!s->budget--) { s->failed_pc=0x0c035556u; return 0; }
r[0]=0xffffffe0u;
goto P_0c035580;
P_0c035558: /* original e0e0, guest PC 0x0c035558 */
if(!s->budget--) { s->failed_pc=0x0c035558u; return 0; }
r[0]=0xffffffe0u;
goto P_0c03555a;
P_0c03555a: /* original a011, guest PC 0x0c03555a */
if(!s->budget--) { s->failed_pc=0x0c03555au; return 0; }
r[0]=0x00000000u;
goto P_0c035580;
P_0c03555c: /* original e000, guest PC 0x0c03555c */
if(!s->budget--) { s->failed_pc=0x0c03555cu; return 0; }
r[0]=0x00000000u;
goto P_0c03555e;
P_0c03555e: /* original 53e6, guest PC 0x0c03555e */
if(!s->budget--) { s->failed_pc=0x0c03555eu; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c035560;
P_0c035560: /* original 3b30, guest PC 0x0c035560 */
if(!s->budget--) { s->failed_pc=0x0c035560u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c035562;
P_0c035562: /* original 8907, guest PC 0x0c035562 */
if(!s->budget--) { s->failed_pc=0x0c035562u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035574; }
goto P_0c035564;
P_0c035564: /* original d120, guest PC 0x0c035564 */
if(!s->budget--) { s->failed_pc=0x0c035564u; return 0; }
r[1]=read(ram,0x0c0355e8u,4);
goto P_0c035566;
P_0c035566: /* original a005, guest PC 0x0c035566 */
if(!s->budget--) { s->failed_pc=0x0c035566u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c035574;
P_0c035568: /* original 6d12, guest PC 0x0c035568 */
if(!s->budget--) { s->failed_pc=0x0c035568u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c03556a;
P_0c03556a: /* original e04e, guest PC 0x0c03556a */
if(!s->budget--) { s->failed_pc=0x0c03556au; return 0; }
r[0]=0x0000004eu;
goto P_0c03556c;
P_0c03556c: /* original a008, guest PC 0x0c03556c */
if(!s->budget--) { s->failed_pc=0x0c03556cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035580;
P_0c03556e: /* original 00ed, guest PC 0x0c03556e */
if(!s->budget--) { s->failed_pc=0x0c03556eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035570;
P_0c035570: /* original a006, guest PC 0x0c035570 */
if(!s->budget--) { s->failed_pc=0x0c035570u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035580;
P_0c035572: /* original e0e7, guest PC 0x0c035572 */
if(!s->budget--) { s->failed_pc=0x0c035572u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035574;
P_0c035574: /* original d31c, guest PC 0x0c035574 */
if(!s->budget--) { s->failed_pc=0x0c035574u; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c035576;
P_0c035576: /* original 6432, guest PC 0x0c035576 */
if(!s->budget--) { s->failed_pc=0x0c035576u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c035578;
P_0c035578: /* original 34d8, guest PC 0x0c035578 */
if(!s->budget--) { s->failed_pc=0x0c035578u; return 0; }
r[4]-=r[13];
goto P_0c03557a;
P_0c03557a: /* original 34c6, guest PC 0x0c03557a */
if(!s->budget--) { s->failed_pc=0x0c03557au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[12])!=0);
goto P_0c03557c;
P_0c03557c: /* original 8bd2, guest PC 0x0c03557c */
if(!s->budget--) { s->failed_pc=0x0c03557cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035524; }
goto P_0c03557e;
P_0c03557e: /* original e0eb, guest PC 0x0c03557e */
if(!s->budget--) { s->failed_pc=0x0c03557eu; return 0; }
r[0]=0xffffffebu;
goto P_0c035580;
P_0c035580: /* original 4f26, guest PC 0x0c035580 */
if(!s->budget--) { s->failed_pc=0x0c035580u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035582;
P_0c035582: /* original 6af6, guest PC 0x0c035582 */
if(!s->budget--) { s->failed_pc=0x0c035582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035584;
P_0c035584: /* original 6bf6, guest PC 0x0c035584 */
if(!s->budget--) { s->failed_pc=0x0c035584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035586;
P_0c035586: /* original 6cf6, guest PC 0x0c035586 */
if(!s->budget--) { s->failed_pc=0x0c035586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035588;
P_0c035588: /* original 6df6, guest PC 0x0c035588 */
if(!s->budget--) { s->failed_pc=0x0c035588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03558a;
P_0c03558a: /* original 000b, guest PC 0x0c03558a */
if(!s->budget--) { s->failed_pc=0x0c03558au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03558c: /* original 6ef6, guest PC 0x0c03558c */
if(!s->budget--) { s->failed_pc=0x0c03558cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03558eu,s,ram);
P_0c03628a: /* original 4f22, guest PC 0x0c03628a */
if(!s->budget--) { s->failed_pc=0x0c03628au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03628c;
P_0c03628c: /* original d316, guest PC 0x0c03628c */
if(!s->budget--) { s->failed_pc=0x0c03628cu; return 0; }
r[3]=read(ram,0x0c0362e8u,4);
goto P_0c03628e;
P_0c03628e: /* original b17d, guest PC 0x0c03628e */
if(!s->budget--) { s->failed_pc=0x0c03628eu; return 0; }
target=0x0c03658cu; r[16]=0x0c036292u;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036292u) { target=s->pc; goto dispatch; }
goto P_0c036292;
P_0c036290: /* original 2f36, guest PC 0x0c036290 */
if(!s->budget--) { s->failed_pc=0x0c036290u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c036292;
P_0c036292: /* original d116, guest PC 0x0c036292 */
if(!s->budget--) { s->failed_pc=0x0c036292u; return 0; }
r[1]=read(ram,0x0c0362ecu,4);
goto P_0c036294;
P_0c036294: /* original 9021, guest PC 0x0c036294 */
if(!s->budget--) { s->failed_pc=0x0c036294u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362dau,2);
goto P_0c036296;
P_0c036296: /* original 6412, guest PC 0x0c036296 */
if(!s->budget--) { s->failed_pc=0x0c036296u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c036298;
P_0c036298: /* original 034e, guest PC 0x0c036298 */
if(!s->budget--) { s->failed_pc=0x0c036298u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c03629a;
P_0c03629a: /* original 2338, guest PC 0x0c03629a */
if(!s->budget--) { s->failed_pc=0x0c03629au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03629c;
P_0c03629c: /* original 8d07, guest PC 0x0c03629c */
if(!s->budget--) { s->failed_pc=0x0c03629cu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c0362ae; }
goto P_0c0362a0;
P_0c03629e: /* original 7f04, guest PC 0x0c03629e */
if(!s->budget--) { s->failed_pc=0x0c03629eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0362a0;
P_0c0362a0: /* original d313, guest PC 0x0c0362a0 */
if(!s->budget--) { s->failed_pc=0x0c0362a0u; return 0; }
r[3]=read(ram,0x0c0362f0u,4);
goto P_0c0362a2;
P_0c0362a2: /* original b173, guest PC 0x0c0362a2 */
if(!s->budget--) { s->failed_pc=0x0c0362a2u; return 0; }
target=0x0c03658cu; r[16]=0x0c0362a6u;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0362a6u) { target=s->pc; goto dispatch; }
goto P_0c0362a6;
P_0c0362a4: /* original 2f36, guest PC 0x0c0362a4 */
if(!s->budget--) { s->failed_pc=0x0c0362a4u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0362a6;
P_0c0362a6: /* original 7f04, guest PC 0x0c0362a6 */
if(!s->budget--) { s->failed_pc=0x0c0362a6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0362a8;
P_0c0362a8: /* original 4f26, guest PC 0x0c0362a8 */
if(!s->budget--) { s->failed_pc=0x0c0362a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0362aa;
P_0c0362aa: /* original 000b, guest PC 0x0c0362aa */
if(!s->budget--) { s->failed_pc=0x0c0362aau; return 0; }
target=r[16];
r[0]=0xfffffffdu;
s->pc=target; return ram->oob==0;
P_0c0362ac: /* original e0fd, guest PC 0x0c0362ac */
if(!s->budget--) { s->failed_pc=0x0c0362acu; return 0; }
r[0]=0xfffffffdu;
goto P_0c0362ae;
P_0c0362ae: /* original 900e, guest PC 0x0c0362ae */
if(!s->budget--) { s->failed_pc=0x0c0362aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362ceu,2);
goto P_0c0362b0;
P_0c0362b0: /* original 034e, guest PC 0x0c0362b0 */
if(!s->budget--) { s->failed_pc=0x0c0362b0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0362b2;
P_0c0362b2: /* original 5036, guest PC 0x0c0362b2 */
if(!s->budget--) { s->failed_pc=0x0c0362b2u; return 0; }
r[0]=read(ram,r[3]+24,4);
goto P_0c0362b4;
P_0c0362b4: /* original c801, guest PC 0x0c0362b4 */
if(!s->budget--) { s->failed_pc=0x0c0362b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0362b6;
P_0c0362b6: /* original 891f, guest PC 0x0c0362b6 */
if(!s->budget--) { s->failed_pc=0x0c0362b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0362f8; }
goto P_0c0362b8;
P_0c0362b8: /* original d20e, guest PC 0x0c0362b8 */
if(!s->budget--) { s->failed_pc=0x0c0362b8u; return 0; }
r[2]=read(ram,0x0c0362f4u,4);
goto P_0c0362ba;
P_0c0362ba: /* original b167, guest PC 0x0c0362ba */
if(!s->budget--) { s->failed_pc=0x0c0362bau; return 0; }
target=0x0c03658cu; r[16]=0x0c0362beu;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0362beu) { target=s->pc; goto dispatch; }
goto P_0c0362be;
P_0c0362bc: /* original 2f26, guest PC 0x0c0362bc */
if(!s->budget--) { s->failed_pc=0x0c0362bcu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0362be;
P_0c0362be: /* original 7f04, guest PC 0x0c0362be */
if(!s->budget--) { s->failed_pc=0x0c0362beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0362c0;
P_0c0362c0: /* original 4f26, guest PC 0x0c0362c0 */
if(!s->budget--) { s->failed_pc=0x0c0362c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0362c2;
P_0c0362c2: /* original 000b, guest PC 0x0c0362c2 */
if(!s->budget--) { s->failed_pc=0x0c0362c2u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c0362c4: /* original e0ff, guest PC 0x0c0362c4 */
if(!s->budget--) { s->failed_pc=0x0c0362c4u; return 0; }
r[0]=0xffffffffu;
return vf3_matrix_family(0x0c0362c6u,s,ram);
P_0c0362f8: /* original d23b, guest PC 0x0c0362f8 */
if(!s->budget--) { s->failed_pc=0x0c0362f8u; return 0; }
r[2]=read(ram,0x0c0363e8u,4);
goto P_0c0362fa;
P_0c0362fa: /* original b147, guest PC 0x0c0362fa */
if(!s->budget--) { s->failed_pc=0x0c0362fau; return 0; }
target=0x0c03658cu; r[16]=0x0c0362feu;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0362feu) { target=s->pc; goto dispatch; }
goto P_0c0362fe;
P_0c0362fc: /* original 2f26, guest PC 0x0c0362fc */
if(!s->budget--) { s->failed_pc=0x0c0362fcu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0362fe;
P_0c0362fe: /* original d33b, guest PC 0x0c0362fe */
if(!s->budget--) { s->failed_pc=0x0c0362feu; return 0; }
r[3]=read(ram,0x0c0363ecu,4);
goto P_0c036300;
P_0c036300: /* original 6032, guest PC 0x0c036300 */
if(!s->budget--) { s->failed_pc=0x0c036300u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c036302;
P_0c036302: /* original 401b, guest PC 0x0c036302 */
if(!s->budget--) { s->failed_pc=0x0c036302u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c036304;
P_0c036304: /* original 8d07, guest PC 0x0c036304 */
if(!s->budget--) { s->failed_pc=0x0c036304u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c036316; }
goto P_0c036308;
P_0c036306: /* original 7f04, guest PC 0x0c036306 */
if(!s->budget--) { s->failed_pc=0x0c036306u; return 0; }
r[15]+=0x00000004u;
goto P_0c036308;
P_0c036308: /* original d139, guest PC 0x0c036308 */
if(!s->budget--) { s->failed_pc=0x0c036308u; return 0; }
r[1]=read(ram,0x0c0363f0u,4);
goto P_0c03630a;
P_0c03630a: /* original b13f, guest PC 0x0c03630a */
if(!s->budget--) { s->failed_pc=0x0c03630au; return 0; }
target=0x0c03658cu; r[16]=0x0c03630eu;
r[15]-=4; write(ram,r[15],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03630eu) { target=s->pc; goto dispatch; }
goto P_0c03630e;
P_0c03630c: /* original 2f16, guest PC 0x0c03630c */
if(!s->budget--) { s->failed_pc=0x0c03630cu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c03630e;
P_0c03630e: /* original 7f04, guest PC 0x0c03630e */
if(!s->budget--) { s->failed_pc=0x0c03630eu; return 0; }
r[15]+=0x00000004u;
goto P_0c036310;
P_0c036310: /* original 4f26, guest PC 0x0c036310 */
if(!s->budget--) { s->failed_pc=0x0c036310u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036312;
P_0c036312: /* original 000b, guest PC 0x0c036312 */
if(!s->budget--) { s->failed_pc=0x0c036312u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c036314: /* original e0fe, guest PC 0x0c036314 */
if(!s->budget--) { s->failed_pc=0x0c036314u; return 0; }
r[0]=0xfffffffeu;
goto P_0c036316;
P_0c036316: /* original e000, guest PC 0x0c036316 */
if(!s->budget--) { s->failed_pc=0x0c036316u; return 0; }
r[0]=0x00000000u;
goto P_0c036318;
P_0c036318: /* original 4f26, guest PC 0x0c036318 */
if(!s->budget--) { s->failed_pc=0x0c036318u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03631a;
P_0c03631a: /* original 000b, guest PC 0x0c03631a */
if(!s->budget--) { s->failed_pc=0x0c03631au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03631c: /* original 0009, guest PC 0x0c03631c */
if(!s->budget--) { s->failed_pc=0x0c03631cu; return 0; }
return vf3_matrix_family(0x0c03631eu,s,ram);
P_0c038fe4: /* original 4f22, guest PC 0x0c038fe4 */
if(!s->budget--) { s->failed_pc=0x0c038fe4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038fe6;
P_0c038fe6: /* original d74c, guest PC 0x0c038fe6 */
if(!s->budget--) { s->failed_pc=0x0c038fe6u; return 0; }
r[7]=read(ram,0x0c039118u,4);
goto P_0c038fe8;
P_0c038fe8: /* original 7f94, guest PC 0x0c038fe8 */
if(!s->budget--) { s->failed_pc=0x0c038fe8u; return 0; }
r[15]+=0xffffff94u;
goto P_0c038fea;
P_0c038fea: /* original 2742, guest PC 0x0c038fea */
if(!s->budget--) { s->failed_pc=0x0c038feau; return 0; }
write(ram,r[7],r[4],4);
goto P_0c038fec;
P_0c038fec: /* original 1751, guest PC 0x0c038fec */
if(!s->budget--) { s->failed_pc=0x0c038fecu; return 0; }
write(ram,r[7]+4,r[5],4);
goto P_0c038fee;
P_0c038fee: /* original 1762, guest PC 0x0c038fee */
if(!s->budget--) { s->failed_pc=0x0c038feeu; return 0; }
write(ram,r[7]+8,r[6],4);
goto P_0c038ff0;
P_0c038ff0: /* original 67f3, guest PC 0x0c038ff0 */
if(!s->budget--) { s->failed_pc=0x0c038ff0u; return 0; }
r[7]=r[15];
goto P_0c038ff2;
P_0c038ff2: /* original 770c, guest PC 0x0c038ff2 */
if(!s->budget--) { s->failed_pc=0x0c038ff2u; return 0; }
r[7]+=0x0000000cu;
goto P_0c038ff4;
P_0c038ff4: /* original d349, guest PC 0x0c038ff4 */
if(!s->budget--) { s->failed_pc=0x0c038ff4u; return 0; }
r[3]=read(ram,0x0c03911cu,4);
goto P_0c038ff6;
P_0c038ff6: /* original 6273, guest PC 0x0c038ff6 */
if(!s->budget--) { s->failed_pc=0x0c038ff6u; return 0; }
r[2]=r[7];
goto P_0c038ff8;
P_0c038ff8: /* original 6123, guest PC 0x0c038ff8 */
if(!s->budget--) { s->failed_pc=0x0c038ff8u; return 0; }
r[1]=r[2];
goto P_0c038ffa;
P_0c038ffa: /* original 7120, guest PC 0x0c038ffa */
if(!s->budget--) { s->failed_pc=0x0c038ffau; return 0; }
r[1]+=0x00000020u;
goto P_0c038ffc;
P_0c038ffc: /* original 2232, guest PC 0x0c038ffc */
if(!s->budget--) { s->failed_pc=0x0c038ffcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c038ffe;
P_0c038ffe: /* original f48d, guest PC 0x0c038ffe */
if(!s->budget--) { s->failed_pc=0x0c038ffeu; return 0; }
fr[4]=0;
goto P_0c039000;
P_0c039000: /* original f247, guest PC 0x0c039000 */
if(!s->budget--) { s->failed_pc=0x0c039000u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039002;
P_0c039002: /* original e008, guest PC 0x0c039002 */
if(!s->budget--) { s->failed_pc=0x0c039002u; return 0; }
r[0]=0x00000008u;
goto P_0c039004;
P_0c039004: /* original f247, guest PC 0x0c039004 */
if(!s->budget--) { s->failed_pc=0x0c039004u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039006;
P_0c039006: /* original c746, guest PC 0x0c039006 */
if(!s->budget--) { s->failed_pc=0x0c039006u; return 0; }
r[0]=0x0c039120u;
goto P_0c039008;
P_0c039008: /* original f508, guest PC 0x0c039008 */
if(!s->budget--) { s->failed_pc=0x0c039008u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03900a;
P_0c03900a: /* original e00c, guest PC 0x0c03900a */
if(!s->budget--) { s->failed_pc=0x0c03900au; return 0; }
r[0]=0x0000000cu;
goto P_0c03900c;
P_0c03900c: /* original f257, guest PC 0x0c03900c */
if(!s->budget--) { s->failed_pc=0x0c03900cu; return 0; }
vf3_matrix_store(s,ram,5,r[2]+r[0]);
goto P_0c03900e;
P_0c03900e: /* original 1244, guest PC 0x0c03900e */
if(!s->budget--) { s->failed_pc=0x0c03900eu; return 0; }
write(ram,r[2]+16,r[4],4);
goto P_0c039010;
P_0c039010: /* original 1246, guest PC 0x0c039010 */
if(!s->budget--) { s->failed_pc=0x0c039010u; return 0; }
write(ram,r[2]+24,r[4],4);
goto P_0c039012;
P_0c039012: /* original 2132, guest PC 0x0c039012 */
if(!s->budget--) { s->failed_pc=0x0c039012u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c039014;
P_0c039014: /* original dc43, guest PC 0x0c039014 */
if(!s->budget--) { s->failed_pc=0x0c039014u; return 0; }
r[12]=read(ram,0x0c039124u,4);
goto P_0c039016;
P_0c039016: /* original 85c2, guest PC 0x0c039016 */
if(!s->budget--) { s->failed_pc=0x0c039016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c039018;
P_0c039018: /* original 6403, guest PC 0x0c039018 */
if(!s->budget--) { s->failed_pc=0x0c039018u; return 0; }
r[4]=r[0];
goto P_0c03901a;
P_0c03901a: /* original 85c5, guest PC 0x0c03901a */
if(!s->budget--) { s->failed_pc=0x0c03901au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+10,2);
goto P_0c03901c;
P_0c03901c: /* original 2008, guest PC 0x0c03901c */
if(!s->budget--) { s->failed_pc=0x0c03901cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03901e;
P_0c03901e: /* original 8907, guest PC 0x0c03901e */
if(!s->budget--) { s->failed_pc=0x0c03901eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039030; }
goto P_0c039020;
P_0c039020: /* original 644f, guest PC 0x0c039020 */
if(!s->budget--) { s->failed_pc=0x0c039020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039022;
P_0c039022: /* original a006, guest PC 0x0c039022 */
if(!s->budget--) { s->failed_pc=0x0c039022u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c039032;
P_0c039024: /* original 4400, guest PC 0x0c039024 */
if(!s->budget--) { s->failed_pc=0x0c039024u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
return vf3_matrix_family(0x0c039026u,s,ram);
P_0c039030: /* original 644f, guest PC 0x0c039030 */
if(!s->budget--) { s->failed_pc=0x0c039030u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039032;
P_0c039032: /* original 445a, guest PC 0x0c039032 */
if(!s->budget--) { s->failed_pc=0x0c039032u; return 0; }
r[53]=r[4];
goto P_0c039034;
P_0c039034: /* original e004, guest PC 0x0c039034 */
if(!s->budget--) { s->failed_pc=0x0c039034u; return 0; }
r[0]=0x00000004u;
goto P_0c039036;
P_0c039036: /* original 6473, guest PC 0x0c039036 */
if(!s->budget--) { s->failed_pc=0x0c039036u; return 0; }
r[4]=r[7];
goto P_0c039038;
P_0c039038: /* original 7440, guest PC 0x0c039038 */
if(!s->budget--) { s->failed_pc=0x0c039038u; return 0; }
r[4]+=0x00000040u;
goto P_0c03903a;
P_0c03903a: /* original f32d, guest PC 0x0c03903a */
if(!s->budget--) { s->failed_pc=0x0c03903au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03903c;
P_0c03903c: /* original f137, guest PC 0x0c03903c */
if(!s->budget--) { s->failed_pc=0x0c03903cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c03903e;
P_0c03903e: /* original e008, guest PC 0x0c03903e */
if(!s->budget--) { s->failed_pc=0x0c03903eu; return 0; }
r[0]=0x00000008u;
goto P_0c039040;
P_0c039040: /* original f147, guest PC 0x0c039040 */
if(!s->budget--) { s->failed_pc=0x0c039040u; return 0; }
vf3_matrix_store(s,ram,4,r[1]+r[0]);
goto P_0c039042;
P_0c039042: /* original e00c, guest PC 0x0c039042 */
if(!s->budget--) { s->failed_pc=0x0c039042u; return 0; }
r[0]=0x0000000cu;
goto P_0c039044;
P_0c039044: /* original f157, guest PC 0x0c039044 */
if(!s->budget--) { s->failed_pc=0x0c039044u; return 0; }
vf3_matrix_store(s,ram,5,r[1]+r[0]);
goto P_0c039046;
P_0c039046: /* original e004, guest PC 0x0c039046 */
if(!s->budget--) { s->failed_pc=0x0c039046u; return 0; }
r[0]=0x00000004u;
goto P_0c039048;
P_0c039048: /* original 1154, guest PC 0x0c039048 */
if(!s->budget--) { s->failed_pc=0x0c039048u; return 0; }
write(ram,r[1]+16,r[5],4);
goto P_0c03904a;
P_0c03904a: /* original 1156, guest PC 0x0c03904a */
if(!s->budget--) { s->failed_pc=0x0c03904au; return 0; }
write(ram,r[1]+24,r[5],4);
goto P_0c03904c;
P_0c03904c: /* original e500, guest PC 0x0c03904c */
if(!s->budget--) { s->failed_pc=0x0c03904cu; return 0; }
r[5]=0x00000000u;
goto P_0c03904e;
P_0c03904e: /* original d336, guest PC 0x0c03904e */
if(!s->budget--) { s->failed_pc=0x0c03904eu; return 0; }
r[3]=read(ram,0x0c039128u,4);
goto P_0c039050;
P_0c039050: /* original 2432, guest PC 0x0c039050 */
if(!s->budget--) { s->failed_pc=0x0c039050u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c039052;
P_0c039052: /* original f447, guest PC 0x0c039052 */
if(!s->budget--) { s->failed_pc=0x0c039052u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c039054;
P_0c039054: /* original 85c3, guest PC 0x0c039054 */
if(!s->budget--) { s->failed_pc=0x0c039054u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c039056;
P_0c039056: /* original 6cf3, guest PC 0x0c039056 */
if(!s->budget--) { s->failed_pc=0x0c039056u; return 0; }
r[12]=r[15];
goto P_0c039058;
P_0c039058: /* original 6303, guest PC 0x0c039058 */
if(!s->budget--) { s->failed_pc=0x0c039058u; return 0; }
r[3]=r[0];
goto P_0c03905a;
P_0c03905a: /* original 435a, guest PC 0x0c03905a */
if(!s->budget--) { s->failed_pc=0x0c03905au; return 0; }
r[53]=r[3];
goto P_0c03905c;
P_0c03905c: /* original e008, guest PC 0x0c03905c */
if(!s->budget--) { s->failed_pc=0x0c03905cu; return 0; }
r[0]=0x00000008u;
goto P_0c03905e;
P_0c03905e: /* original f32d, guest PC 0x0c03905e */
if(!s->budget--) { s->failed_pc=0x0c03905eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039060;
P_0c039060: /* original f437, guest PC 0x0c039060 */
if(!s->budget--) { s->failed_pc=0x0c039060u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c039062;
P_0c039062: /* original e00c, guest PC 0x0c039062 */
if(!s->budget--) { s->failed_pc=0x0c039062u; return 0; }
r[0]=0x0000000cu;
goto P_0c039064;
P_0c039064: /* original f457, guest PC 0x0c039064 */
if(!s->budget--) { s->failed_pc=0x0c039064u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c039066;
P_0c039066: /* original 1464, guest PC 0x0c039066 */
if(!s->budget--) { s->failed_pc=0x0c039066u; return 0; }
write(ram,r[4]+16,r[6],4);
goto P_0c039068;
P_0c039068: /* original 1466, guest PC 0x0c039068 */
if(!s->budget--) { s->failed_pc=0x0c039068u; return 0; }
write(ram,r[4]+24,r[6],4);
goto P_0c03906a;
P_0c03906a: /* original e620, guest PC 0x0c03906a */
if(!s->budget--) { s->failed_pc=0x0c03906au; return 0; }
r[6]=0x00000020u;
goto P_0c03906c;
P_0c03906c: /* original 2c22, guest PC 0x0c03906c */
if(!s->budget--) { s->failed_pc=0x0c03906cu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c03906e;
P_0c03906e: /* original 1c11, guest PC 0x0c03906e */
if(!s->budget--) { s->failed_pc=0x0c03906eu; return 0; }
write(ram,r[12]+4,r[1],4);
goto P_0c039070;
P_0c039070: /* original 1c42, guest PC 0x0c039070 */
if(!s->budget--) { s->failed_pc=0x0c039070u; return 0; }
write(ram,r[12]+8,r[4],4);
goto P_0c039072;
P_0c039072: /* original d32e, guest PC 0x0c039072 */
if(!s->budget--) { s->failed_pc=0x0c039072u; return 0; }
r[3]=read(ram,0x0c03912cu,4);
goto P_0c039074;
P_0c039074: /* original 430b, guest PC 0x0c039074 */
if(!s->budget--) { s->failed_pc=0x0c039074u; return 0; }
target=r[3];
r[16]=0x0c039078u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c039078u) { target=s->pc; goto dispatch; }
goto P_0c039078;
P_0c039076: /* original 64c3, guest PC 0x0c039076 */
if(!s->budget--) { s->failed_pc=0x0c039076u; return 0; }
r[4]=r[12];
goto P_0c039078;
P_0c039078: /* original 7f6c, guest PC 0x0c039078 */
if(!s->budget--) { s->failed_pc=0x0c039078u; return 0; }
r[15]+=0x0000006cu;
goto P_0c03907a;
P_0c03907a: /* original 4f26, guest PC 0x0c03907a */
if(!s->budget--) { s->failed_pc=0x0c03907au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03907c;
P_0c03907c: /* original 000b, guest PC 0x0c03907c */
if(!s->budget--) { s->failed_pc=0x0c03907cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c03907e: /* original 6cf6, guest PC 0x0c03907e */
if(!s->budget--) { s->failed_pc=0x0c03907eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
return vf3_matrix_family(0x0c039080u,s,ram);
P_0c03e442: /* original 4f22, guest PC 0x0c03e442 */
if(!s->budget--) { s->failed_pc=0x0c03e442u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e444;
P_0c03e444: /* original 4f12, guest PC 0x0c03e444 */
if(!s->budget--) { s->failed_pc=0x0c03e444u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e446;
P_0c03e446: /* original 7ff8, guest PC 0x0c03e446 */
if(!s->budget--) { s->failed_pc=0x0c03e446u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03e448;
P_0c03e448: /* original 8f02, guest PC 0x0c03e448 */
if(!s->budget--) { s->failed_pc=0x0c03e448u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c03e450; }
goto P_0c03e44c;
P_0c03e44a: /* original 1f31, guest PC 0x0c03e44a */
if(!s->budget--) { s->failed_pc=0x0c03e44au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03e44c;
P_0c03e44c: /* original a049, guest PC 0x0c03e44c */
if(!s->budget--) { s->failed_pc=0x0c03e44cu; return 0; }
r[0]=0x00000000u;
goto P_0c03e4e2;
P_0c03e44e: /* original e000, guest PC 0x0c03e44e */
if(!s->budget--) { s->failed_pc=0x0c03e44eu; return 0; }
r[0]=0x00000000u;
goto P_0c03e450;
P_0c03e450: /* original 6342, guest PC 0x0c03e450 */
if(!s->budget--) { s->failed_pc=0x0c03e450u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03e452;
P_0c03e452: /* original 2f32, guest PC 0x0c03e452 */
if(!s->budget--) { s->failed_pc=0x0c03e452u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03e454;
P_0c03e454: /* original 5941, guest PC 0x0c03e454 */
if(!s->budget--) { s->failed_pc=0x0c03e454u; return 0; }
r[9]=read(ram,r[4]+4,4);
goto P_0c03e456;
P_0c03e456: /* original de56, guest PC 0x0c03e456 */
if(!s->budget--) { s->failed_pc=0x0c03e456u; return 0; }
r[14]=read(ram,0x0c03e5b0u,4);
goto P_0c03e458;
P_0c03e458: /* original dd57, guest PC 0x0c03e458 */
if(!s->budget--) { s->failed_pc=0x0c03e458u; return 0; }
r[13]=read(ram,0x0c03e5b8u,4);
goto P_0c03e45a;
P_0c03e45a: /* original 2998, guest PC 0x0c03e45a */
if(!s->budget--) { s->failed_pc=0x0c03e45au; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c03e45c;
P_0c03e45c: /* original 8d40, guest PC 0x0c03e45c */
if(!s->budget--) { s->failed_pc=0x0c03e45cu; return 0; }
cond=r[17]&1u;
r[11]=0xffffffffu;
if(cond) { goto P_0c03e4e0; }
goto P_0c03e460;
P_0c03e45e: /* original ebff, guest PC 0x0c03e45e */
if(!s->budget--) { s->failed_pc=0x0c03e45eu; return 0; }
r[11]=0xffffffffu;
goto P_0c03e460;
P_0c03e460: /* original d252, guest PC 0x0c03e460 */
if(!s->budget--) { s->failed_pc=0x0c03e460u; return 0; }
r[2]=read(ram,0x0c03e5acu,4);
goto P_0c03e462;
P_0c03e462: /* original 64f2, guest PC 0x0c03e462 */
if(!s->budget--) { s->failed_pc=0x0c03e462u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03e464;
P_0c03e464: /* original 6322, guest PC 0x0c03e464 */
if(!s->budget--) { s->failed_pc=0x0c03e464u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03e466;
P_0c03e466: /* original 6442, guest PC 0x0c03e466 */
if(!s->budget--) { s->failed_pc=0x0c03e466u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c03e468;
P_0c03e468: /* original 60e2, guest PC 0x0c03e468 */
if(!s->budget--) { s->failed_pc=0x0c03e468u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03e46a;
P_0c03e46a: /* original 343c, guest PC 0x0c03e46a */
if(!s->budget--) { s->failed_pc=0x0c03e46au; return 0; }
r[4]+=r[3];
goto P_0c03e46c;
P_0c03e46c: /* original 6143, guest PC 0x0c03e46c */
if(!s->budget--) { s->failed_pc=0x0c03e46cu; return 0; }
r[1]=r[4];
goto P_0c03e46e;
P_0c03e46e: /* original 4108, guest PC 0x0c03e46e */
if(!s->budget--) { s->failed_pc=0x0c03e46eu; return 0; }
r[1]<<=2;
goto P_0c03e470;
P_0c03e470: /* original 4100, guest PC 0x0c03e470 */
if(!s->budget--) { s->failed_pc=0x0c03e470u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c03e472;
P_0c03e472: /* original 011e, guest PC 0x0c03e472 */
if(!s->budget--) { s->failed_pc=0x0c03e472u; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c03e474;
P_0c03e474: /* original e300, guest PC 0x0c03e474 */
if(!s->budget--) { s->failed_pc=0x0c03e474u; return 0; }
r[3]=0x00000000u;
goto P_0c03e476;
P_0c03e476: /* original 3136, guest PC 0x0c03e476 */
if(!s->budget--) { s->failed_pc=0x0c03e476u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c03e478;
P_0c03e478: /* original 8b2d, guest PC 0x0c03e478 */
if(!s->budget--) { s->failed_pc=0x0c03e478u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e4d6; }
goto P_0c03e47a;
P_0c03e47a: /* original 6a43, guest PC 0x0c03e47a */
if(!s->budget--) { s->failed_pc=0x0c03e47au; return 0; }
r[10]=r[4];
goto P_0c03e47c;
P_0c03e47c: /* original 61e2, guest PC 0x0c03e47c */
if(!s->budget--) { s->failed_pc=0x0c03e47cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03e47e;
P_0c03e47e: /* original 4a08, guest PC 0x0c03e47e */
if(!s->budget--) { s->failed_pc=0x0c03e47eu; return 0; }
r[10]<<=2;
goto P_0c03e480;
P_0c03e480: /* original 4a00, guest PC 0x0c03e480 */
if(!s->budget--) { s->failed_pc=0x0c03e480u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c03e482;
P_0c03e482: /* original 31ac, guest PC 0x0c03e482 */
if(!s->budget--) { s->failed_pc=0x0c03e482u; return 0; }
r[1]+=r[10];
goto P_0c03e484;
P_0c03e484: /* original 6012, guest PC 0x0c03e484 */
if(!s->budget--) { s->failed_pc=0x0c03e484u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03e486;
P_0c03e486: /* original 70ff, guest PC 0x0c03e486 */
if(!s->budget--) { s->failed_pc=0x0c03e486u; return 0; }
r[0]+=0xffffffffu;
goto P_0c03e488;
P_0c03e488: /* original 2102, guest PC 0x0c03e488 */
if(!s->budget--) { s->failed_pc=0x0c03e488u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c03e48a;
P_0c03e48a: /* original 61e2, guest PC 0x0c03e48a */
if(!s->budget--) { s->failed_pc=0x0c03e48au; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03e48c;
P_0c03e48c: /* original 31ac, guest PC 0x0c03e48c */
if(!s->budget--) { s->failed_pc=0x0c03e48cu; return 0; }
r[1]+=r[10];
goto P_0c03e48e;
P_0c03e48e: /* original 6012, guest PC 0x0c03e48e */
if(!s->budget--) { s->failed_pc=0x0c03e48eu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03e490;
P_0c03e490: /* original 2008, guest PC 0x0c03e490 */
if(!s->budget--) { s->failed_pc=0x0c03e490u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03e492;
P_0c03e492: /* original 8b20, guest PC 0x0c03e492 */
if(!s->budget--) { s->failed_pc=0x0c03e492u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e4d6; }
goto P_0c03e494;
P_0c03e494: /* original 68e2, guest PC 0x0c03e494 */
if(!s->budget--) { s->failed_pc=0x0c03e494u; return 0; }
tmp=read(ram,r[14],4);
r[8]=tmp;
goto P_0c03e496;
P_0c03e496: /* original ec3c, guest PC 0x0c03e496 */
if(!s->budget--) { s->failed_pc=0x0c03e496u; return 0; }
r[12]=0x0000003cu;
goto P_0c03e498;
P_0c03e498: /* original 61d2, guest PC 0x0c03e498 */
if(!s->budget--) { s->failed_pc=0x0c03e498u; return 0; }
tmp=read(ram,r[13],4);
r[1]=tmp;
goto P_0c03e49a;
P_0c03e49a: /* original 38ac, guest PC 0x0c03e49a */
if(!s->budget--) { s->failed_pc=0x0c03e49au; return 0; }
r[8]+=r[10];
goto P_0c03e49c;
P_0c03e49c: /* original 5881, guest PC 0x0c03e49c */
if(!s->budget--) { s->failed_pc=0x0c03e49cu; return 0; }
r[8]=read(ram,r[8]+4,4);
goto P_0c03e49e;
P_0c03e49e: /* original 08c7, guest PC 0x0c03e49e */
if(!s->budget--) { s->failed_pc=0x0c03e49eu; return 0; }
r[19]=r[8]*r[12];
goto P_0c03e4a0;
P_0c03e4a0: /* original 0c1a, guest PC 0x0c03e4a0 */
if(!s->budget--) { s->failed_pc=0x0c03e4a0u; return 0; }
r[12]=r[19];
goto P_0c03e4a2;
P_0c03e4a2: /* original 31cc, guest PC 0x0c03e4a2 */
if(!s->budget--) { s->failed_pc=0x0c03e4a2u; return 0; }
r[1]+=r[12];
goto P_0c03e4a4;
P_0c03e4a4: /* original 501a, guest PC 0x0c03e4a4 */
if(!s->budget--) { s->failed_pc=0x0c03e4a4u; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c03e4a6;
P_0c03e4a6: /* original 2008, guest PC 0x0c03e4a6 */
if(!s->budget--) { s->failed_pc=0x0c03e4a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03e4a8;
P_0c03e4a8: /* original 8b08, guest PC 0x0c03e4a8 */
if(!s->budget--) { s->failed_pc=0x0c03e4a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e4bc; }
goto P_0c03e4aa;
P_0c03e4aa: /* original d146, guest PC 0x0c03e4aa */
if(!s->budget--) { s->failed_pc=0x0c03e4aau; return 0; }
r[1]=read(ram,0x0c03e5c4u,4);
goto P_0c03e4ac;
P_0c03e4ac: /* original 64d2, guest PC 0x0c03e4ac */
if(!s->budget--) { s->failed_pc=0x0c03e4acu; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c03e4ae;
P_0c03e4ae: /* original 410b, guest PC 0x0c03e4ae */
if(!s->budget--) { s->failed_pc=0x0c03e4aeu; return 0; }
target=r[1];
r[16]=0x0c03e4b2u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e4b2u) { target=s->pc; goto dispatch; }
goto P_0c03e4b2;
P_0c03e4b0: /* original 34cc, guest PC 0x0c03e4b0 */
if(!s->budget--) { s->failed_pc=0x0c03e4b0u; return 0; }
r[4]+=r[12];
goto P_0c03e4b2;
P_0c03e4b2: /* original 6403, guest PC 0x0c03e4b2 */
if(!s->budget--) { s->failed_pc=0x0c03e4b2u; return 0; }
r[4]=r[0];
goto P_0c03e4b4;
P_0c03e4b4: /* original 2448, guest PC 0x0c03e4b4 */
if(!s->budget--) { s->failed_pc=0x0c03e4b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03e4b6;
P_0c03e4b6: /* original 8901, guest PC 0x0c03e4b6 */
if(!s->budget--) { s->failed_pc=0x0c03e4b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e4bc; }
goto P_0c03e4b8;
P_0c03e4b8: /* original e201, guest PC 0x0c03e4b8 */
if(!s->budget--) { s->failed_pc=0x0c03e4b8u; return 0; }
r[2]=0x00000001u;
goto P_0c03e4ba;
P_0c03e4ba: /* original 1f21, guest PC 0x0c03e4ba */
if(!s->budget--) { s->failed_pc=0x0c03e4bau; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03e4bc;
P_0c03e4bc: /* original 63d2, guest PC 0x0c03e4bc */
if(!s->budget--) { s->failed_pc=0x0c03e4bcu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c03e4be;
P_0c03e4be: /* original e200, guest PC 0x0c03e4be */
if(!s->budget--) { s->failed_pc=0x0c03e4beu; return 0; }
r[2]=0x00000000u;
goto P_0c03e4c0;
P_0c03e4c0: /* original 33cc, guest PC 0x0c03e4c0 */
if(!s->budget--) { s->failed_pc=0x0c03e4c0u; return 0; }
r[3]+=r[12];
goto P_0c03e4c2;
P_0c03e4c2: /* original 132b, guest PC 0x0c03e4c2 */
if(!s->budget--) { s->failed_pc=0x0c03e4c2u; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c03e4c4;
P_0c03e4c4: /* original 63d2, guest PC 0x0c03e4c4 */
if(!s->budget--) { s->failed_pc=0x0c03e4c4u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c03e4c6;
P_0c03e4c6: /* original 33cc, guest PC 0x0c03e4c6 */
if(!s->budget--) { s->failed_pc=0x0c03e4c6u; return 0; }
r[3]+=r[12];
goto P_0c03e4c8;
P_0c03e4c8: /* original 13be, guest PC 0x0c03e4c8 */
if(!s->budget--) { s->failed_pc=0x0c03e4c8u; return 0; }
write(ram,r[3]+56,r[11],4);
goto P_0c03e4ca;
P_0c03e4ca: /* original d23f, guest PC 0x0c03e4ca */
if(!s->budget--) { s->failed_pc=0x0c03e4cau; return 0; }
r[2]=read(ram,0x0c03e5c8u,4);
goto P_0c03e4cc;
P_0c03e4cc: /* original 420b, guest PC 0x0c03e4cc */
if(!s->budget--) { s->failed_pc=0x0c03e4ccu; return 0; }
target=r[2];
r[16]=0x0c03e4d0u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e4d0u) { target=s->pc; goto dispatch; }
goto P_0c03e4d0;
P_0c03e4ce: /* original 6483, guest PC 0x0c03e4ce */
if(!s->budget--) { s->failed_pc=0x0c03e4ceu; return 0; }
r[4]=r[8];
goto P_0c03e4d0;
P_0c03e4d0: /* original 63e2, guest PC 0x0c03e4d0 */
if(!s->budget--) { s->failed_pc=0x0c03e4d0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03e4d2;
P_0c03e4d2: /* original 33ac, guest PC 0x0c03e4d2 */
if(!s->budget--) { s->failed_pc=0x0c03e4d2u; return 0; }
r[3]+=r[10];
goto P_0c03e4d4;
P_0c03e4d4: /* original 13b1, guest PC 0x0c03e4d4 */
if(!s->budget--) { s->failed_pc=0x0c03e4d4u; return 0; }
write(ram,r[3]+4,r[11],4);
goto P_0c03e4d6;
P_0c03e4d6: /* original 62f2, guest PC 0x0c03e4d6 */
if(!s->budget--) { s->failed_pc=0x0c03e4d6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03e4d8;
P_0c03e4d8: /* original 4910, guest PC 0x0c03e4d8 */
if(!s->budget--) { s->failed_pc=0x0c03e4d8u; return 0; }
--r[9];
r[17]=(r[17]&~1u)|((r[9]==0)!=0);
goto P_0c03e4da;
P_0c03e4da: /* original 720c, guest PC 0x0c03e4da */
if(!s->budget--) { s->failed_pc=0x0c03e4dau; return 0; }
r[2]+=0x0000000cu;
goto P_0c03e4dc;
P_0c03e4dc: /* original 8fc0, guest PC 0x0c03e4dc */
if(!s->budget--) { s->failed_pc=0x0c03e4dcu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(!cond) { goto P_0c03e460; }
goto P_0c03e4e0;
P_0c03e4de: /* original 2f22, guest PC 0x0c03e4de */
if(!s->budget--) { s->failed_pc=0x0c03e4deu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c03e4e0;
P_0c03e4e0: /* original 50f1, guest PC 0x0c03e4e0 */
if(!s->budget--) { s->failed_pc=0x0c03e4e0u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c03e4e2;
P_0c03e4e2: /* original 7f08, guest PC 0x0c03e4e2 */
if(!s->budget--) { s->failed_pc=0x0c03e4e2u; return 0; }
r[15]+=0x00000008u;
goto P_0c03e4e4;
P_0c03e4e4: /* original 4f16, guest PC 0x0c03e4e4 */
if(!s->budget--) { s->failed_pc=0x0c03e4e4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e4e6;
P_0c03e4e6: /* original 4f26, guest PC 0x0c03e4e6 */
if(!s->budget--) { s->failed_pc=0x0c03e4e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e4e8;
P_0c03e4e8: /* original 68f6, guest PC 0x0c03e4e8 */
if(!s->budget--) { s->failed_pc=0x0c03e4e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03e4ea;
P_0c03e4ea: /* original 69f6, guest PC 0x0c03e4ea */
if(!s->budget--) { s->failed_pc=0x0c03e4eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03e4ec;
P_0c03e4ec: /* original 6af6, guest PC 0x0c03e4ec */
if(!s->budget--) { s->failed_pc=0x0c03e4ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03e4ee;
P_0c03e4ee: /* original 6bf6, guest PC 0x0c03e4ee */
if(!s->budget--) { s->failed_pc=0x0c03e4eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03e4f0;
P_0c03e4f0: /* original 6cf6, guest PC 0x0c03e4f0 */
if(!s->budget--) { s->failed_pc=0x0c03e4f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e4f2;
P_0c03e4f2: /* original 6df6, guest PC 0x0c03e4f2 */
if(!s->budget--) { s->failed_pc=0x0c03e4f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e4f4;
P_0c03e4f4: /* original 000b, guest PC 0x0c03e4f4 */
if(!s->budget--) { s->failed_pc=0x0c03e4f4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03e4f6: /* original 6ef6, guest PC 0x0c03e4f6 */
if(!s->budget--) { s->failed_pc=0x0c03e4f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03e4f8u,s,ram);
P_0c03f040: /* original 2fe6, guest PC 0x0c03f040 */
if(!s->budget--) { s->failed_pc=0x0c03f040u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c03f042;
P_0c03f042: /* original 6e43, guest PC 0x0c03f042 */
if(!s->budget--) { s->failed_pc=0x0c03f042u; return 0; }
r[14]=r[4];
goto P_0c03f044;
P_0c03f044: /* original 4f22, guest PC 0x0c03f044 */
if(!s->budget--) { s->failed_pc=0x0c03f044u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f046;
P_0c03f046: /* original e40c, guest PC 0x0c03f046 */
if(!s->budget--) { s->failed_pc=0x0c03f046u; return 0; }
r[4]=0x0000000cu;
goto P_0c03f048;
P_0c03f048: /* original 7ffc, guest PC 0x0c03f048 */
if(!s->budget--) { s->failed_pc=0x0c03f048u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03f04a;
P_0c03f04a: /* original ff4a, guest PC 0x0c03f04a */
if(!s->budget--) { s->failed_pc=0x0c03f04au; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03f04c;
P_0c03f04c: /* original d31c, guest PC 0x0c03f04c */
if(!s->budget--) { s->failed_pc=0x0c03f04cu; return 0; }
r[3]=read(ram,0x0c03f0c0u,4);
goto P_0c03f04e;
P_0c03f04e: /* original 2342, guest PC 0x0c03f04e */
if(!s->budget--) { s->failed_pc=0x0c03f04eu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c03f050;
P_0c03f050: /* original d21c, guest PC 0x0c03f050 */
if(!s->budget--) { s->failed_pc=0x0c03f050u; return 0; }
r[2]=read(ram,0x0c03f0c4u,4);
goto P_0c03f052;
P_0c03f052: /* original 2242, guest PC 0x0c03f052 */
if(!s->budget--) { s->failed_pc=0x0c03f052u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c03f054;
P_0c03f054: /* original d111, guest PC 0x0c03f054 */
if(!s->budget--) { s->failed_pc=0x0c03f054u; return 0; }
r[1]=read(ram,0x0c03f09cu,4);
goto P_0c03f056;
P_0c03f056: /* original 410b, guest PC 0x0c03f056 */
if(!s->budget--) { s->failed_pc=0x0c03f056u; return 0; }
target=r[1];
r[16]=0x0c03f05au;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f05au) { target=s->pc; goto dispatch; }
goto P_0c03f05a;
P_0c03f058: /* original e400, guest PC 0x0c03f058 */
if(!s->budget--) { s->failed_pc=0x0c03f058u; return 0; }
r[4]=0x00000000u;
goto P_0c03f05a;
P_0c03f05a: /* original d312, guest PC 0x0c03f05a */
if(!s->budget--) { s->failed_pc=0x0c03f05au; return 0; }
r[3]=read(ram,0x0c03f0a4u,4);
goto P_0c03f05c;
P_0c03f05c: /* original d410, guest PC 0x0c03f05c */
if(!s->budget--) { s->failed_pc=0x0c03f05cu; return 0; }
r[4]=read(ram,0x0c03f0a0u,4);
goto P_0c03f05e;
P_0c03f05e: /* original 430b, guest PC 0x0c03f05e */
if(!s->budget--) { s->failed_pc=0x0c03f05eu; return 0; }
target=r[3];
r[16]=0x0c03f062u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f062u) { target=s->pc; goto dispatch; }
goto P_0c03f062;
P_0c03f060: /* original 0009, guest PC 0x0c03f060 */
if(!s->budget--) { s->failed_pc=0x0c03f060u; return 0; }
goto P_0c03f062;
P_0c03f062: /* original d212, guest PC 0x0c03f062 */
if(!s->budget--) { s->failed_pc=0x0c03f062u; return 0; }
r[2]=read(ram,0x0c03f0acu,4);
goto P_0c03f064;
P_0c03f064: /* original d410, guest PC 0x0c03f064 */
if(!s->budget--) { s->failed_pc=0x0c03f064u; return 0; }
r[4]=read(ram,0x0c03f0a8u,4);
goto P_0c03f066;
P_0c03f066: /* original 420b, guest PC 0x0c03f066 */
if(!s->budget--) { s->failed_pc=0x0c03f066u; return 0; }
target=r[2];
r[16]=0x0c03f06au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f06au) { target=s->pc; goto dispatch; }
goto P_0c03f06a;
P_0c03f068: /* original 0009, guest PC 0x0c03f068 */
if(!s->budget--) { s->failed_pc=0x0c03f068u; return 0; }
goto P_0c03f06a;
P_0c03f06a: /* original 64e2, guest PC 0x0c03f06a */
if(!s->budget--) { s->failed_pc=0x0c03f06au; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c03f06c;
P_0c03f06c: /* original 2448, guest PC 0x0c03f06c */
if(!s->budget--) { s->failed_pc=0x0c03f06cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f06e;
P_0c03f06e: /* original 8b07, guest PC 0x0c03f06e */
if(!s->budget--) { s->failed_pc=0x0c03f06eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f080; }
goto P_0c03f070;
P_0c03f070: /* original d315, guest PC 0x0c03f070 */
if(!s->budget--) { s->failed_pc=0x0c03f070u; return 0; }
r[3]=read(ram,0x0c03f0c8u,4);
goto P_0c03f072;
P_0c03f072: /* original d50f, guest PC 0x0c03f072 */
if(!s->budget--) { s->failed_pc=0x0c03f072u; return 0; }
r[5]=read(ram,0x0c03f0b0u,4);
goto P_0c03f074;
P_0c03f074: /* original f4f8, guest PC 0x0c03f074 */
if(!s->budget--) { s->failed_pc=0x0c03f074u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c03f076;
P_0c03f076: /* original 430b, guest PC 0x0c03f076 */
if(!s->budget--) { s->failed_pc=0x0c03f076u; return 0; }
target=r[3];
r[16]=0x0c03f07au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f07au) { target=s->pc; goto dispatch; }
goto P_0c03f07a;
P_0c03f078: /* original 64e3, guest PC 0x0c03f078 */
if(!s->budget--) { s->failed_pc=0x0c03f078u; return 0; }
r[4]=r[14];
goto P_0c03f07a;
P_0c03f07a: /* original a009, guest PC 0x0c03f07a */
if(!s->budget--) { s->failed_pc=0x0c03f07au; return 0; }
goto P_0c03f090;
P_0c03f07c: /* original 0009, guest PC 0x0c03f07c */
if(!s->budget--) { s->failed_pc=0x0c03f07cu; return 0; }
return vf3_matrix_family(0x0c03f07eu,s,ram);
P_0c03f080: /* original 6043, guest PC 0x0c03f080 */
if(!s->budget--) { s->failed_pc=0x0c03f080u; return 0; }
r[0]=r[4];
goto P_0c03f082;
P_0c03f082: /* original 8801, guest PC 0x0c03f082 */
if(!s->budget--) { s->failed_pc=0x0c03f082u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03f084;
P_0c03f084: /* original 8b04, guest PC 0x0c03f084 */
if(!s->budget--) { s->failed_pc=0x0c03f084u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f090; }
goto P_0c03f086;
P_0c03f086: /* original d311, guest PC 0x0c03f086 */
if(!s->budget--) { s->failed_pc=0x0c03f086u; return 0; }
r[3]=read(ram,0x0c03f0ccu,4);
goto P_0c03f088;
P_0c03f088: /* original d509, guest PC 0x0c03f088 */
if(!s->budget--) { s->failed_pc=0x0c03f088u; return 0; }
r[5]=read(ram,0x0c03f0b0u,4);
goto P_0c03f08a;
P_0c03f08a: /* original f4f8, guest PC 0x0c03f08a */
if(!s->budget--) { s->failed_pc=0x0c03f08au; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c03f08c;
P_0c03f08c: /* original 430b, guest PC 0x0c03f08c */
if(!s->budget--) { s->failed_pc=0x0c03f08cu; return 0; }
target=r[3];
r[16]=0x0c03f090u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f090u) { target=s->pc; goto dispatch; }
goto P_0c03f090;
P_0c03f08e: /* original 64e3, guest PC 0x0c03f08e */
if(!s->budget--) { s->failed_pc=0x0c03f08eu; return 0; }
r[4]=r[14];
goto P_0c03f090;
P_0c03f090: /* original 7f04, guest PC 0x0c03f090 */
if(!s->budget--) { s->failed_pc=0x0c03f090u; return 0; }
r[15]+=0x00000004u;
goto P_0c03f092;
P_0c03f092: /* original d20a, guest PC 0x0c03f092 */
if(!s->budget--) { s->failed_pc=0x0c03f092u; return 0; }
r[2]=read(ram,0x0c03f0bcu,4);
goto P_0c03f094;
P_0c03f094: /* original 4f26, guest PC 0x0c03f094 */
if(!s->budget--) { s->failed_pc=0x0c03f094u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f096;
P_0c03f096: /* original e401, guest PC 0x0c03f096 */
if(!s->budget--) { s->failed_pc=0x0c03f096u; return 0; }
r[4]=0x00000001u;
goto P_0c03f098;
P_0c03f098: /* original 422b, guest PC 0x0c03f098 */
if(!s->budget--) { s->failed_pc=0x0c03f098u; return 0; }
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
P_0c03f09a: /* original 6ef6, guest PC 0x0c03f09a */
if(!s->budget--) { s->failed_pc=0x0c03f09au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f09cu,s,ram);
P_0c03f2e0: /* original 4f22, guest PC 0x0c03f2e0 */
if(!s->budget--) { s->failed_pc=0x0c03f2e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f2e2;
P_0c03f2e2: /* original 4311, guest PC 0x0c03f2e2 */
if(!s->budget--) { s->failed_pc=0x0c03f2e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c03f2e4;
P_0c03f2e4: /* original 8f03, guest PC 0x0c03f2e4 */
if(!s->budget--) { s->failed_pc=0x0c03f2e4u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c03f2ee; }
goto P_0c03f2e8;
P_0c03f2e6: /* original ec00, guest PC 0x0c03f2e6 */
if(!s->budget--) { s->failed_pc=0x0c03f2e6u; return 0; }
r[12]=0x00000000u;
goto P_0c03f2e8;
P_0c03f2e8: /* original 5146, guest PC 0x0c03f2e8 */
if(!s->budget--) { s->failed_pc=0x0c03f2e8u; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f2ea;
P_0c03f2ea: /* original 2118, guest PC 0x0c03f2ea */
if(!s->budget--) { s->failed_pc=0x0c03f2eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f2ec;
P_0c03f2ec: /* original 8b30, guest PC 0x0c03f2ec */
if(!s->budget--) { s->failed_pc=0x0c03f2ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f350; }
goto P_0c03f2ee;
P_0c03f2ee: /* original a06c, guest PC 0x0c03f2ee */
if(!s->budget--) { s->failed_pc=0x0c03f2eeu; return 0; }
r[0]=0x00000000u;
goto P_0c03f3ca;
P_0c03f2f0: /* original e000, guest PC 0x0c03f2f0 */
if(!s->budget--) { s->failed_pc=0x0c03f2f0u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c03f2f2u,s,ram);
P_0c03f350: /* original da65, guest PC 0x0c03f350 */
if(!s->budget--) { s->failed_pc=0x0c03f350u; return 0; }
r[10]=read(ram,0x0c03f4e8u,4);
goto P_0c03f352;
P_0c03f352: /* original 6d43, guest PC 0x0c03f352 */
if(!s->budget--) { s->failed_pc=0x0c03f352u; return 0; }
r[13]=r[4];
goto P_0c03f354;
P_0c03f354: /* original e901, guest PC 0x0c03f354 */
if(!s->budget--) { s->failed_pc=0x0c03f354u; return 0; }
r[9]=0x00000001u;
goto P_0c03f356;
P_0c03f356: /* original 7d18, guest PC 0x0c03f356 */
if(!s->budget--) { s->failed_pc=0x0c03f356u; return 0; }
r[13]+=0x00000018u;
goto P_0c03f358;
P_0c03f358: /* original e8ff, guest PC 0x0c03f358 */
if(!s->budget--) { s->failed_pc=0x0c03f358u; return 0; }
r[8]=0xffffffffu;
goto P_0c03f35a;
P_0c03f35a: /* original 6ed3, guest PC 0x0c03f35a */
if(!s->budget--) { s->failed_pc=0x0c03f35au; return 0; }
r[14]=r[13];
goto P_0c03f35c;
P_0c03f35c: /* original 55e8, guest PC 0x0c03f35c */
if(!s->budget--) { s->failed_pc=0x0c03f35cu; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c03f35e;
P_0c03f35e: /* original 4511, guest PC 0x0c03f35e */
if(!s->budget--) { s->failed_pc=0x0c03f35eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f360;
P_0c03f360: /* original 8f17, guest PC 0x0c03f360 */
if(!s->budget--) { s->failed_pc=0x0c03f360u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000050u;
if(!cond) { goto P_0c03f392; }
goto P_0c03f364;
P_0c03f362: /* original 7d50, guest PC 0x0c03f362 */
if(!s->budget--) { s->failed_pc=0x0c03f362u; return 0; }
r[13]+=0x00000050u;
goto P_0c03f364;
P_0c03f364: /* original d261, guest PC 0x0c03f364 */
if(!s->budget--) { s->failed_pc=0x0c03f364u; return 0; }
r[2]=read(ram,0x0c03f4ecu,4);
goto P_0c03f366;
P_0c03f366: /* original d062, guest PC 0x0c03f366 */
if(!s->budget--) { s->failed_pc=0x0c03f366u; return 0; }
r[0]=read(ram,0x0c03f4f0u,4);
goto P_0c03f368;
P_0c03f368: /* original 6322, guest PC 0x0c03f368 */
if(!s->budget--) { s->failed_pc=0x0c03f368u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f36a;
P_0c03f36a: /* original 6102, guest PC 0x0c03f36a */
if(!s->budget--) { s->failed_pc=0x0c03f36au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c03f36c;
P_0c03f36c: /* original 353c, guest PC 0x0c03f36c */
if(!s->budget--) { s->failed_pc=0x0c03f36cu; return 0; }
r[5]+=r[3];
goto P_0c03f36e;
P_0c03f36e: /* original 6453, guest PC 0x0c03f36e */
if(!s->budget--) { s->failed_pc=0x0c03f36eu; return 0; }
r[4]=r[5];
goto P_0c03f370;
P_0c03f370: /* original 4408, guest PC 0x0c03f370 */
if(!s->budget--) { s->failed_pc=0x0c03f370u; return 0; }
r[4]<<=2;
goto P_0c03f372;
P_0c03f372: /* original 4400, guest PC 0x0c03f372 */
if(!s->budget--) { s->failed_pc=0x0c03f372u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f374;
P_0c03f374: /* original 341c, guest PC 0x0c03f374 */
if(!s->budget--) { s->failed_pc=0x0c03f374u; return 0; }
r[4]+=r[1];
goto P_0c03f376;
P_0c03f376: /* original 6342, guest PC 0x0c03f376 */
if(!s->budget--) { s->failed_pc=0x0c03f376u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03f378;
P_0c03f378: /* original 2338, guest PC 0x0c03f378 */
if(!s->budget--) { s->failed_pc=0x0c03f378u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f37a;
P_0c03f37a: /* original 8b09, guest PC 0x0c03f37a */
if(!s->budget--) { s->failed_pc=0x0c03f37au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f390; }
goto P_0c03f37c;
P_0c03f37c: /* original 6c93, guest PC 0x0c03f37c */
if(!s->budget--) { s->failed_pc=0x0c03f37cu; return 0; }
r[12]=r[9];
goto P_0c03f37e;
P_0c03f37e: /* original a008, guest PC 0x0c03f37e */
if(!s->budget--) { s->failed_pc=0x0c03f37eu; return 0; }
r[5]=r[8];
goto P_0c03f392;
P_0c03f380: /* original 6583, guest PC 0x0c03f380 */
if(!s->budget--) { s->failed_pc=0x0c03f380u; return 0; }
r[5]=r[8];
return vf3_matrix_family(0x0c03f382u,s,ram);
P_0c03f390: /* original 5541, guest PC 0x0c03f390 */
if(!s->budget--) { s->failed_pc=0x0c03f390u; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c03f392;
P_0c03f392: /* original 5be3, guest PC 0x0c03f392 */
if(!s->budget--) { s->failed_pc=0x0c03f392u; return 0; }
r[11]=read(ram,r[14]+12,4);
goto P_0c03f394;
P_0c03f394: /* original 4511, guest PC 0x0c03f394 */
if(!s->budget--) { s->failed_pc=0x0c03f394u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f396;
P_0c03f396: /* original 8f0b, guest PC 0x0c03f396 */
if(!s->budget--) { s->failed_pc=0x0c03f396u; return 0; }
cond=r[17]&1u;
r[11]&=r[10];
if(!cond) { goto P_0c03f3b0; }
goto P_0c03f39a;
P_0c03f398: /* original 2ba9, guest PC 0x0c03f398 */
if(!s->budget--) { s->failed_pc=0x0c03f398u; return 0; }
r[11]&=r[10];
goto P_0c03f39a;
P_0c03f39a: /* original d356, guest PC 0x0c03f39a */
if(!s->budget--) { s->failed_pc=0x0c03f39au; return 0; }
r[3]=read(ram,0x0c03f4f4u,4);
goto P_0c03f39c;
P_0c03f39c: /* original 430b, guest PC 0x0c03f39c */
if(!s->budget--) { s->failed_pc=0x0c03f39cu; return 0; }
target=r[3];
r[16]=0x0c03f3a0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f3a0u) { target=s->pc; goto dispatch; }
goto P_0c03f3a0;
P_0c03f39e: /* original 64e3, guest PC 0x0c03f39e */
if(!s->budget--) { s->failed_pc=0x0c03f39eu; return 0; }
r[4]=r[14];
goto P_0c03f3a0;
P_0c03f3a0: /* original a009, guest PC 0x0c03f3a0 */
if(!s->budget--) { s->failed_pc=0x0c03f3a0u; return 0; }
goto P_0c03f3b6;
P_0c03f3a2: /* original 0009, guest PC 0x0c03f3a2 */
if(!s->budget--) { s->failed_pc=0x0c03f3a2u; return 0; }
return vf3_matrix_family(0x0c03f3a4u,s,ram);
P_0c03f3b0: /* original d351, guest PC 0x0c03f3b0 */
if(!s->budget--) { s->failed_pc=0x0c03f3b0u; return 0; }
r[3]=read(ram,0x0c03f4f8u,4);
goto P_0c03f3b2;
P_0c03f3b2: /* original 430b, guest PC 0x0c03f3b2 */
if(!s->budget--) { s->failed_pc=0x0c03f3b2u; return 0; }
target=r[3];
r[16]=0x0c03f3b6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f3b6u) { target=s->pc; goto dispatch; }
goto P_0c03f3b6;
P_0c03f3b4: /* original 64e3, guest PC 0x0c03f3b4 */
if(!s->budget--) { s->failed_pc=0x0c03f3b4u; return 0; }
r[4]=r[14];
goto P_0c03f3b6;
P_0c03f3b6: /* original e04c, guest PC 0x0c03f3b6 */
if(!s->budget--) { s->failed_pc=0x0c03f3b6u; return 0; }
r[0]=0x0000004cu;
goto P_0c03f3b8;
P_0c03f3b8: /* original 52e3, guest PC 0x0c03f3b8 */
if(!s->budget--) { s->failed_pc=0x0c03f3b8u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c03f3ba;
P_0c03f3ba: /* original 22bb, guest PC 0x0c03f3ba */
if(!s->budget--) { s->failed_pc=0x0c03f3bau; return 0; }
r[2]|=r[11];
goto P_0c03f3bc;
P_0c03f3bc: /* original 1e23, guest PC 0x0c03f3bc */
if(!s->budget--) { s->failed_pc=0x0c03f3bcu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03f3be;
P_0c03f3be: /* original 03ee, guest PC 0x0c03f3be */
if(!s->budget--) { s->failed_pc=0x0c03f3beu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c03f3c0;
P_0c03f3c0: /* original 3d3c, guest PC 0x0c03f3c0 */
if(!s->budget--) { s->failed_pc=0x0c03f3c0u; return 0; }
r[13]+=r[3];
goto P_0c03f3c2;
P_0c03f3c2: /* original 64d2, guest PC 0x0c03f3c2 */
if(!s->budget--) { s->failed_pc=0x0c03f3c2u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c03f3c4;
P_0c03f3c4: /* original 2448, guest PC 0x0c03f3c4 */
if(!s->budget--) { s->failed_pc=0x0c03f3c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f3c6;
P_0c03f3c6: /* original 8bc8, guest PC 0x0c03f3c6 */
if(!s->budget--) { s->failed_pc=0x0c03f3c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f35a; }
goto P_0c03f3c8;
P_0c03f3c8: /* original 60c3, guest PC 0x0c03f3c8 */
if(!s->budget--) { s->failed_pc=0x0c03f3c8u; return 0; }
r[0]=r[12];
goto P_0c03f3ca;
P_0c03f3ca: /* original 4f26, guest PC 0x0c03f3ca */
if(!s->budget--) { s->failed_pc=0x0c03f3cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f3cc;
P_0c03f3cc: /* original 68f6, guest PC 0x0c03f3cc */
if(!s->budget--) { s->failed_pc=0x0c03f3ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f3ce;
P_0c03f3ce: /* original 69f6, guest PC 0x0c03f3ce */
if(!s->budget--) { s->failed_pc=0x0c03f3ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f3d0;
P_0c03f3d0: /* original 6af6, guest PC 0x0c03f3d0 */
if(!s->budget--) { s->failed_pc=0x0c03f3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f3d2;
P_0c03f3d2: /* original 6bf6, guest PC 0x0c03f3d2 */
if(!s->budget--) { s->failed_pc=0x0c03f3d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f3d4;
P_0c03f3d4: /* original 6cf6, guest PC 0x0c03f3d4 */
if(!s->budget--) { s->failed_pc=0x0c03f3d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f3d6;
P_0c03f3d6: /* original 6df6, guest PC 0x0c03f3d6 */
if(!s->budget--) { s->failed_pc=0x0c03f3d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f3d8;
P_0c03f3d8: /* original 000b, guest PC 0x0c03f3d8 */
if(!s->budget--) { s->failed_pc=0x0c03f3d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f3da: /* original 6ef6, guest PC 0x0c03f3da */
if(!s->budget--) { s->failed_pc=0x0c03f3dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f3dcu,s,ram);
P_0c03f3f0: /* original 4f22, guest PC 0x0c03f3f0 */
if(!s->budget--) { s->failed_pc=0x0c03f3f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f3f2;
P_0c03f3f2: /* original 4f12, guest PC 0x0c03f3f2 */
if(!s->budget--) { s->failed_pc=0x0c03f3f2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f3f4;
P_0c03f3f4: /* original 7ff8, guest PC 0x0c03f3f4 */
if(!s->budget--) { s->failed_pc=0x0c03f3f4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03f3f6;
P_0c03f3f6: /* original 1f31, guest PC 0x0c03f3f6 */
if(!s->budget--) { s->failed_pc=0x0c03f3f6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03f3f8;
P_0c03f3f8: /* original 6242, guest PC 0x0c03f3f8 */
if(!s->budget--) { s->failed_pc=0x0c03f3f8u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c03f3fa;
P_0c03f3fa: /* original 4211, guest PC 0x0c03f3fa */
if(!s->budget--) { s->failed_pc=0x0c03f3fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c03f3fc;
P_0c03f3fc: /* original 8b02, guest PC 0x0c03f3fc */
if(!s->budget--) { s->failed_pc=0x0c03f3fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f404; }
goto P_0c03f3fe;
P_0c03f3fe: /* original 5146, guest PC 0x0c03f3fe */
if(!s->budget--) { s->failed_pc=0x0c03f3feu; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f400;
P_0c03f400: /* original 2118, guest PC 0x0c03f400 */
if(!s->budget--) { s->failed_pc=0x0c03f400u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f402;
P_0c03f402: /* original 8b05, guest PC 0x0c03f402 */
if(!s->budget--) { s->failed_pc=0x0c03f402u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f410; }
goto P_0c03f404;
P_0c03f404: /* original a060, guest PC 0x0c03f404 */
if(!s->budget--) { s->failed_pc=0x0c03f404u; return 0; }
r[0]=0x00000000u;
goto P_0c03f4c8;
P_0c03f406: /* original e000, guest PC 0x0c03f406 */
if(!s->budget--) { s->failed_pc=0x0c03f406u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c03f408u,s,ram);
P_0c03f410: /* original db3a, guest PC 0x0c03f410 */
if(!s->budget--) { s->failed_pc=0x0c03f410u; return 0; }
r[11]=read(ram,0x0c03f4fcu,4);
goto P_0c03f412;
P_0c03f412: /* original 6a43, guest PC 0x0c03f412 */
if(!s->budget--) { s->failed_pc=0x0c03f412u; return 0; }
r[10]=r[4];
goto P_0c03f414;
P_0c03f414: /* original de36, guest PC 0x0c03f414 */
if(!s->budget--) { s->failed_pc=0x0c03f414u; return 0; }
r[14]=read(ram,0x0c03f4f0u,4);
goto P_0c03f416;
P_0c03f416: /* original 7a18, guest PC 0x0c03f416 */
if(!s->budget--) { s->failed_pc=0x0c03f416u; return 0; }
r[10]+=0x00000018u;
goto P_0c03f418;
P_0c03f418: /* original e8ff, guest PC 0x0c03f418 */
if(!s->budget--) { s->failed_pc=0x0c03f418u; return 0; }
r[8]=0xffffffffu;
goto P_0c03f41a;
P_0c03f41a: /* original 6ca3, guest PC 0x0c03f41a */
if(!s->budget--) { s->failed_pc=0x0c03f41au; return 0; }
r[12]=r[10];
goto P_0c03f41c;
P_0c03f41c: /* original 54c8, guest PC 0x0c03f41c */
if(!s->budget--) { s->failed_pc=0x0c03f41cu; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c03f41e;
P_0c03f41e: /* original 4411, guest PC 0x0c03f41e */
if(!s->budget--) { s->failed_pc=0x0c03f41eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c03f420;
P_0c03f420: /* original 8f39, guest PC 0x0c03f420 */
if(!s->budget--) { s->failed_pc=0x0c03f420u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000050u;
if(!cond) { goto P_0c03f496; }
goto P_0c03f424;
P_0c03f422: /* original 7a50, guest PC 0x0c03f422 */
if(!s->budget--) { s->failed_pc=0x0c03f422u; return 0; }
r[10]+=0x00000050u;
goto P_0c03f424;
P_0c03f424: /* original d231, guest PC 0x0c03f424 */
if(!s->budget--) { s->failed_pc=0x0c03f424u; return 0; }
r[2]=read(ram,0x0c03f4ecu,4);
goto P_0c03f426;
P_0c03f426: /* original 61e2, guest PC 0x0c03f426 */
if(!s->budget--) { s->failed_pc=0x0c03f426u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f428;
P_0c03f428: /* original 6322, guest PC 0x0c03f428 */
if(!s->budget--) { s->failed_pc=0x0c03f428u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f42a;
P_0c03f42a: /* original 343c, guest PC 0x0c03f42a */
if(!s->budget--) { s->failed_pc=0x0c03f42au; return 0; }
r[4]+=r[3];
goto P_0c03f42c;
P_0c03f42c: /* original 6d43, guest PC 0x0c03f42c */
if(!s->budget--) { s->failed_pc=0x0c03f42cu; return 0; }
r[13]=r[4];
goto P_0c03f42e;
P_0c03f42e: /* original 4d08, guest PC 0x0c03f42e */
if(!s->budget--) { s->failed_pc=0x0c03f42eu; return 0; }
r[13]<<=2;
goto P_0c03f430;
P_0c03f430: /* original 4d00, guest PC 0x0c03f430 */
if(!s->budget--) { s->failed_pc=0x0c03f430u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c03f432;
P_0c03f432: /* original 31dc, guest PC 0x0c03f432 */
if(!s->budget--) { s->failed_pc=0x0c03f432u; return 0; }
r[1]+=r[13];
goto P_0c03f434;
P_0c03f434: /* original 6012, guest PC 0x0c03f434 */
if(!s->budget--) { s->failed_pc=0x0c03f434u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03f436;
P_0c03f436: /* original e300, guest PC 0x0c03f436 */
if(!s->budget--) { s->failed_pc=0x0c03f436u; return 0; }
r[3]=0x00000000u;
goto P_0c03f438;
P_0c03f438: /* original 3036, guest PC 0x0c03f438 */
if(!s->budget--) { s->failed_pc=0x0c03f438u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[3])!=0);
goto P_0c03f43a;
P_0c03f43a: /* original 8b2c, guest PC 0x0c03f43a */
if(!s->budget--) { s->failed_pc=0x0c03f43au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f496; }
goto P_0c03f43c;
P_0c03f43c: /* original 61e2, guest PC 0x0c03f43c */
if(!s->budget--) { s->failed_pc=0x0c03f43cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f43e;
P_0c03f43e: /* original 31dc, guest PC 0x0c03f43e */
if(!s->budget--) { s->failed_pc=0x0c03f43eu; return 0; }
r[1]+=r[13];
goto P_0c03f440;
P_0c03f440: /* original 6012, guest PC 0x0c03f440 */
if(!s->budget--) { s->failed_pc=0x0c03f440u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03f442;
P_0c03f442: /* original 70ff, guest PC 0x0c03f442 */
if(!s->budget--) { s->failed_pc=0x0c03f442u; return 0; }
r[0]+=0xffffffffu;
goto P_0c03f444;
P_0c03f444: /* original 2102, guest PC 0x0c03f444 */
if(!s->budget--) { s->failed_pc=0x0c03f444u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c03f446;
P_0c03f446: /* original 61e2, guest PC 0x0c03f446 */
if(!s->budget--) { s->failed_pc=0x0c03f446u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f448;
P_0c03f448: /* original 31dc, guest PC 0x0c03f448 */
if(!s->budget--) { s->failed_pc=0x0c03f448u; return 0; }
r[1]+=r[13];
goto P_0c03f44a;
P_0c03f44a: /* original 6012, guest PC 0x0c03f44a */
if(!s->budget--) { s->failed_pc=0x0c03f44au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03f44c;
P_0c03f44c: /* original 2008, guest PC 0x0c03f44c */
if(!s->budget--) { s->failed_pc=0x0c03f44cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f44e;
P_0c03f44e: /* original 8b22, guest PC 0x0c03f44e */
if(!s->budget--) { s->failed_pc=0x0c03f44eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f496; }
goto P_0c03f450;
P_0c03f450: /* original 60e2, guest PC 0x0c03f450 */
if(!s->budget--) { s->failed_pc=0x0c03f450u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03f452;
P_0c03f452: /* original 30dc, guest PC 0x0c03f452 */
if(!s->budget--) { s->failed_pc=0x0c03f452u; return 0; }
r[0]+=r[13];
goto P_0c03f454;
P_0c03f454: /* original 5101, guest PC 0x0c03f454 */
if(!s->budget--) { s->failed_pc=0x0c03f454u; return 0; }
r[1]=read(ram,r[0]+4,4);
goto P_0c03f456;
P_0c03f456: /* original 2f12, guest PC 0x0c03f456 */
if(!s->budget--) { s->failed_pc=0x0c03f456u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c03f458;
P_0c03f458: /* original e13c, guest PC 0x0c03f458 */
if(!s->budget--) { s->failed_pc=0x0c03f458u; return 0; }
r[1]=0x0000003cu;
goto P_0c03f45a;
P_0c03f45a: /* original 60f2, guest PC 0x0c03f45a */
if(!s->budget--) { s->failed_pc=0x0c03f45au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f45c;
P_0c03f45c: /* original 62b2, guest PC 0x0c03f45c */
if(!s->budget--) { s->failed_pc=0x0c03f45cu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c03f45e;
P_0c03f45e: /* original 0017, guest PC 0x0c03f45e */
if(!s->budget--) { s->failed_pc=0x0c03f45eu; return 0; }
r[19]=r[0]*r[1];
goto P_0c03f460;
P_0c03f460: /* original 091a, guest PC 0x0c03f460 */
if(!s->budget--) { s->failed_pc=0x0c03f460u; return 0; }
r[9]=r[19];
goto P_0c03f462;
P_0c03f462: /* original 329c, guest PC 0x0c03f462 */
if(!s->budget--) { s->failed_pc=0x0c03f462u; return 0; }
r[2]+=r[9];
goto P_0c03f464;
P_0c03f464: /* original 502a, guest PC 0x0c03f464 */
if(!s->budget--) { s->failed_pc=0x0c03f464u; return 0; }
r[0]=read(ram,r[2]+40,4);
goto P_0c03f466;
P_0c03f466: /* original 2008, guest PC 0x0c03f466 */
if(!s->budget--) { s->failed_pc=0x0c03f466u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f468;
P_0c03f468: /* original 8b08, guest PC 0x0c03f468 */
if(!s->budget--) { s->failed_pc=0x0c03f468u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f47c; }
goto P_0c03f46a;
P_0c03f46a: /* original d225, guest PC 0x0c03f46a */
if(!s->budget--) { s->failed_pc=0x0c03f46au; return 0; }
r[2]=read(ram,0x0c03f500u,4);
goto P_0c03f46c;
P_0c03f46c: /* original 64b2, guest PC 0x0c03f46c */
if(!s->budget--) { s->failed_pc=0x0c03f46cu; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c03f46e;
P_0c03f46e: /* original 420b, guest PC 0x0c03f46e */
if(!s->budget--) { s->failed_pc=0x0c03f46eu; return 0; }
target=r[2];
r[16]=0x0c03f472u;
r[4]+=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f472u) { target=s->pc; goto dispatch; }
goto P_0c03f472;
P_0c03f470: /* original 349c, guest PC 0x0c03f470 */
if(!s->budget--) { s->failed_pc=0x0c03f470u; return 0; }
r[4]+=r[9];
goto P_0c03f472;
P_0c03f472: /* original 6403, guest PC 0x0c03f472 */
if(!s->budget--) { s->failed_pc=0x0c03f472u; return 0; }
r[4]=r[0];
goto P_0c03f474;
P_0c03f474: /* original 2448, guest PC 0x0c03f474 */
if(!s->budget--) { s->failed_pc=0x0c03f474u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f476;
P_0c03f476: /* original 8901, guest PC 0x0c03f476 */
if(!s->budget--) { s->failed_pc=0x0c03f476u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f47c; }
goto P_0c03f478;
P_0c03f478: /* original e201, guest PC 0x0c03f478 */
if(!s->budget--) { s->failed_pc=0x0c03f478u; return 0; }
r[2]=0x00000001u;
goto P_0c03f47a;
P_0c03f47a: /* original 1f21, guest PC 0x0c03f47a */
if(!s->budget--) { s->failed_pc=0x0c03f47au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03f47c;
P_0c03f47c: /* original 63b2, guest PC 0x0c03f47c */
if(!s->budget--) { s->failed_pc=0x0c03f47cu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c03f47e;
P_0c03f47e: /* original e200, guest PC 0x0c03f47e */
if(!s->budget--) { s->failed_pc=0x0c03f47eu; return 0; }
r[2]=0x00000000u;
goto P_0c03f480;
P_0c03f480: /* original 339c, guest PC 0x0c03f480 */
if(!s->budget--) { s->failed_pc=0x0c03f480u; return 0; }
r[3]+=r[9];
goto P_0c03f482;
P_0c03f482: /* original 132b, guest PC 0x0c03f482 */
if(!s->budget--) { s->failed_pc=0x0c03f482u; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c03f484;
P_0c03f484: /* original 63b2, guest PC 0x0c03f484 */
if(!s->budget--) { s->failed_pc=0x0c03f484u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c03f486;
P_0c03f486: /* original 339c, guest PC 0x0c03f486 */
if(!s->budget--) { s->failed_pc=0x0c03f486u; return 0; }
r[3]+=r[9];
goto P_0c03f488;
P_0c03f488: /* original 138e, guest PC 0x0c03f488 */
if(!s->budget--) { s->failed_pc=0x0c03f488u; return 0; }
write(ram,r[3]+56,r[8],4);
goto P_0c03f48a;
P_0c03f48a: /* original d31e, guest PC 0x0c03f48a */
if(!s->budget--) { s->failed_pc=0x0c03f48au; return 0; }
r[3]=read(ram,0x0c03f504u,4);
goto P_0c03f48c;
P_0c03f48c: /* original 430b, guest PC 0x0c03f48c */
if(!s->budget--) { s->failed_pc=0x0c03f48cu; return 0; }
target=r[3];
r[16]=0x0c03f490u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f490u) { target=s->pc; goto dispatch; }
goto P_0c03f490;
P_0c03f48e: /* original 64f2, guest PC 0x0c03f48e */
if(!s->budget--) { s->failed_pc=0x0c03f48eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03f490;
P_0c03f490: /* original 62e2, guest PC 0x0c03f490 */
if(!s->budget--) { s->failed_pc=0x0c03f490u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f492;
P_0c03f492: /* original 32dc, guest PC 0x0c03f492 */
if(!s->budget--) { s->failed_pc=0x0c03f492u; return 0; }
r[2]+=r[13];
goto P_0c03f494;
P_0c03f494: /* original 1281, guest PC 0x0c03f494 */
if(!s->budget--) { s->failed_pc=0x0c03f494u; return 0; }
write(ram,r[2]+4,r[8],4);
goto P_0c03f496;
P_0c03f496: /* original 50c3, guest PC 0x0c03f496 */
if(!s->budget--) { s->failed_pc=0x0c03f496u; return 0; }
r[0]=read(ram,r[12]+12,4);
goto P_0c03f498;
P_0c03f498: /* original e3e5, guest PC 0x0c03f498 */
if(!s->budget--) { s->failed_pc=0x0c03f498u; return 0; }
r[3]=0xffffffe5u;
goto P_0c03f49a;
P_0c03f49a: /* original e407, guest PC 0x0c03f49a */
if(!s->budget--) { s->failed_pc=0x0c03f49au; return 0; }
r[4]=0x00000007u;
goto P_0c03f49c;
P_0c03f49c: /* original 403d, guest PC 0x0c03f49c */
if(!s->budget--) { s->failed_pc=0x0c03f49cu; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c03f49e;
P_0c03f49e: /* original d31a, guest PC 0x0c03f49e */
if(!s->budget--) { s->failed_pc=0x0c03f49eu; return 0; }
r[3]=read(ram,0x0c03f508u,4);
goto P_0c03f4a0;
P_0c03f4a0: /* original 6232, guest PC 0x0c03f4a0 */
if(!s->budget--) { s->failed_pc=0x0c03f4a0u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f4a2;
P_0c03f4a2: /* original 2228, guest PC 0x0c03f4a2 */
if(!s->budget--) { s->failed_pc=0x0c03f4a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f4a4;
P_0c03f4a4: /* original 8d09, guest PC 0x0c03f4a4 */
if(!s->budget--) { s->failed_pc=0x0c03f4a4u; return 0; }
cond=r[17]&1u;
r[4]&=r[0];
if(cond) { goto P_0c03f4ba; }
goto P_0c03f4a8;
P_0c03f4a6: /* original 2409, guest PC 0x0c03f4a6 */
if(!s->budget--) { s->failed_pc=0x0c03f4a6u; return 0; }
r[4]&=r[0];
goto P_0c03f4a8;
P_0c03f4a8: /* original 6043, guest PC 0x0c03f4a8 */
if(!s->budget--) { s->failed_pc=0x0c03f4a8u; return 0; }
r[0]=r[4];
goto P_0c03f4aa;
P_0c03f4aa: /* original 8805, guest PC 0x0c03f4aa */
if(!s->budget--) { s->failed_pc=0x0c03f4aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03f4ac;
P_0c03f4ac: /* original 8902, guest PC 0x0c03f4ac */
if(!s->budget--) { s->failed_pc=0x0c03f4acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f4b4; }
goto P_0c03f4ae;
P_0c03f4ae: /* original 6043, guest PC 0x0c03f4ae */
if(!s->budget--) { s->failed_pc=0x0c03f4aeu; return 0; }
r[0]=r[4];
goto P_0c03f4b0;
P_0c03f4b0: /* original 8806, guest PC 0x0c03f4b0 */
if(!s->budget--) { s->failed_pc=0x0c03f4b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c03f4b2;
P_0c03f4b2: /* original 8b02, guest PC 0x0c03f4b2 */
if(!s->budget--) { s->failed_pc=0x0c03f4b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f4ba; }
goto P_0c03f4b4;
P_0c03f4b4: /* original d315, guest PC 0x0c03f4b4 */
if(!s->budget--) { s->failed_pc=0x0c03f4b4u; return 0; }
r[3]=read(ram,0x0c03f50cu,4);
goto P_0c03f4b6;
P_0c03f4b6: /* original 430b, guest PC 0x0c03f4b6 */
if(!s->budget--) { s->failed_pc=0x0c03f4b6u; return 0; }
target=r[3];
r[16]=0x0c03f4bau;
r[4]=read(ram,r[12]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f4bau) { target=s->pc; goto dispatch; }
goto P_0c03f4ba;
P_0c03f4b8: /* original 54cf, guest PC 0x0c03f4b8 */
if(!s->budget--) { s->failed_pc=0x0c03f4b8u; return 0; }
r[4]=read(ram,r[12]+60,4);
goto P_0c03f4ba;
P_0c03f4ba: /* original e04c, guest PC 0x0c03f4ba */
if(!s->budget--) { s->failed_pc=0x0c03f4bau; return 0; }
r[0]=0x0000004cu;
goto P_0c03f4bc;
P_0c03f4bc: /* original 02ce, guest PC 0x0c03f4bc */
if(!s->budget--) { s->failed_pc=0x0c03f4bcu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c03f4be;
P_0c03f4be: /* original 3a2c, guest PC 0x0c03f4be */
if(!s->budget--) { s->failed_pc=0x0c03f4beu; return 0; }
r[10]+=r[2];
goto P_0c03f4c0;
P_0c03f4c0: /* original 64a2, guest PC 0x0c03f4c0 */
if(!s->budget--) { s->failed_pc=0x0c03f4c0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c03f4c2;
P_0c03f4c2: /* original 2448, guest PC 0x0c03f4c2 */
if(!s->budget--) { s->failed_pc=0x0c03f4c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f4c4;
P_0c03f4c4: /* original 8ba9, guest PC 0x0c03f4c4 */
if(!s->budget--) { s->failed_pc=0x0c03f4c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f41a; }
goto P_0c03f4c6;
P_0c03f4c6: /* original 50f1, guest PC 0x0c03f4c6 */
if(!s->budget--) { s->failed_pc=0x0c03f4c6u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c03f4c8;
P_0c03f4c8: /* original 7f08, guest PC 0x0c03f4c8 */
if(!s->budget--) { s->failed_pc=0x0c03f4c8u; return 0; }
r[15]+=0x00000008u;
goto P_0c03f4ca;
P_0c03f4ca: /* original 4f16, guest PC 0x0c03f4ca */
if(!s->budget--) { s->failed_pc=0x0c03f4cau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f4cc;
P_0c03f4cc: /* original 4f26, guest PC 0x0c03f4cc */
if(!s->budget--) { s->failed_pc=0x0c03f4ccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f4ce;
P_0c03f4ce: /* original 68f6, guest PC 0x0c03f4ce */
if(!s->budget--) { s->failed_pc=0x0c03f4ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f4d0;
P_0c03f4d0: /* original 69f6, guest PC 0x0c03f4d0 */
if(!s->budget--) { s->failed_pc=0x0c03f4d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f4d2;
P_0c03f4d2: /* original 6af6, guest PC 0x0c03f4d2 */
if(!s->budget--) { s->failed_pc=0x0c03f4d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f4d4;
P_0c03f4d4: /* original 6bf6, guest PC 0x0c03f4d4 */
if(!s->budget--) { s->failed_pc=0x0c03f4d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f4d6;
P_0c03f4d6: /* original 6cf6, guest PC 0x0c03f4d6 */
if(!s->budget--) { s->failed_pc=0x0c03f4d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f4d8;
P_0c03f4d8: /* original 6df6, guest PC 0x0c03f4d8 */
if(!s->budget--) { s->failed_pc=0x0c03f4d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f4da;
P_0c03f4da: /* original 000b, guest PC 0x0c03f4da */
if(!s->budget--) { s->failed_pc=0x0c03f4dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f4dc: /* original 6ef6, guest PC 0x0c03f4dc */
if(!s->budget--) { s->failed_pc=0x0c03f4dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f4deu,s,ram);
P_0c03fd02: /* original 4f22, guest PC 0x0c03fd02 */
if(!s->budget--) { s->failed_pc=0x0c03fd02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fd04;
P_0c03fd04: /* original d716, guest PC 0x0c03fd04 */
if(!s->budget--) { s->failed_pc=0x0c03fd04u; return 0; }
r[7]=read(ram,0x0c03fd60u,4);
goto P_0c03fd06;
P_0c03fd06: /* original d815, guest PC 0x0c03fd06 */
if(!s->budget--) { s->failed_pc=0x0c03fd06u; return 0; }
r[8]=read(ram,0x0c03fd5cu,4);
goto P_0c03fd08;
P_0c03fd08: /* original a033, guest PC 0x0c03fd08 */
if(!s->budget--) { s->failed_pc=0x0c03fd08u; return 0; }
r[5]=r[11];
goto P_0c03fd72;
P_0c03fd0a: /* original 65b3, guest PC 0x0c03fd0a */
if(!s->budget--) { s->failed_pc=0x0c03fd0au; return 0; }
r[5]=r[11];
return vf3_matrix_family(0x0c03fd0cu,s,ram);
P_0c03fd10: /* original 6072, guest PC 0x0c03fd10 */
if(!s->budget--) { s->failed_pc=0x0c03fd10u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd12;
P_0c03fd12: /* original 6e53, guest PC 0x0c03fd12 */
if(!s->budget--) { s->failed_pc=0x0c03fd12u; return 0; }
r[14]=r[5];
goto P_0c03fd14;
P_0c03fd14: /* original 4e08, guest PC 0x0c03fd14 */
if(!s->budget--) { s->failed_pc=0x0c03fd14u; return 0; }
r[14]<<=2;
goto P_0c03fd16;
P_0c03fd16: /* original 00ee, guest PC 0x0c03fd16 */
if(!s->budget--) { s->failed_pc=0x0c03fd16u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c03fd18;
P_0c03fd18: /* original 88ff, guest PC 0x0c03fd18 */
if(!s->budget--) { s->failed_pc=0x0c03fd18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03fd1a;
P_0c03fd1a: /* original 8d29, guest PC 0x0c03fd1a */
if(!s->budget--) { s->failed_pc=0x0c03fd1au; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c03fd70; }
goto P_0c03fd1e;
P_0c03fd1c: /* original 6d03, guest PC 0x0c03fd1c */
if(!s->budget--) { s->failed_pc=0x0c03fd1cu; return 0; }
r[13]=r[0];
goto P_0c03fd1e;
P_0c03fd1e: /* original 6153, guest PC 0x0c03fd1e */
if(!s->budget--) { s->failed_pc=0x0c03fd1eu; return 0; }
r[1]=r[5];
goto P_0c03fd20;
P_0c03fd20: /* original 4108, guest PC 0x0c03fd20 */
if(!s->budget--) { s->failed_pc=0x0c03fd20u; return 0; }
r[1]<<=2;
goto P_0c03fd22;
P_0c03fd22: /* original 4108, guest PC 0x0c03fd22 */
if(!s->budget--) { s->failed_pc=0x0c03fd22u; return 0; }
r[1]<<=2;
goto P_0c03fd24;
P_0c03fd24: /* original 66b3, guest PC 0x0c03fd24 */
if(!s->budget--) { s->failed_pc=0x0c03fd24u; return 0; }
r[6]=r[11];
goto P_0c03fd26;
P_0c03fd26: /* original 4100, guest PC 0x0c03fd26 */
if(!s->budget--) { s->failed_pc=0x0c03fd26u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c03fd28;
P_0c03fd28: /* original 64a3, guest PC 0x0c03fd28 */
if(!s->budget--) { s->failed_pc=0x0c03fd28u; return 0; }
r[4]=r[10];
goto P_0c03fd2a;
P_0c03fd2a: /* original 62d3, guest PC 0x0c03fd2a */
if(!s->budget--) { s->failed_pc=0x0c03fd2au; return 0; }
r[2]=r[13];
goto P_0c03fd2c;
P_0c03fd2c: /* original 2248, guest PC 0x0c03fd2c */
if(!s->budget--) { s->failed_pc=0x0c03fd2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c03fd2e;
P_0c03fd2e: /* original 8b07, guest PC 0x0c03fd2e */
if(!s->budget--) { s->failed_pc=0x0c03fd2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd40; }
goto P_0c03fd30;
P_0c03fd30: /* original 6072, guest PC 0x0c03fd30 */
if(!s->budget--) { s->failed_pc=0x0c03fd30u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd32;
P_0c03fd32: /* original 02ee, guest PC 0x0c03fd32 */
if(!s->budget--) { s->failed_pc=0x0c03fd32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c03fd34;
P_0c03fd34: /* original 224b, guest PC 0x0c03fd34 */
if(!s->budget--) { s->failed_pc=0x0c03fd34u; return 0; }
r[2]|=r[4];
goto P_0c03fd36;
P_0c03fd36: /* original 0e26, guest PC 0x0c03fd36 */
if(!s->budget--) { s->failed_pc=0x0c03fd36u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03fd38;
P_0c03fd38: /* original 6013, guest PC 0x0c03fd38 */
if(!s->budget--) { s->failed_pc=0x0c03fd38u; return 0; }
r[0]=r[1];
goto P_0c03fd3a;
P_0c03fd3a: /* original 0009, guest PC 0x0c03fd3a */
if(!s->budget--) { s->failed_pc=0x0c03fd3au; return 0; }
goto P_0c03fd3c;
P_0c03fd3c: /* original a023, guest PC 0x0c03fd3c */
if(!s->budget--) { s->failed_pc=0x0c03fd3cu; return 0; }
r[0]+=r[6];
goto P_0c03fd86;
P_0c03fd3e: /* original 306c, guest PC 0x0c03fd3e */
if(!s->budget--) { s->failed_pc=0x0c03fd3eu; return 0; }
r[0]+=r[6];
goto P_0c03fd40;
P_0c03fd40: /* original 4400, guest PC 0x0c03fd40 */
if(!s->budget--) { s->failed_pc=0x0c03fd40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03fd42;
P_0c03fd42: /* original aff2, guest PC 0x0c03fd42 */
if(!s->budget--) { s->failed_pc=0x0c03fd42u; return 0; }
r[6]+=0x00000001u;
goto P_0c03fd2a;
P_0c03fd44: /* original 7601, guest PC 0x0c03fd44 */
if(!s->budget--) { s->failed_pc=0x0c03fd44u; return 0; }
r[6]+=0x00000001u;
return vf3_matrix_family(0x0c03fd46u,s,ram);
P_0c03fd70: /* original 7501, guest PC 0x0c03fd70 */
if(!s->budget--) { s->failed_pc=0x0c03fd70u; return 0; }
r[5]+=0x00000001u;
goto P_0c03fd72;
P_0c03fd72: /* original 6182, guest PC 0x0c03fd72 */
if(!s->budget--) { s->failed_pc=0x0c03fd72u; return 0; }
tmp=read(ram,r[8],4);
r[1]=tmp;
goto P_0c03fd74;
P_0c03fd74: /* original 711f, guest PC 0x0c03fd74 */
if(!s->budget--) { s->failed_pc=0x0c03fd74u; return 0; }
r[1]+=0x0000001fu;
goto P_0c03fd76;
P_0c03fd76: /* original 6093, guest PC 0x0c03fd76 */
if(!s->budget--) { s->failed_pc=0x0c03fd76u; return 0; }
r[0]=r[9];
goto P_0c03fd78;
P_0c03fd78: /* original 0009, guest PC 0x0c03fd78 */
if(!s->budget--) { s->failed_pc=0x0c03fd78u; return 0; }
goto P_0c03fd7a;
P_0c03fd7a: /* original d311, guest PC 0x0c03fd7a */
if(!s->budget--) { s->failed_pc=0x0c03fd7au; return 0; }
r[3]=read(ram,0x0c03fdc0u,4);
goto P_0c03fd7c;
P_0c03fd7c: /* original 430b, guest PC 0x0c03fd7c */
if(!s->budget--) { s->failed_pc=0x0c03fd7cu; return 0; }
target=r[3];
r[16]=0x0c03fd80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03fd80u) { target=s->pc; goto dispatch; }
goto P_0c03fd80;
P_0c03fd7e: /* original 0009, guest PC 0x0c03fd7e */
if(!s->budget--) { s->failed_pc=0x0c03fd7eu; return 0; }
goto P_0c03fd80;
P_0c03fd80: /* original 3503, guest PC 0x0c03fd80 */
if(!s->budget--) { s->failed_pc=0x0c03fd80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[0])!=0);
goto P_0c03fd82;
P_0c03fd82: /* original 8bc5, guest PC 0x0c03fd82 */
if(!s->budget--) { s->failed_pc=0x0c03fd82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd10; }
goto P_0c03fd84;
P_0c03fd84: /* original e0ff, guest PC 0x0c03fd84 */
if(!s->budget--) { s->failed_pc=0x0c03fd84u; return 0; }
r[0]=0xffffffffu;
goto P_0c03fd86;
P_0c03fd86: /* original 4f26, guest PC 0x0c03fd86 */
if(!s->budget--) { s->failed_pc=0x0c03fd86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fd88;
P_0c03fd88: /* original 68f6, guest PC 0x0c03fd88 */
if(!s->budget--) { s->failed_pc=0x0c03fd88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03fd8a;
P_0c03fd8a: /* original 69f6, guest PC 0x0c03fd8a */
if(!s->budget--) { s->failed_pc=0x0c03fd8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03fd8c;
P_0c03fd8c: /* original 6af6, guest PC 0x0c03fd8c */
if(!s->budget--) { s->failed_pc=0x0c03fd8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03fd8e;
P_0c03fd8e: /* original 6bf6, guest PC 0x0c03fd8e */
if(!s->budget--) { s->failed_pc=0x0c03fd8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03fd90;
P_0c03fd90: /* original 6df6, guest PC 0x0c03fd90 */
if(!s->budget--) { s->failed_pc=0x0c03fd90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03fd92;
P_0c03fd92: /* original 000b, guest PC 0x0c03fd92 */
if(!s->budget--) { s->failed_pc=0x0c03fd92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fd94: /* original 6ef6, guest PC 0x0c03fd94 */
if(!s->budget--) { s->failed_pc=0x0c03fd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03fd96u,s,ram);
P_0c040154: /* original 7fe0, guest PC 0x0c040154 */
if(!s->budget--) { s->failed_pc=0x0c040154u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c040156;
P_0c040156: /* original 1f47, guest PC 0x0c040156 */
if(!s->budget--) { s->failed_pc=0x0c040156u; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c040158;
P_0c040158: /* original 1f56, guest PC 0x0c040158 */
if(!s->budget--) { s->failed_pc=0x0c040158u; return 0; }
write(ram,r[15]+24,r[5],4);
goto P_0c04015a;
P_0c04015a: /* original 53f6, guest PC 0x0c04015a */
if(!s->budget--) { s->failed_pc=0x0c04015au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04015c;
P_0c04015c: /* original 4311, guest PC 0x0c04015c */
if(!s->budget--) { s->failed_pc=0x0c04015cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c04015e;
P_0c04015e: /* original 8b03, guest PC 0x0c04015e */
if(!s->budget--) { s->failed_pc=0x0c04015eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040168; }
goto P_0c040160;
P_0c040160: /* original e108, guest PC 0x0c040160 */
if(!s->budget--) { s->failed_pc=0x0c040160u; return 0; }
r[1]=0x00000008u;
goto P_0c040162;
P_0c040162: /* original 52f6, guest PC 0x0c040162 */
if(!s->budget--) { s->failed_pc=0x0c040162u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c040164;
P_0c040164: /* original 3213, guest PC 0x0c040164 */
if(!s->budget--) { s->failed_pc=0x0c040164u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c040166;
P_0c040166: /* original 8b05, guest PC 0x0c040166 */
if(!s->budget--) { s->failed_pc=0x0c040166u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040174; }
goto P_0c040168;
P_0c040168: /* original e0ff, guest PC 0x0c040168 */
if(!s->budget--) { s->failed_pc=0x0c040168u; return 0; }
r[0]=0xffffffffu;
goto P_0c04016a;
P_0c04016a: /* original 7f20, guest PC 0x0c04016a */
if(!s->budget--) { s->failed_pc=0x0c04016au; return 0; }
r[15]+=0x00000020u;
goto P_0c04016c;
P_0c04016c: /* original 000b, guest PC 0x0c04016c */
if(!s->budget--) { s->failed_pc=0x0c04016cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04016e: /* original 0009, guest PC 0x0c04016e */
if(!s->budget--) { s->failed_pc=0x0c04016eu; return 0; }
return vf3_matrix_family(0x0c040170u,s,ram);
P_0c040174: /* original 52f7, guest PC 0x0c040174 */
if(!s->budget--) { s->failed_pc=0x0c040174u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c040176;
P_0c040176: /* original 1f21, guest PC 0x0c040176 */
if(!s->budget--) { s->failed_pc=0x0c040176u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c040178;
P_0c040178: /* original d323, guest PC 0x0c040178 */
if(!s->budget--) { s->failed_pc=0x0c040178u; return 0; }
r[3]=read(ram,0x0c040208u,4);
goto P_0c04017a;
P_0c04017a: /* original 2f32, guest PC 0x0c04017a */
if(!s->budget--) { s->failed_pc=0x0c04017au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04017c;
P_0c04017c: /* original e200, guest PC 0x0c04017c */
if(!s->budget--) { s->failed_pc=0x0c04017cu; return 0; }
r[2]=0x00000000u;
goto P_0c04017e;
P_0c04017e: /* original 1f23, guest PC 0x0c04017e */
if(!s->budget--) { s->failed_pc=0x0c04017eu; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c040180;
P_0c040180: /* original a013, guest PC 0x0c040180 */
if(!s->budget--) { s->failed_pc=0x0c040180u; return 0; }
goto P_0c0401aa;
P_0c040182: /* original 0009, guest PC 0x0c040182 */
if(!s->budget--) { s->failed_pc=0x0c040182u; return 0; }
goto P_0c040184;
P_0c040184: /* original 51f1, guest PC 0x0c040184 */
if(!s->budget--) { s->failed_pc=0x0c040184u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c040186;
P_0c040186: /* original 7101, guest PC 0x0c040186 */
if(!s->budget--) { s->failed_pc=0x0c040186u; return 0; }
r[1]+=0x00000001u;
goto P_0c040188;
P_0c040188: /* original 1f11, guest PC 0x0c040188 */
if(!s->budget--) { s->failed_pc=0x0c040188u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c04018a;
P_0c04018a: /* original 71ff, guest PC 0x0c04018a */
if(!s->budget--) { s->failed_pc=0x0c04018au; return 0; }
r[1]+=0xffffffffu;
goto P_0c04018c;
P_0c04018c: /* original 6310, guest PC 0x0c04018c */
if(!s->budget--) { s->failed_pc=0x0c04018cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c04018e;
P_0c04018e: /* original 62f2, guest PC 0x0c04018e */
if(!s->budget--) { s->failed_pc=0x0c04018eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c040190;
P_0c040190: /* original 7201, guest PC 0x0c040190 */
if(!s->budget--) { s->failed_pc=0x0c040190u; return 0; }
r[2]+=0x00000001u;
goto P_0c040192;
P_0c040192: /* original 2f22, guest PC 0x0c040192 */
if(!s->budget--) { s->failed_pc=0x0c040192u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c040194;
P_0c040194: /* original 72ff, guest PC 0x0c040194 */
if(!s->budget--) { s->failed_pc=0x0c040194u; return 0; }
r[2]+=0xffffffffu;
goto P_0c040196;
P_0c040196: /* original 6120, guest PC 0x0c040196 */
if(!s->budget--) { s->failed_pc=0x0c040196u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c040198;
P_0c040198: /* original 3310, guest PC 0x0c040198 */
if(!s->budget--) { s->failed_pc=0x0c040198u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c04019a;
P_0c04019a: /* original 8903, guest PC 0x0c04019a */
if(!s->budget--) { s->failed_pc=0x0c04019au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0401a4; }
goto P_0c04019c;
P_0c04019c: /* original e0fe, guest PC 0x0c04019c */
if(!s->budget--) { s->failed_pc=0x0c04019cu; return 0; }
r[0]=0xfffffffeu;
goto P_0c04019e;
P_0c04019e: /* original 7f20, guest PC 0x0c04019e */
if(!s->budget--) { s->failed_pc=0x0c04019eu; return 0; }
r[15]+=0x00000020u;
goto P_0c0401a0;
P_0c0401a0: /* original 000b, guest PC 0x0c0401a0 */
if(!s->budget--) { s->failed_pc=0x0c0401a0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401a2: /* original 0009, guest PC 0x0c0401a2 */
if(!s->budget--) { s->failed_pc=0x0c0401a2u; return 0; }
goto P_0c0401a4;
P_0c0401a4: /* original 52f3, guest PC 0x0c0401a4 */
if(!s->budget--) { s->failed_pc=0x0c0401a4u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0401a6;
P_0c0401a6: /* original 7201, guest PC 0x0c0401a6 */
if(!s->budget--) { s->failed_pc=0x0c0401a6u; return 0; }
r[2]+=0x00000001u;
goto P_0c0401a8;
P_0c0401a8: /* original 1f23, guest PC 0x0c0401a8 */
if(!s->budget--) { s->failed_pc=0x0c0401a8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0401aa;
P_0c0401aa: /* original e304, guest PC 0x0c0401aa */
if(!s->budget--) { s->failed_pc=0x0c0401aau; return 0; }
r[3]=0x00000004u;
goto P_0c0401ac;
P_0c0401ac: /* original 51f3, guest PC 0x0c0401ac */
if(!s->budget--) { s->failed_pc=0x0c0401acu; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c0401ae;
P_0c0401ae: /* original 3133, guest PC 0x0c0401ae */
if(!s->budget--) { s->failed_pc=0x0c0401aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0401b0;
P_0c0401b0: /* original 8be8, guest PC 0x0c0401b0 */
if(!s->budget--) { s->failed_pc=0x0c0401b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040184; }
goto P_0c0401b2;
P_0c0401b2: /* original 50f6, guest PC 0x0c0401b2 */
if(!s->budget--) { s->failed_pc=0x0c0401b2u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0401b4;
P_0c0401b4: /* original 6303, guest PC 0x0c0401b4 */
if(!s->budget--) { s->failed_pc=0x0c0401b4u; return 0; }
r[3]=r[0];
goto P_0c0401b6;
P_0c0401b6: /* original 4000, guest PC 0x0c0401b6 */
if(!s->budget--) { s->failed_pc=0x0c0401b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0401b8;
P_0c0401b8: /* original 303c, guest PC 0x0c0401b8 */
if(!s->budget--) { s->failed_pc=0x0c0401b8u; return 0; }
r[0]+=r[3];
goto P_0c0401ba;
P_0c0401ba: /* original 4008, guest PC 0x0c0401ba */
if(!s->budget--) { s->failed_pc=0x0c0401bau; return 0; }
r[0]<<=2;
goto P_0c0401bc;
P_0c0401bc: /* original 600e, guest PC 0x0c0401bc */
if(!s->budget--) { s->failed_pc=0x0c0401bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0401be;
P_0c0401be: /* original d113, guest PC 0x0c0401be */
if(!s->budget--) { s->failed_pc=0x0c0401beu; return 0; }
r[1]=read(ram,0x0c04020cu,4);
goto P_0c0401c0;
P_0c0401c0: /* original 001e, guest PC 0x0c0401c0 */
if(!s->budget--) { s->failed_pc=0x0c0401c0u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0401c2;
P_0c0401c2: /* original 88ff, guest PC 0x0c0401c2 */
if(!s->budget--) { s->failed_pc=0x0c0401c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0401c4;
P_0c0401c4: /* original 8903, guest PC 0x0c0401c4 */
if(!s->budget--) { s->failed_pc=0x0c0401c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0401ce; }
goto P_0c0401c6;
P_0c0401c6: /* original e0fd, guest PC 0x0c0401c6 */
if(!s->budget--) { s->failed_pc=0x0c0401c6u; return 0; }
r[0]=0xfffffffdu;
goto P_0c0401c8;
P_0c0401c8: /* original 7f20, guest PC 0x0c0401c8 */
if(!s->budget--) { s->failed_pc=0x0c0401c8u; return 0; }
r[15]+=0x00000020u;
goto P_0c0401ca;
P_0c0401ca: /* original 000b, guest PC 0x0c0401ca */
if(!s->budget--) { s->failed_pc=0x0c0401cau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401cc: /* original 0009, guest PC 0x0c0401cc */
if(!s->budget--) { s->failed_pc=0x0c0401ccu; return 0; }
goto P_0c0401ce;
P_0c0401ce: /* original 52f7, guest PC 0x0c0401ce */
if(!s->budget--) { s->failed_pc=0x0c0401ceu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c0401d0;
P_0c0401d0: /* original 5322, guest PC 0x0c0401d0 */
if(!s->budget--) { s->failed_pc=0x0c0401d0u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c0401d2;
P_0c0401d2: /* original 1f34, guest PC 0x0c0401d2 */
if(!s->budget--) { s->failed_pc=0x0c0401d2u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0401d4;
P_0c0401d4: /* original d30e, guest PC 0x0c0401d4 */
if(!s->budget--) { s->failed_pc=0x0c0401d4u; return 0; }
r[3]=read(ram,0x0c040210u,4);
goto P_0c0401d6;
P_0c0401d6: /* original 6132, guest PC 0x0c0401d6 */
if(!s->budget--) { s->failed_pc=0x0c0401d6u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0401d8;
P_0c0401d8: /* original 1f15, guest PC 0x0c0401d8 */
if(!s->budget--) { s->failed_pc=0x0c0401d8u; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0401da;
P_0c0401da: /* original 51f4, guest PC 0x0c0401da */
if(!s->budget--) { s->failed_pc=0x0c0401dau; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c0401dc;
P_0c0401dc: /* original d20d, guest PC 0x0c0401dc */
if(!s->budget--) { s->failed_pc=0x0c0401dcu; return 0; }
r[2]=read(ram,0x0c040214u,4);
goto P_0c0401de;
P_0c0401de: /* original 6022, guest PC 0x0c0401de */
if(!s->budget--) { s->failed_pc=0x0c0401deu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0401e0;
P_0c0401e0: /* original 301c, guest PC 0x0c0401e0 */
if(!s->budget--) { s->failed_pc=0x0c0401e0u; return 0; }
r[0]+=r[1];
goto P_0c0401e2;
P_0c0401e2: /* original 52f5, guest PC 0x0c0401e2 */
if(!s->budget--) { s->failed_pc=0x0c0401e2u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0401e4;
P_0c0401e4: /* original 3027, guest PC 0x0c0401e4 */
if(!s->budget--) { s->failed_pc=0x0c0401e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c0401e6;
P_0c0401e6: /* original 8b03, guest PC 0x0c0401e6 */
if(!s->budget--) { s->failed_pc=0x0c0401e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0401f0; }
goto P_0c0401e8;
P_0c0401e8: /* original e0fc, guest PC 0x0c0401e8 */
if(!s->budget--) { s->failed_pc=0x0c0401e8u; return 0; }
r[0]=0xfffffffcu;
goto P_0c0401ea;
P_0c0401ea: /* original 7f20, guest PC 0x0c0401ea */
if(!s->budget--) { s->failed_pc=0x0c0401eau; return 0; }
r[15]+=0x00000020u;
goto P_0c0401ec;
P_0c0401ec: /* original 000b, guest PC 0x0c0401ec */
if(!s->budget--) { s->failed_pc=0x0c0401ecu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401ee: /* original 0009, guest PC 0x0c0401ee */
if(!s->budget--) { s->failed_pc=0x0c0401eeu; return 0; }
goto P_0c0401f0;
P_0c0401f0: /* original d209, guest PC 0x0c0401f0 */
if(!s->budget--) { s->failed_pc=0x0c0401f0u; return 0; }
r[2]=read(ram,0x0c040218u,4);
goto P_0c0401f2;
P_0c0401f2: /* original 6322, guest PC 0x0c0401f2 */
if(!s->budget--) { s->failed_pc=0x0c0401f2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0401f4;
P_0c0401f4: /* original 2338, guest PC 0x0c0401f4 */
if(!s->budget--) { s->failed_pc=0x0c0401f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0401f6;
P_0c0401f6: /* original 8903, guest PC 0x0c0401f6 */
if(!s->budget--) { s->failed_pc=0x0c0401f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040200; }
goto P_0c0401f8;
P_0c0401f8: /* original e0fb, guest PC 0x0c0401f8 */
if(!s->budget--) { s->failed_pc=0x0c0401f8u; return 0; }
r[0]=0xfffffffbu;
goto P_0c0401fa;
P_0c0401fa: /* original 7f20, guest PC 0x0c0401fa */
if(!s->budget--) { s->failed_pc=0x0c0401fau; return 0; }
r[15]+=0x00000020u;
goto P_0c0401fc;
P_0c0401fc: /* original 000b, guest PC 0x0c0401fc */
if(!s->budget--) { s->failed_pc=0x0c0401fcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401fe: /* original 0009, guest PC 0x0c0401fe */
if(!s->budget--) { s->failed_pc=0x0c0401feu; return 0; }
goto P_0c040200;
P_0c040200: /* original e000, guest PC 0x0c040200 */
if(!s->budget--) { s->failed_pc=0x0c040200u; return 0; }
r[0]=0x00000000u;
goto P_0c040202;
P_0c040202: /* original 7f20, guest PC 0x0c040202 */
if(!s->budget--) { s->failed_pc=0x0c040202u; return 0; }
r[15]+=0x00000020u;
goto P_0c040204;
P_0c040204: /* original 000b, guest PC 0x0c040204 */
if(!s->budget--) { s->failed_pc=0x0c040204u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040206: /* original 0009, guest PC 0x0c040206 */
if(!s->budget--) { s->failed_pc=0x0c040206u; return 0; }
return vf3_matrix_family(0x0c040208u,s,ram);
P_0c040222: /* original 7fe4, guest PC 0x0c040222 */
if(!s->budget--) { s->failed_pc=0x0c040222u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c040224;
P_0c040224: /* original 1f46, guest PC 0x0c040224 */
if(!s->budget--) { s->failed_pc=0x0c040224u; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c040226;
P_0c040226: /* original 1f55, guest PC 0x0c040226 */
if(!s->budget--) { s->failed_pc=0x0c040226u; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c040228;
P_0c040228: /* original 1f64, guest PC 0x0c040228 */
if(!s->budget--) { s->failed_pc=0x0c040228u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c04022a;
P_0c04022a: /* original 1f73, guest PC 0x0c04022a */
if(!s->budget--) { s->failed_pc=0x0c04022au; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c04022c;
P_0c04022c: /* original d312, guest PC 0x0c04022c */
if(!s->budget--) { s->failed_pc=0x0c04022cu; return 0; }
r[3]=read(ram,0x0c040278u,4);
goto P_0c04022e;
P_0c04022e: /* original 52f4, guest PC 0x0c04022e */
if(!s->budget--) { s->failed_pc=0x0c04022eu; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c040230;
P_0c040230: /* original 6132, guest PC 0x0c040230 */
if(!s->budget--) { s->failed_pc=0x0c040230u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040232;
P_0c040232: /* original 312c, guest PC 0x0c040232 */
if(!s->budget--) { s->failed_pc=0x0c040232u; return 0; }
r[1]+=r[2];
goto P_0c040234;
P_0c040234: /* original 2312, guest PC 0x0c040234 */
if(!s->budget--) { s->failed_pc=0x0c040234u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c040236;
P_0c040236: /* original 53f6, guest PC 0x0c040236 */
if(!s->budget--) { s->failed_pc=0x0c040236u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c040238;
P_0c040238: /* original 6033, guest PC 0x0c040238 */
if(!s->budget--) { s->failed_pc=0x0c040238u; return 0; }
r[0]=r[3];
goto P_0c04023a;
P_0c04023a: /* original 0009, guest PC 0x0c04023a */
if(!s->budget--) { s->failed_pc=0x0c04023au; return 0; }
goto P_0c04023c;
P_0c04023c: /* original 4300, guest PC 0x0c04023c */
if(!s->budget--) { s->failed_pc=0x0c04023cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04023e;
P_0c04023e: /* original 330c, guest PC 0x0c04023e */
if(!s->budget--) { s->failed_pc=0x0c04023eu; return 0; }
r[3]+=r[0];
goto P_0c040240;
P_0c040240: /* original 4308, guest PC 0x0c040240 */
if(!s->budget--) { s->failed_pc=0x0c040240u; return 0; }
r[3]<<=2;
goto P_0c040242;
P_0c040242: /* original 633e, guest PC 0x0c040242 */
if(!s->budget--) { s->failed_pc=0x0c040242u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040244;
P_0c040244: /* original 52f5, guest PC 0x0c040244 */
if(!s->budget--) { s->failed_pc=0x0c040244u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c040246;
P_0c040246: /* original d00d, guest PC 0x0c040246 */
if(!s->budget--) { s->failed_pc=0x0c040246u; return 0; }
r[0]=read(ram,0x0c04027cu,4);
goto P_0c040248;
P_0c040248: /* original 0326, guest PC 0x0c040248 */
if(!s->budget--) { s->failed_pc=0x0c040248u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c04024a;
P_0c04024a: /* original 53f6, guest PC 0x0c04024a */
if(!s->budget--) { s->failed_pc=0x0c04024au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04024c;
P_0c04024c: /* original 6233, guest PC 0x0c04024c */
if(!s->budget--) { s->failed_pc=0x0c04024cu; return 0; }
r[2]=r[3];
goto P_0c04024e;
P_0c04024e: /* original 4300, guest PC 0x0c04024e */
if(!s->budget--) { s->failed_pc=0x0c04024eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040250;
P_0c040250: /* original 332c, guest PC 0x0c040250 */
if(!s->budget--) { s->failed_pc=0x0c040250u; return 0; }
r[3]+=r[2];
goto P_0c040252;
P_0c040252: /* original 4308, guest PC 0x0c040252 */
if(!s->budget--) { s->failed_pc=0x0c040252u; return 0; }
r[3]<<=2;
goto P_0c040254;
P_0c040254: /* original 633e, guest PC 0x0c040254 */
if(!s->budget--) { s->failed_pc=0x0c040254u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040256;
P_0c040256: /* original 51f4, guest PC 0x0c040256 */
if(!s->budget--) { s->failed_pc=0x0c040256u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c040258;
P_0c040258: /* original d009, guest PC 0x0c040258 */
if(!s->budget--) { s->failed_pc=0x0c040258u; return 0; }
r[0]=read(ram,0x0c040280u,4);
goto P_0c04025a;
P_0c04025a: /* original 0316, guest PC 0x0c04025a */
if(!s->budget--) { s->failed_pc=0x0c04025au; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c04025c;
P_0c04025c: /* original 53f6, guest PC 0x0c04025c */
if(!s->budget--) { s->failed_pc=0x0c04025cu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04025e;
P_0c04025e: /* original 4308, guest PC 0x0c04025e */
if(!s->budget--) { s->failed_pc=0x0c04025eu; return 0; }
r[3]<<=2;
goto P_0c040260;
P_0c040260: /* original d208, guest PC 0x0c040260 */
if(!s->budget--) { s->failed_pc=0x0c040260u; return 0; }
r[2]=read(ram,0x0c040284u,4);
goto P_0c040262;
P_0c040262: /* original 332c, guest PC 0x0c040262 */
if(!s->budget--) { s->failed_pc=0x0c040262u; return 0; }
r[3]+=r[2];
goto P_0c040264;
P_0c040264: /* original 51f5, guest PC 0x0c040264 */
if(!s->budget--) { s->failed_pc=0x0c040264u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c040266;
P_0c040266: /* original 2312, guest PC 0x0c040266 */
if(!s->budget--) { s->failed_pc=0x0c040266u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c040268;
P_0c040268: /* original e300, guest PC 0x0c040268 */
if(!s->budget--) { s->failed_pc=0x0c040268u; return 0; }
r[3]=0x00000000u;
goto P_0c04026a;
P_0c04026a: /* original 1f32, guest PC 0x0c04026a */
if(!s->budget--) { s->failed_pc=0x0c04026au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04026c;
P_0c04026c: /* original 2f32, guest PC 0x0c04026c */
if(!s->budget--) { s->failed_pc=0x0c04026cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04026e;
P_0c04026e: /* original 51f6, guest PC 0x0c04026e */
if(!s->budget--) { s->failed_pc=0x0c04026eu; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c040270;
P_0c040270: /* original 71ff, guest PC 0x0c040270 */
if(!s->budget--) { s->failed_pc=0x0c040270u; return 0; }
r[1]+=0xffffffffu;
goto P_0c040272;
P_0c040272: /* original 1f11, guest PC 0x0c040272 */
if(!s->budget--) { s->failed_pc=0x0c040272u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c040274;
P_0c040274: /* original a02a, guest PC 0x0c040274 */
if(!s->budget--) { s->failed_pc=0x0c040274u; return 0; }
goto P_0c0402cc;
P_0c040276: /* original 0009, guest PC 0x0c040276 */
if(!s->budget--) { s->failed_pc=0x0c040276u; return 0; }
return vf3_matrix_family(0x0c040278u,s,ram);
P_0c040288: /* original 84f4, guest PC 0x0c040288 */
if(!s->budget--) { s->failed_pc=0x0c040288u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04028a;
P_0c04028a: /* original 6303, guest PC 0x0c04028a */
if(!s->budget--) { s->failed_pc=0x0c04028au; return 0; }
r[3]=r[0];
goto P_0c04028c;
P_0c04028c: /* original 4000, guest PC 0x0c04028c */
if(!s->budget--) { s->failed_pc=0x0c04028cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04028e;
P_0c04028e: /* original 303c, guest PC 0x0c04028e */
if(!s->budget--) { s->failed_pc=0x0c04028eu; return 0; }
r[0]+=r[3];
goto P_0c040290;
P_0c040290: /* original 4008, guest PC 0x0c040290 */
if(!s->budget--) { s->failed_pc=0x0c040290u; return 0; }
r[0]<<=2;
goto P_0c040292;
P_0c040292: /* original 600e, guest PC 0x0c040292 */
if(!s->budget--) { s->failed_pc=0x0c040292u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c040294;
P_0c040294: /* original d119, guest PC 0x0c040294 */
if(!s->budget--) { s->failed_pc=0x0c040294u; return 0; }
r[1]=read(ram,0x0c0402fcu,4);
goto P_0c040296;
P_0c040296: /* original 001e, guest PC 0x0c040296 */
if(!s->budget--) { s->failed_pc=0x0c040296u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040298;
P_0c040298: /* original 88ff, guest PC 0x0c040298 */
if(!s->budget--) { s->failed_pc=0x0c040298u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04029a;
P_0c04029a: /* original 8914, guest PC 0x0c04029a */
if(!s->budget--) { s->failed_pc=0x0c04029au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0402c6; }
goto P_0c04029c;
P_0c04029c: /* original 52f1, guest PC 0x0c04029c */
if(!s->budget--) { s->failed_pc=0x0c04029cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04029e;
P_0c04029e: /* original 6323, guest PC 0x0c04029e */
if(!s->budget--) { s->failed_pc=0x0c04029eu; return 0; }
r[3]=r[2];
goto P_0c0402a0;
P_0c0402a0: /* original 4200, guest PC 0x0c0402a0 */
if(!s->budget--) { s->failed_pc=0x0c0402a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0402a2;
P_0c0402a2: /* original 323c, guest PC 0x0c0402a2 */
if(!s->budget--) { s->failed_pc=0x0c0402a2u; return 0; }
r[2]+=r[3];
goto P_0c0402a4;
P_0c0402a4: /* original 4208, guest PC 0x0c0402a4 */
if(!s->budget--) { s->failed_pc=0x0c0402a4u; return 0; }
r[2]<<=2;
goto P_0c0402a6;
P_0c0402a6: /* original 622e, guest PC 0x0c0402a6 */
if(!s->budget--) { s->failed_pc=0x0c0402a6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c0402a8;
P_0c0402a8: /* original 50f1, guest PC 0x0c0402a8 */
if(!s->budget--) { s->failed_pc=0x0c0402a8u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0402aa;
P_0c0402aa: /* original 6303, guest PC 0x0c0402aa */
if(!s->budget--) { s->failed_pc=0x0c0402aau; return 0; }
r[3]=r[0];
goto P_0c0402ac;
P_0c0402ac: /* original 4000, guest PC 0x0c0402ac */
if(!s->budget--) { s->failed_pc=0x0c0402acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0402ae;
P_0c0402ae: /* original 303c, guest PC 0x0c0402ae */
if(!s->budget--) { s->failed_pc=0x0c0402aeu; return 0; }
r[0]+=r[3];
goto P_0c0402b0;
P_0c0402b0: /* original 4008, guest PC 0x0c0402b0 */
if(!s->budget--) { s->failed_pc=0x0c0402b0u; return 0; }
r[0]<<=2;
goto P_0c0402b2;
P_0c0402b2: /* original 600e, guest PC 0x0c0402b2 */
if(!s->budget--) { s->failed_pc=0x0c0402b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0402b4;
P_0c0402b4: /* original 6313, guest PC 0x0c0402b4 */
if(!s->budget--) { s->failed_pc=0x0c0402b4u; return 0; }
r[3]=r[1];
goto P_0c0402b6;
P_0c0402b6: /* original 303c, guest PC 0x0c0402b6 */
if(!s->budget--) { s->failed_pc=0x0c0402b6u; return 0; }
r[0]+=r[3];
goto P_0c0402b8;
P_0c0402b8: /* original 5302, guest PC 0x0c0402b8 */
if(!s->budget--) { s->failed_pc=0x0c0402b8u; return 0; }
r[3]=read(ram,r[0]+8,4);
goto P_0c0402ba;
P_0c0402ba: /* original d011, guest PC 0x0c0402ba */
if(!s->budget--) { s->failed_pc=0x0c0402bau; return 0; }
r[0]=read(ram,0x0c040300u,4);
goto P_0c0402bc;
P_0c0402bc: /* original 022e, guest PC 0x0c0402bc */
if(!s->budget--) { s->failed_pc=0x0c0402bcu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c0402be;
P_0c0402be: /* original 323c, guest PC 0x0c0402be */
if(!s->budget--) { s->failed_pc=0x0c0402beu; return 0; }
r[2]+=r[3];
goto P_0c0402c0;
P_0c0402c0: /* original 2f22, guest PC 0x0c0402c0 */
if(!s->budget--) { s->failed_pc=0x0c0402c0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0402c2;
P_0c0402c2: /* original a006, guest PC 0x0c0402c2 */
if(!s->budget--) { s->failed_pc=0x0c0402c2u; return 0; }
goto P_0c0402d2;
P_0c0402c4: /* original 0009, guest PC 0x0c0402c4 */
if(!s->budget--) { s->failed_pc=0x0c0402c4u; return 0; }
goto P_0c0402c6;
P_0c0402c6: /* original 51f1, guest PC 0x0c0402c6 */
if(!s->budget--) { s->failed_pc=0x0c0402c6u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0402c8;
P_0c0402c8: /* original 71ff, guest PC 0x0c0402c8 */
if(!s->budget--) { s->failed_pc=0x0c0402c8u; return 0; }
r[1]+=0xffffffffu;
goto P_0c0402ca;
P_0c0402ca: /* original 1f11, guest PC 0x0c0402ca */
if(!s->budget--) { s->failed_pc=0x0c0402cau; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0402cc;
P_0c0402cc: /* original 53f1, guest PC 0x0c0402cc */
if(!s->budget--) { s->failed_pc=0x0c0402ccu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0402ce;
P_0c0402ce: /* original 4311, guest PC 0x0c0402ce */
if(!s->budget--) { s->failed_pc=0x0c0402ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0402d0;
P_0c0402d0: /* original 89da, guest PC 0x0c0402d0 */
if(!s->budget--) { s->failed_pc=0x0c0402d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040288; }
goto P_0c0402d2;
P_0c0402d2: /* original 61f2, guest PC 0x0c0402d2 */
if(!s->budget--) { s->failed_pc=0x0c0402d2u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0402d4;
P_0c0402d4: /* original 2118, guest PC 0x0c0402d4 */
if(!s->budget--) { s->failed_pc=0x0c0402d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0402d6;
P_0c0402d6: /* original 8b02, guest PC 0x0c0402d6 */
if(!s->budget--) { s->failed_pc=0x0c0402d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0402de; }
goto P_0c0402d8;
P_0c0402d8: /* original d10a, guest PC 0x0c0402d8 */
if(!s->budget--) { s->failed_pc=0x0c0402d8u; return 0; }
r[1]=read(ram,0x0c040304u,4);
goto P_0c0402da;
P_0c0402da: /* original 6212, guest PC 0x0c0402da */
if(!s->budget--) { s->failed_pc=0x0c0402dau; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0402dc;
P_0c0402dc: /* original 2f22, guest PC 0x0c0402dc */
if(!s->budget--) { s->failed_pc=0x0c0402dcu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0402de;
P_0c0402de: /* original 53f6, guest PC 0x0c0402de */
if(!s->budget--) { s->failed_pc=0x0c0402deu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0402e0;
P_0c0402e0: /* original 6233, guest PC 0x0c0402e0 */
if(!s->budget--) { s->failed_pc=0x0c0402e0u; return 0; }
r[2]=r[3];
goto P_0c0402e2;
P_0c0402e2: /* original 4300, guest PC 0x0c0402e2 */
if(!s->budget--) { s->failed_pc=0x0c0402e2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0402e4;
P_0c0402e4: /* original 332c, guest PC 0x0c0402e4 */
if(!s->budget--) { s->failed_pc=0x0c0402e4u; return 0; }
r[3]+=r[2];
goto P_0c0402e6;
P_0c0402e6: /* original 4308, guest PC 0x0c0402e6 */
if(!s->budget--) { s->failed_pc=0x0c0402e6u; return 0; }
r[3]<<=2;
goto P_0c0402e8;
P_0c0402e8: /* original 633e, guest PC 0x0c0402e8 */
if(!s->budget--) { s->failed_pc=0x0c0402e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c0402ea;
P_0c0402ea: /* original 61f2, guest PC 0x0c0402ea */
if(!s->budget--) { s->failed_pc=0x0c0402eau; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0402ec;
P_0c0402ec: /* original d004, guest PC 0x0c0402ec */
if(!s->budget--) { s->failed_pc=0x0c0402ecu; return 0; }
r[0]=read(ram,0x0c040300u,4);
goto P_0c0402ee;
P_0c0402ee: /* original 0316, guest PC 0x0c0402ee */
if(!s->budget--) { s->failed_pc=0x0c0402eeu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c0402f0;
P_0c0402f0: /* original 53f6, guest PC 0x0c0402f0 */
if(!s->budget--) { s->failed_pc=0x0c0402f0u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0402f2;
P_0c0402f2: /* original 7301, guest PC 0x0c0402f2 */
if(!s->budget--) { s->failed_pc=0x0c0402f2u; return 0; }
r[3]+=0x00000001u;
goto P_0c0402f4;
P_0c0402f4: /* original 1f31, guest PC 0x0c0402f4 */
if(!s->budget--) { s->failed_pc=0x0c0402f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0402f6;
P_0c0402f6: /* original a02a, guest PC 0x0c0402f6 */
if(!s->budget--) { s->failed_pc=0x0c0402f6u; return 0; }
goto P_0c04034e;
P_0c0402f8: /* original 0009, guest PC 0x0c0402f8 */
if(!s->budget--) { s->failed_pc=0x0c0402f8u; return 0; }
return vf3_matrix_family(0x0c0402fau,s,ram);
P_0c040308: /* original 84f4, guest PC 0x0c040308 */
if(!s->budget--) { s->failed_pc=0x0c040308u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04030a;
P_0c04030a: /* original 6303, guest PC 0x0c04030a */
if(!s->budget--) { s->failed_pc=0x0c04030au; return 0; }
r[3]=r[0];
goto P_0c04030c;
P_0c04030c: /* original 4000, guest PC 0x0c04030c */
if(!s->budget--) { s->failed_pc=0x0c04030cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04030e;
P_0c04030e: /* original 303c, guest PC 0x0c04030e */
if(!s->budget--) { s->failed_pc=0x0c04030eu; return 0; }
r[0]+=r[3];
goto P_0c040310;
P_0c040310: /* original 4008, guest PC 0x0c040310 */
if(!s->budget--) { s->failed_pc=0x0c040310u; return 0; }
r[0]<<=2;
goto P_0c040312;
P_0c040312: /* original 600e, guest PC 0x0c040312 */
if(!s->budget--) { s->failed_pc=0x0c040312u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c040314;
P_0c040314: /* original d115, guest PC 0x0c040314 */
if(!s->budget--) { s->failed_pc=0x0c040314u; return 0; }
r[1]=read(ram,0x0c04036cu,4);
goto P_0c040316;
P_0c040316: /* original 001e, guest PC 0x0c040316 */
if(!s->budget--) { s->failed_pc=0x0c040316u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040318;
P_0c040318: /* original 88ff, guest PC 0x0c040318 */
if(!s->budget--) { s->failed_pc=0x0c040318u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04031a;
P_0c04031a: /* original 8915, guest PC 0x0c04031a */
if(!s->budget--) { s->failed_pc=0x0c04031au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040348; }
goto P_0c04031c;
P_0c04031c: /* original 52f1, guest PC 0x0c04031c */
if(!s->budget--) { s->failed_pc=0x0c04031cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04031e;
P_0c04031e: /* original 6323, guest PC 0x0c04031e */
if(!s->budget--) { s->failed_pc=0x0c04031eu; return 0; }
r[3]=r[2];
goto P_0c040320;
P_0c040320: /* original 4200, guest PC 0x0c040320 */
if(!s->budget--) { s->failed_pc=0x0c040320u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c040322;
P_0c040322: /* original 323c, guest PC 0x0c040322 */
if(!s->budget--) { s->failed_pc=0x0c040322u; return 0; }
r[2]+=r[3];
goto P_0c040324;
P_0c040324: /* original 4208, guest PC 0x0c040324 */
if(!s->budget--) { s->failed_pc=0x0c040324u; return 0; }
r[2]<<=2;
goto P_0c040326;
P_0c040326: /* original 622e, guest PC 0x0c040326 */
if(!s->budget--) { s->failed_pc=0x0c040326u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c040328;
P_0c040328: /* original d011, guest PC 0x0c040328 */
if(!s->budget--) { s->failed_pc=0x0c040328u; return 0; }
r[0]=read(ram,0x0c040370u,4);
goto P_0c04032a;
P_0c04032a: /* original 032e, guest PC 0x0c04032a */
if(!s->budget--) { s->failed_pc=0x0c04032au; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c04032c;
P_0c04032c: /* original 50f2, guest PC 0x0c04032c */
if(!s->budget--) { s->failed_pc=0x0c04032cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c04032e;
P_0c04032e: /* original 303c, guest PC 0x0c04032e */
if(!s->budget--) { s->failed_pc=0x0c04032eu; return 0; }
r[0]+=r[3];
goto P_0c040330;
P_0c040330: /* original 1f02, guest PC 0x0c040330 */
if(!s->budget--) { s->failed_pc=0x0c040330u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c040332;
P_0c040332: /* original 52f1, guest PC 0x0c040332 */
if(!s->budget--) { s->failed_pc=0x0c040332u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c040334;
P_0c040334: /* original 6323, guest PC 0x0c040334 */
if(!s->budget--) { s->failed_pc=0x0c040334u; return 0; }
r[3]=r[2];
goto P_0c040336;
P_0c040336: /* original 4200, guest PC 0x0c040336 */
if(!s->budget--) { s->failed_pc=0x0c040336u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c040338;
P_0c040338: /* original 323c, guest PC 0x0c040338 */
if(!s->budget--) { s->failed_pc=0x0c040338u; return 0; }
r[2]+=r[3];
goto P_0c04033a;
P_0c04033a: /* original 4208, guest PC 0x0c04033a */
if(!s->budget--) { s->failed_pc=0x0c04033au; return 0; }
r[2]<<=2;
goto P_0c04033c;
P_0c04033c: /* original 622e, guest PC 0x0c04033c */
if(!s->budget--) { s->failed_pc=0x0c04033cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c04033e;
P_0c04033e: /* original d00d, guest PC 0x0c04033e */
if(!s->budget--) { s->failed_pc=0x0c04033eu; return 0; }
r[0]=read(ram,0x0c040374u,4);
goto P_0c040340;
P_0c040340: /* original 53f4, guest PC 0x0c040340 */
if(!s->budget--) { s->failed_pc=0x0c040340u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c040342;
P_0c040342: /* original 012e, guest PC 0x0c040342 */
if(!s->budget--) { s->failed_pc=0x0c040342u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c040344;
P_0c040344: /* original 313c, guest PC 0x0c040344 */
if(!s->budget--) { s->failed_pc=0x0c040344u; return 0; }
r[1]+=r[3];
goto P_0c040346;
P_0c040346: /* original 0216, guest PC 0x0c040346 */
if(!s->budget--) { s->failed_pc=0x0c040346u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c040348;
P_0c040348: /* original 52f1, guest PC 0x0c040348 */
if(!s->budget--) { s->failed_pc=0x0c040348u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04034a;
P_0c04034a: /* original 7201, guest PC 0x0c04034a */
if(!s->budget--) { s->failed_pc=0x0c04034au; return 0; }
r[2]+=0x00000001u;
goto P_0c04034c;
P_0c04034c: /* original 1f21, guest PC 0x0c04034c */
if(!s->budget--) { s->failed_pc=0x0c04034cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c04034e;
P_0c04034e: /* original e308, guest PC 0x0c04034e */
if(!s->budget--) { s->failed_pc=0x0c04034eu; return 0; }
r[3]=0x00000008u;
goto P_0c040350;
P_0c040350: /* original 51f1, guest PC 0x0c040350 */
if(!s->budget--) { s->failed_pc=0x0c040350u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c040352;
P_0c040352: /* original 3133, guest PC 0x0c040352 */
if(!s->budget--) { s->failed_pc=0x0c040352u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c040354;
P_0c040354: /* original 8bd8, guest PC 0x0c040354 */
if(!s->budget--) { s->failed_pc=0x0c040354u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040308; }
goto P_0c040356;
P_0c040356: /* original 53f3, guest PC 0x0c040356 */
if(!s->budget--) { s->failed_pc=0x0c040356u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c040358;
P_0c040358: /* original 52f2, guest PC 0x0c040358 */
if(!s->budget--) { s->failed_pc=0x0c040358u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04035a;
P_0c04035a: /* original 2322, guest PC 0x0c04035a */
if(!s->budget--) { s->failed_pc=0x0c04035au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c04035c;
P_0c04035c: /* original 60f2, guest PC 0x0c04035c */
if(!s->budget--) { s->failed_pc=0x0c04035cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04035e;
P_0c04035e: /* original 7f1c, guest PC 0x0c04035e */
if(!s->budget--) { s->failed_pc=0x0c04035eu; return 0; }
r[15]+=0x0000001cu;
goto P_0c040360;
P_0c040360: /* original 000b, guest PC 0x0c040360 */
if(!s->budget--) { s->failed_pc=0x0c040360u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040362: /* original 0009, guest PC 0x0c040362 */
if(!s->budget--) { s->failed_pc=0x0c040362u; return 0; }
return vf3_matrix_family(0x0c040364u,s,ram);
P_0c0406b8: /* original 4f22, guest PC 0x0c0406b8 */
if(!s->budget--) { s->failed_pc=0x0c0406b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0406ba;
P_0c0406ba: /* original 7fe4, guest PC 0x0c0406ba */
if(!s->budget--) { s->failed_pc=0x0c0406bau; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0406bc;
P_0c0406bc: /* original 1f46, guest PC 0x0c0406bc */
if(!s->budget--) { s->failed_pc=0x0c0406bcu; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c0406be;
P_0c0406be: /* original 1f55, guest PC 0x0c0406be */
if(!s->budget--) { s->failed_pc=0x0c0406beu; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c0406c0;
P_0c0406c0: /* original 55f5, guest PC 0x0c0406c0 */
if(!s->budget--) { s->failed_pc=0x0c0406c0u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0406c2;
P_0c0406c2: /* original 54f6, guest PC 0x0c0406c2 */
if(!s->budget--) { s->failed_pc=0x0c0406c2u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0406c4;
P_0c0406c4: /* original bd46, guest PC 0x0c0406c4 */
if(!s->budget--) { s->failed_pc=0x0c0406c4u; return 0; }
target=0x0c040154u; r[16]=0x0c0406c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0406c8u) { target=s->pc; goto dispatch; }
goto P_0c0406c8;
P_0c0406c6: /* original 0009, guest PC 0x0c0406c6 */
if(!s->budget--) { s->failed_pc=0x0c0406c6u; return 0; }
goto P_0c0406c8;
P_0c0406c8: /* original 1f01, guest PC 0x0c0406c8 */
if(!s->budget--) { s->failed_pc=0x0c0406c8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0406ca;
P_0c0406ca: /* original 2008, guest PC 0x0c0406ca */
if(!s->budget--) { s->failed_pc=0x0c0406cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0406cc;
P_0c0406cc: /* original 8901, guest PC 0x0c0406cc */
if(!s->budget--) { s->failed_pc=0x0c0406ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0406d2; }
goto P_0c0406ce;
P_0c0406ce: /* original a075, guest PC 0x0c0406ce */
if(!s->budget--) { s->failed_pc=0x0c0406ceu; return 0; }
goto P_0c0407bc;
P_0c0406d0: /* original 0009, guest PC 0x0c0406d0 */
if(!s->budget--) { s->failed_pc=0x0c0406d0u; return 0; }
goto P_0c0406d2;
P_0c0406d2: /* original 52f6, guest PC 0x0c0406d2 */
if(!s->budget--) { s->failed_pc=0x0c0406d2u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0406d4;
P_0c0406d4: /* original 5322, guest PC 0x0c0406d4 */
if(!s->budget--) { s->failed_pc=0x0c0406d4u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c0406d6;
P_0c0406d6: /* original 1f33, guest PC 0x0c0406d6 */
if(!s->budget--) { s->failed_pc=0x0c0406d6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0406d8;
P_0c0406d8: /* original 5121, guest PC 0x0c0406d8 */
if(!s->budget--) { s->failed_pc=0x0c0406d8u; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c0406da;
P_0c0406da: /* original 1f12, guest PC 0x0c0406da */
if(!s->budget--) { s->failed_pc=0x0c0406dau; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0406dc;
P_0c0406dc: /* original 67f3, guest PC 0x0c0406dc */
if(!s->budget--) { s->failed_pc=0x0c0406dcu; return 0; }
r[7]=r[15];
goto P_0c0406de;
P_0c0406de: /* original 56f3, guest PC 0x0c0406de */
if(!s->budget--) { s->failed_pc=0x0c0406deu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0406e0;
P_0c0406e0: /* original 55f2, guest PC 0x0c0406e0 */
if(!s->budget--) { s->failed_pc=0x0c0406e0u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0406e2;
P_0c0406e2: /* original 54f5, guest PC 0x0c0406e2 */
if(!s->budget--) { s->failed_pc=0x0c0406e2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0406e4;
P_0c0406e4: /* original bd9d, guest PC 0x0c0406e4 */
if(!s->budget--) { s->failed_pc=0x0c0406e4u; return 0; }
target=0x0c040222u; r[16]=0x0c0406e8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0406e8u) { target=s->pc; goto dispatch; }
goto P_0c0406e8;
P_0c0406e6: /* original 0009, guest PC 0x0c0406e6 */
if(!s->budget--) { s->failed_pc=0x0c0406e6u; return 0; }
goto P_0c0406e8;
P_0c0406e8: /* original 1f04, guest PC 0x0c0406e8 */
if(!s->budget--) { s->failed_pc=0x0c0406e8u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c0406ea;
P_0c0406ea: /* original ee00, guest PC 0x0c0406ea */
if(!s->budget--) { s->failed_pc=0x0c0406eau; return 0; }
r[14]=0x00000000u;
goto P_0c0406ec;
P_0c0406ec: /* original a008, guest PC 0x0c0406ec */
if(!s->budget--) { s->failed_pc=0x0c0406ecu; return 0; }
goto P_0c040700;
P_0c0406ee: /* original 0009, guest PC 0x0c0406ee */
if(!s->budget--) { s->failed_pc=0x0c0406eeu; return 0; }
goto P_0c0406f0;
P_0c0406f0: /* original 940c, guest PC 0x0c0406f0 */
if(!s->budget--) { s->failed_pc=0x0c0406f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04070cu,2);
goto P_0c0406f2;
P_0c0406f2: /* original b414, guest PC 0x0c0406f2 */
if(!s->budget--) { s->failed_pc=0x0c0406f2u; return 0; }
target=0x0c040f1eu; r[16]=0x0c0406f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0406f6u) { target=s->pc; goto dispatch; }
goto P_0c0406f6;
P_0c0406f4: /* original 0009, guest PC 0x0c0406f4 */
if(!s->budget--) { s->failed_pc=0x0c0406f4u; return 0; }
goto P_0c0406f6;
P_0c0406f6: /* original 2008, guest PC 0x0c0406f6 */
if(!s->budget--) { s->failed_pc=0x0c0406f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0406f8;
P_0c0406f8: /* original 8b01, guest PC 0x0c0406f8 */
if(!s->budget--) { s->failed_pc=0x0c0406f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0406fe; }
goto P_0c0406fa;
P_0c0406fa: /* original a00b, guest PC 0x0c0406fa */
if(!s->budget--) { s->failed_pc=0x0c0406fau; return 0; }
goto P_0c040714;
P_0c0406fc: /* original 0009, guest PC 0x0c0406fc */
if(!s->budget--) { s->failed_pc=0x0c0406fcu; return 0; }
goto P_0c0406fe;
P_0c0406fe: /* original 7e01, guest PC 0x0c0406fe */
if(!s->budget--) { s->failed_pc=0x0c0406feu; return 0; }
r[14]+=0x00000001u;
goto P_0c040700;
P_0c040700: /* original d303, guest PC 0x0c040700 */
if(!s->budget--) { s->failed_pc=0x0c040700u; return 0; }
r[3]=read(ram,0x0c040710u,4);
goto P_0c040702;
P_0c040702: /* original 3e33, guest PC 0x0c040702 */
if(!s->budget--) { s->failed_pc=0x0c040702u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c040704;
P_0c040704: /* original 8bf4, guest PC 0x0c040704 */
if(!s->budget--) { s->failed_pc=0x0c040704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0406f0; }
goto P_0c040706;
P_0c040706: /* original 9002, guest PC 0x0c040706 */
if(!s->budget--) { s->failed_pc=0x0c040706u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04070eu,2);
goto P_0c040708;
P_0c040708: /* original a058, guest PC 0x0c040708 */
if(!s->budget--) { s->failed_pc=0x0c040708u; return 0; }
goto P_0c0407bc;
P_0c04070a: /* original 0009, guest PC 0x0c04070a */
if(!s->budget--) { s->failed_pc=0x0c04070au; return 0; }
return vf3_matrix_family(0x0c04070cu,s,ram);
P_0c040714: /* original ee00, guest PC 0x0c040714 */
if(!s->budget--) { s->failed_pc=0x0c040714u; return 0; }
r[14]=0x00000000u;
goto P_0c040716;
P_0c040716: /* original a007, guest PC 0x0c040716 */
if(!s->budget--) { s->failed_pc=0x0c040716u; return 0; }
goto P_0c040728;
P_0c040718: /* original 0009, guest PC 0x0c040718 */
if(!s->budget--) { s->failed_pc=0x0c040718u; return 0; }
goto P_0c04071a;
P_0c04071a: /* original d322, guest PC 0x0c04071a */
if(!s->budget--) { s->failed_pc=0x0c04071au; return 0; }
r[3]=read(ram,0x0c0407a4u,4);
goto P_0c04071c;
P_0c04071c: /* original 6232, guest PC 0x0c04071c */
if(!s->budget--) { s->failed_pc=0x0c04071cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04071e;
P_0c04071e: /* original 2228, guest PC 0x0c04071e */
if(!s->budget--) { s->failed_pc=0x0c04071eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c040720;
P_0c040720: /* original 8901, guest PC 0x0c040720 */
if(!s->budget--) { s->failed_pc=0x0c040720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040726; }
goto P_0c040722;
P_0c040722: /* original a007, guest PC 0x0c040722 */
if(!s->budget--) { s->failed_pc=0x0c040722u; return 0; }
goto P_0c040734;
P_0c040724: /* original 0009, guest PC 0x0c040724 */
if(!s->budget--) { s->failed_pc=0x0c040724u; return 0; }
goto P_0c040726;
P_0c040726: /* original 7e01, guest PC 0x0c040726 */
if(!s->budget--) { s->failed_pc=0x0c040726u; return 0; }
r[14]+=0x00000001u;
goto P_0c040728;
P_0c040728: /* original d31f, guest PC 0x0c040728 */
if(!s->budget--) { s->failed_pc=0x0c040728u; return 0; }
r[3]=read(ram,0x0c0407a8u,4);
goto P_0c04072a;
P_0c04072a: /* original 3e33, guest PC 0x0c04072a */
if(!s->budget--) { s->failed_pc=0x0c04072au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c04072c;
P_0c04072c: /* original 8bf5, guest PC 0x0c04072c */
if(!s->budget--) { s->failed_pc=0x0c04072cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04071a; }
goto P_0c04072e;
P_0c04072e: /* original 9037, guest PC 0x0c04072e */
if(!s->budget--) { s->failed_pc=0x0c04072eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0407a0u,2);
goto P_0c040730;
P_0c040730: /* original a044, guest PC 0x0c040730 */
if(!s->budget--) { s->failed_pc=0x0c040730u; return 0; }
goto P_0c0407bc;
P_0c040732: /* original 0009, guest PC 0x0c040732 */
if(!s->budget--) { s->failed_pc=0x0c040732u; return 0; }
goto P_0c040734;
P_0c040734: /* original 63f2, guest PC 0x0c040734 */
if(!s->budget--) { s->failed_pc=0x0c040734u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040736;
P_0c040736: /* original 2338, guest PC 0x0c040736 */
if(!s->budget--) { s->failed_pc=0x0c040736u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c040738;
P_0c040738: /* original 8911, guest PC 0x0c040738 */
if(!s->budget--) { s->failed_pc=0x0c040738u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04075e; }
goto P_0c04073a;
P_0c04073a: /* original 66f2, guest PC 0x0c04073a */
if(!s->budget--) { s->failed_pc=0x0c04073au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04073c;
P_0c04073c: /* original 53f3, guest PC 0x0c04073c */
if(!s->budget--) { s->failed_pc=0x0c04073cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c04073e;
P_0c04073e: /* original 55f4, guest PC 0x0c04073e */
if(!s->budget--) { s->failed_pc=0x0c04073eu; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c040740;
P_0c040740: /* original 353c, guest PC 0x0c040740 */
if(!s->budget--) { s->failed_pc=0x0c040740u; return 0; }
r[5]+=r[3];
goto P_0c040742;
P_0c040742: /* original 54f4, guest PC 0x0c040742 */
if(!s->budget--) { s->failed_pc=0x0c040742u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c040744;
P_0c040744: /* original bcbc, guest PC 0x0c040744 */
if(!s->budget--) { s->failed_pc=0x0c040744u; return 0; }
target=0x0c0400c0u; r[16]=0x0c040748u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040748u) { target=s->pc; goto dispatch; }
goto P_0c040748;
P_0c040746: /* original 0009, guest PC 0x0c040746 */
if(!s->budget--) { s->failed_pc=0x0c040746u; return 0; }
goto P_0c040748;
P_0c040748: /* original 1f01, guest PC 0x0c040748 */
if(!s->budget--) { s->failed_pc=0x0c040748u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c04074a;
P_0c04074a: /* original 2008, guest PC 0x0c04074a */
if(!s->budget--) { s->failed_pc=0x0c04074au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04074c;
P_0c04074c: /* original 8901, guest PC 0x0c04074c */
if(!s->budget--) { s->failed_pc=0x0c04074cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040752; }
goto P_0c04074e;
P_0c04074e: /* original a035, guest PC 0x0c04074e */
if(!s->budget--) { s->failed_pc=0x0c04074eu; return 0; }
goto P_0c0407bc;
P_0c040750: /* original 0009, guest PC 0x0c040750 */
if(!s->budget--) { s->failed_pc=0x0c040750u; return 0; }
goto P_0c040752;
P_0c040752: /* original a000, guest PC 0x0c040752 */
if(!s->budget--) { s->failed_pc=0x0c040752u; return 0; }
goto P_0c040756;
P_0c040754: /* original 0009, guest PC 0x0c040754 */
if(!s->budget--) { s->failed_pc=0x0c040754u; return 0; }
goto P_0c040756;
P_0c040756: /* original bcf1, guest PC 0x0c040756 */
if(!s->budget--) { s->failed_pc=0x0c040756u; return 0; }
target=0x0c04013cu; r[16]=0x0c04075au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04075au) { target=s->pc; goto dispatch; }
goto P_0c04075a;
P_0c040758: /* original 0009, guest PC 0x0c040758 */
if(!s->budget--) { s->failed_pc=0x0c040758u; return 0; }
goto P_0c04075a;
P_0c04075a: /* original 2008, guest PC 0x0c04075a */
if(!s->budget--) { s->failed_pc=0x0c04075au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04075c;
P_0c04075c: /* original 8bfb, guest PC 0x0c04075c */
if(!s->budget--) { s->failed_pc=0x0c04075cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040756; }
goto P_0c04075e;
P_0c04075e: /* original 5df6, guest PC 0x0c04075e */
if(!s->budget--) { s->failed_pc=0x0c04075eu; return 0; }
r[13]=read(ram,r[15]+24,4);
goto P_0c040760;
P_0c040760: /* original 5cf4, guest PC 0x0c040760 */
if(!s->budget--) { s->failed_pc=0x0c040760u; return 0; }
r[12]=read(ram,r[15]+16,4);
goto P_0c040762;
P_0c040762: /* original ee00, guest PC 0x0c040762 */
if(!s->budget--) { s->failed_pc=0x0c040762u; return 0; }
r[14]=0x00000000u;
goto P_0c040764;
P_0c040764: /* original a005, guest PC 0x0c040764 */
if(!s->budget--) { s->failed_pc=0x0c040764u; return 0; }
goto P_0c040772;
P_0c040766: /* original 0009, guest PC 0x0c040766 */
if(!s->budget--) { s->failed_pc=0x0c040766u; return 0; }
goto P_0c040768;
P_0c040768: /* original 62c3, guest PC 0x0c040768 */
if(!s->budget--) { s->failed_pc=0x0c040768u; return 0; }
r[2]=r[12];
goto P_0c04076a;
P_0c04076a: /* original 7c04, guest PC 0x0c04076a */
if(!s->budget--) { s->failed_pc=0x0c04076au; return 0; }
r[12]+=0x00000004u;
goto P_0c04076c;
P_0c04076c: /* original 63d6, guest PC 0x0c04076c */
if(!s->budget--) { s->failed_pc=0x0c04076cu; return 0; }
tmp=read(ram,r[13],4);
r[13]+=4;
r[3]=tmp;
goto P_0c04076e;
P_0c04076e: /* original 2232, guest PC 0x0c04076e */
if(!s->budget--) { s->failed_pc=0x0c04076eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040770;
P_0c040770: /* original 7e01, guest PC 0x0c040770 */
if(!s->budget--) { s->failed_pc=0x0c040770u; return 0; }
r[14]+=0x00000001u;
goto P_0c040772;
P_0c040772: /* original 52f3, guest PC 0x0c040772 */
if(!s->budget--) { s->failed_pc=0x0c040772u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040774;
P_0c040774: /* original 4209, guest PC 0x0c040774 */
if(!s->budget--) { s->failed_pc=0x0c040774u; return 0; }
r[2]>>=2;
goto P_0c040776;
P_0c040776: /* original 3e22, guest PC 0x0c040776 */
if(!s->budget--) { s->failed_pc=0x0c040776u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c040778;
P_0c040778: /* original 8bf6, guest PC 0x0c040778 */
if(!s->budget--) { s->failed_pc=0x0c040778u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040768; }
goto P_0c04077a;
P_0c04077a: /* original e201, guest PC 0x0c04077a */
if(!s->budget--) { s->failed_pc=0x0c04077au; return 0; }
r[2]=0x00000001u;
goto P_0c04077c;
P_0c04077c: /* original d30b, guest PC 0x0c04077c */
if(!s->budget--) { s->failed_pc=0x0c04077cu; return 0; }
r[3]=read(ram,0x0c0407acu,4);
goto P_0c04077e;
P_0c04077e: /* original 2322, guest PC 0x0c04077e */
if(!s->budget--) { s->failed_pc=0x0c04077eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040780;
P_0c040780: /* original ee00, guest PC 0x0c040780 */
if(!s->budget--) { s->failed_pc=0x0c040780u; return 0; }
r[14]=0x00000000u;
goto P_0c040782;
P_0c040782: /* original a007, guest PC 0x0c040782 */
if(!s->budget--) { s->failed_pc=0x0c040782u; return 0; }
goto P_0c040794;
P_0c040784: /* original 0009, guest PC 0x0c040784 */
if(!s->budget--) { s->failed_pc=0x0c040784u; return 0; }
goto P_0c040786;
P_0c040786: /* original d207, guest PC 0x0c040786 */
if(!s->budget--) { s->failed_pc=0x0c040786u; return 0; }
r[2]=read(ram,0x0c0407a4u,4);
goto P_0c040788;
P_0c040788: /* original 6322, guest PC 0x0c040788 */
if(!s->budget--) { s->failed_pc=0x0c040788u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04078a;
P_0c04078a: /* original 2338, guest PC 0x0c04078a */
if(!s->budget--) { s->failed_pc=0x0c04078au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04078c;
P_0c04078c: /* original 8b01, guest PC 0x0c04078c */
if(!s->budget--) { s->failed_pc=0x0c04078cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040792; }
goto P_0c04078e;
P_0c04078e: /* original a00f, guest PC 0x0c04078e */
if(!s->budget--) { s->failed_pc=0x0c04078eu; return 0; }
goto P_0c0407b0;
P_0c040790: /* original 0009, guest PC 0x0c040790 */
if(!s->budget--) { s->failed_pc=0x0c040790u; return 0; }
goto P_0c040792;
P_0c040792: /* original 7e01, guest PC 0x0c040792 */
if(!s->budget--) { s->failed_pc=0x0c040792u; return 0; }
r[14]+=0x00000001u;
goto P_0c040794;
P_0c040794: /* original d204, guest PC 0x0c040794 */
if(!s->budget--) { s->failed_pc=0x0c040794u; return 0; }
r[2]=read(ram,0x0c0407a8u,4);
goto P_0c040796;
P_0c040796: /* original 3e23, guest PC 0x0c040796 */
if(!s->budget--) { s->failed_pc=0x0c040796u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c040798;
P_0c040798: /* original 8bf5, guest PC 0x0c040798 */
if(!s->budget--) { s->failed_pc=0x0c040798u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040786; }
goto P_0c04079a;
P_0c04079a: /* original 9001, guest PC 0x0c04079a */
if(!s->budget--) { s->failed_pc=0x0c04079au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0407a0u,2);
goto P_0c04079c;
P_0c04079c: /* original a00e, guest PC 0x0c04079c */
if(!s->budget--) { s->failed_pc=0x0c04079cu; return 0; }
goto P_0c0407bc;
P_0c04079e: /* original 0009, guest PC 0x0c04079e */
if(!s->budget--) { s->failed_pc=0x0c04079eu; return 0; }
return vf3_matrix_family(0x0c0407a0u,s,ram);
P_0c0407b0: /* original e200, guest PC 0x0c0407b0 */
if(!s->budget--) { s->failed_pc=0x0c0407b0u; return 0; }
r[2]=0x00000000u;
goto P_0c0407b2;
P_0c0407b2: /* original d30e, guest PC 0x0c0407b2 */
if(!s->budget--) { s->failed_pc=0x0c0407b2u; return 0; }
r[3]=read(ram,0x0c0407ecu,4);
goto P_0c0407b4;
P_0c0407b4: /* original 2322, guest PC 0x0c0407b4 */
if(!s->budget--) { s->failed_pc=0x0c0407b4u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0407b6;
P_0c0407b6: /* original e000, guest PC 0x0c0407b6 */
if(!s->budget--) { s->failed_pc=0x0c0407b6u; return 0; }
r[0]=0x00000000u;
goto P_0c0407b8;
P_0c0407b8: /* original a000, guest PC 0x0c0407b8 */
if(!s->budget--) { s->failed_pc=0x0c0407b8u; return 0; }
goto P_0c0407bc;
P_0c0407ba: /* original 0009, guest PC 0x0c0407ba */
if(!s->budget--) { s->failed_pc=0x0c0407bau; return 0; }
goto P_0c0407bc;
P_0c0407bc: /* original 7f1c, guest PC 0x0c0407bc */
if(!s->budget--) { s->failed_pc=0x0c0407bcu; return 0; }
r[15]+=0x0000001cu;
goto P_0c0407be;
P_0c0407be: /* original 4f26, guest PC 0x0c0407be */
if(!s->budget--) { s->failed_pc=0x0c0407beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0407c0;
P_0c0407c0: /* original 6cf6, guest PC 0x0c0407c0 */
if(!s->budget--) { s->failed_pc=0x0c0407c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0407c2;
P_0c0407c2: /* original 6df6, guest PC 0x0c0407c2 */
if(!s->budget--) { s->failed_pc=0x0c0407c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0407c4;
P_0c0407c4: /* original 6ef6, guest PC 0x0c0407c4 */
if(!s->budget--) { s->failed_pc=0x0c0407c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0407c6;
P_0c0407c6: /* original 000b, guest PC 0x0c0407c6 */
if(!s->budget--) { s->failed_pc=0x0c0407c6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0407c8: /* original 0009, guest PC 0x0c0407c8 */
if(!s->budget--) { s->failed_pc=0x0c0407c8u; return 0; }
return vf3_matrix_family(0x0c0407cau,s,ram);
P_0c040b7e: /* original 4f22, guest PC 0x0c040b7e */
if(!s->budget--) { s->failed_pc=0x0c040b7eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c040b80;
P_0c040b80: /* original 7ff0, guest PC 0x0c040b80 */
if(!s->budget--) { s->failed_pc=0x0c040b80u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c040b82;
P_0c040b82: /* original 63f3, guest PC 0x0c040b82 */
if(!s->budget--) { s->failed_pc=0x0c040b82u; return 0; }
r[3]=r[15];
goto P_0c040b84;
P_0c040b84: /* original 730e, guest PC 0x0c040b84 */
if(!s->budget--) { s->failed_pc=0x0c040b84u; return 0; }
r[3]+=0x0000000eu;
goto P_0c040b86;
P_0c040b86: /* original 2341, guest PC 0x0c040b86 */
if(!s->budget--) { s->failed_pc=0x0c040b86u; return 0; }
write(ram,r[3],r[4],2);
goto P_0c040b88;
P_0c040b88: /* original 1f52, guest PC 0x0c040b88 */
if(!s->budget--) { s->failed_pc=0x0c040b88u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c040b8a;
P_0c040b8a: /* original 1f61, guest PC 0x0c040b8a */
if(!s->budget--) { s->failed_pc=0x0c040b8au; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c040b8c;
P_0c040b8c: /* original 85f7, guest PC 0x0c040b8c */
if(!s->budget--) { s->failed_pc=0x0c040b8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+14,2);
goto P_0c040b8e;
P_0c040b8e: /* original 600d, guest PC 0x0c040b8e */
if(!s->budget--) { s->failed_pc=0x0c040b8eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c040b90;
P_0c040b90: /* original ee0f, guest PC 0x0c040b90 */
if(!s->budget--) { s->failed_pc=0x0c040b90u; return 0; }
r[14]=0x0000000fu;
goto P_0c040b92;
P_0c040b92: /* original 2e09, guest PC 0x0c040b92 */
if(!s->budget--) { s->failed_pc=0x0c040b92u; return 0; }
r[14]&=r[0];
goto P_0c040b94;
P_0c040b94: /* original 4e28, guest PC 0x0c040b94 */
if(!s->budget--) { s->failed_pc=0x0c040b94u; return 0; }
r[14]<<=16;
goto P_0c040b96;
P_0c040b96: /* original 4e18, guest PC 0x0c040b96 */
if(!s->budget--) { s->failed_pc=0x0c040b96u; return 0; }
r[14]<<=8;
goto P_0c040b98;
P_0c040b98: /* original 53f2, guest PC 0x0c040b98 */
if(!s->budget--) { s->failed_pc=0x0c040b98u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c040b9a;
P_0c040b9a: /* original 3e3c, guest PC 0x0c040b9a */
if(!s->budget--) { s->failed_pc=0x0c040b9au; return 0; }
r[14]+=r[3];
goto P_0c040b9c;
P_0c040b9c: /* original d21b, guest PC 0x0c040b9c */
if(!s->budget--) { s->failed_pc=0x0c040b9cu; return 0; }
r[2]=read(ram,0x0c040c0cu,4);
goto P_0c040b9e;
P_0c040b9e: /* original 2328, guest PC 0x0c040b9e */
if(!s->budget--) { s->failed_pc=0x0c040b9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c040ba0;
P_0c040ba0: /* original 8936, guest PC 0x0c040ba0 */
if(!s->budget--) { s->failed_pc=0x0c040ba0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040c10; }
goto P_0c040ba2;
P_0c040ba2: /* original 50f2, guest PC 0x0c040ba2 */
if(!s->budget--) { s->failed_pc=0x0c040ba2u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c040ba4;
P_0c040ba4: /* original 9128, guest PC 0x0c040ba4 */
if(!s->budget--) { s->failed_pc=0x0c040ba4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040bf8u,2);
goto P_0c040ba6;
P_0c040ba6: /* original 3010, guest PC 0x0c040ba6 */
if(!s->budget--) { s->failed_pc=0x0c040ba6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040ba8;
P_0c040ba8: /* original 8919, guest PC 0x0c040ba8 */
if(!s->budget--) { s->failed_pc=0x0c040ba8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040baa;
P_0c040baa: /* original 9126, guest PC 0x0c040baa */
if(!s->budget--) { s->failed_pc=0x0c040baau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040bfau,2);
goto P_0c040bac;
P_0c040bac: /* original 3010, guest PC 0x0c040bac */
if(!s->budget--) { s->failed_pc=0x0c040bacu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bae;
P_0c040bae: /* original 8916, guest PC 0x0c040bae */
if(!s->budget--) { s->failed_pc=0x0c040baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040bb0;
P_0c040bb0: /* original 9124, guest PC 0x0c040bb0 */
if(!s->budget--) { s->failed_pc=0x0c040bb0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040bfcu,2);
goto P_0c040bb2;
P_0c040bb2: /* original 3010, guest PC 0x0c040bb2 */
if(!s->budget--) { s->failed_pc=0x0c040bb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bb4;
P_0c040bb4: /* original 8919, guest PC 0x0c040bb4 */
if(!s->budget--) { s->failed_pc=0x0c040bb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bea; }
goto P_0c040bb6;
P_0c040bb6: /* original 9122, guest PC 0x0c040bb6 */
if(!s->budget--) { s->failed_pc=0x0c040bb6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040bfeu,2);
goto P_0c040bb8;
P_0c040bb8: /* original 3010, guest PC 0x0c040bb8 */
if(!s->budget--) { s->failed_pc=0x0c040bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bba;
P_0c040bba: /* original 8916, guest PC 0x0c040bba */
if(!s->budget--) { s->failed_pc=0x0c040bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bea; }
goto P_0c040bbc;
P_0c040bbc: /* original 9120, guest PC 0x0c040bbc */
if(!s->budget--) { s->failed_pc=0x0c040bbcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c00u,2);
goto P_0c040bbe;
P_0c040bbe: /* original 3010, guest PC 0x0c040bbe */
if(!s->budget--) { s->failed_pc=0x0c040bbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bc0;
P_0c040bc0: /* original 8913, guest PC 0x0c040bc0 */
if(!s->budget--) { s->failed_pc=0x0c040bc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bea; }
goto P_0c040bc2;
P_0c040bc2: /* original 911e, guest PC 0x0c040bc2 */
if(!s->budget--) { s->failed_pc=0x0c040bc2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c02u,2);
goto P_0c040bc4;
P_0c040bc4: /* original 3010, guest PC 0x0c040bc4 */
if(!s->budget--) { s->failed_pc=0x0c040bc4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bc6;
P_0c040bc6: /* original 890a, guest PC 0x0c040bc6 */
if(!s->budget--) { s->failed_pc=0x0c040bc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040bc8;
P_0c040bc8: /* original 911c, guest PC 0x0c040bc8 */
if(!s->budget--) { s->failed_pc=0x0c040bc8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c04u,2);
goto P_0c040bca;
P_0c040bca: /* original 3010, guest PC 0x0c040bca */
if(!s->budget--) { s->failed_pc=0x0c040bcau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bcc;
P_0c040bcc: /* original 8907, guest PC 0x0c040bcc */
if(!s->budget--) { s->failed_pc=0x0c040bccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040bce;
P_0c040bce: /* original 911a, guest PC 0x0c040bce */
if(!s->budget--) { s->failed_pc=0x0c040bceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c06u,2);
goto P_0c040bd0;
P_0c040bd0: /* original 3010, guest PC 0x0c040bd0 */
if(!s->budget--) { s->failed_pc=0x0c040bd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bd2;
P_0c040bd2: /* original 8904, guest PC 0x0c040bd2 */
if(!s->budget--) { s->failed_pc=0x0c040bd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bde; }
goto P_0c040bd4;
P_0c040bd4: /* original 9118, guest PC 0x0c040bd4 */
if(!s->budget--) { s->failed_pc=0x0c040bd4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c08u,2);
goto P_0c040bd6;
P_0c040bd6: /* original 3010, guest PC 0x0c040bd6 */
if(!s->budget--) { s->failed_pc=0x0c040bd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c040bd8;
P_0c040bd8: /* original 8907, guest PC 0x0c040bd8 */
if(!s->budget--) { s->failed_pc=0x0c040bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040bea; }
goto P_0c040bda;
P_0c040bda: /* original a019, guest PC 0x0c040bda */
if(!s->budget--) { s->failed_pc=0x0c040bdau; return 0; }
goto P_0c040c10;
P_0c040bdc: /* original 0009, guest PC 0x0c040bdc */
if(!s->budget--) { s->failed_pc=0x0c040bdcu; return 0; }
goto P_0c040bde;
P_0c040bde: /* original 50f1, guest PC 0x0c040bde */
if(!s->budget--) { s->failed_pc=0x0c040bdeu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c040be0;
P_0c040be0: /* original c97f, guest PC 0x0c040be0 */
if(!s->budget--) { s->failed_pc=0x0c040be0u; return 0; }
r[0]&=127u;
goto P_0c040be2;
P_0c040be2: /* original 4028, guest PC 0x0c040be2 */
if(!s->budget--) { s->failed_pc=0x0c040be2u; return 0; }
r[0]<<=16;
goto P_0c040be4;
P_0c040be4: /* original 3e0c, guest PC 0x0c040be4 */
if(!s->budget--) { s->failed_pc=0x0c040be4u; return 0; }
r[14]+=r[0];
goto P_0c040be6;
P_0c040be6: /* original a013, guest PC 0x0c040be6 */
if(!s->budget--) { s->failed_pc=0x0c040be6u; return 0; }
goto P_0c040c10;
P_0c040be8: /* original 0009, guest PC 0x0c040be8 */
if(!s->budget--) { s->failed_pc=0x0c040be8u; return 0; }
goto P_0c040bea;
P_0c040bea: /* original 50f1, guest PC 0x0c040bea */
if(!s->budget--) { s->failed_pc=0x0c040beau; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c040bec;
P_0c040bec: /* original 7040, guest PC 0x0c040bec */
if(!s->budget--) { s->failed_pc=0x0c040becu; return 0; }
r[0]+=0x00000040u;
goto P_0c040bee;
P_0c040bee: /* original c97f, guest PC 0x0c040bee */
if(!s->budget--) { s->failed_pc=0x0c040beeu; return 0; }
r[0]&=127u;
goto P_0c040bf0;
P_0c040bf0: /* original 4028, guest PC 0x0c040bf0 */
if(!s->budget--) { s->failed_pc=0x0c040bf0u; return 0; }
r[0]<<=16;
goto P_0c040bf2;
P_0c040bf2: /* original 3e0c, guest PC 0x0c040bf2 */
if(!s->budget--) { s->failed_pc=0x0c040bf2u; return 0; }
r[14]+=r[0];
goto P_0c040bf4;
P_0c040bf4: /* original a00c, guest PC 0x0c040bf4 */
if(!s->budget--) { s->failed_pc=0x0c040bf4u; return 0; }
goto P_0c040c10;
P_0c040bf6: /* original 0009, guest PC 0x0c040bf6 */
if(!s->budget--) { s->failed_pc=0x0c040bf6u; return 0; }
return vf3_matrix_family(0x0c040bf8u,s,ram);
P_0c040c10: /* original d21c, guest PC 0x0c040c10 */
if(!s->budget--) { s->failed_pc=0x0c040c10u; return 0; }
r[2]=read(ram,0x0c040c84u,4);
goto P_0c040c12;
P_0c040c12: /* original 53f2, guest PC 0x0c040c12 */
if(!s->budget--) { s->failed_pc=0x0c040c12u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c040c14;
P_0c040c14: /* original 3320, guest PC 0x0c040c14 */
if(!s->budget--) { s->failed_pc=0x0c040c14u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c040c16;
P_0c040c16: /* original 8b27, guest PC 0x0c040c16 */
if(!s->budget--) { s->failed_pc=0x0c040c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040c68; }
goto P_0c040c18;
P_0c040c18: /* original e301, guest PC 0x0c040c18 */
if(!s->budget--) { s->failed_pc=0x0c040c18u; return 0; }
r[3]=0x00000001u;
goto P_0c040c1a;
P_0c040c1a: /* original 2f32, guest PC 0x0c040c1a */
if(!s->budget--) { s->failed_pc=0x0c040c1au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c040c1c;
P_0c040c1c: /* original a01b, guest PC 0x0c040c1c */
if(!s->budget--) { s->failed_pc=0x0c040c1cu; return 0; }
goto P_0c040c56;
P_0c040c1e: /* original 0009, guest PC 0x0c040c1e */
if(!s->budget--) { s->failed_pc=0x0c040c1eu; return 0; }
goto P_0c040c20;
P_0c040c20: /* original 60f2, guest PC 0x0c040c20 */
if(!s->budget--) { s->failed_pc=0x0c040c20u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040c22;
P_0c040c22: /* original 6303, guest PC 0x0c040c22 */
if(!s->budget--) { s->failed_pc=0x0c040c22u; return 0; }
r[3]=r[0];
goto P_0c040c24;
P_0c040c24: /* original 4000, guest PC 0x0c040c24 */
if(!s->budget--) { s->failed_pc=0x0c040c24u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c040c26;
P_0c040c26: /* original 303c, guest PC 0x0c040c26 */
if(!s->budget--) { s->failed_pc=0x0c040c26u; return 0; }
r[0]+=r[3];
goto P_0c040c28;
P_0c040c28: /* original 4008, guest PC 0x0c040c28 */
if(!s->budget--) { s->failed_pc=0x0c040c28u; return 0; }
r[0]<<=2;
goto P_0c040c2a;
P_0c040c2a: /* original 600e, guest PC 0x0c040c2a */
if(!s->budget--) { s->failed_pc=0x0c040c2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c040c2c;
P_0c040c2c: /* original d116, guest PC 0x0c040c2c */
if(!s->budget--) { s->failed_pc=0x0c040c2cu; return 0; }
r[1]=read(ram,0x0c040c88u,4);
goto P_0c040c2e;
P_0c040c2e: /* original 001e, guest PC 0x0c040c2e */
if(!s->budget--) { s->failed_pc=0x0c040c2eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040c30;
P_0c040c30: /* original 88ff, guest PC 0x0c040c30 */
if(!s->budget--) { s->failed_pc=0x0c040c30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c040c32;
P_0c040c32: /* original 890d, guest PC 0x0c040c32 */
if(!s->budget--) { s->failed_pc=0x0c040c32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040c50; }
goto P_0c040c34;
P_0c040c34: /* original 64f2, guest PC 0x0c040c34 */
if(!s->budget--) { s->failed_pc=0x0c040c34u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c040c36;
P_0c040c36: /* original 4428, guest PC 0x0c040c36 */
if(!s->budget--) { s->failed_pc=0x0c040c36u; return 0; }
r[4]<<=16;
goto P_0c040c38;
P_0c040c38: /* original 4418, guest PC 0x0c040c38 */
if(!s->budget--) { s->failed_pc=0x0c040c38u; return 0; }
r[4]<<=8;
goto P_0c040c3a;
P_0c040c3a: /* original d314, guest PC 0x0c040c3a */
if(!s->budget--) { s->failed_pc=0x0c040c3au; return 0; }
r[3]=read(ram,0x0c040c8cu,4);
goto P_0c040c3c;
P_0c040c3c: /* original 343c, guest PC 0x0c040c3c */
if(!s->budget--) { s->failed_pc=0x0c040c3cu; return 0; }
r[4]+=r[3];
goto P_0c040c3e;
P_0c040c3e: /* original b16e, guest PC 0x0c040c3e */
if(!s->budget--) { s->failed_pc=0x0c040c3eu; return 0; }
target=0x0c040f1eu; r[16]=0x0c040c42u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040c42u) { target=s->pc; goto dispatch; }
goto P_0c040c42;
P_0c040c40: /* original 0009, guest PC 0x0c040c40 */
if(!s->budget--) { s->failed_pc=0x0c040c40u; return 0; }
goto P_0c040c42;
P_0c040c42: /* original 64f2, guest PC 0x0c040c42 */
if(!s->budget--) { s->failed_pc=0x0c040c42u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c040c44;
P_0c040c44: /* original 4428, guest PC 0x0c040c44 */
if(!s->budget--) { s->failed_pc=0x0c040c44u; return 0; }
r[4]<<=16;
goto P_0c040c46;
P_0c040c46: /* original 4418, guest PC 0x0c040c46 */
if(!s->budget--) { s->failed_pc=0x0c040c46u; return 0; }
r[4]<<=8;
goto P_0c040c48;
P_0c040c48: /* original 931b, guest PC 0x0c040c48 */
if(!s->budget--) { s->failed_pc=0x0c040c48u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040c82u,2);
goto P_0c040c4a;
P_0c040c4a: /* original 343c, guest PC 0x0c040c4a */
if(!s->budget--) { s->failed_pc=0x0c040c4au; return 0; }
r[4]+=r[3];
goto P_0c040c4c;
P_0c040c4c: /* original b167, guest PC 0x0c040c4c */
if(!s->budget--) { s->failed_pc=0x0c040c4cu; return 0; }
target=0x0c040f1eu; r[16]=0x0c040c50u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040c50u) { target=s->pc; goto dispatch; }
goto P_0c040c50;
P_0c040c4e: /* original 0009, guest PC 0x0c040c4e */
if(!s->budget--) { s->failed_pc=0x0c040c4eu; return 0; }
goto P_0c040c50;
P_0c040c50: /* original 63f2, guest PC 0x0c040c50 */
if(!s->budget--) { s->failed_pc=0x0c040c50u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040c52;
P_0c040c52: /* original 7301, guest PC 0x0c040c52 */
if(!s->budget--) { s->failed_pc=0x0c040c52u; return 0; }
r[3]+=0x00000001u;
goto P_0c040c54;
P_0c040c54: /* original 2f32, guest PC 0x0c040c54 */
if(!s->budget--) { s->failed_pc=0x0c040c54u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c040c56;
P_0c040c56: /* original e208, guest PC 0x0c040c56 */
if(!s->budget--) { s->failed_pc=0x0c040c56u; return 0; }
r[2]=0x00000008u;
goto P_0c040c58;
P_0c040c58: /* original 61f2, guest PC 0x0c040c58 */
if(!s->budget--) { s->failed_pc=0x0c040c58u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c040c5a;
P_0c040c5a: /* original 3123, guest PC 0x0c040c5a */
if(!s->budget--) { s->failed_pc=0x0c040c5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c040c5c;
P_0c040c5c: /* original 8be0, guest PC 0x0c040c5c */
if(!s->budget--) { s->failed_pc=0x0c040c5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040c20; }
goto P_0c040c5e;
P_0c040c5e: /* original 7f10, guest PC 0x0c040c5e */
if(!s->budget--) { s->failed_pc=0x0c040c5eu; return 0; }
r[15]+=0x00000010u;
goto P_0c040c60;
P_0c040c60: /* original 4f26, guest PC 0x0c040c60 */
if(!s->budget--) { s->failed_pc=0x0c040c60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040c62;
P_0c040c62: /* original 6ef6, guest PC 0x0c040c62 */
if(!s->budget--) { s->failed_pc=0x0c040c62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c040c64;
P_0c040c64: /* original 000b, guest PC 0x0c040c64 */
if(!s->budget--) { s->failed_pc=0x0c040c64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040c66: /* original 0009, guest PC 0x0c040c66 */
if(!s->budget--) { s->failed_pc=0x0c040c66u; return 0; }
goto P_0c040c68;
P_0c040c68: /* original 64e3, guest PC 0x0c040c68 */
if(!s->budget--) { s->failed_pc=0x0c040c68u; return 0; }
r[4]=r[14];
goto P_0c040c6a;
P_0c040c6a: /* original b158, guest PC 0x0c040c6a */
if(!s->budget--) { s->failed_pc=0x0c040c6au; return 0; }
target=0x0c040f1eu; r[16]=0x0c040c6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040c6eu) { target=s->pc; goto dispatch; }
goto P_0c040c6e;
P_0c040c6c: /* original 0009, guest PC 0x0c040c6c */
if(!s->budget--) { s->failed_pc=0x0c040c6cu; return 0; }
goto P_0c040c6e;
P_0c040c6e: /* original 7f10, guest PC 0x0c040c6e */
if(!s->budget--) { s->failed_pc=0x0c040c6eu; return 0; }
r[15]+=0x00000010u;
goto P_0c040c70;
P_0c040c70: /* original 4f26, guest PC 0x0c040c70 */
if(!s->budget--) { s->failed_pc=0x0c040c70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040c72;
P_0c040c72: /* original 6ef6, guest PC 0x0c040c72 */
if(!s->budget--) { s->failed_pc=0x0c040c72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c040c74;
P_0c040c74: /* original 000b, guest PC 0x0c040c74 */
if(!s->budget--) { s->failed_pc=0x0c040c74u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040c76: /* original 0009, guest PC 0x0c040c76 */
if(!s->budget--) { s->failed_pc=0x0c040c76u; return 0; }
return vf3_matrix_family(0x0c040c78u,s,ram);
P_0c0431ea: /* original 4f22, guest PC 0x0c0431ea */
if(!s->budget--) { s->failed_pc=0x0c0431eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0431ec;
P_0c0431ec: /* original 4c08, guest PC 0x0c0431ec */
if(!s->budget--) { s->failed_pc=0x0c0431ecu; return 0; }
r[12]<<=2;
goto P_0c0431ee;
P_0c0431ee: /* original 6e63, guest PC 0x0c0431ee */
if(!s->budget--) { s->failed_pc=0x0c0431eeu; return 0; }
r[14]=r[6];
goto P_0c0431f0;
P_0c0431f0: /* original 4c00, guest PC 0x0c0431f0 */
if(!s->budget--) { s->failed_pc=0x0c0431f0u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0431f2;
P_0c0431f2: /* original 8801, guest PC 0x0c0431f2 */
if(!s->budget--) { s->failed_pc=0x0c0431f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0431f4;
P_0c0431f4: /* original 7ff0, guest PC 0x0c0431f4 */
if(!s->budget--) { s->failed_pc=0x0c0431f4u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0431f6;
P_0c0431f6: /* original 6df3, guest PC 0x0c0431f6 */
if(!s->budget--) { s->failed_pc=0x0c0431f6u; return 0; }
r[13]=r[15];
goto P_0c0431f8;
P_0c0431f8: /* original 2d42, guest PC 0x0c0431f8 */
if(!s->budget--) { s->failed_pc=0x0c0431f8u; return 0; }
write(ram,r[13],r[4],4);
goto P_0c0431fa;
P_0c0431fa: /* original 1d51, guest PC 0x0c0431fa */
if(!s->budget--) { s->failed_pc=0x0c0431fau; return 0; }
write(ram,r[13]+4,r[5],4);
goto P_0c0431fc;
P_0c0431fc: /* original 64d3, guest PC 0x0c0431fc */
if(!s->budget--) { s->failed_pc=0x0c0431fcu; return 0; }
r[4]=r[13];
goto P_0c0431fe;
P_0c0431fe: /* original 1d33, guest PC 0x0c0431fe */
if(!s->budget--) { s->failed_pc=0x0c0431feu; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c043200;
P_0c043200: /* original 8f08, guest PC 0x0c043200 */
if(!s->budget--) { s->failed_pc=0x0c043200u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(!cond) { goto P_0c043214; }
goto P_0c043204;
P_0c043202: /* original 7408, guest PC 0x0c043202 */
if(!s->budget--) { s->failed_pc=0x0c043202u; return 0; }
r[4]+=0x00000008u;
goto P_0c043204;
P_0c043204: /* original 65c3, guest PC 0x0c043204 */
if(!s->budget--) { s->failed_pc=0x0c043204u; return 0; }
r[5]=r[12];
goto P_0c043206;
P_0c043206: /* original eb11, guest PC 0x0c043206 */
if(!s->budget--) { s->failed_pc=0x0c043206u; return 0; }
r[11]=0x00000011u;
goto P_0c043208;
P_0c043208: /* original 24e2, guest PC 0x0c043208 */
if(!s->budget--) { s->failed_pc=0x0c043208u; return 0; }
write(ram,r[4],r[14],4);
goto P_0c04320a;
P_0c04320a: /* original d348, guest PC 0x0c04320a */
if(!s->budget--) { s->failed_pc=0x0c04320au; return 0; }
r[3]=read(ram,0x0c04332cu,4);
goto P_0c04320c;
P_0c04320c: /* original 430b, guest PC 0x0c04320c */
if(!s->budget--) { s->failed_pc=0x0c04320cu; return 0; }
target=r[3];
r[16]=0x0c043210u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043210u) { target=s->pc; goto dispatch; }
goto P_0c043210;
P_0c04320e: /* original 64e3, guest PC 0x0c04320e */
if(!s->budget--) { s->failed_pc=0x0c04320eu; return 0; }
r[4]=r[14];
goto P_0c043210;
P_0c043210: /* original a009, guest PC 0x0c043210 */
if(!s->budget--) { s->failed_pc=0x0c043210u; return 0; }
goto P_0c043226;
P_0c043212: /* original 0009, guest PC 0x0c043212 */
if(!s->budget--) { s->failed_pc=0x0c043212u; return 0; }
goto P_0c043214;
P_0c043214: /* original 2778, guest PC 0x0c043214 */
if(!s->budget--) { s->failed_pc=0x0c043214u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c043216;
P_0c043216: /* original 8b04, guest PC 0x0c043216 */
if(!s->budget--) { s->failed_pc=0x0c043216u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043222; }
goto P_0c043218;
P_0c043218: /* original d245, guest PC 0x0c043218 */
if(!s->budget--) { s->failed_pc=0x0c043218u; return 0; }
r[2]=read(ram,0x0c043330u,4);
goto P_0c04321a;
P_0c04321a: /* original eb10, guest PC 0x0c04321a */
if(!s->budget--) { s->failed_pc=0x0c04321au; return 0; }
r[11]=0x00000010u;
goto P_0c04321c;
P_0c04321c: /* original 22eb, guest PC 0x0c04321c */
if(!s->budget--) { s->failed_pc=0x0c04321cu; return 0; }
r[2]|=r[14];
goto P_0c04321e;
P_0c04321e: /* original a002, guest PC 0x0c04321e */
if(!s->budget--) { s->failed_pc=0x0c04321eu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c043226;
P_0c043220: /* original 2422, guest PC 0x0c043220 */
if(!s->budget--) { s->failed_pc=0x0c043220u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c043222;
P_0c043222: /* original a01b, guest PC 0x0c043222 */
if(!s->budget--) { s->failed_pc=0x0c043222u; return 0; }
r[0]=0xffffffeeu;
goto P_0c04325c;
P_0c043224: /* original e0ee, guest PC 0x0c043224 */
if(!s->budget--) { s->failed_pc=0x0c043224u; return 0; }
r[0]=0xffffffeeu;
goto P_0c043226;
P_0c043226: /* original d243, guest PC 0x0c043226 */
if(!s->budget--) { s->failed_pc=0x0c043226u; return 0; }
r[2]=read(ram,0x0c043334u,4);
goto P_0c043228;
P_0c043228: /* original 65d3, guest PC 0x0c043228 */
if(!s->budget--) { s->failed_pc=0x0c043228u; return 0; }
r[5]=r[13];
goto P_0c04322a;
P_0c04322a: /* original 420b, guest PC 0x0c04322a */
if(!s->budget--) { s->failed_pc=0x0c04322au; return 0; }
target=r[2];
r[16]=0x0c04322eu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04322eu) { target=s->pc; goto dispatch; }
goto P_0c04322e;
P_0c04322c: /* original 64b3, guest PC 0x0c04322c */
if(!s->budget--) { s->failed_pc=0x0c04322cu; return 0; }
r[4]=r[11];
goto P_0c04322e;
P_0c04322e: /* original 6d03, guest PC 0x0c04322e */
if(!s->budget--) { s->failed_pc=0x0c04322eu; return 0; }
r[13]=r[0];
goto P_0c043230;
P_0c043230: /* original 2dd8, guest PC 0x0c043230 */
if(!s->budget--) { s->failed_pc=0x0c043230u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c043232;
P_0c043232: /* original 8912, guest PC 0x0c043232 */
if(!s->budget--) { s->failed_pc=0x0c043232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04325a; }
goto P_0c043234;
P_0c043234: /* original e3e4, guest PC 0x0c043234 */
if(!s->budget--) { s->failed_pc=0x0c043234u; return 0; }
r[3]=0xffffffe4u;
goto P_0c043236;
P_0c043236: /* original 60e3, guest PC 0x0c043236 */
if(!s->budget--) { s->failed_pc=0x0c043236u; return 0; }
r[0]=r[14];
goto P_0c043238;
P_0c043238: /* original 403c, guest PC 0x0c043238 */
if(!s->budget--) { s->failed_pc=0x0c043238u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c04323a;
P_0c04323a: /* original c90f, guest PC 0x0c04323a */
if(!s->budget--) { s->failed_pc=0x0c04323au; return 0; }
r[0]&=15u;
goto P_0c04323c;
P_0c04323c: /* original 880a, guest PC 0x0c04323c */
if(!s->budget--) { s->failed_pc=0x0c04323cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c04323e;
P_0c04323e: /* original 890c, guest PC 0x0c04323e */
if(!s->budget--) { s->failed_pc=0x0c04323eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04325a; }
goto P_0c043240;
P_0c043240: /* original e31f, guest PC 0x0c043240 */
if(!s->budget--) { s->failed_pc=0x0c043240u; return 0; }
r[3]=0x0000001fu;
goto P_0c043242;
P_0c043242: /* original 23e8, guest PC 0x0c043242 */
if(!s->budget--) { s->failed_pc=0x0c043242u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c043244;
P_0c043244: /* original 8b05, guest PC 0x0c043244 */
if(!s->budget--) { s->failed_pc=0x0c043244u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043252; }
goto P_0c043246;
P_0c043246: /* original d33c, guest PC 0x0c043246 */
if(!s->budget--) { s->failed_pc=0x0c043246u; return 0; }
r[3]=read(ram,0x0c043338u,4);
goto P_0c043248;
P_0c043248: /* original 65c3, guest PC 0x0c043248 */
if(!s->budget--) { s->failed_pc=0x0c043248u; return 0; }
r[5]=r[12];
goto P_0c04324a;
P_0c04324a: /* original 430b, guest PC 0x0c04324a */
if(!s->budget--) { s->failed_pc=0x0c04324au; return 0; }
target=r[3];
r[16]=0x0c04324eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04324eu) { target=s->pc; goto dispatch; }
goto P_0c04324e;
P_0c04324c: /* original 64e3, guest PC 0x0c04324c */
if(!s->budget--) { s->failed_pc=0x0c04324cu; return 0; }
r[4]=r[14];
goto P_0c04324e;
P_0c04324e: /* original a004, guest PC 0x0c04324e */
if(!s->budget--) { s->failed_pc=0x0c04324eu; return 0; }
goto P_0c04325a;
P_0c043250: /* original 0009, guest PC 0x0c043250 */
if(!s->budget--) { s->failed_pc=0x0c043250u; return 0; }
goto P_0c043252;
P_0c043252: /* original d336, guest PC 0x0c043252 */
if(!s->budget--) { s->failed_pc=0x0c043252u; return 0; }
r[3]=read(ram,0x0c04332cu,4);
goto P_0c043254;
P_0c043254: /* original 65c3, guest PC 0x0c043254 */
if(!s->budget--) { s->failed_pc=0x0c043254u; return 0; }
r[5]=r[12];
goto P_0c043256;
P_0c043256: /* original 430b, guest PC 0x0c043256 */
if(!s->budget--) { s->failed_pc=0x0c043256u; return 0; }
target=r[3];
r[16]=0x0c04325au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04325au) { target=s->pc; goto dispatch; }
goto P_0c04325a;
P_0c043258: /* original 64e3, guest PC 0x0c043258 */
if(!s->budget--) { s->failed_pc=0x0c043258u; return 0; }
r[4]=r[14];
goto P_0c04325a;
P_0c04325a: /* original 60d3, guest PC 0x0c04325a */
if(!s->budget--) { s->failed_pc=0x0c04325au; return 0; }
r[0]=r[13];
goto P_0c04325c;
P_0c04325c: /* original 7f10, guest PC 0x0c04325c */
if(!s->budget--) { s->failed_pc=0x0c04325cu; return 0; }
r[15]+=0x00000010u;
goto P_0c04325e;
P_0c04325e: /* original 4f26, guest PC 0x0c04325e */
if(!s->budget--) { s->failed_pc=0x0c04325eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043260;
P_0c043260: /* original 6bf6, guest PC 0x0c043260 */
if(!s->budget--) { s->failed_pc=0x0c043260u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c043262;
P_0c043262: /* original 6cf6, guest PC 0x0c043262 */
if(!s->budget--) { s->failed_pc=0x0c043262u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043264;
P_0c043264: /* original 6df6, guest PC 0x0c043264 */
if(!s->budget--) { s->failed_pc=0x0c043264u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043266;
P_0c043266: /* original 000b, guest PC 0x0c043266 */
if(!s->budget--) { s->failed_pc=0x0c043266u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043268: /* original 6ef6, guest PC 0x0c043268 */
if(!s->budget--) { s->failed_pc=0x0c043268u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04326au,s,ram);
P_0c0432e2: /* original 4f22, guest PC 0x0c0432e2 */
if(!s->budget--) { s->failed_pc=0x0c0432e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0432e4;
P_0c0432e4: /* original d316, guest PC 0x0c0432e4 */
if(!s->budget--) { s->failed_pc=0x0c0432e4u; return 0; }
r[3]=read(ram,0x0c043340u,4);
goto P_0c0432e6;
P_0c0432e6: /* original 7ff0, guest PC 0x0c0432e6 */
if(!s->budget--) { s->failed_pc=0x0c0432e6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0432e8;
P_0c0432e8: /* original 430b, guest PC 0x0c0432e8 */
if(!s->budget--) { s->failed_pc=0x0c0432e8u; return 0; }
target=r[3];
r[16]=0x0c0432ecu;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0432ecu) { target=s->pc; goto dispatch; }
goto P_0c0432ec;
P_0c0432ea: /* original 65f3, guest PC 0x0c0432ea */
if(!s->budget--) { s->failed_pc=0x0c0432eau; return 0; }
r[5]=r[15];
goto P_0c0432ec;
P_0c0432ec: /* original 6403, guest PC 0x0c0432ec */
if(!s->budget--) { s->failed_pc=0x0c0432ecu; return 0; }
r[4]=r[0];
goto P_0c0432ee;
P_0c0432ee: /* original 6043, guest PC 0x0c0432ee */
if(!s->budget--) { s->failed_pc=0x0c0432eeu; return 0; }
r[0]=r[4];
goto P_0c0432f0;
P_0c0432f0: /* original 55f2, guest PC 0x0c0432f0 */
if(!s->budget--) { s->failed_pc=0x0c0432f0u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0432f2;
P_0c0432f2: /* original 88ff, guest PC 0x0c0432f2 */
if(!s->budget--) { s->failed_pc=0x0c0432f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0432f4;
P_0c0432f4: /* original 8d26, guest PC 0x0c0432f4 */
if(!s->budget--) { s->failed_pc=0x0c0432f4u; return 0; }
cond=r[17]&1u;
r[6]=0x00000004u;
if(cond) { goto P_0c043344; }
goto P_0c0432f8;
P_0c0432f6: /* original e604, guest PC 0x0c0432f6 */
if(!s->budget--) { s->failed_pc=0x0c0432f6u; return 0; }
r[6]=0x00000004u;
goto P_0c0432f8;
P_0c0432f8: /* original 8800, guest PC 0x0c0432f8 */
if(!s->budget--) { s->failed_pc=0x0c0432f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0432fa;
P_0c0432fa: /* original 8909, guest PC 0x0c0432fa */
if(!s->budget--) { s->failed_pc=0x0c0432fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043310; }
goto P_0c0432fc;
P_0c0432fc: /* original 8801, guest PC 0x0c0432fc */
if(!s->budget--) { s->failed_pc=0x0c0432fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0432fe;
P_0c0432fe: /* original 8909, guest PC 0x0c0432fe */
if(!s->budget--) { s->failed_pc=0x0c0432feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043314; }
goto P_0c043300;
P_0c043300: /* original 8802, guest PC 0x0c043300 */
if(!s->budget--) { s->failed_pc=0x0c043300u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c043302;
P_0c043302: /* original 8909, guest PC 0x0c043302 */
if(!s->budget--) { s->failed_pc=0x0c043302u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043318; }
goto P_0c043304;
P_0c043304: /* original 8803, guest PC 0x0c043304 */
if(!s->budget--) { s->failed_pc=0x0c043304u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c043306;
P_0c043306: /* original 890a, guest PC 0x0c043306 */
if(!s->budget--) { s->failed_pc=0x0c043306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04331e; }
goto P_0c043308;
P_0c043308: /* original 8804, guest PC 0x0c043308 */
if(!s->budget--) { s->failed_pc=0x0c043308u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c04330a;
P_0c04330a: /* original 890a, guest PC 0x0c04330a */
if(!s->budget--) { s->failed_pc=0x0c04330au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043322; }
goto P_0c04330c;
P_0c04330c: /* original a051, guest PC 0x0c04330c */
if(!s->budget--) { s->failed_pc=0x0c04330cu; return 0; }
goto P_0c0433b2;
P_0c04330e: /* original 0009, guest PC 0x0c04330e */
if(!s->budget--) { s->failed_pc=0x0c04330eu; return 0; }
goto P_0c043310;
P_0c043310: /* original a04f, guest PC 0x0c043310 */
if(!s->budget--) { s->failed_pc=0x0c043310u; return 0; }
r[4]=0x00000000u;
goto P_0c0433b2;
P_0c043312: /* original e400, guest PC 0x0c043312 */
if(!s->budget--) { s->failed_pc=0x0c043312u; return 0; }
r[4]=0x00000000u;
goto P_0c043314;
P_0c043314: /* original a001, guest PC 0x0c043314 */
if(!s->budget--) { s->failed_pc=0x0c043314u; return 0; }
r[4]=r[6];
goto P_0c04331a;
P_0c043316: /* original 6463, guest PC 0x0c043316 */
if(!s->budget--) { s->failed_pc=0x0c043316u; return 0; }
r[4]=r[6];
goto P_0c043318;
P_0c043318: /* original e401, guest PC 0x0c043318 */
if(!s->budget--) { s->failed_pc=0x0c043318u; return 0; }
r[4]=0x00000001u;
goto P_0c04331a;
P_0c04331a: /* original a04a, guest PC 0x0c04331a */
if(!s->budget--) { s->failed_pc=0x0c04331au; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0433b2;
P_0c04331c: /* original 2e52, guest PC 0x0c04331c */
if(!s->budget--) { s->failed_pc=0x0c04331cu; return 0; }
write(ram,r[14],r[5],4);
goto P_0c04331e;
P_0c04331e: /* original a048, guest PC 0x0c04331e */
if(!s->budget--) { s->failed_pc=0x0c04331eu; return 0; }
r[4]=0x00000007u;
goto P_0c0433b2;
P_0c043320: /* original e407, guest PC 0x0c043320 */
if(!s->budget--) { s->failed_pc=0x0c043320u; return 0; }
r[4]=0x00000007u;
goto P_0c043322;
P_0c043322: /* original a046, guest PC 0x0c043322 */
if(!s->budget--) { s->failed_pc=0x0c043322u; return 0; }
r[4]=r[6];
goto P_0c0433b2;
P_0c043324: /* original 6463, guest PC 0x0c043324 */
if(!s->budget--) { s->failed_pc=0x0c043324u; return 0; }
r[4]=r[6];
return vf3_matrix_family(0x0c043326u,s,ram);
P_0c043344: /* original 52f1, guest PC 0x0c043344 */
if(!s->budget--) { s->failed_pc=0x0c043344u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c043346;
P_0c043346: /* original e405, guest PC 0x0c043346 */
if(!s->budget--) { s->failed_pc=0x0c043346u; return 0; }
r[4]=0x00000005u;
goto P_0c043348;
P_0c043348: /* original 1e21, guest PC 0x0c043348 */
if(!s->budget--) { s->failed_pc=0x0c043348u; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c04334a;
P_0c04334a: /* original 60f2, guest PC 0x0c04334a */
if(!s->budget--) { s->failed_pc=0x0c04334au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04334c;
P_0c04334c: /* original e111, guest PC 0x0c04334c */
if(!s->budget--) { s->failed_pc=0x0c04334cu; return 0; }
r[1]=0x00000011u;
goto P_0c04334e;
P_0c04334e: /* original 3012, guest PC 0x0c04334e */
if(!s->budget--) { s->failed_pc=0x0c04334eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c043350;
P_0c043350: /* original 892d, guest PC 0x0c043350 */
if(!s->budget--) { s->failed_pc=0x0c043350u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0433ae; }
goto P_0c043352;
P_0c043352: /* original 4000, guest PC 0x0c043352 */
if(!s->budget--) { s->failed_pc=0x0c043352u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043354;
P_0c043354: /* original 6103, guest PC 0x0c043354 */
if(!s->budget--) { s->failed_pc=0x0c043354u; return 0; }
r[1]=r[0];
goto P_0c043356;
P_0c043356: /* original c702, guest PC 0x0c043356 */
if(!s->budget--) { s->failed_pc=0x0c043356u; return 0; }
r[0]=0x0c043360u;
goto P_0c043358;
P_0c043358: /* original 001d, guest PC 0x0c043358 */
if(!s->budget--) { s->failed_pc=0x0c043358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c04335a;
P_0c04335a: /* original 0023, guest PC 0x0c04335a */
if(!s->budget--) { s->failed_pc=0x0c04335au; return 0; }
target=r[0]+0x0c04335eu;
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
P_0c04335c: /* original 0009, guest PC 0x0c04335c */
if(!s->budget--) { s->failed_pc=0x0c04335cu; return 0; }
return vf3_matrix_family(0x0c04335eu,s,ram);
P_0c0433ae: /* original e2e6, guest PC 0x0c0433ae */
if(!s->budget--) { s->failed_pc=0x0c0433aeu; return 0; }
r[2]=0xffffffe6u;
goto P_0c0433b0;
P_0c0433b0: /* original 2e22, guest PC 0x0c0433b0 */
if(!s->budget--) { s->failed_pc=0x0c0433b0u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0433b2;
P_0c0433b2: /* original 7f10, guest PC 0x0c0433b2 */
if(!s->budget--) { s->failed_pc=0x0c0433b2u; return 0; }
r[15]+=0x00000010u;
goto P_0c0433b4;
P_0c0433b4: /* original 6043, guest PC 0x0c0433b4 */
if(!s->budget--) { s->failed_pc=0x0c0433b4u; return 0; }
r[0]=r[4];
goto P_0c0433b6;
P_0c0433b6: /* original 4f26, guest PC 0x0c0433b6 */
if(!s->budget--) { s->failed_pc=0x0c0433b6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0433b8;
P_0c0433b8: /* original 000b, guest PC 0x0c0433b8 */
if(!s->budget--) { s->failed_pc=0x0c0433b8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0433ba: /* original 6ef6, guest PC 0x0c0433ba */
if(!s->budget--) { s->failed_pc=0x0c0433bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0433bcu,s,ram);
P_0c04363e: /* original 4f22, guest PC 0x0c04363e */
if(!s->budget--) { s->failed_pc=0x0c04363eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043640;
P_0c043640: /* original 633c, guest PC 0x0c043640 */
if(!s->budget--) { s->failed_pc=0x0c043640u; return 0; }
r[3]=r[3]&255u;
goto P_0c043642;
P_0c043642: /* original 3323, guest PC 0x0c043642 */
if(!s->budget--) { s->failed_pc=0x0c043642u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c043644;
P_0c043644: /* original 8d02, guest PC 0x0c043644 */
if(!s->budget--) { s->failed_pc=0x0c043644u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c04364c; }
goto P_0c043648;
P_0c043646: /* original 6e53, guest PC 0x0c043646 */
if(!s->budget--) { s->failed_pc=0x0c043646u; return 0; }
r[14]=r[5];
goto P_0c043648;
P_0c043648: /* original a039, guest PC 0x0c043648 */
if(!s->budget--) { s->failed_pc=0x0c043648u; return 0; }
r[0]=0x00000000u;
goto P_0c0436be;
P_0c04364a: /* original e000, guest PC 0x0c04364a */
if(!s->budget--) { s->failed_pc=0x0c04364au; return 0; }
r[0]=0x00000000u;
goto P_0c04364c;
P_0c04364c: /* original 64d3, guest PC 0x0c04364c */
if(!s->budget--) { s->failed_pc=0x0c04364cu; return 0; }
r[4]=r[13];
goto P_0c04364e;
P_0c04364e: /* original 65e3, guest PC 0x0c04364e */
if(!s->budget--) { s->failed_pc=0x0c04364eu; return 0; }
r[5]=r[14];
goto P_0c043650;
P_0c043650: /* original e604, guest PC 0x0c043650 */
if(!s->budget--) { s->failed_pc=0x0c043650u; return 0; }
r[6]=0x00000004u;
goto P_0c043652;
P_0c043652: /* original bf55, guest PC 0x0c043652 */
if(!s->budget--) { s->failed_pc=0x0c043652u; return 0; }
target=0x0c043500u; r[16]=0x0c043656u;
r[4]+=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043656u) { target=s->pc; goto dispatch; }
goto P_0c043656;
P_0c043654: /* original 7402, guest PC 0x0c043654 */
if(!s->budget--) { s->failed_pc=0x0c043654u; return 0; }
r[4]+=0x00000002u;
goto P_0c043656;
P_0c043656: /* original 65e3, guest PC 0x0c043656 */
if(!s->budget--) { s->failed_pc=0x0c043656u; return 0; }
r[5]=r[14];
goto P_0c043658;
P_0c043658: /* original 64d3, guest PC 0x0c043658 */
if(!s->budget--) { s->failed_pc=0x0c043658u; return 0; }
r[4]=r[13];
goto P_0c04365a;
P_0c04365a: /* original 7504, guest PC 0x0c04365a */
if(!s->budget--) { s->failed_pc=0x0c04365au; return 0; }
r[5]+=0x00000004u;
goto P_0c04365c;
P_0c04365c: /* original e604, guest PC 0x0c04365c */
if(!s->budget--) { s->failed_pc=0x0c04365cu; return 0; }
r[6]=0x00000004u;
goto P_0c04365e;
P_0c04365e: /* original bf4f, guest PC 0x0c04365e */
if(!s->budget--) { s->failed_pc=0x0c04365eu; return 0; }
target=0x0c043500u; r[16]=0x0c043662u;
r[4]+=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043662u) { target=s->pc; goto dispatch; }
goto P_0c043662;
P_0c043660: /* original 740a, guest PC 0x0c043660 */
if(!s->budget--) { s->failed_pc=0x0c043660u; return 0; }
r[4]+=0x0000000au;
goto P_0c043662;
P_0c043662: /* original e019, guest PC 0x0c043662 */
if(!s->budget--) { s->failed_pc=0x0c043662u; return 0; }
r[0]=0x00000019u;
goto P_0c043664;
P_0c043664: /* original 00dc, guest PC 0x0c043664 */
if(!s->budget--) { s->failed_pc=0x0c043664u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c043666;
P_0c043666: /* original 80e8, guest PC 0x0c043666 */
if(!s->budget--) { s->failed_pc=0x0c043666u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c043668;
P_0c043668: /* original e020, guest PC 0x0c043668 */
if(!s->budget--) { s->failed_pc=0x0c043668u; return 0; }
r[0]=0x00000020u;
goto P_0c04366a;
P_0c04366a: /* original 0cdc, guest PC 0x0c04366a */
if(!s->budget--) { s->failed_pc=0x0c04366au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c04366c;
P_0c04366c: /* original 84e8, guest PC 0x0c04366c */
if(!s->budget--) { s->failed_pc=0x0c04366cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c04366e;
P_0c04366e: /* original 600c, guest PC 0x0c04366e */
if(!s->budget--) { s->failed_pc=0x0c04366eu; return 0; }
r[0]=r[0]&255u;
goto P_0c043670;
P_0c043670: /* original c802, guest PC 0x0c043670 */
if(!s->budget--) { s->failed_pc=0x0c043670u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c043672;
P_0c043672: /* original 8f01, guest PC 0x0c043672 */
if(!s->budget--) { s->failed_pc=0x0c043672u; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(!cond) { goto P_0c043678; }
goto P_0c043676;
P_0c043674: /* original 6ccc, guest PC 0x0c043674 */
if(!s->budget--) { s->failed_pc=0x0c043674u; return 0; }
r[12]=r[12]&255u;
goto P_0c043676;
P_0c043676: /* original 7cfe, guest PC 0x0c043676 */
if(!s->budget--) { s->failed_pc=0x0c043676u; return 0; }
r[12]+=0xfffffffeu;
goto P_0c043678;
P_0c043678: /* original 65e3, guest PC 0x0c043678 */
if(!s->budget--) { s->failed_pc=0x0c043678u; return 0; }
r[5]=r[14];
goto P_0c04367a;
P_0c04367a: /* original 64d3, guest PC 0x0c04367a */
if(!s->budget--) { s->failed_pc=0x0c04367au; return 0; }
r[4]=r[13];
goto P_0c04367c;
P_0c04367c: /* original 750a, guest PC 0x0c04367c */
if(!s->budget--) { s->failed_pc=0x0c04367cu; return 0; }
r[5]+=0x0000000au;
goto P_0c04367e;
P_0c04367e: /* original 66c3, guest PC 0x0c04367e */
if(!s->budget--) { s->failed_pc=0x0c04367eu; return 0; }
r[6]=r[12];
goto P_0c043680;
P_0c043680: /* original bf3e, guest PC 0x0c043680 */
if(!s->budget--) { s->failed_pc=0x0c043680u; return 0; }
target=0x0c043500u; r[16]=0x0c043684u;
r[4]+=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043684u) { target=s->pc; goto dispatch; }
goto P_0c043684;
P_0c043682: /* original 7421, guest PC 0x0c043682 */
if(!s->budget--) { s->failed_pc=0x0c043682u; return 0; }
r[4]+=0x00000021u;
goto P_0c043684;
P_0c043684: /* original 63e3, guest PC 0x0c043684 */
if(!s->budget--) { s->failed_pc=0x0c043684u; return 0; }
r[3]=r[14];
goto P_0c043686;
P_0c043686: /* original 730a, guest PC 0x0c043686 */
if(!s->budget--) { s->failed_pc=0x0c043686u; return 0; }
r[3]+=0x0000000au;
goto P_0c043688;
P_0c043688: /* original e400, guest PC 0x0c043688 */
if(!s->budget--) { s->failed_pc=0x0c043688u; return 0; }
r[4]=0x00000000u;
goto P_0c04368a;
P_0c04368a: /* original 3c3c, guest PC 0x0c04368a */
if(!s->budget--) { s->failed_pc=0x0c04368au; return 0; }
r[12]+=r[3];
goto P_0c04368c;
P_0c04368c: /* original 2c40, guest PC 0x0c04368c */
if(!s->budget--) { s->failed_pc=0x0c04368cu; return 0; }
write(ram,r[12],r[4],1);
goto P_0c04368e;
P_0c04368e: /* original 84e8, guest PC 0x0c04368e */
if(!s->budget--) { s->failed_pc=0x0c04368eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c043690;
P_0c043690: /* original 600c, guest PC 0x0c043690 */
if(!s->budget--) { s->failed_pc=0x0c043690u; return 0; }
r[0]=r[0]&255u;
goto P_0c043692;
P_0c043692: /* original c802, guest PC 0x0c043692 */
if(!s->budget--) { s->failed_pc=0x0c043692u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c043694;
P_0c043694: /* original 890d, guest PC 0x0c043694 */
if(!s->budget--) { s->failed_pc=0x0c043694u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0436b2; }
goto P_0c043696;
P_0c043696: /* original 84ea, guest PC 0x0c043696 */
if(!s->budget--) { s->failed_pc=0x0c043696u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c043698;
P_0c043698: /* original 2008, guest PC 0x0c043698 */
if(!s->budget--) { s->failed_pc=0x0c043698u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04369a;
P_0c04369a: /* original 8f03, guest PC 0x0c04369a */
if(!s->budget--) { s->failed_pc=0x0c04369au; return 0; }
cond=r[17]&1u;
r[5]=0x0000002eu;
if(!cond) { goto P_0c0436a4; }
goto P_0c04369e;
P_0c04369c: /* original e52e, guest PC 0x0c04369c */
if(!s->budget--) { s->failed_pc=0x0c04369cu; return 0; }
r[5]=0x0000002eu;
goto P_0c04369e;
P_0c04369e: /* original 6053, guest PC 0x0c04369e */
if(!s->budget--) { s->failed_pc=0x0c04369eu; return 0; }
r[0]=r[5];
goto P_0c0436a0;
P_0c0436a0: /* original a007, guest PC 0x0c0436a0 */
if(!s->budget--) { s->failed_pc=0x0c0436a0u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c0436b2;
P_0c0436a2: /* original 80ea, guest PC 0x0c0436a2 */
if(!s->budget--) { s->failed_pc=0x0c0436a2u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c0436a4;
P_0c0436a4: /* original 8801, guest PC 0x0c0436a4 */
if(!s->budget--) { s->failed_pc=0x0c0436a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0436a6;
P_0c0436a6: /* original 8b04, guest PC 0x0c0436a6 */
if(!s->budget--) { s->failed_pc=0x0c0436a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0436b2; }
goto P_0c0436a8;
P_0c0436a8: /* original 6053, guest PC 0x0c0436a8 */
if(!s->budget--) { s->failed_pc=0x0c0436a8u; return 0; }
r[0]=r[5];
goto P_0c0436aa;
P_0c0436aa: /* original 80ea, guest PC 0x0c0436aa */
if(!s->budget--) { s->failed_pc=0x0c0436aau; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c0436ac;
P_0c0436ac: /* original 80eb, guest PC 0x0c0436ac */
if(!s->budget--) { s->failed_pc=0x0c0436acu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0436ae;
P_0c0436ae: /* original 6043, guest PC 0x0c0436ae */
if(!s->budget--) { s->failed_pc=0x0c0436aeu; return 0; }
r[0]=r[4];
goto P_0c0436b0;
P_0c0436b0: /* original 80ec, guest PC 0x0c0436b0 */
if(!s->budget--) { s->failed_pc=0x0c0436b0u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c0436b2;
P_0c0436b2: /* original 64e3, guest PC 0x0c0436b2 */
if(!s->budget--) { s->failed_pc=0x0c0436b2u; return 0; }
r[4]=r[14];
goto P_0c0436b4;
P_0c0436b4: /* original bfa9, guest PC 0x0c0436b4 */
if(!s->budget--) { s->failed_pc=0x0c0436b4u; return 0; }
target=0x0c04360au; r[16]=0x0c0436b8u;
r[4]+=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0436b8u) { target=s->pc; goto dispatch; }
goto P_0c0436b8;
P_0c0436b6: /* original 740a, guest PC 0x0c0436b6 */
if(!s->budget--) { s->failed_pc=0x0c0436b6u; return 0; }
r[4]+=0x0000000au;
goto P_0c0436b8;
P_0c0436b8: /* original 80e9, guest PC 0x0c0436b8 */
if(!s->budget--) { s->failed_pc=0x0c0436b8u; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c0436ba;
P_0c0436ba: /* original 60d0, guest PC 0x0c0436ba */
if(!s->budget--) { s->failed_pc=0x0c0436bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[0]=tmp;
goto P_0c0436bc;
P_0c0436bc: /* original 600c, guest PC 0x0c0436bc */
if(!s->budget--) { s->failed_pc=0x0c0436bcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0436be;
P_0c0436be: /* original 4f26, guest PC 0x0c0436be */
if(!s->budget--) { s->failed_pc=0x0c0436beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0436c0;
P_0c0436c0: /* original 6cf6, guest PC 0x0c0436c0 */
if(!s->budget--) { s->failed_pc=0x0c0436c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0436c2;
P_0c0436c2: /* original 6df6, guest PC 0x0c0436c2 */
if(!s->budget--) { s->failed_pc=0x0c0436c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0436c4;
P_0c0436c4: /* original 000b, guest PC 0x0c0436c4 */
if(!s->budget--) { s->failed_pc=0x0c0436c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0436c6: /* original 6ef6, guest PC 0x0c0436c6 */
if(!s->budget--) { s->failed_pc=0x0c0436c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0436c8u,s,ram);
P_0c0437ae: /* original 4f22, guest PC 0x0c0437ae */
if(!s->budget--) { s->failed_pc=0x0c0437aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0437b0;
P_0c0437b0: /* original 7ffc, guest PC 0x0c0437b0 */
if(!s->budget--) { s->failed_pc=0x0c0437b0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0437b2;
P_0c0437b2: /* original 2f62, guest PC 0x0c0437b2 */
if(!s->budget--) { s->failed_pc=0x0c0437b2u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0437b4;
P_0c0437b4: /* original 6a52, guest PC 0x0c0437b4 */
if(!s->budget--) { s->failed_pc=0x0c0437b4u; return 0; }
tmp=read(ram,r[5],4);
r[10]=tmp;
goto P_0c0437b6;
P_0c0437b6: /* original bf28, guest PC 0x0c0437b6 */
if(!s->budget--) { s->failed_pc=0x0c0437b6u; return 0; }
target=0x0c04360au; r[16]=0x0c0437bau;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0437bau) { target=s->pc; goto dispatch; }
goto P_0c0437ba;
P_0c0437b8: /* original 64b3, guest PC 0x0c0437b8 */
if(!s->budget--) { s->failed_pc=0x0c0437b8u; return 0; }
r[4]=r[11];
goto P_0c0437ba;
P_0c0437ba: /* original 4a15, guest PC 0x0c0437ba */
if(!s->budget--) { s->failed_pc=0x0c0437bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c0437bc;
P_0c0437bc: /* original 6903, guest PC 0x0c0437bc */
if(!s->budget--) { s->failed_pc=0x0c0437bcu; return 0; }
r[9]=r[0];
goto P_0c0437be;
P_0c0437be: /* original 8f1f, guest PC 0x0c0437be */
if(!s->budget--) { s->failed_pc=0x0c0437beu; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(!cond) { goto P_0c043800; }
goto P_0c0437c2;
P_0c0437c0: /* original ed00, guest PC 0x0c0437c0 */
if(!s->budget--) { s->failed_pc=0x0c0437c0u; return 0; }
r[13]=0x00000000u;
goto P_0c0437c2;
P_0c0437c2: /* original 84e9, guest PC 0x0c0437c2 */
if(!s->budget--) { s->failed_pc=0x0c0437c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+9,1);
goto P_0c0437c4;
P_0c0437c4: /* original 639c, guest PC 0x0c0437c4 */
if(!s->budget--) { s->failed_pc=0x0c0437c4u; return 0; }
r[3]=r[9]&255u;
goto P_0c0437c6;
P_0c0437c6: /* original 600c, guest PC 0x0c0437c6 */
if(!s->budget--) { s->failed_pc=0x0c0437c6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0437c8;
P_0c0437c8: /* original 3030, guest PC 0x0c0437c8 */
if(!s->budget--) { s->failed_pc=0x0c0437c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c0437ca;
P_0c0437ca: /* original 8b15, guest PC 0x0c0437ca */
if(!s->budget--) { s->failed_pc=0x0c0437cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0437f8; }
goto P_0c0437cc;
P_0c0437cc: /* original 60f2, guest PC 0x0c0437cc */
if(!s->budget--) { s->failed_pc=0x0c0437ccu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0437ce;
P_0c0437ce: /* original 6cd3, guest PC 0x0c0437ce */
if(!s->budget--) { s->failed_pc=0x0c0437ceu; return 0; }
r[12]=r[13];
goto P_0c0437d0;
P_0c0437d0: /* original 8801, guest PC 0x0c0437d0 */
if(!s->budget--) { s->failed_pc=0x0c0437d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0437d2;
P_0c0437d2: /* original 8f08, guest PC 0x0c0437d2 */
if(!s->budget--) { s->failed_pc=0x0c0437d2u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c0437e6; }
goto P_0c0437d6;
P_0c0437d4: /* original 7c01, guest PC 0x0c0437d4 */
if(!s->budget--) { s->failed_pc=0x0c0437d4u; return 0; }
r[12]+=0x00000001u;
goto P_0c0437d6;
P_0c0437d6: /* original 65e3, guest PC 0x0c0437d6 */
if(!s->budget--) { s->failed_pc=0x0c0437d6u; return 0; }
r[5]=r[14];
goto P_0c0437d8;
P_0c0437d8: /* original 750a, guest PC 0x0c0437d8 */
if(!s->budget--) { s->failed_pc=0x0c0437d8u; return 0; }
r[5]+=0x0000000au;
goto P_0c0437da;
P_0c0437da: /* original bec8, guest PC 0x0c0437da */
if(!s->budget--) { s->failed_pc=0x0c0437dau; return 0; }
target=0x0c04356eu; r[16]=0x0c0437deu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0437deu) { target=s->pc; goto dispatch; }
goto P_0c0437de;
P_0c0437dc: /* original 64b3, guest PC 0x0c0437dc */
if(!s->budget--) { s->failed_pc=0x0c0437dcu; return 0; }
r[4]=r[11];
goto P_0c0437de;
P_0c0437de: /* original 8801, guest PC 0x0c0437de */
if(!s->budget--) { s->failed_pc=0x0c0437deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0437e0;
P_0c0437e0: /* original 8b0a, guest PC 0x0c0437e0 */
if(!s->budget--) { s->failed_pc=0x0c0437e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0437f8; }
goto P_0c0437e2;
P_0c0437e2: /* original a006, guest PC 0x0c0437e2 */
if(!s->budget--) { s->failed_pc=0x0c0437e2u; return 0; }
goto P_0c0437f2;
P_0c0437e4: /* original 0009, guest PC 0x0c0437e4 */
if(!s->budget--) { s->failed_pc=0x0c0437e4u; return 0; }
goto P_0c0437e6;
P_0c0437e6: /* original 65e3, guest PC 0x0c0437e6 */
if(!s->budget--) { s->failed_pc=0x0c0437e6u; return 0; }
r[5]=r[14];
goto P_0c0437e8;
P_0c0437e8: /* original 750a, guest PC 0x0c0437e8 */
if(!s->budget--) { s->failed_pc=0x0c0437e8u; return 0; }
r[5]+=0x0000000au;
goto P_0c0437ea;
P_0c0437ea: /* original bed2, guest PC 0x0c0437ea */
if(!s->budget--) { s->failed_pc=0x0c0437eau; return 0; }
target=0x0c043592u; r[16]=0x0c0437eeu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0437eeu) { target=s->pc; goto dispatch; }
goto P_0c0437ee;
P_0c0437ec: /* original 64b3, guest PC 0x0c0437ec */
if(!s->budget--) { s->failed_pc=0x0c0437ecu; return 0; }
r[4]=r[11];
goto P_0c0437ee;
P_0c0437ee: /* original 8801, guest PC 0x0c0437ee */
if(!s->budget--) { s->failed_pc=0x0c0437eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0437f0;
P_0c0437f0: /* original 8b02, guest PC 0x0c0437f0 */
if(!s->budget--) { s->failed_pc=0x0c0437f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0437f8; }
goto P_0c0437f2;
P_0c0437f2: /* original a006, guest PC 0x0c0437f2 */
if(!s->budget--) { s->failed_pc=0x0c0437f2u; return 0; }
r[0]=r[12];
goto P_0c043802;
P_0c0437f4: /* original 60c3, guest PC 0x0c0437f4 */
if(!s->budget--) { s->failed_pc=0x0c0437f4u; return 0; }
r[0]=r[12];
return vf3_matrix_family(0x0c0437f6u,s,ram);
P_0c0437f8: /* original 7d01, guest PC 0x0c0437f8 */
if(!s->budget--) { s->failed_pc=0x0c0437f8u; return 0; }
r[13]+=0x00000001u;
goto P_0c0437fa;
P_0c0437fa: /* original 3da3, guest PC 0x0c0437fa */
if(!s->budget--) { s->failed_pc=0x0c0437fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[10])!=0);
goto P_0c0437fc;
P_0c0437fc: /* original 8fe1, guest PC 0x0c0437fc */
if(!s->budget--) { s->failed_pc=0x0c0437fcu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000002cu;
if(!cond) { goto P_0c0437c2; }
goto P_0c043800;
P_0c0437fe: /* original 7e2c, guest PC 0x0c0437fe */
if(!s->budget--) { s->failed_pc=0x0c0437feu; return 0; }
r[14]+=0x0000002cu;
goto P_0c043800;
P_0c043800: /* original e000, guest PC 0x0c043800 */
if(!s->budget--) { s->failed_pc=0x0c043800u; return 0; }
r[0]=0x00000000u;
goto P_0c043802;
P_0c043802: /* original 7f04, guest PC 0x0c043802 */
if(!s->budget--) { s->failed_pc=0x0c043802u; return 0; }
r[15]+=0x00000004u;
goto P_0c043804;
P_0c043804: /* original 4f26, guest PC 0x0c043804 */
if(!s->budget--) { s->failed_pc=0x0c043804u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043806;
P_0c043806: /* original 69f6, guest PC 0x0c043806 */
if(!s->budget--) { s->failed_pc=0x0c043806u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c043808;
P_0c043808: /* original 6af6, guest PC 0x0c043808 */
if(!s->budget--) { s->failed_pc=0x0c043808u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04380a;
P_0c04380a: /* original 6bf6, guest PC 0x0c04380a */
if(!s->budget--) { s->failed_pc=0x0c04380au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04380c;
P_0c04380c: /* original 6cf6, guest PC 0x0c04380c */
if(!s->budget--) { s->failed_pc=0x0c04380cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04380e;
P_0c04380e: /* original 6df6, guest PC 0x0c04380e */
if(!s->budget--) { s->failed_pc=0x0c04380eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043810;
P_0c043810: /* original 000b, guest PC 0x0c043810 */
if(!s->budget--) { s->failed_pc=0x0c043810u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043812: /* original 6ef6, guest PC 0x0c043812 */
if(!s->budget--) { s->failed_pc=0x0c043812u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c043814u,s,ram);
P_0c0460ea: /* original 4f22, guest PC 0x0c0460ea */
if(!s->budget--) { s->failed_pc=0x0c0460eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0460ec;
P_0c0460ec: /* original d33c, guest PC 0x0c0460ec */
if(!s->budget--) { s->failed_pc=0x0c0460ecu; return 0; }
r[3]=read(ram,0x0c0461e0u,4);
goto P_0c0460ee;
P_0c0460ee: /* original d13d, guest PC 0x0c0460ee */
if(!s->budget--) { s->failed_pc=0x0c0460eeu; return 0; }
r[1]=read(ram,0x0c0461e4u,4);
goto P_0c0460f0;
P_0c0460f0: /* original 7ffc, guest PC 0x0c0460f0 */
if(!s->budget--) { s->failed_pc=0x0c0460f0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0460f2;
P_0c0460f2: /* original 6212, guest PC 0x0c0460f2 */
if(!s->budget--) { s->failed_pc=0x0c0460f2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0460f4;
P_0c0460f4: /* original 0002, guest PC 0x0c0460f4 */
if(!s->budget--) { s->failed_pc=0x0c0460f4u; return 0; }
r[0]=r[17];
goto P_0c0460f6;
P_0c0460f6: /* original 2322, guest PC 0x0c0460f6 */
if(!s->budget--) { s->failed_pc=0x0c0460f6u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0460f8;
P_0c0460f8: /* original 4009, guest PC 0x0c0460f8 */
if(!s->budget--) { s->failed_pc=0x0c0460f8u; return 0; }
r[0]>>=2;
goto P_0c0460fa;
P_0c0460fa: /* original 4009, guest PC 0x0c0460fa */
if(!s->budget--) { s->failed_pc=0x0c0460fau; return 0; }
r[0]>>=2;
goto P_0c0460fc;
P_0c0460fc: /* original c90f, guest PC 0x0c0460fc */
if(!s->budget--) { s->failed_pc=0x0c0460fcu; return 0; }
r[0]&=15u;
goto P_0c0460fe;
P_0c0460fe: /* original 2f02, guest PC 0x0c0460fe */
if(!s->budget--) { s->failed_pc=0x0c0460feu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c046100;
P_0c046100: /* original 0002, guest PC 0x0c046100 */
if(!s->budget--) { s->failed_pc=0x0c046100u; return 0; }
r[0]=r[17];
goto P_0c046102;
P_0c046102: /* original 9367, guest PC 0x0c046102 */
if(!s->budget--) { s->failed_pc=0x0c046102u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461d4u,2);
goto P_0c046104;
P_0c046104: /* original 2039, guest PC 0x0c046104 */
if(!s->budget--) { s->failed_pc=0x0c046104u; return 0; }
r[0]&=r[3];
goto P_0c046106;
P_0c046106: /* original cbe0, guest PC 0x0c046106 */
if(!s->budget--) { s->failed_pc=0x0c046106u; return 0; }
r[0]|=224u;
goto P_0c046108;
P_0c046108: /* original 400e, guest PC 0x0c046108 */
if(!s->budget--) { s->failed_pc=0x0c046108u; return 0; }
r[17]=r[0];
goto P_0c04610a;
P_0c04610a: /* original d237, guest PC 0x0c04610a */
if(!s->budget--) { s->failed_pc=0x0c04610au; return 0; }
r[2]=read(ram,0x0c0461e8u,4);
goto P_0c04610c;
P_0c04610c: /* original 6222, guest PC 0x0c04610c */
if(!s->budget--) { s->failed_pc=0x0c04610cu; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c04610e;
P_0c04610e: /* original d037, guest PC 0x0c04610e */
if(!s->budget--) { s->failed_pc=0x0c04610eu; return 0; }
r[0]=read(ram,0x0c0461ecu,4);
goto P_0c046110;
P_0c046110: /* original 6e02, guest PC 0x0c046110 */
if(!s->budget--) { s->failed_pc=0x0c046110u; return 0; }
tmp=read(ram,r[0],4);
r[14]=tmp;
goto P_0c046112;
P_0c046112: /* original d337, guest PC 0x0c046112 */
if(!s->budget--) { s->failed_pc=0x0c046112u; return 0; }
r[3]=read(ram,0x0c0461f0u,4);
goto P_0c046114;
P_0c046114: /* original 6332, guest PC 0x0c046114 */
if(!s->budget--) { s->failed_pc=0x0c046114u; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c046116;
P_0c046116: /* original 925e, guest PC 0x0c046116 */
if(!s->budget--) { s->failed_pc=0x0c046116u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461d6u,2);
goto P_0c046118;
P_0c046118: /* original 22e8, guest PC 0x0c046118 */
if(!s->budget--) { s->failed_pc=0x0c046118u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c04611a;
P_0c04611a: /* original 8901, guest PC 0x0c04611a */
if(!s->budget--) { s->failed_pc=0x0c04611au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046120; }
goto P_0c04611c;
P_0c04611c: /* original bf1f, guest PC 0x0c04611c */
if(!s->budget--) { s->failed_pc=0x0c04611cu; return 0; }
target=0x0c045f5eu; r[16]=0x0c046120u;
r[4]=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046120u) { target=s->pc; goto dispatch; }
goto P_0c046120;
P_0c04611e: /* original e402, guest PC 0x0c04611e */
if(!s->budget--) { s->failed_pc=0x0c04611eu; return 0; }
r[4]=0x00000002u;
goto P_0c046120;
P_0c046120: /* original 935a, guest PC 0x0c046120 */
if(!s->budget--) { s->failed_pc=0x0c046120u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461d8u,2);
goto P_0c046122;
P_0c046122: /* original 23e8, guest PC 0x0c046122 */
if(!s->budget--) { s->failed_pc=0x0c046122u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c046124;
P_0c046124: /* original 8901, guest PC 0x0c046124 */
if(!s->budget--) { s->failed_pc=0x0c046124u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04612a; }
goto P_0c046126;
P_0c046126: /* original bf1a, guest PC 0x0c046126 */
if(!s->budget--) { s->failed_pc=0x0c046126u; return 0; }
target=0x0c045f5eu; r[16]=0x0c04612au;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04612au) { target=s->pc; goto dispatch; }
goto P_0c04612a;
P_0c046128: /* original e403, guest PC 0x0c046128 */
if(!s->budget--) { s->failed_pc=0x0c046128u; return 0; }
r[4]=0x00000003u;
goto P_0c04612a;
P_0c04612a: /* original 9256, guest PC 0x0c04612a */
if(!s->budget--) { s->failed_pc=0x0c04612au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461dau,2);
goto P_0c04612c;
P_0c04612c: /* original 22e8, guest PC 0x0c04612c */
if(!s->budget--) { s->failed_pc=0x0c04612cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c04612e;
P_0c04612e: /* original 8901, guest PC 0x0c04612e */
if(!s->budget--) { s->failed_pc=0x0c04612eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046134; }
goto P_0c046130;
P_0c046130: /* original bf15, guest PC 0x0c046130 */
if(!s->budget--) { s->failed_pc=0x0c046130u; return 0; }
target=0x0c045f5eu; r[16]=0x0c046134u;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046134u) { target=s->pc; goto dispatch; }
goto P_0c046134;
P_0c046132: /* original e404, guest PC 0x0c046132 */
if(!s->budget--) { s->failed_pc=0x0c046132u; return 0; }
r[4]=0x00000004u;
goto P_0c046134;
P_0c046134: /* original d32f, guest PC 0x0c046134 */
if(!s->budget--) { s->failed_pc=0x0c046134u; return 0; }
r[3]=read(ram,0x0c0461f4u,4);
goto P_0c046136;
P_0c046136: /* original 23e8, guest PC 0x0c046136 */
if(!s->budget--) { s->failed_pc=0x0c046136u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c046138;
P_0c046138: /* original 8901, guest PC 0x0c046138 */
if(!s->budget--) { s->failed_pc=0x0c046138u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04613e; }
goto P_0c04613a;
P_0c04613a: /* original bf10, guest PC 0x0c04613a */
if(!s->budget--) { s->failed_pc=0x0c04613au; return 0; }
target=0x0c045f5eu; r[16]=0x0c04613eu;
r[4]=0x00000005u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04613eu) { target=s->pc; goto dispatch; }
goto P_0c04613e;
P_0c04613c: /* original e405, guest PC 0x0c04613c */
if(!s->budget--) { s->failed_pc=0x0c04613cu; return 0; }
r[4]=0x00000005u;
goto P_0c04613e;
P_0c04613e: /* original d22e, guest PC 0x0c04613e */
if(!s->budget--) { s->failed_pc=0x0c04613eu; return 0; }
r[2]=read(ram,0x0c0461f8u,4);
goto P_0c046140;
P_0c046140: /* original 22e8, guest PC 0x0c046140 */
if(!s->budget--) { s->failed_pc=0x0c046140u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c046142;
P_0c046142: /* original 8901, guest PC 0x0c046142 */
if(!s->budget--) { s->failed_pc=0x0c046142u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046148; }
goto P_0c046144;
P_0c046144: /* original bf0b, guest PC 0x0c046144 */
if(!s->budget--) { s->failed_pc=0x0c046144u; return 0; }
target=0x0c045f5eu; r[16]=0x0c046148u;
r[4]=0x00000006u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046148u) { target=s->pc; goto dispatch; }
goto P_0c046148;
P_0c046146: /* original e406, guest PC 0x0c046146 */
if(!s->budget--) { s->failed_pc=0x0c046146u; return 0; }
r[4]=0x00000006u;
goto P_0c046148;
P_0c046148: /* original d32c, guest PC 0x0c046148 */
if(!s->budget--) { s->failed_pc=0x0c046148u; return 0; }
r[3]=read(ram,0x0c0461fcu,4);
goto P_0c04614a;
P_0c04614a: /* original 23e8, guest PC 0x0c04614a */
if(!s->budget--) { s->failed_pc=0x0c04614au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c04614c;
P_0c04614c: /* original 8901, guest PC 0x0c04614c */
if(!s->budget--) { s->failed_pc=0x0c04614cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046152; }
goto P_0c04614e;
P_0c04614e: /* original bf06, guest PC 0x0c04614e */
if(!s->budget--) { s->failed_pc=0x0c04614eu; return 0; }
target=0x0c045f5eu; r[16]=0x0c046152u;
r[4]=0x00000007u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046152u) { target=s->pc; goto dispatch; }
goto P_0c046152;
P_0c046150: /* original e407, guest PC 0x0c046150 */
if(!s->budget--) { s->failed_pc=0x0c046150u; return 0; }
r[4]=0x00000007u;
goto P_0c046152;
P_0c046152: /* original d22b, guest PC 0x0c046152 */
if(!s->budget--) { s->failed_pc=0x0c046152u; return 0; }
r[2]=read(ram,0x0c046200u,4);
goto P_0c046154;
P_0c046154: /* original 2e28, guest PC 0x0c046154 */
if(!s->budget--) { s->failed_pc=0x0c046154u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[2])==0)!=0);
goto P_0c046156;
P_0c046156: /* original 8901, guest PC 0x0c046156 */
if(!s->budget--) { s->failed_pc=0x0c046156u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04615c; }
goto P_0c046158;
P_0c046158: /* original bf01, guest PC 0x0c046158 */
if(!s->budget--) { s->failed_pc=0x0c046158u; return 0; }
target=0x0c045f5eu; r[16]=0x0c04615cu;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04615cu) { target=s->pc; goto dispatch; }
goto P_0c04615c;
P_0c04615a: /* original e408, guest PC 0x0c04615a */
if(!s->budget--) { s->failed_pc=0x0c04615au; return 0; }
r[4]=0x00000008u;
goto P_0c04615c;
P_0c04615c: /* original 60f2, guest PC 0x0c04615c */
if(!s->budget--) { s->failed_pc=0x0c04615cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04615e;
P_0c04615e: /* original 0302, guest PC 0x0c04615e */
if(!s->budget--) { s->failed_pc=0x0c04615eu; return 0; }
r[3]=r[17];
goto P_0c046160;
P_0c046160: /* original 9238, guest PC 0x0c046160 */
if(!s->budget--) { s->failed_pc=0x0c046160u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0461d4u,2);
goto P_0c046162;
P_0c046162: /* original c90f, guest PC 0x0c046162 */
if(!s->budget--) { s->failed_pc=0x0c046162u; return 0; }
r[0]&=15u;
goto P_0c046164;
P_0c046164: /* original 4008, guest PC 0x0c046164 */
if(!s->budget--) { s->failed_pc=0x0c046164u; return 0; }
r[0]<<=2;
goto P_0c046166;
P_0c046166: /* original 2329, guest PC 0x0c046166 */
if(!s->budget--) { s->failed_pc=0x0c046166u; return 0; }
r[3]&=r[2];
goto P_0c046168;
P_0c046168: /* original 4008, guest PC 0x0c046168 */
if(!s->budget--) { s->failed_pc=0x0c046168u; return 0; }
r[0]<<=2;
goto P_0c04616a;
P_0c04616a: /* original 203b, guest PC 0x0c04616a */
if(!s->budget--) { s->failed_pc=0x0c04616au; return 0; }
r[0]|=r[3];
goto P_0c04616c;
P_0c04616c: /* original 400e, guest PC 0x0c04616c */
if(!s->budget--) { s->failed_pc=0x0c04616cu; return 0; }
r[17]=r[0];
goto P_0c04616e;
P_0c04616e: /* original d21d, guest PC 0x0c04616e */
if(!s->budget--) { s->failed_pc=0x0c04616eu; return 0; }
r[2]=read(ram,0x0c0461e4u,4);
goto P_0c046170;
P_0c046170: /* original d124, guest PC 0x0c046170 */
if(!s->budget--) { s->failed_pc=0x0c046170u; return 0; }
r[1]=read(ram,0x0c046204u,4);
goto P_0c046172;
P_0c046172: /* original 6322, guest PC 0x0c046172 */
if(!s->budget--) { s->failed_pc=0x0c046172u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c046174;
P_0c046174: /* original 7f04, guest PC 0x0c046174 */
if(!s->budget--) { s->failed_pc=0x0c046174u; return 0; }
r[15]+=0x00000004u;
goto P_0c046176;
P_0c046176: /* original 2132, guest PC 0x0c046176 */
if(!s->budget--) { s->failed_pc=0x0c046176u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c046178;
P_0c046178: /* original 4f26, guest PC 0x0c046178 */
if(!s->budget--) { s->failed_pc=0x0c046178u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04617a;
P_0c04617a: /* original e000, guest PC 0x0c04617a */
if(!s->budget--) { s->failed_pc=0x0c04617au; return 0; }
r[0]=0x00000000u;
goto P_0c04617c;
P_0c04617c: /* original 000b, guest PC 0x0c04617c */
if(!s->budget--) { s->failed_pc=0x0c04617cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04617e: /* original 6ef6, guest PC 0x0c04617e */
if(!s->budget--) { s->failed_pc=0x0c04617eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046180u,s,ram);
P_0c047340: /* original 4408, guest PC 0x0c047340 */
if(!s->budget--) { s->failed_pc=0x0c047340u; return 0; }
r[4]<<=2;
goto P_0c047342;
P_0c047342: /* original 2fe6, guest PC 0x0c047342 */
if(!s->budget--) { s->failed_pc=0x0c047342u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c047344;
P_0c047344: /* original d371, guest PC 0x0c047344 */
if(!s->budget--) { s->failed_pc=0x0c047344u; return 0; }
r[3]=read(ram,0x0c04750cu,4);
goto P_0c047346;
P_0c047346: /* original 4400, guest PC 0x0c047346 */
if(!s->budget--) { s->failed_pc=0x0c047346u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c047348;
P_0c047348: /* original e601, guest PC 0x0c047348 */
if(!s->budget--) { s->failed_pc=0x0c047348u; return 0; }
r[6]=0x00000001u;
goto P_0c04734a;
P_0c04734a: /* original 6532, guest PC 0x0c04734a */
if(!s->budget--) { s->failed_pc=0x0c04734au; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c04734c;
P_0c04734c: /* original 7ffc, guest PC 0x0c04734c */
if(!s->budget--) { s->failed_pc=0x0c04734cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04734e;
P_0c04734e: /* original 354c, guest PC 0x0c04734e */
if(!s->budget--) { s->failed_pc=0x0c04734eu; return 0; }
r[5]+=r[4];
goto P_0c047350;
P_0c047350: /* original 8552, guest PC 0x0c047350 */
if(!s->budget--) { s->failed_pc=0x0c047350u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+4,2);
goto P_0c047352;
P_0c047352: /* original 3067, guest PC 0x0c047352 */
if(!s->budget--) { s->failed_pc=0x0c047352u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[6])!=0);
goto P_0c047354;
P_0c047354: /* original 8b04, guest PC 0x0c047354 */
if(!s->budget--) { s->failed_pc=0x0c047354u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047360; }
goto P_0c047356;
P_0c047356: /* original 8552, guest PC 0x0c047356 */
if(!s->budget--) { s->failed_pc=0x0c047356u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+4,2);
goto P_0c047358;
P_0c047358: /* original 70ff, guest PC 0x0c047358 */
if(!s->budget--) { s->failed_pc=0x0c047358u; return 0; }
r[0]+=0xffffffffu;
goto P_0c04735a;
P_0c04735a: /* original a025, guest PC 0x0c04735a */
if(!s->budget--) { s->failed_pc=0x0c04735au; return 0; }
write(ram,r[5]+4,r[0],2);
goto P_0c0473a8;
P_0c04735c: /* original 8152, guest PC 0x0c04735c */
if(!s->budget--) { s->failed_pc=0x0c04735cu; return 0; }
write(ram,r[5]+4,r[0],2);
return vf3_matrix_family(0x0c04735eu,s,ram);
P_0c047360: /* original 8453, guest PC 0x0c047360 */
if(!s->budget--) { s->failed_pc=0x0c047360u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c047362;
P_0c047362: /* original e20f, guest PC 0x0c047362 */
if(!s->budget--) { s->failed_pc=0x0c047362u; return 0; }
r[2]=0x0000000fu;
goto P_0c047364;
P_0c047364: /* original 6451, guest PC 0x0c047364 */
if(!s->budget--) { s->failed_pc=0x0c047364u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c047366;
P_0c047366: /* original 6e0c, guest PC 0x0c047366 */
if(!s->budget--) { s->failed_pc=0x0c047366u; return 0; }
r[14]=r[0]&255u;
goto P_0c047368;
P_0c047368: /* original e0ff, guest PC 0x0c047368 */
if(!s->budget--) { s->failed_pc=0x0c047368u; return 0; }
r[0]=0xffffffffu;
goto P_0c04736a;
P_0c04736a: /* original 8153, guest PC 0x0c04736a */
if(!s->budget--) { s->failed_pc=0x0c04736au; return 0; }
write(ram,r[5]+6,r[0],2);
goto P_0c04736c;
P_0c04736c: /* original 2249, guest PC 0x0c04736c */
if(!s->budget--) { s->failed_pc=0x0c04736cu; return 0; }
r[2]&=r[4];
goto P_0c04736e;
P_0c04736e: /* original 2501, guest PC 0x0c04736e */
if(!s->budget--) { s->failed_pc=0x0c04736eu; return 0; }
write(ram,r[5],r[0],2);
goto P_0c047370;
P_0c047370: /* original 8052, guest PC 0x0c047370 */
if(!s->budget--) { s->failed_pc=0x0c047370u; return 0; }
write(ram,r[5]+2,r[0],1);
goto P_0c047372;
P_0c047372: /* original e000, guest PC 0x0c047372 */
if(!s->budget--) { s->failed_pc=0x0c047372u; return 0; }
r[0]=0x00000000u;
goto P_0c047374;
P_0c047374: /* original 8152, guest PC 0x0c047374 */
if(!s->budget--) { s->failed_pc=0x0c047374u; return 0; }
write(ram,r[5]+4,r[0],2);
goto P_0c047376;
P_0c047376: /* original 6563, guest PC 0x0c047376 */
if(!s->budget--) { s->failed_pc=0x0c047376u; return 0; }
r[5]=r[6];
goto P_0c047378;
P_0c047378: /* original 452c, guest PC 0x0c047378 */
if(!s->budget--) { s->failed_pc=0x0c047378u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c04737a;
P_0c04737a: /* original e2fc, guest PC 0x0c04737a */
if(!s->budget--) { s->failed_pc=0x0c04737au; return 0; }
r[2]=0xfffffffcu;
goto P_0c04737c;
P_0c04737c: /* original 442c, guest PC 0x0c04737c */
if(!s->budget--) { s->failed_pc=0x0c04737cu; return 0; }
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[4]>>((-r[2])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[2]&31u);
goto P_0c04737e;
P_0c04737e: /* original 2f42, guest PC 0x0c04737e */
if(!s->budget--) { s->failed_pc=0x0c04737eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c047380;
P_0c047380: /* original 4400, guest PC 0x0c047380 */
if(!s->budget--) { s->failed_pc=0x0c047380u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c047382;
P_0c047382: /* original d260, guest PC 0x0c047382 */
if(!s->budget--) { s->failed_pc=0x0c047382u; return 0; }
r[2]=read(ram,0x0c047504u,4);
goto P_0c047384;
P_0c047384: /* original d762, guest PC 0x0c047384 */
if(!s->budget--) { s->failed_pc=0x0c047384u; return 0; }
r[7]=read(ram,0x0c047510u,4);
goto P_0c047386;
P_0c047386: /* original a00c, guest PC 0x0c047386 */
if(!s->budget--) { s->failed_pc=0x0c047386u; return 0; }
r[4]+=r[2];
goto P_0c0473a2;
P_0c047388: /* original 342c, guest PC 0x0c047388 */
if(!s->budget--) { s->failed_pc=0x0c047388u; return 0; }
r[4]+=r[2];
return vf3_matrix_family(0x0c04738au,s,ram);
P_0c047390: /* original 6241, guest PC 0x0c047390 */
if(!s->budget--) { s->failed_pc=0x0c047390u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c047392;
P_0c047392: /* original 6357, guest PC 0x0c047392 */
if(!s->budget--) { s->failed_pc=0x0c047392u; return 0; }
r[3]=~r[5];
goto P_0c047394;
P_0c047394: /* original 355c, guest PC 0x0c047394 */
if(!s->budget--) { s->failed_pc=0x0c047394u; return 0; }
r[5]+=r[5];
goto P_0c047396;
P_0c047396: /* original 3570, guest PC 0x0c047396 */
if(!s->budget--) { s->failed_pc=0x0c047396u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[7])!=0);
goto P_0c047398;
P_0c047398: /* original 2239, guest PC 0x0c047398 */
if(!s->budget--) { s->failed_pc=0x0c047398u; return 0; }
r[2]&=r[3];
goto P_0c04739a;
P_0c04739a: /* original 8f02, guest PC 0x0c04739a */
if(!s->budget--) { s->failed_pc=0x0c04739au; return 0; }
cond=r[17]&1u;
write(ram,r[4],r[2],2);
if(!cond) { goto P_0c0473a2; }
goto P_0c04739e;
P_0c04739c: /* original 2421, guest PC 0x0c04739c */
if(!s->budget--) { s->failed_pc=0x0c04739cu; return 0; }
write(ram,r[4],r[2],2);
goto P_0c04739e;
P_0c04739e: /* original 7402, guest PC 0x0c04739e */
if(!s->budget--) { s->failed_pc=0x0c04739eu; return 0; }
r[4]+=0x00000002u;
goto P_0c0473a0;
P_0c0473a0: /* original 6563, guest PC 0x0c0473a0 */
if(!s->budget--) { s->failed_pc=0x0c0473a0u; return 0; }
r[5]=r[6];
goto P_0c0473a2;
P_0c0473a2: /* original 4e15, guest PC 0x0c0473a2 */
if(!s->budget--) { s->failed_pc=0x0c0473a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0473a4;
P_0c0473a4: /* original 8df4, guest PC 0x0c0473a4 */
if(!s->budget--) { s->failed_pc=0x0c0473a4u; return 0; }
cond=r[17]&1u;
r[14]+=0xffffffffu;
if(cond) { goto P_0c047390; }
goto P_0c0473a8;
P_0c0473a6: /* original 7eff, guest PC 0x0c0473a6 */
if(!s->budget--) { s->failed_pc=0x0c0473a6u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0473a8;
P_0c0473a8: /* original 7f04, guest PC 0x0c0473a8 */
if(!s->budget--) { s->failed_pc=0x0c0473a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0473aa;
P_0c0473aa: /* original 000b, guest PC 0x0c0473aa */
if(!s->budget--) { s->failed_pc=0x0c0473aau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0473ac: /* original 6ef6, guest PC 0x0c0473ac */
if(!s->budget--) { s->failed_pc=0x0c0473acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0473aeu,s,ram);
P_0c0482f0: /* original 63f3, guest PC 0x0c0482f0 */
if(!s->budget--) { s->failed_pc=0x0c0482f0u; return 0; }
r[3]=r[15];
goto P_0c0482f2;
P_0c0482f2: /* original fb39, guest PC 0x0c0482f2 */
if(!s->budget--) { s->failed_pc=0x0c0482f2u; return 0; }
vf3_matrix_load(s,ram,11,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f4;
P_0c0482f4: /* original f79d, guest PC 0x0c0482f4 */
if(!s->budget--) { s->failed_pc=0x0c0482f4u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0482f6;
P_0c0482f6: /* original f7b5, guest PC 0x0c0482f6 */
if(!s->budget--) { s->failed_pc=0x0c0482f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[11]))!=0);
goto P_0c0482f8;
P_0c0482f8: /* original 6043, guest PC 0x0c0482f8 */
if(!s->budget--) { s->failed_pc=0x0c0482f8u; return 0; }
r[0]=r[4];
goto P_0c0482fa;
P_0c0482fa: /* original 7030, guest PC 0x0c0482fa */
if(!s->budget--) { s->failed_pc=0x0c0482fau; return 0; }
r[0]+=0x00000030u;
goto P_0c0482fc;
P_0c0482fc: /* original 8f15, guest PC 0x0c0482fc */
if(!s->budget--) { s->failed_pc=0x0c0482fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04832a; }
goto P_0c048300;
P_0c0482fe: /* original 0083, guest PC 0x0c0482fe */
if(!s->budget--) { s->failed_pc=0x0c0482feu; return 0; }
goto P_0c048300;
P_0c048300: /* original e202, guest PC 0x0c048300 */
if(!s->budget--) { s->failed_pc=0x0c048300u; return 0; }
r[2]=0x00000002u;
goto P_0c048302;
P_0c048302: /* original f21d, guest PC 0x0c048302 */
if(!s->budget--) { s->failed_pc=0x0c048302u; return 0; }
r[53]=fr[2];
goto P_0c048304;
P_0c048304: /* original 4228, guest PC 0x0c048304 */
if(!s->budget--) { s->failed_pc=0x0c048304u; return 0; }
r[2]<<=16;
goto P_0c048306;
P_0c048306: /* original 005a, guest PC 0x0c048306 */
if(!s->budget--) { s->failed_pc=0x0c048306u; return 0; }
r[0]=r[53];
goto P_0c048308;
P_0c048308: /* original 4218, guest PC 0x0c048308 */
if(!s->budget--) { s->failed_pc=0x0c048308u; return 0; }
r[2]<<=8;
goto P_0c04830a;
P_0c04830a: /* original d9b7, guest PC 0x0c04830a */
if(!s->budget--) { s->failed_pc=0x0c04830au; return 0; }
r[9]=read(ram,0x0c0485e8u,4);
goto P_0c04830c;
P_0c04830c: /* original 282b, guest PC 0x0c04830c */
if(!s->budget--) { s->failed_pc=0x0c04830cu; return 0; }
r[8]|=r[2];
goto P_0c04830e;
P_0c04830e: /* original cbc0, guest PC 0x0c04830e */
if(!s->budget--) { s->failed_pc=0x0c04830eu; return 0; }
r[0]|=192u;
goto P_0c048310;
P_0c048310: /* original 6009, guest PC 0x0c048310 */
if(!s->budget--) { s->failed_pc=0x0c048310u; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c048312;
P_0c048312: /* original 6992, guest PC 0x0c048312 */
if(!s->budget--) { s->failed_pc=0x0c048312u; return 0; }
tmp=read(ram,r[9],4);
r[9]=tmp;
goto P_0c048314;
P_0c048314: /* original cb10, guest PC 0x0c048314 */
if(!s->budget--) { s->failed_pc=0x0c048314u; return 0; }
r[0]|=16u;
goto P_0c048316;
P_0c048316: /* original 6008, guest PC 0x0c048316 */
if(!s->budget--) { s->failed_pc=0x0c048316u; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c048318;
P_0c048318: /* original cbfc, guest PC 0x0c048318 */
if(!s->budget--) { s->failed_pc=0x0c048318u; return 0; }
r[0]|=252u;
goto P_0c04831a;
P_0c04831a: /* original 209a, guest PC 0x0c04831a */
if(!s->budget--) { s->failed_pc=0x0c04831au; return 0; }
r[0]^=r[9];
goto P_0c04831c;
P_0c04831c: /* original 6008, guest PC 0x0c04831c */
if(!s->budget--) { s->failed_pc=0x0c04831cu; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c04831e;
P_0c04831e: /* original 6009, guest PC 0x0c04831e */
if(!s->budget--) { s->failed_pc=0x0c04831eu; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c048320;
P_0c048320: /* original 322c, guest PC 0x0c048320 */
if(!s->budget--) { s->failed_pc=0x0c048320u; return 0; }
r[2]+=r[2];
goto P_0c048322;
P_0c048322: /* original 405a, guest PC 0x0c048322 */
if(!s->budget--) { s->failed_pc=0x0c048322u; return 0; }
r[53]=r[0];
goto P_0c048324;
P_0c048324: /* original 6227, guest PC 0x0c048324 */
if(!s->budget--) { s->failed_pc=0x0c048324u; return 0; }
r[2]=~r[2];
goto P_0c048326;
P_0c048326: /* original f20d, guest PC 0x0c048326 */
if(!s->budget--) { s->failed_pc=0x0c048326u; return 0; }
fr[2]=r[53];
goto P_0c048328;
P_0c048328: /* original 2829, guest PC 0x0c048328 */
if(!s->budget--) { s->failed_pc=0x0c048328u; return 0; }
r[8]&=r[2];
goto P_0c04832a;
P_0c04832a: /* original 6083, guest PC 0x0c04832a */
if(!s->budget--) { s->failed_pc=0x0c04832au; return 0; }
r[0]=r[8];
goto P_0c04832c;
P_0c04832c: /* original f449, guest PC 0x0c04832c */
if(!s->budget--) { s->failed_pc=0x0c04832cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04832e;
P_0c04832e: /* original 4029, guest PC 0x0c04832e */
if(!s->budget--) { s->failed_pc=0x0c04832eu; return 0; }
r[0]>>=16;
goto P_0c048330;
P_0c048330: /* original f549, guest PC 0x0c048330 */
if(!s->budget--) { s->failed_pc=0x0c048330u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048332;
P_0c048332: /* original 4019, guest PC 0x0c048332 */
if(!s->budget--) { s->failed_pc=0x0c048332u; return 0; }
r[0]>>=8;
goto P_0c048334;
P_0c048334: /* original f649, guest PC 0x0c048334 */
if(!s->budget--) { s->failed_pc=0x0c048334u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048336;
P_0c048336: /* original c907, guest PC 0x0c048336 */
if(!s->budget--) { s->failed_pc=0x0c048336u; return 0; }
r[0]&=7u;
goto P_0c048338;
P_0c048338: /* original e204, guest PC 0x0c048338 */
if(!s->budget--) { s->failed_pc=0x0c048338u; return 0; }
r[2]=0x00000004u;
goto P_0c04833a;
P_0c04833a: /* original 4008, guest PC 0x0c04833a */
if(!s->budget--) { s->failed_pc=0x0c04833au; return 0; }
r[0]<<=2;
goto P_0c04833c;
P_0c04833c: /* original f5fd, guest PC 0x0c04833c */
if(!s->budget--) { s->failed_pc=0x0c04833cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c04833e;
P_0c04833e: /* original f139, guest PC 0x0c04833e */
if(!s->budget--) { s->failed_pc=0x0c04833eu; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048340;
P_0c048340: /* original 4218, guest PC 0x0c048340 */
if(!s->budget--) { s->failed_pc=0x0c048340u; return 0; }
r[2]<<=8;
goto P_0c048342;
P_0c048342: /* original f049, guest PC 0x0c048342 */
if(!s->budget--) { s->failed_pc=0x0c048342u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048344;
P_0c048344: /* original 3b00, guest PC 0x0c048344 */
if(!s->budget--) { s->failed_pc=0x0c048344u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[0])!=0);
goto P_0c048346;
P_0c048346: /* original 6b03, guest PC 0x0c048346 */
if(!s->budget--) { s->failed_pc=0x0c048346u; return 0; }
r[11]=r[0];
goto P_0c048348;
P_0c048348: /* original e6e0, guest PC 0x0c048348 */
if(!s->budget--) { s->failed_pc=0x0c048348u; return 0; }
r[6]=0xffffffe0u;
goto P_0c04834a;
P_0c04834a: /* original f012, guest PC 0x0c04834a */
if(!s->budget--) { s->failed_pc=0x0c04834au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c04834c;
P_0c04834c: /* original 4228, guest PC 0x0c04834c */
if(!s->budget--) { s->failed_pc=0x0c04834cu; return 0; }
r[2]<<=16;
goto P_0c04834e;
P_0c04834e: /* original 8d09, guest PC 0x0c04834e */
if(!s->budget--) { s->failed_pc=0x0c04834eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c048364; }
goto P_0c048352;
P_0c048350: /* original 05ae, guest PC 0x0c048350 */
if(!s->budget--) { s->failed_pc=0x0c048350u; return 0; }
r[5]=read(ram,r[10]+r[0],4);
goto P_0c048352;
P_0c048352: /* original e0ff, guest PC 0x0c048352 */
if(!s->budget--) { s->failed_pc=0x0c048352u; return 0; }
r[0]=0xffffffffu;
goto P_0c048354;
P_0c048354: /* original 4028, guest PC 0x0c048354 */
if(!s->budget--) { s->failed_pc=0x0c048354u; return 0; }
r[0]<<=16;
goto P_0c048356;
P_0c048356: /* original 4018, guest PC 0x0c048356 */
if(!s->budget--) { s->failed_pc=0x0c048356u; return 0; }
r[0]<<=8;
goto P_0c048358;
P_0c048358: /* original cb38, guest PC 0x0c048358 */
if(!s->budget--) { s->failed_pc=0x0c048358u; return 0; }
r[0]|=56u;
goto P_0c04835a;
P_0c04835a: /* original 6953, guest PC 0x0c04835a */
if(!s->budget--) { s->failed_pc=0x0c04835au; return 0; }
r[9]=r[5];
goto P_0c04835c;
P_0c04835c: /* original 4929, guest PC 0x0c04835c */
if(!s->budget--) { s->failed_pc=0x0c04835cu; return 0; }
r[9]>>=16;
goto P_0c04835e;
P_0c04835e: /* original 4919, guest PC 0x0c04835e */
if(!s->budget--) { s->failed_pc=0x0c04835eu; return 0; }
r[9]>>=8;
goto P_0c048360;
P_0c048360: /* original 2092, guest PC 0x0c048360 */
if(!s->budget--) { s->failed_pc=0x0c048360u; return 0; }
write(ram,r[0],r[9],4);
goto P_0c048362;
P_0c048362: /* original 1091, guest PC 0x0c048362 */
if(!s->budget--) { s->failed_pc=0x0c048362u; return 0; }
write(ram,r[0]+4,r[9],4);
goto P_0c048364;
P_0c048364: /* original 72ff, guest PC 0x0c048364 */
if(!s->budget--) { s->failed_pc=0x0c048364u; return 0; }
r[2]+=0xffffffffu;
goto P_0c048366;
P_0c048366: /* original 4c5a, guest PC 0x0c048366 */
if(!s->budget--) { s->failed_pc=0x0c048366u; return 0; }
r[53]=r[12];
goto P_0c048368;
P_0c048368: /* original e0fe, guest PC 0x0c048368 */
if(!s->budget--) { s->failed_pc=0x0c048368u; return 0; }
r[0]=0xfffffffeu;
goto P_0c04836a;
P_0c04836a: /* original f700, guest PC 0x0c04836a */
if(!s->budget--) { s->failed_pc=0x0c04836au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'+');
goto P_0c04836c;
P_0c04836c: /* original 2259, guest PC 0x0c04836c */
if(!s->budget--) { s->failed_pc=0x0c04836cu; return 0; }
r[2]&=r[5];
goto P_0c04836e;
P_0c04836e: /* original f10d, guest PC 0x0c04836e */
if(!s->budget--) { s->failed_pc=0x0c04836eu; return 0; }
fr[1]=r[53];
goto P_0c048370;
P_0c048370: /* original 4618, guest PC 0x0c048370 */
if(!s->budget--) { s->failed_pc=0x0c048370u; return 0; }
r[6]<<=8;
goto P_0c048372;
P_0c048372: /* original f715, guest PC 0x0c048372 */
if(!s->budget--) { s->failed_pc=0x0c048372u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c048374;
P_0c048374: /* original 4628, guest PC 0x0c048374 */
if(!s->budget--) { s->failed_pc=0x0c048374u; return 0; }
r[6]<<=16;
goto P_0c048376;
P_0c048376: /* original 262b, guest PC 0x0c048376 */
if(!s->budget--) { s->failed_pc=0x0c048376u; return 0; }
r[6]|=r[2];
goto P_0c048378;
P_0c048378: /* original f701, guest PC 0x0c048378 */
if(!s->budget--) { s->failed_pc=0x0c048378u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c04837a;
P_0c04837a: /* original 2c09, guest PC 0x0c04837a */
if(!s->budget--) { s->failed_pc=0x0c04837au; return 0; }
r[12]&=r[0];
goto P_0c04837c;
P_0c04837c: /* original 59f9, guest PC 0x0c04837c */
if(!s->budget--) { s->failed_pc=0x0c04837cu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c04837e;
P_0c04837e: /* original 8f43, guest PC 0x0c04837e */
if(!s->budget--) { s->failed_pc=0x0c04837eu; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
if(!cond) { goto P_0c048408; }
goto P_0c048382;
P_0c048380: /* original f701, guest PC 0x0c048380 */
if(!s->budget--) { s->failed_pc=0x0c048380u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c048382;
P_0c048382: /* original f715, guest PC 0x0c048382 */
if(!s->budget--) { s->failed_pc=0x0c048382u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c048384;
P_0c048384: /* original 8f40, guest PC 0x0c048384 */
if(!s->budget--) { s->failed_pc=0x0c048384u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c048408; }
goto P_0c048388;
P_0c048386: /* original 7c01, guest PC 0x0c048386 */
if(!s->budget--) { s->failed_pc=0x0c048386u; return 0; }
r[12]+=0x00000001u;
goto P_0c048388;
P_0c048388: /* original 6243, guest PC 0x0c048388 */
if(!s->budget--) { s->failed_pc=0x0c048388u; return 0; }
r[2]=r[4];
goto P_0c04838a;
P_0c04838a: /* original 742c, guest PC 0x0c04838a */
if(!s->budget--) { s->failed_pc=0x0c04838au; return 0; }
r[4]+=0x0000002cu;
goto P_0c04838c;
P_0c04838c: /* original 6046, guest PC 0x0c04838c */
if(!s->budget--) { s->failed_pc=0x0c04838cu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04838e;
P_0c04838e: /* original 2682, guest PC 0x0c04838e */
if(!s->budget--) { s->failed_pc=0x0c04838eu; return 0; }
write(ram,r[6],r[8],4);
goto P_0c048390;
P_0c048390: /* original 6183, guest PC 0x0c048390 */
if(!s->budget--) { s->failed_pc=0x0c048390u; return 0; }
r[1]=r[8];
goto P_0c048392;
P_0c048392: /* original 340c, guest PC 0x0c048392 */
if(!s->budget--) { s->failed_pc=0x0c048392u; return 0; }
r[4]+=r[0];
goto P_0c048394;
P_0c048394: /* original 6846, guest PC 0x0c048394 */
if(!s->budget--) { s->failed_pc=0x0c048394u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[8]=tmp;
goto P_0c048396;
P_0c048396: /* original 2888, guest PC 0x0c048396 */
if(!s->budget--) { s->failed_pc=0x0c048396u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c048398;
P_0c048398: /* original 8b02, guest PC 0x0c048398 */
if(!s->budget--) { s->failed_pc=0x0c048398u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0483a0; }
goto P_0c04839a;
P_0c04839a: /* original a0ef, guest PC 0x0c04839a */
if(!s->budget--) { s->failed_pc=0x0c04839au; return 0; }
goto P_0c04857c;
P_0c04839c: /* original 0009, guest PC 0x0c04839c */
if(!s->budget--) { s->failed_pc=0x0c04839cu; return 0; }
return vf3_matrix_family(0x0c04839eu,s,ram);
P_0c0483a0: /* original 69f3, guest PC 0x0c0483a0 */
if(!s->budget--) { s->failed_pc=0x0c0483a0u; return 0; }
r[9]=r[15];
goto P_0c0483a2;
P_0c0483a2: /* original 7918, guest PC 0x0c0483a2 */
if(!s->budget--) { s->failed_pc=0x0c0483a2u; return 0; }
r[9]+=0x00000018u;
goto P_0c0483a4;
P_0c0483a4: /* original f599, guest PC 0x0c0483a4 */
if(!s->budget--) { s->failed_pc=0x0c0483a4u; return 0; }
vf3_matrix_load(s,ram,5,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483a6;
P_0c0483a6: /* original f699, guest PC 0x0c0483a6 */
if(!s->budget--) { s->failed_pc=0x0c0483a6u; return 0; }
vf3_matrix_load(s,ram,6,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483a8;
P_0c0483a8: /* original 7208, guest PC 0x0c0483a8 */
if(!s->budget--) { s->failed_pc=0x0c0483a8u; return 0; }
r[2]+=0x00000008u;
goto P_0c0483aa;
P_0c0483aa: /* original f799, guest PC 0x0c0483aa */
if(!s->budget--) { s->failed_pc=0x0c0483aau; return 0; }
vf3_matrix_load(s,ram,7,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ac;
P_0c0483ac: /* original 6026, guest PC 0x0c0483ac */
if(!s->budget--) { s->failed_pc=0x0c0483acu; return 0; }
tmp=read(ram,r[2],4);
r[2]+=4;
r[0]=tmp;
goto P_0c0483ae;
P_0c0483ae: /* original c801, guest PC 0x0c0483ae */
if(!s->budget--) { s->failed_pc=0x0c0483aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0483b0;
P_0c0483b0: /* original 6013, guest PC 0x0c0483b0 */
if(!s->budget--) { s->failed_pc=0x0c0483b0u; return 0; }
r[0]=r[1];
goto P_0c0483b2;
P_0c0483b2: /* original 8f24, guest PC 0x0c0483b2 */
if(!s->budget--) { s->failed_pc=0x0c0483b2u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!cond) { goto P_0c0483fe; }
goto P_0c0483b6;
P_0c0483b4: /* original c820, guest PC 0x0c0483b4 */
if(!s->budget--) { s->failed_pc=0x0c0483b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0483b6;
P_0c0483b6: /* original 8922, guest PC 0x0c0483b6 */
if(!s->budget--) { s->failed_pc=0x0c0483b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0483fe; }
goto P_0c0483b8;
P_0c0483b8: /* original f029, guest PC 0x0c0483b8 */
if(!s->budget--) { s->failed_pc=0x0c0483b8u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ba;
P_0c0483ba: /* original f129, guest PC 0x0c0483ba */
if(!s->budget--) { s->failed_pc=0x0c0483bau; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483bc;
P_0c0483bc: /* original f229, guest PC 0x0c0483bc */
if(!s->budget--) { s->failed_pc=0x0c0483bcu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483be;
P_0c0483be: /* original f329, guest PC 0x0c0483be */
if(!s->budget--) { s->failed_pc=0x0c0483beu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483c0;
P_0c0483c0: /* original f0b2, guest PC 0x0c0483c0 */
if(!s->budget--) { s->failed_pc=0x0c0483c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c0483c2;
P_0c0483c2: /* original fb5c, guest PC 0x0c0483c2 */
if(!s->budget--) { s->failed_pc=0x0c0483c2u; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c0483c4;
P_0c0483c4: /* original f152, guest PC 0x0c0483c4 */
if(!s->budget--) { s->failed_pc=0x0c0483c4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c0483c6;
P_0c0483c6: /* original f429, guest PC 0x0c0483c6 */
if(!s->budget--) { s->failed_pc=0x0c0483c6u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483c8;
P_0c0483c8: /* original f529, guest PC 0x0c0483c8 */
if(!s->budget--) { s->failed_pc=0x0c0483c8u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ca;
P_0c0483ca: /* original f5b2, guest PC 0x0c0483ca */
if(!s->budget--) { s->failed_pc=0x0c0483cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c0483cc;
P_0c0483cc: /* original fb6c, guest PC 0x0c0483cc */
if(!s->budget--) { s->failed_pc=0x0c0483ccu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c0483ce;
P_0c0483ce: /* original f262, guest PC 0x0c0483ce */
if(!s->budget--) { s->failed_pc=0x0c0483ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0483d0;
P_0c0483d0: /* original f629, guest PC 0x0c0483d0 */
if(!s->budget--) { s->failed_pc=0x0c0483d0u; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483d2;
P_0c0483d2: /* original f6b2, guest PC 0x0c0483d2 */
if(!s->budget--) { s->failed_pc=0x0c0483d2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c0483d4;
P_0c0483d4: /* original fb7c, guest PC 0x0c0483d4 */
if(!s->budget--) { s->failed_pc=0x0c0483d4u; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c0483d6;
P_0c0483d6: /* original f372, guest PC 0x0c0483d6 */
if(!s->budget--) { s->failed_pc=0x0c0483d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0483d8;
P_0c0483d8: /* original f729, guest PC 0x0c0483d8 */
if(!s->budget--) { s->failed_pc=0x0c0483d8u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483da;
P_0c0483da: /* original f3fd, guest PC 0x0c0483da */
if(!s->budget--) { s->failed_pc=0x0c0483dau; return 0; }
r[18]^=0x100000u;
goto P_0c0483dc;
P_0c0483dc: /* original f7b2, guest PC 0x0c0483dc */
if(!s->budget--) { s->failed_pc=0x0c0483dcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c0483de;
P_0c0483de: /* original e000, guest PC 0x0c0483de */
if(!s->budget--) { s->failed_pc=0x0c0483deu; return 0; }
r[0]=0x00000000u;
goto P_0c0483e0;
P_0c0483e0: /* original 1601, guest PC 0x0c0483e0 */
if(!s->budget--) { s->failed_pc=0x0c0483e0u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0483e2;
P_0c0483e2: /* original 1602, guest PC 0x0c0483e2 */
if(!s->budget--) { s->failed_pc=0x0c0483e2u; return 0; }
write(ram,r[6]+8,r[0],4);
goto P_0c0483e4;
P_0c0483e4: /* original 1603, guest PC 0x0c0483e4 */
if(!s->budget--) { s->failed_pc=0x0c0483e4u; return 0; }
write(ram,r[6]+12,r[0],4);
goto P_0c0483e6;
P_0c0483e6: /* original 0683, guest PC 0x0c0483e6 */
if(!s->budget--) { s->failed_pc=0x0c0483e6u; return 0; }
goto P_0c0483e8;
P_0c0483e8: /* original 7640, guest PC 0x0c0483e8 */
if(!s->budget--) { s->failed_pc=0x0c0483e8u; return 0; }
r[6]+=0x00000040u;
goto P_0c0483ea;
P_0c0483ea: /* original f66b, guest PC 0x0c0483ea */
if(!s->budget--) { s->failed_pc=0x0c0483eau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c0483ec;
P_0c0483ec: /* original f64b, guest PC 0x0c0483ec */
if(!s->budget--) { s->failed_pc=0x0c0483ecu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0483ee;
P_0c0483ee: /* original 60b3, guest PC 0x0c0483ee */
if(!s->budget--) { s->failed_pc=0x0c0483eeu; return 0; }
r[0]=r[11];
goto P_0c0483f0;
P_0c0483f0: /* original f62b, guest PC 0x0c0483f0 */
if(!s->budget--) { s->failed_pc=0x0c0483f0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0483f2;
P_0c0483f2: /* original 7540, guest PC 0x0c0483f2 */
if(!s->budget--) { s->failed_pc=0x0c0483f2u; return 0; }
r[5]+=0x00000040u;
goto P_0c0483f4;
P_0c0483f4: /* original f60b, guest PC 0x0c0483f4 */
if(!s->budget--) { s->failed_pc=0x0c0483f4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c0483f6;
P_0c0483f6: /* original f3fd, guest PC 0x0c0483f6 */
if(!s->budget--) { s->failed_pc=0x0c0483f6u; return 0; }
r[18]^=0x100000u;
goto P_0c0483f8;
P_0c0483f8: /* original 0683, guest PC 0x0c0483f8 */
if(!s->budget--) { s->failed_pc=0x0c0483f8u; return 0; }
goto P_0c0483fa;
P_0c0483fa: /* original 7620, guest PC 0x0c0483fa */
if(!s->budget--) { s->failed_pc=0x0c0483fau; return 0; }
r[6]+=0x00000020u;
goto P_0c0483fc;
P_0c0483fc: /* original 0a56, guest PC 0x0c0483fc */
if(!s->budget--) { s->failed_pc=0x0c0483fcu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0483fe;
P_0c0483fe: /* original 6146, guest PC 0x0c0483fe */
if(!s->budget--) { s->failed_pc=0x0c0483feu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c048400;
P_0c048400: /* original f249, guest PC 0x0c048400 */
if(!s->budget--) { s->failed_pc=0x0c048400u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048402;
P_0c048402: /* original af75, guest PC 0x0c048402 */
if(!s->budget--) { s->failed_pc=0x0c048402u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c048404: /* original f349, guest PC 0x0c048404 */
if(!s->budget--) { s->failed_pc=0x0c048404u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c048406u,s,ram);
P_0c048408: /* original f139, guest PC 0x0c048408 */
if(!s->budget--) { s->failed_pc=0x0c048408u; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04840a;
P_0c04840a: /* original 7910, guest PC 0x0c04840a */
if(!s->budget--) { s->failed_pc=0x0c04840au; return 0; }
r[9]+=0x00000010u;
goto P_0c04840c;
P_0c04840c: /* original f04d, guest PC 0x0c04840c */
if(!s->budget--) { s->failed_pc=0x0c04840cu; return 0; }
fr[0]^=0x80000000u;
goto P_0c04840e;
P_0c04840e: /* original f102, guest PC 0x0c04840e */
if(!s->budget--) { s->failed_pc=0x0c04840eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c048410;
P_0c048410: /* original f93b, guest PC 0x0c048410 */
if(!s->budget--) { s->failed_pc=0x0c048410u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c048412;
P_0c048412: /* original 6243, guest PC 0x0c048412 */
if(!s->budget--) { s->failed_pc=0x0c048412u; return 0; }
r[2]=r[4];
goto P_0c048414;
P_0c048414: /* original f339, guest PC 0x0c048414 */
if(!s->budget--) { s->failed_pc=0x0c048414u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048416;
P_0c048416: /* original f515, guest PC 0x0c048416 */
if(!s->budget--) { s->failed_pc=0x0c048416u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[1]))!=0);
goto P_0c048418;
P_0c048418: /* original f92b, guest PC 0x0c048418 */
if(!s->budget--) { s->failed_pc=0x0c048418u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[9]);
goto P_0c04841a;
P_0c04841a: /* original f302, guest PC 0x0c04841a */
if(!s->budget--) { s->failed_pc=0x0c04841au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c04841c;
P_0c04841c: /* original f039, guest PC 0x0c04841c */
if(!s->budget--) { s->failed_pc=0x0c04841cu; return 0; }
vf3_matrix_load(s,ram,0,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04841e;
P_0c04841e: /* original 8fb3, guest PC 0x0c04841e */
if(!s->budget--) { s->failed_pc=0x0c04841eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
if(!cond) { goto P_0c048388; }
goto P_0c048422;
P_0c048420: /* original f635, guest PC 0x0c048420 */
if(!s->budget--) { s->failed_pc=0x0c048420u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
goto P_0c048422;
P_0c048422: /* original f739, guest PC 0x0c048422 */
if(!s->budget--) { s->failed_pc=0x0c048422u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048424;
P_0c048424: /* original f042, guest PC 0x0c048424 */
if(!s->budget--) { s->failed_pc=0x0c048424u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c048426;
P_0c048426: /* original 5022, guest PC 0x0c048426 */
if(!s->budget--) { s->failed_pc=0x0c048426u; return 0; }
r[0]=read(ram,r[2]+8,4);
goto P_0c048428;
P_0c048428: /* original f011, guest PC 0x0c048428 */
if(!s->budget--) { s->failed_pc=0x0c048428u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c04842a;
P_0c04842a: /* original 8fad, guest PC 0x0c04842a */
if(!s->budget--) { s->failed_pc=0x0c04842au; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
if(!cond) { goto P_0c048388; }
goto P_0c04842e;
P_0c04842c: /* original f505, guest PC 0x0c04842c */
if(!s->budget--) { s->failed_pc=0x0c04842cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
goto P_0c04842e;
P_0c04842e: /* original f539, guest PC 0x0c04842e */
if(!s->budget--) { s->failed_pc=0x0c04842eu; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048430;
P_0c048430: /* original f742, guest PC 0x0c048430 */
if(!s->budget--) { s->failed_pc=0x0c048430u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c048432;
P_0c048432: /* original 8da9, guest PC 0x0c048432 */
if(!s->budget--) { s->failed_pc=0x0c048432u; return 0; }
cond=r[17]&1u;
r[9]-=4; write(ram,r[9],r[1],4);
if(cond) { goto P_0c048388; }
goto P_0c048436;
P_0c048434: /* original 2916, guest PC 0x0c048434 */
if(!s->budget--) { s->failed_pc=0x0c048434u; return 0; }
r[9]-=4; write(ram,r[9],r[1],4);
goto P_0c048436;
P_0c048436: /* original f731, guest PC 0x0c048436 */
if(!s->budget--) { s->failed_pc=0x0c048436u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c048438;
P_0c048438: /* original 2986, guest PC 0x0c048438 */
if(!s->budget--) { s->failed_pc=0x0c048438u; return 0; }
r[9]-=4; write(ram,r[9],r[8],4);
goto P_0c04843a;
P_0c04843a: /* original e108, guest PC 0x0c04843a */
if(!s->budget--) { s->failed_pc=0x0c04843au; return 0; }
r[1]=0x00000008u;
goto P_0c04843c;
P_0c04843c: /* original f675, guest PC 0x0c04843c */
if(!s->budget--) { s->failed_pc=0x0c04843cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c04843e;
P_0c04843e: /* original f639, guest PC 0x0c04843e */
if(!s->budget--) { s->failed_pc=0x0c04843eu; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048440;
P_0c048440: /* original 89a2, guest PC 0x0c048440 */
if(!s->budget--) { s->failed_pc=0x0c048440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c048388; }
goto P_0c048442;
P_0c048442: /* original c801, guest PC 0x0c048442 */
if(!s->budget--) { s->failed_pc=0x0c048442u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c048444;
P_0c048444: /* original 8424, guest PC 0x0c048444 */
if(!s->budget--) { s->failed_pc=0x0c048444u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+4,1);
goto P_0c048446;
P_0c048446: /* original 7208, guest PC 0x0c048446 */
if(!s->budget--) { s->failed_pc=0x0c048446u; return 0; }
r[2]+=0x00000008u;
goto P_0c048448;
P_0c048448: /* original f739, guest PC 0x0c048448 */
if(!s->budget--) { s->failed_pc=0x0c048448u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04844a;
P_0c04844a: /* original 6803, guest PC 0x0c04844a */
if(!s->budget--) { s->failed_pc=0x0c04844au; return 0; }
r[8]=r[0];
goto P_0c04844c;
P_0c04844c: /* original ff29, guest PC 0x0c04844c */
if(!s->budget--) { s->failed_pc=0x0c04844cu; return 0; }
vf3_matrix_load(s,ram,15,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04844e;
P_0c04844e: /* original 8f1a, guest PC 0x0c04844e */
if(!s->budget--) { s->failed_pc=0x0c04844eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000030u;
if(!cond) { goto P_0c048486; }
goto P_0c048452;
P_0c048450: /* original 7430, guest PC 0x0c048450 */
if(!s->budget--) { s->failed_pc=0x0c048450u; return 0; }
r[4]+=0x00000030u;
goto P_0c048452;
P_0c048452: /* original f029, guest PC 0x0c048452 */
if(!s->budget--) { s->failed_pc=0x0c048452u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048454;
P_0c048454: /* original f129, guest PC 0x0c048454 */
if(!s->budget--) { s->failed_pc=0x0c048454u; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048456;
P_0c048456: /* original f229, guest PC 0x0c048456 */
if(!s->budget--) { s->failed_pc=0x0c048456u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048458;
P_0c048458: /* original f329, guest PC 0x0c048458 */
if(!s->budget--) { s->failed_pc=0x0c048458u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04845a;
P_0c04845a: /* original f0b2, guest PC 0x0c04845a */
if(!s->budget--) { s->failed_pc=0x0c04845au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c04845c;
P_0c04845c: /* original fb5c, guest PC 0x0c04845c */
if(!s->budget--) { s->failed_pc=0x0c04845cu; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c04845e;
P_0c04845e: /* original f152, guest PC 0x0c04845e */
if(!s->budget--) { s->failed_pc=0x0c04845eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c048460;
P_0c048460: /* original f429, guest PC 0x0c048460 */
if(!s->budget--) { s->failed_pc=0x0c048460u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048462;
P_0c048462: /* original f529, guest PC 0x0c048462 */
if(!s->budget--) { s->failed_pc=0x0c048462u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048464;
P_0c048464: /* original f5b2, guest PC 0x0c048464 */
if(!s->budget--) { s->failed_pc=0x0c048464u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c048466;
P_0c048466: /* original fb6c, guest PC 0x0c048466 */
if(!s->budget--) { s->failed_pc=0x0c048466u; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c048468;
P_0c048468: /* original f262, guest PC 0x0c048468 */
if(!s->budget--) { s->failed_pc=0x0c048468u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c04846a;
P_0c04846a: /* original f629, guest PC 0x0c04846a */
if(!s->budget--) { s->failed_pc=0x0c04846au; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04846c;
P_0c04846c: /* original f6b2, guest PC 0x0c04846c */
if(!s->budget--) { s->failed_pc=0x0c04846cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c04846e;
P_0c04846e: /* original fb7c, guest PC 0x0c04846e */
if(!s->budget--) { s->failed_pc=0x0c04846eu; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c048470;
P_0c048470: /* original f372, guest PC 0x0c048470 */
if(!s->budget--) { s->failed_pc=0x0c048470u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c048472;
P_0c048472: /* original f729, guest PC 0x0c048472 */
if(!s->budget--) { s->failed_pc=0x0c048472u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048474;
P_0c048474: /* original 7640, guest PC 0x0c048474 */
if(!s->budget--) { s->failed_pc=0x0c048474u; return 0; }
r[6]+=0x00000040u;
goto P_0c048476;
P_0c048476: /* original f7b2, guest PC 0x0c048476 */
if(!s->budget--) { s->failed_pc=0x0c048476u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c048478;
P_0c048478: /* original f3fd, guest PC 0x0c048478 */
if(!s->budget--) { s->failed_pc=0x0c048478u; return 0; }
r[18]^=0x100000u;
goto P_0c04847a;
P_0c04847a: /* original f66b, guest PC 0x0c04847a */
if(!s->budget--) { s->failed_pc=0x0c04847au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04847c;
P_0c04847c: /* original f64b, guest PC 0x0c04847c */
if(!s->budget--) { s->failed_pc=0x0c04847cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04847e;
P_0c04847e: /* original f62b, guest PC 0x0c04847e */
if(!s->budget--) { s->failed_pc=0x0c04847eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048480;
P_0c048480: /* original f60b, guest PC 0x0c048480 */
if(!s->budget--) { s->failed_pc=0x0c048480u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c048482;
P_0c048482: /* original f3fd, guest PC 0x0c048482 */
if(!s->budget--) { s->failed_pc=0x0c048482u; return 0; }
r[18]^=0x100000u;
goto P_0c048484;
P_0c048484: /* original 76e0, guest PC 0x0c048484 */
if(!s->budget--) { s->failed_pc=0x0c048484u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c048486;
P_0c048486: /* original 4811, guest PC 0x0c048486 */
if(!s->budget--) { s->failed_pc=0x0c048486u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=0)!=0);
goto P_0c048488;
P_0c048488: /* original 4d5a, guest PC 0x0c048488 */
if(!s->budget--) { s->failed_pc=0x0c048488u; return 0; }
r[53]=r[13];
goto P_0c04848a;
P_0c04848a: /* original 891b, guest PC 0x0c04848a */
if(!s->budget--) { s->failed_pc=0x0c04848au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0484c4; }
goto P_0c04848c;
P_0c04848c: /* original 6083, guest PC 0x0c04848c */
if(!s->budget--) { s->failed_pc=0x0c04848cu; return 0; }
r[0]=r[8];
goto P_0c04848e;
P_0c04848e: /* original 88ff, guest PC 0x0c04848e */
if(!s->budget--) { s->failed_pc=0x0c04848eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c048490;
P_0c048490: /* original 8d14, guest PC 0x0c048490 */
if(!s->budget--) { s->failed_pc=0x0c048490u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
if(cond) { goto P_0c0484bc; }
goto P_0c048494;
P_0c048492: /* original 88fe, guest PC 0x0c048492 */
if(!s->budget--) { s->failed_pc=0x0c048492u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c048494;
P_0c048494: /* original 8b08, guest PC 0x0c048494 */
if(!s->budget--) { s->failed_pc=0x0c048494u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0484a8; }
goto P_0c048496;
P_0c048496: /* original d052, guest PC 0x0c048496 */
if(!s->budget--) { s->failed_pc=0x0c048496u; return 0; }
r[0]=read(ram,0x0c0485e0u,4);
goto P_0c048498;
P_0c048498: /* original 400b, guest PC 0x0c048498 */
if(!s->budget--) { s->failed_pc=0x0c048498u; return 0; }
target=r[0];
r[16]=0x0c04849cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04849cu) { target=s->pc; goto dispatch; }
goto P_0c04849c;
P_0c04849a: /* original 0009, guest PC 0x0c04849a */
if(!s->budget--) { s->failed_pc=0x0c04849au; return 0; }
goto P_0c04849c;
P_0c04849c: /* original 896e, guest PC 0x0c04849c */
if(!s->budget--) { s->failed_pc=0x0c04849cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c04849e;
P_0c04849e: /* original 6146, guest PC 0x0c04849e */
if(!s->budget--) { s->failed_pc=0x0c04849eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484a0;
P_0c0484a0: /* original f249, guest PC 0x0c0484a0 */
if(!s->budget--) { s->failed_pc=0x0c0484a0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484a2;
P_0c0484a2: /* original af25, guest PC 0x0c0484a2 */
if(!s->budget--) { s->failed_pc=0x0c0484a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484a4: /* original f349, guest PC 0x0c0484a4 */
if(!s->budget--) { s->failed_pc=0x0c0484a4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c0484a6u,s,ram);
P_0c0484a8: /* original 88fd, guest PC 0x0c0484a8 */
if(!s->budget--) { s->failed_pc=0x0c0484a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffdu)!=0);
goto P_0c0484aa;
P_0c0484aa: /* original 8b07, guest PC 0x0c0484aa */
if(!s->budget--) { s->failed_pc=0x0c0484aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0484bc; }
goto P_0c0484ac;
P_0c0484ac: /* original d04d, guest PC 0x0c0484ac */
if(!s->budget--) { s->failed_pc=0x0c0484acu; return 0; }
r[0]=read(ram,0x0c0485e4u,4);
goto P_0c0484ae;
P_0c0484ae: /* original 400b, guest PC 0x0c0484ae */
if(!s->budget--) { s->failed_pc=0x0c0484aeu; return 0; }
target=r[0];
r[16]=0x0c0484b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0484b2u) { target=s->pc; goto dispatch; }
goto P_0c0484b2;
P_0c0484b0: /* original 0009, guest PC 0x0c0484b0 */
if(!s->budget--) { s->failed_pc=0x0c0484b0u; return 0; }
goto P_0c0484b2;
P_0c0484b2: /* original 8963, guest PC 0x0c0484b2 */
if(!s->budget--) { s->failed_pc=0x0c0484b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c0484b4;
P_0c0484b4: /* original 6146, guest PC 0x0c0484b4 */
if(!s->budget--) { s->failed_pc=0x0c0484b4u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484b6;
P_0c0484b6: /* original f249, guest PC 0x0c0484b6 */
if(!s->budget--) { s->failed_pc=0x0c0484b6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484b8;
P_0c0484b8: /* original af1a, guest PC 0x0c0484b8 */
if(!s->budget--) { s->failed_pc=0x0c0484b8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484ba: /* original f349, guest PC 0x0c0484ba */
if(!s->budget--) { s->failed_pc=0x0c0484bau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484bc;
P_0c0484bc: /* original e800, guest PC 0x0c0484bc */
if(!s->budget--) { s->failed_pc=0x0c0484bcu; return 0; }
r[8]=0x00000000u;
goto P_0c0484be;
P_0c0484be: /* original a00b, guest PC 0x0c0484be */
if(!s->budget--) { s->failed_pc=0x0c0484beu; return 0; }
fr[15]=0x3f800000u;
goto P_0c0484d8;
P_0c0484c0: /* original ff9d, guest PC 0x0c0484c0 */
if(!s->budget--) { s->failed_pc=0x0c0484c0u; return 0; }
fr[15]=0x3f800000u;
return vf3_matrix_family(0x0c0484c2u,s,ram);
P_0c0484c4: /* original 3817, guest PC 0x0c0484c4 */
if(!s->budget--) { s->failed_pc=0x0c0484c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>(int32_t)r[1])!=0);
goto P_0c0484c6;
P_0c0484c6: /* original f10d, guest PC 0x0c0484c6 */
if(!s->budget--) { s->failed_pc=0x0c0484c6u; return 0; }
fr[1]=r[53];
goto P_0c0484c8;
P_0c0484c8: /* original 4808, guest PC 0x0c0484c8 */
if(!s->budget--) { s->failed_pc=0x0c0484c8u; return 0; }
r[8]<<=2;
goto P_0c0484ca;
P_0c0484ca: /* original 8f05, guest PC 0x0c0484ca */
if(!s->budget--) { s->failed_pc=0x0c0484cau; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
if(!cond) { goto P_0c0484d8; }
goto P_0c0484ce;
P_0c0484cc: /* original ff12, guest PC 0x0c0484cc */
if(!s->budget--) { s->failed_pc=0x0c0484ccu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
goto P_0c0484ce;
P_0c0484ce: /* original 6083, guest PC 0x0c0484ce */
if(!s->budget--) { s->failed_pc=0x0c0484ceu; return 0; }
r[0]=r[8];
goto P_0c0484d0;
P_0c0484d0: /* original 8840, guest PC 0x0c0484d0 */
if(!s->budget--) { s->failed_pc=0x0c0484d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0484d2;
P_0c0484d2: /* original e824, guest PC 0x0c0484d2 */
if(!s->budget--) { s->failed_pc=0x0c0484d2u; return 0; }
r[8]=0x00000024u;
goto P_0c0484d4;
P_0c0484d4: /* original 8900, guest PC 0x0c0484d4 */
if(!s->budget--) { s->failed_pc=0x0c0484d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0484d8; }
goto P_0c0484d6;
P_0c0484d6: /* original e828, guest PC 0x0c0484d6 */
if(!s->budget--) { s->failed_pc=0x0c0484d6u; return 0; }
r[8]=0x00000028u;
goto P_0c0484d8;
P_0c0484d8: /* original 6046, guest PC 0x0c0484d8 */
if(!s->budget--) { s->failed_pc=0x0c0484d8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0484da: /* original 4015, guest PC 0x0c0484da */
if(!s->budget--) { s->failed_pc=0x0c0484dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0484dc;
P_0c0484dc: /* original 59f9, guest PC 0x0c0484dc */
if(!s->budget--) { s->failed_pc=0x0c0484dcu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c0484de;
P_0c0484de: /* original 8d09, guest PC 0x0c0484de */
if(!s->budget--) { s->failed_pc=0x0c0484deu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
if(cond) { goto P_0c0484f4; }
goto P_0c0484e2;
P_0c0484e0: /* original 4011, guest PC 0x0c0484e0 */
if(!s->budget--) { s->failed_pc=0x0c0484e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0484e2;
P_0c0484e2: /* original 6803, guest PC 0x0c0484e2 */
if(!s->budget--) { s->failed_pc=0x0c0484e2u; return 0; }
r[8]=r[0];
goto P_0c0484e4;
P_0c0484e4: /* original 60b3, guest PC 0x0c0484e4 */
if(!s->budget--) { s->failed_pc=0x0c0484e4u; return 0; }
r[0]=r[11];
goto P_0c0484e6;
P_0c0484e6: /* original 0a56, guest PC 0x0c0484e6 */
if(!s->budget--) { s->failed_pc=0x0c0484e6u; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0484e8;
P_0c0484e8: /* original 8948, guest PC 0x0c0484e8 */
if(!s->budget--) { s->failed_pc=0x0c0484e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c0484ea;
P_0c0484ea: /* original 6146, guest PC 0x0c0484ea */
if(!s->budget--) { s->failed_pc=0x0c0484eau; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484ec;
P_0c0484ec: /* original f249, guest PC 0x0c0484ec */
if(!s->budget--) { s->failed_pc=0x0c0484ecu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484ee;
P_0c0484ee: /* original aeff, guest PC 0x0c0484ee */
if(!s->budget--) { s->failed_pc=0x0c0484eeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484f0: /* original f349, guest PC 0x0c0484f0 */
if(!s->budget--) { s->failed_pc=0x0c0484f0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c0484f2u,s,ram);
P_0c0484f4: /* original 6103, guest PC 0x0c0484f4 */
if(!s->budget--) { s->failed_pc=0x0c0484f4u; return 0; }
r[1]=r[0];
goto P_0c0484f6;
P_0c0484f6: /* original e2fb, guest PC 0x0c0484f6 */
if(!s->budget--) { s->failed_pc=0x0c0484f6u; return 0; }
r[2]=0xfffffffbu;
goto P_0c0484f8;
P_0c0484f8: /* original 6396, guest PC 0x0c0484f8 */
if(!s->budget--) { s->failed_pc=0x0c0484f8u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[3]=tmp;
goto P_0c0484fa;
P_0c0484fa: /* original c940, guest PC 0x0c0484fa */
if(!s->budget--) { s->failed_pc=0x0c0484fau; return 0; }
r[0]&=64u;
goto P_0c0484fc;
P_0c0484fc: /* original 402d, guest PC 0x0c0484fc */
if(!s->budget--) { s->failed_pc=0x0c0484fcu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c0484fe;
P_0c0484fe: /* original e2fd, guest PC 0x0c0484fe */
if(!s->budget--) { s->failed_pc=0x0c0484feu; return 0; }
r[2]=0xfffffffdu;
goto P_0c048500;
P_0c048500: /* original 2329, guest PC 0x0c048500 */
if(!s->budget--) { s->failed_pc=0x0c048500u; return 0; }
r[3]&=r[2];
goto P_0c048502;
P_0c048502: /* original 203b, guest PC 0x0c048502 */
if(!s->budget--) { s->failed_pc=0x0c048502u; return 0; }
r[0]|=r[3];
goto P_0c048504;
P_0c048504: /* original c810, guest PC 0x0c048504 */
if(!s->budget--) { s->failed_pc=0x0c048504u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c048506;
P_0c048506: /* original 7420, guest PC 0x0c048506 */
if(!s->budget--) { s->failed_pc=0x0c048506u; return 0; }
r[4]+=0x00000020u;
goto P_0c048508;
P_0c048508: /* original 8f03, guest PC 0x0c048508 */
if(!s->budget--) { s->failed_pc=0x0c048508u; return 0; }
cond=r[17]&1u;
r[53]=r[0];
if(!cond) { goto P_0c048512; }
goto P_0c04850c;
P_0c04850a: /* original 405a, guest PC 0x0c04850a */
if(!s->budget--) { s->failed_pc=0x0c04850au; return 0; }
r[53]=r[0];
goto P_0c04850c;
P_0c04850c: /* original cb10, guest PC 0x0c04850c */
if(!s->budget--) { s->failed_pc=0x0c04850cu; return 0; }
r[0]|=16u;
goto P_0c04850e;
P_0c04850e: /* original 6293, guest PC 0x0c04850e */
if(!s->budget--) { s->failed_pc=0x0c04850eu; return 0; }
r[2]=r[9];
goto P_0c048510;
P_0c048510: /* original 2206, guest PC 0x0c048510 */
if(!s->budget--) { s->failed_pc=0x0c048510u; return 0; }
r[2]-=4; write(ram,r[2],r[0],4);
goto P_0c048512;
P_0c048512: /* original 6013, guest PC 0x0c048512 */
if(!s->budget--) { s->failed_pc=0x0c048512u; return 0; }
r[0]=r[1];
goto P_0c048514;
P_0c048514: /* original e21b, guest PC 0x0c048514 */
if(!s->budget--) { s->failed_pc=0x0c048514u; return 0; }
r[2]=0x0000001bu;
goto P_0c048516;
P_0c048516: /* original c903, guest PC 0x0c048516 */
if(!s->budget--) { s->failed_pc=0x0c048516u; return 0; }
r[0]&=3u;
goto P_0c048518;
P_0c048518: /* original 402d, guest PC 0x0c048518 */
if(!s->budget--) { s->failed_pc=0x0c048518u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c04851a;
P_0c04851a: /* original e303, guest PC 0x0c04851a */
if(!s->budget--) { s->failed_pc=0x0c04851au; return 0; }
r[3]=0x00000003u;
goto P_0c04851c;
P_0c04851c: /* original f3fd, guest PC 0x0c04851c */
if(!s->budget--) { s->failed_pc=0x0c04851cu; return 0; }
r[18]^=0x100000u;
goto P_0c04851e;
P_0c04851e: /* original 432d, guest PC 0x0c04851e */
if(!s->budget--) { s->failed_pc=0x0c04851eu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c048520;
P_0c048520: /* original 0483, guest PC 0x0c048520 */
if(!s->budget--) { s->failed_pc=0x0c048520u; return 0; }
goto P_0c048522;
P_0c048522: /* original 6337, guest PC 0x0c048522 */
if(!s->budget--) { s->failed_pc=0x0c048522u; return 0; }
r[3]=~r[3];
goto P_0c048524;
P_0c048524: /* original 6296, guest PC 0x0c048524 */
if(!s->budget--) { s->failed_pc=0x0c048524u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[2]=tmp;
goto P_0c048526;
P_0c048526: /* original 2239, guest PC 0x0c048526 */
if(!s->budget--) { s->failed_pc=0x0c048526u; return 0; }
r[2]&=r[3];
goto P_0c048528;
P_0c048528: /* original f00d, guest PC 0x0c048528 */
if(!s->budget--) { s->failed_pc=0x0c048528u; return 0; }
fr[0]=r[53];
goto P_0c04852a;
P_0c04852a: /* original 220b, guest PC 0x0c04852a */
if(!s->budget--) { s->failed_pc=0x0c04852au; return 0; }
r[2]|=r[0];
goto P_0c04852c;
P_0c04852c: /* original 425a, guest PC 0x0c04852c */
if(!s->budget--) { s->failed_pc=0x0c04852cu; return 0; }
r[53]=r[2];
goto P_0c04852e;
P_0c04852e: /* original 74e0, guest PC 0x0c04852e */
if(!s->budget--) { s->failed_pc=0x0c04852eu; return 0; }
r[4]+=0xffffffe0u;
goto P_0c048530;
P_0c048530: /* original f10d, guest PC 0x0c048530 */
if(!s->budget--) { s->failed_pc=0x0c048530u; return 0; }
fr[1]=r[53];
goto P_0c048532;
P_0c048532: /* original 7610, guest PC 0x0c048532 */
if(!s->budget--) { s->failed_pc=0x0c048532u; return 0; }
r[6]+=0x00000010u;
goto P_0c048534;
P_0c048534: /* original f299, guest PC 0x0c048534 */
if(!s->budget--) { s->failed_pc=0x0c048534u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c048536;
P_0c048536: /* original f62b, guest PC 0x0c048536 */
if(!s->budget--) { s->failed_pc=0x0c048536u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048538;
P_0c048538: /* original 7520, guest PC 0x0c048538 */
if(!s->budget--) { s->failed_pc=0x0c048538u; return 0; }
r[5]+=0x00000020u;
goto P_0c04853a;
P_0c04853a: /* original f60b, guest PC 0x0c04853a */
if(!s->budget--) { s->failed_pc=0x0c04853au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c04853c;
P_0c04853c: /* original f3fd, guest PC 0x0c04853c */
if(!s->budget--) { s->failed_pc=0x0c04853cu; return 0; }
r[18]^=0x100000u;
goto P_0c04853e;
P_0c04853e: /* original 0683, guest PC 0x0c04853e */
if(!s->budget--) { s->failed_pc=0x0c04853eu; return 0; }
goto P_0c048540;
P_0c048540: /* original 8f03, guest PC 0x0c048540 */
if(!s->budget--) { s->failed_pc=0x0c048540u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000020u;
if(!cond) { goto P_0c04854a; }
goto P_0c048544;
P_0c048542: /* original 7620, guest PC 0x0c048542 */
if(!s->budget--) { s->failed_pc=0x0c048542u; return 0; }
r[6]+=0x00000020u;
goto P_0c048544;
P_0c048544: /* original 0683, guest PC 0x0c048544 */
if(!s->budget--) { s->failed_pc=0x0c048544u; return 0; }
goto P_0c048546;
P_0c048546: /* original 7620, guest PC 0x0c048546 */
if(!s->budget--) { s->failed_pc=0x0c048546u; return 0; }
r[6]+=0x00000020u;
goto P_0c048548;
P_0c048548: /* original 7520, guest PC 0x0c048548 */
if(!s->budget--) { s->failed_pc=0x0c048548u; return 0; }
r[5]+=0x00000020u;
goto P_0c04854a;
P_0c04854a: /* original 4c25, guest PC 0x0c04854a */
if(!s->budget--) { s->failed_pc=0x0c04854au; return 0; }
tmp=r[12]&1u; r[12]=(r[12]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04854c;
P_0c04854c: /* original 6013, guest PC 0x0c04854c */
if(!s->budget--) { s->failed_pc=0x0c04854cu; return 0; }
r[0]=r[1];
goto P_0c04854e;
P_0c04854e: /* original 8d25, guest PC 0x0c04854e */
if(!s->budget--) { s->failed_pc=0x0c04854eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
if(cond) { goto P_0c04859c; }
goto P_0c048552;
P_0c048550: /* original 4c00, guest PC 0x0c048550 */
if(!s->budget--) { s->failed_pc=0x0c048550u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c048552;
P_0c048552: /* original c808, guest PC 0x0c048552 */
if(!s->budget--) { s->failed_pc=0x0c048552u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c048554;
P_0c048554: /* original 8f0e, guest PC 0x0c048554 */
if(!s->budget--) { s->failed_pc=0x0c048554u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
if(!cond) { goto P_0c048574; }
goto P_0c048558;
P_0c048556: /* original c804, guest PC 0x0c048556 */
if(!s->budget--) { s->failed_pc=0x0c048556u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c048558;
P_0c048558: /* original 8b08, guest PC 0x0c048558 */
if(!s->budget--) { s->failed_pc=0x0c048558u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04856c; }
goto P_0c04855a;
P_0c04855a: /* original b121, guest PC 0x0c04855a */
if(!s->budget--) { s->failed_pc=0x0c04855au; return 0; }
target=0x0c0487a0u; r[16]=0x0c04855eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04855eu) { target=s->pc; goto dispatch; }
goto P_0c04855e;
P_0c04855c: /* original 0009, guest PC 0x0c04855c */
if(!s->budget--) { s->failed_pc=0x0c04855cu; return 0; }
goto P_0c04855e;
P_0c04855e: /* original afbc, guest PC 0x0c04855e */
if(!s->budget--) { s->failed_pc=0x0c04855eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c048560: /* original 6046, guest PC 0x0c048560 */
if(!s->budget--) { s->failed_pc=0x0c048560u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
return vf3_matrix_family(0x0c048562u,s,ram);
P_0c04856c: /* original b048, guest PC 0x0c04856c */
if(!s->budget--) { s->failed_pc=0x0c04856cu; return 0; }
target=0x0c048600u; r[16]=0x0c048570u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048570u) { target=s->pc; goto dispatch; }
goto P_0c048570;
P_0c04856e: /* original 0009, guest PC 0x0c04856e */
if(!s->budget--) { s->failed_pc=0x0c04856eu; return 0; }
goto P_0c048570;
P_0c048570: /* original afb3, guest PC 0x0c048570 */
if(!s->budget--) { s->failed_pc=0x0c048570u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c048572: /* original 6046, guest PC 0x0c048572 */
if(!s->budget--) { s->failed_pc=0x0c048572u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c048574;
P_0c048574: /* original b4f4, guest PC 0x0c048574 */
if(!s->budget--) { s->failed_pc=0x0c048574u; return 0; }
target=0x0c048f60u; r[16]=0x0c048578u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048578u) { target=s->pc; goto dispatch; }
goto P_0c048578;
P_0c048576: /* original 0009, guest PC 0x0c048576 */
if(!s->budget--) { s->failed_pc=0x0c048576u; return 0; }
goto P_0c048578;
P_0c048578: /* original afaf, guest PC 0x0c048578 */
if(!s->budget--) { s->failed_pc=0x0c048578u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c04857a: /* original 6046, guest PC 0x0c04857a */
if(!s->budget--) { s->failed_pc=0x0c04857au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04857c;
P_0c04857c: /* original 7f28, guest PC 0x0c04857c */
if(!s->budget--) { s->failed_pc=0x0c04857cu; return 0; }
r[15]+=0x00000028u;
goto P_0c04857e;
P_0c04857e: /* original 4f26, guest PC 0x0c04857e */
if(!s->budget--) { s->failed_pc=0x0c04857eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c048580;
P_0c048580: /* original 68f6, guest PC 0x0c048580 */
if(!s->budget--) { s->failed_pc=0x0c048580u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c048582;
P_0c048582: /* original 69f6, guest PC 0x0c048582 */
if(!s->budget--) { s->failed_pc=0x0c048582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c048584;
P_0c048584: /* original 6af6, guest PC 0x0c048584 */
if(!s->budget--) { s->failed_pc=0x0c048584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c048586;
P_0c048586: /* original 6bf6, guest PC 0x0c048586 */
if(!s->budget--) { s->failed_pc=0x0c048586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c048588;
P_0c048588: /* original 6cf6, guest PC 0x0c048588 */
if(!s->budget--) { s->failed_pc=0x0c048588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04858a;
P_0c04858a: /* original 6df6, guest PC 0x0c04858a */
if(!s->budget--) { s->failed_pc=0x0c04858au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04858c;
P_0c04858c: /* original 6ef6, guest PC 0x0c04858c */
if(!s->budget--) { s->failed_pc=0x0c04858cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04858e;
P_0c04858e: /* original fcf9, guest PC 0x0c04858e */
if(!s->budget--) { s->failed_pc=0x0c04858eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048590;
P_0c048590: /* original fdf9, guest PC 0x0c048590 */
if(!s->budget--) { s->failed_pc=0x0c048590u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048592;
P_0c048592: /* original fef9, guest PC 0x0c048592 */
if(!s->budget--) { s->failed_pc=0x0c048592u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048594;
P_0c048594: /* original fff9, guest PC 0x0c048594 */
if(!s->budget--) { s->failed_pc=0x0c048594u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048596;
P_0c048596: /* original 000b, guest PC 0x0c048596 */
if(!s->budget--) { s->failed_pc=0x0c048596u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c048598: /* original 0009, guest PC 0x0c048598 */
if(!s->budget--) { s->failed_pc=0x0c048598u; return 0; }
return vf3_matrix_family(0x0c04859au,s,ram);
P_0c04859c: /* original e100, guest PC 0x0c04859c */
if(!s->budget--) { s->failed_pc=0x0c04859cu; return 0; }
r[1]=0x00000000u;
goto P_0c04859e;
P_0c04859e: /* original c840, guest PC 0x0c04859e */
if(!s->budget--) { s->failed_pc=0x0c04859eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0485a0;
P_0c0485a0: /* original 3c1e, guest PC 0x0c0485a0 */
if(!s->budget--) { s->failed_pc=0x0c0485a0u; return 0; }
wide=(uint64_t)r[12]+r[1]+(r[17]&1u); r[12]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0485a2;
P_0c0485a2: /* original c810, guest PC 0x0c0485a2 */
if(!s->budget--) { s->failed_pc=0x0c0485a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0485a4;
P_0c0485a4: /* original 8d04, guest PC 0x0c0485a4 */
if(!s->budget--) { s->failed_pc=0x0c0485a4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
if(cond) { goto P_0c0485b0; }
goto P_0c0485a8;
P_0c0485a6: /* original c808, guest PC 0x0c0485a6 */
if(!s->budget--) { s->failed_pc=0x0c0485a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0485a8;
P_0c0485a8: /* original b19a, guest PC 0x0c0485a8 */
if(!s->budget--) { s->failed_pc=0x0c0485a8u; return 0; }
target=0x0c0488e0u; r[16]=0x0c0485acu;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0485acu) { target=s->pc; goto dispatch; }
goto P_0c0485ac;
P_0c0485aa: /* original c820, guest PC 0x0c0485aa */
if(!s->budget--) { s->failed_pc=0x0c0485aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0485ac;
P_0c0485ac: /* original af95, guest PC 0x0c0485ac */
if(!s->budget--) { s->failed_pc=0x0c0485acu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0485ae: /* original 6046, guest PC 0x0c0485ae */
if(!s->budget--) { s->failed_pc=0x0c0485aeu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0485b0;
P_0c0485b0: /* original 8904, guest PC 0x0c0485b0 */
if(!s->budget--) { s->failed_pc=0x0c0485b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0485bc; }
goto P_0c0485b2;
P_0c0485b2: /* original b3d5, guest PC 0x0c0485b2 */
if(!s->budget--) { s->failed_pc=0x0c0485b2u; return 0; }
target=0x0c048d60u; r[16]=0x0c0485b6u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0485b6u) { target=s->pc; goto dispatch; }
goto P_0c0485b6;
P_0c0485b4: /* original c820, guest PC 0x0c0485b4 */
if(!s->budget--) { s->failed_pc=0x0c0485b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0485b6;
P_0c0485b6: /* original af90, guest PC 0x0c0485b6 */
if(!s->budget--) { s->failed_pc=0x0c0485b6u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0485b8: /* original 6046, guest PC 0x0c0485b8 */
if(!s->budget--) { s->failed_pc=0x0c0485b8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
return vf3_matrix_family(0x0c0485bau,s,ram);
P_0c0485bc: /* original affe, guest PC 0x0c0485bc */
if(!s->budget--) { s->failed_pc=0x0c0485bcu; return 0; }
goto P_0c0485bc;
P_0c0485be: /* original 0009, guest PC 0x0c0485be */
if(!s->budget--) { s->failed_pc=0x0c0485beu; return 0; }
return vf3_matrix_family(0x0c0485c0u,s,ram);
P_0c048dac: /* original a041, guest PC 0x0c048dac */
if(!s->budget--) { s->failed_pc=0x0c048dacu; return 0; }
goto P_0c048e32;
P_0c048dae: /* original 0009, guest PC 0x0c048dae */
if(!s->budget--) { s->failed_pc=0x0c048daeu; return 0; }
return vf3_matrix_family(0x0c048db0u,s,ram);
P_0c048e32: /* original 0008, guest PC 0x0c048e32 */
if(!s->budget--) { s->failed_pc=0x0c048e32u; return 0; }
r[17]=(r[17]&~1u)|((0)!=0);
goto P_0c048e34;
P_0c048e34: /* original bf24, guest PC 0x0c048e34 */
if(!s->budget--) { s->failed_pc=0x0c048e34u; return 0; }
target=0x0c048c80u; r[16]=0x0c048e38u;
r[0]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048e38u) { target=s->pc; goto dispatch; }
goto P_0c048e38;
P_0c048e36: /* original e000, guest PC 0x0c048e36 */
if(!s->budget--) { s->failed_pc=0x0c048e36u; return 0; }
r[0]=0x00000000u;
goto P_0c048e38;
P_0c048e38: /* original 0008, guest PC 0x0c048e38 */
if(!s->budget--) { s->failed_pc=0x0c048e38u; return 0; }
r[17]=(r[17]&~1u)|((0)!=0);
goto P_0c048e3a;
P_0c048e3a: /* original eb01, guest PC 0x0c048e3a */
if(!s->budget--) { s->failed_pc=0x0c048e3au; return 0; }
r[11]=0x00000001u;
goto P_0c048e3c;
P_0c048e3c: /* original bf40, guest PC 0x0c048e3c */
if(!s->budget--) { s->failed_pc=0x0c048e3cu; return 0; }
target=0x0c048cc0u; r[16]=0x0c048e40u;
r[0]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048e40u) { target=s->pc; goto dispatch; }
goto P_0c048e40;
P_0c048e3e: /* original e000, guest PC 0x0c048e3e */
if(!s->budget--) { s->failed_pc=0x0c048e3eu; return 0; }
r[0]=0x00000000u;
goto P_0c048e40;
P_0c048e40: /* original 0008, guest PC 0x0c048e40 */
if(!s->budget--) { s->failed_pc=0x0c048e40u; return 0; }
r[17]=(r[17]&~1u)|((0)!=0);
goto P_0c048e42;
P_0c048e42: /* original eb02, guest PC 0x0c048e42 */
if(!s->budget--) { s->failed_pc=0x0c048e42u; return 0; }
r[11]=0x00000002u;
goto P_0c048e44;
P_0c048e44: /* original bf1c, guest PC 0x0c048e44 */
if(!s->budget--) { s->failed_pc=0x0c048e44u; return 0; }
target=0x0c048c80u; r[16]=0x0c048e48u;
r[0]=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048e48u) { target=s->pc; goto dispatch; }
goto P_0c048e48;
P_0c048e46: /* original e002, guest PC 0x0c048e46 */
if(!s->budget--) { s->failed_pc=0x0c048e46u; return 0; }
r[0]=0x00000002u;
goto P_0c048e48;
P_0c048e48: /* original 0018, guest PC 0x0c048e48 */
if(!s->budget--) { s->failed_pc=0x0c048e48u; return 0; }
r[17]=(r[17]&~1u)|((1)!=0);
goto P_0c048e4a;
P_0c048e4a: /* original bf39, guest PC 0x0c048e4a */
if(!s->budget--) { s->failed_pc=0x0c048e4au; return 0; }
target=0x0c048cc0u; r[16]=0x0c048e4eu;
r[0]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048e4eu) { target=s->pc; goto dispatch; }
goto P_0c048e4e;
P_0c048e4c: /* original e001, guest PC 0x0c048e4c */
if(!s->budget--) { s->failed_pc=0x0c048e4cu; return 0; }
r[0]=0x00000001u;
goto P_0c048e4e;
P_0c048e4e: /* original afb9, guest PC 0x0c048e4e */
if(!s->budget--) { s->failed_pc=0x0c048e4eu; return 0; }
return vf3_matrix_family(0x0c048dc4u,s,ram);
P_0c048e50: /* original 0009, guest PC 0x0c048e50 */
if(!s->budget--) { s->failed_pc=0x0c048e50u; return 0; }
return vf3_matrix_family(0x0c048e52u,s,ram);
P_0c04bf3c: /* original 4f22, guest PC 0x0c04bf3c */
if(!s->budget--) { s->failed_pc=0x0c04bf3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bf3e;
P_0c04bf3e: /* original d32b, guest PC 0x0c04bf3e */
if(!s->budget--) { s->failed_pc=0x0c04bf3eu; return 0; }
r[3]=read(ram,0x0c04bfecu,4);
goto P_0c04bf40;
P_0c04bf40: /* original da2b, guest PC 0x0c04bf40 */
if(!s->budget--) { s->failed_pc=0x0c04bf40u; return 0; }
r[10]=read(ram,0x0c04bff0u,4);
goto P_0c04bf42;
P_0c04bf42: /* original 4f12, guest PC 0x0c04bf42 */
if(!s->budget--) { s->failed_pc=0x0c04bf42u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04bf44;
P_0c04bf44: /* original 6c32, guest PC 0x0c04bf44 */
if(!s->budget--) { s->failed_pc=0x0c04bf44u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c04bf46;
P_0c04bf46: /* original 7ffc, guest PC 0x0c04bf46 */
if(!s->budget--) { s->failed_pc=0x0c04bf46u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04bf48;
P_0c04bf48: /* original 2f66, guest PC 0x0c04bf48 */
if(!s->budget--) { s->failed_pc=0x0c04bf48u; return 0; }
r[15]-=4; write(ram,r[15],r[6],4);
goto P_0c04bf4a;
P_0c04bf4a: /* original 2f86, guest PC 0x0c04bf4a */
if(!s->budget--) { s->failed_pc=0x0c04bf4au; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c04bf4c;
P_0c04bf4c: /* original 2fe6, guest PC 0x0c04bf4c */
if(!s->budget--) { s->failed_pc=0x0c04bf4cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c04bf4e;
P_0c04bf4e: /* original d229, guest PC 0x0c04bf4e */
if(!s->budget--) { s->failed_pc=0x0c04bf4eu; return 0; }
r[2]=read(ram,0x0c04bff4u,4);
goto P_0c04bf50;
P_0c04bf50: /* original 4a0b, guest PC 0x0c04bf50 */
if(!s->budget--) { s->failed_pc=0x0c04bf50u; return 0; }
target=r[10];
r[16]=0x0c04bf54u;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bf54u) { target=s->pc; goto dispatch; }
goto P_0c04bf54;
P_0c04bf52: /* original 2f26, guest PC 0x0c04bf52 */
if(!s->budget--) { s->failed_pc=0x0c04bf52u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c04bf54;
P_0c04bf54: /* original 9d48, guest PC 0x0c04bf54 */
if(!s->budget--) { s->failed_pc=0x0c04bf54u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bfe8u,2);
goto P_0c04bf56;
P_0c04bf56: /* original 7f10, guest PC 0x0c04bf56 */
if(!s->budget--) { s->failed_pc=0x0c04bf56u; return 0; }
r[15]+=0x00000010u;
goto P_0c04bf58;
P_0c04bf58: /* original 0ed7, guest PC 0x0c04bf58 */
if(!s->budget--) { s->failed_pc=0x0c04bf58u; return 0; }
r[19]=r[14]*r[13];
goto P_0c04bf5a;
P_0c04bf5a: /* original 0d1a, guest PC 0x0c04bf5a */
if(!s->budget--) { s->failed_pc=0x0c04bf5au; return 0; }
r[13]=r[19];
goto P_0c04bf5c;
P_0c04bf5c: /* original 2fd2, guest PC 0x0c04bf5c */
if(!s->budget--) { s->failed_pc=0x0c04bf5cu; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04bf5e;
P_0c04bf5e: /* original d326, guest PC 0x0c04bf5e */
if(!s->budget--) { s->failed_pc=0x0c04bf5eu; return 0; }
r[3]=read(ram,0x0c04bff8u,4);
goto P_0c04bf60;
P_0c04bf60: /* original 3d3c, guest PC 0x0c04bf60 */
if(!s->budget--) { s->failed_pc=0x0c04bf60u; return 0; }
r[13]+=r[3];
goto P_0c04bf62;
P_0c04bf62: /* original 2fc6, guest PC 0x0c04bf62 */
if(!s->budget--) { s->failed_pc=0x0c04bf62u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c04bf64;
P_0c04bf64: /* original d225, guest PC 0x0c04bf64 */
if(!s->budget--) { s->failed_pc=0x0c04bf64u; return 0; }
r[2]=read(ram,0x0c04bffcu,4);
goto P_0c04bf66;
P_0c04bf66: /* original 4a0b, guest PC 0x0c04bf66 */
if(!s->budget--) { s->failed_pc=0x0c04bf66u; return 0; }
target=r[10];
r[16]=0x0c04bf6au;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bf6au) { target=s->pc; goto dispatch; }
goto P_0c04bf6a;
P_0c04bf68: /* original 2f26, guest PC 0x0c04bf68 */
if(!s->budget--) { s->failed_pc=0x0c04bf68u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c04bf6a;
P_0c04bf6a: /* original d325, guest PC 0x0c04bf6a */
if(!s->budget--) { s->failed_pc=0x0c04bf6au; return 0; }
r[3]=read(ram,0x0c04c000u,4);
goto P_0c04bf6c;
P_0c04bf6c: /* original 6583, guest PC 0x0c04bf6c */
if(!s->budget--) { s->failed_pc=0x0c04bf6cu; return 0; }
r[5]=r[8];
goto P_0c04bf6e;
P_0c04bf6e: /* original 7f08, guest PC 0x0c04bf6e */
if(!s->budget--) { s->failed_pc=0x0c04bf6eu; return 0; }
r[15]+=0x00000008u;
goto P_0c04bf70;
P_0c04bf70: /* original 6693, guest PC 0x0c04bf70 */
if(!s->budget--) { s->failed_pc=0x0c04bf70u; return 0; }
r[6]=r[9];
goto P_0c04bf72;
P_0c04bf72: /* original 430b, guest PC 0x0c04bf72 */
if(!s->budget--) { s->failed_pc=0x0c04bf72u; return 0; }
target=r[3];
r[16]=0x0c04bf76u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bf76u) { target=s->pc; goto dispatch; }
goto P_0c04bf76;
P_0c04bf74: /* original 64e3, guest PC 0x0c04bf74 */
if(!s->budget--) { s->failed_pc=0x0c04bf74u; return 0; }
r[4]=r[14];
goto P_0c04bf76;
P_0c04bf76: /* original 6b03, guest PC 0x0c04bf76 */
if(!s->budget--) { s->failed_pc=0x0c04bf76u; return 0; }
r[11]=r[0];
goto P_0c04bf78;
P_0c04bf78: /* original 2bb8, guest PC 0x0c04bf78 */
if(!s->budget--) { s->failed_pc=0x0c04bf78u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c04bf7a;
P_0c04bf7a: /* original 8909, guest PC 0x0c04bf7a */
if(!s->budget--) { s->failed_pc=0x0c04bf7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bf90; }
goto P_0c04bf7c;
P_0c04bf7c: /* original 52dd, guest PC 0x0c04bf7c */
if(!s->budget--) { s->failed_pc=0x0c04bf7cu; return 0; }
r[2]=read(ram,r[13]+52,4);
goto P_0c04bf7e;
P_0c04bf7e: /* original 2cc8, guest PC 0x0c04bf7e */
if(!s->budget--) { s->failed_pc=0x0c04bf7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c04bf80;
P_0c04bf80: /* original 7201, guest PC 0x0c04bf80 */
if(!s->budget--) { s->failed_pc=0x0c04bf80u; return 0; }
r[2]+=0x00000001u;
goto P_0c04bf82;
P_0c04bf82: /* original 1d2d, guest PC 0x0c04bf82 */
if(!s->budget--) { s->failed_pc=0x0c04bf82u; return 0; }
write(ram,r[13]+52,r[2],4);
goto P_0c04bf84;
P_0c04bf84: /* original 8fed, guest PC 0x0c04bf84 */
if(!s->budget--) { s->failed_pc=0x0c04bf84u; return 0; }
cond=r[17]&1u;
r[12]+=0xffffffffu;
if(!cond) { goto P_0c04bf62; }
goto P_0c04bf88;
P_0c04bf86: /* original 7cff, guest PC 0x0c04bf86 */
if(!s->budget--) { s->failed_pc=0x0c04bf86u; return 0; }
r[12]+=0xffffffffu;
goto P_0c04bf88;
P_0c04bf88: /* original d118, guest PC 0x0c04bf88 */
if(!s->budget--) { s->failed_pc=0x0c04bf88u; return 0; }
r[1]=read(ram,0x0c04bfecu,4);
goto P_0c04bf8a;
P_0c04bf8a: /* original 6012, guest PC 0x0c04bf8a */
if(!s->budget--) { s->failed_pc=0x0c04bf8au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c04bf8c;
P_0c04bf8c: /* original 88ff, guest PC 0x0c04bf8c */
if(!s->budget--) { s->failed_pc=0x0c04bf8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04bf8e;
P_0c04bf8e: /* original 89e8, guest PC 0x0c04bf8e */
if(!s->budget--) { s->failed_pc=0x0c04bf8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bf62; }
goto P_0c04bf90;
P_0c04bf90: /* original 6df2, guest PC 0x0c04bf90 */
if(!s->budget--) { s->failed_pc=0x0c04bf90u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c04bf92;
P_0c04bf92: /* original 62e3, guest PC 0x0c04bf92 */
if(!s->budget--) { s->failed_pc=0x0c04bf92u; return 0; }
r[2]=r[14];
goto P_0c04bf94;
P_0c04bf94: /* original d318, guest PC 0x0c04bf94 */
if(!s->budget--) { s->failed_pc=0x0c04bf94u; return 0; }
r[3]=read(ram,0x0c04bff8u,4);
goto P_0c04bf96;
P_0c04bf96: /* original 4208, guest PC 0x0c04bf96 */
if(!s->budget--) { s->failed_pc=0x0c04bf96u; return 0; }
r[2]<<=2;
goto P_0c04bf98;
P_0c04bf98: /* original 4208, guest PC 0x0c04bf98 */
if(!s->budget--) { s->failed_pc=0x0c04bf98u; return 0; }
r[2]<<=2;
goto P_0c04bf9a;
P_0c04bf9a: /* original d11a, guest PC 0x0c04bf9a */
if(!s->budget--) { s->failed_pc=0x0c04bf9au; return 0; }
r[1]=read(ram,0x0c04c004u,4);
goto P_0c04bf9c;
P_0c04bf9c: /* original 3d3c, guest PC 0x0c04bf9c */
if(!s->budget--) { s->failed_pc=0x0c04bf9cu; return 0; }
r[13]+=r[3];
goto P_0c04bf9e;
P_0c04bf9e: /* original 4208, guest PC 0x0c04bf9e */
if(!s->budget--) { s->failed_pc=0x0c04bf9eu; return 0; }
r[2]<<=2;
goto P_0c04bfa0;
P_0c04bfa0: /* original 4200, guest PC 0x0c04bfa0 */
if(!s->budget--) { s->failed_pc=0x0c04bfa0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04bfa2;
P_0c04bfa2: /* original 321c, guest PC 0x0c04bfa2 */
if(!s->budget--) { s->failed_pc=0x0c04bfa2u; return 0; }
r[2]+=r[1];
goto P_0c04bfa4;
P_0c04bfa4: /* original 2f22, guest PC 0x0c04bfa4 */
if(!s->budget--) { s->failed_pc=0x0c04bfa4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04bfa6;
P_0c04bfa6: /* original 56dc, guest PC 0x0c04bfa6 */
if(!s->budget--) { s->failed_pc=0x0c04bfa6u; return 0; }
r[6]=read(ram,r[13]+48,4);
goto P_0c04bfa8;
P_0c04bfa8: /* original 57dd, guest PC 0x0c04bfa8 */
if(!s->budget--) { s->failed_pc=0x0c04bfa8u; return 0; }
r[7]=read(ram,r[13]+52,4);
goto P_0c04bfaa;
P_0c04bfaa: /* original 7601, guest PC 0x0c04bfaa */
if(!s->budget--) { s->failed_pc=0x0c04bfaau; return 0; }
r[6]+=0x00000001u;
goto P_0c04bfac;
P_0c04bfac: /* original 1d6c, guest PC 0x0c04bfac */
if(!s->budget--) { s->failed_pc=0x0c04bfacu; return 0; }
write(ram,r[13]+48,r[6],4);
goto P_0c04bfae;
P_0c04bfae: /* original 76ff, guest PC 0x0c04bfae */
if(!s->budget--) { s->failed_pc=0x0c04bfaeu; return 0; }
r[6]+=0xffffffffu;
goto P_0c04bfb0;
P_0c04bfb0: /* original 65f2, guest PC 0x0c04bfb0 */
if(!s->budget--) { s->failed_pc=0x0c04bfb0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04bfb2;
P_0c04bfb2: /* original d315, guest PC 0x0c04bfb2 */
if(!s->budget--) { s->failed_pc=0x0c04bfb2u; return 0; }
r[3]=read(ram,0x0c04c008u,4);
goto P_0c04bfb4;
P_0c04bfb4: /* original 5552, guest PC 0x0c04bfb4 */
if(!s->budget--) { s->failed_pc=0x0c04bfb4u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04bfb6;
P_0c04bfb6: /* original 430b, guest PC 0x0c04bfb6 */
if(!s->budget--) { s->failed_pc=0x0c04bfb6u; return 0; }
target=r[3];
r[16]=0x0c04bfbau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bfbau) { target=s->pc; goto dispatch; }
goto P_0c04bfba;
P_0c04bfb8: /* original 64e3, guest PC 0x0c04bfb8 */
if(!s->budget--) { s->failed_pc=0x0c04bfb8u; return 0; }
r[4]=r[14];
goto P_0c04bfba;
P_0c04bfba: /* original 9116, guest PC 0x0c04bfba */
if(!s->budget--) { s->failed_pc=0x0c04bfbau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bfeau,2);
goto P_0c04bfbc;
P_0c04bfbc: /* original 60b3, guest PC 0x0c04bfbc */
if(!s->budget--) { s->failed_pc=0x0c04bfbcu; return 0; }
r[0]=r[11];
goto P_0c04bfbe;
P_0c04bfbe: /* original 3010, guest PC 0x0c04bfbe */
if(!s->budget--) { s->failed_pc=0x0c04bfbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04bfc0;
P_0c04bfc0: /* original 8903, guest PC 0x0c04bfc0 */
if(!s->budget--) { s->failed_pc=0x0c04bfc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bfca; }
goto P_0c04bfc2;
P_0c04bfc2: /* original 8800, guest PC 0x0c04bfc2 */
if(!s->budget--) { s->failed_pc=0x0c04bfc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04bfc4;
P_0c04bfc4: /* original 8b04, guest PC 0x0c04bfc4 */
if(!s->budget--) { s->failed_pc=0x0c04bfc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bfd0; }
goto P_0c04bfc6;
P_0c04bfc6: /* original a004, guest PC 0x0c04bfc6 */
if(!s->budget--) { s->failed_pc=0x0c04bfc6u; return 0; }
r[0]=0x00000000u;
goto P_0c04bfd2;
P_0c04bfc8: /* original e000, guest PC 0x0c04bfc8 */
if(!s->budget--) { s->failed_pc=0x0c04bfc8u; return 0; }
r[0]=0x00000000u;
goto P_0c04bfca;
P_0c04bfca: /* original 900e, guest PC 0x0c04bfca */
if(!s->budget--) { s->failed_pc=0x0c04bfcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bfeau,2);
goto P_0c04bfcc;
P_0c04bfcc: /* original a001, guest PC 0x0c04bfcc */
if(!s->budget--) { s->failed_pc=0x0c04bfccu; return 0; }
goto P_0c04bfd2;
P_0c04bfce: /* original 0009, guest PC 0x0c04bfce */
if(!s->budget--) { s->failed_pc=0x0c04bfceu; return 0; }
goto P_0c04bfd0;
P_0c04bfd0: /* original d00e, guest PC 0x0c04bfd0 */
if(!s->budget--) { s->failed_pc=0x0c04bfd0u; return 0; }
r[0]=read(ram,0x0c04c00cu,4);
goto P_0c04bfd2;
P_0c04bfd2: /* original 7f04, guest PC 0x0c04bfd2 */
if(!s->budget--) { s->failed_pc=0x0c04bfd2u; return 0; }
r[15]+=0x00000004u;
goto P_0c04bfd4;
P_0c04bfd4: /* original 4f16, guest PC 0x0c04bfd4 */
if(!s->budget--) { s->failed_pc=0x0c04bfd4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bfd6;
P_0c04bfd6: /* original 4f26, guest PC 0x0c04bfd6 */
if(!s->budget--) { s->failed_pc=0x0c04bfd6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bfd8;
P_0c04bfd8: /* original 68f6, guest PC 0x0c04bfd8 */
if(!s->budget--) { s->failed_pc=0x0c04bfd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04bfda;
P_0c04bfda: /* original 69f6, guest PC 0x0c04bfda */
if(!s->budget--) { s->failed_pc=0x0c04bfdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04bfdc;
P_0c04bfdc: /* original 6af6, guest PC 0x0c04bfdc */
if(!s->budget--) { s->failed_pc=0x0c04bfdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04bfde;
P_0c04bfde: /* original 6bf6, guest PC 0x0c04bfde */
if(!s->budget--) { s->failed_pc=0x0c04bfdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04bfe0;
P_0c04bfe0: /* original 6cf6, guest PC 0x0c04bfe0 */
if(!s->budget--) { s->failed_pc=0x0c04bfe0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bfe2;
P_0c04bfe2: /* original 6df6, guest PC 0x0c04bfe2 */
if(!s->budget--) { s->failed_pc=0x0c04bfe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04bfe4;
P_0c04bfe4: /* original 000b, guest PC 0x0c04bfe4 */
if(!s->budget--) { s->failed_pc=0x0c04bfe4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bfe6: /* original 6ef6, guest PC 0x0c04bfe6 */
if(!s->budget--) { s->failed_pc=0x0c04bfe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04bfe8u,s,ram);
P_0c051f8e: /* original ff0b, guest PC 0x0c051f8e */
if(!s->budget--) { s->failed_pc=0x0c051f8eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c051f90;
P_0c051f90: /* original 4f22, guest PC 0x0c051f90 */
if(!s->budget--) { s->failed_pc=0x0c051f90u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c051f92;
P_0c051f92: /* original 6ef3, guest PC 0x0c051f92 */
if(!s->budget--) { s->failed_pc=0x0c051f92u; return 0; }
r[14]=r[15];
goto P_0c051f94;
P_0c051f94: /* original e0ff, guest PC 0x0c051f94 */
if(!s->budget--) { s->failed_pc=0x0c051f94u; return 0; }
r[0]=0xffffffffu;
goto P_0c051f96;
P_0c051f96: /* original 4018, guest PC 0x0c051f96 */
if(!s->budget--) { s->failed_pc=0x0c051f96u; return 0; }
r[0]<<=8;
goto P_0c051f98;
P_0c051f98: /* original 3f0c, guest PC 0x0c051f98 */
if(!s->budget--) { s->failed_pc=0x0c051f98u; return 0; }
r[15]+=r[0];
goto P_0c051f9a;
P_0c051f9a: /* original e064, guest PC 0x0c051f9a */
if(!s->budget--) { s->failed_pc=0x0c051f9au; return 0; }
r[0]=0x00000064u;
goto P_0c051f9c;
P_0c051f9c: /* original 08ee, guest PC 0x0c051f9c */
if(!s->budget--) { s->failed_pc=0x0c051f9cu; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c051f9e;
P_0c051f9e: /* original 7806, guest PC 0x0c051f9e */
if(!s->budget--) { s->failed_pc=0x0c051f9eu; return 0; }
r[8]+=0x00000006u;
goto P_0c051fa0;
P_0c051fa0: /* original e068, guest PC 0x0c051fa0 */
if(!s->budget--) { s->failed_pc=0x0c051fa0u; return 0; }
r[0]=0x00000068u;
goto P_0c051fa2;
P_0c051fa2: /* original 0e86, guest PC 0x0c051fa2 */
if(!s->budget--) { s->failed_pc=0x0c051fa2u; return 0; }
write(ram,r[14]+r[0],r[8],4);
goto P_0c051fa4;
P_0c051fa4: /* original e06c, guest PC 0x0c051fa4 */
if(!s->budget--) { s->failed_pc=0x0c051fa4u; return 0; }
r[0]=0x0000006cu;
goto P_0c051fa6;
P_0c051fa6: /* original 7806, guest PC 0x0c051fa6 */
if(!s->budget--) { s->failed_pc=0x0c051fa6u; return 0; }
r[8]+=0x00000006u;
goto P_0c051fa8;
P_0c051fa8: /* original 0e86, guest PC 0x0c051fa8 */
if(!s->budget--) { s->failed_pc=0x0c051fa8u; return 0; }
write(ram,r[14]+r[0],r[8],4);
goto P_0c051faa;
P_0c051faa: /* original ff3c, guest PC 0x0c051faa */
if(!s->budget--) { s->failed_pc=0x0c051faau; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c051fac;
P_0c051fac: /* original 6543, guest PC 0x0c051fac */
if(!s->budget--) { s->failed_pc=0x0c051facu; return 0; }
r[5]=r[4];
goto P_0c051fae;
P_0c051fae: /* original e001, guest PC 0x0c051fae */
if(!s->budget--) { s->failed_pc=0x0c051faeu; return 0; }
r[0]=0x00000001u;
goto P_0c051fb0;
P_0c051fb0: /* original 2509, guest PC 0x0c051fb0 */
if(!s->budget--) { s->failed_pc=0x0c051fb0u; return 0; }
r[5]&=r[0];
goto P_0c051fb2;
P_0c051fb2: /* original 4508, guest PC 0x0c051fb2 */
if(!s->budget--) { s->failed_pc=0x0c051fb2u; return 0; }
r[5]<<=2;
goto P_0c051fb4;
P_0c051fb4: /* original 6643, guest PC 0x0c051fb4 */
if(!s->budget--) { s->failed_pc=0x0c051fb4u; return 0; }
r[6]=r[4];
goto P_0c051fb6;
P_0c051fb6: /* original e002, guest PC 0x0c051fb6 */
if(!s->budget--) { s->failed_pc=0x0c051fb6u; return 0; }
r[0]=0x00000002u;
goto P_0c051fb8;
P_0c051fb8: /* original 2609, guest PC 0x0c051fb8 */
if(!s->budget--) { s->failed_pc=0x0c051fb8u; return 0; }
r[6]&=r[0];
goto P_0c051fba;
P_0c051fba: /* original 256b, guest PC 0x0c051fba */
if(!s->budget--) { s->failed_pc=0x0c051fbau; return 0; }
r[5]|=r[6];
goto P_0c051fbc;
P_0c051fbc: /* original 6743, guest PC 0x0c051fbc */
if(!s->budget--) { s->failed_pc=0x0c051fbcu; return 0; }
r[7]=r[4];
goto P_0c051fbe;
P_0c051fbe: /* original e004, guest PC 0x0c051fbe */
if(!s->budget--) { s->failed_pc=0x0c051fbeu; return 0; }
r[0]=0x00000004u;
goto P_0c051fc0;
P_0c051fc0: /* original 2709, guest PC 0x0c051fc0 */
if(!s->budget--) { s->failed_pc=0x0c051fc0u; return 0; }
r[7]&=r[0];
goto P_0c051fc2;
P_0c051fc2: /* original 4709, guest PC 0x0c051fc2 */
if(!s->budget--) { s->failed_pc=0x0c051fc2u; return 0; }
r[7]>>=2;
goto P_0c051fc4;
P_0c051fc4: /* original 275b, guest PC 0x0c051fc4 */
if(!s->budget--) { s->failed_pc=0x0c051fc4u; return 0; }
r[7]|=r[5];
goto P_0c051fc6;
P_0c051fc6: /* original 6473, guest PC 0x0c051fc6 */
if(!s->budget--) { s->failed_pc=0x0c051fc6u; return 0; }
r[4]=r[7];
goto P_0c051fc8;
P_0c051fc8: /* original d003, guest PC 0x0c051fc8 */
if(!s->budget--) { s->failed_pc=0x0c051fc8u; return 0; }
r[0]=read(ram,0x0c051fd8u,4);
goto P_0c051fca;
P_0c051fca: /* original 6002, guest PC 0x0c051fca */
if(!s->budget--) { s->failed_pc=0x0c051fcau; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c051fcc;
P_0c051fcc: /* original 2008, guest PC 0x0c051fcc */
if(!s->budget--) { s->failed_pc=0x0c051fccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c051fce;
P_0c051fce: /* original 8907, guest PC 0x0c051fce */
if(!s->budget--) { s->failed_pc=0x0c051fceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c051fe0; }
goto P_0c051fd0;
P_0c051fd0: /* original da02, guest PC 0x0c051fd0 */
if(!s->budget--) { s->failed_pc=0x0c051fd0u; return 0; }
r[10]=read(ram,0x0c051fdcu,4);
goto P_0c051fd2;
P_0c051fd2: /* original a006, guest PC 0x0c051fd2 */
if(!s->budget--) { s->failed_pc=0x0c051fd2u; return 0; }
goto P_0c051fe2;
P_0c051fd4: /* original 0009, guest PC 0x0c051fd4 */
if(!s->budget--) { s->failed_pc=0x0c051fd4u; return 0; }
return vf3_matrix_family(0x0c051fd6u,s,ram);
P_0c051fe0: /* original da12, guest PC 0x0c051fe0 */
if(!s->budget--) { s->failed_pc=0x0c051fe0u; return 0; }
r[10]=read(ram,0x0c05202cu,4);
goto P_0c051fe2;
P_0c051fe2: /* original e001, guest PC 0x0c051fe2 */
if(!s->budget--) { s->failed_pc=0x0c051fe2u; return 0; }
r[0]=0x00000001u;
goto P_0c051fe4;
P_0c051fe4: /* original 2049, guest PC 0x0c051fe4 */
if(!s->budget--) { s->failed_pc=0x0c051fe4u; return 0; }
r[0]&=r[4];
goto P_0c051fe6;
P_0c051fe6: /* original 4015, guest PC 0x0c051fe6 */
if(!s->budget--) { s->failed_pc=0x0c051fe6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c051fe8;
P_0c051fe8: /* original 8d5b, guest PC 0x0c051fe8 */
if(!s->budget--) { s->failed_pc=0x0c051fe8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0520a2; }
goto P_0c051fec;
P_0c051fea: /* original 0009, guest PC 0x0c051fea */
if(!s->budget--) { s->failed_pc=0x0c051feau; return 0; }
goto P_0c051fec;
P_0c051fec: /* original d010, guest PC 0x0c051fec */
if(!s->budget--) { s->failed_pc=0x0c051fecu; return 0; }
r[0]=read(ram,0x0c052030u,4);
goto P_0c051fee;
P_0c051fee: /* original 2049, guest PC 0x0c051fee */
if(!s->budget--) { s->failed_pc=0x0c051feeu; return 0; }
r[0]&=r[4];
goto P_0c051ff0;
P_0c051ff0: /* original 4015, guest PC 0x0c051ff0 */
if(!s->budget--) { s->failed_pc=0x0c051ff0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c051ff2;
P_0c051ff2: /* original 8d1f, guest PC 0x0c051ff2 */
if(!s->budget--) { s->failed_pc=0x0c051ff2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c052034; }
goto P_0c051ff6;
P_0c051ff4: /* original 0009, guest PC 0x0c051ff4 */
if(!s->budget--) { s->failed_pc=0x0c051ff4u; return 0; }
goto P_0c051ff6;
P_0c051ff6: /* original 64c3, guest PC 0x0c051ff6 */
if(!s->budget--) { s->failed_pc=0x0c051ff6u; return 0; }
r[4]=r[12];
goto P_0c051ff8;
P_0c051ff8: /* original e064, guest PC 0x0c051ff8 */
if(!s->budget--) { s->failed_pc=0x0c051ff8u; return 0; }
r[0]=0x00000064u;
goto P_0c051ffa;
P_0c051ffa: /* original e114, guest PC 0x0c051ffa */
if(!s->budget--) { s->failed_pc=0x0c051ffau; return 0; }
r[1]=0x00000014u;
goto P_0c051ffc;
P_0c051ffc: /* original b0ea, guest PC 0x0c051ffc */
if(!s->budget--) { s->failed_pc=0x0c051ffcu; return 0; }
target=0x0c0521d4u; r[16]=0x0c052000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052000u) { target=s->pc; goto dispatch; }
goto P_0c052000;
P_0c051ffe: /* original 0009, guest PC 0x0c051ffe */
if(!s->budget--) { s->failed_pc=0x0c051ffeu; return 0; }
goto P_0c052000;
P_0c052000: /* original 64c3, guest PC 0x0c052000 */
if(!s->budget--) { s->failed_pc=0x0c052000u; return 0; }
r[4]=r[12];
goto P_0c052002;
P_0c052002: /* original e068, guest PC 0x0c052002 */
if(!s->budget--) { s->failed_pc=0x0c052002u; return 0; }
r[0]=0x00000068u;
goto P_0c052004;
P_0c052004: /* original e124, guest PC 0x0c052004 */
if(!s->budget--) { s->failed_pc=0x0c052004u; return 0; }
r[1]=0x00000024u;
goto P_0c052006;
P_0c052006: /* original b0e5, guest PC 0x0c052006 */
if(!s->budget--) { s->failed_pc=0x0c052006u; return 0; }
target=0x0c0521d4u; r[16]=0x0c05200au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05200au) { target=s->pc; goto dispatch; }
goto P_0c05200a;
P_0c052008: /* original 0009, guest PC 0x0c052008 */
if(!s->budget--) { s->failed_pc=0x0c052008u; return 0; }
goto P_0c05200a;
P_0c05200a: /* original 64c3, guest PC 0x0c05200a */
if(!s->budget--) { s->failed_pc=0x0c05200au; return 0; }
r[4]=r[12];
goto P_0c05200c;
P_0c05200c: /* original e064, guest PC 0x0c05200c */
if(!s->budget--) { s->failed_pc=0x0c05200cu; return 0; }
r[0]=0x00000064u;
goto P_0c05200e;
P_0c05200e: /* original e114, guest PC 0x0c05200e */
if(!s->budget--) { s->failed_pc=0x0c05200eu; return 0; }
r[1]=0x00000014u;
goto P_0c052010;
P_0c052010: /* original e26c, guest PC 0x0c052010 */
if(!s->budget--) { s->failed_pc=0x0c052010u; return 0; }
r[2]=0x0000006cu;
goto P_0c052012;
P_0c052012: /* original e334, guest PC 0x0c052012 */
if(!s->budget--) { s->failed_pc=0x0c052012u; return 0; }
r[3]=0x00000034u;
goto P_0c052014;
P_0c052014: /* original b0f4, guest PC 0x0c052014 */
if(!s->budget--) { s->failed_pc=0x0c052014u; return 0; }
target=0x0c052200u; r[16]=0x0c052018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052018u) { target=s->pc; goto dispatch; }
goto P_0c052018;
P_0c052016: /* original 0009, guest PC 0x0c052016 */
if(!s->budget--) { s->failed_pc=0x0c052016u; return 0; }
goto P_0c052018;
P_0c052018: /* original 04c2, guest PC 0x0c052018 */
if(!s->budget--) { s->failed_pc=0x0c052018u; return 0; }
if(!s->bank_known) goto unsupported;
r[4]=s->bank[4];
goto P_0c05201a;
P_0c05201a: /* original e068, guest PC 0x0c05201a */
if(!s->budget--) { s->failed_pc=0x0c05201au; return 0; }
r[0]=0x00000068u;
goto P_0c05201c;
P_0c05201c: /* original e124, guest PC 0x0c05201c */
if(!s->budget--) { s->failed_pc=0x0c05201cu; return 0; }
r[1]=0x00000024u;
goto P_0c05201e;
P_0c05201e: /* original e26c, guest PC 0x0c05201e */
if(!s->budget--) { s->failed_pc=0x0c05201eu; return 0; }
r[2]=0x0000006cu;
goto P_0c052020;
P_0c052020: /* original e334, guest PC 0x0c052020 */
if(!s->budget--) { s->failed_pc=0x0c052020u; return 0; }
r[3]=0x00000034u;
goto P_0c052022;
P_0c052022: /* original b0ed, guest PC 0x0c052022 */
if(!s->budget--) { s->failed_pc=0x0c052022u; return 0; }
target=0x0c052200u; r[16]=0x0c052026u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052026u) { target=s->pc; goto dispatch; }
goto P_0c052026;
P_0c052024: /* original 0009, guest PC 0x0c052024 */
if(!s->budget--) { s->failed_pc=0x0c052024u; return 0; }
goto P_0c052026;
P_0c052026: /* original a08d, guest PC 0x0c052026 */
if(!s->budget--) { s->failed_pc=0x0c052026u; return 0; }
goto P_0c052144;
P_0c052028: /* original 0009, guest PC 0x0c052028 */
if(!s->budget--) { s->failed_pc=0x0c052028u; return 0; }
return vf3_matrix_family(0x0c05202au,s,ram);
P_0c052034: /* original d00f, guest PC 0x0c052034 */
if(!s->budget--) { s->failed_pc=0x0c052034u; return 0; }
r[0]=read(ram,0x0c052074u,4);
goto P_0c052036;
P_0c052036: /* original 2049, guest PC 0x0c052036 */
if(!s->budget--) { s->failed_pc=0x0c052036u; return 0; }
r[0]&=r[4];
goto P_0c052038;
P_0c052038: /* original 4015, guest PC 0x0c052038 */
if(!s->budget--) { s->failed_pc=0x0c052038u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c05203a;
P_0c05203a: /* original 8d1d, guest PC 0x0c05203a */
if(!s->budget--) { s->failed_pc=0x0c05203au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c052078; }
goto P_0c05203e;
P_0c05203c: /* original 0009, guest PC 0x0c05203c */
if(!s->budget--) { s->failed_pc=0x0c05203cu; return 0; }
goto P_0c05203e;
P_0c05203e: /* original 64c3, guest PC 0x0c05203e */
if(!s->budget--) { s->failed_pc=0x0c05203eu; return 0; }
r[4]=r[12];
goto P_0c052040;
P_0c052040: /* original e064, guest PC 0x0c052040 */
if(!s->budget--) { s->failed_pc=0x0c052040u; return 0; }
r[0]=0x00000064u;
goto P_0c052042;
P_0c052042: /* original e114, guest PC 0x0c052042 */
if(!s->budget--) { s->failed_pc=0x0c052042u; return 0; }
r[1]=0x00000014u;
goto P_0c052044;
P_0c052044: /* original b0c6, guest PC 0x0c052044 */
if(!s->budget--) { s->failed_pc=0x0c052044u; return 0; }
target=0x0c0521d4u; r[16]=0x0c052048u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052048u) { target=s->pc; goto dispatch; }
goto P_0c052048;
P_0c052046: /* original 0009, guest PC 0x0c052046 */
if(!s->budget--) { s->failed_pc=0x0c052046u; return 0; }
goto P_0c052048;
P_0c052048: /* original 64c3, guest PC 0x0c052048 */
if(!s->budget--) { s->failed_pc=0x0c052048u; return 0; }
r[4]=r[12];
goto P_0c05204a;
P_0c05204a: /* original e064, guest PC 0x0c05204a */
if(!s->budget--) { s->failed_pc=0x0c05204au; return 0; }
r[0]=0x00000064u;
goto P_0c05204c;
P_0c05204c: /* original e114, guest PC 0x0c05204c */
if(!s->budget--) { s->failed_pc=0x0c05204cu; return 0; }
r[1]=0x00000014u;
goto P_0c05204e;
P_0c05204e: /* original e268, guest PC 0x0c05204e */
if(!s->budget--) { s->failed_pc=0x0c05204eu; return 0; }
r[2]=0x00000068u;
goto P_0c052050;
P_0c052050: /* original e324, guest PC 0x0c052050 */
if(!s->budget--) { s->failed_pc=0x0c052050u; return 0; }
r[3]=0x00000024u;
goto P_0c052052;
P_0c052052: /* original b0d5, guest PC 0x0c052052 */
if(!s->budget--) { s->failed_pc=0x0c052052u; return 0; }
target=0x0c052200u; r[16]=0x0c052056u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052056u) { target=s->pc; goto dispatch; }
goto P_0c052056;
P_0c052054: /* original 0009, guest PC 0x0c052054 */
if(!s->budget--) { s->failed_pc=0x0c052054u; return 0; }
goto P_0c052056;
P_0c052056: /* original 64c3, guest PC 0x0c052056 */
if(!s->budget--) { s->failed_pc=0x0c052056u; return 0; }
r[4]=r[12];
goto P_0c052058;
P_0c052058: /* original e06c, guest PC 0x0c052058 */
if(!s->budget--) { s->failed_pc=0x0c052058u; return 0; }
r[0]=0x0000006cu;
goto P_0c05205a;
P_0c05205a: /* original e134, guest PC 0x0c05205a */
if(!s->budget--) { s->failed_pc=0x0c05205au; return 0; }
r[1]=0x00000034u;
goto P_0c05205c;
P_0c05205c: /* original b0ba, guest PC 0x0c05205c */
if(!s->budget--) { s->failed_pc=0x0c05205cu; return 0; }
target=0x0c0521d4u; r[16]=0x0c052060u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052060u) { target=s->pc; goto dispatch; }
goto P_0c052060;
P_0c05205e: /* original 0009, guest PC 0x0c05205e */
if(!s->budget--) { s->failed_pc=0x0c05205eu; return 0; }
goto P_0c052060;
P_0c052060: /* original 04c2, guest PC 0x0c052060 */
if(!s->budget--) { s->failed_pc=0x0c052060u; return 0; }
if(!s->bank_known) goto unsupported;
r[4]=s->bank[4];
goto P_0c052062;
P_0c052062: /* original e06c, guest PC 0x0c052062 */
if(!s->budget--) { s->failed_pc=0x0c052062u; return 0; }
r[0]=0x0000006cu;
goto P_0c052064;
P_0c052064: /* original e134, guest PC 0x0c052064 */
if(!s->budget--) { s->failed_pc=0x0c052064u; return 0; }
r[1]=0x00000034u;
goto P_0c052066;
P_0c052066: /* original e268, guest PC 0x0c052066 */
if(!s->budget--) { s->failed_pc=0x0c052066u; return 0; }
r[2]=0x00000068u;
goto P_0c052068;
P_0c052068: /* original e324, guest PC 0x0c052068 */
if(!s->budget--) { s->failed_pc=0x0c052068u; return 0; }
r[3]=0x00000024u;
goto P_0c05206a;
P_0c05206a: /* original b0c9, guest PC 0x0c05206a */
if(!s->budget--) { s->failed_pc=0x0c05206au; return 0; }
target=0x0c052200u; r[16]=0x0c05206eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05206eu) { target=s->pc; goto dispatch; }
goto P_0c05206e;
P_0c05206c: /* original 0009, guest PC 0x0c05206c */
if(!s->budget--) { s->failed_pc=0x0c05206cu; return 0; }
goto P_0c05206e;
P_0c05206e: /* original a069, guest PC 0x0c05206e */
if(!s->budget--) { s->failed_pc=0x0c05206eu; return 0; }
goto P_0c052144;
P_0c052070: /* original 0009, guest PC 0x0c052070 */
if(!s->budget--) { s->failed_pc=0x0c052070u; return 0; }
return vf3_matrix_family(0x0c052072u,s,ram);
P_0c052078: /* original 64c3, guest PC 0x0c052078 */
if(!s->budget--) { s->failed_pc=0x0c052078u; return 0; }
r[4]=r[12];
goto P_0c05207a;
P_0c05207a: /* original e064, guest PC 0x0c05207a */
if(!s->budget--) { s->failed_pc=0x0c05207au; return 0; }
r[0]=0x00000064u;
goto P_0c05207c;
P_0c05207c: /* original e114, guest PC 0x0c05207c */
if(!s->budget--) { s->failed_pc=0x0c05207cu; return 0; }
r[1]=0x00000014u;
goto P_0c05207e;
P_0c05207e: /* original b0a9, guest PC 0x0c05207e */
if(!s->budget--) { s->failed_pc=0x0c05207eu; return 0; }
target=0x0c0521d4u; r[16]=0x0c052082u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052082u) { target=s->pc; goto dispatch; }
goto P_0c052082;
P_0c052080: /* original 0009, guest PC 0x0c052080 */
if(!s->budget--) { s->failed_pc=0x0c052080u; return 0; }
goto P_0c052082;
P_0c052082: /* original 64c3, guest PC 0x0c052082 */
if(!s->budget--) { s->failed_pc=0x0c052082u; return 0; }
r[4]=r[12];
goto P_0c052084;
P_0c052084: /* original e064, guest PC 0x0c052084 */
if(!s->budget--) { s->failed_pc=0x0c052084u; return 0; }
r[0]=0x00000064u;
goto P_0c052086;
P_0c052086: /* original e114, guest PC 0x0c052086 */
if(!s->budget--) { s->failed_pc=0x0c052086u; return 0; }
r[1]=0x00000014u;
goto P_0c052088;
P_0c052088: /* original e268, guest PC 0x0c052088 */
if(!s->budget--) { s->failed_pc=0x0c052088u; return 0; }
r[2]=0x00000068u;
goto P_0c05208a;
P_0c05208a: /* original e324, guest PC 0x0c05208a */
if(!s->budget--) { s->failed_pc=0x0c05208au; return 0; }
r[3]=0x00000024u;
goto P_0c05208c;
P_0c05208c: /* original b0b8, guest PC 0x0c05208c */
if(!s->budget--) { s->failed_pc=0x0c05208cu; return 0; }
target=0x0c052200u; r[16]=0x0c052090u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052090u) { target=s->pc; goto dispatch; }
goto P_0c052090;
P_0c05208e: /* original 0009, guest PC 0x0c05208e */
if(!s->budget--) { s->failed_pc=0x0c05208eu; return 0; }
goto P_0c052090;
P_0c052090: /* original 04c2, guest PC 0x0c052090 */
if(!s->budget--) { s->failed_pc=0x0c052090u; return 0; }
if(!s->bank_known) goto unsupported;
r[4]=s->bank[4];
goto P_0c052092;
P_0c052092: /* original e064, guest PC 0x0c052092 */
if(!s->budget--) { s->failed_pc=0x0c052092u; return 0; }
r[0]=0x00000064u;
goto P_0c052094;
P_0c052094: /* original e114, guest PC 0x0c052094 */
if(!s->budget--) { s->failed_pc=0x0c052094u; return 0; }
r[1]=0x00000014u;
goto P_0c052096;
P_0c052096: /* original e26c, guest PC 0x0c052096 */
if(!s->budget--) { s->failed_pc=0x0c052096u; return 0; }
r[2]=0x0000006cu;
goto P_0c052098;
P_0c052098: /* original e334, guest PC 0x0c052098 */
if(!s->budget--) { s->failed_pc=0x0c052098u; return 0; }
r[3]=0x00000034u;
goto P_0c05209a;
P_0c05209a: /* original b0b1, guest PC 0x0c05209a */
if(!s->budget--) { s->failed_pc=0x0c05209au; return 0; }
target=0x0c052200u; r[16]=0x0c05209eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05209eu) { target=s->pc; goto dispatch; }
goto P_0c05209e;
P_0c05209c: /* original 0009, guest PC 0x0c05209c */
if(!s->budget--) { s->failed_pc=0x0c05209cu; return 0; }
goto P_0c05209e;
P_0c05209e: /* original a051, guest PC 0x0c05209e */
if(!s->budget--) { s->failed_pc=0x0c05209eu; return 0; }
goto P_0c052144;
P_0c0520a0: /* original 0009, guest PC 0x0c0520a0 */
if(!s->budget--) { s->failed_pc=0x0c0520a0u; return 0; }
goto P_0c0520a2;
P_0c0520a2: /* original d012, guest PC 0x0c0520a2 */
if(!s->budget--) { s->failed_pc=0x0c0520a2u; return 0; }
r[0]=read(ram,0x0c0520ecu,4);
goto P_0c0520a4;
P_0c0520a4: /* original 2049, guest PC 0x0c0520a4 */
if(!s->budget--) { s->failed_pc=0x0c0520a4u; return 0; }
r[0]&=r[4];
goto P_0c0520a6;
P_0c0520a6: /* original 4015, guest PC 0x0c0520a6 */
if(!s->budget--) { s->failed_pc=0x0c0520a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0520a8;
P_0c0520a8: /* original 8d39, guest PC 0x0c0520a8 */
if(!s->budget--) { s->failed_pc=0x0c0520a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05211e; }
goto P_0c0520ac;
P_0c0520aa: /* original 0009, guest PC 0x0c0520aa */
if(!s->budget--) { s->failed_pc=0x0c0520aau; return 0; }
goto P_0c0520ac;
P_0c0520ac: /* original d010, guest PC 0x0c0520ac */
if(!s->budget--) { s->failed_pc=0x0c0520acu; return 0; }
r[0]=read(ram,0x0c0520f0u,4);
goto P_0c0520ae;
P_0c0520ae: /* original 2049, guest PC 0x0c0520ae */
if(!s->budget--) { s->failed_pc=0x0c0520aeu; return 0; }
r[0]&=r[4];
goto P_0c0520b0;
P_0c0520b0: /* original 4015, guest PC 0x0c0520b0 */
if(!s->budget--) { s->failed_pc=0x0c0520b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0520b2;
P_0c0520b2: /* original 8d1f, guest PC 0x0c0520b2 */
if(!s->budget--) { s->failed_pc=0x0c0520b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0520f4; }
goto P_0c0520b6;
P_0c0520b4: /* original 0009, guest PC 0x0c0520b4 */
if(!s->budget--) { s->failed_pc=0x0c0520b4u; return 0; }
goto P_0c0520b6;
P_0c0520b6: /* original 64c3, guest PC 0x0c0520b6 */
if(!s->budget--) { s->failed_pc=0x0c0520b6u; return 0; }
r[4]=r[12];
goto P_0c0520b8;
P_0c0520b8: /* original e068, guest PC 0x0c0520b8 */
if(!s->budget--) { s->failed_pc=0x0c0520b8u; return 0; }
r[0]=0x00000068u;
goto P_0c0520ba;
P_0c0520ba: /* original e124, guest PC 0x0c0520ba */
if(!s->budget--) { s->failed_pc=0x0c0520bau; return 0; }
r[1]=0x00000024u;
goto P_0c0520bc;
P_0c0520bc: /* original e264, guest PC 0x0c0520bc */
if(!s->budget--) { s->failed_pc=0x0c0520bcu; return 0; }
r[2]=0x00000064u;
goto P_0c0520be;
P_0c0520be: /* original e314, guest PC 0x0c0520be */
if(!s->budget--) { s->failed_pc=0x0c0520beu; return 0; }
r[3]=0x00000014u;
goto P_0c0520c0;
P_0c0520c0: /* original b09e, guest PC 0x0c0520c0 */
if(!s->budget--) { s->failed_pc=0x0c0520c0u; return 0; }
target=0x0c052200u; r[16]=0x0c0520c4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0520c4u) { target=s->pc; goto dispatch; }
goto P_0c0520c4;
P_0c0520c2: /* original 0009, guest PC 0x0c0520c2 */
if(!s->budget--) { s->failed_pc=0x0c0520c2u; return 0; }
goto P_0c0520c4;
P_0c0520c4: /* original 64c3, guest PC 0x0c0520c4 */
if(!s->budget--) { s->failed_pc=0x0c0520c4u; return 0; }
r[4]=r[12];
goto P_0c0520c6;
P_0c0520c6: /* original e068, guest PC 0x0c0520c6 */
if(!s->budget--) { s->failed_pc=0x0c0520c6u; return 0; }
r[0]=0x00000068u;
goto P_0c0520c8;
P_0c0520c8: /* original e124, guest PC 0x0c0520c8 */
if(!s->budget--) { s->failed_pc=0x0c0520c8u; return 0; }
r[1]=0x00000024u;
goto P_0c0520ca;
P_0c0520ca: /* original b083, guest PC 0x0c0520ca */
if(!s->budget--) { s->failed_pc=0x0c0520cau; return 0; }
target=0x0c0521d4u; r[16]=0x0c0520ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0520ceu) { target=s->pc; goto dispatch; }
goto P_0c0520ce;
P_0c0520cc: /* original 0009, guest PC 0x0c0520cc */
if(!s->budget--) { s->failed_pc=0x0c0520ccu; return 0; }
goto P_0c0520ce;
P_0c0520ce: /* original 64c3, guest PC 0x0c0520ce */
if(!s->budget--) { s->failed_pc=0x0c0520ceu; return 0; }
r[4]=r[12];
goto P_0c0520d0;
P_0c0520d0: /* original e06c, guest PC 0x0c0520d0 */
if(!s->budget--) { s->failed_pc=0x0c0520d0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0520d2;
P_0c0520d2: /* original e134, guest PC 0x0c0520d2 */
if(!s->budget--) { s->failed_pc=0x0c0520d2u; return 0; }
r[1]=0x00000034u;
goto P_0c0520d4;
P_0c0520d4: /* original e264, guest PC 0x0c0520d4 */
if(!s->budget--) { s->failed_pc=0x0c0520d4u; return 0; }
r[2]=0x00000064u;
goto P_0c0520d6;
P_0c0520d6: /* original e314, guest PC 0x0c0520d6 */
if(!s->budget--) { s->failed_pc=0x0c0520d6u; return 0; }
r[3]=0x00000014u;
goto P_0c0520d8;
P_0c0520d8: /* original b092, guest PC 0x0c0520d8 */
if(!s->budget--) { s->failed_pc=0x0c0520d8u; return 0; }
target=0x0c052200u; r[16]=0x0c0520dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0520dcu) { target=s->pc; goto dispatch; }
goto P_0c0520dc;
P_0c0520da: /* original 0009, guest PC 0x0c0520da */
if(!s->budget--) { s->failed_pc=0x0c0520dau; return 0; }
goto P_0c0520dc;
P_0c0520dc: /* original 04c2, guest PC 0x0c0520dc */
if(!s->budget--) { s->failed_pc=0x0c0520dcu; return 0; }
if(!s->bank_known) goto unsupported;
r[4]=s->bank[4];
goto P_0c0520de;
P_0c0520de: /* original e06c, guest PC 0x0c0520de */
if(!s->budget--) { s->failed_pc=0x0c0520deu; return 0; }
r[0]=0x0000006cu;
goto P_0c0520e0;
P_0c0520e0: /* original e134, guest PC 0x0c0520e0 */
if(!s->budget--) { s->failed_pc=0x0c0520e0u; return 0; }
r[1]=0x00000034u;
goto P_0c0520e2;
P_0c0520e2: /* original b077, guest PC 0x0c0520e2 */
if(!s->budget--) { s->failed_pc=0x0c0520e2u; return 0; }
target=0x0c0521d4u; r[16]=0x0c0520e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0520e6u) { target=s->pc; goto dispatch; }
goto P_0c0520e6;
P_0c0520e4: /* original 0009, guest PC 0x0c0520e4 */
if(!s->budget--) { s->failed_pc=0x0c0520e4u; return 0; }
goto P_0c0520e6;
P_0c0520e6: /* original a02d, guest PC 0x0c0520e6 */
if(!s->budget--) { s->failed_pc=0x0c0520e6u; return 0; }
goto P_0c052144;
P_0c0520e8: /* original 0009, guest PC 0x0c0520e8 */
if(!s->budget--) { s->failed_pc=0x0c0520e8u; return 0; }
return vf3_matrix_family(0x0c0520eau,s,ram);
P_0c0520f4: /* original 64c3, guest PC 0x0c0520f4 */
if(!s->budget--) { s->failed_pc=0x0c0520f4u; return 0; }
r[4]=r[12];
goto P_0c0520f6;
P_0c0520f6: /* original e068, guest PC 0x0c0520f6 */
if(!s->budget--) { s->failed_pc=0x0c0520f6u; return 0; }
r[0]=0x00000068u;
goto P_0c0520f8;
P_0c0520f8: /* original e124, guest PC 0x0c0520f8 */
if(!s->budget--) { s->failed_pc=0x0c0520f8u; return 0; }
r[1]=0x00000024u;
goto P_0c0520fa;
P_0c0520fa: /* original e264, guest PC 0x0c0520fa */
if(!s->budget--) { s->failed_pc=0x0c0520fau; return 0; }
r[2]=0x00000064u;
goto P_0c0520fc;
P_0c0520fc: /* original e314, guest PC 0x0c0520fc */
if(!s->budget--) { s->failed_pc=0x0c0520fcu; return 0; }
r[3]=0x00000014u;
goto P_0c0520fe;
P_0c0520fe: /* original b07f, guest PC 0x0c0520fe */
if(!s->budget--) { s->failed_pc=0x0c0520feu; return 0; }
target=0x0c052200u; r[16]=0x0c052102u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052102u) { target=s->pc; goto dispatch; }
goto P_0c052102;
P_0c052100: /* original 0009, guest PC 0x0c052100 */
if(!s->budget--) { s->failed_pc=0x0c052100u; return 0; }
goto P_0c052102;
P_0c052102: /* original 64c3, guest PC 0x0c052102 */
if(!s->budget--) { s->failed_pc=0x0c052102u; return 0; }
r[4]=r[12];
goto P_0c052104;
P_0c052104: /* original e068, guest PC 0x0c052104 */
if(!s->budget--) { s->failed_pc=0x0c052104u; return 0; }
r[0]=0x00000068u;
goto P_0c052106;
P_0c052106: /* original e124, guest PC 0x0c052106 */
if(!s->budget--) { s->failed_pc=0x0c052106u; return 0; }
r[1]=0x00000024u;
goto P_0c052108;
P_0c052108: /* original b064, guest PC 0x0c052108 */
if(!s->budget--) { s->failed_pc=0x0c052108u; return 0; }
target=0x0c0521d4u; r[16]=0x0c05210cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05210cu) { target=s->pc; goto dispatch; }
goto P_0c05210c;
P_0c05210a: /* original 0009, guest PC 0x0c05210a */
if(!s->budget--) { s->failed_pc=0x0c05210au; return 0; }
goto P_0c05210c;
P_0c05210c: /* original 04c2, guest PC 0x0c05210c */
if(!s->budget--) { s->failed_pc=0x0c05210cu; return 0; }
if(!s->bank_known) goto unsupported;
r[4]=s->bank[4];
goto P_0c05210e;
P_0c05210e: /* original e068, guest PC 0x0c05210e */
if(!s->budget--) { s->failed_pc=0x0c05210eu; return 0; }
r[0]=0x00000068u;
goto P_0c052110;
P_0c052110: /* original e124, guest PC 0x0c052110 */
if(!s->budget--) { s->failed_pc=0x0c052110u; return 0; }
r[1]=0x00000024u;
goto P_0c052112;
P_0c052112: /* original e26c, guest PC 0x0c052112 */
if(!s->budget--) { s->failed_pc=0x0c052112u; return 0; }
r[2]=0x0000006cu;
goto P_0c052114;
P_0c052114: /* original e334, guest PC 0x0c052114 */
if(!s->budget--) { s->failed_pc=0x0c052114u; return 0; }
r[3]=0x00000034u;
goto P_0c052116;
P_0c052116: /* original b073, guest PC 0x0c052116 */
if(!s->budget--) { s->failed_pc=0x0c052116u; return 0; }
target=0x0c052200u; r[16]=0x0c05211au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05211au) { target=s->pc; goto dispatch; }
goto P_0c05211a;
P_0c052118: /* original 0009, guest PC 0x0c052118 */
if(!s->budget--) { s->failed_pc=0x0c052118u; return 0; }
goto P_0c05211a;
P_0c05211a: /* original a013, guest PC 0x0c05211a */
if(!s->budget--) { s->failed_pc=0x0c05211au; return 0; }
goto P_0c052144;
P_0c05211c: /* original 0009, guest PC 0x0c05211c */
if(!s->budget--) { s->failed_pc=0x0c05211cu; return 0; }
goto P_0c05211e;
P_0c05211e: /* original 64c3, guest PC 0x0c05211e */
if(!s->budget--) { s->failed_pc=0x0c05211eu; return 0; }
r[4]=r[12];
goto P_0c052120;
P_0c052120: /* original e06c, guest PC 0x0c052120 */
if(!s->budget--) { s->failed_pc=0x0c052120u; return 0; }
r[0]=0x0000006cu;
goto P_0c052122;
P_0c052122: /* original e134, guest PC 0x0c052122 */
if(!s->budget--) { s->failed_pc=0x0c052122u; return 0; }
r[1]=0x00000034u;
goto P_0c052124;
P_0c052124: /* original e264, guest PC 0x0c052124 */
if(!s->budget--) { s->failed_pc=0x0c052124u; return 0; }
r[2]=0x00000064u;
goto P_0c052126;
P_0c052126: /* original e314, guest PC 0x0c052126 */
if(!s->budget--) { s->failed_pc=0x0c052126u; return 0; }
r[3]=0x00000014u;
goto P_0c052128;
P_0c052128: /* original b06a, guest PC 0x0c052128 */
if(!s->budget--) { s->failed_pc=0x0c052128u; return 0; }
target=0x0c052200u; r[16]=0x0c05212cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05212cu) { target=s->pc; goto dispatch; }
goto P_0c05212c;
P_0c05212a: /* original 0009, guest PC 0x0c05212a */
if(!s->budget--) { s->failed_pc=0x0c05212au; return 0; }
goto P_0c05212c;
P_0c05212c: /* original 64c3, guest PC 0x0c05212c */
if(!s->budget--) { s->failed_pc=0x0c05212cu; return 0; }
r[4]=r[12];
goto P_0c05212e;
P_0c05212e: /* original e06c, guest PC 0x0c05212e */
if(!s->budget--) { s->failed_pc=0x0c05212eu; return 0; }
r[0]=0x0000006cu;
goto P_0c052130;
P_0c052130: /* original e134, guest PC 0x0c052130 */
if(!s->budget--) { s->failed_pc=0x0c052130u; return 0; }
r[1]=0x00000034u;
goto P_0c052132;
P_0c052132: /* original e268, guest PC 0x0c052132 */
if(!s->budget--) { s->failed_pc=0x0c052132u; return 0; }
r[2]=0x00000068u;
goto P_0c052134;
P_0c052134: /* original e324, guest PC 0x0c052134 */
if(!s->budget--) { s->failed_pc=0x0c052134u; return 0; }
r[3]=0x00000024u;
goto P_0c052136;
P_0c052136: /* original b063, guest PC 0x0c052136 */
if(!s->budget--) { s->failed_pc=0x0c052136u; return 0; }
target=0x0c052200u; r[16]=0x0c05213au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05213au) { target=s->pc; goto dispatch; }
goto P_0c05213a;
P_0c052138: /* original 0009, guest PC 0x0c052138 */
if(!s->budget--) { s->failed_pc=0x0c052138u; return 0; }
goto P_0c05213a;
P_0c05213a: /* original 04c2, guest PC 0x0c05213a */
if(!s->budget--) { s->failed_pc=0x0c05213au; return 0; }
if(!s->bank_known) goto unsupported;
r[4]=s->bank[4];
goto P_0c05213c;
P_0c05213c: /* original e06c, guest PC 0x0c05213c */
if(!s->budget--) { s->failed_pc=0x0c05213cu; return 0; }
r[0]=0x0000006cu;
goto P_0c05213e;
P_0c05213e: /* original e134, guest PC 0x0c05213e */
if(!s->budget--) { s->failed_pc=0x0c05213eu; return 0; }
r[1]=0x00000034u;
goto P_0c052140;
P_0c052140: /* original b048, guest PC 0x0c052140 */
if(!s->budget--) { s->failed_pc=0x0c052140u; return 0; }
target=0x0c0521d4u; r[16]=0x0c052144u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052144u) { target=s->pc; goto dispatch; }
goto P_0c052144;
P_0c052142: /* original 0009, guest PC 0x0c052142 */
if(!s->budget--) { s->failed_pc=0x0c052142u; return 0; }
goto P_0c052144;
P_0c052144: /* original e101, guest PC 0x0c052144 */
if(!s->budget--) { s->failed_pc=0x0c052144u; return 0; }
r[1]=0x00000001u;
goto P_0c052146;
P_0c052146: /* original 4118, guest PC 0x0c052146 */
if(!s->budget--) { s->failed_pc=0x0c052146u; return 0; }
r[1]<<=8;
goto P_0c052148;
P_0c052148: /* original 3f1c, guest PC 0x0c052148 */
if(!s->budget--) { s->failed_pc=0x0c052148u; return 0; }
r[15]+=r[1];
goto P_0c05214a;
P_0c05214a: /* original 4f26, guest PC 0x0c05214a */
if(!s->budget--) { s->failed_pc=0x0c05214au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05214c;
P_0c05214c: /* original f0f9, guest PC 0x0c05214c */
if(!s->budget--) { s->failed_pc=0x0c05214cu; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05214e;
P_0c05214e: /* original f1f9, guest PC 0x0c05214e */
if(!s->budget--) { s->failed_pc=0x0c05214eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052150;
P_0c052150: /* original f2f9, guest PC 0x0c052150 */
if(!s->budget--) { s->failed_pc=0x0c052150u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052152;
P_0c052152: /* original f3f9, guest PC 0x0c052152 */
if(!s->budget--) { s->failed_pc=0x0c052152u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052154;
P_0c052154: /* original f4f9, guest PC 0x0c052154 */
if(!s->budget--) { s->failed_pc=0x0c052154u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052156;
P_0c052156: /* original f5f9, guest PC 0x0c052156 */
if(!s->budget--) { s->failed_pc=0x0c052156u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052158;
P_0c052158: /* original f6f9, guest PC 0x0c052158 */
if(!s->budget--) { s->failed_pc=0x0c052158u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05215a;
P_0c05215a: /* original f7f9, guest PC 0x0c05215a */
if(!s->budget--) { s->failed_pc=0x0c05215au; return 0; }
vf3_matrix_load(s,ram,7,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05215c;
P_0c05215c: /* original f8f9, guest PC 0x0c05215c */
if(!s->budget--) { s->failed_pc=0x0c05215cu; return 0; }
vf3_matrix_load(s,ram,8,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05215e;
P_0c05215e: /* original f9f9, guest PC 0x0c05215e */
if(!s->budget--) { s->failed_pc=0x0c05215eu; return 0; }
vf3_matrix_load(s,ram,9,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052160;
P_0c052160: /* original faf9, guest PC 0x0c052160 */
if(!s->budget--) { s->failed_pc=0x0c052160u; return 0; }
vf3_matrix_load(s,ram,10,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052162;
P_0c052162: /* original fbf9, guest PC 0x0c052162 */
if(!s->budget--) { s->failed_pc=0x0c052162u; return 0; }
vf3_matrix_load(s,ram,11,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052164;
P_0c052164: /* original fcf9, guest PC 0x0c052164 */
if(!s->budget--) { s->failed_pc=0x0c052164u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052166;
P_0c052166: /* original fdf9, guest PC 0x0c052166 */
if(!s->budget--) { s->failed_pc=0x0c052166u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c052168;
P_0c052168: /* original fef9, guest PC 0x0c052168 */
if(!s->budget--) { s->failed_pc=0x0c052168u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05216a;
P_0c05216a: /* original fff9, guest PC 0x0c05216a */
if(!s->budget--) { s->failed_pc=0x0c05216au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05216c;
P_0c05216c: /* original 60f6, guest PC 0x0c05216c */
if(!s->budget--) { s->failed_pc=0x0c05216cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c05216e;
P_0c05216e: /* original 61f6, guest PC 0x0c05216e */
if(!s->budget--) { s->failed_pc=0x0c05216eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c052170;
P_0c052170: /* original 62f6, guest PC 0x0c052170 */
if(!s->budget--) { s->failed_pc=0x0c052170u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c052172;
P_0c052172: /* original 63f6, guest PC 0x0c052172 */
if(!s->budget--) { s->failed_pc=0x0c052172u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c052174;
P_0c052174: /* original 64f6, guest PC 0x0c052174 */
if(!s->budget--) { s->failed_pc=0x0c052174u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c052176;
P_0c052176: /* original 65f6, guest PC 0x0c052176 */
if(!s->budget--) { s->failed_pc=0x0c052176u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c052178;
P_0c052178: /* original 66f6, guest PC 0x0c052178 */
if(!s->budget--) { s->failed_pc=0x0c052178u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c05217a;
P_0c05217a: /* original 67f6, guest PC 0x0c05217a */
if(!s->budget--) { s->failed_pc=0x0c05217au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c05217c;
P_0c05217c: /* original 68f6, guest PC 0x0c05217c */
if(!s->budget--) { s->failed_pc=0x0c05217cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05217e;
P_0c05217e: /* original 69f6, guest PC 0x0c05217e */
if(!s->budget--) { s->failed_pc=0x0c05217eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c052180;
P_0c052180: /* original 6af6, guest PC 0x0c052180 */
if(!s->budget--) { s->failed_pc=0x0c052180u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c052182;
P_0c052182: /* original 6bf6, guest PC 0x0c052182 */
if(!s->budget--) { s->failed_pc=0x0c052182u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c052184;
P_0c052184: /* original 6df6, guest PC 0x0c052184 */
if(!s->budget--) { s->failed_pc=0x0c052184u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c052186;
P_0c052186: /* original 6ef6, guest PC 0x0c052186 */
if(!s->budget--) { s->failed_pc=0x0c052186u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c052188;
P_0c052188: /* original 69f6, guest PC 0x0c052188 */
if(!s->budget--) { s->failed_pc=0x0c052188u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05218a;
P_0c05218a: /* original 6af6, guest PC 0x0c05218a */
if(!s->budget--) { s->failed_pc=0x0c05218au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05218c;
P_0c05218c: /* original 000b, guest PC 0x0c05218c */
if(!s->budget--) { s->failed_pc=0x0c05218cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05218e: /* original 0009, guest PC 0x0c05218e */
if(!s->budget--) { s->failed_pc=0x0c05218eu; return 0; }
goto P_0c052190;
P_0c052190: /* original 7c20, guest PC 0x0c052190 */
if(!s->budget--) { s->failed_pc=0x0c052190u; return 0; }
r[12]+=0x00000020u;
goto P_0c052192;
P_0c052192: /* original e000, guest PC 0x0c052192 */
if(!s->budget--) { s->failed_pc=0x0c052192u; return 0; }
r[0]=0x00000000u;
goto P_0c052194;
P_0c052194: /* original 2c06, guest PC 0x0c052194 */
if(!s->budget--) { s->failed_pc=0x0c052194u; return 0; }
r[12]-=4; write(ram,r[12],r[0],4);
goto P_0c052196;
P_0c052196: /* original fcbb, guest PC 0x0c052196 */
if(!s->budget--) { s->failed_pc=0x0c052196u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,11,r[12]);
goto P_0c052198;
P_0c052198: /* original fc9b, guest PC 0x0c052198 */
if(!s->budget--) { s->failed_pc=0x0c052198u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c05219a;
P_0c05219a: /* original fc8b, guest PC 0x0c05219a */
if(!s->budget--) { s->failed_pc=0x0c05219au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c05219c;
P_0c05219c: /* original fc6b, guest PC 0x0c05219c */
if(!s->budget--) { s->failed_pc=0x0c05219cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c05219e;
P_0c05219e: /* original fc5b, guest PC 0x0c05219e */
if(!s->budget--) { s->failed_pc=0x0c05219eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c0521a0;
P_0c0521a0: /* original fc4b, guest PC 0x0c0521a0 */
if(!s->budget--) { s->failed_pc=0x0c0521a0u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c0521a2;
P_0c0521a2: /* original 2c46, guest PC 0x0c0521a2 */
if(!s->budget--) { s->failed_pc=0x0c0521a2u; return 0; }
r[12]-=4; write(ram,r[12],r[4],4);
goto P_0c0521a4;
P_0c0521a4: /* original 0c83, guest PC 0x0c0521a4 */
if(!s->budget--) { s->failed_pc=0x0c0521a4u; return 0; }
goto P_0c0521a6;
P_0c0521a6: /* original 000b, guest PC 0x0c0521a6 */
if(!s->budget--) { s->failed_pc=0x0c0521a6u; return 0; }
target=r[16];
r[12]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c0521a8: /* original 7c20, guest PC 0x0c0521a8 */
if(!s->budget--) { s->failed_pc=0x0c0521a8u; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c0521aau,s,ram);
P_0c052200: /* original 4f22, guest PC 0x0c052200 */
if(!s->budget--) { s->failed_pc=0x0c052200u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c052202;
P_0c052202: /* original 31ec, guest PC 0x0c052202 */
if(!s->budget--) { s->failed_pc=0x0c052202u; return 0; }
r[1]+=r[14];
goto P_0c052204;
P_0c052204: /* original f419, guest PC 0x0c052204 */
if(!s->budget--) { s->failed_pc=0x0c052204u; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052206;
P_0c052206: /* original f519, guest PC 0x0c052206 */
if(!s->budget--) { s->failed_pc=0x0c052206u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c052208;
P_0c052208: /* original f619, guest PC 0x0c052208 */
if(!s->budget--) { s->failed_pc=0x0c052208u; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c05220a;
P_0c05220a: /* original 6813, guest PC 0x0c05220a */
if(!s->budget--) { s->failed_pc=0x0c05220au; return 0; }
r[8]=r[1];
goto P_0c05220c;
P_0c05220c: /* original 33ec, guest PC 0x0c05220c */
if(!s->budget--) { s->failed_pc=0x0c05220cu; return 0; }
r[3]+=r[14];
goto P_0c05220e;
P_0c05220e: /* original f839, guest PC 0x0c05220e */
if(!s->budget--) { s->failed_pc=0x0c05220eu; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052210;
P_0c052210: /* original f939, guest PC 0x0c052210 */
if(!s->budget--) { s->failed_pc=0x0c052210u; return 0; }
vf3_matrix_load(s,ram,9,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052212;
P_0c052212: /* original fa39, guest PC 0x0c052212 */
if(!s->budget--) { s->failed_pc=0x0c052212u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c052214;
P_0c052214: /* original 6933, guest PC 0x0c052214 */
if(!s->budget--) { s->failed_pc=0x0c052214u; return 0; }
r[9]=r[3];
goto P_0c052216;
P_0c052216: /* original 06ee, guest PC 0x0c052216 */
if(!s->budget--) { s->failed_pc=0x0c052216u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c052218;
P_0c052218: /* original 8561, guest PC 0x0c052218 */
if(!s->budget--) { s->failed_pc=0x0c052218u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+2,2);
goto P_0c05221a;
P_0c05221a: /* original 405a, guest PC 0x0c05221a */
if(!s->budget--) { s->failed_pc=0x0c05221au; return 0; }
r[53]=r[0];
goto P_0c05221c;
P_0c05221c: /* original f02d, guest PC 0x0c05221c */
if(!s->budget--) { s->failed_pc=0x0c05221cu; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c05221e;
P_0c05221e: /* original f0f2, guest PC 0x0c05221e */
if(!s->budget--) { s->failed_pc=0x0c05221eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c052220;
P_0c052220: /* original 8562, guest PC 0x0c052220 */
if(!s->budget--) { s->failed_pc=0x0c052220u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+4,2);
goto P_0c052222;
P_0c052222: /* original 405a, guest PC 0x0c052222 */
if(!s->budget--) { s->failed_pc=0x0c052222u; return 0; }
r[53]=r[0];
goto P_0c052224;
P_0c052224: /* original f12d, guest PC 0x0c052224 */
if(!s->budget--) { s->failed_pc=0x0c052224u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c052226;
P_0c052226: /* original f1f2, guest PC 0x0c052226 */
if(!s->budget--) { s->failed_pc=0x0c052226u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'*');
goto P_0c052228;
P_0c052228: /* original 6023, guest PC 0x0c052228 */
if(!s->budget--) { s->failed_pc=0x0c052228u; return 0; }
r[0]=r[2];
goto P_0c05222a;
P_0c05222a: /* original 07ee, guest PC 0x0c05222a */
if(!s->budget--) { s->failed_pc=0x0c05222au; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c05222c;
P_0c05222c: /* original 8571, guest PC 0x0c05222c */
if(!s->budget--) { s->failed_pc=0x0c05222cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+2,2);
goto P_0c05222e;
P_0c05222e: /* original 405a, guest PC 0x0c05222e */
if(!s->budget--) { s->failed_pc=0x0c05222eu; return 0; }
r[53]=r[0];
goto P_0c052230;
P_0c052230: /* original fb2d, guest PC 0x0c052230 */
if(!s->budget--) { s->failed_pc=0x0c052230u; return 0; }
fr[11]=vf3_fpu_float(r[53],r[18]);
goto P_0c052232;
P_0c052232: /* original fbf2, guest PC 0x0c052232 */
if(!s->budget--) { s->failed_pc=0x0c052232u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[15],r[18],'*');
goto P_0c052234;
P_0c052234: /* original 8572, guest PC 0x0c052234 */
if(!s->budget--) { s->failed_pc=0x0c052234u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+4,2);
goto P_0c052236;
P_0c052236: /* original 405a, guest PC 0x0c052236 */
if(!s->budget--) { s->failed_pc=0x0c052236u; return 0; }
r[53]=r[0];
goto P_0c052238;
P_0c052238: /* original fc2d, guest PC 0x0c052238 */
if(!s->budget--) { s->failed_pc=0x0c052238u; return 0; }
fr[12]=vf3_fpu_float(r[53],r[18]);
goto P_0c05223a;
P_0c05223a: /* original fcf2, guest PC 0x0c05223a */
if(!s->budget--) { s->failed_pc=0x0c05223au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c05223c;
P_0c05223c: /* original d10c, guest PC 0x0c05223c */
if(!s->budget--) { s->failed_pc=0x0c05223cu; return 0; }
r[1]=read(ram,0x0c052270u,4);
goto P_0c05223e;
P_0c05223e: /* original d010, guest PC 0x0c05223e */
if(!s->budget--) { s->failed_pc=0x0c05223eu; return 0; }
r[0]=read(ram,0x0c052280u,4);
goto P_0c052240;
P_0c052240: /* original 410b, guest PC 0x0c052240 */
if(!s->budget--) { s->failed_pc=0x0c052240u; return 0; }
target=r[1];
r[16]=0x0c052244u;
vf3_matrix_load(s,ram,3,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c052244u) { target=s->pc; goto dispatch; }
goto P_0c052244;
P_0c052242: /* original f308, guest PC 0x0c052242 */
if(!s->budget--) { s->failed_pc=0x0c052242u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c052244;
P_0c052244: /* original 6061, guest PC 0x0c052244 */
if(!s->budget--) { s->failed_pc=0x0c052244u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[0]=tmp;
goto P_0c052246;
P_0c052246: /* original 4008, guest PC 0x0c052246 */
if(!s->budget--) { s->failed_pc=0x0c052246u; return 0; }
r[0]<<=2;
goto P_0c052248;
P_0c052248: /* original 011a, guest PC 0x0c052248 */
if(!s->budget--) { s->failed_pc=0x0c052248u; return 0; }
r[1]=r[19];
goto P_0c05224a;
P_0c05224a: /* original 4000, guest PC 0x0c05224a */
if(!s->budget--) { s->failed_pc=0x0c05224au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05224c;
P_0c05224c: /* original fe16, guest PC 0x0c05224c */
if(!s->budget--) { s->failed_pc=0x0c05224cu; return 0; }
vf3_matrix_load(s,ram,14,r[1]+r[0]);
goto P_0c05224e;
P_0c05224e: /* original 6071, guest PC 0x0c05224e */
if(!s->budget--) { s->failed_pc=0x0c05224eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[0]=tmp;
goto P_0c052250;
P_0c052250: /* original 4008, guest PC 0x0c052250 */
if(!s->budget--) { s->failed_pc=0x0c052250u; return 0; }
r[0]<<=2;
goto P_0c052252;
P_0c052252: /* original 4000, guest PC 0x0c052252 */
if(!s->budget--) { s->failed_pc=0x0c052252u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c052254;
P_0c052254: /* original fc16, guest PC 0x0c052254 */
if(!s->budget--) { s->failed_pc=0x0c052254u; return 0; }
vf3_matrix_load(s,ram,12,r[1]+r[0]);
goto P_0c052256;
P_0c052256: /* original f088, guest PC 0x0c052256 */
if(!s->budget--) { s->failed_pc=0x0c052256u; return 0; }
vf3_matrix_load(s,ram,0,r[8]);
goto P_0c052258;
P_0c052258: /* original fb98, guest PC 0x0c052258 */
if(!s->budget--) { s->failed_pc=0x0c052258u; return 0; }
vf3_matrix_load(s,ram,11,r[9]);
goto P_0c05225a;
P_0c05225a: /* original f0d2, guest PC 0x0c05225a */
if(!s->budget--) { s->failed_pc=0x0c05225au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[13],r[18],'*');
goto P_0c05225c;
P_0c05225c: /* original fb72, guest PC 0x0c05225c */
if(!s->budget--) { s->failed_pc=0x0c05225cu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'*');
goto P_0c05225e;
P_0c05225e: /* original fb00, guest PC 0x0c05225e */
if(!s->budget--) { s->failed_pc=0x0c05225eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'+');
goto P_0c052260;
P_0c052260: /* original fed2, guest PC 0x0c052260 */
if(!s->budget--) { s->failed_pc=0x0c052260u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[13],r[18],'*');
goto P_0c052262;
P_0c052262: /* original fc72, guest PC 0x0c052262 */
if(!s->budget--) { s->failed_pc=0x0c052262u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[7],r[18],'*');
goto P_0c052264;
P_0c052264: /* original fce0, guest PC 0x0c052264 */
if(!s->budget--) { s->failed_pc=0x0c052264u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[14],r[18],'+');
goto P_0c052266;
P_0c052266: /* original 4a0b, guest PC 0x0c052266 */
if(!s->budget--) { s->failed_pc=0x0c052266u; return 0; }
target=r[10];
r[16]=0x0c05226au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05226au) { target=s->pc; goto dispatch; }
goto P_0c05226a;
P_0c052268: /* original 0009, guest PC 0x0c052268 */
if(!s->budget--) { s->failed_pc=0x0c052268u; return 0; }
goto P_0c05226a;
P_0c05226a: /* original 4f26, guest PC 0x0c05226a */
if(!s->budget--) { s->failed_pc=0x0c05226au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05226c;
P_0c05226c: /* original 000b, guest PC 0x0c05226c */
if(!s->budget--) { s->failed_pc=0x0c05226cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05226e: /* original 0009, guest PC 0x0c05226e */
if(!s->budget--) { s->failed_pc=0x0c05226eu; return 0; }
return vf3_matrix_family(0x0c052270u,s,ram);
P_0c0537a0: /* original 4f22, guest PC 0x0c0537a0 */
if(!s->budget--) { s->failed_pc=0x0c0537a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0537a2;
P_0c0537a2: /* original 4f12, guest PC 0x0c0537a2 */
if(!s->budget--) { s->failed_pc=0x0c0537a2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0537a4;
P_0c0537a4: /* original 7fec, guest PC 0x0c0537a4 */
if(!s->budget--) { s->failed_pc=0x0c0537a4u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0537a6;
P_0c0537a6: /* original 1f51, guest PC 0x0c0537a6 */
if(!s->budget--) { s->failed_pc=0x0c0537a6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0537a8;
P_0c0537a8: /* original 2f62, guest PC 0x0c0537a8 */
if(!s->budget--) { s->failed_pc=0x0c0537a8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0537aa;
P_0c0537aa: /* original 9358, guest PC 0x0c0537aa */
if(!s->budget--) { s->failed_pc=0x0c0537aau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05385eu,2);
goto P_0c0537ac;
P_0c0537ac: /* original d232, guest PC 0x0c0537ac */
if(!s->budget--) { s->failed_pc=0x0c0537acu; return 0; }
r[2]=read(ram,0x0c053878u,4);
goto P_0c0537ae;
P_0c0537ae: /* original 0d37, guest PC 0x0c0537ae */
if(!s->budget--) { s->failed_pc=0x0c0537aeu; return 0; }
r[19]=r[13]*r[3];
goto P_0c0537b0;
P_0c0537b0: /* original 031a, guest PC 0x0c0537b0 */
if(!s->budget--) { s->failed_pc=0x0c0537b0u; return 0; }
r[3]=r[19];
goto P_0c0537b2;
P_0c0537b2: /* original 332c, guest PC 0x0c0537b2 */
if(!s->budget--) { s->failed_pc=0x0c0537b2u; return 0; }
r[3]+=r[2];
goto P_0c0537b4;
P_0c0537b4: /* original 1f32, guest PC 0x0c0537b4 */
if(!s->budget--) { s->failed_pc=0x0c0537b4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0537b6;
P_0c0537b6: /* original 61f2, guest PC 0x0c0537b6 */
if(!s->budget--) { s->failed_pc=0x0c0537b6u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0537b8;
P_0c0537b8: /* original de30, guest PC 0x0c0537b8 */
if(!s->budget--) { s->failed_pc=0x0c0537b8u; return 0; }
r[14]=read(ram,0x0c05387cu,4);
goto P_0c0537ba;
P_0c0537ba: /* original 2f16, guest PC 0x0c0537ba */
if(!s->budget--) { s->failed_pc=0x0c0537bau; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0537bc;
P_0c0537bc: /* original 51f2, guest PC 0x0c0537bc */
if(!s->budget--) { s->failed_pc=0x0c0537bcu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0537be;
P_0c0537be: /* original 2f16, guest PC 0x0c0537be */
if(!s->budget--) { s->failed_pc=0x0c0537beu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0537c0;
P_0c0537c0: /* original 2fd6, guest PC 0x0c0537c0 */
if(!s->budget--) { s->failed_pc=0x0c0537c0u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0537c2;
P_0c0537c2: /* original d12f, guest PC 0x0c0537c2 */
if(!s->budget--) { s->failed_pc=0x0c0537c2u; return 0; }
r[1]=read(ram,0x0c053880u,4);
goto P_0c0537c4;
P_0c0537c4: /* original 4e0b, guest PC 0x0c0537c4 */
if(!s->budget--) { s->failed_pc=0x0c0537c4u; return 0; }
target=r[14];
r[16]=0x0c0537c8u;
r[15]-=4; write(ram,r[15],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0537c8u) { target=s->pc; goto dispatch; }
goto P_0c0537c8;
P_0c0537c6: /* original 2f16, guest PC 0x0c0537c6 */
if(!s->budget--) { s->failed_pc=0x0c0537c6u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0537c8;
P_0c0537c8: /* original db2f, guest PC 0x0c0537c8 */
if(!s->budget--) { s->failed_pc=0x0c0537c8u; return 0; }
r[11]=read(ram,0x0c053888u,4);
goto P_0c0537ca;
P_0c0537ca: /* original 7f10, guest PC 0x0c0537ca */
if(!s->budget--) { s->failed_pc=0x0c0537cau; return 0; }
r[15]+=0x00000010u;
goto P_0c0537cc;
P_0c0537cc: /* original da2d, guest PC 0x0c0537cc */
if(!s->budget--) { s->failed_pc=0x0c0537ccu; return 0; }
r[10]=read(ram,0x0c053884u,4);
goto P_0c0537ce;
P_0c0537ce: /* original b289, guest PC 0x0c0537ce */
if(!s->budget--) { s->failed_pc=0x0c0537ceu; return 0; }
target=0x0c053ce4u; r[16]=0x0c0537d2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0537d2u) { target=s->pc; goto dispatch; }
goto P_0c0537d2;
P_0c0537d0: /* original 64d3, guest PC 0x0c0537d0 */
if(!s->budget--) { s->failed_pc=0x0c0537d0u; return 0; }
r[4]=r[13];
goto P_0c0537d2;
P_0c0537d2: /* original 2008, guest PC 0x0c0537d2 */
if(!s->budget--) { s->failed_pc=0x0c0537d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0537d4;
P_0c0537d4: /* original 8b05, guest PC 0x0c0537d4 */
if(!s->budget--) { s->failed_pc=0x0c0537d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0537e2; }
goto P_0c0537d6;
P_0c0537d6: /* original 4e0b, guest PC 0x0c0537d6 */
if(!s->budget--) { s->failed_pc=0x0c0537d6u; return 0; }
target=r[14];
r[16]=0x0c0537dau;
r[15]-=4; write(ram,r[15],r[10],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0537dau) { target=s->pc; goto dispatch; }
goto P_0c0537da;
P_0c0537d8: /* original 2fa6, guest PC 0x0c0537d8 */
if(!s->budget--) { s->failed_pc=0x0c0537d8u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0537da;
P_0c0537da: /* original 4b0b, guest PC 0x0c0537da */
if(!s->budget--) { s->failed_pc=0x0c0537dau; return 0; }
target=r[11];
r[16]=0x0c0537deu;
r[15]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0537deu) { target=s->pc; goto dispatch; }
goto P_0c0537de;
P_0c0537dc: /* original 7f04, guest PC 0x0c0537dc */
if(!s->budget--) { s->failed_pc=0x0c0537dcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0537de;
P_0c0537de: /* original a098, guest PC 0x0c0537de */
if(!s->budget--) { s->failed_pc=0x0c0537deu; return 0; }
goto P_0c053912;
P_0c0537e0: /* original 0009, guest PC 0x0c0537e0 */
if(!s->budget--) { s->failed_pc=0x0c0537e0u; return 0; }
goto P_0c0537e2;
P_0c0537e2: /* original d02a, guest PC 0x0c0537e2 */
if(!s->budget--) { s->failed_pc=0x0c0537e2u; return 0; }
r[0]=read(ram,0x0c05388cu,4);
goto P_0c0537e4;
P_0c0537e4: /* original 4d08, guest PC 0x0c0537e4 */
if(!s->budget--) { s->failed_pc=0x0c0537e4u; return 0; }
r[13]<<=2;
goto P_0c0537e6;
P_0c0537e6: /* original d22a, guest PC 0x0c0537e6 */
if(!s->budget--) { s->failed_pc=0x0c0537e6u; return 0; }
r[2]=read(ram,0x0c053890u,4);
goto P_0c0537e8;
P_0c0537e8: /* original 0dde, guest PC 0x0c0537e8 */
if(!s->budget--) { s->failed_pc=0x0c0537e8u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c0537ea;
P_0c0537ea: /* original 420b, guest PC 0x0c0537ea */
if(!s->budget--) { s->failed_pc=0x0c0537eau; return 0; }
target=r[2];
r[16]=0x0c0537eeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0537eeu) { target=s->pc; goto dispatch; }
goto P_0c0537ee;
P_0c0537ec: /* original 64d3, guest PC 0x0c0537ec */
if(!s->budget--) { s->failed_pc=0x0c0537ecu; return 0; }
r[4]=r[13];
goto P_0c0537ee;
P_0c0537ee: /* original 63f2, guest PC 0x0c0537ee */
if(!s->budget--) { s->failed_pc=0x0c0537eeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0537f0;
P_0c0537f0: /* original e400, guest PC 0x0c0537f0 */
if(!s->budget--) { s->failed_pc=0x0c0537f0u; return 0; }
r[4]=0x00000000u;
goto P_0c0537f2;
P_0c0537f2: /* original 1f33, guest PC 0x0c0537f2 */
if(!s->budget--) { s->failed_pc=0x0c0537f2u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0537f4;
P_0c0537f4: /* original 2f42, guest PC 0x0c0537f4 */
if(!s->budget--) { s->failed_pc=0x0c0537f4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0537f6;
P_0c0537f6: /* original a0a3, guest PC 0x0c0537f6 */
if(!s->budget--) { s->failed_pc=0x0c0537f6u; return 0; }
r[9]=r[4];
goto P_0c053940;
P_0c0537f8: /* original 6943, guest PC 0x0c0537f8 */
if(!s->budget--) { s->failed_pc=0x0c0537f8u; return 0; }
r[9]=r[4];
goto P_0c0537fa;
P_0c0537fa: /* original 53f1, guest PC 0x0c0537fa */
if(!s->budget--) { s->failed_pc=0x0c0537fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0537fc;
P_0c0537fc: /* original dc25, guest PC 0x0c0537fc */
if(!s->budget--) { s->failed_pc=0x0c0537fcu; return 0; }
r[12]=read(ram,0x0c053894u,4);
goto P_0c0537fe;
P_0c0537fe: /* original 2f36, guest PC 0x0c0537fe */
if(!s->budget--) { s->failed_pc=0x0c0537feu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c053800;
P_0c053800: /* original 2f96, guest PC 0x0c053800 */
if(!s->budget--) { s->failed_pc=0x0c053800u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c053802;
P_0c053802: /* original 2fd6, guest PC 0x0c053802 */
if(!s->budget--) { s->failed_pc=0x0c053802u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c053804;
P_0c053804: /* original 4e0b, guest PC 0x0c053804 */
if(!s->budget--) { s->failed_pc=0x0c053804u; return 0; }
target=r[14];
r[16]=0x0c053808u;
r[15]-=4; write(ram,r[15],r[12],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053808u) { target=s->pc; goto dispatch; }
goto P_0c053808;
P_0c053806: /* original 2fc6, guest PC 0x0c053806 */
if(!s->budget--) { s->failed_pc=0x0c053806u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c053808;
P_0c053808: /* original d323, guest PC 0x0c053808 */
if(!s->budget--) { s->failed_pc=0x0c053808u; return 0; }
r[3]=read(ram,0x0c053898u,4);
goto P_0c05380a;
P_0c05380a: /* original 7f10, guest PC 0x0c05380a */
if(!s->budget--) { s->failed_pc=0x0c05380au; return 0; }
r[15]+=0x00000010u;
goto P_0c05380c;
P_0c05380c: /* original 430b, guest PC 0x0c05380c */
if(!s->budget--) { s->failed_pc=0x0c05380cu; return 0; }
target=r[3];
r[16]=0x0c053810u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053810u) { target=s->pc; goto dispatch; }
goto P_0c053810;
P_0c05380e: /* original 64d3, guest PC 0x0c05380e */
if(!s->budget--) { s->failed_pc=0x0c05380eu; return 0; }
r[4]=r[13];
goto P_0c053810;
P_0c053810: /* original 2008, guest PC 0x0c053810 */
if(!s->budget--) { s->failed_pc=0x0c053810u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c053812;
P_0c053812: /* original 8b52, guest PC 0x0c053812 */
if(!s->budget--) { s->failed_pc=0x0c053812u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0538ba; }
goto P_0c053814;
P_0c053814: /* original 53f1, guest PC 0x0c053814 */
if(!s->budget--) { s->failed_pc=0x0c053814u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053816;
P_0c053816: /* original e600, guest PC 0x0c053816 */
if(!s->budget--) { s->failed_pc=0x0c053816u; return 0; }
r[6]=0x00000000u;
goto P_0c053818;
P_0c053818: /* original dc20, guest PC 0x0c053818 */
if(!s->budget--) { s->failed_pc=0x0c053818u; return 0; }
r[12]=read(ram,0x0c05389cu,4);
goto P_0c05381a;
P_0c05381a: /* original e502, guest PC 0x0c05381a */
if(!s->budget--) { s->failed_pc=0x0c05381au; return 0; }
r[5]=0x00000002u;
goto P_0c05381c;
P_0c05381c: /* original 2f36, guest PC 0x0c05381c */
if(!s->budget--) { s->failed_pc=0x0c05381cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c05381e;
P_0c05381e: /* original 6793, guest PC 0x0c05381e */
if(!s->budget--) { s->failed_pc=0x0c05381eu; return 0; }
r[7]=r[9];
goto P_0c053820;
P_0c053820: /* original 4c0b, guest PC 0x0c053820 */
if(!s->budget--) { s->failed_pc=0x0c053820u; return 0; }
target=r[12];
r[16]=0x0c053824u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053824u) { target=s->pc; goto dispatch; }
goto P_0c053824;
P_0c053822: /* original 64d3, guest PC 0x0c053822 */
if(!s->budget--) { s->failed_pc=0x0c053822u; return 0; }
r[4]=r[13];
goto P_0c053824;
P_0c053824: /* original 6c03, guest PC 0x0c053824 */
if(!s->budget--) { s->failed_pc=0x0c053824u; return 0; }
r[12]=r[0];
goto P_0c053826;
P_0c053826: /* original 4c11, guest PC 0x0c053826 */
if(!s->budget--) { s->failed_pc=0x0c053826u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c053828;
P_0c053828: /* original 8d06, guest PC 0x0c053828 */
if(!s->budget--) { s->failed_pc=0x0c053828u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c053838; }
goto P_0c05382c;
P_0c05382a: /* original 7f04, guest PC 0x0c05382a */
if(!s->budget--) { s->failed_pc=0x0c05382au; return 0; }
r[15]+=0x00000004u;
goto P_0c05382c;
P_0c05382c: /* original 4e0b, guest PC 0x0c05382c */
if(!s->budget--) { s->failed_pc=0x0c05382cu; return 0; }
target=r[14];
r[16]=0x0c053830u;
r[15]-=4; write(ram,r[15],r[10],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053830u) { target=s->pc; goto dispatch; }
goto P_0c053830;
P_0c05382e: /* original 2fa6, guest PC 0x0c05382e */
if(!s->budget--) { s->failed_pc=0x0c05382eu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c053830;
P_0c053830: /* original 4b0b, guest PC 0x0c053830 */
if(!s->budget--) { s->failed_pc=0x0c053830u; return 0; }
target=r[11];
r[16]=0x0c053834u;
r[15]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053834u) { target=s->pc; goto dispatch; }
goto P_0c053834;
P_0c053832: /* original 7f04, guest PC 0x0c053832 */
if(!s->budget--) { s->failed_pc=0x0c053832u; return 0; }
r[15]+=0x00000004u;
goto P_0c053834;
P_0c053834: /* original afe1, guest PC 0x0c053834 */
if(!s->budget--) { s->failed_pc=0x0c053834u; return 0; }
goto P_0c0537fa;
P_0c053836: /* original 0009, guest PC 0x0c053836 */
if(!s->budget--) { s->failed_pc=0x0c053836u; return 0; }
goto P_0c053838;
P_0c053838: /* original d819, guest PC 0x0c053838 */
if(!s->budget--) { s->failed_pc=0x0c053838u; return 0; }
r[8]=read(ram,0x0c0538a0u,4);
goto P_0c05383a;
P_0c05383a: /* original 2fc6, guest PC 0x0c05383a */
if(!s->budget--) { s->failed_pc=0x0c05383au; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c05383c;
P_0c05383c: /* original 2fd6, guest PC 0x0c05383c */
if(!s->budget--) { s->failed_pc=0x0c05383cu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c05383e;
P_0c05383e: /* original 4e0b, guest PC 0x0c05383e */
if(!s->budget--) { s->failed_pc=0x0c05383eu; return 0; }
target=r[14];
r[16]=0x0c053842u;
r[15]-=4; write(ram,r[15],r[8],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053842u) { target=s->pc; goto dispatch; }
goto P_0c053842;
P_0c053840: /* original 2f86, guest PC 0x0c053840 */
if(!s->budget--) { s->failed_pc=0x0c053840u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c053842;
P_0c053842: /* original d818, guest PC 0x0c053842 */
if(!s->budget--) { s->failed_pc=0x0c053842u; return 0; }
r[8]=read(ram,0x0c0538a4u,4);
goto P_0c053844;
P_0c053844: /* original 65c3, guest PC 0x0c053844 */
if(!s->budget--) { s->failed_pc=0x0c053844u; return 0; }
r[5]=r[12];
goto P_0c053846;
P_0c053846: /* original 7f0c, guest PC 0x0c053846 */
if(!s->budget--) { s->failed_pc=0x0c053846u; return 0; }
r[15]+=0x0000000cu;
goto P_0c053848;
P_0c053848: /* original 480b, guest PC 0x0c053848 */
if(!s->budget--) { s->failed_pc=0x0c053848u; return 0; }
target=r[8];
r[16]=0x0c05384cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05384cu) { target=s->pc; goto dispatch; }
goto P_0c05384c;
P_0c05384a: /* original 64d3, guest PC 0x0c05384a */
if(!s->budget--) { s->failed_pc=0x0c05384au; return 0; }
r[4]=r[13];
goto P_0c05384c;
P_0c05384c: /* original 2008, guest PC 0x0c05384c */
if(!s->budget--) { s->failed_pc=0x0c05384cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05384e;
P_0c05384e: /* original 8b2b, guest PC 0x0c05384e */
if(!s->budget--) { s->failed_pc=0x0c05384eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0538a8; }
goto P_0c053850;
P_0c053850: /* original 4e0b, guest PC 0x0c053850 */
if(!s->budget--) { s->failed_pc=0x0c053850u; return 0; }
target=r[14];
r[16]=0x0c053854u;
r[15]-=4; write(ram,r[15],r[10],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053854u) { target=s->pc; goto dispatch; }
goto P_0c053854;
P_0c053852: /* original 2fa6, guest PC 0x0c053852 */
if(!s->budget--) { s->failed_pc=0x0c053852u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c053854;
P_0c053854: /* original 4b0b, guest PC 0x0c053854 */
if(!s->budget--) { s->failed_pc=0x0c053854u; return 0; }
target=r[11];
r[16]=0x0c053858u;
r[15]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053858u) { target=s->pc; goto dispatch; }
goto P_0c053858;
P_0c053856: /* original 7f04, guest PC 0x0c053856 */
if(!s->budget--) { s->failed_pc=0x0c053856u; return 0; }
r[15]+=0x00000004u;
goto P_0c053858;
P_0c053858: /* original afee, guest PC 0x0c053858 */
if(!s->budget--) { s->failed_pc=0x0c053858u; return 0; }
goto P_0c053838;
P_0c05385a: /* original 0009, guest PC 0x0c05385a */
if(!s->budget--) { s->failed_pc=0x0c05385au; return 0; }
return vf3_matrix_family(0x0c05385cu,s,ram);
P_0c0538a8: /* original d346, guest PC 0x0c0538a8 */
if(!s->budget--) { s->failed_pc=0x0c0538a8u; return 0; }
r[3]=read(ram,0x0c0539c4u,4);
goto P_0c0538aa;
P_0c0538aa: /* original 430b, guest PC 0x0c0538aa */
if(!s->budget--) { s->failed_pc=0x0c0538aau; return 0; }
target=r[3];
r[16]=0x0c0538aeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0538aeu) { target=s->pc; goto dispatch; }
goto P_0c0538ae;
P_0c0538ac: /* original 64d3, guest PC 0x0c0538ac */
if(!s->budget--) { s->failed_pc=0x0c0538acu; return 0; }
r[4]=r[13];
goto P_0c0538ae;
P_0c0538ae: /* original d246, guest PC 0x0c0538ae */
if(!s->budget--) { s->failed_pc=0x0c0538aeu; return 0; }
r[2]=read(ram,0x0c0539c8u,4);
goto P_0c0538b0;
P_0c0538b0: /* original 6803, guest PC 0x0c0538b0 */
if(!s->budget--) { s->failed_pc=0x0c0538b0u; return 0; }
r[8]=r[0];
goto P_0c0538b2;
P_0c0538b2: /* original 420b, guest PC 0x0c0538b2 */
if(!s->budget--) { s->failed_pc=0x0c0538b2u; return 0; }
target=r[2];
r[16]=0x0c0538b6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0538b6u) { target=s->pc; goto dispatch; }
goto P_0c0538b6;
P_0c0538b4: /* original 64d3, guest PC 0x0c0538b4 */
if(!s->budget--) { s->failed_pc=0x0c0538b4u; return 0; }
r[4]=r[13];
goto P_0c0538b6;
P_0c0538b6: /* original 2008, guest PC 0x0c0538b6 */
if(!s->budget--) { s->failed_pc=0x0c0538b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0538b8;
P_0c0538b8: /* original 8904, guest PC 0x0c0538b8 */
if(!s->budget--) { s->failed_pc=0x0c0538b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0538c4; }
goto P_0c0538ba;
P_0c0538ba: /* original dd44, guest PC 0x0c0538ba */
if(!s->budget--) { s->failed_pc=0x0c0538bau; return 0; }
r[13]=read(ram,0x0c0539ccu,4);
goto P_0c0538bc;
P_0c0538bc: /* original 4e0b, guest PC 0x0c0538bc */
if(!s->budget--) { s->failed_pc=0x0c0538bcu; return 0; }
target=r[14];
r[16]=0x0c0538c0u;
r[15]-=4; write(ram,r[15],r[13],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0538c0u) { target=s->pc; goto dispatch; }
goto P_0c0538c0;
P_0c0538be: /* original 2fd6, guest PC 0x0c0538be */
if(!s->budget--) { s->failed_pc=0x0c0538beu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0538c0;
P_0c0538c0: /* original a027, guest PC 0x0c0538c0 */
if(!s->budget--) { s->failed_pc=0x0c0538c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c053912;
P_0c0538c2: /* original 7f04, guest PC 0x0c0538c2 */
if(!s->budget--) { s->failed_pc=0x0c0538c2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0538c4;
P_0c0538c4: /* original 5382, guest PC 0x0c0538c4 */
if(!s->budget--) { s->failed_pc=0x0c0538c4u; return 0; }
r[3]=read(ram,r[8]+8,4);
goto P_0c0538c6;
P_0c0538c6: /* original 1f34, guest PC 0x0c0538c6 */
if(!s->budget--) { s->failed_pc=0x0c0538c6u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0538c8;
P_0c0538c8: /* original 8484, guest PC 0x0c0538c8 */
if(!s->budget--) { s->failed_pc=0x0c0538c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+4,1);
goto P_0c0538ca;
P_0c0538ca: /* original 600c, guest PC 0x0c0538ca */
if(!s->budget--) { s->failed_pc=0x0c0538cau; return 0; }
r[0]=r[0]&255u;
goto P_0c0538cc;
P_0c0538cc: /* original 8808, guest PC 0x0c0538cc */
if(!s->budget--) { s->failed_pc=0x0c0538ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0538ce;
P_0c0538ce: /* original 8907, guest PC 0x0c0538ce */
if(!s->budget--) { s->failed_pc=0x0c0538ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0538e0; }
goto P_0c0538d0;
P_0c0538d0: /* original 9173, guest PC 0x0c0538d0 */
if(!s->budget--) { s->failed_pc=0x0c0538d0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0539bau,2);
goto P_0c0538d2;
P_0c0538d2: /* original 3010, guest PC 0x0c0538d2 */
if(!s->budget--) { s->failed_pc=0x0c0538d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0538d4;
P_0c0538d4: /* original 890e, guest PC 0x0c0538d4 */
if(!s->budget--) { s->failed_pc=0x0c0538d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0538f4; }
goto P_0c0538d6;
P_0c0538d6: /* original 9171, guest PC 0x0c0538d6 */
if(!s->budget--) { s->failed_pc=0x0c0538d6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0539bcu,2);
goto P_0c0538d8;
P_0c0538d8: /* original 3010, guest PC 0x0c0538d8 */
if(!s->budget--) { s->failed_pc=0x0c0538d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0538da;
P_0c0538da: /* original 8906, guest PC 0x0c0538da */
if(!s->budget--) { s->failed_pc=0x0c0538dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0538ea; }
goto P_0c0538dc;
P_0c0538dc: /* original a012, guest PC 0x0c0538dc */
if(!s->budget--) { s->failed_pc=0x0c0538dcu; return 0; }
goto P_0c053904;
P_0c0538de: /* original 0009, guest PC 0x0c0538de */
if(!s->budget--) { s->failed_pc=0x0c0538deu; return 0; }
goto P_0c0538e0;
P_0c0538e0: /* original d83b, guest PC 0x0c0538e0 */
if(!s->budget--) { s->failed_pc=0x0c0538e0u; return 0; }
r[8]=read(ram,0x0c0539d0u,4);
goto P_0c0538e2;
P_0c0538e2: /* original 4e0b, guest PC 0x0c0538e2 */
if(!s->budget--) { s->failed_pc=0x0c0538e2u; return 0; }
target=r[14];
r[16]=0x0c0538e6u;
r[15]-=4; write(ram,r[15],r[8],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0538e6u) { target=s->pc; goto dispatch; }
goto P_0c0538e6;
P_0c0538e4: /* original 2f86, guest PC 0x0c0538e4 */
if(!s->budget--) { s->failed_pc=0x0c0538e4u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0538e6;
P_0c0538e6: /* original a017, guest PC 0x0c0538e6 */
if(!s->budget--) { s->failed_pc=0x0c0538e6u; return 0; }
r[15]+=0x00000004u;
goto P_0c053918;
P_0c0538e8: /* original 7f04, guest PC 0x0c0538e8 */
if(!s->budget--) { s->failed_pc=0x0c0538e8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0538ea;
P_0c0538ea: /* original d83a, guest PC 0x0c0538ea */
if(!s->budget--) { s->failed_pc=0x0c0538eau; return 0; }
r[8]=read(ram,0x0c0539d4u,4);
goto P_0c0538ec;
P_0c0538ec: /* original 4e0b, guest PC 0x0c0538ec */
if(!s->budget--) { s->failed_pc=0x0c0538ecu; return 0; }
target=r[14];
r[16]=0x0c0538f0u;
r[15]-=4; write(ram,r[15],r[8],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0538f0u) { target=s->pc; goto dispatch; }
goto P_0c0538f0;
P_0c0538ee: /* original 2f86, guest PC 0x0c0538ee */
if(!s->budget--) { s->failed_pc=0x0c0538eeu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0538f0;
P_0c0538f0: /* original af83, guest PC 0x0c0538f0 */
if(!s->budget--) { s->failed_pc=0x0c0538f0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0537fa;
P_0c0538f2: /* original 7f04, guest PC 0x0c0538f2 */
if(!s->budget--) { s->failed_pc=0x0c0538f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0538f4;
P_0c0538f4: /* original 5283, guest PC 0x0c0538f4 */
if(!s->budget--) { s->failed_pc=0x0c0538f4u; return 0; }
r[2]=read(ram,r[8]+12,4);
goto P_0c0538f6;
P_0c0538f6: /* original dd38, guest PC 0x0c0538f6 */
if(!s->budget--) { s->failed_pc=0x0c0538f6u; return 0; }
r[13]=read(ram,0x0c0539d8u,4);
goto P_0c0538f8;
P_0c0538f8: /* original 2f26, guest PC 0x0c0538f8 */
if(!s->budget--) { s->failed_pc=0x0c0538f8u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0538fa;
P_0c0538fa: /* original 4e0b, guest PC 0x0c0538fa */
if(!s->budget--) { s->failed_pc=0x0c0538fau; return 0; }
target=r[14];
r[16]=0x0c0538feu;
r[15]-=4; write(ram,r[15],r[13],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0538feu) { target=s->pc; goto dispatch; }
goto P_0c0538fe;
P_0c0538fc: /* original 2fd6, guest PC 0x0c0538fc */
if(!s->budget--) { s->failed_pc=0x0c0538fcu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0538fe;
P_0c0538fe: /* original d037, guest PC 0x0c0538fe */
if(!s->budget--) { s->failed_pc=0x0c0538feu; return 0; }
r[0]=read(ram,0x0c0539dcu,4);
goto P_0c053900;
P_0c053900: /* original a027, guest PC 0x0c053900 */
if(!s->budget--) { s->failed_pc=0x0c053900u; return 0; }
r[15]+=0x00000008u;
goto P_0c053952;
P_0c053902: /* original 7f08, guest PC 0x0c053902 */
if(!s->budget--) { s->failed_pc=0x0c053902u; return 0; }
r[15]+=0x00000008u;
goto P_0c053904;
P_0c053904: /* original 8484, guest PC 0x0c053904 */
if(!s->budget--) { s->failed_pc=0x0c053904u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+4,1);
goto P_0c053906;
P_0c053906: /* original dd36, guest PC 0x0c053906 */
if(!s->budget--) { s->failed_pc=0x0c053906u; return 0; }
r[13]=read(ram,0x0c0539e0u,4);
goto P_0c053908;
P_0c053908: /* original 600c, guest PC 0x0c053908 */
if(!s->budget--) { s->failed_pc=0x0c053908u; return 0; }
r[0]=r[0]&255u;
goto P_0c05390a;
P_0c05390a: /* original 2f06, guest PC 0x0c05390a */
if(!s->budget--) { s->failed_pc=0x0c05390au; return 0; }
r[15]-=4; write(ram,r[15],r[0],4);
goto P_0c05390c;
P_0c05390c: /* original 4e0b, guest PC 0x0c05390c */
if(!s->budget--) { s->failed_pc=0x0c05390cu; return 0; }
target=r[14];
r[16]=0x0c053910u;
r[15]-=4; write(ram,r[15],r[13],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053910u) { target=s->pc; goto dispatch; }
goto P_0c053910;
P_0c05390e: /* original 2fd6, guest PC 0x0c05390e */
if(!s->budget--) { s->failed_pc=0x0c05390eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c053910;
P_0c053910: /* original 7f08, guest PC 0x0c053910 */
if(!s->budget--) { s->failed_pc=0x0c053910u; return 0; }
r[15]+=0x00000008u;
goto P_0c053912;
P_0c053912: /* original 9054, guest PC 0x0c053912 */
if(!s->budget--) { s->failed_pc=0x0c053912u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0539beu,2);
goto P_0c053914;
P_0c053914: /* original a01d, guest PC 0x0c053914 */
if(!s->budget--) { s->failed_pc=0x0c053914u; return 0; }
goto P_0c053952;
P_0c053916: /* original 0009, guest PC 0x0c053916 */
if(!s->budget--) { s->failed_pc=0x0c053916u; return 0; }
goto P_0c053918;
P_0c053918: /* original 56f2, guest PC 0x0c053918 */
if(!s->budget--) { s->failed_pc=0x0c053918u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c05391a;
P_0c05391a: /* original e044, guest PC 0x0c05391a */
if(!s->budget--) { s->failed_pc=0x0c05391au; return 0; }
r[0]=0x00000044u;
goto P_0c05391c;
P_0c05391c: /* original 55f4, guest PC 0x0c05391c */
if(!s->budget--) { s->failed_pc=0x0c05391cu; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c05391e;
P_0c05391e: /* original 5667, guest PC 0x0c05391e */
if(!s->budget--) { s->failed_pc=0x0c05391eu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c053920;
P_0c053920: /* original d830, guest PC 0x0c053920 */
if(!s->budget--) { s->failed_pc=0x0c053920u; return 0; }
r[8]=read(ram,0x0c0539e4u,4);
goto P_0c053922;
P_0c053922: /* original 750c, guest PC 0x0c053922 */
if(!s->budget--) { s->failed_pc=0x0c053922u; return 0; }
r[5]+=0x0000000cu;
goto P_0c053924;
P_0c053924: /* original 066e, guest PC 0x0c053924 */
if(!s->budget--) { s->failed_pc=0x0c053924u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c053926;
P_0c053926: /* original 480b, guest PC 0x0c053926 */
if(!s->budget--) { s->failed_pc=0x0c053926u; return 0; }
target=r[8];
r[16]=0x0c05392au;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05392au) { target=s->pc; goto dispatch; }
goto P_0c05392a;
P_0c053928: /* original 54f3, guest PC 0x0c053928 */
if(!s->budget--) { s->failed_pc=0x0c053928u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c05392a;
P_0c05392a: /* original 53f2, guest PC 0x0c05392a */
if(!s->budget--) { s->failed_pc=0x0c05392au; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05392c;
P_0c05392c: /* original e044, guest PC 0x0c05392c */
if(!s->budget--) { s->failed_pc=0x0c05392cu; return 0; }
r[0]=0x00000044u;
goto P_0c05392e;
P_0c05392e: /* original 51f3, guest PC 0x0c05392e */
if(!s->budget--) { s->failed_pc=0x0c05392eu; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c053930;
P_0c053930: /* original 7901, guest PC 0x0c053930 */
if(!s->budget--) { s->failed_pc=0x0c053930u; return 0; }
r[9]+=0x00000001u;
goto P_0c053932;
P_0c053932: /* original 5237, guest PC 0x0c053932 */
if(!s->budget--) { s->failed_pc=0x0c053932u; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c053934;
P_0c053934: /* original 032e, guest PC 0x0c053934 */
if(!s->budget--) { s->failed_pc=0x0c053934u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c053936;
P_0c053936: /* original 313c, guest PC 0x0c053936 */
if(!s->budget--) { s->failed_pc=0x0c053936u; return 0; }
r[1]+=r[3];
goto P_0c053938;
P_0c053938: /* original 1f13, guest PC 0x0c053938 */
if(!s->budget--) { s->failed_pc=0x0c053938u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c05393a;
P_0c05393a: /* original 62f2, guest PC 0x0c05393a */
if(!s->budget--) { s->failed_pc=0x0c05393au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05393c;
P_0c05393c: /* original 7201, guest PC 0x0c05393c */
if(!s->budget--) { s->failed_pc=0x0c05393cu; return 0; }
r[2]+=0x00000001u;
goto P_0c05393e;
P_0c05393e: /* original 2f22, guest PC 0x0c05393e */
if(!s->budget--) { s->failed_pc=0x0c05393eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c053940;
P_0c053940: /* original 53f2, guest PC 0x0c053940 */
if(!s->budget--) { s->failed_pc=0x0c053940u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c053942;
P_0c053942: /* original 60f2, guest PC 0x0c053942 */
if(!s->budget--) { s->failed_pc=0x0c053942u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c053944;
P_0c053944: /* original 5237, guest PC 0x0c053944 */
if(!s->budget--) { s->failed_pc=0x0c053944u; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c053946;
P_0c053946: /* original 512f, guest PC 0x0c053946 */
if(!s->budget--) { s->failed_pc=0x0c053946u; return 0; }
r[1]=read(ram,r[2]+60,4);
goto P_0c053948;
P_0c053948: /* original 3013, guest PC 0x0c053948 */
if(!s->budget--) { s->failed_pc=0x0c053948u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[1])!=0);
goto P_0c05394a;
P_0c05394a: /* original 8901, guest PC 0x0c05394a */
if(!s->budget--) { s->failed_pc=0x0c05394au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053950; }
goto P_0c05394c;
P_0c05394c: /* original af55, guest PC 0x0c05394c */
if(!s->budget--) { s->failed_pc=0x0c05394cu; return 0; }
goto P_0c0537fa;
P_0c05394e: /* original 0009, guest PC 0x0c05394e */
if(!s->budget--) { s->failed_pc=0x0c05394eu; return 0; }
goto P_0c053950;
P_0c053950: /* original e000, guest PC 0x0c053950 */
if(!s->budget--) { s->failed_pc=0x0c053950u; return 0; }
r[0]=0x00000000u;
goto P_0c053952;
P_0c053952: /* original 7f14, guest PC 0x0c053952 */
if(!s->budget--) { s->failed_pc=0x0c053952u; return 0; }
r[15]+=0x00000014u;
goto P_0c053954;
P_0c053954: /* original 4f16, guest PC 0x0c053954 */
if(!s->budget--) { s->failed_pc=0x0c053954u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c053956;
P_0c053956: /* original 4f26, guest PC 0x0c053956 */
if(!s->budget--) { s->failed_pc=0x0c053956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053958;
P_0c053958: /* original 68f6, guest PC 0x0c053958 */
if(!s->budget--) { s->failed_pc=0x0c053958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05395a;
P_0c05395a: /* original 69f6, guest PC 0x0c05395a */
if(!s->budget--) { s->failed_pc=0x0c05395au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05395c;
P_0c05395c: /* original 6af6, guest PC 0x0c05395c */
if(!s->budget--) { s->failed_pc=0x0c05395cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05395e;
P_0c05395e: /* original 6bf6, guest PC 0x0c05395e */
if(!s->budget--) { s->failed_pc=0x0c05395eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c053960;
P_0c053960: /* original 6cf6, guest PC 0x0c053960 */
if(!s->budget--) { s->failed_pc=0x0c053960u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c053962;
P_0c053962: /* original 6df6, guest PC 0x0c053962 */
if(!s->budget--) { s->failed_pc=0x0c053962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c053964;
P_0c053964: /* original 000b, guest PC 0x0c053964 */
if(!s->budget--) { s->failed_pc=0x0c053964u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053966: /* original 6ef6, guest PC 0x0c053966 */
if(!s->budget--) { s->failed_pc=0x0c053966u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c053968u,s,ram);
P_0c055666: /* original 4f22, guest PC 0x0c055666 */
if(!s->budget--) { s->failed_pc=0x0c055666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055668;
P_0c055668: /* original 4f13, guest PC 0x0c055668 */
if(!s->budget--) { s->failed_pc=0x0c055668u; return 0; }
if(!s->gbr_known) goto unsupported;
r[15]-=4; write(ram,r[15],s->gbr,4);
goto P_0c05566a;
P_0c05566a: /* original 5c10, guest PC 0x0c05566a */
if(!s->budget--) { s->failed_pc=0x0c05566au; return 0; }
r[12]=read(ram,r[1]+0,4);
goto P_0c05566c;
P_0c05566c: /* original 5b14, guest PC 0x0c05566c */
if(!s->budget--) { s->failed_pc=0x0c05566cu; return 0; }
r[11]=read(ram,r[1]+16,4);
goto P_0c05566e;
P_0c05566e: /* original 6303, guest PC 0x0c05566e */
if(!s->budget--) { s->failed_pc=0x0c05566eu; return 0; }
r[3]=r[0];
goto P_0c055670;
P_0c055670: /* original 5012, guest PC 0x0c055670 */
if(!s->budget--) { s->failed_pc=0x0c055670u; return 0; }
r[0]=read(ram,r[1]+8,4);
goto P_0c055672;
P_0c055672: /* original 4317, guest PC 0x0c055672 */
if(!s->budget--) { s->failed_pc=0x0c055672u; return 0; }
s->gbr=read(ram,r[3],4); r[3]+=4; s->gbr_known=1;
goto P_0c055674;
P_0c055674: /* original 432a, guest PC 0x0c055674 */
if(!s->budget--) { s->failed_pc=0x0c055674u; return 0; }
r[16]=r[3];
goto P_0c055676;
P_0c055676: /* original 2c29, guest PC 0x0c055676 */
if(!s->budget--) { s->failed_pc=0x0c055676u; return 0; }
r[12]&=r[2];
goto P_0c055678;
P_0c055678: /* original 2b29, guest PC 0x0c055678 */
if(!s->budget--) { s->failed_pc=0x0c055678u; return 0; }
r[11]&=r[2];
goto P_0c05567a;
P_0c05567a: /* original fffb, guest PC 0x0c05567a */
if(!s->budget--) { s->failed_pc=0x0c05567au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c05567c;
P_0c05567c: /* original 2029, guest PC 0x0c05567c */
if(!s->budget--) { s->failed_pc=0x0c05567cu; return 0; }
r[0]&=r[2];
goto P_0c05567e;
P_0c05567e: /* original ffeb, guest PC 0x0c05567e */
if(!s->budget--) { s->failed_pc=0x0c05567eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c055680;
P_0c055680: /* original 2c7b, guest PC 0x0c055680 */
if(!s->budget--) { s->failed_pc=0x0c055680u; return 0; }
r[12]|=r[7];
goto P_0c055682;
P_0c055682: /* original 2b7b, guest PC 0x0c055682 */
if(!s->budget--) { s->failed_pc=0x0c055682u; return 0; }
r[11]|=r[7];
goto P_0c055684;
P_0c055684: /* original ffdb, guest PC 0x0c055684 */
if(!s->budget--) { s->failed_pc=0x0c055684u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c055686;
P_0c055686: /* original 207b, guest PC 0x0c055686 */
if(!s->budget--) { s->failed_pc=0x0c055686u; return 0; }
r[0]|=r[7];
goto P_0c055688;
P_0c055688: /* original ffcb, guest PC 0x0c055688 */
if(!s->budget--) { s->failed_pc=0x0c055688u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c05568a;
P_0c05568a: /* original c214, guest PC 0x0c05568a */
if(!s->budget--) { s->failed_pc=0x0c05568au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+80,r[0],4);
goto P_0c05568c;
P_0c05568c: /* original 60b3, guest PC 0x0c05568c */
if(!s->budget--) { s->failed_pc=0x0c05568cu; return 0; }
r[0]=r[11];
goto P_0c05568e;
P_0c05568e: /* original c216, guest PC 0x0c05568e */
if(!s->budget--) { s->failed_pc=0x0c05568eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+88,r[0],4);
goto P_0c055690;
P_0c055690: /* original 60c3, guest PC 0x0c055690 */
if(!s->budget--) { s->failed_pc=0x0c055690u; return 0; }
r[0]=r[12];
goto P_0c055692;
P_0c055692: /* original a005, guest PC 0x0c055692 */
if(!s->budget--) { s->failed_pc=0x0c055692u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+72,r[0],4);
goto P_0c0556a0;
P_0c055694: /* original c212, guest PC 0x0c055694 */
if(!s->budget--) { s->failed_pc=0x0c055694u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+72,r[0],4);
return vf3_matrix_family(0x0c055696u,s,ram);
P_0c0556a0: /* original 6d43, guest PC 0x0c0556a0 */
if(!s->budget--) { s->failed_pc=0x0c0556a0u; return 0; }
r[13]=r[4];
goto P_0c0556a2;
P_0c0556a2: /* original 7410, guest PC 0x0c0556a2 */
if(!s->budget--) { s->failed_pc=0x0c0556a2u; return 0; }
r[4]+=0x00000010u;
goto P_0c0556a4;
P_0c0556a4: /* original c60a, guest PC 0x0c0556a4 */
if(!s->budget--) { s->failed_pc=0x0c0556a4u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+40,4);
goto P_0c0556a6;
P_0c0556a6: /* original f049, guest PC 0x0c0556a6 */
if(!s->budget--) { s->failed_pc=0x0c0556a6u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556a8;
P_0c0556a8: /* original f149, guest PC 0x0c0556a8 */
if(!s->budget--) { s->failed_pc=0x0c0556a8u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556aa;
P_0c0556aa: /* original f249, guest PC 0x0c0556aa */
if(!s->budget--) { s->failed_pc=0x0c0556aau; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556ac;
P_0c0556ac: /* original f39d, guest PC 0x0c0556ac */
if(!s->budget--) { s->failed_pc=0x0c0556acu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0556ae;
P_0c0556ae: /* original d33f, guest PC 0x0c0556ae */
if(!s->budget--) { s->failed_pc=0x0c0556aeu; return 0; }
r[3]=read(ram,0x0c0557acu,4);
goto P_0c0556b0;
P_0c0556b0: /* original f1fd, guest PC 0x0c0556b0 */
if(!s->budget--) { s->failed_pc=0x0c0556b0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c0556b2;
P_0c0556b2: /* original 405a, guest PC 0x0c0556b2 */
if(!s->budget--) { s->failed_pc=0x0c0556b2u; return 0; }
r[53]=r[0];
goto P_0c0556b4;
P_0c0556b4: /* original f60d, guest PC 0x0c0556b4 */
if(!s->budget--) { s->failed_pc=0x0c0556b4u; return 0; }
fr[6]=r[53];
goto P_0c0556b6;
P_0c0556b6: /* original f448, guest PC 0x0c0556b6 */
if(!s->budget--) { s->failed_pc=0x0c0556b6u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0556b8;
P_0c0556b8: /* original f538, guest PC 0x0c0556b8 */
if(!s->budget--) { s->failed_pc=0x0c0556b8u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c0556ba;
P_0c0556ba: /* original f24d, guest PC 0x0c0556ba */
if(!s->budget--) { s->failed_pc=0x0c0556bau; return 0; }
fr[2]^=0x80000000u;
goto P_0c0556bc;
P_0c0556bc: /* original f462, guest PC 0x0c0556bc */
if(!s->budget--) { s->failed_pc=0x0c0556bcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0556be;
P_0c0556be: /* original f72c, guest PC 0x0c0556be */
if(!s->budget--) { s->failed_pc=0x0c0556beu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c0556c0;
P_0c0556c0: /* original f82c, guest PC 0x0c0556c0 */
if(!s->budget--) { s->failed_pc=0x0c0556c0u; return 0; }
vf3_matrix_move(s,8,2);
goto P_0c0556c2;
P_0c0556c2: /* original f740, guest PC 0x0c0556c2 */
if(!s->budget--) { s->failed_pc=0x0c0556c2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'+');
goto P_0c0556c4;
P_0c0556c4: /* original f98d, guest PC 0x0c0556c4 */
if(!s->budget--) { s->failed_pc=0x0c0556c4u; return 0; }
fr[9]=0;
goto P_0c0556c6;
P_0c0556c6: /* original f841, guest PC 0x0c0556c6 */
if(!s->budget--) { s->failed_pc=0x0c0556c6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0556c8;
P_0c0556c8: /* original f975, guest PC 0x0c0556c8 */
if(!s->budget--) { s->failed_pc=0x0c0556c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[7]))!=0);
goto P_0c0556ca;
P_0c0556ca: /* original d339, guest PC 0x0c0556ca */
if(!s->budget--) { s->failed_pc=0x0c0556cau; return 0; }
r[3]=read(ram,0x0c0557b0u,4);
goto P_0c0556cc;
P_0c0556cc: /* original 8b01, guest PC 0x0c0556cc */
if(!s->budget--) { s->failed_pc=0x0c0556ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0556d2; }
goto P_0c0556ce;
P_0c0556ce: /* original a06b, guest PC 0x0c0556ce */
if(!s->budget--) { s->failed_pc=0x0c0556ceu; return 0; }
goto P_0c0557a8;
P_0c0556d0: /* original 0009, guest PC 0x0c0556d0 */
if(!s->budget--) { s->failed_pc=0x0c0556d0u; return 0; }
goto P_0c0556d2;
P_0c0556d2: /* original f855, guest PC 0x0c0556d2 */
if(!s->budget--) { s->failed_pc=0x0c0556d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c0556d4;
P_0c0556d4: /* original 8b01, guest PC 0x0c0556d4 */
if(!s->budget--) { s->failed_pc=0x0c0556d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0556da; }
goto P_0c0556d6;
P_0c0556d6: /* original a067, guest PC 0x0c0556d6 */
if(!s->budget--) { s->failed_pc=0x0c0556d6u; return 0; }
goto P_0c0557a8;
P_0c0556d8: /* original 0009, guest PC 0x0c0556d8 */
if(!s->budget--) { s->failed_pc=0x0c0556d8u; return 0; }
goto P_0c0556da;
P_0c0556da: /* original 4f22, guest PC 0x0c0556da */
if(!s->budget--) { s->failed_pc=0x0c0556dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0556dc;
P_0c0556dc: /* original 430b, guest PC 0x0c0556dc */
if(!s->budget--) { s->failed_pc=0x0c0556dcu; return 0; }
target=r[3];
r[16]=0x0c0556e0u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0556e0u) { target=s->pc; goto dispatch; }
goto P_0c0556e0;
P_0c0556de: /* original e400, guest PC 0x0c0556de */
if(!s->budget--) { s->failed_pc=0x0c0556deu; return 0; }
r[4]=0x00000000u;
goto P_0c0556e0;
P_0c0556e0: /* original c605, guest PC 0x0c0556e0 */
if(!s->budget--) { s->failed_pc=0x0c0556e0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+20,4);
goto P_0c0556e2;
P_0c0556e2: /* original 400b, guest PC 0x0c0556e2 */
if(!s->budget--) { s->failed_pc=0x0c0556e2u; return 0; }
target=r[0];
r[16]=0x0c0556e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0556e6u) { target=s->pc; goto dispatch; }
goto P_0c0556e6;
P_0c0556e4: /* original 0009, guest PC 0x0c0556e4 */
if(!s->budget--) { s->failed_pc=0x0c0556e4u; return 0; }
goto P_0c0556e6;
P_0c0556e6: /* original 50d0, guest PC 0x0c0556e6 */
if(!s->budget--) { s->failed_pc=0x0c0556e6u; return 0; }
r[0]=read(ram,r[13]+0,4);
goto P_0c0556e8;
P_0c0556e8: /* original e120, guest PC 0x0c0556e8 */
if(!s->budget--) { s->failed_pc=0x0c0556e8u; return 0; }
r[1]=0x00000020u;
goto P_0c0556ea;
P_0c0556ea: /* original 2108, guest PC 0x0c0556ea */
if(!s->budget--) { s->failed_pc=0x0c0556eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[0])==0)!=0);
goto P_0c0556ec;
P_0c0556ec: /* original 890e, guest PC 0x0c0556ec */
if(!s->budget--) { s->failed_pc=0x0c0556ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05570c; }
goto P_0c0556ee;
P_0c0556ee: /* original d003, guest PC 0x0c0556ee */
if(!s->budget--) { s->failed_pc=0x0c0556eeu; return 0; }
r[0]=read(ram,0x0c0556fcu,4);
goto P_0c0556f0;
P_0c0556f0: /* original 6002, guest PC 0x0c0556f0 */
if(!s->budget--) { s->failed_pc=0x0c0556f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0556f2;
P_0c0556f2: /* original 2008, guest PC 0x0c0556f2 */
if(!s->budget--) { s->failed_pc=0x0c0556f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0556f4;
P_0c0556f4: /* original 8b06, guest PC 0x0c0556f4 */
if(!s->budget--) { s->failed_pc=0x0c0556f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055704; }
goto P_0c0556f6;
P_0c0556f6: /* original d002, guest PC 0x0c0556f6 */
if(!s->budget--) { s->failed_pc=0x0c0556f6u; return 0; }
r[0]=read(ram,0x0c055700u,4);
goto P_0c0556f8;
P_0c0556f8: /* original a005, guest PC 0x0c0556f8 */
if(!s->budget--) { s->failed_pc=0x0c0556f8u; return 0; }
goto P_0c055706;
P_0c0556fa: /* original 0009, guest PC 0x0c0556fa */
if(!s->budget--) { s->failed_pc=0x0c0556fau; return 0; }
return vf3_matrix_family(0x0c0556fcu,s,ram);
P_0c055704: /* original d025, guest PC 0x0c055704 */
if(!s->budget--) { s->failed_pc=0x0c055704u; return 0; }
r[0]=read(ram,0x0c05579cu,4);
goto P_0c055706;
P_0c055706: /* original 54d1, guest PC 0x0c055706 */
if(!s->budget--) { s->failed_pc=0x0c055706u; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c055708;
P_0c055708: /* original 400b, guest PC 0x0c055708 */
if(!s->budget--) { s->failed_pc=0x0c055708u; return 0; }
target=r[0];
r[16]=0x0c05570cu;
r[6]=read(ram,r[13]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05570cu) { target=s->pc; goto dispatch; }
goto P_0c05570c;
P_0c05570a: /* original 56d2, guest PC 0x0c05570a */
if(!s->budget--) { s->failed_pc=0x0c05570au; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c05570c;
P_0c05570c: /* original 64d3, guest PC 0x0c05570c */
if(!s->budget--) { s->failed_pc=0x0c05570cu; return 0; }
r[4]=r[13];
goto P_0c05570e;
P_0c05570e: /* original 7410, guest PC 0x0c05570e */
if(!s->budget--) { s->failed_pc=0x0c05570eu; return 0; }
r[4]+=0x00000010u;
goto P_0c055710;
P_0c055710: /* original c60a, guest PC 0x0c055710 */
if(!s->budget--) { s->failed_pc=0x0c055710u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+40,4);
goto P_0c055712;
P_0c055712: /* original f049, guest PC 0x0c055712 */
if(!s->budget--) { s->failed_pc=0x0c055712u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055714;
P_0c055714: /* original f149, guest PC 0x0c055714 */
if(!s->budget--) { s->failed_pc=0x0c055714u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055716;
P_0c055716: /* original f249, guest PC 0x0c055716 */
if(!s->budget--) { s->failed_pc=0x0c055716u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055718;
P_0c055718: /* original f39d, guest PC 0x0c055718 */
if(!s->budget--) { s->failed_pc=0x0c055718u; return 0; }
fr[3]=0x3f800000u;
goto P_0c05571a;
P_0c05571a: /* original f1fd, guest PC 0x0c05571a */
if(!s->budget--) { s->failed_pc=0x0c05571au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c05571c;
P_0c05571c: /* original 405a, guest PC 0x0c05571c */
if(!s->budget--) { s->failed_pc=0x0c05571cu; return 0; }
r[53]=r[0];
goto P_0c05571e;
P_0c05571e: /* original f60d, guest PC 0x0c05571e */
if(!s->budget--) { s->failed_pc=0x0c05571eu; return 0; }
fr[6]=r[53];
goto P_0c055720;
P_0c055720: /* original c727, guest PC 0x0c055720 */
if(!s->budget--) { s->failed_pc=0x0c055720u; return 0; }
r[0]=0x0c0557c0u;
goto P_0c055722;
P_0c055722: /* original 6002, guest PC 0x0c055722 */
if(!s->budget--) { s->failed_pc=0x0c055722u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c055724;
P_0c055724: /* original e302, guest PC 0x0c055724 */
if(!s->budget--) { s->failed_pc=0x0c055724u; return 0; }
r[3]=0x00000002u;
goto P_0c055726;
P_0c055726: /* original ff49, guest PC 0x0c055726 */
if(!s->budget--) { s->failed_pc=0x0c055726u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055728;
P_0c055728: /* original ff62, guest PC 0x0c055728 */
if(!s->budget--) { s->failed_pc=0x0c055728u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c05572a;
P_0c05572a: /* original f3fd, guest PC 0x0c05572a */
if(!s->budget--) { s->failed_pc=0x0c05572au; return 0; }
r[18]^=0x100000u;
goto P_0c05572c;
P_0c05572c: /* original f409, guest PC 0x0c05572c */
if(!s->budget--) { s->failed_pc=0x0c05572cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c05572e;
P_0c05572e: /* original f609, guest PC 0x0c05572e */
if(!s->budget--) { s->failed_pc=0x0c05572eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055730;
P_0c055730: /* original f809, guest PC 0x0c055730 */
if(!s->budget--) { s->failed_pc=0x0c055730u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055732;
P_0c055732: /* original fa09, guest PC 0x0c055732 */
if(!s->budget--) { s->failed_pc=0x0c055732u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055734;
P_0c055734: /* original f4ed, guest PC 0x0c055734 */
if(!s->budget--) { s->failed_pc=0x0c055734u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c055736;
P_0c055736: /* original f8ed, guest PC 0x0c055736 */
if(!s->budget--) { s->failed_pc=0x0c055736u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c055738;
P_0c055738: /* original ff75, guest PC 0x0c055738 */
if(!s->budget--) { s->failed_pc=0x0c055738u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[7]))!=0);
goto P_0c05573a;
P_0c05573a: /* original f3fd, guest PC 0x0c05573a */
if(!s->budget--) { s->failed_pc=0x0c05573au; return 0; }
r[18]^=0x100000u;
goto P_0c05573c;
P_0c05573c: /* original 8b30, guest PC 0x0c05573c */
if(!s->budget--) { s->failed_pc=0x0c05573cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0557a0; }
goto P_0c05573e;
P_0c05573e: /* original ffb5, guest PC 0x0c05573e */
if(!s->budget--) { s->failed_pc=0x0c05573eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[11]))!=0);
goto P_0c055740;
P_0c055740: /* original 8b2e, guest PC 0x0c055740 */
if(!s->budget--) { s->failed_pc=0x0c055740u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0557a0; }
goto P_0c055742;
P_0c055742: /* original 4310, guest PC 0x0c055742 */
if(!s->budget--) { s->failed_pc=0x0c055742u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c055744;
P_0c055744: /* original 8bf1, guest PC 0x0c055744 */
if(!s->budget--) { s->failed_pc=0x0c055744u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05572a; }
goto P_0c055746;
P_0c055746: /* original c71c, guest PC 0x0c055746 */
if(!s->budget--) { s->failed_pc=0x0c055746u; return 0; }
r[0]=0x0c0557b8u;
goto P_0c055748;
P_0c055748: /* original d31a, guest PC 0x0c055748 */
if(!s->budget--) { s->failed_pc=0x0c055748u; return 0; }
r[3]=read(ram,0x0c0557b4u,4);
goto P_0c05574a;
P_0c05574a: /* original 6106, guest PC 0x0c05574a */
if(!s->budget--) { s->failed_pc=0x0c05574au; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c05574c;
P_0c05574c: /* original f418, guest PC 0x0c05574c */
if(!s->budget--) { s->failed_pc=0x0c05574cu; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
goto P_0c05574e;
P_0c05574e: /* original 6106, guest PC 0x0c05574e */
if(!s->budget--) { s->failed_pc=0x0c05574eu; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055750;
P_0c055750: /* original 430b, guest PC 0x0c055750 */
if(!s->budget--) { s->failed_pc=0x0c055750u; return 0; }
target=r[3];
r[16]=0x0c055754u;
vf3_matrix_load(s,ram,5,r[1]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055754u) { target=s->pc; goto dispatch; }
goto P_0c055754;
P_0c055752: /* original f518, guest PC 0x0c055752 */
if(!s->budget--) { s->failed_pc=0x0c055752u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
goto P_0c055754;
P_0c055754: /* original d11b, guest PC 0x0c055754 */
if(!s->budget--) { s->failed_pc=0x0c055754u; return 0; }
r[1]=read(ram,0x0c0557c4u,4);
goto P_0c055756;
P_0c055756: /* original c611, guest PC 0x0c055756 */
if(!s->budget--) { s->failed_pc=0x0c055756u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+68,4);
goto P_0c055758;
P_0c055758: /* original 6303, guest PC 0x0c055758 */
if(!s->budget--) { s->failed_pc=0x0c055758u; return 0; }
r[3]=r[0];
goto P_0c05575a;
P_0c05575a: /* original c604, guest PC 0x0c05575a */
if(!s->budget--) { s->failed_pc=0x0c05575au; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+16,4);
goto P_0c05575c;
P_0c05575c: /* original 54d1, guest PC 0x0c05575c */
if(!s->budget--) { s->failed_pc=0x0c05575cu; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c05575e;
P_0c05575e: /* original 56d2, guest PC 0x0c05575e */
if(!s->budget--) { s->failed_pc=0x0c05575eu; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c055760;
P_0c055760: /* original 4315, guest PC 0x0c055760 */
if(!s->budget--) { s->failed_pc=0x0c055760u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c055762;
P_0c055762: /* original 67d3, guest PC 0x0c055762 */
if(!s->budget--) { s->failed_pc=0x0c055762u; return 0; }
r[7]=r[13];
goto P_0c055764;
P_0c055764: /* original 8901, guest PC 0x0c055764 */
if(!s->budget--) { s->failed_pc=0x0c055764u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05576a; }
goto P_0c055766;
P_0c055766: /* original 400b, guest PC 0x0c055766 */
if(!s->budget--) { s->failed_pc=0x0c055766u; return 0; }
target=r[0];
r[16]=0x0c05576au;
tmp=read(ram,r[1],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05576au) { target=s->pc; goto dispatch; }
goto P_0c05576a;
P_0c055768: /* original 6512, guest PC 0x0c055768 */
if(!s->budget--) { s->failed_pc=0x0c055768u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c05576a;
P_0c05576a: /* original c719, guest PC 0x0c05576a */
if(!s->budget--) { s->failed_pc=0x0c05576au; return 0; }
r[0]=0x0c0557d0u;
goto P_0c05576c;
P_0c05576c: /* original da19, guest PC 0x0c05576c */
if(!s->budget--) { s->failed_pc=0x0c05576cu; return 0; }
r[10]=read(ram,0x0c0557d4u,4);
goto P_0c05576e;
P_0c05576e: /* original f308, guest PC 0x0c05576e */
if(!s->budget--) { s->failed_pc=0x0c05576eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c055770;
P_0c055770: /* original d314, guest PC 0x0c055770 */
if(!s->budget--) { s->failed_pc=0x0c055770u; return 0; }
r[3]=read(ram,0x0c0557c4u,4);
goto P_0c055772;
P_0c055772: /* original e1f0, guest PC 0x0c055772 */
if(!s->budget--) { s->failed_pc=0x0c055772u; return 0; }
r[1]=0xfffffff0u;
goto P_0c055774;
P_0c055774: /* original c603, guest PC 0x0c055774 */
if(!s->budget--) { s->failed_pc=0x0c055774u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+12,4);
goto P_0c055776;
P_0c055776: /* original 4128, guest PC 0x0c055776 */
if(!s->budget--) { s->failed_pc=0x0c055776u; return 0; }
r[1]<<=16;
goto P_0c055778;
P_0c055778: /* original 54d3, guest PC 0x0c055778 */
if(!s->budget--) { s->failed_pc=0x0c055778u; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c05577a;
P_0c05577a: /* original 4118, guest PC 0x0c05577a */
if(!s->budget--) { s->failed_pc=0x0c05577au; return 0; }
r[1]<<=8;
goto P_0c05577c;
P_0c05577c: /* original 6aa2, guest PC 0x0c05577c */
if(!s->budget--) { s->failed_pc=0x0c05577cu; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c05577e;
P_0c05577e: /* original e200, guest PC 0x0c05577e */
if(!s->budget--) { s->failed_pc=0x0c05577eu; return 0; }
r[2]=0x00000000u;
goto P_0c055780;
P_0c055780: /* original 6e03, guest PC 0x0c055780 */
if(!s->budget--) { s->failed_pc=0x0c055780u; return 0; }
r[14]=r[0];
goto P_0c055782;
P_0c055782: /* original 42be, guest PC 0x0c055782 */
if(!s->budget--) { s->failed_pc=0x0c055782u; return 0; }
if(!s->bank_known) goto unsupported;
s->bank[3]=r[2];
goto P_0c055784;
P_0c055784: /* original 6d32, guest PC 0x0c055784 */
if(!s->budget--) { s->failed_pc=0x0c055784u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c055786;
P_0c055786: /* original 41ce, guest PC 0x0c055786 */
if(!s->budget--) { s->failed_pc=0x0c055786u; return 0; }
if(!s->bank_known) goto unsupported;
s->bank[4]=r[1];
goto P_0c055788;
P_0c055788: /* original 6041, guest PC 0x0c055788 */
if(!s->budget--) { s->failed_pc=0x0c055788u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c05578a;
P_0c05578a: /* original 4011, guest PC 0x0c05578a */
if(!s->budget--) { s->failed_pc=0x0c05578au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c05578c;
P_0c05578c: /* original 600c, guest PC 0x0c05578c */
if(!s->budget--) { s->failed_pc=0x0c05578cu; return 0; }
r[0]=r[0]&255u;
goto P_0c05578e;
P_0c05578e: /* original 8f07, guest PC 0x0c05578e */
if(!s->budget--) { s->failed_pc=0x0c05578eu; return 0; }
cond=r[17]&1u;
r[0]<<=2;
if(!cond) { goto P_0c0557a0; }
goto P_0c055792;
P_0c055790: /* original 4008, guest PC 0x0c055790 */
if(!s->budget--) { s->failed_pc=0x0c055790u; return 0; }
r[0]<<=2;
goto P_0c055792;
P_0c055792: /* original 03ee, guest PC 0x0c055792 */
if(!s->budget--) { s->failed_pc=0x0c055792u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c055794;
P_0c055794: /* original 430b, guest PC 0x0c055794 */
if(!s->budget--) { s->failed_pc=0x0c055794u; return 0; }
target=r[3];
r[16]=0x0c055798u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055798u) { target=s->pc; goto dispatch; }
goto P_0c055798;
P_0c055796: /* original 0009, guest PC 0x0c055796 */
if(!s->budget--) { s->failed_pc=0x0c055796u; return 0; }
goto P_0c055798;
P_0c055798: /* original aff7, guest PC 0x0c055798 */
if(!s->budget--) { s->failed_pc=0x0c055798u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c05578a;
P_0c05579a: /* original 6041, guest PC 0x0c05579a */
if(!s->budget--) { s->failed_pc=0x0c05579au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
return vf3_matrix_family(0x0c05579cu,s,ram);
P_0c0557a0: /* original d30d, guest PC 0x0c0557a0 */
if(!s->budget--) { s->failed_pc=0x0c0557a0u; return 0; }
r[3]=read(ram,0x0c0557d8u,4);
goto P_0c0557a2;
P_0c0557a2: /* original 4f26, guest PC 0x0c0557a2 */
if(!s->budget--) { s->failed_pc=0x0c0557a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0557a4;
P_0c0557a4: /* original 432b, guest PC 0x0c0557a4 */
if(!s->budget--) { s->failed_pc=0x0c0557a4u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c0557a6: /* original e401, guest PC 0x0c0557a6 */
if(!s->budget--) { s->failed_pc=0x0c0557a6u; return 0; }
r[4]=0x00000001u;
goto P_0c0557a8;
P_0c0557a8: /* original 000b, guest PC 0x0c0557a8 */
if(!s->budget--) { s->failed_pc=0x0c0557a8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0557aa: /* original 0009, guest PC 0x0c0557aa */
if(!s->budget--) { s->failed_pc=0x0c0557aau; return 0; }
return vf3_matrix_family(0x0c0557acu,s,ram);
P_0c0558f4: /* original 5d40, guest PC 0x0c0558f4 */
if(!s->budget--) { s->failed_pc=0x0c0558f4u; return 0; }
r[13]=read(ram,r[4]+0,4);
goto P_0c0558f6;
P_0c0558f6: /* original 6e43, guest PC 0x0c0558f6 */
if(!s->budget--) { s->failed_pc=0x0c0558f6u; return 0; }
r[14]=r[4];
goto P_0c0558f8;
P_0c0558f8: /* original 4f22, guest PC 0x0c0558f8 */
if(!s->budget--) { s->failed_pc=0x0c0558f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0558fa;
P_0c0558fa: /* original 60d3, guest PC 0x0c0558fa */
if(!s->budget--) { s->failed_pc=0x0c0558fau; return 0; }
r[0]=r[13];
goto P_0c0558fc;
P_0c0558fc: /* original c83e, guest PC 0x0c0558fc */
if(!s->budget--) { s->failed_pc=0x0c0558fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c0558fe;
P_0c0558fe: /* original 2fd6, guest PC 0x0c0558fe */
if(!s->budget--) { s->failed_pc=0x0c0558feu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c055900;
P_0c055900: /* original 8927, guest PC 0x0c055900 */
if(!s->budget--) { s->failed_pc=0x0c055900u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055952; }
goto P_0c055902;
P_0c055902: /* original d123, guest PC 0x0c055902 */
if(!s->budget--) { s->failed_pc=0x0c055902u; return 0; }
r[1]=read(ram,0x0c055990u,4);
goto P_0c055904;
P_0c055904: /* original 410b, guest PC 0x0c055904 */
if(!s->budget--) { s->failed_pc=0x0c055904u; return 0; }
target=r[1];
r[16]=0x0c055908u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055908u) { target=s->pc; goto dispatch; }
goto P_0c055908;
P_0c055906: /* original e400, guest PC 0x0c055906 */
if(!s->budget--) { s->failed_pc=0x0c055906u; return 0; }
r[4]=0x00000000u;
goto P_0c055908;
P_0c055908: /* original 60d3, guest PC 0x0c055908 */
if(!s->budget--) { s->failed_pc=0x0c055908u; return 0; }
r[0]=r[13];
goto P_0c05590a;
P_0c05590a: /* original c802, guest PC 0x0c05590a */
if(!s->budget--) { s->failed_pc=0x0c05590au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c05590c;
P_0c05590c: /* original d121, guest PC 0x0c05590c */
if(!s->budget--) { s->failed_pc=0x0c05590cu; return 0; }
r[1]=read(ram,0x0c055994u,4);
goto P_0c05590e;
P_0c05590e: /* original 64e3, guest PC 0x0c05590e */
if(!s->budget--) { s->failed_pc=0x0c05590eu; return 0; }
r[4]=r[14];
goto P_0c055910;
P_0c055910: /* original 8d05, guest PC 0x0c055910 */
if(!s->budget--) { s->failed_pc=0x0c055910u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(cond) { goto P_0c05591e; }
goto P_0c055914;
P_0c055912: /* original 7408, guest PC 0x0c055912 */
if(!s->budget--) { s->failed_pc=0x0c055912u; return 0; }
r[4]+=0x00000008u;
goto P_0c055914;
P_0c055914: /* original f449, guest PC 0x0c055914 */
if(!s->budget--) { s->failed_pc=0x0c055914u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055916;
P_0c055916: /* original f549, guest PC 0x0c055916 */
if(!s->budget--) { s->failed_pc=0x0c055916u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055918;
P_0c055918: /* original 410b, guest PC 0x0c055918 */
if(!s->budget--) { s->failed_pc=0x0c055918u; return 0; }
target=r[1];
r[16]=0x0c05591cu;
vf3_matrix_load(s,ram,6,r[4]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05591cu) { target=s->pc; goto dispatch; }
goto P_0c05591c;
P_0c05591a: /* original f648, guest PC 0x0c05591a */
if(!s->budget--) { s->failed_pc=0x0c05591au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c05591c;
P_0c05591c: /* original 60d3, guest PC 0x0c05591c */
if(!s->budget--) { s->failed_pc=0x0c05591cu; return 0; }
r[0]=r[13];
goto P_0c05591e;
P_0c05591e: /* original c838, guest PC 0x0c05591e */
if(!s->budget--) { s->failed_pc=0x0c05591eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&56u)==0)!=0);
goto P_0c055920;
P_0c055920: /* original 8d11, guest PC 0x0c055920 */
if(!s->budget--) { s->failed_pc=0x0c055920u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(cond) { goto P_0c055946; }
goto P_0c055924;
P_0c055922: /* original c820, guest PC 0x0c055922 */
if(!s->budget--) { s->failed_pc=0x0c055922u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c055924;
P_0c055924: /* original d31c, guest PC 0x0c055924 */
if(!s->budget--) { s->failed_pc=0x0c055924u; return 0; }
r[3]=read(ram,0x0c055998u,4);
goto P_0c055926;
P_0c055926: /* original 8902, guest PC 0x0c055926 */
if(!s->budget--) { s->failed_pc=0x0c055926u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05592e; }
goto P_0c055928;
P_0c055928: /* original 430b, guest PC 0x0c055928 */
if(!s->budget--) { s->failed_pc=0x0c055928u; return 0; }
target=r[3];
r[16]=0x0c05592cu;
r[4]=read(ram,r[14]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05592cu) { target=s->pc; goto dispatch; }
goto P_0c05592c;
P_0c05592a: /* original 54e7, guest PC 0x0c05592a */
if(!s->budget--) { s->failed_pc=0x0c05592au; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05592c;
P_0c05592c: /* original 60d3, guest PC 0x0c05592c */
if(!s->budget--) { s->failed_pc=0x0c05592cu; return 0; }
r[0]=r[13];
goto P_0c05592e;
P_0c05592e: /* original c810, guest PC 0x0c05592e */
if(!s->budget--) { s->failed_pc=0x0c05592eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c055930;
P_0c055930: /* original d21a, guest PC 0x0c055930 */
if(!s->budget--) { s->failed_pc=0x0c055930u; return 0; }
r[2]=read(ram,0x0c05599cu,4);
goto P_0c055932;
P_0c055932: /* original 8902, guest PC 0x0c055932 */
if(!s->budget--) { s->failed_pc=0x0c055932u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05593a; }
goto P_0c055934;
P_0c055934: /* original 420b, guest PC 0x0c055934 */
if(!s->budget--) { s->failed_pc=0x0c055934u; return 0; }
target=r[2];
r[16]=0x0c055938u;
r[4]=read(ram,r[14]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055938u) { target=s->pc; goto dispatch; }
goto P_0c055938;
P_0c055936: /* original 54e6, guest PC 0x0c055936 */
if(!s->budget--) { s->failed_pc=0x0c055936u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c055938;
P_0c055938: /* original 60d3, guest PC 0x0c055938 */
if(!s->budget--) { s->failed_pc=0x0c055938u; return 0; }
r[0]=r[13];
goto P_0c05593a;
P_0c05593a: /* original c808, guest PC 0x0c05593a */
if(!s->budget--) { s->failed_pc=0x0c05593au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c05593c;
P_0c05593c: /* original d118, guest PC 0x0c05593c */
if(!s->budget--) { s->failed_pc=0x0c05593cu; return 0; }
r[1]=read(ram,0x0c0559a0u,4);
goto P_0c05593e;
P_0c05593e: /* original 8902, guest PC 0x0c05593e */
if(!s->budget--) { s->failed_pc=0x0c05593eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055946; }
goto P_0c055940;
P_0c055940: /* original 410b, guest PC 0x0c055940 */
if(!s->budget--) { s->failed_pc=0x0c055940u; return 0; }
target=r[1];
r[16]=0x0c055944u;
r[4]=read(ram,r[14]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055944u) { target=s->pc; goto dispatch; }
goto P_0c055944;
P_0c055942: /* original 54e5, guest PC 0x0c055942 */
if(!s->budget--) { s->failed_pc=0x0c055942u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c055944;
P_0c055944: /* original 60d3, guest PC 0x0c055944 */
if(!s->budget--) { s->failed_pc=0x0c055944u; return 0; }
r[0]=r[13];
goto P_0c055946;
P_0c055946: /* original c804, guest PC 0x0c055946 */
if(!s->budget--) { s->failed_pc=0x0c055946u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c055948;
P_0c055948: /* original d316, guest PC 0x0c055948 */
if(!s->budget--) { s->failed_pc=0x0c055948u; return 0; }
r[3]=read(ram,0x0c0559a4u,4);
goto P_0c05594a;
P_0c05594a: /* original 8902, guest PC 0x0c05594a */
if(!s->budget--) { s->failed_pc=0x0c05594au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055952; }
goto P_0c05594c;
P_0c05594c: /* original 64e3, guest PC 0x0c05594c */
if(!s->budget--) { s->failed_pc=0x0c05594cu; return 0; }
r[4]=r[14];
goto P_0c05594e;
P_0c05594e: /* original 430b, guest PC 0x0c05594e */
if(!s->budget--) { s->failed_pc=0x0c05594eu; return 0; }
target=r[3];
r[16]=0x0c055952u;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055952u) { target=s->pc; goto dispatch; }
goto P_0c055952;
P_0c055950: /* original 7420, guest PC 0x0c055950 */
if(!s->budget--) { s->failed_pc=0x0c055950u; return 0; }
r[4]+=0x00000020u;
goto P_0c055952;
P_0c055952: /* original 54e1, guest PC 0x0c055952 */
if(!s->budget--) { s->failed_pc=0x0c055952u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c055954;
P_0c055954: /* original 2448, guest PC 0x0c055954 */
if(!s->budget--) { s->failed_pc=0x0c055954u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055956;
P_0c055956: /* original 2fe6, guest PC 0x0c055956 */
if(!s->budget--) { s->failed_pc=0x0c055956u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c055958;
P_0c055958: /* original 8903, guest PC 0x0c055958 */
if(!s->budget--) { s->failed_pc=0x0c055958u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055962; }
goto P_0c05595a;
P_0c05595a: /* original bea1, guest PC 0x0c05595a */
if(!s->budget--) { s->failed_pc=0x0c05595au; return 0; }
target=0x0c0556a0u; r[16]=0x0c05595eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05595eu) { target=s->pc; goto dispatch; }
goto P_0c05595e;
P_0c05595c: /* original 0009, guest PC 0x0c05595c */
if(!s->budget--) { s->failed_pc=0x0c05595cu; return 0; }
goto P_0c05595e;
P_0c05595e: /* original 5ef0, guest PC 0x0c05595e */
if(!s->budget--) { s->failed_pc=0x0c05595eu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c055960;
P_0c055960: /* original 5df1, guest PC 0x0c055960 */
if(!s->budget--) { s->failed_pc=0x0c055960u; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c055962;
P_0c055962: /* original 54eb, guest PC 0x0c055962 */
if(!s->budget--) { s->failed_pc=0x0c055962u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c055964;
P_0c055964: /* original 2448, guest PC 0x0c055964 */
if(!s->budget--) { s->failed_pc=0x0c055964u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055966;
P_0c055966: /* original 8903, guest PC 0x0c055966 */
if(!s->budget--) { s->failed_pc=0x0c055966u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055970; }
goto P_0c055968;
P_0c055968: /* original bfc4, guest PC 0x0c055968 */
if(!s->budget--) { s->failed_pc=0x0c055968u; return 0; }
target=0x0c0558f4u; r[16]=0x0c05596cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05596cu) { target=s->pc; goto dispatch; }
goto P_0c05596c;
P_0c05596a: /* original 0009, guest PC 0x0c05596a */
if(!s->budget--) { s->failed_pc=0x0c05596au; return 0; }
goto P_0c05596c;
P_0c05596c: /* original 5df1, guest PC 0x0c05596c */
if(!s->budget--) { s->failed_pc=0x0c05596cu; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c05596e;
P_0c05596e: /* original 5ef0, guest PC 0x0c05596e */
if(!s->budget--) { s->failed_pc=0x0c05596eu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c055970;
P_0c055970: /* original 60d3, guest PC 0x0c055970 */
if(!s->budget--) { s->failed_pc=0x0c055970u; return 0; }
r[0]=r[13];
goto P_0c055972;
P_0c055972: /* original c83e, guest PC 0x0c055972 */
if(!s->budget--) { s->failed_pc=0x0c055972u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c055974;
P_0c055974: /* original d10c, guest PC 0x0c055974 */
if(!s->budget--) { s->failed_pc=0x0c055974u; return 0; }
r[1]=read(ram,0x0c0559a8u,4);
goto P_0c055976;
P_0c055976: /* original 7f08, guest PC 0x0c055976 */
if(!s->budget--) { s->failed_pc=0x0c055976u; return 0; }
r[15]+=0x00000008u;
goto P_0c055978;
P_0c055978: /* original 8901, guest PC 0x0c055978 */
if(!s->budget--) { s->failed_pc=0x0c055978u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05597e; }
goto P_0c05597a;
P_0c05597a: /* original 410b, guest PC 0x0c05597a */
if(!s->budget--) { s->failed_pc=0x0c05597au; return 0; }
target=r[1];
r[16]=0x0c05597eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05597eu) { target=s->pc; goto dispatch; }
goto P_0c05597e;
P_0c05597c: /* original e401, guest PC 0x0c05597c */
if(!s->budget--) { s->failed_pc=0x0c05597cu; return 0; }
r[4]=0x00000001u;
goto P_0c05597e;
P_0c05597e: /* original 54ec, guest PC 0x0c05597e */
if(!s->budget--) { s->failed_pc=0x0c05597eu; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c055980;
P_0c055980: /* original 4f26, guest PC 0x0c055980 */
if(!s->budget--) { s->failed_pc=0x0c055980u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055982;
P_0c055982: /* original 2448, guest PC 0x0c055982 */
if(!s->budget--) { s->failed_pc=0x0c055982u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055984;
P_0c055984: /* original 8bb6, guest PC 0x0c055984 */
if(!s->budget--) { s->failed_pc=0x0c055984u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0558f4; }
goto P_0c055986;
P_0c055986: /* original 000b, guest PC 0x0c055986 */
if(!s->budget--) { s->failed_pc=0x0c055986u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055988: /* original 0009, guest PC 0x0c055988 */
if(!s->budget--) { s->failed_pc=0x0c055988u; return 0; }
return vf3_matrix_family(0x0c05598au,s,ram);
P_0c055bfc: /* original 4f22, guest PC 0x0c055bfc */
if(!s->budget--) { s->failed_pc=0x0c055bfcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055bfe;
P_0c055bfe: /* original 6e43, guest PC 0x0c055bfe */
if(!s->budget--) { s->failed_pc=0x0c055bfeu; return 0; }
r[14]=r[4];
goto P_0c055c00;
P_0c055c00: /* original d348, guest PC 0x0c055c00 */
if(!s->budget--) { s->failed_pc=0x0c055c00u; return 0; }
r[3]=read(ram,0x0c055d24u,4);
goto P_0c055c02;
P_0c055c02: /* original 430b, guest PC 0x0c055c02 */
if(!s->budget--) { s->failed_pc=0x0c055c02u; return 0; }
target=r[3];
r[16]=0x0c055c06u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055c06u) { target=s->pc; goto dispatch; }
goto P_0c055c06;
P_0c055c04: /* original e400, guest PC 0x0c055c04 */
if(!s->budget--) { s->failed_pc=0x0c055c04u; return 0; }
r[4]=0x00000000u;
goto P_0c055c06;
P_0c055c06: /* original c605, guest PC 0x0c055c06 */
if(!s->budget--) { s->failed_pc=0x0c055c06u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+20,4);
goto P_0c055c08;
P_0c055c08: /* original 400b, guest PC 0x0c055c08 */
if(!s->budget--) { s->failed_pc=0x0c055c08u; return 0; }
target=r[0];
r[16]=0x0c055c0cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055c0cu) { target=s->pc; goto dispatch; }
goto P_0c055c0c;
P_0c055c0a: /* original 0009, guest PC 0x0c055c0a */
if(!s->budget--) { s->failed_pc=0x0c055c0au; return 0; }
goto P_0c055c0c;
P_0c055c0c: /* original d347, guest PC 0x0c055c0c */
if(!s->budget--) { s->failed_pc=0x0c055c0cu; return 0; }
r[3]=read(ram,0x0c055d2cu,4);
goto P_0c055c0e;
P_0c055c0e: /* original c749, guest PC 0x0c055c0e */
if(!s->budget--) { s->failed_pc=0x0c055c0eu; return 0; }
r[0]=0x0c055d34u;
goto P_0c055c10;
P_0c055c10: /* original 6106, guest PC 0x0c055c10 */
if(!s->budget--) { s->failed_pc=0x0c055c10u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055c12;
P_0c055c12: /* original f418, guest PC 0x0c055c12 */
if(!s->budget--) { s->failed_pc=0x0c055c12u; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
goto P_0c055c14;
P_0c055c14: /* original 6106, guest PC 0x0c055c14 */
if(!s->budget--) { s->failed_pc=0x0c055c14u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055c16;
P_0c055c16: /* original 430b, guest PC 0x0c055c16 */
if(!s->budget--) { s->failed_pc=0x0c055c16u; return 0; }
target=r[3];
r[16]=0x0c055c1au;
vf3_matrix_load(s,ram,5,r[1]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055c1au) { target=s->pc; goto dispatch; }
goto P_0c055c1a;
P_0c055c18: /* original f518, guest PC 0x0c055c18 */
if(!s->budget--) { s->failed_pc=0x0c055c18u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
goto P_0c055c1a;
P_0c055c1a: /* original 54e1, guest PC 0x0c055c1a */
if(!s->budget--) { s->failed_pc=0x0c055c1au; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c055c1c;
P_0c055c1c: /* original c60b, guest PC 0x0c055c1c */
if(!s->budget--) { s->failed_pc=0x0c055c1cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+44,4);
goto P_0c055c1e;
P_0c055c1e: /* original 6503, guest PC 0x0c055c1e */
if(!s->budget--) { s->failed_pc=0x0c055c1eu; return 0; }
r[5]=r[0];
goto P_0c055c20;
P_0c055c20: /* original c604, guest PC 0x0c055c20 */
if(!s->budget--) { s->failed_pc=0x0c055c20u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+16,4);
goto P_0c055c22;
P_0c055c22: /* original 67e3, guest PC 0x0c055c22 */
if(!s->budget--) { s->failed_pc=0x0c055c22u; return 0; }
r[7]=r[14];
goto P_0c055c24;
P_0c055c24: /* original 400b, guest PC 0x0c055c24 */
if(!s->budget--) { s->failed_pc=0x0c055c24u; return 0; }
target=r[0];
r[16]=0x0c055c28u;
r[6]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055c28u) { target=s->pc; goto dispatch; }
goto P_0c055c28;
P_0c055c26: /* original 56e2, guest PC 0x0c055c26 */
if(!s->budget--) { s->failed_pc=0x0c055c26u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c055c28;
P_0c055c28: /* original d33f, guest PC 0x0c055c28 */
if(!s->budget--) { s->failed_pc=0x0c055c28u; return 0; }
r[3]=read(ram,0x0c055d28u,4);
goto P_0c055c2a;
P_0c055c2a: /* original 430b, guest PC 0x0c055c2a */
if(!s->budget--) { s->failed_pc=0x0c055c2au; return 0; }
target=r[3];
r[16]=0x0c055c2eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055c2eu) { target=s->pc; goto dispatch; }
goto P_0c055c2e;
P_0c055c2c: /* original e401, guest PC 0x0c055c2c */
if(!s->budget--) { s->failed_pc=0x0c055c2cu; return 0; }
r[4]=0x00000001u;
goto P_0c055c2e;
P_0c055c2e: /* original 64e3, guest PC 0x0c055c2e */
if(!s->budget--) { s->failed_pc=0x0c055c2eu; return 0; }
r[4]=r[14];
goto P_0c055c30;
P_0c055c30: /* original e001, guest PC 0x0c055c30 */
if(!s->budget--) { s->failed_pc=0x0c055c30u; return 0; }
r[0]=0x00000001u;
goto P_0c055c32;
P_0c055c32: /* original d10c, guest PC 0x0c055c32 */
if(!s->budget--) { s->failed_pc=0x0c055c32u; return 0; }
r[1]=read(ram,0x0c055c64u,4);
goto P_0c055c34;
P_0c055c34: /* original 410b, guest PC 0x0c055c34 */
if(!s->budget--) { s->failed_pc=0x0c055c34u; return 0; }
target=r[1];
r[16]=0x0c055c38u;
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055c38u) { target=s->pc; goto dispatch; }
goto P_0c055c38;
P_0c055c36: /* original c211, guest PC 0x0c055c36 */
if(!s->budget--) { s->failed_pc=0x0c055c36u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
goto P_0c055c38;
P_0c055c38: /* original c60c, guest PC 0x0c055c38 */
if(!s->budget--) { s->failed_pc=0x0c055c38u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+48,4);
goto P_0c055c3a;
P_0c055c3a: /* original c20b, guest PC 0x0c055c3a */
if(!s->budget--) { s->failed_pc=0x0c055c3au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+44,r[0],4);
goto P_0c055c3c;
P_0c055c3c: /* original c60f, guest PC 0x0c055c3c */
if(!s->budget--) { s->failed_pc=0x0c055c3cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+60,4);
goto P_0c055c3e;
P_0c055c3e: /* original c20e, guest PC 0x0c055c3e */
if(!s->budget--) { s->failed_pc=0x0c055c3eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+56,r[0],4);
goto P_0c055c40;
P_0c055c40: /* original e000, guest PC 0x0c055c40 */
if(!s->budget--) { s->failed_pc=0x0c055c40u; return 0; }
r[0]=0x00000000u;
goto P_0c055c42;
P_0c055c42: /* original c211, guest PC 0x0c055c42 */
if(!s->budget--) { s->failed_pc=0x0c055c42u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
goto P_0c055c44;
P_0c055c44: /* original 4f26, guest PC 0x0c055c44 */
if(!s->budget--) { s->failed_pc=0x0c055c44u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055c46;
P_0c055c46: /* original 68f6, guest PC 0x0c055c46 */
if(!s->budget--) { s->failed_pc=0x0c055c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c055c48;
P_0c055c48: /* original 69f6, guest PC 0x0c055c48 */
if(!s->budget--) { s->failed_pc=0x0c055c48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c055c4a;
P_0c055c4a: /* original 6af6, guest PC 0x0c055c4a */
if(!s->budget--) { s->failed_pc=0x0c055c4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c055c4c;
P_0c055c4c: /* original 6bf6, guest PC 0x0c055c4c */
if(!s->budget--) { s->failed_pc=0x0c055c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c055c4e;
P_0c055c4e: /* original 6cf6, guest PC 0x0c055c4e */
if(!s->budget--) { s->failed_pc=0x0c055c4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c055c50;
P_0c055c50: /* original 6df6, guest PC 0x0c055c50 */
if(!s->budget--) { s->failed_pc=0x0c055c50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055c52;
P_0c055c52: /* original 6ef6, guest PC 0x0c055c52 */
if(!s->budget--) { s->failed_pc=0x0c055c52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055c54;
P_0c055c54: /* original fcf9, guest PC 0x0c055c54 */
if(!s->budget--) { s->failed_pc=0x0c055c54u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c56;
P_0c055c56: /* original fdf9, guest PC 0x0c055c56 */
if(!s->budget--) { s->failed_pc=0x0c055c56u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c58;
P_0c055c58: /* original fef9, guest PC 0x0c055c58 */
if(!s->budget--) { s->failed_pc=0x0c055c58u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c5a;
P_0c055c5a: /* original 000b, guest PC 0x0c055c5a */
if(!s->budget--) { s->failed_pc=0x0c055c5au; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c055c5c: /* original fff9, guest PC 0x0c055c5c */
if(!s->budget--) { s->failed_pc=0x0c055c5cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c055c5eu,s,ram);
P_0c0568a2: /* original 4f22, guest PC 0x0c0568a2 */
if(!s->budget--) { s->failed_pc=0x0c0568a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0568a4;
P_0c0568a4: /* original 0483, guest PC 0x0c0568a4 */
if(!s->budget--) { s->failed_pc=0x0c0568a4u; return 0; }
goto P_0c0568a6;
P_0c0568a6: /* original 6e43, guest PC 0x0c0568a6 */
if(!s->budget--) { s->failed_pc=0x0c0568a6u; return 0; }
r[14]=r[4];
goto P_0c0568a8;
P_0c0568a8: /* original 7e04, guest PC 0x0c0568a8 */
if(!s->budget--) { s->failed_pc=0x0c0568a8u; return 0; }
r[14]+=0x00000004u;
goto P_0c0568aa;
P_0c0568aa: /* original d407, guest PC 0x0c0568aa */
if(!s->budget--) { s->failed_pc=0x0c0568aau; return 0; }
r[4]=read(ram,0x0c0568c8u,4);
goto P_0c0568ac;
P_0c0568ac: /* original 6442, guest PC 0x0c0568ac */
if(!s->budget--) { s->failed_pc=0x0c0568acu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0568ae;
P_0c0568ae: /* original 7404, guest PC 0x0c0568ae */
if(!s->budget--) { s->failed_pc=0x0c0568aeu; return 0; }
r[4]+=0x00000004u;
goto P_0c0568b0;
P_0c0568b0: /* original 441a, guest PC 0x0c0568b0 */
if(!s->budget--) { s->failed_pc=0x0c0568b0u; return 0; }
r[19]=r[4];
goto P_0c0568b2;
P_0c0568b2: /* original d006, guest PC 0x0c0568b2 */
if(!s->budget--) { s->failed_pc=0x0c0568b2u; return 0; }
r[0]=read(ram,0x0c0568ccu,4);
goto P_0c0568b4;
P_0c0568b4: /* original 6002, guest PC 0x0c0568b4 */
if(!s->budget--) { s->failed_pc=0x0c0568b4u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0568b6;
P_0c0568b6: /* original 2008, guest PC 0x0c0568b6 */
if(!s->budget--) { s->failed_pc=0x0c0568b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0568b8;
P_0c0568b8: /* original 8b02, guest PC 0x0c0568b8 */
if(!s->budget--) { s->failed_pc=0x0c0568b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0568c0; }
goto P_0c0568ba;
P_0c0568ba: /* original d005, guest PC 0x0c0568ba */
if(!s->budget--) { s->failed_pc=0x0c0568bau; return 0; }
r[0]=read(ram,0x0c0568d0u,4);
goto P_0c0568bc;
P_0c0568bc: /* original a00e, guest PC 0x0c0568bc */
if(!s->budget--) { s->failed_pc=0x0c0568bcu; return 0; }
r[20]=r[0];
goto P_0c0568dc;
P_0c0568be: /* original 400a, guest PC 0x0c0568be */
if(!s->budget--) { s->failed_pc=0x0c0568beu; return 0; }
r[20]=r[0];
goto P_0c0568c0;
P_0c0568c0: /* original d004, guest PC 0x0c0568c0 */
if(!s->budget--) { s->failed_pc=0x0c0568c0u; return 0; }
r[0]=read(ram,0x0c0568d4u,4);
goto P_0c0568c2;
P_0c0568c2: /* original a00b, guest PC 0x0c0568c2 */
if(!s->budget--) { s->failed_pc=0x0c0568c2u; return 0; }
r[20]=r[0];
goto P_0c0568dc;
P_0c0568c4: /* original 400a, guest PC 0x0c0568c4 */
if(!s->budget--) { s->failed_pc=0x0c0568c4u; return 0; }
r[20]=r[0];
return vf3_matrix_family(0x0c0568c6u,s,ram);
P_0c0568d8: /* original a0c3, guest PC 0x0c0568d8 */
if(!s->budget--) { s->failed_pc=0x0c0568d8u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c056a62;
P_0c0568da: /* original 4b10, guest PC 0x0c0568da */
if(!s->budget--) { s->failed_pc=0x0c0568dau; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0568dc;
P_0c0568dc: /* original f3fd, guest PC 0x0c0568dc */
if(!s->budget--) { s->failed_pc=0x0c0568dcu; return 0; }
r[18]^=0x100000u;
goto P_0c0568de;
P_0c0568de: /* original 6be5, guest PC 0x0c0568de */
if(!s->budget--) { s->failed_pc=0x0c0568deu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[11]=tmp;
goto P_0c0568e0;
P_0c0568e0: /* original 68e3, guest PC 0x0c0568e0 */
if(!s->budget--) { s->failed_pc=0x0c0568e0u; return 0; }
r[8]=r[14];
goto P_0c0568e2;
P_0c0568e2: /* original 85e1, guest PC 0x0c0568e2 */
if(!s->budget--) { s->failed_pc=0x0c0568e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c0568e4;
P_0c0568e4: /* original 7e08, guest PC 0x0c0568e4 */
if(!s->budget--) { s->failed_pc=0x0c0568e4u; return 0; }
r[14]+=0x00000008u;
goto P_0c0568e6;
P_0c0568e6: /* original 0e83, guest PC 0x0c0568e6 */
if(!s->budget--) { s->failed_pc=0x0c0568e6u; return 0; }
goto P_0c0568e8;
P_0c0568e8: /* original 4008, guest PC 0x0c0568e8 */
if(!s->budget--) { s->failed_pc=0x0c0568e8u; return 0; }
r[0]<<=2;
goto P_0c0568ea;
P_0c0568ea: /* original 6785, guest PC 0x0c0568ea */
if(!s->budget--) { s->failed_pc=0x0c0568eau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[7]=tmp;
goto P_0c0568ec;
P_0c0568ec: /* original 4008, guest PC 0x0c0568ec */
if(!s->budget--) { s->failed_pc=0x0c0568ecu; return 0; }
r[0]<<=2;
goto P_0c0568ee;
P_0c0568ee: /* original f8d6, guest PC 0x0c0568ee */
if(!s->budget--) { s->failed_pc=0x0c0568eeu; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0568f0;
P_0c0568f0: /* original 30dc, guest PC 0x0c0568f0 */
if(!s->budget--) { s->failed_pc=0x0c0568f0u; return 0; }
r[0]+=r[13];
goto P_0c0568f2;
P_0c0568f2: /* original 5302, guest PC 0x0c0568f2 */
if(!s->budget--) { s->failed_pc=0x0c0568f2u; return 0; }
r[3]=read(ram,r[0]+8,4);
goto P_0c0568f4;
P_0c0568f4: /* original 7008, guest PC 0x0c0568f4 */
if(!s->budget--) { s->failed_pc=0x0c0568f4u; return 0; }
r[0]+=0x00000008u;
goto P_0c0568f6;
P_0c0568f6: /* original fa08, guest PC 0x0c0568f6 */
if(!s->budget--) { s->failed_pc=0x0c0568f6u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c0568f8;
P_0c0568f8: /* original 4711, guest PC 0x0c0568f8 */
if(!s->budget--) { s->failed_pc=0x0c0568f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0568fa;
P_0c0568fa: /* original 8d02, guest PC 0x0c0568fa */
if(!s->budget--) { s->failed_pc=0x0c0568fau; return 0; }
cond=r[17]&1u;
r[5]=0xffffffffu;
if(cond) { goto P_0c056902; }
goto P_0c0568fe;
P_0c0568fc: /* original e5ff, guest PC 0x0c0568fc */
if(!s->budget--) { s->failed_pc=0x0c0568fcu; return 0; }
r[5]=0xffffffffu;
goto P_0c0568fe;
P_0c0568fe: /* original 6557, guest PC 0x0c0568fe */
if(!s->budget--) { s->failed_pc=0x0c0568feu; return 0; }
r[5]=~r[5];
goto P_0c056900;
P_0c056900: /* original 677b, guest PC 0x0c056900 */
if(!s->budget--) { s->failed_pc=0x0c056900u; return 0; }
r[7]=0u-r[7];
goto P_0c056902;
P_0c056902: /* original 33a6, guest PC 0x0c056902 */
if(!s->budget--) { s->failed_pc=0x0c056902u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[10])!=0);
goto P_0c056904;
P_0c056904: /* original 0429, guest PC 0x0c056904 */
if(!s->budget--) { s->failed_pc=0x0c056904u; return 0; }
r[4]=r[17]&1u;
goto P_0c056906;
P_0c056906: /* original 4311, guest PC 0x0c056906 */
if(!s->budget--) { s->failed_pc=0x0c056906u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c056908;
P_0c056908: /* original 0929, guest PC 0x0c056908 */
if(!s->budget--) { s->failed_pc=0x0c056908u; return 0; }
r[9]=r[17]&1u;
goto P_0c05690a;
P_0c05690a: /* original 8b00, guest PC 0x0c05690a */
if(!s->budget--) { s->failed_pc=0x0c05690au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05690e; }
goto P_0c05690c;
P_0c05690c: /* original 6557, guest PC 0x0c05690c */
if(!s->budget--) { s->failed_pc=0x0c05690cu; return 0; }
r[5]=~r[5];
goto P_0c05690e;
P_0c05690e: /* original 60e1, guest PC 0x0c05690e */
if(!s->budget--) { s->failed_pc=0x0c05690eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c056910;
P_0c056910: /* original 4710, guest PC 0x0c056910 */
if(!s->budget--) { s->failed_pc=0x0c056910u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c056912;
P_0c056912: /* original 8de1, guest PC 0x0c056912 */
if(!s->budget--) { s->failed_pc=0x0c056912u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0568d8; }
goto P_0c056916;
P_0c056914: /* original 0009, guest PC 0x0c056914 */
if(!s->budget--) { s->failed_pc=0x0c056914u; return 0; }
goto P_0c056916;
P_0c056916: /* original 4008, guest PC 0x0c056916 */
if(!s->budget--) { s->failed_pc=0x0c056916u; return 0; }
r[0]<<=2;
goto P_0c056918;
P_0c056918: /* original 4008, guest PC 0x0c056918 */
if(!s->budget--) { s->failed_pc=0x0c056918u; return 0; }
r[0]<<=2;
goto P_0c05691a;
P_0c05691a: /* original fcd6, guest PC 0x0c05691a */
if(!s->budget--) { s->failed_pc=0x0c05691au; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c05691c;
P_0c05691c: /* original 30dc, guest PC 0x0c05691c */
if(!s->budget--) { s->failed_pc=0x0c05691cu; return 0; }
r[0]+=r[13];
goto P_0c05691e;
P_0c05691e: /* original 5302, guest PC 0x0c05691e */
if(!s->budget--) { s->failed_pc=0x0c05691eu; return 0; }
r[3]=read(ram,r[0]+8,4);
goto P_0c056920;
P_0c056920: /* original 7008, guest PC 0x0c056920 */
if(!s->budget--) { s->failed_pc=0x0c056920u; return 0; }
r[0]+=0x00000008u;
goto P_0c056922;
P_0c056922: /* original fe08, guest PC 0x0c056922 */
if(!s->budget--) { s->failed_pc=0x0c056922u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c056924;
P_0c056924: /* original 7e06, guest PC 0x0c056924 */
if(!s->budget--) { s->failed_pc=0x0c056924u; return 0; }
r[14]+=0x00000006u;
goto P_0c056926;
P_0c056926: /* original 0e83, guest PC 0x0c056926 */
if(!s->budget--) { s->failed_pc=0x0c056926u; return 0; }
goto P_0c056928;
P_0c056928: /* original 33a6, guest PC 0x0c056928 */
if(!s->budget--) { s->failed_pc=0x0c056928u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[10])!=0);
goto P_0c05692a;
P_0c05692a: /* original 4424, guest PC 0x0c05692a */
if(!s->budget--) { s->failed_pc=0x0c05692au; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c05692c;
P_0c05692c: /* original 4311, guest PC 0x0c05692c */
if(!s->budget--) { s->failed_pc=0x0c05692cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c05692e;
P_0c05692e: /* original 78fa, guest PC 0x0c05692e */
if(!s->budget--) { s->failed_pc=0x0c05692eu; return 0; }
r[8]+=0xfffffffau;
goto P_0c056930;
P_0c056930: /* original 8b00, guest PC 0x0c056930 */
if(!s->budget--) { s->failed_pc=0x0c056930u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c056934; }
goto P_0c056932;
P_0c056932: /* original 6557, guest PC 0x0c056932 */
if(!s->budget--) { s->failed_pc=0x0c056932u; return 0; }
r[5]=~r[5];
goto P_0c056934;
P_0c056934: /* original 4924, guest PC 0x0c056934 */
if(!s->budget--) { s->failed_pc=0x0c056934u; return 0; }
tmp=r[9]>>31; r[9]=(r[9]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c056936;
P_0c056936: /* original e600, guest PC 0x0c056936 */
if(!s->budget--) { s->failed_pc=0x0c056936u; return 0; }
r[6]=0x00000000u;
goto P_0c056938;
P_0c056938: /* original 6043, guest PC 0x0c056938 */
if(!s->budget--) { s->failed_pc=0x0c056938u; return 0; }
r[0]=r[4];
goto P_0c05693a;
P_0c05693a: /* original 4710, guest PC 0x0c05693a */
if(!s->budget--) { s->failed_pc=0x0c05693au; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c05693c;
P_0c05693c: /* original 61e1, guest PC 0x0c05693c */
if(!s->budget--) { s->failed_pc=0x0c05693cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c05693e;
P_0c05693e: /* original 8dcb, guest PC 0x0c05693e */
if(!s->budget--) { s->failed_pc=0x0c05693eu; return 0; }
cond=r[17]&1u;
r[2]=0x00000004u;
if(cond) { goto P_0c0568d8; }
goto P_0c056942;
P_0c056940: /* original e204, guest PC 0x0c056940 */
if(!s->budget--) { s->failed_pc=0x0c056940u; return 0; }
r[2]=0x00000004u;
goto P_0c056942;
P_0c056942: /* original f48c, guest PC 0x0c056942 */
if(!s->budget--) { s->failed_pc=0x0c056942u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c056944;
P_0c056944: /* original 2928, guest PC 0x0c056944 */
if(!s->budget--) { s->failed_pc=0x0c056944u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[2])==0)!=0);
goto P_0c056946;
P_0c056946: /* original f6ac, guest PC 0x0c056946 */
if(!s->budget--) { s->failed_pc=0x0c056946u; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c056948;
P_0c056948: /* original 322a, guest PC 0x0c056948 */
if(!s->budget--) { s->failed_pc=0x0c056948u; return 0; }
wide=(uint64_t)r[2]-r[2]-(r[17]&1u); r[2]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c05694a;
P_0c05694a: /* original faec, guest PC 0x0c05694a */
if(!s->budget--) { s->failed_pc=0x0c05694au; return 0; }
vf3_matrix_move(s,10,14);
goto P_0c05694c;
P_0c05694c: /* original 4108, guest PC 0x0c05694c */
if(!s->budget--) { s->failed_pc=0x0c05694cu; return 0; }
r[1]<<=2;
goto P_0c05694e;
P_0c05694e: /* original f8cc, guest PC 0x0c05694e */
if(!s->budget--) { s->failed_pc=0x0c05694eu; return 0; }
vf3_matrix_move(s,8,12);
goto P_0c056950;
P_0c056950: /* original 4108, guest PC 0x0c056950 */
if(!s->budget--) { s->failed_pc=0x0c056950u; return 0; }
r[1]<<=2;
goto P_0c056952;
P_0c056952: /* original 31dc, guest PC 0x0c056952 */
if(!s->budget--) { s->failed_pc=0x0c056952u; return 0; }
r[1]+=r[13];
goto P_0c056954;
P_0c056954: /* original 5312, guest PC 0x0c056954 */
if(!s->budget--) { s->failed_pc=0x0c056954u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c056956;
P_0c056956: /* original 7e06, guest PC 0x0c056956 */
if(!s->budget--) { s->failed_pc=0x0c056956u; return 0; }
r[14]+=0x00000006u;
goto P_0c056958;
P_0c056958: /* original fc19, guest PC 0x0c056958 */
if(!s->budget--) { s->failed_pc=0x0c056958u; return 0; }
vf3_matrix_load(s,ram,12,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c05695a;
P_0c05695a: /* original 252a, guest PC 0x0c05695a */
if(!s->budget--) { s->failed_pc=0x0c05695au; return 0; }
r[5]^=r[2];
goto P_0c05695c;
P_0c05695c: /* original fe19, guest PC 0x0c05695c */
if(!s->budget--) { s->failed_pc=0x0c05695cu; return 0; }
vf3_matrix_load(s,ram,14,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c05695e;
P_0c05695e: /* original 33a6, guest PC 0x0c05695e */
if(!s->budget--) { s->failed_pc=0x0c05695eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[10])!=0);
goto P_0c056960;
P_0c056960: /* original 0e83, guest PC 0x0c056960 */
if(!s->budget--) { s->failed_pc=0x0c056960u; return 0; }
goto P_0c056962;
P_0c056962: /* original 4024, guest PC 0x0c056962 */
if(!s->budget--) { s->failed_pc=0x0c056962u; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c056964;
P_0c056964: /* original 4311, guest PC 0x0c056964 */
if(!s->budget--) { s->failed_pc=0x0c056964u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c056966;
P_0c056966: /* original c907, guest PC 0x0c056966 */
if(!s->budget--) { s->failed_pc=0x0c056966u; return 0; }
r[0]&=7u;
goto P_0c056968;
P_0c056968: /* original 8f01, guest PC 0x0c056968 */
if(!s->budget--) { s->failed_pc=0x0c056968u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05696e; }
goto P_0c05696c;
P_0c05696a: /* original 0009, guest PC 0x0c05696a */
if(!s->budget--) { s->failed_pc=0x0c05696au; return 0; }
goto P_0c05696c;
P_0c05696c: /* original 6557, guest PC 0x0c05696c */
if(!s->budget--) { s->failed_pc=0x0c05696cu; return 0; }
r[5]=~r[5];
goto P_0c05696e;
P_0c05696e: /* original 4924, guest PC 0x0c05696e */
if(!s->budget--) { s->failed_pc=0x0c05696eu; return 0; }
tmp=r[9]>>31; r[9]=(r[9]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c056970;
P_0c056970: /* original 8807, guest PC 0x0c056970 */
if(!s->budget--) { s->failed_pc=0x0c056970u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c056972;
P_0c056972: /* original 8de2, guest PC 0x0c056972 */
if(!s->budget--) { s->failed_pc=0x0c056972u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000006u;
if(cond) { goto P_0c05693a; }
goto P_0c056976;
P_0c056974: /* original 7806, guest PC 0x0c056974 */
if(!s->budget--) { s->failed_pc=0x0c056974u; return 0; }
r[8]+=0x00000006u;
goto P_0c056976;
P_0c056976: /* original f0cc, guest PC 0x0c056976 */
if(!s->budget--) { s->failed_pc=0x0c056976u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c056978;
P_0c056978: /* original f151, guest PC 0x0c056978 */
if(!s->budget--) { s->failed_pc=0x0c056978u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'-');
goto P_0c05697a;
P_0c05697a: /* original f081, guest PC 0x0c05697a */
if(!s->budget--) { s->failed_pc=0x0c05697au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c05697c;
P_0c05697c: /* original f102, guest PC 0x0c05697c */
if(!s->budget--) { s->failed_pc=0x0c05697cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c05697e;
P_0c05697e: /* original f28d, guest PC 0x0c05697e */
if(!s->budget--) { s->failed_pc=0x0c05697eu; return 0; }
fr[2]=0;
goto P_0c056980;
P_0c056980: /* original f211, guest PC 0x0c056980 */
if(!s->budget--) { s->failed_pc=0x0c056980u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'-');
goto P_0c056982;
P_0c056982: /* original f0cc, guest PC 0x0c056982 */
if(!s->budget--) { s->failed_pc=0x0c056982u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c056984;
P_0c056984: /* original f191, guest PC 0x0c056984 */
if(!s->budget--) { s->failed_pc=0x0c056984u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'-');
goto P_0c056986;
P_0c056986: /* original f041, guest PC 0x0c056986 */
if(!s->budget--) { s->failed_pc=0x0c056986u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'-');
goto P_0c056988;
P_0c056988: /* original 4511, guest PC 0x0c056988 */
if(!s->budget--) { s->failed_pc=0x0c056988u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c05698a;
P_0c05698a: /* original f21e, guest PC 0x0c05698a */
if(!s->budget--) { s->failed_pc=0x0c05698au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[1],fr[2],r[18]);
goto P_0c05698c;
P_0c05698c: /* original 8d01, guest PC 0x0c05698c */
if(!s->budget--) { s->failed_pc=0x0c05698cu; return 0; }
cond=r[17]&1u;
fr[0]=0;
if(cond) { goto P_0c056992; }
goto P_0c056990;
P_0c05698e: /* original f08d, guest PC 0x0c05698e */
if(!s->budget--) { s->failed_pc=0x0c05698eu; return 0; }
fr[0]=0;
goto P_0c056990;
P_0c056990: /* original f24d, guest PC 0x0c056990 */
if(!s->budget--) { s->failed_pc=0x0c056990u; return 0; }
fr[2]^=0x80000000u;
goto P_0c056992;
P_0c056992: /* original f205, guest PC 0x0c056992 */
if(!s->budget--) { s->failed_pc=0x0c056992u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[0]))!=0);
goto P_0c056994;
P_0c056994: /* original 8fd1, guest PC 0x0c056994 */
if(!s->budget--) { s->failed_pc=0x0c056994u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05693a; }
goto P_0c056998;
P_0c056996: /* original 0009, guest PC 0x0c056996 */
if(!s->budget--) { s->failed_pc=0x0c056996u; return 0; }
goto P_0c056998;
P_0c056998: /* original 8800, guest PC 0x0c056998 */
if(!s->budget--) { s->failed_pc=0x0c056998u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05699a;
P_0c05699a: /* original f3fd, guest PC 0x0c05699a */
if(!s->budget--) { s->failed_pc=0x0c05699au; return 0; }
r[18]^=0x100000u;
goto P_0c05699c;
P_0c05699c: /* original 8f43, guest PC 0x0c05699c */
if(!s->budget--) { s->failed_pc=0x0c05699cu; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(!cond) { goto P_0c056a26; }
goto P_0c0569a0;
P_0c05699e: /* original 66c3, guest PC 0x0c05699e */
if(!s->budget--) { s->failed_pc=0x0c05699eu; return 0; }
r[6]=r[12];
goto P_0c0569a0;
P_0c0569a0: /* original 010a, guest PC 0x0c0569a0 */
if(!s->budget--) { s->failed_pc=0x0c0569a0u; return 0; }
r[1]=r[20];
goto P_0c0569a2;
P_0c0569a2: /* original 5110, guest PC 0x0c0569a2 */
if(!s->budget--) { s->failed_pc=0x0c0569a2u; return 0; }
r[1]=read(ram,r[1]+0,4);
goto P_0c0569a4;
P_0c0569a4: /* original 410b, guest PC 0x0c0569a4 */
if(!s->budget--) { s->failed_pc=0x0c0569a4u; return 0; }
target=r[1];
r[16]=0x0c0569a8u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0569a8u) { target=s->pc; goto dispatch; }
goto P_0c0569a8;
P_0c0569a6: /* original 6403, guest PC 0x0c0569a6 */
if(!s->budget--) { s->failed_pc=0x0c0569a6u; return 0; }
r[4]=r[0];
goto P_0c0569a8;
P_0c0569a8: /* original 010a, guest PC 0x0c0569a8 */
if(!s->budget--) { s->failed_pc=0x0c0569a8u; return 0; }
r[1]=r[20];
goto P_0c0569aa;
P_0c0569aa: /* original 5111, guest PC 0x0c0569aa */
if(!s->budget--) { s->failed_pc=0x0c0569aau; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c0569ac;
P_0c0569ac: /* original 410b, guest PC 0x0c0569ac */
if(!s->budget--) { s->failed_pc=0x0c0569acu; return 0; }
target=r[1];
r[16]=0x0c0569b0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0569b0u) { target=s->pc; goto dispatch; }
goto P_0c0569b0;
P_0c0569ae: /* original 0009, guest PC 0x0c0569ae */
if(!s->budget--) { s->failed_pc=0x0c0569aeu; return 0; }
goto P_0c0569b0;
P_0c0569b0: /* original 010a, guest PC 0x0c0569b0 */
if(!s->budget--) { s->failed_pc=0x0c0569b0u; return 0; }
r[1]=r[20];
goto P_0c0569b2;
P_0c0569b2: /* original 5112, guest PC 0x0c0569b2 */
if(!s->budget--) { s->failed_pc=0x0c0569b2u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c0569b4;
P_0c0569b4: /* original 410b, guest PC 0x0c0569b4 */
if(!s->budget--) { s->failed_pc=0x0c0569b4u; return 0; }
target=r[1];
r[16]=0x0c0569b8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0569b8u) { target=s->pc; goto dispatch; }
goto P_0c0569b8;
P_0c0569b6: /* original 0009, guest PC 0x0c0569b6 */
if(!s->budget--) { s->failed_pc=0x0c0569b6u; return 0; }
goto P_0c0569b8;
P_0c0569b8: /* original e204, guest PC 0x0c0569b8 */
if(!s->budget--) { s->failed_pc=0x0c0569b8u; return 0; }
r[2]=0x00000004u;
goto P_0c0569ba;
P_0c0569ba: /* original 60e1, guest PC 0x0c0569ba */
if(!s->budget--) { s->failed_pc=0x0c0569bau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0569bc;
P_0c0569bc: /* original 4710, guest PC 0x0c0569bc */
if(!s->budget--) { s->failed_pc=0x0c0569bcu; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c0569be;
P_0c0569be: /* original f3fd, guest PC 0x0c0569be */
if(!s->budget--) { s->failed_pc=0x0c0569beu; return 0; }
r[18]^=0x100000u;
goto P_0c0569c0;
P_0c0569c0: /* original 8d48, guest PC 0x0c0569c0 */
if(!s->budget--) { s->failed_pc=0x0c0569c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c056a54; }
goto P_0c0569c4;
P_0c0569c2: /* original 0009, guest PC 0x0c0569c2 */
if(!s->budget--) { s->failed_pc=0x0c0569c2u; return 0; }
goto P_0c0569c4;
P_0c0569c4: /* original 2928, guest PC 0x0c0569c4 */
if(!s->budget--) { s->failed_pc=0x0c0569c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[2])==0)!=0);
goto P_0c0569c6;
P_0c0569c6: /* original 4008, guest PC 0x0c0569c6 */
if(!s->budget--) { s->failed_pc=0x0c0569c6u; return 0; }
r[0]<<=2;
goto P_0c0569c8;
P_0c0569c8: /* original f48c, guest PC 0x0c0569c8 */
if(!s->budget--) { s->failed_pc=0x0c0569c8u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0569ca;
P_0c0569ca: /* original f6ac, guest PC 0x0c0569ca */
if(!s->budget--) { s->failed_pc=0x0c0569cau; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c0569cc;
P_0c0569cc: /* original 322a, guest PC 0x0c0569cc */
if(!s->budget--) { s->failed_pc=0x0c0569ccu; return 0; }
wide=(uint64_t)r[2]-r[2]-(r[17]&1u); r[2]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0569ce;
P_0c0569ce: /* original f8cc, guest PC 0x0c0569ce */
if(!s->budget--) { s->failed_pc=0x0c0569ceu; return 0; }
vf3_matrix_move(s,8,12);
goto P_0c0569d0;
P_0c0569d0: /* original faec, guest PC 0x0c0569d0 */
if(!s->budget--) { s->failed_pc=0x0c0569d0u; return 0; }
vf3_matrix_move(s,10,14);
goto P_0c0569d2;
P_0c0569d2: /* original 4008, guest PC 0x0c0569d2 */
if(!s->budget--) { s->failed_pc=0x0c0569d2u; return 0; }
r[0]<<=2;
goto P_0c0569d4;
P_0c0569d4: /* original fcd6, guest PC 0x0c0569d4 */
if(!s->budget--) { s->failed_pc=0x0c0569d4u; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c0569d6;
P_0c0569d6: /* original 30dc, guest PC 0x0c0569d6 */
if(!s->budget--) { s->failed_pc=0x0c0569d6u; return 0; }
r[0]+=r[13];
goto P_0c0569d8;
P_0c0569d8: /* original 5302, guest PC 0x0c0569d8 */
if(!s->budget--) { s->failed_pc=0x0c0569d8u; return 0; }
r[3]=read(ram,r[0]+8,4);
goto P_0c0569da;
P_0c0569da: /* original 7008, guest PC 0x0c0569da */
if(!s->budget--) { s->failed_pc=0x0c0569dau; return 0; }
r[0]+=0x00000008u;
goto P_0c0569dc;
P_0c0569dc: /* original fe08, guest PC 0x0c0569dc */
if(!s->budget--) { s->failed_pc=0x0c0569dcu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0569de;
P_0c0569de: /* original 7e06, guest PC 0x0c0569de */
if(!s->budget--) { s->failed_pc=0x0c0569deu; return 0; }
r[14]+=0x00000006u;
goto P_0c0569e0;
P_0c0569e0: /* original 0e83, guest PC 0x0c0569e0 */
if(!s->budget--) { s->failed_pc=0x0c0569e0u; return 0; }
goto P_0c0569e2;
P_0c0569e2: /* original 252a, guest PC 0x0c0569e2 */
if(!s->budget--) { s->failed_pc=0x0c0569e2u; return 0; }
r[5]^=r[2];
goto P_0c0569e4;
P_0c0569e4: /* original f0cc, guest PC 0x0c0569e4 */
if(!s->budget--) { s->failed_pc=0x0c0569e4u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c0569e6;
P_0c0569e6: /* original f151, guest PC 0x0c0569e6 */
if(!s->budget--) { s->failed_pc=0x0c0569e6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'-');
goto P_0c0569e8;
P_0c0569e8: /* original f081, guest PC 0x0c0569e8 */
if(!s->budget--) { s->failed_pc=0x0c0569e8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c0569ea;
P_0c0569ea: /* original f102, guest PC 0x0c0569ea */
if(!s->budget--) { s->failed_pc=0x0c0569eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c0569ec;
P_0c0569ec: /* original f28d, guest PC 0x0c0569ec */
if(!s->budget--) { s->failed_pc=0x0c0569ecu; return 0; }
fr[2]=0;
goto P_0c0569ee;
P_0c0569ee: /* original f211, guest PC 0x0c0569ee */
if(!s->budget--) { s->failed_pc=0x0c0569eeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'-');
goto P_0c0569f0;
P_0c0569f0: /* original f0cc, guest PC 0x0c0569f0 */
if(!s->budget--) { s->failed_pc=0x0c0569f0u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c0569f2;
P_0c0569f2: /* original f191, guest PC 0x0c0569f2 */
if(!s->budget--) { s->failed_pc=0x0c0569f2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'-');
goto P_0c0569f4;
P_0c0569f4: /* original 4311, guest PC 0x0c0569f4 */
if(!s->budget--) { s->failed_pc=0x0c0569f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0569f6;
P_0c0569f6: /* original f041, guest PC 0x0c0569f6 */
if(!s->budget--) { s->failed_pc=0x0c0569f6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'-');
goto P_0c0569f8;
P_0c0569f8: /* original 8f01, guest PC 0x0c0569f8 */
if(!s->budget--) { s->failed_pc=0x0c0569f8u; return 0; }
cond=r[17]&1u;
tmp=r[9]>>31; r[9]=(r[9]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
if(!cond) { goto P_0c0569fe; }
goto P_0c0569fc;
P_0c0569fa: /* original 4924, guest PC 0x0c0569fa */
if(!s->budget--) { s->failed_pc=0x0c0569fau; return 0; }
tmp=r[9]>>31; r[9]=(r[9]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c0569fc;
P_0c0569fc: /* original 6557, guest PC 0x0c0569fc */
if(!s->budget--) { s->failed_pc=0x0c0569fcu; return 0; }
r[5]=~r[5];
goto P_0c0569fe;
P_0c0569fe: /* original f21e, guest PC 0x0c0569fe */
if(!s->budget--) { s->failed_pc=0x0c0569feu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[1],fr[2],r[18]);
goto P_0c056a00;
P_0c056a00: /* original 33a6, guest PC 0x0c056a00 */
if(!s->budget--) { s->failed_pc=0x0c056a00u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[10])!=0);
goto P_0c056a02;
P_0c056a02: /* original 4424, guest PC 0x0c056a02 */
if(!s->budget--) { s->failed_pc=0x0c056a02u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c056a04;
P_0c056a04: /* original 4511, guest PC 0x0c056a04 */
if(!s->budget--) { s->failed_pc=0x0c056a04u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c056a06;
P_0c056a06: /* original 8d01, guest PC 0x0c056a06 */
if(!s->budget--) { s->failed_pc=0x0c056a06u; return 0; }
cond=r[17]&1u;
fr[0]=0;
if(cond) { goto P_0c056a0c; }
goto P_0c056a0a;
P_0c056a08: /* original f08d, guest PC 0x0c056a08 */
if(!s->budget--) { s->failed_pc=0x0c056a08u; return 0; }
fr[0]=0;
goto P_0c056a0a;
P_0c056a0a: /* original f24d, guest PC 0x0c056a0a */
if(!s->budget--) { s->failed_pc=0x0c056a0au; return 0; }
fr[2]^=0x80000000u;
goto P_0c056a0c;
P_0c056a0c: /* original f205, guest PC 0x0c056a0c */
if(!s->budget--) { s->failed_pc=0x0c056a0cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[0]))!=0);
goto P_0c056a0e;
P_0c056a0e: /* original 7806, guest PC 0x0c056a0e */
if(!s->budget--) { s->failed_pc=0x0c056a0eu; return 0; }
r[8]+=0x00000006u;
goto P_0c056a10;
P_0c056a10: /* original 8f17, guest PC 0x0c056a10 */
if(!s->budget--) { s->failed_pc=0x0c056a10u; return 0; }
cond=r[17]&1u;
r[18]^=0x100000u;
if(!cond) { goto P_0c056a42; }
goto P_0c056a14;
P_0c056a12: /* original f3fd, guest PC 0x0c056a12 */
if(!s->budget--) { s->failed_pc=0x0c056a12u; return 0; }
r[18]^=0x100000u;
goto P_0c056a14;
P_0c056a14: /* original 2448, guest PC 0x0c056a14 */
if(!s->budget--) { s->failed_pc=0x0c056a14u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c056a16;
P_0c056a16: /* original 8b0b, guest PC 0x0c056a16 */
if(!s->budget--) { s->failed_pc=0x0c056a16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c056a30; }
goto P_0c056a18;
P_0c056a18: /* original 010a, guest PC 0x0c056a18 */
if(!s->budget--) { s->failed_pc=0x0c056a18u; return 0; }
r[1]=r[20];
goto P_0c056a1a;
P_0c056a1a: /* original 5112, guest PC 0x0c056a1a */
if(!s->budget--) { s->failed_pc=0x0c056a1au; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c056a1c;
P_0c056a1c: /* original 410b, guest PC 0x0c056a1c */
if(!s->budget--) { s->failed_pc=0x0c056a1cu; return 0; }
target=r[1];
r[16]=0x0c056a20u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056a20u) { target=s->pc; goto dispatch; }
goto P_0c056a20;
P_0c056a1e: /* original 0009, guest PC 0x0c056a1e */
if(!s->budget--) { s->failed_pc=0x0c056a1eu; return 0; }
goto P_0c056a20;
P_0c056a20: /* original e204, guest PC 0x0c056a20 */
if(!s->budget--) { s->failed_pc=0x0c056a20u; return 0; }
r[2]=0x00000004u;
goto P_0c056a22;
P_0c056a22: /* original afcb, guest PC 0x0c056a22 */
if(!s->budget--) { s->failed_pc=0x0c056a22u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0569bc;
P_0c056a24: /* original 60e1, guest PC 0x0c056a24 */
if(!s->budget--) { s->failed_pc=0x0c056a24u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c056a26;
P_0c056a26: /* original d20a, guest PC 0x0c056a26 */
if(!s->budget--) { s->failed_pc=0x0c056a26u; return 0; }
r[2]=read(ram,0x0c056a50u,4);
goto P_0c056a28;
P_0c056a28: /* original 420b, guest PC 0x0c056a28 */
if(!s->budget--) { s->failed_pc=0x0c056a28u; return 0; }
target=r[2];
r[16]=0x0c056a2cu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056a2cu) { target=s->pc; goto dispatch; }
goto P_0c056a2c;
P_0c056a2a: /* original 6403, guest PC 0x0c056a2a */
if(!s->budget--) { s->failed_pc=0x0c056a2au; return 0; }
r[4]=r[0];
goto P_0c056a2c;
P_0c056a2c: /* original af83, guest PC 0x0c056a2c */
if(!s->budget--) { s->failed_pc=0x0c056a2cu; return 0; }
r[18]^=0x100000u;
goto P_0c056936;
P_0c056a2e: /* original f3fd, guest PC 0x0c056a2e */
if(!s->budget--) { s->failed_pc=0x0c056a2eu; return 0; }
r[18]^=0x100000u;
goto P_0c056a30;
P_0c056a30: /* original e0ff, guest PC 0x0c056a30 */
if(!s->budget--) { s->failed_pc=0x0c056a30u; return 0; }
r[0]=0xffffffffu;
goto P_0c056a32;
P_0c056a32: /* original 2c02, guest PC 0x0c056a32 */
if(!s->budget--) { s->failed_pc=0x0c056a32u; return 0; }
write(ram,r[12],r[0],4);
goto P_0c056a34;
P_0c056a34: /* original 0c83, guest PC 0x0c056a34 */
if(!s->budget--) { s->failed_pc=0x0c056a34u; return 0; }
goto P_0c056a36;
P_0c056a36: /* original 7c20, guest PC 0x0c056a36 */
if(!s->budget--) { s->failed_pc=0x0c056a36u; return 0; }
r[12]+=0x00000020u;
goto P_0c056a38;
P_0c056a38: /* original d205, guest PC 0x0c056a38 */
if(!s->budget--) { s->failed_pc=0x0c056a38u; return 0; }
r[2]=read(ram,0x0c056a50u,4);
goto P_0c056a3a;
P_0c056a3a: /* original 420b, guest PC 0x0c056a3a */
if(!s->budget--) { s->failed_pc=0x0c056a3au; return 0; }
target=r[2];
r[16]=0x0c056a3eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056a3eu) { target=s->pc; goto dispatch; }
goto P_0c056a3e;
P_0c056a3c: /* original e401, guest PC 0x0c056a3c */
if(!s->budget--) { s->failed_pc=0x0c056a3cu; return 0; }
r[4]=0x00000001u;
goto P_0c056a3e;
P_0c056a3e: /* original af7a, guest PC 0x0c056a3e */
if(!s->budget--) { s->failed_pc=0x0c056a3eu; return 0; }
r[18]^=0x100000u;
goto P_0c056936;
P_0c056a40: /* original f3fd, guest PC 0x0c056a40 */
if(!s->budget--) { s->failed_pc=0x0c056a40u; return 0; }
r[18]^=0x100000u;
goto P_0c056a42;
P_0c056a42: /* original e0ff, guest PC 0x0c056a42 */
if(!s->budget--) { s->failed_pc=0x0c056a42u; return 0; }
r[0]=0xffffffffu;
goto P_0c056a44;
P_0c056a44: /* original f3fd, guest PC 0x0c056a44 */
if(!s->budget--) { s->failed_pc=0x0c056a44u; return 0; }
r[18]^=0x100000u;
goto P_0c056a46;
P_0c056a46: /* original 2c02, guest PC 0x0c056a46 */
if(!s->budget--) { s->failed_pc=0x0c056a46u; return 0; }
write(ram,r[12],r[0],4);
goto P_0c056a48;
P_0c056a48: /* original 0c83, guest PC 0x0c056a48 */
if(!s->budget--) { s->failed_pc=0x0c056a48u; return 0; }
goto P_0c056a4a;
P_0c056a4a: /* original af74, guest PC 0x0c056a4a */
if(!s->budget--) { s->failed_pc=0x0c056a4au; return 0; }
r[12]+=0x00000020u;
goto P_0c056936;
P_0c056a4c: /* original 7c20, guest PC 0x0c056a4c */
if(!s->budget--) { s->failed_pc=0x0c056a4cu; return 0; }
r[12]+=0x00000020u;
return vf3_matrix_family(0x0c056a4eu,s,ram);
P_0c056a54: /* original 2668, guest PC 0x0c056a54 */
if(!s->budget--) { s->failed_pc=0x0c056a54u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c056a56;
P_0c056a56: /* original 8d04, guest PC 0x0c056a56 */
if(!s->budget--) { s->failed_pc=0x0c056a56u; return 0; }
cond=r[17]&1u;
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
if(cond) { goto P_0c056a62; }
goto P_0c056a5a;
P_0c056a58: /* original 4b10, guest PC 0x0c056a58 */
if(!s->budget--) { s->failed_pc=0x0c056a58u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c056a5a;
P_0c056a5a: /* original e0ff, guest PC 0x0c056a5a */
if(!s->budget--) { s->failed_pc=0x0c056a5au; return 0; }
r[0]=0xffffffffu;
goto P_0c056a5c;
P_0c056a5c: /* original 2c02, guest PC 0x0c056a5c */
if(!s->budget--) { s->failed_pc=0x0c056a5cu; return 0; }
write(ram,r[12],r[0],4);
goto P_0c056a5e;
P_0c056a5e: /* original 0c83, guest PC 0x0c056a5e */
if(!s->budget--) { s->failed_pc=0x0c056a5eu; return 0; }
goto P_0c056a60;
P_0c056a60: /* original 7c20, guest PC 0x0c056a60 */
if(!s->budget--) { s->failed_pc=0x0c056a60u; return 0; }
r[12]+=0x00000020u;
goto P_0c056a62;
P_0c056a62: /* original 8900, guest PC 0x0c056a62 */
if(!s->budget--) { s->failed_pc=0x0c056a62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c056a66; }
goto P_0c056a64;
P_0c056a64: /* original af3c, guest PC 0x0c056a64 */
if(!s->budget--) { s->failed_pc=0x0c056a64u; return 0; }
goto P_0c0568e0;
P_0c056a66: /* original 0009, guest PC 0x0c056a66 */
if(!s->budget--) { s->failed_pc=0x0c056a66u; return 0; }
return vf3_matrix_family(0x0c056a68u,s,ram);
P_0c064246: /* original 4f22, guest PC 0x0c064246 */
if(!s->budget--) { s->failed_pc=0x0c064246u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064248;
P_0c064248: /* original dc26, guest PC 0x0c064248 */
if(!s->budget--) { s->failed_pc=0x0c064248u; return 0; }
r[12]=read(ram,0x0c0642e4u,4);
goto P_0c06424a;
P_0c06424a: /* original 6dc2, guest PC 0x0c06424a */
if(!s->budget--) { s->failed_pc=0x0c06424au; return 0; }
tmp=read(ram,r[12],4);
r[13]=tmp;
goto P_0c06424c;
P_0c06424c: /* original e908, guest PC 0x0c06424c */
if(!s->budget--) { s->failed_pc=0x0c06424cu; return 0; }
r[9]=0x00000008u;
goto P_0c06424e;
P_0c06424e: /* original 63d3, guest PC 0x0c06424e */
if(!s->budget--) { s->failed_pc=0x0c06424eu; return 0; }
r[3]=r[13];
goto P_0c064250;
P_0c064250: /* original de25, guest PC 0x0c064250 */
if(!s->budget--) { s->failed_pc=0x0c064250u; return 0; }
r[14]=read(ram,0x0c0642e8u,4);
goto P_0c064252;
P_0c064252: /* original 2398, guest PC 0x0c064252 */
if(!s->budget--) { s->failed_pc=0x0c064252u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c064254;
P_0c064254: /* original 8906, guest PC 0x0c064254 */
if(!s->budget--) { s->failed_pc=0x0c064254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064264; }
goto P_0c064256;
P_0c064256: /* original bd62, guest PC 0x0c064256 */
if(!s->budget--) { s->failed_pc=0x0c064256u; return 0; }
target=0x0c063d1eu; r[16]=0x0c06425au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06425au) { target=s->pc; goto dispatch; }
goto P_0c06425a;
P_0c064258: /* original 0009, guest PC 0x0c064258 */
if(!s->budget--) { s->failed_pc=0x0c064258u; return 0; }
goto P_0c06425a;
P_0c06425a: /* original 6403, guest PC 0x0c06425a */
if(!s->budget--) { s->failed_pc=0x0c06425au; return 0; }
r[4]=r[0];
goto P_0c06425c;
P_0c06425c: /* original 2448, guest PC 0x0c06425c */
if(!s->budget--) { s->failed_pc=0x0c06425cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06425e;
P_0c06425e: /* original 8901, guest PC 0x0c06425e */
if(!s->budget--) { s->failed_pc=0x0c06425eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064264; }
goto P_0c064260;
P_0c064260: /* original 4e0b, guest PC 0x0c064260 */
if(!s->budget--) { s->failed_pc=0x0c064260u; return 0; }
target=r[14];
r[16]=0x0c064264u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064264u) { target=s->pc; goto dispatch; }
goto P_0c064264;
P_0c064262: /* original 0009, guest PC 0x0c064262 */
if(!s->budget--) { s->failed_pc=0x0c064262u; return 0; }
goto P_0c064264;
P_0c064264: /* original e420, guest PC 0x0c064264 */
if(!s->budget--) { s->failed_pc=0x0c064264u; return 0; }
r[4]=0x00000020u;
goto P_0c064266;
P_0c064266: /* original 62d3, guest PC 0x0c064266 */
if(!s->budget--) { s->failed_pc=0x0c064266u; return 0; }
r[2]=r[13];
goto P_0c064268;
P_0c064268: /* original 2248, guest PC 0x0c064268 */
if(!s->budget--) { s->failed_pc=0x0c064268u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c06426a;
P_0c06426a: /* original 8d05, guest PC 0x0c06426a */
if(!s->budget--) { s->failed_pc=0x0c06426au; return 0; }
cond=r[17]&1u;
r[10]=0x00000004u;
if(cond) { goto P_0c064278; }
goto P_0c06426e;
P_0c06426c: /* original ea04, guest PC 0x0c06426c */
if(!s->budget--) { s->failed_pc=0x0c06426cu; return 0; }
r[10]=0x00000004u;
goto P_0c06426e;
P_0c06426e: /* original 2c42, guest PC 0x0c06426e */
if(!s->budget--) { s->failed_pc=0x0c06426eu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c064270;
P_0c064270: /* original d31b, guest PC 0x0c064270 */
if(!s->budget--) { s->failed_pc=0x0c064270u; return 0; }
r[3]=read(ram,0x0c0642e0u,4);
goto P_0c064272;
P_0c064272: /* original 6232, guest PC 0x0c064272 */
if(!s->budget--) { s->failed_pc=0x0c064272u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c064274;
P_0c064274: /* original 22ab, guest PC 0x0c064274 */
if(!s->budget--) { s->failed_pc=0x0c064274u; return 0; }
r[2]|=r[10];
goto P_0c064276;
P_0c064276: /* original 2322, guest PC 0x0c064276 */
if(!s->budget--) { s->failed_pc=0x0c064276u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c064278;
P_0c064278: /* original 63d3, guest PC 0x0c064278 */
if(!s->budget--) { s->failed_pc=0x0c064278u; return 0; }
r[3]=r[13];
goto P_0c06427a;
P_0c06427a: /* original 23a8, guest PC 0x0c06427a */
if(!s->budget--) { s->failed_pc=0x0c06427au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c06427c;
P_0c06427c: /* original 8d57, guest PC 0x0c06427c */
if(!s->budget--) { s->failed_pc=0x0c06427cu; return 0; }
cond=r[17]&1u;
r[11]=0x00000001u;
if(cond) { goto P_0c06432e; }
goto P_0c064280;
P_0c06427e: /* original eb01, guest PC 0x0c06427e */
if(!s->budget--) { s->failed_pc=0x0c06427eu; return 0; }
r[11]=0x00000001u;
goto P_0c064280;
P_0c064280: /* original e107, guest PC 0x0c064280 */
if(!s->budget--) { s->failed_pc=0x0c064280u; return 0; }
r[1]=0x00000007u;
goto P_0c064282;
P_0c064282: /* original 2c12, guest PC 0x0c064282 */
if(!s->budget--) { s->failed_pc=0x0c064282u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c064284;
P_0c064284: /* original d319, guest PC 0x0c064284 */
if(!s->budget--) { s->failed_pc=0x0c064284u; return 0; }
r[3]=read(ram,0x0c0642ecu,4);
goto P_0c064286;
P_0c064286: /* original e400, guest PC 0x0c064286 */
if(!s->budget--) { s->failed_pc=0x0c064286u; return 0; }
r[4]=0x00000000u;
goto P_0c064288;
P_0c064288: /* original 2342, guest PC 0x0c064288 */
if(!s->budget--) { s->failed_pc=0x0c064288u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06428a;
P_0c06428a: /* original d511, guest PC 0x0c06428a */
if(!s->budget--) { s->failed_pc=0x0c06428au; return 0; }
r[5]=read(ram,0x0c0642d0u,4);
goto P_0c06428c;
P_0c06428c: /* original d018, guest PC 0x0c06428c */
if(!s->budget--) { s->failed_pc=0x0c06428cu; return 0; }
r[0]=read(ram,0x0c0642f0u,4);
goto P_0c06428e;
P_0c06428e: /* original 2542, guest PC 0x0c06428e */
if(!s->budget--) { s->failed_pc=0x0c06428eu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c064290;
P_0c064290: /* original 6202, guest PC 0x0c064290 */
if(!s->budget--) { s->failed_pc=0x0c064290u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c064292;
P_0c064292: /* original e040, guest PC 0x0c064292 */
if(!s->budget--) { s->failed_pc=0x0c064292u; return 0; }
r[0]=0x00000040u;
goto P_0c064294;
P_0c064294: /* original 015e, guest PC 0x0c064294 */
if(!s->budget--) { s->failed_pc=0x0c064294u; return 0; }
r[1]=read(ram,r[5]+r[0],4);
goto P_0c064296;
P_0c064296: /* original e044, guest PC 0x0c064296 */
if(!s->budget--) { s->failed_pc=0x0c064296u; return 0; }
r[0]=0x00000044u;
goto P_0c064298;
P_0c064298: /* original 3128, guest PC 0x0c064298 */
if(!s->budget--) { s->failed_pc=0x0c064298u; return 0; }
r[1]-=r[2];
goto P_0c06429a;
P_0c06429a: /* original 0516, guest PC 0x0c06429a */
if(!s->budget--) { s->failed_pc=0x0c06429au; return 0; }
write(ram,r[5]+r[0],r[1],4);
goto P_0c06429c;
P_0c06429c: /* original d115, guest PC 0x0c06429c */
if(!s->budget--) { s->failed_pc=0x0c06429cu; return 0; }
r[1]=read(ram,0x0c0642f4u,4);
goto P_0c06429e;
P_0c06429e: /* original 6212, guest PC 0x0c06429e */
if(!s->budget--) { s->failed_pc=0x0c06429eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0642a0;
P_0c0642a0: /* original 2228, guest PC 0x0c0642a0 */
if(!s->budget--) { s->failed_pc=0x0c0642a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0642a2;
P_0c0642a2: /* original 8937, guest PC 0x0c0642a2 */
if(!s->budget--) { s->failed_pc=0x0c0642a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064314; }
goto P_0c0642a4;
P_0c0642a4: /* original d313, guest PC 0x0c0642a4 */
if(!s->budget--) { s->failed_pc=0x0c0642a4u; return 0; }
r[3]=read(ram,0x0c0642f4u,4);
goto P_0c0642a6;
P_0c0642a6: /* original 2342, guest PC 0x0c0642a6 */
if(!s->budget--) { s->failed_pc=0x0c0642a6u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0642a8;
P_0c0642a8: /* original 1546, guest PC 0x0c0642a8 */
if(!s->budget--) { s->failed_pc=0x0c0642a8u; return 0; }
write(ram,r[5]+24,r[4],4);
goto P_0c0642aa;
P_0c0642aa: /* original d013, guest PC 0x0c0642aa */
if(!s->budget--) { s->failed_pc=0x0c0642aau; return 0; }
r[0]=read(ram,0x0c0642f8u,4);
goto P_0c0642ac;
P_0c0642ac: /* original 6202, guest PC 0x0c0642ac */
if(!s->budget--) { s->failed_pc=0x0c0642acu; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c0642ae;
P_0c0642ae: /* original d113, guest PC 0x0c0642ae */
if(!s->budget--) { s->failed_pc=0x0c0642aeu; return 0; }
r[1]=read(ram,0x0c0642fcu,4);
goto P_0c0642b0;
P_0c0642b0: /* original 2122, guest PC 0x0c0642b0 */
if(!s->budget--) { s->failed_pc=0x0c0642b0u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0642b2;
P_0c0642b2: /* original d213, guest PC 0x0c0642b2 */
if(!s->budget--) { s->failed_pc=0x0c0642b2u; return 0; }
r[2]=read(ram,0x0c064300u,4);
goto P_0c0642b4;
P_0c0642b4: /* original 6322, guest PC 0x0c0642b4 */
if(!s->budget--) { s->failed_pc=0x0c0642b4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0642b6;
P_0c0642b6: /* original 7104, guest PC 0x0c0642b6 */
if(!s->budget--) { s->failed_pc=0x0c0642b6u; return 0; }
r[1]+=0x00000004u;
goto P_0c0642b8;
P_0c0642b8: /* original 2132, guest PC 0x0c0642b8 */
if(!s->budget--) { s->failed_pc=0x0c0642b8u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0642ba;
P_0c0642ba: /* original d312, guest PC 0x0c0642ba */
if(!s->budget--) { s->failed_pc=0x0c0642bau; return 0; }
r[3]=read(ram,0x0c064304u,4);
goto P_0c0642bc;
P_0c0642bc: /* original 6032, guest PC 0x0c0642bc */
if(!s->budget--) { s->failed_pc=0x0c0642bcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0642be;
P_0c0642be: /* original d212, guest PC 0x0c0642be */
if(!s->budget--) { s->failed_pc=0x0c0642beu; return 0; }
r[2]=read(ram,0x0c064308u,4);
goto P_0c0642c0;
P_0c0642c0: /* original 2202, guest PC 0x0c0642c0 */
if(!s->budget--) { s->failed_pc=0x0c0642c0u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0642c2;
P_0c0642c2: /* original d012, guest PC 0x0c0642c2 */
if(!s->budget--) { s->failed_pc=0x0c0642c2u; return 0; }
r[0]=read(ram,0x0c06430cu,4);
goto P_0c0642c4;
P_0c0642c4: /* original 6102, guest PC 0x0c0642c4 */
if(!s->budget--) { s->failed_pc=0x0c0642c4u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0642c6;
P_0c0642c6: /* original d312, guest PC 0x0c0642c6 */
if(!s->budget--) { s->failed_pc=0x0c0642c6u; return 0; }
r[3]=read(ram,0x0c064310u,4);
goto P_0c0642c8;
P_0c0642c8: /* original a02b, guest PC 0x0c0642c8 */
if(!s->budget--) { s->failed_pc=0x0c0642c8u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c064322;
P_0c0642ca: /* original 2312, guest PC 0x0c0642ca */
if(!s->budget--) { s->failed_pc=0x0c0642cau; return 0; }
write(ram,r[3],r[1],4);
return vf3_matrix_family(0x0c0642ccu,s,ram);
P_0c064314: /* original d043, guest PC 0x0c064314 */
if(!s->budget--) { s->failed_pc=0x0c064314u; return 0; }
r[0]=read(ram,0x0c064424u,4);
goto P_0c064316;
P_0c064316: /* original e105, guest PC 0x0c064316 */
if(!s->budget--) { s->failed_pc=0x0c064316u; return 0; }
r[1]=0x00000005u;
goto P_0c064318;
P_0c064318: /* original 6203, guest PC 0x0c064318 */
if(!s->budget--) { s->failed_pc=0x0c064318u; return 0; }
r[2]=r[0];
goto P_0c06431a;
P_0c06431a: /* original 7214, guest PC 0x0c06431a */
if(!s->budget--) { s->failed_pc=0x0c06431au; return 0; }
r[2]+=0x00000014u;
goto P_0c06431c;
P_0c06431c: /* original 6322, guest PC 0x0c06431c */
if(!s->budget--) { s->failed_pc=0x0c06431cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c06431e;
P_0c06431e: /* original 4308, guest PC 0x0c06431e */
if(!s->budget--) { s->failed_pc=0x0c06431eu; return 0; }
r[3]<<=2;
goto P_0c064320;
P_0c064320: /* original 0316, guest PC 0x0c064320 */
if(!s->budget--) { s->failed_pc=0x0c064320u; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c064322;
P_0c064322: /* original d341, guest PC 0x0c064322 */
if(!s->budget--) { s->failed_pc=0x0c064322u; return 0; }
r[3]=read(ram,0x0c064428u,4);
goto P_0c064324;
P_0c064324: /* original 6232, guest PC 0x0c064324 */
if(!s->budget--) { s->failed_pc=0x0c064324u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c064326;
P_0c064326: /* original 22bb, guest PC 0x0c064326 */
if(!s->budget--) { s->failed_pc=0x0c064326u; return 0; }
r[2]|=r[11];
goto P_0c064328;
P_0c064328: /* original 2322, guest PC 0x0c064328 */
if(!s->budget--) { s->failed_pc=0x0c064328u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c06432a;
P_0c06432a: /* original d340, guest PC 0x0c06432a */
if(!s->budget--) { s->failed_pc=0x0c06432au; return 0; }
r[3]=read(ram,0x0c06442cu,4);
goto P_0c06432c;
P_0c06432c: /* original 2342, guest PC 0x0c06432c */
if(!s->budget--) { s->failed_pc=0x0c06432cu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06432e;
P_0c06432e: /* original 63d3, guest PC 0x0c06432e */
if(!s->budget--) { s->failed_pc=0x0c06432eu; return 0; }
r[3]=r[13];
goto P_0c064330;
P_0c064330: /* original d53f, guest PC 0x0c064330 */
if(!s->budget--) { s->failed_pc=0x0c064330u; return 0; }
r[5]=read(ram,0x0c064430u,4);
goto P_0c064332;
P_0c064332: /* original 2358, guest PC 0x0c064332 */
if(!s->budget--) { s->failed_pc=0x0c064332u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c064334;
P_0c064334: /* original 8907, guest PC 0x0c064334 */
if(!s->budget--) { s->failed_pc=0x0c064334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064346; }
goto P_0c064336;
P_0c064336: /* original e3fc, guest PC 0x0c064336 */
if(!s->budget--) { s->failed_pc=0x0c064336u; return 0; }
r[3]=0xfffffffcu;
goto P_0c064338;
P_0c064338: /* original d63e, guest PC 0x0c064338 */
if(!s->budget--) { s->failed_pc=0x0c064338u; return 0; }
r[6]=read(ram,0x0c064434u,4);
goto P_0c06433a;
P_0c06433a: /* original 6462, guest PC 0x0c06433a */
if(!s->budget--) { s->failed_pc=0x0c06433au; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c06433c;
P_0c06433c: /* original 2439, guest PC 0x0c06433c */
if(!s->budget--) { s->failed_pc=0x0c06433cu; return 0; }
r[4]&=r[3];
goto P_0c06433e;
P_0c06433e: /* original 2642, guest PC 0x0c06433e */
if(!s->budget--) { s->failed_pc=0x0c06433eu; return 0; }
write(ram,r[6],r[4],4);
goto P_0c064340;
P_0c064340: /* original d23d, guest PC 0x0c064340 */
if(!s->budget--) { s->failed_pc=0x0c064340u; return 0; }
r[2]=read(ram,0x0c064438u,4);
goto P_0c064342;
P_0c064342: /* original 420b, guest PC 0x0c064342 */
if(!s->budget--) { s->failed_pc=0x0c064342u; return 0; }
target=r[2];
r[16]=0x0c064346u;
write(ram,r[12],r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064346u) { target=s->pc; goto dispatch; }
goto P_0c064346;
P_0c064344: /* original 2c52, guest PC 0x0c064344 */
if(!s->budget--) { s->failed_pc=0x0c064344u; return 0; }
write(ram,r[12],r[5],4);
goto P_0c064346;
P_0c064346: /* original e440, guest PC 0x0c064346 */
if(!s->budget--) { s->failed_pc=0x0c064346u; return 0; }
r[4]=0x00000040u;
goto P_0c064348;
P_0c064348: /* original 63d3, guest PC 0x0c064348 */
if(!s->budget--) { s->failed_pc=0x0c064348u; return 0; }
r[3]=r[13];
goto P_0c06434a;
P_0c06434a: /* original 2348, guest PC 0x0c06434a */
if(!s->budget--) { s->failed_pc=0x0c06434au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06434c;
P_0c06434c: /* original 8904, guest PC 0x0c06434c */
if(!s->budget--) { s->failed_pc=0x0c06434cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064358; }
goto P_0c06434e;
P_0c06434e: /* original 2c42, guest PC 0x0c06434e */
if(!s->budget--) { s->failed_pc=0x0c06434eu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c064350;
P_0c064350: /* original d335, guest PC 0x0c064350 */
if(!s->budget--) { s->failed_pc=0x0c064350u; return 0; }
r[3]=read(ram,0x0c064428u,4);
goto P_0c064352;
P_0c064352: /* original 6232, guest PC 0x0c064352 */
if(!s->budget--) { s->failed_pc=0x0c064352u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c064354;
P_0c064354: /* original 224b, guest PC 0x0c064354 */
if(!s->budget--) { s->failed_pc=0x0c064354u; return 0; }
r[2]|=r[4];
goto P_0c064356;
P_0c064356: /* original 2322, guest PC 0x0c064356 */
if(!s->budget--) { s->failed_pc=0x0c064356u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c064358;
P_0c064358: /* original 945f, guest PC 0x0c064358 */
if(!s->budget--) { s->failed_pc=0x0c064358u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06441au,2);
goto P_0c06435a;
P_0c06435a: /* original 63d3, guest PC 0x0c06435a */
if(!s->budget--) { s->failed_pc=0x0c06435au; return 0; }
r[3]=r[13];
goto P_0c06435c;
P_0c06435c: /* original 2348, guest PC 0x0c06435c */
if(!s->budget--) { s->failed_pc=0x0c06435cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06435e;
P_0c06435e: /* original 890d, guest PC 0x0c06435e */
if(!s->budget--) { s->failed_pc=0x0c06435eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06437c; }
goto P_0c064360;
P_0c064360: /* original 2c42, guest PC 0x0c064360 */
if(!s->budget--) { s->failed_pc=0x0c064360u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c064362;
P_0c064362: /* original d336, guest PC 0x0c064362 */
if(!s->budget--) { s->failed_pc=0x0c064362u; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c064364;
P_0c064364: /* original 6232, guest PC 0x0c064364 */
if(!s->budget--) { s->failed_pc=0x0c064364u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c064366;
P_0c064366: /* original 22bb, guest PC 0x0c064366 */
if(!s->budget--) { s->failed_pc=0x0c064366u; return 0; }
r[2]|=r[11];
goto P_0c064368;
P_0c064368: /* original 2322, guest PC 0x0c064368 */
if(!s->budget--) { s->failed_pc=0x0c064368u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c06436a;
P_0c06436a: /* original 6033, guest PC 0x0c06436a */
if(!s->budget--) { s->failed_pc=0x0c06436au; return 0; }
r[0]=r[3];
goto P_0c06436c;
P_0c06436c: /* original 0009, guest PC 0x0c06436c */
if(!s->budget--) { s->failed_pc=0x0c06436cu; return 0; }
goto P_0c06436e;
P_0c06436e: /* original 6302, guest PC 0x0c06436e */
if(!s->budget--) { s->failed_pc=0x0c06436eu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c064370;
P_0c064370: /* original d233, guest PC 0x0c064370 */
if(!s->budget--) { s->failed_pc=0x0c064370u; return 0; }
r[2]=read(ram,0x0c064440u,4);
goto P_0c064372;
P_0c064372: /* original 6122, guest PC 0x0c064372 */
if(!s->budget--) { s->failed_pc=0x0c064372u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c064374;
P_0c064374: /* original 3130, guest PC 0x0c064374 */
if(!s->budget--) { s->failed_pc=0x0c064374u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c064376;
P_0c064376: /* original 8b01, guest PC 0x0c064376 */
if(!s->budget--) { s->failed_pc=0x0c064376u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06437c; }
goto P_0c064378;
P_0c064378: /* original be05, guest PC 0x0c064378 */
if(!s->budget--) { s->failed_pc=0x0c064378u; return 0; }
target=0x0c063f86u; r[16]=0x0c06437cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06437cu) { target=s->pc; goto dispatch; }
goto P_0c06437c;
P_0c06437a: /* original 0009, guest PC 0x0c06437a */
if(!s->budget--) { s->failed_pc=0x0c06437au; return 0; }
goto P_0c06437c;
P_0c06437c: /* original 944e, guest PC 0x0c06437c */
if(!s->budget--) { s->failed_pc=0x0c06437cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06441cu,2);
goto P_0c06437e;
P_0c06437e: /* original 63d3, guest PC 0x0c06437e */
if(!s->budget--) { s->failed_pc=0x0c06437eu; return 0; }
r[3]=r[13];
goto P_0c064380;
P_0c064380: /* original 2348, guest PC 0x0c064380 */
if(!s->budget--) { s->failed_pc=0x0c064380u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c064382;
P_0c064382: /* original 890c, guest PC 0x0c064382 */
if(!s->budget--) { s->failed_pc=0x0c064382u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06439e; }
goto P_0c064384;
P_0c064384: /* original 2c42, guest PC 0x0c064384 */
if(!s->budget--) { s->failed_pc=0x0c064384u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c064386;
P_0c064386: /* original d32d, guest PC 0x0c064386 */
if(!s->budget--) { s->failed_pc=0x0c064386u; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c064388;
P_0c064388: /* original 6032, guest PC 0x0c064388 */
if(!s->budget--) { s->failed_pc=0x0c064388u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06438a;
P_0c06438a: /* original cb02, guest PC 0x0c06438a */
if(!s->budget--) { s->failed_pc=0x0c06438au; return 0; }
r[0]|=2u;
goto P_0c06438c;
P_0c06438c: /* original 2302, guest PC 0x0c06438c */
if(!s->budget--) { s->failed_pc=0x0c06438cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c06438e;
P_0c06438e: /* original 6133, guest PC 0x0c06438e */
if(!s->budget--) { s->failed_pc=0x0c06438eu; return 0; }
r[1]=r[3];
goto P_0c064390;
P_0c064390: /* original 6212, guest PC 0x0c064390 */
if(!s->budget--) { s->failed_pc=0x0c064390u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c064392;
P_0c064392: /* original d02b, guest PC 0x0c064392 */
if(!s->budget--) { s->failed_pc=0x0c064392u; return 0; }
r[0]=read(ram,0x0c064440u,4);
goto P_0c064394;
P_0c064394: /* original 6302, guest PC 0x0c064394 */
if(!s->budget--) { s->failed_pc=0x0c064394u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c064396;
P_0c064396: /* original 3320, guest PC 0x0c064396 */
if(!s->budget--) { s->failed_pc=0x0c064396u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c064398;
P_0c064398: /* original 8b01, guest PC 0x0c064398 */
if(!s->budget--) { s->failed_pc=0x0c064398u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06439e; }
goto P_0c06439a;
P_0c06439a: /* original bdf4, guest PC 0x0c06439a */
if(!s->budget--) { s->failed_pc=0x0c06439au; return 0; }
target=0x0c063f86u; r[16]=0x0c06439eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06439eu) { target=s->pc; goto dispatch; }
goto P_0c06439e;
P_0c06439c: /* original 0009, guest PC 0x0c06439c */
if(!s->budget--) { s->failed_pc=0x0c06439cu; return 0; }
goto P_0c06439e;
P_0c06439e: /* original 63d3, guest PC 0x0c06439e */
if(!s->budget--) { s->failed_pc=0x0c06439eu; return 0; }
r[3]=r[13];
goto P_0c0643a0;
P_0c0643a0: /* original 943d, guest PC 0x0c0643a0 */
if(!s->budget--) { s->failed_pc=0x0c0643a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06441eu,2);
goto P_0c0643a2;
P_0c0643a2: /* original 2348, guest PC 0x0c0643a2 */
if(!s->budget--) { s->failed_pc=0x0c0643a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0643a4;
P_0c0643a4: /* original 890d, guest PC 0x0c0643a4 */
if(!s->budget--) { s->failed_pc=0x0c0643a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0643c2; }
goto P_0c0643a6;
P_0c0643a6: /* original 2c42, guest PC 0x0c0643a6 */
if(!s->budget--) { s->failed_pc=0x0c0643a6u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c0643a8;
P_0c0643a8: /* original d324, guest PC 0x0c0643a8 */
if(!s->budget--) { s->failed_pc=0x0c0643a8u; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c0643aa;
P_0c0643aa: /* original 6232, guest PC 0x0c0643aa */
if(!s->budget--) { s->failed_pc=0x0c0643aau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0643ac;
P_0c0643ac: /* original 22ab, guest PC 0x0c0643ac */
if(!s->budget--) { s->failed_pc=0x0c0643acu; return 0; }
r[2]|=r[10];
goto P_0c0643ae;
P_0c0643ae: /* original 2322, guest PC 0x0c0643ae */
if(!s->budget--) { s->failed_pc=0x0c0643aeu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0643b0;
P_0c0643b0: /* original 6033, guest PC 0x0c0643b0 */
if(!s->budget--) { s->failed_pc=0x0c0643b0u; return 0; }
r[0]=r[3];
goto P_0c0643b2;
P_0c0643b2: /* original 0009, guest PC 0x0c0643b2 */
if(!s->budget--) { s->failed_pc=0x0c0643b2u; return 0; }
goto P_0c0643b4;
P_0c0643b4: /* original 6302, guest PC 0x0c0643b4 */
if(!s->budget--) { s->failed_pc=0x0c0643b4u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0643b6;
P_0c0643b6: /* original d222, guest PC 0x0c0643b6 */
if(!s->budget--) { s->failed_pc=0x0c0643b6u; return 0; }
r[2]=read(ram,0x0c064440u,4);
goto P_0c0643b8;
P_0c0643b8: /* original 6122, guest PC 0x0c0643b8 */
if(!s->budget--) { s->failed_pc=0x0c0643b8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0643ba;
P_0c0643ba: /* original 3130, guest PC 0x0c0643ba */
if(!s->budget--) { s->failed_pc=0x0c0643bau; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0643bc;
P_0c0643bc: /* original 8b01, guest PC 0x0c0643bc */
if(!s->budget--) { s->failed_pc=0x0c0643bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0643c2; }
goto P_0c0643be;
P_0c0643be: /* original bde2, guest PC 0x0c0643be */
if(!s->budget--) { s->failed_pc=0x0c0643beu; return 0; }
target=0x0c063f86u; r[16]=0x0c0643c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0643c2u) { target=s->pc; goto dispatch; }
goto P_0c0643c2;
P_0c0643c0: /* original 0009, guest PC 0x0c0643c0 */
if(!s->budget--) { s->failed_pc=0x0c0643c0u; return 0; }
goto P_0c0643c2;
P_0c0643c2: /* original 63d3, guest PC 0x0c0643c2 */
if(!s->budget--) { s->failed_pc=0x0c0643c2u; return 0; }
r[3]=r[13];
goto P_0c0643c4;
P_0c0643c4: /* original 942c, guest PC 0x0c0643c4 */
if(!s->budget--) { s->failed_pc=0x0c0643c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c064420u,2);
goto P_0c0643c6;
P_0c0643c6: /* original 2348, guest PC 0x0c0643c6 */
if(!s->budget--) { s->failed_pc=0x0c0643c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0643c8;
P_0c0643c8: /* original 890d, guest PC 0x0c0643c8 */
if(!s->budget--) { s->failed_pc=0x0c0643c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0643e6; }
goto P_0c0643ca;
P_0c0643ca: /* original 2c42, guest PC 0x0c0643ca */
if(!s->budget--) { s->failed_pc=0x0c0643cau; return 0; }
write(ram,r[12],r[4],4);
goto P_0c0643cc;
P_0c0643cc: /* original d31b, guest PC 0x0c0643cc */
if(!s->budget--) { s->failed_pc=0x0c0643ccu; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c0643ce;
P_0c0643ce: /* original 6232, guest PC 0x0c0643ce */
if(!s->budget--) { s->failed_pc=0x0c0643ceu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0643d0;
P_0c0643d0: /* original 229b, guest PC 0x0c0643d0 */
if(!s->budget--) { s->failed_pc=0x0c0643d0u; return 0; }
r[2]|=r[9];
goto P_0c0643d2;
P_0c0643d2: /* original 2322, guest PC 0x0c0643d2 */
if(!s->budget--) { s->failed_pc=0x0c0643d2u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0643d4;
P_0c0643d4: /* original 6033, guest PC 0x0c0643d4 */
if(!s->budget--) { s->failed_pc=0x0c0643d4u; return 0; }
r[0]=r[3];
goto P_0c0643d6;
P_0c0643d6: /* original 0009, guest PC 0x0c0643d6 */
if(!s->budget--) { s->failed_pc=0x0c0643d6u; return 0; }
goto P_0c0643d8;
P_0c0643d8: /* original 6302, guest PC 0x0c0643d8 */
if(!s->budget--) { s->failed_pc=0x0c0643d8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0643da;
P_0c0643da: /* original d219, guest PC 0x0c0643da */
if(!s->budget--) { s->failed_pc=0x0c0643dau; return 0; }
r[2]=read(ram,0x0c064440u,4);
goto P_0c0643dc;
P_0c0643dc: /* original 6122, guest PC 0x0c0643dc */
if(!s->budget--) { s->failed_pc=0x0c0643dcu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0643de;
P_0c0643de: /* original 3130, guest PC 0x0c0643de */
if(!s->budget--) { s->failed_pc=0x0c0643deu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0643e0;
P_0c0643e0: /* original 8b01, guest PC 0x0c0643e0 */
if(!s->budget--) { s->failed_pc=0x0c0643e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0643e6; }
goto P_0c0643e2;
P_0c0643e2: /* original bdd0, guest PC 0x0c0643e2 */
if(!s->budget--) { s->failed_pc=0x0c0643e2u; return 0; }
target=0x0c063f86u; r[16]=0x0c0643e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0643e6u) { target=s->pc; goto dispatch; }
goto P_0c0643e6;
P_0c0643e4: /* original 0009, guest PC 0x0c0643e4 */
if(!s->budget--) { s->failed_pc=0x0c0643e4u; return 0; }
goto P_0c0643e6;
P_0c0643e6: /* original d417, guest PC 0x0c0643e6 */
if(!s->budget--) { s->failed_pc=0x0c0643e6u; return 0; }
r[4]=read(ram,0x0c064444u,4);
goto P_0c0643e8;
P_0c0643e8: /* original 2d48, guest PC 0x0c0643e8 */
if(!s->budget--) { s->failed_pc=0x0c0643e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[4])==0)!=0);
goto P_0c0643ea;
P_0c0643ea: /* original 890c, guest PC 0x0c0643ea */
if(!s->budget--) { s->failed_pc=0x0c0643eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064406; }
goto P_0c0643ec;
P_0c0643ec: /* original 2c42, guest PC 0x0c0643ec */
if(!s->budget--) { s->failed_pc=0x0c0643ecu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c0643ee;
P_0c0643ee: /* original d313, guest PC 0x0c0643ee */
if(!s->budget--) { s->failed_pc=0x0c0643eeu; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c0643f0;
P_0c0643f0: /* original 6032, guest PC 0x0c0643f0 */
if(!s->budget--) { s->failed_pc=0x0c0643f0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0643f2;
P_0c0643f2: /* original cb10, guest PC 0x0c0643f2 */
if(!s->budget--) { s->failed_pc=0x0c0643f2u; return 0; }
r[0]|=16u;
goto P_0c0643f4;
P_0c0643f4: /* original 2302, guest PC 0x0c0643f4 */
if(!s->budget--) { s->failed_pc=0x0c0643f4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0643f6;
P_0c0643f6: /* original 6133, guest PC 0x0c0643f6 */
if(!s->budget--) { s->failed_pc=0x0c0643f6u; return 0; }
r[1]=r[3];
goto P_0c0643f8;
P_0c0643f8: /* original 6212, guest PC 0x0c0643f8 */
if(!s->budget--) { s->failed_pc=0x0c0643f8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0643fa;
P_0c0643fa: /* original d011, guest PC 0x0c0643fa */
if(!s->budget--) { s->failed_pc=0x0c0643fau; return 0; }
r[0]=read(ram,0x0c064440u,4);
goto P_0c0643fc;
P_0c0643fc: /* original 6302, guest PC 0x0c0643fc */
if(!s->budget--) { s->failed_pc=0x0c0643fcu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0643fe;
P_0c0643fe: /* original 3320, guest PC 0x0c0643fe */
if(!s->budget--) { s->failed_pc=0x0c0643feu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c064400;
P_0c064400: /* original 8b01, guest PC 0x0c064400 */
if(!s->budget--) { s->failed_pc=0x0c064400u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064406; }
goto P_0c064402;
P_0c064402: /* original bdc0, guest PC 0x0c064402 */
if(!s->budget--) { s->failed_pc=0x0c064402u; return 0; }
target=0x0c063f86u; r[16]=0x0c064406u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064406u) { target=s->pc; goto dispatch; }
goto P_0c064406;
P_0c064404: /* original 0009, guest PC 0x0c064404 */
if(!s->budget--) { s->failed_pc=0x0c064404u; return 0; }
goto P_0c064406;
P_0c064406: /* original d310, guest PC 0x0c064406 */
if(!s->budget--) { s->failed_pc=0x0c064406u; return 0; }
r[3]=read(ram,0x0c064448u,4);
goto P_0c064408;
P_0c064408: /* original 6d32, guest PC 0x0c064408 */
if(!s->budget--) { s->failed_pc=0x0c064408u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c06440a;
P_0c06440a: /* original 2ad8, guest PC 0x0c06440a */
if(!s->budget--) { s->failed_pc=0x0c06440au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[13])==0)!=0);
goto P_0c06440c;
P_0c06440c: /* original 8921, guest PC 0x0c06440c */
if(!s->budget--) { s->failed_pc=0x0c06440cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064452; }
goto P_0c06440e;
P_0c06440e: /* original bed7, guest PC 0x0c06440e */
if(!s->budget--) { s->failed_pc=0x0c06440eu; return 0; }
target=0x0c0641c0u; r[16]=0x0c064412u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064412u) { target=s->pc; goto dispatch; }
goto P_0c064412;
P_0c064410: /* original 0009, guest PC 0x0c064410 */
if(!s->budget--) { s->failed_pc=0x0c064410u; return 0; }
goto P_0c064412;
P_0c064412: /* original 6403, guest PC 0x0c064412 */
if(!s->budget--) { s->failed_pc=0x0c064412u; return 0; }
r[4]=r[0];
goto P_0c064414;
P_0c064414: /* original 2448, guest PC 0x0c064414 */
if(!s->budget--) { s->failed_pc=0x0c064414u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c064416;
P_0c064416: /* original a019, guest PC 0x0c064416 */
if(!s->budget--) { s->failed_pc=0x0c064416u; return 0; }
goto P_0c06444c;
P_0c064418: /* original 0009, guest PC 0x0c064418 */
if(!s->budget--) { s->failed_pc=0x0c064418u; return 0; }
return vf3_matrix_family(0x0c06441au,s,ram);
P_0c06444c: /* original 8901, guest PC 0x0c06444c */
if(!s->budget--) { s->failed_pc=0x0c06444cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064452; }
goto P_0c06444e;
P_0c06444e: /* original 4e0b, guest PC 0x0c06444e */
if(!s->budget--) { s->failed_pc=0x0c06444eu; return 0; }
target=r[14];
r[16]=0x0c064452u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064452u) { target=s->pc; goto dispatch; }
goto P_0c064452;
P_0c064450: /* original 0009, guest PC 0x0c064450 */
if(!s->budget--) { s->failed_pc=0x0c064450u; return 0; }
goto P_0c064452;
P_0c064452: /* original 29d8, guest PC 0x0c064452 */
if(!s->budget--) { s->failed_pc=0x0c064452u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[13])==0)!=0);
goto P_0c064454;
P_0c064454: /* original 8906, guest PC 0x0c064454 */
if(!s->budget--) { s->failed_pc=0x0c064454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064464; }
goto P_0c064456;
P_0c064456: /* original becd, guest PC 0x0c064456 */
if(!s->budget--) { s->failed_pc=0x0c064456u; return 0; }
target=0x0c0641f4u; r[16]=0x0c06445au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06445au) { target=s->pc; goto dispatch; }
goto P_0c06445a;
P_0c064458: /* original 0009, guest PC 0x0c064458 */
if(!s->budget--) { s->failed_pc=0x0c064458u; return 0; }
goto P_0c06445a;
P_0c06445a: /* original 6403, guest PC 0x0c06445a */
if(!s->budget--) { s->failed_pc=0x0c06445au; return 0; }
r[4]=r[0];
goto P_0c06445c;
P_0c06445c: /* original 2448, guest PC 0x0c06445c */
if(!s->budget--) { s->failed_pc=0x0c06445cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06445e;
P_0c06445e: /* original 8901, guest PC 0x0c06445e */
if(!s->budget--) { s->failed_pc=0x0c06445eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064464; }
goto P_0c064460;
P_0c064460: /* original 4e0b, guest PC 0x0c064460 */
if(!s->budget--) { s->failed_pc=0x0c064460u; return 0; }
target=r[14];
r[16]=0x0c064464u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064464u) { target=s->pc; goto dispatch; }
goto P_0c064464;
P_0c064462: /* original 0009, guest PC 0x0c064462 */
if(!s->budget--) { s->failed_pc=0x0c064462u; return 0; }
goto P_0c064464;
P_0c064464: /* original e302, guest PC 0x0c064464 */
if(!s->budget--) { s->failed_pc=0x0c064464u; return 0; }
r[3]=0x00000002u;
goto P_0c064466;
P_0c064466: /* original 2d38, guest PC 0x0c064466 */
if(!s->budget--) { s->failed_pc=0x0c064466u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c064468;
P_0c064468: /* original 8906, guest PC 0x0c064468 */
if(!s->budget--) { s->failed_pc=0x0c064468u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064478; }
goto P_0c06446a;
P_0c06446a: /* original bed7, guest PC 0x0c06446a */
if(!s->budget--) { s->failed_pc=0x0c06446au; return 0; }
target=0x0c06421cu; r[16]=0x0c06446eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06446eu) { target=s->pc; goto dispatch; }
goto P_0c06446e;
P_0c06446c: /* original 0009, guest PC 0x0c06446c */
if(!s->budget--) { s->failed_pc=0x0c06446cu; return 0; }
goto P_0c06446e;
P_0c06446e: /* original 6403, guest PC 0x0c06446e */
if(!s->budget--) { s->failed_pc=0x0c06446eu; return 0; }
r[4]=r[0];
goto P_0c064470;
P_0c064470: /* original 2448, guest PC 0x0c064470 */
if(!s->budget--) { s->failed_pc=0x0c064470u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c064472;
P_0c064472: /* original 8901, guest PC 0x0c064472 */
if(!s->budget--) { s->failed_pc=0x0c064472u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064478; }
goto P_0c064474;
P_0c064474: /* original 4e0b, guest PC 0x0c064474 */
if(!s->budget--) { s->failed_pc=0x0c064474u; return 0; }
target=r[14];
r[16]=0x0c064478u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064478u) { target=s->pc; goto dispatch; }
goto P_0c064478;
P_0c064476: /* original 0009, guest PC 0x0c064476 */
if(!s->budget--) { s->failed_pc=0x0c064476u; return 0; }
goto P_0c064478;
P_0c064478: /* original da17, guest PC 0x0c064478 */
if(!s->budget--) { s->failed_pc=0x0c064478u; return 0; }
r[10]=read(ram,0x0c0644d8u,4);
goto P_0c06447a;
P_0c06447a: /* original ec09, guest PC 0x0c06447a */
if(!s->budget--) { s->failed_pc=0x0c06447au; return 0; }
r[12]=0x00000009u;
goto P_0c06447c;
P_0c06447c: /* original a013, guest PC 0x0c06447c */
if(!s->budget--) { s->failed_pc=0x0c06447cu; return 0; }
r[14]=0x00000000u;
goto P_0c0644a6;
P_0c06447e: /* original ee00, guest PC 0x0c06447e */
if(!s->budget--) { s->failed_pc=0x0c06447eu; return 0; }
r[14]=0x00000000u;
goto P_0c064480;
P_0c064480: /* original d216, guest PC 0x0c064480 */
if(!s->budget--) { s->failed_pc=0x0c064480u; return 0; }
r[2]=read(ram,0x0c0644dcu,4);
goto P_0c064482;
P_0c064482: /* original 64b3, guest PC 0x0c064482 */
if(!s->budget--) { s->failed_pc=0x0c064482u; return 0; }
r[4]=r[11];
goto P_0c064484;
P_0c064484: /* original 44ec, guest PC 0x0c064484 */
if(!s->budget--) { s->failed_pc=0x0c064484u; return 0; }
r[4]=(r[14]&0x80000000u)?((r[14]&31u)?(uint32_t)((int32_t)r[4]>>((-r[14])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[14]&31u);
goto P_0c064486;
P_0c064486: /* original 6322, guest PC 0x0c064486 */
if(!s->budget--) { s->failed_pc=0x0c064486u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c064488;
P_0c064488: /* original 2348, guest PC 0x0c064488 */
if(!s->budget--) { s->failed_pc=0x0c064488u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06448a;
P_0c06448a: /* original 890b, guest PC 0x0c06448a */
if(!s->budget--) { s->failed_pc=0x0c06448au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0644a4; }
goto P_0c06448c;
P_0c06448c: /* original 6447, guest PC 0x0c06448c */
if(!s->budget--) { s->failed_pc=0x0c06448cu; return 0; }
r[4]=~r[4];
goto P_0c06448e;
P_0c06448e: /* original 6322, guest PC 0x0c06448e */
if(!s->budget--) { s->failed_pc=0x0c06448eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c064490;
P_0c064490: /* original 2349, guest PC 0x0c064490 */
if(!s->budget--) { s->failed_pc=0x0c064490u; return 0; }
r[3]&=r[4];
goto P_0c064492;
P_0c064492: /* original 2232, guest PC 0x0c064492 */
if(!s->budget--) { s->failed_pc=0x0c064492u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c064494;
P_0c064494: /* original d012, guest PC 0x0c064494 */
if(!s->budget--) { s->failed_pc=0x0c064494u; return 0; }
r[0]=read(ram,0x0c0644e0u,4);
goto P_0c064496;
P_0c064496: /* original 6de3, guest PC 0x0c064496 */
if(!s->budget--) { s->failed_pc=0x0c064496u; return 0; }
r[13]=r[14];
goto P_0c064498;
P_0c064498: /* original 4d08, guest PC 0x0c064498 */
if(!s->budget--) { s->failed_pc=0x0c064498u; return 0; }
r[13]<<=2;
goto P_0c06449a;
P_0c06449a: /* original 4d00, guest PC 0x0c06449a */
if(!s->budget--) { s->failed_pc=0x0c06449au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c06449c;
P_0c06449c: /* original 05de, guest PC 0x0c06449c */
if(!s->budget--) { s->failed_pc=0x0c06449cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c06449e;
P_0c06449e: /* original 70fc, guest PC 0x0c06449e */
if(!s->budget--) { s->failed_pc=0x0c06449eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0644a0;
P_0c0644a0: /* original 4a0b, guest PC 0x0c0644a0 */
if(!s->budget--) { s->failed_pc=0x0c0644a0u; return 0; }
target=r[10];
r[16]=0x0c0644a4u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0644a4u) { target=s->pc; goto dispatch; }
goto P_0c0644a4;
P_0c0644a2: /* original 04de, guest PC 0x0c0644a2 */
if(!s->budget--) { s->failed_pc=0x0c0644a2u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0644a4;
P_0c0644a4: /* original 7e01, guest PC 0x0c0644a4 */
if(!s->budget--) { s->failed_pc=0x0c0644a4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0644a6;
P_0c0644a6: /* original 3ec3, guest PC 0x0c0644a6 */
if(!s->budget--) { s->failed_pc=0x0c0644a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c0644a8;
P_0c0644a8: /* original 8bea, guest PC 0x0c0644a8 */
if(!s->budget--) { s->failed_pc=0x0c0644a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064480; }
goto P_0c0644aa;
P_0c0644aa: /* original e000, guest PC 0x0c0644aa */
if(!s->budget--) { s->failed_pc=0x0c0644aau; return 0; }
r[0]=0x00000000u;
goto P_0c0644ac;
P_0c0644ac: /* original 4f26, guest PC 0x0c0644ac */
if(!s->budget--) { s->failed_pc=0x0c0644acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0644ae;
P_0c0644ae: /* original 69f6, guest PC 0x0c0644ae */
if(!s->budget--) { s->failed_pc=0x0c0644aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0644b0;
P_0c0644b0: /* original 6af6, guest PC 0x0c0644b0 */
if(!s->budget--) { s->failed_pc=0x0c0644b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0644b2;
P_0c0644b2: /* original 6bf6, guest PC 0x0c0644b2 */
if(!s->budget--) { s->failed_pc=0x0c0644b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0644b4;
P_0c0644b4: /* original 6cf6, guest PC 0x0c0644b4 */
if(!s->budget--) { s->failed_pc=0x0c0644b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0644b6;
P_0c0644b6: /* original 6df6, guest PC 0x0c0644b6 */
if(!s->budget--) { s->failed_pc=0x0c0644b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0644b8;
P_0c0644b8: /* original 000b, guest PC 0x0c0644b8 */
if(!s->budget--) { s->failed_pc=0x0c0644b8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0644ba: /* original 6ef6, guest PC 0x0c0644ba */
if(!s->budget--) { s->failed_pc=0x0c0644bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0644bcu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
