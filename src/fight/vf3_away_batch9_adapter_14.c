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
int vf3_away_batch9_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06a826u: goto P_0c06a826;
case 0x0c06a828u: goto P_0c06a828;
case 0x0c06a82au: goto P_0c06a82a;
case 0x0c06a82cu: goto P_0c06a82c;
case 0x0c06a82eu: goto P_0c06a82e;
case 0x0c06a830u: goto P_0c06a830;
case 0x0c06a832u: goto P_0c06a832;
case 0x0c06a834u: goto P_0c06a834;
case 0x0c06a836u: goto P_0c06a836;
case 0x0c06a838u: goto P_0c06a838;
case 0x0c06a83au: goto P_0c06a83a;
case 0x0c06a83cu: goto P_0c06a83c;
case 0x0c06a83eu: goto P_0c06a83e;
case 0x0c06a840u: goto P_0c06a840;
case 0x0c06a842u: goto P_0c06a842;
case 0x0c06a844u: goto P_0c06a844;
case 0x0c06a846u: goto P_0c06a846;
case 0x0c06a848u: goto P_0c06a848;
case 0x0c06a84au: goto P_0c06a84a;
case 0x0c06a84cu: goto P_0c06a84c;
case 0x0c06a84eu: goto P_0c06a84e;
case 0x0c06a850u: goto P_0c06a850;
case 0x0c06a852u: goto P_0c06a852;
case 0x0c06a854u: goto P_0c06a854;
case 0x0c06a856u: goto P_0c06a856;
case 0x0c06a858u: goto P_0c06a858;
case 0x0c06a85au: goto P_0c06a85a;
case 0x0c06a85cu: goto P_0c06a85c;
case 0x0c06a85eu: goto P_0c06a85e;
case 0x0c06a860u: goto P_0c06a860;
case 0x0c06a862u: goto P_0c06a862;
case 0x0c06a864u: goto P_0c06a864;
case 0x0c06a866u: goto P_0c06a866;
case 0x0c06a868u: goto P_0c06a868;
case 0x0c06a86au: goto P_0c06a86a;
case 0x0c06a86cu: goto P_0c06a86c;
case 0x0c06a86eu: goto P_0c06a86e;
case 0x0c06a870u: goto P_0c06a870;
case 0x0c06a872u: goto P_0c06a872;
case 0x0c06a874u: goto P_0c06a874;
case 0x0c06a876u: goto P_0c06a876;
case 0x0c06a878u: goto P_0c06a878;
case 0x0c06a87au: goto P_0c06a87a;
case 0x0c06a87cu: goto P_0c06a87c;
case 0x0c06a87eu: goto P_0c06a87e;
case 0x0c06a880u: goto P_0c06a880;
case 0x0c06a882u: goto P_0c06a882;
case 0x0c06a884u: goto P_0c06a884;
case 0x0c06a886u: goto P_0c06a886;
case 0x0c06a888u: goto P_0c06a888;
case 0x0c06a88au: goto P_0c06a88a;
case 0x0c06a88cu: goto P_0c06a88c;
case 0x0c06a88eu: goto P_0c06a88e;
case 0x0c06a890u: goto P_0c06a890;
case 0x0c06a892u: goto P_0c06a892;
case 0x0c06a894u: goto P_0c06a894;
case 0x0c06a896u: goto P_0c06a896;
case 0x0c06a898u: goto P_0c06a898;
case 0x0c06a89au: goto P_0c06a89a;
case 0x0c06a89cu: goto P_0c06a89c;
case 0x0c06a89eu: goto P_0c06a89e;
case 0x0c06a8a0u: goto P_0c06a8a0;
case 0x0c06a8a2u: goto P_0c06a8a2;
case 0x0c06a8a4u: goto P_0c06a8a4;
case 0x0c06a8a6u: goto P_0c06a8a6;
case 0x0c06a8a8u: goto P_0c06a8a8;
case 0x0c06a8aau: goto P_0c06a8aa;
case 0x0c06a8acu: goto P_0c06a8ac;
case 0x0c06a8aeu: goto P_0c06a8ae;
case 0x0c06a8b0u: goto P_0c06a8b0;
case 0x0c06a8b2u: goto P_0c06a8b2;
case 0x0c06a8b4u: goto P_0c06a8b4;
case 0x0c06a8b6u: goto P_0c06a8b6;
case 0x0c06a8b8u: goto P_0c06a8b8;
case 0x0c06a8bau: goto P_0c06a8ba;
case 0x0c06a8bcu: goto P_0c06a8bc;
case 0x0c06a8beu: goto P_0c06a8be;
case 0x0c06a8c0u: goto P_0c06a8c0;
case 0x0c06a8c2u: goto P_0c06a8c2;
case 0x0c06a8c4u: goto P_0c06a8c4;
case 0x0c06a8c6u: goto P_0c06a8c6;
case 0x0c06a8c8u: goto P_0c06a8c8;
case 0x0c06a8cau: goto P_0c06a8ca;
case 0x0c06a8ccu: goto P_0c06a8cc;
case 0x0c06a8ceu: goto P_0c06a8ce;
case 0x0c06a8d0u: goto P_0c06a8d0;
case 0x0c06a8d2u: goto P_0c06a8d2;
case 0x0c06a8d4u: goto P_0c06a8d4;
case 0x0c06a8d6u: goto P_0c06a8d6;
case 0x0c06a8d8u: goto P_0c06a8d8;
case 0x0c06a8dau: goto P_0c06a8da;
case 0x0c06a8dcu: goto P_0c06a8dc;
case 0x0c06a8deu: goto P_0c06a8de;
case 0x0c06a8e0u: goto P_0c06a8e0;
case 0x0c06a8e2u: goto P_0c06a8e2;
case 0x0c06a8e4u: goto P_0c06a8e4;
case 0x0c06a8e6u: goto P_0c06a8e6;
case 0x0c06a8e8u: goto P_0c06a8e8;
case 0x0c06a8eau: goto P_0c06a8ea;
case 0x0c06a8ecu: goto P_0c06a8ec;
case 0x0c06a8eeu: goto P_0c06a8ee;
case 0x0c06a8f0u: goto P_0c06a8f0;
case 0x0c06a8f2u: goto P_0c06a8f2;
case 0x0c06a8f4u: goto P_0c06a8f4;
case 0x0c06a8f6u: goto P_0c06a8f6;
case 0x0c06a8f8u: goto P_0c06a8f8;
case 0x0c06a8fau: goto P_0c06a8fa;
case 0x0c06a8fcu: goto P_0c06a8fc;
case 0x0c06a8feu: goto P_0c06a8fe;
case 0x0c06a900u: goto P_0c06a900;
case 0x0c06a902u: goto P_0c06a902;
case 0x0c06a904u: goto P_0c06a904;
case 0x0c06a906u: goto P_0c06a906;
case 0x0c06a908u: goto P_0c06a908;
case 0x0c06a90au: goto P_0c06a90a;
case 0x0c06a90cu: goto P_0c06a90c;
case 0x0c06a90eu: goto P_0c06a90e;
case 0x0c06a910u: goto P_0c06a910;
case 0x0c06a912u: goto P_0c06a912;
case 0x0c06a914u: goto P_0c06a914;
case 0x0c06a916u: goto P_0c06a916;
case 0x0c06a918u: goto P_0c06a918;
case 0x0c06a91au: goto P_0c06a91a;
case 0x0c06a91cu: goto P_0c06a91c;
case 0x0c06a91eu: goto P_0c06a91e;
case 0x0c06a920u: goto P_0c06a920;
case 0x0c06a922u: goto P_0c06a922;
case 0x0c06a958u: goto P_0c06a958;
case 0x0c06a95au: goto P_0c06a95a;
case 0x0c06a95cu: goto P_0c06a95c;
case 0x0c06a95eu: goto P_0c06a95e;
case 0x0c06a960u: goto P_0c06a960;
case 0x0c06a962u: goto P_0c06a962;
case 0x0c06a964u: goto P_0c06a964;
case 0x0c06a966u: goto P_0c06a966;
case 0x0c06a968u: goto P_0c06a968;
case 0x0c06a96au: goto P_0c06a96a;
case 0x0c06a96cu: goto P_0c06a96c;
case 0x0c06a96eu: goto P_0c06a96e;
case 0x0c06a970u: goto P_0c06a970;
case 0x0c06a972u: goto P_0c06a972;
case 0x0c06a974u: goto P_0c06a974;
case 0x0c06a976u: goto P_0c06a976;
case 0x0c06a978u: goto P_0c06a978;
case 0x0c06a97au: goto P_0c06a97a;
case 0x0c06a97cu: goto P_0c06a97c;
case 0x0c06a97eu: goto P_0c06a97e;
case 0x0c06a980u: goto P_0c06a980;
case 0x0c06a982u: goto P_0c06a982;
case 0x0c06a984u: goto P_0c06a984;
case 0x0c06a986u: goto P_0c06a986;
case 0x0c06a988u: goto P_0c06a988;
case 0x0c06a98au: goto P_0c06a98a;
case 0x0c06a98cu: goto P_0c06a98c;
case 0x0c06a98eu: goto P_0c06a98e;
case 0x0c06a990u: goto P_0c06a990;
case 0x0c06a992u: goto P_0c06a992;
case 0x0c06a994u: goto P_0c06a994;
case 0x0c06a996u: goto P_0c06a996;
case 0x0c06a998u: goto P_0c06a998;
case 0x0c06a99au: goto P_0c06a99a;
case 0x0c06a99cu: goto P_0c06a99c;
case 0x0c06a99eu: goto P_0c06a99e;
case 0x0c06a9a0u: goto P_0c06a9a0;
case 0x0c06a9a2u: goto P_0c06a9a2;
case 0x0c06a9a4u: goto P_0c06a9a4;
case 0x0c06a9a6u: goto P_0c06a9a6;
case 0x0c06a9a8u: goto P_0c06a9a8;
case 0x0c06a9aau: goto P_0c06a9aa;
case 0x0c06a9acu: goto P_0c06a9ac;
case 0x0c06a9aeu: goto P_0c06a9ae;
case 0x0c06a9b0u: goto P_0c06a9b0;
case 0x0c06a9b2u: goto P_0c06a9b2;
case 0x0c06a9b4u: goto P_0c06a9b4;
case 0x0c06a9b6u: goto P_0c06a9b6;
case 0x0c06a9b8u: goto P_0c06a9b8;
case 0x0c06a9bau: goto P_0c06a9ba;
case 0x0c06a9bcu: goto P_0c06a9bc;
case 0x0c06a9beu: goto P_0c06a9be;
case 0x0c06a9c0u: goto P_0c06a9c0;
case 0x0c06a9c2u: goto P_0c06a9c2;
case 0x0c06a9c4u: goto P_0c06a9c4;
case 0x0c06a9c6u: goto P_0c06a9c6;
case 0x0c06a9c8u: goto P_0c06a9c8;
case 0x0c06a9cau: goto P_0c06a9ca;
case 0x0c06a9ccu: goto P_0c06a9cc;
case 0x0c06a9ceu: goto P_0c06a9ce;
case 0x0c06a9d0u: goto P_0c06a9d0;
case 0x0c06a9d2u: goto P_0c06a9d2;
case 0x0c06a9d4u: goto P_0c06a9d4;
case 0x0c06a9d6u: goto P_0c06a9d6;
case 0x0c06a9d8u: goto P_0c06a9d8;
case 0x0c06a9dau: goto P_0c06a9da;
case 0x0c06a9dcu: goto P_0c06a9dc;
case 0x0c06a9deu: goto P_0c06a9de;
case 0x0c06a9e0u: goto P_0c06a9e0;
case 0x0c06a9e2u: goto P_0c06a9e2;
case 0x0c06a9e4u: goto P_0c06a9e4;
case 0x0c06a9e6u: goto P_0c06a9e6;
case 0x0c06a9e8u: goto P_0c06a9e8;
case 0x0c06a9eau: goto P_0c06a9ea;
case 0x0c06a9ecu: goto P_0c06a9ec;
case 0x0c06a9eeu: goto P_0c06a9ee;
case 0x0c06a9f0u: goto P_0c06a9f0;
case 0x0c06a9f2u: goto P_0c06a9f2;
case 0x0c06a9f4u: goto P_0c06a9f4;
case 0x0c06a9f6u: goto P_0c06a9f6;
case 0x0c06a9f8u: goto P_0c06a9f8;
case 0x0c06a9fau: goto P_0c06a9fa;
case 0x0c06a9fcu: goto P_0c06a9fc;
case 0x0c06a9feu: goto P_0c06a9fe;
case 0x0c06aa00u: goto P_0c06aa00;
case 0x0c06aa02u: goto P_0c06aa02;
case 0x0c06aa04u: goto P_0c06aa04;
case 0x0c06aa06u: goto P_0c06aa06;
case 0x0c06aa08u: goto P_0c06aa08;
case 0x0c06aa0au: goto P_0c06aa0a;
case 0x0c06aa0cu: goto P_0c06aa0c;
case 0x0c06aa0eu: goto P_0c06aa0e;
case 0x0c06aa10u: goto P_0c06aa10;
case 0x0c06aa12u: goto P_0c06aa12;
case 0x0c06aa14u: goto P_0c06aa14;
case 0x0c06aa16u: goto P_0c06aa16;
case 0x0c06aa18u: goto P_0c06aa18;
case 0x0c06aa1au: goto P_0c06aa1a;
case 0x0c06aa1cu: goto P_0c06aa1c;
case 0x0c06aa1eu: goto P_0c06aa1e;
case 0x0c06aa20u: goto P_0c06aa20;
case 0x0c06aa22u: goto P_0c06aa22;
case 0x0c06aa24u: goto P_0c06aa24;
case 0x0c06aa26u: goto P_0c06aa26;
case 0x0c06aa28u: goto P_0c06aa28;
case 0x0c06aa2au: goto P_0c06aa2a;
case 0x0c06aa2cu: goto P_0c06aa2c;
case 0x0c06aa2eu: goto P_0c06aa2e;
case 0x0c06aa30u: goto P_0c06aa30;
case 0x0c06aa32u: goto P_0c06aa32;
case 0x0c06aa34u: goto P_0c06aa34;
case 0x0c06aa36u: goto P_0c06aa36;
case 0x0c06aa38u: goto P_0c06aa38;
case 0x0c06aa3au: goto P_0c06aa3a;
case 0x0c06aa3cu: goto P_0c06aa3c;
case 0x0c06aa3eu: goto P_0c06aa3e;
case 0x0c06aa40u: goto P_0c06aa40;
case 0x0c06aa42u: goto P_0c06aa42;
case 0x0c06aa44u: goto P_0c06aa44;
case 0x0c06aa46u: goto P_0c06aa46;
case 0x0c06aa48u: goto P_0c06aa48;
case 0x0c06aa4au: goto P_0c06aa4a;
case 0x0c06aa4cu: goto P_0c06aa4c;
case 0x0c06aa4eu: goto P_0c06aa4e;
case 0x0c06aa50u: goto P_0c06aa50;
case 0x0c06aa52u: goto P_0c06aa52;
case 0x0c06aa54u: goto P_0c06aa54;
case 0x0c06aa56u: goto P_0c06aa56;
case 0x0c06aa58u: goto P_0c06aa58;
case 0x0c06aa5au: goto P_0c06aa5a;
case 0x0c06aa5cu: goto P_0c06aa5c;
case 0x0c06aa5eu: goto P_0c06aa5e;
case 0x0c06aa60u: goto P_0c06aa60;
case 0x0c06aa62u: goto P_0c06aa62;
case 0x0c06aa64u: goto P_0c06aa64;
case 0x0c06aa66u: goto P_0c06aa66;
case 0x0c06aa68u: goto P_0c06aa68;
case 0x0c06aa6au: goto P_0c06aa6a;
case 0x0c06aa6cu: goto P_0c06aa6c;
case 0x0c06aa6eu: goto P_0c06aa6e;
case 0x0c06aa70u: goto P_0c06aa70;
case 0x0c06aa72u: goto P_0c06aa72;
case 0x0c06aa74u: goto P_0c06aa74;
case 0x0c06aa76u: goto P_0c06aa76;
case 0x0c06aa78u: goto P_0c06aa78;
case 0x0c06aa7au: goto P_0c06aa7a;
case 0x0c06aa7cu: goto P_0c06aa7c;
case 0x0c06aa7eu: goto P_0c06aa7e;
case 0x0c06aa80u: goto P_0c06aa80;
case 0x0c06aa82u: goto P_0c06aa82;
case 0x0c06aaccu: goto P_0c06aacc;
case 0x0c06aaceu: goto P_0c06aace;
case 0x0c06aad0u: goto P_0c06aad0;
case 0x0c06aad2u: goto P_0c06aad2;
case 0x0c06aad4u: goto P_0c06aad4;
case 0x0c06aad6u: goto P_0c06aad6;
case 0x0c06aad8u: goto P_0c06aad8;
case 0x0c06aadau: goto P_0c06aada;
case 0x0c06aadcu: goto P_0c06aadc;
case 0x0c06aadeu: goto P_0c06aade;
case 0x0c06aae0u: goto P_0c06aae0;
case 0x0c06aae2u: goto P_0c06aae2;
case 0x0c06aae4u: goto P_0c06aae4;
case 0x0c06aae6u: goto P_0c06aae6;
case 0x0c06aae8u: goto P_0c06aae8;
case 0x0c06aaeau: goto P_0c06aaea;
case 0x0c06aaecu: goto P_0c06aaec;
case 0x0c06aaeeu: goto P_0c06aaee;
case 0x0c06aaf0u: goto P_0c06aaf0;
case 0x0c06aaf2u: goto P_0c06aaf2;
case 0x0c06aaf4u: goto P_0c06aaf4;
case 0x0c06aaf6u: goto P_0c06aaf6;
case 0x0c06aaf8u: goto P_0c06aaf8;
case 0x0c06aafau: goto P_0c06aafa;
case 0x0c06aafcu: goto P_0c06aafc;
case 0x0c06aafeu: goto P_0c06aafe;
case 0x0c06ab00u: goto P_0c06ab00;
case 0x0c06ab02u: goto P_0c06ab02;
case 0x0c06ab04u: goto P_0c06ab04;
case 0x0c06ab06u: goto P_0c06ab06;
case 0x0c06ab08u: goto P_0c06ab08;
case 0x0c06ab0au: goto P_0c06ab0a;
case 0x0c06ab0cu: goto P_0c06ab0c;
case 0x0c06ab0eu: goto P_0c06ab0e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06a826: /* original 2fe6, guest PC 0x0c06a826 */
if(!s->budget--) { s->failed_pc=0x0c06a826u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a828;
P_0c06a828: /* original 2fd6, guest PC 0x0c06a828 */
if(!s->budget--) { s->failed_pc=0x0c06a828u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a82a;
P_0c06a82a: /* original 2fc6, guest PC 0x0c06a82a */
if(!s->budget--) { s->failed_pc=0x0c06a82au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a82c;
P_0c06a82c: /* original 2fb6, guest PC 0x0c06a82c */
if(!s->budget--) { s->failed_pc=0x0c06a82cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a82e;
P_0c06a82e: /* original 2fa6, guest PC 0x0c06a82e */
if(!s->budget--) { s->failed_pc=0x0c06a82eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a830;
P_0c06a830: /* original 2f96, guest PC 0x0c06a830 */
if(!s->budget--) { s->failed_pc=0x0c06a830u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a832;
P_0c06a832: /* original 2f86, guest PC 0x0c06a832 */
if(!s->budget--) { s->failed_pc=0x0c06a832u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a834;
P_0c06a834: /* original 4f22, guest PC 0x0c06a834 */
if(!s->budget--) { s->failed_pc=0x0c06a834u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06a836;
P_0c06a836: /* original 9475, guest PC 0x0c06a836 */
if(!s->budget--) { s->failed_pc=0x0c06a836u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a924u,2);
goto P_0c06a838;
P_0c06a838: /* original d342, guest PC 0x0c06a838 */
if(!s->budget--) { s->failed_pc=0x0c06a838u; return 0; }
r[3]=read(ram,0x0c06a944u,4);
goto P_0c06a83a;
P_0c06a83a: /* original d541, guest PC 0x0c06a83a */
if(!s->budget--) { s->failed_pc=0x0c06a83au; return 0; }
r[5]=read(ram,0x0c06a940u,4);
goto P_0c06a83c;
P_0c06a83c: /* original 7ff4, guest PC 0x0c06a83c */
if(!s->budget--) { s->failed_pc=0x0c06a83cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06a83e;
P_0c06a83e: /* original dd3f, guest PC 0x0c06a83e */
if(!s->budget--) { s->failed_pc=0x0c06a83eu; return 0; }
r[13]=read(ram,0x0c06a93cu,4);
goto P_0c06a840;
P_0c06a840: /* original 430b, guest PC 0x0c06a840 */
if(!s->budget--) { s->failed_pc=0x0c06a840u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a844u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a844u) { target=s->pc; goto dispatch; }
goto P_0c06a844;
P_0c06a842: /* original e601, guest PC 0x0c06a842 */
if(!s->budget--) { s->failed_pc=0x0c06a842u; return 0; }
r[6]=0x00000001u;
goto P_0c06a844;
P_0c06a844: /* original de40, guest PC 0x0c06a844 */
if(!s->budget--) { s->failed_pc=0x0c06a844u; return 0; }
r[14]=read(ram,0x0c06a948u,4);
goto P_0c06a846;
P_0c06a846: /* original 64d3, guest PC 0x0c06a846 */
if(!s->budget--) { s->failed_pc=0x0c06a846u; return 0; }
r[4]=r[13];
goto P_0c06a848;
P_0c06a848: /* original 4e0b, guest PC 0x0c06a848 */
if(!s->budget--) { s->failed_pc=0x0c06a848u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a84cu;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a84cu) { target=s->pc; goto dispatch; }
goto P_0c06a84c;
P_0c06a84a: /* original 7464, guest PC 0x0c06a84a */
if(!s->budget--) { s->failed_pc=0x0c06a84au; return 0; }
r[4]+=0x00000064u;
goto P_0c06a84c;
P_0c06a84c: /* original 64d3, guest PC 0x0c06a84c */
if(!s->budget--) { s->failed_pc=0x0c06a84cu; return 0; }
r[4]=r[13];
goto P_0c06a84e;
P_0c06a84e: /* original 1f01, guest PC 0x0c06a84e */
if(!s->budget--) { s->failed_pc=0x0c06a84eu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a850;
P_0c06a850: /* original 4e0b, guest PC 0x0c06a850 */
if(!s->budget--) { s->failed_pc=0x0c06a850u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a854u;
r[4]+=0x00000060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a854u) { target=s->pc; goto dispatch; }
goto P_0c06a854;
P_0c06a852: /* original 7460, guest PC 0x0c06a852 */
if(!s->budget--) { s->failed_pc=0x0c06a852u; return 0; }
r[4]+=0x00000060u;
goto P_0c06a854;
P_0c06a854: /* original 64d3, guest PC 0x0c06a854 */
if(!s->budget--) { s->failed_pc=0x0c06a854u; return 0; }
r[4]=r[13];
goto P_0c06a856;
P_0c06a856: /* original 2f02, guest PC 0x0c06a856 */
if(!s->budget--) { s->failed_pc=0x0c06a856u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a858;
P_0c06a858: /* original 4e0b, guest PC 0x0c06a858 */
if(!s->budget--) { s->failed_pc=0x0c06a858u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a85cu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a85cu) { target=s->pc; goto dispatch; }
goto P_0c06a85c;
P_0c06a85a: /* original 745c, guest PC 0x0c06a85a */
if(!s->budget--) { s->failed_pc=0x0c06a85au; return 0; }
r[4]+=0x0000005cu;
goto P_0c06a85c;
P_0c06a85c: /* original 64d3, guest PC 0x0c06a85c */
if(!s->budget--) { s->failed_pc=0x0c06a85cu; return 0; }
r[4]=r[13];
goto P_0c06a85e;
P_0c06a85e: /* original 1f02, guest PC 0x0c06a85e */
if(!s->budget--) { s->failed_pc=0x0c06a85eu; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c06a860;
P_0c06a860: /* original 4e0b, guest PC 0x0c06a860 */
if(!s->budget--) { s->failed_pc=0x0c06a860u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a864u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a864u) { target=s->pc; goto dispatch; }
goto P_0c06a864;
P_0c06a862: /* original 7458, guest PC 0x0c06a862 */
if(!s->budget--) { s->failed_pc=0x0c06a862u; return 0; }
r[4]+=0x00000058u;
goto P_0c06a864;
P_0c06a864: /* original 53f1, guest PC 0x0c06a864 */
if(!s->budget--) { s->failed_pc=0x0c06a864u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06a866;
P_0c06a866: /* original 6503, guest PC 0x0c06a866 */
if(!s->budget--) { s->failed_pc=0x0c06a866u; return 0; }
r[5]=r[0];
goto P_0c06a868;
P_0c06a868: /* original db38, guest PC 0x0c06a868 */
if(!s->budget--) { s->failed_pc=0x0c06a868u; return 0; }
r[11]=read(ram,0x0c06a94cu,4);
goto P_0c06a86a;
P_0c06a86a: /* original 2f36, guest PC 0x0c06a86a */
if(!s->budget--) { s->failed_pc=0x0c06a86au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a86c;
P_0c06a86c: /* original 52f1, guest PC 0x0c06a86c */
if(!s->budget--) { s->failed_pc=0x0c06a86cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06a86e;
P_0c06a86e: /* original 2f26, guest PC 0x0c06a86e */
if(!s->budget--) { s->failed_pc=0x0c06a86eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a870;
P_0c06a870: /* original 53f4, guest PC 0x0c06a870 */
if(!s->budget--) { s->failed_pc=0x0c06a870u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c06a872;
P_0c06a872: /* original 2f36, guest PC 0x0c06a872 */
if(!s->budget--) { s->failed_pc=0x0c06a872u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a874;
P_0c06a874: /* original 2f56, guest PC 0x0c06a874 */
if(!s->budget--) { s->failed_pc=0x0c06a874u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a876;
P_0c06a876: /* original 9456, guest PC 0x0c06a876 */
if(!s->budget--) { s->failed_pc=0x0c06a876u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a926u,2);
goto P_0c06a878;
P_0c06a878: /* original d335, guest PC 0x0c06a878 */
if(!s->budget--) { s->failed_pc=0x0c06a878u; return 0; }
r[3]=read(ram,0x0c06a950u,4);
goto P_0c06a87a;
P_0c06a87a: /* original 4b0b, guest PC 0x0c06a87a */
if(!s->budget--) { s->failed_pc=0x0c06a87au; return 0; }
target=r[11];
r[16]=code_base|0x0c06a87eu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a87eu) { target=s->pc; goto dispatch; }
goto P_0c06a87e;
P_0c06a87c: /* original 2f36, guest PC 0x0c06a87c */
if(!s->budget--) { s->failed_pc=0x0c06a87cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a87e;
P_0c06a87e: /* original 64d3, guest PC 0x0c06a87e */
if(!s->budget--) { s->failed_pc=0x0c06a87eu; return 0; }
r[4]=r[13];
goto P_0c06a880;
P_0c06a880: /* original 7f14, guest PC 0x0c06a880 */
if(!s->budget--) { s->failed_pc=0x0c06a880u; return 0; }
r[15]+=0x00000014u;
goto P_0c06a882;
P_0c06a882: /* original 4e0b, guest PC 0x0c06a882 */
if(!s->budget--) { s->failed_pc=0x0c06a882u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a886u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a886u) { target=s->pc; goto dispatch; }
goto P_0c06a886;
P_0c06a884: /* original 7468, guest PC 0x0c06a884 */
if(!s->budget--) { s->failed_pc=0x0c06a884u; return 0; }
r[4]+=0x00000068u;
goto P_0c06a886;
P_0c06a886: /* original 2f02, guest PC 0x0c06a886 */
if(!s->budget--) { s->failed_pc=0x0c06a886u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a888;
P_0c06a888: /* original 944e, guest PC 0x0c06a888 */
if(!s->budget--) { s->failed_pc=0x0c06a888u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a928u,2);
goto P_0c06a88a;
P_0c06a88a: /* original b247, guest PC 0x0c06a88a */
if(!s->budget--) { s->failed_pc=0x0c06a88au; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a88eu;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a88eu) { target=s->pc; goto dispatch; }
goto P_0c06a88e;
P_0c06a88c: /* original 6503, guest PC 0x0c06a88c */
if(!s->budget--) { s->failed_pc=0x0c06a88cu; return 0; }
r[5]=r[0];
goto P_0c06a88e;
P_0c06a88e: /* original 64d3, guest PC 0x0c06a88e */
if(!s->budget--) { s->failed_pc=0x0c06a88eu; return 0; }
r[4]=r[13];
goto P_0c06a890;
P_0c06a890: /* original 1f01, guest PC 0x0c06a890 */
if(!s->budget--) { s->failed_pc=0x0c06a890u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a892;
P_0c06a892: /* original 4e0b, guest PC 0x0c06a892 */
if(!s->budget--) { s->failed_pc=0x0c06a892u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a896u;
r[4]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a896u) { target=s->pc; goto dispatch; }
goto P_0c06a896;
P_0c06a894: /* original 7470, guest PC 0x0c06a894 */
if(!s->budget--) { s->failed_pc=0x0c06a894u; return 0; }
r[4]+=0x00000070u;
goto P_0c06a896;
P_0c06a896: /* original 6503, guest PC 0x0c06a896 */
if(!s->budget--) { s->failed_pc=0x0c06a896u; return 0; }
r[5]=r[0];
goto P_0c06a898;
P_0c06a898: /* original 2f02, guest PC 0x0c06a898 */
if(!s->budget--) { s->failed_pc=0x0c06a898u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a89a;
P_0c06a89a: /* original b23f, guest PC 0x0c06a89a */
if(!s->budget--) { s->failed_pc=0x0c06a89au; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a89eu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a89eu) { target=s->pc; goto dispatch; }
goto P_0c06a89e;
P_0c06a89c: /* original 54f1, guest PC 0x0c06a89c */
if(!s->budget--) { s->failed_pc=0x0c06a89cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06a89e;
P_0c06a89e: /* original 64d3, guest PC 0x0c06a89e */
if(!s->budget--) { s->failed_pc=0x0c06a89eu; return 0; }
r[4]=r[13];
goto P_0c06a8a0;
P_0c06a8a0: /* original 4e0b, guest PC 0x0c06a8a0 */
if(!s->budget--) { s->failed_pc=0x0c06a8a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a8a4u;
r[4]+=0x0000006cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a8a4u) { target=s->pc; goto dispatch; }
goto P_0c06a8a4;
P_0c06a8a2: /* original 746c, guest PC 0x0c06a8a2 */
if(!s->budget--) { s->failed_pc=0x0c06a8a2u; return 0; }
r[4]+=0x0000006cu;
goto P_0c06a8a4;
P_0c06a8a4: /* original 2f02, guest PC 0x0c06a8a4 */
if(!s->budget--) { s->failed_pc=0x0c06a8a4u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a8a6;
P_0c06a8a6: /* original 9440, guest PC 0x0c06a8a6 */
if(!s->budget--) { s->failed_pc=0x0c06a8a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a92au,2);
goto P_0c06a8a8;
P_0c06a8a8: /* original b238, guest PC 0x0c06a8a8 */
if(!s->budget--) { s->failed_pc=0x0c06a8a8u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a8acu;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a8acu) { target=s->pc; goto dispatch; }
goto P_0c06a8ac;
P_0c06a8aa: /* original 6503, guest PC 0x0c06a8aa */
if(!s->budget--) { s->failed_pc=0x0c06a8aau; return 0; }
r[5]=r[0];
goto P_0c06a8ac;
P_0c06a8ac: /* original 64d3, guest PC 0x0c06a8ac */
if(!s->budget--) { s->failed_pc=0x0c06a8acu; return 0; }
r[4]=r[13];
goto P_0c06a8ae;
P_0c06a8ae: /* original 2f02, guest PC 0x0c06a8ae */
if(!s->budget--) { s->failed_pc=0x0c06a8aeu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a8b0;
P_0c06a8b0: /* original 4e0b, guest PC 0x0c06a8b0 */
if(!s->budget--) { s->failed_pc=0x0c06a8b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a8b4u;
r[4]+=0x00000074u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a8b4u) { target=s->pc; goto dispatch; }
goto P_0c06a8b4;
P_0c06a8b2: /* original 7474, guest PC 0x0c06a8b2 */
if(!s->budget--) { s->failed_pc=0x0c06a8b2u; return 0; }
r[4]+=0x00000074u;
goto P_0c06a8b4;
P_0c06a8b4: /* original 6503, guest PC 0x0c06a8b4 */
if(!s->budget--) { s->failed_pc=0x0c06a8b4u; return 0; }
r[5]=r[0];
goto P_0c06a8b6;
P_0c06a8b6: /* original 1f01, guest PC 0x0c06a8b6 */
if(!s->budget--) { s->failed_pc=0x0c06a8b6u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a8b8;
P_0c06a8b8: /* original b230, guest PC 0x0c06a8b8 */
if(!s->budget--) { s->failed_pc=0x0c06a8b8u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a8bcu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a8bcu) { target=s->pc; goto dispatch; }
goto P_0c06a8bc;
P_0c06a8ba: /* original 64f2, guest PC 0x0c06a8ba */
if(!s->budget--) { s->failed_pc=0x0c06a8bau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a8bc;
P_0c06a8bc: /* original e400, guest PC 0x0c06a8bc */
if(!s->budget--) { s->failed_pc=0x0c06a8bcu; return 0; }
r[4]=0x00000000u;
goto P_0c06a8be;
P_0c06a8be: /* original 9a35, guest PC 0x0c06a8be */
if(!s->budget--) { s->failed_pc=0x0c06a8beu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a92cu,2);
goto P_0c06a8c0;
P_0c06a8c0: /* original 6c43, guest PC 0x0c06a8c0 */
if(!s->budget--) { s->failed_pc=0x0c06a8c0u; return 0; }
r[12]=r[4];
goto P_0c06a8c2;
P_0c06a8c2: /* original e815, guest PC 0x0c06a8c2 */
if(!s->budget--) { s->failed_pc=0x0c06a8c2u; return 0; }
r[8]=0x00000015u;
goto P_0c06a8c4;
P_0c06a8c4: /* original 6943, guest PC 0x0c06a8c4 */
if(!s->budget--) { s->failed_pc=0x0c06a8c4u; return 0; }
r[9]=r[4];
goto P_0c06a8c6;
P_0c06a8c6: /* original 9432, guest PC 0x0c06a8c6 */
if(!s->budget--) { s->failed_pc=0x0c06a8c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a92eu,2);
goto P_0c06a8c8;
P_0c06a8c8: /* original 34dc, guest PC 0x0c06a8c8 */
if(!s->budget--) { s->failed_pc=0x0c06a8c8u; return 0; }
r[4]+=r[13];
goto P_0c06a8ca;
P_0c06a8ca: /* original 4e0b, guest PC 0x0c06a8ca */
if(!s->budget--) { s->failed_pc=0x0c06a8cau; return 0; }
target=r[14];
r[16]=code_base|0x0c06a8ceu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a8ceu) { target=s->pc; goto dispatch; }
goto P_0c06a8ce;
P_0c06a8cc: /* original 34cc, guest PC 0x0c06a8cc */
if(!s->budget--) { s->failed_pc=0x0c06a8ccu; return 0; }
r[4]+=r[12];
goto P_0c06a8ce;
P_0c06a8ce: /* original 1f02, guest PC 0x0c06a8ce */
if(!s->budget--) { s->failed_pc=0x0c06a8ceu; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c06a8d0;
P_0c06a8d0: /* original 942e, guest PC 0x0c06a8d0 */
if(!s->budget--) { s->failed_pc=0x0c06a8d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a930u,2);
goto P_0c06a8d2;
P_0c06a8d2: /* original 34dc, guest PC 0x0c06a8d2 */
if(!s->budget--) { s->failed_pc=0x0c06a8d2u; return 0; }
r[4]+=r[13];
goto P_0c06a8d4;
P_0c06a8d4: /* original 4e0b, guest PC 0x0c06a8d4 */
if(!s->budget--) { s->failed_pc=0x0c06a8d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a8d8u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a8d8u) { target=s->pc; goto dispatch; }
goto P_0c06a8d8;
P_0c06a8d6: /* original 34cc, guest PC 0x0c06a8d6 */
if(!s->budget--) { s->failed_pc=0x0c06a8d6u; return 0; }
r[4]+=r[12];
goto P_0c06a8d8;
P_0c06a8d8: /* original 2f02, guest PC 0x0c06a8d8 */
if(!s->budget--) { s->failed_pc=0x0c06a8d8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a8da;
P_0c06a8da: /* original 942a, guest PC 0x0c06a8da */
if(!s->budget--) { s->failed_pc=0x0c06a8dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a932u,2);
goto P_0c06a8dc;
P_0c06a8dc: /* original 34dc, guest PC 0x0c06a8dc */
if(!s->budget--) { s->failed_pc=0x0c06a8dcu; return 0; }
r[4]+=r[13];
goto P_0c06a8de;
P_0c06a8de: /* original 4e0b, guest PC 0x0c06a8de */
if(!s->budget--) { s->failed_pc=0x0c06a8deu; return 0; }
target=r[14];
r[16]=code_base|0x0c06a8e2u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a8e2u) { target=s->pc; goto dispatch; }
goto P_0c06a8e2;
P_0c06a8e0: /* original 34cc, guest PC 0x0c06a8e0 */
if(!s->budget--) { s->failed_pc=0x0c06a8e0u; return 0; }
r[4]+=r[12];
goto P_0c06a8e2;
P_0c06a8e2: /* original 1f01, guest PC 0x0c06a8e2 */
if(!s->budget--) { s->failed_pc=0x0c06a8e2u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a8e4;
P_0c06a8e4: /* original 9426, guest PC 0x0c06a8e4 */
if(!s->budget--) { s->failed_pc=0x0c06a8e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a934u,2);
goto P_0c06a8e6;
P_0c06a8e6: /* original 34dc, guest PC 0x0c06a8e6 */
if(!s->budget--) { s->failed_pc=0x0c06a8e6u; return 0; }
r[4]+=r[13];
goto P_0c06a8e8;
P_0c06a8e8: /* original 4e0b, guest PC 0x0c06a8e8 */
if(!s->budget--) { s->failed_pc=0x0c06a8e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a8ecu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a8ecu) { target=s->pc; goto dispatch; }
goto P_0c06a8ec;
P_0c06a8ea: /* original 34cc, guest PC 0x0c06a8ea */
if(!s->budget--) { s->failed_pc=0x0c06a8eau; return 0; }
r[4]+=r[12];
goto P_0c06a8ec;
P_0c06a8ec: /* original 53f2, guest PC 0x0c06a8ec */
if(!s->budget--) { s->failed_pc=0x0c06a8ecu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06a8ee;
P_0c06a8ee: /* original 6503, guest PC 0x0c06a8ee */
if(!s->budget--) { s->failed_pc=0x0c06a8eeu; return 0; }
r[5]=r[0];
goto P_0c06a8f0;
P_0c06a8f0: /* original 2f36, guest PC 0x0c06a8f0 */
if(!s->budget--) { s->failed_pc=0x0c06a8f0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a8f2;
P_0c06a8f2: /* original 52f2, guest PC 0x0c06a8f2 */
if(!s->budget--) { s->failed_pc=0x0c06a8f2u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06a8f4;
P_0c06a8f4: /* original 2f26, guest PC 0x0c06a8f4 */
if(!s->budget--) { s->failed_pc=0x0c06a8f4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a8f6;
P_0c06a8f6: /* original 53f2, guest PC 0x0c06a8f6 */
if(!s->budget--) { s->failed_pc=0x0c06a8f6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06a8f8;
P_0c06a8f8: /* original 2f36, guest PC 0x0c06a8f8 */
if(!s->budget--) { s->failed_pc=0x0c06a8f8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a8fa;
P_0c06a8fa: /* original 2f56, guest PC 0x0c06a8fa */
if(!s->budget--) { s->failed_pc=0x0c06a8fau; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a8fc;
P_0c06a8fc: /* original d315, guest PC 0x0c06a8fc */
if(!s->budget--) { s->failed_pc=0x0c06a8fcu; return 0; }
r[3]=read(ram,0x0c06a954u,4);
goto P_0c06a8fe;
P_0c06a8fe: /* original 2f36, guest PC 0x0c06a8fe */
if(!s->budget--) { s->failed_pc=0x0c06a8feu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a900;
P_0c06a900: /* original 4b0b, guest PC 0x0c06a900 */
if(!s->budget--) { s->failed_pc=0x0c06a900u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a904u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a904u) { target=s->pc; goto dispatch; }
goto P_0c06a904;
P_0c06a902: /* original 64a3, guest PC 0x0c06a902 */
if(!s->budget--) { s->failed_pc=0x0c06a902u; return 0; }
r[4]=r[10];
goto P_0c06a904;
P_0c06a904: /* original 7901, guest PC 0x0c06a904 */
if(!s->budget--) { s->failed_pc=0x0c06a904u; return 0; }
r[9]+=0x00000001u;
goto P_0c06a906;
P_0c06a906: /* original 6a03, guest PC 0x0c06a906 */
if(!s->budget--) { s->failed_pc=0x0c06a906u; return 0; }
r[10]=r[0];
goto P_0c06a908;
P_0c06a908: /* original 3983, guest PC 0x0c06a908 */
if(!s->budget--) { s->failed_pc=0x0c06a908u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[8])!=0);
goto P_0c06a90a;
P_0c06a90a: /* original 7f14, guest PC 0x0c06a90a */
if(!s->budget--) { s->failed_pc=0x0c06a90au; return 0; }
r[15]+=0x00000014u;
goto P_0c06a90c;
P_0c06a90c: /* original 8fdb, guest PC 0x0c06a90c */
if(!s->budget--) { s->failed_pc=0x0c06a90cu; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c06a8c6; }
goto P_0c06a910;
P_0c06a90e: /* original 7c04, guest PC 0x0c06a90e */
if(!s->budget--) { s->failed_pc=0x0c06a90eu; return 0; }
r[12]+=0x00000004u;
goto P_0c06a910;
P_0c06a910: /* original 7f0c, guest PC 0x0c06a910 */
if(!s->budget--) { s->failed_pc=0x0c06a910u; return 0; }
r[15]+=0x0000000cu;
goto P_0c06a912;
P_0c06a912: /* original 4f26, guest PC 0x0c06a912 */
if(!s->budget--) { s->failed_pc=0x0c06a912u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06a914;
P_0c06a914: /* original 68f6, guest PC 0x0c06a914 */
if(!s->budget--) { s->failed_pc=0x0c06a914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06a916;
P_0c06a916: /* original 69f6, guest PC 0x0c06a916 */
if(!s->budget--) { s->failed_pc=0x0c06a916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06a918;
P_0c06a918: /* original 6af6, guest PC 0x0c06a918 */
if(!s->budget--) { s->failed_pc=0x0c06a918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06a91a;
P_0c06a91a: /* original 6bf6, guest PC 0x0c06a91a */
if(!s->budget--) { s->failed_pc=0x0c06a91au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06a91c;
P_0c06a91c: /* original 6cf6, guest PC 0x0c06a91c */
if(!s->budget--) { s->failed_pc=0x0c06a91cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06a91e;
P_0c06a91e: /* original 6df6, guest PC 0x0c06a91e */
if(!s->budget--) { s->failed_pc=0x0c06a91eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06a920;
P_0c06a920: /* original 000b, guest PC 0x0c06a920 */
if(!s->budget--) { s->failed_pc=0x0c06a920u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06a922: /* original 6ef6, guest PC 0x0c06a922 */
if(!s->budget--) { s->failed_pc=0x0c06a922u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06a924u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a924u; return 0; } return 1;
P_0c06a958: /* original 2fe6, guest PC 0x0c06a958 */
if(!s->budget--) { s->failed_pc=0x0c06a958u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a95a;
P_0c06a95a: /* original 2fd6, guest PC 0x0c06a95a */
if(!s->budget--) { s->failed_pc=0x0c06a95au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a95c;
P_0c06a95c: /* original 2fc6, guest PC 0x0c06a95c */
if(!s->budget--) { s->failed_pc=0x0c06a95cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a95e;
P_0c06a95e: /* original 2fb6, guest PC 0x0c06a95e */
if(!s->budget--) { s->failed_pc=0x0c06a95eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a960;
P_0c06a960: /* original 2fa6, guest PC 0x0c06a960 */
if(!s->budget--) { s->failed_pc=0x0c06a960u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a962;
P_0c06a962: /* original 2f96, guest PC 0x0c06a962 */
if(!s->budget--) { s->failed_pc=0x0c06a962u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a964;
P_0c06a964: /* original 2f86, guest PC 0x0c06a964 */
if(!s->budget--) { s->failed_pc=0x0c06a964u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a966;
P_0c06a966: /* original 4f22, guest PC 0x0c06a966 */
if(!s->budget--) { s->failed_pc=0x0c06a966u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06a968;
P_0c06a968: /* original 948c, guest PC 0x0c06a968 */
if(!s->budget--) { s->failed_pc=0x0c06a968u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa84u,2);
goto P_0c06a96a;
P_0c06a96a: /* original d351, guest PC 0x0c06a96a */
if(!s->budget--) { s->failed_pc=0x0c06a96au; return 0; }
r[3]=read(ram,0x0c06aab0u,4);
goto P_0c06a96c;
P_0c06a96c: /* original 4f12, guest PC 0x0c06a96c */
if(!s->budget--) { s->failed_pc=0x0c06a96cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06a96e;
P_0c06a96e: /* original d54f, guest PC 0x0c06a96e */
if(!s->budget--) { s->failed_pc=0x0c06a96eu; return 0; }
r[5]=read(ram,0x0c06aaacu,4);
goto P_0c06a970;
P_0c06a970: /* original dd4d, guest PC 0x0c06a970 */
if(!s->budget--) { s->failed_pc=0x0c06a970u; return 0; }
r[13]=read(ram,0x0c06aaa8u,4);
goto P_0c06a972;
P_0c06a972: /* original 7fe4, guest PC 0x0c06a972 */
if(!s->budget--) { s->failed_pc=0x0c06a972u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c06a974;
P_0c06a974: /* original 430b, guest PC 0x0c06a974 */
if(!s->budget--) { s->failed_pc=0x0c06a974u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a978u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a978u) { target=s->pc; goto dispatch; }
goto P_0c06a978;
P_0c06a976: /* original e601, guest PC 0x0c06a976 */
if(!s->budget--) { s->failed_pc=0x0c06a976u; return 0; }
r[6]=0x00000001u;
goto P_0c06a978;
P_0c06a978: /* original 9485, guest PC 0x0c06a978 */
if(!s->budget--) { s->failed_pc=0x0c06a978u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa86u,2);
goto P_0c06a97a;
P_0c06a97a: /* original de4e, guest PC 0x0c06a97a */
if(!s->budget--) { s->failed_pc=0x0c06a97au; return 0; }
r[14]=read(ram,0x0c06aab4u,4);
goto P_0c06a97c;
P_0c06a97c: /* original 4e0b, guest PC 0x0c06a97c */
if(!s->budget--) { s->failed_pc=0x0c06a97cu; return 0; }
target=r[14];
r[16]=code_base|0x0c06a980u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a980u) { target=s->pc; goto dispatch; }
goto P_0c06a980;
P_0c06a97e: /* original 34dc, guest PC 0x0c06a97e */
if(!s->budget--) { s->failed_pc=0x0c06a97eu; return 0; }
r[4]+=r[13];
goto P_0c06a980;
P_0c06a980: /* original 1f01, guest PC 0x0c06a980 */
if(!s->budget--) { s->failed_pc=0x0c06a980u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a982;
P_0c06a982: /* original 9481, guest PC 0x0c06a982 */
if(!s->budget--) { s->failed_pc=0x0c06a982u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa88u,2);
goto P_0c06a984;
P_0c06a984: /* original b174, guest PC 0x0c06a984 */
if(!s->budget--) { s->failed_pc=0x0c06a984u; return 0; }
target=code_base|0x0c06ac70u; r[16]=code_base|0x0c06a988u;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a988u) { target=s->pc; goto dispatch; }
goto P_0c06a988;
P_0c06a986: /* original 6503, guest PC 0x0c06a986 */
if(!s->budget--) { s->failed_pc=0x0c06a986u; return 0; }
r[5]=r[0];
goto P_0c06a988;
P_0c06a988: /* original 1f01, guest PC 0x0c06a988 */
if(!s->budget--) { s->failed_pc=0x0c06a988u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a98a;
P_0c06a98a: /* original e601, guest PC 0x0c06a98a */
if(!s->budget--) { s->failed_pc=0x0c06a98au; return 0; }
r[6]=0x00000001u;
goto P_0c06a98c;
P_0c06a98c: /* original d54a, guest PC 0x0c06a98c */
if(!s->budget--) { s->failed_pc=0x0c06a98cu; return 0; }
r[5]=read(ram,0x0c06aab8u,4);
goto P_0c06a98e;
P_0c06a98e: /* original d348, guest PC 0x0c06a98e */
if(!s->budget--) { s->failed_pc=0x0c06a98eu; return 0; }
r[3]=read(ram,0x0c06aab0u,4);
goto P_0c06a990;
P_0c06a990: /* original 430b, guest PC 0x0c06a990 */
if(!s->budget--) { s->failed_pc=0x0c06a990u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a994u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a994u) { target=s->pc; goto dispatch; }
goto P_0c06a994;
P_0c06a992: /* original 6403, guest PC 0x0c06a992 */
if(!s->budget--) { s->failed_pc=0x0c06a992u; return 0; }
r[4]=r[0];
goto P_0c06a994;
P_0c06a994: /* original 1f01, guest PC 0x0c06a994 */
if(!s->budget--) { s->failed_pc=0x0c06a994u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a996;
P_0c06a996: /* original 9478, guest PC 0x0c06a996 */
if(!s->budget--) { s->failed_pc=0x0c06a996u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa8au,2);
goto P_0c06a998;
P_0c06a998: /* original 4e0b, guest PC 0x0c06a998 */
if(!s->budget--) { s->failed_pc=0x0c06a998u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a99cu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a99cu) { target=s->pc; goto dispatch; }
goto P_0c06a99c;
P_0c06a99a: /* original 34dc, guest PC 0x0c06a99a */
if(!s->budget--) { s->failed_pc=0x0c06a99au; return 0; }
r[4]+=r[13];
goto P_0c06a99c;
P_0c06a99c: /* original 6503, guest PC 0x0c06a99c */
if(!s->budget--) { s->failed_pc=0x0c06a99cu; return 0; }
r[5]=r[0];
goto P_0c06a99e;
P_0c06a99e: /* original 2f02, guest PC 0x0c06a99e */
if(!s->budget--) { s->failed_pc=0x0c06a99eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a9a0;
P_0c06a9a0: /* original b1bc, guest PC 0x0c06a9a0 */
if(!s->budget--) { s->failed_pc=0x0c06a9a0u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a9a4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9a4u) { target=s->pc; goto dispatch; }
goto P_0c06a9a4;
P_0c06a9a2: /* original 54f1, guest PC 0x0c06a9a2 */
if(!s->budget--) { s->failed_pc=0x0c06a9a2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06a9a4;
P_0c06a9a4: /* original 1f01, guest PC 0x0c06a9a4 */
if(!s->budget--) { s->failed_pc=0x0c06a9a4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a9a6;
P_0c06a9a6: /* original 9471, guest PC 0x0c06a9a6 */
if(!s->budget--) { s->failed_pc=0x0c06a9a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa8cu,2);
goto P_0c06a9a8;
P_0c06a9a8: /* original 4e0b, guest PC 0x0c06a9a8 */
if(!s->budget--) { s->failed_pc=0x0c06a9a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9acu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9acu) { target=s->pc; goto dispatch; }
goto P_0c06a9ac;
P_0c06a9aa: /* original 34dc, guest PC 0x0c06a9aa */
if(!s->budget--) { s->failed_pc=0x0c06a9aau; return 0; }
r[4]+=r[13];
goto P_0c06a9ac;
P_0c06a9ac: /* original 6503, guest PC 0x0c06a9ac */
if(!s->budget--) { s->failed_pc=0x0c06a9acu; return 0; }
r[5]=r[0];
goto P_0c06a9ae;
P_0c06a9ae: /* original 2f02, guest PC 0x0c06a9ae */
if(!s->budget--) { s->failed_pc=0x0c06a9aeu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a9b0;
P_0c06a9b0: /* original b1b4, guest PC 0x0c06a9b0 */
if(!s->budget--) { s->failed_pc=0x0c06a9b0u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a9b4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9b4u) { target=s->pc; goto dispatch; }
goto P_0c06a9b4;
P_0c06a9b2: /* original 54f1, guest PC 0x0c06a9b2 */
if(!s->budget--) { s->failed_pc=0x0c06a9b2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06a9b4;
P_0c06a9b4: /* original 1f01, guest PC 0x0c06a9b4 */
if(!s->budget--) { s->failed_pc=0x0c06a9b4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a9b6;
P_0c06a9b6: /* original 946a, guest PC 0x0c06a9b6 */
if(!s->budget--) { s->failed_pc=0x0c06a9b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa8eu,2);
goto P_0c06a9b8;
P_0c06a9b8: /* original 4e0b, guest PC 0x0c06a9b8 */
if(!s->budget--) { s->failed_pc=0x0c06a9b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9bcu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9bcu) { target=s->pc; goto dispatch; }
goto P_0c06a9bc;
P_0c06a9ba: /* original 34dc, guest PC 0x0c06a9ba */
if(!s->budget--) { s->failed_pc=0x0c06a9bau; return 0; }
r[4]+=r[13];
goto P_0c06a9bc;
P_0c06a9bc: /* original 6503, guest PC 0x0c06a9bc */
if(!s->budget--) { s->failed_pc=0x0c06a9bcu; return 0; }
r[5]=r[0];
goto P_0c06a9be;
P_0c06a9be: /* original 2f02, guest PC 0x0c06a9be */
if(!s->budget--) { s->failed_pc=0x0c06a9beu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a9c0;
P_0c06a9c0: /* original b1ac, guest PC 0x0c06a9c0 */
if(!s->budget--) { s->failed_pc=0x0c06a9c0u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a9c4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9c4u) { target=s->pc; goto dispatch; }
goto P_0c06a9c4;
P_0c06a9c2: /* original 54f1, guest PC 0x0c06a9c2 */
if(!s->budget--) { s->failed_pc=0x0c06a9c2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06a9c4;
P_0c06a9c4: /* original 1f02, guest PC 0x0c06a9c4 */
if(!s->budget--) { s->failed_pc=0x0c06a9c4u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c06a9c6;
P_0c06a9c6: /* original 9463, guest PC 0x0c06a9c6 */
if(!s->budget--) { s->failed_pc=0x0c06a9c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa90u,2);
goto P_0c06a9c8;
P_0c06a9c8: /* original 4e0b, guest PC 0x0c06a9c8 */
if(!s->budget--) { s->failed_pc=0x0c06a9c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9ccu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9ccu) { target=s->pc; goto dispatch; }
goto P_0c06a9cc;
P_0c06a9ca: /* original 34dc, guest PC 0x0c06a9ca */
if(!s->budget--) { s->failed_pc=0x0c06a9cau; return 0; }
r[4]+=r[13];
goto P_0c06a9cc;
P_0c06a9cc: /* original 2f02, guest PC 0x0c06a9cc */
if(!s->budget--) { s->failed_pc=0x0c06a9ccu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a9ce;
P_0c06a9ce: /* original 9460, guest PC 0x0c06a9ce */
if(!s->budget--) { s->failed_pc=0x0c06a9ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa92u,2);
goto P_0c06a9d0;
P_0c06a9d0: /* original 4e0b, guest PC 0x0c06a9d0 */
if(!s->budget--) { s->failed_pc=0x0c06a9d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9d4u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9d4u) { target=s->pc; goto dispatch; }
goto P_0c06a9d4;
P_0c06a9d2: /* original 34dc, guest PC 0x0c06a9d2 */
if(!s->budget--) { s->failed_pc=0x0c06a9d2u; return 0; }
r[4]+=r[13];
goto P_0c06a9d4;
P_0c06a9d4: /* original 1f01, guest PC 0x0c06a9d4 */
if(!s->budget--) { s->failed_pc=0x0c06a9d4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a9d6;
P_0c06a9d6: /* original 945d, guest PC 0x0c06a9d6 */
if(!s->budget--) { s->failed_pc=0x0c06a9d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa94u,2);
goto P_0c06a9d8;
P_0c06a9d8: /* original 4e0b, guest PC 0x0c06a9d8 */
if(!s->budget--) { s->failed_pc=0x0c06a9d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9dcu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9dcu) { target=s->pc; goto dispatch; }
goto P_0c06a9dc;
P_0c06a9da: /* original 34dc, guest PC 0x0c06a9da */
if(!s->budget--) { s->failed_pc=0x0c06a9dau; return 0; }
r[4]+=r[13];
goto P_0c06a9dc;
P_0c06a9dc: /* original 1f04, guest PC 0x0c06a9dc */
if(!s->budget--) { s->failed_pc=0x0c06a9dcu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c06a9de;
P_0c06a9de: /* original 945a, guest PC 0x0c06a9de */
if(!s->budget--) { s->failed_pc=0x0c06a9deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa96u,2);
goto P_0c06a9e0;
P_0c06a9e0: /* original 4e0b, guest PC 0x0c06a9e0 */
if(!s->budget--) { s->failed_pc=0x0c06a9e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9e4u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9e4u) { target=s->pc; goto dispatch; }
goto P_0c06a9e4;
P_0c06a9e2: /* original 34dc, guest PC 0x0c06a9e2 */
if(!s->budget--) { s->failed_pc=0x0c06a9e2u; return 0; }
r[4]+=r[13];
goto P_0c06a9e4;
P_0c06a9e4: /* original 1f05, guest PC 0x0c06a9e4 */
if(!s->budget--) { s->failed_pc=0x0c06a9e4u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c06a9e6;
P_0c06a9e6: /* original 9457, guest PC 0x0c06a9e6 */
if(!s->budget--) { s->failed_pc=0x0c06a9e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa98u,2);
goto P_0c06a9e8;
P_0c06a9e8: /* original 4e0b, guest PC 0x0c06a9e8 */
if(!s->budget--) { s->failed_pc=0x0c06a9e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9ecu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9ecu) { target=s->pc; goto dispatch; }
goto P_0c06a9ec;
P_0c06a9ea: /* original 34dc, guest PC 0x0c06a9ea */
if(!s->budget--) { s->failed_pc=0x0c06a9eau; return 0; }
r[4]+=r[13];
goto P_0c06a9ec;
P_0c06a9ec: /* original 1f06, guest PC 0x0c06a9ec */
if(!s->budget--) { s->failed_pc=0x0c06a9ecu; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c06a9ee;
P_0c06a9ee: /* original 9454, guest PC 0x0c06a9ee */
if(!s->budget--) { s->failed_pc=0x0c06a9eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa9au,2);
goto P_0c06a9f0;
P_0c06a9f0: /* original 4e0b, guest PC 0x0c06a9f0 */
if(!s->budget--) { s->failed_pc=0x0c06a9f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9f4u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9f4u) { target=s->pc; goto dispatch; }
goto P_0c06a9f4;
P_0c06a9f2: /* original 34dc, guest PC 0x0c06a9f2 */
if(!s->budget--) { s->failed_pc=0x0c06a9f2u; return 0; }
r[4]+=r[13];
goto P_0c06a9f4;
P_0c06a9f4: /* original 1f03, guest PC 0x0c06a9f4 */
if(!s->budget--) { s->failed_pc=0x0c06a9f4u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c06a9f6;
P_0c06a9f6: /* original 9451, guest PC 0x0c06a9f6 */
if(!s->budget--) { s->failed_pc=0x0c06a9f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa9cu,2);
goto P_0c06a9f8;
P_0c06a9f8: /* original 4e0b, guest PC 0x0c06a9f8 */
if(!s->budget--) { s->failed_pc=0x0c06a9f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06a9fcu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a9fcu) { target=s->pc; goto dispatch; }
goto P_0c06a9fc;
P_0c06a9fa: /* original 34dc, guest PC 0x0c06a9fa */
if(!s->budget--) { s->failed_pc=0x0c06a9fau; return 0; }
r[4]+=r[13];
goto P_0c06a9fc;
P_0c06a9fc: /* original 63f2, guest PC 0x0c06a9fc */
if(!s->budget--) { s->failed_pc=0x0c06a9fcu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a9fe;
P_0c06a9fe: /* original 6503, guest PC 0x0c06a9fe */
if(!s->budget--) { s->failed_pc=0x0c06a9feu; return 0; }
r[5]=r[0];
goto P_0c06aa00;
P_0c06aa00: /* original db2e, guest PC 0x0c06aa00 */
if(!s->budget--) { s->failed_pc=0x0c06aa00u; return 0; }
r[11]=read(ram,0x0c06aabcu,4);
goto P_0c06aa02;
P_0c06aa02: /* original 2f36, guest PC 0x0c06aa02 */
if(!s->budget--) { s->failed_pc=0x0c06aa02u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa04;
P_0c06aa04: /* original 52f2, guest PC 0x0c06aa04 */
if(!s->budget--) { s->failed_pc=0x0c06aa04u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06aa06;
P_0c06aa06: /* original 2f26, guest PC 0x0c06aa06 */
if(!s->budget--) { s->failed_pc=0x0c06aa06u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa08;
P_0c06aa08: /* original 53f6, guest PC 0x0c06aa08 */
if(!s->budget--) { s->failed_pc=0x0c06aa08u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c06aa0a;
P_0c06aa0a: /* original 2f36, guest PC 0x0c06aa0a */
if(!s->budget--) { s->failed_pc=0x0c06aa0au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa0c;
P_0c06aa0c: /* original 52f8, guest PC 0x0c06aa0c */
if(!s->budget--) { s->failed_pc=0x0c06aa0cu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c06aa0e;
P_0c06aa0e: /* original 2f26, guest PC 0x0c06aa0e */
if(!s->budget--) { s->failed_pc=0x0c06aa0eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa10;
P_0c06aa10: /* original 53fa, guest PC 0x0c06aa10 */
if(!s->budget--) { s->failed_pc=0x0c06aa10u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c06aa12;
P_0c06aa12: /* original 2f36, guest PC 0x0c06aa12 */
if(!s->budget--) { s->failed_pc=0x0c06aa12u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa14;
P_0c06aa14: /* original 52f8, guest PC 0x0c06aa14 */
if(!s->budget--) { s->failed_pc=0x0c06aa14u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c06aa16;
P_0c06aa16: /* original 2f26, guest PC 0x0c06aa16 */
if(!s->budget--) { s->failed_pc=0x0c06aa16u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa18;
P_0c06aa18: /* original 2f56, guest PC 0x0c06aa18 */
if(!s->budget--) { s->failed_pc=0x0c06aa18u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa1a;
P_0c06aa1a: /* original d329, guest PC 0x0c06aa1a */
if(!s->budget--) { s->failed_pc=0x0c06aa1au; return 0; }
r[3]=read(ram,0x0c06aac0u,4);
goto P_0c06aa1c;
P_0c06aa1c: /* original 2f36, guest PC 0x0c06aa1c */
if(!s->budget--) { s->failed_pc=0x0c06aa1cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa1e;
P_0c06aa1e: /* original 4b0b, guest PC 0x0c06aa1e */
if(!s->budget--) { s->failed_pc=0x0c06aa1eu; return 0; }
target=r[11];
r[16]=code_base|0x0c06aa22u;
r[4]=read(ram,r[15]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aa22u) { target=s->pc; goto dispatch; }
goto P_0c06aa22;
P_0c06aa20: /* original 54fa, guest PC 0x0c06aa20 */
if(!s->budget--) { s->failed_pc=0x0c06aa20u; return 0; }
r[4]=read(ram,r[15]+40,4);
goto P_0c06aa22;
P_0c06aa22: /* original 7f20, guest PC 0x0c06aa22 */
if(!s->budget--) { s->failed_pc=0x0c06aa22u; return 0; }
r[15]+=0x00000020u;
goto P_0c06aa24;
P_0c06aa24: /* original e300, guest PC 0x0c06aa24 */
if(!s->budget--) { s->failed_pc=0x0c06aa24u; return 0; }
r[3]=0x00000000u;
goto P_0c06aa26;
P_0c06aa26: /* original e81e, guest PC 0x0c06aa26 */
if(!s->budget--) { s->failed_pc=0x0c06aa26u; return 0; }
r[8]=0x0000001eu;
goto P_0c06aa28;
P_0c06aa28: /* original 1f32, guest PC 0x0c06aa28 */
if(!s->budget--) { s->failed_pc=0x0c06aa28u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c06aa2a;
P_0c06aa2a: /* original 9938, guest PC 0x0c06aa2a */
if(!s->budget--) { s->failed_pc=0x0c06aa2au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aa9eu,2);
goto P_0c06aa2c;
P_0c06aa2c: /* original ec00, guest PC 0x0c06aa2c */
if(!s->budget--) { s->failed_pc=0x0c06aa2cu; return 0; }
r[12]=0x00000000u;
goto P_0c06aa2e;
P_0c06aa2e: /* original 39dc, guest PC 0x0c06aa2e */
if(!s->budget--) { s->failed_pc=0x0c06aa2eu; return 0; }
r[9]+=r[13];
goto P_0c06aa30;
P_0c06aa30: /* original 9436, guest PC 0x0c06aa30 */
if(!s->budget--) { s->failed_pc=0x0c06aa30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aaa0u,2);
goto P_0c06aa32;
P_0c06aa32: /* original 34dc, guest PC 0x0c06aa32 */
if(!s->budget--) { s->failed_pc=0x0c06aa32u; return 0; }
r[4]+=r[13];
goto P_0c06aa34;
P_0c06aa34: /* original 4e0b, guest PC 0x0c06aa34 */
if(!s->budget--) { s->failed_pc=0x0c06aa34u; return 0; }
target=r[14];
r[16]=code_base|0x0c06aa38u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aa38u) { target=s->pc; goto dispatch; }
goto P_0c06aa38;
P_0c06aa36: /* original 34cc, guest PC 0x0c06aa36 */
if(!s->budget--) { s->failed_pc=0x0c06aa36u; return 0; }
r[4]+=r[12];
goto P_0c06aa38;
P_0c06aa38: /* original 1f03, guest PC 0x0c06aa38 */
if(!s->budget--) { s->failed_pc=0x0c06aa38u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c06aa3a;
P_0c06aa3a: /* original 9432, guest PC 0x0c06aa3a */
if(!s->budget--) { s->failed_pc=0x0c06aa3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aaa2u,2);
goto P_0c06aa3c;
P_0c06aa3c: /* original 34dc, guest PC 0x0c06aa3c */
if(!s->budget--) { s->failed_pc=0x0c06aa3cu; return 0; }
r[4]+=r[13];
goto P_0c06aa3e;
P_0c06aa3e: /* original 4e0b, guest PC 0x0c06aa3e */
if(!s->budget--) { s->failed_pc=0x0c06aa3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06aa42u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aa42u) { target=s->pc; goto dispatch; }
goto P_0c06aa42;
P_0c06aa40: /* original 34cc, guest PC 0x0c06aa40 */
if(!s->budget--) { s->failed_pc=0x0c06aa40u; return 0; }
r[4]+=r[12];
goto P_0c06aa42;
P_0c06aa42: /* original 942f, guest PC 0x0c06aa42 */
if(!s->budget--) { s->failed_pc=0x0c06aa42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aaa4u,2);
goto P_0c06aa44;
P_0c06aa44: /* original 6a03, guest PC 0x0c06aa44 */
if(!s->budget--) { s->failed_pc=0x0c06aa44u; return 0; }
r[10]=r[0];
goto P_0c06aa46;
P_0c06aa46: /* original 34dc, guest PC 0x0c06aa46 */
if(!s->budget--) { s->failed_pc=0x0c06aa46u; return 0; }
r[4]+=r[13];
goto P_0c06aa48;
P_0c06aa48: /* original 4e0b, guest PC 0x0c06aa48 */
if(!s->budget--) { s->failed_pc=0x0c06aa48u; return 0; }
target=r[14];
r[16]=code_base|0x0c06aa4cu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aa4cu) { target=s->pc; goto dispatch; }
goto P_0c06aa4c;
P_0c06aa4a: /* original 34cc, guest PC 0x0c06aa4a */
if(!s->budget--) { s->failed_pc=0x0c06aa4au; return 0; }
r[4]+=r[12];
goto P_0c06aa4c;
P_0c06aa4c: /* original e307, guest PC 0x0c06aa4c */
if(!s->budget--) { s->failed_pc=0x0c06aa4cu; return 0; }
r[3]=0x00000007u;
goto P_0c06aa4e;
P_0c06aa4e: /* original 6483, guest PC 0x0c06aa4e */
if(!s->budget--) { s->failed_pc=0x0c06aa4eu; return 0; }
r[4]=r[8];
goto P_0c06aa50;
P_0c06aa50: /* original e20e, guest PC 0x0c06aa50 */
if(!s->budget--) { s->failed_pc=0x0c06aa50u; return 0; }
r[2]=0x0000000eu;
goto P_0c06aa52;
P_0c06aa52: /* original 6503, guest PC 0x0c06aa52 */
if(!s->budget--) { s->failed_pc=0x0c06aa52u; return 0; }
r[5]=r[0];
goto P_0c06aa54;
P_0c06aa54: /* original 443c, guest PC 0x0c06aa54 */
if(!s->budget--) { s->failed_pc=0x0c06aa54u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c06aa56;
P_0c06aa56: /* original 2558, guest PC 0x0c06aa56 */
if(!s->budget--) { s->failed_pc=0x0c06aa56u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06aa58;
P_0c06aa58: /* original 242b, guest PC 0x0c06aa58 */
if(!s->budget--) { s->failed_pc=0x0c06aa58u; return 0; }
r[4]|=r[2];
goto P_0c06aa5a;
P_0c06aa5a: /* original 8d37, guest PC 0x0c06aa5a */
if(!s->budget--) { s->failed_pc=0x0c06aa5au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[4],4);
if(cond) { goto P_0c06aacc; }
goto P_0c06aa5e;
P_0c06aa5c: /* original 2f42, guest PC 0x0c06aa5c */
if(!s->budget--) { s->failed_pc=0x0c06aa5cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06aa5e;
P_0c06aa5e: /* original e764, guest PC 0x0c06aa5e */
if(!s->budget--) { s->failed_pc=0x0c06aa5eu; return 0; }
r[7]=0x00000064u;
goto P_0c06aa60;
P_0c06aa60: /* original d318, guest PC 0x0c06aa60 */
if(!s->budget--) { s->failed_pc=0x0c06aa60u; return 0; }
r[3]=read(ram,0x0c06aac4u,4);
goto P_0c06aa62;
P_0c06aa62: /* original 0a77, guest PC 0x0c06aa62 */
if(!s->budget--) { s->failed_pc=0x0c06aa62u; return 0; }
r[19]=r[10]*r[7];
goto P_0c06aa64;
P_0c06aa64: /* original 071a, guest PC 0x0c06aa64 */
if(!s->budget--) { s->failed_pc=0x0c06aa64u; return 0; }
r[7]=r[19];
goto P_0c06aa66;
P_0c06aa66: /* original 6173, guest PC 0x0c06aa66 */
if(!s->budget--) { s->failed_pc=0x0c06aa66u; return 0; }
r[1]=r[7];
goto P_0c06aa68;
P_0c06aa68: /* original 430b, guest PC 0x0c06aa68 */
if(!s->budget--) { s->failed_pc=0x0c06aa68u; return 0; }
target=r[3];
r[16]=code_base|0x0c06aa6cu;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aa6cu) { target=s->pc; goto dispatch; }
goto P_0c06aa6c;
P_0c06aa6a: /* original 6053, guest PC 0x0c06aa6a */
if(!s->budget--) { s->failed_pc=0x0c06aa6au; return 0; }
r[0]=r[5];
goto P_0c06aa6c;
P_0c06aa6c: /* original 51f3, guest PC 0x0c06aa6c */
if(!s->budget--) { s->failed_pc=0x0c06aa6cu; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c06aa6e;
P_0c06aa6e: /* original 6703, guest PC 0x0c06aa6e */
if(!s->budget--) { s->failed_pc=0x0c06aa6eu; return 0; }
r[7]=r[0];
goto P_0c06aa70;
P_0c06aa70: /* original 2f16, guest PC 0x0c06aa70 */
if(!s->budget--) { s->failed_pc=0x0c06aa70u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa72;
P_0c06aa72: /* original 2f76, guest PC 0x0c06aa72 */
if(!s->budget--) { s->failed_pc=0x0c06aa72u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa74;
P_0c06aa74: /* original 2fa6, guest PC 0x0c06aa74 */
if(!s->budget--) { s->failed_pc=0x0c06aa74u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa76;
P_0c06aa76: /* original 2f56, guest PC 0x0c06aa76 */
if(!s->budget--) { s->failed_pc=0x0c06aa76u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa78;
P_0c06aa78: /* original d313, guest PC 0x0c06aa78 */
if(!s->budget--) { s->failed_pc=0x0c06aa78u; return 0; }
r[3]=read(ram,0x0c06aac8u,4);
goto P_0c06aa7a;
P_0c06aa7a: /* original 2f36, guest PC 0x0c06aa7a */
if(!s->budget--) { s->failed_pc=0x0c06aa7au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aa7c;
P_0c06aa7c: /* original 4b0b, guest PC 0x0c06aa7c */
if(!s->budget--) { s->failed_pc=0x0c06aa7cu; return 0; }
target=r[11];
r[16]=code_base|0x0c06aa80u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aa80u) { target=s->pc; goto dispatch; }
goto P_0c06aa80;
P_0c06aa7e: /* original 54f5, guest PC 0x0c06aa7e */
if(!s->budget--) { s->failed_pc=0x0c06aa7eu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c06aa80;
P_0c06aa80: /* original a02b, guest PC 0x0c06aa80 */
if(!s->budget--) { s->failed_pc=0x0c06aa80u; return 0; }
r[15]+=0x00000014u;
goto P_0c06aada;
P_0c06aa82: /* original 7f14, guest PC 0x0c06aa82 */
if(!s->budget--) { s->failed_pc=0x0c06aa82u; return 0; }
r[15]+=0x00000014u;
if(!vf3_matrix_family(0x0c06aa84u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06aa84u; return 0; } return 1;
P_0c06aacc: /* original 2fa6, guest PC 0x0c06aacc */
if(!s->budget--) { s->failed_pc=0x0c06aaccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aace;
P_0c06aace: /* original 2f56, guest PC 0x0c06aace */
if(!s->budget--) { s->failed_pc=0x0c06aaceu; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aad0;
P_0c06aad0: /* original d15d, guest PC 0x0c06aad0 */
if(!s->budget--) { s->failed_pc=0x0c06aad0u; return 0; }
r[1]=read(ram,0x0c06ac48u,4);
goto P_0c06aad2;
P_0c06aad2: /* original 2f16, guest PC 0x0c06aad2 */
if(!s->budget--) { s->failed_pc=0x0c06aad2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06aad4;
P_0c06aad4: /* original 4b0b, guest PC 0x0c06aad4 */
if(!s->budget--) { s->failed_pc=0x0c06aad4u; return 0; }
target=r[11];
r[16]=code_base|0x0c06aad8u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aad8u) { target=s->pc; goto dispatch; }
goto P_0c06aad8;
P_0c06aad6: /* original 54f3, guest PC 0x0c06aad6 */
if(!s->budget--) { s->failed_pc=0x0c06aad6u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c06aad8;
P_0c06aad8: /* original 7f0c, guest PC 0x0c06aad8 */
if(!s->budget--) { s->failed_pc=0x0c06aad8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c06aada;
P_0c06aada: /* original 1f01, guest PC 0x0c06aada */
if(!s->budget--) { s->failed_pc=0x0c06aadau; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06aadc;
P_0c06aadc: /* original 4e0b, guest PC 0x0c06aadc */
if(!s->budget--) { s->failed_pc=0x0c06aadcu; return 0; }
target=r[14];
r[16]=code_base|0x0c06aae0u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aae0u) { target=s->pc; goto dispatch; }
goto P_0c06aae0;
P_0c06aade: /* original 6493, guest PC 0x0c06aade */
if(!s->budget--) { s->failed_pc=0x0c06aadeu; return 0; }
r[4]=r[9];
goto P_0c06aae0;
P_0c06aae0: /* original 6503, guest PC 0x0c06aae0 */
if(!s->budget--) { s->failed_pc=0x0c06aae0u; return 0; }
r[5]=r[0];
goto P_0c06aae2;
P_0c06aae2: /* original 6a03, guest PC 0x0c06aae2 */
if(!s->budget--) { s->failed_pc=0x0c06aae2u; return 0; }
r[10]=r[0];
goto P_0c06aae4;
P_0c06aae4: /* original b11a, guest PC 0x0c06aae4 */
if(!s->budget--) { s->failed_pc=0x0c06aae4u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06aae8u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aae8u) { target=s->pc; goto dispatch; }
goto P_0c06aae8;
P_0c06aae6: /* original 54f1, guest PC 0x0c06aae6 */
if(!s->budget--) { s->failed_pc=0x0c06aae6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06aae8;
P_0c06aae8: /* original 52f2, guest PC 0x0c06aae8 */
if(!s->budget--) { s->failed_pc=0x0c06aae8u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06aaea;
P_0c06aaea: /* original e309, guest PC 0x0c06aaea */
if(!s->budget--) { s->failed_pc=0x0c06aaeau; return 0; }
r[3]=0x00000009u;
goto P_0c06aaec;
P_0c06aaec: /* original 7801, guest PC 0x0c06aaec */
if(!s->budget--) { s->failed_pc=0x0c06aaecu; return 0; }
r[8]+=0x00000001u;
goto P_0c06aaee;
P_0c06aaee: /* original 7201, guest PC 0x0c06aaee */
if(!s->budget--) { s->failed_pc=0x0c06aaeeu; return 0; }
r[2]+=0x00000001u;
goto P_0c06aaf0;
P_0c06aaf0: /* original 3233, guest PC 0x0c06aaf0 */
if(!s->budget--) { s->failed_pc=0x0c06aaf0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c06aaf2;
P_0c06aaf2: /* original 1f22, guest PC 0x0c06aaf2 */
if(!s->budget--) { s->failed_pc=0x0c06aaf2u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c06aaf4;
P_0c06aaf4: /* original 7904, guest PC 0x0c06aaf4 */
if(!s->budget--) { s->failed_pc=0x0c06aaf4u; return 0; }
r[9]+=0x00000004u;
goto P_0c06aaf6;
P_0c06aaf6: /* original 8f9b, guest PC 0x0c06aaf6 */
if(!s->budget--) { s->failed_pc=0x0c06aaf6u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c06aa30; }
goto P_0c06aafa;
P_0c06aaf8: /* original 7c04, guest PC 0x0c06aaf8 */
if(!s->budget--) { s->failed_pc=0x0c06aaf8u; return 0; }
r[12]+=0x00000004u;
goto P_0c06aafa;
P_0c06aafa: /* original 7f1c, guest PC 0x0c06aafa */
if(!s->budget--) { s->failed_pc=0x0c06aafau; return 0; }
r[15]+=0x0000001cu;
goto P_0c06aafc;
P_0c06aafc: /* original 4f16, guest PC 0x0c06aafc */
if(!s->budget--) { s->failed_pc=0x0c06aafcu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06aafe;
P_0c06aafe: /* original 4f26, guest PC 0x0c06aafe */
if(!s->budget--) { s->failed_pc=0x0c06aafeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ab00;
P_0c06ab00: /* original 68f6, guest PC 0x0c06ab00 */
if(!s->budget--) { s->failed_pc=0x0c06ab00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06ab02;
P_0c06ab02: /* original 69f6, guest PC 0x0c06ab02 */
if(!s->budget--) { s->failed_pc=0x0c06ab02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06ab04;
P_0c06ab04: /* original 6af6, guest PC 0x0c06ab04 */
if(!s->budget--) { s->failed_pc=0x0c06ab04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06ab06;
P_0c06ab06: /* original 6bf6, guest PC 0x0c06ab06 */
if(!s->budget--) { s->failed_pc=0x0c06ab06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06ab08;
P_0c06ab08: /* original 6cf6, guest PC 0x0c06ab08 */
if(!s->budget--) { s->failed_pc=0x0c06ab08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06ab0a;
P_0c06ab0a: /* original 6df6, guest PC 0x0c06ab0a */
if(!s->budget--) { s->failed_pc=0x0c06ab0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06ab0c;
P_0c06ab0c: /* original 000b, guest PC 0x0c06ab0c */
if(!s->budget--) { s->failed_pc=0x0c06ab0cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06ab0e: /* original 6ef6, guest PC 0x0c06ab0e */
if(!s->budget--) { s->failed_pc=0x0c06ab0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06ab10u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
