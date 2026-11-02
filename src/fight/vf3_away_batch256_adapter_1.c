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
int vf3_away_batch256_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ca0bcu: goto P_0c0ca0bc;
case 0x0c0ca0beu: goto P_0c0ca0be;
case 0x0c0ca0c0u: goto P_0c0ca0c0;
case 0x0c0ca0c2u: goto P_0c0ca0c2;
case 0x0c0ca0c4u: goto P_0c0ca0c4;
case 0x0c0ca0c6u: goto P_0c0ca0c6;
case 0x0c0ca0c8u: goto P_0c0ca0c8;
case 0x0c0ca0cau: goto P_0c0ca0ca;
case 0x0c0ca0ccu: goto P_0c0ca0cc;
case 0x0c0ca0ceu: goto P_0c0ca0ce;
case 0x0c0ca0d0u: goto P_0c0ca0d0;
case 0x0c0ca0d2u: goto P_0c0ca0d2;
case 0x0c0ca0d4u: goto P_0c0ca0d4;
case 0x0c0ca0d6u: goto P_0c0ca0d6;
case 0x0c0ca0d8u: goto P_0c0ca0d8;
case 0x0c0ca0dau: goto P_0c0ca0da;
case 0x0c0ca0dcu: goto P_0c0ca0dc;
case 0x0c0ca0deu: goto P_0c0ca0de;
case 0x0c0ca0e0u: goto P_0c0ca0e0;
case 0x0c0ca0e2u: goto P_0c0ca0e2;
case 0x0c0ca0e4u: goto P_0c0ca0e4;
case 0x0c0ca0e6u: goto P_0c0ca0e6;
case 0x0c0ca0e8u: goto P_0c0ca0e8;
case 0x0c0ca0eau: goto P_0c0ca0ea;
case 0x0c0ca0ecu: goto P_0c0ca0ec;
case 0x0c0ca0eeu: goto P_0c0ca0ee;
case 0x0c0ca0f0u: goto P_0c0ca0f0;
case 0x0c0ca0f2u: goto P_0c0ca0f2;
case 0x0c0ca0f4u: goto P_0c0ca0f4;
case 0x0c0ca0f6u: goto P_0c0ca0f6;
case 0x0c0ca0f8u: goto P_0c0ca0f8;
case 0x0c0ca0fau: goto P_0c0ca0fa;
case 0x0c0ca0fcu: goto P_0c0ca0fc;
case 0x0c0ca0feu: goto P_0c0ca0fe;
case 0x0c0ca100u: goto P_0c0ca100;
case 0x0c0ca102u: goto P_0c0ca102;
case 0x0c0ca104u: goto P_0c0ca104;
case 0x0c0ca106u: goto P_0c0ca106;
case 0x0c0ca108u: goto P_0c0ca108;
case 0x0c0ca10au: goto P_0c0ca10a;
case 0x0c0ca10cu: goto P_0c0ca10c;
case 0x0c0ca10eu: goto P_0c0ca10e;
case 0x0c0ca110u: goto P_0c0ca110;
case 0x0c0ca112u: goto P_0c0ca112;
case 0x0c0ca114u: goto P_0c0ca114;
case 0x0c0ca116u: goto P_0c0ca116;
case 0x0c0ca118u: goto P_0c0ca118;
case 0x0c0ca11au: goto P_0c0ca11a;
case 0x0c0ca11cu: goto P_0c0ca11c;
case 0x0c0ca11eu: goto P_0c0ca11e;
case 0x0c0ca120u: goto P_0c0ca120;
case 0x0c0ca122u: goto P_0c0ca122;
case 0x0c0ca124u: goto P_0c0ca124;
case 0x0c0ca126u: goto P_0c0ca126;
case 0x0c0ca128u: goto P_0c0ca128;
case 0x0c0ca12au: goto P_0c0ca12a;
case 0x0c0ca12cu: goto P_0c0ca12c;
case 0x0c0ca12eu: goto P_0c0ca12e;
case 0x0c0ca130u: goto P_0c0ca130;
case 0x0c0ca132u: goto P_0c0ca132;
case 0x0c0ca134u: goto P_0c0ca134;
case 0x0c0ca136u: goto P_0c0ca136;
case 0x0c0ca138u: goto P_0c0ca138;
case 0x0c0ca13au: goto P_0c0ca13a;
case 0x0c0ca13cu: goto P_0c0ca13c;
case 0x0c0ca13eu: goto P_0c0ca13e;
case 0x0c0ca140u: goto P_0c0ca140;
case 0x0c0ca142u: goto P_0c0ca142;
case 0x0c0ca144u: goto P_0c0ca144;
case 0x0c0ca146u: goto P_0c0ca146;
case 0x0c0ca148u: goto P_0c0ca148;
case 0x0c0ca14au: goto P_0c0ca14a;
case 0x0c0ca14cu: goto P_0c0ca14c;
case 0x0c0ca14eu: goto P_0c0ca14e;
case 0x0c0ca150u: goto P_0c0ca150;
case 0x0c0ca152u: goto P_0c0ca152;
case 0x0c0ca154u: goto P_0c0ca154;
case 0x0c0ca156u: goto P_0c0ca156;
case 0x0c0ca158u: goto P_0c0ca158;
case 0x0c0ca15au: goto P_0c0ca15a;
case 0x0c0ca15cu: goto P_0c0ca15c;
case 0x0c0ca15eu: goto P_0c0ca15e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ca0bc: /* original 2fe6, guest PC 0x0c0ca0bc */
if(!s->budget--) { s->failed_pc=0x0c0ca0bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca0be;
P_0c0ca0be: /* original e020, guest PC 0x0c0ca0be */
if(!s->budget--) { s->failed_pc=0x0c0ca0beu; return 0; }
r[0]=0x00000020u;
goto P_0c0ca0c0;
P_0c0ca0c0: /* original 2fd6, guest PC 0x0c0ca0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca0c2;
P_0c0ca0c2: /* original e100, guest PC 0x0c0ca0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c2u; return 0; }
r[1]=0x00000000u;
goto P_0c0ca0c4;
P_0c0ca0c4: /* original d52e, guest PC 0x0c0ca0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c4u; return 0; }
r[5]=read(ram,0x0c0ca180u,4);
goto P_0c0ca0c6;
P_0c0ca0c6: /* original 4f22, guest PC 0x0c0ca0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca0c8;
P_0c0ca0c8: /* original 005d, guest PC 0x0c0ca0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0ca0ca;
P_0c0ca0ca: /* original d32e, guest PC 0x0c0ca0ca */
if(!s->budget--) { s->failed_pc=0x0c0ca0cau; return 0; }
r[3]=read(ram,0x0c0ca184u,4);
goto P_0c0ca0cc;
P_0c0ca0cc: /* original 7fec, guest PC 0x0c0ca0cc */
if(!s->budget--) { s->failed_pc=0x0c0ca0ccu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0ca0ce;
P_0c0ca0ce: /* original d42a, guest PC 0x0c0ca0ce */
if(!s->budget--) { s->failed_pc=0x0c0ca0ceu; return 0; }
r[4]=read(ram,0x0c0ca178u,4);
goto P_0c0ca0d0;
P_0c0ca0d0: /* original 6d32, guest PC 0x0c0ca0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d0u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c0ca0d2;
P_0c0ca0d2: /* original 81f8, guest PC 0x0c0ca0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d2u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0ca0d4;
P_0c0ca0d4: /* original e022, guest PC 0x0c0ca0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d4u; return 0; }
r[0]=0x00000022u;
goto P_0c0ca0d6;
P_0c0ca0d6: /* original 005d, guest PC 0x0c0ca0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0ca0d8;
P_0c0ca0d8: /* original 6e43, guest PC 0x0c0ca0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d8u; return 0; }
r[14]=r[4];
goto P_0c0ca0da;
P_0c0ca0da: /* original 81f6, guest PC 0x0c0ca0da */
if(!s->budget--) { s->failed_pc=0x0c0ca0dau; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0ca0dc;
P_0c0ca0dc: /* original 2f16, guest PC 0x0c0ca0dc */
if(!s->budget--) { s->failed_pc=0x0c0ca0dcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca0de;
P_0c0ca0de: /* original 85f8, guest PC 0x0c0ca0de */
if(!s->budget--) { s->failed_pc=0x0c0ca0deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0ca0e0;
P_0c0ca0e0: /* original 2f06, guest PC 0x0c0ca0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e0u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca0e2;
P_0c0ca0e2: /* original 85fc, guest PC 0x0c0ca0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c0ca0e4;
P_0c0ca0e4: /* original 66f3, guest PC 0x0c0ca0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e4u; return 0; }
r[6]=r[15];
goto P_0c0ca0e6;
P_0c0ca0e6: /* original 65f3, guest PC 0x0c0ca0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e6u; return 0; }
r[5]=r[15];
goto P_0c0ca0e8;
P_0c0ca0e8: /* original d227, guest PC 0x0c0ca0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e8u; return 0; }
r[2]=read(ram,0x0c0ca188u,4);
goto P_0c0ca0ea;
P_0c0ca0ea: /* original 64f3, guest PC 0x0c0ca0ea */
if(!s->budget--) { s->failed_pc=0x0c0ca0eau; return 0; }
r[4]=r[15];
goto P_0c0ca0ec;
P_0c0ca0ec: /* original 750c, guest PC 0x0c0ca0ec */
if(!s->budget--) { s->failed_pc=0x0c0ca0ecu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0ca0ee;
P_0c0ca0ee: /* original 6703, guest PC 0x0c0ca0ee */
if(!s->budget--) { s->failed_pc=0x0c0ca0eeu; return 0; }
r[7]=r[0];
goto P_0c0ca0f0;
P_0c0ca0f0: /* original 7610, guest PC 0x0c0ca0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f0u; return 0; }
r[6]+=0x00000010u;
goto P_0c0ca0f2;
P_0c0ca0f2: /* original 420b, guest PC 0x0c0ca0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ca0f6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca0f6u) { target=s->pc; goto dispatch; }
goto P_0c0ca0f6;
P_0c0ca0f4: /* original 7408, guest PC 0x0c0ca0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0ca0f6;
P_0c0ca0f6: /* original e008, guest PC 0x0c0ca0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f6u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca0f8;
P_0c0ca0f8: /* original f3f6, guest PC 0x0c0ca0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca0fa;
P_0c0ca0fa: /* original e008, guest PC 0x0c0ca0fa */
if(!s->budget--) { s->failed_pc=0x0c0ca0fau; return 0; }
r[0]=0x00000008u;
goto P_0c0ca0fc;
P_0c0ca0fc: /* original fe37, guest PC 0x0c0ca0fc */
if(!s->budget--) { s->failed_pc=0x0c0ca0fcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca0fe;
P_0c0ca0fe: /* original e00c, guest PC 0x0c0ca0fe */
if(!s->budget--) { s->failed_pc=0x0c0ca0feu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca100;
P_0c0ca100: /* original f3f6, guest PC 0x0c0ca100 */
if(!s->budget--) { s->failed_pc=0x0c0ca100u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca102;
P_0c0ca102: /* original e00c, guest PC 0x0c0ca102 */
if(!s->budget--) { s->failed_pc=0x0c0ca102u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca104;
P_0c0ca104: /* original fe37, guest PC 0x0c0ca104 */
if(!s->budget--) { s->failed_pc=0x0c0ca104u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca106;
P_0c0ca106: /* original e010, guest PC 0x0c0ca106 */
if(!s->budget--) { s->failed_pc=0x0c0ca106u; return 0; }
r[0]=0x00000010u;
goto P_0c0ca108;
P_0c0ca108: /* original f3f6, guest PC 0x0c0ca108 */
if(!s->budget--) { s->failed_pc=0x0c0ca108u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca10a;
P_0c0ca10a: /* original e010, guest PC 0x0c0ca10a */
if(!s->budget--) { s->failed_pc=0x0c0ca10au; return 0; }
r[0]=0x00000010u;
goto P_0c0ca10c;
P_0c0ca10c: /* original fe37, guest PC 0x0c0ca10c */
if(!s->budget--) { s->failed_pc=0x0c0ca10cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca10e;
P_0c0ca10e: /* original 9027, guest PC 0x0c0ca10e */
if(!s->budget--) { s->failed_pc=0x0c0ca10eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca160u,2);
goto P_0c0ca110;
P_0c0ca110: /* original f3d6, guest PC 0x0c0ca110 */
if(!s->budget--) { s->failed_pc=0x0c0ca110u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca112;
P_0c0ca112: /* original e004, guest PC 0x0c0ca112 */
if(!s->budget--) { s->failed_pc=0x0c0ca112u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca114;
P_0c0ca114: /* original fe37, guest PC 0x0c0ca114 */
if(!s->budget--) { s->failed_pc=0x0c0ca114u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca116;
P_0c0ca116: /* original 9024, guest PC 0x0c0ca116 */
if(!s->budget--) { s->failed_pc=0x0c0ca116u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca162u,2);
goto P_0c0ca118;
P_0c0ca118: /* original f3d6, guest PC 0x0c0ca118 */
if(!s->budget--) { s->failed_pc=0x0c0ca118u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca11a;
P_0c0ca11a: /* original e014, guest PC 0x0c0ca11a */
if(!s->budget--) { s->failed_pc=0x0c0ca11au; return 0; }
r[0]=0x00000014u;
goto P_0c0ca11c;
P_0c0ca11c: /* original fe37, guest PC 0x0c0ca11c */
if(!s->budget--) { s->failed_pc=0x0c0ca11cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca11e;
P_0c0ca11e: /* original 9021, guest PC 0x0c0ca11e */
if(!s->budget--) { s->failed_pc=0x0c0ca11eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca164u,2);
goto P_0c0ca120;
P_0c0ca120: /* original f3d6, guest PC 0x0c0ca120 */
if(!s->budget--) { s->failed_pc=0x0c0ca120u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca122;
P_0c0ca122: /* original e028, guest PC 0x0c0ca122 */
if(!s->budget--) { s->failed_pc=0x0c0ca122u; return 0; }
r[0]=0x00000028u;
goto P_0c0ca124;
P_0c0ca124: /* original fe37, guest PC 0x0c0ca124 */
if(!s->budget--) { s->failed_pc=0x0c0ca124u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca126;
P_0c0ca126: /* original 901e, guest PC 0x0c0ca126 */
if(!s->budget--) { s->failed_pc=0x0c0ca126u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca166u,2);
goto P_0c0ca128;
P_0c0ca128: /* original 03dc, guest PC 0x0c0ca128 */
if(!s->budget--) { s->failed_pc=0x0c0ca128u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca12a;
P_0c0ca12a: /* original e018, guest PC 0x0c0ca12a */
if(!s->budget--) { s->failed_pc=0x0c0ca12au; return 0; }
r[0]=0x00000018u;
goto P_0c0ca12c;
P_0c0ca12c: /* original 0e34, guest PC 0x0c0ca12c */
if(!s->budget--) { s->failed_pc=0x0c0ca12cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ca12e;
P_0c0ca12e: /* original 901b, guest PC 0x0c0ca12e */
if(!s->budget--) { s->failed_pc=0x0c0ca12eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca168u,2);
goto P_0c0ca130;
P_0c0ca130: /* original 02dc, guest PC 0x0c0ca130 */
if(!s->budget--) { s->failed_pc=0x0c0ca130u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca132;
P_0c0ca132: /* original e019, guest PC 0x0c0ca132 */
if(!s->budget--) { s->failed_pc=0x0c0ca132u; return 0; }
r[0]=0x00000019u;
goto P_0c0ca134;
P_0c0ca134: /* original 0e24, guest PC 0x0c0ca134 */
if(!s->budget--) { s->failed_pc=0x0c0ca134u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ca136;
P_0c0ca136: /* original 9018, guest PC 0x0c0ca136 */
if(!s->budget--) { s->failed_pc=0x0c0ca136u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16au,2);
goto P_0c0ca138;
P_0c0ca138: /* original 7f1c, guest PC 0x0c0ca138 */
if(!s->budget--) { s->failed_pc=0x0c0ca138u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0ca13a;
P_0c0ca13a: /* original 4f26, guest PC 0x0c0ca13a */
if(!s->budget--) { s->failed_pc=0x0c0ca13au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca13c;
P_0c0ca13c: /* original 03dc, guest PC 0x0c0ca13c */
if(!s->budget--) { s->failed_pc=0x0c0ca13cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca13e;
P_0c0ca13e: /* original e01a, guest PC 0x0c0ca13e */
if(!s->budget--) { s->failed_pc=0x0c0ca13eu; return 0; }
r[0]=0x0000001au;
goto P_0c0ca140;
P_0c0ca140: /* original 0e34, guest PC 0x0c0ca140 */
if(!s->budget--) { s->failed_pc=0x0c0ca140u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ca142;
P_0c0ca142: /* original 9013, guest PC 0x0c0ca142 */
if(!s->budget--) { s->failed_pc=0x0c0ca142u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16cu,2);
goto P_0c0ca144;
P_0c0ca144: /* original f3d6, guest PC 0x0c0ca144 */
if(!s->budget--) { s->failed_pc=0x0c0ca144u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca146;
P_0c0ca146: /* original e01c, guest PC 0x0c0ca146 */
if(!s->budget--) { s->failed_pc=0x0c0ca146u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ca148;
P_0c0ca148: /* original fe37, guest PC 0x0c0ca148 */
if(!s->budget--) { s->failed_pc=0x0c0ca148u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca14a;
P_0c0ca14a: /* original 9010, guest PC 0x0c0ca14a */
if(!s->budget--) { s->failed_pc=0x0c0ca14au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16eu,2);
goto P_0c0ca14c;
P_0c0ca14c: /* original f3d6, guest PC 0x0c0ca14c */
if(!s->budget--) { s->failed_pc=0x0c0ca14cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca14e;
P_0c0ca14e: /* original e020, guest PC 0x0c0ca14e */
if(!s->budget--) { s->failed_pc=0x0c0ca14eu; return 0; }
r[0]=0x00000020u;
goto P_0c0ca150;
P_0c0ca150: /* original fe37, guest PC 0x0c0ca150 */
if(!s->budget--) { s->failed_pc=0x0c0ca150u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca152;
P_0c0ca152: /* original 900d, guest PC 0x0c0ca152 */
if(!s->budget--) { s->failed_pc=0x0c0ca152u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca170u,2);
goto P_0c0ca154;
P_0c0ca154: /* original f3d6, guest PC 0x0c0ca154 */
if(!s->budget--) { s->failed_pc=0x0c0ca154u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca156;
P_0c0ca156: /* original e024, guest PC 0x0c0ca156 */
if(!s->budget--) { s->failed_pc=0x0c0ca156u; return 0; }
r[0]=0x00000024u;
goto P_0c0ca158;
P_0c0ca158: /* original fe37, guest PC 0x0c0ca158 */
if(!s->budget--) { s->failed_pc=0x0c0ca158u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca15a;
P_0c0ca15a: /* original 6df6, guest PC 0x0c0ca15a */
if(!s->budget--) { s->failed_pc=0x0c0ca15au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ca15c;
P_0c0ca15c: /* original 000b, guest PC 0x0c0ca15c */
if(!s->budget--) { s->failed_pc=0x0c0ca15cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ca15e: /* original 6ef6, guest PC 0x0c0ca15e */
if(!s->budget--) { s->failed_pc=0x0c0ca15eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ca160u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca160u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
