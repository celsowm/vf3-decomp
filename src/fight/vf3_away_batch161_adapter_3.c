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
int vf3_away_batch161_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c4e34u: goto P_0c0c4e34;
case 0x0c0c4e36u: goto P_0c0c4e36;
case 0x0c0c4e38u: goto P_0c0c4e38;
case 0x0c0c4e3au: goto P_0c0c4e3a;
case 0x0c0c4e3cu: goto P_0c0c4e3c;
case 0x0c0c4e3eu: goto P_0c0c4e3e;
case 0x0c0c4e40u: goto P_0c0c4e40;
case 0x0c0c4e42u: goto P_0c0c4e42;
case 0x0c0c4e44u: goto P_0c0c4e44;
case 0x0c0c4e46u: goto P_0c0c4e46;
case 0x0c0c4e48u: goto P_0c0c4e48;
case 0x0c0c4e4au: goto P_0c0c4e4a;
case 0x0c0c4e4cu: goto P_0c0c4e4c;
case 0x0c0c4e4eu: goto P_0c0c4e4e;
case 0x0c0c4e50u: goto P_0c0c4e50;
case 0x0c0c4e52u: goto P_0c0c4e52;
case 0x0c0c4e54u: goto P_0c0c4e54;
case 0x0c0c4e56u: goto P_0c0c4e56;
case 0x0c0c4e58u: goto P_0c0c4e58;
case 0x0c0c4e5au: goto P_0c0c4e5a;
case 0x0c0c4e5cu: goto P_0c0c4e5c;
case 0x0c0c4e5eu: goto P_0c0c4e5e;
case 0x0c0c4e60u: goto P_0c0c4e60;
case 0x0c0c4e62u: goto P_0c0c4e62;
case 0x0c0c4e64u: goto P_0c0c4e64;
case 0x0c0c4e66u: goto P_0c0c4e66;
case 0x0c0c4e68u: goto P_0c0c4e68;
case 0x0c0c4e6au: goto P_0c0c4e6a;
case 0x0c0c4e6cu: goto P_0c0c4e6c;
case 0x0c0c4e6eu: goto P_0c0c4e6e;
case 0x0c0c4e70u: goto P_0c0c4e70;
case 0x0c0c4e72u: goto P_0c0c4e72;
case 0x0c0c4e74u: goto P_0c0c4e74;
case 0x0c0c4e76u: goto P_0c0c4e76;
case 0x0c0c4e78u: goto P_0c0c4e78;
case 0x0c0c4e7au: goto P_0c0c4e7a;
case 0x0c0c4e7cu: goto P_0c0c4e7c;
case 0x0c0c4e7eu: goto P_0c0c4e7e;
case 0x0c0c4e80u: goto P_0c0c4e80;
case 0x0c0c4e82u: goto P_0c0c4e82;
case 0x0c0c4e84u: goto P_0c0c4e84;
case 0x0c0c4e86u: goto P_0c0c4e86;
case 0x0c0c4e88u: goto P_0c0c4e88;
case 0x0c0c4e8au: goto P_0c0c4e8a;
case 0x0c0c4e8cu: goto P_0c0c4e8c;
case 0x0c0c4e8eu: goto P_0c0c4e8e;
case 0x0c0c4e90u: goto P_0c0c4e90;
case 0x0c0c4e92u: goto P_0c0c4e92;
case 0x0c0c4e94u: goto P_0c0c4e94;
case 0x0c0c4e96u: goto P_0c0c4e96;
case 0x0c0c4e98u: goto P_0c0c4e98;
case 0x0c0c4e9au: goto P_0c0c4e9a;
case 0x0c0c4e9cu: goto P_0c0c4e9c;
case 0x0c0c4e9eu: goto P_0c0c4e9e;
case 0x0c0c4ea0u: goto P_0c0c4ea0;
case 0x0c0c4ea2u: goto P_0c0c4ea2;
case 0x0c0c4ea4u: goto P_0c0c4ea4;
case 0x0c0c4ea6u: goto P_0c0c4ea6;
case 0x0c0c4ea8u: goto P_0c0c4ea8;
case 0x0c0c4eaau: goto P_0c0c4eaa;
case 0x0c0c4eacu: goto P_0c0c4eac;
case 0x0c0c4eaeu: goto P_0c0c4eae;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c4e34: /* original 2fe6, guest PC 0x0c0c4e34 */
if(!s->budget--) { s->failed_pc=0x0c0c4e34u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e36;
P_0c0c4e36: /* original 2fd6, guest PC 0x0c0c4e36 */
if(!s->budget--) { s->failed_pc=0x0c0c4e36u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e38;
P_0c0c4e38: /* original ed00, guest PC 0x0c0c4e38 */
if(!s->budget--) { s->failed_pc=0x0c0c4e38u; return 0; }
r[13]=0x00000000u;
goto P_0c0c4e3a;
P_0c0c4e3a: /* original 2fc6, guest PC 0x0c0c4e3a */
if(!s->budget--) { s->failed_pc=0x0c0c4e3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e3c;
P_0c0c4e3c: /* original 6ed3, guest PC 0x0c0c4e3c */
if(!s->budget--) { s->failed_pc=0x0c0c4e3cu; return 0; }
r[14]=r[13];
goto P_0c0c4e3e;
P_0c0c4e3e: /* original 2fb6, guest PC 0x0c0c4e3e */
if(!s->budget--) { s->failed_pc=0x0c0c4e3eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e40;
P_0c0c4e40: /* original 2fa6, guest PC 0x0c0c4e40 */
if(!s->budget--) { s->failed_pc=0x0c0c4e40u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e42;
P_0c0c4e42: /* original 2f96, guest PC 0x0c0c4e42 */
if(!s->budget--) { s->failed_pc=0x0c0c4e42u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e44;
P_0c0c4e44: /* original 2f86, guest PC 0x0c0c4e44 */
if(!s->budget--) { s->failed_pc=0x0c0c4e44u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e46;
P_0c0c4e46: /* original fffb, guest PC 0x0c0c4e46 */
if(!s->budget--) { s->failed_pc=0x0c0c4e46u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c4e48;
P_0c0c4e48: /* original ffeb, guest PC 0x0c0c4e48 */
if(!s->budget--) { s->failed_pc=0x0c0c4e48u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c4e4a;
P_0c0c4e4a: /* original 4f22, guest PC 0x0c0c4e4a */
if(!s->budget--) { s->failed_pc=0x0c0c4e4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4e4c;
P_0c0c4e4c: /* original 7ff8, guest PC 0x0c0c4e4c */
if(!s->budget--) { s->failed_pc=0x0c0c4e4cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c4e4e;
P_0c0c4e4e: /* original 2f42, guest PC 0x0c0c4e4e */
if(!s->budget--) { s->failed_pc=0x0c0c4e4eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c4e50;
P_0c0c4e50: /* original 9078, guest PC 0x0c0c4e50 */
if(!s->budget--) { s->failed_pc=0x0c0c4e50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f44u,2);
goto P_0c0c4e52;
P_0c0c4e52: /* original 9876, guest PC 0x0c0c4e52 */
if(!s->budget--) { s->failed_pc=0x0c0c4e52u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f42u,2);
goto P_0c0c4e54;
P_0c0c4e54: /* original 81f2, guest PC 0x0c0c4e54 */
if(!s->budget--) { s->failed_pc=0x0c0c4e54u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0c4e56;
P_0c0c4e56: /* original c740, guest PC 0x0c0c4e56 */
if(!s->budget--) { s->failed_pc=0x0c0c4e56u; return 0; }
r[0]=code_base|0x000c4f58u;
goto P_0c0c4e58;
P_0c0c4e58: /* original fe08, guest PC 0x0c0c4e58 */
if(!s->budget--) { s->failed_pc=0x0c0c4e58u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c4e5a;
P_0c0c4e5a: /* original c740, guest PC 0x0c0c4e5a */
if(!s->budget--) { s->failed_pc=0x0c0c4e5au; return 0; }
r[0]=code_base|0x000c4f5cu;
goto P_0c0c4e5c;
P_0c0c4e5c: /* original 69f2, guest PC 0x0c0c4e5c */
if(!s->budget--) { s->failed_pc=0x0c0c4e5cu; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c0c4e5e;
P_0c0c4e5e: /* original 9b72, guest PC 0x0c0c4e5e */
if(!s->budget--) { s->failed_pc=0x0c0c4e5eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f46u,2);
goto P_0c0c4e60;
P_0c0c4e60: /* original dc3f, guest PC 0x0c0c4e60 */
if(!s->budget--) { s->failed_pc=0x0c0c4e60u; return 0; }
r[12]=read(ram,0x0c0c4f60u,4);
goto P_0c0c4e62;
P_0c0c4e62: /* original 7904, guest PC 0x0c0c4e62 */
if(!s->budget--) { s->failed_pc=0x0c0c4e62u; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e64;
P_0c0c4e64: /* original ff08, guest PC 0x0c0c4e64 */
if(!s->budget--) { s->failed_pc=0x0c0c4e64u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c4e66;
P_0c0c4e66: /* original 85f2, guest PC 0x0c0c4e66 */
if(!s->budget--) { s->failed_pc=0x0c0c4e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0c4e68;
P_0c0c4e68: /* original 3d8c, guest PC 0x0c0c4e68 */
if(!s->budget--) { s->failed_pc=0x0c0c4e68u; return 0; }
r[13]+=r[8];
goto P_0c0c4e6a;
P_0c0c4e6a: /* original 3e0c, guest PC 0x0c0c4e6a */
if(!s->budget--) { s->failed_pc=0x0c0c4e6au; return 0; }
r[14]+=r[0];
goto P_0c0c4e6c;
P_0c0c4e6c: /* original 4c0b, guest PC 0x0c0c4e6c */
if(!s->budget--) { s->failed_pc=0x0c0c4e6cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c4e70u;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4e70u) { target=s->pc; goto dispatch; }
goto P_0c0c4e70;
P_0c0c4e6e: /* original 64ef, guest PC 0x0c0c4e6e */
if(!s->budget--) { s->failed_pc=0x0c0c4e6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c4e70;
P_0c0c4e70: /* original f4fc, guest PC 0x0c0c4e70 */
if(!s->budget--) { s->failed_pc=0x0c0c4e70u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c4e72;
P_0c0c4e72: /* original 6add, guest PC 0x0c0c4e72 */
if(!s->budget--) { s->failed_pc=0x0c0c4e72u; return 0; }
r[10]=r[13]&65535u;
goto P_0c0c4e74;
P_0c0c4e74: /* original f30c, guest PC 0x0c0c4e74 */
if(!s->budget--) { s->failed_pc=0x0c0c4e74u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e76;
P_0c0c4e76: /* original f432, guest PC 0x0c0c4e76 */
if(!s->budget--) { s->failed_pc=0x0c0c4e76u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e78;
P_0c0c4e78: /* original f43d, guest PC 0x0c0c4e78 */
if(!s->budget--) { s->failed_pc=0x0c0c4e78u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c4e7a;
P_0c0c4e7a: /* original 045a, guest PC 0x0c0c4e7a */
if(!s->budget--) { s->failed_pc=0x0c0c4e7au; return 0; }
r[4]=r[53];
goto P_0c0c4e7c;
P_0c0c4e7c: /* original 3a4c, guest PC 0x0c0c4e7c */
if(!s->budget--) { s->failed_pc=0x0c0c4e7cu; return 0; }
r[10]+=r[4];
goto P_0c0c4e7e;
P_0c0c4e7e: /* original 4c0b, guest PC 0x0c0c4e7e */
if(!s->budget--) { s->failed_pc=0x0c0c4e7eu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c4e82u;
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4e82u) { target=s->pc; goto dispatch; }
goto P_0c0c4e82;
P_0c0c4e80: /* original 64af, guest PC 0x0c0c4e80 */
if(!s->budget--) { s->failed_pc=0x0c0c4e80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c0c4e82;
P_0c0c4e82: /* original f4ec, guest PC 0x0c0c4e82 */
if(!s->budget--) { s->failed_pc=0x0c0c4e82u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c4e84;
P_0c0c4e84: /* original 4b10, guest PC 0x0c0c4e84 */
if(!s->budget--) { s->failed_pc=0x0c0c4e84u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0c4e86;
P_0c0c4e86: /* original f30c, guest PC 0x0c0c4e86 */
if(!s->budget--) { s->failed_pc=0x0c0c4e86u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e88;
P_0c0c4e88: /* original f432, guest PC 0x0c0c4e88 */
if(!s->budget--) { s->failed_pc=0x0c0c4e88u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e8a;
P_0c0c4e8a: /* original 7904, guest PC 0x0c0c4e8a */
if(!s->budget--) { s->failed_pc=0x0c0c4e8au; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e8c;
P_0c0c4e8c: /* original 8feb, guest PC 0x0c0c4e8c */
if(!s->budget--) { s->failed_pc=0x0c0c4e8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[9]);
if(!cond) { goto P_0c0c4e66; }
goto P_0c0c4e90;
P_0c0c4e8e: /* original f94a, guest PC 0x0c0c4e8e */
if(!s->budget--) { s->failed_pc=0x0c0c4e8eu; return 0; }
vf3_matrix_store(s,ram,4,r[9]);
goto P_0c0c4e90;
P_0c0c4e90: /* original 62f2, guest PC 0x0c0c4e90 */
if(!s->budget--) { s->failed_pc=0x0c0c4e90u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c4e92;
P_0c0c4e92: /* original 7f08, guest PC 0x0c0c4e92 */
if(!s->budget--) { s->failed_pc=0x0c0c4e92u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c4e94;
P_0c0c4e94: /* original 4f26, guest PC 0x0c0c4e94 */
if(!s->budget--) { s->failed_pc=0x0c0c4e94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4e96;
P_0c0c4e96: /* original 9057, guest PC 0x0c0c4e96 */
if(!s->budget--) { s->failed_pc=0x0c0c4e96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f48u,2);
goto P_0c0c4e98;
P_0c0c4e98: /* original e300, guest PC 0x0c0c4e98 */
if(!s->budget--) { s->failed_pc=0x0c0c4e98u; return 0; }
r[3]=0x00000000u;
goto P_0c0c4e9a;
P_0c0c4e9a: /* original 0236, guest PC 0x0c0c4e9a */
if(!s->budget--) { s->failed_pc=0x0c0c4e9au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c4e9c;
P_0c0c4e9c: /* original fef9, guest PC 0x0c0c4e9c */
if(!s->budget--) { s->failed_pc=0x0c0c4e9cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4e9e;
P_0c0c4e9e: /* original fff9, guest PC 0x0c0c4e9e */
if(!s->budget--) { s->failed_pc=0x0c0c4e9eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4ea0;
P_0c0c4ea0: /* original 68f6, guest PC 0x0c0c4ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c4ea2;
P_0c0c4ea2: /* original 69f6, guest PC 0x0c0c4ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c4ea4;
P_0c0c4ea4: /* original 6af6, guest PC 0x0c0c4ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c4ea6;
P_0c0c4ea6: /* original 6bf6, guest PC 0x0c0c4ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c4ea8;
P_0c0c4ea8: /* original 6cf6, guest PC 0x0c0c4ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c4eaa;
P_0c0c4eaa: /* original 6df6, guest PC 0x0c0c4eaa */
if(!s->budget--) { s->failed_pc=0x0c0c4eaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4eac;
P_0c0c4eac: /* original 000b, guest PC 0x0c0c4eac */
if(!s->budget--) { s->failed_pc=0x0c0c4eacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4eae: /* original 6ef6, guest PC 0x0c0c4eae */
if(!s->budget--) { s->failed_pc=0x0c0c4eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c4eb0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4eb0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
