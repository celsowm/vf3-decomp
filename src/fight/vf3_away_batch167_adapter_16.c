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
int vf3_away_batch167_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062508u: goto P_0c062508;
case 0x0c06250au: goto P_0c06250a;
case 0x0c06250cu: goto P_0c06250c;
case 0x0c06250eu: goto P_0c06250e;
case 0x0c062510u: goto P_0c062510;
case 0x0c062512u: goto P_0c062512;
case 0x0c062514u: goto P_0c062514;
case 0x0c062516u: goto P_0c062516;
case 0x0c062518u: goto P_0c062518;
case 0x0c06251au: goto P_0c06251a;
case 0x0c06251cu: goto P_0c06251c;
case 0x0c06251eu: goto P_0c06251e;
case 0x0c062520u: goto P_0c062520;
case 0x0c062522u: goto P_0c062522;
case 0x0c062524u: goto P_0c062524;
case 0x0c062526u: goto P_0c062526;
case 0x0c062528u: goto P_0c062528;
case 0x0c06252au: goto P_0c06252a;
case 0x0c06252cu: goto P_0c06252c;
case 0x0c06252eu: goto P_0c06252e;
case 0x0c062530u: goto P_0c062530;
case 0x0c062532u: goto P_0c062532;
case 0x0c062534u: goto P_0c062534;
case 0x0c062536u: goto P_0c062536;
case 0x0c062538u: goto P_0c062538;
case 0x0c06253au: goto P_0c06253a;
case 0x0c06253cu: goto P_0c06253c;
case 0x0c06253eu: goto P_0c06253e;
case 0x0c062540u: goto P_0c062540;
case 0x0c062542u: goto P_0c062542;
case 0x0c062544u: goto P_0c062544;
case 0x0c062546u: goto P_0c062546;
case 0x0c062548u: goto P_0c062548;
case 0x0c06254au: goto P_0c06254a;
case 0x0c06254cu: goto P_0c06254c;
case 0x0c06254eu: goto P_0c06254e;
case 0x0c062550u: goto P_0c062550;
case 0x0c062552u: goto P_0c062552;
case 0x0c06288cu: goto P_0c06288c;
case 0x0c06288eu: goto P_0c06288e;
case 0x0c062890u: goto P_0c062890;
case 0x0c062892u: goto P_0c062892;
case 0x0c062894u: goto P_0c062894;
case 0x0c062896u: goto P_0c062896;
case 0x0c062898u: goto P_0c062898;
case 0x0c06289au: goto P_0c06289a;
case 0x0c06289cu: goto P_0c06289c;
case 0x0c06289eu: goto P_0c06289e;
case 0x0c0628a0u: goto P_0c0628a0;
case 0x0c0628a2u: goto P_0c0628a2;
case 0x0c0628a4u: goto P_0c0628a4;
case 0x0c0628a6u: goto P_0c0628a6;
case 0x0c0628a8u: goto P_0c0628a8;
case 0x0c0628aau: goto P_0c0628aa;
case 0x0c0628acu: goto P_0c0628ac;
case 0x0c0628aeu: goto P_0c0628ae;
case 0x0c0628b0u: goto P_0c0628b0;
case 0x0c0628b2u: goto P_0c0628b2;
case 0x0c0628b4u: goto P_0c0628b4;
case 0x0c0628b6u: goto P_0c0628b6;
case 0x0c0628b8u: goto P_0c0628b8;
case 0x0c0628bau: goto P_0c0628ba;
case 0x0c0628bcu: goto P_0c0628bc;
case 0x0c0628beu: goto P_0c0628be;
case 0x0c0628c0u: goto P_0c0628c0;
case 0x0c0628c2u: goto P_0c0628c2;
case 0x0c0628c4u: goto P_0c0628c4;
case 0x0c0628c6u: goto P_0c0628c6;
case 0x0c0628c8u: goto P_0c0628c8;
case 0x0c0628cau: goto P_0c0628ca;
case 0x0c0628ccu: goto P_0c0628cc;
case 0x0c0628ceu: goto P_0c0628ce;
case 0x0c0628d0u: goto P_0c0628d0;
case 0x0c0628d2u: goto P_0c0628d2;
case 0x0c0628d4u: goto P_0c0628d4;
case 0x0c0628d6u: goto P_0c0628d6;
case 0x0c0628d8u: goto P_0c0628d8;
case 0x0c0628dau: goto P_0c0628da;
case 0x0c0628dcu: goto P_0c0628dc;
case 0x0c0628deu: goto P_0c0628de;
case 0x0c0628e0u: goto P_0c0628e0;
case 0x0c0628e2u: goto P_0c0628e2;
case 0x0c0628e4u: goto P_0c0628e4;
case 0x0c0628e6u: goto P_0c0628e6;
case 0x0c0628e8u: goto P_0c0628e8;
case 0x0c0628eau: goto P_0c0628ea;
case 0x0c0628ecu: goto P_0c0628ec;
case 0x0c0628eeu: goto P_0c0628ee;
case 0x0c0628f0u: goto P_0c0628f0;
case 0x0c0628f2u: goto P_0c0628f2;
case 0x0c0628f4u: goto P_0c0628f4;
case 0x0c0628f6u: goto P_0c0628f6;
case 0x0c0628f8u: goto P_0c0628f8;
case 0x0c0628fau: goto P_0c0628fa;
case 0x0c0628fcu: goto P_0c0628fc;
case 0x0c062908u: goto P_0c062908;
case 0x0c06290au: goto P_0c06290a;
case 0x0c06290cu: goto P_0c06290c;
case 0x0c06290eu: goto P_0c06290e;
case 0x0c062910u: goto P_0c062910;
case 0x0c062912u: goto P_0c062912;
case 0x0c062914u: goto P_0c062914;
case 0x0c062916u: goto P_0c062916;
case 0x0c062918u: goto P_0c062918;
case 0x0c06291au: goto P_0c06291a;
case 0x0c06291cu: goto P_0c06291c;
case 0x0c06291eu: goto P_0c06291e;
case 0x0c062920u: goto P_0c062920;
case 0x0c062922u: goto P_0c062922;
case 0x0c062924u: goto P_0c062924;
case 0x0c062926u: goto P_0c062926;
case 0x0c062928u: goto P_0c062928;
case 0x0c06292au: goto P_0c06292a;
case 0x0c06292cu: goto P_0c06292c;
case 0x0c06292eu: goto P_0c06292e;
case 0x0c062930u: goto P_0c062930;
case 0x0c062932u: goto P_0c062932;
case 0x0c062934u: goto P_0c062934;
case 0x0c062936u: goto P_0c062936;
case 0x0c062938u: goto P_0c062938;
case 0x0c06293au: goto P_0c06293a;
case 0x0c06293cu: goto P_0c06293c;
case 0x0c06293eu: goto P_0c06293e;
case 0x0c062940u: goto P_0c062940;
case 0x0c062942u: goto P_0c062942;
case 0x0c062944u: goto P_0c062944;
case 0x0c062946u: goto P_0c062946;
case 0x0c062948u: goto P_0c062948;
case 0x0c06294au: goto P_0c06294a;
case 0x0c06294cu: goto P_0c06294c;
case 0x0c06294eu: goto P_0c06294e;
case 0x0c062950u: goto P_0c062950;
case 0x0c062952u: goto P_0c062952;
case 0x0c062954u: goto P_0c062954;
case 0x0c062956u: goto P_0c062956;
case 0x0c062958u: goto P_0c062958;
case 0x0c06295au: goto P_0c06295a;
case 0x0c06295cu: goto P_0c06295c;
case 0x0c06295eu: goto P_0c06295e;
case 0x0c062960u: goto P_0c062960;
case 0x0c062962u: goto P_0c062962;
case 0x0c062964u: goto P_0c062964;
case 0x0c062966u: goto P_0c062966;
case 0x0c062968u: goto P_0c062968;
case 0x0c06296au: goto P_0c06296a;
case 0x0c06296cu: goto P_0c06296c;
case 0x0c06296eu: goto P_0c06296e;
case 0x0c062970u: goto P_0c062970;
case 0x0c062972u: goto P_0c062972;
case 0x0c062974u: goto P_0c062974;
case 0x0c062976u: goto P_0c062976;
case 0x0c062978u: goto P_0c062978;
case 0x0c06297au: goto P_0c06297a;
case 0x0c06297cu: goto P_0c06297c;
case 0x0c06297eu: goto P_0c06297e;
case 0x0c062980u: goto P_0c062980;
case 0x0c062982u: goto P_0c062982;
case 0x0c062984u: goto P_0c062984;
case 0x0c062986u: goto P_0c062986;
case 0x0c062988u: goto P_0c062988;
case 0x0c06298au: goto P_0c06298a;
case 0x0c06298cu: goto P_0c06298c;
case 0x0c06298eu: goto P_0c06298e;
case 0x0c062990u: goto P_0c062990;
case 0x0c062992u: goto P_0c062992;
case 0x0c062994u: goto P_0c062994;
case 0x0c062996u: goto P_0c062996;
case 0x0c062998u: goto P_0c062998;
case 0x0c06299au: goto P_0c06299a;
case 0x0c06299cu: goto P_0c06299c;
case 0x0c06299eu: goto P_0c06299e;
case 0x0c0629a0u: goto P_0c0629a0;
case 0x0c0629a2u: goto P_0c0629a2;
case 0x0c0629a4u: goto P_0c0629a4;
case 0x0c0629a6u: goto P_0c0629a6;
case 0x0c0629a8u: goto P_0c0629a8;
case 0x0c0629aau: goto P_0c0629aa;
case 0x0c0629acu: goto P_0c0629ac;
case 0x0c0629aeu: goto P_0c0629ae;
case 0x0c0629b0u: goto P_0c0629b0;
case 0x0c0629b2u: goto P_0c0629b2;
case 0x0c0629b4u: goto P_0c0629b4;
case 0x0c0629b6u: goto P_0c0629b6;
case 0x0c0629b8u: goto P_0c0629b8;
case 0x0c0629bau: goto P_0c0629ba;
case 0x0c0629bcu: goto P_0c0629bc;
case 0x0c0629beu: goto P_0c0629be;
case 0x0c0629c0u: goto P_0c0629c0;
case 0x0c0629c2u: goto P_0c0629c2;
case 0x0c0629c4u: goto P_0c0629c4;
case 0x0c0629c6u: goto P_0c0629c6;
case 0x0c0629c8u: goto P_0c0629c8;
case 0x0c0629cau: goto P_0c0629ca;
case 0x0c0629ccu: goto P_0c0629cc;
case 0x0c0629ceu: goto P_0c0629ce;
case 0x0c0629d0u: goto P_0c0629d0;
case 0x0c0629d2u: goto P_0c0629d2;
case 0x0c0629d4u: goto P_0c0629d4;
case 0x0c0629d6u: goto P_0c0629d6;
case 0x0c0629d8u: goto P_0c0629d8;
case 0x0c0629dau: goto P_0c0629da;
case 0x0c0629dcu: goto P_0c0629dc;
case 0x0c0629deu: goto P_0c0629de;
case 0x0c0629e0u: goto P_0c0629e0;
case 0x0c0629e2u: goto P_0c0629e2;
case 0x0c0629e4u: goto P_0c0629e4;
case 0x0c0629e6u: goto P_0c0629e6;
case 0x0c0629ecu: goto P_0c0629ec;
case 0x0c0629eeu: goto P_0c0629ee;
case 0x0c0629f0u: goto P_0c0629f0;
case 0x0c0629f2u: goto P_0c0629f2;
case 0x0c0629f4u: goto P_0c0629f4;
case 0x0c0629f6u: goto P_0c0629f6;
case 0x0c0629f8u: goto P_0c0629f8;
case 0x0c0629fau: goto P_0c0629fa;
case 0x0c0629fcu: goto P_0c0629fc;
case 0x0c0629feu: goto P_0c0629fe;
case 0x0c062a00u: goto P_0c062a00;
case 0x0c062a02u: goto P_0c062a02;
case 0x0c062a04u: goto P_0c062a04;
case 0x0c062a06u: goto P_0c062a06;
case 0x0c062a08u: goto P_0c062a08;
case 0x0c062a0au: goto P_0c062a0a;
case 0x0c062a0cu: goto P_0c062a0c;
case 0x0c062a0eu: goto P_0c062a0e;
case 0x0c062a10u: goto P_0c062a10;
case 0x0c062a12u: goto P_0c062a12;
case 0x0c062a14u: goto P_0c062a14;
case 0x0c062a16u: goto P_0c062a16;
case 0x0c062a18u: goto P_0c062a18;
case 0x0c062a1au: goto P_0c062a1a;
case 0x0c062a1cu: goto P_0c062a1c;
case 0x0c062a1eu: goto P_0c062a1e;
case 0x0c062a20u: goto P_0c062a20;
case 0x0c062a22u: goto P_0c062a22;
case 0x0c062a24u: goto P_0c062a24;
case 0x0c062a26u: goto P_0c062a26;
case 0x0c062a28u: goto P_0c062a28;
case 0x0c062a2au: goto P_0c062a2a;
case 0x0c062a2cu: goto P_0c062a2c;
case 0x0c062a2eu: goto P_0c062a2e;
case 0x0c062a30u: goto P_0c062a30;
case 0x0c062a32u: goto P_0c062a32;
case 0x0c062a34u: goto P_0c062a34;
case 0x0c062a36u: goto P_0c062a36;
case 0x0c062a38u: goto P_0c062a38;
case 0x0c062a3au: goto P_0c062a3a;
case 0x0c062a3cu: goto P_0c062a3c;
case 0x0c062a3eu: goto P_0c062a3e;
case 0x0c062a40u: goto P_0c062a40;
case 0x0c062a42u: goto P_0c062a42;
case 0x0c062a44u: goto P_0c062a44;
case 0x0c062a46u: goto P_0c062a46;
case 0x0c062a48u: goto P_0c062a48;
case 0x0c062a4au: goto P_0c062a4a;
case 0x0c062a4cu: goto P_0c062a4c;
case 0x0c062a4eu: goto P_0c062a4e;
case 0x0c062a50u: goto P_0c062a50;
case 0x0c062a52u: goto P_0c062a52;
case 0x0c062a54u: goto P_0c062a54;
case 0x0c062a56u: goto P_0c062a56;
case 0x0c062a58u: goto P_0c062a58;
case 0x0c062a5au: goto P_0c062a5a;
case 0x0c062a5cu: goto P_0c062a5c;
case 0x0c062a5eu: goto P_0c062a5e;
case 0x0c062a60u: goto P_0c062a60;
case 0x0c062a62u: goto P_0c062a62;
case 0x0c062a64u: goto P_0c062a64;
case 0x0c062a66u: goto P_0c062a66;
case 0x0c062a68u: goto P_0c062a68;
case 0x0c062a6au: goto P_0c062a6a;
case 0x0c062a6cu: goto P_0c062a6c;
case 0x0c062a6eu: goto P_0c062a6e;
case 0x0c062a70u: goto P_0c062a70;
case 0x0c062a72u: goto P_0c062a72;
case 0x0c062a74u: goto P_0c062a74;
case 0x0c062a76u: goto P_0c062a76;
case 0x0c062a78u: goto P_0c062a78;
case 0x0c062a7au: goto P_0c062a7a;
case 0x0c062a7cu: goto P_0c062a7c;
case 0x0c062a7eu: goto P_0c062a7e;
case 0x0c062a80u: goto P_0c062a80;
case 0x0c062a82u: goto P_0c062a82;
case 0x0c062a84u: goto P_0c062a84;
case 0x0c062a86u: goto P_0c062a86;
case 0x0c062a88u: goto P_0c062a88;
case 0x0c062a8au: goto P_0c062a8a;
case 0x0c062a8cu: goto P_0c062a8c;
case 0x0c062a8eu: goto P_0c062a8e;
case 0x0c062a90u: goto P_0c062a90;
case 0x0c062a92u: goto P_0c062a92;
case 0x0c062a94u: goto P_0c062a94;
case 0x0c062a96u: goto P_0c062a96;
case 0x0c062a98u: goto P_0c062a98;
case 0x0c062a9au: goto P_0c062a9a;
case 0x0c062a9cu: goto P_0c062a9c;
case 0x0c062a9eu: goto P_0c062a9e;
case 0x0c062aa0u: goto P_0c062aa0;
case 0x0c062aa2u: goto P_0c062aa2;
case 0x0c062aa4u: goto P_0c062aa4;
case 0x0c062aa6u: goto P_0c062aa6;
case 0x0c062aa8u: goto P_0c062aa8;
case 0x0c062aaau: goto P_0c062aaa;
case 0x0c062aacu: goto P_0c062aac;
case 0x0c062aaeu: goto P_0c062aae;
case 0x0c062ab0u: goto P_0c062ab0;
case 0x0c062ab2u: goto P_0c062ab2;
case 0x0c062ab4u: goto P_0c062ab4;
case 0x0c062ab6u: goto P_0c062ab6;
case 0x0c062ab8u: goto P_0c062ab8;
case 0x0c062abau: goto P_0c062aba;
case 0x0c062abcu: goto P_0c062abc;
case 0x0c062abeu: goto P_0c062abe;
case 0x0c062ac4u: goto P_0c062ac4;
case 0x0c062ac6u: goto P_0c062ac6;
case 0x0c062ac8u: goto P_0c062ac8;
case 0x0c062acau: goto P_0c062aca;
case 0x0c062accu: goto P_0c062acc;
case 0x0c062aceu: goto P_0c062ace;
case 0x0c062ad0u: goto P_0c062ad0;
case 0x0c062ad2u: goto P_0c062ad2;
case 0x0c062ad4u: goto P_0c062ad4;
case 0x0c062ad6u: goto P_0c062ad6;
case 0x0c062ad8u: goto P_0c062ad8;
case 0x0c062adau: goto P_0c062ada;
case 0x0c062adcu: goto P_0c062adc;
case 0x0c062adeu: goto P_0c062ade;
case 0x0c062ae0u: goto P_0c062ae0;
case 0x0c062ae2u: goto P_0c062ae2;
case 0x0c062ae4u: goto P_0c062ae4;
case 0x0c062ae6u: goto P_0c062ae6;
case 0x0c062ae8u: goto P_0c062ae8;
case 0x0c062aeau: goto P_0c062aea;
case 0x0c062aecu: goto P_0c062aec;
case 0x0c062aeeu: goto P_0c062aee;
case 0x0c062af0u: goto P_0c062af0;
case 0x0c062af2u: goto P_0c062af2;
case 0x0c062af4u: goto P_0c062af4;
case 0x0c062af6u: goto P_0c062af6;
case 0x0c062af8u: goto P_0c062af8;
case 0x0c062afau: goto P_0c062afa;
case 0x0c062afcu: goto P_0c062afc;
case 0x0c062afeu: goto P_0c062afe;
case 0x0c062b00u: goto P_0c062b00;
case 0x0c062b02u: goto P_0c062b02;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062508: /* original 5362, guest PC 0x0c062508 */
if(!s->budget--) { s->failed_pc=0x0c062508u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06250a;
P_0c06250a: /* original 2338, guest PC 0x0c06250a */
if(!s->budget--) { s->failed_pc=0x0c06250au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06250c;
P_0c06250c: /* original 8b03, guest PC 0x0c06250c */
if(!s->budget--) { s->failed_pc=0x0c06250cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062516; }
goto P_0c06250e;
P_0c06250e: /* original 2452, guest PC 0x0c06250e */
if(!s->budget--) { s->failed_pc=0x0c06250eu; return 0; }
write(ram,r[4],r[5],4);
goto P_0c062510;
P_0c062510: /* original 1561, guest PC 0x0c062510 */
if(!s->budget--) { s->failed_pc=0x0c062510u; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c062512;
P_0c062512: /* original a004, guest PC 0x0c062512 */
if(!s->budget--) { s->failed_pc=0x0c062512u; return 0; }
r[3]=0x00000000u;
goto P_0c06251e;
P_0c062514: /* original e300, guest PC 0x0c062514 */
if(!s->budget--) { s->failed_pc=0x0c062514u; return 0; }
r[3]=0x00000000u;
goto P_0c062516;
P_0c062516: /* original 5462, guest PC 0x0c062516 */
if(!s->budget--) { s->failed_pc=0x0c062516u; return 0; }
r[4]=read(ram,r[6]+8,4);
goto P_0c062518;
P_0c062518: /* original 1451, guest PC 0x0c062518 */
if(!s->budget--) { s->failed_pc=0x0c062518u; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c06251a;
P_0c06251a: /* original 1561, guest PC 0x0c06251a */
if(!s->budget--) { s->failed_pc=0x0c06251au; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c06251c;
P_0c06251c: /* original 5362, guest PC 0x0c06251c */
if(!s->budget--) { s->failed_pc=0x0c06251cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06251e;
P_0c06251e: /* original 1532, guest PC 0x0c06251e */
if(!s->budget--) { s->failed_pc=0x0c06251eu; return 0; }
write(ram,r[5]+8,r[3],4);
goto P_0c062520;
P_0c062520: /* original 000b, guest PC 0x0c062520 */
if(!s->budget--) { s->failed_pc=0x0c062520u; return 0; }
target=r[16];
write(ram,r[6]+8,r[5],4);
s->pc=target; return ram->oob==0;
P_0c062522: /* original 1652, guest PC 0x0c062522 */
if(!s->budget--) { s->failed_pc=0x0c062522u; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c062524;
P_0c062524: /* original 7ff8, guest PC 0x0c062524 */
if(!s->budget--) { s->failed_pc=0x0c062524u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c062526;
P_0c062526: /* original 5761, guest PC 0x0c062526 */
if(!s->budget--) { s->failed_pc=0x0c062526u; return 0; }
r[7]=read(ram,r[6]+4,4);
goto P_0c062528;
P_0c062528: /* original 2f72, guest PC 0x0c062528 */
if(!s->budget--) { s->failed_pc=0x0c062528u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c06252a;
P_0c06252a: /* original 2778, guest PC 0x0c06252a */
if(!s->budget--) { s->failed_pc=0x0c06252au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06252c;
P_0c06252c: /* original 5362, guest PC 0x0c06252c */
if(!s->budget--) { s->failed_pc=0x0c06252cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06252e;
P_0c06252e: /* original 8f03, guest PC 0x0c06252e */
if(!s->budget--) { s->failed_pc=0x0c06252eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c062538; }
goto P_0c062532;
P_0c062530: /* original 1f31, guest PC 0x0c062530 */
if(!s->budget--) { s->failed_pc=0x0c062530u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c062532;
P_0c062532: /* original 5162, guest PC 0x0c062532 */
if(!s->budget--) { s->failed_pc=0x0c062532u; return 0; }
r[1]=read(ram,r[6]+8,4);
goto P_0c062534;
P_0c062534: /* original a003, guest PC 0x0c062534 */
if(!s->budget--) { s->failed_pc=0x0c062534u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c06253e;
P_0c062536: /* original 2412, guest PC 0x0c062536 */
if(!s->budget--) { s->failed_pc=0x0c062536u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c062538;
P_0c062538: /* original 62f2, guest PC 0x0c062538 */
if(!s->budget--) { s->failed_pc=0x0c062538u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06253a;
P_0c06253a: /* original 5362, guest PC 0x0c06253a */
if(!s->budget--) { s->failed_pc=0x0c06253au; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06253c;
P_0c06253c: /* original 1232, guest PC 0x0c06253c */
if(!s->budget--) { s->failed_pc=0x0c06253cu; return 0; }
write(ram,r[2]+8,r[3],4);
goto P_0c06253e;
P_0c06253e: /* original 5262, guest PC 0x0c06253e */
if(!s->budget--) { s->failed_pc=0x0c06253eu; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c062540;
P_0c062540: /* original 2228, guest PC 0x0c062540 */
if(!s->budget--) { s->failed_pc=0x0c062540u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c062542;
P_0c062542: /* original 8b02, guest PC 0x0c062542 */
if(!s->budget--) { s->failed_pc=0x0c062542u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06254a; }
goto P_0c062544;
P_0c062544: /* original 5261, guest PC 0x0c062544 */
if(!s->budget--) { s->failed_pc=0x0c062544u; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c062546;
P_0c062546: /* original a003, guest PC 0x0c062546 */
if(!s->budget--) { s->failed_pc=0x0c062546u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c062550;
P_0c062548: /* original 2522, guest PC 0x0c062548 */
if(!s->budget--) { s->failed_pc=0x0c062548u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c06254a;
P_0c06254a: /* original 51f1, guest PC 0x0c06254a */
if(!s->budget--) { s->failed_pc=0x0c06254au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06254c;
P_0c06254c: /* original 5361, guest PC 0x0c06254c */
if(!s->budget--) { s->failed_pc=0x0c06254cu; return 0; }
r[3]=read(ram,r[6]+4,4);
goto P_0c06254e;
P_0c06254e: /* original 1131, guest PC 0x0c06254e */
if(!s->budget--) { s->failed_pc=0x0c06254eu; return 0; }
write(ram,r[1]+4,r[3],4);
goto P_0c062550;
P_0c062550: /* original 000b, guest PC 0x0c062550 */
if(!s->budget--) { s->failed_pc=0x0c062550u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c062552: /* original 7f08, guest PC 0x0c062552 */
if(!s->budget--) { s->failed_pc=0x0c062552u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c062554u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062554u; return 0; } return 1;
P_0c06288c: /* original 2fe6, guest PC 0x0c06288c */
if(!s->budget--) { s->failed_pc=0x0c06288cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06288e;
P_0c06288e: /* original 2fd6, guest PC 0x0c06288e */
if(!s->budget--) { s->failed_pc=0x0c06288eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062890;
P_0c062890: /* original 2fc6, guest PC 0x0c062890 */
if(!s->budget--) { s->failed_pc=0x0c062890u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062892;
P_0c062892: /* original 2fb6, guest PC 0x0c062892 */
if(!s->budget--) { s->failed_pc=0x0c062892u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062894;
P_0c062894: /* original 2fa6, guest PC 0x0c062894 */
if(!s->budget--) { s->failed_pc=0x0c062894u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062896;
P_0c062896: /* original 2f96, guest PC 0x0c062896 */
if(!s->budget--) { s->failed_pc=0x0c062896u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062898;
P_0c062898: /* original 2f86, guest PC 0x0c062898 */
if(!s->budget--) { s->failed_pc=0x0c062898u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06289a;
P_0c06289a: /* original 4f22, guest PC 0x0c06289a */
if(!s->budget--) { s->failed_pc=0x0c06289au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06289c;
P_0c06289c: /* original 7ff0, guest PC 0x0c06289c */
if(!s->budget--) { s->failed_pc=0x0c06289cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c06289e;
P_0c06289e: /* original 6043, guest PC 0x0c06289e */
if(!s->budget--) { s->failed_pc=0x0c06289eu; return 0; }
r[0]=r[4];
goto P_0c0628a0;
P_0c0628a0: /* original 0009, guest PC 0x0c0628a0 */
if(!s->budget--) { s->failed_pc=0x0c0628a0u; return 0; }
goto P_0c0628a2;
P_0c0628a2: /* original 6b53, guest PC 0x0c0628a2 */
if(!s->budget--) { s->failed_pc=0x0c0628a2u; return 0; }
r[11]=r[5];
goto P_0c0628a4;
P_0c0628a4: /* original d316, guest PC 0x0c0628a4 */
if(!s->budget--) { s->failed_pc=0x0c0628a4u; return 0; }
r[3]=read(ram,0x0c062900u,4);
goto P_0c0628a6;
P_0c0628a6: /* original 6c63, guest PC 0x0c0628a6 */
if(!s->budget--) { s->failed_pc=0x0c0628a6u; return 0; }
r[12]=r[6];
goto P_0c0628a8;
P_0c0628a8: /* original 81f2, guest PC 0x0c0628a8 */
if(!s->budget--) { s->failed_pc=0x0c0628a8u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0628aa;
P_0c0628aa: /* original 6a73, guest PC 0x0c0628aa */
if(!s->budget--) { s->failed_pc=0x0c0628aau; return 0; }
r[10]=r[7];
goto P_0c0628ac;
P_0c0628ac: /* original 6653, guest PC 0x0c0628ac */
if(!s->budget--) { s->failed_pc=0x0c0628acu; return 0; }
r[6]=r[5];
goto P_0c0628ae;
P_0c0628ae: /* original 36cc, guest PC 0x0c0628ae */
if(!s->budget--) { s->failed_pc=0x0c0628aeu; return 0; }
r[6]+=r[12];
goto P_0c0628b0;
P_0c0628b0: /* original 61c3, guest PC 0x0c0628b0 */
if(!s->budget--) { s->failed_pc=0x0c0628b0u; return 0; }
r[1]=r[12];
goto P_0c0628b2;
P_0c0628b2: /* original 430b, guest PC 0x0c0628b2 */
if(!s->budget--) { s->failed_pc=0x0c0628b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0628b6u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0628b6u) { target=s->pc; goto dispatch; }
goto P_0c0628b6;
P_0c0628b4: /* original e020, guest PC 0x0c0628b4 */
if(!s->budget--) { s->failed_pc=0x0c0628b4u; return 0; }
r[0]=0x00000020u;
goto P_0c0628b6;
P_0c0628b6: /* original 6403, guest PC 0x0c0628b6 */
if(!s->budget--) { s->failed_pc=0x0c0628b6u; return 0; }
r[4]=r[0];
goto P_0c0628b8;
P_0c0628b8: /* original 2448, guest PC 0x0c0628b8 */
if(!s->budget--) { s->failed_pc=0x0c0628b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0628ba;
P_0c0628ba: /* original 8d03, guest PC 0x0c0628ba */
if(!s->budget--) { s->failed_pc=0x0c0628bau; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c0628c4; }
goto P_0c0628be;
P_0c0628bc: /* original ed00, guest PC 0x0c0628bc */
if(!s->budget--) { s->failed_pc=0x0c0628bcu; return 0; }
r[13]=0x00000000u;
goto P_0c0628be;
P_0c0628be: /* original e320, guest PC 0x0c0628be */
if(!s->budget--) { s->failed_pc=0x0c0628beu; return 0; }
r[3]=0x00000020u;
goto P_0c0628c0;
P_0c0628c0: /* original 3348, guest PC 0x0c0628c0 */
if(!s->budget--) { s->failed_pc=0x0c0628c0u; return 0; }
r[3]-=r[4];
goto P_0c0628c2;
P_0c0628c2: /* original 3c3c, guest PC 0x0c0628c2 */
if(!s->budget--) { s->failed_pc=0x0c0628c2u; return 0; }
r[12]+=r[3];
goto P_0c0628c4;
P_0c0628c4: /* original d80f, guest PC 0x0c0628c4 */
if(!s->budget--) { s->failed_pc=0x0c0628c4u; return 0; }
r[8]=read(ram,0x0c062904u,4);
goto P_0c0628c6;
P_0c0628c6: /* original 85f2, guest PC 0x0c0628c6 */
if(!s->budget--) { s->failed_pc=0x0c0628c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0628c8;
P_0c0628c8: /* original 6903, guest PC 0x0c0628c8 */
if(!s->budget--) { s->failed_pc=0x0c0628c8u; return 0; }
r[9]=r[0];
goto P_0c0628ca;
P_0c0628ca: /* original 6393, guest PC 0x0c0628ca */
if(!s->budget--) { s->failed_pc=0x0c0628cau; return 0; }
r[3]=r[9];
goto P_0c0628cc;
P_0c0628cc: /* original 4908, guest PC 0x0c0628cc */
if(!s->budget--) { s->failed_pc=0x0c0628ccu; return 0; }
r[9]<<=2;
goto P_0c0628ce;
P_0c0628ce: /* original 393c, guest PC 0x0c0628ce */
if(!s->budget--) { s->failed_pc=0x0c0628ceu; return 0; }
r[9]+=r[3];
goto P_0c0628d0;
P_0c0628d0: /* original 4908, guest PC 0x0c0628d0 */
if(!s->budget--) { s->failed_pc=0x0c0628d0u; return 0; }
r[9]<<=2;
goto P_0c0628d2;
P_0c0628d2: /* original 699e, guest PC 0x0c0628d2 */
if(!s->budget--) { s->failed_pc=0x0c0628d2u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)r[9];
goto P_0c0628d4;
P_0c0628d4: /* original 6493, guest PC 0x0c0628d4 */
if(!s->budget--) { s->failed_pc=0x0c0628d4u; return 0; }
r[4]=r[9];
goto P_0c0628d6;
P_0c0628d6: /* original 348c, guest PC 0x0c0628d6 */
if(!s->budget--) { s->failed_pc=0x0c0628d6u; return 0; }
r[4]+=r[8];
goto P_0c0628d8;
P_0c0628d8: /* original 5442, guest PC 0x0c0628d8 */
if(!s->budget--) { s->failed_pc=0x0c0628d8u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c0628da;
P_0c0628da: /* original 2448, guest PC 0x0c0628da */
if(!s->budget--) { s->failed_pc=0x0c0628dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0628dc;
P_0c0628dc: /* original 8917, guest PC 0x0c0628dc */
if(!s->budget--) { s->failed_pc=0x0c0628dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06290e; }
goto P_0c0628de;
P_0c0628de: /* original 5543, guest PC 0x0c0628de */
if(!s->budget--) { s->failed_pc=0x0c0628deu; return 0; }
r[5]=read(ram,r[4]+12,4);
goto P_0c0628e0;
P_0c0628e0: /* original 35b7, guest PC 0x0c0628e0 */
if(!s->budget--) { s->failed_pc=0x0c0628e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[11])!=0);
goto P_0c0628e2;
P_0c0628e2: /* original 8911, guest PC 0x0c0628e2 */
if(!s->budget--) { s->failed_pc=0x0c0628e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062908; }
goto P_0c0628e4;
P_0c0628e4: /* original 5344, guest PC 0x0c0628e4 */
if(!s->budget--) { s->failed_pc=0x0c0628e4u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c0628e6;
P_0c0628e6: /* original 335c, guest PC 0x0c0628e6 */
if(!s->budget--) { s->failed_pc=0x0c0628e6u; return 0; }
r[3]+=r[5];
goto P_0c0628e8;
P_0c0628e8: /* original 33b7, guest PC 0x0c0628e8 */
if(!s->budget--) { s->failed_pc=0x0c0628e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[11])!=0);
goto P_0c0628ea;
P_0c0628ea: /* original 8b0d, guest PC 0x0c0628ea */
if(!s->budget--) { s->failed_pc=0x0c0628eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062908; }
goto P_0c0628ec;
P_0c0628ec: /* original 3567, guest PC 0x0c0628ec */
if(!s->budget--) { s->failed_pc=0x0c0628ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[6])!=0);
goto P_0c0628ee;
P_0c0628ee: /* original 890b, guest PC 0x0c0628ee */
if(!s->budget--) { s->failed_pc=0x0c0628eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062908; }
goto P_0c0628f0;
P_0c0628f0: /* original 5244, guest PC 0x0c0628f0 */
if(!s->budget--) { s->failed_pc=0x0c0628f0u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0628f2;
P_0c0628f2: /* original 325c, guest PC 0x0c0628f2 */
if(!s->budget--) { s->failed_pc=0x0c0628f2u; return 0; }
r[2]+=r[5];
goto P_0c0628f4;
P_0c0628f4: /* original 3263, guest PC 0x0c0628f4 */
if(!s->budget--) { s->failed_pc=0x0c0628f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[6])!=0);
goto P_0c0628f6;
P_0c0628f6: /* original 8b07, guest PC 0x0c0628f6 */
if(!s->budget--) { s->failed_pc=0x0c0628f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062908; }
goto P_0c0628f8;
P_0c0628f8: /* original 6d43, guest PC 0x0c0628f8 */
if(!s->budget--) { s->failed_pc=0x0c0628f8u; return 0; }
r[13]=r[4];
goto P_0c0628fa;
P_0c0628fa: /* original a006, guest PC 0x0c0628fa */
if(!s->budget--) { s->failed_pc=0x0c0628fau; return 0; }
r[4]=0x00000000u;
goto P_0c06290a;
P_0c0628fc: /* original e400, guest PC 0x0c0628fc */
if(!s->budget--) { s->failed_pc=0x0c0628fcu; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c0628feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0628feu; return 0; } return 1;
P_0c062908: /* original 5442, guest PC 0x0c062908 */
if(!s->budget--) { s->failed_pc=0x0c062908u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c06290a;
P_0c06290a: /* original 2448, guest PC 0x0c06290a */
if(!s->budget--) { s->failed_pc=0x0c06290au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06290c;
P_0c06290c: /* original 8be7, guest PC 0x0c06290c */
if(!s->budget--) { s->failed_pc=0x0c06290cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0628de; }
goto P_0c06290e;
P_0c06290e: /* original 2dd8, guest PC 0x0c06290e */
if(!s->budget--) { s->failed_pc=0x0c06290eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c062910;
P_0c062910: /* original 8b01, guest PC 0x0c062910 */
if(!s->budget--) { s->failed_pc=0x0c062910u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062916; }
goto P_0c062912;
P_0c062912: /* original a0a9, guest PC 0x0c062912 */
if(!s->budget--) { s->failed_pc=0x0c062912u; return 0; }
goto P_0c062a68;
P_0c062914: /* original 0009, guest PC 0x0c062914 */
if(!s->budget--) { s->failed_pc=0x0c062914u; return 0; }
goto P_0c062916;
P_0c062916: /* original 53d4, guest PC 0x0c062916 */
if(!s->budget--) { s->failed_pc=0x0c062916u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c062918;
P_0c062918: /* original 33c0, guest PC 0x0c062918 */
if(!s->budget--) { s->failed_pc=0x0c062918u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[12])!=0);
goto P_0c06291a;
P_0c06291a: /* original 8b2f, guest PC 0x0c06291a */
if(!s->budget--) { s->failed_pc=0x0c06291au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06297c; }
goto P_0c06291c;
P_0c06291c: /* original 66d3, guest PC 0x0c06291c */
if(!s->budget--) { s->failed_pc=0x0c06291cu; return 0; }
r[6]=r[13];
goto P_0c06291e;
P_0c06291e: /* original 6e93, guest PC 0x0c06291e */
if(!s->budget--) { s->failed_pc=0x0c06291eu; return 0; }
r[14]=r[9];
goto P_0c062920;
P_0c062920: /* original 3e8c, guest PC 0x0c062920 */
if(!s->budget--) { s->failed_pc=0x0c062920u; return 0; }
r[14]+=r[8];
goto P_0c062922;
P_0c062922: /* original 65e3, guest PC 0x0c062922 */
if(!s->budget--) { s->failed_pc=0x0c062922u; return 0; }
r[5]=r[14];
goto P_0c062924;
P_0c062924: /* original 750c, guest PC 0x0c062924 */
if(!s->budget--) { s->failed_pc=0x0c062924u; return 0; }
r[5]+=0x0000000cu;
goto P_0c062926;
P_0c062926: /* original 64e3, guest PC 0x0c062926 */
if(!s->budget--) { s->failed_pc=0x0c062926u; return 0; }
r[4]=r[14];
goto P_0c062928;
P_0c062928: /* original bdfc, guest PC 0x0c062928 */
if(!s->budget--) { s->failed_pc=0x0c062928u; return 0; }
target=code_base|0x0c062524u; r[16]=code_base|0x0c06292cu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06292cu) { target=s->pc; goto dispatch; }
goto P_0c06292c;
P_0c06292a: /* original 7408, guest PC 0x0c06292a */
if(!s->budget--) { s->failed_pc=0x0c06292au; return 0; }
r[4]+=0x00000008u;
goto P_0c06292c;
P_0c06292c: /* original 66d3, guest PC 0x0c06292c */
if(!s->budget--) { s->failed_pc=0x0c06292cu; return 0; }
r[6]=r[13];
goto P_0c06292e;
P_0c06292e: /* original 65e3, guest PC 0x0c06292e */
if(!s->budget--) { s->failed_pc=0x0c06292eu; return 0; }
r[5]=r[14];
goto P_0c062930;
P_0c062930: /* original 7504, guest PC 0x0c062930 */
if(!s->budget--) { s->failed_pc=0x0c062930u; return 0; }
r[5]+=0x00000004u;
goto P_0c062932;
P_0c062932: /* original bdd7, guest PC 0x0c062932 */
if(!s->budget--) { s->failed_pc=0x0c062932u; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c062936u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062936u) { target=s->pc; goto dispatch; }
goto P_0c062936;
P_0c062934: /* original 64e3, guest PC 0x0c062934 */
if(!s->budget--) { s->failed_pc=0x0c062934u; return 0; }
r[4]=r[14];
goto P_0c062936;
P_0c062936: /* original e201, guest PC 0x0c062936 */
if(!s->budget--) { s->failed_pc=0x0c062936u; return 0; }
r[2]=0x00000001u;
goto P_0c062938;
P_0c062938: /* original 53d3, guest PC 0x0c062938 */
if(!s->budget--) { s->failed_pc=0x0c062938u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c06293a;
P_0c06293a: /* original 1a32, guest PC 0x0c06293a */
if(!s->budget--) { s->failed_pc=0x0c06293au; return 0; }
write(ram,r[10]+8,r[3],4);
goto P_0c06293c;
P_0c06293c: /* original 1da5, guest PC 0x0c06293c */
if(!s->budget--) { s->failed_pc=0x0c06293cu; return 0; }
write(ram,r[13]+20,r[10],4);
goto P_0c06293e;
P_0c06293e: /* original 2d21, guest PC 0x0c06293e */
if(!s->budget--) { s->failed_pc=0x0c06293eu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c062940;
P_0c062940: /* original 85f2, guest PC 0x0c062940 */
if(!s->budget--) { s->failed_pc=0x0c062940u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c062942;
P_0c062942: /* original 2008, guest PC 0x0c062942 */
if(!s->budget--) { s->failed_pc=0x0c062942u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c062944;
P_0c062944: /* original 8b04, guest PC 0x0c062944 */
if(!s->budget--) { s->failed_pc=0x0c062944u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062950; }
goto P_0c062946;
P_0c062946: /* original 934f, guest PC 0x0c062946 */
if(!s->budget--) { s->failed_pc=0x0c062946u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0629e8u,2);
goto P_0c062948;
P_0c062948: /* original 62d1, guest PC 0x0c062948 */
if(!s->budget--) { s->failed_pc=0x0c062948u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c06294a;
P_0c06294a: /* original 223b, guest PC 0x0c06294a */
if(!s->budget--) { s->failed_pc=0x0c06294au; return 0; }
r[2]|=r[3];
goto P_0c06294c;
P_0c06294c: /* original a004, guest PC 0x0c06294c */
if(!s->budget--) { s->failed_pc=0x0c06294cu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c062958;
P_0c06294e: /* original 2d21, guest PC 0x0c06294e */
if(!s->budget--) { s->failed_pc=0x0c06294eu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c062950;
P_0c062950: /* original 934b, guest PC 0x0c062950 */
if(!s->budget--) { s->failed_pc=0x0c062950u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0629eau,2);
goto P_0c062952;
P_0c062952: /* original 61d1, guest PC 0x0c062952 */
if(!s->budget--) { s->failed_pc=0x0c062952u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[1]=tmp;
goto P_0c062954;
P_0c062954: /* original 213b, guest PC 0x0c062954 */
if(!s->budget--) { s->failed_pc=0x0c062954u; return 0; }
r[1]|=r[3];
goto P_0c062956;
P_0c062956: /* original 2d11, guest PC 0x0c062956 */
if(!s->budget--) { s->failed_pc=0x0c062956u; return 0; }
write(ram,r[13],r[1],2);
goto P_0c062958;
P_0c062958: /* original 52fc, guest PC 0x0c062958 */
if(!s->budget--) { s->failed_pc=0x0c062958u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c06295a;
P_0c06295a: /* original 2228, guest PC 0x0c06295a */
if(!s->budget--) { s->failed_pc=0x0c06295au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06295c;
P_0c06295c: /* original 8902, guest PC 0x0c06295c */
if(!s->budget--) { s->failed_pc=0x0c06295cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062964; }
goto P_0c06295e;
P_0c06295e: /* original 60d1, guest PC 0x0c06295e */
if(!s->budget--) { s->failed_pc=0x0c06295eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c062960;
P_0c062960: /* original cb02, guest PC 0x0c062960 */
if(!s->budget--) { s->failed_pc=0x0c062960u; return 0; }
r[0]|=2u;
goto P_0c062962;
P_0c062962: /* original 2d01, guest PC 0x0c062962 */
if(!s->budget--) { s->failed_pc=0x0c062962u; return 0; }
write(ram,r[13],r[0],2);
goto P_0c062964;
P_0c062964: /* original 53fd, guest PC 0x0c062964 */
if(!s->budget--) { s->failed_pc=0x0c062964u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c062966;
P_0c062966: /* original 2338, guest PC 0x0c062966 */
if(!s->budget--) { s->failed_pc=0x0c062966u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062968;
P_0c062968: /* original 8d03, guest PC 0x0c062968 */
if(!s->budget--) { s->failed_pc=0x0c062968u; return 0; }
cond=r[17]&1u;
r[9]+=r[8];
if(cond) { goto P_0c062972; }
goto P_0c06296c;
P_0c06296a: /* original 398c, guest PC 0x0c06296a */
if(!s->budget--) { s->failed_pc=0x0c06296au; return 0; }
r[9]+=r[8];
goto P_0c06296c;
P_0c06296c: /* original 60d1, guest PC 0x0c06296c */
if(!s->budget--) { s->failed_pc=0x0c06296cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c06296e;
P_0c06296e: /* original cb04, guest PC 0x0c06296e */
if(!s->budget--) { s->failed_pc=0x0c06296eu; return 0; }
r[0]|=4u;
goto P_0c062970;
P_0c062970: /* original 2d01, guest PC 0x0c062970 */
if(!s->budget--) { s->failed_pc=0x0c062970u; return 0; }
write(ram,r[13],r[0],2);
goto P_0c062972;
P_0c062972: /* original 53d4, guest PC 0x0c062972 */
if(!s->budget--) { s->failed_pc=0x0c062972u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c062974;
P_0c062974: /* original 5294, guest PC 0x0c062974 */
if(!s->budget--) { s->failed_pc=0x0c062974u; return 0; }
r[2]=read(ram,r[9]+16,4);
goto P_0c062976;
P_0c062976: /* original 3238, guest PC 0x0c062976 */
if(!s->budget--) { s->failed_pc=0x0c062976u; return 0; }
r[2]-=r[3];
goto P_0c062978;
P_0c062978: /* original a0b9, guest PC 0x0c062978 */
if(!s->budget--) { s->failed_pc=0x0c062978u; return 0; }
write(ram,r[9]+16,r[2],4);
goto P_0c062aee;
P_0c06297a: /* original 1924, guest PC 0x0c06297a */
if(!s->budget--) { s->failed_pc=0x0c06297au; return 0; }
write(ram,r[9]+16,r[2],4);
goto P_0c06297c;
P_0c06297c: /* original 50d3, guest PC 0x0c06297c */
if(!s->budget--) { s->failed_pc=0x0c06297cu; return 0; }
r[0]=read(ram,r[13]+12,4);
goto P_0c06297e;
P_0c06297e: /* original 30b0, guest PC 0x0c06297e */
if(!s->budget--) { s->failed_pc=0x0c06297eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[11])!=0);
goto P_0c062980;
P_0c062980: /* original 8b34, guest PC 0x0c062980 */
if(!s->budget--) { s->failed_pc=0x0c062980u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0629ec; }
goto P_0c062982;
P_0c062982: /* original bd85, guest PC 0x0c062982 */
if(!s->budget--) { s->failed_pc=0x0c062982u; return 0; }
target=code_base|0x0c062490u; r[16]=code_base|0x0c062986u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062986u) { target=s->pc; goto dispatch; }
goto P_0c062986;
P_0c062984: /* original 0009, guest PC 0x0c062984 */
if(!s->budget--) { s->failed_pc=0x0c062984u; return 0; }
goto P_0c062986;
P_0c062986: /* original 6e03, guest PC 0x0c062986 */
if(!s->budget--) { s->failed_pc=0x0c062986u; return 0; }
r[14]=r[0];
goto P_0c062988;
P_0c062988: /* original 2ee8, guest PC 0x0c062988 */
if(!s->budget--) { s->failed_pc=0x0c062988u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06298a;
P_0c06298a: /* original 896d, guest PC 0x0c06298a */
if(!s->budget--) { s->failed_pc=0x0c06298au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062a68; }
goto P_0c06298c;
P_0c06298c: /* original 53d3, guest PC 0x0c06298c */
if(!s->budget--) { s->failed_pc=0x0c06298cu; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c06298e;
P_0c06298e: /* original 66e3, guest PC 0x0c06298e */
if(!s->budget--) { s->failed_pc=0x0c06298eu; return 0; }
r[6]=r[14];
goto P_0c062990;
P_0c062990: /* original 1e33, guest PC 0x0c062990 */
if(!s->budget--) { s->failed_pc=0x0c062990u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c062992;
P_0c062992: /* original 6593, guest PC 0x0c062992 */
if(!s->budget--) { s->failed_pc=0x0c062992u; return 0; }
r[5]=r[9];
goto P_0c062994;
P_0c062994: /* original 1ec4, guest PC 0x0c062994 */
if(!s->budget--) { s->failed_pc=0x0c062994u; return 0; }
write(ram,r[14]+16,r[12],4);
goto P_0c062996;
P_0c062996: /* original 358c, guest PC 0x0c062996 */
if(!s->budget--) { s->failed_pc=0x0c062996u; return 0; }
r[5]+=r[8];
goto P_0c062998;
P_0c062998: /* original 54d4, guest PC 0x0c062998 */
if(!s->budget--) { s->failed_pc=0x0c062998u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c06299a;
P_0c06299a: /* original 34c8, guest PC 0x0c06299a */
if(!s->budget--) { s->failed_pc=0x0c06299au; return 0; }
r[4]-=r[12];
goto P_0c06299c;
P_0c06299c: /* original 1d44, guest PC 0x0c06299c */
if(!s->budget--) { s->failed_pc=0x0c06299cu; return 0; }
write(ram,r[13]+16,r[4],4);
goto P_0c06299e;
P_0c06299e: /* original 52d3, guest PC 0x0c06299e */
if(!s->budget--) { s->failed_pc=0x0c06299eu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0629a0;
P_0c0629a0: /* original 32cc, guest PC 0x0c0629a0 */
if(!s->budget--) { s->failed_pc=0x0c0629a0u; return 0; }
r[2]+=r[12];
goto P_0c0629a2;
P_0c0629a2: /* original 1d23, guest PC 0x0c0629a2 */
if(!s->budget--) { s->failed_pc=0x0c0629a2u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0629a4;
P_0c0629a4: /* original 2f52, guest PC 0x0c0629a4 */
if(!s->budget--) { s->failed_pc=0x0c0629a4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0629a6;
P_0c0629a6: /* original 7504, guest PC 0x0c0629a6 */
if(!s->budget--) { s->failed_pc=0x0c0629a6u; return 0; }
r[5]+=0x00000004u;
goto P_0c0629a8;
P_0c0629a8: /* original bd9c, guest PC 0x0c0629a8 */
if(!s->budget--) { s->failed_pc=0x0c0629a8u; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c0629acu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0629acu) { target=s->pc; goto dispatch; }
goto P_0c0629ac;
P_0c0629aa: /* original 64f2, guest PC 0x0c0629aa */
if(!s->budget--) { s->failed_pc=0x0c0629aau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0629ac;
P_0c0629ac: /* original 52e3, guest PC 0x0c0629ac */
if(!s->budget--) { s->failed_pc=0x0c0629acu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0629ae;
P_0c0629ae: /* original 1a22, guest PC 0x0c0629ae */
if(!s->budget--) { s->failed_pc=0x0c0629aeu; return 0; }
write(ram,r[10]+8,r[2],4);
goto P_0c0629b0;
P_0c0629b0: /* original 1ea5, guest PC 0x0c0629b0 */
if(!s->budget--) { s->failed_pc=0x0c0629b0u; return 0; }
write(ram,r[14]+20,r[10],4);
goto P_0c0629b2;
P_0c0629b2: /* original 85f2, guest PC 0x0c0629b2 */
if(!s->budget--) { s->failed_pc=0x0c0629b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0629b4;
P_0c0629b4: /* original 2008, guest PC 0x0c0629b4 */
if(!s->budget--) { s->failed_pc=0x0c0629b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0629b6;
P_0c0629b6: /* original 8b04, guest PC 0x0c0629b6 */
if(!s->budget--) { s->failed_pc=0x0c0629b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0629c2; }
goto P_0c0629b8;
P_0c0629b8: /* original 9316, guest PC 0x0c0629b8 */
if(!s->budget--) { s->failed_pc=0x0c0629b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0629e8u,2);
goto P_0c0629ba;
P_0c0629ba: /* original 62e1, guest PC 0x0c0629ba */
if(!s->budget--) { s->failed_pc=0x0c0629bau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0629bc;
P_0c0629bc: /* original 223b, guest PC 0x0c0629bc */
if(!s->budget--) { s->failed_pc=0x0c0629bcu; return 0; }
r[2]|=r[3];
goto P_0c0629be;
P_0c0629be: /* original a004, guest PC 0x0c0629be */
if(!s->budget--) { s->failed_pc=0x0c0629beu; return 0; }
write(ram,r[14],r[2],2);
goto P_0c0629ca;
P_0c0629c0: /* original 2e21, guest PC 0x0c0629c0 */
if(!s->budget--) { s->failed_pc=0x0c0629c0u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c0629c2;
P_0c0629c2: /* original 9312, guest PC 0x0c0629c2 */
if(!s->budget--) { s->failed_pc=0x0c0629c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0629eau,2);
goto P_0c0629c4;
P_0c0629c4: /* original 61e1, guest PC 0x0c0629c4 */
if(!s->budget--) { s->failed_pc=0x0c0629c4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c0629c6;
P_0c0629c6: /* original 213b, guest PC 0x0c0629c6 */
if(!s->budget--) { s->failed_pc=0x0c0629c6u; return 0; }
r[1]|=r[3];
goto P_0c0629c8;
P_0c0629c8: /* original 2e11, guest PC 0x0c0629c8 */
if(!s->budget--) { s->failed_pc=0x0c0629c8u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c0629ca;
P_0c0629ca: /* original 52fc, guest PC 0x0c0629ca */
if(!s->budget--) { s->failed_pc=0x0c0629cau; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c0629cc;
P_0c0629cc: /* original 2228, guest PC 0x0c0629cc */
if(!s->budget--) { s->failed_pc=0x0c0629ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0629ce;
P_0c0629ce: /* original 8902, guest PC 0x0c0629ce */
if(!s->budget--) { s->failed_pc=0x0c0629ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0629d6; }
goto P_0c0629d0;
P_0c0629d0: /* original 60e1, guest PC 0x0c0629d0 */
if(!s->budget--) { s->failed_pc=0x0c0629d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0629d2;
P_0c0629d2: /* original cb02, guest PC 0x0c0629d2 */
if(!s->budget--) { s->failed_pc=0x0c0629d2u; return 0; }
r[0]|=2u;
goto P_0c0629d4;
P_0c0629d4: /* original 2e01, guest PC 0x0c0629d4 */
if(!s->budget--) { s->failed_pc=0x0c0629d4u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c0629d6;
P_0c0629d6: /* original 53fd, guest PC 0x0c0629d6 */
if(!s->budget--) { s->failed_pc=0x0c0629d6u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0629d8;
P_0c0629d8: /* original 2338, guest PC 0x0c0629d8 */
if(!s->budget--) { s->failed_pc=0x0c0629d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0629da;
P_0c0629da: /* original 8b01, guest PC 0x0c0629da */
if(!s->budget--) { s->failed_pc=0x0c0629dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0629e0; }
goto P_0c0629dc;
P_0c0629dc: /* original a082, guest PC 0x0c0629dc */
if(!s->budget--) { s->failed_pc=0x0c0629dcu; return 0; }
goto P_0c062ae4;
P_0c0629de: /* original 0009, guest PC 0x0c0629de */
if(!s->budget--) { s->failed_pc=0x0c0629deu; return 0; }
goto P_0c0629e0;
P_0c0629e0: /* original 60e1, guest PC 0x0c0629e0 */
if(!s->budget--) { s->failed_pc=0x0c0629e0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0629e2;
P_0c0629e2: /* original cb04, guest PC 0x0c0629e2 */
if(!s->budget--) { s->failed_pc=0x0c0629e2u; return 0; }
r[0]|=4u;
goto P_0c0629e4;
P_0c0629e4: /* original a07e, guest PC 0x0c0629e4 */
if(!s->budget--) { s->failed_pc=0x0c0629e4u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c062ae4;
P_0c0629e6: /* original 2e01, guest PC 0x0c0629e6 */
if(!s->budget--) { s->failed_pc=0x0c0629e6u; return 0; }
write(ram,r[14],r[0],2);
if(!vf3_matrix_family(0x0c0629e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0629e8u; return 0; } return 1;
P_0c0629ec: /* original 53d4, guest PC 0x0c0629ec */
if(!s->budget--) { s->failed_pc=0x0c0629ecu; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0629ee;
P_0c0629ee: /* original 52d3, guest PC 0x0c0629ee */
if(!s->budget--) { s->failed_pc=0x0c0629eeu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0629f0;
P_0c0629f0: /* original 323c, guest PC 0x0c0629f0 */
if(!s->budget--) { s->failed_pc=0x0c0629f0u; return 0; }
r[2]+=r[3];
goto P_0c0629f2;
P_0c0629f2: /* original 3260, guest PC 0x0c0629f2 */
if(!s->budget--) { s->failed_pc=0x0c0629f2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[6])!=0);
goto P_0c0629f4;
P_0c0629f4: /* original 8b2c, guest PC 0x0c0629f4 */
if(!s->budget--) { s->failed_pc=0x0c0629f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062a50; }
goto P_0c0629f6;
P_0c0629f6: /* original bd4b, guest PC 0x0c0629f6 */
if(!s->budget--) { s->failed_pc=0x0c0629f6u; return 0; }
target=code_base|0x0c062490u; r[16]=code_base|0x0c0629fau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0629fau) { target=s->pc; goto dispatch; }
goto P_0c0629fa;
P_0c0629f8: /* original 0009, guest PC 0x0c0629f8 */
if(!s->budget--) { s->failed_pc=0x0c0629f8u; return 0; }
goto P_0c0629fa;
P_0c0629fa: /* original 6e03, guest PC 0x0c0629fa */
if(!s->budget--) { s->failed_pc=0x0c0629fau; return 0; }
r[14]=r[0];
goto P_0c0629fc;
P_0c0629fc: /* original 2ee8, guest PC 0x0c0629fc */
if(!s->budget--) { s->failed_pc=0x0c0629fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0629fe;
P_0c0629fe: /* original 8933, guest PC 0x0c0629fe */
if(!s->budget--) { s->failed_pc=0x0c0629feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062a68; }
goto P_0c062a00;
P_0c062a00: /* original 54d4, guest PC 0x0c062a00 */
if(!s->budget--) { s->failed_pc=0x0c062a00u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c062a02;
P_0c062a02: /* original 66e3, guest PC 0x0c062a02 */
if(!s->budget--) { s->failed_pc=0x0c062a02u; return 0; }
r[6]=r[14];
goto P_0c062a04;
P_0c062a04: /* original 34c8, guest PC 0x0c062a04 */
if(!s->budget--) { s->failed_pc=0x0c062a04u; return 0; }
r[4]-=r[12];
goto P_0c062a06;
P_0c062a06: /* original 6593, guest PC 0x0c062a06 */
if(!s->budget--) { s->failed_pc=0x0c062a06u; return 0; }
r[5]=r[9];
goto P_0c062a08;
P_0c062a08: /* original 1d44, guest PC 0x0c062a08 */
if(!s->budget--) { s->failed_pc=0x0c062a08u; return 0; }
write(ram,r[13]+16,r[4],4);
goto P_0c062a0a;
P_0c062a0a: /* original 358c, guest PC 0x0c062a0a */
if(!s->budget--) { s->failed_pc=0x0c062a0au; return 0; }
r[5]+=r[8];
goto P_0c062a0c;
P_0c062a0c: /* original 1eb3, guest PC 0x0c062a0c */
if(!s->budget--) { s->failed_pc=0x0c062a0cu; return 0; }
write(ram,r[14]+12,r[11],4);
goto P_0c062a0e;
P_0c062a0e: /* original 1ec4, guest PC 0x0c062a0e */
if(!s->budget--) { s->failed_pc=0x0c062a0eu; return 0; }
write(ram,r[14]+16,r[12],4);
goto P_0c062a10;
P_0c062a10: /* original 2f52, guest PC 0x0c062a10 */
if(!s->budget--) { s->failed_pc=0x0c062a10u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062a12;
P_0c062a12: /* original 7504, guest PC 0x0c062a12 */
if(!s->budget--) { s->failed_pc=0x0c062a12u; return 0; }
r[5]+=0x00000004u;
goto P_0c062a14;
P_0c062a14: /* original bd66, guest PC 0x0c062a14 */
if(!s->budget--) { s->failed_pc=0x0c062a14u; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c062a18u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062a18u) { target=s->pc; goto dispatch; }
goto P_0c062a18;
P_0c062a16: /* original 64f2, guest PC 0x0c062a16 */
if(!s->budget--) { s->failed_pc=0x0c062a16u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c062a18;
P_0c062a18: /* original 52e3, guest PC 0x0c062a18 */
if(!s->budget--) { s->failed_pc=0x0c062a18u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062a1a;
P_0c062a1a: /* original 1a22, guest PC 0x0c062a1a */
if(!s->budget--) { s->failed_pc=0x0c062a1au; return 0; }
write(ram,r[10]+8,r[2],4);
goto P_0c062a1c;
P_0c062a1c: /* original 1ea5, guest PC 0x0c062a1c */
if(!s->budget--) { s->failed_pc=0x0c062a1cu; return 0; }
write(ram,r[14]+20,r[10],4);
goto P_0c062a1e;
P_0c062a1e: /* original 85f2, guest PC 0x0c062a1e */
if(!s->budget--) { s->failed_pc=0x0c062a1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c062a20;
P_0c062a20: /* original 2008, guest PC 0x0c062a20 */
if(!s->budget--) { s->failed_pc=0x0c062a20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c062a22;
P_0c062a22: /* original 8b04, guest PC 0x0c062a22 */
if(!s->budget--) { s->failed_pc=0x0c062a22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062a2e; }
goto P_0c062a24;
P_0c062a24: /* original 934c, guest PC 0x0c062a24 */
if(!s->budget--) { s->failed_pc=0x0c062a24u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062ac0u,2);
goto P_0c062a26;
P_0c062a26: /* original 62e1, guest PC 0x0c062a26 */
if(!s->budget--) { s->failed_pc=0x0c062a26u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c062a28;
P_0c062a28: /* original 223b, guest PC 0x0c062a28 */
if(!s->budget--) { s->failed_pc=0x0c062a28u; return 0; }
r[2]|=r[3];
goto P_0c062a2a;
P_0c062a2a: /* original a004, guest PC 0x0c062a2a */
if(!s->budget--) { s->failed_pc=0x0c062a2au; return 0; }
write(ram,r[14],r[2],2);
goto P_0c062a36;
P_0c062a2c: /* original 2e21, guest PC 0x0c062a2c */
if(!s->budget--) { s->failed_pc=0x0c062a2cu; return 0; }
write(ram,r[14],r[2],2);
goto P_0c062a2e;
P_0c062a2e: /* original 9348, guest PC 0x0c062a2e */
if(!s->budget--) { s->failed_pc=0x0c062a2eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062ac2u,2);
goto P_0c062a30;
P_0c062a30: /* original 61e1, guest PC 0x0c062a30 */
if(!s->budget--) { s->failed_pc=0x0c062a30u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c062a32;
P_0c062a32: /* original 213b, guest PC 0x0c062a32 */
if(!s->budget--) { s->failed_pc=0x0c062a32u; return 0; }
r[1]|=r[3];
goto P_0c062a34;
P_0c062a34: /* original 2e11, guest PC 0x0c062a34 */
if(!s->budget--) { s->failed_pc=0x0c062a34u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c062a36;
P_0c062a36: /* original 52fc, guest PC 0x0c062a36 */
if(!s->budget--) { s->failed_pc=0x0c062a36u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c062a38;
P_0c062a38: /* original 2228, guest PC 0x0c062a38 */
if(!s->budget--) { s->failed_pc=0x0c062a38u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c062a3a;
P_0c062a3a: /* original 8902, guest PC 0x0c062a3a */
if(!s->budget--) { s->failed_pc=0x0c062a3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062a42; }
goto P_0c062a3c;
P_0c062a3c: /* original 60e1, guest PC 0x0c062a3c */
if(!s->budget--) { s->failed_pc=0x0c062a3cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c062a3e;
P_0c062a3e: /* original cb02, guest PC 0x0c062a3e */
if(!s->budget--) { s->failed_pc=0x0c062a3eu; return 0; }
r[0]|=2u;
goto P_0c062a40;
P_0c062a40: /* original 2e01, guest PC 0x0c062a40 */
if(!s->budget--) { s->failed_pc=0x0c062a40u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c062a42;
P_0c062a42: /* original 53fd, guest PC 0x0c062a42 */
if(!s->budget--) { s->failed_pc=0x0c062a42u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c062a44;
P_0c062a44: /* original 2338, guest PC 0x0c062a44 */
if(!s->budget--) { s->failed_pc=0x0c062a44u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062a46;
P_0c062a46: /* original 894d, guest PC 0x0c062a46 */
if(!s->budget--) { s->failed_pc=0x0c062a46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062ae4; }
goto P_0c062a48;
P_0c062a48: /* original 60e1, guest PC 0x0c062a48 */
if(!s->budget--) { s->failed_pc=0x0c062a48u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c062a4a;
P_0c062a4a: /* original cb04, guest PC 0x0c062a4a */
if(!s->budget--) { s->failed_pc=0x0c062a4au; return 0; }
r[0]|=4u;
goto P_0c062a4c;
P_0c062a4c: /* original a04a, guest PC 0x0c062a4c */
if(!s->budget--) { s->failed_pc=0x0c062a4cu; return 0; }
write(ram,r[14],r[0],2);
goto P_0c062ae4;
P_0c062a4e: /* original 2e01, guest PC 0x0c062a4e */
if(!s->budget--) { s->failed_pc=0x0c062a4eu; return 0; }
write(ram,r[14],r[0],2);
goto P_0c062a50;
P_0c062a50: /* original bd1e, guest PC 0x0c062a50 */
if(!s->budget--) { s->failed_pc=0x0c062a50u; return 0; }
target=code_base|0x0c062490u; r[16]=code_base|0x0c062a54u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062a54u) { target=s->pc; goto dispatch; }
goto P_0c062a54;
P_0c062a52: /* original 0009, guest PC 0x0c062a52 */
if(!s->budget--) { s->failed_pc=0x0c062a52u; return 0; }
goto P_0c062a54;
P_0c062a54: /* original 6e03, guest PC 0x0c062a54 */
if(!s->budget--) { s->failed_pc=0x0c062a54u; return 0; }
r[14]=r[0];
goto P_0c062a56;
P_0c062a56: /* original 2ee8, guest PC 0x0c062a56 */
if(!s->budget--) { s->failed_pc=0x0c062a56u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c062a58;
P_0c062a58: /* original 8906, guest PC 0x0c062a58 */
if(!s->budget--) { s->failed_pc=0x0c062a58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062a68; }
goto P_0c062a5a;
P_0c062a5a: /* original bd19, guest PC 0x0c062a5a */
if(!s->budget--) { s->failed_pc=0x0c062a5au; return 0; }
target=code_base|0x0c062490u; r[16]=code_base|0x0c062a5eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062a5eu) { target=s->pc; goto dispatch; }
goto P_0c062a5e;
P_0c062a5c: /* original 0009, guest PC 0x0c062a5c */
if(!s->budget--) { s->failed_pc=0x0c062a5cu; return 0; }
goto P_0c062a5e;
P_0c062a5e: /* original 2008, guest PC 0x0c062a5e */
if(!s->budget--) { s->failed_pc=0x0c062a5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c062a60;
P_0c062a60: /* original 8f04, guest PC 0x0c062a60 */
if(!s->budget--) { s->failed_pc=0x0c062a60u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c062a6c; }
goto P_0c062a64;
P_0c062a62: /* original 2f02, guest PC 0x0c062a62 */
if(!s->budget--) { s->failed_pc=0x0c062a62u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c062a64;
P_0c062a64: /* original bd29, guest PC 0x0c062a64 */
if(!s->budget--) { s->failed_pc=0x0c062a64u; return 0; }
target=code_base|0x0c0624bau; r[16]=code_base|0x0c062a68u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062a68u) { target=s->pc; goto dispatch; }
goto P_0c062a68;
P_0c062a66: /* original 64e3, guest PC 0x0c062a66 */
if(!s->budget--) { s->failed_pc=0x0c062a66u; return 0; }
r[4]=r[14];
goto P_0c062a68;
P_0c062a68: /* original a042, guest PC 0x0c062a68 */
if(!s->budget--) { s->failed_pc=0x0c062a68u; return 0; }
r[0]=0x00000003u;
goto P_0c062af0;
P_0c062a6a: /* original e003, guest PC 0x0c062a6a */
if(!s->budget--) { s->failed_pc=0x0c062a6au; return 0; }
r[0]=0x00000003u;
goto P_0c062a6c;
P_0c062a6c: /* original 53d4, guest PC 0x0c062a6c */
if(!s->budget--) { s->failed_pc=0x0c062a6cu; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c062a6e;
P_0c062a6e: /* original 62b3, guest PC 0x0c062a6e */
if(!s->budget--) { s->failed_pc=0x0c062a6eu; return 0; }
r[2]=r[11];
goto P_0c062a70;
P_0c062a70: /* original 1f33, guest PC 0x0c062a70 */
if(!s->budget--) { s->failed_pc=0x0c062a70u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c062a72;
P_0c062a72: /* original 66e3, guest PC 0x0c062a72 */
if(!s->budget--) { s->failed_pc=0x0c062a72u; return 0; }
r[6]=r[14];
goto P_0c062a74;
P_0c062a74: /* original 53d3, guest PC 0x0c062a74 */
if(!s->budget--) { s->failed_pc=0x0c062a74u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c062a76;
P_0c062a76: /* original 3238, guest PC 0x0c062a76 */
if(!s->budget--) { s->failed_pc=0x0c062a76u; return 0; }
r[2]-=r[3];
goto P_0c062a78;
P_0c062a78: /* original 1f22, guest PC 0x0c062a78 */
if(!s->budget--) { s->failed_pc=0x0c062a78u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c062a7a;
P_0c062a7a: /* original 6323, guest PC 0x0c062a7a */
if(!s->budget--) { s->failed_pc=0x0c062a7au; return 0; }
r[3]=r[2];
goto P_0c062a7c;
P_0c062a7c: /* original 1d24, guest PC 0x0c062a7c */
if(!s->budget--) { s->failed_pc=0x0c062a7cu; return 0; }
write(ram,r[13]+16,r[2],4);
goto P_0c062a7e;
P_0c062a7e: /* original 6d93, guest PC 0x0c062a7e */
if(!s->budget--) { s->failed_pc=0x0c062a7eu; return 0; }
r[13]=r[9];
goto P_0c062a80;
P_0c062a80: /* original 1eb3, guest PC 0x0c062a80 */
if(!s->budget--) { s->failed_pc=0x0c062a80u; return 0; }
write(ram,r[14]+12,r[11],4);
goto P_0c062a82;
P_0c062a82: /* original 3d8c, guest PC 0x0c062a82 */
if(!s->budget--) { s->failed_pc=0x0c062a82u; return 0; }
r[13]+=r[8];
goto P_0c062a84;
P_0c062a84: /* original 1ec4, guest PC 0x0c062a84 */
if(!s->budget--) { s->failed_pc=0x0c062a84u; return 0; }
write(ram,r[14]+16,r[12],4);
goto P_0c062a86;
P_0c062a86: /* original 65d3, guest PC 0x0c062a86 */
if(!s->budget--) { s->failed_pc=0x0c062a86u; return 0; }
r[5]=r[13];
goto P_0c062a88;
P_0c062a88: /* original 7504, guest PC 0x0c062a88 */
if(!s->budget--) { s->failed_pc=0x0c062a88u; return 0; }
r[5]+=0x00000004u;
goto P_0c062a8a;
P_0c062a8a: /* original bd2b, guest PC 0x0c062a8a */
if(!s->budget--) { s->failed_pc=0x0c062a8au; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c062a8eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062a8eu) { target=s->pc; goto dispatch; }
goto P_0c062a8e;
P_0c062a8c: /* original 64d3, guest PC 0x0c062a8c */
if(!s->budget--) { s->failed_pc=0x0c062a8cu; return 0; }
r[4]=r[13];
goto P_0c062a8e;
P_0c062a8e: /* original 3bcc, guest PC 0x0c062a8e */
if(!s->budget--) { s->failed_pc=0x0c062a8eu; return 0; }
r[11]+=r[12];
goto P_0c062a90;
P_0c062a90: /* original 62f2, guest PC 0x0c062a90 */
if(!s->budget--) { s->failed_pc=0x0c062a90u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c062a92;
P_0c062a92: /* original 64d3, guest PC 0x0c062a92 */
if(!s->budget--) { s->failed_pc=0x0c062a92u; return 0; }
r[4]=r[13];
goto P_0c062a94;
P_0c062a94: /* original 12b3, guest PC 0x0c062a94 */
if(!s->budget--) { s->failed_pc=0x0c062a94u; return 0; }
write(ram,r[2]+12,r[11],4);
goto P_0c062a96;
P_0c062a96: /* original 63f2, guest PC 0x0c062a96 */
if(!s->budget--) { s->failed_pc=0x0c062a96u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c062a98;
P_0c062a98: /* original 52f3, guest PC 0x0c062a98 */
if(!s->budget--) { s->failed_pc=0x0c062a98u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c062a9a;
P_0c062a9a: /* original 32c8, guest PC 0x0c062a9a */
if(!s->budget--) { s->failed_pc=0x0c062a9au; return 0; }
r[2]-=r[12];
goto P_0c062a9c;
P_0c062a9c: /* original 51f2, guest PC 0x0c062a9c */
if(!s->budget--) { s->failed_pc=0x0c062a9cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c062a9e;
P_0c062a9e: /* original 3218, guest PC 0x0c062a9e */
if(!s->budget--) { s->failed_pc=0x0c062a9eu; return 0; }
r[2]-=r[1];
goto P_0c062aa0;
P_0c062aa0: /* original 1324, guest PC 0x0c062aa0 */
if(!s->budget--) { s->failed_pc=0x0c062aa0u; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c062aa2;
P_0c062aa2: /* original 56d3, guest PC 0x0c062aa2 */
if(!s->budget--) { s->failed_pc=0x0c062aa2u; return 0; }
r[6]=read(ram,r[13]+12,4);
goto P_0c062aa4;
P_0c062aa4: /* original 65f2, guest PC 0x0c062aa4 */
if(!s->budget--) { s->failed_pc=0x0c062aa4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c062aa6;
P_0c062aa6: /* original bd2f, guest PC 0x0c062aa6 */
if(!s->budget--) { s->failed_pc=0x0c062aa6u; return 0; }
target=code_base|0x0c062508u; r[16]=code_base|0x0c062aaau;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062aaau) { target=s->pc; goto dispatch; }
goto P_0c062aaa;
P_0c062aa8: /* original 740c, guest PC 0x0c062aa8 */
if(!s->budget--) { s->failed_pc=0x0c062aa8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c062aaa;
P_0c062aaa: /* original 52e3, guest PC 0x0c062aaa */
if(!s->budget--) { s->failed_pc=0x0c062aaau; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062aac;
P_0c062aac: /* original 1a22, guest PC 0x0c062aac */
if(!s->budget--) { s->failed_pc=0x0c062aacu; return 0; }
write(ram,r[10]+8,r[2],4);
goto P_0c062aae;
P_0c062aae: /* original 1ea5, guest PC 0x0c062aae */
if(!s->budget--) { s->failed_pc=0x0c062aaeu; return 0; }
write(ram,r[14]+20,r[10],4);
goto P_0c062ab0;
P_0c062ab0: /* original 85f2, guest PC 0x0c062ab0 */
if(!s->budget--) { s->failed_pc=0x0c062ab0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c062ab2;
P_0c062ab2: /* original 2008, guest PC 0x0c062ab2 */
if(!s->budget--) { s->failed_pc=0x0c062ab2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c062ab4;
P_0c062ab4: /* original 8b06, guest PC 0x0c062ab4 */
if(!s->budget--) { s->failed_pc=0x0c062ab4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062ac4; }
goto P_0c062ab6;
P_0c062ab6: /* original 9303, guest PC 0x0c062ab6 */
if(!s->budget--) { s->failed_pc=0x0c062ab6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062ac0u,2);
goto P_0c062ab8;
P_0c062ab8: /* original 62e1, guest PC 0x0c062ab8 */
if(!s->budget--) { s->failed_pc=0x0c062ab8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c062aba;
P_0c062aba: /* original 223b, guest PC 0x0c062aba */
if(!s->budget--) { s->failed_pc=0x0c062abau; return 0; }
r[2]|=r[3];
goto P_0c062abc;
P_0c062abc: /* original a006, guest PC 0x0c062abc */
if(!s->budget--) { s->failed_pc=0x0c062abcu; return 0; }
write(ram,r[14],r[2],2);
goto P_0c062acc;
P_0c062abe: /* original 2e21, guest PC 0x0c062abe */
if(!s->budget--) { s->failed_pc=0x0c062abeu; return 0; }
write(ram,r[14],r[2],2);
if(!vf3_matrix_family(0x0c062ac0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062ac0u; return 0; } return 1;
P_0c062ac4: /* original 9376, guest PC 0x0c062ac4 */
if(!s->budget--) { s->failed_pc=0x0c062ac4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062bb4u,2);
goto P_0c062ac6;
P_0c062ac6: /* original 61e1, guest PC 0x0c062ac6 */
if(!s->budget--) { s->failed_pc=0x0c062ac6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c062ac8;
P_0c062ac8: /* original 213b, guest PC 0x0c062ac8 */
if(!s->budget--) { s->failed_pc=0x0c062ac8u; return 0; }
r[1]|=r[3];
goto P_0c062aca;
P_0c062aca: /* original 2e11, guest PC 0x0c062aca */
if(!s->budget--) { s->failed_pc=0x0c062acau; return 0; }
write(ram,r[14],r[1],2);
goto P_0c062acc;
P_0c062acc: /* original 52fc, guest PC 0x0c062acc */
if(!s->budget--) { s->failed_pc=0x0c062accu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c062ace;
P_0c062ace: /* original 2228, guest PC 0x0c062ace */
if(!s->budget--) { s->failed_pc=0x0c062aceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c062ad0;
P_0c062ad0: /* original 8902, guest PC 0x0c062ad0 */
if(!s->budget--) { s->failed_pc=0x0c062ad0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062ad8; }
goto P_0c062ad2;
P_0c062ad2: /* original 60e1, guest PC 0x0c062ad2 */
if(!s->budget--) { s->failed_pc=0x0c062ad2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c062ad4;
P_0c062ad4: /* original cb02, guest PC 0x0c062ad4 */
if(!s->budget--) { s->failed_pc=0x0c062ad4u; return 0; }
r[0]|=2u;
goto P_0c062ad6;
P_0c062ad6: /* original 2e01, guest PC 0x0c062ad6 */
if(!s->budget--) { s->failed_pc=0x0c062ad6u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c062ad8;
P_0c062ad8: /* original 53fd, guest PC 0x0c062ad8 */
if(!s->budget--) { s->failed_pc=0x0c062ad8u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c062ada;
P_0c062ada: /* original 2338, guest PC 0x0c062ada */
if(!s->budget--) { s->failed_pc=0x0c062adau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062adc;
P_0c062adc: /* original 8902, guest PC 0x0c062adc */
if(!s->budget--) { s->failed_pc=0x0c062adcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062ae4; }
goto P_0c062ade;
P_0c062ade: /* original 60e1, guest PC 0x0c062ade */
if(!s->budget--) { s->failed_pc=0x0c062adeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c062ae0;
P_0c062ae0: /* original cb04, guest PC 0x0c062ae0 */
if(!s->budget--) { s->failed_pc=0x0c062ae0u; return 0; }
r[0]|=4u;
goto P_0c062ae2;
P_0c062ae2: /* original 2e01, guest PC 0x0c062ae2 */
if(!s->budget--) { s->failed_pc=0x0c062ae2u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c062ae4;
P_0c062ae4: /* original 53e4, guest PC 0x0c062ae4 */
if(!s->budget--) { s->failed_pc=0x0c062ae4u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c062ae6;
P_0c062ae6: /* original 398c, guest PC 0x0c062ae6 */
if(!s->budget--) { s->failed_pc=0x0c062ae6u; return 0; }
r[9]+=r[8];
goto P_0c062ae8;
P_0c062ae8: /* original 5294, guest PC 0x0c062ae8 */
if(!s->budget--) { s->failed_pc=0x0c062ae8u; return 0; }
r[2]=read(ram,r[9]+16,4);
goto P_0c062aea;
P_0c062aea: /* original 3238, guest PC 0x0c062aea */
if(!s->budget--) { s->failed_pc=0x0c062aeau; return 0; }
r[2]-=r[3];
goto P_0c062aec;
P_0c062aec: /* original 1924, guest PC 0x0c062aec */
if(!s->budget--) { s->failed_pc=0x0c062aecu; return 0; }
write(ram,r[9]+16,r[2],4);
goto P_0c062aee;
P_0c062aee: /* original e000, guest PC 0x0c062aee */
if(!s->budget--) { s->failed_pc=0x0c062aeeu; return 0; }
r[0]=0x00000000u;
goto P_0c062af0;
P_0c062af0: /* original 7f10, guest PC 0x0c062af0 */
if(!s->budget--) { s->failed_pc=0x0c062af0u; return 0; }
r[15]+=0x00000010u;
goto P_0c062af2;
P_0c062af2: /* original 4f26, guest PC 0x0c062af2 */
if(!s->budget--) { s->failed_pc=0x0c062af2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c062af4;
P_0c062af4: /* original 68f6, guest PC 0x0c062af4 */
if(!s->budget--) { s->failed_pc=0x0c062af4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c062af6;
P_0c062af6: /* original 69f6, guest PC 0x0c062af6 */
if(!s->budget--) { s->failed_pc=0x0c062af6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c062af8;
P_0c062af8: /* original 6af6, guest PC 0x0c062af8 */
if(!s->budget--) { s->failed_pc=0x0c062af8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c062afa;
P_0c062afa: /* original 6bf6, guest PC 0x0c062afa */
if(!s->budget--) { s->failed_pc=0x0c062afau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c062afc;
P_0c062afc: /* original 6cf6, guest PC 0x0c062afc */
if(!s->budget--) { s->failed_pc=0x0c062afcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c062afe;
P_0c062afe: /* original 6df6, guest PC 0x0c062afe */
if(!s->budget--) { s->failed_pc=0x0c062afeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062b00;
P_0c062b00: /* original 000b, guest PC 0x0c062b00 */
if(!s->budget--) { s->failed_pc=0x0c062b00u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c062b02: /* original 6ef6, guest PC 0x0c062b02 */
if(!s->budget--) { s->failed_pc=0x0c062b02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c062b04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062b04u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
