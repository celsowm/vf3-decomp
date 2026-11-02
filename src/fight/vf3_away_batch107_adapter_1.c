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
int vf3_away_batch107_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0925ecu: goto P_0c0925ec;
case 0x0c0925eeu: goto P_0c0925ee;
case 0x0c0925f0u: goto P_0c0925f0;
case 0x0c0925f2u: goto P_0c0925f2;
case 0x0c0925f4u: goto P_0c0925f4;
case 0x0c0925f6u: goto P_0c0925f6;
case 0x0c0925f8u: goto P_0c0925f8;
case 0x0c0925fau: goto P_0c0925fa;
case 0x0c0925fcu: goto P_0c0925fc;
case 0x0c0925feu: goto P_0c0925fe;
case 0x0c092600u: goto P_0c092600;
case 0x0c092602u: goto P_0c092602;
case 0x0c092604u: goto P_0c092604;
case 0x0c092606u: goto P_0c092606;
case 0x0c092608u: goto P_0c092608;
case 0x0c09260au: goto P_0c09260a;
case 0x0c09260cu: goto P_0c09260c;
case 0x0c09260eu: goto P_0c09260e;
case 0x0c092610u: goto P_0c092610;
case 0x0c092612u: goto P_0c092612;
case 0x0c092614u: goto P_0c092614;
case 0x0c092616u: goto P_0c092616;
case 0x0c092618u: goto P_0c092618;
case 0x0c09261au: goto P_0c09261a;
case 0x0c09261cu: goto P_0c09261c;
case 0x0c09261eu: goto P_0c09261e;
case 0x0c092620u: goto P_0c092620;
case 0x0c092622u: goto P_0c092622;
case 0x0c092624u: goto P_0c092624;
case 0x0c092626u: goto P_0c092626;
case 0x0c092628u: goto P_0c092628;
case 0x0c09262au: goto P_0c09262a;
case 0x0c09262cu: goto P_0c09262c;
case 0x0c09262eu: goto P_0c09262e;
case 0x0c092630u: goto P_0c092630;
case 0x0c092632u: goto P_0c092632;
case 0x0c092634u: goto P_0c092634;
case 0x0c092636u: goto P_0c092636;
case 0x0c092638u: goto P_0c092638;
case 0x0c09263au: goto P_0c09263a;
case 0x0c09263cu: goto P_0c09263c;
case 0x0c09263eu: goto P_0c09263e;
case 0x0c092640u: goto P_0c092640;
case 0x0c092642u: goto P_0c092642;
case 0x0c092644u: goto P_0c092644;
case 0x0c092646u: goto P_0c092646;
case 0x0c092648u: goto P_0c092648;
case 0x0c09264au: goto P_0c09264a;
case 0x0c09264cu: goto P_0c09264c;
case 0x0c09264eu: goto P_0c09264e;
case 0x0c092650u: goto P_0c092650;
case 0x0c092652u: goto P_0c092652;
case 0x0c092654u: goto P_0c092654;
case 0x0c092656u: goto P_0c092656;
case 0x0c092658u: goto P_0c092658;
case 0x0c09265au: goto P_0c09265a;
case 0x0c09265cu: goto P_0c09265c;
case 0x0c09265eu: goto P_0c09265e;
case 0x0c092660u: goto P_0c092660;
case 0x0c092662u: goto P_0c092662;
case 0x0c092664u: goto P_0c092664;
case 0x0c092666u: goto P_0c092666;
case 0x0c092668u: goto P_0c092668;
case 0x0c09266au: goto P_0c09266a;
case 0x0c09266cu: goto P_0c09266c;
case 0x0c09266eu: goto P_0c09266e;
case 0x0c092670u: goto P_0c092670;
case 0x0c092672u: goto P_0c092672;
case 0x0c092674u: goto P_0c092674;
case 0x0c092676u: goto P_0c092676;
case 0x0c092678u: goto P_0c092678;
case 0x0c09267au: goto P_0c09267a;
case 0x0c09267cu: goto P_0c09267c;
case 0x0c09267eu: goto P_0c09267e;
case 0x0c092680u: goto P_0c092680;
case 0x0c092682u: goto P_0c092682;
case 0x0c092684u: goto P_0c092684;
case 0x0c092686u: goto P_0c092686;
case 0x0c092688u: goto P_0c092688;
case 0x0c09268au: goto P_0c09268a;
case 0x0c09268cu: goto P_0c09268c;
case 0x0c09268eu: goto P_0c09268e;
case 0x0c092690u: goto P_0c092690;
case 0x0c092692u: goto P_0c092692;
case 0x0c092694u: goto P_0c092694;
case 0x0c092696u: goto P_0c092696;
case 0x0c092698u: goto P_0c092698;
case 0x0c09269au: goto P_0c09269a;
case 0x0c09269cu: goto P_0c09269c;
case 0x0c09269eu: goto P_0c09269e;
case 0x0c0926a0u: goto P_0c0926a0;
case 0x0c0926a2u: goto P_0c0926a2;
case 0x0c0926a4u: goto P_0c0926a4;
case 0x0c0926a6u: goto P_0c0926a6;
case 0x0c0926a8u: goto P_0c0926a8;
case 0x0c0926aau: goto P_0c0926aa;
case 0x0c0926acu: goto P_0c0926ac;
case 0x0c0926aeu: goto P_0c0926ae;
case 0x0c0926b0u: goto P_0c0926b0;
case 0x0c0926b2u: goto P_0c0926b2;
case 0x0c0926b4u: goto P_0c0926b4;
case 0x0c0926b6u: goto P_0c0926b6;
case 0x0c0926b8u: goto P_0c0926b8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0925ec: /* original 2fe6, guest PC 0x0c0925ec */
if(!s->budget--) { s->failed_pc=0x0c0925ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0925ee;
P_0c0925ee: /* original e061, guest PC 0x0c0925ee */
if(!s->budget--) { s->failed_pc=0x0c0925eeu; return 0; }
r[0]=0x00000061u;
goto P_0c0925f0;
P_0c0925f0: /* original 2fd6, guest PC 0x0c0925f0 */
if(!s->budget--) { s->failed_pc=0x0c0925f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0925f2;
P_0c0925f2: /* original e30c, guest PC 0x0c0925f2 */
if(!s->budget--) { s->failed_pc=0x0c0925f2u; return 0; }
r[3]=0x0000000cu;
goto P_0c0925f4;
P_0c0925f4: /* original 2fc6, guest PC 0x0c0925f4 */
if(!s->budget--) { s->failed_pc=0x0c0925f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0925f6;
P_0c0925f6: /* original ffdb, guest PC 0x0c0925f6 */
if(!s->budget--) { s->failed_pc=0x0c0925f6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0925f8;
P_0c0925f8: /* original ffcb, guest PC 0x0c0925f8 */
if(!s->budget--) { s->failed_pc=0x0c0925f8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0925fa;
P_0c0925fa: /* original 044c, guest PC 0x0c0925fa */
if(!s->budget--) { s->failed_pc=0x0c0925fau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0925fc;
P_0c0925fc: /* original 7ffc, guest PC 0x0c0925fc */
if(!s->budget--) { s->failed_pc=0x0c0925fcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0925fe;
P_0c0925fe: /* original 644c, guest PC 0x0c0925fe */
if(!s->budget--) { s->failed_pc=0x0c0925feu; return 0; }
r[4]=r[4]&255u;
goto P_0c092600;
P_0c092600: /* original 3436, guest PC 0x0c092600 */
if(!s->budget--) { s->failed_pc=0x0c092600u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c092602;
P_0c092602: /* original 8b00, guest PC 0x0c092602 */
if(!s->budget--) { s->failed_pc=0x0c092602u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092606; }
goto P_0c092604;
P_0c092604: /* original 3438, guest PC 0x0c092604 */
if(!s->budget--) { s->failed_pc=0x0c092604u; return 0; }
r[4]-=r[3];
goto P_0c092606;
P_0c092606: /* original 6d43, guest PC 0x0c092606 */
if(!s->budget--) { s->failed_pc=0x0c092606u; return 0; }
r[13]=r[4];
goto P_0c092608;
P_0c092608: /* original d33d, guest PC 0x0c092608 */
if(!s->budget--) { s->failed_pc=0x0c092608u; return 0; }
r[3]=read(ram,0x0c092700u,4);
goto P_0c09260a;
P_0c09260a: /* original 4d08, guest PC 0x0c09260a */
if(!s->budget--) { s->failed_pc=0x0c09260au; return 0; }
r[13]<<=2;
goto P_0c09260c;
P_0c09260c: /* original dc3d, guest PC 0x0c09260c */
if(!s->budget--) { s->failed_pc=0x0c09260cu; return 0; }
r[12]=read(ram,0x0c092704u,4);
goto P_0c09260e;
P_0c09260e: /* original 4d08, guest PC 0x0c09260e */
if(!s->budget--) { s->failed_pc=0x0c09260eu; return 0; }
r[13]<<=2;
goto P_0c092610;
P_0c092610: /* original 3d3c, guest PC 0x0c092610 */
if(!s->budget--) { s->failed_pc=0x0c092610u; return 0; }
r[13]+=r[3];
goto P_0c092612;
P_0c092612: /* original 6ed5, guest PC 0x0c092612 */
if(!s->budget--) { s->failed_pc=0x0c092612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[14]=tmp;
goto P_0c092614;
P_0c092614: /* original e200, guest PC 0x0c092614 */
if(!s->budget--) { s->failed_pc=0x0c092614u; return 0; }
r[2]=0x00000000u;
goto P_0c092616;
P_0c092616: /* original 3e26, guest PC 0x0c092616 */
if(!s->budget--) { s->failed_pc=0x0c092616u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[2])!=0);
goto P_0c092618;
P_0c092618: /* original 8b48, guest PC 0x0c092618 */
if(!s->budget--) { s->failed_pc=0x0c092618u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0926ac; }
goto P_0c09261a;
P_0c09261a: /* original 67d5, guest PC 0x0c09261a */
if(!s->budget--) { s->failed_pc=0x0c09261au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[7]=tmp;
goto P_0c09261c;
P_0c09261c: /* original 6373, guest PC 0x0c09261c */
if(!s->budget--) { s->failed_pc=0x0c09261cu; return 0; }
r[3]=r[7];
goto P_0c09261e;
P_0c09261e: /* original 4700, guest PC 0x0c09261e */
if(!s->budget--) { s->failed_pc=0x0c09261eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c092620;
P_0c092620: /* original 373c, guest PC 0x0c092620 */
if(!s->budget--) { s->failed_pc=0x0c092620u; return 0; }
r[7]+=r[3];
goto P_0c092622;
P_0c092622: /* original 4708, guest PC 0x0c092622 */
if(!s->budget--) { s->failed_pc=0x0c092622u; return 0; }
r[7]<<=2;
goto P_0c092624;
P_0c092624: /* original 37cc, guest PC 0x0c092624 */
if(!s->budget--) { s->failed_pc=0x0c092624u; return 0; }
r[7]+=r[12];
goto P_0c092626;
P_0c092626: /* original 6471, guest PC 0x0c092626 */
if(!s->budget--) { s->failed_pc=0x0c092626u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[4]=tmp;
goto P_0c092628;
P_0c092628: /* original 8571, guest PC 0x0c092628 */
if(!s->budget--) { s->failed_pc=0x0c092628u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+2,2);
goto P_0c09262a;
P_0c09262a: /* original 6343, guest PC 0x0c09262a */
if(!s->budget--) { s->failed_pc=0x0c09262au; return 0; }
r[3]=r[4];
goto P_0c09262c;
P_0c09262c: /* original 4400, guest PC 0x0c09262c */
if(!s->budget--) { s->failed_pc=0x0c09262cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09262e;
P_0c09262e: /* original 343c, guest PC 0x0c09262e */
if(!s->budget--) { s->failed_pc=0x0c09262eu; return 0; }
r[4]+=r[3];
goto P_0c092630;
P_0c092630: /* original 6303, guest PC 0x0c092630 */
if(!s->budget--) { s->failed_pc=0x0c092630u; return 0; }
r[3]=r[0];
goto P_0c092632;
P_0c092632: /* original 4408, guest PC 0x0c092632 */
if(!s->budget--) { s->failed_pc=0x0c092632u; return 0; }
r[4]<<=2;
goto P_0c092634;
P_0c092634: /* original 4400, guest PC 0x0c092634 */
if(!s->budget--) { s->failed_pc=0x0c092634u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c092636;
P_0c092636: /* original 345c, guest PC 0x0c092636 */
if(!s->budget--) { s->failed_pc=0x0c092636u; return 0; }
r[4]+=r[5];
goto P_0c092638;
P_0c092638: /* original f649, guest PC 0x0c092638 */
if(!s->budget--) { s->failed_pc=0x0c092638u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09263a;
P_0c09263a: /* original 4000, guest PC 0x0c09263a */
if(!s->budget--) { s->failed_pc=0x0c09263au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c09263c;
P_0c09263c: /* original 303c, guest PC 0x0c09263c */
if(!s->budget--) { s->failed_pc=0x0c09263cu; return 0; }
r[0]+=r[3];
goto P_0c09263e;
P_0c09263e: /* original 6363, guest PC 0x0c09263e */
if(!s->budget--) { s->failed_pc=0x0c09263eu; return 0; }
r[3]=r[6];
goto P_0c092640;
P_0c092640: /* original f549, guest PC 0x0c092640 */
if(!s->budget--) { s->failed_pc=0x0c092640u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092642;
P_0c092642: /* original 4008, guest PC 0x0c092642 */
if(!s->budget--) { s->failed_pc=0x0c092642u; return 0; }
r[0]<<=2;
goto P_0c092644;
P_0c092644: /* original 4000, guest PC 0x0c092644 */
if(!s->budget--) { s->failed_pc=0x0c092644u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c092646;
P_0c092646: /* original f449, guest PC 0x0c092646 */
if(!s->budget--) { s->failed_pc=0x0c092646u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092648;
P_0c092648: /* original 7340, guest PC 0x0c092648 */
if(!s->budget--) { s->failed_pc=0x0c092648u; return 0; }
r[3]+=0x00000040u;
goto P_0c09264a;
P_0c09264a: /* original f749, guest PC 0x0c09264a */
if(!s->budget--) { s->failed_pc=0x0c09264au; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09264c;
P_0c09264c: /* original f848, guest PC 0x0c09264c */
if(!s->budget--) { s->failed_pc=0x0c09264cu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c09264e;
P_0c09264e: /* original 6453, guest PC 0x0c09264e */
if(!s->budget--) { s->failed_pc=0x0c09264eu; return 0; }
r[4]=r[5];
goto P_0c092650;
P_0c092650: /* original 340c, guest PC 0x0c092650 */
if(!s->budget--) { s->failed_pc=0x0c092650u; return 0; }
r[4]+=r[0];
goto P_0c092652;
P_0c092652: /* original fa49, guest PC 0x0c092652 */
if(!s->budget--) { s->failed_pc=0x0c092652u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092654;
P_0c092654: /* original f949, guest PC 0x0c092654 */
if(!s->budget--) { s->failed_pc=0x0c092654u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092656;
P_0c092656: /* original fc48, guest PC 0x0c092656 */
if(!s->budget--) { s->failed_pc=0x0c092656u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
goto P_0c092658;
P_0c092658: /* original 0383, guest PC 0x0c092658 */
if(!s->budget--) { s->failed_pc=0x0c092658u; return 0; }
if((r[3]&0xFC000000u)==0xE0000000u) pref(ram,r[3]);
goto P_0c09265a;
P_0c09265a: /* original f19c, guest PC 0x0c09265a */
if(!s->budget--) { s->failed_pc=0x0c09265au; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c09265c;
P_0c09265c: /* original f151, guest PC 0x0c09265c */
if(!s->budget--) { s->failed_pc=0x0c09265cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'-');
goto P_0c09265e;
P_0c09265e: /* original f0cc, guest PC 0x0c09265e */
if(!s->budget--) { s->failed_pc=0x0c09265eu; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c092660;
P_0c092660: /* original f041, guest PC 0x0c092660 */
if(!s->budget--) { s->failed_pc=0x0c092660u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'-');
goto P_0c092662;
P_0c092662: /* original fdac, guest PC 0x0c092662 */
if(!s->budget--) { s->failed_pc=0x0c092662u; return 0; }
vf3_matrix_move(s,13,10);
goto P_0c092664;
P_0c092664: /* original fd61, guest PC 0x0c092664 */
if(!s->budget--) { s->failed_pc=0x0c092664u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[6],r[18],'-');
goto P_0c092666;
P_0c092666: /* original e004, guest PC 0x0c092666 */
if(!s->budget--) { s->failed_pc=0x0c092666u; return 0; }
r[0]=0x00000004u;
goto P_0c092668;
P_0c092668: /* original 6463, guest PC 0x0c092668 */
if(!s->budget--) { s->failed_pc=0x0c092668u; return 0; }
r[4]=r[6];
goto P_0c09266a;
P_0c09266a: /* original fb76, guest PC 0x0c09266a */
if(!s->budget--) { s->failed_pc=0x0c09266au; return 0; }
vf3_matrix_load(s,ram,11,r[7]+r[0]);
goto P_0c09266c;
P_0c09266c: /* original e008, guest PC 0x0c09266c */
if(!s->budget--) { s->failed_pc=0x0c09266cu; return 0; }
r[0]=0x00000008u;
goto P_0c09266e;
P_0c09266e: /* original f376, guest PC 0x0c09266e */
if(!s->budget--) { s->failed_pc=0x0c09266eu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c092670;
P_0c092670: /* original 7430, guest PC 0x0c092670 */
if(!s->budget--) { s->failed_pc=0x0c092670u; return 0; }
r[4]+=0x00000030u;
goto P_0c092672;
P_0c092672: /* original fdb2, guest PC 0x0c092672 */
if(!s->budget--) { s->failed_pc=0x0c092672u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[11],r[18],'*');
goto P_0c092674;
P_0c092674: /* original f0b2, guest PC 0x0c092674 */
if(!s->budget--) { s->failed_pc=0x0c092674u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c092676;
P_0c092676: /* original ff3a, guest PC 0x0c092676 */
if(!s->budget--) { s->failed_pc=0x0c092676u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c092678;
P_0c092678: /* original f1b2, guest PC 0x0c092678 */
if(!s->budget--) { s->failed_pc=0x0c092678u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'*');
goto P_0c09267a;
P_0c09267a: /* original fb7c, guest PC 0x0c09267a */
if(!s->budget--) { s->failed_pc=0x0c09267au; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c09267c;
P_0c09267c: /* original fb30, guest PC 0x0c09267c */
if(!s->budget--) { s->failed_pc=0x0c09267cu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'+');
goto P_0c09267e;
P_0c09267e: /* original f2bc, guest PC 0x0c09267e */
if(!s->budget--) { s->failed_pc=0x0c09267eu; return 0; }
vf3_matrix_move(s,2,11);
goto P_0c092680;
P_0c092680: /* original f2b2, guest PC 0x0c092680 */
if(!s->budget--) { s->failed_pc=0x0c092680u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[11],r[18],'*');
goto P_0c092682;
P_0c092682: /* original f42a, guest PC 0x0c092682 */
if(!s->budget--) { s->failed_pc=0x0c092682u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092684;
P_0c092684: /* original f3f8, guest PC 0x0c092684 */
if(!s->budget--) { s->failed_pc=0x0c092684u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c092686;
P_0c092686: /* original f23c, guest PC 0x0c092686 */
if(!s->budget--) { s->failed_pc=0x0c092686u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c092688;
P_0c092688: /* original f232, guest PC 0x0c092688 */
if(!s->budget--) { s->failed_pc=0x0c092688u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c09268a;
P_0c09268a: /* original f42b, guest PC 0x0c09268a */
if(!s->budget--) { s->failed_pc=0x0c09268au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09268c;
P_0c09268c: /* original f48b, guest PC 0x0c09268c */
if(!s->budget--) { s->failed_pc=0x0c09268cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c09268e;
P_0c09268e: /* original f47b, guest PC 0x0c09268e */
if(!s->budget--) { s->failed_pc=0x0c09268eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c092690;
P_0c092690: /* original f40b, guest PC 0x0c092690 */
if(!s->budget--) { s->failed_pc=0x0c092690u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092692;
P_0c092692: /* original f41b, guest PC 0x0c092692 */
if(!s->budget--) { s->failed_pc=0x0c092692u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092694;
P_0c092694: /* original f4db, guest PC 0x0c092694 */
if(!s->budget--) { s->failed_pc=0x0c092694u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[4]);
goto P_0c092696;
P_0c092696: /* original f4cb, guest PC 0x0c092696 */
if(!s->budget--) { s->failed_pc=0x0c092696u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[4]);
goto P_0c092698;
P_0c092698: /* original f49b, guest PC 0x0c092698 */
if(!s->budget--) { s->failed_pc=0x0c092698u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c09269a;
P_0c09269a: /* original f4ab, guest PC 0x0c09269a */
if(!s->budget--) { s->failed_pc=0x0c09269au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c09269c;
P_0c09269c: /* original 7eff, guest PC 0x0c09269c */
if(!s->budget--) { s->failed_pc=0x0c09269cu; return 0; }
r[14]+=0xffffffffu;
goto P_0c09269e;
P_0c09269e: /* original f44b, guest PC 0x0c09269e */
if(!s->budget--) { s->failed_pc=0x0c09269eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c0926a0;
P_0c0926a0: /* original e300, guest PC 0x0c0926a0 */
if(!s->budget--) { s->failed_pc=0x0c0926a0u; return 0; }
r[3]=0x00000000u;
goto P_0c0926a2;
P_0c0926a2: /* original f45b, guest PC 0x0c0926a2 */
if(!s->budget--) { s->failed_pc=0x0c0926a2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c0926a4;
P_0c0926a4: /* original 3e36, guest PC 0x0c0926a4 */
if(!s->budget--) { s->failed_pc=0x0c0926a4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[3])!=0);
goto P_0c0926a6;
P_0c0926a6: /* original f46b, guest PC 0x0c0926a6 */
if(!s->budget--) { s->failed_pc=0x0c0926a6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c0926a8;
P_0c0926a8: /* original 8db7, guest PC 0x0c0926a8 */
if(!s->budget--) { s->failed_pc=0x0c0926a8u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000040u;
if(cond) { goto P_0c09261a; }
goto P_0c0926ac;
P_0c0926aa: /* original 7640, guest PC 0x0c0926aa */
if(!s->budget--) { s->failed_pc=0x0c0926aau; return 0; }
r[6]+=0x00000040u;
goto P_0c0926ac;
P_0c0926ac: /* original 7f04, guest PC 0x0c0926ac */
if(!s->budget--) { s->failed_pc=0x0c0926acu; return 0; }
r[15]+=0x00000004u;
goto P_0c0926ae;
P_0c0926ae: /* original fcf9, guest PC 0x0c0926ae */
if(!s->budget--) { s->failed_pc=0x0c0926aeu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0926b0;
P_0c0926b0: /* original fdf9, guest PC 0x0c0926b0 */
if(!s->budget--) { s->failed_pc=0x0c0926b0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0926b2;
P_0c0926b2: /* original 6cf6, guest PC 0x0c0926b2 */
if(!s->budget--) { s->failed_pc=0x0c0926b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0926b4;
P_0c0926b4: /* original 6df6, guest PC 0x0c0926b4 */
if(!s->budget--) { s->failed_pc=0x0c0926b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0926b6;
P_0c0926b6: /* original 000b, guest PC 0x0c0926b6 */
if(!s->budget--) { s->failed_pc=0x0c0926b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0926b8: /* original 6ef6, guest PC 0x0c0926b8 */
if(!s->budget--) { s->failed_pc=0x0c0926b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0926bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0926bau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
