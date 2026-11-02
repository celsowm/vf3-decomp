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
int vf3_away_batch167_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c03b300u: goto P_0c03b300;
case 0x0c03b302u: goto P_0c03b302;
case 0x0c03b304u: goto P_0c03b304;
case 0x0c03b306u: goto P_0c03b306;
case 0x0c03b308u: goto P_0c03b308;
case 0x0c03b30au: goto P_0c03b30a;
case 0x0c03b30cu: goto P_0c03b30c;
case 0x0c03b30eu: goto P_0c03b30e;
case 0x0c03b310u: goto P_0c03b310;
case 0x0c03b312u: goto P_0c03b312;
case 0x0c03b314u: goto P_0c03b314;
case 0x0c03b316u: goto P_0c03b316;
case 0x0c03b318u: goto P_0c03b318;
case 0x0c03b31au: goto P_0c03b31a;
case 0x0c03b31cu: goto P_0c03b31c;
case 0x0c03b31eu: goto P_0c03b31e;
case 0x0c03b320u: goto P_0c03b320;
case 0x0c03b322u: goto P_0c03b322;
case 0x0c03b324u: goto P_0c03b324;
case 0x0c03b326u: goto P_0c03b326;
case 0x0c03b328u: goto P_0c03b328;
case 0x0c03b32au: goto P_0c03b32a;
case 0x0c03b32cu: goto P_0c03b32c;
case 0x0c03b32eu: goto P_0c03b32e;
case 0x0c03b330u: goto P_0c03b330;
case 0x0c03b332u: goto P_0c03b332;
case 0x0c03b334u: goto P_0c03b334;
case 0x0c03b336u: goto P_0c03b336;
case 0x0c03b338u: goto P_0c03b338;
case 0x0c03d040u: goto P_0c03d040;
case 0x0c03d042u: goto P_0c03d042;
case 0x0c03d044u: goto P_0c03d044;
case 0x0c03d046u: goto P_0c03d046;
case 0x0c03d048u: goto P_0c03d048;
case 0x0c03d060u: goto P_0c03d060;
case 0x0c03d062u: goto P_0c03d062;
case 0x0c03d064u: goto P_0c03d064;
case 0x0c03d066u: goto P_0c03d066;
case 0x0c03d068u: goto P_0c03d068;
case 0x0c03d06au: goto P_0c03d06a;
case 0x0c03d06cu: goto P_0c03d06c;
case 0x0c03d06eu: goto P_0c03d06e;
case 0x0c03d070u: goto P_0c03d070;
case 0x0c03d072u: goto P_0c03d072;
case 0x0c03d074u: goto P_0c03d074;
case 0x0c03d076u: goto P_0c03d076;
case 0x0c03d078u: goto P_0c03d078;
case 0x0c03d07au: goto P_0c03d07a;
case 0x0c03d07cu: goto P_0c03d07c;
case 0x0c03d07eu: goto P_0c03d07e;
case 0x0c03d080u: goto P_0c03d080;
case 0x0c03d082u: goto P_0c03d082;
case 0x0c03e130u: goto P_0c03e130;
case 0x0c03e132u: goto P_0c03e132;
case 0x0c03e134u: goto P_0c03e134;
case 0x0c03e136u: goto P_0c03e136;
case 0x0c03e138u: goto P_0c03e138;
case 0x0c03e13au: goto P_0c03e13a;
case 0x0c03e13cu: goto P_0c03e13c;
case 0x0c03e13eu: goto P_0c03e13e;
case 0x0c03e140u: goto P_0c03e140;
case 0x0c03e142u: goto P_0c03e142;
case 0x0c03e144u: goto P_0c03e144;
case 0x0c03e146u: goto P_0c03e146;
case 0x0c03e148u: goto P_0c03e148;
case 0x0c03e14au: goto P_0c03e14a;
case 0x0c03e150u: goto P_0c03e150;
case 0x0c03e152u: goto P_0c03e152;
case 0x0c03e154u: goto P_0c03e154;
case 0x0c03e156u: goto P_0c03e156;
case 0x0c03e158u: goto P_0c03e158;
case 0x0c03e15au: goto P_0c03e15a;
case 0x0c03e160u: goto P_0c03e160;
case 0x0c03e162u: goto P_0c03e162;
case 0x0c03e164u: goto P_0c03e164;
case 0x0c03e166u: goto P_0c03e166;
case 0x0c03e168u: goto P_0c03e168;
case 0x0c03e16au: goto P_0c03e16a;
case 0x0c03e16cu: goto P_0c03e16c;
case 0x0c03e16eu: goto P_0c03e16e;
case 0x0c03e170u: goto P_0c03e170;
case 0x0c03e172u: goto P_0c03e172;
case 0x0c03e174u: goto P_0c03e174;
case 0x0c03e176u: goto P_0c03e176;
case 0x0c03e178u: goto P_0c03e178;
case 0x0c03e17au: goto P_0c03e17a;
case 0x0c03e17cu: goto P_0c03e17c;
case 0x0c03e17eu: goto P_0c03e17e;
case 0x0c03e180u: goto P_0c03e180;
case 0x0c03e182u: goto P_0c03e182;
case 0x0c03e184u: goto P_0c03e184;
case 0x0c03e186u: goto P_0c03e186;
case 0x0c03e188u: goto P_0c03e188;
case 0x0c03e18au: goto P_0c03e18a;
case 0x0c03e18cu: goto P_0c03e18c;
case 0x0c03e2a0u: goto P_0c03e2a0;
case 0x0c03e2a2u: goto P_0c03e2a2;
case 0x0c03e2b0u: goto P_0c03e2b0;
case 0x0c03e2b2u: goto P_0c03e2b2;
case 0x0c03e2b4u: goto P_0c03e2b4;
case 0x0c03e2b6u: goto P_0c03e2b6;
case 0x0c03e2b8u: goto P_0c03e2b8;
case 0x0c03e2bau: goto P_0c03e2ba;
case 0x0c03e2bcu: goto P_0c03e2bc;
case 0x0c03e2beu: goto P_0c03e2be;
case 0x0c03e2c0u: goto P_0c03e2c0;
case 0x0c03e2c2u: goto P_0c03e2c2;
case 0x0c03e2c4u: goto P_0c03e2c4;
case 0x0c03e2c6u: goto P_0c03e2c6;
case 0x0c03e2c8u: goto P_0c03e2c8;
case 0x0c03e2cau: goto P_0c03e2ca;
case 0x0c03e2ccu: goto P_0c03e2cc;
case 0x0c03e2ceu: goto P_0c03e2ce;
case 0x0c03e2d0u: goto P_0c03e2d0;
case 0x0c03e2d2u: goto P_0c03e2d2;
case 0x0c03e2d4u: goto P_0c03e2d4;
case 0x0c03e2d6u: goto P_0c03e2d6;
case 0x0c03e2d8u: goto P_0c03e2d8;
case 0x0c03e2dau: goto P_0c03e2da;
case 0x0c03e2dcu: goto P_0c03e2dc;
case 0x0c03e2deu: goto P_0c03e2de;
case 0x0c03e2f0u: goto P_0c03e2f0;
case 0x0c03e2f2u: goto P_0c03e2f2;
case 0x0c03e2f4u: goto P_0c03e2f4;
case 0x0c03e2f6u: goto P_0c03e2f6;
case 0x0c03e2f8u: goto P_0c03e2f8;
case 0x0c03e2fau: goto P_0c03e2fa;
case 0x0c03e2fcu: goto P_0c03e2fc;
case 0x0c03e2feu: goto P_0c03e2fe;
case 0x0c03e300u: goto P_0c03e300;
case 0x0c03e302u: goto P_0c03e302;
case 0x0c03e304u: goto P_0c03e304;
case 0x0c03e306u: goto P_0c03e306;
case 0x0c03e308u: goto P_0c03e308;
case 0x0c03e30au: goto P_0c03e30a;
case 0x0c03e30cu: goto P_0c03e30c;
case 0x0c03e30eu: goto P_0c03e30e;
case 0x0c03e310u: goto P_0c03e310;
case 0x0c03e312u: goto P_0c03e312;
case 0x0c03e314u: goto P_0c03e314;
case 0x0c03e316u: goto P_0c03e316;
case 0x0c03e318u: goto P_0c03e318;
case 0x0c03e31au: goto P_0c03e31a;
case 0x0c03e31cu: goto P_0c03e31c;
case 0x0c03e31eu: goto P_0c03e31e;
case 0x0c03e320u: goto P_0c03e320;
case 0x0c03e322u: goto P_0c03e322;
case 0x0c03e324u: goto P_0c03e324;
case 0x0c03e326u: goto P_0c03e326;
case 0x0c03e330u: goto P_0c03e330;
case 0x0c03e332u: goto P_0c03e332;
case 0x0c03e334u: goto P_0c03e334;
case 0x0c03e336u: goto P_0c03e336;
case 0x0c03e338u: goto P_0c03e338;
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
P_0c03b300: /* original 2fe6, guest PC 0x0c03b300 */
if(!s->budget--) { s->failed_pc=0x0c03b300u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b302;
P_0c03b302: /* original 6743, guest PC 0x0c03b302 */
if(!s->budget--) { s->failed_pc=0x0c03b302u; return 0; }
r[7]=r[4];
goto P_0c03b304;
P_0c03b304: /* original 4f22, guest PC 0x0c03b304 */
if(!s->budget--) { s->failed_pc=0x0c03b304u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b306;
P_0c03b306: /* original 4729, guest PC 0x0c03b306 */
if(!s->budget--) { s->failed_pc=0x0c03b306u; return 0; }
r[7]>>=16;
goto P_0c03b308;
P_0c03b308: /* original 6543, guest PC 0x0c03b308 */
if(!s->budget--) { s->failed_pc=0x0c03b308u; return 0; }
r[5]=r[4];
goto P_0c03b30a;
P_0c03b30a: /* original 4719, guest PC 0x0c03b30a */
if(!s->budget--) { s->failed_pc=0x0c03b30au; return 0; }
r[7]>>=8;
goto P_0c03b30c;
P_0c03b30c: /* original 6643, guest PC 0x0c03b30c */
if(!s->budget--) { s->failed_pc=0x0c03b30cu; return 0; }
r[6]=r[4];
goto P_0c03b30e;
P_0c03b30e: /* original 677e, guest PC 0x0c03b30e */
if(!s->budget--) { s->failed_pc=0x0c03b30eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c03b310;
P_0c03b310: /* original 7ffc, guest PC 0x0c03b310 */
if(!s->budget--) { s->failed_pc=0x0c03b310u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03b312;
P_0c03b312: /* original 6073, guest PC 0x0c03b312 */
if(!s->budget--) { s->failed_pc=0x0c03b312u; return 0; }
r[0]=r[7];
goto P_0c03b314;
P_0c03b314: /* original 6ef3, guest PC 0x0c03b314 */
if(!s->budget--) { s->failed_pc=0x0c03b314u; return 0; }
r[14]=r[15];
goto P_0c03b316;
P_0c03b316: /* original 4529, guest PC 0x0c03b316 */
if(!s->budget--) { s->failed_pc=0x0c03b316u; return 0; }
r[5]>>=16;
goto P_0c03b318;
P_0c03b318: /* original 80e3, guest PC 0x0c03b318 */
if(!s->budget--) { s->failed_pc=0x0c03b318u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c03b31a;
P_0c03b31a: /* original 655f, guest PC 0x0c03b31a */
if(!s->budget--) { s->failed_pc=0x0c03b31au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c03b31c;
P_0c03b31c: /* original 6053, guest PC 0x0c03b31c */
if(!s->budget--) { s->failed_pc=0x0c03b31cu; return 0; }
r[0]=r[5];
goto P_0c03b31e;
P_0c03b31e: /* original e3f8, guest PC 0x0c03b31e */
if(!s->budget--) { s->failed_pc=0x0c03b31eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c03b320;
P_0c03b320: /* original 80e2, guest PC 0x0c03b320 */
if(!s->budget--) { s->failed_pc=0x0c03b320u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c03b322;
P_0c03b322: /* original 463c, guest PC 0x0c03b322 */
if(!s->budget--) { s->failed_pc=0x0c03b322u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c03b324;
P_0c03b324: /* original 6063, guest PC 0x0c03b324 */
if(!s->budget--) { s->failed_pc=0x0c03b324u; return 0; }
r[0]=r[6];
goto P_0c03b326;
P_0c03b326: /* original 80e1, guest PC 0x0c03b326 */
if(!s->budget--) { s->failed_pc=0x0c03b326u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c03b328;
P_0c03b328: /* original 2e40, guest PC 0x0c03b328 */
if(!s->budget--) { s->failed_pc=0x0c03b328u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c03b32a;
P_0c03b32a: /* original 63e2, guest PC 0x0c03b32a */
if(!s->budget--) { s->failed_pc=0x0c03b32au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03b32c;
P_0c03b32c: /* original d21e, guest PC 0x0c03b32c */
if(!s->budget--) { s->failed_pc=0x0c03b32cu; return 0; }
r[2]=read(ram,0x0c03b3a8u,4);
goto P_0c03b32e;
P_0c03b32e: /* original 420b, guest PC 0x0c03b32e */
if(!s->budget--) { s->failed_pc=0x0c03b32eu; return 0; }
target=r[2];
r[16]=code_base|0x0c03b332u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03b332u) { target=s->pc; goto dispatch; }
goto P_0c03b332;
P_0c03b330: /* original 2f36, guest PC 0x0c03b330 */
if(!s->budget--) { s->failed_pc=0x0c03b330u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b332;
P_0c03b332: /* original 7f08, guest PC 0x0c03b332 */
if(!s->budget--) { s->failed_pc=0x0c03b332u; return 0; }
r[15]+=0x00000008u;
goto P_0c03b334;
P_0c03b334: /* original 4f26, guest PC 0x0c03b334 */
if(!s->budget--) { s->failed_pc=0x0c03b334u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b336;
P_0c03b336: /* original 000b, guest PC 0x0c03b336 */
if(!s->budget--) { s->failed_pc=0x0c03b336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b338: /* original 6ef6, guest PC 0x0c03b338 */
if(!s->budget--) { s->failed_pc=0x0c03b338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03b33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b33au; return 0; } return 1;
P_0c03d040: /* original 7ffc, guest PC 0x0c03d040 */
if(!s->budget--) { s->failed_pc=0x0c03d040u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03d042;
P_0c03d042: /* original 6543, guest PC 0x0c03d042 */
if(!s->budget--) { s->failed_pc=0x0c03d042u; return 0; }
r[5]=r[4];
goto P_0c03d044;
P_0c03d044: /* original 2f42, guest PC 0x0c03d044 */
if(!s->budget--) { s->failed_pc=0x0c03d044u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03d046;
P_0c03d046: /* original a00b, guest PC 0x0c03d046 */
if(!s->budget--) { s->failed_pc=0x0c03d046u; return 0; }
goto P_0c03d060;
P_0c03d048: /* original 0009, guest PC 0x0c03d048 */
if(!s->budget--) { s->failed_pc=0x0c03d048u; return 0; }
if(!vf3_matrix_family(0x0c03d04au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d04au; return 0; } return 1;
P_0c03d060: /* original f449, guest PC 0x0c03d060 */
if(!s->budget--) { s->failed_pc=0x0c03d060u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d062;
P_0c03d062: /* original f549, guest PC 0x0c03d062 */
if(!s->budget--) { s->failed_pc=0x0c03d062u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d064;
P_0c03d064: /* original f649, guest PC 0x0c03d064 */
if(!s->budget--) { s->failed_pc=0x0c03d064u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d066;
P_0c03d066: /* original f78d, guest PC 0x0c03d066 */
if(!s->budget--) { s->failed_pc=0x0c03d066u; return 0; }
fr[7]=0;
goto P_0c03d068;
P_0c03d068: /* original 750c, guest PC 0x0c03d068 */
if(!s->budget--) { s->failed_pc=0x0c03d068u; return 0; }
r[5]+=0x0000000cu;
goto P_0c03d06a;
P_0c03d06a: /* original f5ed, guest PC 0x0c03d06a */
if(!s->budget--) { s->failed_pc=0x0c03d06au; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03d06c;
P_0c03d06c: /* original f07c, guest PC 0x0c03d06c */
if(!s->budget--) { s->failed_pc=0x0c03d06cu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c03d06e;
P_0c03d06e: /* original f06d, guest PC 0x0c03d06e */
if(!s->budget--) { s->failed_pc=0x0c03d06eu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c03d070;
P_0c03d070: /* original f77d, guest PC 0x0c03d070 */
if(!s->budget--) { s->failed_pc=0x0c03d070u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03d072;
P_0c03d072: /* original f672, guest PC 0x0c03d072 */
if(!s->budget--) { s->failed_pc=0x0c03d072u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03d074;
P_0c03d074: /* original f572, guest PC 0x0c03d074 */
if(!s->budget--) { s->failed_pc=0x0c03d074u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03d076;
P_0c03d076: /* original f472, guest PC 0x0c03d076 */
if(!s->budget--) { s->failed_pc=0x0c03d076u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03d078;
P_0c03d078: /* original f56b, guest PC 0x0c03d078 */
if(!s->budget--) { s->failed_pc=0x0c03d078u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c03d07a;
P_0c03d07a: /* original f55b, guest PC 0x0c03d07a */
if(!s->budget--) { s->failed_pc=0x0c03d07au; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c03d07c;
P_0c03d07c: /* original f54b, guest PC 0x0c03d07c */
if(!s->budget--) { s->failed_pc=0x0c03d07cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c03d07e;
P_0c03d07e: /* original 0009, guest PC 0x0c03d07e */
if(!s->budget--) { s->failed_pc=0x0c03d07eu; return 0; }
goto P_0c03d080;
P_0c03d080: /* original 000b, guest PC 0x0c03d080 */
if(!s->budget--) { s->failed_pc=0x0c03d080u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c03d082: /* original 7f04, guest PC 0x0c03d082 */
if(!s->budget--) { s->failed_pc=0x0c03d082u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c03d084u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d084u; return 0; } return 1;
P_0c03e130: /* original 2fe6, guest PC 0x0c03e130 */
if(!s->budget--) { s->failed_pc=0x0c03e130u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e132;
P_0c03e132: /* original 2558, guest PC 0x0c03e132 */
if(!s->budget--) { s->failed_pc=0x0c03e132u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03e134;
P_0c03e134: /* original 2fd6, guest PC 0x0c03e134 */
if(!s->budget--) { s->failed_pc=0x0c03e134u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e136;
P_0c03e136: /* original 2fc6, guest PC 0x0c03e136 */
if(!s->budget--) { s->failed_pc=0x0c03e136u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e138;
P_0c03e138: /* original 2fb6, guest PC 0x0c03e138 */
if(!s->budget--) { s->failed_pc=0x0c03e138u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13a;
P_0c03e13a: /* original 2fa6, guest PC 0x0c03e13a */
if(!s->budget--) { s->failed_pc=0x0c03e13au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13c;
P_0c03e13c: /* original 2f96, guest PC 0x0c03e13c */
if(!s->budget--) { s->failed_pc=0x0c03e13cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13e;
P_0c03e13e: /* original 2f86, guest PC 0x0c03e13e */
if(!s->budget--) { s->failed_pc=0x0c03e13eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e140;
P_0c03e140: /* original 4f22, guest PC 0x0c03e140 */
if(!s->budget--) { s->failed_pc=0x0c03e140u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e142;
P_0c03e142: /* original 7ff8, guest PC 0x0c03e142 */
if(!s->budget--) { s->failed_pc=0x0c03e142u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03e144;
P_0c03e144: /* original 8d04, guest PC 0x0c03e144 */
if(!s->budget--) { s->failed_pc=0x0c03e144u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c03e150; }
goto P_0c03e148;
P_0c03e146: /* original ec00, guest PC 0x0c03e146 */
if(!s->budget--) { s->failed_pc=0x0c03e146u; return 0; }
r[12]=0x00000000u;
goto P_0c03e148;
P_0c03e148: /* original a003, guest PC 0x0c03e148 */
if(!s->budget--) { s->failed_pc=0x0c03e148u; return 0; }
tmp=read(ram,r[5],4);
r[8]=tmp;
goto P_0c03e152;
P_0c03e14a: /* original 6852, guest PC 0x0c03e14a */
if(!s->budget--) { s->failed_pc=0x0c03e14au; return 0; }
tmp=read(ram,r[5],4);
r[8]=tmp;
if(!vf3_matrix_family(0x0c03e14cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e14cu; return 0; } return 1;
P_0c03e150: /* original 68c3, guest PC 0x0c03e150 */
if(!s->budget--) { s->failed_pc=0x0c03e150u; return 0; }
r[8]=r[12];
goto P_0c03e152;
P_0c03e152: /* original 2668, guest PC 0x0c03e152 */
if(!s->budget--) { s->failed_pc=0x0c03e152u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c03e154;
P_0c03e154: /* original 8904, guest PC 0x0c03e154 */
if(!s->budget--) { s->failed_pc=0x0c03e154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e160; }
goto P_0c03e156;
P_0c03e156: /* original 6262, guest PC 0x0c03e156 */
if(!s->budget--) { s->failed_pc=0x0c03e156u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c03e158;
P_0c03e158: /* original a003, guest PC 0x0c03e158 */
if(!s->budget--) { s->failed_pc=0x0c03e158u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03e162;
P_0c03e15a: /* original 1f21, guest PC 0x0c03e15a */
if(!s->budget--) { s->failed_pc=0x0c03e15au; return 0; }
write(ram,r[15]+4,r[2],4);
if(!vf3_matrix_family(0x0c03e15cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e15cu; return 0; } return 1;
P_0c03e160: /* original 1fc1, guest PC 0x0c03e160 */
if(!s->budget--) { s->failed_pc=0x0c03e160u; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c03e162;
P_0c03e162: /* original d90b, guest PC 0x0c03e162 */
if(!s->budget--) { s->failed_pc=0x0c03e162u; return 0; }
r[9]=read(ram,0x0c03e190u,4);
goto P_0c03e164;
P_0c03e164: /* original 6ec3, guest PC 0x0c03e164 */
if(!s->budget--) { s->failed_pc=0x0c03e164u; return 0; }
r[14]=r[12];
goto P_0c03e166;
P_0c03e166: /* original da0b, guest PC 0x0c03e166 */
if(!s->budget--) { s->failed_pc=0x0c03e166u; return 0; }
r[10]=read(ram,0x0c03e194u,4);
goto P_0c03e168;
P_0c03e168: /* original ebff, guest PC 0x0c03e168 */
if(!s->budget--) { s->failed_pc=0x0c03e168u; return 0; }
r[11]=0xffffffffu;
goto P_0c03e16a;
P_0c03e16a: /* original 5d43, guest PC 0x0c03e16a */
if(!s->budget--) { s->failed_pc=0x0c03e16au; return 0; }
r[13]=read(ram,r[4]+12,4);
goto P_0c03e16c;
P_0c03e16c: /* original 64d5, guest PC 0x0c03e16c */
if(!s->budget--) { s->failed_pc=0x0c03e16cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[4]=tmp;
goto P_0c03e16e;
P_0c03e16e: /* original 4415, guest PC 0x0c03e16e */
if(!s->budget--) { s->failed_pc=0x0c03e16eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c03e170;
P_0c03e170: /* original 8901, guest PC 0x0c03e170 */
if(!s->budget--) { s->failed_pc=0x0c03e170u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e176; }
goto P_0c03e172;
P_0c03e172: /* original a09d, guest PC 0x0c03e172 */
if(!s->budget--) { s->failed_pc=0x0c03e172u; return 0; }
goto P_0c03e2b0;
P_0c03e174: /* original 0009, guest PC 0x0c03e174 */
if(!s->budget--) { s->failed_pc=0x0c03e174u; return 0; }
goto P_0c03e176;
P_0c03e176: /* original 604c, guest PC 0x0c03e176 */
if(!s->budget--) { s->failed_pc=0x0c03e176u; return 0; }
r[0]=r[4]&255u;
goto P_0c03e178;
P_0c03e178: /* original e11e, guest PC 0x0c03e178 */
if(!s->budget--) { s->failed_pc=0x0c03e178u; return 0; }
r[1]=0x0000001eu;
goto P_0c03e17a;
P_0c03e17a: /* original 3012, guest PC 0x0c03e17a */
if(!s->budget--) { s->failed_pc=0x0c03e17au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c03e17c;
P_0c03e17c: /* original 8b01, guest PC 0x0c03e17c */
if(!s->budget--) { s->failed_pc=0x0c03e17cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e182; }
goto P_0c03e17e;
P_0c03e17e: /* original a08f, guest PC 0x0c03e17e */
if(!s->budget--) { s->failed_pc=0x0c03e17eu; return 0; }
goto P_0c03e2a0;
P_0c03e180: /* original 0009, guest PC 0x0c03e180 */
if(!s->budget--) { s->failed_pc=0x0c03e180u; return 0; }
goto P_0c03e182;
P_0c03e182: /* original 4000, guest PC 0x0c03e182 */
if(!s->budget--) { s->failed_pc=0x0c03e182u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03e184;
P_0c03e184: /* original 6103, guest PC 0x0c03e184 */
if(!s->budget--) { s->failed_pc=0x0c03e184u; return 0; }
r[1]=r[0];
goto P_0c03e186;
P_0c03e186: /* original c704, guest PC 0x0c03e186 */
if(!s->budget--) { s->failed_pc=0x0c03e186u; return 0; }
r[0]=code_base|0x0003e198u;
goto P_0c03e188;
P_0c03e188: /* original 001d, guest PC 0x0c03e188 */
if(!s->budget--) { s->failed_pc=0x0c03e188u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c03e18a;
P_0c03e18a: /* original 0023, guest PC 0x0c03e18a */
if(!s->budget--) { s->failed_pc=0x0c03e18au; return 0; }
target=r[0]+0x0c03e18eu;
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
P_0c03e18c: /* original 0009, guest PC 0x0c03e18c */
if(!s->budget--) { s->failed_pc=0x0c03e18cu; return 0; }
if(!vf3_matrix_family(0x0c03e18eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e18eu; return 0; } return 1;
P_0c03e2a0: /* original a014, guest PC 0x0c03e2a0 */
if(!s->budget--) { s->failed_pc=0x0c03e2a0u; return 0; }
r[0]=0xffffffffu;
goto P_0c03e2cc;
P_0c03e2a2: /* original e0ff, guest PC 0x0c03e2a2 */
if(!s->budget--) { s->failed_pc=0x0c03e2a2u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c03e2a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e2a4u; return 0; } return 1;
P_0c03e2b0: /* original 2ee8, guest PC 0x0c03e2b0 */
if(!s->budget--) { s->failed_pc=0x0c03e2b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c03e2b2;
P_0c03e2b2: /* original 890a, guest PC 0x0c03e2b2 */
if(!s->budget--) { s->failed_pc=0x0c03e2b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e2ca; }
goto P_0c03e2b4;
P_0c03e2b4: /* original d20b, guest PC 0x0c03e2b4 */
if(!s->budget--) { s->failed_pc=0x0c03e2b4u; return 0; }
r[2]=read(ram,0x0c03e2e4u,4);
goto P_0c03e2b6;
P_0c03e2b6: /* original 420b, guest PC 0x0c03e2b6 */
if(!s->budget--) { s->failed_pc=0x0c03e2b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c03e2bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e2bau) { target=s->pc; goto dispatch; }
goto P_0c03e2ba;
P_0c03e2b8: /* original 64e3, guest PC 0x0c03e2b8 */
if(!s->budget--) { s->failed_pc=0x0c03e2b8u; return 0; }
r[4]=r[14];
goto P_0c03e2ba;
P_0c03e2ba: /* original 60e2, guest PC 0x0c03e2ba */
if(!s->budget--) { s->failed_pc=0x0c03e2bau; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03e2bc;
P_0c03e2bc: /* original cb0d, guest PC 0x0c03e2bc */
if(!s->budget--) { s->failed_pc=0x0c03e2bcu; return 0; }
r[0]|=13u;
goto P_0c03e2be;
P_0c03e2be: /* original 2e02, guest PC 0x0c03e2be */
if(!s->budget--) { s->failed_pc=0x0c03e2beu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c03e2c0;
P_0c03e2c0: /* original 50e2, guest PC 0x0c03e2c0 */
if(!s->budget--) { s->failed_pc=0x0c03e2c0u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03e2c2;
P_0c03e2c2: /* original 930d, guest PC 0x0c03e2c2 */
if(!s->budget--) { s->failed_pc=0x0c03e2c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e2e0u,2);
goto P_0c03e2c4;
P_0c03e2c4: /* original 2039, guest PC 0x0c03e2c4 */
if(!s->budget--) { s->failed_pc=0x0c03e2c4u; return 0; }
r[0]&=r[3];
goto P_0c03e2c6;
P_0c03e2c6: /* original cbc0, guest PC 0x0c03e2c6 */
if(!s->budget--) { s->failed_pc=0x0c03e2c6u; return 0; }
r[0]|=192u;
goto P_0c03e2c8;
P_0c03e2c8: /* original 1e02, guest PC 0x0c03e2c8 */
if(!s->budget--) { s->failed_pc=0x0c03e2c8u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03e2ca;
P_0c03e2ca: /* original e000, guest PC 0x0c03e2ca */
if(!s->budget--) { s->failed_pc=0x0c03e2cau; return 0; }
r[0]=0x00000000u;
goto P_0c03e2cc;
P_0c03e2cc: /* original 7f08, guest PC 0x0c03e2cc */
if(!s->budget--) { s->failed_pc=0x0c03e2ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c03e2ce;
P_0c03e2ce: /* original 4f26, guest PC 0x0c03e2ce */
if(!s->budget--) { s->failed_pc=0x0c03e2ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e2d0;
P_0c03e2d0: /* original 68f6, guest PC 0x0c03e2d0 */
if(!s->budget--) { s->failed_pc=0x0c03e2d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03e2d2;
P_0c03e2d2: /* original 69f6, guest PC 0x0c03e2d2 */
if(!s->budget--) { s->failed_pc=0x0c03e2d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03e2d4;
P_0c03e2d4: /* original 6af6, guest PC 0x0c03e2d4 */
if(!s->budget--) { s->failed_pc=0x0c03e2d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03e2d6;
P_0c03e2d6: /* original 6bf6, guest PC 0x0c03e2d6 */
if(!s->budget--) { s->failed_pc=0x0c03e2d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03e2d8;
P_0c03e2d8: /* original 6cf6, guest PC 0x0c03e2d8 */
if(!s->budget--) { s->failed_pc=0x0c03e2d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e2da;
P_0c03e2da: /* original 6df6, guest PC 0x0c03e2da */
if(!s->budget--) { s->failed_pc=0x0c03e2dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e2dc;
P_0c03e2dc: /* original 000b, guest PC 0x0c03e2dc */
if(!s->budget--) { s->failed_pc=0x0c03e2dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03e2de: /* original 6ef6, guest PC 0x0c03e2de */
if(!s->budget--) { s->failed_pc=0x0c03e2deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e2e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e2e0u; return 0; } return 1;
P_0c03e2f0: /* original 2fe6, guest PC 0x0c03e2f0 */
if(!s->budget--) { s->failed_pc=0x0c03e2f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2f2;
P_0c03e2f2: /* original 6e43, guest PC 0x0c03e2f2 */
if(!s->budget--) { s->failed_pc=0x0c03e2f2u; return 0; }
r[14]=r[4];
goto P_0c03e2f4;
P_0c03e2f4: /* original 2fd6, guest PC 0x0c03e2f4 */
if(!s->budget--) { s->failed_pc=0x0c03e2f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2f6;
P_0c03e2f6: /* original 6d63, guest PC 0x0c03e2f6 */
if(!s->budget--) { s->failed_pc=0x0c03e2f6u; return 0; }
r[13]=r[6];
goto P_0c03e2f8;
P_0c03e2f8: /* original 2fc6, guest PC 0x0c03e2f8 */
if(!s->budget--) { s->failed_pc=0x0c03e2f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2fa;
P_0c03e2fa: /* original 6c53, guest PC 0x0c03e2fa */
if(!s->budget--) { s->failed_pc=0x0c03e2fau; return 0; }
r[12]=r[5];
goto P_0c03e2fc;
P_0c03e2fc: /* original 4f22, guest PC 0x0c03e2fc */
if(!s->budget--) { s->failed_pc=0x0c03e2fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e2fe;
P_0c03e2fe: /* original 53e1, guest PC 0x0c03e2fe */
if(!s->budget--) { s->failed_pc=0x0c03e2feu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c03e300;
P_0c03e300: /* original 2338, guest PC 0x0c03e300 */
if(!s->budget--) { s->failed_pc=0x0c03e300u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03e302;
P_0c03e302: /* original 8903, guest PC 0x0c03e302 */
if(!s->budget--) { s->failed_pc=0x0c03e302u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e30c; }
goto P_0c03e304;
P_0c03e304: /* original 65c3, guest PC 0x0c03e304 */
if(!s->budget--) { s->failed_pc=0x0c03e304u; return 0; }
r[5]=r[12];
goto P_0c03e306;
P_0c03e306: /* original 66d3, guest PC 0x0c03e306 */
if(!s->budget--) { s->failed_pc=0x0c03e306u; return 0; }
r[6]=r[13];
goto P_0c03e308;
P_0c03e308: /* original bf12, guest PC 0x0c03e308 */
if(!s->budget--) { s->failed_pc=0x0c03e308u; return 0; }
target=code_base|0x0c03e130u; r[16]=code_base|0x0c03e30cu;
r[4]=read(ram,r[14]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e30cu) { target=s->pc; goto dispatch; }
goto P_0c03e30c;
P_0c03e30a: /* original 54e1, guest PC 0x0c03e30a */
if(!s->budget--) { s->failed_pc=0x0c03e30au; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c03e30c;
P_0c03e30c: /* original 52eb, guest PC 0x0c03e30c */
if(!s->budget--) { s->failed_pc=0x0c03e30cu; return 0; }
r[2]=read(ram,r[14]+44,4);
goto P_0c03e30e;
P_0c03e30e: /* original 2228, guest PC 0x0c03e30e */
if(!s->budget--) { s->failed_pc=0x0c03e30eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e310;
P_0c03e310: /* original 8903, guest PC 0x0c03e310 */
if(!s->budget--) { s->failed_pc=0x0c03e310u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e31a; }
goto P_0c03e312;
P_0c03e312: /* original 65c3, guest PC 0x0c03e312 */
if(!s->budget--) { s->failed_pc=0x0c03e312u; return 0; }
r[5]=r[12];
goto P_0c03e314;
P_0c03e314: /* original 66d3, guest PC 0x0c03e314 */
if(!s->budget--) { s->failed_pc=0x0c03e314u; return 0; }
r[6]=r[13];
goto P_0c03e316;
P_0c03e316: /* original bfeb, guest PC 0x0c03e316 */
if(!s->budget--) { s->failed_pc=0x0c03e316u; return 0; }
target=code_base|0x0c03e2f0u; r[16]=code_base|0x0c03e31au;
r[4]=read(ram,r[14]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e31au) { target=s->pc; goto dispatch; }
goto P_0c03e31a;
P_0c03e318: /* original 54eb, guest PC 0x0c03e318 */
if(!s->budget--) { s->failed_pc=0x0c03e318u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c03e31a;
P_0c03e31a: /* original 52ec, guest PC 0x0c03e31a */
if(!s->budget--) { s->failed_pc=0x0c03e31au; return 0; }
r[2]=read(ram,r[14]+48,4);
goto P_0c03e31c;
P_0c03e31c: /* original 2228, guest PC 0x0c03e31c */
if(!s->budget--) { s->failed_pc=0x0c03e31cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e31e;
P_0c03e31e: /* original 8907, guest PC 0x0c03e31e */
if(!s->budget--) { s->failed_pc=0x0c03e31eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e330; }
goto P_0c03e320;
P_0c03e320: /* original 64c3, guest PC 0x0c03e320 */
if(!s->budget--) { s->failed_pc=0x0c03e320u; return 0; }
r[4]=r[12];
goto P_0c03e322;
P_0c03e322: /* original 65d3, guest PC 0x0c03e322 */
if(!s->budget--) { s->failed_pc=0x0c03e322u; return 0; }
r[5]=r[13];
goto P_0c03e324;
P_0c03e324: /* original afeb, guest PC 0x0c03e324 */
if(!s->budget--) { s->failed_pc=0x0c03e324u; return 0; }
r[14]=read(ram,r[14]+48,4);
goto P_0c03e2fe;
P_0c03e326: /* original 5eec, guest PC 0x0c03e326 */
if(!s->budget--) { s->failed_pc=0x0c03e326u; return 0; }
r[14]=read(ram,r[14]+48,4);
if(!vf3_matrix_family(0x0c03e328u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e328u; return 0; } return 1;
P_0c03e330: /* original 4f26, guest PC 0x0c03e330 */
if(!s->budget--) { s->failed_pc=0x0c03e330u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e332;
P_0c03e332: /* original 6cf6, guest PC 0x0c03e332 */
if(!s->budget--) { s->failed_pc=0x0c03e332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e334;
P_0c03e334: /* original 6df6, guest PC 0x0c03e334 */
if(!s->budget--) { s->failed_pc=0x0c03e334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e336;
P_0c03e336: /* original 000b, guest PC 0x0c03e336 */
if(!s->budget--) { s->failed_pc=0x0c03e336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03e338: /* original 6ef6, guest PC 0x0c03e338 */
if(!s->budget--) { s->failed_pc=0x0c03e338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e33au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
