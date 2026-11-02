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
int vf3_away_batch28_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05c280u: goto P_0c05c280;
case 0x0c05c282u: goto P_0c05c282;
case 0x0c05c284u: goto P_0c05c284;
case 0x0c05c286u: goto P_0c05c286;
case 0x0c05c288u: goto P_0c05c288;
case 0x0c05c28au: goto P_0c05c28a;
case 0x0c05c28cu: goto P_0c05c28c;
case 0x0c05c28eu: goto P_0c05c28e;
case 0x0c05c290u: goto P_0c05c290;
case 0x0c05c292u: goto P_0c05c292;
case 0x0c05c294u: goto P_0c05c294;
case 0x0c05c296u: goto P_0c05c296;
case 0x0c05c298u: goto P_0c05c298;
case 0x0c05c29au: goto P_0c05c29a;
case 0x0c05c29cu: goto P_0c05c29c;
case 0x0c05c29eu: goto P_0c05c29e;
case 0x0c05c2a0u: goto P_0c05c2a0;
case 0x0c05c2a2u: goto P_0c05c2a2;
case 0x0c05c2a4u: goto P_0c05c2a4;
case 0x0c05c2a6u: goto P_0c05c2a6;
case 0x0c05c2a8u: goto P_0c05c2a8;
case 0x0c05c2aau: goto P_0c05c2aa;
case 0x0c05c2acu: goto P_0c05c2ac;
case 0x0c05c2aeu: goto P_0c05c2ae;
case 0x0c05c2b0u: goto P_0c05c2b0;
case 0x0c05c2b2u: goto P_0c05c2b2;
case 0x0c05c2b4u: goto P_0c05c2b4;
case 0x0c05c2b6u: goto P_0c05c2b6;
case 0x0c05c2b8u: goto P_0c05c2b8;
case 0x0c05c2bau: goto P_0c05c2ba;
case 0x0c05c2bcu: goto P_0c05c2bc;
case 0x0c05c2beu: goto P_0c05c2be;
case 0x0c05c2c0u: goto P_0c05c2c0;
case 0x0c05c2c2u: goto P_0c05c2c2;
case 0x0c05c2c4u: goto P_0c05c2c4;
case 0x0c05c2c6u: goto P_0c05c2c6;
case 0x0c05c2c8u: goto P_0c05c2c8;
case 0x0c05c2cau: goto P_0c05c2ca;
case 0x0c05c2ccu: goto P_0c05c2cc;
case 0x0c05c2ceu: goto P_0c05c2ce;
case 0x0c05c2d0u: goto P_0c05c2d0;
case 0x0c05c2d2u: goto P_0c05c2d2;
case 0x0c05c2d4u: goto P_0c05c2d4;
case 0x0c05c2d6u: goto P_0c05c2d6;
case 0x0c05c2d8u: goto P_0c05c2d8;
case 0x0c05c2dau: goto P_0c05c2da;
case 0x0c05c2dcu: goto P_0c05c2dc;
case 0x0c05c2deu: goto P_0c05c2de;
case 0x0c05c2e0u: goto P_0c05c2e0;
case 0x0c05c2e2u: goto P_0c05c2e2;
case 0x0c05c2e4u: goto P_0c05c2e4;
case 0x0c05c7c6u: goto P_0c05c7c6;
case 0x0c05c7c8u: goto P_0c05c7c8;
case 0x0c05c7cau: goto P_0c05c7ca;
case 0x0c05c7ccu: goto P_0c05c7cc;
case 0x0c05c7ceu: goto P_0c05c7ce;
case 0x0c05c7d0u: goto P_0c05c7d0;
case 0x0c05c7d2u: goto P_0c05c7d2;
case 0x0c05c7d4u: goto P_0c05c7d4;
case 0x0c05c7d6u: goto P_0c05c7d6;
case 0x0c05c7d8u: goto P_0c05c7d8;
case 0x0c05c7dau: goto P_0c05c7da;
case 0x0c05c7dcu: goto P_0c05c7dc;
case 0x0c05c7deu: goto P_0c05c7de;
case 0x0c05c7e0u: goto P_0c05c7e0;
case 0x0c05c7e2u: goto P_0c05c7e2;
case 0x0c05c7e4u: goto P_0c05c7e4;
case 0x0c05c81cu: goto P_0c05c81c;
case 0x0c05c81eu: goto P_0c05c81e;
case 0x0c05c820u: goto P_0c05c820;
case 0x0c05c822u: goto P_0c05c822;
case 0x0c05c824u: goto P_0c05c824;
case 0x0c05c826u: goto P_0c05c826;
case 0x0c05c828u: goto P_0c05c828;
case 0x0c05c82au: goto P_0c05c82a;
case 0x0c05c82cu: goto P_0c05c82c;
case 0x0c05c82eu: goto P_0c05c82e;
case 0x0c05c830u: goto P_0c05c830;
case 0x0c05c832u: goto P_0c05c832;
case 0x0c05c834u: goto P_0c05c834;
case 0x0c05c836u: goto P_0c05c836;
case 0x0c05c838u: goto P_0c05c838;
case 0x0c05c83au: goto P_0c05c83a;
case 0x0c05c83cu: goto P_0c05c83c;
case 0x0c05c83eu: goto P_0c05c83e;
case 0x0c05c840u: goto P_0c05c840;
case 0x0c05c842u: goto P_0c05c842;
case 0x0c05c844u: goto P_0c05c844;
case 0x0c05c846u: goto P_0c05c846;
case 0x0c05c848u: goto P_0c05c848;
case 0x0c05c84au: goto P_0c05c84a;
case 0x0c05c84cu: goto P_0c05c84c;
case 0x0c05c84eu: goto P_0c05c84e;
case 0x0c05c850u: goto P_0c05c850;
case 0x0c05c852u: goto P_0c05c852;
case 0x0c05c854u: goto P_0c05c854;
case 0x0c05c856u: goto P_0c05c856;
case 0x0c05c858u: goto P_0c05c858;
case 0x0c05c85au: goto P_0c05c85a;
case 0x0c05c85cu: goto P_0c05c85c;
case 0x0c05c85eu: goto P_0c05c85e;
case 0x0c05c860u: goto P_0c05c860;
case 0x0c05c862u: goto P_0c05c862;
case 0x0c05c864u: goto P_0c05c864;
case 0x0c05c866u: goto P_0c05c866;
case 0x0c05c868u: goto P_0c05c868;
case 0x0c05c86au: goto P_0c05c86a;
case 0x0c05c86cu: goto P_0c05c86c;
case 0x0c05c86eu: goto P_0c05c86e;
case 0x0c05c870u: goto P_0c05c870;
case 0x0c05c872u: goto P_0c05c872;
case 0x0c05c874u: goto P_0c05c874;
case 0x0c05c876u: goto P_0c05c876;
case 0x0c05c878u: goto P_0c05c878;
case 0x0c05c87au: goto P_0c05c87a;
case 0x0c05c87cu: goto P_0c05c87c;
case 0x0c05c87eu: goto P_0c05c87e;
case 0x0c05c880u: goto P_0c05c880;
case 0x0c05c882u: goto P_0c05c882;
case 0x0c05c884u: goto P_0c05c884;
case 0x0c05c886u: goto P_0c05c886;
case 0x0c05c888u: goto P_0c05c888;
case 0x0c05c88au: goto P_0c05c88a;
case 0x0c05c88cu: goto P_0c05c88c;
case 0x0c05c88eu: goto P_0c05c88e;
case 0x0c05c890u: goto P_0c05c890;
case 0x0c05c950u: goto P_0c05c950;
case 0x0c05c952u: goto P_0c05c952;
case 0x0c05c954u: goto P_0c05c954;
case 0x0c05c956u: goto P_0c05c956;
case 0x0c05c958u: goto P_0c05c958;
case 0x0c05c95au: goto P_0c05c95a;
case 0x0c05c95cu: goto P_0c05c95c;
case 0x0c05c95eu: goto P_0c05c95e;
case 0x0c05c960u: goto P_0c05c960;
case 0x0c05c962u: goto P_0c05c962;
case 0x0c05c964u: goto P_0c05c964;
case 0x0c05c966u: goto P_0c05c966;
case 0x0c05c968u: goto P_0c05c968;
case 0x0c05c96au: goto P_0c05c96a;
case 0x0c05c96cu: goto P_0c05c96c;
case 0x0c05c96eu: goto P_0c05c96e;
case 0x0c05c970u: goto P_0c05c970;
case 0x0c05c972u: goto P_0c05c972;
case 0x0c05c974u: goto P_0c05c974;
case 0x0c05c976u: goto P_0c05c976;
case 0x0c05c978u: goto P_0c05c978;
case 0x0c05c97au: goto P_0c05c97a;
case 0x0c05c97cu: goto P_0c05c97c;
case 0x0c05c97eu: goto P_0c05c97e;
case 0x0c05c980u: goto P_0c05c980;
case 0x0c05c982u: goto P_0c05c982;
case 0x0c05c984u: goto P_0c05c984;
case 0x0c05c986u: goto P_0c05c986;
case 0x0c05c988u: goto P_0c05c988;
case 0x0c05c98au: goto P_0c05c98a;
case 0x0c05c98cu: goto P_0c05c98c;
case 0x0c05c98eu: goto P_0c05c98e;
case 0x0c05c990u: goto P_0c05c990;
case 0x0c05c992u: goto P_0c05c992;
case 0x0c05c994u: goto P_0c05c994;
case 0x0c05c996u: goto P_0c05c996;
case 0x0c05c998u: goto P_0c05c998;
case 0x0c05c99au: goto P_0c05c99a;
case 0x0c05c99cu: goto P_0c05c99c;
case 0x0c05c99eu: goto P_0c05c99e;
case 0x0c05c9a0u: goto P_0c05c9a0;
case 0x0c05c9a2u: goto P_0c05c9a2;
case 0x0c05c9a4u: goto P_0c05c9a4;
case 0x0c05c9a6u: goto P_0c05c9a6;
case 0x0c05c9a8u: goto P_0c05c9a8;
case 0x0c05c9aau: goto P_0c05c9aa;
case 0x0c05c9acu: goto P_0c05c9ac;
case 0x0c05c9aeu: goto P_0c05c9ae;
case 0x0c05c9b0u: goto P_0c05c9b0;
case 0x0c05c9b2u: goto P_0c05c9b2;
case 0x0c05c9b4u: goto P_0c05c9b4;
case 0x0c05c9b6u: goto P_0c05c9b6;
case 0x0c05c9b8u: goto P_0c05c9b8;
case 0x0c05c9bau: goto P_0c05c9ba;
case 0x0c05c9bcu: goto P_0c05c9bc;
case 0x0c05c9beu: goto P_0c05c9be;
case 0x0c05c9c0u: goto P_0c05c9c0;
case 0x0c05c9c2u: goto P_0c05c9c2;
case 0x0c05c9c4u: goto P_0c05c9c4;
case 0x0c05c9c6u: goto P_0c05c9c6;
case 0x0c05c9c8u: goto P_0c05c9c8;
case 0x0c05c9cau: goto P_0c05c9ca;
case 0x0c05c9ccu: goto P_0c05c9cc;
case 0x0c05c9ceu: goto P_0c05c9ce;
case 0x0c05c9d0u: goto P_0c05c9d0;
case 0x0c05c9d2u: goto P_0c05c9d2;
case 0x0c05c9d4u: goto P_0c05c9d4;
case 0x0c05c9d6u: goto P_0c05c9d6;
case 0x0c05c9d8u: goto P_0c05c9d8;
case 0x0c05c9dau: goto P_0c05c9da;
case 0x0c05c9dcu: goto P_0c05c9dc;
case 0x0c05c9deu: goto P_0c05c9de;
case 0x0c05c9e0u: goto P_0c05c9e0;
case 0x0c05c9e2u: goto P_0c05c9e2;
case 0x0c05c9e4u: goto P_0c05c9e4;
case 0x0c05c9e6u: goto P_0c05c9e6;
case 0x0c05c9e8u: goto P_0c05c9e8;
case 0x0c05c9eau: goto P_0c05c9ea;
case 0x0c05c9ecu: goto P_0c05c9ec;
case 0x0c05c9eeu: goto P_0c05c9ee;
case 0x0c05c9f0u: goto P_0c05c9f0;
case 0x0c05c9f2u: goto P_0c05c9f2;
case 0x0c05c9f4u: goto P_0c05c9f4;
case 0x0c05c9f6u: goto P_0c05c9f6;
case 0x0c05c9f8u: goto P_0c05c9f8;
case 0x0c05c9fau: goto P_0c05c9fa;
case 0x0c05c9fcu: goto P_0c05c9fc;
case 0x0c05c9feu: goto P_0c05c9fe;
case 0x0c05ca00u: goto P_0c05ca00;
case 0x0c05ca02u: goto P_0c05ca02;
case 0x0c05ca04u: goto P_0c05ca04;
case 0x0c05ca06u: goto P_0c05ca06;
case 0x0c05ca08u: goto P_0c05ca08;
case 0x0c05ca0au: goto P_0c05ca0a;
case 0x0c05ca0cu: goto P_0c05ca0c;
case 0x0c05ca0eu: goto P_0c05ca0e;
case 0x0c05ca10u: goto P_0c05ca10;
case 0x0c05ca12u: goto P_0c05ca12;
case 0x0c05ca14u: goto P_0c05ca14;
case 0x0c05ca16u: goto P_0c05ca16;
case 0x0c05ca18u: goto P_0c05ca18;
case 0x0c05ca1au: goto P_0c05ca1a;
case 0x0c05ca1cu: goto P_0c05ca1c;
case 0x0c05ca1eu: goto P_0c05ca1e;
case 0x0c05ca20u: goto P_0c05ca20;
case 0x0c05ca22u: goto P_0c05ca22;
case 0x0c05ca24u: goto P_0c05ca24;
case 0x0c05ca26u: goto P_0c05ca26;
case 0x0c05ca28u: goto P_0c05ca28;
case 0x0c05ca2au: goto P_0c05ca2a;
case 0x0c05ca2cu: goto P_0c05ca2c;
case 0x0c05ca2eu: goto P_0c05ca2e;
case 0x0c05ca30u: goto P_0c05ca30;
case 0x0c05ca32u: goto P_0c05ca32;
case 0x0c05ca34u: goto P_0c05ca34;
case 0x0c05ca36u: goto P_0c05ca36;
case 0x0c05ca38u: goto P_0c05ca38;
case 0x0c05ca3au: goto P_0c05ca3a;
case 0x0c05ca3cu: goto P_0c05ca3c;
case 0x0c05ca3eu: goto P_0c05ca3e;
case 0x0c05ca40u: goto P_0c05ca40;
case 0x0c05ca42u: goto P_0c05ca42;
case 0x0c05ca44u: goto P_0c05ca44;
case 0x0c05ca46u: goto P_0c05ca46;
case 0x0c05ca48u: goto P_0c05ca48;
case 0x0c05ca4au: goto P_0c05ca4a;
case 0x0c05ca4cu: goto P_0c05ca4c;
case 0x0c05ca4eu: goto P_0c05ca4e;
case 0x0c05ca50u: goto P_0c05ca50;
case 0x0c05ca52u: goto P_0c05ca52;
case 0x0c05ca54u: goto P_0c05ca54;
case 0x0c05ca56u: goto P_0c05ca56;
case 0x0c05ca58u: goto P_0c05ca58;
case 0x0c05ca5au: goto P_0c05ca5a;
case 0x0c05ca5cu: goto P_0c05ca5c;
case 0x0c05ca5eu: goto P_0c05ca5e;
case 0x0c05ca60u: goto P_0c05ca60;
case 0x0c05ca9cu: goto P_0c05ca9c;
case 0x0c05ca9eu: goto P_0c05ca9e;
case 0x0c05caa0u: goto P_0c05caa0;
case 0x0c05caa2u: goto P_0c05caa2;
case 0x0c05caa4u: goto P_0c05caa4;
case 0x0c05caa6u: goto P_0c05caa6;
case 0x0c05caa8u: goto P_0c05caa8;
case 0x0c05caaau: goto P_0c05caaa;
case 0x0c05caacu: goto P_0c05caac;
case 0x0c05caaeu: goto P_0c05caae;
case 0x0c05cab0u: goto P_0c05cab0;
case 0x0c05cab2u: goto P_0c05cab2;
case 0x0c05cab4u: goto P_0c05cab4;
case 0x0c05cab6u: goto P_0c05cab6;
case 0x0c05cab8u: goto P_0c05cab8;
case 0x0c05cabau: goto P_0c05caba;
case 0x0c05cabcu: goto P_0c05cabc;
case 0x0c05cabeu: goto P_0c05cabe;
case 0x0c05cac0u: goto P_0c05cac0;
case 0x0c05cac2u: goto P_0c05cac2;
case 0x0c05cac4u: goto P_0c05cac4;
case 0x0c05cac6u: goto P_0c05cac6;
case 0x0c05cac8u: goto P_0c05cac8;
case 0x0c05cacau: goto P_0c05caca;
case 0x0c05caccu: goto P_0c05cacc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05c280: /* original 2fe6, guest PC 0x0c05c280 */
if(!s->budget--) { s->failed_pc=0x0c05c280u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c282;
P_0c05c282: /* original 6e43, guest PC 0x0c05c282 */
if(!s->budget--) { s->failed_pc=0x0c05c282u; return 0; }
r[14]=r[4];
goto P_0c05c284;
P_0c05c284: /* original d376, guest PC 0x0c05c284 */
if(!s->budget--) { s->failed_pc=0x0c05c284u; return 0; }
r[3]=read(ram,0x0c05c460u,4);
goto P_0c05c286;
P_0c05c286: /* original 2fd6, guest PC 0x0c05c286 */
if(!s->budget--) { s->failed_pc=0x0c05c286u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c288;
P_0c05c288: /* original 2fc6, guest PC 0x0c05c288 */
if(!s->budget--) { s->failed_pc=0x0c05c288u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c28a;
P_0c05c28a: /* original 4f22, guest PC 0x0c05c28a */
if(!s->budget--) { s->failed_pc=0x0c05c28au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05c28c;
P_0c05c28c: /* original 7ffc, guest PC 0x0c05c28c */
if(!s->budget--) { s->failed_pc=0x0c05c28cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05c28e;
P_0c05c28e: /* original 54e2, guest PC 0x0c05c28e */
if(!s->budget--) { s->failed_pc=0x0c05c28eu; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c05c290;
P_0c05c290: /* original 6542, guest PC 0x0c05c290 */
if(!s->budget--) { s->failed_pc=0x0c05c290u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c05c292;
P_0c05c292: /* original 5d41, guest PC 0x0c05c292 */
if(!s->budget--) { s->failed_pc=0x0c05c292u; return 0; }
r[13]=read(ram,r[4]+4,4);
goto P_0c05c294;
P_0c05c294: /* original 6453, guest PC 0x0c05c294 */
if(!s->budget--) { s->failed_pc=0x0c05c294u; return 0; }
r[4]=r[5];
goto P_0c05c296;
P_0c05c296: /* original 4408, guest PC 0x0c05c296 */
if(!s->budget--) { s->failed_pc=0x0c05c296u; return 0; }
r[4]<<=2;
goto P_0c05c298;
P_0c05c298: /* original 2f42, guest PC 0x0c05c298 */
if(!s->budget--) { s->failed_pc=0x0c05c298u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05c29a;
P_0c05c29a: /* original 60e2, guest PC 0x0c05c29a */
if(!s->budget--) { s->failed_pc=0x0c05c29au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c29c;
P_0c05c29c: /* original 55e1, guest PC 0x0c05c29c */
if(!s->budget--) { s->failed_pc=0x0c05c29cu; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c05c29e;
P_0c05c29e: /* original 044e, guest PC 0x0c05c29e */
if(!s->budget--) { s->failed_pc=0x0c05c29eu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c05c2a0;
P_0c05c2a0: /* original 6643, guest PC 0x0c05c2a0 */
if(!s->budget--) { s->failed_pc=0x0c05c2a0u; return 0; }
r[6]=r[4];
goto P_0c05c2a2;
P_0c05c2a2: /* original 4629, guest PC 0x0c05c2a2 */
if(!s->budget--) { s->failed_pc=0x0c05c2a2u; return 0; }
r[6]>>=16;
goto P_0c05c2a4;
P_0c05c2a4: /* original 4619, guest PC 0x0c05c2a4 */
if(!s->budget--) { s->failed_pc=0x0c05c2a4u; return 0; }
r[6]>>=8;
goto P_0c05c2a6;
P_0c05c2a6: /* original 2362, guest PC 0x0c05c2a6 */
if(!s->budget--) { s->failed_pc=0x0c05c2a6u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c05c2a8;
P_0c05c2a8: /* original d26e, guest PC 0x0c05c2a8 */
if(!s->budget--) { s->failed_pc=0x0c05c2a8u; return 0; }
r[2]=read(ram,0x0c05c464u,4);
goto P_0c05c2aa;
P_0c05c2aa: /* original 2262, guest PC 0x0c05c2aa */
if(!s->budget--) { s->failed_pc=0x0c05c2aau; return 0; }
write(ram,r[2],r[6],4);
goto P_0c05c2ac;
P_0c05c2ac: /* original dc6e, guest PC 0x0c05c2ac */
if(!s->budget--) { s->failed_pc=0x0c05c2acu; return 0; }
r[12]=read(ram,0x0c05c468u,4);
goto P_0c05c2ae;
P_0c05c2ae: /* original 66d3, guest PC 0x0c05c2ae */
if(!s->budget--) { s->failed_pc=0x0c05c2aeu; return 0; }
r[6]=r[13];
goto P_0c05c2b0;
P_0c05c2b0: /* original d36f, guest PC 0x0c05c2b0 */
if(!s->budget--) { s->failed_pc=0x0c05c2b0u; return 0; }
r[3]=read(ram,0x0c05c470u,4);
goto P_0c05c2b2;
P_0c05c2b2: /* original 2c49, guest PC 0x0c05c2b2 */
if(!s->budget--) { s->failed_pc=0x0c05c2b2u; return 0; }
r[12]&=r[4];
goto P_0c05c2b4;
P_0c05c2b4: /* original d16d, guest PC 0x0c05c2b4 */
if(!s->budget--) { s->failed_pc=0x0c05c2b4u; return 0; }
r[1]=read(ram,0x0c05c46cu,4);
goto P_0c05c2b6;
P_0c05c2b6: /* original 2c1b, guest PC 0x0c05c2b6 */
if(!s->budget--) { s->failed_pc=0x0c05c2b6u; return 0; }
r[12]|=r[1];
goto P_0c05c2b8;
P_0c05c2b8: /* original 430b, guest PC 0x0c05c2b8 */
if(!s->budget--) { s->failed_pc=0x0c05c2b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05c2bcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c2bcu) { target=s->pc; goto dispatch; }
goto P_0c05c2bc;
P_0c05c2ba: /* original 64c3, guest PC 0x0c05c2ba */
if(!s->budget--) { s->failed_pc=0x0c05c2bau; return 0; }
r[4]=r[12];
goto P_0c05c2bc;
P_0c05c2bc: /* original 0c83, guest PC 0x0c05c2bc */
if(!s->budget--) { s->failed_pc=0x0c05c2bcu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05c2be;
P_0c05c2be: /* original 60d3, guest PC 0x0c05c2be */
if(!s->budget--) { s->failed_pc=0x0c05c2beu; return 0; }
r[0]=r[13];
goto P_0c05c2c0;
P_0c05c2c0: /* original 0009, guest PC 0x0c05c2c0 */
if(!s->budget--) { s->failed_pc=0x0c05c2c0u; return 0; }
goto P_0c05c2c2;
P_0c05c2c2: /* original 8840, guest PC 0x0c05c2c2 */
if(!s->budget--) { s->failed_pc=0x0c05c2c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c05c2c4;
P_0c05c2c4: /* original 8b01, guest PC 0x0c05c2c4 */
if(!s->budget--) { s->failed_pc=0x0c05c2c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05c2ca; }
goto P_0c05c2c6;
P_0c05c2c6: /* original 7c20, guest PC 0x0c05c2c6 */
if(!s->budget--) { s->failed_pc=0x0c05c2c6u; return 0; }
r[12]+=0x00000020u;
goto P_0c05c2c8;
P_0c05c2c8: /* original 0c83, guest PC 0x0c05c2c8 */
if(!s->budget--) { s->failed_pc=0x0c05c2c8u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05c2ca;
P_0c05c2ca: /* original 4d09, guest PC 0x0c05c2ca */
if(!s->budget--) { s->failed_pc=0x0c05c2cau; return 0; }
r[13]>>=2;
goto P_0c05c2cc;
P_0c05c2cc: /* original 63f2, guest PC 0x0c05c2cc */
if(!s->budget--) { s->failed_pc=0x0c05c2ccu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05c2ce;
P_0c05c2ce: /* original 4d08, guest PC 0x0c05c2ce */
if(!s->budget--) { s->failed_pc=0x0c05c2ceu; return 0; }
r[13]<<=2;
goto P_0c05c2d0;
P_0c05c2d0: /* original 60e2, guest PC 0x0c05c2d0 */
if(!s->budget--) { s->failed_pc=0x0c05c2d0u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05c2d2;
P_0c05c2d2: /* original 023e, guest PC 0x0c05c2d2 */
if(!s->budget--) { s->failed_pc=0x0c05c2d2u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c05c2d4;
P_0c05c2d4: /* original 32dc, guest PC 0x0c05c2d4 */
if(!s->budget--) { s->failed_pc=0x0c05c2d4u; return 0; }
r[2]+=r[13];
goto P_0c05c2d6;
P_0c05c2d6: /* original 0326, guest PC 0x0c05c2d6 */
if(!s->budget--) { s->failed_pc=0x0c05c2d6u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c05c2d8;
P_0c05c2d8: /* original e000, guest PC 0x0c05c2d8 */
if(!s->budget--) { s->failed_pc=0x0c05c2d8u; return 0; }
r[0]=0x00000000u;
goto P_0c05c2da;
P_0c05c2da: /* original 7f04, guest PC 0x0c05c2da */
if(!s->budget--) { s->failed_pc=0x0c05c2dau; return 0; }
r[15]+=0x00000004u;
goto P_0c05c2dc;
P_0c05c2dc: /* original 4f26, guest PC 0x0c05c2dc */
if(!s->budget--) { s->failed_pc=0x0c05c2dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05c2de;
P_0c05c2de: /* original 6cf6, guest PC 0x0c05c2de */
if(!s->budget--) { s->failed_pc=0x0c05c2deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05c2e0;
P_0c05c2e0: /* original 6df6, guest PC 0x0c05c2e0 */
if(!s->budget--) { s->failed_pc=0x0c05c2e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05c2e2;
P_0c05c2e2: /* original 000b, guest PC 0x0c05c2e2 */
if(!s->budget--) { s->failed_pc=0x0c05c2e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05c2e4: /* original 6ef6, guest PC 0x0c05c2e4 */
if(!s->budget--) { s->failed_pc=0x0c05c2e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05c2e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05c2e6u; return 0; } return 1;
P_0c05c7c6: /* original 2fe6, guest PC 0x0c05c7c6 */
if(!s->budget--) { s->failed_pc=0x0c05c7c6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c7c8;
P_0c05c7c8: /* original d609, guest PC 0x0c05c7c8 */
if(!s->budget--) { s->failed_pc=0x0c05c7c8u; return 0; }
r[6]=read(ram,0x0c05c7f0u,4);
goto P_0c05c7ca;
P_0c05c7ca: /* original d512, guest PC 0x0c05c7ca */
if(!s->budget--) { s->failed_pc=0x0c05c7cau; return 0; }
r[5]=read(ram,0x0c05c814u,4);
goto P_0c05c7cc;
P_0c05c7cc: /* original d312, guest PC 0x0c05c7cc */
if(!s->budget--) { s->failed_pc=0x0c05c7ccu; return 0; }
r[3]=read(ram,0x0c05c818u,4);
goto P_0c05c7ce;
P_0c05c7ce: /* original 6032, guest PC 0x0c05c7ce */
if(!s->budget--) { s->failed_pc=0x0c05c7ceu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05c7d0;
P_0c05c7d0: /* original 8801, guest PC 0x0c05c7d0 */
if(!s->budget--) { s->failed_pc=0x0c05c7d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05c7d2;
P_0c05c7d2: /* original 8923, guest PC 0x0c05c7d2 */
if(!s->budget--) { s->failed_pc=0x0c05c7d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05c81c; }
goto P_0c05c7d4;
P_0c05c7d4: /* original 6143, guest PC 0x0c05c7d4 */
if(!s->budget--) { s->failed_pc=0x0c05c7d4u; return 0; }
r[1]=r[4];
goto P_0c05c7d6;
P_0c05c7d6: /* original 6243, guest PC 0x0c05c7d6 */
if(!s->budget--) { s->failed_pc=0x0c05c7d6u; return 0; }
r[2]=r[4];
goto P_0c05c7d8;
P_0c05c7d8: /* original 4108, guest PC 0x0c05c7d8 */
if(!s->budget--) { s->failed_pc=0x0c05c7d8u; return 0; }
r[1]<<=2;
goto P_0c05c7da;
P_0c05c7da: /* original 312c, guest PC 0x0c05c7da */
if(!s->budget--) { s->failed_pc=0x0c05c7dau; return 0; }
r[1]+=r[2];
goto P_0c05c7dc;
P_0c05c7dc: /* original 4108, guest PC 0x0c05c7dc */
if(!s->budget--) { s->failed_pc=0x0c05c7dcu; return 0; }
r[1]<<=2;
goto P_0c05c7de;
P_0c05c7de: /* original 611e, guest PC 0x0c05c7de */
if(!s->budget--) { s->failed_pc=0x0c05c7deu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c05c7e0;
P_0c05c7e0: /* original 315c, guest PC 0x0c05c7e0 */
if(!s->budget--) { s->failed_pc=0x0c05c7e0u; return 0; }
r[1]+=r[5];
goto P_0c05c7e2;
P_0c05c7e2: /* original a01c, guest PC 0x0c05c7e2 */
if(!s->budget--) { s->failed_pc=0x0c05c7e2u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c05c81e;
P_0c05c7e4: /* original 2612, guest PC 0x0c05c7e4 */
if(!s->budget--) { s->failed_pc=0x0c05c7e4u; return 0; }
write(ram,r[6],r[1],4);
if(!vf3_matrix_family(0x0c05c7e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05c7e6u; return 0; } return 1;
P_0c05c81c: /* original 2652, guest PC 0x0c05c81c */
if(!s->budget--) { s->failed_pc=0x0c05c81cu; return 0; }
write(ram,r[6],r[5],4);
goto P_0c05c81e;
P_0c05c81e: /* original ee00, guest PC 0x0c05c81e */
if(!s->budget--) { s->failed_pc=0x0c05c81eu; return 0; }
r[14]=0x00000000u;
goto P_0c05c820;
P_0c05c820: /* original d542, guest PC 0x0c05c820 */
if(!s->budget--) { s->failed_pc=0x0c05c820u; return 0; }
r[5]=read(ram,0x0c05c92cu,4);
goto P_0c05c822;
P_0c05c822: /* original e705, guest PC 0x0c05c822 */
if(!s->budget--) { s->failed_pc=0x0c05c822u; return 0; }
r[7]=0x00000005u;
goto P_0c05c824;
P_0c05c824: /* original 6262, guest PC 0x0c05c824 */
if(!s->budget--) { s->failed_pc=0x0c05c824u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c05c826;
P_0c05c826: /* original 6352, guest PC 0x0c05c826 */
if(!s->budget--) { s->failed_pc=0x0c05c826u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05c828;
P_0c05c828: /* original 6122, guest PC 0x0c05c828 */
if(!s->budget--) { s->failed_pc=0x0c05c828u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05c82a;
P_0c05c82a: /* original 2312, guest PC 0x0c05c82a */
if(!s->budget--) { s->failed_pc=0x0c05c82au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05c82c;
P_0c05c82c: /* original 6352, guest PC 0x0c05c82c */
if(!s->budget--) { s->failed_pc=0x0c05c82cu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05c82e;
P_0c05c82e: /* original 6262, guest PC 0x0c05c82e */
if(!s->budget--) { s->failed_pc=0x0c05c82eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c05c830;
P_0c05c830: /* original 5121, guest PC 0x0c05c830 */
if(!s->budget--) { s->failed_pc=0x0c05c830u; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c05c832;
P_0c05c832: /* original 1311, guest PC 0x0c05c832 */
if(!s->budget--) { s->failed_pc=0x0c05c832u; return 0; }
write(ram,r[3]+4,r[1],4);
goto P_0c05c834;
P_0c05c834: /* original 6352, guest PC 0x0c05c834 */
if(!s->budget--) { s->failed_pc=0x0c05c834u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05c836;
P_0c05c836: /* original 6262, guest PC 0x0c05c836 */
if(!s->budget--) { s->failed_pc=0x0c05c836u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c05c838;
P_0c05c838: /* original 5122, guest PC 0x0c05c838 */
if(!s->budget--) { s->failed_pc=0x0c05c838u; return 0; }
r[1]=read(ram,r[2]+8,4);
goto P_0c05c83a;
P_0c05c83a: /* original 1312, guest PC 0x0c05c83a */
if(!s->budget--) { s->failed_pc=0x0c05c83au; return 0; }
write(ram,r[3]+8,r[1],4);
goto P_0c05c83c;
P_0c05c83c: /* original 6352, guest PC 0x0c05c83c */
if(!s->budget--) { s->failed_pc=0x0c05c83cu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05c83e;
P_0c05c83e: /* original 6262, guest PC 0x0c05c83e */
if(!s->budget--) { s->failed_pc=0x0c05c83eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c05c840;
P_0c05c840: /* original 5123, guest PC 0x0c05c840 */
if(!s->budget--) { s->failed_pc=0x0c05c840u; return 0; }
r[1]=read(ram,r[2]+12,4);
goto P_0c05c842;
P_0c05c842: /* original 1313, guest PC 0x0c05c842 */
if(!s->budget--) { s->failed_pc=0x0c05c842u; return 0; }
write(ram,r[3]+12,r[1],4);
goto P_0c05c844;
P_0c05c844: /* original 6352, guest PC 0x0c05c844 */
if(!s->budget--) { s->failed_pc=0x0c05c844u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05c846;
P_0c05c846: /* original 6262, guest PC 0x0c05c846 */
if(!s->budget--) { s->failed_pc=0x0c05c846u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c05c848;
P_0c05c848: /* original 5124, guest PC 0x0c05c848 */
if(!s->budget--) { s->failed_pc=0x0c05c848u; return 0; }
r[1]=read(ram,r[2]+16,4);
goto P_0c05c84a;
P_0c05c84a: /* original 66e3, guest PC 0x0c05c84a */
if(!s->budget--) { s->failed_pc=0x0c05c84au; return 0; }
r[6]=r[14];
goto P_0c05c84c;
P_0c05c84c: /* original 1314, guest PC 0x0c05c84c */
if(!s->budget--) { s->failed_pc=0x0c05c84cu; return 0; }
write(ram,r[3]+16,r[1],4);
goto P_0c05c84e;
P_0c05c84e: /* original d138, guest PC 0x0c05c84e */
if(!s->budget--) { s->failed_pc=0x0c05c84eu; return 0; }
r[1]=read(ram,0x0c05c930u,4);
goto P_0c05c850;
P_0c05c850: /* original 6063, guest PC 0x0c05c850 */
if(!s->budget--) { s->failed_pc=0x0c05c850u; return 0; }
r[0]=r[6];
goto P_0c05c852;
P_0c05c852: /* original 0009, guest PC 0x0c05c852 */
if(!s->budget--) { s->failed_pc=0x0c05c852u; return 0; }
goto P_0c05c854;
P_0c05c854: /* original 6352, guest PC 0x0c05c854 */
if(!s->budget--) { s->failed_pc=0x0c05c854u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05c856;
P_0c05c856: /* original 7e01, guest PC 0x0c05c856 */
if(!s->budget--) { s->failed_pc=0x0c05c856u; return 0; }
r[14]+=0x00000001u;
goto P_0c05c858;
P_0c05c858: /* original 033e, guest PC 0x0c05c858 */
if(!s->budget--) { s->failed_pc=0x0c05c858u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05c85a;
P_0c05c85a: /* original 6263, guest PC 0x0c05c85a */
if(!s->budget--) { s->failed_pc=0x0c05c85au; return 0; }
r[2]=r[6];
goto P_0c05c85c;
P_0c05c85c: /* original 321c, guest PC 0x0c05c85c */
if(!s->budget--) { s->failed_pc=0x0c05c85cu; return 0; }
r[2]+=r[1];
goto P_0c05c85e;
P_0c05c85e: /* original 3e72, guest PC 0x0c05c85e */
if(!s->budget--) { s->failed_pc=0x0c05c85eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[7])!=0);
goto P_0c05c860;
P_0c05c860: /* original 2232, guest PC 0x0c05c860 */
if(!s->budget--) { s->failed_pc=0x0c05c860u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05c862;
P_0c05c862: /* original 8ff5, guest PC 0x0c05c862 */
if(!s->budget--) { s->failed_pc=0x0c05c862u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c05c850; }
goto P_0c05c866;
P_0c05c864: /* original 7604, guest PC 0x0c05c864 */
if(!s->budget--) { s->failed_pc=0x0c05c864u; return 0; }
r[6]+=0x00000004u;
goto P_0c05c866;
P_0c05c866: /* original e201, guest PC 0x0c05c866 */
if(!s->budget--) { s->failed_pc=0x0c05c866u; return 0; }
r[2]=0x00000001u;
goto P_0c05c868;
P_0c05c868: /* original d332, guest PC 0x0c05c868 */
if(!s->budget--) { s->failed_pc=0x0c05c868u; return 0; }
r[3]=read(ram,0x0c05c934u,4);
goto P_0c05c86a;
P_0c05c86a: /* original e600, guest PC 0x0c05c86a */
if(!s->budget--) { s->failed_pc=0x0c05c86au; return 0; }
r[6]=0x00000000u;
goto P_0c05c86c;
P_0c05c86c: /* original de32, guest PC 0x0c05c86c */
if(!s->budget--) { s->failed_pc=0x0c05c86cu; return 0; }
r[14]=read(ram,0x0c05c938u,4);
goto P_0c05c86e;
P_0c05c86e: /* original 2429, guest PC 0x0c05c86e */
if(!s->budget--) { s->failed_pc=0x0c05c86eu; return 0; }
r[4]&=r[2];
goto P_0c05c870;
P_0c05c870: /* original 2342, guest PC 0x0c05c870 */
if(!s->budget--) { s->failed_pc=0x0c05c870u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05c872;
P_0c05c872: /* original 6463, guest PC 0x0c05c872 */
if(!s->budget--) { s->failed_pc=0x0c05c872u; return 0; }
r[4]=r[6];
goto P_0c05c874;
P_0c05c874: /* original 6252, guest PC 0x0c05c874 */
if(!s->budget--) { s->failed_pc=0x0c05c874u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c05c876;
P_0c05c876: /* original 324c, guest PC 0x0c05c876 */
if(!s->budget--) { s->failed_pc=0x0c05c876u; return 0; }
r[2]+=r[4];
goto P_0c05c878;
P_0c05c878: /* original 6043, guest PC 0x0c05c878 */
if(!s->budget--) { s->failed_pc=0x0c05c878u; return 0; }
r[0]=r[4];
goto P_0c05c87a;
P_0c05c87a: /* original 0009, guest PC 0x0c05c87a */
if(!s->budget--) { s->failed_pc=0x0c05c87au; return 0; }
goto P_0c05c87c;
P_0c05c87c: /* original 03ee, guest PC 0x0c05c87c */
if(!s->budget--) { s->failed_pc=0x0c05c87cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05c87e;
P_0c05c87e: /* original 7601, guest PC 0x0c05c87e */
if(!s->budget--) { s->failed_pc=0x0c05c87eu; return 0; }
r[6]+=0x00000001u;
goto P_0c05c880;
P_0c05c880: /* original 6122, guest PC 0x0c05c880 */
if(!s->budget--) { s->failed_pc=0x0c05c880u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05c882;
P_0c05c882: /* original 4308, guest PC 0x0c05c882 */
if(!s->budget--) { s->failed_pc=0x0c05c882u; return 0; }
r[3]<<=2;
goto P_0c05c884;
P_0c05c884: /* original 313c, guest PC 0x0c05c884 */
if(!s->budget--) { s->failed_pc=0x0c05c884u; return 0; }
r[1]+=r[3];
goto P_0c05c886;
P_0c05c886: /* original 3672, guest PC 0x0c05c886 */
if(!s->budget--) { s->failed_pc=0x0c05c886u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c05c888;
P_0c05c888: /* original 2212, guest PC 0x0c05c888 */
if(!s->budget--) { s->failed_pc=0x0c05c888u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c05c88a;
P_0c05c88a: /* original 8ff3, guest PC 0x0c05c88a */
if(!s->budget--) { s->failed_pc=0x0c05c88au; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c05c874; }
goto P_0c05c88e;
P_0c05c88c: /* original 7404, guest PC 0x0c05c88c */
if(!s->budget--) { s->failed_pc=0x0c05c88cu; return 0; }
r[4]+=0x00000004u;
goto P_0c05c88e;
P_0c05c88e: /* original 000b, guest PC 0x0c05c88e */
if(!s->budget--) { s->failed_pc=0x0c05c88eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05c890: /* original 6ef6, guest PC 0x0c05c890 */
if(!s->budget--) { s->failed_pc=0x0c05c890u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05c892u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05c892u; return 0; } return 1;
P_0c05c950: /* original 2fe6, guest PC 0x0c05c950 */
if(!s->budget--) { s->failed_pc=0x0c05c950u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c952;
P_0c05c952: /* original e054, guest PC 0x0c05c952 */
if(!s->budget--) { s->failed_pc=0x0c05c952u; return 0; }
r[0]=0x00000054u;
goto P_0c05c954;
P_0c05c954: /* original d344, guest PC 0x0c05c954 */
if(!s->budget--) { s->failed_pc=0x0c05c954u; return 0; }
r[3]=read(ram,0x0c05ca68u,4);
goto P_0c05c956;
P_0c05c956: /* original 2fd6, guest PC 0x0c05c956 */
if(!s->budget--) { s->failed_pc=0x0c05c956u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c958;
P_0c05c958: /* original 2fc6, guest PC 0x0c05c958 */
if(!s->budget--) { s->failed_pc=0x0c05c958u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c95a;
P_0c05c95a: /* original 6d43, guest PC 0x0c05c95a */
if(!s->budget--) { s->failed_pc=0x0c05c95au; return 0; }
r[13]=r[4];
goto P_0c05c95c;
P_0c05c95c: /* original de41, guest PC 0x0c05c95c */
if(!s->budget--) { s->failed_pc=0x0c05c95cu; return 0; }
r[14]=read(ram,0x0c05ca64u,4);
goto P_0c05c95e;
P_0c05c95e: /* original 2fb6, guest PC 0x0c05c95e */
if(!s->budget--) { s->failed_pc=0x0c05c95eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c960;
P_0c05c960: /* original 2fa6, guest PC 0x0c05c960 */
if(!s->budget--) { s->failed_pc=0x0c05c960u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c962;
P_0c05c962: /* original eb02, guest PC 0x0c05c962 */
if(!s->budget--) { s->failed_pc=0x0c05c962u; return 0; }
r[11]=0x00000002u;
goto P_0c05c964;
P_0c05c964: /* original 2f96, guest PC 0x0c05c964 */
if(!s->budget--) { s->failed_pc=0x0c05c964u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c966;
P_0c05c966: /* original 2f86, guest PC 0x0c05c966 */
if(!s->budget--) { s->failed_pc=0x0c05c966u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c968;
P_0c05c968: /* original 4f22, guest PC 0x0c05c968 */
if(!s->budget--) { s->failed_pc=0x0c05c968u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05c96a;
P_0c05c96a: /* original 7ff0, guest PC 0x0c05c96a */
if(!s->budget--) { s->failed_pc=0x0c05c96au; return 0; }
r[15]+=0xfffffff0u;
goto P_0c05c96c;
P_0c05c96c: /* original 0eb6, guest PC 0x0c05c96c */
if(!s->budget--) { s->failed_pc=0x0c05c96cu; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c05c96e;
P_0c05c96e: /* original e058, guest PC 0x0c05c96e */
if(!s->budget--) { s->failed_pc=0x0c05c96eu; return 0; }
r[0]=0x00000058u;
goto P_0c05c970;
P_0c05c970: /* original 2ed2, guest PC 0x0c05c970 */
if(!s->budget--) { s->failed_pc=0x0c05c970u; return 0; }
write(ram,r[14],r[13],4);
goto P_0c05c972;
P_0c05c972: /* original 430b, guest PC 0x0c05c972 */
if(!s->budget--) { s->failed_pc=0x0c05c972u; return 0; }
target=r[3];
r[16]=code_base|0x0c05c976u;
write(ram,r[14]+r[0],r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c976u) { target=s->pc; goto dispatch; }
goto P_0c05c976;
P_0c05c974: /* original 0e56, guest PC 0x0c05c974 */
if(!s->budget--) { s->failed_pc=0x0c05c974u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c05c976;
P_0c05c976: /* original d23d, guest PC 0x0c05c976 */
if(!s->budget--) { s->failed_pc=0x0c05c976u; return 0; }
r[2]=read(ram,0x0c05ca6cu,4);
goto P_0c05c978;
P_0c05c978: /* original 3020, guest PC 0x0c05c978 */
if(!s->budget--) { s->failed_pc=0x0c05c978u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c05c97a;
P_0c05c97a: /* original 8901, guest PC 0x0c05c97a */
if(!s->budget--) { s->failed_pc=0x0c05c97au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05c980; }
goto P_0c05c97c;
P_0c05c97c: /* original a08e, guest PC 0x0c05c97c */
if(!s->budget--) { s->failed_pc=0x0c05c97cu; return 0; }
goto P_0c05ca9c;
P_0c05c97e: /* original 0009, guest PC 0x0c05c97e */
if(!s->budget--) { s->failed_pc=0x0c05c97eu; return 0; }
goto P_0c05c980;
P_0c05c980: /* original d13b, guest PC 0x0c05c980 */
if(!s->budget--) { s->failed_pc=0x0c05c980u; return 0; }
r[1]=read(ram,0x0c05ca70u,4);
goto P_0c05c982;
P_0c05c982: /* original ec01, guest PC 0x0c05c982 */
if(!s->budget--) { s->failed_pc=0x0c05c982u; return 0; }
r[12]=0x00000001u;
goto P_0c05c984;
P_0c05c984: /* original d03b, guest PC 0x0c05c984 */
if(!s->budget--) { s->failed_pc=0x0c05c984u; return 0; }
r[0]=read(ram,0x0c05ca74u,4);
goto P_0c05c986;
P_0c05c986: /* original 21c2, guest PC 0x0c05c986 */
if(!s->budget--) { s->failed_pc=0x0c05c986u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c05c988;
P_0c05c988: /* original 6302, guest PC 0x0c05c988 */
if(!s->budget--) { s->failed_pc=0x0c05c988u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05c98a;
P_0c05c98a: /* original d23b, guest PC 0x0c05c98a */
if(!s->budget--) { s->failed_pc=0x0c05c98au; return 0; }
r[2]=read(ram,0x0c05ca78u,4);
goto P_0c05c98c;
P_0c05c98c: /* original 2232, guest PC 0x0c05c98c */
if(!s->budget--) { s->failed_pc=0x0c05c98cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05c98e;
P_0c05c98e: /* original 70f0, guest PC 0x0c05c98e */
if(!s->budget--) { s->failed_pc=0x0c05c98eu; return 0; }
r[0]+=0xfffffff0u;
goto P_0c05c990;
P_0c05c990: /* original d338, guest PC 0x0c05c990 */
if(!s->budget--) { s->failed_pc=0x0c05c990u; return 0; }
r[3]=read(ram,0x0c05ca74u,4);
goto P_0c05c992;
P_0c05c992: /* original 6132, guest PC 0x0c05c992 */
if(!s->budget--) { s->failed_pc=0x0c05c992u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05c994;
P_0c05c994: /* original 4108, guest PC 0x0c05c994 */
if(!s->budget--) { s->failed_pc=0x0c05c994u; return 0; }
r[1]<<=2;
goto P_0c05c996;
P_0c05c996: /* original 01b6, guest PC 0x0c05c996 */
if(!s->budget--) { s->failed_pc=0x0c05c996u; return 0; }
write(ram,r[1]+r[0],r[11],4);
goto P_0c05c998;
P_0c05c998: /* original d138, guest PC 0x0c05c998 */
if(!s->budget--) { s->failed_pc=0x0c05c998u; return 0; }
r[1]=read(ram,0x0c05ca7cu,4);
goto P_0c05c99a;
P_0c05c99a: /* original e200, guest PC 0x0c05c99a */
if(!s->budget--) { s->failed_pc=0x0c05c99au; return 0; }
r[2]=0x00000000u;
goto P_0c05c99c;
P_0c05c99c: /* original 2122, guest PC 0x0c05c99c */
if(!s->budget--) { s->failed_pc=0x0c05c99cu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c05c99e;
P_0c05c99e: /* original 7318, guest PC 0x0c05c99e */
if(!s->budget--) { s->failed_pc=0x0c05c99eu; return 0; }
r[3]+=0x00000018u;
goto P_0c05c9a0;
P_0c05c9a0: /* original 23c2, guest PC 0x0c05c9a0 */
if(!s->budget--) { s->failed_pc=0x0c05c9a0u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c05c9a2;
P_0c05c9a2: /* original 64f3, guest PC 0x0c05c9a2 */
if(!s->budget--) { s->failed_pc=0x0c05c9a2u; return 0; }
r[4]=r[15];
goto P_0c05c9a4;
P_0c05c9a4: /* original 52d4, guest PC 0x0c05c9a4 */
if(!s->budget--) { s->failed_pc=0x0c05c9a4u; return 0; }
r[2]=read(ram,r[13]+16,4);
goto P_0c05c9a6;
P_0c05c9a6: /* original 6a43, guest PC 0x0c05c9a6 */
if(!s->budget--) { s->failed_pc=0x0c05c9a6u; return 0; }
r[10]=r[4];
goto P_0c05c9a8;
P_0c05c9a8: /* original 22c9, guest PC 0x0c05c9a8 */
if(!s->budget--) { s->failed_pc=0x0c05c9a8u; return 0; }
r[2]&=r[12];
goto P_0c05c9aa;
P_0c05c9aa: /* original 69a3, guest PC 0x0c05c9aa */
if(!s->budget--) { s->failed_pc=0x0c05c9aau; return 0; }
r[9]=r[10];
goto P_0c05c9ac;
P_0c05c9ac: /* original 2a22, guest PC 0x0c05c9ac */
if(!s->budget--) { s->failed_pc=0x0c05c9acu; return 0; }
write(ram,r[10],r[2],4);
goto P_0c05c9ae;
P_0c05c9ae: /* original 68a3, guest PC 0x0c05c9ae */
if(!s->budget--) { s->failed_pc=0x0c05c9aeu; return 0; }
r[8]=r[10];
goto P_0c05c9b0;
P_0c05c9b0: /* original 50d4, guest PC 0x0c05c9b0 */
if(!s->budget--) { s->failed_pc=0x0c05c9b0u; return 0; }
r[0]=read(ram,r[13]+16,4);
goto P_0c05c9b2;
P_0c05c9b2: /* original 7904, guest PC 0x0c05c9b2 */
if(!s->budget--) { s->failed_pc=0x0c05c9b2u; return 0; }
r[9]+=0x00000004u;
goto P_0c05c9b4;
P_0c05c9b4: /* original 2b09, guest PC 0x0c05c9b4 */
if(!s->budget--) { s->failed_pc=0x0c05c9b4u; return 0; }
r[11]&=r[0];
goto P_0c05c9b6;
P_0c05c9b6: /* original 7808, guest PC 0x0c05c9b6 */
if(!s->budget--) { s->failed_pc=0x0c05c9b6u; return 0; }
r[8]+=0x00000008u;
goto P_0c05c9b8;
P_0c05c9b8: /* original 29b2, guest PC 0x0c05c9b8 */
if(!s->budget--) { s->failed_pc=0x0c05c9b8u; return 0; }
write(ram,r[9],r[11],4);
goto P_0c05c9ba;
P_0c05c9ba: /* original 50d4, guest PC 0x0c05c9ba */
if(!s->budget--) { s->failed_pc=0x0c05c9bau; return 0; }
r[0]=read(ram,r[13]+16,4);
goto P_0c05c9bc;
P_0c05c9bc: /* original c904, guest PC 0x0c05c9bc */
if(!s->budget--) { s->failed_pc=0x0c05c9bcu; return 0; }
r[0]&=4u;
goto P_0c05c9be;
P_0c05c9be: /* original 6ba3, guest PC 0x0c05c9be */
if(!s->budget--) { s->failed_pc=0x0c05c9beu; return 0; }
r[11]=r[10];
goto P_0c05c9c0;
P_0c05c9c0: /* original 2802, guest PC 0x0c05c9c0 */
if(!s->budget--) { s->failed_pc=0x0c05c9c0u; return 0; }
write(ram,r[8],r[0],4);
goto P_0c05c9c2;
P_0c05c9c2: /* original e200, guest PC 0x0c05c9c2 */
if(!s->budget--) { s->failed_pc=0x0c05c9c2u; return 0; }
r[2]=0x00000000u;
goto P_0c05c9c4;
P_0c05c9c4: /* original 50d4, guest PC 0x0c05c9c4 */
if(!s->budget--) { s->failed_pc=0x0c05c9c4u; return 0; }
r[0]=read(ram,r[13]+16,4);
goto P_0c05c9c6;
P_0c05c9c6: /* original 7b0c, guest PC 0x0c05c9c6 */
if(!s->budget--) { s->failed_pc=0x0c05c9c6u; return 0; }
r[11]+=0x0000000cu;
goto P_0c05c9c8;
P_0c05c9c8: /* original c908, guest PC 0x0c05c9c8 */
if(!s->budget--) { s->failed_pc=0x0c05c9c8u; return 0; }
r[0]&=8u;
goto P_0c05c9ca;
P_0c05c9ca: /* original 2b02, guest PC 0x0c05c9ca */
if(!s->budget--) { s->failed_pc=0x0c05c9cau; return 0; }
write(ram,r[11],r[0],4);
goto P_0c05c9cc;
P_0c05c9cc: /* original 2f26, guest PC 0x0c05c9cc */
if(!s->budget--) { s->failed_pc=0x0c05c9ccu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c9ce;
P_0c05c9ce: /* original 67b2, guest PC 0x0c05c9ce */
if(!s->budget--) { s->failed_pc=0x0c05c9ceu; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c05c9d0;
P_0c05c9d0: /* original 6682, guest PC 0x0c05c9d0 */
if(!s->budget--) { s->failed_pc=0x0c05c9d0u; return 0; }
tmp=read(ram,r[8],4);
r[6]=tmp;
goto P_0c05c9d2;
P_0c05c9d2: /* original 6592, guest PC 0x0c05c9d2 */
if(!s->budget--) { s->failed_pc=0x0c05c9d2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c05c9d4;
P_0c05c9d4: /* original b412, guest PC 0x0c05c9d4 */
if(!s->budget--) { s->failed_pc=0x0c05c9d4u; return 0; }
target=code_base|0x0c05d1fcu; r[16]=code_base|0x0c05c9d8u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c9d8u) { target=s->pc; goto dispatch; }
goto P_0c05c9d8;
P_0c05c9d6: /* original 64a2, guest PC 0x0c05c9d6 */
if(!s->budget--) { s->failed_pc=0x0c05c9d6u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c05c9d8;
P_0c05c9d8: /* original 2fc6, guest PC 0x0c05c9d8 */
if(!s->budget--) { s->failed_pc=0x0c05c9d8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c9da;
P_0c05c9da: /* original e300, guest PC 0x0c05c9da */
if(!s->budget--) { s->failed_pc=0x0c05c9dau; return 0; }
r[3]=0x00000000u;
goto P_0c05c9dc;
P_0c05c9dc: /* original 2f36, guest PC 0x0c05c9dc */
if(!s->budget--) { s->failed_pc=0x0c05c9dcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c9de;
P_0c05c9de: /* original 67b2, guest PC 0x0c05c9de */
if(!s->budget--) { s->failed_pc=0x0c05c9deu; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c05c9e0;
P_0c05c9e0: /* original 6682, guest PC 0x0c05c9e0 */
if(!s->budget--) { s->failed_pc=0x0c05c9e0u; return 0; }
tmp=read(ram,r[8],4);
r[6]=tmp;
goto P_0c05c9e2;
P_0c05c9e2: /* original 6592, guest PC 0x0c05c9e2 */
if(!s->budget--) { s->failed_pc=0x0c05c9e2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c05c9e4;
P_0c05c9e4: /* original b474, guest PC 0x0c05c9e4 */
if(!s->budget--) { s->failed_pc=0x0c05c9e4u; return 0; }
target=code_base|0x0c05d2d0u; r[16]=code_base|0x0c05c9e8u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c9e8u) { target=s->pc; goto dispatch; }
goto P_0c05c9e8;
P_0c05c9e6: /* original 64a2, guest PC 0x0c05c9e6 */
if(!s->budget--) { s->failed_pc=0x0c05c9e6u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c05c9e8;
P_0c05c9e8: /* original 7f0c, guest PC 0x0c05c9e8 */
if(!s->budget--) { s->failed_pc=0x0c05c9e8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05c9ea;
P_0c05c9ea: /* original 6d03, guest PC 0x0c05c9ea */
if(!s->budget--) { s->failed_pc=0x0c05c9eau; return 0; }
r[13]=r[0];
goto P_0c05c9ec;
P_0c05c9ec: /* original b5dc, guest PC 0x0c05c9ec */
if(!s->budget--) { s->failed_pc=0x0c05c9ecu; return 0; }
target=code_base|0x0c05d5a8u; r[16]=code_base|0x0c05c9f0u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c9f0u) { target=s->pc; goto dispatch; }
goto P_0c05c9f0;
P_0c05c9ee: /* original 6403, guest PC 0x0c05c9ee */
if(!s->budget--) { s->failed_pc=0x0c05c9eeu; return 0; }
r[4]=r[0];
goto P_0c05c9f0;
P_0c05c9f0: /* original 9437, guest PC 0x0c05c9f0 */
if(!s->budget--) { s->failed_pc=0x0c05c9f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ca62u,2);
goto P_0c05c9f2;
P_0c05c9f2: /* original e058, guest PC 0x0c05c9f2 */
if(!s->budget--) { s->failed_pc=0x0c05c9f2u; return 0; }
r[0]=0x00000058u;
goto P_0c05c9f4;
P_0c05c9f4: /* original d322, guest PC 0x0c05c9f4 */
if(!s->budget--) { s->failed_pc=0x0c05c9f4u; return 0; }
r[3]=read(ram,0x0c05ca80u,4);
goto P_0c05c9f6;
P_0c05c9f6: /* original 02ee, guest PC 0x0c05c9f6 */
if(!s->budget--) { s->failed_pc=0x0c05c9f6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05c9f8;
P_0c05c9f8: /* original 4201, guest PC 0x0c05c9f8 */
if(!s->budget--) { s->failed_pc=0x0c05c9f8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05c9fa;
P_0c05c9fa: /* original 0e26, guest PC 0x0c05c9fa */
if(!s->budget--) { s->failed_pc=0x0c05c9fau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c05c9fc;
P_0c05c9fc: /* original 56e9, guest PC 0x0c05c9fc */
if(!s->budget--) { s->failed_pc=0x0c05c9fcu; return 0; }
r[6]=read(ram,r[14]+36,4);
goto P_0c05c9fe;
P_0c05c9fe: /* original 430b, guest PC 0x0c05c9fe */
if(!s->budget--) { s->failed_pc=0x0c05c9feu; return 0; }
target=r[3];
r[16]=code_base|0x0c05ca02u;
r[5]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ca02u) { target=s->pc; goto dispatch; }
goto P_0c05ca02;
P_0c05ca00: /* original 55e6, guest PC 0x0c05ca00 */
if(!s->budget--) { s->failed_pc=0x0c05ca00u; return 0; }
r[5]=read(ram,r[14]+24,4);
goto P_0c05ca02;
P_0c05ca02: /* original e060, guest PC 0x0c05ca02 */
if(!s->budget--) { s->failed_pc=0x0c05ca02u; return 0; }
r[0]=0x00000060u;
goto P_0c05ca04;
P_0c05ca04: /* original d31f, guest PC 0x0c05ca04 */
if(!s->budget--) { s->failed_pc=0x0c05ca04u; return 0; }
r[3]=read(ram,0x0c05ca84u,4);
goto P_0c05ca06;
P_0c05ca06: /* original 04ee, guest PC 0x0c05ca06 */
if(!s->budget--) { s->failed_pc=0x0c05ca06u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c05ca08;
P_0c05ca08: /* original 644b, guest PC 0x0c05ca08 */
if(!s->budget--) { s->failed_pc=0x0c05ca08u; return 0; }
r[4]=0u-r[4];
goto P_0c05ca0a;
P_0c05ca0a: /* original 343c, guest PC 0x0c05ca0a */
if(!s->budget--) { s->failed_pc=0x0c05ca0au; return 0; }
r[4]+=r[3];
goto P_0c05ca0c;
P_0c05ca0c: /* original e058, guest PC 0x0c05ca0c */
if(!s->budget--) { s->failed_pc=0x0c05ca0cu; return 0; }
r[0]=0x00000058u;
goto P_0c05ca0e;
P_0c05ca0e: /* original 02ee, guest PC 0x0c05ca0e */
if(!s->budget--) { s->failed_pc=0x0c05ca0eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ca10;
P_0c05ca10: /* original 3246, guest PC 0x0c05ca10 */
if(!s->budget--) { s->failed_pc=0x0c05ca10u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[4])!=0);
goto P_0c05ca12;
P_0c05ca12: /* original 8b00, guest PC 0x0c05ca12 */
if(!s->budget--) { s->failed_pc=0x0c05ca12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ca16; }
goto P_0c05ca14;
P_0c05ca14: /* original 0e46, guest PC 0x0c05ca14 */
if(!s->budget--) { s->failed_pc=0x0c05ca14u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c05ca16;
P_0c05ca16: /* original d61c, guest PC 0x0c05ca16 */
if(!s->budget--) { s->failed_pc=0x0c05ca16u; return 0; }
r[6]=read(ram,0x0c05ca88u,4);
goto P_0c05ca18;
P_0c05ca18: /* original d31c, guest PC 0x0c05ca18 */
if(!s->budget--) { s->failed_pc=0x0c05ca18u; return 0; }
r[3]=read(ram,0x0c05ca8cu,4);
goto P_0c05ca1a;
P_0c05ca1a: /* original 6563, guest PC 0x0c05ca1a */
if(!s->budget--) { s->failed_pc=0x0c05ca1au; return 0; }
r[5]=r[6];
goto P_0c05ca1c;
P_0c05ca1c: /* original 75fc, guest PC 0x0c05ca1c */
if(!s->budget--) { s->failed_pc=0x0c05ca1cu; return 0; }
r[5]+=0xfffffffcu;
goto P_0c05ca1e;
P_0c05ca1e: /* original 430b, guest PC 0x0c05ca1e */
if(!s->budget--) { s->failed_pc=0x0c05ca1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c05ca22u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ca22u) { target=s->pc; goto dispatch; }
goto P_0c05ca22;
P_0c05ca20: /* original 04ee, guest PC 0x0c05ca20 */
if(!s->budget--) { s->failed_pc=0x0c05ca20u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c05ca22;
P_0c05ca22: /* original 6b03, guest PC 0x0c05ca22 */
if(!s->budget--) { s->failed_pc=0x0c05ca22u; return 0; }
r[11]=r[0];
goto P_0c05ca24;
P_0c05ca24: /* original 2bb8, guest PC 0x0c05ca24 */
if(!s->budget--) { s->failed_pc=0x0c05ca24u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c05ca26;
P_0c05ca26: /* original 8b46, guest PC 0x0c05ca26 */
if(!s->budget--) { s->failed_pc=0x0c05ca26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cab6; }
goto P_0c05ca28;
P_0c05ca28: /* original d319, guest PC 0x0c05ca28 */
if(!s->budget--) { s->failed_pc=0x0c05ca28u; return 0; }
r[3]=read(ram,0x0c05ca90u,4);
goto P_0c05ca2a;
P_0c05ca2a: /* original e058, guest PC 0x0c05ca2a */
if(!s->budget--) { s->failed_pc=0x0c05ca2au; return 0; }
r[0]=0x00000058u;
goto P_0c05ca2c;
P_0c05ca2c: /* original 02ee, guest PC 0x0c05ca2c */
if(!s->budget--) { s->failed_pc=0x0c05ca2cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ca2e;
P_0c05ca2e: /* original 2322, guest PC 0x0c05ca2e */
if(!s->budget--) { s->failed_pc=0x0c05ca2eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05ca30;
P_0c05ca30: /* original d718, guest PC 0x0c05ca30 */
if(!s->budget--) { s->failed_pc=0x0c05ca30u; return 0; }
r[7]=read(ram,0x0c05ca94u,4);
goto P_0c05ca32;
P_0c05ca32: /* original e100, guest PC 0x0c05ca32 */
if(!s->budget--) { s->failed_pc=0x0c05ca32u; return 0; }
r[1]=0x00000000u;
goto P_0c05ca34;
P_0c05ca34: /* original 2f16, guest PC 0x0c05ca34 */
if(!s->budget--) { s->failed_pc=0x0c05ca34u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ca36;
P_0c05ca36: /* original 53e6, guest PC 0x0c05ca36 */
if(!s->budget--) { s->failed_pc=0x0c05ca36u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c05ca38;
P_0c05ca38: /* original 6337, guest PC 0x0c05ca38 */
if(!s->budget--) { s->failed_pc=0x0c05ca38u; return 0; }
r[3]=~r[3];
goto P_0c05ca3a;
P_0c05ca3a: /* original 2d39, guest PC 0x0c05ca3a */
if(!s->budget--) { s->failed_pc=0x0c05ca3au; return 0; }
r[13]&=r[3];
goto P_0c05ca3c;
P_0c05ca3c: /* original 2fd6, guest PC 0x0c05ca3c */
if(!s->budget--) { s->failed_pc=0x0c05ca3cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ca3e;
P_0c05ca3e: /* original 5773, guest PC 0x0c05ca3e */
if(!s->budget--) { s->failed_pc=0x0c05ca3eu; return 0; }
r[7]=read(ram,r[7]+12,4);
goto P_0c05ca40;
P_0c05ca40: /* original e3f9, guest PC 0x0c05ca40 */
if(!s->budget--) { s->failed_pc=0x0c05ca40u; return 0; }
r[3]=0xfffffff9u;
goto P_0c05ca42;
P_0c05ca42: /* original 473d, guest PC 0x0c05ca42 */
if(!s->budget--) { s->failed_pc=0x0c05ca42u; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?r[7]>>((-r[3])&31u):0):r[7]<<(r[3]&31u);
goto P_0c05ca44;
P_0c05ca44: /* original d613, guest PC 0x0c05ca44 */
if(!s->budget--) { s->failed_pc=0x0c05ca44u; return 0; }
r[6]=read(ram,0x0c05ca94u,4);
goto P_0c05ca46;
P_0c05ca46: /* original 5662, guest PC 0x0c05ca46 */
if(!s->budget--) { s->failed_pc=0x0c05ca46u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c05ca48;
P_0c05ca48: /* original 463d, guest PC 0x0c05ca48 */
if(!s->budget--) { s->failed_pc=0x0c05ca48u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?r[6]>>((-r[3])&31u):0):r[6]<<(r[3]&31u);
goto P_0c05ca4a;
P_0c05ca4a: /* original d512, guest PC 0x0c05ca4a */
if(!s->budget--) { s->failed_pc=0x0c05ca4au; return 0; }
r[5]=read(ram,0x0c05ca94u,4);
goto P_0c05ca4c;
P_0c05ca4c: /* original 5551, guest PC 0x0c05ca4c */
if(!s->budget--) { s->failed_pc=0x0c05ca4cu; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c05ca4e;
P_0c05ca4e: /* original 453d, guest PC 0x0c05ca4e */
if(!s->budget--) { s->failed_pc=0x0c05ca4eu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c05ca50;
P_0c05ca50: /* original d410, guest PC 0x0c05ca50 */
if(!s->budget--) { s->failed_pc=0x0c05ca50u; return 0; }
r[4]=read(ram,0x0c05ca94u,4);
goto P_0c05ca52;
P_0c05ca52: /* original 6442, guest PC 0x0c05ca52 */
if(!s->budget--) { s->failed_pc=0x0c05ca52u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05ca54;
P_0c05ca54: /* original d210, guest PC 0x0c05ca54 */
if(!s->budget--) { s->failed_pc=0x0c05ca54u; return 0; }
r[2]=read(ram,0x0c05ca98u,4);
goto P_0c05ca56;
P_0c05ca56: /* original 420b, guest PC 0x0c05ca56 */
if(!s->budget--) { s->failed_pc=0x0c05ca56u; return 0; }
target=r[2];
r[16]=code_base|0x0c05ca5au;
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ca5au) { target=s->pc; goto dispatch; }
goto P_0c05ca5a;
P_0c05ca58: /* original 443d, guest PC 0x0c05ca58 */
if(!s->budget--) { s->failed_pc=0x0c05ca58u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c05ca5a;
P_0c05ca5a: /* original 7f08, guest PC 0x0c05ca5a */
if(!s->budget--) { s->failed_pc=0x0c05ca5au; return 0; }
r[15]+=0x00000008u;
goto P_0c05ca5c;
P_0c05ca5c: /* original d307, guest PC 0x0c05ca5c */
if(!s->budget--) { s->failed_pc=0x0c05ca5cu; return 0; }
r[3]=read(ram,0x0c05ca7cu,4);
goto P_0c05ca5e;
P_0c05ca5e: /* original a02a, guest PC 0x0c05ca5e */
if(!s->budget--) { s->failed_pc=0x0c05ca5eu; return 0; }
write(ram,r[3],r[12],4);
goto P_0c05cab6;
P_0c05ca60: /* original 23c2, guest PC 0x0c05ca60 */
if(!s->budget--) { s->failed_pc=0x0c05ca60u; return 0; }
write(ram,r[3],r[12],4);
if(!vf3_matrix_family(0x0c05ca62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05ca62u; return 0; } return 1;
P_0c05ca9c: /* original 9482, guest PC 0x0c05ca9c */
if(!s->budget--) { s->failed_pc=0x0c05ca9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05cba4u,2);
goto P_0c05ca9e;
P_0c05ca9e: /* original b7c6, guest PC 0x0c05ca9e */
if(!s->budget--) { s->failed_pc=0x0c05ca9eu; return 0; }
target=code_base|0x0c05da2eu; r[16]=code_base|0x0c05caa2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05caa2u) { target=s->pc; goto dispatch; }
goto P_0c05caa2;
P_0c05caa0: /* original 0009, guest PC 0x0c05caa0 */
if(!s->budget--) { s->failed_pc=0x0c05caa0u; return 0; }
goto P_0c05caa2;
P_0c05caa2: /* original 9280, guest PC 0x0c05caa2 */
if(!s->budget--) { s->failed_pc=0x0c05caa2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05cba6u,2);
goto P_0c05caa4;
P_0c05caa4: /* original 3020, guest PC 0x0c05caa4 */
if(!s->budget--) { s->failed_pc=0x0c05caa4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c05caa6;
P_0c05caa6: /* original 8b06, guest PC 0x0c05caa6 */
if(!s->budget--) { s->failed_pc=0x0c05caa6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cab6; }
goto P_0c05caa8;
P_0c05caa8: /* original d43f, guest PC 0x0c05caa8 */
if(!s->budget--) { s->failed_pc=0x0c05caa8u; return 0; }
r[4]=read(ram,0x0c05cba8u,4);
goto P_0c05caaa;
P_0c05caaa: /* original b7c6, guest PC 0x0c05caaa */
if(!s->budget--) { s->failed_pc=0x0c05caaau; return 0; }
target=code_base|0x0c05da3au; r[16]=code_base|0x0c05caaeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05caaeu) { target=s->pc; goto dispatch; }
goto P_0c05caae;
P_0c05caac: /* original 0009, guest PC 0x0c05caac */
if(!s->budget--) { s->failed_pc=0x0c05caacu; return 0; }
goto P_0c05caae;
P_0c05caae: /* original e054, guest PC 0x0c05caae */
if(!s->budget--) { s->failed_pc=0x0c05caaeu; return 0; }
r[0]=0x00000054u;
goto P_0c05cab0;
P_0c05cab0: /* original b716, guest PC 0x0c05cab0 */
if(!s->budget--) { s->failed_pc=0x0c05cab0u; return 0; }
target=code_base|0x0c05d8e0u; r[16]=code_base|0x0c05cab4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cab4u) { target=s->pc; goto dispatch; }
goto P_0c05cab4;
P_0c05cab2: /* original 04ee, guest PC 0x0c05cab2 */
if(!s->budget--) { s->failed_pc=0x0c05cab2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c05cab4;
P_0c05cab4: /* original 6b03, guest PC 0x0c05cab4 */
if(!s->budget--) { s->failed_pc=0x0c05cab4u; return 0; }
r[11]=r[0];
goto P_0c05cab6;
P_0c05cab6: /* original 60b3, guest PC 0x0c05cab6 */
if(!s->budget--) { s->failed_pc=0x0c05cab6u; return 0; }
r[0]=r[11];
goto P_0c05cab8;
P_0c05cab8: /* original 0009, guest PC 0x0c05cab8 */
if(!s->budget--) { s->failed_pc=0x0c05cab8u; return 0; }
goto P_0c05caba;
P_0c05caba: /* original 7f10, guest PC 0x0c05caba */
if(!s->budget--) { s->failed_pc=0x0c05cabau; return 0; }
r[15]+=0x00000010u;
goto P_0c05cabc;
P_0c05cabc: /* original 4f26, guest PC 0x0c05cabc */
if(!s->budget--) { s->failed_pc=0x0c05cabcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05cabe;
P_0c05cabe: /* original 68f6, guest PC 0x0c05cabe */
if(!s->budget--) { s->failed_pc=0x0c05cabeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05cac0;
P_0c05cac0: /* original 69f6, guest PC 0x0c05cac0 */
if(!s->budget--) { s->failed_pc=0x0c05cac0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05cac2;
P_0c05cac2: /* original 6af6, guest PC 0x0c05cac2 */
if(!s->budget--) { s->failed_pc=0x0c05cac2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05cac4;
P_0c05cac4: /* original 6bf6, guest PC 0x0c05cac4 */
if(!s->budget--) { s->failed_pc=0x0c05cac4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05cac6;
P_0c05cac6: /* original 6cf6, guest PC 0x0c05cac6 */
if(!s->budget--) { s->failed_pc=0x0c05cac6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05cac8;
P_0c05cac8: /* original 6df6, guest PC 0x0c05cac8 */
if(!s->budget--) { s->failed_pc=0x0c05cac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05caca;
P_0c05caca: /* original 000b, guest PC 0x0c05caca */
if(!s->budget--) { s->failed_pc=0x0c05cacau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05cacc: /* original 6ef6, guest PC 0x0c05cacc */
if(!s->budget--) { s->failed_pc=0x0c05caccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05caceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05caceu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
