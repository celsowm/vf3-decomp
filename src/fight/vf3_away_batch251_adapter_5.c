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
int vf3_away_batch251_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c7de8u: goto P_0c0c7de8;
case 0x0c0c7deau: goto P_0c0c7dea;
case 0x0c0c7decu: goto P_0c0c7dec;
case 0x0c0c7deeu: goto P_0c0c7dee;
case 0x0c0c7df0u: goto P_0c0c7df0;
case 0x0c0c7df2u: goto P_0c0c7df2;
case 0x0c0c7df4u: goto P_0c0c7df4;
case 0x0c0c7df6u: goto P_0c0c7df6;
case 0x0c0c7df8u: goto P_0c0c7df8;
case 0x0c0c7dfau: goto P_0c0c7dfa;
case 0x0c0c7dfcu: goto P_0c0c7dfc;
case 0x0c0c7dfeu: goto P_0c0c7dfe;
case 0x0c0c7e1cu: goto P_0c0c7e1c;
case 0x0c0c7e1eu: goto P_0c0c7e1e;
case 0x0c0c7e20u: goto P_0c0c7e20;
case 0x0c0c7e22u: goto P_0c0c7e22;
case 0x0c0c7e24u: goto P_0c0c7e24;
case 0x0c0c7e26u: goto P_0c0c7e26;
case 0x0c0c7e28u: goto P_0c0c7e28;
case 0x0c0c7e2au: goto P_0c0c7e2a;
case 0x0c0c7e2cu: goto P_0c0c7e2c;
case 0x0c0c7e2eu: goto P_0c0c7e2e;
case 0x0c0c7e30u: goto P_0c0c7e30;
case 0x0c0c7e32u: goto P_0c0c7e32;
case 0x0c0c7e34u: goto P_0c0c7e34;
case 0x0c0c7e36u: goto P_0c0c7e36;
case 0x0c0c7e38u: goto P_0c0c7e38;
case 0x0c0c7e3au: goto P_0c0c7e3a;
case 0x0c0c7e3cu: goto P_0c0c7e3c;
case 0x0c0c7e3eu: goto P_0c0c7e3e;
case 0x0c0c7e40u: goto P_0c0c7e40;
case 0x0c0c7e42u: goto P_0c0c7e42;
case 0x0c0c7e44u: goto P_0c0c7e44;
case 0x0c0c7e46u: goto P_0c0c7e46;
case 0x0c0c7e48u: goto P_0c0c7e48;
case 0x0c0c7e4au: goto P_0c0c7e4a;
case 0x0c0c7e4cu: goto P_0c0c7e4c;
case 0x0c0c7e4eu: goto P_0c0c7e4e;
case 0x0c0c7e50u: goto P_0c0c7e50;
case 0x0c0c7e52u: goto P_0c0c7e52;
case 0x0c0c7e54u: goto P_0c0c7e54;
case 0x0c0c7e56u: goto P_0c0c7e56;
case 0x0c0c7e58u: goto P_0c0c7e58;
case 0x0c0c7e5au: goto P_0c0c7e5a;
case 0x0c0c7e5cu: goto P_0c0c7e5c;
case 0x0c0c7e5eu: goto P_0c0c7e5e;
case 0x0c0c7e60u: goto P_0c0c7e60;
case 0x0c0c7e62u: goto P_0c0c7e62;
case 0x0c0c7e64u: goto P_0c0c7e64;
case 0x0c0c7e66u: goto P_0c0c7e66;
case 0x0c0c7e68u: goto P_0c0c7e68;
case 0x0c0c7e6au: goto P_0c0c7e6a;
case 0x0c0c7e6cu: goto P_0c0c7e6c;
case 0x0c0c7e6eu: goto P_0c0c7e6e;
case 0x0c0c7e70u: goto P_0c0c7e70;
case 0x0c0c7e72u: goto P_0c0c7e72;
case 0x0c0c7e74u: goto P_0c0c7e74;
case 0x0c0c7e76u: goto P_0c0c7e76;
case 0x0c0c7e78u: goto P_0c0c7e78;
case 0x0c0c7e7au: goto P_0c0c7e7a;
case 0x0c0c7e7cu: goto P_0c0c7e7c;
case 0x0c0c7e7eu: goto P_0c0c7e7e;
case 0x0c0c7e80u: goto P_0c0c7e80;
case 0x0c0c7e82u: goto P_0c0c7e82;
case 0x0c0c7e84u: goto P_0c0c7e84;
case 0x0c0c7e86u: goto P_0c0c7e86;
case 0x0c0c7e88u: goto P_0c0c7e88;
case 0x0c0c7e8au: goto P_0c0c7e8a;
case 0x0c0c7e8cu: goto P_0c0c7e8c;
case 0x0c0c7e8eu: goto P_0c0c7e8e;
case 0x0c0c7e90u: goto P_0c0c7e90;
case 0x0c0c7e92u: goto P_0c0c7e92;
case 0x0c0c7e94u: goto P_0c0c7e94;
case 0x0c0c7e96u: goto P_0c0c7e96;
case 0x0c0c7e98u: goto P_0c0c7e98;
case 0x0c0c7e9au: goto P_0c0c7e9a;
case 0x0c0c7e9cu: goto P_0c0c7e9c;
case 0x0c0c7e9eu: goto P_0c0c7e9e;
case 0x0c0c7ea0u: goto P_0c0c7ea0;
case 0x0c0c7ea2u: goto P_0c0c7ea2;
case 0x0c0c7ea4u: goto P_0c0c7ea4;
case 0x0c0c7ea6u: goto P_0c0c7ea6;
case 0x0c0c7ea8u: goto P_0c0c7ea8;
case 0x0c0c7eaau: goto P_0c0c7eaa;
case 0x0c0c7eacu: goto P_0c0c7eac;
case 0x0c0c7eaeu: goto P_0c0c7eae;
case 0x0c0c7eb0u: goto P_0c0c7eb0;
case 0x0c0c7eb2u: goto P_0c0c7eb2;
case 0x0c0c7eb4u: goto P_0c0c7eb4;
case 0x0c0c7eb6u: goto P_0c0c7eb6;
case 0x0c0c7eb8u: goto P_0c0c7eb8;
case 0x0c0c7ebau: goto P_0c0c7eba;
case 0x0c0c7ebcu: goto P_0c0c7ebc;
case 0x0c0c7ebeu: goto P_0c0c7ebe;
case 0x0c0c7ec0u: goto P_0c0c7ec0;
case 0x0c0c7ec2u: goto P_0c0c7ec2;
case 0x0c0c7ec4u: goto P_0c0c7ec4;
case 0x0c0c7ec6u: goto P_0c0c7ec6;
case 0x0c0c7ec8u: goto P_0c0c7ec8;
case 0x0c0c7ecau: goto P_0c0c7eca;
case 0x0c0c7eccu: goto P_0c0c7ecc;
case 0x0c0c7eceu: goto P_0c0c7ece;
case 0x0c0c7ed0u: goto P_0c0c7ed0;
case 0x0c0c7ed2u: goto P_0c0c7ed2;
case 0x0c0c7ed4u: goto P_0c0c7ed4;
case 0x0c0c7ed6u: goto P_0c0c7ed6;
case 0x0c0c7ed8u: goto P_0c0c7ed8;
case 0x0c0c7edau: goto P_0c0c7eda;
case 0x0c0c7edcu: goto P_0c0c7edc;
case 0x0c0c7edeu: goto P_0c0c7ede;
case 0x0c0c7ee0u: goto P_0c0c7ee0;
case 0x0c0c7ee2u: goto P_0c0c7ee2;
case 0x0c0c7ee4u: goto P_0c0c7ee4;
case 0x0c0c7ee6u: goto P_0c0c7ee6;
case 0x0c0c7ee8u: goto P_0c0c7ee8;
case 0x0c0c7eeau: goto P_0c0c7eea;
case 0x0c0c7eecu: goto P_0c0c7eec;
case 0x0c0c7eeeu: goto P_0c0c7eee;
case 0x0c0c7ef0u: goto P_0c0c7ef0;
case 0x0c0c7ef2u: goto P_0c0c7ef2;
case 0x0c0c7ef4u: goto P_0c0c7ef4;
case 0x0c0c7ef6u: goto P_0c0c7ef6;
case 0x0c0c7ef8u: goto P_0c0c7ef8;
case 0x0c0c7efau: goto P_0c0c7efa;
case 0x0c0c7efcu: goto P_0c0c7efc;
case 0x0c0c7efeu: goto P_0c0c7efe;
case 0x0c0c7f00u: goto P_0c0c7f00;
case 0x0c0c7f02u: goto P_0c0c7f02;
case 0x0c0c7f44u: goto P_0c0c7f44;
case 0x0c0c7f46u: goto P_0c0c7f46;
case 0x0c0c7f48u: goto P_0c0c7f48;
case 0x0c0c7f4au: goto P_0c0c7f4a;
case 0x0c0c7f4cu: goto P_0c0c7f4c;
case 0x0c0c7f4eu: goto P_0c0c7f4e;
case 0x0c0c7f50u: goto P_0c0c7f50;
case 0x0c0c7f52u: goto P_0c0c7f52;
case 0x0c0c7f54u: goto P_0c0c7f54;
case 0x0c0c7f56u: goto P_0c0c7f56;
case 0x0c0c7f58u: goto P_0c0c7f58;
case 0x0c0c7f5au: goto P_0c0c7f5a;
case 0x0c0c7f5cu: goto P_0c0c7f5c;
case 0x0c0c7f5eu: goto P_0c0c7f5e;
case 0x0c0c7f60u: goto P_0c0c7f60;
case 0x0c0c7f62u: goto P_0c0c7f62;
case 0x0c0c7f64u: goto P_0c0c7f64;
case 0x0c0c7f66u: goto P_0c0c7f66;
case 0x0c0c7f68u: goto P_0c0c7f68;
case 0x0c0c7f6au: goto P_0c0c7f6a;
case 0x0c0c7f6cu: goto P_0c0c7f6c;
case 0x0c0c7f6eu: goto P_0c0c7f6e;
case 0x0c0c7f70u: goto P_0c0c7f70;
case 0x0c0c7f72u: goto P_0c0c7f72;
case 0x0c0c7f74u: goto P_0c0c7f74;
case 0x0c0c7f76u: goto P_0c0c7f76;
case 0x0c0c7f78u: goto P_0c0c7f78;
case 0x0c0c7f7au: goto P_0c0c7f7a;
case 0x0c0c7f7cu: goto P_0c0c7f7c;
case 0x0c0c7f7eu: goto P_0c0c7f7e;
case 0x0c0c7f80u: goto P_0c0c7f80;
case 0x0c0c7f82u: goto P_0c0c7f82;
case 0x0c0c7f84u: goto P_0c0c7f84;
case 0x0c0c7f86u: goto P_0c0c7f86;
case 0x0c0c7f88u: goto P_0c0c7f88;
case 0x0c0c7f8au: goto P_0c0c7f8a;
case 0x0c0c7f8cu: goto P_0c0c7f8c;
case 0x0c0c7f8eu: goto P_0c0c7f8e;
case 0x0c0c7f90u: goto P_0c0c7f90;
case 0x0c0c7f92u: goto P_0c0c7f92;
case 0x0c0c7f94u: goto P_0c0c7f94;
case 0x0c0c7f96u: goto P_0c0c7f96;
case 0x0c0c7f98u: goto P_0c0c7f98;
case 0x0c0c7f9au: goto P_0c0c7f9a;
case 0x0c0c7f9cu: goto P_0c0c7f9c;
case 0x0c0c7f9eu: goto P_0c0c7f9e;
case 0x0c0c7fa0u: goto P_0c0c7fa0;
case 0x0c0c7fa2u: goto P_0c0c7fa2;
case 0x0c0c7fa4u: goto P_0c0c7fa4;
case 0x0c0c7fa6u: goto P_0c0c7fa6;
case 0x0c0c7fa8u: goto P_0c0c7fa8;
case 0x0c0c7faau: goto P_0c0c7faa;
case 0x0c0c7facu: goto P_0c0c7fac;
case 0x0c0c7faeu: goto P_0c0c7fae;
case 0x0c0c7fb0u: goto P_0c0c7fb0;
case 0x0c0c7fb2u: goto P_0c0c7fb2;
case 0x0c0c7fb4u: goto P_0c0c7fb4;
case 0x0c0c8268u: goto P_0c0c8268;
case 0x0c0c826au: goto P_0c0c826a;
case 0x0c0c826cu: goto P_0c0c826c;
case 0x0c0c826eu: goto P_0c0c826e;
case 0x0c0c8270u: goto P_0c0c8270;
case 0x0c0c8272u: goto P_0c0c8272;
case 0x0c0c8274u: goto P_0c0c8274;
case 0x0c0c8276u: goto P_0c0c8276;
case 0x0c0c8278u: goto P_0c0c8278;
case 0x0c0c827au: goto P_0c0c827a;
case 0x0c0c827cu: goto P_0c0c827c;
case 0x0c0c827eu: goto P_0c0c827e;
case 0x0c0c8280u: goto P_0c0c8280;
case 0x0c0c8282u: goto P_0c0c8282;
case 0x0c0c8284u: goto P_0c0c8284;
case 0x0c0c8286u: goto P_0c0c8286;
case 0x0c0c8288u: goto P_0c0c8288;
case 0x0c0c828au: goto P_0c0c828a;
case 0x0c0c828cu: goto P_0c0c828c;
case 0x0c0c828eu: goto P_0c0c828e;
case 0x0c0c8290u: goto P_0c0c8290;
case 0x0c0c8292u: goto P_0c0c8292;
case 0x0c0c8294u: goto P_0c0c8294;
case 0x0c0c8296u: goto P_0c0c8296;
case 0x0c0c8298u: goto P_0c0c8298;
case 0x0c0c829au: goto P_0c0c829a;
case 0x0c0c829cu: goto P_0c0c829c;
case 0x0c0c829eu: goto P_0c0c829e;
case 0x0c0c82a0u: goto P_0c0c82a0;
case 0x0c0c82a2u: goto P_0c0c82a2;
case 0x0c0c82a4u: goto P_0c0c82a4;
case 0x0c0c82a6u: goto P_0c0c82a6;
case 0x0c0c82a8u: goto P_0c0c82a8;
case 0x0c0c82aau: goto P_0c0c82aa;
case 0x0c0c82acu: goto P_0c0c82ac;
case 0x0c0c82aeu: goto P_0c0c82ae;
case 0x0c0c82b0u: goto P_0c0c82b0;
case 0x0c0c82b2u: goto P_0c0c82b2;
case 0x0c0c82b4u: goto P_0c0c82b4;
case 0x0c0c82b6u: goto P_0c0c82b6;
case 0x0c0c82b8u: goto P_0c0c82b8;
case 0x0c0c82bau: goto P_0c0c82ba;
case 0x0c0c82bcu: goto P_0c0c82bc;
case 0x0c0c82beu: goto P_0c0c82be;
case 0x0c0c82c0u: goto P_0c0c82c0;
case 0x0c0c82c2u: goto P_0c0c82c2;
case 0x0c0c82c4u: goto P_0c0c82c4;
case 0x0c0c82c6u: goto P_0c0c82c6;
case 0x0c0c82c8u: goto P_0c0c82c8;
case 0x0c0c82cau: goto P_0c0c82ca;
case 0x0c0c82ccu: goto P_0c0c82cc;
case 0x0c0c82ceu: goto P_0c0c82ce;
case 0x0c0c82d0u: goto P_0c0c82d0;
case 0x0c0c82d2u: goto P_0c0c82d2;
case 0x0c0c82d4u: goto P_0c0c82d4;
case 0x0c0c82d6u: goto P_0c0c82d6;
case 0x0c0c82d8u: goto P_0c0c82d8;
case 0x0c0c82dau: goto P_0c0c82da;
case 0x0c0c82dcu: goto P_0c0c82dc;
case 0x0c0c82deu: goto P_0c0c82de;
case 0x0c0c82e0u: goto P_0c0c82e0;
case 0x0c0c82e2u: goto P_0c0c82e2;
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
P_0c0c7de8: /* original d54a, guest PC 0x0c0c7de8 */
if(!s->budget--) { s->failed_pc=0x0c0c7de8u; return 0; }
r[5]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7dea;
P_0c0c7dea: /* original e01c, guest PC 0x0c0c7dea */
if(!s->budget--) { s->failed_pc=0x0c0c7deau; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7dec;
P_0c0c7dec: /* original e30f, guest PC 0x0c0c7dec */
if(!s->budget--) { s->failed_pc=0x0c0c7decu; return 0; }
r[3]=0x0000000fu;
goto P_0c0c7dee;
P_0c0c7dee: /* original 9189, guest PC 0x0c0c7dee */
if(!s->budget--) { s->failed_pc=0x0c0c7deeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f04u,2);
goto P_0c0c7df0;
P_0c0c7df0: /* original 045c, guest PC 0x0c0c7df0 */
if(!s->budget--) { s->failed_pc=0x0c0c7df0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c7df2;
P_0c0c7df2: /* original d049, guest PC 0x0c0c7df2 */
if(!s->budget--) { s->failed_pc=0x0c0c7df2u; return 0; }
r[0]=read(ram,0x0c0c7f18u,4);
goto P_0c0c7df4;
P_0c0c7df4: /* original 315c, guest PC 0x0c0c7df4 */
if(!s->budget--) { s->failed_pc=0x0c0c7df4u; return 0; }
r[1]+=r[5];
goto P_0c0c7df6;
P_0c0c7df6: /* original 644c, guest PC 0x0c0c7df6 */
if(!s->budget--) { s->failed_pc=0x0c0c7df6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7df8;
P_0c0c7df8: /* original 2439, guest PC 0x0c0c7df8 */
if(!s->budget--) { s->failed_pc=0x0c0c7df8u; return 0; }
r[4]&=r[3];
goto P_0c0c7dfa;
P_0c0c7dfa: /* original 024c, guest PC 0x0c0c7dfa */
if(!s->budget--) { s->failed_pc=0x0c0c7dfau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7dfc;
P_0c0c7dfc: /* original 000b, guest PC 0x0c0c7dfc */
if(!s->budget--) { s->failed_pc=0x0c0c7dfcu; return 0; }
target=r[16];
write(ram,r[1],r[2],1);
s->pc=target; return ram->oob==0;
P_0c0c7dfe: /* original 2120, guest PC 0x0c0c7dfe */
if(!s->budget--) { s->failed_pc=0x0c0c7dfeu; return 0; }
write(ram,r[1],r[2],1);
if(!vf3_matrix_family(0x0c0c7e00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7e00u; return 0; } return 1;
P_0c0c7e1c: /* original 2fe6, guest PC 0x0c0c7e1c */
if(!s->budget--) { s->failed_pc=0x0c0c7e1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e1e;
P_0c0c7e1e: /* original e00c, guest PC 0x0c0c7e1e */
if(!s->budget--) { s->failed_pc=0x0c0c7e1eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e20;
P_0c0c7e20: /* original 2fd6, guest PC 0x0c0c7e20 */
if(!s->budget--) { s->failed_pc=0x0c0c7e20u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e22;
P_0c0c7e22: /* original 6d53, guest PC 0x0c0c7e22 */
if(!s->budget--) { s->failed_pc=0x0c0c7e22u; return 0; }
r[13]=r[5];
goto P_0c0c7e24;
P_0c0c7e24: /* original 2fc6, guest PC 0x0c0c7e24 */
if(!s->budget--) { s->failed_pc=0x0c0c7e24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e26;
P_0c0c7e26: /* original 2fb6, guest PC 0x0c0c7e26 */
if(!s->budget--) { s->failed_pc=0x0c0c7e26u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e28;
P_0c0c7e28: /* original fffb, guest PC 0x0c0c7e28 */
if(!s->budget--) { s->failed_pc=0x0c0c7e28u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c7e2a;
P_0c0c7e2a: /* original 4f22, guest PC 0x0c0c7e2a */
if(!s->budget--) { s->failed_pc=0x0c0c7e2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7e2c;
P_0c0c7e2c: /* original 7fec, guest PC 0x0c0c7e2c */
if(!s->budget--) { s->failed_pc=0x0c0c7e2cu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0c7e2e;
P_0c0c7e2e: /* original ff47, guest PC 0x0c0c7e2e */
if(!s->budget--) { s->failed_pc=0x0c0c7e2eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e30;
P_0c0c7e30: /* original e010, guest PC 0x0c0c7e30 */
if(!s->budget--) { s->failed_pc=0x0c0c7e30u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e32;
P_0c0c7e32: /* original ff67, guest PC 0x0c0c7e32 */
if(!s->budget--) { s->failed_pc=0x0c0c7e32u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0c7e34;
P_0c0c7e34: /* original 1f62, guest PC 0x0c0c7e34 */
if(!s->budget--) { s->failed_pc=0x0c0c7e34u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c7e36;
P_0c0c7e36: /* original dc37, guest PC 0x0c0c7e36 */
if(!s->budget--) { s->failed_pc=0x0c0c7e36u; return 0; }
r[12]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7e38;
P_0c0c7e38: /* original bfd6, guest PC 0x0c0c7e38 */
if(!s->budget--) { s->failed_pc=0x0c0c7e38u; return 0; }
target=code_base|0x0c0c7de8u; r[16]=code_base|0x0c0c7e3cu;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e3cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e3c;
P_0c0c7e3a: /* original 6e43, guest PC 0x0c0c7e3a */
if(!s->budget--) { s->failed_pc=0x0c0c7e3au; return 0; }
r[14]=r[4];
goto P_0c0c7e3c;
P_0c0c7e3c: /* original 60d3, guest PC 0x0c0c7e3c */
if(!s->budget--) { s->failed_pc=0x0c0c7e3cu; return 0; }
r[0]=r[13];
goto P_0c0c7e3e;
P_0c0c7e3e: /* original 80e4, guest PC 0x0c0c7e3e */
if(!s->budget--) { s->failed_pc=0x0c0c7e3eu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0c7e40;
P_0c0c7e40: /* original e01c, guest PC 0x0c0c7e40 */
if(!s->budget--) { s->failed_pc=0x0c0c7e40u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7e42;
P_0c0c7e42: /* original d337, guest PC 0x0c0c7e42 */
if(!s->budget--) { s->failed_pc=0x0c0c7e42u; return 0; }
r[3]=read(ram,0x0c0c7f20u,4);
goto P_0c0c7e44;
P_0c0c7e44: /* original 04cc, guest PC 0x0c0c7e44 */
if(!s->budget--) { s->failed_pc=0x0c0c7e44u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c7e46;
P_0c0c7e46: /* original e032, guest PC 0x0c0c7e46 */
if(!s->budget--) { s->failed_pc=0x0c0c7e46u; return 0; }
r[0]=0x00000032u;
goto P_0c0c7e48;
P_0c0c7e48: /* original 65f3, guest PC 0x0c0c7e48 */
if(!s->budget--) { s->failed_pc=0x0c0c7e48u; return 0; }
r[5]=r[15];
goto P_0c0c7e4a;
P_0c0c7e4a: /* original 7504, guest PC 0x0c0c7e4a */
if(!s->budget--) { s->failed_pc=0x0c0c7e4au; return 0; }
r[5]+=0x00000004u;
goto P_0c0c7e4c;
P_0c0c7e4c: /* original 644c, guest PC 0x0c0c7e4c */
if(!s->budget--) { s->failed_pc=0x0c0c7e4cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7e4e;
P_0c0c7e4e: /* original 66f3, guest PC 0x0c0c7e4e */
if(!s->budget--) { s->failed_pc=0x0c0c7e4eu; return 0; }
r[6]=r[15];
goto P_0c0c7e50;
P_0c0c7e50: /* original 4408, guest PC 0x0c0c7e50 */
if(!s->budget--) { s->failed_pc=0x0c0c7e50u; return 0; }
r[4]<<=2;
goto P_0c0c7e52;
P_0c0c7e52: /* original 4408, guest PC 0x0c0c7e52 */
if(!s->budget--) { s->failed_pc=0x0c0c7e52u; return 0; }
r[4]<<=2;
goto P_0c0c7e54;
P_0c0c7e54: /* original 4408, guest PC 0x0c0c7e54 */
if(!s->budget--) { s->failed_pc=0x0c0c7e54u; return 0; }
r[4]<<=2;
goto P_0c0c7e56;
P_0c0c7e56: /* original 343c, guest PC 0x0c0c7e56 */
if(!s->budget--) { s->failed_pc=0x0c0c7e56u; return 0; }
r[4]+=r[3];
goto P_0c0c7e58;
P_0c0c7e58: /* original 0b4d, guest PC 0x0c0c7e58 */
if(!s->budget--) { s->failed_pc=0x0c0c7e58u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c7e5a;
P_0c0c7e5a: /* original e028, guest PC 0x0c0c7e5a */
if(!s->budget--) { s->failed_pc=0x0c0c7e5au; return 0; }
r[0]=0x00000028u;
goto P_0c0c7e5c;
P_0c0c7e5c: /* original f446, guest PC 0x0c0c7e5c */
if(!s->budget--) { s->failed_pc=0x0c0c7e5cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0c7e5e;
P_0c0c7e5e: /* original e00c, guest PC 0x0c0c7e5e */
if(!s->budget--) { s->failed_pc=0x0c0c7e5eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e60;
P_0c0c7e60: /* original f34c, guest PC 0x0c0c7e60 */
if(!s->budget--) { s->failed_pc=0x0c0c7e60u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c7e62;
P_0c0c7e62: /* original f4f6, guest PC 0x0c0c7e62 */
if(!s->budget--) { s->failed_pc=0x0c0c7e62u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e64;
P_0c0c7e64: /* original e010, guest PC 0x0c0c7e64 */
if(!s->budget--) { s->failed_pc=0x0c0c7e64u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e66;
P_0c0c7e66: /* original f5f6, guest PC 0x0c0c7e66 */
if(!s->budget--) { s->failed_pc=0x0c0c7e66u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c7e68;
P_0c0c7e68: /* original e004, guest PC 0x0c0c7e68 */
if(!s->budget--) { s->failed_pc=0x0c0c7e68u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e6a;
P_0c0c7e6a: /* original f430, guest PC 0x0c0c7e6a */
if(!s->budget--) { s->failed_pc=0x0c0c7e6au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0c7e6c;
P_0c0c7e6c: /* original ff47, guest PC 0x0c0c7e6c */
if(!s->budget--) { s->failed_pc=0x0c0c7e6cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e6e;
P_0c0c7e6e: /* original ff5a, guest PC 0x0c0c7e6e */
if(!s->budget--) { s->failed_pc=0x0c0c7e6eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0c7e70;
P_0c0c7e70: /* original d22c, guest PC 0x0c0c7e70 */
if(!s->budget--) { s->failed_pc=0x0c0c7e70u; return 0; }
r[2]=read(ram,0x0c0c7f24u,4);
goto P_0c0c7e72;
P_0c0c7e72: /* original 420b, guest PC 0x0c0c7e72 */
if(!s->budget--) { s->failed_pc=0x0c0c7e72u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7e76u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e76u) { target=s->pc; goto dispatch; }
goto P_0c0c7e76;
P_0c0c7e74: /* original 64b3, guest PC 0x0c0c7e74 */
if(!s->budget--) { s->failed_pc=0x0c0c7e74u; return 0; }
r[4]=r[11];
goto P_0c0c7e76;
P_0c0c7e76: /* original e004, guest PC 0x0c0c7e76 */
if(!s->budget--) { s->failed_pc=0x0c0c7e76u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e78;
P_0c0c7e78: /* original fff8, guest PC 0x0c0c7e78 */
if(!s->budget--) { s->failed_pc=0x0c0c7e78u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c7e7a;
P_0c0c7e7a: /* original f4f6, guest PC 0x0c0c7e7a */
if(!s->budget--) { s->failed_pc=0x0c0c7e7au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e7c;
P_0c0c7e7c: /* original e010, guest PC 0x0c0c7e7c */
if(!s->budget--) { s->failed_pc=0x0c0c7e7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e7e;
P_0c0c7e7e: /* original 54f2, guest PC 0x0c0c7e7e */
if(!s->budget--) { s->failed_pc=0x0c0c7e7eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c7e80;
P_0c0c7e80: /* original fe47, guest PC 0x0c0c7e80 */
if(!s->budget--) { s->failed_pc=0x0c0c7e80u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e82;
P_0c0c7e82: /* original e018, guest PC 0x0c0c7e82 */
if(!s->budget--) { s->failed_pc=0x0c0c7e82u; return 0; }
r[0]=0x00000018u;
goto P_0c0c7e84;
P_0c0c7e84: /* original fef7, guest PC 0x0c0c7e84 */
if(!s->budget--) { s->failed_pc=0x0c0c7e84u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e86;
P_0c0c7e86: /* original 34bc, guest PC 0x0c0c7e86 */
if(!s->budget--) { s->failed_pc=0x0c0c7e86u; return 0; }
r[4]+=r[11];
goto P_0c0c7e88;
P_0c0c7e88: /* original 903d, guest PC 0x0c0c7e88 */
if(!s->budget--) { s->failed_pc=0x0c0c7e88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f06u,2);
goto P_0c0c7e8a;
P_0c0c7e8a: /* original fe47, guest PC 0x0c0c7e8a */
if(!s->budget--) { s->failed_pc=0x0c0c7e8au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e8c;
P_0c0c7e8c: /* original 7008, guest PC 0x0c0c7e8c */
if(!s->budget--) { s->failed_pc=0x0c0c7e8cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c7e8e;
P_0c0c7e8e: /* original fef7, guest PC 0x0c0c7e8e */
if(!s->budget--) { s->failed_pc=0x0c0c7e8eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e90;
P_0c0c7e90: /* original 6043, guest PC 0x0c0c7e90 */
if(!s->budget--) { s->failed_pc=0x0c0c7e90u; return 0; }
r[0]=r[4];
goto P_0c0c7e92;
P_0c0c7e92: /* original 81ef, guest PC 0x0c0c7e92 */
if(!s->budget--) { s->failed_pc=0x0c0c7e92u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0c7e94;
P_0c0c7e94: /* original d324, guest PC 0x0c0c7e94 */
if(!s->budget--) { s->failed_pc=0x0c0c7e94u; return 0; }
r[3]=read(ram,0x0c0c7f28u,4);
goto P_0c0c7e96;
P_0c0c7e96: /* original f5fc, guest PC 0x0c0c7e96 */
if(!s->budget--) { s->failed_pc=0x0c0c7e96u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c7e98;
P_0c0c7e98: /* original 430b, guest PC 0x0c0c7e98 */
if(!s->budget--) { s->failed_pc=0x0c0c7e98u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7e9cu;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e9cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e9c;
P_0c0c7e9a: /* original f54d, guest PC 0x0c0c7e9a */
if(!s->budget--) { s->failed_pc=0x0c0c7e9au; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c7e9c;
P_0c0c7e9c: /* original e014, guest PC 0x0c0c7e9c */
if(!s->budget--) { s->failed_pc=0x0c0c7e9cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c7e9e;
P_0c0c7e9e: /* original f40c, guest PC 0x0c0c7e9e */
if(!s->budget--) { s->failed_pc=0x0c0c7e9eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c7ea0;
P_0c0c7ea0: /* original fe47, guest PC 0x0c0c7ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea2;
P_0c0c7ea2: /* original e30d, guest PC 0x0c0c7ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea2u; return 0; }
r[3]=0x0000000du;
goto P_0c0c7ea4;
P_0c0c7ea4: /* original 9030, guest PC 0x0c0c7ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f08u,2);
goto P_0c0c7ea6;
P_0c0c7ea6: /* original fe47, guest PC 0x0c0c7ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea8;
P_0c0c7ea8: /* original e060, guest PC 0x0c0c7ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea8u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7eaa;
P_0c0c7eaa: /* original 04ec, guest PC 0x0c0c7eaa */
if(!s->budget--) { s->failed_pc=0x0c0c7eaau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7eac;
P_0c0c7eac: /* original 644c, guest PC 0x0c0c7eac */
if(!s->budget--) { s->failed_pc=0x0c0c7eacu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7eae;
P_0c0c7eae: /* original 3433, guest PC 0x0c0c7eae */
if(!s->budget--) { s->failed_pc=0x0c0c7eaeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c7eb0;
P_0c0c7eb0: /* original 8f01, guest PC 0x0c0c7eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb0u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0c7eb6; }
goto P_0c0c7eb4;
P_0c0c7eb2: /* original e061, guest PC 0x0c0c7eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb2u; return 0; }
r[0]=0x00000061u;
goto P_0c0c7eb4;
P_0c0c7eb4: /* original 74f3, guest PC 0x0c0c7eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb4u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0c7eb6;
P_0c0c7eb6: /* original 634b, guest PC 0x0c0c7eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb6u; return 0; }
r[3]=0u-r[4];
goto P_0c0c7eb8;
P_0c0c7eb8: /* original 0e44, guest PC 0x0c0c7eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7eba;
P_0c0c7eba: /* original d41c, guest PC 0x0c0c7eba */
if(!s->budget--) { s->failed_pc=0x0c0c7ebau; return 0; }
r[4]=read(ram,0x0c0c7f2cu,4);
goto P_0c0c7ebc;
P_0c0c7ebc: /* original 9025, guest PC 0x0c0c7ebc */
if(!s->budget--) { s->failed_pc=0x0c0c7ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0au,2);
goto P_0c0c7ebe;
P_0c0c7ebe: /* original 443d, guest PC 0x0c0c7ebe */
if(!s->budget--) { s->failed_pc=0x0c0c7ebeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0c7ec0;
P_0c0c7ec0: /* original 0e46, guest PC 0x0c0c7ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ec2;
P_0c0c7ec2: /* original e400, guest PC 0x0c0c7ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec2u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7ec4;
P_0c0c7ec4: /* original e022, guest PC 0x0c0c7ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c7ec6;
P_0c0c7ec6: /* original d31a, guest PC 0x0c0c7ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec6u; return 0; }
r[3]=read(ram,0x0c0c7f30u,4);
goto P_0c0c7ec8;
P_0c0c7ec8: /* original 1e33, guest PC 0x0c0c7ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec8u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0c7eca;
P_0c0c7eca: /* original 0e44, guest PC 0x0c0c7eca */
if(!s->budget--) { s->failed_pc=0x0c0c7ecau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ecc;
P_0c0c7ecc: /* original 901e, guest PC 0x0c0c7ecc */
if(!s->budget--) { s->failed_pc=0x0c0c7eccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0cu,2);
goto P_0c0c7ece;
P_0c0c7ece: /* original 0e46, guest PC 0x0c0c7ece */
if(!s->budget--) { s->failed_pc=0x0c0c7eceu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed0;
P_0c0c7ed0: /* original 700c, guest PC 0x0c0c7ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed0u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7ed2;
P_0c0c7ed2: /* original 0e46, guest PC 0x0c0c7ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed4;
P_0c0c7ed4: /* original 901b, guest PC 0x0c0c7ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0eu,2);
goto P_0c0c7ed6;
P_0c0c7ed6: /* original 0e46, guest PC 0x0c0c7ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed8;
P_0c0c7ed8: /* original 700c, guest PC 0x0c0c7ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed8u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7eda;
P_0c0c7eda: /* original 0e46, guest PC 0x0c0c7eda */
if(!s->budget--) { s->failed_pc=0x0c0c7edau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7edc;
P_0c0c7edc: /* original 9018, guest PC 0x0c0c7edc */
if(!s->budget--) { s->failed_pc=0x0c0c7edcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f10u,2);
goto P_0c0c7ede;
P_0c0c7ede: /* original 0e44, guest PC 0x0c0c7ede */
if(!s->budget--) { s->failed_pc=0x0c0c7edeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ee0;
P_0c0c7ee0: /* original e401, guest PC 0x0c0c7ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee0u; return 0; }
r[4]=0x00000001u;
goto P_0c0c7ee2;
P_0c0c7ee2: /* original 60e2, guest PC 0x0c0c7ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c7ee4;
P_0c0c7ee4: /* original d313, guest PC 0x0c0c7ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee4u; return 0; }
r[3]=read(ram,0x0c0c7f34u,4);
goto P_0c0c7ee6;
P_0c0c7ee6: /* original 2039, guest PC 0x0c0c7ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee6u; return 0; }
r[0]&=r[3];
goto P_0c0c7ee8;
P_0c0c7ee8: /* original 240b, guest PC 0x0c0c7ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee8u; return 0; }
r[4]|=r[0];
goto P_0c0c7eea;
P_0c0c7eea: /* original 2e42, guest PC 0x0c0c7eea */
if(!s->budget--) { s->failed_pc=0x0c0c7eeau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0c7eec;
P_0c0c7eec: /* original d212, guest PC 0x0c0c7eec */
if(!s->budget--) { s->failed_pc=0x0c0c7eecu; return 0; }
r[2]=read(ram,0x0c0c7f38u,4);
goto P_0c0c7eee;
P_0c0c7eee: /* original 420b, guest PC 0x0c0c7eee */
if(!s->budget--) { s->failed_pc=0x0c0c7eeeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7ef2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7ef2u) { target=s->pc; goto dispatch; }
goto P_0c0c7ef2;
P_0c0c7ef0: /* original 64e3, guest PC 0x0c0c7ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef0u; return 0; }
r[4]=r[14];
goto P_0c0c7ef2;
P_0c0c7ef2: /* original 62c2, guest PC 0x0c0c7ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef2u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c7ef4;
P_0c0c7ef4: /* original d311, guest PC 0x0c0c7ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef4u; return 0; }
r[3]=read(ram,0x0c0c7f3cu,4);
goto P_0c0c7ef6;
P_0c0c7ef6: /* original 2238, guest PC 0x0c0c7ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c7ef8;
P_0c0c7ef8: /* original 8924, guest PC 0x0c0c7ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f44; }
goto P_0c0c7efa;
P_0c0c7efa: /* original d211, guest PC 0x0c0c7efa */
if(!s->budget--) { s->failed_pc=0x0c0c7efau; return 0; }
r[2]=read(ram,0x0c0c7f40u,4);
goto P_0c0c7efc;
P_0c0c7efc: /* original 420b, guest PC 0x0c0c7efc */
if(!s->budget--) { s->failed_pc=0x0c0c7efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f00u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f00u) { target=s->pc; goto dispatch; }
goto P_0c0c7f00;
P_0c0c7efe: /* original 64e3, guest PC 0x0c0c7efe */
if(!s->budget--) { s->failed_pc=0x0c0c7efeu; return 0; }
r[4]=r[14];
goto P_0c0c7f00;
P_0c0c7f00: /* original a02a, guest PC 0x0c0c7f00 */
if(!s->budget--) { s->failed_pc=0x0c0c7f00u; return 0; }
goto P_0c0c7f58;
P_0c0c7f02: /* original 0009, guest PC 0x0c0c7f02 */
if(!s->budget--) { s->failed_pc=0x0c0c7f02u; return 0; }
if(!vf3_matrix_family(0x0c0c7f04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7f04u; return 0; } return 1;
P_0c0c7f44: /* original e060, guest PC 0x0c0c7f44 */
if(!s->budget--) { s->failed_pc=0x0c0c7f44u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f46;
P_0c0c7f46: /* original d247, guest PC 0x0c0c7f46 */
if(!s->budget--) { s->failed_pc=0x0c0c7f46u; return 0; }
r[2]=read(ram,0x0c0c8064u,4);
goto P_0c0c7f48;
P_0c0c7f48: /* original 05ec, guest PC 0x0c0c7f48 */
if(!s->budget--) { s->failed_pc=0x0c0c7f48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f4a;
P_0c0c7f4a: /* original 84e4, guest PC 0x0c0c7f4a */
if(!s->budget--) { s->failed_pc=0x0c0c7f4au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c7f4c;
P_0c0c7f4c: /* original 655c, guest PC 0x0c0c7f4c */
if(!s->budget--) { s->failed_pc=0x0c0c7f4cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c7f4e;
P_0c0c7f4e: /* original 420b, guest PC 0x0c0c7f4e */
if(!s->budget--) { s->failed_pc=0x0c0c7f4eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f52u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f52u) { target=s->pc; goto dispatch; }
goto P_0c0c7f52;
P_0c0c7f50: /* original 640c, guest PC 0x0c0c7f50 */
if(!s->budget--) { s->failed_pc=0x0c0c7f50u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7f52;
P_0c0c7f52: /* original d345, guest PC 0x0c0c7f52 */
if(!s->budget--) { s->failed_pc=0x0c0c7f52u; return 0; }
r[3]=read(ram,0x0c0c8068u,4);
goto P_0c0c7f54;
P_0c0c7f54: /* original 430b, guest PC 0x0c0c7f54 */
if(!s->budget--) { s->failed_pc=0x0c0c7f54u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f58u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f58u) { target=s->pc; goto dispatch; }
goto P_0c0c7f58;
P_0c0c7f56: /* original 64e3, guest PC 0x0c0c7f56 */
if(!s->budget--) { s->failed_pc=0x0c0c7f56u; return 0; }
r[4]=r[14];
goto P_0c0c7f58;
P_0c0c7f58: /* original e060, guest PC 0x0c0c7f58 */
if(!s->budget--) { s->failed_pc=0x0c0c7f58u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f5a;
P_0c0c7f5a: /* original 02ec, guest PC 0x0c0c7f5a */
if(!s->budget--) { s->failed_pc=0x0c0c7f5au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f5c;
P_0c0c7f5c: /* original 907e, guest PC 0x0c0c7f5c */
if(!s->budget--) { s->failed_pc=0x0c0c7f5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c805cu,2);
goto P_0c0c7f5e;
P_0c0c7f5e: /* original 0e24, guest PC 0x0c0c7f5e */
if(!s->budget--) { s->failed_pc=0x0c0c7f5eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c7f60;
P_0c0c7f60: /* original d342, guest PC 0x0c0c7f60 */
if(!s->budget--) { s->failed_pc=0x0c0c7f60u; return 0; }
r[3]=read(ram,0x0c0c806cu,4);
goto P_0c0c7f62;
P_0c0c7f62: /* original 61c2, guest PC 0x0c0c7f62 */
if(!s->budget--) { s->failed_pc=0x0c0c7f62u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0c7f64;
P_0c0c7f64: /* original 2138, guest PC 0x0c0c7f64 */
if(!s->budget--) { s->failed_pc=0x0c0c7f64u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7f66;
P_0c0c7f66: /* original 8904, guest PC 0x0c0c7f66 */
if(!s->budget--) { s->failed_pc=0x0c0c7f66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f72; }
goto P_0c0c7f68;
P_0c0c7f68: /* original d241, guest PC 0x0c0c7f68 */
if(!s->budget--) { s->failed_pc=0x0c0c7f68u; return 0; }
r[2]=read(ram,0x0c0c8070u,4);
goto P_0c0c7f6a;
P_0c0c7f6a: /* original 420b, guest PC 0x0c0c7f6a */
if(!s->budget--) { s->failed_pc=0x0c0c7f6au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f6eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f6eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f6e;
P_0c0c7f6c: /* original 0009, guest PC 0x0c0c7f6c */
if(!s->budget--) { s->failed_pc=0x0c0c7f6cu; return 0; }
goto P_0c0c7f6e;
P_0c0c7f6e: /* original a006, guest PC 0x0c0c7f6e */
if(!s->budget--) { s->failed_pc=0x0c0c7f6eu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f70: /* original 0009, guest PC 0x0c0c7f70 */
if(!s->budget--) { s->failed_pc=0x0c0c7f70u; return 0; }
goto P_0c0c7f72;
P_0c0c7f72: /* original 60d3, guest PC 0x0c0c7f72 */
if(!s->budget--) { s->failed_pc=0x0c0c7f72u; return 0; }
r[0]=r[13];
goto P_0c0c7f74;
P_0c0c7f74: /* original 8801, guest PC 0x0c0c7f74 */
if(!s->budget--) { s->failed_pc=0x0c0c7f74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c7f76;
P_0c0c7f76: /* original 8b02, guest PC 0x0c0c7f76 */
if(!s->budget--) { s->failed_pc=0x0c0c7f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f7e; }
goto P_0c0c7f78;
P_0c0c7f78: /* original d13e, guest PC 0x0c0c7f78 */
if(!s->budget--) { s->failed_pc=0x0c0c7f78u; return 0; }
r[1]=read(ram,0x0c0c8074u,4);
goto P_0c0c7f7a;
P_0c0c7f7a: /* original 410b, guest PC 0x0c0c7f7a */
if(!s->budget--) { s->failed_pc=0x0c0c7f7au; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7f7eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f7eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f7e;
P_0c0c7f7c: /* original 0009, guest PC 0x0c0c7f7c */
if(!s->budget--) { s->failed_pc=0x0c0c7f7cu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f7e: /* original d33e, guest PC 0x0c0c7f7e */
if(!s->budget--) { s->failed_pc=0x0c0c7f7eu; return 0; }
r[3]=read(ram,0x0c0c8078u,4);
goto P_0c0c7f80;
P_0c0c7f80: /* original 430b, guest PC 0x0c0c7f80 */
if(!s->budget--) { s->failed_pc=0x0c0c7f80u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f84u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f84u) { target=s->pc; goto dispatch; }
goto P_0c0c7f84;
P_0c0c7f82: /* original 64e3, guest PC 0x0c0c7f82 */
if(!s->budget--) { s->failed_pc=0x0c0c7f82u; return 0; }
r[4]=r[14];
goto P_0c0c7f84;
P_0c0c7f84: /* original d23d, guest PC 0x0c0c7f84 */
if(!s->budget--) { s->failed_pc=0x0c0c7f84u; return 0; }
r[2]=read(ram,0x0c0c807cu,4);
goto P_0c0c7f86;
P_0c0c7f86: /* original 420b, guest PC 0x0c0c7f86 */
if(!s->budget--) { s->failed_pc=0x0c0c7f86u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f8au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f8au) { target=s->pc; goto dispatch; }
goto P_0c0c7f8a;
P_0c0c7f88: /* original 0009, guest PC 0x0c0c7f88 */
if(!s->budget--) { s->failed_pc=0x0c0c7f88u; return 0; }
goto P_0c0c7f8a;
P_0c0c7f8a: /* original 2dd8, guest PC 0x0c0c7f8a */
if(!s->budget--) { s->failed_pc=0x0c0c7f8au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c7f8c;
P_0c0c7f8c: /* original 8b06, guest PC 0x0c0c7f8c */
if(!s->budget--) { s->failed_pc=0x0c0c7f8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f9c; }
goto P_0c0c7f8e;
P_0c0c7f8e: /* original d33e, guest PC 0x0c0c7f8e */
if(!s->budget--) { s->failed_pc=0x0c0c7f8eu; return 0; }
r[3]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f90;
P_0c0c7f90: /* original d23c, guest PC 0x0c0c7f90 */
if(!s->budget--) { s->failed_pc=0x0c0c7f90u; return 0; }
r[2]=read(ram,0x0c0c8084u,4);
goto P_0c0c7f92;
P_0c0c7f92: /* original d53b, guest PC 0x0c0c7f92 */
if(!s->budget--) { s->failed_pc=0x0c0c7f92u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7f94;
P_0c0c7f94: /* original 430b, guest PC 0x0c0c7f94 */
if(!s->budget--) { s->failed_pc=0x0c0c7f94u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f98u;
tmp=read(ram,r[2],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f98u) { target=s->pc; goto dispatch; }
goto P_0c0c7f98;
P_0c0c7f96: /* original 6422, guest PC 0x0c0c7f96 */
if(!s->budget--) { s->failed_pc=0x0c0c7f96u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c7f98;
P_0c0c7f98: /* original a005, guest PC 0x0c0c7f98 */
if(!s->budget--) { s->failed_pc=0x0c0c7f98u; return 0; }
goto P_0c0c7fa6;
P_0c0c7f9a: /* original 0009, guest PC 0x0c0c7f9a */
if(!s->budget--) { s->failed_pc=0x0c0c7f9au; return 0; }
goto P_0c0c7f9c;
P_0c0c7f9c: /* original d23a, guest PC 0x0c0c7f9c */
if(!s->budget--) { s->failed_pc=0x0c0c7f9cu; return 0; }
r[2]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f9e;
P_0c0c7f9e: /* original d33b, guest PC 0x0c0c7f9e */
if(!s->budget--) { s->failed_pc=0x0c0c7f9eu; return 0; }
r[3]=read(ram,0x0c0c808cu,4);
goto P_0c0c7fa0;
P_0c0c7fa0: /* original d537, guest PC 0x0c0c7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa0u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7fa2;
P_0c0c7fa2: /* original 420b, guest PC 0x0c0c7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7fa6u;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7fa6u) { target=s->pc; goto dispatch; }
goto P_0c0c7fa6;
P_0c0c7fa4: /* original 6432, guest PC 0x0c0c7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c7fa6;
P_0c0c7fa6: /* original 7f14, guest PC 0x0c0c7fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa6u; return 0; }
r[15]+=0x00000014u;
goto P_0c0c7fa8;
P_0c0c7fa8: /* original 4f26, guest PC 0x0c0c7fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7faa;
P_0c0c7faa: /* original fff9, guest PC 0x0c0c7faa */
if(!s->budget--) { s->failed_pc=0x0c0c7faau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c7fac;
P_0c0c7fac: /* original 6bf6, guest PC 0x0c0c7fac */
if(!s->budget--) { s->failed_pc=0x0c0c7facu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7fae;
P_0c0c7fae: /* original 6cf6, guest PC 0x0c0c7fae */
if(!s->budget--) { s->failed_pc=0x0c0c7faeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7fb0;
P_0c0c7fb0: /* original 6df6, guest PC 0x0c0c7fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7fb2;
P_0c0c7fb2: /* original 000b, guest PC 0x0c0c7fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7fb4: /* original 6ef6, guest PC 0x0c0c7fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7fb6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7fb6u; return 0; } return 1;
P_0c0c8268: /* original 2fe6, guest PC 0x0c0c8268 */
if(!s->budget--) { s->failed_pc=0x0c0c8268u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c826a;
P_0c0c826a: /* original e061, guest PC 0x0c0c826a */
if(!s->budget--) { s->failed_pc=0x0c0c826au; return 0; }
r[0]=0x00000061u;
goto P_0c0c826c;
P_0c0c826c: /* original 2fd6, guest PC 0x0c0c826c */
if(!s->budget--) { s->failed_pc=0x0c0c826cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c826e;
P_0c0c826e: /* original 2fc6, guest PC 0x0c0c826e */
if(!s->budget--) { s->failed_pc=0x0c0c826eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8270;
P_0c0c8270: /* original 2fb6, guest PC 0x0c0c8270 */
if(!s->budget--) { s->failed_pc=0x0c0c8270u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8272;
P_0c0c8272: /* original eb00, guest PC 0x0c0c8272 */
if(!s->budget--) { s->failed_pc=0x0c0c8272u; return 0; }
r[11]=0x00000000u;
goto P_0c0c8274;
P_0c0c8274: /* original 4f22, guest PC 0x0c0c8274 */
if(!s->budget--) { s->failed_pc=0x0c0c8274u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8276;
P_0c0c8276: /* original d340, guest PC 0x0c0c8276 */
if(!s->budget--) { s->failed_pc=0x0c0c8276u; return 0; }
r[3]=read(ram,0x0c0c8378u,4);
goto P_0c0c8278;
P_0c0c8278: /* original 67b3, guest PC 0x0c0c8278 */
if(!s->budget--) { s->failed_pc=0x0c0c8278u; return 0; }
r[7]=r[11];
goto P_0c0c827a;
P_0c0c827a: /* original de3e, guest PC 0x0c0c827a */
if(!s->budget--) { s->failed_pc=0x0c0c827au; return 0; }
r[14]=read(ram,0x0c0c8374u,4);
goto P_0c0c827c;
P_0c0c827c: /* original 7ff4, guest PC 0x0c0c827c */
if(!s->budget--) { s->failed_pc=0x0c0c827cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c827e;
P_0c0c827e: /* original 1f32, guest PC 0x0c0c827e */
if(!s->budget--) { s->failed_pc=0x0c0c827eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c8280;
P_0c0c8280: /* original 66e3, guest PC 0x0c0c8280 */
if(!s->budget--) { s->failed_pc=0x0c0c8280u; return 0; }
r[6]=r[14];
goto P_0c0c8282;
P_0c0c8282: /* original d53e, guest PC 0x0c0c8282 */
if(!s->budget--) { s->failed_pc=0x0c0c8282u; return 0; }
r[5]=read(ram,0x0c0c837cu,4);
goto P_0c0c8284;
P_0c0c8284: /* original 7658, guest PC 0x0c0c8284 */
if(!s->budget--) { s->failed_pc=0x0c0c8284u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c8286;
P_0c0c8286: /* original 5454, guest PC 0x0c0c8286 */
if(!s->budget--) { s->failed_pc=0x0c0c8286u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c8288;
P_0c0c8288: /* original 034c, guest PC 0x0c0c8288 */
if(!s->budget--) { s->failed_pc=0x0c0c8288u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c828a;
P_0c0c828a: /* original e061, guest PC 0x0c0c828a */
if(!s->budget--) { s->failed_pc=0x0c0c828au; return 0; }
r[0]=0x00000061u;
goto P_0c0c828c;
P_0c0c828c: /* original 633c, guest PC 0x0c0c828c */
if(!s->budget--) { s->failed_pc=0x0c0c828cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c828e;
P_0c0c828e: /* original 2f32, guest PC 0x0c0c828e */
if(!s->budget--) { s->failed_pc=0x0c0c828eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c8290;
P_0c0c8290: /* original 5455, guest PC 0x0c0c8290 */
if(!s->budget--) { s->failed_pc=0x0c0c8290u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0c8292;
P_0c0c8292: /* original 034c, guest PC 0x0c0c8292 */
if(!s->budget--) { s->failed_pc=0x0c0c8292u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c8294;
P_0c0c8294: /* original 633c, guest PC 0x0c0c8294 */
if(!s->budget--) { s->failed_pc=0x0c0c8294u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c8296;
P_0c0c8296: /* original 1f31, guest PC 0x0c0c8296 */
if(!s->budget--) { s->failed_pc=0x0c0c8296u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c8298;
P_0c0c8298: /* original dc39, guest PC 0x0c0c8298 */
if(!s->budget--) { s->failed_pc=0x0c0c8298u; return 0; }
r[12]=read(ram,0x0c0c8380u,4);
goto P_0c0c829a;
P_0c0c829a: /* original 2fb6, guest PC 0x0c0c829a */
if(!s->budget--) { s->failed_pc=0x0c0c829au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c829c;
P_0c0c829c: /* original 9360, guest PC 0x0c0c829c */
if(!s->budget--) { s->failed_pc=0x0c0c829cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8360u,2);
goto P_0c0c829e;
P_0c0c829e: /* original 55f1, guest PC 0x0c0c829e */
if(!s->budget--) { s->failed_pc=0x0c0c829eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c82a0;
P_0c0c82a0: /* original 945f, guest PC 0x0c0c82a0 */
if(!s->budget--) { s->failed_pc=0x0c0c82a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8362u,2);
goto P_0c0c82a2;
P_0c0c82a2: /* original 4c0b, guest PC 0x0c0c82a2 */
if(!s->budget--) { s->failed_pc=0x0c0c82a2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c82a6u;
r[5]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c82a6u) { target=s->pc; goto dispatch; }
goto P_0c0c82a6;
P_0c0c82a4: /* original 353c, guest PC 0x0c0c82a4 */
if(!s->budget--) { s->failed_pc=0x0c0c82a4u; return 0; }
r[5]+=r[3];
goto P_0c0c82a6;
P_0c0c82a6: /* original 2fb6, guest PC 0x0c0c82a6 */
if(!s->budget--) { s->failed_pc=0x0c0c82a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c82a8;
P_0c0c82a8: /* original 66e3, guest PC 0x0c0c82a8 */
if(!s->budget--) { s->failed_pc=0x0c0c82a8u; return 0; }
r[6]=r[14];
goto P_0c0c82aa;
P_0c0c82aa: /* original 55f3, guest PC 0x0c0c82aa */
if(!s->budget--) { s->failed_pc=0x0c0c82aau; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c0c82ac;
P_0c0c82ac: /* original 67b3, guest PC 0x0c0c82ac */
if(!s->budget--) { s->failed_pc=0x0c0c82acu; return 0; }
r[7]=r[11];
goto P_0c0c82ae;
P_0c0c82ae: /* original 9357, guest PC 0x0c0c82ae */
if(!s->budget--) { s->failed_pc=0x0c0c82aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8360u,2);
goto P_0c0c82b0;
P_0c0c82b0: /* original 7658, guest PC 0x0c0c82b0 */
if(!s->budget--) { s->failed_pc=0x0c0c82b0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c82b2;
P_0c0c82b2: /* original 9457, guest PC 0x0c0c82b2 */
if(!s->budget--) { s->failed_pc=0x0c0c82b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8364u,2);
goto P_0c0c82b4;
P_0c0c82b4: /* original 4c0b, guest PC 0x0c0c82b4 */
if(!s->budget--) { s->failed_pc=0x0c0c82b4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c82b8u;
r[5]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c82b8u) { target=s->pc; goto dispatch; }
goto P_0c0c82b8;
P_0c0c82b6: /* original 353c, guest PC 0x0c0c82b6 */
if(!s->budget--) { s->failed_pc=0x0c0c82b6u; return 0; }
r[5]+=r[3];
goto P_0c0c82b8;
P_0c0c82b8: /* original 7f08, guest PC 0x0c0c82b8 */
if(!s->budget--) { s->failed_pc=0x0c0c82b8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c82ba;
P_0c0c82ba: /* original 9155, guest PC 0x0c0c82ba */
if(!s->budget--) { s->failed_pc=0x0c0c82bau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8368u,2);
goto P_0c0c82bc;
P_0c0c82bc: /* original 50f2, guest PC 0x0c0c82bc */
if(!s->budget--) { s->failed_pc=0x0c0c82bcu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c0c82be;
P_0c0c82be: /* original 9d52, guest PC 0x0c0c82be */
if(!s->budget--) { s->failed_pc=0x0c0c82beu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8366u,2);
goto P_0c0c82c0;
P_0c0c82c0: /* original 001c, guest PC 0x0c0c82c0 */
if(!s->budget--) { s->failed_pc=0x0c0c82c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c82c2;
P_0c0c82c2: /* original 8801, guest PC 0x0c0c82c2 */
if(!s->budget--) { s->failed_pc=0x0c0c82c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c82c4;
P_0c0c82c4: /* original 8f01, guest PC 0x0c0c82c4 */
if(!s->budget--) { s->failed_pc=0x0c0c82c4u; return 0; }
cond=r[17]&1u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(!cond) { goto P_0c0c82ca; }
goto P_0c0c82c8;
P_0c0c82c6: /* original 2fb6, guest PC 0x0c0c82c6 */
if(!s->budget--) { s->failed_pc=0x0c0c82c6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c82c8;
P_0c0c82c8: /* original 9d4f, guest PC 0x0c0c82c8 */
if(!s->budget--) { s->failed_pc=0x0c0c82c8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c836au,2);
goto P_0c0c82ca;
P_0c0c82ca: /* original 954f, guest PC 0x0c0c82ca */
if(!s->budget--) { s->failed_pc=0x0c0c82cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c836cu,2);
goto P_0c0c82cc;
P_0c0c82cc: /* original 66e3, guest PC 0x0c0c82cc */
if(!s->budget--) { s->failed_pc=0x0c0c82ccu; return 0; }
r[6]=r[14];
goto P_0c0c82ce;
P_0c0c82ce: /* original e700, guest PC 0x0c0c82ce */
if(!s->budget--) { s->failed_pc=0x0c0c82ceu; return 0; }
r[7]=0x00000000u;
goto P_0c0c82d0;
P_0c0c82d0: /* original 4c0b, guest PC 0x0c0c82d0 */
if(!s->budget--) { s->failed_pc=0x0c0c82d0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c82d4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c82d4u) { target=s->pc; goto dispatch; }
goto P_0c0c82d4;
P_0c0c82d2: /* original 64d3, guest PC 0x0c0c82d2 */
if(!s->budget--) { s->failed_pc=0x0c0c82d2u; return 0; }
r[4]=r[13];
goto P_0c0c82d4;
P_0c0c82d4: /* original 7f10, guest PC 0x0c0c82d4 */
if(!s->budget--) { s->failed_pc=0x0c0c82d4u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c82d6;
P_0c0c82d6: /* original 64d3, guest PC 0x0c0c82d6 */
if(!s->budget--) { s->failed_pc=0x0c0c82d6u; return 0; }
r[4]=r[13];
goto P_0c0c82d8;
P_0c0c82d8: /* original 4f26, guest PC 0x0c0c82d8 */
if(!s->budget--) { s->failed_pc=0x0c0c82d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c82da;
P_0c0c82da: /* original 6bf6, guest PC 0x0c0c82da */
if(!s->budget--) { s->failed_pc=0x0c0c82dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c82dc;
P_0c0c82dc: /* original 6cf6, guest PC 0x0c0c82dc */
if(!s->budget--) { s->failed_pc=0x0c0c82dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c82de;
P_0c0c82de: /* original 6df6, guest PC 0x0c0c82de */
if(!s->budget--) { s->failed_pc=0x0c0c82deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c82e0;
P_0c0c82e0: /* original a020, guest PC 0x0c0c82e0 */
if(!s->budget--) { s->failed_pc=0x0c0c82e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c82e2: /* original 6ef6, guest PC 0x0c0c82e2 */
if(!s->budget--) { s->failed_pc=0x0c0c82e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c82e4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c82e4u; return 0; } return 1;
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
if(!vf3_matrix_family(0x0c0c8360u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8360u; return 0; } return 1;
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
r[16]=code_base|0x0c0c8402u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8402u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c840eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c840eu) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c841eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c841eu) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c842au;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c842au) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c8450u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8450u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c0c8474u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8474u; return 0; } return 1;
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
r[16]=code_base|0x0c0c84bcu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84bcu) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c84c4u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84c4u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c84d8u;
r[5]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84d8u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c84f6u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84f6u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c84fcu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84fcu) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c8510u;
r[5]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8510u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c8530u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8530u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c853cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c853cu) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c8552u;
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8552u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c0c8556u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8556u; return 0; } return 1;
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
r[16]=code_base|0x0c0c85acu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c85acu) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c85bcu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c85bcu) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c85d2u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c85d2u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c85e0u;
r[5]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c85e0u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c8602u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8602u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0c8610u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8610u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c0c8624u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8624u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
