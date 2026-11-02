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
int vf3_away_batch25_adapter_27(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a7850u: goto P_0c0a7850;
case 0x0c0a7852u: goto P_0c0a7852;
case 0x0c0a7854u: goto P_0c0a7854;
case 0x0c0a7856u: goto P_0c0a7856;
case 0x0c0a7858u: goto P_0c0a7858;
case 0x0c0a785au: goto P_0c0a785a;
case 0x0c0a785cu: goto P_0c0a785c;
case 0x0c0a785eu: goto P_0c0a785e;
case 0x0c0a7860u: goto P_0c0a7860;
case 0x0c0a7862u: goto P_0c0a7862;
case 0x0c0a7864u: goto P_0c0a7864;
case 0x0c0a7866u: goto P_0c0a7866;
case 0x0c0a7868u: goto P_0c0a7868;
case 0x0c0a786au: goto P_0c0a786a;
case 0x0c0a786cu: goto P_0c0a786c;
case 0x0c0a786eu: goto P_0c0a786e;
case 0x0c0a7870u: goto P_0c0a7870;
case 0x0c0a7872u: goto P_0c0a7872;
case 0x0c0a7874u: goto P_0c0a7874;
case 0x0c0a7876u: goto P_0c0a7876;
case 0x0c0a7878u: goto P_0c0a7878;
case 0x0c0a787au: goto P_0c0a787a;
case 0x0c0a787cu: goto P_0c0a787c;
case 0x0c0a787eu: goto P_0c0a787e;
case 0x0c0a7880u: goto P_0c0a7880;
case 0x0c0a7882u: goto P_0c0a7882;
case 0x0c0a7884u: goto P_0c0a7884;
case 0x0c0a7886u: goto P_0c0a7886;
case 0x0c0a7888u: goto P_0c0a7888;
case 0x0c0a788au: goto P_0c0a788a;
case 0x0c0a788cu: goto P_0c0a788c;
case 0x0c0a788eu: goto P_0c0a788e;
case 0x0c0a7890u: goto P_0c0a7890;
case 0x0c0a7892u: goto P_0c0a7892;
case 0x0c0a7894u: goto P_0c0a7894;
case 0x0c0a7896u: goto P_0c0a7896;
case 0x0c0a7898u: goto P_0c0a7898;
case 0x0c0a789au: goto P_0c0a789a;
case 0x0c0a789cu: goto P_0c0a789c;
case 0x0c0a789eu: goto P_0c0a789e;
case 0x0c0a78a0u: goto P_0c0a78a0;
case 0x0c0a78a2u: goto P_0c0a78a2;
case 0x0c0a78a4u: goto P_0c0a78a4;
case 0x0c0a78a6u: goto P_0c0a78a6;
case 0x0c0a78a8u: goto P_0c0a78a8;
case 0x0c0a78aau: goto P_0c0a78aa;
case 0x0c0a7908u: goto P_0c0a7908;
case 0x0c0a790au: goto P_0c0a790a;
case 0x0c0a790cu: goto P_0c0a790c;
case 0x0c0a790eu: goto P_0c0a790e;
case 0x0c0a7910u: goto P_0c0a7910;
case 0x0c0a7912u: goto P_0c0a7912;
case 0x0c0a7914u: goto P_0c0a7914;
case 0x0c0a7916u: goto P_0c0a7916;
case 0x0c0a7918u: goto P_0c0a7918;
case 0x0c0a791au: goto P_0c0a791a;
case 0x0c0a791cu: goto P_0c0a791c;
case 0x0c0a791eu: goto P_0c0a791e;
case 0x0c0a7920u: goto P_0c0a7920;
case 0x0c0a7922u: goto P_0c0a7922;
case 0x0c0a7924u: goto P_0c0a7924;
case 0x0c0a7926u: goto P_0c0a7926;
case 0x0c0a7928u: goto P_0c0a7928;
case 0x0c0a792au: goto P_0c0a792a;
case 0x0c0a792cu: goto P_0c0a792c;
case 0x0c0a792eu: goto P_0c0a792e;
case 0x0c0a7930u: goto P_0c0a7930;
case 0x0c0a7932u: goto P_0c0a7932;
case 0x0c0a7934u: goto P_0c0a7934;
case 0x0c0a7936u: goto P_0c0a7936;
case 0x0c0a7938u: goto P_0c0a7938;
case 0x0c0a793au: goto P_0c0a793a;
case 0x0c0a793cu: goto P_0c0a793c;
case 0x0c0a793eu: goto P_0c0a793e;
case 0x0c0a7940u: goto P_0c0a7940;
case 0x0c0a7942u: goto P_0c0a7942;
case 0x0c0a7944u: goto P_0c0a7944;
case 0x0c0a7946u: goto P_0c0a7946;
case 0x0c0a7948u: goto P_0c0a7948;
case 0x0c0a794au: goto P_0c0a794a;
case 0x0c0a7978u: goto P_0c0a7978;
case 0x0c0a797au: goto P_0c0a797a;
case 0x0c0a797cu: goto P_0c0a797c;
case 0x0c0a797eu: goto P_0c0a797e;
case 0x0c0a7980u: goto P_0c0a7980;
case 0x0c0a7982u: goto P_0c0a7982;
case 0x0c0a7984u: goto P_0c0a7984;
case 0x0c0a7986u: goto P_0c0a7986;
case 0x0c0a7988u: goto P_0c0a7988;
case 0x0c0a798au: goto P_0c0a798a;
case 0x0c0a798cu: goto P_0c0a798c;
case 0x0c0a798eu: goto P_0c0a798e;
case 0x0c0a7990u: goto P_0c0a7990;
case 0x0c0a7992u: goto P_0c0a7992;
case 0x0c0a7994u: goto P_0c0a7994;
case 0x0c0a7996u: goto P_0c0a7996;
case 0x0c0a7998u: goto P_0c0a7998;
case 0x0c0a799au: goto P_0c0a799a;
case 0x0c0a799cu: goto P_0c0a799c;
case 0x0c0a799eu: goto P_0c0a799e;
case 0x0c0a79a0u: goto P_0c0a79a0;
case 0x0c0a79a2u: goto P_0c0a79a2;
case 0x0c0a79a4u: goto P_0c0a79a4;
case 0x0c0a79a6u: goto P_0c0a79a6;
case 0x0c0a79a8u: goto P_0c0a79a8;
case 0x0c0a79aau: goto P_0c0a79aa;
case 0x0c0a79acu: goto P_0c0a79ac;
case 0x0c0a79aeu: goto P_0c0a79ae;
case 0x0c0a79b0u: goto P_0c0a79b0;
case 0x0c0a79b2u: goto P_0c0a79b2;
case 0x0c0a79b4u: goto P_0c0a79b4;
case 0x0c0a79b6u: goto P_0c0a79b6;
case 0x0c0a79b8u: goto P_0c0a79b8;
case 0x0c0a79bau: goto P_0c0a79ba;
case 0x0c0a79bcu: goto P_0c0a79bc;
case 0x0c0a79beu: goto P_0c0a79be;
case 0x0c0a79c0u: goto P_0c0a79c0;
case 0x0c0a79c2u: goto P_0c0a79c2;
case 0x0c0a79c4u: goto P_0c0a79c4;
case 0x0c0a79c6u: goto P_0c0a79c6;
case 0x0c0a79c8u: goto P_0c0a79c8;
case 0x0c0a79cau: goto P_0c0a79ca;
case 0x0c0a79ccu: goto P_0c0a79cc;
case 0x0c0a79ceu: goto P_0c0a79ce;
case 0x0c0a79d0u: goto P_0c0a79d0;
case 0x0c0a79d2u: goto P_0c0a79d2;
case 0x0c0a79d4u: goto P_0c0a79d4;
case 0x0c0a79d6u: goto P_0c0a79d6;
case 0x0c0a79d8u: goto P_0c0a79d8;
case 0x0c0a79dau: goto P_0c0a79da;
case 0x0c0a79dcu: goto P_0c0a79dc;
case 0x0c0a79deu: goto P_0c0a79de;
case 0x0c0a79e0u: goto P_0c0a79e0;
case 0x0c0a79e2u: goto P_0c0a79e2;
case 0x0c0a79e4u: goto P_0c0a79e4;
case 0x0c0a79e6u: goto P_0c0a79e6;
case 0x0c0a79e8u: goto P_0c0a79e8;
case 0x0c0a79eau: goto P_0c0a79ea;
case 0x0c0a79ecu: goto P_0c0a79ec;
case 0x0c0a79eeu: goto P_0c0a79ee;
case 0x0c0a79f0u: goto P_0c0a79f0;
case 0x0c0a79f2u: goto P_0c0a79f2;
case 0x0c0a79f4u: goto P_0c0a79f4;
case 0x0c0a79f6u: goto P_0c0a79f6;
case 0x0c0a79f8u: goto P_0c0a79f8;
case 0x0c0a79fau: goto P_0c0a79fa;
case 0x0c0a79fcu: goto P_0c0a79fc;
case 0x0c0a79feu: goto P_0c0a79fe;
case 0x0c0a7a00u: goto P_0c0a7a00;
case 0x0c0a7a02u: goto P_0c0a7a02;
case 0x0c0a7a04u: goto P_0c0a7a04;
case 0x0c0a7a06u: goto P_0c0a7a06;
case 0x0c0a7a08u: goto P_0c0a7a08;
case 0x0c0a7a0au: goto P_0c0a7a0a;
case 0x0c0a7a0cu: goto P_0c0a7a0c;
case 0x0c0a7a0eu: goto P_0c0a7a0e;
case 0x0c0a7a10u: goto P_0c0a7a10;
case 0x0c0a7a12u: goto P_0c0a7a12;
case 0x0c0a7a14u: goto P_0c0a7a14;
case 0x0c0a7a16u: goto P_0c0a7a16;
case 0x0c0a7a18u: goto P_0c0a7a18;
case 0x0c0a7a1au: goto P_0c0a7a1a;
case 0x0c0a7a1cu: goto P_0c0a7a1c;
case 0x0c0a7a1eu: goto P_0c0a7a1e;
case 0x0c0a7a20u: goto P_0c0a7a20;
case 0x0c0a7a22u: goto P_0c0a7a22;
case 0x0c0a7a24u: goto P_0c0a7a24;
case 0x0c0a7a26u: goto P_0c0a7a26;
case 0x0c0a7a28u: goto P_0c0a7a28;
case 0x0c0a7a2au: goto P_0c0a7a2a;
case 0x0c0a7a2cu: goto P_0c0a7a2c;
case 0x0c0a7a2eu: goto P_0c0a7a2e;
case 0x0c0a7a30u: goto P_0c0a7a30;
case 0x0c0a7a32u: goto P_0c0a7a32;
case 0x0c0a7a34u: goto P_0c0a7a34;
case 0x0c0a7a36u: goto P_0c0a7a36;
case 0x0c0a7a38u: goto P_0c0a7a38;
case 0x0c0a7a3au: goto P_0c0a7a3a;
case 0x0c0a7a3cu: goto P_0c0a7a3c;
case 0x0c0a7a3eu: goto P_0c0a7a3e;
case 0x0c0a7a40u: goto P_0c0a7a40;
case 0x0c0a7a42u: goto P_0c0a7a42;
case 0x0c0a7a44u: goto P_0c0a7a44;
case 0x0c0a7a46u: goto P_0c0a7a46;
case 0x0c0a7a48u: goto P_0c0a7a48;
case 0x0c0a7a4au: goto P_0c0a7a4a;
case 0x0c0a7a4cu: goto P_0c0a7a4c;
case 0x0c0a7a4eu: goto P_0c0a7a4e;
case 0x0c0a7a50u: goto P_0c0a7a50;
case 0x0c0a7a52u: goto P_0c0a7a52;
case 0x0c0a7a54u: goto P_0c0a7a54;
case 0x0c0a7a56u: goto P_0c0a7a56;
case 0x0c0a7a58u: goto P_0c0a7a58;
case 0x0c0a7a5au: goto P_0c0a7a5a;
case 0x0c0a7a5cu: goto P_0c0a7a5c;
case 0x0c0a7a5eu: goto P_0c0a7a5e;
case 0x0c0a7a60u: goto P_0c0a7a60;
case 0x0c0a7a62u: goto P_0c0a7a62;
case 0x0c0a7a64u: goto P_0c0a7a64;
case 0x0c0a7a66u: goto P_0c0a7a66;
case 0x0c0a7a68u: goto P_0c0a7a68;
case 0x0c0a7a6au: goto P_0c0a7a6a;
case 0x0c0a7a6cu: goto P_0c0a7a6c;
case 0x0c0a7a6eu: goto P_0c0a7a6e;
case 0x0c0a7a70u: goto P_0c0a7a70;
case 0x0c0a7a72u: goto P_0c0a7a72;
case 0x0c0a7a74u: goto P_0c0a7a74;
case 0x0c0a7a76u: goto P_0c0a7a76;
case 0x0c0a7a78u: goto P_0c0a7a78;
case 0x0c0a7a7au: goto P_0c0a7a7a;
case 0x0c0a7a7cu: goto P_0c0a7a7c;
case 0x0c0a7a7eu: goto P_0c0a7a7e;
case 0x0c0a7a80u: goto P_0c0a7a80;
case 0x0c0a7a82u: goto P_0c0a7a82;
case 0x0c0a7a84u: goto P_0c0a7a84;
case 0x0c0a7a86u: goto P_0c0a7a86;
case 0x0c0a7a88u: goto P_0c0a7a88;
case 0x0c0a7a8au: goto P_0c0a7a8a;
case 0x0c0a7a8cu: goto P_0c0a7a8c;
case 0x0c0a7a8eu: goto P_0c0a7a8e;
case 0x0c0a7a90u: goto P_0c0a7a90;
case 0x0c0a7a92u: goto P_0c0a7a92;
case 0x0c0a7a94u: goto P_0c0a7a94;
case 0x0c0a7a96u: goto P_0c0a7a96;
case 0x0c0a7a98u: goto P_0c0a7a98;
case 0x0c0a7a9au: goto P_0c0a7a9a;
case 0x0c0a7a9cu: goto P_0c0a7a9c;
case 0x0c0a7a9eu: goto P_0c0a7a9e;
case 0x0c0a7aa0u: goto P_0c0a7aa0;
case 0x0c0a7aa2u: goto P_0c0a7aa2;
case 0x0c0a7ae0u: goto P_0c0a7ae0;
case 0x0c0a7ae2u: goto P_0c0a7ae2;
case 0x0c0a7ae4u: goto P_0c0a7ae4;
case 0x0c0a7ae6u: goto P_0c0a7ae6;
case 0x0c0a7ae8u: goto P_0c0a7ae8;
case 0x0c0a7aeau: goto P_0c0a7aea;
case 0x0c0a7aecu: goto P_0c0a7aec;
case 0x0c0a7aeeu: goto P_0c0a7aee;
case 0x0c0a7af0u: goto P_0c0a7af0;
case 0x0c0a7af2u: goto P_0c0a7af2;
case 0x0c0a7af4u: goto P_0c0a7af4;
case 0x0c0a7af6u: goto P_0c0a7af6;
case 0x0c0a7af8u: goto P_0c0a7af8;
case 0x0c0a7afau: goto P_0c0a7afa;
case 0x0c0a7afcu: goto P_0c0a7afc;
case 0x0c0a7afeu: goto P_0c0a7afe;
case 0x0c0a7b00u: goto P_0c0a7b00;
case 0x0c0a7b02u: goto P_0c0a7b02;
case 0x0c0a7b04u: goto P_0c0a7b04;
case 0x0c0a7b06u: goto P_0c0a7b06;
case 0x0c0a7b08u: goto P_0c0a7b08;
case 0x0c0a7b0au: goto P_0c0a7b0a;
case 0x0c0a7b0cu: goto P_0c0a7b0c;
case 0x0c0a7b0eu: goto P_0c0a7b0e;
case 0x0c0a7b10u: goto P_0c0a7b10;
case 0x0c0a7b12u: goto P_0c0a7b12;
case 0x0c0a7b14u: goto P_0c0a7b14;
case 0x0c0a7b16u: goto P_0c0a7b16;
case 0x0c0a7b18u: goto P_0c0a7b18;
case 0x0c0a7f14u: goto P_0c0a7f14;
case 0x0c0a7f16u: goto P_0c0a7f16;
case 0x0c0a7f18u: goto P_0c0a7f18;
case 0x0c0a7f1au: goto P_0c0a7f1a;
case 0x0c0a7f1cu: goto P_0c0a7f1c;
case 0x0c0a7f1eu: goto P_0c0a7f1e;
case 0x0c0a7f20u: goto P_0c0a7f20;
case 0x0c0a7f22u: goto P_0c0a7f22;
case 0x0c0a7f24u: goto P_0c0a7f24;
case 0x0c0a7f26u: goto P_0c0a7f26;
case 0x0c0a7f28u: goto P_0c0a7f28;
case 0x0c0a7f2au: goto P_0c0a7f2a;
case 0x0c0a7f2cu: goto P_0c0a7f2c;
case 0x0c0a7f2eu: goto P_0c0a7f2e;
case 0x0c0a7f30u: goto P_0c0a7f30;
case 0x0c0a7f32u: goto P_0c0a7f32;
case 0x0c0a7f34u: goto P_0c0a7f34;
case 0x0c0a7f36u: goto P_0c0a7f36;
case 0x0c0a7f38u: goto P_0c0a7f38;
case 0x0c0a7f3au: goto P_0c0a7f3a;
case 0x0c0a7f3cu: goto P_0c0a7f3c;
case 0x0c0a7f3eu: goto P_0c0a7f3e;
case 0x0c0a7f40u: goto P_0c0a7f40;
case 0x0c0a7f42u: goto P_0c0a7f42;
case 0x0c0a7f44u: goto P_0c0a7f44;
case 0x0c0a7f46u: goto P_0c0a7f46;
case 0x0c0a7f48u: goto P_0c0a7f48;
case 0x0c0a7f4au: goto P_0c0a7f4a;
case 0x0c0a7f4cu: goto P_0c0a7f4c;
case 0x0c0a7f4eu: goto P_0c0a7f4e;
case 0x0c0a7f50u: goto P_0c0a7f50;
case 0x0c0a7f52u: goto P_0c0a7f52;
case 0x0c0a7f54u: goto P_0c0a7f54;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a7850: /* original d43f, guest PC 0x0c0a7850 */
if(!s->budget--) { s->failed_pc=0x0c0a7850u; return 0; }
r[4]=read(ram,0x0c0a7950u,4);
goto P_0c0a7852;
P_0c0a7852: /* original e040, guest PC 0x0c0a7852 */
if(!s->budget--) { s->failed_pc=0x0c0a7852u; return 0; }
r[0]=0x00000040u;
goto P_0c0a7854;
P_0c0a7854: /* original f447, guest PC 0x0c0a7854 */
if(!s->budget--) { s->failed_pc=0x0c0a7854u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0a7856;
P_0c0a7856: /* original e044, guest PC 0x0c0a7856 */
if(!s->budget--) { s->failed_pc=0x0c0a7856u; return 0; }
r[0]=0x00000044u;
goto P_0c0a7858;
P_0c0a7858: /* original f457, guest PC 0x0c0a7858 */
if(!s->budget--) { s->failed_pc=0x0c0a7858u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0a785a;
P_0c0a785a: /* original e048, guest PC 0x0c0a785a */
if(!s->budget--) { s->failed_pc=0x0c0a785au; return 0; }
r[0]=0x00000048u;
goto P_0c0a785c;
P_0c0a785c: /* original a000, guest PC 0x0c0a785c */
if(!s->budget--) { s->failed_pc=0x0c0a785cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a7860;
P_0c0a785e: /* original f467, guest PC 0x0c0a785e */
if(!s->budget--) { s->failed_pc=0x0c0a785eu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a7860;
P_0c0a7860: /* original 2fe6, guest PC 0x0c0a7860 */
if(!s->budget--) { s->failed_pc=0x0c0a7860u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7862;
P_0c0a7862: /* original e040, guest PC 0x0c0a7862 */
if(!s->budget--) { s->failed_pc=0x0c0a7862u; return 0; }
r[0]=0x00000040u;
goto P_0c0a7864;
P_0c0a7864: /* original de3a, guest PC 0x0c0a7864 */
if(!s->budget--) { s->failed_pc=0x0c0a7864u; return 0; }
r[14]=read(ram,0x0c0a7950u,4);
goto P_0c0a7866;
P_0c0a7866: /* original 4f22, guest PC 0x0c0a7866 */
if(!s->budget--) { s->failed_pc=0x0c0a7866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7868;
P_0c0a7868: /* original f4e6, guest PC 0x0c0a7868 */
if(!s->budget--) { s->failed_pc=0x0c0a7868u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a786a;
P_0c0a786a: /* original e044, guest PC 0x0c0a786a */
if(!s->budget--) { s->failed_pc=0x0c0a786au; return 0; }
r[0]=0x00000044u;
goto P_0c0a786c;
P_0c0a786c: /* original f5e6, guest PC 0x0c0a786c */
if(!s->budget--) { s->failed_pc=0x0c0a786cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a786e;
P_0c0a786e: /* original e048, guest PC 0x0c0a786e */
if(!s->budget--) { s->failed_pc=0x0c0a786eu; return 0; }
r[0]=0x00000048u;
goto P_0c0a7870;
P_0c0a7870: /* original d338, guest PC 0x0c0a7870 */
if(!s->budget--) { s->failed_pc=0x0c0a7870u; return 0; }
r[3]=read(ram,0x0c0a7954u,4);
goto P_0c0a7872;
P_0c0a7872: /* original 7ff4, guest PC 0x0c0a7872 */
if(!s->budget--) { s->failed_pc=0x0c0a7872u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7874;
P_0c0a7874: /* original f6e6, guest PC 0x0c0a7874 */
if(!s->budget--) { s->failed_pc=0x0c0a7874u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0a7876;
P_0c0a7876: /* original 430b, guest PC 0x0c0a7876 */
if(!s->budget--) { s->failed_pc=0x0c0a7876u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a787au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a787au) { target=s->pc; goto dispatch; }
goto P_0c0a787a;
P_0c0a7878: /* original e400, guest PC 0x0c0a7878 */
if(!s->budget--) { s->failed_pc=0x0c0a7878u; return 0; }
r[4]=0x00000000u;
goto P_0c0a787a;
P_0c0a787a: /* original d237, guest PC 0x0c0a787a */
if(!s->budget--) { s->failed_pc=0x0c0a787au; return 0; }
r[2]=read(ram,0x0c0a7958u,4);
goto P_0c0a787c;
P_0c0a787c: /* original 420b, guest PC 0x0c0a787c */
if(!s->budget--) { s->failed_pc=0x0c0a787cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7880u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7880u) { target=s->pc; goto dispatch; }
goto P_0c0a7880;
P_0c0a787e: /* original e400, guest PC 0x0c0a787e */
if(!s->budget--) { s->failed_pc=0x0c0a787eu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7880;
P_0c0a7880: /* original d336, guest PC 0x0c0a7880 */
if(!s->budget--) { s->failed_pc=0x0c0a7880u; return 0; }
r[3]=read(ram,0x0c0a795cu,4);
goto P_0c0a7882;
P_0c0a7882: /* original 9463, guest PC 0x0c0a7882 */
if(!s->budget--) { s->failed_pc=0x0c0a7882u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a794cu,2);
goto P_0c0a7884;
P_0c0a7884: /* original 430b, guest PC 0x0c0a7884 */
if(!s->budget--) { s->failed_pc=0x0c0a7884u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7888u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7888u) { target=s->pc; goto dispatch; }
goto P_0c0a7888;
P_0c0a7886: /* original 34ec, guest PC 0x0c0a7886 */
if(!s->budget--) { s->failed_pc=0x0c0a7886u; return 0; }
r[4]+=r[14];
goto P_0c0a7888;
P_0c0a7888: /* original d235, guest PC 0x0c0a7888 */
if(!s->budget--) { s->failed_pc=0x0c0a7888u; return 0; }
r[2]=read(ram,0x0c0a7960u,4);
goto P_0c0a788a;
P_0c0a788a: /* original 420b, guest PC 0x0c0a788a */
if(!s->budget--) { s->failed_pc=0x0c0a788au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a788eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a788eu) { target=s->pc; goto dispatch; }
goto P_0c0a788e;
P_0c0a788c: /* original 0009, guest PC 0x0c0a788c */
if(!s->budget--) { s->failed_pc=0x0c0a788cu; return 0; }
goto P_0c0a788e;
P_0c0a788e: /* original d335, guest PC 0x0c0a788e */
if(!s->budget--) { s->failed_pc=0x0c0a788eu; return 0; }
r[3]=read(ram,0x0c0a7964u,4);
goto P_0c0a7890;
P_0c0a7890: /* original 64e3, guest PC 0x0c0a7890 */
if(!s->budget--) { s->failed_pc=0x0c0a7890u; return 0; }
r[4]=r[14];
goto P_0c0a7892;
P_0c0a7892: /* original 65f3, guest PC 0x0c0a7892 */
if(!s->budget--) { s->failed_pc=0x0c0a7892u; return 0; }
r[5]=r[15];
goto P_0c0a7894;
P_0c0a7894: /* original 430b, guest PC 0x0c0a7894 */
if(!s->budget--) { s->failed_pc=0x0c0a7894u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7898u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7898u) { target=s->pc; goto dispatch; }
goto P_0c0a7898;
P_0c0a7896: /* original 7440, guest PC 0x0c0a7896 */
if(!s->budget--) { s->failed_pc=0x0c0a7896u; return 0; }
r[4]+=0x00000040u;
goto P_0c0a7898;
P_0c0a7898: /* original d233, guest PC 0x0c0a7898 */
if(!s->budget--) { s->failed_pc=0x0c0a7898u; return 0; }
r[2]=read(ram,0x0c0a7968u,4);
goto P_0c0a789a;
P_0c0a789a: /* original 420b, guest PC 0x0c0a789a */
if(!s->budget--) { s->failed_pc=0x0c0a789au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a789eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a789eu) { target=s->pc; goto dispatch; }
goto P_0c0a789e;
P_0c0a789c: /* original 64f3, guest PC 0x0c0a789c */
if(!s->budget--) { s->failed_pc=0x0c0a789cu; return 0; }
r[4]=r[15];
goto P_0c0a789e;
P_0c0a789e: /* original d333, guest PC 0x0c0a789e */
if(!s->budget--) { s->failed_pc=0x0c0a789eu; return 0; }
r[3]=read(ram,0x0c0a796cu,4);
goto P_0c0a78a0;
P_0c0a78a0: /* original 430b, guest PC 0x0c0a78a0 */
if(!s->budget--) { s->failed_pc=0x0c0a78a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a78a4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a78a4u) { target=s->pc; goto dispatch; }
goto P_0c0a78a4;
P_0c0a78a2: /* original e401, guest PC 0x0c0a78a2 */
if(!s->budget--) { s->failed_pc=0x0c0a78a2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a78a4;
P_0c0a78a4: /* original 7f0c, guest PC 0x0c0a78a4 */
if(!s->budget--) { s->failed_pc=0x0c0a78a4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a78a6;
P_0c0a78a6: /* original 4f26, guest PC 0x0c0a78a6 */
if(!s->budget--) { s->failed_pc=0x0c0a78a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a78a8;
P_0c0a78a8: /* original 000b, guest PC 0x0c0a78a8 */
if(!s->budget--) { s->failed_pc=0x0c0a78a8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a78aa: /* original 6ef6, guest PC 0x0c0a78aa */
if(!s->budget--) { s->failed_pc=0x0c0a78aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a78acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a78acu; return 0; } return 1;
P_0c0a7908: /* original 2fe6, guest PC 0x0c0a7908 */
if(!s->budget--) { s->failed_pc=0x0c0a7908u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a790a;
P_0c0a790a: /* original c71a, guest PC 0x0c0a790a */
if(!s->budget--) { s->failed_pc=0x0c0a790au; return 0; }
r[0]=code_base|0x000a7974u;
goto P_0c0a790c;
P_0c0a790c: /* original 2fd6, guest PC 0x0c0a790c */
if(!s->budget--) { s->failed_pc=0x0c0a790cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a790e;
P_0c0a790e: /* original 2fc6, guest PC 0x0c0a790e */
if(!s->budget--) { s->failed_pc=0x0c0a790eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7910;
P_0c0a7910: /* original 2fb6, guest PC 0x0c0a7910 */
if(!s->budget--) { s->failed_pc=0x0c0a7910u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7912;
P_0c0a7912: /* original fffb, guest PC 0x0c0a7912 */
if(!s->budget--) { s->failed_pc=0x0c0a7912u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a7914;
P_0c0a7914: /* original ffeb, guest PC 0x0c0a7914 */
if(!s->budget--) { s->failed_pc=0x0c0a7914u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a7916;
P_0c0a7916: /* original ffdb, guest PC 0x0c0a7916 */
if(!s->budget--) { s->failed_pc=0x0c0a7916u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0a7918;
P_0c0a7918: /* original ffcb, guest PC 0x0c0a7918 */
if(!s->budget--) { s->failed_pc=0x0c0a7918u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0a791a;
P_0c0a791a: /* original 4f22, guest PC 0x0c0a791a */
if(!s->budget--) { s->failed_pc=0x0c0a791au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a791c;
P_0c0a791c: /* original ff5c, guest PC 0x0c0a791c */
if(!s->budget--) { s->failed_pc=0x0c0a791cu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a791e;
P_0c0a791e: /* original f508, guest PC 0x0c0a791e */
if(!s->budget--) { s->failed_pc=0x0c0a791eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a7920;
P_0c0a7920: /* original e004, guest PC 0x0c0a7920 */
if(!s->budget--) { s->failed_pc=0x0c0a7920u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7922;
P_0c0a7922: /* original 7fd8, guest PC 0x0c0a7922 */
if(!s->budget--) { s->failed_pc=0x0c0a7922u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0a7924;
P_0c0a7924: /* original fd5c, guest PC 0x0c0a7924 */
if(!s->budget--) { s->failed_pc=0x0c0a7924u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0a7926;
P_0c0a7926: /* original 65f3, guest PC 0x0c0a7926 */
if(!s->budget--) { s->failed_pc=0x0c0a7926u; return 0; }
r[5]=r[15];
goto P_0c0a7928;
P_0c0a7928: /* original ff57, guest PC 0x0c0a7928 */
if(!s->budget--) { s->failed_pc=0x0c0a7928u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a792a;
P_0c0a792a: /* original 7508, guest PC 0x0c0a792a */
if(!s->budget--) { s->failed_pc=0x0c0a792au; return 0; }
r[5]+=0x00000008u;
goto P_0c0a792c;
P_0c0a792c: /* original f59d, guest PC 0x0c0a792c */
if(!s->budget--) { s->failed_pc=0x0c0a792cu; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a792e;
P_0c0a792e: /* original f455, guest PC 0x0c0a792e */
if(!s->budget--) { s->failed_pc=0x0c0a792eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7930;
P_0c0a7930: /* original 6b53, guest PC 0x0c0a7930 */
if(!s->budget--) { s->failed_pc=0x0c0a7930u; return 0; }
r[11]=r[5];
goto P_0c0a7932;
P_0c0a7932: /* original 8f01, guest PC 0x0c0a7932 */
if(!s->budget--) { s->failed_pc=0x0c0a7932u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,12,13);
if(!cond) { goto P_0c0a7938; }
goto P_0c0a7936;
P_0c0a7934: /* original fcdc, guest PC 0x0c0a7934 */
if(!s->budget--) { s->failed_pc=0x0c0a7934u; return 0; }
vf3_matrix_move(s,12,13);
goto P_0c0a7936;
P_0c0a7936: /* original f45c, guest PC 0x0c0a7936 */
if(!s->budget--) { s->failed_pc=0x0c0a7936u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7938;
P_0c0a7938: /* original ff55, guest PC 0x0c0a7938 */
if(!s->budget--) { s->failed_pc=0x0c0a7938u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[5]))!=0);
goto P_0c0a793a;
P_0c0a793a: /* original 8b00, guest PC 0x0c0a793a */
if(!s->budget--) { s->failed_pc=0x0c0a793au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a793e; }
goto P_0c0a793c;
P_0c0a793c: /* original ff5c, guest PC 0x0c0a793c */
if(!s->budget--) { s->failed_pc=0x0c0a793cu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a793e;
P_0c0a793e: /* original 2448, guest PC 0x0c0a793e */
if(!s->budget--) { s->failed_pc=0x0c0a793eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a7940;
P_0c0a7940: /* original 8b1a, guest PC 0x0c0a7940 */
if(!s->budget--) { s->failed_pc=0x0c0a7940u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7978; }
goto P_0c0a7942;
P_0c0a7942: /* original e004, guest PC 0x0c0a7942 */
if(!s->budget--) { s->failed_pc=0x0c0a7942u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7944;
P_0c0a7944: /* original fc5c, guest PC 0x0c0a7944 */
if(!s->budget--) { s->failed_pc=0x0c0a7944u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a7946;
P_0c0a7946: /* original ff57, guest PC 0x0c0a7946 */
if(!s->budget--) { s->failed_pc=0x0c0a7946u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a7948;
P_0c0a7948: /* original a023, guest PC 0x0c0a7948 */
if(!s->budget--) { s->failed_pc=0x0c0a7948u; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c0a7992;
P_0c0a794a: /* original fdcc, guest PC 0x0c0a794a */
if(!s->budget--) { s->failed_pc=0x0c0a794au; return 0; }
vf3_matrix_move(s,13,12);
if(!vf3_matrix_family(0x0c0a794cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a794cu; return 0; } return 1;
P_0c0a7978: /* original e201, guest PC 0x0c0a7978 */
if(!s->budget--) { s->failed_pc=0x0c0a7978u; return 0; }
r[2]=0x00000001u;
goto P_0c0a797a;
P_0c0a797a: /* original 2248, guest PC 0x0c0a797a */
if(!s->budget--) { s->failed_pc=0x0c0a797au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a797c;
P_0c0a797c: /* original 8d01, guest PC 0x0c0a797c */
if(!s->budget--) { s->failed_pc=0x0c0a797cu; return 0; }
cond=r[17]&1u;
r[2]=0x00000002u;
if(cond) { goto P_0c0a7982; }
goto P_0c0a7980;
P_0c0a797e: /* original e202, guest PC 0x0c0a797e */
if(!s->budget--) { s->failed_pc=0x0c0a797eu; return 0; }
r[2]=0x00000002u;
goto P_0c0a7980;
P_0c0a7980: /* original fc5c, guest PC 0x0c0a7980 */
if(!s->budget--) { s->failed_pc=0x0c0a7980u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a7982;
P_0c0a7982: /* original 2248, guest PC 0x0c0a7982 */
if(!s->budget--) { s->failed_pc=0x0c0a7982u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a7984;
P_0c0a7984: /* original 8901, guest PC 0x0c0a7984 */
if(!s->budget--) { s->failed_pc=0x0c0a7984u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a798a; }
goto P_0c0a7986;
P_0c0a7986: /* original e004, guest PC 0x0c0a7986 */
if(!s->budget--) { s->failed_pc=0x0c0a7986u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7988;
P_0c0a7988: /* original ff57, guest PC 0x0c0a7988 */
if(!s->budget--) { s->failed_pc=0x0c0a7988u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a798a;
P_0c0a798a: /* original e304, guest PC 0x0c0a798a */
if(!s->budget--) { s->failed_pc=0x0c0a798au; return 0; }
r[3]=0x00000004u;
goto P_0c0a798c;
P_0c0a798c: /* original 2438, guest PC 0x0c0a798c */
if(!s->budget--) { s->failed_pc=0x0c0a798cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a798e;
P_0c0a798e: /* original 8900, guest PC 0x0c0a798e */
if(!s->budget--) { s->failed_pc=0x0c0a798eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7992; }
goto P_0c0a7990;
P_0c0a7990: /* original fd5c, guest PC 0x0c0a7990 */
if(!s->budget--) { s->failed_pc=0x0c0a7990u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0a7992;
P_0c0a7992: /* original 6353, guest PC 0x0c0a7992 */
if(!s->budget--) { s->failed_pc=0x0c0a7992u; return 0; }
r[3]=r[5];
goto P_0c0a7994;
P_0c0a7994: /* original 6d33, guest PC 0x0c0a7994 */
if(!s->budget--) { s->failed_pc=0x0c0a7994u; return 0; }
r[13]=r[3];
goto P_0c0a7996;
P_0c0a7996: /* original 6e33, guest PC 0x0c0a7996 */
if(!s->budget--) { s->failed_pc=0x0c0a7996u; return 0; }
r[14]=r[3];
goto P_0c0a7998;
P_0c0a7998: /* original 6c33, guest PC 0x0c0a7998 */
if(!s->budget--) { s->failed_pc=0x0c0a7998u; return 0; }
r[12]=r[3];
goto P_0c0a799a;
P_0c0a799a: /* original 7c0c, guest PC 0x0c0a799a */
if(!s->budget--) { s->failed_pc=0x0c0a799au; return 0; }
r[12]+=0x0000000cu;
goto P_0c0a799c;
P_0c0a799c: /* original fe4c, guest PC 0x0c0a799c */
if(!s->budget--) { s->failed_pc=0x0c0a799cu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0a799e;
P_0c0a799e: /* original 2f32, guest PC 0x0c0a799e */
if(!s->budget--) { s->failed_pc=0x0c0a799eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a79a0;
P_0c0a79a0: /* original 7e08, guest PC 0x0c0a79a0 */
if(!s->budget--) { s->failed_pc=0x0c0a79a0u; return 0; }
r[14]+=0x00000008u;
goto P_0c0a79a2;
P_0c0a79a2: /* original f38d, guest PC 0x0c0a79a2 */
if(!s->budget--) { s->failed_pc=0x0c0a79a2u; return 0; }
fr[3]=0;
goto P_0c0a79a4;
P_0c0a79a4: /* original 7d04, guest PC 0x0c0a79a4 */
if(!s->budget--) { s->failed_pc=0x0c0a79a4u; return 0; }
r[13]+=0x00000004u;
goto P_0c0a79a6;
P_0c0a79a6: /* original f33a, guest PC 0x0c0a79a6 */
if(!s->budget--) { s->failed_pc=0x0c0a79a6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a79a8;
P_0c0a79a8: /* original fdea, guest PC 0x0c0a79a8 */
if(!s->budget--) { s->failed_pc=0x0c0a79a8u; return 0; }
vf3_matrix_store(s,ram,14,r[13]);
goto P_0c0a79aa;
P_0c0a79aa: /* original feea, guest PC 0x0c0a79aa */
if(!s->budget--) { s->failed_pc=0x0c0a79aau; return 0; }
vf3_matrix_store(s,ram,14,r[14]);
goto P_0c0a79ac;
P_0c0a79ac: /* original fcea, guest PC 0x0c0a79ac */
if(!s->budget--) { s->failed_pc=0x0c0a79acu; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c0a79ae;
P_0c0a79ae: /* original d33f, guest PC 0x0c0a79ae */
if(!s->budget--) { s->failed_pc=0x0c0a79aeu; return 0; }
r[3]=read(ram,0x0c0a7aacu,4);
goto P_0c0a79b0;
P_0c0a79b0: /* original 430b, guest PC 0x0c0a79b0 */
if(!s->budget--) { s->failed_pc=0x0c0a79b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79b4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79b4u) { target=s->pc; goto dispatch; }
goto P_0c0a79b4;
P_0c0a79b2: /* original 64b3, guest PC 0x0c0a79b2 */
if(!s->budget--) { s->failed_pc=0x0c0a79b2u; return 0; }
r[4]=r[11];
goto P_0c0a79b4;
P_0c0a79b4: /* original d23e, guest PC 0x0c0a79b4 */
if(!s->budget--) { s->failed_pc=0x0c0a79b4u; return 0; }
r[2]=read(ram,0x0c0a7ab0u,4);
goto P_0c0a79b6;
P_0c0a79b6: /* original 420b, guest PC 0x0c0a79b6 */
if(!s->budget--) { s->failed_pc=0x0c0a79b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79bau;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79bau) { target=s->pc; goto dispatch; }
goto P_0c0a79ba;
P_0c0a79b8: /* original f4ec, guest PC 0x0c0a79b8 */
if(!s->budget--) { s->failed_pc=0x0c0a79b8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a79ba;
P_0c0a79ba: /* original 63f2, guest PC 0x0c0a79ba */
if(!s->budget--) { s->failed_pc=0x0c0a79bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a79bc;
P_0c0a79bc: /* original e004, guest PC 0x0c0a79bc */
if(!s->budget--) { s->failed_pc=0x0c0a79bcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a79be;
P_0c0a79be: /* original f38d, guest PC 0x0c0a79be */
if(!s->budget--) { s->failed_pc=0x0c0a79beu; return 0; }
fr[3]=0;
goto P_0c0a79c0;
P_0c0a79c0: /* original 65b3, guest PC 0x0c0a79c0 */
if(!s->budget--) { s->failed_pc=0x0c0a79c0u; return 0; }
r[5]=r[11];
goto P_0c0a79c2;
P_0c0a79c2: /* original f33a, guest PC 0x0c0a79c2 */
if(!s->budget--) { s->failed_pc=0x0c0a79c2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a79c4;
P_0c0a79c4: /* original f2fc, guest PC 0x0c0a79c4 */
if(!s->budget--) { s->failed_pc=0x0c0a79c4u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0a79c6;
P_0c0a79c6: /* original f2d2, guest PC 0x0c0a79c6 */
if(!s->budget--) { s->failed_pc=0x0c0a79c6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c0a79c8;
P_0c0a79c8: /* original fd2a, guest PC 0x0c0a79c8 */
if(!s->budget--) { s->failed_pc=0x0c0a79c8u; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c0a79ca;
P_0c0a79ca: /* original f3f6, guest PC 0x0c0a79ca */
if(!s->budget--) { s->failed_pc=0x0c0a79cau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a79cc;
P_0c0a79cc: /* original f2fc, guest PC 0x0c0a79cc */
if(!s->budget--) { s->failed_pc=0x0c0a79ccu; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0a79ce;
P_0c0a79ce: /* original ffc2, guest PC 0x0c0a79ce */
if(!s->budget--) { s->failed_pc=0x0c0a79ceu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0a79d0;
P_0c0a79d0: /* original f232, guest PC 0x0c0a79d0 */
if(!s->budget--) { s->failed_pc=0x0c0a79d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a79d2;
P_0c0a79d2: /* original fe2a, guest PC 0x0c0a79d2 */
if(!s->budget--) { s->failed_pc=0x0c0a79d2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c0a79d4;
P_0c0a79d4: /* original fcfa, guest PC 0x0c0a79d4 */
if(!s->budget--) { s->failed_pc=0x0c0a79d4u; return 0; }
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c0a79d6;
P_0c0a79d6: /* original d337, guest PC 0x0c0a79d6 */
if(!s->budget--) { s->failed_pc=0x0c0a79d6u; return 0; }
r[3]=read(ram,0x0c0a7ab4u,4);
goto P_0c0a79d8;
P_0c0a79d8: /* original 430b, guest PC 0x0c0a79d8 */
if(!s->budget--) { s->failed_pc=0x0c0a79d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79dcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79dcu) { target=s->pc; goto dispatch; }
goto P_0c0a79dc;
P_0c0a79da: /* original e400, guest PC 0x0c0a79da */
if(!s->budget--) { s->failed_pc=0x0c0a79dau; return 0; }
r[4]=0x00000000u;
goto P_0c0a79dc;
P_0c0a79dc: /* original d236, guest PC 0x0c0a79dc */
if(!s->budget--) { s->failed_pc=0x0c0a79dcu; return 0; }
r[2]=read(ram,0x0c0a7ab8u,4);
goto P_0c0a79de;
P_0c0a79de: /* original f5e8, guest PC 0x0c0a79de */
if(!s->budget--) { s->failed_pc=0x0c0a79deu; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c0a79e0;
P_0c0a79e0: /* original f6c8, guest PC 0x0c0a79e0 */
if(!s->budget--) { s->failed_pc=0x0c0a79e0u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c0a79e2;
P_0c0a79e2: /* original 420b, guest PC 0x0c0a79e2 */
if(!s->budget--) { s->failed_pc=0x0c0a79e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79e6u;
vf3_matrix_load(s,ram,4,r[13]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79e6u) { target=s->pc; goto dispatch; }
goto P_0c0a79e6;
P_0c0a79e4: /* original f4d8, guest PC 0x0c0a79e4 */
if(!s->budget--) { s->failed_pc=0x0c0a79e4u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c0a79e6;
P_0c0a79e6: /* original d335, guest PC 0x0c0a79e6 */
if(!s->budget--) { s->failed_pc=0x0c0a79e6u; return 0; }
r[3]=read(ram,0x0c0a7abcu,4);
goto P_0c0a79e8;
P_0c0a79e8: /* original e502, guest PC 0x0c0a79e8 */
if(!s->budget--) { s->failed_pc=0x0c0a79e8u; return 0; }
r[5]=0x00000002u;
goto P_0c0a79ea;
P_0c0a79ea: /* original 430b, guest PC 0x0c0a79ea */
if(!s->budget--) { s->failed_pc=0x0c0a79eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79eeu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79eeu) { target=s->pc; goto dispatch; }
goto P_0c0a79ee;
P_0c0a79ec: /* original e400, guest PC 0x0c0a79ec */
if(!s->budget--) { s->failed_pc=0x0c0a79ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0a79ee;
P_0c0a79ee: /* original d234, guest PC 0x0c0a79ee */
if(!s->budget--) { s->failed_pc=0x0c0a79eeu; return 0; }
r[2]=read(ram,0x0c0a7ac0u,4);
goto P_0c0a79f0;
P_0c0a79f0: /* original e501, guest PC 0x0c0a79f0 */
if(!s->budget--) { s->failed_pc=0x0c0a79f0u; return 0; }
r[5]=0x00000001u;
goto P_0c0a79f2;
P_0c0a79f2: /* original 420b, guest PC 0x0c0a79f2 */
if(!s->budget--) { s->failed_pc=0x0c0a79f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79f6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79f6u) { target=s->pc; goto dispatch; }
goto P_0c0a79f6;
P_0c0a79f4: /* original e400, guest PC 0x0c0a79f4 */
if(!s->budget--) { s->failed_pc=0x0c0a79f4u; return 0; }
r[4]=0x00000000u;
goto P_0c0a79f6;
P_0c0a79f6: /* original 7f28, guest PC 0x0c0a79f6 */
if(!s->budget--) { s->failed_pc=0x0c0a79f6u; return 0; }
r[15]+=0x00000028u;
goto P_0c0a79f8;
P_0c0a79f8: /* original 4f26, guest PC 0x0c0a79f8 */
if(!s->budget--) { s->failed_pc=0x0c0a79f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a79fa;
P_0c0a79fa: /* original fcf9, guest PC 0x0c0a79fa */
if(!s->budget--) { s->failed_pc=0x0c0a79fau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a79fc;
P_0c0a79fc: /* original fdf9, guest PC 0x0c0a79fc */
if(!s->budget--) { s->failed_pc=0x0c0a79fcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a79fe;
P_0c0a79fe: /* original fef9, guest PC 0x0c0a79fe */
if(!s->budget--) { s->failed_pc=0x0c0a79feu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7a00;
P_0c0a7a00: /* original fff9, guest PC 0x0c0a7a00 */
if(!s->budget--) { s->failed_pc=0x0c0a7a00u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7a02;
P_0c0a7a02: /* original 6bf6, guest PC 0x0c0a7a02 */
if(!s->budget--) { s->failed_pc=0x0c0a7a02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a7a04;
P_0c0a7a04: /* original 6cf6, guest PC 0x0c0a7a04 */
if(!s->budget--) { s->failed_pc=0x0c0a7a04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a7a06;
P_0c0a7a06: /* original 6df6, guest PC 0x0c0a7a06 */
if(!s->budget--) { s->failed_pc=0x0c0a7a06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7a08;
P_0c0a7a08: /* original 000b, guest PC 0x0c0a7a08 */
if(!s->budget--) { s->failed_pc=0x0c0a7a08u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7a0a: /* original 6ef6, guest PC 0x0c0a7a0a */
if(!s->budget--) { s->failed_pc=0x0c0a7a0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7a0c;
P_0c0a7a0c: /* original 2fe6, guest PC 0x0c0a7a0c */
if(!s->budget--) { s->failed_pc=0x0c0a7a0cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7a0e;
P_0c0a7a0e: /* original 6743, guest PC 0x0c0a7a0e */
if(!s->budget--) { s->failed_pc=0x0c0a7a0eu; return 0; }
r[7]=r[4];
goto P_0c0a7a10;
P_0c0a7a10: /* original 2fd6, guest PC 0x0c0a7a10 */
if(!s->budget--) { s->failed_pc=0x0c0a7a10u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7a12;
P_0c0a7a12: /* original 4728, guest PC 0x0c0a7a12 */
if(!s->budget--) { s->failed_pc=0x0c0a7a12u; return 0; }
r[7]<<=16;
goto P_0c0a7a14;
P_0c0a7a14: /* original fffb, guest PC 0x0c0a7a14 */
if(!s->budget--) { s->failed_pc=0x0c0a7a14u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a7a16;
P_0c0a7a16: /* original 6e73, guest PC 0x0c0a7a16 */
if(!s->budget--) { s->failed_pc=0x0c0a7a16u; return 0; }
r[14]=r[7];
goto P_0c0a7a18;
P_0c0a7a18: /* original 4518, guest PC 0x0c0a7a18 */
if(!s->budget--) { s->failed_pc=0x0c0a7a18u; return 0; }
r[5]<<=8;
goto P_0c0a7a1a;
P_0c0a7a1a: /* original 6463, guest PC 0x0c0a7a1a */
if(!s->budget--) { s->failed_pc=0x0c0a7a1au; return 0; }
r[4]=r[6];
goto P_0c0a7a1c;
P_0c0a7a1c: /* original 4f22, guest PC 0x0c0a7a1c */
if(!s->budget--) { s->failed_pc=0x0c0a7a1cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7a1e;
P_0c0a7a1e: /* original 2e5b, guest PC 0x0c0a7a1e */
if(!s->budget--) { s->failed_pc=0x0c0a7a1eu; return 0; }
r[14]|=r[5];
goto P_0c0a7a20;
P_0c0a7a20: /* original 2e4b, guest PC 0x0c0a7a20 */
if(!s->budget--) { s->failed_pc=0x0c0a7a20u; return 0; }
r[14]|=r[4];
goto P_0c0a7a22;
P_0c0a7a22: /* original 7ffc, guest PC 0x0c0a7a22 */
if(!s->budget--) { s->failed_pc=0x0c0a7a22u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7a24;
P_0c0a7a24: /* original ff4a, guest PC 0x0c0a7a24 */
if(!s->budget--) { s->failed_pc=0x0c0a7a24u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a7a26;
P_0c0a7a26: /* original d327, guest PC 0x0c0a7a26 */
if(!s->budget--) { s->failed_pc=0x0c0a7a26u; return 0; }
r[3]=read(ram,0x0c0a7ac4u,4);
goto P_0c0a7a28;
P_0c0a7a28: /* original 903c, guest PC 0x0c0a7a28 */
if(!s->budget--) { s->failed_pc=0x0c0a7a28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa4u,2);
goto P_0c0a7a2a;
P_0c0a7a2a: /* original dd27, guest PC 0x0c0a7a2a */
if(!s->budget--) { s->failed_pc=0x0c0a7a2au; return 0; }
r[13]=read(ram,0x0c0a7ac8u,4);
goto P_0c0a7a2c;
P_0c0a7a2c: /* original 2e3b, guest PC 0x0c0a7a2c */
if(!s->budget--) { s->failed_pc=0x0c0a7a2cu; return 0; }
r[14]|=r[3];
goto P_0c0a7a2e;
P_0c0a7a2e: /* original ff5c, guest PC 0x0c0a7a2e */
if(!s->budget--) { s->failed_pc=0x0c0a7a2eu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a7a30;
P_0c0a7a30: /* original 0de6, guest PC 0x0c0a7a30 */
if(!s->budget--) { s->failed_pc=0x0c0a7a30u; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c0a7a32;
P_0c0a7a32: /* original d226, guest PC 0x0c0a7a32 */
if(!s->budget--) { s->failed_pc=0x0c0a7a32u; return 0; }
r[2]=read(ram,0x0c0a7accu,4);
goto P_0c0a7a34;
P_0c0a7a34: /* original 420b, guest PC 0x0c0a7a34 */
if(!s->budget--) { s->failed_pc=0x0c0a7a34u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7a38u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7a38u) { target=s->pc; goto dispatch; }
goto P_0c0a7a38;
P_0c0a7a36: /* original 64e3, guest PC 0x0c0a7a36 */
if(!s->budget--) { s->failed_pc=0x0c0a7a36u; return 0; }
r[4]=r[14];
goto P_0c0a7a38;
P_0c0a7a38: /* original d325, guest PC 0x0c0a7a38 */
if(!s->budget--) { s->failed_pc=0x0c0a7a38u; return 0; }
r[3]=read(ram,0x0c0a7ad0u,4);
goto P_0c0a7a3a;
P_0c0a7a3a: /* original 65e3, guest PC 0x0c0a7a3a */
if(!s->budget--) { s->failed_pc=0x0c0a7a3au; return 0; }
r[5]=r[14];
goto P_0c0a7a3c;
P_0c0a7a3c: /* original 66e3, guest PC 0x0c0a7a3c */
if(!s->budget--) { s->failed_pc=0x0c0a7a3cu; return 0; }
r[6]=r[14];
goto P_0c0a7a3e;
P_0c0a7a3e: /* original 430b, guest PC 0x0c0a7a3e */
if(!s->budget--) { s->failed_pc=0x0c0a7a3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7a42u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7a42u) { target=s->pc; goto dispatch; }
goto P_0c0a7a42;
P_0c0a7a40: /* original 64e3, guest PC 0x0c0a7a40 */
if(!s->budget--) { s->failed_pc=0x0c0a7a40u; return 0; }
r[4]=r[14];
goto P_0c0a7a42;
P_0c0a7a42: /* original f2f8, guest PC 0x0c0a7a42 */
if(!s->budget--) { s->failed_pc=0x0c0a7a42u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a7a44;
P_0c0a7a44: /* original e500, guest PC 0x0c0a7a44 */
if(!s->budget--) { s->failed_pc=0x0c0a7a44u; return 0; }
r[5]=0x00000000u;
goto P_0c0a7a46;
P_0c0a7a46: /* original f38d, guest PC 0x0c0a7a46 */
if(!s->budget--) { s->failed_pc=0x0c0a7a46u; return 0; }
fr[3]=0;
goto P_0c0a7a48;
P_0c0a7a48: /* original e100, guest PC 0x0c0a7a48 */
if(!s->budget--) { s->failed_pc=0x0c0a7a48u; return 0; }
r[1]=0x00000000u;
goto P_0c0a7a4a;
P_0c0a7a4a: /* original f235, guest PC 0x0c0a7a4a */
if(!s->budget--) { s->failed_pc=0x0c0a7a4au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0a7a4c;
P_0c0a7a4c: /* original 9e2b, guest PC 0x0c0a7a4c */
if(!s->budget--) { s->failed_pc=0x0c0a7a4cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa6u,2);
goto P_0c0a7a4e;
P_0c0a7a4e: /* original 942b, guest PC 0x0c0a7a4e */
if(!s->budget--) { s->failed_pc=0x0c0a7a4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa8u,2);
goto P_0c0a7a50;
P_0c0a7a50: /* original 3edc, guest PC 0x0c0a7a50 */
if(!s->budget--) { s->failed_pc=0x0c0a7a50u; return 0; }
r[14]+=r[13];
goto P_0c0a7a52;
P_0c0a7a52: /* original f68d, guest PC 0x0c0a7a52 */
if(!s->budget--) { s->failed_pc=0x0c0a7a52u; return 0; }
fr[6]=0;
goto P_0c0a7a54;
P_0c0a7a54: /* original 8d0c, guest PC 0x0c0a7a54 */
if(!s->budget--) { s->failed_pc=0x0c0a7a54u; return 0; }
cond=r[17]&1u;
r[1]+=r[14];
if(cond) { goto P_0c0a7a70; }
goto P_0c0a7a58;
P_0c0a7a56: /* original 31ec, guest PC 0x0c0a7a56 */
if(!s->budget--) { s->failed_pc=0x0c0a7a56u; return 0; }
r[1]+=r[14];
goto P_0c0a7a58;
P_0c0a7a58: /* original 6653, guest PC 0x0c0a7a58 */
if(!s->budget--) { s->failed_pc=0x0c0a7a58u; return 0; }
r[6]=r[5];
goto P_0c0a7a5a;
P_0c0a7a5a: /* original 6513, guest PC 0x0c0a7a5a */
if(!s->budget--) { s->failed_pc=0x0c0a7a5au; return 0; }
r[5]=r[1];
goto P_0c0a7a5c;
P_0c0a7a5c: /* original 7601, guest PC 0x0c0a7a5c */
if(!s->budget--) { s->failed_pc=0x0c0a7a5cu; return 0; }
r[6]+=0x00000001u;
goto P_0c0a7a5e;
P_0c0a7a5e: /* original f56a, guest PC 0x0c0a7a5e */
if(!s->budget--) { s->failed_pc=0x0c0a7a5eu; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0a7a60;
P_0c0a7a60: /* original 3647, guest PC 0x0c0a7a60 */
if(!s->budget--) { s->failed_pc=0x0c0a7a60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[4])!=0);
goto P_0c0a7a62;
P_0c0a7a62: /* original 8ffb, guest PC 0x0c0a7a62 */
if(!s->budget--) { s->failed_pc=0x0c0a7a62u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c0a7a5c; }
goto P_0c0a7a66;
P_0c0a7a64: /* original 7504, guest PC 0x0c0a7a64 */
if(!s->budget--) { s->failed_pc=0x0c0a7a64u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a7a66;
P_0c0a7a66: /* original c71b, guest PC 0x0c0a7a66 */
if(!s->budget--) { s->failed_pc=0x0c0a7a66u; return 0; }
r[0]=code_base|0x000a7ad4u;
goto P_0c0a7a68;
P_0c0a7a68: /* original f308, guest PC 0x0c0a7a68 */
if(!s->budget--) { s->failed_pc=0x0c0a7a68u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a6a;
P_0c0a7a6a: /* original 901e, guest PC 0x0c0a7a6a */
if(!s->budget--) { s->failed_pc=0x0c0a7a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a6c;
P_0c0a7a6c: /* original a049, guest PC 0x0c0a7a6c */
if(!s->budget--) { s->failed_pc=0x0c0a7a6cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7b02;
P_0c0a7a6e: /* original fd37, guest PC 0x0c0a7a6e */
if(!s->budget--) { s->failed_pc=0x0c0a7a6eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7a70;
P_0c0a7a70: /* original c719, guest PC 0x0c0a7a70 */
if(!s->budget--) { s->failed_pc=0x0c0a7a70u; return 0; }
r[0]=code_base|0x000a7ad8u;
goto P_0c0a7a72;
P_0c0a7a72: /* original f59d, guest PC 0x0c0a7a72 */
if(!s->budget--) { s->failed_pc=0x0c0a7a72u; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a7a74;
P_0c0a7a74: /* original f308, guest PC 0x0c0a7a74 */
if(!s->budget--) { s->failed_pc=0x0c0a7a74u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a76;
P_0c0a7a76: /* original 6753, guest PC 0x0c0a7a76 */
if(!s->budget--) { s->failed_pc=0x0c0a7a76u; return 0; }
r[7]=r[5];
goto P_0c0a7a78;
P_0c0a7a78: /* original f75c, guest PC 0x0c0a7a78 */
if(!s->budget--) { s->failed_pc=0x0c0a7a78u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c0a7a7a;
P_0c0a7a7a: /* original f7f1, guest PC 0x0c0a7a7a */
if(!s->budget--) { s->failed_pc=0x0c0a7a7au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'-');
goto P_0c0a7a7c;
P_0c0a7a7c: /* original f232, guest PC 0x0c0a7a7c */
if(!s->budget--) { s->failed_pc=0x0c0a7a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a7a7e;
P_0c0a7a7e: /* original 9014, guest PC 0x0c0a7a7e */
if(!s->budget--) { s->failed_pc=0x0c0a7a7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a80;
P_0c0a7a80: /* original 6543, guest PC 0x0c0a7a80 */
if(!s->budget--) { s->failed_pc=0x0c0a7a80u; return 0; }
r[5]=r[4];
goto P_0c0a7a82;
P_0c0a7a82: /* original 6613, guest PC 0x0c0a7a82 */
if(!s->budget--) { s->failed_pc=0x0c0a7a82u; return 0; }
r[6]=r[1];
goto P_0c0a7a84;
P_0c0a7a84: /* original f47c, guest PC 0x0c0a7a84 */
if(!s->budget--) { s->failed_pc=0x0c0a7a84u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0a7a86;
P_0c0a7a86: /* original f423, guest PC 0x0c0a7a86 */
if(!s->budget--) { s->failed_pc=0x0c0a7a86u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0a7a88;
P_0c0a7a88: /* original fd47, guest PC 0x0c0a7a88 */
if(!s->budget--) { s->failed_pc=0x0c0a7a88u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a7a8a;
P_0c0a7a8a: /* original c714, guest PC 0x0c0a7a8a */
if(!s->budget--) { s->failed_pc=0x0c0a7a8au; return 0; }
r[0]=code_base|0x000a7adcu;
goto P_0c0a7a8c;
P_0c0a7a8c: /* original f808, guest PC 0x0c0a7a8c */
if(!s->budget--) { s->failed_pc=0x0c0a7a8cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0a7a8e;
P_0c0a7a8e: /* original 455a, guest PC 0x0c0a7a8e */
if(!s->budget--) { s->failed_pc=0x0c0a7a8eu; return 0; }
r[53]=r[5];
goto P_0c0a7a90;
P_0c0a7a90: /* original f28d, guest PC 0x0c0a7a90 */
if(!s->budget--) { s->failed_pc=0x0c0a7a90u; return 0; }
fr[2]=0;
goto P_0c0a7a92;
P_0c0a7a92: /* original f32d, guest PC 0x0c0a7a92 */
if(!s->budget--) { s->failed_pc=0x0c0a7a92u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a7a94;
P_0c0a7a94: /* original f372, guest PC 0x0c0a7a94 */
if(!s->budget--) { s->failed_pc=0x0c0a7a94u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0a7a96;
P_0c0a7a96: /* original f383, guest PC 0x0c0a7a96 */
if(!s->budget--) { s->failed_pc=0x0c0a7a96u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'/');
goto P_0c0a7a98;
P_0c0a7a98: /* original f43c, guest PC 0x0c0a7a98 */
if(!s->budget--) { s->failed_pc=0x0c0a7a98u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a7a9a;
P_0c0a7a9a: /* original f4f0, guest PC 0x0c0a7a9a */
if(!s->budget--) { s->failed_pc=0x0c0a7a9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c0a7a9c;
P_0c0a7a9c: /* original f245, guest PC 0x0c0a7a9c */
if(!s->budget--) { s->failed_pc=0x0c0a7a9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0a7a9e;
P_0c0a7a9e: /* original 8b1f, guest PC 0x0c0a7a9e */
if(!s->budget--) { s->failed_pc=0x0c0a7a9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae0; }
goto P_0c0a7aa0;
P_0c0a7aa0: /* original a021, guest PC 0x0c0a7aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0a7ae6;
P_0c0a7aa2: /* original f46c, guest PC 0x0c0a7aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa2u; return 0; }
vf3_matrix_move(s,4,6);
if(!vf3_matrix_family(0x0c0a7aa4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7aa4u; return 0; } return 1;
P_0c0a7ae0: /* original f455, guest PC 0x0c0a7ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7ae2;
P_0c0a7ae2: /* original 8b00, guest PC 0x0c0a7ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae6; }
goto P_0c0a7ae4;
P_0c0a7ae4: /* original f45c, guest PC 0x0c0a7ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae4u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7ae6;
P_0c0a7ae6: /* original 7701, guest PC 0x0c0a7ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae6u; return 0; }
r[7]+=0x00000001u;
goto P_0c0a7ae8;
P_0c0a7ae8: /* original f64a, guest PC 0x0c0a7ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae8u; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0a7aea;
P_0c0a7aea: /* original 3743, guest PC 0x0c0a7aea */
if(!s->budget--) { s->failed_pc=0x0c0a7aeau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[4])!=0);
goto P_0c0a7aec;
P_0c0a7aec: /* original 7604, guest PC 0x0c0a7aec */
if(!s->budget--) { s->failed_pc=0x0c0a7aecu; return 0; }
r[6]+=0x00000004u;
goto P_0c0a7aee;
P_0c0a7aee: /* original 8fce, guest PC 0x0c0a7aee */
if(!s->budget--) { s->failed_pc=0x0c0a7aeeu; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(!cond) { goto P_0c0a7a8e; }
goto P_0c0a7af2;
P_0c0a7af0: /* original 75ff, guest PC 0x0c0a7af0 */
if(!s->budget--) { s->failed_pc=0x0c0a7af0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a7af2;
P_0c0a7af2: /* original f28d, guest PC 0x0c0a7af2 */
if(!s->budget--) { s->failed_pc=0x0c0a7af2u; return 0; }
fr[2]=0;
goto P_0c0a7af4;
P_0c0a7af4: /* original f2f5, guest PC 0x0c0a7af4 */
if(!s->budget--) { s->failed_pc=0x0c0a7af4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c0a7af6;
P_0c0a7af6: /* original 8b01, guest PC 0x0c0a7af6 */
if(!s->budget--) { s->failed_pc=0x0c0a7af6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7afc; }
goto P_0c0a7af8;
P_0c0a7af8: /* original a001, guest PC 0x0c0a7af8 */
if(!s->budget--) { s->failed_pc=0x0c0a7af8u; return 0; }
fr[3]=0;
goto P_0c0a7afe;
P_0c0a7afa: /* original f38d, guest PC 0x0c0a7afa */
if(!s->budget--) { s->failed_pc=0x0c0a7afau; return 0; }
fr[3]=0;
goto P_0c0a7afc;
P_0c0a7afc: /* original f3fc, guest PC 0x0c0a7afc */
if(!s->budget--) { s->failed_pc=0x0c0a7afcu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0a7afe;
P_0c0a7afe: /* original 9042, guest PC 0x0c0a7afe */
if(!s->budget--) { s->failed_pc=0x0c0a7afeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b86u,2);
goto P_0c0a7b00;
P_0c0a7b00: /* original fe37, guest PC 0x0c0a7b00 */
if(!s->budget--) { s->failed_pc=0x0c0a7b00u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7b02;
P_0c0a7b02: /* original 7f04, guest PC 0x0c0a7b02 */
if(!s->budget--) { s->failed_pc=0x0c0a7b02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7b04;
P_0c0a7b04: /* original 60d2, guest PC 0x0c0a7b04 */
if(!s->budget--) { s->failed_pc=0x0c0a7b04u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a7b06;
P_0c0a7b06: /* original 4f26, guest PC 0x0c0a7b06 */
if(!s->budget--) { s->failed_pc=0x0c0a7b06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7b08;
P_0c0a7b08: /* original cb01, guest PC 0x0c0a7b08 */
if(!s->budget--) { s->failed_pc=0x0c0a7b08u; return 0; }
r[0]|=1u;
goto P_0c0a7b0a;
P_0c0a7b0a: /* original 2d02, guest PC 0x0c0a7b0a */
if(!s->budget--) { s->failed_pc=0x0c0a7b0au; return 0; }
write(ram,r[13],r[0],4);
goto P_0c0a7b0c;
P_0c0a7b0c: /* original e500, guest PC 0x0c0a7b0c */
if(!s->budget--) { s->failed_pc=0x0c0a7b0cu; return 0; }
r[5]=0x00000000u;
goto P_0c0a7b0e;
P_0c0a7b0e: /* original fff9, guest PC 0x0c0a7b0e */
if(!s->budget--) { s->failed_pc=0x0c0a7b0eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7b10;
P_0c0a7b10: /* original d320, guest PC 0x0c0a7b10 */
if(!s->budget--) { s->failed_pc=0x0c0a7b10u; return 0; }
r[3]=read(ram,0x0c0a7b94u,4);
goto P_0c0a7b12;
P_0c0a7b12: /* original 6df6, guest PC 0x0c0a7b12 */
if(!s->budget--) { s->failed_pc=0x0c0a7b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7b14;
P_0c0a7b14: /* original d41e, guest PC 0x0c0a7b14 */
if(!s->budget--) { s->failed_pc=0x0c0a7b14u; return 0; }
r[4]=read(ram,0x0c0a7b90u,4);
goto P_0c0a7b16;
P_0c0a7b16: /* original 432b, guest PC 0x0c0a7b16 */
if(!s->budget--) { s->failed_pc=0x0c0a7b16u; return 0; }
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
P_0c0a7b18: /* original 6ef6, guest PC 0x0c0a7b18 */
if(!s->budget--) { s->failed_pc=0x0c0a7b18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7b1au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7b1au; return 0; } return 1;
P_0c0a7f14: /* original 2fe6, guest PC 0x0c0a7f14 */
if(!s->budget--) { s->failed_pc=0x0c0a7f14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f16;
P_0c0a7f16: /* original d324, guest PC 0x0c0a7f16 */
if(!s->budget--) { s->failed_pc=0x0c0a7f16u; return 0; }
r[3]=read(ram,0x0c0a7fa8u,4);
goto P_0c0a7f18;
P_0c0a7f18: /* original 4f12, guest PC 0x0c0a7f18 */
if(!s->budget--) { s->failed_pc=0x0c0a7f18u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a7f1a;
P_0c0a7f1a: /* original 6632, guest PC 0x0c0a7f1a */
if(!s->budget--) { s->failed_pc=0x0c0a7f1au; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0a7f1c;
P_0c0a7f1c: /* original 856d, guest PC 0x0c0a7f1c */
if(!s->budget--) { s->failed_pc=0x0c0a7f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+26,2);
goto P_0c0a7f1e;
P_0c0a7f1e: /* original 670d, guest PC 0x0c0a7f1e */
if(!s->budget--) { s->failed_pc=0x0c0a7f1eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0a7f20;
P_0c0a7f20: /* original a012, guest PC 0x0c0a7f20 */
if(!s->budget--) { s->failed_pc=0x0c0a7f20u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f48;
P_0c0a7f22: /* original ee1f, guest PC 0x0c0a7f22 */
if(!s->budget--) { s->failed_pc=0x0c0a7f22u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f24;
P_0c0a7f24: /* original 856b, guest PC 0x0c0a7f24 */
if(!s->budget--) { s->failed_pc=0x0c0a7f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a7f26;
P_0c0a7f26: /* original 600d, guest PC 0x0c0a7f26 */
if(!s->budget--) { s->failed_pc=0x0c0a7f26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a7f28;
P_0c0a7f28: /* original 3500, guest PC 0x0c0a7f28 */
if(!s->budget--) { s->failed_pc=0x0c0a7f28u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c0a7f2a;
P_0c0a7f2a: /* original 8910, guest PC 0x0c0a7f2a */
if(!s->budget--) { s->failed_pc=0x0c0a7f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7f4e; }
goto P_0c0a7f2c;
P_0c0a7f2c: /* original e334, guest PC 0x0c0a7f2c */
if(!s->budget--) { s->failed_pc=0x0c0a7f2cu; return 0; }
r[3]=0x00000034u;
goto P_0c0a7f2e;
P_0c0a7f2e: /* original 6263, guest PC 0x0c0a7f2e */
if(!s->budget--) { s->failed_pc=0x0c0a7f2eu; return 0; }
r[2]=r[6];
goto P_0c0a7f30;
P_0c0a7f30: /* original 253f, guest PC 0x0c0a7f30 */
if(!s->budget--) { s->failed_pc=0x0c0a7f30u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[3]);
goto P_0c0a7f32;
P_0c0a7f32: /* original 721c, guest PC 0x0c0a7f32 */
if(!s->budget--) { s->failed_pc=0x0c0a7f32u; return 0; }
r[2]+=0x0000001cu;
goto P_0c0a7f34;
P_0c0a7f34: /* original e030, guest PC 0x0c0a7f34 */
if(!s->budget--) { s->failed_pc=0x0c0a7f34u; return 0; }
r[0]=0x00000030u;
goto P_0c0a7f36;
P_0c0a7f36: /* original 051a, guest PC 0x0c0a7f36 */
if(!s->budget--) { s->failed_pc=0x0c0a7f36u; return 0; }
r[5]=r[19];
goto P_0c0a7f38;
P_0c0a7f38: /* original 655f, guest PC 0x0c0a7f38 */
if(!s->budget--) { s->failed_pc=0x0c0a7f38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a7f3a;
P_0c0a7f3a: /* original 352c, guest PC 0x0c0a7f3a */
if(!s->budget--) { s->failed_pc=0x0c0a7f3au; return 0; }
r[5]+=r[2];
goto P_0c0a7f3c;
P_0c0a7f3c: /* original 015d, guest PC 0x0c0a7f3c */
if(!s->budget--) { s->failed_pc=0x0c0a7f3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7f3e;
P_0c0a7f3e: /* original 3140, guest PC 0x0c0a7f3e */
if(!s->budget--) { s->failed_pc=0x0c0a7f3eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c0a7f40;
P_0c0a7f40: /* original 8b01, guest PC 0x0c0a7f40 */
if(!s->budget--) { s->failed_pc=0x0c0a7f40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7f46; }
goto P_0c0a7f42;
P_0c0a7f42: /* original a005, guest PC 0x0c0a7f42 */
if(!s->budget--) { s->failed_pc=0x0c0a7f42u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f50;
P_0c0a7f44: /* original e001, guest PC 0x0c0a7f44 */
if(!s->budget--) { s->failed_pc=0x0c0a7f44u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f46;
P_0c0a7f46: /* original 77ff, guest PC 0x0c0a7f46 */
if(!s->budget--) { s->failed_pc=0x0c0a7f46u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0a7f48;
P_0c0a7f48: /* original 6573, guest PC 0x0c0a7f48 */
if(!s->budget--) { s->failed_pc=0x0c0a7f48u; return 0; }
r[5]=r[7];
goto P_0c0a7f4a;
P_0c0a7f4a: /* original afeb, guest PC 0x0c0a7f4a */
if(!s->budget--) { s->failed_pc=0x0c0a7f4au; return 0; }
r[5]&=r[14];
goto P_0c0a7f24;
P_0c0a7f4c: /* original 25e9, guest PC 0x0c0a7f4c */
if(!s->budget--) { s->failed_pc=0x0c0a7f4cu; return 0; }
r[5]&=r[14];
goto P_0c0a7f4e;
P_0c0a7f4e: /* original e000, guest PC 0x0c0a7f4e */
if(!s->budget--) { s->failed_pc=0x0c0a7f4eu; return 0; }
r[0]=0x00000000u;
goto P_0c0a7f50;
P_0c0a7f50: /* original 4f16, guest PC 0x0c0a7f50 */
if(!s->budget--) { s->failed_pc=0x0c0a7f50u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7f52;
P_0c0a7f52: /* original 000b, guest PC 0x0c0a7f52 */
if(!s->budget--) { s->failed_pc=0x0c0a7f52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7f54: /* original 6ef6, guest PC 0x0c0a7f54 */
if(!s->budget--) { s->failed_pc=0x0c0a7f54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7f56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7f56u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
