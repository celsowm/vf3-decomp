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
int vf3_away_batch238_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c1192u: goto P_0c0c1192;
case 0x0c0c1194u: goto P_0c0c1194;
case 0x0c0c1196u: goto P_0c0c1196;
case 0x0c0c1198u: goto P_0c0c1198;
case 0x0c0c119au: goto P_0c0c119a;
case 0x0c0c119cu: goto P_0c0c119c;
case 0x0c0c119eu: goto P_0c0c119e;
case 0x0c0c11a0u: goto P_0c0c11a0;
case 0x0c0c11a2u: goto P_0c0c11a2;
case 0x0c0c11a4u: goto P_0c0c11a4;
case 0x0c0c11a6u: goto P_0c0c11a6;
case 0x0c0c11a8u: goto P_0c0c11a8;
case 0x0c0c11aau: goto P_0c0c11aa;
case 0x0c0c11acu: goto P_0c0c11ac;
case 0x0c0c11aeu: goto P_0c0c11ae;
case 0x0c0c11b0u: goto P_0c0c11b0;
case 0x0c0c11b2u: goto P_0c0c11b2;
case 0x0c0c11b4u: goto P_0c0c11b4;
case 0x0c0c11b6u: goto P_0c0c11b6;
case 0x0c0c11b8u: goto P_0c0c11b8;
case 0x0c0c11bau: goto P_0c0c11ba;
case 0x0c0c11bcu: goto P_0c0c11bc;
case 0x0c0c11beu: goto P_0c0c11be;
case 0x0c0c11c0u: goto P_0c0c11c0;
case 0x0c0c11c2u: goto P_0c0c11c2;
case 0x0c0c11c4u: goto P_0c0c11c4;
case 0x0c0c11c6u: goto P_0c0c11c6;
case 0x0c0c11c8u: goto P_0c0c11c8;
case 0x0c0c11cau: goto P_0c0c11ca;
case 0x0c0c11ccu: goto P_0c0c11cc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c1192: /* original 2fe6, guest PC 0x0c0c1192 */
if(!s->budget--) { s->failed_pc=0x0c0c1192u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1194;
P_0c0c1194: /* original d314, guest PC 0x0c0c1194 */
if(!s->budget--) { s->failed_pc=0x0c0c1194u; return 0; }
r[3]=read(ram,0x0c0c11e8u,4);
goto P_0c0c1196;
P_0c0c1196: /* original 7ffc, guest PC 0x0c0c1196 */
if(!s->budget--) { s->failed_pc=0x0c0c1196u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1198;
P_0c0c1198: /* original d114, guest PC 0x0c0c1198 */
if(!s->budget--) { s->failed_pc=0x0c0c1198u; return 0; }
r[1]=read(ram,0x0c0c11ecu,4);
goto P_0c0c119a;
P_0c0c119a: /* original 6e32, guest PC 0x0c0c119a */
if(!s->budget--) { s->failed_pc=0x0c0c119au; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0c119c;
P_0c0c119c: /* original 6210, guest PC 0x0c0c119c */
if(!s->budget--) { s->failed_pc=0x0c0c119cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c0c119e;
P_0c0c119e: /* original 622c, guest PC 0x0c0c119e */
if(!s->budget--) { s->failed_pc=0x0c0c119eu; return 0; }
r[2]=r[2]&255u;
goto P_0c0c11a0;
P_0c0c11a0: /* original 2f22, guest PC 0x0c0c11a0 */
if(!s->budget--) { s->failed_pc=0x0c0c11a0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c11a2;
P_0c0c11a2: /* original d313, guest PC 0x0c0c11a2 */
if(!s->budget--) { s->failed_pc=0x0c0c11a2u; return 0; }
r[3]=read(ram,0x0c0c11f0u,4);
goto P_0c0c11a4;
P_0c0c11a4: /* original 2e39, guest PC 0x0c0c11a4 */
if(!s->budget--) { s->failed_pc=0x0c0c11a4u; return 0; }
r[14]&=r[3];
goto P_0c0c11a6;
P_0c0c11a6: /* original 2ee8, guest PC 0x0c0c11a6 */
if(!s->budget--) { s->failed_pc=0x0c0c11a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c11a8;
P_0c0c11a8: /* original 8b0e, guest PC 0x0c0c11a8 */
if(!s->budget--) { s->failed_pc=0x0c0c11a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c11c8; }
goto P_0c0c11aa;
P_0c0c11aa: /* original 60f2, guest PC 0x0c0c11aa */
if(!s->budget--) { s->failed_pc=0x0c0c11aau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c11ac;
P_0c0c11ac: /* original 8801, guest PC 0x0c0c11ac */
if(!s->budget--) { s->failed_pc=0x0c0c11acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c11ae;
P_0c0c11ae: /* original 890b, guest PC 0x0c0c11ae */
if(!s->budget--) { s->failed_pc=0x0c0c11aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c11c8; }
goto P_0c0c11b0;
P_0c0c11b0: /* original ee3f, guest PC 0x0c0c11b0 */
if(!s->budget--) { s->failed_pc=0x0c0c11b0u; return 0; }
r[14]=0x0000003fu;
goto P_0c0c11b2;
P_0c0c11b2: /* original 26e9, guest PC 0x0c0c11b2 */
if(!s->budget--) { s->failed_pc=0x0c0c11b2u; return 0; }
r[6]&=r[14];
goto P_0c0c11b4;
P_0c0c11b4: /* original 4618, guest PC 0x0c0c11b4 */
if(!s->budget--) { s->failed_pc=0x0c0c11b4u; return 0; }
r[6]<<=8;
goto P_0c0c11b6;
P_0c0c11b6: /* original 25e9, guest PC 0x0c0c11b6 */
if(!s->budget--) { s->failed_pc=0x0c0c11b6u; return 0; }
r[5]&=r[14];
goto P_0c0c11b8;
P_0c0c11b8: /* original 27e9, guest PC 0x0c0c11b8 */
if(!s->budget--) { s->failed_pc=0x0c0c11b8u; return 0; }
r[7]&=r[14];
goto P_0c0c11ba;
P_0c0c11ba: /* original 4728, guest PC 0x0c0c11ba */
if(!s->budget--) { s->failed_pc=0x0c0c11bau; return 0; }
r[7]<<=16;
goto P_0c0c11bc;
P_0c0c11bc: /* original 4508, guest PC 0x0c0c11bc */
if(!s->budget--) { s->failed_pc=0x0c0c11bcu; return 0; }
r[5]<<=2;
goto P_0c0c11be;
P_0c0c11be: /* original 4608, guest PC 0x0c0c11be */
if(!s->budget--) { s->failed_pc=0x0c0c11beu; return 0; }
r[6]<<=2;
goto P_0c0c11c0;
P_0c0c11c0: /* original 4708, guest PC 0x0c0c11c0 */
if(!s->budget--) { s->failed_pc=0x0c0c11c0u; return 0; }
r[7]<<=2;
goto P_0c0c11c2;
P_0c0c11c2: /* original 256b, guest PC 0x0c0c11c2 */
if(!s->budget--) { s->failed_pc=0x0c0c11c2u; return 0; }
r[5]|=r[6];
goto P_0c0c11c4;
P_0c0c11c4: /* original 257b, guest PC 0x0c0c11c4 */
if(!s->budget--) { s->failed_pc=0x0c0c11c4u; return 0; }
r[5]|=r[7];
goto P_0c0c11c6;
P_0c0c11c6: /* original 2452, guest PC 0x0c0c11c6 */
if(!s->budget--) { s->failed_pc=0x0c0c11c6u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0c11c8;
P_0c0c11c8: /* original 7f04, guest PC 0x0c0c11c8 */
if(!s->budget--) { s->failed_pc=0x0c0c11c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c11ca;
P_0c0c11ca: /* original 000b, guest PC 0x0c0c11ca */
if(!s->budget--) { s->failed_pc=0x0c0c11cau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c11cc: /* original 6ef6, guest PC 0x0c0c11cc */
if(!s->budget--) { s->failed_pc=0x0c0c11ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c11ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c11ceu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
