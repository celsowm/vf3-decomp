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
int vf3_tenpp_leaf_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c103cu: goto P_0c0c103c;
case 0x0c0c103eu: goto P_0c0c103e;
case 0x0c0c1040u: goto P_0c0c1040;
case 0x0c0c1042u: goto P_0c0c1042;
case 0x0c0c1044u: goto P_0c0c1044;
case 0x0c0c1046u: goto P_0c0c1046;
case 0x0c0c1048u: goto P_0c0c1048;
case 0x0c0c104au: goto P_0c0c104a;
case 0x0c0c104cu: goto P_0c0c104c;
case 0x0c0c104eu: goto P_0c0c104e;
case 0x0c0c1050u: goto P_0c0c1050;
case 0x0c0c1052u: goto P_0c0c1052;
case 0x0c0c1054u: goto P_0c0c1054;
case 0x0c0c1056u: goto P_0c0c1056;
case 0x0c0c1058u: goto P_0c0c1058;
case 0x0c0c105au: goto P_0c0c105a;
case 0x0c0c105cu: goto P_0c0c105c;
case 0x0c0c105eu: goto P_0c0c105e;
case 0x0c0c1060u: goto P_0c0c1060;
case 0x0c0c1062u: goto P_0c0c1062;
case 0x0c0c1064u: goto P_0c0c1064;
case 0x0c0c1066u: goto P_0c0c1066;
case 0x0c0c1068u: goto P_0c0c1068;
case 0x0c0c106au: goto P_0c0c106a;
case 0x0c0c106cu: goto P_0c0c106c;
case 0x0c0c106eu: goto P_0c0c106e;
case 0x0c0c1070u: goto P_0c0c1070;
case 0x0c0c1072u: goto P_0c0c1072;
case 0x0c0c1074u: goto P_0c0c1074;
case 0x0c0c1076u: goto P_0c0c1076;
case 0x0c0c1078u: goto P_0c0c1078;
case 0x0c0c107au: goto P_0c0c107a;
case 0x0c0c107cu: goto P_0c0c107c;
case 0x0c0c107eu: goto P_0c0c107e;
case 0x0c0c1080u: goto P_0c0c1080;
case 0x0c0c1082u: goto P_0c0c1082;
case 0x0c0c18c0u: goto P_0c0c18c0;
case 0x0c0c18c2u: goto P_0c0c18c2;
case 0x0c0c18c4u: goto P_0c0c18c4;
case 0x0c0c18c6u: goto P_0c0c18c6;
case 0x0c0c18c8u: goto P_0c0c18c8;
case 0x0c0c18cau: goto P_0c0c18ca;
case 0x0c0c18ccu: goto P_0c0c18cc;
case 0x0c0c18ceu: goto P_0c0c18ce;
case 0x0c0c18d0u: goto P_0c0c18d0;
case 0x0c0c18d2u: goto P_0c0c18d2;
case 0x0c0c18d4u: goto P_0c0c18d4;
case 0x0c0c18d6u: goto P_0c0c18d6;
case 0x0c0c18d8u: goto P_0c0c18d8;
case 0x0c0c18dau: goto P_0c0c18da;
case 0x0c0c18dcu: goto P_0c0c18dc;
case 0x0c0c18deu: goto P_0c0c18de;
case 0x0c0c18e0u: goto P_0c0c18e0;
case 0x0c0c18e2u: goto P_0c0c18e2;
case 0x0c0c18e4u: goto P_0c0c18e4;
case 0x0c0c18e6u: goto P_0c0c18e6;
case 0x0c0c18e8u: goto P_0c0c18e8;
case 0x0c0c18eau: goto P_0c0c18ea;
case 0x0c0c18ecu: goto P_0c0c18ec;
case 0x0c0c18eeu: goto P_0c0c18ee;
case 0x0c0c18f0u: goto P_0c0c18f0;
case 0x0c0c18f2u: goto P_0c0c18f2;
case 0x0c0c18f4u: goto P_0c0c18f4;
case 0x0c0c26e0u: goto P_0c0c26e0;
case 0x0c0c26e2u: goto P_0c0c26e2;
case 0x0c0c26e4u: goto P_0c0c26e4;
case 0x0c0c26e6u: goto P_0c0c26e6;
case 0x0c0c26e8u: goto P_0c0c26e8;
case 0x0c0c26eau: goto P_0c0c26ea;
case 0x0c0c26ecu: goto P_0c0c26ec;
case 0x0c0c26eeu: goto P_0c0c26ee;
case 0x0c0c26f0u: goto P_0c0c26f0;
case 0x0c0c26f2u: goto P_0c0c26f2;
case 0x0c0c26f4u: goto P_0c0c26f4;
case 0x0c0c26f6u: goto P_0c0c26f6;
case 0x0c0c26f8u: goto P_0c0c26f8;
case 0x0c0c9d04u: goto P_0c0c9d04;
case 0x0c0c9d06u: goto P_0c0c9d06;
case 0x0c0c9d08u: goto P_0c0c9d08;
case 0x0c0c9d0au: goto P_0c0c9d0a;
case 0x0c0c9d0cu: goto P_0c0c9d0c;
case 0x0c0c9d0eu: goto P_0c0c9d0e;
case 0x0c0c9d10u: goto P_0c0c9d10;
case 0x0c0c9d12u: goto P_0c0c9d12;
case 0x0c0c9d14u: goto P_0c0c9d14;
case 0x0c0c9d16u: goto P_0c0c9d16;
case 0x0c0c9d18u: goto P_0c0c9d18;
case 0x0c0c9d1au: goto P_0c0c9d1a;
case 0x0c0c9d1cu: goto P_0c0c9d1c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c103c: /* original e600, guest PC 0x0c0c103c */
if(!s->budget--) { s->failed_pc=0x0c0c103cu; return 0; }
r[6]=0x00000000u;
goto P_0c0c103e;
P_0c0c103e: /* original 6343, guest PC 0x0c0c103e */
if(!s->budget--) { s->failed_pc=0x0c0c103eu; return 0; }
r[3]=r[4];
goto P_0c0c1040;
P_0c0c1040: /* original 1565, guest PC 0x0c0c1040 */
if(!s->budget--) { s->failed_pc=0x0c0c1040u; return 0; }
write(ram,r[5]+20,r[6],4);
goto P_0c0c1042;
P_0c0c1042: /* original e011, guest PC 0x0c0c1042 */
if(!s->budget--) { s->failed_pc=0x0c0c1042u; return 0; }
r[0]=0x00000011u;
goto P_0c0c1044;
P_0c0c1044: /* original e5ff, guest PC 0x0c0c1044 */
if(!s->budget--) { s->failed_pc=0x0c0c1044u; return 0; }
r[5]=0xffffffffu;
goto P_0c0c1046;
P_0c0c1046: /* original 7310, guest PC 0x0c0c1046 */
if(!s->budget--) { s->failed_pc=0x0c0c1046u; return 0; }
r[3]+=0x00000010u;
goto P_0c0c1048;
P_0c0c1048: /* original 2350, guest PC 0x0c0c1048 */
if(!s->budget--) { s->failed_pc=0x0c0c1048u; return 0; }
write(ram,r[3],r[5],1);
goto P_0c0c104a;
P_0c0c104a: /* original 0454, guest PC 0x0c0c104a */
if(!s->budget--) { s->failed_pc=0x0c0c104au; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c104c;
P_0c0c104c: /* original e012, guest PC 0x0c0c104c */
if(!s->budget--) { s->failed_pc=0x0c0c104cu; return 0; }
r[0]=0x00000012u;
goto P_0c0c104e;
P_0c0c104e: /* original 0454, guest PC 0x0c0c104e */
if(!s->budget--) { s->failed_pc=0x0c0c104eu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c1050;
P_0c0c1050: /* original e013, guest PC 0x0c0c1050 */
if(!s->budget--) { s->failed_pc=0x0c0c1050u; return 0; }
r[0]=0x00000013u;
goto P_0c0c1052;
P_0c0c1052: /* original 0454, guest PC 0x0c0c1052 */
if(!s->budget--) { s->failed_pc=0x0c0c1052u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c1054;
P_0c0c1054: /* original e014, guest PC 0x0c0c1054 */
if(!s->budget--) { s->failed_pc=0x0c0c1054u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1056;
P_0c0c1056: /* original 0454, guest PC 0x0c0c1056 */
if(!s->budget--) { s->failed_pc=0x0c0c1056u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c1058;
P_0c0c1058: /* original 6063, guest PC 0x0c0c1058 */
if(!s->budget--) { s->failed_pc=0x0c0c1058u; return 0; }
r[0]=r[6];
goto P_0c0c105a;
P_0c0c105a: /* original 814b, guest PC 0x0c0c105a */
if(!s->budget--) { s->failed_pc=0x0c0c105au; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c0c105c;
P_0c0c105c: /* original 814c, guest PC 0x0c0c105c */
if(!s->budget--) { s->failed_pc=0x0c0c105cu; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c0c105e;
P_0c0c105e: /* original 814d, guest PC 0x0c0c105e */
if(!s->budget--) { s->failed_pc=0x0c0c105eu; return 0; }
write(ram,r[4]+26,r[0],2);
goto P_0c0c1060;
P_0c0c1060: /* original 814e, guest PC 0x0c0c1060 */
if(!s->budget--) { s->failed_pc=0x0c0c1060u; return 0; }
write(ram,r[4]+28,r[0],2);
goto P_0c0c1062;
P_0c0c1062: /* original 814f, guest PC 0x0c0c1062 */
if(!s->budget--) { s->failed_pc=0x0c0c1062u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c0c1064;
P_0c0c1064: /* original e020, guest PC 0x0c0c1064 */
if(!s->budget--) { s->failed_pc=0x0c0c1064u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1066;
P_0c0c1066: /* original 0465, guest PC 0x0c0c1066 */
if(!s->budget--) { s->failed_pc=0x0c0c1066u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c1068;
P_0c0c1068: /* original e022, guest PC 0x0c0c1068 */
if(!s->budget--) { s->failed_pc=0x0c0c1068u; return 0; }
r[0]=0x00000022u;
goto P_0c0c106a;
P_0c0c106a: /* original 0465, guest PC 0x0c0c106a */
if(!s->budget--) { s->failed_pc=0x0c0c106au; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c106c;
P_0c0c106c: /* original e024, guest PC 0x0c0c106c */
if(!s->budget--) { s->failed_pc=0x0c0c106cu; return 0; }
r[0]=0x00000024u;
goto P_0c0c106e;
P_0c0c106e: /* original 0465, guest PC 0x0c0c106e */
if(!s->budget--) { s->failed_pc=0x0c0c106eu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c1070;
P_0c0c1070: /* original e026, guest PC 0x0c0c1070 */
if(!s->budget--) { s->failed_pc=0x0c0c1070u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1072;
P_0c0c1072: /* original 0465, guest PC 0x0c0c1072 */
if(!s->budget--) { s->failed_pc=0x0c0c1072u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c1074;
P_0c0c1074: /* original e028, guest PC 0x0c0c1074 */
if(!s->budget--) { s->failed_pc=0x0c0c1074u; return 0; }
r[0]=0x00000028u;
goto P_0c0c1076;
P_0c0c1076: /* original 0465, guest PC 0x0c0c1076 */
if(!s->budget--) { s->failed_pc=0x0c0c1076u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0c1078;
P_0c0c1078: /* original 146b, guest PC 0x0c0c1078 */
if(!s->budget--) { s->failed_pc=0x0c0c1078u; return 0; }
write(ram,r[4]+44,r[6],4);
goto P_0c0c107a;
P_0c0c107a: /* original 146c, guest PC 0x0c0c107a */
if(!s->budget--) { s->failed_pc=0x0c0c107au; return 0; }
write(ram,r[4]+48,r[6],4);
goto P_0c0c107c;
P_0c0c107c: /* original 146d, guest PC 0x0c0c107c */
if(!s->budget--) { s->failed_pc=0x0c0c107cu; return 0; }
write(ram,r[4]+52,r[6],4);
goto P_0c0c107e;
P_0c0c107e: /* original 146e, guest PC 0x0c0c107e */
if(!s->budget--) { s->failed_pc=0x0c0c107eu; return 0; }
write(ram,r[4]+56,r[6],4);
goto P_0c0c1080;
P_0c0c1080: /* original 000b, guest PC 0x0c0c1080 */
if(!s->budget--) { s->failed_pc=0x0c0c1080u; return 0; }
target=r[16];
write(ram,r[4]+60,r[6],4);
s->pc=target; return ram->oob==0;
P_0c0c1082: /* original 146f, guest PC 0x0c0c1082 */
if(!s->budget--) { s->failed_pc=0x0c0c1082u; return 0; }
write(ram,r[4]+60,r[6],4);
return vf3_matrix_family(0x0c0c1084u,s,ram);
P_0c0c18c0: /* original 4f22, guest PC 0x0c0c18c0 */
if(!s->budget--) { s->failed_pc=0x0c0c18c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c18c2;
P_0c0c18c2: /* original 947a, guest PC 0x0c0c18c2 */
if(!s->budget--) { s->failed_pc=0x0c0c18c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c19bau,2);
goto P_0c0c18c4;
P_0c0c18c4: /* original bbed, guest PC 0x0c0c18c4 */
if(!s->budget--) { s->failed_pc=0x0c0c18c4u; return 0; }
target=0x0c0c10a2u; r[16]=0x0c0c18c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c18c8u) { target=s->pc; goto dispatch; }
goto P_0c0c18c8;
P_0c0c18c6: /* original 0009, guest PC 0x0c0c18c6 */
if(!s->budget--) { s->failed_pc=0x0c0c18c6u; return 0; }
goto P_0c0c18c8;
P_0c0c18c8: /* original 9478, guest PC 0x0c0c18c8 */
if(!s->budget--) { s->failed_pc=0x0c0c18c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c19bcu,2);
goto P_0c0c18ca;
P_0c0c18ca: /* original bbea, guest PC 0x0c0c18ca */
if(!s->budget--) { s->failed_pc=0x0c0c18cau; return 0; }
target=0x0c0c10a2u; r[16]=0x0c0c18ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c18ceu) { target=s->pc; goto dispatch; }
goto P_0c0c18ce;
P_0c0c18cc: /* original 0009, guest PC 0x0c0c18cc */
if(!s->budget--) { s->failed_pc=0x0c0c18ccu; return 0; }
goto P_0c0c18ce;
P_0c0c18ce: /* original d43d, guest PC 0x0c0c18ce */
if(!s->budget--) { s->failed_pc=0x0c0c18ceu; return 0; }
r[4]=read(ram,0x0c0c19c4u,4);
goto P_0c0c18d0;
P_0c0c18d0: /* original e022, guest PC 0x0c0c18d0 */
if(!s->budget--) { s->failed_pc=0x0c0c18d0u; return 0; }
r[0]=0x00000022u;
goto P_0c0c18d2;
P_0c0c18d2: /* original e302, guest PC 0x0c0c18d2 */
if(!s->budget--) { s->failed_pc=0x0c0c18d2u; return 0; }
r[3]=0x00000002u;
goto P_0c0c18d4;
P_0c0c18d4: /* original 024d, guest PC 0x0c0c18d4 */
if(!s->budget--) { s->failed_pc=0x0c0c18d4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c18d6;
P_0c0c18d6: /* original 4f26, guest PC 0x0c0c18d6 */
if(!s->budget--) { s->failed_pc=0x0c0c18d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c18d8;
P_0c0c18d8: /* original 223b, guest PC 0x0c0c18d8 */
if(!s->budget--) { s->failed_pc=0x0c0c18d8u; return 0; }
r[2]|=r[3];
goto P_0c0c18da;
P_0c0c18da: /* original 0425, guest PC 0x0c0c18da */
if(!s->budget--) { s->failed_pc=0x0c0c18dau; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c18dc;
P_0c0c18dc: /* original e07a, guest PC 0x0c0c18dc */
if(!s->budget--) { s->failed_pc=0x0c0c18dcu; return 0; }
r[0]=0x0000007au;
goto P_0c0c18de;
P_0c0c18de: /* original 014d, guest PC 0x0c0c18de */
if(!s->budget--) { s->failed_pc=0x0c0c18deu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c18e0;
P_0c0c18e0: /* original 213b, guest PC 0x0c0c18e0 */
if(!s->budget--) { s->failed_pc=0x0c0c18e0u; return 0; }
r[1]|=r[3];
goto P_0c0c18e2;
P_0c0c18e2: /* original 0415, guest PC 0x0c0c18e2 */
if(!s->budget--) { s->failed_pc=0x0c0c18e2u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c0c18e4;
P_0c0c18e4: /* original e04e, guest PC 0x0c0c18e4 */
if(!s->budget--) { s->failed_pc=0x0c0c18e4u; return 0; }
r[0]=0x0000004eu;
goto P_0c0c18e6;
P_0c0c18e6: /* original 024d, guest PC 0x0c0c18e6 */
if(!s->budget--) { s->failed_pc=0x0c0c18e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c18e8;
P_0c0c18e8: /* original 223b, guest PC 0x0c0c18e8 */
if(!s->budget--) { s->failed_pc=0x0c0c18e8u; return 0; }
r[2]|=r[3];
goto P_0c0c18ea;
P_0c0c18ea: /* original 0425, guest PC 0x0c0c18ea */
if(!s->budget--) { s->failed_pc=0x0c0c18eau; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c18ec;
P_0c0c18ec: /* original 7058, guest PC 0x0c0c18ec */
if(!s->budget--) { s->failed_pc=0x0c0c18ecu; return 0; }
r[0]+=0x00000058u;
goto P_0c0c18ee;
P_0c0c18ee: /* original 014d, guest PC 0x0c0c18ee */
if(!s->budget--) { s->failed_pc=0x0c0c18eeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c18f0;
P_0c0c18f0: /* original 213b, guest PC 0x0c0c18f0 */
if(!s->budget--) { s->failed_pc=0x0c0c18f0u; return 0; }
r[1]|=r[3];
goto P_0c0c18f2;
P_0c0c18f2: /* original 000b, guest PC 0x0c0c18f2 */
if(!s->budget--) { s->failed_pc=0x0c0c18f2u; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[1],2);
s->pc=target; return ram->oob==0;
P_0c0c18f4: /* original 0415, guest PC 0x0c0c18f4 */
if(!s->budget--) { s->failed_pc=0x0c0c18f4u; return 0; }
write(ram,r[4]+r[0],r[1],2);
return vf3_matrix_family(0x0c0c18f6u,s,ram);
P_0c0c26e0: /* original 4f22, guest PC 0x0c0c26e0 */
if(!s->budget--) { s->failed_pc=0x0c0c26e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c26e2;
P_0c0c26e2: /* original 9492, guest PC 0x0c0c26e2 */
if(!s->budget--) { s->failed_pc=0x0c0c26e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280au,2);
goto P_0c0c26e4;
P_0c0c26e4: /* original d252, guest PC 0x0c0c26e4 */
if(!s->budget--) { s->failed_pc=0x0c0c26e4u; return 0; }
r[2]=read(ram,0x0c0c2830u,4);
goto P_0c0c26e6;
P_0c0c26e6: /* original d551, guest PC 0x0c0c26e6 */
if(!s->budget--) { s->failed_pc=0x0c0c26e6u; return 0; }
r[5]=read(ram,0x0c0c282cu,4);
goto P_0c0c26e8;
P_0c0c26e8: /* original d34e, guest PC 0x0c0c26e8 */
if(!s->budget--) { s->failed_pc=0x0c0c26e8u; return 0; }
r[3]=read(ram,0x0c0c2824u,4);
goto P_0c0c26ea;
P_0c0c26ea: /* original d64f, guest PC 0x0c0c26ea */
if(!s->budget--) { s->failed_pc=0x0c0c26eau; return 0; }
r[6]=read(ram,0x0c0c2828u,4);
goto P_0c0c26ec;
P_0c0c26ec: /* original 420b, guest PC 0x0c0c26ec */
if(!s->budget--) { s->failed_pc=0x0c0c26ecu; return 0; }
target=r[2];
r[16]=0x0c0c26f0u;
write(ram,r[14]+12,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c26f0u) { target=s->pc; goto dispatch; }
goto P_0c0c26f0;
P_0c0c26ee: /* original 1e33, guest PC 0x0c0c26ee */
if(!s->budget--) { s->failed_pc=0x0c0c26eeu; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0c26f0;
P_0c0c26f0: /* original 4f26, guest PC 0x0c0c26f0 */
if(!s->budget--) { s->failed_pc=0x0c0c26f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c26f2;
P_0c0c26f2: /* original e000, guest PC 0x0c0c26f2 */
if(!s->budget--) { s->failed_pc=0x0c0c26f2u; return 0; }
r[0]=0x00000000u;
goto P_0c0c26f4;
P_0c0c26f4: /* original 81ec, guest PC 0x0c0c26f4 */
if(!s->budget--) { s->failed_pc=0x0c0c26f4u; return 0; }
write(ram,r[14]+24,r[0],2);
goto P_0c0c26f6;
P_0c0c26f6: /* original 000b, guest PC 0x0c0c26f6 */
if(!s->budget--) { s->failed_pc=0x0c0c26f6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c26f8: /* original 6ef6, guest PC 0x0c0c26f8 */
if(!s->budget--) { s->failed_pc=0x0c0c26f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c26fau,s,ram);
P_0c0c9d04: /* original 4f22, guest PC 0x0c0c9d04 */
if(!s->budget--) { s->failed_pc=0x0c0c9d04u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9d06;
P_0c0c9d06: /* original bfdb, guest PC 0x0c0c9d06 */
if(!s->budget--) { s->failed_pc=0x0c0c9d06u; return 0; }
target=0x0c0c9cc0u; r[16]=0x0c0c9d0au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9d0au) { target=s->pc; goto dispatch; }
goto P_0c0c9d0a;
P_0c0c9d08: /* original 0009, guest PC 0x0c0c9d08 */
if(!s->budget--) { s->failed_pc=0x0c0c9d08u; return 0; }
goto P_0c0c9d0a;
P_0c0c9d0a: /* original 6403, guest PC 0x0c0c9d0a */
if(!s->budget--) { s->failed_pc=0x0c0c9d0au; return 0; }
r[4]=r[0];
goto P_0c0c9d0c;
P_0c0c9d0c: /* original 445a, guest PC 0x0c0c9d0c */
if(!s->budget--) { s->failed_pc=0x0c0c9d0cu; return 0; }
r[53]=r[4];
goto P_0c0c9d0e;
P_0c0c9d0e: /* original c70e, guest PC 0x0c0c9d0e */
if(!s->budget--) { s->failed_pc=0x0c0c9d0eu; return 0; }
r[0]=0x0c0c9d48u;
goto P_0c0c9d10;
P_0c0c9d10: /* original 4f26, guest PC 0x0c0c9d10 */
if(!s->budget--) { s->failed_pc=0x0c0c9d10u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9d12;
P_0c0c9d12: /* original f32d, guest PC 0x0c0c9d12 */
if(!s->budget--) { s->failed_pc=0x0c0c9d12u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c9d14;
P_0c0c9d14: /* original f43c, guest PC 0x0c0c9d14 */
if(!s->budget--) { s->failed_pc=0x0c0c9d14u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c9d16;
P_0c0c9d16: /* original f308, guest PC 0x0c0c9d16 */
if(!s->budget--) { s->failed_pc=0x0c0c9d16u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c9d18;
P_0c0c9d18: /* original f432, guest PC 0x0c0c9d18 */
if(!s->budget--) { s->failed_pc=0x0c0c9d18u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c9d1a;
P_0c0c9d1a: /* original 000b, guest PC 0x0c0c9d1a */
if(!s->budget--) { s->failed_pc=0x0c0c9d1au; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c0c9d1c: /* original f04c, guest PC 0x0c0c9d1c */
if(!s->budget--) { s->failed_pc=0x0c0c9d1cu; return 0; }
vf3_matrix_move(s,0,4);
return vf3_matrix_family(0x0c0c9d1eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
