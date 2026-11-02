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
int vf3_away_batch199_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c03c5b0u: goto P_0c03c5b0;
case 0x0c03c5b2u: goto P_0c03c5b2;
case 0x0c03c5b4u: goto P_0c03c5b4;
case 0x0c03c5b6u: goto P_0c03c5b6;
case 0x0c03c5b8u: goto P_0c03c5b8;
case 0x0c03c5bau: goto P_0c03c5ba;
case 0x0c03c5bcu: goto P_0c03c5bc;
case 0x0c03c5beu: goto P_0c03c5be;
case 0x0c03c5c0u: goto P_0c03c5c0;
case 0x0c03c5c2u: goto P_0c03c5c2;
case 0x0c03c5c4u: goto P_0c03c5c4;
case 0x0c03c5c6u: goto P_0c03c5c6;
case 0x0c03c5c8u: goto P_0c03c5c8;
case 0x0c03c5cau: goto P_0c03c5ca;
case 0x0c03c5ccu: goto P_0c03c5cc;
case 0x0c03c5ceu: goto P_0c03c5ce;
case 0x0c03c5d0u: goto P_0c03c5d0;
case 0x0c03c5d2u: goto P_0c03c5d2;
case 0x0c03c5d4u: goto P_0c03c5d4;
case 0x0c03c5d6u: goto P_0c03c5d6;
case 0x0c03c5d8u: goto P_0c03c5d8;
case 0x0c03c5dau: goto P_0c03c5da;
case 0x0c03c5dcu: goto P_0c03c5dc;
case 0x0c03c5deu: goto P_0c03c5de;
case 0x0c03c5e0u: goto P_0c03c5e0;
case 0x0c03c5e2u: goto P_0c03c5e2;
case 0x0c03c5e4u: goto P_0c03c5e4;
case 0x0c03c5e6u: goto P_0c03c5e6;
case 0x0c03c5e8u: goto P_0c03c5e8;
case 0x0c03c5eau: goto P_0c03c5ea;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c091afeu: goto P_0c091afe;
case 0x0c091b00u: goto P_0c091b00;
case 0x0c091b02u: goto P_0c091b02;
case 0x0c091b04u: goto P_0c091b04;
case 0x0c091b06u: goto P_0c091b06;
case 0x0c091b08u: goto P_0c091b08;
case 0x0c091b0au: goto P_0c091b0a;
case 0x0c091b0cu: goto P_0c091b0c;
case 0x0c091b0eu: goto P_0c091b0e;
case 0x0c091b10u: goto P_0c091b10;
case 0x0c091b12u: goto P_0c091b12;
case 0x0c091b14u: goto P_0c091b14;
case 0x0c091b16u: goto P_0c091b16;
case 0x0c091b18u: goto P_0c091b18;
case 0x0c091b1au: goto P_0c091b1a;
case 0x0c091b1cu: goto P_0c091b1c;
case 0x0c091b1eu: goto P_0c091b1e;
case 0x0c091b20u: goto P_0c091b20;
case 0x0c091b22u: goto P_0c091b22;
case 0x0c091b24u: goto P_0c091b24;
case 0x0c091b26u: goto P_0c091b26;
case 0x0c091b28u: goto P_0c091b28;
case 0x0c091b2au: goto P_0c091b2a;
case 0x0c091b2cu: goto P_0c091b2c;
case 0x0c091b2eu: goto P_0c091b2e;
case 0x0c091b30u: goto P_0c091b30;
case 0x0c091b32u: goto P_0c091b32;
case 0x0c091b34u: goto P_0c091b34;
case 0x0c091b36u: goto P_0c091b36;
case 0x0c091b38u: goto P_0c091b38;
case 0x0c091b3au: goto P_0c091b3a;
case 0x0c091b3cu: goto P_0c091b3c;
case 0x0c091b3eu: goto P_0c091b3e;
case 0x0c091b40u: goto P_0c091b40;
case 0x0c091b42u: goto P_0c091b42;
case 0x0c091b44u: goto P_0c091b44;
case 0x0c09d408u: goto P_0c09d408;
case 0x0c09d40au: goto P_0c09d40a;
case 0x0c09d40cu: goto P_0c09d40c;
case 0x0c09d40eu: goto P_0c09d40e;
case 0x0c09d410u: goto P_0c09d410;
case 0x0c09d412u: goto P_0c09d412;
case 0x0c09d414u: goto P_0c09d414;
case 0x0c09d416u: goto P_0c09d416;
case 0x0c09d418u: goto P_0c09d418;
case 0x0c09d41au: goto P_0c09d41a;
case 0x0c09d41cu: goto P_0c09d41c;
case 0x0c09d41eu: goto P_0c09d41e;
case 0x0c09d420u: goto P_0c09d420;
case 0x0c09d422u: goto P_0c09d422;
case 0x0c09d424u: goto P_0c09d424;
case 0x0c09d426u: goto P_0c09d426;
case 0x0c09d428u: goto P_0c09d428;
case 0x0c09d42au: goto P_0c09d42a;
case 0x0c09d42cu: goto P_0c09d42c;
case 0x0c09d42eu: goto P_0c09d42e;
case 0x0c09d430u: goto P_0c09d430;
case 0x0c09d432u: goto P_0c09d432;
case 0x0c09d434u: goto P_0c09d434;
case 0x0c09d436u: goto P_0c09d436;
case 0x0c09d438u: goto P_0c09d438;
case 0x0c09d43au: goto P_0c09d43a;
case 0x0c09d43cu: goto P_0c09d43c;
case 0x0c09d43eu: goto P_0c09d43e;
case 0x0c09d440u: goto P_0c09d440;
case 0x0c09d442u: goto P_0c09d442;
case 0x0c09d444u: goto P_0c09d444;
case 0x0c09d446u: goto P_0c09d446;
case 0x0c09d448u: goto P_0c09d448;
case 0x0c09d44au: goto P_0c09d44a;
case 0x0c09d44cu: goto P_0c09d44c;
case 0x0c09d44eu: goto P_0c09d44e;
case 0x0c09d450u: goto P_0c09d450;
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
P_0c03c5b0: /* original fbfd, guest PC 0x0c03c5b0 */
if(!s->budget--) { s->failed_pc=0x0c03c5b0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5b2;
P_0c03c5b2: /* original f38d, guest PC 0x0c03c5b2 */
if(!s->budget--) { s->failed_pc=0x0c03c5b2u; return 0; }
fr[3]=0;
goto P_0c03c5b4;
P_0c03c5b4: /* original fbb1, guest PC 0x0c03c5b4 */
if(!s->budget--) { s->failed_pc=0x0c03c5b4u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5b6;
P_0c03c5b6: /* original f78d, guest PC 0x0c03c5b6 */
if(!s->budget--) { s->failed_pc=0x0c03c5b6u; return 0; }
fr[7]=0;
goto P_0c03c5b8;
P_0c03c5b8: /* original ff9d, guest PC 0x0c03c5b8 */
if(!s->budget--) { s->failed_pc=0x0c03c5b8u; return 0; }
fr[15]=0x3f800000u;
goto P_0c03c5ba;
P_0c03c5ba: /* original f11d, guest PC 0x0c03c5ba */
if(!s->budget--) { s->failed_pc=0x0c03c5bau; return 0; }
r[53]=fr[1];
goto P_0c03c5bc;
P_0c03c5bc: /* original f3ed, guest PC 0x0c03c5bc */
if(!s->budget--) { s->failed_pc=0x0c03c5bcu; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03c5be;
P_0c03c5be: /* original f14c, guest PC 0x0c03c5be */
if(!s->budget--) { s->failed_pc=0x0c03c5beu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03c5c0;
P_0c03c5c0: /* original f7ed, guest PC 0x0c03c5c0 */
if(!s->budget--) { s->failed_pc=0x0c03c5c0u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03c5c2;
P_0c03c5c2: /* original f40d, guest PC 0x0c03c5c2 */
if(!s->budget--) { s->failed_pc=0x0c03c5c2u; return 0; }
fr[4]=r[53];
goto P_0c03c5c4;
P_0c03c5c4: /* original fbed, guest PC 0x0c03c5c4 */
if(!s->budget--) { s->failed_pc=0x0c03c5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03c5c6;
P_0c03c5c6: /* original fc8d, guest PC 0x0c03c5c6 */
if(!s->budget--) { s->failed_pc=0x0c03c5c6u; return 0; }
fr[12]=0;
goto P_0c03c5c8;
P_0c03c5c8: /* original fee1, guest PC 0x0c03c5c8 */
if(!s->budget--) { s->failed_pc=0x0c03c5c8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[14],r[18],'-');
goto P_0c03c5ca;
P_0c03c5ca: /* original fc31, guest PC 0x0c03c5ca */
if(!s->budget--) { s->failed_pc=0x0c03c5cau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'-');
goto P_0c03c5cc;
P_0c03c5cc: /* original fd8d, guest PC 0x0c03c5cc */
if(!s->budget--) { s->failed_pc=0x0c03c5ccu; return 0; }
fr[13]=0;
goto P_0c03c5ce;
P_0c03c5ce: /* original fd71, guest PC 0x0c03c5ce */
if(!s->budget--) { s->failed_pc=0x0c03c5ceu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'-');
goto P_0c03c5d0;
P_0c03c5d0: /* original f21d, guest PC 0x0c03c5d0 */
if(!s->budget--) { s->failed_pc=0x0c03c5d0u; return 0; }
r[53]=fr[2];
goto P_0c03c5d2;
P_0c03c5d2: /* original feb1, guest PC 0x0c03c5d2 */
if(!s->budget--) { s->failed_pc=0x0c03c5d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'-');
goto P_0c03c5d4;
P_0c03c5d4: /* original f28c, guest PC 0x0c03c5d4 */
if(!s->budget--) { s->failed_pc=0x0c03c5d4u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03c5d6;
P_0c03c5d6: /* original f331, guest PC 0x0c03c5d6 */
if(!s->budget--) { s->failed_pc=0x0c03c5d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03c5d8;
P_0c03c5d8: /* original f80d, guest PC 0x0c03c5d8 */
if(!s->budget--) { s->failed_pc=0x0c03c5d8u; return 0; }
fr[8]=r[53];
goto P_0c03c5da;
P_0c03c5da: /* original f771, guest PC 0x0c03c5da */
if(!s->budget--) { s->failed_pc=0x0c03c5dau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03c5dc;
P_0c03c5dc: /* original f61d, guest PC 0x0c03c5dc */
if(!s->budget--) { s->failed_pc=0x0c03c5dcu; return 0; }
r[53]=fr[6];
goto P_0c03c5de;
P_0c03c5de: /* original fbb1, guest PC 0x0c03c5de */
if(!s->budget--) { s->failed_pc=0x0c03c5deu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5e0;
P_0c03c5e0: /* original f69c, guest PC 0x0c03c5e0 */
if(!s->budget--) { s->failed_pc=0x0c03c5e0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03c5e2;
P_0c03c5e2: /* original f90d, guest PC 0x0c03c5e2 */
if(!s->budget--) { s->failed_pc=0x0c03c5e2u; return 0; }
fr[9]=r[53];
goto P_0c03c5e4;
P_0c03c5e4: /* original fbfd, guest PC 0x0c03c5e4 */
if(!s->budget--) { s->failed_pc=0x0c03c5e4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5e6;
P_0c03c5e6: /* original 0009, guest PC 0x0c03c5e6 */
if(!s->budget--) { s->failed_pc=0x0c03c5e6u; return 0; }
goto P_0c03c5e8;
P_0c03c5e8: /* original 000b, guest PC 0x0c03c5e8 */
if(!s->budget--) { s->failed_pc=0x0c03c5e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c5ea: /* original 0009, guest PC 0x0c03c5ea */
if(!s->budget--) { s->failed_pc=0x0c03c5eau; return 0; }
if(!vf3_matrix_family(0x0c03c5ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c5ecu; return 0; } return 1;
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
P_0c091afe: /* original d313, guest PC 0x0c091afe */
if(!s->budget--) { s->failed_pc=0x0c091afeu; return 0; }
r[3]=read(ram,0x0c091b4cu,4);
goto P_0c091b00;
P_0c091b00: /* original 7ff4, guest PC 0x0c091b00 */
if(!s->budget--) { s->failed_pc=0x0c091b00u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c091b02;
P_0c091b02: /* original d513, guest PC 0x0c091b02 */
if(!s->budget--) { s->failed_pc=0x0c091b02u; return 0; }
r[5]=read(ram,0x0c091b50u,4);
goto P_0c091b04;
P_0c091b04: /* original e201, guest PC 0x0c091b04 */
if(!s->budget--) { s->failed_pc=0x0c091b04u; return 0; }
r[2]=0x00000001u;
goto P_0c091b06;
P_0c091b06: /* original 6632, guest PC 0x0c091b06 */
if(!s->budget--) { s->failed_pc=0x0c091b06u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c091b08;
P_0c091b08: /* original 1f21, guest PC 0x0c091b08 */
if(!s->budget--) { s->failed_pc=0x0c091b08u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c091b0a;
P_0c091b0a: /* original 7614, guest PC 0x0c091b0a */
if(!s->budget--) { s->failed_pc=0x0c091b0au; return 0; }
r[6]+=0x00000014u;
goto P_0c091b0c;
P_0c091b0c: /* original 6152, guest PC 0x0c091b0c */
if(!s->budget--) { s->failed_pc=0x0c091b0cu; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c091b0e;
P_0c091b0e: /* original 1f12, guest PC 0x0c091b0e */
if(!s->budget--) { s->failed_pc=0x0c091b0eu; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c091b10;
P_0c091b10: /* original 6462, guest PC 0x0c091b10 */
if(!s->budget--) { s->failed_pc=0x0c091b10u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c091b12;
P_0c091b12: /* original 2448, guest PC 0x0c091b12 */
if(!s->budget--) { s->failed_pc=0x0c091b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c091b14;
P_0c091b14: /* original 8d15, guest PC 0x0c091b14 */
if(!s->budget--) { s->failed_pc=0x0c091b14u; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c091b42; }
goto P_0c091b18;
P_0c091b16: /* original e700, guest PC 0x0c091b16 */
if(!s->budget--) { s->failed_pc=0x0c091b16u; return 0; }
r[7]=0x00000000u;
goto P_0c091b18;
P_0c091b18: /* original 6543, guest PC 0x0c091b18 */
if(!s->budget--) { s->failed_pc=0x0c091b18u; return 0; }
r[5]=r[4];
goto P_0c091b1a;
P_0c091b1a: /* original 6363, guest PC 0x0c091b1a */
if(!s->budget--) { s->failed_pc=0x0c091b1au; return 0; }
r[3]=r[6];
goto P_0c091b1c;
P_0c091b1c: /* original 6473, guest PC 0x0c091b1c */
if(!s->budget--) { s->failed_pc=0x0c091b1cu; return 0; }
r[4]=r[7];
goto P_0c091b1e;
P_0c091b1e: /* original 7304, guest PC 0x0c091b1e */
if(!s->budget--) { s->failed_pc=0x0c091b1eu; return 0; }
r[3]+=0x00000004u;
goto P_0c091b20;
P_0c091b20: /* original 4408, guest PC 0x0c091b20 */
if(!s->budget--) { s->failed_pc=0x0c091b20u; return 0; }
r[4]<<=2;
goto P_0c091b22;
P_0c091b22: /* original 343c, guest PC 0x0c091b22 */
if(!s->budget--) { s->failed_pc=0x0c091b22u; return 0; }
r[4]+=r[3];
goto P_0c091b24;
P_0c091b24: /* original 6442, guest PC 0x0c091b24 */
if(!s->budget--) { s->failed_pc=0x0c091b24u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c091b26;
P_0c091b26: /* original 5248, guest PC 0x0c091b26 */
if(!s->budget--) { s->failed_pc=0x0c091b26u; return 0; }
r[2]=read(ram,r[4]+32,4);
goto P_0c091b28;
P_0c091b28: /* original 6323, guest PC 0x0c091b28 */
if(!s->budget--) { s->failed_pc=0x0c091b28u; return 0; }
r[3]=r[2];
goto P_0c091b2a;
P_0c091b2a: /* original 2f22, guest PC 0x0c091b2a */
if(!s->budget--) { s->failed_pc=0x0c091b2au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c091b2c;
P_0c091b2c: /* original 51f2, guest PC 0x0c091b2c */
if(!s->budget--) { s->failed_pc=0x0c091b2cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c091b2e;
P_0c091b2e: /* original 3138, guest PC 0x0c091b2e */
if(!s->budget--) { s->failed_pc=0x0c091b2eu; return 0; }
r[1]-=r[3];
goto P_0c091b30;
P_0c091b30: /* original 2f12, guest PC 0x0c091b30 */
if(!s->budget--) { s->failed_pc=0x0c091b30u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c091b32;
P_0c091b32: /* original 9208, guest PC 0x0c091b32 */
if(!s->budget--) { s->failed_pc=0x0c091b32u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091b46u,2);
goto P_0c091b34;
P_0c091b34: /* original 3126, guest PC 0x0c091b34 */
if(!s->budget--) { s->failed_pc=0x0c091b34u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c091b36;
P_0c091b36: /* original 8d02, guest PC 0x0c091b36 */
if(!s->budget--) { s->failed_pc=0x0c091b36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(cond) { goto P_0c091b3e; }
goto P_0c091b3a;
P_0c091b38: /* original 7701, guest PC 0x0c091b38 */
if(!s->budget--) { s->failed_pc=0x0c091b38u; return 0; }
r[7]+=0x00000001u;
goto P_0c091b3a;
P_0c091b3a: /* original 53f1, guest PC 0x0c091b3a */
if(!s->budget--) { s->failed_pc=0x0c091b3au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c091b3c;
P_0c091b3c: /* original 2432, guest PC 0x0c091b3c */
if(!s->budget--) { s->failed_pc=0x0c091b3cu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c091b3e;
P_0c091b3e: /* original 4510, guest PC 0x0c091b3e */
if(!s->budget--) { s->failed_pc=0x0c091b3eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c091b40;
P_0c091b40: /* original 8beb, guest PC 0x0c091b40 */
if(!s->budget--) { s->failed_pc=0x0c091b40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091b1a; }
goto P_0c091b42;
P_0c091b42: /* original 000b, guest PC 0x0c091b42 */
if(!s->budget--) { s->failed_pc=0x0c091b42u; return 0; }
target=r[16];
r[15]+=0x0000000cu;
s->pc=target; return ram->oob==0;
P_0c091b44: /* original 7f0c, guest PC 0x0c091b44 */
if(!s->budget--) { s->failed_pc=0x0c091b44u; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c091b46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091b46u; return 0; } return 1;
P_0c09d408: /* original e507, guest PC 0x0c09d408 */
if(!s->budget--) { s->failed_pc=0x0c09d408u; return 0; }
r[5]=0x00000007u;
goto P_0c09d40a;
P_0c09d40a: /* original 7408, guest PC 0x0c09d40a */
if(!s->budget--) { s->failed_pc=0x0c09d40au; return 0; }
r[4]+=0x00000008u;
goto P_0c09d40c;
P_0c09d40c: /* original f348, guest PC 0x0c09d40c */
if(!s->budget--) { s->failed_pc=0x0c09d40cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09d40e;
P_0c09d40e: /* original 4510, guest PC 0x0c09d40e */
if(!s->budget--) { s->failed_pc=0x0c09d40eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09d410;
P_0c09d410: /* original f34d, guest PC 0x0c09d410 */
if(!s->budget--) { s->failed_pc=0x0c09d410u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09d412;
P_0c09d412: /* original f43a, guest PC 0x0c09d412 */
if(!s->budget--) { s->failed_pc=0x0c09d412u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09d414;
P_0c09d414: /* original 8ffa, guest PC 0x0c09d414 */
if(!s->budget--) { s->failed_pc=0x0c09d414u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09d40c; }
goto P_0c09d418;
P_0c09d416: /* original 740c, guest PC 0x0c09d416 */
if(!s->budget--) { s->failed_pc=0x0c09d416u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09d418;
P_0c09d418: /* original e50e, guest PC 0x0c09d418 */
if(!s->budget--) { s->failed_pc=0x0c09d418u; return 0; }
r[5]=0x0000000eu;
goto P_0c09d41a;
P_0c09d41a: /* original 74f8, guest PC 0x0c09d41a */
if(!s->budget--) { s->failed_pc=0x0c09d41au; return 0; }
r[4]+=0xfffffff8u;
goto P_0c09d41c;
P_0c09d41c: /* original f348, guest PC 0x0c09d41c */
if(!s->budget--) { s->failed_pc=0x0c09d41cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09d41e;
P_0c09d41e: /* original 4510, guest PC 0x0c09d41e */
if(!s->budget--) { s->failed_pc=0x0c09d41eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09d420;
P_0c09d420: /* original f34d, guest PC 0x0c09d420 */
if(!s->budget--) { s->failed_pc=0x0c09d420u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09d422;
P_0c09d422: /* original f43a, guest PC 0x0c09d422 */
if(!s->budget--) { s->failed_pc=0x0c09d422u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09d424;
P_0c09d424: /* original 8ffa, guest PC 0x0c09d424 */
if(!s->budget--) { s->failed_pc=0x0c09d424u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09d41c; }
goto P_0c09d428;
P_0c09d426: /* original 740c, guest PC 0x0c09d426 */
if(!s->budget--) { s->failed_pc=0x0c09d426u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09d428;
P_0c09d428: /* original 000b, guest PC 0x0c09d428 */
if(!s->budget--) { s->failed_pc=0x0c09d428u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d42a: /* original 0009, guest PC 0x0c09d42a */
if(!s->budget--) { s->failed_pc=0x0c09d42au; return 0; }
goto P_0c09d42c;
P_0c09d42c: /* original 4f22, guest PC 0x0c09d42c */
if(!s->budget--) { s->failed_pc=0x0c09d42cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d42e;
P_0c09d42e: /* original e004, guest PC 0x0c09d42e */
if(!s->budget--) { s->failed_pc=0x0c09d42eu; return 0; }
r[0]=0x00000004u;
goto P_0c09d430;
P_0c09d430: /* original 7ff0, guest PC 0x0c09d430 */
if(!s->budget--) { s->failed_pc=0x0c09d430u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d432;
P_0c09d432: /* original 2f42, guest PC 0x0c09d432 */
if(!s->budget--) { s->failed_pc=0x0c09d432u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d434;
P_0c09d434: /* original 64f3, guest PC 0x0c09d434 */
if(!s->budget--) { s->failed_pc=0x0c09d434u; return 0; }
r[4]=r[15];
goto P_0c09d436;
P_0c09d436: /* original ff47, guest PC 0x0c09d436 */
if(!s->budget--) { s->failed_pc=0x0c09d436u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d438;
P_0c09d438: /* original e008, guest PC 0x0c09d438 */
if(!s->budget--) { s->failed_pc=0x0c09d438u; return 0; }
r[0]=0x00000008u;
goto P_0c09d43a;
P_0c09d43a: /* original f38d, guest PC 0x0c09d43a */
if(!s->budget--) { s->failed_pc=0x0c09d43au; return 0; }
fr[3]=0;
goto P_0c09d43c;
P_0c09d43c: /* original ff37, guest PC 0x0c09d43c */
if(!s->budget--) { s->failed_pc=0x0c09d43cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09d43e;
P_0c09d43e: /* original e00c, guest PC 0x0c09d43e */
if(!s->budget--) { s->failed_pc=0x0c09d43eu; return 0; }
r[0]=0x0000000cu;
goto P_0c09d440;
P_0c09d440: /* original ff57, guest PC 0x0c09d440 */
if(!s->budget--) { s->failed_pc=0x0c09d440u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d442;
P_0c09d442: /* original d34e, guest PC 0x0c09d442 */
if(!s->budget--) { s->failed_pc=0x0c09d442u; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d444;
P_0c09d444: /* original 65f2, guest PC 0x0c09d444 */
if(!s->budget--) { s->failed_pc=0x0c09d444u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d446;
P_0c09d446: /* original 430b, guest PC 0x0c09d446 */
if(!s->budget--) { s->failed_pc=0x0c09d446u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d44au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d44au) { target=s->pc; goto dispatch; }
goto P_0c09d44a;
P_0c09d448: /* original 7404, guest PC 0x0c09d448 */
if(!s->budget--) { s->failed_pc=0x0c09d448u; return 0; }
r[4]+=0x00000004u;
goto P_0c09d44a;
P_0c09d44a: /* original 7f10, guest PC 0x0c09d44a */
if(!s->budget--) { s->failed_pc=0x0c09d44au; return 0; }
r[15]+=0x00000010u;
goto P_0c09d44c;
P_0c09d44c: /* original 4f26, guest PC 0x0c09d44c */
if(!s->budget--) { s->failed_pc=0x0c09d44cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d44e;
P_0c09d44e: /* original 000b, guest PC 0x0c09d44e */
if(!s->budget--) { s->failed_pc=0x0c09d44eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d450: /* original 0009, guest PC 0x0c09d450 */
if(!s->budget--) { s->failed_pc=0x0c09d450u; return 0; }
return vf3_matrix_family(0x0c09d452u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
