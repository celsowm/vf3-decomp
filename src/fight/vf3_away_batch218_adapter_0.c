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
int vf3_away_batch218_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0af37cu: goto P_0c0af37c;
case 0x0c0af37eu: goto P_0c0af37e;
case 0x0c0af380u: goto P_0c0af380;
case 0x0c0af382u: goto P_0c0af382;
case 0x0c0af384u: goto P_0c0af384;
case 0x0c0af386u: goto P_0c0af386;
case 0x0c0af388u: goto P_0c0af388;
case 0x0c0af38au: goto P_0c0af38a;
case 0x0c0af38cu: goto P_0c0af38c;
case 0x0c0af38eu: goto P_0c0af38e;
case 0x0c0af390u: goto P_0c0af390;
case 0x0c0af392u: goto P_0c0af392;
case 0x0c0af394u: goto P_0c0af394;
case 0x0c0af396u: goto P_0c0af396;
case 0x0c0af398u: goto P_0c0af398;
case 0x0c0af39au: goto P_0c0af39a;
case 0x0c0af39cu: goto P_0c0af39c;
case 0x0c0af39eu: goto P_0c0af39e;
case 0x0c0af3a0u: goto P_0c0af3a0;
case 0x0c0af3a2u: goto P_0c0af3a2;
case 0x0c0af3a4u: goto P_0c0af3a4;
case 0x0c0af3a6u: goto P_0c0af3a6;
case 0x0c0af3a8u: goto P_0c0af3a8;
case 0x0c0af3aau: goto P_0c0af3aa;
case 0x0c0af3acu: goto P_0c0af3ac;
case 0x0c0af3aeu: goto P_0c0af3ae;
case 0x0c0af3b0u: goto P_0c0af3b0;
case 0x0c0af3b2u: goto P_0c0af3b2;
case 0x0c0af3b4u: goto P_0c0af3b4;
case 0x0c0af3b6u: goto P_0c0af3b6;
case 0x0c0af3b8u: goto P_0c0af3b8;
case 0x0c0af3bau: goto P_0c0af3ba;
case 0x0c0af3bcu: goto P_0c0af3bc;
case 0x0c0af3beu: goto P_0c0af3be;
case 0x0c0af3c0u: goto P_0c0af3c0;
case 0x0c0af3c2u: goto P_0c0af3c2;
case 0x0c0af3c4u: goto P_0c0af3c4;
case 0x0c0af3c6u: goto P_0c0af3c6;
case 0x0c0af3c8u: goto P_0c0af3c8;
case 0x0c0af3cau: goto P_0c0af3ca;
case 0x0c0af3ccu: goto P_0c0af3cc;
case 0x0c0af3ceu: goto P_0c0af3ce;
case 0x0c0af3d0u: goto P_0c0af3d0;
case 0x0c0af3d2u: goto P_0c0af3d2;
case 0x0c0af3d4u: goto P_0c0af3d4;
case 0x0c0af3d6u: goto P_0c0af3d6;
case 0x0c0af3d8u: goto P_0c0af3d8;
case 0x0c0af3dau: goto P_0c0af3da;
case 0x0c0af3dcu: goto P_0c0af3dc;
case 0x0c0af3deu: goto P_0c0af3de;
case 0x0c0af3e0u: goto P_0c0af3e0;
case 0x0c0af3e2u: goto P_0c0af3e2;
case 0x0c0af3e4u: goto P_0c0af3e4;
case 0x0c0af3e6u: goto P_0c0af3e6;
case 0x0c0af3e8u: goto P_0c0af3e8;
case 0x0c0af3eau: goto P_0c0af3ea;
case 0x0c0af3ecu: goto P_0c0af3ec;
case 0x0c0af3eeu: goto P_0c0af3ee;
case 0x0c0af3f0u: goto P_0c0af3f0;
case 0x0c0af3f2u: goto P_0c0af3f2;
case 0x0c0af3f4u: goto P_0c0af3f4;
case 0x0c0af3f6u: goto P_0c0af3f6;
case 0x0c0af3f8u: goto P_0c0af3f8;
case 0x0c0af3fau: goto P_0c0af3fa;
case 0x0c0af3fcu: goto P_0c0af3fc;
case 0x0c0af3feu: goto P_0c0af3fe;
case 0x0c0af400u: goto P_0c0af400;
case 0x0c0af402u: goto P_0c0af402;
case 0x0c0af404u: goto P_0c0af404;
case 0x0c0af406u: goto P_0c0af406;
case 0x0c0af408u: goto P_0c0af408;
case 0x0c0af40au: goto P_0c0af40a;
case 0x0c0af40cu: goto P_0c0af40c;
case 0x0c0af40eu: goto P_0c0af40e;
case 0x0c0af410u: goto P_0c0af410;
case 0x0c0af412u: goto P_0c0af412;
case 0x0c0af414u: goto P_0c0af414;
case 0x0c0af416u: goto P_0c0af416;
case 0x0c0af418u: goto P_0c0af418;
case 0x0c0af41au: goto P_0c0af41a;
case 0x0c0af41cu: goto P_0c0af41c;
case 0x0c0af41eu: goto P_0c0af41e;
case 0x0c0af420u: goto P_0c0af420;
case 0x0c0af422u: goto P_0c0af422;
case 0x0c0af424u: goto P_0c0af424;
case 0x0c0af426u: goto P_0c0af426;
case 0x0c0af428u: goto P_0c0af428;
case 0x0c0af42au: goto P_0c0af42a;
case 0x0c0af42cu: goto P_0c0af42c;
case 0x0c0af42eu: goto P_0c0af42e;
case 0x0c0af430u: goto P_0c0af430;
case 0x0c0af432u: goto P_0c0af432;
case 0x0c0af434u: goto P_0c0af434;
case 0x0c0af436u: goto P_0c0af436;
case 0x0c0af438u: goto P_0c0af438;
case 0x0c0af43au: goto P_0c0af43a;
case 0x0c0af43cu: goto P_0c0af43c;
case 0x0c0af43eu: goto P_0c0af43e;
case 0x0c0af440u: goto P_0c0af440;
case 0x0c0af442u: goto P_0c0af442;
case 0x0c0af444u: goto P_0c0af444;
case 0x0c0af446u: goto P_0c0af446;
case 0x0c0af554u: goto P_0c0af554;
case 0x0c0af556u: goto P_0c0af556;
case 0x0c0af558u: goto P_0c0af558;
case 0x0c0af55au: goto P_0c0af55a;
case 0x0c0af55cu: goto P_0c0af55c;
case 0x0c0af55eu: goto P_0c0af55e;
case 0x0c0af560u: goto P_0c0af560;
case 0x0c0af562u: goto P_0c0af562;
case 0x0c0af564u: goto P_0c0af564;
case 0x0c0af566u: goto P_0c0af566;
case 0x0c0af568u: goto P_0c0af568;
case 0x0c0af56au: goto P_0c0af56a;
case 0x0c0af56cu: goto P_0c0af56c;
case 0x0c0af56eu: goto P_0c0af56e;
case 0x0c0af570u: goto P_0c0af570;
case 0x0c0af572u: goto P_0c0af572;
case 0x0c0af574u: goto P_0c0af574;
case 0x0c0af576u: goto P_0c0af576;
case 0x0c0af578u: goto P_0c0af578;
case 0x0c0af57au: goto P_0c0af57a;
case 0x0c0af57cu: goto P_0c0af57c;
case 0x0c0af57eu: goto P_0c0af57e;
case 0x0c0af580u: goto P_0c0af580;
case 0x0c0af582u: goto P_0c0af582;
case 0x0c0af584u: goto P_0c0af584;
case 0x0c0af586u: goto P_0c0af586;
case 0x0c0af588u: goto P_0c0af588;
case 0x0c0af58au: goto P_0c0af58a;
case 0x0c0af58cu: goto P_0c0af58c;
case 0x0c0af58eu: goto P_0c0af58e;
case 0x0c0af590u: goto P_0c0af590;
case 0x0c0af592u: goto P_0c0af592;
case 0x0c0af594u: goto P_0c0af594;
case 0x0c0af596u: goto P_0c0af596;
case 0x0c0af598u: goto P_0c0af598;
case 0x0c0af59au: goto P_0c0af59a;
case 0x0c0af59cu: goto P_0c0af59c;
case 0x0c0af59eu: goto P_0c0af59e;
case 0x0c0af5a0u: goto P_0c0af5a0;
case 0x0c0af5a2u: goto P_0c0af5a2;
case 0x0c0af5a4u: goto P_0c0af5a4;
case 0x0c0af5a6u: goto P_0c0af5a6;
case 0x0c0af5a8u: goto P_0c0af5a8;
case 0x0c0af5aau: goto P_0c0af5aa;
case 0x0c0af5acu: goto P_0c0af5ac;
case 0x0c0af5aeu: goto P_0c0af5ae;
case 0x0c0af5b0u: goto P_0c0af5b0;
case 0x0c0af5b2u: goto P_0c0af5b2;
case 0x0c0af5b4u: goto P_0c0af5b4;
case 0x0c0af5b6u: goto P_0c0af5b6;
case 0x0c0af5b8u: goto P_0c0af5b8;
case 0x0c0af5bau: goto P_0c0af5ba;
case 0x0c0af5bcu: goto P_0c0af5bc;
case 0x0c0af5beu: goto P_0c0af5be;
case 0x0c0af5c0u: goto P_0c0af5c0;
case 0x0c0af5c2u: goto P_0c0af5c2;
case 0x0c0af5c4u: goto P_0c0af5c4;
case 0x0c0af5c6u: goto P_0c0af5c6;
case 0x0c0af5c8u: goto P_0c0af5c8;
case 0x0c0af5cau: goto P_0c0af5ca;
case 0x0c0af5ccu: goto P_0c0af5cc;
case 0x0c0af5ceu: goto P_0c0af5ce;
case 0x0c0af5d0u: goto P_0c0af5d0;
case 0x0c0af5d2u: goto P_0c0af5d2;
case 0x0c0af5d4u: goto P_0c0af5d4;
case 0x0c0af5d6u: goto P_0c0af5d6;
case 0x0c0af5d8u: goto P_0c0af5d8;
case 0x0c0af5dau: goto P_0c0af5da;
case 0x0c0af5dcu: goto P_0c0af5dc;
case 0x0c0af5deu: goto P_0c0af5de;
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
P_0c0af37c: /* original 2fe6, guest PC 0x0c0af37c */
if(!s->budget--) { s->failed_pc=0x0c0af37cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af37e;
P_0c0af37e: /* original 6e43, guest PC 0x0c0af37e */
if(!s->budget--) { s->failed_pc=0x0c0af37eu; return 0; }
r[14]=r[4];
goto P_0c0af380;
P_0c0af380: /* original 2fd6, guest PC 0x0c0af380 */
if(!s->budget--) { s->failed_pc=0x0c0af380u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af382;
P_0c0af382: /* original 2fc6, guest PC 0x0c0af382 */
if(!s->budget--) { s->failed_pc=0x0c0af382u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af384;
P_0c0af384: /* original fffb, guest PC 0x0c0af384 */
if(!s->budget--) { s->failed_pc=0x0c0af384u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0af386;
P_0c0af386: /* original ffeb, guest PC 0x0c0af386 */
if(!s->budget--) { s->failed_pc=0x0c0af386u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0af388;
P_0c0af388: /* original ffdb, guest PC 0x0c0af388 */
if(!s->budget--) { s->failed_pc=0x0c0af388u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0af38a;
P_0c0af38a: /* original ffcb, guest PC 0x0c0af38a */
if(!s->budget--) { s->failed_pc=0x0c0af38au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0af38c;
P_0c0af38c: /* original 4f22, guest PC 0x0c0af38c */
if(!s->budget--) { s->failed_pc=0x0c0af38cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af38e;
P_0c0af38e: /* original 7ff4, guest PC 0x0c0af38e */
if(!s->budget--) { s->failed_pc=0x0c0af38eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0af390;
P_0c0af390: /* original 2f52, guest PC 0x0c0af390 */
if(!s->budget--) { s->failed_pc=0x0c0af390u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0af392;
P_0c0af392: /* original d452, guest PC 0x0c0af392 */
if(!s->budget--) { s->failed_pc=0x0c0af392u; return 0; }
r[4]=read(ram,0x0c0af4dcu,4);
goto P_0c0af394;
P_0c0af394: /* original d552, guest PC 0x0c0af394 */
if(!s->budget--) { s->failed_pc=0x0c0af394u; return 0; }
r[5]=read(ram,0x0c0af4e0u,4);
goto P_0c0af396;
P_0c0af396: /* original 5341, guest PC 0x0c0af396 */
if(!s->budget--) { s->failed_pc=0x0c0af396u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0af398;
P_0c0af398: /* original 2358, guest PC 0x0c0af398 */
if(!s->budget--) { s->failed_pc=0x0c0af398u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0af39a;
P_0c0af39a: /* original 8f44, guest PC 0x0c0af39a */
if(!s->budget--) { s->failed_pc=0x0c0af39au; return 0; }
cond=r[17]&1u;
r[12]=r[6];
if(!cond) { goto P_0c0af426; }
goto P_0c0af39e;
P_0c0af39c: /* original 6c63, guest PC 0x0c0af39c */
if(!s->budget--) { s->failed_pc=0x0c0af39cu; return 0; }
r[12]=r[6];
goto P_0c0af39e;
P_0c0af39e: /* original 6242, guest PC 0x0c0af39e */
if(!s->budget--) { s->failed_pc=0x0c0af39eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0af3a0;
P_0c0af3a0: /* original 2528, guest PC 0x0c0af3a0 */
if(!s->budget--) { s->failed_pc=0x0c0af3a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0af3a2;
P_0c0af3a2: /* original 8b40, guest PC 0x0c0af3a2 */
if(!s->budget--) { s->failed_pc=0x0c0af3a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af426; }
goto P_0c0af3a4;
P_0c0af3a4: /* original 85ef, guest PC 0x0c0af3a4 */
if(!s->budget--) { s->failed_pc=0x0c0af3a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af3a6;
P_0c0af3a6: /* original 81ef, guest PC 0x0c0af3a6 */
if(!s->budget--) { s->failed_pc=0x0c0af3a6u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0af3a8;
P_0c0af3a8: /* original 6403, guest PC 0x0c0af3a8 */
if(!s->budget--) { s->failed_pc=0x0c0af3a8u; return 0; }
r[4]=r[0];
goto P_0c0af3aa;
P_0c0af3aa: /* original 6d03, guest PC 0x0c0af3aa */
if(!s->budget--) { s->failed_pc=0x0c0af3aau; return 0; }
r[13]=r[0];
goto P_0c0af3ac;
P_0c0af3ac: /* original e010, guest PC 0x0c0af3ac */
if(!s->budget--) { s->failed_pc=0x0c0af3acu; return 0; }
r[0]=0x00000010u;
goto P_0c0af3ae;
P_0c0af3ae: /* original 6343, guest PC 0x0c0af3ae */
if(!s->budget--) { s->failed_pc=0x0c0af3aeu; return 0; }
r[3]=r[4];
goto P_0c0af3b0;
P_0c0af3b0: /* original 3348, guest PC 0x0c0af3b0 */
if(!s->budget--) { s->failed_pc=0x0c0af3b0u; return 0; }
r[3]-=r[4];
goto P_0c0af3b2;
P_0c0af3b2: /* original 643d, guest PC 0x0c0af3b2 */
if(!s->budget--) { s->failed_pc=0x0c0af3b2u; return 0; }
r[4]=r[3]&65535u;
goto P_0c0af3b4;
P_0c0af3b4: /* original 1f42, guest PC 0x0c0af3b4 */
if(!s->budget--) { s->failed_pc=0x0c0af3b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0af3b6;
P_0c0af3b6: /* original f4e6, guest PC 0x0c0af3b6 */
if(!s->budget--) { s->failed_pc=0x0c0af3b6u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0af3b8;
P_0c0af3b8: /* original e018, guest PC 0x0c0af3b8 */
if(!s->budget--) { s->failed_pc=0x0c0af3b8u; return 0; }
r[0]=0x00000018u;
goto P_0c0af3ba;
P_0c0af3ba: /* original f5e6, guest PC 0x0c0af3ba */
if(!s->budget--) { s->failed_pc=0x0c0af3bau; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0af3bc;
P_0c0af3bc: /* original 908a, guest PC 0x0c0af3bc */
if(!s->budget--) { s->failed_pc=0x0c0af3bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af4d4u,2);
goto P_0c0af3be;
P_0c0af3be: /* original fde6, guest PC 0x0c0af3be */
if(!s->budget--) { s->failed_pc=0x0c0af3beu; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0af3c0;
P_0c0af3c0: /* original 7008, guest PC 0x0c0af3c0 */
if(!s->budget--) { s->failed_pc=0x0c0af3c0u; return 0; }
r[0]+=0x00000008u;
goto P_0c0af3c2;
P_0c0af3c2: /* original fce6, guest PC 0x0c0af3c2 */
if(!s->budget--) { s->failed_pc=0x0c0af3c2u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0af3c4;
P_0c0af3c4: /* original e004, guest PC 0x0c0af3c4 */
if(!s->budget--) { s->failed_pc=0x0c0af3c4u; return 0; }
r[0]=0x00000004u;
goto P_0c0af3c6;
P_0c0af3c6: /* original ffdc, guest PC 0x0c0af3c6 */
if(!s->budget--) { s->failed_pc=0x0c0af3c6u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0af3c8;
P_0c0af3c8: /* original ff41, guest PC 0x0c0af3c8 */
if(!s->budget--) { s->failed_pc=0x0c0af3c8u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c0af3ca;
P_0c0af3ca: /* original f3cc, guest PC 0x0c0af3ca */
if(!s->budget--) { s->failed_pc=0x0c0af3cau; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c0af3cc;
P_0c0af3cc: /* original f351, guest PC 0x0c0af3cc */
if(!s->budget--) { s->failed_pc=0x0c0af3ccu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c0af3ce;
P_0c0af3ce: /* original ff37, guest PC 0x0c0af3ce */
if(!s->budget--) { s->failed_pc=0x0c0af3ceu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0af3d0;
P_0c0af3d0: /* original 5df2, guest PC 0x0c0af3d0 */
if(!s->budget--) { s->failed_pc=0x0c0af3d0u; return 0; }
r[13]=read(ram,r[15]+8,4);
goto P_0c0af3d2;
P_0c0af3d2: /* original d344, guest PC 0x0c0af3d2 */
if(!s->budget--) { s->failed_pc=0x0c0af3d2u; return 0; }
r[3]=read(ram,0x0c0af4e4u,4);
goto P_0c0af3d4;
P_0c0af3d4: /* original 6ddf, guest PC 0x0c0af3d4 */
if(!s->budget--) { s->failed_pc=0x0c0af3d4u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0af3d6;
P_0c0af3d6: /* original 430b, guest PC 0x0c0af3d6 */
if(!s->budget--) { s->failed_pc=0x0c0af3d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0af3dau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af3dau) { target=s->pc; goto dispatch; }
goto P_0c0af3da;
P_0c0af3d8: /* original 64d3, guest PC 0x0c0af3d8 */
if(!s->budget--) { s->failed_pc=0x0c0af3d8u; return 0; }
r[4]=r[13];
goto P_0c0af3da;
P_0c0af3da: /* original f3fc, guest PC 0x0c0af3da */
if(!s->budget--) { s->failed_pc=0x0c0af3dau; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0af3dc;
P_0c0af3dc: /* original ff0c, guest PC 0x0c0af3dc */
if(!s->budget--) { s->failed_pc=0x0c0af3dcu; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0af3de;
P_0c0af3de: /* original ff32, guest PC 0x0c0af3de */
if(!s->budget--) { s->failed_pc=0x0c0af3deu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c0af3e0;
P_0c0af3e0: /* original d341, guest PC 0x0c0af3e0 */
if(!s->budget--) { s->failed_pc=0x0c0af3e0u; return 0; }
r[3]=read(ram,0x0c0af4e8u,4);
goto P_0c0af3e2;
P_0c0af3e2: /* original f40c, guest PC 0x0c0af3e2 */
if(!s->budget--) { s->failed_pc=0x0c0af3e2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0af3e4;
P_0c0af3e4: /* original 430b, guest PC 0x0c0af3e4 */
if(!s->budget--) { s->failed_pc=0x0c0af3e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0af3e8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af3e8u) { target=s->pc; goto dispatch; }
goto P_0c0af3e8;
P_0c0af3e6: /* original 64d3, guest PC 0x0c0af3e6 */
if(!s->budget--) { s->failed_pc=0x0c0af3e6u; return 0; }
r[4]=r[13];
goto P_0c0af3e8;
P_0c0af3e8: /* original e004, guest PC 0x0c0af3e8 */
if(!s->budget--) { s->failed_pc=0x0c0af3e8u; return 0; }
r[0]=0x00000004u;
goto P_0c0af3ea;
P_0c0af3ea: /* original f40c, guest PC 0x0c0af3ea */
if(!s->budget--) { s->failed_pc=0x0c0af3eau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0af3ec;
P_0c0af3ec: /* original f3f6, guest PC 0x0c0af3ec */
if(!s->budget--) { s->failed_pc=0x0c0af3ecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af3ee;
P_0c0af3ee: /* original f2fc, guest PC 0x0c0af3ee */
if(!s->budget--) { s->failed_pc=0x0c0af3eeu; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0af3f0;
P_0c0af3f0: /* original f432, guest PC 0x0c0af3f0 */
if(!s->budget--) { s->failed_pc=0x0c0af3f0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0af3f2;
P_0c0af3f2: /* original d33d, guest PC 0x0c0af3f2 */
if(!s->budget--) { s->failed_pc=0x0c0af3f2u; return 0; }
r[3]=read(ram,0x0c0af4e8u,4);
goto P_0c0af3f4;
P_0c0af3f4: /* original ff4c, guest PC 0x0c0af3f4 */
if(!s->budget--) { s->failed_pc=0x0c0af3f4u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0af3f6;
P_0c0af3f6: /* original ff20, guest PC 0x0c0af3f6 */
if(!s->budget--) { s->failed_pc=0x0c0af3f6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'+');
goto P_0c0af3f8;
P_0c0af3f8: /* original 430b, guest PC 0x0c0af3f8 */
if(!s->budget--) { s->failed_pc=0x0c0af3f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0af3fcu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af3fcu) { target=s->pc; goto dispatch; }
goto P_0c0af3fc;
P_0c0af3fa: /* original 64d3, guest PC 0x0c0af3fa */
if(!s->budget--) { s->failed_pc=0x0c0af3fau; return 0; }
r[4]=r[13];
goto P_0c0af3fc;
P_0c0af3fc: /* original fe0c, guest PC 0x0c0af3fc */
if(!s->budget--) { s->failed_pc=0x0c0af3fcu; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c0af3fe;
P_0c0af3fe: /* original fef2, guest PC 0x0c0af3fe */
if(!s->budget--) { s->failed_pc=0x0c0af3feu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c0af400;
P_0c0af400: /* original d238, guest PC 0x0c0af400 */
if(!s->budget--) { s->failed_pc=0x0c0af400u; return 0; }
r[2]=read(ram,0x0c0af4e4u,4);
goto P_0c0af402;
P_0c0af402: /* original f40c, guest PC 0x0c0af402 */
if(!s->budget--) { s->failed_pc=0x0c0af402u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0af404;
P_0c0af404: /* original 420b, guest PC 0x0c0af404 */
if(!s->budget--) { s->failed_pc=0x0c0af404u; return 0; }
target=r[2];
r[16]=code_base|0x0c0af408u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af408u) { target=s->pc; goto dispatch; }
goto P_0c0af408;
P_0c0af406: /* original 64d3, guest PC 0x0c0af406 */
if(!s->budget--) { s->failed_pc=0x0c0af406u; return 0; }
r[4]=r[13];
goto P_0c0af408;
P_0c0af408: /* original f40c, guest PC 0x0c0af408 */
if(!s->budget--) { s->failed_pc=0x0c0af408u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0af40a;
P_0c0af40a: /* original f4e2, guest PC 0x0c0af40a */
if(!s->budget--) { s->failed_pc=0x0c0af40au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'*');
goto P_0c0af40c;
P_0c0af40c: /* original f3ec, guest PC 0x0c0af40c */
if(!s->budget--) { s->failed_pc=0x0c0af40cu; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0af40e;
P_0c0af40e: /* original e010, guest PC 0x0c0af40e */
if(!s->budget--) { s->failed_pc=0x0c0af40eu; return 0; }
r[0]=0x00000010u;
goto P_0c0af410;
P_0c0af410: /* original fe4c, guest PC 0x0c0af410 */
if(!s->budget--) { s->failed_pc=0x0c0af410u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0af412;
P_0c0af412: /* original fe31, guest PC 0x0c0af412 */
if(!s->budget--) { s->failed_pc=0x0c0af412u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0af414;
P_0c0af414: /* original f3fc, guest PC 0x0c0af414 */
if(!s->budget--) { s->failed_pc=0x0c0af414u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0af416;
P_0c0af416: /* original ffdc, guest PC 0x0c0af416 */
if(!s->budget--) { s->failed_pc=0x0c0af416u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0af418;
P_0c0af418: /* original ff31, guest PC 0x0c0af418 */
if(!s->budget--) { s->failed_pc=0x0c0af418u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c0af41a;
P_0c0af41a: /* original f3ec, guest PC 0x0c0af41a */
if(!s->budget--) { s->failed_pc=0x0c0af41au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0af41c;
P_0c0af41c: /* original fecc, guest PC 0x0c0af41c */
if(!s->budget--) { s->failed_pc=0x0c0af41cu; return 0; }
vf3_matrix_move(s,14,12);
goto P_0c0af41e;
P_0c0af41e: /* original fe31, guest PC 0x0c0af41e */
if(!s->budget--) { s->failed_pc=0x0c0af41eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0af420;
P_0c0af420: /* original fef7, guest PC 0x0c0af420 */
if(!s->budget--) { s->failed_pc=0x0c0af420u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0af422;
P_0c0af422: /* original e018, guest PC 0x0c0af422 */
if(!s->budget--) { s->failed_pc=0x0c0af422u; return 0; }
r[0]=0x00000018u;
goto P_0c0af424;
P_0c0af424: /* original fee7, guest PC 0x0c0af424 */
if(!s->budget--) { s->failed_pc=0x0c0af424u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0af426;
P_0c0af426: /* original 53c2, guest PC 0x0c0af426 */
if(!s->budget--) { s->failed_pc=0x0c0af426u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c0af428;
P_0c0af428: /* original 66c3, guest PC 0x0c0af428 */
if(!s->budget--) { s->failed_pc=0x0c0af428u; return 0; }
r[6]=r[12];
goto P_0c0af42a;
P_0c0af42a: /* original 64e3, guest PC 0x0c0af42a */
if(!s->budget--) { s->failed_pc=0x0c0af42au; return 0; }
r[4]=r[14];
goto P_0c0af42c;
P_0c0af42c: /* original 7305, guest PC 0x0c0af42c */
if(!s->budget--) { s->failed_pc=0x0c0af42cu; return 0; }
r[3]+=0x00000005u;
goto P_0c0af42e;
P_0c0af42e: /* original 1c32, guest PC 0x0c0af42e */
if(!s->budget--) { s->failed_pc=0x0c0af42eu; return 0; }
write(ram,r[12]+8,r[3],4);
goto P_0c0af430;
P_0c0af430: /* original 65f2, guest PC 0x0c0af430 */
if(!s->budget--) { s->failed_pc=0x0c0af430u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0af432;
P_0c0af432: /* original 7f0c, guest PC 0x0c0af432 */
if(!s->budget--) { s->failed_pc=0x0c0af432u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0af434;
P_0c0af434: /* original 4f26, guest PC 0x0c0af434 */
if(!s->budget--) { s->failed_pc=0x0c0af434u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af436;
P_0c0af436: /* original d32d, guest PC 0x0c0af436 */
if(!s->budget--) { s->failed_pc=0x0c0af436u; return 0; }
r[3]=read(ram,0x0c0af4ecu,4);
goto P_0c0af438;
P_0c0af438: /* original fcf9, guest PC 0x0c0af438 */
if(!s->budget--) { s->failed_pc=0x0c0af438u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af43a;
P_0c0af43a: /* original fdf9, guest PC 0x0c0af43a */
if(!s->budget--) { s->failed_pc=0x0c0af43au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af43c;
P_0c0af43c: /* original fef9, guest PC 0x0c0af43c */
if(!s->budget--) { s->failed_pc=0x0c0af43cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af43e;
P_0c0af43e: /* original fff9, guest PC 0x0c0af43e */
if(!s->budget--) { s->failed_pc=0x0c0af43eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af440;
P_0c0af440: /* original 6cf6, guest PC 0x0c0af440 */
if(!s->budget--) { s->failed_pc=0x0c0af440u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0af442;
P_0c0af442: /* original 6df6, guest PC 0x0c0af442 */
if(!s->budget--) { s->failed_pc=0x0c0af442u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af444;
P_0c0af444: /* original 432b, guest PC 0x0c0af444 */
if(!s->budget--) { s->failed_pc=0x0c0af444u; return 0; }
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
P_0c0af446: /* original 6ef6, guest PC 0x0c0af446 */
if(!s->budget--) { s->failed_pc=0x0c0af446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af448u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af448u; return 0; } return 1;
P_0c0af554: /* original 2fe6, guest PC 0x0c0af554 */
if(!s->budget--) { s->failed_pc=0x0c0af554u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af556;
P_0c0af556: /* original 2fd6, guest PC 0x0c0af556 */
if(!s->budget--) { s->failed_pc=0x0c0af556u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af558;
P_0c0af558: /* original 5762, guest PC 0x0c0af558 */
if(!s->budget--) { s->failed_pc=0x0c0af558u; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0af55a;
P_0c0af55a: /* original 7ff4, guest PC 0x0c0af55a */
if(!s->budget--) { s->failed_pc=0x0c0af55au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0af55c;
P_0c0af55c: /* original de27, guest PC 0x0c0af55c */
if(!s->budget--) { s->failed_pc=0x0c0af55cu; return 0; }
r[14]=read(ram,0x0c0af5fcu,4);
goto P_0c0af55e;
P_0c0af55e: /* original 8474, guest PC 0x0c0af55e */
if(!s->budget--) { s->failed_pc=0x0c0af55eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+4,1);
goto P_0c0af560;
P_0c0af560: /* original 600c, guest PC 0x0c0af560 */
if(!s->budget--) { s->failed_pc=0x0c0af560u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af562;
P_0c0af562: /* original 4018, guest PC 0x0c0af562 */
if(!s->budget--) { s->failed_pc=0x0c0af562u; return 0; }
r[0]<<=8;
goto P_0c0af564;
P_0c0af564: /* original 20e9, guest PC 0x0c0af564 */
if(!s->budget--) { s->failed_pc=0x0c0af564u; return 0; }
r[0]&=r[14];
goto P_0c0af566;
P_0c0af566: /* original 6303, guest PC 0x0c0af566 */
if(!s->budget--) { s->failed_pc=0x0c0af566u; return 0; }
r[3]=r[0];
goto P_0c0af568;
P_0c0af568: /* original 8473, guest PC 0x0c0af568 */
if(!s->budget--) { s->failed_pc=0x0c0af568u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+3,1);
goto P_0c0af56a;
P_0c0af56a: /* original 600c, guest PC 0x0c0af56a */
if(!s->budget--) { s->failed_pc=0x0c0af56au; return 0; }
r[0]=r[0]&255u;
goto P_0c0af56c;
P_0c0af56c: /* original 230b, guest PC 0x0c0af56c */
if(!s->budget--) { s->failed_pc=0x0c0af56cu; return 0; }
r[3]|=r[0];
goto P_0c0af56e;
P_0c0af56e: /* original 1f31, guest PC 0x0c0af56e */
if(!s->budget--) { s->failed_pc=0x0c0af56eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0af570;
P_0c0af570: /* original 8477, guest PC 0x0c0af570 */
if(!s->budget--) { s->failed_pc=0x0c0af570u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+7,1);
goto P_0c0af572;
P_0c0af572: /* original 600c, guest PC 0x0c0af572 */
if(!s->budget--) { s->failed_pc=0x0c0af572u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af574;
P_0c0af574: /* original 4018, guest PC 0x0c0af574 */
if(!s->budget--) { s->failed_pc=0x0c0af574u; return 0; }
r[0]<<=8;
goto P_0c0af576;
P_0c0af576: /* original 6d03, guest PC 0x0c0af576 */
if(!s->budget--) { s->failed_pc=0x0c0af576u; return 0; }
r[13]=r[0];
goto P_0c0af578;
P_0c0af578: /* original 8476, guest PC 0x0c0af578 */
if(!s->budget--) { s->failed_pc=0x0c0af578u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+6,1);
goto P_0c0af57a;
P_0c0af57a: /* original 2de9, guest PC 0x0c0af57a */
if(!s->budget--) { s->failed_pc=0x0c0af57au; return 0; }
r[13]&=r[14];
goto P_0c0af57c;
P_0c0af57c: /* original 600c, guest PC 0x0c0af57c */
if(!s->budget--) { s->failed_pc=0x0c0af57cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0af57e;
P_0c0af57e: /* original 2d0b, guest PC 0x0c0af57e */
if(!s->budget--) { s->failed_pc=0x0c0af57eu; return 0; }
r[13]|=r[0];
goto P_0c0af580;
P_0c0af580: /* original 9036, guest PC 0x0c0af580 */
if(!s->budget--) { s->failed_pc=0x0c0af580u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af5f0u,2);
goto P_0c0af582;
P_0c0af582: /* original 034d, guest PC 0x0c0af582 */
if(!s->budget--) { s->failed_pc=0x0c0af582u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0af584;
P_0c0af584: /* original 1f32, guest PC 0x0c0af584 */
if(!s->budget--) { s->failed_pc=0x0c0af584u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0af586;
P_0c0af586: /* original 8479, guest PC 0x0c0af586 */
if(!s->budget--) { s->failed_pc=0x0c0af586u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+9,1);
goto P_0c0af588;
P_0c0af588: /* original 600c, guest PC 0x0c0af588 */
if(!s->budget--) { s->failed_pc=0x0c0af588u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af58a;
P_0c0af58a: /* original 4018, guest PC 0x0c0af58a */
if(!s->budget--) { s->failed_pc=0x0c0af58au; return 0; }
r[0]<<=8;
goto P_0c0af58c;
P_0c0af58c: /* original 20e9, guest PC 0x0c0af58c */
if(!s->budget--) { s->failed_pc=0x0c0af58cu; return 0; }
r[0]&=r[14];
goto P_0c0af58e;
P_0c0af58e: /* original 6e03, guest PC 0x0c0af58e */
if(!s->budget--) { s->failed_pc=0x0c0af58eu; return 0; }
r[14]=r[0];
goto P_0c0af590;
P_0c0af590: /* original 8478, guest PC 0x0c0af590 */
if(!s->budget--) { s->failed_pc=0x0c0af590u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+8,1);
goto P_0c0af592;
P_0c0af592: /* original 600c, guest PC 0x0c0af592 */
if(!s->budget--) { s->failed_pc=0x0c0af592u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af594;
P_0c0af594: /* original 2e0b, guest PC 0x0c0af594 */
if(!s->budget--) { s->failed_pc=0x0c0af594u; return 0; }
r[14]|=r[0];
goto P_0c0af596;
P_0c0af596: /* original 902c, guest PC 0x0c0af596 */
if(!s->budget--) { s->failed_pc=0x0c0af596u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af5f2u,2);
goto P_0c0af598;
P_0c0af598: /* original 034d, guest PC 0x0c0af598 */
if(!s->budget--) { s->failed_pc=0x0c0af598u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0af59a;
P_0c0af59a: /* original 2f32, guest PC 0x0c0af59a */
if(!s->budget--) { s->failed_pc=0x0c0af59au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0af59c;
P_0c0af59c: /* original 8475, guest PC 0x0c0af59c */
if(!s->budget--) { s->failed_pc=0x0c0af59cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+5,1);
goto P_0c0af59e;
P_0c0af59e: /* original 600c, guest PC 0x0c0af59e */
if(!s->budget--) { s->failed_pc=0x0c0af59eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0af5a0;
P_0c0af5a0: /* original 8801, guest PC 0x0c0af5a0 */
if(!s->budget--) { s->failed_pc=0x0c0af5a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0af5a2;
P_0c0af5a2: /* original 8d07, guest PC 0x0c0af5a2 */
if(!s->budget--) { s->failed_pc=0x0c0af5a2u; return 0; }
cond=r[17]&1u;
r[7]=r[0];
if(cond) { goto P_0c0af5b4; }
goto P_0c0af5a6;
P_0c0af5a4: /* original 6703, guest PC 0x0c0af5a4 */
if(!s->budget--) { s->failed_pc=0x0c0af5a4u; return 0; }
r[7]=r[0];
goto P_0c0af5a6;
P_0c0af5a6: /* original 6073, guest PC 0x0c0af5a6 */
if(!s->budget--) { s->failed_pc=0x0c0af5a6u; return 0; }
r[0]=r[7];
goto P_0c0af5a8;
P_0c0af5a8: /* original 8805, guest PC 0x0c0af5a8 */
if(!s->budget--) { s->failed_pc=0x0c0af5a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0af5aa;
P_0c0af5aa: /* original 8b0e, guest PC 0x0c0af5aa */
if(!s->budget--) { s->failed_pc=0x0c0af5aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af5ca; }
goto P_0c0af5ac;
P_0c0af5ac: /* original 62f2, guest PC 0x0c0af5ac */
if(!s->budget--) { s->failed_pc=0x0c0af5acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0af5ae;
P_0c0af5ae: /* original 53f2, guest PC 0x0c0af5ae */
if(!s->budget--) { s->failed_pc=0x0c0af5aeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0af5b0;
P_0c0af5b0: /* original 3e28, guest PC 0x0c0af5b0 */
if(!s->budget--) { s->failed_pc=0x0c0af5b0u; return 0; }
r[14]-=r[2];
goto P_0c0af5b2;
P_0c0af5b2: /* original 3d38, guest PC 0x0c0af5b2 */
if(!s->budget--) { s->failed_pc=0x0c0af5b2u; return 0; }
r[13]-=r[3];
goto P_0c0af5b4;
P_0c0af5b4: /* original 901e, guest PC 0x0c0af5b4 */
if(!s->budget--) { s->failed_pc=0x0c0af5b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af5f4u,2);
goto P_0c0af5b6;
P_0c0af5b6: /* original 04d5, guest PC 0x0c0af5b6 */
if(!s->budget--) { s->failed_pc=0x0c0af5b6u; return 0; }
write(ram,r[4]+r[0],r[13],2);
goto P_0c0af5b8;
P_0c0af5b8: /* original 70fe, guest PC 0x0c0af5b8 */
if(!s->budget--) { s->failed_pc=0x0c0af5b8u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0af5ba;
P_0c0af5ba: /* original 04e5, guest PC 0x0c0af5ba */
if(!s->budget--) { s->failed_pc=0x0c0af5bau; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0af5bc;
P_0c0af5bc: /* original 901b, guest PC 0x0c0af5bc */
if(!s->budget--) { s->failed_pc=0x0c0af5bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af5f6u,2);
goto P_0c0af5be;
P_0c0af5be: /* original 53f1, guest PC 0x0c0af5be */
if(!s->budget--) { s->failed_pc=0x0c0af5beu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0af5c0;
P_0c0af5c0: /* original 0435, guest PC 0x0c0af5c0 */
if(!s->budget--) { s->failed_pc=0x0c0af5c0u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0af5c2;
P_0c0af5c2: /* original 70ff, guest PC 0x0c0af5c2 */
if(!s->budget--) { s->failed_pc=0x0c0af5c2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0af5c4;
P_0c0af5c4: /* original 0474, guest PC 0x0c0af5c4 */
if(!s->budget--) { s->failed_pc=0x0c0af5c4u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0af5c6;
P_0c0af5c6: /* original a001, guest PC 0x0c0af5c6 */
if(!s->budget--) { s->failed_pc=0x0c0af5c6u; return 0; }
r[14]=0x00000005u;
goto P_0c0af5cc;
P_0c0af5c8: /* original ee05, guest PC 0x0c0af5c8 */
if(!s->budget--) { s->failed_pc=0x0c0af5c8u; return 0; }
r[14]=0x00000005u;
goto P_0c0af5ca;
P_0c0af5ca: /* original 6e73, guest PC 0x0c0af5ca */
if(!s->budget--) { s->failed_pc=0x0c0af5cau; return 0; }
r[14]=r[7];
goto P_0c0af5cc;
P_0c0af5cc: /* original 7f0c, guest PC 0x0c0af5cc */
if(!s->budget--) { s->failed_pc=0x0c0af5ccu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0af5ce;
P_0c0af5ce: /* original 9013, guest PC 0x0c0af5ce */
if(!s->budget--) { s->failed_pc=0x0c0af5ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af5f8u,2);
goto P_0c0af5d0;
P_0c0af5d0: /* original 04e4, guest PC 0x0c0af5d0 */
if(!s->budget--) { s->failed_pc=0x0c0af5d0u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0af5d2;
P_0c0af5d2: /* original 5362, guest PC 0x0c0af5d2 */
if(!s->budget--) { s->failed_pc=0x0c0af5d2u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0af5d4;
P_0c0af5d4: /* original 730a, guest PC 0x0c0af5d4 */
if(!s->budget--) { s->failed_pc=0x0c0af5d4u; return 0; }
r[3]+=0x0000000au;
goto P_0c0af5d6;
P_0c0af5d6: /* original 1632, guest PC 0x0c0af5d6 */
if(!s->budget--) { s->failed_pc=0x0c0af5d6u; return 0; }
write(ram,r[6]+8,r[3],4);
goto P_0c0af5d8;
P_0c0af5d8: /* original d20a, guest PC 0x0c0af5d8 */
if(!s->budget--) { s->failed_pc=0x0c0af5d8u; return 0; }
r[2]=read(ram,0x0c0af604u,4);
goto P_0c0af5da;
P_0c0af5da: /* original 6df6, guest PC 0x0c0af5da */
if(!s->budget--) { s->failed_pc=0x0c0af5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af5dc;
P_0c0af5dc: /* original 422b, guest PC 0x0c0af5dc */
if(!s->budget--) { s->failed_pc=0x0c0af5dcu; return 0; }
target=r[2];
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
P_0c0af5de: /* original 6ef6, guest PC 0x0c0af5de */
if(!s->budget--) { s->failed_pc=0x0c0af5deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af5e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af5e0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
