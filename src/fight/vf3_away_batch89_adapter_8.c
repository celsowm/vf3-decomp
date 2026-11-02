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
int vf3_away_batch89_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0c66d8u: goto P_0c0c66d8;
case 0x0c0c66dau: goto P_0c0c66da;
case 0x0c0c6742u: goto P_0c0c6742;
case 0x0c0c6744u: goto P_0c0c6744;
case 0x0c0c6746u: goto P_0c0c6746;
case 0x0c0c6748u: goto P_0c0c6748;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0c66d8: /* original 000b, guest PC 0x0c0c66d8 */
if(!s->budget--) { s->failed_pc=0x0c0c66d8u; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c0c66da: /* original 2452, guest PC 0x0c0c66da */
if(!s->budget--) { s->failed_pc=0x0c0c66dau; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c0c66dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66dcu; return 0; } return 1;
P_0c0c6742: /* original 9049, guest PC 0x0c0c6742 */
if(!s->budget--) { s->failed_pc=0x0c0c6742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67d8u,2);
goto P_0c0c6744;
P_0c0c6744: /* original d426, guest PC 0x0c0c6744 */
if(!s->budget--) { s->failed_pc=0x0c0c6744u; return 0; }
r[4]=read(ram,0x0c0c67e0u,4);
goto P_0c0c6746;
P_0c0c6746: /* original 000b, guest PC 0x0c0c6746 */
if(!s->budget--) { s->failed_pc=0x0c0c6746u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c0c6748: /* original 004e, guest PC 0x0c0c6748 */
if(!s->budget--) { s->failed_pc=0x0c0c6748u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(0x0c0c674au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c674au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
