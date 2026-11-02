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
int vf3_away_batch174_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a7f5au: goto P_0c0a7f5a;
case 0x0c0a7f5cu: goto P_0c0a7f5c;
case 0x0c0a7f5eu: goto P_0c0a7f5e;
case 0x0c0a7f60u: goto P_0c0a7f60;
case 0x0c0a7f62u: goto P_0c0a7f62;
case 0x0c0a7f64u: goto P_0c0a7f64;
case 0x0c0a7f66u: goto P_0c0a7f66;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
case 0x0c0a82c0u: goto P_0c0a82c0;
case 0x0c0a82c2u: goto P_0c0a82c2;
case 0x0c0a82c4u: goto P_0c0a82c4;
case 0x0c0a82c6u: goto P_0c0a82c6;
case 0x0c0a82c8u: goto P_0c0a82c8;
case 0x0c0a82cau: goto P_0c0a82ca;
case 0x0c0a82ccu: goto P_0c0a82cc;
case 0x0c0a82ceu: goto P_0c0a82ce;
case 0x0c0a82d0u: goto P_0c0a82d0;
case 0x0c0a82d2u: goto P_0c0a82d2;
case 0x0c0a82d4u: goto P_0c0a82d4;
case 0x0c0a82d6u: goto P_0c0a82d6;
case 0x0c0a82d8u: goto P_0c0a82d8;
case 0x0c0a82dau: goto P_0c0a82da;
case 0x0c0a82dcu: goto P_0c0a82dc;
case 0x0c0a82deu: goto P_0c0a82de;
case 0x0c0a82e0u: goto P_0c0a82e0;
case 0x0c0a82e2u: goto P_0c0a82e2;
case 0x0c0a82e4u: goto P_0c0a82e4;
case 0x0c0a82e6u: goto P_0c0a82e6;
case 0x0c0a82e8u: goto P_0c0a82e8;
case 0x0c0a82eau: goto P_0c0a82ea;
case 0x0c0a82ecu: goto P_0c0a82ec;
case 0x0c0a82eeu: goto P_0c0a82ee;
case 0x0c0a82f0u: goto P_0c0a82f0;
case 0x0c0a82f2u: goto P_0c0a82f2;
case 0x0c0a82f4u: goto P_0c0a82f4;
case 0x0c0a82f6u: goto P_0c0a82f6;
case 0x0c0a82f8u: goto P_0c0a82f8;
case 0x0c0a82fau: goto P_0c0a82fa;
case 0x0c0a82fcu: goto P_0c0a82fc;
case 0x0c0a82feu: goto P_0c0a82fe;
case 0x0c0a8300u: goto P_0c0a8300;
case 0x0c0a8302u: goto P_0c0a8302;
case 0x0c0a8304u: goto P_0c0a8304;
case 0x0c0a8306u: goto P_0c0a8306;
case 0x0c0a8308u: goto P_0c0a8308;
case 0x0c0a830au: goto P_0c0a830a;
case 0x0c0a830cu: goto P_0c0a830c;
case 0x0c0a830eu: goto P_0c0a830e;
case 0x0c0a8310u: goto P_0c0a8310;
case 0x0c0a8312u: goto P_0c0a8312;
case 0x0c0a8314u: goto P_0c0a8314;
case 0x0c0a8316u: goto P_0c0a8316;
case 0x0c0a8318u: goto P_0c0a8318;
case 0x0c0a831au: goto P_0c0a831a;
case 0x0c0a831cu: goto P_0c0a831c;
case 0x0c0a831eu: goto P_0c0a831e;
case 0x0c0a8320u: goto P_0c0a8320;
case 0x0c0a8322u: goto P_0c0a8322;
case 0x0c0a8324u: goto P_0c0a8324;
case 0x0c0a8326u: goto P_0c0a8326;
case 0x0c0a8328u: goto P_0c0a8328;
case 0x0c0a832au: goto P_0c0a832a;
case 0x0c0a832cu: goto P_0c0a832c;
case 0x0c0a832eu: goto P_0c0a832e;
case 0x0c0a8330u: goto P_0c0a8330;
case 0x0c0a8332u: goto P_0c0a8332;
case 0x0c0a8334u: goto P_0c0a8334;
case 0x0c0a8336u: goto P_0c0a8336;
case 0x0c0a8338u: goto P_0c0a8338;
case 0x0c0a833au: goto P_0c0a833a;
case 0x0c0a833cu: goto P_0c0a833c;
case 0x0c0a833eu: goto P_0c0a833e;
case 0x0c0a8340u: goto P_0c0a8340;
case 0x0c0a8342u: goto P_0c0a8342;
case 0x0c0a8344u: goto P_0c0a8344;
case 0x0c0a8346u: goto P_0c0a8346;
case 0x0c0a8348u: goto P_0c0a8348;
case 0x0c0a834au: goto P_0c0a834a;
case 0x0c0a834cu: goto P_0c0a834c;
case 0x0c0a834eu: goto P_0c0a834e;
case 0x0c0a8350u: goto P_0c0a8350;
case 0x0c0a8352u: goto P_0c0a8352;
case 0x0c0a8354u: goto P_0c0a8354;
case 0x0c0b22c4u: goto P_0c0b22c4;
case 0x0c0b22c6u: goto P_0c0b22c6;
case 0x0c0b22c8u: goto P_0c0b22c8;
case 0x0c0b22cau: goto P_0c0b22ca;
case 0x0c0b22ccu: goto P_0c0b22cc;
case 0x0c0b22ceu: goto P_0c0b22ce;
case 0x0c0b22d0u: goto P_0c0b22d0;
case 0x0c0b22d2u: goto P_0c0b22d2;
case 0x0c0b22d4u: goto P_0c0b22d4;
case 0x0c0b22d6u: goto P_0c0b22d6;
case 0x0c0b22d8u: goto P_0c0b22d8;
case 0x0c0b22dau: goto P_0c0b22da;
case 0x0c0b22dcu: goto P_0c0b22dc;
case 0x0c0b22deu: goto P_0c0b22de;
case 0x0c0b22e0u: goto P_0c0b22e0;
case 0x0c0b22e2u: goto P_0c0b22e2;
case 0x0c0b22e4u: goto P_0c0b22e4;
case 0x0c0b22e6u: goto P_0c0b22e6;
case 0x0c0b22e8u: goto P_0c0b22e8;
case 0x0c0b22eau: goto P_0c0b22ea;
case 0x0c0b22ecu: goto P_0c0b22ec;
case 0x0c0b22eeu: goto P_0c0b22ee;
case 0x0c0b22f0u: goto P_0c0b22f0;
case 0x0c0b22f2u: goto P_0c0b22f2;
case 0x0c0b22f4u: goto P_0c0b22f4;
case 0x0c0b22f6u: goto P_0c0b22f6;
case 0x0c0b22f8u: goto P_0c0b22f8;
case 0x0c0b22fau: goto P_0c0b22fa;
case 0x0c0b22fcu: goto P_0c0b22fc;
case 0x0c0b22feu: goto P_0c0b22fe;
case 0x0c0b2300u: goto P_0c0b2300;
case 0x0c0b2302u: goto P_0c0b2302;
case 0x0c0b2304u: goto P_0c0b2304;
case 0x0c0b2306u: goto P_0c0b2306;
case 0x0c0b2308u: goto P_0c0b2308;
case 0x0c0b230au: goto P_0c0b230a;
case 0x0c0b230cu: goto P_0c0b230c;
case 0x0c0b230eu: goto P_0c0b230e;
case 0x0c0b2310u: goto P_0c0b2310;
case 0x0c0b2312u: goto P_0c0b2312;
case 0x0c0b2314u: goto P_0c0b2314;
case 0x0c0b2316u: goto P_0c0b2316;
case 0x0c0b2318u: goto P_0c0b2318;
case 0x0c0b231au: goto P_0c0b231a;
case 0x0c0b231cu: goto P_0c0b231c;
case 0x0c0b231eu: goto P_0c0b231e;
case 0x0c0b2320u: goto P_0c0b2320;
case 0x0c0b2322u: goto P_0c0b2322;
case 0x0c0b2324u: goto P_0c0b2324;
case 0x0c0b2326u: goto P_0c0b2326;
case 0x0c0b2328u: goto P_0c0b2328;
case 0x0c0b232au: goto P_0c0b232a;
case 0x0c0b232cu: goto P_0c0b232c;
case 0x0c0b232eu: goto P_0c0b232e;
case 0x0c0b2330u: goto P_0c0b2330;
case 0x0c0b2332u: goto P_0c0b2332;
case 0x0c0b2334u: goto P_0c0b2334;
case 0x0c0b2336u: goto P_0c0b2336;
case 0x0c0b2338u: goto P_0c0b2338;
case 0x0c0b233au: goto P_0c0b233a;
case 0x0c0b233cu: goto P_0c0b233c;
case 0x0c0b233eu: goto P_0c0b233e;
case 0x0c0b2340u: goto P_0c0b2340;
case 0x0c0b2342u: goto P_0c0b2342;
case 0x0c0b2344u: goto P_0c0b2344;
case 0x0c0b2346u: goto P_0c0b2346;
case 0x0c0b2348u: goto P_0c0b2348;
case 0x0c0b234au: goto P_0c0b234a;
case 0x0c0b234cu: goto P_0c0b234c;
case 0x0c0b234eu: goto P_0c0b234e;
case 0x0c0b2350u: goto P_0c0b2350;
case 0x0c0b2352u: goto P_0c0b2352;
case 0x0c0b2354u: goto P_0c0b2354;
case 0x0c0b2356u: goto P_0c0b2356;
case 0x0c0b2358u: goto P_0c0b2358;
case 0x0c0b235au: goto P_0c0b235a;
case 0x0c0b235cu: goto P_0c0b235c;
case 0x0c0b235eu: goto P_0c0b235e;
case 0x0c0b2360u: goto P_0c0b2360;
case 0x0c0b2362u: goto P_0c0b2362;
case 0x0c0b2364u: goto P_0c0b2364;
case 0x0c0b2366u: goto P_0c0b2366;
case 0x0c0b2368u: goto P_0c0b2368;
case 0x0c0b236au: goto P_0c0b236a;
case 0x0c0b236cu: goto P_0c0b236c;
case 0x0c0b236eu: goto P_0c0b236e;
case 0x0c0b2370u: goto P_0c0b2370;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a7f5a: /* original 2fe6, guest PC 0x0c0a7f5a */
if(!s->budget--) { s->failed_pc=0x0c0a7f5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5c;
P_0c0a7f5c: /* original 2fd6, guest PC 0x0c0a7f5c */
if(!s->budget--) { s->failed_pc=0x0c0a7f5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5e;
P_0c0a7f5e: /* original 2fc6, guest PC 0x0c0a7f5e */
if(!s->budget--) { s->failed_pc=0x0c0a7f5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f60;
P_0c0a7f60: /* original 2fb6, guest PC 0x0c0a7f60 */
if(!s->budget--) { s->failed_pc=0x0c0a7f60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f62;
P_0c0a7f62: /* original 6b43, guest PC 0x0c0a7f62 */
if(!s->budget--) { s->failed_pc=0x0c0a7f62u; return 0; }
r[11]=r[4];
goto P_0c0a7f64;
P_0c0a7f64: /* original 2fa6, guest PC 0x0c0a7f64 */
if(!s->budget--) { s->failed_pc=0x0c0a7f64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f66;
P_0c0a7f66: /* original e400, guest PC 0x0c0a7f66 */
if(!s->budget--) { s->failed_pc=0x0c0a7f66u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7f68;
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
if(!vf3_matrix_family(0x0c0a7fa6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7fa6u; return 0; } return 1;
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7fc8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a7fd6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7ff6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8000u;
r[5]=0x00000072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8006u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a801au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8024u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a802au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a803cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a803cu; return 0; } return 1;
P_0c0a82c0: /* original 2fe6, guest PC 0x0c0a82c0 */
if(!s->budget--) { s->failed_pc=0x0c0a82c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c2;
P_0c0a82c2: /* original 2fd6, guest PC 0x0c0a82c2 */
if(!s->budget--) { s->failed_pc=0x0c0a82c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c4;
P_0c0a82c4: /* original 2fc6, guest PC 0x0c0a82c4 */
if(!s->budget--) { s->failed_pc=0x0c0a82c4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c6;
P_0c0a82c6: /* original d324, guest PC 0x0c0a82c6 */
if(!s->budget--) { s->failed_pc=0x0c0a82c6u; return 0; }
r[3]=read(ram,0x0c0a8358u,4);
goto P_0c0a82c8;
P_0c0a82c8: /* original 4f22, guest PC 0x0c0a82c8 */
if(!s->budget--) { s->failed_pc=0x0c0a82c8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a82ca;
P_0c0a82ca: /* original 6e32, guest PC 0x0c0a82ca */
if(!s->budget--) { s->failed_pc=0x0c0a82cau; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a82cc;
P_0c0a82cc: /* original d223, guest PC 0x0c0a82cc */
if(!s->budget--) { s->failed_pc=0x0c0a82ccu; return 0; }
r[2]=read(ram,0x0c0a835cu,4);
goto P_0c0a82ce;
P_0c0a82ce: /* original 61e2, guest PC 0x0c0a82ce */
if(!s->budget--) { s->failed_pc=0x0c0a82ceu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a82d0;
P_0c0a82d0: /* original 4f12, guest PC 0x0c0a82d0 */
if(!s->budget--) { s->failed_pc=0x0c0a82d0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a82d2;
P_0c0a82d2: /* original 2128, guest PC 0x0c0a82d2 */
if(!s->budget--) { s->failed_pc=0x0c0a82d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0a82d4;
P_0c0a82d4: /* original 8934, guest PC 0x0c0a82d4 */
if(!s->budget--) { s->failed_pc=0x0c0a82d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8340; }
goto P_0c0a82d6;
P_0c0a82d6: /* original 85eb, guest PC 0x0c0a82d6 */
if(!s->budget--) { s->failed_pc=0x0c0a82d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a82d8;
P_0c0a82d8: /* original ed34, guest PC 0x0c0a82d8 */
if(!s->budget--) { s->failed_pc=0x0c0a82d8u; return 0; }
r[13]=0x00000034u;
goto P_0c0a82da;
P_0c0a82da: /* original 61e3, guest PC 0x0c0a82da */
if(!s->budget--) { s->failed_pc=0x0c0a82dau; return 0; }
r[1]=r[14];
goto P_0c0a82dc;
P_0c0a82dc: /* original 711c, guest PC 0x0c0a82dc */
if(!s->budget--) { s->failed_pc=0x0c0a82dcu; return 0; }
r[1]+=0x0000001cu;
goto P_0c0a82de;
P_0c0a82de: /* original 20df, guest PC 0x0c0a82de */
if(!s->budget--) { s->failed_pc=0x0c0a82deu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[13]);
goto P_0c0a82e0;
P_0c0a82e0: /* original 0d1a, guest PC 0x0c0a82e0 */
if(!s->budget--) { s->failed_pc=0x0c0a82e0u; return 0; }
r[13]=r[19];
goto P_0c0a82e2;
P_0c0a82e2: /* original 6ddf, guest PC 0x0c0a82e2 */
if(!s->budget--) { s->failed_pc=0x0c0a82e2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a82e4;
P_0c0a82e4: /* original 3d1c, guest PC 0x0c0a82e4 */
if(!s->budget--) { s->failed_pc=0x0c0a82e4u; return 0; }
r[13]+=r[1];
goto P_0c0a82e6;
P_0c0a82e6: /* original d11e, guest PC 0x0c0a82e6 */
if(!s->budget--) { s->failed_pc=0x0c0a82e6u; return 0; }
r[1]=read(ram,0x0c0a8360u,4);
goto P_0c0a82e8;
P_0c0a82e8: /* original 410b, guest PC 0x0c0a82e8 */
if(!s->budget--) { s->failed_pc=0x0c0a82e8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a82ecu;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a82ecu) { target=s->pc; goto dispatch; }
goto P_0c0a82ec;
P_0c0a82ea: /* original 54d3, guest PC 0x0c0a82ea */
if(!s->budget--) { s->failed_pc=0x0c0a82eau; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a82ec;
P_0c0a82ec: /* original dc1d, guest PC 0x0c0a82ec */
if(!s->budget--) { s->failed_pc=0x0c0a82ecu; return 0; }
r[12]=read(ram,0x0c0a8364u,4);
goto P_0c0a82ee;
P_0c0a82ee: /* original 4c0b, guest PC 0x0c0a82ee */
if(!s->budget--) { s->failed_pc=0x0c0a82eeu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a82f2u;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a82f2u) { target=s->pc; goto dispatch; }
goto P_0c0a82f2;
P_0c0a82f0: /* original 54d3, guest PC 0x0c0a82f0 */
if(!s->budget--) { s->failed_pc=0x0c0a82f0u; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a82f2;
P_0c0a82f2: /* original 8802, guest PC 0x0c0a82f2 */
if(!s->budget--) { s->failed_pc=0x0c0a82f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a82f4;
P_0c0a82f4: /* original 8dfb, guest PC 0x0c0a82f4 */
if(!s->budget--) { s->failed_pc=0x0c0a82f4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0a82ee; }
goto P_0c0a82f8;
P_0c0a82f6: /* original 6403, guest PC 0x0c0a82f6 */
if(!s->budget--) { s->failed_pc=0x0c0a82f6u; return 0; }
r[4]=r[0];
goto P_0c0a82f8;
P_0c0a82f8: /* original 53d5, guest PC 0x0c0a82f8 */
if(!s->budget--) { s->failed_pc=0x0c0a82f8u; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0a82fa;
P_0c0a82fa: /* original 2338, guest PC 0x0c0a82fa */
if(!s->budget--) { s->failed_pc=0x0c0a82fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a82fc;
P_0c0a82fc: /* original 8904, guest PC 0x0c0a82fc */
if(!s->budget--) { s->failed_pc=0x0c0a82fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8308; }
goto P_0c0a82fe;
P_0c0a82fe: /* original 53d5, guest PC 0x0c0a82fe */
if(!s->budget--) { s->failed_pc=0x0c0a82feu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0a8300;
P_0c0a8300: /* original e5ff, guest PC 0x0c0a8300 */
if(!s->budget--) { s->failed_pc=0x0c0a8300u; return 0; }
r[5]=0xffffffffu;
goto P_0c0a8302;
P_0c0a8302: /* original 430b, guest PC 0x0c0a8302 */
if(!s->budget--) { s->failed_pc=0x0c0a8302u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8306u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8306u) { target=s->pc; goto dispatch; }
goto P_0c0a8306;
P_0c0a8304: /* original 64d3, guest PC 0x0c0a8304 */
if(!s->budget--) { s->failed_pc=0x0c0a8304u; return 0; }
r[4]=r[13];
goto P_0c0a8306;
P_0c0a8306: /* original 2008, guest PC 0x0c0a8306 */
if(!s->budget--) { s->failed_pc=0x0c0a8306u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8308;
P_0c0a8308: /* original d317, guest PC 0x0c0a8308 */
if(!s->budget--) { s->failed_pc=0x0c0a8308u; return 0; }
r[3]=read(ram,0x0c0a8368u,4);
goto P_0c0a830a;
P_0c0a830a: /* original 430b, guest PC 0x0c0a830a */
if(!s->budget--) { s->failed_pc=0x0c0a830au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a830eu;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a830eu) { target=s->pc; goto dispatch; }
goto P_0c0a830e;
P_0c0a830c: /* original 54d3, guest PC 0x0c0a830c */
if(!s->budget--) { s->failed_pc=0x0c0a830cu; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a830e;
P_0c0a830e: /* original 62e2, guest PC 0x0c0a830e */
if(!s->budget--) { s->failed_pc=0x0c0a830eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a8310;
P_0c0a8310: /* original d316, guest PC 0x0c0a8310 */
if(!s->budget--) { s->failed_pc=0x0c0a8310u; return 0; }
r[3]=read(ram,0x0c0a836cu,4);
goto P_0c0a8312;
P_0c0a8312: /* original 2239, guest PC 0x0c0a8312 */
if(!s->budget--) { s->failed_pc=0x0c0a8312u; return 0; }
r[2]&=r[3];
goto P_0c0a8314;
P_0c0a8314: /* original a014, guest PC 0x0c0a8314 */
if(!s->budget--) { s->failed_pc=0x0c0a8314u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8340;
P_0c0a8316: /* original 2e22, guest PC 0x0c0a8316 */
if(!s->budget--) { s->failed_pc=0x0c0a8316u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8318;
P_0c0a8318: /* original 85eb, guest PC 0x0c0a8318 */
if(!s->budget--) { s->failed_pc=0x0c0a8318u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a831a;
P_0c0a831a: /* original ed34, guest PC 0x0c0a831a */
if(!s->budget--) { s->failed_pc=0x0c0a831au; return 0; }
r[13]=0x00000034u;
goto P_0c0a831c;
P_0c0a831c: /* original 63e3, guest PC 0x0c0a831c */
if(!s->budget--) { s->failed_pc=0x0c0a831cu; return 0; }
r[3]=r[14];
goto P_0c0a831e;
P_0c0a831e: /* original 731c, guest PC 0x0c0a831e */
if(!s->budget--) { s->failed_pc=0x0c0a831eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8320;
P_0c0a8320: /* original 7001, guest PC 0x0c0a8320 */
if(!s->budget--) { s->failed_pc=0x0c0a8320u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8322;
P_0c0a8322: /* original c91f, guest PC 0x0c0a8322 */
if(!s->budget--) { s->failed_pc=0x0c0a8322u; return 0; }
r[0]&=31u;
goto P_0c0a8324;
P_0c0a8324: /* original 81eb, guest PC 0x0c0a8324 */
if(!s->budget--) { s->failed_pc=0x0c0a8324u; return 0; }
write(ram,r[14]+22,r[0],2);
goto P_0c0a8326;
P_0c0a8326: /* original 85eb, guest PC 0x0c0a8326 */
if(!s->budget--) { s->failed_pc=0x0c0a8326u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a8328;
P_0c0a8328: /* original 20df, guest PC 0x0c0a8328 */
if(!s->budget--) { s->failed_pc=0x0c0a8328u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[13]);
goto P_0c0a832a;
P_0c0a832a: /* original 0d1a, guest PC 0x0c0a832a */
if(!s->budget--) { s->failed_pc=0x0c0a832au; return 0; }
r[13]=r[19];
goto P_0c0a832c;
P_0c0a832c: /* original 6ddf, guest PC 0x0c0a832c */
if(!s->budget--) { s->failed_pc=0x0c0a832cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a832e;
P_0c0a832e: /* original 3d3c, guest PC 0x0c0a832e */
if(!s->budget--) { s->failed_pc=0x0c0a832eu; return 0; }
r[13]+=r[3];
goto P_0c0a8330;
P_0c0a8330: /* original 52d5, guest PC 0x0c0a8330 */
if(!s->budget--) { s->failed_pc=0x0c0a8330u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0a8332;
P_0c0a8332: /* original 2228, guest PC 0x0c0a8332 */
if(!s->budget--) { s->failed_pc=0x0c0a8332u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8334;
P_0c0a8334: /* original 8904, guest PC 0x0c0a8334 */
if(!s->budget--) { s->failed_pc=0x0c0a8334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8340; }
goto P_0c0a8336;
P_0c0a8336: /* original 52d5, guest PC 0x0c0a8336 */
if(!s->budget--) { s->failed_pc=0x0c0a8336u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0a8338;
P_0c0a8338: /* original e5ff, guest PC 0x0c0a8338 */
if(!s->budget--) { s->failed_pc=0x0c0a8338u; return 0; }
r[5]=0xffffffffu;
goto P_0c0a833a;
P_0c0a833a: /* original 420b, guest PC 0x0c0a833a */
if(!s->budget--) { s->failed_pc=0x0c0a833au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a833eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a833eu) { target=s->pc; goto dispatch; }
goto P_0c0a833e;
P_0c0a833c: /* original 64d3, guest PC 0x0c0a833c */
if(!s->budget--) { s->failed_pc=0x0c0a833cu; return 0; }
r[4]=r[13];
goto P_0c0a833e;
P_0c0a833e: /* original 2008, guest PC 0x0c0a833e */
if(!s->budget--) { s->failed_pc=0x0c0a833eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8340;
P_0c0a8340: /* original 85eb, guest PC 0x0c0a8340 */
if(!s->budget--) { s->failed_pc=0x0c0a8340u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a8342;
P_0c0a8342: /* original 6303, guest PC 0x0c0a8342 */
if(!s->budget--) { s->failed_pc=0x0c0a8342u; return 0; }
r[3]=r[0];
goto P_0c0a8344;
P_0c0a8344: /* original 85ed, guest PC 0x0c0a8344 */
if(!s->budget--) { s->failed_pc=0x0c0a8344u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8346;
P_0c0a8346: /* original 3300, guest PC 0x0c0a8346 */
if(!s->budget--) { s->failed_pc=0x0c0a8346u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c0a8348;
P_0c0a8348: /* original 8be6, guest PC 0x0c0a8348 */
if(!s->budget--) { s->failed_pc=0x0c0a8348u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8318; }
goto P_0c0a834a;
P_0c0a834a: /* original 4f16, guest PC 0x0c0a834a */
if(!s->budget--) { s->failed_pc=0x0c0a834au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a834c;
P_0c0a834c: /* original 4f26, guest PC 0x0c0a834c */
if(!s->budget--) { s->failed_pc=0x0c0a834cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a834e;
P_0c0a834e: /* original 6cf6, guest PC 0x0c0a834e */
if(!s->budget--) { s->failed_pc=0x0c0a834eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8350;
P_0c0a8350: /* original 6df6, guest PC 0x0c0a8350 */
if(!s->budget--) { s->failed_pc=0x0c0a8350u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8352;
P_0c0a8352: /* original 000b, guest PC 0x0c0a8352 */
if(!s->budget--) { s->failed_pc=0x0c0a8352u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8354: /* original 6ef6, guest PC 0x0c0a8354 */
if(!s->budget--) { s->failed_pc=0x0c0a8354u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8356u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8356u; return 0; } return 1;
P_0c0b22c4: /* original 2fe6, guest PC 0x0c0b22c4 */
if(!s->budget--) { s->failed_pc=0x0c0b22c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22c6;
P_0c0b22c6: /* original e3ff, guest PC 0x0c0b22c6 */
if(!s->budget--) { s->failed_pc=0x0c0b22c6u; return 0; }
r[3]=0xffffffffu;
goto P_0c0b22c8;
P_0c0b22c8: /* original 2fd6, guest PC 0x0c0b22c8 */
if(!s->budget--) { s->failed_pc=0x0c0b22c8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22ca;
P_0c0b22ca: /* original 2fc6, guest PC 0x0c0b22ca */
if(!s->budget--) { s->failed_pc=0x0c0b22cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22cc;
P_0c0b22cc: /* original ec00, guest PC 0x0c0b22cc */
if(!s->budget--) { s->failed_pc=0x0c0b22ccu; return 0; }
r[12]=0x00000000u;
goto P_0c0b22ce;
P_0c0b22ce: /* original 2fb6, guest PC 0x0c0b22ce */
if(!s->budget--) { s->failed_pc=0x0c0b22ceu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22d0;
P_0c0b22d0: /* original 2fa6, guest PC 0x0c0b22d0 */
if(!s->budget--) { s->failed_pc=0x0c0b22d0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22d2;
P_0c0b22d2: /* original 6ac3, guest PC 0x0c0b22d2 */
if(!s->budget--) { s->failed_pc=0x0c0b22d2u; return 0; }
r[10]=r[12];
goto P_0c0b22d4;
P_0c0b22d4: /* original 2f96, guest PC 0x0c0b22d4 */
if(!s->budget--) { s->failed_pc=0x0c0b22d4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22d6;
P_0c0b22d6: /* original e91a, guest PC 0x0c0b22d6 */
if(!s->budget--) { s->failed_pc=0x0c0b22d6u; return 0; }
r[9]=0x0000001au;
goto P_0c0b22d8;
P_0c0b22d8: /* original 2f86, guest PC 0x0c0b22d8 */
if(!s->budget--) { s->failed_pc=0x0c0b22d8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b22da;
P_0c0b22da: /* original de28, guest PC 0x0c0b22da */
if(!s->budget--) { s->failed_pc=0x0c0b22dau; return 0; }
r[14]=read(ram,0x0c0b237cu,4);
goto P_0c0b22dc;
P_0c0b22dc: /* original 9049, guest PC 0x0c0b22dc */
if(!s->budget--) { s->failed_pc=0x0c0b22dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2372u,2);
goto P_0c0b22de;
P_0c0b22de: /* original 4f22, guest PC 0x0c0b22de */
if(!s->budget--) { s->failed_pc=0x0c0b22deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b22e0;
P_0c0b22e0: /* original 0e36, guest PC 0x0c0b22e0 */
if(!s->budget--) { s->failed_pc=0x0c0b22e0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0b22e2;
P_0c0b22e2: /* original 7008, guest PC 0x0c0b22e2 */
if(!s->budget--) { s->failed_pc=0x0c0b22e2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0b22e4;
P_0c0b22e4: /* original 0ec6, guest PC 0x0c0b22e4 */
if(!s->budget--) { s->failed_pc=0x0c0b22e4u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0b22e6;
P_0c0b22e6: /* original 70fc, guest PC 0x0c0b22e6 */
if(!s->budget--) { s->failed_pc=0x0c0b22e6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0b22e8;
P_0c0b22e8: /* original 0ec6, guest PC 0x0c0b22e8 */
if(!s->budget--) { s->failed_pc=0x0c0b22e8u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0b22ea;
P_0c0b22ea: /* original dd25, guest PC 0x0c0b22ea */
if(!s->budget--) { s->failed_pc=0x0c0b22eau; return 0; }
r[13]=read(ram,0x0c0b2380u,4);
goto P_0c0b22ec;
P_0c0b22ec: /* original 5bd3, guest PC 0x0c0b22ec */
if(!s->budget--) { s->failed_pc=0x0c0b22ecu; return 0; }
r[11]=read(ram,r[13]+12,4);
goto P_0c0b22ee;
P_0c0b22ee: /* original 4b0b, guest PC 0x0c0b22ee */
if(!s->budget--) { s->failed_pc=0x0c0b22eeu; return 0; }
target=r[11];
r[16]=code_base|0x0c0b22f2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b22f2u) { target=s->pc; goto dispatch; }
goto P_0c0b22f2;
P_0c0b22f0: /* original 0009, guest PC 0x0c0b22f0 */
if(!s->budget--) { s->failed_pc=0x0c0b22f0u; return 0; }
goto P_0c0b22f2;
P_0c0b22f2: /* original 5bd8, guest PC 0x0c0b22f2 */
if(!s->budget--) { s->failed_pc=0x0c0b22f2u; return 0; }
r[11]=read(ram,r[13]+32,4);
goto P_0c0b22f4;
P_0c0b22f4: /* original 2bb8, guest PC 0x0c0b22f4 */
if(!s->budget--) { s->failed_pc=0x0c0b22f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0b22f6;
P_0c0b22f6: /* original 8901, guest PC 0x0c0b22f6 */
if(!s->budget--) { s->failed_pc=0x0c0b22f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b22fc; }
goto P_0c0b22f8;
P_0c0b22f8: /* original 4b0b, guest PC 0x0c0b22f8 */
if(!s->budget--) { s->failed_pc=0x0c0b22f8u; return 0; }
target=r[11];
r[16]=code_base|0x0c0b22fcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b22fcu) { target=s->pc; goto dispatch; }
goto P_0c0b22fc;
P_0c0b22fa: /* original 0009, guest PC 0x0c0b22fa */
if(!s->budget--) { s->failed_pc=0x0c0b22fau; return 0; }
goto P_0c0b22fc;
P_0c0b22fc: /* original 7a01, guest PC 0x0c0b22fc */
if(!s->budget--) { s->failed_pc=0x0c0b22fcu; return 0; }
r[10]+=0x00000001u;
goto P_0c0b22fe;
P_0c0b22fe: /* original 3a93, guest PC 0x0c0b22fe */
if(!s->budget--) { s->failed_pc=0x0c0b22feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c0b2300;
P_0c0b2300: /* original 8ff4, guest PC 0x0c0b2300 */
if(!s->budget--) { s->failed_pc=0x0c0b2300u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000024u;
if(!cond) { goto P_0c0b22ec; }
goto P_0c0b2304;
P_0c0b2302: /* original 7d24, guest PC 0x0c0b2302 */
if(!s->budget--) { s->failed_pc=0x0c0b2302u; return 0; }
r[13]+=0x00000024u;
goto P_0c0b2304;
P_0c0b2304: /* original 9436, guest PC 0x0c0b2304 */
if(!s->budget--) { s->failed_pc=0x0c0b2304u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2374u,2);
goto P_0c0b2306;
P_0c0b2306: /* original 69c3, guest PC 0x0c0b2306 */
if(!s->budget--) { s->failed_pc=0x0c0b2306u; return 0; }
r[9]=r[12];
goto P_0c0b2308;
P_0c0b2308: /* original 6dc3, guest PC 0x0c0b2308 */
if(!s->budget--) { s->failed_pc=0x0c0b2308u; return 0; }
r[13]=r[12];
goto P_0c0b230a;
P_0c0b230a: /* original 34ec, guest PC 0x0c0b230a */
if(!s->budget--) { s->failed_pc=0x0c0b230au; return 0; }
r[4]+=r[14];
goto P_0c0b230c;
P_0c0b230c: /* original 6a43, guest PC 0x0c0b230c */
if(!s->budget--) { s->failed_pc=0x0c0b230cu; return 0; }
r[10]=r[4];
goto P_0c0b230e;
P_0c0b230e: /* original 6b43, guest PC 0x0c0b230e */
if(!s->budget--) { s->failed_pc=0x0c0b230eu; return 0; }
r[11]=r[4];
goto P_0c0b2310;
P_0c0b2310: /* original 9331, guest PC 0x0c0b2310 */
if(!s->budget--) { s->failed_pc=0x0c0b2310u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2376u,2);
goto P_0c0b2312;
P_0c0b2312: /* original 6893, guest PC 0x0c0b2312 */
if(!s->budget--) { s->failed_pc=0x0c0b2312u; return 0; }
r[8]=r[9];
goto P_0c0b2314;
P_0c0b2314: /* original 4808, guest PC 0x0c0b2314 */
if(!s->budget--) { s->failed_pc=0x0c0b2314u; return 0; }
r[8]<<=2;
goto P_0c0b2316;
P_0c0b2316: /* original 33ec, guest PC 0x0c0b2316 */
if(!s->budget--) { s->failed_pc=0x0c0b2316u; return 0; }
r[3]+=r[14];
goto P_0c0b2318;
P_0c0b2318: /* original 338c, guest PC 0x0c0b2318 */
if(!s->budget--) { s->failed_pc=0x0c0b2318u; return 0; }
r[3]+=r[8];
goto P_0c0b231a;
P_0c0b231a: /* original 6232, guest PC 0x0c0b231a */
if(!s->budget--) { s->failed_pc=0x0c0b231au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0b231c;
P_0c0b231c: /* original 2228, guest PC 0x0c0b231c */
if(!s->budget--) { s->failed_pc=0x0c0b231cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b231e;
P_0c0b231e: /* original 8905, guest PC 0x0c0b231e */
if(!s->budget--) { s->failed_pc=0x0c0b231eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b232c; }
goto P_0c0b2320;
P_0c0b2320: /* original 9429, guest PC 0x0c0b2320 */
if(!s->budget--) { s->failed_pc=0x0c0b2320u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2376u,2);
goto P_0c0b2322;
P_0c0b2322: /* original d318, guest PC 0x0c0b2322 */
if(!s->budget--) { s->failed_pc=0x0c0b2322u; return 0; }
r[3]=read(ram,0x0c0b2384u,4);
goto P_0c0b2324;
P_0c0b2324: /* original 34ec, guest PC 0x0c0b2324 */
if(!s->budget--) { s->failed_pc=0x0c0b2324u; return 0; }
r[4]+=r[14];
goto P_0c0b2326;
P_0c0b2326: /* original 348c, guest PC 0x0c0b2326 */
if(!s->budget--) { s->failed_pc=0x0c0b2326u; return 0; }
r[4]+=r[8];
goto P_0c0b2328;
P_0c0b2328: /* original 430b, guest PC 0x0c0b2328 */
if(!s->budget--) { s->failed_pc=0x0c0b2328u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b232cu;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b232cu) { target=s->pc; goto dispatch; }
goto P_0c0b232c;
P_0c0b232a: /* original 6442, guest PC 0x0c0b232a */
if(!s->budget--) { s->failed_pc=0x0c0b232au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0b232c;
P_0c0b232c: /* original 62b2, guest PC 0x0c0b232c */
if(!s->budget--) { s->failed_pc=0x0c0b232cu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0b232e;
P_0c0b232e: /* original 2228, guest PC 0x0c0b232e */
if(!s->budget--) { s->failed_pc=0x0c0b232eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b2330;
P_0c0b2330: /* original 8902, guest PC 0x0c0b2330 */
if(!s->budget--) { s->failed_pc=0x0c0b2330u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b2338; }
goto P_0c0b2332;
P_0c0b2332: /* original d314, guest PC 0x0c0b2332 */
if(!s->budget--) { s->failed_pc=0x0c0b2332u; return 0; }
r[3]=read(ram,0x0c0b2384u,4);
goto P_0c0b2334;
P_0c0b2334: /* original 430b, guest PC 0x0c0b2334 */
if(!s->budget--) { s->failed_pc=0x0c0b2334u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b2338u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2338u) { target=s->pc; goto dispatch; }
goto P_0c0b2338;
P_0c0b2336: /* original 64a2, guest PC 0x0c0b2336 */
if(!s->budget--) { s->failed_pc=0x0c0b2336u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0b2338;
P_0c0b2338: /* original 921d, guest PC 0x0c0b2338 */
if(!s->budget--) { s->failed_pc=0x0c0b2338u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2376u,2);
goto P_0c0b233a;
P_0c0b233a: /* original 7901, guest PC 0x0c0b233a */
if(!s->budget--) { s->failed_pc=0x0c0b233au; return 0; }
r[9]+=0x00000001u;
goto P_0c0b233c;
P_0c0b233c: /* original 931a, guest PC 0x0c0b233c */
if(!s->budget--) { s->failed_pc=0x0c0b233cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2374u,2);
goto P_0c0b233e;
P_0c0b233e: /* original 7a04, guest PC 0x0c0b233e */
if(!s->budget--) { s->failed_pc=0x0c0b233eu; return 0; }
r[10]+=0x00000004u;
goto P_0c0b2340;
P_0c0b2340: /* original 32ec, guest PC 0x0c0b2340 */
if(!s->budget--) { s->failed_pc=0x0c0b2340u; return 0; }
r[2]+=r[14];
goto P_0c0b2342;
P_0c0b2342: /* original 32dc, guest PC 0x0c0b2342 */
if(!s->budget--) { s->failed_pc=0x0c0b2342u; return 0; }
r[2]+=r[13];
goto P_0c0b2344;
P_0c0b2344: /* original 33ec, guest PC 0x0c0b2344 */
if(!s->budget--) { s->failed_pc=0x0c0b2344u; return 0; }
r[3]+=r[14];
goto P_0c0b2346;
P_0c0b2346: /* original 33dc, guest PC 0x0c0b2346 */
if(!s->budget--) { s->failed_pc=0x0c0b2346u; return 0; }
r[3]+=r[13];
goto P_0c0b2348;
P_0c0b2348: /* original 23c2, guest PC 0x0c0b2348 */
if(!s->budget--) { s->failed_pc=0x0c0b2348u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c0b234a;
P_0c0b234a: /* original e3ff, guest PC 0x0c0b234a */
if(!s->budget--) { s->failed_pc=0x0c0b234au; return 0; }
r[3]=0xffffffffu;
goto P_0c0b234c;
P_0c0b234c: /* original 22c2, guest PC 0x0c0b234c */
if(!s->budget--) { s->failed_pc=0x0c0b234cu; return 0; }
write(ram,r[2],r[12],4);
goto P_0c0b234e;
P_0c0b234e: /* original 9213, guest PC 0x0c0b234e */
if(!s->budget--) { s->failed_pc=0x0c0b234eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2378u,2);
goto P_0c0b2350;
P_0c0b2350: /* original 32ec, guest PC 0x0c0b2350 */
if(!s->budget--) { s->failed_pc=0x0c0b2350u; return 0; }
r[2]+=r[14];
goto P_0c0b2352;
P_0c0b2352: /* original 32dc, guest PC 0x0c0b2352 */
if(!s->budget--) { s->failed_pc=0x0c0b2352u; return 0; }
r[2]+=r[13];
goto P_0c0b2354;
P_0c0b2354: /* original 2232, guest PC 0x0c0b2354 */
if(!s->budget--) { s->failed_pc=0x0c0b2354u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0b2356;
P_0c0b2356: /* original e202, guest PC 0x0c0b2356 */
if(!s->budget--) { s->failed_pc=0x0c0b2356u; return 0; }
r[2]=0x00000002u;
goto P_0c0b2358;
P_0c0b2358: /* original 3923, guest PC 0x0c0b2358 */
if(!s->budget--) { s->failed_pc=0x0c0b2358u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[2])!=0);
goto P_0c0b235a;
P_0c0b235a: /* original 7d04, guest PC 0x0c0b235a */
if(!s->budget--) { s->failed_pc=0x0c0b235au; return 0; }
r[13]+=0x00000004u;
goto P_0c0b235c;
P_0c0b235c: /* original 8fd8, guest PC 0x0c0b235c */
if(!s->budget--) { s->failed_pc=0x0c0b235cu; return 0; }
cond=r[17]&1u;
r[11]+=0x00000004u;
if(!cond) { goto P_0c0b2310; }
goto P_0c0b2360;
P_0c0b235e: /* original 7b04, guest PC 0x0c0b235e */
if(!s->budget--) { s->failed_pc=0x0c0b235eu; return 0; }
r[11]+=0x00000004u;
goto P_0c0b2360;
P_0c0b2360: /* original 4f26, guest PC 0x0c0b2360 */
if(!s->budget--) { s->failed_pc=0x0c0b2360u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b2362;
P_0c0b2362: /* original 68f6, guest PC 0x0c0b2362 */
if(!s->budget--) { s->failed_pc=0x0c0b2362u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0b2364;
P_0c0b2364: /* original 69f6, guest PC 0x0c0b2364 */
if(!s->budget--) { s->failed_pc=0x0c0b2364u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b2366;
P_0c0b2366: /* original 6af6, guest PC 0x0c0b2366 */
if(!s->budget--) { s->failed_pc=0x0c0b2366u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b2368;
P_0c0b2368: /* original 6bf6, guest PC 0x0c0b2368 */
if(!s->budget--) { s->failed_pc=0x0c0b2368u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b236a;
P_0c0b236a: /* original 6cf6, guest PC 0x0c0b236a */
if(!s->budget--) { s->failed_pc=0x0c0b236au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b236c;
P_0c0b236c: /* original 6df6, guest PC 0x0c0b236c */
if(!s->budget--) { s->failed_pc=0x0c0b236cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b236e;
P_0c0b236e: /* original 000b, guest PC 0x0c0b236e */
if(!s->budget--) { s->failed_pc=0x0c0b236eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b2370: /* original 6ef6, guest PC 0x0c0b2370 */
if(!s->budget--) { s->failed_pc=0x0c0b2370u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b2372u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b2372u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
