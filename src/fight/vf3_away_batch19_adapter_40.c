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
int vf3_away_batch19_adapter_40(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0c10a2u: goto P_0c0c10a2;
case 0x0c0c10a4u: goto P_0c0c10a4;
case 0x0c0c10a6u: goto P_0c0c10a6;
case 0x0c0c10a8u: goto P_0c0c10a8;
case 0x0c0c10aau: goto P_0c0c10aa;
case 0x0c0c10acu: goto P_0c0c10ac;
case 0x0c0c10aeu: goto P_0c0c10ae;
case 0x0c0c10b0u: goto P_0c0c10b0;
case 0x0c0c10b2u: goto P_0c0c10b2;
case 0x0c0c10b4u: goto P_0c0c10b4;
case 0x0c0c10b6u: goto P_0c0c10b6;
case 0x0c0c10b8u: goto P_0c0c10b8;
case 0x0c0c10bau: goto P_0c0c10ba;
case 0x0c0c10bcu: goto P_0c0c10bc;
case 0x0c0c10beu: goto P_0c0c10be;
case 0x0c0c10c0u: goto P_0c0c10c0;
case 0x0c0c10c2u: goto P_0c0c10c2;
case 0x0c0c10c4u: goto P_0c0c10c4;
case 0x0c0c10c6u: goto P_0c0c10c6;
case 0x0c0c10c8u: goto P_0c0c10c8;
case 0x0c0c10cau: goto P_0c0c10ca;
case 0x0c0c10ccu: goto P_0c0c10cc;
case 0x0c0c10ceu: goto P_0c0c10ce;
case 0x0c0c10d0u: goto P_0c0c10d0;
case 0x0c0c10d2u: goto P_0c0c10d2;
case 0x0c0c10d4u: goto P_0c0c10d4;
case 0x0c0c10d6u: goto P_0c0c10d6;
case 0x0c0c10d8u: goto P_0c0c10d8;
case 0x0c0c10dau: goto P_0c0c10da;
case 0x0c0c10dcu: goto P_0c0c10dc;
case 0x0c0c10deu: goto P_0c0c10de;
case 0x0c0c10e0u: goto P_0c0c10e0;
case 0x0c0c10e2u: goto P_0c0c10e2;
case 0x0c0c10e4u: goto P_0c0c10e4;
case 0x0c0c10e6u: goto P_0c0c10e6;
case 0x0c0c10e8u: goto P_0c0c10e8;
case 0x0c0c10eau: goto P_0c0c10ea;
case 0x0c0c10ecu: goto P_0c0c10ec;
case 0x0c0c10eeu: goto P_0c0c10ee;
case 0x0c0c10f0u: goto P_0c0c10f0;
case 0x0c0c10f2u: goto P_0c0c10f2;
case 0x0c0c10f4u: goto P_0c0c10f4;
case 0x0c0c10f6u: goto P_0c0c10f6;
case 0x0c0c10f8u: goto P_0c0c10f8;
case 0x0c0c10fau: goto P_0c0c10fa;
case 0x0c0c10fcu: goto P_0c0c10fc;
case 0x0c0c10feu: goto P_0c0c10fe;
case 0x0c0c1100u: goto P_0c0c1100;
case 0x0c0c1102u: goto P_0c0c1102;
case 0x0c0c1104u: goto P_0c0c1104;
case 0x0c0c1106u: goto P_0c0c1106;
case 0x0c0c1108u: goto P_0c0c1108;
case 0x0c0c110au: goto P_0c0c110a;
case 0x0c0c110cu: goto P_0c0c110c;
case 0x0c0c110eu: goto P_0c0c110e;
case 0x0c0c1110u: goto P_0c0c1110;
case 0x0c0c1112u: goto P_0c0c1112;
case 0x0c0c1114u: goto P_0c0c1114;
case 0x0c0c1116u: goto P_0c0c1116;
case 0x0c0c1118u: goto P_0c0c1118;
case 0x0c0c111au: goto P_0c0c111a;
case 0x0c0c111cu: goto P_0c0c111c;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0c10a2: /* original 2fe6, guest PC 0x0c0c10a2 */
if(!s->budget--) { s->failed_pc=0x0c0c10a2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c10a4;
P_0c0c10a4: /* original e600, guest PC 0x0c0c10a4 */
if(!s->budget--) { s->failed_pc=0x0c0c10a4u; return 0; }
r[6]=0x00000000u;
goto P_0c0c10a6;
P_0c0c10a6: /* original 2fd6, guest PC 0x0c0c10a6 */
if(!s->budget--) { s->failed_pc=0x0c0c10a6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c10a8;
P_0c0c10a8: /* original d54d, guest PC 0x0c0c10a8 */
if(!s->budget--) { s->failed_pc=0x0c0c10a8u; return 0; }
r[5]=read(ram,0x0c0c11e0u,4);
goto P_0c0c10aa;
P_0c0c10aa: /* original 7ff0, guest PC 0x0c0c10aa */
if(!s->budget--) { s->failed_pc=0x0c0c10aau; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c10ac;
P_0c0c10ac: /* original 6353, guest PC 0x0c0c10ac */
if(!s->budget--) { s->failed_pc=0x0c0c10acu; return 0; }
r[3]=r[5];
goto P_0c0c10ae;
P_0c0c10ae: /* original 7358, guest PC 0x0c0c10ae */
if(!s->budget--) { s->failed_pc=0x0c0c10aeu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c10b0;
P_0c0c10b0: /* original 6253, guest PC 0x0c0c10b0 */
if(!s->budget--) { s->failed_pc=0x0c0c10b0u; return 0; }
r[2]=r[5];
goto P_0c0c10b2;
P_0c0c10b2: /* original 722c, guest PC 0x0c0c10b2 */
if(!s->budget--) { s->failed_pc=0x0c0c10b2u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c10b4;
P_0c0c10b4: /* original 2f52, guest PC 0x0c0c10b4 */
if(!s->budget--) { s->failed_pc=0x0c0c10b4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c10b6;
P_0c0c10b6: /* original 1f31, guest PC 0x0c0c10b6 */
if(!s->budget--) { s->failed_pc=0x0c0c10b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c10b8;
P_0c0c10b8: /* original 1f23, guest PC 0x0c0c10b8 */
if(!s->budget--) { s->failed_pc=0x0c0c10b8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c10ba;
P_0c0c10ba: /* original 9388, guest PC 0x0c0c10ba */
if(!s->budget--) { s->failed_pc=0x0c0c10bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11ceu,2);
goto P_0c0c10bc;
P_0c0c10bc: /* original 335c, guest PC 0x0c0c10bc */
if(!s->budget--) { s->failed_pc=0x0c0c10bcu; return 0; }
r[3]+=r[5];
goto P_0c0c10be;
P_0c0c10be: /* original 1f32, guest PC 0x0c0c10be */
if(!s->budget--) { s->failed_pc=0x0c0c10beu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c10c0;
P_0c0c10c0: /* original 9286, guest PC 0x0c0c10c0 */
if(!s->budget--) { s->failed_pc=0x0c0c10c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d0u,2);
goto P_0c0c10c2;
P_0c0c10c2: /* original 2248, guest PC 0x0c0c10c2 */
if(!s->budget--) { s->failed_pc=0x0c0c10c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c10c4;
P_0c0c10c4: /* original 8d03, guest PC 0x0c0c10c4 */
if(!s->budget--) { s->failed_pc=0x0c0c10c4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000004u;
if(cond) { goto P_0c0c10ce; }
goto P_0c0c10c8;
P_0c0c10c6: /* original e504, guest PC 0x0c0c10c6 */
if(!s->budget--) { s->failed_pc=0x0c0c10c6u; return 0; }
r[5]=0x00000004u;
goto P_0c0c10c8;
P_0c0c10c8: /* original 6763, guest PC 0x0c0c10c8 */
if(!s->budget--) { s->failed_pc=0x0c0c10c8u; return 0; }
r[7]=r[6];
goto P_0c0c10ca;
P_0c0c10ca: /* original a002, guest PC 0x0c0c10ca */
if(!s->budget--) { s->failed_pc=0x0c0c10cau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10d2;
P_0c0c10cc: /* original 7601, guest PC 0x0c0c10cc */
if(!s->budget--) { s->failed_pc=0x0c0c10ccu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10ce;
P_0c0c10ce: /* original 6753, guest PC 0x0c0c10ce */
if(!s->budget--) { s->failed_pc=0x0c0c10ceu; return 0; }
r[7]=r[5];
goto P_0c0c10d0;
P_0c0c10d0: /* original 7501, guest PC 0x0c0c10d0 */
if(!s->budget--) { s->failed_pc=0x0c0c10d0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10d2;
P_0c0c10d2: /* original 937e, guest PC 0x0c0c10d2 */
if(!s->budget--) { s->failed_pc=0x0c0c10d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d2u,2);
goto P_0c0c10d4;
P_0c0c10d4: /* original 2348, guest PC 0x0c0c10d4 */
if(!s->budget--) { s->failed_pc=0x0c0c10d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c10d6;
P_0c0c10d6: /* original 8902, guest PC 0x0c0c10d6 */
if(!s->budget--) { s->failed_pc=0x0c0c10d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10de; }
goto P_0c0c10d8;
P_0c0c10d8: /* original 6d63, guest PC 0x0c0c10d8 */
if(!s->budget--) { s->failed_pc=0x0c0c10d8u; return 0; }
r[13]=r[6];
goto P_0c0c10da;
P_0c0c10da: /* original a002, guest PC 0x0c0c10da */
if(!s->budget--) { s->failed_pc=0x0c0c10dau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10e2;
P_0c0c10dc: /* original 7601, guest PC 0x0c0c10dc */
if(!s->budget--) { s->failed_pc=0x0c0c10dcu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10de;
P_0c0c10de: /* original 6d53, guest PC 0x0c0c10de */
if(!s->budget--) { s->failed_pc=0x0c0c10deu; return 0; }
r[13]=r[5];
goto P_0c0c10e0;
P_0c0c10e0: /* original 7501, guest PC 0x0c0c10e0 */
if(!s->budget--) { s->failed_pc=0x0c0c10e0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10e2;
P_0c0c10e2: /* original 9277, guest PC 0x0c0c10e2 */
if(!s->budget--) { s->failed_pc=0x0c0c10e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d4u,2);
goto P_0c0c10e4;
P_0c0c10e4: /* original 2248, guest PC 0x0c0c10e4 */
if(!s->budget--) { s->failed_pc=0x0c0c10e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c10e6;
P_0c0c10e6: /* original 8902, guest PC 0x0c0c10e6 */
if(!s->budget--) { s->failed_pc=0x0c0c10e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10ee; }
goto P_0c0c10e8;
P_0c0c10e8: /* original 6e63, guest PC 0x0c0c10e8 */
if(!s->budget--) { s->failed_pc=0x0c0c10e8u; return 0; }
r[14]=r[6];
goto P_0c0c10ea;
P_0c0c10ea: /* original a002, guest PC 0x0c0c10ea */
if(!s->budget--) { s->failed_pc=0x0c0c10eau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10f2;
P_0c0c10ec: /* original 7601, guest PC 0x0c0c10ec */
if(!s->budget--) { s->failed_pc=0x0c0c10ecu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10ee;
P_0c0c10ee: /* original 6e53, guest PC 0x0c0c10ee */
if(!s->budget--) { s->failed_pc=0x0c0c10eeu; return 0; }
r[14]=r[5];
goto P_0c0c10f0;
P_0c0c10f0: /* original 7501, guest PC 0x0c0c10f0 */
if(!s->budget--) { s->failed_pc=0x0c0c10f0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10f2;
P_0c0c10f2: /* original 9370, guest PC 0x0c0c10f2 */
if(!s->budget--) { s->failed_pc=0x0c0c10f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d6u,2);
goto P_0c0c10f4;
P_0c0c10f4: /* original 2438, guest PC 0x0c0c10f4 */
if(!s->budget--) { s->failed_pc=0x0c0c10f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c10f6;
P_0c0c10f6: /* original 8901, guest PC 0x0c0c10f6 */
if(!s->budget--) { s->failed_pc=0x0c0c10f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10fc; }
goto P_0c0c10f8;
P_0c0c10f8: /* original a001, guest PC 0x0c0c10f8 */
if(!s->budget--) { s->failed_pc=0x0c0c10f8u; return 0; }
r[4]=r[6];
goto P_0c0c10fe;
P_0c0c10fa: /* original 6463, guest PC 0x0c0c10fa */
if(!s->budget--) { s->failed_pc=0x0c0c10fau; return 0; }
r[4]=r[6];
goto P_0c0c10fc;
P_0c0c10fc: /* original 6453, guest PC 0x0c0c10fc */
if(!s->budget--) { s->failed_pc=0x0c0c10fcu; return 0; }
r[4]=r[5];
goto P_0c0c10fe;
P_0c0c10fe: /* original 63f2, guest PC 0x0c0c10fe */
if(!s->budget--) { s->failed_pc=0x0c0c10feu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1100;
P_0c0c1100: /* original e026, guest PC 0x0c0c1100 */
if(!s->budget--) { s->failed_pc=0x0c0c1100u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1102;
P_0c0c1102: /* original 0375, guest PC 0x0c0c1102 */
if(!s->budget--) { s->failed_pc=0x0c0c1102u; return 0; }
write(ram,r[3]+r[0],r[7],2);
goto P_0c0c1104;
P_0c0c1104: /* original e026, guest PC 0x0c0c1104 */
if(!s->budget--) { s->failed_pc=0x0c0c1104u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1106;
P_0c0c1106: /* original 53f3, guest PC 0x0c0c1106 */
if(!s->budget--) { s->failed_pc=0x0c0c1106u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1108;
P_0c0c1108: /* original 03d5, guest PC 0x0c0c1108 */
if(!s->budget--) { s->failed_pc=0x0c0c1108u; return 0; }
write(ram,r[3]+r[0],r[13],2);
goto P_0c0c110a;
P_0c0c110a: /* original e026, guest PC 0x0c0c110a */
if(!s->budget--) { s->failed_pc=0x0c0c110au; return 0; }
r[0]=0x00000026u;
goto P_0c0c110c;
P_0c0c110c: /* original 53f1, guest PC 0x0c0c110c */
if(!s->budget--) { s->failed_pc=0x0c0c110cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c110e;
P_0c0c110e: /* original 03e5, guest PC 0x0c0c110e */
if(!s->budget--) { s->failed_pc=0x0c0c110eu; return 0; }
write(ram,r[3]+r[0],r[14],2);
goto P_0c0c1110;
P_0c0c1110: /* original e026, guest PC 0x0c0c1110 */
if(!s->budget--) { s->failed_pc=0x0c0c1110u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1112;
P_0c0c1112: /* original 53f2, guest PC 0x0c0c1112 */
if(!s->budget--) { s->failed_pc=0x0c0c1112u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c1114;
P_0c0c1114: /* original 7f10, guest PC 0x0c0c1114 */
if(!s->budget--) { s->failed_pc=0x0c0c1114u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c1116;
P_0c0c1116: /* original 0345, guest PC 0x0c0c1116 */
if(!s->budget--) { s->failed_pc=0x0c0c1116u; return 0; }
write(ram,r[3]+r[0],r[4],2);
goto P_0c0c1118;
P_0c0c1118: /* original 6df6, guest PC 0x0c0c1118 */
if(!s->budget--) { s->failed_pc=0x0c0c1118u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c111a;
P_0c0c111a: /* original 000b, guest PC 0x0c0c111a */
if(!s->budget--) { s->failed_pc=0x0c0c111au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c111c: /* original 6ef6, guest PC 0x0c0c111c */
if(!s->budget--) { s->failed_pc=0x0c0c111cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c111eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
