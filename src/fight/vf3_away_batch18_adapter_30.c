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
int vf3_away_batch18_adapter_30(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0955b0u: goto P_0c0955b0;
case 0x0c0955b2u: goto P_0c0955b2;
case 0x0c0955b4u: goto P_0c0955b4;
case 0x0c0955b6u: goto P_0c0955b6;
case 0x0c0955b8u: goto P_0c0955b8;
case 0x0c0955bau: goto P_0c0955ba;
case 0x0c0955bcu: goto P_0c0955bc;
case 0x0c0955beu: goto P_0c0955be;
case 0x0c0955c0u: goto P_0c0955c0;
case 0x0c0955c2u: goto P_0c0955c2;
case 0x0c0955c4u: goto P_0c0955c4;
case 0x0c0955c6u: goto P_0c0955c6;
case 0x0c0955c8u: goto P_0c0955c8;
case 0x0c0955cau: goto P_0c0955ca;
case 0x0c0955ccu: goto P_0c0955cc;
case 0x0c0955ceu: goto P_0c0955ce;
case 0x0c0955d0u: goto P_0c0955d0;
case 0x0c0955d2u: goto P_0c0955d2;
case 0x0c0955d4u: goto P_0c0955d4;
case 0x0c0955d6u: goto P_0c0955d6;
case 0x0c0955d8u: goto P_0c0955d8;
case 0x0c0955dau: goto P_0c0955da;
case 0x0c0955dcu: goto P_0c0955dc;
case 0x0c0955deu: goto P_0c0955de;
case 0x0c0955e0u: goto P_0c0955e0;
case 0x0c0955e2u: goto P_0c0955e2;
case 0x0c0955e4u: goto P_0c0955e4;
case 0x0c0955e6u: goto P_0c0955e6;
case 0x0c0955e8u: goto P_0c0955e8;
case 0x0c0955eau: goto P_0c0955ea;
case 0x0c0955ecu: goto P_0c0955ec;
case 0x0c0955eeu: goto P_0c0955ee;
case 0x0c0955f0u: goto P_0c0955f0;
case 0x0c0955f2u: goto P_0c0955f2;
case 0x0c0955f4u: goto P_0c0955f4;
case 0x0c0955f6u: goto P_0c0955f6;
case 0x0c0955f8u: goto P_0c0955f8;
case 0x0c0955fau: goto P_0c0955fa;
case 0x0c0955fcu: goto P_0c0955fc;
case 0x0c0955feu: goto P_0c0955fe;
case 0x0c095600u: goto P_0c095600;
case 0x0c095602u: goto P_0c095602;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c0961f4u: goto P_0c0961f4;
case 0x0c0961f6u: goto P_0c0961f6;
case 0x0c0961f8u: goto P_0c0961f8;
case 0x0c0961fau: goto P_0c0961fa;
case 0x0c0961fcu: goto P_0c0961fc;
case 0x0c0961feu: goto P_0c0961fe;
case 0x0c096200u: goto P_0c096200;
case 0x0c096202u: goto P_0c096202;
case 0x0c096204u: goto P_0c096204;
case 0x0c096206u: goto P_0c096206;
case 0x0c096208u: goto P_0c096208;
case 0x0c09620au: goto P_0c09620a;
case 0x0c09620cu: goto P_0c09620c;
case 0x0c09620eu: goto P_0c09620e;
case 0x0c096210u: goto P_0c096210;
case 0x0c096212u: goto P_0c096212;
case 0x0c096214u: goto P_0c096214;
case 0x0c096216u: goto P_0c096216;
case 0x0c096218u: goto P_0c096218;
case 0x0c09621au: goto P_0c09621a;
case 0x0c09621cu: goto P_0c09621c;
case 0x0c09621eu: goto P_0c09621e;
case 0x0c096220u: goto P_0c096220;
case 0x0c096222u: goto P_0c096222;
case 0x0c096224u: goto P_0c096224;
case 0x0c096226u: goto P_0c096226;
case 0x0c096228u: goto P_0c096228;
case 0x0c09622au: goto P_0c09622a;
case 0x0c09622cu: goto P_0c09622c;
case 0x0c09622eu: goto P_0c09622e;
case 0x0c096230u: goto P_0c096230;
case 0x0c096232u: goto P_0c096232;
case 0x0c096234u: goto P_0c096234;
case 0x0c096236u: goto P_0c096236;
case 0x0c096238u: goto P_0c096238;
case 0x0c09623au: goto P_0c09623a;
case 0x0c09623cu: goto P_0c09623c;
case 0x0c09623eu: goto P_0c09623e;
case 0x0c096240u: goto P_0c096240;
case 0x0c096242u: goto P_0c096242;
case 0x0c096244u: goto P_0c096244;
case 0x0c096246u: goto P_0c096246;
case 0x0c096248u: goto P_0c096248;
case 0x0c09624au: goto P_0c09624a;
case 0x0c09624cu: goto P_0c09624c;
case 0x0c09624eu: goto P_0c09624e;
case 0x0c096250u: goto P_0c096250;
case 0x0c096252u: goto P_0c096252;
case 0x0c096254u: goto P_0c096254;
case 0x0c096256u: goto P_0c096256;
case 0x0c096258u: goto P_0c096258;
case 0x0c09625au: goto P_0c09625a;
case 0x0c09625cu: goto P_0c09625c;
case 0x0c09625eu: goto P_0c09625e;
case 0x0c096260u: goto P_0c096260;
case 0x0c096262u: goto P_0c096262;
case 0x0c096264u: goto P_0c096264;
case 0x0c096266u: goto P_0c096266;
case 0x0c096268u: goto P_0c096268;
case 0x0c09626au: goto P_0c09626a;
case 0x0c09626cu: goto P_0c09626c;
case 0x0c09626eu: goto P_0c09626e;
case 0x0c096270u: goto P_0c096270;
case 0x0c096272u: goto P_0c096272;
case 0x0c096274u: goto P_0c096274;
case 0x0c096276u: goto P_0c096276;
case 0x0c096278u: goto P_0c096278;
case 0x0c09627au: goto P_0c09627a;
case 0x0c09627cu: goto P_0c09627c;
case 0x0c09627eu: goto P_0c09627e;
case 0x0c096280u: goto P_0c096280;
case 0x0c096282u: goto P_0c096282;
case 0x0c096284u: goto P_0c096284;
case 0x0c096286u: goto P_0c096286;
case 0x0c096288u: goto P_0c096288;
case 0x0c09628au: goto P_0c09628a;
case 0x0c09628cu: goto P_0c09628c;
case 0x0c09628eu: goto P_0c09628e;
case 0x0c096290u: goto P_0c096290;
case 0x0c096292u: goto P_0c096292;
case 0x0c096294u: goto P_0c096294;
case 0x0c096296u: goto P_0c096296;
case 0x0c096298u: goto P_0c096298;
case 0x0c09629au: goto P_0c09629a;
case 0x0c09629cu: goto P_0c09629c;
case 0x0c09629eu: goto P_0c09629e;
case 0x0c0962a0u: goto P_0c0962a0;
case 0x0c0962a2u: goto P_0c0962a2;
case 0x0c0962a4u: goto P_0c0962a4;
case 0x0c0962a6u: goto P_0c0962a6;
case 0x0c0962a8u: goto P_0c0962a8;
case 0x0c0962aau: goto P_0c0962aa;
case 0x0c0962acu: goto P_0c0962ac;
case 0x0c0962aeu: goto P_0c0962ae;
case 0x0c0962b0u: goto P_0c0962b0;
case 0x0c0962b2u: goto P_0c0962b2;
case 0x0c0962b4u: goto P_0c0962b4;
case 0x0c0962b6u: goto P_0c0962b6;
case 0x0c0962b8u: goto P_0c0962b8;
case 0x0c0962bau: goto P_0c0962ba;
case 0x0c0962bcu: goto P_0c0962bc;
case 0x0c0962beu: goto P_0c0962be;
case 0x0c0962c0u: goto P_0c0962c0;
case 0x0c0962c2u: goto P_0c0962c2;
case 0x0c0962c4u: goto P_0c0962c4;
case 0x0c0962c6u: goto P_0c0962c6;
case 0x0c0962c8u: goto P_0c0962c8;
case 0x0c0962cau: goto P_0c0962ca;
case 0x0c0962ccu: goto P_0c0962cc;
case 0x0c0962ceu: goto P_0c0962ce;
case 0x0c0962d0u: goto P_0c0962d0;
case 0x0c0962d2u: goto P_0c0962d2;
case 0x0c0962d4u: goto P_0c0962d4;
case 0x0c0962d6u: goto P_0c0962d6;
case 0x0c0962d8u: goto P_0c0962d8;
case 0x0c0962dau: goto P_0c0962da;
case 0x0c0962dcu: goto P_0c0962dc;
case 0x0c0962deu: goto P_0c0962de;
case 0x0c0962e0u: goto P_0c0962e0;
case 0x0c0962e2u: goto P_0c0962e2;
case 0x0c0962e4u: goto P_0c0962e4;
case 0x0c0962e6u: goto P_0c0962e6;
case 0x0c0962e8u: goto P_0c0962e8;
case 0x0c0962eau: goto P_0c0962ea;
case 0x0c0962ecu: goto P_0c0962ec;
case 0x0c0962eeu: goto P_0c0962ee;
case 0x0c0962f0u: goto P_0c0962f0;
case 0x0c0962f2u: goto P_0c0962f2;
case 0x0c0962f4u: goto P_0c0962f4;
case 0x0c0962f6u: goto P_0c0962f6;
case 0x0c0962f8u: goto P_0c0962f8;
case 0x0c0962fau: goto P_0c0962fa;
case 0x0c0962fcu: goto P_0c0962fc;
case 0x0c0962feu: goto P_0c0962fe;
case 0x0c096300u: goto P_0c096300;
case 0x0c096302u: goto P_0c096302;
case 0x0c096304u: goto P_0c096304;
case 0x0c096306u: goto P_0c096306;
case 0x0c096308u: goto P_0c096308;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0955b0: /* original 4f22, guest PC 0x0c0955b0 */
if(!s->budget--) { s->failed_pc=0x0c0955b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0955b2;
P_0c0955b2: /* original 7ff0, guest PC 0x0c0955b2 */
if(!s->budget--) { s->failed_pc=0x0c0955b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0955b4;
P_0c0955b4: /* original 1f42, guest PC 0x0c0955b4 */
if(!s->budget--) { s->failed_pc=0x0c0955b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0955b6;
P_0c0955b6: /* original 1f51, guest PC 0x0c0955b6 */
if(!s->budget--) { s->failed_pc=0x0c0955b6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0955b8;
P_0c0955b8: /* original 2f62, guest PC 0x0c0955b8 */
if(!s->budget--) { s->failed_pc=0x0c0955b8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0955ba;
P_0c0955ba: /* original 1f73, guest PC 0x0c0955ba */
if(!s->budget--) { s->failed_pc=0x0c0955bau; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0955bc;
P_0c0955bc: /* original d34e, guest PC 0x0c0955bc */
if(!s->budget--) { s->failed_pc=0x0c0955bcu; return 0; }
r[3]=read(ram,0x0c0956f8u,4);
goto P_0c0955be;
P_0c0955be: /* original 430b, guest PC 0x0c0955be */
if(!s->budget--) { s->failed_pc=0x0c0955beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0955c2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c2u) { target=s->pc; goto dispatch; }
goto P_0c0955c2;
P_0c0955c0: /* original e400, guest PC 0x0c0955c0 */
if(!s->budget--) { s->failed_pc=0x0c0955c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0955c2;
P_0c0955c2: /* original d24e, guest PC 0x0c0955c2 */
if(!s->budget--) { s->failed_pc=0x0c0955c2u; return 0; }
r[2]=read(ram,0x0c0956fcu,4);
goto P_0c0955c4;
P_0c0955c4: /* original 420b, guest PC 0x0c0955c4 */
if(!s->budget--) { s->failed_pc=0x0c0955c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0955c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c8u) { target=s->pc; goto dispatch; }
goto P_0c0955c8;
P_0c0955c6: /* original 0009, guest PC 0x0c0955c6 */
if(!s->budget--) { s->failed_pc=0x0c0955c6u; return 0; }
goto P_0c0955c8;
P_0c0955c8: /* original d34d, guest PC 0x0c0955c8 */
if(!s->budget--) { s->failed_pc=0x0c0955c8u; return 0; }
r[3]=read(ram,0x0c095700u,4);
goto P_0c0955ca;
P_0c0955ca: /* original 430b, guest PC 0x0c0955ca */
if(!s->budget--) { s->failed_pc=0x0c0955cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0955ceu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955ceu) { target=s->pc; goto dispatch; }
goto P_0c0955ce;
P_0c0955cc: /* original 54f6, guest PC 0x0c0955cc */
if(!s->budget--) { s->failed_pc=0x0c0955ccu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0955ce;
P_0c0955ce: /* original d34d, guest PC 0x0c0955ce */
if(!s->budget--) { s->failed_pc=0x0c0955ceu; return 0; }
r[3]=read(ram,0x0c095704u,4);
goto P_0c0955d0;
P_0c0955d0: /* original 430b, guest PC 0x0c0955d0 */
if(!s->budget--) { s->failed_pc=0x0c0955d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955d4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955d4u) { target=s->pc; goto dispatch; }
goto P_0c0955d4;
P_0c0955d2: /* original 54f5, guest PC 0x0c0955d2 */
if(!s->budget--) { s->failed_pc=0x0c0955d2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0955d4;
P_0c0955d4: /* original d34c, guest PC 0x0c0955d4 */
if(!s->budget--) { s->failed_pc=0x0c0955d4u; return 0; }
r[3]=read(ram,0x0c095708u,4);
goto P_0c0955d6;
P_0c0955d6: /* original 430b, guest PC 0x0c0955d6 */
if(!s->budget--) { s->failed_pc=0x0c0955d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955dau;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955dau) { target=s->pc; goto dispatch; }
goto P_0c0955da;
P_0c0955d8: /* original 54f3, guest PC 0x0c0955d8 */
if(!s->budget--) { s->failed_pc=0x0c0955d8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0955da;
P_0c0955da: /* original d24c, guest PC 0x0c0955da */
if(!s->budget--) { s->failed_pc=0x0c0955dau; return 0; }
r[2]=read(ram,0x0c09570cu,4);
goto P_0c0955dc;
P_0c0955dc: /* original 420b, guest PC 0x0c0955dc */
if(!s->budget--) { s->failed_pc=0x0c0955dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0955e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955e0u) { target=s->pc; goto dispatch; }
goto P_0c0955e0;
P_0c0955de: /* original e400, guest PC 0x0c0955de */
if(!s->budget--) { s->failed_pc=0x0c0955deu; return 0; }
r[4]=0x00000000u;
goto P_0c0955e0;
P_0c0955e0: /* original 6403, guest PC 0x0c0955e0 */
if(!s->budget--) { s->failed_pc=0x0c0955e0u; return 0; }
r[4]=r[0];
goto P_0c0955e2;
P_0c0955e2: /* original e020, guest PC 0x0c0955e2 */
if(!s->budget--) { s->failed_pc=0x0c0955e2u; return 0; }
r[0]=0x00000020u;
goto P_0c0955e4;
P_0c0955e4: /* original f346, guest PC 0x0c0955e4 */
if(!s->budget--) { s->failed_pc=0x0c0955e4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955e6;
P_0c0955e6: /* original e024, guest PC 0x0c0955e6 */
if(!s->budget--) { s->failed_pc=0x0c0955e6u; return 0; }
r[0]=0x00000024u;
goto P_0c0955e8;
P_0c0955e8: /* original 53f2, guest PC 0x0c0955e8 */
if(!s->budget--) { s->failed_pc=0x0c0955e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0955ea;
P_0c0955ea: /* original f33a, guest PC 0x0c0955ea */
if(!s->budget--) { s->failed_pc=0x0c0955eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955ec;
P_0c0955ec: /* original f346, guest PC 0x0c0955ec */
if(!s->budget--) { s->failed_pc=0x0c0955ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955ee;
P_0c0955ee: /* original e028, guest PC 0x0c0955ee */
if(!s->budget--) { s->failed_pc=0x0c0955eeu; return 0; }
r[0]=0x00000028u;
goto P_0c0955f0;
P_0c0955f0: /* original 53f1, guest PC 0x0c0955f0 */
if(!s->budget--) { s->failed_pc=0x0c0955f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0955f2;
P_0c0955f2: /* original f33a, guest PC 0x0c0955f2 */
if(!s->budget--) { s->failed_pc=0x0c0955f2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955f4;
P_0c0955f4: /* original f346, guest PC 0x0c0955f4 */
if(!s->budget--) { s->failed_pc=0x0c0955f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955f6;
P_0c0955f6: /* original e401, guest PC 0x0c0955f6 */
if(!s->budget--) { s->failed_pc=0x0c0955f6u; return 0; }
r[4]=0x00000001u;
goto P_0c0955f8;
P_0c0955f8: /* original 63f2, guest PC 0x0c0955f8 */
if(!s->budget--) { s->failed_pc=0x0c0955f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0955fa;
P_0c0955fa: /* original 7f10, guest PC 0x0c0955fa */
if(!s->budget--) { s->failed_pc=0x0c0955fau; return 0; }
r[15]+=0x00000010u;
goto P_0c0955fc;
P_0c0955fc: /* original f33a, guest PC 0x0c0955fc */
if(!s->budget--) { s->failed_pc=0x0c0955fcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955fe;
P_0c0955fe: /* original d344, guest PC 0x0c0955fe */
if(!s->budget--) { s->failed_pc=0x0c0955feu; return 0; }
r[3]=read(ram,0x0c095710u,4);
goto P_0c095600;
P_0c095600: /* original 432b, guest PC 0x0c095600 */
if(!s->budget--) { s->failed_pc=0x0c095600u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c095602: /* original 4f26, guest PC 0x0c095602 */
if(!s->budget--) { s->failed_pc=0x0c095602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c095604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095604u; return 0; } return 1;
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c0961f4: /* original 5352, guest PC 0x0c0961f4 */
if(!s->budget--) { s->failed_pc=0x0c0961f4u; return 0; }
r[3]=read(ram,r[5]+8,4);
goto P_0c0961f6;
P_0c0961f6: /* original 2348, guest PC 0x0c0961f6 */
if(!s->budget--) { s->failed_pc=0x0c0961f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0961f8;
P_0c0961f8: /* original 8d01, guest PC 0x0c0961f8 */
if(!s->budget--) { s->failed_pc=0x0c0961f8u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c0961fe; }
goto P_0c0961fc;
P_0c0961fa: /* original e600, guest PC 0x0c0961fa */
if(!s->budget--) { s->failed_pc=0x0c0961fau; return 0; }
r[6]=0x00000000u;
goto P_0c0961fc;
P_0c0961fc: /* original e604, guest PC 0x0c0961fc */
if(!s->budget--) { s->failed_pc=0x0c0961fcu; return 0; }
r[6]=0x00000004u;
goto P_0c0961fe;
P_0c0961fe: /* original 5353, guest PC 0x0c0961fe */
if(!s->budget--) { s->failed_pc=0x0c0961feu; return 0; }
r[3]=read(ram,r[5]+12,4);
goto P_0c096200;
P_0c096200: /* original 2348, guest PC 0x0c096200 */
if(!s->budget--) { s->failed_pc=0x0c096200u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c096202;
P_0c096202: /* original 8d02, guest PC 0x0c096202 */
if(!s->budget--) { s->failed_pc=0x0c096202u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[5],4);
r[3]=tmp;
if(cond) { goto P_0c09620a; }
goto P_0c096206;
P_0c096204: /* original 6352, guest PC 0x0c096204 */
if(!s->budget--) { s->failed_pc=0x0c096204u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c096206;
P_0c096206: /* original e108, guest PC 0x0c096206 */
if(!s->budget--) { s->failed_pc=0x0c096206u; return 0; }
r[1]=0x00000008u;
goto P_0c096208;
P_0c096208: /* original 261b, guest PC 0x0c096208 */
if(!s->budget--) { s->failed_pc=0x0c096208u; return 0; }
r[6]|=r[1];
goto P_0c09620a;
P_0c09620a: /* original 2348, guest PC 0x0c09620a */
if(!s->budget--) { s->failed_pc=0x0c09620au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c09620c;
P_0c09620c: /* original 8d02, guest PC 0x0c09620c */
if(!s->budget--) { s->failed_pc=0x0c09620cu; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[5]+4,4);
if(cond) { goto P_0c096214; }
goto P_0c096210;
P_0c09620e: /* original 5351, guest PC 0x0c09620e */
if(!s->budget--) { s->failed_pc=0x0c09620eu; return 0; }
r[3]=read(ram,r[5]+4,4);
goto P_0c096210;
P_0c096210: /* original e101, guest PC 0x0c096210 */
if(!s->budget--) { s->failed_pc=0x0c096210u; return 0; }
r[1]=0x00000001u;
goto P_0c096212;
P_0c096212: /* original 261b, guest PC 0x0c096212 */
if(!s->budget--) { s->failed_pc=0x0c096212u; return 0; }
r[6]|=r[1];
goto P_0c096214;
P_0c096214: /* original 2348, guest PC 0x0c096214 */
if(!s->budget--) { s->failed_pc=0x0c096214u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c096216;
P_0c096216: /* original 8d02, guest PC 0x0c096216 */
if(!s->budget--) { s->failed_pc=0x0c096216u; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[5]+24,4);
if(cond) { goto P_0c09621e; }
goto P_0c09621a;
P_0c096218: /* original 5356, guest PC 0x0c096218 */
if(!s->budget--) { s->failed_pc=0x0c096218u; return 0; }
r[3]=read(ram,r[5]+24,4);
goto P_0c09621a;
P_0c09621a: /* original e102, guest PC 0x0c09621a */
if(!s->budget--) { s->failed_pc=0x0c09621au; return 0; }
r[1]=0x00000002u;
goto P_0c09621c;
P_0c09621c: /* original 261b, guest PC 0x0c09621c */
if(!s->budget--) { s->failed_pc=0x0c09621cu; return 0; }
r[6]|=r[1];
goto P_0c09621e;
P_0c09621e: /* original 2348, guest PC 0x0c09621e */
if(!s->budget--) { s->failed_pc=0x0c09621eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c096220;
P_0c096220: /* original 8d02, guest PC 0x0c096220 */
if(!s->budget--) { s->failed_pc=0x0c096220u; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[5]+20,4);
if(cond) { goto P_0c096228; }
goto P_0c096224;
P_0c096222: /* original 5355, guest PC 0x0c096222 */
if(!s->budget--) { s->failed_pc=0x0c096222u; return 0; }
r[3]=read(ram,r[5]+20,4);
goto P_0c096224;
P_0c096224: /* original e110, guest PC 0x0c096224 */
if(!s->budget--) { s->failed_pc=0x0c096224u; return 0; }
r[1]=0x00000010u;
goto P_0c096226;
P_0c096226: /* original 261b, guest PC 0x0c096226 */
if(!s->budget--) { s->failed_pc=0x0c096226u; return 0; }
r[6]|=r[1];
goto P_0c096228;
P_0c096228: /* original 2348, guest PC 0x0c096228 */
if(!s->budget--) { s->failed_pc=0x0c096228u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c09622a;
P_0c09622a: /* original 8d02, guest PC 0x0c09622a */
if(!s->budget--) { s->failed_pc=0x0c09622au; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[5]+28,4);
if(cond) { goto P_0c096232; }
goto P_0c09622e;
P_0c09622c: /* original 5357, guest PC 0x0c09622c */
if(!s->budget--) { s->failed_pc=0x0c09622cu; return 0; }
r[3]=read(ram,r[5]+28,4);
goto P_0c09622e;
P_0c09622e: /* original e120, guest PC 0x0c09622e */
if(!s->budget--) { s->failed_pc=0x0c09622eu; return 0; }
r[1]=0x00000020u;
goto P_0c096230;
P_0c096230: /* original 261b, guest PC 0x0c096230 */
if(!s->budget--) { s->failed_pc=0x0c096230u; return 0; }
r[6]|=r[1];
goto P_0c096232;
P_0c096232: /* original 2348, guest PC 0x0c096232 */
if(!s->budget--) { s->failed_pc=0x0c096232u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c096234;
P_0c096234: /* original 8d02, guest PC 0x0c096234 */
if(!s->budget--) { s->failed_pc=0x0c096234u; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[5]+32,4);
if(cond) { goto P_0c09623c; }
goto P_0c096238;
P_0c096236: /* original 5358, guest PC 0x0c096236 */
if(!s->budget--) { s->failed_pc=0x0c096236u; return 0; }
r[3]=read(ram,r[5]+32,4);
goto P_0c096238;
P_0c096238: /* original e140, guest PC 0x0c096238 */
if(!s->budget--) { s->failed_pc=0x0c096238u; return 0; }
r[1]=0x00000040u;
goto P_0c09623a;
P_0c09623a: /* original 261b, guest PC 0x0c09623a */
if(!s->budget--) { s->failed_pc=0x0c09623au; return 0; }
r[6]|=r[1];
goto P_0c09623c;
P_0c09623c: /* original 2438, guest PC 0x0c09623c */
if(!s->budget--) { s->failed_pc=0x0c09623cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c09623e;
P_0c09623e: /* original 8901, guest PC 0x0c09623e */
if(!s->budget--) { s->failed_pc=0x0c09623eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096244; }
goto P_0c096240;
P_0c096240: /* original 9163, guest PC 0x0c096240 */
if(!s->budget--) { s->failed_pc=0x0c096240u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09630au,2);
goto P_0c096242;
P_0c096242: /* original 261b, guest PC 0x0c096242 */
if(!s->budget--) { s->failed_pc=0x0c096242u; return 0; }
r[6]|=r[1];
goto P_0c096244;
P_0c096244: /* original 000b, guest PC 0x0c096244 */
if(!s->budget--) { s->failed_pc=0x0c096244u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c096246: /* original 6063, guest PC 0x0c096246 */
if(!s->budget--) { s->failed_pc=0x0c096246u; return 0; }
r[0]=r[6];
goto P_0c096248;
P_0c096248: /* original 2fe6, guest PC 0x0c096248 */
if(!s->budget--) { s->failed_pc=0x0c096248u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09624a;
P_0c09624a: /* original 2fd6, guest PC 0x0c09624a */
if(!s->budget--) { s->failed_pc=0x0c09624au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09624c;
P_0c09624c: /* original 6d53, guest PC 0x0c09624c */
if(!s->budget--) { s->failed_pc=0x0c09624cu; return 0; }
r[13]=r[5];
goto P_0c09624e;
P_0c09624e: /* original 2fc6, guest PC 0x0c09624e */
if(!s->budget--) { s->failed_pc=0x0c09624eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096250;
P_0c096250: /* original 2fb6, guest PC 0x0c096250 */
if(!s->budget--) { s->failed_pc=0x0c096250u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096252;
P_0c096252: /* original 2fa6, guest PC 0x0c096252 */
if(!s->budget--) { s->failed_pc=0x0c096252u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096254;
P_0c096254: /* original 2f96, guest PC 0x0c096254 */
if(!s->budget--) { s->failed_pc=0x0c096254u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096256;
P_0c096256: /* original 2f86, guest PC 0x0c096256 */
if(!s->budget--) { s->failed_pc=0x0c096256u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096258;
P_0c096258: /* original 4f22, guest PC 0x0c096258 */
if(!s->budget--) { s->failed_pc=0x0c096258u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09625a;
P_0c09625a: /* original da2d, guest PC 0x0c09625a */
if(!s->budget--) { s->failed_pc=0x0c09625au; return 0; }
r[10]=read(ram,0x0c096310u,4);
goto P_0c09625c;
P_0c09625c: /* original d32d, guest PC 0x0c09625c */
if(!s->budget--) { s->failed_pc=0x0c09625cu; return 0; }
r[3]=read(ram,0x0c096314u,4);
goto P_0c09625e;
P_0c09625e: /* original 430b, guest PC 0x0c09625e */
if(!s->budget--) { s->failed_pc=0x0c09625eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096262u;
r[12]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096262u) { target=s->pc; goto dispatch; }
goto P_0c096262;
P_0c096260: /* original 6c63, guest PC 0x0c096260 */
if(!s->budget--) { s->failed_pc=0x0c096260u; return 0; }
r[12]=r[6];
goto P_0c096262;
P_0c096262: /* original 6e03, guest PC 0x0c096262 */
if(!s->budget--) { s->failed_pc=0x0c096262u; return 0; }
r[14]=r[0];
goto P_0c096264;
P_0c096264: /* original 60e2, guest PC 0x0c096264 */
if(!s->budget--) { s->failed_pc=0x0c096264u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c096266;
P_0c096266: /* original 88ff, guest PC 0x0c096266 */
if(!s->budget--) { s->failed_pc=0x0c096266u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c096268;
P_0c096268: /* original 8946, guest PC 0x0c096268 */
if(!s->budget--) { s->failed_pc=0x0c096268u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0962f8; }
goto P_0c09626a;
P_0c09626a: /* original 68d3, guest PC 0x0c09626a */
if(!s->budget--) { s->failed_pc=0x0c09626au; return 0; }
r[8]=r[13];
goto P_0c09626c;
P_0c09626c: /* original 4808, guest PC 0x0c09626c */
if(!s->budget--) { s->failed_pc=0x0c09626cu; return 0; }
r[8]<<=2;
goto P_0c09626e;
P_0c09626e: /* original 4800, guest PC 0x0c09626e */
if(!s->budget--) { s->failed_pc=0x0c09626eu; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c096270;
P_0c096270: /* original 65c3, guest PC 0x0c096270 */
if(!s->budget--) { s->failed_pc=0x0c096270u; return 0; }
r[5]=r[12];
goto P_0c096272;
P_0c096272: /* original 7808, guest PC 0x0c096272 */
if(!s->budget--) { s->failed_pc=0x0c096272u; return 0; }
r[8]+=0x00000008u;
goto P_0c096274;
P_0c096274: /* original bfbe, guest PC 0x0c096274 */
if(!s->budget--) { s->failed_pc=0x0c096274u; return 0; }
target=code_base|0x0c0961f4u; r[16]=code_base|0x0c096278u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096278u) { target=s->pc; goto dispatch; }
goto P_0c096278;
P_0c096276: /* original 54e4, guest PC 0x0c096276 */
if(!s->budget--) { s->failed_pc=0x0c096276u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c096278;
P_0c096278: /* original 408d, guest PC 0x0c096278 */
if(!s->budget--) { s->failed_pc=0x0c096278u; return 0; }
r[0]=(r[8]&0x80000000u)?((r[8]&31u)?r[0]>>((-r[8])&31u):0):r[0]<<(r[8]&31u);
goto P_0c09627a;
P_0c09627a: /* original 65c3, guest PC 0x0c09627a */
if(!s->budget--) { s->failed_pc=0x0c09627au; return 0; }
r[5]=r[12];
goto P_0c09627c;
P_0c09627c: /* original 6903, guest PC 0x0c09627c */
if(!s->budget--) { s->failed_pc=0x0c09627cu; return 0; }
r[9]=r[0];
goto P_0c09627e;
P_0c09627e: /* original bfb9, guest PC 0x0c09627e */
if(!s->budget--) { s->failed_pc=0x0c09627eu; return 0; }
target=code_base|0x0c0961f4u; r[16]=code_base|0x0c096282u;
r[4]=read(ram,r[14]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096282u) { target=s->pc; goto dispatch; }
goto P_0c096282;
P_0c096280: /* original 54e2, guest PC 0x0c096280 */
if(!s->budget--) { s->failed_pc=0x0c096280u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c096282;
P_0c096282: /* original 408d, guest PC 0x0c096282 */
if(!s->budget--) { s->failed_pc=0x0c096282u; return 0; }
r[0]=(r[8]&0x80000000u)?((r[8]&31u)?r[0]>>((-r[8])&31u):0):r[0]<<(r[8]&31u);
goto P_0c096284;
P_0c096284: /* original 65c3, guest PC 0x0c096284 */
if(!s->budget--) { s->failed_pc=0x0c096284u; return 0; }
r[5]=r[12];
goto P_0c096286;
P_0c096286: /* original 6b03, guest PC 0x0c096286 */
if(!s->budget--) { s->failed_pc=0x0c096286u; return 0; }
r[11]=r[0];
goto P_0c096288;
P_0c096288: /* original bfb4, guest PC 0x0c096288 */
if(!s->budget--) { s->failed_pc=0x0c096288u; return 0; }
target=code_base|0x0c0961f4u; r[16]=code_base|0x0c09628cu;
r[4]=read(ram,r[14]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09628cu) { target=s->pc; goto dispatch; }
goto P_0c09628c;
P_0c09628a: /* original 54e3, guest PC 0x0c09628a */
if(!s->budget--) { s->failed_pc=0x0c09628au; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c09628c;
P_0c09628c: /* original 52e4, guest PC 0x0c09628c */
if(!s->budget--) { s->failed_pc=0x0c09628cu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c09628e;
P_0c09628e: /* original e608, guest PC 0x0c09628e */
if(!s->budget--) { s->failed_pc=0x0c09628eu; return 0; }
r[6]=0x00000008u;
goto P_0c096290;
P_0c096290: /* original 408d, guest PC 0x0c096290 */
if(!s->budget--) { s->failed_pc=0x0c096290u; return 0; }
r[0]=(r[8]&0x80000000u)?((r[8]&31u)?r[0]>>((-r[8])&31u):0):r[0]<<(r[8]&31u);
goto P_0c096292;
P_0c096292: /* original 2268, guest PC 0x0c096292 */
if(!s->budget--) { s->failed_pc=0x0c096292u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c096294;
P_0c096294: /* original 6403, guest PC 0x0c096294 */
if(!s->budget--) { s->failed_pc=0x0c096294u; return 0; }
r[4]=r[0];
goto P_0c096296;
P_0c096296: /* original 8d03, guest PC 0x0c096296 */
if(!s->budget--) { s->failed_pc=0x0c096296u; return 0; }
cond=r[17]&1u;
r[5]=0x00000010u;
if(cond) { goto P_0c0962a0; }
goto P_0c09629a;
P_0c096298: /* original e510, guest PC 0x0c096298 */
if(!s->budget--) { s->failed_pc=0x0c096298u; return 0; }
r[5]=0x00000010u;
goto P_0c09629a;
P_0c09629a: /* original 6153, guest PC 0x0c09629a */
if(!s->budget--) { s->failed_pc=0x0c09629au; return 0; }
r[1]=r[5];
goto P_0c09629c;
P_0c09629c: /* original 41dc, guest PC 0x0c09629c */
if(!s->budget--) { s->failed_pc=0x0c09629cu; return 0; }
r[1]=(r[13]&0x80000000u)?((r[13]&31u)?(uint32_t)((int32_t)r[1]>>((-r[13])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[13]&31u);
goto P_0c09629e;
P_0c09629e: /* original 291b, guest PC 0x0c09629e */
if(!s->budget--) { s->failed_pc=0x0c09629eu; return 0; }
r[9]|=r[1];
goto P_0c0962a0;
P_0c0962a0: /* original 53e2, guest PC 0x0c0962a0 */
if(!s->budget--) { s->failed_pc=0x0c0962a0u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0962a2;
P_0c0962a2: /* original 2368, guest PC 0x0c0962a2 */
if(!s->budget--) { s->failed_pc=0x0c0962a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0962a4;
P_0c0962a4: /* original 8d03, guest PC 0x0c0962a4 */
if(!s->budget--) { s->failed_pc=0x0c0962a4u; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[14]+12,4);
if(cond) { goto P_0c0962ae; }
goto P_0c0962a8;
P_0c0962a6: /* original 53e3, guest PC 0x0c0962a6 */
if(!s->budget--) { s->failed_pc=0x0c0962a6u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c0962a8;
P_0c0962a8: /* original 6153, guest PC 0x0c0962a8 */
if(!s->budget--) { s->failed_pc=0x0c0962a8u; return 0; }
r[1]=r[5];
goto P_0c0962aa;
P_0c0962aa: /* original 41dc, guest PC 0x0c0962aa */
if(!s->budget--) { s->failed_pc=0x0c0962aau; return 0; }
r[1]=(r[13]&0x80000000u)?((r[13]&31u)?(uint32_t)((int32_t)r[1]>>((-r[13])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[13]&31u);
goto P_0c0962ac;
P_0c0962ac: /* original 2b1b, guest PC 0x0c0962ac */
if(!s->budget--) { s->failed_pc=0x0c0962acu; return 0; }
r[11]|=r[1];
goto P_0c0962ae;
P_0c0962ae: /* original 2638, guest PC 0x0c0962ae */
if(!s->budget--) { s->failed_pc=0x0c0962aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0962b0;
P_0c0962b0: /* original 8901, guest PC 0x0c0962b0 */
if(!s->budget--) { s->failed_pc=0x0c0962b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0962b6; }
goto P_0c0962b2;
P_0c0962b2: /* original 45dc, guest PC 0x0c0962b2 */
if(!s->budget--) { s->failed_pc=0x0c0962b2u; return 0; }
r[5]=(r[13]&0x80000000u)?((r[13]&31u)?(uint32_t)((int32_t)r[5]>>((-r[13])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[13]&31u);
goto P_0c0962b4;
P_0c0962b4: /* original 245b, guest PC 0x0c0962b4 */
if(!s->budget--) { s->failed_pc=0x0c0962b4u; return 0; }
r[4]|=r[5];
goto P_0c0962b6;
P_0c0962b6: /* original 52e4, guest PC 0x0c0962b6 */
if(!s->budget--) { s->failed_pc=0x0c0962b6u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0962b8;
P_0c0962b8: /* original 53c4, guest PC 0x0c0962b8 */
if(!s->budget--) { s->failed_pc=0x0c0962b8u; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c0962ba;
P_0c0962ba: /* original d517, guest PC 0x0c0962ba */
if(!s->budget--) { s->failed_pc=0x0c0962bau; return 0; }
r[5]=read(ram,0x0c096318u,4);
goto P_0c0962bc;
P_0c0962bc: /* original 2238, guest PC 0x0c0962bc */
if(!s->budget--) { s->failed_pc=0x0c0962bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0962be;
P_0c0962be: /* original 8d03, guest PC 0x0c0962be */
if(!s->budget--) { s->failed_pc=0x0c0962beu; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[12]+16,4);
if(cond) { goto P_0c0962c8; }
goto P_0c0962c2;
P_0c0962c0: /* original 53c4, guest PC 0x0c0962c0 */
if(!s->budget--) { s->failed_pc=0x0c0962c0u; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c0962c2;
P_0c0962c2: /* original 6053, guest PC 0x0c0962c2 */
if(!s->budget--) { s->failed_pc=0x0c0962c2u; return 0; }
r[0]=r[5];
goto P_0c0962c4;
P_0c0962c4: /* original 40dc, guest PC 0x0c0962c4 */
if(!s->budget--) { s->failed_pc=0x0c0962c4u; return 0; }
r[0]=(r[13]&0x80000000u)?((r[13]&31u)?(uint32_t)((int32_t)r[0]>>((-r[13])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[13]&31u);
goto P_0c0962c6;
P_0c0962c6: /* original 290b, guest PC 0x0c0962c6 */
if(!s->budget--) { s->failed_pc=0x0c0962c6u; return 0; }
r[9]|=r[0];
goto P_0c0962c8;
P_0c0962c8: /* original 52e2, guest PC 0x0c0962c8 */
if(!s->budget--) { s->failed_pc=0x0c0962c8u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0962ca;
P_0c0962ca: /* original 2238, guest PC 0x0c0962ca */
if(!s->budget--) { s->failed_pc=0x0c0962cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0962cc;
P_0c0962cc: /* original 8d03, guest PC 0x0c0962cc */
if(!s->budget--) { s->failed_pc=0x0c0962ccu; return 0; }
cond=r[17]&1u;
r[3]=read(ram,r[12]+16,4);
if(cond) { goto P_0c0962d6; }
goto P_0c0962d0;
P_0c0962ce: /* original 53c4, guest PC 0x0c0962ce */
if(!s->budget--) { s->failed_pc=0x0c0962ceu; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c0962d0;
P_0c0962d0: /* original 6053, guest PC 0x0c0962d0 */
if(!s->budget--) { s->failed_pc=0x0c0962d0u; return 0; }
r[0]=r[5];
goto P_0c0962d2;
P_0c0962d2: /* original 40dc, guest PC 0x0c0962d2 */
if(!s->budget--) { s->failed_pc=0x0c0962d2u; return 0; }
r[0]=(r[13]&0x80000000u)?((r[13]&31u)?(uint32_t)((int32_t)r[0]>>((-r[13])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[13]&31u);
goto P_0c0962d4;
P_0c0962d4: /* original 2b0b, guest PC 0x0c0962d4 */
if(!s->budget--) { s->failed_pc=0x0c0962d4u; return 0; }
r[11]|=r[0];
goto P_0c0962d6;
P_0c0962d6: /* original 52e3, guest PC 0x0c0962d6 */
if(!s->budget--) { s->failed_pc=0x0c0962d6u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0962d8;
P_0c0962d8: /* original 2238, guest PC 0x0c0962d8 */
if(!s->budget--) { s->failed_pc=0x0c0962d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0962da;
P_0c0962da: /* original 8901, guest PC 0x0c0962da */
if(!s->budget--) { s->failed_pc=0x0c0962dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0962e0; }
goto P_0c0962dc;
P_0c0962dc: /* original 45dc, guest PC 0x0c0962dc */
if(!s->budget--) { s->failed_pc=0x0c0962dcu; return 0; }
r[5]=(r[13]&0x80000000u)?((r[13]&31u)?(uint32_t)((int32_t)r[5]>>((-r[13])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[13]&31u);
goto P_0c0962de;
P_0c0962de: /* original 245b, guest PC 0x0c0962de */
if(!s->budget--) { s->failed_pc=0x0c0962deu; return 0; }
r[4]|=r[5];
goto P_0c0962e0;
P_0c0962e0: /* original 9014, guest PC 0x0c0962e0 */
if(!s->budget--) { s->failed_pc=0x0c0962e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09630cu,2);
goto P_0c0962e2;
P_0c0962e2: /* original 03ae, guest PC 0x0c0962e2 */
if(!s->budget--) { s->failed_pc=0x0c0962e2u; return 0; }
r[3]=read(ram,r[10]+r[0],4);
goto P_0c0962e4;
P_0c0962e4: /* original 239b, guest PC 0x0c0962e4 */
if(!s->budget--) { s->failed_pc=0x0c0962e4u; return 0; }
r[3]|=r[9];
goto P_0c0962e6;
P_0c0962e6: /* original 0a36, guest PC 0x0c0962e6 */
if(!s->budget--) { s->failed_pc=0x0c0962e6u; return 0; }
write(ram,r[10]+r[0],r[3],4);
goto P_0c0962e8;
P_0c0962e8: /* original 7004, guest PC 0x0c0962e8 */
if(!s->budget--) { s->failed_pc=0x0c0962e8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0962ea;
P_0c0962ea: /* original 02ae, guest PC 0x0c0962ea */
if(!s->budget--) { s->failed_pc=0x0c0962eau; return 0; }
r[2]=read(ram,r[10]+r[0],4);
goto P_0c0962ec;
P_0c0962ec: /* original 22bb, guest PC 0x0c0962ec */
if(!s->budget--) { s->failed_pc=0x0c0962ecu; return 0; }
r[2]|=r[11];
goto P_0c0962ee;
P_0c0962ee: /* original 0a26, guest PC 0x0c0962ee */
if(!s->budget--) { s->failed_pc=0x0c0962eeu; return 0; }
write(ram,r[10]+r[0],r[2],4);
goto P_0c0962f0;
P_0c0962f0: /* original 7004, guest PC 0x0c0962f0 */
if(!s->budget--) { s->failed_pc=0x0c0962f0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0962f2;
P_0c0962f2: /* original 03ae, guest PC 0x0c0962f2 */
if(!s->budget--) { s->failed_pc=0x0c0962f2u; return 0; }
r[3]=read(ram,r[10]+r[0],4);
goto P_0c0962f4;
P_0c0962f4: /* original 234b, guest PC 0x0c0962f4 */
if(!s->budget--) { s->failed_pc=0x0c0962f4u; return 0; }
r[3]|=r[4];
goto P_0c0962f6;
P_0c0962f6: /* original 0a36, guest PC 0x0c0962f6 */
if(!s->budget--) { s->failed_pc=0x0c0962f6u; return 0; }
write(ram,r[10]+r[0],r[3],4);
goto P_0c0962f8;
P_0c0962f8: /* original 4f26, guest PC 0x0c0962f8 */
if(!s->budget--) { s->failed_pc=0x0c0962f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0962fa;
P_0c0962fa: /* original 68f6, guest PC 0x0c0962fa */
if(!s->budget--) { s->failed_pc=0x0c0962fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0962fc;
P_0c0962fc: /* original 69f6, guest PC 0x0c0962fc */
if(!s->budget--) { s->failed_pc=0x0c0962fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0962fe;
P_0c0962fe: /* original 6af6, guest PC 0x0c0962fe */
if(!s->budget--) { s->failed_pc=0x0c0962feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096300;
P_0c096300: /* original 6bf6, guest PC 0x0c096300 */
if(!s->budget--) { s->failed_pc=0x0c096300u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096302;
P_0c096302: /* original 6cf6, guest PC 0x0c096302 */
if(!s->budget--) { s->failed_pc=0x0c096302u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096304;
P_0c096304: /* original 6df6, guest PC 0x0c096304 */
if(!s->budget--) { s->failed_pc=0x0c096304u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096306;
P_0c096306: /* original 000b, guest PC 0x0c096306 */
if(!s->budget--) { s->failed_pc=0x0c096306u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096308: /* original 6ef6, guest PC 0x0c096308 */
if(!s->budget--) { s->failed_pc=0x0c096308u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09630au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09630au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
