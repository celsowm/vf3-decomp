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
int vf3_away_batch18_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04760cu: goto P_0c04760c;
case 0x0c04760eu: goto P_0c04760e;
case 0x0c047610u: goto P_0c047610;
case 0x0c047612u: goto P_0c047612;
case 0x0c047614u: goto P_0c047614;
case 0x0c047616u: goto P_0c047616;
case 0x0c047618u: goto P_0c047618;
case 0x0c04761au: goto P_0c04761a;
case 0x0c04b9e4u: goto P_0c04b9e4;
case 0x0c04b9e6u: goto P_0c04b9e6;
case 0x0c04b9e8u: goto P_0c04b9e8;
case 0x0c04b9eau: goto P_0c04b9ea;
case 0x0c04b9ecu: goto P_0c04b9ec;
case 0x0c04b9eeu: goto P_0c04b9ee;
case 0x0c04b9f0u: goto P_0c04b9f0;
case 0x0c04b9f2u: goto P_0c04b9f2;
case 0x0c04b9f4u: goto P_0c04b9f4;
case 0x0c04b9f6u: goto P_0c04b9f6;
case 0x0c04b9f8u: goto P_0c04b9f8;
case 0x0c04b9fau: goto P_0c04b9fa;
case 0x0c04c14au: goto P_0c04c14a;
case 0x0c04c14cu: goto P_0c04c14c;
case 0x0c04c14eu: goto P_0c04c14e;
case 0x0c04c150u: goto P_0c04c150;
case 0x0c04c152u: goto P_0c04c152;
case 0x0c04c154u: goto P_0c04c154;
case 0x0c04c156u: goto P_0c04c156;
case 0x0c04c158u: goto P_0c04c158;
case 0x0c04c15au: goto P_0c04c15a;
case 0x0c04c5a0u: goto P_0c04c5a0;
case 0x0c04c5a2u: goto P_0c04c5a2;
case 0x0c04c5a4u: goto P_0c04c5a4;
case 0x0c04c5a6u: goto P_0c04c5a6;
case 0x0c04c5a8u: goto P_0c04c5a8;
case 0x0c04c5aau: goto P_0c04c5aa;
case 0x0c04c5acu: goto P_0c04c5ac;
case 0x0c04c5aeu: goto P_0c04c5ae;
case 0x0c04c5b0u: goto P_0c04c5b0;
case 0x0c04c5b2u: goto P_0c04c5b2;
case 0x0c04c5b4u: goto P_0c04c5b4;
case 0x0c04c5b6u: goto P_0c04c5b6;
case 0x0c04c5b8u: goto P_0c04c5b8;
case 0x0c04c5bau: goto P_0c04c5ba;
case 0x0c04c5bcu: goto P_0c04c5bc;
case 0x0c04c5beu: goto P_0c04c5be;
case 0x0c04c5c0u: goto P_0c04c5c0;
case 0x0c04c5c2u: goto P_0c04c5c2;
case 0x0c04c5c4u: goto P_0c04c5c4;
case 0x0c04c5c6u: goto P_0c04c5c6;
case 0x0c04c5c8u: goto P_0c04c5c8;
case 0x0c04c5cau: goto P_0c04c5ca;
case 0x0c04c5ccu: goto P_0c04c5cc;
case 0x0c04c5ceu: goto P_0c04c5ce;
case 0x0c04c5d0u: goto P_0c04c5d0;
case 0x0c04c5d2u: goto P_0c04c5d2;
case 0x0c04c5d4u: goto P_0c04c5d4;
case 0x0c04c5d6u: goto P_0c04c5d6;
case 0x0c04c5d8u: goto P_0c04c5d8;
case 0x0c04c5dau: goto P_0c04c5da;
case 0x0c04cb3eu: goto P_0c04cb3e;
case 0x0c04cb40u: goto P_0c04cb40;
case 0x0c04cb42u: goto P_0c04cb42;
case 0x0c04cb44u: goto P_0c04cb44;
case 0x0c04cb46u: goto P_0c04cb46;
case 0x0c04cb48u: goto P_0c04cb48;
case 0x0c04cb4au: goto P_0c04cb4a;
case 0x0c04cb4cu: goto P_0c04cb4c;
case 0x0c04cb4eu: goto P_0c04cb4e;
case 0x0c04cb50u: goto P_0c04cb50;
case 0x0c04cb52u: goto P_0c04cb52;
case 0x0c04cb54u: goto P_0c04cb54;
case 0x0c04cb56u: goto P_0c04cb56;
case 0x0c04cb58u: goto P_0c04cb58;
case 0x0c04cb5au: goto P_0c04cb5a;
case 0x0c04cb5cu: goto P_0c04cb5c;
case 0x0c05344cu: goto P_0c05344c;
case 0x0c05344eu: goto P_0c05344e;
case 0x0c055d40u: goto P_0c055d40;
case 0x0c055d42u: goto P_0c055d42;
case 0x0c055d44u: goto P_0c055d44;
case 0x0c055d46u: goto P_0c055d46;
case 0x0c055d48u: goto P_0c055d48;
case 0x0c055d4au: goto P_0c055d4a;
case 0x0c055d4cu: goto P_0c055d4c;
case 0x0c055d4eu: goto P_0c055d4e;
case 0x0c055d50u: goto P_0c055d50;
case 0x0c055d52u: goto P_0c055d52;
case 0x0c055d54u: goto P_0c055d54;
case 0x0c055d56u: goto P_0c055d56;
case 0x0c055d58u: goto P_0c055d58;
case 0x0c055d5au: goto P_0c055d5a;
case 0x0c055d5cu: goto P_0c055d5c;
case 0x0c055d5eu: goto P_0c055d5e;
case 0x0c055d60u: goto P_0c055d60;
case 0x0c055d62u: goto P_0c055d62;
case 0x0c055d64u: goto P_0c055d64;
case 0x0c055d66u: goto P_0c055d66;
case 0x0c055d68u: goto P_0c055d68;
case 0x0c055d6au: goto P_0c055d6a;
case 0x0c055d6cu: goto P_0c055d6c;
case 0x0c055d6eu: goto P_0c055d6e;
case 0x0c055d70u: goto P_0c055d70;
case 0x0c055d72u: goto P_0c055d72;
case 0x0c055d74u: goto P_0c055d74;
case 0x0c055d76u: goto P_0c055d76;
case 0x0c055d78u: goto P_0c055d78;
case 0x0c055d7au: goto P_0c055d7a;
case 0x0c055d7cu: goto P_0c055d7c;
case 0x0c055d7eu: goto P_0c055d7e;
case 0x0c055d80u: goto P_0c055d80;
case 0x0c055d82u: goto P_0c055d82;
case 0x0c055d84u: goto P_0c055d84;
case 0x0c055d86u: goto P_0c055d86;
case 0x0c055d88u: goto P_0c055d88;
case 0x0c055d8au: goto P_0c055d8a;
case 0x0c055d8cu: goto P_0c055d8c;
case 0x0c055d8eu: goto P_0c055d8e;
case 0x0c055d90u: goto P_0c055d90;
case 0x0c055d92u: goto P_0c055d92;
case 0x0c055d94u: goto P_0c055d94;
case 0x0c055d96u: goto P_0c055d96;
case 0x0c055d98u: goto P_0c055d98;
case 0x0c055d9au: goto P_0c055d9a;
case 0x0c055d9cu: goto P_0c055d9c;
case 0x0c055d9eu: goto P_0c055d9e;
case 0x0c055da0u: goto P_0c055da0;
case 0x0c055da2u: goto P_0c055da2;
case 0x0c055da4u: goto P_0c055da4;
case 0x0c055da6u: goto P_0c055da6;
case 0x0c055da8u: goto P_0c055da8;
case 0x0c055daau: goto P_0c055daa;
case 0x0c055dacu: goto P_0c055dac;
case 0x0c055daeu: goto P_0c055dae;
case 0x0c055db0u: goto P_0c055db0;
case 0x0c055db2u: goto P_0c055db2;
case 0x0c055db4u: goto P_0c055db4;
case 0x0c055db6u: goto P_0c055db6;
case 0x0c055db8u: goto P_0c055db8;
case 0x0c059840u: goto P_0c059840;
case 0x0c059842u: goto P_0c059842;
case 0x0c059844u: goto P_0c059844;
case 0x0c059846u: goto P_0c059846;
case 0x0c059848u: goto P_0c059848;
case 0x0c05984au: goto P_0c05984a;
case 0x0c05984cu: goto P_0c05984c;
case 0x0c05984eu: goto P_0c05984e;
case 0x0c059850u: goto P_0c059850;
case 0x0c059852u: goto P_0c059852;
case 0x0c059854u: goto P_0c059854;
case 0x0c059856u: goto P_0c059856;
case 0x0c059858u: goto P_0c059858;
case 0x0c05985au: goto P_0c05985a;
case 0x0c05985cu: goto P_0c05985c;
case 0x0c05985eu: goto P_0c05985e;
case 0x0c059860u: goto P_0c059860;
case 0x0c059862u: goto P_0c059862;
case 0x0c059864u: goto P_0c059864;
case 0x0c059866u: goto P_0c059866;
case 0x0c059868u: goto P_0c059868;
case 0x0c05986au: goto P_0c05986a;
case 0x0c05986cu: goto P_0c05986c;
case 0x0c05986eu: goto P_0c05986e;
case 0x0c059870u: goto P_0c059870;
case 0x0c059872u: goto P_0c059872;
case 0x0c059874u: goto P_0c059874;
case 0x0c059876u: goto P_0c059876;
case 0x0c059878u: goto P_0c059878;
case 0x0c05987au: goto P_0c05987a;
case 0x0c05987cu: goto P_0c05987c;
case 0x0c05987eu: goto P_0c05987e;
case 0x0c059880u: goto P_0c059880;
case 0x0c059882u: goto P_0c059882;
case 0x0c059884u: goto P_0c059884;
case 0x0c059886u: goto P_0c059886;
case 0x0c059888u: goto P_0c059888;
case 0x0c05988au: goto P_0c05988a;
case 0x0c05988cu: goto P_0c05988c;
case 0x0c05988eu: goto P_0c05988e;
case 0x0c059890u: goto P_0c059890;
case 0x0c059892u: goto P_0c059892;
case 0x0c059894u: goto P_0c059894;
case 0x0c059a20u: goto P_0c059a20;
case 0x0c059a22u: goto P_0c059a22;
case 0x0c059a24u: goto P_0c059a24;
case 0x0c059a26u: goto P_0c059a26;
case 0x0c059a28u: goto P_0c059a28;
case 0x0c059a2au: goto P_0c059a2a;
case 0x0c059a2cu: goto P_0c059a2c;
case 0x0c059a2eu: goto P_0c059a2e;
case 0x0c059a30u: goto P_0c059a30;
case 0x0c059a32u: goto P_0c059a32;
case 0x0c059a34u: goto P_0c059a34;
case 0x0c059a36u: goto P_0c059a36;
case 0x0c059a38u: goto P_0c059a38;
case 0x0c059a3au: goto P_0c059a3a;
case 0x0c059a3cu: goto P_0c059a3c;
case 0x0c059a3eu: goto P_0c059a3e;
case 0x0c059a40u: goto P_0c059a40;
case 0x0c059a42u: goto P_0c059a42;
case 0x0c059a44u: goto P_0c059a44;
case 0x0c059a46u: goto P_0c059a46;
case 0x0c059a48u: goto P_0c059a48;
case 0x0c059a4au: goto P_0c059a4a;
case 0x0c059a4cu: goto P_0c059a4c;
case 0x0c059a4eu: goto P_0c059a4e;
case 0x0c059a50u: goto P_0c059a50;
case 0x0c059a52u: goto P_0c059a52;
case 0x0c059a54u: goto P_0c059a54;
case 0x0c059a56u: goto P_0c059a56;
case 0x0c059a58u: goto P_0c059a58;
case 0x0c059a5au: goto P_0c059a5a;
case 0x0c059a5cu: goto P_0c059a5c;
case 0x0c059a5eu: goto P_0c059a5e;
case 0x0c059a60u: goto P_0c059a60;
case 0x0c059a62u: goto P_0c059a62;
case 0x0c059a64u: goto P_0c059a64;
case 0x0c059a66u: goto P_0c059a66;
case 0x0c059a68u: goto P_0c059a68;
case 0x0c059a6au: goto P_0c059a6a;
case 0x0c059a6cu: goto P_0c059a6c;
case 0x0c059a6eu: goto P_0c059a6e;
case 0x0c059a70u: goto P_0c059a70;
case 0x0c059a72u: goto P_0c059a72;
case 0x0c059a74u: goto P_0c059a74;
case 0x0c059a76u: goto P_0c059a76;
case 0x0c059a78u: goto P_0c059a78;
case 0x0c059a7au: goto P_0c059a7a;
case 0x0c059a7cu: goto P_0c059a7c;
case 0x0c059a7eu: goto P_0c059a7e;
case 0x0c059a80u: goto P_0c059a80;
case 0x0c059a82u: goto P_0c059a82;
case 0x0c059a84u: goto P_0c059a84;
case 0x0c059a86u: goto P_0c059a86;
case 0x0c059a88u: goto P_0c059a88;
case 0x0c059a8au: goto P_0c059a8a;
case 0x0c059a8cu: goto P_0c059a8c;
case 0x0c059a8eu: goto P_0c059a8e;
case 0x0c059a90u: goto P_0c059a90;
case 0x0c059a92u: goto P_0c059a92;
case 0x0c059a94u: goto P_0c059a94;
case 0x0c059a96u: goto P_0c059a96;
case 0x0c059a98u: goto P_0c059a98;
case 0x0c059a9au: goto P_0c059a9a;
case 0x0c059a9cu: goto P_0c059a9c;
case 0x0c059a9eu: goto P_0c059a9e;
case 0x0c059aa0u: goto P_0c059aa0;
case 0x0c059aa2u: goto P_0c059aa2;
case 0x0c059aa4u: goto P_0c059aa4;
case 0x0c059aa6u: goto P_0c059aa6;
case 0x0c059aa8u: goto P_0c059aa8;
case 0x0c059aaau: goto P_0c059aaa;
case 0x0c059aacu: goto P_0c059aac;
case 0x0c059aaeu: goto P_0c059aae;
case 0x0c059ab0u: goto P_0c059ab0;
case 0x0c059ab2u: goto P_0c059ab2;
case 0x0c059ab4u: goto P_0c059ab4;
case 0x0c059ab6u: goto P_0c059ab6;
case 0x0c059ab8u: goto P_0c059ab8;
case 0x0c059abau: goto P_0c059aba;
case 0x0c059abcu: goto P_0c059abc;
case 0x0c059abeu: goto P_0c059abe;
case 0x0c059ac0u: goto P_0c059ac0;
case 0x0c059ac2u: goto P_0c059ac2;
case 0x0c059ac4u: goto P_0c059ac4;
case 0x0c059ac6u: goto P_0c059ac6;
case 0x0c059ac8u: goto P_0c059ac8;
case 0x0c059acau: goto P_0c059aca;
case 0x0c059accu: goto P_0c059acc;
case 0x0c059aceu: goto P_0c059ace;
case 0x0c059ad0u: goto P_0c059ad0;
case 0x0c059ad2u: goto P_0c059ad2;
case 0x0c059ad4u: goto P_0c059ad4;
case 0x0c059ad6u: goto P_0c059ad6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04760c: /* original 6156, guest PC 0x0c04760c */
if(!s->budget--) { s->failed_pc=0x0c04760cu; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[1]=tmp;
goto P_0c04760e;
P_0c04760e: /* original 4610, guest PC 0x0c04760e */
if(!s->budget--) { s->failed_pc=0x0c04760eu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c047610;
P_0c047610: /* original 0416, guest PC 0x0c047610 */
if(!s->budget--) { s->failed_pc=0x0c047610u; return 0; }
write(ram,r[4]+r[0],r[1],4);
goto P_0c047612;
P_0c047612: /* original 8ffb, guest PC 0x0c047612 */
if(!s->budget--) { s->failed_pc=0x0c047612u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c04760c; }
goto P_0c047616;
P_0c047614: /* original 7404, guest PC 0x0c047614 */
if(!s->budget--) { s->failed_pc=0x0c047614u; return 0; }
r[4]+=0x00000004u;
goto P_0c047616;
P_0c047616: /* original e001, guest PC 0x0c047616 */
if(!s->budget--) { s->failed_pc=0x0c047616u; return 0; }
r[0]=0x00000001u;
goto P_0c047618;
P_0c047618: /* original 000b, guest PC 0x0c047618 */
if(!s->budget--) { s->failed_pc=0x0c047618u; return 0; }
target=r[16];
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
s->pc=target; return ram->oob==0;
P_0c04761a: /* original c000, guest PC 0x0c04761a */
if(!s->budget--) { s->failed_pc=0x0c04761au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
if(!vf3_matrix_family(0x0c04761cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04761cu; return 0; } return 1;
P_0c04b9e4: /* original e700, guest PC 0x0c04b9e4 */
if(!s->budget--) { s->failed_pc=0x0c04b9e4u; return 0; }
r[7]=0x00000000u;
goto P_0c04b9e6;
P_0c04b9e6: /* original 6373, guest PC 0x0c04b9e6 */
if(!s->budget--) { s->failed_pc=0x0c04b9e6u; return 0; }
r[3]=r[7];
goto P_0c04b9e8;
P_0c04b9e8: /* original 3362, guest PC 0x0c04b9e8 */
if(!s->budget--) { s->failed_pc=0x0c04b9e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c04b9ea;
P_0c04b9ea: /* original 8d05, guest PC 0x0c04b9ea */
if(!s->budget--) { s->failed_pc=0x0c04b9eau; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c04b9f8; }
goto P_0c04b9ee;
P_0c04b9ec: /* original 6043, guest PC 0x0c04b9ec */
if(!s->budget--) { s->failed_pc=0x0c04b9ecu; return 0; }
r[0]=r[4];
goto P_0c04b9ee;
P_0c04b9ee: /* original 7701, guest PC 0x0c04b9ee */
if(!s->budget--) { s->failed_pc=0x0c04b9eeu; return 0; }
r[7]+=0x00000001u;
goto P_0c04b9f0;
P_0c04b9f0: /* original 2050, guest PC 0x0c04b9f0 */
if(!s->budget--) { s->failed_pc=0x0c04b9f0u; return 0; }
write(ram,r[0],r[5],1);
goto P_0c04b9f2;
P_0c04b9f2: /* original 3762, guest PC 0x0c04b9f2 */
if(!s->budget--) { s->failed_pc=0x0c04b9f2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[6])!=0);
goto P_0c04b9f4;
P_0c04b9f4: /* original 8ffb, guest PC 0x0c04b9f4 */
if(!s->budget--) { s->failed_pc=0x0c04b9f4u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c04b9ee; }
goto P_0c04b9f8;
P_0c04b9f6: /* original 7001, guest PC 0x0c04b9f6 */
if(!s->budget--) { s->failed_pc=0x0c04b9f6u; return 0; }
r[0]+=0x00000001u;
goto P_0c04b9f8;
P_0c04b9f8: /* original 000b, guest PC 0x0c04b9f8 */
if(!s->budget--) { s->failed_pc=0x0c04b9f8u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04b9fa: /* original 6043, guest PC 0x0c04b9fa */
if(!s->budget--) { s->failed_pc=0x0c04b9fau; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04b9fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04b9fcu; return 0; } return 1;
P_0c04c14a: /* original 4f22, guest PC 0x0c04c14a */
if(!s->budget--) { s->failed_pc=0x0c04c14au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c14c;
P_0c04c14c: /* original d309, guest PC 0x0c04c14c */
if(!s->budget--) { s->failed_pc=0x0c04c14cu; return 0; }
r[3]=read(ram,0x0c04c174u,4);
goto P_0c04c14e;
P_0c04c14e: /* original d408, guest PC 0x0c04c14e */
if(!s->budget--) { s->failed_pc=0x0c04c14eu; return 0; }
r[4]=read(ram,0x0c04c170u,4);
goto P_0c04c150;
P_0c04c150: /* original 9609, guest PC 0x0c04c150 */
if(!s->budget--) { s->failed_pc=0x0c04c150u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c166u,2);
goto P_0c04c152;
P_0c04c152: /* original 430b, guest PC 0x0c04c152 */
if(!s->budget--) { s->failed_pc=0x0c04c152u; return 0; }
target=r[3];
r[16]=code_base|0x0c04c156u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c156u) { target=s->pc; goto dispatch; }
goto P_0c04c156;
P_0c04c154: /* original e500, guest PC 0x0c04c154 */
if(!s->budget--) { s->failed_pc=0x0c04c154u; return 0; }
r[5]=0x00000000u;
goto P_0c04c156;
P_0c04c156: /* original 4f26, guest PC 0x0c04c156 */
if(!s->budget--) { s->failed_pc=0x0c04c156u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c158;
P_0c04c158: /* original 000b, guest PC 0x0c04c158 */
if(!s->budget--) { s->failed_pc=0x0c04c158u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04c15a: /* original e000, guest PC 0x0c04c15a */
if(!s->budget--) { s->failed_pc=0x0c04c15au; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c04c15cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c15cu; return 0; } return 1;
P_0c04c5a0: /* original 2fe6, guest PC 0x0c04c5a0 */
if(!s->budget--) { s->failed_pc=0x0c04c5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c5a2;
P_0c04c5a2: /* original e503, guest PC 0x0c04c5a2 */
if(!s->budget--) { s->failed_pc=0x0c04c5a2u; return 0; }
r[5]=0x00000003u;
goto P_0c04c5a4;
P_0c04c5a4: /* original 4f22, guest PC 0x0c04c5a4 */
if(!s->budget--) { s->failed_pc=0x0c04c5a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c5a6;
P_0c04c5a6: /* original 60f3, guest PC 0x0c04c5a6 */
if(!s->budget--) { s->failed_pc=0x0c04c5a6u; return 0; }
r[0]=r[15];
goto P_0c04c5a8;
P_0c04c5a8: /* original 7008, guest PC 0x0c04c5a8 */
if(!s->budget--) { s->failed_pc=0x0c04c5a8u; return 0; }
r[0]+=0x00000008u;
goto P_0c04c5aa;
P_0c04c5aa: /* original 7004, guest PC 0x0c04c5aa */
if(!s->budget--) { s->failed_pc=0x0c04c5aau; return 0; }
r[0]+=0x00000004u;
goto P_0c04c5ac;
P_0c04c5ac: /* original 2508, guest PC 0x0c04c5ac */
if(!s->budget--) { s->failed_pc=0x0c04c5acu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c04c5ae;
P_0c04c5ae: /* original 8903, guest PC 0x0c04c5ae */
if(!s->budget--) { s->failed_pc=0x0c04c5aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c5b8; }
goto P_0c04c5b0;
P_0c04c5b0: /* original 65f3, guest PC 0x0c04c5b0 */
if(!s->budget--) { s->failed_pc=0x0c04c5b0u; return 0; }
r[5]=r[15];
goto P_0c04c5b2;
P_0c04c5b2: /* original 7508, guest PC 0x0c04c5b2 */
if(!s->budget--) { s->failed_pc=0x0c04c5b2u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5b4;
P_0c04c5b4: /* original a003, guest PC 0x0c04c5b4 */
if(!s->budget--) { s->failed_pc=0x0c04c5b4u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5be;
P_0c04c5b6: /* original 7508, guest PC 0x0c04c5b6 */
if(!s->budget--) { s->failed_pc=0x0c04c5b6u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5b8;
P_0c04c5b8: /* original 65f3, guest PC 0x0c04c5b8 */
if(!s->budget--) { s->failed_pc=0x0c04c5b8u; return 0; }
r[5]=r[15];
goto P_0c04c5ba;
P_0c04c5ba: /* original 7508, guest PC 0x0c04c5ba */
if(!s->budget--) { s->failed_pc=0x0c04c5bau; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5bc;
P_0c04c5bc: /* original 7504, guest PC 0x0c04c5bc */
if(!s->budget--) { s->failed_pc=0x0c04c5bcu; return 0; }
r[5]+=0x00000004u;
goto P_0c04c5be;
P_0c04c5be: /* original d335, guest PC 0x0c04c5be */
if(!s->budget--) { s->failed_pc=0x0c04c5beu; return 0; }
r[3]=read(ram,0x0c04c694u,4);
goto P_0c04c5c0;
P_0c04c5c0: /* original 6653, guest PC 0x0c04c5c0 */
if(!s->budget--) { s->failed_pc=0x0c04c5c0u; return 0; }
r[6]=r[5];
goto P_0c04c5c2;
P_0c04c5c2: /* original d433, guest PC 0x0c04c5c2 */
if(!s->budget--) { s->failed_pc=0x0c04c5c2u; return 0; }
r[4]=read(ram,0x0c04c690u,4);
goto P_0c04c5c4;
P_0c04c5c4: /* original 430b, guest PC 0x0c04c5c4 */
if(!s->budget--) { s->failed_pc=0x0c04c5c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c04c5c8u;
r[5]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c5c8u) { target=s->pc; goto dispatch; }
goto P_0c04c5c8;
P_0c04c5c6: /* original 55f2, guest PC 0x0c04c5c6 */
if(!s->budget--) { s->failed_pc=0x0c04c5c6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c04c5c8;
P_0c04c5c8: /* original d233, guest PC 0x0c04c5c8 */
if(!s->budget--) { s->failed_pc=0x0c04c5c8u; return 0; }
r[2]=read(ram,0x0c04c698u,4);
goto P_0c04c5ca;
P_0c04c5ca: /* original 6e22, guest PC 0x0c04c5ca */
if(!s->budget--) { s->failed_pc=0x0c04c5cau; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c04c5cc;
P_0c04c5cc: /* original 2ee8, guest PC 0x0c04c5cc */
if(!s->budget--) { s->failed_pc=0x0c04c5ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04c5ce;
P_0c04c5ce: /* original 8902, guest PC 0x0c04c5ce */
if(!s->budget--) { s->failed_pc=0x0c04c5ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c5d6; }
goto P_0c04c5d0;
P_0c04c5d0: /* original d42f, guest PC 0x0c04c5d0 */
if(!s->budget--) { s->failed_pc=0x0c04c5d0u; return 0; }
r[4]=read(ram,0x0c04c690u,4);
goto P_0c04c5d2;
P_0c04c5d2: /* original 4e0b, guest PC 0x0c04c5d2 */
if(!s->budget--) { s->failed_pc=0x0c04c5d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c04c5d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c5d6u) { target=s->pc; goto dispatch; }
goto P_0c04c5d6;
P_0c04c5d4: /* original 0009, guest PC 0x0c04c5d4 */
if(!s->budget--) { s->failed_pc=0x0c04c5d4u; return 0; }
goto P_0c04c5d6;
P_0c04c5d6: /* original 4f26, guest PC 0x0c04c5d6 */
if(!s->budget--) { s->failed_pc=0x0c04c5d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c5d8;
P_0c04c5d8: /* original 000b, guest PC 0x0c04c5d8 */
if(!s->budget--) { s->failed_pc=0x0c04c5d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c5da: /* original 6ef6, guest PC 0x0c04c5da */
if(!s->budget--) { s->failed_pc=0x0c04c5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04c5dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c5dcu; return 0; } return 1;
P_0c04cb3e: /* original 4f22, guest PC 0x0c04cb3e */
if(!s->budget--) { s->failed_pc=0x0c04cb3eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04cb40;
P_0c04cb40: /* original d31e, guest PC 0x0c04cb40 */
if(!s->budget--) { s->failed_pc=0x0c04cb40u; return 0; }
r[3]=read(ram,0x0c04cbbcu,4);
goto P_0c04cb42;
P_0c04cb42: /* original bd2d, guest PC 0x0c04cb42 */
if(!s->budget--) { s->failed_pc=0x0c04cb42u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cb46u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cb46u) { target=s->pc; goto dispatch; }
goto P_0c04cb46;
P_0c04cb44: /* original 2f36, guest PC 0x0c04cb44 */
if(!s->budget--) { s->failed_pc=0x0c04cb44u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb46;
P_0c04cb46: /* original d41e, guest PC 0x0c04cb46 */
if(!s->budget--) { s->failed_pc=0x0c04cb46u; return 0; }
r[4]=read(ram,0x0c04cbc0u,4);
goto P_0c04cb48;
P_0c04cb48: /* original 7f04, guest PC 0x0c04cb48 */
if(!s->budget--) { s->failed_pc=0x0c04cb48u; return 0; }
r[15]+=0x00000004u;
goto P_0c04cb4a;
P_0c04cb4a: /* original d316, guest PC 0x0c04cb4a */
if(!s->budget--) { s->failed_pc=0x0c04cb4au; return 0; }
r[3]=read(ram,0x0c04cba4u,4);
goto P_0c04cb4c;
P_0c04cb4c: /* original 9626, guest PC 0x0c04cb4c */
if(!s->budget--) { s->failed_pc=0x0c04cb4cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cb9cu,2);
goto P_0c04cb4e;
P_0c04cb4e: /* original 430b, guest PC 0x0c04cb4e */
if(!s->budget--) { s->failed_pc=0x0c04cb4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04cb52u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cb52u) { target=s->pc; goto dispatch; }
goto P_0c04cb52;
P_0c04cb50: /* original e500, guest PC 0x0c04cb50 */
if(!s->budget--) { s->failed_pc=0x0c04cb50u; return 0; }
r[5]=0x00000000u;
goto P_0c04cb52;
P_0c04cb52: /* original d21c, guest PC 0x0c04cb52 */
if(!s->budget--) { s->failed_pc=0x0c04cb52u; return 0; }
r[2]=read(ram,0x0c04cbc4u,4);
goto P_0c04cb54;
P_0c04cb54: /* original 420b, guest PC 0x0c04cb54 */
if(!s->budget--) { s->failed_pc=0x0c04cb54u; return 0; }
target=r[2];
r[16]=code_base|0x0c04cb58u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cb58u) { target=s->pc; goto dispatch; }
goto P_0c04cb58;
P_0c04cb56: /* original 0009, guest PC 0x0c04cb56 */
if(!s->budget--) { s->failed_pc=0x0c04cb56u; return 0; }
goto P_0c04cb58;
P_0c04cb58: /* original 4f26, guest PC 0x0c04cb58 */
if(!s->budget--) { s->failed_pc=0x0c04cb58u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cb5a;
P_0c04cb5a: /* original 000b, guest PC 0x0c04cb5a */
if(!s->budget--) { s->failed_pc=0x0c04cb5au; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04cb5c: /* original e000, guest PC 0x0c04cb5c */
if(!s->budget--) { s->failed_pc=0x0c04cb5cu; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c04cb5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04cb5eu; return 0; } return 1;
P_0c05344c: /* original 000b, guest PC 0x0c05344c */
if(!s->budget--) { s->failed_pc=0x0c05344cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05344e: /* original 0009, guest PC 0x0c05344e */
if(!s->budget--) { s->failed_pc=0x0c05344eu; return 0; }
if(!vf3_matrix_family(0x0c053450u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c053450u; return 0; } return 1;
P_0c055d40: /* original 4f22, guest PC 0x0c055d40 */
if(!s->budget--) { s->failed_pc=0x0c055d40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055d42;
P_0c055d42: /* original d01f, guest PC 0x0c055d42 */
if(!s->budget--) { s->failed_pc=0x0c055d42u; return 0; }
r[0]=read(ram,0x0c055dc0u,4);
goto P_0c055d44;
P_0c055d44: /* original 6102, guest PC 0x0c055d44 */
if(!s->budget--) { s->failed_pc=0x0c055d44u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c055d46;
P_0c055d46: /* original 4115, guest PC 0x0c055d46 */
if(!s->budget--) { s->failed_pc=0x0c055d46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d48;
P_0c055d48: /* original d01c, guest PC 0x0c055d48 */
if(!s->budget--) { s->failed_pc=0x0c055d48u; return 0; }
r[0]=read(ram,0x0c055dbcu,4);
goto P_0c055d4a;
P_0c055d4a: /* original 8d0e, guest PC 0x0c055d4a */
if(!s->budget--) { s->failed_pc=0x0c055d4au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c055d6a; }
goto P_0c055d4e;
P_0c055d4c: /* original 6403, guest PC 0x0c055d4c */
if(!s->budget--) { s->failed_pc=0x0c055d4cu; return 0; }
r[4]=r[0];
goto P_0c055d4e;
P_0c055d4e: /* original 7440, guest PC 0x0c055d4e */
if(!s->budget--) { s->failed_pc=0x0c055d4eu; return 0; }
r[4]+=0x00000040u;
goto P_0c055d50;
P_0c055d50: /* original 6503, guest PC 0x0c055d50 */
if(!s->budget--) { s->failed_pc=0x0c055d50u; return 0; }
r[5]=r[0];
goto P_0c055d52;
P_0c055d52: /* original d31c, guest PC 0x0c055d52 */
if(!s->budget--) { s->failed_pc=0x0c055d52u; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d54;
P_0c055d54: /* original 430b, guest PC 0x0c055d54 */
if(!s->budget--) { s->failed_pc=0x0c055d54u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d58u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d58u) { target=s->pc; goto dispatch; }
goto P_0c055d58;
P_0c055d56: /* original 7568, guest PC 0x0c055d56 */
if(!s->budget--) { s->failed_pc=0x0c055d56u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d58;
P_0c055d58: /* original d01c, guest PC 0x0c055d58 */
if(!s->budget--) { s->failed_pc=0x0c055d58u; return 0; }
r[0]=read(ram,0x0c055dccu,4);
goto P_0c055d5a;
P_0c055d5a: /* original d11f, guest PC 0x0c055d5a */
if(!s->budget--) { s->failed_pc=0x0c055d5au; return 0; }
r[1]=read(ram,0x0c055dd8u,4);
goto P_0c055d5c;
P_0c055d5c: /* original d220, guest PC 0x0c055d5c */
if(!s->budget--) { s->failed_pc=0x0c055d5cu; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055d5e;
P_0c055d5e: /* original c204, guest PC 0x0c055d5e */
if(!s->budget--) { s->failed_pc=0x0c055d5eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055d60;
P_0c055d60: /* original 6013, guest PC 0x0c055d60 */
if(!s->budget--) { s->failed_pc=0x0c055d60u; return 0; }
r[0]=r[1];
goto P_0c055d62;
P_0c055d62: /* original c205, guest PC 0x0c055d62 */
if(!s->budget--) { s->failed_pc=0x0c055d62u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055d64;
P_0c055d64: /* original 6023, guest PC 0x0c055d64 */
if(!s->budget--) { s->failed_pc=0x0c055d64u; return 0; }
r[0]=r[2];
goto P_0c055d66;
P_0c055d66: /* original a025, guest PC 0x0c055d66 */
if(!s->budget--) { s->failed_pc=0x0c055d66u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055d68: /* original c203, guest PC 0x0c055d68 */
if(!s->budget--) { s->failed_pc=0x0c055d68u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055d6a;
P_0c055d6a: /* original 2fe6, guest PC 0x0c055d6a */
if(!s->budget--) { s->failed_pc=0x0c055d6au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6c;
P_0c055d6c: /* original 2fd6, guest PC 0x0c055d6c */
if(!s->budget--) { s->failed_pc=0x0c055d6cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6e;
P_0c055d6e: /* original 6e03, guest PC 0x0c055d6e */
if(!s->budget--) { s->failed_pc=0x0c055d6eu; return 0; }
r[14]=r[0];
goto P_0c055d70;
P_0c055d70: /* original ed10, guest PC 0x0c055d70 */
if(!s->budget--) { s->failed_pc=0x0c055d70u; return 0; }
r[13]=0x00000010u;
goto P_0c055d72;
P_0c055d72: /* original 61e2, guest PC 0x0c055d72 */
if(!s->budget--) { s->failed_pc=0x0c055d72u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c055d74;
P_0c055d74: /* original 4115, guest PC 0x0c055d74 */
if(!s->budget--) { s->failed_pc=0x0c055d74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d76;
P_0c055d76: /* original 8f0b, guest PC 0x0c055d76 */
if(!s->budget--) { s->failed_pc=0x0c055d76u; return 0; }
cond=r[17]&1u;
r[4]=r[14];
if(!cond) { goto P_0c055d90; }
goto P_0c055d7a;
P_0c055d78: /* original 64e3, guest PC 0x0c055d78 */
if(!s->budget--) { s->failed_pc=0x0c055d78u; return 0; }
r[4]=r[14];
goto P_0c055d7a;
P_0c055d7a: /* original 7440, guest PC 0x0c055d7a */
if(!s->budget--) { s->failed_pc=0x0c055d7au; return 0; }
r[4]+=0x00000040u;
goto P_0c055d7c;
P_0c055d7c: /* original 65e3, guest PC 0x0c055d7c */
if(!s->budget--) { s->failed_pc=0x0c055d7cu; return 0; }
r[5]=r[14];
goto P_0c055d7e;
P_0c055d7e: /* original d311, guest PC 0x0c055d7e */
if(!s->budget--) { s->failed_pc=0x0c055d7eu; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d80;
P_0c055d80: /* original 430b, guest PC 0x0c055d80 */
if(!s->budget--) { s->failed_pc=0x0c055d80u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d84u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d84u) { target=s->pc; goto dispatch; }
goto P_0c055d84;
P_0c055d82: /* original 7568, guest PC 0x0c055d82 */
if(!s->budget--) { s->failed_pc=0x0c055d82u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d84;
P_0c055d84: /* original 64e3, guest PC 0x0c055d84 */
if(!s->budget--) { s->failed_pc=0x0c055d84u; return 0; }
r[4]=r[14];
goto P_0c055d86;
P_0c055d86: /* original 7434, guest PC 0x0c055d86 */
if(!s->budget--) { s->failed_pc=0x0c055d86u; return 0; }
r[4]+=0x00000034u;
goto P_0c055d88;
P_0c055d88: /* original 65e3, guest PC 0x0c055d88 */
if(!s->budget--) { s->failed_pc=0x0c055d88u; return 0; }
r[5]=r[14];
goto P_0c055d8a;
P_0c055d8a: /* original d30f, guest PC 0x0c055d8a */
if(!s->budget--) { s->failed_pc=0x0c055d8au; return 0; }
r[3]=read(ram,0x0c055dc8u,4);
goto P_0c055d8c;
P_0c055d8c: /* original 430b, guest PC 0x0c055d8c */
if(!s->budget--) { s->failed_pc=0x0c055d8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c055d90u;
r[5]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d90u) { target=s->pc; goto dispatch; }
goto P_0c055d90;
P_0c055d8e: /* original 755c, guest PC 0x0c055d8e */
if(!s->budget--) { s->failed_pc=0x0c055d8eu; return 0; }
r[5]+=0x0000005cu;
goto P_0c055d90;
P_0c055d90: /* original e3b0, guest PC 0x0c055d90 */
if(!s->budget--) { s->failed_pc=0x0c055d90u; return 0; }
r[3]=0xffffffb0u;
goto P_0c055d92;
P_0c055d92: /* original 623c, guest PC 0x0c055d92 */
if(!s->budget--) { s->failed_pc=0x0c055d92u; return 0; }
r[2]=r[3]&255u;
goto P_0c055d94;
P_0c055d94: /* original 4d10, guest PC 0x0c055d94 */
if(!s->budget--) { s->failed_pc=0x0c055d94u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c055d96;
P_0c055d96: /* original 8fec, guest PC 0x0c055d96 */
if(!s->budget--) { s->failed_pc=0x0c055d96u; return 0; }
cond=r[17]&1u;
r[14]+=r[2];
if(!cond) { goto P_0c055d72; }
goto P_0c055d9a;
P_0c055d98: /* original 3e2c, guest PC 0x0c055d98 */
if(!s->budget--) { s->failed_pc=0x0c055d98u; return 0; }
r[14]+=r[2];
goto P_0c055d9a;
P_0c055d9a: /* original 6df6, guest PC 0x0c055d9a */
if(!s->budget--) { s->failed_pc=0x0c055d9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055d9c;
P_0c055d9c: /* original 6ef6, guest PC 0x0c055d9c */
if(!s->budget--) { s->failed_pc=0x0c055d9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055d9e;
P_0c055d9e: /* original d00c, guest PC 0x0c055d9e */
if(!s->budget--) { s->failed_pc=0x0c055d9eu; return 0; }
r[0]=read(ram,0x0c055dd0u,4);
goto P_0c055da0;
P_0c055da0: /* original e380, guest PC 0x0c055da0 */
if(!s->budget--) { s->failed_pc=0x0c055da0u; return 0; }
r[3]=0xffffff80u;
goto P_0c055da2;
P_0c055da2: /* original d10e, guest PC 0x0c055da2 */
if(!s->budget--) { s->failed_pc=0x0c055da2u; return 0; }
r[1]=read(ram,0x0c055ddcu,4);
goto P_0c055da4;
P_0c055da4: /* original 633c, guest PC 0x0c055da4 */
if(!s->budget--) { s->failed_pc=0x0c055da4u; return 0; }
r[3]=r[3]&255u;
goto P_0c055da6;
P_0c055da6: /* original d20e, guest PC 0x0c055da6 */
if(!s->budget--) { s->failed_pc=0x0c055da6u; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055da8;
P_0c055da8: /* original c204, guest PC 0x0c055da8 */
if(!s->budget--) { s->failed_pc=0x0c055da8u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055daa;
P_0c055daa: /* original 6013, guest PC 0x0c055daa */
if(!s->budget--) { s->failed_pc=0x0c055daau; return 0; }
r[0]=r[1];
goto P_0c055dac;
P_0c055dac: /* original c205, guest PC 0x0c055dac */
if(!s->budget--) { s->failed_pc=0x0c055dacu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055dae;
P_0c055dae: /* original 6023, guest PC 0x0c055dae */
if(!s->budget--) { s->failed_pc=0x0c055daeu; return 0; }
r[0]=r[2];
goto P_0c055db0;
P_0c055db0: /* original 303c, guest PC 0x0c055db0 */
if(!s->budget--) { s->failed_pc=0x0c055db0u; return 0; }
r[0]+=r[3];
goto P_0c055db2;
P_0c055db2: /* original c203, guest PC 0x0c055db2 */
if(!s->budget--) { s->failed_pc=0x0c055db2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055db4: /* original 4f26, guest PC 0x0c055db4 */
if(!s->budget--) { s->failed_pc=0x0c055db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055db6;
P_0c055db6: /* original 000b, guest PC 0x0c055db6 */
if(!s->budget--) { s->failed_pc=0x0c055db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055db8: /* original 0009, guest PC 0x0c055db8 */
if(!s->budget--) { s->failed_pc=0x0c055db8u; return 0; }
if(!vf3_matrix_family(0x0c055dbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055dbau; return 0; } return 1;
P_0c059840: /* original 2fe6, guest PC 0x0c059840 */
if(!s->budget--) { s->failed_pc=0x0c059840u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059842;
P_0c059842: /* original 2fd6, guest PC 0x0c059842 */
if(!s->budget--) { s->failed_pc=0x0c059842u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059844;
P_0c059844: /* original 2fc6, guest PC 0x0c059844 */
if(!s->budget--) { s->failed_pc=0x0c059844u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059846;
P_0c059846: /* original 2fb6, guest PC 0x0c059846 */
if(!s->budget--) { s->failed_pc=0x0c059846u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059848;
P_0c059848: /* original 4f22, guest PC 0x0c059848 */
if(!s->budget--) { s->failed_pc=0x0c059848u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05984a;
P_0c05984a: /* original d32a, guest PC 0x0c05984a */
if(!s->budget--) { s->failed_pc=0x0c05984au; return 0; }
r[3]=read(ram,0x0c0598f4u,4);
goto P_0c05984c;
P_0c05984c: /* original de2a, guest PC 0x0c05984c */
if(!s->budget--) { s->failed_pc=0x0c05984cu; return 0; }
r[14]=read(ram,0x0c0598f8u,4);
goto P_0c05984e;
P_0c05984e: /* original 6432, guest PC 0x0c05984e */
if(!s->budget--) { s->failed_pc=0x0c05984eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059850;
P_0c059850: /* original d22a, guest PC 0x0c059850 */
if(!s->budget--) { s->failed_pc=0x0c059850u; return 0; }
r[2]=read(ram,0x0c0598fcu,4);
goto P_0c059852;
P_0c059852: /* original 6442, guest PC 0x0c059852 */
if(!s->budget--) { s->failed_pc=0x0c059852u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c059854;
P_0c059854: /* original 6543, guest PC 0x0c059854 */
if(!s->budget--) { s->failed_pc=0x0c059854u; return 0; }
r[5]=r[4];
goto P_0c059856;
P_0c059856: /* original 4529, guest PC 0x0c059856 */
if(!s->budget--) { s->failed_pc=0x0c059856u; return 0; }
r[5]>>=16;
goto P_0c059858;
P_0c059858: /* original 4519, guest PC 0x0c059858 */
if(!s->budget--) { s->failed_pc=0x0c059858u; return 0; }
r[5]>>=8;
goto P_0c05985a;
P_0c05985a: /* original 2252, guest PC 0x0c05985a */
if(!s->budget--) { s->failed_pc=0x0c05985au; return 0; }
write(ram,r[2],r[5],4);
goto P_0c05985c;
P_0c05985c: /* original d128, guest PC 0x0c05985c */
if(!s->budget--) { s->failed_pc=0x0c05985cu; return 0; }
r[1]=read(ram,0x0c059900u,4);
goto P_0c05985e;
P_0c05985e: /* original 2152, guest PC 0x0c05985e */
if(!s->budget--) { s->failed_pc=0x0c05985eu; return 0; }
write(ram,r[1],r[5],4);
goto P_0c059860;
P_0c059860: /* original dd28, guest PC 0x0c059860 */
if(!s->budget--) { s->failed_pc=0x0c059860u; return 0; }
r[13]=read(ram,0x0c059904u,4);
goto P_0c059862;
P_0c059862: /* original ec04, guest PC 0x0c059862 */
if(!s->budget--) { s->failed_pc=0x0c059862u; return 0; }
r[12]=0x00000004u;
goto P_0c059864;
P_0c059864: /* original d328, guest PC 0x0c059864 */
if(!s->budget--) { s->failed_pc=0x0c059864u; return 0; }
r[3]=read(ram,0x0c059908u,4);
goto P_0c059866;
P_0c059866: /* original 2d49, guest PC 0x0c059866 */
if(!s->budget--) { s->failed_pc=0x0c059866u; return 0; }
r[13]&=r[4];
goto P_0c059868;
P_0c059868: /* original db28, guest PC 0x0c059868 */
if(!s->budget--) { s->failed_pc=0x0c059868u; return 0; }
r[11]=read(ram,0x0c05990cu,4);
goto P_0c05986a;
P_0c05986a: /* original 2d3b, guest PC 0x0c05986a */
if(!s->budget--) { s->failed_pc=0x0c05986au; return 0; }
r[13]|=r[3];
goto P_0c05986c;
P_0c05986c: /* original e620, guest PC 0x0c05986c */
if(!s->budget--) { s->failed_pc=0x0c05986cu; return 0; }
r[6]=0x00000020u;
goto P_0c05986e;
P_0c05986e: /* original 65e3, guest PC 0x0c05986e */
if(!s->budget--) { s->failed_pc=0x0c05986eu; return 0; }
r[5]=r[14];
goto P_0c059870;
P_0c059870: /* original 4b0b, guest PC 0x0c059870 */
if(!s->budget--) { s->failed_pc=0x0c059870u; return 0; }
target=r[11];
r[16]=code_base|0x0c059874u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059874u) { target=s->pc; goto dispatch; }
goto P_0c059874;
P_0c059872: /* original 64d3, guest PC 0x0c059872 */
if(!s->budget--) { s->failed_pc=0x0c059872u; return 0; }
r[4]=r[13];
goto P_0c059874;
P_0c059874: /* original 0d83, guest PC 0x0c059874 */
if(!s->budget--) { s->failed_pc=0x0c059874u; return 0; }
if((r[13]&0xFC000000u)==0xE0000000u) pref(ram,r[13]);
goto P_0c059876;
P_0c059876: /* original 7d20, guest PC 0x0c059876 */
if(!s->budget--) { s->failed_pc=0x0c059876u; return 0; }
r[13]+=0x00000020u;
goto P_0c059878;
P_0c059878: /* original 4c10, guest PC 0x0c059878 */
if(!s->budget--) { s->failed_pc=0x0c059878u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c05987a;
P_0c05987a: /* original 8ff7, guest PC 0x0c05987a */
if(!s->budget--) { s->failed_pc=0x0c05987au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000020u;
if(!cond) { goto P_0c05986c; }
goto P_0c05987e;
P_0c05987c: /* original 7e20, guest PC 0x0c05987c */
if(!s->budget--) { s->failed_pc=0x0c05987cu; return 0; }
r[14]+=0x00000020u;
goto P_0c05987e;
P_0c05987e: /* original d21d, guest PC 0x0c05987e */
if(!s->budget--) { s->failed_pc=0x0c05987eu; return 0; }
r[2]=read(ram,0x0c0598f4u,4);
goto P_0c059880;
P_0c059880: /* original 9136, guest PC 0x0c059880 */
if(!s->budget--) { s->failed_pc=0x0c059880u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0598f0u,2);
goto P_0c059882;
P_0c059882: /* original 6322, guest PC 0x0c059882 */
if(!s->budget--) { s->failed_pc=0x0c059882u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059884;
P_0c059884: /* original 6032, guest PC 0x0c059884 */
if(!s->budget--) { s->failed_pc=0x0c059884u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059886;
P_0c059886: /* original 301c, guest PC 0x0c059886 */
if(!s->budget--) { s->failed_pc=0x0c059886u; return 0; }
r[0]+=r[1];
goto P_0c059888;
P_0c059888: /* original 2302, guest PC 0x0c059888 */
if(!s->budget--) { s->failed_pc=0x0c059888u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05988a;
P_0c05988a: /* original 4f26, guest PC 0x0c05988a */
if(!s->budget--) { s->failed_pc=0x0c05988au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05988c;
P_0c05988c: /* original 6bf6, guest PC 0x0c05988c */
if(!s->budget--) { s->failed_pc=0x0c05988cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05988e;
P_0c05988e: /* original 6cf6, guest PC 0x0c05988e */
if(!s->budget--) { s->failed_pc=0x0c05988eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059890;
P_0c059890: /* original 6df6, guest PC 0x0c059890 */
if(!s->budget--) { s->failed_pc=0x0c059890u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059892;
P_0c059892: /* original 000b, guest PC 0x0c059892 */
if(!s->budget--) { s->failed_pc=0x0c059892u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059894: /* original 6ef6, guest PC 0x0c059894 */
if(!s->budget--) { s->failed_pc=0x0c059894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c059896u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059896u; return 0; } return 1;
P_0c059a20: /* original 2fe6, guest PC 0x0c059a20 */
if(!s->budget--) { s->failed_pc=0x0c059a20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a22;
P_0c059a22: /* original 2fd6, guest PC 0x0c059a22 */
if(!s->budget--) { s->failed_pc=0x0c059a22u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a24;
P_0c059a24: /* original 2fc6, guest PC 0x0c059a24 */
if(!s->budget--) { s->failed_pc=0x0c059a24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a26;
P_0c059a26: /* original 2fb6, guest PC 0x0c059a26 */
if(!s->budget--) { s->failed_pc=0x0c059a26u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a28;
P_0c059a28: /* original 2fa6, guest PC 0x0c059a28 */
if(!s->budget--) { s->failed_pc=0x0c059a28u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2a;
P_0c059a2a: /* original 2f96, guest PC 0x0c059a2a */
if(!s->budget--) { s->failed_pc=0x0c059a2au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2c;
P_0c059a2c: /* original 2f86, guest PC 0x0c059a2c */
if(!s->budget--) { s->failed_pc=0x0c059a2cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2e;
P_0c059a2e: /* original 4f22, guest PC 0x0c059a2e */
if(!s->budget--) { s->failed_pc=0x0c059a2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059a30;
P_0c059a30: /* original d337, guest PC 0x0c059a30 */
if(!s->budget--) { s->failed_pc=0x0c059a30u; return 0; }
r[3]=read(ram,0x0c059b10u,4);
goto P_0c059a32;
P_0c059a32: /* original 7ff8, guest PC 0x0c059a32 */
if(!s->budget--) { s->failed_pc=0x0c059a32u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059a34;
P_0c059a34: /* original 1f41, guest PC 0x0c059a34 */
if(!s->budget--) { s->failed_pc=0x0c059a34u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c059a36;
P_0c059a36: /* original 6432, guest PC 0x0c059a36 */
if(!s->budget--) { s->failed_pc=0x0c059a36u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059a38;
P_0c059a38: /* original 6543, guest PC 0x0c059a38 */
if(!s->budget--) { s->failed_pc=0x0c059a38u; return 0; }
r[5]=r[4];
goto P_0c059a3a;
P_0c059a3a: /* original 4508, guest PC 0x0c059a3a */
if(!s->budget--) { s->failed_pc=0x0c059a3au; return 0; }
r[5]<<=2;
goto P_0c059a3c;
P_0c059a3c: /* original d935, guest PC 0x0c059a3c */
if(!s->budget--) { s->failed_pc=0x0c059a3cu; return 0; }
r[9]=read(ram,0x0c059b14u,4);
goto P_0c059a3e;
P_0c059a3e: /* original ee00, guest PC 0x0c059a3e */
if(!s->budget--) { s->failed_pc=0x0c059a3eu; return 0; }
r[14]=0x00000000u;
goto P_0c059a40;
P_0c059a40: /* original db35, guest PC 0x0c059a40 */
if(!s->budget--) { s->failed_pc=0x0c059a40u; return 0; }
r[11]=read(ram,0x0c059b18u,4);
goto P_0c059a42;
P_0c059a42: /* original 395c, guest PC 0x0c059a42 */
if(!s->budget--) { s->failed_pc=0x0c059a42u; return 0; }
r[9]+=r[5];
goto P_0c059a44;
P_0c059a44: /* original d835, guest PC 0x0c059a44 */
if(!s->budget--) { s->failed_pc=0x0c059a44u; return 0; }
r[8]=read(ram,0x0c059b1cu,4);
goto P_0c059a46;
P_0c059a46: /* original 3b5c, guest PC 0x0c059a46 */
if(!s->budget--) { s->failed_pc=0x0c059a46u; return 0; }
r[11]+=r[5];
goto P_0c059a48;
P_0c059a48: /* original da35, guest PC 0x0c059a48 */
if(!s->budget--) { s->failed_pc=0x0c059a48u; return 0; }
r[10]=read(ram,0x0c059b20u,4);
goto P_0c059a4a;
P_0c059a4a: /* original dc36, guest PC 0x0c059a4a */
if(!s->budget--) { s->failed_pc=0x0c059a4au; return 0; }
r[12]=read(ram,0x0c059b24u,4);
goto P_0c059a4c;
P_0c059a4c: /* original 9d5f, guest PC 0x0c059a4c */
if(!s->budget--) { s->failed_pc=0x0c059a4cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059b0eu,2);
goto P_0c059a4e;
P_0c059a4e: /* original 62b2, guest PC 0x0c059a4e */
if(!s->budget--) { s->failed_pc=0x0c059a4eu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c059a50;
P_0c059a50: /* original 2228, guest PC 0x0c059a50 */
if(!s->budget--) { s->failed_pc=0x0c059a50u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c059a52;
P_0c059a52: /* original 8931, guest PC 0x0c059a52 */
if(!s->budget--) { s->failed_pc=0x0c059a52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059ab8; }
goto P_0c059a54;
P_0c059a54: /* original 53f1, guest PC 0x0c059a54 */
if(!s->budget--) { s->failed_pc=0x0c059a54u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c059a56;
P_0c059a56: /* original 33e0, guest PC 0x0c059a56 */
if(!s->budget--) { s->failed_pc=0x0c059a56u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[14])!=0);
goto P_0c059a58;
P_0c059a58: /* original 892e, guest PC 0x0c059a58 */
if(!s->budget--) { s->failed_pc=0x0c059a58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059ab8; }
goto P_0c059a5a;
P_0c059a5a: /* original d133, guest PC 0x0c059a5a */
if(!s->budget--) { s->failed_pc=0x0c059a5au; return 0; }
r[1]=read(ram,0x0c059b28u,4);
goto P_0c059a5c;
P_0c059a5c: /* original 6012, guest PC 0x0c059a5c */
if(!s->budget--) { s->failed_pc=0x0c059a5cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059a5e;
P_0c059a5e: /* original 8801, guest PC 0x0c059a5e */
if(!s->budget--) { s->failed_pc=0x0c059a5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059a60;
P_0c059a60: /* original 8b1f, guest PC 0x0c059a60 */
if(!s->budget--) { s->failed_pc=0x0c059a60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059aa2; }
goto P_0c059a62;
P_0c059a62: /* original 60e3, guest PC 0x0c059a62 */
if(!s->budget--) { s->failed_pc=0x0c059a62u; return 0; }
r[0]=r[14];
goto P_0c059a64;
P_0c059a64: /* original 0009, guest PC 0x0c059a64 */
if(!s->budget--) { s->failed_pc=0x0c059a64u; return 0; }
goto P_0c059a66;
P_0c059a66: /* original 8801, guest PC 0x0c059a66 */
if(!s->budget--) { s->failed_pc=0x0c059a66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059a68;
P_0c059a68: /* original 8903, guest PC 0x0c059a68 */
if(!s->budget--) { s->failed_pc=0x0c059a68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059a72; }
goto P_0c059a6a;
P_0c059a6a: /* original 60e3, guest PC 0x0c059a6a */
if(!s->budget--) { s->failed_pc=0x0c059a6au; return 0; }
r[0]=r[14];
goto P_0c059a6c;
P_0c059a6c: /* original 0009, guest PC 0x0c059a6c */
if(!s->budget--) { s->failed_pc=0x0c059a6cu; return 0; }
goto P_0c059a6e;
P_0c059a6e: /* original 8803, guest PC 0x0c059a6e */
if(!s->budget--) { s->failed_pc=0x0c059a6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c059a70;
P_0c059a70: /* original 8b17, guest PC 0x0c059a70 */
if(!s->budget--) { s->failed_pc=0x0c059a70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059aa2; }
goto P_0c059a72;
P_0c059a72: /* original d32e, guest PC 0x0c059a72 */
if(!s->budget--) { s->failed_pc=0x0c059a72u; return 0; }
r[3]=read(ram,0x0c059b2cu,4);
goto P_0c059a74;
P_0c059a74: /* original 6232, guest PC 0x0c059a74 */
if(!s->budget--) { s->failed_pc=0x0c059a74u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059a76;
P_0c059a76: /* original 6033, guest PC 0x0c059a76 */
if(!s->budget--) { s->failed_pc=0x0c059a76u; return 0; }
r[0]=r[3];
goto P_0c059a78;
P_0c059a78: /* original 0009, guest PC 0x0c059a78 */
if(!s->budget--) { s->failed_pc=0x0c059a78u; return 0; }
goto P_0c059a7a;
P_0c059a7a: /* original 6102, guest PC 0x0c059a7a */
if(!s->budget--) { s->failed_pc=0x0c059a7au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059a7c;
P_0c059a7c: /* original 6112, guest PC 0x0c059a7c */
if(!s->budget--) { s->failed_pc=0x0c059a7cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c059a7e;
P_0c059a7e: /* original 63e3, guest PC 0x0c059a7e */
if(!s->budget--) { s->failed_pc=0x0c059a7eu; return 0; }
r[3]=r[14];
goto P_0c059a80;
P_0c059a80: /* original 2189, guest PC 0x0c059a80 */
if(!s->budget--) { s->failed_pc=0x0c059a80u; return 0; }
r[1]&=r[8];
goto P_0c059a82;
P_0c059a82: /* original 4328, guest PC 0x0c059a82 */
if(!s->budget--) { s->failed_pc=0x0c059a82u; return 0; }
r[3]<<=16;
goto P_0c059a84;
P_0c059a84: /* original 4318, guest PC 0x0c059a84 */
if(!s->budget--) { s->failed_pc=0x0c059a84u; return 0; }
r[3]<<=8;
goto P_0c059a86;
P_0c059a86: /* original 213b, guest PC 0x0c059a86 */
if(!s->budget--) { s->failed_pc=0x0c059a86u; return 0; }
r[1]|=r[3];
goto P_0c059a88;
P_0c059a88: /* original 2212, guest PC 0x0c059a88 */
if(!s->budget--) { s->failed_pc=0x0c059a88u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c059a8a;
P_0c059a8a: /* original 63f3, guest PC 0x0c059a8a */
if(!s->budget--) { s->failed_pc=0x0c059a8au; return 0; }
r[3]=r[15];
goto P_0c059a8c;
P_0c059a8c: /* original d228, guest PC 0x0c059a8c */
if(!s->budget--) { s->failed_pc=0x0c059a8cu; return 0; }
r[2]=read(ram,0x0c059b30u,4);
goto P_0c059a8e;
P_0c059a8e: /* original e710, guest PC 0x0c059a8e */
if(!s->budget--) { s->failed_pc=0x0c059a8eu; return 0; }
r[7]=0x00000010u;
goto P_0c059a90;
P_0c059a90: /* original 2f36, guest PC 0x0c059a90 */
if(!s->budget--) { s->failed_pc=0x0c059a90u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a92;
P_0c059a92: /* original 6622, guest PC 0x0c059a92 */
if(!s->budget--) { s->failed_pc=0x0c059a92u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c059a94;
P_0c059a94: /* original d325, guest PC 0x0c059a94 */
if(!s->budget--) { s->failed_pc=0x0c059a94u; return 0; }
r[3]=read(ram,0x0c059b2cu,4);
goto P_0c059a96;
P_0c059a96: /* original 6532, guest PC 0x0c059a96 */
if(!s->budget--) { s->failed_pc=0x0c059a96u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059a98;
P_0c059a98: /* original 4a0b, guest PC 0x0c059a98 */
if(!s->budget--) { s->failed_pc=0x0c059a98u; return 0; }
target=r[10];
r[16]=code_base|0x0c059a9cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059a9cu) { target=s->pc; goto dispatch; }
goto P_0c059a9c;
P_0c059a9a: /* original 64c3, guest PC 0x0c059a9a */
if(!s->budget--) { s->failed_pc=0x0c059a9au; return 0; }
r[4]=r[12];
goto P_0c059a9c;
P_0c059a9c: /* original 30d0, guest PC 0x0c059a9c */
if(!s->budget--) { s->failed_pc=0x0c059a9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c059a9e;
P_0c059a9e: /* original 8df4, guest PC 0x0c059a9e */
if(!s->budget--) { s->failed_pc=0x0c059a9eu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059a8a; }
goto P_0c059aa2;
P_0c059aa0: /* original 7f04, guest PC 0x0c059aa0 */
if(!s->budget--) { s->failed_pc=0x0c059aa0u; return 0; }
r[15]+=0x00000004u;
goto P_0c059aa2;
P_0c059aa2: /* original 62f3, guest PC 0x0c059aa2 */
if(!s->budget--) { s->failed_pc=0x0c059aa2u; return 0; }
r[2]=r[15];
goto P_0c059aa4;
P_0c059aa4: /* original 2f26, guest PC 0x0c059aa4 */
if(!s->budget--) { s->failed_pc=0x0c059aa4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059aa6;
P_0c059aa6: /* original e710, guest PC 0x0c059aa6 */
if(!s->budget--) { s->failed_pc=0x0c059aa6u; return 0; }
r[7]=0x00000010u;
goto P_0c059aa8;
P_0c059aa8: /* original 66b2, guest PC 0x0c059aa8 */
if(!s->budget--) { s->failed_pc=0x0c059aa8u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c059aaa;
P_0c059aaa: /* original 7620, guest PC 0x0c059aaa */
if(!s->budget--) { s->failed_pc=0x0c059aaau; return 0; }
r[6]+=0x00000020u;
goto P_0c059aac;
P_0c059aac: /* original 6592, guest PC 0x0c059aac */
if(!s->budget--) { s->failed_pc=0x0c059aacu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c059aae;
P_0c059aae: /* original 4a0b, guest PC 0x0c059aae */
if(!s->budget--) { s->failed_pc=0x0c059aaeu; return 0; }
target=r[10];
r[16]=code_base|0x0c059ab2u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059ab2u) { target=s->pc; goto dispatch; }
goto P_0c059ab2;
P_0c059ab0: /* original 64c3, guest PC 0x0c059ab0 */
if(!s->budget--) { s->failed_pc=0x0c059ab0u; return 0; }
r[4]=r[12];
goto P_0c059ab2;
P_0c059ab2: /* original 30d0, guest PC 0x0c059ab2 */
if(!s->budget--) { s->failed_pc=0x0c059ab2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c059ab4;
P_0c059ab4: /* original 8df5, guest PC 0x0c059ab4 */
if(!s->budget--) { s->failed_pc=0x0c059ab4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059aa2; }
goto P_0c059ab8;
P_0c059ab6: /* original 7f04, guest PC 0x0c059ab6 */
if(!s->budget--) { s->failed_pc=0x0c059ab6u; return 0; }
r[15]+=0x00000004u;
goto P_0c059ab8;
P_0c059ab8: /* original 7b10, guest PC 0x0c059ab8 */
if(!s->budget--) { s->failed_pc=0x0c059ab8u; return 0; }
r[11]+=0x00000010u;
goto P_0c059aba;
P_0c059aba: /* original 7e01, guest PC 0x0c059aba */
if(!s->budget--) { s->failed_pc=0x0c059abau; return 0; }
r[14]+=0x00000001u;
goto P_0c059abc;
P_0c059abc: /* original e205, guest PC 0x0c059abc */
if(!s->budget--) { s->failed_pc=0x0c059abcu; return 0; }
r[2]=0x00000005u;
goto P_0c059abe;
P_0c059abe: /* original 3e22, guest PC 0x0c059abe */
if(!s->budget--) { s->failed_pc=0x0c059abeu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c059ac0;
P_0c059ac0: /* original 8fc5, guest PC 0x0c059ac0 */
if(!s->budget--) { s->failed_pc=0x0c059ac0u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000010u;
if(!cond) { goto P_0c059a4e; }
goto P_0c059ac4;
P_0c059ac2: /* original 7910, guest PC 0x0c059ac2 */
if(!s->budget--) { s->failed_pc=0x0c059ac2u; return 0; }
r[9]+=0x00000010u;
goto P_0c059ac4;
P_0c059ac4: /* original 7f08, guest PC 0x0c059ac4 */
if(!s->budget--) { s->failed_pc=0x0c059ac4u; return 0; }
r[15]+=0x00000008u;
goto P_0c059ac6;
P_0c059ac6: /* original 4f26, guest PC 0x0c059ac6 */
if(!s->budget--) { s->failed_pc=0x0c059ac6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059ac8;
P_0c059ac8: /* original 68f6, guest PC 0x0c059ac8 */
if(!s->budget--) { s->failed_pc=0x0c059ac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c059aca;
P_0c059aca: /* original 69f6, guest PC 0x0c059aca */
if(!s->budget--) { s->failed_pc=0x0c059acau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c059acc;
P_0c059acc: /* original 6af6, guest PC 0x0c059acc */
if(!s->budget--) { s->failed_pc=0x0c059accu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c059ace;
P_0c059ace: /* original 6bf6, guest PC 0x0c059ace */
if(!s->budget--) { s->failed_pc=0x0c059aceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c059ad0;
P_0c059ad0: /* original 6cf6, guest PC 0x0c059ad0 */
if(!s->budget--) { s->failed_pc=0x0c059ad0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059ad2;
P_0c059ad2: /* original 6df6, guest PC 0x0c059ad2 */
if(!s->budget--) { s->failed_pc=0x0c059ad2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059ad4;
P_0c059ad4: /* original 000b, guest PC 0x0c059ad4 */
if(!s->budget--) { s->failed_pc=0x0c059ad4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059ad6: /* original 6ef6, guest PC 0x0c059ad6 */
if(!s->budget--) { s->failed_pc=0x0c059ad6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c059ad8u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
