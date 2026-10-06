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
int vf3_target_action_selector_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a92dau: goto P_0c0a92da;
case 0x0c0a92dcu: goto P_0c0a92dc;
case 0x0c0a92deu: goto P_0c0a92de;
case 0x0c0a92e0u: goto P_0c0a92e0;
case 0x0c0a92e2u: goto P_0c0a92e2;
case 0x0c0a92e4u: goto P_0c0a92e4;
case 0x0c0a92e6u: goto P_0c0a92e6;
case 0x0c0a92e8u: goto P_0c0a92e8;
case 0x0c0a92eau: goto P_0c0a92ea;
case 0x0c0a92ecu: goto P_0c0a92ec;
case 0x0c0a92eeu: goto P_0c0a92ee;
case 0x0c0a92f0u: goto P_0c0a92f0;
case 0x0c0a92f2u: goto P_0c0a92f2;
case 0x0c0a92f4u: goto P_0c0a92f4;
case 0x0c0a92f6u: goto P_0c0a92f6;
case 0x0c0a92f8u: goto P_0c0a92f8;
case 0x0c0a92fau: goto P_0c0a92fa;
case 0x0c0a92fcu: goto P_0c0a92fc;
case 0x0c0a92feu: goto P_0c0a92fe;
case 0x0c0a9300u: goto P_0c0a9300;
case 0x0c0a9302u: goto P_0c0a9302;
case 0x0c0a9304u: goto P_0c0a9304;
case 0x0c0a9306u: goto P_0c0a9306;
case 0x0c0a9308u: goto P_0c0a9308;
case 0x0c0a930au: goto P_0c0a930a;
case 0x0c0a930cu: goto P_0c0a930c;
case 0x0c0a930eu: goto P_0c0a930e;
case 0x0c0a9310u: goto P_0c0a9310;
case 0x0c0a9312u: goto P_0c0a9312;
case 0x0c0a9314u: goto P_0c0a9314;
case 0x0c0a9316u: goto P_0c0a9316;
case 0x0c0a9318u: goto P_0c0a9318;
case 0x0c0a931au: goto P_0c0a931a;
case 0x0c0a931cu: goto P_0c0a931c;
case 0x0c0a931eu: goto P_0c0a931e;
case 0x0c0a9320u: goto P_0c0a9320;
case 0x0c0a9322u: goto P_0c0a9322;
case 0x0c0a9324u: goto P_0c0a9324;
case 0x0c0a9326u: goto P_0c0a9326;
case 0x0c0a9328u: goto P_0c0a9328;
case 0x0c0a932au: goto P_0c0a932a;
case 0x0c0a932cu: goto P_0c0a932c;
case 0x0c0a932eu: goto P_0c0a932e;
case 0x0c0a9330u: goto P_0c0a9330;
case 0x0c0a9332u: goto P_0c0a9332;
case 0x0c0a9334u: goto P_0c0a9334;
case 0x0c0a9336u: goto P_0c0a9336;
case 0x0c0a9338u: goto P_0c0a9338;
case 0x0c0a933au: goto P_0c0a933a;
case 0x0c0a933cu: goto P_0c0a933c;
case 0x0c0a933eu: goto P_0c0a933e;
case 0x0c0a9340u: goto P_0c0a9340;
case 0x0c0a9342u: goto P_0c0a9342;
case 0x0c0a9344u: goto P_0c0a9344;
case 0x0c0a9346u: goto P_0c0a9346;
case 0x0c0a9348u: goto P_0c0a9348;
case 0x0c0a934au: goto P_0c0a934a;
case 0x0c0a934cu: goto P_0c0a934c;
case 0x0c0a934eu: goto P_0c0a934e;
case 0x0c0a9350u: goto P_0c0a9350;
case 0x0c0a9352u: goto P_0c0a9352;
case 0x0c0a9354u: goto P_0c0a9354;
case 0x0c0a9356u: goto P_0c0a9356;
case 0x0c0a9358u: goto P_0c0a9358;
case 0x0c0a935au: goto P_0c0a935a;
case 0x0c0a935cu: goto P_0c0a935c;
case 0x0c0a935eu: goto P_0c0a935e;
case 0x0c0a9360u: goto P_0c0a9360;
case 0x0c0a9362u: goto P_0c0a9362;
case 0x0c0a9364u: goto P_0c0a9364;
case 0x0c0a9366u: goto P_0c0a9366;
case 0x0c0a9368u: goto P_0c0a9368;
case 0x0c0a936au: goto P_0c0a936a;
case 0x0c0a936cu: goto P_0c0a936c;
case 0x0c0a936eu: goto P_0c0a936e;
case 0x0c0a9370u: goto P_0c0a9370;
case 0x0c0a9372u: goto P_0c0a9372;
case 0x0c0a9374u: goto P_0c0a9374;
case 0x0c0a9376u: goto P_0c0a9376;
case 0x0c0a9378u: goto P_0c0a9378;
case 0x0c0a937au: goto P_0c0a937a;
case 0x0c0a937cu: goto P_0c0a937c;
case 0x0c0a937eu: goto P_0c0a937e;
case 0x0c0a9380u: goto P_0c0a9380;
case 0x0c0a9382u: goto P_0c0a9382;
case 0x0c0a9384u: goto P_0c0a9384;
case 0x0c0a9386u: goto P_0c0a9386;
case 0x0c0a9388u: goto P_0c0a9388;
case 0x0c0a938au: goto P_0c0a938a;
case 0x0c0a938cu: goto P_0c0a938c;
case 0x0c0a938eu: goto P_0c0a938e;
case 0x0c0a9390u: goto P_0c0a9390;
case 0x0c0a9392u: goto P_0c0a9392;
case 0x0c0a9394u: goto P_0c0a9394;
case 0x0c0a9396u: goto P_0c0a9396;
case 0x0c0a9398u: goto P_0c0a9398;
case 0x0c0a939au: goto P_0c0a939a;
case 0x0c0a939cu: goto P_0c0a939c;
case 0x0c0a93c8u: goto P_0c0a93c8;
case 0x0c0a93cau: goto P_0c0a93ca;
case 0x0c0a93ccu: goto P_0c0a93cc;
case 0x0c0a93ceu: goto P_0c0a93ce;
case 0x0c0a93d0u: goto P_0c0a93d0;
case 0x0c0a93d2u: goto P_0c0a93d2;
case 0x0c0a93d4u: goto P_0c0a93d4;
case 0x0c0a93d6u: goto P_0c0a93d6;
case 0x0c0a93d8u: goto P_0c0a93d8;
case 0x0c0a93dau: goto P_0c0a93da;
case 0x0c0a93dcu: goto P_0c0a93dc;
case 0x0c0a93deu: goto P_0c0a93de;
case 0x0c0a93e0u: goto P_0c0a93e0;
case 0x0c0a93e2u: goto P_0c0a93e2;
case 0x0c0a93e4u: goto P_0c0a93e4;
case 0x0c0a93e6u: goto P_0c0a93e6;
case 0x0c0a93e8u: goto P_0c0a93e8;
case 0x0c0a93eau: goto P_0c0a93ea;
case 0x0c0a93ecu: goto P_0c0a93ec;
case 0x0c0a93eeu: goto P_0c0a93ee;
case 0x0c0a93f0u: goto P_0c0a93f0;
case 0x0c0a93f2u: goto P_0c0a93f2;
case 0x0c0a93f4u: goto P_0c0a93f4;
case 0x0c0a93f6u: goto P_0c0a93f6;
case 0x0c0a93f8u: goto P_0c0a93f8;
case 0x0c0a93fau: goto P_0c0a93fa;
case 0x0c0a93fcu: goto P_0c0a93fc;
case 0x0c0a93feu: goto P_0c0a93fe;
case 0x0c0a9400u: goto P_0c0a9400;
case 0x0c0a9402u: goto P_0c0a9402;
case 0x0c0a9404u: goto P_0c0a9404;
case 0x0c0a9406u: goto P_0c0a9406;
case 0x0c0a9408u: goto P_0c0a9408;
case 0x0c0a940au: goto P_0c0a940a;
case 0x0c0a940cu: goto P_0c0a940c;
case 0x0c0a940eu: goto P_0c0a940e;
case 0x0c0a9410u: goto P_0c0a9410;
case 0x0c0a9412u: goto P_0c0a9412;
case 0x0c0a9414u: goto P_0c0a9414;
case 0x0c0a9416u: goto P_0c0a9416;
case 0x0c0a9418u: goto P_0c0a9418;
case 0x0c0a941au: goto P_0c0a941a;
case 0x0c0a941cu: goto P_0c0a941c;
case 0x0c0a941eu: goto P_0c0a941e;
case 0x0c0a9420u: goto P_0c0a9420;
case 0x0c0a9422u: goto P_0c0a9422;
case 0x0c0a9424u: goto P_0c0a9424;
case 0x0c0a9426u: goto P_0c0a9426;
case 0x0c0a9428u: goto P_0c0a9428;
case 0x0c0a942au: goto P_0c0a942a;
case 0x0c0a942cu: goto P_0c0a942c;
case 0x0c0a942eu: goto P_0c0a942e;
case 0x0c0a9430u: goto P_0c0a9430;
case 0x0c0a9432u: goto P_0c0a9432;
case 0x0c0a9434u: goto P_0c0a9434;
case 0x0c0a9436u: goto P_0c0a9436;
case 0x0c0a9438u: goto P_0c0a9438;
case 0x0c0a943au: goto P_0c0a943a;
case 0x0c0a943cu: goto P_0c0a943c;
case 0x0c0a943eu: goto P_0c0a943e;
case 0x0c0a9440u: goto P_0c0a9440;
case 0x0c0a9442u: goto P_0c0a9442;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a92da: /* original 4f22, guest PC 0x0c0a92da */
if(!s->budget--) { s->failed_pc=0x0c0a92dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a92dc;
P_0c0a92dc: /* original 04d4, guest PC 0x0c0a92dc */
if(!s->budget--) { s->failed_pc=0x0c0a92dcu; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0a92de;
P_0c0a92de: /* original 06d4, guest PC 0x0c0a92de */
if(!s->budget--) { s->failed_pc=0x0c0a92deu; return 0; }
write(ram,r[6]+r[0],r[13],1);
goto P_0c0a92e0;
P_0c0a92e0: /* original 84e4, guest PC 0x0c0a92e0 */
if(!s->budget--) { s->failed_pc=0x0c0a92e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0a92e2;
P_0c0a92e2: /* original 7ffc, guest PC 0x0c0a92e2 */
if(!s->budget--) { s->failed_pc=0x0c0a92e2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a92e4;
P_0c0a92e4: /* original d335, guest PC 0x0c0a92e4 */
if(!s->budget--) { s->failed_pc=0x0c0a92e4u; return 0; }
r[3]=read(ram,0x0c0a93bcu,4);
goto P_0c0a92e6;
P_0c0a92e6: /* original 660e, guest PC 0x0c0a92e6 */
if(!s->budget--) { s->failed_pc=0x0c0a92e6u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0a92e8;
P_0c0a92e8: /* original 2668, guest PC 0x0c0a92e8 */
if(!s->budget--) { s->failed_pc=0x0c0a92e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a92ea;
P_0c0a92ea: /* original 8d01, guest PC 0x0c0a92ea */
if(!s->budget--) { s->failed_pc=0x0c0a92eau; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(cond) { goto P_0c0a92f0; }
goto P_0c0a92ee;
P_0c0a92ec: /* original 6432, guest PC 0x0c0a92ec */
if(!s->budget--) { s->failed_pc=0x0c0a92ecu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0a92ee;
P_0c0a92ee: /* original 4419, guest PC 0x0c0a92ee */
if(!s->budget--) { s->failed_pc=0x0c0a92eeu; return 0; }
r[4]>>=8;
goto P_0c0a92f0;
P_0c0a92f0: /* original e061, guest PC 0x0c0a92f0 */
if(!s->budget--) { s->failed_pc=0x0c0a92f0u; return 0; }
r[0]=0x00000061u;
goto P_0c0a92f2;
P_0c0a92f2: /* original 03ec, guest PC 0x0c0a92f2 */
if(!s->budget--) { s->failed_pc=0x0c0a92f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a92f4;
P_0c0a92f4: /* original 2f30, guest PC 0x0c0a92f4 */
if(!s->budget--) { s->failed_pc=0x0c0a92f4u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0a92f6;
P_0c0a92f6: /* original 67f0, guest PC 0x0c0a92f6 */
if(!s->budget--) { s->failed_pc=0x0c0a92f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[7]=tmp;
goto P_0c0a92f8;
P_0c0a92f8: /* original 6073, guest PC 0x0c0a92f8 */
if(!s->budget--) { s->failed_pc=0x0c0a92f8u; return 0; }
r[0]=r[7];
goto P_0c0a92fa;
P_0c0a92fa: /* original 8803, guest PC 0x0c0a92fa */
if(!s->budget--) { s->failed_pc=0x0c0a92fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a92fc;
P_0c0a92fc: /* original 8d03, guest PC 0x0c0a92fc */
if(!s->budget--) { s->failed_pc=0x0c0a92fcu; return 0; }
cond=r[17]&1u;
r[6]=r[4];
if(cond) { goto P_0c0a9306; }
goto P_0c0a9300;
P_0c0a92fe: /* original 6643, guest PC 0x0c0a92fe */
if(!s->budget--) { s->failed_pc=0x0c0a92feu; return 0; }
r[6]=r[4];
goto P_0c0a9300;
P_0c0a9300: /* original 6073, guest PC 0x0c0a9300 */
if(!s->budget--) { s->failed_pc=0x0c0a9300u; return 0; }
r[0]=r[7];
goto P_0c0a9302;
P_0c0a9302: /* original 8801, guest PC 0x0c0a9302 */
if(!s->budget--) { s->failed_pc=0x0c0a9302u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9304;
P_0c0a9304: /* original 8b11, guest PC 0x0c0a9304 */
if(!s->budget--) { s->failed_pc=0x0c0a9304u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a932a; }
goto P_0c0a9306;
P_0c0a9306: /* original d32e, guest PC 0x0c0a9306 */
if(!s->budget--) { s->failed_pc=0x0c0a9306u; return 0; }
r[3]=read(ram,0x0c0a93c0u,4);
goto P_0c0a9308;
P_0c0a9308: /* original 924a, guest PC 0x0c0a9308 */
if(!s->budget--) { s->failed_pc=0x0c0a9308u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a0u,2);
goto P_0c0a930a;
P_0c0a930a: /* original 2439, guest PC 0x0c0a930a */
if(!s->budget--) { s->failed_pc=0x0c0a930au; return 0; }
r[4]&=r[3];
goto P_0c0a930c;
P_0c0a930c: /* original 3420, guest PC 0x0c0a930c */
if(!s->budget--) { s->failed_pc=0x0c0a930cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0a930e;
P_0c0a930e: /* original 8b0c, guest PC 0x0c0a930e */
if(!s->budget--) { s->failed_pc=0x0c0a930eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a932a; }
goto P_0c0a9310;
P_0c0a9310: /* original 9047, guest PC 0x0c0a9310 */
if(!s->budget--) { s->failed_pc=0x0c0a9310u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a2u,2);
goto P_0c0a9312;
P_0c0a9312: /* original e31c, guest PC 0x0c0a9312 */
if(!s->budget--) { s->failed_pc=0x0c0a9312u; return 0; }
r[3]=0x0000001cu;
goto P_0c0a9314;
P_0c0a9314: /* original 54c8, guest PC 0x0c0a9314 */
if(!s->budget--) { s->failed_pc=0x0c0a9314u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c0a9316;
P_0c0a9316: /* original 0436, guest PC 0x0c0a9316 */
if(!s->budget--) { s->failed_pc=0x0c0a9316u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0a9318;
P_0c0a9318: /* original 9041, guest PC 0x0c0a9318 */
if(!s->budget--) { s->failed_pc=0x0c0a9318u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a939eu,2);
goto P_0c0a931a;
P_0c0a931a: /* original 0ed4, guest PC 0x0c0a931a */
if(!s->budget--) { s->failed_pc=0x0c0a931au; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a931c;
P_0c0a931c: /* original 6073, guest PC 0x0c0a931c */
if(!s->budget--) { s->failed_pc=0x0c0a931cu; return 0; }
r[0]=r[7];
goto P_0c0a931e;
P_0c0a931e: /* original 9441, guest PC 0x0c0a931e */
if(!s->budget--) { s->failed_pc=0x0c0a931eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a4u,2);
goto P_0c0a9320;
P_0c0a9320: /* original 8803, guest PC 0x0c0a9320 */
if(!s->budget--) { s->failed_pc=0x0c0a9320u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a9322;
P_0c0a9322: /* original 8971, guest PC 0x0c0a9322 */
if(!s->budget--) { s->failed_pc=0x0c0a9322u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9408; }
goto P_0c0a9324;
P_0c0a9324: /* original 943f, guest PC 0x0c0a9324 */
if(!s->budget--) { s->failed_pc=0x0c0a9324u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a6u,2);
goto P_0c0a9326;
P_0c0a9326: /* original a06f, guest PC 0x0c0a9326 */
if(!s->budget--) { s->failed_pc=0x0c0a9326u; return 0; }
goto P_0c0a9408;
P_0c0a9328: /* original 0009, guest PC 0x0c0a9328 */
if(!s->budget--) { s->failed_pc=0x0c0a9328u; return 0; }
goto P_0c0a932a;
P_0c0a932a: /* original d726, guest PC 0x0c0a932a */
if(!s->budget--) { s->failed_pc=0x0c0a932au; return 0; }
r[7]=read(ram,0x0c0a93c4u,4);
goto P_0c0a932c;
P_0c0a932c: /* original e018, guest PC 0x0c0a932c */
if(!s->budget--) { s->failed_pc=0x0c0a932cu; return 0; }
r[0]=0x00000018u;
goto P_0c0a932e;
P_0c0a932e: /* original 047c, guest PC 0x0c0a932e */
if(!s->budget--) { s->failed_pc=0x0c0a932eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0a9330;
P_0c0a9330: /* original 2448, guest PC 0x0c0a9330 */
if(!s->budget--) { s->failed_pc=0x0c0a9330u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9332;
P_0c0a9332: /* original 8b17, guest PC 0x0c0a9332 */
if(!s->budget--) { s->failed_pc=0x0c0a9332u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9364; }
goto P_0c0a9334;
P_0c0a9334: /* original 6403, guest PC 0x0c0a9334 */
if(!s->budget--) { s->failed_pc=0x0c0a9334u; return 0; }
r[4]=r[0];
goto P_0c0a9336;
P_0c0a9336: /* original 9037, guest PC 0x0c0a9336 */
if(!s->budget--) { s->failed_pc=0x0c0a9336u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a8u,2);
goto P_0c0a9338;
P_0c0a9338: /* original 02ed, guest PC 0x0c0a9338 */
if(!s->budget--) { s->failed_pc=0x0c0a9338u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a933a;
P_0c0a933a: /* original e046, guest PC 0x0c0a933a */
if(!s->budget--) { s->failed_pc=0x0c0a933au; return 0; }
r[0]=0x00000046u;
goto P_0c0a933c;
P_0c0a933c: /* original 03ed, guest PC 0x0c0a933c */
if(!s->budget--) { s->failed_pc=0x0c0a933cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a933e;
P_0c0a933e: /* original 633d, guest PC 0x0c0a933e */
if(!s->budget--) { s->failed_pc=0x0c0a933eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a9340;
P_0c0a9340: /* original 3230, guest PC 0x0c0a9340 */
if(!s->budget--) { s->failed_pc=0x0c0a9340u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0a9342;
P_0c0a9342: /* original 8b0f, guest PC 0x0c0a9342 */
if(!s->budget--) { s->failed_pc=0x0c0a9342u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9364; }
goto P_0c0a9344;
P_0c0a9344: /* original e061, guest PC 0x0c0a9344 */
if(!s->budget--) { s->failed_pc=0x0c0a9344u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9346;
P_0c0a9346: /* original 025c, guest PC 0x0c0a9346 */
if(!s->budget--) { s->failed_pc=0x0c0a9346u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a9348;
P_0c0a9348: /* original 2228, guest PC 0x0c0a9348 */
if(!s->budget--) { s->failed_pc=0x0c0a9348u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a934a;
P_0c0a934a: /* original 8b4d, guest PC 0x0c0a934a */
if(!s->budget--) { s->failed_pc=0x0c0a934au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a93e8; }
goto P_0c0a934c;
P_0c0a934c: /* original 00ec, guest PC 0x0c0a934c */
if(!s->budget--) { s->failed_pc=0x0c0a934cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a934e;
P_0c0a934e: /* original 600c, guest PC 0x0c0a934e */
if(!s->budget--) { s->failed_pc=0x0c0a934eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9350;
P_0c0a9350: /* original 8806, guest PC 0x0c0a9350 */
if(!s->budget--) { s->failed_pc=0x0c0a9350u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0a9352;
P_0c0a9352: /* original 8b49, guest PC 0x0c0a9352 */
if(!s->budget--) { s->failed_pc=0x0c0a9352u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a93e8; }
goto P_0c0a9354;
P_0c0a9354: /* original 9025, guest PC 0x0c0a9354 */
if(!s->budget--) { s->failed_pc=0x0c0a9354u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a2u,2);
goto P_0c0a9356;
P_0c0a9356: /* original e31c, guest PC 0x0c0a9356 */
if(!s->budget--) { s->failed_pc=0x0c0a9356u; return 0; }
r[3]=0x0000001cu;
goto P_0c0a9358;
P_0c0a9358: /* original 54c8, guest PC 0x0c0a9358 */
if(!s->budget--) { s->failed_pc=0x0c0a9358u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c0a935a;
P_0c0a935a: /* original 0436, guest PC 0x0c0a935a */
if(!s->budget--) { s->failed_pc=0x0c0a935au; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0a935c;
P_0c0a935c: /* original 9425, guest PC 0x0c0a935c */
if(!s->budget--) { s->failed_pc=0x0c0a935cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93aau,2);
goto P_0c0a935e;
P_0c0a935e: /* original 901e, guest PC 0x0c0a935e */
if(!s->budget--) { s->failed_pc=0x0c0a935eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a939eu,2);
goto P_0c0a9360;
P_0c0a9360: /* original a052, guest PC 0x0c0a9360 */
if(!s->budget--) { s->failed_pc=0x0c0a9360u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a9408;
P_0c0a9362: /* original 0ed4, guest PC 0x0c0a9362 */
if(!s->budget--) { s->failed_pc=0x0c0a9362u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a9364;
P_0c0a9364: /* original 9422, guest PC 0x0c0a9364 */
if(!s->budget--) { s->failed_pc=0x0c0a9364u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93acu,2);
goto P_0c0a9366;
P_0c0a9366: /* original 6263, guest PC 0x0c0a9366 */
if(!s->budget--) { s->failed_pc=0x0c0a9366u; return 0; }
r[2]=r[6];
goto P_0c0a9368;
P_0c0a9368: /* original 2249, guest PC 0x0c0a9368 */
if(!s->budget--) { s->failed_pc=0x0c0a9368u; return 0; }
r[2]&=r[4];
goto P_0c0a936a;
P_0c0a936a: /* original 3240, guest PC 0x0c0a936a */
if(!s->budget--) { s->failed_pc=0x0c0a936au; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c0a936c;
P_0c0a936c: /* original 8b01, guest PC 0x0c0a936c */
if(!s->budget--) { s->failed_pc=0x0c0a936cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9372; }
goto P_0c0a936e;
P_0c0a936e: /* original a03b, guest PC 0x0c0a936e */
if(!s->budget--) { s->failed_pc=0x0c0a936eu; return 0; }
r[4]=0x00000010u;
goto P_0c0a93e8;
P_0c0a9370: /* original e410, guest PC 0x0c0a9370 */
if(!s->budget--) { s->failed_pc=0x0c0a9370u; return 0; }
r[4]=0x00000010u;
goto P_0c0a9372;
P_0c0a9372: /* original 941c, guest PC 0x0c0a9372 */
if(!s->budget--) { s->failed_pc=0x0c0a9372u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93aeu,2);
goto P_0c0a9374;
P_0c0a9374: /* original 6263, guest PC 0x0c0a9374 */
if(!s->budget--) { s->failed_pc=0x0c0a9374u; return 0; }
r[2]=r[6];
goto P_0c0a9376;
P_0c0a9376: /* original 2249, guest PC 0x0c0a9376 */
if(!s->budget--) { s->failed_pc=0x0c0a9376u; return 0; }
r[2]&=r[4];
goto P_0c0a9378;
P_0c0a9378: /* original 3240, guest PC 0x0c0a9378 */
if(!s->budget--) { s->failed_pc=0x0c0a9378u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c0a937a;
P_0c0a937a: /* original 8b01, guest PC 0x0c0a937a */
if(!s->budget--) { s->failed_pc=0x0c0a937au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9380; }
goto P_0c0a937c;
P_0c0a937c: /* original a034, guest PC 0x0c0a937c */
if(!s->budget--) { s->failed_pc=0x0c0a937cu; return 0; }
r[4]=0x00000014u;
goto P_0c0a93e8;
P_0c0a937e: /* original e414, guest PC 0x0c0a937e */
if(!s->budget--) { s->failed_pc=0x0c0a937eu; return 0; }
r[4]=0x00000014u;
goto P_0c0a9380;
P_0c0a9380: /* original 9316, guest PC 0x0c0a9380 */
if(!s->budget--) { s->failed_pc=0x0c0a9380u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b0u,2);
goto P_0c0a9382;
P_0c0a9382: /* original 2368, guest PC 0x0c0a9382 */
if(!s->budget--) { s->failed_pc=0x0c0a9382u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0a9384;
P_0c0a9384: /* original 8901, guest PC 0x0c0a9384 */
if(!s->budget--) { s->failed_pc=0x0c0a9384u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a938a; }
goto P_0c0a9386;
P_0c0a9386: /* original a02f, guest PC 0x0c0a9386 */
if(!s->budget--) { s->failed_pc=0x0c0a9386u; return 0; }
r[4]=0x00000000u;
goto P_0c0a93e8;
P_0c0a9388: /* original e400, guest PC 0x0c0a9388 */
if(!s->budget--) { s->failed_pc=0x0c0a9388u; return 0; }
r[4]=0x00000000u;
goto P_0c0a938a;
P_0c0a938a: /* original 9312, guest PC 0x0c0a938a */
if(!s->budget--) { s->failed_pc=0x0c0a938au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b2u,2);
goto P_0c0a938c;
P_0c0a938c: /* original 2368, guest PC 0x0c0a938c */
if(!s->budget--) { s->failed_pc=0x0c0a938cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0a938e;
P_0c0a938e: /* original 8901, guest PC 0x0c0a938e */
if(!s->budget--) { s->failed_pc=0x0c0a938eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9394; }
goto P_0c0a9390;
P_0c0a9390: /* original a02a, guest PC 0x0c0a9390 */
if(!s->budget--) { s->failed_pc=0x0c0a9390u; return 0; }
r[4]=0x00000004u;
goto P_0c0a93e8;
P_0c0a9392: /* original e404, guest PC 0x0c0a9392 */
if(!s->budget--) { s->failed_pc=0x0c0a9392u; return 0; }
r[4]=0x00000004u;
goto P_0c0a9394;
P_0c0a9394: /* original 920e, guest PC 0x0c0a9394 */
if(!s->budget--) { s->failed_pc=0x0c0a9394u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b4u,2);
goto P_0c0a9396;
P_0c0a9396: /* original 2268, guest PC 0x0c0a9396 */
if(!s->budget--) { s->failed_pc=0x0c0a9396u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0a9398;
P_0c0a9398: /* original 8916, guest PC 0x0c0a9398 */
if(!s->budget--) { s->failed_pc=0x0c0a9398u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a93c8; }
goto P_0c0a939a;
P_0c0a939a: /* original a025, guest PC 0x0c0a939a */
if(!s->budget--) { s->failed_pc=0x0c0a939au; return 0; }
r[4]=0x00000008u;
goto P_0c0a93e8;
P_0c0a939c: /* original e408, guest PC 0x0c0a939c */
if(!s->budget--) { s->failed_pc=0x0c0a939cu; return 0; }
r[4]=0x00000008u;
return vf3_matrix_family(0x0c0a939eu,s,ram);
P_0c0a93c8: /* original 926d, guest PC 0x0c0a93c8 */
if(!s->budget--) { s->failed_pc=0x0c0a93c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94a6u,2);
goto P_0c0a93ca;
P_0c0a93ca: /* original 2628, guest PC 0x0c0a93ca */
if(!s->budget--) { s->failed_pc=0x0c0a93cau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0a93cc;
P_0c0a93cc: /* original 8901, guest PC 0x0c0a93cc */
if(!s->budget--) { s->failed_pc=0x0c0a93ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a93d2; }
goto P_0c0a93ce;
P_0c0a93ce: /* original a00b, guest PC 0x0c0a93ce */
if(!s->budget--) { s->failed_pc=0x0c0a93ceu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a93e8;
P_0c0a93d0: /* original e40c, guest PC 0x0c0a93d0 */
if(!s->budget--) { s->failed_pc=0x0c0a93d0u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a93d2;
P_0c0a93d2: /* original d138, guest PC 0x0c0a93d2 */
if(!s->budget--) { s->failed_pc=0x0c0a93d2u; return 0; }
r[1]=read(ram,0x0c0a94b4u,4);
goto P_0c0a93d4;
P_0c0a93d4: /* original d336, guest PC 0x0c0a93d4 */
if(!s->budget--) { s->failed_pc=0x0c0a93d4u; return 0; }
r[3]=read(ram,0x0c0a94b0u,4);
goto P_0c0a93d6;
P_0c0a93d6: /* original 5472, guest PC 0x0c0a93d6 */
if(!s->budget--) { s->failed_pc=0x0c0a93d6u; return 0; }
r[4]=read(ram,r[7]+8,4);
goto P_0c0a93d8;
P_0c0a93d8: /* original 410b, guest PC 0x0c0a93d8 */
if(!s->budget--) { s->failed_pc=0x0c0a93d8u; return 0; }
target=r[1];
r[16]=0x0c0a93dcu;
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a93dcu) { target=s->pc; goto dispatch; }
goto P_0c0a93dc;
P_0c0a93da: /* original 2438, guest PC 0x0c0a93da */
if(!s->budget--) { s->failed_pc=0x0c0a93dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a93dc;
P_0c0a93dc: /* original d236, guest PC 0x0c0a93dc */
if(!s->budget--) { s->failed_pc=0x0c0a93dcu; return 0; }
r[2]=read(ram,0x0c0a94b8u,4);
goto P_0c0a93de;
P_0c0a93de: /* original 6103, guest PC 0x0c0a93de */
if(!s->budget--) { s->failed_pc=0x0c0a93deu; return 0; }
r[1]=r[0];
goto P_0c0a93e0;
P_0c0a93e0: /* original 420b, guest PC 0x0c0a93e0 */
if(!s->budget--) { s->failed_pc=0x0c0a93e0u; return 0; }
target=r[2];
r[16]=0x0c0a93e4u;
r[0]=0x00000006u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a93e4u) { target=s->pc; goto dispatch; }
goto P_0c0a93e4;
P_0c0a93e2: /* original e006, guest PC 0x0c0a93e2 */
if(!s->budget--) { s->failed_pc=0x0c0a93e2u; return 0; }
r[0]=0x00000006u;
goto P_0c0a93e4;
P_0c0a93e4: /* original 6403, guest PC 0x0c0a93e4 */
if(!s->budget--) { s->failed_pc=0x0c0a93e4u; return 0; }
r[4]=r[0];
goto P_0c0a93e6;
P_0c0a93e6: /* original 4408, guest PC 0x0c0a93e6 */
if(!s->budget--) { s->failed_pc=0x0c0a93e6u; return 0; }
r[4]<<=2;
goto P_0c0a93e8;
P_0c0a93e8: /* original 905e, guest PC 0x0c0a93e8 */
if(!s->budget--) { s->failed_pc=0x0c0a93e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94a8u,2);
goto P_0c0a93ea;
P_0c0a93ea: /* original 55c8, guest PC 0x0c0a93ea */
if(!s->budget--) { s->failed_pc=0x0c0a93eau; return 0; }
r[5]=read(ram,r[12]+32,4);
goto P_0c0a93ec;
P_0c0a93ec: /* original 0546, guest PC 0x0c0a93ec */
if(!s->budget--) { s->failed_pc=0x0c0a93ecu; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0a93ee;
P_0c0a93ee: /* original 4409, guest PC 0x0c0a93ee */
if(!s->budget--) { s->failed_pc=0x0c0a93eeu; return 0; }
r[4]>>=2;
goto P_0c0a93f0;
P_0c0a93f0: /* original 905b, guest PC 0x0c0a93f0 */
if(!s->budget--) { s->failed_pc=0x0c0a93f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94aau,2);
goto P_0c0a93f2;
P_0c0a93f2: /* original 6543, guest PC 0x0c0a93f2 */
if(!s->budget--) { s->failed_pc=0x0c0a93f2u; return 0; }
r[5]=r[4];
goto P_0c0a93f4;
P_0c0a93f4: /* original 4508, guest PC 0x0c0a93f4 */
if(!s->budget--) { s->failed_pc=0x0c0a93f4u; return 0; }
r[5]<<=2;
goto P_0c0a93f6;
P_0c0a93f6: /* original 0ed4, guest PC 0x0c0a93f6 */
if(!s->budget--) { s->failed_pc=0x0c0a93f6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a93f8;
P_0c0a93f8: /* original d030, guest PC 0x0c0a93f8 */
if(!s->budget--) { s->failed_pc=0x0c0a93f8u; return 0; }
r[0]=read(ram,0x0c0a94bcu,4);
goto P_0c0a93fa;
P_0c0a93fa: /* original 055e, guest PC 0x0c0a93fa */
if(!s->budget--) { s->failed_pc=0x0c0a93fau; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0a93fc;
P_0c0a93fc: /* original e061, guest PC 0x0c0a93fc */
if(!s->budget--) { s->failed_pc=0x0c0a93fcu; return 0; }
r[0]=0x00000061u;
goto P_0c0a93fe;
P_0c0a93fe: /* original 00ec, guest PC 0x0c0a93fe */
if(!s->budget--) { s->failed_pc=0x0c0a93feu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a9400;
P_0c0a9400: /* original 600c, guest PC 0x0c0a9400 */
if(!s->budget--) { s->failed_pc=0x0c0a9400u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9402;
P_0c0a9402: /* original 4000, guest PC 0x0c0a9402 */
if(!s->budget--) { s->failed_pc=0x0c0a9402u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0a9404;
P_0c0a9404: /* original 045d, guest PC 0x0c0a9404 */
if(!s->budget--) { s->failed_pc=0x0c0a9404u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a9406;
P_0c0a9406: /* original 644d, guest PC 0x0c0a9406 */
if(!s->budget--) { s->failed_pc=0x0c0a9406u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9408;
P_0c0a9408: /* original e03c, guest PC 0x0c0a9408 */
if(!s->budget--) { s->failed_pc=0x0c0a9408u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a940a;
P_0c0a940a: /* original 0e45, guest PC 0x0c0a940a */
if(!s->budget--) { s->failed_pc=0x0c0a940au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a940c;
P_0c0a940c: /* original e03e, guest PC 0x0c0a940c */
if(!s->budget--) { s->failed_pc=0x0c0a940cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a940e;
P_0c0a940e: /* original 1e4d, guest PC 0x0c0a940e */
if(!s->budget--) { s->failed_pc=0x0c0a940eu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c0a9410;
P_0c0a9410: /* original 0ed5, guest PC 0x0c0a9410 */
if(!s->budget--) { s->failed_pc=0x0c0a9410u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0a9412;
P_0c0a9412: /* original e010, guest PC 0x0c0a9412 */
if(!s->budget--) { s->failed_pc=0x0c0a9412u; return 0; }
r[0]=0x00000010u;
goto P_0c0a9414;
P_0c0a9414: /* original f4e6, guest PC 0x0c0a9414 */
if(!s->budget--) { s->failed_pc=0x0c0a9414u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a9416;
P_0c0a9416: /* original e018, guest PC 0x0c0a9416 */
if(!s->budget--) { s->failed_pc=0x0c0a9416u; return 0; }
r[0]=0x00000018u;
goto P_0c0a9418;
P_0c0a9418: /* original d329, guest PC 0x0c0a9418 */
if(!s->budget--) { s->failed_pc=0x0c0a9418u; return 0; }
r[3]=read(ram,0x0c0a94c0u,4);
goto P_0c0a941a;
P_0c0a941a: /* original f5e6, guest PC 0x0c0a941a */
if(!s->budget--) { s->failed_pc=0x0c0a941au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a941c;
P_0c0a941c: /* original 430b, guest PC 0x0c0a941c */
if(!s->budget--) { s->failed_pc=0x0c0a941cu; return 0; }
target=r[3];
r[16]=0x0c0a9420u;
fr[5]^=0x80000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9420u) { target=s->pc; goto dispatch; }
goto P_0c0a9420;
P_0c0a941e: /* original f54d, guest PC 0x0c0a941e */
if(!s->budget--) { s->failed_pc=0x0c0a941eu; return 0; }
fr[5]^=0x80000000u;
goto P_0c0a9420;
P_0c0a9420: /* original e024, guest PC 0x0c0a9420 */
if(!s->budget--) { s->failed_pc=0x0c0a9420u; return 0; }
r[0]=0x00000024u;
goto P_0c0a9422;
P_0c0a9422: /* original f58d, guest PC 0x0c0a9422 */
if(!s->budget--) { s->failed_pc=0x0c0a9422u; return 0; }
fr[5]=0;
goto P_0c0a9424;
P_0c0a9424: /* original 7f04, guest PC 0x0c0a9424 */
if(!s->budget--) { s->failed_pc=0x0c0a9424u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a9426;
P_0c0a9426: /* original f40c, guest PC 0x0c0a9426 */
if(!s->budget--) { s->failed_pc=0x0c0a9426u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0a9428;
P_0c0a9428: /* original fe57, guest PC 0x0c0a9428 */
if(!s->budget--) { s->failed_pc=0x0c0a9428u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a942a;
P_0c0a942a: /* original e028, guest PC 0x0c0a942a */
if(!s->budget--) { s->failed_pc=0x0c0a942au; return 0; }
r[0]=0x00000028u;
goto P_0c0a942c;
P_0c0a942c: /* original fe57, guest PC 0x0c0a942c */
if(!s->budget--) { s->failed_pc=0x0c0a942cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a942e;
P_0c0a942e: /* original e02c, guest PC 0x0c0a942e */
if(!s->budget--) { s->failed_pc=0x0c0a942eu; return 0; }
r[0]=0x0000002cu;
goto P_0c0a9430;
P_0c0a9430: /* original 4f26, guest PC 0x0c0a9430 */
if(!s->budget--) { s->failed_pc=0x0c0a9430u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9432;
P_0c0a9432: /* original fe57, guest PC 0x0c0a9432 */
if(!s->budget--) { s->failed_pc=0x0c0a9432u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a9434;
P_0c0a9434: /* original e014, guest PC 0x0c0a9434 */
if(!s->budget--) { s->failed_pc=0x0c0a9434u; return 0; }
r[0]=0x00000014u;
goto P_0c0a9436;
P_0c0a9436: /* original fe47, guest PC 0x0c0a9436 */
if(!s->budget--) { s->failed_pc=0x0c0a9436u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9438;
P_0c0a9438: /* original 9038, guest PC 0x0c0a9438 */
if(!s->budget--) { s->failed_pc=0x0c0a9438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94acu,2);
goto P_0c0a943a;
P_0c0a943a: /* original fe47, guest PC 0x0c0a943a */
if(!s->budget--) { s->failed_pc=0x0c0a943au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a943c;
P_0c0a943c: /* original 6cf6, guest PC 0x0c0a943c */
if(!s->budget--) { s->failed_pc=0x0c0a943cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a943e;
P_0c0a943e: /* original 6df6, guest PC 0x0c0a943e */
if(!s->budget--) { s->failed_pc=0x0c0a943eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9440;
P_0c0a9440: /* original 000b, guest PC 0x0c0a9440 */
if(!s->budget--) { s->failed_pc=0x0c0a9440u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9442: /* original 6ef6, guest PC 0x0c0a9442 */
if(!s->budget--) { s->failed_pc=0x0c0a9442u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9444u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0a92dau,0x0c0a92dcu,0x0c0a92deu,0x0c0a92e0u,0x0c0a92e2u,0x0c0a92e4u,0x0c0a92e6u,0x0c0a92e8u,0x0c0a92eau,0x0c0a92ecu,0x0c0a92eeu,0x0c0a92f0u,0x0c0a92f2u,0x0c0a92f4u,0x0c0a92f6u,0x0c0a92f8u,
0x0c0a92fau,0x0c0a92fcu,0x0c0a92feu,0x0c0a9300u,0x0c0a9302u,0x0c0a9304u,0x0c0a9306u,0x0c0a9308u,0x0c0a930au,0x0c0a930cu,0x0c0a930eu,0x0c0a9310u,0x0c0a9312u,0x0c0a9314u,0x0c0a9316u,0x0c0a9318u,
0x0c0a931au,0x0c0a931cu,0x0c0a931eu,0x0c0a9320u,0x0c0a9322u,0x0c0a9324u,0x0c0a9326u,0x0c0a9328u,0x0c0a932au,0x0c0a932cu,0x0c0a932eu,0x0c0a9330u,0x0c0a9332u,0x0c0a9334u,0x0c0a9336u,0x0c0a9338u,
0x0c0a933au,0x0c0a933cu,0x0c0a933eu,0x0c0a9340u,0x0c0a9342u,0x0c0a9344u,0x0c0a9346u,0x0c0a9348u,0x0c0a934au,0x0c0a934cu,0x0c0a934eu,0x0c0a9350u,0x0c0a9352u,0x0c0a9354u,0x0c0a9356u,0x0c0a9358u,
0x0c0a935au,0x0c0a935cu,0x0c0a935eu,0x0c0a9360u,0x0c0a9362u,0x0c0a9364u,0x0c0a9366u,0x0c0a9368u,0x0c0a936au,0x0c0a936cu,0x0c0a936eu,0x0c0a9370u,0x0c0a9372u,0x0c0a9374u,0x0c0a9376u,0x0c0a9378u,
0x0c0a937au,0x0c0a937cu,0x0c0a937eu,0x0c0a9380u,0x0c0a9382u,0x0c0a9384u,0x0c0a9386u,0x0c0a9388u,0x0c0a938au,0x0c0a938cu,0x0c0a938eu,0x0c0a9390u,0x0c0a9392u,0x0c0a9394u,0x0c0a9396u,0x0c0a9398u,
0x0c0a939au,0x0c0a939cu,0x0c0a93c8u,0x0c0a93cau,0x0c0a93ccu,0x0c0a93ceu,0x0c0a93d0u,0x0c0a93d2u,0x0c0a93d4u,0x0c0a93d6u,0x0c0a93d8u,0x0c0a93dau,0x0c0a93dcu,0x0c0a93deu,0x0c0a93e0u,0x0c0a93e2u,
0x0c0a93e4u,0x0c0a93e6u,0x0c0a93e8u,0x0c0a93eau,0x0c0a93ecu,0x0c0a93eeu,0x0c0a93f0u,0x0c0a93f2u,0x0c0a93f4u,0x0c0a93f6u,0x0c0a93f8u,0x0c0a93fau,0x0c0a93fcu,0x0c0a93feu,0x0c0a9400u,0x0c0a9402u,
0x0c0a9404u,0x0c0a9406u,0x0c0a9408u,0x0c0a940au,0x0c0a940cu,0x0c0a940eu,0x0c0a9410u,0x0c0a9412u,0x0c0a9414u,0x0c0a9416u,0x0c0a9418u,0x0c0a941au,0x0c0a941cu,0x0c0a941eu,0x0c0a9420u,0x0c0a9422u,
0x0c0a9424u,0x0c0a9426u,0x0c0a9428u,0x0c0a942au,0x0c0a942cu,0x0c0a942eu,0x0c0a9430u,0x0c0a9432u,0x0c0a9434u,0x0c0a9436u,0x0c0a9438u,0x0c0a943au,0x0c0a943cu,0x0c0a943eu,0x0c0a9440u,0x0c0a9442u,
};
int vf3_target_action_selector_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
