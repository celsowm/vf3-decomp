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
int vf3_away_batch133_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a9036u: goto P_0c0a9036;
case 0x0c0a9038u: goto P_0c0a9038;
case 0x0c0a903au: goto P_0c0a903a;
case 0x0c0a903cu: goto P_0c0a903c;
case 0x0c0a903eu: goto P_0c0a903e;
case 0x0c0a9040u: goto P_0c0a9040;
case 0x0c0a9042u: goto P_0c0a9042;
case 0x0c0a9044u: goto P_0c0a9044;
case 0x0c0a9046u: goto P_0c0a9046;
case 0x0c0a9048u: goto P_0c0a9048;
case 0x0c0a904au: goto P_0c0a904a;
case 0x0c0a904cu: goto P_0c0a904c;
case 0x0c0a904eu: goto P_0c0a904e;
case 0x0c0a9050u: goto P_0c0a9050;
case 0x0c0a9052u: goto P_0c0a9052;
case 0x0c0a9054u: goto P_0c0a9054;
case 0x0c0a9056u: goto P_0c0a9056;
case 0x0c0a9058u: goto P_0c0a9058;
case 0x0c0a905au: goto P_0c0a905a;
case 0x0c0a905cu: goto P_0c0a905c;
case 0x0c0a905eu: goto P_0c0a905e;
case 0x0c0a9060u: goto P_0c0a9060;
case 0x0c0a9062u: goto P_0c0a9062;
case 0x0c0a9064u: goto P_0c0a9064;
case 0x0c0a9066u: goto P_0c0a9066;
case 0x0c0a9068u: goto P_0c0a9068;
case 0x0c0a906au: goto P_0c0a906a;
case 0x0c0a906cu: goto P_0c0a906c;
case 0x0c0a9088u: goto P_0c0a9088;
case 0x0c0a908au: goto P_0c0a908a;
case 0x0c0a908cu: goto P_0c0a908c;
case 0x0c0a908eu: goto P_0c0a908e;
case 0x0c0a9090u: goto P_0c0a9090;
case 0x0c0a9092u: goto P_0c0a9092;
case 0x0c0a9094u: goto P_0c0a9094;
case 0x0c0a9096u: goto P_0c0a9096;
case 0x0c0a9098u: goto P_0c0a9098;
case 0x0c0a909au: goto P_0c0a909a;
case 0x0c0a909cu: goto P_0c0a909c;
case 0x0c0a909eu: goto P_0c0a909e;
case 0x0c0a90a0u: goto P_0c0a90a0;
case 0x0c0a90a2u: goto P_0c0a90a2;
case 0x0c0a90a4u: goto P_0c0a90a4;
case 0x0c0a90a6u: goto P_0c0a90a6;
case 0x0c0a90a8u: goto P_0c0a90a8;
case 0x0c0a90aau: goto P_0c0a90aa;
case 0x0c0a90acu: goto P_0c0a90ac;
case 0x0c0a90aeu: goto P_0c0a90ae;
case 0x0c0a90b0u: goto P_0c0a90b0;
case 0x0c0a90b2u: goto P_0c0a90b2;
case 0x0c0a90b4u: goto P_0c0a90b4;
case 0x0c0a90b6u: goto P_0c0a90b6;
case 0x0c0a90b8u: goto P_0c0a90b8;
case 0x0c0a90bau: goto P_0c0a90ba;
case 0x0c0a90bcu: goto P_0c0a90bc;
case 0x0c0a90beu: goto P_0c0a90be;
case 0x0c0a90c0u: goto P_0c0a90c0;
case 0x0c0a90c2u: goto P_0c0a90c2;
case 0x0c0a90c4u: goto P_0c0a90c4;
case 0x0c0a90c6u: goto P_0c0a90c6;
case 0x0c0a90c8u: goto P_0c0a90c8;
case 0x0c0a90cau: goto P_0c0a90ca;
case 0x0c0a90ccu: goto P_0c0a90cc;
case 0x0c0a90ceu: goto P_0c0a90ce;
case 0x0c0a90d0u: goto P_0c0a90d0;
case 0x0c0a90d2u: goto P_0c0a90d2;
case 0x0c0a90d4u: goto P_0c0a90d4;
case 0x0c0a90d6u: goto P_0c0a90d6;
case 0x0c0a90d8u: goto P_0c0a90d8;
case 0x0c0a90dau: goto P_0c0a90da;
case 0x0c0a90dcu: goto P_0c0a90dc;
case 0x0c0a90deu: goto P_0c0a90de;
case 0x0c0a90e0u: goto P_0c0a90e0;
case 0x0c0a90e2u: goto P_0c0a90e2;
case 0x0c0a90e4u: goto P_0c0a90e4;
case 0x0c0a90e6u: goto P_0c0a90e6;
case 0x0c0a90e8u: goto P_0c0a90e8;
case 0x0c0a90eau: goto P_0c0a90ea;
case 0x0c0a90ecu: goto P_0c0a90ec;
case 0x0c0a90eeu: goto P_0c0a90ee;
case 0x0c0a90f0u: goto P_0c0a90f0;
case 0x0c0a90f2u: goto P_0c0a90f2;
case 0x0c0a90f4u: goto P_0c0a90f4;
case 0x0c0a90f6u: goto P_0c0a90f6;
case 0x0c0a90f8u: goto P_0c0a90f8;
case 0x0c0a90fau: goto P_0c0a90fa;
case 0x0c0a90fcu: goto P_0c0a90fc;
case 0x0c0a90feu: goto P_0c0a90fe;
case 0x0c0a9100u: goto P_0c0a9100;
case 0x0c0a9102u: goto P_0c0a9102;
case 0x0c0a9104u: goto P_0c0a9104;
case 0x0c0a9106u: goto P_0c0a9106;
case 0x0c0a9108u: goto P_0c0a9108;
case 0x0c0a910au: goto P_0c0a910a;
case 0x0c0a910cu: goto P_0c0a910c;
case 0x0c0a910eu: goto P_0c0a910e;
case 0x0c0a9110u: goto P_0c0a9110;
case 0x0c0a9112u: goto P_0c0a9112;
case 0x0c0a9114u: goto P_0c0a9114;
case 0x0c0a9116u: goto P_0c0a9116;
case 0x0c0a9118u: goto P_0c0a9118;
case 0x0c0a911au: goto P_0c0a911a;
case 0x0c0a911cu: goto P_0c0a911c;
case 0x0c0a911eu: goto P_0c0a911e;
case 0x0c0a9120u: goto P_0c0a9120;
case 0x0c0a9122u: goto P_0c0a9122;
case 0x0c0a9124u: goto P_0c0a9124;
case 0x0c0a9126u: goto P_0c0a9126;
case 0x0c0a9128u: goto P_0c0a9128;
case 0x0c0a912au: goto P_0c0a912a;
case 0x0c0a912cu: goto P_0c0a912c;
case 0x0c0a912eu: goto P_0c0a912e;
case 0x0c0a9130u: goto P_0c0a9130;
case 0x0c0a9132u: goto P_0c0a9132;
case 0x0c0a9134u: goto P_0c0a9134;
case 0x0c0a9136u: goto P_0c0a9136;
case 0x0c0a9138u: goto P_0c0a9138;
case 0x0c0a913au: goto P_0c0a913a;
case 0x0c0a913cu: goto P_0c0a913c;
case 0x0c0a913eu: goto P_0c0a913e;
case 0x0c0a9140u: goto P_0c0a9140;
case 0x0c0a9142u: goto P_0c0a9142;
case 0x0c0a9144u: goto P_0c0a9144;
case 0x0c0a9146u: goto P_0c0a9146;
case 0x0c0a9148u: goto P_0c0a9148;
case 0x0c0a914au: goto P_0c0a914a;
case 0x0c0a914cu: goto P_0c0a914c;
case 0x0c0a914eu: goto P_0c0a914e;
case 0x0c0a9150u: goto P_0c0a9150;
case 0x0c0a9152u: goto P_0c0a9152;
case 0x0c0a9154u: goto P_0c0a9154;
case 0x0c0a9156u: goto P_0c0a9156;
case 0x0c0a9158u: goto P_0c0a9158;
case 0x0c0a915au: goto P_0c0a915a;
case 0x0c0a915cu: goto P_0c0a915c;
case 0x0c0a915eu: goto P_0c0a915e;
case 0x0c0a9160u: goto P_0c0a9160;
case 0x0c0a9162u: goto P_0c0a9162;
case 0x0c0a9164u: goto P_0c0a9164;
case 0x0c0a9166u: goto P_0c0a9166;
case 0x0c0a9168u: goto P_0c0a9168;
case 0x0c0a916au: goto P_0c0a916a;
case 0x0c0a916cu: goto P_0c0a916c;
case 0x0c0a916eu: goto P_0c0a916e;
case 0x0c0a9170u: goto P_0c0a9170;
case 0x0c0a9172u: goto P_0c0a9172;
case 0x0c0a9174u: goto P_0c0a9174;
case 0x0c0a9176u: goto P_0c0a9176;
case 0x0c0a9178u: goto P_0c0a9178;
case 0x0c0a917au: goto P_0c0a917a;
case 0x0c0a917cu: goto P_0c0a917c;
case 0x0c0a917eu: goto P_0c0a917e;
case 0x0c0a9180u: goto P_0c0a9180;
case 0x0c0a9182u: goto P_0c0a9182;
case 0x0c0a9184u: goto P_0c0a9184;
case 0x0c0a9186u: goto P_0c0a9186;
case 0x0c0a9188u: goto P_0c0a9188;
case 0x0c0a918au: goto P_0c0a918a;
case 0x0c0a918cu: goto P_0c0a918c;
case 0x0c0a918eu: goto P_0c0a918e;
case 0x0c0a9190u: goto P_0c0a9190;
case 0x0c0a9192u: goto P_0c0a9192;
case 0x0c0a9194u: goto P_0c0a9194;
case 0x0c0a9196u: goto P_0c0a9196;
case 0x0c0a9198u: goto P_0c0a9198;
case 0x0c0a919au: goto P_0c0a919a;
case 0x0c0a91c0u: goto P_0c0a91c0;
case 0x0c0a91c2u: goto P_0c0a91c2;
case 0x0c0a91c4u: goto P_0c0a91c4;
case 0x0c0a91c6u: goto P_0c0a91c6;
case 0x0c0a91c8u: goto P_0c0a91c8;
case 0x0c0a91cau: goto P_0c0a91ca;
case 0x0c0a91ccu: goto P_0c0a91cc;
case 0x0c0a91ceu: goto P_0c0a91ce;
case 0x0c0a91d0u: goto P_0c0a91d0;
case 0x0c0a91d2u: goto P_0c0a91d2;
case 0x0c0a91d4u: goto P_0c0a91d4;
case 0x0c0a91d6u: goto P_0c0a91d6;
case 0x0c0a91d8u: goto P_0c0a91d8;
case 0x0c0c5d86u: goto P_0c0c5d86;
case 0x0c0c5d88u: goto P_0c0c5d88;
case 0x0c0c5d8au: goto P_0c0c5d8a;
case 0x0c0c5d8cu: goto P_0c0c5d8c;
case 0x0c0c5d8eu: goto P_0c0c5d8e;
case 0x0c0c5d90u: goto P_0c0c5d90;
case 0x0c0c5d92u: goto P_0c0c5d92;
case 0x0c0c5d94u: goto P_0c0c5d94;
case 0x0c0c5d96u: goto P_0c0c5d96;
case 0x0c0c5d98u: goto P_0c0c5d98;
case 0x0c0c5d9au: goto P_0c0c5d9a;
case 0x0c0c5d9cu: goto P_0c0c5d9c;
case 0x0c0c5d9eu: goto P_0c0c5d9e;
case 0x0c0c5da0u: goto P_0c0c5da0;
case 0x0c0c5da2u: goto P_0c0c5da2;
case 0x0c0c5da4u: goto P_0c0c5da4;
case 0x0c0c5da6u: goto P_0c0c5da6;
case 0x0c0c5da8u: goto P_0c0c5da8;
case 0x0c0c5daau: goto P_0c0c5daa;
case 0x0c0c5dacu: goto P_0c0c5dac;
case 0x0c0c5daeu: goto P_0c0c5dae;
case 0x0c0c5db0u: goto P_0c0c5db0;
case 0x0c0c5db2u: goto P_0c0c5db2;
case 0x0c0c5db4u: goto P_0c0c5db4;
case 0x0c0c5db6u: goto P_0c0c5db6;
case 0x0c0c5db8u: goto P_0c0c5db8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a9036: /* original 2fe6, guest PC 0x0c0a9036 */
if(!s->budget--) { s->failed_pc=0x0c0a9036u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9038;
P_0c0a9038: /* original 2fd6, guest PC 0x0c0a9038 */
if(!s->budget--) { s->failed_pc=0x0c0a9038u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a903a;
P_0c0a903a: /* original 6d43, guest PC 0x0c0a903a */
if(!s->budget--) { s->failed_pc=0x0c0a903au; return 0; }
r[13]=r[4];
goto P_0c0a903c;
P_0c0a903c: /* original 2fc6, guest PC 0x0c0a903c */
if(!s->budget--) { s->failed_pc=0x0c0a903cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a903e;
P_0c0a903e: /* original 2fb6, guest PC 0x0c0a903e */
if(!s->budget--) { s->failed_pc=0x0c0a903eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9040;
P_0c0a9040: /* original 4f22, guest PC 0x0c0a9040 */
if(!s->budget--) { s->failed_pc=0x0c0a9040u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9042;
P_0c0a9042: /* original 7fe8, guest PC 0x0c0a9042 */
if(!s->budget--) { s->failed_pc=0x0c0a9042u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0a9044;
P_0c0a9044: /* original 1f61, guest PC 0x0c0a9044 */
if(!s->budget--) { s->failed_pc=0x0c0a9044u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a9046;
P_0c0a9046: /* original db0f, guest PC 0x0c0a9046 */
if(!s->budget--) { s->failed_pc=0x0c0a9046u; return 0; }
r[11]=read(ram,0x0c0a9084u,4);
goto P_0c0a9048;
P_0c0a9048: /* original 9313, guest PC 0x0c0a9048 */
if(!s->budget--) { s->failed_pc=0x0c0a9048u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9072u,2);
goto P_0c0a904a;
P_0c0a904a: /* original 5cb2, guest PC 0x0c0a904a */
if(!s->budget--) { s->failed_pc=0x0c0a904au; return 0; }
r[12]=read(ram,r[11]+8,4);
goto P_0c0a904c;
P_0c0a904c: /* original 23c8, guest PC 0x0c0a904c */
if(!s->budget--) { s->failed_pc=0x0c0a904cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0a904e;
P_0c0a904e: /* original 8d1b, guest PC 0x0c0a904e */
if(!s->budget--) { s->failed_pc=0x0c0a904eu; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c0a9088; }
goto P_0c0a9052;
P_0c0a9050: /* original 6e53, guest PC 0x0c0a9050 */
if(!s->budget--) { s->failed_pc=0x0c0a9050u; return 0; }
r[14]=r[5];
goto P_0c0a9052;
P_0c0a9052: /* original e040, guest PC 0x0c0a9052 */
if(!s->budget--) { s->failed_pc=0x0c0a9052u; return 0; }
r[0]=0x00000040u;
goto P_0c0a9054;
P_0c0a9054: /* original e100, guest PC 0x0c0a9054 */
if(!s->budget--) { s->failed_pc=0x0c0a9054u; return 0; }
r[1]=0x00000000u;
goto P_0c0a9056;
P_0c0a9056: /* original 0e15, guest PC 0x0c0a9056 */
if(!s->budget--) { s->failed_pc=0x0c0a9056u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0a9058;
P_0c0a9058: /* original e301, guest PC 0x0c0a9058 */
if(!s->budget--) { s->failed_pc=0x0c0a9058u; return 0; }
r[3]=0x00000001u;
goto P_0c0a905a;
P_0c0a905a: /* original 900b, guest PC 0x0c0a905a */
if(!s->budget--) { s->failed_pc=0x0c0a905au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9074u,2);
goto P_0c0a905c;
P_0c0a905c: /* original 0cbd, guest PC 0x0c0a905c */
if(!s->budget--) { s->failed_pc=0x0c0a905cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0a905e;
P_0c0a905e: /* original 23c8, guest PC 0x0c0a905e */
if(!s->budget--) { s->failed_pc=0x0c0a905eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0a9060;
P_0c0a9060: /* original 8912, guest PC 0x0c0a9060 */
if(!s->budget--) { s->failed_pc=0x0c0a9060u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9088; }
goto P_0c0a9062;
P_0c0a9062: /* original 56f1, guest PC 0x0c0a9062 */
if(!s->budget--) { s->failed_pc=0x0c0a9062u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0a9064;
P_0c0a9064: /* original 65e3, guest PC 0x0c0a9064 */
if(!s->budget--) { s->failed_pc=0x0c0a9064u; return 0; }
r[5]=r[14];
goto P_0c0a9066;
P_0c0a9066: /* original bf91, guest PC 0x0c0a9066 */
if(!s->budget--) { s->failed_pc=0x0c0a9066u; return 0; }
target=code_base|0x0c0a8f8cu; r[16]=code_base|0x0c0a906au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a906au) { target=s->pc; goto dispatch; }
goto P_0c0a906a;
P_0c0a9068: /* original 64d3, guest PC 0x0c0a9068 */
if(!s->budget--) { s->failed_pc=0x0c0a9068u; return 0; }
r[4]=r[13];
goto P_0c0a906a;
P_0c0a906a: /* original a0af, guest PC 0x0c0a906a */
if(!s->budget--) { s->failed_pc=0x0c0a906au; return 0; }
goto P_0c0a91cc;
P_0c0a906c: /* original 0009, guest PC 0x0c0a906c */
if(!s->budget--) { s->failed_pc=0x0c0a906cu; return 0; }
if(!vf3_matrix_family(0x0c0a906eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a906eu; return 0; } return 1;
P_0c0a9088: /* original e004, guest PC 0x0c0a9088 */
if(!s->budget--) { s->failed_pc=0x0c0a9088u; return 0; }
r[0]=0x00000004u;
goto P_0c0a908a;
P_0c0a908a: /* original 64d2, guest PC 0x0c0a908a */
if(!s->budget--) { s->failed_pc=0x0c0a908au; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a908c;
P_0c0a908c: /* original e3fe, guest PC 0x0c0a908c */
if(!s->budget--) { s->failed_pc=0x0c0a908cu; return 0; }
r[3]=0xfffffffeu;
goto P_0c0a908e;
P_0c0a908e: /* original 2439, guest PC 0x0c0a908e */
if(!s->budget--) { s->failed_pc=0x0c0a908eu; return 0; }
r[4]&=r[3];
goto P_0c0a9090;
P_0c0a9090: /* original 2e42, guest PC 0x0c0a9090 */
if(!s->budget--) { s->failed_pc=0x0c0a9090u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0a9092;
P_0c0a9092: /* original f5d6, guest PC 0x0c0a9092 */
if(!s->budget--) { s->failed_pc=0x0c0a9092u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a9094;
P_0c0a9094: /* original e008, guest PC 0x0c0a9094 */
if(!s->budget--) { s->failed_pc=0x0c0a9094u; return 0; }
r[0]=0x00000008u;
goto P_0c0a9096;
P_0c0a9096: /* original f6d6, guest PC 0x0c0a9096 */
if(!s->budget--) { s->failed_pc=0x0c0a9096u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c0a9098;
P_0c0a9098: /* original e00c, guest PC 0x0c0a9098 */
if(!s->budget--) { s->failed_pc=0x0c0a9098u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a909a;
P_0c0a909a: /* original f4d6, guest PC 0x0c0a909a */
if(!s->budget--) { s->failed_pc=0x0c0a909au; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0a909c;
P_0c0a909c: /* original e020, guest PC 0x0c0a909c */
if(!s->budget--) { s->failed_pc=0x0c0a909cu; return 0; }
r[0]=0x00000020u;
goto P_0c0a909e;
P_0c0a909e: /* original 00dd, guest PC 0x0c0a909e */
if(!s->budget--) { s->failed_pc=0x0c0a909eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90a0;
P_0c0a90a0: /* original 81f4, guest PC 0x0c0a90a0 */
if(!s->budget--) { s->failed_pc=0x0c0a90a0u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0a90a2;
P_0c0a90a2: /* original e024, guest PC 0x0c0a90a2 */
if(!s->budget--) { s->failed_pc=0x0c0a90a2u; return 0; }
r[0]=0x00000024u;
goto P_0c0a90a4;
P_0c0a90a4: /* original 04dd, guest PC 0x0c0a90a4 */
if(!s->budget--) { s->failed_pc=0x0c0a90a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90a6;
P_0c0a90a6: /* original e038, guest PC 0x0c0a90a6 */
if(!s->budget--) { s->failed_pc=0x0c0a90a6u; return 0; }
r[0]=0x00000038u;
goto P_0c0a90a8;
P_0c0a90a8: /* original 52dc, guest PC 0x0c0a90a8 */
if(!s->budget--) { s->failed_pc=0x0c0a90a8u; return 0; }
r[2]=read(ram,r[13]+48,4);
goto P_0c0a90aa;
P_0c0a90aa: /* original 56db, guest PC 0x0c0a90aa */
if(!s->budget--) { s->failed_pc=0x0c0a90aau; return 0; }
r[6]=read(ram,r[13]+44,4);
goto P_0c0a90ac;
P_0c0a90ac: /* original 55d4, guest PC 0x0c0a90ac */
if(!s->budget--) { s->failed_pc=0x0c0a90acu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0a90ae;
P_0c0a90ae: /* original 57d7, guest PC 0x0c0a90ae */
if(!s->budget--) { s->failed_pc=0x0c0a90aeu; return 0; }
r[7]=read(ram,r[13]+28,4);
goto P_0c0a90b0;
P_0c0a90b0: /* original 2f22, guest PC 0x0c0a90b0 */
if(!s->budget--) { s->failed_pc=0x0c0a90b0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a90b2;
P_0c0a90b2: /* original 01dc, guest PC 0x0c0a90b2 */
if(!s->budget--) { s->failed_pc=0x0c0a90b2u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a90b4;
P_0c0a90b4: /* original e014, guest PC 0x0c0a90b4 */
if(!s->budget--) { s->failed_pc=0x0c0a90b4u; return 0; }
r[0]=0x00000014u;
goto P_0c0a90b6;
P_0c0a90b6: /* original 0f14, guest PC 0x0c0a90b6 */
if(!s->budget--) { s->failed_pc=0x0c0a90b6u; return 0; }
write(ram,r[15]+r[0],r[1],1);
goto P_0c0a90b8;
P_0c0a90b8: /* original e02a, guest PC 0x0c0a90b8 */
if(!s->budget--) { s->failed_pc=0x0c0a90b8u; return 0; }
r[0]=0x0000002au;
goto P_0c0a90ba;
P_0c0a90ba: /* original 00dd, guest PC 0x0c0a90ba */
if(!s->budget--) { s->failed_pc=0x0c0a90bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90bc;
P_0c0a90bc: /* original 81f8, guest PC 0x0c0a90bc */
if(!s->budget--) { s->failed_pc=0x0c0a90bcu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0a90be;
P_0c0a90be: /* original e03a, guest PC 0x0c0a90be */
if(!s->budget--) { s->failed_pc=0x0c0a90beu; return 0; }
r[0]=0x0000003au;
goto P_0c0a90c0;
P_0c0a90c0: /* original 00dc, guest PC 0x0c0a90c0 */
if(!s->budget--) { s->failed_pc=0x0c0a90c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a90c2;
P_0c0a90c2: /* original 80fc, guest PC 0x0c0a90c2 */
if(!s->budget--) { s->failed_pc=0x0c0a90c2u; return 0; }
write(ram,r[15]+12,r[0],1);
goto P_0c0a90c4;
P_0c0a90c4: /* original e010, guest PC 0x0c0a90c4 */
if(!s->budget--) { s->failed_pc=0x0c0a90c4u; return 0; }
r[0]=0x00000010u;
goto P_0c0a90c6;
P_0c0a90c6: /* original fe57, guest PC 0x0c0a90c6 */
if(!s->budget--) { s->failed_pc=0x0c0a90c6u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a90c8;
P_0c0a90c8: /* original e014, guest PC 0x0c0a90c8 */
if(!s->budget--) { s->failed_pc=0x0c0a90c8u; return 0; }
r[0]=0x00000014u;
goto P_0c0a90ca;
P_0c0a90ca: /* original fe67, guest PC 0x0c0a90ca */
if(!s->budget--) { s->failed_pc=0x0c0a90cau; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a90cc;
P_0c0a90cc: /* original e018, guest PC 0x0c0a90cc */
if(!s->budget--) { s->failed_pc=0x0c0a90ccu; return 0; }
r[0]=0x00000018u;
goto P_0c0a90ce;
P_0c0a90ce: /* original fe47, guest PC 0x0c0a90ce */
if(!s->budget--) { s->failed_pc=0x0c0a90ceu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a90d0;
P_0c0a90d0: /* original 85f4, guest PC 0x0c0a90d0 */
if(!s->budget--) { s->failed_pc=0x0c0a90d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0a90d2;
P_0c0a90d2: /* original 81ef, guest PC 0x0c0a90d2 */
if(!s->budget--) { s->failed_pc=0x0c0a90d2u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a90d4;
P_0c0a90d4: /* original e03e, guest PC 0x0c0a90d4 */
if(!s->budget--) { s->failed_pc=0x0c0a90d4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a90d6;
P_0c0a90d6: /* original 0e45, guest PC 0x0c0a90d6 */
if(!s->budget--) { s->failed_pc=0x0c0a90d6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a90d8;
P_0c0a90d8: /* original 9060, guest PC 0x0c0a90d8 */
if(!s->budget--) { s->failed_pc=0x0c0a90d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a919cu,2);
goto P_0c0a90da;
P_0c0a90da: /* original 0e46, guest PC 0x0c0a90da */
if(!s->budget--) { s->failed_pc=0x0c0a90dau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a90dc;
P_0c0a90dc: /* original e048, guest PC 0x0c0a90dc */
if(!s->budget--) { s->failed_pc=0x0c0a90dcu; return 0; }
r[0]=0x00000048u;
goto P_0c0a90de;
P_0c0a90de: /* original 0e56, guest PC 0x0c0a90de */
if(!s->budget--) { s->failed_pc=0x0c0a90deu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0a90e0;
P_0c0a90e0: /* original 905d, guest PC 0x0c0a90e0 */
if(!s->budget--) { s->failed_pc=0x0c0a90e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a919eu,2);
goto P_0c0a90e2;
P_0c0a90e2: /* original 0e66, guest PC 0x0c0a90e2 */
if(!s->budget--) { s->failed_pc=0x0c0a90e2u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0a90e4;
P_0c0a90e4: /* original 905c, guest PC 0x0c0a90e4 */
if(!s->budget--) { s->failed_pc=0x0c0a90e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a0u,2);
goto P_0c0a90e6;
P_0c0a90e6: /* original 0e76, guest PC 0x0c0a90e6 */
if(!s->budget--) { s->failed_pc=0x0c0a90e6u; return 0; }
write(ram,r[14]+r[0],r[7],4);
goto P_0c0a90e8;
P_0c0a90e8: /* original 905b, guest PC 0x0c0a90e8 */
if(!s->budget--) { s->failed_pc=0x0c0a90e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a2u,2);
goto P_0c0a90ea;
P_0c0a90ea: /* original 62f2, guest PC 0x0c0a90ea */
if(!s->budget--) { s->failed_pc=0x0c0a90eau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a90ec;
P_0c0a90ec: /* original 0e26, guest PC 0x0c0a90ec */
if(!s->budget--) { s->failed_pc=0x0c0a90ecu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0a90ee;
P_0c0a90ee: /* original e014, guest PC 0x0c0a90ee */
if(!s->budget--) { s->failed_pc=0x0c0a90eeu; return 0; }
r[0]=0x00000014u;
goto P_0c0a90f0;
P_0c0a90f0: /* original 01fc, guest PC 0x0c0a90f0 */
if(!s->budget--) { s->failed_pc=0x0c0a90f0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0a90f2;
P_0c0a90f2: /* original e246, guest PC 0x0c0a90f2 */
if(!s->budget--) { s->failed_pc=0x0c0a90f2u; return 0; }
r[2]=0x00000046u;
goto P_0c0a90f4;
P_0c0a90f4: /* original 9056, guest PC 0x0c0a90f4 */
if(!s->budget--) { s->failed_pc=0x0c0a90f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a4u,2);
goto P_0c0a90f6;
P_0c0a90f6: /* original 32ec, guest PC 0x0c0a90f6 */
if(!s->budget--) { s->failed_pc=0x0c0a90f6u; return 0; }
r[2]+=r[14];
goto P_0c0a90f8;
P_0c0a90f8: /* original 0e14, guest PC 0x0c0a90f8 */
if(!s->budget--) { s->failed_pc=0x0c0a90f8u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a90fa;
P_0c0a90fa: /* original 85f8, guest PC 0x0c0a90fa */
if(!s->budget--) { s->failed_pc=0x0c0a90fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0a90fc;
P_0c0a90fc: /* original 2201, guest PC 0x0c0a90fc */
if(!s->budget--) { s->failed_pc=0x0c0a90fcu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a90fe;
P_0c0a90fe: /* original 9152, guest PC 0x0c0a90fe */
if(!s->budget--) { s->failed_pc=0x0c0a90feu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a6u,2);
goto P_0c0a9100;
P_0c0a9100: /* original 84fc, guest PC 0x0c0a9100 */
if(!s->budget--) { s->failed_pc=0x0c0a9100u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c0a9102;
P_0c0a9102: /* original 31bc, guest PC 0x0c0a9102 */
if(!s->budget--) { s->failed_pc=0x0c0a9102u; return 0; }
r[1]+=r[11];
goto P_0c0a9104;
P_0c0a9104: /* original 2100, guest PC 0x0c0a9104 */
if(!s->budget--) { s->failed_pc=0x0c0a9104u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a9106;
P_0c0a9106: /* original e061, guest PC 0x0c0a9106 */
if(!s->budget--) { s->failed_pc=0x0c0a9106u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9108;
P_0c0a9108: /* original 04ec, guest PC 0x0c0a9108 */
if(!s->budget--) { s->failed_pc=0x0c0a9108u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a910a;
P_0c0a910a: /* original 604e, guest PC 0x0c0a910a */
if(!s->budget--) { s->failed_pc=0x0c0a910au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a910c;
P_0c0a910c: /* original 8808, guest PC 0x0c0a910c */
if(!s->budget--) { s->failed_pc=0x0c0a910cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0a910e;
P_0c0a910e: /* original 8b03, guest PC 0x0c0a910e */
if(!s->budget--) { s->failed_pc=0x0c0a910eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9118; }
goto P_0c0a9110;
P_0c0a9110: /* original e039, guest PC 0x0c0a9110 */
if(!s->budget--) { s->failed_pc=0x0c0a9110u; return 0; }
r[0]=0x00000039u;
goto P_0c0a9112;
P_0c0a9112: /* original 04dc, guest PC 0x0c0a9112 */
if(!s->budget--) { s->failed_pc=0x0c0a9112u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a9114;
P_0c0a9114: /* original 9048, guest PC 0x0c0a9114 */
if(!s->budget--) { s->failed_pc=0x0c0a9114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a8u,2);
goto P_0c0a9116;
P_0c0a9116: /* original 0e44, guest PC 0x0c0a9116 */
if(!s->budget--) { s->failed_pc=0x0c0a9116u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9118;
P_0c0a9118: /* original 54d5, guest PC 0x0c0a9118 */
if(!s->budget--) { s->failed_pc=0x0c0a9118u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c0a911a;
P_0c0a911a: /* original 2448, guest PC 0x0c0a911a */
if(!s->budget--) { s->failed_pc=0x0c0a911au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a911c;
P_0c0a911c: /* original 8902, guest PC 0x0c0a911c */
if(!s->budget--) { s->failed_pc=0x0c0a911cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9124; }
goto P_0c0a911e;
P_0c0a911e: /* original d224, guest PC 0x0c0a911e */
if(!s->budget--) { s->failed_pc=0x0c0a911eu; return 0; }
r[2]=read(ram,0x0c0a91b0u,4);
goto P_0c0a9120;
P_0c0a9120: /* original 420b, guest PC 0x0c0a9120 */
if(!s->budget--) { s->failed_pc=0x0c0a9120u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9124u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9124u) { target=s->pc; goto dispatch; }
goto P_0c0a9124;
P_0c0a9122: /* original 0009, guest PC 0x0c0a9122 */
if(!s->budget--) { s->failed_pc=0x0c0a9122u; return 0; }
goto P_0c0a9124;
P_0c0a9124: /* original 54d6, guest PC 0x0c0a9124 */
if(!s->budget--) { s->failed_pc=0x0c0a9124u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0a9126;
P_0c0a9126: /* original 2448, guest PC 0x0c0a9126 */
if(!s->budget--) { s->failed_pc=0x0c0a9126u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9128;
P_0c0a9128: /* original 8902, guest PC 0x0c0a9128 */
if(!s->budget--) { s->failed_pc=0x0c0a9128u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9130; }
goto P_0c0a912a;
P_0c0a912a: /* original d221, guest PC 0x0c0a912a */
if(!s->budget--) { s->failed_pc=0x0c0a912au; return 0; }
r[2]=read(ram,0x0c0a91b0u,4);
goto P_0c0a912c;
P_0c0a912c: /* original 420b, guest PC 0x0c0a912c */
if(!s->budget--) { s->failed_pc=0x0c0a912cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9130u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9130u) { target=s->pc; goto dispatch; }
goto P_0c0a9130;
P_0c0a912e: /* original 0009, guest PC 0x0c0a912e */
if(!s->budget--) { s->failed_pc=0x0c0a912eu; return 0; }
goto P_0c0a9130;
P_0c0a9130: /* original e03c, guest PC 0x0c0a9130 */
if(!s->budget--) { s->failed_pc=0x0c0a9130u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9132;
P_0c0a9132: /* original 06ed, guest PC 0x0c0a9132 */
if(!s->budget--) { s->failed_pc=0x0c0a9132u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9134;
P_0c0a9134: /* original e022, guest PC 0x0c0a9134 */
if(!s->budget--) { s->failed_pc=0x0c0a9134u; return 0; }
r[0]=0x00000022u;
goto P_0c0a9136;
P_0c0a9136: /* original 04dd, guest PC 0x0c0a9136 */
if(!s->budget--) { s->failed_pc=0x0c0a9136u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a9138;
P_0c0a9138: /* original e03c, guest PC 0x0c0a9138 */
if(!s->budget--) { s->failed_pc=0x0c0a9138u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a913a;
P_0c0a913a: /* original 654f, guest PC 0x0c0a913a */
if(!s->budget--) { s->failed_pc=0x0c0a913au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a913c;
P_0c0a913c: /* original 2558, guest PC 0x0c0a913c */
if(!s->budget--) { s->failed_pc=0x0c0a913cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a913e;
P_0c0a913e: /* original 8d45, guest PC 0x0c0a913e */
if(!s->budget--) { s->failed_pc=0x0c0a913eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0a91cc; }
goto P_0c0a9142;
P_0c0a9140: /* original 0e45, guest PC 0x0c0a9140 */
if(!s->budget--) { s->failed_pc=0x0c0a9140u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9142;
P_0c0a9142: /* original 666f, guest PC 0x0c0a9142 */
if(!s->budget--) { s->failed_pc=0x0c0a9142u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0a9144;
P_0c0a9144: /* original 3560, guest PC 0x0c0a9144 */
if(!s->budget--) { s->failed_pc=0x0c0a9144u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0a9146;
P_0c0a9146: /* original 8b19, guest PC 0x0c0a9146 */
if(!s->budget--) { s->failed_pc=0x0c0a9146u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a917c; }
goto P_0c0a9148;
P_0c0a9148: /* original 902f, guest PC 0x0c0a9148 */
if(!s->budget--) { s->failed_pc=0x0c0a9148u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91aau,2);
goto P_0c0a914a;
P_0c0a914a: /* original 7cfd, guest PC 0x0c0a914a */
if(!s->budget--) { s->failed_pc=0x0c0a914au; return 0; }
r[12]+=0xfffffffdu;
goto P_0c0a914c;
P_0c0a914c: /* original 63c3, guest PC 0x0c0a914c */
if(!s->budget--) { s->failed_pc=0x0c0a914cu; return 0; }
r[3]=r[12];
goto P_0c0a914e;
P_0c0a914e: /* original e503, guest PC 0x0c0a914e */
if(!s->budget--) { s->failed_pc=0x0c0a914eu; return 0; }
r[5]=0x00000003u;
goto P_0c0a9150;
P_0c0a9150: /* original 04bc, guest PC 0x0c0a9150 */
if(!s->budget--) { s->failed_pc=0x0c0a9150u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0a9152;
P_0c0a9152: /* original 3353, guest PC 0x0c0a9152 */
if(!s->budget--) { s->failed_pc=0x0c0a9152u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a9154;
P_0c0a9154: /* original 8d03, guest PC 0x0c0a9154 */
if(!s->budget--) { s->failed_pc=0x0c0a9154u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[12],4);
if(cond) { goto P_0c0a915e; }
goto P_0c0a9158;
P_0c0a9156: /* original 2fc2, guest PC 0x0c0a9156 */
if(!s->budget--) { s->failed_pc=0x0c0a9156u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0a9158;
P_0c0a9158: /* original 9027, guest PC 0x0c0a9158 */
if(!s->budget--) { s->failed_pc=0x0c0a9158u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91aau,2);
goto P_0c0a915a;
P_0c0a915a: /* original 7401, guest PC 0x0c0a915a */
if(!s->budget--) { s->failed_pc=0x0c0a915au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a915c;
P_0c0a915c: /* original 0b44, guest PC 0x0c0a915c */
if(!s->budget--) { s->failed_pc=0x0c0a915cu; return 0; }
write(ram,r[11]+r[0],r[4],1);
goto P_0c0a915e;
P_0c0a915e: /* original 63f2, guest PC 0x0c0a915e */
if(!s->budget--) { s->failed_pc=0x0c0a915eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a9160;
P_0c0a9160: /* original 3353, guest PC 0x0c0a9160 */
if(!s->budget--) { s->failed_pc=0x0c0a9160u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a9162;
P_0c0a9162: /* original 8903, guest PC 0x0c0a9162 */
if(!s->budget--) { s->failed_pc=0x0c0a9162u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a916c; }
goto P_0c0a9164;
P_0c0a9164: /* original 9022, guest PC 0x0c0a9164 */
if(!s->budget--) { s->failed_pc=0x0c0a9164u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91acu,2);
goto P_0c0a9166;
P_0c0a9166: /* original e101, guest PC 0x0c0a9166 */
if(!s->budget--) { s->failed_pc=0x0c0a9166u; return 0; }
r[1]=0x00000001u;
goto P_0c0a9168;
P_0c0a9168: /* original a008, guest PC 0x0c0a9168 */
if(!s->budget--) { s->failed_pc=0x0c0a9168u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a917c;
P_0c0a916a: /* original 0e14, guest PC 0x0c0a916a */
if(!s->budget--) { s->failed_pc=0x0c0a916au; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a916c;
P_0c0a916c: /* original e03e, guest PC 0x0c0a916c */
if(!s->budget--) { s->failed_pc=0x0c0a916cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a916e;
P_0c0a916e: /* original 04ed, guest PC 0x0c0a916e */
if(!s->budget--) { s->failed_pc=0x0c0a916eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9170;
P_0c0a9170: /* original 604d, guest PC 0x0c0a9170 */
if(!s->budget--) { s->failed_pc=0x0c0a9170u; return 0; }
r[0]=r[4]&65535u;
goto P_0c0a9172;
P_0c0a9172: /* original 8801, guest PC 0x0c0a9172 */
if(!s->budget--) { s->failed_pc=0x0c0a9172u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9174;
P_0c0a9174: /* original 8d0d, guest PC 0x0c0a9174 */
if(!s->budget--) { s->failed_pc=0x0c0a9174u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0a9192; }
goto P_0c0a9178;
P_0c0a9176: /* original 6403, guest PC 0x0c0a9176 */
if(!s->budget--) { s->failed_pc=0x0c0a9176u; return 0; }
r[4]=r[0];
goto P_0c0a9178;
P_0c0a9178: /* original a022, guest PC 0x0c0a9178 */
if(!s->budget--) { s->failed_pc=0x0c0a9178u; return 0; }
goto P_0c0a91c0;
P_0c0a917a: /* original 0009, guest PC 0x0c0a917a */
if(!s->budget--) { s->failed_pc=0x0c0a917au; return 0; }
goto P_0c0a917c;
P_0c0a917c: /* original e03c, guest PC 0x0c0a917c */
if(!s->budget--) { s->failed_pc=0x0c0a917cu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a917e;
P_0c0a917e: /* original 02ed, guest PC 0x0c0a917e */
if(!s->budget--) { s->failed_pc=0x0c0a917eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9180;
P_0c0a9180: /* original 2f21, guest PC 0x0c0a9180 */
if(!s->budget--) { s->failed_pc=0x0c0a9180u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0a9182;
P_0c0a9182: /* original 55f1, guest PC 0x0c0a9182 */
if(!s->budget--) { s->failed_pc=0x0c0a9182u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0a9184;
P_0c0a9184: /* original 66f1, guest PC 0x0c0a9184 */
if(!s->budget--) { s->failed_pc=0x0c0a9184u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a9186;
P_0c0a9186: /* original d30b, guest PC 0x0c0a9186 */
if(!s->budget--) { s->failed_pc=0x0c0a9186u; return 0; }
r[3]=read(ram,0x0c0a91b4u,4);
goto P_0c0a9188;
P_0c0a9188: /* original 430b, guest PC 0x0c0a9188 */
if(!s->budget--) { s->failed_pc=0x0c0a9188u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a918cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a918cu) { target=s->pc; goto dispatch; }
goto P_0c0a918c;
P_0c0a918a: /* original 64e3, guest PC 0x0c0a918a */
if(!s->budget--) { s->failed_pc=0x0c0a918au; return 0; }
r[4]=r[14];
goto P_0c0a918c;
P_0c0a918c: /* original d20a, guest PC 0x0c0a918c */
if(!s->budget--) { s->failed_pc=0x0c0a918cu; return 0; }
r[2]=read(ram,0x0c0a91b8u,4);
goto P_0c0a918e;
P_0c0a918e: /* original 420b, guest PC 0x0c0a918e */
if(!s->budget--) { s->failed_pc=0x0c0a918eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9192u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9192u) { target=s->pc; goto dispatch; }
goto P_0c0a9192;
P_0c0a9190: /* original 64e3, guest PC 0x0c0a9190 */
if(!s->budget--) { s->failed_pc=0x0c0a9190u; return 0; }
r[4]=r[14];
goto P_0c0a9192;
P_0c0a9192: /* original d30a, guest PC 0x0c0a9192 */
if(!s->budget--) { s->failed_pc=0x0c0a9192u; return 0; }
r[3]=read(ram,0x0c0a91bcu,4);
goto P_0c0a9194;
P_0c0a9194: /* original 430b, guest PC 0x0c0a9194 */
if(!s->budget--) { s->failed_pc=0x0c0a9194u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9198u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9198u) { target=s->pc; goto dispatch; }
goto P_0c0a9198;
P_0c0a9196: /* original 64e3, guest PC 0x0c0a9196 */
if(!s->budget--) { s->failed_pc=0x0c0a9196u; return 0; }
r[4]=r[14];
goto P_0c0a9198;
P_0c0a9198: /* original a015, guest PC 0x0c0a9198 */
if(!s->budget--) { s->failed_pc=0x0c0a9198u; return 0; }
goto P_0c0a91c6;
P_0c0a919a: /* original 0009, guest PC 0x0c0a919a */
if(!s->budget--) { s->failed_pc=0x0c0a919au; return 0; }
if(!vf3_matrix_family(0x0c0a919cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a919cu; return 0; } return 1;
P_0c0a91c0: /* original d335, guest PC 0x0c0a91c0 */
if(!s->budget--) { s->failed_pc=0x0c0a91c0u; return 0; }
r[3]=read(ram,0x0c0a9298u,4);
goto P_0c0a91c2;
P_0c0a91c2: /* original 430b, guest PC 0x0c0a91c2 */
if(!s->budget--) { s->failed_pc=0x0c0a91c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a91c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a91c6u) { target=s->pc; goto dispatch; }
goto P_0c0a91c6;
P_0c0a91c4: /* original 64e3, guest PC 0x0c0a91c4 */
if(!s->budget--) { s->failed_pc=0x0c0a91c4u; return 0; }
r[4]=r[14];
goto P_0c0a91c6;
P_0c0a91c6: /* original d235, guest PC 0x0c0a91c6 */
if(!s->budget--) { s->failed_pc=0x0c0a91c6u; return 0; }
r[2]=read(ram,0x0c0a929cu,4);
goto P_0c0a91c8;
P_0c0a91c8: /* original 420b, guest PC 0x0c0a91c8 */
if(!s->budget--) { s->failed_pc=0x0c0a91c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a91ccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a91ccu) { target=s->pc; goto dispatch; }
goto P_0c0a91cc;
P_0c0a91ca: /* original 64e3, guest PC 0x0c0a91ca */
if(!s->budget--) { s->failed_pc=0x0c0a91cau; return 0; }
r[4]=r[14];
goto P_0c0a91cc;
P_0c0a91cc: /* original 7f18, guest PC 0x0c0a91cc */
if(!s->budget--) { s->failed_pc=0x0c0a91ccu; return 0; }
r[15]+=0x00000018u;
goto P_0c0a91ce;
P_0c0a91ce: /* original 4f26, guest PC 0x0c0a91ce */
if(!s->budget--) { s->failed_pc=0x0c0a91ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a91d0;
P_0c0a91d0: /* original 6bf6, guest PC 0x0c0a91d0 */
if(!s->budget--) { s->failed_pc=0x0c0a91d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a91d2;
P_0c0a91d2: /* original 6cf6, guest PC 0x0c0a91d2 */
if(!s->budget--) { s->failed_pc=0x0c0a91d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a91d4;
P_0c0a91d4: /* original 6df6, guest PC 0x0c0a91d4 */
if(!s->budget--) { s->failed_pc=0x0c0a91d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a91d6;
P_0c0a91d6: /* original 000b, guest PC 0x0c0a91d6 */
if(!s->budget--) { s->failed_pc=0x0c0a91d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a91d8: /* original 6ef6, guest PC 0x0c0a91d8 */
if(!s->budget--) { s->failed_pc=0x0c0a91d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a91dau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a91dau; return 0; } return 1;
P_0c0c5d86: /* original 4f22, guest PC 0x0c0c5d86 */
if(!s->budget--) { s->failed_pc=0x0c0c5d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5d88;
P_0c0c5d88: /* original 7ff8, guest PC 0x0c0c5d88 */
if(!s->budget--) { s->failed_pc=0x0c0c5d88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5d8a;
P_0c0c5d8a: /* original 2f42, guest PC 0x0c0c5d8a */
if(!s->budget--) { s->failed_pc=0x0c0c5d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c5d8c;
P_0c0c5d8c: /* original d421, guest PC 0x0c0c5d8c */
if(!s->budget--) { s->failed_pc=0x0c0c5d8cu; return 0; }
r[4]=read(ram,0x0c0c5e14u,4);
goto P_0c0c5d8e;
P_0c0c5d8e: /* original d322, guest PC 0x0c0c5d8e */
if(!s->budget--) { s->failed_pc=0x0c0c5d8eu; return 0; }
r[3]=read(ram,0x0c0c5e18u,4);
goto P_0c0c5d90;
P_0c0c5d90: /* original 1f31, guest PC 0x0c0c5d90 */
if(!s->budget--) { s->failed_pc=0x0c0c5d90u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5d92;
P_0c0c5d92: /* original 8448, guest PC 0x0c0c5d92 */
if(!s->budget--) { s->failed_pc=0x0c0c5d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c5d94;
P_0c0c5d94: /* original 600c, guest PC 0x0c0c5d94 */
if(!s->budget--) { s->failed_pc=0x0c0c5d94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c5d96;
P_0c0c5d96: /* original 8803, guest PC 0x0c0c5d96 */
if(!s->budget--) { s->failed_pc=0x0c0c5d96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c5d98;
P_0c0c5d98: /* original 8f07, guest PC 0x0c0c5d98 */
if(!s->budget--) { s->failed_pc=0x0c0c5d98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c5daa; }
goto P_0c0c5d9c;
P_0c0c5d9a: /* original 6403, guest PC 0x0c0c5d9a */
if(!s->budget--) { s->failed_pc=0x0c0c5d9au; return 0; }
r[4]=r[0];
goto P_0c0c5d9c;
P_0c0c5d9c: /* original d31f, guest PC 0x0c0c5d9c */
if(!s->budget--) { s->failed_pc=0x0c0c5d9cu; return 0; }
r[3]=read(ram,0x0c0c5e1cu,4);
goto P_0c0c5d9e;
P_0c0c5d9e: /* original 54f1, guest PC 0x0c0c5d9e */
if(!s->budget--) { s->failed_pc=0x0c0c5d9eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5da0;
P_0c0c5da0: /* original 430b, guest PC 0x0c0c5da0 */
if(!s->budget--) { s->failed_pc=0x0c0c5da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5da4u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5da4u) { target=s->pc; goto dispatch; }
goto P_0c0c5da4;
P_0c0c5da2: /* original 7403, guest PC 0x0c0c5da2 */
if(!s->budget--) { s->failed_pc=0x0c0c5da2u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c5da4;
P_0c0c5da4: /* original 640c, guest PC 0x0c0c5da4 */
if(!s->budget--) { s->failed_pc=0x0c0c5da4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c5da6;
P_0c0c5da6: /* original 2448, guest PC 0x0c0c5da6 */
if(!s->budget--) { s->failed_pc=0x0c0c5da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c5da8;
P_0c0c5da8: /* original 8b03, guest PC 0x0c0c5da8 */
if(!s->budget--) { s->failed_pc=0x0c0c5da8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5db2; }
goto P_0c0c5daa;
P_0c0c5daa: /* original 64f2, guest PC 0x0c0c5daa */
if(!s->budget--) { s->failed_pc=0x0c0c5daau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c5dac;
P_0c0c5dac: /* original 7f08, guest PC 0x0c0c5dac */
if(!s->budget--) { s->failed_pc=0x0c0c5dacu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5dae;
P_0c0c5dae: /* original a004, guest PC 0x0c0c5dae */
if(!s->budget--) { s->failed_pc=0x0c0c5daeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0c5dbau,s,ram);
P_0c0c5db0: /* original 4f26, guest PC 0x0c0c5db0 */
if(!s->budget--) { s->failed_pc=0x0c0c5db0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db2;
P_0c0c5db2: /* original 7f08, guest PC 0x0c0c5db2 */
if(!s->budget--) { s->failed_pc=0x0c0c5db2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5db4;
P_0c0c5db4: /* original 4f26, guest PC 0x0c0c5db4 */
if(!s->budget--) { s->failed_pc=0x0c0c5db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db6;
P_0c0c5db6: /* original 000b, guest PC 0x0c0c5db6 */
if(!s->budget--) { s->failed_pc=0x0c0c5db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c5db8: /* original 0009, guest PC 0x0c0c5db8 */
if(!s->budget--) { s->failed_pc=0x0c0c5db8u; return 0; }
return vf3_matrix_family(0x0c0c5dbau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
