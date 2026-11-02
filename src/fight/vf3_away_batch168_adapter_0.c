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
int vf3_away_batch168_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c020024u: goto P_0c020024;
case 0x0c020026u: goto P_0c020026;
case 0x0c020028u: goto P_0c020028;
case 0x0c02002au: goto P_0c02002a;
case 0x0c02002cu: goto P_0c02002c;
case 0x0c02002eu: goto P_0c02002e;
case 0x0c020030u: goto P_0c020030;
case 0x0c020032u: goto P_0c020032;
case 0x0c020034u: goto P_0c020034;
case 0x0c020036u: goto P_0c020036;
case 0x0c020038u: goto P_0c020038;
case 0x0c02003au: goto P_0c02003a;
case 0x0c02003cu: goto P_0c02003c;
case 0x0c02003eu: goto P_0c02003e;
case 0x0c020040u: goto P_0c020040;
case 0x0c020042u: goto P_0c020042;
case 0x0c020044u: goto P_0c020044;
case 0x0c020046u: goto P_0c020046;
case 0x0c020048u: goto P_0c020048;
case 0x0c02004au: goto P_0c02004a;
case 0x0c02004cu: goto P_0c02004c;
case 0x0c02004eu: goto P_0c02004e;
case 0x0c020050u: goto P_0c020050;
case 0x0c020052u: goto P_0c020052;
case 0x0c020054u: goto P_0c020054;
case 0x0c020056u: goto P_0c020056;
case 0x0c020058u: goto P_0c020058;
case 0x0c02005au: goto P_0c02005a;
case 0x0c02005cu: goto P_0c02005c;
case 0x0c02005eu: goto P_0c02005e;
case 0x0c020060u: goto P_0c020060;
case 0x0c020062u: goto P_0c020062;
case 0x0c020064u: goto P_0c020064;
case 0x0c020066u: goto P_0c020066;
case 0x0c020068u: goto P_0c020068;
case 0x0c02006au: goto P_0c02006a;
case 0x0c02006cu: goto P_0c02006c;
case 0x0c02006eu: goto P_0c02006e;
case 0x0c020070u: goto P_0c020070;
case 0x0c020072u: goto P_0c020072;
case 0x0c020074u: goto P_0c020074;
case 0x0c020076u: goto P_0c020076;
case 0x0c020078u: goto P_0c020078;
case 0x0c02007au: goto P_0c02007a;
case 0x0c02007cu: goto P_0c02007c;
case 0x0c02007eu: goto P_0c02007e;
case 0x0c07ae2cu: goto P_0c07ae2c;
case 0x0c07ae2eu: goto P_0c07ae2e;
case 0x0c07ae30u: goto P_0c07ae30;
case 0x0c07ae32u: goto P_0c07ae32;
case 0x0c07ae34u: goto P_0c07ae34;
case 0x0c07ae36u: goto P_0c07ae36;
case 0x0c07ae38u: goto P_0c07ae38;
case 0x0c07ae3au: goto P_0c07ae3a;
case 0x0c07ae3cu: goto P_0c07ae3c;
case 0x0c07ae3eu: goto P_0c07ae3e;
case 0x0c07ae40u: goto P_0c07ae40;
case 0x0c07ae42u: goto P_0c07ae42;
case 0x0c07ae44u: goto P_0c07ae44;
case 0x0c07ae46u: goto P_0c07ae46;
case 0x0c07ae48u: goto P_0c07ae48;
case 0x0c07ae4au: goto P_0c07ae4a;
case 0x0c07ae4cu: goto P_0c07ae4c;
case 0x0c07ae4eu: goto P_0c07ae4e;
case 0x0c07ae50u: goto P_0c07ae50;
case 0x0c07ae52u: goto P_0c07ae52;
case 0x0c07ae54u: goto P_0c07ae54;
case 0x0c07ae56u: goto P_0c07ae56;
case 0x0c07ae58u: goto P_0c07ae58;
case 0x0c07ae5au: goto P_0c07ae5a;
case 0x0c07ae5cu: goto P_0c07ae5c;
case 0x0c07ae5eu: goto P_0c07ae5e;
case 0x0c07ae60u: goto P_0c07ae60;
case 0x0c07ae62u: goto P_0c07ae62;
case 0x0c07ae64u: goto P_0c07ae64;
case 0x0c07ae66u: goto P_0c07ae66;
case 0x0c07ae68u: goto P_0c07ae68;
case 0x0c07ae6au: goto P_0c07ae6a;
case 0x0c07ae6cu: goto P_0c07ae6c;
case 0x0c07ae6eu: goto P_0c07ae6e;
case 0x0c07ae70u: goto P_0c07ae70;
case 0x0c07ae72u: goto P_0c07ae72;
case 0x0c07ae74u: goto P_0c07ae74;
case 0x0c07ae76u: goto P_0c07ae76;
case 0x0c07ae78u: goto P_0c07ae78;
case 0x0c07ae7au: goto P_0c07ae7a;
case 0x0c07ae7cu: goto P_0c07ae7c;
case 0x0c07ae7eu: goto P_0c07ae7e;
case 0x0c07ae80u: goto P_0c07ae80;
case 0x0c07ae82u: goto P_0c07ae82;
case 0x0c07ae84u: goto P_0c07ae84;
case 0x0c07ae86u: goto P_0c07ae86;
case 0x0c07ae88u: goto P_0c07ae88;
case 0x0c07ae8au: goto P_0c07ae8a;
case 0x0c07ae8cu: goto P_0c07ae8c;
case 0x0c07b398u: goto P_0c07b398;
case 0x0c07b39au: goto P_0c07b39a;
case 0x0c07b39cu: goto P_0c07b39c;
case 0x0c07b39eu: goto P_0c07b39e;
case 0x0c07b3a0u: goto P_0c07b3a0;
case 0x0c07b3a2u: goto P_0c07b3a2;
case 0x0c07b3a4u: goto P_0c07b3a4;
case 0x0c07b3a6u: goto P_0c07b3a6;
case 0x0c07b3a8u: goto P_0c07b3a8;
case 0x0c07b3aau: goto P_0c07b3aa;
case 0x0c07b3acu: goto P_0c07b3ac;
case 0x0c07b3aeu: goto P_0c07b3ae;
case 0x0c07b3b0u: goto P_0c07b3b0;
case 0x0c07b3b2u: goto P_0c07b3b2;
case 0x0c07b3b4u: goto P_0c07b3b4;
case 0x0c07b3b6u: goto P_0c07b3b6;
case 0x0c07b3b8u: goto P_0c07b3b8;
case 0x0c07b3bau: goto P_0c07b3ba;
case 0x0c07b3bcu: goto P_0c07b3bc;
case 0x0c07b3beu: goto P_0c07b3be;
case 0x0c07b3c0u: goto P_0c07b3c0;
case 0x0c07b3c2u: goto P_0c07b3c2;
case 0x0c07b3c4u: goto P_0c07b3c4;
case 0x0c07b3c6u: goto P_0c07b3c6;
case 0x0c07b3c8u: goto P_0c07b3c8;
case 0x0c07b3cau: goto P_0c07b3ca;
case 0x0c07b3ccu: goto P_0c07b3cc;
case 0x0c07b3ceu: goto P_0c07b3ce;
case 0x0c07b3d0u: goto P_0c07b3d0;
case 0x0c07b4d4u: goto P_0c07b4d4;
case 0x0c07b4d6u: goto P_0c07b4d6;
case 0x0c07b4d8u: goto P_0c07b4d8;
case 0x0c07b4dau: goto P_0c07b4da;
case 0x0c07b4dcu: goto P_0c07b4dc;
case 0x0c07b4deu: goto P_0c07b4de;
case 0x0c07b4e0u: goto P_0c07b4e0;
case 0x0c07b4e2u: goto P_0c07b4e2;
case 0x0c07b4e4u: goto P_0c07b4e4;
case 0x0c07b4e6u: goto P_0c07b4e6;
case 0x0c07b4e8u: goto P_0c07b4e8;
case 0x0c07b4eau: goto P_0c07b4ea;
case 0x0c07b4ecu: goto P_0c07b4ec;
case 0x0c07b4eeu: goto P_0c07b4ee;
case 0x0c07b4f0u: goto P_0c07b4f0;
case 0x0c07b4f2u: goto P_0c07b4f2;
case 0x0c07b4f4u: goto P_0c07b4f4;
case 0x0c07b4f6u: goto P_0c07b4f6;
case 0x0c07b4f8u: goto P_0c07b4f8;
case 0x0c07b4fau: goto P_0c07b4fa;
case 0x0c07b4fcu: goto P_0c07b4fc;
case 0x0c07b4feu: goto P_0c07b4fe;
case 0x0c07b500u: goto P_0c07b500;
case 0x0c07b502u: goto P_0c07b502;
case 0x0c07b504u: goto P_0c07b504;
case 0x0c07b506u: goto P_0c07b506;
case 0x0c07b508u: goto P_0c07b508;
case 0x0c07b50au: goto P_0c07b50a;
case 0x0c07b50cu: goto P_0c07b50c;
case 0x0c07b50eu: goto P_0c07b50e;
case 0x0c07b510u: goto P_0c07b510;
case 0x0c07b512u: goto P_0c07b512;
case 0x0c07b514u: goto P_0c07b514;
case 0x0c07b516u: goto P_0c07b516;
case 0x0c07b518u: goto P_0c07b518;
case 0x0c07b51au: goto P_0c07b51a;
case 0x0c07b51cu: goto P_0c07b51c;
case 0x0c07b51eu: goto P_0c07b51e;
case 0x0c07b520u: goto P_0c07b520;
case 0x0c07b522u: goto P_0c07b522;
case 0x0c07b524u: goto P_0c07b524;
case 0x0c07b526u: goto P_0c07b526;
case 0x0c07b528u: goto P_0c07b528;
case 0x0c07b52au: goto P_0c07b52a;
case 0x0c07b52cu: goto P_0c07b52c;
case 0x0c07b52eu: goto P_0c07b52e;
case 0x0c07b530u: goto P_0c07b530;
case 0x0c07b532u: goto P_0c07b532;
case 0x0c07b534u: goto P_0c07b534;
case 0x0c07b536u: goto P_0c07b536;
case 0x0c07b538u: goto P_0c07b538;
case 0x0c07b53au: goto P_0c07b53a;
case 0x0c07b53cu: goto P_0c07b53c;
case 0x0c07b53eu: goto P_0c07b53e;
case 0x0c07b540u: goto P_0c07b540;
case 0x0c07b542u: goto P_0c07b542;
case 0x0c07b544u: goto P_0c07b544;
case 0x0c07b546u: goto P_0c07b546;
case 0x0c07b548u: goto P_0c07b548;
case 0x0c07b54au: goto P_0c07b54a;
case 0x0c07b54cu: goto P_0c07b54c;
case 0x0c07b54eu: goto P_0c07b54e;
case 0x0c07b550u: goto P_0c07b550;
case 0x0c07b552u: goto P_0c07b552;
case 0x0c07b554u: goto P_0c07b554;
case 0x0c07b556u: goto P_0c07b556;
case 0x0c07b558u: goto P_0c07b558;
case 0x0c07b55au: goto P_0c07b55a;
case 0x0c07b55cu: goto P_0c07b55c;
case 0x0c07b55eu: goto P_0c07b55e;
case 0x0c07b560u: goto P_0c07b560;
case 0x0c07b562u: goto P_0c07b562;
case 0x0c07b564u: goto P_0c07b564;
case 0x0c07b566u: goto P_0c07b566;
case 0x0c07b568u: goto P_0c07b568;
case 0x0c07b56au: goto P_0c07b56a;
case 0x0c07b56cu: goto P_0c07b56c;
case 0x0c07b56eu: goto P_0c07b56e;
case 0x0c07b570u: goto P_0c07b570;
case 0x0c07b572u: goto P_0c07b572;
case 0x0c07b574u: goto P_0c07b574;
case 0x0c07b576u: goto P_0c07b576;
case 0x0c07b578u: goto P_0c07b578;
case 0x0c07b57au: goto P_0c07b57a;
case 0x0c07b57cu: goto P_0c07b57c;
case 0x0c07b57eu: goto P_0c07b57e;
case 0x0c07b580u: goto P_0c07b580;
case 0x0c07b582u: goto P_0c07b582;
case 0x0c07b584u: goto P_0c07b584;
case 0x0c07b586u: goto P_0c07b586;
case 0x0c07b588u: goto P_0c07b588;
case 0x0c07b58au: goto P_0c07b58a;
case 0x0c07b58cu: goto P_0c07b58c;
case 0x0c07b58eu: goto P_0c07b58e;
case 0x0c07b590u: goto P_0c07b590;
case 0x0c07b592u: goto P_0c07b592;
case 0x0c07b594u: goto P_0c07b594;
case 0x0c07b596u: goto P_0c07b596;
case 0x0c07b598u: goto P_0c07b598;
case 0x0c07b59au: goto P_0c07b59a;
case 0x0c07b59cu: goto P_0c07b59c;
case 0x0c07b59eu: goto P_0c07b59e;
case 0x0c07b5a0u: goto P_0c07b5a0;
case 0x0c07b5a2u: goto P_0c07b5a2;
case 0x0c07b5a4u: goto P_0c07b5a4;
case 0x0c07b5a6u: goto P_0c07b5a6;
case 0x0c07b5a8u: goto P_0c07b5a8;
case 0x0c07b5aau: goto P_0c07b5aa;
case 0x0c07b5acu: goto P_0c07b5ac;
case 0x0c07b5aeu: goto P_0c07b5ae;
default: return vf3_matrix_family(target,s,ram);
}
P_0c020024: /* original c719, guest PC 0x0c020024 */
if(!s->budget--) { s->failed_pc=0x0c020024u; return 0; }
r[0]=code_base|0x0002008cu;
goto P_0c020026;
P_0c020026: /* original 6206, guest PC 0x0c020026 */
if(!s->budget--) { s->failed_pc=0x0c020026u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[2]=tmp;
goto P_0c020028;
P_0c020028: /* original e300, guest PC 0x0c020028 */
if(!s->budget--) { s->failed_pc=0x0c020028u; return 0; }
r[3]=0x00000000u;
goto P_0c02002a;
P_0c02002a: /* original 6406, guest PC 0x0c02002a */
if(!s->budget--) { s->failed_pc=0x0c02002au; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[4]=tmp;
goto P_0c02002c;
P_0c02002c: /* original 2232, guest PC 0x0c02002c */
if(!s->budget--) { s->failed_pc=0x0c02002cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c02002e;
P_0c02002e: /* original 4410, guest PC 0x0c02002e */
if(!s->budget--) { s->failed_pc=0x0c02002eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c020030;
P_0c020030: /* original 7204, guest PC 0x0c020030 */
if(!s->budget--) { s->failed_pc=0x0c020030u; return 0; }
r[2]+=0x00000004u;
goto P_0c020032;
P_0c020032: /* original 8bfb, guest PC 0x0c020032 */
if(!s->budget--) { s->failed_pc=0x0c020032u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c02002c; }
goto P_0c020034;
P_0c020034: /* original 0009, guest PC 0x0c020034 */
if(!s->budget--) { s->failed_pc=0x0c020034u; return 0; }
goto P_0c020036;
P_0c020036: /* original c719, guest PC 0x0c020036 */
if(!s->budget--) { s->failed_pc=0x0c020036u; return 0; }
r[0]=code_base|0x0002009cu;
goto P_0c020038;
P_0c020038: /* original 6f06, guest PC 0x0c020038 */
if(!s->budget--) { s->failed_pc=0x0c020038u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[15]=tmp;
goto P_0c02003a;
P_0c02003a: /* original 6006, guest PC 0x0c02003a */
if(!s->budget--) { s->failed_pc=0x0c02003au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c02003c;
P_0c02003c: /* original e100, guest PC 0x0c02003c */
if(!s->budget--) { s->failed_pc=0x0c02003cu; return 0; }
r[1]=0x00000000u;
goto P_0c02003e;
P_0c02003e: /* original e200, guest PC 0x0c02003e */
if(!s->budget--) { s->failed_pc=0x0c02003eu; return 0; }
r[2]=0x00000000u;
goto P_0c020040;
P_0c020040: /* original e300, guest PC 0x0c020040 */
if(!s->budget--) { s->failed_pc=0x0c020040u; return 0; }
r[3]=0x00000000u;
goto P_0c020042;
P_0c020042: /* original e400, guest PC 0x0c020042 */
if(!s->budget--) { s->failed_pc=0x0c020042u; return 0; }
r[4]=0x00000000u;
goto P_0c020044;
P_0c020044: /* original e500, guest PC 0x0c020044 */
if(!s->budget--) { s->failed_pc=0x0c020044u; return 0; }
r[5]=0x00000000u;
goto P_0c020046;
P_0c020046: /* original e600, guest PC 0x0c020046 */
if(!s->budget--) { s->failed_pc=0x0c020046u; return 0; }
r[6]=0x00000000u;
goto P_0c020048;
P_0c020048: /* original e700, guest PC 0x0c020048 */
if(!s->budget--) { s->failed_pc=0x0c020048u; return 0; }
r[7]=0x00000000u;
goto P_0c02004a;
P_0c02004a: /* original e800, guest PC 0x0c02004a */
if(!s->budget--) { s->failed_pc=0x0c02004au; return 0; }
r[8]=0x00000000u;
goto P_0c02004c;
P_0c02004c: /* original e900, guest PC 0x0c02004c */
if(!s->budget--) { s->failed_pc=0x0c02004cu; return 0; }
r[9]=0x00000000u;
goto P_0c02004e;
P_0c02004e: /* original ea00, guest PC 0x0c02004e */
if(!s->budget--) { s->failed_pc=0x0c02004eu; return 0; }
r[10]=0x00000000u;
goto P_0c020050;
P_0c020050: /* original eb00, guest PC 0x0c020050 */
if(!s->budget--) { s->failed_pc=0x0c020050u; return 0; }
r[11]=0x00000000u;
goto P_0c020052;
P_0c020052: /* original ec00, guest PC 0x0c020052 */
if(!s->budget--) { s->failed_pc=0x0c020052u; return 0; }
r[12]=0x00000000u;
goto P_0c020054;
P_0c020054: /* original ed00, guest PC 0x0c020054 */
if(!s->budget--) { s->failed_pc=0x0c020054u; return 0; }
r[13]=0x00000000u;
goto P_0c020056;
P_0c020056: /* original ee00, guest PC 0x0c020056 */
if(!s->budget--) { s->failed_pc=0x0c020056u; return 0; }
r[14]=0x00000000u;
goto P_0c020058;
P_0c020058: /* original f08d, guest PC 0x0c020058 */
if(!s->budget--) { s->failed_pc=0x0c020058u; return 0; }
fr[0]=0;
goto P_0c02005a;
P_0c02005a: /* original f10c, guest PC 0x0c02005a */
if(!s->budget--) { s->failed_pc=0x0c02005au; return 0; }
vf3_matrix_move(s,1,0);
goto P_0c02005c;
P_0c02005c: /* original f20c, guest PC 0x0c02005c */
if(!s->budget--) { s->failed_pc=0x0c02005cu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c02005e;
P_0c02005e: /* original f30c, guest PC 0x0c02005e */
if(!s->budget--) { s->failed_pc=0x0c02005eu; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c020060;
P_0c020060: /* original f40c, guest PC 0x0c020060 */
if(!s->budget--) { s->failed_pc=0x0c020060u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c020062;
P_0c020062: /* original f50c, guest PC 0x0c020062 */
if(!s->budget--) { s->failed_pc=0x0c020062u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c020064;
P_0c020064: /* original f60c, guest PC 0x0c020064 */
if(!s->budget--) { s->failed_pc=0x0c020064u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c020066;
P_0c020066: /* original f70c, guest PC 0x0c020066 */
if(!s->budget--) { s->failed_pc=0x0c020066u; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c020068;
P_0c020068: /* original f80c, guest PC 0x0c020068 */
if(!s->budget--) { s->failed_pc=0x0c020068u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c02006a;
P_0c02006a: /* original f90c, guest PC 0x0c02006a */
if(!s->budget--) { s->failed_pc=0x0c02006au; return 0; }
vf3_matrix_move(s,9,0);
goto P_0c02006c;
P_0c02006c: /* original fa0c, guest PC 0x0c02006c */
if(!s->budget--) { s->failed_pc=0x0c02006cu; return 0; }
vf3_matrix_move(s,10,0);
goto P_0c02006e;
P_0c02006e: /* original fb0c, guest PC 0x0c02006e */
if(!s->budget--) { s->failed_pc=0x0c02006eu; return 0; }
vf3_matrix_move(s,11,0);
goto P_0c020070;
P_0c020070: /* original fc0c, guest PC 0x0c020070 */
if(!s->budget--) { s->failed_pc=0x0c020070u; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c020072;
P_0c020072: /* original fd0c, guest PC 0x0c020072 */
if(!s->budget--) { s->failed_pc=0x0c020072u; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c020074;
P_0c020074: /* original fe0c, guest PC 0x0c020074 */
if(!s->budget--) { s->failed_pc=0x0c020074u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c020076;
P_0c020076: /* original ff0c, guest PC 0x0c020076 */
if(!s->budget--) { s->failed_pc=0x0c020076u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c020078;
P_0c020078: /* original 400b, guest PC 0x0c020078 */
if(!s->budget--) { s->failed_pc=0x0c020078u; return 0; }
target=r[0];
r[16]=code_base|0x0c02007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c02007cu) { target=s->pc; goto dispatch; }
goto P_0c02007c;
P_0c02007a: /* original 0009, guest PC 0x0c02007a */
if(!s->budget--) { s->failed_pc=0x0c02007au; return 0; }
goto P_0c02007c;
P_0c02007c: /* original affe, guest PC 0x0c02007c */
if(!s->budget--) { s->failed_pc=0x0c02007cu; return 0; }
goto P_0c02007c;
P_0c02007e: /* original 0009, guest PC 0x0c02007e */
if(!s->budget--) { s->failed_pc=0x0c02007eu; return 0; }
if(!vf3_matrix_family(0x0c020080u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c020080u; return 0; } return 1;
P_0c07ae2c: /* original 2fe6, guest PC 0x0c07ae2c */
if(!s->budget--) { s->failed_pc=0x0c07ae2cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae2e;
P_0c07ae2e: /* original 2fd6, guest PC 0x0c07ae2e */
if(!s->budget--) { s->failed_pc=0x0c07ae2eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae30;
P_0c07ae30: /* original 4f22, guest PC 0x0c07ae30 */
if(!s->budget--) { s->failed_pc=0x0c07ae30u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ae32;
P_0c07ae32: /* original 7ffc, guest PC 0x0c07ae32 */
if(!s->budget--) { s->failed_pc=0x0c07ae32u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ae34;
P_0c07ae34: /* original 2f42, guest PC 0x0c07ae34 */
if(!s->budget--) { s->failed_pc=0x0c07ae34u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07ae36;
P_0c07ae36: /* original b3bb, guest PC 0x0c07ae36 */
if(!s->budget--) { s->failed_pc=0x0c07ae36u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07ae3au;
r[14]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ae3au) { target=s->pc; goto dispatch; }
goto P_0c07ae3a;
P_0c07ae38: /* original 6e53, guest PC 0x0c07ae38 */
if(!s->budget--) { s->failed_pc=0x0c07ae38u; return 0; }
r[14]=r[5];
goto P_0c07ae3a;
P_0c07ae3a: /* original 6d0d, guest PC 0x0c07ae3a */
if(!s->budget--) { s->failed_pc=0x0c07ae3au; return 0; }
r[13]=r[0]&65535u;
goto P_0c07ae3c;
P_0c07ae3c: /* original d33e, guest PC 0x0c07ae3c */
if(!s->budget--) { s->failed_pc=0x0c07ae3cu; return 0; }
r[3]=read(ram,0x0c07af38u,4);
goto P_0c07ae3e;
P_0c07ae3e: /* original 64d3, guest PC 0x0c07ae3e */
if(!s->budget--) { s->failed_pc=0x0c07ae3eu; return 0; }
r[4]=r[13];
goto P_0c07ae40;
P_0c07ae40: /* original 4400, guest PC 0x0c07ae40 */
if(!s->budget--) { s->failed_pc=0x0c07ae40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07ae42;
P_0c07ae42: /* original 343c, guest PC 0x0c07ae42 */
if(!s->budget--) { s->failed_pc=0x0c07ae42u; return 0; }
r[4]+=r[3];
goto P_0c07ae44;
P_0c07ae44: /* original d53b, guest PC 0x0c07ae44 */
if(!s->budget--) { s->failed_pc=0x0c07ae44u; return 0; }
r[5]=read(ram,0x0c07af34u,4);
goto P_0c07ae46;
P_0c07ae46: /* original 6241, guest PC 0x0c07ae46 */
if(!s->budget--) { s->failed_pc=0x0c07ae46u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c07ae48;
P_0c07ae48: /* original 2228, guest PC 0x0c07ae48 */
if(!s->budget--) { s->failed_pc=0x0c07ae48u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07ae4a;
P_0c07ae4a: /* original 8b12, guest PC 0x0c07ae4a */
if(!s->budget--) { s->failed_pc=0x0c07ae4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ae72; }
goto P_0c07ae4c;
P_0c07ae4c: /* original 2451, guest PC 0x0c07ae4c */
if(!s->budget--) { s->failed_pc=0x0c07ae4cu; return 0; }
write(ram,r[4],r[5],2);
goto P_0c07ae4e;
P_0c07ae4e: /* original 64d3, guest PC 0x0c07ae4e */
if(!s->budget--) { s->failed_pc=0x0c07ae4eu; return 0; }
r[4]=r[13];
goto P_0c07ae50;
P_0c07ae50: /* original 926f, guest PC 0x0c07ae50 */
if(!s->budget--) { s->failed_pc=0x0c07ae50u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07af32u,2);
goto P_0c07ae52;
P_0c07ae52: /* original 74bb, guest PC 0x0c07ae52 */
if(!s->budget--) { s->failed_pc=0x0c07ae52u; return 0; }
r[4]+=0xffffffbbu;
goto P_0c07ae54;
P_0c07ae54: /* original 4408, guest PC 0x0c07ae54 */
if(!s->budget--) { s->failed_pc=0x0c07ae54u; return 0; }
r[4]<<=2;
goto P_0c07ae56;
P_0c07ae56: /* original 66e3, guest PC 0x0c07ae56 */
if(!s->budget--) { s->failed_pc=0x0c07ae56u; return 0; }
r[6]=r[14];
goto P_0c07ae58;
P_0c07ae58: /* original 2f26, guest PC 0x0c07ae58 */
if(!s->budget--) { s->failed_pc=0x0c07ae58u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae5a;
P_0c07ae5a: /* original d138, guest PC 0x0c07ae5a */
if(!s->budget--) { s->failed_pc=0x0c07ae5au; return 0; }
r[1]=read(ram,0x0c07af3cu,4);
goto P_0c07ae5c;
P_0c07ae5c: /* original 2f16, guest PC 0x0c07ae5c */
if(!s->budget--) { s->failed_pc=0x0c07ae5cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae5e;
P_0c07ae5e: /* original 2fd6, guest PC 0x0c07ae5e */
if(!s->budget--) { s->failed_pc=0x0c07ae5eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ae60;
P_0c07ae60: /* original d338, guest PC 0x0c07ae60 */
if(!s->budget--) { s->failed_pc=0x0c07ae60u; return 0; }
r[3]=read(ram,0x0c07af44u,4);
goto P_0c07ae62;
P_0c07ae62: /* original d039, guest PC 0x0c07ae62 */
if(!s->budget--) { s->failed_pc=0x0c07ae62u; return 0; }
r[0]=read(ram,0x0c07af48u,4);
goto P_0c07ae64;
P_0c07ae64: /* original 6532, guest PC 0x0c07ae64 */
if(!s->budget--) { s->failed_pc=0x0c07ae64u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c07ae66;
P_0c07ae66: /* original d339, guest PC 0x0c07ae66 */
if(!s->budget--) { s->failed_pc=0x0c07ae66u; return 0; }
r[3]=read(ram,0x0c07af4cu,4);
goto P_0c07ae68;
P_0c07ae68: /* original d735, guest PC 0x0c07ae68 */
if(!s->budget--) { s->failed_pc=0x0c07ae68u; return 0; }
r[7]=read(ram,0x0c07af40u,4);
goto P_0c07ae6a;
P_0c07ae6a: /* original 430b, guest PC 0x0c07ae6a */
if(!s->budget--) { s->failed_pc=0x0c07ae6au; return 0; }
target=r[3];
r[16]=code_base|0x0c07ae6eu;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ae6eu) { target=s->pc; goto dispatch; }
goto P_0c07ae6e;
P_0c07ae6c: /* original 044e, guest PC 0x0c07ae6c */
if(!s->budget--) { s->failed_pc=0x0c07ae6cu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07ae6e;
P_0c07ae6e: /* original a009, guest PC 0x0c07ae6e */
if(!s->budget--) { s->failed_pc=0x0c07ae6eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ae84;
P_0c07ae70: /* original 7f0c, guest PC 0x0c07ae70 */
if(!s->budget--) { s->failed_pc=0x0c07ae70u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ae72;
P_0c07ae72: /* original 6141, guest PC 0x0c07ae72 */
if(!s->budget--) { s->failed_pc=0x0c07ae72u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[1]=tmp;
goto P_0c07ae74;
P_0c07ae74: /* original 611d, guest PC 0x0c07ae74 */
if(!s->budget--) { s->failed_pc=0x0c07ae74u; return 0; }
r[1]=r[1]&65535u;
goto P_0c07ae76;
P_0c07ae76: /* original 3150, guest PC 0x0c07ae76 */
if(!s->budget--) { s->failed_pc=0x0c07ae76u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[5])!=0);
goto P_0c07ae78;
P_0c07ae78: /* original 8b02, guest PC 0x0c07ae78 */
if(!s->budget--) { s->failed_pc=0x0c07ae78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ae80; }
goto P_0c07ae7a;
P_0c07ae7a: /* original e100, guest PC 0x0c07ae7a */
if(!s->budget--) { s->failed_pc=0x0c07ae7au; return 0; }
r[1]=0x00000000u;
goto P_0c07ae7c;
P_0c07ae7c: /* original a002, guest PC 0x0c07ae7c */
if(!s->budget--) { s->failed_pc=0x0c07ae7cu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c07ae84;
P_0c07ae7e: /* original 2e12, guest PC 0x0c07ae7e */
if(!s->budget--) { s->failed_pc=0x0c07ae7eu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c07ae80;
P_0c07ae80: /* original e0ff, guest PC 0x0c07ae80 */
if(!s->budget--) { s->failed_pc=0x0c07ae80u; return 0; }
r[0]=0xffffffffu;
goto P_0c07ae82;
P_0c07ae82: /* original 2e02, guest PC 0x0c07ae82 */
if(!s->budget--) { s->failed_pc=0x0c07ae82u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c07ae84;
P_0c07ae84: /* original 7f04, guest PC 0x0c07ae84 */
if(!s->budget--) { s->failed_pc=0x0c07ae84u; return 0; }
r[15]+=0x00000004u;
goto P_0c07ae86;
P_0c07ae86: /* original 4f26, guest PC 0x0c07ae86 */
if(!s->budget--) { s->failed_pc=0x0c07ae86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ae88;
P_0c07ae88: /* original 6df6, guest PC 0x0c07ae88 */
if(!s->budget--) { s->failed_pc=0x0c07ae88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ae8a;
P_0c07ae8a: /* original 000b, guest PC 0x0c07ae8a */
if(!s->budget--) { s->failed_pc=0x0c07ae8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ae8c: /* original 6ef6, guest PC 0x0c07ae8c */
if(!s->budget--) { s->failed_pc=0x0c07ae8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ae8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ae8eu; return 0; } return 1;
P_0c07b398: /* original c748, guest PC 0x0c07b398 */
if(!s->budget--) { s->failed_pc=0x0c07b398u; return 0; }
r[0]=code_base|0x0007b4bcu;
goto P_0c07b39a;
P_0c07b39a: /* original f24c, guest PC 0x0c07b39a */
if(!s->budget--) { s->failed_pc=0x0c07b39au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b39c;
P_0c07b39c: /* original f308, guest PC 0x0c07b39c */
if(!s->budget--) { s->failed_pc=0x0c07b39cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b39e;
P_0c07b39e: /* original e018, guest PC 0x0c07b39e */
if(!s->budget--) { s->failed_pc=0x0c07b39eu; return 0; }
r[0]=0x00000018u;
goto P_0c07b3a0;
P_0c07b3a0: /* original f460, guest PC 0x0c07b3a0 */
if(!s->budget--) { s->failed_pc=0x0c07b3a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07b3a2;
P_0c07b3a2: /* original f230, guest PC 0x0c07b3a2 */
if(!s->budget--) { s->failed_pc=0x0c07b3a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c07b3a4;
P_0c07b3a4: /* original f282, guest PC 0x0c07b3a4 */
if(!s->budget--) { s->failed_pc=0x0c07b3a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c07b3a6;
P_0c07b3a6: /* original f427, guest PC 0x0c07b3a6 */
if(!s->budget--) { s->failed_pc=0x0c07b3a6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07b3a8;
P_0c07b3a8: /* original c745, guest PC 0x0c07b3a8 */
if(!s->budget--) { s->failed_pc=0x0c07b3a8u; return 0; }
r[0]=code_base|0x0007b4c0u;
goto P_0c07b3aa;
P_0c07b3aa: /* original f208, guest PC 0x0c07b3aa */
if(!s->budget--) { s->failed_pc=0x0c07b3aau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b3ac;
P_0c07b3ac: /* original e01c, guest PC 0x0c07b3ac */
if(!s->budget--) { s->failed_pc=0x0c07b3acu; return 0; }
r[0]=0x0000001cu;
goto P_0c07b3ae;
P_0c07b3ae: /* original f15c, guest PC 0x0c07b3ae */
if(!s->budget--) { s->failed_pc=0x0c07b3aeu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c07b3b0;
P_0c07b3b0: /* original f570, guest PC 0x0c07b3b0 */
if(!s->budget--) { s->failed_pc=0x0c07b3b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c07b3b2;
P_0c07b3b2: /* original f120, guest PC 0x0c07b3b2 */
if(!s->budget--) { s->failed_pc=0x0c07b3b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c07b3b4;
P_0c07b3b4: /* original f192, guest PC 0x0c07b3b4 */
if(!s->budget--) { s->failed_pc=0x0c07b3b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07b3b6;
P_0c07b3b6: /* original f417, guest PC 0x0c07b3b6 */
if(!s->budget--) { s->failed_pc=0x0c07b3b6u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c07b3b8;
P_0c07b3b8: /* original c742, guest PC 0x0c07b3b8 */
if(!s->budget--) { s->failed_pc=0x0c07b3b8u; return 0; }
r[0]=code_base|0x0007b4c4u;
goto P_0c07b3ba;
P_0c07b3ba: /* original f108, guest PC 0x0c07b3ba */
if(!s->budget--) { s->failed_pc=0x0c07b3bau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c07b3bc;
P_0c07b3bc: /* original e020, guest PC 0x0c07b3bc */
if(!s->budget--) { s->failed_pc=0x0c07b3bcu; return 0; }
r[0]=0x00000020u;
goto P_0c07b3be;
P_0c07b3be: /* original f410, guest PC 0x0c07b3be */
if(!s->budget--) { s->failed_pc=0x0c07b3beu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c07b3c0;
P_0c07b3c0: /* original f482, guest PC 0x0c07b3c0 */
if(!s->budget--) { s->failed_pc=0x0c07b3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c07b3c2;
P_0c07b3c2: /* original f447, guest PC 0x0c07b3c2 */
if(!s->budget--) { s->failed_pc=0x0c07b3c2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b3c4;
P_0c07b3c4: /* original c740, guest PC 0x0c07b3c4 */
if(!s->budget--) { s->failed_pc=0x0c07b3c4u; return 0; }
r[0]=code_base|0x0007b4c8u;
goto P_0c07b3c6;
P_0c07b3c6: /* original f308, guest PC 0x0c07b3c6 */
if(!s->budget--) { s->failed_pc=0x0c07b3c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b3c8;
P_0c07b3c8: /* original e024, guest PC 0x0c07b3c8 */
if(!s->budget--) { s->failed_pc=0x0c07b3c8u; return 0; }
r[0]=0x00000024u;
goto P_0c07b3ca;
P_0c07b3ca: /* original f530, guest PC 0x0c07b3ca */
if(!s->budget--) { s->failed_pc=0x0c07b3cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c07b3cc;
P_0c07b3cc: /* original f592, guest PC 0x0c07b3cc */
if(!s->budget--) { s->failed_pc=0x0c07b3ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b3ce;
P_0c07b3ce: /* original 000b, guest PC 0x0c07b3ce */
if(!s->budget--) { s->failed_pc=0x0c07b3ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c07b3d0: /* original f457, guest PC 0x0c07b3d0 */
if(!s->budget--) { s->failed_pc=0x0c07b3d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07b3d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b3d2u; return 0; } return 1;
P_0c07b4d4: /* original 654d, guest PC 0x0c07b4d4 */
if(!s->budget--) { s->failed_pc=0x0c07b4d4u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b4d6;
P_0c07b4d6: /* original 2fe6, guest PC 0x0c07b4d6 */
if(!s->budget--) { s->failed_pc=0x0c07b4d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4d8;
P_0c07b4d8: /* original 2fd6, guest PC 0x0c07b4d8 */
if(!s->budget--) { s->failed_pc=0x0c07b4d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4da;
P_0c07b4da: /* original 9378, guest PC 0x0c07b4da */
if(!s->budget--) { s->failed_pc=0x0c07b4dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b4dc;
P_0c07b4dc: /* original 2358, guest PC 0x0c07b4dc */
if(!s->budget--) { s->failed_pc=0x0c07b4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c07b4de;
P_0c07b4de: /* original 8912, guest PC 0x0c07b4de */
if(!s->budget--) { s->failed_pc=0x0c07b4deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b506; }
goto P_0c07b4e0;
P_0c07b4e0: /* original 9476, guest PC 0x0c07b4e0 */
if(!s->budget--) { s->failed_pc=0x0c07b4e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b4e2;
P_0c07b4e2: /* original d23c, guest PC 0x0c07b4e2 */
if(!s->budget--) { s->failed_pc=0x0c07b4e2u; return 0; }
r[2]=read(ram,0x0c07b5d4u,4);
goto P_0c07b4e4;
P_0c07b4e4: /* original 2459, guest PC 0x0c07b4e4 */
if(!s->budget--) { s->failed_pc=0x0c07b4e4u; return 0; }
r[4]&=r[5];
goto P_0c07b4e6;
P_0c07b4e6: /* original 6343, guest PC 0x0c07b4e6 */
if(!s->budget--) { s->failed_pc=0x0c07b4e6u; return 0; }
r[3]=r[4];
goto P_0c07b4e8;
P_0c07b4e8: /* original 6543, guest PC 0x0c07b4e8 */
if(!s->budget--) { s->failed_pc=0x0c07b4e8u; return 0; }
r[5]=r[4];
goto P_0c07b4ea;
P_0c07b4ea: /* original 4308, guest PC 0x0c07b4ea */
if(!s->budget--) { s->failed_pc=0x0c07b4eau; return 0; }
r[3]<<=2;
goto P_0c07b4ec;
P_0c07b4ec: /* original 4500, guest PC 0x0c07b4ec */
if(!s->budget--) { s->failed_pc=0x0c07b4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b4ee;
P_0c07b4ee: /* original 353c, guest PC 0x0c07b4ee */
if(!s->budget--) { s->failed_pc=0x0c07b4eeu; return 0; }
r[5]+=r[3];
goto P_0c07b4f0;
P_0c07b4f0: /* original 352c, guest PC 0x0c07b4f0 */
if(!s->budget--) { s->failed_pc=0x0c07b4f0u; return 0; }
r[5]+=r[2];
goto P_0c07b4f2;
P_0c07b4f2: /* original 8452, guest PC 0x0c07b4f2 */
if(!s->budget--) { s->failed_pc=0x0c07b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c07b4f4;
P_0c07b4f4: /* original 6451, guest PC 0x0c07b4f4 */
if(!s->budget--) { s->failed_pc=0x0c07b4f4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c07b4f6;
P_0c07b4f6: /* original 660c, guest PC 0x0c07b4f6 */
if(!s->budget--) { s->failed_pc=0x0c07b4f6u; return 0; }
r[6]=r[0]&255u;
goto P_0c07b4f8;
P_0c07b4f8: /* original 8453, guest PC 0x0c07b4f8 */
if(!s->budget--) { s->failed_pc=0x0c07b4f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c07b4fa;
P_0c07b4fa: /* original 670c, guest PC 0x0c07b4fa */
if(!s->budget--) { s->failed_pc=0x0c07b4fau; return 0; }
r[7]=r[0]&255u;
goto P_0c07b4fc;
P_0c07b4fc: /* original 8454, guest PC 0x0c07b4fc */
if(!s->budget--) { s->failed_pc=0x0c07b4fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c07b4fe;
P_0c07b4fe: /* original 6e0c, guest PC 0x0c07b4fe */
if(!s->budget--) { s->failed_pc=0x0c07b4feu; return 0; }
r[14]=r[0]&255u;
goto P_0c07b500;
P_0c07b500: /* original 8455, guest PC 0x0c07b500 */
if(!s->budget--) { s->failed_pc=0x0c07b500u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c07b502;
P_0c07b502: /* original a00a, guest PC 0x0c07b502 */
if(!s->budget--) { s->failed_pc=0x0c07b502u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b51a;
P_0c07b504: /* original 6d0c, guest PC 0x0c07b504 */
if(!s->budget--) { s->failed_pc=0x0c07b504u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b506;
P_0c07b506: /* original e500, guest PC 0x0c07b506 */
if(!s->budget--) { s->failed_pc=0x0c07b506u; return 0; }
r[5]=0x00000000u;
goto P_0c07b508;
P_0c07b508: /* original d333, guest PC 0x0c07b508 */
if(!s->budget--) { s->failed_pc=0x0c07b508u; return 0; }
r[3]=read(ram,0x0c07b5d8u,4);
goto P_0c07b50a;
P_0c07b50a: /* original 6753, guest PC 0x0c07b50a */
if(!s->budget--) { s->failed_pc=0x0c07b50au; return 0; }
r[7]=r[5];
goto P_0c07b50c;
P_0c07b50c: /* original 6653, guest PC 0x0c07b50c */
if(!s->budget--) { s->failed_pc=0x0c07b50cu; return 0; }
r[6]=r[5];
goto P_0c07b50e;
P_0c07b50e: /* original 654d, guest PC 0x0c07b50e */
if(!s->budget--) { s->failed_pc=0x0c07b50eu; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b510;
P_0c07b510: /* original 4508, guest PC 0x0c07b510 */
if(!s->budget--) { s->failed_pc=0x0c07b510u; return 0; }
r[5]<<=2;
goto P_0c07b512;
P_0c07b512: /* original 353c, guest PC 0x0c07b512 */
if(!s->budget--) { s->failed_pc=0x0c07b512u; return 0; }
r[5]+=r[3];
goto P_0c07b514;
P_0c07b514: /* original 8551, guest PC 0x0c07b514 */
if(!s->budget--) { s->failed_pc=0x0c07b514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b516;
P_0c07b516: /* original 6e51, guest PC 0x0c07b516 */
if(!s->budget--) { s->failed_pc=0x0c07b516u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[14]=tmp;
goto P_0c07b518;
P_0c07b518: /* original 6d03, guest PC 0x0c07b518 */
if(!s->budget--) { s->failed_pc=0x0c07b518u; return 0; }
r[13]=r[0];
goto P_0c07b51a;
P_0c07b51a: /* original 666d, guest PC 0x0c07b51a */
if(!s->budget--) { s->failed_pc=0x0c07b51au; return 0; }
r[6]=r[6]&65535u;
goto P_0c07b51c;
P_0c07b51c: /* original d22f, guest PC 0x0c07b51c */
if(!s->budget--) { s->failed_pc=0x0c07b51cu; return 0; }
r[2]=read(ram,0x0c07b5dcu,4);
goto P_0c07b51e;
P_0c07b51e: /* original 4608, guest PC 0x0c07b51e */
if(!s->budget--) { s->failed_pc=0x0c07b51eu; return 0; }
r[6]<<=2;
goto P_0c07b520;
P_0c07b520: /* original 4600, guest PC 0x0c07b520 */
if(!s->budget--) { s->failed_pc=0x0c07b520u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b522;
P_0c07b522: /* original 677d, guest PC 0x0c07b522 */
if(!s->budget--) { s->failed_pc=0x0c07b522u; return 0; }
r[7]=r[7]&65535u;
goto P_0c07b524;
P_0c07b524: /* original 4708, guest PC 0x0c07b524 */
if(!s->budget--) { s->failed_pc=0x0c07b524u; return 0; }
r[7]<<=2;
goto P_0c07b526;
P_0c07b526: /* original 634d, guest PC 0x0c07b526 */
if(!s->budget--) { s->failed_pc=0x0c07b526u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b528;
P_0c07b528: /* original 2232, guest PC 0x0c07b528 */
if(!s->budget--) { s->failed_pc=0x0c07b528u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07b52a;
P_0c07b52a: /* original 4700, guest PC 0x0c07b52a */
if(!s->budget--) { s->failed_pc=0x0c07b52au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c07b52c;
P_0c07b52c: /* original 465a, guest PC 0x0c07b52c */
if(!s->budget--) { s->failed_pc=0x0c07b52cu; return 0; }
r[53]=r[6];
goto P_0c07b52e;
P_0c07b52e: /* original 6eed, guest PC 0x0c07b52e */
if(!s->budget--) { s->failed_pc=0x0c07b52eu; return 0; }
r[14]=r[14]&65535u;
goto P_0c07b530;
P_0c07b530: /* original d32b, guest PC 0x0c07b530 */
if(!s->budget--) { s->failed_pc=0x0c07b530u; return 0; }
r[3]=read(ram,0x0c07b5e0u,4);
goto P_0c07b532;
P_0c07b532: /* original 4e08, guest PC 0x0c07b532 */
if(!s->budget--) { s->failed_pc=0x0c07b532u; return 0; }
r[14]<<=2;
goto P_0c07b534;
P_0c07b534: /* original 4e00, guest PC 0x0c07b534 */
if(!s->budget--) { s->failed_pc=0x0c07b534u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07b536;
P_0c07b536: /* original f32d, guest PC 0x0c07b536 */
if(!s->budget--) { s->failed_pc=0x0c07b536u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b538;
P_0c07b538: /* original 6ddd, guest PC 0x0c07b538 */
if(!s->budget--) { s->failed_pc=0x0c07b538u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b53a;
P_0c07b53a: /* original 4d08, guest PC 0x0c07b53a */
if(!s->budget--) { s->failed_pc=0x0c07b53au; return 0; }
r[13]<<=2;
goto P_0c07b53c;
P_0c07b53c: /* original 4d00, guest PC 0x0c07b53c */
if(!s->budget--) { s->failed_pc=0x0c07b53cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b53e;
P_0c07b53e: /* original 72e8, guest PC 0x0c07b53e */
if(!s->budget--) { s->failed_pc=0x0c07b53eu; return 0; }
r[2]+=0xffffffe8u;
goto P_0c07b540;
P_0c07b540: /* original 654d, guest PC 0x0c07b540 */
if(!s->budget--) { s->failed_pc=0x0c07b540u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b542;
P_0c07b542: /* original f33a, guest PC 0x0c07b542 */
if(!s->budget--) { s->failed_pc=0x0c07b542u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b544;
P_0c07b544: /* original 730c, guest PC 0x0c07b544 */
if(!s->budget--) { s->failed_pc=0x0c07b544u; return 0; }
r[3]+=0x0000000cu;
goto P_0c07b546;
P_0c07b546: /* original 475a, guest PC 0x0c07b546 */
if(!s->budget--) { s->failed_pc=0x0c07b546u; return 0; }
r[53]=r[7];
goto P_0c07b548;
P_0c07b548: /* original d126, guest PC 0x0c07b548 */
if(!s->budget--) { s->failed_pc=0x0c07b548u; return 0; }
r[1]=read(ram,0x0c07b5e4u,4);
goto P_0c07b54a;
P_0c07b54a: /* original f32d, guest PC 0x0c07b54a */
if(!s->budget--) { s->failed_pc=0x0c07b54au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b54c;
P_0c07b54c: /* original f13a, guest PC 0x0c07b54c */
if(!s->budget--) { s->failed_pc=0x0c07b54cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c07b54e;
P_0c07b54e: /* original 4e5a, guest PC 0x0c07b54e */
if(!s->budget--) { s->failed_pc=0x0c07b54eu; return 0; }
r[53]=r[14];
goto P_0c07b550;
P_0c07b550: /* original f32d, guest PC 0x0c07b550 */
if(!s->budget--) { s->failed_pc=0x0c07b550u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b552;
P_0c07b552: /* original f23a, guest PC 0x0c07b552 */
if(!s->budget--) { s->failed_pc=0x0c07b552u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c07b554;
P_0c07b554: /* original 4d5a, guest PC 0x0c07b554 */
if(!s->budget--) { s->failed_pc=0x0c07b554u; return 0; }
r[53]=r[13];
goto P_0c07b556;
P_0c07b556: /* original f32d, guest PC 0x0c07b556 */
if(!s->budget--) { s->failed_pc=0x0c07b556u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b558;
P_0c07b558: /* original f33a, guest PC 0x0c07b558 */
if(!s->budget--) { s->failed_pc=0x0c07b558u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b55a;
P_0c07b55a: /* original d11f, guest PC 0x0c07b55a */
if(!s->budget--) { s->failed_pc=0x0c07b55au; return 0; }
r[1]=read(ram,0x0c07b5d8u,4);
goto P_0c07b55c;
P_0c07b55c: /* original 4508, guest PC 0x0c07b55c */
if(!s->budget--) { s->failed_pc=0x0c07b55cu; return 0; }
r[5]<<=2;
goto P_0c07b55e;
P_0c07b55e: /* original f49d, guest PC 0x0c07b55e */
if(!s->budget--) { s->failed_pc=0x0c07b55eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c07b560;
P_0c07b560: /* original 7308, guest PC 0x0c07b560 */
if(!s->budget--) { s->failed_pc=0x0c07b560u; return 0; }
r[3]+=0x00000008u;
goto P_0c07b562;
P_0c07b562: /* original 351c, guest PC 0x0c07b562 */
if(!s->budget--) { s->failed_pc=0x0c07b562u; return 0; }
r[5]+=r[1];
goto P_0c07b564;
P_0c07b564: /* original f24c, guest PC 0x0c07b564 */
if(!s->budget--) { s->failed_pc=0x0c07b564u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b566;
P_0c07b566: /* original 6251, guest PC 0x0c07b566 */
if(!s->budget--) { s->failed_pc=0x0c07b566u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b568;
P_0c07b568: /* original 8551, guest PC 0x0c07b568 */
if(!s->budget--) { s->failed_pc=0x0c07b568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b56a;
P_0c07b56a: /* original 642d, guest PC 0x0c07b56a */
if(!s->budget--) { s->failed_pc=0x0c07b56au; return 0; }
r[4]=r[2]&65535u;
goto P_0c07b56c;
P_0c07b56c: /* original d21e, guest PC 0x0c07b56c */
if(!s->budget--) { s->failed_pc=0x0c07b56cu; return 0; }
r[2]=read(ram,0x0c07b5e8u,4);
goto P_0c07b56e;
P_0c07b56e: /* original 4408, guest PC 0x0c07b56e */
if(!s->budget--) { s->failed_pc=0x0c07b56eu; return 0; }
r[4]<<=2;
goto P_0c07b570;
P_0c07b570: /* original 4400, guest PC 0x0c07b570 */
if(!s->budget--) { s->failed_pc=0x0c07b570u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b572;
P_0c07b572: /* original 6123, guest PC 0x0c07b572 */
if(!s->budget--) { s->failed_pc=0x0c07b572u; return 0; }
r[1]=r[2];
goto P_0c07b574;
P_0c07b574: /* original 644d, guest PC 0x0c07b574 */
if(!s->budget--) { s->failed_pc=0x0c07b574u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b576;
P_0c07b576: /* original 445a, guest PC 0x0c07b576 */
if(!s->budget--) { s->failed_pc=0x0c07b576u; return 0; }
r[53]=r[4];
goto P_0c07b578;
P_0c07b578: /* original 650d, guest PC 0x0c07b578 */
if(!s->budget--) { s->failed_pc=0x0c07b578u; return 0; }
r[5]=r[0]&65535u;
goto P_0c07b57a;
P_0c07b57a: /* original 4508, guest PC 0x0c07b57a */
if(!s->budget--) { s->failed_pc=0x0c07b57au; return 0; }
r[5]<<=2;
goto P_0c07b57c;
P_0c07b57c: /* original 4500, guest PC 0x0c07b57c */
if(!s->budget--) { s->failed_pc=0x0c07b57cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b57e;
P_0c07b57e: /* original f32d, guest PC 0x0c07b57e */
if(!s->budget--) { s->failed_pc=0x0c07b57eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b580;
P_0c07b580: /* original 655d, guest PC 0x0c07b580 */
if(!s->budget--) { s->failed_pc=0x0c07b580u; return 0; }
r[5]=r[5]&65535u;
goto P_0c07b582;
P_0c07b582: /* original f233, guest PC 0x0c07b582 */
if(!s->budget--) { s->failed_pc=0x0c07b582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c07b584;
P_0c07b584: /* original f22a, guest PC 0x0c07b584 */
if(!s->budget--) { s->failed_pc=0x0c07b584u; return 0; }
vf3_matrix_store(s,ram,2,r[2]);
goto P_0c07b586;
P_0c07b586: /* original 72f8, guest PC 0x0c07b586 */
if(!s->budget--) { s->failed_pc=0x0c07b586u; return 0; }
r[2]+=0xfffffff8u;
goto P_0c07b588;
P_0c07b588: /* original 455a, guest PC 0x0c07b588 */
if(!s->budget--) { s->failed_pc=0x0c07b588u; return 0; }
r[53]=r[5];
goto P_0c07b58a;
P_0c07b58a: /* original f32d, guest PC 0x0c07b58a */
if(!s->budget--) { s->failed_pc=0x0c07b58au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b58c;
P_0c07b58c: /* original f433, guest PC 0x0c07b58c */
if(!s->budget--) { s->failed_pc=0x0c07b58cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c07b58e;
P_0c07b58e: /* original f34a, guest PC 0x0c07b58e */
if(!s->budget--) { s->failed_pc=0x0c07b58eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c07b590;
P_0c07b590: /* original 7304, guest PC 0x0c07b590 */
if(!s->budget--) { s->failed_pc=0x0c07b590u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b592;
P_0c07b592: /* original f318, guest PC 0x0c07b592 */
if(!s->budget--) { s->failed_pc=0x0c07b592u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c07b594;
P_0c07b594: /* original f228, guest PC 0x0c07b594 */
if(!s->budget--) { s->failed_pc=0x0c07b594u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c07b596;
P_0c07b596: /* original f232, guest PC 0x0c07b596 */
if(!s->budget--) { s->failed_pc=0x0c07b596u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b598;
P_0c07b598: /* original f32a, guest PC 0x0c07b598 */
if(!s->budget--) { s->failed_pc=0x0c07b598u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b59a;
P_0c07b59a: /* original d014, guest PC 0x0c07b59a */
if(!s->budget--) { s->failed_pc=0x0c07b59au; return 0; }
r[0]=read(ram,0x0c07b5ecu,4);
goto P_0c07b59c;
P_0c07b59c: /* original 720c, guest PC 0x0c07b59c */
if(!s->budget--) { s->failed_pc=0x0c07b59cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c07b59e;
P_0c07b59e: /* original f328, guest PC 0x0c07b59e */
if(!s->budget--) { s->failed_pc=0x0c07b59eu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07b5a0;
P_0c07b5a0: /* original 7304, guest PC 0x0c07b5a0 */
if(!s->budget--) { s->failed_pc=0x0c07b5a0u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b5a2;
P_0c07b5a2: /* original f208, guest PC 0x0c07b5a2 */
if(!s->budget--) { s->failed_pc=0x0c07b5a2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b5a4;
P_0c07b5a4: /* original 70f4, guest PC 0x0c07b5a4 */
if(!s->budget--) { s->failed_pc=0x0c07b5a4u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c07b5a6;
P_0c07b5a6: /* original f232, guest PC 0x0c07b5a6 */
if(!s->budget--) { s->failed_pc=0x0c07b5a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b5a8;
P_0c07b5a8: /* original f32a, guest PC 0x0c07b5a8 */
if(!s->budget--) { s->failed_pc=0x0c07b5a8u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b5aa;
P_0c07b5aa: /* original 6df6, guest PC 0x0c07b5aa */
if(!s->budget--) { s->failed_pc=0x0c07b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b5ac;
P_0c07b5ac: /* original 000b, guest PC 0x0c07b5ac */
if(!s->budget--) { s->failed_pc=0x0c07b5acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b5ae: /* original 6ef6, guest PC 0x0c07b5ae */
if(!s->budget--) { s->failed_pc=0x0c07b5aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07b5b0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
