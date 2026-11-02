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
int vf3_away_batch14_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c091980u: goto P_0c091980;
case 0x0c091982u: goto P_0c091982;
case 0x0c091984u: goto P_0c091984;
case 0x0c091986u: goto P_0c091986;
case 0x0c091988u: goto P_0c091988;
case 0x0c09198au: goto P_0c09198a;
case 0x0c09198cu: goto P_0c09198c;
case 0x0c09198eu: goto P_0c09198e;
case 0x0c091990u: goto P_0c091990;
case 0x0c091992u: goto P_0c091992;
case 0x0c091994u: goto P_0c091994;
case 0x0c091996u: goto P_0c091996;
case 0x0c091998u: goto P_0c091998;
case 0x0c09199au: goto P_0c09199a;
case 0x0c09199cu: goto P_0c09199c;
case 0x0c09199eu: goto P_0c09199e;
case 0x0c0919a0u: goto P_0c0919a0;
case 0x0c0919a2u: goto P_0c0919a2;
case 0x0c0919a4u: goto P_0c0919a4;
case 0x0c0919a6u: goto P_0c0919a6;
case 0x0c0919a8u: goto P_0c0919a8;
case 0x0c0919aau: goto P_0c0919aa;
case 0x0c0919acu: goto P_0c0919ac;
case 0x0c0919aeu: goto P_0c0919ae;
case 0x0c0919b0u: goto P_0c0919b0;
case 0x0c0919b2u: goto P_0c0919b2;
case 0x0c0919b4u: goto P_0c0919b4;
case 0x0c0919b6u: goto P_0c0919b6;
case 0x0c0919b8u: goto P_0c0919b8;
case 0x0c0919bau: goto P_0c0919ba;
case 0x0c0919bcu: goto P_0c0919bc;
case 0x0c0919beu: goto P_0c0919be;
case 0x0c0919c0u: goto P_0c0919c0;
case 0x0c0919c2u: goto P_0c0919c2;
case 0x0c0919c4u: goto P_0c0919c4;
case 0x0c0919c6u: goto P_0c0919c6;
case 0x0c0919c8u: goto P_0c0919c8;
case 0x0c0919cau: goto P_0c0919ca;
case 0x0c0919ccu: goto P_0c0919cc;
case 0x0c0919ceu: goto P_0c0919ce;
case 0x0c0919d0u: goto P_0c0919d0;
case 0x0c0919d2u: goto P_0c0919d2;
case 0x0c0919d4u: goto P_0c0919d4;
case 0x0c0919d6u: goto P_0c0919d6;
case 0x0c0919d8u: goto P_0c0919d8;
case 0x0c0919dau: goto P_0c0919da;
case 0x0c0919dcu: goto P_0c0919dc;
case 0x0c0919deu: goto P_0c0919de;
case 0x0c0919e0u: goto P_0c0919e0;
case 0x0c0919e2u: goto P_0c0919e2;
case 0x0c0919e4u: goto P_0c0919e4;
case 0x0c0919e6u: goto P_0c0919e6;
case 0x0c0919e8u: goto P_0c0919e8;
case 0x0c0919eau: goto P_0c0919ea;
case 0x0c0919ecu: goto P_0c0919ec;
case 0x0c0919eeu: goto P_0c0919ee;
case 0x0c0919f0u: goto P_0c0919f0;
case 0x0c0919f2u: goto P_0c0919f2;
case 0x0c0919f4u: goto P_0c0919f4;
case 0x0c0919f6u: goto P_0c0919f6;
case 0x0c0919f8u: goto P_0c0919f8;
case 0x0c0919fau: goto P_0c0919fa;
case 0x0c0919fcu: goto P_0c0919fc;
case 0x0c0919feu: goto P_0c0919fe;
case 0x0c091a00u: goto P_0c091a00;
case 0x0c091a02u: goto P_0c091a02;
case 0x0c091a04u: goto P_0c091a04;
case 0x0c091a06u: goto P_0c091a06;
case 0x0c091a08u: goto P_0c091a08;
case 0x0c091a0au: goto P_0c091a0a;
case 0x0c091a0cu: goto P_0c091a0c;
case 0x0c091a0eu: goto P_0c091a0e;
case 0x0c091a10u: goto P_0c091a10;
case 0x0c091a12u: goto P_0c091a12;
case 0x0c091a14u: goto P_0c091a14;
case 0x0c091a16u: goto P_0c091a16;
case 0x0c091a18u: goto P_0c091a18;
case 0x0c091a1au: goto P_0c091a1a;
case 0x0c091a1cu: goto P_0c091a1c;
case 0x0c091a1eu: goto P_0c091a1e;
case 0x0c091a20u: goto P_0c091a20;
case 0x0c091a22u: goto P_0c091a22;
case 0x0c091a24u: goto P_0c091a24;
case 0x0c091a26u: goto P_0c091a26;
case 0x0c091a28u: goto P_0c091a28;
case 0x0c091a2au: goto P_0c091a2a;
case 0x0c091a2cu: goto P_0c091a2c;
case 0x0c091a2eu: goto P_0c091a2e;
case 0x0c091a30u: goto P_0c091a30;
case 0x0c091a32u: goto P_0c091a32;
case 0x0c091a34u: goto P_0c091a34;
case 0x0c091a36u: goto P_0c091a36;
case 0x0c091a38u: goto P_0c091a38;
case 0x0c091a3au: goto P_0c091a3a;
case 0x0c091a3cu: goto P_0c091a3c;
case 0x0c091a3eu: goto P_0c091a3e;
case 0x0c091a40u: goto P_0c091a40;
case 0x0c091a42u: goto P_0c091a42;
case 0x0c091a44u: goto P_0c091a44;
case 0x0c091a46u: goto P_0c091a46;
case 0x0c091a48u: goto P_0c091a48;
case 0x0c091a4au: goto P_0c091a4a;
case 0x0c091a4cu: goto P_0c091a4c;
case 0x0c091a4eu: goto P_0c091a4e;
case 0x0c091a50u: goto P_0c091a50;
case 0x0c091a52u: goto P_0c091a52;
case 0x0c091a54u: goto P_0c091a54;
case 0x0c091a56u: goto P_0c091a56;
case 0x0c091a58u: goto P_0c091a58;
case 0x0c091a5au: goto P_0c091a5a;
case 0x0c091a5cu: goto P_0c091a5c;
case 0x0c091a5eu: goto P_0c091a5e;
case 0x0c091a60u: goto P_0c091a60;
case 0x0c091a62u: goto P_0c091a62;
case 0x0c091a64u: goto P_0c091a64;
case 0x0c091a66u: goto P_0c091a66;
case 0x0c091a68u: goto P_0c091a68;
case 0x0c091a6au: goto P_0c091a6a;
case 0x0c091a6cu: goto P_0c091a6c;
case 0x0c091a6eu: goto P_0c091a6e;
case 0x0c091a70u: goto P_0c091a70;
case 0x0c091a72u: goto P_0c091a72;
case 0x0c091a74u: goto P_0c091a74;
case 0x0c091a76u: goto P_0c091a76;
case 0x0c091a78u: goto P_0c091a78;
case 0x0c091a7au: goto P_0c091a7a;
case 0x0c091a7cu: goto P_0c091a7c;
case 0x0c091a7eu: goto P_0c091a7e;
case 0x0c091a80u: goto P_0c091a80;
case 0x0c091a82u: goto P_0c091a82;
case 0x0c091a84u: goto P_0c091a84;
case 0x0c091a86u: goto P_0c091a86;
case 0x0c091a88u: goto P_0c091a88;
case 0x0c091a8au: goto P_0c091a8a;
case 0x0c091a8cu: goto P_0c091a8c;
case 0x0c091a8eu: goto P_0c091a8e;
case 0x0c091a90u: goto P_0c091a90;
case 0x0c091a92u: goto P_0c091a92;
case 0x0c091a94u: goto P_0c091a94;
case 0x0c091a96u: goto P_0c091a96;
case 0x0c091a98u: goto P_0c091a98;
case 0x0c091a9au: goto P_0c091a9a;
case 0x0c091a9cu: goto P_0c091a9c;
case 0x0c091a9eu: goto P_0c091a9e;
case 0x0c091aa0u: goto P_0c091aa0;
case 0x0c091aa2u: goto P_0c091aa2;
case 0x0c091aa4u: goto P_0c091aa4;
case 0x0c091aa6u: goto P_0c091aa6;
case 0x0c091aa8u: goto P_0c091aa8;
case 0x0c091aaau: goto P_0c091aaa;
case 0x0c091aacu: goto P_0c091aac;
case 0x0c091aaeu: goto P_0c091aae;
case 0x0c091ab0u: goto P_0c091ab0;
case 0x0c091ab2u: goto P_0c091ab2;
case 0x0c091ac8u: goto P_0c091ac8;
case 0x0c091acau: goto P_0c091aca;
case 0x0c091accu: goto P_0c091acc;
case 0x0c091aceu: goto P_0c091ace;
case 0x0c091ad0u: goto P_0c091ad0;
case 0x0c091ad2u: goto P_0c091ad2;
case 0x0c091ad4u: goto P_0c091ad4;
case 0x0c091ad6u: goto P_0c091ad6;
case 0x0c091ad8u: goto P_0c091ad8;
case 0x0c091adau: goto P_0c091ada;
case 0x0c091adcu: goto P_0c091adc;
case 0x0c091adeu: goto P_0c091ade;
case 0x0c091ae0u: goto P_0c091ae0;
case 0x0c091ae2u: goto P_0c091ae2;
case 0x0c091ae4u: goto P_0c091ae4;
case 0x0c091ae6u: goto P_0c091ae6;
case 0x0c091ae8u: goto P_0c091ae8;
case 0x0c091aeau: goto P_0c091aea;
case 0x0c091aecu: goto P_0c091aec;
case 0x0c091aeeu: goto P_0c091aee;
case 0x0c091af0u: goto P_0c091af0;
case 0x0c091af2u: goto P_0c091af2;
case 0x0c091af4u: goto P_0c091af4;
case 0x0c091af6u: goto P_0c091af6;
case 0x0c091af8u: goto P_0c091af8;
case 0x0c091afau: goto P_0c091afa;
case 0x0c091afcu: goto P_0c091afc;
case 0x0c0a7662u: goto P_0c0a7662;
case 0x0c0a7664u: goto P_0c0a7664;
case 0x0c0a7666u: goto P_0c0a7666;
case 0x0c0a7668u: goto P_0c0a7668;
case 0x0c0a766au: goto P_0c0a766a;
case 0x0c0a766cu: goto P_0c0a766c;
case 0x0c0a766eu: goto P_0c0a766e;
case 0x0c0a7670u: goto P_0c0a7670;
case 0x0c0a7672u: goto P_0c0a7672;
case 0x0c0a7674u: goto P_0c0a7674;
case 0x0c0a7676u: goto P_0c0a7676;
case 0x0c0a7678u: goto P_0c0a7678;
case 0x0c0a767au: goto P_0c0a767a;
case 0x0c0a767cu: goto P_0c0a767c;
case 0x0c0a767eu: goto P_0c0a767e;
case 0x0c0a7680u: goto P_0c0a7680;
case 0x0c0a7682u: goto P_0c0a7682;
case 0x0c0a7684u: goto P_0c0a7684;
case 0x0c0a7686u: goto P_0c0a7686;
case 0x0c0a7688u: goto P_0c0a7688;
case 0x0c0a768au: goto P_0c0a768a;
case 0x0c0a768cu: goto P_0c0a768c;
case 0x0c0a768eu: goto P_0c0a768e;
case 0x0c0a7690u: goto P_0c0a7690;
case 0x0c0a7692u: goto P_0c0a7692;
case 0x0c0a7694u: goto P_0c0a7694;
case 0x0c0a7696u: goto P_0c0a7696;
case 0x0c0a7698u: goto P_0c0a7698;
case 0x0c0a769au: goto P_0c0a769a;
case 0x0c0a769cu: goto P_0c0a769c;
case 0x0c0a769eu: goto P_0c0a769e;
case 0x0c0a76a0u: goto P_0c0a76a0;
case 0x0c0a76a2u: goto P_0c0a76a2;
case 0x0c0a76a4u: goto P_0c0a76a4;
case 0x0c0a76a6u: goto P_0c0a76a6;
case 0x0c0a76a8u: goto P_0c0a76a8;
case 0x0c0a76aau: goto P_0c0a76aa;
case 0x0c0a76acu: goto P_0c0a76ac;
case 0x0c0a76aeu: goto P_0c0a76ae;
case 0x0c0a76b0u: goto P_0c0a76b0;
case 0x0c0a76b2u: goto P_0c0a76b2;
case 0x0c0a76b4u: goto P_0c0a76b4;
case 0x0c0a76b6u: goto P_0c0a76b6;
case 0x0c0a76b8u: goto P_0c0a76b8;
case 0x0c0a76bau: goto P_0c0a76ba;
case 0x0c0a76bcu: goto P_0c0a76bc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c091980: /* original 2fd6, guest PC 0x0c091980 */
if(!s->budget--) { s->failed_pc=0x0c091980u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091982;
P_0c091982: /* original e700, guest PC 0x0c091982 */
if(!s->budget--) { s->failed_pc=0x0c091982u; return 0; }
r[7]=0x00000000u;
goto P_0c091984;
P_0c091984: /* original 2fc6, guest PC 0x0c091984 */
if(!s->budget--) { s->failed_pc=0x0c091984u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091986;
P_0c091986: /* original ec1c, guest PC 0x0c091986 */
if(!s->budget--) { s->failed_pc=0x0c091986u; return 0; }
r[12]=0x0000001cu;
goto P_0c091988;
P_0c091988: /* original 2fb6, guest PC 0x0c091988 */
if(!s->budget--) { s->failed_pc=0x0c091988u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09198a;
P_0c09198a: /* original 6b73, guest PC 0x0c09198a */
if(!s->budget--) { s->failed_pc=0x0c09198au; return 0; }
r[11]=r[7];
goto P_0c09198c;
P_0c09198c: /* original fffb, guest PC 0x0c09198c */
if(!s->budget--) { s->failed_pc=0x0c09198cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09198e;
P_0c09198e: /* original 6dc3, guest PC 0x0c09198e */
if(!s->budget--) { s->failed_pc=0x0c09198eu; return 0; }
r[13]=r[12];
goto P_0c091990;
P_0c091990: /* original 9090, guest PC 0x0c091990 */
if(!s->budget--) { s->failed_pc=0x0c091990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091ab4u,2);
goto P_0c091992;
P_0c091992: /* original 7ffc, guest PC 0x0c091992 */
if(!s->budget--) { s->failed_pc=0x0c091992u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c091994;
P_0c091994: /* original f868, guest PC 0x0c091994 */
if(!s->budget--) { s->failed_pc=0x0c091994u; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
goto P_0c091996;
P_0c091996: /* original 014e, guest PC 0x0c091996 */
if(!s->budget--) { s->failed_pc=0x0c091996u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c091998;
P_0c091998: /* original c747, guest PC 0x0c091998 */
if(!s->budget--) { s->failed_pc=0x0c091998u; return 0; }
r[0]=code_base|0x00091ab8u;
goto P_0c09199a;
P_0c09199a: /* original fa08, guest PC 0x0c09199a */
if(!s->budget--) { s->failed_pc=0x0c09199au; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c09199c;
P_0c09199c: /* original f758, guest PC 0x0c09199c */
if(!s->budget--) { s->failed_pc=0x0c09199cu; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
goto P_0c09199e;
P_0c09199e: /* original e004, guest PC 0x0c09199e */
if(!s->budget--) { s->failed_pc=0x0c09199eu; return 0; }
r[0]=0x00000004u;
goto P_0c0919a0;
P_0c0919a0: /* original f618, guest PC 0x0c0919a0 */
if(!s->budget--) { s->failed_pc=0x0c0919a0u; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c0919a2;
P_0c0919a2: /* original f916, guest PC 0x0c0919a2 */
if(!s->budget--) { s->failed_pc=0x0c0919a2u; return 0; }
vf3_matrix_load(s,ram,9,r[1]+r[0]);
goto P_0c0919a4;
P_0c0919a4: /* original e008, guest PC 0x0c0919a4 */
if(!s->budget--) { s->failed_pc=0x0c0919a4u; return 0; }
r[0]=0x00000008u;
goto P_0c0919a6;
P_0c0919a6: /* original f945, guest PC 0x0c0919a6 */
if(!s->budget--) { s->failed_pc=0x0c0919a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c0919a8;
P_0c0919a8: /* original 8d17, guest PC 0x0c0919a8 */
if(!s->budget--) { s->failed_pc=0x0c0919a8u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,11,r[1]+r[0]);
if(cond) { goto P_0c0919da; }
goto P_0c0919ac;
P_0c0919aa: /* original fb16, guest PC 0x0c0919aa */
if(!s->budget--) { s->failed_pc=0x0c0919aau; return 0; }
vf3_matrix_load(s,ram,11,r[1]+r[0]);
goto P_0c0919ac;
P_0c0919ac: /* original f36c, guest PC 0x0c0919ac */
if(!s->budget--) { s->failed_pc=0x0c0919acu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0919ae;
P_0c0919ae: /* original f67c, guest PC 0x0c0919ae */
if(!s->budget--) { s->failed_pc=0x0c0919aeu; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0919b0;
P_0c0919b0: /* original f631, guest PC 0x0c0919b0 */
if(!s->budget--) { s->failed_pc=0x0c0919b0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0919b2;
P_0c0919b2: /* original f39c, guest PC 0x0c0919b2 */
if(!s->budget--) { s->failed_pc=0x0c0919b2u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0919b4;
P_0c0919b4: /* original f94c, guest PC 0x0c0919b4 */
if(!s->budget--) { s->failed_pc=0x0c0919b4u; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c0919b6;
P_0c0919b6: /* original f931, guest PC 0x0c0919b6 */
if(!s->budget--) { s->failed_pc=0x0c0919b6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c0919b8;
P_0c0919b8: /* original f3bc, guest PC 0x0c0919b8 */
if(!s->budget--) { s->failed_pc=0x0c0919b8u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c0919ba;
P_0c0919ba: /* original fb8c, guest PC 0x0c0919ba */
if(!s->budget--) { s->failed_pc=0x0c0919bau; return 0; }
vf3_matrix_move(s,11,8);
goto P_0c0919bc;
P_0c0919bc: /* original fb31, guest PC 0x0c0919bc */
if(!s->budget--) { s->failed_pc=0x0c0919bcu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'-');
goto P_0c0919be;
P_0c0919be: /* original f36c, guest PC 0x0c0919be */
if(!s->budget--) { s->failed_pc=0x0c0919beu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0919c0;
P_0c0919c0: /* original f632, guest PC 0x0c0919c0 */
if(!s->budget--) { s->failed_pc=0x0c0919c0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0919c2;
P_0c0919c2: /* original f09c, guest PC 0x0c0919c2 */
if(!s->budget--) { s->failed_pc=0x0c0919c2u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c0919c4;
P_0c0919c4: /* original f26c, guest PC 0x0c0919c4 */
if(!s->budget--) { s->failed_pc=0x0c0919c4u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0919c6;
P_0c0919c6: /* original f29e, guest PC 0x0c0919c6 */
if(!s->budget--) { s->failed_pc=0x0c0919c6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[9],fr[2],r[18]);
goto P_0c0919c8;
P_0c0919c8: /* original f0bc, guest PC 0x0c0919c8 */
if(!s->budget--) { s->failed_pc=0x0c0919c8u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c0919ca;
P_0c0919ca: /* original f32c, guest PC 0x0c0919ca */
if(!s->budget--) { s->failed_pc=0x0c0919cau; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0919cc;
P_0c0919cc: /* original f3be, guest PC 0x0c0919cc */
if(!s->budget--) { s->failed_pc=0x0c0919ccu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[11],fr[3],r[18]);
goto P_0c0919ce;
P_0c0919ce: /* original f63c, guest PC 0x0c0919ce */
if(!s->budget--) { s->failed_pc=0x0c0919ceu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0919d0;
P_0c0919d0: /* original fa65, guest PC 0x0c0919d0 */
if(!s->budget--) { s->failed_pc=0x0c0919d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[6]))!=0);
goto P_0c0919d2;
P_0c0919d2: /* original 8b02, guest PC 0x0c0919d2 */
if(!s->budget--) { s->failed_pc=0x0c0919d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0919da; }
goto P_0c0919d4;
P_0c0919d4: /* original 6db3, guest PC 0x0c0919d4 */
if(!s->budget--) { s->failed_pc=0x0c0919d4u; return 0; }
r[13]=r[11];
goto P_0c0919d6;
P_0c0919d6: /* original 6713, guest PC 0x0c0919d6 */
if(!s->budget--) { s->failed_pc=0x0c0919d6u; return 0; }
r[7]=r[1];
goto P_0c0919d8;
P_0c0919d8: /* original fa6c, guest PC 0x0c0919d8 */
if(!s->budget--) { s->failed_pc=0x0c0919d8u; return 0; }
vf3_matrix_move(s,10,6);
goto P_0c0919da;
P_0c0919da: /* original 7cff, guest PC 0x0c0919da */
if(!s->budget--) { s->failed_pc=0x0c0919dau; return 0; }
r[12]+=0xffffffffu;
goto P_0c0919dc;
P_0c0919dc: /* original 60c3, guest PC 0x0c0919dc */
if(!s->budget--) { s->failed_pc=0x0c0919dcu; return 0; }
r[0]=r[12];
goto P_0c0919de;
P_0c0919de: /* original 88ff, guest PC 0x0c0919de */
if(!s->budget--) { s->failed_pc=0x0c0919deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0919e0;
P_0c0919e0: /* original 710c, guest PC 0x0c0919e0 */
if(!s->budget--) { s->failed_pc=0x0c0919e0u; return 0; }
r[1]+=0x0000000cu;
goto P_0c0919e2;
P_0c0919e2: /* original 8fdc, guest PC 0x0c0919e2 */
if(!s->budget--) { s->failed_pc=0x0c0919e2u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(!cond) { goto P_0c09199e; }
goto P_0c0919e6;
P_0c0919e4: /* original 7b01, guest PC 0x0c0919e4 */
if(!s->budget--) { s->failed_pc=0x0c0919e4u; return 0; }
r[11]+=0x00000001u;
goto P_0c0919e6;
P_0c0919e6: /* original 2778, guest PC 0x0c0919e6 */
if(!s->budget--) { s->failed_pc=0x0c0919e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0919e8;
P_0c0919e8: /* original 8b01, guest PC 0x0c0919e8 */
if(!s->budget--) { s->failed_pc=0x0c0919e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0919ee; }
goto P_0c0919ea;
P_0c0919ea: /* original a080, guest PC 0x0c0919ea */
if(!s->budget--) { s->failed_pc=0x0c0919eau; return 0; }
goto P_0c091aee;
P_0c0919ec: /* original 0009, guest PC 0x0c0919ec */
if(!s->budget--) { s->failed_pc=0x0c0919ecu; return 0; }
goto P_0c0919ee;
P_0c0919ee: /* original 9262, guest PC 0x0c0919ee */
if(!s->budget--) { s->failed_pc=0x0c0919eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091ab6u,2);
goto P_0c0919f0;
P_0c0919f0: /* original 63d3, guest PC 0x0c0919f0 */
if(!s->budget--) { s->failed_pc=0x0c0919f0u; return 0; }
r[3]=r[13];
goto P_0c0919f2;
P_0c0919f2: /* original f35c, guest PC 0x0c0919f2 */
if(!s->budget--) { s->failed_pc=0x0c0919f2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0919f4;
P_0c0919f4: /* original 4308, guest PC 0x0c0919f4 */
if(!s->budget--) { s->failed_pc=0x0c0919f4u; return 0; }
r[3]<<=2;
goto P_0c0919f6;
P_0c0919f6: /* original 324c, guest PC 0x0c0919f6 */
if(!s->budget--) { s->failed_pc=0x0c0919f6u; return 0; }
r[2]+=r[4];
goto P_0c0919f8;
P_0c0919f8: /* original f532, guest PC 0x0c0919f8 */
if(!s->budget--) { s->failed_pc=0x0c0919f8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0919fa;
P_0c0919fa: /* original 332c, guest PC 0x0c0919fa */
if(!s->budget--) { s->failed_pc=0x0c0919fau; return 0; }
r[3]+=r[2];
goto P_0c0919fc;
P_0c0919fc: /* original f438, guest PC 0x0c0919fc */
if(!s->budget--) { s->failed_pc=0x0c0919fcu; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0919fe;
P_0c0919fe: /* original f04c, guest PC 0x0c0919fe */
if(!s->budget--) { s->failed_pc=0x0c0919feu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c091a00;
P_0c091a00: /* original f54e, guest PC 0x0c091a00 */
if(!s->budget--) { s->failed_pc=0x0c091a00u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c091a02;
P_0c091a02: /* original f95c, guest PC 0x0c091a02 */
if(!s->budget--) { s->failed_pc=0x0c091a02u; return 0; }
vf3_matrix_move(s,9,5);
goto P_0c091a04;
P_0c091a04: /* original fa95, guest PC 0x0c091a04 */
if(!s->budget--) { s->failed_pc=0x0c091a04u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[9]))!=0);
goto P_0c091a06;
P_0c091a06: /* original 8972, guest PC 0x0c091a06 */
if(!s->budget--) { s->failed_pc=0x0c091a06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091aee; }
goto P_0c091a08;
P_0c091a08: /* original e008, guest PC 0x0c091a08 */
if(!s->budget--) { s->failed_pc=0x0c091a08u; return 0; }
r[0]=0x00000008u;
goto P_0c091a0a;
P_0c091a0a: /* original f9a1, guest PC 0x0c091a0a */
if(!s->budget--) { s->failed_pc=0x0c091a0au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'-');
goto P_0c091a0c;
P_0c091a0c: /* original f676, guest PC 0x0c091a0c */
if(!s->budget--) { s->failed_pc=0x0c091a0cu; return 0; }
vf3_matrix_load(s,ram,6,r[7]+r[0]);
goto P_0c091a0e;
P_0c091a0e: /* original d02b, guest PC 0x0c091a0e */
if(!s->budget--) { s->failed_pc=0x0c091a0eu; return 0; }
r[0]=read(ram,0x0c091abcu,4);
goto P_0c091a10;
P_0c091a10: /* original f578, guest PC 0x0c091a10 */
if(!s->budget--) { s->failed_pc=0x0c091a10u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c091a12;
P_0c091a12: /* original 03dc, guest PC 0x0c091a12 */
if(!s->budget--) { s->failed_pc=0x0c091a12u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c091a14;
P_0c091a14: /* original 2f32, guest PC 0x0c091a14 */
if(!s->budget--) { s->failed_pc=0x0c091a14u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c091a16;
P_0c091a16: /* original 904d, guest PC 0x0c091a16 */
if(!s->budget--) { s->failed_pc=0x0c091a16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091ab4u,2);
goto P_0c091a18;
P_0c091a18: /* original 044e, guest PC 0x0c091a18 */
if(!s->budget--) { s->failed_pc=0x0c091a18u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c091a1a;
P_0c091a1a: /* original 6033, guest PC 0x0c091a1a */
if(!s->budget--) { s->failed_pc=0x0c091a1au; return 0; }
r[0]=r[3];
goto P_0c091a1c;
P_0c091a1c: /* original 4000, guest PC 0x0c091a1c */
if(!s->budget--) { s->failed_pc=0x0c091a1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091a1e;
P_0c091a1e: /* original 303c, guest PC 0x0c091a1e */
if(!s->budget--) { s->failed_pc=0x0c091a1eu; return 0; }
r[0]+=r[3];
goto P_0c091a20;
P_0c091a20: /* original 4008, guest PC 0x0c091a20 */
if(!s->budget--) { s->failed_pc=0x0c091a20u; return 0; }
r[0]<<=2;
goto P_0c091a22;
P_0c091a22: /* original 340c, guest PC 0x0c091a22 */
if(!s->budget--) { s->failed_pc=0x0c091a22u; return 0; }
r[4]+=r[0];
goto P_0c091a24;
P_0c091a24: /* original e008, guest PC 0x0c091a24 */
if(!s->budget--) { s->failed_pc=0x0c091a24u; return 0; }
r[0]=0x00000008u;
goto P_0c091a26;
P_0c091a26: /* original f448, guest PC 0x0c091a26 */
if(!s->budget--) { s->failed_pc=0x0c091a26u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c091a28;
P_0c091a28: /* original fa46, guest PC 0x0c091a28 */
if(!s->budget--) { s->failed_pc=0x0c091a28u; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c091a2a;
P_0c091a2a: /* original fb4c, guest PC 0x0c091a2a */
if(!s->budget--) { s->failed_pc=0x0c091a2au; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c091a2c;
P_0c091a2c: /* original f541, guest PC 0x0c091a2c */
if(!s->budget--) { s->failed_pc=0x0c091a2cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c091a2e;
P_0c091a2e: /* original f4ac, guest PC 0x0c091a2e */
if(!s->budget--) { s->failed_pc=0x0c091a2eu; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c091a30;
P_0c091a30: /* original f481, guest PC 0x0c091a30 */
if(!s->budget--) { s->failed_pc=0x0c091a30u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c091a32;
P_0c091a32: /* original f6a1, guest PC 0x0c091a32 */
if(!s->budget--) { s->failed_pc=0x0c091a32u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'-');
goto P_0c091a34;
P_0c091a34: /* original fb71, guest PC 0x0c091a34 */
if(!s->budget--) { s->failed_pc=0x0c091a34u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'-');
goto P_0c091a36;
P_0c091a36: /* original fa5c, guest PC 0x0c091a36 */
if(!s->budget--) { s->failed_pc=0x0c091a36u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c091a38;
P_0c091a38: /* original fa52, guest PC 0x0c091a38 */
if(!s->budget--) { s->failed_pc=0x0c091a38u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'*');
goto P_0c091a3a;
P_0c091a3a: /* original f34c, guest PC 0x0c091a3a */
if(!s->budget--) { s->failed_pc=0x0c091a3au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c091a3c;
P_0c091a3c: /* original f46c, guest PC 0x0c091a3c */
if(!s->budget--) { s->failed_pc=0x0c091a3cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c091a3e;
P_0c091a3e: /* original f432, guest PC 0x0c091a3e */
if(!s->budget--) { s->failed_pc=0x0c091a3eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c091a40;
P_0c091a40: /* original f0bc, guest PC 0x0c091a40 */
if(!s->budget--) { s->failed_pc=0x0c091a40u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c091a42;
P_0c091a42: /* original f24c, guest PC 0x0c091a42 */
if(!s->budget--) { s->failed_pc=0x0c091a42u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c091a44;
P_0c091a44: /* original f25e, guest PC 0x0c091a44 */
if(!s->budget--) { s->failed_pc=0x0c091a44u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c091a46;
P_0c091a46: /* original f42c, guest PC 0x0c091a46 */
if(!s->budget--) { s->failed_pc=0x0c091a46u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c091a48;
P_0c091a48: /* original f06c, guest PC 0x0c091a48 */
if(!s->budget--) { s->failed_pc=0x0c091a48u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c091a4a;
P_0c091a4a: /* original c71d, guest PC 0x0c091a4a */
if(!s->budget--) { s->failed_pc=0x0c091a4au; return 0; }
r[0]=code_base|0x00091ac0u;
goto P_0c091a4c;
P_0c091a4c: /* original f3ac, guest PC 0x0c091a4c */
if(!s->budget--) { s->failed_pc=0x0c091a4cu; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c091a4e;
P_0c091a4e: /* original f36e, guest PC 0x0c091a4e */
if(!s->budget--) { s->failed_pc=0x0c091a4eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c091a50;
P_0c091a50: /* original f18d, guest PC 0x0c091a50 */
if(!s->budget--) { s->failed_pc=0x0c091a50u; return 0; }
fr[1]=0;
goto P_0c091a52;
P_0c091a52: /* original fa3c, guest PC 0x0c091a52 */
if(!s->budget--) { s->failed_pc=0x0c091a52u; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c091a54;
P_0c091a54: /* original f38d, guest PC 0x0c091a54 */
if(!s->budget--) { s->failed_pc=0x0c091a54u; return 0; }
fr[3]=0;
goto P_0c091a56;
P_0c091a56: /* original f3a4, guest PC 0x0c091a56 */
if(!s->budget--) { s->failed_pc=0x0c091a56u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[10]))!=0);
goto P_0c091a58;
P_0c091a58: /* original 8d07, guest PC 0x0c091a58 */
if(!s->budget--) { s->failed_pc=0x0c091a58u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[0]);
if(cond) { goto P_0c091a6a; }
goto P_0c091a5c;
P_0c091a5a: /* original ff08, guest PC 0x0c091a5a */
if(!s->budget--) { s->failed_pc=0x0c091a5au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c091a5c;
P_0c091a5c: /* original ffa5, guest PC 0x0c091a5c */
if(!s->budget--) { s->failed_pc=0x0c091a5cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[10]))!=0);
goto P_0c091a5e;
P_0c091a5e: /* original 8b01, guest PC 0x0c091a5e */
if(!s->budget--) { s->failed_pc=0x0c091a5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091a64; }
goto P_0c091a60;
P_0c091a60: /* original a004, guest PC 0x0c091a60 */
if(!s->budget--) { s->failed_pc=0x0c091a60u; return 0; }
fr[11]=0;
goto P_0c091a6c;
P_0c091a62: /* original fb8d, guest PC 0x0c091a62 */
if(!s->budget--) { s->failed_pc=0x0c091a62u; return 0; }
fr[11]=0;
goto P_0c091a64;
P_0c091a64: /* original fbac, guest PC 0x0c091a64 */
if(!s->budget--) { s->failed_pc=0x0c091a64u; return 0; }
vf3_matrix_move(s,11,10);
goto P_0c091a66;
P_0c091a66: /* original a001, guest PC 0x0c091a66 */
if(!s->budget--) { s->failed_pc=0x0c091a66u; return 0; }
if(!vf3_fpu_fsrra(fr[11],r[18],&fr[11])) goto unsupported;
goto P_0c091a6c;
P_0c091a68: /* original fb7d, guest PC 0x0c091a68 */
if(!s->budget--) { s->failed_pc=0x0c091a68u; return 0; }
if(!vf3_fpu_fsrra(fr[11],r[18],&fr[11])) goto unsupported;
goto P_0c091a6a;
P_0c091a6a: /* original fb1c, guest PC 0x0c091a6a */
if(!s->budget--) { s->failed_pc=0x0c091a6au; return 0; }
vf3_matrix_move(s,11,1);
goto P_0c091a6c;
P_0c091a6c: /* original f34c, guest PC 0x0c091a6c */
if(!s->budget--) { s->failed_pc=0x0c091a6cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c091a6e;
P_0c091a6e: /* original e008, guest PC 0x0c091a6e */
if(!s->budget--) { s->failed_pc=0x0c091a6eu; return 0; }
r[0]=0x00000008u;
goto P_0c091a70;
P_0c091a70: /* original f4bc, guest PC 0x0c091a70 */
if(!s->budget--) { s->failed_pc=0x0c091a70u; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c091a72;
P_0c091a72: /* original f432, guest PC 0x0c091a72 */
if(!s->budget--) { s->failed_pc=0x0c091a72u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c091a74;
P_0c091a74: /* original fb78, guest PC 0x0c091a74 */
if(!s->budget--) { s->failed_pc=0x0c091a74u; return 0; }
vf3_matrix_load(s,ram,11,r[7]);
goto P_0c091a76;
P_0c091a76: /* original fa76, guest PC 0x0c091a76 */
if(!s->budget--) { s->failed_pc=0x0c091a76u; return 0; }
vf3_matrix_load(s,ram,10,r[7]+r[0]);
goto P_0c091a78;
P_0c091a78: /* original f04c, guest PC 0x0c091a78 */
if(!s->budget--) { s->failed_pc=0x0c091a78u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c091a7a;
P_0c091a7a: /* original fb5e, guest PC 0x0c091a7a */
if(!s->budget--) { s->failed_pc=0x0c091a7au; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[5],fr[11],r[18]);
goto P_0c091a7c;
P_0c091a7c: /* original fa6e, guest PC 0x0c091a7c */
if(!s->budget--) { s->failed_pc=0x0c091a7cu; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[6],fr[10],r[18]);
goto P_0c091a7e;
P_0c091a7e: /* original f5bc, guest PC 0x0c091a7e */
if(!s->budget--) { s->failed_pc=0x0c091a7eu; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c091a80;
P_0c091a80: /* original f754, guest PC 0x0c091a80 */
if(!s->budget--) { s->failed_pc=0x0c091a80u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])==as_float(fr[5]))!=0);
goto P_0c091a82;
P_0c091a82: /* original 8f07, guest PC 0x0c091a82 */
if(!s->budget--) { s->failed_pc=0x0c091a82u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,10);
if(!cond) { goto P_0c091a94; }
goto P_0c091a86;
P_0c091a84: /* original f4ac, guest PC 0x0c091a84 */
if(!s->budget--) { s->failed_pc=0x0c091a84u; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c091a86;
P_0c091a86: /* original f844, guest PC 0x0c091a86 */
if(!s->budget--) { s->failed_pc=0x0c091a86u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])==as_float(fr[4]))!=0);
goto P_0c091a88;
P_0c091a88: /* original 8b04, guest PC 0x0c091a88 */
if(!s->budget--) { s->failed_pc=0x0c091a88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091a94; }
goto P_0c091a8a;
P_0c091a8a: /* original c70e, guest PC 0x0c091a8a */
if(!s->budget--) { s->failed_pc=0x0c091a8au; return 0; }
r[0]=code_base|0x00091ac4u;
goto P_0c091a8c;
P_0c091a8c: /* original f51c, guest PC 0x0c091a8c */
if(!s->budget--) { s->failed_pc=0x0c091a8cu; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c091a8e;
P_0c091a8e: /* original f608, guest PC 0x0c091a8e */
if(!s->budget--) { s->failed_pc=0x0c091a8eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c091a90;
P_0c091a90: /* original a00c, guest PC 0x0c091a90 */
if(!s->budget--) { s->failed_pc=0x0c091a90u; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c091aac;
P_0c091a92: /* original f41c, guest PC 0x0c091a92 */
if(!s->budget--) { s->failed_pc=0x0c091a92u; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c091a94;
P_0c091a94: /* original f35c, guest PC 0x0c091a94 */
if(!s->budget--) { s->failed_pc=0x0c091a94u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c091a96;
P_0c091a96: /* original f57c, guest PC 0x0c091a96 */
if(!s->budget--) { s->failed_pc=0x0c091a96u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c091a98;
P_0c091a98: /* original f531, guest PC 0x0c091a98 */
if(!s->budget--) { s->failed_pc=0x0c091a98u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c091a9a;
P_0c091a9a: /* original f34c, guest PC 0x0c091a9a */
if(!s->budget--) { s->failed_pc=0x0c091a9au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c091a9c;
P_0c091a9c: /* original f48c, guest PC 0x0c091a9c */
if(!s->budget--) { s->failed_pc=0x0c091a9cu; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c091a9e;
P_0c091a9e: /* original f431, guest PC 0x0c091a9e */
if(!s->budget--) { s->failed_pc=0x0c091a9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c091aa0;
P_0c091aa0: /* original f65c, guest PC 0x0c091aa0 */
if(!s->budget--) { s->failed_pc=0x0c091aa0u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c091aa2;
P_0c091aa2: /* original f652, guest PC 0x0c091aa2 */
if(!s->budget--) { s->failed_pc=0x0c091aa2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c091aa4;
P_0c091aa4: /* original f04c, guest PC 0x0c091aa4 */
if(!s->budget--) { s->failed_pc=0x0c091aa4u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c091aa6;
P_0c091aa6: /* original f26c, guest PC 0x0c091aa6 */
if(!s->budget--) { s->failed_pc=0x0c091aa6u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c091aa8;
P_0c091aa8: /* original f24e, guest PC 0x0c091aa8 */
if(!s->budget--) { s->failed_pc=0x0c091aa8u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c091aaa;
P_0c091aaa: /* original f62c, guest PC 0x0c091aaa */
if(!s->budget--) { s->failed_pc=0x0c091aaau; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c091aac;
P_0c091aac: /* original ff65, guest PC 0x0c091aac */
if(!s->budget--) { s->failed_pc=0x0c091aacu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[6]))!=0);
goto P_0c091aae;
P_0c091aae: /* original 8b0b, guest PC 0x0c091aae */
if(!s->budget--) { s->failed_pc=0x0c091aaeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091ac8; }
goto P_0c091ab0;
P_0c091ab0: /* original a00b, guest PC 0x0c091ab0 */
if(!s->budget--) { s->failed_pc=0x0c091ab0u; return 0; }
fr[6]=0;
goto P_0c091aca;
P_0c091ab2: /* original f68d, guest PC 0x0c091ab2 */
if(!s->budget--) { s->failed_pc=0x0c091ab2u; return 0; }
fr[6]=0;
if(!vf3_matrix_family(0x0c091ab4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091ab4u; return 0; } return 1;
P_0c091ac8: /* original f67d, guest PC 0x0c091ac8 */
if(!s->budget--) { s->failed_pc=0x0c091ac8u; return 0; }
if(!vf3_fpu_fsrra(fr[6],r[18],&fr[6])) goto unsupported;
goto P_0c091aca;
P_0c091aca: /* original ff95, guest PC 0x0c091aca */
if(!s->budget--) { s->failed_pc=0x0c091acau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[9]))!=0);
goto P_0c091acc;
P_0c091acc: /* original f562, guest PC 0x0c091acc */
if(!s->budget--) { s->failed_pc=0x0c091accu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c091ace;
P_0c091ace: /* original 8f02, guest PC 0x0c091ace */
if(!s->budget--) { s->failed_pc=0x0c091aceu; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
if(!cond) { goto P_0c091ad6; }
goto P_0c091ad2;
P_0c091ad0: /* original f462, guest PC 0x0c091ad0 */
if(!s->budget--) { s->failed_pc=0x0c091ad0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c091ad2;
P_0c091ad2: /* original a002, guest PC 0x0c091ad2 */
if(!s->budget--) { s->failed_pc=0x0c091ad2u; return 0; }
fr[6]=0;
goto P_0c091ada;
P_0c091ad4: /* original f68d, guest PC 0x0c091ad4 */
if(!s->budget--) { s->failed_pc=0x0c091ad4u; return 0; }
fr[6]=0;
goto P_0c091ad6;
P_0c091ad6: /* original f69c, guest PC 0x0c091ad6 */
if(!s->budget--) { s->failed_pc=0x0c091ad6u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c091ad8;
P_0c091ad8: /* original f66d, guest PC 0x0c091ad8 */
if(!s->budget--) { s->failed_pc=0x0c091ad8u; return 0; }
fr[6]=vf3_fpu_sqrt(fr[6],r[18]);
goto P_0c091ada;
P_0c091ada: /* original c71b, guest PC 0x0c091ada */
if(!s->budget--) { s->failed_pc=0x0c091adau; return 0; }
r[0]=code_base|0x00091b48u;
goto P_0c091adc;
P_0c091adc: /* original f28c, guest PC 0x0c091adc */
if(!s->budget--) { s->failed_pc=0x0c091adcu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c091ade;
P_0c091ade: /* original f908, guest PC 0x0c091ade */
if(!s->budget--) { s->failed_pc=0x0c091adeu; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c091ae0;
P_0c091ae0: /* original f37c, guest PC 0x0c091ae0 */
if(!s->budget--) { s->failed_pc=0x0c091ae0u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c091ae2;
P_0c091ae2: /* original f692, guest PC 0x0c091ae2 */
if(!s->budget--) { s->failed_pc=0x0c091ae2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'*');
goto P_0c091ae4;
P_0c091ae4: /* original f06c, guest PC 0x0c091ae4 */
if(!s->budget--) { s->failed_pc=0x0c091ae4u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c091ae6;
P_0c091ae6: /* original f24e, guest PC 0x0c091ae6 */
if(!s->budget--) { s->failed_pc=0x0c091ae6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c091ae8;
P_0c091ae8: /* original f35e, guest PC 0x0c091ae8 */
if(!s->budget--) { s->failed_pc=0x0c091ae8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c091aea;
P_0c091aea: /* original f82c, guest PC 0x0c091aea */
if(!s->budget--) { s->failed_pc=0x0c091aeau; return 0; }
vf3_matrix_move(s,8,2);
goto P_0c091aec;
P_0c091aec: /* original f73c, guest PC 0x0c091aec */
if(!s->budget--) { s->failed_pc=0x0c091aecu; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c091aee;
P_0c091aee: /* original 7f04, guest PC 0x0c091aee */
if(!s->budget--) { s->failed_pc=0x0c091aeeu; return 0; }
r[15]+=0x00000004u;
goto P_0c091af0;
P_0c091af0: /* original f57a, guest PC 0x0c091af0 */
if(!s->budget--) { s->failed_pc=0x0c091af0u; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c091af2;
P_0c091af2: /* original f68a, guest PC 0x0c091af2 */
if(!s->budget--) { s->failed_pc=0x0c091af2u; return 0; }
vf3_matrix_store(s,ram,8,r[6]);
goto P_0c091af4;
P_0c091af4: /* original fff9, guest PC 0x0c091af4 */
if(!s->budget--) { s->failed_pc=0x0c091af4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091af6;
P_0c091af6: /* original 6bf6, guest PC 0x0c091af6 */
if(!s->budget--) { s->failed_pc=0x0c091af6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c091af8;
P_0c091af8: /* original 6cf6, guest PC 0x0c091af8 */
if(!s->budget--) { s->failed_pc=0x0c091af8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091afa;
P_0c091afa: /* original 000b, guest PC 0x0c091afa */
if(!s->budget--) { s->failed_pc=0x0c091afau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c091afc: /* original 6df6, guest PC 0x0c091afc */
if(!s->budget--) { s->failed_pc=0x0c091afcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c091afeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091afeu; return 0; } return 1;
P_0c0a7662: /* original 2fe6, guest PC 0x0c0a7662 */
if(!s->budget--) { s->failed_pc=0x0c0a7662u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7664;
P_0c0a7664: /* original 932b, guest PC 0x0c0a7664 */
if(!s->budget--) { s->failed_pc=0x0c0a7664u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7666;
P_0c0a7666: /* original 4f22, guest PC 0x0c0a7666 */
if(!s->budget--) { s->failed_pc=0x0c0a7666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7668;
P_0c0a7668: /* original 3433, guest PC 0x0c0a7668 */
if(!s->budget--) { s->failed_pc=0x0c0a7668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a766a;
P_0c0a766a: /* original 8925, guest PC 0x0c0a766a */
if(!s->budget--) { s->failed_pc=0x0c0a766au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a766c;
P_0c0a766c: /* original d014, guest PC 0x0c0a766c */
if(!s->budget--) { s->failed_pc=0x0c0a766cu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a766e;
P_0c0a766e: /* original 6e43, guest PC 0x0c0a766e */
if(!s->budget--) { s->failed_pc=0x0c0a766eu; return 0; }
r[14]=r[4];
goto P_0c0a7670;
P_0c0a7670: /* original 4e08, guest PC 0x0c0a7670 */
if(!s->budget--) { s->failed_pc=0x0c0a7670u; return 0; }
r[14]<<=2;
goto P_0c0a7672;
P_0c0a7672: /* original 0eee, guest PC 0x0c0a7672 */
if(!s->budget--) { s->failed_pc=0x0c0a7672u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7674;
P_0c0a7674: /* original 2ee8, guest PC 0x0c0a7674 */
if(!s->budget--) { s->failed_pc=0x0c0a7674u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7676;
P_0c0a7676: /* original 891f, guest PC 0x0c0a7676 */
if(!s->budget--) { s->failed_pc=0x0c0a7676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a7678;
P_0c0a7678: /* original 60e3, guest PC 0x0c0a7678 */
if(!s->budget--) { s->failed_pc=0x0c0a7678u; return 0; }
r[0]=r[14];
goto P_0c0a767a;
P_0c0a767a: /* original 88ff, guest PC 0x0c0a767a */
if(!s->budget--) { s->failed_pc=0x0c0a767au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a767c;
P_0c0a767c: /* original 891c, guest PC 0x0c0a767c */
if(!s->budget--) { s->failed_pc=0x0c0a767cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a767e;
P_0c0a767e: /* original d311, guest PC 0x0c0a767e */
if(!s->budget--) { s->failed_pc=0x0c0a767eu; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7680;
P_0c0a7680: /* original 430b, guest PC 0x0c0a7680 */
if(!s->budget--) { s->failed_pc=0x0c0a7680u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7684u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7684u) { target=s->pc; goto dispatch; }
goto P_0c0a7684;
P_0c0a7682: /* original e400, guest PC 0x0c0a7682 */
if(!s->budget--) { s->failed_pc=0x0c0a7682u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7684;
P_0c0a7684: /* original d211, guest PC 0x0c0a7684 */
if(!s->budget--) { s->failed_pc=0x0c0a7684u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7686;
P_0c0a7686: /* original d410, guest PC 0x0c0a7686 */
if(!s->budget--) { s->failed_pc=0x0c0a7686u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a7688;
P_0c0a7688: /* original 420b, guest PC 0x0c0a7688 */
if(!s->budget--) { s->failed_pc=0x0c0a7688u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a768cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a768cu) { target=s->pc; goto dispatch; }
goto P_0c0a768c;
P_0c0a768a: /* original 0009, guest PC 0x0c0a768a */
if(!s->budget--) { s->failed_pc=0x0c0a768au; return 0; }
goto P_0c0a768c;
P_0c0a768c: /* original 50e1, guest PC 0x0c0a768c */
if(!s->budget--) { s->failed_pc=0x0c0a768cu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a768e;
P_0c0a768e: /* original c801, guest PC 0x0c0a768e */
if(!s->budget--) { s->failed_pc=0x0c0a768eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7690;
P_0c0a7690: /* original 8904, guest PC 0x0c0a7690 */
if(!s->budget--) { s->failed_pc=0x0c0a7690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a769c; }
goto P_0c0a7692;
P_0c0a7692: /* original d213, guest PC 0x0c0a7692 */
if(!s->budget--) { s->failed_pc=0x0c0a7692u; return 0; }
r[2]=read(ram,0x0c0a76e0u,4);
goto P_0c0a7694;
P_0c0a7694: /* original 420b, guest PC 0x0c0a7694 */
if(!s->budget--) { s->failed_pc=0x0c0a7694u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7698u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7698u) { target=s->pc; goto dispatch; }
goto P_0c0a7698;
P_0c0a7696: /* original 64e3, guest PC 0x0c0a7696 */
if(!s->budget--) { s->failed_pc=0x0c0a7696u; return 0; }
r[4]=r[14];
goto P_0c0a7698;
P_0c0a7698: /* original a009, guest PC 0x0c0a7698 */
if(!s->budget--) { s->failed_pc=0x0c0a7698u; return 0; }
goto P_0c0a76ae;
P_0c0a769a: /* original 0009, guest PC 0x0c0a769a */
if(!s->budget--) { s->failed_pc=0x0c0a769au; return 0; }
goto P_0c0a769c;
P_0c0a769c: /* original d20d, guest PC 0x0c0a769c */
if(!s->budget--) { s->failed_pc=0x0c0a769cu; return 0; }
r[2]=read(ram,0x0c0a76d4u,4);
goto P_0c0a769e;
P_0c0a769e: /* original 420b, guest PC 0x0c0a769e */
if(!s->budget--) { s->failed_pc=0x0c0a769eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a76a2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76a2u) { target=s->pc; goto dispatch; }
goto P_0c0a76a2;
P_0c0a76a0: /* original 0009, guest PC 0x0c0a76a0 */
if(!s->budget--) { s->failed_pc=0x0c0a76a0u; return 0; }
goto P_0c0a76a2;
P_0c0a76a2: /* original d310, guest PC 0x0c0a76a2 */
if(!s->budget--) { s->failed_pc=0x0c0a76a2u; return 0; }
r[3]=read(ram,0x0c0a76e4u,4);
goto P_0c0a76a4;
P_0c0a76a4: /* original 23e8, guest PC 0x0c0a76a4 */
if(!s->budget--) { s->failed_pc=0x0c0a76a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a76a6;
P_0c0a76a6: /* original 8902, guest PC 0x0c0a76a6 */
if(!s->budget--) { s->failed_pc=0x0c0a76a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76ae; }
goto P_0c0a76a8;
P_0c0a76a8: /* original d30f, guest PC 0x0c0a76a8 */
if(!s->budget--) { s->failed_pc=0x0c0a76a8u; return 0; }
r[3]=read(ram,0x0c0a76e8u,4);
goto P_0c0a76aa;
P_0c0a76aa: /* original 430b, guest PC 0x0c0a76aa */
if(!s->budget--) { s->failed_pc=0x0c0a76aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76aeu) { target=s->pc; goto dispatch; }
goto P_0c0a76ae;
P_0c0a76ac: /* original 64e3, guest PC 0x0c0a76ac */
if(!s->budget--) { s->failed_pc=0x0c0a76acu; return 0; }
r[4]=r[14];
goto P_0c0a76ae;
P_0c0a76ae: /* original 4f26, guest PC 0x0c0a76ae */
if(!s->budget--) { s->failed_pc=0x0c0a76aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76b0;
P_0c0a76b0: /* original d30a, guest PC 0x0c0a76b0 */
if(!s->budget--) { s->failed_pc=0x0c0a76b0u; return 0; }
r[3]=read(ram,0x0c0a76dcu,4);
goto P_0c0a76b2;
P_0c0a76b2: /* original e401, guest PC 0x0c0a76b2 */
if(!s->budget--) { s->failed_pc=0x0c0a76b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a76b4;
P_0c0a76b4: /* original 432b, guest PC 0x0c0a76b4 */
if(!s->budget--) { s->failed_pc=0x0c0a76b4u; return 0; }
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
P_0c0a76b6: /* original 6ef6, guest PC 0x0c0a76b6 */
if(!s->budget--) { s->failed_pc=0x0c0a76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a76b8;
P_0c0a76b8: /* original 4f26, guest PC 0x0c0a76b8 */
if(!s->budget--) { s->failed_pc=0x0c0a76b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76ba;
P_0c0a76ba: /* original 000b, guest PC 0x0c0a76ba */
if(!s->budget--) { s->failed_pc=0x0c0a76bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a76bc: /* original 6ef6, guest PC 0x0c0a76bc */
if(!s->budget--) { s->failed_pc=0x0c0a76bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a76beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a76beu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
