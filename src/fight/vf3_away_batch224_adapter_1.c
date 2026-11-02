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
int vf3_away_batch224_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b2ddau: goto P_0c0b2dda;
case 0x0c0b2ddcu: goto P_0c0b2ddc;
case 0x0c0b2ddeu: goto P_0c0b2dde;
case 0x0c0b2de0u: goto P_0c0b2de0;
case 0x0c0b2de2u: goto P_0c0b2de2;
case 0x0c0b2de4u: goto P_0c0b2de4;
case 0x0c0b2de6u: goto P_0c0b2de6;
case 0x0c0b2de8u: goto P_0c0b2de8;
case 0x0c0b2deau: goto P_0c0b2dea;
case 0x0c0b2decu: goto P_0c0b2dec;
case 0x0c0b2deeu: goto P_0c0b2dee;
case 0x0c0b2df0u: goto P_0c0b2df0;
case 0x0c0b2df2u: goto P_0c0b2df2;
case 0x0c0b2df4u: goto P_0c0b2df4;
case 0x0c0b2df6u: goto P_0c0b2df6;
case 0x0c0b2df8u: goto P_0c0b2df8;
case 0x0c0b2dfau: goto P_0c0b2dfa;
case 0x0c0b2dfcu: goto P_0c0b2dfc;
case 0x0c0b2dfeu: goto P_0c0b2dfe;
case 0x0c0b2e00u: goto P_0c0b2e00;
case 0x0c0b2e02u: goto P_0c0b2e02;
case 0x0c0b2e04u: goto P_0c0b2e04;
case 0x0c0b2e06u: goto P_0c0b2e06;
case 0x0c0b2e08u: goto P_0c0b2e08;
case 0x0c0b2e0au: goto P_0c0b2e0a;
case 0x0c0b2e0cu: goto P_0c0b2e0c;
case 0x0c0b2e0eu: goto P_0c0b2e0e;
case 0x0c0b2e10u: goto P_0c0b2e10;
case 0x0c0b2e12u: goto P_0c0b2e12;
case 0x0c0b2e14u: goto P_0c0b2e14;
case 0x0c0b2e16u: goto P_0c0b2e16;
case 0x0c0b2e18u: goto P_0c0b2e18;
case 0x0c0b2e1au: goto P_0c0b2e1a;
case 0x0c0b2e1cu: goto P_0c0b2e1c;
case 0x0c0b2e1eu: goto P_0c0b2e1e;
case 0x0c0b2e20u: goto P_0c0b2e20;
case 0x0c0b2e22u: goto P_0c0b2e22;
case 0x0c0b2e24u: goto P_0c0b2e24;
case 0x0c0b2e26u: goto P_0c0b2e26;
case 0x0c0b2e28u: goto P_0c0b2e28;
case 0x0c0b2e2au: goto P_0c0b2e2a;
case 0x0c0b2e2cu: goto P_0c0b2e2c;
case 0x0c0b2e2eu: goto P_0c0b2e2e;
case 0x0c0b2e30u: goto P_0c0b2e30;
case 0x0c0b2e32u: goto P_0c0b2e32;
case 0x0c0b2e34u: goto P_0c0b2e34;
case 0x0c0b2e36u: goto P_0c0b2e36;
case 0x0c0b2e38u: goto P_0c0b2e38;
case 0x0c0b2e3au: goto P_0c0b2e3a;
case 0x0c0b2e3cu: goto P_0c0b2e3c;
case 0x0c0b2e3eu: goto P_0c0b2e3e;
case 0x0c0b2e40u: goto P_0c0b2e40;
case 0x0c0b2e42u: goto P_0c0b2e42;
case 0x0c0b2e44u: goto P_0c0b2e44;
case 0x0c0b2e46u: goto P_0c0b2e46;
case 0x0c0b2e48u: goto P_0c0b2e48;
case 0x0c0b2e4au: goto P_0c0b2e4a;
case 0x0c0b2e4cu: goto P_0c0b2e4c;
case 0x0c0b2e4eu: goto P_0c0b2e4e;
case 0x0c0b2e50u: goto P_0c0b2e50;
case 0x0c0b2e52u: goto P_0c0b2e52;
case 0x0c0b2e54u: goto P_0c0b2e54;
case 0x0c0b2e56u: goto P_0c0b2e56;
case 0x0c0b2e58u: goto P_0c0b2e58;
case 0x0c0b2e5au: goto P_0c0b2e5a;
case 0x0c0b2e5cu: goto P_0c0b2e5c;
case 0x0c0b2e5eu: goto P_0c0b2e5e;
case 0x0c0b2e60u: goto P_0c0b2e60;
case 0x0c0b2e62u: goto P_0c0b2e62;
case 0x0c0b2e64u: goto P_0c0b2e64;
case 0x0c0b2e66u: goto P_0c0b2e66;
case 0x0c0b2e68u: goto P_0c0b2e68;
case 0x0c0b2e6au: goto P_0c0b2e6a;
case 0x0c0b2e6cu: goto P_0c0b2e6c;
case 0x0c0b2e6eu: goto P_0c0b2e6e;
case 0x0c0b2e70u: goto P_0c0b2e70;
case 0x0c0b2e72u: goto P_0c0b2e72;
case 0x0c0b2e74u: goto P_0c0b2e74;
case 0x0c0b2e76u: goto P_0c0b2e76;
case 0x0c0b2e78u: goto P_0c0b2e78;
case 0x0c0b2e7au: goto P_0c0b2e7a;
case 0x0c0b2e7cu: goto P_0c0b2e7c;
case 0x0c0b2e7eu: goto P_0c0b2e7e;
case 0x0c0b2e80u: goto P_0c0b2e80;
case 0x0c0b2e82u: goto P_0c0b2e82;
case 0x0c0b2e84u: goto P_0c0b2e84;
case 0x0c0b2e86u: goto P_0c0b2e86;
case 0x0c0b2e88u: goto P_0c0b2e88;
case 0x0c0b2e8au: goto P_0c0b2e8a;
case 0x0c0b2e8cu: goto P_0c0b2e8c;
case 0x0c0b2e8eu: goto P_0c0b2e8e;
case 0x0c0b2e90u: goto P_0c0b2e90;
case 0x0c0b2e92u: goto P_0c0b2e92;
case 0x0c0b2e94u: goto P_0c0b2e94;
case 0x0c0b2e96u: goto P_0c0b2e96;
case 0x0c0b2e98u: goto P_0c0b2e98;
case 0x0c0b2e9au: goto P_0c0b2e9a;
case 0x0c0b2e9cu: goto P_0c0b2e9c;
case 0x0c0b2e9eu: goto P_0c0b2e9e;
case 0x0c0b2ea0u: goto P_0c0b2ea0;
case 0x0c0b2ea2u: goto P_0c0b2ea2;
case 0x0c0b2ea4u: goto P_0c0b2ea4;
case 0x0c0b2ea6u: goto P_0c0b2ea6;
case 0x0c0b2ea8u: goto P_0c0b2ea8;
case 0x0c0b2eaau: goto P_0c0b2eaa;
case 0x0c0b2eacu: goto P_0c0b2eac;
case 0x0c0b2eaeu: goto P_0c0b2eae;
case 0x0c0b2eb0u: goto P_0c0b2eb0;
case 0x0c0b2eb2u: goto P_0c0b2eb2;
case 0x0c0b2eb4u: goto P_0c0b2eb4;
case 0x0c0b2eb6u: goto P_0c0b2eb6;
case 0x0c0b2eb8u: goto P_0c0b2eb8;
case 0x0c0b2ebau: goto P_0c0b2eba;
case 0x0c0b2ebcu: goto P_0c0b2ebc;
case 0x0c0b2ebeu: goto P_0c0b2ebe;
case 0x0c0b2ec0u: goto P_0c0b2ec0;
case 0x0c0b2ec2u: goto P_0c0b2ec2;
case 0x0c0b2ec4u: goto P_0c0b2ec4;
case 0x0c0b2ec6u: goto P_0c0b2ec6;
case 0x0c0b2ec8u: goto P_0c0b2ec8;
case 0x0c0b2ecau: goto P_0c0b2eca;
case 0x0c0b2eccu: goto P_0c0b2ecc;
case 0x0c0b2eceu: goto P_0c0b2ece;
case 0x0c0b2ed0u: goto P_0c0b2ed0;
case 0x0c0b2ed2u: goto P_0c0b2ed2;
case 0x0c0b2ed4u: goto P_0c0b2ed4;
case 0x0c0b2ed6u: goto P_0c0b2ed6;
case 0x0c0b2ed8u: goto P_0c0b2ed8;
case 0x0c0b2edau: goto P_0c0b2eda;
case 0x0c0b2edcu: goto P_0c0b2edc;
case 0x0c0b2edeu: goto P_0c0b2ede;
case 0x0c0b2ee0u: goto P_0c0b2ee0;
case 0x0c0b2ee2u: goto P_0c0b2ee2;
case 0x0c0b2ee4u: goto P_0c0b2ee4;
case 0x0c0b2ee6u: goto P_0c0b2ee6;
case 0x0c0b2ee8u: goto P_0c0b2ee8;
case 0x0c0b2eeau: goto P_0c0b2eea;
case 0x0c0b2eecu: goto P_0c0b2eec;
case 0x0c0b2eeeu: goto P_0c0b2eee;
case 0x0c0b2ef0u: goto P_0c0b2ef0;
case 0x0c0b2ef2u: goto P_0c0b2ef2;
case 0x0c0b2ef4u: goto P_0c0b2ef4;
case 0x0c0b2ef6u: goto P_0c0b2ef6;
case 0x0c0b2ef8u: goto P_0c0b2ef8;
case 0x0c0b2efau: goto P_0c0b2efa;
case 0x0c0b2efcu: goto P_0c0b2efc;
case 0x0c0b2efeu: goto P_0c0b2efe;
case 0x0c0b2f00u: goto P_0c0b2f00;
case 0x0c0b2f02u: goto P_0c0b2f02;
case 0x0c0b2f04u: goto P_0c0b2f04;
case 0x0c0b2f06u: goto P_0c0b2f06;
case 0x0c0b2f08u: goto P_0c0b2f08;
case 0x0c0b2f0au: goto P_0c0b2f0a;
case 0x0c0b2f0cu: goto P_0c0b2f0c;
case 0x0c0b2f0eu: goto P_0c0b2f0e;
case 0x0c0b2f10u: goto P_0c0b2f10;
case 0x0c0b2f12u: goto P_0c0b2f12;
case 0x0c0b2f14u: goto P_0c0b2f14;
case 0x0c0b2f16u: goto P_0c0b2f16;
case 0x0c0b2f18u: goto P_0c0b2f18;
case 0x0c0b2f1au: goto P_0c0b2f1a;
case 0x0c0b2f1cu: goto P_0c0b2f1c;
case 0x0c0b2f1eu: goto P_0c0b2f1e;
case 0x0c0b2f20u: goto P_0c0b2f20;
case 0x0c0b2f22u: goto P_0c0b2f22;
case 0x0c0b2f24u: goto P_0c0b2f24;
case 0x0c0b2f26u: goto P_0c0b2f26;
case 0x0c0b2f28u: goto P_0c0b2f28;
case 0x0c0b2f2au: goto P_0c0b2f2a;
case 0x0c0b2f2cu: goto P_0c0b2f2c;
case 0x0c0b2f2eu: goto P_0c0b2f2e;
case 0x0c0b2f30u: goto P_0c0b2f30;
case 0x0c0b2f32u: goto P_0c0b2f32;
case 0x0c0b2f34u: goto P_0c0b2f34;
case 0x0c0b2f36u: goto P_0c0b2f36;
case 0x0c0b2f38u: goto P_0c0b2f38;
case 0x0c0b2f3au: goto P_0c0b2f3a;
case 0x0c0b2f3cu: goto P_0c0b2f3c;
case 0x0c0b2facu: goto P_0c0b2fac;
case 0x0c0b2faeu: goto P_0c0b2fae;
case 0x0c0b2fb0u: goto P_0c0b2fb0;
case 0x0c0b2fb2u: goto P_0c0b2fb2;
case 0x0c0b2fb4u: goto P_0c0b2fb4;
case 0x0c0b2fb6u: goto P_0c0b2fb6;
case 0x0c0b2fb8u: goto P_0c0b2fb8;
case 0x0c0b2fbau: goto P_0c0b2fba;
case 0x0c0b2fbcu: goto P_0c0b2fbc;
case 0x0c0b2fbeu: goto P_0c0b2fbe;
case 0x0c0b2fc0u: goto P_0c0b2fc0;
case 0x0c0b2fc2u: goto P_0c0b2fc2;
case 0x0c0b2fc4u: goto P_0c0b2fc4;
case 0x0c0b2fc6u: goto P_0c0b2fc6;
case 0x0c0b2fc8u: goto P_0c0b2fc8;
case 0x0c0b2fcau: goto P_0c0b2fca;
case 0x0c0b2fccu: goto P_0c0b2fcc;
case 0x0c0b2fceu: goto P_0c0b2fce;
case 0x0c0b2fd0u: goto P_0c0b2fd0;
case 0x0c0b2fd2u: goto P_0c0b2fd2;
case 0x0c0b2fd4u: goto P_0c0b2fd4;
case 0x0c0b2fd6u: goto P_0c0b2fd6;
case 0x0c0b2fd8u: goto P_0c0b2fd8;
case 0x0c0b2fdau: goto P_0c0b2fda;
case 0x0c0b2fdcu: goto P_0c0b2fdc;
case 0x0c0b2fdeu: goto P_0c0b2fde;
case 0x0c0b2fe0u: goto P_0c0b2fe0;
case 0x0c0b2fe2u: goto P_0c0b2fe2;
case 0x0c0b2fe4u: goto P_0c0b2fe4;
case 0x0c0b2fe6u: goto P_0c0b2fe6;
case 0x0c0b2fe8u: goto P_0c0b2fe8;
case 0x0c0b2feau: goto P_0c0b2fea;
case 0x0c0b2fecu: goto P_0c0b2fec;
case 0x0c0b2feeu: goto P_0c0b2fee;
case 0x0c0b2ff0u: goto P_0c0b2ff0;
case 0x0c0b2ff2u: goto P_0c0b2ff2;
case 0x0c0b2ff4u: goto P_0c0b2ff4;
case 0x0c0b2ff6u: goto P_0c0b2ff6;
case 0x0c0b2ff8u: goto P_0c0b2ff8;
case 0x0c0b2ffau: goto P_0c0b2ffa;
case 0x0c0b2ffcu: goto P_0c0b2ffc;
case 0x0c0b2ffeu: goto P_0c0b2ffe;
case 0x0c0b3000u: goto P_0c0b3000;
case 0x0c0b3002u: goto P_0c0b3002;
case 0x0c0b3004u: goto P_0c0b3004;
case 0x0c0b3006u: goto P_0c0b3006;
case 0x0c0b3008u: goto P_0c0b3008;
case 0x0c0b300au: goto P_0c0b300a;
case 0x0c0b300cu: goto P_0c0b300c;
case 0x0c0b300eu: goto P_0c0b300e;
case 0x0c0b3010u: goto P_0c0b3010;
case 0x0c0b3012u: goto P_0c0b3012;
case 0x0c0b3014u: goto P_0c0b3014;
case 0x0c0b3016u: goto P_0c0b3016;
case 0x0c0b3018u: goto P_0c0b3018;
case 0x0c0b301au: goto P_0c0b301a;
case 0x0c0b301cu: goto P_0c0b301c;
case 0x0c0b301eu: goto P_0c0b301e;
case 0x0c0b3020u: goto P_0c0b3020;
case 0x0c0b3022u: goto P_0c0b3022;
case 0x0c0b3024u: goto P_0c0b3024;
case 0x0c0b3026u: goto P_0c0b3026;
case 0x0c0b3028u: goto P_0c0b3028;
case 0x0c0b302au: goto P_0c0b302a;
case 0x0c0b302cu: goto P_0c0b302c;
case 0x0c0b302eu: goto P_0c0b302e;
case 0x0c0b3030u: goto P_0c0b3030;
case 0x0c0b3032u: goto P_0c0b3032;
case 0x0c0b3034u: goto P_0c0b3034;
case 0x0c0b3036u: goto P_0c0b3036;
case 0x0c0b3038u: goto P_0c0b3038;
case 0x0c0b303au: goto P_0c0b303a;
case 0x0c0b303cu: goto P_0c0b303c;
case 0x0c0b303eu: goto P_0c0b303e;
case 0x0c0b3040u: goto P_0c0b3040;
case 0x0c0b3042u: goto P_0c0b3042;
case 0x0c0b3044u: goto P_0c0b3044;
case 0x0c0b3046u: goto P_0c0b3046;
case 0x0c0b3048u: goto P_0c0b3048;
case 0x0c0b304au: goto P_0c0b304a;
case 0x0c0b304cu: goto P_0c0b304c;
case 0x0c0b304eu: goto P_0c0b304e;
case 0x0c0b3050u: goto P_0c0b3050;
case 0x0c0b3052u: goto P_0c0b3052;
case 0x0c0b3054u: goto P_0c0b3054;
case 0x0c0b3056u: goto P_0c0b3056;
case 0x0c0b3058u: goto P_0c0b3058;
case 0x0c0b305au: goto P_0c0b305a;
case 0x0c0b305cu: goto P_0c0b305c;
case 0x0c0b305eu: goto P_0c0b305e;
case 0x0c0b3060u: goto P_0c0b3060;
case 0x0c0b3062u: goto P_0c0b3062;
case 0x0c0b3064u: goto P_0c0b3064;
case 0x0c0b3066u: goto P_0c0b3066;
case 0x0c0b3068u: goto P_0c0b3068;
case 0x0c0b306au: goto P_0c0b306a;
case 0x0c0b306cu: goto P_0c0b306c;
case 0x0c0b306eu: goto P_0c0b306e;
case 0x0c0b3070u: goto P_0c0b3070;
case 0x0c0b3072u: goto P_0c0b3072;
case 0x0c0b3074u: goto P_0c0b3074;
case 0x0c0b3076u: goto P_0c0b3076;
case 0x0c0b3078u: goto P_0c0b3078;
case 0x0c0b307au: goto P_0c0b307a;
case 0x0c0b307cu: goto P_0c0b307c;
case 0x0c0b307eu: goto P_0c0b307e;
case 0x0c0b3080u: goto P_0c0b3080;
case 0x0c0b3082u: goto P_0c0b3082;
case 0x0c0b3084u: goto P_0c0b3084;
case 0x0c0b3086u: goto P_0c0b3086;
case 0x0c0b3088u: goto P_0c0b3088;
case 0x0c0b308au: goto P_0c0b308a;
case 0x0c0b308cu: goto P_0c0b308c;
case 0x0c0b308eu: goto P_0c0b308e;
case 0x0c0b3090u: goto P_0c0b3090;
case 0x0c0b3092u: goto P_0c0b3092;
case 0x0c0b3094u: goto P_0c0b3094;
case 0x0c0b3096u: goto P_0c0b3096;
case 0x0c0b3098u: goto P_0c0b3098;
case 0x0c0b309au: goto P_0c0b309a;
case 0x0c0b309cu: goto P_0c0b309c;
case 0x0c0b309eu: goto P_0c0b309e;
case 0x0c0b30a0u: goto P_0c0b30a0;
case 0x0c0b30a2u: goto P_0c0b30a2;
case 0x0c0b30a4u: goto P_0c0b30a4;
case 0x0c0b30a6u: goto P_0c0b30a6;
case 0x0c0b30a8u: goto P_0c0b30a8;
case 0x0c0b30aau: goto P_0c0b30aa;
case 0x0c0b30acu: goto P_0c0b30ac;
case 0x0c0b30aeu: goto P_0c0b30ae;
case 0x0c0b30b0u: goto P_0c0b30b0;
case 0x0c0b30b2u: goto P_0c0b30b2;
case 0x0c0b30b4u: goto P_0c0b30b4;
case 0x0c0b30b6u: goto P_0c0b30b6;
case 0x0c0b30b8u: goto P_0c0b30b8;
case 0x0c0b30bau: goto P_0c0b30ba;
case 0x0c0b30bcu: goto P_0c0b30bc;
case 0x0c0b30beu: goto P_0c0b30be;
case 0x0c0b30c0u: goto P_0c0b30c0;
case 0x0c0b30c2u: goto P_0c0b30c2;
case 0x0c0b30c4u: goto P_0c0b30c4;
case 0x0c0b30c6u: goto P_0c0b30c6;
case 0x0c0b30c8u: goto P_0c0b30c8;
case 0x0c0b30cau: goto P_0c0b30ca;
case 0x0c0b30ccu: goto P_0c0b30cc;
case 0x0c0b30ceu: goto P_0c0b30ce;
case 0x0c0b30d0u: goto P_0c0b30d0;
case 0x0c0b30d2u: goto P_0c0b30d2;
case 0x0c0b30d4u: goto P_0c0b30d4;
case 0x0c0b30d6u: goto P_0c0b30d6;
case 0x0c0b30d8u: goto P_0c0b30d8;
case 0x0c0b30dau: goto P_0c0b30da;
case 0x0c0b30dcu: goto P_0c0b30dc;
case 0x0c0b30deu: goto P_0c0b30de;
case 0x0c0b30e0u: goto P_0c0b30e0;
case 0x0c0b30e2u: goto P_0c0b30e2;
case 0x0c0b30e4u: goto P_0c0b30e4;
case 0x0c0b30e6u: goto P_0c0b30e6;
case 0x0c0b30e8u: goto P_0c0b30e8;
case 0x0c0b30eau: goto P_0c0b30ea;
case 0x0c0b30ecu: goto P_0c0b30ec;
case 0x0c0b30eeu: goto P_0c0b30ee;
case 0x0c0b30f0u: goto P_0c0b30f0;
case 0x0c0b30f2u: goto P_0c0b30f2;
case 0x0c0b30f4u: goto P_0c0b30f4;
case 0x0c0b30f6u: goto P_0c0b30f6;
case 0x0c0b30f8u: goto P_0c0b30f8;
case 0x0c0b30fau: goto P_0c0b30fa;
case 0x0c0b30fcu: goto P_0c0b30fc;
case 0x0c0b30feu: goto P_0c0b30fe;
case 0x0c0b3100u: goto P_0c0b3100;
case 0x0c0b3102u: goto P_0c0b3102;
case 0x0c0b3104u: goto P_0c0b3104;
case 0x0c0b317eu: goto P_0c0b317e;
case 0x0c0b3180u: goto P_0c0b3180;
case 0x0c0b3182u: goto P_0c0b3182;
case 0x0c0b3184u: goto P_0c0b3184;
case 0x0c0b3186u: goto P_0c0b3186;
case 0x0c0b3188u: goto P_0c0b3188;
case 0x0c0b318au: goto P_0c0b318a;
case 0x0c0b318cu: goto P_0c0b318c;
case 0x0c0b318eu: goto P_0c0b318e;
case 0x0c0b3190u: goto P_0c0b3190;
case 0x0c0b3192u: goto P_0c0b3192;
case 0x0c0b3194u: goto P_0c0b3194;
case 0x0c0b3196u: goto P_0c0b3196;
case 0x0c0b3198u: goto P_0c0b3198;
case 0x0c0b319au: goto P_0c0b319a;
case 0x0c0b319cu: goto P_0c0b319c;
case 0x0c0b319eu: goto P_0c0b319e;
case 0x0c0b31a0u: goto P_0c0b31a0;
case 0x0c0b31a2u: goto P_0c0b31a2;
case 0x0c0b31a4u: goto P_0c0b31a4;
case 0x0c0b31a6u: goto P_0c0b31a6;
case 0x0c0b31a8u: goto P_0c0b31a8;
case 0x0c0b31aau: goto P_0c0b31aa;
case 0x0c0b31acu: goto P_0c0b31ac;
case 0x0c0b31aeu: goto P_0c0b31ae;
case 0x0c0b31b0u: goto P_0c0b31b0;
case 0x0c0b31b2u: goto P_0c0b31b2;
case 0x0c0b31b4u: goto P_0c0b31b4;
case 0x0c0b31b6u: goto P_0c0b31b6;
case 0x0c0b31b8u: goto P_0c0b31b8;
case 0x0c0b31bau: goto P_0c0b31ba;
case 0x0c0b31bcu: goto P_0c0b31bc;
case 0x0c0b31beu: goto P_0c0b31be;
case 0x0c0b31c0u: goto P_0c0b31c0;
case 0x0c0b31c2u: goto P_0c0b31c2;
case 0x0c0b31c4u: goto P_0c0b31c4;
case 0x0c0b31c6u: goto P_0c0b31c6;
case 0x0c0b31c8u: goto P_0c0b31c8;
case 0x0c0b31cau: goto P_0c0b31ca;
case 0x0c0b31ccu: goto P_0c0b31cc;
case 0x0c0b31ceu: goto P_0c0b31ce;
case 0x0c0b31d0u: goto P_0c0b31d0;
case 0x0c0b31d2u: goto P_0c0b31d2;
case 0x0c0b31d4u: goto P_0c0b31d4;
case 0x0c0b31d6u: goto P_0c0b31d6;
case 0x0c0b31d8u: goto P_0c0b31d8;
case 0x0c0b31dau: goto P_0c0b31da;
case 0x0c0b31dcu: goto P_0c0b31dc;
case 0x0c0b31deu: goto P_0c0b31de;
case 0x0c0b31e0u: goto P_0c0b31e0;
case 0x0c0b31e2u: goto P_0c0b31e2;
case 0x0c0b31e4u: goto P_0c0b31e4;
case 0x0c0b31e6u: goto P_0c0b31e6;
case 0x0c0b31e8u: goto P_0c0b31e8;
case 0x0c0b31eau: goto P_0c0b31ea;
case 0x0c0b31ecu: goto P_0c0b31ec;
case 0x0c0b31eeu: goto P_0c0b31ee;
case 0x0c0b31f0u: goto P_0c0b31f0;
case 0x0c0b31f2u: goto P_0c0b31f2;
case 0x0c0b31f4u: goto P_0c0b31f4;
case 0x0c0b31f6u: goto P_0c0b31f6;
case 0x0c0b31f8u: goto P_0c0b31f8;
case 0x0c0b31fau: goto P_0c0b31fa;
case 0x0c0b31fcu: goto P_0c0b31fc;
case 0x0c0b31feu: goto P_0c0b31fe;
case 0x0c0b3200u: goto P_0c0b3200;
case 0x0c0b3202u: goto P_0c0b3202;
case 0x0c0b3204u: goto P_0c0b3204;
case 0x0c0b3206u: goto P_0c0b3206;
case 0x0c0b3208u: goto P_0c0b3208;
case 0x0c0b320au: goto P_0c0b320a;
case 0x0c0b320cu: goto P_0c0b320c;
case 0x0c0b320eu: goto P_0c0b320e;
case 0x0c0b3210u: goto P_0c0b3210;
case 0x0c0b3212u: goto P_0c0b3212;
case 0x0c0b3214u: goto P_0c0b3214;
case 0x0c0b3216u: goto P_0c0b3216;
case 0x0c0b3218u: goto P_0c0b3218;
case 0x0c0b321au: goto P_0c0b321a;
case 0x0c0b321cu: goto P_0c0b321c;
case 0x0c0b321eu: goto P_0c0b321e;
case 0x0c0b3220u: goto P_0c0b3220;
case 0x0c0b3222u: goto P_0c0b3222;
case 0x0c0b3224u: goto P_0c0b3224;
case 0x0c0b3226u: goto P_0c0b3226;
case 0x0c0b3228u: goto P_0c0b3228;
case 0x0c0b322au: goto P_0c0b322a;
case 0x0c0b322cu: goto P_0c0b322c;
case 0x0c0b322eu: goto P_0c0b322e;
case 0x0c0b3230u: goto P_0c0b3230;
case 0x0c0b3232u: goto P_0c0b3232;
case 0x0c0b3234u: goto P_0c0b3234;
case 0x0c0b3236u: goto P_0c0b3236;
case 0x0c0b3238u: goto P_0c0b3238;
case 0x0c0b323au: goto P_0c0b323a;
case 0x0c0b323cu: goto P_0c0b323c;
case 0x0c0b323eu: goto P_0c0b323e;
case 0x0c0b3240u: goto P_0c0b3240;
case 0x0c0b3242u: goto P_0c0b3242;
case 0x0c0b3244u: goto P_0c0b3244;
case 0x0c0b3246u: goto P_0c0b3246;
case 0x0c0b3248u: goto P_0c0b3248;
case 0x0c0b324au: goto P_0c0b324a;
case 0x0c0b324cu: goto P_0c0b324c;
case 0x0c0b324eu: goto P_0c0b324e;
case 0x0c0b3250u: goto P_0c0b3250;
case 0x0c0b3252u: goto P_0c0b3252;
case 0x0c0b3254u: goto P_0c0b3254;
case 0x0c0b3256u: goto P_0c0b3256;
case 0x0c0b3258u: goto P_0c0b3258;
case 0x0c0b325au: goto P_0c0b325a;
case 0x0c0b325cu: goto P_0c0b325c;
case 0x0c0b325eu: goto P_0c0b325e;
case 0x0c0b3260u: goto P_0c0b3260;
case 0x0c0b3262u: goto P_0c0b3262;
case 0x0c0b3264u: goto P_0c0b3264;
case 0x0c0b3266u: goto P_0c0b3266;
case 0x0c0b3268u: goto P_0c0b3268;
case 0x0c0b326au: goto P_0c0b326a;
case 0x0c0b326cu: goto P_0c0b326c;
case 0x0c0b326eu: goto P_0c0b326e;
case 0x0c0b3270u: goto P_0c0b3270;
case 0x0c0b3272u: goto P_0c0b3272;
case 0x0c0b3274u: goto P_0c0b3274;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b2dda: /* original 2fe6, guest PC 0x0c0b2dda */
if(!s->budget--) { s->failed_pc=0x0c0b2ddau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2ddc;
P_0c0b2ddc: /* original 2fd6, guest PC 0x0c0b2ddc */
if(!s->budget--) { s->failed_pc=0x0c0b2ddcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2dde;
P_0c0b2dde: /* original 2fc6, guest PC 0x0c0b2dde */
if(!s->budget--) { s->failed_pc=0x0c0b2ddeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2de0;
P_0c0b2de0: /* original 2fb6, guest PC 0x0c0b2de0 */
if(!s->budget--) { s->failed_pc=0x0c0b2de0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2de2;
P_0c0b2de2: /* original 2fa6, guest PC 0x0c0b2de2 */
if(!s->budget--) { s->failed_pc=0x0c0b2de2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2de4;
P_0c0b2de4: /* original 2f96, guest PC 0x0c0b2de4 */
if(!s->budget--) { s->failed_pc=0x0c0b2de4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2de6;
P_0c0b2de6: /* original 4f22, guest PC 0x0c0b2de6 */
if(!s->budget--) { s->failed_pc=0x0c0b2de6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b2de8;
P_0c0b2de8: /* original 5d44, guest PC 0x0c0b2de8 */
if(!s->budget--) { s->failed_pc=0x0c0b2de8u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b2dea;
P_0c0b2dea: /* original 94a8, guest PC 0x0c0b2dea */
if(!s->budget--) { s->failed_pc=0x0c0b2deau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f3eu,2);
goto P_0c0b2dec;
P_0c0b2dec: /* original de6e, guest PC 0x0c0b2dec */
if(!s->budget--) { s->failed_pc=0x0c0b2decu; return 0; }
r[14]=read(ram,0x0c0b2fa8u,4);
goto P_0c0b2dee;
P_0c0b2dee: /* original 7ff8, guest PC 0x0c0b2dee */
if(!s->budget--) { s->failed_pc=0x0c0b2deeu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b2df0;
P_0c0b2df0: /* original 4e0b, guest PC 0x0c0b2df0 */
if(!s->budget--) { s->failed_pc=0x0c0b2df0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2df4u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2df4u) { target=s->pc; goto dispatch; }
goto P_0c0b2df4;
P_0c0b2df2: /* original 65d2, guest PC 0x0c0b2df2 */
if(!s->budget--) { s->failed_pc=0x0c0b2df2u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b2df4;
P_0c0b2df4: /* original 94a4, guest PC 0x0c0b2df4 */
if(!s->budget--) { s->failed_pc=0x0c0b2df4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f40u,2);
goto P_0c0b2df6;
P_0c0b2df6: /* original 4e0b, guest PC 0x0c0b2df6 */
if(!s->budget--) { s->failed_pc=0x0c0b2df6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2dfau;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2dfau) { target=s->pc; goto dispatch; }
goto P_0c0b2dfa;
P_0c0b2df8: /* original 55d1, guest PC 0x0c0b2df8 */
if(!s->budget--) { s->failed_pc=0x0c0b2df8u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b2dfa;
P_0c0b2dfa: /* original 94a2, guest PC 0x0c0b2dfa */
if(!s->budget--) { s->failed_pc=0x0c0b2dfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f42u,2);
goto P_0c0b2dfc;
P_0c0b2dfc: /* original 4e0b, guest PC 0x0c0b2dfc */
if(!s->budget--) { s->failed_pc=0x0c0b2dfcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e00u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e00u) { target=s->pc; goto dispatch; }
goto P_0c0b2e00;
P_0c0b2dfe: /* original 55d2, guest PC 0x0c0b2dfe */
if(!s->budget--) { s->failed_pc=0x0c0b2dfeu; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b2e00;
P_0c0b2e00: /* original 94a0, guest PC 0x0c0b2e00 */
if(!s->budget--) { s->failed_pc=0x0c0b2e00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f44u,2);
goto P_0c0b2e02;
P_0c0b2e02: /* original 4e0b, guest PC 0x0c0b2e02 */
if(!s->budget--) { s->failed_pc=0x0c0b2e02u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e06u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e06u) { target=s->pc; goto dispatch; }
goto P_0c0b2e06;
P_0c0b2e04: /* original 55d3, guest PC 0x0c0b2e04 */
if(!s->budget--) { s->failed_pc=0x0c0b2e04u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b2e06;
P_0c0b2e06: /* original 949e, guest PC 0x0c0b2e06 */
if(!s->budget--) { s->failed_pc=0x0c0b2e06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f46u,2);
goto P_0c0b2e08;
P_0c0b2e08: /* original 4e0b, guest PC 0x0c0b2e08 */
if(!s->budget--) { s->failed_pc=0x0c0b2e08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e0cu;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e0cu) { target=s->pc; goto dispatch; }
goto P_0c0b2e0c;
P_0c0b2e0a: /* original 55d4, guest PC 0x0c0b2e0a */
if(!s->budget--) { s->failed_pc=0x0c0b2e0au; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b2e0c;
P_0c0b2e0c: /* original 949c, guest PC 0x0c0b2e0c */
if(!s->budget--) { s->failed_pc=0x0c0b2e0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f48u,2);
goto P_0c0b2e0e;
P_0c0b2e0e: /* original 4e0b, guest PC 0x0c0b2e0e */
if(!s->budget--) { s->failed_pc=0x0c0b2e0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e12u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e12u) { target=s->pc; goto dispatch; }
goto P_0c0b2e12;
P_0c0b2e10: /* original 55d5, guest PC 0x0c0b2e10 */
if(!s->budget--) { s->failed_pc=0x0c0b2e10u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b2e12;
P_0c0b2e12: /* original 949a, guest PC 0x0c0b2e12 */
if(!s->budget--) { s->failed_pc=0x0c0b2e12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f4au,2);
goto P_0c0b2e14;
P_0c0b2e14: /* original 4e0b, guest PC 0x0c0b2e14 */
if(!s->budget--) { s->failed_pc=0x0c0b2e14u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e18u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e18u) { target=s->pc; goto dispatch; }
goto P_0c0b2e18;
P_0c0b2e16: /* original 55d6, guest PC 0x0c0b2e16 */
if(!s->budget--) { s->failed_pc=0x0c0b2e16u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b2e18;
P_0c0b2e18: /* original 9498, guest PC 0x0c0b2e18 */
if(!s->budget--) { s->failed_pc=0x0c0b2e18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f4cu,2);
goto P_0c0b2e1a;
P_0c0b2e1a: /* original 4e0b, guest PC 0x0c0b2e1a */
if(!s->budget--) { s->failed_pc=0x0c0b2e1au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e1eu;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e1eu) { target=s->pc; goto dispatch; }
goto P_0c0b2e1e;
P_0c0b2e1c: /* original 55d7, guest PC 0x0c0b2e1c */
if(!s->budget--) { s->failed_pc=0x0c0b2e1cu; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b2e1e;
P_0c0b2e1e: /* original 9496, guest PC 0x0c0b2e1e */
if(!s->budget--) { s->failed_pc=0x0c0b2e1eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f4eu,2);
goto P_0c0b2e20;
P_0c0b2e20: /* original 4e0b, guest PC 0x0c0b2e20 */
if(!s->budget--) { s->failed_pc=0x0c0b2e20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e24u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e24u) { target=s->pc; goto dispatch; }
goto P_0c0b2e24;
P_0c0b2e22: /* original 55d8, guest PC 0x0c0b2e22 */
if(!s->budget--) { s->failed_pc=0x0c0b2e22u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b2e24;
P_0c0b2e24: /* original 9494, guest PC 0x0c0b2e24 */
if(!s->budget--) { s->failed_pc=0x0c0b2e24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f50u,2);
goto P_0c0b2e26;
P_0c0b2e26: /* original 4e0b, guest PC 0x0c0b2e26 */
if(!s->budget--) { s->failed_pc=0x0c0b2e26u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e2au;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e2au) { target=s->pc; goto dispatch; }
goto P_0c0b2e2a;
P_0c0b2e28: /* original 55d9, guest PC 0x0c0b2e28 */
if(!s->budget--) { s->failed_pc=0x0c0b2e28u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b2e2a;
P_0c0b2e2a: /* original 9492, guest PC 0x0c0b2e2a */
if(!s->budget--) { s->failed_pc=0x0c0b2e2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f52u,2);
goto P_0c0b2e2c;
P_0c0b2e2c: /* original 4e0b, guest PC 0x0c0b2e2c */
if(!s->budget--) { s->failed_pc=0x0c0b2e2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e30u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e30u) { target=s->pc; goto dispatch; }
goto P_0c0b2e30;
P_0c0b2e2e: /* original 55da, guest PC 0x0c0b2e2e */
if(!s->budget--) { s->failed_pc=0x0c0b2e2eu; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b2e30;
P_0c0b2e30: /* original 9490, guest PC 0x0c0b2e30 */
if(!s->budget--) { s->failed_pc=0x0c0b2e30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f54u,2);
goto P_0c0b2e32;
P_0c0b2e32: /* original 4e0b, guest PC 0x0c0b2e32 */
if(!s->budget--) { s->failed_pc=0x0c0b2e32u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e36u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e36u) { target=s->pc; goto dispatch; }
goto P_0c0b2e36;
P_0c0b2e34: /* original 55db, guest PC 0x0c0b2e34 */
if(!s->budget--) { s->failed_pc=0x0c0b2e34u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b2e36;
P_0c0b2e36: /* original 948e, guest PC 0x0c0b2e36 */
if(!s->budget--) { s->failed_pc=0x0c0b2e36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f56u,2);
goto P_0c0b2e38;
P_0c0b2e38: /* original 4e0b, guest PC 0x0c0b2e38 */
if(!s->budget--) { s->failed_pc=0x0c0b2e38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e3cu;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e3cu) { target=s->pc; goto dispatch; }
goto P_0c0b2e3c;
P_0c0b2e3a: /* original 55dc, guest PC 0x0c0b2e3a */
if(!s->budget--) { s->failed_pc=0x0c0b2e3au; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b2e3c;
P_0c0b2e3c: /* original 948c, guest PC 0x0c0b2e3c */
if(!s->budget--) { s->failed_pc=0x0c0b2e3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f58u,2);
goto P_0c0b2e3e;
P_0c0b2e3e: /* original 4e0b, guest PC 0x0c0b2e3e */
if(!s->budget--) { s->failed_pc=0x0c0b2e3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e42u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e42u) { target=s->pc; goto dispatch; }
goto P_0c0b2e42;
P_0c0b2e40: /* original 55dd, guest PC 0x0c0b2e40 */
if(!s->budget--) { s->failed_pc=0x0c0b2e40u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b2e42;
P_0c0b2e42: /* original 948a, guest PC 0x0c0b2e42 */
if(!s->budget--) { s->failed_pc=0x0c0b2e42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f5au,2);
goto P_0c0b2e44;
P_0c0b2e44: /* original 4e0b, guest PC 0x0c0b2e44 */
if(!s->budget--) { s->failed_pc=0x0c0b2e44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e48u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e48u) { target=s->pc; goto dispatch; }
goto P_0c0b2e48;
P_0c0b2e46: /* original 55de, guest PC 0x0c0b2e46 */
if(!s->budget--) { s->failed_pc=0x0c0b2e46u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b2e48;
P_0c0b2e48: /* original 9488, guest PC 0x0c0b2e48 */
if(!s->budget--) { s->failed_pc=0x0c0b2e48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f5cu,2);
goto P_0c0b2e4a;
P_0c0b2e4a: /* original 4e0b, guest PC 0x0c0b2e4a */
if(!s->budget--) { s->failed_pc=0x0c0b2e4au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e4eu;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e4eu) { target=s->pc; goto dispatch; }
goto P_0c0b2e4e;
P_0c0b2e4c: /* original 55df, guest PC 0x0c0b2e4c */
if(!s->budget--) { s->failed_pc=0x0c0b2e4cu; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b2e4e;
P_0c0b2e4e: /* original 9486, guest PC 0x0c0b2e4e */
if(!s->budget--) { s->failed_pc=0x0c0b2e4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f5eu,2);
goto P_0c0b2e50;
P_0c0b2e50: /* original e040, guest PC 0x0c0b2e50 */
if(!s->budget--) { s->failed_pc=0x0c0b2e50u; return 0; }
r[0]=0x00000040u;
goto P_0c0b2e52;
P_0c0b2e52: /* original 4e0b, guest PC 0x0c0b2e52 */
if(!s->budget--) { s->failed_pc=0x0c0b2e52u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e56u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e56u) { target=s->pc; goto dispatch; }
goto P_0c0b2e56;
P_0c0b2e54: /* original 05de, guest PC 0x0c0b2e54 */
if(!s->budget--) { s->failed_pc=0x0c0b2e54u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e56;
P_0c0b2e56: /* original 9483, guest PC 0x0c0b2e56 */
if(!s->budget--) { s->failed_pc=0x0c0b2e56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f60u,2);
goto P_0c0b2e58;
P_0c0b2e58: /* original e044, guest PC 0x0c0b2e58 */
if(!s->budget--) { s->failed_pc=0x0c0b2e58u; return 0; }
r[0]=0x00000044u;
goto P_0c0b2e5a;
P_0c0b2e5a: /* original 4e0b, guest PC 0x0c0b2e5a */
if(!s->budget--) { s->failed_pc=0x0c0b2e5au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e5eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e5eu) { target=s->pc; goto dispatch; }
goto P_0c0b2e5e;
P_0c0b2e5c: /* original 05de, guest PC 0x0c0b2e5c */
if(!s->budget--) { s->failed_pc=0x0c0b2e5cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e5e;
P_0c0b2e5e: /* original 9480, guest PC 0x0c0b2e5e */
if(!s->budget--) { s->failed_pc=0x0c0b2e5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f62u,2);
goto P_0c0b2e60;
P_0c0b2e60: /* original e048, guest PC 0x0c0b2e60 */
if(!s->budget--) { s->failed_pc=0x0c0b2e60u; return 0; }
r[0]=0x00000048u;
goto P_0c0b2e62;
P_0c0b2e62: /* original 4e0b, guest PC 0x0c0b2e62 */
if(!s->budget--) { s->failed_pc=0x0c0b2e62u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e66u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e66u) { target=s->pc; goto dispatch; }
goto P_0c0b2e66;
P_0c0b2e64: /* original 05de, guest PC 0x0c0b2e64 */
if(!s->budget--) { s->failed_pc=0x0c0b2e64u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e66;
P_0c0b2e66: /* original 947d, guest PC 0x0c0b2e66 */
if(!s->budget--) { s->failed_pc=0x0c0b2e66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f64u,2);
goto P_0c0b2e68;
P_0c0b2e68: /* original e04c, guest PC 0x0c0b2e68 */
if(!s->budget--) { s->failed_pc=0x0c0b2e68u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b2e6a;
P_0c0b2e6a: /* original 4e0b, guest PC 0x0c0b2e6a */
if(!s->budget--) { s->failed_pc=0x0c0b2e6au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e6eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e6eu) { target=s->pc; goto dispatch; }
goto P_0c0b2e6e;
P_0c0b2e6c: /* original 05de, guest PC 0x0c0b2e6c */
if(!s->budget--) { s->failed_pc=0x0c0b2e6cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e6e;
P_0c0b2e6e: /* original 947a, guest PC 0x0c0b2e6e */
if(!s->budget--) { s->failed_pc=0x0c0b2e6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f66u,2);
goto P_0c0b2e70;
P_0c0b2e70: /* original e050, guest PC 0x0c0b2e70 */
if(!s->budget--) { s->failed_pc=0x0c0b2e70u; return 0; }
r[0]=0x00000050u;
goto P_0c0b2e72;
P_0c0b2e72: /* original 4e0b, guest PC 0x0c0b2e72 */
if(!s->budget--) { s->failed_pc=0x0c0b2e72u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e76u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e76u) { target=s->pc; goto dispatch; }
goto P_0c0b2e76;
P_0c0b2e74: /* original 05de, guest PC 0x0c0b2e74 */
if(!s->budget--) { s->failed_pc=0x0c0b2e74u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e76;
P_0c0b2e76: /* original 9477, guest PC 0x0c0b2e76 */
if(!s->budget--) { s->failed_pc=0x0c0b2e76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f68u,2);
goto P_0c0b2e78;
P_0c0b2e78: /* original e054, guest PC 0x0c0b2e78 */
if(!s->budget--) { s->failed_pc=0x0c0b2e78u; return 0; }
r[0]=0x00000054u;
goto P_0c0b2e7a;
P_0c0b2e7a: /* original 4e0b, guest PC 0x0c0b2e7a */
if(!s->budget--) { s->failed_pc=0x0c0b2e7au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e7eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e7eu) { target=s->pc; goto dispatch; }
goto P_0c0b2e7e;
P_0c0b2e7c: /* original 05de, guest PC 0x0c0b2e7c */
if(!s->budget--) { s->failed_pc=0x0c0b2e7cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e7e;
P_0c0b2e7e: /* original 9474, guest PC 0x0c0b2e7e */
if(!s->budget--) { s->failed_pc=0x0c0b2e7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f6au,2);
goto P_0c0b2e80;
P_0c0b2e80: /* original e058, guest PC 0x0c0b2e80 */
if(!s->budget--) { s->failed_pc=0x0c0b2e80u; return 0; }
r[0]=0x00000058u;
goto P_0c0b2e82;
P_0c0b2e82: /* original 4e0b, guest PC 0x0c0b2e82 */
if(!s->budget--) { s->failed_pc=0x0c0b2e82u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e86u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e86u) { target=s->pc; goto dispatch; }
goto P_0c0b2e86;
P_0c0b2e84: /* original 05de, guest PC 0x0c0b2e84 */
if(!s->budget--) { s->failed_pc=0x0c0b2e84u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e86;
P_0c0b2e86: /* original 9471, guest PC 0x0c0b2e86 */
if(!s->budget--) { s->failed_pc=0x0c0b2e86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f6cu,2);
goto P_0c0b2e88;
P_0c0b2e88: /* original e05c, guest PC 0x0c0b2e88 */
if(!s->budget--) { s->failed_pc=0x0c0b2e88u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b2e8a;
P_0c0b2e8a: /* original 4e0b, guest PC 0x0c0b2e8a */
if(!s->budget--) { s->failed_pc=0x0c0b2e8au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e8eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e8eu) { target=s->pc; goto dispatch; }
goto P_0c0b2e8e;
P_0c0b2e8c: /* original 05de, guest PC 0x0c0b2e8c */
if(!s->budget--) { s->failed_pc=0x0c0b2e8cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e8e;
P_0c0b2e8e: /* original 946e, guest PC 0x0c0b2e8e */
if(!s->budget--) { s->failed_pc=0x0c0b2e8eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f6eu,2);
goto P_0c0b2e90;
P_0c0b2e90: /* original e060, guest PC 0x0c0b2e90 */
if(!s->budget--) { s->failed_pc=0x0c0b2e90u; return 0; }
r[0]=0x00000060u;
goto P_0c0b2e92;
P_0c0b2e92: /* original 4e0b, guest PC 0x0c0b2e92 */
if(!s->budget--) { s->failed_pc=0x0c0b2e92u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e96u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e96u) { target=s->pc; goto dispatch; }
goto P_0c0b2e96;
P_0c0b2e94: /* original 05de, guest PC 0x0c0b2e94 */
if(!s->budget--) { s->failed_pc=0x0c0b2e94u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e96;
P_0c0b2e96: /* original 946b, guest PC 0x0c0b2e96 */
if(!s->budget--) { s->failed_pc=0x0c0b2e96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f70u,2);
goto P_0c0b2e98;
P_0c0b2e98: /* original e064, guest PC 0x0c0b2e98 */
if(!s->budget--) { s->failed_pc=0x0c0b2e98u; return 0; }
r[0]=0x00000064u;
goto P_0c0b2e9a;
P_0c0b2e9a: /* original 4e0b, guest PC 0x0c0b2e9a */
if(!s->budget--) { s->failed_pc=0x0c0b2e9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2e9eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2e9eu) { target=s->pc; goto dispatch; }
goto P_0c0b2e9e;
P_0c0b2e9c: /* original 05de, guest PC 0x0c0b2e9c */
if(!s->budget--) { s->failed_pc=0x0c0b2e9cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2e9e;
P_0c0b2e9e: /* original 9468, guest PC 0x0c0b2e9e */
if(!s->budget--) { s->failed_pc=0x0c0b2e9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f72u,2);
goto P_0c0b2ea0;
P_0c0b2ea0: /* original e068, guest PC 0x0c0b2ea0 */
if(!s->budget--) { s->failed_pc=0x0c0b2ea0u; return 0; }
r[0]=0x00000068u;
goto P_0c0b2ea2;
P_0c0b2ea2: /* original 4e0b, guest PC 0x0c0b2ea2 */
if(!s->budget--) { s->failed_pc=0x0c0b2ea2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ea6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ea6u) { target=s->pc; goto dispatch; }
goto P_0c0b2ea6;
P_0c0b2ea4: /* original 05de, guest PC 0x0c0b2ea4 */
if(!s->budget--) { s->failed_pc=0x0c0b2ea4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2ea6;
P_0c0b2ea6: /* original 9465, guest PC 0x0c0b2ea6 */
if(!s->budget--) { s->failed_pc=0x0c0b2ea6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f74u,2);
goto P_0c0b2ea8;
P_0c0b2ea8: /* original e06c, guest PC 0x0c0b2ea8 */
if(!s->budget--) { s->failed_pc=0x0c0b2ea8u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b2eaa;
P_0c0b2eaa: /* original 4e0b, guest PC 0x0c0b2eaa */
if(!s->budget--) { s->failed_pc=0x0c0b2eaau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2eaeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2eaeu) { target=s->pc; goto dispatch; }
goto P_0c0b2eae;
P_0c0b2eac: /* original 05de, guest PC 0x0c0b2eac */
if(!s->budget--) { s->failed_pc=0x0c0b2eacu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2eae;
P_0c0b2eae: /* original 9462, guest PC 0x0c0b2eae */
if(!s->budget--) { s->failed_pc=0x0c0b2eaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f76u,2);
goto P_0c0b2eb0;
P_0c0b2eb0: /* original e070, guest PC 0x0c0b2eb0 */
if(!s->budget--) { s->failed_pc=0x0c0b2eb0u; return 0; }
r[0]=0x00000070u;
goto P_0c0b2eb2;
P_0c0b2eb2: /* original 4e0b, guest PC 0x0c0b2eb2 */
if(!s->budget--) { s->failed_pc=0x0c0b2eb2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2eb6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2eb6u) { target=s->pc; goto dispatch; }
goto P_0c0b2eb6;
P_0c0b2eb4: /* original 05de, guest PC 0x0c0b2eb4 */
if(!s->budget--) { s->failed_pc=0x0c0b2eb4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2eb6;
P_0c0b2eb6: /* original 945f, guest PC 0x0c0b2eb6 */
if(!s->budget--) { s->failed_pc=0x0c0b2eb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f78u,2);
goto P_0c0b2eb8;
P_0c0b2eb8: /* original e074, guest PC 0x0c0b2eb8 */
if(!s->budget--) { s->failed_pc=0x0c0b2eb8u; return 0; }
r[0]=0x00000074u;
goto P_0c0b2eba;
P_0c0b2eba: /* original 4e0b, guest PC 0x0c0b2eba */
if(!s->budget--) { s->failed_pc=0x0c0b2ebau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ebeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ebeu) { target=s->pc; goto dispatch; }
goto P_0c0b2ebe;
P_0c0b2ebc: /* original 05de, guest PC 0x0c0b2ebc */
if(!s->budget--) { s->failed_pc=0x0c0b2ebcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2ebe;
P_0c0b2ebe: /* original 945c, guest PC 0x0c0b2ebe */
if(!s->budget--) { s->failed_pc=0x0c0b2ebeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f7au,2);
goto P_0c0b2ec0;
P_0c0b2ec0: /* original e078, guest PC 0x0c0b2ec0 */
if(!s->budget--) { s->failed_pc=0x0c0b2ec0u; return 0; }
r[0]=0x00000078u;
goto P_0c0b2ec2;
P_0c0b2ec2: /* original 4e0b, guest PC 0x0c0b2ec2 */
if(!s->budget--) { s->failed_pc=0x0c0b2ec2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ec6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ec6u) { target=s->pc; goto dispatch; }
goto P_0c0b2ec6;
P_0c0b2ec4: /* original 05de, guest PC 0x0c0b2ec4 */
if(!s->budget--) { s->failed_pc=0x0c0b2ec4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2ec6;
P_0c0b2ec6: /* original 9459, guest PC 0x0c0b2ec6 */
if(!s->budget--) { s->failed_pc=0x0c0b2ec6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f7cu,2);
goto P_0c0b2ec8;
P_0c0b2ec8: /* original e07c, guest PC 0x0c0b2ec8 */
if(!s->budget--) { s->failed_pc=0x0c0b2ec8u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b2eca;
P_0c0b2eca: /* original 4e0b, guest PC 0x0c0b2eca */
if(!s->budget--) { s->failed_pc=0x0c0b2ecau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2eceu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2eceu) { target=s->pc; goto dispatch; }
goto P_0c0b2ece;
P_0c0b2ecc: /* original 05de, guest PC 0x0c0b2ecc */
if(!s->budget--) { s->failed_pc=0x0c0b2eccu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2ece;
P_0c0b2ece: /* original 9457, guest PC 0x0c0b2ece */
if(!s->budget--) { s->failed_pc=0x0c0b2eceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f80u,2);
goto P_0c0b2ed0;
P_0c0b2ed0: /* original 9055, guest PC 0x0c0b2ed0 */
if(!s->budget--) { s->failed_pc=0x0c0b2ed0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f7eu,2);
goto P_0c0b2ed2;
P_0c0b2ed2: /* original 4e0b, guest PC 0x0c0b2ed2 */
if(!s->budget--) { s->failed_pc=0x0c0b2ed2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ed6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ed6u) { target=s->pc; goto dispatch; }
goto P_0c0b2ed6;
P_0c0b2ed4: /* original 05de, guest PC 0x0c0b2ed4 */
if(!s->budget--) { s->failed_pc=0x0c0b2ed4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2ed6;
P_0c0b2ed6: /* original 9554, guest PC 0x0c0b2ed6 */
if(!s->budget--) { s->failed_pc=0x0c0b2ed6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f82u,2);
goto P_0c0b2ed8;
P_0c0b2ed8: /* original 35dc, guest PC 0x0c0b2ed8 */
if(!s->budget--) { s->failed_pc=0x0c0b2ed8u; return 0; }
r[5]+=r[13];
goto P_0c0b2eda;
P_0c0b2eda: /* original 2f52, guest PC 0x0c0b2eda */
if(!s->budget--) { s->failed_pc=0x0c0b2edau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b2edc;
P_0c0b2edc: /* original 9452, guest PC 0x0c0b2edc */
if(!s->budget--) { s->failed_pc=0x0c0b2edcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f84u,2);
goto P_0c0b2ede;
P_0c0b2ede: /* original 4e0b, guest PC 0x0c0b2ede */
if(!s->budget--) { s->failed_pc=0x0c0b2edeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ee2u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ee2u) { target=s->pc; goto dispatch; }
goto P_0c0b2ee2;
P_0c0b2ee0: /* original 6552, guest PC 0x0c0b2ee0 */
if(!s->budget--) { s->failed_pc=0x0c0b2ee0u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2ee2;
P_0c0b2ee2: /* original 9550, guest PC 0x0c0b2ee2 */
if(!s->budget--) { s->failed_pc=0x0c0b2ee2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f86u,2);
goto P_0c0b2ee4;
P_0c0b2ee4: /* original 35dc, guest PC 0x0c0b2ee4 */
if(!s->budget--) { s->failed_pc=0x0c0b2ee4u; return 0; }
r[5]+=r[13];
goto P_0c0b2ee6;
P_0c0b2ee6: /* original 1f51, guest PC 0x0c0b2ee6 */
if(!s->budget--) { s->failed_pc=0x0c0b2ee6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b2ee8;
P_0c0b2ee8: /* original 944e, guest PC 0x0c0b2ee8 */
if(!s->budget--) { s->failed_pc=0x0c0b2ee8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f88u,2);
goto P_0c0b2eea;
P_0c0b2eea: /* original 4e0b, guest PC 0x0c0b2eea */
if(!s->budget--) { s->failed_pc=0x0c0b2eeau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2eeeu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2eeeu) { target=s->pc; goto dispatch; }
goto P_0c0b2eee;
P_0c0b2eec: /* original 6552, guest PC 0x0c0b2eec */
if(!s->budget--) { s->failed_pc=0x0c0b2eecu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2eee;
P_0c0b2eee: /* original 944d, guest PC 0x0c0b2eee */
if(!s->budget--) { s->failed_pc=0x0c0b2eeeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f8cu,2);
goto P_0c0b2ef0;
P_0c0b2ef0: /* original 904b, guest PC 0x0c0b2ef0 */
if(!s->budget--) { s->failed_pc=0x0c0b2ef0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f8au,2);
goto P_0c0b2ef2;
P_0c0b2ef2: /* original 4e0b, guest PC 0x0c0b2ef2 */
if(!s->budget--) { s->failed_pc=0x0c0b2ef2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ef6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ef6u) { target=s->pc; goto dispatch; }
goto P_0c0b2ef6;
P_0c0b2ef4: /* original 05de, guest PC 0x0c0b2ef4 */
if(!s->budget--) { s->failed_pc=0x0c0b2ef4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2ef6;
P_0c0b2ef6: /* original 944b, guest PC 0x0c0b2ef6 */
if(!s->budget--) { s->failed_pc=0x0c0b2ef6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f90u,2);
goto P_0c0b2ef8;
P_0c0b2ef8: /* original 9049, guest PC 0x0c0b2ef8 */
if(!s->budget--) { s->failed_pc=0x0c0b2ef8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f8eu,2);
goto P_0c0b2efa;
P_0c0b2efa: /* original 4e0b, guest PC 0x0c0b2efa */
if(!s->budget--) { s->failed_pc=0x0c0b2efau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2efeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2efeu) { target=s->pc; goto dispatch; }
goto P_0c0b2efe;
P_0c0b2efc: /* original 05de, guest PC 0x0c0b2efc */
if(!s->budget--) { s->failed_pc=0x0c0b2efcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b2efe;
P_0c0b2efe: /* original 9a48, guest PC 0x0c0b2efe */
if(!s->budget--) { s->failed_pc=0x0c0b2efeu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f92u,2);
goto P_0c0b2f00;
P_0c0b2f00: /* original 9448, guest PC 0x0c0b2f00 */
if(!s->budget--) { s->failed_pc=0x0c0b2f00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f94u,2);
goto P_0c0b2f02;
P_0c0b2f02: /* original 3adc, guest PC 0x0c0b2f02 */
if(!s->budget--) { s->failed_pc=0x0c0b2f02u; return 0; }
r[10]+=r[13];
goto P_0c0b2f04;
P_0c0b2f04: /* original 4e0b, guest PC 0x0c0b2f04 */
if(!s->budget--) { s->failed_pc=0x0c0b2f04u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2f08u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2f08u) { target=s->pc; goto dispatch; }
goto P_0c0b2f08;
P_0c0b2f06: /* original 65a2, guest PC 0x0c0b2f06 */
if(!s->budget--) { s->failed_pc=0x0c0b2f06u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2f08;
P_0c0b2f08: /* original 9445, guest PC 0x0c0b2f08 */
if(!s->budget--) { s->failed_pc=0x0c0b2f08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f96u,2);
goto P_0c0b2f0a;
P_0c0b2f0a: /* original 4e0b, guest PC 0x0c0b2f0a */
if(!s->budget--) { s->failed_pc=0x0c0b2f0au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2f0eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2f0eu) { target=s->pc; goto dispatch; }
goto P_0c0b2f0e;
P_0c0b2f0c: /* original 65a2, guest PC 0x0c0b2f0c */
if(!s->budget--) { s->failed_pc=0x0c0b2f0cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2f0e;
P_0c0b2f0e: /* original 9443, guest PC 0x0c0b2f0e */
if(!s->budget--) { s->failed_pc=0x0c0b2f0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f98u,2);
goto P_0c0b2f10;
P_0c0b2f10: /* original 4e0b, guest PC 0x0c0b2f10 */
if(!s->budget--) { s->failed_pc=0x0c0b2f10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2f14u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2f14u) { target=s->pc; goto dispatch; }
goto P_0c0b2f14;
P_0c0b2f12: /* original 65a2, guest PC 0x0c0b2f12 */
if(!s->budget--) { s->failed_pc=0x0c0b2f12u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2f14;
P_0c0b2f14: /* original 9441, guest PC 0x0c0b2f14 */
if(!s->budget--) { s->failed_pc=0x0c0b2f14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f9au,2);
goto P_0c0b2f16;
P_0c0b2f16: /* original 4e0b, guest PC 0x0c0b2f16 */
if(!s->budget--) { s->failed_pc=0x0c0b2f16u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2f1au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2f1au) { target=s->pc; goto dispatch; }
goto P_0c0b2f1a;
P_0c0b2f18: /* original 65a2, guest PC 0x0c0b2f18 */
if(!s->budget--) { s->failed_pc=0x0c0b2f18u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2f1a;
P_0c0b2f1a: /* original 9b3f, guest PC 0x0c0b2f1a */
if(!s->budget--) { s->failed_pc=0x0c0b2f1au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f9cu,2);
goto P_0c0b2f1c;
P_0c0b2f1c: /* original 943f, guest PC 0x0c0b2f1c */
if(!s->budget--) { s->failed_pc=0x0c0b2f1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2f9eu,2);
goto P_0c0b2f1e;
P_0c0b2f1e: /* original 3bdc, guest PC 0x0c0b2f1e */
if(!s->budget--) { s->failed_pc=0x0c0b2f1eu; return 0; }
r[11]+=r[13];
goto P_0c0b2f20;
P_0c0b2f20: /* original 4e0b, guest PC 0x0c0b2f20 */
if(!s->budget--) { s->failed_pc=0x0c0b2f20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2f24u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2f24u) { target=s->pc; goto dispatch; }
goto P_0c0b2f24;
P_0c0b2f22: /* original 65b2, guest PC 0x0c0b2f22 */
if(!s->budget--) { s->failed_pc=0x0c0b2f22u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2f24;
P_0c0b2f24: /* original 943c, guest PC 0x0c0b2f24 */
if(!s->budget--) { s->failed_pc=0x0c0b2f24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2fa0u,2);
goto P_0c0b2f26;
P_0c0b2f26: /* original 4e0b, guest PC 0x0c0b2f26 */
if(!s->budget--) { s->failed_pc=0x0c0b2f26u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2f2au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2f2au) { target=s->pc; goto dispatch; }
goto P_0c0b2f2a;
P_0c0b2f28: /* original 65b2, guest PC 0x0c0b2f28 */
if(!s->budget--) { s->failed_pc=0x0c0b2f28u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2f2a;
P_0c0b2f2a: /* original 943a, guest PC 0x0c0b2f2a */
if(!s->budget--) { s->failed_pc=0x0c0b2f2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2fa2u,2);
goto P_0c0b2f2c;
P_0c0b2f2c: /* original 4e0b, guest PC 0x0c0b2f2c */
if(!s->budget--) { s->failed_pc=0x0c0b2f2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2f30u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2f30u) { target=s->pc; goto dispatch; }
goto P_0c0b2f30;
P_0c0b2f2e: /* original 65b2, guest PC 0x0c0b2f2e */
if(!s->budget--) { s->failed_pc=0x0c0b2f2eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2f30;
P_0c0b2f30: /* original 9438, guest PC 0x0c0b2f30 */
if(!s->budget--) { s->failed_pc=0x0c0b2f30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2fa4u,2);
goto P_0c0b2f32;
P_0c0b2f32: /* original 4e0b, guest PC 0x0c0b2f32 */
if(!s->budget--) { s->failed_pc=0x0c0b2f32u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2f36u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2f36u) { target=s->pc; goto dispatch; }
goto P_0c0b2f36;
P_0c0b2f34: /* original 65b2, guest PC 0x0c0b2f34 */
if(!s->budget--) { s->failed_pc=0x0c0b2f34u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b2f36;
P_0c0b2f36: /* original 9936, guest PC 0x0c0b2f36 */
if(!s->budget--) { s->failed_pc=0x0c0b2f36u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2fa6u,2);
goto P_0c0b2f38;
P_0c0b2f38: /* original 39dc, guest PC 0x0c0b2f38 */
if(!s->budget--) { s->failed_pc=0x0c0b2f38u; return 0; }
r[9]+=r[13];
goto P_0c0b2f3a;
P_0c0b2f3a: /* original a037, guest PC 0x0c0b2f3a */
if(!s->budget--) { s->failed_pc=0x0c0b2f3au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2fac;
P_0c0b2f3c: /* original 6592, guest PC 0x0c0b2f3c */
if(!s->budget--) { s->failed_pc=0x0c0b2f3cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b2f3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b2f3eu; return 0; } return 1;
P_0c0b2fac: /* original 94ab, guest PC 0x0c0b2fac */
if(!s->budget--) { s->failed_pc=0x0c0b2facu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3106u,2);
goto P_0c0b2fae;
P_0c0b2fae: /* original 4e0b, guest PC 0x0c0b2fae */
if(!s->budget--) { s->failed_pc=0x0c0b2faeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fb2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fb2u) { target=s->pc; goto dispatch; }
goto P_0c0b2fb2;
P_0c0b2fb0: /* original 0009, guest PC 0x0c0b2fb0 */
if(!s->budget--) { s->failed_pc=0x0c0b2fb0u; return 0; }
goto P_0c0b2fb2;
P_0c0b2fb2: /* original 94a9, guest PC 0x0c0b2fb2 */
if(!s->budget--) { s->failed_pc=0x0c0b2fb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3108u,2);
goto P_0c0b2fb4;
P_0c0b2fb4: /* original 4e0b, guest PC 0x0c0b2fb4 */
if(!s->budget--) { s->failed_pc=0x0c0b2fb4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fb8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fb8u) { target=s->pc; goto dispatch; }
goto P_0c0b2fb8;
P_0c0b2fb6: /* original 6592, guest PC 0x0c0b2fb6 */
if(!s->budget--) { s->failed_pc=0x0c0b2fb6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2fb8;
P_0c0b2fb8: /* original 94a7, guest PC 0x0c0b2fb8 */
if(!s->budget--) { s->failed_pc=0x0c0b2fb8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b310au,2);
goto P_0c0b2fba;
P_0c0b2fba: /* original 4e0b, guest PC 0x0c0b2fba */
if(!s->budget--) { s->failed_pc=0x0c0b2fbau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fbeu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fbeu) { target=s->pc; goto dispatch; }
goto P_0c0b2fbe;
P_0c0b2fbc: /* original 6592, guest PC 0x0c0b2fbc */
if(!s->budget--) { s->failed_pc=0x0c0b2fbcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2fbe;
P_0c0b2fbe: /* original 94a5, guest PC 0x0c0b2fbe */
if(!s->budget--) { s->failed_pc=0x0c0b2fbeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b310cu,2);
goto P_0c0b2fc0;
P_0c0b2fc0: /* original 4e0b, guest PC 0x0c0b2fc0 */
if(!s->budget--) { s->failed_pc=0x0c0b2fc0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fc4u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fc4u) { target=s->pc; goto dispatch; }
goto P_0c0b2fc4;
P_0c0b2fc2: /* original 6592, guest PC 0x0c0b2fc2 */
if(!s->budget--) { s->failed_pc=0x0c0b2fc2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b2fc4;
P_0c0b2fc4: /* original 9ca3, guest PC 0x0c0b2fc4 */
if(!s->budget--) { s->failed_pc=0x0c0b2fc4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b310eu,2);
goto P_0c0b2fc6;
P_0c0b2fc6: /* original 94a3, guest PC 0x0c0b2fc6 */
if(!s->budget--) { s->failed_pc=0x0c0b2fc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3110u,2);
goto P_0c0b2fc8;
P_0c0b2fc8: /* original 3cdc, guest PC 0x0c0b2fc8 */
if(!s->budget--) { s->failed_pc=0x0c0b2fc8u; return 0; }
r[12]+=r[13];
goto P_0c0b2fca;
P_0c0b2fca: /* original 4e0b, guest PC 0x0c0b2fca */
if(!s->budget--) { s->failed_pc=0x0c0b2fcau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fceu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fceu) { target=s->pc; goto dispatch; }
goto P_0c0b2fce;
P_0c0b2fcc: /* original 65c2, guest PC 0x0c0b2fcc */
if(!s->budget--) { s->failed_pc=0x0c0b2fccu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2fce;
P_0c0b2fce: /* original 94a0, guest PC 0x0c0b2fce */
if(!s->budget--) { s->failed_pc=0x0c0b2fceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3112u,2);
goto P_0c0b2fd0;
P_0c0b2fd0: /* original 4e0b, guest PC 0x0c0b2fd0 */
if(!s->budget--) { s->failed_pc=0x0c0b2fd0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fd4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fd4u) { target=s->pc; goto dispatch; }
goto P_0c0b2fd4;
P_0c0b2fd2: /* original 65c2, guest PC 0x0c0b2fd2 */
if(!s->budget--) { s->failed_pc=0x0c0b2fd2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2fd4;
P_0c0b2fd4: /* original 949e, guest PC 0x0c0b2fd4 */
if(!s->budget--) { s->failed_pc=0x0c0b2fd4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3114u,2);
goto P_0c0b2fd6;
P_0c0b2fd6: /* original 4e0b, guest PC 0x0c0b2fd6 */
if(!s->budget--) { s->failed_pc=0x0c0b2fd6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fdau;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fdau) { target=s->pc; goto dispatch; }
goto P_0c0b2fda;
P_0c0b2fd8: /* original 65c2, guest PC 0x0c0b2fd8 */
if(!s->budget--) { s->failed_pc=0x0c0b2fd8u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2fda;
P_0c0b2fda: /* original 949c, guest PC 0x0c0b2fda */
if(!s->budget--) { s->failed_pc=0x0c0b2fdau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3116u,2);
goto P_0c0b2fdc;
P_0c0b2fdc: /* original 4e0b, guest PC 0x0c0b2fdc */
if(!s->budget--) { s->failed_pc=0x0c0b2fdcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fe0u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fe0u) { target=s->pc; goto dispatch; }
goto P_0c0b2fe0;
P_0c0b2fde: /* original 65c2, guest PC 0x0c0b2fde */
if(!s->budget--) { s->failed_pc=0x0c0b2fdeu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b2fe0;
P_0c0b2fe0: /* original 949a, guest PC 0x0c0b2fe0 */
if(!s->budget--) { s->failed_pc=0x0c0b2fe0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3118u,2);
goto P_0c0b2fe2;
P_0c0b2fe2: /* original 65f2, guest PC 0x0c0b2fe2 */
if(!s->budget--) { s->failed_pc=0x0c0b2fe2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b2fe4;
P_0c0b2fe4: /* original 4e0b, guest PC 0x0c0b2fe4 */
if(!s->budget--) { s->failed_pc=0x0c0b2fe4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2fe8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2fe8u) { target=s->pc; goto dispatch; }
goto P_0c0b2fe8;
P_0c0b2fe6: /* original 6552, guest PC 0x0c0b2fe6 */
if(!s->budget--) { s->failed_pc=0x0c0b2fe6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2fe8;
P_0c0b2fe8: /* original 9497, guest PC 0x0c0b2fe8 */
if(!s->budget--) { s->failed_pc=0x0c0b2fe8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b311au,2);
goto P_0c0b2fea;
P_0c0b2fea: /* original 55f1, guest PC 0x0c0b2fea */
if(!s->budget--) { s->failed_pc=0x0c0b2feau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b2fec;
P_0c0b2fec: /* original 4e0b, guest PC 0x0c0b2fec */
if(!s->budget--) { s->failed_pc=0x0c0b2fecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ff0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ff0u) { target=s->pc; goto dispatch; }
goto P_0c0b2ff0;
P_0c0b2fee: /* original 6552, guest PC 0x0c0b2fee */
if(!s->budget--) { s->failed_pc=0x0c0b2feeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b2ff0;
P_0c0b2ff0: /* original 9494, guest PC 0x0c0b2ff0 */
if(!s->budget--) { s->failed_pc=0x0c0b2ff0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b311cu,2);
goto P_0c0b2ff2;
P_0c0b2ff2: /* original 4e0b, guest PC 0x0c0b2ff2 */
if(!s->budget--) { s->failed_pc=0x0c0b2ff2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ff6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ff6u) { target=s->pc; goto dispatch; }
goto P_0c0b2ff6;
P_0c0b2ff4: /* original 65a2, guest PC 0x0c0b2ff4 */
if(!s->budget--) { s->failed_pc=0x0c0b2ff4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2ff6;
P_0c0b2ff6: /* original 9492, guest PC 0x0c0b2ff6 */
if(!s->budget--) { s->failed_pc=0x0c0b2ff6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b311eu,2);
goto P_0c0b2ff8;
P_0c0b2ff8: /* original 4e0b, guest PC 0x0c0b2ff8 */
if(!s->budget--) { s->failed_pc=0x0c0b2ff8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b2ffcu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2ffcu) { target=s->pc; goto dispatch; }
goto P_0c0b2ffc;
P_0c0b2ffa: /* original 65a2, guest PC 0x0c0b2ffa */
if(!s->budget--) { s->failed_pc=0x0c0b2ffau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b2ffc;
P_0c0b2ffc: /* original 9490, guest PC 0x0c0b2ffc */
if(!s->budget--) { s->failed_pc=0x0c0b2ffcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3120u,2);
goto P_0c0b2ffe;
P_0c0b2ffe: /* original 4e0b, guest PC 0x0c0b2ffe */
if(!s->budget--) { s->failed_pc=0x0c0b2ffeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3002u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3002u) { target=s->pc; goto dispatch; }
goto P_0c0b3002;
P_0c0b3000: /* original 65a2, guest PC 0x0c0b3000 */
if(!s->budget--) { s->failed_pc=0x0c0b3000u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3002;
P_0c0b3002: /* original 948e, guest PC 0x0c0b3002 */
if(!s->budget--) { s->failed_pc=0x0c0b3002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3122u,2);
goto P_0c0b3004;
P_0c0b3004: /* original 4e0b, guest PC 0x0c0b3004 */
if(!s->budget--) { s->failed_pc=0x0c0b3004u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3008u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3008u) { target=s->pc; goto dispatch; }
goto P_0c0b3008;
P_0c0b3006: /* original 65a2, guest PC 0x0c0b3006 */
if(!s->budget--) { s->failed_pc=0x0c0b3006u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3008;
P_0c0b3008: /* original 948c, guest PC 0x0c0b3008 */
if(!s->budget--) { s->failed_pc=0x0c0b3008u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3124u,2);
goto P_0c0b300a;
P_0c0b300a: /* original 4e0b, guest PC 0x0c0b300a */
if(!s->budget--) { s->failed_pc=0x0c0b300au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b300eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b300eu) { target=s->pc; goto dispatch; }
goto P_0c0b300e;
P_0c0b300c: /* original 65b2, guest PC 0x0c0b300c */
if(!s->budget--) { s->failed_pc=0x0c0b300cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b300e;
P_0c0b300e: /* original 948a, guest PC 0x0c0b300e */
if(!s->budget--) { s->failed_pc=0x0c0b300eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3126u,2);
goto P_0c0b3010;
P_0c0b3010: /* original 4e0b, guest PC 0x0c0b3010 */
if(!s->budget--) { s->failed_pc=0x0c0b3010u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3014u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3014u) { target=s->pc; goto dispatch; }
goto P_0c0b3014;
P_0c0b3012: /* original 65b2, guest PC 0x0c0b3012 */
if(!s->budget--) { s->failed_pc=0x0c0b3012u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3014;
P_0c0b3014: /* original 9488, guest PC 0x0c0b3014 */
if(!s->budget--) { s->failed_pc=0x0c0b3014u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3128u,2);
goto P_0c0b3016;
P_0c0b3016: /* original 4e0b, guest PC 0x0c0b3016 */
if(!s->budget--) { s->failed_pc=0x0c0b3016u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b301au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b301au) { target=s->pc; goto dispatch; }
goto P_0c0b301a;
P_0c0b3018: /* original 65b2, guest PC 0x0c0b3018 */
if(!s->budget--) { s->failed_pc=0x0c0b3018u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b301a;
P_0c0b301a: /* original 9486, guest PC 0x0c0b301a */
if(!s->budget--) { s->failed_pc=0x0c0b301au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b312au,2);
goto P_0c0b301c;
P_0c0b301c: /* original 4e0b, guest PC 0x0c0b301c */
if(!s->budget--) { s->failed_pc=0x0c0b301cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3020u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3020u) { target=s->pc; goto dispatch; }
goto P_0c0b3020;
P_0c0b301e: /* original 65b2, guest PC 0x0c0b301e */
if(!s->budget--) { s->failed_pc=0x0c0b301eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3020;
P_0c0b3020: /* original 9484, guest PC 0x0c0b3020 */
if(!s->budget--) { s->failed_pc=0x0c0b3020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b312cu,2);
goto P_0c0b3022;
P_0c0b3022: /* original 4e0b, guest PC 0x0c0b3022 */
if(!s->budget--) { s->failed_pc=0x0c0b3022u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3026u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3026u) { target=s->pc; goto dispatch; }
goto P_0c0b3026;
P_0c0b3024: /* original 6592, guest PC 0x0c0b3024 */
if(!s->budget--) { s->failed_pc=0x0c0b3024u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3026;
P_0c0b3026: /* original 9482, guest PC 0x0c0b3026 */
if(!s->budget--) { s->failed_pc=0x0c0b3026u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b312eu,2);
goto P_0c0b3028;
P_0c0b3028: /* original 4e0b, guest PC 0x0c0b3028 */
if(!s->budget--) { s->failed_pc=0x0c0b3028u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b302cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b302cu) { target=s->pc; goto dispatch; }
goto P_0c0b302c;
P_0c0b302a: /* original 6592, guest PC 0x0c0b302a */
if(!s->budget--) { s->failed_pc=0x0c0b302au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b302c;
P_0c0b302c: /* original 9480, guest PC 0x0c0b302c */
if(!s->budget--) { s->failed_pc=0x0c0b302cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3130u,2);
goto P_0c0b302e;
P_0c0b302e: /* original 4e0b, guest PC 0x0c0b302e */
if(!s->budget--) { s->failed_pc=0x0c0b302eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3032u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3032u) { target=s->pc; goto dispatch; }
goto P_0c0b3032;
P_0c0b3030: /* original 6592, guest PC 0x0c0b3030 */
if(!s->budget--) { s->failed_pc=0x0c0b3030u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3032;
P_0c0b3032: /* original 947e, guest PC 0x0c0b3032 */
if(!s->budget--) { s->failed_pc=0x0c0b3032u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3132u,2);
goto P_0c0b3034;
P_0c0b3034: /* original 4e0b, guest PC 0x0c0b3034 */
if(!s->budget--) { s->failed_pc=0x0c0b3034u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3038u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3038u) { target=s->pc; goto dispatch; }
goto P_0c0b3038;
P_0c0b3036: /* original 6592, guest PC 0x0c0b3036 */
if(!s->budget--) { s->failed_pc=0x0c0b3036u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3038;
P_0c0b3038: /* original 947c, guest PC 0x0c0b3038 */
if(!s->budget--) { s->failed_pc=0x0c0b3038u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3134u,2);
goto P_0c0b303a;
P_0c0b303a: /* original 4e0b, guest PC 0x0c0b303a */
if(!s->budget--) { s->failed_pc=0x0c0b303au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b303eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b303eu) { target=s->pc; goto dispatch; }
goto P_0c0b303e;
P_0c0b303c: /* original 65c2, guest PC 0x0c0b303c */
if(!s->budget--) { s->failed_pc=0x0c0b303cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b303e;
P_0c0b303e: /* original 947a, guest PC 0x0c0b303e */
if(!s->budget--) { s->failed_pc=0x0c0b303eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3136u,2);
goto P_0c0b3040;
P_0c0b3040: /* original 4e0b, guest PC 0x0c0b3040 */
if(!s->budget--) { s->failed_pc=0x0c0b3040u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3044u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3044u) { target=s->pc; goto dispatch; }
goto P_0c0b3044;
P_0c0b3042: /* original 65c2, guest PC 0x0c0b3042 */
if(!s->budget--) { s->failed_pc=0x0c0b3042u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3044;
P_0c0b3044: /* original 9478, guest PC 0x0c0b3044 */
if(!s->budget--) { s->failed_pc=0x0c0b3044u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3138u,2);
goto P_0c0b3046;
P_0c0b3046: /* original 4e0b, guest PC 0x0c0b3046 */
if(!s->budget--) { s->failed_pc=0x0c0b3046u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b304au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b304au) { target=s->pc; goto dispatch; }
goto P_0c0b304a;
P_0c0b3048: /* original 65c2, guest PC 0x0c0b3048 */
if(!s->budget--) { s->failed_pc=0x0c0b3048u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b304a;
P_0c0b304a: /* original 9476, guest PC 0x0c0b304a */
if(!s->budget--) { s->failed_pc=0x0c0b304au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b313au,2);
goto P_0c0b304c;
P_0c0b304c: /* original 4e0b, guest PC 0x0c0b304c */
if(!s->budget--) { s->failed_pc=0x0c0b304cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3050u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3050u) { target=s->pc; goto dispatch; }
goto P_0c0b3050;
P_0c0b304e: /* original 65c2, guest PC 0x0c0b304e */
if(!s->budget--) { s->failed_pc=0x0c0b304eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3050;
P_0c0b3050: /* original 9574, guest PC 0x0c0b3050 */
if(!s->budget--) { s->failed_pc=0x0c0b3050u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b313cu,2);
goto P_0c0b3052;
P_0c0b3052: /* original 35dc, guest PC 0x0c0b3052 */
if(!s->budget--) { s->failed_pc=0x0c0b3052u; return 0; }
r[5]+=r[13];
goto P_0c0b3054;
P_0c0b3054: /* original 2f52, guest PC 0x0c0b3054 */
if(!s->budget--) { s->failed_pc=0x0c0b3054u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3056;
P_0c0b3056: /* original 9472, guest PC 0x0c0b3056 */
if(!s->budget--) { s->failed_pc=0x0c0b3056u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b313eu,2);
goto P_0c0b3058;
P_0c0b3058: /* original 4e0b, guest PC 0x0c0b3058 */
if(!s->budget--) { s->failed_pc=0x0c0b3058u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b305cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b305cu) { target=s->pc; goto dispatch; }
goto P_0c0b305c;
P_0c0b305a: /* original 6552, guest PC 0x0c0b305a */
if(!s->budget--) { s->failed_pc=0x0c0b305au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b305c;
P_0c0b305c: /* original 9470, guest PC 0x0c0b305c */
if(!s->budget--) { s->failed_pc=0x0c0b305cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3140u,2);
goto P_0c0b305e;
P_0c0b305e: /* original 65f2, guest PC 0x0c0b305e */
if(!s->budget--) { s->failed_pc=0x0c0b305eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3060;
P_0c0b3060: /* original 4e0b, guest PC 0x0c0b3060 */
if(!s->budget--) { s->failed_pc=0x0c0b3060u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3064u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3064u) { target=s->pc; goto dispatch; }
goto P_0c0b3064;
P_0c0b3062: /* original 6552, guest PC 0x0c0b3062 */
if(!s->budget--) { s->failed_pc=0x0c0b3062u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3064;
P_0c0b3064: /* original 956d, guest PC 0x0c0b3064 */
if(!s->budget--) { s->failed_pc=0x0c0b3064u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3142u,2);
goto P_0c0b3066;
P_0c0b3066: /* original 35dc, guest PC 0x0c0b3066 */
if(!s->budget--) { s->failed_pc=0x0c0b3066u; return 0; }
r[5]+=r[13];
goto P_0c0b3068;
P_0c0b3068: /* original 2f52, guest PC 0x0c0b3068 */
if(!s->budget--) { s->failed_pc=0x0c0b3068u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b306a;
P_0c0b306a: /* original 946b, guest PC 0x0c0b306a */
if(!s->budget--) { s->failed_pc=0x0c0b306au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3144u,2);
goto P_0c0b306c;
P_0c0b306c: /* original 4e0b, guest PC 0x0c0b306c */
if(!s->budget--) { s->failed_pc=0x0c0b306cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3070u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3070u) { target=s->pc; goto dispatch; }
goto P_0c0b3070;
P_0c0b306e: /* original 6552, guest PC 0x0c0b306e */
if(!s->budget--) { s->failed_pc=0x0c0b306eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3070;
P_0c0b3070: /* original 9469, guest PC 0x0c0b3070 */
if(!s->budget--) { s->failed_pc=0x0c0b3070u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3146u,2);
goto P_0c0b3072;
P_0c0b3072: /* original 65f2, guest PC 0x0c0b3072 */
if(!s->budget--) { s->failed_pc=0x0c0b3072u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3074;
P_0c0b3074: /* original 4e0b, guest PC 0x0c0b3074 */
if(!s->budget--) { s->failed_pc=0x0c0b3074u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3078u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3078u) { target=s->pc; goto dispatch; }
goto P_0c0b3078;
P_0c0b3076: /* original 6552, guest PC 0x0c0b3076 */
if(!s->budget--) { s->failed_pc=0x0c0b3076u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3078;
P_0c0b3078: /* original 9467, guest PC 0x0c0b3078 */
if(!s->budget--) { s->failed_pc=0x0c0b3078u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b314au,2);
goto P_0c0b307a;
P_0c0b307a: /* original 9065, guest PC 0x0c0b307a */
if(!s->budget--) { s->failed_pc=0x0c0b307au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3148u,2);
goto P_0c0b307c;
P_0c0b307c: /* original 4e0b, guest PC 0x0c0b307c */
if(!s->budget--) { s->failed_pc=0x0c0b307cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3080u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3080u) { target=s->pc; goto dispatch; }
goto P_0c0b3080;
P_0c0b307e: /* original 05de, guest PC 0x0c0b307e */
if(!s->budget--) { s->failed_pc=0x0c0b307eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3080;
P_0c0b3080: /* original 9564, guest PC 0x0c0b3080 */
if(!s->budget--) { s->failed_pc=0x0c0b3080u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b314cu,2);
goto P_0c0b3082;
P_0c0b3082: /* original 35dc, guest PC 0x0c0b3082 */
if(!s->budget--) { s->failed_pc=0x0c0b3082u; return 0; }
r[5]+=r[13];
goto P_0c0b3084;
P_0c0b3084: /* original 2f52, guest PC 0x0c0b3084 */
if(!s->budget--) { s->failed_pc=0x0c0b3084u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3086;
P_0c0b3086: /* original 9462, guest PC 0x0c0b3086 */
if(!s->budget--) { s->failed_pc=0x0c0b3086u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b314eu,2);
goto P_0c0b3088;
P_0c0b3088: /* original 4e0b, guest PC 0x0c0b3088 */
if(!s->budget--) { s->failed_pc=0x0c0b3088u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b308cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b308cu) { target=s->pc; goto dispatch; }
goto P_0c0b308c;
P_0c0b308a: /* original 6552, guest PC 0x0c0b308a */
if(!s->budget--) { s->failed_pc=0x0c0b308au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b308c;
P_0c0b308c: /* original 9460, guest PC 0x0c0b308c */
if(!s->budget--) { s->failed_pc=0x0c0b308cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3150u,2);
goto P_0c0b308e;
P_0c0b308e: /* original 65f2, guest PC 0x0c0b308e */
if(!s->budget--) { s->failed_pc=0x0c0b308eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3090;
P_0c0b3090: /* original 4e0b, guest PC 0x0c0b3090 */
if(!s->budget--) { s->failed_pc=0x0c0b3090u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3094u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3094u) { target=s->pc; goto dispatch; }
goto P_0c0b3094;
P_0c0b3092: /* original 6552, guest PC 0x0c0b3092 */
if(!s->budget--) { s->failed_pc=0x0c0b3092u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3094;
P_0c0b3094: /* original 945e, guest PC 0x0c0b3094 */
if(!s->budget--) { s->failed_pc=0x0c0b3094u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3154u,2);
goto P_0c0b3096;
P_0c0b3096: /* original 905c, guest PC 0x0c0b3096 */
if(!s->budget--) { s->failed_pc=0x0c0b3096u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3152u,2);
goto P_0c0b3098;
P_0c0b3098: /* original 4e0b, guest PC 0x0c0b3098 */
if(!s->budget--) { s->failed_pc=0x0c0b3098u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b309cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b309cu) { target=s->pc; goto dispatch; }
goto P_0c0b309c;
P_0c0b309a: /* original 05de, guest PC 0x0c0b309a */
if(!s->budget--) { s->failed_pc=0x0c0b309au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b309c;
P_0c0b309c: /* original 955b, guest PC 0x0c0b309c */
if(!s->budget--) { s->failed_pc=0x0c0b309cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3156u,2);
goto P_0c0b309e;
P_0c0b309e: /* original 35dc, guest PC 0x0c0b309e */
if(!s->budget--) { s->failed_pc=0x0c0b309eu; return 0; }
r[5]+=r[13];
goto P_0c0b30a0;
P_0c0b30a0: /* original 2f52, guest PC 0x0c0b30a0 */
if(!s->budget--) { s->failed_pc=0x0c0b30a0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b30a2;
P_0c0b30a2: /* original 9459, guest PC 0x0c0b30a2 */
if(!s->budget--) { s->failed_pc=0x0c0b30a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3158u,2);
goto P_0c0b30a4;
P_0c0b30a4: /* original 4e0b, guest PC 0x0c0b30a4 */
if(!s->budget--) { s->failed_pc=0x0c0b30a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30a8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30a8u) { target=s->pc; goto dispatch; }
goto P_0c0b30a8;
P_0c0b30a6: /* original 6552, guest PC 0x0c0b30a6 */
if(!s->budget--) { s->failed_pc=0x0c0b30a6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b30a8;
P_0c0b30a8: /* original 9457, guest PC 0x0c0b30a8 */
if(!s->budget--) { s->failed_pc=0x0c0b30a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b315au,2);
goto P_0c0b30aa;
P_0c0b30aa: /* original 65f2, guest PC 0x0c0b30aa */
if(!s->budget--) { s->failed_pc=0x0c0b30aau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b30ac;
P_0c0b30ac: /* original 4e0b, guest PC 0x0c0b30ac */
if(!s->budget--) { s->failed_pc=0x0c0b30acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30b0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30b0u) { target=s->pc; goto dispatch; }
goto P_0c0b30b0;
P_0c0b30ae: /* original 6552, guest PC 0x0c0b30ae */
if(!s->budget--) { s->failed_pc=0x0c0b30aeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b30b0;
P_0c0b30b0: /* original 9455, guest PC 0x0c0b30b0 */
if(!s->budget--) { s->failed_pc=0x0c0b30b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b315eu,2);
goto P_0c0b30b2;
P_0c0b30b2: /* original 9053, guest PC 0x0c0b30b2 */
if(!s->budget--) { s->failed_pc=0x0c0b30b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b315cu,2);
goto P_0c0b30b4;
P_0c0b30b4: /* original 4e0b, guest PC 0x0c0b30b4 */
if(!s->budget--) { s->failed_pc=0x0c0b30b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30b8u) { target=s->pc; goto dispatch; }
goto P_0c0b30b8;
P_0c0b30b6: /* original 05de, guest PC 0x0c0b30b6 */
if(!s->budget--) { s->failed_pc=0x0c0b30b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b30b8;
P_0c0b30b8: /* original 9552, guest PC 0x0c0b30b8 */
if(!s->budget--) { s->failed_pc=0x0c0b30b8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3160u,2);
goto P_0c0b30ba;
P_0c0b30ba: /* original 35dc, guest PC 0x0c0b30ba */
if(!s->budget--) { s->failed_pc=0x0c0b30bau; return 0; }
r[5]+=r[13];
goto P_0c0b30bc;
P_0c0b30bc: /* original 2f52, guest PC 0x0c0b30bc */
if(!s->budget--) { s->failed_pc=0x0c0b30bcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b30be;
P_0c0b30be: /* original 9450, guest PC 0x0c0b30be */
if(!s->budget--) { s->failed_pc=0x0c0b30beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3162u,2);
goto P_0c0b30c0;
P_0c0b30c0: /* original 4e0b, guest PC 0x0c0b30c0 */
if(!s->budget--) { s->failed_pc=0x0c0b30c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30c4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30c4u) { target=s->pc; goto dispatch; }
goto P_0c0b30c4;
P_0c0b30c2: /* original 6552, guest PC 0x0c0b30c2 */
if(!s->budget--) { s->failed_pc=0x0c0b30c2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b30c4;
P_0c0b30c4: /* original 944e, guest PC 0x0c0b30c4 */
if(!s->budget--) { s->failed_pc=0x0c0b30c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3164u,2);
goto P_0c0b30c6;
P_0c0b30c6: /* original 65f2, guest PC 0x0c0b30c6 */
if(!s->budget--) { s->failed_pc=0x0c0b30c6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b30c8;
P_0c0b30c8: /* original 4e0b, guest PC 0x0c0b30c8 */
if(!s->budget--) { s->failed_pc=0x0c0b30c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30ccu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30ccu) { target=s->pc; goto dispatch; }
goto P_0c0b30cc;
P_0c0b30ca: /* original 6552, guest PC 0x0c0b30ca */
if(!s->budget--) { s->failed_pc=0x0c0b30cau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b30cc;
P_0c0b30cc: /* original 954b, guest PC 0x0c0b30cc */
if(!s->budget--) { s->failed_pc=0x0c0b30ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3166u,2);
goto P_0c0b30ce;
P_0c0b30ce: /* original 35dc, guest PC 0x0c0b30ce */
if(!s->budget--) { s->failed_pc=0x0c0b30ceu; return 0; }
r[5]+=r[13];
goto P_0c0b30d0;
P_0c0b30d0: /* original 2f52, guest PC 0x0c0b30d0 */
if(!s->budget--) { s->failed_pc=0x0c0b30d0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b30d2;
P_0c0b30d2: /* original 9449, guest PC 0x0c0b30d2 */
if(!s->budget--) { s->failed_pc=0x0c0b30d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3168u,2);
goto P_0c0b30d4;
P_0c0b30d4: /* original 4e0b, guest PC 0x0c0b30d4 */
if(!s->budget--) { s->failed_pc=0x0c0b30d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30d8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30d8u) { target=s->pc; goto dispatch; }
goto P_0c0b30d8;
P_0c0b30d6: /* original 6552, guest PC 0x0c0b30d6 */
if(!s->budget--) { s->failed_pc=0x0c0b30d6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b30d8;
P_0c0b30d8: /* original 9447, guest PC 0x0c0b30d8 */
if(!s->budget--) { s->failed_pc=0x0c0b30d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b316au,2);
goto P_0c0b30da;
P_0c0b30da: /* original 65f2, guest PC 0x0c0b30da */
if(!s->budget--) { s->failed_pc=0x0c0b30dau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b30dc;
P_0c0b30dc: /* original 4e0b, guest PC 0x0c0b30dc */
if(!s->budget--) { s->failed_pc=0x0c0b30dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30e0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30e0u) { target=s->pc; goto dispatch; }
goto P_0c0b30e0;
P_0c0b30de: /* original 6552, guest PC 0x0c0b30de */
if(!s->budget--) { s->failed_pc=0x0c0b30deu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b30e0;
P_0c0b30e0: /* original 9445, guest PC 0x0c0b30e0 */
if(!s->budget--) { s->failed_pc=0x0c0b30e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b316eu,2);
goto P_0c0b30e2;
P_0c0b30e2: /* original 9043, guest PC 0x0c0b30e2 */
if(!s->budget--) { s->failed_pc=0x0c0b30e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b316cu,2);
goto P_0c0b30e4;
P_0c0b30e4: /* original 4e0b, guest PC 0x0c0b30e4 */
if(!s->budget--) { s->failed_pc=0x0c0b30e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30e8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30e8u) { target=s->pc; goto dispatch; }
goto P_0c0b30e8;
P_0c0b30e6: /* original 05de, guest PC 0x0c0b30e6 */
if(!s->budget--) { s->failed_pc=0x0c0b30e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b30e8;
P_0c0b30e8: /* original 9443, guest PC 0x0c0b30e8 */
if(!s->budget--) { s->failed_pc=0x0c0b30e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3172u,2);
goto P_0c0b30ea;
P_0c0b30ea: /* original 9041, guest PC 0x0c0b30ea */
if(!s->budget--) { s->failed_pc=0x0c0b30eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3170u,2);
goto P_0c0b30ec;
P_0c0b30ec: /* original 4e0b, guest PC 0x0c0b30ec */
if(!s->budget--) { s->failed_pc=0x0c0b30ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30f0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30f0u) { target=s->pc; goto dispatch; }
goto P_0c0b30f0;
P_0c0b30ee: /* original 05de, guest PC 0x0c0b30ee */
if(!s->budget--) { s->failed_pc=0x0c0b30eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b30f0;
P_0c0b30f0: /* original 9441, guest PC 0x0c0b30f0 */
if(!s->budget--) { s->failed_pc=0x0c0b30f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3176u,2);
goto P_0c0b30f2;
P_0c0b30f2: /* original 903f, guest PC 0x0c0b30f2 */
if(!s->budget--) { s->failed_pc=0x0c0b30f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3174u,2);
goto P_0c0b30f4;
P_0c0b30f4: /* original 4e0b, guest PC 0x0c0b30f4 */
if(!s->budget--) { s->failed_pc=0x0c0b30f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b30f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b30f8u) { target=s->pc; goto dispatch; }
goto P_0c0b30f8;
P_0c0b30f6: /* original 05de, guest PC 0x0c0b30f6 */
if(!s->budget--) { s->failed_pc=0x0c0b30f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b30f8;
P_0c0b30f8: /* original 943f, guest PC 0x0c0b30f8 */
if(!s->budget--) { s->failed_pc=0x0c0b30f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b317au,2);
goto P_0c0b30fa;
P_0c0b30fa: /* original 903d, guest PC 0x0c0b30fa */
if(!s->budget--) { s->failed_pc=0x0c0b30fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3178u,2);
goto P_0c0b30fc;
P_0c0b30fc: /* original 4e0b, guest PC 0x0c0b30fc */
if(!s->budget--) { s->failed_pc=0x0c0b30fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3100u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3100u) { target=s->pc; goto dispatch; }
goto P_0c0b3100;
P_0c0b30fe: /* original 05de, guest PC 0x0c0b30fe */
if(!s->budget--) { s->failed_pc=0x0c0b30feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3100;
P_0c0b3100: /* original 903c, guest PC 0x0c0b3100 */
if(!s->budget--) { s->failed_pc=0x0c0b3100u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b317cu,2);
goto P_0c0b3102;
P_0c0b3102: /* original a03c, guest PC 0x0c0b3102 */
if(!s->budget--) { s->failed_pc=0x0c0b3102u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b317e;
P_0c0b3104: /* original 05de, guest PC 0x0c0b3104 */
if(!s->budget--) { s->failed_pc=0x0c0b3104u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b3106u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b3106u; return 0; } return 1;
P_0c0b317e: /* original 947a, guest PC 0x0c0b317e */
if(!s->budget--) { s->failed_pc=0x0c0b317eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3276u,2);
goto P_0c0b3180;
P_0c0b3180: /* original 4e0b, guest PC 0x0c0b3180 */
if(!s->budget--) { s->failed_pc=0x0c0b3180u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3184u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3184u) { target=s->pc; goto dispatch; }
goto P_0c0b3184;
P_0c0b3182: /* original 0009, guest PC 0x0c0b3182 */
if(!s->budget--) { s->failed_pc=0x0c0b3182u; return 0; }
goto P_0c0b3184;
P_0c0b3184: /* original 9479, guest PC 0x0c0b3184 */
if(!s->budget--) { s->failed_pc=0x0c0b3184u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b327au,2);
goto P_0c0b3186;
P_0c0b3186: /* original 9077, guest PC 0x0c0b3186 */
if(!s->budget--) { s->failed_pc=0x0c0b3186u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3278u,2);
goto P_0c0b3188;
P_0c0b3188: /* original 4e0b, guest PC 0x0c0b3188 */
if(!s->budget--) { s->failed_pc=0x0c0b3188u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b318cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b318cu) { target=s->pc; goto dispatch; }
goto P_0c0b318c;
P_0c0b318a: /* original 05de, guest PC 0x0c0b318a */
if(!s->budget--) { s->failed_pc=0x0c0b318au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b318c;
P_0c0b318c: /* original 9477, guest PC 0x0c0b318c */
if(!s->budget--) { s->failed_pc=0x0c0b318cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b327eu,2);
goto P_0c0b318e;
P_0c0b318e: /* original 9075, guest PC 0x0c0b318e */
if(!s->budget--) { s->failed_pc=0x0c0b318eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b327cu,2);
goto P_0c0b3190;
P_0c0b3190: /* original 4e0b, guest PC 0x0c0b3190 */
if(!s->budget--) { s->failed_pc=0x0c0b3190u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3194u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3194u) { target=s->pc; goto dispatch; }
goto P_0c0b3194;
P_0c0b3192: /* original 05de, guest PC 0x0c0b3192 */
if(!s->budget--) { s->failed_pc=0x0c0b3192u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3194;
P_0c0b3194: /* original 9475, guest PC 0x0c0b3194 */
if(!s->budget--) { s->failed_pc=0x0c0b3194u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3282u,2);
goto P_0c0b3196;
P_0c0b3196: /* original 9073, guest PC 0x0c0b3196 */
if(!s->budget--) { s->failed_pc=0x0c0b3196u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3280u,2);
goto P_0c0b3198;
P_0c0b3198: /* original 4e0b, guest PC 0x0c0b3198 */
if(!s->budget--) { s->failed_pc=0x0c0b3198u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b319cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b319cu) { target=s->pc; goto dispatch; }
goto P_0c0b319c;
P_0c0b319a: /* original 05de, guest PC 0x0c0b319a */
if(!s->budget--) { s->failed_pc=0x0c0b319au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b319c;
P_0c0b319c: /* original 9473, guest PC 0x0c0b319c */
if(!s->budget--) { s->failed_pc=0x0c0b319cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3286u,2);
goto P_0c0b319e;
P_0c0b319e: /* original 9071, guest PC 0x0c0b319e */
if(!s->budget--) { s->failed_pc=0x0c0b319eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3284u,2);
goto P_0c0b31a0;
P_0c0b31a0: /* original 4e0b, guest PC 0x0c0b31a0 */
if(!s->budget--) { s->failed_pc=0x0c0b31a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31a4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31a4u) { target=s->pc; goto dispatch; }
goto P_0c0b31a4;
P_0c0b31a2: /* original 05de, guest PC 0x0c0b31a2 */
if(!s->budget--) { s->failed_pc=0x0c0b31a2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31a4;
P_0c0b31a4: /* original 9471, guest PC 0x0c0b31a4 */
if(!s->budget--) { s->failed_pc=0x0c0b31a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b328au,2);
goto P_0c0b31a6;
P_0c0b31a6: /* original 906f, guest PC 0x0c0b31a6 */
if(!s->budget--) { s->failed_pc=0x0c0b31a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3288u,2);
goto P_0c0b31a8;
P_0c0b31a8: /* original 4e0b, guest PC 0x0c0b31a8 */
if(!s->budget--) { s->failed_pc=0x0c0b31a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31acu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31acu) { target=s->pc; goto dispatch; }
goto P_0c0b31ac;
P_0c0b31aa: /* original 05de, guest PC 0x0c0b31aa */
if(!s->budget--) { s->failed_pc=0x0c0b31aau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31ac;
P_0c0b31ac: /* original 946f, guest PC 0x0c0b31ac */
if(!s->budget--) { s->failed_pc=0x0c0b31acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b328eu,2);
goto P_0c0b31ae;
P_0c0b31ae: /* original 906d, guest PC 0x0c0b31ae */
if(!s->budget--) { s->failed_pc=0x0c0b31aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b328cu,2);
goto P_0c0b31b0;
P_0c0b31b0: /* original 4e0b, guest PC 0x0c0b31b0 */
if(!s->budget--) { s->failed_pc=0x0c0b31b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31b4u) { target=s->pc; goto dispatch; }
goto P_0c0b31b4;
P_0c0b31b2: /* original 05de, guest PC 0x0c0b31b2 */
if(!s->budget--) { s->failed_pc=0x0c0b31b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31b4;
P_0c0b31b4: /* original 946d, guest PC 0x0c0b31b4 */
if(!s->budget--) { s->failed_pc=0x0c0b31b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3292u,2);
goto P_0c0b31b6;
P_0c0b31b6: /* original 906b, guest PC 0x0c0b31b6 */
if(!s->budget--) { s->failed_pc=0x0c0b31b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3290u,2);
goto P_0c0b31b8;
P_0c0b31b8: /* original 4e0b, guest PC 0x0c0b31b8 */
if(!s->budget--) { s->failed_pc=0x0c0b31b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31bcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31bcu) { target=s->pc; goto dispatch; }
goto P_0c0b31bc;
P_0c0b31ba: /* original 05de, guest PC 0x0c0b31ba */
if(!s->budget--) { s->failed_pc=0x0c0b31bau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31bc;
P_0c0b31bc: /* original 9468, guest PC 0x0c0b31bc */
if(!s->budget--) { s->failed_pc=0x0c0b31bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3290u,2);
goto P_0c0b31be;
P_0c0b31be: /* original 9069, guest PC 0x0c0b31be */
if(!s->budget--) { s->failed_pc=0x0c0b31beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3294u,2);
goto P_0c0b31c0;
P_0c0b31c0: /* original 4e0b, guest PC 0x0c0b31c0 */
if(!s->budget--) { s->failed_pc=0x0c0b31c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31c4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31c4u) { target=s->pc; goto dispatch; }
goto P_0c0b31c4;
P_0c0b31c2: /* original 05de, guest PC 0x0c0b31c2 */
if(!s->budget--) { s->failed_pc=0x0c0b31c2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31c4;
P_0c0b31c4: /* original 9468, guest PC 0x0c0b31c4 */
if(!s->budget--) { s->failed_pc=0x0c0b31c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3298u,2);
goto P_0c0b31c6;
P_0c0b31c6: /* original 9066, guest PC 0x0c0b31c6 */
if(!s->budget--) { s->failed_pc=0x0c0b31c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3296u,2);
goto P_0c0b31c8;
P_0c0b31c8: /* original 4e0b, guest PC 0x0c0b31c8 */
if(!s->budget--) { s->failed_pc=0x0c0b31c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31ccu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31ccu) { target=s->pc; goto dispatch; }
goto P_0c0b31cc;
P_0c0b31ca: /* original 05de, guest PC 0x0c0b31ca */
if(!s->budget--) { s->failed_pc=0x0c0b31cau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31cc;
P_0c0b31cc: /* original 9466, guest PC 0x0c0b31cc */
if(!s->budget--) { s->failed_pc=0x0c0b31ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b329cu,2);
goto P_0c0b31ce;
P_0c0b31ce: /* original 9064, guest PC 0x0c0b31ce */
if(!s->budget--) { s->failed_pc=0x0c0b31ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b329au,2);
goto P_0c0b31d0;
P_0c0b31d0: /* original 4e0b, guest PC 0x0c0b31d0 */
if(!s->budget--) { s->failed_pc=0x0c0b31d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31d4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31d4u) { target=s->pc; goto dispatch; }
goto P_0c0b31d4;
P_0c0b31d2: /* original 05de, guest PC 0x0c0b31d2 */
if(!s->budget--) { s->failed_pc=0x0c0b31d2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31d4;
P_0c0b31d4: /* original 9464, guest PC 0x0c0b31d4 */
if(!s->budget--) { s->failed_pc=0x0c0b31d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32a0u,2);
goto P_0c0b31d6;
P_0c0b31d6: /* original 9062, guest PC 0x0c0b31d6 */
if(!s->budget--) { s->failed_pc=0x0c0b31d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b329eu,2);
goto P_0c0b31d8;
P_0c0b31d8: /* original 4e0b, guest PC 0x0c0b31d8 */
if(!s->budget--) { s->failed_pc=0x0c0b31d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31dcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31dcu) { target=s->pc; goto dispatch; }
goto P_0c0b31dc;
P_0c0b31da: /* original 05de, guest PC 0x0c0b31da */
if(!s->budget--) { s->failed_pc=0x0c0b31dau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31dc;
P_0c0b31dc: /* original 9462, guest PC 0x0c0b31dc */
if(!s->budget--) { s->failed_pc=0x0c0b31dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32a4u,2);
goto P_0c0b31de;
P_0c0b31de: /* original 9060, guest PC 0x0c0b31de */
if(!s->budget--) { s->failed_pc=0x0c0b31deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32a2u,2);
goto P_0c0b31e0;
P_0c0b31e0: /* original 4e0b, guest PC 0x0c0b31e0 */
if(!s->budget--) { s->failed_pc=0x0c0b31e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31e4u) { target=s->pc; goto dispatch; }
goto P_0c0b31e4;
P_0c0b31e2: /* original 05de, guest PC 0x0c0b31e2 */
if(!s->budget--) { s->failed_pc=0x0c0b31e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31e4;
P_0c0b31e4: /* original 9448, guest PC 0x0c0b31e4 */
if(!s->budget--) { s->failed_pc=0x0c0b31e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3278u,2);
goto P_0c0b31e6;
P_0c0b31e6: /* original 905e, guest PC 0x0c0b31e6 */
if(!s->budget--) { s->failed_pc=0x0c0b31e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32a6u,2);
goto P_0c0b31e8;
P_0c0b31e8: /* original 4e0b, guest PC 0x0c0b31e8 */
if(!s->budget--) { s->failed_pc=0x0c0b31e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31ecu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31ecu) { target=s->pc; goto dispatch; }
goto P_0c0b31ec;
P_0c0b31ea: /* original 05de, guest PC 0x0c0b31ea */
if(!s->budget--) { s->failed_pc=0x0c0b31eau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31ec;
P_0c0b31ec: /* original 945d, guest PC 0x0c0b31ec */
if(!s->budget--) { s->failed_pc=0x0c0b31ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32aau,2);
goto P_0c0b31ee;
P_0c0b31ee: /* original 905b, guest PC 0x0c0b31ee */
if(!s->budget--) { s->failed_pc=0x0c0b31eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32a8u,2);
goto P_0c0b31f0;
P_0c0b31f0: /* original 4e0b, guest PC 0x0c0b31f0 */
if(!s->budget--) { s->failed_pc=0x0c0b31f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31f4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31f4u) { target=s->pc; goto dispatch; }
goto P_0c0b31f4;
P_0c0b31f2: /* original 05de, guest PC 0x0c0b31f2 */
if(!s->budget--) { s->failed_pc=0x0c0b31f2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31f4;
P_0c0b31f4: /* original 945b, guest PC 0x0c0b31f4 */
if(!s->budget--) { s->failed_pc=0x0c0b31f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32aeu,2);
goto P_0c0b31f6;
P_0c0b31f6: /* original 9059, guest PC 0x0c0b31f6 */
if(!s->budget--) { s->failed_pc=0x0c0b31f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32acu,2);
goto P_0c0b31f8;
P_0c0b31f8: /* original 4e0b, guest PC 0x0c0b31f8 */
if(!s->budget--) { s->failed_pc=0x0c0b31f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b31fcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b31fcu) { target=s->pc; goto dispatch; }
goto P_0c0b31fc;
P_0c0b31fa: /* original 05de, guest PC 0x0c0b31fa */
if(!s->budget--) { s->failed_pc=0x0c0b31fau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b31fc;
P_0c0b31fc: /* original 9459, guest PC 0x0c0b31fc */
if(!s->budget--) { s->failed_pc=0x0c0b31fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32b2u,2);
goto P_0c0b31fe;
P_0c0b31fe: /* original 9057, guest PC 0x0c0b31fe */
if(!s->budget--) { s->failed_pc=0x0c0b31feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32b0u,2);
goto P_0c0b3200;
P_0c0b3200: /* original 4e0b, guest PC 0x0c0b3200 */
if(!s->budget--) { s->failed_pc=0x0c0b3200u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3204u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3204u) { target=s->pc; goto dispatch; }
goto P_0c0b3204;
P_0c0b3202: /* original 05de, guest PC 0x0c0b3202 */
if(!s->budget--) { s->failed_pc=0x0c0b3202u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3204;
P_0c0b3204: /* original 9457, guest PC 0x0c0b3204 */
if(!s->budget--) { s->failed_pc=0x0c0b3204u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32b6u,2);
goto P_0c0b3206;
P_0c0b3206: /* original 9055, guest PC 0x0c0b3206 */
if(!s->budget--) { s->failed_pc=0x0c0b3206u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32b4u,2);
goto P_0c0b3208;
P_0c0b3208: /* original 4e0b, guest PC 0x0c0b3208 */
if(!s->budget--) { s->failed_pc=0x0c0b3208u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b320cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b320cu) { target=s->pc; goto dispatch; }
goto P_0c0b320c;
P_0c0b320a: /* original 05de, guest PC 0x0c0b320a */
if(!s->budget--) { s->failed_pc=0x0c0b320au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b320c;
P_0c0b320c: /* original 9455, guest PC 0x0c0b320c */
if(!s->budget--) { s->failed_pc=0x0c0b320cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32bau,2);
goto P_0c0b320e;
P_0c0b320e: /* original 9053, guest PC 0x0c0b320e */
if(!s->budget--) { s->failed_pc=0x0c0b320eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32b8u,2);
goto P_0c0b3210;
P_0c0b3210: /* original 4e0b, guest PC 0x0c0b3210 */
if(!s->budget--) { s->failed_pc=0x0c0b3210u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3214u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3214u) { target=s->pc; goto dispatch; }
goto P_0c0b3214;
P_0c0b3212: /* original 05de, guest PC 0x0c0b3212 */
if(!s->budget--) { s->failed_pc=0x0c0b3212u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3214;
P_0c0b3214: /* original 9453, guest PC 0x0c0b3214 */
if(!s->budget--) { s->failed_pc=0x0c0b3214u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32beu,2);
goto P_0c0b3216;
P_0c0b3216: /* original 9051, guest PC 0x0c0b3216 */
if(!s->budget--) { s->failed_pc=0x0c0b3216u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32bcu,2);
goto P_0c0b3218;
P_0c0b3218: /* original 4e0b, guest PC 0x0c0b3218 */
if(!s->budget--) { s->failed_pc=0x0c0b3218u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b321cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b321cu) { target=s->pc; goto dispatch; }
goto P_0c0b321c;
P_0c0b321a: /* original 05de, guest PC 0x0c0b321a */
if(!s->budget--) { s->failed_pc=0x0c0b321au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b321c;
P_0c0b321c: /* original 9451, guest PC 0x0c0b321c */
if(!s->budget--) { s->failed_pc=0x0c0b321cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32c2u,2);
goto P_0c0b321e;
P_0c0b321e: /* original 904f, guest PC 0x0c0b321e */
if(!s->budget--) { s->failed_pc=0x0c0b321eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32c0u,2);
goto P_0c0b3220;
P_0c0b3220: /* original 4e0b, guest PC 0x0c0b3220 */
if(!s->budget--) { s->failed_pc=0x0c0b3220u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3224u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3224u) { target=s->pc; goto dispatch; }
goto P_0c0b3224;
P_0c0b3222: /* original 05de, guest PC 0x0c0b3222 */
if(!s->budget--) { s->failed_pc=0x0c0b3222u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3224;
P_0c0b3224: /* original 944f, guest PC 0x0c0b3224 */
if(!s->budget--) { s->failed_pc=0x0c0b3224u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32c6u,2);
goto P_0c0b3226;
P_0c0b3226: /* original 904d, guest PC 0x0c0b3226 */
if(!s->budget--) { s->failed_pc=0x0c0b3226u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32c4u,2);
goto P_0c0b3228;
P_0c0b3228: /* original 4e0b, guest PC 0x0c0b3228 */
if(!s->budget--) { s->failed_pc=0x0c0b3228u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b322cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b322cu) { target=s->pc; goto dispatch; }
goto P_0c0b322c;
P_0c0b322a: /* original 05de, guest PC 0x0c0b322a */
if(!s->budget--) { s->failed_pc=0x0c0b322au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b322c;
P_0c0b322c: /* original 944d, guest PC 0x0c0b322c */
if(!s->budget--) { s->failed_pc=0x0c0b322cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32cau,2);
goto P_0c0b322e;
P_0c0b322e: /* original 904b, guest PC 0x0c0b322e */
if(!s->budget--) { s->failed_pc=0x0c0b322eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32c8u,2);
goto P_0c0b3230;
P_0c0b3230: /* original 4e0b, guest PC 0x0c0b3230 */
if(!s->budget--) { s->failed_pc=0x0c0b3230u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3234u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3234u) { target=s->pc; goto dispatch; }
goto P_0c0b3234;
P_0c0b3232: /* original 05de, guest PC 0x0c0b3232 */
if(!s->budget--) { s->failed_pc=0x0c0b3232u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3234;
P_0c0b3234: /* original 944b, guest PC 0x0c0b3234 */
if(!s->budget--) { s->failed_pc=0x0c0b3234u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32ceu,2);
goto P_0c0b3236;
P_0c0b3236: /* original 9049, guest PC 0x0c0b3236 */
if(!s->budget--) { s->failed_pc=0x0c0b3236u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32ccu,2);
goto P_0c0b3238;
P_0c0b3238: /* original 4e0b, guest PC 0x0c0b3238 */
if(!s->budget--) { s->failed_pc=0x0c0b3238u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b323cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b323cu) { target=s->pc; goto dispatch; }
goto P_0c0b323c;
P_0c0b323a: /* original 05de, guest PC 0x0c0b323a */
if(!s->budget--) { s->failed_pc=0x0c0b323au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b323c;
P_0c0b323c: /* original 9449, guest PC 0x0c0b323c */
if(!s->budget--) { s->failed_pc=0x0c0b323cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32d2u,2);
goto P_0c0b323e;
P_0c0b323e: /* original 9047, guest PC 0x0c0b323e */
if(!s->budget--) { s->failed_pc=0x0c0b323eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32d0u,2);
goto P_0c0b3240;
P_0c0b3240: /* original 4e0b, guest PC 0x0c0b3240 */
if(!s->budget--) { s->failed_pc=0x0c0b3240u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3244u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3244u) { target=s->pc; goto dispatch; }
goto P_0c0b3244;
P_0c0b3242: /* original 05de, guest PC 0x0c0b3242 */
if(!s->budget--) { s->failed_pc=0x0c0b3242u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3244;
P_0c0b3244: /* original 9447, guest PC 0x0c0b3244 */
if(!s->budget--) { s->failed_pc=0x0c0b3244u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32d6u,2);
goto P_0c0b3246;
P_0c0b3246: /* original 9045, guest PC 0x0c0b3246 */
if(!s->budget--) { s->failed_pc=0x0c0b3246u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32d4u,2);
goto P_0c0b3248;
P_0c0b3248: /* original 4e0b, guest PC 0x0c0b3248 */
if(!s->budget--) { s->failed_pc=0x0c0b3248u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b324cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b324cu) { target=s->pc; goto dispatch; }
goto P_0c0b324c;
P_0c0b324a: /* original 05de, guest PC 0x0c0b324a */
if(!s->budget--) { s->failed_pc=0x0c0b324au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b324c;
P_0c0b324c: /* original 9445, guest PC 0x0c0b324c */
if(!s->budget--) { s->failed_pc=0x0c0b324cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32dau,2);
goto P_0c0b324e;
P_0c0b324e: /* original 9043, guest PC 0x0c0b324e */
if(!s->budget--) { s->failed_pc=0x0c0b324eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32d8u,2);
goto P_0c0b3250;
P_0c0b3250: /* original 4e0b, guest PC 0x0c0b3250 */
if(!s->budget--) { s->failed_pc=0x0c0b3250u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3254u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3254u) { target=s->pc; goto dispatch; }
goto P_0c0b3254;
P_0c0b3252: /* original 05de, guest PC 0x0c0b3252 */
if(!s->budget--) { s->failed_pc=0x0c0b3252u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3254;
P_0c0b3254: /* original 9443, guest PC 0x0c0b3254 */
if(!s->budget--) { s->failed_pc=0x0c0b3254u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32deu,2);
goto P_0c0b3256;
P_0c0b3256: /* original 9041, guest PC 0x0c0b3256 */
if(!s->budget--) { s->failed_pc=0x0c0b3256u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32dcu,2);
goto P_0c0b3258;
P_0c0b3258: /* original 4e0b, guest PC 0x0c0b3258 */
if(!s->budget--) { s->failed_pc=0x0c0b3258u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b325cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b325cu) { target=s->pc; goto dispatch; }
goto P_0c0b325c;
P_0c0b325a: /* original 05de, guest PC 0x0c0b325a */
if(!s->budget--) { s->failed_pc=0x0c0b325au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b325c;
P_0c0b325c: /* original 9441, guest PC 0x0c0b325c */
if(!s->budget--) { s->failed_pc=0x0c0b325cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32e2u,2);
goto P_0c0b325e;
P_0c0b325e: /* original 903f, guest PC 0x0c0b325e */
if(!s->budget--) { s->failed_pc=0x0c0b325eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b32e0u,2);
goto P_0c0b3260;
P_0c0b3260: /* original 4e0b, guest PC 0x0c0b3260 */
if(!s->budget--) { s->failed_pc=0x0c0b3260u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3264u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3264u) { target=s->pc; goto dispatch; }
goto P_0c0b3264;
P_0c0b3262: /* original 05de, guest PC 0x0c0b3262 */
if(!s->budget--) { s->failed_pc=0x0c0b3262u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3264;
P_0c0b3264: /* original 7f08, guest PC 0x0c0b3264 */
if(!s->budget--) { s->failed_pc=0x0c0b3264u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b3266;
P_0c0b3266: /* original 4f26, guest PC 0x0c0b3266 */
if(!s->budget--) { s->failed_pc=0x0c0b3266u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b3268;
P_0c0b3268: /* original 69f6, guest PC 0x0c0b3268 */
if(!s->budget--) { s->failed_pc=0x0c0b3268u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b326a;
P_0c0b326a: /* original 6af6, guest PC 0x0c0b326a */
if(!s->budget--) { s->failed_pc=0x0c0b326au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b326c;
P_0c0b326c: /* original 6bf6, guest PC 0x0c0b326c */
if(!s->budget--) { s->failed_pc=0x0c0b326cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b326e;
P_0c0b326e: /* original 6cf6, guest PC 0x0c0b326e */
if(!s->budget--) { s->failed_pc=0x0c0b326eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b3270;
P_0c0b3270: /* original 6df6, guest PC 0x0c0b3270 */
if(!s->budget--) { s->failed_pc=0x0c0b3270u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b3272;
P_0c0b3272: /* original 000b, guest PC 0x0c0b3272 */
if(!s->budget--) { s->failed_pc=0x0c0b3272u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b3274: /* original 6ef6, guest PC 0x0c0b3274 */
if(!s->budget--) { s->failed_pc=0x0c0b3274u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b3276u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b3276u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
