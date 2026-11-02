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
int vf3_away_batch116_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038760u: goto P_0c038760;
case 0x0c038762u: goto P_0c038762;
case 0x0c038764u: goto P_0c038764;
case 0x0c038860u: goto P_0c038860;
case 0x0c038862u: goto P_0c038862;
case 0x0c038864u: goto P_0c038864;
case 0x0c038866u: goto P_0c038866;
case 0x0c038868u: goto P_0c038868;
case 0x0c03886au: goto P_0c03886a;
case 0x0c03886cu: goto P_0c03886c;
case 0x0c03886eu: goto P_0c03886e;
case 0x0c038870u: goto P_0c038870;
case 0x0c038872u: goto P_0c038872;
case 0x0c038874u: goto P_0c038874;
case 0x0c038876u: goto P_0c038876;
case 0x0c038878u: goto P_0c038878;
case 0x0c03887au: goto P_0c03887a;
case 0x0c03887cu: goto P_0c03887c;
case 0x0c038880u: goto P_0c038880;
case 0x0c038882u: goto P_0c038882;
case 0x0c038884u: goto P_0c038884;
case 0x0c038886u: goto P_0c038886;
case 0x0c038888u: goto P_0c038888;
case 0x0c03888au: goto P_0c03888a;
case 0x0c03888cu: goto P_0c03888c;
case 0x0c03888eu: goto P_0c03888e;
case 0x0c038890u: goto P_0c038890;
case 0x0c038892u: goto P_0c038892;
case 0x0c038894u: goto P_0c038894;
case 0x0c038896u: goto P_0c038896;
case 0x0c038898u: goto P_0c038898;
case 0x0c03889au: goto P_0c03889a;
case 0x0c03889cu: goto P_0c03889c;
case 0x0c03889eu: goto P_0c03889e;
case 0x0c0388a0u: goto P_0c0388a0;
case 0x0c0388b0u: goto P_0c0388b0;
case 0x0c0388b2u: goto P_0c0388b2;
case 0x0c0388b4u: goto P_0c0388b4;
case 0x0c0388c0u: goto P_0c0388c0;
case 0x0c0388c2u: goto P_0c0388c2;
case 0x0c0388c4u: goto P_0c0388c4;
case 0x0c0388c6u: goto P_0c0388c6;
case 0x0c0388c8u: goto P_0c0388c8;
case 0x0c0388cau: goto P_0c0388ca;
case 0x0c0388ccu: goto P_0c0388cc;
case 0x0c0388ceu: goto P_0c0388ce;
case 0x0c0388d0u: goto P_0c0388d0;
case 0x0c0388d2u: goto P_0c0388d2;
case 0x0c0388d4u: goto P_0c0388d4;
case 0x0c0388d6u: goto P_0c0388d6;
case 0x0c0388d8u: goto P_0c0388d8;
case 0x0c0388dau: goto P_0c0388da;
case 0x0c0388dcu: goto P_0c0388dc;
case 0x0c038950u: goto P_0c038950;
case 0x0c038952u: goto P_0c038952;
case 0x0c038954u: goto P_0c038954;
case 0x0c038956u: goto P_0c038956;
case 0x0c038958u: goto P_0c038958;
case 0x0c03895au: goto P_0c03895a;
case 0x0c03895cu: goto P_0c03895c;
case 0x0c03895eu: goto P_0c03895e;
case 0x0c038960u: goto P_0c038960;
case 0x0c038962u: goto P_0c038962;
case 0x0c038964u: goto P_0c038964;
case 0x0c038966u: goto P_0c038966;
case 0x0c038970u: goto P_0c038970;
case 0x0c038972u: goto P_0c038972;
case 0x0c038974u: goto P_0c038974;
case 0x0c038976u: goto P_0c038976;
case 0x0c038978u: goto P_0c038978;
case 0x0c03897au: goto P_0c03897a;
case 0x0c03897cu: goto P_0c03897c;
case 0x0c03897eu: goto P_0c03897e;
case 0x0c038980u: goto P_0c038980;
case 0x0c038982u: goto P_0c038982;
case 0x0c038984u: goto P_0c038984;
case 0x0c038986u: goto P_0c038986;
case 0x0c038988u: goto P_0c038988;
case 0x0c03898au: goto P_0c03898a;
case 0x0c03898cu: goto P_0c03898c;
case 0x0c038990u: goto P_0c038990;
case 0x0c038992u: goto P_0c038992;
case 0x0c038994u: goto P_0c038994;
case 0x0c038996u: goto P_0c038996;
case 0x0c038998u: goto P_0c038998;
case 0x0c0389a0u: goto P_0c0389a0;
case 0x0c0389a2u: goto P_0c0389a2;
case 0x0c0389a4u: goto P_0c0389a4;
case 0x0c0389a6u: goto P_0c0389a6;
case 0x0c0389b0u: goto P_0c0389b0;
case 0x0c0389b2u: goto P_0c0389b2;
case 0x0c0389b4u: goto P_0c0389b4;
case 0x0c0389b6u: goto P_0c0389b6;
case 0x0c0389b8u: goto P_0c0389b8;
case 0x0c0389c0u: goto P_0c0389c0;
case 0x0c0389c2u: goto P_0c0389c2;
case 0x0c0389c4u: goto P_0c0389c4;
case 0x0c0389c6u: goto P_0c0389c6;
case 0x0c0389e0u: goto P_0c0389e0;
case 0x0c0389e2u: goto P_0c0389e2;
case 0x0c0389e4u: goto P_0c0389e4;
case 0x0c0389e6u: goto P_0c0389e6;
case 0x0c0389e8u: goto P_0c0389e8;
case 0x0c0389f0u: goto P_0c0389f0;
case 0x0c0389f2u: goto P_0c0389f2;
case 0x0c0389f4u: goto P_0c0389f4;
case 0x0c0389f6u: goto P_0c0389f6;
case 0x0c0389f8u: goto P_0c0389f8;
case 0x0c038a00u: goto P_0c038a00;
case 0x0c038a02u: goto P_0c038a02;
case 0x0c038a04u: goto P_0c038a04;
case 0x0c038a06u: goto P_0c038a06;
case 0x0c038a08u: goto P_0c038a08;
case 0x0c038a10u: goto P_0c038a10;
case 0x0c038a12u: goto P_0c038a12;
case 0x0c038a14u: goto P_0c038a14;
case 0x0c038a16u: goto P_0c038a16;
case 0x0c038a18u: goto P_0c038a18;
case 0x0c038a1au: goto P_0c038a1a;
case 0x0c038a20u: goto P_0c038a20;
case 0x0c038a22u: goto P_0c038a22;
case 0x0c038a24u: goto P_0c038a24;
case 0x0c038a26u: goto P_0c038a26;
case 0x0c038a28u: goto P_0c038a28;
case 0x0c038a2au: goto P_0c038a2a;
case 0x0c038a2cu: goto P_0c038a2c;
case 0x0c038a2eu: goto P_0c038a2e;
case 0x0c038a30u: goto P_0c038a30;
case 0x0c038a32u: goto P_0c038a32;
case 0x0c038a34u: goto P_0c038a34;
case 0x0c038a36u: goto P_0c038a36;
case 0x0c038a38u: goto P_0c038a38;
case 0x0c038a3au: goto P_0c038a3a;
case 0x0c038a3cu: goto P_0c038a3c;
case 0x0c038a3eu: goto P_0c038a3e;
case 0x0c038a40u: goto P_0c038a40;
case 0x0c038a42u: goto P_0c038a42;
case 0x0c038a44u: goto P_0c038a44;
case 0x0c038a80u: goto P_0c038a80;
case 0x0c038a82u: goto P_0c038a82;
case 0x0c038a84u: goto P_0c038a84;
case 0x0c038a86u: goto P_0c038a86;
case 0x0c038a88u: goto P_0c038a88;
case 0x0c038a8au: goto P_0c038a8a;
case 0x0c038a8cu: goto P_0c038a8c;
case 0x0c038a8eu: goto P_0c038a8e;
case 0x0c038a90u: goto P_0c038a90;
case 0x0c038a92u: goto P_0c038a92;
case 0x0c038a94u: goto P_0c038a94;
case 0x0c038a96u: goto P_0c038a96;
case 0x0c038a98u: goto P_0c038a98;
case 0x0c038a9au: goto P_0c038a9a;
case 0x0c038a9cu: goto P_0c038a9c;
case 0x0c038a9eu: goto P_0c038a9e;
case 0x0c038aa0u: goto P_0c038aa0;
case 0x0c038aa2u: goto P_0c038aa2;
case 0x0c038aa4u: goto P_0c038aa4;
case 0x0c038aa6u: goto P_0c038aa6;
case 0x0c038aa8u: goto P_0c038aa8;
case 0x0c038aaau: goto P_0c038aaa;
case 0x0c038aacu: goto P_0c038aac;
case 0x0c038aaeu: goto P_0c038aae;
case 0x0c038ab0u: goto P_0c038ab0;
case 0x0c038ab2u: goto P_0c038ab2;
case 0x0c038ab4u: goto P_0c038ab4;
case 0x0c038ab6u: goto P_0c038ab6;
case 0x0c038ab8u: goto P_0c038ab8;
case 0x0c038abau: goto P_0c038aba;
case 0x0c038abcu: goto P_0c038abc;
case 0x0c038abeu: goto P_0c038abe;
case 0x0c038ac0u: goto P_0c038ac0;
case 0x0c038ac2u: goto P_0c038ac2;
case 0x0c038ac4u: goto P_0c038ac4;
case 0x0c038ac6u: goto P_0c038ac6;
case 0x0c038ac8u: goto P_0c038ac8;
case 0x0c038acau: goto P_0c038aca;
case 0x0c038accu: goto P_0c038acc;
case 0x0c038aceu: goto P_0c038ace;
case 0x0c038ad0u: goto P_0c038ad0;
case 0x0c038ad2u: goto P_0c038ad2;
case 0x0c038ad4u: goto P_0c038ad4;
case 0x0c038ad6u: goto P_0c038ad6;
case 0x0c038ad8u: goto P_0c038ad8;
case 0x0c038adau: goto P_0c038ada;
case 0x0c038adcu: goto P_0c038adc;
case 0x0c038adeu: goto P_0c038ade;
case 0x0c038ae0u: goto P_0c038ae0;
case 0x0c038ae2u: goto P_0c038ae2;
case 0x0c038ae4u: goto P_0c038ae4;
case 0x0c038ae6u: goto P_0c038ae6;
case 0x0c038ae8u: goto P_0c038ae8;
case 0x0c038aeau: goto P_0c038aea;
case 0x0c038aecu: goto P_0c038aec;
case 0x0c038aeeu: goto P_0c038aee;
case 0x0c038af0u: goto P_0c038af0;
case 0x0c038b10u: goto P_0c038b10;
case 0x0c038b12u: goto P_0c038b12;
case 0x0c038b14u: goto P_0c038b14;
case 0x0c038b16u: goto P_0c038b16;
case 0x0c038b18u: goto P_0c038b18;
case 0x0c038b1au: goto P_0c038b1a;
case 0x0c038b1cu: goto P_0c038b1c;
case 0x0c038b1eu: goto P_0c038b1e;
case 0x0c038b20u: goto P_0c038b20;
case 0x0c038b22u: goto P_0c038b22;
case 0x0c038b24u: goto P_0c038b24;
case 0x0c038b26u: goto P_0c038b26;
case 0x0c038b30u: goto P_0c038b30;
case 0x0c038b32u: goto P_0c038b32;
case 0x0c038b34u: goto P_0c038b34;
case 0x0c038b36u: goto P_0c038b36;
case 0x0c038b38u: goto P_0c038b38;
case 0x0c038b3au: goto P_0c038b3a;
case 0x0c038b3cu: goto P_0c038b3c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c038760: /* original d23a, guest PC 0x0c038760 */
if(!s->budget--) { s->failed_pc=0x0c038760u; return 0; }
r[2]=read(ram,0x0c03884cu,4);
goto P_0c038762;
P_0c038762: /* original 000b, guest PC 0x0c038762 */
if(!s->budget--) { s->failed_pc=0x0c038762u; return 0; }
target=r[16];
write(ram,r[2],r[4],4);
s->pc=target; return ram->oob==0;
P_0c038764: /* original 2242, guest PC 0x0c038764 */
if(!s->budget--) { s->failed_pc=0x0c038764u; return 0; }
write(ram,r[2],r[4],4);
if(!vf3_matrix_family(0x0c038766u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038766u; return 0; } return 1;
P_0c038860: /* original 2fe6, guest PC 0x0c038860 */
if(!s->budget--) { s->failed_pc=0x0c038860u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038862;
P_0c038862: /* original e700, guest PC 0x0c038862 */
if(!s->budget--) { s->failed_pc=0x0c038862u; return 0; }
r[7]=0x00000000u;
goto P_0c038864;
P_0c038864: /* original 2fd6, guest PC 0x0c038864 */
if(!s->budget--) { s->failed_pc=0x0c038864u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038866;
P_0c038866: /* original 6573, guest PC 0x0c038866 */
if(!s->budget--) { s->failed_pc=0x0c038866u; return 0; }
r[5]=r[7];
goto P_0c038868;
P_0c038868: /* original 2fb6, guest PC 0x0c038868 */
if(!s->budget--) { s->failed_pc=0x0c038868u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03886a;
P_0c03886a: /* original 6e73, guest PC 0x0c03886a */
if(!s->budget--) { s->failed_pc=0x0c03886au; return 0; }
r[14]=r[7];
goto P_0c03886c;
P_0c03886c: /* original 2fa6, guest PC 0x0c03886c */
if(!s->budget--) { s->failed_pc=0x0c03886cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03886e;
P_0c03886e: /* original 6a73, guest PC 0x0c03886e */
if(!s->budget--) { s->failed_pc=0x0c03886eu; return 0; }
r[10]=r[7];
goto P_0c038870;
P_0c038870: /* original 2f96, guest PC 0x0c038870 */
if(!s->budget--) { s->failed_pc=0x0c038870u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038872;
P_0c038872: /* original e901, guest PC 0x0c038872 */
if(!s->budget--) { s->failed_pc=0x0c038872u; return 0; }
r[9]=0x00000001u;
goto P_0c038874;
P_0c038874: /* original 2f86, guest PC 0x0c038874 */
if(!s->budget--) { s->failed_pc=0x0c038874u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038876;
P_0c038876: /* original d854, guest PC 0x0c038876 */
if(!s->budget--) { s->failed_pc=0x0c038876u; return 0; }
r[8]=read(ram,0x0c0389c8u,4);
goto P_0c038878;
P_0c038878: /* original dd54, guest PC 0x0c038878 */
if(!s->budget--) { s->failed_pc=0x0c038878u; return 0; }
r[13]=read(ram,0x0c0389ccu,4);
goto P_0c03887a;
P_0c03887a: /* original a025, guest PC 0x0c03887a */
if(!s->budget--) { s->failed_pc=0x0c03887au; return 0; }
r[11]=r[7];
goto P_0c0388c8;
P_0c03887c: /* original 6b73, guest PC 0x0c03887c */
if(!s->budget--) { s->failed_pc=0x0c03887cu; return 0; }
r[11]=r[7];
if(!vf3_matrix_family(0x0c03887eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03887eu; return 0; } return 1;
P_0c038880: /* original 60d2, guest PC 0x0c038880 */
if(!s->budget--) { s->failed_pc=0x0c038880u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c038882;
P_0c038882: /* original 00be, guest PC 0x0c038882 */
if(!s->budget--) { s->failed_pc=0x0c038882u; return 0; }
r[0]=read(ram,r[11]+r[0],4);
goto P_0c038884;
P_0c038884: /* original 88ff, guest PC 0x0c038884 */
if(!s->budget--) { s->failed_pc=0x0c038884u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c038886;
P_0c038886: /* original 8d1b, guest PC 0x0c038886 */
if(!s->budget--) { s->failed_pc=0x0c038886u; return 0; }
cond=r[17]&1u;
r[1]=r[0];
if(cond) { goto P_0c0388c0; }
goto P_0c03888a;
P_0c038888: /* original 6103, guest PC 0x0c038888 */
if(!s->budget--) { s->failed_pc=0x0c038888u; return 0; }
r[1]=r[0];
goto P_0c03888a;
P_0c03888a: /* original 6493, guest PC 0x0c03888a */
if(!s->budget--) { s->failed_pc=0x0c03888au; return 0; }
r[4]=r[9];
goto P_0c03888c;
P_0c03888c: /* original 6673, guest PC 0x0c03888c */
if(!s->budget--) { s->failed_pc=0x0c03888cu; return 0; }
r[6]=r[7];
goto P_0c03888e;
P_0c03888e: /* original 6213, guest PC 0x0c03888e */
if(!s->budget--) { s->failed_pc=0x0c03888eu; return 0; }
r[2]=r[1];
goto P_0c038890;
P_0c038890: /* original 2248, guest PC 0x0c038890 */
if(!s->budget--) { s->failed_pc=0x0c038890u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c038892;
P_0c038892: /* original 8b0d, guest PC 0x0c038892 */
if(!s->budget--) { s->failed_pc=0x0c038892u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0388b0; }
goto P_0c038894;
P_0c038894: /* original 60d2, guest PC 0x0c038894 */
if(!s->budget--) { s->failed_pc=0x0c038894u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c038896;
P_0c038896: /* original 02ee, guest PC 0x0c038896 */
if(!s->budget--) { s->failed_pc=0x0c038896u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c038898;
P_0c038898: /* original 224b, guest PC 0x0c038898 */
if(!s->budget--) { s->failed_pc=0x0c038898u; return 0; }
r[2]|=r[4];
goto P_0c03889a;
P_0c03889a: /* original 0e26, guest PC 0x0c03889a */
if(!s->budget--) { s->failed_pc=0x0c03889au; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03889c;
P_0c03889c: /* original 6053, guest PC 0x0c03889c */
if(!s->budget--) { s->failed_pc=0x0c03889cu; return 0; }
r[0]=r[5];
goto P_0c03889e;
P_0c03889e: /* original a017, guest PC 0x0c03889e */
if(!s->budget--) { s->failed_pc=0x0c03889eu; return 0; }
r[0]+=r[6];
goto P_0c0388d0;
P_0c0388a0: /* original 306c, guest PC 0x0c0388a0 */
if(!s->budget--) { s->failed_pc=0x0c0388a0u; return 0; }
r[0]+=r[6];
if(!vf3_matrix_family(0x0c0388a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388a2u; return 0; } return 1;
P_0c0388b0: /* original 4400, guest PC 0x0c0388b0 */
if(!s->budget--) { s->failed_pc=0x0c0388b0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0388b2;
P_0c0388b2: /* original afec, guest PC 0x0c0388b2 */
if(!s->budget--) { s->failed_pc=0x0c0388b2u; return 0; }
r[6]+=0x00000001u;
goto P_0c03888e;
P_0c0388b4: /* original 7601, guest PC 0x0c0388b4 */
if(!s->budget--) { s->failed_pc=0x0c0388b4u; return 0; }
r[6]+=0x00000001u;
if(!vf3_matrix_family(0x0c0388b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388b6u; return 0; } return 1;
P_0c0388c0: /* original 7e04, guest PC 0x0c0388c0 */
if(!s->budget--) { s->failed_pc=0x0c0388c0u; return 0; }
r[14]+=0x00000004u;
goto P_0c0388c2;
P_0c0388c2: /* original 7b04, guest PC 0x0c0388c2 */
if(!s->budget--) { s->failed_pc=0x0c0388c2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0388c4;
P_0c0388c4: /* original 7a01, guest PC 0x0c0388c4 */
if(!s->budget--) { s->failed_pc=0x0c0388c4u; return 0; }
r[10]+=0x00000001u;
goto P_0c0388c6;
P_0c0388c6: /* original 7520, guest PC 0x0c0388c6 */
if(!s->budget--) { s->failed_pc=0x0c0388c6u; return 0; }
r[5]+=0x00000020u;
goto P_0c0388c8;
P_0c0388c8: /* original 6382, guest PC 0x0c0388c8 */
if(!s->budget--) { s->failed_pc=0x0c0388c8u; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c0388ca;
P_0c0388ca: /* original 3a33, guest PC 0x0c0388ca */
if(!s->budget--) { s->failed_pc=0x0c0388cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0388cc;
P_0c0388cc: /* original 8bd8, guest PC 0x0c0388cc */
if(!s->budget--) { s->failed_pc=0x0c0388ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038880; }
goto P_0c0388ce;
P_0c0388ce: /* original e0ff, guest PC 0x0c0388ce */
if(!s->budget--) { s->failed_pc=0x0c0388ceu; return 0; }
r[0]=0xffffffffu;
goto P_0c0388d0;
P_0c0388d0: /* original 68f6, guest PC 0x0c0388d0 */
if(!s->budget--) { s->failed_pc=0x0c0388d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0388d2;
P_0c0388d2: /* original 69f6, guest PC 0x0c0388d2 */
if(!s->budget--) { s->failed_pc=0x0c0388d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0388d4;
P_0c0388d4: /* original 6af6, guest PC 0x0c0388d4 */
if(!s->budget--) { s->failed_pc=0x0c0388d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0388d6;
P_0c0388d6: /* original 6bf6, guest PC 0x0c0388d6 */
if(!s->budget--) { s->failed_pc=0x0c0388d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0388d8;
P_0c0388d8: /* original 6df6, guest PC 0x0c0388d8 */
if(!s->budget--) { s->failed_pc=0x0c0388d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0388da;
P_0c0388da: /* original 000b, guest PC 0x0c0388da */
if(!s->budget--) { s->failed_pc=0x0c0388dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0388dc: /* original 6ef6, guest PC 0x0c0388dc */
if(!s->budget--) { s->failed_pc=0x0c0388dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0388deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388deu; return 0; } return 1;
P_0c038950: /* original 2fe6, guest PC 0x0c038950 */
if(!s->budget--) { s->failed_pc=0x0c038950u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038952;
P_0c038952: /* original 2fd6, guest PC 0x0c038952 */
if(!s->budget--) { s->failed_pc=0x0c038952u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038954;
P_0c038954: /* original 2fc6, guest PC 0x0c038954 */
if(!s->budget--) { s->failed_pc=0x0c038954u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038956;
P_0c038956: /* original 4f22, guest PC 0x0c038956 */
if(!s->budget--) { s->failed_pc=0x0c038956u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038958;
P_0c038958: /* original d31f, guest PC 0x0c038958 */
if(!s->budget--) { s->failed_pc=0x0c038958u; return 0; }
r[3]=read(ram,0x0c0389d8u,4);
goto P_0c03895a;
P_0c03895a: /* original 430b, guest PC 0x0c03895a */
if(!s->budget--) { s->failed_pc=0x0c03895au; return 0; }
target=r[3];
r[16]=code_base|0x0c03895eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03895eu) { target=s->pc; goto dispatch; }
goto P_0c03895e;
P_0c03895c: /* original 0009, guest PC 0x0c03895c */
if(!s->budget--) { s->failed_pc=0x0c03895cu; return 0; }
goto P_0c03895e;
P_0c03895e: /* original d21d, guest PC 0x0c03895e */
if(!s->budget--) { s->failed_pc=0x0c03895eu; return 0; }
r[2]=read(ram,0x0c0389d4u,4);
goto P_0c038960;
P_0c038960: /* original dc1e, guest PC 0x0c038960 */
if(!s->budget--) { s->failed_pc=0x0c038960u; return 0; }
r[12]=read(ram,0x0c0389dcu,4);
goto P_0c038962;
P_0c038962: /* original 6e22, guest PC 0x0c038962 */
if(!s->budget--) { s->failed_pc=0x0c038962u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c038964;
P_0c038964: /* original a00b, guest PC 0x0c038964 */
if(!s->budget--) { s->failed_pc=0x0c038964u; return 0; }
r[13]=0x00000000u;
goto P_0c03897e;
P_0c038966: /* original ed00, guest PC 0x0c038966 */
if(!s->budget--) { s->failed_pc=0x0c038966u; return 0; }
r[13]=0x00000000u;
if(!vf3_matrix_family(0x0c038968u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038968u; return 0; } return 1;
P_0c038970: /* original 52ea, guest PC 0x0c038970 */
if(!s->budget--) { s->failed_pc=0x0c038970u; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c038972;
P_0c038972: /* original 2228, guest PC 0x0c038972 */
if(!s->budget--) { s->failed_pc=0x0c038972u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c038974;
P_0c038974: /* original 8b01, guest PC 0x0c038974 */
if(!s->budget--) { s->failed_pc=0x0c038974u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03897a; }
goto P_0c038976;
P_0c038976: /* original b083, guest PC 0x0c038976 */
if(!s->budget--) { s->failed_pc=0x0c038976u; return 0; }
target=code_base|0x0c038a80u; r[16]=code_base|0x0c03897au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03897au) { target=s->pc; goto dispatch; }
goto P_0c03897a;
P_0c038978: /* original 64e3, guest PC 0x0c038978 */
if(!s->budget--) { s->failed_pc=0x0c038978u; return 0; }
r[4]=r[14];
goto P_0c03897a;
P_0c03897a: /* original 7e3c, guest PC 0x0c03897a */
if(!s->budget--) { s->failed_pc=0x0c03897au; return 0; }
r[14]+=0x0000003cu;
goto P_0c03897c;
P_0c03897c: /* original 7d01, guest PC 0x0c03897c */
if(!s->budget--) { s->failed_pc=0x0c03897cu; return 0; }
r[13]+=0x00000001u;
goto P_0c03897e;
P_0c03897e: /* original 62c2, guest PC 0x0c03897e */
if(!s->budget--) { s->failed_pc=0x0c03897eu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c038980;
P_0c038980: /* original 3d23, guest PC 0x0c038980 */
if(!s->budget--) { s->failed_pc=0x0c038980u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c038982;
P_0c038982: /* original 8bf5, guest PC 0x0c038982 */
if(!s->budget--) { s->failed_pc=0x0c038982u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038970; }
goto P_0c038984;
P_0c038984: /* original 4f26, guest PC 0x0c038984 */
if(!s->budget--) { s->failed_pc=0x0c038984u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038986;
P_0c038986: /* original 6cf6, guest PC 0x0c038986 */
if(!s->budget--) { s->failed_pc=0x0c038986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c038988;
P_0c038988: /* original 6df6, guest PC 0x0c038988 */
if(!s->budget--) { s->failed_pc=0x0c038988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03898a;
P_0c03898a: /* original 000b, guest PC 0x0c03898a */
if(!s->budget--) { s->failed_pc=0x0c03898au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03898c: /* original 6ef6, guest PC 0x0c03898c */
if(!s->budget--) { s->failed_pc=0x0c03898cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03898eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03898eu; return 0; } return 1;
P_0c038990: /* original 6043, guest PC 0x0c038990 */
if(!s->budget--) { s->failed_pc=0x0c038990u; return 0; }
r[0]=r[4];
goto P_0c038992;
P_0c038992: /* original 8808, guest PC 0x0c038992 */
if(!s->budget--) { s->failed_pc=0x0c038992u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c038994;
P_0c038994: /* original 8b04, guest PC 0x0c038994 */
if(!s->budget--) { s->failed_pc=0x0c038994u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389a0; }
goto P_0c038996;
P_0c038996: /* original a03f, guest PC 0x0c038996 */
if(!s->budget--) { s->failed_pc=0x0c038996u; return 0; }
r[4]=0x00000000u;
goto P_0c038a18;
P_0c038998: /* original e400, guest PC 0x0c038998 */
if(!s->budget--) { s->failed_pc=0x0c038998u; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c03899au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03899au; return 0; } return 1;
P_0c0389a0: /* original 8810, guest PC 0x0c0389a0 */
if(!s->budget--) { s->failed_pc=0x0c0389a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0389a2;
P_0c0389a2: /* original 8b05, guest PC 0x0c0389a2 */
if(!s->budget--) { s->failed_pc=0x0c0389a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389b0; }
goto P_0c0389a4;
P_0c0389a4: /* original a038, guest PC 0x0c0389a4 */
if(!s->budget--) { s->failed_pc=0x0c0389a4u; return 0; }
r[4]=0x00000001u;
goto P_0c038a18;
P_0c0389a6: /* original e401, guest PC 0x0c0389a6 */
if(!s->budget--) { s->failed_pc=0x0c0389a6u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c0389a8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389a8u; return 0; } return 1;
P_0c0389b0: /* original 6043, guest PC 0x0c0389b0 */
if(!s->budget--) { s->failed_pc=0x0c0389b0u; return 0; }
r[0]=r[4];
goto P_0c0389b2;
P_0c0389b2: /* original 8820, guest PC 0x0c0389b2 */
if(!s->budget--) { s->failed_pc=0x0c0389b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0389b4;
P_0c0389b4: /* original 8b04, guest PC 0x0c0389b4 */
if(!s->budget--) { s->failed_pc=0x0c0389b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389c0; }
goto P_0c0389b6;
P_0c0389b6: /* original a02f, guest PC 0x0c0389b6 */
if(!s->budget--) { s->failed_pc=0x0c0389b6u; return 0; }
r[4]=0x00000002u;
goto P_0c038a18;
P_0c0389b8: /* original e402, guest PC 0x0c0389b8 */
if(!s->budget--) { s->failed_pc=0x0c0389b8u; return 0; }
r[4]=0x00000002u;
if(!vf3_matrix_family(0x0c0389bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389bau; return 0; } return 1;
P_0c0389c0: /* original 8840, guest PC 0x0c0389c0 */
if(!s->budget--) { s->failed_pc=0x0c0389c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0389c2;
P_0c0389c2: /* original 8b0d, guest PC 0x0c0389c2 */
if(!s->budget--) { s->failed_pc=0x0c0389c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389e0; }
goto P_0c0389c4;
P_0c0389c4: /* original a028, guest PC 0x0c0389c4 */
if(!s->budget--) { s->failed_pc=0x0c0389c4u; return 0; }
r[4]=0x00000003u;
goto P_0c038a18;
P_0c0389c6: /* original e403, guest PC 0x0c0389c6 */
if(!s->budget--) { s->failed_pc=0x0c0389c6u; return 0; }
r[4]=0x00000003u;
if(!vf3_matrix_family(0x0c0389c8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389c8u; return 0; } return 1;
P_0c0389e0: /* original 9387, guest PC 0x0c0389e0 */
if(!s->budget--) { s->failed_pc=0x0c0389e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038af2u,2);
goto P_0c0389e2;
P_0c0389e2: /* original 3430, guest PC 0x0c0389e2 */
if(!s->budget--) { s->failed_pc=0x0c0389e2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0389e4;
P_0c0389e4: /* original 8b04, guest PC 0x0c0389e4 */
if(!s->budget--) { s->failed_pc=0x0c0389e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389f0; }
goto P_0c0389e6;
P_0c0389e6: /* original a017, guest PC 0x0c0389e6 */
if(!s->budget--) { s->failed_pc=0x0c0389e6u; return 0; }
r[4]=0x00000004u;
goto P_0c038a18;
P_0c0389e8: /* original e404, guest PC 0x0c0389e8 */
if(!s->budget--) { s->failed_pc=0x0c0389e8u; return 0; }
r[4]=0x00000004u;
if(!vf3_matrix_family(0x0c0389eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389eau; return 0; } return 1;
P_0c0389f0: /* original 9280, guest PC 0x0c0389f0 */
if(!s->budget--) { s->failed_pc=0x0c0389f0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038af4u,2);
goto P_0c0389f2;
P_0c0389f2: /* original 3420, guest PC 0x0c0389f2 */
if(!s->budget--) { s->failed_pc=0x0c0389f2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0389f4;
P_0c0389f4: /* original 8b04, guest PC 0x0c0389f4 */
if(!s->budget--) { s->failed_pc=0x0c0389f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038a00; }
goto P_0c0389f6;
P_0c0389f6: /* original a00f, guest PC 0x0c0389f6 */
if(!s->budget--) { s->failed_pc=0x0c0389f6u; return 0; }
r[4]=0x00000005u;
goto P_0c038a18;
P_0c0389f8: /* original e405, guest PC 0x0c0389f8 */
if(!s->budget--) { s->failed_pc=0x0c0389f8u; return 0; }
r[4]=0x00000005u;
if(!vf3_matrix_family(0x0c0389fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389fau; return 0; } return 1;
P_0c038a00: /* original 9179, guest PC 0x0c038a00 */
if(!s->budget--) { s->failed_pc=0x0c038a00u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038af6u,2);
goto P_0c038a02;
P_0c038a02: /* original 3410, guest PC 0x0c038a02 */
if(!s->budget--) { s->failed_pc=0x0c038a02u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c038a04;
P_0c038a04: /* original 8b04, guest PC 0x0c038a04 */
if(!s->budget--) { s->failed_pc=0x0c038a04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038a10; }
goto P_0c038a06;
P_0c038a06: /* original a007, guest PC 0x0c038a06 */
if(!s->budget--) { s->failed_pc=0x0c038a06u; return 0; }
r[4]=0x00000006u;
goto P_0c038a18;
P_0c038a08: /* original e406, guest PC 0x0c038a08 */
if(!s->budget--) { s->failed_pc=0x0c038a08u; return 0; }
r[4]=0x00000006u;
if(!vf3_matrix_family(0x0c038a0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038a0au; return 0; } return 1;
P_0c038a10: /* original 9372, guest PC 0x0c038a10 */
if(!s->budget--) { s->failed_pc=0x0c038a10u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038af8u,2);
goto P_0c038a12;
P_0c038a12: /* original 3430, guest PC 0x0c038a12 */
if(!s->budget--) { s->failed_pc=0x0c038a12u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c038a14;
P_0c038a14: /* original 8b00, guest PC 0x0c038a14 */
if(!s->budget--) { s->failed_pc=0x0c038a14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038a18; }
goto P_0c038a16;
P_0c038a16: /* original e407, guest PC 0x0c038a16 */
if(!s->budget--) { s->failed_pc=0x0c038a16u; return 0; }
r[4]=0x00000007u;
goto P_0c038a18;
P_0c038a18: /* original 000b, guest PC 0x0c038a18 */
if(!s->budget--) { s->failed_pc=0x0c038a18u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c038a1a: /* original 6043, guest PC 0x0c038a1a */
if(!s->budget--) { s->failed_pc=0x0c038a1au; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c038a1cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038a1cu; return 0; } return 1;
P_0c038a20: /* original e23c, guest PC 0x0c038a20 */
if(!s->budget--) { s->failed_pc=0x0c038a20u; return 0; }
r[2]=0x0000003cu;
goto P_0c038a22;
P_0c038a22: /* original d036, guest PC 0x0c038a22 */
if(!s->budget--) { s->failed_pc=0x0c038a22u; return 0; }
r[0]=read(ram,0x0c038afcu,4);
goto P_0c038a24;
P_0c038a24: /* original 4f12, guest PC 0x0c038a24 */
if(!s->budget--) { s->failed_pc=0x0c038a24u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c038a26;
P_0c038a26: /* original 0527, guest PC 0x0c038a26 */
if(!s->budget--) { s->failed_pc=0x0c038a26u; return 0; }
r[19]=r[5]*r[2];
goto P_0c038a28;
P_0c038a28: /* original 6102, guest PC 0x0c038a28 */
if(!s->budget--) { s->failed_pc=0x0c038a28u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c038a2a;
P_0c038a2a: /* original e3c0, guest PC 0x0c038a2a */
if(!s->budget--) { s->failed_pc=0x0c038a2au; return 0; }
r[3]=0xffffffc0u;
goto P_0c038a2c;
P_0c038a2c: /* original 5642, guest PC 0x0c038a2c */
if(!s->budget--) { s->failed_pc=0x0c038a2cu; return 0; }
r[6]=read(ram,r[4]+8,4);
goto P_0c038a2e;
P_0c038a2e: /* original e700, guest PC 0x0c038a2e */
if(!s->budget--) { s->failed_pc=0x0c038a2eu; return 0; }
r[7]=0x00000000u;
goto P_0c038a30;
P_0c038a30: /* original 051a, guest PC 0x0c038a30 */
if(!s->budget--) { s->failed_pc=0x0c038a30u; return 0; }
r[5]=r[19];
goto P_0c038a32;
P_0c038a32: /* original 2639, guest PC 0x0c038a32 */
if(!s->budget--) { s->failed_pc=0x0c038a32u; return 0; }
r[6]&=r[3];
goto P_0c038a34;
P_0c038a34: /* original 351c, guest PC 0x0c038a34 */
if(!s->budget--) { s->failed_pc=0x0c038a34u; return 0; }
r[5]+=r[1];
goto P_0c038a36;
P_0c038a36: /* original 525d, guest PC 0x0c038a36 */
if(!s->budget--) { s->failed_pc=0x0c038a36u; return 0; }
r[2]=read(ram,r[5]+52,4);
goto P_0c038a38;
P_0c038a38: /* original 535c, guest PC 0x0c038a38 */
if(!s->budget--) { s->failed_pc=0x0c038a38u; return 0; }
r[3]=read(ram,r[5]+48,4);
goto P_0c038a3a;
P_0c038a3a: /* original 272b, guest PC 0x0c038a3a */
if(!s->budget--) { s->failed_pc=0x0c038a3au; return 0; }
r[7]|=r[2];
goto P_0c038a3c;
P_0c038a3c: /* original 263b, guest PC 0x0c038a3c */
if(!s->budget--) { s->failed_pc=0x0c038a3cu; return 0; }
r[6]|=r[3];
goto P_0c038a3e;
P_0c038a3e: /* original 1462, guest PC 0x0c038a3e */
if(!s->budget--) { s->failed_pc=0x0c038a3eu; return 0; }
write(ram,r[4]+8,r[6],4);
goto P_0c038a40;
P_0c038a40: /* original 1473, guest PC 0x0c038a40 */
if(!s->budget--) { s->failed_pc=0x0c038a40u; return 0; }
write(ram,r[4]+12,r[7],4);
goto P_0c038a42;
P_0c038a42: /* original 000b, guest PC 0x0c038a42 */
if(!s->budget--) { s->failed_pc=0x0c038a42u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c038a44: /* original 4f16, guest PC 0x0c038a44 */
if(!s->budget--) { s->failed_pc=0x0c038a44u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038a46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038a46u; return 0; } return 1;
P_0c038a80: /* original 2fe6, guest PC 0x0c038a80 */
if(!s->budget--) { s->failed_pc=0x0c038a80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038a82;
P_0c038a82: /* original 6e43, guest PC 0x0c038a82 */
if(!s->budget--) { s->failed_pc=0x0c038a82u; return 0; }
r[14]=r[4];
goto P_0c038a84;
P_0c038a84: /* original 2fd6, guest PC 0x0c038a84 */
if(!s->budget--) { s->failed_pc=0x0c038a84u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038a86;
P_0c038a86: /* original 6d43, guest PC 0x0c038a86 */
if(!s->budget--) { s->failed_pc=0x0c038a86u; return 0; }
r[13]=r[4];
goto P_0c038a88;
P_0c038a88: /* original 2f86, guest PC 0x0c038a88 */
if(!s->budget--) { s->failed_pc=0x0c038a88u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038a8a;
P_0c038a8a: /* original 4f22, guest PC 0x0c038a8a */
if(!s->budget--) { s->failed_pc=0x0c038a8au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038a8c;
P_0c038a8c: /* original 7ffc, guest PC 0x0c038a8c */
if(!s->budget--) { s->failed_pc=0x0c038a8cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c038a8e;
P_0c038a8e: /* original bf7f, guest PC 0x0c038a8e */
if(!s->budget--) { s->failed_pc=0x0c038a8eu; return 0; }
target=code_base|0x0c038990u; r[16]=code_base|0x0c038a92u;
r[4]=read(ram,r[14]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038a92u) { target=s->pc; goto dispatch; }
goto P_0c038a92;
P_0c038a90: /* original 54e3, guest PC 0x0c038a90 */
if(!s->budget--) { s->failed_pc=0x0c038a90u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c038a92;
P_0c038a92: /* original 4008, guest PC 0x0c038a92 */
if(!s->budget--) { s->failed_pc=0x0c038a92u; return 0; }
r[0]<<=2;
goto P_0c038a94;
P_0c038a94: /* original 4000, guest PC 0x0c038a94 */
if(!s->budget--) { s->failed_pc=0x0c038a94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c038a96;
P_0c038a96: /* original e3f8, guest PC 0x0c038a96 */
if(!s->budget--) { s->failed_pc=0x0c038a96u; return 0; }
r[3]=0xfffffff8u;
goto P_0c038a98;
P_0c038a98: /* original 2f02, guest PC 0x0c038a98 */
if(!s->budget--) { s->failed_pc=0x0c038a98u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c038a9a;
P_0c038a9a: /* original 2039, guest PC 0x0c038a9a */
if(!s->budget--) { s->failed_pc=0x0c038a9au; return 0; }
r[0]&=r[3];
goto P_0c038a9c;
P_0c038a9c: /* original 6803, guest PC 0x0c038a9c */
if(!s->budget--) { s->failed_pc=0x0c038a9cu; return 0; }
r[8]=r[0];
goto P_0c038a9e;
P_0c038a9e: /* original bf77, guest PC 0x0c038a9e */
if(!s->budget--) { s->failed_pc=0x0c038a9eu; return 0; }
target=code_base|0x0c038990u; r[16]=code_base|0x0c038aa2u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038aa2u) { target=s->pc; goto dispatch; }
goto P_0c038aa2;
P_0c038aa0: /* original 54e4, guest PC 0x0c038aa0 */
if(!s->budget--) { s->failed_pc=0x0c038aa0u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c038aa2;
P_0c038aa2: /* original 6483, guest PC 0x0c038aa2 */
if(!s->budget--) { s->failed_pc=0x0c038aa2u; return 0; }
r[4]=r[8];
goto P_0c038aa4;
P_0c038aa4: /* original 240b, guest PC 0x0c038aa4 */
if(!s->budget--) { s->failed_pc=0x0c038aa4u; return 0; }
r[4]|=r[0];
goto P_0c038aa6;
P_0c038aa6: /* original 1d4c, guest PC 0x0c038aa6 */
if(!s->budget--) { s->failed_pc=0x0c038aa6u; return 0; }
write(ram,r[13]+48,r[4],4);
goto P_0c038aa8;
P_0c038aa8: /* original e001, guest PC 0x0c038aa8 */
if(!s->budget--) { s->failed_pc=0x0c038aa8u; return 0; }
r[0]=0x00000001u;
goto P_0c038aaa;
P_0c038aaa: /* original 54e6, guest PC 0x0c038aaa */
if(!s->budget--) { s->failed_pc=0x0c038aaau; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c038aac;
P_0c038aac: /* original e308, guest PC 0x0c038aac */
if(!s->budget--) { s->failed_pc=0x0c038aacu; return 0; }
r[3]=0x00000008u;
goto P_0c038aae;
P_0c038aae: /* original e21b, guest PC 0x0c038aae */
if(!s->budget--) { s->failed_pc=0x0c038aaeu; return 0; }
r[2]=0x0000001bu;
goto P_0c038ab0;
P_0c038ab0: /* original 51e2, guest PC 0x0c038ab0 */
if(!s->budget--) { s->failed_pc=0x0c038ab0u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c038ab2;
P_0c038ab2: /* original 2049, guest PC 0x0c038ab2 */
if(!s->budget--) { s->failed_pc=0x0c038ab2u; return 0; }
r[0]&=r[4];
goto P_0c038ab4;
P_0c038ab4: /* original 2349, guest PC 0x0c038ab4 */
if(!s->budget--) { s->failed_pc=0x0c038ab4u; return 0; }
r[3]&=r[4];
goto P_0c038ab6;
P_0c038ab6: /* original c901, guest PC 0x0c038ab6 */
if(!s->budget--) { s->failed_pc=0x0c038ab6u; return 0; }
r[0]&=1u;
goto P_0c038ab8;
P_0c038ab8: /* original 432d, guest PC 0x0c038ab8 */
if(!s->budget--) { s->failed_pc=0x0c038ab8u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c038aba;
P_0c038aba: /* original 4005, guest PC 0x0c038aba */
if(!s->budget--) { s->failed_pc=0x0c038abau; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c038abc;
P_0c038abc: /* original 203b, guest PC 0x0c038abc */
if(!s->budget--) { s->failed_pc=0x0c038abcu; return 0; }
r[0]|=r[3];
goto P_0c038abe;
P_0c038abe: /* original d313, guest PC 0x0c038abe */
if(!s->budget--) { s->failed_pc=0x0c038abeu; return 0; }
r[3]=read(ram,0x0c038b0cu,4);
goto P_0c038ac0;
P_0c038ac0: /* original 2139, guest PC 0x0c038ac0 */
if(!s->budget--) { s->failed_pc=0x0c038ac0u; return 0; }
r[1]&=r[3];
goto P_0c038ac2;
P_0c038ac2: /* original 201b, guest PC 0x0c038ac2 */
if(!s->budget--) { s->failed_pc=0x0c038ac2u; return 0; }
r[0]|=r[1];
goto P_0c038ac4;
P_0c038ac4: /* original 6103, guest PC 0x0c038ac4 */
if(!s->budget--) { s->failed_pc=0x0c038ac4u; return 0; }
r[1]=r[0];
goto P_0c038ac6;
P_0c038ac6: /* original 6047, guest PC 0x0c038ac6 */
if(!s->budget--) { s->failed_pc=0x0c038ac6u; return 0; }
r[0]=~r[4];
goto P_0c038ac8;
P_0c038ac8: /* original c904, guest PC 0x0c038ac8 */
if(!s->budget--) { s->failed_pc=0x0c038ac8u; return 0; }
r[0]&=4u;
goto P_0c038aca;
P_0c038aca: /* original 4028, guest PC 0x0c038aca */
if(!s->budget--) { s->failed_pc=0x0c038acau; return 0; }
r[0]<<=16;
goto P_0c038acc;
P_0c038acc: /* original 4018, guest PC 0x0c038acc */
if(!s->budget--) { s->failed_pc=0x0c038accu; return 0; }
r[0]<<=8;
goto P_0c038ace;
P_0c038ace: /* original 210b, guest PC 0x0c038ace */
if(!s->budget--) { s->failed_pc=0x0c038aceu; return 0; }
r[1]|=r[0];
goto P_0c038ad0;
P_0c038ad0: /* original e010, guest PC 0x0c038ad0 */
if(!s->budget--) { s->failed_pc=0x0c038ad0u; return 0; }
r[0]=0x00000010u;
goto P_0c038ad2;
P_0c038ad2: /* original e315, guest PC 0x0c038ad2 */
if(!s->budget--) { s->failed_pc=0x0c038ad2u; return 0; }
r[3]=0x00000015u;
goto P_0c038ad4;
P_0c038ad4: /* original 2049, guest PC 0x0c038ad4 */
if(!s->budget--) { s->failed_pc=0x0c038ad4u; return 0; }
r[0]&=r[4];
goto P_0c038ad6;
P_0c038ad6: /* original 403d, guest PC 0x0c038ad6 */
if(!s->budget--) { s->failed_pc=0x0c038ad6u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c038ad8;
P_0c038ad8: /* original 210b, guest PC 0x0c038ad8 */
if(!s->budget--) { s->failed_pc=0x0c038ad8u; return 0; }
r[1]|=r[0];
goto P_0c038ada;
P_0c038ada: /* original 50e7, guest PC 0x0c038ada */
if(!s->budget--) { s->failed_pc=0x0c038adau; return 0; }
r[0]=read(ram,r[14]+28,4);
goto P_0c038adc;
P_0c038adc: /* original 6413, guest PC 0x0c038adc */
if(!s->budget--) { s->failed_pc=0x0c038adcu; return 0; }
r[4]=r[1];
goto P_0c038ade;
P_0c038ade: /* original 4009, guest PC 0x0c038ade */
if(!s->budget--) { s->failed_pc=0x0c038adeu; return 0; }
r[0]>>=2;
goto P_0c038ae0;
P_0c038ae0: /* original 4001, guest PC 0x0c038ae0 */
if(!s->budget--) { s->failed_pc=0x0c038ae0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c038ae2;
P_0c038ae2: /* original 7f04, guest PC 0x0c038ae2 */
if(!s->budget--) { s->failed_pc=0x0c038ae2u; return 0; }
r[15]+=0x00000004u;
goto P_0c038ae4;
P_0c038ae4: /* original 4f26, guest PC 0x0c038ae4 */
if(!s->budget--) { s->failed_pc=0x0c038ae4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038ae6;
P_0c038ae6: /* original 240b, guest PC 0x0c038ae6 */
if(!s->budget--) { s->failed_pc=0x0c038ae6u; return 0; }
r[4]|=r[0];
goto P_0c038ae8;
P_0c038ae8: /* original 1d4d, guest PC 0x0c038ae8 */
if(!s->budget--) { s->failed_pc=0x0c038ae8u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c038aea;
P_0c038aea: /* original 68f6, guest PC 0x0c038aea */
if(!s->budget--) { s->failed_pc=0x0c038aeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c038aec;
P_0c038aec: /* original 6df6, guest PC 0x0c038aec */
if(!s->budget--) { s->failed_pc=0x0c038aecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c038aee;
P_0c038aee: /* original 000b, guest PC 0x0c038aee */
if(!s->budget--) { s->failed_pc=0x0c038aeeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c038af0: /* original 6ef6, guest PC 0x0c038af0 */
if(!s->budget--) { s->failed_pc=0x0c038af0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c038af2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038af2u; return 0; } return 1;
P_0c038b10: /* original e33c, guest PC 0x0c038b10 */
if(!s->budget--) { s->failed_pc=0x0c038b10u; return 0; }
r[3]=0x0000003cu;
goto P_0c038b12;
P_0c038b12: /* original d13e, guest PC 0x0c038b12 */
if(!s->budget--) { s->failed_pc=0x0c038b12u; return 0; }
r[1]=read(ram,0x0c038c0cu,4);
goto P_0c038b14;
P_0c038b14: /* original 4f12, guest PC 0x0c038b14 */
if(!s->budget--) { s->failed_pc=0x0c038b14u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c038b16;
P_0c038b16: /* original 0437, guest PC 0x0c038b16 */
if(!s->budget--) { s->failed_pc=0x0c038b16u; return 0; }
r[19]=r[4]*r[3];
goto P_0c038b18;
P_0c038b18: /* original 6212, guest PC 0x0c038b18 */
if(!s->budget--) { s->failed_pc=0x0c038b18u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c038b1a;
P_0c038b1a: /* original 041a, guest PC 0x0c038b1a */
if(!s->budget--) { s->failed_pc=0x0c038b1au; return 0; }
r[4]=r[19];
goto P_0c038b1c;
P_0c038b1c: /* original 342c, guest PC 0x0c038b1c */
if(!s->budget--) { s->failed_pc=0x0c038b1cu; return 0; }
r[4]+=r[2];
goto P_0c038b1e;
P_0c038b1e: /* original 534a, guest PC 0x0c038b1e */
if(!s->budget--) { s->failed_pc=0x0c038b1eu; return 0; }
r[3]=read(ram,r[4]+40,4);
goto P_0c038b20;
P_0c038b20: /* original 2338, guest PC 0x0c038b20 */
if(!s->budget--) { s->failed_pc=0x0c038b20u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c038b22;
P_0c038b22: /* original 8b05, guest PC 0x0c038b22 */
if(!s->budget--) { s->failed_pc=0x0c038b22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038b30; }
goto P_0c038b24;
P_0c038b24: /* original afac, guest PC 0x0c038b24 */
if(!s->budget--) { s->failed_pc=0x0c038b24u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c038a80;
P_0c038b26: /* original 4f16, guest PC 0x0c038b26 */
if(!s->budget--) { s->failed_pc=0x0c038b26u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038b28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038b28u; return 0; } return 1;
P_0c038b30: /* original d537, guest PC 0x0c038b30 */
if(!s->budget--) { s->failed_pc=0x0c038b30u; return 0; }
r[5]=read(ram,0x0c038c10u,4);
goto P_0c038b32;
P_0c038b32: /* original 535c, guest PC 0x0c038b32 */
if(!s->budget--) { s->failed_pc=0x0c038b32u; return 0; }
r[3]=read(ram,r[5]+48,4);
goto P_0c038b34;
P_0c038b34: /* original 143c, guest PC 0x0c038b34 */
if(!s->budget--) { s->failed_pc=0x0c038b34u; return 0; }
write(ram,r[4]+48,r[3],4);
goto P_0c038b36;
P_0c038b36: /* original 525d, guest PC 0x0c038b36 */
if(!s->budget--) { s->failed_pc=0x0c038b36u; return 0; }
r[2]=read(ram,r[5]+52,4);
goto P_0c038b38;
P_0c038b38: /* original 142d, guest PC 0x0c038b38 */
if(!s->budget--) { s->failed_pc=0x0c038b38u; return 0; }
write(ram,r[4]+52,r[2],4);
goto P_0c038b3a;
P_0c038b3a: /* original 000b, guest PC 0x0c038b3a */
if(!s->budget--) { s->failed_pc=0x0c038b3au; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c038b3c: /* original 4f16, guest PC 0x0c038b3c */
if(!s->budget--) { s->failed_pc=0x0c038b3cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038b3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038b3eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
