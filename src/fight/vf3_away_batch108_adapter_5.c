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
int vf3_away_batch108_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09382au: goto P_0c09382a;
case 0x0c09382cu: goto P_0c09382c;
case 0x0c09382eu: goto P_0c09382e;
case 0x0c093830u: goto P_0c093830;
case 0x0c093832u: goto P_0c093832;
case 0x0c093834u: goto P_0c093834;
case 0x0c093836u: goto P_0c093836;
case 0x0c093838u: goto P_0c093838;
case 0x0c09383au: goto P_0c09383a;
case 0x0c09383cu: goto P_0c09383c;
case 0x0c09383eu: goto P_0c09383e;
case 0x0c093840u: goto P_0c093840;
case 0x0c093842u: goto P_0c093842;
case 0x0c093844u: goto P_0c093844;
case 0x0c093846u: goto P_0c093846;
case 0x0c093848u: goto P_0c093848;
case 0x0c09384au: goto P_0c09384a;
case 0x0c09384cu: goto P_0c09384c;
case 0x0c09384eu: goto P_0c09384e;
case 0x0c093850u: goto P_0c093850;
case 0x0c093852u: goto P_0c093852;
case 0x0c093854u: goto P_0c093854;
case 0x0c093856u: goto P_0c093856;
case 0x0c093858u: goto P_0c093858;
case 0x0c09385au: goto P_0c09385a;
case 0x0c09385cu: goto P_0c09385c;
case 0x0c09385eu: goto P_0c09385e;
case 0x0c093860u: goto P_0c093860;
case 0x0c093862u: goto P_0c093862;
case 0x0c093864u: goto P_0c093864;
case 0x0c093866u: goto P_0c093866;
case 0x0c093868u: goto P_0c093868;
case 0x0c09386au: goto P_0c09386a;
case 0x0c09386cu: goto P_0c09386c;
case 0x0c09386eu: goto P_0c09386e;
case 0x0c093870u: goto P_0c093870;
case 0x0c093872u: goto P_0c093872;
case 0x0c093874u: goto P_0c093874;
case 0x0c093876u: goto P_0c093876;
case 0x0c093878u: goto P_0c093878;
case 0x0c09387au: goto P_0c09387a;
case 0x0c09387cu: goto P_0c09387c;
case 0x0c09387eu: goto P_0c09387e;
case 0x0c093880u: goto P_0c093880;
case 0x0c093882u: goto P_0c093882;
case 0x0c093884u: goto P_0c093884;
case 0x0c093886u: goto P_0c093886;
case 0x0c093888u: goto P_0c093888;
case 0x0c09388au: goto P_0c09388a;
case 0x0c09388cu: goto P_0c09388c;
case 0x0c09388eu: goto P_0c09388e;
case 0x0c093890u: goto P_0c093890;
case 0x0c093892u: goto P_0c093892;
case 0x0c093894u: goto P_0c093894;
case 0x0c093896u: goto P_0c093896;
case 0x0c093898u: goto P_0c093898;
case 0x0c09389au: goto P_0c09389a;
case 0x0c09389cu: goto P_0c09389c;
case 0x0c09389eu: goto P_0c09389e;
case 0x0c0938a0u: goto P_0c0938a0;
case 0x0c0938a2u: goto P_0c0938a2;
case 0x0c0938a4u: goto P_0c0938a4;
case 0x0c0938a6u: goto P_0c0938a6;
case 0x0c0938a8u: goto P_0c0938a8;
case 0x0c0938aau: goto P_0c0938aa;
case 0x0c0938acu: goto P_0c0938ac;
case 0x0c0938aeu: goto P_0c0938ae;
case 0x0c0938b0u: goto P_0c0938b0;
case 0x0c0938b2u: goto P_0c0938b2;
case 0x0c0938b4u: goto P_0c0938b4;
case 0x0c0938b6u: goto P_0c0938b6;
case 0x0c0938b8u: goto P_0c0938b8;
case 0x0c0938bau: goto P_0c0938ba;
case 0x0c0938bcu: goto P_0c0938bc;
case 0x0c0938beu: goto P_0c0938be;
case 0x0c0938c0u: goto P_0c0938c0;
case 0x0c0938c2u: goto P_0c0938c2;
case 0x0c0938c4u: goto P_0c0938c4;
case 0x0c0938c6u: goto P_0c0938c6;
case 0x0c0938c8u: goto P_0c0938c8;
case 0x0c0938cau: goto P_0c0938ca;
case 0x0c0938ccu: goto P_0c0938cc;
case 0x0c0938ceu: goto P_0c0938ce;
case 0x0c0938d0u: goto P_0c0938d0;
case 0x0c0938d2u: goto P_0c0938d2;
case 0x0c0938d4u: goto P_0c0938d4;
case 0x0c0938d6u: goto P_0c0938d6;
case 0x0c0938d8u: goto P_0c0938d8;
case 0x0c0938dau: goto P_0c0938da;
case 0x0c0938dcu: goto P_0c0938dc;
case 0x0c0938deu: goto P_0c0938de;
case 0x0c0938e0u: goto P_0c0938e0;
case 0x0c0938e2u: goto P_0c0938e2;
case 0x0c0938e4u: goto P_0c0938e4;
case 0x0c0938e6u: goto P_0c0938e6;
case 0x0c0938e8u: goto P_0c0938e8;
case 0x0c0938eau: goto P_0c0938ea;
case 0x0c0938ecu: goto P_0c0938ec;
case 0x0c0938eeu: goto P_0c0938ee;
case 0x0c0938f0u: goto P_0c0938f0;
case 0x0c0938f2u: goto P_0c0938f2;
case 0x0c0938f4u: goto P_0c0938f4;
case 0x0c0938f6u: goto P_0c0938f6;
case 0x0c0938f8u: goto P_0c0938f8;
case 0x0c0938fau: goto P_0c0938fa;
case 0x0c0938fcu: goto P_0c0938fc;
case 0x0c0938feu: goto P_0c0938fe;
case 0x0c093900u: goto P_0c093900;
case 0x0c093902u: goto P_0c093902;
case 0x0c093904u: goto P_0c093904;
case 0x0c093906u: goto P_0c093906;
case 0x0c093908u: goto P_0c093908;
case 0x0c09390au: goto P_0c09390a;
case 0x0c09390cu: goto P_0c09390c;
case 0x0c09390eu: goto P_0c09390e;
case 0x0c093910u: goto P_0c093910;
case 0x0c093912u: goto P_0c093912;
case 0x0c093914u: goto P_0c093914;
case 0x0c093916u: goto P_0c093916;
case 0x0c093918u: goto P_0c093918;
case 0x0c09391au: goto P_0c09391a;
case 0x0c09391cu: goto P_0c09391c;
case 0x0c09391eu: goto P_0c09391e;
case 0x0c093920u: goto P_0c093920;
case 0x0c093922u: goto P_0c093922;
case 0x0c093924u: goto P_0c093924;
case 0x0c093926u: goto P_0c093926;
case 0x0c093928u: goto P_0c093928;
case 0x0c09392au: goto P_0c09392a;
case 0x0c09392cu: goto P_0c09392c;
case 0x0c09392eu: goto P_0c09392e;
case 0x0c093930u: goto P_0c093930;
case 0x0c093932u: goto P_0c093932;
case 0x0c093934u: goto P_0c093934;
case 0x0c093936u: goto P_0c093936;
case 0x0c093938u: goto P_0c093938;
case 0x0c09393au: goto P_0c09393a;
case 0x0c09393cu: goto P_0c09393c;
case 0x0c09393eu: goto P_0c09393e;
case 0x0c093940u: goto P_0c093940;
case 0x0c093942u: goto P_0c093942;
case 0x0c093944u: goto P_0c093944;
case 0x0c093946u: goto P_0c093946;
case 0x0c093948u: goto P_0c093948;
case 0x0c09394au: goto P_0c09394a;
case 0x0c09394cu: goto P_0c09394c;
case 0x0c09394eu: goto P_0c09394e;
case 0x0c093950u: goto P_0c093950;
case 0x0c093952u: goto P_0c093952;
case 0x0c093954u: goto P_0c093954;
case 0x0c093956u: goto P_0c093956;
case 0x0c093958u: goto P_0c093958;
case 0x0c09395au: goto P_0c09395a;
case 0x0c09395cu: goto P_0c09395c;
case 0x0c093964u: goto P_0c093964;
case 0x0c093966u: goto P_0c093966;
case 0x0c093968u: goto P_0c093968;
case 0x0c09396au: goto P_0c09396a;
case 0x0c09396cu: goto P_0c09396c;
case 0x0c09396eu: goto P_0c09396e;
case 0x0c093970u: goto P_0c093970;
case 0x0c093972u: goto P_0c093972;
case 0x0c093974u: goto P_0c093974;
case 0x0c093976u: goto P_0c093976;
case 0x0c093978u: goto P_0c093978;
case 0x0c09397au: goto P_0c09397a;
case 0x0c09397cu: goto P_0c09397c;
case 0x0c09397eu: goto P_0c09397e;
case 0x0c093980u: goto P_0c093980;
case 0x0c093982u: goto P_0c093982;
case 0x0c093984u: goto P_0c093984;
case 0x0c093986u: goto P_0c093986;
case 0x0c093988u: goto P_0c093988;
case 0x0c09398au: goto P_0c09398a;
case 0x0c09398cu: goto P_0c09398c;
case 0x0c09398eu: goto P_0c09398e;
case 0x0c093990u: goto P_0c093990;
case 0x0c093992u: goto P_0c093992;
case 0x0c093994u: goto P_0c093994;
case 0x0c093996u: goto P_0c093996;
case 0x0c093998u: goto P_0c093998;
case 0x0c09399au: goto P_0c09399a;
case 0x0c09399cu: goto P_0c09399c;
case 0x0c09399eu: goto P_0c09399e;
case 0x0c0939a0u: goto P_0c0939a0;
case 0x0c0939a2u: goto P_0c0939a2;
case 0x0c0939a4u: goto P_0c0939a4;
case 0x0c0939a6u: goto P_0c0939a6;
case 0x0c0939a8u: goto P_0c0939a8;
case 0x0c0939aau: goto P_0c0939aa;
case 0x0c0939acu: goto P_0c0939ac;
case 0x0c0939aeu: goto P_0c0939ae;
case 0x0c0939b0u: goto P_0c0939b0;
case 0x0c0939b2u: goto P_0c0939b2;
case 0x0c0939b4u: goto P_0c0939b4;
case 0x0c0939b6u: goto P_0c0939b6;
case 0x0c0939b8u: goto P_0c0939b8;
case 0x0c0939bau: goto P_0c0939ba;
case 0x0c0939bcu: goto P_0c0939bc;
case 0x0c0939beu: goto P_0c0939be;
case 0x0c0939c0u: goto P_0c0939c0;
case 0x0c0939c2u: goto P_0c0939c2;
case 0x0c0939c4u: goto P_0c0939c4;
case 0x0c0939c6u: goto P_0c0939c6;
case 0x0c0939c8u: goto P_0c0939c8;
case 0x0c0939cau: goto P_0c0939ca;
case 0x0c0939ccu: goto P_0c0939cc;
case 0x0c0939ceu: goto P_0c0939ce;
case 0x0c0939d0u: goto P_0c0939d0;
case 0x0c0939d2u: goto P_0c0939d2;
case 0x0c0939d4u: goto P_0c0939d4;
case 0x0c0939d6u: goto P_0c0939d6;
case 0x0c0939d8u: goto P_0c0939d8;
case 0x0c0939dau: goto P_0c0939da;
case 0x0c0939dcu: goto P_0c0939dc;
case 0x0c0939deu: goto P_0c0939de;
case 0x0c0939e0u: goto P_0c0939e0;
case 0x0c0939e2u: goto P_0c0939e2;
case 0x0c0939e4u: goto P_0c0939e4;
case 0x0c0939e6u: goto P_0c0939e6;
case 0x0c0939e8u: goto P_0c0939e8;
case 0x0c0939eau: goto P_0c0939ea;
case 0x0c0939ecu: goto P_0c0939ec;
case 0x0c0939eeu: goto P_0c0939ee;
case 0x0c0939f0u: goto P_0c0939f0;
case 0x0c093a04u: goto P_0c093a04;
case 0x0c093a06u: goto P_0c093a06;
case 0x0c093a08u: goto P_0c093a08;
case 0x0c093a0au: goto P_0c093a0a;
case 0x0c093a0cu: goto P_0c093a0c;
case 0x0c093a0eu: goto P_0c093a0e;
case 0x0c093a10u: goto P_0c093a10;
case 0x0c093a12u: goto P_0c093a12;
case 0x0c093a14u: goto P_0c093a14;
case 0x0c093a16u: goto P_0c093a16;
case 0x0c093a18u: goto P_0c093a18;
case 0x0c093a1au: goto P_0c093a1a;
case 0x0c093a1cu: goto P_0c093a1c;
case 0x0c093a1eu: goto P_0c093a1e;
case 0x0c093a20u: goto P_0c093a20;
case 0x0c093a22u: goto P_0c093a22;
case 0x0c093a24u: goto P_0c093a24;
case 0x0c093a26u: goto P_0c093a26;
case 0x0c093a28u: goto P_0c093a28;
case 0x0c093a2au: goto P_0c093a2a;
case 0x0c093a2cu: goto P_0c093a2c;
case 0x0c093a2eu: goto P_0c093a2e;
case 0x0c093a30u: goto P_0c093a30;
case 0x0c093a32u: goto P_0c093a32;
case 0x0c093a34u: goto P_0c093a34;
case 0x0c093a36u: goto P_0c093a36;
case 0x0c093a38u: goto P_0c093a38;
case 0x0c093a3au: goto P_0c093a3a;
case 0x0c093a3cu: goto P_0c093a3c;
case 0x0c093a3eu: goto P_0c093a3e;
case 0x0c093a40u: goto P_0c093a40;
case 0x0c093a42u: goto P_0c093a42;
case 0x0c093a44u: goto P_0c093a44;
case 0x0c093a46u: goto P_0c093a46;
case 0x0c093a48u: goto P_0c093a48;
case 0x0c093a4au: goto P_0c093a4a;
case 0x0c093a4cu: goto P_0c093a4c;
case 0x0c093a4eu: goto P_0c093a4e;
case 0x0c093a50u: goto P_0c093a50;
case 0x0c093a52u: goto P_0c093a52;
case 0x0c093a54u: goto P_0c093a54;
case 0x0c093a56u: goto P_0c093a56;
case 0x0c093a58u: goto P_0c093a58;
case 0x0c093a5au: goto P_0c093a5a;
case 0x0c093a5cu: goto P_0c093a5c;
case 0x0c093a5eu: goto P_0c093a5e;
case 0x0c093a60u: goto P_0c093a60;
case 0x0c093a62u: goto P_0c093a62;
case 0x0c093a64u: goto P_0c093a64;
case 0x0c093a66u: goto P_0c093a66;
case 0x0c093a68u: goto P_0c093a68;
case 0x0c093a6au: goto P_0c093a6a;
case 0x0c093a6cu: goto P_0c093a6c;
case 0x0c093a6eu: goto P_0c093a6e;
case 0x0c093a70u: goto P_0c093a70;
case 0x0c093a72u: goto P_0c093a72;
case 0x0c093a74u: goto P_0c093a74;
case 0x0c093a76u: goto P_0c093a76;
case 0x0c093a78u: goto P_0c093a78;
case 0x0c093a7au: goto P_0c093a7a;
case 0x0c093a7cu: goto P_0c093a7c;
case 0x0c093a7eu: goto P_0c093a7e;
case 0x0c093a80u: goto P_0c093a80;
case 0x0c093a82u: goto P_0c093a82;
case 0x0c093a84u: goto P_0c093a84;
case 0x0c093a86u: goto P_0c093a86;
case 0x0c093a88u: goto P_0c093a88;
case 0x0c093a8au: goto P_0c093a8a;
case 0x0c093a8cu: goto P_0c093a8c;
case 0x0c093a8eu: goto P_0c093a8e;
case 0x0c093a90u: goto P_0c093a90;
case 0x0c093a92u: goto P_0c093a92;
case 0x0c093a94u: goto P_0c093a94;
case 0x0c093a96u: goto P_0c093a96;
case 0x0c093a98u: goto P_0c093a98;
case 0x0c093a9au: goto P_0c093a9a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09382a: /* original 2fe6, guest PC 0x0c09382a */
if(!s->budget--) { s->failed_pc=0x0c09382au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09382c;
P_0c09382c: /* original e068, guest PC 0x0c09382c */
if(!s->budget--) { s->failed_pc=0x0c09382cu; return 0; }
r[0]=0x00000068u;
goto P_0c09382e;
P_0c09382e: /* original 2fd6, guest PC 0x0c09382e */
if(!s->budget--) { s->failed_pc=0x0c09382eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093830;
P_0c093830: /* original 6d43, guest PC 0x0c093830 */
if(!s->budget--) { s->failed_pc=0x0c093830u; return 0; }
r[13]=r[4];
goto P_0c093832;
P_0c093832: /* original 2fc6, guest PC 0x0c093832 */
if(!s->budget--) { s->failed_pc=0x0c093832u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093834;
P_0c093834: /* original 6c73, guest PC 0x0c093834 */
if(!s->budget--) { s->failed_pc=0x0c093834u; return 0; }
r[12]=r[7];
goto P_0c093836;
P_0c093836: /* original 2fb6, guest PC 0x0c093836 */
if(!s->budget--) { s->failed_pc=0x0c093836u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093838;
P_0c093838: /* original 6b63, guest PC 0x0c093838 */
if(!s->budget--) { s->failed_pc=0x0c093838u; return 0; }
r[11]=r[6];
goto P_0c09383a;
P_0c09383a: /* original 2fa6, guest PC 0x0c09383a */
if(!s->budget--) { s->failed_pc=0x0c09383au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09383c;
P_0c09383c: /* original 6a53, guest PC 0x0c09383c */
if(!s->budget--) { s->failed_pc=0x0c09383cu; return 0; }
r[10]=r[5];
goto P_0c09383e;
P_0c09383e: /* original 2f96, guest PC 0x0c09383e */
if(!s->budget--) { s->failed_pc=0x0c09383eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093840;
P_0c093840: /* original fffb, guest PC 0x0c093840 */
if(!s->budget--) { s->failed_pc=0x0c093840u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c093842;
P_0c093842: /* original ffeb, guest PC 0x0c093842 */
if(!s->budget--) { s->failed_pc=0x0c093842u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c093844;
P_0c093844: /* original 4f22, guest PC 0x0c093844 */
if(!s->budget--) { s->failed_pc=0x0c093844u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c093846;
P_0c093846: /* original 7fc4, guest PC 0x0c093846 */
if(!s->budget--) { s->failed_pc=0x0c093846u; return 0; }
r[15]+=0xffffffc4u;
goto P_0c093848;
P_0c093848: /* original 09fe, guest PC 0x0c093848 */
if(!s->budget--) { s->failed_pc=0x0c093848u; return 0; }
r[9]=read(ram,r[15]+r[0],4);
goto P_0c09384a;
P_0c09384a: /* original e064, guest PC 0x0c09384a */
if(!s->budget--) { s->failed_pc=0x0c09384au; return 0; }
r[0]=0x00000064u;
goto P_0c09384c;
P_0c09384c: /* original 03fe, guest PC 0x0c09384c */
if(!s->budget--) { s->failed_pc=0x0c09384cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c09384e;
P_0c09384e: /* original e060, guest PC 0x0c09384e */
if(!s->budget--) { s->failed_pc=0x0c09384eu; return 0; }
r[0]=0x00000060u;
goto P_0c093850;
P_0c093850: /* original 0efe, guest PC 0x0c093850 */
if(!s->budget--) { s->failed_pc=0x0c093850u; return 0; }
r[14]=read(ram,r[15]+r[0],4);
goto P_0c093852;
P_0c093852: /* original e030, guest PC 0x0c093852 */
if(!s->budget--) { s->failed_pc=0x0c093852u; return 0; }
r[0]=0x00000030u;
goto P_0c093854;
P_0c093854: /* original 3e3c, guest PC 0x0c093854 */
if(!s->budget--) { s->failed_pc=0x0c093854u; return 0; }
r[14]+=r[3];
goto P_0c093856;
P_0c093856: /* original f3e8, guest PC 0x0c093856 */
if(!s->budget--) { s->failed_pc=0x0c093856u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c093858;
P_0c093858: /* original ff37, guest PC 0x0c093858 */
if(!s->budget--) { s->failed_pc=0x0c093858u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09385a;
P_0c09385a: /* original e004, guest PC 0x0c09385a */
if(!s->budget--) { s->failed_pc=0x0c09385au; return 0; }
r[0]=0x00000004u;
goto P_0c09385c;
P_0c09385c: /* original f3e6, guest PC 0x0c09385c */
if(!s->budget--) { s->failed_pc=0x0c09385cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09385e;
P_0c09385e: /* original e034, guest PC 0x0c09385e */
if(!s->budget--) { s->failed_pc=0x0c09385eu; return 0; }
r[0]=0x00000034u;
goto P_0c093860;
P_0c093860: /* original ff37, guest PC 0x0c093860 */
if(!s->budget--) { s->failed_pc=0x0c093860u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093862;
P_0c093862: /* original e008, guest PC 0x0c093862 */
if(!s->budget--) { s->failed_pc=0x0c093862u; return 0; }
r[0]=0x00000008u;
goto P_0c093864;
P_0c093864: /* original f3e6, guest PC 0x0c093864 */
if(!s->budget--) { s->failed_pc=0x0c093864u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093866;
P_0c093866: /* original e038, guest PC 0x0c093866 */
if(!s->budget--) { s->failed_pc=0x0c093866u; return 0; }
r[0]=0x00000038u;
goto P_0c093868;
P_0c093868: /* original ff37, guest PC 0x0c093868 */
if(!s->budget--) { s->failed_pc=0x0c093868u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09386a;
P_0c09386a: /* original e018, guest PC 0x0c09386a */
if(!s->budget--) { s->failed_pc=0x0c09386au; return 0; }
r[0]=0x00000018u;
goto P_0c09386c;
P_0c09386c: /* original 65d3, guest PC 0x0c09386c */
if(!s->budget--) { s->failed_pc=0x0c09386cu; return 0; }
r[5]=r[13];
goto P_0c09386e;
P_0c09386e: /* original f3e6, guest PC 0x0c09386e */
if(!s->budget--) { s->failed_pc=0x0c09386eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093870;
P_0c093870: /* original e00c, guest PC 0x0c093870 */
if(!s->budget--) { s->failed_pc=0x0c093870u; return 0; }
r[0]=0x0000000cu;
goto P_0c093872;
P_0c093872: /* original 64f3, guest PC 0x0c093872 */
if(!s->budget--) { s->failed_pc=0x0c093872u; return 0; }
r[4]=r[15];
goto P_0c093874;
P_0c093874: /* original 66e3, guest PC 0x0c093874 */
if(!s->budget--) { s->failed_pc=0x0c093874u; return 0; }
r[6]=r[14];
goto P_0c093876;
P_0c093876: /* original ff37, guest PC 0x0c093876 */
if(!s->budget--) { s->failed_pc=0x0c093876u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093878;
P_0c093878: /* original e01c, guest PC 0x0c093878 */
if(!s->budget--) { s->failed_pc=0x0c093878u; return 0; }
r[0]=0x0000001cu;
goto P_0c09387a;
P_0c09387a: /* original f3e6, guest PC 0x0c09387a */
if(!s->budget--) { s->failed_pc=0x0c09387au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09387c;
P_0c09387c: /* original e010, guest PC 0x0c09387c */
if(!s->budget--) { s->failed_pc=0x0c09387cu; return 0; }
r[0]=0x00000010u;
goto P_0c09387e;
P_0c09387e: /* original ff37, guest PC 0x0c09387e */
if(!s->budget--) { s->failed_pc=0x0c09387eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093880;
P_0c093880: /* original e020, guest PC 0x0c093880 */
if(!s->budget--) { s->failed_pc=0x0c093880u; return 0; }
r[0]=0x00000020u;
goto P_0c093882;
P_0c093882: /* original f3e6, guest PC 0x0c093882 */
if(!s->budget--) { s->failed_pc=0x0c093882u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093884;
P_0c093884: /* original e014, guest PC 0x0c093884 */
if(!s->budget--) { s->failed_pc=0x0c093884u; return 0; }
r[0]=0x00000014u;
goto P_0c093886;
P_0c093886: /* original ff37, guest PC 0x0c093886 */
if(!s->budget--) { s->failed_pc=0x0c093886u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093888;
P_0c093888: /* original e024, guest PC 0x0c093888 */
if(!s->budget--) { s->failed_pc=0x0c093888u; return 0; }
r[0]=0x00000024u;
goto P_0c09388a;
P_0c09388a: /* original f3e6, guest PC 0x0c09388a */
if(!s->budget--) { s->failed_pc=0x0c09388au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09388c;
P_0c09388c: /* original e028, guest PC 0x0c09388c */
if(!s->budget--) { s->failed_pc=0x0c09388cu; return 0; }
r[0]=0x00000028u;
goto P_0c09388e;
P_0c09388e: /* original fb3a, guest PC 0x0c09388e */
if(!s->budget--) { s->failed_pc=0x0c09388eu; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c093890;
P_0c093890: /* original f3e6, guest PC 0x0c093890 */
if(!s->budget--) { s->failed_pc=0x0c093890u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093892;
P_0c093892: /* original fc3a, guest PC 0x0c093892 */
if(!s->budget--) { s->failed_pc=0x0c093892u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c093894;
P_0c093894: /* original f059, guest PC 0x0c093894 */
if(!s->budget--) { s->failed_pc=0x0c093894u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093896;
P_0c093896: /* original f369, guest PC 0x0c093896 */
if(!s->budget--) { s->failed_pc=0x0c093896u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093898;
P_0c093898: /* original f159, guest PC 0x0c093898 */
if(!s->budget--) { s->failed_pc=0x0c093898u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09389a;
P_0c09389a: /* original f469, guest PC 0x0c09389a */
if(!s->budget--) { s->failed_pc=0x0c09389au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09389c;
P_0c09389c: /* original f031, guest PC 0x0c09389c */
if(!s->budget--) { s->failed_pc=0x0c09389cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c09389e;
P_0c09389e: /* original f258, guest PC 0x0c09389e */
if(!s->budget--) { s->failed_pc=0x0c09389eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0938a0;
P_0c0938a0: /* original f568, guest PC 0x0c0938a0 */
if(!s->budget--) { s->failed_pc=0x0c0938a0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0938a2;
P_0c0938a2: /* original f141, guest PC 0x0c0938a2 */
if(!s->budget--) { s->failed_pc=0x0c0938a2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0938a4;
P_0c0938a4: /* original f251, guest PC 0x0c0938a4 */
if(!s->budget--) { s->failed_pc=0x0c0938a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0938a6;
P_0c0938a6: /* original 7408, guest PC 0x0c0938a6 */
if(!s->budget--) { s->failed_pc=0x0c0938a6u; return 0; }
r[4]+=0x00000008u;
goto P_0c0938a8;
P_0c0938a8: /* original f42a, guest PC 0x0c0938a8 */
if(!s->budget--) { s->failed_pc=0x0c0938a8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0938aa;
P_0c0938aa: /* original f41b, guest PC 0x0c0938aa */
if(!s->budget--) { s->failed_pc=0x0c0938aau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0938ac;
P_0c0938ac: /* original f40b, guest PC 0x0c0938ac */
if(!s->budget--) { s->failed_pc=0x0c0938acu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0938ae;
P_0c0938ae: /* original 0009, guest PC 0x0c0938ae */
if(!s->budget--) { s->failed_pc=0x0c0938aeu; return 0; }
goto P_0c0938b0;
P_0c0938b0: /* original 64f3, guest PC 0x0c0938b0 */
if(!s->budget--) { s->failed_pc=0x0c0938b0u; return 0; }
r[4]=r[15];
goto P_0c0938b2;
P_0c0938b2: /* original 740c, guest PC 0x0c0938b2 */
if(!s->budget--) { s->failed_pc=0x0c0938b2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0938b4;
P_0c0938b4: /* original 65f3, guest PC 0x0c0938b4 */
if(!s->budget--) { s->failed_pc=0x0c0938b4u; return 0; }
r[5]=r[15];
goto P_0c0938b6;
P_0c0938b6: /* original f049, guest PC 0x0c0938b6 */
if(!s->budget--) { s->failed_pc=0x0c0938b6u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938b8;
P_0c0938b8: /* original f149, guest PC 0x0c0938b8 */
if(!s->budget--) { s->failed_pc=0x0c0938b8u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938ba;
P_0c0938ba: /* original f249, guest PC 0x0c0938ba */
if(!s->budget--) { s->failed_pc=0x0c0938bau; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938bc;
P_0c0938bc: /* original f38d, guest PC 0x0c0938bc */
if(!s->budget--) { s->failed_pc=0x0c0938bcu; return 0; }
fr[3]=0;
goto P_0c0938be;
P_0c0938be: /* original f459, guest PC 0x0c0938be */
if(!s->budget--) { s->failed_pc=0x0c0938beu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938c0;
P_0c0938c0: /* original f559, guest PC 0x0c0938c0 */
if(!s->budget--) { s->failed_pc=0x0c0938c0u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938c2;
P_0c0938c2: /* original f659, guest PC 0x0c0938c2 */
if(!s->budget--) { s->failed_pc=0x0c0938c2u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938c4;
P_0c0938c4: /* original f78d, guest PC 0x0c0938c4 */
if(!s->budget--) { s->failed_pc=0x0c0938c4u; return 0; }
fr[7]=0;
goto P_0c0938c6;
P_0c0938c6: /* original f4ed, guest PC 0x0c0938c6 */
if(!s->budget--) { s->failed_pc=0x0c0938c6u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0938c8;
P_0c0938c8: /* original f07c, guest PC 0x0c0938c8 */
if(!s->budget--) { s->failed_pc=0x0c0938c8u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0938ca;
P_0c0938ca: /* original 0009, guest PC 0x0c0938ca */
if(!s->budget--) { s->failed_pc=0x0c0938cau; return 0; }
goto P_0c0938cc;
P_0c0938cc: /* original 65f3, guest PC 0x0c0938cc */
if(!s->budget--) { s->failed_pc=0x0c0938ccu; return 0; }
r[5]=r[15];
goto P_0c0938ce;
P_0c0938ce: /* original 64f3, guest PC 0x0c0938ce */
if(!s->budget--) { s->failed_pc=0x0c0938ceu; return 0; }
r[4]=r[15];
goto P_0c0938d0;
P_0c0938d0: /* original ff0c, guest PC 0x0c0938d0 */
if(!s->budget--) { s->failed_pc=0x0c0938d0u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0938d2;
P_0c0938d2: /* original 7424, guest PC 0x0c0938d2 */
if(!s->budget--) { s->failed_pc=0x0c0938d2u; return 0; }
r[4]+=0x00000024u;
goto P_0c0938d4;
P_0c0938d4: /* original f40c, guest PC 0x0c0938d4 */
if(!s->budget--) { s->failed_pc=0x0c0938d4u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0938d6;
P_0c0938d6: /* original 750c, guest PC 0x0c0938d6 */
if(!s->budget--) { s->failed_pc=0x0c0938d6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0938d8;
P_0c0938d8: /* original f059, guest PC 0x0c0938d8 */
if(!s->budget--) { s->failed_pc=0x0c0938d8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938da;
P_0c0938da: /* original f159, guest PC 0x0c0938da */
if(!s->budget--) { s->failed_pc=0x0c0938dau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938dc;
P_0c0938dc: /* original f259, guest PC 0x0c0938dc */
if(!s->budget--) { s->failed_pc=0x0c0938dcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938de;
P_0c0938de: /* original 740c, guest PC 0x0c0938de */
if(!s->budget--) { s->failed_pc=0x0c0938deu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0938e0;
P_0c0938e0: /* original f242, guest PC 0x0c0938e0 */
if(!s->budget--) { s->failed_pc=0x0c0938e0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0938e2;
P_0c0938e2: /* original f142, guest PC 0x0c0938e2 */
if(!s->budget--) { s->failed_pc=0x0c0938e2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0938e4;
P_0c0938e4: /* original f042, guest PC 0x0c0938e4 */
if(!s->budget--) { s->failed_pc=0x0c0938e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0938e6;
P_0c0938e6: /* original f42b, guest PC 0x0c0938e6 */
if(!s->budget--) { s->failed_pc=0x0c0938e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0938e8;
P_0c0938e8: /* original f41b, guest PC 0x0c0938e8 */
if(!s->budget--) { s->failed_pc=0x0c0938e8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0938ea;
P_0c0938ea: /* original f40b, guest PC 0x0c0938ea */
if(!s->budget--) { s->failed_pc=0x0c0938eau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0938ec;
P_0c0938ec: /* original 64f3, guest PC 0x0c0938ec */
if(!s->budget--) { s->failed_pc=0x0c0938ecu; return 0; }
r[4]=r[15];
goto P_0c0938ee;
P_0c0938ee: /* original 7424, guest PC 0x0c0938ee */
if(!s->budget--) { s->failed_pc=0x0c0938eeu; return 0; }
r[4]+=0x00000024u;
goto P_0c0938f0;
P_0c0938f0: /* original 65e3, guest PC 0x0c0938f0 */
if(!s->budget--) { s->failed_pc=0x0c0938f0u; return 0; }
r[5]=r[14];
goto P_0c0938f2;
P_0c0938f2: /* original f049, guest PC 0x0c0938f2 */
if(!s->budget--) { s->failed_pc=0x0c0938f2u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938f4;
P_0c0938f4: /* original f359, guest PC 0x0c0938f4 */
if(!s->budget--) { s->failed_pc=0x0c0938f4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938f6;
P_0c0938f6: /* original f149, guest PC 0x0c0938f6 */
if(!s->budget--) { s->failed_pc=0x0c0938f6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938f8;
P_0c0938f8: /* original f459, guest PC 0x0c0938f8 */
if(!s->budget--) { s->failed_pc=0x0c0938f8u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938fa;
P_0c0938fa: /* original f249, guest PC 0x0c0938fa */
if(!s->budget--) { s->failed_pc=0x0c0938fau; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938fc;
P_0c0938fc: /* original f559, guest PC 0x0c0938fc */
if(!s->budget--) { s->failed_pc=0x0c0938fcu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938fe;
P_0c0938fe: /* original f030, guest PC 0x0c0938fe */
if(!s->budget--) { s->failed_pc=0x0c0938feu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093900;
P_0c093900: /* original f250, guest PC 0x0c093900 */
if(!s->budget--) { s->failed_pc=0x0c093900u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093902;
P_0c093902: /* original f140, guest PC 0x0c093902 */
if(!s->budget--) { s->failed_pc=0x0c093902u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c093904;
P_0c093904: /* original f42b, guest PC 0x0c093904 */
if(!s->budget--) { s->failed_pc=0x0c093904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093906;
P_0c093906: /* original f41b, guest PC 0x0c093906 */
if(!s->budget--) { s->failed_pc=0x0c093906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093908;
P_0c093908: /* original f40b, guest PC 0x0c093908 */
if(!s->budget--) { s->failed_pc=0x0c093908u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c09390a;
P_0c09390a: /* original 0009, guest PC 0x0c09390a */
if(!s->budget--) { s->failed_pc=0x0c09390au; return 0; }
goto P_0c09390c;
P_0c09390c: /* original 64f3, guest PC 0x0c09390c */
if(!s->budget--) { s->failed_pc=0x0c09390cu; return 0; }
r[4]=r[15];
goto P_0c09390e;
P_0c09390e: /* original 66f3, guest PC 0x0c09390e */
if(!s->budget--) { s->failed_pc=0x0c09390eu; return 0; }
r[6]=r[15];
goto P_0c093910;
P_0c093910: /* original 7418, guest PC 0x0c093910 */
if(!s->budget--) { s->failed_pc=0x0c093910u; return 0; }
r[4]+=0x00000018u;
goto P_0c093912;
P_0c093912: /* original 65d3, guest PC 0x0c093912 */
if(!s->budget--) { s->failed_pc=0x0c093912u; return 0; }
r[5]=r[13];
goto P_0c093914;
P_0c093914: /* original 7624, guest PC 0x0c093914 */
if(!s->budget--) { s->failed_pc=0x0c093914u; return 0; }
r[6]+=0x00000024u;
goto P_0c093916;
P_0c093916: /* original f059, guest PC 0x0c093916 */
if(!s->budget--) { s->failed_pc=0x0c093916u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093918;
P_0c093918: /* original f369, guest PC 0x0c093918 */
if(!s->budget--) { s->failed_pc=0x0c093918u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09391a;
P_0c09391a: /* original f159, guest PC 0x0c09391a */
if(!s->budget--) { s->failed_pc=0x0c09391au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09391c;
P_0c09391c: /* original f469, guest PC 0x0c09391c */
if(!s->budget--) { s->failed_pc=0x0c09391cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09391e;
P_0c09391e: /* original f031, guest PC 0x0c09391e */
if(!s->budget--) { s->failed_pc=0x0c09391eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c093920;
P_0c093920: /* original f258, guest PC 0x0c093920 */
if(!s->budget--) { s->failed_pc=0x0c093920u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c093922;
P_0c093922: /* original f568, guest PC 0x0c093922 */
if(!s->budget--) { s->failed_pc=0x0c093922u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c093924;
P_0c093924: /* original f141, guest PC 0x0c093924 */
if(!s->budget--) { s->failed_pc=0x0c093924u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c093926;
P_0c093926: /* original f251, guest PC 0x0c093926 */
if(!s->budget--) { s->failed_pc=0x0c093926u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c093928;
P_0c093928: /* original 7408, guest PC 0x0c093928 */
if(!s->budget--) { s->failed_pc=0x0c093928u; return 0; }
r[4]+=0x00000008u;
goto P_0c09392a;
P_0c09392a: /* original f42a, guest PC 0x0c09392a */
if(!s->budget--) { s->failed_pc=0x0c09392au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09392c;
P_0c09392c: /* original f41b, guest PC 0x0c09392c */
if(!s->budget--) { s->failed_pc=0x0c09392cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09392e;
P_0c09392e: /* original f40b, guest PC 0x0c09392e */
if(!s->budget--) { s->failed_pc=0x0c09392eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093930;
P_0c093930: /* original 64f3, guest PC 0x0c093930 */
if(!s->budget--) { s->failed_pc=0x0c093930u; return 0; }
r[4]=r[15];
goto P_0c093932;
P_0c093932: /* original 7418, guest PC 0x0c093932 */
if(!s->budget--) { s->failed_pc=0x0c093932u; return 0; }
r[4]+=0x00000018u;
goto P_0c093934;
P_0c093934: /* original f049, guest PC 0x0c093934 */
if(!s->budget--) { s->failed_pc=0x0c093934u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093936;
P_0c093936: /* original f149, guest PC 0x0c093936 */
if(!s->budget--) { s->failed_pc=0x0c093936u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093938;
P_0c093938: /* original f248, guest PC 0x0c093938 */
if(!s->budget--) { s->failed_pc=0x0c093938u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
goto P_0c09393a;
P_0c09393a: /* original f38d, guest PC 0x0c09393a */
if(!s->budget--) { s->failed_pc=0x0c09393au; return 0; }
fr[3]=0;
goto P_0c09393c;
P_0c09393c: /* original f0ed, guest PC 0x0c09393c */
if(!s->budget--) { s->failed_pc=0x0c09393cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c09393e;
P_0c09393e: /* original f03c, guest PC 0x0c09393e */
if(!s->budget--) { s->failed_pc=0x0c09393eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c093940;
P_0c093940: /* original f3c8, guest PC 0x0c093940 */
if(!s->budget--) { s->failed_pc=0x0c093940u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c093942;
P_0c093942: /* original fe0c, guest PC 0x0c093942 */
if(!s->budget--) { s->failed_pc=0x0c093942u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c093944;
P_0c093944: /* original f3e5, guest PC 0x0c093944 */
if(!s->budget--) { s->failed_pc=0x0c093944u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c093946;
P_0c093946: /* original 8902, guest PC 0x0c093946 */
if(!s->budget--) { s->failed_pc=0x0c093946u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09394e; }
goto P_0c093948;
P_0c093948: /* original d305, guest PC 0x0c093948 */
if(!s->budget--) { s->failed_pc=0x0c093948u; return 0; }
r[3]=read(ram,0x0c093960u,4);
goto P_0c09394a;
P_0c09394a: /* original 432b, guest PC 0x0c09394a */
if(!s->budget--) { s->failed_pc=0x0c09394au; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093a70u: goto P_0c093a70;
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
P_0c09394c: /* original 0009, guest PC 0x0c09394c */
if(!s->budget--) { s->failed_pc=0x0c09394cu; return 0; }
goto P_0c09394e;
P_0c09394e: /* original f3fc, guest PC 0x0c09394e */
if(!s->budget--) { s->failed_pc=0x0c09394eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c093950;
P_0c093950: /* original ff32, guest PC 0x0c093950 */
if(!s->budget--) { s->failed_pc=0x0c093950u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c093952;
P_0c093952: /* original 65f3, guest PC 0x0c093952 */
if(!s->budget--) { s->failed_pc=0x0c093952u; return 0; }
r[5]=r[15];
goto P_0c093954;
P_0c093954: /* original 64f3, guest PC 0x0c093954 */
if(!s->budget--) { s->failed_pc=0x0c093954u; return 0; }
r[4]=r[15];
goto P_0c093956;
P_0c093956: /* original 7524, guest PC 0x0c093956 */
if(!s->budget--) { s->failed_pc=0x0c093956u; return 0; }
r[5]+=0x00000024u;
goto P_0c093958;
P_0c093958: /* original 66e3, guest PC 0x0c093958 */
if(!s->budget--) { s->failed_pc=0x0c093958u; return 0; }
r[6]=r[14];
goto P_0c09395a;
P_0c09395a: /* original a003, guest PC 0x0c09395a */
if(!s->budget--) { s->failed_pc=0x0c09395au; return 0; }
goto P_0c093964;
P_0c09395c: /* original 0009, guest PC 0x0c09395c */
if(!s->budget--) { s->failed_pc=0x0c09395cu; return 0; }
if(!vf3_matrix_family(0x0c09395eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09395eu; return 0; } return 1;
P_0c093964: /* original f059, guest PC 0x0c093964 */
if(!s->budget--) { s->failed_pc=0x0c093964u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093966;
P_0c093966: /* original f369, guest PC 0x0c093966 */
if(!s->budget--) { s->failed_pc=0x0c093966u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093968;
P_0c093968: /* original f159, guest PC 0x0c093968 */
if(!s->budget--) { s->failed_pc=0x0c093968u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09396a;
P_0c09396a: /* original f469, guest PC 0x0c09396a */
if(!s->budget--) { s->failed_pc=0x0c09396au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09396c;
P_0c09396c: /* original f031, guest PC 0x0c09396c */
if(!s->budget--) { s->failed_pc=0x0c09396cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c09396e;
P_0c09396e: /* original f258, guest PC 0x0c09396e */
if(!s->budget--) { s->failed_pc=0x0c09396eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c093970;
P_0c093970: /* original f568, guest PC 0x0c093970 */
if(!s->budget--) { s->failed_pc=0x0c093970u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c093972;
P_0c093972: /* original f141, guest PC 0x0c093972 */
if(!s->budget--) { s->failed_pc=0x0c093972u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c093974;
P_0c093974: /* original f251, guest PC 0x0c093974 */
if(!s->budget--) { s->failed_pc=0x0c093974u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c093976;
P_0c093976: /* original 7408, guest PC 0x0c093976 */
if(!s->budget--) { s->failed_pc=0x0c093976u; return 0; }
r[4]+=0x00000008u;
goto P_0c093978;
P_0c093978: /* original f42a, guest PC 0x0c093978 */
if(!s->budget--) { s->failed_pc=0x0c093978u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09397a;
P_0c09397a: /* original f41b, guest PC 0x0c09397a */
if(!s->budget--) { s->failed_pc=0x0c09397au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09397c;
P_0c09397c: /* original f40b, guest PC 0x0c09397c */
if(!s->budget--) { s->failed_pc=0x0c09397cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c09397e;
P_0c09397e: /* original 0009, guest PC 0x0c09397e */
if(!s->budget--) { s->failed_pc=0x0c09397eu; return 0; }
goto P_0c093980;
P_0c093980: /* original 64f3, guest PC 0x0c093980 */
if(!s->budget--) { s->failed_pc=0x0c093980u; return 0; }
r[4]=r[15];
goto P_0c093982;
P_0c093982: /* original 740c, guest PC 0x0c093982 */
if(!s->budget--) { s->failed_pc=0x0c093982u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093984;
P_0c093984: /* original 65f3, guest PC 0x0c093984 */
if(!s->budget--) { s->failed_pc=0x0c093984u; return 0; }
r[5]=r[15];
goto P_0c093986;
P_0c093986: /* original f049, guest PC 0x0c093986 */
if(!s->budget--) { s->failed_pc=0x0c093986u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093988;
P_0c093988: /* original f149, guest PC 0x0c093988 */
if(!s->budget--) { s->failed_pc=0x0c093988u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09398a;
P_0c09398a: /* original f249, guest PC 0x0c09398a */
if(!s->budget--) { s->failed_pc=0x0c09398au; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09398c;
P_0c09398c: /* original f38d, guest PC 0x0c09398c */
if(!s->budget--) { s->failed_pc=0x0c09398cu; return 0; }
fr[3]=0;
goto P_0c09398e;
P_0c09398e: /* original f459, guest PC 0x0c09398e */
if(!s->budget--) { s->failed_pc=0x0c09398eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093990;
P_0c093990: /* original f559, guest PC 0x0c093990 */
if(!s->budget--) { s->failed_pc=0x0c093990u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093992;
P_0c093992: /* original f659, guest PC 0x0c093992 */
if(!s->budget--) { s->failed_pc=0x0c093992u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093994;
P_0c093994: /* original f78d, guest PC 0x0c093994 */
if(!s->budget--) { s->failed_pc=0x0c093994u; return 0; }
fr[7]=0;
goto P_0c093996;
P_0c093996: /* original f4ed, guest PC 0x0c093996 */
if(!s->budget--) { s->failed_pc=0x0c093996u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c093998;
P_0c093998: /* original f07c, guest PC 0x0c093998 */
if(!s->budget--) { s->failed_pc=0x0c093998u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c09399a;
P_0c09399a: /* original 0009, guest PC 0x0c09399a */
if(!s->budget--) { s->failed_pc=0x0c09399au; return 0; }
goto P_0c09399c;
P_0c09399c: /* original f38d, guest PC 0x0c09399c */
if(!s->budget--) { s->failed_pc=0x0c09399cu; return 0; }
fr[3]=0;
goto P_0c09399e;
P_0c09399e: /* original f40c, guest PC 0x0c09399e */
if(!s->budget--) { s->failed_pc=0x0c09399eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0939a0;
P_0c0939a0: /* original f345, guest PC 0x0c0939a0 */
if(!s->budget--) { s->failed_pc=0x0c0939a0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0939a2;
P_0c0939a2: /* original 8b10, guest PC 0x0c0939a2 */
if(!s->budget--) { s->failed_pc=0x0c0939a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0939c6; }
goto P_0c0939a4;
P_0c0939a4: /* original f3c8, guest PC 0x0c0939a4 */
if(!s->budget--) { s->failed_pc=0x0c0939a4u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c0939a6;
P_0c0939a6: /* original ff35, guest PC 0x0c0939a6 */
if(!s->budget--) { s->failed_pc=0x0c0939a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0939a8;
P_0c0939a8: /* original 8b02, guest PC 0x0c0939a8 */
if(!s->budget--) { s->failed_pc=0x0c0939a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0939b0; }
goto P_0c0939aa;
P_0c0939aa: /* original d312, guest PC 0x0c0939aa */
if(!s->budget--) { s->failed_pc=0x0c0939aau; return 0; }
r[3]=read(ram,0x0c0939f4u,4);
goto P_0c0939ac;
P_0c0939ac: /* original 432b, guest PC 0x0c0939ac */
if(!s->budget--) { s->failed_pc=0x0c0939acu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093a70u: goto P_0c093a70;
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
P_0c0939ae: /* original 0009, guest PC 0x0c0939ae */
if(!s->budget--) { s->failed_pc=0x0c0939aeu; return 0; }
goto P_0c0939b0;
P_0c0939b0: /* original 65f3, guest PC 0x0c0939b0 */
if(!s->budget--) { s->failed_pc=0x0c0939b0u; return 0; }
r[5]=r[15];
goto P_0c0939b2;
P_0c0939b2: /* original d311, guest PC 0x0c0939b2 */
if(!s->budget--) { s->failed_pc=0x0c0939b2u; return 0; }
r[3]=read(ram,0x0c0939f8u,4);
goto P_0c0939b4;
P_0c0939b4: /* original f4b8, guest PC 0x0c0939b4 */
if(!s->budget--) { s->failed_pc=0x0c0939b4u; return 0; }
vf3_matrix_load(s,ram,4,r[11]);
goto P_0c0939b6;
P_0c0939b6: /* original 6693, guest PC 0x0c0939b6 */
if(!s->budget--) { s->failed_pc=0x0c0939b6u; return 0; }
r[6]=r[9];
goto P_0c0939b8;
P_0c0939b8: /* original f5c8, guest PC 0x0c0939b8 */
if(!s->budget--) { s->failed_pc=0x0c0939b8u; return 0; }
vf3_matrix_load(s,ram,5,r[12]);
goto P_0c0939ba;
P_0c0939ba: /* original 7530, guest PC 0x0c0939ba */
if(!s->budget--) { s->failed_pc=0x0c0939bau; return 0; }
r[5]+=0x00000030u;
goto P_0c0939bc;
P_0c0939bc: /* original 430b, guest PC 0x0c0939bc */
if(!s->budget--) { s->failed_pc=0x0c0939bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0939c0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0939c0u) { target=s->pc; goto dispatch; }
goto P_0c0939c0;
P_0c0939be: /* original 64d3, guest PC 0x0c0939be */
if(!s->budget--) { s->failed_pc=0x0c0939beu; return 0; }
r[4]=r[13];
goto P_0c0939c0;
P_0c0939c0: /* original d20c, guest PC 0x0c0939c0 */
if(!s->budget--) { s->failed_pc=0x0c0939c0u; return 0; }
r[2]=read(ram,0x0c0939f4u,4);
goto P_0c0939c2;
P_0c0939c2: /* original 422b, guest PC 0x0c0939c2 */
if(!s->budget--) { s->failed_pc=0x0c0939c2u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093a70u: goto P_0c093a70;
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
P_0c0939c4: /* original 0009, guest PC 0x0c0939c4 */
if(!s->budget--) { s->failed_pc=0x0c0939c4u; return 0; }
goto P_0c0939c6;
P_0c0939c6: /* original e02c, guest PC 0x0c0939c6 */
if(!s->budget--) { s->failed_pc=0x0c0939c6u; return 0; }
r[0]=0x0000002cu;
goto P_0c0939c8;
P_0c0939c8: /* original f3e6, guest PC 0x0c0939c8 */
if(!s->budget--) { s->failed_pc=0x0c0939c8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0939ca;
P_0c0939ca: /* original f3f5, guest PC 0x0c0939ca */
if(!s->budget--) { s->failed_pc=0x0c0939cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0939cc;
P_0c0939cc: /* original 8902, guest PC 0x0c0939cc */
if(!s->budget--) { s->failed_pc=0x0c0939ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0939d4; }
goto P_0c0939ce;
P_0c0939ce: /* original d30b, guest PC 0x0c0939ce */
if(!s->budget--) { s->failed_pc=0x0c0939ceu; return 0; }
r[3]=read(ram,0x0c0939fcu,4);
goto P_0c0939d0;
P_0c0939d0: /* original 432b, guest PC 0x0c0939d0 */
if(!s->budget--) { s->failed_pc=0x0c0939d0u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093a42u: goto P_0c093a42;
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
P_0c0939d2: /* original 0009, guest PC 0x0c0939d2 */
if(!s->budget--) { s->failed_pc=0x0c0939d2u; return 0; }
goto P_0c0939d4;
P_0c0939d4: /* original c70a, guest PC 0x0c0939d4 */
if(!s->budget--) { s->failed_pc=0x0c0939d4u; return 0; }
r[0]=code_base|0x00093a00u;
goto P_0c0939d6;
P_0c0939d6: /* original f208, guest PC 0x0c0939d6 */
if(!s->budget--) { s->failed_pc=0x0c0939d6u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0939d8;
P_0c0939d8: /* original f2e5, guest PC 0x0c0939d8 */
if(!s->budget--) { s->failed_pc=0x0c0939d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[14]))!=0);
goto P_0c0939da;
P_0c0939da: /* original 8f02, guest PC 0x0c0939da */
if(!s->budget--) { s->failed_pc=0x0c0939dau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[11]);
if(!cond) { goto P_0c0939e2; }
goto P_0c0939de;
P_0c0939dc: /* original f4b8, guest PC 0x0c0939dc */
if(!s->budget--) { s->failed_pc=0x0c0939dcu; return 0; }
vf3_matrix_load(s,ram,4,r[11]);
goto P_0c0939de;
P_0c0939de: /* original a002, guest PC 0x0c0939de */
if(!s->budget--) { s->failed_pc=0x0c0939deu; return 0; }
fr[3]=0;
goto P_0c0939e6;
P_0c0939e0: /* original f38d, guest PC 0x0c0939e0 */
if(!s->budget--) { s->failed_pc=0x0c0939e0u; return 0; }
fr[3]=0;
goto P_0c0939e2;
P_0c0939e2: /* original f3ec, guest PC 0x0c0939e2 */
if(!s->budget--) { s->failed_pc=0x0c0939e2u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0939e4;
P_0c0939e4: /* original f37d, guest PC 0x0c0939e4 */
if(!s->budget--) { s->failed_pc=0x0c0939e4u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0939e6;
P_0c0939e6: /* original f432, guest PC 0x0c0939e6 */
if(!s->budget--) { s->failed_pc=0x0c0939e6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0939e8;
P_0c0939e8: /* original 65f3, guest PC 0x0c0939e8 */
if(!s->budget--) { s->failed_pc=0x0c0939e8u; return 0; }
r[5]=r[15];
goto P_0c0939ea;
P_0c0939ea: /* original 64d3, guest PC 0x0c0939ea */
if(!s->budget--) { s->failed_pc=0x0c0939eau; return 0; }
r[4]=r[13];
goto P_0c0939ec;
P_0c0939ec: /* original 7518, guest PC 0x0c0939ec */
if(!s->budget--) { s->failed_pc=0x0c0939ecu; return 0; }
r[5]+=0x00000018u;
goto P_0c0939ee;
P_0c0939ee: /* original a009, guest PC 0x0c0939ee */
if(!s->budget--) { s->failed_pc=0x0c0939eeu; return 0; }
goto P_0c093a04;
P_0c0939f0: /* original 0009, guest PC 0x0c0939f0 */
if(!s->budget--) { s->failed_pc=0x0c0939f0u; return 0; }
if(!vf3_matrix_family(0x0c0939f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0939f2u; return 0; } return 1;
P_0c093a04: /* original f059, guest PC 0x0c093a04 */
if(!s->budget--) { s->failed_pc=0x0c093a04u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a06;
P_0c093a06: /* original f159, guest PC 0x0c093a06 */
if(!s->budget--) { s->failed_pc=0x0c093a06u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a08;
P_0c093a08: /* original f259, guest PC 0x0c093a08 */
if(!s->budget--) { s->failed_pc=0x0c093a08u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a0a;
P_0c093a0a: /* original 740c, guest PC 0x0c093a0a */
if(!s->budget--) { s->failed_pc=0x0c093a0au; return 0; }
r[4]+=0x0000000cu;
goto P_0c093a0c;
P_0c093a0c: /* original f242, guest PC 0x0c093a0c */
if(!s->budget--) { s->failed_pc=0x0c093a0cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c093a0e;
P_0c093a0e: /* original f142, guest PC 0x0c093a0e */
if(!s->budget--) { s->failed_pc=0x0c093a0eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c093a10;
P_0c093a10: /* original f042, guest PC 0x0c093a10 */
if(!s->budget--) { s->failed_pc=0x0c093a10u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c093a12;
P_0c093a12: /* original f42b, guest PC 0x0c093a12 */
if(!s->budget--) { s->failed_pc=0x0c093a12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093a14;
P_0c093a14: /* original f41b, guest PC 0x0c093a14 */
if(!s->budget--) { s->failed_pc=0x0c093a14u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093a16;
P_0c093a16: /* original f40b, guest PC 0x0c093a16 */
if(!s->budget--) { s->failed_pc=0x0c093a16u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093a18;
P_0c093a18: /* original 65f3, guest PC 0x0c093a18 */
if(!s->budget--) { s->failed_pc=0x0c093a18u; return 0; }
r[5]=r[15];
goto P_0c093a1a;
P_0c093a1a: /* original 64d3, guest PC 0x0c093a1a */
if(!s->budget--) { s->failed_pc=0x0c093a1au; return 0; }
r[4]=r[13];
goto P_0c093a1c;
P_0c093a1c: /* original 7524, guest PC 0x0c093a1c */
if(!s->budget--) { s->failed_pc=0x0c093a1cu; return 0; }
r[5]+=0x00000024u;
goto P_0c093a1e;
P_0c093a1e: /* original f049, guest PC 0x0c093a1e */
if(!s->budget--) { s->failed_pc=0x0c093a1eu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093a20;
P_0c093a20: /* original f359, guest PC 0x0c093a20 */
if(!s->budget--) { s->failed_pc=0x0c093a20u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a22;
P_0c093a22: /* original f149, guest PC 0x0c093a22 */
if(!s->budget--) { s->failed_pc=0x0c093a22u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093a24;
P_0c093a24: /* original f459, guest PC 0x0c093a24 */
if(!s->budget--) { s->failed_pc=0x0c093a24u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a26;
P_0c093a26: /* original f249, guest PC 0x0c093a26 */
if(!s->budget--) { s->failed_pc=0x0c093a26u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093a28;
P_0c093a28: /* original f559, guest PC 0x0c093a28 */
if(!s->budget--) { s->failed_pc=0x0c093a28u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a2a;
P_0c093a2a: /* original f030, guest PC 0x0c093a2a */
if(!s->budget--) { s->failed_pc=0x0c093a2au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093a2c;
P_0c093a2c: /* original f250, guest PC 0x0c093a2c */
if(!s->budget--) { s->failed_pc=0x0c093a2cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093a2e;
P_0c093a2e: /* original f140, guest PC 0x0c093a2e */
if(!s->budget--) { s->failed_pc=0x0c093a2eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c093a30;
P_0c093a30: /* original f42b, guest PC 0x0c093a30 */
if(!s->budget--) { s->failed_pc=0x0c093a30u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093a32;
P_0c093a32: /* original f41b, guest PC 0x0c093a32 */
if(!s->budget--) { s->failed_pc=0x0c093a32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093a34;
P_0c093a34: /* original f40b, guest PC 0x0c093a34 */
if(!s->budget--) { s->failed_pc=0x0c093a34u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093a36;
P_0c093a36: /* original 0009, guest PC 0x0c093a36 */
if(!s->budget--) { s->failed_pc=0x0c093a36u; return 0; }
goto P_0c093a38;
P_0c093a38: /* original 6292, guest PC 0x0c093a38 */
if(!s->budget--) { s->failed_pc=0x0c093a38u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c093a3a;
P_0c093a3a: /* original 933c, guest PC 0x0c093a3a */
if(!s->budget--) { s->failed_pc=0x0c093a3au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093ab6u,2);
goto P_0c093a3c;
P_0c093a3c: /* original 223b, guest PC 0x0c093a3c */
if(!s->budget--) { s->failed_pc=0x0c093a3cu; return 0; }
r[2]|=r[3];
goto P_0c093a3e;
P_0c093a3e: /* original a017, guest PC 0x0c093a3e */
if(!s->budget--) { s->failed_pc=0x0c093a3eu; return 0; }
write(ram,r[9],r[2],4);
goto P_0c093a70;
P_0c093a40: /* original 2922, guest PC 0x0c093a40 */
if(!s->budget--) { s->failed_pc=0x0c093a40u; return 0; }
write(ram,r[9],r[2],4);
goto P_0c093a42;
P_0c093a42: /* original e030, guest PC 0x0c093a42 */
if(!s->budget--) { s->failed_pc=0x0c093a42u; return 0; }
r[0]=0x00000030u;
goto P_0c093a44;
P_0c093a44: /* original f3e6, guest PC 0x0c093a44 */
if(!s->budget--) { s->failed_pc=0x0c093a44u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093a46;
P_0c093a46: /* original ff35, guest PC 0x0c093a46 */
if(!s->budget--) { s->failed_pc=0x0c093a46u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c093a48;
P_0c093a48: /* original 8912, guest PC 0x0c093a48 */
if(!s->budget--) { s->failed_pc=0x0c093a48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093a70; }
goto P_0c093a4a;
P_0c093a4a: /* original e00c, guest PC 0x0c093a4a */
if(!s->budget--) { s->failed_pc=0x0c093a4au; return 0; }
r[0]=0x0000000cu;
goto P_0c093a4c;
P_0c093a4c: /* original 65e3, guest PC 0x0c093a4c */
if(!s->budget--) { s->failed_pc=0x0c093a4cu; return 0; }
r[5]=r[14];
goto P_0c093a4e;
P_0c093a4e: /* original f3e6, guest PC 0x0c093a4e */
if(!s->budget--) { s->failed_pc=0x0c093a4eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093a50;
P_0c093a50: /* original e030, guest PC 0x0c093a50 */
if(!s->budget--) { s->failed_pc=0x0c093a50u; return 0; }
r[0]=0x00000030u;
goto P_0c093a52;
P_0c093a52: /* original 750c, guest PC 0x0c093a52 */
if(!s->budget--) { s->failed_pc=0x0c093a52u; return 0; }
r[5]+=0x0000000cu;
goto P_0c093a54;
P_0c093a54: /* original 6693, guest PC 0x0c093a54 */
if(!s->budget--) { s->failed_pc=0x0c093a54u; return 0; }
r[6]=r[9];
goto P_0c093a56;
P_0c093a56: /* original ff37, guest PC 0x0c093a56 */
if(!s->budget--) { s->failed_pc=0x0c093a56u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093a58;
P_0c093a58: /* original e010, guest PC 0x0c093a58 */
if(!s->budget--) { s->failed_pc=0x0c093a58u; return 0; }
r[0]=0x00000010u;
goto P_0c093a5a;
P_0c093a5a: /* original f3e6, guest PC 0x0c093a5a */
if(!s->budget--) { s->failed_pc=0x0c093a5au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093a5c;
P_0c093a5c: /* original e034, guest PC 0x0c093a5c */
if(!s->budget--) { s->failed_pc=0x0c093a5cu; return 0; }
r[0]=0x00000034u;
goto P_0c093a5e;
P_0c093a5e: /* original ff37, guest PC 0x0c093a5e */
if(!s->budget--) { s->failed_pc=0x0c093a5eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093a60;
P_0c093a60: /* original e014, guest PC 0x0c093a60 */
if(!s->budget--) { s->failed_pc=0x0c093a60u; return 0; }
r[0]=0x00000014u;
goto P_0c093a62;
P_0c093a62: /* original f3e6, guest PC 0x0c093a62 */
if(!s->budget--) { s->failed_pc=0x0c093a62u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093a64;
P_0c093a64: /* original e038, guest PC 0x0c093a64 */
if(!s->budget--) { s->failed_pc=0x0c093a64u; return 0; }
r[0]=0x00000038u;
goto P_0c093a66;
P_0c093a66: /* original ff37, guest PC 0x0c093a66 */
if(!s->budget--) { s->failed_pc=0x0c093a66u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093a68;
P_0c093a68: /* original f5c8, guest PC 0x0c093a68 */
if(!s->budget--) { s->failed_pc=0x0c093a68u; return 0; }
vf3_matrix_load(s,ram,5,r[12]);
goto P_0c093a6a;
P_0c093a6a: /* original f4b8, guest PC 0x0c093a6a */
if(!s->budget--) { s->failed_pc=0x0c093a6au; return 0; }
vf3_matrix_load(s,ram,4,r[11]);
goto P_0c093a6c;
P_0c093a6c: /* original b016, guest PC 0x0c093a6c */
if(!s->budget--) { s->failed_pc=0x0c093a6cu; return 0; }
target=code_base|0x0c093a9cu; r[16]=code_base|0x0c093a70u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c093a70u) { target=s->pc; goto dispatch; }
goto P_0c093a70;
P_0c093a6e: /* original 64d3, guest PC 0x0c093a6e */
if(!s->budget--) { s->failed_pc=0x0c093a6eu; return 0; }
r[4]=r[13];
goto P_0c093a70;
P_0c093a70: /* original e030, guest PC 0x0c093a70 */
if(!s->budget--) { s->failed_pc=0x0c093a70u; return 0; }
r[0]=0x00000030u;
goto P_0c093a72;
P_0c093a72: /* original f3f6, guest PC 0x0c093a72 */
if(!s->budget--) { s->failed_pc=0x0c093a72u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093a74;
P_0c093a74: /* original e034, guest PC 0x0c093a74 */
if(!s->budget--) { s->failed_pc=0x0c093a74u; return 0; }
r[0]=0x00000034u;
goto P_0c093a76;
P_0c093a76: /* original fa3a, guest PC 0x0c093a76 */
if(!s->budget--) { s->failed_pc=0x0c093a76u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c093a78;
P_0c093a78: /* original f3f6, guest PC 0x0c093a78 */
if(!s->budget--) { s->failed_pc=0x0c093a78u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093a7a;
P_0c093a7a: /* original e004, guest PC 0x0c093a7a */
if(!s->budget--) { s->failed_pc=0x0c093a7au; return 0; }
r[0]=0x00000004u;
goto P_0c093a7c;
P_0c093a7c: /* original fa37, guest PC 0x0c093a7c */
if(!s->budget--) { s->failed_pc=0x0c093a7cu; return 0; }
vf3_matrix_store(s,ram,3,r[10]+r[0]);
goto P_0c093a7e;
P_0c093a7e: /* original e038, guest PC 0x0c093a7e */
if(!s->budget--) { s->failed_pc=0x0c093a7eu; return 0; }
r[0]=0x00000038u;
goto P_0c093a80;
P_0c093a80: /* original f3f6, guest PC 0x0c093a80 */
if(!s->budget--) { s->failed_pc=0x0c093a80u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093a82;
P_0c093a82: /* original 7f3c, guest PC 0x0c093a82 */
if(!s->budget--) { s->failed_pc=0x0c093a82u; return 0; }
r[15]+=0x0000003cu;
goto P_0c093a84;
P_0c093a84: /* original 4f26, guest PC 0x0c093a84 */
if(!s->budget--) { s->failed_pc=0x0c093a84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c093a86;
P_0c093a86: /* original e008, guest PC 0x0c093a86 */
if(!s->budget--) { s->failed_pc=0x0c093a86u; return 0; }
r[0]=0x00000008u;
goto P_0c093a88;
P_0c093a88: /* original fa37, guest PC 0x0c093a88 */
if(!s->budget--) { s->failed_pc=0x0c093a88u; return 0; }
vf3_matrix_store(s,ram,3,r[10]+r[0]);
goto P_0c093a8a;
P_0c093a8a: /* original fef9, guest PC 0x0c093a8a */
if(!s->budget--) { s->failed_pc=0x0c093a8au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c093a8c;
P_0c093a8c: /* original fff9, guest PC 0x0c093a8c */
if(!s->budget--) { s->failed_pc=0x0c093a8cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c093a8e;
P_0c093a8e: /* original 69f6, guest PC 0x0c093a8e */
if(!s->budget--) { s->failed_pc=0x0c093a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c093a90;
P_0c093a90: /* original 6af6, guest PC 0x0c093a90 */
if(!s->budget--) { s->failed_pc=0x0c093a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c093a92;
P_0c093a92: /* original 6bf6, guest PC 0x0c093a92 */
if(!s->budget--) { s->failed_pc=0x0c093a92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c093a94;
P_0c093a94: /* original 6cf6, guest PC 0x0c093a94 */
if(!s->budget--) { s->failed_pc=0x0c093a94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c093a96;
P_0c093a96: /* original 6df6, guest PC 0x0c093a96 */
if(!s->budget--) { s->failed_pc=0x0c093a96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093a98;
P_0c093a98: /* original 000b, guest PC 0x0c093a98 */
if(!s->budget--) { s->failed_pc=0x0c093a98u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093a9a: /* original 6ef6, guest PC 0x0c093a9a */
if(!s->budget--) { s->failed_pc=0x0c093a9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c093a9cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
