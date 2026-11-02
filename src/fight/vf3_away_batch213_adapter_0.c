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
int vf3_away_batch213_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c09553cu: goto P_0c09553c;
case 0x0c09553eu: goto P_0c09553e;
case 0x0c095540u: goto P_0c095540;
case 0x0c095542u: goto P_0c095542;
case 0x0c095544u: goto P_0c095544;
case 0x0c095546u: goto P_0c095546;
case 0x0c095548u: goto P_0c095548;
case 0x0c09554au: goto P_0c09554a;
case 0x0c09554cu: goto P_0c09554c;
case 0x0c09554eu: goto P_0c09554e;
case 0x0c095550u: goto P_0c095550;
case 0x0c095552u: goto P_0c095552;
case 0x0c095554u: goto P_0c095554;
case 0x0c095556u: goto P_0c095556;
case 0x0c095558u: goto P_0c095558;
case 0x0c09555au: goto P_0c09555a;
case 0x0c09555cu: goto P_0c09555c;
case 0x0c09555eu: goto P_0c09555e;
case 0x0c095560u: goto P_0c095560;
case 0x0c095562u: goto P_0c095562;
case 0x0c095564u: goto P_0c095564;
case 0x0c095566u: goto P_0c095566;
case 0x0c095568u: goto P_0c095568;
case 0x0c09556au: goto P_0c09556a;
case 0x0c09556cu: goto P_0c09556c;
case 0x0c09556eu: goto P_0c09556e;
case 0x0c095570u: goto P_0c095570;
case 0x0c095572u: goto P_0c095572;
case 0x0c095574u: goto P_0c095574;
case 0x0c095576u: goto P_0c095576;
case 0x0c095578u: goto P_0c095578;
case 0x0c09557au: goto P_0c09557a;
case 0x0c09557cu: goto P_0c09557c;
case 0x0c09557eu: goto P_0c09557e;
case 0x0c095580u: goto P_0c095580;
case 0x0c095582u: goto P_0c095582;
case 0x0c0ad578u: goto P_0c0ad578;
case 0x0c0ad57au: goto P_0c0ad57a;
case 0x0c0ad57cu: goto P_0c0ad57c;
case 0x0c0ad57eu: goto P_0c0ad57e;
case 0x0c0ad580u: goto P_0c0ad580;
case 0x0c0ad582u: goto P_0c0ad582;
case 0x0c0ad584u: goto P_0c0ad584;
case 0x0c0ad586u: goto P_0c0ad586;
case 0x0c0ad588u: goto P_0c0ad588;
case 0x0c0ade24u: goto P_0c0ade24;
case 0x0c0ade26u: goto P_0c0ade26;
case 0x0c0ade28u: goto P_0c0ade28;
case 0x0c0ade2au: goto P_0c0ade2a;
case 0x0c0ade2cu: goto P_0c0ade2c;
case 0x0c0ade2eu: goto P_0c0ade2e;
case 0x0c0ade30u: goto P_0c0ade30;
case 0x0c0ade32u: goto P_0c0ade32;
case 0x0c0ade34u: goto P_0c0ade34;
case 0x0c0ade36u: goto P_0c0ade36;
case 0x0c0ade38u: goto P_0c0ade38;
case 0x0c0ade3au: goto P_0c0ade3a;
case 0x0c0ade3cu: goto P_0c0ade3c;
case 0x0c0ade3eu: goto P_0c0ade3e;
case 0x0c0ade40u: goto P_0c0ade40;
case 0x0c0ade42u: goto P_0c0ade42;
case 0x0c0ade44u: goto P_0c0ade44;
case 0x0c0ade46u: goto P_0c0ade46;
case 0x0c0ade48u: goto P_0c0ade48;
case 0x0c0ade4au: goto P_0c0ade4a;
case 0x0c0ade4cu: goto P_0c0ade4c;
case 0x0c0ade4eu: goto P_0c0ade4e;
case 0x0c0ade50u: goto P_0c0ade50;
case 0x0c0ade52u: goto P_0c0ade52;
case 0x0c0ade54u: goto P_0c0ade54;
case 0x0c0ade56u: goto P_0c0ade56;
case 0x0c0ade58u: goto P_0c0ade58;
case 0x0c0ade5au: goto P_0c0ade5a;
case 0x0c0ade5cu: goto P_0c0ade5c;
case 0x0c0ade5eu: goto P_0c0ade5e;
case 0x0c0ade60u: goto P_0c0ade60;
case 0x0c0ade62u: goto P_0c0ade62;
case 0x0c0ade64u: goto P_0c0ade64;
case 0x0c0ade66u: goto P_0c0ade66;
case 0x0c0ade68u: goto P_0c0ade68;
case 0x0c0ade6au: goto P_0c0ade6a;
case 0x0c0ade6cu: goto P_0c0ade6c;
case 0x0c0ade6eu: goto P_0c0ade6e;
case 0x0c0ade70u: goto P_0c0ade70;
case 0x0c0ade72u: goto P_0c0ade72;
case 0x0c0ade74u: goto P_0c0ade74;
case 0x0c0ade76u: goto P_0c0ade76;
case 0x0c0ade78u: goto P_0c0ade78;
case 0x0c0ade7au: goto P_0c0ade7a;
case 0x0c0ade7cu: goto P_0c0ade7c;
case 0x0c0ade7eu: goto P_0c0ade7e;
case 0x0c0ade80u: goto P_0c0ade80;
case 0x0c0ade82u: goto P_0c0ade82;
case 0x0c0ade84u: goto P_0c0ade84;
case 0x0c0ade86u: goto P_0c0ade86;
case 0x0c0ade88u: goto P_0c0ade88;
case 0x0c0ade8au: goto P_0c0ade8a;
case 0x0c0ade8cu: goto P_0c0ade8c;
case 0x0c0ade8eu: goto P_0c0ade8e;
case 0x0c0ade90u: goto P_0c0ade90;
case 0x0c0ade92u: goto P_0c0ade92;
case 0x0c0ade94u: goto P_0c0ade94;
case 0x0c0ade96u: goto P_0c0ade96;
case 0x0c0ade98u: goto P_0c0ade98;
case 0x0c0ade9au: goto P_0c0ade9a;
case 0x0c0ade9cu: goto P_0c0ade9c;
case 0x0c0ade9eu: goto P_0c0ade9e;
case 0x0c0adea0u: goto P_0c0adea0;
case 0x0c0adea2u: goto P_0c0adea2;
case 0x0c0adea4u: goto P_0c0adea4;
case 0x0c0adea6u: goto P_0c0adea6;
case 0x0c0adea8u: goto P_0c0adea8;
case 0x0c0adeaau: goto P_0c0adeaa;
case 0x0c0adeacu: goto P_0c0adeac;
case 0x0c0adeaeu: goto P_0c0adeae;
case 0x0c0adeb0u: goto P_0c0adeb0;
case 0x0c0adeb2u: goto P_0c0adeb2;
case 0x0c0adeb4u: goto P_0c0adeb4;
case 0x0c0adeb6u: goto P_0c0adeb6;
case 0x0c0adeb8u: goto P_0c0adeb8;
case 0x0c0adebau: goto P_0c0adeba;
case 0x0c0adebcu: goto P_0c0adebc;
case 0x0c0adebeu: goto P_0c0adebe;
case 0x0c0adec0u: goto P_0c0adec0;
case 0x0c0adec2u: goto P_0c0adec2;
case 0x0c0adec4u: goto P_0c0adec4;
case 0x0c0adec6u: goto P_0c0adec6;
case 0x0c0adec8u: goto P_0c0adec8;
case 0x0c0adecau: goto P_0c0adeca;
case 0x0c0adeccu: goto P_0c0adecc;
case 0x0c0adeceu: goto P_0c0adece;
case 0x0c0aded0u: goto P_0c0aded0;
case 0x0c0aded2u: goto P_0c0aded2;
case 0x0c0aded4u: goto P_0c0aded4;
case 0x0c0aded6u: goto P_0c0aded6;
case 0x0c0aded8u: goto P_0c0aded8;
case 0x0c0adedau: goto P_0c0adeda;
case 0x0c0adedcu: goto P_0c0adedc;
case 0x0c0adedeu: goto P_0c0adede;
case 0x0c0adee0u: goto P_0c0adee0;
case 0x0c0adee2u: goto P_0c0adee2;
case 0x0c0adee4u: goto P_0c0adee4;
case 0x0c0adee6u: goto P_0c0adee6;
case 0x0c0adee8u: goto P_0c0adee8;
case 0x0c0adeeau: goto P_0c0adeea;
case 0x0c0adeecu: goto P_0c0adeec;
case 0x0c0adeeeu: goto P_0c0adeee;
case 0x0c0adef0u: goto P_0c0adef0;
case 0x0c0adef2u: goto P_0c0adef2;
case 0x0c0adef4u: goto P_0c0adef4;
case 0x0c0adef6u: goto P_0c0adef6;
case 0x0c0adef8u: goto P_0c0adef8;
case 0x0c0adefau: goto P_0c0adefa;
case 0x0c0adefcu: goto P_0c0adefc;
case 0x0c0adefeu: goto P_0c0adefe;
case 0x0c0adf00u: goto P_0c0adf00;
case 0x0c0adf02u: goto P_0c0adf02;
case 0x0c0adf04u: goto P_0c0adf04;
case 0x0c0adf06u: goto P_0c0adf06;
case 0x0c0adf08u: goto P_0c0adf08;
case 0x0c0adf0au: goto P_0c0adf0a;
case 0x0c0adf0cu: goto P_0c0adf0c;
case 0x0c0adf0eu: goto P_0c0adf0e;
case 0x0c0adf10u: goto P_0c0adf10;
case 0x0c0adf12u: goto P_0c0adf12;
case 0x0c0adf14u: goto P_0c0adf14;
case 0x0c0adf16u: goto P_0c0adf16;
case 0x0c0adf18u: goto P_0c0adf18;
case 0x0c0adf1au: goto P_0c0adf1a;
case 0x0c0adf1cu: goto P_0c0adf1c;
case 0x0c0adf38u: goto P_0c0adf38;
case 0x0c0adf3au: goto P_0c0adf3a;
case 0x0c0adf3cu: goto P_0c0adf3c;
case 0x0c0adf3eu: goto P_0c0adf3e;
case 0x0c0adf40u: goto P_0c0adf40;
case 0x0c0adf42u: goto P_0c0adf42;
case 0x0c0adf44u: goto P_0c0adf44;
case 0x0c0adf46u: goto P_0c0adf46;
case 0x0c0adf48u: goto P_0c0adf48;
case 0x0c0adf4au: goto P_0c0adf4a;
case 0x0c0adf4cu: goto P_0c0adf4c;
case 0x0c0adf4eu: goto P_0c0adf4e;
case 0x0c0adf50u: goto P_0c0adf50;
case 0x0c0adf52u: goto P_0c0adf52;
case 0x0c0adf54u: goto P_0c0adf54;
case 0x0c0adf56u: goto P_0c0adf56;
case 0x0c0adf58u: goto P_0c0adf58;
case 0x0c0adf5au: goto P_0c0adf5a;
case 0x0c0adf5cu: goto P_0c0adf5c;
case 0x0c0adf5eu: goto P_0c0adf5e;
case 0x0c0adf60u: goto P_0c0adf60;
case 0x0c0adf62u: goto P_0c0adf62;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c09553c: /* original fffb, guest PC 0x0c09553c */
if(!s->budget--) { s->failed_pc=0x0c09553cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09553e;
P_0c09553e: /* original 4f22, guest PC 0x0c09553e */
if(!s->budget--) { s->failed_pc=0x0c09553eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095540;
P_0c095540: /* original 7ff0, guest PC 0x0c095540 */
if(!s->budget--) { s->failed_pc=0x0c095540u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c095542;
P_0c095542: /* original 1f42, guest PC 0x0c095542 */
if(!s->budget--) { s->failed_pc=0x0c095542u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c095544;
P_0c095544: /* original 2f52, guest PC 0x0c095544 */
if(!s->budget--) { s->failed_pc=0x0c095544u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c095546;
P_0c095546: /* original 1f61, guest PC 0x0c095546 */
if(!s->budget--) { s->failed_pc=0x0c095546u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c095548;
P_0c095548: /* original 54f2, guest PC 0x0c095548 */
if(!s->budget--) { s->failed_pc=0x0c095548u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09554a;
P_0c09554a: /* original d369, guest PC 0x0c09554a */
if(!s->budget--) { s->failed_pc=0x0c09554au; return 0; }
r[3]=read(ram,0x0c0956f0u,4);
goto P_0c09554c;
P_0c09554c: /* original 644f, guest PC 0x0c09554c */
if(!s->budget--) { s->failed_pc=0x0c09554cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09554e;
P_0c09554e: /* original 430b, guest PC 0x0c09554e */
if(!s->budget--) { s->failed_pc=0x0c09554eu; return 0; }
target=r[3];
r[16]=code_base|0x0c095552u;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095552u) { target=s->pc; goto dispatch; }
goto P_0c095552;
P_0c095550: /* original 1f43, guest PC 0x0c095550 */
if(!s->budget--) { s->failed_pc=0x0c095550u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c095552;
P_0c095552: /* original d368, guest PC 0x0c095552 */
if(!s->budget--) { s->failed_pc=0x0c095552u; return 0; }
r[3]=read(ram,0x0c0956f4u,4);
goto P_0c095554;
P_0c095554: /* original ff0c, guest PC 0x0c095554 */
if(!s->budget--) { s->failed_pc=0x0c095554u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c095556;
P_0c095556: /* original 430b, guest PC 0x0c095556 */
if(!s->budget--) { s->failed_pc=0x0c095556u; return 0; }
target=r[3];
r[16]=code_base|0x0c09555au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09555au) { target=s->pc; goto dispatch; }
goto P_0c09555a;
P_0c095558: /* original 54f3, guest PC 0x0c095558 */
if(!s->budget--) { s->failed_pc=0x0c095558u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09555a;
P_0c09555a: /* original 62f2, guest PC 0x0c09555a */
if(!s->budget--) { s->failed_pc=0x0c09555au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09555c;
P_0c09555c: /* original f70c, guest PC 0x0c09555c */
if(!s->budget--) { s->failed_pc=0x0c09555cu; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c09555e;
P_0c09555e: /* original f628, guest PC 0x0c09555e */
if(!s->budget--) { s->failed_pc=0x0c09555eu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c095560;
P_0c095560: /* original 53f1, guest PC 0x0c095560 */
if(!s->budget--) { s->failed_pc=0x0c095560u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c095562;
P_0c095562: /* original f762, guest PC 0x0c095562 */
if(!s->budget--) { s->failed_pc=0x0c095562u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c095564;
P_0c095564: /* original f40c, guest PC 0x0c095564 */
if(!s->budget--) { s->failed_pc=0x0c095564u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c095566;
P_0c095566: /* original f538, guest PC 0x0c095566 */
if(!s->budget--) { s->failed_pc=0x0c095566u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c095568;
P_0c095568: /* original 6323, guest PC 0x0c095568 */
if(!s->budget--) { s->failed_pc=0x0c095568u; return 0; }
r[3]=r[2];
goto P_0c09556a;
P_0c09556a: /* original f05c, guest PC 0x0c09556a */
if(!s->budget--) { s->failed_pc=0x0c09556au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09556c;
P_0c09556c: /* original f452, guest PC 0x0c09556c */
if(!s->budget--) { s->failed_pc=0x0c09556cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09556e;
P_0c09556e: /* original f7fe, guest PC 0x0c09556e */
if(!s->budget--) { s->failed_pc=0x0c09556eu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[15],fr[7],r[18]);
goto P_0c095570;
P_0c095570: /* original ff62, guest PC 0x0c095570 */
if(!s->budget--) { s->failed_pc=0x0c095570u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c095572;
P_0c095572: /* original f57c, guest PC 0x0c095572 */
if(!s->budget--) { s->failed_pc=0x0c095572u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c095574;
P_0c095574: /* original f35a, guest PC 0x0c095574 */
if(!s->budget--) { s->failed_pc=0x0c095574u; return 0; }
vf3_matrix_store(s,ram,5,r[3]);
goto P_0c095576;
P_0c095576: /* original f4f1, guest PC 0x0c095576 */
if(!s->budget--) { s->failed_pc=0x0c095576u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c095578;
P_0c095578: /* original 53f1, guest PC 0x0c095578 */
if(!s->budget--) { s->failed_pc=0x0c095578u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09557a;
P_0c09557a: /* original 7f10, guest PC 0x0c09557a */
if(!s->budget--) { s->failed_pc=0x0c09557au; return 0; }
r[15]+=0x00000010u;
goto P_0c09557c;
P_0c09557c: /* original 4f26, guest PC 0x0c09557c */
if(!s->budget--) { s->failed_pc=0x0c09557cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09557e;
P_0c09557e: /* original f34a, guest PC 0x0c09557e */
if(!s->budget--) { s->failed_pc=0x0c09557eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c095580;
P_0c095580: /* original 000b, guest PC 0x0c095580 */
if(!s->budget--) { s->failed_pc=0x0c095580u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c095582: /* original fff9, guest PC 0x0c095582 */
if(!s->budget--) { s->failed_pc=0x0c095582u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c095584u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095584u; return 0; } return 1;
P_0c0ad578: /* original 6360, guest PC 0x0c0ad578 */
if(!s->budget--) { s->failed_pc=0x0c0ad578u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0ad57a;
P_0c0ad57a: /* original 7ffc, guest PC 0x0c0ad57a */
if(!s->budget--) { s->failed_pc=0x0c0ad57au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad57c;
P_0c0ad57c: /* original d007, guest PC 0x0c0ad57c */
if(!s->budget--) { s->failed_pc=0x0c0ad57cu; return 0; }
r[0]=read(ram,0x0c0ad59cu,4);
goto P_0c0ad57e;
P_0c0ad57e: /* original 633c, guest PC 0x0c0ad57e */
if(!s->budget--) { s->failed_pc=0x0c0ad57eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad580;
P_0c0ad580: /* original 4308, guest PC 0x0c0ad580 */
if(!s->budget--) { s->failed_pc=0x0c0ad580u; return 0; }
r[3]<<=2;
goto P_0c0ad582;
P_0c0ad582: /* original 023e, guest PC 0x0c0ad582 */
if(!s->budget--) { s->failed_pc=0x0c0ad582u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0ad584;
P_0c0ad584: /* original 2f22, guest PC 0x0c0ad584 */
if(!s->budget--) { s->failed_pc=0x0c0ad584u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad586;
P_0c0ad586: /* original 422b, guest PC 0x0c0ad586 */
if(!s->budget--) { s->failed_pc=0x0c0ad586u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ad588: /* original 7f04, guest PC 0x0c0ad588 */
if(!s->budget--) { s->failed_pc=0x0c0ad588u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ad58au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad58au; return 0; } return 1;
P_0c0ade24: /* original 2fe6, guest PC 0x0c0ade24 */
if(!s->budget--) { s->failed_pc=0x0c0ade24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ade26;
P_0c0ade26: /* original 2fd6, guest PC 0x0c0ade26 */
if(!s->budget--) { s->failed_pc=0x0c0ade26u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ade28;
P_0c0ade28: /* original 8464, guest PC 0x0c0ade28 */
if(!s->budget--) { s->failed_pc=0x0c0ade28u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c0ade2a;
P_0c0ade2a: /* original d141, guest PC 0x0c0ade2a */
if(!s->budget--) { s->failed_pc=0x0c0ade2au; return 0; }
r[1]=read(ram,0x0c0adf30u,4);
goto P_0c0ade2c;
P_0c0ade2c: /* original 600c, guest PC 0x0c0ade2c */
if(!s->budget--) { s->failed_pc=0x0c0ade2cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade2e;
P_0c0ade2e: /* original d23f, guest PC 0x0c0ade2e */
if(!s->budget--) { s->failed_pc=0x0c0ade2eu; return 0; }
r[2]=read(ram,0x0c0adf2cu,4);
goto P_0c0ade30;
P_0c0ade30: /* original 4028, guest PC 0x0c0ade30 */
if(!s->budget--) { s->failed_pc=0x0c0ade30u; return 0; }
r[0]<<=16;
goto P_0c0ade32;
P_0c0ade32: /* original dd40, guest PC 0x0c0ade32 */
if(!s->budget--) { s->failed_pc=0x0c0ade32u; return 0; }
r[13]=read(ram,0x0c0adf34u,4);
goto P_0c0ade34;
P_0c0ade34: /* original 4018, guest PC 0x0c0ade34 */
if(!s->budget--) { s->failed_pc=0x0c0ade34u; return 0; }
r[0]<<=8;
goto P_0c0ade36;
P_0c0ade36: /* original 2019, guest PC 0x0c0ade36 */
if(!s->budget--) { s->failed_pc=0x0c0ade36u; return 0; }
r[0]&=r[1];
goto P_0c0ade38;
P_0c0ade38: /* original 6303, guest PC 0x0c0ade38 */
if(!s->budget--) { s->failed_pc=0x0c0ade38u; return 0; }
r[3]=r[0];
goto P_0c0ade3a;
P_0c0ade3a: /* original 8463, guest PC 0x0c0ade3a */
if(!s->budget--) { s->failed_pc=0x0c0ade3au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0ade3c;
P_0c0ade3c: /* original 4f22, guest PC 0x0c0ade3c */
if(!s->budget--) { s->failed_pc=0x0c0ade3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ade3e;
P_0c0ade3e: /* original 600c, guest PC 0x0c0ade3e */
if(!s->budget--) { s->failed_pc=0x0c0ade3eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade40;
P_0c0ade40: /* original 4028, guest PC 0x0c0ade40 */
if(!s->budget--) { s->failed_pc=0x0c0ade40u; return 0; }
r[0]<<=16;
goto P_0c0ade42;
P_0c0ade42: /* original 2029, guest PC 0x0c0ade42 */
if(!s->budget--) { s->failed_pc=0x0c0ade42u; return 0; }
r[0]&=r[2];
goto P_0c0ade44;
P_0c0ade44: /* original 230b, guest PC 0x0c0ade44 */
if(!s->budget--) { s->failed_pc=0x0c0ade44u; return 0; }
r[3]|=r[0];
goto P_0c0ade46;
P_0c0ade46: /* original 8462, guest PC 0x0c0ade46 */
if(!s->budget--) { s->failed_pc=0x0c0ade46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c0ade48;
P_0c0ade48: /* original 7ff0, guest PC 0x0c0ade48 */
if(!s->budget--) { s->failed_pc=0x0c0ade48u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0ade4a;
P_0c0ade4a: /* original 600c, guest PC 0x0c0ade4a */
if(!s->budget--) { s->failed_pc=0x0c0ade4au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade4c;
P_0c0ade4c: /* original 67f3, guest PC 0x0c0ade4c */
if(!s->budget--) { s->failed_pc=0x0c0ade4cu; return 0; }
r[7]=r[15];
goto P_0c0ade4e;
P_0c0ade4e: /* original 4018, guest PC 0x0c0ade4e */
if(!s->budget--) { s->failed_pc=0x0c0ade4eu; return 0; }
r[0]<<=8;
goto P_0c0ade50;
P_0c0ade50: /* original 6ef3, guest PC 0x0c0ade50 */
if(!s->budget--) { s->failed_pc=0x0c0ade50u; return 0; }
r[14]=r[15];
goto P_0c0ade52;
P_0c0ade52: /* original 20d9, guest PC 0x0c0ade52 */
if(!s->budget--) { s->failed_pc=0x0c0ade52u; return 0; }
r[0]&=r[13];
goto P_0c0ade54;
P_0c0ade54: /* original 230b, guest PC 0x0c0ade54 */
if(!s->budget--) { s->failed_pc=0x0c0ade54u; return 0; }
r[3]|=r[0];
goto P_0c0ade56;
P_0c0ade56: /* original 8461, guest PC 0x0c0ade56 */
if(!s->budget--) { s->failed_pc=0x0c0ade56u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c0ade58;
P_0c0ade58: /* original 7704, guest PC 0x0c0ade58 */
if(!s->budget--) { s->failed_pc=0x0c0ade58u; return 0; }
r[7]+=0x00000004u;
goto P_0c0ade5a;
P_0c0ade5a: /* original 600c, guest PC 0x0c0ade5a */
if(!s->budget--) { s->failed_pc=0x0c0ade5au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade5c;
P_0c0ade5c: /* original 230b, guest PC 0x0c0ade5c */
if(!s->budget--) { s->failed_pc=0x0c0ade5cu; return 0; }
r[3]|=r[0];
goto P_0c0ade5e;
P_0c0ade5e: /* original 2732, guest PC 0x0c0ade5e */
if(!s->budget--) { s->failed_pc=0x0c0ade5eu; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0ade60;
P_0c0ade60: /* original 7e04, guest PC 0x0c0ade60 */
if(!s->budget--) { s->failed_pc=0x0c0ade60u; return 0; }
r[14]+=0x00000004u;
goto P_0c0ade62;
P_0c0ade62: /* original 8469, guest PC 0x0c0ade62 */
if(!s->budget--) { s->failed_pc=0x0c0ade62u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0ade64;
P_0c0ade64: /* original 600c, guest PC 0x0c0ade64 */
if(!s->budget--) { s->failed_pc=0x0c0ade64u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade66;
P_0c0ade66: /* original 4028, guest PC 0x0c0ade66 */
if(!s->budget--) { s->failed_pc=0x0c0ade66u; return 0; }
r[0]<<=16;
goto P_0c0ade68;
P_0c0ade68: /* original 4018, guest PC 0x0c0ade68 */
if(!s->budget--) { s->failed_pc=0x0c0ade68u; return 0; }
r[0]<<=8;
goto P_0c0ade6a;
P_0c0ade6a: /* original 2019, guest PC 0x0c0ade6a */
if(!s->budget--) { s->failed_pc=0x0c0ade6au; return 0; }
r[0]&=r[1];
goto P_0c0ade6c;
P_0c0ade6c: /* original 6303, guest PC 0x0c0ade6c */
if(!s->budget--) { s->failed_pc=0x0c0ade6cu; return 0; }
r[3]=r[0];
goto P_0c0ade6e;
P_0c0ade6e: /* original 8468, guest PC 0x0c0ade6e */
if(!s->budget--) { s->failed_pc=0x0c0ade6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0ade70;
P_0c0ade70: /* original 600c, guest PC 0x0c0ade70 */
if(!s->budget--) { s->failed_pc=0x0c0ade70u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade72;
P_0c0ade72: /* original 4028, guest PC 0x0c0ade72 */
if(!s->budget--) { s->failed_pc=0x0c0ade72u; return 0; }
r[0]<<=16;
goto P_0c0ade74;
P_0c0ade74: /* original 2029, guest PC 0x0c0ade74 */
if(!s->budget--) { s->failed_pc=0x0c0ade74u; return 0; }
r[0]&=r[2];
goto P_0c0ade76;
P_0c0ade76: /* original 230b, guest PC 0x0c0ade76 */
if(!s->budget--) { s->failed_pc=0x0c0ade76u; return 0; }
r[3]|=r[0];
goto P_0c0ade78;
P_0c0ade78: /* original 8467, guest PC 0x0c0ade78 */
if(!s->budget--) { s->failed_pc=0x0c0ade78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+7,1);
goto P_0c0ade7a;
P_0c0ade7a: /* original 600c, guest PC 0x0c0ade7a */
if(!s->budget--) { s->failed_pc=0x0c0ade7au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade7c;
P_0c0ade7c: /* original 4018, guest PC 0x0c0ade7c */
if(!s->budget--) { s->failed_pc=0x0c0ade7cu; return 0; }
r[0]<<=8;
goto P_0c0ade7e;
P_0c0ade7e: /* original 20d9, guest PC 0x0c0ade7e */
if(!s->budget--) { s->failed_pc=0x0c0ade7eu; return 0; }
r[0]&=r[13];
goto P_0c0ade80;
P_0c0ade80: /* original 230b, guest PC 0x0c0ade80 */
if(!s->budget--) { s->failed_pc=0x0c0ade80u; return 0; }
r[3]|=r[0];
goto P_0c0ade82;
P_0c0ade82: /* original 8466, guest PC 0x0c0ade82 */
if(!s->budget--) { s->failed_pc=0x0c0ade82u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+6,1);
goto P_0c0ade84;
P_0c0ade84: /* original 600c, guest PC 0x0c0ade84 */
if(!s->budget--) { s->failed_pc=0x0c0ade84u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade86;
P_0c0ade86: /* original 230b, guest PC 0x0c0ade86 */
if(!s->budget--) { s->failed_pc=0x0c0ade86u; return 0; }
r[3]|=r[0];
goto P_0c0ade88;
P_0c0ade88: /* original 1731, guest PC 0x0c0ade88 */
if(!s->budget--) { s->failed_pc=0x0c0ade88u; return 0; }
write(ram,r[7]+4,r[3],4);
goto P_0c0ade8a;
P_0c0ade8a: /* original 846e, guest PC 0x0c0ade8a */
if(!s->budget--) { s->failed_pc=0x0c0ade8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+14,1);
goto P_0c0ade8c;
P_0c0ade8c: /* original 600c, guest PC 0x0c0ade8c */
if(!s->budget--) { s->failed_pc=0x0c0ade8cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade8e;
P_0c0ade8e: /* original 4028, guest PC 0x0c0ade8e */
if(!s->budget--) { s->failed_pc=0x0c0ade8eu; return 0; }
r[0]<<=16;
goto P_0c0ade90;
P_0c0ade90: /* original 4018, guest PC 0x0c0ade90 */
if(!s->budget--) { s->failed_pc=0x0c0ade90u; return 0; }
r[0]<<=8;
goto P_0c0ade92;
P_0c0ade92: /* original 2019, guest PC 0x0c0ade92 */
if(!s->budget--) { s->failed_pc=0x0c0ade92u; return 0; }
r[0]&=r[1];
goto P_0c0ade94;
P_0c0ade94: /* original 6303, guest PC 0x0c0ade94 */
if(!s->budget--) { s->failed_pc=0x0c0ade94u; return 0; }
r[3]=r[0];
goto P_0c0ade96;
P_0c0ade96: /* original 846d, guest PC 0x0c0ade96 */
if(!s->budget--) { s->failed_pc=0x0c0ade96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+13,1);
goto P_0c0ade98;
P_0c0ade98: /* original 600c, guest PC 0x0c0ade98 */
if(!s->budget--) { s->failed_pc=0x0c0ade98u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade9a;
P_0c0ade9a: /* original 4028, guest PC 0x0c0ade9a */
if(!s->budget--) { s->failed_pc=0x0c0ade9au; return 0; }
r[0]<<=16;
goto P_0c0ade9c;
P_0c0ade9c: /* original 2029, guest PC 0x0c0ade9c */
if(!s->budget--) { s->failed_pc=0x0c0ade9cu; return 0; }
r[0]&=r[2];
goto P_0c0ade9e;
P_0c0ade9e: /* original 230b, guest PC 0x0c0ade9e */
if(!s->budget--) { s->failed_pc=0x0c0ade9eu; return 0; }
r[3]|=r[0];
goto P_0c0adea0;
P_0c0adea0: /* original 846c, guest PC 0x0c0adea0 */
if(!s->budget--) { s->failed_pc=0x0c0adea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+12,1);
goto P_0c0adea2;
P_0c0adea2: /* original 600c, guest PC 0x0c0adea2 */
if(!s->budget--) { s->failed_pc=0x0c0adea2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adea4;
P_0c0adea4: /* original 4018, guest PC 0x0c0adea4 */
if(!s->budget--) { s->failed_pc=0x0c0adea4u; return 0; }
r[0]<<=8;
goto P_0c0adea6;
P_0c0adea6: /* original 20d9, guest PC 0x0c0adea6 */
if(!s->budget--) { s->failed_pc=0x0c0adea6u; return 0; }
r[0]&=r[13];
goto P_0c0adea8;
P_0c0adea8: /* original 230b, guest PC 0x0c0adea8 */
if(!s->budget--) { s->failed_pc=0x0c0adea8u; return 0; }
r[3]|=r[0];
goto P_0c0adeaa;
P_0c0adeaa: /* original 846b, guest PC 0x0c0adeaa */
if(!s->budget--) { s->failed_pc=0x0c0adeaau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0adeac;
P_0c0adeac: /* original 600c, guest PC 0x0c0adeac */
if(!s->budget--) { s->failed_pc=0x0c0adeacu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adeae;
P_0c0adeae: /* original 230b, guest PC 0x0c0adeae */
if(!s->budget--) { s->failed_pc=0x0c0adeaeu; return 0; }
r[3]|=r[0];
goto P_0c0adeb0;
P_0c0adeb0: /* original e004, guest PC 0x0c0adeb0 */
if(!s->budget--) { s->failed_pc=0x0c0adeb0u; return 0; }
r[0]=0x00000004u;
goto P_0c0adeb2;
P_0c0adeb2: /* original 1732, guest PC 0x0c0adeb2 */
if(!s->budget--) { s->failed_pc=0x0c0adeb2u; return 0; }
write(ram,r[7]+8,r[3],4);
goto P_0c0adeb4;
P_0c0adeb4: /* original f6e6, guest PC 0x0c0adeb4 */
if(!s->budget--) { s->failed_pc=0x0c0adeb4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0adeb6;
P_0c0adeb6: /* original e008, guest PC 0x0c0adeb6 */
if(!s->budget--) { s->failed_pc=0x0c0adeb6u; return 0; }
r[0]=0x00000008u;
goto P_0c0adeb8;
P_0c0adeb8: /* original f8e6, guest PC 0x0c0adeb8 */
if(!s->budget--) { s->failed_pc=0x0c0adeb8u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0adeba;
P_0c0adeba: /* original 8465, guest PC 0x0c0adeba */
if(!s->budget--) { s->failed_pc=0x0c0adebau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+5,1);
goto P_0c0adebc;
P_0c0adebc: /* original f7e8, guest PC 0x0c0adebc */
if(!s->budget--) { s->failed_pc=0x0c0adebcu; return 0; }
vf3_matrix_load(s,ram,7,r[14]);
goto P_0c0adebe;
P_0c0adebe: /* original 600c, guest PC 0x0c0adebe */
if(!s->budget--) { s->failed_pc=0x0c0adebeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adec0;
P_0c0adec0: /* original f675, guest PC 0x0c0adec0 */
if(!s->budget--) { s->failed_pc=0x0c0adec0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c0adec2;
P_0c0adec2: /* original 2f02, guest PC 0x0c0adec2 */
if(!s->budget--) { s->failed_pc=0x0c0adec2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0adec4;
P_0c0adec4: /* original 846a, guest PC 0x0c0adec4 */
if(!s->budget--) { s->failed_pc=0x0c0adec4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0adec6;
P_0c0adec6: /* original 6d0c, guest PC 0x0c0adec6 */
if(!s->budget--) { s->failed_pc=0x0c0adec6u; return 0; }
r[13]=r[0]&255u;
goto P_0c0adec8;
P_0c0adec8: /* original 8d01, guest PC 0x0c0adec8 */
if(!s->budget--) { s->failed_pc=0x0c0adec8u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c0adece; }
goto P_0c0adecc;
P_0c0adeca: /* original e701, guest PC 0x0c0adeca */
if(!s->budget--) { s->failed_pc=0x0c0adecau; return 0; }
r[7]=0x00000001u;
goto P_0c0adecc;
P_0c0adecc: /* original e702, guest PC 0x0c0adecc */
if(!s->budget--) { s->failed_pc=0x0c0adeccu; return 0; }
r[7]=0x00000002u;
goto P_0c0adece;
P_0c0adece: /* original 902b, guest PC 0x0c0adece */
if(!s->budget--) { s->failed_pc=0x0c0adeceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adf28u,2);
goto P_0c0aded0;
P_0c0aded0: /* original 2dd8, guest PC 0x0c0aded0 */
if(!s->budget--) { s->failed_pc=0x0c0aded0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0aded2;
P_0c0aded2: /* original 0474, guest PC 0x0c0aded2 */
if(!s->budget--) { s->failed_pc=0x0c0aded2u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0aded4;
P_0c0aded4: /* original e05c, guest PC 0x0c0aded4 */
if(!s->budget--) { s->failed_pc=0x0c0aded4u; return 0; }
r[0]=0x0000005cu;
goto P_0c0aded6;
P_0c0aded6: /* original f946, guest PC 0x0c0aded6 */
if(!s->budget--) { s->failed_pc=0x0c0aded6u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c0aded8;
P_0c0aded8: /* original f57c, guest PC 0x0c0aded8 */
if(!s->budget--) { s->failed_pc=0x0c0aded8u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0adeda;
P_0c0adeda: /* original f561, guest PC 0x0c0adeda */
if(!s->budget--) { s->failed_pc=0x0c0adedau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0adedc;
P_0c0adedc: /* original f49c, guest PC 0x0c0adedc */
if(!s->budget--) { s->failed_pc=0x0c0adedcu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c0adede;
P_0c0adede: /* original f461, guest PC 0x0c0adede */
if(!s->budget--) { s->failed_pc=0x0c0adedeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0adee0;
P_0c0adee0: /* original 9023, guest PC 0x0c0adee0 */
if(!s->budget--) { s->failed_pc=0x0c0adee0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adf2au,2);
goto P_0c0adee2;
P_0c0adee2: /* original 6ef2, guest PC 0x0c0adee2 */
if(!s->budget--) { s->failed_pc=0x0c0adee2u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c0adee4;
P_0c0adee4: /* original 074c, guest PC 0x0c0adee4 */
if(!s->budget--) { s->failed_pc=0x0c0adee4u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0adee6;
P_0c0adee6: /* original 8d0b, guest PC 0x0c0adee6 */
if(!s->budget--) { s->failed_pc=0x0c0adee6u; return 0; }
cond=r[17]&1u;
r[7]=r[7]&255u;
if(cond) { goto P_0c0adf00; }
goto P_0c0adeea;
P_0c0adee8: /* original 677c, guest PC 0x0c0adee8 */
if(!s->budget--) { s->failed_pc=0x0c0adee8u; return 0; }
r[7]=r[7]&255u;
goto P_0c0adeea;
P_0c0adeea: /* original f58c, guest PC 0x0c0adeea */
if(!s->budget--) { s->failed_pc=0x0c0adeeau; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0adeec;
P_0c0adeec: /* original f561, guest PC 0x0c0adeec */
if(!s->budget--) { s->failed_pc=0x0c0adeecu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0adeee;
P_0c0adeee: /* original f455, guest PC 0x0c0adeee */
if(!s->budget--) { s->failed_pc=0x0c0adeeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adef0;
P_0c0adef0: /* original 8905, guest PC 0x0c0adef0 */
if(!s->budget--) { s->failed_pc=0x0c0adef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adefe; }
goto P_0c0adef2;
P_0c0adef2: /* original f57c, guest PC 0x0c0adef2 */
if(!s->budget--) { s->failed_pc=0x0c0adef2u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0adef4;
P_0c0adef4: /* original f581, guest PC 0x0c0adef4 */
if(!s->budget--) { s->failed_pc=0x0c0adef4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c0adef6;
P_0c0adef6: /* original f49c, guest PC 0x0c0adef6 */
if(!s->budget--) { s->failed_pc=0x0c0adef6u; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c0adef8;
P_0c0adef8: /* original 6ed3, guest PC 0x0c0adef8 */
if(!s->budget--) { s->failed_pc=0x0c0adef8u; return 0; }
r[14]=r[13];
goto P_0c0adefa;
P_0c0adefa: /* original a001, guest PC 0x0c0adefa */
if(!s->budget--) { s->failed_pc=0x0c0adefau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c0adf00;
P_0c0adefc: /* original f481, guest PC 0x0c0adefc */
if(!s->budget--) { s->failed_pc=0x0c0adefcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c0adefe;
P_0c0adefe: /* original 67d3, guest PC 0x0c0adefe */
if(!s->budget--) { s->failed_pc=0x0c0adefeu; return 0; }
r[7]=r[13];
goto P_0c0adf00;
P_0c0adf00: /* original f38d, guest PC 0x0c0adf00 */
if(!s->budget--) { s->failed_pc=0x0c0adf00u; return 0; }
fr[3]=0;
goto P_0c0adf02;
P_0c0adf02: /* original f355, guest PC 0x0c0adf02 */
if(!s->budget--) { s->failed_pc=0x0c0adf02u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0adf04;
P_0c0adf04: /* original 8d07, guest PC 0x0c0adf04 */
if(!s->budget--) { s->failed_pc=0x0c0adf04u; return 0; }
cond=r[17]&1u;
fr[6]=0;
if(cond) { goto P_0c0adf16; }
goto P_0c0adf08;
P_0c0adf06: /* original f68d, guest PC 0x0c0adf06 */
if(!s->budget--) { s->failed_pc=0x0c0adf06u; return 0; }
fr[6]=0;
goto P_0c0adf08;
P_0c0adf08: /* original f38d, guest PC 0x0c0adf08 */
if(!s->budget--) { s->failed_pc=0x0c0adf08u; return 0; }
fr[3]=0;
goto P_0c0adf0a;
P_0c0adf0a: /* original f345, guest PC 0x0c0adf0a */
if(!s->budget--) { s->failed_pc=0x0c0adf0au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0adf0c;
P_0c0adf0c: /* original 8917, guest PC 0x0c0adf0c */
if(!s->budget--) { s->failed_pc=0x0c0adf0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf3e; }
goto P_0c0adf0e;
P_0c0adf0e: /* original f455, guest PC 0x0c0adf0e */
if(!s->budget--) { s->failed_pc=0x0c0adf0eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adf10;
P_0c0adf10: /* original 8b16, guest PC 0x0c0adf10 */
if(!s->budget--) { s->failed_pc=0x0c0adf10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0adf40; }
goto P_0c0adf12;
P_0c0adf12: /* original a002, guest PC 0x0c0adf12 */
if(!s->budget--) { s->failed_pc=0x0c0adf12u; return 0; }
goto P_0c0adf1a;
P_0c0adf14: /* original 0009, guest PC 0x0c0adf14 */
if(!s->budget--) { s->failed_pc=0x0c0adf14u; return 0; }
goto P_0c0adf16;
P_0c0adf16: /* original f455, guest PC 0x0c0adf16 */
if(!s->budget--) { s->failed_pc=0x0c0adf16u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adf18;
P_0c0adf18: /* original 890e, guest PC 0x0c0adf18 */
if(!s->budget--) { s->failed_pc=0x0c0adf18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf38; }
goto P_0c0adf1a;
P_0c0adf1a: /* original a011, guest PC 0x0c0adf1a */
if(!s->budget--) { s->failed_pc=0x0c0adf1au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0adf40;
P_0c0adf1c: /* original f45c, guest PC 0x0c0adf1c */
if(!s->budget--) { s->failed_pc=0x0c0adf1cu; return 0; }
vf3_matrix_move(s,4,5);
if(!vf3_matrix_family(0x0c0adf1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0adf1eu; return 0; } return 1;
P_0c0adf38: /* original f38d, guest PC 0x0c0adf38 */
if(!s->budget--) { s->failed_pc=0x0c0adf38u; return 0; }
fr[3]=0;
goto P_0c0adf3a;
P_0c0adf3a: /* original f345, guest PC 0x0c0adf3a */
if(!s->budget--) { s->failed_pc=0x0c0adf3au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0adf3c;
P_0c0adf3c: /* original 8900, guest PC 0x0c0adf3c */
if(!s->budget--) { s->failed_pc=0x0c0adf3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf40; }
goto P_0c0adf3e;
P_0c0adf3e: /* original f46c, guest PC 0x0c0adf3e */
if(!s->budget--) { s->failed_pc=0x0c0adf3eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0adf40;
P_0c0adf40: /* original f453, guest PC 0x0c0adf40 */
if(!s->budget--) { s->failed_pc=0x0c0adf40u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c0adf42;
P_0c0adf42: /* original 37e8, guest PC 0x0c0adf42 */
if(!s->budget--) { s->failed_pc=0x0c0adf42u; return 0; }
r[7]-=r[14];
goto P_0c0adf44;
P_0c0adf44: /* original 475a, guest PC 0x0c0adf44 */
if(!s->budget--) { s->failed_pc=0x0c0adf44u; return 0; }
r[53]=r[7];
goto P_0c0adf46;
P_0c0adf46: /* original 9093, guest PC 0x0c0adf46 */
if(!s->budget--) { s->failed_pc=0x0c0adf46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae070u,2);
goto P_0c0adf48;
P_0c0adf48: /* original f32d, guest PC 0x0c0adf48 */
if(!s->budget--) { s->failed_pc=0x0c0adf48u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0adf4a;
P_0c0adf4a: /* original f63c, guest PC 0x0c0adf4a */
if(!s->budget--) { s->failed_pc=0x0c0adf4au; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0adf4c;
P_0c0adf4c: /* original f462, guest PC 0x0c0adf4c */
if(!s->budget--) { s->failed_pc=0x0c0adf4cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0adf4e;
P_0c0adf4e: /* original f43d, guest PC 0x0c0adf4e */
if(!s->budget--) { s->failed_pc=0x0c0adf4eu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0adf50;
P_0c0adf50: /* original 075a, guest PC 0x0c0adf50 */
if(!s->budget--) { s->failed_pc=0x0c0adf50u; return 0; }
r[7]=r[53];
goto P_0c0adf52;
P_0c0adf52: /* original 3e7c, guest PC 0x0c0adf52 */
if(!s->budget--) { s->failed_pc=0x0c0adf52u; return 0; }
r[14]+=r[7];
goto P_0c0adf54;
P_0c0adf54: /* original 04e4, guest PC 0x0c0adf54 */
if(!s->budget--) { s->failed_pc=0x0c0adf54u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0adf56;
P_0c0adf56: /* original bb0f, guest PC 0x0c0adf56 */
if(!s->budget--) { s->failed_pc=0x0c0adf56u; return 0; }
target=code_base|0x0c0ad578u; r[16]=code_base|0x0c0adf5au;
r[6]+=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0adf5au) { target=s->pc; goto dispatch; }
goto P_0c0adf5a;
P_0c0adf58: /* original 760f, guest PC 0x0c0adf58 */
if(!s->budget--) { s->failed_pc=0x0c0adf58u; return 0; }
r[6]+=0x0000000fu;
goto P_0c0adf5a;
P_0c0adf5a: /* original 7f10, guest PC 0x0c0adf5a */
if(!s->budget--) { s->failed_pc=0x0c0adf5au; return 0; }
r[15]+=0x00000010u;
goto P_0c0adf5c;
P_0c0adf5c: /* original 4f26, guest PC 0x0c0adf5c */
if(!s->budget--) { s->failed_pc=0x0c0adf5cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0adf5e;
P_0c0adf5e: /* original 6df6, guest PC 0x0c0adf5e */
if(!s->budget--) { s->failed_pc=0x0c0adf5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0adf60;
P_0c0adf60: /* original 000b, guest PC 0x0c0adf60 */
if(!s->budget--) { s->failed_pc=0x0c0adf60u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0adf62: /* original 6ef6, guest PC 0x0c0adf62 */
if(!s->budget--) { s->failed_pc=0x0c0adf62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0adf64u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0adf64u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
