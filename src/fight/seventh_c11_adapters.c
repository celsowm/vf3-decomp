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
int vf3_seventh_c11_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0365d4u: goto P_0c0365d4;
case 0x0c0365d6u: goto P_0c0365d6;
case 0x0c0365d8u: goto P_0c0365d8;
case 0x0c0365dau: goto P_0c0365da;
case 0x0c0365dcu: goto P_0c0365dc;
case 0x0c0365deu: goto P_0c0365de;
case 0x0c0365e0u: goto P_0c0365e0;
case 0x0c0365e2u: goto P_0c0365e2;
case 0x0c0365e4u: goto P_0c0365e4;
case 0x0c0365e6u: goto P_0c0365e6;
case 0x0c0365e8u: goto P_0c0365e8;
case 0x0c04013cu: goto P_0c04013c;
case 0x0c04013eu: goto P_0c04013e;
case 0x0c040140u: goto P_0c040140;
case 0x0c040142u: goto P_0c040142;
case 0x0c040144u: goto P_0c040144;
case 0x0c040146u: goto P_0c040146;
case 0x0c040148u: goto P_0c040148;
case 0x0c04014au: goto P_0c04014a;
case 0x0c04014cu: goto P_0c04014c;
case 0x0c04014eu: goto P_0c04014e;
case 0x0c067350u: goto P_0c067350;
case 0x0c067352u: goto P_0c067352;
case 0x0c067354u: goto P_0c067354;
case 0x0c067356u: goto P_0c067356;
case 0x0c067358u: goto P_0c067358;
case 0x0c06735au: goto P_0c06735a;
case 0x0c06735cu: goto P_0c06735c;
case 0x0c06735eu: goto P_0c06735e;
case 0x0c067360u: goto P_0c067360;
case 0x0c067362u: goto P_0c067362;
case 0x0c067364u: goto P_0c067364;
case 0x0c067366u: goto P_0c067366;
case 0x0c074a3au: goto P_0c074a3a;
case 0x0c074a3cu: goto P_0c074a3c;
case 0x0c074a3eu: goto P_0c074a3e;
case 0x0c074a40u: goto P_0c074a40;
case 0x0c074a42u: goto P_0c074a42;
case 0x0c074a44u: goto P_0c074a44;
case 0x0c074a46u: goto P_0c074a46;
case 0x0c074a48u: goto P_0c074a48;
case 0x0c074a4au: goto P_0c074a4a;
case 0x0c074a4cu: goto P_0c074a4c;
case 0x0c074a4eu: goto P_0c074a4e;
case 0x0c074a50u: goto P_0c074a50;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0365d4: /* original e22c, guest PC 0x0c0365d4 */
if(!s->budget--) { s->failed_pc=0x0c0365d4u; return 0; }
r[2]=0x0000002cu;
goto P_0c0365d6;
P_0c0365d6: /* original d31b, guest PC 0x0c0365d6 */
if(!s->budget--) { s->failed_pc=0x0c0365d6u; return 0; }
r[3]=read(ram,0x0c036644u,4);
goto P_0c0365d8;
P_0c0365d8: /* original 4f12, guest PC 0x0c0365d8 */
if(!s->budget--) { s->failed_pc=0x0c0365d8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0365da;
P_0c0365da: /* original 242f, guest PC 0x0c0365da */
if(!s->budget--) { s->failed_pc=0x0c0365dau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[2]);
goto P_0c0365dc;
P_0c0365dc: /* original 6032, guest PC 0x0c0365dc */
if(!s->budget--) { s->failed_pc=0x0c0365dcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0365de;
P_0c0365de: /* original 7028, guest PC 0x0c0365de */
if(!s->budget--) { s->failed_pc=0x0c0365deu; return 0; }
r[0]+=0x00000028u;
goto P_0c0365e0;
P_0c0365e0: /* original 041a, guest PC 0x0c0365e0 */
if(!s->budget--) { s->failed_pc=0x0c0365e0u; return 0; }
r[4]=r[19];
goto P_0c0365e2;
P_0c0365e2: /* original 644f, guest PC 0x0c0365e2 */
if(!s->budget--) { s->failed_pc=0x0c0365e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0365e4;
P_0c0365e4: /* original 304c, guest PC 0x0c0365e4 */
if(!s->budget--) { s->failed_pc=0x0c0365e4u; return 0; }
r[0]+=r[4];
goto P_0c0365e6;
P_0c0365e6: /* original 000b, guest PC 0x0c0365e6 */
if(!s->budget--) { s->failed_pc=0x0c0365e6u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0365e8: /* original 4f16, guest PC 0x0c0365e8 */
if(!s->budget--) { s->failed_pc=0x0c0365e8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0365eau,s,ram);
P_0c04013c: /* original d20c, guest PC 0x0c04013c */
if(!s->budget--) { s->failed_pc=0x0c04013cu; return 0; }
r[2]=read(ram,0x0c040170u,4);
goto P_0c04013e;
P_0c04013e: /* original 6322, guest PC 0x0c04013e */
if(!s->budget--) { s->failed_pc=0x0c04013eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c040140;
P_0c040140: /* original 2338, guest PC 0x0c040140 */
if(!s->budget--) { s->failed_pc=0x0c040140u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c040142;
P_0c040142: /* original 8902, guest PC 0x0c040142 */
if(!s->budget--) { s->failed_pc=0x0c040142u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04014a; }
goto P_0c040144;
P_0c040144: /* original e001, guest PC 0x0c040144 */
if(!s->budget--) { s->failed_pc=0x0c040144u; return 0; }
r[0]=0x00000001u;
goto P_0c040146;
P_0c040146: /* original 000b, guest PC 0x0c040146 */
if(!s->budget--) { s->failed_pc=0x0c040146u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040148: /* original 0009, guest PC 0x0c040148 */
if(!s->budget--) { s->failed_pc=0x0c040148u; return 0; }
goto P_0c04014a;
P_0c04014a: /* original e000, guest PC 0x0c04014a */
if(!s->budget--) { s->failed_pc=0x0c04014au; return 0; }
r[0]=0x00000000u;
goto P_0c04014c;
P_0c04014c: /* original 000b, guest PC 0x0c04014c */
if(!s->budget--) { s->failed_pc=0x0c04014cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04014e: /* original 0009, guest PC 0x0c04014e */
if(!s->budget--) { s->failed_pc=0x0c04014eu; return 0; }
return vf3_matrix_family(0x0c040150u,s,ram);
P_0c067350: /* original 901a, guest PC 0x0c067350 */
if(!s->budget--) { s->failed_pc=0x0c067350u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067388u,2);
goto P_0c067352;
P_0c067352: /* original 034c, guest PC 0x0c067352 */
if(!s->budget--) { s->failed_pc=0x0c067352u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067354;
P_0c067354: /* original 2338, guest PC 0x0c067354 */
if(!s->budget--) { s->failed_pc=0x0c067354u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c067356;
P_0c067356: /* original 8905, guest PC 0x0c067356 */
if(!s->budget--) { s->failed_pc=0x0c067356u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067364; }
goto P_0c067358;
P_0c067358: /* original d311, guest PC 0x0c067358 */
if(!s->budget--) { s->failed_pc=0x0c067358u; return 0; }
r[3]=read(ram,0x0c0673a0u,4);
goto P_0c06735a;
P_0c06735a: /* original 014c, guest PC 0x0c06735a */
if(!s->budget--) { s->failed_pc=0x0c06735au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06735c;
P_0c06735c: /* original 6231, guest PC 0x0c06735c */
if(!s->budget--) { s->failed_pc=0x0c06735cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c06735e;
P_0c06735e: /* original 611c, guest PC 0x0c06735e */
if(!s->budget--) { s->failed_pc=0x0c06735eu; return 0; }
r[1]=r[1]&255u;
goto P_0c067360;
P_0c067360: /* original 3218, guest PC 0x0c067360 */
if(!s->budget--) { s->failed_pc=0x0c067360u; return 0; }
r[2]-=r[1];
goto P_0c067362;
P_0c067362: /* original 2321, guest PC 0x0c067362 */
if(!s->budget--) { s->failed_pc=0x0c067362u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c067364;
P_0c067364: /* original 000b, guest PC 0x0c067364 */
if(!s->budget--) { s->failed_pc=0x0c067364u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c067366: /* original 0009, guest PC 0x0c067366 */
if(!s->budget--) { s->failed_pc=0x0c067366u; return 0; }
return vf3_matrix_family(0x0c067368u,s,ram);
P_0c074a3a: /* original 903f, guest PC 0x0c074a3a */
if(!s->budget--) { s->failed_pc=0x0c074a3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074abcu,2);
goto P_0c074a3c;
P_0c074a3c: /* original f346, guest PC 0x0c074a3c */
if(!s->budget--) { s->failed_pc=0x0c074a3cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074a3e;
P_0c074a3e: /* original 903e, guest PC 0x0c074a3e */
if(!s->budget--) { s->failed_pc=0x0c074a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074abeu,2);
goto P_0c074a40;
P_0c074a40: /* original f456, guest PC 0x0c074a40 */
if(!s->budget--) { s->failed_pc=0x0c074a40u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c074a42;
P_0c074a42: /* original c725, guest PC 0x0c074a42 */
if(!s->budget--) { s->failed_pc=0x0c074a42u; return 0; }
r[0]=0x0c074ad8u;
goto P_0c074a44;
P_0c074a44: /* original f431, guest PC 0x0c074a44 */
if(!s->budget--) { s->failed_pc=0x0c074a44u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c074a46;
P_0c074a46: /* original f308, guest PC 0x0c074a46 */
if(!s->budget--) { s->failed_pc=0x0c074a46u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c074a48;
P_0c074a48: /* original f435, guest PC 0x0c074a48 */
if(!s->budget--) { s->failed_pc=0x0c074a48u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c074a4a;
P_0c074a4a: /* original 8900, guest PC 0x0c074a4a */
if(!s->budget--) { s->failed_pc=0x0c074a4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074a4e; }
goto P_0c074a4c;
P_0c074a4c: /* original 9638, guest PC 0x0c074a4c */
if(!s->budget--) { s->failed_pc=0x0c074a4cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074ac0u,2);
goto P_0c074a4e;
P_0c074a4e: /* original 000b, guest PC 0x0c074a4e */
if(!s->budget--) { s->failed_pc=0x0c074a4eu; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c074a50: /* original 6063, guest PC 0x0c074a50 */
if(!s->budget--) { s->failed_pc=0x0c074a50u; return 0; }
r[0]=r[6];
return vf3_matrix_family(0x0c074a52u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0365d4u,0x0c0365d6u,0x0c0365d8u,0x0c0365dau,0x0c0365dcu,0x0c0365deu,0x0c0365e0u,0x0c0365e2u,0x0c0365e4u,0x0c0365e6u,0x0c0365e8u,0x0c04013cu,0x0c04013eu,0x0c040140u,0x0c040142u,0x0c040144u,
0x0c040146u,0x0c040148u,0x0c04014au,0x0c04014cu,0x0c04014eu,0x0c067350u,0x0c067352u,0x0c067354u,0x0c067356u,0x0c067358u,0x0c06735au,0x0c06735cu,0x0c06735eu,0x0c067360u,0x0c067362u,0x0c067364u,
0x0c067366u,0x0c074a3au,0x0c074a3cu,0x0c074a3eu,0x0c074a40u,0x0c074a42u,0x0c074a44u,0x0c074a46u,0x0c074a48u,0x0c074a4au,0x0c074a4cu,0x0c074a4eu,0x0c074a50u,
};
int vf3_seventh_c11_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
