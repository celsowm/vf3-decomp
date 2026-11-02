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
int vf3_away_batch42_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0cb67au: goto P_0c0cb67a;
case 0x0c0cb67cu: goto P_0c0cb67c;
case 0x0c0cb67eu: goto P_0c0cb67e;
case 0x0c0cb680u: goto P_0c0cb680;
case 0x0c0cb682u: goto P_0c0cb682;
case 0x0c0cb684u: goto P_0c0cb684;
case 0x0c0cb686u: goto P_0c0cb686;
case 0x0c0cb688u: goto P_0c0cb688;
case 0x0c0cb68au: goto P_0c0cb68a;
case 0x0c0cb68cu: goto P_0c0cb68c;
case 0x0c0cb68eu: goto P_0c0cb68e;
case 0x0c0cb690u: goto P_0c0cb690;
case 0x0c0cb692u: goto P_0c0cb692;
case 0x0c0cb694u: goto P_0c0cb694;
case 0x0c0cb696u: goto P_0c0cb696;
case 0x0c0cb698u: goto P_0c0cb698;
case 0x0c0cb69au: goto P_0c0cb69a;
case 0x0c0cb69cu: goto P_0c0cb69c;
case 0x0c0cb69eu: goto P_0c0cb69e;
case 0x0c0cb6a0u: goto P_0c0cb6a0;
case 0x0c0cb6a2u: goto P_0c0cb6a2;
case 0x0c0cb6a4u: goto P_0c0cb6a4;
case 0x0c0cb6a6u: goto P_0c0cb6a6;
case 0x0c0cb6a8u: goto P_0c0cb6a8;
case 0x0c0cb6d4u: goto P_0c0cb6d4;
case 0x0c0cb6d6u: goto P_0c0cb6d6;
case 0x0c0cb6d8u: goto P_0c0cb6d8;
case 0x0c0cb6dau: goto P_0c0cb6da;
case 0x0c0cb6dcu: goto P_0c0cb6dc;
case 0x0c0cb6deu: goto P_0c0cb6de;
case 0x0c0cb6e0u: goto P_0c0cb6e0;
case 0x0c0cb6e2u: goto P_0c0cb6e2;
case 0x0c0cb6e4u: goto P_0c0cb6e4;
case 0x0c0cb6e6u: goto P_0c0cb6e6;
case 0x0c0cb6e8u: goto P_0c0cb6e8;
case 0x0c0cb6eau: goto P_0c0cb6ea;
case 0x0c0cb6ecu: goto P_0c0cb6ec;
case 0x0c0cb6eeu: goto P_0c0cb6ee;
case 0x0c0cb6f0u: goto P_0c0cb6f0;
case 0x0c0cb6f2u: goto P_0c0cb6f2;
case 0x0c0cb6f4u: goto P_0c0cb6f4;
case 0x0c0cb6f6u: goto P_0c0cb6f6;
case 0x0c0cb6f8u: goto P_0c0cb6f8;
case 0x0c0cb6fau: goto P_0c0cb6fa;
case 0x0c0cb6fcu: goto P_0c0cb6fc;
case 0x0c0cb6feu: goto P_0c0cb6fe;
case 0x0c0cb700u: goto P_0c0cb700;
case 0x0c0cb702u: goto P_0c0cb702;
case 0x0c0cb704u: goto P_0c0cb704;
case 0x0c0cb706u: goto P_0c0cb706;
case 0x0c0cb708u: goto P_0c0cb708;
case 0x0c0cb70au: goto P_0c0cb70a;
case 0x0c0cb70cu: goto P_0c0cb70c;
case 0x0c0cb70eu: goto P_0c0cb70e;
case 0x0c0cb710u: goto P_0c0cb710;
case 0x0c0cb712u: goto P_0c0cb712;
case 0x0c0cb714u: goto P_0c0cb714;
case 0x0c0cb716u: goto P_0c0cb716;
case 0x0c0cb718u: goto P_0c0cb718;
case 0x0c0cb71au: goto P_0c0cb71a;
case 0x0c0cb71cu: goto P_0c0cb71c;
case 0x0c0cb71eu: goto P_0c0cb71e;
case 0x0c0cb720u: goto P_0c0cb720;
case 0x0c0cb722u: goto P_0c0cb722;
case 0x0c0cb724u: goto P_0c0cb724;
case 0x0c0cb726u: goto P_0c0cb726;
case 0x0c0cb728u: goto P_0c0cb728;
case 0x0c0cb72au: goto P_0c0cb72a;
case 0x0c0cb72cu: goto P_0c0cb72c;
case 0x0c0cb72eu: goto P_0c0cb72e;
case 0x0c0cb730u: goto P_0c0cb730;
case 0x0c0cb732u: goto P_0c0cb732;
case 0x0c0cb734u: goto P_0c0cb734;
case 0x0c0cb736u: goto P_0c0cb736;
case 0x0c0cb738u: goto P_0c0cb738;
case 0x0c0cb73au: goto P_0c0cb73a;
case 0x0c0cb73cu: goto P_0c0cb73c;
case 0x0c0cb73eu: goto P_0c0cb73e;
case 0x0c0cb740u: goto P_0c0cb740;
case 0x0c0cb742u: goto P_0c0cb742;
case 0x0c0cb744u: goto P_0c0cb744;
case 0x0c0cb746u: goto P_0c0cb746;
case 0x0c0cb748u: goto P_0c0cb748;
case 0x0c0cb74au: goto P_0c0cb74a;
case 0x0c0cb74cu: goto P_0c0cb74c;
case 0x0c0cb74eu: goto P_0c0cb74e;
case 0x0c0cb750u: goto P_0c0cb750;
case 0x0c0cb752u: goto P_0c0cb752;
case 0x0c0cb754u: goto P_0c0cb754;
case 0x0c0cb756u: goto P_0c0cb756;
case 0x0c0cb758u: goto P_0c0cb758;
case 0x0c0cb75au: goto P_0c0cb75a;
case 0x0c0cb75cu: goto P_0c0cb75c;
case 0x0c0cb75eu: goto P_0c0cb75e;
case 0x0c0cb760u: goto P_0c0cb760;
case 0x0c0cb762u: goto P_0c0cb762;
case 0x0c0cb764u: goto P_0c0cb764;
case 0x0c0cb766u: goto P_0c0cb766;
case 0x0c0cb768u: goto P_0c0cb768;
case 0x0c0cb76au: goto P_0c0cb76a;
case 0x0c0cb76cu: goto P_0c0cb76c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0cb67a: /* original 2fd6, guest PC 0x0c0cb67a */
if(!s->budget--) { s->failed_pc=0x0c0cb67au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb67c;
P_0c0cb67c: /* original 2fc6, guest PC 0x0c0cb67c */
if(!s->budget--) { s->failed_pc=0x0c0cb67cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb67e;
P_0c0cb67e: /* original ec04, guest PC 0x0c0cb67e */
if(!s->budget--) { s->failed_pc=0x0c0cb67eu; return 0; }
r[12]=0x00000004u;
goto P_0c0cb680;
P_0c0cb680: /* original 2fb6, guest PC 0x0c0cb680 */
if(!s->budget--) { s->failed_pc=0x0c0cb680u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb682;
P_0c0cb682: /* original eb06, guest PC 0x0c0cb682 */
if(!s->budget--) { s->failed_pc=0x0c0cb682u; return 0; }
r[11]=0x00000006u;
goto P_0c0cb684;
P_0c0cb684: /* original 2fa6, guest PC 0x0c0cb684 */
if(!s->budget--) { s->failed_pc=0x0c0cb684u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb686;
P_0c0cb686: /* original 65b3, guest PC 0x0c0cb686 */
if(!s->budget--) { s->failed_pc=0x0c0cb686u; return 0; }
r[5]=r[11];
goto P_0c0cb688;
P_0c0cb688: /* original 2f96, guest PC 0x0c0cb688 */
if(!s->budget--) { s->failed_pc=0x0c0cb688u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb68a;
P_0c0cb68a: /* original 9011, guest PC 0x0c0cb68a */
if(!s->budget--) { s->failed_pc=0x0c0cb68au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6b0u,2);
goto P_0c0cb68c;
P_0c0cb68c: /* original 9712, guest PC 0x0c0cb68c */
if(!s->budget--) { s->failed_pc=0x0c0cb68cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6b4u,2);
goto P_0c0cb68e;
P_0c0cb68e: /* original 094e, guest PC 0x0c0cb68e */
if(!s->budget--) { s->failed_pc=0x0c0cb68eu; return 0; }
r[9]=read(ram,r[4]+r[0],4);
goto P_0c0cb690;
P_0c0cb690: /* original c70d, guest PC 0x0c0cb690 */
if(!s->budget--) { s->failed_pc=0x0c0cb690u; return 0; }
r[0]=code_base|0x000cb6c8u;
goto P_0c0cb692;
P_0c0cb692: /* original fa08, guest PC 0x0c0cb692 */
if(!s->budget--) { s->failed_pc=0x0c0cb692u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c0cb694;
P_0c0cb694: /* original c70d, guest PC 0x0c0cb694 */
if(!s->budget--) { s->failed_pc=0x0c0cb694u; return 0; }
r[0]=code_base|0x000cb6ccu;
goto P_0c0cb696;
P_0c0cb696: /* original f108, guest PC 0x0c0cb696 */
if(!s->budget--) { s->failed_pc=0x0c0cb696u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0cb698;
P_0c0cb698: /* original c70d, guest PC 0x0c0cb698 */
if(!s->budget--) { s->failed_pc=0x0c0cb698u; return 0; }
r[0]=code_base|0x000cb6d0u;
goto P_0c0cb69a;
P_0c0cb69a: /* original 9d0a, guest PC 0x0c0cb69a */
if(!s->budget--) { s->failed_pc=0x0c0cb69au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6b2u,2);
goto P_0c0cb69c;
P_0c0cb69c: /* original 374c, guest PC 0x0c0cb69c */
if(!s->budget--) { s->failed_pc=0x0c0cb69cu; return 0; }
r[7]+=r[4];
goto P_0c0cb69e;
P_0c0cb69e: /* original 4f22, guest PC 0x0c0cb69e */
if(!s->budget--) { s->failed_pc=0x0c0cb69eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb6a0;
P_0c0cb6a0: /* original da08, guest PC 0x0c0cb6a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a0u; return 0; }
r[10]=read(ram,0x0c0cb6c4u,4);
goto P_0c0cb6a2;
P_0c0cb6a2: /* original 3d4c, guest PC 0x0c0cb6a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a2u; return 0; }
r[13]+=r[4];
goto P_0c0cb6a4;
P_0c0cb6a4: /* original fb08, guest PC 0x0c0cb6a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a4u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c0cb6a6;
P_0c0cb6a6: /* original a059, guest PC 0x0c0cb6a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a6u; return 0; }
fr[8]=0;
goto P_0c0cb75c;
P_0c0cb6a8: /* original f88d, guest PC 0x0c0cb6a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb6a8u; return 0; }
fr[8]=0;
if(!vf3_matrix_family(0x0c0cb6aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cb6aau; return 0; } return 1;
P_0c0cb6d4: /* original 64b3, guest PC 0x0c0cb6d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb6d4u; return 0; }
r[4]=r[11];
goto P_0c0cb6d6;
P_0c0cb6d6: /* original 3458, guest PC 0x0c0cb6d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb6d6u; return 0; }
r[4]-=r[5];
goto P_0c0cb6d8;
P_0c0cb6d8: /* original 34ac, guest PC 0x0c0cb6d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb6d8u; return 0; }
r[4]+=r[10];
goto P_0c0cb6da;
P_0c0cb6da: /* original d225, guest PC 0x0c0cb6da */
if(!s->budget--) { s->failed_pc=0x0c0cb6dau; return 0; }
r[2]=read(ram,0x0c0cb770u,4);
goto P_0c0cb6dc;
P_0c0cb6dc: /* original 6140, guest PC 0x0c0cb6dc */
if(!s->budget--) { s->failed_pc=0x0c0cb6dcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c0cb6de;
P_0c0cb6de: /* original 420b, guest PC 0x0c0cb6de */
if(!s->budget--) { s->failed_pc=0x0c0cb6deu; return 0; }
target=r[2];
r[16]=code_base|0x0c0cb6e2u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb6e2u) { target=s->pc; goto dispatch; }
goto P_0c0cb6e2;
P_0c0cb6e0: /* original 60c3, guest PC 0x0c0cb6e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e0u; return 0; }
r[0]=r[12];
goto P_0c0cb6e2;
P_0c0cb6e2: /* original 6403, guest PC 0x0c0cb6e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e2u; return 0; }
r[4]=r[0];
goto P_0c0cb6e4;
P_0c0cb6e4: /* original 664e, guest PC 0x0c0cb6e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb6e6;
P_0c0cb6e6: /* original 6363, guest PC 0x0c0cb6e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e6u; return 0; }
r[3]=r[6];
goto P_0c0cb6e8;
P_0c0cb6e8: /* original 4600, guest PC 0x0c0cb6e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb6e8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0cb6ea;
P_0c0cb6ea: /* original 363c, guest PC 0x0c0cb6ea */
if(!s->budget--) { s->failed_pc=0x0c0cb6eau; return 0; }
r[6]+=r[3];
goto P_0c0cb6ec;
P_0c0cb6ec: /* original 4608, guest PC 0x0c0cb6ec */
if(!s->budget--) { s->failed_pc=0x0c0cb6ecu; return 0; }
r[6]<<=2;
goto P_0c0cb6ee;
P_0c0cb6ee: /* original 369c, guest PC 0x0c0cb6ee */
if(!s->budget--) { s->failed_pc=0x0c0cb6eeu; return 0; }
r[6]+=r[9];
goto P_0c0cb6f0;
P_0c0cb6f0: /* original f668, guest PC 0x0c0cb6f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f0u; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c0cb6f2;
P_0c0cb6f2: /* original e008, guest PC 0x0c0cb6f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f2u; return 0; }
r[0]=0x00000008u;
goto P_0c0cb6f4;
P_0c0cb6f4: /* original f766, guest PC 0x0c0cb6f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f4u; return 0; }
vf3_matrix_load(s,ram,7,r[6]+r[0]);
goto P_0c0cb6f6;
P_0c0cb6f6: /* original f36c, guest PC 0x0c0cb6f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f6u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0cb6f8;
P_0c0cb6f8: /* original f362, guest PC 0x0c0cb6f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb6f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0cb6fa;
P_0c0cb6fa: /* original f07c, guest PC 0x0c0cb6fa */
if(!s->budget--) { s->failed_pc=0x0c0cb6fau; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0cb6fc;
P_0c0cb6fc: /* original f37e, guest PC 0x0c0cb6fc */
if(!s->budget--) { s->failed_pc=0x0c0cb6fcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c0cb6fe;
P_0c0cb6fe: /* original f93c, guest PC 0x0c0cb6fe */
if(!s->budget--) { s->failed_pc=0x0c0cb6feu; return 0; }
vf3_matrix_move(s,9,3);
goto P_0c0cb700;
P_0c0cb700: /* original fb95, guest PC 0x0c0cb700 */
if(!s->budget--) { s->failed_pc=0x0c0cb700u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[9]))!=0);
goto P_0c0cb702;
P_0c0cb702: /* original 8b01, guest PC 0x0c0cb702 */
if(!s->budget--) { s->failed_pc=0x0c0cb702u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb708; }
goto P_0c0cb704;
P_0c0cb704: /* original a002, guest PC 0x0c0cb704 */
if(!s->budget--) { s->failed_pc=0x0c0cb704u; return 0; }
fr[5]=0;
goto P_0c0cb70c;
P_0c0cb706: /* original f58d, guest PC 0x0c0cb706 */
if(!s->budget--) { s->failed_pc=0x0c0cb706u; return 0; }
fr[5]=0;
goto P_0c0cb708;
P_0c0cb708: /* original f59c, guest PC 0x0c0cb708 */
if(!s->budget--) { s->failed_pc=0x0c0cb708u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c0cb70a;
P_0c0cb70a: /* original f57d, guest PC 0x0c0cb70a */
if(!s->budget--) { s->failed_pc=0x0c0cb70au; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c0cb70c;
P_0c0cb70c: /* original f45c, guest PC 0x0c0cb70c */
if(!s->budget--) { s->failed_pc=0x0c0cb70cu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cb70e;
P_0c0cb70e: /* original f462, guest PC 0x0c0cb70e */
if(!s->budget--) { s->failed_pc=0x0c0cb70eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0cb710;
P_0c0cb710: /* original f572, guest PC 0x0c0cb710 */
if(!s->budget--) { s->failed_pc=0x0c0cb710u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0cb712;
P_0c0cb712: /* original 614e, guest PC 0x0c0cb712 */
if(!s->budget--) { s->failed_pc=0x0c0cb712u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb714;
P_0c0cb714: /* original 4100, guest PC 0x0c0cb714 */
if(!s->budget--) { s->failed_pc=0x0c0cb714u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0cb716;
P_0c0cb716: /* original f915, guest PC 0x0c0cb716 */
if(!s->budget--) { s->failed_pc=0x0c0cb716u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[1]))!=0);
goto P_0c0cb718;
P_0c0cb718: /* original f34c, guest PC 0x0c0cb718 */
if(!s->budget--) { s->failed_pc=0x0c0cb718u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb71a;
P_0c0cb71a: /* original f4ac, guest PC 0x0c0cb71a */
if(!s->budget--) { s->failed_pc=0x0c0cb71au; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c0cb71c;
P_0c0cb71c: /* original f432, guest PC 0x0c0cb71c */
if(!s->budget--) { s->failed_pc=0x0c0cb71cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cb71e;
P_0c0cb71e: /* original f35c, guest PC 0x0c0cb71e */
if(!s->budget--) { s->failed_pc=0x0c0cb71eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cb720;
P_0c0cb720: /* original f5ac, guest PC 0x0c0cb720 */
if(!s->budget--) { s->failed_pc=0x0c0cb720u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c0cb722;
P_0c0cb722: /* original f532, guest PC 0x0c0cb722 */
if(!s->budget--) { s->failed_pc=0x0c0cb722u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cb724;
P_0c0cb724: /* original 8d0a, guest PC 0x0c0cb724 */
if(!s->budget--) { s->failed_pc=0x0c0cb724u; return 0; }
cond=r[17]&1u;
r[1]<<=2;
if(cond) { goto P_0c0cb73c; }
goto P_0c0cb728;
P_0c0cb726: /* original 4108, guest PC 0x0c0cb726 */
if(!s->budget--) { s->failed_pc=0x0c0cb726u; return 0; }
r[1]<<=2;
goto P_0c0cb728;
P_0c0cb728: /* original f571, guest PC 0x0c0cb728 */
if(!s->budget--) { s->failed_pc=0x0c0cb728u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c0cb72a;
P_0c0cb72a: /* original 6413, guest PC 0x0c0cb72a */
if(!s->budget--) { s->failed_pc=0x0c0cb72au; return 0; }
r[4]=r[1];
goto P_0c0cb72c;
P_0c0cb72c: /* original f461, guest PC 0x0c0cb72c */
if(!s->budget--) { s->failed_pc=0x0c0cb72cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0cb72e;
P_0c0cb72e: /* original 34dc, guest PC 0x0c0cb72e */
if(!s->budget--) { s->failed_pc=0x0c0cb72eu; return 0; }
r[4]+=r[13];
goto P_0c0cb730;
P_0c0cb730: /* original e004, guest PC 0x0c0cb730 */
if(!s->budget--) { s->failed_pc=0x0c0cb730u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb732;
P_0c0cb732: /* original f487, guest PC 0x0c0cb732 */
if(!s->budget--) { s->failed_pc=0x0c0cb732u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0cb734;
P_0c0cb734: /* original f48a, guest PC 0x0c0cb734 */
if(!s->budget--) { s->failed_pc=0x0c0cb734u; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c0cb736;
P_0c0cb736: /* original 6413, guest PC 0x0c0cb736 */
if(!s->budget--) { s->failed_pc=0x0c0cb736u; return 0; }
r[4]=r[1];
goto P_0c0cb738;
P_0c0cb738: /* original a00d, guest PC 0x0c0cb738 */
if(!s->budget--) { s->failed_pc=0x0c0cb738u; return 0; }
r[4]+=r[7];
goto P_0c0cb756;
P_0c0cb73a: /* original 347c, guest PC 0x0c0cb73a */
if(!s->budget--) { s->failed_pc=0x0c0cb73au; return 0; }
r[4]+=r[7];
goto P_0c0cb73c;
P_0c0cb73c: /* original 6413, guest PC 0x0c0cb73c */
if(!s->budget--) { s->failed_pc=0x0c0cb73cu; return 0; }
r[4]=r[1];
goto P_0c0cb73e;
P_0c0cb73e: /* original e004, guest PC 0x0c0cb73e */
if(!s->budget--) { s->failed_pc=0x0c0cb73eu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb740;
P_0c0cb740: /* original 347c, guest PC 0x0c0cb740 */
if(!s->budget--) { s->failed_pc=0x0c0cb740u; return 0; }
r[4]+=r[7];
goto P_0c0cb742;
P_0c0cb742: /* original f487, guest PC 0x0c0cb742 */
if(!s->budget--) { s->failed_pc=0x0c0cb742u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0cb744;
P_0c0cb744: /* original f48a, guest PC 0x0c0cb744 */
if(!s->budget--) { s->failed_pc=0x0c0cb744u; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c0cb746;
P_0c0cb746: /* original 6413, guest PC 0x0c0cb746 */
if(!s->budget--) { s->failed_pc=0x0c0cb746u; return 0; }
r[4]=r[1];
goto P_0c0cb748;
P_0c0cb748: /* original f34c, guest PC 0x0c0cb748 */
if(!s->budget--) { s->failed_pc=0x0c0cb748u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb74a;
P_0c0cb74a: /* original 34dc, guest PC 0x0c0cb74a */
if(!s->budget--) { s->failed_pc=0x0c0cb74au; return 0; }
r[4]+=r[13];
goto P_0c0cb74c;
P_0c0cb74c: /* original f46c, guest PC 0x0c0cb74c */
if(!s->budget--) { s->failed_pc=0x0c0cb74cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cb74e;
P_0c0cb74e: /* original f431, guest PC 0x0c0cb74e */
if(!s->budget--) { s->failed_pc=0x0c0cb74eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0cb750;
P_0c0cb750: /* original f35c, guest PC 0x0c0cb750 */
if(!s->budget--) { s->failed_pc=0x0c0cb750u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cb752;
P_0c0cb752: /* original f57c, guest PC 0x0c0cb752 */
if(!s->budget--) { s->failed_pc=0x0c0cb752u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cb754;
P_0c0cb754: /* original f531, guest PC 0x0c0cb754 */
if(!s->budget--) { s->failed_pc=0x0c0cb754u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0cb756;
P_0c0cb756: /* original 75ff, guest PC 0x0c0cb756 */
if(!s->budget--) { s->failed_pc=0x0c0cb756u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0cb758;
P_0c0cb758: /* original f44a, guest PC 0x0c0cb758 */
if(!s->budget--) { s->failed_pc=0x0c0cb758u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c0cb75a;
P_0c0cb75a: /* original f457, guest PC 0x0c0cb75a */
if(!s->budget--) { s->failed_pc=0x0c0cb75au; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0cb75c;
P_0c0cb75c: /* original 2558, guest PC 0x0c0cb75c */
if(!s->budget--) { s->failed_pc=0x0c0cb75cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0cb75e;
P_0c0cb75e: /* original 8bb9, guest PC 0x0c0cb75e */
if(!s->budget--) { s->failed_pc=0x0c0cb75eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb6d4; }
goto P_0c0cb760;
P_0c0cb760: /* original 4f26, guest PC 0x0c0cb760 */
if(!s->budget--) { s->failed_pc=0x0c0cb760u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb762;
P_0c0cb762: /* original 69f6, guest PC 0x0c0cb762 */
if(!s->budget--) { s->failed_pc=0x0c0cb762u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cb764;
P_0c0cb764: /* original 6af6, guest PC 0x0c0cb764 */
if(!s->budget--) { s->failed_pc=0x0c0cb764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cb766;
P_0c0cb766: /* original 6bf6, guest PC 0x0c0cb766 */
if(!s->budget--) { s->failed_pc=0x0c0cb766u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cb768;
P_0c0cb768: /* original 6cf6, guest PC 0x0c0cb768 */
if(!s->budget--) { s->failed_pc=0x0c0cb768u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cb76a;
P_0c0cb76a: /* original 000b, guest PC 0x0c0cb76a */
if(!s->budget--) { s->failed_pc=0x0c0cb76au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb76c: /* original 6df6, guest PC 0x0c0cb76c */
if(!s->budget--) { s->failed_pc=0x0c0cb76cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c0cb76eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cb76eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
