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
int vf3_advance_small_tail_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042fdcu: goto P_0c042fdc;
case 0x0c042fdeu: goto P_0c042fde;
case 0x0c042fe0u: goto P_0c042fe0;
case 0x0c042fe2u: goto P_0c042fe2;
case 0x0c042fe4u: goto P_0c042fe4;
case 0x0c042fe6u: goto P_0c042fe6;
case 0x0c042fe8u: goto P_0c042fe8;
case 0x0c042feau: goto P_0c042fea;
case 0x0c042fecu: goto P_0c042fec;
case 0x0c042feeu: goto P_0c042fee;
case 0x0c042ff0u: goto P_0c042ff0;
case 0x0c042ff2u: goto P_0c042ff2;
case 0x0c042ff4u: goto P_0c042ff4;
case 0x0c042ff6u: goto P_0c042ff6;
case 0x0c042ff8u: goto P_0c042ff8;
case 0x0c042ffau: goto P_0c042ffa;
case 0x0c042ffcu: goto P_0c042ffc;
case 0x0c042ffeu: goto P_0c042ffe;
case 0x0c043000u: goto P_0c043000;
case 0x0c043002u: goto P_0c043002;
case 0x0c043004u: goto P_0c043004;
case 0x0c043006u: goto P_0c043006;
case 0x0c043008u: goto P_0c043008;
case 0x0c04300au: goto P_0c04300a;
case 0x0c04300cu: goto P_0c04300c;
case 0x0c04300eu: goto P_0c04300e;
case 0x0c043010u: goto P_0c043010;
case 0x0c043012u: goto P_0c043012;
case 0x0c043014u: goto P_0c043014;
case 0x0c043016u: goto P_0c043016;
case 0x0c04bc8cu: goto P_0c04bc8c;
case 0x0c04bc8eu: goto P_0c04bc8e;
case 0x0c04bc90u: goto P_0c04bc90;
case 0x0c04bc92u: goto P_0c04bc92;
case 0x0c04bc94u: goto P_0c04bc94;
case 0x0c04bc96u: goto P_0c04bc96;
case 0x0c04bc98u: goto P_0c04bc98;
case 0x0c04bc9au: goto P_0c04bc9a;
case 0x0c04bc9cu: goto P_0c04bc9c;
case 0x0c04bc9eu: goto P_0c04bc9e;
case 0x0c04bca0u: goto P_0c04bca0;
case 0x0c04bca2u: goto P_0c04bca2;
case 0x0c04bca4u: goto P_0c04bca4;
case 0x0c04bca6u: goto P_0c04bca6;
case 0x0c04bca8u: goto P_0c04bca8;
case 0x0c04bcaau: goto P_0c04bcaa;
case 0x0c04bcacu: goto P_0c04bcac;
case 0x0c04bcaeu: goto P_0c04bcae;
case 0x0c04bcb0u: goto P_0c04bcb0;
case 0x0c04bcb2u: goto P_0c04bcb2;
case 0x0c04bcb4u: goto P_0c04bcb4;
case 0x0c04bcb6u: goto P_0c04bcb6;
case 0x0c04bcb8u: goto P_0c04bcb8;
case 0x0c04bcbau: goto P_0c04bcba;
case 0x0c04bcc6u: goto P_0c04bcc6;
case 0x0c04bcc8u: goto P_0c04bcc8;
case 0x0c04bccau: goto P_0c04bcca;
case 0x0c04bcccu: goto P_0c04bccc;
case 0x0c04bcceu: goto P_0c04bcce;
case 0x0c04bcd0u: goto P_0c04bcd0;
case 0x0c04bcd2u: goto P_0c04bcd2;
case 0x0c04bcd4u: goto P_0c04bcd4;
case 0x0c04bcd6u: goto P_0c04bcd6;
case 0x0c04bcd8u: goto P_0c04bcd8;
case 0x0c04bcdau: goto P_0c04bcda;
case 0x0c04bcdcu: goto P_0c04bcdc;
case 0x0c04bcdeu: goto P_0c04bcde;
case 0x0c04bce0u: goto P_0c04bce0;
case 0x0c04bce2u: goto P_0c04bce2;
case 0x0c04bce4u: goto P_0c04bce4;
case 0x0c04bce6u: goto P_0c04bce6;
case 0x0c04bce8u: goto P_0c04bce8;
case 0x0c04bceau: goto P_0c04bcea;
case 0x0c04bcecu: goto P_0c04bcec;
case 0x0c04bceeu: goto P_0c04bcee;
case 0x0c04bcf0u: goto P_0c04bcf0;
case 0x0c04bcf2u: goto P_0c04bcf2;
case 0x0c04bcf4u: goto P_0c04bcf4;
case 0x0c04bcf6u: goto P_0c04bcf6;
case 0x0c04bcf8u: goto P_0c04bcf8;
case 0x0c04bcfau: goto P_0c04bcfa;
case 0x0c04bcfcu: goto P_0c04bcfc;
case 0x0c04bcfeu: goto P_0c04bcfe;
case 0x0c04bd00u: goto P_0c04bd00;
case 0x0c04bd02u: goto P_0c04bd02;
case 0x0c04bd04u: goto P_0c04bd04;
case 0x0c04bd06u: goto P_0c04bd06;
case 0x0c04bd08u: goto P_0c04bd08;
case 0x0c04bd0au: goto P_0c04bd0a;
case 0x0c04bd0cu: goto P_0c04bd0c;
case 0x0c04bd0eu: goto P_0c04bd0e;
case 0x0c04bd10u: goto P_0c04bd10;
case 0x0c04bd12u: goto P_0c04bd12;
case 0x0c04bd14u: goto P_0c04bd14;
case 0x0c04bd16u: goto P_0c04bd16;
case 0x0c04bd18u: goto P_0c04bd18;
case 0x0c04bd1au: goto P_0c04bd1a;
case 0x0c04bd1cu: goto P_0c04bd1c;
case 0x0c04bd1eu: goto P_0c04bd1e;
case 0x0c076b3cu: goto P_0c076b3c;
case 0x0c076b3eu: goto P_0c076b3e;
case 0x0c076b40u: goto P_0c076b40;
case 0x0c076b42u: goto P_0c076b42;
case 0x0c076b44u: goto P_0c076b44;
case 0x0c076b46u: goto P_0c076b46;
case 0x0c076b48u: goto P_0c076b48;
case 0x0c076b4au: goto P_0c076b4a;
case 0x0c076b4cu: goto P_0c076b4c;
case 0x0c076b4eu: goto P_0c076b4e;
case 0x0c076b50u: goto P_0c076b50;
case 0x0c076b52u: goto P_0c076b52;
case 0x0c076b54u: goto P_0c076b54;
case 0x0c076b56u: goto P_0c076b56;
case 0x0c076b58u: goto P_0c076b58;
case 0x0c076b5au: goto P_0c076b5a;
case 0x0c076b5cu: goto P_0c076b5c;
case 0x0c076b5eu: goto P_0c076b5e;
case 0x0c076b60u: goto P_0c076b60;
case 0x0c076b62u: goto P_0c076b62;
case 0x0c076b64u: goto P_0c076b64;
case 0x0c0819fau: goto P_0c0819fa;
case 0x0c0819fcu: goto P_0c0819fc;
case 0x0c0819feu: goto P_0c0819fe;
case 0x0c081a00u: goto P_0c081a00;
case 0x0c081a02u: goto P_0c081a02;
case 0x0c081a04u: goto P_0c081a04;
case 0x0c081a06u: goto P_0c081a06;
case 0x0c081a08u: goto P_0c081a08;
case 0x0c081a0au: goto P_0c081a0a;
case 0x0c081a0cu: goto P_0c081a0c;
case 0x0c081a0eu: goto P_0c081a0e;
case 0x0c081a10u: goto P_0c081a10;
case 0x0c081a12u: goto P_0c081a12;
case 0x0c081a14u: goto P_0c081a14;
case 0x0c081a16u: goto P_0c081a16;
case 0x0c081a18u: goto P_0c081a18;
case 0x0c081a1au: goto P_0c081a1a;
case 0x0c081a1cu: goto P_0c081a1c;
case 0x0c081a1eu: goto P_0c081a1e;
case 0x0c081a20u: goto P_0c081a20;
case 0x0c081a22u: goto P_0c081a22;
case 0x0c081a24u: goto P_0c081a24;
case 0x0c081a26u: goto P_0c081a26;
case 0x0c081a28u: goto P_0c081a28;
case 0x0c081a2au: goto P_0c081a2a;
case 0x0c081a2cu: goto P_0c081a2c;
case 0x0c081a2eu: goto P_0c081a2e;
case 0x0c081a30u: goto P_0c081a30;
case 0x0c095724u: goto P_0c095724;
case 0x0c095726u: goto P_0c095726;
case 0x0c095728u: goto P_0c095728;
case 0x0c09572au: goto P_0c09572a;
case 0x0c09572cu: goto P_0c09572c;
case 0x0c09572eu: goto P_0c09572e;
case 0x0c095730u: goto P_0c095730;
case 0x0c095732u: goto P_0c095732;
case 0x0c095734u: goto P_0c095734;
case 0x0c095736u: goto P_0c095736;
case 0x0c095738u: goto P_0c095738;
case 0x0c09573au: goto P_0c09573a;
case 0x0c09573cu: goto P_0c09573c;
case 0x0c09573eu: goto P_0c09573e;
case 0x0c095740u: goto P_0c095740;
case 0x0c095742u: goto P_0c095742;
case 0x0c095744u: goto P_0c095744;
case 0x0c095746u: goto P_0c095746;
case 0x0c095748u: goto P_0c095748;
case 0x0c09574au: goto P_0c09574a;
case 0x0c09574cu: goto P_0c09574c;
case 0x0c09af6cu: goto P_0c09af6c;
case 0x0c09af6eu: goto P_0c09af6e;
case 0x0c09af70u: goto P_0c09af70;
case 0x0c09af72u: goto P_0c09af72;
case 0x0c09af74u: goto P_0c09af74;
case 0x0c09af76u: goto P_0c09af76;
case 0x0c09af78u: goto P_0c09af78;
case 0x0c09af7au: goto P_0c09af7a;
case 0x0c09af7cu: goto P_0c09af7c;
case 0x0c09af7eu: goto P_0c09af7e;
case 0x0c09af80u: goto P_0c09af80;
case 0x0c09af82u: goto P_0c09af82;
case 0x0c09af84u: goto P_0c09af84;
case 0x0c09af86u: goto P_0c09af86;
case 0x0c09af88u: goto P_0c09af88;
case 0x0c09af8au: goto P_0c09af8a;
case 0x0c09af8cu: goto P_0c09af8c;
case 0x0c09af8eu: goto P_0c09af8e;
case 0x0c09af90u: goto P_0c09af90;
case 0x0c09af92u: goto P_0c09af92;
case 0x0c09af94u: goto P_0c09af94;
case 0x0c09af96u: goto P_0c09af96;
case 0x0c09af98u: goto P_0c09af98;
case 0x0c09af9au: goto P_0c09af9a;
case 0x0c09af9cu: goto P_0c09af9c;
case 0x0c09af9eu: goto P_0c09af9e;
case 0x0c09afa0u: goto P_0c09afa0;
case 0x0c09afa2u: goto P_0c09afa2;
case 0x0c09afa4u: goto P_0c09afa4;
case 0x0c09afa6u: goto P_0c09afa6;
case 0x0c09afa8u: goto P_0c09afa8;
case 0x0c09afaau: goto P_0c09afaa;
case 0x0c09afacu: goto P_0c09afac;
case 0x0c09afaeu: goto P_0c09afae;
case 0x0c09afb0u: goto P_0c09afb0;
case 0x0c09afb2u: goto P_0c09afb2;
case 0x0c09afb4u: goto P_0c09afb4;
case 0x0c09afb6u: goto P_0c09afb6;
case 0x0c09afb8u: goto P_0c09afb8;
case 0x0c09afbau: goto P_0c09afba;
case 0x0c09afbcu: goto P_0c09afbc;
case 0x0c09afbeu: goto P_0c09afbe;
case 0x0c09b926u: goto P_0c09b926;
case 0x0c09b928u: goto P_0c09b928;
case 0x0c09b92au: goto P_0c09b92a;
case 0x0c09b92cu: goto P_0c09b92c;
case 0x0c09b92eu: goto P_0c09b92e;
case 0x0c09b930u: goto P_0c09b930;
case 0x0c09b932u: goto P_0c09b932;
case 0x0c09b934u: goto P_0c09b934;
case 0x0c09b936u: goto P_0c09b936;
case 0x0c09b938u: goto P_0c09b938;
case 0x0c09b93au: goto P_0c09b93a;
case 0x0c09b93cu: goto P_0c09b93c;
case 0x0c09b93eu: goto P_0c09b93e;
case 0x0c09b940u: goto P_0c09b940;
case 0x0c09b942u: goto P_0c09b942;
case 0x0c09b944u: goto P_0c09b944;
case 0x0c09b946u: goto P_0c09b946;
case 0x0c09b948u: goto P_0c09b948;
case 0x0c09b94au: goto P_0c09b94a;
case 0x0c09b94cu: goto P_0c09b94c;
case 0x0c09b94eu: goto P_0c09b94e;
case 0x0c09b950u: goto P_0c09b950;
case 0x0c09b952u: goto P_0c09b952;
case 0x0c09b954u: goto P_0c09b954;
case 0x0c09b978u: goto P_0c09b978;
case 0x0c09b97au: goto P_0c09b97a;
case 0x0c09b97cu: goto P_0c09b97c;
case 0x0c09b97eu: goto P_0c09b97e;
case 0x0c09b980u: goto P_0c09b980;
case 0x0c09b982u: goto P_0c09b982;
case 0x0c09b984u: goto P_0c09b984;
case 0x0c09b986u: goto P_0c09b986;
case 0x0c09b988u: goto P_0c09b988;
case 0x0c09b98au: goto P_0c09b98a;
case 0x0c09b98cu: goto P_0c09b98c;
case 0x0c09b98eu: goto P_0c09b98e;
case 0x0c09b990u: goto P_0c09b990;
case 0x0c09b992u: goto P_0c09b992;
case 0x0c09b994u: goto P_0c09b994;
case 0x0c09b996u: goto P_0c09b996;
case 0x0c09b998u: goto P_0c09b998;
case 0x0c09b99au: goto P_0c09b99a;
case 0x0c09b99cu: goto P_0c09b99c;
case 0x0c09b99eu: goto P_0c09b99e;
case 0x0c09b9a0u: goto P_0c09b9a0;
case 0x0c09b9a2u: goto P_0c09b9a2;
case 0x0c09b9a4u: goto P_0c09b9a4;
case 0x0c09b9a6u: goto P_0c09b9a6;
case 0x0c09b9a8u: goto P_0c09b9a8;
case 0x0c09b9aau: goto P_0c09b9aa;
case 0x0c09b9acu: goto P_0c09b9ac;
case 0x0c09b9aeu: goto P_0c09b9ae;
case 0x0c09b9b0u: goto P_0c09b9b0;
case 0x0c09b9b2u: goto P_0c09b9b2;
case 0x0c09b9b4u: goto P_0c09b9b4;
case 0x0c09b9b6u: goto P_0c09b9b6;
case 0x0c09b9b8u: goto P_0c09b9b8;
case 0x0c09b9bau: goto P_0c09b9ba;
case 0x0c09b9bcu: goto P_0c09b9bc;
case 0x0c09b9beu: goto P_0c09b9be;
case 0x0c09b9c0u: goto P_0c09b9c0;
case 0x0c09b9c2u: goto P_0c09b9c2;
case 0x0c09b9c4u: goto P_0c09b9c4;
case 0x0c09b9c6u: goto P_0c09b9c6;
case 0x0c09b9c8u: goto P_0c09b9c8;
case 0x0c09b9cau: goto P_0c09b9ca;
case 0x0c09b9ccu: goto P_0c09b9cc;
case 0x0c09b9ceu: goto P_0c09b9ce;
case 0x0c09b9d0u: goto P_0c09b9d0;
case 0x0c09b9d2u: goto P_0c09b9d2;
case 0x0c09b9d4u: goto P_0c09b9d4;
case 0x0c09b9d6u: goto P_0c09b9d6;
case 0x0c09b9d8u: goto P_0c09b9d8;
case 0x0c09b9dau: goto P_0c09b9da;
case 0x0c09b9dcu: goto P_0c09b9dc;
case 0x0c09b9deu: goto P_0c09b9de;
case 0x0c09b9e0u: goto P_0c09b9e0;
case 0x0c09b9e2u: goto P_0c09b9e2;
case 0x0c09b9e4u: goto P_0c09b9e4;
case 0x0c09b9e6u: goto P_0c09b9e6;
case 0x0c09b9e8u: goto P_0c09b9e8;
case 0x0c09b9eau: goto P_0c09b9ea;
case 0x0c09b9ecu: goto P_0c09b9ec;
case 0x0c09b9eeu: goto P_0c09b9ee;
case 0x0c09b9f0u: goto P_0c09b9f0;
case 0x0c09b9f2u: goto P_0c09b9f2;
case 0x0c09b9f4u: goto P_0c09b9f4;
case 0x0c09b9f6u: goto P_0c09b9f6;
case 0x0c09b9f8u: goto P_0c09b9f8;
case 0x0c09b9fau: goto P_0c09b9fa;
case 0x0c09b9fcu: goto P_0c09b9fc;
case 0x0c09b9feu: goto P_0c09b9fe;
case 0x0c09ba00u: goto P_0c09ba00;
case 0x0c09ba02u: goto P_0c09ba02;
case 0x0c09ba04u: goto P_0c09ba04;
case 0x0c09ba06u: goto P_0c09ba06;
case 0x0c09ba08u: goto P_0c09ba08;
case 0x0c09ba0au: goto P_0c09ba0a;
case 0x0c09ba0cu: goto P_0c09ba0c;
case 0x0c09ba0eu: goto P_0c09ba0e;
case 0x0c09ba10u: goto P_0c09ba10;
case 0x0c09ba12u: goto P_0c09ba12;
case 0x0c09ba14u: goto P_0c09ba14;
case 0x0c09ba16u: goto P_0c09ba16;
case 0x0c09ba18u: goto P_0c09ba18;
case 0x0c09ba1au: goto P_0c09ba1a;
case 0x0c09ba1cu: goto P_0c09ba1c;
case 0x0c09ba1eu: goto P_0c09ba1e;
case 0x0c09ba20u: goto P_0c09ba20;
case 0x0c09ba22u: goto P_0c09ba22;
case 0x0c09ba24u: goto P_0c09ba24;
case 0x0c09ba26u: goto P_0c09ba26;
case 0x0c09ba28u: goto P_0c09ba28;
case 0x0c09ba2au: goto P_0c09ba2a;
case 0x0c09ba2cu: goto P_0c09ba2c;
case 0x0c09ba2eu: goto P_0c09ba2e;
case 0x0c09ba30u: goto P_0c09ba30;
case 0x0c09ba32u: goto P_0c09ba32;
case 0x0c09ba34u: goto P_0c09ba34;
case 0x0c09ba36u: goto P_0c09ba36;
case 0x0c09ba38u: goto P_0c09ba38;
case 0x0c09ba3au: goto P_0c09ba3a;
case 0x0c09ba3cu: goto P_0c09ba3c;
case 0x0c09ba3eu: goto P_0c09ba3e;
case 0x0c09ba40u: goto P_0c09ba40;
case 0x0c09ba42u: goto P_0c09ba42;
case 0x0c09ba44u: goto P_0c09ba44;
case 0x0c09ba46u: goto P_0c09ba46;
case 0x0c09ba48u: goto P_0c09ba48;
case 0x0c09ba4au: goto P_0c09ba4a;
case 0x0c09ba4cu: goto P_0c09ba4c;
case 0x0c09ba4eu: goto P_0c09ba4e;
case 0x0c09ba50u: goto P_0c09ba50;
case 0x0c09ba52u: goto P_0c09ba52;
case 0x0c09ba54u: goto P_0c09ba54;
case 0x0c09ba56u: goto P_0c09ba56;
case 0x0c09ba58u: goto P_0c09ba58;
case 0x0c09ba5au: goto P_0c09ba5a;
case 0x0c09ba5cu: goto P_0c09ba5c;
case 0x0c09ba5eu: goto P_0c09ba5e;
case 0x0c09ba60u: goto P_0c09ba60;
case 0x0c09ba62u: goto P_0c09ba62;
case 0x0c09ba64u: goto P_0c09ba64;
case 0x0c09ba66u: goto P_0c09ba66;
case 0x0c09ba68u: goto P_0c09ba68;
case 0x0c09ba6au: goto P_0c09ba6a;
case 0x0c09ba6cu: goto P_0c09ba6c;
case 0x0c0c9c18u: goto P_0c0c9c18;
case 0x0c0c9c1au: goto P_0c0c9c1a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042fdc: /* original 2668, guest PC 0x0c042fdc */
if(!s->budget--) { s->failed_pc=0x0c042fdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c042fde;
P_0c042fde: /* original 8f02, guest PC 0x0c042fde */
if(!s->budget--) { s->failed_pc=0x0c042fdeu; return 0; }
cond=r[17]&1u;
r[7]=r[5];
if(!cond) { goto P_0c042fe6; }
goto P_0c042fe2;
P_0c042fe0: /* original 6753, guest PC 0x0c042fe0 */
if(!s->budget--) { s->failed_pc=0x0c042fe0u; return 0; }
r[7]=r[5];
goto P_0c042fe2;
P_0c042fe2: /* original 000b, guest PC 0x0c042fe2 */
if(!s->budget--) { s->failed_pc=0x0c042fe2u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c042fe4: /* original e000, guest PC 0x0c042fe4 */
if(!s->budget--) { s->failed_pc=0x0c042fe4u; return 0; }
r[0]=0x00000000u;
goto P_0c042fe6;
P_0c042fe6: /* original e500, guest PC 0x0c042fe6 */
if(!s->budget--) { s->failed_pc=0x0c042fe6u; return 0; }
r[5]=0x00000000u;
goto P_0c042fe8;
P_0c042fe8: /* original 6253, guest PC 0x0c042fe8 */
if(!s->budget--) { s->failed_pc=0x0c042fe8u; return 0; }
r[2]=r[5];
goto P_0c042fea;
P_0c042fea: /* original 3262, guest PC 0x0c042fea */
if(!s->budget--) { s->failed_pc=0x0c042feau; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[6])!=0);
goto P_0c042fec;
P_0c042fec: /* original 8d09, guest PC 0x0c042fec */
if(!s->budget--) { s->failed_pc=0x0c042fecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043002; }
goto P_0c042ff0;
P_0c042fee: /* original 0009, guest PC 0x0c042fee */
if(!s->budget--) { s->failed_pc=0x0c042feeu; return 0; }
goto P_0c042ff0;
P_0c042ff0: /* original 6344, guest PC 0x0c042ff0 */
if(!s->budget--) { s->failed_pc=0x0c042ff0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[3]=tmp;
goto P_0c042ff2;
P_0c042ff2: /* original 6274, guest PC 0x0c042ff2 */
if(!s->budget--) { s->failed_pc=0x0c042ff2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[2]=tmp;
goto P_0c042ff4;
P_0c042ff4: /* original 3320, guest PC 0x0c042ff4 */
if(!s->budget--) { s->failed_pc=0x0c042ff4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c042ff6;
P_0c042ff6: /* original 8f04, guest PC 0x0c042ff6 */
if(!s->budget--) { s->failed_pc=0x0c042ff6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043002; }
goto P_0c042ffa;
P_0c042ff8: /* original 0009, guest PC 0x0c042ff8 */
if(!s->budget--) { s->failed_pc=0x0c042ff8u; return 0; }
goto P_0c042ffa;
P_0c042ffa: /* original 7501, guest PC 0x0c042ffa */
if(!s->budget--) { s->failed_pc=0x0c042ffau; return 0; }
r[5]+=0x00000001u;
goto P_0c042ffc;
P_0c042ffc: /* original 3562, guest PC 0x0c042ffc */
if(!s->budget--) { s->failed_pc=0x0c042ffcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c042ffe;
P_0c042ffe: /* original 8ff7, guest PC 0x0c042ffe */
if(!s->budget--) { s->failed_pc=0x0c042ffeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042ff0; }
goto P_0c043002;
P_0c043000: /* original 0009, guest PC 0x0c043000 */
if(!s->budget--) { s->failed_pc=0x0c043000u; return 0; }
goto P_0c043002;
P_0c043002: /* original 6043, guest PC 0x0c043002 */
if(!s->budget--) { s->failed_pc=0x0c043002u; return 0; }
r[0]=r[4];
goto P_0c043004;
P_0c043004: /* original 0009, guest PC 0x0c043004 */
if(!s->budget--) { s->failed_pc=0x0c043004u; return 0; }
goto P_0c043006;
P_0c043006: /* original 70ff, guest PC 0x0c043006 */
if(!s->budget--) { s->failed_pc=0x0c043006u; return 0; }
r[0]+=0xffffffffu;
goto P_0c043008;
P_0c043008: /* original 6000, guest PC 0x0c043008 */
if(!s->budget--) { s->failed_pc=0x0c043008u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]=tmp;
goto P_0c04300a;
P_0c04300a: /* original 77ff, guest PC 0x0c04300a */
if(!s->budget--) { s->failed_pc=0x0c04300au; return 0; }
r[7]+=0xffffffffu;
goto P_0c04300c;
P_0c04300c: /* original 6370, guest PC 0x0c04300c */
if(!s->budget--) { s->failed_pc=0x0c04300cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[3]=tmp;
goto P_0c04300e;
P_0c04300e: /* original 600c, guest PC 0x0c04300e */
if(!s->budget--) { s->failed_pc=0x0c04300eu; return 0; }
r[0]=r[0]&255u;
goto P_0c043010;
P_0c043010: /* original 633c, guest PC 0x0c043010 */
if(!s->budget--) { s->failed_pc=0x0c043010u; return 0; }
r[3]=r[3]&255u;
goto P_0c043012;
P_0c043012: /* original 3038, guest PC 0x0c043012 */
if(!s->budget--) { s->failed_pc=0x0c043012u; return 0; }
r[0]-=r[3];
goto P_0c043014;
P_0c043014: /* original 000b, guest PC 0x0c043014 */
if(!s->budget--) { s->failed_pc=0x0c043014u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043016: /* original 0009, guest PC 0x0c043016 */
if(!s->budget--) { s->failed_pc=0x0c043016u; return 0; }
return vf3_matrix_family(0x0c043018u,s,ram);
P_0c04bc8c: /* original 2fe6, guest PC 0x0c04bc8c */
if(!s->budget--) { s->failed_pc=0x0c04bc8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bc8e;
P_0c04bc8e: /* original 4f22, guest PC 0x0c04bc8e */
if(!s->budget--) { s->failed_pc=0x0c04bc8eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bc90;
P_0c04bc90: /* original 9e83, guest PC 0x0c04bc90 */
if(!s->budget--) { s->failed_pc=0x0c04bc90u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bd9au,2);
goto P_0c04bc92;
P_0c04bc92: /* original 9383, guest PC 0x0c04bc92 */
if(!s->budget--) { s->failed_pc=0x0c04bc92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bd9cu,2);
goto P_0c04bc94;
P_0c04bc94: /* original 4f12, guest PC 0x0c04bc94 */
if(!s->budget--) { s->failed_pc=0x0c04bc94u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04bc96;
P_0c04bc96: /* original 25ef, guest PC 0x0c04bc96 */
if(!s->budget--) { s->failed_pc=0x0c04bc96u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[14]);
goto P_0c04bc98;
P_0c04bc98: /* original 334c, guest PC 0x0c04bc98 */
if(!s->budget--) { s->failed_pc=0x0c04bc98u; return 0; }
r[3]+=r[4];
goto P_0c04bc9a;
P_0c04bc9a: /* original 0e1a, guest PC 0x0c04bc9a */
if(!s->budget--) { s->failed_pc=0x0c04bc9au; return 0; }
r[14]=r[19];
goto P_0c04bc9c;
P_0c04bc9c: /* original 6eef, guest PC 0x0c04bc9c */
if(!s->budget--) { s->failed_pc=0x0c04bc9cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04bc9e;
P_0c04bc9e: /* original 3e3c, guest PC 0x0c04bc9e */
if(!s->budget--) { s->failed_pc=0x0c04bc9eu; return 0; }
r[14]+=r[3];
goto P_0c04bca0;
P_0c04bca0: /* original 50e3, guest PC 0x0c04bca0 */
if(!s->budget--) { s->failed_pc=0x0c04bca0u; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c04bca2;
P_0c04bca2: /* original 8801, guest PC 0x0c04bca2 */
if(!s->budget--) { s->failed_pc=0x0c04bca2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04bca4;
P_0c04bca4: /* original 8b05, guest PC 0x0c04bca4 */
if(!s->budget--) { s->failed_pc=0x0c04bca4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bcb2; }
goto P_0c04bca6;
P_0c04bca6: /* original b02b, guest PC 0x0c04bca6 */
if(!s->budget--) { s->failed_pc=0x0c04bca6u; return 0; }
target=0x0c04bd00u; r[16]=0x0c04bcaau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bcaau) { target=s->pc; goto dispatch; }
goto P_0c04bcaa;
P_0c04bca8: /* original 0009, guest PC 0x0c04bca8 */
if(!s->budget--) { s->failed_pc=0x0c04bca8u; return 0; }
goto P_0c04bcaa;
P_0c04bcaa: /* original e202, guest PC 0x0c04bcaa */
if(!s->budget--) { s->failed_pc=0x0c04bcaau; return 0; }
r[2]=0x00000002u;
goto P_0c04bcac;
P_0c04bcac: /* original 1e23, guest PC 0x0c04bcac */
if(!s->budget--) { s->failed_pc=0x0c04bcacu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c04bcae;
P_0c04bcae: /* original a001, guest PC 0x0c04bcae */
if(!s->budget--) { s->failed_pc=0x0c04bcaeu; return 0; }
r[0]=0x00000000u;
goto P_0c04bcb4;
P_0c04bcb0: /* original e000, guest PC 0x0c04bcb0 */
if(!s->budget--) { s->failed_pc=0x0c04bcb0u; return 0; }
r[0]=0x00000000u;
goto P_0c04bcb2;
P_0c04bcb2: /* original e0ff, guest PC 0x0c04bcb2 */
if(!s->budget--) { s->failed_pc=0x0c04bcb2u; return 0; }
r[0]=0xffffffffu;
goto P_0c04bcb4;
P_0c04bcb4: /* original 4f16, guest PC 0x0c04bcb4 */
if(!s->budget--) { s->failed_pc=0x0c04bcb4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bcb6;
P_0c04bcb6: /* original 4f26, guest PC 0x0c04bcb6 */
if(!s->budget--) { s->failed_pc=0x0c04bcb6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bcb8;
P_0c04bcb8: /* original 000b, guest PC 0x0c04bcb8 */
if(!s->budget--) { s->failed_pc=0x0c04bcb8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bcba: /* original 6ef6, guest PC 0x0c04bcba */
if(!s->budget--) { s->failed_pc=0x0c04bcbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04bcbcu,s,ram);
P_0c04bcc6: /* original 4f22, guest PC 0x0c04bcc6 */
if(!s->budget--) { s->failed_pc=0x0c04bcc6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bcc8;
P_0c04bcc8: /* original 7ffc, guest PC 0x0c04bcc8 */
if(!s->budget--) { s->failed_pc=0x0c04bcc8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04bcca;
P_0c04bcca: /* original 2f52, guest PC 0x0c04bcca */
if(!s->budget--) { s->failed_pc=0x0c04bccau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04bccc;
P_0c04bccc: /* original 9e66, guest PC 0x0c04bccc */
if(!s->budget--) { s->failed_pc=0x0c04bcccu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bd9cu,2);
goto P_0c04bcce;
P_0c04bcce: /* original a00d, guest PC 0x0c04bcce */
if(!s->budget--) { s->failed_pc=0x0c04bcceu; return 0; }
r[14]+=r[12];
goto P_0c04bcec;
P_0c04bcd0: /* original 3ecc, guest PC 0x0c04bcd0 */
if(!s->budget--) { s->failed_pc=0x0c04bcd0u; return 0; }
r[14]+=r[12];
goto P_0c04bcd2;
P_0c04bcd2: /* original 52e3, guest PC 0x0c04bcd2 */
if(!s->budget--) { s->failed_pc=0x0c04bcd2u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c04bcd4;
P_0c04bcd4: /* original 2228, guest PC 0x0c04bcd4 */
if(!s->budget--) { s->failed_pc=0x0c04bcd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04bcd6;
P_0c04bcd6: /* original 8906, guest PC 0x0c04bcd6 */
if(!s->budget--) { s->failed_pc=0x0c04bcd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bce6; }
goto P_0c04bcd8;
P_0c04bcd8: /* original 53e4, guest PC 0x0c04bcd8 */
if(!s->budget--) { s->failed_pc=0x0c04bcd8u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c04bcda;
P_0c04bcda: /* original 62f2, guest PC 0x0c04bcda */
if(!s->budget--) { s->failed_pc=0x0c04bcdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04bcdc;
P_0c04bcdc: /* original 3327, guest PC 0x0c04bcdc */
if(!s->budget--) { s->failed_pc=0x0c04bcdcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c04bcde;
P_0c04bcde: /* original 8902, guest PC 0x0c04bcde */
if(!s->budget--) { s->failed_pc=0x0c04bcdeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bce6; }
goto P_0c04bce0;
P_0c04bce0: /* original 65d3, guest PC 0x0c04bce0 */
if(!s->budget--) { s->failed_pc=0x0c04bce0u; return 0; }
r[5]=r[13];
goto P_0c04bce2;
P_0c04bce2: /* original bfd3, guest PC 0x0c04bce2 */
if(!s->budget--) { s->failed_pc=0x0c04bce2u; return 0; }
target=0x0c04bc8cu; r[16]=0x0c04bce6u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bce6u) { target=s->pc; goto dispatch; }
goto P_0c04bce6;
P_0c04bce4: /* original 64c3, guest PC 0x0c04bce4 */
if(!s->budget--) { s->failed_pc=0x0c04bce4u; return 0; }
r[4]=r[12];
goto P_0c04bce6;
P_0c04bce6: /* original 9258, guest PC 0x0c04bce6 */
if(!s->budget--) { s->failed_pc=0x0c04bce6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bd9au,2);
goto P_0c04bce8;
P_0c04bce8: /* original 7d01, guest PC 0x0c04bce8 */
if(!s->budget--) { s->failed_pc=0x0c04bce8u; return 0; }
r[13]+=0x00000001u;
goto P_0c04bcea;
P_0c04bcea: /* original 3e2c, guest PC 0x0c04bcea */
if(!s->budget--) { s->failed_pc=0x0c04bceau; return 0; }
r[14]+=r[2];
goto P_0c04bcec;
P_0c04bcec: /* original 9057, guest PC 0x0c04bcec */
if(!s->budget--) { s->failed_pc=0x0c04bcecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bd9eu,2);
goto P_0c04bcee;
P_0c04bcee: /* original 03ce, guest PC 0x0c04bcee */
if(!s->budget--) { s->failed_pc=0x0c04bceeu; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c04bcf0;
P_0c04bcf0: /* original 3d33, guest PC 0x0c04bcf0 */
if(!s->budget--) { s->failed_pc=0x0c04bcf0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c04bcf2;
P_0c04bcf2: /* original 8bee, guest PC 0x0c04bcf2 */
if(!s->budget--) { s->failed_pc=0x0c04bcf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bcd2; }
goto P_0c04bcf4;
P_0c04bcf4: /* original 7f04, guest PC 0x0c04bcf4 */
if(!s->budget--) { s->failed_pc=0x0c04bcf4u; return 0; }
r[15]+=0x00000004u;
goto P_0c04bcf6;
P_0c04bcf6: /* original 4f26, guest PC 0x0c04bcf6 */
if(!s->budget--) { s->failed_pc=0x0c04bcf6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bcf8;
P_0c04bcf8: /* original 6cf6, guest PC 0x0c04bcf8 */
if(!s->budget--) { s->failed_pc=0x0c04bcf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bcfa;
P_0c04bcfa: /* original 6df6, guest PC 0x0c04bcfa */
if(!s->budget--) { s->failed_pc=0x0c04bcfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04bcfc;
P_0c04bcfc: /* original 000b, guest PC 0x0c04bcfc */
if(!s->budget--) { s->failed_pc=0x0c04bcfcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bcfe: /* original 6ef6, guest PC 0x0c04bcfe */
if(!s->budget--) { s->failed_pc=0x0c04bcfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04bd00;
P_0c04bd00: /* original 924b, guest PC 0x0c04bd00 */
if(!s->budget--) { s->failed_pc=0x0c04bd00u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bd9au,2);
goto P_0c04bd02;
P_0c04bd02: /* original 4f12, guest PC 0x0c04bd02 */
if(!s->budget--) { s->failed_pc=0x0c04bd02u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04bd04;
P_0c04bd04: /* original 252f, guest PC 0x0c04bd04 */
if(!s->budget--) { s->failed_pc=0x0c04bd04u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[2]);
goto P_0c04bd06;
P_0c04bd06: /* original 9349, guest PC 0x0c04bd06 */
if(!s->budget--) { s->failed_pc=0x0c04bd06u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bd9cu,2);
goto P_0c04bd08;
P_0c04bd08: /* original 334c, guest PC 0x0c04bd08 */
if(!s->budget--) { s->failed_pc=0x0c04bd08u; return 0; }
r[3]+=r[4];
goto P_0c04bd0a;
P_0c04bd0a: /* original 051a, guest PC 0x0c04bd0a */
if(!s->budget--) { s->failed_pc=0x0c04bd0au; return 0; }
r[5]=r[19];
goto P_0c04bd0c;
P_0c04bd0c: /* original 655f, guest PC 0x0c04bd0c */
if(!s->budget--) { s->failed_pc=0x0c04bd0cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c04bd0e;
P_0c04bd0e: /* original 353c, guest PC 0x0c04bd0e */
if(!s->budget--) { s->failed_pc=0x0c04bd0eu; return 0; }
r[5]+=r[3];
goto P_0c04bd10;
P_0c04bd10: /* original 5153, guest PC 0x0c04bd10 */
if(!s->budget--) { s->failed_pc=0x0c04bd10u; return 0; }
r[1]=read(ram,r[5]+12,4);
goto P_0c04bd12;
P_0c04bd12: /* original 2118, guest PC 0x0c04bd12 */
if(!s->budget--) { s->failed_pc=0x0c04bd12u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04bd14;
P_0c04bd14: /* original 8902, guest PC 0x0c04bd14 */
if(!s->budget--) { s->failed_pc=0x0c04bd14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bd1c; }
goto P_0c04bd16;
P_0c04bd16: /* original 9043, guest PC 0x0c04bd16 */
if(!s->budget--) { s->failed_pc=0x0c04bd16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bda0u,2);
goto P_0c04bd18;
P_0c04bd18: /* original 014e, guest PC 0x0c04bd18 */
if(!s->budget--) { s->failed_pc=0x0c04bd18u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c04bd1a;
P_0c04bd1a: /* original 1515, guest PC 0x0c04bd1a */
if(!s->budget--) { s->failed_pc=0x0c04bd1au; return 0; }
write(ram,r[5]+20,r[1],4);
goto P_0c04bd1c;
P_0c04bd1c: /* original 000b, guest PC 0x0c04bd1c */
if(!s->budget--) { s->failed_pc=0x0c04bd1cu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04bd1e: /* original 4f16, guest PC 0x0c04bd1e */
if(!s->budget--) { s->failed_pc=0x0c04bd1eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c04bd20u,s,ram);
P_0c076b3c: /* original e600, guest PC 0x0c076b3c */
if(!s->budget--) { s->failed_pc=0x0c076b3cu; return 0; }
r[6]=0x00000000u;
goto P_0c076b3e;
P_0c076b3e: /* original 7ffc, guest PC 0x0c076b3e */
if(!s->budget--) { s->failed_pc=0x0c076b3eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c076b40;
P_0c076b40: /* original 6344, guest PC 0x0c076b40 */
if(!s->budget--) { s->failed_pc=0x0c076b40u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[3]=tmp;
goto P_0c076b42;
P_0c076b42: /* original 6763, guest PC 0x0c076b42 */
if(!s->budget--) { s->failed_pc=0x0c076b42u; return 0; }
r[7]=r[6];
goto P_0c076b44;
P_0c076b44: /* original 4719, guest PC 0x0c076b44 */
if(!s->budget--) { s->failed_pc=0x0c076b44u; return 0; }
r[7]>>=8;
goto P_0c076b46;
P_0c076b46: /* original 633c, guest PC 0x0c076b46 */
if(!s->budget--) { s->failed_pc=0x0c076b46u; return 0; }
r[3]=r[3]&255u;
goto P_0c076b48;
P_0c076b48: /* original 273a, guest PC 0x0c076b48 */
if(!s->budget--) { s->failed_pc=0x0c076b48u; return 0; }
r[7]^=r[3];
goto P_0c076b4a;
P_0c076b4a: /* original 2f32, guest PC 0x0c076b4a */
if(!s->budget--) { s->failed_pc=0x0c076b4au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c076b4c;
P_0c076b4c: /* original 677c, guest PC 0x0c076b4c */
if(!s->budget--) { s->failed_pc=0x0c076b4cu; return 0; }
r[7]=r[7]&255u;
goto P_0c076b4e;
P_0c076b4e: /* original d006, guest PC 0x0c076b4e */
if(!s->budget--) { s->failed_pc=0x0c076b4eu; return 0; }
r[0]=read(ram,0x0c076b68u,4);
goto P_0c076b50;
P_0c076b50: /* original 4700, guest PC 0x0c076b50 */
if(!s->budget--) { s->failed_pc=0x0c076b50u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c076b52;
P_0c076b52: /* original 4700, guest PC 0x0c076b52 */
if(!s->budget--) { s->failed_pc=0x0c076b52u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c076b54;
P_0c076b54: /* original 027d, guest PC 0x0c076b54 */
if(!s->budget--) { s->failed_pc=0x0c076b54u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+r[0],2);
goto P_0c076b56;
P_0c076b56: /* original 4510, guest PC 0x0c076b56 */
if(!s->budget--) { s->failed_pc=0x0c076b56u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c076b58;
P_0c076b58: /* original 4618, guest PC 0x0c076b58 */
if(!s->budget--) { s->failed_pc=0x0c076b58u; return 0; }
r[6]<<=8;
goto P_0c076b5a;
P_0c076b5a: /* original 672d, guest PC 0x0c076b5a */
if(!s->budget--) { s->failed_pc=0x0c076b5au; return 0; }
r[7]=r[2]&65535u;
goto P_0c076b5c;
P_0c076b5c: /* original 8ff0, guest PC 0x0c076b5c */
if(!s->budget--) { s->failed_pc=0x0c076b5cu; return 0; }
cond=r[17]&1u;
r[6]^=r[7];
if(!cond) { goto P_0c076b40; }
goto P_0c076b60;
P_0c076b5e: /* original 267a, guest PC 0x0c076b5e */
if(!s->budget--) { s->failed_pc=0x0c076b5eu; return 0; }
r[6]^=r[7];
goto P_0c076b60;
P_0c076b60: /* original 606d, guest PC 0x0c076b60 */
if(!s->budget--) { s->failed_pc=0x0c076b60u; return 0; }
r[0]=r[6]&65535u;
goto P_0c076b62;
P_0c076b62: /* original 000b, guest PC 0x0c076b62 */
if(!s->budget--) { s->failed_pc=0x0c076b62u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c076b64: /* original 7f04, guest PC 0x0c076b64 */
if(!s->budget--) { s->failed_pc=0x0c076b64u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c076b66u,s,ram);
P_0c0819fa: /* original 4f22, guest PC 0x0c0819fa */
if(!s->budget--) { s->failed_pc=0x0c0819fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0819fc;
P_0c0819fc: /* original 02dc, guest PC 0x0c0819fc */
if(!s->budget--) { s->failed_pc=0x0c0819fcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0819fe;
P_0c0819fe: /* original 7ffc, guest PC 0x0c0819fe */
if(!s->budget--) { s->failed_pc=0x0c0819feu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c081a00;
P_0c081a00: /* original 2f20, guest PC 0x0c081a00 */
if(!s->budget--) { s->failed_pc=0x0c081a00u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c081a02;
P_0c081a02: /* original da4c, guest PC 0x0c081a02 */
if(!s->budget--) { s->failed_pc=0x0c081a02u; return 0; }
r[10]=read(ram,0x0c081b34u,4);
goto P_0c081a04;
P_0c081a04: /* original 9b90, guest PC 0x0c081a04 */
if(!s->budget--) { s->failed_pc=0x0c081a04u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081b28u,2);
goto P_0c081a06;
P_0c081a06: /* original 60c3, guest PC 0x0c081a06 */
if(!s->budget--) { s->failed_pc=0x0c081a06u; return 0; }
r[0]=r[12];
goto P_0c081a08;
P_0c081a08: /* original 0eac, guest PC 0x0c081a08 */
if(!s->budget--) { s->failed_pc=0x0c081a08u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c081a0a;
P_0c081a0a: /* original 63ec, guest PC 0x0c081a0a */
if(!s->budget--) { s->failed_pc=0x0c081a0au; return 0; }
r[3]=r[14]&255u;
goto P_0c081a0c;
P_0c081a0c: /* original 33b0, guest PC 0x0c081a0c */
if(!s->budget--) { s->failed_pc=0x0c081a0cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c081a0e;
P_0c081a0e: /* original 8905, guest PC 0x0c081a0e */
if(!s->budget--) { s->failed_pc=0x0c081a0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081a1c; }
goto P_0c081a10;
P_0c081a10: /* original 65e3, guest PC 0x0c081a10 */
if(!s->budget--) { s->failed_pc=0x0c081a10u; return 0; }
r[5]=r[14];
goto P_0c081a12;
P_0c081a12: /* original 66f3, guest PC 0x0c081a12 */
if(!s->budget--) { s->failed_pc=0x0c081a12u; return 0; }
r[6]=r[15];
goto P_0c081a14;
P_0c081a14: /* original b00d, guest PC 0x0c081a14 */
if(!s->budget--) { s->failed_pc=0x0c081a14u; return 0; }
target=0x0c081a32u; r[16]=0x0c081a18u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081a18u) { target=s->pc; goto dispatch; }
goto P_0c081a18;
P_0c081a16: /* original 64d3, guest PC 0x0c081a16 */
if(!s->budget--) { s->failed_pc=0x0c081a16u; return 0; }
r[4]=r[13];
goto P_0c081a18;
P_0c081a18: /* original aff5, guest PC 0x0c081a18 */
if(!s->budget--) { s->failed_pc=0x0c081a18u; return 0; }
r[12]+=0x00000001u;
goto P_0c081a06;
P_0c081a1a: /* original 7c01, guest PC 0x0c081a1a */
if(!s->budget--) { s->failed_pc=0x0c081a1au; return 0; }
r[12]+=0x00000001u;
goto P_0c081a1c;
P_0c081a1c: /* original 62f0, guest PC 0x0c081a1c */
if(!s->budget--) { s->failed_pc=0x0c081a1cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c081a1e;
P_0c081a1e: /* original 7f04, guest PC 0x0c081a1e */
if(!s->budget--) { s->failed_pc=0x0c081a1eu; return 0; }
r[15]+=0x00000004u;
goto P_0c081a20;
P_0c081a20: /* original 4f26, guest PC 0x0c081a20 */
if(!s->budget--) { s->failed_pc=0x0c081a20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081a22;
P_0c081a22: /* original 9080, guest PC 0x0c081a22 */
if(!s->budget--) { s->failed_pc=0x0c081a22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081b26u,2);
goto P_0c081a24;
P_0c081a24: /* original 0d24, guest PC 0x0c081a24 */
if(!s->budget--) { s->failed_pc=0x0c081a24u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c081a26;
P_0c081a26: /* original 6af6, guest PC 0x0c081a26 */
if(!s->budget--) { s->failed_pc=0x0c081a26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081a28;
P_0c081a28: /* original 6bf6, guest PC 0x0c081a28 */
if(!s->budget--) { s->failed_pc=0x0c081a28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c081a2a;
P_0c081a2a: /* original 6cf6, guest PC 0x0c081a2a */
if(!s->budget--) { s->failed_pc=0x0c081a2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c081a2c;
P_0c081a2c: /* original 6df6, guest PC 0x0c081a2c */
if(!s->budget--) { s->failed_pc=0x0c081a2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c081a2e;
P_0c081a2e: /* original 000b, guest PC 0x0c081a2e */
if(!s->budget--) { s->failed_pc=0x0c081a2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081a30: /* original 6ef6, guest PC 0x0c081a30 */
if(!s->budget--) { s->failed_pc=0x0c081a30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c081a32u,s,ram);
P_0c095724: /* original 2fe6, guest PC 0x0c095724 */
if(!s->budget--) { s->failed_pc=0x0c095724u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c095726;
P_0c095726: /* original 4f22, guest PC 0x0c095726 */
if(!s->budget--) { s->failed_pc=0x0c095726u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095728;
P_0c095728: /* original 7ffc, guest PC 0x0c095728 */
if(!s->budget--) { s->failed_pc=0x0c095728u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09572a;
P_0c09572a: /* original 2f42, guest PC 0x0c09572a */
if(!s->budget--) { s->failed_pc=0x0c09572au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09572c;
P_0c09572c: /* original d31a, guest PC 0x0c09572c */
if(!s->budget--) { s->failed_pc=0x0c09572cu; return 0; }
r[3]=read(ram,0x0c095798u,4);
goto P_0c09572e;
P_0c09572e: /* original 942c, guest PC 0x0c09572e */
if(!s->budget--) { s->failed_pc=0x0c09572eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09578au,2);
goto P_0c095730;
P_0c095730: /* original de18, guest PC 0x0c095730 */
if(!s->budget--) { s->failed_pc=0x0c095730u; return 0; }
r[14]=read(ram,0x0c095794u,4);
goto P_0c095732;
P_0c095732: /* original 430b, guest PC 0x0c095732 */
if(!s->budget--) { s->failed_pc=0x0c095732u; return 0; }
target=r[3];
r[16]=0x0c095736u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095736u) { target=s->pc; goto dispatch; }
goto P_0c095736;
P_0c095734: /* original 65e3, guest PC 0x0c095734 */
if(!s->budget--) { s->failed_pc=0x0c095734u; return 0; }
r[5]=r[14];
goto P_0c095736;
P_0c095736: /* original 62f2, guest PC 0x0c095736 */
if(!s->budget--) { s->failed_pc=0x0c095736u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c095738;
P_0c095738: /* original 2228, guest PC 0x0c095738 */
if(!s->budget--) { s->failed_pc=0x0c095738u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09573a;
P_0c09573a: /* original 8901, guest PC 0x0c09573a */
if(!s->budget--) { s->failed_pc=0x0c09573au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095740; }
goto P_0c09573c;
P_0c09573c: /* original a001, guest PC 0x0c09573c */
if(!s->budget--) { s->failed_pc=0x0c09573cu; return 0; }
r[4]=0x00000001u;
goto P_0c095742;
P_0c09573e: /* original e401, guest PC 0x0c09573e */
if(!s->budget--) { s->failed_pc=0x0c09573eu; return 0; }
r[4]=0x00000001u;
goto P_0c095740;
P_0c095740: /* original e400, guest PC 0x0c095740 */
if(!s->budget--) { s->failed_pc=0x0c095740u; return 0; }
r[4]=0x00000000u;
goto P_0c095742;
P_0c095742: /* original 4e0b, guest PC 0x0c095742 */
if(!s->budget--) { s->failed_pc=0x0c095742u; return 0; }
target=r[14];
r[16]=0x0c095746u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095746u) { target=s->pc; goto dispatch; }
goto P_0c095746;
P_0c095744: /* original 0009, guest PC 0x0c095744 */
if(!s->budget--) { s->failed_pc=0x0c095744u; return 0; }
goto P_0c095746;
P_0c095746: /* original 7f04, guest PC 0x0c095746 */
if(!s->budget--) { s->failed_pc=0x0c095746u; return 0; }
r[15]+=0x00000004u;
goto P_0c095748;
P_0c095748: /* original 4f26, guest PC 0x0c095748 */
if(!s->budget--) { s->failed_pc=0x0c095748u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09574a;
P_0c09574a: /* original 000b, guest PC 0x0c09574a */
if(!s->budget--) { s->failed_pc=0x0c09574au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09574c: /* original 6ef6, guest PC 0x0c09574c */
if(!s->budget--) { s->failed_pc=0x0c09574cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09574eu,s,ram);
P_0c09af6c: /* original 2fe6, guest PC 0x0c09af6c */
if(!s->budget--) { s->failed_pc=0x0c09af6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af6e;
P_0c09af6e: /* original 2fd6, guest PC 0x0c09af6e */
if(!s->budget--) { s->failed_pc=0x0c09af6eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af70;
P_0c09af70: /* original 2fc6, guest PC 0x0c09af70 */
if(!s->budget--) { s->failed_pc=0x0c09af70u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af72;
P_0c09af72: /* original 4f22, guest PC 0x0c09af72 */
if(!s->budget--) { s->failed_pc=0x0c09af72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09af74;
P_0c09af74: /* original d32c, guest PC 0x0c09af74 */
if(!s->budget--) { s->failed_pc=0x0c09af74u; return 0; }
r[3]=read(ram,0x0c09b028u,4);
goto P_0c09af76;
P_0c09af76: /* original 7ffc, guest PC 0x0c09af76 */
if(!s->budget--) { s->failed_pc=0x0c09af76u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09af78;
P_0c09af78: /* original 2f32, guest PC 0x0c09af78 */
if(!s->budget--) { s->failed_pc=0x0c09af78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09af7a;
P_0c09af7a: /* original dc2c, guest PC 0x0c09af7a */
if(!s->budget--) { s->failed_pc=0x0c09af7au; return 0; }
r[12]=read(ram,0x0c09b02cu,4);
goto P_0c09af7c;
P_0c09af7c: /* original dd2c, guest PC 0x0c09af7c */
if(!s->budget--) { s->failed_pc=0x0c09af7cu; return 0; }
r[13]=read(ram,0x0c09b030u,4);
goto P_0c09af7e;
P_0c09af7e: /* original 4d0b, guest PC 0x0c09af7e */
if(!s->budget--) { s->failed_pc=0x0c09af7eu; return 0; }
target=r[13];
r[16]=0x0c09af82u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09af82u) { target=s->pc; goto dispatch; }
goto P_0c09af82;
P_0c09af80: /* original e400, guest PC 0x0c09af80 */
if(!s->budget--) { s->failed_pc=0x0c09af80u; return 0; }
r[4]=0x00000000u;
goto P_0c09af82;
P_0c09af82: /* original 6403, guest PC 0x0c09af82 */
if(!s->budget--) { s->failed_pc=0x0c09af82u; return 0; }
r[4]=r[0];
goto P_0c09af84;
P_0c09af84: /* original 5e42, guest PC 0x0c09af84 */
if(!s->budget--) { s->failed_pc=0x0c09af84u; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09af86;
P_0c09af86: /* original 53c2, guest PC 0x0c09af86 */
if(!s->budget--) { s->failed_pc=0x0c09af86u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c09af88;
P_0c09af88: /* original d42a, guest PC 0x0c09af88 */
if(!s->budget--) { s->failed_pc=0x0c09af88u; return 0; }
r[4]=read(ram,0x0c09b034u,4);
goto P_0c09af8a;
P_0c09af8a: /* original 2349, guest PC 0x0c09af8a */
if(!s->budget--) { s->failed_pc=0x0c09af8au; return 0; }
r[3]&=r[4];
goto P_0c09af8c;
P_0c09af8c: /* original 3340, guest PC 0x0c09af8c */
if(!s->budget--) { s->failed_pc=0x0c09af8cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c09af8e;
P_0c09af8e: /* original 8b05, guest PC 0x0c09af8e */
if(!s->budget--) { s->failed_pc=0x0c09af8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09af9c; }
goto P_0c09af90;
P_0c09af90: /* original 4d0b, guest PC 0x0c09af90 */
if(!s->budget--) { s->failed_pc=0x0c09af90u; return 0; }
target=r[13];
r[16]=0x0c09af94u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09af94u) { target=s->pc; goto dispatch; }
goto P_0c09af94;
P_0c09af92: /* original e401, guest PC 0x0c09af92 */
if(!s->budget--) { s->failed_pc=0x0c09af92u; return 0; }
r[4]=0x00000001u;
goto P_0c09af94;
P_0c09af94: /* original 6403, guest PC 0x0c09af94 */
if(!s->budget--) { s->failed_pc=0x0c09af94u; return 0; }
r[4]=r[0];
goto P_0c09af96;
P_0c09af96: /* original 5342, guest PC 0x0c09af96 */
if(!s->budget--) { s->failed_pc=0x0c09af96u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09af98;
P_0c09af98: /* original a008, guest PC 0x0c09af98 */
if(!s->budget--) { s->failed_pc=0x0c09af98u; return 0; }
r[14]|=r[3];
goto P_0c09afac;
P_0c09af9a: /* original 2e3b, guest PC 0x0c09af9a */
if(!s->budget--) { s->failed_pc=0x0c09af9au; return 0; }
r[14]|=r[3];
goto P_0c09af9c;
P_0c09af9c: /* original 52c2, guest PC 0x0c09af9c */
if(!s->budget--) { s->failed_pc=0x0c09af9cu; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09af9e;
P_0c09af9e: /* original d326, guest PC 0x0c09af9e */
if(!s->budget--) { s->failed_pc=0x0c09af9eu; return 0; }
r[3]=read(ram,0x0c09b038u,4);
goto P_0c09afa0;
P_0c09afa0: /* original 2238, guest PC 0x0c09afa0 */
if(!s->budget--) { s->failed_pc=0x0c09afa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09afa2;
P_0c09afa2: /* original 8903, guest PC 0x0c09afa2 */
if(!s->budget--) { s->failed_pc=0x0c09afa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09afac; }
goto P_0c09afa4;
P_0c09afa4: /* original 4d0b, guest PC 0x0c09afa4 */
if(!s->budget--) { s->failed_pc=0x0c09afa4u; return 0; }
target=r[13];
r[16]=0x0c09afa8u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09afa8u) { target=s->pc; goto dispatch; }
goto P_0c09afa8;
P_0c09afa6: /* original e401, guest PC 0x0c09afa6 */
if(!s->budget--) { s->failed_pc=0x0c09afa6u; return 0; }
r[4]=0x00000001u;
goto P_0c09afa8;
P_0c09afa8: /* original 6403, guest PC 0x0c09afa8 */
if(!s->budget--) { s->failed_pc=0x0c09afa8u; return 0; }
r[4]=r[0];
goto P_0c09afaa;
P_0c09afaa: /* original 5e42, guest PC 0x0c09afaa */
if(!s->budget--) { s->failed_pc=0x0c09afaau; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09afac;
P_0c09afac: /* original 63f2, guest PC 0x0c09afac */
if(!s->budget--) { s->failed_pc=0x0c09afacu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09afae;
P_0c09afae: /* original 7f04, guest PC 0x0c09afae */
if(!s->budget--) { s->failed_pc=0x0c09afaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c09afb0;
P_0c09afb0: /* original 4f26, guest PC 0x0c09afb0 */
if(!s->budget--) { s->failed_pc=0x0c09afb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09afb2;
P_0c09afb2: /* original 9038, guest PC 0x0c09afb2 */
if(!s->budget--) { s->failed_pc=0x0c09afb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b026u,2);
goto P_0c09afb4;
P_0c09afb4: /* original 03e6, guest PC 0x0c09afb4 */
if(!s->budget--) { s->failed_pc=0x0c09afb4u; return 0; }
write(ram,r[3]+r[0],r[14],4);
goto P_0c09afb6;
P_0c09afb6: /* original 60e3, guest PC 0x0c09afb6 */
if(!s->budget--) { s->failed_pc=0x0c09afb6u; return 0; }
r[0]=r[14];
goto P_0c09afb8;
P_0c09afb8: /* original 6cf6, guest PC 0x0c09afb8 */
if(!s->budget--) { s->failed_pc=0x0c09afb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09afba;
P_0c09afba: /* original 6df6, guest PC 0x0c09afba */
if(!s->budget--) { s->failed_pc=0x0c09afbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09afbc;
P_0c09afbc: /* original 000b, guest PC 0x0c09afbc */
if(!s->budget--) { s->failed_pc=0x0c09afbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09afbe: /* original 6ef6, guest PC 0x0c09afbe */
if(!s->budget--) { s->failed_pc=0x0c09afbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09afc0u,s,ram);
P_0c09b926: /* original 4f22, guest PC 0x0c09b926 */
if(!s->budget--) { s->failed_pc=0x0c09b926u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b928;
P_0c09b928: /* original de12, guest PC 0x0c09b928 */
if(!s->budget--) { s->failed_pc=0x0c09b928u; return 0; }
r[14]=read(ram,0x0c09b974u,4);
goto P_0c09b92a;
P_0c09b92a: /* original bb1f, guest PC 0x0c09b92a */
if(!s->budget--) { s->failed_pc=0x0c09b92au; return 0; }
target=0x0c09af6cu; r[16]=0x0c09b92eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b92eu) { target=s->pc; goto dispatch; }
goto P_0c09b92e;
P_0c09b92c: /* original 0009, guest PC 0x0c09b92c */
if(!s->budget--) { s->failed_pc=0x0c09b92cu; return 0; }
goto P_0c09b92e;
P_0c09b92e: /* original e400, guest PC 0x0c09b92e */
if(!s->budget--) { s->failed_pc=0x0c09b92eu; return 0; }
r[4]=0x00000000u;
goto P_0c09b930;
P_0c09b930: /* original e07d, guest PC 0x0c09b930 */
if(!s->budget--) { s->failed_pc=0x0c09b930u; return 0; }
r[0]=0x0000007du;
goto P_0c09b932;
P_0c09b932: /* original 4f26, guest PC 0x0c09b932 */
if(!s->budget--) { s->failed_pc=0x0c09b932u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b934;
P_0c09b934: /* original e375, guest PC 0x0c09b934 */
if(!s->budget--) { s->failed_pc=0x0c09b934u; return 0; }
r[3]=0x00000075u;
goto P_0c09b936;
P_0c09b936: /* original e240, guest PC 0x0c09b936 */
if(!s->budget--) { s->failed_pc=0x0c09b936u; return 0; }
r[2]=0x00000040u;
goto P_0c09b938;
P_0c09b938: /* original 1e23, guest PC 0x0c09b938 */
if(!s->budget--) { s->failed_pc=0x0c09b938u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09b93a;
P_0c09b93a: /* original 1e46, guest PC 0x0c09b93a */
if(!s->budget--) { s->failed_pc=0x0c09b93au; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c09b93c;
P_0c09b93c: /* original 0e44, guest PC 0x0c09b93c */
if(!s->budget--) { s->failed_pc=0x0c09b93cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c09b93e;
P_0c09b93e: /* original 1e45, guest PC 0x0c09b93e */
if(!s->budget--) { s->failed_pc=0x0c09b93eu; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c09b940;
P_0c09b940: /* original 900b, guest PC 0x0c09b940 */
if(!s->budget--) { s->failed_pc=0x0c09b940u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b95au,2);
goto P_0c09b942;
P_0c09b942: /* original 0e46, guest PC 0x0c09b942 */
if(!s->budget--) { s->failed_pc=0x0c09b942u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b944;
P_0c09b944: /* original 70fc, guest PC 0x0c09b944 */
if(!s->budget--) { s->failed_pc=0x0c09b944u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b946;
P_0c09b946: /* original 0e46, guest PC 0x0c09b946 */
if(!s->budget--) { s->failed_pc=0x0c09b946u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b948;
P_0c09b948: /* original 84eb, guest PC 0x0c09b948 */
if(!s->budget--) { s->failed_pc=0x0c09b948u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09b94a;
P_0c09b94a: /* original 7001, guest PC 0x0c09b94a */
if(!s->budget--) { s->failed_pc=0x0c09b94au; return 0; }
r[0]+=0x00000001u;
goto P_0c09b94c;
P_0c09b94c: /* original 80eb, guest PC 0x0c09b94c */
if(!s->budget--) { s->failed_pc=0x0c09b94cu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b94e;
P_0c09b94e: /* original e010, guest PC 0x0c09b94e */
if(!s->budget--) { s->failed_pc=0x0c09b94eu; return 0; }
r[0]=0x00000010u;
goto P_0c09b950;
P_0c09b950: /* original 0e34, guest PC 0x0c09b950 */
if(!s->budget--) { s->failed_pc=0x0c09b950u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09b952;
P_0c09b952: /* original a011, guest PC 0x0c09b952 */
if(!s->budget--) { s->failed_pc=0x0c09b952u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09b978;
P_0c09b954: /* original 6ef6, guest PC 0x0c09b954 */
if(!s->budget--) { s->failed_pc=0x0c09b954u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09b956u,s,ram);
P_0c09b978: /* original 2fe6, guest PC 0x0c09b978 */
if(!s->budget--) { s->failed_pc=0x0c09b978u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b97a;
P_0c09b97a: /* original 2fd6, guest PC 0x0c09b97a */
if(!s->budget--) { s->failed_pc=0x0c09b97au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b97c;
P_0c09b97c: /* original 2fc6, guest PC 0x0c09b97c */
if(!s->budget--) { s->failed_pc=0x0c09b97cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b97e;
P_0c09b97e: /* original 2fb6, guest PC 0x0c09b97e */
if(!s->budget--) { s->failed_pc=0x0c09b97eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b980;
P_0c09b980: /* original 2fa6, guest PC 0x0c09b980 */
if(!s->budget--) { s->failed_pc=0x0c09b980u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b982;
P_0c09b982: /* original 4f22, guest PC 0x0c09b982 */
if(!s->budget--) { s->failed_pc=0x0c09b982u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b984;
P_0c09b984: /* original da3d, guest PC 0x0c09b984 */
if(!s->budget--) { s->failed_pc=0x0c09b984u; return 0; }
r[10]=read(ram,0x0c09ba7cu,4);
goto P_0c09b986;
P_0c09b986: /* original de3c, guest PC 0x0c09b986 */
if(!s->budget--) { s->failed_pc=0x0c09b986u; return 0; }
r[14]=read(ram,0x0c09ba78u,4);
goto P_0c09b988;
P_0c09b988: /* original baf0, guest PC 0x0c09b988 */
if(!s->budget--) { s->failed_pc=0x0c09b988u; return 0; }
target=0x0c09af6cu; r[16]=0x0c09b98cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b98cu) { target=s->pc; goto dispatch; }
goto P_0c09b98c;
P_0c09b98a: /* original 0009, guest PC 0x0c09b98a */
if(!s->budget--) { s->failed_pc=0x0c09b98au; return 0; }
goto P_0c09b98c;
P_0c09b98c: /* original 6d03, guest PC 0x0c09b98c */
if(!s->budget--) { s->failed_pc=0x0c09b98cu; return 0; }
r[13]=r[0];
goto P_0c09b98e;
P_0c09b98e: /* original e310, guest PC 0x0c09b98e */
if(!s->budget--) { s->failed_pc=0x0c09b98eu; return 0; }
r[3]=0x00000010u;
goto P_0c09b990;
P_0c09b990: /* original e07d, guest PC 0x0c09b990 */
if(!s->budget--) { s->failed_pc=0x0c09b990u; return 0; }
r[0]=0x0000007du;
goto P_0c09b992;
P_0c09b992: /* original e240, guest PC 0x0c09b992 */
if(!s->budget--) { s->failed_pc=0x0c09b992u; return 0; }
r[2]=0x00000040u;
goto P_0c09b994;
P_0c09b994: /* original eb00, guest PC 0x0c09b994 */
if(!s->budget--) { s->failed_pc=0x0c09b994u; return 0; }
r[11]=0x00000000u;
goto P_0c09b996;
P_0c09b996: /* original 1e23, guest PC 0x0c09b996 */
if(!s->budget--) { s->failed_pc=0x0c09b996u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09b998;
P_0c09b998: /* original 23d8, guest PC 0x0c09b998 */
if(!s->budget--) { s->failed_pc=0x0c09b998u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09b99a;
P_0c09b99a: /* original 1eb6, guest PC 0x0c09b99a */
if(!s->budget--) { s->failed_pc=0x0c09b99au; return 0; }
write(ram,r[14]+24,r[11],4);
goto P_0c09b99c;
P_0c09b99c: /* original 0eb4, guest PC 0x0c09b99c */
if(!s->budget--) { s->failed_pc=0x0c09b99cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09b99e;
P_0c09b99e: /* original dc38, guest PC 0x0c09b99e */
if(!s->budget--) { s->failed_pc=0x0c09b99eu; return 0; }
r[12]=read(ram,0x0c09ba80u,4);
goto P_0c09b9a0;
P_0c09b9a0: /* original 8d15, guest PC 0x0c09b9a0 */
if(!s->budget--) { s->failed_pc=0x0c09b9a0u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[11],4);
if(cond) { goto P_0c09b9ce; }
goto P_0c09b9a4;
P_0c09b9a2: /* original 1eb5, guest PC 0x0c09b9a2 */
if(!s->budget--) { s->failed_pc=0x0c09b9a2u; return 0; }
write(ram,r[14]+20,r[11],4);
goto P_0c09b9a4;
P_0c09b9a4: /* original 9463, guest PC 0x0c09b9a4 */
if(!s->budget--) { s->failed_pc=0x0c09b9a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba6eu,2);
goto P_0c09b9a6;
P_0c09b9a6: /* original 4c0b, guest PC 0x0c09b9a6 */
if(!s->budget--) { s->failed_pc=0x0c09b9a6u; return 0; }
target=r[12];
r[16]=0x0c09b9aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b9aau) { target=s->pc; goto dispatch; }
goto P_0c09b9aa;
P_0c09b9a8: /* original 0009, guest PC 0x0c09b9a8 */
if(!s->budget--) { s->failed_pc=0x0c09b9a8u; return 0; }
goto P_0c09b9aa;
P_0c09b9aa: /* original 9061, guest PC 0x0c09b9aa */
if(!s->budget--) { s->failed_pc=0x0c09b9aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba70u,2);
goto P_0c09b9ac;
P_0c09b9ac: /* original 03ee, guest PC 0x0c09b9ac */
if(!s->budget--) { s->failed_pc=0x0c09b9acu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b9ae;
P_0c09b9ae: /* original 73ff, guest PC 0x0c09b9ae */
if(!s->budget--) { s->failed_pc=0x0c09b9aeu; return 0; }
r[3]+=0xffffffffu;
goto P_0c09b9b0;
P_0c09b9b0: /* original 0e36, guest PC 0x0c09b9b0 */
if(!s->budget--) { s->failed_pc=0x0c09b9b0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b9b2;
P_0c09b9b2: /* original 02ee, guest PC 0x0c09b9b2 */
if(!s->budget--) { s->failed_pc=0x0c09b9b2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b9b4;
P_0c09b9b4: /* original 4211, guest PC 0x0c09b9b4 */
if(!s->budget--) { s->failed_pc=0x0c09b9b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09b9b6;
P_0c09b9b6: /* original 8901, guest PC 0x0c09b9b6 */
if(!s->budget--) { s->failed_pc=0x0c09b9b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b9bc; }
goto P_0c09b9b8;
P_0c09b9b8: /* original e102, guest PC 0x0c09b9b8 */
if(!s->budget--) { s->failed_pc=0x0c09b9b8u; return 0; }
r[1]=0x00000002u;
goto P_0c09b9ba;
P_0c09b9ba: /* original 0e16, guest PC 0x0c09b9ba */
if(!s->budget--) { s->failed_pc=0x0c09b9bau; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09b9bc;
P_0c09b9bc: /* original 00ee, guest PC 0x0c09b9bc */
if(!s->budget--) { s->failed_pc=0x0c09b9bcu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b9be;
P_0c09b9be: /* original 8801, guest PC 0x0c09b9be */
if(!s->budget--) { s->failed_pc=0x0c09b9beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b9c0;
P_0c09b9c0: /* original 8b05, guest PC 0x0c09b9c0 */
if(!s->budget--) { s->failed_pc=0x0c09b9c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b9ce; }
goto P_0c09b9c2;
P_0c09b9c2: /* original 9056, guest PC 0x0c09b9c2 */
if(!s->budget--) { s->failed_pc=0x0c09b9c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba72u,2);
goto P_0c09b9c4;
P_0c09b9c4: /* original 02ae, guest PC 0x0c09b9c4 */
if(!s->budget--) { s->failed_pc=0x0c09b9c4u; return 0; }
r[2]=read(ram,r[10]+r[0],4);
goto P_0c09b9c6;
P_0c09b9c6: /* original 2228, guest PC 0x0c09b9c6 */
if(!s->budget--) { s->failed_pc=0x0c09b9c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09b9c8;
P_0c09b9c8: /* original 8b01, guest PC 0x0c09b9c8 */
if(!s->budget--) { s->failed_pc=0x0c09b9c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b9ce; }
goto P_0c09b9ca;
P_0c09b9ca: /* original 9051, guest PC 0x0c09b9ca */
if(!s->budget--) { s->failed_pc=0x0c09b9cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba70u,2);
goto P_0c09b9cc;
P_0c09b9cc: /* original 0eb6, guest PC 0x0c09b9cc */
if(!s->budget--) { s->failed_pc=0x0c09b9ccu; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b9ce;
P_0c09b9ce: /* original e320, guest PC 0x0c09b9ce */
if(!s->budget--) { s->failed_pc=0x0c09b9ceu; return 0; }
r[3]=0x00000020u;
goto P_0c09b9d0;
P_0c09b9d0: /* original 23d8, guest PC 0x0c09b9d0 */
if(!s->budget--) { s->failed_pc=0x0c09b9d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09b9d2;
P_0c09b9d2: /* original 8915, guest PC 0x0c09b9d2 */
if(!s->budget--) { s->failed_pc=0x0c09b9d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ba00; }
goto P_0c09b9d4;
P_0c09b9d4: /* original 904c, guest PC 0x0c09b9d4 */
if(!s->budget--) { s->failed_pc=0x0c09b9d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba70u,2);
goto P_0c09b9d6;
P_0c09b9d6: /* original 944a, guest PC 0x0c09b9d6 */
if(!s->budget--) { s->failed_pc=0x0c09b9d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba6eu,2);
goto P_0c09b9d8;
P_0c09b9d8: /* original 03ee, guest PC 0x0c09b9d8 */
if(!s->budget--) { s->failed_pc=0x0c09b9d8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b9da;
P_0c09b9da: /* original 7301, guest PC 0x0c09b9da */
if(!s->budget--) { s->failed_pc=0x0c09b9dau; return 0; }
r[3]+=0x00000001u;
goto P_0c09b9dc;
P_0c09b9dc: /* original 4c0b, guest PC 0x0c09b9dc */
if(!s->budget--) { s->failed_pc=0x0c09b9dcu; return 0; }
target=r[12];
r[16]=0x0c09b9e0u;
write(ram,r[14]+r[0],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b9e0u) { target=s->pc; goto dispatch; }
goto P_0c09b9e0;
P_0c09b9de: /* original 0e36, guest PC 0x0c09b9de */
if(!s->budget--) { s->failed_pc=0x0c09b9deu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b9e0;
P_0c09b9e0: /* original 9046, guest PC 0x0c09b9e0 */
if(!s->budget--) { s->failed_pc=0x0c09b9e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba70u,2);
goto P_0c09b9e2;
P_0c09b9e2: /* original e203, guest PC 0x0c09b9e2 */
if(!s->budget--) { s->failed_pc=0x0c09b9e2u; return 0; }
r[2]=0x00000003u;
goto P_0c09b9e4;
P_0c09b9e4: /* original 03ee, guest PC 0x0c09b9e4 */
if(!s->budget--) { s->failed_pc=0x0c09b9e4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b9e6;
P_0c09b9e6: /* original 3323, guest PC 0x0c09b9e6 */
if(!s->budget--) { s->failed_pc=0x0c09b9e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c09b9e8;
P_0c09b9e8: /* original 8b00, guest PC 0x0c09b9e8 */
if(!s->budget--) { s->failed_pc=0x0c09b9e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b9ec; }
goto P_0c09b9ea;
P_0c09b9ea: /* original 0eb6, guest PC 0x0c09b9ea */
if(!s->budget--) { s->failed_pc=0x0c09b9eau; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b9ec;
P_0c09b9ec: /* original 00ee, guest PC 0x0c09b9ec */
if(!s->budget--) { s->failed_pc=0x0c09b9ecu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b9ee;
P_0c09b9ee: /* original 8801, guest PC 0x0c09b9ee */
if(!s->budget--) { s->failed_pc=0x0c09b9eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b9f0;
P_0c09b9f0: /* original 8b06, guest PC 0x0c09b9f0 */
if(!s->budget--) { s->failed_pc=0x0c09b9f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ba00; }
goto P_0c09b9f2;
P_0c09b9f2: /* original 903e, guest PC 0x0c09b9f2 */
if(!s->budget--) { s->failed_pc=0x0c09b9f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba72u,2);
goto P_0c09b9f4;
P_0c09b9f4: /* original 02ae, guest PC 0x0c09b9f4 */
if(!s->budget--) { s->failed_pc=0x0c09b9f4u; return 0; }
r[2]=read(ram,r[10]+r[0],4);
goto P_0c09b9f6;
P_0c09b9f6: /* original 2228, guest PC 0x0c09b9f6 */
if(!s->budget--) { s->failed_pc=0x0c09b9f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09b9f8;
P_0c09b9f8: /* original 8b02, guest PC 0x0c09b9f8 */
if(!s->budget--) { s->failed_pc=0x0c09b9f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ba00; }
goto P_0c09b9fa;
P_0c09b9fa: /* original 9039, guest PC 0x0c09b9fa */
if(!s->budget--) { s->failed_pc=0x0c09b9fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba70u,2);
goto P_0c09b9fc;
P_0c09b9fc: /* original e202, guest PC 0x0c09b9fc */
if(!s->budget--) { s->failed_pc=0x0c09b9fcu; return 0; }
r[2]=0x00000002u;
goto P_0c09b9fe;
P_0c09b9fe: /* original 0e26, guest PC 0x0c09b9fe */
if(!s->budget--) { s->failed_pc=0x0c09b9feu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09ba00;
P_0c09ba00: /* original e304, guest PC 0x0c09ba00 */
if(!s->budget--) { s->failed_pc=0x0c09ba00u; return 0; }
r[3]=0x00000004u;
goto P_0c09ba02;
P_0c09ba02: /* original 23d8, guest PC 0x0c09ba02 */
if(!s->budget--) { s->failed_pc=0x0c09ba02u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ba04;
P_0c09ba04: /* original 891b, guest PC 0x0c09ba04 */
if(!s->budget--) { s->failed_pc=0x0c09ba04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ba3e; }
goto P_0c09ba06;
P_0c09ba06: /* original 9435, guest PC 0x0c09ba06 */
if(!s->budget--) { s->failed_pc=0x0c09ba06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba74u,2);
goto P_0c09ba08;
P_0c09ba08: /* original 4c0b, guest PC 0x0c09ba08 */
if(!s->budget--) { s->failed_pc=0x0c09ba08u; return 0; }
target=r[12];
r[16]=0x0c09ba0cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ba0cu) { target=s->pc; goto dispatch; }
goto P_0c09ba0c;
P_0c09ba0a: /* original 0009, guest PC 0x0c09ba0a */
if(!s->budget--) { s->failed_pc=0x0c09ba0au; return 0; }
goto P_0c09ba0c;
P_0c09ba0c: /* original 9030, guest PC 0x0c09ba0c */
if(!s->budget--) { s->failed_pc=0x0c09ba0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba70u,2);
goto P_0c09ba0e;
P_0c09ba0e: /* original 00ee, guest PC 0x0c09ba0e */
if(!s->budget--) { s->failed_pc=0x0c09ba0eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09ba10;
P_0c09ba10: /* original 8802, guest PC 0x0c09ba10 */
if(!s->budget--) { s->failed_pc=0x0c09ba10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09ba12;
P_0c09ba12: /* original 8b05, guest PC 0x0c09ba12 */
if(!s->budget--) { s->failed_pc=0x0c09ba12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ba20; }
goto P_0c09ba14;
P_0c09ba14: /* original e001, guest PC 0x0c09ba14 */
if(!s->budget--) { s->failed_pc=0x0c09ba14u; return 0; }
r[0]=0x00000001u;
goto P_0c09ba16;
P_0c09ba16: /* original 80eb, guest PC 0x0c09ba16 */
if(!s->budget--) { s->failed_pc=0x0c09ba16u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09ba18;
P_0c09ba18: /* original e010, guest PC 0x0c09ba18 */
if(!s->budget--) { s->failed_pc=0x0c09ba18u; return 0; }
r[0]=0x00000010u;
goto P_0c09ba1a;
P_0c09ba1a: /* original e372, guest PC 0x0c09ba1a */
if(!s->budget--) { s->failed_pc=0x0c09ba1au; return 0; }
r[3]=0x00000072u;
goto P_0c09ba1c;
P_0c09ba1c: /* original a00f, guest PC 0x0c09ba1c */
if(!s->budget--) { s->failed_pc=0x0c09ba1cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09ba3e;
P_0c09ba1e: /* original 0e34, guest PC 0x0c09ba1e */
if(!s->budget--) { s->failed_pc=0x0c09ba1eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09ba20;
P_0c09ba20: /* original 9026, guest PC 0x0c09ba20 */
if(!s->budget--) { s->failed_pc=0x0c09ba20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba70u,2);
goto P_0c09ba22;
P_0c09ba22: /* original 01ee, guest PC 0x0c09ba22 */
if(!s->budget--) { s->failed_pc=0x0c09ba22u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09ba24;
P_0c09ba24: /* original 2118, guest PC 0x0c09ba24 */
if(!s->budget--) { s->failed_pc=0x0c09ba24u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09ba26;
P_0c09ba26: /* original 8b04, guest PC 0x0c09ba26 */
if(!s->budget--) { s->failed_pc=0x0c09ba26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ba32; }
goto P_0c09ba28;
P_0c09ba28: /* original d316, guest PC 0x0c09ba28 */
if(!s->budget--) { s->failed_pc=0x0c09ba28u; return 0; }
r[3]=read(ram,0x0c09ba84u,4);
goto P_0c09ba2a;
P_0c09ba2a: /* original 430b, guest PC 0x0c09ba2a */
if(!s->budget--) { s->failed_pc=0x0c09ba2au; return 0; }
target=r[3];
r[16]=0x0c09ba2eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ba2eu) { target=s->pc; goto dispatch; }
goto P_0c09ba2e;
P_0c09ba2c: /* original e400, guest PC 0x0c09ba2c */
if(!s->budget--) { s->failed_pc=0x0c09ba2cu; return 0; }
r[4]=0x00000000u;
goto P_0c09ba2e;
P_0c09ba2e: /* original a006, guest PC 0x0c09ba2e */
if(!s->budget--) { s->failed_pc=0x0c09ba2eu; return 0; }
goto P_0c09ba3e;
P_0c09ba30: /* original 0009, guest PC 0x0c09ba30 */
if(!s->budget--) { s->failed_pc=0x0c09ba30u; return 0; }
goto P_0c09ba32;
P_0c09ba32: /* original 00ee, guest PC 0x0c09ba32 */
if(!s->budget--) { s->failed_pc=0x0c09ba32u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09ba34;
P_0c09ba34: /* original 8801, guest PC 0x0c09ba34 */
if(!s->budget--) { s->failed_pc=0x0c09ba34u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09ba36;
P_0c09ba36: /* original 8b02, guest PC 0x0c09ba36 */
if(!s->budget--) { s->failed_pc=0x0c09ba36u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ba3e; }
goto P_0c09ba38;
P_0c09ba38: /* original d212, guest PC 0x0c09ba38 */
if(!s->budget--) { s->failed_pc=0x0c09ba38u; return 0; }
r[2]=read(ram,0x0c09ba84u,4);
goto P_0c09ba3a;
P_0c09ba3a: /* original 420b, guest PC 0x0c09ba3a */
if(!s->budget--) { s->failed_pc=0x0c09ba3au; return 0; }
target=r[2];
r[16]=0x0c09ba3eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ba3eu) { target=s->pc; goto dispatch; }
goto P_0c09ba3e;
P_0c09ba3c: /* original e401, guest PC 0x0c09ba3c */
if(!s->budget--) { s->failed_pc=0x0c09ba3cu; return 0; }
r[4]=0x00000001u;
goto P_0c09ba3e;
P_0c09ba3e: /* original e30a, guest PC 0x0c09ba3e */
if(!s->budget--) { s->failed_pc=0x0c09ba3eu; return 0; }
r[3]=0x0000000au;
goto P_0c09ba40;
P_0c09ba40: /* original 23d8, guest PC 0x0c09ba40 */
if(!s->budget--) { s->failed_pc=0x0c09ba40u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ba42;
P_0c09ba42: /* original 890d, guest PC 0x0c09ba42 */
if(!s->budget--) { s->failed_pc=0x0c09ba42u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ba60; }
goto P_0c09ba44;
P_0c09ba44: /* original e108, guest PC 0x0c09ba44 */
if(!s->budget--) { s->failed_pc=0x0c09ba44u; return 0; }
r[1]=0x00000008u;
goto P_0c09ba46;
P_0c09ba46: /* original 2d18, guest PC 0x0c09ba46 */
if(!s->budget--) { s->failed_pc=0x0c09ba46u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[1])==0)!=0);
goto P_0c09ba48;
P_0c09ba48: /* original 8902, guest PC 0x0c09ba48 */
if(!s->budget--) { s->failed_pc=0x0c09ba48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ba50; }
goto P_0c09ba4a;
P_0c09ba4a: /* original 9413, guest PC 0x0c09ba4a */
if(!s->budget--) { s->failed_pc=0x0c09ba4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba74u,2);
goto P_0c09ba4c;
P_0c09ba4c: /* original a001, guest PC 0x0c09ba4c */
if(!s->budget--) { s->failed_pc=0x0c09ba4cu; return 0; }
goto P_0c09ba52;
P_0c09ba4e: /* original 0009, guest PC 0x0c09ba4e */
if(!s->budget--) { s->failed_pc=0x0c09ba4eu; return 0; }
goto P_0c09ba50;
P_0c09ba50: /* original 9411, guest PC 0x0c09ba50 */
if(!s->budget--) { s->failed_pc=0x0c09ba50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ba76u,2);
goto P_0c09ba52;
P_0c09ba52: /* original 4c0b, guest PC 0x0c09ba52 */
if(!s->budget--) { s->failed_pc=0x0c09ba52u; return 0; }
target=r[12];
r[16]=0x0c09ba56u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ba56u) { target=s->pc; goto dispatch; }
goto P_0c09ba56;
P_0c09ba54: /* original 0009, guest PC 0x0c09ba54 */
if(!s->budget--) { s->failed_pc=0x0c09ba54u; return 0; }
goto P_0c09ba56;
P_0c09ba56: /* original e001, guest PC 0x0c09ba56 */
if(!s->budget--) { s->failed_pc=0x0c09ba56u; return 0; }
r[0]=0x00000001u;
goto P_0c09ba58;
P_0c09ba58: /* original 80eb, guest PC 0x0c09ba58 */
if(!s->budget--) { s->failed_pc=0x0c09ba58u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09ba5a;
P_0c09ba5a: /* original e010, guest PC 0x0c09ba5a */
if(!s->budget--) { s->failed_pc=0x0c09ba5au; return 0; }
r[0]=0x00000010u;
goto P_0c09ba5c;
P_0c09ba5c: /* original e372, guest PC 0x0c09ba5c */
if(!s->budget--) { s->failed_pc=0x0c09ba5cu; return 0; }
r[3]=0x00000072u;
goto P_0c09ba5e;
P_0c09ba5e: /* original 0e34, guest PC 0x0c09ba5e */
if(!s->budget--) { s->failed_pc=0x0c09ba5eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09ba60;
P_0c09ba60: /* original 4f26, guest PC 0x0c09ba60 */
if(!s->budget--) { s->failed_pc=0x0c09ba60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ba62;
P_0c09ba62: /* original 6af6, guest PC 0x0c09ba62 */
if(!s->budget--) { s->failed_pc=0x0c09ba62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ba64;
P_0c09ba64: /* original 6bf6, guest PC 0x0c09ba64 */
if(!s->budget--) { s->failed_pc=0x0c09ba64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ba66;
P_0c09ba66: /* original 6cf6, guest PC 0x0c09ba66 */
if(!s->budget--) { s->failed_pc=0x0c09ba66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ba68;
P_0c09ba68: /* original 6df6, guest PC 0x0c09ba68 */
if(!s->budget--) { s->failed_pc=0x0c09ba68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ba6a;
P_0c09ba6a: /* original 000b, guest PC 0x0c09ba6a */
if(!s->budget--) { s->failed_pc=0x0c09ba6au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09ba6c: /* original 6ef6, guest PC 0x0c09ba6c */
if(!s->budget--) { s->failed_pc=0x0c09ba6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09ba6eu,s,ram);
P_0c0c9c18: /* original 000b, guest PC 0x0c0c9c18 */
if(!s->budget--) { s->failed_pc=0x0c0c9c18u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9c1a: /* original 0009, guest PC 0x0c0c9c1a */
if(!s->budget--) { s->failed_pc=0x0c0c9c1au; return 0; }
return vf3_matrix_family(0x0c0c9c1cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c042fdcu,0x0c042fdeu,0x0c042fe0u,0x0c042fe2u,0x0c042fe4u,0x0c042fe6u,0x0c042fe8u,0x0c042feau,0x0c042fecu,0x0c042feeu,0x0c042ff0u,0x0c042ff2u,0x0c042ff4u,0x0c042ff6u,0x0c042ff8u,0x0c042ffau,
0x0c042ffcu,0x0c042ffeu,0x0c043000u,0x0c043002u,0x0c043004u,0x0c043006u,0x0c043008u,0x0c04300au,0x0c04300cu,0x0c04300eu,0x0c043010u,0x0c043012u,0x0c043014u,0x0c043016u,0x0c04bc8cu,0x0c04bc8eu,
0x0c04bc90u,0x0c04bc92u,0x0c04bc94u,0x0c04bc96u,0x0c04bc98u,0x0c04bc9au,0x0c04bc9cu,0x0c04bc9eu,0x0c04bca0u,0x0c04bca2u,0x0c04bca4u,0x0c04bca6u,0x0c04bca8u,0x0c04bcaau,0x0c04bcacu,0x0c04bcaeu,
0x0c04bcb0u,0x0c04bcb2u,0x0c04bcb4u,0x0c04bcb6u,0x0c04bcb8u,0x0c04bcbau,0x0c04bcc6u,0x0c04bcc8u,0x0c04bccau,0x0c04bcccu,0x0c04bcceu,0x0c04bcd0u,0x0c04bcd2u,0x0c04bcd4u,0x0c04bcd6u,0x0c04bcd8u,
0x0c04bcdau,0x0c04bcdcu,0x0c04bcdeu,0x0c04bce0u,0x0c04bce2u,0x0c04bce4u,0x0c04bce6u,0x0c04bce8u,0x0c04bceau,0x0c04bcecu,0x0c04bceeu,0x0c04bcf0u,0x0c04bcf2u,0x0c04bcf4u,0x0c04bcf6u,0x0c04bcf8u,
0x0c04bcfau,0x0c04bcfcu,0x0c04bcfeu,0x0c04bd00u,0x0c04bd02u,0x0c04bd04u,0x0c04bd06u,0x0c04bd08u,0x0c04bd0au,0x0c04bd0cu,0x0c04bd0eu,0x0c04bd10u,0x0c04bd12u,0x0c04bd14u,0x0c04bd16u,0x0c04bd18u,
0x0c04bd1au,0x0c04bd1cu,0x0c04bd1eu,0x0c076b3cu,0x0c076b3eu,0x0c076b40u,0x0c076b42u,0x0c076b44u,0x0c076b46u,0x0c076b48u,0x0c076b4au,0x0c076b4cu,0x0c076b4eu,0x0c076b50u,0x0c076b52u,0x0c076b54u,
0x0c076b56u,0x0c076b58u,0x0c076b5au,0x0c076b5cu,0x0c076b5eu,0x0c076b60u,0x0c076b62u,0x0c076b64u,0x0c0819fau,0x0c0819fcu,0x0c0819feu,0x0c081a00u,0x0c081a02u,0x0c081a04u,0x0c081a06u,0x0c081a08u,
0x0c081a0au,0x0c081a0cu,0x0c081a0eu,0x0c081a10u,0x0c081a12u,0x0c081a14u,0x0c081a16u,0x0c081a18u,0x0c081a1au,0x0c081a1cu,0x0c081a1eu,0x0c081a20u,0x0c081a22u,0x0c081a24u,0x0c081a26u,0x0c081a28u,
0x0c081a2au,0x0c081a2cu,0x0c081a2eu,0x0c081a30u,0x0c095724u,0x0c095726u,0x0c095728u,0x0c09572au,0x0c09572cu,0x0c09572eu,0x0c095730u,0x0c095732u,0x0c095734u,0x0c095736u,0x0c095738u,0x0c09573au,
0x0c09573cu,0x0c09573eu,0x0c095740u,0x0c095742u,0x0c095744u,0x0c095746u,0x0c095748u,0x0c09574au,0x0c09574cu,0x0c09af6cu,0x0c09af6eu,0x0c09af70u,0x0c09af72u,0x0c09af74u,0x0c09af76u,0x0c09af78u,
0x0c09af7au,0x0c09af7cu,0x0c09af7eu,0x0c09af80u,0x0c09af82u,0x0c09af84u,0x0c09af86u,0x0c09af88u,0x0c09af8au,0x0c09af8cu,0x0c09af8eu,0x0c09af90u,0x0c09af92u,0x0c09af94u,0x0c09af96u,0x0c09af98u,
0x0c09af9au,0x0c09af9cu,0x0c09af9eu,0x0c09afa0u,0x0c09afa2u,0x0c09afa4u,0x0c09afa6u,0x0c09afa8u,0x0c09afaau,0x0c09afacu,0x0c09afaeu,0x0c09afb0u,0x0c09afb2u,0x0c09afb4u,0x0c09afb6u,0x0c09afb8u,
0x0c09afbau,0x0c09afbcu,0x0c09afbeu,0x0c09b926u,0x0c09b928u,0x0c09b92au,0x0c09b92cu,0x0c09b92eu,0x0c09b930u,0x0c09b932u,0x0c09b934u,0x0c09b936u,0x0c09b938u,0x0c09b93au,0x0c09b93cu,0x0c09b93eu,
0x0c09b940u,0x0c09b942u,0x0c09b944u,0x0c09b946u,0x0c09b948u,0x0c09b94au,0x0c09b94cu,0x0c09b94eu,0x0c09b950u,0x0c09b952u,0x0c09b954u,0x0c09b978u,0x0c09b97au,0x0c09b97cu,0x0c09b97eu,0x0c09b980u,
0x0c09b982u,0x0c09b984u,0x0c09b986u,0x0c09b988u,0x0c09b98au,0x0c09b98cu,0x0c09b98eu,0x0c09b990u,0x0c09b992u,0x0c09b994u,0x0c09b996u,0x0c09b998u,0x0c09b99au,0x0c09b99cu,0x0c09b99eu,0x0c09b9a0u,
0x0c09b9a2u,0x0c09b9a4u,0x0c09b9a6u,0x0c09b9a8u,0x0c09b9aau,0x0c09b9acu,0x0c09b9aeu,0x0c09b9b0u,0x0c09b9b2u,0x0c09b9b4u,0x0c09b9b6u,0x0c09b9b8u,0x0c09b9bau,0x0c09b9bcu,0x0c09b9beu,0x0c09b9c0u,
0x0c09b9c2u,0x0c09b9c4u,0x0c09b9c6u,0x0c09b9c8u,0x0c09b9cau,0x0c09b9ccu,0x0c09b9ceu,0x0c09b9d0u,0x0c09b9d2u,0x0c09b9d4u,0x0c09b9d6u,0x0c09b9d8u,0x0c09b9dau,0x0c09b9dcu,0x0c09b9deu,0x0c09b9e0u,
0x0c09b9e2u,0x0c09b9e4u,0x0c09b9e6u,0x0c09b9e8u,0x0c09b9eau,0x0c09b9ecu,0x0c09b9eeu,0x0c09b9f0u,0x0c09b9f2u,0x0c09b9f4u,0x0c09b9f6u,0x0c09b9f8u,0x0c09b9fau,0x0c09b9fcu,0x0c09b9feu,0x0c09ba00u,
0x0c09ba02u,0x0c09ba04u,0x0c09ba06u,0x0c09ba08u,0x0c09ba0au,0x0c09ba0cu,0x0c09ba0eu,0x0c09ba10u,0x0c09ba12u,0x0c09ba14u,0x0c09ba16u,0x0c09ba18u,0x0c09ba1au,0x0c09ba1cu,0x0c09ba1eu,0x0c09ba20u,
0x0c09ba22u,0x0c09ba24u,0x0c09ba26u,0x0c09ba28u,0x0c09ba2au,0x0c09ba2cu,0x0c09ba2eu,0x0c09ba30u,0x0c09ba32u,0x0c09ba34u,0x0c09ba36u,0x0c09ba38u,0x0c09ba3au,0x0c09ba3cu,0x0c09ba3eu,0x0c09ba40u,
0x0c09ba42u,0x0c09ba44u,0x0c09ba46u,0x0c09ba48u,0x0c09ba4au,0x0c09ba4cu,0x0c09ba4eu,0x0c09ba50u,0x0c09ba52u,0x0c09ba54u,0x0c09ba56u,0x0c09ba58u,0x0c09ba5au,0x0c09ba5cu,0x0c09ba5eu,0x0c09ba60u,
0x0c09ba62u,0x0c09ba64u,0x0c09ba66u,0x0c09ba68u,0x0c09ba6au,0x0c09ba6cu,0x0c0c9c18u,0x0c0c9c1au,
};
int vf3_advance_small_tail_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
