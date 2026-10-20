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
int vf3_0898_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c089764u: goto P_0c089764;
case 0x0c089766u: goto P_0c089766;
case 0x0c089768u: goto P_0c089768;
case 0x0c08976au: goto P_0c08976a;
case 0x0c0897ceu: goto P_0c0897ce;
case 0x0c0897d0u: goto P_0c0897d0;
case 0x0c0897d2u: goto P_0c0897d2;
case 0x0c0897d4u: goto P_0c0897d4;
case 0x0c0897d6u: goto P_0c0897d6;
case 0x0c0897d8u: goto P_0c0897d8;
case 0x0c0897dau: goto P_0c0897da;
case 0x0c0897dcu: goto P_0c0897dc;
case 0x0c0897deu: goto P_0c0897de;
case 0x0c0897e0u: goto P_0c0897e0;
case 0x0c0897e2u: goto P_0c0897e2;
case 0x0c0897e4u: goto P_0c0897e4;
case 0x0c0897e6u: goto P_0c0897e6;
case 0x0c0897e8u: goto P_0c0897e8;
case 0x0c0897eau: goto P_0c0897ea;
case 0x0c089864u: goto P_0c089864;
case 0x0c089866u: goto P_0c089866;
case 0x0c089868u: goto P_0c089868;
case 0x0c08986au: goto P_0c08986a;
case 0x0c08986cu: goto P_0c08986c;
case 0x0c08986eu: goto P_0c08986e;
case 0x0c089870u: goto P_0c089870;
case 0x0c089872u: goto P_0c089872;
case 0x0c089874u: goto P_0c089874;
case 0x0c089876u: goto P_0c089876;
case 0x0c089878u: goto P_0c089878;
case 0x0c08987au: goto P_0c08987a;
case 0x0c08987cu: goto P_0c08987c;
case 0x0c08987eu: goto P_0c08987e;
case 0x0c089880u: goto P_0c089880;
case 0x0c089882u: goto P_0c089882;
case 0x0c089884u: goto P_0c089884;
case 0x0c089886u: goto P_0c089886;
case 0x0c089888u: goto P_0c089888;
case 0x0c08988au: goto P_0c08988a;
case 0x0c08988cu: goto P_0c08988c;
case 0x0c08988eu: goto P_0c08988e;
case 0x0c089890u: goto P_0c089890;
case 0x0c089892u: goto P_0c089892;
case 0x0c089894u: goto P_0c089894;
case 0x0c089896u: goto P_0c089896;
case 0x0c0898c4u: goto P_0c0898c4;
case 0x0c0898c6u: goto P_0c0898c6;
case 0x0c0898c8u: goto P_0c0898c8;
case 0x0c0898cau: goto P_0c0898ca;
case 0x0c0898ccu: goto P_0c0898cc;
case 0x0c0898ceu: goto P_0c0898ce;
case 0x0c0898d0u: goto P_0c0898d0;
case 0x0c0898d2u: goto P_0c0898d2;
case 0x0c0898d4u: goto P_0c0898d4;
case 0x0c0898d6u: goto P_0c0898d6;
case 0x0c0898d8u: goto P_0c0898d8;
case 0x0c0898dau: goto P_0c0898da;
case 0x0c0898dcu: goto P_0c0898dc;
case 0x0c0898deu: goto P_0c0898de;
case 0x0c0898e0u: goto P_0c0898e0;
case 0x0c0898e2u: goto P_0c0898e2;
case 0x0c0898e4u: goto P_0c0898e4;
case 0x0c0898e6u: goto P_0c0898e6;
case 0x0c0898e8u: goto P_0c0898e8;
case 0x0c0898eau: goto P_0c0898ea;
case 0x0c0898ecu: goto P_0c0898ec;
case 0x0c0898eeu: goto P_0c0898ee;
case 0x0c0898f0u: goto P_0c0898f0;
case 0x0c0898f2u: goto P_0c0898f2;
case 0x0c0898f4u: goto P_0c0898f4;
case 0x0c0898f6u: goto P_0c0898f6;
case 0x0c0898f8u: goto P_0c0898f8;
case 0x0c0898fau: goto P_0c0898fa;
case 0x0c0898fcu: goto P_0c0898fc;
case 0x0c0898feu: goto P_0c0898fe;
case 0x0c089900u: goto P_0c089900;
case 0x0c089902u: goto P_0c089902;
case 0x0c089904u: goto P_0c089904;
case 0x0c089906u: goto P_0c089906;
case 0x0c089908u: goto P_0c089908;
case 0x0c08990au: goto P_0c08990a;
case 0x0c08990cu: goto P_0c08990c;
case 0x0c08990eu: goto P_0c08990e;
case 0x0c089910u: goto P_0c089910;
case 0x0c089912u: goto P_0c089912;
case 0x0c089914u: goto P_0c089914;
case 0x0c089916u: goto P_0c089916;
case 0x0c089918u: goto P_0c089918;
case 0x0c08991au: goto P_0c08991a;
case 0x0c08991cu: goto P_0c08991c;
case 0x0c08991eu: goto P_0c08991e;
case 0x0c089920u: goto P_0c089920;
case 0x0c089922u: goto P_0c089922;
case 0x0c089924u: goto P_0c089924;
case 0x0c089926u: goto P_0c089926;
case 0x0c089928u: goto P_0c089928;
case 0x0c08992au: goto P_0c08992a;
case 0x0c08992cu: goto P_0c08992c;
case 0x0c08992eu: goto P_0c08992e;
case 0x0c089930u: goto P_0c089930;
case 0x0c089932u: goto P_0c089932;
case 0x0c089934u: goto P_0c089934;
case 0x0c089936u: goto P_0c089936;
case 0x0c089938u: goto P_0c089938;
case 0x0c08993au: goto P_0c08993a;
case 0x0c08993cu: goto P_0c08993c;
case 0x0c08993eu: goto P_0c08993e;
case 0x0c089940u: goto P_0c089940;
case 0x0c089942u: goto P_0c089942;
case 0x0c089944u: goto P_0c089944;
case 0x0c089946u: goto P_0c089946;
case 0x0c089948u: goto P_0c089948;
case 0x0c08994au: goto P_0c08994a;
case 0x0c08994cu: goto P_0c08994c;
case 0x0c08994eu: goto P_0c08994e;
case 0x0c089950u: goto P_0c089950;
case 0x0c089952u: goto P_0c089952;
case 0x0c089954u: goto P_0c089954;
case 0x0c089956u: goto P_0c089956;
case 0x0c089958u: goto P_0c089958;
case 0x0c08995au: goto P_0c08995a;
case 0x0c08995cu: goto P_0c08995c;
case 0x0c08995eu: goto P_0c08995e;
case 0x0c089960u: goto P_0c089960;
case 0x0c089962u: goto P_0c089962;
case 0x0c089964u: goto P_0c089964;
case 0x0c089966u: goto P_0c089966;
case 0x0c089968u: goto P_0c089968;
case 0x0c08996au: goto P_0c08996a;
case 0x0c08996cu: goto P_0c08996c;
case 0x0c08996eu: goto P_0c08996e;
case 0x0c089970u: goto P_0c089970;
case 0x0c089972u: goto P_0c089972;
case 0x0c089974u: goto P_0c089974;
case 0x0c089976u: goto P_0c089976;
case 0x0c089978u: goto P_0c089978;
case 0x0c08997au: goto P_0c08997a;
case 0x0c08997cu: goto P_0c08997c;
case 0x0c08997eu: goto P_0c08997e;
case 0x0c089980u: goto P_0c089980;
case 0x0c089982u: goto P_0c089982;
case 0x0c089984u: goto P_0c089984;
case 0x0c089986u: goto P_0c089986;
case 0x0c089988u: goto P_0c089988;
case 0x0c08998au: goto P_0c08998a;
case 0x0c08998cu: goto P_0c08998c;
case 0x0c08998eu: goto P_0c08998e;
case 0x0c089990u: goto P_0c089990;
case 0x0c089992u: goto P_0c089992;
case 0x0c089994u: goto P_0c089994;
case 0x0c089996u: goto P_0c089996;
case 0x0c089998u: goto P_0c089998;
case 0x0c08999au: goto P_0c08999a;
case 0x0c08999cu: goto P_0c08999c;
case 0x0c08999eu: goto P_0c08999e;
case 0x0c0899a0u: goto P_0c0899a0;
case 0x0c0899a2u: goto P_0c0899a2;
case 0x0c0899a4u: goto P_0c0899a4;
case 0x0c0899a6u: goto P_0c0899a6;
case 0x0c0899a8u: goto P_0c0899a8;
case 0x0c0899aau: goto P_0c0899aa;
case 0x0c0899acu: goto P_0c0899ac;
case 0x0c0899aeu: goto P_0c0899ae;
case 0x0c0899b0u: goto P_0c0899b0;
case 0x0c0899b2u: goto P_0c0899b2;
case 0x0c0899b4u: goto P_0c0899b4;
case 0x0c0899b6u: goto P_0c0899b6;
case 0x0c0899b8u: goto P_0c0899b8;
case 0x0c0899bau: goto P_0c0899ba;
case 0x0c0899bcu: goto P_0c0899bc;
case 0x0c0899beu: goto P_0c0899be;
case 0x0c0899c0u: goto P_0c0899c0;
case 0x0c0899c2u: goto P_0c0899c2;
case 0x0c0899c4u: goto P_0c0899c4;
case 0x0c0899c6u: goto P_0c0899c6;
case 0x0c0899c8u: goto P_0c0899c8;
case 0x0c0899cau: goto P_0c0899ca;
case 0x0c0899ccu: goto P_0c0899cc;
case 0x0c0899ceu: goto P_0c0899ce;
case 0x0c0899d0u: goto P_0c0899d0;
case 0x0c0899d2u: goto P_0c0899d2;
case 0x0c0899d4u: goto P_0c0899d4;
case 0x0c0899d6u: goto P_0c0899d6;
case 0x0c0899d8u: goto P_0c0899d8;
case 0x0c0899dau: goto P_0c0899da;
case 0x0c0899dcu: goto P_0c0899dc;
case 0x0c0899deu: goto P_0c0899de;
case 0x0c0899e0u: goto P_0c0899e0;
case 0x0c0899e2u: goto P_0c0899e2;
case 0x0c0899e4u: goto P_0c0899e4;
case 0x0c0899e6u: goto P_0c0899e6;
case 0x0c0899e8u: goto P_0c0899e8;
case 0x0c0899eau: goto P_0c0899ea;
case 0x0c0899ecu: goto P_0c0899ec;
case 0x0c0899eeu: goto P_0c0899ee;
case 0x0c0899f0u: goto P_0c0899f0;
case 0x0c0899f2u: goto P_0c0899f2;
case 0x0c0899f4u: goto P_0c0899f4;
case 0x0c0899f6u: goto P_0c0899f6;
case 0x0c0899f8u: goto P_0c0899f8;
case 0x0c0899fau: goto P_0c0899fa;
case 0x0c0899fcu: goto P_0c0899fc;
case 0x0c0899feu: goto P_0c0899fe;
case 0x0c089a00u: goto P_0c089a00;
case 0x0c089a02u: goto P_0c089a02;
case 0x0c089a04u: goto P_0c089a04;
case 0x0c089a06u: goto P_0c089a06;
case 0x0c089a08u: goto P_0c089a08;
case 0x0c089a0au: goto P_0c089a0a;
case 0x0c089a0cu: goto P_0c089a0c;
case 0x0c089a0eu: goto P_0c089a0e;
case 0x0c089a10u: goto P_0c089a10;
case 0x0c089a12u: goto P_0c089a12;
case 0x0c089a14u: goto P_0c089a14;
case 0x0c089a16u: goto P_0c089a16;
case 0x0c089a18u: goto P_0c089a18;
case 0x0c089a1au: goto P_0c089a1a;
case 0x0c089a1cu: goto P_0c089a1c;
case 0x0c089a1eu: goto P_0c089a1e;
case 0x0c089a20u: goto P_0c089a20;
case 0x0c089a22u: goto P_0c089a22;
case 0x0c089a3cu: goto P_0c089a3c;
case 0x0c089a3eu: goto P_0c089a3e;
case 0x0c089a40u: goto P_0c089a40;
case 0x0c089a42u: goto P_0c089a42;
case 0x0c089a44u: goto P_0c089a44;
case 0x0c089a46u: goto P_0c089a46;
case 0x0c089a48u: goto P_0c089a48;
case 0x0c089a4au: goto P_0c089a4a;
case 0x0c089a4cu: goto P_0c089a4c;
case 0x0c089a4eu: goto P_0c089a4e;
case 0x0c089a50u: goto P_0c089a50;
case 0x0c089a52u: goto P_0c089a52;
case 0x0c089a54u: goto P_0c089a54;
case 0x0c089a56u: goto P_0c089a56;
case 0x0c089a58u: goto P_0c089a58;
case 0x0c089a5au: goto P_0c089a5a;
case 0x0c089a5cu: goto P_0c089a5c;
case 0x0c089a5eu: goto P_0c089a5e;
case 0x0c089a60u: goto P_0c089a60;
case 0x0c089a62u: goto P_0c089a62;
case 0x0c089a64u: goto P_0c089a64;
case 0x0c089a66u: goto P_0c089a66;
case 0x0c089a68u: goto P_0c089a68;
case 0x0c089a6au: goto P_0c089a6a;
case 0x0c089a6cu: goto P_0c089a6c;
case 0x0c089a6eu: goto P_0c089a6e;
case 0x0c089a70u: goto P_0c089a70;
case 0x0c089a72u: goto P_0c089a72;
case 0x0c089a74u: goto P_0c089a74;
case 0x0c089a76u: goto P_0c089a76;
case 0x0c089a78u: goto P_0c089a78;
case 0x0c089a7au: goto P_0c089a7a;
case 0x0c089a7cu: goto P_0c089a7c;
case 0x0c089a7eu: goto P_0c089a7e;
case 0x0c089a80u: goto P_0c089a80;
case 0x0c089a82u: goto P_0c089a82;
case 0x0c089a84u: goto P_0c089a84;
case 0x0c089a86u: goto P_0c089a86;
case 0x0c089a88u: goto P_0c089a88;
case 0x0c089a8au: goto P_0c089a8a;
case 0x0c089a8cu: goto P_0c089a8c;
case 0x0c089a8eu: goto P_0c089a8e;
case 0x0c089a90u: goto P_0c089a90;
case 0x0c089a92u: goto P_0c089a92;
case 0x0c089a94u: goto P_0c089a94;
case 0x0c089a96u: goto P_0c089a96;
case 0x0c089a98u: goto P_0c089a98;
case 0x0c089a9au: goto P_0c089a9a;
case 0x0c089a9cu: goto P_0c089a9c;
case 0x0c089a9eu: goto P_0c089a9e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c089764: /* original f571, guest PC 0x0c089764 */
if(!s->budget--) { s->failed_pc=0x0c089764u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c089766;
P_0c089766: /* original 2fe6, guest PC 0x0c089766 */
if(!s->budget--) { s->failed_pc=0x0c089766u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089768;
P_0c089768: /* original f461, guest PC 0x0c089768 */
if(!s->budget--) { s->failed_pc=0x0c089768u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c08976a;
P_0c08976a: /* original 6e53, guest PC 0x0c08976a */
if(!s->budget--) { s->failed_pc=0x0c08976au; return 0; }
r[14]=r[5];
return vf3_matrix_family(0x0c08976cu,s,ram);
P_0c0897ce: /* original c738, guest PC 0x0c0897ce */
if(!s->budget--) { s->failed_pc=0x0c0897ceu; return 0; }
r[0]=0x0c0898b0u;
goto P_0c0897d0;
P_0c0897d0: /* original 2fe6, guest PC 0x0c0897d0 */
if(!s->budget--) { s->failed_pc=0x0c0897d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d2;
P_0c0897d2: /* original 2fd6, guest PC 0x0c0897d2 */
if(!s->budget--) { s->failed_pc=0x0c0897d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d4;
P_0c0897d4: /* original ed00, guest PC 0x0c0897d4 */
if(!s->budget--) { s->failed_pc=0x0c0897d4u; return 0; }
r[13]=0x00000000u;
goto P_0c0897d6;
P_0c0897d6: /* original 2fc6, guest PC 0x0c0897d6 */
if(!s->budget--) { s->failed_pc=0x0c0897d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d8;
P_0c0897d8: /* original 6e43, guest PC 0x0c0897d8 */
if(!s->budget--) { s->failed_pc=0x0c0897d8u; return 0; }
r[14]=r[4];
goto P_0c0897da;
P_0c0897da: /* original 2fb6, guest PC 0x0c0897da */
if(!s->budget--) { s->failed_pc=0x0c0897dau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897dc;
P_0c0897dc: /* original eb20, guest PC 0x0c0897dc */
if(!s->budget--) { s->failed_pc=0x0c0897dcu; return 0; }
r[11]=0x00000020u;
goto P_0c0897de;
P_0c0897de: /* original 2fa6, guest PC 0x0c0897de */
if(!s->budget--) { s->failed_pc=0x0c0897deu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897e0;
P_0c0897e0: /* original ea7f, guest PC 0x0c0897e0 */
if(!s->budget--) { s->failed_pc=0x0c0897e0u; return 0; }
r[10]=0x0000007fu;
goto P_0c0897e2;
P_0c0897e2: /* original 2f96, guest PC 0x0c0897e2 */
if(!s->budget--) { s->failed_pc=0x0c0897e2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897e4;
P_0c0897e4: /* original 7e18, guest PC 0x0c0897e4 */
if(!s->budget--) { s->failed_pc=0x0c0897e4u; return 0; }
r[14]+=0x00000018u;
goto P_0c0897e6;
P_0c0897e6: /* original fffb, guest PC 0x0c0897e6 */
if(!s->budget--) { s->failed_pc=0x0c0897e6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0897e8;
P_0c0897e8: /* original f308, guest PC 0x0c0897e8 */
if(!s->budget--) { s->failed_pc=0x0c0897e8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0897ea;
P_0c0897ea: /* original e010, guest PC 0x0c0897ea */
if(!s->budget--) { s->failed_pc=0x0c0897eau; return 0; }
r[0]=0x00000010u;
return vf3_matrix_family(0x0c0897ecu,s,ram);
P_0c089864: /* original 4f22, guest PC 0x0c089864 */
if(!s->budget--) { s->failed_pc=0x0c089864u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089866;
P_0c089866: /* original d314, guest PC 0x0c089866 */
if(!s->budget--) { s->failed_pc=0x0c089866u; return 0; }
r[3]=read(ram,0x0c0898b8u,4);
goto P_0c089868;
P_0c089868: /* original 6212, guest PC 0x0c089868 */
if(!s->budget--) { s->failed_pc=0x0c089868u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08986a;
P_0c08986a: /* original 7fec, guest PC 0x0c08986a */
if(!s->budget--) { s->failed_pc=0x0c08986au; return 0; }
r[15]+=0xffffffecu;
goto P_0c08986c;
P_0c08986c: /* original 2238, guest PC 0x0c08986c */
if(!s->budget--) { s->failed_pc=0x0c08986cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08986e;
P_0c08986e: /* original 8901, guest PC 0x0c08986e */
if(!s->budget--) { s->failed_pc=0x0c08986eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089874; }
goto P_0c089870;
P_0c089870: /* original a108, guest PC 0x0c089870 */
if(!s->budget--) { s->failed_pc=0x0c089870u; return 0; }
goto P_0c089a84;
P_0c089872: /* original 0009, guest PC 0x0c089872 */
if(!s->budget--) { s->failed_pc=0x0c089872u; return 0; }
goto P_0c089874;
P_0c089874: /* original d912, guest PC 0x0c089874 */
if(!s->budget--) { s->failed_pc=0x0c089874u; return 0; }
r[9]=read(ram,0x0c0898c0u,4);
goto P_0c089876;
P_0c089876: /* original 6e43, guest PC 0x0c089876 */
if(!s->budget--) { s->failed_pc=0x0c089876u; return 0; }
r[14]=r[4];
goto P_0c089878;
P_0c089878: /* original 900e, guest PC 0x0c089878 */
if(!s->budget--) { s->failed_pc=0x0c089878u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089898u,2);
goto P_0c08987a;
P_0c08987a: /* original 6c43, guest PC 0x0c08987a */
if(!s->budget--) { s->failed_pc=0x0c08987au; return 0; }
r[12]=r[4];
goto P_0c08987c;
P_0c08987c: /* original 5898, guest PC 0x0c08987c */
if(!s->budget--) { s->failed_pc=0x0c08987cu; return 0; }
r[8]=read(ram,r[9]+32,4);
goto P_0c08987e;
P_0c08987e: /* original 008c, guest PC 0x0c08987e */
if(!s->budget--) { s->failed_pc=0x0c08987eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c089880;
P_0c089880: /* original 8802, guest PC 0x0c089880 */
if(!s->budget--) { s->failed_pc=0x0c089880u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c089882;
P_0c089882: /* original 8f02, guest PC 0x0c089882 */
if(!s->budget--) { s->failed_pc=0x0c089882u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c08988a; }
goto P_0c089886;
P_0c089884: /* original 7e18, guest PC 0x0c089884 */
if(!s->budget--) { s->failed_pc=0x0c089884u; return 0; }
r[14]+=0x00000018u;
goto P_0c089886;
P_0c089886: /* original bfa2, guest PC 0x0c089886 */
if(!s->budget--) { s->failed_pc=0x0c089886u; return 0; }
target=0x0c0897ceu; r[16]=code_base|0x0c08988au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08988au) { target=s->pc; goto dispatch; }
goto P_0c08988a;
P_0c089888: /* original 0009, guest PC 0x0c089888 */
if(!s->budget--) { s->failed_pc=0x0c089888u; return 0; }
goto P_0c08988a;
P_0c08988a: /* original e010, guest PC 0x0c08988a */
if(!s->budget--) { s->failed_pc=0x0c08988au; return 0; }
r[0]=0x00000010u;
goto P_0c08988c;
P_0c08988c: /* original fdc6, guest PC 0x0c08988c */
if(!s->budget--) { s->failed_pc=0x0c08988cu; return 0; }
vf3_matrix_load(s,ram,13,r[12]+r[0]);
goto P_0c08988e;
P_0c08988e: /* original ed00, guest PC 0x0c08988e */
if(!s->budget--) { s->failed_pc=0x0c08988eu; return 0; }
r[13]=0x00000000u;
goto P_0c089890;
P_0c089890: /* original 85ca, guest PC 0x0c089890 */
if(!s->budget--) { s->failed_pc=0x0c089890u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+20,2);
goto P_0c089892;
P_0c089892: /* original 6a03, guest PC 0x0c089892 */
if(!s->budget--) { s->failed_pc=0x0c089892u; return 0; }
r[10]=r[0];
goto P_0c089894;
P_0c089894: /* original a0ee, guest PC 0x0c089894 */
if(!s->budget--) { s->failed_pc=0x0c089894u; return 0; }
write(ram,r[15]+16,r[13],4);
goto P_0c089a74;
P_0c089896: /* original 1fd4, guest PC 0x0c089896 */
if(!s->budget--) { s->failed_pc=0x0c089896u; return 0; }
write(ram,r[15]+16,r[13],4);
return vf3_matrix_family(0x0c089898u,s,ram);
P_0c0898c4: /* original e00c, guest PC 0x0c0898c4 */
if(!s->budget--) { s->failed_pc=0x0c0898c4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0898c6;
P_0c0898c6: /* original 64e1, guest PC 0x0c0898c6 */
if(!s->budget--) { s->failed_pc=0x0c0898c6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c0898c8;
P_0c0898c8: /* original ffe6, guest PC 0x0c0898c8 */
if(!s->budget--) { s->failed_pc=0x0c0898c8u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0898ca;
P_0c0898ca: /* original e010, guest PC 0x0c0898ca */
if(!s->budget--) { s->failed_pc=0x0c0898cau; return 0; }
r[0]=0x00000010u;
goto P_0c0898cc;
P_0c0898cc: /* original fce6, guest PC 0x0c0898cc */
if(!s->budget--) { s->failed_pc=0x0c0898ccu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0898ce;
P_0c0898ce: /* original e014, guest PC 0x0c0898ce */
if(!s->budget--) { s->failed_pc=0x0c0898ceu; return 0; }
r[0]=0x00000014u;
goto P_0c0898d0;
P_0c0898d0: /* original fee6, guest PC 0x0c0898d0 */
if(!s->budget--) { s->failed_pc=0x0c0898d0u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0898d2;
P_0c0898d2: /* original e57f, guest PC 0x0c0898d2 */
if(!s->budget--) { s->failed_pc=0x0c0898d2u; return 0; }
r[5]=0x0000007fu;
goto P_0c0898d4;
P_0c0898d4: /* original 7401, guest PC 0x0c0898d4 */
if(!s->budget--) { s->failed_pc=0x0c0898d4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0898d6;
P_0c0898d6: /* original 2459, guest PC 0x0c0898d6 */
if(!s->budget--) { s->failed_pc=0x0c0898d6u; return 0; }
r[4]&=r[5];
goto P_0c0898d8;
P_0c0898d8: /* original 2e41, guest PC 0x0c0898d8 */
if(!s->budget--) { s->failed_pc=0x0c0898d8u; return 0; }
write(ram,r[14],r[4],2);
goto P_0c0898da;
P_0c0898da: /* original 84eb, guest PC 0x0c0898da */
if(!s->budget--) { s->failed_pc=0x0c0898dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c0898dc;
P_0c0898dc: /* original 80f8, guest PC 0x0c0898dc */
if(!s->budget--) { s->failed_pc=0x0c0898dcu; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0898de;
P_0c0898de: /* original 84f8, guest PC 0x0c0898de */
if(!s->budget--) { s->failed_pc=0x0c0898deu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c0898e0;
P_0c0898e0: /* original 9ba0, guest PC 0x0c0898e0 */
if(!s->budget--) { s->failed_pc=0x0c0898e0u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089a24u,2);
goto P_0c0898e2;
P_0c0898e2: /* original 8801, guest PC 0x0c0898e2 */
if(!s->budget--) { s->failed_pc=0x0c0898e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0898e4;
P_0c0898e4: /* original 8d5b, guest PC 0x0c0898e4 */
if(!s->budget--) { s->failed_pc=0x0c0898e4u; return 0; }
cond=r[17]&1u;
fr[14]^=0x80000000u;
if(cond) { goto P_0c08999e; }
goto P_0c0898e8;
P_0c0898e6: /* original fe4d, guest PC 0x0c0898e6 */
if(!s->budget--) { s->failed_pc=0x0c0898e6u; return 0; }
fr[14]^=0x80000000u;
goto P_0c0898e8;
P_0c0898e8: /* original 5294, guest PC 0x0c0898e8 */
if(!s->budget--) { s->failed_pc=0x0c0898e8u; return 0; }
r[2]=read(ram,r[9]+16,4);
goto P_0c0898ea;
P_0c0898ea: /* original 66f3, guest PC 0x0c0898ea */
if(!s->budget--) { s->failed_pc=0x0c0898eau; return 0; }
r[6]=r[15];
goto P_0c0898ec;
P_0c0898ec: /* original 65e3, guest PC 0x0c0898ec */
if(!s->budget--) { s->failed_pc=0x0c0898ecu; return 0; }
r[5]=r[14];
goto P_0c0898ee;
P_0c0898ee: /* original 7608, guest PC 0x0c0898ee */
if(!s->budget--) { s->failed_pc=0x0c0898eeu; return 0; }
r[6]+=0x00000008u;
goto P_0c0898f0;
P_0c0898f0: /* original 6323, guest PC 0x0c0898f0 */
if(!s->budget--) { s->failed_pc=0x0c0898f0u; return 0; }
r[3]=r[2];
goto P_0c0898f2;
P_0c0898f2: /* original 1f23, guest PC 0x0c0898f2 */
if(!s->budget--) { s->failed_pc=0x0c0898f2u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0898f4;
P_0c0898f4: /* original 9097, guest PC 0x0c0898f4 */
if(!s->budget--) { s->failed_pc=0x0c0898f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089a26u,2);
goto P_0c0898f6;
P_0c0898f6: /* original f8dc, guest PC 0x0c0898f6 */
if(!s->budget--) { s->failed_pc=0x0c0898f6u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c0898f8;
P_0c0898f8: /* original f536, guest PC 0x0c0898f8 */
if(!s->budget--) { s->failed_pc=0x0c0898f8u; return 0; }
vf3_matrix_load(s,ram,5,r[3]+r[0]);
goto P_0c0898fa;
P_0c0898fa: /* original 70f8, guest PC 0x0c0898fa */
if(!s->budget--) { s->failed_pc=0x0c0898fau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0898fc;
P_0c0898fc: /* original f436, guest PC 0x0c0898fc */
if(!s->budget--) { s->failed_pc=0x0c0898fcu; return 0; }
vf3_matrix_load(s,ram,4,r[3]+r[0]);
goto P_0c0898fe;
P_0c0898fe: /* original f54d, guest PC 0x0c0898fe */
if(!s->budget--) { s->failed_pc=0x0c0898feu; return 0; }
fr[5]^=0x80000000u;
goto P_0c089900;
P_0c089900: /* original f6fc, guest PC 0x0c089900 */
if(!s->budget--) { s->failed_pc=0x0c089900u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c089902;
P_0c089902: /* original f7ec, guest PC 0x0c089902 */
if(!s->budget--) { s->failed_pc=0x0c089902u; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c089904;
P_0c089904: /* original bf2e, guest PC 0x0c089904 */
if(!s->budget--) { s->failed_pc=0x0c089904u; return 0; }
target=0x0c089764u; r[16]=code_base|0x0c089908u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089908u) { target=s->pc; goto dispatch; }
goto P_0c089908;
P_0c089906: /* original 64c3, guest PC 0x0c089906 */
if(!s->budget--) { s->failed_pc=0x0c089906u; return 0; }
r[4]=r[12];
goto P_0c089908;
P_0c089908: /* original 5295, guest PC 0x0c089908 */
if(!s->budget--) { s->failed_pc=0x0c089908u; return 0; }
r[2]=read(ram,r[9]+20,4);
goto P_0c08990a;
P_0c08990a: /* original 66f3, guest PC 0x0c08990a */
if(!s->budget--) { s->failed_pc=0x0c08990au; return 0; }
r[6]=r[15];
goto P_0c08990c;
P_0c08990c: /* original 65e3, guest PC 0x0c08990c */
if(!s->budget--) { s->failed_pc=0x0c08990cu; return 0; }
r[5]=r[14];
goto P_0c08990e;
P_0c08990e: /* original 7608, guest PC 0x0c08990e */
if(!s->budget--) { s->failed_pc=0x0c08990eu; return 0; }
r[6]+=0x00000008u;
goto P_0c089910;
P_0c089910: /* original 6323, guest PC 0x0c089910 */
if(!s->budget--) { s->failed_pc=0x0c089910u; return 0; }
r[3]=r[2];
goto P_0c089912;
P_0c089912: /* original 1f23, guest PC 0x0c089912 */
if(!s->budget--) { s->failed_pc=0x0c089912u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c089914;
P_0c089914: /* original 9087, guest PC 0x0c089914 */
if(!s->budget--) { s->failed_pc=0x0c089914u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089a26u,2);
goto P_0c089916;
P_0c089916: /* original f8dc, guest PC 0x0c089916 */
if(!s->budget--) { s->failed_pc=0x0c089916u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c089918;
P_0c089918: /* original f536, guest PC 0x0c089918 */
if(!s->budget--) { s->failed_pc=0x0c089918u; return 0; }
vf3_matrix_load(s,ram,5,r[3]+r[0]);
goto P_0c08991a;
P_0c08991a: /* original 70f8, guest PC 0x0c08991a */
if(!s->budget--) { s->failed_pc=0x0c08991au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c08991c;
P_0c08991c: /* original f436, guest PC 0x0c08991c */
if(!s->budget--) { s->failed_pc=0x0c08991cu; return 0; }
vf3_matrix_load(s,ram,4,r[3]+r[0]);
goto P_0c08991e;
P_0c08991e: /* original f54d, guest PC 0x0c08991e */
if(!s->budget--) { s->failed_pc=0x0c08991eu; return 0; }
fr[5]^=0x80000000u;
goto P_0c089920;
P_0c089920: /* original f6fc, guest PC 0x0c089920 */
if(!s->budget--) { s->failed_pc=0x0c089920u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c089922;
P_0c089922: /* original f7ec, guest PC 0x0c089922 */
if(!s->budget--) { s->failed_pc=0x0c089922u; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c089924;
P_0c089924: /* original bf1e, guest PC 0x0c089924 */
if(!s->budget--) { s->failed_pc=0x0c089924u; return 0; }
target=0x0c089764u; r[16]=code_base|0x0c089928u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089928u) { target=s->pc; goto dispatch; }
goto P_0c089928;
P_0c089926: /* original 64c3, guest PC 0x0c089926 */
if(!s->budget--) { s->failed_pc=0x0c089926u; return 0; }
r[4]=r[12];
goto P_0c089928;
P_0c089928: /* original e018, guest PC 0x0c089928 */
if(!s->budget--) { s->failed_pc=0x0c089928u; return 0; }
r[0]=0x00000018u;
goto P_0c08992a;
P_0c08992a: /* original 66f3, guest PC 0x0c08992a */
if(!s->budget--) { s->failed_pc=0x0c08992au; return 0; }
r[6]=r[15];
goto P_0c08992c;
P_0c08992c: /* original f586, guest PC 0x0c08992c */
if(!s->budget--) { s->failed_pc=0x0c08992cu; return 0; }
vf3_matrix_load(s,ram,5,r[8]+r[0]);
goto P_0c08992e;
P_0c08992e: /* original e010, guest PC 0x0c08992e */
if(!s->budget--) { s->failed_pc=0x0c08992eu; return 0; }
r[0]=0x00000010u;
goto P_0c089930;
P_0c089930: /* original f486, guest PC 0x0c089930 */
if(!s->budget--) { s->failed_pc=0x0c089930u; return 0; }
vf3_matrix_load(s,ram,4,r[8]+r[0]);
goto P_0c089932;
P_0c089932: /* original 65e3, guest PC 0x0c089932 */
if(!s->budget--) { s->failed_pc=0x0c089932u; return 0; }
r[5]=r[14];
goto P_0c089934;
P_0c089934: /* original f8dc, guest PC 0x0c089934 */
if(!s->budget--) { s->failed_pc=0x0c089934u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c089936;
P_0c089936: /* original 7608, guest PC 0x0c089936 */
if(!s->budget--) { s->failed_pc=0x0c089936u; return 0; }
r[6]+=0x00000008u;
goto P_0c089938;
P_0c089938: /* original f6fc, guest PC 0x0c089938 */
if(!s->budget--) { s->failed_pc=0x0c089938u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08993a;
P_0c08993a: /* original f7ec, guest PC 0x0c08993a */
if(!s->budget--) { s->failed_pc=0x0c08993au; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c08993c;
P_0c08993c: /* original bf12, guest PC 0x0c08993c */
if(!s->budget--) { s->failed_pc=0x0c08993cu; return 0; }
target=0x0c089764u; r[16]=code_base|0x0c089940u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089940u) { target=s->pc; goto dispatch; }
goto P_0c089940;
P_0c08993e: /* original 64c3, guest PC 0x0c08993e */
if(!s->budget--) { s->failed_pc=0x0c08993eu; return 0; }
r[4]=r[12];
goto P_0c089940;
P_0c089940: /* original 84f8, guest PC 0x0c089940 */
if(!s->budget--) { s->failed_pc=0x0c089940u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c089942;
P_0c089942: /* original 8801, guest PC 0x0c089942 */
if(!s->budget--) { s->failed_pc=0x0c089942u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c089944;
P_0c089944: /* original 8d02, guest PC 0x0c089944 */
if(!s->budget--) { s->failed_pc=0x0c089944u; return 0; }
cond=r[17]&1u;
r[4]=r[13];
if(cond) { goto P_0c08994c; }
goto P_0c089948;
P_0c089946: /* original 64d3, guest PC 0x0c089946 */
if(!s->budget--) { s->failed_pc=0x0c089946u; return 0; }
r[4]=r[13];
goto P_0c089948;
P_0c089948: /* original a08e, guest PC 0x0c089948 */
if(!s->budget--) { s->failed_pc=0x0c089948u; return 0; }
goto P_0c089a68;
P_0c08994a: /* original 0009, guest PC 0x0c08994a */
if(!s->budget--) { s->failed_pc=0x0c08994au; return 0; }
goto P_0c08994c;
P_0c08994c: /* original 85e3, guest PC 0x0c08994c */
if(!s->budget--) { s->failed_pc=0x0c08994cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c08994e;
P_0c08994e: /* original 956b, guest PC 0x0c08994e */
if(!s->budget--) { s->failed_pc=0x0c08994eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089a28u,2);
goto P_0c089950;
P_0c089950: /* original 6403, guest PC 0x0c089950 */
if(!s->budget--) { s->failed_pc=0x0c089950u; return 0; }
r[4]=r[0];
goto P_0c089952;
P_0c089952: /* original 84ea, guest PC 0x0c089952 */
if(!s->budget--) { s->failed_pc=0x0c089952u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c089954;
P_0c089954: /* original 6603, guest PC 0x0c089954 */
if(!s->budget--) { s->failed_pc=0x0c089954u; return 0; }
r[6]=r[0];
goto P_0c089956;
P_0c089956: /* original 2668, guest PC 0x0c089956 */
if(!s->budget--) { s->failed_pc=0x0c089956u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c089958;
P_0c089958: /* original 8d01, guest PC 0x0c089958 */
if(!s->budget--) { s->failed_pc=0x0c089958u; return 0; }
cond=r[17]&1u;
r[4]&=r[5];
if(cond) { goto P_0c08995e; }
goto P_0c08995c;
P_0c08995a: /* original 2459, guest PC 0x0c08995a */
if(!s->budget--) { s->failed_pc=0x0c08995au; return 0; }
r[4]&=r[5];
goto P_0c08995c;
P_0c08995c: /* original 34bc, guest PC 0x0c08995c */
if(!s->budget--) { s->failed_pc=0x0c08995cu; return 0; }
r[4]+=r[11];
goto P_0c08995e;
P_0c08995e: /* original 6043, guest PC 0x0c08995e */
if(!s->budget--) { s->failed_pc=0x0c08995eu; return 0; }
r[0]=r[4];
goto P_0c089960;
P_0c089960: /* original 81e3, guest PC 0x0c089960 */
if(!s->budget--) { s->failed_pc=0x0c089960u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c089962;
P_0c089962: /* original c733, guest PC 0x0c089962 */
if(!s->budget--) { s->failed_pc=0x0c089962u; return 0; }
r[0]=0x0c089a30u;
goto P_0c089964;
P_0c089964: /* original 65f3, guest PC 0x0c089964 */
if(!s->budget--) { s->failed_pc=0x0c089964u; return 0; }
r[5]=r[15];
goto P_0c089966;
P_0c089966: /* original f408, guest PC 0x0c089966 */
if(!s->budget--) { s->failed_pc=0x0c089966u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c089968;
P_0c089968: /* original e004, guest PC 0x0c089968 */
if(!s->budget--) { s->failed_pc=0x0c089968u; return 0; }
r[0]=0x00000004u;
goto P_0c08996a;
P_0c08996a: /* original 66f3, guest PC 0x0c08996a */
if(!s->budget--) { s->failed_pc=0x0c08996au; return 0; }
r[6]=r[15];
goto P_0c08996c;
P_0c08996c: /* original 34bc, guest PC 0x0c08996c */
if(!s->budget--) { s->failed_pc=0x0c08996cu; return 0; }
r[4]+=r[11];
goto P_0c08996e;
P_0c08996e: /* original ff47, guest PC 0x0c08996e */
if(!s->budget--) { s->failed_pc=0x0c08996eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c089970;
P_0c089970: /* original f48d, guest PC 0x0c089970 */
if(!s->budget--) { s->failed_pc=0x0c089970u; return 0; }
fr[4]=0;
goto P_0c089972;
P_0c089972: /* original ff4a, guest PC 0x0c089972 */
if(!s->budget--) { s->failed_pc=0x0c089972u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c089974;
P_0c089974: /* original d32f, guest PC 0x0c089974 */
if(!s->budget--) { s->failed_pc=0x0c089974u; return 0; }
r[3]=read(ram,0x0c089a34u,4);
goto P_0c089976;
P_0c089976: /* original 430b, guest PC 0x0c089976 */
if(!s->budget--) { s->failed_pc=0x0c089976u; return 0; }
target=r[3];
r[16]=code_base|0x0c08997au;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08997au) { target=s->pc; goto dispatch; }
goto P_0c08997a;
P_0c089978: /* original 7504, guest PC 0x0c089978 */
if(!s->budget--) { s->failed_pc=0x0c089978u; return 0; }
r[5]+=0x00000004u;
goto P_0c08997a;
P_0c08997a: /* original e004, guest PC 0x0c08997a */
if(!s->budget--) { s->failed_pc=0x0c08997au; return 0; }
r[0]=0x00000004u;
goto P_0c08997c;
P_0c08997c: /* original f3f6, guest PC 0x0c08997c */
if(!s->budget--) { s->failed_pc=0x0c08997cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08997e;
P_0c08997e: /* original e018, guest PC 0x0c08997e */
if(!s->budget--) { s->failed_pc=0x0c08997eu; return 0; }
r[0]=0x00000018u;
goto P_0c089980;
P_0c089980: /* original fe37, guest PC 0x0c089980 */
if(!s->budget--) { s->failed_pc=0x0c089980u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089982;
P_0c089982: /* original e020, guest PC 0x0c089982 */
if(!s->budget--) { s->failed_pc=0x0c089982u; return 0; }
r[0]=0x00000020u;
goto P_0c089984;
P_0c089984: /* original d32c, guest PC 0x0c089984 */
if(!s->budget--) { s->failed_pc=0x0c089984u; return 0; }
r[3]=read(ram,0x0c089a38u,4);
goto P_0c089986;
P_0c089986: /* original f3f8, guest PC 0x0c089986 */
if(!s->budget--) { s->failed_pc=0x0c089986u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089988;
P_0c089988: /* original 430b, guest PC 0x0c089988 */
if(!s->budget--) { s->failed_pc=0x0c089988u; return 0; }
target=r[3];
r[16]=code_base|0x0c08998cu;
vf3_matrix_store(s,ram,3,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08998cu) { target=s->pc; goto dispatch; }
goto P_0c08998c;
P_0c08998a: /* original fe37, guest PC 0x0c08998a */
if(!s->budget--) { s->failed_pc=0x0c08998au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08998c;
P_0c08998c: /* original e51f, guest PC 0x0c08998c */
if(!s->budget--) { s->failed_pc=0x0c08998cu; return 0; }
r[5]=0x0000001fu;
goto P_0c08998e;
P_0c08998e: /* original 6403, guest PC 0x0c08998e */
if(!s->budget--) { s->failed_pc=0x0c08998eu; return 0; }
r[4]=r[0];
goto P_0c089990;
P_0c089990: /* original 7a01, guest PC 0x0c089990 */
if(!s->budget--) { s->failed_pc=0x0c089990u; return 0; }
r[10]+=0x00000001u;
goto P_0c089992;
P_0c089992: /* original 2459, guest PC 0x0c089992 */
if(!s->budget--) { s->failed_pc=0x0c089992u; return 0; }
r[4]&=r[5];
goto P_0c089994;
P_0c089994: /* original 34ac, guest PC 0x0c089994 */
if(!s->budget--) { s->failed_pc=0x0c089994u; return 0; }
r[4]+=r[10];
goto P_0c089996;
P_0c089996: /* original 6043, guest PC 0x0c089996 */
if(!s->budget--) { s->failed_pc=0x0c089996u; return 0; }
r[0]=r[4];
goto P_0c089998;
P_0c089998: /* original 81e4, guest PC 0x0c089998 */
if(!s->budget--) { s->failed_pc=0x0c089998u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c08999a;
P_0c08999a: /* original 60d3, guest PC 0x0c08999a */
if(!s->budget--) { s->failed_pc=0x0c08999au; return 0; }
r[0]=r[13];
goto P_0c08999c;
P_0c08999c: /* original 81e2, guest PC 0x0c08999c */
if(!s->budget--) { s->failed_pc=0x0c08999cu; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c08999e;
P_0c08999e: /* original 85e4, guest PC 0x0c08999e */
if(!s->budget--) { s->failed_pc=0x0c08999eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c0899a0;
P_0c0899a0: /* original 6403, guest PC 0x0c0899a0 */
if(!s->budget--) { s->failed_pc=0x0c0899a0u; return 0; }
r[4]=r[0];
goto P_0c0899a2;
P_0c0899a2: /* original 74ff, guest PC 0x0c0899a2 */
if(!s->budget--) { s->failed_pc=0x0c0899a2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0899a4;
P_0c0899a4: /* original 4415, guest PC 0x0c0899a4 */
if(!s->budget--) { s->failed_pc=0x0c0899a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0899a6;
P_0c0899a6: /* original 895f, guest PC 0x0c0899a6 */
if(!s->budget--) { s->failed_pc=0x0c0899a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089a68; }
goto P_0c0899a8;
P_0c0899a8: /* original 54e9, guest PC 0x0c0899a8 */
if(!s->budget--) { s->failed_pc=0x0c0899a8u; return 0; }
r[4]=read(ram,r[14]+36,4);
goto P_0c0899aa;
P_0c0899aa: /* original 4411, guest PC 0x0c0899aa */
if(!s->budget--) { s->failed_pc=0x0c0899aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0899ac;
P_0c0899ac: /* original 8b07, guest PC 0x0c0899ac */
if(!s->budget--) { s->failed_pc=0x0c0899acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0899be; }
goto P_0c0899ae;
P_0c0899ae: /* original 74ff, guest PC 0x0c0899ae */
if(!s->budget--) { s->failed_pc=0x0c0899aeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0899b0;
P_0c0899b0: /* original 4411, guest PC 0x0c0899b0 */
if(!s->budget--) { s->failed_pc=0x0c0899b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0899b2;
P_0c0899b2: /* original 8d04, guest PC 0x0c0899b2 */
if(!s->budget--) { s->failed_pc=0x0c0899b2u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+36,r[4],4);
if(cond) { goto P_0c0899be; }
goto P_0c0899b6;
P_0c0899b4: /* original 1e49, guest PC 0x0c0899b4 */
if(!s->budget--) { s->failed_pc=0x0c0899b4u; return 0; }
write(ram,r[14]+36,r[4],4);
goto P_0c0899b6;
P_0c0899b6: /* original e016, guest PC 0x0c0899b6 */
if(!s->budget--) { s->failed_pc=0x0c0899b6u; return 0; }
r[0]=0x00000016u;
goto P_0c0899b8;
P_0c0899b8: /* original 02cc, guest PC 0x0c0899b8 */
if(!s->budget--) { s->failed_pc=0x0c0899b8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0899ba;
P_0c0899ba: /* original 72ff, guest PC 0x0c0899ba */
if(!s->budget--) { s->failed_pc=0x0c0899bau; return 0; }
r[2]+=0xffffffffu;
goto P_0c0899bc;
P_0c0899bc: /* original 0c24, guest PC 0x0c0899bc */
if(!s->budget--) { s->failed_pc=0x0c0899bcu; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c0899be;
P_0c0899be: /* original e018, guest PC 0x0c0899be */
if(!s->budget--) { s->failed_pc=0x0c0899beu; return 0; }
r[0]=0x00000018u;
goto P_0c0899c0;
P_0c0899c0: /* original f3e6, guest PC 0x0c0899c0 */
if(!s->budget--) { s->failed_pc=0x0c0899c0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0899c2;
P_0c0899c2: /* original e004, guest PC 0x0c0899c2 */
if(!s->budget--) { s->failed_pc=0x0c0899c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0899c4;
P_0c0899c4: /* original ff37, guest PC 0x0c0899c4 */
if(!s->budget--) { s->failed_pc=0x0c0899c4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0899c6;
P_0c0899c6: /* original e01c, guest PC 0x0c0899c6 */
if(!s->budget--) { s->failed_pc=0x0c0899c6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0899c8;
P_0c0899c8: /* original f4e6, guest PC 0x0c0899c8 */
if(!s->budget--) { s->failed_pc=0x0c0899c8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0899ca;
P_0c0899ca: /* original e020, guest PC 0x0c0899ca */
if(!s->budget--) { s->failed_pc=0x0c0899cau; return 0; }
r[0]=0x00000020u;
goto P_0c0899cc;
P_0c0899cc: /* original f3e6, guest PC 0x0c0899cc */
if(!s->budget--) { s->failed_pc=0x0c0899ccu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0899ce;
P_0c0899ce: /* original e004, guest PC 0x0c0899ce */
if(!s->budget--) { s->failed_pc=0x0c0899ceu; return 0; }
r[0]=0x00000004u;
goto P_0c0899d0;
P_0c0899d0: /* original fc40, guest PC 0x0c0899d0 */
if(!s->budget--) { s->failed_pc=0x0c0899d0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'+');
goto P_0c0899d2;
P_0c0899d2: /* original ff3a, guest PC 0x0c0899d2 */
if(!s->budget--) { s->failed_pc=0x0c0899d2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0899d4;
P_0c0899d4: /* original f3f6, guest PC 0x0c0899d4 */
if(!s->budget--) { s->failed_pc=0x0c0899d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0899d6;
P_0c0899d6: /* original 85e2, guest PC 0x0c0899d6 */
if(!s->budget--) { s->failed_pc=0x0c0899d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+4,2);
goto P_0c0899d8;
P_0c0899d8: /* original ff30, guest PC 0x0c0899d8 */
if(!s->budget--) { s->failed_pc=0x0c0899d8u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0899da;
P_0c0899da: /* original 9526, guest PC 0x0c0899da */
if(!s->budget--) { s->failed_pc=0x0c0899dau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089a2au,2);
goto P_0c0899dc;
P_0c0899dc: /* original 6403, guest PC 0x0c0899dc */
if(!s->budget--) { s->failed_pc=0x0c0899dcu; return 0; }
r[4]=r[0];
goto P_0c0899de;
P_0c0899de: /* original 7401, guest PC 0x0c0899de */
if(!s->budget--) { s->failed_pc=0x0c0899deu; return 0; }
r[4]+=0x00000001u;
goto P_0c0899e0;
P_0c0899e0: /* original f2f8, guest PC 0x0c0899e0 */
if(!s->budget--) { s->failed_pc=0x0c0899e0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0899e2;
P_0c0899e2: /* original 3450, guest PC 0x0c0899e2 */
if(!s->budget--) { s->failed_pc=0x0c0899e2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0899e4;
P_0c0899e4: /* original 8f18, guest PC 0x0c0899e4 */
if(!s->budget--) { s->failed_pc=0x0c0899e4u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
if(!cond) { goto P_0c089a18; }
goto P_0c0899e8;
P_0c0899e6: /* original fe20, guest PC 0x0c0899e6 */
if(!s->budget--) { s->failed_pc=0x0c0899e6u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c0899e8;
P_0c0899e8: /* original 85e3, guest PC 0x0c0899e8 */
if(!s->budget--) { s->failed_pc=0x0c0899e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c0899ea;
P_0c0899ea: /* original 6503, guest PC 0x0c0899ea */
if(!s->budget--) { s->failed_pc=0x0c0899eau; return 0; }
r[5]=r[0];
goto P_0c0899ec;
P_0c0899ec: /* original e004, guest PC 0x0c0899ec */
if(!s->budget--) { s->failed_pc=0x0c0899ecu; return 0; }
r[0]=0x00000004u;
goto P_0c0899ee;
P_0c0899ee: /* original f3f6, guest PC 0x0c0899ee */
if(!s->budget--) { s->failed_pc=0x0c0899eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0899f0;
P_0c0899f0: /* original e004, guest PC 0x0c0899f0 */
if(!s->budget--) { s->failed_pc=0x0c0899f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0899f2;
P_0c0899f2: /* original 35bc, guest PC 0x0c0899f2 */
if(!s->budget--) { s->failed_pc=0x0c0899f2u; return 0; }
r[5]+=r[11];
goto P_0c0899f4;
P_0c0899f4: /* original f34d, guest PC 0x0c0899f4 */
if(!s->budget--) { s->failed_pc=0x0c0899f4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0899f6;
P_0c0899f6: /* original 35bc, guest PC 0x0c0899f6 */
if(!s->budget--) { s->failed_pc=0x0c0899f6u; return 0; }
r[5]+=r[11];
goto P_0c0899f8;
P_0c0899f8: /* original ff37, guest PC 0x0c0899f8 */
if(!s->budget--) { s->failed_pc=0x0c0899f8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0899fa;
P_0c0899fa: /* original e004, guest PC 0x0c0899fa */
if(!s->budget--) { s->failed_pc=0x0c0899fau; return 0; }
r[0]=0x00000004u;
goto P_0c0899fc;
P_0c0899fc: /* original f44d, guest PC 0x0c0899fc */
if(!s->budget--) { s->failed_pc=0x0c0899fcu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0899fe;
P_0c0899fe: /* original f2f8, guest PC 0x0c0899fe */
if(!s->budget--) { s->failed_pc=0x0c0899feu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c089a00;
P_0c089a00: /* original f24d, guest PC 0x0c089a00 */
if(!s->budget--) { s->failed_pc=0x0c089a00u; return 0; }
fr[2]^=0x80000000u;
goto P_0c089a02;
P_0c089a02: /* original ff2a, guest PC 0x0c089a02 */
if(!s->budget--) { s->failed_pc=0x0c089a02u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c089a04;
P_0c089a04: /* original f3f6, guest PC 0x0c089a04 */
if(!s->budget--) { s->failed_pc=0x0c089a04u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089a06;
P_0c089a06: /* original e018, guest PC 0x0c089a06 */
if(!s->budget--) { s->failed_pc=0x0c089a06u; return 0; }
r[0]=0x00000018u;
goto P_0c089a08;
P_0c089a08: /* original fe37, guest PC 0x0c089a08 */
if(!s->budget--) { s->failed_pc=0x0c089a08u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089a0a;
P_0c089a0a: /* original e01c, guest PC 0x0c089a0a */
if(!s->budget--) { s->failed_pc=0x0c089a0au; return 0; }
r[0]=0x0000001cu;
goto P_0c089a0c;
P_0c089a0c: /* original fe47, guest PC 0x0c089a0c */
if(!s->budget--) { s->failed_pc=0x0c089a0cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c089a0e;
P_0c089a0e: /* original e020, guest PC 0x0c089a0e */
if(!s->budget--) { s->failed_pc=0x0c089a0eu; return 0; }
r[0]=0x00000020u;
goto P_0c089a10;
P_0c089a10: /* original f3f8, guest PC 0x0c089a10 */
if(!s->budget--) { s->failed_pc=0x0c089a10u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089a12;
P_0c089a12: /* original fe37, guest PC 0x0c089a12 */
if(!s->budget--) { s->failed_pc=0x0c089a12u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089a14;
P_0c089a14: /* original 6053, guest PC 0x0c089a14 */
if(!s->budget--) { s->failed_pc=0x0c089a14u; return 0; }
r[0]=r[5];
goto P_0c089a16;
P_0c089a16: /* original 81e3, guest PC 0x0c089a16 */
if(!s->budget--) { s->failed_pc=0x0c089a16u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c089a18;
P_0c089a18: /* original 9508, guest PC 0x0c089a18 */
if(!s->budget--) { s->failed_pc=0x0c089a18u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089a2cu,2);
goto P_0c089a1a;
P_0c089a1a: /* original 3450, guest PC 0x0c089a1a */
if(!s->budget--) { s->failed_pc=0x0c089a1au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c089a1c;
P_0c089a1c: /* original 8b1a, guest PC 0x0c089a1c */
if(!s->budget--) { s->failed_pc=0x0c089a1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089a54; }
goto P_0c089a1e;
P_0c089a1e: /* original 64d3, guest PC 0x0c089a1e */
if(!s->budget--) { s->failed_pc=0x0c089a1eu; return 0; }
r[4]=r[13];
goto P_0c089a20;
P_0c089a20: /* original a00c, guest PC 0x0c089a20 */
if(!s->budget--) { s->failed_pc=0x0c089a20u; return 0; }
goto P_0c089a3c;
P_0c089a22: /* original 0009, guest PC 0x0c089a22 */
if(!s->budget--) { s->failed_pc=0x0c089a22u; return 0; }
return vf3_matrix_family(0x0c089a24u,s,ram);
P_0c089a3c: /* original c738, guest PC 0x0c089a3c */
if(!s->budget--) { s->failed_pc=0x0c089a3cu; return 0; }
r[0]=0x0c089b20u;
goto P_0c089a3e;
P_0c089a3e: /* original 6ad3, guest PC 0x0c089a3e */
if(!s->budget--) { s->failed_pc=0x0c089a3eu; return 0; }
r[10]=r[13];
goto P_0c089a40;
P_0c089a40: /* original f408, guest PC 0x0c089a40 */
if(!s->budget--) { s->failed_pc=0x0c089a40u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c089a42;
P_0c089a42: /* original c738, guest PC 0x0c089a42 */
if(!s->budget--) { s->failed_pc=0x0c089a42u; return 0; }
r[0]=0x0c089b24u;
goto P_0c089a44;
P_0c089a44: /* original f508, guest PC 0x0c089a44 */
if(!s->budget--) { s->failed_pc=0x0c089a44u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c089a46;
P_0c089a46: /* original 60d3, guest PC 0x0c089a46 */
if(!s->budget--) { s->failed_pc=0x0c089a46u; return 0; }
r[0]=r[13];
goto P_0c089a48;
P_0c089a48: /* original fd5c, guest PC 0x0c089a48 */
if(!s->budget--) { s->failed_pc=0x0c089a48u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c089a4a;
P_0c089a4a: /* original 80eb, guest PC 0x0c089a4a */
if(!s->budget--) { s->failed_pc=0x0c089a4au; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c089a4c;
P_0c089a4c: /* original e01c, guest PC 0x0c089a4c */
if(!s->budget--) { s->failed_pc=0x0c089a4cu; return 0; }
r[0]=0x0000001cu;
goto P_0c089a4e;
P_0c089a4e: /* original fe47, guest PC 0x0c089a4e */
if(!s->budget--) { s->failed_pc=0x0c089a4eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c089a50;
P_0c089a50: /* original e010, guest PC 0x0c089a50 */
if(!s->budget--) { s->failed_pc=0x0c089a50u; return 0; }
r[0]=0x00000010u;
goto P_0c089a52;
P_0c089a52: /* original fcd7, guest PC 0x0c089a52 */
if(!s->budget--) { s->failed_pc=0x0c089a52u; return 0; }
vf3_matrix_store(s,ram,13,r[12]+r[0]);
goto P_0c089a54;
P_0c089a54: /* original 6043, guest PC 0x0c089a54 */
if(!s->budget--) { s->failed_pc=0x0c089a54u; return 0; }
r[0]=r[4];
goto P_0c089a56;
P_0c089a56: /* original 81e2, guest PC 0x0c089a56 */
if(!s->budget--) { s->failed_pc=0x0c089a56u; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c089a58;
P_0c089a58: /* original e00c, guest PC 0x0c089a58 */
if(!s->budget--) { s->failed_pc=0x0c089a58u; return 0; }
r[0]=0x0000000cu;
goto P_0c089a5a;
P_0c089a5a: /* original 64d3, guest PC 0x0c089a5a */
if(!s->budget--) { s->failed_pc=0x0c089a5au; return 0; }
r[4]=r[13];
goto P_0c089a5c;
P_0c089a5c: /* original fef7, guest PC 0x0c089a5c */
if(!s->budget--) { s->failed_pc=0x0c089a5cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089a5e;
P_0c089a5e: /* original e010, guest PC 0x0c089a5e */
if(!s->budget--) { s->failed_pc=0x0c089a5eu; return 0; }
r[0]=0x00000010u;
goto P_0c089a60;
P_0c089a60: /* original fec7, guest PC 0x0c089a60 */
if(!s->budget--) { s->failed_pc=0x0c089a60u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c089a62;
P_0c089a62: /* original e014, guest PC 0x0c089a62 */
if(!s->budget--) { s->failed_pc=0x0c089a62u; return 0; }
r[0]=0x00000014u;
goto P_0c089a64;
P_0c089a64: /* original fe4d, guest PC 0x0c089a64 */
if(!s->budget--) { s->failed_pc=0x0c089a64u; return 0; }
fr[14]^=0x80000000u;
goto P_0c089a66;
P_0c089a66: /* original fee7, guest PC 0x0c089a66 */
if(!s->budget--) { s->failed_pc=0x0c089a66u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c089a68;
P_0c089a68: /* original 6043, guest PC 0x0c089a68 */
if(!s->budget--) { s->failed_pc=0x0c089a68u; return 0; }
r[0]=r[4];
goto P_0c089a6a;
P_0c089a6a: /* original 81e4, guest PC 0x0c089a6a */
if(!s->budget--) { s->failed_pc=0x0c089a6au; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c089a6c;
P_0c089a6c: /* original 53f4, guest PC 0x0c089a6c */
if(!s->budget--) { s->failed_pc=0x0c089a6cu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c089a6e;
P_0c089a6e: /* original 7e28, guest PC 0x0c089a6e */
if(!s->budget--) { s->failed_pc=0x0c089a6eu; return 0; }
r[14]+=0x00000028u;
goto P_0c089a70;
P_0c089a70: /* original 7301, guest PC 0x0c089a70 */
if(!s->budget--) { s->failed_pc=0x0c089a70u; return 0; }
r[3]+=0x00000001u;
goto P_0c089a72;
P_0c089a72: /* original 1f34, guest PC 0x0c089a72 */
if(!s->budget--) { s->failed_pc=0x0c089a72u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c089a74;
P_0c089a74: /* original 53f4, guest PC 0x0c089a74 */
if(!s->budget--) { s->failed_pc=0x0c089a74u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c089a76;
P_0c089a76: /* original e420, guest PC 0x0c089a76 */
if(!s->budget--) { s->failed_pc=0x0c089a76u; return 0; }
r[4]=0x00000020u;
goto P_0c089a78;
P_0c089a78: /* original 3343, guest PC 0x0c089a78 */
if(!s->budget--) { s->failed_pc=0x0c089a78u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c089a7a;
P_0c089a7a: /* original 8901, guest PC 0x0c089a7a */
if(!s->budget--) { s->failed_pc=0x0c089a7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089a80; }
goto P_0c089a7c;
P_0c089a7c: /* original af22, guest PC 0x0c089a7c */
if(!s->budget--) { s->failed_pc=0x0c089a7cu; return 0; }
goto P_0c0898c4;
P_0c089a7e: /* original 0009, guest PC 0x0c089a7e */
if(!s->budget--) { s->failed_pc=0x0c089a7eu; return 0; }
goto P_0c089a80;
P_0c089a80: /* original 60a3, guest PC 0x0c089a80 */
if(!s->budget--) { s->failed_pc=0x0c089a80u; return 0; }
r[0]=r[10];
goto P_0c089a82;
P_0c089a82: /* original 81ca, guest PC 0x0c089a82 */
if(!s->budget--) { s->failed_pc=0x0c089a82u; return 0; }
write(ram,r[12]+20,r[0],2);
goto P_0c089a84;
P_0c089a84: /* original 7f14, guest PC 0x0c089a84 */
if(!s->budget--) { s->failed_pc=0x0c089a84u; return 0; }
r[15]+=0x00000014u;
goto P_0c089a86;
P_0c089a86: /* original 4f26, guest PC 0x0c089a86 */
if(!s->budget--) { s->failed_pc=0x0c089a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089a88;
P_0c089a88: /* original fcf9, guest PC 0x0c089a88 */
if(!s->budget--) { s->failed_pc=0x0c089a88u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089a8a;
P_0c089a8a: /* original fdf9, guest PC 0x0c089a8a */
if(!s->budget--) { s->failed_pc=0x0c089a8au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089a8c;
P_0c089a8c: /* original fef9, guest PC 0x0c089a8c */
if(!s->budget--) { s->failed_pc=0x0c089a8cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089a8e;
P_0c089a8e: /* original fff9, guest PC 0x0c089a8e */
if(!s->budget--) { s->failed_pc=0x0c089a8eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089a90;
P_0c089a90: /* original 68f6, guest PC 0x0c089a90 */
if(!s->budget--) { s->failed_pc=0x0c089a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c089a92;
P_0c089a92: /* original 69f6, guest PC 0x0c089a92 */
if(!s->budget--) { s->failed_pc=0x0c089a92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089a94;
P_0c089a94: /* original 6af6, guest PC 0x0c089a94 */
if(!s->budget--) { s->failed_pc=0x0c089a94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089a96;
P_0c089a96: /* original 6bf6, guest PC 0x0c089a96 */
if(!s->budget--) { s->failed_pc=0x0c089a96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089a98;
P_0c089a98: /* original 6cf6, guest PC 0x0c089a98 */
if(!s->budget--) { s->failed_pc=0x0c089a98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089a9a;
P_0c089a9a: /* original 6df6, guest PC 0x0c089a9a */
if(!s->budget--) { s->failed_pc=0x0c089a9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089a9c;
P_0c089a9c: /* original 000b, guest PC 0x0c089a9c */
if(!s->budget--) { s->failed_pc=0x0c089a9cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089a9e: /* original 6ef6, guest PC 0x0c089a9e */
if(!s->budget--) { s->failed_pc=0x0c089a9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089aa0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c089764u,0x0c089766u,0x0c089768u,0x0c08976au,0x0c0897ceu,0x0c0897d0u,0x0c0897d2u,0x0c0897d4u,0x0c0897d6u,0x0c0897d8u,0x0c0897dau,0x0c0897dcu,0x0c0897deu,0x0c0897e0u,0x0c0897e2u,0x0c0897e4u,
0x0c0897e6u,0x0c0897e8u,0x0c0897eau,0x0c089864u,0x0c089866u,0x0c089868u,0x0c08986au,0x0c08986cu,0x0c08986eu,0x0c089870u,0x0c089872u,0x0c089874u,0x0c089876u,0x0c089878u,0x0c08987au,0x0c08987cu,
0x0c08987eu,0x0c089880u,0x0c089882u,0x0c089884u,0x0c089886u,0x0c089888u,0x0c08988au,0x0c08988cu,0x0c08988eu,0x0c089890u,0x0c089892u,0x0c089894u,0x0c089896u,0x0c0898c4u,0x0c0898c6u,0x0c0898c8u,
0x0c0898cau,0x0c0898ccu,0x0c0898ceu,0x0c0898d0u,0x0c0898d2u,0x0c0898d4u,0x0c0898d6u,0x0c0898d8u,0x0c0898dau,0x0c0898dcu,0x0c0898deu,0x0c0898e0u,0x0c0898e2u,0x0c0898e4u,0x0c0898e6u,0x0c0898e8u,
0x0c0898eau,0x0c0898ecu,0x0c0898eeu,0x0c0898f0u,0x0c0898f2u,0x0c0898f4u,0x0c0898f6u,0x0c0898f8u,0x0c0898fau,0x0c0898fcu,0x0c0898feu,0x0c089900u,0x0c089902u,0x0c089904u,0x0c089906u,0x0c089908u,
0x0c08990au,0x0c08990cu,0x0c08990eu,0x0c089910u,0x0c089912u,0x0c089914u,0x0c089916u,0x0c089918u,0x0c08991au,0x0c08991cu,0x0c08991eu,0x0c089920u,0x0c089922u,0x0c089924u,0x0c089926u,0x0c089928u,
0x0c08992au,0x0c08992cu,0x0c08992eu,0x0c089930u,0x0c089932u,0x0c089934u,0x0c089936u,0x0c089938u,0x0c08993au,0x0c08993cu,0x0c08993eu,0x0c089940u,0x0c089942u,0x0c089944u,0x0c089946u,0x0c089948u,
0x0c08994au,0x0c08994cu,0x0c08994eu,0x0c089950u,0x0c089952u,0x0c089954u,0x0c089956u,0x0c089958u,0x0c08995au,0x0c08995cu,0x0c08995eu,0x0c089960u,0x0c089962u,0x0c089964u,0x0c089966u,0x0c089968u,
0x0c08996au,0x0c08996cu,0x0c08996eu,0x0c089970u,0x0c089972u,0x0c089974u,0x0c089976u,0x0c089978u,0x0c08997au,0x0c08997cu,0x0c08997eu,0x0c089980u,0x0c089982u,0x0c089984u,0x0c089986u,0x0c089988u,
0x0c08998au,0x0c08998cu,0x0c08998eu,0x0c089990u,0x0c089992u,0x0c089994u,0x0c089996u,0x0c089998u,0x0c08999au,0x0c08999cu,0x0c08999eu,0x0c0899a0u,0x0c0899a2u,0x0c0899a4u,0x0c0899a6u,0x0c0899a8u,
0x0c0899aau,0x0c0899acu,0x0c0899aeu,0x0c0899b0u,0x0c0899b2u,0x0c0899b4u,0x0c0899b6u,0x0c0899b8u,0x0c0899bau,0x0c0899bcu,0x0c0899beu,0x0c0899c0u,0x0c0899c2u,0x0c0899c4u,0x0c0899c6u,0x0c0899c8u,
0x0c0899cau,0x0c0899ccu,0x0c0899ceu,0x0c0899d0u,0x0c0899d2u,0x0c0899d4u,0x0c0899d6u,0x0c0899d8u,0x0c0899dau,0x0c0899dcu,0x0c0899deu,0x0c0899e0u,0x0c0899e2u,0x0c0899e4u,0x0c0899e6u,0x0c0899e8u,
0x0c0899eau,0x0c0899ecu,0x0c0899eeu,0x0c0899f0u,0x0c0899f2u,0x0c0899f4u,0x0c0899f6u,0x0c0899f8u,0x0c0899fau,0x0c0899fcu,0x0c0899feu,0x0c089a00u,0x0c089a02u,0x0c089a04u,0x0c089a06u,0x0c089a08u,
0x0c089a0au,0x0c089a0cu,0x0c089a0eu,0x0c089a10u,0x0c089a12u,0x0c089a14u,0x0c089a16u,0x0c089a18u,0x0c089a1au,0x0c089a1cu,0x0c089a1eu,0x0c089a20u,0x0c089a22u,0x0c089a3cu,0x0c089a3eu,0x0c089a40u,
0x0c089a42u,0x0c089a44u,0x0c089a46u,0x0c089a48u,0x0c089a4au,0x0c089a4cu,0x0c089a4eu,0x0c089a50u,0x0c089a52u,0x0c089a54u,0x0c089a56u,0x0c089a58u,0x0c089a5au,0x0c089a5cu,0x0c089a5eu,0x0c089a60u,
0x0c089a62u,0x0c089a64u,0x0c089a66u,0x0c089a68u,0x0c089a6au,0x0c089a6cu,0x0c089a6eu,0x0c089a70u,0x0c089a72u,0x0c089a74u,0x0c089a76u,0x0c089a78u,0x0c089a7au,0x0c089a7cu,0x0c089a7eu,0x0c089a80u,
0x0c089a82u,0x0c089a84u,0x0c089a86u,0x0c089a88u,0x0c089a8au,0x0c089a8cu,0x0c089a8eu,0x0c089a90u,0x0c089a92u,0x0c089a94u,0x0c089a96u,0x0c089a98u,0x0c089a9au,0x0c089a9cu,0x0c089a9eu,
};
int vf3_0898_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
