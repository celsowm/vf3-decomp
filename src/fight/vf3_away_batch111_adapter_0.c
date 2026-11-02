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
int vf3_away_batch111_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c03c72eu: goto P_0c03c72e;
case 0x0c03c730u: goto P_0c03c730;
case 0x0c03c732u: goto P_0c03c732;
case 0x0c03c734u: goto P_0c03c734;
case 0x0c03c736u: goto P_0c03c736;
case 0x0c03c738u: goto P_0c03c738;
case 0x0c03c73au: goto P_0c03c73a;
case 0x0c03c73cu: goto P_0c03c73c;
case 0x0c03c73eu: goto P_0c03c73e;
case 0x0c03c740u: goto P_0c03c740;
case 0x0c03c750u: goto P_0c03c750;
case 0x0c03c752u: goto P_0c03c752;
case 0x0c03c754u: goto P_0c03c754;
case 0x0c03c756u: goto P_0c03c756;
case 0x0c03c758u: goto P_0c03c758;
case 0x0c03c75au: goto P_0c03c75a;
case 0x0c03c75cu: goto P_0c03c75c;
case 0x0c03c75eu: goto P_0c03c75e;
case 0x0c03c760u: goto P_0c03c760;
case 0x0c03c762u: goto P_0c03c762;
case 0x0c03c764u: goto P_0c03c764;
case 0x0c03c766u: goto P_0c03c766;
case 0x0c03c768u: goto P_0c03c768;
case 0x0c03c76au: goto P_0c03c76a;
case 0x0c03c76cu: goto P_0c03c76c;
case 0x0c03c76eu: goto P_0c03c76e;
case 0x0c03c770u: goto P_0c03c770;
case 0x0c03c772u: goto P_0c03c772;
case 0x0c03c774u: goto P_0c03c774;
case 0x0c03c776u: goto P_0c03c776;
case 0x0c03c778u: goto P_0c03c778;
case 0x0c03c77au: goto P_0c03c77a;
case 0x0c03c77cu: goto P_0c03c77c;
case 0x0c03c77eu: goto P_0c03c77e;
case 0x0c03c780u: goto P_0c03c780;
case 0x0c03c782u: goto P_0c03c782;
case 0x0c03c784u: goto P_0c03c784;
case 0x0c03c786u: goto P_0c03c786;
case 0x0c03c788u: goto P_0c03c788;
case 0x0c03c78au: goto P_0c03c78a;
case 0x0c03c78cu: goto P_0c03c78c;
case 0x0c03c78eu: goto P_0c03c78e;
case 0x0c03c790u: goto P_0c03c790;
case 0x0c03c792u: goto P_0c03c792;
case 0x0c03c794u: goto P_0c03c794;
case 0x0c03c796u: goto P_0c03c796;
case 0x0c03c798u: goto P_0c03c798;
case 0x0c03c79au: goto P_0c03c79a;
case 0x0c03c79cu: goto P_0c03c79c;
case 0x0c03c79eu: goto P_0c03c79e;
case 0x0c03c7a0u: goto P_0c03c7a0;
case 0x0c03c7a2u: goto P_0c03c7a2;
case 0x0c03c7a4u: goto P_0c03c7a4;
case 0x0c03c7a6u: goto P_0c03c7a6;
case 0x0c03c7a8u: goto P_0c03c7a8;
case 0x0c03c7aau: goto P_0c03c7aa;
case 0x0c03c7acu: goto P_0c03c7ac;
case 0x0c03c7aeu: goto P_0c03c7ae;
case 0x0c03c7b0u: goto P_0c03c7b0;
case 0x0c03c7b2u: goto P_0c03c7b2;
case 0x0c03c7b4u: goto P_0c03c7b4;
case 0x0c03c7b6u: goto P_0c03c7b6;
case 0x0c03c7b8u: goto P_0c03c7b8;
case 0x0c03c7bau: goto P_0c03c7ba;
case 0x0c03c7bcu: goto P_0c03c7bc;
case 0x0c03c7beu: goto P_0c03c7be;
case 0x0c03c7c0u: goto P_0c03c7c0;
case 0x0c03c7c2u: goto P_0c03c7c2;
case 0x0c03c7c4u: goto P_0c03c7c4;
case 0x0c03c7c6u: goto P_0c03c7c6;
case 0x0c03c7c8u: goto P_0c03c7c8;
case 0x0c03c7cau: goto P_0c03c7ca;
case 0x0c03c7ccu: goto P_0c03c7cc;
case 0x0c03c7ceu: goto P_0c03c7ce;
case 0x0c03c7d0u: goto P_0c03c7d0;
case 0x0c03c7d2u: goto P_0c03c7d2;
case 0x0c03c7d4u: goto P_0c03c7d4;
case 0x0c03c7d6u: goto P_0c03c7d6;
case 0x0c03c7d8u: goto P_0c03c7d8;
case 0x0c03c7dau: goto P_0c03c7da;
case 0x0c03c7dcu: goto P_0c03c7dc;
case 0x0c03c7deu: goto P_0c03c7de;
case 0x0c03c7e0u: goto P_0c03c7e0;
case 0x0c03c7e2u: goto P_0c03c7e2;
case 0x0c03c7e4u: goto P_0c03c7e4;
case 0x0c03c7e6u: goto P_0c03c7e6;
case 0x0c03c7e8u: goto P_0c03c7e8;
case 0x0c03c7eau: goto P_0c03c7ea;
case 0x0c03c7ecu: goto P_0c03c7ec;
case 0x0c03c7eeu: goto P_0c03c7ee;
case 0x0c03c7f0u: goto P_0c03c7f0;
case 0x0c03c7f2u: goto P_0c03c7f2;
case 0x0c03c7f4u: goto P_0c03c7f4;
case 0x0c03c7f6u: goto P_0c03c7f6;
case 0x0c03c7f8u: goto P_0c03c7f8;
case 0x0c03c7fau: goto P_0c03c7fa;
case 0x0c03c7fcu: goto P_0c03c7fc;
case 0x0c03c7feu: goto P_0c03c7fe;
case 0x0c03c800u: goto P_0c03c800;
case 0x0c03c802u: goto P_0c03c802;
case 0x0c03c804u: goto P_0c03c804;
case 0x0c03c806u: goto P_0c03c806;
case 0x0c03c808u: goto P_0c03c808;
case 0x0c03c80au: goto P_0c03c80a;
case 0x0c03c80cu: goto P_0c03c80c;
case 0x0c03c80eu: goto P_0c03c80e;
case 0x0c03c810u: goto P_0c03c810;
case 0x0c03c812u: goto P_0c03c812;
case 0x0c03cac0u: goto P_0c03cac0;
case 0x0c03cac2u: goto P_0c03cac2;
case 0x0c03cac4u: goto P_0c03cac4;
case 0x0c03cac6u: goto P_0c03cac6;
case 0x0c03cac8u: goto P_0c03cac8;
case 0x0c03cacau: goto P_0c03caca;
case 0x0c03caccu: goto P_0c03cacc;
case 0x0c03caceu: goto P_0c03cace;
case 0x0c03cad0u: goto P_0c03cad0;
case 0x0c03cad2u: goto P_0c03cad2;
case 0x0c03cad4u: goto P_0c03cad4;
case 0x0c03cad6u: goto P_0c03cad6;
case 0x0c03cad8u: goto P_0c03cad8;
case 0x0c03cadau: goto P_0c03cada;
case 0x0c03cadcu: goto P_0c03cadc;
case 0x0c03cadeu: goto P_0c03cade;
case 0x0c03cae0u: goto P_0c03cae0;
case 0x0c03cae2u: goto P_0c03cae2;
case 0x0c03cae4u: goto P_0c03cae4;
case 0x0c03cae6u: goto P_0c03cae6;
case 0x0c03cae8u: goto P_0c03cae8;
case 0x0c03caeau: goto P_0c03caea;
case 0x0c03caecu: goto P_0c03caec;
case 0x0c03caeeu: goto P_0c03caee;
case 0x0c03caf0u: goto P_0c03caf0;
case 0x0c03caf2u: goto P_0c03caf2;
case 0x0c03caf4u: goto P_0c03caf4;
case 0x0c03caf6u: goto P_0c03caf6;
case 0x0c03caf8u: goto P_0c03caf8;
case 0x0c03cafau: goto P_0c03cafa;
case 0x0c03cafcu: goto P_0c03cafc;
case 0x0c03cb00u: goto P_0c03cb00;
case 0x0c03cb02u: goto P_0c03cb02;
case 0x0c03cb04u: goto P_0c03cb04;
case 0x0c03cb06u: goto P_0c03cb06;
case 0x0c03cb08u: goto P_0c03cb08;
case 0x0c03cb0au: goto P_0c03cb0a;
case 0x0c03cb0cu: goto P_0c03cb0c;
case 0x0c03cb0eu: goto P_0c03cb0e;
case 0x0c03cb10u: goto P_0c03cb10;
case 0x0c03cb12u: goto P_0c03cb12;
case 0x0c03cb14u: goto P_0c03cb14;
case 0x0c03cb16u: goto P_0c03cb16;
case 0x0c03cb18u: goto P_0c03cb18;
case 0x0c03cb1au: goto P_0c03cb1a;
case 0x0c03cb1cu: goto P_0c03cb1c;
case 0x0c03cb1eu: goto P_0c03cb1e;
case 0x0c03cb20u: goto P_0c03cb20;
case 0x0c03cb22u: goto P_0c03cb22;
case 0x0c03cb24u: goto P_0c03cb24;
case 0x0c03cb26u: goto P_0c03cb26;
case 0x0c03cb28u: goto P_0c03cb28;
case 0x0c03cb2au: goto P_0c03cb2a;
case 0x0c03cb2cu: goto P_0c03cb2c;
case 0x0c03cb2eu: goto P_0c03cb2e;
case 0x0c03cb30u: goto P_0c03cb30;
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
P_0c03c72e: /* original ff0b, guest PC 0x0c03c72e */
if(!s->budget--) { s->failed_pc=0x0c03c72eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03c730;
P_0c03c730: /* original d339, guest PC 0x0c03c730 */
if(!s->budget--) { s->failed_pc=0x0c03c730u; return 0; }
r[3]=read(ram,0x0c03c818u,4);
goto P_0c03c732;
P_0c03c732: /* original 430b, guest PC 0x0c03c732 */
if(!s->budget--) { s->failed_pc=0x0c03c732u; return 0; }
target=r[3];
r[16]=code_base|0x0c03c736u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03c736u) { target=s->pc; goto dispatch; }
goto P_0c03c736;
P_0c03c734: /* original 54f1, guest PC 0x0c03c734 */
if(!s->budget--) { s->failed_pc=0x0c03c734u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c03c736;
P_0c03c736: /* original 54f2, guest PC 0x0c03c736 */
if(!s->budget--) { s->failed_pc=0x0c03c736u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c03c738;
P_0c03c738: /* original f5f9, guest PC 0x0c03c738 */
if(!s->budget--) { s->failed_pc=0x0c03c738u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c73a;
P_0c03c73a: /* original f40c, guest PC 0x0c03c73a */
if(!s->budget--) { s->failed_pc=0x0c03c73au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03c73c;
P_0c03c73c: /* original 7f08, guest PC 0x0c03c73c */
if(!s->budget--) { s->failed_pc=0x0c03c73cu; return 0; }
r[15]+=0x00000008u;
goto P_0c03c73e;
P_0c03c73e: /* original a007, guest PC 0x0c03c73e */
if(!s->budget--) { s->failed_pc=0x0c03c73eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c750;
P_0c03c740: /* original 4f26, guest PC 0x0c03c740 */
if(!s->budget--) { s->failed_pc=0x0c03c740u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03c742u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c742u; return 0; } return 1;
P_0c03c750: /* original e004, guest PC 0x0c03c750 */
if(!s->budget--) { s->failed_pc=0x0c03c750u; return 0; }
r[0]=0x00000004u;
goto P_0c03c752;
P_0c03c752: /* original fffb, guest PC 0x0c03c752 */
if(!s->budget--) { s->failed_pc=0x0c03c752u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03c754;
P_0c03c754: /* original ffeb, guest PC 0x0c03c754 */
if(!s->budget--) { s->failed_pc=0x0c03c754u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03c756;
P_0c03c756: /* original ffdb, guest PC 0x0c03c756 */
if(!s->budget--) { s->failed_pc=0x0c03c756u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03c758;
P_0c03c758: /* original f99d, guest PC 0x0c03c758 */
if(!s->budget--) { s->failed_pc=0x0c03c758u; return 0; }
fr[9]=0x3f800000u;
goto P_0c03c75a;
P_0c03c75a: /* original fa9c, guest PC 0x0c03c75a */
if(!s->budget--) { s->failed_pc=0x0c03c75au; return 0; }
vf3_matrix_move(s,10,9);
goto P_0c03c75c;
P_0c03c75c: /* original fa51, guest PC 0x0c03c75c */
if(!s->budget--) { s->failed_pc=0x0c03c75cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'-');
goto P_0c03c75e;
P_0c03c75e: /* original f746, guest PC 0x0c03c75e */
if(!s->budget--) { s->failed_pc=0x0c03c75eu; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c03c760;
P_0c03c760: /* original e008, guest PC 0x0c03c760 */
if(!s->budget--) { s->failed_pc=0x0c03c760u; return 0; }
r[0]=0x00000008u;
goto P_0c03c762;
P_0c03c762: /* original f848, guest PC 0x0c03c762 */
if(!s->budget--) { s->failed_pc=0x0c03c762u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c03c764;
P_0c03c764: /* original f646, guest PC 0x0c03c764 */
if(!s->budget--) { s->failed_pc=0x0c03c764u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c03c766;
P_0c03c766: /* original f3ac, guest PC 0x0c03c766 */
if(!s->budget--) { s->failed_pc=0x0c03c766u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c03c768;
P_0c03c768: /* original fa72, guest PC 0x0c03c768 */
if(!s->budget--) { s->failed_pc=0x0c03c768u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'*');
goto P_0c03c76a;
P_0c03c76a: /* original f382, guest PC 0x0c03c76a */
if(!s->budget--) { s->failed_pc=0x0c03c76au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c03c76c;
P_0c03c76c: /* original 4f22, guest PC 0x0c03c76c */
if(!s->budget--) { s->failed_pc=0x0c03c76cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03c76e;
P_0c03c76e: /* original 7fbc, guest PC 0x0c03c76e */
if(!s->budget--) { s->failed_pc=0x0c03c76eu; return 0; }
r[15]+=0xffffffbcu;
goto P_0c03c770;
P_0c03c770: /* original ff3a, guest PC 0x0c03c770 */
if(!s->budget--) { s->failed_pc=0x0c03c770u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c03c772;
P_0c03c772: /* original fdac, guest PC 0x0c03c772 */
if(!s->budget--) { s->failed_pc=0x0c03c772u; return 0; }
vf3_matrix_move(s,13,10);
goto P_0c03c774;
P_0c03c774: /* original fd62, guest PC 0x0c03c774 */
if(!s->budget--) { s->failed_pc=0x0c03c774u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[6],r[18],'*');
goto P_0c03c776;
P_0c03c776: /* original fa3c, guest PC 0x0c03c776 */
if(!s->budget--) { s->failed_pc=0x0c03c776u; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c03c778;
P_0c03c778: /* original fa62, guest PC 0x0c03c778 */
if(!s->budget--) { s->failed_pc=0x0c03c778u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[6],r[18],'*');
goto P_0c03c77a;
P_0c03c77a: /* original fe4c, guest PC 0x0c03c77a */
if(!s->budget--) { s->failed_pc=0x0c03c77au; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c03c77c;
P_0c03c77c: /* original fe82, guest PC 0x0c03c77c */
if(!s->budget--) { s->failed_pc=0x0c03c77cu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[8],r[18],'*');
goto P_0c03c77e;
P_0c03c77e: /* original ff4c, guest PC 0x0c03c77e */
if(!s->budget--) { s->failed_pc=0x0c03c77eu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c03c780;
P_0c03c780: /* original f462, guest PC 0x0c03c780 */
if(!s->budget--) { s->failed_pc=0x0c03c780u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c03c782;
P_0c03c782: /* original fb3c, guest PC 0x0c03c782 */
if(!s->budget--) { s->failed_pc=0x0c03c782u; return 0; }
vf3_matrix_move(s,11,3);
goto P_0c03c784;
P_0c03c784: /* original ff72, guest PC 0x0c03c784 */
if(!s->budget--) { s->failed_pc=0x0c03c784u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[7],r[18],'*');
goto P_0c03c786;
P_0c03c786: /* original fb72, guest PC 0x0c03c786 */
if(!s->budget--) { s->failed_pc=0x0c03c786u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'*');
goto P_0c03c788;
P_0c03c788: /* original f29c, guest PC 0x0c03c788 */
if(!s->budget--) { s->failed_pc=0x0c03c788u; return 0; }
vf3_matrix_move(s,2,9);
goto P_0c03c78a;
P_0c03c78a: /* original f882, guest PC 0x0c03c78a */
if(!s->budget--) { s->failed_pc=0x0c03c78au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[8],r[18],'*');
goto P_0c03c78c;
P_0c03c78c: /* original f772, guest PC 0x0c03c78c */
if(!s->budget--) { s->failed_pc=0x0c03c78cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'*');
goto P_0c03c78e;
P_0c03c78e: /* original f662, guest PC 0x0c03c78e */
if(!s->budget--) { s->failed_pc=0x0c03c78eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[6],r[18],'*');
goto P_0c03c790;
P_0c03c790: /* original f281, guest PC 0x0c03c790 */
if(!s->budget--) { s->failed_pc=0x0c03c790u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'-');
goto P_0c03c792;
P_0c03c792: /* original f05c, guest PC 0x0c03c792 */
if(!s->budget--) { s->failed_pc=0x0c03c792u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03c794;
P_0c03c794: /* original f18c, guest PC 0x0c03c794 */
if(!s->budget--) { s->failed_pc=0x0c03c794u; return 0; }
vf3_matrix_move(s,1,8);
goto P_0c03c796;
P_0c03c796: /* original e004, guest PC 0x0c03c796 */
if(!s->budget--) { s->failed_pc=0x0c03c796u; return 0; }
r[0]=0x00000004u;
goto P_0c03c798;
P_0c03c798: /* original f12e, guest PC 0x0c03c798 */
if(!s->budget--) { s->failed_pc=0x0c03c798u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[2],fr[1],r[18]);
goto P_0c03c79a;
P_0c03c79a: /* original ff17, guest PC 0x0c03c79a */
if(!s->budget--) { s->failed_pc=0x0c03c79au; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c03c79c;
P_0c03c79c: /* original e008, guest PC 0x0c03c79c */
if(!s->budget--) { s->failed_pc=0x0c03c79cu; return 0; }
r[0]=0x00000008u;
goto P_0c03c79e;
P_0c03c79e: /* original f34c, guest PC 0x0c03c79e */
if(!s->budget--) { s->failed_pc=0x0c03c79eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03c7a0;
P_0c03c7a0: /* original f3b0, guest PC 0x0c03c7a0 */
if(!s->budget--) { s->failed_pc=0x0c03c7a0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'+');
goto P_0c03c7a2;
P_0c03c7a2: /* original fb41, guest PC 0x0c03c7a2 */
if(!s->budget--) { s->failed_pc=0x0c03c7a2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[4],r[18],'-');
goto P_0c03c7a4;
P_0c03c7a4: /* original ff37, guest PC 0x0c03c7a4 */
if(!s->budget--) { s->failed_pc=0x0c03c7a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c7a6;
P_0c03c7a6: /* original e00c, guest PC 0x0c03c7a6 */
if(!s->budget--) { s->failed_pc=0x0c03c7a6u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c7a8;
P_0c03c7a8: /* original f3ac, guest PC 0x0c03c7a8 */
if(!s->budget--) { s->failed_pc=0x0c03c7a8u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c03c7aa;
P_0c03c7aa: /* original f3f1, guest PC 0x0c03c7aa */
if(!s->budget--) { s->failed_pc=0x0c03c7aau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'-');
goto P_0c03c7ac;
P_0c03c7ac: /* original ffa0, guest PC 0x0c03c7ac */
if(!s->budget--) { s->failed_pc=0x0c03c7acu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[10],r[18],'+');
goto P_0c03c7ae;
P_0c03c7ae: /* original ff37, guest PC 0x0c03c7ae */
if(!s->budget--) { s->failed_pc=0x0c03c7aeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c7b0;
P_0c03c7b0: /* original e014, guest PC 0x0c03c7b0 */
if(!s->budget--) { s->failed_pc=0x0c03c7b0u; return 0; }
r[0]=0x00000014u;
goto P_0c03c7b2;
P_0c03c7b2: /* original ffb7, guest PC 0x0c03c7b2 */
if(!s->budget--) { s->failed_pc=0x0c03c7b2u; return 0; }
vf3_matrix_store(s,ram,11,r[15]+r[0]);
goto P_0c03c7b4;
P_0c03c7b4: /* original e018, guest PC 0x0c03c7b4 */
if(!s->budget--) { s->failed_pc=0x0c03c7b4u; return 0; }
r[0]=0x00000018u;
goto P_0c03c7b6;
P_0c03c7b6: /* original f39c, guest PC 0x0c03c7b6 */
if(!s->budget--) { s->failed_pc=0x0c03c7b6u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c03c7b8;
P_0c03c7b8: /* original f371, guest PC 0x0c03c7b8 */
if(!s->budget--) { s->failed_pc=0x0c03c7b8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'-');
goto P_0c03c7ba;
P_0c03c7ba: /* original f27c, guest PC 0x0c03c7ba */
if(!s->budget--) { s->failed_pc=0x0c03c7bau; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c03c7bc;
P_0c03c7bc: /* original f23e, guest PC 0x0c03c7bc */
if(!s->budget--) { s->failed_pc=0x0c03c7bcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c03c7be;
P_0c03c7be: /* original ff27, guest PC 0x0c03c7be */
if(!s->budget--) { s->failed_pc=0x0c03c7beu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03c7c0;
P_0c03c7c0: /* original e01c, guest PC 0x0c03c7c0 */
if(!s->budget--) { s->failed_pc=0x0c03c7c0u; return 0; }
r[0]=0x0000001cu;
goto P_0c03c7c2;
P_0c03c7c2: /* original f3ec, guest PC 0x0c03c7c2 */
if(!s->budget--) { s->failed_pc=0x0c03c7c2u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c03c7c4;
P_0c03c7c4: /* original f3d0, guest PC 0x0c03c7c4 */
if(!s->budget--) { s->failed_pc=0x0c03c7c4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'+');
goto P_0c03c7c6;
P_0c03c7c6: /* original fde1, guest PC 0x0c03c7c6 */
if(!s->budget--) { s->failed_pc=0x0c03c7c6u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c03c7c8;
P_0c03c7c8: /* original ff37, guest PC 0x0c03c7c8 */
if(!s->budget--) { s->failed_pc=0x0c03c7c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c7ca;
P_0c03c7ca: /* original e024, guest PC 0x0c03c7ca */
if(!s->budget--) { s->failed_pc=0x0c03c7cau; return 0; }
r[0]=0x00000024u;
goto P_0c03c7cc;
P_0c03c7cc: /* original fff7, guest PC 0x0c03c7cc */
if(!s->budget--) { s->failed_pc=0x0c03c7ccu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03c7ce;
P_0c03c7ce: /* original e028, guest PC 0x0c03c7ce */
if(!s->budget--) { s->failed_pc=0x0c03c7ceu; return 0; }
r[0]=0x00000028u;
goto P_0c03c7d0;
P_0c03c7d0: /* original ffd7, guest PC 0x0c03c7d0 */
if(!s->budget--) { s->failed_pc=0x0c03c7d0u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c03c7d2;
P_0c03c7d2: /* original e02c, guest PC 0x0c03c7d2 */
if(!s->budget--) { s->failed_pc=0x0c03c7d2u; return 0; }
r[0]=0x0000002cu;
goto P_0c03c7d4;
P_0c03c7d4: /* original f39c, guest PC 0x0c03c7d4 */
if(!s->budget--) { s->failed_pc=0x0c03c7d4u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c03c7d6;
P_0c03c7d6: /* original f361, guest PC 0x0c03c7d6 */
if(!s->budget--) { s->failed_pc=0x0c03c7d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c03c7d8;
P_0c03c7d8: /* original f26c, guest PC 0x0c03c7d8 */
if(!s->budget--) { s->failed_pc=0x0c03c7d8u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c03c7da;
P_0c03c7da: /* original 64f3, guest PC 0x0c03c7da */
if(!s->budget--) { s->failed_pc=0x0c03c7dau; return 0; }
r[4]=r[15];
goto P_0c03c7dc;
P_0c03c7dc: /* original 7404, guest PC 0x0c03c7dc */
if(!s->budget--) { s->failed_pc=0x0c03c7dcu; return 0; }
r[4]+=0x00000004u;
goto P_0c03c7de;
P_0c03c7de: /* original f23e, guest PC 0x0c03c7de */
if(!s->budget--) { s->failed_pc=0x0c03c7deu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c03c7e0;
P_0c03c7e0: /* original ff27, guest PC 0x0c03c7e0 */
if(!s->budget--) { s->failed_pc=0x0c03c7e0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03c7e2;
P_0c03c7e2: /* original e038, guest PC 0x0c03c7e2 */
if(!s->budget--) { s->failed_pc=0x0c03c7e2u; return 0; }
r[0]=0x00000038u;
goto P_0c03c7e4;
P_0c03c7e4: /* original f38d, guest PC 0x0c03c7e4 */
if(!s->budget--) { s->failed_pc=0x0c03c7e4u; return 0; }
fr[3]=0;
goto P_0c03c7e6;
P_0c03c7e6: /* original f437, guest PC 0x0c03c7e6 */
if(!s->budget--) { s->failed_pc=0x0c03c7e6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7e8;
P_0c03c7e8: /* original e034, guest PC 0x0c03c7e8 */
if(!s->budget--) { s->failed_pc=0x0c03c7e8u; return 0; }
r[0]=0x00000034u;
goto P_0c03c7ea;
P_0c03c7ea: /* original f437, guest PC 0x0c03c7ea */
if(!s->budget--) { s->failed_pc=0x0c03c7eau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7ec;
P_0c03c7ec: /* original e030, guest PC 0x0c03c7ec */
if(!s->budget--) { s->failed_pc=0x0c03c7ecu; return 0; }
r[0]=0x00000030u;
goto P_0c03c7ee;
P_0c03c7ee: /* original f437, guest PC 0x0c03c7ee */
if(!s->budget--) { s->failed_pc=0x0c03c7eeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7f0;
P_0c03c7f0: /* original e02c, guest PC 0x0c03c7f0 */
if(!s->budget--) { s->failed_pc=0x0c03c7f0u; return 0; }
r[0]=0x0000002cu;
goto P_0c03c7f2;
P_0c03c7f2: /* original f437, guest PC 0x0c03c7f2 */
if(!s->budget--) { s->failed_pc=0x0c03c7f2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7f4;
P_0c03c7f4: /* original e01c, guest PC 0x0c03c7f4 */
if(!s->budget--) { s->failed_pc=0x0c03c7f4u; return 0; }
r[0]=0x0000001cu;
goto P_0c03c7f6;
P_0c03c7f6: /* original f437, guest PC 0x0c03c7f6 */
if(!s->budget--) { s->failed_pc=0x0c03c7f6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7f8;
P_0c03c7f8: /* original e00c, guest PC 0x0c03c7f8 */
if(!s->budget--) { s->failed_pc=0x0c03c7f8u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c7fa;
P_0c03c7fa: /* original f437, guest PC 0x0c03c7fa */
if(!s->budget--) { s->failed_pc=0x0c03c7fau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7fc;
P_0c03c7fc: /* original e040, guest PC 0x0c03c7fc */
if(!s->budget--) { s->failed_pc=0x0c03c7fcu; return 0; }
r[0]=0x00000040u;
goto P_0c03c7fe;
P_0c03c7fe: /* original 64f3, guest PC 0x0c03c7fe */
if(!s->budget--) { s->failed_pc=0x0c03c7feu; return 0; }
r[4]=r[15];
goto P_0c03c800;
P_0c03c800: /* original ff97, guest PC 0x0c03c800 */
if(!s->budget--) { s->failed_pc=0x0c03c800u; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c03c802;
P_0c03c802: /* original d306, guest PC 0x0c03c802 */
if(!s->budget--) { s->failed_pc=0x0c03c802u; return 0; }
r[3]=read(ram,0x0c03c81cu,4);
goto P_0c03c804;
P_0c03c804: /* original 430b, guest PC 0x0c03c804 */
if(!s->budget--) { s->failed_pc=0x0c03c804u; return 0; }
target=r[3];
r[16]=code_base|0x0c03c808u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03c808u) { target=s->pc; goto dispatch; }
goto P_0c03c808;
P_0c03c806: /* original 7404, guest PC 0x0c03c806 */
if(!s->budget--) { s->failed_pc=0x0c03c806u; return 0; }
r[4]+=0x00000004u;
goto P_0c03c808;
P_0c03c808: /* original 7f44, guest PC 0x0c03c808 */
if(!s->budget--) { s->failed_pc=0x0c03c808u; return 0; }
r[15]+=0x00000044u;
goto P_0c03c80a;
P_0c03c80a: /* original 4f26, guest PC 0x0c03c80a */
if(!s->budget--) { s->failed_pc=0x0c03c80au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c80c;
P_0c03c80c: /* original fdf9, guest PC 0x0c03c80c */
if(!s->budget--) { s->failed_pc=0x0c03c80cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c80e;
P_0c03c80e: /* original fef9, guest PC 0x0c03c80e */
if(!s->budget--) { s->failed_pc=0x0c03c80eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c810;
P_0c03c810: /* original 000b, guest PC 0x0c03c810 */
if(!s->budget--) { s->failed_pc=0x0c03c810u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c03c812: /* original fff9, guest PC 0x0c03c812 */
if(!s->budget--) { s->failed_pc=0x0c03c812u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c03c814u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c814u; return 0; } return 1;
P_0c03cac0: /* original 2fe6, guest PC 0x0c03cac0 */
if(!s->budget--) { s->failed_pc=0x0c03cac0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03cac2;
P_0c03cac2: /* original 6e43, guest PC 0x0c03cac2 */
if(!s->budget--) { s->failed_pc=0x0c03cac2u; return 0; }
r[14]=r[4];
goto P_0c03cac4;
P_0c03cac4: /* original fffb, guest PC 0x0c03cac4 */
if(!s->budget--) { s->failed_pc=0x0c03cac4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03cac6;
P_0c03cac6: /* original 4f22, guest PC 0x0c03cac6 */
if(!s->budget--) { s->failed_pc=0x0c03cac6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03cac8;
P_0c03cac8: /* original 7ff0, guest PC 0x0c03cac8 */
if(!s->budget--) { s->failed_pc=0x0c03cac8u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03caca;
P_0c03caca: /* original 66f3, guest PC 0x0c03caca */
if(!s->budget--) { s->failed_pc=0x0c03cacau; return 0; }
r[6]=r[15];
goto P_0c03cacc;
P_0c03cacc: /* original 7604, guest PC 0x0c03cacc */
if(!s->budget--) { s->failed_pc=0x0c03caccu; return 0; }
r[6]+=0x00000004u;
goto P_0c03cace;
P_0c03cace: /* original 2f52, guest PC 0x0c03cace */
if(!s->budget--) { s->failed_pc=0x0c03caceu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03cad0;
P_0c03cad0: /* original d320, guest PC 0x0c03cad0 */
if(!s->budget--) { s->failed_pc=0x0c03cad0u; return 0; }
r[3]=read(ram,0x0c03cb54u,4);
goto P_0c03cad2;
P_0c03cad2: /* original 430b, guest PC 0x0c03cad2 */
if(!s->budget--) { s->failed_pc=0x0c03cad2u; return 0; }
target=r[3];
r[16]=code_base|0x0c03cad6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cad6u) { target=s->pc; goto dispatch; }
goto P_0c03cad6;
P_0c03cad4: /* original 64e3, guest PC 0x0c03cad4 */
if(!s->budget--) { s->failed_pc=0x0c03cad4u; return 0; }
r[4]=r[14];
goto P_0c03cad6;
P_0c03cad6: /* original d220, guest PC 0x0c03cad6 */
if(!s->budget--) { s->failed_pc=0x0c03cad6u; return 0; }
r[2]=read(ram,0x0c03cb58u,4);
goto P_0c03cad8;
P_0c03cad8: /* original 64f3, guest PC 0x0c03cad8 */
if(!s->budget--) { s->failed_pc=0x0c03cad8u; return 0; }
r[4]=r[15];
goto P_0c03cada;
P_0c03cada: /* original 420b, guest PC 0x0c03cada */
if(!s->budget--) { s->failed_pc=0x0c03cadau; return 0; }
target=r[2];
r[16]=code_base|0x0c03cadeu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cadeu) { target=s->pc; goto dispatch; }
goto P_0c03cade;
P_0c03cadc: /* original 7404, guest PC 0x0c03cadc */
if(!s->budget--) { s->failed_pc=0x0c03cadcu; return 0; }
r[4]+=0x00000004u;
goto P_0c03cade;
P_0c03cade: /* original d31f, guest PC 0x0c03cade */
if(!s->budget--) { s->failed_pc=0x0c03cadeu; return 0; }
r[3]=read(ram,0x0c03cb5cu,4);
goto P_0c03cae0;
P_0c03cae0: /* original 65f2, guest PC 0x0c03cae0 */
if(!s->budget--) { s->failed_pc=0x0c03cae0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03cae2;
P_0c03cae2: /* original ff0c, guest PC 0x0c03cae2 */
if(!s->budget--) { s->failed_pc=0x0c03cae2u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c03cae4;
P_0c03cae4: /* original 430b, guest PC 0x0c03cae4 */
if(!s->budget--) { s->failed_pc=0x0c03cae4u; return 0; }
target=r[3];
r[16]=code_base|0x0c03cae8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cae8u) { target=s->pc; goto dispatch; }
goto P_0c03cae8;
P_0c03cae6: /* original 64e3, guest PC 0x0c03cae6 */
if(!s->budget--) { s->failed_pc=0x0c03cae6u; return 0; }
r[4]=r[14];
goto P_0c03cae8;
P_0c03cae8: /* original f38d, guest PC 0x0c03cae8 */
if(!s->budget--) { s->failed_pc=0x0c03cae8u; return 0; }
fr[3]=0;
goto P_0c03caea;
P_0c03caea: /* original ff34, guest PC 0x0c03caea */
if(!s->budget--) { s->failed_pc=0x0c03caeau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c03caec;
P_0c03caec: /* original 8d08, guest PC 0x0c03caec */
if(!s->budget--) { s->failed_pc=0x0c03caecu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,0);
if(cond) { goto P_0c03cb00; }
goto P_0c03caf0;
P_0c03caee: /* original f50c, guest PC 0x0c03caee */
if(!s->budget--) { s->failed_pc=0x0c03caeeu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c03caf0;
P_0c03caf0: /* original d21b, guest PC 0x0c03caf0 */
if(!s->budget--) { s->failed_pc=0x0c03caf0u; return 0; }
r[2]=read(ram,0x0c03cb60u,4);
goto P_0c03caf2;
P_0c03caf2: /* original 64f3, guest PC 0x0c03caf2 */
if(!s->budget--) { s->failed_pc=0x0c03caf2u; return 0; }
r[4]=r[15];
goto P_0c03caf4;
P_0c03caf4: /* original f4fc, guest PC 0x0c03caf4 */
if(!s->budget--) { s->failed_pc=0x0c03caf4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c03caf6;
P_0c03caf6: /* original 420b, guest PC 0x0c03caf6 */
if(!s->budget--) { s->failed_pc=0x0c03caf6u; return 0; }
target=r[2];
r[16]=code_base|0x0c03cafau;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cafau) { target=s->pc; goto dispatch; }
goto P_0c03cafa;
P_0c03caf8: /* original 7404, guest PC 0x0c03caf8 */
if(!s->budget--) { s->failed_pc=0x0c03caf8u; return 0; }
r[4]+=0x00000004u;
goto P_0c03cafa;
P_0c03cafa: /* original a015, guest PC 0x0c03cafa */
if(!s->budget--) { s->failed_pc=0x0c03cafau; return 0; }
goto P_0c03cb28;
P_0c03cafc: /* original 0009, guest PC 0x0c03cafc */
if(!s->budget--) { s->failed_pc=0x0c03cafcu; return 0; }
if(!vf3_matrix_family(0x0c03cafeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cafeu; return 0; } return 1;
P_0c03cb00: /* original f355, guest PC 0x0c03cb00 */
if(!s->budget--) { s->failed_pc=0x0c03cb00u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c03cb02;
P_0c03cb02: /* original 8b11, guest PC 0x0c03cb02 */
if(!s->budget--) { s->failed_pc=0x0c03cb02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03cb28; }
goto P_0c03cb04;
P_0c03cb04: /* original e004, guest PC 0x0c03cb04 */
if(!s->budget--) { s->failed_pc=0x0c03cb04u; return 0; }
r[0]=0x00000004u;
goto P_0c03cb06;
P_0c03cb06: /* original 64f3, guest PC 0x0c03cb06 */
if(!s->budget--) { s->failed_pc=0x0c03cb06u; return 0; }
r[4]=r[15];
goto P_0c03cb08;
P_0c03cb08: /* original f3e6, guest PC 0x0c03cb08 */
if(!s->budget--) { s->failed_pc=0x0c03cb08u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03cb0a;
P_0c03cb0a: /* original e004, guest PC 0x0c03cb0a */
if(!s->budget--) { s->failed_pc=0x0c03cb0au; return 0; }
r[0]=0x00000004u;
goto P_0c03cb0c;
P_0c03cb0c: /* original ff37, guest PC 0x0c03cb0c */
if(!s->budget--) { s->failed_pc=0x0c03cb0cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03cb0e;
P_0c03cb0e: /* original e008, guest PC 0x0c03cb0e */
if(!s->budget--) { s->failed_pc=0x0c03cb0eu; return 0; }
r[0]=0x00000008u;
goto P_0c03cb10;
P_0c03cb10: /* original f3e6, guest PC 0x0c03cb10 */
if(!s->budget--) { s->failed_pc=0x0c03cb10u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03cb12;
P_0c03cb12: /* original e008, guest PC 0x0c03cb12 */
if(!s->budget--) { s->failed_pc=0x0c03cb12u; return 0; }
r[0]=0x00000008u;
goto P_0c03cb14;
P_0c03cb14: /* original ff37, guest PC 0x0c03cb14 */
if(!s->budget--) { s->failed_pc=0x0c03cb14u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03cb16;
P_0c03cb16: /* original e00c, guest PC 0x0c03cb16 */
if(!s->budget--) { s->failed_pc=0x0c03cb16u; return 0; }
r[0]=0x0000000cu;
goto P_0c03cb18;
P_0c03cb18: /* original f3e8, guest PC 0x0c03cb18 */
if(!s->budget--) { s->failed_pc=0x0c03cb18u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c03cb1a;
P_0c03cb1a: /* original ff37, guest PC 0x0c03cb1a */
if(!s->budget--) { s->failed_pc=0x0c03cb1au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03cb1c;
P_0c03cb1c: /* original c711, guest PC 0x0c03cb1c */
if(!s->budget--) { s->failed_pc=0x0c03cb1cu; return 0; }
r[0]=code_base|0x0003cb64u;
goto P_0c03cb1e;
P_0c03cb1e: /* original d310, guest PC 0x0c03cb1e */
if(!s->budget--) { s->failed_pc=0x0c03cb1eu; return 0; }
r[3]=read(ram,0x0c03cb60u,4);
goto P_0c03cb20;
P_0c03cb20: /* original f508, guest PC 0x0c03cb20 */
if(!s->budget--) { s->failed_pc=0x0c03cb20u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03cb22;
P_0c03cb22: /* original f48d, guest PC 0x0c03cb22 */
if(!s->budget--) { s->failed_pc=0x0c03cb22u; return 0; }
fr[4]=0;
goto P_0c03cb24;
P_0c03cb24: /* original 430b, guest PC 0x0c03cb24 */
if(!s->budget--) { s->failed_pc=0x0c03cb24u; return 0; }
target=r[3];
r[16]=code_base|0x0c03cb28u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cb28u) { target=s->pc; goto dispatch; }
goto P_0c03cb28;
P_0c03cb26: /* original 7404, guest PC 0x0c03cb26 */
if(!s->budget--) { s->failed_pc=0x0c03cb26u; return 0; }
r[4]+=0x00000004u;
goto P_0c03cb28;
P_0c03cb28: /* original 7f10, guest PC 0x0c03cb28 */
if(!s->budget--) { s->failed_pc=0x0c03cb28u; return 0; }
r[15]+=0x00000010u;
goto P_0c03cb2a;
P_0c03cb2a: /* original 4f26, guest PC 0x0c03cb2a */
if(!s->budget--) { s->failed_pc=0x0c03cb2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03cb2c;
P_0c03cb2c: /* original fff9, guest PC 0x0c03cb2c */
if(!s->budget--) { s->failed_pc=0x0c03cb2cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03cb2e;
P_0c03cb2e: /* original 000b, guest PC 0x0c03cb2e */
if(!s->budget--) { s->failed_pc=0x0c03cb2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03cb30: /* original 6ef6, guest PC 0x0c03cb30 */
if(!s->budget--) { s->failed_pc=0x0c03cb30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03cb32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cb32u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
