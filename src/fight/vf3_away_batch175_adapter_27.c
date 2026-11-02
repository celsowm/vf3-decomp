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
int vf3_away_batch175_adapter_27(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a28d4u: goto P_0c0a28d4;
case 0x0c0a28d6u: goto P_0c0a28d6;
case 0x0c0a28d8u: goto P_0c0a28d8;
case 0x0c0a28dau: goto P_0c0a28da;
case 0x0c0a28dcu: goto P_0c0a28dc;
case 0x0c0a28deu: goto P_0c0a28de;
case 0x0c0a28e0u: goto P_0c0a28e0;
case 0x0c0a28e2u: goto P_0c0a28e2;
case 0x0c0a28e4u: goto P_0c0a28e4;
case 0x0c0a28e6u: goto P_0c0a28e6;
case 0x0c0a28e8u: goto P_0c0a28e8;
case 0x0c0a28eau: goto P_0c0a28ea;
case 0x0c0a28ecu: goto P_0c0a28ec;
case 0x0c0a28eeu: goto P_0c0a28ee;
case 0x0c0a28f0u: goto P_0c0a28f0;
case 0x0c0a28f2u: goto P_0c0a28f2;
case 0x0c0a28f4u: goto P_0c0a28f4;
case 0x0c0a28f6u: goto P_0c0a28f6;
case 0x0c0a28f8u: goto P_0c0a28f8;
case 0x0c0a28fau: goto P_0c0a28fa;
case 0x0c0a28fcu: goto P_0c0a28fc;
case 0x0c0a28feu: goto P_0c0a28fe;
case 0x0c0a2900u: goto P_0c0a2900;
case 0x0c0a2902u: goto P_0c0a2902;
case 0x0c0a2904u: goto P_0c0a2904;
case 0x0c0a2906u: goto P_0c0a2906;
case 0x0c0a2908u: goto P_0c0a2908;
case 0x0c0a290au: goto P_0c0a290a;
case 0x0c0a290cu: goto P_0c0a290c;
case 0x0c0a290eu: goto P_0c0a290e;
case 0x0c0a2910u: goto P_0c0a2910;
case 0x0c0a2912u: goto P_0c0a2912;
case 0x0c0a2914u: goto P_0c0a2914;
case 0x0c0a2916u: goto P_0c0a2916;
case 0x0c0a2918u: goto P_0c0a2918;
case 0x0c0a291au: goto P_0c0a291a;
case 0x0c0a291cu: goto P_0c0a291c;
case 0x0c0a291eu: goto P_0c0a291e;
case 0x0c0a2920u: goto P_0c0a2920;
case 0x0c0a2922u: goto P_0c0a2922;
case 0x0c0a2924u: goto P_0c0a2924;
case 0x0c0a2926u: goto P_0c0a2926;
case 0x0c0a2928u: goto P_0c0a2928;
case 0x0c0a292au: goto P_0c0a292a;
case 0x0c0a292cu: goto P_0c0a292c;
case 0x0c0a292eu: goto P_0c0a292e;
case 0x0c0a2930u: goto P_0c0a2930;
case 0x0c0a2932u: goto P_0c0a2932;
case 0x0c0a2934u: goto P_0c0a2934;
case 0x0c0a2936u: goto P_0c0a2936;
case 0x0c0a2938u: goto P_0c0a2938;
case 0x0c0a293au: goto P_0c0a293a;
case 0x0c0a293cu: goto P_0c0a293c;
case 0x0c0a293eu: goto P_0c0a293e;
case 0x0c0a2940u: goto P_0c0a2940;
case 0x0c0a2942u: goto P_0c0a2942;
case 0x0c0a2944u: goto P_0c0a2944;
case 0x0c0a2946u: goto P_0c0a2946;
case 0x0c0a2948u: goto P_0c0a2948;
case 0x0c0a294au: goto P_0c0a294a;
case 0x0c0a294cu: goto P_0c0a294c;
case 0x0c0a294eu: goto P_0c0a294e;
case 0x0c0a2950u: goto P_0c0a2950;
case 0x0c0a2952u: goto P_0c0a2952;
case 0x0c0a2954u: goto P_0c0a2954;
case 0x0c0a2956u: goto P_0c0a2956;
case 0x0c0a2958u: goto P_0c0a2958;
case 0x0c0a295au: goto P_0c0a295a;
case 0x0c0a295cu: goto P_0c0a295c;
case 0x0c0a2984u: goto P_0c0a2984;
case 0x0c0a2986u: goto P_0c0a2986;
case 0x0c0a2988u: goto P_0c0a2988;
case 0x0c0a298au: goto P_0c0a298a;
case 0x0c0a298cu: goto P_0c0a298c;
case 0x0c0a298eu: goto P_0c0a298e;
case 0x0c0a2990u: goto P_0c0a2990;
case 0x0c0a2992u: goto P_0c0a2992;
case 0x0c0a2994u: goto P_0c0a2994;
case 0x0c0a2996u: goto P_0c0a2996;
case 0x0c0a2998u: goto P_0c0a2998;
case 0x0c0a299au: goto P_0c0a299a;
case 0x0c0a299cu: goto P_0c0a299c;
case 0x0c0a299eu: goto P_0c0a299e;
case 0x0c0a29a0u: goto P_0c0a29a0;
case 0x0c0a29a2u: goto P_0c0a29a2;
case 0x0c0a29a4u: goto P_0c0a29a4;
case 0x0c0a29a6u: goto P_0c0a29a6;
case 0x0c0a29a8u: goto P_0c0a29a8;
case 0x0c0a29aau: goto P_0c0a29aa;
case 0x0c0a29acu: goto P_0c0a29ac;
case 0x0c0a29aeu: goto P_0c0a29ae;
case 0x0c0a29b0u: goto P_0c0a29b0;
case 0x0c0a29b2u: goto P_0c0a29b2;
case 0x0c0a29b4u: goto P_0c0a29b4;
case 0x0c0a29b6u: goto P_0c0a29b6;
case 0x0c0a29b8u: goto P_0c0a29b8;
case 0x0c0a29bau: goto P_0c0a29ba;
case 0x0c0a29bcu: goto P_0c0a29bc;
case 0x0c0a29beu: goto P_0c0a29be;
case 0x0c0a29c0u: goto P_0c0a29c0;
case 0x0c0a29c2u: goto P_0c0a29c2;
case 0x0c0a29c4u: goto P_0c0a29c4;
case 0x0c0a29c6u: goto P_0c0a29c6;
case 0x0c0a29c8u: goto P_0c0a29c8;
case 0x0c0a29cau: goto P_0c0a29ca;
case 0x0c0a29ccu: goto P_0c0a29cc;
case 0x0c0a29ceu: goto P_0c0a29ce;
case 0x0c0a29d0u: goto P_0c0a29d0;
case 0x0c0a29d2u: goto P_0c0a29d2;
case 0x0c0a29d4u: goto P_0c0a29d4;
case 0x0c0a29d6u: goto P_0c0a29d6;
case 0x0c0a29d8u: goto P_0c0a29d8;
case 0x0c0a29dau: goto P_0c0a29da;
case 0x0c0a29dcu: goto P_0c0a29dc;
case 0x0c0a29deu: goto P_0c0a29de;
case 0x0c0a29e0u: goto P_0c0a29e0;
case 0x0c0a29e2u: goto P_0c0a29e2;
case 0x0c0a29e4u: goto P_0c0a29e4;
case 0x0c0a29e6u: goto P_0c0a29e6;
case 0x0c0a29e8u: goto P_0c0a29e8;
case 0x0c0a29eau: goto P_0c0a29ea;
case 0x0c0a29ecu: goto P_0c0a29ec;
case 0x0c0a29eeu: goto P_0c0a29ee;
case 0x0c0a29f0u: goto P_0c0a29f0;
case 0x0c0a29f2u: goto P_0c0a29f2;
case 0x0c0a29f4u: goto P_0c0a29f4;
case 0x0c0a29f6u: goto P_0c0a29f6;
case 0x0c0a29f8u: goto P_0c0a29f8;
case 0x0c0a29fau: goto P_0c0a29fa;
case 0x0c0a29fcu: goto P_0c0a29fc;
case 0x0c0a29feu: goto P_0c0a29fe;
case 0x0c0a2a00u: goto P_0c0a2a00;
case 0x0c0a2a02u: goto P_0c0a2a02;
case 0x0c0a2a04u: goto P_0c0a2a04;
case 0x0c0a2a06u: goto P_0c0a2a06;
case 0x0c0a2a08u: goto P_0c0a2a08;
case 0x0c0a2a0au: goto P_0c0a2a0a;
case 0x0c0a2a0cu: goto P_0c0a2a0c;
case 0x0c0a2a0eu: goto P_0c0a2a0e;
case 0x0c0a2a10u: goto P_0c0a2a10;
case 0x0c0a2a12u: goto P_0c0a2a12;
case 0x0c0a2a14u: goto P_0c0a2a14;
case 0x0c0a2a16u: goto P_0c0a2a16;
case 0x0c0a2a18u: goto P_0c0a2a18;
case 0x0c0a2a1au: goto P_0c0a2a1a;
case 0x0c0a2a1cu: goto P_0c0a2a1c;
case 0x0c0a2a1eu: goto P_0c0a2a1e;
case 0x0c0a2a20u: goto P_0c0a2a20;
case 0x0c0a2a22u: goto P_0c0a2a22;
case 0x0c0a2a24u: goto P_0c0a2a24;
case 0x0c0a2a26u: goto P_0c0a2a26;
case 0x0c0a2a28u: goto P_0c0a2a28;
case 0x0c0a2a2au: goto P_0c0a2a2a;
case 0x0c0a2a2cu: goto P_0c0a2a2c;
case 0x0c0a2a2eu: goto P_0c0a2a2e;
case 0x0c0a2a30u: goto P_0c0a2a30;
case 0x0c0a2a32u: goto P_0c0a2a32;
case 0x0c0a2a34u: goto P_0c0a2a34;
case 0x0c0a2a36u: goto P_0c0a2a36;
case 0x0c0a2a38u: goto P_0c0a2a38;
case 0x0c0a2a3au: goto P_0c0a2a3a;
case 0x0c0a2a3cu: goto P_0c0a2a3c;
case 0x0c0a2a3eu: goto P_0c0a2a3e;
case 0x0c0a2a40u: goto P_0c0a2a40;
case 0x0c0a2a42u: goto P_0c0a2a42;
case 0x0c0a2a44u: goto P_0c0a2a44;
case 0x0c0a2a46u: goto P_0c0a2a46;
case 0x0c0a2a48u: goto P_0c0a2a48;
case 0x0c0a2a4au: goto P_0c0a2a4a;
case 0x0c0a2a4cu: goto P_0c0a2a4c;
case 0x0c0a2a4eu: goto P_0c0a2a4e;
case 0x0c0a2a50u: goto P_0c0a2a50;
case 0x0c0a2a52u: goto P_0c0a2a52;
case 0x0c0a2a54u: goto P_0c0a2a54;
case 0x0c0a2a56u: goto P_0c0a2a56;
case 0x0c0a2a58u: goto P_0c0a2a58;
case 0x0c0a2a5au: goto P_0c0a2a5a;
case 0x0c0a2a5cu: goto P_0c0a2a5c;
case 0x0c0a2a5eu: goto P_0c0a2a5e;
case 0x0c0a2a60u: goto P_0c0a2a60;
case 0x0c0a2a62u: goto P_0c0a2a62;
case 0x0c0a2a64u: goto P_0c0a2a64;
case 0x0c0a2a66u: goto P_0c0a2a66;
case 0x0c0a2a68u: goto P_0c0a2a68;
case 0x0c0a2a6au: goto P_0c0a2a6a;
case 0x0c0a2a6cu: goto P_0c0a2a6c;
case 0x0c0a2a6eu: goto P_0c0a2a6e;
case 0x0c0a2a70u: goto P_0c0a2a70;
case 0x0c0a2a72u: goto P_0c0a2a72;
case 0x0c0a2b98u: goto P_0c0a2b98;
case 0x0c0a2b9au: goto P_0c0a2b9a;
case 0x0c0a2b9cu: goto P_0c0a2b9c;
case 0x0c0a2b9eu: goto P_0c0a2b9e;
case 0x0c0a2ba0u: goto P_0c0a2ba0;
case 0x0c0a2ba2u: goto P_0c0a2ba2;
case 0x0c0a2ba4u: goto P_0c0a2ba4;
case 0x0c0a2ba6u: goto P_0c0a2ba6;
case 0x0c0a2ba8u: goto P_0c0a2ba8;
case 0x0c0a2baau: goto P_0c0a2baa;
case 0x0c0a2bacu: goto P_0c0a2bac;
case 0x0c0a2baeu: goto P_0c0a2bae;
case 0x0c0a2bb0u: goto P_0c0a2bb0;
case 0x0c0a2bb2u: goto P_0c0a2bb2;
case 0x0c0a2bb4u: goto P_0c0a2bb4;
case 0x0c0a2bb6u: goto P_0c0a2bb6;
case 0x0c0a2bb8u: goto P_0c0a2bb8;
case 0x0c0a2bbau: goto P_0c0a2bba;
case 0x0c0a2bbcu: goto P_0c0a2bbc;
case 0x0c0a2bbeu: goto P_0c0a2bbe;
case 0x0c0a2bc0u: goto P_0c0a2bc0;
case 0x0c0a2bc2u: goto P_0c0a2bc2;
case 0x0c0a2bc4u: goto P_0c0a2bc4;
case 0x0c0a2bc6u: goto P_0c0a2bc6;
case 0x0c0a2bc8u: goto P_0c0a2bc8;
case 0x0c0a2bcau: goto P_0c0a2bca;
case 0x0c0a2bccu: goto P_0c0a2bcc;
case 0x0c0a2bceu: goto P_0c0a2bce;
case 0x0c0a2bd0u: goto P_0c0a2bd0;
case 0x0c0a2bd2u: goto P_0c0a2bd2;
case 0x0c0a2bd4u: goto P_0c0a2bd4;
case 0x0c0a2bd6u: goto P_0c0a2bd6;
case 0x0c0a2bd8u: goto P_0c0a2bd8;
case 0x0c0a2bdau: goto P_0c0a2bda;
case 0x0c0a2bdcu: goto P_0c0a2bdc;
case 0x0c0a2bdeu: goto P_0c0a2bde;
case 0x0c0a2be0u: goto P_0c0a2be0;
case 0x0c0a2be2u: goto P_0c0a2be2;
case 0x0c0a2be4u: goto P_0c0a2be4;
case 0x0c0a2be6u: goto P_0c0a2be6;
case 0x0c0a2be8u: goto P_0c0a2be8;
case 0x0c0a2beau: goto P_0c0a2bea;
case 0x0c0a2becu: goto P_0c0a2bec;
case 0x0c0a2beeu: goto P_0c0a2bee;
case 0x0c0a2bf0u: goto P_0c0a2bf0;
case 0x0c0a2bf2u: goto P_0c0a2bf2;
case 0x0c0a2bf4u: goto P_0c0a2bf4;
case 0x0c0a2bf6u: goto P_0c0a2bf6;
case 0x0c0a2bf8u: goto P_0c0a2bf8;
case 0x0c0a2bfau: goto P_0c0a2bfa;
case 0x0c0a2bfcu: goto P_0c0a2bfc;
case 0x0c0a2bfeu: goto P_0c0a2bfe;
case 0x0c0a2c00u: goto P_0c0a2c00;
case 0x0c0a2c02u: goto P_0c0a2c02;
case 0x0c0a2c04u: goto P_0c0a2c04;
case 0x0c0a2c06u: goto P_0c0a2c06;
case 0x0c0a2c08u: goto P_0c0a2c08;
case 0x0c0a2c0au: goto P_0c0a2c0a;
case 0x0c0a2c0cu: goto P_0c0a2c0c;
case 0x0c0a2c0eu: goto P_0c0a2c0e;
case 0x0c0a2c10u: goto P_0c0a2c10;
case 0x0c0a2c12u: goto P_0c0a2c12;
case 0x0c0a2c14u: goto P_0c0a2c14;
case 0x0c0a2c16u: goto P_0c0a2c16;
case 0x0c0a2c18u: goto P_0c0a2c18;
case 0x0c0a2c1au: goto P_0c0a2c1a;
case 0x0c0a2c1cu: goto P_0c0a2c1c;
case 0x0c0a2c1eu: goto P_0c0a2c1e;
case 0x0c0a2c20u: goto P_0c0a2c20;
case 0x0c0a2c22u: goto P_0c0a2c22;
case 0x0c0a2c24u: goto P_0c0a2c24;
case 0x0c0a2c26u: goto P_0c0a2c26;
case 0x0c0a2c28u: goto P_0c0a2c28;
case 0x0c0a2c2au: goto P_0c0a2c2a;
case 0x0c0a2c2cu: goto P_0c0a2c2c;
case 0x0c0a2c2eu: goto P_0c0a2c2e;
case 0x0c0a2c30u: goto P_0c0a2c30;
case 0x0c0a2c32u: goto P_0c0a2c32;
case 0x0c0a2c34u: goto P_0c0a2c34;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a28d4: /* original 2fe6, guest PC 0x0c0a28d4 */
if(!s->budget--) { s->failed_pc=0x0c0a28d4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a28d6;
P_0c0a28d6: /* original 6073, guest PC 0x0c0a28d6 */
if(!s->budget--) { s->failed_pc=0x0c0a28d6u; return 0; }
r[0]=r[7];
goto P_0c0a28d8;
P_0c0a28d8: /* original 2fd6, guest PC 0x0c0a28d8 */
if(!s->budget--) { s->failed_pc=0x0c0a28d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a28da;
P_0c0a28da: /* original 6e63, guest PC 0x0c0a28da */
if(!s->budget--) { s->failed_pc=0x0c0a28dau; return 0; }
r[14]=r[6];
goto P_0c0a28dc;
P_0c0a28dc: /* original 4f22, guest PC 0x0c0a28dc */
if(!s->budget--) { s->failed_pc=0x0c0a28dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a28de;
P_0c0a28de: /* original 7ff4, guest PC 0x0c0a28de */
if(!s->budget--) { s->failed_pc=0x0c0a28deu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a28e0;
P_0c0a28e0: /* original 2f52, guest PC 0x0c0a28e0 */
if(!s->budget--) { s->failed_pc=0x0c0a28e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a28e2;
P_0c0a28e2: /* original 81f2, guest PC 0x0c0a28e2 */
if(!s->budget--) { s->failed_pc=0x0c0a28e2u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0a28e4;
P_0c0a28e4: /* original 953e, guest PC 0x0c0a28e4 */
if(!s->budget--) { s->failed_pc=0x0c0a28e4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2964u,2);
goto P_0c0a28e6;
P_0c0a28e6: /* original 3453, guest PC 0x0c0a28e6 */
if(!s->budget--) { s->failed_pc=0x0c0a28e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0a28e8;
P_0c0a28e8: /* original 8d1c, guest PC 0x0c0a28e8 */
if(!s->budget--) { s->failed_pc=0x0c0a28e8u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[14],4);
if(cond) { goto P_0c0a2924; }
goto P_0c0a28ec;
P_0c0a28ea: /* original 1fe2, guest PC 0x0c0a28ea */
if(!s->budget--) { s->failed_pc=0x0c0a28eau; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c0a28ec;
P_0c0a28ec: /* original 62f2, guest PC 0x0c0a28ec */
if(!s->budget--) { s->failed_pc=0x0c0a28ecu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a28ee;
P_0c0a28ee: /* original 3253, guest PC 0x0c0a28ee */
if(!s->budget--) { s->failed_pc=0x0c0a28eeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[5])!=0);
goto P_0c0a28f0;
P_0c0a28f0: /* original 8918, guest PC 0x0c0a28f0 */
if(!s->budget--) { s->failed_pc=0x0c0a28f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2924; }
goto P_0c0a28f2;
P_0c0a28f2: /* original b01e, guest PC 0x0c0a28f2 */
if(!s->budget--) { s->failed_pc=0x0c0a28f2u; return 0; }
target=code_base|0x0c0a2932u; r[16]=code_base|0x0c0a28f6u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a28f6u) { target=s->pc; goto dispatch; }
goto P_0c0a28f6;
P_0c0a28f4: /* original 65e3, guest PC 0x0c0a28f4 */
if(!s->budget--) { s->failed_pc=0x0c0a28f4u; return 0; }
r[5]=r[14];
goto P_0c0a28f6;
P_0c0a28f6: /* original 6403, guest PC 0x0c0a28f6 */
if(!s->budget--) { s->failed_pc=0x0c0a28f6u; return 0; }
r[4]=r[0];
goto P_0c0a28f8;
P_0c0a28f8: /* original 2448, guest PC 0x0c0a28f8 */
if(!s->budget--) { s->failed_pc=0x0c0a28f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a28fa;
P_0c0a28fa: /* original 8913, guest PC 0x0c0a28fa */
if(!s->budget--) { s->failed_pc=0x0c0a28fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2924; }
goto P_0c0a28fc;
P_0c0a28fc: /* original d11d, guest PC 0x0c0a28fc */
if(!s->budget--) { s->failed_pc=0x0c0a28fcu; return 0; }
r[1]=read(ram,0x0c0a2974u,4);
goto P_0c0a28fe;
P_0c0a28fe: /* original 52f2, guest PC 0x0c0a28fe */
if(!s->budget--) { s->failed_pc=0x0c0a28feu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a2900;
P_0c0a2900: /* original 6d12, guest PC 0x0c0a2900 */
if(!s->budget--) { s->failed_pc=0x0c0a2900u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c0a2902;
P_0c0a2902: /* original 5327, guest PC 0x0c0a2902 */
if(!s->budget--) { s->failed_pc=0x0c0a2902u; return 0; }
r[3]=read(ram,r[2]+28,4);
goto P_0c0a2904;
P_0c0a2904: /* original 922f, guest PC 0x0c0a2904 */
if(!s->budget--) { s->failed_pc=0x0c0a2904u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2966u,2);
goto P_0c0a2906;
P_0c0a2906: /* original 3d38, guest PC 0x0c0a2906 */
if(!s->budget--) { s->failed_pc=0x0c0a2906u; return 0; }
r[13]-=r[3];
goto P_0c0a2908;
P_0c0a2908: /* original 932a, guest PC 0x0c0a2908 */
if(!s->budget--) { s->failed_pc=0x0c0a2908u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2960u,2);
goto P_0c0a290a;
P_0c0a290a: /* original 3d2c, guest PC 0x0c0a290a */
if(!s->budget--) { s->failed_pc=0x0c0a290au; return 0; }
r[13]+=r[2];
goto P_0c0a290c;
P_0c0a290c: /* original d21b, guest PC 0x0c0a290c */
if(!s->budget--) { s->failed_pc=0x0c0a290cu; return 0; }
r[2]=read(ram,0x0c0a297cu,4);
goto P_0c0a290e;
P_0c0a290e: /* original 2d39, guest PC 0x0c0a290e */
if(!s->budget--) { s->failed_pc=0x0c0a290eu; return 0; }
r[13]&=r[3];
goto P_0c0a2910;
P_0c0a2910: /* original 65d3, guest PC 0x0c0a2910 */
if(!s->budget--) { s->failed_pc=0x0c0a2910u; return 0; }
r[5]=r[13];
goto P_0c0a2912;
P_0c0a2912: /* original 420b, guest PC 0x0c0a2912 */
if(!s->budget--) { s->failed_pc=0x0c0a2912u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2916u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2916u) { target=s->pc; goto dispatch; }
goto P_0c0a2916;
P_0c0a2914: /* original 64f2, guest PC 0x0c0a2914 */
if(!s->budget--) { s->failed_pc=0x0c0a2914u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a2916;
P_0c0a2916: /* original 85f2, guest PC 0x0c0a2916 */
if(!s->budget--) { s->failed_pc=0x0c0a2916u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0a2918;
P_0c0a2918: /* original 65d3, guest PC 0x0c0a2918 */
if(!s->budget--) { s->failed_pc=0x0c0a2918u; return 0; }
r[5]=r[13];
goto P_0c0a291a;
P_0c0a291a: /* original 6603, guest PC 0x0c0a291a */
if(!s->budget--) { s->failed_pc=0x0c0a291au; return 0; }
r[6]=r[0];
goto P_0c0a291c;
P_0c0a291c: /* original b032, guest PC 0x0c0a291c */
if(!s->budget--) { s->failed_pc=0x0c0a291cu; return 0; }
target=code_base|0x0c0a2984u; r[16]=code_base|0x0c0a2920u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2920u) { target=s->pc; goto dispatch; }
goto P_0c0a2920;
P_0c0a291e: /* original 64e3, guest PC 0x0c0a291e */
if(!s->budget--) { s->failed_pc=0x0c0a291eu; return 0; }
r[4]=r[14];
goto P_0c0a2920;
P_0c0a2920: /* original a001, guest PC 0x0c0a2920 */
if(!s->budget--) { s->failed_pc=0x0c0a2920u; return 0; }
r[4]=r[0];
goto P_0c0a2926;
P_0c0a2922: /* original 6403, guest PC 0x0c0a2922 */
if(!s->budget--) { s->failed_pc=0x0c0a2922u; return 0; }
r[4]=r[0];
goto P_0c0a2924;
P_0c0a2924: /* original d416, guest PC 0x0c0a2924 */
if(!s->budget--) { s->failed_pc=0x0c0a2924u; return 0; }
r[4]=read(ram,0x0c0a2980u,4);
goto P_0c0a2926;
P_0c0a2926: /* original 7f0c, guest PC 0x0c0a2926 */
if(!s->budget--) { s->failed_pc=0x0c0a2926u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2928;
P_0c0a2928: /* original 6043, guest PC 0x0c0a2928 */
if(!s->budget--) { s->failed_pc=0x0c0a2928u; return 0; }
r[0]=r[4];
goto P_0c0a292a;
P_0c0a292a: /* original 4f26, guest PC 0x0c0a292a */
if(!s->budget--) { s->failed_pc=0x0c0a292au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a292c;
P_0c0a292c: /* original 6df6, guest PC 0x0c0a292c */
if(!s->budget--) { s->failed_pc=0x0c0a292cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a292e;
P_0c0a292e: /* original 000b, guest PC 0x0c0a292e */
if(!s->budget--) { s->failed_pc=0x0c0a292eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2930: /* original 6ef6, guest PC 0x0c0a2930 */
if(!s->budget--) { s->failed_pc=0x0c0a2930u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a2932;
P_0c0a2932: /* original 2fe6, guest PC 0x0c0a2932 */
if(!s->budget--) { s->failed_pc=0x0c0a2932u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2934;
P_0c0a2934: /* original 6e53, guest PC 0x0c0a2934 */
if(!s->budget--) { s->failed_pc=0x0c0a2934u; return 0; }
r[14]=r[5];
goto P_0c0a2936;
P_0c0a2936: /* original 2fd6, guest PC 0x0c0a2936 */
if(!s->budget--) { s->failed_pc=0x0c0a2936u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2938;
P_0c0a2938: /* original 9314, guest PC 0x0c0a2938 */
if(!s->budget--) { s->failed_pc=0x0c0a2938u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2964u,2);
goto P_0c0a293a;
P_0c0a293a: /* original 4f22, guest PC 0x0c0a293a */
if(!s->budget--) { s->failed_pc=0x0c0a293au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a293c;
P_0c0a293c: /* original 3433, guest PC 0x0c0a293c */
if(!s->budget--) { s->failed_pc=0x0c0a293cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a293e;
P_0c0a293e: /* original 8f02, guest PC 0x0c0a293e */
if(!s->budget--) { s->failed_pc=0x0c0a293eu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(!cond) { goto P_0c0a2946; }
goto P_0c0a2942;
P_0c0a2940: /* original 6d53, guest PC 0x0c0a2940 */
if(!s->budget--) { s->failed_pc=0x0c0a2940u; return 0; }
r[13]=r[5];
goto P_0c0a2942;
P_0c0a2942: /* original a008, guest PC 0x0c0a2942 */
if(!s->budget--) { s->failed_pc=0x0c0a2942u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2956;
P_0c0a2944: /* original e000, guest PC 0x0c0a2944 */
if(!s->budget--) { s->failed_pc=0x0c0a2944u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2946;
P_0c0a2946: /* original d30d, guest PC 0x0c0a2946 */
if(!s->budget--) { s->failed_pc=0x0c0a2946u; return 0; }
r[3]=read(ram,0x0c0a297cu,4);
goto P_0c0a2948;
P_0c0a2948: /* original 430b, guest PC 0x0c0a2948 */
if(!s->budget--) { s->failed_pc=0x0c0a2948u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a294cu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a294cu) { target=s->pc; goto dispatch; }
goto P_0c0a294c;
P_0c0a294a: /* original 65e3, guest PC 0x0c0a294a */
if(!s->budget--) { s->failed_pc=0x0c0a294au; return 0; }
r[5]=r[14];
goto P_0c0a294c;
P_0c0a294c: /* original b173, guest PC 0x0c0a294c */
if(!s->budget--) { s->failed_pc=0x0c0a294cu; return 0; }
target=code_base|0x0c0a2c36u; r[16]=code_base|0x0c0a2950u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2950u) { target=s->pc; goto dispatch; }
goto P_0c0a2950;
P_0c0a294e: /* original 64d3, guest PC 0x0c0a294e */
if(!s->budget--) { s->failed_pc=0x0c0a294eu; return 0; }
r[4]=r[13];
goto P_0c0a2950;
P_0c0a2950: /* original 54d6, guest PC 0x0c0a2950 */
if(!s->budget--) { s->failed_pc=0x0c0a2950u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0a2952;
P_0c0a2952: /* original 34ec, guest PC 0x0c0a2952 */
if(!s->budget--) { s->failed_pc=0x0c0a2952u; return 0; }
r[4]+=r[14];
goto P_0c0a2954;
P_0c0a2954: /* original 6043, guest PC 0x0c0a2954 */
if(!s->budget--) { s->failed_pc=0x0c0a2954u; return 0; }
r[0]=r[4];
goto P_0c0a2956;
P_0c0a2956: /* original 4f26, guest PC 0x0c0a2956 */
if(!s->budget--) { s->failed_pc=0x0c0a2956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2958;
P_0c0a2958: /* original 6df6, guest PC 0x0c0a2958 */
if(!s->budget--) { s->failed_pc=0x0c0a2958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a295a;
P_0c0a295a: /* original 000b, guest PC 0x0c0a295a */
if(!s->budget--) { s->failed_pc=0x0c0a295au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a295c: /* original 6ef6, guest PC 0x0c0a295c */
if(!s->budget--) { s->failed_pc=0x0c0a295cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a295eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a295eu; return 0; } return 1;
P_0c0a2984: /* original 2fe6, guest PC 0x0c0a2984 */
if(!s->budget--) { s->failed_pc=0x0c0a2984u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2986;
P_0c0a2986: /* original 6e43, guest PC 0x0c0a2986 */
if(!s->budget--) { s->failed_pc=0x0c0a2986u; return 0; }
r[14]=r[4];
goto P_0c0a2988;
P_0c0a2988: /* original 2fd6, guest PC 0x0c0a2988 */
if(!s->budget--) { s->failed_pc=0x0c0a2988u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298a;
P_0c0a298a: /* original 2fc6, guest PC 0x0c0a298a */
if(!s->budget--) { s->failed_pc=0x0c0a298au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298c;
P_0c0a298c: /* original 2fb6, guest PC 0x0c0a298c */
if(!s->budget--) { s->failed_pc=0x0c0a298cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298e;
P_0c0a298e: /* original 2fa6, guest PC 0x0c0a298e */
if(!s->budget--) { s->failed_pc=0x0c0a298eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2990;
P_0c0a2990: /* original 2f96, guest PC 0x0c0a2990 */
if(!s->budget--) { s->failed_pc=0x0c0a2990u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2992;
P_0c0a2992: /* original 2f86, guest PC 0x0c0a2992 */
if(!s->budget--) { s->failed_pc=0x0c0a2992u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2994;
P_0c0a2994: /* original 4f22, guest PC 0x0c0a2994 */
if(!s->budget--) { s->failed_pc=0x0c0a2994u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2996;
P_0c0a2996: /* original 7ff8, guest PC 0x0c0a2996 */
if(!s->budget--) { s->failed_pc=0x0c0a2996u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2998;
P_0c0a2998: /* original 2f61, guest PC 0x0c0a2998 */
if(!s->budget--) { s->failed_pc=0x0c0a2998u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a299a;
P_0c0a299a: /* original b14c, guest PC 0x0c0a299a */
if(!s->budget--) { s->failed_pc=0x0c0a299au; return 0; }
target=code_base|0x0c0a2c36u; r[16]=code_base|0x0c0a299eu;
r[10]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a299eu) { target=s->pc; goto dispatch; }
goto P_0c0a299e;
P_0c0a299c: /* original 6a53, guest PC 0x0c0a299c */
if(!s->budget--) { s->failed_pc=0x0c0a299cu; return 0; }
r[10]=r[5];
goto P_0c0a299e;
P_0c0a299e: /* original 6403, guest PC 0x0c0a299e */
if(!s->budget--) { s->failed_pc=0x0c0a299eu; return 0; }
r[4]=r[0];
goto P_0c0a29a0;
P_0c0a29a0: /* original 2448, guest PC 0x0c0a29a0 */
if(!s->budget--) { s->failed_pc=0x0c0a29a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a29a2;
P_0c0a29a2: /* original 8902, guest PC 0x0c0a29a2 */
if(!s->budget--) { s->failed_pc=0x0c0a29a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a29aa; }
goto P_0c0a29a4;
P_0c0a29a4: /* original d375, guest PC 0x0c0a29a4 */
if(!s->budget--) { s->failed_pc=0x0c0a29a4u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a29a6;
P_0c0a29a6: /* original 3430, guest PC 0x0c0a29a6 */
if(!s->budget--) { s->failed_pc=0x0c0a29a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0a29a8;
P_0c0a29a8: /* original 8b59, guest PC 0x0c0a29a8 */
if(!s->budget--) { s->failed_pc=0x0c0a29a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29aa;
P_0c0a29aa: /* original e020, guest PC 0x0c0a29aa */
if(!s->budget--) { s->failed_pc=0x0c0a29aau; return 0; }
r[0]=0x00000020u;
goto P_0c0a29ac;
P_0c0a29ac: /* original 01ed, guest PC 0x0c0a29ac */
if(!s->budget--) { s->failed_pc=0x0c0a29acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ae;
P_0c0a29ae: /* original e022, guest PC 0x0c0a29ae */
if(!s->budget--) { s->failed_pc=0x0c0a29aeu; return 0; }
r[0]=0x00000022u;
goto P_0c0a29b0;
P_0c0a29b0: /* original 03ed, guest PC 0x0c0a29b0 */
if(!s->budget--) { s->failed_pc=0x0c0a29b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29b2;
P_0c0a29b2: /* original 611d, guest PC 0x0c0a29b2 */
if(!s->budget--) { s->failed_pc=0x0c0a29b2u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a29b4;
P_0c0a29b4: /* original 633d, guest PC 0x0c0a29b4 */
if(!s->budget--) { s->failed_pc=0x0c0a29b4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a29b6;
P_0c0a29b6: /* original 213b, guest PC 0x0c0a29b6 */
if(!s->budget--) { s->failed_pc=0x0c0a29b6u; return 0; }
r[1]|=r[3];
goto P_0c0a29b8;
P_0c0a29b8: /* original 2118, guest PC 0x0c0a29b8 */
if(!s->budget--) { s->failed_pc=0x0c0a29b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a29ba;
P_0c0a29ba: /* original 8b50, guest PC 0x0c0a29ba */
if(!s->budget--) { s->failed_pc=0x0c0a29bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29bc;
P_0c0a29bc: /* original e020, guest PC 0x0c0a29bc */
if(!s->budget--) { s->failed_pc=0x0c0a29bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0a29be;
P_0c0a29be: /* original 52e4, guest PC 0x0c0a29be */
if(!s->budget--) { s->failed_pc=0x0c0a29beu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a29c0;
P_0c0a29c0: /* original 1f21, guest PC 0x0c0a29c0 */
if(!s->budget--) { s->failed_pc=0x0c0a29c0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a29c2;
P_0c0a29c2: /* original 63f1, guest PC 0x0c0a29c2 */
if(!s->budget--) { s->failed_pc=0x0c0a29c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a29c4;
P_0c0a29c4: /* original 5ce5, guest PC 0x0c0a29c4 */
if(!s->budget--) { s->failed_pc=0x0c0a29c4u; return 0; }
r[12]=read(ram,r[14]+20,4);
goto P_0c0a29c6;
P_0c0a29c6: /* original 0e35, guest PC 0x0c0a29c6 */
if(!s->budget--) { s->failed_pc=0x0c0a29c6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a29c8;
P_0c0a29c8: /* original 04ed, guest PC 0x0c0a29c8 */
if(!s->budget--) { s->failed_pc=0x0c0a29c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ca;
P_0c0a29ca: /* original d36d, guest PC 0x0c0a29ca */
if(!s->budget--) { s->failed_pc=0x0c0a29cau; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a29cc;
P_0c0a29cc: /* original 430b, guest PC 0x0c0a29cc */
if(!s->budget--) { s->failed_pc=0x0c0a29ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a29d0u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a29d0u) { target=s->pc; goto dispatch; }
goto P_0c0a29d0;
P_0c0a29ce: /* original 644d, guest PC 0x0c0a29ce */
if(!s->budget--) { s->failed_pc=0x0c0a29ceu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a29d0;
P_0c0a29d0: /* original eb00, guest PC 0x0c0a29d0 */
if(!s->budget--) { s->failed_pc=0x0c0a29d0u; return 0; }
r[11]=0x00000000u;
goto P_0c0a29d2;
P_0c0a29d2: /* original a039, guest PC 0x0c0a29d2 */
if(!s->budget--) { s->failed_pc=0x0c0a29d2u; return 0; }
r[8]=r[11];
goto P_0c0a2a48;
P_0c0a29d4: /* original 68b3, guest PC 0x0c0a29d4 */
if(!s->budget--) { s->failed_pc=0x0c0a29d4u; return 0; }
r[8]=r[11];
goto P_0c0a29d6;
P_0c0a29d6: /* original 53f1, guest PC 0x0c0a29d6 */
if(!s->budget--) { s->failed_pc=0x0c0a29d6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a29d8;
P_0c0a29d8: /* original 6d83, guest PC 0x0c0a29d8 */
if(!s->budget--) { s->failed_pc=0x0c0a29d8u; return 0; }
r[13]=r[8];
goto P_0c0a29da;
P_0c0a29da: /* original 4d08, guest PC 0x0c0a29da */
if(!s->budget--) { s->failed_pc=0x0c0a29dau; return 0; }
r[13]<<=2;
goto P_0c0a29dc;
P_0c0a29dc: /* original 3d3c, guest PC 0x0c0a29dc */
if(!s->budget--) { s->failed_pc=0x0c0a29dcu; return 0; }
r[13]+=r[3];
goto P_0c0a29de;
P_0c0a29de: /* original 60d2, guest PC 0x0c0a29de */
if(!s->budget--) { s->failed_pc=0x0c0a29deu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a29e0;
P_0c0a29e0: /* original 5001, guest PC 0x0c0a29e0 */
if(!s->budget--) { s->failed_pc=0x0c0a29e0u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a29e2;
P_0c0a29e2: /* original c801, guest PC 0x0c0a29e2 */
if(!s->budget--) { s->failed_pc=0x0c0a29e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a29e4;
P_0c0a29e4: /* original 8922, guest PC 0x0c0a29e4 */
if(!s->budget--) { s->failed_pc=0x0c0a29e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a2c; }
goto P_0c0a29e6;
P_0c0a29e6: /* original a008, guest PC 0x0c0a29e6 */
if(!s->budget--) { s->failed_pc=0x0c0a29e6u; return 0; }
r[4]=r[11];
goto P_0c0a29fa;
P_0c0a29e8: /* original 64b3, guest PC 0x0c0a29e8 */
if(!s->budget--) { s->failed_pc=0x0c0a29e8u; return 0; }
r[4]=r[11];
goto P_0c0a29ea;
P_0c0a29ea: /* original 6343, guest PC 0x0c0a29ea */
if(!s->budget--) { s->failed_pc=0x0c0a29eau; return 0; }
r[3]=r[4];
goto P_0c0a29ec;
P_0c0a29ec: /* original 4308, guest PC 0x0c0a29ec */
if(!s->budget--) { s->failed_pc=0x0c0a29ecu; return 0; }
r[3]<<=2;
goto P_0c0a29ee;
P_0c0a29ee: /* original 4308, guest PC 0x0c0a29ee */
if(!s->budget--) { s->failed_pc=0x0c0a29eeu; return 0; }
r[3]<<=2;
goto P_0c0a29f0;
P_0c0a29f0: /* original 33cc, guest PC 0x0c0a29f0 */
if(!s->budget--) { s->failed_pc=0x0c0a29f0u; return 0; }
r[3]+=r[12];
goto P_0c0a29f2;
P_0c0a29f2: /* original 5232, guest PC 0x0c0a29f2 */
if(!s->budget--) { s->failed_pc=0x0c0a29f2u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a29f4;
P_0c0a29f4: /* original 7401, guest PC 0x0c0a29f4 */
if(!s->budget--) { s->failed_pc=0x0c0a29f4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a29f6;
P_0c0a29f6: /* original 32ac, guest PC 0x0c0a29f6 */
if(!s->budget--) { s->failed_pc=0x0c0a29f6u; return 0; }
r[2]+=r[10];
goto P_0c0a29f8;
P_0c0a29f8: /* original 1322, guest PC 0x0c0a29f8 */
if(!s->budget--) { s->failed_pc=0x0c0a29f8u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a29fa;
P_0c0a29fa: /* original 85e7, guest PC 0x0c0a29fa */
if(!s->budget--) { s->failed_pc=0x0c0a29fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a29fc;
P_0c0a29fc: /* original 600d, guest PC 0x0c0a29fc */
if(!s->budget--) { s->failed_pc=0x0c0a29fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a29fe;
P_0c0a29fe: /* original 3403, guest PC 0x0c0a29fe */
if(!s->budget--) { s->failed_pc=0x0c0a29feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a00;
P_0c0a2a00: /* original 8bf3, guest PC 0x0c0a2a00 */
if(!s->budget--) { s->failed_pc=0x0c0a2a00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29ea; }
goto P_0c0a2a02;
P_0c0a2a02: /* original d260, guest PC 0x0c0a2a02 */
if(!s->budget--) { s->failed_pc=0x0c0a2a02u; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2a04;
P_0c0a2a04: /* original 65c3, guest PC 0x0c0a2a04 */
if(!s->budget--) { s->failed_pc=0x0c0a2a04u; return 0; }
r[5]=r[12];
goto P_0c0a2a06;
P_0c0a2a06: /* original 420b, guest PC 0x0c0a2a06 */
if(!s->budget--) { s->failed_pc=0x0c0a2a06u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2a0au;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a0au) { target=s->pc; goto dispatch; }
goto P_0c0a2a0a;
P_0c0a2a08: /* original 64d2, guest PC 0x0c0a2a08 */
if(!s->budget--) { s->failed_pc=0x0c0a2a08u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a0a;
P_0c0a2a0a: /* original 2008, guest PC 0x0c0a2a0a */
if(!s->budget--) { s->failed_pc=0x0c0a2a0au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a0c;
P_0c0a2a0c: /* original a008, guest PC 0x0c0a2a0c */
if(!s->budget--) { s->failed_pc=0x0c0a2a0cu; return 0; }
r[4]=r[11];
goto P_0c0a2a20;
P_0c0a2a0e: /* original 64b3, guest PC 0x0c0a2a0e */
if(!s->budget--) { s->failed_pc=0x0c0a2a0eu; return 0; }
r[4]=r[11];
goto P_0c0a2a10;
P_0c0a2a10: /* original 6343, guest PC 0x0c0a2a10 */
if(!s->budget--) { s->failed_pc=0x0c0a2a10u; return 0; }
r[3]=r[4];
goto P_0c0a2a12;
P_0c0a2a12: /* original 4308, guest PC 0x0c0a2a12 */
if(!s->budget--) { s->failed_pc=0x0c0a2a12u; return 0; }
r[3]<<=2;
goto P_0c0a2a14;
P_0c0a2a14: /* original 4308, guest PC 0x0c0a2a14 */
if(!s->budget--) { s->failed_pc=0x0c0a2a14u; return 0; }
r[3]<<=2;
goto P_0c0a2a16;
P_0c0a2a16: /* original 33cc, guest PC 0x0c0a2a16 */
if(!s->budget--) { s->failed_pc=0x0c0a2a16u; return 0; }
r[3]+=r[12];
goto P_0c0a2a18;
P_0c0a2a18: /* original 5232, guest PC 0x0c0a2a18 */
if(!s->budget--) { s->failed_pc=0x0c0a2a18u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2a1a;
P_0c0a2a1a: /* original 7401, guest PC 0x0c0a2a1a */
if(!s->budget--) { s->failed_pc=0x0c0a2a1au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2a1c;
P_0c0a2a1c: /* original 32a8, guest PC 0x0c0a2a1c */
if(!s->budget--) { s->failed_pc=0x0c0a2a1cu; return 0; }
r[2]-=r[10];
goto P_0c0a2a1e;
P_0c0a2a1e: /* original 1322, guest PC 0x0c0a2a1e */
if(!s->budget--) { s->failed_pc=0x0c0a2a1eu; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2a20;
P_0c0a2a20: /* original 85e7, guest PC 0x0c0a2a20 */
if(!s->budget--) { s->failed_pc=0x0c0a2a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a22;
P_0c0a2a22: /* original 600d, guest PC 0x0c0a2a22 */
if(!s->budget--) { s->failed_pc=0x0c0a2a22u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a24;
P_0c0a2a24: /* original 3403, guest PC 0x0c0a2a24 */
if(!s->budget--) { s->failed_pc=0x0c0a2a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a26;
P_0c0a2a26: /* original 8bf3, guest PC 0x0c0a2a26 */
if(!s->budget--) { s->failed_pc=0x0c0a2a26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a10; }
goto P_0c0a2a28;
P_0c0a2a28: /* original a00d, guest PC 0x0c0a2a28 */
if(!s->budget--) { s->failed_pc=0x0c0a2a28u; return 0; }
goto P_0c0a2a46;
P_0c0a2a2a: /* original 0009, guest PC 0x0c0a2a2a */
if(!s->budget--) { s->failed_pc=0x0c0a2a2au; return 0; }
goto P_0c0a2a2c;
P_0c0a2a2c: /* original 64d2, guest PC 0x0c0a2a2c */
if(!s->budget--) { s->failed_pc=0x0c0a2a2cu; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a2e;
P_0c0a2a2e: /* original 66a3, guest PC 0x0c0a2a2e */
if(!s->budget--) { s->failed_pc=0x0c0a2a2eu; return 0; }
r[6]=r[10];
goto P_0c0a2a30;
P_0c0a2a30: /* original d355, guest PC 0x0c0a2a30 */
if(!s->budget--) { s->failed_pc=0x0c0a2a30u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2a32;
P_0c0a2a32: /* original 65c3, guest PC 0x0c0a2a32 */
if(!s->budget--) { s->failed_pc=0x0c0a2a32u; return 0; }
r[5]=r[12];
goto P_0c0a2a34;
P_0c0a2a34: /* original 430b, guest PC 0x0c0a2a34 */
if(!s->budget--) { s->failed_pc=0x0c0a2a34u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a38u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a38u) { target=s->pc; goto dispatch; }
goto P_0c0a2a38;
P_0c0a2a36: /* original 5441, guest PC 0x0c0a2a36 */
if(!s->budget--) { s->failed_pc=0x0c0a2a36u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2a38;
P_0c0a2a38: /* original 69d2, guest PC 0x0c0a2a38 */
if(!s->budget--) { s->failed_pc=0x0c0a2a38u; return 0; }
tmp=read(ram,r[13],4);
r[9]=tmp;
goto P_0c0a2a3a;
P_0c0a2a3a: /* original 2008, guest PC 0x0c0a2a3a */
if(!s->budget--) { s->failed_pc=0x0c0a2a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a3c;
P_0c0a2a3c: /* original d353, guest PC 0x0c0a2a3c */
if(!s->budget--) { s->failed_pc=0x0c0a2a3cu; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2a3e;
P_0c0a2a3e: /* original 5591, guest PC 0x0c0a2a3e */
if(!s->budget--) { s->failed_pc=0x0c0a2a3eu; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2a40;
P_0c0a2a40: /* original 5692, guest PC 0x0c0a2a40 */
if(!s->budget--) { s->failed_pc=0x0c0a2a40u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2a42;
P_0c0a2a42: /* original 430b, guest PC 0x0c0a2a42 */
if(!s->budget--) { s->failed_pc=0x0c0a2a42u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a46u;
tmp=read(ram,r[9],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a46u) { target=s->pc; goto dispatch; }
goto P_0c0a2a46;
P_0c0a2a44: /* original 6492, guest PC 0x0c0a2a44 */
if(!s->budget--) { s->failed_pc=0x0c0a2a44u; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2a46;
P_0c0a2a46: /* original 7801, guest PC 0x0c0a2a46 */
if(!s->budget--) { s->failed_pc=0x0c0a2a46u; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2a48;
P_0c0a2a48: /* original 85e6, guest PC 0x0c0a2a48 */
if(!s->budget--) { s->failed_pc=0x0c0a2a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2a4a;
P_0c0a2a4a: /* original 600d, guest PC 0x0c0a2a4a */
if(!s->budget--) { s->failed_pc=0x0c0a2a4au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a4c;
P_0c0a2a4c: /* original 3803, guest PC 0x0c0a2a4c */
if(!s->budget--) { s->failed_pc=0x0c0a2a4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2a4e;
P_0c0a2a4e: /* original 8bc2, guest PC 0x0c0a2a4e */
if(!s->budget--) { s->failed_pc=0x0c0a2a4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29d6; }
goto P_0c0a2a50;
P_0c0a2a50: /* original 63f1, guest PC 0x0c0a2a50 */
if(!s->budget--) { s->failed_pc=0x0c0a2a50u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2a52;
P_0c0a2a52: /* original e222, guest PC 0x0c0a2a52 */
if(!s->budget--) { s->failed_pc=0x0c0a2a52u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2a54;
P_0c0a2a54: /* original 85e7, guest PC 0x0c0a2a54 */
if(!s->budget--) { s->failed_pc=0x0c0a2a54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a56;
P_0c0a2a56: /* original 32ec, guest PC 0x0c0a2a56 */
if(!s->budget--) { s->failed_pc=0x0c0a2a56u; return 0; }
r[2]+=r[14];
goto P_0c0a2a58;
P_0c0a2a58: /* original 64b3, guest PC 0x0c0a2a58 */
if(!s->budget--) { s->failed_pc=0x0c0a2a58u; return 0; }
r[4]=r[11];
goto P_0c0a2a5a;
P_0c0a2a5a: /* original 303c, guest PC 0x0c0a2a5a */
if(!s->budget--) { s->failed_pc=0x0c0a2a5au; return 0; }
r[0]+=r[3];
goto P_0c0a2a5c;
P_0c0a2a5c: /* original 2201, guest PC 0x0c0a2a5c */
if(!s->budget--) { s->failed_pc=0x0c0a2a5cu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2a5e;
P_0c0a2a5e: /* original 7f08, guest PC 0x0c0a2a5e */
if(!s->budget--) { s->failed_pc=0x0c0a2a5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2a60;
P_0c0a2a60: /* original 6043, guest PC 0x0c0a2a60 */
if(!s->budget--) { s->failed_pc=0x0c0a2a60u; return 0; }
r[0]=r[4];
goto P_0c0a2a62;
P_0c0a2a62: /* original 4f26, guest PC 0x0c0a2a62 */
if(!s->budget--) { s->failed_pc=0x0c0a2a62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2a64;
P_0c0a2a64: /* original 68f6, guest PC 0x0c0a2a64 */
if(!s->budget--) { s->failed_pc=0x0c0a2a64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2a66;
P_0c0a2a66: /* original 69f6, guest PC 0x0c0a2a66 */
if(!s->budget--) { s->failed_pc=0x0c0a2a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2a68;
P_0c0a2a68: /* original 6af6, guest PC 0x0c0a2a68 */
if(!s->budget--) { s->failed_pc=0x0c0a2a68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2a6a;
P_0c0a2a6a: /* original 6bf6, guest PC 0x0c0a2a6a */
if(!s->budget--) { s->failed_pc=0x0c0a2a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2a6c;
P_0c0a2a6c: /* original 6cf6, guest PC 0x0c0a2a6c */
if(!s->budget--) { s->failed_pc=0x0c0a2a6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2a6e;
P_0c0a2a6e: /* original 6df6, guest PC 0x0c0a2a6e */
if(!s->budget--) { s->failed_pc=0x0c0a2a6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2a70;
P_0c0a2a70: /* original 000b, guest PC 0x0c0a2a70 */
if(!s->budget--) { s->failed_pc=0x0c0a2a70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2a72: /* original 6ef6, guest PC 0x0c0a2a72 */
if(!s->budget--) { s->failed_pc=0x0c0a2a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2a74u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2a74u; return 0; } return 1;
P_0c0a2b98: /* original 2fe6, guest PC 0x0c0a2b98 */
if(!s->budget--) { s->failed_pc=0x0c0a2b98u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9a;
P_0c0a2b9a: /* original 6e43, guest PC 0x0c0a2b9a */
if(!s->budget--) { s->failed_pc=0x0c0a2b9au; return 0; }
r[14]=r[4];
goto P_0c0a2b9c;
P_0c0a2b9c: /* original 2fd6, guest PC 0x0c0a2b9c */
if(!s->budget--) { s->failed_pc=0x0c0a2b9cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9e;
P_0c0a2b9e: /* original 2fc6, guest PC 0x0c0a2b9e */
if(!s->budget--) { s->failed_pc=0x0c0a2b9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba0;
P_0c0a2ba0: /* original 2fb6, guest PC 0x0c0a2ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba2;
P_0c0a2ba2: /* original 2fa6, guest PC 0x0c0a2ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba4;
P_0c0a2ba4: /* original 2f96, guest PC 0x0c0a2ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba6;
P_0c0a2ba6: /* original 2f86, guest PC 0x0c0a2ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba8;
P_0c0a2ba8: /* original 60e2, guest PC 0x0c0a2ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a2baa;
P_0c0a2baa: /* original 4f22, guest PC 0x0c0a2baa */
if(!s->budget--) { s->failed_pc=0x0c0a2baau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2bac;
P_0c0a2bac: /* original c880, guest PC 0x0c0a2bac */
if(!s->budget--) { s->failed_pc=0x0c0a2bacu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2bae;
P_0c0a2bae: /* original 8938, guest PC 0x0c0a2bae */
if(!s->budget--) { s->failed_pc=0x0c0a2baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bb0;
P_0c0a2bb0: /* original 62e2, guest PC 0x0c0a2bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a2bb2;
P_0c0a2bb2: /* original d33b, guest PC 0x0c0a2bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb2u; return 0; }
r[3]=read(ram,0x0c0a2ca0u,4);
goto P_0c0a2bb4;
P_0c0a2bb4: /* original 9173, guest PC 0x0c0a2bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2c9eu,2);
goto P_0c0a2bb6;
P_0c0a2bb6: /* original 2239, guest PC 0x0c0a2bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb6u; return 0; }
r[2]&=r[3];
goto P_0c0a2bb8;
P_0c0a2bb8: /* original 3210, guest PC 0x0c0a2bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a2bba;
P_0c0a2bba: /* original 8905, guest PC 0x0c0a2bba */
if(!s->budget--) { s->failed_pc=0x0c0a2bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2bc8; }
goto P_0c0a2bbc;
P_0c0a2bbc: /* original d239, guest PC 0x0c0a2bbc */
if(!s->budget--) { s->failed_pc=0x0c0a2bbcu; return 0; }
r[2]=read(ram,0x0c0a2ca4u,4);
goto P_0c0a2bbe;
P_0c0a2bbe: /* original e56a, guest PC 0x0c0a2bbe */
if(!s->budget--) { s->failed_pc=0x0c0a2bbeu; return 0; }
r[5]=0x0000006au;
goto P_0c0a2bc0;
P_0c0a2bc0: /* original 420b, guest PC 0x0c0a2bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2bc4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2bc4u) { target=s->pc; goto dispatch; }
goto P_0c0a2bc4;
P_0c0a2bc2: /* original e401, guest PC 0x0c0a2bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2bc4;
P_0c0a2bc4: /* original a02e, guest PC 0x0c0a2bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2c24;
P_0c0a2bc6: /* original e0ff, guest PC 0x0c0a2bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2bc8;
P_0c0a2bc8: /* original e020, guest PC 0x0c0a2bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc8u; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bca;
P_0c0a2bca: /* original 03ed, guest PC 0x0c0a2bca */
if(!s->budget--) { s->failed_pc=0x0c0a2bcau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bcc;
P_0c0a2bcc: /* original e022, guest PC 0x0c0a2bcc */
if(!s->budget--) { s->failed_pc=0x0c0a2bccu; return 0; }
r[0]=0x00000022u;
goto P_0c0a2bce;
P_0c0a2bce: /* original 02ed, guest PC 0x0c0a2bce */
if(!s->budget--) { s->failed_pc=0x0c0a2bceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bd0;
P_0c0a2bd0: /* original 633d, guest PC 0x0c0a2bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2bd2;
P_0c0a2bd2: /* original 622d, guest PC 0x0c0a2bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd2u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2bd4;
P_0c0a2bd4: /* original 232b, guest PC 0x0c0a2bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd4u; return 0; }
r[3]|=r[2];
goto P_0c0a2bd6;
P_0c0a2bd6: /* original 2338, guest PC 0x0c0a2bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2bd8;
P_0c0a2bd8: /* original 8923, guest PC 0x0c0a2bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bda;
P_0c0a2bda: /* original e020, guest PC 0x0c0a2bda */
if(!s->budget--) { s->failed_pc=0x0c0a2bdau; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bdc;
P_0c0a2bdc: /* original d332, guest PC 0x0c0a2bdc */
if(!s->budget--) { s->failed_pc=0x0c0a2bdcu; return 0; }
r[3]=read(ram,0x0c0a2ca8u,4);
goto P_0c0a2bde;
P_0c0a2bde: /* original 04ed, guest PC 0x0c0a2bde */
if(!s->budget--) { s->failed_pc=0x0c0a2bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2be0;
P_0c0a2be0: /* original 430b, guest PC 0x0c0a2be0 */
if(!s->budget--) { s->failed_pc=0x0c0a2be0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2be4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2be4u) { target=s->pc; goto dispatch; }
goto P_0c0a2be4;
P_0c0a2be2: /* original 644d, guest PC 0x0c0a2be2 */
if(!s->budget--) { s->failed_pc=0x0c0a2be2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2be4;
P_0c0a2be4: /* original d932, guest PC 0x0c0a2be4 */
if(!s->budget--) { s->failed_pc=0x0c0a2be4u; return 0; }
r[9]=read(ram,0x0c0a2cb0u,4);
goto P_0c0a2be6;
P_0c0a2be6: /* original eb01, guest PC 0x0c0a2be6 */
if(!s->budget--) { s->failed_pc=0x0c0a2be6u; return 0; }
r[11]=0x00000001u;
goto P_0c0a2be8;
P_0c0a2be8: /* original d830, guest PC 0x0c0a2be8 */
if(!s->budget--) { s->failed_pc=0x0c0a2be8u; return 0; }
r[8]=read(ram,0x0c0a2cacu,4);
goto P_0c0a2bea;
P_0c0a2bea: /* original 5ae4, guest PC 0x0c0a2bea */
if(!s->budget--) { s->failed_pc=0x0c0a2beau; return 0; }
r[10]=read(ram,r[14]+16,4);
goto P_0c0a2bec;
P_0c0a2bec: /* original a010, guest PC 0x0c0a2bec */
if(!s->budget--) { s->failed_pc=0x0c0a2becu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2c10;
P_0c0a2bee: /* original ec00, guest PC 0x0c0a2bee */
if(!s->budget--) { s->failed_pc=0x0c0a2beeu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2bf0;
P_0c0a2bf0: /* original 6dc3, guest PC 0x0c0a2bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf0u; return 0; }
r[13]=r[12];
goto P_0c0a2bf2;
P_0c0a2bf2: /* original 4d08, guest PC 0x0c0a2bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf2u; return 0; }
r[13]<<=2;
goto P_0c0a2bf4;
P_0c0a2bf4: /* original 3dac, guest PC 0x0c0a2bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf4u; return 0; }
r[13]+=r[10];
goto P_0c0a2bf6;
P_0c0a2bf6: /* original 63d2, guest PC 0x0c0a2bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0a2bf8;
P_0c0a2bf8: /* original 5231, guest PC 0x0c0a2bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2bfa;
P_0c0a2bfa: /* original 22b8, guest PC 0x0c0a2bfa */
if(!s->budget--) { s->failed_pc=0x0c0a2bfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0a2bfc;
P_0c0a2bfc: /* original 8903, guest PC 0x0c0a2bfc */
if(!s->budget--) { s->failed_pc=0x0c0a2bfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c06; }
goto P_0c0a2bfe;
P_0c0a2bfe: /* original 480b, guest PC 0x0c0a2bfe */
if(!s->budget--) { s->failed_pc=0x0c0a2bfeu; return 0; }
target=r[8];
r[16]=code_base|0x0c0a2c02u;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c02u) { target=s->pc; goto dispatch; }
goto P_0c0a2c02;
P_0c0a2c00: /* original 64d2, guest PC 0x0c0a2c00 */
if(!s->budget--) { s->failed_pc=0x0c0a2c00u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c02;
P_0c0a2c02: /* original a004, guest PC 0x0c0a2c02 */
if(!s->budget--) { s->failed_pc=0x0c0a2c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c04: /* original 2008, guest PC 0x0c0a2c04 */
if(!s->budget--) { s->failed_pc=0x0c0a2c04u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c06;
P_0c0a2c06: /* original 64d2, guest PC 0x0c0a2c06 */
if(!s->budget--) { s->failed_pc=0x0c0a2c06u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c08;
P_0c0a2c08: /* original 490b, guest PC 0x0c0a2c08 */
if(!s->budget--) { s->failed_pc=0x0c0a2c08u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a2c0cu;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c0cu) { target=s->pc; goto dispatch; }
goto P_0c0a2c0c;
P_0c0a2c0a: /* original 5441, guest PC 0x0c0a2c0a */
if(!s->budget--) { s->failed_pc=0x0c0a2c0au; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2c0c;
P_0c0a2c0c: /* original 2008, guest PC 0x0c0a2c0c */
if(!s->budget--) { s->failed_pc=0x0c0a2c0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c0e: /* original 7c01, guest PC 0x0c0a2c0e */
if(!s->budget--) { s->failed_pc=0x0c0a2c0eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a2c10;
P_0c0a2c10: /* original 85e6, guest PC 0x0c0a2c10 */
if(!s->budget--) { s->failed_pc=0x0c0a2c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2c12;
P_0c0a2c12: /* original 600d, guest PC 0x0c0a2c12 */
if(!s->budget--) { s->failed_pc=0x0c0a2c12u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2c14;
P_0c0a2c14: /* original 3c03, guest PC 0x0c0a2c14 */
if(!s->budget--) { s->failed_pc=0x0c0a2c14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a2c16;
P_0c0a2c16: /* original 8beb, guest PC 0x0c0a2c16 */
if(!s->budget--) { s->failed_pc=0x0c0a2c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2bf0; }
goto P_0c0a2c18;
P_0c0a2c18: /* original e022, guest PC 0x0c0a2c18 */
if(!s->budget--) { s->failed_pc=0x0c0a2c18u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2c1a;
P_0c0a2c1a: /* original e200, guest PC 0x0c0a2c1a */
if(!s->budget--) { s->failed_pc=0x0c0a2c1au; return 0; }
r[2]=0x00000000u;
goto P_0c0a2c1c;
P_0c0a2c1c: /* original 0e25, guest PC 0x0c0a2c1c */
if(!s->budget--) { s->failed_pc=0x0c0a2c1cu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c1e;
P_0c0a2c1e: /* original e020, guest PC 0x0c0a2c1e */
if(!s->budget--) { s->failed_pc=0x0c0a2c1eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2c20;
P_0c0a2c20: /* original 0e25, guest PC 0x0c0a2c20 */
if(!s->budget--) { s->failed_pc=0x0c0a2c20u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c22;
P_0c0a2c22: /* original e000, guest PC 0x0c0a2c22 */
if(!s->budget--) { s->failed_pc=0x0c0a2c22u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2c24;
P_0c0a2c24: /* original 4f26, guest PC 0x0c0a2c24 */
if(!s->budget--) { s->failed_pc=0x0c0a2c24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2c26;
P_0c0a2c26: /* original 68f6, guest PC 0x0c0a2c26 */
if(!s->budget--) { s->failed_pc=0x0c0a2c26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2c28;
P_0c0a2c28: /* original 69f6, guest PC 0x0c0a2c28 */
if(!s->budget--) { s->failed_pc=0x0c0a2c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2c2a;
P_0c0a2c2a: /* original 6af6, guest PC 0x0c0a2c2a */
if(!s->budget--) { s->failed_pc=0x0c0a2c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2c2c;
P_0c0a2c2c: /* original 6bf6, guest PC 0x0c0a2c2c */
if(!s->budget--) { s->failed_pc=0x0c0a2c2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2c2e;
P_0c0a2c2e: /* original 6cf6, guest PC 0x0c0a2c2e */
if(!s->budget--) { s->failed_pc=0x0c0a2c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2c30;
P_0c0a2c30: /* original 6df6, guest PC 0x0c0a2c30 */
if(!s->budget--) { s->failed_pc=0x0c0a2c30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2c32;
P_0c0a2c32: /* original 000b, guest PC 0x0c0a2c32 */
if(!s->budget--) { s->failed_pc=0x0c0a2c32u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2c34: /* original 6ef6, guest PC 0x0c0a2c34 */
if(!s->budget--) { s->failed_pc=0x0c0a2c34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2c36u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
