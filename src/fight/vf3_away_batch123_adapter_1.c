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
int vf3_away_batch123_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09d38eu: goto P_0c09d38e;
case 0x0c09d390u: goto P_0c09d390;
case 0x0c09d392u: goto P_0c09d392;
case 0x0c09d394u: goto P_0c09d394;
case 0x0c09d396u: goto P_0c09d396;
case 0x0c09d398u: goto P_0c09d398;
case 0x0c09d39au: goto P_0c09d39a;
case 0x0c09d39cu: goto P_0c09d39c;
case 0x0c09d39eu: goto P_0c09d39e;
case 0x0c09d3a0u: goto P_0c09d3a0;
case 0x0c09d3a2u: goto P_0c09d3a2;
case 0x0c09d3a4u: goto P_0c09d3a4;
case 0x0c09d3a6u: goto P_0c09d3a6;
case 0x0c09d3a8u: goto P_0c09d3a8;
case 0x0c09d3aau: goto P_0c09d3aa;
case 0x0c09d3acu: goto P_0c09d3ac;
case 0x0c09d3aeu: goto P_0c09d3ae;
case 0x0c09d3b0u: goto P_0c09d3b0;
case 0x0c09d3b2u: goto P_0c09d3b2;
case 0x0c09d3b4u: goto P_0c09d3b4;
case 0x0c09d3b6u: goto P_0c09d3b6;
case 0x0c09d3b8u: goto P_0c09d3b8;
case 0x0c09d3bau: goto P_0c09d3ba;
case 0x0c09d3bcu: goto P_0c09d3bc;
case 0x0c09d3beu: goto P_0c09d3be;
case 0x0c09d3c0u: goto P_0c09d3c0;
case 0x0c09d3c2u: goto P_0c09d3c2;
case 0x0c09d3c4u: goto P_0c09d3c4;
case 0x0c09d3c6u: goto P_0c09d3c6;
case 0x0c09d3c8u: goto P_0c09d3c8;
case 0x0c09d3cau: goto P_0c09d3ca;
case 0x0c09d3ccu: goto P_0c09d3cc;
case 0x0c09d3ceu: goto P_0c09d3ce;
case 0x0c09d3d0u: goto P_0c09d3d0;
case 0x0c09d3d2u: goto P_0c09d3d2;
case 0x0c09d3d4u: goto P_0c09d3d4;
case 0x0c09d3d6u: goto P_0c09d3d6;
case 0x0c09d3d8u: goto P_0c09d3d8;
case 0x0c09d3dau: goto P_0c09d3da;
case 0x0c09d3dcu: goto P_0c09d3dc;
case 0x0c09d3deu: goto P_0c09d3de;
case 0x0c09d3e0u: goto P_0c09d3e0;
case 0x0c09d3e2u: goto P_0c09d3e2;
case 0x0c09d3e4u: goto P_0c09d3e4;
case 0x0c0a1282u: goto P_0c0a1282;
case 0x0c0a1284u: goto P_0c0a1284;
case 0x0c0a1286u: goto P_0c0a1286;
case 0x0c0a1288u: goto P_0c0a1288;
case 0x0c0a128au: goto P_0c0a128a;
case 0x0c0a128cu: goto P_0c0a128c;
case 0x0c0a128eu: goto P_0c0a128e;
case 0x0c0a1290u: goto P_0c0a1290;
case 0x0c0a1292u: goto P_0c0a1292;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09d38e: /* original 2fe6, guest PC 0x0c09d38e */
if(!s->budget--) { s->failed_pc=0x0c09d38eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d390;
P_0c09d390: /* original d217, guest PC 0x0c09d390 */
if(!s->budget--) { s->failed_pc=0x0c09d390u; return 0; }
r[2]=read(ram,0x0c09d3f0u,4);
goto P_0c09d392;
P_0c09d392: /* original 7ffc, guest PC 0x0c09d392 */
if(!s->budget--) { s->failed_pc=0x0c09d392u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09d394;
P_0c09d394: /* original d01a, guest PC 0x0c09d394 */
if(!s->budget--) { s->failed_pc=0x0c09d394u; return 0; }
r[0]=read(ram,0x0c09d400u,4);
goto P_0c09d396;
P_0c09d396: /* original 6322, guest PC 0x0c09d396 */
if(!s->budget--) { s->failed_pc=0x0c09d396u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c09d398;
P_0c09d398: /* original d218, guest PC 0x0c09d398 */
if(!s->budget--) { s->failed_pc=0x0c09d398u; return 0; }
r[2]=read(ram,0x0c09d3fcu,4);
goto P_0c09d39a;
P_0c09d39a: /* original d61a, guest PC 0x0c09d39a */
if(!s->budget--) { s->failed_pc=0x0c09d39au; return 0; }
r[6]=read(ram,0x0c09d404u,4);
goto P_0c09d39c;
P_0c09d39c: /* original 2338, guest PC 0x0c09d39c */
if(!s->budget--) { s->failed_pc=0x0c09d39cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09d39e;
P_0c09d39e: /* original d416, guest PC 0x0c09d39e */
if(!s->budget--) { s->failed_pc=0x0c09d39eu; return 0; }
r[4]=read(ram,0x0c09d3f8u,4);
goto P_0c09d3a0;
P_0c09d3a0: /* original 6422, guest PC 0x0c09d3a0 */
if(!s->budget--) { s->failed_pc=0x0c09d3a0u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c09d3a2;
P_0c09d3a2: /* original 6563, guest PC 0x0c09d3a2 */
if(!s->budget--) { s->failed_pc=0x0c09d3a2u; return 0; }
r[5]=r[6];
goto P_0c09d3a4;
P_0c09d3a4: /* original d713, guest PC 0x0c09d3a4 */
if(!s->budget--) { s->failed_pc=0x0c09d3a4u; return 0; }
r[7]=read(ram,0x0c09d3f4u,4);
goto P_0c09d3a6;
P_0c09d3a6: /* original 4408, guest PC 0x0c09d3a6 */
if(!s->budget--) { s->failed_pc=0x0c09d3a6u; return 0; }
r[4]<<=2;
goto P_0c09d3a8;
P_0c09d3a8: /* original 6e43, guest PC 0x0c09d3a8 */
if(!s->budget--) { s->failed_pc=0x0c09d3a8u; return 0; }
r[14]=r[4];
goto P_0c09d3aa;
P_0c09d3aa: /* original 044e, guest PC 0x0c09d3aa */
if(!s->budget--) { s->failed_pc=0x0c09d3aau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09d3ac;
P_0c09d3ac: /* original 6063, guest PC 0x0c09d3ac */
if(!s->budget--) { s->failed_pc=0x0c09d3acu; return 0; }
r[0]=r[6];
goto P_0c09d3ae;
P_0c09d3ae: /* original 03ee, guest PC 0x0c09d3ae */
if(!s->budget--) { s->failed_pc=0x0c09d3aeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09d3b0;
P_0c09d3b0: /* original 3343, guest PC 0x0c09d3b0 */
if(!s->budget--) { s->failed_pc=0x0c09d3b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c09d3b2;
P_0c09d3b2: /* original 8d02, guest PC 0x0c09d3b2 */
if(!s->budget--) { s->failed_pc=0x0c09d3b2u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c09d3ba; }
goto P_0c09d3b6;
P_0c09d3b4: /* original 2f32, guest PC 0x0c09d3b4 */
if(!s->budget--) { s->failed_pc=0x0c09d3b4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09d3b6;
P_0c09d3b6: /* original 60e3, guest PC 0x0c09d3b6 */
if(!s->budget--) { s->failed_pc=0x0c09d3b6u; return 0; }
r[0]=r[14];
goto P_0c09d3b8;
P_0c09d3b8: /* original 0546, guest PC 0x0c09d3b8 */
if(!s->budget--) { s->failed_pc=0x0c09d3b8u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c09d3ba;
P_0c09d3ba: /* original d011, guest PC 0x0c09d3ba */
if(!s->budget--) { s->failed_pc=0x0c09d3bau; return 0; }
r[0]=read(ram,0x0c09d400u,4);
goto P_0c09d3bc;
P_0c09d3bc: /* original e100, guest PC 0x0c09d3bc */
if(!s->budget--) { s->failed_pc=0x0c09d3bcu; return 0; }
r[1]=0x00000000u;
goto P_0c09d3be;
P_0c09d3be: /* original e3ff, guest PC 0x0c09d3be */
if(!s->budget--) { s->failed_pc=0x0c09d3beu; return 0; }
r[3]=0xffffffffu;
goto P_0c09d3c0;
P_0c09d3c0: /* original 6413, guest PC 0x0c09d3c0 */
if(!s->budget--) { s->failed_pc=0x0c09d3c0u; return 0; }
r[4]=r[1];
goto P_0c09d3c2;
P_0c09d3c2: /* original 0e16, guest PC 0x0c09d3c2 */
if(!s->budget--) { s->failed_pc=0x0c09d3c2u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09d3c4;
P_0c09d3c4: /* original ee0d, guest PC 0x0c09d3c4 */
if(!s->budget--) { s->failed_pc=0x0c09d3c4u; return 0; }
r[14]=0x0000000du;
goto P_0c09d3c6;
P_0c09d3c6: /* original d20a, guest PC 0x0c09d3c6 */
if(!s->budget--) { s->failed_pc=0x0c09d3c6u; return 0; }
r[2]=read(ram,0x0c09d3f0u,4);
goto P_0c09d3c8;
P_0c09d3c8: /* original 6513, guest PC 0x0c09d3c8 */
if(!s->budget--) { s->failed_pc=0x0c09d3c8u; return 0; }
r[5]=r[1];
goto P_0c09d3ca;
P_0c09d3ca: /* original 2232, guest PC 0x0c09d3ca */
if(!s->budget--) { s->failed_pc=0x0c09d3cau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c09d3cc;
P_0c09d3cc: /* original 930e, guest PC 0x0c09d3cc */
if(!s->budget--) { s->failed_pc=0x0c09d3ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d3ecu,2);
goto P_0c09d3ce;
P_0c09d3ce: /* original 6043, guest PC 0x0c09d3ce */
if(!s->budget--) { s->failed_pc=0x0c09d3ceu; return 0; }
r[0]=r[4];
goto P_0c09d3d0;
P_0c09d3d0: /* original 026e, guest PC 0x0c09d3d0 */
if(!s->budget--) { s->failed_pc=0x0c09d3d0u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c09d3d2;
P_0c09d3d2: /* original 7501, guest PC 0x0c09d3d2 */
if(!s->budget--) { s->failed_pc=0x0c09d3d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c09d3d4;
P_0c09d3d4: /* original 337c, guest PC 0x0c09d3d4 */
if(!s->budget--) { s->failed_pc=0x0c09d3d4u; return 0; }
r[3]+=r[7];
goto P_0c09d3d6;
P_0c09d3d6: /* original 35e3, guest PC 0x0c09d3d6 */
if(!s->budget--) { s->failed_pc=0x0c09d3d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c09d3d8;
P_0c09d3d8: /* original 334c, guest PC 0x0c09d3d8 */
if(!s->budget--) { s->failed_pc=0x0c09d3d8u; return 0; }
r[3]+=r[4];
goto P_0c09d3da;
P_0c09d3da: /* original 2322, guest PC 0x0c09d3da */
if(!s->budget--) { s->failed_pc=0x0c09d3dau; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09d3dc;
P_0c09d3dc: /* original 8ff6, guest PC 0x0c09d3dc */
if(!s->budget--) { s->failed_pc=0x0c09d3dcu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c09d3cc; }
goto P_0c09d3e0;
P_0c09d3de: /* original 7404, guest PC 0x0c09d3de */
if(!s->budget--) { s->failed_pc=0x0c09d3deu; return 0; }
r[4]+=0x00000004u;
goto P_0c09d3e0;
P_0c09d3e0: /* original 7f04, guest PC 0x0c09d3e0 */
if(!s->budget--) { s->failed_pc=0x0c09d3e0u; return 0; }
r[15]+=0x00000004u;
goto P_0c09d3e2;
P_0c09d3e2: /* original 000b, guest PC 0x0c09d3e2 */
if(!s->budget--) { s->failed_pc=0x0c09d3e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d3e4: /* original 6ef6, guest PC 0x0c09d3e4 */
if(!s->budget--) { s->failed_pc=0x0c09d3e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09d3e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d3e6u; return 0; } return 1;
P_0c0a1282: /* original 6043, guest PC 0x0c0a1282 */
if(!s->budget--) { s->failed_pc=0x0c0a1282u; return 0; }
r[0]=r[4];
goto P_0c0a1284;
P_0c0a1284: /* original 4008, guest PC 0x0c0a1284 */
if(!s->budget--) { s->failed_pc=0x0c0a1284u; return 0; }
r[0]<<=2;
goto P_0c0a1286;
P_0c0a1286: /* original 6343, guest PC 0x0c0a1286 */
if(!s->budget--) { s->failed_pc=0x0c0a1286u; return 0; }
r[3]=r[4];
goto P_0c0a1288;
P_0c0a1288: /* original 303c, guest PC 0x0c0a1288 */
if(!s->budget--) { s->failed_pc=0x0c0a1288u; return 0; }
r[0]+=r[3];
goto P_0c0a128a;
P_0c0a128a: /* original d21d, guest PC 0x0c0a128a */
if(!s->budget--) { s->failed_pc=0x0c0a128au; return 0; }
r[2]=read(ram,0x0c0a1300u,4);
goto P_0c0a128c;
P_0c0a128c: /* original 4008, guest PC 0x0c0a128c */
if(!s->budget--) { s->failed_pc=0x0c0a128cu; return 0; }
r[0]<<=2;
goto P_0c0a128e;
P_0c0a128e: /* original 600e, guest PC 0x0c0a128e */
if(!s->budget--) { s->failed_pc=0x0c0a128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0a1290;
P_0c0a1290: /* original 000b, guest PC 0x0c0a1290 */
if(!s->budget--) { s->failed_pc=0x0c0a1290u; return 0; }
target=r[16];
r[0]+=r[2];
s->pc=target; return ram->oob==0;
P_0c0a1292: /* original 302c, guest PC 0x0c0a1292 */
if(!s->budget--) { s->failed_pc=0x0c0a1292u; return 0; }
r[0]+=r[2];
if(!vf3_matrix_family(0x0c0a1294u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a1294u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
