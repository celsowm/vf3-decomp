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
int vf3_away_batch2_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03e430u: goto P_0c03e430;
case 0x0c03e432u: goto P_0c03e432;
case 0x0c03e434u: goto P_0c03e434;
case 0x0c03e436u: goto P_0c03e436;
case 0x0c03e438u: goto P_0c03e438;
case 0x0c03e43au: goto P_0c03e43a;
case 0x0c03e43cu: goto P_0c03e43c;
case 0x0c03e43eu: goto P_0c03e43e;
case 0x0c03e440u: goto P_0c03e440;
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
case 0x0c03e680u: goto P_0c03e680;
case 0x0c03e682u: goto P_0c03e682;
case 0x0c03e684u: goto P_0c03e684;
case 0x0c03e686u: goto P_0c03e686;
case 0x0c03e688u: goto P_0c03e688;
case 0x0c03e68au: goto P_0c03e68a;
case 0x0c03e68cu: goto P_0c03e68c;
case 0x0c03e68eu: goto P_0c03e68e;
case 0x0c03e690u: goto P_0c03e690;
case 0x0c03e692u: goto P_0c03e692;
case 0x0c03e694u: goto P_0c03e694;
case 0x0c03e696u: goto P_0c03e696;
case 0x0c03e698u: goto P_0c03e698;
case 0x0c03e69au: goto P_0c03e69a;
case 0x0c03e69cu: goto P_0c03e69c;
case 0x0c03e69eu: goto P_0c03e69e;
case 0x0c03e6a0u: goto P_0c03e6a0;
case 0x0c03e6a2u: goto P_0c03e6a2;
case 0x0c03e6a4u: goto P_0c03e6a4;
case 0x0c03e6a6u: goto P_0c03e6a6;
case 0x0c03e6a8u: goto P_0c03e6a8;
case 0x0c03e860u: goto P_0c03e860;
case 0x0c03e862u: goto P_0c03e862;
case 0x0c03e864u: goto P_0c03e864;
case 0x0c03e866u: goto P_0c03e866;
case 0x0c03e868u: goto P_0c03e868;
case 0x0c03e86au: goto P_0c03e86a;
case 0x0c03e86cu: goto P_0c03e86c;
case 0x0c03e86eu: goto P_0c03e86e;
case 0x0c03e870u: goto P_0c03e870;
case 0x0c03e872u: goto P_0c03e872;
case 0x0c03e874u: goto P_0c03e874;
case 0x0c03e876u: goto P_0c03e876;
case 0x0c03e878u: goto P_0c03e878;
case 0x0c03e87au: goto P_0c03e87a;
case 0x0c03e87cu: goto P_0c03e87c;
case 0x0c03e87eu: goto P_0c03e87e;
case 0x0c03e880u: goto P_0c03e880;
case 0x0c03e882u: goto P_0c03e882;
case 0x0c03e884u: goto P_0c03e884;
case 0x0c03e886u: goto P_0c03e886;
case 0x0c03e888u: goto P_0c03e888;
case 0x0c03e8c0u: goto P_0c03e8c0;
case 0x0c03e8c2u: goto P_0c03e8c2;
case 0x0c03e8c4u: goto P_0c03e8c4;
case 0x0c03e8c6u: goto P_0c03e8c6;
case 0x0c03e8c8u: goto P_0c03e8c8;
case 0x0c03e8cau: goto P_0c03e8ca;
case 0x0c03e8ccu: goto P_0c03e8cc;
case 0x0c03e8ceu: goto P_0c03e8ce;
case 0x0c03e8d0u: goto P_0c03e8d0;
case 0x0c03e8d2u: goto P_0c03e8d2;
case 0x0c03e8d4u: goto P_0c03e8d4;
case 0x0c03e8d6u: goto P_0c03e8d6;
case 0x0c03e8d8u: goto P_0c03e8d8;
case 0x0c03e8dau: goto P_0c03e8da;
case 0x0c03e8dcu: goto P_0c03e8dc;
case 0x0c03e8deu: goto P_0c03e8de;
case 0x0c03e8e0u: goto P_0c03e8e0;
case 0x0c03e8e2u: goto P_0c03e8e2;
case 0x0c03e8e4u: goto P_0c03e8e4;
case 0x0c03e8e6u: goto P_0c03e8e6;
case 0x0c03e8e8u: goto P_0c03e8e8;
case 0x0c03e8eau: goto P_0c03e8ea;
case 0x0c03e8ecu: goto P_0c03e8ec;
case 0x0c03e8eeu: goto P_0c03e8ee;
case 0x0c03e8f0u: goto P_0c03e8f0;
case 0x0c03e8f2u: goto P_0c03e8f2;
case 0x0c03e8f4u: goto P_0c03e8f4;
case 0x0c03e8f6u: goto P_0c03e8f6;
case 0x0c03e8f8u: goto P_0c03e8f8;
case 0x0c03e8fau: goto P_0c03e8fa;
case 0x0c03e8fcu: goto P_0c03e8fc;
case 0x0c03e8feu: goto P_0c03e8fe;
case 0x0c03e900u: goto P_0c03e900;
case 0x0c03e902u: goto P_0c03e902;
case 0x0c03e904u: goto P_0c03e904;
case 0x0c03e906u: goto P_0c03e906;
case 0x0c03e908u: goto P_0c03e908;
case 0x0c03e90au: goto P_0c03e90a;
case 0x0c03e90cu: goto P_0c03e90c;
case 0x0c03e90eu: goto P_0c03e90e;
case 0x0c03e910u: goto P_0c03e910;
case 0x0c03e912u: goto P_0c03e912;
case 0x0c03e914u: goto P_0c03e914;
case 0x0c03e916u: goto P_0c03e916;
case 0x0c03e918u: goto P_0c03e918;
case 0x0c03e91au: goto P_0c03e91a;
case 0x0c03e91cu: goto P_0c03e91c;
case 0x0c03e91eu: goto P_0c03e91e;
case 0x0c03e920u: goto P_0c03e920;
case 0x0c03e922u: goto P_0c03e922;
case 0x0c03e924u: goto P_0c03e924;
case 0x0c03e926u: goto P_0c03e926;
case 0x0c03e928u: goto P_0c03e928;
case 0x0c03e92au: goto P_0c03e92a;
case 0x0c03e92cu: goto P_0c03e92c;
case 0x0c03e92eu: goto P_0c03e92e;
case 0x0c03e930u: goto P_0c03e930;
case 0x0c03e932u: goto P_0c03e932;
case 0x0c03e934u: goto P_0c03e934;
case 0x0c03e936u: goto P_0c03e936;
case 0x0c03e938u: goto P_0c03e938;
case 0x0c03e93au: goto P_0c03e93a;
case 0x0c03e93cu: goto P_0c03e93c;
case 0x0c03e93eu: goto P_0c03e93e;
case 0x0c03e940u: goto P_0c03e940;
case 0x0c03e942u: goto P_0c03e942;
case 0x0c03e944u: goto P_0c03e944;
case 0x0c03e946u: goto P_0c03e946;
case 0x0c03e948u: goto P_0c03e948;
case 0x0c03e94au: goto P_0c03e94a;
case 0x0c03e94cu: goto P_0c03e94c;
case 0x0c03e94eu: goto P_0c03e94e;
case 0x0c03e950u: goto P_0c03e950;
case 0x0c03e952u: goto P_0c03e952;
case 0x0c03e954u: goto P_0c03e954;
case 0x0c03e956u: goto P_0c03e956;
case 0x0c03e958u: goto P_0c03e958;
case 0x0c03e95au: goto P_0c03e95a;
case 0x0c03e95cu: goto P_0c03e95c;
case 0x0c03e95eu: goto P_0c03e95e;
case 0x0c03e960u: goto P_0c03e960;
case 0x0c03e962u: goto P_0c03e962;
case 0x0c03e964u: goto P_0c03e964;
case 0x0c03e966u: goto P_0c03e966;
case 0x0c03e968u: goto P_0c03e968;
case 0x0c03e96au: goto P_0c03e96a;
case 0x0c03e96cu: goto P_0c03e96c;
case 0x0c03e96eu: goto P_0c03e96e;
case 0x0c03e970u: goto P_0c03e970;
case 0x0c03e972u: goto P_0c03e972;
case 0x0c03e974u: goto P_0c03e974;
case 0x0c03e976u: goto P_0c03e976;
case 0x0c03ea10u: goto P_0c03ea10;
case 0x0c03ea12u: goto P_0c03ea12;
case 0x0c03ea14u: goto P_0c03ea14;
case 0x0c03ea16u: goto P_0c03ea16;
case 0x0c03ea18u: goto P_0c03ea18;
case 0x0c03ea1au: goto P_0c03ea1a;
case 0x0c03ea1cu: goto P_0c03ea1c;
case 0x0c03ea1eu: goto P_0c03ea1e;
case 0x0c03ea20u: goto P_0c03ea20;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c03e430: /* original 2fe6, guest PC 0x0c03e430 */
if(!s->budget--) { s->failed_pc=0x0c03e430u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e432;
P_0c03e432: /* original 2448, guest PC 0x0c03e432 */
if(!s->budget--) { s->failed_pc=0x0c03e432u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03e434;
P_0c03e434: /* original 2fd6, guest PC 0x0c03e434 */
if(!s->budget--) { s->failed_pc=0x0c03e434u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e436;
P_0c03e436: /* original e300, guest PC 0x0c03e436 */
if(!s->budget--) { s->failed_pc=0x0c03e436u; return 0; }
r[3]=0x00000000u;
goto P_0c03e438;
P_0c03e438: /* original 2fc6, guest PC 0x0c03e438 */
if(!s->budget--) { s->failed_pc=0x0c03e438u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e43a;
P_0c03e43a: /* original 2fb6, guest PC 0x0c03e43a */
if(!s->budget--) { s->failed_pc=0x0c03e43au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e43c;
P_0c03e43c: /* original 2fa6, guest PC 0x0c03e43c */
if(!s->budget--) { s->failed_pc=0x0c03e43cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e43e;
P_0c03e43e: /* original 2f96, guest PC 0x0c03e43e */
if(!s->budget--) { s->failed_pc=0x0c03e43eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e440;
P_0c03e440: /* original 2f86, guest PC 0x0c03e440 */
if(!s->budget--) { s->failed_pc=0x0c03e440u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e442;
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
r[16]=code_base|0x0c03e4b2u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e4b2u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c03e4d0u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e4d0u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c03e4f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e4f8u; return 0; } return 1;
P_0c03e680: /* original 2fe6, guest PC 0x0c03e680 */
if(!s->budget--) { s->failed_pc=0x0c03e680u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e682;
P_0c03e682: /* original e044, guest PC 0x0c03e682 */
if(!s->budget--) { s->failed_pc=0x0c03e682u; return 0; }
r[0]=0x00000044u;
goto P_0c03e684;
P_0c03e684: /* original 9e57, guest PC 0x0c03e684 */
if(!s->budget--) { s->failed_pc=0x0c03e684u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e736u,2);
goto P_0c03e686;
P_0c03e686: /* original 4f12, guest PC 0x0c03e686 */
if(!s->budget--) { s->failed_pc=0x0c03e686u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e688;
P_0c03e688: /* original 24ef, guest PC 0x0c03e688 */
if(!s->budget--) { s->failed_pc=0x0c03e688u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c03e68a;
P_0c03e68a: /* original d32c, guest PC 0x0c03e68a */
if(!s->budget--) { s->failed_pc=0x0c03e68au; return 0; }
r[3]=read(ram,0x0c03e73cu,4);
goto P_0c03e68c;
P_0c03e68c: /* original 0e1a, guest PC 0x0c03e68c */
if(!s->budget--) { s->failed_pc=0x0c03e68cu; return 0; }
r[14]=r[19];
goto P_0c03e68e;
P_0c03e68e: /* original 4f16, guest PC 0x0c03e68e */
if(!s->budget--) { s->failed_pc=0x0c03e68eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e690;
P_0c03e690: /* original 6eef, guest PC 0x0c03e690 */
if(!s->budget--) { s->failed_pc=0x0c03e690u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c03e692;
P_0c03e692: /* original 3e3c, guest PC 0x0c03e692 */
if(!s->budget--) { s->failed_pc=0x0c03e692u; return 0; }
r[14]+=r[3];
goto P_0c03e694;
P_0c03e694: /* original 62e3, guest PC 0x0c03e694 */
if(!s->budget--) { s->failed_pc=0x0c03e694u; return 0; }
r[2]=r[14];
goto P_0c03e696;
P_0c03e696: /* original 7240, guest PC 0x0c03e696 */
if(!s->budget--) { s->failed_pc=0x0c03e696u; return 0; }
r[2]+=0x00000040u;
goto P_0c03e698;
P_0c03e698: /* original f24a, guest PC 0x0c03e698 */
if(!s->budget--) { s->failed_pc=0x0c03e698u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
goto P_0c03e69a;
P_0c03e69a: /* original 64e3, guest PC 0x0c03e69a */
if(!s->budget--) { s->failed_pc=0x0c03e69au; return 0; }
r[4]=r[14];
goto P_0c03e69c;
P_0c03e69c: /* original fe57, guest PC 0x0c03e69c */
if(!s->budget--) { s->failed_pc=0x0c03e69cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c03e69e;
P_0c03e69e: /* original e048, guest PC 0x0c03e69e */
if(!s->budget--) { s->failed_pc=0x0c03e69eu; return 0; }
r[0]=0x00000048u;
goto P_0c03e6a0;
P_0c03e6a0: /* original fe67, guest PC 0x0c03e6a0 */
if(!s->budget--) { s->failed_pc=0x0c03e6a0u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c03e6a2;
P_0c03e6a2: /* original 7440, guest PC 0x0c03e6a2 */
if(!s->budget--) { s->failed_pc=0x0c03e6a2u; return 0; }
r[4]+=0x00000040u;
goto P_0c03e6a4;
P_0c03e6a4: /* original d22a, guest PC 0x0c03e6a4 */
if(!s->budget--) { s->failed_pc=0x0c03e6a4u; return 0; }
r[2]=read(ram,0x0c03e750u,4);
goto P_0c03e6a6;
P_0c03e6a6: /* original 422b, guest PC 0x0c03e6a6 */
if(!s->budget--) { s->failed_pc=0x0c03e6a6u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03d040u: return vf3_matrix_family(0x0c03d040u,s,ram);
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
P_0c03e6a8: /* original 6ef6, guest PC 0x0c03e6a8 */
if(!s->budget--) { s->failed_pc=0x0c03e6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e6aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e6aau; return 0; } return 1;
P_0c03e860: /* original 9313, guest PC 0x0c03e860 */
if(!s->budget--) { s->failed_pc=0x0c03e860u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88au,2);
goto P_0c03e862;
P_0c03e862: /* original e014, guest PC 0x0c03e862 */
if(!s->budget--) { s->failed_pc=0x0c03e862u; return 0; }
r[0]=0x00000014u;
goto P_0c03e864;
P_0c03e864: /* original 4f12, guest PC 0x0c03e864 */
if(!s->budget--) { s->failed_pc=0x0c03e864u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e866;
P_0c03e866: /* original 243f, guest PC 0x0c03e866 */
if(!s->budget--) { s->failed_pc=0x0c03e866u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c03e868;
P_0c03e868: /* original d209, guest PC 0x0c03e868 */
if(!s->budget--) { s->failed_pc=0x0c03e868u; return 0; }
r[2]=read(ram,0x0c03e890u,4);
goto P_0c03e86a;
P_0c03e86a: /* original f359, guest PC 0x0c03e86a */
if(!s->budget--) { s->failed_pc=0x0c03e86au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e86c;
P_0c03e86c: /* original 041a, guest PC 0x0c03e86c */
if(!s->budget--) { s->failed_pc=0x0c03e86cu; return 0; }
r[4]=r[19];
goto P_0c03e86e;
P_0c03e86e: /* original 644f, guest PC 0x0c03e86e */
if(!s->budget--) { s->failed_pc=0x0c03e86eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c03e870;
P_0c03e870: /* original 342c, guest PC 0x0c03e870 */
if(!s->budget--) { s->failed_pc=0x0c03e870u; return 0; }
r[4]+=r[2];
goto P_0c03e872;
P_0c03e872: /* original f437, guest PC 0x0c03e872 */
if(!s->budget--) { s->failed_pc=0x0c03e872u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e874;
P_0c03e874: /* original e018, guest PC 0x0c03e874 */
if(!s->budget--) { s->failed_pc=0x0c03e874u; return 0; }
r[0]=0x00000018u;
goto P_0c03e876;
P_0c03e876: /* original f359, guest PC 0x0c03e876 */
if(!s->budget--) { s->failed_pc=0x0c03e876u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e878;
P_0c03e878: /* original f437, guest PC 0x0c03e878 */
if(!s->budget--) { s->failed_pc=0x0c03e878u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e87a;
P_0c03e87a: /* original e01c, guest PC 0x0c03e87a */
if(!s->budget--) { s->failed_pc=0x0c03e87au; return 0; }
r[0]=0x0000001cu;
goto P_0c03e87c;
P_0c03e87c: /* original f359, guest PC 0x0c03e87c */
if(!s->budget--) { s->failed_pc=0x0c03e87cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e87e;
P_0c03e87e: /* original f437, guest PC 0x0c03e87e */
if(!s->budget--) { s->failed_pc=0x0c03e87eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e880;
P_0c03e880: /* original e020, guest PC 0x0c03e880 */
if(!s->budget--) { s->failed_pc=0x0c03e880u; return 0; }
r[0]=0x00000020u;
goto P_0c03e882;
P_0c03e882: /* original f358, guest PC 0x0c03e882 */
if(!s->budget--) { s->failed_pc=0x0c03e882u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c03e884;
P_0c03e884: /* original f437, guest PC 0x0c03e884 */
if(!s->budget--) { s->failed_pc=0x0c03e884u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e886;
P_0c03e886: /* original 000b, guest PC 0x0c03e886 */
if(!s->budget--) { s->failed_pc=0x0c03e886u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c03e888: /* original 4f16, guest PC 0x0c03e888 */
if(!s->budget--) { s->failed_pc=0x0c03e888u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03e88au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e88au; return 0; } return 1;
P_0c03e8c0: /* original 2fe6, guest PC 0x0c03e8c0 */
if(!s->budget--) { s->failed_pc=0x0c03e8c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8c2;
P_0c03e8c2: /* original 2fd6, guest PC 0x0c03e8c2 */
if(!s->budget--) { s->failed_pc=0x0c03e8c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8c4;
P_0c03e8c4: /* original 2fc6, guest PC 0x0c03e8c4 */
if(!s->budget--) { s->failed_pc=0x0c03e8c4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8c6;
P_0c03e8c6: /* original 2fb6, guest PC 0x0c03e8c6 */
if(!s->budget--) { s->failed_pc=0x0c03e8c6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8c8;
P_0c03e8c8: /* original 2fa6, guest PC 0x0c03e8c8 */
if(!s->budget--) { s->failed_pc=0x0c03e8c8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8ca;
P_0c03e8ca: /* original 4f22, guest PC 0x0c03e8ca */
if(!s->budget--) { s->failed_pc=0x0c03e8cau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e8cc;
P_0c03e8cc: /* original d344, guest PC 0x0c03e8cc */
if(!s->budget--) { s->failed_pc=0x0c03e8ccu; return 0; }
r[3]=read(ram,0x0c03e9e0u,4);
goto P_0c03e8ce;
P_0c03e8ce: /* original 430b, guest PC 0x0c03e8ce */
if(!s->budget--) { s->failed_pc=0x0c03e8ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c03e8d2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e8d2u) { target=s->pc; goto dispatch; }
goto P_0c03e8d2;
P_0c03e8d0: /* original e400, guest PC 0x0c03e8d0 */
if(!s->budget--) { s->failed_pc=0x0c03e8d0u; return 0; }
r[4]=0x00000000u;
goto P_0c03e8d2;
P_0c03e8d2: /* original d244, guest PC 0x0c03e8d2 */
if(!s->budget--) { s->failed_pc=0x0c03e8d2u; return 0; }
r[2]=read(ram,0x0c03e9e4u,4);
goto P_0c03e8d4;
P_0c03e8d4: /* original 420b, guest PC 0x0c03e8d4 */
if(!s->budget--) { s->failed_pc=0x0c03e8d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c03e8d8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e8d8u) { target=s->pc; goto dispatch; }
goto P_0c03e8d8;
P_0c03e8d6: /* original 0009, guest PC 0x0c03e8d6 */
if(!s->budget--) { s->failed_pc=0x0c03e8d6u; return 0; }
goto P_0c03e8d8;
P_0c03e8d8: /* original dc44, guest PC 0x0c03e8d8 */
if(!s->budget--) { s->failed_pc=0x0c03e8d8u; return 0; }
r[12]=read(ram,0x0c03e9ecu,4);
goto P_0c03e8da;
P_0c03e8da: /* original eb00, guest PC 0x0c03e8da */
if(!s->budget--) { s->failed_pc=0x0c03e8dau; return 0; }
r[11]=0x00000000u;
goto P_0c03e8dc;
P_0c03e8dc: /* original de42, guest PC 0x0c03e8dc */
if(!s->budget--) { s->failed_pc=0x0c03e8dcu; return 0; }
r[14]=read(ram,0x0c03e9e8u,4);
goto P_0c03e8de;
P_0c03e8de: /* original ea10, guest PC 0x0c03e8de */
if(!s->budget--) { s->failed_pc=0x0c03e8deu; return 0; }
r[10]=0x00000010u;
goto P_0c03e8e0;
P_0c03e8e0: /* original dd43, guest PC 0x0c03e8e0 */
if(!s->budget--) { s->failed_pc=0x0c03e8e0u; return 0; }
r[13]=read(ram,0x0c03e9f0u,4);
goto P_0c03e8e2;
P_0c03e8e2: /* original 63e1, guest PC 0x0c03e8e2 */
if(!s->budget--) { s->failed_pc=0x0c03e8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c03e8e4;
P_0c03e8e4: /* original 2338, guest PC 0x0c03e8e4 */
if(!s->budget--) { s->failed_pc=0x0c03e8e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03e8e6;
P_0c03e8e6: /* original 8909, guest PC 0x0c03e8e6 */
if(!s->budget--) { s->failed_pc=0x0c03e8e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e8fc; }
goto P_0c03e8e8;
P_0c03e8e8: /* original 9577, guest PC 0x0c03e8e8 */
if(!s->budget--) { s->failed_pc=0x0c03e8e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e8ea;
P_0c03e8ea: /* original 64e3, guest PC 0x0c03e8ea */
if(!s->budget--) { s->failed_pc=0x0c03e8eau; return 0; }
r[4]=r[14];
goto P_0c03e8ec;
P_0c03e8ec: /* original 35ec, guest PC 0x0c03e8ec */
if(!s->budget--) { s->failed_pc=0x0c03e8ecu; return 0; }
r[5]+=r[14];
goto P_0c03e8ee;
P_0c03e8ee: /* original 4c0b, guest PC 0x0c03e8ee */
if(!s->budget--) { s->failed_pc=0x0c03e8eeu; return 0; }
target=r[12];
r[16]=code_base|0x0c03e8f2u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e8f2u) { target=s->pc; goto dispatch; }
goto P_0c03e8f2;
P_0c03e8f0: /* original 7468, guest PC 0x0c03e8f0 */
if(!s->budget--) { s->failed_pc=0x0c03e8f0u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e8f2;
P_0c03e8f2: /* original 65e3, guest PC 0x0c03e8f2 */
if(!s->budget--) { s->failed_pc=0x0c03e8f2u; return 0; }
r[5]=r[14];
goto P_0c03e8f4;
P_0c03e8f4: /* original 64e3, guest PC 0x0c03e8f4 */
if(!s->budget--) { s->failed_pc=0x0c03e8f4u; return 0; }
r[4]=r[14];
goto P_0c03e8f6;
P_0c03e8f6: /* original 7574, guest PC 0x0c03e8f6 */
if(!s->budget--) { s->failed_pc=0x0c03e8f6u; return 0; }
r[5]+=0x00000074u;
goto P_0c03e8f8;
P_0c03e8f8: /* original 4d0b, guest PC 0x0c03e8f8 */
if(!s->budget--) { s->failed_pc=0x0c03e8f8u; return 0; }
target=r[13];
r[16]=code_base|0x0c03e8fcu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e8fcu) { target=s->pc; goto dispatch; }
goto P_0c03e8fc;
P_0c03e8fa: /* original 745c, guest PC 0x0c03e8fa */
if(!s->budget--) { s->failed_pc=0x0c03e8fau; return 0; }
r[4]+=0x0000005cu;
goto P_0c03e8fc;
P_0c03e8fc: /* original 936e, guest PC 0x0c03e8fc */
if(!s->budget--) { s->failed_pc=0x0c03e8fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dcu,2);
goto P_0c03e8fe;
P_0c03e8fe: /* original 3e3c, guest PC 0x0c03e8fe */
if(!s->budget--) { s->failed_pc=0x0c03e8feu; return 0; }
r[14]+=r[3];
goto P_0c03e900;
P_0c03e900: /* original 62e1, guest PC 0x0c03e900 */
if(!s->budget--) { s->failed_pc=0x0c03e900u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c03e902;
P_0c03e902: /* original 2228, guest PC 0x0c03e902 */
if(!s->budget--) { s->failed_pc=0x0c03e902u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e904;
P_0c03e904: /* original 8d0a, guest PC 0x0c03e904 */
if(!s->budget--) { s->failed_pc=0x0c03e904u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(cond) { goto P_0c03e91c; }
goto P_0c03e908;
P_0c03e906: /* original 7b01, guest PC 0x0c03e906 */
if(!s->budget--) { s->failed_pc=0x0c03e906u; return 0; }
r[11]+=0x00000001u;
goto P_0c03e908;
P_0c03e908: /* original 9567, guest PC 0x0c03e908 */
if(!s->budget--) { s->failed_pc=0x0c03e908u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e90a;
P_0c03e90a: /* original 64e3, guest PC 0x0c03e90a */
if(!s->budget--) { s->failed_pc=0x0c03e90au; return 0; }
r[4]=r[14];
goto P_0c03e90c;
P_0c03e90c: /* original 35ec, guest PC 0x0c03e90c */
if(!s->budget--) { s->failed_pc=0x0c03e90cu; return 0; }
r[5]+=r[14];
goto P_0c03e90e;
P_0c03e90e: /* original 4c0b, guest PC 0x0c03e90e */
if(!s->budget--) { s->failed_pc=0x0c03e90eu; return 0; }
target=r[12];
r[16]=code_base|0x0c03e912u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e912u) { target=s->pc; goto dispatch; }
goto P_0c03e912;
P_0c03e910: /* original 7468, guest PC 0x0c03e910 */
if(!s->budget--) { s->failed_pc=0x0c03e910u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e912;
P_0c03e912: /* original 65e3, guest PC 0x0c03e912 */
if(!s->budget--) { s->failed_pc=0x0c03e912u; return 0; }
r[5]=r[14];
goto P_0c03e914;
P_0c03e914: /* original 64e3, guest PC 0x0c03e914 */
if(!s->budget--) { s->failed_pc=0x0c03e914u; return 0; }
r[4]=r[14];
goto P_0c03e916;
P_0c03e916: /* original 7574, guest PC 0x0c03e916 */
if(!s->budget--) { s->failed_pc=0x0c03e916u; return 0; }
r[5]+=0x00000074u;
goto P_0c03e918;
P_0c03e918: /* original 4d0b, guest PC 0x0c03e918 */
if(!s->budget--) { s->failed_pc=0x0c03e918u; return 0; }
target=r[13];
r[16]=code_base|0x0c03e91cu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e91cu) { target=s->pc; goto dispatch; }
goto P_0c03e91c;
P_0c03e91a: /* original 745c, guest PC 0x0c03e91a */
if(!s->budget--) { s->failed_pc=0x0c03e91au; return 0; }
r[4]+=0x0000005cu;
goto P_0c03e91c;
P_0c03e91c: /* original 935e, guest PC 0x0c03e91c */
if(!s->budget--) { s->failed_pc=0x0c03e91cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dcu,2);
goto P_0c03e91e;
P_0c03e91e: /* original 3e3c, guest PC 0x0c03e91e */
if(!s->budget--) { s->failed_pc=0x0c03e91eu; return 0; }
r[14]+=r[3];
goto P_0c03e920;
P_0c03e920: /* original 62e1, guest PC 0x0c03e920 */
if(!s->budget--) { s->failed_pc=0x0c03e920u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c03e922;
P_0c03e922: /* original 2228, guest PC 0x0c03e922 */
if(!s->budget--) { s->failed_pc=0x0c03e922u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e924;
P_0c03e924: /* original 8d0a, guest PC 0x0c03e924 */
if(!s->budget--) { s->failed_pc=0x0c03e924u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(cond) { goto P_0c03e93c; }
goto P_0c03e928;
P_0c03e926: /* original 7b01, guest PC 0x0c03e926 */
if(!s->budget--) { s->failed_pc=0x0c03e926u; return 0; }
r[11]+=0x00000001u;
goto P_0c03e928;
P_0c03e928: /* original 9557, guest PC 0x0c03e928 */
if(!s->budget--) { s->failed_pc=0x0c03e928u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e92a;
P_0c03e92a: /* original 64e3, guest PC 0x0c03e92a */
if(!s->budget--) { s->failed_pc=0x0c03e92au; return 0; }
r[4]=r[14];
goto P_0c03e92c;
P_0c03e92c: /* original 35ec, guest PC 0x0c03e92c */
if(!s->budget--) { s->failed_pc=0x0c03e92cu; return 0; }
r[5]+=r[14];
goto P_0c03e92e;
P_0c03e92e: /* original 4c0b, guest PC 0x0c03e92e */
if(!s->budget--) { s->failed_pc=0x0c03e92eu; return 0; }
target=r[12];
r[16]=code_base|0x0c03e932u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e932u) { target=s->pc; goto dispatch; }
goto P_0c03e932;
P_0c03e930: /* original 7468, guest PC 0x0c03e930 */
if(!s->budget--) { s->failed_pc=0x0c03e930u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e932;
P_0c03e932: /* original 65e3, guest PC 0x0c03e932 */
if(!s->budget--) { s->failed_pc=0x0c03e932u; return 0; }
r[5]=r[14];
goto P_0c03e934;
P_0c03e934: /* original 64e3, guest PC 0x0c03e934 */
if(!s->budget--) { s->failed_pc=0x0c03e934u; return 0; }
r[4]=r[14];
goto P_0c03e936;
P_0c03e936: /* original 7574, guest PC 0x0c03e936 */
if(!s->budget--) { s->failed_pc=0x0c03e936u; return 0; }
r[5]+=0x00000074u;
goto P_0c03e938;
P_0c03e938: /* original 4d0b, guest PC 0x0c03e938 */
if(!s->budget--) { s->failed_pc=0x0c03e938u; return 0; }
target=r[13];
r[16]=code_base|0x0c03e93cu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e93cu) { target=s->pc; goto dispatch; }
goto P_0c03e93c;
P_0c03e93a: /* original 745c, guest PC 0x0c03e93a */
if(!s->budget--) { s->failed_pc=0x0c03e93au; return 0; }
r[4]+=0x0000005cu;
goto P_0c03e93c;
P_0c03e93c: /* original 934e, guest PC 0x0c03e93c */
if(!s->budget--) { s->failed_pc=0x0c03e93cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dcu,2);
goto P_0c03e93e;
P_0c03e93e: /* original 3e3c, guest PC 0x0c03e93e */
if(!s->budget--) { s->failed_pc=0x0c03e93eu; return 0; }
r[14]+=r[3];
goto P_0c03e940;
P_0c03e940: /* original 62e1, guest PC 0x0c03e940 */
if(!s->budget--) { s->failed_pc=0x0c03e940u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c03e942;
P_0c03e942: /* original 2228, guest PC 0x0c03e942 */
if(!s->budget--) { s->failed_pc=0x0c03e942u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e944;
P_0c03e944: /* original 8d0a, guest PC 0x0c03e944 */
if(!s->budget--) { s->failed_pc=0x0c03e944u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(cond) { goto P_0c03e95c; }
goto P_0c03e948;
P_0c03e946: /* original 7b01, guest PC 0x0c03e946 */
if(!s->budget--) { s->failed_pc=0x0c03e946u; return 0; }
r[11]+=0x00000001u;
goto P_0c03e948;
P_0c03e948: /* original 9547, guest PC 0x0c03e948 */
if(!s->budget--) { s->failed_pc=0x0c03e948u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e94a;
P_0c03e94a: /* original 64e3, guest PC 0x0c03e94a */
if(!s->budget--) { s->failed_pc=0x0c03e94au; return 0; }
r[4]=r[14];
goto P_0c03e94c;
P_0c03e94c: /* original 35ec, guest PC 0x0c03e94c */
if(!s->budget--) { s->failed_pc=0x0c03e94cu; return 0; }
r[5]+=r[14];
goto P_0c03e94e;
P_0c03e94e: /* original 4c0b, guest PC 0x0c03e94e */
if(!s->budget--) { s->failed_pc=0x0c03e94eu; return 0; }
target=r[12];
r[16]=code_base|0x0c03e952u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e952u) { target=s->pc; goto dispatch; }
goto P_0c03e952;
P_0c03e950: /* original 7468, guest PC 0x0c03e950 */
if(!s->budget--) { s->failed_pc=0x0c03e950u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e952;
P_0c03e952: /* original 65e3, guest PC 0x0c03e952 */
if(!s->budget--) { s->failed_pc=0x0c03e952u; return 0; }
r[5]=r[14];
goto P_0c03e954;
P_0c03e954: /* original 64e3, guest PC 0x0c03e954 */
if(!s->budget--) { s->failed_pc=0x0c03e954u; return 0; }
r[4]=r[14];
goto P_0c03e956;
P_0c03e956: /* original 7574, guest PC 0x0c03e956 */
if(!s->budget--) { s->failed_pc=0x0c03e956u; return 0; }
r[5]+=0x00000074u;
goto P_0c03e958;
P_0c03e958: /* original 4d0b, guest PC 0x0c03e958 */
if(!s->budget--) { s->failed_pc=0x0c03e958u; return 0; }
target=r[13];
r[16]=code_base|0x0c03e95cu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e95cu) { target=s->pc; goto dispatch; }
goto P_0c03e95c;
P_0c03e95a: /* original 745c, guest PC 0x0c03e95a */
if(!s->budget--) { s->failed_pc=0x0c03e95au; return 0; }
r[4]+=0x0000005cu;
goto P_0c03e95c;
P_0c03e95c: /* original 7b01, guest PC 0x0c03e95c */
if(!s->budget--) { s->failed_pc=0x0c03e95cu; return 0; }
r[11]+=0x00000001u;
goto P_0c03e95e;
P_0c03e95e: /* original 933d, guest PC 0x0c03e95e */
if(!s->budget--) { s->failed_pc=0x0c03e95eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dcu,2);
goto P_0c03e960;
P_0c03e960: /* original 3ba3, guest PC 0x0c03e960 */
if(!s->budget--) { s->failed_pc=0x0c03e960u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[10])!=0);
goto P_0c03e962;
P_0c03e962: /* original 8fbe, guest PC 0x0c03e962 */
if(!s->budget--) { s->failed_pc=0x0c03e962u; return 0; }
cond=r[17]&1u;
r[14]+=r[3];
if(!cond) { goto P_0c03e8e2; }
goto P_0c03e966;
P_0c03e964: /* original 3e3c, guest PC 0x0c03e964 */
if(!s->budget--) { s->failed_pc=0x0c03e964u; return 0; }
r[14]+=r[3];
goto P_0c03e966;
P_0c03e966: /* original 4f26, guest PC 0x0c03e966 */
if(!s->budget--) { s->failed_pc=0x0c03e966u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e968;
P_0c03e968: /* original d322, guest PC 0x0c03e968 */
if(!s->budget--) { s->failed_pc=0x0c03e968u; return 0; }
r[3]=read(ram,0x0c03e9f4u,4);
goto P_0c03e96a;
P_0c03e96a: /* original e401, guest PC 0x0c03e96a */
if(!s->budget--) { s->failed_pc=0x0c03e96au; return 0; }
r[4]=0x00000001u;
goto P_0c03e96c;
P_0c03e96c: /* original 6af6, guest PC 0x0c03e96c */
if(!s->budget--) { s->failed_pc=0x0c03e96cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03e96e;
P_0c03e96e: /* original 6bf6, guest PC 0x0c03e96e */
if(!s->budget--) { s->failed_pc=0x0c03e96eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03e970;
P_0c03e970: /* original 6cf6, guest PC 0x0c03e970 */
if(!s->budget--) { s->failed_pc=0x0c03e970u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e972;
P_0c03e972: /* original 6df6, guest PC 0x0c03e972 */
if(!s->budget--) { s->failed_pc=0x0c03e972u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e974;
P_0c03e974: /* original 432b, guest PC 0x0c03e974 */
if(!s->budget--) { s->failed_pc=0x0c03e974u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c03e976: /* original 6ef6, guest PC 0x0c03e976 */
if(!s->budget--) { s->failed_pc=0x0c03e976u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e978u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e978u; return 0; } return 1;
P_0c03ea10: /* original 2fe6, guest PC 0x0c03ea10 */
if(!s->budget--) { s->failed_pc=0x0c03ea10u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ea12;
P_0c03ea12: /* original 2fd6, guest PC 0x0c03ea12 */
if(!s->budget--) { s->failed_pc=0x0c03ea12u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ea14;
P_0c03ea14: /* original 2fc6, guest PC 0x0c03ea14 */
if(!s->budget--) { s->failed_pc=0x0c03ea14u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ea16;
P_0c03ea16: /* original ec00, guest PC 0x0c03ea16 */
if(!s->budget--) { s->failed_pc=0x0c03ea16u; return 0; }
r[12]=0x00000000u;
goto P_0c03ea18;
P_0c03ea18: /* original 2fb6, guest PC 0x0c03ea18 */
if(!s->budget--) { s->failed_pc=0x0c03ea18u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ea1a;
P_0c03ea1a: /* original 6ec3, guest PC 0x0c03ea1a */
if(!s->budget--) { s->failed_pc=0x0c03ea1au; return 0; }
r[14]=r[12];
goto P_0c03ea1c;
P_0c03ea1c: /* original 2fa6, guest PC 0x0c03ea1c */
if(!s->budget--) { s->failed_pc=0x0c03ea1cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ea1e;
P_0c03ea1e: /* original 2f96, guest PC 0x0c03ea1e */
if(!s->budget--) { s->failed_pc=0x0c03ea1eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ea20;
P_0c03ea20: /* original 2f86, guest PC 0x0c03ea20 */
if(!s->budget--) { s->failed_pc=0x0c03ea20u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ea22;
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
target=code_base|0x0c03e860u; r[16]=code_base|0x0c03ea6cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ea6cu) { target=s->pc; goto dispatch; }
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
target=code_base|0x0c03e860u; r[16]=code_base|0x0c03eaaeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03eaaeu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c03ead0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ead0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
