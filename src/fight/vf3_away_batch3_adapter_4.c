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
int vf3_away_batch3_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c03f510u: goto P_0c03f510;
case 0x0c03f512u: goto P_0c03f512;
case 0x0c03f514u: goto P_0c03f514;
case 0x0c03f516u: goto P_0c03f516;
case 0x0c03f518u: goto P_0c03f518;
case 0x0c03f51au: goto P_0c03f51a;
case 0x0c03f51cu: goto P_0c03f51c;
case 0x0c03f51eu: goto P_0c03f51e;
case 0x0c03f520u: goto P_0c03f520;
case 0x0c03f522u: goto P_0c03f522;
case 0x0c03f524u: goto P_0c03f524;
case 0x0c03f526u: goto P_0c03f526;
case 0x0c03f528u: goto P_0c03f528;
case 0x0c03f52au: goto P_0c03f52a;
case 0x0c03f52cu: goto P_0c03f52c;
case 0x0c03f52eu: goto P_0c03f52e;
case 0x0c03f530u: goto P_0c03f530;
case 0x0c03f532u: goto P_0c03f532;
case 0x0c03f534u: goto P_0c03f534;
case 0x0c03f536u: goto P_0c03f536;
case 0x0c03f538u: goto P_0c03f538;
case 0x0c03f53au: goto P_0c03f53a;
case 0x0c03f53cu: goto P_0c03f53c;
case 0x0c03f53eu: goto P_0c03f53e;
case 0x0c03f540u: goto P_0c03f540;
case 0x0c03f542u: goto P_0c03f542;
case 0x0c03f544u: goto P_0c03f544;
case 0x0c03f546u: goto P_0c03f546;
case 0x0c03f548u: goto P_0c03f548;
case 0x0c03f54au: goto P_0c03f54a;
case 0x0c03f54cu: goto P_0c03f54c;
case 0x0c03f54eu: goto P_0c03f54e;
case 0x0c03f550u: goto P_0c03f550;
case 0x0c03f552u: goto P_0c03f552;
case 0x0c03f554u: goto P_0c03f554;
case 0x0c03f556u: goto P_0c03f556;
case 0x0c03f558u: goto P_0c03f558;
case 0x0c03f55au: goto P_0c03f55a;
case 0x0c03f55cu: goto P_0c03f55c;
case 0x0c03f55eu: goto P_0c03f55e;
case 0x0c03f560u: goto P_0c03f560;
case 0x0c03f562u: goto P_0c03f562;
case 0x0c03f564u: goto P_0c03f564;
case 0x0c03f566u: goto P_0c03f566;
case 0x0c03f568u: goto P_0c03f568;
case 0x0c03f56au: goto P_0c03f56a;
case 0x0c03f570u: goto P_0c03f570;
case 0x0c03f572u: goto P_0c03f572;
case 0x0c03f574u: goto P_0c03f574;
case 0x0c03f576u: goto P_0c03f576;
case 0x0c03f578u: goto P_0c03f578;
case 0x0c03f57au: goto P_0c03f57a;
case 0x0c03f57cu: goto P_0c03f57c;
case 0x0c03f57eu: goto P_0c03f57e;
case 0x0c03f580u: goto P_0c03f580;
case 0x0c03f582u: goto P_0c03f582;
case 0x0c03f584u: goto P_0c03f584;
case 0x0c03f586u: goto P_0c03f586;
case 0x0c03f588u: goto P_0c03f588;
case 0x0c03f58au: goto P_0c03f58a;
case 0x0c03f58cu: goto P_0c03f58c;
case 0x0c03f58eu: goto P_0c03f58e;
case 0x0c03f590u: goto P_0c03f590;
case 0x0c03f592u: goto P_0c03f592;
case 0x0c03f594u: goto P_0c03f594;
case 0x0c03f596u: goto P_0c03f596;
case 0x0c03f598u: goto P_0c03f598;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c03f510: /* original 2fe6, guest PC 0x0c03f510 */
if(!s->budget--) { s->failed_pc=0x0c03f510u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f512;
P_0c03f512: /* original 6353, guest PC 0x0c03f512 */
if(!s->budget--) { s->failed_pc=0x0c03f512u; return 0; }
r[3]=r[5];
goto P_0c03f514;
P_0c03f514: /* original 2fd6, guest PC 0x0c03f514 */
if(!s->budget--) { s->failed_pc=0x0c03f514u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f516;
P_0c03f516: /* original 4300, guest PC 0x0c03f516 */
if(!s->budget--) { s->failed_pc=0x0c03f516u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c03f518;
P_0c03f518: /* original 2fc6, guest PC 0x0c03f518 */
if(!s->budget--) { s->failed_pc=0x0c03f518u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f51a;
P_0c03f51a: /* original 334c, guest PC 0x0c03f51a */
if(!s->budget--) { s->failed_pc=0x0c03f51au; return 0; }
r[3]+=r[4];
goto P_0c03f51c;
P_0c03f51c: /* original 2fb6, guest PC 0x0c03f51c */
if(!s->budget--) { s->failed_pc=0x0c03f51cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f51e;
P_0c03f51e: /* original 7303, guest PC 0x0c03f51e */
if(!s->budget--) { s->failed_pc=0x0c03f51eu; return 0; }
r[3]+=0x00000003u;
goto P_0c03f520;
P_0c03f520: /* original db9a, guest PC 0x0c03f520 */
if(!s->budget--) { s->failed_pc=0x0c03f520u; return 0; }
r[11]=read(ram,0x0c03f78cu,4);
goto P_0c03f522;
P_0c03f522: /* original 6163, guest PC 0x0c03f522 */
if(!s->budget--) { s->failed_pc=0x0c03f522u; return 0; }
r[1]=r[6];
goto P_0c03f524;
P_0c03f524: /* original 4f22, guest PC 0x0c03f524 */
if(!s->budget--) { s->failed_pc=0x0c03f524u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f526;
P_0c03f526: /* original 711f, guest PC 0x0c03f526 */
if(!s->budget--) { s->failed_pc=0x0c03f526u; return 0; }
r[1]+=0x0000001fu;
goto P_0c03f528;
P_0c03f528: /* original 2b62, guest PC 0x0c03f528 */
if(!s->budget--) { s->failed_pc=0x0c03f528u; return 0; }
write(ram,r[11],r[6],4);
goto P_0c03f52a;
P_0c03f52a: /* original d799, guest PC 0x0c03f52a */
if(!s->budget--) { s->failed_pc=0x0c03f52au; return 0; }
r[7]=read(ram,0x0c03f790u,4);
goto P_0c03f52c;
P_0c03f52c: /* original ee20, guest PC 0x0c03f52c */
if(!s->budget--) { s->failed_pc=0x0c03f52cu; return 0; }
r[14]=0x00000020u;
goto P_0c03f52e;
P_0c03f52e: /* original 2742, guest PC 0x0c03f52e */
if(!s->budget--) { s->failed_pc=0x0c03f52eu; return 0; }
write(ram,r[7],r[4],4);
goto P_0c03f530;
P_0c03f530: /* original e4fc, guest PC 0x0c03f530 */
if(!s->budget--) { s->failed_pc=0x0c03f530u; return 0; }
r[4]=0xfffffffcu;
goto P_0c03f532;
P_0c03f532: /* original dc98, guest PC 0x0c03f532 */
if(!s->budget--) { s->failed_pc=0x0c03f532u; return 0; }
r[12]=read(ram,0x0c03f794u,4);
goto P_0c03f534;
P_0c03f534: /* original 2439, guest PC 0x0c03f534 */
if(!s->budget--) { s->failed_pc=0x0c03f534u; return 0; }
r[4]&=r[3];
goto P_0c03f536;
P_0c03f536: /* original 2c42, guest PC 0x0c03f536 */
if(!s->budget--) { s->failed_pc=0x0c03f536u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c03f538;
P_0c03f538: /* original 60e3, guest PC 0x0c03f538 */
if(!s->budget--) { s->failed_pc=0x0c03f538u; return 0; }
r[0]=r[14];
goto P_0c03f53a;
P_0c03f53a: /* original 0009, guest PC 0x0c03f53a */
if(!s->budget--) { s->failed_pc=0x0c03f53au; return 0; }
goto P_0c03f53c;
P_0c03f53c: /* original d396, guest PC 0x0c03f53c */
if(!s->budget--) { s->failed_pc=0x0c03f53cu; return 0; }
r[3]=read(ram,0x0c03f798u,4);
goto P_0c03f53e;
P_0c03f53e: /* original 430b, guest PC 0x0c03f53e */
if(!s->budget--) { s->failed_pc=0x0c03f53eu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f542u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f542u) { target=s->pc; goto dispatch; }
goto P_0c03f542;
P_0c03f540: /* original 0009, guest PC 0x0c03f540 */
if(!s->budget--) { s->failed_pc=0x0c03f540u; return 0; }
goto P_0c03f542;
P_0c03f542: /* original 4008, guest PC 0x0c03f542 */
if(!s->budget--) { s->failed_pc=0x0c03f542u; return 0; }
r[0]<<=2;
goto P_0c03f544;
P_0c03f544: /* original d295, guest PC 0x0c03f544 */
if(!s->budget--) { s->failed_pc=0x0c03f544u; return 0; }
r[2]=read(ram,0x0c03f79cu,4);
goto P_0c03f546;
P_0c03f546: /* original 304c, guest PC 0x0c03f546 */
if(!s->budget--) { s->failed_pc=0x0c03f546u; return 0; }
r[0]+=r[4];
goto P_0c03f548;
P_0c03f548: /* original 4515, guest PC 0x0c03f548 */
if(!s->budget--) { s->failed_pc=0x0c03f548u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c03f54a;
P_0c03f54a: /* original e4fc, guest PC 0x0c03f54a */
if(!s->budget--) { s->failed_pc=0x0c03f54au; return 0; }
r[4]=0xfffffffcu;
goto P_0c03f54c;
P_0c03f54c: /* original 7003, guest PC 0x0c03f54c */
if(!s->budget--) { s->failed_pc=0x0c03f54cu; return 0; }
r[0]+=0x00000003u;
goto P_0c03f54e;
P_0c03f54e: /* original 2409, guest PC 0x0c03f54e */
if(!s->budget--) { s->failed_pc=0x0c03f54eu; return 0; }
r[4]&=r[0];
goto P_0c03f550;
P_0c03f550: /* original e600, guest PC 0x0c03f550 */
if(!s->budget--) { s->failed_pc=0x0c03f550u; return 0; }
r[6]=0x00000000u;
goto P_0c03f552;
P_0c03f552: /* original 2242, guest PC 0x0c03f552 */
if(!s->budget--) { s->failed_pc=0x0c03f552u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c03f554;
P_0c03f554: /* original 6463, guest PC 0x0c03f554 */
if(!s->budget--) { s->failed_pc=0x0c03f554u; return 0; }
r[4]=r[6];
goto P_0c03f556;
P_0c03f556: /* original 6d63, guest PC 0x0c03f556 */
if(!s->budget--) { s->failed_pc=0x0c03f556u; return 0; }
r[13]=r[6];
goto P_0c03f558;
P_0c03f558: /* original 8f06, guest PC 0x0c03f558 */
if(!s->budget--) { s->failed_pc=0x0c03f558u; return 0; }
cond=r[17]&1u;
r[1]=0xffffffffu;
if(!cond) { goto P_0c03f568; }
goto P_0c03f55c;
P_0c03f55a: /* original e1ff, guest PC 0x0c03f55a */
if(!s->budget--) { s->failed_pc=0x0c03f55au; return 0; }
r[1]=0xffffffffu;
goto P_0c03f55c;
P_0c03f55c: /* original 6072, guest PC 0x0c03f55c */
if(!s->budget--) { s->failed_pc=0x0c03f55cu; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03f55e;
P_0c03f55e: /* original 7d01, guest PC 0x0c03f55e */
if(!s->budget--) { s->failed_pc=0x0c03f55eu; return 0; }
r[13]+=0x00000001u;
goto P_0c03f560;
P_0c03f560: /* original 3d53, guest PC 0x0c03f560 */
if(!s->budget--) { s->failed_pc=0x0c03f560u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[5])!=0);
goto P_0c03f562;
P_0c03f562: /* original 0415, guest PC 0x0c03f562 */
if(!s->budget--) { s->failed_pc=0x0c03f562u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c03f564;
P_0c03f564: /* original 8ffa, guest PC 0x0c03f564 */
if(!s->budget--) { s->failed_pc=0x0c03f564u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000002u;
if(!cond) { goto P_0c03f55c; }
goto P_0c03f568;
P_0c03f566: /* original 7402, guest PC 0x0c03f566 */
if(!s->budget--) { s->failed_pc=0x0c03f566u; return 0; }
r[4]+=0x00000002u;
goto P_0c03f568;
P_0c03f568: /* original a008, guest PC 0x0c03f568 */
if(!s->budget--) { s->failed_pc=0x0c03f568u; return 0; }
r[4]=r[6];
goto P_0c03f57c;
P_0c03f56a: /* original 6463, guest PC 0x0c03f56a */
if(!s->budget--) { s->failed_pc=0x0c03f56au; return 0; }
r[4]=r[6];
if(!vf3_matrix_family(0x0c03f56cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f56cu; return 0; } return 1;
P_0c03f570: /* original 6043, guest PC 0x0c03f570 */
if(!s->budget--) { s->failed_pc=0x0c03f570u; return 0; }
r[0]=r[4];
goto P_0c03f572;
P_0c03f572: /* original 0009, guest PC 0x0c03f572 */
if(!s->budget--) { s->failed_pc=0x0c03f572u; return 0; }
goto P_0c03f574;
P_0c03f574: /* original 63c2, guest PC 0x0c03f574 */
if(!s->budget--) { s->failed_pc=0x0c03f574u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f576;
P_0c03f576: /* original 4008, guest PC 0x0c03f576 */
if(!s->budget--) { s->failed_pc=0x0c03f576u; return 0; }
r[0]<<=2;
goto P_0c03f578;
P_0c03f578: /* original 7401, guest PC 0x0c03f578 */
if(!s->budget--) { s->failed_pc=0x0c03f578u; return 0; }
r[4]+=0x00000001u;
goto P_0c03f57a;
P_0c03f57a: /* original 0366, guest PC 0x0c03f57a */
if(!s->budget--) { s->failed_pc=0x0c03f57au; return 0; }
write(ram,r[3]+r[0],r[6],4);
goto P_0c03f57c;
P_0c03f57c: /* original 61b2, guest PC 0x0c03f57c */
if(!s->budget--) { s->failed_pc=0x0c03f57cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c03f57e;
P_0c03f57e: /* original 711f, guest PC 0x0c03f57e */
if(!s->budget--) { s->failed_pc=0x0c03f57eu; return 0; }
r[1]+=0x0000001fu;
goto P_0c03f580;
P_0c03f580: /* original 60e3, guest PC 0x0c03f580 */
if(!s->budget--) { s->failed_pc=0x0c03f580u; return 0; }
r[0]=r[14];
goto P_0c03f582;
P_0c03f582: /* original 0009, guest PC 0x0c03f582 */
if(!s->budget--) { s->failed_pc=0x0c03f582u; return 0; }
goto P_0c03f584;
P_0c03f584: /* original d384, guest PC 0x0c03f584 */
if(!s->budget--) { s->failed_pc=0x0c03f584u; return 0; }
r[3]=read(ram,0x0c03f798u,4);
goto P_0c03f586;
P_0c03f586: /* original 430b, guest PC 0x0c03f586 */
if(!s->budget--) { s->failed_pc=0x0c03f586u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f58au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f58au) { target=s->pc; goto dispatch; }
goto P_0c03f58a;
P_0c03f588: /* original 0009, guest PC 0x0c03f588 */
if(!s->budget--) { s->failed_pc=0x0c03f588u; return 0; }
goto P_0c03f58a;
P_0c03f58a: /* original 3403, guest PC 0x0c03f58a */
if(!s->budget--) { s->failed_pc=0x0c03f58au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c03f58c;
P_0c03f58c: /* original 8bf0, guest PC 0x0c03f58c */
if(!s->budget--) { s->failed_pc=0x0c03f58cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f570; }
goto P_0c03f58e;
P_0c03f58e: /* original 4f26, guest PC 0x0c03f58e */
if(!s->budget--) { s->failed_pc=0x0c03f58eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f590;
P_0c03f590: /* original 6bf6, guest PC 0x0c03f590 */
if(!s->budget--) { s->failed_pc=0x0c03f590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f592;
P_0c03f592: /* original 6cf6, guest PC 0x0c03f592 */
if(!s->budget--) { s->failed_pc=0x0c03f592u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f594;
P_0c03f594: /* original 6df6, guest PC 0x0c03f594 */
if(!s->budget--) { s->failed_pc=0x0c03f594u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f596;
P_0c03f596: /* original 000b, guest PC 0x0c03f596 */
if(!s->budget--) { s->failed_pc=0x0c03f596u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f598: /* original 6ef6, guest PC 0x0c03f598 */
if(!s->budget--) { s->failed_pc=0x0c03f598u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f59au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f59au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
