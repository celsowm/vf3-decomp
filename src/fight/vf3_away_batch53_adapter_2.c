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
int vf3_away_batch53_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c086178u: goto P_0c086178;
case 0x0c08617au: goto P_0c08617a;
case 0x0c08617cu: goto P_0c08617c;
case 0x0c08617eu: goto P_0c08617e;
case 0x0c086180u: goto P_0c086180;
case 0x0c086182u: goto P_0c086182;
case 0x0c086184u: goto P_0c086184;
case 0x0c086186u: goto P_0c086186;
case 0x0c086188u: goto P_0c086188;
case 0x0c08618au: goto P_0c08618a;
case 0x0c08618cu: goto P_0c08618c;
case 0x0c08618eu: goto P_0c08618e;
case 0x0c086190u: goto P_0c086190;
case 0x0c086192u: goto P_0c086192;
case 0x0c086194u: goto P_0c086194;
case 0x0c086196u: goto P_0c086196;
case 0x0c086198u: goto P_0c086198;
case 0x0c08619au: goto P_0c08619a;
case 0x0c08619cu: goto P_0c08619c;
case 0x0c08619eu: goto P_0c08619e;
case 0x0c0861a0u: goto P_0c0861a0;
case 0x0c0861a2u: goto P_0c0861a2;
case 0x0c0861a4u: goto P_0c0861a4;
case 0x0c0861a6u: goto P_0c0861a6;
case 0x0c0861a8u: goto P_0c0861a8;
case 0x0c0861aau: goto P_0c0861aa;
case 0x0c0861acu: goto P_0c0861ac;
case 0x0c0861aeu: goto P_0c0861ae;
case 0x0c0861b0u: goto P_0c0861b0;
case 0x0c0861b2u: goto P_0c0861b2;
case 0x0c0861b4u: goto P_0c0861b4;
case 0x0c0861b6u: goto P_0c0861b6;
case 0x0c0861b8u: goto P_0c0861b8;
case 0x0c0861bau: goto P_0c0861ba;
case 0x0c0861bcu: goto P_0c0861bc;
case 0x0c0861beu: goto P_0c0861be;
case 0x0c0861c0u: goto P_0c0861c0;
case 0x0c0861c2u: goto P_0c0861c2;
case 0x0c0861c4u: goto P_0c0861c4;
case 0x0c0861c6u: goto P_0c0861c6;
case 0x0c0861c8u: goto P_0c0861c8;
case 0x0c0861cau: goto P_0c0861ca;
case 0x0c0861ccu: goto P_0c0861cc;
case 0x0c0861ceu: goto P_0c0861ce;
case 0x0c0861d0u: goto P_0c0861d0;
case 0x0c0861d2u: goto P_0c0861d2;
case 0x0c0861d4u: goto P_0c0861d4;
case 0x0c0861d6u: goto P_0c0861d6;
case 0x0c0861d8u: goto P_0c0861d8;
case 0x0c0861dau: goto P_0c0861da;
case 0x0c0861dcu: goto P_0c0861dc;
case 0x0c0861deu: goto P_0c0861de;
case 0x0c0861e0u: goto P_0c0861e0;
case 0x0c0861e2u: goto P_0c0861e2;
case 0x0c0861e4u: goto P_0c0861e4;
case 0x0c0861e6u: goto P_0c0861e6;
case 0x0c0861e8u: goto P_0c0861e8;
case 0x0c0861eau: goto P_0c0861ea;
case 0x0c0861ecu: goto P_0c0861ec;
case 0x0c0861eeu: goto P_0c0861ee;
case 0x0c0861f0u: goto P_0c0861f0;
case 0x0c0861f2u: goto P_0c0861f2;
case 0x0c0861f4u: goto P_0c0861f4;
case 0x0c0861f6u: goto P_0c0861f6;
case 0x0c0861f8u: goto P_0c0861f8;
case 0x0c0861fau: goto P_0c0861fa;
case 0x0c0861fcu: goto P_0c0861fc;
case 0x0c0861feu: goto P_0c0861fe;
case 0x0c086200u: goto P_0c086200;
case 0x0c086202u: goto P_0c086202;
case 0x0c086204u: goto P_0c086204;
case 0x0c086206u: goto P_0c086206;
case 0x0c08648cu: goto P_0c08648c;
case 0x0c08648eu: goto P_0c08648e;
case 0x0c086490u: goto P_0c086490;
case 0x0c086492u: goto P_0c086492;
case 0x0c086494u: goto P_0c086494;
case 0x0c086496u: goto P_0c086496;
case 0x0c086498u: goto P_0c086498;
case 0x0c08649au: goto P_0c08649a;
case 0x0c08649cu: goto P_0c08649c;
case 0x0c08649eu: goto P_0c08649e;
case 0x0c0864a0u: goto P_0c0864a0;
case 0x0c0864a2u: goto P_0c0864a2;
case 0x0c0864a4u: goto P_0c0864a4;
case 0x0c0864a6u: goto P_0c0864a6;
case 0x0c0864a8u: goto P_0c0864a8;
case 0x0c0864aau: goto P_0c0864aa;
case 0x0c0864acu: goto P_0c0864ac;
case 0x0c0864aeu: goto P_0c0864ae;
case 0x0c0864b0u: goto P_0c0864b0;
case 0x0c0864b2u: goto P_0c0864b2;
case 0x0c0864b4u: goto P_0c0864b4;
case 0x0c0864b6u: goto P_0c0864b6;
case 0x0c0864b8u: goto P_0c0864b8;
case 0x0c0864bau: goto P_0c0864ba;
case 0x0c0864bcu: goto P_0c0864bc;
case 0x0c0864beu: goto P_0c0864be;
case 0x0c0864c0u: goto P_0c0864c0;
case 0x0c0864c2u: goto P_0c0864c2;
case 0x0c0864c4u: goto P_0c0864c4;
case 0x0c0864c6u: goto P_0c0864c6;
case 0x0c0864c8u: goto P_0c0864c8;
case 0x0c0864cau: goto P_0c0864ca;
case 0x0c0864ccu: goto P_0c0864cc;
case 0x0c0864ceu: goto P_0c0864ce;
case 0x0c0864d0u: goto P_0c0864d0;
case 0x0c0864d2u: goto P_0c0864d2;
case 0x0c0864d4u: goto P_0c0864d4;
case 0x0c0864d6u: goto P_0c0864d6;
case 0x0c0864d8u: goto P_0c0864d8;
case 0x0c0864dau: goto P_0c0864da;
case 0x0c0864dcu: goto P_0c0864dc;
case 0x0c0864deu: goto P_0c0864de;
case 0x0c0864e0u: goto P_0c0864e0;
case 0x0c0864e2u: goto P_0c0864e2;
case 0x0c0864e4u: goto P_0c0864e4;
case 0x0c0864e6u: goto P_0c0864e6;
case 0x0c0864e8u: goto P_0c0864e8;
case 0x0c0864eau: goto P_0c0864ea;
case 0x0c0864ecu: goto P_0c0864ec;
case 0x0c0864eeu: goto P_0c0864ee;
case 0x0c0864f0u: goto P_0c0864f0;
case 0x0c0864f2u: goto P_0c0864f2;
case 0x0c0864f4u: goto P_0c0864f4;
case 0x0c0864f6u: goto P_0c0864f6;
case 0x0c0864f8u: goto P_0c0864f8;
case 0x0c0864fau: goto P_0c0864fa;
case 0x0c0864fcu: goto P_0c0864fc;
case 0x0c0864feu: goto P_0c0864fe;
case 0x0c086500u: goto P_0c086500;
case 0x0c086502u: goto P_0c086502;
case 0x0c086504u: goto P_0c086504;
case 0x0c086506u: goto P_0c086506;
case 0x0c086508u: goto P_0c086508;
case 0x0c08650au: goto P_0c08650a;
case 0x0c08650cu: goto P_0c08650c;
case 0x0c08650eu: goto P_0c08650e;
case 0x0c086538u: goto P_0c086538;
case 0x0c08653au: goto P_0c08653a;
case 0x0c08653cu: goto P_0c08653c;
case 0x0c08653eu: goto P_0c08653e;
case 0x0c086540u: goto P_0c086540;
case 0x0c086542u: goto P_0c086542;
case 0x0c086544u: goto P_0c086544;
case 0x0c086546u: goto P_0c086546;
case 0x0c086548u: goto P_0c086548;
case 0x0c08654au: goto P_0c08654a;
case 0x0c08654cu: goto P_0c08654c;
case 0x0c08654eu: goto P_0c08654e;
case 0x0c086550u: goto P_0c086550;
case 0x0c086552u: goto P_0c086552;
case 0x0c086554u: goto P_0c086554;
case 0x0c086556u: goto P_0c086556;
case 0x0c086558u: goto P_0c086558;
case 0x0c08655au: goto P_0c08655a;
case 0x0c08655cu: goto P_0c08655c;
case 0x0c08655eu: goto P_0c08655e;
case 0x0c086560u: goto P_0c086560;
case 0x0c086562u: goto P_0c086562;
case 0x0c086564u: goto P_0c086564;
case 0x0c086566u: goto P_0c086566;
case 0x0c086568u: goto P_0c086568;
case 0x0c08656au: goto P_0c08656a;
case 0x0c08656cu: goto P_0c08656c;
case 0x0c08656eu: goto P_0c08656e;
case 0x0c086570u: goto P_0c086570;
case 0x0c086572u: goto P_0c086572;
case 0x0c086574u: goto P_0c086574;
case 0x0c086576u: goto P_0c086576;
case 0x0c086578u: goto P_0c086578;
case 0x0c08657au: goto P_0c08657a;
case 0x0c08657cu: goto P_0c08657c;
case 0x0c08657eu: goto P_0c08657e;
case 0x0c086580u: goto P_0c086580;
case 0x0c086582u: goto P_0c086582;
case 0x0c086584u: goto P_0c086584;
case 0x0c086586u: goto P_0c086586;
case 0x0c086588u: goto P_0c086588;
case 0x0c08658au: goto P_0c08658a;
case 0x0c08658cu: goto P_0c08658c;
case 0x0c08658eu: goto P_0c08658e;
case 0x0c086590u: goto P_0c086590;
case 0x0c086592u: goto P_0c086592;
case 0x0c086594u: goto P_0c086594;
case 0x0c086596u: goto P_0c086596;
case 0x0c086598u: goto P_0c086598;
case 0x0c08659au: goto P_0c08659a;
case 0x0c08659cu: goto P_0c08659c;
case 0x0c08659eu: goto P_0c08659e;
case 0x0c0865a0u: goto P_0c0865a0;
case 0x0c0865a2u: goto P_0c0865a2;
case 0x0c0865a4u: goto P_0c0865a4;
case 0x0c0865a6u: goto P_0c0865a6;
case 0x0c0865a8u: goto P_0c0865a8;
case 0x0c0865aau: goto P_0c0865aa;
case 0x0c0865acu: goto P_0c0865ac;
case 0x0c0865aeu: goto P_0c0865ae;
case 0x0c0865b0u: goto P_0c0865b0;
case 0x0c0865b2u: goto P_0c0865b2;
case 0x0c0865b4u: goto P_0c0865b4;
case 0x0c0865b6u: goto P_0c0865b6;
case 0x0c0865b8u: goto P_0c0865b8;
case 0x0c0865bau: goto P_0c0865ba;
case 0x0c0865bcu: goto P_0c0865bc;
case 0x0c0865beu: goto P_0c0865be;
case 0x0c0865c0u: goto P_0c0865c0;
case 0x0c0865c2u: goto P_0c0865c2;
case 0x0c0865c4u: goto P_0c0865c4;
case 0x0c0865c6u: goto P_0c0865c6;
case 0x0c0865c8u: goto P_0c0865c8;
case 0x0c0865cau: goto P_0c0865ca;
case 0x0c0865ccu: goto P_0c0865cc;
case 0x0c0865ceu: goto P_0c0865ce;
case 0x0c0865d0u: goto P_0c0865d0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c086178: /* original 2fe6, guest PC 0x0c086178 */
if(!s->budget--) { s->failed_pc=0x0c086178u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08617a;
P_0c08617a: /* original 2fd6, guest PC 0x0c08617a */
if(!s->budget--) { s->failed_pc=0x0c08617au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08617c;
P_0c08617c: /* original 2fc6, guest PC 0x0c08617c */
if(!s->budget--) { s->failed_pc=0x0c08617cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08617e;
P_0c08617e: /* original 2fb6, guest PC 0x0c08617e */
if(!s->budget--) { s->failed_pc=0x0c08617eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086180;
P_0c086180: /* original 2fa6, guest PC 0x0c086180 */
if(!s->budget--) { s->failed_pc=0x0c086180u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086182;
P_0c086182: /* original 4f22, guest PC 0x0c086182 */
if(!s->budget--) { s->failed_pc=0x0c086182u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086184;
P_0c086184: /* original db21, guest PC 0x0c086184 */
if(!s->budget--) { s->failed_pc=0x0c086184u; return 0; }
r[11]=read(ram,0x0c08620cu,4);
goto P_0c086186;
P_0c086186: /* original 7ffc, guest PC 0x0c086186 */
if(!s->budget--) { s->failed_pc=0x0c086186u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c086188;
P_0c086188: /* original 2f42, guest PC 0x0c086188 */
if(!s->budget--) { s->failed_pc=0x0c086188u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08618a;
P_0c08618a: /* original d321, guest PC 0x0c08618a */
if(!s->budget--) { s->failed_pc=0x0c08618au; return 0; }
r[3]=read(ram,0x0c086210u,4);
goto P_0c08618c;
P_0c08618c: /* original 430b, guest PC 0x0c08618c */
if(!s->budget--) { s->failed_pc=0x0c08618cu; return 0; }
target=r[3];
r[16]=code_base|0x0c086190u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086190u) { target=s->pc; goto dispatch; }
goto P_0c086190;
P_0c08618e: /* original e400, guest PC 0x0c08618e */
if(!s->budget--) { s->failed_pc=0x0c08618eu; return 0; }
r[4]=0x00000000u;
goto P_0c086190;
P_0c086190: /* original 64f2, guest PC 0x0c086190 */
if(!s->budget--) { s->failed_pc=0x0c086190u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c086192;
P_0c086192: /* original 9d39, guest PC 0x0c086192 */
if(!s->budget--) { s->failed_pc=0x0c086192u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086208u,2);
goto P_0c086194;
P_0c086194: /* original 5345, guest PC 0x0c086194 */
if(!s->budget--) { s->failed_pc=0x0c086194u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c086196;
P_0c086196: /* original d220, guest PC 0x0c086196 */
if(!s->budget--) { s->failed_pc=0x0c086196u; return 0; }
r[2]=read(ram,0x0c086218u,4);
goto P_0c086198;
P_0c086198: /* original 3d4c, guest PC 0x0c086198 */
if(!s->budget--) { s->failed_pc=0x0c086198u; return 0; }
r[13]+=r[4];
goto P_0c08619a;
P_0c08619a: /* original da1e, guest PC 0x0c08619a */
if(!s->budget--) { s->failed_pc=0x0c08619au; return 0; }
r[10]=read(ram,0x0c086214u,4);
goto P_0c08619c;
P_0c08619c: /* original 420b, guest PC 0x0c08619c */
if(!s->budget--) { s->failed_pc=0x0c08619cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0861a0u;
write(ram,r[11],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0861a0u) { target=s->pc; goto dispatch; }
goto P_0c0861a0;
P_0c08619e: /* original 2b32, guest PC 0x0c08619e */
if(!s->budget--) { s->failed_pc=0x0c08619eu; return 0; }
write(ram,r[11],r[3],4);
goto P_0c0861a0;
P_0c0861a0: /* original 62b2, guest PC 0x0c0861a0 */
if(!s->budget--) { s->failed_pc=0x0c0861a0u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0861a2;
P_0c0861a2: /* original 3d22, guest PC 0x0c0861a2 */
if(!s->budget--) { s->failed_pc=0x0c0861a2u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[2])!=0);
goto P_0c0861a4;
P_0c0861a4: /* original 8b04, guest PC 0x0c0861a4 */
if(!s->budget--) { s->failed_pc=0x0c0861a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0861b0; }
goto P_0c0861a6;
P_0c0861a6: /* original de1d, guest PC 0x0c0861a6 */
if(!s->budget--) { s->failed_pc=0x0c0861a6u; return 0; }
r[14]=read(ram,0x0c08621cu,4);
goto P_0c0861a8;
P_0c0861a8: /* original 4e0b, guest PC 0x0c0861a8 */
if(!s->budget--) { s->failed_pc=0x0c0861a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0861acu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0861acu) { target=s->pc; goto dispatch; }
goto P_0c0861ac;
P_0c0861aa: /* original e401, guest PC 0x0c0861aa */
if(!s->budget--) { s->failed_pc=0x0c0861aau; return 0; }
r[4]=0x00000001u;
goto P_0c0861ac;
P_0c0861ac: /* original a024, guest PC 0x0c0861ac */
if(!s->budget--) { s->failed_pc=0x0c0861acu; return 0; }
goto P_0c0861f8;
P_0c0861ae: /* original 0009, guest PC 0x0c0861ae */
if(!s->budget--) { s->failed_pc=0x0c0861aeu; return 0; }
goto P_0c0861b0;
P_0c0861b0: /* original 5cd4, guest PC 0x0c0861b0 */
if(!s->budget--) { s->failed_pc=0x0c0861b0u; return 0; }
r[12]=read(ram,r[13]+16,4);
goto P_0c0861b2;
P_0c0861b2: /* original e401, guest PC 0x0c0861b2 */
if(!s->budget--) { s->failed_pc=0x0c0861b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0861b4;
P_0c0861b4: /* original 63c3, guest PC 0x0c0861b4 */
if(!s->budget--) { s->failed_pc=0x0c0861b4u; return 0; }
r[3]=r[12];
goto P_0c0861b6;
P_0c0861b6: /* original 2348, guest PC 0x0c0861b6 */
if(!s->budget--) { s->failed_pc=0x0c0861b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0861b8;
P_0c0861b8: /* original 891c, guest PC 0x0c0861b8 */
if(!s->budget--) { s->failed_pc=0x0c0861b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0861f4; }
goto P_0c0861ba;
P_0c0861ba: /* original de19, guest PC 0x0c0861ba */
if(!s->budget--) { s->failed_pc=0x0c0861bau; return 0; }
r[14]=read(ram,0x0c086220u,4);
goto P_0c0861bc;
P_0c0861bc: /* original 4e0b, guest PC 0x0c0861bc */
if(!s->budget--) { s->failed_pc=0x0c0861bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0861c0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0861c0u) { target=s->pc; goto dispatch; }
goto P_0c0861c0;
P_0c0861be: /* original 64d3, guest PC 0x0c0861be */
if(!s->budget--) { s->failed_pc=0x0c0861beu; return 0; }
r[4]=r[13];
goto P_0c0861c0;
P_0c0861c0: /* original e00c, guest PC 0x0c0861c0 */
if(!s->budget--) { s->failed_pc=0x0c0861c0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0861c2;
P_0c0861c2: /* original f4d6, guest PC 0x0c0861c2 */
if(!s->budget--) { s->failed_pc=0x0c0861c2u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0861c4;
P_0c0861c4: /* original c717, guest PC 0x0c0861c4 */
if(!s->budget--) { s->failed_pc=0x0c0861c4u; return 0; }
r[0]=code_base|0x00086224u;
goto P_0c0861c6;
P_0c0861c6: /* original f508, guest PC 0x0c0861c6 */
if(!s->budget--) { s->failed_pc=0x0c0861c6u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0861c8;
P_0c0861c8: /* original f452, guest PC 0x0c0861c8 */
if(!s->budget--) { s->failed_pc=0x0c0861c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0861ca;
P_0c0861ca: /* original f43d, guest PC 0x0c0861ca */
if(!s->budget--) { s->failed_pc=0x0c0861cau; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0861cc;
P_0c0861cc: /* original 0e5a, guest PC 0x0c0861cc */
if(!s->budget--) { s->failed_pc=0x0c0861ccu; return 0; }
r[14]=r[53];
goto P_0c0861ce;
P_0c0861ce: /* original 4e11, guest PC 0x0c0861ce */
if(!s->budget--) { s->failed_pc=0x0c0861ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0861d0;
P_0c0861d0: /* original 8b04, guest PC 0x0c0861d0 */
if(!s->budget--) { s->failed_pc=0x0c0861d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0861dc; }
goto P_0c0861d2;
P_0c0861d2: /* original e41f, guest PC 0x0c0861d2 */
if(!s->budget--) { s->failed_pc=0x0c0861d2u; return 0; }
r[4]=0x0000001fu;
goto P_0c0861d4;
P_0c0861d4: /* original 3e47, guest PC 0x0c0861d4 */
if(!s->budget--) { s->failed_pc=0x0c0861d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[4])!=0);
goto P_0c0861d6;
P_0c0861d6: /* original 8b03, guest PC 0x0c0861d6 */
if(!s->budget--) { s->failed_pc=0x0c0861d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0861e0; }
goto P_0c0861d8;
P_0c0861d8: /* original a002, guest PC 0x0c0861d8 */
if(!s->budget--) { s->failed_pc=0x0c0861d8u; return 0; }
r[14]=r[4];
goto P_0c0861e0;
P_0c0861da: /* original 6e43, guest PC 0x0c0861da */
if(!s->budget--) { s->failed_pc=0x0c0861dau; return 0; }
r[14]=r[4];
goto P_0c0861dc;
P_0c0861dc: /* original e400, guest PC 0x0c0861dc */
if(!s->budget--) { s->failed_pc=0x0c0861dcu; return 0; }
r[4]=0x00000000u;
goto P_0c0861de;
P_0c0861de: /* original 6e43, guest PC 0x0c0861de */
if(!s->budget--) { s->failed_pc=0x0c0861deu; return 0; }
r[14]=r[4];
goto P_0c0861e0;
P_0c0861e0: /* original e402, guest PC 0x0c0861e0 */
if(!s->budget--) { s->failed_pc=0x0c0861e0u; return 0; }
r[4]=0x00000002u;
goto P_0c0861e2;
P_0c0861e2: /* original 2c48, guest PC 0x0c0861e2 */
if(!s->budget--) { s->failed_pc=0x0c0861e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[4])==0)!=0);
goto P_0c0861e4;
P_0c0861e4: /* original 8900, guest PC 0x0c0861e4 */
if(!s->budget--) { s->failed_pc=0x0c0861e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0861e8; }
goto P_0c0861e6;
P_0c0861e6: /* original 7e20, guest PC 0x0c0861e6 */
if(!s->budget--) { s->failed_pc=0x0c0861e6u; return 0; }
r[14]+=0x00000020u;
goto P_0c0861e8;
P_0c0861e8: /* original 60e3, guest PC 0x0c0861e8 */
if(!s->budget--) { s->failed_pc=0x0c0861e8u; return 0; }
r[0]=r[14];
goto P_0c0861ea;
P_0c0861ea: /* original 4000, guest PC 0x0c0861ea */
if(!s->budget--) { s->failed_pc=0x0c0861eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0861ec;
P_0c0861ec: /* original 04ad, guest PC 0x0c0861ec */
if(!s->budget--) { s->failed_pc=0x0c0861ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0861ee;
P_0c0861ee: /* original dc0e, guest PC 0x0c0861ee */
if(!s->budget--) { s->failed_pc=0x0c0861eeu; return 0; }
r[12]=read(ram,0x0c086228u,4);
goto P_0c0861f0;
P_0c0861f0: /* original 4c0b, guest PC 0x0c0861f0 */
if(!s->budget--) { s->failed_pc=0x0c0861f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0861f4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0861f4u) { target=s->pc; goto dispatch; }
goto P_0c0861f4;
P_0c0861f2: /* original 644d, guest PC 0x0c0861f2 */
if(!s->budget--) { s->failed_pc=0x0c0861f2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0861f4;
P_0c0861f4: /* original afd4, guest PC 0x0c0861f4 */
if(!s->budget--) { s->failed_pc=0x0c0861f4u; return 0; }
r[13]+=0x00000014u;
goto P_0c0861a0;
P_0c0861f6: /* original 7d14, guest PC 0x0c0861f6 */
if(!s->budget--) { s->failed_pc=0x0c0861f6u; return 0; }
r[13]+=0x00000014u;
goto P_0c0861f8;
P_0c0861f8: /* original 7f04, guest PC 0x0c0861f8 */
if(!s->budget--) { s->failed_pc=0x0c0861f8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0861fa;
P_0c0861fa: /* original 4f26, guest PC 0x0c0861fa */
if(!s->budget--) { s->failed_pc=0x0c0861fau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0861fc;
P_0c0861fc: /* original 6af6, guest PC 0x0c0861fc */
if(!s->budget--) { s->failed_pc=0x0c0861fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0861fe;
P_0c0861fe: /* original 6bf6, guest PC 0x0c0861fe */
if(!s->budget--) { s->failed_pc=0x0c0861feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c086200;
P_0c086200: /* original 6cf6, guest PC 0x0c086200 */
if(!s->budget--) { s->failed_pc=0x0c086200u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086202;
P_0c086202: /* original 6df6, guest PC 0x0c086202 */
if(!s->budget--) { s->failed_pc=0x0c086202u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086204;
P_0c086204: /* original 000b, guest PC 0x0c086204 */
if(!s->budget--) { s->failed_pc=0x0c086204u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086206: /* original 6ef6, guest PC 0x0c086206 */
if(!s->budget--) { s->failed_pc=0x0c086206u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c086208u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086208u; return 0; } return 1;
P_0c08648c: /* original 2fe6, guest PC 0x0c08648c */
if(!s->budget--) { s->failed_pc=0x0c08648cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08648e;
P_0c08648e: /* original 2fd6, guest PC 0x0c08648e */
if(!s->budget--) { s->failed_pc=0x0c08648eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086490;
P_0c086490: /* original 2fc6, guest PC 0x0c086490 */
if(!s->budget--) { s->failed_pc=0x0c086490u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086492;
P_0c086492: /* original 2fb6, guest PC 0x0c086492 */
if(!s->budget--) { s->failed_pc=0x0c086492u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086494;
P_0c086494: /* original 2fa6, guest PC 0x0c086494 */
if(!s->budget--) { s->failed_pc=0x0c086494u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086496;
P_0c086496: /* original 2f96, guest PC 0x0c086496 */
if(!s->budget--) { s->failed_pc=0x0c086496u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086498;
P_0c086498: /* original 2f86, guest PC 0x0c086498 */
if(!s->budget--) { s->failed_pc=0x0c086498u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08649a;
P_0c08649a: /* original d126, guest PC 0x0c08649a */
if(!s->budget--) { s->failed_pc=0x0c08649au; return 0; }
r[1]=read(ram,0x0c086534u,4);
goto P_0c08649c;
P_0c08649c: /* original 4f22, guest PC 0x0c08649c */
if(!s->budget--) { s->failed_pc=0x0c08649cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08649e;
P_0c08649e: /* original 6212, guest PC 0x0c08649e */
if(!s->budget--) { s->failed_pc=0x0c08649eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0864a0;
P_0c0864a0: /* original d323, guest PC 0x0c0864a0 */
if(!s->budget--) { s->failed_pc=0x0c0864a0u; return 0; }
r[3]=read(ram,0x0c086530u,4);
goto P_0c0864a2;
P_0c0864a2: /* original 2238, guest PC 0x0c0864a2 */
if(!s->budget--) { s->failed_pc=0x0c0864a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0864a4;
P_0c0864a4: /* original 8b54, guest PC 0x0c0864a4 */
if(!s->budget--) { s->failed_pc=0x0c0864a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086550; }
goto P_0c0864a6;
P_0c0864a6: /* original da1b, guest PC 0x0c0864a6 */
if(!s->budget--) { s->failed_pc=0x0c0864a6u; return 0; }
r[10]=read(ram,0x0c086514u,4);
goto P_0c0864a8;
P_0c0864a8: /* original 6c43, guest PC 0x0c0864a8 */
if(!s->budget--) { s->failed_pc=0x0c0864a8u; return 0; }
r[12]=r[4];
goto P_0c0864aa;
P_0c0864aa: /* original e900, guest PC 0x0c0864aa */
if(!s->budget--) { s->failed_pc=0x0c0864aau; return 0; }
r[9]=0x00000000u;
goto P_0c0864ac;
P_0c0864ac: /* original 6d43, guest PC 0x0c0864ac */
if(!s->budget--) { s->failed_pc=0x0c0864acu; return 0; }
r[13]=r[4];
goto P_0c0864ae;
P_0c0864ae: /* original 5ea4, guest PC 0x0c0864ae */
if(!s->budget--) { s->failed_pc=0x0c0864aeu; return 0; }
r[14]=read(ram,r[10]+16,4);
goto P_0c0864b0;
P_0c0864b0: /* original 7c28, guest PC 0x0c0864b0 */
if(!s->budget--) { s->failed_pc=0x0c0864b0u; return 0; }
r[12]+=0x00000028u;
goto P_0c0864b2;
P_0c0864b2: /* original a049, guest PC 0x0c0864b2 */
if(!s->budget--) { s->failed_pc=0x0c0864b2u; return 0; }
r[8]=r[9];
goto P_0c086548;
P_0c0864b4: /* original 6893, guest PC 0x0c0864b4 */
if(!s->budget--) { s->failed_pc=0x0c0864b4u; return 0; }
r[8]=r[9];
goto P_0c0864b6;
P_0c0864b6: /* original e061, guest PC 0x0c0864b6 */
if(!s->budget--) { s->failed_pc=0x0c0864b6u; return 0; }
r[0]=0x00000061u;
goto P_0c0864b8;
P_0c0864b8: /* original 00ec, guest PC 0x0c0864b8 */
if(!s->budget--) { s->failed_pc=0x0c0864b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0864ba;
P_0c0864ba: /* original 600c, guest PC 0x0c0864ba */
if(!s->budget--) { s->failed_pc=0x0c0864bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0864bc;
P_0c0864bc: /* original 880c, guest PC 0x0c0864bc */
if(!s->budget--) { s->failed_pc=0x0c0864bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0864be;
P_0c0864be: /* original 893f, guest PC 0x0c0864be */
if(!s->budget--) { s->failed_pc=0x0c0864beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086540; }
goto P_0c0864c0;
P_0c0864c0: /* original 9026, guest PC 0x0c0864c0 */
if(!s->budget--) { s->failed_pc=0x0c0864c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086510u,2);
goto P_0c0864c2;
P_0c0864c2: /* original e504, guest PC 0x0c0864c2 */
if(!s->budget--) { s->failed_pc=0x0c0864c2u; return 0; }
r[5]=0x00000004u;
goto P_0c0864c4;
P_0c0864c4: /* original 06ee, guest PC 0x0c0864c4 */
if(!s->budget--) { s->failed_pc=0x0c0864c4u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0864c6;
P_0c0864c6: /* original 6363, guest PC 0x0c0864c6 */
if(!s->budget--) { s->failed_pc=0x0c0864c6u; return 0; }
r[3]=r[6];
goto P_0c0864c8;
P_0c0864c8: /* original 2358, guest PC 0x0c0864c8 */
if(!s->budget--) { s->failed_pc=0x0c0864c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0864ca;
P_0c0864ca: /* original 8f0c, guest PC 0x0c0864ca */
if(!s->budget--) { s->failed_pc=0x0c0864cau; return 0; }
cond=r[17]&1u;
r[11]=r[4];
if(!cond) { goto P_0c0864e6; }
goto P_0c0864ce;
P_0c0864cc: /* original 6b43, guest PC 0x0c0864cc */
if(!s->budget--) { s->failed_pc=0x0c0864ccu; return 0; }
r[11]=r[4];
goto P_0c0864ce;
P_0c0864ce: /* original 2468, guest PC 0x0c0864ce */
if(!s->budget--) { s->failed_pc=0x0c0864ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[6])==0)!=0);
goto P_0c0864d0;
P_0c0864d0: /* original e501, guest PC 0x0c0864d0 */
if(!s->budget--) { s->failed_pc=0x0c0864d0u; return 0; }
r[5]=0x00000001u;
goto P_0c0864d2;
P_0c0864d2: /* original 8f08, guest PC 0x0c0864d2 */
if(!s->budget--) { s->failed_pc=0x0c0864d2u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(!cond) { goto P_0c0864e6; }
goto P_0c0864d6;
P_0c0864d4: /* original 6b53, guest PC 0x0c0864d4 */
if(!s->budget--) { s->failed_pc=0x0c0864d4u; return 0; }
r[11]=r[5];
goto P_0c0864d6;
P_0c0864d6: /* original 2658, guest PC 0x0c0864d6 */
if(!s->budget--) { s->failed_pc=0x0c0864d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c0864d8;
P_0c0864d8: /* original 8d05, guest PC 0x0c0864d8 */
if(!s->budget--) { s->failed_pc=0x0c0864d8u; return 0; }
cond=r[17]&1u;
r[11]=r[9];
if(cond) { goto P_0c0864e6; }
goto P_0c0864dc;
P_0c0864da: /* original 6b93, guest PC 0x0c0864da */
if(!s->budget--) { s->failed_pc=0x0c0864dau; return 0; }
r[11]=r[9];
goto P_0c0864dc;
P_0c0864dc: /* original 6b53, guest PC 0x0c0864dc */
if(!s->budget--) { s->failed_pc=0x0c0864dcu; return 0; }
r[11]=r[5];
goto P_0c0864de;
P_0c0864de: /* original 65c3, guest PC 0x0c0864de */
if(!s->budget--) { s->failed_pc=0x0c0864deu; return 0; }
r[5]=r[12];
goto P_0c0864e0;
P_0c0864e0: /* original 66e3, guest PC 0x0c0864e0 */
if(!s->budget--) { s->failed_pc=0x0c0864e0u; return 0; }
r[6]=r[14];
goto P_0c0864e2;
P_0c0864e2: /* original b03e, guest PC 0x0c0864e2 */
if(!s->budget--) { s->failed_pc=0x0c0864e2u; return 0; }
target=code_base|0x0c086562u; r[16]=code_base|0x0c0864e6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0864e6u) { target=s->pc; goto dispatch; }
goto P_0c0864e6;
P_0c0864e4: /* original 64d3, guest PC 0x0c0864e4 */
if(!s->budget--) { s->failed_pc=0x0c0864e4u; return 0; }
r[4]=r[13];
goto P_0c0864e6;
P_0c0864e6: /* original 60bf, guest PC 0x0c0864e6 */
if(!s->budget--) { s->failed_pc=0x0c0864e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c0864e8;
P_0c0864e8: /* original 8800, guest PC 0x0c0864e8 */
if(!s->budget--) { s->failed_pc=0x0c0864e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0864ea;
P_0c0864ea: /* original 8905, guest PC 0x0c0864ea */
if(!s->budget--) { s->failed_pc=0x0c0864eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0864f8; }
goto P_0c0864ec;
P_0c0864ec: /* original 8801, guest PC 0x0c0864ec */
if(!s->budget--) { s->failed_pc=0x0c0864ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0864ee;
P_0c0864ee: /* original 8909, guest PC 0x0c0864ee */
if(!s->budget--) { s->failed_pc=0x0c0864eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086504; }
goto P_0c0864f0;
P_0c0864f0: /* original 8802, guest PC 0x0c0864f0 */
if(!s->budget--) { s->failed_pc=0x0c0864f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0864f2;
P_0c0864f2: /* original 8921, guest PC 0x0c0864f2 */
if(!s->budget--) { s->failed_pc=0x0c0864f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086538; }
goto P_0c0864f4;
P_0c0864f4: /* original a024, guest PC 0x0c0864f4 */
if(!s->budget--) { s->failed_pc=0x0c0864f4u; return 0; }
goto P_0c086540;
P_0c0864f6: /* original 0009, guest PC 0x0c0864f6 */
if(!s->budget--) { s->failed_pc=0x0c0864f6u; return 0; }
goto P_0c0864f8;
P_0c0864f8: /* original 65c3, guest PC 0x0c0864f8 */
if(!s->budget--) { s->failed_pc=0x0c0864f8u; return 0; }
r[5]=r[12];
goto P_0c0864fa;
P_0c0864fa: /* original 66e3, guest PC 0x0c0864fa */
if(!s->budget--) { s->failed_pc=0x0c0864fau; return 0; }
r[6]=r[14];
goto P_0c0864fc;
P_0c0864fc: /* original b058, guest PC 0x0c0864fc */
if(!s->budget--) { s->failed_pc=0x0c0864fcu; return 0; }
target=code_base|0x0c0865b0u; r[16]=code_base|0x0c086500u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086500u) { target=s->pc; goto dispatch; }
goto P_0c086500;
P_0c0864fe: /* original 64d3, guest PC 0x0c0864fe */
if(!s->budget--) { s->failed_pc=0x0c0864feu; return 0; }
r[4]=r[13];
goto P_0c086500;
P_0c086500: /* original a01e, guest PC 0x0c086500 */
if(!s->budget--) { s->failed_pc=0x0c086500u; return 0; }
goto P_0c086540;
P_0c086502: /* original 0009, guest PC 0x0c086502 */
if(!s->budget--) { s->failed_pc=0x0c086502u; return 0; }
goto P_0c086504;
P_0c086504: /* original 65c3, guest PC 0x0c086504 */
if(!s->budget--) { s->failed_pc=0x0c086504u; return 0; }
r[5]=r[12];
goto P_0c086506;
P_0c086506: /* original 66e3, guest PC 0x0c086506 */
if(!s->budget--) { s->failed_pc=0x0c086506u; return 0; }
r[6]=r[14];
goto P_0c086508;
P_0c086508: /* original b073, guest PC 0x0c086508 */
if(!s->budget--) { s->failed_pc=0x0c086508u; return 0; }
target=code_base|0x0c0865f2u; r[16]=code_base|0x0c08650cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08650cu) { target=s->pc; goto dispatch; }
goto P_0c08650c;
P_0c08650a: /* original 64d3, guest PC 0x0c08650a */
if(!s->budget--) { s->failed_pc=0x0c08650au; return 0; }
r[4]=r[13];
goto P_0c08650c;
P_0c08650c: /* original a018, guest PC 0x0c08650c */
if(!s->budget--) { s->failed_pc=0x0c08650cu; return 0; }
goto P_0c086540;
P_0c08650e: /* original 0009, guest PC 0x0c08650e */
if(!s->budget--) { s->failed_pc=0x0c08650eu; return 0; }
if(!vf3_matrix_family(0x0c086510u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086510u; return 0; } return 1;
P_0c086538: /* original 65c3, guest PC 0x0c086538 */
if(!s->budget--) { s->failed_pc=0x0c086538u; return 0; }
r[5]=r[12];
goto P_0c08653a;
P_0c08653a: /* original 66e3, guest PC 0x0c08653a */
if(!s->budget--) { s->failed_pc=0x0c08653au; return 0; }
r[6]=r[14];
goto P_0c08653c;
P_0c08653c: /* original b049, guest PC 0x0c08653c */
if(!s->budget--) { s->failed_pc=0x0c08653cu; return 0; }
target=code_base|0x0c0865d2u; r[16]=code_base|0x0c086540u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086540u) { target=s->pc; goto dispatch; }
goto P_0c086540;
P_0c08653e: /* original 64d3, guest PC 0x0c08653e */
if(!s->budget--) { s->failed_pc=0x0c08653eu; return 0; }
r[4]=r[13];
goto P_0c086540;
P_0c086540: /* original 6cd3, guest PC 0x0c086540 */
if(!s->budget--) { s->failed_pc=0x0c086540u; return 0; }
r[12]=r[13];
goto P_0c086542;
P_0c086542: /* original 5ea5, guest PC 0x0c086542 */
if(!s->budget--) { s->failed_pc=0x0c086542u; return 0; }
r[14]=read(ram,r[10]+20,4);
goto P_0c086544;
P_0c086544: /* original 7801, guest PC 0x0c086544 */
if(!s->budget--) { s->failed_pc=0x0c086544u; return 0; }
r[8]+=0x00000001u;
goto P_0c086546;
P_0c086546: /* original 7c78, guest PC 0x0c086546 */
if(!s->budget--) { s->failed_pc=0x0c086546u; return 0; }
r[12]+=0x00000078u;
goto P_0c086548;
P_0c086548: /* original 628f, guest PC 0x0c086548 */
if(!s->budget--) { s->failed_pc=0x0c086548u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[8];
goto P_0c08654a;
P_0c08654a: /* original e402, guest PC 0x0c08654a */
if(!s->budget--) { s->failed_pc=0x0c08654au; return 0; }
r[4]=0x00000002u;
goto P_0c08654c;
P_0c08654c: /* original 3243, guest PC 0x0c08654c */
if(!s->budget--) { s->failed_pc=0x0c08654cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c08654e;
P_0c08654e: /* original 8bb2, guest PC 0x0c08654e */
if(!s->budget--) { s->failed_pc=0x0c08654eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0864b6; }
goto P_0c086550;
P_0c086550: /* original 4f26, guest PC 0x0c086550 */
if(!s->budget--) { s->failed_pc=0x0c086550u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086552;
P_0c086552: /* original 68f6, guest PC 0x0c086552 */
if(!s->budget--) { s->failed_pc=0x0c086552u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c086554;
P_0c086554: /* original 69f6, guest PC 0x0c086554 */
if(!s->budget--) { s->failed_pc=0x0c086554u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c086556;
P_0c086556: /* original 6af6, guest PC 0x0c086556 */
if(!s->budget--) { s->failed_pc=0x0c086556u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c086558;
P_0c086558: /* original 6bf6, guest PC 0x0c086558 */
if(!s->budget--) { s->failed_pc=0x0c086558u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08655a;
P_0c08655a: /* original 6cf6, guest PC 0x0c08655a */
if(!s->budget--) { s->failed_pc=0x0c08655au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08655c;
P_0c08655c: /* original 6df6, guest PC 0x0c08655c */
if(!s->budget--) { s->failed_pc=0x0c08655cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08655e;
P_0c08655e: /* original 000b, guest PC 0x0c08655e */
if(!s->budget--) { s->failed_pc=0x0c08655eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086560: /* original 6ef6, guest PC 0x0c086560 */
if(!s->budget--) { s->failed_pc=0x0c086560u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086562;
P_0c086562: /* original 2fe6, guest PC 0x0c086562 */
if(!s->budget--) { s->failed_pc=0x0c086562u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086564;
P_0c086564: /* original 6e63, guest PC 0x0c086564 */
if(!s->budget--) { s->failed_pc=0x0c086564u; return 0; }
r[14]=r[6];
goto P_0c086566;
P_0c086566: /* original e3fa, guest PC 0x0c086566 */
if(!s->budget--) { s->failed_pc=0x0c086566u; return 0; }
r[3]=0xfffffffau;
goto P_0c086568;
P_0c086568: /* original 7ffc, guest PC 0x0c086568 */
if(!s->budget--) { s->failed_pc=0x0c086568u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08656a;
P_0c08656a: /* original 2f42, guest PC 0x0c08656a */
if(!s->budget--) { s->failed_pc=0x0c08656au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08656c;
P_0c08656c: /* original e401, guest PC 0x0c08656c */
if(!s->budget--) { s->failed_pc=0x0c08656cu; return 0; }
r[4]=0x00000001u;
goto P_0c08656e;
P_0c08656e: /* original 9088, guest PC 0x0c08656e */
if(!s->budget--) { s->failed_pc=0x0c08656eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086682u,2);
goto P_0c086570;
P_0c086570: /* original 02ee, guest PC 0x0c086570 */
if(!s->budget--) { s->failed_pc=0x0c086570u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c086572;
P_0c086572: /* original 2239, guest PC 0x0c086572 */
if(!s->budget--) { s->failed_pc=0x0c086572u; return 0; }
r[2]&=r[3];
goto P_0c086574;
P_0c086574: /* original 0e26, guest PC 0x0c086574 */
if(!s->budget--) { s->failed_pc=0x0c086574u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c086576;
P_0c086576: /* original e202, guest PC 0x0c086576 */
if(!s->budget--) { s->failed_pc=0x0c086576u; return 0; }
r[2]=0x00000002u;
goto P_0c086578;
P_0c086578: /* original 01ee, guest PC 0x0c086578 */
if(!s->budget--) { s->failed_pc=0x0c086578u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c08657a;
P_0c08657a: /* original 212b, guest PC 0x0c08657a */
if(!s->budget--) { s->failed_pc=0x0c08657au; return 0; }
r[1]|=r[2];
goto P_0c08657c;
P_0c08657c: /* original 0e16, guest PC 0x0c08657c */
if(!s->budget--) { s->failed_pc=0x0c08657cu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c08657e;
P_0c08657e: /* original 9081, guest PC 0x0c08657e */
if(!s->budget--) { s->failed_pc=0x0c08657eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086684u,2);
goto P_0c086580;
P_0c086580: /* original f3e6, guest PC 0x0c086580 */
if(!s->budget--) { s->failed_pc=0x0c086580u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086582;
P_0c086582: /* original e004, guest PC 0x0c086582 */
if(!s->budget--) { s->failed_pc=0x0c086582u; return 0; }
r[0]=0x00000004u;
goto P_0c086584;
P_0c086584: /* original f537, guest PC 0x0c086584 */
if(!s->budget--) { s->failed_pc=0x0c086584u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c086586;
P_0c086586: /* original 907e, guest PC 0x0c086586 */
if(!s->budget--) { s->failed_pc=0x0c086586u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086686u,2);
goto P_0c086588;
P_0c086588: /* original f3e6, guest PC 0x0c086588 */
if(!s->budget--) { s->failed_pc=0x0c086588u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08658a;
P_0c08658a: /* original e008, guest PC 0x0c08658a */
if(!s->budget--) { s->failed_pc=0x0c08658au; return 0; }
r[0]=0x00000008u;
goto P_0c08658c;
P_0c08658c: /* original f537, guest PC 0x0c08658c */
if(!s->budget--) { s->failed_pc=0x0c08658cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c08658e;
P_0c08658e: /* original 907b, guest PC 0x0c08658e */
if(!s->budget--) { s->failed_pc=0x0c08658eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086688u,2);
goto P_0c086590;
P_0c086590: /* original f3e6, guest PC 0x0c086590 */
if(!s->budget--) { s->failed_pc=0x0c086590u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086592;
P_0c086592: /* original e00c, guest PC 0x0c086592 */
if(!s->budget--) { s->failed_pc=0x0c086592u; return 0; }
r[0]=0x0000000cu;
goto P_0c086594;
P_0c086594: /* original f537, guest PC 0x0c086594 */
if(!s->budget--) { s->failed_pc=0x0c086594u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c086596;
P_0c086596: /* original e024, guest PC 0x0c086596 */
if(!s->budget--) { s->failed_pc=0x0c086596u; return 0; }
r[0]=0x00000024u;
goto P_0c086598;
P_0c086598: /* original 0545, guest PC 0x0c086598 */
if(!s->budget--) { s->failed_pc=0x0c086598u; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c08659a;
P_0c08659a: /* original e026, guest PC 0x0c08659a */
if(!s->budget--) { s->failed_pc=0x0c08659au; return 0; }
r[0]=0x00000026u;
goto P_0c08659c;
P_0c08659c: /* original 0545, guest PC 0x0c08659c */
if(!s->budget--) { s->failed_pc=0x0c08659cu; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c08659e;
P_0c08659e: /* original e028, guest PC 0x0c08659e */
if(!s->budget--) { s->failed_pc=0x0c08659eu; return 0; }
r[0]=0x00000028u;
goto P_0c0865a0;
P_0c0865a0: /* original 0545, guest PC 0x0c0865a0 */
if(!s->budget--) { s->failed_pc=0x0c0865a0u; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c0865a2;
P_0c0865a2: /* original e300, guest PC 0x0c0865a2 */
if(!s->budget--) { s->failed_pc=0x0c0865a2u; return 0; }
r[3]=0x00000000u;
goto P_0c0865a4;
P_0c0865a4: /* original 66e3, guest PC 0x0c0865a4 */
if(!s->budget--) { s->failed_pc=0x0c0865a4u; return 0; }
r[6]=r[14];
goto P_0c0865a6;
P_0c0865a6: /* original 153e, guest PC 0x0c0865a6 */
if(!s->budget--) { s->failed_pc=0x0c0865a6u; return 0; }
write(ram,r[5]+56,r[3],4);
goto P_0c0865a8;
P_0c0865a8: /* original 64f2, guest PC 0x0c0865a8 */
if(!s->budget--) { s->failed_pc=0x0c0865a8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0865aa;
P_0c0865aa: /* original 7f04, guest PC 0x0c0865aa */
if(!s->budget--) { s->failed_pc=0x0c0865aau; return 0; }
r[15]+=0x00000004u;
goto P_0c0865ac;
P_0c0865ac: /* original a12d, guest PC 0x0c0865ac */
if(!s->budget--) { s->failed_pc=0x0c0865acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08680au,s,ram);
P_0c0865ae: /* original 6ef6, guest PC 0x0c0865ae */
if(!s->budget--) { s->failed_pc=0x0c0865aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0865b0;
P_0c0865b0: /* original 9068, guest PC 0x0c0865b0 */
if(!s->budget--) { s->failed_pc=0x0c0865b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086684u,2);
goto P_0c0865b2;
P_0c0865b2: /* original 6463, guest PC 0x0c0865b2 */
if(!s->budget--) { s->failed_pc=0x0c0865b2u; return 0; }
r[4]=r[6];
goto P_0c0865b4;
P_0c0865b4: /* original f346, guest PC 0x0c0865b4 */
if(!s->budget--) { s->failed_pc=0x0c0865b4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0865b6;
P_0c0865b6: /* original e004, guest PC 0x0c0865b6 */
if(!s->budget--) { s->failed_pc=0x0c0865b6u; return 0; }
r[0]=0x00000004u;
goto P_0c0865b8;
P_0c0865b8: /* original f537, guest PC 0x0c0865b8 */
if(!s->budget--) { s->failed_pc=0x0c0865b8u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0865ba;
P_0c0865ba: /* original c734, guest PC 0x0c0865ba */
if(!s->budget--) { s->failed_pc=0x0c0865bau; return 0; }
r[0]=code_base|0x0008668cu;
goto P_0c0865bc;
P_0c0865bc: /* original f308, guest PC 0x0c0865bc */
if(!s->budget--) { s->failed_pc=0x0c0865bcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0865be;
P_0c0865be: /* original 9062, guest PC 0x0c0865be */
if(!s->budget--) { s->failed_pc=0x0c0865beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086686u,2);
goto P_0c0865c0;
P_0c0865c0: /* original f246, guest PC 0x0c0865c0 */
if(!s->budget--) { s->failed_pc=0x0c0865c0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0865c2;
P_0c0865c2: /* original e008, guest PC 0x0c0865c2 */
if(!s->budget--) { s->failed_pc=0x0c0865c2u; return 0; }
r[0]=0x00000008u;
goto P_0c0865c4;
P_0c0865c4: /* original f230, guest PC 0x0c0865c4 */
if(!s->budget--) { s->failed_pc=0x0c0865c4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0865c6;
P_0c0865c6: /* original f527, guest PC 0x0c0865c6 */
if(!s->budget--) { s->failed_pc=0x0c0865c6u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0865c8;
P_0c0865c8: /* original 905e, guest PC 0x0c0865c8 */
if(!s->budget--) { s->failed_pc=0x0c0865c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086688u,2);
goto P_0c0865ca;
P_0c0865ca: /* original f246, guest PC 0x0c0865ca */
if(!s->budget--) { s->failed_pc=0x0c0865cau; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0865cc;
P_0c0865cc: /* original e00c, guest PC 0x0c0865cc */
if(!s->budget--) { s->failed_pc=0x0c0865ccu; return 0; }
r[0]=0x0000000cu;
goto P_0c0865ce;
P_0c0865ce: /* original 000b, guest PC 0x0c0865ce */
if(!s->budget--) { s->failed_pc=0x0c0865ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[5]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0865d0: /* original f527, guest PC 0x0c0865d0 */
if(!s->budget--) { s->failed_pc=0x0c0865d0u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
return vf3_matrix_family(0x0c0865d2u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
