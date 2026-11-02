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
int vf3_away_batch220_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0aff76u: goto P_0c0aff76;
case 0x0c0aff78u: goto P_0c0aff78;
case 0x0c0aff7au: goto P_0c0aff7a;
case 0x0c0aff7cu: goto P_0c0aff7c;
case 0x0c0aff7eu: goto P_0c0aff7e;
case 0x0c0aff80u: goto P_0c0aff80;
case 0x0c0aff82u: goto P_0c0aff82;
case 0x0c0aff84u: goto P_0c0aff84;
case 0x0c0aff86u: goto P_0c0aff86;
case 0x0c0aff88u: goto P_0c0aff88;
case 0x0c0aff8au: goto P_0c0aff8a;
case 0x0c0aff8cu: goto P_0c0aff8c;
case 0x0c0aff8eu: goto P_0c0aff8e;
case 0x0c0aff90u: goto P_0c0aff90;
case 0x0c0aff92u: goto P_0c0aff92;
case 0x0c0aff94u: goto P_0c0aff94;
case 0x0c0aff96u: goto P_0c0aff96;
case 0x0c0aff98u: goto P_0c0aff98;
case 0x0c0aff9au: goto P_0c0aff9a;
case 0x0c0aff9cu: goto P_0c0aff9c;
case 0x0c0aff9eu: goto P_0c0aff9e;
case 0x0c0affa0u: goto P_0c0affa0;
case 0x0c0affa2u: goto P_0c0affa2;
case 0x0c0affa4u: goto P_0c0affa4;
case 0x0c0affa6u: goto P_0c0affa6;
case 0x0c0affa8u: goto P_0c0affa8;
case 0x0c0affaau: goto P_0c0affaa;
case 0x0c0affacu: goto P_0c0affac;
case 0x0c0affaeu: goto P_0c0affae;
case 0x0c0affb0u: goto P_0c0affb0;
case 0x0c0affb2u: goto P_0c0affb2;
case 0x0c0affb4u: goto P_0c0affb4;
case 0x0c0affb6u: goto P_0c0affb6;
case 0x0c0affb8u: goto P_0c0affb8;
case 0x0c0affbau: goto P_0c0affba;
case 0x0c0affbcu: goto P_0c0affbc;
case 0x0c0affbeu: goto P_0c0affbe;
case 0x0c0affc0u: goto P_0c0affc0;
case 0x0c0affc2u: goto P_0c0affc2;
case 0x0c0affc4u: goto P_0c0affc4;
case 0x0c0affc6u: goto P_0c0affc6;
case 0x0c0affc8u: goto P_0c0affc8;
case 0x0c0affcau: goto P_0c0affca;
case 0x0c0affccu: goto P_0c0affcc;
case 0x0c0affceu: goto P_0c0affce;
case 0x0c0affd0u: goto P_0c0affd0;
case 0x0c0affd2u: goto P_0c0affd2;
case 0x0c0affd4u: goto P_0c0affd4;
case 0x0c0b001cu: goto P_0c0b001c;
case 0x0c0b001eu: goto P_0c0b001e;
case 0x0c0b0020u: goto P_0c0b0020;
case 0x0c0b0022u: goto P_0c0b0022;
case 0x0c0b0024u: goto P_0c0b0024;
case 0x0c0b0026u: goto P_0c0b0026;
case 0x0c0b0028u: goto P_0c0b0028;
case 0x0c0b002au: goto P_0c0b002a;
case 0x0c0b002cu: goto P_0c0b002c;
case 0x0c0b002eu: goto P_0c0b002e;
case 0x0c0b0030u: goto P_0c0b0030;
case 0x0c0b0032u: goto P_0c0b0032;
case 0x0c0b0034u: goto P_0c0b0034;
case 0x0c0b0036u: goto P_0c0b0036;
case 0x0c0b0038u: goto P_0c0b0038;
case 0x0c0b003au: goto P_0c0b003a;
case 0x0c0b003cu: goto P_0c0b003c;
case 0x0c0b003eu: goto P_0c0b003e;
case 0x0c0b0040u: goto P_0c0b0040;
case 0x0c0b0042u: goto P_0c0b0042;
case 0x0c0b0044u: goto P_0c0b0044;
case 0x0c0b0046u: goto P_0c0b0046;
case 0x0c0b0048u: goto P_0c0b0048;
case 0x0c0b004au: goto P_0c0b004a;
case 0x0c0b004cu: goto P_0c0b004c;
case 0x0c0b004eu: goto P_0c0b004e;
case 0x0c0b0050u: goto P_0c0b0050;
case 0x0c0b0052u: goto P_0c0b0052;
case 0x0c0b0054u: goto P_0c0b0054;
case 0x0c0b0056u: goto P_0c0b0056;
case 0x0c0b0058u: goto P_0c0b0058;
case 0x0c0b005au: goto P_0c0b005a;
case 0x0c0b005cu: goto P_0c0b005c;
case 0x0c0b005eu: goto P_0c0b005e;
case 0x0c0b0060u: goto P_0c0b0060;
case 0x0c0b0062u: goto P_0c0b0062;
case 0x0c0b0064u: goto P_0c0b0064;
case 0x0c0b0066u: goto P_0c0b0066;
case 0x0c0b0068u: goto P_0c0b0068;
case 0x0c0b006au: goto P_0c0b006a;
case 0x0c0b006cu: goto P_0c0b006c;
case 0x0c0b006eu: goto P_0c0b006e;
case 0x0c0b0070u: goto P_0c0b0070;
case 0x0c0b0072u: goto P_0c0b0072;
case 0x0c0b0074u: goto P_0c0b0074;
case 0x0c0b0076u: goto P_0c0b0076;
case 0x0c0b0078u: goto P_0c0b0078;
case 0x0c0b007au: goto P_0c0b007a;
case 0x0c0b007cu: goto P_0c0b007c;
case 0x0c0b007eu: goto P_0c0b007e;
case 0x0c0b0080u: goto P_0c0b0080;
case 0x0c0b0082u: goto P_0c0b0082;
case 0x0c0b0084u: goto P_0c0b0084;
case 0x0c0b0086u: goto P_0c0b0086;
case 0x0c0b0088u: goto P_0c0b0088;
case 0x0c0b008au: goto P_0c0b008a;
case 0x0c0b008cu: goto P_0c0b008c;
case 0x0c0b008eu: goto P_0c0b008e;
case 0x0c0b0090u: goto P_0c0b0090;
case 0x0c0b0092u: goto P_0c0b0092;
case 0x0c0b0094u: goto P_0c0b0094;
case 0x0c0b0096u: goto P_0c0b0096;
case 0x0c0b0098u: goto P_0c0b0098;
case 0x0c0b009au: goto P_0c0b009a;
case 0x0c0b009cu: goto P_0c0b009c;
case 0x0c0b009eu: goto P_0c0b009e;
case 0x0c0b00a0u: goto P_0c0b00a0;
case 0x0c0b00a2u: goto P_0c0b00a2;
case 0x0c0b00a4u: goto P_0c0b00a4;
case 0x0c0b00a6u: goto P_0c0b00a6;
case 0x0c0b00a8u: goto P_0c0b00a8;
case 0x0c0b00aau: goto P_0c0b00aa;
case 0x0c0b00acu: goto P_0c0b00ac;
case 0x0c0b00aeu: goto P_0c0b00ae;
case 0x0c0b00b0u: goto P_0c0b00b0;
case 0x0c0b00b2u: goto P_0c0b00b2;
case 0x0c0b00b4u: goto P_0c0b00b4;
case 0x0c0b00b6u: goto P_0c0b00b6;
case 0x0c0b00b8u: goto P_0c0b00b8;
case 0x0c0b00bau: goto P_0c0b00ba;
case 0x0c0b00bcu: goto P_0c0b00bc;
case 0x0c0b00beu: goto P_0c0b00be;
case 0x0c0b00c0u: goto P_0c0b00c0;
case 0x0c0b00c2u: goto P_0c0b00c2;
case 0x0c0b00c4u: goto P_0c0b00c4;
case 0x0c0b00c6u: goto P_0c0b00c6;
case 0x0c0b00c8u: goto P_0c0b00c8;
case 0x0c0b00cau: goto P_0c0b00ca;
case 0x0c0b00ccu: goto P_0c0b00cc;
case 0x0c0b00ceu: goto P_0c0b00ce;
case 0x0c0b00d0u: goto P_0c0b00d0;
case 0x0c0b00d2u: goto P_0c0b00d2;
case 0x0c0b00d4u: goto P_0c0b00d4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0aff76: /* original 2fe6, guest PC 0x0c0aff76 */
if(!s->budget--) { s->failed_pc=0x0c0aff76u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aff78;
P_0c0aff78: /* original e048, guest PC 0x0c0aff78 */
if(!s->budget--) { s->failed_pc=0x0c0aff78u; return 0; }
r[0]=0x00000048u;
goto P_0c0aff7a;
P_0c0aff7a: /* original 2fd6, guest PC 0x0c0aff7a */
if(!s->budget--) { s->failed_pc=0x0c0aff7au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aff7c;
P_0c0aff7c: /* original 2fc6, guest PC 0x0c0aff7c */
if(!s->budget--) { s->failed_pc=0x0c0aff7cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aff7e;
P_0c0aff7e: /* original 2fb6, guest PC 0x0c0aff7e */
if(!s->budget--) { s->failed_pc=0x0c0aff7eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aff80;
P_0c0aff80: /* original 054e, guest PC 0x0c0aff80 */
if(!s->budget--) { s->failed_pc=0x0c0aff80u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0aff82;
P_0c0aff82: /* original 7ff0, guest PC 0x0c0aff82 */
if(!s->budget--) { s->failed_pc=0x0c0aff82u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0aff84;
P_0c0aff84: /* original d321, guest PC 0x0c0aff84 */
if(!s->budget--) { s->failed_pc=0x0c0aff84u; return 0; }
r[3]=read(ram,0x0c0b000cu,4);
goto P_0c0aff86;
P_0c0aff86: /* original 854f, guest PC 0x0c0aff86 */
if(!s->budget--) { s->failed_pc=0x0c0aff86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0aff88;
P_0c0aff88: /* original 6642, guest PC 0x0c0aff88 */
if(!s->budget--) { s->failed_pc=0x0c0aff88u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c0aff8a;
P_0c0aff8a: /* original 2358, guest PC 0x0c0aff8a */
if(!s->budget--) { s->failed_pc=0x0c0aff8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0aff8c;
P_0c0aff8c: /* original 8d04, guest PC 0x0c0aff8c */
if(!s->budget--) { s->failed_pc=0x0c0aff8cu; return 0; }
cond=r[17]&1u;
r[7]=r[0]&65535u;
if(cond) { goto P_0c0aff98; }
goto P_0c0aff90;
P_0c0aff8e: /* original 670d, guest PC 0x0c0aff8e */
if(!s->budget--) { s->failed_pc=0x0c0aff8eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0aff90;
P_0c0aff90: /* original 9023, guest PC 0x0c0aff90 */
if(!s->budget--) { s->failed_pc=0x0c0aff90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affdau,2);
goto P_0c0aff92;
P_0c0aff92: /* original 024d, guest PC 0x0c0aff92 */
if(!s->budget--) { s->failed_pc=0x0c0aff92u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aff94;
P_0c0aff94: /* original 622d, guest PC 0x0c0aff94 */
if(!s->budget--) { s->failed_pc=0x0c0aff94u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aff96;
P_0c0aff96: /* original 372c, guest PC 0x0c0aff96 */
if(!s->budget--) { s->failed_pc=0x0c0aff96u; return 0; }
r[7]+=r[2];
goto P_0c0aff98;
P_0c0aff98: /* original 9020, guest PC 0x0c0aff98 */
if(!s->budget--) { s->failed_pc=0x0c0aff98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affdcu,2);
goto P_0c0aff9a;
P_0c0aff9a: /* original 6b43, guest PC 0x0c0aff9a */
if(!s->budget--) { s->failed_pc=0x0c0aff9au; return 0; }
r[11]=r[4];
goto P_0c0aff9c;
P_0c0aff9c: /* original 7b38, guest PC 0x0c0aff9c */
if(!s->budget--) { s->failed_pc=0x0c0aff9cu; return 0; }
r[11]+=0x00000038u;
goto P_0c0aff9e;
P_0c0aff9e: /* original 0475, guest PC 0x0c0aff9e */
if(!s->budget--) { s->failed_pc=0x0c0aff9eu; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0affa0;
P_0c0affa0: /* original 901d, guest PC 0x0c0affa0 */
if(!s->budget--) { s->failed_pc=0x0c0affa0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affdeu,2);
goto P_0c0affa2;
P_0c0affa2: /* original d31c, guest PC 0x0c0affa2 */
if(!s->budget--) { s->failed_pc=0x0c0affa2u; return 0; }
r[3]=read(ram,0x0c0b0014u,4);
goto P_0c0affa4;
P_0c0affa4: /* original 0e4d, guest PC 0x0c0affa4 */
if(!s->budget--) { s->failed_pc=0x0c0affa4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0affa6;
P_0c0affa6: /* original e03e, guest PC 0x0c0affa6 */
if(!s->budget--) { s->failed_pc=0x0c0affa6u; return 0; }
r[0]=0x0000003eu;
goto P_0c0affa8;
P_0c0affa8: /* original 0d4d, guest PC 0x0c0affa8 */
if(!s->budget--) { s->failed_pc=0x0c0affa8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0affaa;
P_0c0affaa: /* original 9019, guest PC 0x0c0affaa */
if(!s->budget--) { s->failed_pc=0x0c0affaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affe0u,2);
goto P_0c0affac;
P_0c0affac: /* original 6eed, guest PC 0x0c0affac */
if(!s->budget--) { s->failed_pc=0x0c0affacu; return 0; }
r[14]=r[14]&65535u;
goto P_0c0affae;
P_0c0affae: /* original d718, guest PC 0x0c0affae */
if(!s->budget--) { s->failed_pc=0x0c0affaeu; return 0; }
r[7]=read(ram,0x0c0b0010u,4);
goto P_0c0affb0;
P_0c0affb0: /* original 6ddd, guest PC 0x0c0affb0 */
if(!s->budget--) { s->failed_pc=0x0c0affb0u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0affb2;
P_0c0affb2: /* original 0c4d, guest PC 0x0c0affb2 */
if(!s->budget--) { s->failed_pc=0x0c0affb2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0affb4;
P_0c0affb4: /* original 84b3, guest PC 0x0c0affb4 */
if(!s->budget--) { s->failed_pc=0x0c0affb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+3,1);
goto P_0c0affb6;
P_0c0affb6: /* original 6ccd, guest PC 0x0c0affb6 */
if(!s->budget--) { s->failed_pc=0x0c0affb6u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0affb8;
P_0c0affb8: /* original 4c01, guest PC 0x0c0affb8 */
if(!s->budget--) { s->failed_pc=0x0c0affb8u; return 0; }
r[17]=(r[17]&~1u)|((r[12]&1)!=0);
r[12]>>=1;
goto P_0c0affba;
P_0c0affba: /* original 2358, guest PC 0x0c0affba */
if(!s->budget--) { s->failed_pc=0x0c0affbau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0affbc;
P_0c0affbc: /* original 8f2e, guest PC 0x0c0affbc */
if(!s->budget--) { s->failed_pc=0x0c0affbcu; return 0; }
cond=r[17]&1u;
r[11]=r[0]&255u;
if(!cond) { goto P_0c0b001c; }
goto P_0c0affc0;
P_0c0affbe: /* original 6b0c, guest PC 0x0c0affbe */
if(!s->budget--) { s->failed_pc=0x0c0affbeu; return 0; }
r[11]=r[0]&255u;
goto P_0c0affc0;
P_0c0affc0: /* original 60b3, guest PC 0x0c0affc0 */
if(!s->budget--) { s->failed_pc=0x0c0affc0u; return 0; }
r[0]=r[11];
goto P_0c0affc2;
P_0c0affc2: /* original 8812, guest PC 0x0c0affc2 */
if(!s->budget--) { s->failed_pc=0x0c0affc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0affc4;
P_0c0affc4: /* original 8904, guest PC 0x0c0affc4 */
if(!s->budget--) { s->failed_pc=0x0c0affc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0affd0; }
goto P_0c0affc6;
P_0c0affc6: /* original 920c, guest PC 0x0c0affc6 */
if(!s->budget--) { s->failed_pc=0x0c0affc6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affe2u,2);
goto P_0c0affc8;
P_0c0affc8: /* original 2e28, guest PC 0x0c0affc8 */
if(!s->budget--) { s->failed_pc=0x0c0affc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[2])==0)!=0);
goto P_0c0affca;
P_0c0affca: /* original 8901, guest PC 0x0c0affca */
if(!s->budget--) { s->failed_pc=0x0c0affcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0affd0; }
goto P_0c0affcc;
P_0c0affcc: /* original 3dc6, guest PC 0x0c0affcc */
if(!s->budget--) { s->failed_pc=0x0c0affccu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[12])!=0);
goto P_0c0affce;
P_0c0affce: /* original 8b36, guest PC 0x0c0affce */
if(!s->budget--) { s->failed_pc=0x0c0affceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b003e; }
goto P_0c0affd0;
P_0c0affd0: /* original d311, guest PC 0x0c0affd0 */
if(!s->budget--) { s->failed_pc=0x0c0affd0u; return 0; }
r[3]=read(ram,0x0c0b0018u,4);
goto P_0c0affd2;
P_0c0affd2: /* original a035, guest PC 0x0c0affd2 */
if(!s->budget--) { s->failed_pc=0x0c0affd2u; return 0; }
r[6]&=r[3];
goto P_0c0b0040;
P_0c0affd4: /* original 2639, guest PC 0x0c0affd4 */
if(!s->budget--) { s->failed_pc=0x0c0affd4u; return 0; }
r[6]&=r[3];
if(!vf3_matrix_family(0x0c0affd6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0affd6u; return 0; } return 1;
P_0c0b001c: /* original 905b, guest PC 0x0c0b001c */
if(!s->budget--) { s->failed_pc=0x0c0b001cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d6u,2);
goto P_0c0b001e;
P_0c0b001e: /* original 014e, guest PC 0x0c0b001e */
if(!s->budget--) { s->failed_pc=0x0c0b001eu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0b0020;
P_0c0b0020: /* original 2178, guest PC 0x0c0b0020 */
if(!s->budget--) { s->failed_pc=0x0c0b0020u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[7])==0)!=0);
goto P_0c0b0022;
P_0c0b0022: /* original 8b0c, guest PC 0x0c0b0022 */
if(!s->budget--) { s->failed_pc=0x0c0b0022u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b003e; }
goto P_0c0b0024;
P_0c0b0024: /* original 60b3, guest PC 0x0c0b0024 */
if(!s->budget--) { s->failed_pc=0x0c0b0024u; return 0; }
r[0]=r[11];
goto P_0c0b0026;
P_0c0b0026: /* original 8812, guest PC 0x0c0b0026 */
if(!s->budget--) { s->failed_pc=0x0c0b0026u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0b0028;
P_0c0b0028: /* original 8b04, guest PC 0x0c0b0028 */
if(!s->budget--) { s->failed_pc=0x0c0b0028u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b0034; }
goto P_0c0b002a;
P_0c0b002a: /* original 9355, guest PC 0x0c0b002a */
if(!s->budget--) { s->failed_pc=0x0c0b002au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d8u,2);
goto P_0c0b002c;
P_0c0b002c: /* original 9055, guest PC 0x0c0b002c */
if(!s->budget--) { s->failed_pc=0x0c0b002cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00dau,2);
goto P_0c0b002e;
P_0c0b002e: /* original 2e3b, guest PC 0x0c0b002e */
if(!s->budget--) { s->failed_pc=0x0c0b002eu; return 0; }
r[14]|=r[3];
goto P_0c0b0030;
P_0c0b0030: /* original a005, guest PC 0x0c0b0030 */
if(!s->budget--) { s->failed_pc=0x0c0b0030u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0b003e;
P_0c0b0032: /* original 04e5, guest PC 0x0c0b0032 */
if(!s->budget--) { s->failed_pc=0x0c0b0032u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0b0034;
P_0c0b0034: /* original 9350, guest PC 0x0c0b0034 */
if(!s->budget--) { s->failed_pc=0x0c0b0034u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d8u,2);
goto P_0c0b0036;
P_0c0b0036: /* original 2e38, guest PC 0x0c0b0036 */
if(!s->budget--) { s->failed_pc=0x0c0b0036u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[3])==0)!=0);
goto P_0c0b0038;
P_0c0b0038: /* original 8b01, guest PC 0x0c0b0038 */
if(!s->budget--) { s->failed_pc=0x0c0b0038u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b003e; }
goto P_0c0b003a;
P_0c0b003a: /* original 3dc6, guest PC 0x0c0b003a */
if(!s->budget--) { s->failed_pc=0x0c0b003au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[12])!=0);
goto P_0c0b003c;
P_0c0b003c: /* original 8bc8, guest PC 0x0c0b003c */
if(!s->budget--) { s->failed_pc=0x0c0b003cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0affd0; }
goto P_0c0b003e;
P_0c0b003e: /* original 267b, guest PC 0x0c0b003e */
if(!s->budget--) { s->failed_pc=0x0c0b003eu; return 0; }
r[6]|=r[7];
goto P_0c0b0040;
P_0c0b0040: /* original e04c, guest PC 0x0c0b0040 */
if(!s->budget--) { s->failed_pc=0x0c0b0040u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b0042;
P_0c0b0042: /* original 034e, guest PC 0x0c0b0042 */
if(!s->budget--) { s->failed_pc=0x0c0b0042u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0b0044;
P_0c0b0044: /* original 2f32, guest PC 0x0c0b0044 */
if(!s->budget--) { s->failed_pc=0x0c0b0044u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0b0046;
P_0c0b0046: /* original 62f2, guest PC 0x0c0b0046 */
if(!s->budget--) { s->failed_pc=0x0c0b0046u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0b0048;
P_0c0b0048: /* original d327, guest PC 0x0c0b0048 */
if(!s->budget--) { s->failed_pc=0x0c0b0048u; return 0; }
r[3]=read(ram,0x0c0b00e8u,4);
goto P_0c0b004a;
P_0c0b004a: /* original 2238, guest PC 0x0c0b004a */
if(!s->budget--) { s->failed_pc=0x0c0b004au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0b004c;
P_0c0b004c: /* original 8b26, guest PC 0x0c0b004c */
if(!s->budget--) { s->failed_pc=0x0c0b004cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b009c; }
goto P_0c0b004e;
P_0c0b004e: /* original d127, guest PC 0x0c0b004e */
if(!s->budget--) { s->failed_pc=0x0c0b004eu; return 0; }
r[1]=read(ram,0x0c0b00ecu,4);
goto P_0c0b0050;
P_0c0b0050: /* original 2158, guest PC 0x0c0b0050 */
if(!s->budget--) { s->failed_pc=0x0c0b0050u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c0b0052;
P_0c0b0052: /* original 8b23, guest PC 0x0c0b0052 */
if(!s->budget--) { s->failed_pc=0x0c0b0052u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b009c; }
goto P_0c0b0054;
P_0c0b0054: /* original d326, guest PC 0x0c0b0054 */
if(!s->budget--) { s->failed_pc=0x0c0b0054u; return 0; }
r[3]=read(ram,0x0c0b00f0u,4);
goto P_0c0b0056;
P_0c0b0056: /* original 2358, guest PC 0x0c0b0056 */
if(!s->budget--) { s->failed_pc=0x0c0b0056u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0b0058;
P_0c0b0058: /* original 8b29, guest PC 0x0c0b0058 */
if(!s->budget--) { s->failed_pc=0x0c0b0058u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b00ae; }
goto P_0c0b005a;
P_0c0b005a: /* original d226, guest PC 0x0c0b005a */
if(!s->budget--) { s->failed_pc=0x0c0b005au; return 0; }
r[2]=read(ram,0x0c0b00f4u,4);
goto P_0c0b005c;
P_0c0b005c: /* original 2268, guest PC 0x0c0b005c */
if(!s->budget--) { s->failed_pc=0x0c0b005cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0b005e;
P_0c0b005e: /* original 8b26, guest PC 0x0c0b005e */
if(!s->budget--) { s->failed_pc=0x0c0b005eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b00ae; }
goto P_0c0b0060;
P_0c0b0060: /* original e066, guest PC 0x0c0b0060 */
if(!s->budget--) { s->failed_pc=0x0c0b0060u; return 0; }
r[0]=0x00000066u;
goto P_0c0b0062;
P_0c0b0062: /* original 034d, guest PC 0x0c0b0062 */
if(!s->budget--) { s->failed_pc=0x0c0b0062u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b0064;
P_0c0b0064: /* original 4315, guest PC 0x0c0b0064 */
if(!s->budget--) { s->failed_pc=0x0c0b0064u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0b0066;
P_0c0b0066: /* original 8922, guest PC 0x0c0b0066 */
if(!s->budget--) { s->failed_pc=0x0c0b0066u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00ae; }
goto P_0c0b0068;
P_0c0b0068: /* original e03e, guest PC 0x0c0b0068 */
if(!s->budget--) { s->failed_pc=0x0c0b0068u; return 0; }
r[0]=0x0000003eu;
goto P_0c0b006a;
P_0c0b006a: /* original 034d, guest PC 0x0c0b006a */
if(!s->budget--) { s->failed_pc=0x0c0b006au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b006c;
P_0c0b006c: /* original 633d, guest PC 0x0c0b006c */
if(!s->budget--) { s->failed_pc=0x0c0b006cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0b006e;
P_0c0b006e: /* original 1f32, guest PC 0x0c0b006e */
if(!s->budget--) { s->failed_pc=0x0c0b006eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0b0070;
P_0c0b0070: /* original 9034, guest PC 0x0c0b0070 */
if(!s->budget--) { s->failed_pc=0x0c0b0070u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00dcu,2);
goto P_0c0b0072;
P_0c0b0072: /* original 024d, guest PC 0x0c0b0072 */
if(!s->budget--) { s->failed_pc=0x0c0b0072u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b0074;
P_0c0b0074: /* original 2f22, guest PC 0x0c0b0074 */
if(!s->budget--) { s->failed_pc=0x0c0b0074u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b0076;
P_0c0b0076: /* original 902e, guest PC 0x0c0b0076 */
if(!s->budget--) { s->failed_pc=0x0c0b0076u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d6u,2);
goto P_0c0b0078;
P_0c0b0078: /* original 034e, guest PC 0x0c0b0078 */
if(!s->budget--) { s->failed_pc=0x0c0b0078u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0b007a;
P_0c0b007a: /* original 1f33, guest PC 0x0c0b007a */
if(!s->budget--) { s->failed_pc=0x0c0b007au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0b007c;
P_0c0b007c: /* original e300, guest PC 0x0c0b007c */
if(!s->budget--) { s->failed_pc=0x0c0b007cu; return 0; }
r[3]=0x00000000u;
goto P_0c0b007e;
P_0c0b007e: /* original 902e, guest PC 0x0c0b007e */
if(!s->budget--) { s->failed_pc=0x0c0b007eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00deu,2);
goto P_0c0b0080;
P_0c0b0080: /* original 024d, guest PC 0x0c0b0080 */
if(!s->budget--) { s->failed_pc=0x0c0b0080u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b0082;
P_0c0b0082: /* original 622d, guest PC 0x0c0b0082 */
if(!s->budget--) { s->failed_pc=0x0c0b0082u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0b0084;
P_0c0b0084: /* original 1f21, guest PC 0x0c0b0084 */
if(!s->budget--) { s->failed_pc=0x0c0b0084u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0b0086;
P_0c0b0086: /* original 61f2, guest PC 0x0c0b0086 */
if(!s->budget--) { s->failed_pc=0x0c0b0086u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0b0088;
P_0c0b0088: /* original 3136, guest PC 0x0c0b0088 */
if(!s->budget--) { s->failed_pc=0x0c0b0088u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c0b008a;
P_0c0b008a: /* original 8910, guest PC 0x0c0b008a */
if(!s->budget--) { s->failed_pc=0x0c0b008au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00ae; }
goto P_0c0b008c;
P_0c0b008c: /* original 52f3, guest PC 0x0c0b008c */
if(!s->budget--) { s->failed_pc=0x0c0b008cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0b008e;
P_0c0b008e: /* original d318, guest PC 0x0c0b008e */
if(!s->budget--) { s->failed_pc=0x0c0b008eu; return 0; }
r[3]=read(ram,0x0c0b00f0u,4);
goto P_0c0b0090;
P_0c0b0090: /* original 2238, guest PC 0x0c0b0090 */
if(!s->budget--) { s->failed_pc=0x0c0b0090u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0b0092;
P_0c0b0092: /* original 8b03, guest PC 0x0c0b0092 */
if(!s->budget--) { s->failed_pc=0x0c0b0092u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b009c; }
goto P_0c0b0094;
P_0c0b0094: /* original 53f2, guest PC 0x0c0b0094 */
if(!s->budget--) { s->failed_pc=0x0c0b0094u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0b0096;
P_0c0b0096: /* original 51f1, guest PC 0x0c0b0096 */
if(!s->budget--) { s->failed_pc=0x0c0b0096u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0b0098;
P_0c0b0098: /* original 3310, guest PC 0x0c0b0098 */
if(!s->budget--) { s->failed_pc=0x0c0b0098u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0b009a;
P_0c0b009a: /* original 8908, guest PC 0x0c0b009a */
if(!s->budget--) { s->failed_pc=0x0c0b009au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00ae; }
goto P_0c0b009c;
P_0c0b009c: /* original 9020, guest PC 0x0c0b009c */
if(!s->budget--) { s->failed_pc=0x0c0b009cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00e0u,2);
goto P_0c0b009e;
P_0c0b009e: /* original ee00, guest PC 0x0c0b009e */
if(!s->budget--) { s->failed_pc=0x0c0b009eu; return 0; }
r[14]=0x00000000u;
goto P_0c0b00a0;
P_0c0b00a0: /* original 04e4, guest PC 0x0c0b00a0 */
if(!s->budget--) { s->failed_pc=0x0c0b00a0u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0b00a2;
P_0c0b00a2: /* original 901e, guest PC 0x0c0b00a2 */
if(!s->budget--) { s->failed_pc=0x0c0b00a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00e2u,2);
goto P_0c0b00a4;
P_0c0b00a4: /* original 04e4, guest PC 0x0c0b00a4 */
if(!s->budget--) { s->failed_pc=0x0c0b00a4u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0b00a6;
P_0c0b00a6: /* original 703f, guest PC 0x0c0b00a6 */
if(!s->budget--) { s->failed_pc=0x0c0b00a6u; return 0; }
r[0]+=0x0000003fu;
goto P_0c0b00a8;
P_0c0b00a8: /* original 04e4, guest PC 0x0c0b00a8 */
if(!s->budget--) { s->failed_pc=0x0c0b00a8u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0b00aa;
P_0c0b00aa: /* original 901b, guest PC 0x0c0b00aa */
if(!s->budget--) { s->failed_pc=0x0c0b00aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00e4u,2);
goto P_0c0b00ac;
P_0c0b00ac: /* original 04e4, guest PC 0x0c0b00ac */
if(!s->budget--) { s->failed_pc=0x0c0b00acu; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0b00ae;
P_0c0b00ae: /* original 9012, guest PC 0x0c0b00ae */
if(!s->budget--) { s->failed_pc=0x0c0b00aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d6u,2);
goto P_0c0b00b0;
P_0c0b00b0: /* original 034e, guest PC 0x0c0b00b0 */
if(!s->budget--) { s->failed_pc=0x0c0b00b0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0b00b2;
P_0c0b00b2: /* original 2378, guest PC 0x0c0b00b2 */
if(!s->budget--) { s->failed_pc=0x0c0b00b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0b00b4;
P_0c0b00b4: /* original 8908, guest PC 0x0c0b00b4 */
if(!s->budget--) { s->failed_pc=0x0c0b00b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00c8; }
goto P_0c0b00b6;
P_0c0b00b6: /* original d210, guest PC 0x0c0b00b6 */
if(!s->budget--) { s->failed_pc=0x0c0b00b6u; return 0; }
r[2]=read(ram,0x0c0b00f8u,4);
goto P_0c0b00b8;
P_0c0b00b8: /* original 2258, guest PC 0x0c0b00b8 */
if(!s->budget--) { s->failed_pc=0x0c0b00b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0b00ba;
P_0c0b00ba: /* original 8905, guest PC 0x0c0b00ba */
if(!s->budget--) { s->failed_pc=0x0c0b00bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00c8; }
goto P_0c0b00bc;
P_0c0b00bc: /* original 2758, guest PC 0x0c0b00bc */
if(!s->budget--) { s->failed_pc=0x0c0b00bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[5])==0)!=0);
goto P_0c0b00be;
P_0c0b00be: /* original 8b03, guest PC 0x0c0b00be */
if(!s->budget--) { s->failed_pc=0x0c0b00beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b00c8; }
goto P_0c0b00c0;
P_0c0b00c0: /* original d30e, guest PC 0x0c0b00c0 */
if(!s->budget--) { s->failed_pc=0x0c0b00c0u; return 0; }
r[3]=read(ram,0x0c0b00fcu,4);
goto P_0c0b00c2;
P_0c0b00c2: /* original e048, guest PC 0x0c0b00c2 */
if(!s->budget--) { s->failed_pc=0x0c0b00c2u; return 0; }
r[0]=0x00000048u;
goto P_0c0b00c4;
P_0c0b00c4: /* original 2539, guest PC 0x0c0b00c4 */
if(!s->budget--) { s->failed_pc=0x0c0b00c4u; return 0; }
r[5]&=r[3];
goto P_0c0b00c6;
P_0c0b00c6: /* original 0456, guest PC 0x0c0b00c6 */
if(!s->budget--) { s->failed_pc=0x0c0b00c6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0b00c8;
P_0c0b00c8: /* original 7f10, guest PC 0x0c0b00c8 */
if(!s->budget--) { s->failed_pc=0x0c0b00c8u; return 0; }
r[15]+=0x00000010u;
goto P_0c0b00ca;
P_0c0b00ca: /* original 2462, guest PC 0x0c0b00ca */
if(!s->budget--) { s->failed_pc=0x0c0b00cau; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0b00cc;
P_0c0b00cc: /* original 6bf6, guest PC 0x0c0b00cc */
if(!s->budget--) { s->failed_pc=0x0c0b00ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b00ce;
P_0c0b00ce: /* original 6cf6, guest PC 0x0c0b00ce */
if(!s->budget--) { s->failed_pc=0x0c0b00ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b00d0;
P_0c0b00d0: /* original 6df6, guest PC 0x0c0b00d0 */
if(!s->budget--) { s->failed_pc=0x0c0b00d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b00d2;
P_0c0b00d2: /* original 000b, guest PC 0x0c0b00d2 */
if(!s->budget--) { s->failed_pc=0x0c0b00d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b00d4: /* original 6ef6, guest PC 0x0c0b00d4 */
if(!s->budget--) { s->failed_pc=0x0c0b00d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b00d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b00d6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
