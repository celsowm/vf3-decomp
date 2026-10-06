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
int vf3_target_remaining_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c034a02u: goto P_0c034a02;
case 0x0c034a04u: goto P_0c034a04;
case 0x0c034a06u: goto P_0c034a06;
case 0x0c034a08u: goto P_0c034a08;
case 0x0c034a0au: goto P_0c034a0a;
case 0x0c034a0cu: goto P_0c034a0c;
case 0x0c034a0eu: goto P_0c034a0e;
case 0x0c034a10u: goto P_0c034a10;
case 0x0c034a12u: goto P_0c034a12;
case 0x0c034a14u: goto P_0c034a14;
case 0x0c034a16u: goto P_0c034a16;
case 0x0c034a18u: goto P_0c034a18;
case 0x0c034a1au: goto P_0c034a1a;
case 0x0c034a1cu: goto P_0c034a1c;
case 0x0c034a1eu: goto P_0c034a1e;
case 0x0c03667eu: goto P_0c03667e;
case 0x0c036680u: goto P_0c036680;
case 0x0c036682u: goto P_0c036682;
case 0x0c036684u: goto P_0c036684;
case 0x0c036686u: goto P_0c036686;
case 0x0c036688u: goto P_0c036688;
case 0x0c0366b2u: goto P_0c0366b2;
case 0x0c0366b4u: goto P_0c0366b4;
case 0x0c0366b6u: goto P_0c0366b6;
case 0x0c0366b8u: goto P_0c0366b8;
case 0x0c0366bau: goto P_0c0366ba;
case 0x0c0366c6u: goto P_0c0366c6;
case 0x0c0366c8u: goto P_0c0366c8;
case 0x0c0366cau: goto P_0c0366ca;
case 0x0c0366ccu: goto P_0c0366cc;
case 0x0c0366ceu: goto P_0c0366ce;
case 0x0c0366f2u: goto P_0c0366f2;
case 0x0c0366f4u: goto P_0c0366f4;
case 0x0c0366f6u: goto P_0c0366f6;
case 0x0c0366f8u: goto P_0c0366f8;
case 0x0c0366fau: goto P_0c0366fa;
case 0x0c036706u: goto P_0c036706;
case 0x0c036708u: goto P_0c036708;
case 0x0c03670au: goto P_0c03670a;
case 0x0c03670cu: goto P_0c03670c;
case 0x0c03670eu: goto P_0c03670e;
case 0x0c03671au: goto P_0c03671a;
case 0x0c03671cu: goto P_0c03671c;
case 0x0c03671eu: goto P_0c03671e;
case 0x0c036720u: goto P_0c036720;
case 0x0c036722u: goto P_0c036722;
case 0x0c036724u: goto P_0c036724;
case 0x0c036726u: goto P_0c036726;
case 0x0c036728u: goto P_0c036728;
case 0x0c03673eu: goto P_0c03673e;
case 0x0c036740u: goto P_0c036740;
case 0x0c036742u: goto P_0c036742;
case 0x0c036744u: goto P_0c036744;
case 0x0c036746u: goto P_0c036746;
case 0x0c036752u: goto P_0c036752;
case 0x0c036754u: goto P_0c036754;
case 0x0c036756u: goto P_0c036756;
case 0x0c036758u: goto P_0c036758;
case 0x0c03675au: goto P_0c03675a;
case 0x0c038b4eu: goto P_0c038b4e;
case 0x0c038b50u: goto P_0c038b50;
case 0x0c038b52u: goto P_0c038b52;
case 0x0c038b54u: goto P_0c038b54;
case 0x0c038b56u: goto P_0c038b56;
case 0x0c038b58u: goto P_0c038b58;
case 0x0c038b60u: goto P_0c038b60;
case 0x0c038b62u: goto P_0c038b62;
case 0x0c038b64u: goto P_0c038b64;
case 0x0c038b66u: goto P_0c038b66;
case 0x0c038b68u: goto P_0c038b68;
case 0x0c038b6au: goto P_0c038b6a;
case 0x0c038b6cu: goto P_0c038b6c;
case 0x0c038b6eu: goto P_0c038b6e;
case 0x0c038b70u: goto P_0c038b70;
case 0x0c038b72u: goto P_0c038b72;
case 0x0c038b74u: goto P_0c038b74;
case 0x0c038b76u: goto P_0c038b76;
case 0x0c038b78u: goto P_0c038b78;
case 0x0c038b7au: goto P_0c038b7a;
case 0x0c038b7cu: goto P_0c038b7c;
case 0x0c038b7eu: goto P_0c038b7e;
case 0x0c038b80u: goto P_0c038b80;
case 0x0c038b82u: goto P_0c038b82;
case 0x0c038b90u: goto P_0c038b90;
case 0x0c038b92u: goto P_0c038b92;
case 0x0c038b94u: goto P_0c038b94;
case 0x0c038b96u: goto P_0c038b96;
case 0x0c038b98u: goto P_0c038b98;
case 0x0c038b9au: goto P_0c038b9a;
case 0x0c038b9cu: goto P_0c038b9c;
case 0x0c038b9eu: goto P_0c038b9e;
case 0x0c038ba0u: goto P_0c038ba0;
case 0x0c038ba2u: goto P_0c038ba2;
case 0x0c038ba4u: goto P_0c038ba4;
case 0x0c038ba6u: goto P_0c038ba6;
case 0x0c038ba8u: goto P_0c038ba8;
case 0x0c038baau: goto P_0c038baa;
case 0x0c038bacu: goto P_0c038bac;
case 0x0c038baeu: goto P_0c038bae;
case 0x0c038bb0u: goto P_0c038bb0;
case 0x0c038bb2u: goto P_0c038bb2;
case 0x0c038bb4u: goto P_0c038bb4;
case 0x0c03a190u: goto P_0c03a190;
case 0x0c03a192u: goto P_0c03a192;
case 0x0c03a194u: goto P_0c03a194;
case 0x0c03a196u: goto P_0c03a196;
case 0x0c03a198u: goto P_0c03a198;
case 0x0c03a19au: goto P_0c03a19a;
case 0x0c03a19cu: goto P_0c03a19c;
case 0x0c03a19eu: goto P_0c03a19e;
case 0x0c03a1a0u: goto P_0c03a1a0;
case 0x0c03a1a2u: goto P_0c03a1a2;
case 0x0c03a1a4u: goto P_0c03a1a4;
case 0x0c03c6f0u: goto P_0c03c6f0;
case 0x0c03c6f2u: goto P_0c03c6f2;
case 0x0c03c6f4u: goto P_0c03c6f4;
case 0x0c03c6f6u: goto P_0c03c6f6;
case 0x0c03c6f8u: goto P_0c03c6f8;
case 0x0c03c6fau: goto P_0c03c6fa;
case 0x0c03c6fcu: goto P_0c03c6fc;
case 0x0c03c6feu: goto P_0c03c6fe;
case 0x0c03c700u: goto P_0c03c700;
case 0x0c03c702u: goto P_0c03c702;
case 0x0c03c704u: goto P_0c03c704;
case 0x0c03c706u: goto P_0c03c706;
case 0x0c03c708u: goto P_0c03c708;
case 0x0c03c70au: goto P_0c03c70a;
case 0x0c03c70cu: goto P_0c03c70c;
case 0x0c03c70eu: goto P_0c03c70e;
case 0x0c03c710u: goto P_0c03c710;
case 0x0c03c712u: goto P_0c03c712;
case 0x0c03c714u: goto P_0c03c714;
case 0x0c03c716u: goto P_0c03c716;
case 0x0c03c850u: goto P_0c03c850;
case 0x0c03c852u: goto P_0c03c852;
case 0x0c03c854u: goto P_0c03c854;
case 0x0c03c856u: goto P_0c03c856;
case 0x0c03c858u: goto P_0c03c858;
case 0x0c03c85au: goto P_0c03c85a;
case 0x0c03c85cu: goto P_0c03c85c;
case 0x0c03c85eu: goto P_0c03c85e;
case 0x0c03c860u: goto P_0c03c860;
case 0x0c03c862u: goto P_0c03c862;
case 0x0c03c864u: goto P_0c03c864;
case 0x0c03c866u: goto P_0c03c866;
case 0x0c03c868u: goto P_0c03c868;
case 0x0c03c86au: goto P_0c03c86a;
case 0x0c03c86cu: goto P_0c03c86c;
case 0x0c03c86eu: goto P_0c03c86e;
case 0x0c03c870u: goto P_0c03c870;
case 0x0c03c872u: goto P_0c03c872;
case 0x0c03c910u: goto P_0c03c910;
case 0x0c03c912u: goto P_0c03c912;
case 0x0c03c914u: goto P_0c03c914;
case 0x0c03c916u: goto P_0c03c916;
case 0x0c03c918u: goto P_0c03c918;
case 0x0c03c91au: goto P_0c03c91a;
case 0x0c03c91cu: goto P_0c03c91c;
case 0x0c03c91eu: goto P_0c03c91e;
case 0x0c03c920u: goto P_0c03c920;
case 0x0c03c922u: goto P_0c03c922;
case 0x0c03c924u: goto P_0c03c924;
case 0x0c03c926u: goto P_0c03c926;
case 0x0c03c928u: goto P_0c03c928;
case 0x0c03c92au: goto P_0c03c92a;
case 0x0c03c92cu: goto P_0c03c92c;
case 0x0c03c92eu: goto P_0c03c92e;
case 0x0c03c930u: goto P_0c03c930;
case 0x0c03c932u: goto P_0c03c932;
case 0x0c03c9d0u: goto P_0c03c9d0;
case 0x0c03c9d2u: goto P_0c03c9d2;
case 0x0c03c9d4u: goto P_0c03c9d4;
case 0x0c03c9d6u: goto P_0c03c9d6;
case 0x0c03c9d8u: goto P_0c03c9d8;
case 0x0c03c9dau: goto P_0c03c9da;
case 0x0c03c9dcu: goto P_0c03c9dc;
case 0x0c03c9deu: goto P_0c03c9de;
case 0x0c03c9e0u: goto P_0c03c9e0;
case 0x0c03c9e2u: goto P_0c03c9e2;
case 0x0c03c9e4u: goto P_0c03c9e4;
case 0x0c03c9e6u: goto P_0c03c9e6;
case 0x0c03c9e8u: goto P_0c03c9e8;
case 0x0c03c9eau: goto P_0c03c9ea;
case 0x0c03c9ecu: goto P_0c03c9ec;
case 0x0c03c9eeu: goto P_0c03c9ee;
case 0x0c03c9f0u: goto P_0c03c9f0;
case 0x0c03c9f2u: goto P_0c03c9f2;
case 0x0c03ca00u: goto P_0c03ca00;
case 0x0c03ca02u: goto P_0c03ca02;
case 0x0c03ca04u: goto P_0c03ca04;
case 0x0c03ca06u: goto P_0c03ca06;
case 0x0c03ca08u: goto P_0c03ca08;
case 0x0c03ca0au: goto P_0c03ca0a;
case 0x0c03ca0cu: goto P_0c03ca0c;
case 0x0c03ca0eu: goto P_0c03ca0e;
case 0x0c03ca10u: goto P_0c03ca10;
case 0x0c03ca12u: goto P_0c03ca12;
case 0x0c03ca14u: goto P_0c03ca14;
case 0x0c03ca16u: goto P_0c03ca16;
case 0x0c03ca18u: goto P_0c03ca18;
case 0x0c03ca1au: goto P_0c03ca1a;
case 0x0c03ca1cu: goto P_0c03ca1c;
case 0x0c03ca1eu: goto P_0c03ca1e;
case 0x0c03ca20u: goto P_0c03ca20;
case 0x0c03ca22u: goto P_0c03ca22;
case 0x0c03ca24u: goto P_0c03ca24;
case 0x0c03ca26u: goto P_0c03ca26;
case 0x0c03ca28u: goto P_0c03ca28;
case 0x0c03ca2au: goto P_0c03ca2a;
case 0x0c03ca2cu: goto P_0c03ca2c;
case 0x0c03ca2eu: goto P_0c03ca2e;
case 0x0c03ca30u: goto P_0c03ca30;
case 0x0c03ca32u: goto P_0c03ca32;
case 0x0c03ca34u: goto P_0c03ca34;
case 0x0c03ca36u: goto P_0c03ca36;
case 0x0c03ca38u: goto P_0c03ca38;
case 0x0c03ca3au: goto P_0c03ca3a;
case 0x0c03ca3cu: goto P_0c03ca3c;
case 0x0c03ca3eu: goto P_0c03ca3e;
case 0x0c03ca40u: goto P_0c03ca40;
case 0x0c03ca42u: goto P_0c03ca42;
case 0x0c03ca44u: goto P_0c03ca44;
case 0x0c03ca46u: goto P_0c03ca46;
case 0x0c03ca48u: goto P_0c03ca48;
case 0x0c03ca4au: goto P_0c03ca4a;
case 0x0c03ca4cu: goto P_0c03ca4c;
case 0x0c03ca4eu: goto P_0c03ca4e;
case 0x0c03ca50u: goto P_0c03ca50;
case 0x0c03ca52u: goto P_0c03ca52;
case 0x0c03ca54u: goto P_0c03ca54;
case 0x0c03ca56u: goto P_0c03ca56;
case 0x0c03ca58u: goto P_0c03ca58;
case 0x0c03ca5au: goto P_0c03ca5a;
case 0x0c03ca5cu: goto P_0c03ca5c;
case 0x0c03ca5eu: goto P_0c03ca5e;
case 0x0c03ca60u: goto P_0c03ca60;
case 0x0c03ca62u: goto P_0c03ca62;
case 0x0c03ca64u: goto P_0c03ca64;
case 0x0c03ca66u: goto P_0c03ca66;
case 0x0c03ca68u: goto P_0c03ca68;
case 0x0c03ca6au: goto P_0c03ca6a;
case 0x0c03ca6cu: goto P_0c03ca6c;
case 0x0c03ca6eu: goto P_0c03ca6e;
case 0x0c03ca70u: goto P_0c03ca70;
case 0x0c03ca72u: goto P_0c03ca72;
case 0x0c03ca74u: goto P_0c03ca74;
case 0x0c03ca76u: goto P_0c03ca76;
case 0x0c03ca78u: goto P_0c03ca78;
case 0x0c03ca7au: goto P_0c03ca7a;
case 0x0c03ca7cu: goto P_0c03ca7c;
case 0x0c03ca7eu: goto P_0c03ca7e;
case 0x0c03ca80u: goto P_0c03ca80;
case 0x0c03ca82u: goto P_0c03ca82;
case 0x0c03ca84u: goto P_0c03ca84;
case 0x0c03ca86u: goto P_0c03ca86;
case 0x0c03ca88u: goto P_0c03ca88;
case 0x0c03ca8au: goto P_0c03ca8a;
case 0x0c03ca8cu: goto P_0c03ca8c;
case 0x0c03ca8eu: goto P_0c03ca8e;
case 0x0c03ca90u: goto P_0c03ca90;
case 0x0c03ca92u: goto P_0c03ca92;
case 0x0c03ca94u: goto P_0c03ca94;
case 0x0c03ca96u: goto P_0c03ca96;
case 0x0c03ca98u: goto P_0c03ca98;
case 0x0c03ca9au: goto P_0c03ca9a;
case 0x0c03ca9cu: goto P_0c03ca9c;
case 0x0c03ca9eu: goto P_0c03ca9e;
case 0x0c03caa0u: goto P_0c03caa0;
case 0x0c03caa2u: goto P_0c03caa2;
case 0x0c03caa4u: goto P_0c03caa4;
case 0x0c03caa6u: goto P_0c03caa6;
case 0x0c03caa8u: goto P_0c03caa8;
case 0x0c03caaau: goto P_0c03caaa;
case 0x0c03caacu: goto P_0c03caac;
case 0x0c03caaeu: goto P_0c03caae;
case 0x0c03cab0u: goto P_0c03cab0;
case 0x0c03cab2u: goto P_0c03cab2;
case 0x0c03cab4u: goto P_0c03cab4;
case 0x0c03cab6u: goto P_0c03cab6;
case 0x0c03cab8u: goto P_0c03cab8;
case 0x0c03cabau: goto P_0c03caba;
case 0x0c03cabcu: goto P_0c03cabc;
case 0x0c03cabeu: goto P_0c03cabe;
case 0x0c03e760u: goto P_0c03e760;
case 0x0c03e762u: goto P_0c03e762;
case 0x0c03e764u: goto P_0c03e764;
case 0x0c03e766u: goto P_0c03e766;
case 0x0c03e768u: goto P_0c03e768;
case 0x0c03e76au: goto P_0c03e76a;
case 0x0c03e76cu: goto P_0c03e76c;
case 0x0c03e76eu: goto P_0c03e76e;
case 0x0c03e770u: goto P_0c03e770;
case 0x0c03e772u: goto P_0c03e772;
case 0x0c03e774u: goto P_0c03e774;
case 0x0c03e776u: goto P_0c03e776;
case 0x0c03e778u: goto P_0c03e778;
case 0x0c03e77au: goto P_0c03e77a;
case 0x0c03e77cu: goto P_0c03e77c;
case 0x0c03e77eu: goto P_0c03e77e;
case 0x0c03e780u: goto P_0c03e780;
case 0x0c03e782u: goto P_0c03e782;
case 0x0c03e784u: goto P_0c03e784;
case 0x0c03e786u: goto P_0c03e786;
case 0x0c03e7c0u: goto P_0c03e7c0;
case 0x0c03e7c2u: goto P_0c03e7c2;
case 0x0c03e7c4u: goto P_0c03e7c4;
case 0x0c03e7c6u: goto P_0c03e7c6;
case 0x0c03e7c8u: goto P_0c03e7c8;
case 0x0c03e7cau: goto P_0c03e7ca;
case 0x0c03e7ccu: goto P_0c03e7cc;
case 0x0c03e7ceu: goto P_0c03e7ce;
case 0x0c03e7d0u: goto P_0c03e7d0;
case 0x0c03e7d2u: goto P_0c03e7d2;
case 0x0c03e7d4u: goto P_0c03e7d4;
case 0x0c03e7d6u: goto P_0c03e7d6;
case 0x0c03e7d8u: goto P_0c03e7d8;
case 0x0c03e7dau: goto P_0c03e7da;
case 0x0c03e7dcu: goto P_0c03e7dc;
case 0x0c03e7deu: goto P_0c03e7de;
case 0x0c03e7e0u: goto P_0c03e7e0;
case 0x0c04236au: goto P_0c04236a;
case 0x0c04236cu: goto P_0c04236c;
case 0x0c04236eu: goto P_0c04236e;
case 0x0c042370u: goto P_0c042370;
case 0x0c042372u: goto P_0c042372;
case 0x0c042374u: goto P_0c042374;
case 0x0c042376u: goto P_0c042376;
case 0x0c042378u: goto P_0c042378;
case 0x0c04237au: goto P_0c04237a;
case 0x0c04237cu: goto P_0c04237c;
case 0x0c04237eu: goto P_0c04237e;
case 0x0c042380u: goto P_0c042380;
case 0x0c042382u: goto P_0c042382;
case 0x0c042384u: goto P_0c042384;
case 0x0c042386u: goto P_0c042386;
case 0x0c042388u: goto P_0c042388;
case 0x0c04238au: goto P_0c04238a;
case 0x0c04238cu: goto P_0c04238c;
case 0x0c04238eu: goto P_0c04238e;
case 0x0c042390u: goto P_0c042390;
case 0x0c042392u: goto P_0c042392;
case 0x0c042394u: goto P_0c042394;
case 0x0c042396u: goto P_0c042396;
case 0x0c042398u: goto P_0c042398;
case 0x0c04239au: goto P_0c04239a;
case 0x0c04239cu: goto P_0c04239c;
case 0x0c04239eu: goto P_0c04239e;
case 0x0c0423a0u: goto P_0c0423a0;
case 0x0c0423a2u: goto P_0c0423a2;
case 0x0c0430f0u: goto P_0c0430f0;
case 0x0c0430f2u: goto P_0c0430f2;
case 0x0c0430f4u: goto P_0c0430f4;
case 0x0c0430f6u: goto P_0c0430f6;
case 0x0c0430f8u: goto P_0c0430f8;
case 0x0c0430fau: goto P_0c0430fa;
case 0x0c0443f2u: goto P_0c0443f2;
case 0x0c0443f4u: goto P_0c0443f4;
case 0x0c0443f6u: goto P_0c0443f6;
case 0x0c0443f8u: goto P_0c0443f8;
case 0x0c0443fau: goto P_0c0443fa;
case 0x0c0443fcu: goto P_0c0443fc;
case 0x0c0443feu: goto P_0c0443fe;
case 0x0c044400u: goto P_0c044400;
case 0x0c044402u: goto P_0c044402;
case 0x0c044404u: goto P_0c044404;
case 0x0c044406u: goto P_0c044406;
case 0x0c044408u: goto P_0c044408;
case 0x0c04440au: goto P_0c04440a;
case 0x0c04440cu: goto P_0c04440c;
case 0x0c04440eu: goto P_0c04440e;
case 0x0c044410u: goto P_0c044410;
case 0x0c044412u: goto P_0c044412;
case 0x0c044414u: goto P_0c044414;
case 0x0c044416u: goto P_0c044416;
case 0x0c044418u: goto P_0c044418;
case 0x0c04441au: goto P_0c04441a;
case 0x0c04441cu: goto P_0c04441c;
case 0x0c04441eu: goto P_0c04441e;
case 0x0c044420u: goto P_0c044420;
case 0x0c044422u: goto P_0c044422;
case 0x0c044424u: goto P_0c044424;
case 0x0c044426u: goto P_0c044426;
case 0x0c044428u: goto P_0c044428;
case 0x0c04442au: goto P_0c04442a;
case 0x0c04442cu: goto P_0c04442c;
case 0x0c04442eu: goto P_0c04442e;
case 0x0c044430u: goto P_0c044430;
case 0x0c044432u: goto P_0c044432;
case 0x0c044434u: goto P_0c044434;
case 0x0c044436u: goto P_0c044436;
case 0x0c044438u: goto P_0c044438;
case 0x0c04443au: goto P_0c04443a;
case 0x0c04443cu: goto P_0c04443c;
case 0x0c04443eu: goto P_0c04443e;
case 0x0c044440u: goto P_0c044440;
case 0x0c044442u: goto P_0c044442;
case 0x0c044444u: goto P_0c044444;
case 0x0c044446u: goto P_0c044446;
case 0x0c044448u: goto P_0c044448;
case 0x0c04444au: goto P_0c04444a;
case 0x0c04444cu: goto P_0c04444c;
case 0x0c04444eu: goto P_0c04444e;
case 0x0c044450u: goto P_0c044450;
case 0x0c044452u: goto P_0c044452;
case 0x0c044454u: goto P_0c044454;
case 0x0c044456u: goto P_0c044456;
case 0x0c044458u: goto P_0c044458;
case 0x0c04445au: goto P_0c04445a;
case 0x0c04445cu: goto P_0c04445c;
case 0x0c04445eu: goto P_0c04445e;
case 0x0c044460u: goto P_0c044460;
case 0x0c044462u: goto P_0c044462;
case 0x0c044464u: goto P_0c044464;
case 0x0c044466u: goto P_0c044466;
case 0x0c044468u: goto P_0c044468;
case 0x0c04446au: goto P_0c04446a;
case 0x0c04446cu: goto P_0c04446c;
case 0x0c04446eu: goto P_0c04446e;
case 0x0c044470u: goto P_0c044470;
case 0x0c044472u: goto P_0c044472;
case 0x0c044474u: goto P_0c044474;
case 0x0c044476u: goto P_0c044476;
case 0x0c044478u: goto P_0c044478;
case 0x0c04447au: goto P_0c04447a;
case 0x0c04447cu: goto P_0c04447c;
case 0x0c04447eu: goto P_0c04447e;
case 0x0c044480u: goto P_0c044480;
case 0x0c044482u: goto P_0c044482;
case 0x0c045f62u: goto P_0c045f62;
case 0x0c045f64u: goto P_0c045f64;
case 0x0c045f66u: goto P_0c045f66;
case 0x0c045f68u: goto P_0c045f68;
case 0x0c045f6au: goto P_0c045f6a;
case 0x0c045f6cu: goto P_0c045f6c;
case 0x0c045f6eu: goto P_0c045f6e;
case 0x0c045f70u: goto P_0c045f70;
case 0x0c045f72u: goto P_0c045f72;
case 0x0c045f74u: goto P_0c045f74;
case 0x0c045f76u: goto P_0c045f76;
case 0x0c045f78u: goto P_0c045f78;
case 0x0c045f7au: goto P_0c045f7a;
case 0x0c045f7cu: goto P_0c045f7c;
case 0x0c04d4c2u: goto P_0c04d4c2;
case 0x0c04d4c4u: goto P_0c04d4c4;
case 0x0c04d4c6u: goto P_0c04d4c6;
case 0x0c04d4c8u: goto P_0c04d4c8;
case 0x0c04d4cau: goto P_0c04d4ca;
case 0x0c04d4ccu: goto P_0c04d4cc;
case 0x0c04d4ceu: goto P_0c04d4ce;
case 0x0c04d4d0u: goto P_0c04d4d0;
case 0x0c04d4d2u: goto P_0c04d4d2;
case 0x0c04d4d4u: goto P_0c04d4d4;
case 0x0c04d4d6u: goto P_0c04d4d6;
case 0x0c04d4d8u: goto P_0c04d4d8;
case 0x0c04d4dau: goto P_0c04d4da;
case 0x0c04d4dcu: goto P_0c04d4dc;
case 0x0c04d4deu: goto P_0c04d4de;
case 0x0c04d4e0u: goto P_0c04d4e0;
case 0x0c04d4e2u: goto P_0c04d4e2;
case 0x0c04d4e4u: goto P_0c04d4e4;
case 0x0c04d4e6u: goto P_0c04d4e6;
case 0x0c04d4e8u: goto P_0c04d4e8;
case 0x0c04d4eau: goto P_0c04d4ea;
case 0x0c04d4ecu: goto P_0c04d4ec;
case 0x0c04d4eeu: goto P_0c04d4ee;
case 0x0c04d4f0u: goto P_0c04d4f0;
case 0x0c04d4f2u: goto P_0c04d4f2;
case 0x0c04d4f4u: goto P_0c04d4f4;
case 0x0c04d4f6u: goto P_0c04d4f6;
case 0x0c04d4f8u: goto P_0c04d4f8;
case 0x0c04d4fau: goto P_0c04d4fa;
case 0x0c04d4fcu: goto P_0c04d4fc;
case 0x0c04d4feu: goto P_0c04d4fe;
case 0x0c04d500u: goto P_0c04d500;
case 0x0c04d502u: goto P_0c04d502;
case 0x0c04d504u: goto P_0c04d504;
case 0x0c04d506u: goto P_0c04d506;
case 0x0c04d508u: goto P_0c04d508;
case 0x0c04d50au: goto P_0c04d50a;
case 0x0c04f256u: goto P_0c04f256;
case 0x0c04f258u: goto P_0c04f258;
case 0x0c04f25au: goto P_0c04f25a;
case 0x0c04f25cu: goto P_0c04f25c;
case 0x0c04f25eu: goto P_0c04f25e;
case 0x0c04f260u: goto P_0c04f260;
case 0x0c04f262u: goto P_0c04f262;
case 0x0c04f264u: goto P_0c04f264;
case 0x0c04f266u: goto P_0c04f266;
case 0x0c04f268u: goto P_0c04f268;
case 0x0c04f26au: goto P_0c04f26a;
case 0x0c04f26cu: goto P_0c04f26c;
case 0x0c04f26eu: goto P_0c04f26e;
case 0x0c04f270u: goto P_0c04f270;
case 0x0c04f272u: goto P_0c04f272;
case 0x0c04f274u: goto P_0c04f274;
case 0x0c04f276u: goto P_0c04f276;
case 0x0c04f278u: goto P_0c04f278;
case 0x0c04f27au: goto P_0c04f27a;
case 0x0c04f27cu: goto P_0c04f27c;
case 0x0c04f27eu: goto P_0c04f27e;
case 0x0c04f280u: goto P_0c04f280;
case 0x0c04f282u: goto P_0c04f282;
case 0x0c04f284u: goto P_0c04f284;
case 0x0c04f286u: goto P_0c04f286;
case 0x0c04f288u: goto P_0c04f288;
case 0x0c04f28au: goto P_0c04f28a;
case 0x0c04f28cu: goto P_0c04f28c;
case 0x0c04f28eu: goto P_0c04f28e;
case 0x0c04f290u: goto P_0c04f290;
case 0x0c04f292u: goto P_0c04f292;
case 0x0c04f294u: goto P_0c04f294;
case 0x0c04f296u: goto P_0c04f296;
case 0x0c04f298u: goto P_0c04f298;
case 0x0c04f29au: goto P_0c04f29a;
case 0x0c04f29cu: goto P_0c04f29c;
case 0x0c04f29eu: goto P_0c04f29e;
case 0x0c04f2a0u: goto P_0c04f2a0;
case 0x0c04f2a2u: goto P_0c04f2a2;
case 0x0c04f2b0u: goto P_0c04f2b0;
case 0x0c04f2b2u: goto P_0c04f2b2;
case 0x0c04f2b4u: goto P_0c04f2b4;
case 0x0c04f2b6u: goto P_0c04f2b6;
case 0x0c04f2b8u: goto P_0c04f2b8;
case 0x0c04f2bau: goto P_0c04f2ba;
case 0x0c04f2bcu: goto P_0c04f2bc;
case 0x0c04f2beu: goto P_0c04f2be;
case 0x0c04f2c0u: goto P_0c04f2c0;
case 0x0c04f2c2u: goto P_0c04f2c2;
case 0x0c04f2c4u: goto P_0c04f2c4;
case 0x0c04f2c6u: goto P_0c04f2c6;
case 0x0c04f2c8u: goto P_0c04f2c8;
case 0x0c04f2cau: goto P_0c04f2ca;
case 0x0c04f2ccu: goto P_0c04f2cc;
case 0x0c04f2ceu: goto P_0c04f2ce;
case 0x0c04f2d0u: goto P_0c04f2d0;
case 0x0c04f2d2u: goto P_0c04f2d2;
case 0x0c04f2d4u: goto P_0c04f2d4;
case 0x0c04f2d6u: goto P_0c04f2d6;
case 0x0c04f2d8u: goto P_0c04f2d8;
case 0x0c04f2dau: goto P_0c04f2da;
case 0x0c04f2dcu: goto P_0c04f2dc;
case 0x0c04f2deu: goto P_0c04f2de;
case 0x0c04f2e0u: goto P_0c04f2e0;
case 0x0c04f2e2u: goto P_0c04f2e2;
case 0x0c04f2e4u: goto P_0c04f2e4;
case 0x0c04f2e6u: goto P_0c04f2e6;
case 0x0c04f2e8u: goto P_0c04f2e8;
case 0x0c04f2eau: goto P_0c04f2ea;
case 0x0c04f2ecu: goto P_0c04f2ec;
case 0x0c04f2eeu: goto P_0c04f2ee;
case 0x0c04f2f0u: goto P_0c04f2f0;
case 0x0c04f2f2u: goto P_0c04f2f2;
case 0x0c04f2f4u: goto P_0c04f2f4;
case 0x0c04f2f6u: goto P_0c04f2f6;
case 0x0c04f2f8u: goto P_0c04f2f8;
case 0x0c04f2fau: goto P_0c04f2fa;
case 0x0c058b80u: goto P_0c058b80;
case 0x0c058b82u: goto P_0c058b82;
case 0x0c058b84u: goto P_0c058b84;
case 0x0c058b86u: goto P_0c058b86;
case 0x0c058b88u: goto P_0c058b88;
case 0x0c058b8au: goto P_0c058b8a;
case 0x0c058b8cu: goto P_0c058b8c;
case 0x0c058b8eu: goto P_0c058b8e;
case 0x0c058b90u: goto P_0c058b90;
case 0x0c058b92u: goto P_0c058b92;
case 0x0c058b94u: goto P_0c058b94;
case 0x0c058b96u: goto P_0c058b96;
case 0x0c058b98u: goto P_0c058b98;
case 0x0c058b9au: goto P_0c058b9a;
case 0x0c058b9cu: goto P_0c058b9c;
case 0x0c058b9eu: goto P_0c058b9e;
case 0x0c058ba0u: goto P_0c058ba0;
case 0x0c058ba2u: goto P_0c058ba2;
case 0x0c058ba4u: goto P_0c058ba4;
case 0x0c058bc0u: goto P_0c058bc0;
case 0x0c058bc2u: goto P_0c058bc2;
case 0x0c058bc4u: goto P_0c058bc4;
case 0x0c058bc6u: goto P_0c058bc6;
case 0x0c058bc8u: goto P_0c058bc8;
case 0x0c058bcau: goto P_0c058bca;
case 0x0c058bccu: goto P_0c058bcc;
case 0x0c058bceu: goto P_0c058bce;
case 0x0c058bd0u: goto P_0c058bd0;
case 0x0c058bd2u: goto P_0c058bd2;
case 0x0c058bd4u: goto P_0c058bd4;
case 0x0c058bd6u: goto P_0c058bd6;
case 0x0c058bd8u: goto P_0c058bd8;
case 0x0c058bdau: goto P_0c058bda;
case 0x0c058bdcu: goto P_0c058bdc;
case 0x0c058bdeu: goto P_0c058bde;
case 0x0c058be0u: goto P_0c058be0;
case 0x0c058be2u: goto P_0c058be2;
case 0x0c058be4u: goto P_0c058be4;
case 0x0c058be6u: goto P_0c058be6;
case 0x0c058be8u: goto P_0c058be8;
case 0x0c058beau: goto P_0c058bea;
case 0x0c058becu: goto P_0c058bec;
case 0x0c058beeu: goto P_0c058bee;
case 0x0c058bf0u: goto P_0c058bf0;
case 0x0c058bf2u: goto P_0c058bf2;
case 0x0c058bf4u: goto P_0c058bf4;
case 0x0c058bf6u: goto P_0c058bf6;
case 0x0c058bf8u: goto P_0c058bf8;
case 0x0c058bfau: goto P_0c058bfa;
case 0x0c058bfcu: goto P_0c058bfc;
case 0x0c058bfeu: goto P_0c058bfe;
case 0x0c058c00u: goto P_0c058c00;
case 0x0c058c02u: goto P_0c058c02;
case 0x0c058c04u: goto P_0c058c04;
case 0x0c058c06u: goto P_0c058c06;
case 0x0c058c08u: goto P_0c058c08;
case 0x0c058c0au: goto P_0c058c0a;
case 0x0c058c0cu: goto P_0c058c0c;
case 0x0c058c0eu: goto P_0c058c0e;
case 0x0c058c10u: goto P_0c058c10;
case 0x0c058c12u: goto P_0c058c12;
case 0x0c058c14u: goto P_0c058c14;
case 0x0c058c16u: goto P_0c058c16;
case 0x0c058c18u: goto P_0c058c18;
case 0x0c058c1au: goto P_0c058c1a;
case 0x0c058c1cu: goto P_0c058c1c;
case 0x0c058c1eu: goto P_0c058c1e;
case 0x0c058c20u: goto P_0c058c20;
case 0x0c058c22u: goto P_0c058c22;
case 0x0c058c24u: goto P_0c058c24;
case 0x0c058c26u: goto P_0c058c26;
case 0x0c058c28u: goto P_0c058c28;
case 0x0c058c2au: goto P_0c058c2a;
case 0x0c058c2cu: goto P_0c058c2c;
case 0x0c058c2eu: goto P_0c058c2e;
case 0x0c058c30u: goto P_0c058c30;
case 0x0c058c32u: goto P_0c058c32;
case 0x0c058c34u: goto P_0c058c34;
case 0x0c058c36u: goto P_0c058c36;
case 0x0c058c38u: goto P_0c058c38;
case 0x0c058c3au: goto P_0c058c3a;
case 0x0c058c3cu: goto P_0c058c3c;
case 0x0c058c3eu: goto P_0c058c3e;
case 0x0c058c40u: goto P_0c058c40;
case 0x0c058c42u: goto P_0c058c42;
case 0x0c058c44u: goto P_0c058c44;
case 0x0c058c46u: goto P_0c058c46;
case 0x0c058c48u: goto P_0c058c48;
case 0x0c058c4au: goto P_0c058c4a;
case 0x0c058c4cu: goto P_0c058c4c;
case 0x0c058c4eu: goto P_0c058c4e;
case 0x0c058c50u: goto P_0c058c50;
case 0x0c058c52u: goto P_0c058c52;
case 0x0c058c54u: goto P_0c058c54;
case 0x0c058c56u: goto P_0c058c56;
case 0x0c058c58u: goto P_0c058c58;
case 0x0c058c5au: goto P_0c058c5a;
case 0x0c058c5cu: goto P_0c058c5c;
case 0x0c058c5eu: goto P_0c058c5e;
case 0x0c058c60u: goto P_0c058c60;
case 0x0c058c62u: goto P_0c058c62;
case 0x0c058c64u: goto P_0c058c64;
case 0x0c058c66u: goto P_0c058c66;
case 0x0c058c68u: goto P_0c058c68;
case 0x0c058c6au: goto P_0c058c6a;
case 0x0c058c6cu: goto P_0c058c6c;
case 0x0c058c6eu: goto P_0c058c6e;
case 0x0c058c70u: goto P_0c058c70;
case 0x0c058c72u: goto P_0c058c72;
case 0x0c058c74u: goto P_0c058c74;
case 0x0c058c76u: goto P_0c058c76;
case 0x0c058c78u: goto P_0c058c78;
case 0x0c058c7au: goto P_0c058c7a;
case 0x0c058c7cu: goto P_0c058c7c;
case 0x0c058c7eu: goto P_0c058c7e;
case 0x0c058c80u: goto P_0c058c80;
case 0x0c058c82u: goto P_0c058c82;
case 0x0c058c84u: goto P_0c058c84;
case 0x0c058c86u: goto P_0c058c86;
case 0x0c058c88u: goto P_0c058c88;
case 0x0c058c8au: goto P_0c058c8a;
case 0x0c058c8cu: goto P_0c058c8c;
case 0x0c058c8eu: goto P_0c058c8e;
case 0x0c058c90u: goto P_0c058c90;
case 0x0c058c92u: goto P_0c058c92;
case 0x0c058c94u: goto P_0c058c94;
case 0x0c058c96u: goto P_0c058c96;
case 0x0c058c98u: goto P_0c058c98;
case 0x0c058c9au: goto P_0c058c9a;
case 0x0c058c9cu: goto P_0c058c9c;
case 0x0c058c9eu: goto P_0c058c9e;
case 0x0c058ca0u: goto P_0c058ca0;
case 0x0c058ca2u: goto P_0c058ca2;
case 0x0c058ca4u: goto P_0c058ca4;
case 0x0c058ca6u: goto P_0c058ca6;
case 0x0c058ca8u: goto P_0c058ca8;
case 0x0c058d70u: goto P_0c058d70;
case 0x0c058d72u: goto P_0c058d72;
case 0x0c058d74u: goto P_0c058d74;
case 0x0c058d76u: goto P_0c058d76;
case 0x0c058d78u: goto P_0c058d78;
case 0x0c058d7au: goto P_0c058d7a;
case 0x0c058d7cu: goto P_0c058d7c;
case 0x0c058d7eu: goto P_0c058d7e;
case 0x0c058d80u: goto P_0c058d80;
case 0x0c058d82u: goto P_0c058d82;
case 0x0c058d84u: goto P_0c058d84;
case 0x0c058d86u: goto P_0c058d86;
case 0x0c058d88u: goto P_0c058d88;
case 0x0c058d8au: goto P_0c058d8a;
case 0x0c058d8cu: goto P_0c058d8c;
case 0x0c058d8eu: goto P_0c058d8e;
case 0x0c058d90u: goto P_0c058d90;
case 0x0c058d92u: goto P_0c058d92;
case 0x0c058d94u: goto P_0c058d94;
case 0x0c058d96u: goto P_0c058d96;
case 0x0c058d98u: goto P_0c058d98;
case 0x0c058d9au: goto P_0c058d9a;
case 0x0c058d9cu: goto P_0c058d9c;
case 0x0c058d9eu: goto P_0c058d9e;
case 0x0c058da0u: goto P_0c058da0;
case 0x0c058da2u: goto P_0c058da2;
case 0x0c058da4u: goto P_0c058da4;
case 0x0c058da6u: goto P_0c058da6;
case 0x0c058da8u: goto P_0c058da8;
case 0x0c058daau: goto P_0c058daa;
case 0x0c058dacu: goto P_0c058dac;
case 0x0c058daeu: goto P_0c058dae;
case 0x0c058db0u: goto P_0c058db0;
case 0x0c058db2u: goto P_0c058db2;
case 0x0c058db4u: goto P_0c058db4;
case 0x0c058db6u: goto P_0c058db6;
case 0x0c058db8u: goto P_0c058db8;
case 0x0c058dbau: goto P_0c058dba;
case 0x0c058dbcu: goto P_0c058dbc;
case 0x0c058dbeu: goto P_0c058dbe;
case 0x0c058dc0u: goto P_0c058dc0;
case 0x0c058dc2u: goto P_0c058dc2;
case 0x0c058dc4u: goto P_0c058dc4;
case 0x0c058dc6u: goto P_0c058dc6;
case 0x0c058dc8u: goto P_0c058dc8;
case 0x0c058dcau: goto P_0c058dca;
case 0x0c058dccu: goto P_0c058dcc;
case 0x0c058dceu: goto P_0c058dce;
case 0x0c058dd0u: goto P_0c058dd0;
case 0x0c058dd2u: goto P_0c058dd2;
case 0x0c058dd4u: goto P_0c058dd4;
case 0x0c058dd6u: goto P_0c058dd6;
case 0x0c058dd8u: goto P_0c058dd8;
case 0x0c058ddau: goto P_0c058dda;
case 0x0c058ddcu: goto P_0c058ddc;
case 0x0c058ddeu: goto P_0c058dde;
case 0x0c058de0u: goto P_0c058de0;
case 0x0c058de2u: goto P_0c058de2;
case 0x0c058de4u: goto P_0c058de4;
case 0x0c058de6u: goto P_0c058de6;
case 0x0c058de8u: goto P_0c058de8;
case 0x0c058deau: goto P_0c058dea;
case 0x0c058decu: goto P_0c058dec;
case 0x0c058deeu: goto P_0c058dee;
case 0x0c058df0u: goto P_0c058df0;
case 0x0c058df2u: goto P_0c058df2;
case 0x0c058df4u: goto P_0c058df4;
case 0x0c058df6u: goto P_0c058df6;
case 0x0c058df8u: goto P_0c058df8;
case 0x0c058dfau: goto P_0c058dfa;
case 0x0c058dfcu: goto P_0c058dfc;
case 0x0c058dfeu: goto P_0c058dfe;
case 0x0c058e00u: goto P_0c058e00;
case 0x0c058e02u: goto P_0c058e02;
case 0x0c058e04u: goto P_0c058e04;
case 0x0c058e06u: goto P_0c058e06;
case 0x0c058e08u: goto P_0c058e08;
case 0x0c058e0au: goto P_0c058e0a;
case 0x0c058e0cu: goto P_0c058e0c;
case 0x0c058e0eu: goto P_0c058e0e;
case 0x0c058e10u: goto P_0c058e10;
case 0x0c058e12u: goto P_0c058e12;
case 0x0c058e14u: goto P_0c058e14;
case 0x0c058e16u: goto P_0c058e16;
case 0x0c058e18u: goto P_0c058e18;
case 0x0c060d28u: goto P_0c060d28;
case 0x0c060d2au: goto P_0c060d2a;
case 0x0c060d2cu: goto P_0c060d2c;
case 0x0c060d2eu: goto P_0c060d2e;
case 0x0c060d30u: goto P_0c060d30;
case 0x0c060d32u: goto P_0c060d32;
case 0x0c060d34u: goto P_0c060d34;
case 0x0c060d36u: goto P_0c060d36;
case 0x0c060d38u: goto P_0c060d38;
case 0x0c060d3au: goto P_0c060d3a;
case 0x0c060d3cu: goto P_0c060d3c;
case 0x0c060d3eu: goto P_0c060d3e;
case 0x0c060d40u: goto P_0c060d40;
case 0x0c060d42u: goto P_0c060d42;
case 0x0c060d44u: goto P_0c060d44;
case 0x0c062e8eu: goto P_0c062e8e;
case 0x0c062e90u: goto P_0c062e90;
case 0x0c062e92u: goto P_0c062e92;
case 0x0c0804f6u: goto P_0c0804f6;
case 0x0c0804f8u: goto P_0c0804f8;
case 0x0c0804fau: goto P_0c0804fa;
case 0x0c0804fcu: goto P_0c0804fc;
case 0x0c0804feu: goto P_0c0804fe;
case 0x0c080500u: goto P_0c080500;
case 0x0c080502u: goto P_0c080502;
case 0x0c080504u: goto P_0c080504;
case 0x0c080506u: goto P_0c080506;
case 0x0c080508u: goto P_0c080508;
case 0x0c08050au: goto P_0c08050a;
case 0x0c08050cu: goto P_0c08050c;
case 0x0c081d38u: goto P_0c081d38;
case 0x0c081d3au: goto P_0c081d3a;
case 0x0c081d3cu: goto P_0c081d3c;
case 0x0c081d3eu: goto P_0c081d3e;
case 0x0c081d40u: goto P_0c081d40;
case 0x0c081d42u: goto P_0c081d42;
case 0x0c081d44u: goto P_0c081d44;
case 0x0c081d46u: goto P_0c081d46;
case 0x0c081d48u: goto P_0c081d48;
case 0x0c081d4au: goto P_0c081d4a;
case 0x0c081d4cu: goto P_0c081d4c;
case 0x0c081d4eu: goto P_0c081d4e;
case 0x0c081d50u: goto P_0c081d50;
case 0x0c081d52u: goto P_0c081d52;
case 0x0c081d54u: goto P_0c081d54;
case 0x0c081d56u: goto P_0c081d56;
case 0x0c081d58u: goto P_0c081d58;
case 0x0c081d5au: goto P_0c081d5a;
case 0x0c081d5cu: goto P_0c081d5c;
case 0x0c081d5eu: goto P_0c081d5e;
case 0x0c081d60u: goto P_0c081d60;
case 0x0c081d62u: goto P_0c081d62;
case 0x0c081d64u: goto P_0c081d64;
case 0x0c081d66u: goto P_0c081d66;
case 0x0c081d68u: goto P_0c081d68;
case 0x0c081d6au: goto P_0c081d6a;
case 0x0c081d6cu: goto P_0c081d6c;
case 0x0c081d6eu: goto P_0c081d6e;
case 0x0c081d70u: goto P_0c081d70;
case 0x0c081d72u: goto P_0c081d72;
case 0x0c081d74u: goto P_0c081d74;
case 0x0c081d76u: goto P_0c081d76;
case 0x0c081d78u: goto P_0c081d78;
case 0x0c081d7au: goto P_0c081d7a;
case 0x0c081d7cu: goto P_0c081d7c;
case 0x0c081d7eu: goto P_0c081d7e;
case 0x0c081d80u: goto P_0c081d80;
case 0x0c081d82u: goto P_0c081d82;
case 0x0c081d84u: goto P_0c081d84;
case 0x0c081d86u: goto P_0c081d86;
case 0x0c081d88u: goto P_0c081d88;
case 0x0c081d8au: goto P_0c081d8a;
case 0x0c081d8cu: goto P_0c081d8c;
case 0x0c081d8eu: goto P_0c081d8e;
case 0x0c081d90u: goto P_0c081d90;
case 0x0c081d92u: goto P_0c081d92;
case 0x0c081d94u: goto P_0c081d94;
case 0x0c081d96u: goto P_0c081d96;
case 0x0c081d98u: goto P_0c081d98;
case 0x0c081d9au: goto P_0c081d9a;
case 0x0c081d9cu: goto P_0c081d9c;
case 0x0c081d9eu: goto P_0c081d9e;
case 0x0c081da0u: goto P_0c081da0;
case 0x0c081da2u: goto P_0c081da2;
case 0x0c081da4u: goto P_0c081da4;
case 0x0c081da6u: goto P_0c081da6;
case 0x0c081da8u: goto P_0c081da8;
case 0x0c081daau: goto P_0c081daa;
case 0x0c081dacu: goto P_0c081dac;
case 0x0c081daeu: goto P_0c081dae;
case 0x0c081db0u: goto P_0c081db0;
case 0x0c081db2u: goto P_0c081db2;
case 0x0c081db4u: goto P_0c081db4;
case 0x0c081db6u: goto P_0c081db6;
case 0x0c081db8u: goto P_0c081db8;
case 0x0c081dbau: goto P_0c081dba;
case 0x0c081dbcu: goto P_0c081dbc;
case 0x0c081dbeu: goto P_0c081dbe;
case 0x0c081dc0u: goto P_0c081dc0;
case 0x0c081dc2u: goto P_0c081dc2;
case 0x0c081dc4u: goto P_0c081dc4;
case 0x0c081dc6u: goto P_0c081dc6;
case 0x0c081dc8u: goto P_0c081dc8;
case 0x0c081dcau: goto P_0c081dca;
case 0x0c081dccu: goto P_0c081dcc;
case 0x0c081dceu: goto P_0c081dce;
case 0x0c081dd0u: goto P_0c081dd0;
case 0x0c081dd2u: goto P_0c081dd2;
case 0x0c081dd4u: goto P_0c081dd4;
case 0x0c081dd6u: goto P_0c081dd6;
case 0x0c081dd8u: goto P_0c081dd8;
case 0x0c081ddau: goto P_0c081dda;
case 0x0c081ddcu: goto P_0c081ddc;
case 0x0c081ddeu: goto P_0c081dde;
case 0x0c081de0u: goto P_0c081de0;
case 0x0c081de2u: goto P_0c081de2;
case 0x0c081de4u: goto P_0c081de4;
case 0x0c081de6u: goto P_0c081de6;
case 0x0c081de8u: goto P_0c081de8;
case 0x0c081deau: goto P_0c081dea;
case 0x0c081decu: goto P_0c081dec;
case 0x0c081deeu: goto P_0c081dee;
case 0x0c081df0u: goto P_0c081df0;
case 0x0c081df2u: goto P_0c081df2;
case 0x0c081df4u: goto P_0c081df4;
case 0x0c081df6u: goto P_0c081df6;
case 0x0c081df8u: goto P_0c081df8;
case 0x0c081dfau: goto P_0c081dfa;
case 0x0c081dfcu: goto P_0c081dfc;
case 0x0c081dfeu: goto P_0c081dfe;
case 0x0c081e00u: goto P_0c081e00;
case 0x0c081e02u: goto P_0c081e02;
case 0x0c081e04u: goto P_0c081e04;
case 0x0c081e06u: goto P_0c081e06;
case 0x0c081e08u: goto P_0c081e08;
case 0x0c081e0au: goto P_0c081e0a;
case 0x0c081e0cu: goto P_0c081e0c;
case 0x0c081e0eu: goto P_0c081e0e;
case 0x0c081e10u: goto P_0c081e10;
case 0x0c081e12u: goto P_0c081e12;
case 0x0c081e14u: goto P_0c081e14;
case 0x0c081e16u: goto P_0c081e16;
case 0x0c081e18u: goto P_0c081e18;
case 0x0c081e1au: goto P_0c081e1a;
case 0x0c081e1cu: goto P_0c081e1c;
case 0x0c081e1eu: goto P_0c081e1e;
case 0x0c081e20u: goto P_0c081e20;
case 0x0c081e22u: goto P_0c081e22;
case 0x0c081e24u: goto P_0c081e24;
case 0x0c081e26u: goto P_0c081e26;
case 0x0c081e28u: goto P_0c081e28;
case 0x0c081e2au: goto P_0c081e2a;
case 0x0c081e2cu: goto P_0c081e2c;
case 0x0c081e2eu: goto P_0c081e2e;
case 0x0c081e30u: goto P_0c081e30;
case 0x0c081e32u: goto P_0c081e32;
case 0x0c081e34u: goto P_0c081e34;
case 0x0c081e36u: goto P_0c081e36;
case 0x0c081e38u: goto P_0c081e38;
case 0x0c081e3au: goto P_0c081e3a;
case 0x0c081e3cu: goto P_0c081e3c;
case 0x0c081e3eu: goto P_0c081e3e;
case 0x0c083d70u: goto P_0c083d70;
case 0x0c083d72u: goto P_0c083d72;
case 0x0c083d74u: goto P_0c083d74;
case 0x0c083d76u: goto P_0c083d76;
case 0x0c083d78u: goto P_0c083d78;
case 0x0c083d7au: goto P_0c083d7a;
case 0x0c083d7cu: goto P_0c083d7c;
case 0x0c083d7eu: goto P_0c083d7e;
case 0x0c083d80u: goto P_0c083d80;
case 0x0c083d82u: goto P_0c083d82;
case 0x0c083d84u: goto P_0c083d84;
case 0x0c083d86u: goto P_0c083d86;
case 0x0c083d88u: goto P_0c083d88;
case 0x0c083d8au: goto P_0c083d8a;
case 0x0c083d8cu: goto P_0c083d8c;
case 0x0c083d8eu: goto P_0c083d8e;
case 0x0c083d90u: goto P_0c083d90;
case 0x0c083d92u: goto P_0c083d92;
case 0x0c083d94u: goto P_0c083d94;
case 0x0c083d96u: goto P_0c083d96;
case 0x0c083d98u: goto P_0c083d98;
case 0x0c083d9au: goto P_0c083d9a;
case 0x0c083d9cu: goto P_0c083d9c;
case 0x0c083d9eu: goto P_0c083d9e;
case 0x0c083da0u: goto P_0c083da0;
case 0x0c083da2u: goto P_0c083da2;
case 0x0c083da4u: goto P_0c083da4;
case 0x0c083da6u: goto P_0c083da6;
case 0x0c08935au: goto P_0c08935a;
case 0x0c08935cu: goto P_0c08935c;
case 0x0c08935eu: goto P_0c08935e;
case 0x0c089360u: goto P_0c089360;
case 0x0c089362u: goto P_0c089362;
case 0x0c089364u: goto P_0c089364;
case 0x0c089366u: goto P_0c089366;
case 0x0c089368u: goto P_0c089368;
case 0x0c08936au: goto P_0c08936a;
case 0x0c08936cu: goto P_0c08936c;
case 0x0c08936eu: goto P_0c08936e;
case 0x0c089370u: goto P_0c089370;
case 0x0c089372u: goto P_0c089372;
case 0x0c089374u: goto P_0c089374;
case 0x0c089376u: goto P_0c089376;
case 0x0c089378u: goto P_0c089378;
case 0x0c08937au: goto P_0c08937a;
case 0x0c08937cu: goto P_0c08937c;
case 0x0c08937eu: goto P_0c08937e;
case 0x0c089380u: goto P_0c089380;
case 0x0c089382u: goto P_0c089382;
case 0x0c089384u: goto P_0c089384;
case 0x0c089386u: goto P_0c089386;
case 0x0c089388u: goto P_0c089388;
case 0x0c08938au: goto P_0c08938a;
case 0x0c08938cu: goto P_0c08938c;
case 0x0c08938eu: goto P_0c08938e;
case 0x0c089390u: goto P_0c089390;
case 0x0c089392u: goto P_0c089392;
case 0x0c089394u: goto P_0c089394;
case 0x0c089396u: goto P_0c089396;
case 0x0c089398u: goto P_0c089398;
case 0x0c08939au: goto P_0c08939a;
case 0x0c08939cu: goto P_0c08939c;
case 0x0c08939eu: goto P_0c08939e;
case 0x0c0893a0u: goto P_0c0893a0;
case 0x0c0893a2u: goto P_0c0893a2;
case 0x0c0893a4u: goto P_0c0893a4;
case 0x0c0893a6u: goto P_0c0893a6;
case 0x0c0893a8u: goto P_0c0893a8;
case 0x0c0893aau: goto P_0c0893aa;
case 0x0c0893acu: goto P_0c0893ac;
case 0x0c0893aeu: goto P_0c0893ae;
case 0x0c0893b0u: goto P_0c0893b0;
case 0x0c0893b2u: goto P_0c0893b2;
case 0x0c0893b4u: goto P_0c0893b4;
case 0x0c0893b6u: goto P_0c0893b6;
case 0x0c0893b8u: goto P_0c0893b8;
case 0x0c0893bau: goto P_0c0893ba;
case 0x0c0893bcu: goto P_0c0893bc;
case 0x0c0893beu: goto P_0c0893be;
case 0x0c08a8e4u: goto P_0c08a8e4;
case 0x0c08a8e6u: goto P_0c08a8e6;
case 0x0c08a8e8u: goto P_0c08a8e8;
case 0x0c08a8eau: goto P_0c08a8ea;
case 0x0c08a8ecu: goto P_0c08a8ec;
case 0x0c08a8eeu: goto P_0c08a8ee;
case 0x0c08a8f0u: goto P_0c08a8f0;
case 0x0c08a8f2u: goto P_0c08a8f2;
case 0x0c08a8f4u: goto P_0c08a8f4;
case 0x0c08a8f6u: goto P_0c08a8f6;
case 0x0c08a8f8u: goto P_0c08a8f8;
case 0x0c08a8fau: goto P_0c08a8fa;
case 0x0c08a8fcu: goto P_0c08a8fc;
case 0x0c08a8feu: goto P_0c08a8fe;
case 0x0c08a900u: goto P_0c08a900;
case 0x0c08a902u: goto P_0c08a902;
case 0x0c08a904u: goto P_0c08a904;
case 0x0c08a906u: goto P_0c08a906;
case 0x0c08a908u: goto P_0c08a908;
case 0x0c08a90au: goto P_0c08a90a;
case 0x0c08a90cu: goto P_0c08a90c;
case 0x0c08a90eu: goto P_0c08a90e;
case 0x0c08a910u: goto P_0c08a910;
case 0x0c08a912u: goto P_0c08a912;
case 0x0c08a914u: goto P_0c08a914;
case 0x0c08a916u: goto P_0c08a916;
case 0x0c08a918u: goto P_0c08a918;
case 0x0c08a91au: goto P_0c08a91a;
case 0x0c08a91cu: goto P_0c08a91c;
case 0x0c08a91eu: goto P_0c08a91e;
case 0x0c08a920u: goto P_0c08a920;
case 0x0c08a922u: goto P_0c08a922;
case 0x0c08a924u: goto P_0c08a924;
case 0x0c08a926u: goto P_0c08a926;
case 0x0c08a928u: goto P_0c08a928;
case 0x0c08b528u: goto P_0c08b528;
case 0x0c08b52au: goto P_0c08b52a;
case 0x0c08b52cu: goto P_0c08b52c;
case 0x0c08b52eu: goto P_0c08b52e;
case 0x0c08b530u: goto P_0c08b530;
case 0x0c08b532u: goto P_0c08b532;
case 0x0c08b534u: goto P_0c08b534;
case 0x0c08b536u: goto P_0c08b536;
case 0x0c08b538u: goto P_0c08b538;
case 0x0c08b53au: goto P_0c08b53a;
case 0x0c08b53cu: goto P_0c08b53c;
case 0x0c08b53eu: goto P_0c08b53e;
case 0x0c08b540u: goto P_0c08b540;
case 0x0c08b542u: goto P_0c08b542;
case 0x0c096174u: goto P_0c096174;
case 0x0c096176u: goto P_0c096176;
case 0x0c096178u: goto P_0c096178;
case 0x0c09617au: goto P_0c09617a;
case 0x0c09617cu: goto P_0c09617c;
case 0x0c09617eu: goto P_0c09617e;
case 0x0c096180u: goto P_0c096180;
case 0x0c096182u: goto P_0c096182;
case 0x0c096184u: goto P_0c096184;
case 0x0c096186u: goto P_0c096186;
case 0x0c096188u: goto P_0c096188;
case 0x0c09618au: goto P_0c09618a;
case 0x0c09618cu: goto P_0c09618c;
case 0x0c09618eu: goto P_0c09618e;
case 0x0c096190u: goto P_0c096190;
case 0x0c096192u: goto P_0c096192;
case 0x0c096194u: goto P_0c096194;
case 0x0c096196u: goto P_0c096196;
case 0x0c096198u: goto P_0c096198;
case 0x0c09619au: goto P_0c09619a;
case 0x0c09619cu: goto P_0c09619c;
case 0x0c09619eu: goto P_0c09619e;
case 0x0c0961a0u: goto P_0c0961a0;
case 0x0c0961a2u: goto P_0c0961a2;
case 0x0c09caccu: goto P_0c09cacc;
case 0x0c09caceu: goto P_0c09cace;
case 0x0c09cad0u: goto P_0c09cad0;
case 0x0c09cad2u: goto P_0c09cad2;
case 0x0c09cad4u: goto P_0c09cad4;
case 0x0c09cad6u: goto P_0c09cad6;
case 0x0c09cad8u: goto P_0c09cad8;
case 0x0c09cadau: goto P_0c09cada;
case 0x0c09cadcu: goto P_0c09cadc;
case 0x0c09cadeu: goto P_0c09cade;
case 0x0c09cae0u: goto P_0c09cae0;
case 0x0c09cae2u: goto P_0c09cae2;
case 0x0c09cae4u: goto P_0c09cae4;
case 0x0c09cae6u: goto P_0c09cae6;
case 0x0c09cae8u: goto P_0c09cae8;
case 0x0c09caeau: goto P_0c09caea;
case 0x0c09caecu: goto P_0c09caec;
case 0x0c09caeeu: goto P_0c09caee;
case 0x0c09caf0u: goto P_0c09caf0;
case 0x0c09caf2u: goto P_0c09caf2;
case 0x0c09caf4u: goto P_0c09caf4;
case 0x0c09caf6u: goto P_0c09caf6;
case 0x0c09caf8u: goto P_0c09caf8;
case 0x0c09cafau: goto P_0c09cafa;
case 0x0c09cafcu: goto P_0c09cafc;
case 0x0c09cafeu: goto P_0c09cafe;
case 0x0c09cb00u: goto P_0c09cb00;
case 0x0c09cb02u: goto P_0c09cb02;
case 0x0c09cb04u: goto P_0c09cb04;
case 0x0c09cb06u: goto P_0c09cb06;
case 0x0c09cb08u: goto P_0c09cb08;
case 0x0c09cb0au: goto P_0c09cb0a;
case 0x0c09cb0cu: goto P_0c09cb0c;
case 0x0c09cb0eu: goto P_0c09cb0e;
case 0x0c09cb10u: goto P_0c09cb10;
case 0x0c09cb12u: goto P_0c09cb12;
case 0x0c09cb14u: goto P_0c09cb14;
case 0x0c09cb16u: goto P_0c09cb16;
case 0x0c09cb18u: goto P_0c09cb18;
case 0x0c09cb1au: goto P_0c09cb1a;
case 0x0c09cb1cu: goto P_0c09cb1c;
case 0x0c09cb1eu: goto P_0c09cb1e;
case 0x0c09cb20u: goto P_0c09cb20;
case 0x0c09cb22u: goto P_0c09cb22;
case 0x0c09cb24u: goto P_0c09cb24;
case 0x0c09cb26u: goto P_0c09cb26;
case 0x0c09cb28u: goto P_0c09cb28;
case 0x0c09cb2au: goto P_0c09cb2a;
case 0x0c09cb2cu: goto P_0c09cb2c;
case 0x0c09cb2eu: goto P_0c09cb2e;
case 0x0c09cb30u: goto P_0c09cb30;
case 0x0c09cb32u: goto P_0c09cb32;
case 0x0c09cb34u: goto P_0c09cb34;
case 0x0c09cb36u: goto P_0c09cb36;
case 0x0c09cb38u: goto P_0c09cb38;
case 0x0c09cb50u: goto P_0c09cb50;
case 0x0c09cb52u: goto P_0c09cb52;
case 0x0c09cb54u: goto P_0c09cb54;
case 0x0c09cb56u: goto P_0c09cb56;
case 0x0c09cb58u: goto P_0c09cb58;
case 0x0c09cb5au: goto P_0c09cb5a;
case 0x0c09cb5cu: goto P_0c09cb5c;
case 0x0c09cb5eu: goto P_0c09cb5e;
case 0x0c09cb60u: goto P_0c09cb60;
case 0x0c09cb62u: goto P_0c09cb62;
case 0x0c09cb64u: goto P_0c09cb64;
case 0x0c09cb66u: goto P_0c09cb66;
case 0x0c09cb68u: goto P_0c09cb68;
case 0x0c09cb6au: goto P_0c09cb6a;
case 0x0c09cb6cu: goto P_0c09cb6c;
case 0x0c09cb6eu: goto P_0c09cb6e;
case 0x0c09cb70u: goto P_0c09cb70;
case 0x0c09cb72u: goto P_0c09cb72;
case 0x0c09cb74u: goto P_0c09cb74;
case 0x0c09cb76u: goto P_0c09cb76;
case 0x0c09cb78u: goto P_0c09cb78;
case 0x0c09cb7au: goto P_0c09cb7a;
case 0x0c09cb7cu: goto P_0c09cb7c;
case 0x0c09cb7eu: goto P_0c09cb7e;
case 0x0c09cb80u: goto P_0c09cb80;
case 0x0c09cb82u: goto P_0c09cb82;
case 0x0c09cb84u: goto P_0c09cb84;
case 0x0c09cb86u: goto P_0c09cb86;
case 0x0c09cb88u: goto P_0c09cb88;
case 0x0c09cb8au: goto P_0c09cb8a;
case 0x0c09cb8cu: goto P_0c09cb8c;
case 0x0c09cb8eu: goto P_0c09cb8e;
case 0x0c09cb90u: goto P_0c09cb90;
case 0x0c09cb92u: goto P_0c09cb92;
case 0x0c09cb94u: goto P_0c09cb94;
case 0x0c09cb96u: goto P_0c09cb96;
case 0x0c09cb98u: goto P_0c09cb98;
case 0x0c09cb9au: goto P_0c09cb9a;
case 0x0c09cb9cu: goto P_0c09cb9c;
case 0x0c09cb9eu: goto P_0c09cb9e;
case 0x0c09cba0u: goto P_0c09cba0;
case 0x0c09cba2u: goto P_0c09cba2;
case 0x0c09cba4u: goto P_0c09cba4;
case 0x0c09cba6u: goto P_0c09cba6;
case 0x0c09cba8u: goto P_0c09cba8;
case 0x0c09cbaau: goto P_0c09cbaa;
case 0x0c09cbacu: goto P_0c09cbac;
case 0x0c09cbaeu: goto P_0c09cbae;
case 0x0c09cbb0u: goto P_0c09cbb0;
case 0x0c09cbb2u: goto P_0c09cbb2;
case 0x0c09cbb4u: goto P_0c09cbb4;
case 0x0c09cbb6u: goto P_0c09cbb6;
case 0x0c09cbb8u: goto P_0c09cbb8;
case 0x0c09cbbau: goto P_0c09cbba;
case 0x0c09cbbcu: goto P_0c09cbbc;
case 0x0c09cbbeu: goto P_0c09cbbe;
case 0x0c09cbc0u: goto P_0c09cbc0;
case 0x0c09cbc2u: goto P_0c09cbc2;
case 0x0c09cbc4u: goto P_0c09cbc4;
case 0x0c09cbc6u: goto P_0c09cbc6;
case 0x0c09cbc8u: goto P_0c09cbc8;
case 0x0c09cbcau: goto P_0c09cbca;
case 0x0c09cbccu: goto P_0c09cbcc;
case 0x0c09cbceu: goto P_0c09cbce;
case 0x0c09cbd0u: goto P_0c09cbd0;
case 0x0c09cbd2u: goto P_0c09cbd2;
case 0x0c09cbd4u: goto P_0c09cbd4;
case 0x0c09cbd6u: goto P_0c09cbd6;
case 0x0c09cbd8u: goto P_0c09cbd8;
case 0x0c09cbdau: goto P_0c09cbda;
case 0x0c09cbdcu: goto P_0c09cbdc;
case 0x0c09cbdeu: goto P_0c09cbde;
case 0x0c09cbe0u: goto P_0c09cbe0;
case 0x0c09cbe2u: goto P_0c09cbe2;
case 0x0c09cbe4u: goto P_0c09cbe4;
case 0x0c09cbe6u: goto P_0c09cbe6;
case 0x0c09cbe8u: goto P_0c09cbe8;
case 0x0c09cbeau: goto P_0c09cbea;
case 0x0c09cbecu: goto P_0c09cbec;
case 0x0c09cbeeu: goto P_0c09cbee;
case 0x0c09cbf0u: goto P_0c09cbf0;
case 0x0c09cbf2u: goto P_0c09cbf2;
case 0x0c09cbf4u: goto P_0c09cbf4;
case 0x0c09cbf6u: goto P_0c09cbf6;
case 0x0c09cbf8u: goto P_0c09cbf8;
case 0x0c09cbfau: goto P_0c09cbfa;
case 0x0c09cbfcu: goto P_0c09cbfc;
case 0x0c09cbfeu: goto P_0c09cbfe;
case 0x0c09cc00u: goto P_0c09cc00;
case 0x0c09cc02u: goto P_0c09cc02;
case 0x0c09cc04u: goto P_0c09cc04;
case 0x0c09cc06u: goto P_0c09cc06;
case 0x0c09cc08u: goto P_0c09cc08;
case 0x0c09cc0au: goto P_0c09cc0a;
case 0x0c09cc0cu: goto P_0c09cc0c;
case 0x0c09cc0eu: goto P_0c09cc0e;
case 0x0c09cc10u: goto P_0c09cc10;
case 0x0c09cc12u: goto P_0c09cc12;
case 0x0c09cc14u: goto P_0c09cc14;
case 0x0c09cc16u: goto P_0c09cc16;
case 0x0c09cc18u: goto P_0c09cc18;
case 0x0c09cc1au: goto P_0c09cc1a;
case 0x0c09cc1cu: goto P_0c09cc1c;
case 0x0c09cc1eu: goto P_0c09cc1e;
case 0x0c09cc30u: goto P_0c09cc30;
case 0x0c09cc32u: goto P_0c09cc32;
case 0x0c09cc34u: goto P_0c09cc34;
case 0x0c09cc36u: goto P_0c09cc36;
case 0x0c09cc38u: goto P_0c09cc38;
case 0x0c09cc3au: goto P_0c09cc3a;
case 0x0c09cc3cu: goto P_0c09cc3c;
case 0x0c09cc3eu: goto P_0c09cc3e;
case 0x0c09cc40u: goto P_0c09cc40;
case 0x0c09cc42u: goto P_0c09cc42;
case 0x0c09cc44u: goto P_0c09cc44;
case 0x0c09cc46u: goto P_0c09cc46;
case 0x0c09cc48u: goto P_0c09cc48;
case 0x0c09cc4au: goto P_0c09cc4a;
case 0x0c09cc4cu: goto P_0c09cc4c;
case 0x0c09cc4eu: goto P_0c09cc4e;
case 0x0c09cc50u: goto P_0c09cc50;
case 0x0c09cc52u: goto P_0c09cc52;
case 0x0c09cc54u: goto P_0c09cc54;
case 0x0c09cc56u: goto P_0c09cc56;
case 0x0c09cc58u: goto P_0c09cc58;
case 0x0c09cc5au: goto P_0c09cc5a;
case 0x0c09cc5cu: goto P_0c09cc5c;
case 0x0c09cc5eu: goto P_0c09cc5e;
case 0x0c09cc60u: goto P_0c09cc60;
case 0x0c09cc62u: goto P_0c09cc62;
case 0x0c09cc64u: goto P_0c09cc64;
case 0x0c09cc66u: goto P_0c09cc66;
case 0x0c09cc68u: goto P_0c09cc68;
case 0x0c09cc6au: goto P_0c09cc6a;
case 0x0c09cc6cu: goto P_0c09cc6c;
case 0x0c09cc6eu: goto P_0c09cc6e;
case 0x0c09cc70u: goto P_0c09cc70;
case 0x0c09cc72u: goto P_0c09cc72;
case 0x0c09cc74u: goto P_0c09cc74;
case 0x0c09cc76u: goto P_0c09cc76;
case 0x0c09cc78u: goto P_0c09cc78;
case 0x0c09cc7au: goto P_0c09cc7a;
case 0x0c09cc7cu: goto P_0c09cc7c;
case 0x0c09cc7eu: goto P_0c09cc7e;
case 0x0c09cc80u: goto P_0c09cc80;
case 0x0c09cc82u: goto P_0c09cc82;
case 0x0c09cc84u: goto P_0c09cc84;
case 0x0c09cc86u: goto P_0c09cc86;
case 0x0c09cc88u: goto P_0c09cc88;
case 0x0c09cc8au: goto P_0c09cc8a;
case 0x0c09cc8cu: goto P_0c09cc8c;
case 0x0c09cc8eu: goto P_0c09cc8e;
case 0x0c09cc90u: goto P_0c09cc90;
case 0x0c09cc92u: goto P_0c09cc92;
case 0x0c09cc94u: goto P_0c09cc94;
case 0x0c09cc96u: goto P_0c09cc96;
case 0x0c09cc98u: goto P_0c09cc98;
case 0x0c09cc9au: goto P_0c09cc9a;
case 0x0c09cc9cu: goto P_0c09cc9c;
case 0x0c09cc9eu: goto P_0c09cc9e;
case 0x0c09cca0u: goto P_0c09cca0;
case 0x0c09cca2u: goto P_0c09cca2;
case 0x0c09cca4u: goto P_0c09cca4;
case 0x0c09cca6u: goto P_0c09cca6;
case 0x0c09cca8u: goto P_0c09cca8;
case 0x0c09ccaau: goto P_0c09ccaa;
case 0x0c09ccacu: goto P_0c09ccac;
case 0x0c09ccaeu: goto P_0c09ccae;
case 0x0c09ccb0u: goto P_0c09ccb0;
case 0x0c09ccb2u: goto P_0c09ccb2;
case 0x0c09ccb4u: goto P_0c09ccb4;
case 0x0c09ccb6u: goto P_0c09ccb6;
case 0x0c09ccb8u: goto P_0c09ccb8;
case 0x0c09ccbau: goto P_0c09ccba;
case 0x0c09ccbcu: goto P_0c09ccbc;
case 0x0c09ccbeu: goto P_0c09ccbe;
case 0x0c09ccc0u: goto P_0c09ccc0;
case 0x0c09ccc2u: goto P_0c09ccc2;
case 0x0c09ccc4u: goto P_0c09ccc4;
case 0x0c09ccc6u: goto P_0c09ccc6;
case 0x0c09ccc8u: goto P_0c09ccc8;
case 0x0c09cccau: goto P_0c09ccca;
case 0x0c09ccccu: goto P_0c09cccc;
case 0x0c09ccceu: goto P_0c09ccce;
case 0x0c09ccd0u: goto P_0c09ccd0;
case 0x0c09ccd2u: goto P_0c09ccd2;
case 0x0c09ccd4u: goto P_0c09ccd4;
case 0x0c09ccd6u: goto P_0c09ccd6;
case 0x0c09ccd8u: goto P_0c09ccd8;
case 0x0c09ccdau: goto P_0c09ccda;
case 0x0c09ccdcu: goto P_0c09ccdc;
case 0x0c09ccdeu: goto P_0c09ccde;
case 0x0c09cce0u: goto P_0c09cce0;
case 0x0c09cce2u: goto P_0c09cce2;
case 0x0c09cce4u: goto P_0c09cce4;
case 0x0c09cce6u: goto P_0c09cce6;
case 0x0c09cce8u: goto P_0c09cce8;
case 0x0c09cceau: goto P_0c09ccea;
case 0x0c09ccecu: goto P_0c09ccec;
case 0x0c09cceeu: goto P_0c09ccee;
case 0x0c09ccf0u: goto P_0c09ccf0;
case 0x0c09ccf2u: goto P_0c09ccf2;
case 0x0c09ccf4u: goto P_0c09ccf4;
case 0x0c09ccf6u: goto P_0c09ccf6;
case 0x0c09ccf8u: goto P_0c09ccf8;
case 0x0c09ccfau: goto P_0c09ccfa;
case 0x0c09ccfcu: goto P_0c09ccfc;
case 0x0c09ccfeu: goto P_0c09ccfe;
case 0x0c09cd00u: goto P_0c09cd00;
case 0x0c09cd02u: goto P_0c09cd02;
case 0x0c09cd04u: goto P_0c09cd04;
case 0x0c09cd06u: goto P_0c09cd06;
case 0x0c09cd08u: goto P_0c09cd08;
case 0x0c09cd0au: goto P_0c09cd0a;
case 0x0c09cd0cu: goto P_0c09cd0c;
case 0x0c09cd0eu: goto P_0c09cd0e;
case 0x0c09cd10u: goto P_0c09cd10;
case 0x0c09cd12u: goto P_0c09cd12;
case 0x0c09cd38u: goto P_0c09cd38;
case 0x0c09cd3au: goto P_0c09cd3a;
case 0x0c09cd3cu: goto P_0c09cd3c;
case 0x0c09cd3eu: goto P_0c09cd3e;
case 0x0c09cd40u: goto P_0c09cd40;
case 0x0c09cd42u: goto P_0c09cd42;
case 0x0c09cd44u: goto P_0c09cd44;
case 0x0c09cd46u: goto P_0c09cd46;
case 0x0c09cd48u: goto P_0c09cd48;
case 0x0c09cd4au: goto P_0c09cd4a;
case 0x0c09cd4cu: goto P_0c09cd4c;
case 0x0c09cd4eu: goto P_0c09cd4e;
case 0x0c09cd50u: goto P_0c09cd50;
case 0x0c09cd52u: goto P_0c09cd52;
case 0x0c09cd54u: goto P_0c09cd54;
case 0x0c09cd56u: goto P_0c09cd56;
case 0x0c09cd58u: goto P_0c09cd58;
case 0x0c09cd5au: goto P_0c09cd5a;
case 0x0c09cd5cu: goto P_0c09cd5c;
case 0x0c09cd5eu: goto P_0c09cd5e;
case 0x0c09cd60u: goto P_0c09cd60;
case 0x0c09cd62u: goto P_0c09cd62;
case 0x0c09cd64u: goto P_0c09cd64;
case 0x0c09cd66u: goto P_0c09cd66;
case 0x0c09cd68u: goto P_0c09cd68;
case 0x0c09cd6au: goto P_0c09cd6a;
case 0x0c09cd6cu: goto P_0c09cd6c;
case 0x0c09cd6eu: goto P_0c09cd6e;
case 0x0c09cd70u: goto P_0c09cd70;
case 0x0c09cd72u: goto P_0c09cd72;
case 0x0c09cd74u: goto P_0c09cd74;
case 0x0c09cd76u: goto P_0c09cd76;
case 0x0c09cd78u: goto P_0c09cd78;
case 0x0c09cd7au: goto P_0c09cd7a;
case 0x0c09cd7cu: goto P_0c09cd7c;
case 0x0c09cd7eu: goto P_0c09cd7e;
case 0x0c09cd80u: goto P_0c09cd80;
case 0x0c09cd82u: goto P_0c09cd82;
case 0x0c09cd84u: goto P_0c09cd84;
case 0x0c09cd86u: goto P_0c09cd86;
case 0x0c09cd88u: goto P_0c09cd88;
case 0x0c09cd8au: goto P_0c09cd8a;
case 0x0c09cd8cu: goto P_0c09cd8c;
case 0x0c09cd8eu: goto P_0c09cd8e;
case 0x0c09cd90u: goto P_0c09cd90;
case 0x0c09cd92u: goto P_0c09cd92;
case 0x0c09cd94u: goto P_0c09cd94;
case 0x0c09cd96u: goto P_0c09cd96;
case 0x0c09cd98u: goto P_0c09cd98;
case 0x0c09cd9au: goto P_0c09cd9a;
case 0x0c09cd9cu: goto P_0c09cd9c;
case 0x0c09cd9eu: goto P_0c09cd9e;
case 0x0c09cda0u: goto P_0c09cda0;
case 0x0c09cda2u: goto P_0c09cda2;
case 0x0c09cda4u: goto P_0c09cda4;
case 0x0c09cda6u: goto P_0c09cda6;
case 0x0c09cda8u: goto P_0c09cda8;
case 0x0c09cdaau: goto P_0c09cdaa;
case 0x0c09cdacu: goto P_0c09cdac;
case 0x0c09cdaeu: goto P_0c09cdae;
case 0x0c09cdb0u: goto P_0c09cdb0;
case 0x0c09cdb2u: goto P_0c09cdb2;
case 0x0c09cdb4u: goto P_0c09cdb4;
case 0x0c09cdb6u: goto P_0c09cdb6;
case 0x0c09cdb8u: goto P_0c09cdb8;
case 0x0c09cdbau: goto P_0c09cdba;
case 0x0c09cdbcu: goto P_0c09cdbc;
case 0x0c09cdbeu: goto P_0c09cdbe;
case 0x0c09cdc0u: goto P_0c09cdc0;
case 0x0c09cdecu: goto P_0c09cdec;
case 0x0c09cdeeu: goto P_0c09cdee;
case 0x0c09cdf0u: goto P_0c09cdf0;
case 0x0c09cdf2u: goto P_0c09cdf2;
case 0x0c09cdf4u: goto P_0c09cdf4;
case 0x0c09cdf6u: goto P_0c09cdf6;
case 0x0c09cdf8u: goto P_0c09cdf8;
case 0x0c09cdfau: goto P_0c09cdfa;
case 0x0c09cdfcu: goto P_0c09cdfc;
case 0x0c09cdfeu: goto P_0c09cdfe;
case 0x0c09ce00u: goto P_0c09ce00;
case 0x0c09ce02u: goto P_0c09ce02;
case 0x0c09ce04u: goto P_0c09ce04;
case 0x0c09ce06u: goto P_0c09ce06;
case 0x0c09ce08u: goto P_0c09ce08;
case 0x0c09ce0au: goto P_0c09ce0a;
case 0x0c09ce0cu: goto P_0c09ce0c;
case 0x0c09ce0eu: goto P_0c09ce0e;
case 0x0c09ce10u: goto P_0c09ce10;
case 0x0c09ce12u: goto P_0c09ce12;
case 0x0c09ce14u: goto P_0c09ce14;
case 0x0c09ce16u: goto P_0c09ce16;
case 0x0c09ce18u: goto P_0c09ce18;
case 0x0c09ce1au: goto P_0c09ce1a;
case 0x0c09ce1cu: goto P_0c09ce1c;
case 0x0c09ce1eu: goto P_0c09ce1e;
case 0x0c09ce20u: goto P_0c09ce20;
case 0x0c09ce22u: goto P_0c09ce22;
case 0x0c09ce24u: goto P_0c09ce24;
case 0x0c09ce26u: goto P_0c09ce26;
case 0x0c09ce28u: goto P_0c09ce28;
case 0x0c09ce2au: goto P_0c09ce2a;
case 0x0c09ce2cu: goto P_0c09ce2c;
case 0x0c09ce2eu: goto P_0c09ce2e;
case 0x0c09ce30u: goto P_0c09ce30;
case 0x0c09ce32u: goto P_0c09ce32;
case 0x0c09ce34u: goto P_0c09ce34;
case 0x0c09ce36u: goto P_0c09ce36;
case 0x0c09ce38u: goto P_0c09ce38;
case 0x0c09ce3au: goto P_0c09ce3a;
case 0x0c09ce3cu: goto P_0c09ce3c;
case 0x0c09ce3eu: goto P_0c09ce3e;
case 0x0c09ce40u: goto P_0c09ce40;
case 0x0c09ce42u: goto P_0c09ce42;
case 0x0c09ce44u: goto P_0c09ce44;
case 0x0c09ce46u: goto P_0c09ce46;
case 0x0c09ce48u: goto P_0c09ce48;
case 0x0c09ce4cu: goto P_0c09ce4c;
case 0x0c09ce4eu: goto P_0c09ce4e;
case 0x0c09ce50u: goto P_0c09ce50;
case 0x0c09ce52u: goto P_0c09ce52;
case 0x0c09ce54u: goto P_0c09ce54;
case 0x0c09ce56u: goto P_0c09ce56;
case 0x0c09ce58u: goto P_0c09ce58;
case 0x0c09ce5au: goto P_0c09ce5a;
case 0x0c09ce5cu: goto P_0c09ce5c;
case 0x0c09ce5eu: goto P_0c09ce5e;
case 0x0c09ce60u: goto P_0c09ce60;
case 0x0c09ce62u: goto P_0c09ce62;
case 0x0c09ce64u: goto P_0c09ce64;
case 0x0c09ce66u: goto P_0c09ce66;
case 0x0c09ce68u: goto P_0c09ce68;
case 0x0c09ce6au: goto P_0c09ce6a;
case 0x0c09ce6cu: goto P_0c09ce6c;
case 0x0c09ce6eu: goto P_0c09ce6e;
case 0x0c09ce70u: goto P_0c09ce70;
case 0x0c09ce72u: goto P_0c09ce72;
case 0x0c09ce74u: goto P_0c09ce74;
case 0x0c09ce76u: goto P_0c09ce76;
case 0x0c09ce78u: goto P_0c09ce78;
case 0x0c09ce7au: goto P_0c09ce7a;
case 0x0c09ce7cu: goto P_0c09ce7c;
case 0x0c09cf60u: goto P_0c09cf60;
case 0x0c09cf62u: goto P_0c09cf62;
case 0x0c09cf64u: goto P_0c09cf64;
case 0x0c09cf66u: goto P_0c09cf66;
case 0x0c09cf68u: goto P_0c09cf68;
case 0x0c09cf6au: goto P_0c09cf6a;
case 0x0c09cf6cu: goto P_0c09cf6c;
case 0x0c09cf6eu: goto P_0c09cf6e;
case 0x0c09cf70u: goto P_0c09cf70;
case 0x0c09cf72u: goto P_0c09cf72;
case 0x0c09cf74u: goto P_0c09cf74;
case 0x0c09cf76u: goto P_0c09cf76;
case 0x0c09cf78u: goto P_0c09cf78;
case 0x0c09cf7au: goto P_0c09cf7a;
case 0x0c09cf7cu: goto P_0c09cf7c;
case 0x0c09cf7eu: goto P_0c09cf7e;
case 0x0c09cf80u: goto P_0c09cf80;
case 0x0c09cf82u: goto P_0c09cf82;
case 0x0c09cf84u: goto P_0c09cf84;
case 0x0c09cf86u: goto P_0c09cf86;
case 0x0c09cf88u: goto P_0c09cf88;
case 0x0c09cf8au: goto P_0c09cf8a;
case 0x0c09cf8cu: goto P_0c09cf8c;
case 0x0c09cf8eu: goto P_0c09cf8e;
case 0x0c09cf90u: goto P_0c09cf90;
case 0x0c0a9452u: goto P_0c0a9452;
case 0x0c0a9454u: goto P_0c0a9454;
case 0x0c0a9456u: goto P_0c0a9456;
case 0x0c0a9458u: goto P_0c0a9458;
case 0x0c0a945au: goto P_0c0a945a;
case 0x0c0a945cu: goto P_0c0a945c;
case 0x0c0a945eu: goto P_0c0a945e;
case 0x0c0a9460u: goto P_0c0a9460;
case 0x0c0a9462u: goto P_0c0a9462;
case 0x0c0a9464u: goto P_0c0a9464;
case 0x0c0a9466u: goto P_0c0a9466;
case 0x0c0a9468u: goto P_0c0a9468;
case 0x0c0a946au: goto P_0c0a946a;
case 0x0c0a946cu: goto P_0c0a946c;
case 0x0c0a946eu: goto P_0c0a946e;
case 0x0c0a9470u: goto P_0c0a9470;
case 0x0c0a9472u: goto P_0c0a9472;
case 0x0c0a9474u: goto P_0c0a9474;
case 0x0c0a9476u: goto P_0c0a9476;
case 0x0c0a9478u: goto P_0c0a9478;
case 0x0c0a947au: goto P_0c0a947a;
case 0x0c0a947cu: goto P_0c0a947c;
case 0x0c0a947eu: goto P_0c0a947e;
case 0x0c0a9480u: goto P_0c0a9480;
case 0x0c0a9482u: goto P_0c0a9482;
case 0x0c0a9484u: goto P_0c0a9484;
case 0x0c0a9486u: goto P_0c0a9486;
case 0x0c0a9488u: goto P_0c0a9488;
case 0x0c0a948au: goto P_0c0a948a;
case 0x0c0a948cu: goto P_0c0a948c;
case 0x0c0a948eu: goto P_0c0a948e;
case 0x0c0a9490u: goto P_0c0a9490;
case 0x0c0a9492u: goto P_0c0a9492;
case 0x0c0a9494u: goto P_0c0a9494;
case 0x0c0a9496u: goto P_0c0a9496;
case 0x0c0a9498u: goto P_0c0a9498;
case 0x0c0a949au: goto P_0c0a949a;
case 0x0c0a949cu: goto P_0c0a949c;
case 0x0c0a949eu: goto P_0c0a949e;
case 0x0c0a94a0u: goto P_0c0a94a0;
case 0x0c0a94a2u: goto P_0c0a94a2;
case 0x0c0a94a4u: goto P_0c0a94a4;
case 0x0c0c2c88u: goto P_0c0c2c88;
case 0x0c0c2c8au: goto P_0c0c2c8a;
case 0x0c0c2c8cu: goto P_0c0c2c8c;
case 0x0c0c2c8eu: goto P_0c0c2c8e;
case 0x0c0c2c90u: goto P_0c0c2c90;
case 0x0c0c2c92u: goto P_0c0c2c92;
case 0x0c0c2c94u: goto P_0c0c2c94;
case 0x0c0c2c96u: goto P_0c0c2c96;
case 0x0c0c2c98u: goto P_0c0c2c98;
case 0x0c0c2c9au: goto P_0c0c2c9a;
case 0x0c0c2c9cu: goto P_0c0c2c9c;
case 0x0c0c2c9eu: goto P_0c0c2c9e;
case 0x0c0c2ca0u: goto P_0c0c2ca0;
case 0x0c0c2ca2u: goto P_0c0c2ca2;
case 0x0c0c2ca4u: goto P_0c0c2ca4;
case 0x0c0c2ca6u: goto P_0c0c2ca6;
case 0x0c0c2ca8u: goto P_0c0c2ca8;
case 0x0c0c2caau: goto P_0c0c2caa;
case 0x0c0c2cacu: goto P_0c0c2cac;
case 0x0c0c2caeu: goto P_0c0c2cae;
case 0x0c0c2cb0u: goto P_0c0c2cb0;
case 0x0c0c2cb2u: goto P_0c0c2cb2;
case 0x0c0c2cb4u: goto P_0c0c2cb4;
case 0x0c0c2cb6u: goto P_0c0c2cb6;
case 0x0c0c2cb8u: goto P_0c0c2cb8;
case 0x0c0c2cbau: goto P_0c0c2cba;
case 0x0c0c2cbcu: goto P_0c0c2cbc;
case 0x0c0c2cbeu: goto P_0c0c2cbe;
case 0x0c0c2cc0u: goto P_0c0c2cc0;
case 0x0c0c2cc2u: goto P_0c0c2cc2;
case 0x0c0c2cc4u: goto P_0c0c2cc4;
case 0x0c0c2cc6u: goto P_0c0c2cc6;
case 0x0c0c2cc8u: goto P_0c0c2cc8;
case 0x0c0c426cu: goto P_0c0c426c;
case 0x0c0c426eu: goto P_0c0c426e;
case 0x0c0c4270u: goto P_0c0c4270;
case 0x0c0c4272u: goto P_0c0c4272;
case 0x0c0c4274u: goto P_0c0c4274;
case 0x0c0c4276u: goto P_0c0c4276;
case 0x0c0c4278u: goto P_0c0c4278;
case 0x0c0c427au: goto P_0c0c427a;
case 0x0c0c427cu: goto P_0c0c427c;
case 0x0c0c427eu: goto P_0c0c427e;
case 0x0c0c4280u: goto P_0c0c4280;
case 0x0c0c4282u: goto P_0c0c4282;
case 0x0c0c4284u: goto P_0c0c4284;
case 0x0c0c4286u: goto P_0c0c4286;
case 0x0c0c4288u: goto P_0c0c4288;
case 0x0c0c428au: goto P_0c0c428a;
case 0x0c0c428cu: goto P_0c0c428c;
case 0x0c0c428eu: goto P_0c0c428e;
case 0x0c0c4290u: goto P_0c0c4290;
case 0x0c0c4292u: goto P_0c0c4292;
case 0x0c0c4294u: goto P_0c0c4294;
case 0x0c0c4296u: goto P_0c0c4296;
case 0x0c0c4298u: goto P_0c0c4298;
case 0x0c0c429au: goto P_0c0c429a;
case 0x0c0c429cu: goto P_0c0c429c;
case 0x0c0c429eu: goto P_0c0c429e;
case 0x0c0c42a0u: goto P_0c0c42a0;
case 0x0c0c42a2u: goto P_0c0c42a2;
case 0x0c0c42a4u: goto P_0c0c42a4;
case 0x0c0c42a6u: goto P_0c0c42a6;
case 0x0c0c42a8u: goto P_0c0c42a8;
case 0x0c0c42aau: goto P_0c0c42aa;
case 0x0c0c42acu: goto P_0c0c42ac;
case 0x0c0c42aeu: goto P_0c0c42ae;
case 0x0c0c42b0u: goto P_0c0c42b0;
case 0x0c0c42b2u: goto P_0c0c42b2;
case 0x0c0c42b4u: goto P_0c0c42b4;
case 0x0c0c42b6u: goto P_0c0c42b6;
case 0x0c0c42b8u: goto P_0c0c42b8;
case 0x0c0c42bau: goto P_0c0c42ba;
case 0x0c0c42bcu: goto P_0c0c42bc;
case 0x0c0c42beu: goto P_0c0c42be;
case 0x0c0c42c0u: goto P_0c0c42c0;
case 0x0c0c42c2u: goto P_0c0c42c2;
case 0x0c0c42c4u: goto P_0c0c42c4;
case 0x0c0c42c6u: goto P_0c0c42c6;
case 0x0c0c42c8u: goto P_0c0c42c8;
case 0x0c0c42cau: goto P_0c0c42ca;
case 0x0c0c42ccu: goto P_0c0c42cc;
case 0x0c0c42ceu: goto P_0c0c42ce;
case 0x0c0c42d0u: goto P_0c0c42d0;
case 0x0c0c42d2u: goto P_0c0c42d2;
case 0x0c0c42d4u: goto P_0c0c42d4;
case 0x0c0c42d6u: goto P_0c0c42d6;
case 0x0c0c42d8u: goto P_0c0c42d8;
case 0x0c0c42dau: goto P_0c0c42da;
case 0x0c0c42dcu: goto P_0c0c42dc;
case 0x0c0c42deu: goto P_0c0c42de;
case 0x0c0c42e0u: goto P_0c0c42e0;
case 0x0c0c42e2u: goto P_0c0c42e2;
case 0x0c0c42e4u: goto P_0c0c42e4;
case 0x0c0c42e6u: goto P_0c0c42e6;
case 0x0c0c42e8u: goto P_0c0c42e8;
case 0x0c0c42eau: goto P_0c0c42ea;
case 0x0c0c82e6u: goto P_0c0c82e6;
case 0x0c0c82e8u: goto P_0c0c82e8;
case 0x0c0c82eau: goto P_0c0c82ea;
case 0x0c0c82ecu: goto P_0c0c82ec;
case 0x0c0c82eeu: goto P_0c0c82ee;
case 0x0c0c82f0u: goto P_0c0c82f0;
case 0x0c0c82f2u: goto P_0c0c82f2;
case 0x0c0c82f4u: goto P_0c0c82f4;
case 0x0c0c82f6u: goto P_0c0c82f6;
case 0x0c0c82f8u: goto P_0c0c82f8;
case 0x0c0c82fau: goto P_0c0c82fa;
case 0x0c0c82fcu: goto P_0c0c82fc;
case 0x0c0c82feu: goto P_0c0c82fe;
case 0x0c0c8300u: goto P_0c0c8300;
case 0x0c0c8302u: goto P_0c0c8302;
case 0x0c0c8304u: goto P_0c0c8304;
case 0x0c0c8306u: goto P_0c0c8306;
case 0x0c0c8308u: goto P_0c0c8308;
case 0x0c0c830au: goto P_0c0c830a;
case 0x0c0c830cu: goto P_0c0c830c;
case 0x0c0c830eu: goto P_0c0c830e;
case 0x0c0c8310u: goto P_0c0c8310;
case 0x0c0c8312u: goto P_0c0c8312;
case 0x0c0c8314u: goto P_0c0c8314;
case 0x0c0c8316u: goto P_0c0c8316;
case 0x0c0c8318u: goto P_0c0c8318;
case 0x0c0c831au: goto P_0c0c831a;
case 0x0c0c831cu: goto P_0c0c831c;
case 0x0c0c831eu: goto P_0c0c831e;
case 0x0c0c8320u: goto P_0c0c8320;
case 0x0c0c8322u: goto P_0c0c8322;
case 0x0c0c8324u: goto P_0c0c8324;
case 0x0c0c8326u: goto P_0c0c8326;
case 0x0c0c8328u: goto P_0c0c8328;
case 0x0c0c832au: goto P_0c0c832a;
case 0x0c0c832cu: goto P_0c0c832c;
case 0x0c0c832eu: goto P_0c0c832e;
case 0x0c0c8330u: goto P_0c0c8330;
case 0x0c0c8332u: goto P_0c0c8332;
case 0x0c0c8334u: goto P_0c0c8334;
case 0x0c0c8336u: goto P_0c0c8336;
case 0x0c0c8338u: goto P_0c0c8338;
case 0x0c0c833au: goto P_0c0c833a;
case 0x0c0c833cu: goto P_0c0c833c;
case 0x0c0c833eu: goto P_0c0c833e;
case 0x0c0c8340u: goto P_0c0c8340;
case 0x0c0c8342u: goto P_0c0c8342;
case 0x0c0c8344u: goto P_0c0c8344;
case 0x0c0c8346u: goto P_0c0c8346;
case 0x0c0c8348u: goto P_0c0c8348;
case 0x0c0c834au: goto P_0c0c834a;
case 0x0c0c834cu: goto P_0c0c834c;
case 0x0c0c834eu: goto P_0c0c834e;
case 0x0c0c8350u: goto P_0c0c8350;
case 0x0c0c8352u: goto P_0c0c8352;
case 0x0c0c8354u: goto P_0c0c8354;
case 0x0c0c8356u: goto P_0c0c8356;
case 0x0c0c8358u: goto P_0c0c8358;
case 0x0c0c835au: goto P_0c0c835a;
case 0x0c0c835cu: goto P_0c0c835c;
case 0x0c0c835eu: goto P_0c0c835e;
case 0x0c0c8394u: goto P_0c0c8394;
case 0x0c0c8396u: goto P_0c0c8396;
case 0x0c0c8398u: goto P_0c0c8398;
case 0x0c0c839au: goto P_0c0c839a;
case 0x0c0c839cu: goto P_0c0c839c;
case 0x0c0c839eu: goto P_0c0c839e;
case 0x0c0c83a0u: goto P_0c0c83a0;
case 0x0c0c83a2u: goto P_0c0c83a2;
case 0x0c0c83a4u: goto P_0c0c83a4;
case 0x0c0c83a6u: goto P_0c0c83a6;
case 0x0c0c83a8u: goto P_0c0c83a8;
case 0x0c0c83aau: goto P_0c0c83aa;
case 0x0c0c83acu: goto P_0c0c83ac;
case 0x0c0c83aeu: goto P_0c0c83ae;
case 0x0c0c83b0u: goto P_0c0c83b0;
case 0x0c0c83b2u: goto P_0c0c83b2;
case 0x0c0c83b4u: goto P_0c0c83b4;
case 0x0c0c83b6u: goto P_0c0c83b6;
case 0x0c0c83b8u: goto P_0c0c83b8;
case 0x0c0c83bau: goto P_0c0c83ba;
case 0x0c0c83bcu: goto P_0c0c83bc;
case 0x0c0c83beu: goto P_0c0c83be;
case 0x0c0c83c0u: goto P_0c0c83c0;
case 0x0c0c83c2u: goto P_0c0c83c2;
case 0x0c0c83c4u: goto P_0c0c83c4;
case 0x0c0c83c6u: goto P_0c0c83c6;
case 0x0c0c83c8u: goto P_0c0c83c8;
case 0x0c0c83cau: goto P_0c0c83ca;
case 0x0c0c83ccu: goto P_0c0c83cc;
case 0x0c0c83ceu: goto P_0c0c83ce;
case 0x0c0c83d0u: goto P_0c0c83d0;
case 0x0c0c83d2u: goto P_0c0c83d2;
case 0x0c0c83d4u: goto P_0c0c83d4;
case 0x0c0c83d6u: goto P_0c0c83d6;
case 0x0c0c83d8u: goto P_0c0c83d8;
case 0x0c0c83dau: goto P_0c0c83da;
case 0x0c0c83dcu: goto P_0c0c83dc;
case 0x0c0c83deu: goto P_0c0c83de;
case 0x0c0c83e0u: goto P_0c0c83e0;
case 0x0c0c83e2u: goto P_0c0c83e2;
case 0x0c0c83e4u: goto P_0c0c83e4;
case 0x0c0c83e6u: goto P_0c0c83e6;
case 0x0c0c83e8u: goto P_0c0c83e8;
case 0x0c0c83eau: goto P_0c0c83ea;
case 0x0c0c83ecu: goto P_0c0c83ec;
case 0x0c0c83eeu: goto P_0c0c83ee;
case 0x0c0c83f0u: goto P_0c0c83f0;
case 0x0c0c83f2u: goto P_0c0c83f2;
case 0x0c0c83f4u: goto P_0c0c83f4;
case 0x0c0c83f6u: goto P_0c0c83f6;
case 0x0c0c83f8u: goto P_0c0c83f8;
case 0x0c0c83fau: goto P_0c0c83fa;
case 0x0c0c83fcu: goto P_0c0c83fc;
case 0x0c0c83feu: goto P_0c0c83fe;
case 0x0c0c8400u: goto P_0c0c8400;
case 0x0c0c8402u: goto P_0c0c8402;
case 0x0c0c8404u: goto P_0c0c8404;
case 0x0c0c8406u: goto P_0c0c8406;
case 0x0c0c8408u: goto P_0c0c8408;
case 0x0c0c840au: goto P_0c0c840a;
case 0x0c0c840cu: goto P_0c0c840c;
case 0x0c0c840eu: goto P_0c0c840e;
case 0x0c0c8410u: goto P_0c0c8410;
case 0x0c0c8412u: goto P_0c0c8412;
case 0x0c0c8414u: goto P_0c0c8414;
case 0x0c0c8416u: goto P_0c0c8416;
case 0x0c0c8418u: goto P_0c0c8418;
case 0x0c0c841au: goto P_0c0c841a;
case 0x0c0c841cu: goto P_0c0c841c;
case 0x0c0c841eu: goto P_0c0c841e;
case 0x0c0c8420u: goto P_0c0c8420;
case 0x0c0c8422u: goto P_0c0c8422;
case 0x0c0c8424u: goto P_0c0c8424;
case 0x0c0c8426u: goto P_0c0c8426;
case 0x0c0c8428u: goto P_0c0c8428;
case 0x0c0c842au: goto P_0c0c842a;
case 0x0c0c842cu: goto P_0c0c842c;
case 0x0c0c842eu: goto P_0c0c842e;
case 0x0c0c8430u: goto P_0c0c8430;
case 0x0c0c8432u: goto P_0c0c8432;
case 0x0c0c8434u: goto P_0c0c8434;
case 0x0c0c8436u: goto P_0c0c8436;
case 0x0c0c8438u: goto P_0c0c8438;
case 0x0c0c843au: goto P_0c0c843a;
case 0x0c0c843cu: goto P_0c0c843c;
case 0x0c0c843eu: goto P_0c0c843e;
case 0x0c0c8440u: goto P_0c0c8440;
case 0x0c0c8442u: goto P_0c0c8442;
case 0x0c0c8444u: goto P_0c0c8444;
case 0x0c0c8446u: goto P_0c0c8446;
case 0x0c0c8448u: goto P_0c0c8448;
case 0x0c0c844au: goto P_0c0c844a;
case 0x0c0c844cu: goto P_0c0c844c;
case 0x0c0c844eu: goto P_0c0c844e;
case 0x0c0c8450u: goto P_0c0c8450;
case 0x0c0c8452u: goto P_0c0c8452;
case 0x0c0c8454u: goto P_0c0c8454;
case 0x0c0c8456u: goto P_0c0c8456;
case 0x0c0c8458u: goto P_0c0c8458;
case 0x0c0c845au: goto P_0c0c845a;
case 0x0c0c845cu: goto P_0c0c845c;
case 0x0c0c845eu: goto P_0c0c845e;
case 0x0c0c8460u: goto P_0c0c8460;
case 0x0c0c8462u: goto P_0c0c8462;
case 0x0c0c8464u: goto P_0c0c8464;
case 0x0c0c8466u: goto P_0c0c8466;
case 0x0c0c8468u: goto P_0c0c8468;
case 0x0c0c846au: goto P_0c0c846a;
case 0x0c0c846cu: goto P_0c0c846c;
case 0x0c0c846eu: goto P_0c0c846e;
case 0x0c0c8470u: goto P_0c0c8470;
case 0x0c0c8472u: goto P_0c0c8472;
case 0x0c0c8494u: goto P_0c0c8494;
case 0x0c0c8496u: goto P_0c0c8496;
case 0x0c0c8498u: goto P_0c0c8498;
case 0x0c0c849au: goto P_0c0c849a;
case 0x0c0c849cu: goto P_0c0c849c;
case 0x0c0c849eu: goto P_0c0c849e;
case 0x0c0c84a0u: goto P_0c0c84a0;
case 0x0c0c84a2u: goto P_0c0c84a2;
case 0x0c0c84a4u: goto P_0c0c84a4;
case 0x0c0c84a6u: goto P_0c0c84a6;
case 0x0c0c84a8u: goto P_0c0c84a8;
case 0x0c0c84aau: goto P_0c0c84aa;
case 0x0c0c84acu: goto P_0c0c84ac;
case 0x0c0c84aeu: goto P_0c0c84ae;
case 0x0c0c84b0u: goto P_0c0c84b0;
case 0x0c0c84b2u: goto P_0c0c84b2;
case 0x0c0c84b4u: goto P_0c0c84b4;
case 0x0c0c84b6u: goto P_0c0c84b6;
case 0x0c0c84b8u: goto P_0c0c84b8;
case 0x0c0c84bau: goto P_0c0c84ba;
case 0x0c0c84bcu: goto P_0c0c84bc;
case 0x0c0c84beu: goto P_0c0c84be;
case 0x0c0c84c0u: goto P_0c0c84c0;
case 0x0c0c84c2u: goto P_0c0c84c2;
case 0x0c0c84c4u: goto P_0c0c84c4;
case 0x0c0c84c6u: goto P_0c0c84c6;
case 0x0c0c84c8u: goto P_0c0c84c8;
case 0x0c0c84cau: goto P_0c0c84ca;
case 0x0c0c84ccu: goto P_0c0c84cc;
case 0x0c0c84ceu: goto P_0c0c84ce;
case 0x0c0c84d0u: goto P_0c0c84d0;
case 0x0c0c84d2u: goto P_0c0c84d2;
case 0x0c0c84d4u: goto P_0c0c84d4;
case 0x0c0c84d6u: goto P_0c0c84d6;
case 0x0c0c84d8u: goto P_0c0c84d8;
case 0x0c0c84dau: goto P_0c0c84da;
case 0x0c0c84dcu: goto P_0c0c84dc;
case 0x0c0c84deu: goto P_0c0c84de;
case 0x0c0c84e0u: goto P_0c0c84e0;
case 0x0c0c84e2u: goto P_0c0c84e2;
case 0x0c0c84e4u: goto P_0c0c84e4;
case 0x0c0c84e6u: goto P_0c0c84e6;
case 0x0c0c84e8u: goto P_0c0c84e8;
case 0x0c0c84eau: goto P_0c0c84ea;
case 0x0c0c84ecu: goto P_0c0c84ec;
case 0x0c0c84eeu: goto P_0c0c84ee;
case 0x0c0c84f0u: goto P_0c0c84f0;
case 0x0c0c84f2u: goto P_0c0c84f2;
case 0x0c0c84f4u: goto P_0c0c84f4;
case 0x0c0c84f6u: goto P_0c0c84f6;
case 0x0c0c84f8u: goto P_0c0c84f8;
case 0x0c0c84fau: goto P_0c0c84fa;
case 0x0c0c84fcu: goto P_0c0c84fc;
case 0x0c0c84feu: goto P_0c0c84fe;
case 0x0c0c8500u: goto P_0c0c8500;
case 0x0c0c8502u: goto P_0c0c8502;
case 0x0c0c8504u: goto P_0c0c8504;
case 0x0c0c8506u: goto P_0c0c8506;
case 0x0c0c8508u: goto P_0c0c8508;
case 0x0c0c850au: goto P_0c0c850a;
case 0x0c0c850cu: goto P_0c0c850c;
case 0x0c0c850eu: goto P_0c0c850e;
case 0x0c0c8510u: goto P_0c0c8510;
case 0x0c0c8512u: goto P_0c0c8512;
case 0x0c0c8514u: goto P_0c0c8514;
case 0x0c0c8516u: goto P_0c0c8516;
case 0x0c0c8518u: goto P_0c0c8518;
case 0x0c0c851au: goto P_0c0c851a;
case 0x0c0c851cu: goto P_0c0c851c;
case 0x0c0c851eu: goto P_0c0c851e;
case 0x0c0c8520u: goto P_0c0c8520;
case 0x0c0c8522u: goto P_0c0c8522;
case 0x0c0c8524u: goto P_0c0c8524;
case 0x0c0c8526u: goto P_0c0c8526;
case 0x0c0c8528u: goto P_0c0c8528;
case 0x0c0c852au: goto P_0c0c852a;
case 0x0c0c852cu: goto P_0c0c852c;
case 0x0c0c852eu: goto P_0c0c852e;
case 0x0c0c8530u: goto P_0c0c8530;
case 0x0c0c8532u: goto P_0c0c8532;
case 0x0c0c8534u: goto P_0c0c8534;
case 0x0c0c8536u: goto P_0c0c8536;
case 0x0c0c8538u: goto P_0c0c8538;
case 0x0c0c853au: goto P_0c0c853a;
case 0x0c0c853cu: goto P_0c0c853c;
case 0x0c0c853eu: goto P_0c0c853e;
case 0x0c0c8540u: goto P_0c0c8540;
case 0x0c0c8542u: goto P_0c0c8542;
case 0x0c0c8544u: goto P_0c0c8544;
case 0x0c0c8546u: goto P_0c0c8546;
case 0x0c0c8548u: goto P_0c0c8548;
case 0x0c0c854au: goto P_0c0c854a;
case 0x0c0c854cu: goto P_0c0c854c;
case 0x0c0c854eu: goto P_0c0c854e;
case 0x0c0c8550u: goto P_0c0c8550;
case 0x0c0c8552u: goto P_0c0c8552;
case 0x0c0c8554u: goto P_0c0c8554;
case 0x0c0c8574u: goto P_0c0c8574;
case 0x0c0c8576u: goto P_0c0c8576;
case 0x0c0c8578u: goto P_0c0c8578;
case 0x0c0c857au: goto P_0c0c857a;
case 0x0c0c857cu: goto P_0c0c857c;
case 0x0c0c857eu: goto P_0c0c857e;
case 0x0c0c8580u: goto P_0c0c8580;
case 0x0c0c8582u: goto P_0c0c8582;
case 0x0c0c8584u: goto P_0c0c8584;
case 0x0c0c8586u: goto P_0c0c8586;
case 0x0c0c8588u: goto P_0c0c8588;
case 0x0c0c858au: goto P_0c0c858a;
case 0x0c0c858cu: goto P_0c0c858c;
case 0x0c0c858eu: goto P_0c0c858e;
case 0x0c0c8590u: goto P_0c0c8590;
case 0x0c0c8592u: goto P_0c0c8592;
case 0x0c0c8594u: goto P_0c0c8594;
case 0x0c0c8596u: goto P_0c0c8596;
case 0x0c0c8598u: goto P_0c0c8598;
case 0x0c0c859au: goto P_0c0c859a;
case 0x0c0c859cu: goto P_0c0c859c;
case 0x0c0c859eu: goto P_0c0c859e;
case 0x0c0c85a0u: goto P_0c0c85a0;
case 0x0c0c85a2u: goto P_0c0c85a2;
case 0x0c0c85a4u: goto P_0c0c85a4;
case 0x0c0c85a6u: goto P_0c0c85a6;
case 0x0c0c85a8u: goto P_0c0c85a8;
case 0x0c0c85aau: goto P_0c0c85aa;
case 0x0c0c85acu: goto P_0c0c85ac;
case 0x0c0c85aeu: goto P_0c0c85ae;
case 0x0c0c85b0u: goto P_0c0c85b0;
case 0x0c0c85b2u: goto P_0c0c85b2;
case 0x0c0c85b4u: goto P_0c0c85b4;
case 0x0c0c85b6u: goto P_0c0c85b6;
case 0x0c0c85b8u: goto P_0c0c85b8;
case 0x0c0c85bau: goto P_0c0c85ba;
case 0x0c0c85bcu: goto P_0c0c85bc;
case 0x0c0c85beu: goto P_0c0c85be;
case 0x0c0c85c0u: goto P_0c0c85c0;
case 0x0c0c85c2u: goto P_0c0c85c2;
case 0x0c0c85c4u: goto P_0c0c85c4;
case 0x0c0c85c6u: goto P_0c0c85c6;
case 0x0c0c85c8u: goto P_0c0c85c8;
case 0x0c0c85cau: goto P_0c0c85ca;
case 0x0c0c85ccu: goto P_0c0c85cc;
case 0x0c0c85ceu: goto P_0c0c85ce;
case 0x0c0c85d0u: goto P_0c0c85d0;
case 0x0c0c85d2u: goto P_0c0c85d2;
case 0x0c0c85d4u: goto P_0c0c85d4;
case 0x0c0c85d6u: goto P_0c0c85d6;
case 0x0c0c85d8u: goto P_0c0c85d8;
case 0x0c0c85dau: goto P_0c0c85da;
case 0x0c0c85dcu: goto P_0c0c85dc;
case 0x0c0c85deu: goto P_0c0c85de;
case 0x0c0c85e0u: goto P_0c0c85e0;
case 0x0c0c85e2u: goto P_0c0c85e2;
case 0x0c0c85e4u: goto P_0c0c85e4;
case 0x0c0c85e6u: goto P_0c0c85e6;
case 0x0c0c85e8u: goto P_0c0c85e8;
case 0x0c0c85eau: goto P_0c0c85ea;
case 0x0c0c85ecu: goto P_0c0c85ec;
case 0x0c0c85eeu: goto P_0c0c85ee;
case 0x0c0c85f0u: goto P_0c0c85f0;
case 0x0c0c85f2u: goto P_0c0c85f2;
case 0x0c0c85f4u: goto P_0c0c85f4;
case 0x0c0c85f6u: goto P_0c0c85f6;
case 0x0c0c85f8u: goto P_0c0c85f8;
case 0x0c0c85fau: goto P_0c0c85fa;
case 0x0c0c85fcu: goto P_0c0c85fc;
case 0x0c0c85feu: goto P_0c0c85fe;
case 0x0c0c8600u: goto P_0c0c8600;
case 0x0c0c8602u: goto P_0c0c8602;
case 0x0c0c8604u: goto P_0c0c8604;
case 0x0c0c8606u: goto P_0c0c8606;
case 0x0c0c8608u: goto P_0c0c8608;
case 0x0c0c860au: goto P_0c0c860a;
case 0x0c0c860cu: goto P_0c0c860c;
case 0x0c0c860eu: goto P_0c0c860e;
case 0x0c0c8610u: goto P_0c0c8610;
case 0x0c0c8612u: goto P_0c0c8612;
case 0x0c0c8614u: goto P_0c0c8614;
case 0x0c0c8616u: goto P_0c0c8616;
case 0x0c0c8618u: goto P_0c0c8618;
case 0x0c0c861au: goto P_0c0c861a;
case 0x0c0c861cu: goto P_0c0c861c;
case 0x0c0c861eu: goto P_0c0c861e;
case 0x0c0c8620u: goto P_0c0c8620;
case 0x0c0c8622u: goto P_0c0c8622;
default: return vf3_matrix_family(target,s,ram);
}
P_0c034a02: /* original d311, guest PC 0x0c034a02 */
if(!s->budget--) { s->failed_pc=0x0c034a02u; return 0; }
r[3]=read(ram,0x0c034a48u,4);
goto P_0c034a04;
P_0c034a04: /* original 6632, guest PC 0x0c034a04 */
if(!s->budget--) { s->failed_pc=0x0c034a04u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c034a06;
P_0c034a06: /* original 566a, guest PC 0x0c034a06 */
if(!s->budget--) { s->failed_pc=0x0c034a06u; return 0; }
r[6]=read(ram,r[6]+40,4);
goto P_0c034a08;
P_0c034a08: /* original 2668, guest PC 0x0c034a08 */
if(!s->budget--) { s->failed_pc=0x0c034a08u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c034a0a;
P_0c034a0a: /* original e500, guest PC 0x0c034a0a */
if(!s->budget--) { s->failed_pc=0x0c034a0au; return 0; }
r[5]=0x00000000u;
goto P_0c034a0c;
P_0c034a0c: /* original 8d05, guest PC 0x0c034a0c */
if(!s->budget--) { s->failed_pc=0x0c034a0cu; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(cond) { goto P_0c034a1a; }
goto P_0c034a10;
P_0c034a0e: /* original 6453, guest PC 0x0c034a0e */
if(!s->budget--) { s->failed_pc=0x0c034a0eu; return 0; }
r[4]=r[5];
goto P_0c034a10;
P_0c034a10: /* original 516b, guest PC 0x0c034a10 */
if(!s->budget--) { s->failed_pc=0x0c034a10u; return 0; }
r[1]=read(ram,r[6]+44,4);
goto P_0c034a12;
P_0c034a12: /* original 2118, guest PC 0x0c034a12 */
if(!s->budget--) { s->failed_pc=0x0c034a12u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c034a14;
P_0c034a14: /* original 8901, guest PC 0x0c034a14 */
if(!s->budget--) { s->failed_pc=0x0c034a14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034a1a; }
goto P_0c034a16;
P_0c034a16: /* original 556c, guest PC 0x0c034a16 */
if(!s->budget--) { s->failed_pc=0x0c034a16u; return 0; }
r[5]=read(ram,r[6]+48,4);
goto P_0c034a18;
P_0c034a18: /* original 546b, guest PC 0x0c034a18 */
if(!s->budget--) { s->failed_pc=0x0c034a18u; return 0; }
r[4]=read(ram,r[6]+44,4);
goto P_0c034a1a;
P_0c034a1a: /* original d30f, guest PC 0x0c034a1a */
if(!s->budget--) { s->failed_pc=0x0c034a1au; return 0; }
r[3]=read(ram,0x0c034a58u,4);
goto P_0c034a1c;
P_0c034a1c: /* original 432b, guest PC 0x0c034a1c */
if(!s->budget--) { s->failed_pc=0x0c034a1cu; return 0; }
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
P_0c034a1e: /* original 0009, guest PC 0x0c034a1e */
if(!s->budget--) { s->failed_pc=0x0c034a1eu; return 0; }
return vf3_matrix_family(0x0c034a20u,s,ram);
P_0c03667e: /* original d241, guest PC 0x0c03667e */
if(!s->budget--) { s->failed_pc=0x0c03667eu; return 0; }
r[2]=read(ram,0x0c036784u,4);
goto P_0c036680;
P_0c036680: /* original 4428, guest PC 0x0c036680 */
if(!s->budget--) { s->failed_pc=0x0c036680u; return 0; }
r[4]<<=16;
goto P_0c036682;
P_0c036682: /* original 9073, guest PC 0x0c036682 */
if(!s->budget--) { s->failed_pc=0x0c036682u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03676cu,2);
goto P_0c036684;
P_0c036684: /* original 6322, guest PC 0x0c036684 */
if(!s->budget--) { s->failed_pc=0x0c036684u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c036686;
P_0c036686: /* original 000b, guest PC 0x0c036686 */
if(!s->budget--) { s->failed_pc=0x0c036686u; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c036688: /* original 0346, guest PC 0x0c036688 */
if(!s->budget--) { s->failed_pc=0x0c036688u; return 0; }
write(ram,r[3]+r[0],r[4],4);
return vf3_matrix_family(0x0c03668au,s,ram);
P_0c0366b2: /* original d234, guest PC 0x0c0366b2 */
if(!s->budget--) { s->failed_pc=0x0c0366b2u; return 0; }
r[2]=read(ram,0x0c036784u,4);
goto P_0c0366b4;
P_0c0366b4: /* original 905c, guest PC 0x0c0366b4 */
if(!s->budget--) { s->failed_pc=0x0c0366b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036770u,2);
goto P_0c0366b6;
P_0c0366b6: /* original 6322, guest PC 0x0c0366b6 */
if(!s->budget--) { s->failed_pc=0x0c0366b6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0366b8;
P_0c0366b8: /* original 000b, guest PC 0x0c0366b8 */
if(!s->budget--) { s->failed_pc=0x0c0366b8u; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c0366ba: /* original 0346, guest PC 0x0c0366ba */
if(!s->budget--) { s->failed_pc=0x0c0366bau; return 0; }
write(ram,r[3]+r[0],r[4],4);
return vf3_matrix_family(0x0c0366bcu,s,ram);
P_0c0366c6: /* original d22f, guest PC 0x0c0366c6 */
if(!s->budget--) { s->failed_pc=0x0c0366c6u; return 0; }
r[2]=read(ram,0x0c036784u,4);
goto P_0c0366c8;
P_0c0366c8: /* original 9053, guest PC 0x0c0366c8 */
if(!s->budget--) { s->failed_pc=0x0c0366c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036772u,2);
goto P_0c0366ca;
P_0c0366ca: /* original 6322, guest PC 0x0c0366ca */
if(!s->budget--) { s->failed_pc=0x0c0366cau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0366cc;
P_0c0366cc: /* original 000b, guest PC 0x0c0366cc */
if(!s->budget--) { s->failed_pc=0x0c0366ccu; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c0366ce: /* original 0346, guest PC 0x0c0366ce */
if(!s->budget--) { s->failed_pc=0x0c0366ceu; return 0; }
write(ram,r[3]+r[0],r[4],4);
return vf3_matrix_family(0x0c0366d0u,s,ram);
P_0c0366f2: /* original d224, guest PC 0x0c0366f2 */
if(!s->budget--) { s->failed_pc=0x0c0366f2u; return 0; }
r[2]=read(ram,0x0c036784u,4);
goto P_0c0366f4;
P_0c0366f4: /* original 903e, guest PC 0x0c0366f4 */
if(!s->budget--) { s->failed_pc=0x0c0366f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036774u,2);
goto P_0c0366f6;
P_0c0366f6: /* original 6322, guest PC 0x0c0366f6 */
if(!s->budget--) { s->failed_pc=0x0c0366f6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0366f8;
P_0c0366f8: /* original 000b, guest PC 0x0c0366f8 */
if(!s->budget--) { s->failed_pc=0x0c0366f8u; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c0366fa: /* original 0346, guest PC 0x0c0366fa */
if(!s->budget--) { s->failed_pc=0x0c0366fau; return 0; }
write(ram,r[3]+r[0],r[4],4);
return vf3_matrix_family(0x0c0366fcu,s,ram);
P_0c036706: /* original d21f, guest PC 0x0c036706 */
if(!s->budget--) { s->failed_pc=0x0c036706u; return 0; }
r[2]=read(ram,0x0c036784u,4);
goto P_0c036708;
P_0c036708: /* original 9035, guest PC 0x0c036708 */
if(!s->budget--) { s->failed_pc=0x0c036708u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036776u,2);
goto P_0c03670a;
P_0c03670a: /* original 6322, guest PC 0x0c03670a */
if(!s->budget--) { s->failed_pc=0x0c03670au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03670c;
P_0c03670c: /* original 000b, guest PC 0x0c03670c */
if(!s->budget--) { s->failed_pc=0x0c03670cu; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c03670e: /* original 0346, guest PC 0x0c03670e */
if(!s->budget--) { s->failed_pc=0x0c03670eu; return 0; }
write(ram,r[3]+r[0],r[4],4);
return vf3_matrix_family(0x0c036710u,s,ram);
P_0c03671a: /* original d51a, guest PC 0x0c03671a */
if(!s->budget--) { s->failed_pc=0x0c03671au; return 0; }
r[5]=read(ram,0x0c036784u,4);
goto P_0c03671c;
P_0c03671c: /* original 902c, guest PC 0x0c03671c */
if(!s->budget--) { s->failed_pc=0x0c03671cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036778u,2);
goto P_0c03671e;
P_0c03671e: /* original 6352, guest PC 0x0c03671e */
if(!s->budget--) { s->failed_pc=0x0c03671eu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c036720;
P_0c036720: /* original 0346, guest PC 0x0c036720 */
if(!s->budget--) { s->failed_pc=0x0c036720u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c036722;
P_0c036722: /* original 7004, guest PC 0x0c036722 */
if(!s->budget--) { s->failed_pc=0x0c036722u; return 0; }
r[0]+=0x00000004u;
goto P_0c036724;
P_0c036724: /* original 6352, guest PC 0x0c036724 */
if(!s->budget--) { s->failed_pc=0x0c036724u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c036726;
P_0c036726: /* original 000b, guest PC 0x0c036726 */
if(!s->budget--) { s->failed_pc=0x0c036726u; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c036728: /* original 0346, guest PC 0x0c036728 */
if(!s->budget--) { s->failed_pc=0x0c036728u; return 0; }
write(ram,r[3]+r[0],r[4],4);
return vf3_matrix_family(0x0c03672au,s,ram);
P_0c03673e: /* original d211, guest PC 0x0c03673e */
if(!s->budget--) { s->failed_pc=0x0c03673eu; return 0; }
r[2]=read(ram,0x0c036784u,4);
goto P_0c036740;
P_0c036740: /* original 901d, guest PC 0x0c036740 */
if(!s->budget--) { s->failed_pc=0x0c036740u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03677eu,2);
goto P_0c036742;
P_0c036742: /* original 6322, guest PC 0x0c036742 */
if(!s->budget--) { s->failed_pc=0x0c036742u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c036744;
P_0c036744: /* original 000b, guest PC 0x0c036744 */
if(!s->budget--) { s->failed_pc=0x0c036744u; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c036746: /* original 0346, guest PC 0x0c036746 */
if(!s->budget--) { s->failed_pc=0x0c036746u; return 0; }
write(ram,r[3]+r[0],r[4],4);
return vf3_matrix_family(0x0c036748u,s,ram);
P_0c036752: /* original d20c, guest PC 0x0c036752 */
if(!s->budget--) { s->failed_pc=0x0c036752u; return 0; }
r[2]=read(ram,0x0c036784u,4);
goto P_0c036754;
P_0c036754: /* original 9014, guest PC 0x0c036754 */
if(!s->budget--) { s->failed_pc=0x0c036754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036780u,2);
goto P_0c036756;
P_0c036756: /* original 6322, guest PC 0x0c036756 */
if(!s->budget--) { s->failed_pc=0x0c036756u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c036758;
P_0c036758: /* original 000b, guest PC 0x0c036758 */
if(!s->budget--) { s->failed_pc=0x0c036758u; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[4],4);
s->pc=target; return ram->oob==0;
P_0c03675a: /* original 0346, guest PC 0x0c03675a */
if(!s->budget--) { s->failed_pc=0x0c03675au; return 0; }
write(ram,r[3]+r[0],r[4],4);
return vf3_matrix_family(0x0c03675cu,s,ram);
P_0c038b4e: /* original 4f22, guest PC 0x0c038b4e */
if(!s->budget--) { s->failed_pc=0x0c038b4eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038b50;
P_0c038b50: /* original db31, guest PC 0x0c038b50 */
if(!s->budget--) { s->failed_pc=0x0c038b50u; return 0; }
r[11]=read(ram,0x0c038c18u,4);
goto P_0c038b52;
P_0c038b52: /* original da30, guest PC 0x0c038b52 */
if(!s->budget--) { s->failed_pc=0x0c038b52u; return 0; }
r[10]=read(ram,0x0c038c14u,4);
goto P_0c038b54;
P_0c038b54: /* original 6e32, guest PC 0x0c038b54 */
if(!s->budget--) { s->failed_pc=0x0c038b54u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c038b56;
P_0c038b56: /* original a00d, guest PC 0x0c038b56 */
if(!s->budget--) { s->failed_pc=0x0c038b56u; return 0; }
r[12]=r[13];
goto P_0c038b74;
P_0c038b58: /* original 6cd3, guest PC 0x0c038b58 */
if(!s->budget--) { s->failed_pc=0x0c038b58u; return 0; }
r[12]=r[13];
return vf3_matrix_family(0x0c038b5au,s,ram);
P_0c038b60: /* original 53eb, guest PC 0x0c038b60 */
if(!s->budget--) { s->failed_pc=0x0c038b60u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c038b62;
P_0c038b62: /* original 2338, guest PC 0x0c038b62 */
if(!s->budget--) { s->failed_pc=0x0c038b62u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c038b64;
P_0c038b64: /* original 8904, guest PC 0x0c038b64 */
if(!s->budget--) { s->failed_pc=0x0c038b64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c038b70; }
goto P_0c038b66;
P_0c038b66: /* original 53ea, guest PC 0x0c038b66 */
if(!s->budget--) { s->failed_pc=0x0c038b66u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c038b68;
P_0c038b68: /* original 2338, guest PC 0x0c038b68 */
if(!s->budget--) { s->failed_pc=0x0c038b68u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c038b6a;
P_0c038b6a: /* original 8b01, guest PC 0x0c038b6a */
if(!s->budget--) { s->failed_pc=0x0c038b6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038b70; }
goto P_0c038b6c;
P_0c038b6c: /* original 4a0b, guest PC 0x0c038b6c */
if(!s->budget--) { s->failed_pc=0x0c038b6cu; return 0; }
target=r[10];
r[16]=0x0c038b70u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038b70u) { target=s->pc; goto dispatch; }
goto P_0c038b70;
P_0c038b6e: /* original 64e3, guest PC 0x0c038b6e */
if(!s->budget--) { s->failed_pc=0x0c038b6eu; return 0; }
r[4]=r[14];
goto P_0c038b70;
P_0c038b70: /* original 7c01, guest PC 0x0c038b70 */
if(!s->budget--) { s->failed_pc=0x0c038b70u; return 0; }
r[12]+=0x00000001u;
goto P_0c038b72;
P_0c038b72: /* original 7e3c, guest PC 0x0c038b72 */
if(!s->budget--) { s->failed_pc=0x0c038b72u; return 0; }
r[14]+=0x0000003cu;
goto P_0c038b74;
P_0c038b74: /* original 63b2, guest PC 0x0c038b74 */
if(!s->budget--) { s->failed_pc=0x0c038b74u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c038b76;
P_0c038b76: /* original 3c33, guest PC 0x0c038b76 */
if(!s->budget--) { s->failed_pc=0x0c038b76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c038b78;
P_0c038b78: /* original 8bf2, guest PC 0x0c038b78 */
if(!s->budget--) { s->failed_pc=0x0c038b78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038b60; }
goto P_0c038b7a;
P_0c038b7a: /* original d124, guest PC 0x0c038b7a */
if(!s->budget--) { s->failed_pc=0x0c038b7au; return 0; }
r[1]=read(ram,0x0c038c0cu,4);
goto P_0c038b7c;
P_0c038b7c: /* original e5ff, guest PC 0x0c038b7c */
if(!s->budget--) { s->failed_pc=0x0c038b7cu; return 0; }
r[5]=0xffffffffu;
goto P_0c038b7e;
P_0c038b7e: /* original 6412, guest PC 0x0c038b7e */
if(!s->budget--) { s->failed_pc=0x0c038b7eu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c038b80;
P_0c038b80: /* original a00b, guest PC 0x0c038b80 */
if(!s->budget--) { s->failed_pc=0x0c038b80u; return 0; }
r[6]=r[13];
goto P_0c038b9a;
P_0c038b82: /* original 66d3, guest PC 0x0c038b82 */
if(!s->budget--) { s->failed_pc=0x0c038b82u; return 0; }
r[6]=r[13];
return vf3_matrix_family(0x0c038b84u,s,ram);
P_0c038b90: /* original 145a, guest PC 0x0c038b90 */
if(!s->budget--) { s->failed_pc=0x0c038b90u; return 0; }
write(ram,r[4]+40,r[5],4);
goto P_0c038b92;
P_0c038b92: /* original 7601, guest PC 0x0c038b92 */
if(!s->budget--) { s->failed_pc=0x0c038b92u; return 0; }
r[6]+=0x00000001u;
goto P_0c038b94;
P_0c038b94: /* original 14db, guest PC 0x0c038b94 */
if(!s->budget--) { s->failed_pc=0x0c038b94u; return 0; }
write(ram,r[4]+44,r[13],4);
goto P_0c038b96;
P_0c038b96: /* original 145e, guest PC 0x0c038b96 */
if(!s->budget--) { s->failed_pc=0x0c038b96u; return 0; }
write(ram,r[4]+56,r[5],4);
goto P_0c038b98;
P_0c038b98: /* original 743c, guest PC 0x0c038b98 */
if(!s->budget--) { s->failed_pc=0x0c038b98u; return 0; }
r[4]+=0x0000003cu;
goto P_0c038b9a;
P_0c038b9a: /* original 62b2, guest PC 0x0c038b9a */
if(!s->budget--) { s->failed_pc=0x0c038b9au; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c038b9c;
P_0c038b9c: /* original 3623, guest PC 0x0c038b9c */
if(!s->budget--) { s->failed_pc=0x0c038b9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[2])!=0);
goto P_0c038b9e;
P_0c038b9e: /* original 8bf7, guest PC 0x0c038b9e */
if(!s->budget--) { s->failed_pc=0x0c038b9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038b90; }
goto P_0c038ba0;
P_0c038ba0: /* original 4f26, guest PC 0x0c038ba0 */
if(!s->budget--) { s->failed_pc=0x0c038ba0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038ba2;
P_0c038ba2: /* original d11e, guest PC 0x0c038ba2 */
if(!s->budget--) { s->failed_pc=0x0c038ba2u; return 0; }
r[1]=read(ram,0x0c038c1cu,4);
goto P_0c038ba4;
P_0c038ba4: /* original 21d2, guest PC 0x0c038ba4 */
if(!s->budget--) { s->failed_pc=0x0c038ba4u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c038ba6;
P_0c038ba6: /* original d31e, guest PC 0x0c038ba6 */
if(!s->budget--) { s->failed_pc=0x0c038ba6u; return 0; }
r[3]=read(ram,0x0c038c20u,4);
goto P_0c038ba8;
P_0c038ba8: /* original 23d2, guest PC 0x0c038ba8 */
if(!s->budget--) { s->failed_pc=0x0c038ba8u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c038baa;
P_0c038baa: /* original 6af6, guest PC 0x0c038baa */
if(!s->budget--) { s->failed_pc=0x0c038baau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c038bac;
P_0c038bac: /* original 6bf6, guest PC 0x0c038bac */
if(!s->budget--) { s->failed_pc=0x0c038bacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c038bae;
P_0c038bae: /* original 6cf6, guest PC 0x0c038bae */
if(!s->budget--) { s->failed_pc=0x0c038baeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c038bb0;
P_0c038bb0: /* original 6df6, guest PC 0x0c038bb0 */
if(!s->budget--) { s->failed_pc=0x0c038bb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c038bb2;
P_0c038bb2: /* original 000b, guest PC 0x0c038bb2 */
if(!s->budget--) { s->failed_pc=0x0c038bb2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c038bb4: /* original 6ef6, guest PC 0x0c038bb4 */
if(!s->budget--) { s->failed_pc=0x0c038bb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c038bb6u,s,ram);
P_0c03a190: /* original c727, guest PC 0x0c03a190 */
if(!s->budget--) { s->failed_pc=0x0c03a190u; return 0; }
r[0]=0x0c03a230u;
goto P_0c03a192;
P_0c03a192: /* original 7ffc, guest PC 0x0c03a192 */
if(!s->budget--) { s->failed_pc=0x0c03a192u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03a194;
P_0c03a194: /* original ff4a, guest PC 0x0c03a194 */
if(!s->budget--) { s->failed_pc=0x0c03a194u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03a196;
P_0c03a196: /* original f34c, guest PC 0x0c03a196 */
if(!s->budget--) { s->failed_pc=0x0c03a196u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a198;
P_0c03a198: /* original f35d, guest PC 0x0c03a198 */
if(!s->budget--) { s->failed_pc=0x0c03a198u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c03a19a;
P_0c03a19a: /* original f208, guest PC 0x0c03a19a */
if(!s->budget--) { s->failed_pc=0x0c03a19au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a19c;
P_0c03a19c: /* original f34d, guest PC 0x0c03a19c */
if(!s->budget--) { s->failed_pc=0x0c03a19cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c03a19e;
P_0c03a19e: /* original f43c, guest PC 0x0c03a19e */
if(!s->budget--) { s->failed_pc=0x0c03a19eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a1a0;
P_0c03a1a0: /* original f420, guest PC 0x0c03a1a0 */
if(!s->budget--) { s->failed_pc=0x0c03a1a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c03a1a2;
P_0c03a1a2: /* original a30d, guest PC 0x0c03a1a2 */
if(!s->budget--) { s->failed_pc=0x0c03a1a2u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c03a7c0u,s,ram);
P_0c03a1a4: /* original 7f04, guest PC 0x0c03a1a4 */
if(!s->budget--) { s->failed_pc=0x0c03a1a4u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c03a1a6u,s,ram);
P_0c03c6f0: /* original f15c, guest PC 0x0c03c6f0 */
if(!s->budget--) { s->failed_pc=0x0c03c6f0u; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c03c6f2;
P_0c03c6f2: /* original f24c, guest PC 0x0c03c6f2 */
if(!s->budget--) { s->failed_pc=0x0c03c6f2u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03c6f4;
P_0c03c6f4: /* original f08d, guest PC 0x0c03c6f4 */
if(!s->budget--) { s->failed_pc=0x0c03c6f4u; return 0; }
fr[0]=0;
goto P_0c03c6f6;
P_0c03c6f6: /* original f38d, guest PC 0x0c03c6f6 */
if(!s->budget--) { s->failed_pc=0x0c03c6f6u; return 0; }
fr[3]=0;
goto P_0c03c6f8;
P_0c03c6f8: /* original f65c, guest PC 0x0c03c6f8 */
if(!s->budget--) { s->failed_pc=0x0c03c6f8u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c03c6fa;
P_0c03c6fa: /* original f54c, guest PC 0x0c03c6fa */
if(!s->budget--) { s->failed_pc=0x0c03c6fau; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c03c6fc;
P_0c03c6fc: /* original f54d, guest PC 0x0c03c6fc */
if(!s->budget--) { s->failed_pc=0x0c03c6fcu; return 0; }
fr[5]^=0x80000000u;
goto P_0c03c6fe;
P_0c03c6fe: /* original f1fd, guest PC 0x0c03c6fe */
if(!s->budget--) { s->failed_pc=0x0c03c6feu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03c700;
P_0c03c700: /* original f48d, guest PC 0x0c03c700 */
if(!s->budget--) { s->failed_pc=0x0c03c700u; return 0; }
fr[4]=0;
goto P_0c03c702;
P_0c03c702: /* original f78d, guest PC 0x0c03c702 */
if(!s->budget--) { s->failed_pc=0x0c03c702u; return 0; }
fr[7]=0;
goto P_0c03c704;
P_0c03c704: /* original f5fd, guest PC 0x0c03c704 */
if(!s->budget--) { s->failed_pc=0x0c03c704u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03c706;
P_0c03c706: /* original f3fd, guest PC 0x0c03c706 */
if(!s->budget--) { s->failed_pc=0x0c03c706u; return 0; }
r[18]^=0x100000u;
goto P_0c03c708;
P_0c03c708: /* original f50c, guest PC 0x0c03c708 */
if(!s->budget--) { s->failed_pc=0x0c03c708u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c03c70a;
P_0c03c70a: /* original f72c, guest PC 0x0c03c70a */
if(!s->budget--) { s->failed_pc=0x0c03c70au; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c03c70c;
P_0c03c70c: /* original f94c, guest PC 0x0c03c70c */
if(!s->budget--) { s->failed_pc=0x0c03c70cu; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c03c70e;
P_0c03c70e: /* original fb6c, guest PC 0x0c03c70e */
if(!s->budget--) { s->failed_pc=0x0c03c70eu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c03c710;
P_0c03c710: /* original f3fd, guest PC 0x0c03c710 */
if(!s->budget--) { s->failed_pc=0x0c03c710u; return 0; }
r[18]^=0x100000u;
goto P_0c03c712;
P_0c03c712: /* original 0009, guest PC 0x0c03c712 */
if(!s->budget--) { s->failed_pc=0x0c03c712u; return 0; }
goto P_0c03c714;
P_0c03c714: /* original 000b, guest PC 0x0c03c714 */
if(!s->budget--) { s->failed_pc=0x0c03c714u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c716: /* original 0009, guest PC 0x0c03c716 */
if(!s->budget--) { s->failed_pc=0x0c03c716u; return 0; }
return vf3_matrix_family(0x0c03c718u,s,ram);
P_0c03c850: /* original f15c, guest PC 0x0c03c850 */
if(!s->budget--) { s->failed_pc=0x0c03c850u; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c03c852;
P_0c03c852: /* original f24c, guest PC 0x0c03c852 */
if(!s->budget--) { s->failed_pc=0x0c03c852u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03c854;
P_0c03c854: /* original f08d, guest PC 0x0c03c854 */
if(!s->budget--) { s->failed_pc=0x0c03c854u; return 0; }
fr[0]=0;
goto P_0c03c856;
P_0c03c856: /* original f38d, guest PC 0x0c03c856 */
if(!s->budget--) { s->failed_pc=0x0c03c856u; return 0; }
fr[3]=0;
goto P_0c03c858;
P_0c03c858: /* original f65c, guest PC 0x0c03c858 */
if(!s->budget--) { s->failed_pc=0x0c03c858u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c03c85a;
P_0c03c85a: /* original f54c, guest PC 0x0c03c85a */
if(!s->budget--) { s->failed_pc=0x0c03c85au; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c03c85c;
P_0c03c85c: /* original f1fd, guest PC 0x0c03c85c */
if(!s->budget--) { s->failed_pc=0x0c03c85cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03c85e;
P_0c03c85e: /* original f48d, guest PC 0x0c03c85e */
if(!s->budget--) { s->failed_pc=0x0c03c85eu; return 0; }
fr[4]=0;
goto P_0c03c860;
P_0c03c860: /* original f78d, guest PC 0x0c03c860 */
if(!s->budget--) { s->failed_pc=0x0c03c860u; return 0; }
fr[7]=0;
goto P_0c03c862;
P_0c03c862: /* original f5fd, guest PC 0x0c03c862 */
if(!s->budget--) { s->failed_pc=0x0c03c862u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03c864;
P_0c03c864: /* original f3fd, guest PC 0x0c03c864 */
if(!s->budget--) { s->failed_pc=0x0c03c864u; return 0; }
r[18]^=0x100000u;
goto P_0c03c866;
P_0c03c866: /* original f50c, guest PC 0x0c03c866 */
if(!s->budget--) { s->failed_pc=0x0c03c866u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c03c868;
P_0c03c868: /* original f72c, guest PC 0x0c03c868 */
if(!s->budget--) { s->failed_pc=0x0c03c868u; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c03c86a;
P_0c03c86a: /* original f94c, guest PC 0x0c03c86a */
if(!s->budget--) { s->failed_pc=0x0c03c86au; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c03c86c;
P_0c03c86c: /* original fb6c, guest PC 0x0c03c86c */
if(!s->budget--) { s->failed_pc=0x0c03c86cu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c03c86e;
P_0c03c86e: /* original f3fd, guest PC 0x0c03c86e */
if(!s->budget--) { s->failed_pc=0x0c03c86eu; return 0; }
r[18]^=0x100000u;
goto P_0c03c870;
P_0c03c870: /* original 000b, guest PC 0x0c03c870 */
if(!s->budget--) { s->failed_pc=0x0c03c870u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c872: /* original 0009, guest PC 0x0c03c872 */
if(!s->budget--) { s->failed_pc=0x0c03c872u; return 0; }
return vf3_matrix_family(0x0c03c874u,s,ram);
P_0c03c910: /* original f05c, guest PC 0x0c03c910 */
if(!s->budget--) { s->failed_pc=0x0c03c910u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03c912;
P_0c03c912: /* original f24c, guest PC 0x0c03c912 */
if(!s->budget--) { s->failed_pc=0x0c03c912u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03c914;
P_0c03c914: /* original f44d, guest PC 0x0c03c914 */
if(!s->budget--) { s->failed_pc=0x0c03c914u; return 0; }
fr[4]^=0x80000000u;
goto P_0c03c916;
P_0c03c916: /* original f60c, guest PC 0x0c03c916 */
if(!s->budget--) { s->failed_pc=0x0c03c916u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c03c918;
P_0c03c918: /* original f18d, guest PC 0x0c03c918 */
if(!s->budget--) { s->failed_pc=0x0c03c918u; return 0; }
fr[1]=0;
goto P_0c03c91a;
P_0c03c91a: /* original f38d, guest PC 0x0c03c91a */
if(!s->budget--) { s->failed_pc=0x0c03c91au; return 0; }
fr[3]=0;
goto P_0c03c91c;
P_0c03c91c: /* original f1fd, guest PC 0x0c03c91c */
if(!s->budget--) { s->failed_pc=0x0c03c91cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03c91e;
P_0c03c91e: /* original f58d, guest PC 0x0c03c91e */
if(!s->budget--) { s->failed_pc=0x0c03c91eu; return 0; }
fr[5]=0;
goto P_0c03c920;
P_0c03c920: /* original f78d, guest PC 0x0c03c920 */
if(!s->budget--) { s->failed_pc=0x0c03c920u; return 0; }
fr[7]=0;
goto P_0c03c922;
P_0c03c922: /* original f5fd, guest PC 0x0c03c922 */
if(!s->budget--) { s->failed_pc=0x0c03c922u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03c924;
P_0c03c924: /* original f3fd, guest PC 0x0c03c924 */
if(!s->budget--) { s->failed_pc=0x0c03c924u; return 0; }
r[18]^=0x100000u;
goto P_0c03c926;
P_0c03c926: /* original f10c, guest PC 0x0c03c926 */
if(!s->budget--) { s->failed_pc=0x0c03c926u; return 0; }
vf3_matrix_move(s,1,0);
goto P_0c03c928;
P_0c03c928: /* original f32c, guest PC 0x0c03c928 */
if(!s->budget--) { s->failed_pc=0x0c03c928u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c03c92a;
P_0c03c92a: /* original f94c, guest PC 0x0c03c92a */
if(!s->budget--) { s->failed_pc=0x0c03c92au; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c03c92c;
P_0c03c92c: /* original fb6c, guest PC 0x0c03c92c */
if(!s->budget--) { s->failed_pc=0x0c03c92cu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c03c92e;
P_0c03c92e: /* original f3fd, guest PC 0x0c03c92e */
if(!s->budget--) { s->failed_pc=0x0c03c92eu; return 0; }
r[18]^=0x100000u;
goto P_0c03c930;
P_0c03c930: /* original 000b, guest PC 0x0c03c930 */
if(!s->budget--) { s->failed_pc=0x0c03c930u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c932: /* original 0009, guest PC 0x0c03c932 */
if(!s->budget--) { s->failed_pc=0x0c03c932u; return 0; }
return vf3_matrix_family(0x0c03c934u,s,ram);
P_0c03c9d0: /* original f14c, guest PC 0x0c03c9d0 */
if(!s->budget--) { s->failed_pc=0x0c03c9d0u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03c9d2;
P_0c03c9d2: /* original f14d, guest PC 0x0c03c9d2 */
if(!s->budget--) { s->failed_pc=0x0c03c9d2u; return 0; }
fr[1]^=0x80000000u;
goto P_0c03c9d4;
P_0c03c9d4: /* original f05c, guest PC 0x0c03c9d4 */
if(!s->budget--) { s->failed_pc=0x0c03c9d4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03c9d6;
P_0c03c9d6: /* original f28d, guest PC 0x0c03c9d6 */
if(!s->budget--) { s->failed_pc=0x0c03c9d6u; return 0; }
fr[2]=0;
goto P_0c03c9d8;
P_0c03c9d8: /* original f38d, guest PC 0x0c03c9d8 */
if(!s->budget--) { s->failed_pc=0x0c03c9d8u; return 0; }
fr[3]=0;
goto P_0c03c9da;
P_0c03c9da: /* original f1fd, guest PC 0x0c03c9da */
if(!s->budget--) { s->failed_pc=0x0c03c9dau; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03c9dc;
P_0c03c9dc: /* original f68d, guest PC 0x0c03c9dc */
if(!s->budget--) { s->failed_pc=0x0c03c9dcu; return 0; }
fr[6]=0;
goto P_0c03c9de;
P_0c03c9de: /* original f78d, guest PC 0x0c03c9de */
if(!s->budget--) { s->failed_pc=0x0c03c9deu; return 0; }
fr[7]=0;
goto P_0c03c9e0;
P_0c03c9e0: /* original f5fd, guest PC 0x0c03c9e0 */
if(!s->budget--) { s->failed_pc=0x0c03c9e0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03c9e2;
P_0c03c9e2: /* original f3fd, guest PC 0x0c03c9e2 */
if(!s->budget--) { s->failed_pc=0x0c03c9e2u; return 0; }
r[18]^=0x100000u;
goto P_0c03c9e4;
P_0c03c9e4: /* original f10c, guest PC 0x0c03c9e4 */
if(!s->budget--) { s->failed_pc=0x0c03c9e4u; return 0; }
vf3_matrix_move(s,1,0);
goto P_0c03c9e6;
P_0c03c9e6: /* original f32c, guest PC 0x0c03c9e6 */
if(!s->budget--) { s->failed_pc=0x0c03c9e6u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c03c9e8;
P_0c03c9e8: /* original f54c, guest PC 0x0c03c9e8 */
if(!s->budget--) { s->failed_pc=0x0c03c9e8u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c03c9ea;
P_0c03c9ea: /* original f76c, guest PC 0x0c03c9ea */
if(!s->budget--) { s->failed_pc=0x0c03c9eau; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c03c9ec;
P_0c03c9ec: /* original f3fd, guest PC 0x0c03c9ec */
if(!s->budget--) { s->failed_pc=0x0c03c9ecu; return 0; }
r[18]^=0x100000u;
goto P_0c03c9ee;
P_0c03c9ee: /* original 0009, guest PC 0x0c03c9ee */
if(!s->budget--) { s->failed_pc=0x0c03c9eeu; return 0; }
goto P_0c03c9f0;
P_0c03c9f0: /* original 000b, guest PC 0x0c03c9f0 */
if(!s->budget--) { s->failed_pc=0x0c03c9f0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c9f2: /* original 0009, guest PC 0x0c03c9f2 */
if(!s->budget--) { s->failed_pc=0x0c03c9f2u; return 0; }
return vf3_matrix_family(0x0c03c9f4u,s,ram);
P_0c03ca00: /* original 4f22, guest PC 0x0c03ca00 */
if(!s->budget--) { s->failed_pc=0x0c03ca00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ca02;
P_0c03ca02: /* original d34c, guest PC 0x0c03ca02 */
if(!s->budget--) { s->failed_pc=0x0c03ca02u; return 0; }
r[3]=read(ram,0x0c03cb34u,4);
goto P_0c03ca04;
P_0c03ca04: /* original 7ffc, guest PC 0x0c03ca04 */
if(!s->budget--) { s->failed_pc=0x0c03ca04u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ca06;
P_0c03ca06: /* original 430b, guest PC 0x0c03ca06 */
if(!s->budget--) { s->failed_pc=0x0c03ca06u; return 0; }
target=r[3];
r[16]=0x0c03ca0au;
vf3_matrix_store(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca0au) { target=s->pc; goto dispatch; }
goto P_0c03ca0a;
P_0c03ca08: /* original ff4a, guest PC 0x0c03ca08 */
if(!s->budget--) { s->failed_pc=0x0c03ca08u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03ca0a;
P_0c03ca0a: /* original e004, guest PC 0x0c03ca0a */
if(!s->budget--) { s->failed_pc=0x0c03ca0au; return 0; }
r[0]=0x00000004u;
goto P_0c03ca0c;
P_0c03ca0c: /* original ff0b, guest PC 0x0c03ca0c */
if(!s->budget--) { s->failed_pc=0x0c03ca0cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03ca0e;
P_0c03ca0e: /* original d34a, guest PC 0x0c03ca0e */
if(!s->budget--) { s->failed_pc=0x0c03ca0eu; return 0; }
r[3]=read(ram,0x0c03cb38u,4);
goto P_0c03ca10;
P_0c03ca10: /* original 430b, guest PC 0x0c03ca10 */
if(!s->budget--) { s->failed_pc=0x0c03ca10u; return 0; }
target=r[3];
r[16]=0x0c03ca14u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca14u) { target=s->pc; goto dispatch; }
goto P_0c03ca14;
P_0c03ca12: /* original f4f6, guest PC 0x0c03ca12 */
if(!s->budget--) { s->failed_pc=0x0c03ca12u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03ca14;
P_0c03ca14: /* original f5f9, guest PC 0x0c03ca14 */
if(!s->budget--) { s->failed_pc=0x0c03ca14u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03ca16;
P_0c03ca16: /* original d249, guest PC 0x0c03ca16 */
if(!s->budget--) { s->failed_pc=0x0c03ca16u; return 0; }
r[2]=read(ram,0x0c03cb3cu,4);
goto P_0c03ca18;
P_0c03ca18: /* original 7f04, guest PC 0x0c03ca18 */
if(!s->budget--) { s->failed_pc=0x0c03ca18u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ca1a;
P_0c03ca1a: /* original f40c, guest PC 0x0c03ca1a */
if(!s->budget--) { s->failed_pc=0x0c03ca1au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03ca1c;
P_0c03ca1c: /* original 422b, guest PC 0x0c03ca1c */
if(!s->budget--) { s->failed_pc=0x0c03ca1cu; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03ca1e: /* original 4f26, guest PC 0x0c03ca1e */
if(!s->budget--) { s->failed_pc=0x0c03ca1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ca20;
P_0c03ca20: /* original 4f22, guest PC 0x0c03ca20 */
if(!s->budget--) { s->failed_pc=0x0c03ca20u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ca22;
P_0c03ca22: /* original d344, guest PC 0x0c03ca22 */
if(!s->budget--) { s->failed_pc=0x0c03ca22u; return 0; }
r[3]=read(ram,0x0c03cb34u,4);
goto P_0c03ca24;
P_0c03ca24: /* original 7ffc, guest PC 0x0c03ca24 */
if(!s->budget--) { s->failed_pc=0x0c03ca24u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ca26;
P_0c03ca26: /* original 430b, guest PC 0x0c03ca26 */
if(!s->budget--) { s->failed_pc=0x0c03ca26u; return 0; }
target=r[3];
r[16]=0x0c03ca2au;
vf3_matrix_store(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca2au) { target=s->pc; goto dispatch; }
goto P_0c03ca2a;
P_0c03ca28: /* original ff4a, guest PC 0x0c03ca28 */
if(!s->budget--) { s->failed_pc=0x0c03ca28u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03ca2a;
P_0c03ca2a: /* original e004, guest PC 0x0c03ca2a */
if(!s->budget--) { s->failed_pc=0x0c03ca2au; return 0; }
r[0]=0x00000004u;
goto P_0c03ca2c;
P_0c03ca2c: /* original ff0b, guest PC 0x0c03ca2c */
if(!s->budget--) { s->failed_pc=0x0c03ca2cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03ca2e;
P_0c03ca2e: /* original d342, guest PC 0x0c03ca2e */
if(!s->budget--) { s->failed_pc=0x0c03ca2eu; return 0; }
r[3]=read(ram,0x0c03cb38u,4);
goto P_0c03ca30;
P_0c03ca30: /* original 430b, guest PC 0x0c03ca30 */
if(!s->budget--) { s->failed_pc=0x0c03ca30u; return 0; }
target=r[3];
r[16]=0x0c03ca34u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca34u) { target=s->pc; goto dispatch; }
goto P_0c03ca34;
P_0c03ca32: /* original f4f6, guest PC 0x0c03ca32 */
if(!s->budget--) { s->failed_pc=0x0c03ca32u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03ca34;
P_0c03ca34: /* original f5f9, guest PC 0x0c03ca34 */
if(!s->budget--) { s->failed_pc=0x0c03ca34u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03ca36;
P_0c03ca36: /* original d242, guest PC 0x0c03ca36 */
if(!s->budget--) { s->failed_pc=0x0c03ca36u; return 0; }
r[2]=read(ram,0x0c03cb40u,4);
goto P_0c03ca38;
P_0c03ca38: /* original 7f04, guest PC 0x0c03ca38 */
if(!s->budget--) { s->failed_pc=0x0c03ca38u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ca3a;
P_0c03ca3a: /* original f40c, guest PC 0x0c03ca3a */
if(!s->budget--) { s->failed_pc=0x0c03ca3au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03ca3c;
P_0c03ca3c: /* original 422b, guest PC 0x0c03ca3c */
if(!s->budget--) { s->failed_pc=0x0c03ca3cu; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03ca3e: /* original 4f26, guest PC 0x0c03ca3e */
if(!s->budget--) { s->failed_pc=0x0c03ca3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ca40;
P_0c03ca40: /* original 4f22, guest PC 0x0c03ca40 */
if(!s->budget--) { s->failed_pc=0x0c03ca40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ca42;
P_0c03ca42: /* original d33c, guest PC 0x0c03ca42 */
if(!s->budget--) { s->failed_pc=0x0c03ca42u; return 0; }
r[3]=read(ram,0x0c03cb34u,4);
goto P_0c03ca44;
P_0c03ca44: /* original 7ffc, guest PC 0x0c03ca44 */
if(!s->budget--) { s->failed_pc=0x0c03ca44u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ca46;
P_0c03ca46: /* original 430b, guest PC 0x0c03ca46 */
if(!s->budget--) { s->failed_pc=0x0c03ca46u; return 0; }
target=r[3];
r[16]=0x0c03ca4au;
vf3_matrix_store(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca4au) { target=s->pc; goto dispatch; }
goto P_0c03ca4a;
P_0c03ca48: /* original ff4a, guest PC 0x0c03ca48 */
if(!s->budget--) { s->failed_pc=0x0c03ca48u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03ca4a;
P_0c03ca4a: /* original e004, guest PC 0x0c03ca4a */
if(!s->budget--) { s->failed_pc=0x0c03ca4au; return 0; }
r[0]=0x00000004u;
goto P_0c03ca4c;
P_0c03ca4c: /* original ff0b, guest PC 0x0c03ca4c */
if(!s->budget--) { s->failed_pc=0x0c03ca4cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03ca4e;
P_0c03ca4e: /* original d33a, guest PC 0x0c03ca4e */
if(!s->budget--) { s->failed_pc=0x0c03ca4eu; return 0; }
r[3]=read(ram,0x0c03cb38u,4);
goto P_0c03ca50;
P_0c03ca50: /* original 430b, guest PC 0x0c03ca50 */
if(!s->budget--) { s->failed_pc=0x0c03ca50u; return 0; }
target=r[3];
r[16]=0x0c03ca54u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca54u) { target=s->pc; goto dispatch; }
goto P_0c03ca54;
P_0c03ca52: /* original f4f6, guest PC 0x0c03ca52 */
if(!s->budget--) { s->failed_pc=0x0c03ca52u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03ca54;
P_0c03ca54: /* original f5f9, guest PC 0x0c03ca54 */
if(!s->budget--) { s->failed_pc=0x0c03ca54u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03ca56;
P_0c03ca56: /* original d23b, guest PC 0x0c03ca56 */
if(!s->budget--) { s->failed_pc=0x0c03ca56u; return 0; }
r[2]=read(ram,0x0c03cb44u,4);
goto P_0c03ca58;
P_0c03ca58: /* original 7f04, guest PC 0x0c03ca58 */
if(!s->budget--) { s->failed_pc=0x0c03ca58u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ca5a;
P_0c03ca5a: /* original f40c, guest PC 0x0c03ca5a */
if(!s->budget--) { s->failed_pc=0x0c03ca5au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03ca5c;
P_0c03ca5c: /* original 422b, guest PC 0x0c03ca5c */
if(!s->budget--) { s->failed_pc=0x0c03ca5cu; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03ca5e: /* original 4f26, guest PC 0x0c03ca5e */
if(!s->budget--) { s->failed_pc=0x0c03ca5eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ca60;
P_0c03ca60: /* original 4f22, guest PC 0x0c03ca60 */
if(!s->budget--) { s->failed_pc=0x0c03ca60u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ca62;
P_0c03ca62: /* original d334, guest PC 0x0c03ca62 */
if(!s->budget--) { s->failed_pc=0x0c03ca62u; return 0; }
r[3]=read(ram,0x0c03cb34u,4);
goto P_0c03ca64;
P_0c03ca64: /* original 7ffc, guest PC 0x0c03ca64 */
if(!s->budget--) { s->failed_pc=0x0c03ca64u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ca66;
P_0c03ca66: /* original 430b, guest PC 0x0c03ca66 */
if(!s->budget--) { s->failed_pc=0x0c03ca66u; return 0; }
target=r[3];
r[16]=0x0c03ca6au;
vf3_matrix_store(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca6au) { target=s->pc; goto dispatch; }
goto P_0c03ca6a;
P_0c03ca68: /* original ff4a, guest PC 0x0c03ca68 */
if(!s->budget--) { s->failed_pc=0x0c03ca68u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03ca6a;
P_0c03ca6a: /* original e004, guest PC 0x0c03ca6a */
if(!s->budget--) { s->failed_pc=0x0c03ca6au; return 0; }
r[0]=0x00000004u;
goto P_0c03ca6c;
P_0c03ca6c: /* original ff0b, guest PC 0x0c03ca6c */
if(!s->budget--) { s->failed_pc=0x0c03ca6cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03ca6e;
P_0c03ca6e: /* original d332, guest PC 0x0c03ca6e */
if(!s->budget--) { s->failed_pc=0x0c03ca6eu; return 0; }
r[3]=read(ram,0x0c03cb38u,4);
goto P_0c03ca70;
P_0c03ca70: /* original 430b, guest PC 0x0c03ca70 */
if(!s->budget--) { s->failed_pc=0x0c03ca70u; return 0; }
target=r[3];
r[16]=0x0c03ca74u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca74u) { target=s->pc; goto dispatch; }
goto P_0c03ca74;
P_0c03ca72: /* original f4f6, guest PC 0x0c03ca72 */
if(!s->budget--) { s->failed_pc=0x0c03ca72u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03ca74;
P_0c03ca74: /* original f5f9, guest PC 0x0c03ca74 */
if(!s->budget--) { s->failed_pc=0x0c03ca74u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03ca76;
P_0c03ca76: /* original d234, guest PC 0x0c03ca76 */
if(!s->budget--) { s->failed_pc=0x0c03ca76u; return 0; }
r[2]=read(ram,0x0c03cb48u,4);
goto P_0c03ca78;
P_0c03ca78: /* original 7f04, guest PC 0x0c03ca78 */
if(!s->budget--) { s->failed_pc=0x0c03ca78u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ca7a;
P_0c03ca7a: /* original f40c, guest PC 0x0c03ca7a */
if(!s->budget--) { s->failed_pc=0x0c03ca7au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03ca7c;
P_0c03ca7c: /* original 422b, guest PC 0x0c03ca7c */
if(!s->budget--) { s->failed_pc=0x0c03ca7cu; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03ca7e: /* original 4f26, guest PC 0x0c03ca7e */
if(!s->budget--) { s->failed_pc=0x0c03ca7eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ca80;
P_0c03ca80: /* original 4f22, guest PC 0x0c03ca80 */
if(!s->budget--) { s->failed_pc=0x0c03ca80u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ca82;
P_0c03ca82: /* original d32c, guest PC 0x0c03ca82 */
if(!s->budget--) { s->failed_pc=0x0c03ca82u; return 0; }
r[3]=read(ram,0x0c03cb34u,4);
goto P_0c03ca84;
P_0c03ca84: /* original 7ffc, guest PC 0x0c03ca84 */
if(!s->budget--) { s->failed_pc=0x0c03ca84u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ca86;
P_0c03ca86: /* original 430b, guest PC 0x0c03ca86 */
if(!s->budget--) { s->failed_pc=0x0c03ca86u; return 0; }
target=r[3];
r[16]=0x0c03ca8au;
vf3_matrix_store(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca8au) { target=s->pc; goto dispatch; }
goto P_0c03ca8a;
P_0c03ca88: /* original ff4a, guest PC 0x0c03ca88 */
if(!s->budget--) { s->failed_pc=0x0c03ca88u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03ca8a;
P_0c03ca8a: /* original e004, guest PC 0x0c03ca8a */
if(!s->budget--) { s->failed_pc=0x0c03ca8au; return 0; }
r[0]=0x00000004u;
goto P_0c03ca8c;
P_0c03ca8c: /* original ff0b, guest PC 0x0c03ca8c */
if(!s->budget--) { s->failed_pc=0x0c03ca8cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03ca8e;
P_0c03ca8e: /* original d32a, guest PC 0x0c03ca8e */
if(!s->budget--) { s->failed_pc=0x0c03ca8eu; return 0; }
r[3]=read(ram,0x0c03cb38u,4);
goto P_0c03ca90;
P_0c03ca90: /* original 430b, guest PC 0x0c03ca90 */
if(!s->budget--) { s->failed_pc=0x0c03ca90u; return 0; }
target=r[3];
r[16]=0x0c03ca94u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ca94u) { target=s->pc; goto dispatch; }
goto P_0c03ca94;
P_0c03ca92: /* original f4f6, guest PC 0x0c03ca92 */
if(!s->budget--) { s->failed_pc=0x0c03ca92u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03ca94;
P_0c03ca94: /* original f5f9, guest PC 0x0c03ca94 */
if(!s->budget--) { s->failed_pc=0x0c03ca94u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03ca96;
P_0c03ca96: /* original d22d, guest PC 0x0c03ca96 */
if(!s->budget--) { s->failed_pc=0x0c03ca96u; return 0; }
r[2]=read(ram,0x0c03cb4cu,4);
goto P_0c03ca98;
P_0c03ca98: /* original 7f04, guest PC 0x0c03ca98 */
if(!s->budget--) { s->failed_pc=0x0c03ca98u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ca9a;
P_0c03ca9a: /* original f40c, guest PC 0x0c03ca9a */
if(!s->budget--) { s->failed_pc=0x0c03ca9au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03ca9c;
P_0c03ca9c: /* original 422b, guest PC 0x0c03ca9c */
if(!s->budget--) { s->failed_pc=0x0c03ca9cu; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03ca9e: /* original 4f26, guest PC 0x0c03ca9e */
if(!s->budget--) { s->failed_pc=0x0c03ca9eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03caa0;
P_0c03caa0: /* original 4f22, guest PC 0x0c03caa0 */
if(!s->budget--) { s->failed_pc=0x0c03caa0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03caa2;
P_0c03caa2: /* original d324, guest PC 0x0c03caa2 */
if(!s->budget--) { s->failed_pc=0x0c03caa2u; return 0; }
r[3]=read(ram,0x0c03cb34u,4);
goto P_0c03caa4;
P_0c03caa4: /* original 7ffc, guest PC 0x0c03caa4 */
if(!s->budget--) { s->failed_pc=0x0c03caa4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03caa6;
P_0c03caa6: /* original 430b, guest PC 0x0c03caa6 */
if(!s->budget--) { s->failed_pc=0x0c03caa6u; return 0; }
target=r[3];
r[16]=0x0c03caaau;
vf3_matrix_store(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03caaau) { target=s->pc; goto dispatch; }
goto P_0c03caaa;
P_0c03caa8: /* original ff4a, guest PC 0x0c03caa8 */
if(!s->budget--) { s->failed_pc=0x0c03caa8u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03caaa;
P_0c03caaa: /* original e004, guest PC 0x0c03caaa */
if(!s->budget--) { s->failed_pc=0x0c03caaau; return 0; }
r[0]=0x00000004u;
goto P_0c03caac;
P_0c03caac: /* original ff0b, guest PC 0x0c03caac */
if(!s->budget--) { s->failed_pc=0x0c03caacu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03caae;
P_0c03caae: /* original d322, guest PC 0x0c03caae */
if(!s->budget--) { s->failed_pc=0x0c03caaeu; return 0; }
r[3]=read(ram,0x0c03cb38u,4);
goto P_0c03cab0;
P_0c03cab0: /* original 430b, guest PC 0x0c03cab0 */
if(!s->budget--) { s->failed_pc=0x0c03cab0u; return 0; }
target=r[3];
r[16]=0x0c03cab4u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03cab4u) { target=s->pc; goto dispatch; }
goto P_0c03cab4;
P_0c03cab2: /* original f4f6, guest PC 0x0c03cab2 */
if(!s->budget--) { s->failed_pc=0x0c03cab2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03cab4;
P_0c03cab4: /* original f5f9, guest PC 0x0c03cab4 */
if(!s->budget--) { s->failed_pc=0x0c03cab4u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03cab6;
P_0c03cab6: /* original d226, guest PC 0x0c03cab6 */
if(!s->budget--) { s->failed_pc=0x0c03cab6u; return 0; }
r[2]=read(ram,0x0c03cb50u,4);
goto P_0c03cab8;
P_0c03cab8: /* original 7f04, guest PC 0x0c03cab8 */
if(!s->budget--) { s->failed_pc=0x0c03cab8u; return 0; }
r[15]+=0x00000004u;
goto P_0c03caba;
P_0c03caba: /* original f40c, guest PC 0x0c03caba */
if(!s->budget--) { s->failed_pc=0x0c03cabau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03cabc;
P_0c03cabc: /* original 422b, guest PC 0x0c03cabc */
if(!s->budget--) { s->failed_pc=0x0c03cabcu; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03cabe: /* original 4f26, guest PC 0x0c03cabe */
if(!s->budget--) { s->failed_pc=0x0c03cabeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03cac0u,s,ram);
P_0c03e760: /* original 9393, guest PC 0x0c03e760 */
if(!s->budget--) { s->failed_pc=0x0c03e760u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88au,2);
goto P_0c03e762;
P_0c03e762: /* original 4f12, guest PC 0x0c03e762 */
if(!s->budget--) { s->failed_pc=0x0c03e762u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e764;
P_0c03e764: /* original 243f, guest PC 0x0c03e764 */
if(!s->budget--) { s->failed_pc=0x0c03e764u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c03e766;
P_0c03e766: /* original d24a, guest PC 0x0c03e766 */
if(!s->budget--) { s->failed_pc=0x0c03e766u; return 0; }
r[2]=read(ram,0x0c03e890u,4);
goto P_0c03e768;
P_0c03e768: /* original 9090, guest PC 0x0c03e768 */
if(!s->budget--) { s->failed_pc=0x0c03e768u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88cu,2);
goto P_0c03e76a;
P_0c03e76a: /* original 041a, guest PC 0x0c03e76a */
if(!s->budget--) { s->failed_pc=0x0c03e76au; return 0; }
r[4]=r[19];
goto P_0c03e76c;
P_0c03e76c: /* original 644f, guest PC 0x0c03e76c */
if(!s->budget--) { s->failed_pc=0x0c03e76cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c03e76e;
P_0c03e76e: /* original 342c, guest PC 0x0c03e76e */
if(!s->budget--) { s->failed_pc=0x0c03e76eu; return 0; }
r[4]+=r[2];
goto P_0c03e770;
P_0c03e770: /* original f447, guest PC 0x0c03e770 */
if(!s->budget--) { s->failed_pc=0x0c03e770u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03e772;
P_0c03e772: /* original e058, guest PC 0x0c03e772 */
if(!s->budget--) { s->failed_pc=0x0c03e772u; return 0; }
r[0]=0x00000058u;
goto P_0c03e774;
P_0c03e774: /* original f457, guest PC 0x0c03e774 */
if(!s->budget--) { s->failed_pc=0x0c03e774u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03e776;
P_0c03e776: /* original 7044, guest PC 0x0c03e776 */
if(!s->budget--) { s->failed_pc=0x0c03e776u; return 0; }
r[0]+=0x00000044u;
goto P_0c03e778;
P_0c03e778: /* original f49d, guest PC 0x0c03e778 */
if(!s->budget--) { s->failed_pc=0x0c03e778u; return 0; }
fr[4]=0x3f800000u;
goto P_0c03e77a;
P_0c03e77a: /* original f34c, guest PC 0x0c03e77a */
if(!s->budget--) { s->failed_pc=0x0c03e77au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03e77c;
P_0c03e77c: /* original f351, guest PC 0x0c03e77c */
if(!s->budget--) { s->failed_pc=0x0c03e77cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03e77e;
P_0c03e77e: /* original f24c, guest PC 0x0c03e77e */
if(!s->budget--) { s->failed_pc=0x0c03e77eu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03e780;
P_0c03e780: /* original f233, guest PC 0x0c03e780 */
if(!s->budget--) { s->failed_pc=0x0c03e780u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c03e782;
P_0c03e782: /* original f427, guest PC 0x0c03e782 */
if(!s->budget--) { s->failed_pc=0x0c03e782u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03e784;
P_0c03e784: /* original 000b, guest PC 0x0c03e784 */
if(!s->budget--) { s->failed_pc=0x0c03e784u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c03e786: /* original 4f16, guest PC 0x0c03e786 */
if(!s->budget--) { s->failed_pc=0x0c03e786u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03e788u,s,ram);
P_0c03e7c0: /* original 4f22, guest PC 0x0c03e7c0 */
if(!s->budget--) { s->failed_pc=0x0c03e7c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e7c2;
P_0c03e7c2: /* original 7ff8, guest PC 0x0c03e7c2 */
if(!s->budget--) { s->failed_pc=0x0c03e7c2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03e7c4;
P_0c03e7c4: /* original 1f41, guest PC 0x0c03e7c4 */
if(!s->budget--) { s->failed_pc=0x0c03e7c4u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03e7c6;
P_0c03e7c6: /* original d335, guest PC 0x0c03e7c6 */
if(!s->budget--) { s->failed_pc=0x0c03e7c6u; return 0; }
r[3]=read(ram,0x0c03e89cu,4);
goto P_0c03e7c8;
P_0c03e7c8: /* original 430b, guest PC 0x0c03e7c8 */
if(!s->budget--) { s->failed_pc=0x0c03e7c8u; return 0; }
target=r[3];
r[16]=0x0c03e7ccu;
vf3_matrix_store(s,ram,4,r[15]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e7ccu) { target=s->pc; goto dispatch; }
goto P_0c03e7cc;
P_0c03e7ca: /* original ff4a, guest PC 0x0c03e7ca */
if(!s->budget--) { s->failed_pc=0x0c03e7cau; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03e7cc;
P_0c03e7cc: /* original e004, guest PC 0x0c03e7cc */
if(!s->budget--) { s->failed_pc=0x0c03e7ccu; return 0; }
r[0]=0x00000004u;
goto P_0c03e7ce;
P_0c03e7ce: /* original ff0b, guest PC 0x0c03e7ce */
if(!s->budget--) { s->failed_pc=0x0c03e7ceu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03e7d0;
P_0c03e7d0: /* original d333, guest PC 0x0c03e7d0 */
if(!s->budget--) { s->failed_pc=0x0c03e7d0u; return 0; }
r[3]=read(ram,0x0c03e8a0u,4);
goto P_0c03e7d2;
P_0c03e7d2: /* original 430b, guest PC 0x0c03e7d2 */
if(!s->budget--) { s->failed_pc=0x0c03e7d2u; return 0; }
target=r[3];
r[16]=0x0c03e7d6u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e7d6u) { target=s->pc; goto dispatch; }
goto P_0c03e7d6;
P_0c03e7d4: /* original f4f6, guest PC 0x0c03e7d4 */
if(!s->budget--) { s->failed_pc=0x0c03e7d4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03e7d6;
P_0c03e7d6: /* original 54f2, guest PC 0x0c03e7d6 */
if(!s->budget--) { s->failed_pc=0x0c03e7d6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c03e7d8;
P_0c03e7d8: /* original f5f9, guest PC 0x0c03e7d8 */
if(!s->budget--) { s->failed_pc=0x0c03e7d8u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03e7da;
P_0c03e7da: /* original f40c, guest PC 0x0c03e7da */
if(!s->budget--) { s->failed_pc=0x0c03e7dau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03e7dc;
P_0c03e7dc: /* original 7f08, guest PC 0x0c03e7dc */
if(!s->budget--) { s->failed_pc=0x0c03e7dcu; return 0; }
r[15]+=0x00000008u;
goto P_0c03e7de;
P_0c03e7de: /* original afbf, guest PC 0x0c03e7de */
if(!s->budget--) { s->failed_pc=0x0c03e7deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e760;
P_0c03e7e0: /* original 4f26, guest PC 0x0c03e7e0 */
if(!s->budget--) { s->failed_pc=0x0c03e7e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03e7e2u,s,ram);
P_0c04236a: /* original 4f22, guest PC 0x0c04236a */
if(!s->budget--) { s->failed_pc=0x0c04236au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04236c;
P_0c04236c: /* original 6322, guest PC 0x0c04236c */
if(!s->budget--) { s->failed_pc=0x0c04236cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04236e;
P_0c04236e: /* original 2338, guest PC 0x0c04236e */
if(!s->budget--) { s->failed_pc=0x0c04236eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c042370;
P_0c042370: /* original 8912, guest PC 0x0c042370 */
if(!s->budget--) { s->failed_pc=0x0c042370u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042398; }
goto P_0c042372;
P_0c042372: /* original dc41, guest PC 0x0c042372 */
if(!s->budget--) { s->failed_pc=0x0c042372u; return 0; }
r[12]=read(ram,0x0c042478u,4);
goto P_0c042374;
P_0c042374: /* original ee00, guest PC 0x0c042374 */
if(!s->budget--) { s->failed_pc=0x0c042374u; return 0; }
r[14]=0x00000000u;
goto P_0c042376;
P_0c042376: /* original db3f, guest PC 0x0c042376 */
if(!s->budget--) { s->failed_pc=0x0c042376u; return 0; }
r[11]=read(ram,0x0c042474u,4);
goto P_0c042378;
P_0c042378: /* original ed03, guest PC 0x0c042378 */
if(!s->budget--) { s->failed_pc=0x0c042378u; return 0; }
r[13]=0x00000003u;
goto P_0c04237a;
P_0c04237a: /* original 64e3, guest PC 0x0c04237a */
if(!s->budget--) { s->failed_pc=0x0c04237au; return 0; }
r[4]=r[14];
goto P_0c04237c;
P_0c04237c: /* original 4408, guest PC 0x0c04237c */
if(!s->budget--) { s->failed_pc=0x0c04237cu; return 0; }
r[4]<<=2;
goto P_0c04237e;
P_0c04237e: /* original 63e3, guest PC 0x0c04237e */
if(!s->budget--) { s->failed_pc=0x0c04237eu; return 0; }
r[3]=r[14];
goto P_0c042380;
P_0c042380: /* original 343c, guest PC 0x0c042380 */
if(!s->budget--) { s->failed_pc=0x0c042380u; return 0; }
r[4]+=r[3];
goto P_0c042382;
P_0c042382: /* original 4408, guest PC 0x0c042382 */
if(!s->budget--) { s->failed_pc=0x0c042382u; return 0; }
r[4]<<=2;
goto P_0c042384;
P_0c042384: /* original 4400, guest PC 0x0c042384 */
if(!s->budget--) { s->failed_pc=0x0c042384u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c042386;
P_0c042386: /* original 644e, guest PC 0x0c042386 */
if(!s->budget--) { s->failed_pc=0x0c042386u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c042388;
P_0c042388: /* original 4c0b, guest PC 0x0c042388 */
if(!s->budget--) { s->failed_pc=0x0c042388u; return 0; }
target=r[12];
r[16]=0x0c04238cu;
r[4]+=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04238cu) { target=s->pc; goto dispatch; }
goto P_0c04238c;
P_0c04238a: /* original 34bc, guest PC 0x0c04238a */
if(!s->budget--) { s->failed_pc=0x0c04238au; return 0; }
r[4]+=r[11];
goto P_0c04238c;
P_0c04238c: /* original 7e01, guest PC 0x0c04238c */
if(!s->budget--) { s->failed_pc=0x0c04238cu; return 0; }
r[14]+=0x00000001u;
goto P_0c04238e;
P_0c04238e: /* original 3ed3, guest PC 0x0c04238e */
if(!s->budget--) { s->failed_pc=0x0c04238eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c042390;
P_0c042390: /* original 8bf3, guest PC 0x0c042390 */
if(!s->budget--) { s->failed_pc=0x0c042390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04237a; }
goto P_0c042392;
P_0c042392: /* original d237, guest PC 0x0c042392 */
if(!s->budget--) { s->failed_pc=0x0c042392u; return 0; }
r[2]=read(ram,0x0c042470u,4);
goto P_0c042394;
P_0c042394: /* original e300, guest PC 0x0c042394 */
if(!s->budget--) { s->failed_pc=0x0c042394u; return 0; }
r[3]=0x00000000u;
goto P_0c042396;
P_0c042396: /* original 2232, guest PC 0x0c042396 */
if(!s->budget--) { s->failed_pc=0x0c042396u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c042398;
P_0c042398: /* original 4f26, guest PC 0x0c042398 */
if(!s->budget--) { s->failed_pc=0x0c042398u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04239a;
P_0c04239a: /* original 6bf6, guest PC 0x0c04239a */
if(!s->budget--) { s->failed_pc=0x0c04239au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04239c;
P_0c04239c: /* original 6cf6, guest PC 0x0c04239c */
if(!s->budget--) { s->failed_pc=0x0c04239cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04239e;
P_0c04239e: /* original 6df6, guest PC 0x0c04239e */
if(!s->budget--) { s->failed_pc=0x0c04239eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0423a0;
P_0c0423a0: /* original 000b, guest PC 0x0c0423a0 */
if(!s->budget--) { s->failed_pc=0x0c0423a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0423a2: /* original 6ef6, guest PC 0x0c0423a2 */
if(!s->budget--) { s->failed_pc=0x0c0423a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0423a4u,s,ram);
P_0c0430f0: /* original e600, guest PC 0x0c0430f0 */
if(!s->budget--) { s->failed_pc=0x0c0430f0u; return 0; }
r[6]=0x00000000u;
goto P_0c0430f2;
P_0c0430f2: /* original d702, guest PC 0x0c0430f2 */
if(!s->budget--) { s->failed_pc=0x0c0430f2u; return 0; }
r[7]=read(ram,0x0c0430fcu,4);
goto P_0c0430f4;
P_0c0430f4: /* original d002, guest PC 0x0c0430f4 */
if(!s->budget--) { s->failed_pc=0x0c0430f4u; return 0; }
r[0]=read(ram,0x0c043100u,4);
goto P_0c0430f6;
P_0c0430f6: /* original 6002, guest PC 0x0c0430f6 */
if(!s->budget--) { s->failed_pc=0x0c0430f6u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0430f8;
P_0c0430f8: /* original 402b, guest PC 0x0c0430f8 */
if(!s->budget--) { s->failed_pc=0x0c0430f8u; return 0; }
target=r[0];
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
P_0c0430fa: /* original 0009, guest PC 0x0c0430fa */
if(!s->budget--) { s->failed_pc=0x0c0430fau; return 0; }
return vf3_matrix_family(0x0c0430fcu,s,ram);
P_0c0443f2: /* original 4f22, guest PC 0x0c0443f2 */
if(!s->budget--) { s->failed_pc=0x0c0443f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0443f4;
P_0c0443f4: /* original 8800, guest PC 0x0c0443f4 */
if(!s->budget--) { s->failed_pc=0x0c0443f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0443f6;
P_0c0443f6: /* original 8d30, guest PC 0x0c0443f6 */
if(!s->budget--) { s->failed_pc=0x0c0443f6u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c04445a; }
goto P_0c0443fa;
P_0c0443f8: /* original 6e53, guest PC 0x0c0443f8 */
if(!s->budget--) { s->failed_pc=0x0c0443f8u; return 0; }
r[14]=r[5];
goto P_0c0443fa;
P_0c0443fa: /* original 8801, guest PC 0x0c0443fa */
if(!s->budget--) { s->failed_pc=0x0c0443fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0443fc;
P_0c0443fc: /* original 890f, guest PC 0x0c0443fc */
if(!s->budget--) { s->failed_pc=0x0c0443fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04441e; }
goto P_0c0443fe;
P_0c0443fe: /* original 8802, guest PC 0x0c0443fe */
if(!s->budget--) { s->failed_pc=0x0c0443feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c044400;
P_0c044400: /* original 8912, guest PC 0x0c044400 */
if(!s->budget--) { s->failed_pc=0x0c044400u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c044428; }
goto P_0c044402;
P_0c044402: /* original 8803, guest PC 0x0c044402 */
if(!s->budget--) { s->failed_pc=0x0c044402u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c044404;
P_0c044404: /* original 891a, guest PC 0x0c044404 */
if(!s->budget--) { s->failed_pc=0x0c044404u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04443c; }
goto P_0c044406;
P_0c044406: /* original 8804, guest PC 0x0c044406 */
if(!s->budget--) { s->failed_pc=0x0c044406u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c044408;
P_0c044408: /* original 8913, guest PC 0x0c044408 */
if(!s->budget--) { s->failed_pc=0x0c044408u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c044432; }
goto P_0c04440a;
P_0c04440a: /* original 8805, guest PC 0x0c04440a */
if(!s->budget--) { s->failed_pc=0x0c04440au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c04440c;
P_0c04440c: /* original 8920, guest PC 0x0c04440c */
if(!s->budget--) { s->failed_pc=0x0c04440cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c044450; }
goto P_0c04440e;
P_0c04440e: /* original 8806, guest PC 0x0c04440e */
if(!s->budget--) { s->failed_pc=0x0c04440eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c044410;
P_0c044410: /* original 8919, guest PC 0x0c044410 */
if(!s->budget--) { s->failed_pc=0x0c044410u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c044446; }
goto P_0c044412;
P_0c044412: /* original 8807, guest PC 0x0c044412 */
if(!s->budget--) { s->failed_pc=0x0c044412u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c044414;
P_0c044414: /* original 8926, guest PC 0x0c044414 */
if(!s->budget--) { s->failed_pc=0x0c044414u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c044464; }
goto P_0c044416;
P_0c044416: /* original 8808, guest PC 0x0c044416 */
if(!s->budget--) { s->failed_pc=0x0c044416u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c044418;
P_0c044418: /* original 8929, guest PC 0x0c044418 */
if(!s->budget--) { s->failed_pc=0x0c044418u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04446e; }
goto P_0c04441a;
P_0c04441a: /* original a02b, guest PC 0x0c04441a */
if(!s->budget--) { s->failed_pc=0x0c04441au; return 0; }
goto P_0c044474;
P_0c04441c: /* original 0009, guest PC 0x0c04441c */
if(!s->budget--) { s->failed_pc=0x0c04441cu; return 0; }
goto P_0c04441e;
P_0c04441e: /* original d330, guest PC 0x0c04441e */
if(!s->budget--) { s->failed_pc=0x0c04441eu; return 0; }
r[3]=read(ram,0x0c0444e0u,4);
goto P_0c044420;
P_0c044420: /* original 430b, guest PC 0x0c044420 */
if(!s->budget--) { s->failed_pc=0x0c044420u; return 0; }
target=r[3];
r[16]=0x0c044424u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044424u) { target=s->pc; goto dispatch; }
goto P_0c044424;
P_0c044422: /* original 64e3, guest PC 0x0c044422 */
if(!s->budget--) { s->failed_pc=0x0c044422u; return 0; }
r[4]=r[14];
goto P_0c044424;
P_0c044424: /* original a02a, guest PC 0x0c044424 */
if(!s->budget--) { s->failed_pc=0x0c044424u; return 0; }
goto P_0c04447c;
P_0c044426: /* original 0009, guest PC 0x0c044426 */
if(!s->budget--) { s->failed_pc=0x0c044426u; return 0; }
goto P_0c044428;
P_0c044428: /* original d32e, guest PC 0x0c044428 */
if(!s->budget--) { s->failed_pc=0x0c044428u; return 0; }
r[3]=read(ram,0x0c0444e4u,4);
goto P_0c04442a;
P_0c04442a: /* original 430b, guest PC 0x0c04442a */
if(!s->budget--) { s->failed_pc=0x0c04442au; return 0; }
target=r[3];
r[16]=0x0c04442eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04442eu) { target=s->pc; goto dispatch; }
goto P_0c04442e;
P_0c04442c: /* original 64e3, guest PC 0x0c04442c */
if(!s->budget--) { s->failed_pc=0x0c04442cu; return 0; }
r[4]=r[14];
goto P_0c04442e;
P_0c04442e: /* original a025, guest PC 0x0c04442e */
if(!s->budget--) { s->failed_pc=0x0c04442eu; return 0; }
goto P_0c04447c;
P_0c044430: /* original 0009, guest PC 0x0c044430 */
if(!s->budget--) { s->failed_pc=0x0c044430u; return 0; }
goto P_0c044432;
P_0c044432: /* original d32d, guest PC 0x0c044432 */
if(!s->budget--) { s->failed_pc=0x0c044432u; return 0; }
r[3]=read(ram,0x0c0444e8u,4);
goto P_0c044434;
P_0c044434: /* original 430b, guest PC 0x0c044434 */
if(!s->budget--) { s->failed_pc=0x0c044434u; return 0; }
target=r[3];
r[16]=0x0c044438u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044438u) { target=s->pc; goto dispatch; }
goto P_0c044438;
P_0c044436: /* original 64e3, guest PC 0x0c044436 */
if(!s->budget--) { s->failed_pc=0x0c044436u; return 0; }
r[4]=r[14];
goto P_0c044438;
P_0c044438: /* original a020, guest PC 0x0c044438 */
if(!s->budget--) { s->failed_pc=0x0c044438u; return 0; }
goto P_0c04447c;
P_0c04443a: /* original 0009, guest PC 0x0c04443a */
if(!s->budget--) { s->failed_pc=0x0c04443au; return 0; }
goto P_0c04443c;
P_0c04443c: /* original d32b, guest PC 0x0c04443c */
if(!s->budget--) { s->failed_pc=0x0c04443cu; return 0; }
r[3]=read(ram,0x0c0444ecu,4);
goto P_0c04443e;
P_0c04443e: /* original 430b, guest PC 0x0c04443e */
if(!s->budget--) { s->failed_pc=0x0c04443eu; return 0; }
target=r[3];
r[16]=0x0c044442u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044442u) { target=s->pc; goto dispatch; }
goto P_0c044442;
P_0c044440: /* original 64e3, guest PC 0x0c044440 */
if(!s->budget--) { s->failed_pc=0x0c044440u; return 0; }
r[4]=r[14];
goto P_0c044442;
P_0c044442: /* original a01b, guest PC 0x0c044442 */
if(!s->budget--) { s->failed_pc=0x0c044442u; return 0; }
goto P_0c04447c;
P_0c044444: /* original 0009, guest PC 0x0c044444 */
if(!s->budget--) { s->failed_pc=0x0c044444u; return 0; }
goto P_0c044446;
P_0c044446: /* original d32a, guest PC 0x0c044446 */
if(!s->budget--) { s->failed_pc=0x0c044446u; return 0; }
r[3]=read(ram,0x0c0444f0u,4);
goto P_0c044448;
P_0c044448: /* original 430b, guest PC 0x0c044448 */
if(!s->budget--) { s->failed_pc=0x0c044448u; return 0; }
target=r[3];
r[16]=0x0c04444cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04444cu) { target=s->pc; goto dispatch; }
goto P_0c04444c;
P_0c04444a: /* original 64e3, guest PC 0x0c04444a */
if(!s->budget--) { s->failed_pc=0x0c04444au; return 0; }
r[4]=r[14];
goto P_0c04444c;
P_0c04444c: /* original a016, guest PC 0x0c04444c */
if(!s->budget--) { s->failed_pc=0x0c04444cu; return 0; }
goto P_0c04447c;
P_0c04444e: /* original 0009, guest PC 0x0c04444e */
if(!s->budget--) { s->failed_pc=0x0c04444eu; return 0; }
goto P_0c044450;
P_0c044450: /* original d328, guest PC 0x0c044450 */
if(!s->budget--) { s->failed_pc=0x0c044450u; return 0; }
r[3]=read(ram,0x0c0444f4u,4);
goto P_0c044452;
P_0c044452: /* original 430b, guest PC 0x0c044452 */
if(!s->budget--) { s->failed_pc=0x0c044452u; return 0; }
target=r[3];
r[16]=0x0c044456u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044456u) { target=s->pc; goto dispatch; }
goto P_0c044456;
P_0c044454: /* original 64e3, guest PC 0x0c044454 */
if(!s->budget--) { s->failed_pc=0x0c044454u; return 0; }
r[4]=r[14];
goto P_0c044456;
P_0c044456: /* original a011, guest PC 0x0c044456 */
if(!s->budget--) { s->failed_pc=0x0c044456u; return 0; }
goto P_0c04447c;
P_0c044458: /* original 0009, guest PC 0x0c044458 */
if(!s->budget--) { s->failed_pc=0x0c044458u; return 0; }
goto P_0c04445a;
P_0c04445a: /* original d327, guest PC 0x0c04445a */
if(!s->budget--) { s->failed_pc=0x0c04445au; return 0; }
r[3]=read(ram,0x0c0444f8u,4);
goto P_0c04445c;
P_0c04445c: /* original 430b, guest PC 0x0c04445c */
if(!s->budget--) { s->failed_pc=0x0c04445cu; return 0; }
target=r[3];
r[16]=0x0c044460u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044460u) { target=s->pc; goto dispatch; }
goto P_0c044460;
P_0c04445e: /* original 64e3, guest PC 0x0c04445e */
if(!s->budget--) { s->failed_pc=0x0c04445eu; return 0; }
r[4]=r[14];
goto P_0c044460;
P_0c044460: /* original a00c, guest PC 0x0c044460 */
if(!s->budget--) { s->failed_pc=0x0c044460u; return 0; }
goto P_0c04447c;
P_0c044462: /* original 0009, guest PC 0x0c044462 */
if(!s->budget--) { s->failed_pc=0x0c044462u; return 0; }
goto P_0c044464;
P_0c044464: /* original d325, guest PC 0x0c044464 */
if(!s->budget--) { s->failed_pc=0x0c044464u; return 0; }
r[3]=read(ram,0x0c0444fcu,4);
goto P_0c044466;
P_0c044466: /* original 430b, guest PC 0x0c044466 */
if(!s->budget--) { s->failed_pc=0x0c044466u; return 0; }
target=r[3];
r[16]=0x0c04446au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04446au) { target=s->pc; goto dispatch; }
goto P_0c04446a;
P_0c044468: /* original 64e3, guest PC 0x0c044468 */
if(!s->budget--) { s->failed_pc=0x0c044468u; return 0; }
r[4]=r[14];
goto P_0c04446a;
P_0c04446a: /* original a007, guest PC 0x0c04446a */
if(!s->budget--) { s->failed_pc=0x0c04446au; return 0; }
goto P_0c04447c;
P_0c04446c: /* original 0009, guest PC 0x0c04446c */
if(!s->budget--) { s->failed_pc=0x0c04446cu; return 0; }
goto P_0c04446e;
P_0c04446e: /* original d324, guest PC 0x0c04446e */
if(!s->budget--) { s->failed_pc=0x0c04446eu; return 0; }
r[3]=read(ram,0x0c044500u,4);
goto P_0c044470;
P_0c044470: /* original 430b, guest PC 0x0c044470 */
if(!s->budget--) { s->failed_pc=0x0c044470u; return 0; }
target=r[3];
r[16]=0x0c044474u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044474u) { target=s->pc; goto dispatch; }
goto P_0c044474;
P_0c044472: /* original 64e3, guest PC 0x0c044472 */
if(!s->budget--) { s->failed_pc=0x0c044472u; return 0; }
r[4]=r[14];
goto P_0c044474;
P_0c044474: /* original 4f26, guest PC 0x0c044474 */
if(!s->budget--) { s->failed_pc=0x0c044474u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044476;
P_0c044476: /* original e0ff, guest PC 0x0c044476 */
if(!s->budget--) { s->failed_pc=0x0c044476u; return 0; }
r[0]=0xffffffffu;
goto P_0c044478;
P_0c044478: /* original 000b, guest PC 0x0c044478 */
if(!s->budget--) { s->failed_pc=0x0c044478u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04447a: /* original 6ef6, guest PC 0x0c04447a */
if(!s->budget--) { s->failed_pc=0x0c04447au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04447c;
P_0c04447c: /* original e000, guest PC 0x0c04447c */
if(!s->budget--) { s->failed_pc=0x0c04447cu; return 0; }
r[0]=0x00000000u;
goto P_0c04447e;
P_0c04447e: /* original 4f26, guest PC 0x0c04447e */
if(!s->budget--) { s->failed_pc=0x0c04447eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044480;
P_0c044480: /* original 000b, guest PC 0x0c044480 */
if(!s->budget--) { s->failed_pc=0x0c044480u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c044482: /* original 6ef6, guest PC 0x0c044482 */
if(!s->budget--) { s->failed_pc=0x0c044482u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c044484u,s,ram);
P_0c045f62: /* original 4f22, guest PC 0x0c045f62 */
if(!s->budget--) { s->failed_pc=0x0c045f62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045f64;
P_0c045f64: /* original d02d, guest PC 0x0c045f64 */
if(!s->budget--) { s->failed_pc=0x0c045f64u; return 0; }
r[0]=read(ram,0x0c04601cu,4);
goto P_0c045f66;
P_0c045f66: /* original 4e08, guest PC 0x0c045f66 */
if(!s->budget--) { s->failed_pc=0x0c045f66u; return 0; }
r[14]<<=2;
goto P_0c045f68;
P_0c045f68: /* original a004, guest PC 0x0c045f68 */
if(!s->budget--) { s->failed_pc=0x0c045f68u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c045f74;
P_0c045f6a: /* original 0eee, guest PC 0x0c045f6a */
if(!s->budget--) { s->failed_pc=0x0c045f6au; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c045f6c;
P_0c045f6c: /* original 62e2, guest PC 0x0c045f6c */
if(!s->budget--) { s->failed_pc=0x0c045f6cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c045f6e;
P_0c045f6e: /* original 420b, guest PC 0x0c045f6e */
if(!s->budget--) { s->failed_pc=0x0c045f6eu; return 0; }
target=r[2];
r[16]=0x0c045f72u;
r[4]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045f72u) { target=s->pc; goto dispatch; }
goto P_0c045f72;
P_0c045f70: /* original 54e2, guest PC 0x0c045f70 */
if(!s->budget--) { s->failed_pc=0x0c045f70u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c045f72;
P_0c045f72: /* original 5ee1, guest PC 0x0c045f72 */
if(!s->budget--) { s->failed_pc=0x0c045f72u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c045f74;
P_0c045f74: /* original 2ee8, guest PC 0x0c045f74 */
if(!s->budget--) { s->failed_pc=0x0c045f74u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c045f76;
P_0c045f76: /* original 8bf9, guest PC 0x0c045f76 */
if(!s->budget--) { s->failed_pc=0x0c045f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045f6c; }
goto P_0c045f78;
P_0c045f78: /* original 4f26, guest PC 0x0c045f78 */
if(!s->budget--) { s->failed_pc=0x0c045f78u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045f7a;
P_0c045f7a: /* original 000b, guest PC 0x0c045f7a */
if(!s->budget--) { s->failed_pc=0x0c045f7au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045f7c: /* original 6ef6, guest PC 0x0c045f7c */
if(!s->budget--) { s->failed_pc=0x0c045f7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c045f7eu,s,ram);
P_0c04d4c2: /* original 4f22, guest PC 0x0c04d4c2 */
if(!s->budget--) { s->failed_pc=0x0c04d4c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d4c4;
P_0c04d4c4: /* original 4f12, guest PC 0x0c04d4c4 */
if(!s->budget--) { s->failed_pc=0x0c04d4c4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d4c6;
P_0c04d4c6: /* original 7ffc, guest PC 0x0c04d4c6 */
if(!s->budget--) { s->failed_pc=0x0c04d4c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04d4c8;
P_0c04d4c8: /* original 2f51, guest PC 0x0c04d4c8 */
if(!s->budget--) { s->failed_pc=0x0c04d4c8u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c04d4ca;
P_0c04d4ca: /* original 9c40, guest PC 0x0c04d4ca */
if(!s->budget--) { s->failed_pc=0x0c04d4cau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d54eu,2);
goto P_0c04d4cc;
P_0c04d4cc: /* original db21, guest PC 0x0c04d4cc */
if(!s->budget--) { s->failed_pc=0x0c04d4ccu; return 0; }
r[11]=read(ram,0x0c04d554u,4);
goto P_0c04d4ce;
P_0c04d4ce: /* original 24cf, guest PC 0x0c04d4ce */
if(!s->budget--) { s->failed_pc=0x0c04d4ceu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[12]);
goto P_0c04d4d0;
P_0c04d4d0: /* original d31f, guest PC 0x0c04d4d0 */
if(!s->budget--) { s->failed_pc=0x0c04d4d0u; return 0; }
r[3]=read(ram,0x0c04d550u,4);
goto P_0c04d4d2;
P_0c04d4d2: /* original 0c1a, guest PC 0x0c04d4d2 */
if(!s->budget--) { s->failed_pc=0x0c04d4d2u; return 0; }
r[12]=r[19];
goto P_0c04d4d4;
P_0c04d4d4: /* original 6ccf, guest PC 0x0c04d4d4 */
if(!s->budget--) { s->failed_pc=0x0c04d4d4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04d4d6;
P_0c04d4d6: /* original 8f10, guest PC 0x0c04d4d6 */
if(!s->budget--) { s->failed_pc=0x0c04d4d6u; return 0; }
cond=r[17]&1u;
r[12]+=r[3];
if(!cond) { goto P_0c04d4fa; }
goto P_0c04d4da;
P_0c04d4d8: /* original 3c3c, guest PC 0x0c04d4d8 */
if(!s->budget--) { s->failed_pc=0x0c04d4d8u; return 0; }
r[12]+=r[3];
goto P_0c04d4da;
P_0c04d4da: /* original 63b2, guest PC 0x0c04d4da */
if(!s->budget--) { s->failed_pc=0x0c04d4dau; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d4dc;
P_0c04d4dc: /* original 65e3, guest PC 0x0c04d4dc */
if(!s->budget--) { s->failed_pc=0x0c04d4dcu; return 0; }
r[5]=r[14];
goto P_0c04d4de;
P_0c04d4de: /* original 4500, guest PC 0x0c04d4de */
if(!s->budget--) { s->failed_pc=0x0c04d4deu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04d4e0;
P_0c04d4e0: /* original 5233, guest PC 0x0c04d4e0 */
if(!s->budget--) { s->failed_pc=0x0c04d4e0u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04d4e2;
P_0c04d4e2: /* original 420b, guest PC 0x0c04d4e2 */
if(!s->budget--) { s->failed_pc=0x0c04d4e2u; return 0; }
target=r[2];
r[16]=0x0c04d4e6u;
r[4]=read(ram,r[12]+36,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d4e6u) { target=s->pc; goto dispatch; }
goto P_0c04d4e6;
P_0c04d4e4: /* original 54c9, guest PC 0x0c04d4e4 */
if(!s->budget--) { s->failed_pc=0x0c04d4e4u; return 0; }
r[4]=read(ram,r[12]+36,4);
goto P_0c04d4e6;
P_0c04d4e6: /* original 63f1, guest PC 0x0c04d4e6 */
if(!s->budget--) { s->failed_pc=0x0c04d4e6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c04d4e8;
P_0c04d4e8: /* original 600d, guest PC 0x0c04d4e8 */
if(!s->budget--) { s->failed_pc=0x0c04d4e8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d4ea;
P_0c04d4ea: /* original 633d, guest PC 0x0c04d4ea */
if(!s->budget--) { s->failed_pc=0x0c04d4eau; return 0; }
r[3]=r[3]&65535u;
goto P_0c04d4ec;
P_0c04d4ec: /* original 3030, guest PC 0x0c04d4ec */
if(!s->budget--) { s->failed_pc=0x0c04d4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c04d4ee;
P_0c04d4ee: /* original 8b01, guest PC 0x0c04d4ee */
if(!s->budget--) { s->failed_pc=0x0c04d4eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d4f4; }
goto P_0c04d4f0;
P_0c04d4f0: /* original a004, guest PC 0x0c04d4f0 */
if(!s->budget--) { s->failed_pc=0x0c04d4f0u; return 0; }
r[0]=r[14];
goto P_0c04d4fc;
P_0c04d4f2: /* original 60e3, guest PC 0x0c04d4f2 */
if(!s->budget--) { s->failed_pc=0x0c04d4f2u; return 0; }
r[0]=r[14];
goto P_0c04d4f4;
P_0c04d4f4: /* original 7eff, guest PC 0x0c04d4f4 */
if(!s->budget--) { s->failed_pc=0x0c04d4f4u; return 0; }
r[14]+=0xffffffffu;
goto P_0c04d4f6;
P_0c04d4f6: /* original 3ed3, guest PC 0x0c04d4f6 */
if(!s->budget--) { s->failed_pc=0x0c04d4f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c04d4f8;
P_0c04d4f8: /* original 89ef, guest PC 0x0c04d4f8 */
if(!s->budget--) { s->failed_pc=0x0c04d4f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d4da; }
goto P_0c04d4fa;
P_0c04d4fa: /* original e0ff, guest PC 0x0c04d4fa */
if(!s->budget--) { s->failed_pc=0x0c04d4fau; return 0; }
r[0]=0xffffffffu;
goto P_0c04d4fc;
P_0c04d4fc: /* original 7f04, guest PC 0x0c04d4fc */
if(!s->budget--) { s->failed_pc=0x0c04d4fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c04d4fe;
P_0c04d4fe: /* original 4f16, guest PC 0x0c04d4fe */
if(!s->budget--) { s->failed_pc=0x0c04d4feu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d500;
P_0c04d500: /* original 4f26, guest PC 0x0c04d500 */
if(!s->budget--) { s->failed_pc=0x0c04d500u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d502;
P_0c04d502: /* original 6bf6, guest PC 0x0c04d502 */
if(!s->budget--) { s->failed_pc=0x0c04d502u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d504;
P_0c04d504: /* original 6cf6, guest PC 0x0c04d504 */
if(!s->budget--) { s->failed_pc=0x0c04d504u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d506;
P_0c04d506: /* original 6df6, guest PC 0x0c04d506 */
if(!s->budget--) { s->failed_pc=0x0c04d506u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d508;
P_0c04d508: /* original 000b, guest PC 0x0c04d508 */
if(!s->budget--) { s->failed_pc=0x0c04d508u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d50a: /* original 6ef6, guest PC 0x0c04d50a */
if(!s->budget--) { s->failed_pc=0x0c04d50au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04d50cu,s,ram);
P_0c04f256: /* original 4f22, guest PC 0x0c04f256 */
if(!s->budget--) { s->failed_pc=0x0c04f256u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f258;
P_0c04f258: /* original 9d80, guest PC 0x0c04f258 */
if(!s->budget--) { s->failed_pc=0x0c04f258u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f35cu,2);
goto P_0c04f25a;
P_0c04f25a: /* original d341, guest PC 0x0c04f25a */
if(!s->budget--) { s->failed_pc=0x0c04f25au; return 0; }
r[3]=read(ram,0x0c04f360u,4);
goto P_0c04f25c;
P_0c04f25c: /* original 4f12, guest PC 0x0c04f25c */
if(!s->budget--) { s->failed_pc=0x0c04f25cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f25e;
P_0c04f25e: /* original 24df, guest PC 0x0c04f25e */
if(!s->budget--) { s->failed_pc=0x0c04f25eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[13]);
goto P_0c04f260;
P_0c04f260: /* original dc40, guest PC 0x0c04f260 */
if(!s->budget--) { s->failed_pc=0x0c04f260u; return 0; }
r[12]=read(ram,0x0c04f364u,4);
goto P_0c04f262;
P_0c04f262: /* original 0d1a, guest PC 0x0c04f262 */
if(!s->budget--) { s->failed_pc=0x0c04f262u; return 0; }
r[13]=r[19];
goto P_0c04f264;
P_0c04f264: /* original 6ddf, guest PC 0x0c04f264 */
if(!s->budget--) { s->failed_pc=0x0c04f264u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04f266;
P_0c04f266: /* original 3d3c, guest PC 0x0c04f266 */
if(!s->budget--) { s->failed_pc=0x0c04f266u; return 0; }
r[13]+=r[3];
goto P_0c04f268;
P_0c04f268: /* original a011, guest PC 0x0c04f268 */
if(!s->budget--) { s->failed_pc=0x0c04f268u; return 0; }
r[14]=0x00000000u;
goto P_0c04f28e;
P_0c04f26a: /* original ee00, guest PC 0x0c04f26a */
if(!s->budget--) { s->failed_pc=0x0c04f26au; return 0; }
r[14]=0x00000000u;
goto P_0c04f26c;
P_0c04f26c: /* original 63c2, guest PC 0x0c04f26c */
if(!s->budget--) { s->failed_pc=0x0c04f26cu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04f26e;
P_0c04f26e: /* original 65e3, guest PC 0x0c04f26e */
if(!s->budget--) { s->failed_pc=0x0c04f26eu; return 0; }
r[5]=r[14];
goto P_0c04f270;
P_0c04f270: /* original 4500, guest PC 0x0c04f270 */
if(!s->budget--) { s->failed_pc=0x0c04f270u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04f272;
P_0c04f272: /* original 5233, guest PC 0x0c04f272 */
if(!s->budget--) { s->failed_pc=0x0c04f272u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f274;
P_0c04f274: /* original 420b, guest PC 0x0c04f274 */
if(!s->budget--) { s->failed_pc=0x0c04f274u; return 0; }
target=r[2];
r[16]=0x0c04f278u;
r[4]=read(ram,r[13]+36,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f278u) { target=s->pc; goto dispatch; }
goto P_0c04f278;
P_0c04f276: /* original 54d9, guest PC 0x0c04f276 */
if(!s->budget--) { s->failed_pc=0x0c04f276u; return 0; }
r[4]=read(ram,r[13]+36,4);
goto P_0c04f278;
P_0c04f278: /* original d13b, guest PC 0x0c04f278 */
if(!s->budget--) { s->failed_pc=0x0c04f278u; return 0; }
r[1]=read(ram,0x0c04f368u,4);
goto P_0c04f27a;
P_0c04f27a: /* original 640d, guest PC 0x0c04f27a */
if(!s->budget--) { s->failed_pc=0x0c04f27au; return 0; }
r[4]=r[0]&65535u;
goto P_0c04f27c;
P_0c04f27c: /* original 6043, guest PC 0x0c04f27c */
if(!s->budget--) { s->failed_pc=0x0c04f27cu; return 0; }
r[0]=r[4];
goto P_0c04f27e;
P_0c04f27e: /* original 3010, guest PC 0x0c04f27e */
if(!s->budget--) { s->failed_pc=0x0c04f27eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f280;
P_0c04f280: /* original 8904, guest PC 0x0c04f280 */
if(!s->budget--) { s->failed_pc=0x0c04f280u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f28c; }
goto P_0c04f282;
P_0c04f282: /* original d13a, guest PC 0x0c04f282 */
if(!s->budget--) { s->failed_pc=0x0c04f282u; return 0; }
r[1]=read(ram,0x0c04f36cu,4);
goto P_0c04f284;
P_0c04f284: /* original 3010, guest PC 0x0c04f284 */
if(!s->budget--) { s->failed_pc=0x0c04f284u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f286;
P_0c04f286: /* original 8901, guest PC 0x0c04f286 */
if(!s->budget--) { s->failed_pc=0x0c04f286u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f28c; }
goto P_0c04f288;
P_0c04f288: /* original a006, guest PC 0x0c04f288 */
if(!s->budget--) { s->failed_pc=0x0c04f288u; return 0; }
r[0]=r[14];
goto P_0c04f298;
P_0c04f28a: /* original 60e3, guest PC 0x0c04f28a */
if(!s->budget--) { s->failed_pc=0x0c04f28au; return 0; }
r[0]=r[14];
goto P_0c04f28c;
P_0c04f28c: /* original 7e01, guest PC 0x0c04f28c */
if(!s->budget--) { s->failed_pc=0x0c04f28cu; return 0; }
r[14]+=0x00000001u;
goto P_0c04f28e;
P_0c04f28e: /* original 52d7, guest PC 0x0c04f28e */
if(!s->budget--) { s->failed_pc=0x0c04f28eu; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04f290;
P_0c04f290: /* original 532c, guest PC 0x0c04f290 */
if(!s->budget--) { s->failed_pc=0x0c04f290u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04f292;
P_0c04f292: /* original 3e33, guest PC 0x0c04f292 */
if(!s->budget--) { s->failed_pc=0x0c04f292u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c04f294;
P_0c04f294: /* original 8bea, guest PC 0x0c04f294 */
if(!s->budget--) { s->failed_pc=0x0c04f294u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f26c; }
goto P_0c04f296;
P_0c04f296: /* original e0ff, guest PC 0x0c04f296 */
if(!s->budget--) { s->failed_pc=0x0c04f296u; return 0; }
r[0]=0xffffffffu;
goto P_0c04f298;
P_0c04f298: /* original 4f16, guest PC 0x0c04f298 */
if(!s->budget--) { s->failed_pc=0x0c04f298u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f29a;
P_0c04f29a: /* original 4f26, guest PC 0x0c04f29a */
if(!s->budget--) { s->failed_pc=0x0c04f29au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f29c;
P_0c04f29c: /* original 6cf6, guest PC 0x0c04f29c */
if(!s->budget--) { s->failed_pc=0x0c04f29cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f29e;
P_0c04f29e: /* original 6df6, guest PC 0x0c04f29e */
if(!s->budget--) { s->failed_pc=0x0c04f29eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f2a0;
P_0c04f2a0: /* original 000b, guest PC 0x0c04f2a0 */
if(!s->budget--) { s->failed_pc=0x0c04f2a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f2a2: /* original 6ef6, guest PC 0x0c04f2a2 */
if(!s->budget--) { s->failed_pc=0x0c04f2a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f2a4u,s,ram);
P_0c04f2b0: /* original 4f22, guest PC 0x0c04f2b0 */
if(!s->budget--) { s->failed_pc=0x0c04f2b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f2b2;
P_0c04f2b2: /* original 9d53, guest PC 0x0c04f2b2 */
if(!s->budget--) { s->failed_pc=0x0c04f2b2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f35cu,2);
goto P_0c04f2b4;
P_0c04f2b4: /* original d32a, guest PC 0x0c04f2b4 */
if(!s->budget--) { s->failed_pc=0x0c04f2b4u; return 0; }
r[3]=read(ram,0x0c04f360u,4);
goto P_0c04f2b6;
P_0c04f2b6: /* original 4f12, guest PC 0x0c04f2b6 */
if(!s->budget--) { s->failed_pc=0x0c04f2b6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f2b8;
P_0c04f2b8: /* original 24df, guest PC 0x0c04f2b8 */
if(!s->budget--) { s->failed_pc=0x0c04f2b8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[13]);
goto P_0c04f2ba;
P_0c04f2ba: /* original da2a, guest PC 0x0c04f2ba */
if(!s->budget--) { s->failed_pc=0x0c04f2bau; return 0; }
r[10]=read(ram,0x0c04f364u,4);
goto P_0c04f2bc;
P_0c04f2bc: /* original dc2a, guest PC 0x0c04f2bc */
if(!s->budget--) { s->failed_pc=0x0c04f2bcu; return 0; }
r[12]=read(ram,0x0c04f368u,4);
goto P_0c04f2be;
P_0c04f2be: /* original 0d1a, guest PC 0x0c04f2be */
if(!s->budget--) { s->failed_pc=0x0c04f2beu; return 0; }
r[13]=r[19];
goto P_0c04f2c0;
P_0c04f2c0: /* original 6ddf, guest PC 0x0c04f2c0 */
if(!s->budget--) { s->failed_pc=0x0c04f2c0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04f2c2;
P_0c04f2c2: /* original 3d3c, guest PC 0x0c04f2c2 */
if(!s->budget--) { s->failed_pc=0x0c04f2c2u; return 0; }
r[13]+=r[3];
goto P_0c04f2c4;
P_0c04f2c4: /* original 5ed7, guest PC 0x0c04f2c4 */
if(!s->budget--) { s->failed_pc=0x0c04f2c4u; return 0; }
r[14]=read(ram,r[13]+28,4);
goto P_0c04f2c6;
P_0c04f2c6: /* original 5eec, guest PC 0x0c04f2c6 */
if(!s->budget--) { s->failed_pc=0x0c04f2c6u; return 0; }
r[14]=read(ram,r[14]+48,4);
goto P_0c04f2c8;
P_0c04f2c8: /* original 7eff, guest PC 0x0c04f2c8 */
if(!s->budget--) { s->failed_pc=0x0c04f2c8u; return 0; }
r[14]+=0xffffffffu;
goto P_0c04f2ca;
P_0c04f2ca: /* original 3eb3, guest PC 0x0c04f2ca */
if(!s->budget--) { s->failed_pc=0x0c04f2cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c04f2cc;
P_0c04f2cc: /* original 8b0d, guest PC 0x0c04f2cc */
if(!s->budget--) { s->failed_pc=0x0c04f2ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f2ea; }
goto P_0c04f2ce;
P_0c04f2ce: /* original 63a2, guest PC 0x0c04f2ce */
if(!s->budget--) { s->failed_pc=0x0c04f2ceu; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c04f2d0;
P_0c04f2d0: /* original 65e3, guest PC 0x0c04f2d0 */
if(!s->budget--) { s->failed_pc=0x0c04f2d0u; return 0; }
r[5]=r[14];
goto P_0c04f2d2;
P_0c04f2d2: /* original 4500, guest PC 0x0c04f2d2 */
if(!s->budget--) { s->failed_pc=0x0c04f2d2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04f2d4;
P_0c04f2d4: /* original 5233, guest PC 0x0c04f2d4 */
if(!s->budget--) { s->failed_pc=0x0c04f2d4u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f2d6;
P_0c04f2d6: /* original 420b, guest PC 0x0c04f2d6 */
if(!s->budget--) { s->failed_pc=0x0c04f2d6u; return 0; }
target=r[2];
r[16]=0x0c04f2dau;
r[4]=read(ram,r[13]+36,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f2dau) { target=s->pc; goto dispatch; }
goto P_0c04f2da;
P_0c04f2d8: /* original 54d9, guest PC 0x0c04f2d8 */
if(!s->budget--) { s->failed_pc=0x0c04f2d8u; return 0; }
r[4]=read(ram,r[13]+36,4);
goto P_0c04f2da;
P_0c04f2da: /* original 600d, guest PC 0x0c04f2da */
if(!s->budget--) { s->failed_pc=0x0c04f2dau; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f2dc;
P_0c04f2dc: /* original 30c0, guest PC 0x0c04f2dc */
if(!s->budget--) { s->failed_pc=0x0c04f2dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[12])!=0);
goto P_0c04f2de;
P_0c04f2de: /* original 8b01, guest PC 0x0c04f2de */
if(!s->budget--) { s->failed_pc=0x0c04f2deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f2e4; }
goto P_0c04f2e0;
P_0c04f2e0: /* original a004, guest PC 0x0c04f2e0 */
if(!s->budget--) { s->failed_pc=0x0c04f2e0u; return 0; }
r[0]=r[14];
goto P_0c04f2ec;
P_0c04f2e2: /* original 60e3, guest PC 0x0c04f2e2 */
if(!s->budget--) { s->failed_pc=0x0c04f2e2u; return 0; }
r[0]=r[14];
goto P_0c04f2e4;
P_0c04f2e4: /* original 7eff, guest PC 0x0c04f2e4 */
if(!s->budget--) { s->failed_pc=0x0c04f2e4u; return 0; }
r[14]+=0xffffffffu;
goto P_0c04f2e6;
P_0c04f2e6: /* original 3eb3, guest PC 0x0c04f2e6 */
if(!s->budget--) { s->failed_pc=0x0c04f2e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c04f2e8;
P_0c04f2e8: /* original 89f1, guest PC 0x0c04f2e8 */
if(!s->budget--) { s->failed_pc=0x0c04f2e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f2ce; }
goto P_0c04f2ea;
P_0c04f2ea: /* original e0ff, guest PC 0x0c04f2ea */
if(!s->budget--) { s->failed_pc=0x0c04f2eau; return 0; }
r[0]=0xffffffffu;
goto P_0c04f2ec;
P_0c04f2ec: /* original 4f16, guest PC 0x0c04f2ec */
if(!s->budget--) { s->failed_pc=0x0c04f2ecu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f2ee;
P_0c04f2ee: /* original 4f26, guest PC 0x0c04f2ee */
if(!s->budget--) { s->failed_pc=0x0c04f2eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f2f0;
P_0c04f2f0: /* original 6af6, guest PC 0x0c04f2f0 */
if(!s->budget--) { s->failed_pc=0x0c04f2f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04f2f2;
P_0c04f2f2: /* original 6bf6, guest PC 0x0c04f2f2 */
if(!s->budget--) { s->failed_pc=0x0c04f2f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04f2f4;
P_0c04f2f4: /* original 6cf6, guest PC 0x0c04f2f4 */
if(!s->budget--) { s->failed_pc=0x0c04f2f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f2f6;
P_0c04f2f6: /* original 6df6, guest PC 0x0c04f2f6 */
if(!s->budget--) { s->failed_pc=0x0c04f2f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f2f8;
P_0c04f2f8: /* original 000b, guest PC 0x0c04f2f8 */
if(!s->budget--) { s->failed_pc=0x0c04f2f8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f2fa: /* original 6ef6, guest PC 0x0c04f2fa */
if(!s->budget--) { s->failed_pc=0x0c04f2fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f2fcu,s,ram);
P_0c058b80: /* original 4f22, guest PC 0x0c058b80 */
if(!s->budget--) { s->failed_pc=0x0c058b80u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058b82;
P_0c058b82: /* original 4f13, guest PC 0x0c058b82 */
if(!s->budget--) { s->failed_pc=0x0c058b82u; return 0; }
if(!s->gbr_known) goto unsupported;
r[15]-=4; write(ram,r[15],s->gbr,4);
goto P_0c058b84;
P_0c058b84: /* original 5c10, guest PC 0x0c058b84 */
if(!s->budget--) { s->failed_pc=0x0c058b84u; return 0; }
r[12]=read(ram,r[1]+0,4);
goto P_0c058b86;
P_0c058b86: /* original 6303, guest PC 0x0c058b86 */
if(!s->budget--) { s->failed_pc=0x0c058b86u; return 0; }
r[3]=r[0];
goto P_0c058b88;
P_0c058b88: /* original 5012, guest PC 0x0c058b88 */
if(!s->budget--) { s->failed_pc=0x0c058b88u; return 0; }
r[0]=read(ram,r[1]+8,4);
goto P_0c058b8a;
P_0c058b8a: /* original 4317, guest PC 0x0c058b8a */
if(!s->budget--) { s->failed_pc=0x0c058b8au; return 0; }
s->gbr=read(ram,r[3],4); r[3]+=4; s->gbr_known=1;
goto P_0c058b8c;
P_0c058b8c: /* original 432a, guest PC 0x0c058b8c */
if(!s->budget--) { s->failed_pc=0x0c058b8cu; return 0; }
r[16]=r[3];
goto P_0c058b8e;
P_0c058b8e: /* original 2c29, guest PC 0x0c058b8e */
if(!s->budget--) { s->failed_pc=0x0c058b8eu; return 0; }
r[12]&=r[2];
goto P_0c058b90;
P_0c058b90: /* original fffb, guest PC 0x0c058b90 */
if(!s->budget--) { s->failed_pc=0x0c058b90u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c058b92;
P_0c058b92: /* original 2029, guest PC 0x0c058b92 */
if(!s->budget--) { s->failed_pc=0x0c058b92u; return 0; }
r[0]&=r[2];
goto P_0c058b94;
P_0c058b94: /* original ffeb, guest PC 0x0c058b94 */
if(!s->budget--) { s->failed_pc=0x0c058b94u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c058b96;
P_0c058b96: /* original 2c7b, guest PC 0x0c058b96 */
if(!s->budget--) { s->failed_pc=0x0c058b96u; return 0; }
r[12]|=r[7];
goto P_0c058b98;
P_0c058b98: /* original ffdb, guest PC 0x0c058b98 */
if(!s->budget--) { s->failed_pc=0x0c058b98u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c058b9a;
P_0c058b9a: /* original 207b, guest PC 0x0c058b9a */
if(!s->budget--) { s->failed_pc=0x0c058b9au; return 0; }
r[0]|=r[7];
goto P_0c058b9c;
P_0c058b9c: /* original ffcb, guest PC 0x0c058b9c */
if(!s->budget--) { s->failed_pc=0x0c058b9cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c058b9e;
P_0c058b9e: /* original c214, guest PC 0x0c058b9e */
if(!s->budget--) { s->failed_pc=0x0c058b9eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+80,r[0],4);
goto P_0c058ba0;
P_0c058ba0: /* original 60c3, guest PC 0x0c058ba0 */
if(!s->budget--) { s->failed_pc=0x0c058ba0u; return 0; }
r[0]=r[12];
goto P_0c058ba2;
P_0c058ba2: /* original a00d, guest PC 0x0c058ba2 */
if(!s->budget--) { s->failed_pc=0x0c058ba2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+72,r[0],4);
goto P_0c058bc0;
P_0c058ba4: /* original c212, guest PC 0x0c058ba4 */
if(!s->budget--) { s->failed_pc=0x0c058ba4u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+72,r[0],4);
return vf3_matrix_family(0x0c058ba6u,s,ram);
P_0c058bc0: /* original 6d43, guest PC 0x0c058bc0 */
if(!s->budget--) { s->failed_pc=0x0c058bc0u; return 0; }
r[13]=r[4];
goto P_0c058bc2;
P_0c058bc2: /* original 7410, guest PC 0x0c058bc2 */
if(!s->budget--) { s->failed_pc=0x0c058bc2u; return 0; }
r[4]+=0x00000010u;
goto P_0c058bc4;
P_0c058bc4: /* original c60a, guest PC 0x0c058bc4 */
if(!s->budget--) { s->failed_pc=0x0c058bc4u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+40,4);
goto P_0c058bc6;
P_0c058bc6: /* original f049, guest PC 0x0c058bc6 */
if(!s->budget--) { s->failed_pc=0x0c058bc6u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c058bc8;
P_0c058bc8: /* original f149, guest PC 0x0c058bc8 */
if(!s->budget--) { s->failed_pc=0x0c058bc8u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c058bca;
P_0c058bca: /* original f249, guest PC 0x0c058bca */
if(!s->budget--) { s->failed_pc=0x0c058bcau; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c058bcc;
P_0c058bcc: /* original f39d, guest PC 0x0c058bcc */
if(!s->budget--) { s->failed_pc=0x0c058bccu; return 0; }
fr[3]=0x3f800000u;
goto P_0c058bce;
P_0c058bce: /* original d337, guest PC 0x0c058bce */
if(!s->budget--) { s->failed_pc=0x0c058bceu; return 0; }
r[3]=read(ram,0x0c058cacu,4);
goto P_0c058bd0;
P_0c058bd0: /* original f1fd, guest PC 0x0c058bd0 */
if(!s->budget--) { s->failed_pc=0x0c058bd0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c058bd2;
P_0c058bd2: /* original 405a, guest PC 0x0c058bd2 */
if(!s->budget--) { s->failed_pc=0x0c058bd2u; return 0; }
r[53]=r[0];
goto P_0c058bd4;
P_0c058bd4: /* original f60d, guest PC 0x0c058bd4 */
if(!s->budget--) { s->failed_pc=0x0c058bd4u; return 0; }
fr[6]=r[53];
goto P_0c058bd6;
P_0c058bd6: /* original f448, guest PC 0x0c058bd6 */
if(!s->budget--) { s->failed_pc=0x0c058bd6u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c058bd8;
P_0c058bd8: /* original f538, guest PC 0x0c058bd8 */
if(!s->budget--) { s->failed_pc=0x0c058bd8u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c058bda;
P_0c058bda: /* original f24d, guest PC 0x0c058bda */
if(!s->budget--) { s->failed_pc=0x0c058bdau; return 0; }
fr[2]^=0x80000000u;
goto P_0c058bdc;
P_0c058bdc: /* original f462, guest PC 0x0c058bdc */
if(!s->budget--) { s->failed_pc=0x0c058bdcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c058bde;
P_0c058bde: /* original f12c, guest PC 0x0c058bde */
if(!s->budget--) { s->failed_pc=0x0c058bdeu; return 0; }
vf3_matrix_move(s,1,2);
goto P_0c058be0;
P_0c058be0: /* original f140, guest PC 0x0c058be0 */
if(!s->budget--) { s->failed_pc=0x0c058be0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c058be2;
P_0c058be2: /* original f08d, guest PC 0x0c058be2 */
if(!s->budget--) { s->failed_pc=0x0c058be2u; return 0; }
fr[0]=0;
goto P_0c058be4;
P_0c058be4: /* original f241, guest PC 0x0c058be4 */
if(!s->budget--) { s->failed_pc=0x0c058be4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c058be6;
P_0c058be6: /* original f015, guest PC 0x0c058be6 */
if(!s->budget--) { s->failed_pc=0x0c058be6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[1]))!=0);
goto P_0c058be8;
P_0c058be8: /* original d331, guest PC 0x0c058be8 */
if(!s->budget--) { s->failed_pc=0x0c058be8u; return 0; }
r[3]=read(ram,0x0c058cb0u,4);
goto P_0c058bea;
P_0c058bea: /* original 8d5c, guest PC 0x0c058bea */
if(!s->budget--) { s->failed_pc=0x0c058beau; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[5]))!=0);
if(cond) { goto P_0c058ca6; }
goto P_0c058bee;
P_0c058bec: /* original f255, guest PC 0x0c058bec */
if(!s->budget--) { s->failed_pc=0x0c058becu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[5]))!=0);
goto P_0c058bee;
P_0c058bee: /* original 895a, guest PC 0x0c058bee */
if(!s->budget--) { s->failed_pc=0x0c058beeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058ca6; }
goto P_0c058bf0;
P_0c058bf0: /* original 4f22, guest PC 0x0c058bf0 */
if(!s->budget--) { s->failed_pc=0x0c058bf0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058bf2;
P_0c058bf2: /* original 430b, guest PC 0x0c058bf2 */
if(!s->budget--) { s->failed_pc=0x0c058bf2u; return 0; }
target=r[3];
r[16]=0x0c058bf6u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058bf6u) { target=s->pc; goto dispatch; }
goto P_0c058bf6;
P_0c058bf4: /* original e400, guest PC 0x0c058bf4 */
if(!s->budget--) { s->failed_pc=0x0c058bf4u; return 0; }
r[4]=0x00000000u;
goto P_0c058bf6;
P_0c058bf6: /* original c605, guest PC 0x0c058bf6 */
if(!s->budget--) { s->failed_pc=0x0c058bf6u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+20,4);
goto P_0c058bf8;
P_0c058bf8: /* original 400b, guest PC 0x0c058bf8 */
if(!s->budget--) { s->failed_pc=0x0c058bf8u; return 0; }
target=r[0];
r[16]=0x0c058bfcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058bfcu) { target=s->pc; goto dispatch; }
goto P_0c058bfc;
P_0c058bfa: /* original 0009, guest PC 0x0c058bfa */
if(!s->budget--) { s->failed_pc=0x0c058bfau; return 0; }
goto P_0c058bfc;
P_0c058bfc: /* original c72e, guest PC 0x0c058bfc */
if(!s->budget--) { s->failed_pc=0x0c058bfcu; return 0; }
r[0]=0x0c058cb8u;
goto P_0c058bfe;
P_0c058bfe: /* original d32d, guest PC 0x0c058bfe */
if(!s->budget--) { s->failed_pc=0x0c058bfeu; return 0; }
r[3]=read(ram,0x0c058cb4u,4);
goto P_0c058c00;
P_0c058c00: /* original f409, guest PC 0x0c058c00 */
if(!s->budget--) { s->failed_pc=0x0c058c00u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c058c02;
P_0c058c02: /* original 430b, guest PC 0x0c058c02 */
if(!s->budget--) { s->failed_pc=0x0c058c02u; return 0; }
target=r[3];
r[16]=0x0c058c06u;
vf3_matrix_load(s,ram,5,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058c06u) { target=s->pc; goto dispatch; }
goto P_0c058c06;
P_0c058c04: /* original f508, guest PC 0x0c058c04 */
if(!s->budget--) { s->failed_pc=0x0c058c04u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c058c06;
P_0c058c06: /* original 64d3, guest PC 0x0c058c06 */
if(!s->budget--) { s->failed_pc=0x0c058c06u; return 0; }
r[4]=r[13];
goto P_0c058c08;
P_0c058c08: /* original 7410, guest PC 0x0c058c08 */
if(!s->budget--) { s->failed_pc=0x0c058c08u; return 0; }
r[4]+=0x00000010u;
goto P_0c058c0a;
P_0c058c0a: /* original c60a, guest PC 0x0c058c0a */
if(!s->budget--) { s->failed_pc=0x0c058c0au; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+40,4);
goto P_0c058c0c;
P_0c058c0c: /* original f049, guest PC 0x0c058c0c */
if(!s->budget--) { s->failed_pc=0x0c058c0cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c058c0e;
P_0c058c0e: /* original f149, guest PC 0x0c058c0e */
if(!s->budget--) { s->failed_pc=0x0c058c0eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c058c10;
P_0c058c10: /* original f249, guest PC 0x0c058c10 */
if(!s->budget--) { s->failed_pc=0x0c058c10u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c058c12;
P_0c058c12: /* original f39d, guest PC 0x0c058c12 */
if(!s->budget--) { s->failed_pc=0x0c058c12u; return 0; }
fr[3]=0x3f800000u;
goto P_0c058c14;
P_0c058c14: /* original f1fd, guest PC 0x0c058c14 */
if(!s->budget--) { s->failed_pc=0x0c058c14u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c058c16;
P_0c058c16: /* original 405a, guest PC 0x0c058c16 */
if(!s->budget--) { s->failed_pc=0x0c058c16u; return 0; }
r[53]=r[0];
goto P_0c058c18;
P_0c058c18: /* original f60d, guest PC 0x0c058c18 */
if(!s->budget--) { s->failed_pc=0x0c058c18u; return 0; }
fr[6]=r[53];
goto P_0c058c1a;
P_0c058c1a: /* original f448, guest PC 0x0c058c1a */
if(!s->budget--) { s->failed_pc=0x0c058c1au; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c058c1c;
P_0c058c1c: /* original f28d, guest PC 0x0c058c1c */
if(!s->budget--) { s->failed_pc=0x0c058c1cu; return 0; }
fr[2]=0;
goto P_0c058c1e;
P_0c058c1e: /* original f59d, guest PC 0x0c058c1e */
if(!s->budget--) { s->failed_pc=0x0c058c1eu; return 0; }
fr[5]=0x3f800000u;
goto P_0c058c20;
P_0c058c20: /* original f235, guest PC 0x0c058c20 */
if(!s->budget--) { s->failed_pc=0x0c058c20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c058c22;
P_0c058c22: /* original f24c, guest PC 0x0c058c22 */
if(!s->budget--) { s->failed_pc=0x0c058c22u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c058c24;
P_0c058c24: /* original f262, guest PC 0x0c058c24 */
if(!s->budget--) { s->failed_pc=0x0c058c24u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c058c26;
P_0c058c26: /* original 8b00, guest PC 0x0c058c26 */
if(!s->budget--) { s->failed_pc=0x0c058c26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058c2a; }
goto P_0c058c28;
P_0c058c28: /* original f54d, guest PC 0x0c058c28 */
if(!s->budget--) { s->failed_pc=0x0c058c28u; return 0; }
fr[5]^=0x80000000u;
goto P_0c058c2a;
P_0c058c2a: /* original f533, guest PC 0x0c058c2a */
if(!s->budget--) { s->failed_pc=0x0c058c2au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'/');
goto P_0c058c2c;
P_0c058c2c: /* original c722, guest PC 0x0c058c2c */
if(!s->budget--) { s->failed_pc=0x0c058c2cu; return 0; }
r[0]=0x0c058cb8u;
goto P_0c058c2e;
P_0c058c2e: /* original f609, guest PC 0x0c058c2e */
if(!s->budget--) { s->failed_pc=0x0c058c2eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c058c30;
P_0c058c30: /* original f708, guest PC 0x0c058c30 */
if(!s->budget--) { s->failed_pc=0x0c058c30u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c058c32;
P_0c058c32: /* original f152, guest PC 0x0c058c32 */
if(!s->budget--) { s->failed_pc=0x0c058c32u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c058c34;
P_0c058c34: /* original f30c, guest PC 0x0c058c34 */
if(!s->budget--) { s->failed_pc=0x0c058c34u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c058c36;
P_0c058c36: /* original f352, guest PC 0x0c058c36 */
if(!s->budget--) { s->failed_pc=0x0c058c36u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c058c38;
P_0c058c38: /* original f462, guest PC 0x0c058c38 */
if(!s->budget--) { s->failed_pc=0x0c058c38u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c058c3a;
P_0c058c3a: /* original f05c, guest PC 0x0c058c3a */
if(!s->budget--) { s->failed_pc=0x0c058c3au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c058c3c;
P_0c058c3c: /* original f272, guest PC 0x0c058c3c */
if(!s->budget--) { s->failed_pc=0x0c058c3cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c058c3e;
P_0c058c3e: /* original f550, guest PC 0x0c058c3e */
if(!s->budget--) { s->failed_pc=0x0c058c3eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[5],r[18],'+');
goto P_0c058c40;
P_0c058c40: /* original f34e, guest PC 0x0c058c40 */
if(!s->budget--) { s->failed_pc=0x0c058c40u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c058c42;
P_0c058c42: /* original f12e, guest PC 0x0c058c42 */
if(!s->budget--) { s->failed_pc=0x0c058c42u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[2],fr[1],r[18]);
goto P_0c058c44;
P_0c058c44: /* original d11e, guest PC 0x0c058c44 */
if(!s->budget--) { s->failed_pc=0x0c058c44u; return 0; }
r[1]=read(ram,0x0c058cc0u,4);
goto P_0c058c46;
P_0c058c46: /* original f452, guest PC 0x0c058c46 */
if(!s->budget--) { s->failed_pc=0x0c058c46u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c058c48;
P_0c058c48: /* original f08d, guest PC 0x0c058c48 */
if(!s->budget--) { s->failed_pc=0x0c058c48u; return 0; }
fr[0]=0;
goto P_0c058c4a;
P_0c058c4a: /* original f305, guest PC 0x0c058c4a */
if(!s->budget--) { s->failed_pc=0x0c058c4au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[0]))!=0);
goto P_0c058c4c;
P_0c058c4c: /* original f252, guest PC 0x0c058c4c */
if(!s->budget--) { s->failed_pc=0x0c058c4cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c058c4e;
P_0c058c4e: /* original 8f26, guest PC 0x0c058c4e */
if(!s->budget--) { s->failed_pc=0x0c058c4eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[0]))!=0);
if(!cond) { goto P_0c058c9e; }
goto P_0c058c52;
P_0c058c50: /* original f105, guest PC 0x0c058c50 */
if(!s->budget--) { s->failed_pc=0x0c058c50u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[0]))!=0);
goto P_0c058c52;
P_0c058c52: /* original c604, guest PC 0x0c058c52 */
if(!s->budget--) { s->failed_pc=0x0c058c52u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+16,4);
goto P_0c058c54;
P_0c058c54: /* original f341, guest PC 0x0c058c54 */
if(!s->budget--) { s->failed_pc=0x0c058c54u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c058c56;
P_0c058c56: /* original 8f22, guest PC 0x0c058c56 */
if(!s->budget--) { s->failed_pc=0x0c058c56u; return 0; }
cond=r[17]&1u;
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
if(!cond) { goto P_0c058c9e; }
goto P_0c058c5a;
P_0c058c58: /* original f121, guest PC 0x0c058c58 */
if(!s->budget--) { s->failed_pc=0x0c058c58u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c058c5a;
P_0c058c5a: /* original f365, guest PC 0x0c058c5a */
if(!s->budget--) { s->failed_pc=0x0c058c5au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c058c5c;
P_0c058c5c: /* original 54d1, guest PC 0x0c058c5c */
if(!s->budget--) { s->failed_pc=0x0c058c5cu; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c058c5e;
P_0c058c5e: /* original 8d1e, guest PC 0x0c058c5e */
if(!s->budget--) { s->failed_pc=0x0c058c5eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[7]))!=0);
if(cond) { goto P_0c058c9e; }
goto P_0c058c62;
P_0c058c60: /* original f175, guest PC 0x0c058c60 */
if(!s->budget--) { s->failed_pc=0x0c058c60u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[7]))!=0);
goto P_0c058c62;
P_0c058c62: /* original 56d2, guest PC 0x0c058c62 */
if(!s->budget--) { s->failed_pc=0x0c058c62u; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c058c64;
P_0c058c64: /* original 891b, guest PC 0x0c058c64 */
if(!s->budget--) { s->failed_pc=0x0c058c64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058c9e; }
goto P_0c058c66;
P_0c058c66: /* original 67d3, guest PC 0x0c058c66 */
if(!s->budget--) { s->failed_pc=0x0c058c66u; return 0; }
r[7]=r[13];
goto P_0c058c68;
P_0c058c68: /* original 400b, guest PC 0x0c058c68 */
if(!s->budget--) { s->failed_pc=0x0c058c68u; return 0; }
target=r[0];
r[16]=0x0c058c6cu;
tmp=read(ram,r[1],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058c6cu) { target=s->pc; goto dispatch; }
goto P_0c058c6c;
P_0c058c6a: /* original 6512, guest PC 0x0c058c6a */
if(!s->budget--) { s->failed_pc=0x0c058c6au; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c058c6c;
P_0c058c6c: /* original c717, guest PC 0x0c058c6c */
if(!s->budget--) { s->failed_pc=0x0c058c6cu; return 0; }
r[0]=0x0c058cccu;
goto P_0c058c6e;
P_0c058c6e: /* original da18, guest PC 0x0c058c6e */
if(!s->budget--) { s->failed_pc=0x0c058c6eu; return 0; }
r[10]=read(ram,0x0c058cd0u,4);
goto P_0c058c70;
P_0c058c70: /* original f308, guest PC 0x0c058c70 */
if(!s->budget--) { s->failed_pc=0x0c058c70u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c058c72;
P_0c058c72: /* original d313, guest PC 0x0c058c72 */
if(!s->budget--) { s->failed_pc=0x0c058c72u; return 0; }
r[3]=read(ram,0x0c058cc0u,4);
goto P_0c058c74;
P_0c058c74: /* original e1f0, guest PC 0x0c058c74 */
if(!s->budget--) { s->failed_pc=0x0c058c74u; return 0; }
r[1]=0xfffffff0u;
goto P_0c058c76;
P_0c058c76: /* original c603, guest PC 0x0c058c76 */
if(!s->budget--) { s->failed_pc=0x0c058c76u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+12,4);
goto P_0c058c78;
P_0c058c78: /* original 4128, guest PC 0x0c058c78 */
if(!s->budget--) { s->failed_pc=0x0c058c78u; return 0; }
r[1]<<=16;
goto P_0c058c7a;
P_0c058c7a: /* original 54d3, guest PC 0x0c058c7a */
if(!s->budget--) { s->failed_pc=0x0c058c7au; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c058c7c;
P_0c058c7c: /* original 4118, guest PC 0x0c058c7c */
if(!s->budget--) { s->failed_pc=0x0c058c7cu; return 0; }
r[1]<<=8;
goto P_0c058c7e;
P_0c058c7e: /* original 6aa2, guest PC 0x0c058c7e */
if(!s->budget--) { s->failed_pc=0x0c058c7eu; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c058c80;
P_0c058c80: /* original e200, guest PC 0x0c058c80 */
if(!s->budget--) { s->failed_pc=0x0c058c80u; return 0; }
r[2]=0x00000000u;
goto P_0c058c82;
P_0c058c82: /* original 6e03, guest PC 0x0c058c82 */
if(!s->budget--) { s->failed_pc=0x0c058c82u; return 0; }
r[14]=r[0];
goto P_0c058c84;
P_0c058c84: /* original 42be, guest PC 0x0c058c84 */
if(!s->budget--) { s->failed_pc=0x0c058c84u; return 0; }
if(!s->bank_known) goto unsupported;
s->bank[3]=r[2];
goto P_0c058c86;
P_0c058c86: /* original 6d32, guest PC 0x0c058c86 */
if(!s->budget--) { s->failed_pc=0x0c058c86u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c058c88;
P_0c058c88: /* original 41ce, guest PC 0x0c058c88 */
if(!s->budget--) { s->failed_pc=0x0c058c88u; return 0; }
if(!s->bank_known) goto unsupported;
s->bank[4]=r[1];
goto P_0c058c8a;
P_0c058c8a: /* original 6041, guest PC 0x0c058c8a */
if(!s->budget--) { s->failed_pc=0x0c058c8au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c058c8c;
P_0c058c8c: /* original 4011, guest PC 0x0c058c8c */
if(!s->budget--) { s->failed_pc=0x0c058c8cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c058c8e;
P_0c058c8e: /* original 600c, guest PC 0x0c058c8e */
if(!s->budget--) { s->failed_pc=0x0c058c8eu; return 0; }
r[0]=r[0]&255u;
goto P_0c058c90;
P_0c058c90: /* original 8f05, guest PC 0x0c058c90 */
if(!s->budget--) { s->failed_pc=0x0c058c90u; return 0; }
cond=r[17]&1u;
r[0]<<=2;
if(!cond) { goto P_0c058c9e; }
goto P_0c058c94;
P_0c058c92: /* original 4008, guest PC 0x0c058c92 */
if(!s->budget--) { s->failed_pc=0x0c058c92u; return 0; }
r[0]<<=2;
goto P_0c058c94;
P_0c058c94: /* original 03ee, guest PC 0x0c058c94 */
if(!s->budget--) { s->failed_pc=0x0c058c94u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c058c96;
P_0c058c96: /* original 430b, guest PC 0x0c058c96 */
if(!s->budget--) { s->failed_pc=0x0c058c96u; return 0; }
target=r[3];
r[16]=0x0c058c9au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058c9au) { target=s->pc; goto dispatch; }
goto P_0c058c9a;
P_0c058c98: /* original 0009, guest PC 0x0c058c98 */
if(!s->budget--) { s->failed_pc=0x0c058c98u; return 0; }
goto P_0c058c9a;
P_0c058c9a: /* original aff7, guest PC 0x0c058c9a */
if(!s->budget--) { s->failed_pc=0x0c058c9au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c058c8c;
P_0c058c9c: /* original 6041, guest PC 0x0c058c9c */
if(!s->budget--) { s->failed_pc=0x0c058c9cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c058c9e;
P_0c058c9e: /* original d30d, guest PC 0x0c058c9e */
if(!s->budget--) { s->failed_pc=0x0c058c9eu; return 0; }
r[3]=read(ram,0x0c058cd4u,4);
goto P_0c058ca0;
P_0c058ca0: /* original 4f26, guest PC 0x0c058ca0 */
if(!s->budget--) { s->failed_pc=0x0c058ca0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058ca2;
P_0c058ca2: /* original 432b, guest PC 0x0c058ca2 */
if(!s->budget--) { s->failed_pc=0x0c058ca2u; return 0; }
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
P_0c058ca4: /* original e401, guest PC 0x0c058ca4 */
if(!s->budget--) { s->failed_pc=0x0c058ca4u; return 0; }
r[4]=0x00000001u;
goto P_0c058ca6;
P_0c058ca6: /* original 000b, guest PC 0x0c058ca6 */
if(!s->budget--) { s->failed_pc=0x0c058ca6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c058ca8: /* original 0009, guest PC 0x0c058ca8 */
if(!s->budget--) { s->failed_pc=0x0c058ca8u; return 0; }
return vf3_matrix_family(0x0c058caau,s,ram);
P_0c058d70: /* original 4f22, guest PC 0x0c058d70 */
if(!s->budget--) { s->failed_pc=0x0c058d70u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058d72;
P_0c058d72: /* original 4f13, guest PC 0x0c058d72 */
if(!s->budget--) { s->failed_pc=0x0c058d72u; return 0; }
if(!s->gbr_known) goto unsupported;
r[15]-=4; write(ram,r[15],s->gbr,4);
goto P_0c058d74;
P_0c058d74: /* original 4017, guest PC 0x0c058d74 */
if(!s->budget--) { s->failed_pc=0x0c058d74u; return 0; }
s->gbr=read(ram,r[0],4); r[0]+=4; s->gbr_known=1;
goto P_0c058d76;
P_0c058d76: /* original 402a, guest PC 0x0c058d76 */
if(!s->budget--) { s->failed_pc=0x0c058d76u; return 0; }
r[16]=r[0];
goto P_0c058d78;
P_0c058d78: /* original 267b, guest PC 0x0c058d78 */
if(!s->budget--) { s->failed_pc=0x0c058d78u; return 0; }
r[6]|=r[7];
goto P_0c058d7a;
P_0c058d7a: /* original 237b, guest PC 0x0c058d7a */
if(!s->budget--) { s->failed_pc=0x0c058d7au; return 0; }
r[3]|=r[7];
goto P_0c058d7c;
P_0c058d7c: /* original 6063, guest PC 0x0c058d7c */
if(!s->budget--) { s->failed_pc=0x0c058d7cu; return 0; }
r[0]=r[6];
goto P_0c058d7e;
P_0c058d7e: /* original c212, guest PC 0x0c058d7e */
if(!s->budget--) { s->failed_pc=0x0c058d7eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+72,r[0],4);
goto P_0c058d80;
P_0c058d80: /* original 6033, guest PC 0x0c058d80 */
if(!s->budget--) { s->failed_pc=0x0c058d80u; return 0; }
r[0]=r[3];
goto P_0c058d82;
P_0c058d82: /* original c214, guest PC 0x0c058d82 */
if(!s->budget--) { s->failed_pc=0x0c058d82u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+80,r[0],4);
goto P_0c058d84;
P_0c058d84: /* original 5d40, guest PC 0x0c058d84 */
if(!s->budget--) { s->failed_pc=0x0c058d84u; return 0; }
r[13]=read(ram,r[4]+0,4);
goto P_0c058d86;
P_0c058d86: /* original 6e43, guest PC 0x0c058d86 */
if(!s->budget--) { s->failed_pc=0x0c058d86u; return 0; }
r[14]=r[4];
goto P_0c058d88;
P_0c058d88: /* original 4f22, guest PC 0x0c058d88 */
if(!s->budget--) { s->failed_pc=0x0c058d88u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058d8a;
P_0c058d8a: /* original 60d3, guest PC 0x0c058d8a */
if(!s->budget--) { s->failed_pc=0x0c058d8au; return 0; }
r[0]=r[13];
goto P_0c058d8c;
P_0c058d8c: /* original c83e, guest PC 0x0c058d8c */
if(!s->budget--) { s->failed_pc=0x0c058d8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c058d8e;
P_0c058d8e: /* original 2fd6, guest PC 0x0c058d8e */
if(!s->budget--) { s->failed_pc=0x0c058d8eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c058d90;
P_0c058d90: /* original 8927, guest PC 0x0c058d90 */
if(!s->budget--) { s->failed_pc=0x0c058d90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058de2; }
goto P_0c058d92;
P_0c058d92: /* original d122, guest PC 0x0c058d92 */
if(!s->budget--) { s->failed_pc=0x0c058d92u; return 0; }
r[1]=read(ram,0x0c058e1cu,4);
goto P_0c058d94;
P_0c058d94: /* original 410b, guest PC 0x0c058d94 */
if(!s->budget--) { s->failed_pc=0x0c058d94u; return 0; }
target=r[1];
r[16]=0x0c058d98u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058d98u) { target=s->pc; goto dispatch; }
goto P_0c058d98;
P_0c058d96: /* original e400, guest PC 0x0c058d96 */
if(!s->budget--) { s->failed_pc=0x0c058d96u; return 0; }
r[4]=0x00000000u;
goto P_0c058d98;
P_0c058d98: /* original 60d3, guest PC 0x0c058d98 */
if(!s->budget--) { s->failed_pc=0x0c058d98u; return 0; }
r[0]=r[13];
goto P_0c058d9a;
P_0c058d9a: /* original c802, guest PC 0x0c058d9a */
if(!s->budget--) { s->failed_pc=0x0c058d9au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c058d9c;
P_0c058d9c: /* original d120, guest PC 0x0c058d9c */
if(!s->budget--) { s->failed_pc=0x0c058d9cu; return 0; }
r[1]=read(ram,0x0c058e20u,4);
goto P_0c058d9e;
P_0c058d9e: /* original 64e3, guest PC 0x0c058d9e */
if(!s->budget--) { s->failed_pc=0x0c058d9eu; return 0; }
r[4]=r[14];
goto P_0c058da0;
P_0c058da0: /* original 8d05, guest PC 0x0c058da0 */
if(!s->budget--) { s->failed_pc=0x0c058da0u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(cond) { goto P_0c058dae; }
goto P_0c058da4;
P_0c058da2: /* original 7408, guest PC 0x0c058da2 */
if(!s->budget--) { s->failed_pc=0x0c058da2u; return 0; }
r[4]+=0x00000008u;
goto P_0c058da4;
P_0c058da4: /* original f449, guest PC 0x0c058da4 */
if(!s->budget--) { s->failed_pc=0x0c058da4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c058da6;
P_0c058da6: /* original f549, guest PC 0x0c058da6 */
if(!s->budget--) { s->failed_pc=0x0c058da6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c058da8;
P_0c058da8: /* original 410b, guest PC 0x0c058da8 */
if(!s->budget--) { s->failed_pc=0x0c058da8u; return 0; }
target=r[1];
r[16]=0x0c058dacu;
vf3_matrix_load(s,ram,6,r[4]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058dacu) { target=s->pc; goto dispatch; }
goto P_0c058dac;
P_0c058daa: /* original f648, guest PC 0x0c058daa */
if(!s->budget--) { s->failed_pc=0x0c058daau; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c058dac;
P_0c058dac: /* original 60d3, guest PC 0x0c058dac */
if(!s->budget--) { s->failed_pc=0x0c058dacu; return 0; }
r[0]=r[13];
goto P_0c058dae;
P_0c058dae: /* original c838, guest PC 0x0c058dae */
if(!s->budget--) { s->failed_pc=0x0c058daeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&56u)==0)!=0);
goto P_0c058db0;
P_0c058db0: /* original 8d11, guest PC 0x0c058db0 */
if(!s->budget--) { s->failed_pc=0x0c058db0u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(cond) { goto P_0c058dd6; }
goto P_0c058db4;
P_0c058db2: /* original c820, guest PC 0x0c058db2 */
if(!s->budget--) { s->failed_pc=0x0c058db2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c058db4;
P_0c058db4: /* original d31b, guest PC 0x0c058db4 */
if(!s->budget--) { s->failed_pc=0x0c058db4u; return 0; }
r[3]=read(ram,0x0c058e24u,4);
goto P_0c058db6;
P_0c058db6: /* original 8902, guest PC 0x0c058db6 */
if(!s->budget--) { s->failed_pc=0x0c058db6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058dbe; }
goto P_0c058db8;
P_0c058db8: /* original 430b, guest PC 0x0c058db8 */
if(!s->budget--) { s->failed_pc=0x0c058db8u; return 0; }
target=r[3];
r[16]=0x0c058dbcu;
r[4]=read(ram,r[14]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058dbcu) { target=s->pc; goto dispatch; }
goto P_0c058dbc;
P_0c058dba: /* original 54e7, guest PC 0x0c058dba */
if(!s->budget--) { s->failed_pc=0x0c058dbau; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c058dbc;
P_0c058dbc: /* original 60d3, guest PC 0x0c058dbc */
if(!s->budget--) { s->failed_pc=0x0c058dbcu; return 0; }
r[0]=r[13];
goto P_0c058dbe;
P_0c058dbe: /* original c810, guest PC 0x0c058dbe */
if(!s->budget--) { s->failed_pc=0x0c058dbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c058dc0;
P_0c058dc0: /* original d219, guest PC 0x0c058dc0 */
if(!s->budget--) { s->failed_pc=0x0c058dc0u; return 0; }
r[2]=read(ram,0x0c058e28u,4);
goto P_0c058dc2;
P_0c058dc2: /* original 8902, guest PC 0x0c058dc2 */
if(!s->budget--) { s->failed_pc=0x0c058dc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058dca; }
goto P_0c058dc4;
P_0c058dc4: /* original 420b, guest PC 0x0c058dc4 */
if(!s->budget--) { s->failed_pc=0x0c058dc4u; return 0; }
target=r[2];
r[16]=0x0c058dc8u;
r[4]=read(ram,r[14]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058dc8u) { target=s->pc; goto dispatch; }
goto P_0c058dc8;
P_0c058dc6: /* original 54e6, guest PC 0x0c058dc6 */
if(!s->budget--) { s->failed_pc=0x0c058dc6u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c058dc8;
P_0c058dc8: /* original 60d3, guest PC 0x0c058dc8 */
if(!s->budget--) { s->failed_pc=0x0c058dc8u; return 0; }
r[0]=r[13];
goto P_0c058dca;
P_0c058dca: /* original c808, guest PC 0x0c058dca */
if(!s->budget--) { s->failed_pc=0x0c058dcau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c058dcc;
P_0c058dcc: /* original d117, guest PC 0x0c058dcc */
if(!s->budget--) { s->failed_pc=0x0c058dccu; return 0; }
r[1]=read(ram,0x0c058e2cu,4);
goto P_0c058dce;
P_0c058dce: /* original 8902, guest PC 0x0c058dce */
if(!s->budget--) { s->failed_pc=0x0c058dceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058dd6; }
goto P_0c058dd0;
P_0c058dd0: /* original 410b, guest PC 0x0c058dd0 */
if(!s->budget--) { s->failed_pc=0x0c058dd0u; return 0; }
target=r[1];
r[16]=0x0c058dd4u;
r[4]=read(ram,r[14]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058dd4u) { target=s->pc; goto dispatch; }
goto P_0c058dd4;
P_0c058dd2: /* original 54e5, guest PC 0x0c058dd2 */
if(!s->budget--) { s->failed_pc=0x0c058dd2u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c058dd4;
P_0c058dd4: /* original 60d3, guest PC 0x0c058dd4 */
if(!s->budget--) { s->failed_pc=0x0c058dd4u; return 0; }
r[0]=r[13];
goto P_0c058dd6;
P_0c058dd6: /* original c804, guest PC 0x0c058dd6 */
if(!s->budget--) { s->failed_pc=0x0c058dd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c058dd8;
P_0c058dd8: /* original d315, guest PC 0x0c058dd8 */
if(!s->budget--) { s->failed_pc=0x0c058dd8u; return 0; }
r[3]=read(ram,0x0c058e30u,4);
goto P_0c058dda;
P_0c058dda: /* original 8902, guest PC 0x0c058dda */
if(!s->budget--) { s->failed_pc=0x0c058ddau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058de2; }
goto P_0c058ddc;
P_0c058ddc: /* original 64e3, guest PC 0x0c058ddc */
if(!s->budget--) { s->failed_pc=0x0c058ddcu; return 0; }
r[4]=r[14];
goto P_0c058dde;
P_0c058dde: /* original 430b, guest PC 0x0c058dde */
if(!s->budget--) { s->failed_pc=0x0c058ddeu; return 0; }
target=r[3];
r[16]=0x0c058de2u;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058de2u) { target=s->pc; goto dispatch; }
goto P_0c058de2;
P_0c058de0: /* original 7420, guest PC 0x0c058de0 */
if(!s->budget--) { s->failed_pc=0x0c058de0u; return 0; }
r[4]+=0x00000020u;
goto P_0c058de2;
P_0c058de2: /* original 54e1, guest PC 0x0c058de2 */
if(!s->budget--) { s->failed_pc=0x0c058de2u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c058de4;
P_0c058de4: /* original 2448, guest PC 0x0c058de4 */
if(!s->budget--) { s->failed_pc=0x0c058de4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c058de6;
P_0c058de6: /* original 2fe6, guest PC 0x0c058de6 */
if(!s->budget--) { s->failed_pc=0x0c058de6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c058de8;
P_0c058de8: /* original 8903, guest PC 0x0c058de8 */
if(!s->budget--) { s->failed_pc=0x0c058de8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058df2; }
goto P_0c058dea;
P_0c058dea: /* original bee9, guest PC 0x0c058dea */
if(!s->budget--) { s->failed_pc=0x0c058deau; return 0; }
target=0x0c058bc0u; r[16]=0x0c058deeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058deeu) { target=s->pc; goto dispatch; }
goto P_0c058dee;
P_0c058dec: /* original 0009, guest PC 0x0c058dec */
if(!s->budget--) { s->failed_pc=0x0c058decu; return 0; }
goto P_0c058dee;
P_0c058dee: /* original 5ef0, guest PC 0x0c058dee */
if(!s->budget--) { s->failed_pc=0x0c058deeu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c058df0;
P_0c058df0: /* original 5df1, guest PC 0x0c058df0 */
if(!s->budget--) { s->failed_pc=0x0c058df0u; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c058df2;
P_0c058df2: /* original 54eb, guest PC 0x0c058df2 */
if(!s->budget--) { s->failed_pc=0x0c058df2u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c058df4;
P_0c058df4: /* original 2448, guest PC 0x0c058df4 */
if(!s->budget--) { s->failed_pc=0x0c058df4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c058df6;
P_0c058df6: /* original 8903, guest PC 0x0c058df6 */
if(!s->budget--) { s->failed_pc=0x0c058df6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058e00; }
goto P_0c058df8;
P_0c058df8: /* original bfc4, guest PC 0x0c058df8 */
if(!s->budget--) { s->failed_pc=0x0c058df8u; return 0; }
target=0x0c058d84u; r[16]=0x0c058dfcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058dfcu) { target=s->pc; goto dispatch; }
goto P_0c058dfc;
P_0c058dfa: /* original 0009, guest PC 0x0c058dfa */
if(!s->budget--) { s->failed_pc=0x0c058dfau; return 0; }
goto P_0c058dfc;
P_0c058dfc: /* original 5df1, guest PC 0x0c058dfc */
if(!s->budget--) { s->failed_pc=0x0c058dfcu; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c058dfe;
P_0c058dfe: /* original 5ef0, guest PC 0x0c058dfe */
if(!s->budget--) { s->failed_pc=0x0c058dfeu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c058e00;
P_0c058e00: /* original 60d3, guest PC 0x0c058e00 */
if(!s->budget--) { s->failed_pc=0x0c058e00u; return 0; }
r[0]=r[13];
goto P_0c058e02;
P_0c058e02: /* original c83e, guest PC 0x0c058e02 */
if(!s->budget--) { s->failed_pc=0x0c058e02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c058e04;
P_0c058e04: /* original d10b, guest PC 0x0c058e04 */
if(!s->budget--) { s->failed_pc=0x0c058e04u; return 0; }
r[1]=read(ram,0x0c058e34u,4);
goto P_0c058e06;
P_0c058e06: /* original 7f08, guest PC 0x0c058e06 */
if(!s->budget--) { s->failed_pc=0x0c058e06u; return 0; }
r[15]+=0x00000008u;
goto P_0c058e08;
P_0c058e08: /* original 8901, guest PC 0x0c058e08 */
if(!s->budget--) { s->failed_pc=0x0c058e08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058e0e; }
goto P_0c058e0a;
P_0c058e0a: /* original 410b, guest PC 0x0c058e0a */
if(!s->budget--) { s->failed_pc=0x0c058e0au; return 0; }
target=r[1];
r[16]=0x0c058e0eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058e0eu) { target=s->pc; goto dispatch; }
goto P_0c058e0e;
P_0c058e0c: /* original e401, guest PC 0x0c058e0c */
if(!s->budget--) { s->failed_pc=0x0c058e0cu; return 0; }
r[4]=0x00000001u;
goto P_0c058e0e;
P_0c058e0e: /* original 54ec, guest PC 0x0c058e0e */
if(!s->budget--) { s->failed_pc=0x0c058e0eu; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c058e10;
P_0c058e10: /* original 4f26, guest PC 0x0c058e10 */
if(!s->budget--) { s->failed_pc=0x0c058e10u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058e12;
P_0c058e12: /* original 2448, guest PC 0x0c058e12 */
if(!s->budget--) { s->failed_pc=0x0c058e12u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c058e14;
P_0c058e14: /* original 8bb6, guest PC 0x0c058e14 */
if(!s->budget--) { s->failed_pc=0x0c058e14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058d84; }
goto P_0c058e16;
P_0c058e16: /* original 000b, guest PC 0x0c058e16 */
if(!s->budget--) { s->failed_pc=0x0c058e16u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c058e18: /* original 0009, guest PC 0x0c058e18 */
if(!s->budget--) { s->failed_pc=0x0c058e18u; return 0; }
return vf3_matrix_family(0x0c058e1au,s,ram);
P_0c060d28: /* original 4f22, guest PC 0x0c060d28 */
if(!s->budget--) { s->failed_pc=0x0c060d28u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060d2a;
P_0c060d2a: /* original 3d5c, guest PC 0x0c060d2a */
if(!s->budget--) { s->failed_pc=0x0c060d2au; return 0; }
r[13]+=r[5];
goto P_0c060d2c;
P_0c060d2c: /* original dc3f, guest PC 0x0c060d2c */
if(!s->budget--) { s->failed_pc=0x0c060d2cu; return 0; }
r[12]=read(ram,0x0c060e2cu,4);
goto P_0c060d2e;
P_0c060d2e: /* original 3ed6, guest PC 0x0c060d2e */
if(!s->budget--) { s->failed_pc=0x0c060d2eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[13])!=0);
goto P_0c060d30;
P_0c060d30: /* original 8904, guest PC 0x0c060d30 */
if(!s->budget--) { s->failed_pc=0x0c060d30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060d3c; }
goto P_0c060d32;
P_0c060d32: /* original 4c0b, guest PC 0x0c060d32 */
if(!s->budget--) { s->failed_pc=0x0c060d32u; return 0; }
target=r[12];
r[16]=0x0c060d36u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c060d36u) { target=s->pc; goto dispatch; }
goto P_0c060d36;
P_0c060d34: /* original 64e3, guest PC 0x0c060d34 */
if(!s->budget--) { s->failed_pc=0x0c060d34u; return 0; }
r[4]=r[14];
goto P_0c060d36;
P_0c060d36: /* original 7e20, guest PC 0x0c060d36 */
if(!s->budget--) { s->failed_pc=0x0c060d36u; return 0; }
r[14]+=0x00000020u;
goto P_0c060d38;
P_0c060d38: /* original 3ed6, guest PC 0x0c060d38 */
if(!s->budget--) { s->failed_pc=0x0c060d38u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[13])!=0);
goto P_0c060d3a;
P_0c060d3a: /* original 8bfa, guest PC 0x0c060d3a */
if(!s->budget--) { s->failed_pc=0x0c060d3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060d32; }
goto P_0c060d3c;
P_0c060d3c: /* original 4f26, guest PC 0x0c060d3c */
if(!s->budget--) { s->failed_pc=0x0c060d3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060d3e;
P_0c060d3e: /* original 6cf6, guest PC 0x0c060d3e */
if(!s->budget--) { s->failed_pc=0x0c060d3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060d40;
P_0c060d40: /* original 6df6, guest PC 0x0c060d40 */
if(!s->budget--) { s->failed_pc=0x0c060d40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060d42;
P_0c060d42: /* original 000b, guest PC 0x0c060d42 */
if(!s->budget--) { s->failed_pc=0x0c060d42u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060d44: /* original 6ef6, guest PC 0x0c060d44 */
if(!s->budget--) { s->failed_pc=0x0c060d44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c060d46u,s,ram);
P_0c062e8e: /* original 04b3, guest PC 0x0c062e8e */
if(!s->budget--) { s->failed_pc=0x0c062e8eu; return 0; }
goto P_0c062e90;
P_0c062e90: /* original 000b, guest PC 0x0c062e90 */
if(!s->budget--) { s->failed_pc=0x0c062e90u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e92: /* original 0009, guest PC 0x0c062e92 */
if(!s->budget--) { s->failed_pc=0x0c062e92u; return 0; }
return vf3_matrix_family(0x0c062e94u,s,ram);
P_0c0804f6: /* original 4f22, guest PC 0x0c0804f6 */
if(!s->budget--) { s->failed_pc=0x0c0804f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0804f8;
P_0c0804f8: /* original 948b, guest PC 0x0c0804f8 */
if(!s->budget--) { s->failed_pc=0x0c0804f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080612u,2);
goto P_0c0804fa;
P_0c0804fa: /* original d34f, guest PC 0x0c0804fa */
if(!s->budget--) { s->failed_pc=0x0c0804fau; return 0; }
r[3]=read(ram,0x0c080638u,4);
goto P_0c0804fc;
P_0c0804fc: /* original de4c, guest PC 0x0c0804fc */
if(!s->budget--) { s->failed_pc=0x0c0804fcu; return 0; }
r[14]=read(ram,0x0c080630u,4);
goto P_0c0804fe;
P_0c0804fe: /* original d64d, guest PC 0x0c0804fe */
if(!s->budget--) { s->failed_pc=0x0c0804feu; return 0; }
r[6]=read(ram,0x0c080634u,4);
goto P_0c080500;
P_0c080500: /* original 430b, guest PC 0x0c080500 */
if(!s->budget--) { s->failed_pc=0x0c080500u; return 0; }
target=r[3];
r[16]=0x0c080504u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080504u) { target=s->pc; goto dispatch; }
goto P_0c080504;
P_0c080502: /* original 65e3, guest PC 0x0c080502 */
if(!s->budget--) { s->failed_pc=0x0c080502u; return 0; }
r[5]=r[14];
goto P_0c080504;
P_0c080504: /* original 4f26, guest PC 0x0c080504 */
if(!s->budget--) { s->failed_pc=0x0c080504u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080506;
P_0c080506: /* original d24d, guest PC 0x0c080506 */
if(!s->budget--) { s->failed_pc=0x0c080506u; return 0; }
r[2]=read(ram,0x0c08063cu,4);
goto P_0c080508;
P_0c080508: /* original 64e3, guest PC 0x0c080508 */
if(!s->budget--) { s->failed_pc=0x0c080508u; return 0; }
r[4]=r[14];
goto P_0c08050a;
P_0c08050a: /* original 422b, guest PC 0x0c08050a */
if(!s->budget--) { s->failed_pc=0x0c08050au; return 0; }
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
P_0c08050c: /* original 6ef6, guest PC 0x0c08050c */
if(!s->budget--) { s->failed_pc=0x0c08050cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08050eu,s,ram);
P_0c081d38: /* original 4f22, guest PC 0x0c081d38 */
if(!s->budget--) { s->failed_pc=0x0c081d38u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081d3a;
P_0c081d3a: /* original db4a, guest PC 0x0c081d3a */
if(!s->budget--) { s->failed_pc=0x0c081d3au; return 0; }
r[11]=read(ram,0x0c081e64u,4);
goto P_0c081d3c;
P_0c081d3c: /* original 4c00, guest PC 0x0c081d3c */
if(!s->budget--) { s->failed_pc=0x0c081d3cu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c081d3e;
P_0c081d3e: /* original de48, guest PC 0x0c081d3e */
if(!s->budget--) { s->failed_pc=0x0c081d3eu; return 0; }
r[14]=read(ram,0x0c081e60u,4);
goto P_0c081d40;
P_0c081d40: /* original 2dd8, guest PC 0x0c081d40 */
if(!s->budget--) { s->failed_pc=0x0c081d40u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c081d42;
P_0c081d42: /* original 2c5b, guest PC 0x0c081d42 */
if(!s->budget--) { s->failed_pc=0x0c081d42u; return 0; }
r[12]|=r[5];
goto P_0c081d44;
P_0c081d44: /* original 8f07, guest PC 0x0c081d44 */
if(!s->budget--) { s->failed_pc=0x0c081d44u; return 0; }
cond=r[17]&1u;
r[10]=0x00000010u;
if(!cond) { goto P_0c081d56; }
goto P_0c081d48;
P_0c081d46: /* original ea10, guest PC 0x0c081d46 */
if(!s->budget--) { s->failed_pc=0x0c081d46u; return 0; }
r[10]=0x00000010u;
goto P_0c081d48;
P_0c081d48: /* original 66e3, guest PC 0x0c081d48 */
if(!s->budget--) { s->failed_pc=0x0c081d48u; return 0; }
r[6]=r[14];
goto P_0c081d4a;
P_0c081d4a: /* original 2fa6, guest PC 0x0c081d4a */
if(!s->budget--) { s->failed_pc=0x0c081d4au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d4c;
P_0c081d4c: /* original 9578, guest PC 0x0c081d4c */
if(!s->budget--) { s->failed_pc=0x0c081d4cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e40u,2);
goto P_0c081d4e;
P_0c081d4e: /* original e700, guest PC 0x0c081d4e */
if(!s->budget--) { s->failed_pc=0x0c081d4eu; return 0; }
r[7]=0x00000000u;
goto P_0c081d50;
P_0c081d50: /* original 4b0b, guest PC 0x0c081d50 */
if(!s->budget--) { s->failed_pc=0x0c081d50u; return 0; }
target=r[11];
r[16]=0x0c081d54u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d54u) { target=s->pc; goto dispatch; }
goto P_0c081d54;
P_0c081d52: /* original 64c3, guest PC 0x0c081d52 */
if(!s->budget--) { s->failed_pc=0x0c081d52u; return 0; }
r[4]=r[12];
goto P_0c081d54;
P_0c081d54: /* original 7f04, guest PC 0x0c081d54 */
if(!s->budget--) { s->failed_pc=0x0c081d54u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d56;
P_0c081d56: /* original 60d3, guest PC 0x0c081d56 */
if(!s->budget--) { s->failed_pc=0x0c081d56u; return 0; }
r[0]=r[13];
goto P_0c081d58;
P_0c081d58: /* original 8801, guest PC 0x0c081d58 */
if(!s->budget--) { s->failed_pc=0x0c081d58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c081d5a;
P_0c081d5a: /* original 8b06, guest PC 0x0c081d5a */
if(!s->budget--) { s->failed_pc=0x0c081d5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d6a; }
goto P_0c081d5c;
P_0c081d5c: /* original 66e3, guest PC 0x0c081d5c */
if(!s->budget--) { s->failed_pc=0x0c081d5cu; return 0; }
r[6]=r[14];
goto P_0c081d5e;
P_0c081d5e: /* original 2fa6, guest PC 0x0c081d5e */
if(!s->budget--) { s->failed_pc=0x0c081d5eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d60;
P_0c081d60: /* original 956f, guest PC 0x0c081d60 */
if(!s->budget--) { s->failed_pc=0x0c081d60u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e42u,2);
goto P_0c081d62;
P_0c081d62: /* original e700, guest PC 0x0c081d62 */
if(!s->budget--) { s->failed_pc=0x0c081d62u; return 0; }
r[7]=0x00000000u;
goto P_0c081d64;
P_0c081d64: /* original 4b0b, guest PC 0x0c081d64 */
if(!s->budget--) { s->failed_pc=0x0c081d64u; return 0; }
target=r[11];
r[16]=0x0c081d68u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d68u) { target=s->pc; goto dispatch; }
goto P_0c081d68;
P_0c081d66: /* original 64c3, guest PC 0x0c081d66 */
if(!s->budget--) { s->failed_pc=0x0c081d66u; return 0; }
r[4]=r[12];
goto P_0c081d68;
P_0c081d68: /* original 7f04, guest PC 0x0c081d68 */
if(!s->budget--) { s->failed_pc=0x0c081d68u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d6a;
P_0c081d6a: /* original 60d3, guest PC 0x0c081d6a */
if(!s->budget--) { s->failed_pc=0x0c081d6au; return 0; }
r[0]=r[13];
goto P_0c081d6c;
P_0c081d6c: /* original 8802, guest PC 0x0c081d6c */
if(!s->budget--) { s->failed_pc=0x0c081d6cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c081d6e;
P_0c081d6e: /* original 8b06, guest PC 0x0c081d6e */
if(!s->budget--) { s->failed_pc=0x0c081d6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d7e; }
goto P_0c081d70;
P_0c081d70: /* original 66e3, guest PC 0x0c081d70 */
if(!s->budget--) { s->failed_pc=0x0c081d70u; return 0; }
r[6]=r[14];
goto P_0c081d72;
P_0c081d72: /* original 2fa6, guest PC 0x0c081d72 */
if(!s->budget--) { s->failed_pc=0x0c081d72u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d74;
P_0c081d74: /* original 9566, guest PC 0x0c081d74 */
if(!s->budget--) { s->failed_pc=0x0c081d74u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e44u,2);
goto P_0c081d76;
P_0c081d76: /* original e700, guest PC 0x0c081d76 */
if(!s->budget--) { s->failed_pc=0x0c081d76u; return 0; }
r[7]=0x00000000u;
goto P_0c081d78;
P_0c081d78: /* original 4b0b, guest PC 0x0c081d78 */
if(!s->budget--) { s->failed_pc=0x0c081d78u; return 0; }
target=r[11];
r[16]=0x0c081d7cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d7cu) { target=s->pc; goto dispatch; }
goto P_0c081d7c;
P_0c081d7a: /* original 64c3, guest PC 0x0c081d7a */
if(!s->budget--) { s->failed_pc=0x0c081d7au; return 0; }
r[4]=r[12];
goto P_0c081d7c;
P_0c081d7c: /* original 7f04, guest PC 0x0c081d7c */
if(!s->budget--) { s->failed_pc=0x0c081d7cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081d7e;
P_0c081d7e: /* original 60d3, guest PC 0x0c081d7e */
if(!s->budget--) { s->failed_pc=0x0c081d7eu; return 0; }
r[0]=r[13];
goto P_0c081d80;
P_0c081d80: /* original 8804, guest PC 0x0c081d80 */
if(!s->budget--) { s->failed_pc=0x0c081d80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c081d82;
P_0c081d82: /* original 8b06, guest PC 0x0c081d82 */
if(!s->budget--) { s->failed_pc=0x0c081d82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081d92; }
goto P_0c081d84;
P_0c081d84: /* original 66e3, guest PC 0x0c081d84 */
if(!s->budget--) { s->failed_pc=0x0c081d84u; return 0; }
r[6]=r[14];
goto P_0c081d86;
P_0c081d86: /* original 2fa6, guest PC 0x0c081d86 */
if(!s->budget--) { s->failed_pc=0x0c081d86u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d88;
P_0c081d88: /* original 955d, guest PC 0x0c081d88 */
if(!s->budget--) { s->failed_pc=0x0c081d88u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e46u,2);
goto P_0c081d8a;
P_0c081d8a: /* original e700, guest PC 0x0c081d8a */
if(!s->budget--) { s->failed_pc=0x0c081d8au; return 0; }
r[7]=0x00000000u;
goto P_0c081d8c;
P_0c081d8c: /* original 4b0b, guest PC 0x0c081d8c */
if(!s->budget--) { s->failed_pc=0x0c081d8cu; return 0; }
target=r[11];
r[16]=0x0c081d90u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d90u) { target=s->pc; goto dispatch; }
goto P_0c081d90;
P_0c081d8e: /* original 64c3, guest PC 0x0c081d8e */
if(!s->budget--) { s->failed_pc=0x0c081d8eu; return 0; }
r[4]=r[12];
goto P_0c081d90;
P_0c081d90: /* original 7f04, guest PC 0x0c081d90 */
if(!s->budget--) { s->failed_pc=0x0c081d90u; return 0; }
r[15]+=0x00000004u;
goto P_0c081d92;
P_0c081d92: /* original 60d3, guest PC 0x0c081d92 */
if(!s->budget--) { s->failed_pc=0x0c081d92u; return 0; }
r[0]=r[13];
goto P_0c081d94;
P_0c081d94: /* original 8808, guest PC 0x0c081d94 */
if(!s->budget--) { s->failed_pc=0x0c081d94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c081d96;
P_0c081d96: /* original 8b06, guest PC 0x0c081d96 */
if(!s->budget--) { s->failed_pc=0x0c081d96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081da6; }
goto P_0c081d98;
P_0c081d98: /* original 66e3, guest PC 0x0c081d98 */
if(!s->budget--) { s->failed_pc=0x0c081d98u; return 0; }
r[6]=r[14];
goto P_0c081d9a;
P_0c081d9a: /* original 2fa6, guest PC 0x0c081d9a */
if(!s->budget--) { s->failed_pc=0x0c081d9au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081d9c;
P_0c081d9c: /* original 9554, guest PC 0x0c081d9c */
if(!s->budget--) { s->failed_pc=0x0c081d9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e48u,2);
goto P_0c081d9e;
P_0c081d9e: /* original e700, guest PC 0x0c081d9e */
if(!s->budget--) { s->failed_pc=0x0c081d9eu; return 0; }
r[7]=0x00000000u;
goto P_0c081da0;
P_0c081da0: /* original 4b0b, guest PC 0x0c081da0 */
if(!s->budget--) { s->failed_pc=0x0c081da0u; return 0; }
target=r[11];
r[16]=0x0c081da4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081da4u) { target=s->pc; goto dispatch; }
goto P_0c081da4;
P_0c081da2: /* original 64c3, guest PC 0x0c081da2 */
if(!s->budget--) { s->failed_pc=0x0c081da2u; return 0; }
r[4]=r[12];
goto P_0c081da4;
P_0c081da4: /* original 7f04, guest PC 0x0c081da4 */
if(!s->budget--) { s->failed_pc=0x0c081da4u; return 0; }
r[15]+=0x00000004u;
goto P_0c081da6;
P_0c081da6: /* original 60d3, guest PC 0x0c081da6 */
if(!s->budget--) { s->failed_pc=0x0c081da6u; return 0; }
r[0]=r[13];
goto P_0c081da8;
P_0c081da8: /* original 8810, guest PC 0x0c081da8 */
if(!s->budget--) { s->failed_pc=0x0c081da8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c081daa;
P_0c081daa: /* original 8b06, guest PC 0x0c081daa */
if(!s->budget--) { s->failed_pc=0x0c081daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081dba; }
goto P_0c081dac;
P_0c081dac: /* original 66e3, guest PC 0x0c081dac */
if(!s->budget--) { s->failed_pc=0x0c081dacu; return 0; }
r[6]=r[14];
goto P_0c081dae;
P_0c081dae: /* original 2fa6, guest PC 0x0c081dae */
if(!s->budget--) { s->failed_pc=0x0c081daeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081db0;
P_0c081db0: /* original 954b, guest PC 0x0c081db0 */
if(!s->budget--) { s->failed_pc=0x0c081db0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4au,2);
goto P_0c081db2;
P_0c081db2: /* original e700, guest PC 0x0c081db2 */
if(!s->budget--) { s->failed_pc=0x0c081db2u; return 0; }
r[7]=0x00000000u;
goto P_0c081db4;
P_0c081db4: /* original 4b0b, guest PC 0x0c081db4 */
if(!s->budget--) { s->failed_pc=0x0c081db4u; return 0; }
target=r[11];
r[16]=0x0c081db8u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081db8u) { target=s->pc; goto dispatch; }
goto P_0c081db8;
P_0c081db6: /* original 64c3, guest PC 0x0c081db6 */
if(!s->budget--) { s->failed_pc=0x0c081db6u; return 0; }
r[4]=r[12];
goto P_0c081db8;
P_0c081db8: /* original 7f04, guest PC 0x0c081db8 */
if(!s->budget--) { s->failed_pc=0x0c081db8u; return 0; }
r[15]+=0x00000004u;
goto P_0c081dba;
P_0c081dba: /* original 60d3, guest PC 0x0c081dba */
if(!s->budget--) { s->failed_pc=0x0c081dbau; return 0; }
r[0]=r[13];
goto P_0c081dbc;
P_0c081dbc: /* original 8820, guest PC 0x0c081dbc */
if(!s->budget--) { s->failed_pc=0x0c081dbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c081dbe;
P_0c081dbe: /* original 8b06, guest PC 0x0c081dbe */
if(!s->budget--) { s->failed_pc=0x0c081dbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081dce; }
goto P_0c081dc0;
P_0c081dc0: /* original 66e3, guest PC 0x0c081dc0 */
if(!s->budget--) { s->failed_pc=0x0c081dc0u; return 0; }
r[6]=r[14];
goto P_0c081dc2;
P_0c081dc2: /* original 2fa6, guest PC 0x0c081dc2 */
if(!s->budget--) { s->failed_pc=0x0c081dc2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dc4;
P_0c081dc4: /* original 9542, guest PC 0x0c081dc4 */
if(!s->budget--) { s->failed_pc=0x0c081dc4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4cu,2);
goto P_0c081dc6;
P_0c081dc6: /* original e700, guest PC 0x0c081dc6 */
if(!s->budget--) { s->failed_pc=0x0c081dc6u; return 0; }
r[7]=0x00000000u;
goto P_0c081dc8;
P_0c081dc8: /* original 4b0b, guest PC 0x0c081dc8 */
if(!s->budget--) { s->failed_pc=0x0c081dc8u; return 0; }
target=r[11];
r[16]=0x0c081dccu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081dccu) { target=s->pc; goto dispatch; }
goto P_0c081dcc;
P_0c081dca: /* original 64c3, guest PC 0x0c081dca */
if(!s->budget--) { s->failed_pc=0x0c081dcau; return 0; }
r[4]=r[12];
goto P_0c081dcc;
P_0c081dcc: /* original 7f04, guest PC 0x0c081dcc */
if(!s->budget--) { s->failed_pc=0x0c081dccu; return 0; }
r[15]+=0x00000004u;
goto P_0c081dce;
P_0c081dce: /* original 60d3, guest PC 0x0c081dce */
if(!s->budget--) { s->failed_pc=0x0c081dceu; return 0; }
r[0]=r[13];
goto P_0c081dd0;
P_0c081dd0: /* original 8840, guest PC 0x0c081dd0 */
if(!s->budget--) { s->failed_pc=0x0c081dd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c081dd2;
P_0c081dd2: /* original 8b06, guest PC 0x0c081dd2 */
if(!s->budget--) { s->failed_pc=0x0c081dd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081de2; }
goto P_0c081dd4;
P_0c081dd4: /* original 66e3, guest PC 0x0c081dd4 */
if(!s->budget--) { s->failed_pc=0x0c081dd4u; return 0; }
r[6]=r[14];
goto P_0c081dd6;
P_0c081dd6: /* original 2fa6, guest PC 0x0c081dd6 */
if(!s->budget--) { s->failed_pc=0x0c081dd6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dd8;
P_0c081dd8: /* original 9539, guest PC 0x0c081dd8 */
if(!s->budget--) { s->failed_pc=0x0c081dd8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e4eu,2);
goto P_0c081dda;
P_0c081dda: /* original e700, guest PC 0x0c081dda */
if(!s->budget--) { s->failed_pc=0x0c081ddau; return 0; }
r[7]=0x00000000u;
goto P_0c081ddc;
P_0c081ddc: /* original 4b0b, guest PC 0x0c081ddc */
if(!s->budget--) { s->failed_pc=0x0c081ddcu; return 0; }
target=r[11];
r[16]=0x0c081de0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081de0u) { target=s->pc; goto dispatch; }
goto P_0c081de0;
P_0c081dde: /* original 64c3, guest PC 0x0c081dde */
if(!s->budget--) { s->failed_pc=0x0c081ddeu; return 0; }
r[4]=r[12];
goto P_0c081de0;
P_0c081de0: /* original 7f04, guest PC 0x0c081de0 */
if(!s->budget--) { s->failed_pc=0x0c081de0u; return 0; }
r[15]+=0x00000004u;
goto P_0c081de2;
P_0c081de2: /* original 9235, guest PC 0x0c081de2 */
if(!s->budget--) { s->failed_pc=0x0c081de2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e50u,2);
goto P_0c081de4;
P_0c081de4: /* original 3d20, guest PC 0x0c081de4 */
if(!s->budget--) { s->failed_pc=0x0c081de4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081de6;
P_0c081de6: /* original 8b06, guest PC 0x0c081de6 */
if(!s->budget--) { s->failed_pc=0x0c081de6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081df6; }
goto P_0c081de8;
P_0c081de8: /* original 66e3, guest PC 0x0c081de8 */
if(!s->budget--) { s->failed_pc=0x0c081de8u; return 0; }
r[6]=r[14];
goto P_0c081dea;
P_0c081dea: /* original 2fa6, guest PC 0x0c081dea */
if(!s->budget--) { s->failed_pc=0x0c081deau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081dec;
P_0c081dec: /* original 9531, guest PC 0x0c081dec */
if(!s->budget--) { s->failed_pc=0x0c081decu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e52u,2);
goto P_0c081dee;
P_0c081dee: /* original e700, guest PC 0x0c081dee */
if(!s->budget--) { s->failed_pc=0x0c081deeu; return 0; }
r[7]=0x00000000u;
goto P_0c081df0;
P_0c081df0: /* original 4b0b, guest PC 0x0c081df0 */
if(!s->budget--) { s->failed_pc=0x0c081df0u; return 0; }
target=r[11];
r[16]=0x0c081df4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081df4u) { target=s->pc; goto dispatch; }
goto P_0c081df4;
P_0c081df2: /* original 64c3, guest PC 0x0c081df2 */
if(!s->budget--) { s->failed_pc=0x0c081df2u; return 0; }
r[4]=r[12];
goto P_0c081df4;
P_0c081df4: /* original 7f04, guest PC 0x0c081df4 */
if(!s->budget--) { s->failed_pc=0x0c081df4u; return 0; }
r[15]+=0x00000004u;
goto P_0c081df6;
P_0c081df6: /* original 922d, guest PC 0x0c081df6 */
if(!s->budget--) { s->failed_pc=0x0c081df6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e54u,2);
goto P_0c081df8;
P_0c081df8: /* original 3d20, guest PC 0x0c081df8 */
if(!s->budget--) { s->failed_pc=0x0c081df8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081dfa;
P_0c081dfa: /* original 8b06, guest PC 0x0c081dfa */
if(!s->budget--) { s->failed_pc=0x0c081dfau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e0a; }
goto P_0c081dfc;
P_0c081dfc: /* original 66e3, guest PC 0x0c081dfc */
if(!s->budget--) { s->failed_pc=0x0c081dfcu; return 0; }
r[6]=r[14];
goto P_0c081dfe;
P_0c081dfe: /* original 2fa6, guest PC 0x0c081dfe */
if(!s->budget--) { s->failed_pc=0x0c081dfeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e00;
P_0c081e00: /* original 9529, guest PC 0x0c081e00 */
if(!s->budget--) { s->failed_pc=0x0c081e00u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e56u,2);
goto P_0c081e02;
P_0c081e02: /* original e700, guest PC 0x0c081e02 */
if(!s->budget--) { s->failed_pc=0x0c081e02u; return 0; }
r[7]=0x00000000u;
goto P_0c081e04;
P_0c081e04: /* original 4b0b, guest PC 0x0c081e04 */
if(!s->budget--) { s->failed_pc=0x0c081e04u; return 0; }
target=r[11];
r[16]=0x0c081e08u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081e08u) { target=s->pc; goto dispatch; }
goto P_0c081e08;
P_0c081e06: /* original 64c3, guest PC 0x0c081e06 */
if(!s->budget--) { s->failed_pc=0x0c081e06u; return 0; }
r[4]=r[12];
goto P_0c081e08;
P_0c081e08: /* original 7f04, guest PC 0x0c081e08 */
if(!s->budget--) { s->failed_pc=0x0c081e08u; return 0; }
r[15]+=0x00000004u;
goto P_0c081e0a;
P_0c081e0a: /* original 9225, guest PC 0x0c081e0a */
if(!s->budget--) { s->failed_pc=0x0c081e0au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e58u,2);
goto P_0c081e0c;
P_0c081e0c: /* original 3d20, guest PC 0x0c081e0c */
if(!s->budget--) { s->failed_pc=0x0c081e0cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081e0e;
P_0c081e0e: /* original 8b06, guest PC 0x0c081e0e */
if(!s->budget--) { s->failed_pc=0x0c081e0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e1e; }
goto P_0c081e10;
P_0c081e10: /* original 66e3, guest PC 0x0c081e10 */
if(!s->budget--) { s->failed_pc=0x0c081e10u; return 0; }
r[6]=r[14];
goto P_0c081e12;
P_0c081e12: /* original 2fa6, guest PC 0x0c081e12 */
if(!s->budget--) { s->failed_pc=0x0c081e12u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e14;
P_0c081e14: /* original 9521, guest PC 0x0c081e14 */
if(!s->budget--) { s->failed_pc=0x0c081e14u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5au,2);
goto P_0c081e16;
P_0c081e16: /* original e700, guest PC 0x0c081e16 */
if(!s->budget--) { s->failed_pc=0x0c081e16u; return 0; }
r[7]=0x00000000u;
goto P_0c081e18;
P_0c081e18: /* original 4b0b, guest PC 0x0c081e18 */
if(!s->budget--) { s->failed_pc=0x0c081e18u; return 0; }
target=r[11];
r[16]=0x0c081e1cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081e1cu) { target=s->pc; goto dispatch; }
goto P_0c081e1c;
P_0c081e1a: /* original 64c3, guest PC 0x0c081e1a */
if(!s->budget--) { s->failed_pc=0x0c081e1au; return 0; }
r[4]=r[12];
goto P_0c081e1c;
P_0c081e1c: /* original 7f04, guest PC 0x0c081e1c */
if(!s->budget--) { s->failed_pc=0x0c081e1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c081e1e;
P_0c081e1e: /* original 921d, guest PC 0x0c081e1e */
if(!s->budget--) { s->failed_pc=0x0c081e1eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5cu,2);
goto P_0c081e20;
P_0c081e20: /* original 3d20, guest PC 0x0c081e20 */
if(!s->budget--) { s->failed_pc=0x0c081e20u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c081e22;
P_0c081e22: /* original 8b06, guest PC 0x0c081e22 */
if(!s->budget--) { s->failed_pc=0x0c081e22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081e32; }
goto P_0c081e24;
P_0c081e24: /* original 66e3, guest PC 0x0c081e24 */
if(!s->budget--) { s->failed_pc=0x0c081e24u; return 0; }
r[6]=r[14];
goto P_0c081e26;
P_0c081e26: /* original 2fa6, guest PC 0x0c081e26 */
if(!s->budget--) { s->failed_pc=0x0c081e26u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081e28;
P_0c081e28: /* original 9519, guest PC 0x0c081e28 */
if(!s->budget--) { s->failed_pc=0x0c081e28u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081e5eu,2);
goto P_0c081e2a;
P_0c081e2a: /* original e700, guest PC 0x0c081e2a */
if(!s->budget--) { s->failed_pc=0x0c081e2au; return 0; }
r[7]=0x00000000u;
goto P_0c081e2c;
P_0c081e2c: /* original 4b0b, guest PC 0x0c081e2c */
if(!s->budget--) { s->failed_pc=0x0c081e2cu; return 0; }
target=r[11];
r[16]=0x0c081e30u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081e30u) { target=s->pc; goto dispatch; }
goto P_0c081e30;
P_0c081e2e: /* original 64c3, guest PC 0x0c081e2e */
if(!s->budget--) { s->failed_pc=0x0c081e2eu; return 0; }
r[4]=r[12];
goto P_0c081e30;
P_0c081e30: /* original 7f04, guest PC 0x0c081e30 */
if(!s->budget--) { s->failed_pc=0x0c081e30u; return 0; }
r[15]+=0x00000004u;
goto P_0c081e32;
P_0c081e32: /* original 4f26, guest PC 0x0c081e32 */
if(!s->budget--) { s->failed_pc=0x0c081e32u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081e34;
P_0c081e34: /* original 6af6, guest PC 0x0c081e34 */
if(!s->budget--) { s->failed_pc=0x0c081e34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081e36;
P_0c081e36: /* original 6bf6, guest PC 0x0c081e36 */
if(!s->budget--) { s->failed_pc=0x0c081e36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081e38;
P_0c081e38: /* original 6cf6, guest PC 0x0c081e38 */
if(!s->budget--) { s->failed_pc=0x0c081e38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081e3a;
P_0c081e3a: /* original 6df6, guest PC 0x0c081e3a */
if(!s->budget--) { s->failed_pc=0x0c081e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081e3c;
P_0c081e3c: /* original 000b, guest PC 0x0c081e3c */
if(!s->budget--) { s->failed_pc=0x0c081e3cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081e3e: /* original 6ef6, guest PC 0x0c081e3e */
if(!s->budget--) { s->failed_pc=0x0c081e3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c081e40u,s,ram);
P_0c083d70: /* original 4f22, guest PC 0x0c083d70 */
if(!s->budget--) { s->failed_pc=0x0c083d70u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083d72;
P_0c083d72: /* original dc1b, guest PC 0x0c083d72 */
if(!s->budget--) { s->failed_pc=0x0c083d72u; return 0; }
r[12]=read(ram,0x0c083de0u,4);
goto P_0c083d74;
P_0c083d74: /* original db17, guest PC 0x0c083d74 */
if(!s->budget--) { s->failed_pc=0x0c083d74u; return 0; }
r[11]=read(ram,0x0c083dd4u,4);
goto P_0c083d76;
P_0c083d76: /* original a00e, guest PC 0x0c083d76 */
if(!s->budget--) { s->failed_pc=0x0c083d76u; return 0; }
r[13]=0x00000000u;
goto P_0c083d96;
P_0c083d78: /* original ed00, guest PC 0x0c083d78 */
if(!s->budget--) { s->failed_pc=0x0c083d78u; return 0; }
r[13]=0x00000000u;
goto P_0c083d7a;
P_0c083d7a: /* original 85e1, guest PC 0x0c083d7a */
if(!s->budget--) { s->failed_pc=0x0c083d7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c083d7c;
P_0c083d7c: /* original e307, guest PC 0x0c083d7c */
if(!s->budget--) { s->failed_pc=0x0c083d7cu; return 0; }
r[3]=0x00000007u;
goto P_0c083d7e;
P_0c083d7e: /* original 64e1, guest PC 0x0c083d7e */
if(!s->budget--) { s->failed_pc=0x0c083d7eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c083d80;
P_0c083d80: /* original 66c3, guest PC 0x0c083d80 */
if(!s->budget--) { s->failed_pc=0x0c083d80u; return 0; }
r[6]=r[12];
goto P_0c083d82;
P_0c083d82: /* original 403c, guest PC 0x0c083d82 */
if(!s->budget--) { s->failed_pc=0x0c083d82u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c083d84;
P_0c083d84: /* original 2fd6, guest PC 0x0c083d84 */
if(!s->budget--) { s->failed_pc=0x0c083d84u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083d86;
P_0c083d86: /* original 4400, guest PC 0x0c083d86 */
if(!s->budget--) { s->failed_pc=0x0c083d86u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c083d88;
P_0c083d88: /* original 240b, guest PC 0x0c083d88 */
if(!s->budget--) { s->failed_pc=0x0c083d88u; return 0; }
r[4]|=r[0];
goto P_0c083d8a;
P_0c083d8a: /* original 85e2, guest PC 0x0c083d8a */
if(!s->budget--) { s->failed_pc=0x0c083d8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+4,2);
goto P_0c083d8c;
P_0c083d8c: /* original e700, guest PC 0x0c083d8c */
if(!s->budget--) { s->failed_pc=0x0c083d8cu; return 0; }
r[7]=0x00000000u;
goto P_0c083d8e;
P_0c083d8e: /* original 4b0b, guest PC 0x0c083d8e */
if(!s->budget--) { s->failed_pc=0x0c083d8eu; return 0; }
target=r[11];
r[16]=0x0c083d92u;
r[5]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c083d92u) { target=s->pc; goto dispatch; }
goto P_0c083d92;
P_0c083d90: /* original 6503, guest PC 0x0c083d90 */
if(!s->budget--) { s->failed_pc=0x0c083d90u; return 0; }
r[5]=r[0];
goto P_0c083d92;
P_0c083d92: /* original 7e06, guest PC 0x0c083d92 */
if(!s->budget--) { s->failed_pc=0x0c083d92u; return 0; }
r[14]+=0x00000006u;
goto P_0c083d94;
P_0c083d94: /* original 7f04, guest PC 0x0c083d94 */
if(!s->budget--) { s->failed_pc=0x0c083d94u; return 0; }
r[15]+=0x00000004u;
goto P_0c083d96;
P_0c083d96: /* original 63e1, guest PC 0x0c083d96 */
if(!s->budget--) { s->failed_pc=0x0c083d96u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c083d98;
P_0c083d98: /* original 4311, guest PC 0x0c083d98 */
if(!s->budget--) { s->failed_pc=0x0c083d98u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c083d9a;
P_0c083d9a: /* original 89ee, guest PC 0x0c083d9a */
if(!s->budget--) { s->failed_pc=0x0c083d9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c083d7a; }
goto P_0c083d9c;
P_0c083d9c: /* original 4f26, guest PC 0x0c083d9c */
if(!s->budget--) { s->failed_pc=0x0c083d9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083d9e;
P_0c083d9e: /* original 6bf6, guest PC 0x0c083d9e */
if(!s->budget--) { s->failed_pc=0x0c083d9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c083da0;
P_0c083da0: /* original 6cf6, guest PC 0x0c083da0 */
if(!s->budget--) { s->failed_pc=0x0c083da0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c083da2;
P_0c083da2: /* original 6df6, guest PC 0x0c083da2 */
if(!s->budget--) { s->failed_pc=0x0c083da2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c083da4;
P_0c083da4: /* original 000b, guest PC 0x0c083da4 */
if(!s->budget--) { s->failed_pc=0x0c083da4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c083da6: /* original 6ef6, guest PC 0x0c083da6 */
if(!s->budget--) { s->failed_pc=0x0c083da6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c083da8u,s,ram);
P_0c08935a: /* original 4f22, guest PC 0x0c08935a */
if(!s->budget--) { s->failed_pc=0x0c08935au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08935c;
P_0c08935c: /* original 7ffc, guest PC 0x0c08935c */
if(!s->budget--) { s->failed_pc=0x0c08935cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08935e;
P_0c08935e: /* original 2f42, guest PC 0x0c08935e */
if(!s->budget--) { s->failed_pc=0x0c08935eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c089360;
P_0c089360: /* original d31b, guest PC 0x0c089360 */
if(!s->budget--) { s->failed_pc=0x0c089360u; return 0; }
r[3]=read(ram,0x0c0893d0u,4);
goto P_0c089362;
P_0c089362: /* original 430b, guest PC 0x0c089362 */
if(!s->budget--) { s->failed_pc=0x0c089362u; return 0; }
target=r[3];
r[16]=0x0c089366u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089366u) { target=s->pc; goto dispatch; }
goto P_0c089366;
P_0c089364: /* original e400, guest PC 0x0c089364 */
if(!s->budget--) { s->failed_pc=0x0c089364u; return 0; }
r[4]=0x00000000u;
goto P_0c089366;
P_0c089366: /* original 6df2, guest PC 0x0c089366 */
if(!s->budget--) { s->failed_pc=0x0c089366u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c089368;
P_0c089368: /* original 6dd2, guest PC 0x0c089368 */
if(!s->budget--) { s->failed_pc=0x0c089368u; return 0; }
tmp=read(ram,r[13],4);
r[13]=tmp;
goto P_0c08936a;
P_0c08936a: /* original 60d3, guest PC 0x0c08936a */
if(!s->budget--) { s->failed_pc=0x0c08936au; return 0; }
r[0]=r[13];
goto P_0c08936c;
P_0c08936c: /* original 88ff, guest PC 0x0c08936c */
if(!s->budget--) { s->failed_pc=0x0c08936cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c08936e;
P_0c08936e: /* original 8919, guest PC 0x0c08936e */
if(!s->budget--) { s->failed_pc=0x0c08936eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0893a4; }
goto P_0c089370;
P_0c089370: /* original dc1a, guest PC 0x0c089370 */
if(!s->budget--) { s->failed_pc=0x0c089370u; return 0; }
r[12]=read(ram,0x0c0893dcu,4);
goto P_0c089372;
P_0c089372: /* original db19, guest PC 0x0c089372 */
if(!s->budget--) { s->failed_pc=0x0c089372u; return 0; }
r[11]=read(ram,0x0c0893d8u,4);
goto P_0c089374;
P_0c089374: /* original da17, guest PC 0x0c089374 */
if(!s->budget--) { s->failed_pc=0x0c089374u; return 0; }
r[10]=read(ram,0x0c0893d4u,4);
goto P_0c089376;
P_0c089376: /* original fc9d, guest PC 0x0c089376 */
if(!s->budget--) { s->failed_pc=0x0c089376u; return 0; }
fr[12]=0x3f800000u;
goto P_0c089378;
P_0c089378: /* original e00c, guest PC 0x0c089378 */
if(!s->budget--) { s->failed_pc=0x0c089378u; return 0; }
r[0]=0x0000000cu;
goto P_0c08937a;
P_0c08937a: /* original 6ed3, guest PC 0x0c08937a */
if(!s->budget--) { s->failed_pc=0x0c08937au; return 0; }
r[14]=r[13];
goto P_0c08937c;
P_0c08937c: /* original fde6, guest PC 0x0c08937c */
if(!s->budget--) { s->failed_pc=0x0c08937cu; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c08937e;
P_0c08937e: /* original e010, guest PC 0x0c08937e */
if(!s->budget--) { s->failed_pc=0x0c08937eu; return 0; }
r[0]=0x00000010u;
goto P_0c089380;
P_0c089380: /* original fee6, guest PC 0x0c089380 */
if(!s->budget--) { s->failed_pc=0x0c089380u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c089382;
P_0c089382: /* original e014, guest PC 0x0c089382 */
if(!s->budget--) { s->failed_pc=0x0c089382u; return 0; }
r[0]=0x00000014u;
goto P_0c089384;
P_0c089384: /* original f3e6, guest PC 0x0c089384 */
if(!s->budget--) { s->failed_pc=0x0c089384u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089386;
P_0c089386: /* original f3c2, guest PC 0x0c089386 */
if(!s->budget--) { s->failed_pc=0x0c089386u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c089388;
P_0c089388: /* original ff3c, guest PC 0x0c089388 */
if(!s->budget--) { s->failed_pc=0x0c089388u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c08938a;
P_0c08938a: /* original 4c0b, guest PC 0x0c08938a */
if(!s->budget--) { s->failed_pc=0x0c08938au; return 0; }
target=r[12];
r[16]=0x0c08938eu;
fr[15]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08938eu) { target=s->pc; goto dispatch; }
goto P_0c08938e;
P_0c08938c: /* original ff4d, guest PC 0x0c08938c */
if(!s->budget--) { s->failed_pc=0x0c08938cu; return 0; }
fr[15]^=0x80000000u;
goto P_0c08938e;
P_0c08938e: /* original f5ec, guest PC 0x0c08938e */
if(!s->budget--) { s->failed_pc=0x0c08938eu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c089390;
P_0c089390: /* original f6fc, guest PC 0x0c089390 */
if(!s->budget--) { s->failed_pc=0x0c089390u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c089392;
P_0c089392: /* original 4b0b, guest PC 0x0c089392 */
if(!s->budget--) { s->failed_pc=0x0c089392u; return 0; }
target=r[11];
r[16]=0x0c089396u;
vf3_matrix_move(s,4,13);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089396u) { target=s->pc; goto dispatch; }
goto P_0c089396;
P_0c089394: /* original f4dc, guest PC 0x0c089394 */
if(!s->budget--) { s->failed_pc=0x0c089394u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c089396;
P_0c089396: /* original 85e5, guest PC 0x0c089396 */
if(!s->budget--) { s->failed_pc=0x0c089396u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c089398;
P_0c089398: /* original 4a0b, guest PC 0x0c089398 */
if(!s->budget--) { s->failed_pc=0x0c089398u; return 0; }
target=r[10];
r[16]=0x0c08939cu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08939cu) { target=s->pc; goto dispatch; }
goto P_0c08939c;
P_0c08939a: /* original 6403, guest PC 0x0c08939a */
if(!s->budget--) { s->failed_pc=0x0c08939au; return 0; }
r[4]=r[0];
goto P_0c08939c;
P_0c08939c: /* original 60e2, guest PC 0x0c08939c */
if(!s->budget--) { s->failed_pc=0x0c08939cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08939e;
P_0c08939e: /* original 88ff, guest PC 0x0c08939e */
if(!s->budget--) { s->failed_pc=0x0c08939eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0893a0;
P_0c0893a0: /* original 8fea, guest PC 0x0c0893a0 */
if(!s->budget--) { s->failed_pc=0x0c0893a0u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(!cond) { goto P_0c089378; }
goto P_0c0893a4;
P_0c0893a2: /* original 6d03, guest PC 0x0c0893a2 */
if(!s->budget--) { s->failed_pc=0x0c0893a2u; return 0; }
r[13]=r[0];
goto P_0c0893a4;
P_0c0893a4: /* original 7f04, guest PC 0x0c0893a4 */
if(!s->budget--) { s->failed_pc=0x0c0893a4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0893a6;
P_0c0893a6: /* original d30e, guest PC 0x0c0893a6 */
if(!s->budget--) { s->failed_pc=0x0c0893a6u; return 0; }
r[3]=read(ram,0x0c0893e0u,4);
goto P_0c0893a8;
P_0c0893a8: /* original 4f26, guest PC 0x0c0893a8 */
if(!s->budget--) { s->failed_pc=0x0c0893a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0893aa;
P_0c0893aa: /* original e401, guest PC 0x0c0893aa */
if(!s->budget--) { s->failed_pc=0x0c0893aau; return 0; }
r[4]=0x00000001u;
goto P_0c0893ac;
P_0c0893ac: /* original fcf9, guest PC 0x0c0893ac */
if(!s->budget--) { s->failed_pc=0x0c0893acu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0893ae;
P_0c0893ae: /* original fdf9, guest PC 0x0c0893ae */
if(!s->budget--) { s->failed_pc=0x0c0893aeu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0893b0;
P_0c0893b0: /* original fef9, guest PC 0x0c0893b0 */
if(!s->budget--) { s->failed_pc=0x0c0893b0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0893b2;
P_0c0893b2: /* original fff9, guest PC 0x0c0893b2 */
if(!s->budget--) { s->failed_pc=0x0c0893b2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0893b4;
P_0c0893b4: /* original 6af6, guest PC 0x0c0893b4 */
if(!s->budget--) { s->failed_pc=0x0c0893b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0893b6;
P_0c0893b6: /* original 6bf6, guest PC 0x0c0893b6 */
if(!s->budget--) { s->failed_pc=0x0c0893b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0893b8;
P_0c0893b8: /* original 6cf6, guest PC 0x0c0893b8 */
if(!s->budget--) { s->failed_pc=0x0c0893b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0893ba;
P_0c0893ba: /* original 6df6, guest PC 0x0c0893ba */
if(!s->budget--) { s->failed_pc=0x0c0893bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0893bc;
P_0c0893bc: /* original 432b, guest PC 0x0c0893bc */
if(!s->budget--) { s->failed_pc=0x0c0893bcu; return 0; }
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
P_0c0893be: /* original 6ef6, guest PC 0x0c0893be */
if(!s->budget--) { s->failed_pc=0x0c0893beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0893c0u,s,ram);
P_0c08a8e4: /* original 4f22, guest PC 0x0c08a8e4 */
if(!s->budget--) { s->failed_pc=0x0c08a8e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a8e6;
P_0c08a8e6: /* original d911, guest PC 0x0c08a8e6 */
if(!s->budget--) { s->failed_pc=0x0c08a8e6u; return 0; }
r[9]=read(ram,0x0c08a92cu,4);
goto P_0c08a8e8;
P_0c08a8e8: /* original da11, guest PC 0x0c08a8e8 */
if(!s->budget--) { s->failed_pc=0x0c08a8e8u; return 0; }
r[10]=read(ram,0x0c08a930u,4);
goto P_0c08a8ea;
P_0c08a8ea: /* original 85e1, guest PC 0x0c08a8ea */
if(!s->budget--) { s->failed_pc=0x0c08a8eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c08a8ec;
P_0c08a8ec: /* original 6de1, guest PC 0x0c08a8ec */
if(!s->budget--) { s->failed_pc=0x0c08a8ecu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[13]=tmp;
goto P_0c08a8ee;
P_0c08a8ee: /* original 6403, guest PC 0x0c08a8ee */
if(!s->budget--) { s->failed_pc=0x0c08a8eeu; return 0; }
r[4]=r[0];
goto P_0c08a8f0;
P_0c08a8f0: /* original 3d4c, guest PC 0x0c08a8f0 */
if(!s->budget--) { s->failed_pc=0x0c08a8f0u; return 0; }
r[13]+=r[4];
goto P_0c08a8f2;
P_0c08a8f2: /* original 6bdf, guest PC 0x0c08a8f2 */
if(!s->budget--) { s->failed_pc=0x0c08a8f2u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c08a8f4;
P_0c08a8f4: /* original 2ed1, guest PC 0x0c08a8f4 */
if(!s->budget--) { s->failed_pc=0x0c08a8f4u; return 0; }
write(ram,r[14],r[13],2);
goto P_0c08a8f6;
P_0c08a8f6: /* original 4a0b, guest PC 0x0c08a8f6 */
if(!s->budget--) { s->failed_pc=0x0c08a8f6u; return 0; }
target=r[10];
r[16]=0x0c08a8fau;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a8fau) { target=s->pc; goto dispatch; }
goto P_0c08a8fa;
P_0c08a8f8: /* original 64b3, guest PC 0x0c08a8f8 */
if(!s->budget--) { s->failed_pc=0x0c08a8f8u; return 0; }
r[4]=r[11];
goto P_0c08a8fa;
P_0c08a8fa: /* original ff0c, guest PC 0x0c08a8fa */
if(!s->budget--) { s->failed_pc=0x0c08a8fau; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c08a8fc;
P_0c08a8fc: /* original 490b, guest PC 0x0c08a8fc */
if(!s->budget--) { s->failed_pc=0x0c08a8fcu; return 0; }
target=r[9];
r[16]=0x0c08a900u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a900u) { target=s->pc; goto dispatch; }
goto P_0c08a900;
P_0c08a8fe: /* original 64b3, guest PC 0x0c08a8fe */
if(!s->budget--) { s->failed_pc=0x0c08a8feu; return 0; }
r[4]=r[11];
goto P_0c08a900;
P_0c08a900: /* original e004, guest PC 0x0c08a900 */
if(!s->budget--) { s->failed_pc=0x0c08a900u; return 0; }
r[0]=0x00000004u;
goto P_0c08a902;
P_0c08a902: /* original f40c, guest PC 0x0c08a902 */
if(!s->budget--) { s->failed_pc=0x0c08a902u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08a904;
P_0c08a904: /* original f5e6, guest PC 0x0c08a904 */
if(!s->budget--) { s->failed_pc=0x0c08a904u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08a906;
P_0c08a906: /* original e008, guest PC 0x0c08a906 */
if(!s->budget--) { s->failed_pc=0x0c08a906u; return 0; }
r[0]=0x00000008u;
goto P_0c08a908;
P_0c08a908: /* original 4c10, guest PC 0x0c08a908 */
if(!s->budget--) { s->failed_pc=0x0c08a908u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c08a90a;
P_0c08a90a: /* original ff52, guest PC 0x0c08a90a */
if(!s->budget--) { s->failed_pc=0x0c08a90au; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'*');
goto P_0c08a90c;
P_0c08a90c: /* original f452, guest PC 0x0c08a90c */
if(!s->budget--) { s->failed_pc=0x0c08a90cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c08a90e;
P_0c08a90e: /* original fef7, guest PC 0x0c08a90e */
if(!s->budget--) { s->failed_pc=0x0c08a90eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08a910;
P_0c08a910: /* original e00c, guest PC 0x0c08a910 */
if(!s->budget--) { s->failed_pc=0x0c08a910u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a912;
P_0c08a912: /* original fe47, guest PC 0x0c08a912 */
if(!s->budget--) { s->failed_pc=0x0c08a912u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a914;
P_0c08a914: /* original 8fe9, guest PC 0x0c08a914 */
if(!s->budget--) { s->failed_pc=0x0c08a914u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000010u;
if(!cond) { goto P_0c08a8ea; }
goto P_0c08a918;
P_0c08a916: /* original 7e10, guest PC 0x0c08a916 */
if(!s->budget--) { s->failed_pc=0x0c08a916u; return 0; }
r[14]+=0x00000010u;
goto P_0c08a918;
P_0c08a918: /* original 4f26, guest PC 0x0c08a918 */
if(!s->budget--) { s->failed_pc=0x0c08a918u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a91a;
P_0c08a91a: /* original fff9, guest PC 0x0c08a91a */
if(!s->budget--) { s->failed_pc=0x0c08a91au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a91c;
P_0c08a91c: /* original 69f6, guest PC 0x0c08a91c */
if(!s->budget--) { s->failed_pc=0x0c08a91cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08a91e;
P_0c08a91e: /* original 6af6, guest PC 0x0c08a91e */
if(!s->budget--) { s->failed_pc=0x0c08a91eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08a920;
P_0c08a920: /* original 6bf6, guest PC 0x0c08a920 */
if(!s->budget--) { s->failed_pc=0x0c08a920u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a922;
P_0c08a922: /* original 6cf6, guest PC 0x0c08a922 */
if(!s->budget--) { s->failed_pc=0x0c08a922u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a924;
P_0c08a924: /* original 6df6, guest PC 0x0c08a924 */
if(!s->budget--) { s->failed_pc=0x0c08a924u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a926;
P_0c08a926: /* original 000b, guest PC 0x0c08a926 */
if(!s->budget--) { s->failed_pc=0x0c08a926u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a928: /* original 6ef6, guest PC 0x0c08a928 */
if(!s->budget--) { s->failed_pc=0x0c08a928u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08a92au,s,ram);
P_0c08b528: /* original 4f22, guest PC 0x0c08b528 */
if(!s->budget--) { s->failed_pc=0x0c08b528u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b52a;
P_0c08b52a: /* original 1433, guest PC 0x0c08b52a */
if(!s->budget--) { s->failed_pc=0x0c08b52au; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c08b52c;
P_0c08b52c: /* original 0424, guest PC 0x0c08b52c */
if(!s->budget--) { s->failed_pc=0x0c08b52cu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c08b52e;
P_0c08b52e: /* original dd41, guest PC 0x0c08b52e */
if(!s->budget--) { s->failed_pc=0x0c08b52eu; return 0; }
r[13]=read(ram,0x0c08b634u,4);
goto P_0c08b530;
P_0c08b530: /* original 63d2, guest PC 0x0c08b530 */
if(!s->budget--) { s->failed_pc=0x0c08b530u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c08b532;
P_0c08b532: /* original 430b, guest PC 0x0c08b532 */
if(!s->budget--) { s->failed_pc=0x0c08b532u; return 0; }
target=r[3];
r[16]=0x0c08b536u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b536u) { target=s->pc; goto dispatch; }
goto P_0c08b536;
P_0c08b534: /* original 0009, guest PC 0x0c08b534 */
if(!s->budget--) { s->failed_pc=0x0c08b534u; return 0; }
goto P_0c08b536;
P_0c08b536: /* original 4e10, guest PC 0x0c08b536 */
if(!s->budget--) { s->failed_pc=0x0c08b536u; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c08b538;
P_0c08b538: /* original 8ffa, guest PC 0x0c08b538 */
if(!s->budget--) { s->failed_pc=0x0c08b538u; return 0; }
cond=r[17]&1u;
r[13]+=0x0000001cu;
if(!cond) { goto P_0c08b530; }
goto P_0c08b53c;
P_0c08b53a: /* original 7d1c, guest PC 0x0c08b53a */
if(!s->budget--) { s->failed_pc=0x0c08b53au; return 0; }
r[13]+=0x0000001cu;
goto P_0c08b53c;
P_0c08b53c: /* original 4f26, guest PC 0x0c08b53c */
if(!s->budget--) { s->failed_pc=0x0c08b53cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b53e;
P_0c08b53e: /* original 6df6, guest PC 0x0c08b53e */
if(!s->budget--) { s->failed_pc=0x0c08b53eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b540;
P_0c08b540: /* original 000b, guest PC 0x0c08b540 */
if(!s->budget--) { s->failed_pc=0x0c08b540u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b542: /* original 6ef6, guest PC 0x0c08b542 */
if(!s->budget--) { s->failed_pc=0x0c08b542u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b544u,s,ram);
P_0c096174: /* original 4f22, guest PC 0x0c096174 */
if(!s->budget--) { s->failed_pc=0x0c096174u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096176;
P_0c096176: /* original dd1a, guest PC 0x0c096176 */
if(!s->budget--) { s->failed_pc=0x0c096176u; return 0; }
r[13]=read(ram,0x0c0961e0u,4);
goto P_0c096178;
P_0c096178: /* original 2c32, guest PC 0x0c096178 */
if(!s->budget--) { s->failed_pc=0x0c096178u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c09617a;
P_0c09617a: /* original 6ed3, guest PC 0x0c09617a */
if(!s->budget--) { s->failed_pc=0x0c09617au; return 0; }
r[14]=r[13];
goto P_0c09617c;
P_0c09617c: /* original 60e2, guest PC 0x0c09617c */
if(!s->budget--) { s->failed_pc=0x0c09617cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09617e;
P_0c09617e: /* original c801, guest PC 0x0c09617e */
if(!s->budget--) { s->failed_pc=0x0c09617eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c096180;
P_0c096180: /* original 8902, guest PC 0x0c096180 */
if(!s->budget--) { s->failed_pc=0x0c096180u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096188; }
goto P_0c096182;
P_0c096182: /* original 53e3, guest PC 0x0c096182 */
if(!s->budget--) { s->failed_pc=0x0c096182u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c096184;
P_0c096184: /* original 430b, guest PC 0x0c096184 */
if(!s->budget--) { s->failed_pc=0x0c096184u; return 0; }
target=r[3];
r[16]=0x0c096188u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096188u) { target=s->pc; goto dispatch; }
goto P_0c096188;
P_0c096186: /* original 64e3, guest PC 0x0c096186 */
if(!s->budget--) { s->failed_pc=0x0c096186u; return 0; }
r[4]=r[14];
goto P_0c096188;
P_0c096188: /* original 63c2, guest PC 0x0c096188 */
if(!s->budget--) { s->failed_pc=0x0c096188u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c09618a;
P_0c09618a: /* original 52e2, guest PC 0x0c09618a */
if(!s->budget--) { s->failed_pc=0x0c09618au; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c09618c;
P_0c09618c: /* original 73ff, guest PC 0x0c09618c */
if(!s->budget--) { s->failed_pc=0x0c09618cu; return 0; }
r[3]+=0xffffffffu;
goto P_0c09618e;
P_0c09618e: /* original 3d2c, guest PC 0x0c09618e */
if(!s->budget--) { s->failed_pc=0x0c09618eu; return 0; }
r[13]+=r[2];
goto P_0c096190;
P_0c096190: /* original 6133, guest PC 0x0c096190 */
if(!s->budget--) { s->failed_pc=0x0c096190u; return 0; }
r[1]=r[3];
goto P_0c096192;
P_0c096192: /* original e200, guest PC 0x0c096192 */
if(!s->budget--) { s->failed_pc=0x0c096192u; return 0; }
r[2]=0x00000000u;
goto P_0c096194;
P_0c096194: /* original 2c32, guest PC 0x0c096194 */
if(!s->budget--) { s->failed_pc=0x0c096194u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c096196;
P_0c096196: /* original 3126, guest PC 0x0c096196 */
if(!s->budget--) { s->failed_pc=0x0c096196u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c096198;
P_0c096198: /* original 89ef, guest PC 0x0c096198 */
if(!s->budget--) { s->failed_pc=0x0c096198u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09617a; }
goto P_0c09619a;
P_0c09619a: /* original 4f26, guest PC 0x0c09619a */
if(!s->budget--) { s->failed_pc=0x0c09619au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09619c;
P_0c09619c: /* original 6cf6, guest PC 0x0c09619c */
if(!s->budget--) { s->failed_pc=0x0c09619cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09619e;
P_0c09619e: /* original 6df6, guest PC 0x0c09619e */
if(!s->budget--) { s->failed_pc=0x0c09619eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0961a0;
P_0c0961a0: /* original 000b, guest PC 0x0c0961a0 */
if(!s->budget--) { s->failed_pc=0x0c0961a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0961a2: /* original 6ef6, guest PC 0x0c0961a2 */
if(!s->budget--) { s->failed_pc=0x0c0961a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0961a4u,s,ram);
P_0c09cacc: /* original 2fe6, guest PC 0x0c09cacc */
if(!s->budget--) { s->failed_pc=0x0c09caccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cace;
P_0c09cace: /* original 2fd6, guest PC 0x0c09cace */
if(!s->budget--) { s->failed_pc=0x0c09caceu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad0;
P_0c09cad0: /* original 2fc6, guest PC 0x0c09cad0 */
if(!s->budget--) { s->failed_pc=0x0c09cad0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad2;
P_0c09cad2: /* original 2fb6, guest PC 0x0c09cad2 */
if(!s->budget--) { s->failed_pc=0x0c09cad2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad4;
P_0c09cad4: /* original 2fa6, guest PC 0x0c09cad4 */
if(!s->budget--) { s->failed_pc=0x0c09cad4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad6;
P_0c09cad6: /* original 2f96, guest PC 0x0c09cad6 */
if(!s->budget--) { s->failed_pc=0x0c09cad6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad8;
P_0c09cad8: /* original 2f86, guest PC 0x0c09cad8 */
if(!s->budget--) { s->failed_pc=0x0c09cad8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cada;
P_0c09cada: /* original 4f22, guest PC 0x0c09cada */
if(!s->budget--) { s->failed_pc=0x0c09cadau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09cadc;
P_0c09cadc: /* original d31a, guest PC 0x0c09cadc */
if(!s->budget--) { s->failed_pc=0x0c09cadcu; return 0; }
r[3]=read(ram,0x0c09cb48u,4);
goto P_0c09cade;
P_0c09cade: /* original de19, guest PC 0x0c09cade */
if(!s->budget--) { s->failed_pc=0x0c09cadeu; return 0; }
r[14]=read(ram,0x0c09cb44u,4);
goto P_0c09cae0;
P_0c09cae0: /* original 430b, guest PC 0x0c09cae0 */
if(!s->budget--) { s->failed_pc=0x0c09cae0u; return 0; }
target=r[3];
r[16]=0x0c09cae4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cae4u) { target=s->pc; goto dispatch; }
goto P_0c09cae4;
P_0c09cae2: /* original 0009, guest PC 0x0c09cae2 */
if(!s->budget--) { s->failed_pc=0x0c09cae2u; return 0; }
goto P_0c09cae4;
P_0c09cae4: /* original 6d03, guest PC 0x0c09cae4 */
if(!s->budget--) { s->failed_pc=0x0c09cae4u; return 0; }
r[13]=r[0];
goto P_0c09cae6;
P_0c09cae6: /* original e07d, guest PC 0x0c09cae6 */
if(!s->budget--) { s->failed_pc=0x0c09cae6u; return 0; }
r[0]=0x0000007du;
goto P_0c09cae8;
P_0c09cae8: /* original e310, guest PC 0x0c09cae8 */
if(!s->budget--) { s->failed_pc=0x0c09cae8u; return 0; }
r[3]=0x00000010u;
goto P_0c09caea;
P_0c09caea: /* original e240, guest PC 0x0c09caea */
if(!s->budget--) { s->failed_pc=0x0c09caeau; return 0; }
r[2]=0x00000040u;
goto P_0c09caec;
P_0c09caec: /* original ec00, guest PC 0x0c09caec */
if(!s->budget--) { s->failed_pc=0x0c09caecu; return 0; }
r[12]=0x00000000u;
goto P_0c09caee;
P_0c09caee: /* original 1e23, guest PC 0x0c09caee */
if(!s->budget--) { s->failed_pc=0x0c09caeeu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09caf0;
P_0c09caf0: /* original 23d8, guest PC 0x0c09caf0 */
if(!s->budget--) { s->failed_pc=0x0c09caf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09caf2;
P_0c09caf2: /* original 1ec6, guest PC 0x0c09caf2 */
if(!s->budget--) { s->failed_pc=0x0c09caf2u; return 0; }
write(ram,r[14]+24,r[12],4);
goto P_0c09caf4;
P_0c09caf4: /* original 0ec4, guest PC 0x0c09caf4 */
if(!s->budget--) { s->failed_pc=0x0c09caf4u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c09caf6;
P_0c09caf6: /* original 1ec5, guest PC 0x0c09caf6 */
if(!s->budget--) { s->failed_pc=0x0c09caf6u; return 0; }
write(ram,r[14]+20,r[12],4);
goto P_0c09caf8;
P_0c09caf8: /* original db14, guest PC 0x0c09caf8 */
if(!s->budget--) { s->failed_pc=0x0c09caf8u; return 0; }
r[11]=read(ram,0x0c09cb4cu,4);
goto P_0c09cafa;
P_0c09cafa: /* original 8d2d, guest PC 0x0c09cafa */
if(!s->budget--) { s->failed_pc=0x0c09cafau; return 0; }
cond=r[17]&1u;
r[10]=0x00000003u;
if(cond) { goto P_0c09cb58; }
goto P_0c09cafe;
P_0c09cafc: /* original ea03, guest PC 0x0c09cafc */
if(!s->budget--) { s->failed_pc=0x0c09cafcu; return 0; }
r[10]=0x00000003u;
goto P_0c09cafe;
P_0c09cafe: /* original 941e, guest PC 0x0c09cafe */
if(!s->budget--) { s->failed_pc=0x0c09cafeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3eu,2);
goto P_0c09cb00;
P_0c09cb00: /* original 4b0b, guest PC 0x0c09cb00 */
if(!s->budget--) { s->failed_pc=0x0c09cb00u; return 0; }
target=r[11];
r[16]=0x0c09cb04u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cb04u) { target=s->pc; goto dispatch; }
goto P_0c09cb04;
P_0c09cb02: /* original 0009, guest PC 0x0c09cb02 */
if(!s->budget--) { s->failed_pc=0x0c09cb02u; return 0; }
goto P_0c09cb04;
P_0c09cb04: /* original 901a, guest PC 0x0c09cb04 */
if(!s->budget--) { s->failed_pc=0x0c09cb04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3cu,2);
goto P_0c09cb06;
P_0c09cb06: /* original 03ee, guest PC 0x0c09cb06 */
if(!s->budget--) { s->failed_pc=0x0c09cb06u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cb08;
P_0c09cb08: /* original 73ff, guest PC 0x0c09cb08 */
if(!s->budget--) { s->failed_pc=0x0c09cb08u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cb0a;
P_0c09cb0a: /* original 0e36, guest PC 0x0c09cb0a */
if(!s->budget--) { s->failed_pc=0x0c09cb0au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cb0c;
P_0c09cb0c: /* original 02ee, guest PC 0x0c09cb0c */
if(!s->budget--) { s->failed_pc=0x0c09cb0cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cb0e;
P_0c09cb0e: /* original 4211, guest PC 0x0c09cb0e */
if(!s->budget--) { s->failed_pc=0x0c09cb0eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cb10;
P_0c09cb10: /* original 8900, guest PC 0x0c09cb10 */
if(!s->budget--) { s->failed_pc=0x0c09cb10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb14; }
goto P_0c09cb12;
P_0c09cb12: /* original 0ea6, guest PC 0x0c09cb12 */
if(!s->budget--) { s->failed_pc=0x0c09cb12u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09cb14;
P_0c09cb14: /* original 00ee, guest PC 0x0c09cb14 */
if(!s->budget--) { s->failed_pc=0x0c09cb14u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cb16;
P_0c09cb16: /* original 8800, guest PC 0x0c09cb16 */
if(!s->budget--) { s->failed_pc=0x0c09cb16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cb18;
P_0c09cb18: /* original 8905, guest PC 0x0c09cb18 */
if(!s->budget--) { s->failed_pc=0x0c09cb18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb26; }
goto P_0c09cb1a;
P_0c09cb1a: /* original 8801, guest PC 0x0c09cb1a */
if(!s->budget--) { s->failed_pc=0x0c09cb1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cb1c;
P_0c09cb1c: /* original 8908, guest PC 0x0c09cb1c */
if(!s->budget--) { s->failed_pc=0x0c09cb1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb30; }
goto P_0c09cb1e;
P_0c09cb1e: /* original 8802, guest PC 0x0c09cb1e */
if(!s->budget--) { s->failed_pc=0x0c09cb1eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cb20;
P_0c09cb20: /* original 8916, guest PC 0x0c09cb20 */
if(!s->budget--) { s->failed_pc=0x0c09cb20u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb50; }
goto P_0c09cb22;
P_0c09cb22: /* original a019, guest PC 0x0c09cb22 */
if(!s->budget--) { s->failed_pc=0x0c09cb22u; return 0; }
goto P_0c09cb58;
P_0c09cb24: /* original 0009, guest PC 0x0c09cb24 */
if(!s->budget--) { s->failed_pc=0x0c09cb24u; return 0; }
goto P_0c09cb26;
P_0c09cb26: /* original 900b, guest PC 0x0c09cb26 */
if(!s->budget--) { s->failed_pc=0x0c09cb26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb40u,2);
goto P_0c09cb28;
P_0c09cb28: /* original 03ee, guest PC 0x0c09cb28 */
if(!s->budget--) { s->failed_pc=0x0c09cb28u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cb2a;
P_0c09cb2a: /* original 70f8, guest PC 0x0c09cb2a */
if(!s->budget--) { s->failed_pc=0x0c09cb2au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c09cb2c;
P_0c09cb2c: /* original a014, guest PC 0x0c09cb2c */
if(!s->budget--) { s->failed_pc=0x0c09cb2cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cb58;
P_0c09cb2e: /* original 0e36, guest PC 0x0c09cb2e */
if(!s->budget--) { s->failed_pc=0x0c09cb2eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cb30;
P_0c09cb30: /* original 9007, guest PC 0x0c09cb30 */
if(!s->budget--) { s->failed_pc=0x0c09cb30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb42u,2);
goto P_0c09cb32;
P_0c09cb32: /* original 01ee, guest PC 0x0c09cb32 */
if(!s->budget--) { s->failed_pc=0x0c09cb32u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09cb34;
P_0c09cb34: /* original 70f4, guest PC 0x0c09cb34 */
if(!s->budget--) { s->failed_pc=0x0c09cb34u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c09cb36;
P_0c09cb36: /* original a00f, guest PC 0x0c09cb36 */
if(!s->budget--) { s->failed_pc=0x0c09cb36u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09cb58;
P_0c09cb38: /* original 0e16, guest PC 0x0c09cb38 */
if(!s->budget--) { s->failed_pc=0x0c09cb38u; return 0; }
write(ram,r[14]+r[0],r[1],4);
return vf3_matrix_family(0x0c09cb3au,s,ram);
P_0c09cb50: /* original 9066, guest PC 0x0c09cb50 */
if(!s->budget--) { s->failed_pc=0x0c09cb50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc20u,2);
goto P_0c09cb52;
P_0c09cb52: /* original 02ee, guest PC 0x0c09cb52 */
if(!s->budget--) { s->failed_pc=0x0c09cb52u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cb54;
P_0c09cb54: /* original 70f0, guest PC 0x0c09cb54 */
if(!s->budget--) { s->failed_pc=0x0c09cb54u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c09cb56;
P_0c09cb56: /* original 0e26, guest PC 0x0c09cb56 */
if(!s->budget--) { s->failed_pc=0x0c09cb56u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09cb58;
P_0c09cb58: /* original e120, guest PC 0x0c09cb58 */
if(!s->budget--) { s->failed_pc=0x0c09cb58u; return 0; }
r[1]=0x00000020u;
goto P_0c09cb5a;
P_0c09cb5a: /* original 21d8, guest PC 0x0c09cb5a */
if(!s->budget--) { s->failed_pc=0x0c09cb5au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c09cb5c;
P_0c09cb5c: /* original 8921, guest PC 0x0c09cb5c */
if(!s->budget--) { s->failed_pc=0x0c09cb5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cba2; }
goto P_0c09cb5e;
P_0c09cb5e: /* original 9460, guest PC 0x0c09cb5e */
if(!s->budget--) { s->failed_pc=0x0c09cb5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc22u,2);
goto P_0c09cb60;
P_0c09cb60: /* original 4b0b, guest PC 0x0c09cb60 */
if(!s->budget--) { s->failed_pc=0x0c09cb60u; return 0; }
target=r[11];
r[16]=0x0c09cb64u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cb64u) { target=s->pc; goto dispatch; }
goto P_0c09cb64;
P_0c09cb62: /* original 0009, guest PC 0x0c09cb62 */
if(!s->budget--) { s->failed_pc=0x0c09cb62u; return 0; }
goto P_0c09cb64;
P_0c09cb64: /* original 905e, guest PC 0x0c09cb64 */
if(!s->budget--) { s->failed_pc=0x0c09cb64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc24u,2);
goto P_0c09cb66;
P_0c09cb66: /* original 02ee, guest PC 0x0c09cb66 */
if(!s->budget--) { s->failed_pc=0x0c09cb66u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cb68;
P_0c09cb68: /* original 7201, guest PC 0x0c09cb68 */
if(!s->budget--) { s->failed_pc=0x0c09cb68u; return 0; }
r[2]+=0x00000001u;
goto P_0c09cb6a;
P_0c09cb6a: /* original 0e26, guest PC 0x0c09cb6a */
if(!s->budget--) { s->failed_pc=0x0c09cb6au; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09cb6c;
P_0c09cb6c: /* original 03ee, guest PC 0x0c09cb6c */
if(!s->budget--) { s->failed_pc=0x0c09cb6cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cb6e;
P_0c09cb6e: /* original 33a7, guest PC 0x0c09cb6e */
if(!s->budget--) { s->failed_pc=0x0c09cb6eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[10])!=0);
goto P_0c09cb70;
P_0c09cb70: /* original 8b00, guest PC 0x0c09cb70 */
if(!s->budget--) { s->failed_pc=0x0c09cb70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cb74; }
goto P_0c09cb72;
P_0c09cb72: /* original 0ec6, guest PC 0x0c09cb72 */
if(!s->budget--) { s->failed_pc=0x0c09cb72u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09cb74;
P_0c09cb74: /* original 00ee, guest PC 0x0c09cb74 */
if(!s->budget--) { s->failed_pc=0x0c09cb74u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cb76;
P_0c09cb76: /* original 8800, guest PC 0x0c09cb76 */
if(!s->budget--) { s->failed_pc=0x0c09cb76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cb78;
P_0c09cb78: /* original 8905, guest PC 0x0c09cb78 */
if(!s->budget--) { s->failed_pc=0x0c09cb78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb86; }
goto P_0c09cb7a;
P_0c09cb7a: /* original 8801, guest PC 0x0c09cb7a */
if(!s->budget--) { s->failed_pc=0x0c09cb7au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cb7c;
P_0c09cb7c: /* original 8908, guest PC 0x0c09cb7c */
if(!s->budget--) { s->failed_pc=0x0c09cb7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb90; }
goto P_0c09cb7e;
P_0c09cb7e: /* original 8802, guest PC 0x0c09cb7e */
if(!s->budget--) { s->failed_pc=0x0c09cb7eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cb80;
P_0c09cb80: /* original 890b, guest PC 0x0c09cb80 */
if(!s->budget--) { s->failed_pc=0x0c09cb80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb9a; }
goto P_0c09cb82;
P_0c09cb82: /* original a00e, guest PC 0x0c09cb82 */
if(!s->budget--) { s->failed_pc=0x0c09cb82u; return 0; }
goto P_0c09cba2;
P_0c09cb84: /* original 0009, guest PC 0x0c09cb84 */
if(!s->budget--) { s->failed_pc=0x0c09cb84u; return 0; }
goto P_0c09cb86;
P_0c09cb86: /* original 904e, guest PC 0x0c09cb86 */
if(!s->budget--) { s->failed_pc=0x0c09cb86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc26u,2);
goto P_0c09cb88;
P_0c09cb88: /* original 03ee, guest PC 0x0c09cb88 */
if(!s->budget--) { s->failed_pc=0x0c09cb88u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cb8a;
P_0c09cb8a: /* original 70f8, guest PC 0x0c09cb8a */
if(!s->budget--) { s->failed_pc=0x0c09cb8au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c09cb8c;
P_0c09cb8c: /* original a009, guest PC 0x0c09cb8c */
if(!s->budget--) { s->failed_pc=0x0c09cb8cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cba2;
P_0c09cb8e: /* original 0e36, guest PC 0x0c09cb8e */
if(!s->budget--) { s->failed_pc=0x0c09cb8eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cb90;
P_0c09cb90: /* original 904a, guest PC 0x0c09cb90 */
if(!s->budget--) { s->failed_pc=0x0c09cb90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc28u,2);
goto P_0c09cb92;
P_0c09cb92: /* original 01ee, guest PC 0x0c09cb92 */
if(!s->budget--) { s->failed_pc=0x0c09cb92u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09cb94;
P_0c09cb94: /* original 70f4, guest PC 0x0c09cb94 */
if(!s->budget--) { s->failed_pc=0x0c09cb94u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c09cb96;
P_0c09cb96: /* original a004, guest PC 0x0c09cb96 */
if(!s->budget--) { s->failed_pc=0x0c09cb96u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09cba2;
P_0c09cb98: /* original 0e16, guest PC 0x0c09cb98 */
if(!s->budget--) { s->failed_pc=0x0c09cb98u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09cb9a;
P_0c09cb9a: /* original 9041, guest PC 0x0c09cb9a */
if(!s->budget--) { s->failed_pc=0x0c09cb9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc20u,2);
goto P_0c09cb9c;
P_0c09cb9c: /* original 02ee, guest PC 0x0c09cb9c */
if(!s->budget--) { s->failed_pc=0x0c09cb9cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cb9e;
P_0c09cb9e: /* original 70f0, guest PC 0x0c09cb9e */
if(!s->budget--) { s->failed_pc=0x0c09cb9eu; return 0; }
r[0]+=0xfffffff0u;
goto P_0c09cba0;
P_0c09cba0: /* original 0e26, guest PC 0x0c09cba0 */
if(!s->budget--) { s->failed_pc=0x0c09cba0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09cba2;
P_0c09cba2: /* original 9642, guest PC 0x0c09cba2 */
if(!s->budget--) { s->failed_pc=0x0c09cba2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2au,2);
goto P_0c09cba4;
P_0c09cba4: /* original e240, guest PC 0x0c09cba4 */
if(!s->budget--) { s->failed_pc=0x0c09cba4u; return 0; }
r[2]=0x00000040u;
goto P_0c09cba6;
P_0c09cba6: /* original 22d8, guest PC 0x0c09cba6 */
if(!s->budget--) { s->failed_pc=0x0c09cba6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09cba8;
P_0c09cba8: /* original 6563, guest PC 0x0c09cba8 */
if(!s->budget--) { s->failed_pc=0x0c09cba8u; return 0; }
r[5]=r[6];
goto P_0c09cbaa;
P_0c09cbaa: /* original 75d0, guest PC 0x0c09cbaa */
if(!s->budget--) { s->failed_pc=0x0c09cbaau; return 0; }
r[5]+=0xffffffd0u;
goto P_0c09cbac;
P_0c09cbac: /* original 8d2b, guest PC 0x0c09cbac */
if(!s->budget--) { s->failed_pc=0x0c09cbacu; return 0; }
cond=r[17]&1u;
r[4]=0x0000001eu;
if(cond) { goto P_0c09cc06; }
goto P_0c09cbb0;
P_0c09cbae: /* original e41e, guest PC 0x0c09cbae */
if(!s->budget--) { s->failed_pc=0x0c09cbaeu; return 0; }
r[4]=0x0000001eu;
goto P_0c09cbb0;
P_0c09cbb0: /* original 9038, guest PC 0x0c09cbb0 */
if(!s->budget--) { s->failed_pc=0x0c09cbb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc24u,2);
goto P_0c09cbb2;
P_0c09cbb2: /* original 00ee, guest PC 0x0c09cbb2 */
if(!s->budget--) { s->failed_pc=0x0c09cbb2u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cbb4;
P_0c09cbb4: /* original 8800, guest PC 0x0c09cbb4 */
if(!s->budget--) { s->failed_pc=0x0c09cbb4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cbb6;
P_0c09cbb6: /* original 8905, guest PC 0x0c09cbb6 */
if(!s->budget--) { s->failed_pc=0x0c09cbb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbc4; }
goto P_0c09cbb8;
P_0c09cbb8: /* original 8801, guest PC 0x0c09cbb8 */
if(!s->budget--) { s->failed_pc=0x0c09cbb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cbba;
P_0c09cbba: /* original 890e, guest PC 0x0c09cbba */
if(!s->budget--) { s->failed_pc=0x0c09cbbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbda; }
goto P_0c09cbbc;
P_0c09cbbc: /* original 8802, guest PC 0x0c09cbbc */
if(!s->budget--) { s->failed_pc=0x0c09cbbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cbbe;
P_0c09cbbe: /* original 8917, guest PC 0x0c09cbbe */
if(!s->budget--) { s->failed_pc=0x0c09cbbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbf0; }
goto P_0c09cbc0;
P_0c09cbc0: /* original a021, guest PC 0x0c09cbc0 */
if(!s->budget--) { s->failed_pc=0x0c09cbc0u; return 0; }
goto P_0c09cc06;
P_0c09cbc2: /* original 0009, guest PC 0x0c09cbc2 */
if(!s->budget--) { s->failed_pc=0x0c09cbc2u; return 0; }
goto P_0c09cbc4;
P_0c09cbc4: /* original 9032, guest PC 0x0c09cbc4 */
if(!s->budget--) { s->failed_pc=0x0c09cbc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2cu,2);
goto P_0c09cbc6;
P_0c09cbc6: /* original 03ee, guest PC 0x0c09cbc6 */
if(!s->budget--) { s->failed_pc=0x0c09cbc6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbc8;
P_0c09cbc8: /* original 73ff, guest PC 0x0c09cbc8 */
if(!s->budget--) { s->failed_pc=0x0c09cbc8u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cbca;
P_0c09cbca: /* original 0e36, guest PC 0x0c09cbca */
if(!s->budget--) { s->failed_pc=0x0c09cbcau; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cbcc;
P_0c09cbcc: /* original 02ee, guest PC 0x0c09cbcc */
if(!s->budget--) { s->failed_pc=0x0c09cbccu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cbce;
P_0c09cbce: /* original 4211, guest PC 0x0c09cbce */
if(!s->budget--) { s->failed_pc=0x0c09cbceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cbd0;
P_0c09cbd0: /* original 8900, guest PC 0x0c09cbd0 */
if(!s->budget--) { s->failed_pc=0x0c09cbd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbd4; }
goto P_0c09cbd2;
P_0c09cbd2: /* original 0e56, guest PC 0x0c09cbd2 */
if(!s->budget--) { s->failed_pc=0x0c09cbd2u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c09cbd4;
P_0c09cbd4: /* original 03ee, guest PC 0x0c09cbd4 */
if(!s->budget--) { s->failed_pc=0x0c09cbd4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbd6;
P_0c09cbd6: /* original a015, guest PC 0x0c09cbd6 */
if(!s->budget--) { s->failed_pc=0x0c09cbd6u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cc04;
P_0c09cbd8: /* original 7008, guest PC 0x0c09cbd8 */
if(!s->budget--) { s->failed_pc=0x0c09cbd8u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cbda;
P_0c09cbda: /* original 9027, guest PC 0x0c09cbda */
if(!s->budget--) { s->failed_pc=0x0c09cbdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2cu,2);
goto P_0c09cbdc;
P_0c09cbdc: /* original 03ee, guest PC 0x0c09cbdc */
if(!s->budget--) { s->failed_pc=0x0c09cbdcu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbde;
P_0c09cbde: /* original 73ff, guest PC 0x0c09cbde */
if(!s->budget--) { s->failed_pc=0x0c09cbdeu; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cbe0;
P_0c09cbe0: /* original 0e36, guest PC 0x0c09cbe0 */
if(!s->budget--) { s->failed_pc=0x0c09cbe0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cbe2;
P_0c09cbe2: /* original 02ee, guest PC 0x0c09cbe2 */
if(!s->budget--) { s->failed_pc=0x0c09cbe2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cbe4;
P_0c09cbe4: /* original 4211, guest PC 0x0c09cbe4 */
if(!s->budget--) { s->failed_pc=0x0c09cbe4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cbe6;
P_0c09cbe6: /* original 8900, guest PC 0x0c09cbe6 */
if(!s->budget--) { s->failed_pc=0x0c09cbe6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbea; }
goto P_0c09cbe8;
P_0c09cbe8: /* original 0e66, guest PC 0x0c09cbe8 */
if(!s->budget--) { s->failed_pc=0x0c09cbe8u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c09cbea;
P_0c09cbea: /* original 03ee, guest PC 0x0c09cbea */
if(!s->budget--) { s->failed_pc=0x0c09cbeau; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbec;
P_0c09cbec: /* original a00a, guest PC 0x0c09cbec */
if(!s->budget--) { s->failed_pc=0x0c09cbecu; return 0; }
r[0]+=0x0000000cu;
goto P_0c09cc04;
P_0c09cbee: /* original 700c, guest PC 0x0c09cbee */
if(!s->budget--) { s->failed_pc=0x0c09cbeeu; return 0; }
r[0]+=0x0000000cu;
goto P_0c09cbf0;
P_0c09cbf0: /* original 901c, guest PC 0x0c09cbf0 */
if(!s->budget--) { s->failed_pc=0x0c09cbf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2cu,2);
goto P_0c09cbf2;
P_0c09cbf2: /* original 03ee, guest PC 0x0c09cbf2 */
if(!s->budget--) { s->failed_pc=0x0c09cbf2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbf4;
P_0c09cbf4: /* original 73ff, guest PC 0x0c09cbf4 */
if(!s->budget--) { s->failed_pc=0x0c09cbf4u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cbf6;
P_0c09cbf6: /* original 0e36, guest PC 0x0c09cbf6 */
if(!s->budget--) { s->failed_pc=0x0c09cbf6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cbf8;
P_0c09cbf8: /* original 02ee, guest PC 0x0c09cbf8 */
if(!s->budget--) { s->failed_pc=0x0c09cbf8u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cbfa;
P_0c09cbfa: /* original 4211, guest PC 0x0c09cbfa */
if(!s->budget--) { s->failed_pc=0x0c09cbfau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cbfc;
P_0c09cbfc: /* original 8900, guest PC 0x0c09cbfc */
if(!s->budget--) { s->failed_pc=0x0c09cbfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc00; }
goto P_0c09cbfe;
P_0c09cbfe: /* original 0e46, guest PC 0x0c09cbfe */
if(!s->budget--) { s->failed_pc=0x0c09cbfeu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cc00;
P_0c09cc00: /* original 03ee, guest PC 0x0c09cc00 */
if(!s->budget--) { s->failed_pc=0x0c09cc00u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc02;
P_0c09cc02: /* original 900d, guest PC 0x0c09cc02 */
if(!s->budget--) { s->failed_pc=0x0c09cc02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc20u,2);
goto P_0c09cc04;
P_0c09cc04: /* original 0e36, guest PC 0x0c09cc04 */
if(!s->budget--) { s->failed_pc=0x0c09cc04u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc06;
P_0c09cc06: /* original 9112, guest PC 0x0c09cc06 */
if(!s->budget--) { s->failed_pc=0x0c09cc06u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2eu,2);
goto P_0c09cc08;
P_0c09cc08: /* original 21d8, guest PC 0x0c09cc08 */
if(!s->budget--) { s->failed_pc=0x0c09cc08u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c09cc0a;
P_0c09cc0a: /* original 8932, guest PC 0x0c09cc0a */
if(!s->budget--) { s->failed_pc=0x0c09cc0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc72; }
goto P_0c09cc0c;
P_0c09cc0c: /* original 900a, guest PC 0x0c09cc0c */
if(!s->budget--) { s->failed_pc=0x0c09cc0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc24u,2);
goto P_0c09cc0e;
P_0c09cc0e: /* original 00ee, guest PC 0x0c09cc0e */
if(!s->budget--) { s->failed_pc=0x0c09cc0eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cc10;
P_0c09cc10: /* original 8800, guest PC 0x0c09cc10 */
if(!s->budget--) { s->failed_pc=0x0c09cc10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cc12;
P_0c09cc12: /* original 890d, guest PC 0x0c09cc12 */
if(!s->budget--) { s->failed_pc=0x0c09cc12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc30; }
goto P_0c09cc14;
P_0c09cc14: /* original 8801, guest PC 0x0c09cc14 */
if(!s->budget--) { s->failed_pc=0x0c09cc14u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cc16;
P_0c09cc16: /* original 8916, guest PC 0x0c09cc16 */
if(!s->budget--) { s->failed_pc=0x0c09cc16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc46; }
goto P_0c09cc18;
P_0c09cc18: /* original 8802, guest PC 0x0c09cc18 */
if(!s->budget--) { s->failed_pc=0x0c09cc18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cc1a;
P_0c09cc1a: /* original 891f, guest PC 0x0c09cc1a */
if(!s->budget--) { s->failed_pc=0x0c09cc1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc5c; }
goto P_0c09cc1c;
P_0c09cc1c: /* original a029, guest PC 0x0c09cc1c */
if(!s->budget--) { s->failed_pc=0x0c09cc1cu; return 0; }
goto P_0c09cc72;
P_0c09cc1e: /* original 0009, guest PC 0x0c09cc1e */
if(!s->budget--) { s->failed_pc=0x0c09cc1eu; return 0; }
return vf3_matrix_family(0x0c09cc20u,s,ram);
P_0c09cc30: /* original 9070, guest PC 0x0c09cc30 */
if(!s->budget--) { s->failed_pc=0x0c09cc30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd14u,2);
goto P_0c09cc32;
P_0c09cc32: /* original 03ee, guest PC 0x0c09cc32 */
if(!s->budget--) { s->failed_pc=0x0c09cc32u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc34;
P_0c09cc34: /* original 7301, guest PC 0x0c09cc34 */
if(!s->budget--) { s->failed_pc=0x0c09cc34u; return 0; }
r[3]+=0x00000001u;
goto P_0c09cc36;
P_0c09cc36: /* original 0e36, guest PC 0x0c09cc36 */
if(!s->budget--) { s->failed_pc=0x0c09cc36u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc38;
P_0c09cc38: /* original 02ee, guest PC 0x0c09cc38 */
if(!s->budget--) { s->failed_pc=0x0c09cc38u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cc3a;
P_0c09cc3a: /* original 3257, guest PC 0x0c09cc3a */
if(!s->budget--) { s->failed_pc=0x0c09cc3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[5])!=0);
goto P_0c09cc3c;
P_0c09cc3c: /* original 8b00, guest PC 0x0c09cc3c */
if(!s->budget--) { s->failed_pc=0x0c09cc3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc40; }
goto P_0c09cc3e;
P_0c09cc3e: /* original 0ec6, guest PC 0x0c09cc3e */
if(!s->budget--) { s->failed_pc=0x0c09cc3eu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09cc40;
P_0c09cc40: /* original 03ee, guest PC 0x0c09cc40 */
if(!s->budget--) { s->failed_pc=0x0c09cc40u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc42;
P_0c09cc42: /* original a015, guest PC 0x0c09cc42 */
if(!s->budget--) { s->failed_pc=0x0c09cc42u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cc70;
P_0c09cc44: /* original 7008, guest PC 0x0c09cc44 */
if(!s->budget--) { s->failed_pc=0x0c09cc44u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cc46;
P_0c09cc46: /* original 9065, guest PC 0x0c09cc46 */
if(!s->budget--) { s->failed_pc=0x0c09cc46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd14u,2);
goto P_0c09cc48;
P_0c09cc48: /* original 03ee, guest PC 0x0c09cc48 */
if(!s->budget--) { s->failed_pc=0x0c09cc48u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc4a;
P_0c09cc4a: /* original 7301, guest PC 0x0c09cc4a */
if(!s->budget--) { s->failed_pc=0x0c09cc4au; return 0; }
r[3]+=0x00000001u;
goto P_0c09cc4c;
P_0c09cc4c: /* original 0e36, guest PC 0x0c09cc4c */
if(!s->budget--) { s->failed_pc=0x0c09cc4cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc4e;
P_0c09cc4e: /* original 02ee, guest PC 0x0c09cc4e */
if(!s->budget--) { s->failed_pc=0x0c09cc4eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cc50;
P_0c09cc50: /* original 3267, guest PC 0x0c09cc50 */
if(!s->budget--) { s->failed_pc=0x0c09cc50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[6])!=0);
goto P_0c09cc52;
P_0c09cc52: /* original 8b00, guest PC 0x0c09cc52 */
if(!s->budget--) { s->failed_pc=0x0c09cc52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc56; }
goto P_0c09cc54;
P_0c09cc54: /* original 0ec6, guest PC 0x0c09cc54 */
if(!s->budget--) { s->failed_pc=0x0c09cc54u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09cc56;
P_0c09cc56: /* original 03ee, guest PC 0x0c09cc56 */
if(!s->budget--) { s->failed_pc=0x0c09cc56u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc58;
P_0c09cc58: /* original a00a, guest PC 0x0c09cc58 */
if(!s->budget--) { s->failed_pc=0x0c09cc58u; return 0; }
r[0]+=0x0000000cu;
goto P_0c09cc70;
P_0c09cc5a: /* original 700c, guest PC 0x0c09cc5a */
if(!s->budget--) { s->failed_pc=0x0c09cc5au; return 0; }
r[0]+=0x0000000cu;
goto P_0c09cc5c;
P_0c09cc5c: /* original 905a, guest PC 0x0c09cc5c */
if(!s->budget--) { s->failed_pc=0x0c09cc5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd14u,2);
goto P_0c09cc5e;
P_0c09cc5e: /* original 03ee, guest PC 0x0c09cc5e */
if(!s->budget--) { s->failed_pc=0x0c09cc5eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc60;
P_0c09cc60: /* original 7301, guest PC 0x0c09cc60 */
if(!s->budget--) { s->failed_pc=0x0c09cc60u; return 0; }
r[3]+=0x00000001u;
goto P_0c09cc62;
P_0c09cc62: /* original 0e36, guest PC 0x0c09cc62 */
if(!s->budget--) { s->failed_pc=0x0c09cc62u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc64;
P_0c09cc64: /* original 02ee, guest PC 0x0c09cc64 */
if(!s->budget--) { s->failed_pc=0x0c09cc64u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cc66;
P_0c09cc66: /* original 3247, guest PC 0x0c09cc66 */
if(!s->budget--) { s->failed_pc=0x0c09cc66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[4])!=0);
goto P_0c09cc68;
P_0c09cc68: /* original 8b00, guest PC 0x0c09cc68 */
if(!s->budget--) { s->failed_pc=0x0c09cc68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc6c; }
goto P_0c09cc6a;
P_0c09cc6a: /* original 0ec6, guest PC 0x0c09cc6a */
if(!s->budget--) { s->failed_pc=0x0c09cc6au; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09cc6c;
P_0c09cc6c: /* original 03ee, guest PC 0x0c09cc6c */
if(!s->budget--) { s->failed_pc=0x0c09cc6cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc6e;
P_0c09cc6e: /* original 9052, guest PC 0x0c09cc6e */
if(!s->budget--) { s->failed_pc=0x0c09cc6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd16u,2);
goto P_0c09cc70;
P_0c09cc70: /* original 0e36, guest PC 0x0c09cc70 */
if(!s->budget--) { s->failed_pc=0x0c09cc70u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc72;
P_0c09cc72: /* original d92d, guest PC 0x0c09cc72 */
if(!s->budget--) { s->failed_pc=0x0c09cc72u; return 0; }
r[9]=read(ram,0x0c09cd28u,4);
goto P_0c09cc74;
P_0c09cc74: /* original 63d3, guest PC 0x0c09cc74 */
if(!s->budget--) { s->failed_pc=0x0c09cc74u; return 0; }
r[3]=r[13];
goto P_0c09cc76;
P_0c09cc76: /* original e604, guest PC 0x0c09cc76 */
if(!s->budget--) { s->failed_pc=0x0c09cc76u; return 0; }
r[6]=0x00000004u;
goto P_0c09cc78;
P_0c09cc78: /* original d82a, guest PC 0x0c09cc78 */
if(!s->budget--) { s->failed_pc=0x0c09cc78u; return 0; }
r[8]=read(ram,0x0c09cd24u,4);
goto P_0c09cc7a;
P_0c09cc7a: /* original 2368, guest PC 0x0c09cc7a */
if(!s->budget--) { s->failed_pc=0x0c09cc7au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c09cc7c;
P_0c09cc7c: /* original 8b01, guest PC 0x0c09cc7c */
if(!s->budget--) { s->failed_pc=0x0c09cc7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc82; }
goto P_0c09cc7e;
P_0c09cc7e: /* original a0c0, guest PC 0x0c09cc7e */
if(!s->budget--) { s->failed_pc=0x0c09cc7eu; return 0; }
goto P_0c09ce02;
P_0c09cc80: /* original 0009, guest PC 0x0c09cc80 */
if(!s->budget--) { s->failed_pc=0x0c09cc80u; return 0; }
goto P_0c09cc82;
P_0c09cc82: /* original 9049, guest PC 0x0c09cc82 */
if(!s->budget--) { s->failed_pc=0x0c09cc82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd18u,2);
goto P_0c09cc84;
P_0c09cc84: /* original 00ee, guest PC 0x0c09cc84 */
if(!s->budget--) { s->failed_pc=0x0c09cc84u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cc86;
P_0c09cc86: /* original 8800, guest PC 0x0c09cc86 */
if(!s->budget--) { s->failed_pc=0x0c09cc86u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cc88;
P_0c09cc88: /* original 890b, guest PC 0x0c09cc88 */
if(!s->budget--) { s->failed_pc=0x0c09cc88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cca2; }
goto P_0c09cc8a;
P_0c09cc8a: /* original 8801, guest PC 0x0c09cc8a */
if(!s->budget--) { s->failed_pc=0x0c09cc8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cc8c;
P_0c09cc8c: /* original 8928, guest PC 0x0c09cc8c */
if(!s->budget--) { s->failed_pc=0x0c09cc8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cce0; }
goto P_0c09cc8e;
P_0c09cc8e: /* original 8802, guest PC 0x0c09cc8e */
if(!s->budget--) { s->failed_pc=0x0c09cc8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cc90;
P_0c09cc90: /* original 8b01, guest PC 0x0c09cc90 */
if(!s->budget--) { s->failed_pc=0x0c09cc90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc96; }
goto P_0c09cc92;
P_0c09cc92: /* original a08c, guest PC 0x0c09cc92 */
if(!s->budget--) { s->failed_pc=0x0c09cc92u; return 0; }
goto P_0c09cdae;
P_0c09cc94: /* original 0009, guest PC 0x0c09cc94 */
if(!s->budget--) { s->failed_pc=0x0c09cc94u; return 0; }
goto P_0c09cc96;
P_0c09cc96: /* original 8803, guest PC 0x0c09cc96 */
if(!s->budget--) { s->failed_pc=0x0c09cc96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09cc98;
P_0c09cc98: /* original 8b01, guest PC 0x0c09cc98 */
if(!s->budget--) { s->failed_pc=0x0c09cc98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc9e; }
goto P_0c09cc9a;
P_0c09cc9a: /* original a0a7, guest PC 0x0c09cc9a */
if(!s->budget--) { s->failed_pc=0x0c09cc9au; return 0; }
goto P_0c09cdec;
P_0c09cc9c: /* original 0009, guest PC 0x0c09cc9c */
if(!s->budget--) { s->failed_pc=0x0c09cc9cu; return 0; }
goto P_0c09cc9e;
P_0c09cc9e: /* original a0b0, guest PC 0x0c09cc9e */
if(!s->budget--) { s->failed_pc=0x0c09cc9eu; return 0; }
goto P_0c09ce02;
P_0c09cca0: /* original 0009, guest PC 0x0c09cca0 */
if(!s->budget--) { s->failed_pc=0x0c09cca0u; return 0; }
goto P_0c09cca2;
P_0c09cca2: /* original 903a, guest PC 0x0c09cca2 */
if(!s->budget--) { s->failed_pc=0x0c09cca2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd1au,2);
goto P_0c09cca4;
P_0c09cca4: /* original dc21, guest PC 0x0c09cca4 */
if(!s->budget--) { s->failed_pc=0x0c09cca4u; return 0; }
r[12]=read(ram,0x0c09cd2cu,4);
goto P_0c09cca6;
P_0c09cca6: /* original 03ed, guest PC 0x0c09cca6 */
if(!s->budget--) { s->failed_pc=0x0c09cca6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09cca8;
P_0c09cca8: /* original 6233, guest PC 0x0c09cca8 */
if(!s->budget--) { s->failed_pc=0x0c09cca8u; return 0; }
r[2]=r[3];
goto P_0c09ccaa;
P_0c09ccaa: /* original 4300, guest PC 0x0c09ccaa */
if(!s->budget--) { s->failed_pc=0x0c09ccaau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c09ccac;
P_0c09ccac: /* original 332c, guest PC 0x0c09ccac */
if(!s->budget--) { s->failed_pc=0x0c09ccacu; return 0; }
r[3]+=r[2];
goto P_0c09ccae;
P_0c09ccae: /* original 4308, guest PC 0x0c09ccae */
if(!s->budget--) { s->failed_pc=0x0c09ccaeu; return 0; }
r[3]<<=2;
goto P_0c09ccb0;
P_0c09ccb0: /* original 633f, guest PC 0x0c09ccb0 */
if(!s->budget--) { s->failed_pc=0x0c09ccb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c09ccb2;
P_0c09ccb2: /* original 33cc, guest PC 0x0c09ccb2 */
if(!s->budget--) { s->failed_pc=0x0c09ccb2u; return 0; }
r[3]+=r[12];
goto P_0c09ccb4;
P_0c09ccb4: /* original 5232, guest PC 0x0c09ccb4 */
if(!s->budget--) { s->failed_pc=0x0c09ccb4u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c09ccb6;
P_0c09ccb6: /* original 2228, guest PC 0x0c09ccb6 */
if(!s->budget--) { s->failed_pc=0x0c09ccb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09ccb8;
P_0c09ccb8: /* original 8909, guest PC 0x0c09ccb8 */
if(!s->budget--) { s->failed_pc=0x0c09ccb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ccce; }
goto P_0c09ccba;
P_0c09ccba: /* original 04ed, guest PC 0x0c09ccba */
if(!s->budget--) { s->failed_pc=0x0c09ccbau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ccbc;
P_0c09ccbc: /* original 6343, guest PC 0x0c09ccbc */
if(!s->budget--) { s->failed_pc=0x0c09ccbcu; return 0; }
r[3]=r[4];
goto P_0c09ccbe;
P_0c09ccbe: /* original 4400, guest PC 0x0c09ccbe */
if(!s->budget--) { s->failed_pc=0x0c09ccbeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09ccc0;
P_0c09ccc0: /* original 343c, guest PC 0x0c09ccc0 */
if(!s->budget--) { s->failed_pc=0x0c09ccc0u; return 0; }
r[4]+=r[3];
goto P_0c09ccc2;
P_0c09ccc2: /* original d31b, guest PC 0x0c09ccc2 */
if(!s->budget--) { s->failed_pc=0x0c09ccc2u; return 0; }
r[3]=read(ram,0x0c09cd30u,4);
goto P_0c09ccc4;
P_0c09ccc4: /* original 4408, guest PC 0x0c09ccc4 */
if(!s->budget--) { s->failed_pc=0x0c09ccc4u; return 0; }
r[4]<<=2;
goto P_0c09ccc6;
P_0c09ccc6: /* original 644f, guest PC 0x0c09ccc6 */
if(!s->budget--) { s->failed_pc=0x0c09ccc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09ccc8;
P_0c09ccc8: /* original 34cc, guest PC 0x0c09ccc8 */
if(!s->budget--) { s->failed_pc=0x0c09ccc8u; return 0; }
r[4]+=r[12];
goto P_0c09ccca;
P_0c09ccca: /* original 430b, guest PC 0x0c09ccca */
if(!s->budget--) { s->failed_pc=0x0c09cccau; return 0; }
target=r[3];
r[16]=0x0c09ccceu;
r[4]=read(ram,r[4]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ccceu) { target=s->pc; goto dispatch; }
goto P_0c09ccce;
P_0c09cccc: /* original 5442, guest PC 0x0c09cccc */
if(!s->budget--) { s->failed_pc=0x0c09ccccu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c09ccce;
P_0c09ccce: /* original 9024, guest PC 0x0c09ccce */
if(!s->budget--) { s->failed_pc=0x0c09ccceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd1au,2);
goto P_0c09ccd0;
P_0c09ccd0: /* original 04ed, guest PC 0x0c09ccd0 */
if(!s->budget--) { s->failed_pc=0x0c09ccd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ccd2;
P_0c09ccd2: /* original d016, guest PC 0x0c09ccd2 */
if(!s->budget--) { s->failed_pc=0x0c09ccd2u; return 0; }
r[0]=read(ram,0x0c09cd2cu,4);
goto P_0c09ccd4;
P_0c09ccd4: /* original 6343, guest PC 0x0c09ccd4 */
if(!s->budget--) { s->failed_pc=0x0c09ccd4u; return 0; }
r[3]=r[4];
goto P_0c09ccd6;
P_0c09ccd6: /* original 4400, guest PC 0x0c09ccd6 */
if(!s->budget--) { s->failed_pc=0x0c09ccd6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09ccd8;
P_0c09ccd8: /* original 343c, guest PC 0x0c09ccd8 */
if(!s->budget--) { s->failed_pc=0x0c09ccd8u; return 0; }
r[4]+=r[3];
goto P_0c09ccda;
P_0c09ccda: /* original 4408, guest PC 0x0c09ccda */
if(!s->budget--) { s->failed_pc=0x0c09ccdau; return 0; }
r[4]<<=2;
goto P_0c09ccdc;
P_0c09ccdc: /* original a065, guest PC 0x0c09ccdc */
if(!s->budget--) { s->failed_pc=0x0c09ccdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09cdaa;
P_0c09ccde: /* original 644f, guest PC 0x0c09ccde */
if(!s->budget--) { s->failed_pc=0x0c09ccdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09cce0;
P_0c09cce0: /* original 901c, guest PC 0x0c09cce0 */
if(!s->budget--) { s->failed_pc=0x0c09cce0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd1cu,2);
goto P_0c09cce2;
P_0c09cce2: /* original 04ee, guest PC 0x0c09cce2 */
if(!s->budget--) { s->failed_pc=0x0c09cce2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09cce4;
P_0c09cce4: /* original d013, guest PC 0x0c09cce4 */
if(!s->budget--) { s->failed_pc=0x0c09cce4u; return 0; }
r[0]=read(ram,0x0c09cd34u,4);
goto P_0c09cce6;
P_0c09cce6: /* original 4408, guest PC 0x0c09cce6 */
if(!s->budget--) { s->failed_pc=0x0c09cce6u; return 0; }
r[4]<<=2;
goto P_0c09cce8;
P_0c09cce8: /* original 4400, guest PC 0x0c09cce8 */
if(!s->budget--) { s->failed_pc=0x0c09cce8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09ccea;
P_0c09ccea: /* original 044e, guest PC 0x0c09ccea */
if(!s->budget--) { s->failed_pc=0x0c09cceau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09ccec;
P_0c09ccec: /* original 6340, guest PC 0x0c09ccec */
if(!s->budget--) { s->failed_pc=0x0c09ccecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c09ccee;
P_0c09ccee: /* original 8441, guest PC 0x0c09ccee */
if(!s->budget--) { s->failed_pc=0x0c09cceeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c09ccf0;
P_0c09ccf0: /* original 4318, guest PC 0x0c09ccf0 */
if(!s->budget--) { s->failed_pc=0x0c09ccf0u; return 0; }
r[3]<<=8;
goto P_0c09ccf2;
P_0c09ccf2: /* original 6433, guest PC 0x0c09ccf2 */
if(!s->budget--) { s->failed_pc=0x0c09ccf2u; return 0; }
r[4]=r[3];
goto P_0c09ccf4;
P_0c09ccf4: /* original 9313, guest PC 0x0c09ccf4 */
if(!s->budget--) { s->failed_pc=0x0c09ccf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd1eu,2);
goto P_0c09ccf6;
P_0c09ccf6: /* original 240b, guest PC 0x0c09ccf6 */
if(!s->budget--) { s->failed_pc=0x0c09ccf6u; return 0; }
r[4]|=r[0];
goto P_0c09ccf8;
P_0c09ccf8: /* original 3430, guest PC 0x0c09ccf8 */
if(!s->budget--) { s->failed_pc=0x0c09ccf8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09ccfa;
P_0c09ccfa: /* original 8b01, guest PC 0x0c09ccfa */
if(!s->budget--) { s->failed_pc=0x0c09ccfau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd00; }
goto P_0c09ccfc;
P_0c09ccfc: /* original a04d, guest PC 0x0c09ccfc */
if(!s->budget--) { s->failed_pc=0x0c09ccfcu; return 0; }
r[5]=r[12];
goto P_0c09cd9a;
P_0c09ccfe: /* original 65c3, guest PC 0x0c09ccfe */
if(!s->budget--) { s->failed_pc=0x0c09ccfeu; return 0; }
r[5]=r[12];
goto P_0c09cd00;
P_0c09cd00: /* original 920e, guest PC 0x0c09cd00 */
if(!s->budget--) { s->failed_pc=0x0c09cd00u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd20u,2);
goto P_0c09cd02;
P_0c09cd02: /* original 3420, guest PC 0x0c09cd02 */
if(!s->budget--) { s->failed_pc=0x0c09cd02u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c09cd04;
P_0c09cd04: /* original 8b01, guest PC 0x0c09cd04 */
if(!s->budget--) { s->failed_pc=0x0c09cd04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd0a; }
goto P_0c09cd06;
P_0c09cd06: /* original a048, guest PC 0x0c09cd06 */
if(!s->budget--) { s->failed_pc=0x0c09cd06u; return 0; }
r[5]=0x00000001u;
goto P_0c09cd9a;
P_0c09cd08: /* original e501, guest PC 0x0c09cd08 */
if(!s->budget--) { s->failed_pc=0x0c09cd08u; return 0; }
r[5]=0x00000001u;
goto P_0c09cd0a;
P_0c09cd0a: /* original 910a, guest PC 0x0c09cd0a */
if(!s->budget--) { s->failed_pc=0x0c09cd0au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd22u,2);
goto P_0c09cd0c;
P_0c09cd0c: /* original 3410, guest PC 0x0c09cd0c */
if(!s->budget--) { s->failed_pc=0x0c09cd0cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c09cd0e;
P_0c09cd0e: /* original 8b13, guest PC 0x0c09cd0e */
if(!s->budget--) { s->failed_pc=0x0c09cd0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd38; }
goto P_0c09cd10;
P_0c09cd10: /* original a043, guest PC 0x0c09cd10 */
if(!s->budget--) { s->failed_pc=0x0c09cd10u; return 0; }
r[5]=0x00000005u;
goto P_0c09cd9a;
P_0c09cd12: /* original e505, guest PC 0x0c09cd12 */
if(!s->budget--) { s->failed_pc=0x0c09cd12u; return 0; }
r[5]=0x00000005u;
return vf3_matrix_family(0x0c09cd14u,s,ram);
P_0c09cd38: /* original 9343, guest PC 0x0c09cd38 */
if(!s->budget--) { s->failed_pc=0x0c09cd38u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdc2u,2);
goto P_0c09cd3a;
P_0c09cd3a: /* original 3430, guest PC 0x0c09cd3a */
if(!s->budget--) { s->failed_pc=0x0c09cd3au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09cd3c;
P_0c09cd3c: /* original 8b01, guest PC 0x0c09cd3c */
if(!s->budget--) { s->failed_pc=0x0c09cd3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd42; }
goto P_0c09cd3e;
P_0c09cd3e: /* original a02c, guest PC 0x0c09cd3e */
if(!s->budget--) { s->failed_pc=0x0c09cd3eu; return 0; }
r[5]=r[10];
goto P_0c09cd9a;
P_0c09cd40: /* original 65a3, guest PC 0x0c09cd40 */
if(!s->budget--) { s->failed_pc=0x0c09cd40u; return 0; }
r[5]=r[10];
goto P_0c09cd42;
P_0c09cd42: /* original 923f, guest PC 0x0c09cd42 */
if(!s->budget--) { s->failed_pc=0x0c09cd42u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdc4u,2);
goto P_0c09cd44;
P_0c09cd44: /* original 3420, guest PC 0x0c09cd44 */
if(!s->budget--) { s->failed_pc=0x0c09cd44u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c09cd46;
P_0c09cd46: /* original 8b01, guest PC 0x0c09cd46 */
if(!s->budget--) { s->failed_pc=0x0c09cd46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd4c; }
goto P_0c09cd48;
P_0c09cd48: /* original a027, guest PC 0x0c09cd48 */
if(!s->budget--) { s->failed_pc=0x0c09cd48u; return 0; }
r[5]=r[6];
goto P_0c09cd9a;
P_0c09cd4a: /* original 6563, guest PC 0x0c09cd4a */
if(!s->budget--) { s->failed_pc=0x0c09cd4au; return 0; }
r[5]=r[6];
goto P_0c09cd4c;
P_0c09cd4c: /* original 913b, guest PC 0x0c09cd4c */
if(!s->budget--) { s->failed_pc=0x0c09cd4cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdc6u,2);
goto P_0c09cd4e;
P_0c09cd4e: /* original 3410, guest PC 0x0c09cd4e */
if(!s->budget--) { s->failed_pc=0x0c09cd4eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c09cd50;
P_0c09cd50: /* original 8b01, guest PC 0x0c09cd50 */
if(!s->budget--) { s->failed_pc=0x0c09cd50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd56; }
goto P_0c09cd52;
P_0c09cd52: /* original a022, guest PC 0x0c09cd52 */
if(!s->budget--) { s->failed_pc=0x0c09cd52u; return 0; }
r[5]=0x0000000au;
goto P_0c09cd9a;
P_0c09cd54: /* original e50a, guest PC 0x0c09cd54 */
if(!s->budget--) { s->failed_pc=0x0c09cd54u; return 0; }
r[5]=0x0000000au;
goto P_0c09cd56;
P_0c09cd56: /* original 9337, guest PC 0x0c09cd56 */
if(!s->budget--) { s->failed_pc=0x0c09cd56u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdc8u,2);
goto P_0c09cd58;
P_0c09cd58: /* original 3430, guest PC 0x0c09cd58 */
if(!s->budget--) { s->failed_pc=0x0c09cd58u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09cd5a;
P_0c09cd5a: /* original 8b01, guest PC 0x0c09cd5a */
if(!s->budget--) { s->failed_pc=0x0c09cd5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd60; }
goto P_0c09cd5c;
P_0c09cd5c: /* original a01d, guest PC 0x0c09cd5c */
if(!s->budget--) { s->failed_pc=0x0c09cd5cu; return 0; }
r[5]=0x00000006u;
goto P_0c09cd9a;
P_0c09cd5e: /* original e506, guest PC 0x0c09cd5e */
if(!s->budget--) { s->failed_pc=0x0c09cd5eu; return 0; }
r[5]=0x00000006u;
goto P_0c09cd60;
P_0c09cd60: /* original 9233, guest PC 0x0c09cd60 */
if(!s->budget--) { s->failed_pc=0x0c09cd60u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdcau,2);
goto P_0c09cd62;
P_0c09cd62: /* original 3420, guest PC 0x0c09cd62 */
if(!s->budget--) { s->failed_pc=0x0c09cd62u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c09cd64;
P_0c09cd64: /* original 8b01, guest PC 0x0c09cd64 */
if(!s->budget--) { s->failed_pc=0x0c09cd64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd6a; }
goto P_0c09cd66;
P_0c09cd66: /* original a018, guest PC 0x0c09cd66 */
if(!s->budget--) { s->failed_pc=0x0c09cd66u; return 0; }
r[5]=0x00000002u;
goto P_0c09cd9a;
P_0c09cd68: /* original e502, guest PC 0x0c09cd68 */
if(!s->budget--) { s->failed_pc=0x0c09cd68u; return 0; }
r[5]=0x00000002u;
goto P_0c09cd6a;
P_0c09cd6a: /* original 912f, guest PC 0x0c09cd6a */
if(!s->budget--) { s->failed_pc=0x0c09cd6au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdccu,2);
goto P_0c09cd6c;
P_0c09cd6c: /* original 3410, guest PC 0x0c09cd6c */
if(!s->budget--) { s->failed_pc=0x0c09cd6cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c09cd6e;
P_0c09cd6e: /* original 8b01, guest PC 0x0c09cd6e */
if(!s->budget--) { s->failed_pc=0x0c09cd6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd74; }
goto P_0c09cd70;
P_0c09cd70: /* original a013, guest PC 0x0c09cd70 */
if(!s->budget--) { s->failed_pc=0x0c09cd70u; return 0; }
r[5]=0x00000008u;
goto P_0c09cd9a;
P_0c09cd72: /* original e508, guest PC 0x0c09cd72 */
if(!s->budget--) { s->failed_pc=0x0c09cd72u; return 0; }
r[5]=0x00000008u;
goto P_0c09cd74;
P_0c09cd74: /* original 932b, guest PC 0x0c09cd74 */
if(!s->budget--) { s->failed_pc=0x0c09cd74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdceu,2);
goto P_0c09cd76;
P_0c09cd76: /* original 3430, guest PC 0x0c09cd76 */
if(!s->budget--) { s->failed_pc=0x0c09cd76u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09cd78;
P_0c09cd78: /* original 8b01, guest PC 0x0c09cd78 */
if(!s->budget--) { s->failed_pc=0x0c09cd78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd7e; }
goto P_0c09cd7a;
P_0c09cd7a: /* original a00e, guest PC 0x0c09cd7a */
if(!s->budget--) { s->failed_pc=0x0c09cd7au; return 0; }
r[5]=0x00000007u;
goto P_0c09cd9a;
P_0c09cd7c: /* original e507, guest PC 0x0c09cd7c */
if(!s->budget--) { s->failed_pc=0x0c09cd7cu; return 0; }
r[5]=0x00000007u;
goto P_0c09cd7e;
P_0c09cd7e: /* original 9227, guest PC 0x0c09cd7e */
if(!s->budget--) { s->failed_pc=0x0c09cd7eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd0u,2);
goto P_0c09cd80;
P_0c09cd80: /* original 3420, guest PC 0x0c09cd80 */
if(!s->budget--) { s->failed_pc=0x0c09cd80u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c09cd82;
P_0c09cd82: /* original 8b01, guest PC 0x0c09cd82 */
if(!s->budget--) { s->failed_pc=0x0c09cd82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd88; }
goto P_0c09cd84;
P_0c09cd84: /* original a009, guest PC 0x0c09cd84 */
if(!s->budget--) { s->failed_pc=0x0c09cd84u; return 0; }
r[5]=0x0000000bu;
goto P_0c09cd9a;
P_0c09cd86: /* original e50b, guest PC 0x0c09cd86 */
if(!s->budget--) { s->failed_pc=0x0c09cd86u; return 0; }
r[5]=0x0000000bu;
goto P_0c09cd88;
P_0c09cd88: /* original 9123, guest PC 0x0c09cd88 */
if(!s->budget--) { s->failed_pc=0x0c09cd88u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd2u,2);
goto P_0c09cd8a;
P_0c09cd8a: /* original 3410, guest PC 0x0c09cd8a */
if(!s->budget--) { s->failed_pc=0x0c09cd8au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c09cd8c;
P_0c09cd8c: /* original 8b01, guest PC 0x0c09cd8c */
if(!s->budget--) { s->failed_pc=0x0c09cd8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd92; }
goto P_0c09cd8e;
P_0c09cd8e: /* original a004, guest PC 0x0c09cd8e */
if(!s->budget--) { s->failed_pc=0x0c09cd8eu; return 0; }
r[5]=0x0000000cu;
goto P_0c09cd9a;
P_0c09cd90: /* original e50c, guest PC 0x0c09cd90 */
if(!s->budget--) { s->failed_pc=0x0c09cd90u; return 0; }
r[5]=0x0000000cu;
goto P_0c09cd92;
P_0c09cd92: /* original 931f, guest PC 0x0c09cd92 */
if(!s->budget--) { s->failed_pc=0x0c09cd92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd4u,2);
goto P_0c09cd94;
P_0c09cd94: /* original 3430, guest PC 0x0c09cd94 */
if(!s->budget--) { s->failed_pc=0x0c09cd94u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09cd96;
P_0c09cd96: /* original 8b34, guest PC 0x0c09cd96 */
if(!s->budget--) { s->failed_pc=0x0c09cd96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ce02; }
goto P_0c09cd98;
P_0c09cd98: /* original e51f, guest PC 0x0c09cd98 */
if(!s->budget--) { s->failed_pc=0x0c09cd98u; return 0; }
r[5]=0x0000001fu;
goto P_0c09cd9a;
P_0c09cd9a: /* original d310, guest PC 0x0c09cd9a */
if(!s->budget--) { s->failed_pc=0x0c09cd9au; return 0; }
r[3]=read(ram,0x0c09cddcu,4);
goto P_0c09cd9c;
P_0c09cd9c: /* original 430b, guest PC 0x0c09cd9c */
if(!s->budget--) { s->failed_pc=0x0c09cd9cu; return 0; }
target=r[3];
r[16]=0x0c09cda0u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cda0u) { target=s->pc; goto dispatch; }
goto P_0c09cda0;
P_0c09cd9e: /* original e400, guest PC 0x0c09cd9e */
if(!s->budget--) { s->failed_pc=0x0c09cd9eu; return 0; }
r[4]=0x00000000u;
goto P_0c09cda0;
P_0c09cda0: /* original 9019, guest PC 0x0c09cda0 */
if(!s->budget--) { s->failed_pc=0x0c09cda0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd6u,2);
goto P_0c09cda2;
P_0c09cda2: /* original 04ee, guest PC 0x0c09cda2 */
if(!s->budget--) { s->failed_pc=0x0c09cda2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09cda4;
P_0c09cda4: /* original d00e, guest PC 0x0c09cda4 */
if(!s->budget--) { s->failed_pc=0x0c09cda4u; return 0; }
r[0]=read(ram,0x0c09cde0u,4);
goto P_0c09cda6;
P_0c09cda6: /* original 4408, guest PC 0x0c09cda6 */
if(!s->budget--) { s->failed_pc=0x0c09cda6u; return 0; }
r[4]<<=2;
goto P_0c09cda8;
P_0c09cda8: /* original 4400, guest PC 0x0c09cda8 */
if(!s->budget--) { s->failed_pc=0x0c09cda8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09cdaa;
P_0c09cdaa: /* original a028, guest PC 0x0c09cdaa */
if(!s->budget--) { s->failed_pc=0x0c09cdaau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09cdfe;
P_0c09cdac: /* original 044e, guest PC 0x0c09cdac */
if(!s->budget--) { s->failed_pc=0x0c09cdacu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09cdae;
P_0c09cdae: /* original 9013, guest PC 0x0c09cdae */
if(!s->budget--) { s->failed_pc=0x0c09cdaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd8u,2);
goto P_0c09cdb0;
P_0c09cdb0: /* original d30d, guest PC 0x0c09cdb0 */
if(!s->budget--) { s->failed_pc=0x0c09cdb0u; return 0; }
r[3]=read(ram,0x0c09cde8u,4);
goto P_0c09cdb2;
P_0c09cdb2: /* original 04ee, guest PC 0x0c09cdb2 */
if(!s->budget--) { s->failed_pc=0x0c09cdb2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09cdb4;
P_0c09cdb4: /* original d00b, guest PC 0x0c09cdb4 */
if(!s->budget--) { s->failed_pc=0x0c09cdb4u; return 0; }
r[0]=read(ram,0x0c09cde4u,4);
goto P_0c09cdb6;
P_0c09cdb6: /* original 4408, guest PC 0x0c09cdb6 */
if(!s->budget--) { s->failed_pc=0x0c09cdb6u; return 0; }
r[4]<<=2;
goto P_0c09cdb8;
P_0c09cdb8: /* original 4400, guest PC 0x0c09cdb8 */
if(!s->budget--) { s->failed_pc=0x0c09cdb8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09cdba;
P_0c09cdba: /* original 430b, guest PC 0x0c09cdba */
if(!s->budget--) { s->failed_pc=0x0c09cdbau; return 0; }
target=r[3];
r[16]=0x0c09cdbeu;
r[4]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cdbeu) { target=s->pc; goto dispatch; }
goto P_0c09cdbe;
P_0c09cdbc: /* original 044e, guest PC 0x0c09cdbc */
if(!s->budget--) { s->failed_pc=0x0c09cdbcu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09cdbe;
P_0c09cdbe: /* original a020, guest PC 0x0c09cdbe */
if(!s->budget--) { s->failed_pc=0x0c09cdbeu; return 0; }
goto P_0c09ce02;
P_0c09cdc0: /* original 0009, guest PC 0x0c09cdc0 */
if(!s->budget--) { s->failed_pc=0x0c09cdc0u; return 0; }
return vf3_matrix_family(0x0c09cdc2u,s,ram);
P_0c09cdec: /* original e009, guest PC 0x0c09cdec */
if(!s->budget--) { s->failed_pc=0x0c09cdecu; return 0; }
r[0]=0x00000009u;
goto P_0c09cdee;
P_0c09cdee: /* original 80eb, guest PC 0x0c09cdee */
if(!s->budget--) { s->failed_pc=0x0c09cdeeu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09cdf0;
P_0c09cdf0: /* original e010, guest PC 0x0c09cdf0 */
if(!s->budget--) { s->failed_pc=0x0c09cdf0u; return 0; }
r[0]=0x00000010u;
goto P_0c09cdf2;
P_0c09cdf2: /* original e376, guest PC 0x0c09cdf2 */
if(!s->budget--) { s->failed_pc=0x0c09cdf2u; return 0; }
r[3]=0x00000076u;
goto P_0c09cdf4;
P_0c09cdf4: /* original e500, guest PC 0x0c09cdf4 */
if(!s->budget--) { s->failed_pc=0x0c09cdf4u; return 0; }
r[5]=0x00000000u;
goto P_0c09cdf6;
P_0c09cdf6: /* original 0e34, guest PC 0x0c09cdf6 */
if(!s->budget--) { s->failed_pc=0x0c09cdf6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09cdf8;
P_0c09cdf8: /* original 490b, guest PC 0x0c09cdf8 */
if(!s->budget--) { s->failed_pc=0x0c09cdf8u; return 0; }
target=r[9];
r[16]=0x0c09cdfcu;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cdfcu) { target=s->pc; goto dispatch; }
goto P_0c09cdfc;
P_0c09cdfa: /* original 6483, guest PC 0x0c09cdfa */
if(!s->budget--) { s->failed_pc=0x0c09cdfau; return 0; }
r[4]=r[8];
goto P_0c09cdfc;
P_0c09cdfc: /* original 943f, guest PC 0x0c09cdfc */
if(!s->budget--) { s->failed_pc=0x0c09cdfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ce7eu,2);
goto P_0c09cdfe;
P_0c09cdfe: /* original 4b0b, guest PC 0x0c09cdfe */
if(!s->budget--) { s->failed_pc=0x0c09cdfeu; return 0; }
target=r[11];
r[16]=0x0c09ce02u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce02u) { target=s->pc; goto dispatch; }
goto P_0c09ce02;
P_0c09ce00: /* original 0009, guest PC 0x0c09ce00 */
if(!s->budget--) { s->failed_pc=0x0c09ce00u; return 0; }
goto P_0c09ce02;
P_0c09ce02: /* original e208, guest PC 0x0c09ce02 */
if(!s->budget--) { s->failed_pc=0x0c09ce02u; return 0; }
r[2]=0x00000008u;
goto P_0c09ce04;
P_0c09ce04: /* original 22d8, guest PC 0x0c09ce04 */
if(!s->budget--) { s->failed_pc=0x0c09ce04u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09ce06;
P_0c09ce06: /* original 890a, guest PC 0x0c09ce06 */
if(!s->budget--) { s->failed_pc=0x0c09ce06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ce1e; }
goto P_0c09ce08;
P_0c09ce08: /* original e001, guest PC 0x0c09ce08 */
if(!s->budget--) { s->failed_pc=0x0c09ce08u; return 0; }
r[0]=0x00000001u;
goto P_0c09ce0a;
P_0c09ce0a: /* original 80eb, guest PC 0x0c09ce0a */
if(!s->budget--) { s->failed_pc=0x0c09ce0au; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09ce0c;
P_0c09ce0c: /* original e010, guest PC 0x0c09ce0c */
if(!s->budget--) { s->failed_pc=0x0c09ce0cu; return 0; }
r[0]=0x00000010u;
goto P_0c09ce0e;
P_0c09ce0e: /* original e372, guest PC 0x0c09ce0e */
if(!s->budget--) { s->failed_pc=0x0c09ce0eu; return 0; }
r[3]=0x00000072u;
goto P_0c09ce10;
P_0c09ce10: /* original e500, guest PC 0x0c09ce10 */
if(!s->budget--) { s->failed_pc=0x0c09ce10u; return 0; }
r[5]=0x00000000u;
goto P_0c09ce12;
P_0c09ce12: /* original 0e34, guest PC 0x0c09ce12 */
if(!s->budget--) { s->failed_pc=0x0c09ce12u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09ce14;
P_0c09ce14: /* original 490b, guest PC 0x0c09ce14 */
if(!s->budget--) { s->failed_pc=0x0c09ce14u; return 0; }
target=r[9];
r[16]=0x0c09ce18u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce18u) { target=s->pc; goto dispatch; }
goto P_0c09ce18;
P_0c09ce16: /* original 6483, guest PC 0x0c09ce16 */
if(!s->budget--) { s->failed_pc=0x0c09ce16u; return 0; }
r[4]=r[8];
goto P_0c09ce18;
P_0c09ce18: /* original 9431, guest PC 0x0c09ce18 */
if(!s->budget--) { s->failed_pc=0x0c09ce18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ce7eu,2);
goto P_0c09ce1a;
P_0c09ce1a: /* original 4b0b, guest PC 0x0c09ce1a */
if(!s->budget--) { s->failed_pc=0x0c09ce1au; return 0; }
target=r[11];
r[16]=0x0c09ce1eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce1eu) { target=s->pc; goto dispatch; }
goto P_0c09ce1e;
P_0c09ce1c: /* original 0009, guest PC 0x0c09ce1c */
if(!s->budget--) { s->failed_pc=0x0c09ce1cu; return 0; }
goto P_0c09ce1e;
P_0c09ce1e: /* original e302, guest PC 0x0c09ce1e */
if(!s->budget--) { s->failed_pc=0x0c09ce1eu; return 0; }
r[3]=0x00000002u;
goto P_0c09ce20;
P_0c09ce20: /* original 2d38, guest PC 0x0c09ce20 */
if(!s->budget--) { s->failed_pc=0x0c09ce20u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c09ce22;
P_0c09ce22: /* original 8909, guest PC 0x0c09ce22 */
if(!s->budget--) { s->failed_pc=0x0c09ce22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ce38; }
goto P_0c09ce24;
P_0c09ce24: /* original e009, guest PC 0x0c09ce24 */
if(!s->budget--) { s->failed_pc=0x0c09ce24u; return 0; }
r[0]=0x00000009u;
goto P_0c09ce26;
P_0c09ce26: /* original 80eb, guest PC 0x0c09ce26 */
if(!s->budget--) { s->failed_pc=0x0c09ce26u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09ce28;
P_0c09ce28: /* original e010, guest PC 0x0c09ce28 */
if(!s->budget--) { s->failed_pc=0x0c09ce28u; return 0; }
r[0]=0x00000010u;
goto P_0c09ce2a;
P_0c09ce2a: /* original 9429, guest PC 0x0c09ce2a */
if(!s->budget--) { s->failed_pc=0x0c09ce2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ce80u,2);
goto P_0c09ce2c;
P_0c09ce2c: /* original e276, guest PC 0x0c09ce2c */
if(!s->budget--) { s->failed_pc=0x0c09ce2cu; return 0; }
r[2]=0x00000076u;
goto P_0c09ce2e;
P_0c09ce2e: /* original 4b0b, guest PC 0x0c09ce2e */
if(!s->budget--) { s->failed_pc=0x0c09ce2eu; return 0; }
target=r[11];
r[16]=0x0c09ce32u;
write(ram,r[14]+r[0],r[2],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce32u) { target=s->pc; goto dispatch; }
goto P_0c09ce32;
P_0c09ce30: /* original 0e24, guest PC 0x0c09ce30 */
if(!s->budget--) { s->failed_pc=0x0c09ce30u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09ce32;
P_0c09ce32: /* original e500, guest PC 0x0c09ce32 */
if(!s->budget--) { s->failed_pc=0x0c09ce32u; return 0; }
r[5]=0x00000000u;
goto P_0c09ce34;
P_0c09ce34: /* original 490b, guest PC 0x0c09ce34 */
if(!s->budget--) { s->failed_pc=0x0c09ce34u; return 0; }
target=r[9];
r[16]=0x0c09ce38u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce38u) { target=s->pc; goto dispatch; }
goto P_0c09ce38;
P_0c09ce36: /* original 6483, guest PC 0x0c09ce36 */
if(!s->budget--) { s->failed_pc=0x0c09ce36u; return 0; }
r[4]=r[8];
goto P_0c09ce38;
P_0c09ce38: /* original 4f26, guest PC 0x0c09ce38 */
if(!s->budget--) { s->failed_pc=0x0c09ce38u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ce3a;
P_0c09ce3a: /* original 68f6, guest PC 0x0c09ce3a */
if(!s->budget--) { s->failed_pc=0x0c09ce3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09ce3c;
P_0c09ce3c: /* original 69f6, guest PC 0x0c09ce3c */
if(!s->budget--) { s->failed_pc=0x0c09ce3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09ce3e;
P_0c09ce3e: /* original 6af6, guest PC 0x0c09ce3e */
if(!s->budget--) { s->failed_pc=0x0c09ce3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ce40;
P_0c09ce40: /* original 6bf6, guest PC 0x0c09ce40 */
if(!s->budget--) { s->failed_pc=0x0c09ce40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ce42;
P_0c09ce42: /* original 6cf6, guest PC 0x0c09ce42 */
if(!s->budget--) { s->failed_pc=0x0c09ce42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ce44;
P_0c09ce44: /* original 6df6, guest PC 0x0c09ce44 */
if(!s->budget--) { s->failed_pc=0x0c09ce44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ce46;
P_0c09ce46: /* original 000b, guest PC 0x0c09ce46 */
if(!s->budget--) { s->failed_pc=0x0c09ce46u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09ce48: /* original 6ef6, guest PC 0x0c09ce48 */
if(!s->budget--) { s->failed_pc=0x0c09ce48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09ce4au,s,ram);
P_0c09ce4c: /* original 4f22, guest PC 0x0c09ce4c */
if(!s->budget--) { s->failed_pc=0x0c09ce4cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ce4e;
P_0c09ce4e: /* original d30e, guest PC 0x0c09ce4e */
if(!s->budget--) { s->failed_pc=0x0c09ce4eu; return 0; }
r[3]=read(ram,0x0c09ce88u,4);
goto P_0c09ce50;
P_0c09ce50: /* original de0c, guest PC 0x0c09ce50 */
if(!s->budget--) { s->failed_pc=0x0c09ce50u; return 0; }
r[14]=read(ram,0x0c09ce84u,4);
goto P_0c09ce52;
P_0c09ce52: /* original 430b, guest PC 0x0c09ce52 */
if(!s->budget--) { s->failed_pc=0x0c09ce52u; return 0; }
target=r[3];
r[16]=0x0c09ce56u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce56u) { target=s->pc; goto dispatch; }
goto P_0c09ce56;
P_0c09ce54: /* original 0009, guest PC 0x0c09ce54 */
if(!s->budget--) { s->failed_pc=0x0c09ce54u; return 0; }
goto P_0c09ce56;
P_0c09ce56: /* original e400, guest PC 0x0c09ce56 */
if(!s->budget--) { s->failed_pc=0x0c09ce56u; return 0; }
r[4]=0x00000000u;
goto P_0c09ce58;
P_0c09ce58: /* original e07d, guest PC 0x0c09ce58 */
if(!s->budget--) { s->failed_pc=0x0c09ce58u; return 0; }
r[0]=0x0000007du;
goto P_0c09ce5a;
P_0c09ce5a: /* original 4f26, guest PC 0x0c09ce5a */
if(!s->budget--) { s->failed_pc=0x0c09ce5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ce5c;
P_0c09ce5c: /* original e378, guest PC 0x0c09ce5c */
if(!s->budget--) { s->failed_pc=0x0c09ce5cu; return 0; }
r[3]=0x00000078u;
goto P_0c09ce5e;
P_0c09ce5e: /* original e240, guest PC 0x0c09ce5e */
if(!s->budget--) { s->failed_pc=0x0c09ce5eu; return 0; }
r[2]=0x00000040u;
goto P_0c09ce60;
P_0c09ce60: /* original 1e23, guest PC 0x0c09ce60 */
if(!s->budget--) { s->failed_pc=0x0c09ce60u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09ce62;
P_0c09ce62: /* original 1e46, guest PC 0x0c09ce62 */
if(!s->budget--) { s->failed_pc=0x0c09ce62u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c09ce64;
P_0c09ce64: /* original 0e44, guest PC 0x0c09ce64 */
if(!s->budget--) { s->failed_pc=0x0c09ce64u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c09ce66;
P_0c09ce66: /* original 1e45, guest PC 0x0c09ce66 */
if(!s->budget--) { s->failed_pc=0x0c09ce66u; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c09ce68;
P_0c09ce68: /* original 900b, guest PC 0x0c09ce68 */
if(!s->budget--) { s->failed_pc=0x0c09ce68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ce82u,2);
goto P_0c09ce6a;
P_0c09ce6a: /* original 0e46, guest PC 0x0c09ce6a */
if(!s->budget--) { s->failed_pc=0x0c09ce6au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09ce6c;
P_0c09ce6c: /* original 70fc, guest PC 0x0c09ce6c */
if(!s->budget--) { s->failed_pc=0x0c09ce6cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09ce6e;
P_0c09ce6e: /* original 0e46, guest PC 0x0c09ce6e */
if(!s->budget--) { s->failed_pc=0x0c09ce6eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09ce70;
P_0c09ce70: /* original 84eb, guest PC 0x0c09ce70 */
if(!s->budget--) { s->failed_pc=0x0c09ce70u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09ce72;
P_0c09ce72: /* original 7001, guest PC 0x0c09ce72 */
if(!s->budget--) { s->failed_pc=0x0c09ce72u; return 0; }
r[0]+=0x00000001u;
goto P_0c09ce74;
P_0c09ce74: /* original 80eb, guest PC 0x0c09ce74 */
if(!s->budget--) { s->failed_pc=0x0c09ce74u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09ce76;
P_0c09ce76: /* original e010, guest PC 0x0c09ce76 */
if(!s->budget--) { s->failed_pc=0x0c09ce76u; return 0; }
r[0]=0x00000010u;
goto P_0c09ce78;
P_0c09ce78: /* original 0e34, guest PC 0x0c09ce78 */
if(!s->budget--) { s->failed_pc=0x0c09ce78u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09ce7a;
P_0c09ce7a: /* original ae27, guest PC 0x0c09ce7a */
if(!s->budget--) { s->failed_pc=0x0c09ce7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09cacc;
P_0c09ce7c: /* original 6ef6, guest PC 0x0c09ce7c */
if(!s->budget--) { s->failed_pc=0x0c09ce7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09ce7eu,s,ram);
P_0c09cf60: /* original 4f22, guest PC 0x0c09cf60 */
if(!s->budget--) { s->failed_pc=0x0c09cf60u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09cf62;
P_0c09cf62: /* original d310, guest PC 0x0c09cf62 */
if(!s->budget--) { s->failed_pc=0x0c09cf62u; return 0; }
r[3]=read(ram,0x0c09cfa4u,4);
goto P_0c09cf64;
P_0c09cf64: /* original de0e, guest PC 0x0c09cf64 */
if(!s->budget--) { s->failed_pc=0x0c09cf64u; return 0; }
r[14]=read(ram,0x0c09cfa0u,4);
goto P_0c09cf66;
P_0c09cf66: /* original 430b, guest PC 0x0c09cf66 */
if(!s->budget--) { s->failed_pc=0x0c09cf66u; return 0; }
target=r[3];
r[16]=0x0c09cf6au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cf6au) { target=s->pc; goto dispatch; }
goto P_0c09cf6a;
P_0c09cf68: /* original 0009, guest PC 0x0c09cf68 */
if(!s->budget--) { s->failed_pc=0x0c09cf68u; return 0; }
goto P_0c09cf6a;
P_0c09cf6a: /* original e400, guest PC 0x0c09cf6a */
if(!s->budget--) { s->failed_pc=0x0c09cf6au; return 0; }
r[4]=0x00000000u;
goto P_0c09cf6c;
P_0c09cf6c: /* original e07d, guest PC 0x0c09cf6c */
if(!s->budget--) { s->failed_pc=0x0c09cf6cu; return 0; }
r[0]=0x0000007du;
goto P_0c09cf6e;
P_0c09cf6e: /* original 4f26, guest PC 0x0c09cf6e */
if(!s->budget--) { s->failed_pc=0x0c09cf6eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09cf70;
P_0c09cf70: /* original e378, guest PC 0x0c09cf70 */
if(!s->budget--) { s->failed_pc=0x0c09cf70u; return 0; }
r[3]=0x00000078u;
goto P_0c09cf72;
P_0c09cf72: /* original e240, guest PC 0x0c09cf72 */
if(!s->budget--) { s->failed_pc=0x0c09cf72u; return 0; }
r[2]=0x00000040u;
goto P_0c09cf74;
P_0c09cf74: /* original 1e23, guest PC 0x0c09cf74 */
if(!s->budget--) { s->failed_pc=0x0c09cf74u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09cf76;
P_0c09cf76: /* original 1e46, guest PC 0x0c09cf76 */
if(!s->budget--) { s->failed_pc=0x0c09cf76u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c09cf78;
P_0c09cf78: /* original 0e44, guest PC 0x0c09cf78 */
if(!s->budget--) { s->failed_pc=0x0c09cf78u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c09cf7a;
P_0c09cf7a: /* original 1e45, guest PC 0x0c09cf7a */
if(!s->budget--) { s->failed_pc=0x0c09cf7au; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c09cf7c;
P_0c09cf7c: /* original 900f, guest PC 0x0c09cf7c */
if(!s->budget--) { s->failed_pc=0x0c09cf7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf9eu,2);
goto P_0c09cf7e;
P_0c09cf7e: /* original 0e46, guest PC 0x0c09cf7e */
if(!s->budget--) { s->failed_pc=0x0c09cf7eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cf80;
P_0c09cf80: /* original 70fc, guest PC 0x0c09cf80 */
if(!s->budget--) { s->failed_pc=0x0c09cf80u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09cf82;
P_0c09cf82: /* original 0e46, guest PC 0x0c09cf82 */
if(!s->budget--) { s->failed_pc=0x0c09cf82u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cf84;
P_0c09cf84: /* original 84eb, guest PC 0x0c09cf84 */
if(!s->budget--) { s->failed_pc=0x0c09cf84u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09cf86;
P_0c09cf86: /* original 7001, guest PC 0x0c09cf86 */
if(!s->budget--) { s->failed_pc=0x0c09cf86u; return 0; }
r[0]+=0x00000001u;
goto P_0c09cf88;
P_0c09cf88: /* original 80eb, guest PC 0x0c09cf88 */
if(!s->budget--) { s->failed_pc=0x0c09cf88u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09cf8a;
P_0c09cf8a: /* original e010, guest PC 0x0c09cf8a */
if(!s->budget--) { s->failed_pc=0x0c09cf8au; return 0; }
r[0]=0x00000010u;
goto P_0c09cf8c;
P_0c09cf8c: /* original 0e34, guest PC 0x0c09cf8c */
if(!s->budget--) { s->failed_pc=0x0c09cf8cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09cf8e;
P_0c09cf8e: /* original ad9d, guest PC 0x0c09cf8e */
if(!s->budget--) { s->failed_pc=0x0c09cf8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09cacc;
P_0c09cf90: /* original 6ef6, guest PC 0x0c09cf90 */
if(!s->budget--) { s->failed_pc=0x0c09cf90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09cf92u,s,ram);
P_0c0a9452: /* original 4f22, guest PC 0x0c0a9452 */
if(!s->budget--) { s->failed_pc=0x0c0a9452u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9454;
P_0c0a9454: /* original 0544, guest PC 0x0c0a9454 */
if(!s->budget--) { s->failed_pc=0x0c0a9454u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c0a9456;
P_0c0a9456: /* original 0644, guest PC 0x0c0a9456 */
if(!s->budget--) { s->failed_pc=0x0c0a9456u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0a9458;
P_0c0a9458: /* original d31b, guest PC 0x0c0a9458 */
if(!s->budget--) { s->failed_pc=0x0c0a9458u; return 0; }
r[3]=read(ram,0x0c0a94c8u,4);
goto P_0c0a945a;
P_0c0a945a: /* original 6530, guest PC 0x0c0a945a */
if(!s->budget--) { s->failed_pc=0x0c0a945au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c0a945c;
P_0c0a945c: /* original 605e, guest PC 0x0c0a945c */
if(!s->budget--) { s->failed_pc=0x0c0a945cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0a945e;
P_0c0a945e: /* original 8802, guest PC 0x0c0a945e */
if(!s->budget--) { s->failed_pc=0x0c0a945eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a9460;
P_0c0a9460: /* original 8b1e, guest PC 0x0c0a9460 */
if(!s->budget--) { s->failed_pc=0x0c0a9460u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a94a0; }
goto P_0c0a9462;
P_0c0a9462: /* original e061, guest PC 0x0c0a9462 */
if(!s->budget--) { s->failed_pc=0x0c0a9462u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9464;
P_0c0a9464: /* original 05ec, guest PC 0x0c0a9464 */
if(!s->budget--) { s->failed_pc=0x0c0a9464u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a9466;
P_0c0a9466: /* original d019, guest PC 0x0c0a9466 */
if(!s->budget--) { s->failed_pc=0x0c0a9466u; return 0; }
r[0]=read(ram,0x0c0a94ccu,4);
goto P_0c0a9468;
P_0c0a9468: /* original 4508, guest PC 0x0c0a9468 */
if(!s->budget--) { s->failed_pc=0x0c0a9468u; return 0; }
r[5]<<=2;
goto P_0c0a946a;
P_0c0a946a: /* original 4509, guest PC 0x0c0a946a */
if(!s->budget--) { s->failed_pc=0x0c0a946au; return 0; }
r[5]>>=2;
goto P_0c0a946c;
P_0c0a946c: /* original 4508, guest PC 0x0c0a946c */
if(!s->budget--) { s->failed_pc=0x0c0a946cu; return 0; }
r[5]<<=2;
goto P_0c0a946e;
P_0c0a946e: /* original 055e, guest PC 0x0c0a946e */
if(!s->budget--) { s->failed_pc=0x0c0a946eu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0a9470;
P_0c0a9470: /* original e03c, guest PC 0x0c0a9470 */
if(!s->budget--) { s->failed_pc=0x0c0a9470u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9472;
P_0c0a9472: /* original 0e55, guest PC 0x0c0a9472 */
if(!s->budget--) { s->failed_pc=0x0c0a9472u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0a9474;
P_0c0a9474: /* original e03e, guest PC 0x0c0a9474 */
if(!s->budget--) { s->failed_pc=0x0c0a9474u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9476;
P_0c0a9476: /* original 1e5d, guest PC 0x0c0a9476 */
if(!s->budget--) { s->failed_pc=0x0c0a9476u; return 0; }
write(ram,r[14]+52,r[5],4);
goto P_0c0a9478;
P_0c0a9478: /* original 0e45, guest PC 0x0c0a9478 */
if(!s->budget--) { s->failed_pc=0x0c0a9478u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a947a;
P_0c0a947a: /* original e010, guest PC 0x0c0a947a */
if(!s->budget--) { s->failed_pc=0x0c0a947au; return 0; }
r[0]=0x00000010u;
goto P_0c0a947c;
P_0c0a947c: /* original f4e6, guest PC 0x0c0a947c */
if(!s->budget--) { s->failed_pc=0x0c0a947cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a947e;
P_0c0a947e: /* original e018, guest PC 0x0c0a947e */
if(!s->budget--) { s->failed_pc=0x0c0a947eu; return 0; }
r[0]=0x00000018u;
goto P_0c0a9480;
P_0c0a9480: /* original d30f, guest PC 0x0c0a9480 */
if(!s->budget--) { s->failed_pc=0x0c0a9480u; return 0; }
r[3]=read(ram,0x0c0a94c0u,4);
goto P_0c0a9482;
P_0c0a9482: /* original f5e6, guest PC 0x0c0a9482 */
if(!s->budget--) { s->failed_pc=0x0c0a9482u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a9484;
P_0c0a9484: /* original 430b, guest PC 0x0c0a9484 */
if(!s->budget--) { s->failed_pc=0x0c0a9484u; return 0; }
target=r[3];
r[16]=0x0c0a9488u;
fr[5]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9488u) { target=s->pc; goto dispatch; }
goto P_0c0a9488;
P_0c0a9486: /* original f54d, guest PC 0x0c0a9486 */
if(!s->budget--) { s->failed_pc=0x0c0a9486u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0a9488;
P_0c0a9488: /* original e024, guest PC 0x0c0a9488 */
if(!s->budget--) { s->failed_pc=0x0c0a9488u; return 0; }
r[0]=0x00000024u;
goto P_0c0a948a;
P_0c0a948a: /* original f48d, guest PC 0x0c0a948a */
if(!s->budget--) { s->failed_pc=0x0c0a948au; return 0; }
fr[4]=0;
goto P_0c0a948c;
P_0c0a948c: /* original f50c, guest PC 0x0c0a948c */
if(!s->budget--) { s->failed_pc=0x0c0a948cu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0a948e;
P_0c0a948e: /* original fe47, guest PC 0x0c0a948e */
if(!s->budget--) { s->failed_pc=0x0c0a948eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9490;
P_0c0a9490: /* original e028, guest PC 0x0c0a9490 */
if(!s->budget--) { s->failed_pc=0x0c0a9490u; return 0; }
r[0]=0x00000028u;
goto P_0c0a9492;
P_0c0a9492: /* original fe47, guest PC 0x0c0a9492 */
if(!s->budget--) { s->failed_pc=0x0c0a9492u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9494;
P_0c0a9494: /* original e02c, guest PC 0x0c0a9494 */
if(!s->budget--) { s->failed_pc=0x0c0a9494u; return 0; }
r[0]=0x0000002cu;
goto P_0c0a9496;
P_0c0a9496: /* original fe47, guest PC 0x0c0a9496 */
if(!s->budget--) { s->failed_pc=0x0c0a9496u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9498;
P_0c0a9498: /* original e014, guest PC 0x0c0a9498 */
if(!s->budget--) { s->failed_pc=0x0c0a9498u; return 0; }
r[0]=0x00000014u;
goto P_0c0a949a;
P_0c0a949a: /* original fe57, guest PC 0x0c0a949a */
if(!s->budget--) { s->failed_pc=0x0c0a949au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a949c;
P_0c0a949c: /* original 9006, guest PC 0x0c0a949c */
if(!s->budget--) { s->failed_pc=0x0c0a949cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94acu,2);
goto P_0c0a949e;
P_0c0a949e: /* original fe57, guest PC 0x0c0a949e */
if(!s->budget--) { s->failed_pc=0x0c0a949eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a94a0;
P_0c0a94a0: /* original 4f26, guest PC 0x0c0a94a0 */
if(!s->budget--) { s->failed_pc=0x0c0a94a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a94a2;
P_0c0a94a2: /* original 000b, guest PC 0x0c0a94a2 */
if(!s->budget--) { s->failed_pc=0x0c0a94a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a94a4: /* original 6ef6, guest PC 0x0c0a94a4 */
if(!s->budget--) { s->failed_pc=0x0c0a94a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a94a6u,s,ram);
P_0c0c2c88: /* original 4f22, guest PC 0x0c0c2c88 */
if(!s->budget--) { s->failed_pc=0x0c0c2c88u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2c8a;
P_0c0c2c8a: /* original 0456, guest PC 0x0c0c2c8a */
if(!s->budget--) { s->failed_pc=0x0c0c2c8au; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c2c8c;
P_0c0c2c8c: /* original c741, guest PC 0x0c0c2c8c */
if(!s->budget--) { s->failed_pc=0x0c0c2c8cu; return 0; }
r[0]=0x0c0c2d94u;
goto P_0c0c2c8e;
P_0c0c2c8e: /* original ff08, guest PC 0x0c0c2c8e */
if(!s->budget--) { s->failed_pc=0x0c0c2c8eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c2c90;
P_0c0c2c90: /* original c741, guest PC 0x0c0c2c90 */
if(!s->budget--) { s->failed_pc=0x0c0c2c90u; return 0; }
r[0]=0x0c0c2d98u;
goto P_0c0c2c92;
P_0c0c2c92: /* original da42, guest PC 0x0c0c2c92 */
if(!s->budget--) { s->failed_pc=0x0c0c2c92u; return 0; }
r[10]=read(ram,0x0c0c2d9cu,4);
goto P_0c0c2c94;
P_0c0c2c94: /* original fe08, guest PC 0x0c0c2c94 */
if(!s->budget--) { s->failed_pc=0x0c0c2c94u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c2c96;
P_0c0c2c96: /* original 9d79, guest PC 0x0c0c2c96 */
if(!s->budget--) { s->failed_pc=0x0c0c2c96u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d8cu,2);
goto P_0c0c2c98;
P_0c0c2c98: /* original 9c77, guest PC 0x0c0c2c98 */
if(!s->budget--) { s->failed_pc=0x0c0c2c98u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d8au,2);
goto P_0c0c2c9a;
P_0c0c2c9a: /* original 4a0b, guest PC 0x0c0c2c9a */
if(!s->budget--) { s->failed_pc=0x0c0c2c9au; return 0; }
target=r[10];
r[16]=0x0c0c2c9eu;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2c9eu) { target=s->pc; goto dispatch; }
goto P_0c0c2c9e;
P_0c0c2c9c: /* original 64ef, guest PC 0x0c0c2c9c */
if(!s->budget--) { s->failed_pc=0x0c0c2c9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c2c9e;
P_0c0c2c9e: /* original f40c, guest PC 0x0c0c2c9e */
if(!s->budget--) { s->failed_pc=0x0c0c2c9eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c2ca0;
P_0c0c2ca0: /* original 7b04, guest PC 0x0c0c2ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca0u; return 0; }
r[11]+=0x00000004u;
goto P_0c0c2ca2;
P_0c0c2ca2: /* original f0fc, guest PC 0x0c0c2ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca2u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0c2ca4;
P_0c0c2ca4: /* original 4d10, guest PC 0x0c0c2ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca4u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c0c2ca6;
P_0c0c2ca6: /* original f3ec, guest PC 0x0c0c2ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca6u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0c2ca8;
P_0c0c2ca8: /* original f34e, guest PC 0x0c0c2ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0c2caa;
P_0c0c2caa: /* original 3ecc, guest PC 0x0c0c2caa */
if(!s->budget--) { s->failed_pc=0x0c0c2caau; return 0; }
r[14]+=r[12];
goto P_0c0c2cac;
P_0c0c2cac: /* original f43c, guest PC 0x0c0c2cac */
if(!s->budget--) { s->failed_pc=0x0c0c2cacu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c2cae;
P_0c0c2cae: /* original f43d, guest PC 0x0c0c2cae */
if(!s->budget--) { s->failed_pc=0x0c0c2caeu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c2cb0;
P_0c0c2cb0: /* original 035a, guest PC 0x0c0c2cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb0u; return 0; }
r[3]=r[53];
goto P_0c0c2cb2;
P_0c0c2cb2: /* original 2b32, guest PC 0x0c0c2cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb2u; return 0; }
write(ram,r[11],r[3],4);
goto P_0c0c2cb4;
P_0c0c2cb4: /* original 8ff1, guest PC 0x0c0c2cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb4u; return 0; }
cond=r[17]&1u;
r[14]=r[14]&65535u;
if(!cond) { goto P_0c0c2c9a; }
goto P_0c0c2cb8;
P_0c0c2cb6: /* original 6eed, guest PC 0x0c0c2cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb6u; return 0; }
r[14]=r[14]&65535u;
goto P_0c0c2cb8;
P_0c0c2cb8: /* original 4f26, guest PC 0x0c0c2cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2cba;
P_0c0c2cba: /* original fef9, guest PC 0x0c0c2cba */
if(!s->budget--) { s->failed_pc=0x0c0c2cbau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2cbc;
P_0c0c2cbc: /* original fff9, guest PC 0x0c0c2cbc */
if(!s->budget--) { s->failed_pc=0x0c0c2cbcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2cbe;
P_0c0c2cbe: /* original 6af6, guest PC 0x0c0c2cbe */
if(!s->budget--) { s->failed_pc=0x0c0c2cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c2cc0;
P_0c0c2cc0: /* original 6bf6, guest PC 0x0c0c2cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c2cc2;
P_0c0c2cc2: /* original 6cf6, guest PC 0x0c0c2cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2cc4;
P_0c0c2cc4: /* original 6df6, guest PC 0x0c0c2cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2cc6;
P_0c0c2cc6: /* original 000b, guest PC 0x0c0c2cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2cc8: /* original 6ef6, guest PC 0x0c0c2cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c2ccau,s,ram);
P_0c0c426c: /* original 4f22, guest PC 0x0c0c426c */
if(!s->budget--) { s->failed_pc=0x0c0c426cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c426e;
P_0c0c426e: /* original 00ec, guest PC 0x0c0c426e */
if(!s->budget--) { s->failed_pc=0x0c0c426eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4270;
P_0c0c4270: /* original db33, guest PC 0x0c0c4270 */
if(!s->budget--) { s->failed_pc=0x0c0c4270u; return 0; }
r[11]=read(ram,0x0c0c4340u,4);
goto P_0c0c4272;
P_0c0c4272: /* original 8801, guest PC 0x0c0c4272 */
if(!s->budget--) { s->failed_pc=0x0c0c4272u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4274;
P_0c0c4274: /* original 8d2e, guest PC 0x0c0c4274 */
if(!s->budget--) { s->failed_pc=0x0c0c4274u; return 0; }
cond=r[17]&1u;
r[13]=r[4];
if(cond) { goto P_0c0c42d4; }
goto P_0c0c4278;
P_0c0c4276: /* original 6d43, guest PC 0x0c0c4276 */
if(!s->budget--) { s->failed_pc=0x0c0c4276u; return 0; }
r[13]=r[4];
goto P_0c0c4278;
P_0c0c4278: /* original 9056, guest PC 0x0c0c4278 */
if(!s->budget--) { s->failed_pc=0x0c0c4278u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4328u,2);
goto P_0c0c427a;
P_0c0c427a: /* original da2f, guest PC 0x0c0c427a */
if(!s->budget--) { s->failed_pc=0x0c0c427au; return 0; }
r[10]=read(ram,0x0c0c4338u,4);
goto P_0c0c427c;
P_0c0c427c: /* original 00ec, guest PC 0x0c0c427c */
if(!s->budget--) { s->failed_pc=0x0c0c427cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c427e;
P_0c0c427e: /* original 8801, guest PC 0x0c0c427e */
if(!s->budget--) { s->failed_pc=0x0c0c427eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4280;
P_0c0c4280: /* original 8911, guest PC 0x0c0c4280 */
if(!s->budget--) { s->failed_pc=0x0c0c4280u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c42a6; }
goto P_0c0c4282;
P_0c0c4282: /* original 9055, guest PC 0x0c0c4282 */
if(!s->budget--) { s->failed_pc=0x0c0c4282u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4330u,2);
goto P_0c0c4284;
P_0c0c4284: /* original 0cec, guest PC 0x0c0c4284 */
if(!s->budget--) { s->failed_pc=0x0c0c4284u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4286;
P_0c0c4286: /* original 3cd3, guest PC 0x0c0c4286 */
if(!s->budget--) { s->failed_pc=0x0c0c4286u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c0c4288;
P_0c0c4288: /* original 8b11, guest PC 0x0c0c4288 */
if(!s->budget--) { s->failed_pc=0x0c0c4288u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c42ae; }
goto P_0c0c428a;
P_0c0c428a: /* original 3cd8, guest PC 0x0c0c428a */
if(!s->budget--) { s->failed_pc=0x0c0c428au; return 0; }
r[12]-=r[13];
goto P_0c0c428c;
P_0c0c428c: /* original 64b3, guest PC 0x0c0c428c */
if(!s->budget--) { s->failed_pc=0x0c0c428cu; return 0; }
r[4]=r[11];
goto P_0c0c428e;
P_0c0c428e: /* original 65c3, guest PC 0x0c0c428e */
if(!s->budget--) { s->failed_pc=0x0c0c428eu; return 0; }
r[5]=r[12];
goto P_0c0c4290;
P_0c0c4290: /* original 0ec4, guest PC 0x0c0c4290 */
if(!s->budget--) { s->failed_pc=0x0c0c4290u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c4292;
P_0c0c4292: /* original 4a0b, guest PC 0x0c0c4292 */
if(!s->budget--) { s->failed_pc=0x0c0c4292u; return 0; }
target=r[10];
r[16]=0x0c0c4296u;
r[4]+=0x00000026u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4296u) { target=s->pc; goto dispatch; }
goto P_0c0c4296;
P_0c0c4294: /* original 7426, guest PC 0x0c0c4294 */
if(!s->budget--) { s->failed_pc=0x0c0c4294u; return 0; }
r[4]+=0x00000026u;
goto P_0c0c4296;
P_0c0c4296: /* original 9046, guest PC 0x0c0c4296 */
if(!s->budget--) { s->failed_pc=0x0c0c4296u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4326u,2);
goto P_0c0c4298;
P_0c0c4298: /* original e300, guest PC 0x0c0c4298 */
if(!s->budget--) { s->failed_pc=0x0c0c4298u; return 0; }
r[3]=0x00000000u;
goto P_0c0c429a;
P_0c0c429a: /* original 6533, guest PC 0x0c0c429a */
if(!s->budget--) { s->failed_pc=0x0c0c429au; return 0; }
r[5]=r[3];
goto P_0c0c429c;
P_0c0c429c: /* original 64b3, guest PC 0x0c0c429c */
if(!s->budget--) { s->failed_pc=0x0c0c429cu; return 0; }
r[4]=r[11];
goto P_0c0c429e;
P_0c0c429e: /* original 6cd3, guest PC 0x0c0c429e */
if(!s->budget--) { s->failed_pc=0x0c0c429eu; return 0; }
r[12]=r[13];
goto P_0c0c42a0;
P_0c0c42a0: /* original 0e34, guest PC 0x0c0c42a0 */
if(!s->budget--) { s->failed_pc=0x0c0c42a0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c42a2;
P_0c0c42a2: /* original a013, guest PC 0x0c0c42a2 */
if(!s->budget--) { s->failed_pc=0x0c0c42a2u; return 0; }
r[4]+=0x00000028u;
goto P_0c0c42cc;
P_0c0c42a4: /* original 7428, guest PC 0x0c0c42a4 */
if(!s->budget--) { s->failed_pc=0x0c0c42a4u; return 0; }
r[4]+=0x00000028u;
goto P_0c0c42a6;
P_0c0c42a6: /* original 9044, guest PC 0x0c0c42a6 */
if(!s->budget--) { s->failed_pc=0x0c0c42a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4332u,2);
goto P_0c0c42a8;
P_0c0c42a8: /* original 0cec, guest PC 0x0c0c42a8 */
if(!s->budget--) { s->failed_pc=0x0c0c42a8u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c42aa;
P_0c0c42aa: /* original 3cd3, guest PC 0x0c0c42aa */
if(!s->budget--) { s->failed_pc=0x0c0c42aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c0c42ac;
P_0c0c42ac: /* original 8901, guest PC 0x0c0c42ac */
if(!s->budget--) { s->failed_pc=0x0c0c42acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c42b2; }
goto P_0c0c42ae;
P_0c0c42ae: /* original a016, guest PC 0x0c0c42ae */
if(!s->budget--) { s->failed_pc=0x0c0c42aeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c42de;
P_0c0c42b0: /* original e0ff, guest PC 0x0c0c42b0 */
if(!s->budget--) { s->failed_pc=0x0c0c42b0u; return 0; }
r[0]=0xffffffffu;
goto P_0c0c42b2;
P_0c0c42b2: /* original 3cd8, guest PC 0x0c0c42b2 */
if(!s->budget--) { s->failed_pc=0x0c0c42b2u; return 0; }
r[12]-=r[13];
goto P_0c0c42b4;
P_0c0c42b4: /* original 64b3, guest PC 0x0c0c42b4 */
if(!s->budget--) { s->failed_pc=0x0c0c42b4u; return 0; }
r[4]=r[11];
goto P_0c0c42b6;
P_0c0c42b6: /* original 65c3, guest PC 0x0c0c42b6 */
if(!s->budget--) { s->failed_pc=0x0c0c42b6u; return 0; }
r[5]=r[12];
goto P_0c0c42b8;
P_0c0c42b8: /* original 0ec4, guest PC 0x0c0c42b8 */
if(!s->budget--) { s->failed_pc=0x0c0c42b8u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c42ba;
P_0c0c42ba: /* original 4a0b, guest PC 0x0c0c42ba */
if(!s->budget--) { s->failed_pc=0x0c0c42bau; return 0; }
target=r[10];
r[16]=0x0c0c42beu;
r[4]+=0x00000029u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c42beu) { target=s->pc; goto dispatch; }
goto P_0c0c42be;
P_0c0c42bc: /* original 7429, guest PC 0x0c0c42bc */
if(!s->budget--) { s->failed_pc=0x0c0c42bcu; return 0; }
r[4]+=0x00000029u;
goto P_0c0c42be;
P_0c0c42be: /* original 9034, guest PC 0x0c0c42be */
if(!s->budget--) { s->failed_pc=0x0c0c42beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c432au,2);
goto P_0c0c42c0;
P_0c0c42c0: /* original 64b3, guest PC 0x0c0c42c0 */
if(!s->budget--) { s->failed_pc=0x0c0c42c0u; return 0; }
r[4]=r[11];
goto P_0c0c42c2;
P_0c0c42c2: /* original e300, guest PC 0x0c0c42c2 */
if(!s->budget--) { s->failed_pc=0x0c0c42c2u; return 0; }
r[3]=0x00000000u;
goto P_0c0c42c4;
P_0c0c42c4: /* original 6cd3, guest PC 0x0c0c42c4 */
if(!s->budget--) { s->failed_pc=0x0c0c42c4u; return 0; }
r[12]=r[13];
goto P_0c0c42c6;
P_0c0c42c6: /* original 742b, guest PC 0x0c0c42c6 */
if(!s->budget--) { s->failed_pc=0x0c0c42c6u; return 0; }
r[4]+=0x0000002bu;
goto P_0c0c42c8;
P_0c0c42c8: /* original 6533, guest PC 0x0c0c42c8 */
if(!s->budget--) { s->failed_pc=0x0c0c42c8u; return 0; }
r[5]=r[3];
goto P_0c0c42ca;
P_0c0c42ca: /* original 0e34, guest PC 0x0c0c42ca */
if(!s->budget--) { s->failed_pc=0x0c0c42cau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c42cc;
P_0c0c42cc: /* original 4a0b, guest PC 0x0c0c42cc */
if(!s->budget--) { s->failed_pc=0x0c0c42ccu; return 0; }
target=r[10];
r[16]=0x0c0c42d0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c42d0u) { target=s->pc; goto dispatch; }
goto P_0c0c42d0;
P_0c0c42ce: /* original 0009, guest PC 0x0c0c42ce */
if(!s->budget--) { s->failed_pc=0x0c0c42ceu; return 0; }
goto P_0c0c42d0;
P_0c0c42d0: /* original a004, guest PC 0x0c0c42d0 */
if(!s->budget--) { s->failed_pc=0x0c0c42d0u; return 0; }
r[13]=r[12];
goto P_0c0c42dc;
P_0c0c42d2: /* original 6dc3, guest PC 0x0c0c42d2 */
if(!s->budget--) { s->failed_pc=0x0c0c42d2u; return 0; }
r[13]=r[12];
goto P_0c0c42d4;
P_0c0c42d4: /* original 902a, guest PC 0x0c0c42d4 */
if(!s->budget--) { s->failed_pc=0x0c0c42d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c432cu,2);
goto P_0c0c42d6;
P_0c0c42d6: /* original 02ec, guest PC 0x0c0c42d6 */
if(!s->budget--) { s->failed_pc=0x0c0c42d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c42d8;
P_0c0c42d8: /* original 7201, guest PC 0x0c0c42d8 */
if(!s->budget--) { s->failed_pc=0x0c0c42d8u; return 0; }
r[2]+=0x00000001u;
goto P_0c0c42da;
P_0c0c42da: /* original 0e24, guest PC 0x0c0c42da */
if(!s->budget--) { s->failed_pc=0x0c0c42dau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c42dc;
P_0c0c42dc: /* original 60d3, guest PC 0x0c0c42dc */
if(!s->budget--) { s->failed_pc=0x0c0c42dcu; return 0; }
r[0]=r[13];
goto P_0c0c42de;
P_0c0c42de: /* original 4f26, guest PC 0x0c0c42de */
if(!s->budget--) { s->failed_pc=0x0c0c42deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c42e0;
P_0c0c42e0: /* original 6af6, guest PC 0x0c0c42e0 */
if(!s->budget--) { s->failed_pc=0x0c0c42e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c42e2;
P_0c0c42e2: /* original 6bf6, guest PC 0x0c0c42e2 */
if(!s->budget--) { s->failed_pc=0x0c0c42e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c42e4;
P_0c0c42e4: /* original 6cf6, guest PC 0x0c0c42e4 */
if(!s->budget--) { s->failed_pc=0x0c0c42e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c42e6;
P_0c0c42e6: /* original 6df6, guest PC 0x0c0c42e6 */
if(!s->budget--) { s->failed_pc=0x0c0c42e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c42e8;
P_0c0c42e8: /* original 000b, guest PC 0x0c0c42e8 */
if(!s->budget--) { s->failed_pc=0x0c0c42e8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c42ea: /* original 6ef6, guest PC 0x0c0c42ea */
if(!s->budget--) { s->failed_pc=0x0c0c42eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c42ecu,s,ram);
P_0c0c82e6: /* original 4f22, guest PC 0x0c0c82e6 */
if(!s->budget--) { s->failed_pc=0x0c0c82e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c82e8;
P_0c0c82e8: /* original d426, guest PC 0x0c0c82e8 */
if(!s->budget--) { s->failed_pc=0x0c0c82e8u; return 0; }
r[4]=read(ram,0x0c0c8384u,4);
goto P_0c0c82ea;
P_0c0c82ea: /* original d322, guest PC 0x0c0c82ea */
if(!s->budget--) { s->failed_pc=0x0c0c82eau; return 0; }
r[3]=read(ram,0x0c0c8374u,4);
goto P_0c0c82ec;
P_0c0c82ec: /* original 7ffc, guest PC 0x0c0c82ec */
if(!s->budget--) { s->failed_pc=0x0c0c82ecu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c82ee;
P_0c0c82ee: /* original 2f32, guest PC 0x0c0c82ee */
if(!s->budget--) { s->failed_pc=0x0c0c82eeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c82f0;
P_0c0c82f0: /* original 903d, guest PC 0x0c0c82f0 */
if(!s->budget--) { s->failed_pc=0x0c0c82f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c836eu,2);
goto P_0c0c82f2;
P_0c0c82f2: /* original 024c, guest PC 0x0c0c82f2 */
if(!s->budget--) { s->failed_pc=0x0c0c82f2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c82f4;
P_0c0c82f4: /* original 70f8, guest PC 0x0c0c82f4 */
if(!s->budget--) { s->failed_pc=0x0c0c82f4u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c82f6;
P_0c0c82f6: /* original 034c, guest PC 0x0c0c82f6 */
if(!s->budget--) { s->failed_pc=0x0c0c82f6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c82f8;
P_0c0c82f8: /* original 3230, guest PC 0x0c0c82f8 */
if(!s->budget--) { s->failed_pc=0x0c0c82f8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c82fa;
P_0c0c82fa: /* original 8b04, guest PC 0x0c0c82fa */
if(!s->budget--) { s->failed_pc=0x0c0c82fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8306; }
goto P_0c0c82fc;
P_0c0c82fc: /* original 7f04, guest PC 0x0c0c82fc */
if(!s->budget--) { s->failed_pc=0x0c0c82fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c82fe;
P_0c0c82fe: /* original 4f26, guest PC 0x0c0c82fe */
if(!s->budget--) { s->failed_pc=0x0c0c82feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8300;
P_0c0c8300: /* original e400, guest PC 0x0c0c8300 */
if(!s->budget--) { s->failed_pc=0x0c0c8300u; return 0; }
r[4]=0x00000000u;
goto P_0c0c8302;
P_0c0c8302: /* original a00f, guest PC 0x0c0c8302 */
if(!s->budget--) { s->failed_pc=0x0c0c8302u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c8304: /* original 6ef6, guest PC 0x0c0c8304 */
if(!s->budget--) { s->failed_pc=0x0c0c8304u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8306;
P_0c0c8306: /* original 9033, guest PC 0x0c0c8306 */
if(!s->budget--) { s->failed_pc=0x0c0c8306u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8370u,2);
goto P_0c0c8308;
P_0c0c8308: /* original e320, guest PC 0x0c0c8308 */
if(!s->budget--) { s->failed_pc=0x0c0c8308u; return 0; }
r[3]=0x00000020u;
goto P_0c0c830a;
P_0c0c830a: /* original e608, guest PC 0x0c0c830a */
if(!s->budget--) { s->failed_pc=0x0c0c830au; return 0; }
r[6]=0x00000008u;
goto P_0c0c830c;
P_0c0c830c: /* original 0e4e, guest PC 0x0c0c830c */
if(!s->budget--) { s->failed_pc=0x0c0c830cu; return 0; }
r[14]=read(ram,r[4]+r[0],4);
goto P_0c0c830e;
P_0c0c830e: /* original e707, guest PC 0x0c0c830e */
if(!s->budget--) { s->failed_pc=0x0c0c830eu; return 0; }
r[7]=0x00000007u;
goto P_0c0c8310;
P_0c0c8310: /* original 2f36, guest PC 0x0c0c8310 */
if(!s->budget--) { s->failed_pc=0x0c0c8310u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8312;
P_0c0c8312: /* original d21d, guest PC 0x0c0c8312 */
if(!s->budget--) { s->failed_pc=0x0c0c8312u; return 0; }
r[2]=read(ram,0x0c0c8388u,4);
goto P_0c0c8314;
P_0c0c8314: /* original 65e3, guest PC 0x0c0c8314 */
if(!s->budget--) { s->failed_pc=0x0c0c8314u; return 0; }
r[5]=r[14];
goto P_0c0c8316;
P_0c0c8316: /* original 420b, guest PC 0x0c0c8316 */
if(!s->budget--) { s->failed_pc=0x0c0c8316u; return 0; }
target=r[2];
r[16]=0x0c0c831au;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c831au) { target=s->pc; goto dispatch; }
goto P_0c0c831a;
P_0c0c8318: /* original 54f1, guest PC 0x0c0c8318 */
if(!s->budget--) { s->failed_pc=0x0c0c8318u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c831a;
P_0c0c831a: /* original 7f08, guest PC 0x0c0c831a */
if(!s->budget--) { s->failed_pc=0x0c0c831au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c831c;
P_0c0c831c: /* original 64e3, guest PC 0x0c0c831c */
if(!s->budget--) { s->failed_pc=0x0c0c831cu; return 0; }
r[4]=r[14];
goto P_0c0c831e;
P_0c0c831e: /* original 4f26, guest PC 0x0c0c831e */
if(!s->budget--) { s->failed_pc=0x0c0c831eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8320;
P_0c0c8320: /* original a000, guest PC 0x0c0c8320 */
if(!s->budget--) { s->failed_pc=0x0c0c8320u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c8322: /* original 6ef6, guest PC 0x0c0c8322 */
if(!s->budget--) { s->failed_pc=0x0c0c8322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c8324: /* original 2fe6, guest PC 0x0c0c8324 */
if(!s->budget--) { s->failed_pc=0x0c0c8324u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8326;
P_0c0c8326: /* original 2fd6, guest PC 0x0c0c8326 */
if(!s->budget--) { s->failed_pc=0x0c0c8326u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8328;
P_0c0c8328: /* original 2fc6, guest PC 0x0c0c8328 */
if(!s->budget--) { s->failed_pc=0x0c0c8328u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832a;
P_0c0c832a: /* original 2fb6, guest PC 0x0c0c832a */
if(!s->budget--) { s->failed_pc=0x0c0c832au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832c;
P_0c0c832c: /* original 2fa6, guest PC 0x0c0c832c */
if(!s->budget--) { s->failed_pc=0x0c0c832cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832e;
P_0c0c832e: /* original 2f96, guest PC 0x0c0c832e */
if(!s->budget--) { s->failed_pc=0x0c0c832eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8330;
P_0c0c8330: /* original 2f86, guest PC 0x0c0c8330 */
if(!s->budget--) { s->failed_pc=0x0c0c8330u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8332;
P_0c0c8332: /* original de14, guest PC 0x0c0c8332 */
if(!s->budget--) { s->failed_pc=0x0c0c8332u; return 0; }
r[14]=read(ram,0x0c0c8384u,4);
goto P_0c0c8334;
P_0c0c8334: /* original 4f22, guest PC 0x0c0c8334 */
if(!s->budget--) { s->failed_pc=0x0c0c8334u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8336;
P_0c0c8336: /* original d310, guest PC 0x0c0c8336 */
if(!s->budget--) { s->failed_pc=0x0c0c8336u; return 0; }
r[3]=read(ram,0x0c0c8378u,4);
goto P_0c0c8338;
P_0c0c8338: /* original dd0e, guest PC 0x0c0c8338 */
if(!s->budget--) { s->failed_pc=0x0c0c8338u; return 0; }
r[13]=read(ram,0x0c0c8374u,4);
goto P_0c0c833a;
P_0c0c833a: /* original 7fe8, guest PC 0x0c0c833a */
if(!s->budget--) { s->failed_pc=0x0c0c833au; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0c833c;
P_0c0c833c: /* original 1f35, guest PC 0x0c0c833c */
if(!s->budget--) { s->failed_pc=0x0c0c833cu; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0c833e;
P_0c0c833e: /* original d213, guest PC 0x0c0c833e */
if(!s->budget--) { s->failed_pc=0x0c0c833eu; return 0; }
r[2]=read(ram,0x0c0c838cu,4);
goto P_0c0c8340;
P_0c0c8340: /* original 1f24, guest PC 0x0c0c8340 */
if(!s->budget--) { s->failed_pc=0x0c0c8340u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0c8342;
P_0c0c8342: /* original 9016, guest PC 0x0c0c8342 */
if(!s->budget--) { s->failed_pc=0x0c0c8342u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8372u,2);
goto P_0c0c8344;
P_0c0c8344: /* original d912, guest PC 0x0c0c8344 */
if(!s->budget--) { s->failed_pc=0x0c0c8344u; return 0; }
r[9]=read(ram,0x0c0c8390u,4);
goto P_0c0c8346;
P_0c0c8346: /* original 04ec, guest PC 0x0c0c8346 */
if(!s->budget--) { s->failed_pc=0x0c0c8346u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8348;
P_0c0c8348: /* original 7001, guest PC 0x0c0c8348 */
if(!s->budget--) { s->failed_pc=0x0c0c8348u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c834a;
P_0c0c834a: /* original 06ec, guest PC 0x0c0c834a */
if(!s->budget--) { s->failed_pc=0x0c0c834au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c834c;
P_0c0c834c: /* original 644c, guest PC 0x0c0c834c */
if(!s->budget--) { s->failed_pc=0x0c0c834cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c834e;
P_0c0c834e: /* original 666c, guest PC 0x0c0c834e */
if(!s->budget--) { s->failed_pc=0x0c0c834eu; return 0; }
r[6]=r[6]&255u;
goto P_0c0c8350;
P_0c0c8350: /* original 6763, guest PC 0x0c0c8350 */
if(!s->budget--) { s->failed_pc=0x0c0c8350u; return 0; }
r[7]=r[6];
goto P_0c0c8352;
P_0c0c8352: /* original 4708, guest PC 0x0c0c8352 */
if(!s->budget--) { s->failed_pc=0x0c0c8352u; return 0; }
r[7]<<=2;
goto P_0c0c8354;
P_0c0c8354: /* original 4700, guest PC 0x0c0c8354 */
if(!s->budget--) { s->failed_pc=0x0c0c8354u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c8356;
P_0c0c8356: /* original 2448, guest PC 0x0c0c8356 */
if(!s->budget--) { s->failed_pc=0x0c0c8356u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c8358;
P_0c0c8358: /* original 891c, guest PC 0x0c0c8358 */
if(!s->budget--) { s->failed_pc=0x0c0c8358u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8394; }
goto P_0c0c835a;
P_0c0c835a: /* original 6573, guest PC 0x0c0c835a */
if(!s->budget--) { s->failed_pc=0x0c0c835au; return 0; }
r[5]=r[7];
goto P_0c0c835c;
P_0c0c835c: /* original a01c, guest PC 0x0c0c835c */
if(!s->budget--) { s->failed_pc=0x0c0c835cu; return 0; }
r[5]+=0x00000003u;
goto P_0c0c8398;
P_0c0c835e: /* original 7503, guest PC 0x0c0c835e */
if(!s->budget--) { s->failed_pc=0x0c0c835eu; return 0; }
r[5]+=0x00000003u;
return vf3_matrix_family(0x0c0c8360u,s,ram);
P_0c0c8394: /* original 6573, guest PC 0x0c0c8394 */
if(!s->budget--) { s->failed_pc=0x0c0c8394u; return 0; }
r[5]=r[7];
goto P_0c0c8396;
P_0c0c8396: /* original 7507, guest PC 0x0c0c8396 */
if(!s->budget--) { s->failed_pc=0x0c0c8396u; return 0; }
r[5]+=0x00000007u;
goto P_0c0c8398;
P_0c0c8398: /* original 6243, guest PC 0x0c0c8398 */
if(!s->budget--) { s->failed_pc=0x0c0c8398u; return 0; }
r[2]=r[4];
goto P_0c0c839a;
P_0c0c839a: /* original 6343, guest PC 0x0c0c839a */
if(!s->budget--) { s->failed_pc=0x0c0c839au; return 0; }
r[3]=r[4];
goto P_0c0c839c;
P_0c0c839c: /* original 6743, guest PC 0x0c0c839c */
if(!s->budget--) { s->failed_pc=0x0c0c839cu; return 0; }
r[7]=r[4];
goto P_0c0c839e;
P_0c0c839e: /* original 4208, guest PC 0x0c0c839e */
if(!s->budget--) { s->failed_pc=0x0c0c839eu; return 0; }
r[2]<<=2;
goto P_0c0c83a0;
P_0c0c83a0: /* original 4708, guest PC 0x0c0c83a0 */
if(!s->budget--) { s->failed_pc=0x0c0c83a0u; return 0; }
r[7]<<=2;
goto P_0c0c83a2;
P_0c0c83a2: /* original 4700, guest PC 0x0c0c83a2 */
if(!s->budget--) { s->failed_pc=0x0c0c83a2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c83a4;
P_0c0c83a4: /* original 4400, guest PC 0x0c0c83a4 */
if(!s->budget--) { s->failed_pc=0x0c0c83a4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c83a6;
P_0c0c83a6: /* original 342c, guest PC 0x0c0c83a6 */
if(!s->budget--) { s->failed_pc=0x0c0c83a6u; return 0; }
r[4]+=r[2];
goto P_0c0c83a8;
P_0c0c83a8: /* original 3738, guest PC 0x0c0c83a8 */
if(!s->budget--) { s->failed_pc=0x0c0c83a8u; return 0; }
r[7]-=r[3];
goto P_0c0c83aa;
P_0c0c83aa: /* original 346c, guest PC 0x0c0c83aa */
if(!s->budget--) { s->failed_pc=0x0c0c83aau; return 0; }
r[4]+=r[6];
goto P_0c0c83ac;
P_0c0c83ac: /* original 6343, guest PC 0x0c0c83ac */
if(!s->budget--) { s->failed_pc=0x0c0c83acu; return 0; }
r[3]=r[4];
goto P_0c0c83ae;
P_0c0c83ae: /* original 4300, guest PC 0x0c0c83ae */
if(!s->budget--) { s->failed_pc=0x0c0c83aeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c83b0;
P_0c0c83b0: /* original e107, guest PC 0x0c0c83b0 */
if(!s->budget--) { s->failed_pc=0x0c0c83b0u; return 0; }
r[1]=0x00000007u;
goto P_0c0c83b2;
P_0c0c83b2: /* original 1f42, guest PC 0x0c0c83b2 */
if(!s->budget--) { s->failed_pc=0x0c0c83b2u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0c83b4;
P_0c0c83b4: /* original 4500, guest PC 0x0c0c83b4 */
if(!s->budget--) { s->failed_pc=0x0c0c83b4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c83b6;
P_0c0c83b6: /* original 1f31, guest PC 0x0c0c83b6 */
if(!s->budget--) { s->failed_pc=0x0c0c83b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c83b8;
P_0c0c83b8: /* original d031, guest PC 0x0c0c83b8 */
if(!s->budget--) { s->failed_pc=0x0c0c83b8u; return 0; }
r[0]=read(ram,0x0c0c8480u,4);
goto P_0c0c83ba;
P_0c0c83ba: /* original 7721, guest PC 0x0c0c83ba */
if(!s->budget--) { s->failed_pc=0x0c0c83bau; return 0; }
r[7]+=0x00000021u;
goto P_0c0c83bc;
P_0c0c83bc: /* original 6a53, guest PC 0x0c0c83bc */
if(!s->budget--) { s->failed_pc=0x0c0c83bcu; return 0; }
r[10]=r[5];
goto P_0c0c83be;
P_0c0c83be: /* original 471c, guest PC 0x0c0c83be */
if(!s->budget--) { s->failed_pc=0x0c0c83beu; return 0; }
r[7]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[7]>>((-r[1])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[1]&31u);
goto P_0c0c83c0;
P_0c0c83c0: /* original 023d, guest PC 0x0c0c83c0 */
if(!s->budget--) { s->failed_pc=0x0c0c83c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c83c2;
P_0c0c83c2: /* original 2a7b, guest PC 0x0c0c83c2 */
if(!s->budget--) { s->failed_pc=0x0c0c83c2u; return 0; }
r[10]|=r[7];
goto P_0c0c83c4;
P_0c0c83c4: /* original 622d, guest PC 0x0c0c83c4 */
if(!s->budget--) { s->failed_pc=0x0c0c83c4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c83c6;
P_0c0c83c6: /* original 1f23, guest PC 0x0c0c83c6 */
if(!s->budget--) { s->failed_pc=0x0c0c83c6u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c83c8;
P_0c0c83c8: /* original 9054, guest PC 0x0c0c83c8 */
if(!s->budget--) { s->failed_pc=0x0c0c83c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8474u,2);
goto P_0c0c83ca;
P_0c0c83ca: /* original 0ea6, guest PC 0x0c0c83ca */
if(!s->budget--) { s->failed_pc=0x0c0c83cau; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0c83cc;
P_0c0c83cc: /* original 9353, guest PC 0x0c0c83cc */
if(!s->budget--) { s->failed_pc=0x0c0c83ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8476u,2);
goto P_0c0c83ce;
P_0c0c83ce: /* original 2f32, guest PC 0x0c0c83ce */
if(!s->budget--) { s->failed_pc=0x0c0c83ceu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c83d0;
P_0c0c83d0: /* original 50f5, guest PC 0x0c0c83d0 */
if(!s->budget--) { s->failed_pc=0x0c0c83d0u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c0c83d2;
P_0c0c83d2: /* original 9251, guest PC 0x0c0c83d2 */
if(!s->budget--) { s->failed_pc=0x0c0c83d2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8478u,2);
goto P_0c0c83d4;
P_0c0c83d4: /* original 002c, guest PC 0x0c0c83d4 */
if(!s->budget--) { s->failed_pc=0x0c0c83d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0c83d6;
P_0c0c83d6: /* original 8801, guest PC 0x0c0c83d6 */
if(!s->budget--) { s->failed_pc=0x0c0c83d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c83d8;
P_0c0c83d8: /* original 8b01, guest PC 0x0c0c83d8 */
if(!s->budget--) { s->failed_pc=0x0c0c83d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c83de; }
goto P_0c0c83da;
P_0c0c83da: /* original 904e, guest PC 0x0c0c83da */
if(!s->budget--) { s->failed_pc=0x0c0c83dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847au,2);
goto P_0c0c83dc;
P_0c0c83dc: /* original 2f02, guest PC 0x0c0c83dc */
if(!s->budget--) { s->failed_pc=0x0c0c83dcu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c83de;
P_0c0c83de: /* original 904d, guest PC 0x0c0c83de */
if(!s->budget--) { s->failed_pc=0x0c0c83deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847cu,2);
goto P_0c0c83e0;
P_0c0c83e0: /* original db29, guest PC 0x0c0c83e0 */
if(!s->budget--) { s->failed_pc=0x0c0c83e0u; return 0; }
r[11]=read(ram,0x0c0c8488u,4);
goto P_0c0c83e2;
P_0c0c83e2: /* original 00ec, guest PC 0x0c0c83e2 */
if(!s->budget--) { s->failed_pc=0x0c0c83e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c83e4;
P_0c0c83e4: /* original d827, guest PC 0x0c0c83e4 */
if(!s->budget--) { s->failed_pc=0x0c0c83e4u; return 0; }
r[8]=read(ram,0x0c0c8484u,4);
goto P_0c0c83e6;
P_0c0c83e6: /* original 600c, guest PC 0x0c0c83e6 */
if(!s->budget--) { s->failed_pc=0x0c0c83e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c83e8;
P_0c0c83e8: /* original 8801, guest PC 0x0c0c83e8 */
if(!s->budget--) { s->failed_pc=0x0c0c83e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c83ea;
P_0c0c83ea: /* original 8d04, guest PC 0x0c0c83ea */
if(!s->budget--) { s->failed_pc=0x0c0c83eau; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c0c83f6; }
goto P_0c0c83ee;
P_0c0c83ec: /* original ec00, guest PC 0x0c0c83ec */
if(!s->budget--) { s->failed_pc=0x0c0c83ecu; return 0; }
r[12]=0x00000000u;
goto P_0c0c83ee;
P_0c0c83ee: /* original 50f4, guest PC 0x0c0c83ee */
if(!s->budget--) { s->failed_pc=0x0c0c83eeu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c83f0;
P_0c0c83f0: /* original 6002, guest PC 0x0c0c83f0 */
if(!s->budget--) { s->failed_pc=0x0c0c83f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0c83f2;
P_0c0c83f2: /* original c808, guest PC 0x0c0c83f2 */
if(!s->budget--) { s->failed_pc=0x0c0c83f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0c83f4;
P_0c0c83f4: /* original 8b0d, guest PC 0x0c0c83f4 */
if(!s->budget--) { s->failed_pc=0x0c0c83f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8412; }
goto P_0c0c83f6;
P_0c0c83f6: /* original 2fc6, guest PC 0x0c0c83f6 */
if(!s->budget--) { s->failed_pc=0x0c0c83f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c83f8;
P_0c0c83f8: /* original 66d3, guest PC 0x0c0c83f8 */
if(!s->budget--) { s->failed_pc=0x0c0c83f8u; return 0; }
r[6]=r[13];
goto P_0c0c83fa;
P_0c0c83fa: /* original 55f1, guest PC 0x0c0c83fa */
if(!s->budget--) { s->failed_pc=0x0c0c83fau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c83fc;
P_0c0c83fc: /* original e700, guest PC 0x0c0c83fc */
if(!s->budget--) { s->failed_pc=0x0c0c83fcu; return 0; }
r[7]=0x00000000u;
goto P_0c0c83fe;
P_0c0c83fe: /* original 4b0b, guest PC 0x0c0c83fe */
if(!s->budget--) { s->failed_pc=0x0c0c83feu; return 0; }
target=r[11];
r[16]=0x0c0c8402u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8402u) { target=s->pc; goto dispatch; }
goto P_0c0c8402;
P_0c0c8400: /* original 64a3, guest PC 0x0c0c8400 */
if(!s->budget--) { s->failed_pc=0x0c0c8400u; return 0; }
r[4]=r[10];
goto P_0c0c8402;
P_0c0c8402: /* original 2fc6, guest PC 0x0c0c8402 */
if(!s->budget--) { s->failed_pc=0x0c0c8402u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8404;
P_0c0c8404: /* original 66d3, guest PC 0x0c0c8404 */
if(!s->budget--) { s->failed_pc=0x0c0c8404u; return 0; }
r[6]=r[13];
goto P_0c0c8406;
P_0c0c8406: /* original 55f5, guest PC 0x0c0c8406 */
if(!s->budget--) { s->failed_pc=0x0c0c8406u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0c8408;
P_0c0c8408: /* original e700, guest PC 0x0c0c8408 */
if(!s->budget--) { s->failed_pc=0x0c0c8408u; return 0; }
r[7]=0x00000000u;
goto P_0c0c840a;
P_0c0c840a: /* original 480b, guest PC 0x0c0c840a */
if(!s->budget--) { s->failed_pc=0x0c0c840au; return 0; }
target=r[8];
r[16]=0x0c0c840eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c840eu) { target=s->pc; goto dispatch; }
goto P_0c0c840e;
P_0c0c840c: /* original 64a3, guest PC 0x0c0c840c */
if(!s->budget--) { s->failed_pc=0x0c0c840cu; return 0; }
r[4]=r[10];
goto P_0c0c840e;
P_0c0c840e: /* original a00c, guest PC 0x0c0c840e */
if(!s->budget--) { s->failed_pc=0x0c0c840eu; return 0; }
goto P_0c0c842a;
P_0c0c8410: /* original 0009, guest PC 0x0c0c8410 */
if(!s->budget--) { s->failed_pc=0x0c0c8410u; return 0; }
goto P_0c0c8412;
P_0c0c8412: /* original 2fc6, guest PC 0x0c0c8412 */
if(!s->budget--) { s->failed_pc=0x0c0c8412u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8414;
P_0c0c8414: /* original 66d3, guest PC 0x0c0c8414 */
if(!s->budget--) { s->failed_pc=0x0c0c8414u; return 0; }
r[6]=r[13];
goto P_0c0c8416;
P_0c0c8416: /* original 55f1, guest PC 0x0c0c8416 */
if(!s->budget--) { s->failed_pc=0x0c0c8416u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c8418;
P_0c0c8418: /* original e700, guest PC 0x0c0c8418 */
if(!s->budget--) { s->failed_pc=0x0c0c8418u; return 0; }
r[7]=0x00000000u;
goto P_0c0c841a;
P_0c0c841a: /* original 480b, guest PC 0x0c0c841a */
if(!s->budget--) { s->failed_pc=0x0c0c841au; return 0; }
target=r[8];
r[16]=0x0c0c841eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c841eu) { target=s->pc; goto dispatch; }
goto P_0c0c841e;
P_0c0c841c: /* original 64a3, guest PC 0x0c0c841c */
if(!s->budget--) { s->failed_pc=0x0c0c841cu; return 0; }
r[4]=r[10];
goto P_0c0c841e;
P_0c0c841e: /* original 2fc6, guest PC 0x0c0c841e */
if(!s->budget--) { s->failed_pc=0x0c0c841eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8420;
P_0c0c8420: /* original 66d3, guest PC 0x0c0c8420 */
if(!s->budget--) { s->failed_pc=0x0c0c8420u; return 0; }
r[6]=r[13];
goto P_0c0c8422;
P_0c0c8422: /* original 55f5, guest PC 0x0c0c8422 */
if(!s->budget--) { s->failed_pc=0x0c0c8422u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0c8424;
P_0c0c8424: /* original e700, guest PC 0x0c0c8424 */
if(!s->budget--) { s->failed_pc=0x0c0c8424u; return 0; }
r[7]=0x00000000u;
goto P_0c0c8426;
P_0c0c8426: /* original 4b0b, guest PC 0x0c0c8426 */
if(!s->budget--) { s->failed_pc=0x0c0c8426u; return 0; }
target=r[11];
r[16]=0x0c0c842au;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c842au) { target=s->pc; goto dispatch; }
goto P_0c0c842a;
P_0c0c8428: /* original 64a3, guest PC 0x0c0c8428 */
if(!s->budget--) { s->failed_pc=0x0c0c8428u; return 0; }
r[4]=r[10];
goto P_0c0c842a;
P_0c0c842a: /* original 7f08, guest PC 0x0c0c842a */
if(!s->budget--) { s->failed_pc=0x0c0c842au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c842c;
P_0c0c842c: /* original d017, guest PC 0x0c0c842c */
if(!s->budget--) { s->failed_pc=0x0c0c842cu; return 0; }
r[0]=read(ram,0x0c0c848cu,4);
goto P_0c0c842e;
P_0c0c842e: /* original 53f1, guest PC 0x0c0c842e */
if(!s->budget--) { s->failed_pc=0x0c0c842eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c8430;
P_0c0c8430: /* original 6a93, guest PC 0x0c0c8430 */
if(!s->budget--) { s->failed_pc=0x0c0c8430u; return 0; }
r[10]=r[9];
goto P_0c0c8432;
P_0c0c8432: /* original 003d, guest PC 0x0c0c8432 */
if(!s->budget--) { s->failed_pc=0x0c0c8432u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c8434;
P_0c0c8434: /* original 88ff, guest PC 0x0c0c8434 */
if(!s->budget--) { s->failed_pc=0x0c0c8434u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c8436;
P_0c0c8436: /* original 8d0f, guest PC 0x0c0c8436 */
if(!s->budget--) { s->failed_pc=0x0c0c8436u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000040u;
if(cond) { goto P_0c0c8458; }
goto P_0c0c843a;
P_0c0c8438: /* original 7a40, guest PC 0x0c0c8438 */
if(!s->budget--) { s->failed_pc=0x0c0c8438u; return 0; }
r[10]+=0x00000040u;
goto P_0c0c843a;
P_0c0c843a: /* original 51f2, guest PC 0x0c0c843a */
if(!s->budget--) { s->failed_pc=0x0c0c843au; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0c843c;
P_0c0c843c: /* original 4108, guest PC 0x0c0c843c */
if(!s->budget--) { s->failed_pc=0x0c0c843cu; return 0; }
r[1]<<=2;
goto P_0c0c843e;
P_0c0c843e: /* original 319c, guest PC 0x0c0c843e */
if(!s->budget--) { s->failed_pc=0x0c0c843eu; return 0; }
r[1]+=r[9];
goto P_0c0c8440;
P_0c0c8440: /* original 2f12, guest PC 0x0c0c8440 */
if(!s->budget--) { s->failed_pc=0x0c0c8440u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c8442;
P_0c0c8442: /* original 2a12, guest PC 0x0c0c8442 */
if(!s->budget--) { s->failed_pc=0x0c0c8442u; return 0; }
write(ram,r[10],r[1],4);
goto P_0c0c8444;
P_0c0c8444: /* original 65f2, guest PC 0x0c0c8444 */
if(!s->budget--) { s->failed_pc=0x0c0c8444u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c8446;
P_0c0c8446: /* original 53f1, guest PC 0x0c0c8446 */
if(!s->budget--) { s->failed_pc=0x0c0c8446u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c8448;
P_0c0c8448: /* original d010, guest PC 0x0c0c8448 */
if(!s->budget--) { s->failed_pc=0x0c0c8448u; return 0; }
r[0]=read(ram,0x0c0c848cu,4);
goto P_0c0c844a;
P_0c0c844a: /* original d211, guest PC 0x0c0c844a */
if(!s->budget--) { s->failed_pc=0x0c0c844au; return 0; }
r[2]=read(ram,0x0c0c8490u,4);
goto P_0c0c844c;
P_0c0c844c: /* original 420b, guest PC 0x0c0c844c */
if(!s->budget--) { s->failed_pc=0x0c0c844cu; return 0; }
target=r[2];
r[16]=0x0c0c8450u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8450u) { target=s->pc; goto dispatch; }
goto P_0c0c8450;
P_0c0c844e: /* original 043d, guest PC 0x0c0c844e */
if(!s->budget--) { s->failed_pc=0x0c0c844eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c8450;
P_0c0c8450: /* original 63f2, guest PC 0x0c0c8450 */
if(!s->budget--) { s->failed_pc=0x0c0c8450u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c8452;
P_0c0c8452: /* original 6232, guest PC 0x0c0c8452 */
if(!s->budget--) { s->failed_pc=0x0c0c8452u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0c8454;
P_0c0c8454: /* original 2228, guest PC 0x0c0c8454 */
if(!s->budget--) { s->failed_pc=0x0c0c8454u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c8456;
P_0c0c8456: /* original 891d, guest PC 0x0c0c8456 */
if(!s->budget--) { s->failed_pc=0x0c0c8456u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8494; }
goto P_0c0c8458;
P_0c0c8458: /* original 61a2, guest PC 0x0c0c8458 */
if(!s->budget--) { s->failed_pc=0x0c0c8458u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0c845a;
P_0c0c845a: /* original 2118, guest PC 0x0c0c845a */
if(!s->budget--) { s->failed_pc=0x0c0c845au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c845c;
P_0c0c845c: /* original 891a, guest PC 0x0c0c845c */
if(!s->budget--) { s->failed_pc=0x0c0c845cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8494; }
goto P_0c0c845e;
P_0c0c845e: /* original 64a2, guest PC 0x0c0c845e */
if(!s->budget--) { s->failed_pc=0x0c0c845eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c8460;
P_0c0c8460: /* original 6342, guest PC 0x0c0c8460 */
if(!s->budget--) { s->failed_pc=0x0c0c8460u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0c8462;
P_0c0c8462: /* original 2338, guest PC 0x0c0c8462 */
if(!s->budget--) { s->failed_pc=0x0c0c8462u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c8464;
P_0c0c8464: /* original 8901, guest PC 0x0c0c8464 */
if(!s->budget--) { s->failed_pc=0x0c0c8464u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c846a; }
goto P_0c0c8466;
P_0c0c8466: /* original a015, guest PC 0x0c0c8466 */
if(!s->budget--) { s->failed_pc=0x0c0c8466u; return 0; }
write(ram,r[10],r[12],4);
goto P_0c0c8494;
P_0c0c8468: /* original 2ac2, guest PC 0x0c0c8468 */
if(!s->budget--) { s->failed_pc=0x0c0c8468u; return 0; }
write(ram,r[10],r[12],4);
goto P_0c0c846a;
P_0c0c846a: /* original 9308, guest PC 0x0c0c846a */
if(!s->budget--) { s->failed_pc=0x0c0c846au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847eu,2);
goto P_0c0c846c;
P_0c0c846c: /* original 6033, guest PC 0x0c0c846c */
if(!s->budget--) { s->failed_pc=0x0c0c846cu; return 0; }
r[0]=r[3];
goto P_0c0c846e;
P_0c0c846e: /* original 70d0, guest PC 0x0c0c846e */
if(!s->budget--) { s->failed_pc=0x0c0c846eu; return 0; }
r[0]+=0xffffffd0u;
goto P_0c0c8470;
P_0c0c8470: /* original a0b7, guest PC 0x0c0c8470 */
if(!s->budget--) { s->failed_pc=0x0c0c8470u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c85e2;
P_0c0c8472: /* original 0e34, guest PC 0x0c0c8472 */
if(!s->budget--) { s->failed_pc=0x0c0c8472u; return 0; }
write(ram,r[14]+r[0],r[3],1);
return vf3_matrix_family(0x0c0c8474u,s,ram);
P_0c0c8494: /* original 905f, guest PC 0x0c0c8494 */
if(!s->budget--) { s->failed_pc=0x0c0c8494u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8556u,2);
goto P_0c0c8496;
P_0c0c8496: /* original 01ec, guest PC 0x0c0c8496 */
if(!s->budget--) { s->failed_pc=0x0c0c8496u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8498;
P_0c0c8498: /* original 70f8, guest PC 0x0c0c8498 */
if(!s->budget--) { s->failed_pc=0x0c0c8498u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c849a;
P_0c0c849a: /* original 03ec, guest PC 0x0c0c849a */
if(!s->budget--) { s->failed_pc=0x0c0c849au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c849c;
P_0c0c849c: /* original 3130, guest PC 0x0c0c849c */
if(!s->budget--) { s->failed_pc=0x0c0c849cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0c849e;
P_0c0c849e: /* original 8939, guest PC 0x0c0c849e */
if(!s->budget--) { s->failed_pc=0x0c0c849eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8514; }
goto P_0c0c84a0;
P_0c0c84a0: /* original 905a, guest PC 0x0c0c84a0 */
if(!s->budget--) { s->failed_pc=0x0c0c84a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c84a2;
P_0c0c84a2: /* original 00ed, guest PC 0x0c0c84a2 */
if(!s->budget--) { s->failed_pc=0x0c0c84a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c84a4;
P_0c0c84a4: /* original 88ff, guest PC 0x0c0c84a4 */
if(!s->budget--) { s->failed_pc=0x0c0c84a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c84a6;
P_0c0c84a6: /* original 8d18, guest PC 0x0c0c84a6 */
if(!s->budget--) { s->failed_pc=0x0c0c84a6u; return 0; }
cond=r[17]&1u;
r[10]=r[0];
if(cond) { goto P_0c0c84da; }
goto P_0c0c84aa;
P_0c0c84a8: /* original 6a03, guest PC 0x0c0c84a8 */
if(!s->budget--) { s->failed_pc=0x0c0c84a8u; return 0; }
r[10]=r[0];
goto P_0c0c84aa;
P_0c0c84aa: /* original e220, guest PC 0x0c0c84aa */
if(!s->budget--) { s->failed_pc=0x0c0c84aau; return 0; }
r[2]=0x00000020u;
goto P_0c0c84ac;
P_0c0c84ac: /* original 64d3, guest PC 0x0c0c84ac */
if(!s->budget--) { s->failed_pc=0x0c0c84acu; return 0; }
r[4]=r[13];
goto P_0c0c84ae;
P_0c0c84ae: /* original 2f26, guest PC 0x0c0c84ae */
if(!s->budget--) { s->failed_pc=0x0c0c84aeu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c84b0;
P_0c0c84b0: /* original 6723, guest PC 0x0c0c84b0 */
if(!s->budget--) { s->failed_pc=0x0c0c84b0u; return 0; }
r[7]=r[2];
goto P_0c0c84b2;
P_0c0c84b2: /* original 9552, guest PC 0x0c0c84b2 */
if(!s->budget--) { s->failed_pc=0x0c0c84b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c84b4;
P_0c0c84b4: /* original e63e, guest PC 0x0c0c84b4 */
if(!s->budget--) { s->failed_pc=0x0c0c84b4u; return 0; }
r[6]=0x0000003eu;
goto P_0c0c84b6;
P_0c0c84b6: /* original d32a, guest PC 0x0c0c84b6 */
if(!s->budget--) { s->failed_pc=0x0c0c84b6u; return 0; }
r[3]=read(ram,0x0c0c8560u,4);
goto P_0c0c84b8;
P_0c0c84b8: /* original 430b, guest PC 0x0c0c84b8 */
if(!s->budget--) { s->failed_pc=0x0c0c84b8u; return 0; }
target=r[3];
r[16]=0x0c0c84bcu;
r[4]+=0x00000058u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84bcu) { target=s->pc; goto dispatch; }
goto P_0c0c84bc;
P_0c0c84ba: /* original 7458, guest PC 0x0c0c84ba */
if(!s->budget--) { s->failed_pc=0x0c0c84bau; return 0; }
r[4]+=0x00000058u;
goto P_0c0c84bc;
P_0c0c84bc: /* original d229, guest PC 0x0c0c84bc */
if(!s->budget--) { s->failed_pc=0x0c0c84bcu; return 0; }
r[2]=read(ram,0x0c0c8564u,4);
goto P_0c0c84be;
P_0c0c84be: /* original 7f04, guest PC 0x0c0c84be */
if(!s->budget--) { s->failed_pc=0x0c0c84beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c84c0;
P_0c0c84c0: /* original 420b, guest PC 0x0c0c84c0 */
if(!s->budget--) { s->failed_pc=0x0c0c84c0u; return 0; }
target=r[2];
r[16]=0x0c0c84c4u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84c4u) { target=s->pc; goto dispatch; }
goto P_0c0c84c4;
P_0c0c84c2: /* original 64a3, guest PC 0x0c0c84c2 */
if(!s->budget--) { s->failed_pc=0x0c0c84c2u; return 0; }
r[4]=r[10];
goto P_0c0c84c4;
P_0c0c84c4: /* original 600d, guest PC 0x0c0c84c4 */
if(!s->budget--) { s->failed_pc=0x0c0c84c4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c84c6;
P_0c0c84c6: /* original 2008, guest PC 0x0c0c84c6 */
if(!s->budget--) { s->failed_pc=0x0c0c84c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c84c8;
P_0c0c84c8: /* original 8907, guest PC 0x0c0c84c8 */
if(!s->budget--) { s->failed_pc=0x0c0c84c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c84da; }
goto P_0c0c84ca;
P_0c0c84ca: /* original 66d3, guest PC 0x0c0c84ca */
if(!s->budget--) { s->failed_pc=0x0c0c84cau; return 0; }
r[6]=r[13];
goto P_0c0c84cc;
P_0c0c84cc: /* original 2fc6, guest PC 0x0c0c84cc */
if(!s->budget--) { s->failed_pc=0x0c0c84ccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c84ce;
P_0c0c84ce: /* original 9444, guest PC 0x0c0c84ce */
if(!s->budget--) { s->failed_pc=0x0c0c84ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c84d0;
P_0c0c84d0: /* original 7658, guest PC 0x0c0c84d0 */
if(!s->budget--) { s->failed_pc=0x0c0c84d0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c84d2;
P_0c0c84d2: /* original e700, guest PC 0x0c0c84d2 */
if(!s->budget--) { s->failed_pc=0x0c0c84d2u; return 0; }
r[7]=0x00000000u;
goto P_0c0c84d4;
P_0c0c84d4: /* original 4b0b, guest PC 0x0c0c84d4 */
if(!s->budget--) { s->failed_pc=0x0c0c84d4u; return 0; }
target=r[11];
r[16]=0x0c0c84d8u;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84d8u) { target=s->pc; goto dispatch; }
goto P_0c0c84d8;
P_0c0c84d6: /* original 65a3, guest PC 0x0c0c84d6 */
if(!s->budget--) { s->failed_pc=0x0c0c84d6u; return 0; }
r[5]=r[10];
goto P_0c0c84d8;
P_0c0c84d8: /* original 7f04, guest PC 0x0c0c84d8 */
if(!s->budget--) { s->failed_pc=0x0c0c84d8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c84da;
P_0c0c84da: /* original d023, guest PC 0x0c0c84da */
if(!s->budget--) { s->failed_pc=0x0c0c84dau; return 0; }
r[0]=read(ram,0x0c0c8568u,4);
goto P_0c0c84dc;
P_0c0c84dc: /* original 65d3, guest PC 0x0c0c84dc */
if(!s->budget--) { s->failed_pc=0x0c0c84dcu; return 0; }
r[5]=r[13];
goto P_0c0c84de;
P_0c0c84de: /* original 52f1, guest PC 0x0c0c84de */
if(!s->budget--) { s->failed_pc=0x0c0c84deu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c84e0;
P_0c0c84e0: /* original 7558, guest PC 0x0c0c84e0 */
if(!s->budget--) { s->failed_pc=0x0c0c84e0u; return 0; }
r[5]+=0x00000058u;
goto P_0c0c84e2;
P_0c0c84e2: /* original 032d, guest PC 0x0c0c84e2 */
if(!s->budget--) { s->failed_pc=0x0c0c84e2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0c84e4;
P_0c0c84e4: /* original 9038, guest PC 0x0c0c84e4 */
if(!s->budget--) { s->failed_pc=0x0c0c84e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c84e6;
P_0c0c84e6: /* original 0e35, guest PC 0x0c0c84e6 */
if(!s->budget--) { s->failed_pc=0x0c0c84e6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c84e8;
P_0c0c84e8: /* original e307, guest PC 0x0c0c84e8 */
if(!s->budget--) { s->failed_pc=0x0c0c84e8u; return 0; }
r[3]=0x00000007u;
goto P_0c0c84ea;
P_0c0c84ea: /* original 0aed, guest PC 0x0c0c84ea */
if(!s->budget--) { s->failed_pc=0x0c0c84eau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c84ec;
P_0c0c84ec: /* original 7002, guest PC 0x0c0c84ec */
if(!s->budget--) { s->failed_pc=0x0c0c84ecu; return 0; }
r[0]+=0x00000002u;
goto P_0c0c84ee;
P_0c0c84ee: /* original 0e34, guest PC 0x0c0c84ee */
if(!s->budget--) { s->failed_pc=0x0c0c84eeu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c84f0;
P_0c0c84f0: /* original d31e, guest PC 0x0c0c84f0 */
if(!s->budget--) { s->failed_pc=0x0c0c84f0u; return 0; }
r[3]=read(ram,0x0c0c856cu,4);
goto P_0c0c84f2;
P_0c0c84f2: /* original 430b, guest PC 0x0c0c84f2 */
if(!s->budget--) { s->failed_pc=0x0c0c84f2u; return 0; }
target=r[3];
r[16]=0x0c0c84f6u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84f6u) { target=s->pc; goto dispatch; }
goto P_0c0c84f6;
P_0c0c84f4: /* original 64a3, guest PC 0x0c0c84f4 */
if(!s->budget--) { s->failed_pc=0x0c0c84f4u; return 0; }
r[4]=r[10];
goto P_0c0c84f6;
P_0c0c84f6: /* original d21b, guest PC 0x0c0c84f6 */
if(!s->budget--) { s->failed_pc=0x0c0c84f6u; return 0; }
r[2]=read(ram,0x0c0c8564u,4);
goto P_0c0c84f8;
P_0c0c84f8: /* original 420b, guest PC 0x0c0c84f8 */
if(!s->budget--) { s->failed_pc=0x0c0c84f8u; return 0; }
target=r[2];
r[16]=0x0c0c84fcu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84fcu) { target=s->pc; goto dispatch; }
goto P_0c0c84fc;
P_0c0c84fa: /* original 64a3, guest PC 0x0c0c84fa */
if(!s->budget--) { s->failed_pc=0x0c0c84fau; return 0; }
r[4]=r[10];
goto P_0c0c84fc;
P_0c0c84fc: /* original 600d, guest PC 0x0c0c84fc */
if(!s->budget--) { s->failed_pc=0x0c0c84fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c84fe;
P_0c0c84fe: /* original 2008, guest PC 0x0c0c84fe */
if(!s->budget--) { s->failed_pc=0x0c0c84feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c8500;
P_0c0c8500: /* original 896f, guest PC 0x0c0c8500 */
if(!s->budget--) { s->failed_pc=0x0c0c8500u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c8502;
P_0c0c8502: /* original 66d3, guest PC 0x0c0c8502 */
if(!s->budget--) { s->failed_pc=0x0c0c8502u; return 0; }
r[6]=r[13];
goto P_0c0c8504;
P_0c0c8504: /* original 2fc6, guest PC 0x0c0c8504 */
if(!s->budget--) { s->failed_pc=0x0c0c8504u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8506;
P_0c0c8506: /* original 9429, guest PC 0x0c0c8506 */
if(!s->budget--) { s->failed_pc=0x0c0c8506u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855cu,2);
goto P_0c0c8508;
P_0c0c8508: /* original 7658, guest PC 0x0c0c8508 */
if(!s->budget--) { s->failed_pc=0x0c0c8508u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c850a;
P_0c0c850a: /* original d719, guest PC 0x0c0c850a */
if(!s->budget--) { s->failed_pc=0x0c0c850au; return 0; }
r[7]=read(ram,0x0c0c8570u,4);
goto P_0c0c850c;
P_0c0c850c: /* original 4b0b, guest PC 0x0c0c850c */
if(!s->budget--) { s->failed_pc=0x0c0c850cu; return 0; }
target=r[11];
r[16]=0x0c0c8510u;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8510u) { target=s->pc; goto dispatch; }
goto P_0c0c8510;
P_0c0c850e: /* original 65a3, guest PC 0x0c0c850e */
if(!s->budget--) { s->failed_pc=0x0c0c850eu; return 0; }
r[5]=r[10];
goto P_0c0c8510;
P_0c0c8510: /* original a067, guest PC 0x0c0c8510 */
if(!s->budget--) { s->failed_pc=0x0c0c8510u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c85e2;
P_0c0c8512: /* original 7f04, guest PC 0x0c0c8512 */
if(!s->budget--) { s->failed_pc=0x0c0c8512u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8514;
P_0c0c8514: /* original 9023, guest PC 0x0c0c8514 */
if(!s->budget--) { s->failed_pc=0x0c0c8514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855eu,2);
goto P_0c0c8516;
P_0c0c8516: /* original 04ec, guest PC 0x0c0c8516 */
if(!s->budget--) { s->failed_pc=0x0c0c8516u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8518;
P_0c0c8518: /* original 4415, guest PC 0x0c0c8518 */
if(!s->budget--) { s->failed_pc=0x0c0c8518u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c851a;
P_0c0c851a: /* original 892b, guest PC 0x0c0c851a */
if(!s->budget--) { s->failed_pc=0x0c0c851au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8574; }
goto P_0c0c851c;
P_0c0c851c: /* original 6a93, guest PC 0x0c0c851c */
if(!s->budget--) { s->failed_pc=0x0c0c851cu; return 0; }
r[10]=r[9];
goto P_0c0c851e;
P_0c0c851e: /* original 7a44, guest PC 0x0c0c851e */
if(!s->budget--) { s->failed_pc=0x0c0c851eu; return 0; }
r[10]+=0x00000044u;
goto P_0c0c8520;
P_0c0c8520: /* original 62a2, guest PC 0x0c0c8520 */
if(!s->budget--) { s->failed_pc=0x0c0c8520u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0c8522;
P_0c0c8522: /* original 2228, guest PC 0x0c0c8522 */
if(!s->budget--) { s->failed_pc=0x0c0c8522u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c8524;
P_0c0c8524: /* original 8904, guest PC 0x0c0c8524 */
if(!s->budget--) { s->failed_pc=0x0c0c8524u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8530; }
goto P_0c0c8526;
P_0c0c8526: /* original d311, guest PC 0x0c0c8526 */
if(!s->budget--) { s->failed_pc=0x0c0c8526u; return 0; }
r[3]=read(ram,0x0c0c856cu,4);
goto P_0c0c8528;
P_0c0c8528: /* original 65d3, guest PC 0x0c0c8528 */
if(!s->budget--) { s->failed_pc=0x0c0c8528u; return 0; }
r[5]=r[13];
goto P_0c0c852a;
P_0c0c852a: /* original 7558, guest PC 0x0c0c852a */
if(!s->budget--) { s->failed_pc=0x0c0c852au; return 0; }
r[5]+=0x00000058u;
goto P_0c0c852c;
P_0c0c852c: /* original 430b, guest PC 0x0c0c852c */
if(!s->budget--) { s->failed_pc=0x0c0c852cu; return 0; }
target=r[3];
r[16]=0x0c0c8530u;
tmp=read(ram,r[10],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8530u) { target=s->pc; goto dispatch; }
goto P_0c0c8530;
P_0c0c852e: /* original 64a2, guest PC 0x0c0c852e */
if(!s->budget--) { s->failed_pc=0x0c0c852eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c8530;
P_0c0c8530: /* original 9012, guest PC 0x0c0c8530 */
if(!s->budget--) { s->failed_pc=0x0c0c8530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c8532;
P_0c0c8532: /* original 02ed, guest PC 0x0c0c8532 */
if(!s->budget--) { s->failed_pc=0x0c0c8532u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8534;
P_0c0c8534: /* original 2a22, guest PC 0x0c0c8534 */
if(!s->budget--) { s->failed_pc=0x0c0c8534u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c0c8536;
P_0c0c8536: /* original d30b, guest PC 0x0c0c8536 */
if(!s->budget--) { s->failed_pc=0x0c0c8536u; return 0; }
r[3]=read(ram,0x0c0c8564u,4);
goto P_0c0c8538;
P_0c0c8538: /* original 430b, guest PC 0x0c0c8538 */
if(!s->budget--) { s->failed_pc=0x0c0c8538u; return 0; }
target=r[3];
r[16]=0x0c0c853cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c853cu) { target=s->pc; goto dispatch; }
goto P_0c0c853c;
P_0c0c853a: /* original 04ed, guest PC 0x0c0c853a */
if(!s->budget--) { s->failed_pc=0x0c0c853au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c853c;
P_0c0c853c: /* original 600d, guest PC 0x0c0c853c */
if(!s->budget--) { s->failed_pc=0x0c0c853cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c853e;
P_0c0c853e: /* original 2008, guest PC 0x0c0c853e */
if(!s->budget--) { s->failed_pc=0x0c0c853eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c8540;
P_0c0c8540: /* original 894f, guest PC 0x0c0c8540 */
if(!s->budget--) { s->failed_pc=0x0c0c8540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c8542;
P_0c0c8542: /* original 66d3, guest PC 0x0c0c8542 */
if(!s->budget--) { s->failed_pc=0x0c0c8542u; return 0; }
r[6]=r[13];
goto P_0c0c8544;
P_0c0c8544: /* original 2fc6, guest PC 0x0c0c8544 */
if(!s->budget--) { s->failed_pc=0x0c0c8544u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8546;
P_0c0c8546: /* original 9007, guest PC 0x0c0c8546 */
if(!s->budget--) { s->failed_pc=0x0c0c8546u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c8548;
P_0c0c8548: /* original e700, guest PC 0x0c0c8548 */
if(!s->budget--) { s->failed_pc=0x0c0c8548u; return 0; }
r[7]=0x00000000u;
goto P_0c0c854a;
P_0c0c854a: /* original 9406, guest PC 0x0c0c854a */
if(!s->budget--) { s->failed_pc=0x0c0c854au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c854c;
P_0c0c854c: /* original 7658, guest PC 0x0c0c854c */
if(!s->budget--) { s->failed_pc=0x0c0c854cu; return 0; }
r[6]+=0x00000058u;
goto P_0c0c854e;
P_0c0c854e: /* original 4b0b, guest PC 0x0c0c854e */
if(!s->budget--) { s->failed_pc=0x0c0c854eu; return 0; }
target=r[11];
r[16]=0x0c0c8552u;
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8552u) { target=s->pc; goto dispatch; }
goto P_0c0c8552;
P_0c0c8550: /* original 05ed, guest PC 0x0c0c8550 */
if(!s->budget--) { s->failed_pc=0x0c0c8550u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8552;
P_0c0c8552: /* original a046, guest PC 0x0c0c8552 */
if(!s->budget--) { s->failed_pc=0x0c0c8552u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c85e2;
P_0c0c8554: /* original 7f04, guest PC 0x0c0c8554 */
if(!s->budget--) { s->failed_pc=0x0c0c8554u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0c8556u,s,ram);
P_0c0c8574: /* original e306, guest PC 0x0c0c8574 */
if(!s->budget--) { s->failed_pc=0x0c0c8574u; return 0; }
r[3]=0x00000006u;
goto P_0c0c8576;
P_0c0c8576: /* original 74ff, guest PC 0x0c0c8576 */
if(!s->budget--) { s->failed_pc=0x0c0c8576u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c8578;
P_0c0c8578: /* original 3348, guest PC 0x0c0c8578 */
if(!s->budget--) { s->failed_pc=0x0c0c8578u; return 0; }
r[3]-=r[4];
goto P_0c0c857a;
P_0c0c857a: /* original 0e44, guest PC 0x0c0c857a */
if(!s->budget--) { s->failed_pc=0x0c0c857au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c857c;
P_0c0c857c: /* original 6433, guest PC 0x0c0c857c */
if(!s->budget--) { s->failed_pc=0x0c0c857cu; return 0; }
r[4]=r[3];
goto P_0c0c857e;
P_0c0c857e: /* original 4408, guest PC 0x0c0c857e */
if(!s->budget--) { s->failed_pc=0x0c0c857eu; return 0; }
r[4]<<=2;
goto P_0c0c8580;
P_0c0c8580: /* original e91b, guest PC 0x0c0c8580 */
if(!s->budget--) { s->failed_pc=0x0c0c8580u; return 0; }
r[9]=0x0000001bu;
goto P_0c0c8582;
P_0c0c8582: /* original 6543, guest PC 0x0c0c8582 */
if(!s->budget--) { s->failed_pc=0x0c0c8582u; return 0; }
r[5]=r[4];
goto P_0c0c8584;
P_0c0c8584: /* original 3948, guest PC 0x0c0c8584 */
if(!s->budget--) { s->failed_pc=0x0c0c8584u; return 0; }
r[9]-=r[4];
goto P_0c0c8586;
P_0c0c8586: /* original d72a, guest PC 0x0c0c8586 */
if(!s->budget--) { s->failed_pc=0x0c0c8586u; return 0; }
r[7]=read(ram,0x0c0c8630u,4);
goto P_0c0c8588;
P_0c0c8588: /* original 7504, guest PC 0x0c0c8588 */
if(!s->budget--) { s->failed_pc=0x0c0c8588u; return 0; }
r[5]+=0x00000004u;
goto P_0c0c858a;
P_0c0c858a: /* original 6693, guest PC 0x0c0c858a */
if(!s->budget--) { s->failed_pc=0x0c0c858au; return 0; }
r[6]=r[9];
goto P_0c0c858c;
P_0c0c858c: /* original 70fe, guest PC 0x0c0c858c */
if(!s->budget--) { s->failed_pc=0x0c0c858cu; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c858e;
P_0c0c858e: /* original 0aed, guest PC 0x0c0c858e */
if(!s->budget--) { s->failed_pc=0x0c0c858eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8590;
P_0c0c8590: /* original 4518, guest PC 0x0c0c8590 */
if(!s->budget--) { s->failed_pc=0x0c0c8590u; return 0; }
r[5]<<=8;
goto P_0c0c8592;
P_0c0c8592: /* original 4628, guest PC 0x0c0c8592 */
if(!s->budget--) { s->failed_pc=0x0c0c8592u; return 0; }
r[6]<<=16;
goto P_0c0c8594;
P_0c0c8594: /* original 6053, guest PC 0x0c0c8594 */
if(!s->budget--) { s->failed_pc=0x0c0c8594u; return 0; }
r[0]=r[5];
goto P_0c0c8596;
P_0c0c8596: /* original 4618, guest PC 0x0c0c8596 */
if(!s->budget--) { s->failed_pc=0x0c0c8596u; return 0; }
r[6]<<=8;
goto P_0c0c8598;
P_0c0c8598: /* original 206b, guest PC 0x0c0c8598 */
if(!s->budget--) { s->failed_pc=0x0c0c8598u; return 0; }
r[0]|=r[6];
goto P_0c0c859a;
P_0c0c859a: /* original cb18, guest PC 0x0c0c859a */
if(!s->budget--) { s->failed_pc=0x0c0c859au; return 0; }
r[0]|=24u;
goto P_0c0c859c;
P_0c0c859c: /* original 2f02, guest PC 0x0c0c859c */
if(!s->budget--) { s->failed_pc=0x0c0c859cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c859e;
P_0c0c859e: /* original 6053, guest PC 0x0c0c859e */
if(!s->budget--) { s->failed_pc=0x0c0c859eu; return 0; }
r[0]=r[5];
goto P_0c0c85a0;
P_0c0c85a0: /* original 207b, guest PC 0x0c0c85a0 */
if(!s->budget--) { s->failed_pc=0x0c0c85a0u; return 0; }
r[0]|=r[7];
goto P_0c0c85a2;
P_0c0c85a2: /* original cb18, guest PC 0x0c0c85a2 */
if(!s->budget--) { s->failed_pc=0x0c0c85a2u; return 0; }
r[0]|=24u;
goto P_0c0c85a4;
P_0c0c85a4: /* original 1f01, guest PC 0x0c0c85a4 */
if(!s->budget--) { s->failed_pc=0x0c0c85a4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0c85a6;
P_0c0c85a6: /* original d323, guest PC 0x0c0c85a6 */
if(!s->budget--) { s->failed_pc=0x0c0c85a6u; return 0; }
r[3]=read(ram,0x0c0c8634u,4);
goto P_0c0c85a8;
P_0c0c85a8: /* original 430b, guest PC 0x0c0c85a8 */
if(!s->budget--) { s->failed_pc=0x0c0c85a8u; return 0; }
target=r[3];
r[16]=0x0c0c85acu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c85acu) { target=s->pc; goto dispatch; }
goto P_0c0c85ac;
P_0c0c85aa: /* original 64a3, guest PC 0x0c0c85aa */
if(!s->budget--) { s->failed_pc=0x0c0c85aau; return 0; }
r[4]=r[10];
goto P_0c0c85ac;
P_0c0c85ac: /* original 600d, guest PC 0x0c0c85ac */
if(!s->budget--) { s->failed_pc=0x0c0c85acu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c85ae;
P_0c0c85ae: /* original 2008, guest PC 0x0c0c85ae */
if(!s->budget--) { s->failed_pc=0x0c0c85aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c85b0;
P_0c0c85b0: /* original 8917, guest PC 0x0c0c85b0 */
if(!s->budget--) { s->failed_pc=0x0c0c85b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c85b2;
P_0c0c85b2: /* original d321, guest PC 0x0c0c85b2 */
if(!s->budget--) { s->failed_pc=0x0c0c85b2u; return 0; }
r[3]=read(ram,0x0c0c8638u,4);
goto P_0c0c85b4;
P_0c0c85b4: /* original 65d3, guest PC 0x0c0c85b4 */
if(!s->budget--) { s->failed_pc=0x0c0c85b4u; return 0; }
r[5]=r[13];
goto P_0c0c85b6;
P_0c0c85b6: /* original 7558, guest PC 0x0c0c85b6 */
if(!s->budget--) { s->failed_pc=0x0c0c85b6u; return 0; }
r[5]+=0x00000058u;
goto P_0c0c85b8;
P_0c0c85b8: /* original 430b, guest PC 0x0c0c85b8 */
if(!s->budget--) { s->failed_pc=0x0c0c85b8u; return 0; }
target=r[3];
r[16]=0x0c0c85bcu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c85bcu) { target=s->pc; goto dispatch; }
goto P_0c0c85bc;
P_0c0c85ba: /* original 64a3, guest PC 0x0c0c85ba */
if(!s->budget--) { s->failed_pc=0x0c0c85bau; return 0; }
r[4]=r[10];
goto P_0c0c85bc;
P_0c0c85bc: /* original 9232, guest PC 0x0c0c85bc */
if(!s->budget--) { s->failed_pc=0x0c0c85bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8624u,2);
goto P_0c0c85be;
P_0c0c85be: /* original 4900, guest PC 0x0c0c85be */
if(!s->budget--) { s->failed_pc=0x0c0c85beu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0c85c0;
P_0c0c85c0: /* original 66d3, guest PC 0x0c0c85c0 */
if(!s->budget--) { s->failed_pc=0x0c0c85c0u; return 0; }
r[6]=r[13];
goto P_0c0c85c2;
P_0c0c85c2: /* original 65a3, guest PC 0x0c0c85c2 */
if(!s->budget--) { s->failed_pc=0x0c0c85c2u; return 0; }
r[5]=r[10];
goto P_0c0c85c4;
P_0c0c85c4: /* original 292b, guest PC 0x0c0c85c4 */
if(!s->budget--) { s->failed_pc=0x0c0c85c4u; return 0; }
r[9]|=r[2];
goto P_0c0c85c6;
P_0c0c85c6: /* original 1f92, guest PC 0x0c0c85c6 */
if(!s->budget--) { s->failed_pc=0x0c0c85c6u; return 0; }
write(ram,r[15]+8,r[9],4);
goto P_0c0c85c8;
P_0c0c85c8: /* original 7658, guest PC 0x0c0c85c8 */
if(!s->budget--) { s->failed_pc=0x0c0c85c8u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c85ca;
P_0c0c85ca: /* original 2fc6, guest PC 0x0c0c85ca */
if(!s->budget--) { s->failed_pc=0x0c0c85cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85cc;
P_0c0c85cc: /* original 57f1, guest PC 0x0c0c85cc */
if(!s->budget--) { s->failed_pc=0x0c0c85ccu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0c85ce;
P_0c0c85ce: /* original 4b0b, guest PC 0x0c0c85ce */
if(!s->budget--) { s->failed_pc=0x0c0c85ceu; return 0; }
target=r[11];
r[16]=0x0c0c85d2u;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c85d2u) { target=s->pc; goto dispatch; }
goto P_0c0c85d2;
P_0c0c85d0: /* original 54f3, guest PC 0x0c0c85d0 */
if(!s->budget--) { s->failed_pc=0x0c0c85d0u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0c85d2;
P_0c0c85d2: /* original 2fc6, guest PC 0x0c0c85d2 */
if(!s->budget--) { s->failed_pc=0x0c0c85d2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85d4;
P_0c0c85d4: /* original 66d3, guest PC 0x0c0c85d4 */
if(!s->budget--) { s->failed_pc=0x0c0c85d4u; return 0; }
r[6]=r[13];
goto P_0c0c85d6;
P_0c0c85d6: /* original 9426, guest PC 0x0c0c85d6 */
if(!s->budget--) { s->failed_pc=0x0c0c85d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8626u,2);
goto P_0c0c85d8;
P_0c0c85d8: /* original 7658, guest PC 0x0c0c85d8 */
if(!s->budget--) { s->failed_pc=0x0c0c85d8u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c85da;
P_0c0c85da: /* original 57f3, guest PC 0x0c0c85da */
if(!s->budget--) { s->failed_pc=0x0c0c85dau; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c0c85dc;
P_0c0c85dc: /* original 4b0b, guest PC 0x0c0c85dc */
if(!s->budget--) { s->failed_pc=0x0c0c85dcu; return 0; }
target=r[11];
r[16]=0x0c0c85e0u;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c85e0u) { target=s->pc; goto dispatch; }
goto P_0c0c85e0;
P_0c0c85de: /* original 65a3, guest PC 0x0c0c85de */
if(!s->budget--) { s->failed_pc=0x0c0c85deu; return 0; }
r[5]=r[10];
goto P_0c0c85e0;
P_0c0c85e0: /* original 7f08, guest PC 0x0c0c85e0 */
if(!s->budget--) { s->failed_pc=0x0c0c85e0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c85e2;
P_0c0c85e2: /* original 9022, guest PC 0x0c0c85e2 */
if(!s->budget--) { s->failed_pc=0x0c0c85e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862au,2);
goto P_0c0c85e4;
P_0c0c85e4: /* original 9420, guest PC 0x0c0c85e4 */
if(!s->budget--) { s->failed_pc=0x0c0c85e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8628u,2);
goto P_0c0c85e6;
P_0c0c85e6: /* original 00ec, guest PC 0x0c0c85e6 */
if(!s->budget--) { s->failed_pc=0x0c0c85e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c85e8;
P_0c0c85e8: /* original 600c, guest PC 0x0c0c85e8 */
if(!s->budget--) { s->failed_pc=0x0c0c85e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c85ea;
P_0c0c85ea: /* original 8801, guest PC 0x0c0c85ea */
if(!s->budget--) { s->failed_pc=0x0c0c85eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c85ec;
P_0c0c85ec: /* original 8903, guest PC 0x0c0c85ec */
if(!s->budget--) { s->failed_pc=0x0c0c85ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85f6; }
goto P_0c0c85ee;
P_0c0c85ee: /* original 50f4, guest PC 0x0c0c85ee */
if(!s->budget--) { s->failed_pc=0x0c0c85eeu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c85f0;
P_0c0c85f0: /* original 6002, guest PC 0x0c0c85f0 */
if(!s->budget--) { s->failed_pc=0x0c0c85f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0c85f2;
P_0c0c85f2: /* original c810, guest PC 0x0c0c85f2 */
if(!s->budget--) { s->failed_pc=0x0c0c85f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0c85f4;
P_0c0c85f4: /* original 8b07, guest PC 0x0c0c85f4 */
if(!s->budget--) { s->failed_pc=0x0c0c85f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8606; }
goto P_0c0c85f6;
P_0c0c85f6: /* original 2fc6, guest PC 0x0c0c85f6 */
if(!s->budget--) { s->failed_pc=0x0c0c85f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85f8;
P_0c0c85f8: /* original e700, guest PC 0x0c0c85f8 */
if(!s->budget--) { s->failed_pc=0x0c0c85f8u; return 0; }
r[7]=0x00000000u;
goto P_0c0c85fa;
P_0c0c85fa: /* original 9517, guest PC 0x0c0c85fa */
if(!s->budget--) { s->failed_pc=0x0c0c85fau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862cu,2);
goto P_0c0c85fc;
P_0c0c85fc: /* original 9414, guest PC 0x0c0c85fc */
if(!s->budget--) { s->failed_pc=0x0c0c85fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8628u,2);
goto P_0c0c85fe;
P_0c0c85fe: /* original 4b0b, guest PC 0x0c0c85fe */
if(!s->budget--) { s->failed_pc=0x0c0c85feu; return 0; }
target=r[11];
r[16]=0x0c0c8602u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8602u) { target=s->pc; goto dispatch; }
goto P_0c0c8602;
P_0c0c8600: /* original 66d3, guest PC 0x0c0c8600 */
if(!s->budget--) { s->failed_pc=0x0c0c8600u; return 0; }
r[6]=r[13];
goto P_0c0c8602;
P_0c0c8602: /* original a005, guest PC 0x0c0c8602 */
if(!s->budget--) { s->failed_pc=0x0c0c8602u; return 0; }
goto P_0c0c8610;
P_0c0c8604: /* original 0009, guest PC 0x0c0c8604 */
if(!s->budget--) { s->failed_pc=0x0c0c8604u; return 0; }
goto P_0c0c8606;
P_0c0c8606: /* original e700, guest PC 0x0c0c8606 */
if(!s->budget--) { s->failed_pc=0x0c0c8606u; return 0; }
r[7]=0x00000000u;
goto P_0c0c8608;
P_0c0c8608: /* original 2fc6, guest PC 0x0c0c8608 */
if(!s->budget--) { s->failed_pc=0x0c0c8608u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c860a;
P_0c0c860a: /* original 950f, guest PC 0x0c0c860a */
if(!s->budget--) { s->failed_pc=0x0c0c860au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862cu,2);
goto P_0c0c860c;
P_0c0c860c: /* original 480b, guest PC 0x0c0c860c */
if(!s->budget--) { s->failed_pc=0x0c0c860cu; return 0; }
target=r[8];
r[16]=0x0c0c8610u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8610u) { target=s->pc; goto dispatch; }
goto P_0c0c8610;
P_0c0c860e: /* original 66d3, guest PC 0x0c0c860e */
if(!s->budget--) { s->failed_pc=0x0c0c860eu; return 0; }
r[6]=r[13];
goto P_0c0c8610;
P_0c0c8610: /* original 7f1c, guest PC 0x0c0c8610 */
if(!s->budget--) { s->failed_pc=0x0c0c8610u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0c8612;
P_0c0c8612: /* original 4f26, guest PC 0x0c0c8612 */
if(!s->budget--) { s->failed_pc=0x0c0c8612u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8614;
P_0c0c8614: /* original 68f6, guest PC 0x0c0c8614 */
if(!s->budget--) { s->failed_pc=0x0c0c8614u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c8616;
P_0c0c8616: /* original 69f6, guest PC 0x0c0c8616 */
if(!s->budget--) { s->failed_pc=0x0c0c8616u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c8618;
P_0c0c8618: /* original 6af6, guest PC 0x0c0c8618 */
if(!s->budget--) { s->failed_pc=0x0c0c8618u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c861a;
P_0c0c861a: /* original 6bf6, guest PC 0x0c0c861a */
if(!s->budget--) { s->failed_pc=0x0c0c861au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c861c;
P_0c0c861c: /* original 6cf6, guest PC 0x0c0c861c */
if(!s->budget--) { s->failed_pc=0x0c0c861cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c861e;
P_0c0c861e: /* original 6df6, guest PC 0x0c0c861e */
if(!s->budget--) { s->failed_pc=0x0c0c861eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8620;
P_0c0c8620: /* original 000b, guest PC 0x0c0c8620 */
if(!s->budget--) { s->failed_pc=0x0c0c8620u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c8622: /* original 6ef6, guest PC 0x0c0c8622 */
if(!s->budget--) { s->failed_pc=0x0c0c8622u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c8624u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c034a02u,0x0c034a04u,0x0c034a06u,0x0c034a08u,0x0c034a0au,0x0c034a0cu,0x0c034a0eu,0x0c034a10u,0x0c034a12u,0x0c034a14u,0x0c034a16u,0x0c034a18u,0x0c034a1au,0x0c034a1cu,0x0c034a1eu,0x0c03667eu,
0x0c036680u,0x0c036682u,0x0c036684u,0x0c036686u,0x0c036688u,0x0c0366b2u,0x0c0366b4u,0x0c0366b6u,0x0c0366b8u,0x0c0366bau,0x0c0366c6u,0x0c0366c8u,0x0c0366cau,0x0c0366ccu,0x0c0366ceu,0x0c0366f2u,
0x0c0366f4u,0x0c0366f6u,0x0c0366f8u,0x0c0366fau,0x0c036706u,0x0c036708u,0x0c03670au,0x0c03670cu,0x0c03670eu,0x0c03671au,0x0c03671cu,0x0c03671eu,0x0c036720u,0x0c036722u,0x0c036724u,0x0c036726u,
0x0c036728u,0x0c03673eu,0x0c036740u,0x0c036742u,0x0c036744u,0x0c036746u,0x0c036752u,0x0c036754u,0x0c036756u,0x0c036758u,0x0c03675au,0x0c038b4eu,0x0c038b50u,0x0c038b52u,0x0c038b54u,0x0c038b56u,
0x0c038b58u,0x0c038b60u,0x0c038b62u,0x0c038b64u,0x0c038b66u,0x0c038b68u,0x0c038b6au,0x0c038b6cu,0x0c038b6eu,0x0c038b70u,0x0c038b72u,0x0c038b74u,0x0c038b76u,0x0c038b78u,0x0c038b7au,0x0c038b7cu,
0x0c038b7eu,0x0c038b80u,0x0c038b82u,0x0c038b90u,0x0c038b92u,0x0c038b94u,0x0c038b96u,0x0c038b98u,0x0c038b9au,0x0c038b9cu,0x0c038b9eu,0x0c038ba0u,0x0c038ba2u,0x0c038ba4u,0x0c038ba6u,0x0c038ba8u,
0x0c038baau,0x0c038bacu,0x0c038baeu,0x0c038bb0u,0x0c038bb2u,0x0c038bb4u,0x0c03a190u,0x0c03a192u,0x0c03a194u,0x0c03a196u,0x0c03a198u,0x0c03a19au,0x0c03a19cu,0x0c03a19eu,0x0c03a1a0u,0x0c03a1a2u,
0x0c03a1a4u,0x0c03c6f0u,0x0c03c6f2u,0x0c03c6f4u,0x0c03c6f6u,0x0c03c6f8u,0x0c03c6fau,0x0c03c6fcu,0x0c03c6feu,0x0c03c700u,0x0c03c702u,0x0c03c704u,0x0c03c706u,0x0c03c708u,0x0c03c70au,0x0c03c70cu,
0x0c03c70eu,0x0c03c710u,0x0c03c712u,0x0c03c714u,0x0c03c716u,0x0c03c850u,0x0c03c852u,0x0c03c854u,0x0c03c856u,0x0c03c858u,0x0c03c85au,0x0c03c85cu,0x0c03c85eu,0x0c03c860u,0x0c03c862u,0x0c03c864u,
0x0c03c866u,0x0c03c868u,0x0c03c86au,0x0c03c86cu,0x0c03c86eu,0x0c03c870u,0x0c03c872u,0x0c03c910u,0x0c03c912u,0x0c03c914u,0x0c03c916u,0x0c03c918u,0x0c03c91au,0x0c03c91cu,0x0c03c91eu,0x0c03c920u,
0x0c03c922u,0x0c03c924u,0x0c03c926u,0x0c03c928u,0x0c03c92au,0x0c03c92cu,0x0c03c92eu,0x0c03c930u,0x0c03c932u,0x0c03c9d0u,0x0c03c9d2u,0x0c03c9d4u,0x0c03c9d6u,0x0c03c9d8u,0x0c03c9dau,0x0c03c9dcu,
0x0c03c9deu,0x0c03c9e0u,0x0c03c9e2u,0x0c03c9e4u,0x0c03c9e6u,0x0c03c9e8u,0x0c03c9eau,0x0c03c9ecu,0x0c03c9eeu,0x0c03c9f0u,0x0c03c9f2u,0x0c03ca00u,0x0c03ca02u,0x0c03ca04u,0x0c03ca06u,0x0c03ca08u,
0x0c03ca0au,0x0c03ca0cu,0x0c03ca0eu,0x0c03ca10u,0x0c03ca12u,0x0c03ca14u,0x0c03ca16u,0x0c03ca18u,0x0c03ca1au,0x0c03ca1cu,0x0c03ca1eu,0x0c03ca20u,0x0c03ca22u,0x0c03ca24u,0x0c03ca26u,0x0c03ca28u,
0x0c03ca2au,0x0c03ca2cu,0x0c03ca2eu,0x0c03ca30u,0x0c03ca32u,0x0c03ca34u,0x0c03ca36u,0x0c03ca38u,0x0c03ca3au,0x0c03ca3cu,0x0c03ca3eu,0x0c03ca40u,0x0c03ca42u,0x0c03ca44u,0x0c03ca46u,0x0c03ca48u,
0x0c03ca4au,0x0c03ca4cu,0x0c03ca4eu,0x0c03ca50u,0x0c03ca52u,0x0c03ca54u,0x0c03ca56u,0x0c03ca58u,0x0c03ca5au,0x0c03ca5cu,0x0c03ca5eu,0x0c03ca60u,0x0c03ca62u,0x0c03ca64u,0x0c03ca66u,0x0c03ca68u,
0x0c03ca6au,0x0c03ca6cu,0x0c03ca6eu,0x0c03ca70u,0x0c03ca72u,0x0c03ca74u,0x0c03ca76u,0x0c03ca78u,0x0c03ca7au,0x0c03ca7cu,0x0c03ca7eu,0x0c03ca80u,0x0c03ca82u,0x0c03ca84u,0x0c03ca86u,0x0c03ca88u,
0x0c03ca8au,0x0c03ca8cu,0x0c03ca8eu,0x0c03ca90u,0x0c03ca92u,0x0c03ca94u,0x0c03ca96u,0x0c03ca98u,0x0c03ca9au,0x0c03ca9cu,0x0c03ca9eu,0x0c03caa0u,0x0c03caa2u,0x0c03caa4u,0x0c03caa6u,0x0c03caa8u,
0x0c03caaau,0x0c03caacu,0x0c03caaeu,0x0c03cab0u,0x0c03cab2u,0x0c03cab4u,0x0c03cab6u,0x0c03cab8u,0x0c03cabau,0x0c03cabcu,0x0c03cabeu,0x0c03e760u,0x0c03e762u,0x0c03e764u,0x0c03e766u,0x0c03e768u,
0x0c03e76au,0x0c03e76cu,0x0c03e76eu,0x0c03e770u,0x0c03e772u,0x0c03e774u,0x0c03e776u,0x0c03e778u,0x0c03e77au,0x0c03e77cu,0x0c03e77eu,0x0c03e780u,0x0c03e782u,0x0c03e784u,0x0c03e786u,0x0c03e7c0u,
0x0c03e7c2u,0x0c03e7c4u,0x0c03e7c6u,0x0c03e7c8u,0x0c03e7cau,0x0c03e7ccu,0x0c03e7ceu,0x0c03e7d0u,0x0c03e7d2u,0x0c03e7d4u,0x0c03e7d6u,0x0c03e7d8u,0x0c03e7dau,0x0c03e7dcu,0x0c03e7deu,0x0c03e7e0u,
0x0c04236au,0x0c04236cu,0x0c04236eu,0x0c042370u,0x0c042372u,0x0c042374u,0x0c042376u,0x0c042378u,0x0c04237au,0x0c04237cu,0x0c04237eu,0x0c042380u,0x0c042382u,0x0c042384u,0x0c042386u,0x0c042388u,
0x0c04238au,0x0c04238cu,0x0c04238eu,0x0c042390u,0x0c042392u,0x0c042394u,0x0c042396u,0x0c042398u,0x0c04239au,0x0c04239cu,0x0c04239eu,0x0c0423a0u,0x0c0423a2u,0x0c0430f0u,0x0c0430f2u,0x0c0430f4u,
0x0c0430f6u,0x0c0430f8u,0x0c0430fau,0x0c0443f2u,0x0c0443f4u,0x0c0443f6u,0x0c0443f8u,0x0c0443fau,0x0c0443fcu,0x0c0443feu,0x0c044400u,0x0c044402u,0x0c044404u,0x0c044406u,0x0c044408u,0x0c04440au,
0x0c04440cu,0x0c04440eu,0x0c044410u,0x0c044412u,0x0c044414u,0x0c044416u,0x0c044418u,0x0c04441au,0x0c04441cu,0x0c04441eu,0x0c044420u,0x0c044422u,0x0c044424u,0x0c044426u,0x0c044428u,0x0c04442au,
0x0c04442cu,0x0c04442eu,0x0c044430u,0x0c044432u,0x0c044434u,0x0c044436u,0x0c044438u,0x0c04443au,0x0c04443cu,0x0c04443eu,0x0c044440u,0x0c044442u,0x0c044444u,0x0c044446u,0x0c044448u,0x0c04444au,
0x0c04444cu,0x0c04444eu,0x0c044450u,0x0c044452u,0x0c044454u,0x0c044456u,0x0c044458u,0x0c04445au,0x0c04445cu,0x0c04445eu,0x0c044460u,0x0c044462u,0x0c044464u,0x0c044466u,0x0c044468u,0x0c04446au,
0x0c04446cu,0x0c04446eu,0x0c044470u,0x0c044472u,0x0c044474u,0x0c044476u,0x0c044478u,0x0c04447au,0x0c04447cu,0x0c04447eu,0x0c044480u,0x0c044482u,0x0c045f62u,0x0c045f64u,0x0c045f66u,0x0c045f68u,
0x0c045f6au,0x0c045f6cu,0x0c045f6eu,0x0c045f70u,0x0c045f72u,0x0c045f74u,0x0c045f76u,0x0c045f78u,0x0c045f7au,0x0c045f7cu,0x0c04d4c2u,0x0c04d4c4u,0x0c04d4c6u,0x0c04d4c8u,0x0c04d4cau,0x0c04d4ccu,
0x0c04d4ceu,0x0c04d4d0u,0x0c04d4d2u,0x0c04d4d4u,0x0c04d4d6u,0x0c04d4d8u,0x0c04d4dau,0x0c04d4dcu,0x0c04d4deu,0x0c04d4e0u,0x0c04d4e2u,0x0c04d4e4u,0x0c04d4e6u,0x0c04d4e8u,0x0c04d4eau,0x0c04d4ecu,
0x0c04d4eeu,0x0c04d4f0u,0x0c04d4f2u,0x0c04d4f4u,0x0c04d4f6u,0x0c04d4f8u,0x0c04d4fau,0x0c04d4fcu,0x0c04d4feu,0x0c04d500u,0x0c04d502u,0x0c04d504u,0x0c04d506u,0x0c04d508u,0x0c04d50au,0x0c04f256u,
0x0c04f258u,0x0c04f25au,0x0c04f25cu,0x0c04f25eu,0x0c04f260u,0x0c04f262u,0x0c04f264u,0x0c04f266u,0x0c04f268u,0x0c04f26au,0x0c04f26cu,0x0c04f26eu,0x0c04f270u,0x0c04f272u,0x0c04f274u,0x0c04f276u,
0x0c04f278u,0x0c04f27au,0x0c04f27cu,0x0c04f27eu,0x0c04f280u,0x0c04f282u,0x0c04f284u,0x0c04f286u,0x0c04f288u,0x0c04f28au,0x0c04f28cu,0x0c04f28eu,0x0c04f290u,0x0c04f292u,0x0c04f294u,0x0c04f296u,
0x0c04f298u,0x0c04f29au,0x0c04f29cu,0x0c04f29eu,0x0c04f2a0u,0x0c04f2a2u,0x0c04f2b0u,0x0c04f2b2u,0x0c04f2b4u,0x0c04f2b6u,0x0c04f2b8u,0x0c04f2bau,0x0c04f2bcu,0x0c04f2beu,0x0c04f2c0u,0x0c04f2c2u,
0x0c04f2c4u,0x0c04f2c6u,0x0c04f2c8u,0x0c04f2cau,0x0c04f2ccu,0x0c04f2ceu,0x0c04f2d0u,0x0c04f2d2u,0x0c04f2d4u,0x0c04f2d6u,0x0c04f2d8u,0x0c04f2dau,0x0c04f2dcu,0x0c04f2deu,0x0c04f2e0u,0x0c04f2e2u,
0x0c04f2e4u,0x0c04f2e6u,0x0c04f2e8u,0x0c04f2eau,0x0c04f2ecu,0x0c04f2eeu,0x0c04f2f0u,0x0c04f2f2u,0x0c04f2f4u,0x0c04f2f6u,0x0c04f2f8u,0x0c04f2fau,0x0c058b80u,0x0c058b82u,0x0c058b84u,0x0c058b86u,
0x0c058b88u,0x0c058b8au,0x0c058b8cu,0x0c058b8eu,0x0c058b90u,0x0c058b92u,0x0c058b94u,0x0c058b96u,0x0c058b98u,0x0c058b9au,0x0c058b9cu,0x0c058b9eu,0x0c058ba0u,0x0c058ba2u,0x0c058ba4u,0x0c058bc0u,
0x0c058bc2u,0x0c058bc4u,0x0c058bc6u,0x0c058bc8u,0x0c058bcau,0x0c058bccu,0x0c058bceu,0x0c058bd0u,0x0c058bd2u,0x0c058bd4u,0x0c058bd6u,0x0c058bd8u,0x0c058bdau,0x0c058bdcu,0x0c058bdeu,0x0c058be0u,
0x0c058be2u,0x0c058be4u,0x0c058be6u,0x0c058be8u,0x0c058beau,0x0c058becu,0x0c058beeu,0x0c058bf0u,0x0c058bf2u,0x0c058bf4u,0x0c058bf6u,0x0c058bf8u,0x0c058bfau,0x0c058bfcu,0x0c058bfeu,0x0c058c00u,
0x0c058c02u,0x0c058c04u,0x0c058c06u,0x0c058c08u,0x0c058c0au,0x0c058c0cu,0x0c058c0eu,0x0c058c10u,0x0c058c12u,0x0c058c14u,0x0c058c16u,0x0c058c18u,0x0c058c1au,0x0c058c1cu,0x0c058c1eu,0x0c058c20u,
0x0c058c22u,0x0c058c24u,0x0c058c26u,0x0c058c28u,0x0c058c2au,0x0c058c2cu,0x0c058c2eu,0x0c058c30u,0x0c058c32u,0x0c058c34u,0x0c058c36u,0x0c058c38u,0x0c058c3au,0x0c058c3cu,0x0c058c3eu,0x0c058c40u,
0x0c058c42u,0x0c058c44u,0x0c058c46u,0x0c058c48u,0x0c058c4au,0x0c058c4cu,0x0c058c4eu,0x0c058c50u,0x0c058c52u,0x0c058c54u,0x0c058c56u,0x0c058c58u,0x0c058c5au,0x0c058c5cu,0x0c058c5eu,0x0c058c60u,
0x0c058c62u,0x0c058c64u,0x0c058c66u,0x0c058c68u,0x0c058c6au,0x0c058c6cu,0x0c058c6eu,0x0c058c70u,0x0c058c72u,0x0c058c74u,0x0c058c76u,0x0c058c78u,0x0c058c7au,0x0c058c7cu,0x0c058c7eu,0x0c058c80u,
0x0c058c82u,0x0c058c84u,0x0c058c86u,0x0c058c88u,0x0c058c8au,0x0c058c8cu,0x0c058c8eu,0x0c058c90u,0x0c058c92u,0x0c058c94u,0x0c058c96u,0x0c058c98u,0x0c058c9au,0x0c058c9cu,0x0c058c9eu,0x0c058ca0u,
0x0c058ca2u,0x0c058ca4u,0x0c058ca6u,0x0c058ca8u,0x0c058d70u,0x0c058d72u,0x0c058d74u,0x0c058d76u,0x0c058d78u,0x0c058d7au,0x0c058d7cu,0x0c058d7eu,0x0c058d80u,0x0c058d82u,0x0c058d84u,0x0c058d86u,
0x0c058d88u,0x0c058d8au,0x0c058d8cu,0x0c058d8eu,0x0c058d90u,0x0c058d92u,0x0c058d94u,0x0c058d96u,0x0c058d98u,0x0c058d9au,0x0c058d9cu,0x0c058d9eu,0x0c058da0u,0x0c058da2u,0x0c058da4u,0x0c058da6u,
0x0c058da8u,0x0c058daau,0x0c058dacu,0x0c058daeu,0x0c058db0u,0x0c058db2u,0x0c058db4u,0x0c058db6u,0x0c058db8u,0x0c058dbau,0x0c058dbcu,0x0c058dbeu,0x0c058dc0u,0x0c058dc2u,0x0c058dc4u,0x0c058dc6u,
0x0c058dc8u,0x0c058dcau,0x0c058dccu,0x0c058dceu,0x0c058dd0u,0x0c058dd2u,0x0c058dd4u,0x0c058dd6u,0x0c058dd8u,0x0c058ddau,0x0c058ddcu,0x0c058ddeu,0x0c058de0u,0x0c058de2u,0x0c058de4u,0x0c058de6u,
0x0c058de8u,0x0c058deau,0x0c058decu,0x0c058deeu,0x0c058df0u,0x0c058df2u,0x0c058df4u,0x0c058df6u,0x0c058df8u,0x0c058dfau,0x0c058dfcu,0x0c058dfeu,0x0c058e00u,0x0c058e02u,0x0c058e04u,0x0c058e06u,
0x0c058e08u,0x0c058e0au,0x0c058e0cu,0x0c058e0eu,0x0c058e10u,0x0c058e12u,0x0c058e14u,0x0c058e16u,0x0c058e18u,0x0c060d28u,0x0c060d2au,0x0c060d2cu,0x0c060d2eu,0x0c060d30u,0x0c060d32u,0x0c060d34u,
0x0c060d36u,0x0c060d38u,0x0c060d3au,0x0c060d3cu,0x0c060d3eu,0x0c060d40u,0x0c060d42u,0x0c060d44u,0x0c062e8eu,0x0c062e90u,0x0c062e92u,0x0c0804f6u,0x0c0804f8u,0x0c0804fau,0x0c0804fcu,0x0c0804feu,
0x0c080500u,0x0c080502u,0x0c080504u,0x0c080506u,0x0c080508u,0x0c08050au,0x0c08050cu,0x0c081d38u,0x0c081d3au,0x0c081d3cu,0x0c081d3eu,0x0c081d40u,0x0c081d42u,0x0c081d44u,0x0c081d46u,0x0c081d48u,
0x0c081d4au,0x0c081d4cu,0x0c081d4eu,0x0c081d50u,0x0c081d52u,0x0c081d54u,0x0c081d56u,0x0c081d58u,0x0c081d5au,0x0c081d5cu,0x0c081d5eu,0x0c081d60u,0x0c081d62u,0x0c081d64u,0x0c081d66u,0x0c081d68u,
0x0c081d6au,0x0c081d6cu,0x0c081d6eu,0x0c081d70u,0x0c081d72u,0x0c081d74u,0x0c081d76u,0x0c081d78u,0x0c081d7au,0x0c081d7cu,0x0c081d7eu,0x0c081d80u,0x0c081d82u,0x0c081d84u,0x0c081d86u,0x0c081d88u,
0x0c081d8au,0x0c081d8cu,0x0c081d8eu,0x0c081d90u,0x0c081d92u,0x0c081d94u,0x0c081d96u,0x0c081d98u,0x0c081d9au,0x0c081d9cu,0x0c081d9eu,0x0c081da0u,0x0c081da2u,0x0c081da4u,0x0c081da6u,0x0c081da8u,
0x0c081daau,0x0c081dacu,0x0c081daeu,0x0c081db0u,0x0c081db2u,0x0c081db4u,0x0c081db6u,0x0c081db8u,0x0c081dbau,0x0c081dbcu,0x0c081dbeu,0x0c081dc0u,0x0c081dc2u,0x0c081dc4u,0x0c081dc6u,0x0c081dc8u,
0x0c081dcau,0x0c081dccu,0x0c081dceu,0x0c081dd0u,0x0c081dd2u,0x0c081dd4u,0x0c081dd6u,0x0c081dd8u,0x0c081ddau,0x0c081ddcu,0x0c081ddeu,0x0c081de0u,0x0c081de2u,0x0c081de4u,0x0c081de6u,0x0c081de8u,
0x0c081deau,0x0c081decu,0x0c081deeu,0x0c081df0u,0x0c081df2u,0x0c081df4u,0x0c081df6u,0x0c081df8u,0x0c081dfau,0x0c081dfcu,0x0c081dfeu,0x0c081e00u,0x0c081e02u,0x0c081e04u,0x0c081e06u,0x0c081e08u,
0x0c081e0au,0x0c081e0cu,0x0c081e0eu,0x0c081e10u,0x0c081e12u,0x0c081e14u,0x0c081e16u,0x0c081e18u,0x0c081e1au,0x0c081e1cu,0x0c081e1eu,0x0c081e20u,0x0c081e22u,0x0c081e24u,0x0c081e26u,0x0c081e28u,
0x0c081e2au,0x0c081e2cu,0x0c081e2eu,0x0c081e30u,0x0c081e32u,0x0c081e34u,0x0c081e36u,0x0c081e38u,0x0c081e3au,0x0c081e3cu,0x0c081e3eu,0x0c083d70u,0x0c083d72u,0x0c083d74u,0x0c083d76u,0x0c083d78u,
0x0c083d7au,0x0c083d7cu,0x0c083d7eu,0x0c083d80u,0x0c083d82u,0x0c083d84u,0x0c083d86u,0x0c083d88u,0x0c083d8au,0x0c083d8cu,0x0c083d8eu,0x0c083d90u,0x0c083d92u,0x0c083d94u,0x0c083d96u,0x0c083d98u,
0x0c083d9au,0x0c083d9cu,0x0c083d9eu,0x0c083da0u,0x0c083da2u,0x0c083da4u,0x0c083da6u,0x0c08935au,0x0c08935cu,0x0c08935eu,0x0c089360u,0x0c089362u,0x0c089364u,0x0c089366u,0x0c089368u,0x0c08936au,
0x0c08936cu,0x0c08936eu,0x0c089370u,0x0c089372u,0x0c089374u,0x0c089376u,0x0c089378u,0x0c08937au,0x0c08937cu,0x0c08937eu,0x0c089380u,0x0c089382u,0x0c089384u,0x0c089386u,0x0c089388u,0x0c08938au,
0x0c08938cu,0x0c08938eu,0x0c089390u,0x0c089392u,0x0c089394u,0x0c089396u,0x0c089398u,0x0c08939au,0x0c08939cu,0x0c08939eu,0x0c0893a0u,0x0c0893a2u,0x0c0893a4u,0x0c0893a6u,0x0c0893a8u,0x0c0893aau,
0x0c0893acu,0x0c0893aeu,0x0c0893b0u,0x0c0893b2u,0x0c0893b4u,0x0c0893b6u,0x0c0893b8u,0x0c0893bau,0x0c0893bcu,0x0c0893beu,0x0c08a8e4u,0x0c08a8e6u,0x0c08a8e8u,0x0c08a8eau,0x0c08a8ecu,0x0c08a8eeu,
0x0c08a8f0u,0x0c08a8f2u,0x0c08a8f4u,0x0c08a8f6u,0x0c08a8f8u,0x0c08a8fau,0x0c08a8fcu,0x0c08a8feu,0x0c08a900u,0x0c08a902u,0x0c08a904u,0x0c08a906u,0x0c08a908u,0x0c08a90au,0x0c08a90cu,0x0c08a90eu,
0x0c08a910u,0x0c08a912u,0x0c08a914u,0x0c08a916u,0x0c08a918u,0x0c08a91au,0x0c08a91cu,0x0c08a91eu,0x0c08a920u,0x0c08a922u,0x0c08a924u,0x0c08a926u,0x0c08a928u,0x0c08b528u,0x0c08b52au,0x0c08b52cu,
0x0c08b52eu,0x0c08b530u,0x0c08b532u,0x0c08b534u,0x0c08b536u,0x0c08b538u,0x0c08b53au,0x0c08b53cu,0x0c08b53eu,0x0c08b540u,0x0c08b542u,0x0c096174u,0x0c096176u,0x0c096178u,0x0c09617au,0x0c09617cu,
0x0c09617eu,0x0c096180u,0x0c096182u,0x0c096184u,0x0c096186u,0x0c096188u,0x0c09618au,0x0c09618cu,0x0c09618eu,0x0c096190u,0x0c096192u,0x0c096194u,0x0c096196u,0x0c096198u,0x0c09619au,0x0c09619cu,
0x0c09619eu,0x0c0961a0u,0x0c0961a2u,0x0c09caccu,0x0c09caceu,0x0c09cad0u,0x0c09cad2u,0x0c09cad4u,0x0c09cad6u,0x0c09cad8u,0x0c09cadau,0x0c09cadcu,0x0c09cadeu,0x0c09cae0u,0x0c09cae2u,0x0c09cae4u,
0x0c09cae6u,0x0c09cae8u,0x0c09caeau,0x0c09caecu,0x0c09caeeu,0x0c09caf0u,0x0c09caf2u,0x0c09caf4u,0x0c09caf6u,0x0c09caf8u,0x0c09cafau,0x0c09cafcu,0x0c09cafeu,0x0c09cb00u,0x0c09cb02u,0x0c09cb04u,
0x0c09cb06u,0x0c09cb08u,0x0c09cb0au,0x0c09cb0cu,0x0c09cb0eu,0x0c09cb10u,0x0c09cb12u,0x0c09cb14u,0x0c09cb16u,0x0c09cb18u,0x0c09cb1au,0x0c09cb1cu,0x0c09cb1eu,0x0c09cb20u,0x0c09cb22u,0x0c09cb24u,
0x0c09cb26u,0x0c09cb28u,0x0c09cb2au,0x0c09cb2cu,0x0c09cb2eu,0x0c09cb30u,0x0c09cb32u,0x0c09cb34u,0x0c09cb36u,0x0c09cb38u,0x0c09cb50u,0x0c09cb52u,0x0c09cb54u,0x0c09cb56u,0x0c09cb58u,0x0c09cb5au,
0x0c09cb5cu,0x0c09cb5eu,0x0c09cb60u,0x0c09cb62u,0x0c09cb64u,0x0c09cb66u,0x0c09cb68u,0x0c09cb6au,0x0c09cb6cu,0x0c09cb6eu,0x0c09cb70u,0x0c09cb72u,0x0c09cb74u,0x0c09cb76u,0x0c09cb78u,0x0c09cb7au,
0x0c09cb7cu,0x0c09cb7eu,0x0c09cb80u,0x0c09cb82u,0x0c09cb84u,0x0c09cb86u,0x0c09cb88u,0x0c09cb8au,0x0c09cb8cu,0x0c09cb8eu,0x0c09cb90u,0x0c09cb92u,0x0c09cb94u,0x0c09cb96u,0x0c09cb98u,0x0c09cb9au,
0x0c09cb9cu,0x0c09cb9eu,0x0c09cba0u,0x0c09cba2u,0x0c09cba4u,0x0c09cba6u,0x0c09cba8u,0x0c09cbaau,0x0c09cbacu,0x0c09cbaeu,0x0c09cbb0u,0x0c09cbb2u,0x0c09cbb4u,0x0c09cbb6u,0x0c09cbb8u,0x0c09cbbau,
0x0c09cbbcu,0x0c09cbbeu,0x0c09cbc0u,0x0c09cbc2u,0x0c09cbc4u,0x0c09cbc6u,0x0c09cbc8u,0x0c09cbcau,0x0c09cbccu,0x0c09cbceu,0x0c09cbd0u,0x0c09cbd2u,0x0c09cbd4u,0x0c09cbd6u,0x0c09cbd8u,0x0c09cbdau,
0x0c09cbdcu,0x0c09cbdeu,0x0c09cbe0u,0x0c09cbe2u,0x0c09cbe4u,0x0c09cbe6u,0x0c09cbe8u,0x0c09cbeau,0x0c09cbecu,0x0c09cbeeu,0x0c09cbf0u,0x0c09cbf2u,0x0c09cbf4u,0x0c09cbf6u,0x0c09cbf8u,0x0c09cbfau,
0x0c09cbfcu,0x0c09cbfeu,0x0c09cc00u,0x0c09cc02u,0x0c09cc04u,0x0c09cc06u,0x0c09cc08u,0x0c09cc0au,0x0c09cc0cu,0x0c09cc0eu,0x0c09cc10u,0x0c09cc12u,0x0c09cc14u,0x0c09cc16u,0x0c09cc18u,0x0c09cc1au,
0x0c09cc1cu,0x0c09cc1eu,0x0c09cc30u,0x0c09cc32u,0x0c09cc34u,0x0c09cc36u,0x0c09cc38u,0x0c09cc3au,0x0c09cc3cu,0x0c09cc3eu,0x0c09cc40u,0x0c09cc42u,0x0c09cc44u,0x0c09cc46u,0x0c09cc48u,0x0c09cc4au,
0x0c09cc4cu,0x0c09cc4eu,0x0c09cc50u,0x0c09cc52u,0x0c09cc54u,0x0c09cc56u,0x0c09cc58u,0x0c09cc5au,0x0c09cc5cu,0x0c09cc5eu,0x0c09cc60u,0x0c09cc62u,0x0c09cc64u,0x0c09cc66u,0x0c09cc68u,0x0c09cc6au,
0x0c09cc6cu,0x0c09cc6eu,0x0c09cc70u,0x0c09cc72u,0x0c09cc74u,0x0c09cc76u,0x0c09cc78u,0x0c09cc7au,0x0c09cc7cu,0x0c09cc7eu,0x0c09cc80u,0x0c09cc82u,0x0c09cc84u,0x0c09cc86u,0x0c09cc88u,0x0c09cc8au,
0x0c09cc8cu,0x0c09cc8eu,0x0c09cc90u,0x0c09cc92u,0x0c09cc94u,0x0c09cc96u,0x0c09cc98u,0x0c09cc9au,0x0c09cc9cu,0x0c09cc9eu,0x0c09cca0u,0x0c09cca2u,0x0c09cca4u,0x0c09cca6u,0x0c09cca8u,0x0c09ccaau,
0x0c09ccacu,0x0c09ccaeu,0x0c09ccb0u,0x0c09ccb2u,0x0c09ccb4u,0x0c09ccb6u,0x0c09ccb8u,0x0c09ccbau,0x0c09ccbcu,0x0c09ccbeu,0x0c09ccc0u,0x0c09ccc2u,0x0c09ccc4u,0x0c09ccc6u,0x0c09ccc8u,0x0c09cccau,
0x0c09ccccu,0x0c09ccceu,0x0c09ccd0u,0x0c09ccd2u,0x0c09ccd4u,0x0c09ccd6u,0x0c09ccd8u,0x0c09ccdau,0x0c09ccdcu,0x0c09ccdeu,0x0c09cce0u,0x0c09cce2u,0x0c09cce4u,0x0c09cce6u,0x0c09cce8u,0x0c09cceau,
0x0c09ccecu,0x0c09cceeu,0x0c09ccf0u,0x0c09ccf2u,0x0c09ccf4u,0x0c09ccf6u,0x0c09ccf8u,0x0c09ccfau,0x0c09ccfcu,0x0c09ccfeu,0x0c09cd00u,0x0c09cd02u,0x0c09cd04u,0x0c09cd06u,0x0c09cd08u,0x0c09cd0au,
0x0c09cd0cu,0x0c09cd0eu,0x0c09cd10u,0x0c09cd12u,0x0c09cd38u,0x0c09cd3au,0x0c09cd3cu,0x0c09cd3eu,0x0c09cd40u,0x0c09cd42u,0x0c09cd44u,0x0c09cd46u,0x0c09cd48u,0x0c09cd4au,0x0c09cd4cu,0x0c09cd4eu,
0x0c09cd50u,0x0c09cd52u,0x0c09cd54u,0x0c09cd56u,0x0c09cd58u,0x0c09cd5au,0x0c09cd5cu,0x0c09cd5eu,0x0c09cd60u,0x0c09cd62u,0x0c09cd64u,0x0c09cd66u,0x0c09cd68u,0x0c09cd6au,0x0c09cd6cu,0x0c09cd6eu,
0x0c09cd70u,0x0c09cd72u,0x0c09cd74u,0x0c09cd76u,0x0c09cd78u,0x0c09cd7au,0x0c09cd7cu,0x0c09cd7eu,0x0c09cd80u,0x0c09cd82u,0x0c09cd84u,0x0c09cd86u,0x0c09cd88u,0x0c09cd8au,0x0c09cd8cu,0x0c09cd8eu,
0x0c09cd90u,0x0c09cd92u,0x0c09cd94u,0x0c09cd96u,0x0c09cd98u,0x0c09cd9au,0x0c09cd9cu,0x0c09cd9eu,0x0c09cda0u,0x0c09cda2u,0x0c09cda4u,0x0c09cda6u,0x0c09cda8u,0x0c09cdaau,0x0c09cdacu,0x0c09cdaeu,
0x0c09cdb0u,0x0c09cdb2u,0x0c09cdb4u,0x0c09cdb6u,0x0c09cdb8u,0x0c09cdbau,0x0c09cdbcu,0x0c09cdbeu,0x0c09cdc0u,0x0c09cdecu,0x0c09cdeeu,0x0c09cdf0u,0x0c09cdf2u,0x0c09cdf4u,0x0c09cdf6u,0x0c09cdf8u,
0x0c09cdfau,0x0c09cdfcu,0x0c09cdfeu,0x0c09ce00u,0x0c09ce02u,0x0c09ce04u,0x0c09ce06u,0x0c09ce08u,0x0c09ce0au,0x0c09ce0cu,0x0c09ce0eu,0x0c09ce10u,0x0c09ce12u,0x0c09ce14u,0x0c09ce16u,0x0c09ce18u,
0x0c09ce1au,0x0c09ce1cu,0x0c09ce1eu,0x0c09ce20u,0x0c09ce22u,0x0c09ce24u,0x0c09ce26u,0x0c09ce28u,0x0c09ce2au,0x0c09ce2cu,0x0c09ce2eu,0x0c09ce30u,0x0c09ce32u,0x0c09ce34u,0x0c09ce36u,0x0c09ce38u,
0x0c09ce3au,0x0c09ce3cu,0x0c09ce3eu,0x0c09ce40u,0x0c09ce42u,0x0c09ce44u,0x0c09ce46u,0x0c09ce48u,0x0c09ce4cu,0x0c09ce4eu,0x0c09ce50u,0x0c09ce52u,0x0c09ce54u,0x0c09ce56u,0x0c09ce58u,0x0c09ce5au,
0x0c09ce5cu,0x0c09ce5eu,0x0c09ce60u,0x0c09ce62u,0x0c09ce64u,0x0c09ce66u,0x0c09ce68u,0x0c09ce6au,0x0c09ce6cu,0x0c09ce6eu,0x0c09ce70u,0x0c09ce72u,0x0c09ce74u,0x0c09ce76u,0x0c09ce78u,0x0c09ce7au,
0x0c09ce7cu,0x0c09cf60u,0x0c09cf62u,0x0c09cf64u,0x0c09cf66u,0x0c09cf68u,0x0c09cf6au,0x0c09cf6cu,0x0c09cf6eu,0x0c09cf70u,0x0c09cf72u,0x0c09cf74u,0x0c09cf76u,0x0c09cf78u,0x0c09cf7au,0x0c09cf7cu,
0x0c09cf7eu,0x0c09cf80u,0x0c09cf82u,0x0c09cf84u,0x0c09cf86u,0x0c09cf88u,0x0c09cf8au,0x0c09cf8cu,0x0c09cf8eu,0x0c09cf90u,0x0c0a9452u,0x0c0a9454u,0x0c0a9456u,0x0c0a9458u,0x0c0a945au,0x0c0a945cu,
0x0c0a945eu,0x0c0a9460u,0x0c0a9462u,0x0c0a9464u,0x0c0a9466u,0x0c0a9468u,0x0c0a946au,0x0c0a946cu,0x0c0a946eu,0x0c0a9470u,0x0c0a9472u,0x0c0a9474u,0x0c0a9476u,0x0c0a9478u,0x0c0a947au,0x0c0a947cu,
0x0c0a947eu,0x0c0a9480u,0x0c0a9482u,0x0c0a9484u,0x0c0a9486u,0x0c0a9488u,0x0c0a948au,0x0c0a948cu,0x0c0a948eu,0x0c0a9490u,0x0c0a9492u,0x0c0a9494u,0x0c0a9496u,0x0c0a9498u,0x0c0a949au,0x0c0a949cu,
0x0c0a949eu,0x0c0a94a0u,0x0c0a94a2u,0x0c0a94a4u,0x0c0c2c88u,0x0c0c2c8au,0x0c0c2c8cu,0x0c0c2c8eu,0x0c0c2c90u,0x0c0c2c92u,0x0c0c2c94u,0x0c0c2c96u,0x0c0c2c98u,0x0c0c2c9au,0x0c0c2c9cu,0x0c0c2c9eu,
0x0c0c2ca0u,0x0c0c2ca2u,0x0c0c2ca4u,0x0c0c2ca6u,0x0c0c2ca8u,0x0c0c2caau,0x0c0c2cacu,0x0c0c2caeu,0x0c0c2cb0u,0x0c0c2cb2u,0x0c0c2cb4u,0x0c0c2cb6u,0x0c0c2cb8u,0x0c0c2cbau,0x0c0c2cbcu,0x0c0c2cbeu,
0x0c0c2cc0u,0x0c0c2cc2u,0x0c0c2cc4u,0x0c0c2cc6u,0x0c0c2cc8u,0x0c0c426cu,0x0c0c426eu,0x0c0c4270u,0x0c0c4272u,0x0c0c4274u,0x0c0c4276u,0x0c0c4278u,0x0c0c427au,0x0c0c427cu,0x0c0c427eu,0x0c0c4280u,
0x0c0c4282u,0x0c0c4284u,0x0c0c4286u,0x0c0c4288u,0x0c0c428au,0x0c0c428cu,0x0c0c428eu,0x0c0c4290u,0x0c0c4292u,0x0c0c4294u,0x0c0c4296u,0x0c0c4298u,0x0c0c429au,0x0c0c429cu,0x0c0c429eu,0x0c0c42a0u,
0x0c0c42a2u,0x0c0c42a4u,0x0c0c42a6u,0x0c0c42a8u,0x0c0c42aau,0x0c0c42acu,0x0c0c42aeu,0x0c0c42b0u,0x0c0c42b2u,0x0c0c42b4u,0x0c0c42b6u,0x0c0c42b8u,0x0c0c42bau,0x0c0c42bcu,0x0c0c42beu,0x0c0c42c0u,
0x0c0c42c2u,0x0c0c42c4u,0x0c0c42c6u,0x0c0c42c8u,0x0c0c42cau,0x0c0c42ccu,0x0c0c42ceu,0x0c0c42d0u,0x0c0c42d2u,0x0c0c42d4u,0x0c0c42d6u,0x0c0c42d8u,0x0c0c42dau,0x0c0c42dcu,0x0c0c42deu,0x0c0c42e0u,
0x0c0c42e2u,0x0c0c42e4u,0x0c0c42e6u,0x0c0c42e8u,0x0c0c42eau,0x0c0c82e6u,0x0c0c82e8u,0x0c0c82eau,0x0c0c82ecu,0x0c0c82eeu,0x0c0c82f0u,0x0c0c82f2u,0x0c0c82f4u,0x0c0c82f6u,0x0c0c82f8u,0x0c0c82fau,
0x0c0c82fcu,0x0c0c82feu,0x0c0c8300u,0x0c0c8302u,0x0c0c8304u,0x0c0c8306u,0x0c0c8308u,0x0c0c830au,0x0c0c830cu,0x0c0c830eu,0x0c0c8310u,0x0c0c8312u,0x0c0c8314u,0x0c0c8316u,0x0c0c8318u,0x0c0c831au,
0x0c0c831cu,0x0c0c831eu,0x0c0c8320u,0x0c0c8322u,0x0c0c8324u,0x0c0c8326u,0x0c0c8328u,0x0c0c832au,0x0c0c832cu,0x0c0c832eu,0x0c0c8330u,0x0c0c8332u,0x0c0c8334u,0x0c0c8336u,0x0c0c8338u,0x0c0c833au,
0x0c0c833cu,0x0c0c833eu,0x0c0c8340u,0x0c0c8342u,0x0c0c8344u,0x0c0c8346u,0x0c0c8348u,0x0c0c834au,0x0c0c834cu,0x0c0c834eu,0x0c0c8350u,0x0c0c8352u,0x0c0c8354u,0x0c0c8356u,0x0c0c8358u,0x0c0c835au,
0x0c0c835cu,0x0c0c835eu,0x0c0c8394u,0x0c0c8396u,0x0c0c8398u,0x0c0c839au,0x0c0c839cu,0x0c0c839eu,0x0c0c83a0u,0x0c0c83a2u,0x0c0c83a4u,0x0c0c83a6u,0x0c0c83a8u,0x0c0c83aau,0x0c0c83acu,0x0c0c83aeu,
0x0c0c83b0u,0x0c0c83b2u,0x0c0c83b4u,0x0c0c83b6u,0x0c0c83b8u,0x0c0c83bau,0x0c0c83bcu,0x0c0c83beu,0x0c0c83c0u,0x0c0c83c2u,0x0c0c83c4u,0x0c0c83c6u,0x0c0c83c8u,0x0c0c83cau,0x0c0c83ccu,0x0c0c83ceu,
0x0c0c83d0u,0x0c0c83d2u,0x0c0c83d4u,0x0c0c83d6u,0x0c0c83d8u,0x0c0c83dau,0x0c0c83dcu,0x0c0c83deu,0x0c0c83e0u,0x0c0c83e2u,0x0c0c83e4u,0x0c0c83e6u,0x0c0c83e8u,0x0c0c83eau,0x0c0c83ecu,0x0c0c83eeu,
0x0c0c83f0u,0x0c0c83f2u,0x0c0c83f4u,0x0c0c83f6u,0x0c0c83f8u,0x0c0c83fau,0x0c0c83fcu,0x0c0c83feu,0x0c0c8400u,0x0c0c8402u,0x0c0c8404u,0x0c0c8406u,0x0c0c8408u,0x0c0c840au,0x0c0c840cu,0x0c0c840eu,
0x0c0c8410u,0x0c0c8412u,0x0c0c8414u,0x0c0c8416u,0x0c0c8418u,0x0c0c841au,0x0c0c841cu,0x0c0c841eu,0x0c0c8420u,0x0c0c8422u,0x0c0c8424u,0x0c0c8426u,0x0c0c8428u,0x0c0c842au,0x0c0c842cu,0x0c0c842eu,
0x0c0c8430u,0x0c0c8432u,0x0c0c8434u,0x0c0c8436u,0x0c0c8438u,0x0c0c843au,0x0c0c843cu,0x0c0c843eu,0x0c0c8440u,0x0c0c8442u,0x0c0c8444u,0x0c0c8446u,0x0c0c8448u,0x0c0c844au,0x0c0c844cu,0x0c0c844eu,
0x0c0c8450u,0x0c0c8452u,0x0c0c8454u,0x0c0c8456u,0x0c0c8458u,0x0c0c845au,0x0c0c845cu,0x0c0c845eu,0x0c0c8460u,0x0c0c8462u,0x0c0c8464u,0x0c0c8466u,0x0c0c8468u,0x0c0c846au,0x0c0c846cu,0x0c0c846eu,
0x0c0c8470u,0x0c0c8472u,0x0c0c8494u,0x0c0c8496u,0x0c0c8498u,0x0c0c849au,0x0c0c849cu,0x0c0c849eu,0x0c0c84a0u,0x0c0c84a2u,0x0c0c84a4u,0x0c0c84a6u,0x0c0c84a8u,0x0c0c84aau,0x0c0c84acu,0x0c0c84aeu,
0x0c0c84b0u,0x0c0c84b2u,0x0c0c84b4u,0x0c0c84b6u,0x0c0c84b8u,0x0c0c84bau,0x0c0c84bcu,0x0c0c84beu,0x0c0c84c0u,0x0c0c84c2u,0x0c0c84c4u,0x0c0c84c6u,0x0c0c84c8u,0x0c0c84cau,0x0c0c84ccu,0x0c0c84ceu,
0x0c0c84d0u,0x0c0c84d2u,0x0c0c84d4u,0x0c0c84d6u,0x0c0c84d8u,0x0c0c84dau,0x0c0c84dcu,0x0c0c84deu,0x0c0c84e0u,0x0c0c84e2u,0x0c0c84e4u,0x0c0c84e6u,0x0c0c84e8u,0x0c0c84eau,0x0c0c84ecu,0x0c0c84eeu,
0x0c0c84f0u,0x0c0c84f2u,0x0c0c84f4u,0x0c0c84f6u,0x0c0c84f8u,0x0c0c84fau,0x0c0c84fcu,0x0c0c84feu,0x0c0c8500u,0x0c0c8502u,0x0c0c8504u,0x0c0c8506u,0x0c0c8508u,0x0c0c850au,0x0c0c850cu,0x0c0c850eu,
0x0c0c8510u,0x0c0c8512u,0x0c0c8514u,0x0c0c8516u,0x0c0c8518u,0x0c0c851au,0x0c0c851cu,0x0c0c851eu,0x0c0c8520u,0x0c0c8522u,0x0c0c8524u,0x0c0c8526u,0x0c0c8528u,0x0c0c852au,0x0c0c852cu,0x0c0c852eu,
0x0c0c8530u,0x0c0c8532u,0x0c0c8534u,0x0c0c8536u,0x0c0c8538u,0x0c0c853au,0x0c0c853cu,0x0c0c853eu,0x0c0c8540u,0x0c0c8542u,0x0c0c8544u,0x0c0c8546u,0x0c0c8548u,0x0c0c854au,0x0c0c854cu,0x0c0c854eu,
0x0c0c8550u,0x0c0c8552u,0x0c0c8554u,0x0c0c8574u,0x0c0c8576u,0x0c0c8578u,0x0c0c857au,0x0c0c857cu,0x0c0c857eu,0x0c0c8580u,0x0c0c8582u,0x0c0c8584u,0x0c0c8586u,0x0c0c8588u,0x0c0c858au,0x0c0c858cu,
0x0c0c858eu,0x0c0c8590u,0x0c0c8592u,0x0c0c8594u,0x0c0c8596u,0x0c0c8598u,0x0c0c859au,0x0c0c859cu,0x0c0c859eu,0x0c0c85a0u,0x0c0c85a2u,0x0c0c85a4u,0x0c0c85a6u,0x0c0c85a8u,0x0c0c85aau,0x0c0c85acu,
0x0c0c85aeu,0x0c0c85b0u,0x0c0c85b2u,0x0c0c85b4u,0x0c0c85b6u,0x0c0c85b8u,0x0c0c85bau,0x0c0c85bcu,0x0c0c85beu,0x0c0c85c0u,0x0c0c85c2u,0x0c0c85c4u,0x0c0c85c6u,0x0c0c85c8u,0x0c0c85cau,0x0c0c85ccu,
0x0c0c85ceu,0x0c0c85d0u,0x0c0c85d2u,0x0c0c85d4u,0x0c0c85d6u,0x0c0c85d8u,0x0c0c85dau,0x0c0c85dcu,0x0c0c85deu,0x0c0c85e0u,0x0c0c85e2u,0x0c0c85e4u,0x0c0c85e6u,0x0c0c85e8u,0x0c0c85eau,0x0c0c85ecu,
0x0c0c85eeu,0x0c0c85f0u,0x0c0c85f2u,0x0c0c85f4u,0x0c0c85f6u,0x0c0c85f8u,0x0c0c85fau,0x0c0c85fcu,0x0c0c85feu,0x0c0c8600u,0x0c0c8602u,0x0c0c8604u,0x0c0c8606u,0x0c0c8608u,0x0c0c860au,0x0c0c860cu,
0x0c0c860eu,0x0c0c8610u,0x0c0c8612u,0x0c0c8614u,0x0c0c8616u,0x0c0c8618u,0x0c0c861au,0x0c0c861cu,0x0c0c861eu,0x0c0c8620u,0x0c0c8622u,
};
int vf3_target_remaining_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
