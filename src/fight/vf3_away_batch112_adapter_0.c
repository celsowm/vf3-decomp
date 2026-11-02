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
int vf3_away_batch112_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c03ba40u: goto P_0c03ba40;
case 0x0c03ba42u: goto P_0c03ba42;
case 0x0c03ba44u: goto P_0c03ba44;
case 0x0c03ba46u: goto P_0c03ba46;
case 0x0c03ba48u: goto P_0c03ba48;
case 0x0c03ba4au: goto P_0c03ba4a;
case 0x0c03ba4cu: goto P_0c03ba4c;
case 0x0c03ba70u: goto P_0c03ba70;
case 0x0c03ba72u: goto P_0c03ba72;
case 0x0c03ba74u: goto P_0c03ba74;
case 0x0c03ba76u: goto P_0c03ba76;
case 0x0c03ba78u: goto P_0c03ba78;
case 0x0c03ba7au: goto P_0c03ba7a;
case 0x0c03ba7cu: goto P_0c03ba7c;
case 0x0c03ba7eu: goto P_0c03ba7e;
case 0x0c03ba80u: goto P_0c03ba80;
case 0x0c03ba82u: goto P_0c03ba82;
case 0x0c03ba84u: goto P_0c03ba84;
case 0x0c03ba86u: goto P_0c03ba86;
case 0x0c03ba88u: goto P_0c03ba88;
case 0x0c03ba8au: goto P_0c03ba8a;
case 0x0c03ba8cu: goto P_0c03ba8c;
case 0x0c03ba8eu: goto P_0c03ba8e;
case 0x0c094368u: goto P_0c094368;
case 0x0c09436au: goto P_0c09436a;
case 0x0c09436cu: goto P_0c09436c;
case 0x0c09436eu: goto P_0c09436e;
case 0x0c094370u: goto P_0c094370;
case 0x0c094372u: goto P_0c094372;
case 0x0c094374u: goto P_0c094374;
case 0x0c094376u: goto P_0c094376;
case 0x0c094378u: goto P_0c094378;
case 0x0c09437au: goto P_0c09437a;
case 0x0c09437cu: goto P_0c09437c;
case 0x0c09437eu: goto P_0c09437e;
case 0x0c094380u: goto P_0c094380;
case 0x0c094382u: goto P_0c094382;
case 0x0c094384u: goto P_0c094384;
case 0x0c094386u: goto P_0c094386;
case 0x0c094388u: goto P_0c094388;
case 0x0c09438au: goto P_0c09438a;
case 0x0c09438cu: goto P_0c09438c;
case 0x0c09438eu: goto P_0c09438e;
case 0x0c094390u: goto P_0c094390;
case 0x0c094392u: goto P_0c094392;
case 0x0c094394u: goto P_0c094394;
case 0x0c094396u: goto P_0c094396;
case 0x0c094398u: goto P_0c094398;
case 0x0c09439au: goto P_0c09439a;
case 0x0c09439cu: goto P_0c09439c;
case 0x0c09439eu: goto P_0c09439e;
case 0x0c0943a0u: goto P_0c0943a0;
case 0x0c0943a2u: goto P_0c0943a2;
case 0x0c0943a4u: goto P_0c0943a4;
case 0x0c0943a6u: goto P_0c0943a6;
case 0x0c0943a8u: goto P_0c0943a8;
case 0x0c0943aau: goto P_0c0943aa;
case 0x0c0943acu: goto P_0c0943ac;
case 0x0c0943aeu: goto P_0c0943ae;
case 0x0c0943b0u: goto P_0c0943b0;
case 0x0c0943b2u: goto P_0c0943b2;
case 0x0c0943b4u: goto P_0c0943b4;
case 0x0c0943b6u: goto P_0c0943b6;
case 0x0c0943b8u: goto P_0c0943b8;
case 0x0c0943bau: goto P_0c0943ba;
case 0x0c0943f8u: goto P_0c0943f8;
case 0x0c0943fau: goto P_0c0943fa;
case 0x0c0943fcu: goto P_0c0943fc;
case 0x0c0943feu: goto P_0c0943fe;
case 0x0c094400u: goto P_0c094400;
case 0x0c094402u: goto P_0c094402;
case 0x0c094404u: goto P_0c094404;
case 0x0c094406u: goto P_0c094406;
case 0x0c094408u: goto P_0c094408;
case 0x0c09440au: goto P_0c09440a;
case 0x0c09440cu: goto P_0c09440c;
case 0x0c09440eu: goto P_0c09440e;
case 0x0c094410u: goto P_0c094410;
case 0x0c094412u: goto P_0c094412;
case 0x0c094414u: goto P_0c094414;
case 0x0c094416u: goto P_0c094416;
case 0x0c094418u: goto P_0c094418;
case 0x0c09441au: goto P_0c09441a;
case 0x0c094420u: goto P_0c094420;
case 0x0c094422u: goto P_0c094422;
case 0x0c094424u: goto P_0c094424;
case 0x0c094426u: goto P_0c094426;
case 0x0c094428u: goto P_0c094428;
case 0x0c09442au: goto P_0c09442a;
case 0x0c09442cu: goto P_0c09442c;
case 0x0c09442eu: goto P_0c09442e;
case 0x0c094430u: goto P_0c094430;
case 0x0c094432u: goto P_0c094432;
case 0x0c094434u: goto P_0c094434;
case 0x0c094436u: goto P_0c094436;
case 0x0c094438u: goto P_0c094438;
case 0x0c09443au: goto P_0c09443a;
case 0x0c09443cu: goto P_0c09443c;
case 0x0c09443eu: goto P_0c09443e;
case 0x0c094440u: goto P_0c094440;
case 0x0c094442u: goto P_0c094442;
case 0x0c094444u: goto P_0c094444;
case 0x0c094446u: goto P_0c094446;
case 0x0c094448u: goto P_0c094448;
case 0x0c09444au: goto P_0c09444a;
case 0x0c09444cu: goto P_0c09444c;
case 0x0c09444eu: goto P_0c09444e;
case 0x0c094450u: goto P_0c094450;
case 0x0c094452u: goto P_0c094452;
case 0x0c094454u: goto P_0c094454;
case 0x0c094456u: goto P_0c094456;
case 0x0c094458u: goto P_0c094458;
case 0x0c09445au: goto P_0c09445a;
case 0x0c09445cu: goto P_0c09445c;
case 0x0c09445eu: goto P_0c09445e;
case 0x0c094460u: goto P_0c094460;
case 0x0c094462u: goto P_0c094462;
case 0x0c094464u: goto P_0c094464;
case 0x0c094466u: goto P_0c094466;
case 0x0c094468u: goto P_0c094468;
case 0x0c094470u: goto P_0c094470;
case 0x0c094472u: goto P_0c094472;
case 0x0c094474u: goto P_0c094474;
case 0x0c094476u: goto P_0c094476;
case 0x0c094478u: goto P_0c094478;
case 0x0c09447au: goto P_0c09447a;
case 0x0c09447cu: goto P_0c09447c;
case 0x0c09447eu: goto P_0c09447e;
case 0x0c094480u: goto P_0c094480;
case 0x0c094482u: goto P_0c094482;
case 0x0c094484u: goto P_0c094484;
case 0x0c094486u: goto P_0c094486;
case 0x0c094488u: goto P_0c094488;
case 0x0c09448au: goto P_0c09448a;
case 0x0c09448cu: goto P_0c09448c;
case 0x0c09448eu: goto P_0c09448e;
case 0x0c094490u: goto P_0c094490;
case 0x0c094492u: goto P_0c094492;
case 0x0c094494u: goto P_0c094494;
case 0x0c094496u: goto P_0c094496;
case 0x0c094498u: goto P_0c094498;
case 0x0c09449au: goto P_0c09449a;
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
P_0c03ba40: /* original 2448, guest PC 0x0c03ba40 */
if(!s->budget--) { s->failed_pc=0x0c03ba40u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03ba42;
P_0c03ba42: /* original 8b02, guest PC 0x0c03ba42 */
if(!s->budget--) { s->failed_pc=0x0c03ba42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ba4a; }
goto P_0c03ba44;
P_0c03ba44: /* original d306, guest PC 0x0c03ba44 */
if(!s->budget--) { s->failed_pc=0x0c03ba44u; return 0; }
r[3]=read(ram,0x0c03ba60u,4);
goto P_0c03ba46;
P_0c03ba46: /* original 432b, guest PC 0x0c03ba46 */
if(!s->budget--) { s->failed_pc=0x0c03ba46u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03ba8cu: goto P_0c03ba8c;
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
P_0c03ba48: /* original 0009, guest PC 0x0c03ba48 */
if(!s->budget--) { s->failed_pc=0x0c03ba48u; return 0; }
goto P_0c03ba4a;
P_0c03ba4a: /* original a011, guest PC 0x0c03ba4a */
if(!s->budget--) { s->failed_pc=0x0c03ba4au; return 0; }
goto P_0c03ba70;
P_0c03ba4c: /* original 0009, guest PC 0x0c03ba4c */
if(!s->budget--) { s->failed_pc=0x0c03ba4cu; return 0; }
if(!vf3_matrix_family(0x0c03ba4eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ba4eu; return 0; } return 1;
P_0c03ba70: /* original fbfd, guest PC 0x0c03ba70 */
if(!s->budget--) { s->failed_pc=0x0c03ba70u; return 0; }
vf3_matrix_swap(s);
goto P_0c03ba72;
P_0c03ba72: /* original f049, guest PC 0x0c03ba72 */
if(!s->budget--) { s->failed_pc=0x0c03ba72u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba74;
P_0c03ba74: /* original f149, guest PC 0x0c03ba74 */
if(!s->budget--) { s->failed_pc=0x0c03ba74u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba76;
P_0c03ba76: /* original f249, guest PC 0x0c03ba76 */
if(!s->budget--) { s->failed_pc=0x0c03ba76u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba78;
P_0c03ba78: /* original f449, guest PC 0x0c03ba78 */
if(!s->budget--) { s->failed_pc=0x0c03ba78u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba7a;
P_0c03ba7a: /* original f549, guest PC 0x0c03ba7a */
if(!s->budget--) { s->failed_pc=0x0c03ba7au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba7c;
P_0c03ba7c: /* original f649, guest PC 0x0c03ba7c */
if(!s->budget--) { s->failed_pc=0x0c03ba7cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba7e;
P_0c03ba7e: /* original f849, guest PC 0x0c03ba7e */
if(!s->budget--) { s->failed_pc=0x0c03ba7eu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba80;
P_0c03ba80: /* original f949, guest PC 0x0c03ba80 */
if(!s->budget--) { s->failed_pc=0x0c03ba80u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba82;
P_0c03ba82: /* original fa49, guest PC 0x0c03ba82 */
if(!s->budget--) { s->failed_pc=0x0c03ba82u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba84;
P_0c03ba84: /* original f38d, guest PC 0x0c03ba84 */
if(!s->budget--) { s->failed_pc=0x0c03ba84u; return 0; }
fr[3]=0;
goto P_0c03ba86;
P_0c03ba86: /* original f78d, guest PC 0x0c03ba86 */
if(!s->budget--) { s->failed_pc=0x0c03ba86u; return 0; }
fr[7]=0;
goto P_0c03ba88;
P_0c03ba88: /* original fb8d, guest PC 0x0c03ba88 */
if(!s->budget--) { s->failed_pc=0x0c03ba88u; return 0; }
fr[11]=0;
goto P_0c03ba8a;
P_0c03ba8a: /* original fbfd, guest PC 0x0c03ba8a */
if(!s->budget--) { s->failed_pc=0x0c03ba8au; return 0; }
vf3_matrix_swap(s);
goto P_0c03ba8c;
P_0c03ba8c: /* original 000b, guest PC 0x0c03ba8c */
if(!s->budget--) { s->failed_pc=0x0c03ba8cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03ba8e: /* original 0009, guest PC 0x0c03ba8e */
if(!s->budget--) { s->failed_pc=0x0c03ba8eu; return 0; }
if(!vf3_matrix_family(0x0c03ba90u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ba90u; return 0; } return 1;
P_0c094368: /* original 2fe6, guest PC 0x0c094368 */
if(!s->budget--) { s->failed_pc=0x0c094368u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09436a;
P_0c09436a: /* original 2fd6, guest PC 0x0c09436a */
if(!s->budget--) { s->failed_pc=0x0c09436au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09436c;
P_0c09436c: /* original 2fc6, guest PC 0x0c09436c */
if(!s->budget--) { s->failed_pc=0x0c09436cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09436e;
P_0c09436e: /* original 2fb6, guest PC 0x0c09436e */
if(!s->budget--) { s->failed_pc=0x0c09436eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094370;
P_0c094370: /* original fffb, guest PC 0x0c094370 */
if(!s->budget--) { s->failed_pc=0x0c094370u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c094372;
P_0c094372: /* original 4f22, guest PC 0x0c094372 */
if(!s->budget--) { s->failed_pc=0x0c094372u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094374;
P_0c094374: /* original 7fd8, guest PC 0x0c094374 */
if(!s->budget--) { s->failed_pc=0x0c094374u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c094376;
P_0c094376: /* original 2f42, guest PC 0x0c094376 */
if(!s->budget--) { s->failed_pc=0x0c094376u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c094378;
P_0c094378: /* original 1f51, guest PC 0x0c094378 */
if(!s->budget--) { s->failed_pc=0x0c094378u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09437a;
P_0c09437a: /* original d41a, guest PC 0x0c09437a */
if(!s->budget--) { s->failed_pc=0x0c09437au; return 0; }
r[4]=read(ram,0x0c0943e4u,4);
goto P_0c09437c;
P_0c09437c: /* original 901e, guest PC 0x0c09437c */
if(!s->budget--) { s->failed_pc=0x0c09437cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0943bcu,2);
goto P_0c09437e;
P_0c09437e: /* original dd18, guest PC 0x0c09437e */
if(!s->budget--) { s->failed_pc=0x0c09437eu; return 0; }
r[13]=read(ram,0x0c0943e0u,4);
goto P_0c094380;
P_0c094380: /* original 034e, guest PC 0x0c094380 */
if(!s->budget--) { s->failed_pc=0x0c094380u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c094382;
P_0c094382: /* original 2338, guest PC 0x0c094382 */
if(!s->budget--) { s->failed_pc=0x0c094382u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c094384;
P_0c094384: /* original 8900, guest PC 0x0c094384 */
if(!s->budget--) { s->failed_pc=0x0c094384u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094388; }
goto P_0c094386;
P_0c094386: /* original dd18, guest PC 0x0c094386 */
if(!s->budget--) { s->failed_pc=0x0c094386u; return 0; }
r[13]=read(ram,0x0c0943e8u,4);
goto P_0c094388;
P_0c094388: /* original c718, guest PC 0x0c094388 */
if(!s->budget--) { s->failed_pc=0x0c094388u; return 0; }
r[0]=code_base|0x000943ecu;
goto P_0c09438a;
P_0c09438a: /* original ff08, guest PC 0x0c09438a */
if(!s->budget--) { s->failed_pc=0x0c09438au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09438c;
P_0c09438c: /* original 6cd1, guest PC 0x0c09438c */
if(!s->budget--) { s->failed_pc=0x0c09438cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
goto P_0c09438e;
P_0c09438e: /* original 2cc8, guest PC 0x0c09438e */
if(!s->budget--) { s->failed_pc=0x0c09438eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c094390;
P_0c094390: /* original 8b02, guest PC 0x0c094390 */
if(!s->budget--) { s->failed_pc=0x0c094390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094398; }
goto P_0c094392;
P_0c094392: /* original d317, guest PC 0x0c094392 */
if(!s->budget--) { s->failed_pc=0x0c094392u; return 0; }
r[3]=read(ram,0x0c0943f0u,4);
goto P_0c094394;
P_0c094394: /* original 432b, guest PC 0x0c094394 */
if(!s->budget--) { s->failed_pc=0x0c094394u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09448cu: goto P_0c09448c;
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
P_0c094396: /* original 0009, guest PC 0x0c094396 */
if(!s->budget--) { s->failed_pc=0x0c094396u; return 0; }
goto P_0c094398;
P_0c094398: /* original 85d1, guest PC 0x0c094398 */
if(!s->budget--) { s->failed_pc=0x0c094398u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c09439a;
P_0c09439a: /* original 5ef1, guest PC 0x0c09439a */
if(!s->budget--) { s->failed_pc=0x0c09439au; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c09439c;
P_0c09439c: /* original 6403, guest PC 0x0c09439c */
if(!s->budget--) { s->failed_pc=0x0c09439cu; return 0; }
r[4]=r[0];
goto P_0c09439e;
P_0c09439e: /* original 3e4c, guest PC 0x0c09439e */
if(!s->budget--) { s->failed_pc=0x0c09439eu; return 0; }
r[14]+=r[4];
goto P_0c0943a0;
P_0c0943a0: /* original 0e83, guest PC 0x0c0943a0 */
if(!s->budget--) { s->failed_pc=0x0c0943a0u; return 0; }
if((r[14]&0xFC000000u)==0xE0000000u) pref(ram,r[14]);
goto P_0c0943a2;
P_0c0943a2: /* original 53d1, guest PC 0x0c0943a2 */
if(!s->budget--) { s->failed_pc=0x0c0943a2u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0943a4;
P_0c0943a4: /* original 1f32, guest PC 0x0c0943a4 */
if(!s->budget--) { s->failed_pc=0x0c0943a4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0943a6;
P_0c0943a6: /* original 52d2, guest PC 0x0c0943a6 */
if(!s->budget--) { s->failed_pc=0x0c0943a6u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0943a8;
P_0c0943a8: /* original 1f23, guest PC 0x0c0943a8 */
if(!s->budget--) { s->failed_pc=0x0c0943a8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0943aa;
P_0c0943aa: /* original d312, guest PC 0x0c0943aa */
if(!s->budget--) { s->failed_pc=0x0c0943aau; return 0; }
r[3]=read(ram,0x0c0943f4u,4);
goto P_0c0943ac;
P_0c0943ac: /* original 430b, guest PC 0x0c0943ac */
if(!s->budget--) { s->failed_pc=0x0c0943acu; return 0; }
target=r[3];
r[16]=code_base|0x0c0943b0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0943b0u) { target=s->pc; goto dispatch; }
goto P_0c0943b0;
P_0c0943ae: /* original 64f2, guest PC 0x0c0943ae */
if(!s->budget--) { s->failed_pc=0x0c0943aeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0943b0;
P_0c0943b0: /* original 64d3, guest PC 0x0c0943b0 */
if(!s->budget--) { s->failed_pc=0x0c0943b0u; return 0; }
r[4]=r[13];
goto P_0c0943b2;
P_0c0943b2: /* original 65f3, guest PC 0x0c0943b2 */
if(!s->budget--) { s->failed_pc=0x0c0943b2u; return 0; }
r[5]=r[15];
goto P_0c0943b4;
P_0c0943b4: /* original 740c, guest PC 0x0c0943b4 */
if(!s->budget--) { s->failed_pc=0x0c0943b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0943b6;
P_0c0943b6: /* original 751c, guest PC 0x0c0943b6 */
if(!s->budget--) { s->failed_pc=0x0c0943b6u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0943b8;
P_0c0943b8: /* original a01e, guest PC 0x0c0943b8 */
if(!s->budget--) { s->failed_pc=0x0c0943b8u; return 0; }
goto P_0c0943f8;
P_0c0943ba: /* original 0009, guest PC 0x0c0943ba */
if(!s->budget--) { s->failed_pc=0x0c0943bau; return 0; }
if(!vf3_matrix_family(0x0c0943bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0943bcu; return 0; } return 1;
P_0c0943f8: /* original f449, guest PC 0x0c0943f8 */
if(!s->budget--) { s->failed_pc=0x0c0943f8u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0943fa;
P_0c0943fa: /* original f549, guest PC 0x0c0943fa */
if(!s->budget--) { s->failed_pc=0x0c0943fau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0943fc;
P_0c0943fc: /* original f648, guest PC 0x0c0943fc */
if(!s->budget--) { s->failed_pc=0x0c0943fcu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0943fe;
P_0c0943fe: /* original f79d, guest PC 0x0c0943fe */
if(!s->budget--) { s->failed_pc=0x0c0943feu; return 0; }
fr[7]=0x3f800000u;
goto P_0c094400;
P_0c094400: /* original f5fd, guest PC 0x0c094400 */
if(!s->budget--) { s->failed_pc=0x0c094400u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c094402;
P_0c094402: /* original 750c, guest PC 0x0c094402 */
if(!s->budget--) { s->failed_pc=0x0c094402u; return 0; }
r[5]+=0x0000000cu;
goto P_0c094404;
P_0c094404: /* original f56b, guest PC 0x0c094404 */
if(!s->budget--) { s->failed_pc=0x0c094404u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c094406;
P_0c094406: /* original f55b, guest PC 0x0c094406 */
if(!s->budget--) { s->failed_pc=0x0c094406u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c094408;
P_0c094408: /* original f54b, guest PC 0x0c094408 */
if(!s->budget--) { s->failed_pc=0x0c094408u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09440a;
P_0c09440a: /* original 0009, guest PC 0x0c09440a */
if(!s->budget--) { s->failed_pc=0x0c09440au; return 0; }
goto P_0c09440c;
P_0c09440c: /* original 7d18, guest PC 0x0c09440c */
if(!s->budget--) { s->failed_pc=0x0c09440cu; return 0; }
r[13]+=0x00000018u;
goto P_0c09440e;
P_0c09440e: /* original d303, guest PC 0x0c09440e */
if(!s->budget--) { s->failed_pc=0x0c09440eu; return 0; }
r[3]=read(ram,0x0c09441cu,4);
goto P_0c094410;
P_0c094410: /* original 430b, guest PC 0x0c094410 */
if(!s->budget--) { s->failed_pc=0x0c094410u; return 0; }
target=r[3];
r[16]=code_base|0x0c094414u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094414u) { target=s->pc; goto dispatch; }
goto P_0c094414;
P_0c094412: /* original 64e3, guest PC 0x0c094412 */
if(!s->budget--) { s->failed_pc=0x0c094412u; return 0; }
r[4]=r[14];
goto P_0c094414;
P_0c094414: /* original 64f3, guest PC 0x0c094414 */
if(!s->budget--) { s->failed_pc=0x0c094414u; return 0; }
r[4]=r[15];
goto P_0c094416;
P_0c094416: /* original 741c, guest PC 0x0c094416 */
if(!s->budget--) { s->failed_pc=0x0c094416u; return 0; }
r[4]+=0x0000001cu;
goto P_0c094418;
P_0c094418: /* original a002, guest PC 0x0c094418 */
if(!s->budget--) { s->failed_pc=0x0c094418u; return 0; }
goto P_0c094420;
P_0c09441a: /* original 0009, guest PC 0x0c09441a */
if(!s->budget--) { s->failed_pc=0x0c09441au; return 0; }
if(!vf3_matrix_family(0x0c09441cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09441cu; return 0; } return 1;
P_0c094420: /* original fbfd, guest PC 0x0c094420 */
if(!s->budget--) { s->failed_pc=0x0c094420u; return 0; }
vf3_matrix_swap(s);
goto P_0c094422;
P_0c094422: /* original fc49, guest PC 0x0c094422 */
if(!s->budget--) { s->failed_pc=0x0c094422u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094424;
P_0c094424: /* original fd49, guest PC 0x0c094424 */
if(!s->budget--) { s->failed_pc=0x0c094424u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094426;
P_0c094426: /* original fe49, guest PC 0x0c094426 */
if(!s->budget--) { s->failed_pc=0x0c094426u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094428;
P_0c094428: /* original fbfd, guest PC 0x0c094428 */
if(!s->budget--) { s->failed_pc=0x0c094428u; return 0; }
vf3_matrix_swap(s);
goto P_0c09442a;
P_0c09442a: /* original 0009, guest PC 0x0c09442a */
if(!s->budget--) { s->failed_pc=0x0c09442au; return 0; }
goto P_0c09442c;
P_0c09442c: /* original 4c10, guest PC 0x0c09442c */
if(!s->budget--) { s->failed_pc=0x0c09442cu; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c09442e;
P_0c09442e: /* original 8d15, guest PC 0x0c09442e */
if(!s->budget--) { s->failed_pc=0x0c09442eu; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[15]+12,4);
if(cond) { goto P_0c09445c; }
goto P_0c094432;
P_0c094430: /* original 5bf3, guest PC 0x0c094430 */
if(!s->budget--) { s->failed_pc=0x0c094430u; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c094432;
P_0c094432: /* original e01c, guest PC 0x0c094432 */
if(!s->budget--) { s->failed_pc=0x0c094432u; return 0; }
r[0]=0x0000001cu;
goto P_0c094434;
P_0c094434: /* original f2e9, guest PC 0x0c094434 */
if(!s->budget--) { s->failed_pc=0x0c094434u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094436;
P_0c094436: /* original f3f6, guest PC 0x0c094436 */
if(!s->budget--) { s->failed_pc=0x0c094436u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094438;
P_0c094438: /* original e01c, guest PC 0x0c094438 */
if(!s->budget--) { s->failed_pc=0x0c094438u; return 0; }
r[0]=0x0000001cu;
goto P_0c09443a;
P_0c09443a: /* original f0fc, guest PC 0x0c09443a */
if(!s->budget--) { s->failed_pc=0x0c09443au; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c09443c;
P_0c09443c: /* original f32e, guest PC 0x0c09443c */
if(!s->budget--) { s->failed_pc=0x0c09443cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09443e;
P_0c09443e: /* original 5bf2, guest PC 0x0c09443e */
if(!s->budget--) { s->failed_pc=0x0c09443eu; return 0; }
r[11]=read(ram,r[15]+8,4);
goto P_0c094440;
P_0c094440: /* original ff37, guest PC 0x0c094440 */
if(!s->budget--) { s->failed_pc=0x0c094440u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c094442;
P_0c094442: /* original e020, guest PC 0x0c094442 */
if(!s->budget--) { s->failed_pc=0x0c094442u; return 0; }
r[0]=0x00000020u;
goto P_0c094444;
P_0c094444: /* original f2e9, guest PC 0x0c094444 */
if(!s->budget--) { s->failed_pc=0x0c094444u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094446;
P_0c094446: /* original f3f6, guest PC 0x0c094446 */
if(!s->budget--) { s->failed_pc=0x0c094446u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094448;
P_0c094448: /* original e020, guest PC 0x0c094448 */
if(!s->budget--) { s->failed_pc=0x0c094448u; return 0; }
r[0]=0x00000020u;
goto P_0c09444a;
P_0c09444a: /* original f32e, guest PC 0x0c09444a */
if(!s->budget--) { s->failed_pc=0x0c09444au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09444c;
P_0c09444c: /* original ff37, guest PC 0x0c09444c */
if(!s->budget--) { s->failed_pc=0x0c09444cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09444e;
P_0c09444e: /* original e024, guest PC 0x0c09444e */
if(!s->budget--) { s->failed_pc=0x0c09444eu; return 0; }
r[0]=0x00000024u;
goto P_0c094450;
P_0c094450: /* original f2e9, guest PC 0x0c094450 */
if(!s->budget--) { s->failed_pc=0x0c094450u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094452;
P_0c094452: /* original f3f6, guest PC 0x0c094452 */
if(!s->budget--) { s->failed_pc=0x0c094452u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094454;
P_0c094454: /* original e024, guest PC 0x0c094454 */
if(!s->budget--) { s->failed_pc=0x0c094454u; return 0; }
r[0]=0x00000024u;
goto P_0c094456;
P_0c094456: /* original 7e18, guest PC 0x0c094456 */
if(!s->budget--) { s->failed_pc=0x0c094456u; return 0; }
r[14]+=0x00000018u;
goto P_0c094458;
P_0c094458: /* original f32e, guest PC 0x0c094458 */
if(!s->budget--) { s->failed_pc=0x0c094458u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09445a;
P_0c09445a: /* original ff37, guest PC 0x0c09445a */
if(!s->budget--) { s->failed_pc=0x0c09445au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09445c;
P_0c09445c: /* original d303, guest PC 0x0c09445c */
if(!s->budget--) { s->failed_pc=0x0c09445cu; return 0; }
r[3]=read(ram,0x0c09446cu,4);
goto P_0c09445e;
P_0c09445e: /* original 430b, guest PC 0x0c09445e */
if(!s->budget--) { s->failed_pc=0x0c09445eu; return 0; }
target=r[3];
r[16]=code_base|0x0c094462u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094462u) { target=s->pc; goto dispatch; }
goto P_0c094462;
P_0c094460: /* original 64b3, guest PC 0x0c094460 */
if(!s->budget--) { s->failed_pc=0x0c094460u; return 0; }
r[4]=r[11];
goto P_0c094462;
P_0c094462: /* original 64f3, guest PC 0x0c094462 */
if(!s->budget--) { s->failed_pc=0x0c094462u; return 0; }
r[4]=r[15];
goto P_0c094464;
P_0c094464: /* original 741c, guest PC 0x0c094464 */
if(!s->budget--) { s->failed_pc=0x0c094464u; return 0; }
r[4]+=0x0000001cu;
goto P_0c094466;
P_0c094466: /* original a003, guest PC 0x0c094466 */
if(!s->budget--) { s->failed_pc=0x0c094466u; return 0; }
goto P_0c094470;
P_0c094468: /* original 0009, guest PC 0x0c094468 */
if(!s->budget--) { s->failed_pc=0x0c094468u; return 0; }
if(!vf3_matrix_family(0x0c09446au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09446au; return 0; } return 1;
P_0c094470: /* original fbfd, guest PC 0x0c094470 */
if(!s->budget--) { s->failed_pc=0x0c094470u; return 0; }
vf3_matrix_swap(s);
goto P_0c094472;
P_0c094472: /* original fc49, guest PC 0x0c094472 */
if(!s->budget--) { s->failed_pc=0x0c094472u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094474;
P_0c094474: /* original fd49, guest PC 0x0c094474 */
if(!s->budget--) { s->failed_pc=0x0c094474u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094476;
P_0c094476: /* original fe49, guest PC 0x0c094476 */
if(!s->budget--) { s->failed_pc=0x0c094476u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094478;
P_0c094478: /* original fbfd, guest PC 0x0c094478 */
if(!s->budget--) { s->failed_pc=0x0c094478u; return 0; }
vf3_matrix_swap(s);
goto P_0c09447a;
P_0c09447a: /* original 0009, guest PC 0x0c09447a */
if(!s->budget--) { s->failed_pc=0x0c09447au; return 0; }
goto P_0c09447c;
P_0c09447c: /* original 2cc8, guest PC 0x0c09447c */
if(!s->budget--) { s->failed_pc=0x0c09447cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c09447e;
P_0c09447e: /* original 8902, guest PC 0x0c09447e */
if(!s->budget--) { s->failed_pc=0x0c09447eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094486; }
goto P_0c094480;
P_0c094480: /* original d32a, guest PC 0x0c094480 */
if(!s->budget--) { s->failed_pc=0x0c094480u; return 0; }
r[3]=read(ram,0x0c09452cu,4);
goto P_0c094482;
P_0c094482: /* original 432b, guest PC 0x0c094482 */
if(!s->budget--) { s->failed_pc=0x0c094482u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09440eu: goto P_0c09440e;
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
P_0c094484: /* original 0009, guest PC 0x0c094484 */
if(!s->budget--) { s->failed_pc=0x0c094484u; return 0; }
goto P_0c094486;
P_0c094486: /* original d32a, guest PC 0x0c094486 */
if(!s->budget--) { s->failed_pc=0x0c094486u; return 0; }
r[3]=read(ram,0x0c094530u,4);
goto P_0c094488;
P_0c094488: /* original 432b, guest PC 0x0c094488 */
if(!s->budget--) { s->failed_pc=0x0c094488u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09438cu: goto P_0c09438c;
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
P_0c09448a: /* original 0009, guest PC 0x0c09448a */
if(!s->budget--) { s->failed_pc=0x0c09448au; return 0; }
goto P_0c09448c;
P_0c09448c: /* original 7f28, guest PC 0x0c09448c */
if(!s->budget--) { s->failed_pc=0x0c09448cu; return 0; }
r[15]+=0x00000028u;
goto P_0c09448e;
P_0c09448e: /* original 4f26, guest PC 0x0c09448e */
if(!s->budget--) { s->failed_pc=0x0c09448eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094490;
P_0c094490: /* original fff9, guest PC 0x0c094490 */
if(!s->budget--) { s->failed_pc=0x0c094490u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c094492;
P_0c094492: /* original 6bf6, guest PC 0x0c094492 */
if(!s->budget--) { s->failed_pc=0x0c094492u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094494;
P_0c094494: /* original 6cf6, guest PC 0x0c094494 */
if(!s->budget--) { s->failed_pc=0x0c094494u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094496;
P_0c094496: /* original 6df6, guest PC 0x0c094496 */
if(!s->budget--) { s->failed_pc=0x0c094496u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094498;
P_0c094498: /* original 000b, guest PC 0x0c094498 */
if(!s->budget--) { s->failed_pc=0x0c094498u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09449a: /* original 6ef6, guest PC 0x0c09449a */
if(!s->budget--) { s->failed_pc=0x0c09449au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09449cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09449cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
