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
int vf3_away_batch15_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08b168u: goto P_0c08b168;
case 0x0c08b16au: goto P_0c08b16a;
case 0x0c08b16cu: goto P_0c08b16c;
case 0x0c08b16eu: goto P_0c08b16e;
case 0x0c08b170u: goto P_0c08b170;
case 0x0c08b172u: goto P_0c08b172;
case 0x0c08b174u: goto P_0c08b174;
case 0x0c08b176u: goto P_0c08b176;
case 0x0c08b178u: goto P_0c08b178;
case 0x0c08b17au: goto P_0c08b17a;
case 0x0c08b17cu: goto P_0c08b17c;
case 0x0c08b17eu: goto P_0c08b17e;
case 0x0c08b180u: goto P_0c08b180;
case 0x0c08b182u: goto P_0c08b182;
case 0x0c08b184u: goto P_0c08b184;
case 0x0c08b186u: goto P_0c08b186;
case 0x0c08b188u: goto P_0c08b188;
case 0x0c08b18au: goto P_0c08b18a;
case 0x0c08b18cu: goto P_0c08b18c;
case 0x0c08b18eu: goto P_0c08b18e;
case 0x0c08b190u: goto P_0c08b190;
case 0x0c08b192u: goto P_0c08b192;
case 0x0c08b194u: goto P_0c08b194;
case 0x0c08b196u: goto P_0c08b196;
case 0x0c08b198u: goto P_0c08b198;
case 0x0c08b19au: goto P_0c08b19a;
case 0x0c08b19cu: goto P_0c08b19c;
case 0x0c08b19eu: goto P_0c08b19e;
case 0x0c08b1a0u: goto P_0c08b1a0;
case 0x0c08b1a2u: goto P_0c08b1a2;
case 0x0c08b1a4u: goto P_0c08b1a4;
case 0x0c08b1a6u: goto P_0c08b1a6;
case 0x0c08b1a8u: goto P_0c08b1a8;
case 0x0c08b1aau: goto P_0c08b1aa;
case 0x0c08b1acu: goto P_0c08b1ac;
case 0x0c08b1aeu: goto P_0c08b1ae;
case 0x0c08b1b0u: goto P_0c08b1b0;
case 0x0c08b1b2u: goto P_0c08b1b2;
case 0x0c08b1b4u: goto P_0c08b1b4;
case 0x0c08b1b6u: goto P_0c08b1b6;
case 0x0c08b1b8u: goto P_0c08b1b8;
case 0x0c08b1bau: goto P_0c08b1ba;
case 0x0c08b1bcu: goto P_0c08b1bc;
case 0x0c08b1beu: goto P_0c08b1be;
case 0x0c08b1c0u: goto P_0c08b1c0;
case 0x0c08b1c2u: goto P_0c08b1c2;
case 0x0c08b1c4u: goto P_0c08b1c4;
case 0x0c08b1c6u: goto P_0c08b1c6;
case 0x0c08b1c8u: goto P_0c08b1c8;
case 0x0c08b1cau: goto P_0c08b1ca;
case 0x0c08b1ccu: goto P_0c08b1cc;
case 0x0c08b1ceu: goto P_0c08b1ce;
case 0x0c08b1d0u: goto P_0c08b1d0;
case 0x0c08b1d2u: goto P_0c08b1d2;
case 0x0c08b1d4u: goto P_0c08b1d4;
case 0x0c08b1d6u: goto P_0c08b1d6;
case 0x0c08b1d8u: goto P_0c08b1d8;
case 0x0c08b1dau: goto P_0c08b1da;
case 0x0c08b1dcu: goto P_0c08b1dc;
case 0x0c08b1deu: goto P_0c08b1de;
case 0x0c08b1e0u: goto P_0c08b1e0;
case 0x0c08b1e2u: goto P_0c08b1e2;
case 0x0c08b1e4u: goto P_0c08b1e4;
case 0x0c08b1e6u: goto P_0c08b1e6;
case 0x0c08b1e8u: goto P_0c08b1e8;
case 0x0c08b1eau: goto P_0c08b1ea;
case 0x0c08b1ecu: goto P_0c08b1ec;
case 0x0c08b1eeu: goto P_0c08b1ee;
case 0x0c08b1f0u: goto P_0c08b1f0;
case 0x0c08b1f2u: goto P_0c08b1f2;
case 0x0c08b1f4u: goto P_0c08b1f4;
case 0x0c08b1f6u: goto P_0c08b1f6;
case 0x0c08b1f8u: goto P_0c08b1f8;
case 0x0c08b1fau: goto P_0c08b1fa;
case 0x0c08b1fcu: goto P_0c08b1fc;
case 0x0c08b1feu: goto P_0c08b1fe;
case 0x0c08b200u: goto P_0c08b200;
case 0x0c08b202u: goto P_0c08b202;
case 0x0c08b204u: goto P_0c08b204;
case 0x0c08b206u: goto P_0c08b206;
case 0x0c08b208u: goto P_0c08b208;
case 0x0c08b20au: goto P_0c08b20a;
case 0x0c08b20cu: goto P_0c08b20c;
case 0x0c08b20eu: goto P_0c08b20e;
case 0x0c08b210u: goto P_0c08b210;
case 0x0c08b212u: goto P_0c08b212;
case 0x0c08b214u: goto P_0c08b214;
case 0x0c08b216u: goto P_0c08b216;
case 0x0c08b218u: goto P_0c08b218;
case 0x0c08b21au: goto P_0c08b21a;
case 0x0c08b21cu: goto P_0c08b21c;
case 0x0c08b21eu: goto P_0c08b21e;
case 0x0c08b220u: goto P_0c08b220;
case 0x0c08b222u: goto P_0c08b222;
case 0x0c08b224u: goto P_0c08b224;
case 0x0c08b226u: goto P_0c08b226;
case 0x0c08b228u: goto P_0c08b228;
case 0x0c08b22au: goto P_0c08b22a;
case 0x0c08b22cu: goto P_0c08b22c;
case 0x0c08b22eu: goto P_0c08b22e;
case 0x0c08b230u: goto P_0c08b230;
case 0x0c08b232u: goto P_0c08b232;
case 0x0c08b234u: goto P_0c08b234;
case 0x0c08b236u: goto P_0c08b236;
case 0x0c08b238u: goto P_0c08b238;
case 0x0c08b23au: goto P_0c08b23a;
case 0x0c08b23cu: goto P_0c08b23c;
case 0x0c08b23eu: goto P_0c08b23e;
case 0x0c08b240u: goto P_0c08b240;
case 0x0c08b242u: goto P_0c08b242;
case 0x0c08b244u: goto P_0c08b244;
case 0x0c08b246u: goto P_0c08b246;
case 0x0c08b248u: goto P_0c08b248;
case 0x0c08b24au: goto P_0c08b24a;
case 0x0c08b24cu: goto P_0c08b24c;
case 0x0c08b24eu: goto P_0c08b24e;
case 0x0c08b250u: goto P_0c08b250;
case 0x0c08b252u: goto P_0c08b252;
case 0x0c08b254u: goto P_0c08b254;
case 0x0c08b256u: goto P_0c08b256;
case 0x0c08b258u: goto P_0c08b258;
case 0x0c08b25au: goto P_0c08b25a;
case 0x0c08b25cu: goto P_0c08b25c;
case 0x0c08b25eu: goto P_0c08b25e;
case 0x0c08b260u: goto P_0c08b260;
case 0x0c08b262u: goto P_0c08b262;
case 0x0c08b264u: goto P_0c08b264;
case 0x0c08b266u: goto P_0c08b266;
case 0x0c08b268u: goto P_0c08b268;
case 0x0c08b26au: goto P_0c08b26a;
case 0x0c08b26cu: goto P_0c08b26c;
case 0x0c08b26eu: goto P_0c08b26e;
case 0x0c08b270u: goto P_0c08b270;
case 0x0c08b272u: goto P_0c08b272;
case 0x0c08b274u: goto P_0c08b274;
case 0x0c08b276u: goto P_0c08b276;
case 0x0c08b278u: goto P_0c08b278;
case 0x0c08b27au: goto P_0c08b27a;
case 0x0c08b27cu: goto P_0c08b27c;
case 0x0c08b27eu: goto P_0c08b27e;
case 0x0c08b280u: goto P_0c08b280;
case 0x0c08b282u: goto P_0c08b282;
case 0x0c08b284u: goto P_0c08b284;
case 0x0c08b286u: goto P_0c08b286;
case 0x0c08b288u: goto P_0c08b288;
case 0x0c08b28au: goto P_0c08b28a;
case 0x0c08b28cu: goto P_0c08b28c;
case 0x0c08b28eu: goto P_0c08b28e;
case 0x0c08b290u: goto P_0c08b290;
case 0x0c08b292u: goto P_0c08b292;
case 0x0c08b294u: goto P_0c08b294;
case 0x0c08b296u: goto P_0c08b296;
case 0x0c08b298u: goto P_0c08b298;
case 0x0c08b29au: goto P_0c08b29a;
case 0x0c08b29cu: goto P_0c08b29c;
case 0x0c08b29eu: goto P_0c08b29e;
case 0x0c08b2a0u: goto P_0c08b2a0;
case 0x0c08b2a2u: goto P_0c08b2a2;
case 0x0c08b2a4u: goto P_0c08b2a4;
case 0x0c08b2a6u: goto P_0c08b2a6;
case 0x0c08b2a8u: goto P_0c08b2a8;
case 0x0c08b2aau: goto P_0c08b2aa;
case 0x0c08b2acu: goto P_0c08b2ac;
case 0x0c08b2aeu: goto P_0c08b2ae;
case 0x0c08b2b0u: goto P_0c08b2b0;
case 0x0c08b2b2u: goto P_0c08b2b2;
case 0x0c08b2b4u: goto P_0c08b2b4;
case 0x0c08b2b6u: goto P_0c08b2b6;
case 0x0c08b2b8u: goto P_0c08b2b8;
case 0x0c08b2bau: goto P_0c08b2ba;
case 0x0c08b2bcu: goto P_0c08b2bc;
case 0x0c08b2beu: goto P_0c08b2be;
case 0x0c08b2c0u: goto P_0c08b2c0;
case 0x0c08b2c2u: goto P_0c08b2c2;
case 0x0c08b2c4u: goto P_0c08b2c4;
case 0x0c08b2c6u: goto P_0c08b2c6;
case 0x0c08b2c8u: goto P_0c08b2c8;
case 0x0c08b2cau: goto P_0c08b2ca;
case 0x0c08b2ccu: goto P_0c08b2cc;
case 0x0c08b2ceu: goto P_0c08b2ce;
case 0x0c08b2d0u: goto P_0c08b2d0;
case 0x0c08b2d2u: goto P_0c08b2d2;
case 0x0c08b2d4u: goto P_0c08b2d4;
case 0x0c08b2d6u: goto P_0c08b2d6;
case 0x0c08b2d8u: goto P_0c08b2d8;
case 0x0c08b2dau: goto P_0c08b2da;
case 0x0c08b2dcu: goto P_0c08b2dc;
case 0x0c08b2deu: goto P_0c08b2de;
case 0x0c08b2e0u: goto P_0c08b2e0;
case 0x0c08b2e2u: goto P_0c08b2e2;
case 0x0c08b2e4u: goto P_0c08b2e4;
case 0x0c08b2e6u: goto P_0c08b2e6;
case 0x0c08b2e8u: goto P_0c08b2e8;
case 0x0c08b2eau: goto P_0c08b2ea;
case 0x0c08b2ecu: goto P_0c08b2ec;
case 0x0c08b2eeu: goto P_0c08b2ee;
case 0x0c08b2f0u: goto P_0c08b2f0;
case 0x0c08b2f2u: goto P_0c08b2f2;
case 0x0c08b2f4u: goto P_0c08b2f4;
case 0x0c08b2f6u: goto P_0c08b2f6;
case 0x0c08b2f8u: goto P_0c08b2f8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08b168: /* original d165, guest PC 0x0c08b168 */
if(!s->budget--) { s->failed_pc=0x0c08b168u; return 0; }
r[1]=read(ram,0x0c08b300u,4);
goto P_0c08b16a;
P_0c08b16a: /* original 7ffc, guest PC 0x0c08b16a */
if(!s->budget--) { s->failed_pc=0x0c08b16au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08b16c;
P_0c08b16c: /* original d363, guest PC 0x0c08b16c */
if(!s->budget--) { s->failed_pc=0x0c08b16cu; return 0; }
r[3]=read(ram,0x0c08b2fcu,4);
goto P_0c08b16e;
P_0c08b16e: /* original 6212, guest PC 0x0c08b16e */
if(!s->budget--) { s->failed_pc=0x0c08b16eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08b170;
P_0c08b170: /* original 2238, guest PC 0x0c08b170 */
if(!s->budget--) { s->failed_pc=0x0c08b170u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08b172;
P_0c08b172: /* original 8b37, guest PC 0x0c08b172 */
if(!s->budget--) { s->failed_pc=0x0c08b172u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b1e4; }
goto P_0c08b174;
P_0c08b174: /* original d063, guest PC 0x0c08b174 */
if(!s->budget--) { s->failed_pc=0x0c08b174u; return 0; }
r[0]=read(ram,0x0c08b304u,4);
goto P_0c08b176;
P_0c08b176: /* original 4408, guest PC 0x0c08b176 */
if(!s->budget--) { s->failed_pc=0x0c08b176u; return 0; }
r[4]<<=2;
goto P_0c08b178;
P_0c08b178: /* original d363, guest PC 0x0c08b178 */
if(!s->budget--) { s->failed_pc=0x0c08b178u; return 0; }
r[3]=read(ram,0x0c08b308u,4);
goto P_0c08b17a;
P_0c08b17a: /* original 4408, guest PC 0x0c08b17a */
if(!s->budget--) { s->failed_pc=0x0c08b17au; return 0; }
r[4]<<=2;
goto P_0c08b17c;
P_0c08b17c: /* original 6602, guest PC 0x0c08b17c */
if(!s->budget--) { s->failed_pc=0x0c08b17cu; return 0; }
tmp=read(ram,r[0],4);
r[6]=tmp;
goto P_0c08b17e;
P_0c08b17e: /* original e010, guest PC 0x0c08b17e */
if(!s->budget--) { s->failed_pc=0x0c08b17eu; return 0; }
r[0]=0x00000010u;
goto P_0c08b180;
P_0c08b180: /* original 334c, guest PC 0x0c08b180 */
if(!s->budget--) { s->failed_pc=0x0c08b180u; return 0; }
r[3]+=r[4];
goto P_0c08b182;
P_0c08b182: /* original f766, guest PC 0x0c08b182 */
if(!s->budget--) { s->failed_pc=0x0c08b182u; return 0; }
vf3_matrix_load(s,ram,7,r[6]+r[0]);
goto P_0c08b184;
P_0c08b184: /* original e018, guest PC 0x0c08b184 */
if(!s->budget--) { s->failed_pc=0x0c08b184u; return 0; }
r[0]=0x00000018u;
goto P_0c08b186;
P_0c08b186: /* original 6433, guest PC 0x0c08b186 */
if(!s->budget--) { s->failed_pc=0x0c08b186u; return 0; }
r[4]=r[3];
goto P_0c08b188;
P_0c08b188: /* original f966, guest PC 0x0c08b188 */
if(!s->budget--) { s->failed_pc=0x0c08b188u; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c08b18a;
P_0c08b18a: /* original 7408, guest PC 0x0c08b18a */
if(!s->budget--) { s->failed_pc=0x0c08b18au; return 0; }
r[4]+=0x00000008u;
goto P_0c08b18c;
P_0c08b18c: /* original 2f32, guest PC 0x0c08b18c */
if(!s->budget--) { s->failed_pc=0x0c08b18cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08b18e;
P_0c08b18e: /* original e004, guest PC 0x0c08b18e */
if(!s->budget--) { s->failed_pc=0x0c08b18eu; return 0; }
r[0]=0x00000004u;
goto P_0c08b190;
P_0c08b190: /* original f48d, guest PC 0x0c08b190 */
if(!s->budget--) { s->failed_pc=0x0c08b190u; return 0; }
fr[4]=0;
goto P_0c08b192;
P_0c08b192: /* original f846, guest PC 0x0c08b192 */
if(!s->budget--) { s->failed_pc=0x0c08b192u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c08b194;
P_0c08b194: /* original f19c, guest PC 0x0c08b194 */
if(!s->budget--) { s->failed_pc=0x0c08b194u; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c08b196;
P_0c08b196: /* original f28c, guest PC 0x0c08b196 */
if(!s->budget--) { s->failed_pc=0x0c08b196u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c08b198;
P_0c08b198: /* original f240, guest PC 0x0c08b198 */
if(!s->budget--) { s->failed_pc=0x0c08b198u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c08b19a;
P_0c08b19a: /* original f180, guest PC 0x0c08b19a */
if(!s->budget--) { s->failed_pc=0x0c08b19au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[8],r[18],'+');
goto P_0c08b19c;
P_0c08b19c: /* original f648, guest PC 0x0c08b19c */
if(!s->budget--) { s->failed_pc=0x0c08b19cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c08b19e;
P_0c08b19e: /* original f07c, guest PC 0x0c08b19e */
if(!s->budget--) { s->failed_pc=0x0c08b19eu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08b1a0;
P_0c08b1a0: /* original f34c, guest PC 0x0c08b1a0 */
if(!s->budget--) { s->failed_pc=0x0c08b1a0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08b1a2;
P_0c08b1a2: /* original f361, guest PC 0x0c08b1a2 */
if(!s->budget--) { s->failed_pc=0x0c08b1a2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c08b1a4;
P_0c08b1a4: /* original f061, guest PC 0x0c08b1a4 */
if(!s->budget--) { s->failed_pc=0x0c08b1a4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[6],r[18],'-');
goto P_0c08b1a6;
P_0c08b1a6: /* original fa38, guest PC 0x0c08b1a6 */
if(!s->budget--) { s->failed_pc=0x0c08b1a6u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
goto P_0c08b1a8;
P_0c08b1a8: /* original f212, guest PC 0x0c08b1a8 */
if(!s->budget--) { s->failed_pc=0x0c08b1a8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'*');
goto P_0c08b1aa;
P_0c08b1aa: /* original f536, guest PC 0x0c08b1aa */
if(!s->budget--) { s->failed_pc=0x0c08b1aau; return 0; }
vf3_matrix_load(s,ram,5,r[3]+r[0]);
goto P_0c08b1ac;
P_0c08b1ac: /* original f23e, guest PC 0x0c08b1ac */
if(!s->budget--) { s->failed_pc=0x0c08b1acu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c08b1ae;
P_0c08b1ae: /* original f34c, guest PC 0x0c08b1ae */
if(!s->budget--) { s->failed_pc=0x0c08b1aeu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08b1b0;
P_0c08b1b0: /* original f3a1, guest PC 0x0c08b1b0 */
if(!s->budget--) { s->failed_pc=0x0c08b1b0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c08b1b2;
P_0c08b1b2: /* original f62c, guest PC 0x0c08b1b2 */
if(!s->budget--) { s->failed_pc=0x0c08b1b2u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c08b1b4;
P_0c08b1b4: /* original f25c, guest PC 0x0c08b1b4 */
if(!s->budget--) { s->failed_pc=0x0c08b1b4u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c08b1b6;
P_0c08b1b6: /* original f950, guest PC 0x0c08b1b6 */
if(!s->budget--) { s->failed_pc=0x0c08b1b6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[5],r[18],'+');
goto P_0c08b1b8;
P_0c08b1b8: /* original f240, guest PC 0x0c08b1b8 */
if(!s->budget--) { s->failed_pc=0x0c08b1b8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c08b1ba;
P_0c08b1ba: /* original 2558, guest PC 0x0c08b1ba */
if(!s->budget--) { s->failed_pc=0x0c08b1bau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c08b1bc;
P_0c08b1bc: /* original f7a1, guest PC 0x0c08b1bc */
if(!s->budget--) { s->failed_pc=0x0c08b1bcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c08b1be;
P_0c08b1be: /* original f292, guest PC 0x0c08b1be */
if(!s->budget--) { s->failed_pc=0x0c08b1beu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'*');
goto P_0c08b1c0;
P_0c08b1c0: /* original f07c, guest PC 0x0c08b1c0 */
if(!s->budget--) { s->failed_pc=0x0c08b1c0u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08b1c2;
P_0c08b1c2: /* original f23e, guest PC 0x0c08b1c2 */
if(!s->budget--) { s->failed_pc=0x0c08b1c2u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c08b1c4;
P_0c08b1c4: /* original 8f05, guest PC 0x0c08b1c4 */
if(!s->budget--) { s->failed_pc=0x0c08b1c4u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,2);
if(!cond) { goto P_0c08b1d2; }
goto P_0c08b1c8;
P_0c08b1c6: /* original f42c, guest PC 0x0c08b1c6 */
if(!s->budget--) { s->failed_pc=0x0c08b1c6u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c08b1c8;
P_0c08b1c8: /* original f38d, guest PC 0x0c08b1c8 */
if(!s->budget--) { s->failed_pc=0x0c08b1c8u; return 0; }
fr[3]=0;
goto P_0c08b1ca;
P_0c08b1ca: /* original f345, guest PC 0x0c08b1ca */
if(!s->budget--) { s->failed_pc=0x0c08b1cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c08b1cc;
P_0c08b1cc: /* original 8904, guest PC 0x0c08b1cc */
if(!s->budget--) { s->failed_pc=0x0c08b1ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b1d8; }
goto P_0c08b1ce;
P_0c08b1ce: /* original a006, guest PC 0x0c08b1ce */
if(!s->budget--) { s->failed_pc=0x0c08b1ceu; return 0; }
goto P_0c08b1de;
P_0c08b1d0: /* original 0009, guest PC 0x0c08b1d0 */
if(!s->budget--) { s->failed_pc=0x0c08b1d0u; return 0; }
goto P_0c08b1d2;
P_0c08b1d2: /* original f38d, guest PC 0x0c08b1d2 */
if(!s->budget--) { s->failed_pc=0x0c08b1d2u; return 0; }
fr[3]=0;
goto P_0c08b1d4;
P_0c08b1d4: /* original f365, guest PC 0x0c08b1d4 */
if(!s->budget--) { s->failed_pc=0x0c08b1d4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c08b1d6;
P_0c08b1d6: /* original 8b02, guest PC 0x0c08b1d6 */
if(!s->budget--) { s->failed_pc=0x0c08b1d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b1de; }
goto P_0c08b1d8;
P_0c08b1d8: /* original e002, guest PC 0x0c08b1d8 */
if(!s->budget--) { s->failed_pc=0x0c08b1d8u; return 0; }
r[0]=0x00000002u;
goto P_0c08b1da;
P_0c08b1da: /* original 000b, guest PC 0x0c08b1da */
if(!s->budget--) { s->failed_pc=0x0c08b1dau; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c08b1dc: /* original 7f04, guest PC 0x0c08b1dc */
if(!s->budget--) { s->failed_pc=0x0c08b1dcu; return 0; }
r[15]+=0x00000004u;
goto P_0c08b1de;
P_0c08b1de: /* original e001, guest PC 0x0c08b1de */
if(!s->budget--) { s->failed_pc=0x0c08b1deu; return 0; }
r[0]=0x00000001u;
goto P_0c08b1e0;
P_0c08b1e0: /* original 000b, guest PC 0x0c08b1e0 */
if(!s->budget--) { s->failed_pc=0x0c08b1e0u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c08b1e2: /* original 7f04, guest PC 0x0c08b1e2 */
if(!s->budget--) { s->failed_pc=0x0c08b1e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c08b1e4;
P_0c08b1e4: /* original e000, guest PC 0x0c08b1e4 */
if(!s->budget--) { s->failed_pc=0x0c08b1e4u; return 0; }
r[0]=0x00000000u;
goto P_0c08b1e6;
P_0c08b1e6: /* original 000b, guest PC 0x0c08b1e6 */
if(!s->budget--) { s->failed_pc=0x0c08b1e6u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c08b1e8: /* original 7f04, guest PC 0x0c08b1e8 */
if(!s->budget--) { s->failed_pc=0x0c08b1e8u; return 0; }
r[15]+=0x00000004u;
goto P_0c08b1ea;
P_0c08b1ea: /* original 2fe6, guest PC 0x0c08b1ea */
if(!s->budget--) { s->failed_pc=0x0c08b1eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b1ec;
P_0c08b1ec: /* original 2fd6, guest PC 0x0c08b1ec */
if(!s->budget--) { s->failed_pc=0x0c08b1ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b1ee;
P_0c08b1ee: /* original 2fc6, guest PC 0x0c08b1ee */
if(!s->budget--) { s->failed_pc=0x0c08b1eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b1f0;
P_0c08b1f0: /* original 2fb6, guest PC 0x0c08b1f0 */
if(!s->budget--) { s->failed_pc=0x0c08b1f0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b1f2;
P_0c08b1f2: /* original 2fa6, guest PC 0x0c08b1f2 */
if(!s->budget--) { s->failed_pc=0x0c08b1f2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b1f4;
P_0c08b1f4: /* original 2f96, guest PC 0x0c08b1f4 */
if(!s->budget--) { s->failed_pc=0x0c08b1f4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b1f6;
P_0c08b1f6: /* original e90f, guest PC 0x0c08b1f6 */
if(!s->budget--) { s->failed_pc=0x0c08b1f6u; return 0; }
r[9]=0x0000000fu;
goto P_0c08b1f8;
P_0c08b1f8: /* original 2f86, guest PC 0x0c08b1f8 */
if(!s->budget--) { s->failed_pc=0x0c08b1f8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b1fa;
P_0c08b1fa: /* original fffb, guest PC 0x0c08b1fa */
if(!s->budget--) { s->failed_pc=0x0c08b1fau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08b1fc;
P_0c08b1fc: /* original ffeb, guest PC 0x0c08b1fc */
if(!s->budget--) { s->failed_pc=0x0c08b1fcu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08b1fe;
P_0c08b1fe: /* original ffdb, guest PC 0x0c08b1fe */
if(!s->budget--) { s->failed_pc=0x0c08b1feu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08b200;
P_0c08b200: /* original ffcb, guest PC 0x0c08b200 */
if(!s->budget--) { s->failed_pc=0x0c08b200u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08b202;
P_0c08b202: /* original d342, guest PC 0x0c08b202 */
if(!s->budget--) { s->failed_pc=0x0c08b202u; return 0; }
r[3]=read(ram,0x0c08b30cu,4);
goto P_0c08b204;
P_0c08b204: /* original 4f22, guest PC 0x0c08b204 */
if(!s->budget--) { s->failed_pc=0x0c08b204u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b206;
P_0c08b206: /* original 6030, guest PC 0x0c08b206 */
if(!s->budget--) { s->failed_pc=0x0c08b206u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c08b208;
P_0c08b208: /* original 600c, guest PC 0x0c08b208 */
if(!s->budget--) { s->failed_pc=0x0c08b208u; return 0; }
r[0]=r[0]&255u;
goto P_0c08b20a;
P_0c08b20a: /* original 2909, guest PC 0x0c08b20a */
if(!s->budget--) { s->failed_pc=0x0c08b20au; return 0; }
r[9]&=r[0];
goto P_0c08b20c;
P_0c08b20c: /* original 6a93, guest PC 0x0c08b20c */
if(!s->budget--) { s->failed_pc=0x0c08b20cu; return 0; }
r[10]=r[9];
goto P_0c08b20e;
P_0c08b20e: /* original 4a08, guest PC 0x0c08b20e */
if(!s->budget--) { s->failed_pc=0x0c08b20eu; return 0; }
r[10]<<=2;
goto P_0c08b210;
P_0c08b210: /* original 4a00, guest PC 0x0c08b210 */
if(!s->budget--) { s->failed_pc=0x0c08b210u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c08b212;
P_0c08b212: /* original 7ffc, guest PC 0x0c08b212 */
if(!s->budget--) { s->failed_pc=0x0c08b212u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08b214;
P_0c08b214: /* original 2fa2, guest PC 0x0c08b214 */
if(!s->budget--) { s->failed_pc=0x0c08b214u; return 0; }
write(ram,r[15],r[10],4);
goto P_0c08b216;
P_0c08b216: /* original d03e, guest PC 0x0c08b216 */
if(!s->budget--) { s->failed_pc=0x0c08b216u; return 0; }
r[0]=read(ram,0x0c08b310u,4);
goto P_0c08b218;
P_0c08b218: /* original 0aae, guest PC 0x0c08b218 */
if(!s->budget--) { s->failed_pc=0x0c08b218u; return 0; }
r[10]=read(ram,r[10]+r[0],4);
goto P_0c08b21a;
P_0c08b21a: /* original 2aa8, guest PC 0x0c08b21a */
if(!s->budget--) { s->failed_pc=0x0c08b21au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c08b21c;
P_0c08b21c: /* original 895f, guest PC 0x0c08b21c */
if(!s->budget--) { s->failed_pc=0x0c08b21cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b2de; }
goto P_0c08b21e;
P_0c08b21e: /* original d13d, guest PC 0x0c08b21e */
if(!s->budget--) { s->failed_pc=0x0c08b21eu; return 0; }
r[1]=read(ram,0x0c08b314u,4);
goto P_0c08b220;
P_0c08b220: /* original 410b, guest PC 0x0c08b220 */
if(!s->budget--) { s->failed_pc=0x0c08b220u; return 0; }
target=r[1];
r[16]=code_base|0x0c08b224u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b224u) { target=s->pc; goto dispatch; }
goto P_0c08b224;
P_0c08b222: /* original e400, guest PC 0x0c08b222 */
if(!s->budget--) { s->failed_pc=0x0c08b222u; return 0; }
r[4]=0x00000000u;
goto P_0c08b224;
P_0c08b224: /* original 6cf2, guest PC 0x0c08b224 */
if(!s->budget--) { s->failed_pc=0x0c08b224u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c08b226;
P_0c08b226: /* original d33a, guest PC 0x0c08b226 */
if(!s->budget--) { s->failed_pc=0x0c08b226u; return 0; }
r[3]=read(ram,0x0c08b310u,4);
goto P_0c08b228;
P_0c08b228: /* original d23b, guest PC 0x0c08b228 */
if(!s->budget--) { s->failed_pc=0x0c08b228u; return 0; }
r[2]=read(ram,0x0c08b318u,4);
goto P_0c08b22a;
P_0c08b22a: /* original 3c3c, guest PC 0x0c08b22a */
if(!s->budget--) { s->failed_pc=0x0c08b22au; return 0; }
r[12]+=r[3];
goto P_0c08b22c;
P_0c08b22c: /* original 420b, guest PC 0x0c08b22c */
if(!s->budget--) { s->failed_pc=0x0c08b22cu; return 0; }
target=r[2];
r[16]=code_base|0x0c08b230u;
r[12]=read(ram,r[12]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b230u) { target=s->pc; goto dispatch; }
goto P_0c08b230;
P_0c08b22e: /* original 5cc1, guest PC 0x0c08b22e */
if(!s->budget--) { s->failed_pc=0x0c08b22eu; return 0; }
r[12]=read(ram,r[12]+4,4);
goto P_0c08b230;
P_0c08b230: /* original c73a, guest PC 0x0c08b230 */
if(!s->budget--) { s->failed_pc=0x0c08b230u; return 0; }
r[0]=code_base|0x0008b31cu;
goto P_0c08b232;
P_0c08b232: /* original db3d, guest PC 0x0c08b232 */
if(!s->budget--) { s->failed_pc=0x0c08b232u; return 0; }
r[11]=read(ram,0x0c08b328u,4);
goto P_0c08b234;
P_0c08b234: /* original fc08, guest PC 0x0c08b234 */
if(!s->budget--) { s->failed_pc=0x0c08b234u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c08b236;
P_0c08b236: /* original c73a, guest PC 0x0c08b236 */
if(!s->budget--) { s->failed_pc=0x0c08b236u; return 0; }
r[0]=code_base|0x0008b320u;
goto P_0c08b238;
P_0c08b238: /* original fd08, guest PC 0x0c08b238 */
if(!s->budget--) { s->failed_pc=0x0c08b238u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c08b23a;
P_0c08b23a: /* original c73a, guest PC 0x0c08b23a */
if(!s->budget--) { s->failed_pc=0x0c08b23au; return 0; }
r[0]=code_base|0x0008b324u;
goto P_0c08b23c;
P_0c08b23c: /* original dd3b, guest PC 0x0c08b23c */
if(!s->budget--) { s->failed_pc=0x0c08b23cu; return 0; }
r[13]=read(ram,0x0c08b32cu,4);
goto P_0c08b23e;
P_0c08b23e: /* original 4a15, guest PC 0x0c08b23e */
if(!s->budget--) { s->failed_pc=0x0c08b23eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c08b240;
P_0c08b240: /* original fe08, guest PC 0x0c08b240 */
if(!s->budget--) { s->failed_pc=0x0c08b240u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c08b242;
P_0c08b242: /* original ee00, guest PC 0x0c08b242 */
if(!s->budget--) { s->failed_pc=0x0c08b242u; return 0; }
r[14]=0x00000000u;
goto P_0c08b244;
P_0c08b244: /* original 8f3b, guest PC 0x0c08b244 */
if(!s->budget--) { s->failed_pc=0x0c08b244u; return 0; }
cond=r[17]&1u;
fr[15]=0x3f800000u;
if(!cond) { goto P_0c08b2be; }
goto P_0c08b248;
P_0c08b246: /* original ff9d, guest PC 0x0c08b246 */
if(!s->budget--) { s->failed_pc=0x0c08b246u; return 0; }
fr[15]=0x3f800000u;
goto P_0c08b248;
P_0c08b248: /* original 65e3, guest PC 0x0c08b248 */
if(!s->budget--) { s->failed_pc=0x0c08b248u; return 0; }
r[5]=r[14];
goto P_0c08b24a;
P_0c08b24a: /* original bf8d, guest PC 0x0c08b24a */
if(!s->budget--) { s->failed_pc=0x0c08b24au; return 0; }
target=code_base|0x0c08b168u; r[16]=code_base|0x0c08b24eu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b24eu) { target=s->pc; goto dispatch; }
goto P_0c08b24e;
P_0c08b24c: /* original 6493, guest PC 0x0c08b24c */
if(!s->budget--) { s->failed_pc=0x0c08b24cu; return 0; }
r[4]=r[9];
goto P_0c08b24e;
P_0c08b24e: /* original 6403, guest PC 0x0c08b24e */
if(!s->budget--) { s->failed_pc=0x0c08b24eu; return 0; }
r[4]=r[0];
goto P_0c08b250;
P_0c08b250: /* original 604f, guest PC 0x0c08b250 */
if(!s->budget--) { s->failed_pc=0x0c08b250u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08b252;
P_0c08b252: /* original 8800, guest PC 0x0c08b252 */
if(!s->budget--) { s->failed_pc=0x0c08b252u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c08b254;
P_0c08b254: /* original 8905, guest PC 0x0c08b254 */
if(!s->budget--) { s->failed_pc=0x0c08b254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b262; }
goto P_0c08b256;
P_0c08b256: /* original 8801, guest PC 0x0c08b256 */
if(!s->budget--) { s->failed_pc=0x0c08b256u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08b258;
P_0c08b258: /* original 890a, guest PC 0x0c08b258 */
if(!s->budget--) { s->failed_pc=0x0c08b258u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b270; }
goto P_0c08b25a;
P_0c08b25a: /* original 8802, guest PC 0x0c08b25a */
if(!s->budget--) { s->failed_pc=0x0c08b25au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08b25c;
P_0c08b25c: /* original 891d, guest PC 0x0c08b25c */
if(!s->budget--) { s->failed_pc=0x0c08b25cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b29a; }
goto P_0c08b25e;
P_0c08b25e: /* original a02a, guest PC 0x0c08b25e */
if(!s->budget--) { s->failed_pc=0x0c08b25eu; return 0; }
goto P_0c08b2b6;
P_0c08b260: /* original 0009, guest PC 0x0c08b260 */
if(!s->budget--) { s->failed_pc=0x0c08b260u; return 0; }
goto P_0c08b262;
P_0c08b262: /* original 60e3, guest PC 0x0c08b262 */
if(!s->budget--) { s->failed_pc=0x0c08b262u; return 0; }
r[0]=r[14];
goto P_0c08b264;
P_0c08b264: /* original 4008, guest PC 0x0c08b264 */
if(!s->budget--) { s->failed_pc=0x0c08b264u; return 0; }
r[0]<<=2;
goto P_0c08b266;
P_0c08b266: /* original f4d6, guest PC 0x0c08b266 */
if(!s->budget--) { s->failed_pc=0x0c08b266u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c08b268;
P_0c08b268: /* original 4b0b, guest PC 0x0c08b268 */
if(!s->budget--) { s->failed_pc=0x0c08b268u; return 0; }
target=r[11];
r[16]=code_base|0x0c08b26cu;
tmp=read(ram,r[12],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b26cu) { target=s->pc; goto dispatch; }
goto P_0c08b26c;
P_0c08b26a: /* original 64c2, guest PC 0x0c08b26a */
if(!s->budget--) { s->failed_pc=0x0c08b26au; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c08b26c;
P_0c08b26c: /* original a023, guest PC 0x0c08b26c */
if(!s->budget--) { s->failed_pc=0x0c08b26cu; return 0; }
goto P_0c08b2b6;
P_0c08b26e: /* original 0009, guest PC 0x0c08b26e */
if(!s->budget--) { s->failed_pc=0x0c08b26eu; return 0; }
goto P_0c08b270;
P_0c08b270: /* original 68e3, guest PC 0x0c08b270 */
if(!s->budget--) { s->failed_pc=0x0c08b270u; return 0; }
r[8]=r[14];
goto P_0c08b272;
P_0c08b272: /* original 4808, guest PC 0x0c08b272 */
if(!s->budget--) { s->failed_pc=0x0c08b272u; return 0; }
r[8]<<=2;
goto P_0c08b274;
P_0c08b274: /* original 38dc, guest PC 0x0c08b274 */
if(!s->budget--) { s->failed_pc=0x0c08b274u; return 0; }
r[8]+=r[13];
goto P_0c08b276;
P_0c08b276: /* original f488, guest PC 0x0c08b276 */
if(!s->budget--) { s->failed_pc=0x0c08b276u; return 0; }
vf3_matrix_load(s,ram,4,r[8]);
goto P_0c08b278;
P_0c08b278: /* original 4b0b, guest PC 0x0c08b278 */
if(!s->budget--) { s->failed_pc=0x0c08b278u; return 0; }
target=r[11];
r[16]=code_base|0x0c08b27cu;
tmp=read(ram,r[12],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b27cu) { target=s->pc; goto dispatch; }
goto P_0c08b27c;
P_0c08b27a: /* original 64c2, guest PC 0x0c08b27a */
if(!s->budget--) { s->failed_pc=0x0c08b27au; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c08b27c;
P_0c08b27c: /* original c72c, guest PC 0x0c08b27c */
if(!s->budget--) { s->failed_pc=0x0c08b27cu; return 0; }
r[0]=code_base|0x0008b330u;
goto P_0c08b27e;
P_0c08b27e: /* original f288, guest PC 0x0c08b27e */
if(!s->budget--) { s->failed_pc=0x0c08b27eu; return 0; }
vf3_matrix_load(s,ram,2,r[8]);
goto P_0c08b280;
P_0c08b280: /* original f308, guest PC 0x0c08b280 */
if(!s->budget--) { s->failed_pc=0x0c08b280u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08b282;
P_0c08b282: /* original f325, guest PC 0x0c08b282 */
if(!s->budget--) { s->failed_pc=0x0c08b282u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c08b284;
P_0c08b284: /* original 8b05, guest PC 0x0c08b284 */
if(!s->budget--) { s->failed_pc=0x0c08b284u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b292; }
goto P_0c08b286;
P_0c08b286: /* original 60e3, guest PC 0x0c08b286 */
if(!s->budget--) { s->failed_pc=0x0c08b286u; return 0; }
r[0]=r[14];
goto P_0c08b288;
P_0c08b288: /* original 4008, guest PC 0x0c08b288 */
if(!s->budget--) { s->failed_pc=0x0c08b288u; return 0; }
r[0]<<=2;
goto P_0c08b28a;
P_0c08b28a: /* original f3d6, guest PC 0x0c08b28a */
if(!s->budget--) { s->failed_pc=0x0c08b28au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08b28c;
P_0c08b28c: /* original f3e2, guest PC 0x0c08b28c */
if(!s->budget--) { s->failed_pc=0x0c08b28cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c08b28e;
P_0c08b28e: /* original a012, guest PC 0x0c08b28e */
if(!s->budget--) { s->failed_pc=0x0c08b28eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08b2b6;
P_0c08b290: /* original fd37, guest PC 0x0c08b290 */
if(!s->budget--) { s->failed_pc=0x0c08b290u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08b292;
P_0c08b292: /* original 60e3, guest PC 0x0c08b292 */
if(!s->budget--) { s->failed_pc=0x0c08b292u; return 0; }
r[0]=r[14];
goto P_0c08b294;
P_0c08b294: /* original 4008, guest PC 0x0c08b294 */
if(!s->budget--) { s->failed_pc=0x0c08b294u; return 0; }
r[0]<<=2;
goto P_0c08b296;
P_0c08b296: /* original a00e, guest PC 0x0c08b296 */
if(!s->budget--) { s->failed_pc=0x0c08b296u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c08b2b6;
P_0c08b298: /* original fdf7, guest PC 0x0c08b298 */
if(!s->budget--) { s->failed_pc=0x0c08b298u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c08b29a;
P_0c08b29a: /* original 68e3, guest PC 0x0c08b29a */
if(!s->budget--) { s->failed_pc=0x0c08b29au; return 0; }
r[8]=r[14];
goto P_0c08b29c;
P_0c08b29c: /* original 4808, guest PC 0x0c08b29c */
if(!s->budget--) { s->failed_pc=0x0c08b29cu; return 0; }
r[8]<<=2;
goto P_0c08b29e;
P_0c08b29e: /* original 38dc, guest PC 0x0c08b29e */
if(!s->budget--) { s->failed_pc=0x0c08b29eu; return 0; }
r[8]+=r[13];
goto P_0c08b2a0;
P_0c08b2a0: /* original f488, guest PC 0x0c08b2a0 */
if(!s->budget--) { s->failed_pc=0x0c08b2a0u; return 0; }
vf3_matrix_load(s,ram,4,r[8]);
goto P_0c08b2a2;
P_0c08b2a2: /* original 4b0b, guest PC 0x0c08b2a2 */
if(!s->budget--) { s->failed_pc=0x0c08b2a2u; return 0; }
target=r[11];
r[16]=code_base|0x0c08b2a6u;
tmp=read(ram,r[12],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b2a6u) { target=s->pc; goto dispatch; }
goto P_0c08b2a6;
P_0c08b2a4: /* original 64c2, guest PC 0x0c08b2a4 */
if(!s->budget--) { s->failed_pc=0x0c08b2a4u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c08b2a6;
P_0c08b2a6: /* original f388, guest PC 0x0c08b2a6 */
if(!s->budget--) { s->failed_pc=0x0c08b2a6u; return 0; }
vf3_matrix_load(s,ram,3,r[8]);
goto P_0c08b2a8;
P_0c08b2a8: /* original f3d5, guest PC 0x0c08b2a8 */
if(!s->budget--) { s->failed_pc=0x0c08b2a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[13]))!=0);
goto P_0c08b2aa;
P_0c08b2aa: /* original 8b04, guest PC 0x0c08b2aa */
if(!s->budget--) { s->failed_pc=0x0c08b2aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b2b6; }
goto P_0c08b2ac;
P_0c08b2ac: /* original 60e3, guest PC 0x0c08b2ac */
if(!s->budget--) { s->failed_pc=0x0c08b2acu; return 0; }
r[0]=r[14];
goto P_0c08b2ae;
P_0c08b2ae: /* original 4008, guest PC 0x0c08b2ae */
if(!s->budget--) { s->failed_pc=0x0c08b2aeu; return 0; }
r[0]<<=2;
goto P_0c08b2b0;
P_0c08b2b0: /* original f3d6, guest PC 0x0c08b2b0 */
if(!s->budget--) { s->failed_pc=0x0c08b2b0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08b2b2;
P_0c08b2b2: /* original f3c2, guest PC 0x0c08b2b2 */
if(!s->budget--) { s->failed_pc=0x0c08b2b2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c08b2b4;
P_0c08b2b4: /* original fd37, guest PC 0x0c08b2b4 */
if(!s->budget--) { s->failed_pc=0x0c08b2b4u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08b2b6;
P_0c08b2b6: /* original 7e01, guest PC 0x0c08b2b6 */
if(!s->budget--) { s->failed_pc=0x0c08b2b6u; return 0; }
r[14]+=0x00000001u;
goto P_0c08b2b8;
P_0c08b2b8: /* original 3ea3, guest PC 0x0c08b2b8 */
if(!s->budget--) { s->failed_pc=0x0c08b2b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[10])!=0);
goto P_0c08b2ba;
P_0c08b2ba: /* original 8fc5, guest PC 0x0c08b2ba */
if(!s->budget--) { s->failed_pc=0x0c08b2bau; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c08b248; }
goto P_0c08b2be;
P_0c08b2bc: /* original 7c04, guest PC 0x0c08b2bc */
if(!s->budget--) { s->failed_pc=0x0c08b2bcu; return 0; }
r[12]+=0x00000004u;
goto P_0c08b2be;
P_0c08b2be: /* original 7f04, guest PC 0x0c08b2be */
if(!s->budget--) { s->failed_pc=0x0c08b2beu; return 0; }
r[15]+=0x00000004u;
goto P_0c08b2c0;
P_0c08b2c0: /* original d31c, guest PC 0x0c08b2c0 */
if(!s->budget--) { s->failed_pc=0x0c08b2c0u; return 0; }
r[3]=read(ram,0x0c08b334u,4);
goto P_0c08b2c2;
P_0c08b2c2: /* original 4f26, guest PC 0x0c08b2c2 */
if(!s->budget--) { s->failed_pc=0x0c08b2c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b2c4;
P_0c08b2c4: /* original e401, guest PC 0x0c08b2c4 */
if(!s->budget--) { s->failed_pc=0x0c08b2c4u; return 0; }
r[4]=0x00000001u;
goto P_0c08b2c6;
P_0c08b2c6: /* original fcf9, guest PC 0x0c08b2c6 */
if(!s->budget--) { s->failed_pc=0x0c08b2c6u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2c8;
P_0c08b2c8: /* original fdf9, guest PC 0x0c08b2c8 */
if(!s->budget--) { s->failed_pc=0x0c08b2c8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2ca;
P_0c08b2ca: /* original fef9, guest PC 0x0c08b2ca */
if(!s->budget--) { s->failed_pc=0x0c08b2cau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2cc;
P_0c08b2cc: /* original fff9, guest PC 0x0c08b2cc */
if(!s->budget--) { s->failed_pc=0x0c08b2ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2ce;
P_0c08b2ce: /* original 68f6, guest PC 0x0c08b2ce */
if(!s->budget--) { s->failed_pc=0x0c08b2ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b2d0;
P_0c08b2d0: /* original 69f6, guest PC 0x0c08b2d0 */
if(!s->budget--) { s->failed_pc=0x0c08b2d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b2d2;
P_0c08b2d2: /* original 6af6, guest PC 0x0c08b2d2 */
if(!s->budget--) { s->failed_pc=0x0c08b2d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b2d4;
P_0c08b2d4: /* original 6bf6, guest PC 0x0c08b2d4 */
if(!s->budget--) { s->failed_pc=0x0c08b2d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b2d6;
P_0c08b2d6: /* original 6cf6, guest PC 0x0c08b2d6 */
if(!s->budget--) { s->failed_pc=0x0c08b2d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b2d8;
P_0c08b2d8: /* original 6df6, guest PC 0x0c08b2d8 */
if(!s->budget--) { s->failed_pc=0x0c08b2d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b2da;
P_0c08b2da: /* original 432b, guest PC 0x0c08b2da */
if(!s->budget--) { s->failed_pc=0x0c08b2dau; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c08b2dc: /* original 6ef6, guest PC 0x0c08b2dc */
if(!s->budget--) { s->failed_pc=0x0c08b2dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b2de;
P_0c08b2de: /* original 7f04, guest PC 0x0c08b2de */
if(!s->budget--) { s->failed_pc=0x0c08b2deu; return 0; }
r[15]+=0x00000004u;
goto P_0c08b2e0;
P_0c08b2e0: /* original 4f26, guest PC 0x0c08b2e0 */
if(!s->budget--) { s->failed_pc=0x0c08b2e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b2e2;
P_0c08b2e2: /* original fcf9, guest PC 0x0c08b2e2 */
if(!s->budget--) { s->failed_pc=0x0c08b2e2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2e4;
P_0c08b2e4: /* original fdf9, guest PC 0x0c08b2e4 */
if(!s->budget--) { s->failed_pc=0x0c08b2e4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2e6;
P_0c08b2e6: /* original fef9, guest PC 0x0c08b2e6 */
if(!s->budget--) { s->failed_pc=0x0c08b2e6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2e8;
P_0c08b2e8: /* original fff9, guest PC 0x0c08b2e8 */
if(!s->budget--) { s->failed_pc=0x0c08b2e8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2ea;
P_0c08b2ea: /* original 68f6, guest PC 0x0c08b2ea */
if(!s->budget--) { s->failed_pc=0x0c08b2eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b2ec;
P_0c08b2ec: /* original 69f6, guest PC 0x0c08b2ec */
if(!s->budget--) { s->failed_pc=0x0c08b2ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b2ee;
P_0c08b2ee: /* original 6af6, guest PC 0x0c08b2ee */
if(!s->budget--) { s->failed_pc=0x0c08b2eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b2f0;
P_0c08b2f0: /* original 6bf6, guest PC 0x0c08b2f0 */
if(!s->budget--) { s->failed_pc=0x0c08b2f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b2f2;
P_0c08b2f2: /* original 6cf6, guest PC 0x0c08b2f2 */
if(!s->budget--) { s->failed_pc=0x0c08b2f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b2f4;
P_0c08b2f4: /* original 6df6, guest PC 0x0c08b2f4 */
if(!s->budget--) { s->failed_pc=0x0c08b2f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b2f6;
P_0c08b2f6: /* original 000b, guest PC 0x0c08b2f6 */
if(!s->budget--) { s->failed_pc=0x0c08b2f6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b2f8: /* original 6ef6, guest PC 0x0c08b2f8 */
if(!s->budget--) { s->failed_pc=0x0c08b2f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08b2fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08b2fau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
