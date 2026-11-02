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
int vf3_away_batch246_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c5e7au: goto P_0c0c5e7a;
case 0x0c0c5e7cu: goto P_0c0c5e7c;
case 0x0c0c5e7eu: goto P_0c0c5e7e;
case 0x0c0c5e80u: goto P_0c0c5e80;
case 0x0c0c5e82u: goto P_0c0c5e82;
case 0x0c0c5e84u: goto P_0c0c5e84;
case 0x0c0c5e86u: goto P_0c0c5e86;
case 0x0c0c5e88u: goto P_0c0c5e88;
case 0x0c0c5e8au: goto P_0c0c5e8a;
case 0x0c0c5e8cu: goto P_0c0c5e8c;
case 0x0c0c5e8eu: goto P_0c0c5e8e;
case 0x0c0c5e90u: goto P_0c0c5e90;
case 0x0c0c5e92u: goto P_0c0c5e92;
case 0x0c0c5e94u: goto P_0c0c5e94;
case 0x0c0c5e96u: goto P_0c0c5e96;
case 0x0c0c5e98u: goto P_0c0c5e98;
case 0x0c0c5e9au: goto P_0c0c5e9a;
case 0x0c0c5e9cu: goto P_0c0c5e9c;
case 0x0c0c5e9eu: goto P_0c0c5e9e;
case 0x0c0c5ea0u: goto P_0c0c5ea0;
case 0x0c0c5ea2u: goto P_0c0c5ea2;
case 0x0c0c5ea4u: goto P_0c0c5ea4;
case 0x0c0c5ea6u: goto P_0c0c5ea6;
case 0x0c0c5ea8u: goto P_0c0c5ea8;
case 0x0c0c5eaau: goto P_0c0c5eaa;
case 0x0c0c5eacu: goto P_0c0c5eac;
case 0x0c0c5eaeu: goto P_0c0c5eae;
case 0x0c0c5eb0u: goto P_0c0c5eb0;
case 0x0c0c5eb2u: goto P_0c0c5eb2;
case 0x0c0c5eb4u: goto P_0c0c5eb4;
case 0x0c0c5eb6u: goto P_0c0c5eb6;
case 0x0c0c5eb8u: goto P_0c0c5eb8;
case 0x0c0c5ebau: goto P_0c0c5eba;
case 0x0c0c5ebcu: goto P_0c0c5ebc;
case 0x0c0c5ebeu: goto P_0c0c5ebe;
case 0x0c0c5ec0u: goto P_0c0c5ec0;
case 0x0c0c5ec2u: goto P_0c0c5ec2;
case 0x0c0c5ec4u: goto P_0c0c5ec4;
case 0x0c0c5ec6u: goto P_0c0c5ec6;
case 0x0c0c5ec8u: goto P_0c0c5ec8;
case 0x0c0c5ecau: goto P_0c0c5eca;
case 0x0c0c5eccu: goto P_0c0c5ecc;
case 0x0c0c5eceu: goto P_0c0c5ece;
case 0x0c0c5ed0u: goto P_0c0c5ed0;
case 0x0c0c5ed2u: goto P_0c0c5ed2;
case 0x0c0c5ed4u: goto P_0c0c5ed4;
case 0x0c0c5ed6u: goto P_0c0c5ed6;
case 0x0c0c5ed8u: goto P_0c0c5ed8;
case 0x0c0c5edau: goto P_0c0c5eda;
case 0x0c0c5edcu: goto P_0c0c5edc;
case 0x0c0c5edeu: goto P_0c0c5ede;
case 0x0c0c5ee0u: goto P_0c0c5ee0;
case 0x0c0c5ee2u: goto P_0c0c5ee2;
case 0x0c0c5ee4u: goto P_0c0c5ee4;
case 0x0c0c5ee6u: goto P_0c0c5ee6;
case 0x0c0c5ee8u: goto P_0c0c5ee8;
case 0x0c0c5eeau: goto P_0c0c5eea;
case 0x0c0c5eecu: goto P_0c0c5eec;
case 0x0c0c5eeeu: goto P_0c0c5eee;
case 0x0c0c5ef0u: goto P_0c0c5ef0;
case 0x0c0c5ef2u: goto P_0c0c5ef2;
case 0x0c0c5ef4u: goto P_0c0c5ef4;
case 0x0c0c5ef6u: goto P_0c0c5ef6;
case 0x0c0c5ef8u: goto P_0c0c5ef8;
case 0x0c0c5efau: goto P_0c0c5efa;
case 0x0c0c5efcu: goto P_0c0c5efc;
case 0x0c0c5efeu: goto P_0c0c5efe;
case 0x0c0c5f00u: goto P_0c0c5f00;
case 0x0c0c5f02u: goto P_0c0c5f02;
case 0x0c0c5f04u: goto P_0c0c5f04;
case 0x0c0c5f06u: goto P_0c0c5f06;
case 0x0c0c5f08u: goto P_0c0c5f08;
case 0x0c0c5f0au: goto P_0c0c5f0a;
case 0x0c0c5f0cu: goto P_0c0c5f0c;
case 0x0c0c5f0eu: goto P_0c0c5f0e;
case 0x0c0c5f10u: goto P_0c0c5f10;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c5e7a: /* original 2fe6, guest PC 0x0c0c5e7a */
if(!s->budget--) { s->failed_pc=0x0c0c5e7au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5e7c;
P_0c0c5e7c: /* original e705, guest PC 0x0c0c5e7c */
if(!s->budget--) { s->failed_pc=0x0c0c5e7cu; return 0; }
r[7]=0x00000005u;
goto P_0c0c5e7e;
P_0c0c5e7e: /* original 2fd6, guest PC 0x0c0c5e7e */
if(!s->budget--) { s->failed_pc=0x0c0c5e7eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5e80;
P_0c0c5e80: /* original ee06, guest PC 0x0c0c5e80 */
if(!s->budget--) { s->failed_pc=0x0c0c5e80u; return 0; }
r[14]=0x00000006u;
goto P_0c0c5e82;
P_0c0c5e82: /* original 2fc6, guest PC 0x0c0c5e82 */
if(!s->budget--) { s->failed_pc=0x0c0c5e82u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5e84;
P_0c0c5e84: /* original 6573, guest PC 0x0c0c5e84 */
if(!s->budget--) { s->failed_pc=0x0c0c5e84u; return 0; }
r[5]=r[7];
goto P_0c0c5e86;
P_0c0c5e86: /* original 4f22, guest PC 0x0c0c5e86 */
if(!s->budget--) { s->failed_pc=0x0c0c5e86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5e88;
P_0c0c5e88: /* original d425, guest PC 0x0c0c5e88 */
if(!s->budget--) { s->failed_pc=0x0c0c5e88u; return 0; }
r[4]=read(ram,0x0c0c5f20u,4);
goto P_0c0c5e8a;
P_0c0c5e8a: /* original e600, guest PC 0x0c0c5e8a */
if(!s->budget--) { s->failed_pc=0x0c0c5e8au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5e8c;
P_0c0c5e8c: /* original 7501, guest PC 0x0c0c5e8c */
if(!s->budget--) { s->failed_pc=0x0c0c5e8cu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c5e8e;
P_0c0c5e8e: /* original 2462, guest PC 0x0c0c5e8e */
if(!s->budget--) { s->failed_pc=0x0c0c5e8eu; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0c5e90;
P_0c0c5e90: /* original 35e7, guest PC 0x0c0c5e90 */
if(!s->budget--) { s->failed_pc=0x0c0c5e90u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[14])!=0);
goto P_0c0c5e92;
P_0c0c5e92: /* original 8ffb, guest PC 0x0c0c5e92 */
if(!s->budget--) { s->failed_pc=0x0c0c5e92u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c0c5e8c; }
goto P_0c0c5e96;
P_0c0c5e94: /* original 7404, guest PC 0x0c0c5e94 */
if(!s->budget--) { s->failed_pc=0x0c0c5e94u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c5e96;
P_0c0c5e96: /* original dc21, guest PC 0x0c0c5e96 */
if(!s->budget--) { s->failed_pc=0x0c0c5e96u; return 0; }
r[12]=read(ram,0x0c0c5f1cu,4);
goto P_0c0c5e98;
P_0c0c5e98: /* original 6d73, guest PC 0x0c0c5e98 */
if(!s->budget--) { s->failed_pc=0x0c0c5e98u; return 0; }
r[13]=r[7];
goto P_0c0c5e9a;
P_0c0c5e9a: /* original 4c0b, guest PC 0x0c0c5e9a */
if(!s->budget--) { s->failed_pc=0x0c0c5e9au; return 0; }
target=r[12];
r[16]=code_base|0x0c0c5e9eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5e9eu) { target=s->pc; goto dispatch; }
goto P_0c0c5e9e;
P_0c0c5e9c: /* original 64d3, guest PC 0x0c0c5e9c */
if(!s->budget--) { s->failed_pc=0x0c0c5e9cu; return 0; }
r[4]=r[13];
goto P_0c0c5e9e;
P_0c0c5e9e: /* original 7d01, guest PC 0x0c0c5e9e */
if(!s->budget--) { s->failed_pc=0x0c0c5e9eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c5ea0;
P_0c0c5ea0: /* original 3de7, guest PC 0x0c0c5ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[14])!=0);
goto P_0c0c5ea2;
P_0c0c5ea2: /* original 8bfa, guest PC 0x0c0c5ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5e9a; }
goto P_0c0c5ea4;
P_0c0c5ea4: /* original 4f26, guest PC 0x0c0c5ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5ea6;
P_0c0c5ea6: /* original 6cf6, guest PC 0x0c0c5ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5ea8;
P_0c0c5ea8: /* original 6df6, guest PC 0x0c0c5ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5eaa;
P_0c0c5eaa: /* original 000b, guest PC 0x0c0c5eaa */
if(!s->budget--) { s->failed_pc=0x0c0c5eaau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5eac: /* original 6ef6, guest PC 0x0c0c5eac */
if(!s->budget--) { s->failed_pc=0x0c0c5eacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c5eae;
P_0c0c5eae: /* original 2fe6, guest PC 0x0c0c5eae */
if(!s->budget--) { s->failed_pc=0x0c0c5eaeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb0;
P_0c0c5eb0: /* original 2fd6, guest PC 0x0c0c5eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb2;
P_0c0c5eb2: /* original ed1f, guest PC 0x0c0c5eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb2u; return 0; }
r[13]=0x0000001fu;
goto P_0c0c5eb4;
P_0c0c5eb4: /* original 2d49, guest PC 0x0c0c5eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb4u; return 0; }
r[13]&=r[4];
goto P_0c0c5eb6;
P_0c0c5eb6: /* original d31b, guest PC 0x0c0c5eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb6u; return 0; }
r[3]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5eb8;
P_0c0c5eb8: /* original 4d00, guest PC 0x0c0c5eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0c5eba;
P_0c0c5eba: /* original 6ed3, guest PC 0x0c0c5eba */
if(!s->budget--) { s->failed_pc=0x0c0c5ebau; return 0; }
r[14]=r[13];
goto P_0c0c5ebc;
P_0c0c5ebc: /* original 4e08, guest PC 0x0c0c5ebc */
if(!s->budget--) { s->failed_pc=0x0c0c5ebcu; return 0; }
r[14]<<=2;
goto P_0c0c5ebe;
P_0c0c5ebe: /* original 3e3c, guest PC 0x0c0c5ebe */
if(!s->budget--) { s->failed_pc=0x0c0c5ebeu; return 0; }
r[14]+=r[3];
goto P_0c0c5ec0;
P_0c0c5ec0: /* original 62e2, guest PC 0x0c0c5ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0c5ec2;
P_0c0c5ec2: /* original 4f22, guest PC 0x0c0c5ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ec4;
P_0c0c5ec4: /* original 2228, guest PC 0x0c0c5ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c5ec6;
P_0c0c5ec6: /* original 8920, guest PC 0x0c0c5ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ec8;
P_0c0c5ec8: /* original d217, guest PC 0x0c0c5ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec8u; return 0; }
r[2]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5eca;
P_0c0c5eca: /* original 61e2, guest PC 0x0c0c5eca */
if(!s->budget--) { s->failed_pc=0x0c0c5ecau; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c5ecc;
P_0c0c5ecc: /* original 6022, guest PC 0x0c0c5ecc */
if(!s->budget--) { s->failed_pc=0x0c0c5eccu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0c5ece;
P_0c0c5ece: /* original 3010, guest PC 0x0c0c5ece */
if(!s->budget--) { s->failed_pc=0x0c0c5eceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c5ed0;
P_0c0c5ed0: /* original 891b, guest PC 0x0c0c5ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ed2;
P_0c0c5ed2: /* original d317, guest PC 0x0c0c5ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed2u; return 0; }
r[3]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ed4;
P_0c0c5ed4: /* original d115, guest PC 0x0c0c5ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed4u; return 0; }
r[1]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ed6;
P_0c0c5ed6: /* original 6532, guest PC 0x0c0c5ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c5ed8;
P_0c0c5ed8: /* original d216, guest PC 0x0c0c5ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed8u; return 0; }
r[2]=read(ram,0x0c0c5f34u,4);
goto P_0c0c5eda;
P_0c0c5eda: /* original 351c, guest PC 0x0c0c5eda */
if(!s->budget--) { s->failed_pc=0x0c0c5edau; return 0; }
r[5]+=r[1];
goto P_0c0c5edc;
P_0c0c5edc: /* original 420b, guest PC 0x0c0c5edc */
if(!s->budget--) { s->failed_pc=0x0c0c5edcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5ee0u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee0u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee0;
P_0c0c5ede: /* original 64e2, guest PC 0x0c0c5ede */
if(!s->budget--) { s->failed_pc=0x0c0c5edeu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c5ee0;
P_0c0c5ee0: /* original d30e, guest PC 0x0c0c5ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee0u; return 0; }
r[3]=read(ram,0x0c0c5f1cu,4);
goto P_0c0c5ee2;
P_0c0c5ee2: /* original 430b, guest PC 0x0c0c5ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5ee6u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee6u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee6;
P_0c0c5ee4: /* original e404, guest PC 0x0c0c5ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee4u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5ee6;
P_0c0c5ee6: /* original d212, guest PC 0x0c0c5ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee6u; return 0; }
r[2]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ee8;
P_0c0c5ee8: /* original e504, guest PC 0x0c0c5ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee8u; return 0; }
r[5]=0x00000004u;
goto P_0c0c5eea;
P_0c0c5eea: /* original d113, guest PC 0x0c0c5eea */
if(!s->budget--) { s->failed_pc=0x0c0c5eeau; return 0; }
r[1]=read(ram,0x0c0c5f38u,4);
goto P_0c0c5eec;
P_0c0c5eec: /* original 6422, guest PC 0x0c0c5eec */
if(!s->budget--) { s->failed_pc=0x0c0c5eecu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c5eee;
P_0c0c5eee: /* original d30f, guest PC 0x0c0c5eee */
if(!s->budget--) { s->failed_pc=0x0c0c5eeeu; return 0; }
r[3]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ef0;
P_0c0c5ef0: /* original 410b, guest PC 0x0c0c5ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef0u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c5ef4u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ef4u) { target=s->pc; goto dispatch; }
goto P_0c0c5ef4;
P_0c0c5ef2: /* original 343c, guest PC 0x0c0c5ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef2u; return 0; }
r[4]+=r[3];
goto P_0c0c5ef4;
P_0c0c5ef4: /* original 2008, guest PC 0x0c0c5ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c5ef6;
P_0c0c5ef6: /* original 8903, guest PC 0x0c0c5ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f00; }
goto P_0c0c5ef8;
P_0c0c5ef8: /* original d210, guest PC 0x0c0c5ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef8u; return 0; }
r[2]=read(ram,0x0c0c5f3cu,4);
goto P_0c0c5efa;
P_0c0c5efa: /* original 950a, guest PC 0x0c0c5efa */
if(!s->budget--) { s->failed_pc=0x0c0c5efau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5f12u,2);
goto P_0c0c5efc;
P_0c0c5efc: /* original 420b, guest PC 0x0c0c5efc */
if(!s->budget--) { s->failed_pc=0x0c0c5efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5f00u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5f00u) { target=s->pc; goto dispatch; }
goto P_0c0c5f00;
P_0c0c5efe: /* original e401, guest PC 0x0c0c5efe */
if(!s->budget--) { s->failed_pc=0x0c0c5efeu; return 0; }
r[4]=0x00000001u;
goto P_0c0c5f00;
P_0c0c5f00: /* original d008, guest PC 0x0c0c5f00 */
if(!s->budget--) { s->failed_pc=0x0c0c5f00u; return 0; }
r[0]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5f02;
P_0c0c5f02: /* original 4d08, guest PC 0x0c0c5f02 */
if(!s->budget--) { s->failed_pc=0x0c0c5f02u; return 0; }
r[13]<<=2;
goto P_0c0c5f04;
P_0c0c5f04: /* original d308, guest PC 0x0c0c5f04 */
if(!s->budget--) { s->failed_pc=0x0c0c5f04u; return 0; }
r[3]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5f06;
P_0c0c5f06: /* original 02de, guest PC 0x0c0c5f06 */
if(!s->budget--) { s->failed_pc=0x0c0c5f06u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0c5f08;
P_0c0c5f08: /* original 2322, guest PC 0x0c0c5f08 */
if(!s->budget--) { s->failed_pc=0x0c0c5f08u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0c5f0a;
P_0c0c5f0a: /* original 4f26, guest PC 0x0c0c5f0a */
if(!s->budget--) { s->failed_pc=0x0c0c5f0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5f0c;
P_0c0c5f0c: /* original 6df6, guest PC 0x0c0c5f0c */
if(!s->budget--) { s->failed_pc=0x0c0c5f0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5f0e;
P_0c0c5f0e: /* original 000b, guest PC 0x0c0c5f0e */
if(!s->budget--) { s->failed_pc=0x0c0c5f0eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5f10: /* original 6ef6, guest PC 0x0c0c5f10 */
if(!s->budget--) { s->failed_pc=0x0c0c5f10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5f12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5f12u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
