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
int vf3_away_batch52_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0853e6u: goto P_0c0853e6;
case 0x0c0853e8u: goto P_0c0853e8;
case 0x0c0853eau: goto P_0c0853ea;
case 0x0c0853ecu: goto P_0c0853ec;
case 0x0c0853eeu: goto P_0c0853ee;
case 0x0c0853f0u: goto P_0c0853f0;
case 0x0c0853f2u: goto P_0c0853f2;
case 0x0c0853f4u: goto P_0c0853f4;
case 0x0c0853f6u: goto P_0c0853f6;
case 0x0c0853f8u: goto P_0c0853f8;
case 0x0c0853fau: goto P_0c0853fa;
case 0x0c0853fcu: goto P_0c0853fc;
case 0x0c0853feu: goto P_0c0853fe;
case 0x0c085400u: goto P_0c085400;
case 0x0c085402u: goto P_0c085402;
case 0x0c085404u: goto P_0c085404;
case 0x0c085406u: goto P_0c085406;
case 0x0c085408u: goto P_0c085408;
case 0x0c08540au: goto P_0c08540a;
case 0x0c08540cu: goto P_0c08540c;
case 0x0c08540eu: goto P_0c08540e;
case 0x0c085410u: goto P_0c085410;
case 0x0c085412u: goto P_0c085412;
case 0x0c085414u: goto P_0c085414;
case 0x0c085416u: goto P_0c085416;
case 0x0c085418u: goto P_0c085418;
case 0x0c08541au: goto P_0c08541a;
case 0x0c08541cu: goto P_0c08541c;
case 0x0c08541eu: goto P_0c08541e;
case 0x0c085420u: goto P_0c085420;
case 0x0c085422u: goto P_0c085422;
case 0x0c085424u: goto P_0c085424;
case 0x0c085426u: goto P_0c085426;
case 0x0c085428u: goto P_0c085428;
case 0x0c08542au: goto P_0c08542a;
case 0x0c08542cu: goto P_0c08542c;
case 0x0c08542eu: goto P_0c08542e;
case 0x0c085430u: goto P_0c085430;
case 0x0c085432u: goto P_0c085432;
case 0x0c085434u: goto P_0c085434;
case 0x0c085436u: goto P_0c085436;
case 0x0c085438u: goto P_0c085438;
case 0x0c08543au: goto P_0c08543a;
case 0x0c08543cu: goto P_0c08543c;
case 0x0c08543eu: goto P_0c08543e;
case 0x0c085440u: goto P_0c085440;
case 0x0c085442u: goto P_0c085442;
case 0x0c085444u: goto P_0c085444;
case 0x0c085446u: goto P_0c085446;
case 0x0c085448u: goto P_0c085448;
case 0x0c08544au: goto P_0c08544a;
case 0x0c08544cu: goto P_0c08544c;
case 0x0c08544eu: goto P_0c08544e;
case 0x0c085450u: goto P_0c085450;
case 0x0c085452u: goto P_0c085452;
case 0x0c085480u: goto P_0c085480;
case 0x0c085482u: goto P_0c085482;
case 0x0c085484u: goto P_0c085484;
case 0x0c085486u: goto P_0c085486;
case 0x0c085488u: goto P_0c085488;
case 0x0c08548au: goto P_0c08548a;
case 0x0c08548cu: goto P_0c08548c;
case 0x0c08548eu: goto P_0c08548e;
case 0x0c085490u: goto P_0c085490;
case 0x0c085492u: goto P_0c085492;
case 0x0c085494u: goto P_0c085494;
case 0x0c085496u: goto P_0c085496;
case 0x0c085498u: goto P_0c085498;
case 0x0c08549au: goto P_0c08549a;
case 0x0c08549cu: goto P_0c08549c;
case 0x0c08549eu: goto P_0c08549e;
case 0x0c0854a0u: goto P_0c0854a0;
case 0x0c0854a2u: goto P_0c0854a2;
case 0x0c0854a4u: goto P_0c0854a4;
case 0x0c0854a6u: goto P_0c0854a6;
case 0x0c0854a8u: goto P_0c0854a8;
case 0x0c0854aau: goto P_0c0854aa;
case 0x0c0854acu: goto P_0c0854ac;
case 0x0c0854aeu: goto P_0c0854ae;
case 0x0c0854b0u: goto P_0c0854b0;
case 0x0c0854b2u: goto P_0c0854b2;
case 0x0c0854b4u: goto P_0c0854b4;
case 0x0c0854b6u: goto P_0c0854b6;
case 0x0c0854b8u: goto P_0c0854b8;
case 0x0c0854bau: goto P_0c0854ba;
case 0x0c0854bcu: goto P_0c0854bc;
case 0x0c0854beu: goto P_0c0854be;
case 0x0c0854c0u: goto P_0c0854c0;
case 0x0c0854c2u: goto P_0c0854c2;
case 0x0c0854c4u: goto P_0c0854c4;
case 0x0c0854c6u: goto P_0c0854c6;
case 0x0c0854c8u: goto P_0c0854c8;
case 0x0c0854cau: goto P_0c0854ca;
case 0x0c0854ccu: goto P_0c0854cc;
case 0x0c0854ceu: goto P_0c0854ce;
case 0x0c0854d0u: goto P_0c0854d0;
case 0x0c0854d2u: goto P_0c0854d2;
case 0x0c0854d4u: goto P_0c0854d4;
case 0x0c0854d6u: goto P_0c0854d6;
case 0x0c0854d8u: goto P_0c0854d8;
case 0x0c0854dau: goto P_0c0854da;
case 0x0c0854dcu: goto P_0c0854dc;
case 0x0c0854deu: goto P_0c0854de;
case 0x0c0854e0u: goto P_0c0854e0;
case 0x0c0854e2u: goto P_0c0854e2;
case 0x0c0854e4u: goto P_0c0854e4;
case 0x0c0854e6u: goto P_0c0854e6;
case 0x0c0854e8u: goto P_0c0854e8;
case 0x0c0854eau: goto P_0c0854ea;
case 0x0c0854ecu: goto P_0c0854ec;
case 0x0c0854eeu: goto P_0c0854ee;
case 0x0c0854f0u: goto P_0c0854f0;
case 0x0c0854f2u: goto P_0c0854f2;
case 0x0c0854f4u: goto P_0c0854f4;
case 0x0c0854f6u: goto P_0c0854f6;
case 0x0c0854f8u: goto P_0c0854f8;
case 0x0c0854fau: goto P_0c0854fa;
case 0x0c0854fcu: goto P_0c0854fc;
case 0x0c0854feu: goto P_0c0854fe;
case 0x0c085500u: goto P_0c085500;
case 0x0c085502u: goto P_0c085502;
case 0x0c085504u: goto P_0c085504;
case 0x0c085506u: goto P_0c085506;
case 0x0c085508u: goto P_0c085508;
case 0x0c08550au: goto P_0c08550a;
case 0x0c08550cu: goto P_0c08550c;
case 0x0c08550eu: goto P_0c08550e;
case 0x0c085510u: goto P_0c085510;
case 0x0c085512u: goto P_0c085512;
case 0x0c085514u: goto P_0c085514;
case 0x0c085516u: goto P_0c085516;
case 0x0c085518u: goto P_0c085518;
case 0x0c08551au: goto P_0c08551a;
case 0x0c08551cu: goto P_0c08551c;
case 0x0c08551eu: goto P_0c08551e;
case 0x0c085520u: goto P_0c085520;
case 0x0c085522u: goto P_0c085522;
case 0x0c085524u: goto P_0c085524;
case 0x0c085526u: goto P_0c085526;
case 0x0c085528u: goto P_0c085528;
case 0x0c08552au: goto P_0c08552a;
case 0x0c08552cu: goto P_0c08552c;
case 0x0c08552eu: goto P_0c08552e;
case 0x0c085530u: goto P_0c085530;
case 0x0c085532u: goto P_0c085532;
case 0x0c085534u: goto P_0c085534;
case 0x0c085536u: goto P_0c085536;
case 0x0c085538u: goto P_0c085538;
case 0x0c08553au: goto P_0c08553a;
case 0x0c08553cu: goto P_0c08553c;
case 0x0c08553eu: goto P_0c08553e;
case 0x0c085540u: goto P_0c085540;
case 0x0c085542u: goto P_0c085542;
case 0x0c085544u: goto P_0c085544;
case 0x0c085546u: goto P_0c085546;
case 0x0c085548u: goto P_0c085548;
case 0x0c08554au: goto P_0c08554a;
case 0x0c08554cu: goto P_0c08554c;
case 0x0c08554eu: goto P_0c08554e;
case 0x0c085550u: goto P_0c085550;
case 0x0c085552u: goto P_0c085552;
case 0x0c085554u: goto P_0c085554;
case 0x0c085556u: goto P_0c085556;
case 0x0c085558u: goto P_0c085558;
case 0x0c08555au: goto P_0c08555a;
case 0x0c08555cu: goto P_0c08555c;
case 0x0c08555eu: goto P_0c08555e;
case 0x0c085560u: goto P_0c085560;
case 0x0c085562u: goto P_0c085562;
case 0x0c085564u: goto P_0c085564;
case 0x0c085566u: goto P_0c085566;
case 0x0c085568u: goto P_0c085568;
case 0x0c08556au: goto P_0c08556a;
case 0x0c08556cu: goto P_0c08556c;
case 0x0c08556eu: goto P_0c08556e;
case 0x0c085570u: goto P_0c085570;
case 0x0c085572u: goto P_0c085572;
case 0x0c085574u: goto P_0c085574;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0853e6: /* original 2fe6, guest PC 0x0c0853e6 */
if(!s->budget--) { s->failed_pc=0x0c0853e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853e8;
P_0c0853e8: /* original 2fd6, guest PC 0x0c0853e8 */
if(!s->budget--) { s->failed_pc=0x0c0853e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853ea;
P_0c0853ea: /* original 2fc6, guest PC 0x0c0853ea */
if(!s->budget--) { s->failed_pc=0x0c0853eau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853ec;
P_0c0853ec: /* original 2fb6, guest PC 0x0c0853ec */
if(!s->budget--) { s->failed_pc=0x0c0853ecu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853ee;
P_0c0853ee: /* original 2fa6, guest PC 0x0c0853ee */
if(!s->budget--) { s->failed_pc=0x0c0853eeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853f0;
P_0c0853f0: /* original 2f96, guest PC 0x0c0853f0 */
if(!s->budget--) { s->failed_pc=0x0c0853f0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853f2;
P_0c0853f2: /* original 2f86, guest PC 0x0c0853f2 */
if(!s->budget--) { s->failed_pc=0x0c0853f2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853f4;
P_0c0853f4: /* original fffb, guest PC 0x0c0853f4 */
if(!s->budget--) { s->failed_pc=0x0c0853f4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0853f6;
P_0c0853f6: /* original ffeb, guest PC 0x0c0853f6 */
if(!s->budget--) { s->failed_pc=0x0c0853f6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0853f8;
P_0c0853f8: /* original ffdb, guest PC 0x0c0853f8 */
if(!s->budget--) { s->failed_pc=0x0c0853f8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0853fa;
P_0c0853fa: /* original ffcb, guest PC 0x0c0853fa */
if(!s->budget--) { s->failed_pc=0x0c0853fau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0853fc;
P_0c0853fc: /* original d11a, guest PC 0x0c0853fc */
if(!s->budget--) { s->failed_pc=0x0c0853fcu; return 0; }
r[1]=read(ram,0x0c085468u,4);
goto P_0c0853fe;
P_0c0853fe: /* original 4f22, guest PC 0x0c0853fe */
if(!s->budget--) { s->failed_pc=0x0c0853feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085400;
P_0c085400: /* original d318, guest PC 0x0c085400 */
if(!s->budget--) { s->failed_pc=0x0c085400u; return 0; }
r[3]=read(ram,0x0c085464u,4);
goto P_0c085402;
P_0c085402: /* original 6212, guest PC 0x0c085402 */
if(!s->budget--) { s->failed_pc=0x0c085402u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c085404;
P_0c085404: /* original 7ff0, guest PC 0x0c085404 */
if(!s->budget--) { s->failed_pc=0x0c085404u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c085406;
P_0c085406: /* original 2238, guest PC 0x0c085406 */
if(!s->budget--) { s->failed_pc=0x0c085406u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085408;
P_0c085408: /* original 8d02, guest PC 0x0c085408 */
if(!s->budget--) { s->failed_pc=0x0c085408u; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(cond) { goto P_0c085410; }
goto P_0c08540c;
P_0c08540a: /* original eb00, guest PC 0x0c08540a */
if(!s->budget--) { s->failed_pc=0x0c08540au; return 0; }
r[11]=0x00000000u;
goto P_0c08540c;
P_0c08540c: /* original a0a5, guest PC 0x0c08540c */
if(!s->budget--) { s->failed_pc=0x0c08540cu; return 0; }
goto P_0c08555a;
P_0c08540e: /* original 0009, guest PC 0x0c08540e */
if(!s->budget--) { s->failed_pc=0x0c08540eu; return 0; }
goto P_0c085410;
P_0c085410: /* original d316, guest PC 0x0c085410 */
if(!s->budget--) { s->failed_pc=0x0c085410u; return 0; }
r[3]=read(ram,0x0c08546cu,4);
goto P_0c085412;
P_0c085412: /* original 6543, guest PC 0x0c085412 */
if(!s->budget--) { s->failed_pc=0x0c085412u; return 0; }
r[5]=r[4];
goto P_0c085414;
P_0c085414: /* original d216, guest PC 0x0c085414 */
if(!s->budget--) { s->failed_pc=0x0c085414u; return 0; }
r[2]=read(ram,0x0c085470u,4);
goto P_0c085416;
P_0c085416: /* original 6a32, guest PC 0x0c085416 */
if(!s->budget--) { s->failed_pc=0x0c085416u; return 0; }
tmp=read(ram,r[3],4);
r[10]=tmp;
goto P_0c085418;
P_0c085418: /* original 85af, guest PC 0x0c085418 */
if(!s->budget--) { s->failed_pc=0x0c085418u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+30,2);
goto P_0c08541a;
P_0c08541a: /* original 6403, guest PC 0x0c08541a */
if(!s->budget--) { s->failed_pc=0x0c08541au; return 0; }
r[4]=r[0];
goto P_0c08541c;
P_0c08541c: /* original 3427, guest PC 0x0c08541c */
if(!s->budget--) { s->failed_pc=0x0c08541cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c08541e;
P_0c08541e: /* original 8b02, guest PC 0x0c08541e */
if(!s->budget--) { s->failed_pc=0x0c08541eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085426; }
goto P_0c085420;
P_0c085420: /* original d80e, guest PC 0x0c085420 */
if(!s->budget--) { s->failed_pc=0x0c085420u; return 0; }
r[8]=read(ram,0x0c08545cu,4);
goto P_0c085422;
P_0c085422: /* original a001, guest PC 0x0c085422 */
if(!s->budget--) { s->failed_pc=0x0c085422u; return 0; }
goto P_0c085428;
P_0c085424: /* original 0009, guest PC 0x0c085424 */
if(!s->budget--) { s->failed_pc=0x0c085424u; return 0; }
goto P_0c085426;
P_0c085426: /* original d813, guest PC 0x0c085426 */
if(!s->budget--) { s->failed_pc=0x0c085426u; return 0; }
r[8]=read(ram,0x0c085474u,4);
goto P_0c085428;
P_0c085428: /* original dc0b, guest PC 0x0c085428 */
if(!s->budget--) { s->failed_pc=0x0c085428u; return 0; }
r[12]=read(ram,0x0c085458u,4);
goto P_0c08542a;
P_0c08542a: /* original 6e53, guest PC 0x0c08542a */
if(!s->budget--) { s->failed_pc=0x0c08542au; return 0; }
r[14]=r[5];
goto P_0c08542c;
P_0c08542c: /* original 2fb2, guest PC 0x0c08542c */
if(!s->budget--) { s->failed_pc=0x0c08542cu; return 0; }
write(ram,r[15],r[11],4);
goto P_0c08542e;
P_0c08542e: /* original d312, guest PC 0x0c08542e */
if(!s->budget--) { s->failed_pc=0x0c08542eu; return 0; }
r[3]=read(ram,0x0c085478u,4);
goto P_0c085430;
P_0c085430: /* original a08d, guest PC 0x0c085430 */
if(!s->budget--) { s->failed_pc=0x0c085430u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08554e;
P_0c085432: /* original 1f32, guest PC 0x0c085432 */
if(!s->budget--) { s->failed_pc=0x0c085432u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c085434;
P_0c085434: /* original e008, guest PC 0x0c085434 */
if(!s->budget--) { s->failed_pc=0x0c085434u; return 0; }
r[0]=0x00000008u;
goto P_0c085436;
P_0c085436: /* original fee6, guest PC 0x0c085436 */
if(!s->budget--) { s->failed_pc=0x0c085436u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c085438;
P_0c085438: /* original 85e6, guest PC 0x0c085438 */
if(!s->budget--) { s->failed_pc=0x0c085438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c08543a;
P_0c08543a: /* original 6d03, guest PC 0x0c08543a */
if(!s->budget--) { s->failed_pc=0x0c08543au; return 0; }
r[13]=r[0];
goto P_0c08543c;
P_0c08543c: /* original 2dd8, guest PC 0x0c08543c */
if(!s->budget--) { s->failed_pc=0x0c08543cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c08543e;
P_0c08543e: /* original 8f1f, guest PC 0x0c08543e */
if(!s->budget--) { s->failed_pc=0x0c08543eu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]);
if(!cond) { goto P_0c085480; }
goto P_0c085442;
P_0c085440: /* original ffe8, guest PC 0x0c085440 */
if(!s->budget--) { s->failed_pc=0x0c085440u; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c085442;
P_0c085442: /* original d10e, guest PC 0x0c085442 */
if(!s->budget--) { s->failed_pc=0x0c085442u; return 0; }
r[1]=read(ram,0x0c08547cu,4);
goto P_0c085444;
P_0c085444: /* original 9206, guest PC 0x0c085444 */
if(!s->budget--) { s->failed_pc=0x0c085444u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085454u,2);
goto P_0c085446;
P_0c085446: /* original 6312, guest PC 0x0c085446 */
if(!s->budget--) { s->failed_pc=0x0c085446u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c085448;
P_0c085448: /* original 3327, guest PC 0x0c085448 */
if(!s->budget--) { s->failed_pc=0x0c085448u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c08544a;
P_0c08544a: /* original 8b19, guest PC 0x0c08544a */
if(!s->budget--) { s->failed_pc=0x0c08544au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085480; }
goto P_0c08544c;
P_0c08544c: /* original 50f2, guest PC 0x0c08544c */
if(!s->budget--) { s->failed_pc=0x0c08544cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c08544e;
P_0c08544e: /* original 6001, guest PC 0x0c08544e */
if(!s->budget--) { s->failed_pc=0x0c08544eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[0],2);
r[0]=tmp;
goto P_0c085450;
P_0c085450: /* original a079, guest PC 0x0c085450 */
if(!s->budget--) { s->failed_pc=0x0c085450u; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c085546;
P_0c085452: /* original 81e7, guest PC 0x0c085452 */
if(!s->budget--) { s->failed_pc=0x0c085452u; return 0; }
write(ram,r[14]+14,r[0],2);
if(!vf3_matrix_family(0x0c085454u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085454u; return 0; } return 1;
P_0c085480: /* original 85e8, guest PC 0x0c085480 */
if(!s->budget--) { s->failed_pc=0x0c085480u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c085482;
P_0c085482: /* original f4c8, guest PC 0x0c085482 */
if(!s->budget--) { s->failed_pc=0x0c085482u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c085484;
P_0c085484: /* original 6903, guest PC 0x0c085484 */
if(!s->budget--) { s->failed_pc=0x0c085484u; return 0; }
r[9]=r[0];
goto P_0c085486;
P_0c085486: /* original e010, guest PC 0x0c085486 */
if(!s->budget--) { s->failed_pc=0x0c085486u; return 0; }
r[0]=0x00000010u;
goto P_0c085488;
P_0c085488: /* original fca6, guest PC 0x0c085488 */
if(!s->budget--) { s->failed_pc=0x0c085488u; return 0; }
vf3_matrix_load(s,ram,12,r[10]+r[0]);
goto P_0c08548a;
P_0c08548a: /* original e018, guest PC 0x0c08548a */
if(!s->budget--) { s->failed_pc=0x0c08548au; return 0; }
r[0]=0x00000018u;
goto P_0c08548c;
P_0c08548c: /* original fda6, guest PC 0x0c08548c */
if(!s->budget--) { s->failed_pc=0x0c08548cu; return 0; }
vf3_matrix_load(s,ram,13,r[10]+r[0]);
goto P_0c08548e;
P_0c08548e: /* original ff40, guest PC 0x0c08548e */
if(!s->budget--) { s->failed_pc=0x0c08548eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'+');
goto P_0c085490;
P_0c085490: /* original 85af, guest PC 0x0c085490 */
if(!s->budget--) { s->failed_pc=0x0c085490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+30,2);
goto P_0c085492;
P_0c085492: /* original 53c6, guest PC 0x0c085492 */
if(!s->budget--) { s->failed_pc=0x0c085492u; return 0; }
r[3]=read(ram,r[12]+24,4);
goto P_0c085494;
P_0c085494: /* original 6503, guest PC 0x0c085494 */
if(!s->budget--) { s->failed_pc=0x0c085494u; return 0; }
r[5]=r[0];
goto P_0c085496;
P_0c085496: /* original e004, guest PC 0x0c085496 */
if(!s->budget--) { s->failed_pc=0x0c085496u; return 0; }
r[0]=0x00000004u;
goto P_0c085498;
P_0c085498: /* original f5c6, guest PC 0x0c085498 */
if(!s->budget--) { s->failed_pc=0x0c085498u; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c08549a;
P_0c08549a: /* original e008, guest PC 0x0c08549a */
if(!s->budget--) { s->failed_pc=0x0c08549au; return 0; }
r[0]=0x00000008u;
goto P_0c08549c;
P_0c08549c: /* original f9c6, guest PC 0x0c08549c */
if(!s->budget--) { s->failed_pc=0x0c08549cu; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08549e;
P_0c08549e: /* original e00c, guest PC 0x0c08549e */
if(!s->budget--) { s->failed_pc=0x0c08549eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0854a0;
P_0c0854a0: /* original f7c6, guest PC 0x0c0854a0 */
if(!s->budget--) { s->failed_pc=0x0c0854a0u; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c0854a2;
P_0c0854a2: /* original e010, guest PC 0x0c0854a2 */
if(!s->budget--) { s->failed_pc=0x0c0854a2u; return 0; }
r[0]=0x00000010u;
goto P_0c0854a4;
P_0c0854a4: /* original f8c6, guest PC 0x0c0854a4 */
if(!s->budget--) { s->failed_pc=0x0c0854a4u; return 0; }
vf3_matrix_load(s,ram,8,r[12]+r[0]);
goto P_0c0854a6;
P_0c0854a6: /* original ff95, guest PC 0x0c0854a6 */
if(!s->budget--) { s->failed_pc=0x0c0854a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[9]))!=0);
goto P_0c0854a8;
P_0c0854a8: /* original e014, guest PC 0x0c0854a8 */
if(!s->budget--) { s->failed_pc=0x0c0854a8u; return 0; }
r[0]=0x00000014u;
goto P_0c0854aa;
P_0c0854aa: /* original f6c6, guest PC 0x0c0854aa */
if(!s->budget--) { s->failed_pc=0x0c0854aau; return 0; }
vf3_matrix_load(s,ram,6,r[12]+r[0]);
goto P_0c0854ac;
P_0c0854ac: /* original 1f31, guest PC 0x0c0854ac */
if(!s->budget--) { s->failed_pc=0x0c0854acu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0854ae;
P_0c0854ae: /* original 54c7, guest PC 0x0c0854ae */
if(!s->budget--) { s->failed_pc=0x0c0854aeu; return 0; }
r[4]=read(ram,r[12]+28,4);
goto P_0c0854b0;
P_0c0854b0: /* original 7c20, guest PC 0x0c0854b0 */
if(!s->budget--) { s->failed_pc=0x0c0854b0u; return 0; }
r[12]+=0x00000020u;
goto P_0c0854b2;
P_0c0854b2: /* original 1fd3, guest PC 0x0c0854b2 */
if(!s->budget--) { s->failed_pc=0x0c0854b2u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0854b4;
P_0c0854b4: /* original 345c, guest PC 0x0c0854b4 */
if(!s->budget--) { s->failed_pc=0x0c0854b4u; return 0; }
r[4]+=r[5];
goto P_0c0854b6;
P_0c0854b6: /* original 955e, guest PC 0x0c0854b6 */
if(!s->budget--) { s->failed_pc=0x0c0854b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085576u,2);
goto P_0c0854b8;
P_0c0854b8: /* original 345c, guest PC 0x0c0854b8 */
if(!s->budget--) { s->failed_pc=0x0c0854b8u; return 0; }
r[4]+=r[5];
goto P_0c0854ba;
P_0c0854ba: /* original 6043, guest PC 0x0c0854ba */
if(!s->budget--) { s->failed_pc=0x0c0854bau; return 0; }
r[0]=r[4];
goto P_0c0854bc;
P_0c0854bc: /* original 81e9, guest PC 0x0c0854bc */
if(!s->budget--) { s->failed_pc=0x0c0854bcu; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c0854be;
P_0c0854be: /* original 8d04, guest PC 0x0c0854be */
if(!s->budget--) { s->failed_pc=0x0c0854beu; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'+');
if(cond) { goto P_0c0854ca; }
goto P_0c0854c2;
P_0c0854c0: /* original fe50, guest PC 0x0c0854c0 */
if(!s->budget--) { s->failed_pc=0x0c0854c0u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'+');
goto P_0c0854c2;
P_0c0854c2: /* original 2dd8, guest PC 0x0c0854c2 */
if(!s->budget--) { s->failed_pc=0x0c0854c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0854c4;
P_0c0854c4: /* original 8f01, guest PC 0x0c0854c4 */
if(!s->budget--) { s->failed_pc=0x0c0854c4u; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
if(!cond) { goto P_0c0854ca; }
goto P_0c0854c8;
P_0c0854c6: /* original ff41, guest PC 0x0c0854c6 */
if(!s->budget--) { s->failed_pc=0x0c0854c6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c0854c8;
P_0c0854c8: /* original ff8c, guest PC 0x0c0854c8 */
if(!s->budget--) { s->failed_pc=0x0c0854c8u; return 0; }
vf3_matrix_move(s,15,8);
goto P_0c0854ca;
P_0c0854ca: /* original fe75, guest PC 0x0c0854ca */
if(!s->budget--) { s->failed_pc=0x0c0854cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[7]))!=0);
goto P_0c0854cc;
P_0c0854cc: /* original 8903, guest PC 0x0c0854cc */
if(!s->budget--) { s->failed_pc=0x0c0854ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0854d6; }
goto P_0c0854ce;
P_0c0854ce: /* original 2dd8, guest PC 0x0c0854ce */
if(!s->budget--) { s->failed_pc=0x0c0854ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0854d0;
P_0c0854d0: /* original 8f01, guest PC 0x0c0854d0 */
if(!s->budget--) { s->failed_pc=0x0c0854d0u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'-');
if(!cond) { goto P_0c0854d6; }
goto P_0c0854d4;
P_0c0854d2: /* original fe51, guest PC 0x0c0854d2 */
if(!s->budget--) { s->failed_pc=0x0c0854d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'-');
goto P_0c0854d4;
P_0c0854d4: /* original fe6c, guest PC 0x0c0854d4 */
if(!s->budget--) { s->failed_pc=0x0c0854d4u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c0854d6;
P_0c0854d6: /* original d328, guest PC 0x0c0854d6 */
if(!s->budget--) { s->failed_pc=0x0c0854d6u; return 0; }
r[3]=read(ram,0x0c085578u,4);
goto P_0c0854d8;
P_0c0854d8: /* original f5ec, guest PC 0x0c0854d8 */
if(!s->budget--) { s->failed_pc=0x0c0854d8u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0854da;
P_0c0854da: /* original 430b, guest PC 0x0c0854da */
if(!s->budget--) { s->failed_pc=0x0c0854dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0854deu;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0854deu) { target=s->pc; goto dispatch; }
goto P_0c0854de;
P_0c0854dc: /* original f4fc, guest PC 0x0c0854dc */
if(!s->budget--) { s->failed_pc=0x0c0854dcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0854de;
P_0c0854de: /* original 7901, guest PC 0x0c0854de */
if(!s->budget--) { s->failed_pc=0x0c0854deu; return 0; }
r[9]+=0x00000001u;
goto P_0c0854e0;
P_0c0854e0: /* original 6293, guest PC 0x0c0854e0 */
if(!s->budget--) { s->failed_pc=0x0c0854e0u; return 0; }
r[2]=r[9];
goto P_0c0854e2;
P_0c0854e2: /* original e401, guest PC 0x0c0854e2 */
if(!s->budget--) { s->failed_pc=0x0c0854e2u; return 0; }
r[4]=0x00000001u;
goto P_0c0854e4;
P_0c0854e4: /* original 2248, guest PC 0x0c0854e4 */
if(!s->budget--) { s->failed_pc=0x0c0854e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0854e6;
P_0c0854e6: /* original 8d01, guest PC 0x0c0854e6 */
if(!s->budget--) { s->failed_pc=0x0c0854e6u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,0);
if(cond) { goto P_0c0854ec; }
goto P_0c0854ea;
P_0c0854e8: /* original f50c, guest PC 0x0c0854e8 */
if(!s->budget--) { s->failed_pc=0x0c0854e8u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0854ea;
P_0c0854ea: /* original 7d01, guest PC 0x0c0854ea */
if(!s->budget--) { s->failed_pc=0x0c0854eau; return 0; }
r[13]+=0x00000001u;
goto P_0c0854ec;
P_0c0854ec: /* original fde1, guest PC 0x0c0854ec */
if(!s->budget--) { s->failed_pc=0x0c0854ecu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c0854ee;
P_0c0854ee: /* original 649d, guest PC 0x0c0854ee */
if(!s->budget--) { s->failed_pc=0x0c0854eeu; return 0; }
r[4]=r[9]&65535u;
goto P_0c0854f0;
P_0c0854f0: /* original fcf1, guest PC 0x0c0854f0 */
if(!s->budget--) { s->failed_pc=0x0c0854f0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'-');
goto P_0c0854f2;
P_0c0854f2: /* original 52f1, guest PC 0x0c0854f2 */
if(!s->budget--) { s->failed_pc=0x0c0854f2u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0854f4;
P_0c0854f4: /* original 6043, guest PC 0x0c0854f4 */
if(!s->budget--) { s->failed_pc=0x0c0854f4u; return 0; }
r[0]=r[4];
goto P_0c0854f6;
P_0c0854f6: /* original 81e8, guest PC 0x0c0854f6 */
if(!s->budget--) { s->failed_pc=0x0c0854f6u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c0854f8;
P_0c0854f8: /* original 2d29, guest PC 0x0c0854f8 */
if(!s->budget--) { s->failed_pc=0x0c0854f8u; return 0; }
r[13]&=r[2];
goto P_0c0854fa;
P_0c0854fa: /* original 60d3, guest PC 0x0c0854fa */
if(!s->budget--) { s->failed_pc=0x0c0854fau; return 0; }
r[0]=r[13];
goto P_0c0854fc;
P_0c0854fc: /* original 81e6, guest PC 0x0c0854fc */
if(!s->budget--) { s->failed_pc=0x0c0854fcu; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c0854fe;
P_0c0854fe: /* original f3dc, guest PC 0x0c0854fe */
if(!s->budget--) { s->failed_pc=0x0c0854feu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c085500;
P_0c085500: /* original f3d2, guest PC 0x0c085500 */
if(!s->budget--) { s->failed_pc=0x0c085500u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c085502;
P_0c085502: /* original f0cc, guest PC 0x0c085502 */
if(!s->budget--) { s->failed_pc=0x0c085502u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c085504;
P_0c085504: /* original c71d, guest PC 0x0c085504 */
if(!s->budget--) { s->failed_pc=0x0c085504u; return 0; }
r[0]=code_base|0x0008557cu;
goto P_0c085506;
P_0c085506: /* original 53f3, guest PC 0x0c085506 */
if(!s->budget--) { s->failed_pc=0x0c085506u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c085508;
P_0c085508: /* original f608, guest PC 0x0c085508 */
if(!s->budget--) { s->failed_pc=0x0c085508u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08550a;
P_0c08550a: /* original f3ce, guest PC 0x0c08550a */
if(!s->budget--) { s->failed_pc=0x0c08550au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[12],fr[3],r[18]);
goto P_0c08550c;
P_0c08550c: /* original 2338, guest PC 0x0c08550c */
if(!s->budget--) { s->failed_pc=0x0c08550cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08550e;
P_0c08550e: /* original f43c, guest PC 0x0c08550e */
if(!s->budget--) { s->failed_pc=0x0c08550eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085510;
P_0c085510: /* original 8f06, guest PC 0x0c085510 */
if(!s->budget--) { s->failed_pc=0x0c085510u; return 0; }
cond=r[17]&1u;
fr[4]&=0x7fffffffu;
if(!cond) { goto P_0c085520; }
goto P_0c085514;
P_0c085512: /* original f45d, guest PC 0x0c085512 */
if(!s->budget--) { s->failed_pc=0x0c085512u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c085514;
P_0c085514: /* original f465, guest PC 0x0c085514 */
if(!s->budget--) { s->failed_pc=0x0c085514u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c085516;
P_0c085516: /* original 6482, guest PC 0x0c085516 */
if(!s->budget--) { s->failed_pc=0x0c085516u; return 0; }
tmp=read(ram,r[8],4);
r[4]=tmp;
goto P_0c085518;
P_0c085518: /* original 8d0a, guest PC 0x0c085518 */
if(!s->budget--) { s->failed_pc=0x0c085518u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[4],4);
if(cond) { goto P_0c085530; }
goto P_0c08551c;
P_0c08551a: /* original 1e45, guest PC 0x0c08551a */
if(!s->budget--) { s->failed_pc=0x0c08551au; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c08551c;
P_0c08551c: /* original a006, guest PC 0x0c08551c */
if(!s->budget--) { s->failed_pc=0x0c08551cu; return 0; }
r[13]=r[11];
goto P_0c08552c;
P_0c08551e: /* original 6db3, guest PC 0x0c08551e */
if(!s->budget--) { s->failed_pc=0x0c08551eu; return 0; }
r[13]=r[11];
goto P_0c085520;
P_0c085520: /* original e43e, guest PC 0x0c085520 */
if(!s->budget--) { s->failed_pc=0x0c085520u; return 0; }
r[4]=0x0000003eu;
goto P_0c085522;
P_0c085522: /* original 3d43, guest PC 0x0c085522 */
if(!s->budget--) { s->failed_pc=0x0c085522u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[4])!=0);
goto P_0c085524;
P_0c085524: /* original 8b04, guest PC 0x0c085524 */
if(!s->budget--) { s->failed_pc=0x0c085524u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085530; }
goto P_0c085526;
P_0c085526: /* original f645, guest PC 0x0c085526 */
if(!s->budget--) { s->failed_pc=0x0c085526u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[4]))!=0);
goto P_0c085528;
P_0c085528: /* original 8d02, guest PC 0x0c085528 */
if(!s->budget--) { s->failed_pc=0x0c085528u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(cond) { goto P_0c085530; }
goto P_0c08552c;
P_0c08552a: /* original 6db3, guest PC 0x0c08552a */
if(!s->budget--) { s->failed_pc=0x0c08552au; return 0; }
r[13]=r[11];
goto P_0c08552c;
P_0c08552c: /* original 60b3, guest PC 0x0c08552c */
if(!s->budget--) { s->failed_pc=0x0c08552cu; return 0; }
r[0]=r[11];
goto P_0c08552e;
P_0c08552e: /* original 81e6, guest PC 0x0c08552e */
if(!s->budget--) { s->failed_pc=0x0c08552eu; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c085530;
P_0c085530: /* original 60d3, guest PC 0x0c085530 */
if(!s->budget--) { s->failed_pc=0x0c085530u; return 0; }
r[0]=r[13];
goto P_0c085532;
P_0c085532: /* original 54e5, guest PC 0x0c085532 */
if(!s->budget--) { s->failed_pc=0x0c085532u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c085534;
P_0c085534: /* original 4000, guest PC 0x0c085534 */
if(!s->budget--) { s->failed_pc=0x0c085534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c085536;
P_0c085536: /* original 004d, guest PC 0x0c085536 */
if(!s->budget--) { s->failed_pc=0x0c085536u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c085538;
P_0c085538: /* original 7804, guest PC 0x0c085538 */
if(!s->budget--) { s->failed_pc=0x0c085538u; return 0; }
r[8]+=0x00000004u;
goto P_0c08553a;
P_0c08553a: /* original 81e7, guest PC 0x0c08553a */
if(!s->budget--) { s->failed_pc=0x0c08553au; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c08553c;
P_0c08553c: /* original e004, guest PC 0x0c08553c */
if(!s->budget--) { s->failed_pc=0x0c08553cu; return 0; }
r[0]=0x00000004u;
goto P_0c08553e;
P_0c08553e: /* original fefa, guest PC 0x0c08553e */
if(!s->budget--) { s->failed_pc=0x0c08553eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c085540;
P_0c085540: /* original fe57, guest PC 0x0c085540 */
if(!s->budget--) { s->failed_pc=0x0c085540u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c085542;
P_0c085542: /* original e008, guest PC 0x0c085542 */
if(!s->budget--) { s->failed_pc=0x0c085542u; return 0; }
r[0]=0x00000008u;
goto P_0c085544;
P_0c085544: /* original fee7, guest PC 0x0c085544 */
if(!s->budget--) { s->failed_pc=0x0c085544u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c085546;
P_0c085546: /* original 63f2, guest PC 0x0c085546 */
if(!s->budget--) { s->failed_pc=0x0c085546u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085548;
P_0c085548: /* original 7e18, guest PC 0x0c085548 */
if(!s->budget--) { s->failed_pc=0x0c085548u; return 0; }
r[14]+=0x00000018u;
goto P_0c08554a;
P_0c08554a: /* original 7301, guest PC 0x0c08554a */
if(!s->budget--) { s->failed_pc=0x0c08554au; return 0; }
r[3]+=0x00000001u;
goto P_0c08554c;
P_0c08554c: /* original 2f32, guest PC 0x0c08554c */
if(!s->budget--) { s->failed_pc=0x0c08554cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08554e;
P_0c08554e: /* original 63f2, guest PC 0x0c08554e */
if(!s->budget--) { s->failed_pc=0x0c08554eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085550;
P_0c085550: /* original e40d, guest PC 0x0c085550 */
if(!s->budget--) { s->failed_pc=0x0c085550u; return 0; }
r[4]=0x0000000du;
goto P_0c085552;
P_0c085552: /* original 3343, guest PC 0x0c085552 */
if(!s->budget--) { s->failed_pc=0x0c085552u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c085554;
P_0c085554: /* original 8901, guest PC 0x0c085554 */
if(!s->budget--) { s->failed_pc=0x0c085554u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08555a; }
goto P_0c085556;
P_0c085556: /* original af6d, guest PC 0x0c085556 */
if(!s->budget--) { s->failed_pc=0x0c085556u; return 0; }
goto P_0c085434;
P_0c085558: /* original 0009, guest PC 0x0c085558 */
if(!s->budget--) { s->failed_pc=0x0c085558u; return 0; }
goto P_0c08555a;
P_0c08555a: /* original 7f10, guest PC 0x0c08555a */
if(!s->budget--) { s->failed_pc=0x0c08555au; return 0; }
r[15]+=0x00000010u;
goto P_0c08555c;
P_0c08555c: /* original 4f26, guest PC 0x0c08555c */
if(!s->budget--) { s->failed_pc=0x0c08555cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08555e;
P_0c08555e: /* original fcf9, guest PC 0x0c08555e */
if(!s->budget--) { s->failed_pc=0x0c08555eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085560;
P_0c085560: /* original fdf9, guest PC 0x0c085560 */
if(!s->budget--) { s->failed_pc=0x0c085560u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085562;
P_0c085562: /* original fef9, guest PC 0x0c085562 */
if(!s->budget--) { s->failed_pc=0x0c085562u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085564;
P_0c085564: /* original fff9, guest PC 0x0c085564 */
if(!s->budget--) { s->failed_pc=0x0c085564u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085566;
P_0c085566: /* original 68f6, guest PC 0x0c085566 */
if(!s->budget--) { s->failed_pc=0x0c085566u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085568;
P_0c085568: /* original 69f6, guest PC 0x0c085568 */
if(!s->budget--) { s->failed_pc=0x0c085568u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08556a;
P_0c08556a: /* original 6af6, guest PC 0x0c08556a */
if(!s->budget--) { s->failed_pc=0x0c08556au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08556c;
P_0c08556c: /* original 6bf6, guest PC 0x0c08556c */
if(!s->budget--) { s->failed_pc=0x0c08556cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08556e;
P_0c08556e: /* original 6cf6, guest PC 0x0c08556e */
if(!s->budget--) { s->failed_pc=0x0c08556eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085570;
P_0c085570: /* original 6df6, guest PC 0x0c085570 */
if(!s->budget--) { s->failed_pc=0x0c085570u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085572;
P_0c085572: /* original 000b, guest PC 0x0c085572 */
if(!s->budget--) { s->failed_pc=0x0c085572u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085574: /* original 6ef6, guest PC 0x0c085574 */
if(!s->budget--) { s->failed_pc=0x0c085574u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c085576u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085576u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
