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
int vf3_continuation_matrix_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03be20u: goto P_0c03be20;
case 0x0c03be22u: goto P_0c03be22;
case 0x0c03be24u: goto P_0c03be24;
case 0x0c03be26u: goto P_0c03be26;
case 0x0c03be28u: goto P_0c03be28;
case 0x0c03be2au: goto P_0c03be2a;
case 0x0c03be2cu: goto P_0c03be2c;
case 0x0c03be2eu: goto P_0c03be2e;
case 0x0c03be30u: goto P_0c03be30;
case 0x0c03be32u: goto P_0c03be32;
case 0x0c03be34u: goto P_0c03be34;
case 0x0c03be36u: goto P_0c03be36;
case 0x0c03be38u: goto P_0c03be38;
case 0x0c03be3au: goto P_0c03be3a;
case 0x0c03be3cu: goto P_0c03be3c;
case 0x0c03be3eu: goto P_0c03be3e;
case 0x0c03be40u: goto P_0c03be40;
case 0x0c03be42u: goto P_0c03be42;
case 0x0c03be44u: goto P_0c03be44;
case 0x0c03be46u: goto P_0c03be46;
case 0x0c03be48u: goto P_0c03be48;
case 0x0c03be4au: goto P_0c03be4a;
case 0x0c03be4cu: goto P_0c03be4c;
case 0x0c03be4eu: goto P_0c03be4e;
case 0x0c03be50u: goto P_0c03be50;
case 0x0c03be52u: goto P_0c03be52;
case 0x0c03be54u: goto P_0c03be54;
case 0x0c03be60u: goto P_0c03be60;
case 0x0c03be62u: goto P_0c03be62;
case 0x0c03be64u: goto P_0c03be64;
case 0x0c03be66u: goto P_0c03be66;
case 0x0c03be68u: goto P_0c03be68;
case 0x0c03be6au: goto P_0c03be6a;
case 0x0c03be6cu: goto P_0c03be6c;
case 0x0c03be6eu: goto P_0c03be6e;
case 0x0c03be70u: goto P_0c03be70;
case 0x0c03be72u: goto P_0c03be72;
case 0x0c03be74u: goto P_0c03be74;
case 0x0c03be76u: goto P_0c03be76;
case 0x0c03be78u: goto P_0c03be78;
case 0x0c03be7au: goto P_0c03be7a;
case 0x0c03be7cu: goto P_0c03be7c;
case 0x0c03be7eu: goto P_0c03be7e;
case 0x0c03be80u: goto P_0c03be80;
case 0x0c03be82u: goto P_0c03be82;
case 0x0c03be84u: goto P_0c03be84;
case 0x0c03be86u: goto P_0c03be86;
case 0x0c03be88u: goto P_0c03be88;
case 0x0c03be8au: goto P_0c03be8a;
case 0x0c03be8cu: goto P_0c03be8c;
case 0x0c03be8eu: goto P_0c03be8e;
case 0x0c03be90u: goto P_0c03be90;
case 0x0c03be92u: goto P_0c03be92;
case 0x0c03be94u: goto P_0c03be94;
case 0x0c03be96u: goto P_0c03be96;
case 0x0c03be98u: goto P_0c03be98;
case 0x0c03be9au: goto P_0c03be9a;
case 0x0c03be9cu: goto P_0c03be9c;
case 0x0c03be9eu: goto P_0c03be9e;
case 0x0c03bea0u: goto P_0c03bea0;
case 0x0c03bea2u: goto P_0c03bea2;
case 0x0c03bea4u: goto P_0c03bea4;
case 0x0c03bea6u: goto P_0c03bea6;
case 0x0c03bea8u: goto P_0c03bea8;
case 0x0c03beaau: goto P_0c03beaa;
case 0x0c03beacu: goto P_0c03beac;
case 0x0c03beb0u: goto P_0c03beb0;
case 0x0c03beb2u: goto P_0c03beb2;
case 0x0c03beb4u: goto P_0c03beb4;
case 0x0c03beb6u: goto P_0c03beb6;
case 0x0c03beb8u: goto P_0c03beb8;
case 0x0c03bebau: goto P_0c03beba;
case 0x0c03bebcu: goto P_0c03bebc;
case 0x0c03bebeu: goto P_0c03bebe;
case 0x0c03bec0u: goto P_0c03bec0;
case 0x0c03bec2u: goto P_0c03bec2;
case 0x0c03bec4u: goto P_0c03bec4;
case 0x0c03bec6u: goto P_0c03bec6;
case 0x0c03bec8u: goto P_0c03bec8;
case 0x0c03becau: goto P_0c03beca;
case 0x0c03beccu: goto P_0c03becc;
case 0x0c03beceu: goto P_0c03bece;
case 0x0c03bed0u: goto P_0c03bed0;
case 0x0c03bed2u: goto P_0c03bed2;
case 0x0c03bed4u: goto P_0c03bed4;
case 0x0c03bed6u: goto P_0c03bed6;
case 0x0c03bed8u: goto P_0c03bed8;
case 0x0c03bedau: goto P_0c03beda;
case 0x0c03bedcu: goto P_0c03bedc;
case 0x0c03bedeu: goto P_0c03bede;
case 0x0c03bee0u: goto P_0c03bee0;
case 0x0c03bee2u: goto P_0c03bee2;
case 0x0c03bee4u: goto P_0c03bee4;
case 0x0c03bee6u: goto P_0c03bee6;
case 0x0c03bee8u: goto P_0c03bee8;
case 0x0c03beeau: goto P_0c03beea;
case 0x0c03beecu: goto P_0c03beec;
case 0x0c03beeeu: goto P_0c03beee;
case 0x0c03bef0u: goto P_0c03bef0;
case 0x0c03bef2u: goto P_0c03bef2;
case 0x0c03bef4u: goto P_0c03bef4;
case 0x0c03bef6u: goto P_0c03bef6;
case 0x0c03bef8u: goto P_0c03bef8;
case 0x0c03befau: goto P_0c03befa;
case 0x0c03befcu: goto P_0c03befc;
case 0x0c03befeu: goto P_0c03befe;
case 0x0c03bf00u: goto P_0c03bf00;
case 0x0c03bf02u: goto P_0c03bf02;
case 0x0c03bf04u: goto P_0c03bf04;
case 0x0c03bf06u: goto P_0c03bf06;
case 0x0c03bf08u: goto P_0c03bf08;
case 0x0c03bf0au: goto P_0c03bf0a;
case 0x0c03bf0cu: goto P_0c03bf0c;
case 0x0c03bf0eu: goto P_0c03bf0e;
case 0x0c03bf10u: goto P_0c03bf10;
case 0x0c03bf12u: goto P_0c03bf12;
case 0x0c03bf14u: goto P_0c03bf14;
case 0x0c03bf16u: goto P_0c03bf16;
case 0x0c03bf18u: goto P_0c03bf18;
case 0x0c03bf1au: goto P_0c03bf1a;
case 0x0c03bf1cu: goto P_0c03bf1c;
case 0x0c03bf20u: goto P_0c03bf20;
case 0x0c03bf22u: goto P_0c03bf22;
case 0x0c03bf24u: goto P_0c03bf24;
case 0x0c03bf26u: goto P_0c03bf26;
case 0x0c03bf28u: goto P_0c03bf28;
case 0x0c03bf2au: goto P_0c03bf2a;
case 0x0c03bf2cu: goto P_0c03bf2c;
case 0x0c03bf2eu: goto P_0c03bf2e;
case 0x0c03bf30u: goto P_0c03bf30;
case 0x0c03bf32u: goto P_0c03bf32;
case 0x0c03bf34u: goto P_0c03bf34;
case 0x0c03bf36u: goto P_0c03bf36;
case 0x0c03bf38u: goto P_0c03bf38;
case 0x0c03bf3au: goto P_0c03bf3a;
case 0x0c03bf3cu: goto P_0c03bf3c;
case 0x0c03bf3eu: goto P_0c03bf3e;
case 0x0c03bf40u: goto P_0c03bf40;
case 0x0c03bf42u: goto P_0c03bf42;
case 0x0c03bf44u: goto P_0c03bf44;
case 0x0c03bf46u: goto P_0c03bf46;
case 0x0c03bf48u: goto P_0c03bf48;
case 0x0c03bf4au: goto P_0c03bf4a;
case 0x0c03bf4cu: goto P_0c03bf4c;
case 0x0c03bf4eu: goto P_0c03bf4e;
case 0x0c03bf50u: goto P_0c03bf50;
case 0x0c03bf52u: goto P_0c03bf52;
case 0x0c03bf54u: goto P_0c03bf54;
case 0x0c03bf56u: goto P_0c03bf56;
case 0x0c03bf58u: goto P_0c03bf58;
case 0x0c03bf5au: goto P_0c03bf5a;
case 0x0c03bf5cu: goto P_0c03bf5c;
case 0x0c03bf5eu: goto P_0c03bf5e;
case 0x0c03bf60u: goto P_0c03bf60;
case 0x0c03bf62u: goto P_0c03bf62;
case 0x0c03bf64u: goto P_0c03bf64;
case 0x0c03bf66u: goto P_0c03bf66;
case 0x0c03bf68u: goto P_0c03bf68;
case 0x0c03bf6au: goto P_0c03bf6a;
case 0x0c03bf6cu: goto P_0c03bf6c;
case 0x0c03bf6eu: goto P_0c03bf6e;
case 0x0c03bf70u: goto P_0c03bf70;
case 0x0c03bf72u: goto P_0c03bf72;
case 0x0c03bf74u: goto P_0c03bf74;
case 0x0c03bf76u: goto P_0c03bf76;
case 0x0c03bf78u: goto P_0c03bf78;
case 0x0c03bf7au: goto P_0c03bf7a;
case 0x0c03bf7cu: goto P_0c03bf7c;
case 0x0c03bf7eu: goto P_0c03bf7e;
case 0x0c03bf80u: goto P_0c03bf80;
case 0x0c03bf82u: goto P_0c03bf82;
case 0x0c03bf84u: goto P_0c03bf84;
case 0x0c03bf86u: goto P_0c03bf86;
case 0x0c03bf88u: goto P_0c03bf88;
case 0x0c03bf8au: goto P_0c03bf8a;
case 0x0c03bf8cu: goto P_0c03bf8c;
case 0x0c03bf8eu: goto P_0c03bf8e;
case 0x0c03bf90u: goto P_0c03bf90;
case 0x0c03bf92u: goto P_0c03bf92;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03be20: /* original 2fe6, guest PC 0x0c03be20 */
if(!s->budget--) { s->failed_pc=0x0c03be20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03be22;
P_0c03be22: /* original 2448, guest PC 0x0c03be22 */
if(!s->budget--) { s->failed_pc=0x0c03be22u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03be24;
P_0c03be24: /* original 2fd6, guest PC 0x0c03be24 */
if(!s->budget--) { s->failed_pc=0x0c03be24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03be26;
P_0c03be26: /* original 2fc6, guest PC 0x0c03be26 */
if(!s->budget--) { s->failed_pc=0x0c03be26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03be28;
P_0c03be28: /* original 6c53, guest PC 0x0c03be28 */
if(!s->budget--) { s->failed_pc=0x0c03be28u; return 0; }
r[12]=r[5];
goto P_0c03be2a;
P_0c03be2a: /* original 2fb6, guest PC 0x0c03be2a */
if(!s->budget--) { s->failed_pc=0x0c03be2au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03be2c;
P_0c03be2c: /* original 2fa6, guest PC 0x0c03be2c */
if(!s->budget--) { s->failed_pc=0x0c03be2cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03be2e;
P_0c03be2e: /* original 2f96, guest PC 0x0c03be2e */
if(!s->budget--) { s->failed_pc=0x0c03be2eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03be30;
P_0c03be30: /* original 2f86, guest PC 0x0c03be30 */
if(!s->budget--) { s->failed_pc=0x0c03be30u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03be32;
P_0c03be32: /* original fffb, guest PC 0x0c03be32 */
if(!s->budget--) { s->failed_pc=0x0c03be32u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03be34;
P_0c03be34: /* original 4f22, guest PC 0x0c03be34 */
if(!s->budget--) { s->failed_pc=0x0c03be34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03be36;
P_0c03be36: /* original 7fe0, guest PC 0x0c03be36 */
if(!s->budget--) { s->failed_pc=0x0c03be36u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c03be38;
P_0c03be38: /* original 8f04, guest PC 0x0c03be38 */
if(!s->budget--) { s->failed_pc=0x0c03be38u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[4],4);
if(!cond) { goto P_0c03be44; }
goto P_0c03be3c;
P_0c03be3a: /* original 1f43, guest PC 0x0c03be3a */
if(!s->budget--) { s->failed_pc=0x0c03be3au; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c03be3c;
P_0c03be3c: /* original d28f, guest PC 0x0c03be3c */
if(!s->budget--) { s->failed_pc=0x0c03be3cu; return 0; }
r[2]=read(ram,0x0c03c07cu,4);
goto P_0c03be3e;
P_0c03be3e: /* original 420b, guest PC 0x0c03be3e */
if(!s->budget--) { s->failed_pc=0x0c03be3eu; return 0; }
target=r[2];
r[16]=0x0c03be42u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03be42u) { target=s->pc; goto dispatch; }
goto P_0c03be42;
P_0c03be40: /* original e400, guest PC 0x0c03be40 */
if(!s->budget--) { s->failed_pc=0x0c03be40u; return 0; }
r[4]=0x00000000u;
goto P_0c03be42;
P_0c03be42: /* original 6403, guest PC 0x0c03be42 */
if(!s->budget--) { s->failed_pc=0x0c03be42u; return 0; }
r[4]=r[0];
goto P_0c03be44;
P_0c03be44: /* original 6af3, guest PC 0x0c03be44 */
if(!s->budget--) { s->failed_pc=0x0c03be44u; return 0; }
r[10]=r[15];
goto P_0c03be46;
P_0c03be46: /* original f68d, guest PC 0x0c03be46 */
if(!s->budget--) { s->failed_pc=0x0c03be46u; return 0; }
fr[6]=0;
goto P_0c03be48;
P_0c03be48: /* original 7a10, guest PC 0x0c03be48 */
if(!s->budget--) { s->failed_pc=0x0c03be48u; return 0; }
r[10]+=0x00000010u;
goto P_0c03be4a;
P_0c03be4a: /* original ff6c, guest PC 0x0c03be4a */
if(!s->budget--) { s->failed_pc=0x0c03be4au; return 0; }
vf3_matrix_move(s,15,6);
goto P_0c03be4c;
P_0c03be4c: /* original e504, guest PC 0x0c03be4c */
if(!s->budget--) { s->failed_pc=0x0c03be4cu; return 0; }
r[5]=0x00000004u;
goto P_0c03be4e;
P_0c03be4e: /* original f79d, guest PC 0x0c03be4e */
if(!s->budget--) { s->failed_pc=0x0c03be4eu; return 0; }
fr[7]=0x3f800000u;
goto P_0c03be50;
P_0c03be50: /* original ee00, guest PC 0x0c03be50 */
if(!s->budget--) { s->failed_pc=0x0c03be50u; return 0; }
r[14]=0x00000000u;
goto P_0c03be52;
P_0c03be52: /* original a025, guest PC 0x0c03be52 */
if(!s->budget--) { s->failed_pc=0x0c03be52u; return 0; }
r[7]=r[14];
goto P_0c03bea0;
P_0c03be54: /* original 67e3, guest PC 0x0c03be54 */
if(!s->budget--) { s->failed_pc=0x0c03be54u; return 0; }
r[7]=r[14];
return vf3_matrix_family(0x0c03be56u,s,ram);
P_0c03be60: /* original 6073, guest PC 0x0c03be60 */
if(!s->budget--) { s->failed_pc=0x0c03be60u; return 0; }
r[0]=r[7];
goto P_0c03be62;
P_0c03be62: /* original 6d03, guest PC 0x0c03be62 */
if(!s->budget--) { s->failed_pc=0x0c03be62u; return 0; }
r[13]=r[0];
goto P_0c03be64;
P_0c03be64: /* original 4d08, guest PC 0x0c03be64 */
if(!s->budget--) { s->failed_pc=0x0c03be64u; return 0; }
r[13]<<=2;
goto P_0c03be66;
P_0c03be66: /* original 66e3, guest PC 0x0c03be66 */
if(!s->budget--) { s->failed_pc=0x0c03be66u; return 0; }
r[6]=r[14];
goto P_0c03be68;
P_0c03be68: /* original 0c04, guest PC 0x0c03be68 */
if(!s->budget--) { s->failed_pc=0x0c03be68u; return 0; }
write(ram,r[12]+r[0],r[0],1);
goto P_0c03be6a;
P_0c03be6a: /* original f46c, guest PC 0x0c03be6a */
if(!s->budget--) { s->failed_pc=0x0c03be6au; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c03be6c;
P_0c03be6c: /* original a00b, guest PC 0x0c03be6c */
if(!s->budget--) { s->failed_pc=0x0c03be6cu; return 0; }
r[13]<<=2;
goto P_0c03be86;
P_0c03be6e: /* original 4d08, guest PC 0x0c03be6e */
if(!s->budget--) { s->failed_pc=0x0c03be6eu; return 0; }
r[13]<<=2;
goto P_0c03be70;
P_0c03be70: /* original 6363, guest PC 0x0c03be70 */
if(!s->budget--) { s->failed_pc=0x0c03be70u; return 0; }
r[3]=r[6];
goto P_0c03be72;
P_0c03be72: /* original 6043, guest PC 0x0c03be72 */
if(!s->budget--) { s->failed_pc=0x0c03be72u; return 0; }
r[0]=r[4];
goto P_0c03be74;
P_0c03be74: /* original 4308, guest PC 0x0c03be74 */
if(!s->budget--) { s->failed_pc=0x0c03be74u; return 0; }
r[3]<<=2;
goto P_0c03be76;
P_0c03be76: /* original 30dc, guest PC 0x0c03be76 */
if(!s->budget--) { s->failed_pc=0x0c03be76u; return 0; }
r[0]+=r[13];
goto P_0c03be78;
P_0c03be78: /* original f336, guest PC 0x0c03be78 */
if(!s->budget--) { s->failed_pc=0x0c03be78u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c03be7a;
P_0c03be7a: /* original f35d, guest PC 0x0c03be7a */
if(!s->budget--) { s->failed_pc=0x0c03be7au; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c03be7c;
P_0c03be7c: /* original f53c, guest PC 0x0c03be7c */
if(!s->budget--) { s->failed_pc=0x0c03be7cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c03be7e;
P_0c03be7e: /* original f545, guest PC 0x0c03be7e */
if(!s->budget--) { s->failed_pc=0x0c03be7eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c03be80;
P_0c03be80: /* original 8f01, guest PC 0x0c03be80 */
if(!s->budget--) { s->failed_pc=0x0c03be80u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c03be86; }
goto P_0c03be84;
P_0c03be82: /* original 7601, guest PC 0x0c03be82 */
if(!s->budget--) { s->failed_pc=0x0c03be82u; return 0; }
r[6]+=0x00000001u;
goto P_0c03be84;
P_0c03be84: /* original f45c, guest PC 0x0c03be84 */
if(!s->budget--) { s->failed_pc=0x0c03be84u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c03be86;
P_0c03be86: /* original 3653, guest PC 0x0c03be86 */
if(!s->budget--) { s->failed_pc=0x0c03be86u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c03be88;
P_0c03be88: /* original 8bf2, guest PC 0x0c03be88 */
if(!s->budget--) { s->failed_pc=0x0c03be88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03be70; }
goto P_0c03be8a;
P_0c03be8a: /* original f38d, guest PC 0x0c03be8a */
if(!s->budget--) { s->failed_pc=0x0c03be8au; return 0; }
fr[3]=0;
goto P_0c03be8c;
P_0c03be8c: /* original f434, guest PC 0x0c03be8c */
if(!s->budget--) { s->failed_pc=0x0c03be8cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03be8e;
P_0c03be8e: /* original 8b01, guest PC 0x0c03be8e */
if(!s->budget--) { s->failed_pc=0x0c03be8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03be94; }
goto P_0c03be90;
P_0c03be90: /* original a074, guest PC 0x0c03be90 */
if(!s->budget--) { s->failed_pc=0x0c03be90u; return 0; }
goto P_0c03bf7c;
P_0c03be92: /* original 0009, guest PC 0x0c03be92 */
if(!s->budget--) { s->failed_pc=0x0c03be92u; return 0; }
goto P_0c03be94;
P_0c03be94: /* original f37c, guest PC 0x0c03be94 */
if(!s->budget--) { s->failed_pc=0x0c03be94u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c03be96;
P_0c03be96: /* original f343, guest PC 0x0c03be96 */
if(!s->budget--) { s->failed_pc=0x0c03be96u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c03be98;
P_0c03be98: /* original 6073, guest PC 0x0c03be98 */
if(!s->budget--) { s->failed_pc=0x0c03be98u; return 0; }
r[0]=r[7];
goto P_0c03be9a;
P_0c03be9a: /* original 4008, guest PC 0x0c03be9a */
if(!s->budget--) { s->failed_pc=0x0c03be9au; return 0; }
r[0]<<=2;
goto P_0c03be9c;
P_0c03be9c: /* original 7701, guest PC 0x0c03be9c */
if(!s->budget--) { s->failed_pc=0x0c03be9cu; return 0; }
r[7]+=0x00000001u;
goto P_0c03be9e;
P_0c03be9e: /* original fa37, guest PC 0x0c03be9e */
if(!s->budget--) { s->failed_pc=0x0c03be9eu; return 0; }
vf3_matrix_store(s,ram,3,r[10]+r[0]);
goto P_0c03bea0;
P_0c03bea0: /* original 3753, guest PC 0x0c03bea0 */
if(!s->budget--) { s->failed_pc=0x0c03bea0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[5])!=0);
goto P_0c03bea2;
P_0c03bea2: /* original 8bdd, guest PC 0x0c03bea2 */
if(!s->budget--) { s->failed_pc=0x0c03bea2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03be60; }
goto P_0c03bea4;
P_0c03bea4: /* original c776, guest PC 0x0c03bea4 */
if(!s->budget--) { s->failed_pc=0x0c03bea4u; return 0; }
r[0]=0x0c03c080u;
goto P_0c03bea6;
P_0c03bea6: /* original ff7c, guest PC 0x0c03bea6 */
if(!s->budget--) { s->failed_pc=0x0c03bea6u; return 0; }
vf3_matrix_move(s,15,7);
goto P_0c03bea8;
P_0c03bea8: /* original f608, guest PC 0x0c03bea8 */
if(!s->budget--) { s->failed_pc=0x0c03bea8u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c03beaa;
P_0c03beaa: /* original a05f, guest PC 0x0c03beaa */
if(!s->budget--) { s->failed_pc=0x0c03beaau; return 0; }
r[7]=r[14];
goto P_0c03bf6c;
P_0c03beac: /* original 67e3, guest PC 0x0c03beac */
if(!s->budget--) { s->failed_pc=0x0c03beacu; return 0; }
r[7]=r[14];
return vf3_matrix_family(0x0c03beaeu,s,ram);
P_0c03beb0: /* original 6e73, guest PC 0x0c03beb0 */
if(!s->budget--) { s->failed_pc=0x0c03beb0u; return 0; }
r[14]=r[7];
goto P_0c03beb2;
P_0c03beb2: /* original 3e53, guest PC 0x0c03beb2 */
if(!s->budget--) { s->failed_pc=0x0c03beb2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c03beb4;
P_0c03beb4: /* original 6d73, guest PC 0x0c03beb4 */
if(!s->budget--) { s->failed_pc=0x0c03beb4u; return 0; }
r[13]=r[7];
goto P_0c03beb6;
P_0c03beb6: /* original f56c, guest PC 0x0c03beb6 */
if(!s->budget--) { s->failed_pc=0x0c03beb6u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03beb8;
P_0c03beb8: /* original 8d15, guest PC 0x0c03beb8 */
if(!s->budget--) { s->failed_pc=0x0c03beb8u; return 0; }
cond=r[17]&1u;
r[13]<<=2;
if(cond) { goto P_0c03bee6; }
goto P_0c03bebc;
P_0c03beba: /* original 4d08, guest PC 0x0c03beba */
if(!s->budget--) { s->failed_pc=0x0c03bebau; return 0; }
r[13]<<=2;
goto P_0c03bebc;
P_0c03bebc: /* original 60e3, guest PC 0x0c03bebc */
if(!s->budget--) { s->failed_pc=0x0c03bebcu; return 0; }
r[0]=r[14];
goto P_0c03bebe;
P_0c03bebe: /* original 0bcc, guest PC 0x0c03bebe */
if(!s->budget--) { s->failed_pc=0x0c03bebeu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c03bec0;
P_0c03bec0: /* original 6343, guest PC 0x0c03bec0 */
if(!s->budget--) { s->failed_pc=0x0c03bec0u; return 0; }
r[3]=r[4];
goto P_0c03bec2;
P_0c03bec2: /* original 60b3, guest PC 0x0c03bec2 */
if(!s->budget--) { s->failed_pc=0x0c03bec2u; return 0; }
r[0]=r[11];
goto P_0c03bec4;
P_0c03bec4: /* original 4008, guest PC 0x0c03bec4 */
if(!s->budget--) { s->failed_pc=0x0c03bec4u; return 0; }
r[0]<<=2;
goto P_0c03bec6;
P_0c03bec6: /* original 4008, guest PC 0x0c03bec6 */
if(!s->budget--) { s->failed_pc=0x0c03bec6u; return 0; }
r[0]<<=2;
goto P_0c03bec8;
P_0c03bec8: /* original 303c, guest PC 0x0c03bec8 */
if(!s->budget--) { s->failed_pc=0x0c03bec8u; return 0; }
r[0]+=r[3];
goto P_0c03beca;
P_0c03beca: /* original f3d6, guest PC 0x0c03beca */
if(!s->budget--) { s->failed_pc=0x0c03becau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03becc;
P_0c03becc: /* original 60b3, guest PC 0x0c03becc */
if(!s->budget--) { s->failed_pc=0x0c03beccu; return 0; }
r[0]=r[11];
goto P_0c03bece;
P_0c03bece: /* original 4008, guest PC 0x0c03bece */
if(!s->budget--) { s->failed_pc=0x0c03beceu; return 0; }
r[0]<<=2;
goto P_0c03bed0;
P_0c03bed0: /* original f2a6, guest PC 0x0c03bed0 */
if(!s->budget--) { s->failed_pc=0x0c03bed0u; return 0; }
vf3_matrix_load(s,ram,2,r[10]+r[0]);
goto P_0c03bed2;
P_0c03bed2: /* original f35d, guest PC 0x0c03bed2 */
if(!s->budget--) { s->failed_pc=0x0c03bed2u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c03bed4;
P_0c03bed4: /* original f43c, guest PC 0x0c03bed4 */
if(!s->budget--) { s->failed_pc=0x0c03bed4u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03bed6;
P_0c03bed6: /* original f422, guest PC 0x0c03bed6 */
if(!s->budget--) { s->failed_pc=0x0c03bed6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c03bed8;
P_0c03bed8: /* original f455, guest PC 0x0c03bed8 */
if(!s->budget--) { s->failed_pc=0x0c03bed8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c03beda;
P_0c03beda: /* original 8b01, guest PC 0x0c03beda */
if(!s->budget--) { s->failed_pc=0x0c03bedau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03bee0; }
goto P_0c03bedc;
P_0c03bedc: /* original 66e3, guest PC 0x0c03bedc */
if(!s->budget--) { s->failed_pc=0x0c03bedcu; return 0; }
r[6]=r[14];
goto P_0c03bede;
P_0c03bede: /* original f54c, guest PC 0x0c03bede */
if(!s->budget--) { s->failed_pc=0x0c03bedeu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c03bee0;
P_0c03bee0: /* original 7e01, guest PC 0x0c03bee0 */
if(!s->budget--) { s->failed_pc=0x0c03bee0u; return 0; }
r[14]+=0x00000001u;
goto P_0c03bee2;
P_0c03bee2: /* original 3e53, guest PC 0x0c03bee2 */
if(!s->budget--) { s->failed_pc=0x0c03bee2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c03bee4;
P_0c03bee4: /* original 8bea, guest PC 0x0c03bee4 */
if(!s->budget--) { s->failed_pc=0x0c03bee4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03bebc; }
goto P_0c03bee6;
P_0c03bee6: /* original 6963, guest PC 0x0c03bee6 */
if(!s->budget--) { s->failed_pc=0x0c03bee6u; return 0; }
r[9]=r[6];
goto P_0c03bee8;
P_0c03bee8: /* original 3670, guest PC 0x0c03bee8 */
if(!s->budget--) { s->failed_pc=0x0c03bee8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[7])!=0);
goto P_0c03beea;
P_0c03beea: /* original 39cc, guest PC 0x0c03beea */
if(!s->budget--) { s->failed_pc=0x0c03beeau; return 0; }
r[9]+=r[12];
goto P_0c03beec;
P_0c03beec: /* original 8d06, guest PC 0x0c03beec */
if(!s->budget--) { s->failed_pc=0x0c03beecu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[14]=tmp;
if(cond) { goto P_0c03befc; }
goto P_0c03bef0;
P_0c03beee: /* original 6e90, guest PC 0x0c03beee */
if(!s->budget--) { s->failed_pc=0x0c03beeeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[14]=tmp;
goto P_0c03bef0;
P_0c03bef0: /* original 6b73, guest PC 0x0c03bef0 */
if(!s->budget--) { s->failed_pc=0x0c03bef0u; return 0; }
r[11]=r[7];
goto P_0c03bef2;
P_0c03bef2: /* original 3bcc, guest PC 0x0c03bef2 */
if(!s->budget--) { s->failed_pc=0x0c03bef2u; return 0; }
r[11]+=r[12];
goto P_0c03bef4;
P_0c03bef4: /* original 62b0, guest PC 0x0c03bef4 */
if(!s->budget--) { s->failed_pc=0x0c03bef4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[2]=tmp;
goto P_0c03bef6;
P_0c03bef6: /* original 2920, guest PC 0x0c03bef6 */
if(!s->budget--) { s->failed_pc=0x0c03bef6u; return 0; }
write(ram,r[9],r[2],1);
goto P_0c03bef8;
P_0c03bef8: /* original 2be0, guest PC 0x0c03bef8 */
if(!s->budget--) { s->failed_pc=0x0c03bef8u; return 0; }
write(ram,r[11],r[14],1);
goto P_0c03befa;
P_0c03befa: /* original ff4d, guest PC 0x0c03befa */
if(!s->budget--) { s->failed_pc=0x0c03befau; return 0; }
fr[15]^=0x80000000u;
goto P_0c03befc;
P_0c03befc: /* original 69e3, guest PC 0x0c03befc */
if(!s->budget--) { s->failed_pc=0x0c03befcu; return 0; }
r[9]=r[14];
goto P_0c03befe;
P_0c03befe: /* original 4908, guest PC 0x0c03befe */
if(!s->budget--) { s->failed_pc=0x0c03befeu; return 0; }
r[9]<<=2;
goto P_0c03bf00;
P_0c03bf00: /* original 6043, guest PC 0x0c03bf00 */
if(!s->budget--) { s->failed_pc=0x0c03bf00u; return 0; }
r[0]=r[4];
goto P_0c03bf02;
P_0c03bf02: /* original 4908, guest PC 0x0c03bf02 */
if(!s->budget--) { s->failed_pc=0x0c03bf02u; return 0; }
r[9]<<=2;
goto P_0c03bf04;
P_0c03bf04: /* original 309c, guest PC 0x0c03bf04 */
if(!s->budget--) { s->failed_pc=0x0c03bf04u; return 0; }
r[0]+=r[9];
goto P_0c03bf06;
P_0c03bf06: /* original f38d, guest PC 0x0c03bf06 */
if(!s->budget--) { s->failed_pc=0x0c03bf06u; return 0; }
fr[3]=0;
goto P_0c03bf08;
P_0c03bf08: /* original f4d6, guest PC 0x0c03bf08 */
if(!s->budget--) { s->failed_pc=0x0c03bf08u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c03bf0a;
P_0c03bf0a: /* original f434, guest PC 0x0c03bf0a */
if(!s->budget--) { s->failed_pc=0x0c03bf0au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03bf0c;
P_0c03bf0c: /* original 8d36, guest PC 0x0c03bf0c */
if(!s->budget--) { s->failed_pc=0x0c03bf0cu; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
if(cond) { goto P_0c03bf7c; }
goto P_0c03bf10;
P_0c03bf0e: /* original ff42, guest PC 0x0c03bf0e */
if(!s->budget--) { s->failed_pc=0x0c03bf0eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
goto P_0c03bf10;
P_0c03bf10: /* original 6b73, guest PC 0x0c03bf10 */
if(!s->budget--) { s->failed_pc=0x0c03bf10u; return 0; }
r[11]=r[7];
goto P_0c03bf12;
P_0c03bf12: /* original 7b01, guest PC 0x0c03bf12 */
if(!s->budget--) { s->failed_pc=0x0c03bf12u; return 0; }
r[11]+=0x00000001u;
goto P_0c03bf14;
P_0c03bf14: /* original 63b3, guest PC 0x0c03bf14 */
if(!s->budget--) { s->failed_pc=0x0c03bf14u; return 0; }
r[3]=r[11];
goto P_0c03bf16;
P_0c03bf16: /* original 33cc, guest PC 0x0c03bf16 */
if(!s->budget--) { s->failed_pc=0x0c03bf16u; return 0; }
r[3]+=r[12];
goto P_0c03bf18;
P_0c03bf18: /* original 2fb2, guest PC 0x0c03bf18 */
if(!s->budget--) { s->failed_pc=0x0c03bf18u; return 0; }
write(ram,r[15],r[11],4);
goto P_0c03bf1a;
P_0c03bf1a: /* original a024, guest PC 0x0c03bf1a */
if(!s->budget--) { s->failed_pc=0x0c03bf1au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c03bf66;
P_0c03bf1c: /* original 1f32, guest PC 0x0c03bf1c */
if(!s->budget--) { s->failed_pc=0x0c03bf1cu; return 0; }
write(ram,r[15]+8,r[3],4);
return vf3_matrix_family(0x0c03bf1eu,s,ram);
P_0c03bf20: /* original 56f2, guest PC 0x0c03bf20 */
if(!s->budget--) { s->failed_pc=0x0c03bf20u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c03bf22;
P_0c03bf22: /* original 6043, guest PC 0x0c03bf22 */
if(!s->budget--) { s->failed_pc=0x0c03bf22u; return 0; }
r[0]=r[4];
goto P_0c03bf24;
P_0c03bf24: /* original 7601, guest PC 0x0c03bf24 */
if(!s->budget--) { s->failed_pc=0x0c03bf24u; return 0; }
r[6]+=0x00000001u;
goto P_0c03bf26;
P_0c03bf26: /* original 1f62, guest PC 0x0c03bf26 */
if(!s->budget--) { s->failed_pc=0x0c03bf26u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c03bf28;
P_0c03bf28: /* original 76ff, guest PC 0x0c03bf28 */
if(!s->budget--) { s->failed_pc=0x0c03bf28u; return 0; }
r[6]+=0xffffffffu;
goto P_0c03bf2a;
P_0c03bf2a: /* original 6660, guest PC 0x0c03bf2a */
if(!s->budget--) { s->failed_pc=0x0c03bf2au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c03bf2c;
P_0c03bf2c: /* original 6e63, guest PC 0x0c03bf2c */
if(!s->budget--) { s->failed_pc=0x0c03bf2cu; return 0; }
r[14]=r[6];
goto P_0c03bf2e;
P_0c03bf2e: /* original 4e08, guest PC 0x0c03bf2e */
if(!s->budget--) { s->failed_pc=0x0c03bf2eu; return 0; }
r[14]<<=2;
goto P_0c03bf30;
P_0c03bf30: /* original 4e08, guest PC 0x0c03bf30 */
if(!s->budget--) { s->failed_pc=0x0c03bf30u; return 0; }
r[14]<<=2;
goto P_0c03bf32;
P_0c03bf32: /* original 30ec, guest PC 0x0c03bf32 */
if(!s->budget--) { s->failed_pc=0x0c03bf32u; return 0; }
r[0]+=r[14];
goto P_0c03bf34;
P_0c03bf34: /* original f5d6, guest PC 0x0c03bf34 */
if(!s->budget--) { s->failed_pc=0x0c03bf34u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c03bf36;
P_0c03bf36: /* original f543, guest PC 0x0c03bf36 */
if(!s->budget--) { s->failed_pc=0x0c03bf36u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c03bf38;
P_0c03bf38: /* original fd57, guest PC 0x0c03bf38 */
if(!s->budget--) { s->failed_pc=0x0c03bf38u; return 0; }
vf3_matrix_store(s,ram,5,r[13]+r[0]);
goto P_0c03bf3a;
P_0c03bf3a: /* original 66f2, guest PC 0x0c03bf3a */
if(!s->budget--) { s->failed_pc=0x0c03bf3au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c03bf3c;
P_0c03bf3c: /* original 3653, guest PC 0x0c03bf3c */
if(!s->budget--) { s->failed_pc=0x0c03bf3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c03bf3e;
P_0c03bf3e: /* original 8911, guest PC 0x0c03bf3e */
if(!s->budget--) { s->failed_pc=0x0c03bf3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03bf64; }
goto P_0c03bf40;
P_0c03bf40: /* original 6363, guest PC 0x0c03bf40 */
if(!s->budget--) { s->failed_pc=0x0c03bf40u; return 0; }
r[3]=r[6];
goto P_0c03bf42;
P_0c03bf42: /* original 6293, guest PC 0x0c03bf42 */
if(!s->budget--) { s->failed_pc=0x0c03bf42u; return 0; }
r[2]=r[9];
goto P_0c03bf44;
P_0c03bf44: /* original 6843, guest PC 0x0c03bf44 */
if(!s->budget--) { s->failed_pc=0x0c03bf44u; return 0; }
r[8]=r[4];
goto P_0c03bf46;
P_0c03bf46: /* original 328c, guest PC 0x0c03bf46 */
if(!s->budget--) { s->failed_pc=0x0c03bf46u; return 0; }
r[2]+=r[8];
goto P_0c03bf48;
P_0c03bf48: /* original 4308, guest PC 0x0c03bf48 */
if(!s->budget--) { s->failed_pc=0x0c03bf48u; return 0; }
r[3]<<=2;
goto P_0c03bf4a;
P_0c03bf4a: /* original 6043, guest PC 0x0c03bf4a */
if(!s->budget--) { s->failed_pc=0x0c03bf4au; return 0; }
r[0]=r[4];
goto P_0c03bf4c;
P_0c03bf4c: /* original 323c, guest PC 0x0c03bf4c */
if(!s->budget--) { s->failed_pc=0x0c03bf4cu; return 0; }
r[2]+=r[3];
goto P_0c03bf4e;
P_0c03bf4e: /* original 1f31, guest PC 0x0c03bf4e */
if(!s->budget--) { s->failed_pc=0x0c03bf4eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03bf50;
P_0c03bf50: /* original f328, guest PC 0x0c03bf50 */
if(!s->budget--) { s->failed_pc=0x0c03bf50u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c03bf52;
P_0c03bf52: /* original 30ec, guest PC 0x0c03bf52 */
if(!s->budget--) { s->failed_pc=0x0c03bf52u; return 0; }
r[0]+=r[14];
goto P_0c03bf54;
P_0c03bf54: /* original 303c, guest PC 0x0c03bf54 */
if(!s->budget--) { s->failed_pc=0x0c03bf54u; return 0; }
r[0]+=r[3];
goto P_0c03bf56;
P_0c03bf56: /* original f352, guest PC 0x0c03bf56 */
if(!s->budget--) { s->failed_pc=0x0c03bf56u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03bf58;
P_0c03bf58: /* original f208, guest PC 0x0c03bf58 */
if(!s->budget--) { s->failed_pc=0x0c03bf58u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03bf5a;
P_0c03bf5a: /* original 7601, guest PC 0x0c03bf5a */
if(!s->budget--) { s->failed_pc=0x0c03bf5au; return 0; }
r[6]+=0x00000001u;
goto P_0c03bf5c;
P_0c03bf5c: /* original 3653, guest PC 0x0c03bf5c */
if(!s->budget--) { s->failed_pc=0x0c03bf5cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c03bf5e;
P_0c03bf5e: /* original f231, guest PC 0x0c03bf5e */
if(!s->budget--) { s->failed_pc=0x0c03bf5eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c03bf60;
P_0c03bf60: /* original 8fee, guest PC 0x0c03bf60 */
if(!s->budget--) { s->failed_pc=0x0c03bf60u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[0]);
if(!cond) { goto P_0c03bf40; }
goto P_0c03bf64;
P_0c03bf62: /* original f02a, guest PC 0x0c03bf62 */
if(!s->budget--) { s->failed_pc=0x0c03bf62u; return 0; }
vf3_matrix_store(s,ram,2,r[0]);
goto P_0c03bf64;
P_0c03bf64: /* original 7b01, guest PC 0x0c03bf64 */
if(!s->budget--) { s->failed_pc=0x0c03bf64u; return 0; }
r[11]+=0x00000001u;
goto P_0c03bf66;
P_0c03bf66: /* original 3b53, guest PC 0x0c03bf66 */
if(!s->budget--) { s->failed_pc=0x0c03bf66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[5])!=0);
goto P_0c03bf68;
P_0c03bf68: /* original 8bda, guest PC 0x0c03bf68 */
if(!s->budget--) { s->failed_pc=0x0c03bf68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03bf20; }
goto P_0c03bf6a;
P_0c03bf6a: /* original 7701, guest PC 0x0c03bf6a */
if(!s->budget--) { s->failed_pc=0x0c03bf6au; return 0; }
r[7]+=0x00000001u;
goto P_0c03bf6c;
P_0c03bf6c: /* original 3753, guest PC 0x0c03bf6c */
if(!s->budget--) { s->failed_pc=0x0c03bf6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[5])!=0);
goto P_0c03bf6e;
P_0c03bf6e: /* original 8b9f, guest PC 0x0c03bf6e */
if(!s->budget--) { s->failed_pc=0x0c03bf6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03beb0; }
goto P_0c03bf70;
P_0c03bf70: /* original 52f3, guest PC 0x0c03bf70 */
if(!s->budget--) { s->failed_pc=0x0c03bf70u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c03bf72;
P_0c03bf72: /* original 2228, guest PC 0x0c03bf72 */
if(!s->budget--) { s->failed_pc=0x0c03bf72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03bf74;
P_0c03bf74: /* original 8b02, guest PC 0x0c03bf74 */
if(!s->budget--) { s->failed_pc=0x0c03bf74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03bf7c; }
goto P_0c03bf76;
P_0c03bf76: /* original d343, guest PC 0x0c03bf76 */
if(!s->budget--) { s->failed_pc=0x0c03bf76u; return 0; }
r[3]=read(ram,0x0c03c084u,4);
goto P_0c03bf78;
P_0c03bf78: /* original 430b, guest PC 0x0c03bf78 */
if(!s->budget--) { s->failed_pc=0x0c03bf78u; return 0; }
target=r[3];
r[16]=0x0c03bf7cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bf7cu) { target=s->pc; goto dispatch; }
goto P_0c03bf7c;
P_0c03bf7a: /* original 0009, guest PC 0x0c03bf7a */
if(!s->budget--) { s->failed_pc=0x0c03bf7au; return 0; }
goto P_0c03bf7c;
P_0c03bf7c: /* original 7f20, guest PC 0x0c03bf7c */
if(!s->budget--) { s->failed_pc=0x0c03bf7cu; return 0; }
r[15]+=0x00000020u;
goto P_0c03bf7e;
P_0c03bf7e: /* original f0fc, guest PC 0x0c03bf7e */
if(!s->budget--) { s->failed_pc=0x0c03bf7eu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c03bf80;
P_0c03bf80: /* original 4f26, guest PC 0x0c03bf80 */
if(!s->budget--) { s->failed_pc=0x0c03bf80u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03bf82;
P_0c03bf82: /* original fff9, guest PC 0x0c03bf82 */
if(!s->budget--) { s->failed_pc=0x0c03bf82u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03bf84;
P_0c03bf84: /* original 68f6, guest PC 0x0c03bf84 */
if(!s->budget--) { s->failed_pc=0x0c03bf84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03bf86;
P_0c03bf86: /* original 69f6, guest PC 0x0c03bf86 */
if(!s->budget--) { s->failed_pc=0x0c03bf86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03bf88;
P_0c03bf88: /* original 6af6, guest PC 0x0c03bf88 */
if(!s->budget--) { s->failed_pc=0x0c03bf88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03bf8a;
P_0c03bf8a: /* original 6bf6, guest PC 0x0c03bf8a */
if(!s->budget--) { s->failed_pc=0x0c03bf8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03bf8c;
P_0c03bf8c: /* original 6cf6, guest PC 0x0c03bf8c */
if(!s->budget--) { s->failed_pc=0x0c03bf8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03bf8e;
P_0c03bf8e: /* original 6df6, guest PC 0x0c03bf8e */
if(!s->budget--) { s->failed_pc=0x0c03bf8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03bf90;
P_0c03bf90: /* original 000b, guest PC 0x0c03bf90 */
if(!s->budget--) { s->failed_pc=0x0c03bf90u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03bf92: /* original 6ef6, guest PC 0x0c03bf92 */
if(!s->budget--) { s->failed_pc=0x0c03bf92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03bf94u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03be20u,0x0c03be22u,0x0c03be24u,0x0c03be26u,0x0c03be28u,0x0c03be2au,0x0c03be2cu,0x0c03be2eu,0x0c03be30u,0x0c03be32u,0x0c03be34u,0x0c03be36u,0x0c03be38u,0x0c03be3au,0x0c03be3cu,0x0c03be3eu,
0x0c03be40u,0x0c03be42u,0x0c03be44u,0x0c03be46u,0x0c03be48u,0x0c03be4au,0x0c03be4cu,0x0c03be4eu,0x0c03be50u,0x0c03be52u,0x0c03be54u,0x0c03be60u,0x0c03be62u,0x0c03be64u,0x0c03be66u,0x0c03be68u,
0x0c03be6au,0x0c03be6cu,0x0c03be6eu,0x0c03be70u,0x0c03be72u,0x0c03be74u,0x0c03be76u,0x0c03be78u,0x0c03be7au,0x0c03be7cu,0x0c03be7eu,0x0c03be80u,0x0c03be82u,0x0c03be84u,0x0c03be86u,0x0c03be88u,
0x0c03be8au,0x0c03be8cu,0x0c03be8eu,0x0c03be90u,0x0c03be92u,0x0c03be94u,0x0c03be96u,0x0c03be98u,0x0c03be9au,0x0c03be9cu,0x0c03be9eu,0x0c03bea0u,0x0c03bea2u,0x0c03bea4u,0x0c03bea6u,0x0c03bea8u,
0x0c03beaau,0x0c03beacu,0x0c03beb0u,0x0c03beb2u,0x0c03beb4u,0x0c03beb6u,0x0c03beb8u,0x0c03bebau,0x0c03bebcu,0x0c03bebeu,0x0c03bec0u,0x0c03bec2u,0x0c03bec4u,0x0c03bec6u,0x0c03bec8u,0x0c03becau,
0x0c03beccu,0x0c03beceu,0x0c03bed0u,0x0c03bed2u,0x0c03bed4u,0x0c03bed6u,0x0c03bed8u,0x0c03bedau,0x0c03bedcu,0x0c03bedeu,0x0c03bee0u,0x0c03bee2u,0x0c03bee4u,0x0c03bee6u,0x0c03bee8u,0x0c03beeau,
0x0c03beecu,0x0c03beeeu,0x0c03bef0u,0x0c03bef2u,0x0c03bef4u,0x0c03bef6u,0x0c03bef8u,0x0c03befau,0x0c03befcu,0x0c03befeu,0x0c03bf00u,0x0c03bf02u,0x0c03bf04u,0x0c03bf06u,0x0c03bf08u,0x0c03bf0au,
0x0c03bf0cu,0x0c03bf0eu,0x0c03bf10u,0x0c03bf12u,0x0c03bf14u,0x0c03bf16u,0x0c03bf18u,0x0c03bf1au,0x0c03bf1cu,0x0c03bf20u,0x0c03bf22u,0x0c03bf24u,0x0c03bf26u,0x0c03bf28u,0x0c03bf2au,0x0c03bf2cu,
0x0c03bf2eu,0x0c03bf30u,0x0c03bf32u,0x0c03bf34u,0x0c03bf36u,0x0c03bf38u,0x0c03bf3au,0x0c03bf3cu,0x0c03bf3eu,0x0c03bf40u,0x0c03bf42u,0x0c03bf44u,0x0c03bf46u,0x0c03bf48u,0x0c03bf4au,0x0c03bf4cu,
0x0c03bf4eu,0x0c03bf50u,0x0c03bf52u,0x0c03bf54u,0x0c03bf56u,0x0c03bf58u,0x0c03bf5au,0x0c03bf5cu,0x0c03bf5eu,0x0c03bf60u,0x0c03bf62u,0x0c03bf64u,0x0c03bf66u,0x0c03bf68u,0x0c03bf6au,0x0c03bf6cu,
0x0c03bf6eu,0x0c03bf70u,0x0c03bf72u,0x0c03bf74u,0x0c03bf76u,0x0c03bf78u,0x0c03bf7au,0x0c03bf7cu,0x0c03bf7eu,0x0c03bf80u,0x0c03bf82u,0x0c03bf84u,0x0c03bf86u,0x0c03bf88u,0x0c03bf8au,0x0c03bf8cu,
0x0c03bf8eu,0x0c03bf90u,0x0c03bf92u,
};
int vf3_continuation_matrix_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
