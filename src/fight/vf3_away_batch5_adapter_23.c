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
int vf3_away_batch5_adapter_23(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04fffcu: goto P_0c04fffc;
case 0x0c04fffeu: goto P_0c04fffe;
case 0x0c050000u: goto P_0c050000;
case 0x0c050002u: goto P_0c050002;
case 0x0c050004u: goto P_0c050004;
case 0x0c050006u: goto P_0c050006;
case 0x0c050008u: goto P_0c050008;
case 0x0c05000au: goto P_0c05000a;
case 0x0c05000cu: goto P_0c05000c;
case 0x0c05000eu: goto P_0c05000e;
case 0x0c050010u: goto P_0c050010;
case 0x0c050012u: goto P_0c050012;
case 0x0c050014u: goto P_0c050014;
case 0x0c050016u: goto P_0c050016;
case 0x0c050018u: goto P_0c050018;
case 0x0c05001au: goto P_0c05001a;
case 0x0c05001cu: goto P_0c05001c;
case 0x0c05001eu: goto P_0c05001e;
case 0x0c050020u: goto P_0c050020;
case 0x0c050022u: goto P_0c050022;
case 0x0c050024u: goto P_0c050024;
case 0x0c050026u: goto P_0c050026;
case 0x0c050028u: goto P_0c050028;
case 0x0c05002au: goto P_0c05002a;
case 0x0c05002cu: goto P_0c05002c;
case 0x0c05002eu: goto P_0c05002e;
case 0x0c050030u: goto P_0c050030;
case 0x0c050032u: goto P_0c050032;
case 0x0c050034u: goto P_0c050034;
case 0x0c050036u: goto P_0c050036;
case 0x0c050038u: goto P_0c050038;
case 0x0c05003au: goto P_0c05003a;
case 0x0c05003cu: goto P_0c05003c;
case 0x0c05003eu: goto P_0c05003e;
case 0x0c050040u: goto P_0c050040;
case 0x0c050042u: goto P_0c050042;
case 0x0c050044u: goto P_0c050044;
case 0x0c050046u: goto P_0c050046;
case 0x0c050048u: goto P_0c050048;
case 0x0c05004au: goto P_0c05004a;
case 0x0c05004cu: goto P_0c05004c;
case 0x0c05004eu: goto P_0c05004e;
case 0x0c050050u: goto P_0c050050;
case 0x0c050052u: goto P_0c050052;
case 0x0c050054u: goto P_0c050054;
case 0x0c050056u: goto P_0c050056;
case 0x0c050058u: goto P_0c050058;
case 0x0c05005au: goto P_0c05005a;
case 0x0c05005cu: goto P_0c05005c;
case 0x0c05005eu: goto P_0c05005e;
case 0x0c050060u: goto P_0c050060;
case 0x0c050062u: goto P_0c050062;
case 0x0c050064u: goto P_0c050064;
case 0x0c050066u: goto P_0c050066;
case 0x0c050068u: goto P_0c050068;
case 0x0c05006au: goto P_0c05006a;
case 0x0c05006cu: goto P_0c05006c;
case 0x0c05006eu: goto P_0c05006e;
case 0x0c050070u: goto P_0c050070;
case 0x0c050072u: goto P_0c050072;
case 0x0c050074u: goto P_0c050074;
case 0x0c050076u: goto P_0c050076;
case 0x0c050078u: goto P_0c050078;
case 0x0c05007au: goto P_0c05007a;
case 0x0c05007cu: goto P_0c05007c;
case 0x0c05007eu: goto P_0c05007e;
case 0x0c050080u: goto P_0c050080;
case 0x0c050082u: goto P_0c050082;
case 0x0c050084u: goto P_0c050084;
case 0x0c050086u: goto P_0c050086;
case 0x0c050088u: goto P_0c050088;
case 0x0c05008au: goto P_0c05008a;
case 0x0c05008cu: goto P_0c05008c;
case 0x0c05008eu: goto P_0c05008e;
case 0x0c050090u: goto P_0c050090;
case 0x0c050092u: goto P_0c050092;
case 0x0c050094u: goto P_0c050094;
case 0x0c050096u: goto P_0c050096;
case 0x0c050098u: goto P_0c050098;
case 0x0c05009au: goto P_0c05009a;
case 0x0c05009cu: goto P_0c05009c;
case 0x0c05009eu: goto P_0c05009e;
case 0x0c0500a0u: goto P_0c0500a0;
case 0x0c0500a2u: goto P_0c0500a2;
case 0x0c0500a4u: goto P_0c0500a4;
case 0x0c0500a6u: goto P_0c0500a6;
case 0x0c0500a8u: goto P_0c0500a8;
case 0x0c0500aau: goto P_0c0500aa;
case 0x0c0500acu: goto P_0c0500ac;
case 0x0c0500aeu: goto P_0c0500ae;
case 0x0c0500b0u: goto P_0c0500b0;
case 0x0c0500b2u: goto P_0c0500b2;
case 0x0c0500b4u: goto P_0c0500b4;
case 0x0c0500b6u: goto P_0c0500b6;
case 0x0c0500b8u: goto P_0c0500b8;
case 0x0c0500bau: goto P_0c0500ba;
case 0x0c0500bcu: goto P_0c0500bc;
case 0x0c0500beu: goto P_0c0500be;
case 0x0c0500f0u: goto P_0c0500f0;
case 0x0c0500f2u: goto P_0c0500f2;
case 0x0c0500f4u: goto P_0c0500f4;
case 0x0c0500f6u: goto P_0c0500f6;
case 0x0c0500f8u: goto P_0c0500f8;
case 0x0c0500fau: goto P_0c0500fa;
case 0x0c0500fcu: goto P_0c0500fc;
case 0x0c0500feu: goto P_0c0500fe;
case 0x0c050100u: goto P_0c050100;
case 0x0c050102u: goto P_0c050102;
case 0x0c050104u: goto P_0c050104;
case 0x0c050106u: goto P_0c050106;
case 0x0c050108u: goto P_0c050108;
case 0x0c05010au: goto P_0c05010a;
case 0x0c05010cu: goto P_0c05010c;
case 0x0c05010eu: goto P_0c05010e;
case 0x0c050110u: goto P_0c050110;
case 0x0c050112u: goto P_0c050112;
case 0x0c050114u: goto P_0c050114;
case 0x0c050116u: goto P_0c050116;
case 0x0c050118u: goto P_0c050118;
case 0x0c05011au: goto P_0c05011a;
case 0x0c05011cu: goto P_0c05011c;
case 0x0c05011eu: goto P_0c05011e;
case 0x0c050120u: goto P_0c050120;
case 0x0c050122u: goto P_0c050122;
case 0x0c050124u: goto P_0c050124;
case 0x0c050126u: goto P_0c050126;
case 0x0c050128u: goto P_0c050128;
case 0x0c05012au: goto P_0c05012a;
case 0x0c05012cu: goto P_0c05012c;
case 0x0c05012eu: goto P_0c05012e;
case 0x0c050130u: goto P_0c050130;
case 0x0c050132u: goto P_0c050132;
case 0x0c050134u: goto P_0c050134;
case 0x0c050136u: goto P_0c050136;
case 0x0c050138u: goto P_0c050138;
case 0x0c05013au: goto P_0c05013a;
case 0x0c05013cu: goto P_0c05013c;
case 0x0c05013eu: goto P_0c05013e;
case 0x0c050140u: goto P_0c050140;
case 0x0c050142u: goto P_0c050142;
case 0x0c050144u: goto P_0c050144;
case 0x0c050146u: goto P_0c050146;
case 0x0c050148u: goto P_0c050148;
case 0x0c05014au: goto P_0c05014a;
case 0x0c050164u: goto P_0c050164;
case 0x0c050166u: goto P_0c050166;
case 0x0c050168u: goto P_0c050168;
case 0x0c05016au: goto P_0c05016a;
case 0x0c05016cu: goto P_0c05016c;
case 0x0c05016eu: goto P_0c05016e;
case 0x0c050170u: goto P_0c050170;
case 0x0c050172u: goto P_0c050172;
case 0x0c050174u: goto P_0c050174;
case 0x0c050176u: goto P_0c050176;
case 0x0c050178u: goto P_0c050178;
case 0x0c05017au: goto P_0c05017a;
case 0x0c05017cu: goto P_0c05017c;
case 0x0c05017eu: goto P_0c05017e;
case 0x0c050180u: goto P_0c050180;
case 0x0c050182u: goto P_0c050182;
case 0x0c050184u: goto P_0c050184;
case 0x0c050186u: goto P_0c050186;
case 0x0c050188u: goto P_0c050188;
case 0x0c05018au: goto P_0c05018a;
case 0x0c05018cu: goto P_0c05018c;
case 0x0c05018eu: goto P_0c05018e;
case 0x0c050190u: goto P_0c050190;
case 0x0c050192u: goto P_0c050192;
case 0x0c050194u: goto P_0c050194;
case 0x0c050196u: goto P_0c050196;
case 0x0c050198u: goto P_0c050198;
case 0x0c05019au: goto P_0c05019a;
case 0x0c05019cu: goto P_0c05019c;
case 0x0c05019eu: goto P_0c05019e;
case 0x0c0501a0u: goto P_0c0501a0;
case 0x0c0501a2u: goto P_0c0501a2;
case 0x0c0501a4u: goto P_0c0501a4;
case 0x0c0501a6u: goto P_0c0501a6;
case 0x0c0501a8u: goto P_0c0501a8;
case 0x0c0501aau: goto P_0c0501aa;
case 0x0c0501acu: goto P_0c0501ac;
case 0x0c0501aeu: goto P_0c0501ae;
case 0x0c0501b0u: goto P_0c0501b0;
case 0x0c0501b2u: goto P_0c0501b2;
case 0x0c0501b4u: goto P_0c0501b4;
case 0x0c0501b6u: goto P_0c0501b6;
case 0x0c0501b8u: goto P_0c0501b8;
case 0x0c0501bau: goto P_0c0501ba;
case 0x0c0501bcu: goto P_0c0501bc;
case 0x0c0501beu: goto P_0c0501be;
case 0x0c0501c0u: goto P_0c0501c0;
case 0x0c0501c2u: goto P_0c0501c2;
case 0x0c0501c4u: goto P_0c0501c4;
case 0x0c0501c6u: goto P_0c0501c6;
case 0x0c0501c8u: goto P_0c0501c8;
case 0x0c0501cau: goto P_0c0501ca;
case 0x0c0501ccu: goto P_0c0501cc;
case 0x0c0501ceu: goto P_0c0501ce;
case 0x0c0501d0u: goto P_0c0501d0;
case 0x0c0501d2u: goto P_0c0501d2;
case 0x0c0501d4u: goto P_0c0501d4;
case 0x0c0501d6u: goto P_0c0501d6;
case 0x0c0501d8u: goto P_0c0501d8;
case 0x0c0501dau: goto P_0c0501da;
case 0x0c0501dcu: goto P_0c0501dc;
case 0x0c0501deu: goto P_0c0501de;
case 0x0c0501e0u: goto P_0c0501e0;
case 0x0c0501e2u: goto P_0c0501e2;
case 0x0c0501e4u: goto P_0c0501e4;
case 0x0c0501e6u: goto P_0c0501e6;
case 0x0c0501e8u: goto P_0c0501e8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04fffc: /* original 2fe6, guest PC 0x0c04fffc */
if(!s->budget--) { s->failed_pc=0x0c04fffcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fffe;
P_0c04fffe: /* original 6253, guest PC 0x0c04fffe */
if(!s->budget--) { s->failed_pc=0x0c04fffeu; return 0; }
r[2]=r[5];
goto P_0c050000;
P_0c050000: /* original 2fd6, guest PC 0x0c050000 */
if(!s->budget--) { s->failed_pc=0x0c050000u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050002;
P_0c050002: /* original 6d43, guest PC 0x0c050002 */
if(!s->budget--) { s->failed_pc=0x0c050002u; return 0; }
r[13]=r[4];
goto P_0c050004;
P_0c050004: /* original 2fc6, guest PC 0x0c050004 */
if(!s->budget--) { s->failed_pc=0x0c050004u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050006;
P_0c050006: /* original 2fb6, guest PC 0x0c050006 */
if(!s->budget--) { s->failed_pc=0x0c050006u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050008;
P_0c050008: /* original 4f22, guest PC 0x0c050008 */
if(!s->budget--) { s->failed_pc=0x0c050008u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05000a;
P_0c05000a: /* original 4f12, guest PC 0x0c05000a */
if(!s->budget--) { s->failed_pc=0x0c05000au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c05000c;
P_0c05000c: /* original 7fd0, guest PC 0x0c05000c */
if(!s->budget--) { s->failed_pc=0x0c05000cu; return 0; }
r[15]+=0xffffffd0u;
goto P_0c05000e;
P_0c05000e: /* original 2f52, guest PC 0x0c05000e */
if(!s->budget--) { s->failed_pc=0x0c05000eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c050010;
P_0c050010: /* original 9b56, guest PC 0x0c050010 */
if(!s->budget--) { s->failed_pc=0x0c050010u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0500c0u,2);
goto P_0c050012;
P_0c050012: /* original d32c, guest PC 0x0c050012 */
if(!s->budget--) { s->failed_pc=0x0c050012u; return 0; }
r[3]=read(ram,0x0c0500c4u,4);
goto P_0c050014;
P_0c050014: /* original 2dbf, guest PC 0x0c050014 */
if(!s->budget--) { s->failed_pc=0x0c050014u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[11]);
goto P_0c050016;
P_0c050016: /* original 2f56, guest PC 0x0c050016 */
if(!s->budget--) { s->failed_pc=0x0c050016u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050018;
P_0c050018: /* original 2fd6, guest PC 0x0c050018 */
if(!s->budget--) { s->failed_pc=0x0c050018u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05001a;
P_0c05001a: /* original d22b, guest PC 0x0c05001a */
if(!s->budget--) { s->failed_pc=0x0c05001au; return 0; }
r[2]=read(ram,0x0c0500c8u,4);
goto P_0c05001c;
P_0c05001c: /* original 0b1a, guest PC 0x0c05001c */
if(!s->budget--) { s->failed_pc=0x0c05001cu; return 0; }
r[11]=r[19];
goto P_0c05001e;
P_0c05001e: /* original d12b, guest PC 0x0c05001e */
if(!s->budget--) { s->failed_pc=0x0c05001eu; return 0; }
r[1]=read(ram,0x0c0500ccu,4);
goto P_0c050020;
P_0c050020: /* original 6bbf, guest PC 0x0c050020 */
if(!s->budget--) { s->failed_pc=0x0c050020u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c050022;
P_0c050022: /* original 3b3c, guest PC 0x0c050022 */
if(!s->budget--) { s->failed_pc=0x0c050022u; return 0; }
r[11]+=r[3];
goto P_0c050024;
P_0c050024: /* original 410b, guest PC 0x0c050024 */
if(!s->budget--) { s->failed_pc=0x0c050024u; return 0; }
target=r[1];
r[16]=code_base|0x0c050028u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050028u) { target=s->pc; goto dispatch; }
goto P_0c050028;
P_0c050026: /* original 2f26, guest PC 0x0c050026 */
if(!s->budget--) { s->failed_pc=0x0c050026u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050028;
P_0c050028: /* original 7f0c, guest PC 0x0c050028 */
if(!s->budget--) { s->failed_pc=0x0c050028u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05002a;
P_0c05002a: /* original 65f2, guest PC 0x0c05002a */
if(!s->budget--) { s->failed_pc=0x0c05002au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05002c;
P_0c05002c: /* original 66f3, guest PC 0x0c05002c */
if(!s->budget--) { s->failed_pc=0x0c05002cu; return 0; }
r[6]=r[15];
goto P_0c05002e;
P_0c05002e: /* original 7604, guest PC 0x0c05002e */
if(!s->budget--) { s->failed_pc=0x0c05002eu; return 0; }
r[6]+=0x00000004u;
goto P_0c050030;
P_0c050030: /* original bcad, guest PC 0x0c050030 */
if(!s->budget--) { s->failed_pc=0x0c050030u; return 0; }
target=code_base|0x0c04f98eu; r[16]=code_base|0x0c050034u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050034u) { target=s->pc; goto dispatch; }
goto P_0c050034;
P_0c050032: /* original 64d3, guest PC 0x0c050032 */
if(!s->budget--) { s->failed_pc=0x0c050032u; return 0; }
r[4]=r[13];
goto P_0c050034;
P_0c050034: /* original 6503, guest PC 0x0c050034 */
if(!s->budget--) { s->failed_pc=0x0c050034u; return 0; }
r[5]=r[0];
goto P_0c050036;
P_0c050036: /* original 4511, guest PC 0x0c050036 */
if(!s->budget--) { s->failed_pc=0x0c050036u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c050038;
P_0c050038: /* original 8902, guest PC 0x0c050038 */
if(!s->budget--) { s->failed_pc=0x0c050038u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050040; }
goto P_0c05003a;
P_0c05003a: /* original 9042, guest PC 0x0c05003a */
if(!s->budget--) { s->failed_pc=0x0c05003au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0500c2u,2);
goto P_0c05003c;
P_0c05003c: /* original a06c, guest PC 0x0c05003c */
if(!s->budget--) { s->failed_pc=0x0c05003cu; return 0; }
goto P_0c050118;
P_0c05003e: /* original 0009, guest PC 0x0c05003e */
if(!s->budget--) { s->failed_pc=0x0c05003eu; return 0; }
goto P_0c050040;
P_0c050040: /* original bf8f, guest PC 0x0c050040 */
if(!s->budget--) { s->failed_pc=0x0c050040u; return 0; }
target=code_base|0x0c04ff62u; r[16]=code_base|0x0c050044u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050044u) { target=s->pc; goto dispatch; }
goto P_0c050044;
P_0c050042: /* original 64d3, guest PC 0x0c050042 */
if(!s->budget--) { s->failed_pc=0x0c050042u; return 0; }
r[4]=r[13];
goto P_0c050044;
P_0c050044: /* original 53b7, guest PC 0x0c050044 */
if(!s->budget--) { s->failed_pc=0x0c050044u; return 0; }
r[3]=read(ram,r[11]+28,4);
goto P_0c050046;
P_0c050046: /* original 5ef4, guest PC 0x0c050046 */
if(!s->budget--) { s->failed_pc=0x0c050046u; return 0; }
r[14]=read(ram,r[15]+16,4);
goto P_0c050048;
P_0c050048: /* original 523c, guest PC 0x0c050048 */
if(!s->budget--) { s->failed_pc=0x0c050048u; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c05004a;
P_0c05004a: /* original 3e23, guest PC 0x0c05004a */
if(!s->budget--) { s->failed_pc=0x0c05004au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c05004c;
P_0c05004c: /* original 890c, guest PC 0x0c05004c */
if(!s->budget--) { s->failed_pc=0x0c05004cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050068; }
goto P_0c05004e;
P_0c05004e: /* original a05f, guest PC 0x0c05004e */
if(!s->budget--) { s->failed_pc=0x0c05004eu; return 0; }
r[12]=0x00000000u;
goto P_0c050110;
P_0c050050: /* original ec00, guest PC 0x0c050050 */
if(!s->budget--) { s->failed_pc=0x0c050050u; return 0; }
r[12]=0x00000000u;
goto P_0c050052;
P_0c050052: /* original 65e3, guest PC 0x0c050052 */
if(!s->budget--) { s->failed_pc=0x0c050052u; return 0; }
r[5]=r[14];
goto P_0c050054;
P_0c050054: /* original bf23, guest PC 0x0c050054 */
if(!s->budget--) { s->failed_pc=0x0c050054u; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c050058u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050058u) { target=s->pc; goto dispatch; }
goto P_0c050058;
P_0c050056: /* original 64d3, guest PC 0x0c050056 */
if(!s->budget--) { s->failed_pc=0x0c050056u; return 0; }
r[4]=r[13];
goto P_0c050058;
P_0c050058: /* original 52fb, guest PC 0x0c050058 */
if(!s->budget--) { s->failed_pc=0x0c050058u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c05005a;
P_0c05005a: /* original 640d, guest PC 0x0c05005a */
if(!s->budget--) { s->failed_pc=0x0c05005au; return 0; }
r[4]=r[0]&65535u;
goto P_0c05005c;
P_0c05005c: /* original d51c, guest PC 0x0c05005c */
if(!s->budget--) { s->failed_pc=0x0c05005cu; return 0; }
r[5]=read(ram,0x0c0500d0u,4);
goto P_0c05005e;
P_0c05005e: /* original 72ff, guest PC 0x0c05005e */
if(!s->budget--) { s->failed_pc=0x0c05005eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c050060;
P_0c050060: /* original 3c20, guest PC 0x0c050060 */
if(!s->budget--) { s->failed_pc=0x0c050060u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[2])!=0);
goto P_0c050062;
P_0c050062: /* original 8b08, guest PC 0x0c050062 */
if(!s->budget--) { s->failed_pc=0x0c050062u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050076; }
goto P_0c050064;
P_0c050064: /* original 3450, guest PC 0x0c050064 */
if(!s->budget--) { s->failed_pc=0x0c050064u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c050066;
P_0c050066: /* original 8951, guest PC 0x0c050066 */
if(!s->budget--) { s->failed_pc=0x0c050066u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05010c; }
goto P_0c050068;
P_0c050068: /* original dd1a, guest PC 0x0c050068 */
if(!s->budget--) { s->failed_pc=0x0c050068u; return 0; }
r[13]=read(ram,0x0c0500d4u,4);
goto P_0c05006a;
P_0c05006a: /* original 2fe6, guest PC 0x0c05006a */
if(!s->budget--) { s->failed_pc=0x0c05006au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05006c;
P_0c05006c: /* original d317, guest PC 0x0c05006c */
if(!s->budget--) { s->failed_pc=0x0c05006cu; return 0; }
r[3]=read(ram,0x0c0500ccu,4);
goto P_0c05006e;
P_0c05006e: /* original 430b, guest PC 0x0c05006e */
if(!s->budget--) { s->failed_pc=0x0c05006eu; return 0; }
target=r[3];
r[16]=code_base|0x0c050072u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050072u) { target=s->pc; goto dispatch; }
goto P_0c050072;
P_0c050070: /* original 2fd6, guest PC 0x0c050070 */
if(!s->budget--) { s->failed_pc=0x0c050070u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050072;
P_0c050072: /* original a048, guest PC 0x0c050072 */
if(!s->budget--) { s->failed_pc=0x0c050072u; return 0; }
r[15]+=0x00000008u;
goto P_0c050106;
P_0c050074: /* original 7f08, guest PC 0x0c050074 */
if(!s->budget--) { s->failed_pc=0x0c050074u; return 0; }
r[15]+=0x00000008u;
goto P_0c050076;
P_0c050076: /* original 34e0, guest PC 0x0c050076 */
if(!s->budget--) { s->failed_pc=0x0c050076u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[14])!=0);
goto P_0c050078;
P_0c050078: /* original 8b07, guest PC 0x0c050078 */
if(!s->budget--) { s->failed_pc=0x0c050078u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05008a; }
goto P_0c05007a;
P_0c05007a: /* original dd17, guest PC 0x0c05007a */
if(!s->budget--) { s->failed_pc=0x0c05007au; return 0; }
r[13]=read(ram,0x0c0500d8u,4);
goto P_0c05007c;
P_0c05007c: /* original 2fe6, guest PC 0x0c05007c */
if(!s->budget--) { s->failed_pc=0x0c05007cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05007e;
P_0c05007e: /* original 2f46, guest PC 0x0c05007e */
if(!s->budget--) { s->failed_pc=0x0c05007eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050080;
P_0c050080: /* original d312, guest PC 0x0c050080 */
if(!s->budget--) { s->failed_pc=0x0c050080u; return 0; }
r[3]=read(ram,0x0c0500ccu,4);
goto P_0c050082;
P_0c050082: /* original 430b, guest PC 0x0c050082 */
if(!s->budget--) { s->failed_pc=0x0c050082u; return 0; }
target=r[3];
r[16]=code_base|0x0c050086u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050086u) { target=s->pc; goto dispatch; }
goto P_0c050086;
P_0c050084: /* original 2fd6, guest PC 0x0c050084 */
if(!s->budget--) { s->failed_pc=0x0c050084u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050086;
P_0c050086: /* original a03e, guest PC 0x0c050086 */
if(!s->budget--) { s->failed_pc=0x0c050086u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c050088: /* original 7f0c, guest PC 0x0c050088 */
if(!s->budget--) { s->failed_pc=0x0c050088u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05008a;
P_0c05008a: /* original 3450, guest PC 0x0c05008a */
if(!s->budget--) { s->failed_pc=0x0c05008au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c05008c;
P_0c05008c: /* original 8b02, guest PC 0x0c05008c */
if(!s->budget--) { s->failed_pc=0x0c05008cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050094; }
goto P_0c05008e;
P_0c05008e: /* original dd13, guest PC 0x0c05008e */
if(!s->budget--) { s->failed_pc=0x0c05008eu; return 0; }
r[13]=read(ram,0x0c0500dcu,4);
goto P_0c050090;
P_0c050090: /* original aff4, guest PC 0x0c050090 */
if(!s->budget--) { s->failed_pc=0x0c050090u; return 0; }
goto P_0c05007c;
P_0c050092: /* original 0009, guest PC 0x0c050092 */
if(!s->budget--) { s->failed_pc=0x0c050092u; return 0; }
goto P_0c050094;
P_0c050094: /* original d512, guest PC 0x0c050094 */
if(!s->budget--) { s->failed_pc=0x0c050094u; return 0; }
r[5]=read(ram,0x0c0500e0u,4);
goto P_0c050096;
P_0c050096: /* original 3450, guest PC 0x0c050096 */
if(!s->budget--) { s->failed_pc=0x0c050096u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c050098;
P_0c050098: /* original 8b07, guest PC 0x0c050098 */
if(!s->budget--) { s->failed_pc=0x0c050098u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0500aa; }
goto P_0c05009a;
P_0c05009a: /* original dd12, guest PC 0x0c05009a */
if(!s->budget--) { s->failed_pc=0x0c05009au; return 0; }
r[13]=read(ram,0x0c0500e4u,4);
goto P_0c05009c;
P_0c05009c: /* original 2fe6, guest PC 0x0c05009c */
if(!s->budget--) { s->failed_pc=0x0c05009cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05009e;
P_0c05009e: /* original 2f46, guest PC 0x0c05009e */
if(!s->budget--) { s->failed_pc=0x0c05009eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500a0;
P_0c0500a0: /* original d20a, guest PC 0x0c0500a0 */
if(!s->budget--) { s->failed_pc=0x0c0500a0u; return 0; }
r[2]=read(ram,0x0c0500ccu,4);
goto P_0c0500a2;
P_0c0500a2: /* original 420b, guest PC 0x0c0500a2 */
if(!s->budget--) { s->failed_pc=0x0c0500a2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0500a6u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0500a6u) { target=s->pc; goto dispatch; }
goto P_0c0500a6;
P_0c0500a4: /* original 2fd6, guest PC 0x0c0500a4 */
if(!s->budget--) { s->failed_pc=0x0c0500a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500a6;
P_0c0500a6: /* original a02e, guest PC 0x0c0500a6 */
if(!s->budget--) { s->failed_pc=0x0c0500a6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c0500a8: /* original 7f0c, guest PC 0x0c0500a8 */
if(!s->budget--) { s->failed_pc=0x0c0500a8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0500aa;
P_0c0500aa: /* original d50f, guest PC 0x0c0500aa */
if(!s->budget--) { s->failed_pc=0x0c0500aau; return 0; }
r[5]=read(ram,0x0c0500e8u,4);
goto P_0c0500ac;
P_0c0500ac: /* original 3450, guest PC 0x0c0500ac */
if(!s->budget--) { s->failed_pc=0x0c0500acu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0500ae;
P_0c0500ae: /* original 8b1f, guest PC 0x0c0500ae */
if(!s->budget--) { s->failed_pc=0x0c0500aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0500f0; }
goto P_0c0500b0;
P_0c0500b0: /* original dd0e, guest PC 0x0c0500b0 */
if(!s->budget--) { s->failed_pc=0x0c0500b0u; return 0; }
r[13]=read(ram,0x0c0500ecu,4);
goto P_0c0500b2;
P_0c0500b2: /* original 2fe6, guest PC 0x0c0500b2 */
if(!s->budget--) { s->failed_pc=0x0c0500b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500b4;
P_0c0500b4: /* original 2f46, guest PC 0x0c0500b4 */
if(!s->budget--) { s->failed_pc=0x0c0500b4u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500b6;
P_0c0500b6: /* original d205, guest PC 0x0c0500b6 */
if(!s->budget--) { s->failed_pc=0x0c0500b6u; return 0; }
r[2]=read(ram,0x0c0500ccu,4);
goto P_0c0500b8;
P_0c0500b8: /* original 420b, guest PC 0x0c0500b8 */
if(!s->budget--) { s->failed_pc=0x0c0500b8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0500bcu;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0500bcu) { target=s->pc; goto dispatch; }
goto P_0c0500bc;
P_0c0500ba: /* original 2fd6, guest PC 0x0c0500ba */
if(!s->budget--) { s->failed_pc=0x0c0500bau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500bc;
P_0c0500bc: /* original a023, guest PC 0x0c0500bc */
if(!s->budget--) { s->failed_pc=0x0c0500bcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c0500be: /* original 7f0c, guest PC 0x0c0500be */
if(!s->budget--) { s->failed_pc=0x0c0500beu; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c0500c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0500c0u; return 0; } return 1;
P_0c0500f0: /* original 52b7, guest PC 0x0c0500f0 */
if(!s->budget--) { s->failed_pc=0x0c0500f0u; return 0; }
r[2]=read(ram,r[11]+28,4);
goto P_0c0500f2;
P_0c0500f2: /* original 532c, guest PC 0x0c0500f2 */
if(!s->budget--) { s->failed_pc=0x0c0500f2u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c0500f4;
P_0c0500f4: /* original 3433, guest PC 0x0c0500f4 */
if(!s->budget--) { s->failed_pc=0x0c0500f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0500f6;
P_0c0500f6: /* original 8b09, guest PC 0x0c0500f6 */
if(!s->budget--) { s->failed_pc=0x0c0500f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05010c; }
goto P_0c0500f8;
P_0c0500f8: /* original dd56, guest PC 0x0c0500f8 */
if(!s->budget--) { s->failed_pc=0x0c0500f8u; return 0; }
r[13]=read(ram,0x0c050254u,4);
goto P_0c0500fa;
P_0c0500fa: /* original 2fe6, guest PC 0x0c0500fa */
if(!s->budget--) { s->failed_pc=0x0c0500fau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500fc;
P_0c0500fc: /* original 2f46, guest PC 0x0c0500fc */
if(!s->budget--) { s->failed_pc=0x0c0500fcu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500fe;
P_0c0500fe: /* original d356, guest PC 0x0c0500fe */
if(!s->budget--) { s->failed_pc=0x0c0500feu; return 0; }
r[3]=read(ram,0x0c050258u,4);
goto P_0c050100;
P_0c050100: /* original 430b, guest PC 0x0c050100 */
if(!s->budget--) { s->failed_pc=0x0c050100u; return 0; }
target=r[3];
r[16]=code_base|0x0c050104u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050104u) { target=s->pc; goto dispatch; }
goto P_0c050104;
P_0c050102: /* original 2fd6, guest PC 0x0c050102 */
if(!s->budget--) { s->failed_pc=0x0c050102u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050104;
P_0c050104: /* original 7f0c, guest PC 0x0c050104 */
if(!s->budget--) { s->failed_pc=0x0c050104u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c050106: /* original 90a3, guest PC 0x0c050106 */
if(!s->budget--) { s->failed_pc=0x0c050106u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050250u,2);
goto P_0c050108;
P_0c050108: /* original a006, guest PC 0x0c050108 */
if(!s->budget--) { s->failed_pc=0x0c050108u; return 0; }
goto P_0c050118;
P_0c05010a: /* original 0009, guest PC 0x0c05010a */
if(!s->budget--) { s->failed_pc=0x0c05010au; return 0; }
goto P_0c05010c;
P_0c05010c: /* original 7c01, guest PC 0x0c05010c */
if(!s->budget--) { s->failed_pc=0x0c05010cu; return 0; }
r[12]+=0x00000001u;
goto P_0c05010e;
P_0c05010e: /* original 6e43, guest PC 0x0c05010e */
if(!s->budget--) { s->failed_pc=0x0c05010eu; return 0; }
r[14]=r[4];
goto P_0c050110;
P_0c050110: /* original 52fb, guest PC 0x0c050110 */
if(!s->budget--) { s->failed_pc=0x0c050110u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c050112;
P_0c050112: /* original 3c23, guest PC 0x0c050112 */
if(!s->budget--) { s->failed_pc=0x0c050112u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[2])!=0);
goto P_0c050114;
P_0c050114: /* original 8b9d, guest PC 0x0c050114 */
if(!s->budget--) { s->failed_pc=0x0c050114u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050052; }
goto P_0c050116;
P_0c050116: /* original e000, guest PC 0x0c050116 */
if(!s->budget--) { s->failed_pc=0x0c050116u; return 0; }
r[0]=0x00000000u;
goto P_0c050118;
P_0c050118: /* original 7f30, guest PC 0x0c050118 */
if(!s->budget--) { s->failed_pc=0x0c050118u; return 0; }
r[15]+=0x00000030u;
goto P_0c05011a;
P_0c05011a: /* original 4f16, guest PC 0x0c05011a */
if(!s->budget--) { s->failed_pc=0x0c05011au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c05011c;
P_0c05011c: /* original 4f26, guest PC 0x0c05011c */
if(!s->budget--) { s->failed_pc=0x0c05011cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05011e;
P_0c05011e: /* original 6bf6, guest PC 0x0c05011e */
if(!s->budget--) { s->failed_pc=0x0c05011eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c050120;
P_0c050120: /* original 6cf6, guest PC 0x0c050120 */
if(!s->budget--) { s->failed_pc=0x0c050120u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c050122;
P_0c050122: /* original 6df6, guest PC 0x0c050122 */
if(!s->budget--) { s->failed_pc=0x0c050122u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050124;
P_0c050124: /* original 000b, guest PC 0x0c050124 */
if(!s->budget--) { s->failed_pc=0x0c050124u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050126: /* original 6ef6, guest PC 0x0c050126 */
if(!s->budget--) { s->failed_pc=0x0c050126u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c050128;
P_0c050128: /* original 4f22, guest PC 0x0c050128 */
if(!s->budget--) { s->failed_pc=0x0c050128u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05012a;
P_0c05012a: /* original d34c, guest PC 0x0c05012a */
if(!s->budget--) { s->failed_pc=0x0c05012au; return 0; }
r[3]=read(ram,0x0c05025cu,4);
goto P_0c05012c;
P_0c05012c: /* original 6143, guest PC 0x0c05012c */
if(!s->budget--) { s->failed_pc=0x0c05012cu; return 0; }
r[1]=r[4];
goto P_0c05012e;
P_0c05012e: /* original e60a, guest PC 0x0c05012e */
if(!s->budget--) { s->failed_pc=0x0c05012eu; return 0; }
r[6]=0x0000000au;
goto P_0c050130;
P_0c050130: /* original 430b, guest PC 0x0c050130 */
if(!s->budget--) { s->failed_pc=0x0c050130u; return 0; }
target=r[3];
r[16]=code_base|0x0c050134u;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050134u) { target=s->pc; goto dispatch; }
goto P_0c050134;
P_0c050132: /* original 6063, guest PC 0x0c050132 */
if(!s->budget--) { s->failed_pc=0x0c050132u; return 0; }
r[0]=r[6];
goto P_0c050134;
P_0c050134: /* original d24a, guest PC 0x0c050134 */
if(!s->budget--) { s->failed_pc=0x0c050134u; return 0; }
r[2]=read(ram,0x0c050260u,4);
goto P_0c050136;
P_0c050136: /* original 6143, guest PC 0x0c050136 */
if(!s->budget--) { s->failed_pc=0x0c050136u; return 0; }
r[1]=r[4];
goto P_0c050138;
P_0c050138: /* original 6503, guest PC 0x0c050138 */
if(!s->budget--) { s->failed_pc=0x0c050138u; return 0; }
r[5]=r[0];
goto P_0c05013a;
P_0c05013a: /* original 420b, guest PC 0x0c05013a */
if(!s->budget--) { s->failed_pc=0x0c05013au; return 0; }
target=r[2];
r[16]=code_base|0x0c05013eu;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05013eu) { target=s->pc; goto dispatch; }
goto P_0c05013e;
P_0c05013c: /* original 6063, guest PC 0x0c05013c */
if(!s->budget--) { s->failed_pc=0x0c05013cu; return 0; }
r[0]=r[6];
goto P_0c05013e;
P_0c05013e: /* original 6403, guest PC 0x0c05013e */
if(!s->budget--) { s->failed_pc=0x0c05013eu; return 0; }
r[4]=r[0];
goto P_0c050140;
P_0c050140: /* original 6053, guest PC 0x0c050140 */
if(!s->budget--) { s->failed_pc=0x0c050140u; return 0; }
r[0]=r[5];
goto P_0c050142;
P_0c050142: /* original 4f26, guest PC 0x0c050142 */
if(!s->budget--) { s->failed_pc=0x0c050142u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c050144;
P_0c050144: /* original 4008, guest PC 0x0c050144 */
if(!s->budget--) { s->failed_pc=0x0c050144u; return 0; }
r[0]<<=2;
goto P_0c050146;
P_0c050146: /* original 4008, guest PC 0x0c050146 */
if(!s->budget--) { s->failed_pc=0x0c050146u; return 0; }
r[0]<<=2;
goto P_0c050148;
P_0c050148: /* original 000b, guest PC 0x0c050148 */
if(!s->budget--) { s->failed_pc=0x0c050148u; return 0; }
target=r[16];
r[0]+=r[4];
s->pc=target; return ram->oob==0;
P_0c05014a: /* original 304c, guest PC 0x0c05014a */
if(!s->budget--) { s->failed_pc=0x0c05014au; return 0; }
r[0]+=r[4];
if(!vf3_matrix_family(0x0c05014cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05014cu; return 0; } return 1;
P_0c050164: /* original 2fe6, guest PC 0x0c050164 */
if(!s->budget--) { s->failed_pc=0x0c050164u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050166;
P_0c050166: /* original e064, guest PC 0x0c050166 */
if(!s->budget--) { s->failed_pc=0x0c050166u; return 0; }
r[0]=0x00000064u;
goto P_0c050168;
P_0c050168: /* original 2fd6, guest PC 0x0c050168 */
if(!s->budget--) { s->failed_pc=0x0c050168u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05016a;
P_0c05016a: /* original 6d53, guest PC 0x0c05016a */
if(!s->budget--) { s->failed_pc=0x0c05016au; return 0; }
r[13]=r[5];
goto P_0c05016c;
P_0c05016c: /* original 2f86, guest PC 0x0c05016c */
if(!s->budget--) { s->failed_pc=0x0c05016cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05016e;
P_0c05016e: /* original 6e43, guest PC 0x0c05016e */
if(!s->budget--) { s->failed_pc=0x0c05016eu; return 0; }
r[14]=r[4];
goto P_0c050170;
P_0c050170: /* original 61d1, guest PC 0x0c050170 */
if(!s->budget--) { s->failed_pc=0x0c050170u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[1]=tmp;
goto P_0c050172;
P_0c050172: /* original 6843, guest PC 0x0c050172 */
if(!s->budget--) { s->failed_pc=0x0c050172u; return 0; }
r[8]=r[4];
goto P_0c050174;
P_0c050174: /* original 4f22, guest PC 0x0c050174 */
if(!s->budget--) { s->failed_pc=0x0c050174u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050176;
P_0c050176: /* original d33b, guest PC 0x0c050176 */
if(!s->budget--) { s->failed_pc=0x0c050176u; return 0; }
r[3]=read(ram,0x0c050264u,4);
goto P_0c050178;
P_0c050178: /* original 611d, guest PC 0x0c050178 */
if(!s->budget--) { s->failed_pc=0x0c050178u; return 0; }
r[1]=r[1]&65535u;
goto P_0c05017a;
P_0c05017a: /* original 430b, guest PC 0x0c05017a */
if(!s->budget--) { s->failed_pc=0x0c05017au; return 0; }
target=r[3];
r[16]=code_base|0x0c05017eu;
r[14]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05017eu) { target=s->pc; goto dispatch; }
goto P_0c05017e;
P_0c05017c: /* original 7e01, guest PC 0x0c05017c */
if(!s->budget--) { s->failed_pc=0x0c05017cu; return 0; }
r[14]+=0x00000001u;
goto P_0c05017e;
P_0c05017e: /* original bfd3, guest PC 0x0c05017e */
if(!s->budget--) { s->failed_pc=0x0c05017eu; return 0; }
target=code_base|0x0c050128u; r[16]=code_base|0x0c050182u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050182u) { target=s->pc; goto dispatch; }
goto P_0c050182;
P_0c050180: /* original 6403, guest PC 0x0c050180 */
if(!s->budget--) { s->failed_pc=0x0c050180u; return 0; }
r[4]=r[0];
goto P_0c050182;
P_0c050182: /* original 2800, guest PC 0x0c050182 */
if(!s->budget--) { s->failed_pc=0x0c050182u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c050184;
P_0c050184: /* original e064, guest PC 0x0c050184 */
if(!s->budget--) { s->failed_pc=0x0c050184u; return 0; }
r[0]=0x00000064u;
goto P_0c050186;
P_0c050186: /* original 61d1, guest PC 0x0c050186 */
if(!s->budget--) { s->failed_pc=0x0c050186u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[1]=tmp;
goto P_0c050188;
P_0c050188: /* original 68e3, guest PC 0x0c050188 */
if(!s->budget--) { s->failed_pc=0x0c050188u; return 0; }
r[8]=r[14];
goto P_0c05018a;
P_0c05018a: /* original d337, guest PC 0x0c05018a */
if(!s->budget--) { s->failed_pc=0x0c05018au; return 0; }
r[3]=read(ram,0x0c050268u,4);
goto P_0c05018c;
P_0c05018c: /* original 611d, guest PC 0x0c05018c */
if(!s->budget--) { s->failed_pc=0x0c05018cu; return 0; }
r[1]=r[1]&65535u;
goto P_0c05018e;
P_0c05018e: /* original 430b, guest PC 0x0c05018e */
if(!s->budget--) { s->failed_pc=0x0c05018eu; return 0; }
target=r[3];
r[16]=code_base|0x0c050192u;
r[14]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050192u) { target=s->pc; goto dispatch; }
goto P_0c050192;
P_0c050190: /* original 7e01, guest PC 0x0c050190 */
if(!s->budget--) { s->failed_pc=0x0c050190u; return 0; }
r[14]+=0x00000001u;
goto P_0c050192;
P_0c050192: /* original bfc9, guest PC 0x0c050192 */
if(!s->budget--) { s->failed_pc=0x0c050192u; return 0; }
target=code_base|0x0c050128u; r[16]=code_base|0x0c050196u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050196u) { target=s->pc; goto dispatch; }
goto P_0c050196;
P_0c050194: /* original 6403, guest PC 0x0c050194 */
if(!s->budget--) { s->failed_pc=0x0c050194u; return 0; }
r[4]=r[0];
goto P_0c050196;
P_0c050196: /* original 2800, guest PC 0x0c050196 */
if(!s->budget--) { s->failed_pc=0x0c050196u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c050198;
P_0c050198: /* original 68e3, guest PC 0x0c050198 */
if(!s->budget--) { s->failed_pc=0x0c050198u; return 0; }
r[8]=r[14];
goto P_0c05019a;
P_0c05019a: /* original 84d2, guest PC 0x0c05019a */
if(!s->budget--) { s->failed_pc=0x0c05019au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c05019c;
P_0c05019c: /* original 640c, guest PC 0x0c05019c */
if(!s->budget--) { s->failed_pc=0x0c05019cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05019e;
P_0c05019e: /* original bfc3, guest PC 0x0c05019e */
if(!s->budget--) { s->failed_pc=0x0c05019eu; return 0; }
target=code_base|0x0c050128u; r[16]=code_base|0x0c0501a2u;
r[14]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0501a2u) { target=s->pc; goto dispatch; }
goto P_0c0501a2;
P_0c0501a0: /* original 7e01, guest PC 0x0c0501a0 */
if(!s->budget--) { s->failed_pc=0x0c0501a0u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501a2;
P_0c0501a2: /* original 2800, guest PC 0x0c0501a2 */
if(!s->budget--) { s->failed_pc=0x0c0501a2u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501a4;
P_0c0501a4: /* original 68e3, guest PC 0x0c0501a4 */
if(!s->budget--) { s->failed_pc=0x0c0501a4u; return 0; }
r[8]=r[14];
goto P_0c0501a6;
P_0c0501a6: /* original 84d3, guest PC 0x0c0501a6 */
if(!s->budget--) { s->failed_pc=0x0c0501a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+3,1);
goto P_0c0501a8;
P_0c0501a8: /* original 640c, guest PC 0x0c0501a8 */
if(!s->budget--) { s->failed_pc=0x0c0501a8u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501aa;
P_0c0501aa: /* original bfbd, guest PC 0x0c0501aa */
if(!s->budget--) { s->failed_pc=0x0c0501aau; return 0; }
target=code_base|0x0c050128u; r[16]=code_base|0x0c0501aeu;
r[14]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0501aeu) { target=s->pc; goto dispatch; }
goto P_0c0501ae;
P_0c0501ac: /* original 7e01, guest PC 0x0c0501ac */
if(!s->budget--) { s->failed_pc=0x0c0501acu; return 0; }
r[14]+=0x00000001u;
goto P_0c0501ae;
P_0c0501ae: /* original 2800, guest PC 0x0c0501ae */
if(!s->budget--) { s->failed_pc=0x0c0501aeu; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501b0;
P_0c0501b0: /* original 68e3, guest PC 0x0c0501b0 */
if(!s->budget--) { s->failed_pc=0x0c0501b0u; return 0; }
r[8]=r[14];
goto P_0c0501b2;
P_0c0501b2: /* original 84d4, guest PC 0x0c0501b2 */
if(!s->budget--) { s->failed_pc=0x0c0501b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c0501b4;
P_0c0501b4: /* original 640c, guest PC 0x0c0501b4 */
if(!s->budget--) { s->failed_pc=0x0c0501b4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501b6;
P_0c0501b6: /* original bfb7, guest PC 0x0c0501b6 */
if(!s->budget--) { s->failed_pc=0x0c0501b6u; return 0; }
target=code_base|0x0c050128u; r[16]=code_base|0x0c0501bau;
r[14]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0501bau) { target=s->pc; goto dispatch; }
goto P_0c0501ba;
P_0c0501b8: /* original 7e01, guest PC 0x0c0501b8 */
if(!s->budget--) { s->failed_pc=0x0c0501b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501ba;
P_0c0501ba: /* original 2800, guest PC 0x0c0501ba */
if(!s->budget--) { s->failed_pc=0x0c0501bau; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501bc;
P_0c0501bc: /* original 68e3, guest PC 0x0c0501bc */
if(!s->budget--) { s->failed_pc=0x0c0501bcu; return 0; }
r[8]=r[14];
goto P_0c0501be;
P_0c0501be: /* original 84d5, guest PC 0x0c0501be */
if(!s->budget--) { s->failed_pc=0x0c0501beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+5,1);
goto P_0c0501c0;
P_0c0501c0: /* original 640c, guest PC 0x0c0501c0 */
if(!s->budget--) { s->failed_pc=0x0c0501c0u; return 0; }
r[4]=r[0]&255u;
goto P_0c0501c2;
P_0c0501c2: /* original bfb1, guest PC 0x0c0501c2 */
if(!s->budget--) { s->failed_pc=0x0c0501c2u; return 0; }
target=code_base|0x0c050128u; r[16]=code_base|0x0c0501c6u;
r[14]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0501c6u) { target=s->pc; goto dispatch; }
goto P_0c0501c6;
P_0c0501c4: /* original 7e01, guest PC 0x0c0501c4 */
if(!s->budget--) { s->failed_pc=0x0c0501c4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501c6;
P_0c0501c6: /* original 2800, guest PC 0x0c0501c6 */
if(!s->budget--) { s->failed_pc=0x0c0501c6u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501c8;
P_0c0501c8: /* original 68e3, guest PC 0x0c0501c8 */
if(!s->budget--) { s->failed_pc=0x0c0501c8u; return 0; }
r[8]=r[14];
goto P_0c0501ca;
P_0c0501ca: /* original 84d6, guest PC 0x0c0501ca */
if(!s->budget--) { s->failed_pc=0x0c0501cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+6,1);
goto P_0c0501cc;
P_0c0501cc: /* original 640c, guest PC 0x0c0501cc */
if(!s->budget--) { s->failed_pc=0x0c0501ccu; return 0; }
r[4]=r[0]&255u;
goto P_0c0501ce;
P_0c0501ce: /* original bfab, guest PC 0x0c0501ce */
if(!s->budget--) { s->failed_pc=0x0c0501ceu; return 0; }
target=code_base|0x0c050128u; r[16]=code_base|0x0c0501d2u;
r[14]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0501d2u) { target=s->pc; goto dispatch; }
goto P_0c0501d2;
P_0c0501d0: /* original 7e01, guest PC 0x0c0501d0 */
if(!s->budget--) { s->failed_pc=0x0c0501d0u; return 0; }
r[14]+=0x00000001u;
goto P_0c0501d2;
P_0c0501d2: /* original 2800, guest PC 0x0c0501d2 */
if(!s->budget--) { s->failed_pc=0x0c0501d2u; return 0; }
write(ram,r[8],r[0],1);
goto P_0c0501d4;
P_0c0501d4: /* original 4f26, guest PC 0x0c0501d4 */
if(!s->budget--) { s->failed_pc=0x0c0501d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0501d6;
P_0c0501d6: /* original 84d7, guest PC 0x0c0501d6 */
if(!s->budget--) { s->failed_pc=0x0c0501d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+7,1);
goto P_0c0501d8;
P_0c0501d8: /* original d124, guest PC 0x0c0501d8 */
if(!s->budget--) { s->failed_pc=0x0c0501d8u; return 0; }
r[1]=read(ram,0x0c05026cu,4);
goto P_0c0501da;
P_0c0501da: /* original 600c, guest PC 0x0c0501da */
if(!s->budget--) { s->failed_pc=0x0c0501dau; return 0; }
r[0]=r[0]&255u;
goto P_0c0501dc;
P_0c0501dc: /* original c907, guest PC 0x0c0501dc */
if(!s->budget--) { s->failed_pc=0x0c0501dcu; return 0; }
r[0]&=7u;
goto P_0c0501de;
P_0c0501de: /* original 031c, guest PC 0x0c0501de */
if(!s->budget--) { s->failed_pc=0x0c0501deu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0501e0;
P_0c0501e0: /* original 2e30, guest PC 0x0c0501e0 */
if(!s->budget--) { s->failed_pc=0x0c0501e0u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c0501e2;
P_0c0501e2: /* original 68f6, guest PC 0x0c0501e2 */
if(!s->budget--) { s->failed_pc=0x0c0501e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0501e4;
P_0c0501e4: /* original 6df6, guest PC 0x0c0501e4 */
if(!s->budget--) { s->failed_pc=0x0c0501e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0501e6;
P_0c0501e6: /* original 000b, guest PC 0x0c0501e6 */
if(!s->budget--) { s->failed_pc=0x0c0501e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0501e8: /* original 6ef6, guest PC 0x0c0501e8 */
if(!s->budget--) { s->failed_pc=0x0c0501e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0501eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0501eau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
