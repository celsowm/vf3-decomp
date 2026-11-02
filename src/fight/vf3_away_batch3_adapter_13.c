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
int vf3_away_batch3_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04379cu: goto P_0c04379c;
case 0x0c04379eu: goto P_0c04379e;
case 0x0c0437a0u: goto P_0c0437a0;
case 0x0c0437a2u: goto P_0c0437a2;
case 0x0c0437a4u: goto P_0c0437a4;
case 0x0c0437a6u: goto P_0c0437a6;
case 0x0c0437a8u: goto P_0c0437a8;
case 0x0c0437aau: goto P_0c0437aa;
case 0x0c0437acu: goto P_0c0437ac;
case 0x0c0437aeu: goto P_0c0437ae;
case 0x0c0437b0u: goto P_0c0437b0;
case 0x0c0437b2u: goto P_0c0437b2;
case 0x0c0437b4u: goto P_0c0437b4;
case 0x0c0437b6u: goto P_0c0437b6;
case 0x0c0437b8u: goto P_0c0437b8;
case 0x0c0437bau: goto P_0c0437ba;
case 0x0c0437bcu: goto P_0c0437bc;
case 0x0c0437beu: goto P_0c0437be;
case 0x0c0437c0u: goto P_0c0437c0;
case 0x0c0437c2u: goto P_0c0437c2;
case 0x0c0437c4u: goto P_0c0437c4;
case 0x0c0437c6u: goto P_0c0437c6;
case 0x0c0437c8u: goto P_0c0437c8;
case 0x0c0437cau: goto P_0c0437ca;
case 0x0c0437ccu: goto P_0c0437cc;
case 0x0c0437ceu: goto P_0c0437ce;
case 0x0c0437d0u: goto P_0c0437d0;
case 0x0c0437d2u: goto P_0c0437d2;
case 0x0c0437d4u: goto P_0c0437d4;
case 0x0c0437d6u: goto P_0c0437d6;
case 0x0c0437d8u: goto P_0c0437d8;
case 0x0c0437dau: goto P_0c0437da;
case 0x0c0437dcu: goto P_0c0437dc;
case 0x0c0437deu: goto P_0c0437de;
case 0x0c0437e0u: goto P_0c0437e0;
case 0x0c0437e2u: goto P_0c0437e2;
case 0x0c0437e4u: goto P_0c0437e4;
case 0x0c0437e6u: goto P_0c0437e6;
case 0x0c0437e8u: goto P_0c0437e8;
case 0x0c0437eau: goto P_0c0437ea;
case 0x0c0437ecu: goto P_0c0437ec;
case 0x0c0437eeu: goto P_0c0437ee;
case 0x0c0437f0u: goto P_0c0437f0;
case 0x0c0437f2u: goto P_0c0437f2;
case 0x0c0437f4u: goto P_0c0437f4;
case 0x0c0437f8u: goto P_0c0437f8;
case 0x0c0437fau: goto P_0c0437fa;
case 0x0c0437fcu: goto P_0c0437fc;
case 0x0c0437feu: goto P_0c0437fe;
case 0x0c043800u: goto P_0c043800;
case 0x0c043802u: goto P_0c043802;
case 0x0c043804u: goto P_0c043804;
case 0x0c043806u: goto P_0c043806;
case 0x0c043808u: goto P_0c043808;
case 0x0c04380au: goto P_0c04380a;
case 0x0c04380cu: goto P_0c04380c;
case 0x0c04380eu: goto P_0c04380e;
case 0x0c043810u: goto P_0c043810;
case 0x0c043812u: goto P_0c043812;
case 0x0c043814u: goto P_0c043814;
case 0x0c043816u: goto P_0c043816;
case 0x0c043818u: goto P_0c043818;
case 0x0c04381au: goto P_0c04381a;
case 0x0c04381cu: goto P_0c04381c;
case 0x0c04381eu: goto P_0c04381e;
case 0x0c043820u: goto P_0c043820;
case 0x0c043822u: goto P_0c043822;
case 0x0c043824u: goto P_0c043824;
case 0x0c043826u: goto P_0c043826;
case 0x0c043828u: goto P_0c043828;
case 0x0c04382au: goto P_0c04382a;
case 0x0c04382cu: goto P_0c04382c;
case 0x0c04382eu: goto P_0c04382e;
case 0x0c043830u: goto P_0c043830;
case 0x0c043832u: goto P_0c043832;
case 0x0c043834u: goto P_0c043834;
case 0x0c043836u: goto P_0c043836;
case 0x0c043838u: goto P_0c043838;
case 0x0c04383au: goto P_0c04383a;
case 0x0c04383cu: goto P_0c04383c;
case 0x0c04383eu: goto P_0c04383e;
case 0x0c043840u: goto P_0c043840;
case 0x0c043842u: goto P_0c043842;
case 0x0c043844u: goto P_0c043844;
case 0x0c043846u: goto P_0c043846;
case 0x0c043848u: goto P_0c043848;
case 0x0c04384au: goto P_0c04384a;
case 0x0c04384cu: goto P_0c04384c;
case 0x0c04384eu: goto P_0c04384e;
case 0x0c043850u: goto P_0c043850;
case 0x0c043852u: goto P_0c043852;
case 0x0c043854u: goto P_0c043854;
case 0x0c043856u: goto P_0c043856;
case 0x0c043858u: goto P_0c043858;
case 0x0c04385au: goto P_0c04385a;
case 0x0c04385cu: goto P_0c04385c;
case 0x0c04385eu: goto P_0c04385e;
case 0x0c043860u: goto P_0c043860;
case 0x0c043862u: goto P_0c043862;
case 0x0c043864u: goto P_0c043864;
case 0x0c043866u: goto P_0c043866;
case 0x0c043868u: goto P_0c043868;
case 0x0c04386au: goto P_0c04386a;
case 0x0c04386cu: goto P_0c04386c;
case 0x0c04386eu: goto P_0c04386e;
case 0x0c043870u: goto P_0c043870;
case 0x0c043872u: goto P_0c043872;
case 0x0c043874u: goto P_0c043874;
case 0x0c043876u: goto P_0c043876;
case 0x0c043878u: goto P_0c043878;
case 0x0c04387au: goto P_0c04387a;
case 0x0c04387cu: goto P_0c04387c;
case 0x0c04387eu: goto P_0c04387e;
case 0x0c043880u: goto P_0c043880;
case 0x0c043882u: goto P_0c043882;
case 0x0c043884u: goto P_0c043884;
case 0x0c043886u: goto P_0c043886;
case 0x0c043888u: goto P_0c043888;
case 0x0c04388au: goto P_0c04388a;
case 0x0c04388cu: goto P_0c04388c;
case 0x0c04388eu: goto P_0c04388e;
case 0x0c043890u: goto P_0c043890;
case 0x0c043892u: goto P_0c043892;
case 0x0c043894u: goto P_0c043894;
case 0x0c043896u: goto P_0c043896;
case 0x0c043898u: goto P_0c043898;
case 0x0c04389au: goto P_0c04389a;
case 0x0c04389cu: goto P_0c04389c;
case 0x0c04389eu: goto P_0c04389e;
case 0x0c0438a0u: goto P_0c0438a0;
case 0x0c0438a2u: goto P_0c0438a2;
case 0x0c0438a4u: goto P_0c0438a4;
case 0x0c0438a6u: goto P_0c0438a6;
case 0x0c0438a8u: goto P_0c0438a8;
case 0x0c0438aau: goto P_0c0438aa;
case 0x0c0438acu: goto P_0c0438ac;
case 0x0c0438aeu: goto P_0c0438ae;
case 0x0c0438b0u: goto P_0c0438b0;
case 0x0c0438b2u: goto P_0c0438b2;
case 0x0c0438b4u: goto P_0c0438b4;
case 0x0c0438b6u: goto P_0c0438b6;
case 0x0c0438b8u: goto P_0c0438b8;
case 0x0c0438bau: goto P_0c0438ba;
case 0x0c0438bcu: goto P_0c0438bc;
case 0x0c0438beu: goto P_0c0438be;
case 0x0c0438c0u: goto P_0c0438c0;
case 0x0c0438c2u: goto P_0c0438c2;
case 0x0c0438c4u: goto P_0c0438c4;
case 0x0c0438c6u: goto P_0c0438c6;
case 0x0c0438c8u: goto P_0c0438c8;
case 0x0c0438cau: goto P_0c0438ca;
case 0x0c0438ccu: goto P_0c0438cc;
case 0x0c0438ceu: goto P_0c0438ce;
case 0x0c0438d0u: goto P_0c0438d0;
case 0x0c0438d2u: goto P_0c0438d2;
case 0x0c0438d4u: goto P_0c0438d4;
case 0x0c0438d6u: goto P_0c0438d6;
case 0x0c0438d8u: goto P_0c0438d8;
case 0x0c0438dau: goto P_0c0438da;
case 0x0c0438dcu: goto P_0c0438dc;
case 0x0c0438deu: goto P_0c0438de;
case 0x0c0438e0u: goto P_0c0438e0;
case 0x0c0438e2u: goto P_0c0438e2;
case 0x0c0438e4u: goto P_0c0438e4;
case 0x0c0438e6u: goto P_0c0438e6;
case 0x0c0438e8u: goto P_0c0438e8;
case 0x0c0438eau: goto P_0c0438ea;
case 0x0c0438ecu: goto P_0c0438ec;
case 0x0c0438eeu: goto P_0c0438ee;
case 0x0c0438f0u: goto P_0c0438f0;
case 0x0c0438f2u: goto P_0c0438f2;
case 0x0c0438f4u: goto P_0c0438f4;
case 0x0c0438f6u: goto P_0c0438f6;
case 0x0c0438f8u: goto P_0c0438f8;
case 0x0c0438fau: goto P_0c0438fa;
case 0x0c0438fcu: goto P_0c0438fc;
case 0x0c0438feu: goto P_0c0438fe;
case 0x0c043900u: goto P_0c043900;
case 0x0c043902u: goto P_0c043902;
case 0x0c043904u: goto P_0c043904;
case 0x0c043906u: goto P_0c043906;
case 0x0c043908u: goto P_0c043908;
case 0x0c04390au: goto P_0c04390a;
case 0x0c04390cu: goto P_0c04390c;
case 0x0c04390eu: goto P_0c04390e;
case 0x0c043910u: goto P_0c043910;
case 0x0c043912u: goto P_0c043912;
case 0x0c043914u: goto P_0c043914;
case 0x0c043916u: goto P_0c043916;
case 0x0c043918u: goto P_0c043918;
case 0x0c04391au: goto P_0c04391a;
case 0x0c04391cu: goto P_0c04391c;
case 0x0c043964u: goto P_0c043964;
case 0x0c043966u: goto P_0c043966;
case 0x0c043968u: goto P_0c043968;
case 0x0c04396au: goto P_0c04396a;
case 0x0c04396cu: goto P_0c04396c;
case 0x0c04396eu: goto P_0c04396e;
case 0x0c043970u: goto P_0c043970;
case 0x0c043972u: goto P_0c043972;
case 0x0c043974u: goto P_0c043974;
case 0x0c043976u: goto P_0c043976;
case 0x0c043978u: goto P_0c043978;
case 0x0c04397au: goto P_0c04397a;
case 0x0c04397cu: goto P_0c04397c;
case 0x0c04397eu: goto P_0c04397e;
case 0x0c043980u: goto P_0c043980;
case 0x0c043982u: goto P_0c043982;
case 0x0c043984u: goto P_0c043984;
case 0x0c043986u: goto P_0c043986;
case 0x0c043988u: goto P_0c043988;
case 0x0c04398au: goto P_0c04398a;
case 0x0c04398cu: goto P_0c04398c;
case 0x0c04398eu: goto P_0c04398e;
case 0x0c043990u: goto P_0c043990;
case 0x0c043992u: goto P_0c043992;
case 0x0c043994u: goto P_0c043994;
case 0x0c043996u: goto P_0c043996;
case 0x0c043998u: goto P_0c043998;
case 0x0c04399au: goto P_0c04399a;
case 0x0c04399cu: goto P_0c04399c;
case 0x0c04399eu: goto P_0c04399e;
case 0x0c0439a0u: goto P_0c0439a0;
case 0x0c0439a2u: goto P_0c0439a2;
case 0x0c0439a4u: goto P_0c0439a4;
case 0x0c0439a6u: goto P_0c0439a6;
case 0x0c0439a8u: goto P_0c0439a8;
case 0x0c0439aau: goto P_0c0439aa;
case 0x0c0439acu: goto P_0c0439ac;
case 0x0c0439aeu: goto P_0c0439ae;
case 0x0c0439b0u: goto P_0c0439b0;
case 0x0c0439b2u: goto P_0c0439b2;
case 0x0c0439b4u: goto P_0c0439b4;
case 0x0c0439b6u: goto P_0c0439b6;
case 0x0c0439b8u: goto P_0c0439b8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04379c: /* original 2fe6, guest PC 0x0c04379c */
if(!s->budget--) { s->failed_pc=0x0c04379cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04379e;
P_0c04379e: /* original 6e53, guest PC 0x0c04379e */
if(!s->budget--) { s->failed_pc=0x0c04379eu; return 0; }
r[14]=r[5];
goto P_0c0437a0;
P_0c0437a0: /* original 2fd6, guest PC 0x0c0437a0 */
if(!s->budget--) { s->failed_pc=0x0c0437a0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0437a2;
P_0c0437a2: /* original 7e10, guest PC 0x0c0437a2 */
if(!s->budget--) { s->failed_pc=0x0c0437a2u; return 0; }
r[14]+=0x00000010u;
goto P_0c0437a4;
P_0c0437a4: /* original 2fc6, guest PC 0x0c0437a4 */
if(!s->budget--) { s->failed_pc=0x0c0437a4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0437a6;
P_0c0437a6: /* original 2fb6, guest PC 0x0c0437a6 */
if(!s->budget--) { s->failed_pc=0x0c0437a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0437a8;
P_0c0437a8: /* original 6b43, guest PC 0x0c0437a8 */
if(!s->budget--) { s->failed_pc=0x0c0437a8u; return 0; }
r[11]=r[4];
goto P_0c0437aa;
P_0c0437aa: /* original 2fa6, guest PC 0x0c0437aa */
if(!s->budget--) { s->failed_pc=0x0c0437aau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0437ac;
P_0c0437ac: /* original 2f96, guest PC 0x0c0437ac */
if(!s->budget--) { s->failed_pc=0x0c0437acu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0437ae;
P_0c0437ae: /* original 4f22, guest PC 0x0c0437ae */
if(!s->budget--) { s->failed_pc=0x0c0437aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0437b0;
P_0c0437b0: /* original 7ffc, guest PC 0x0c0437b0 */
if(!s->budget--) { s->failed_pc=0x0c0437b0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0437b2;
P_0c0437b2: /* original 2f62, guest PC 0x0c0437b2 */
if(!s->budget--) { s->failed_pc=0x0c0437b2u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0437b4;
P_0c0437b4: /* original 6a52, guest PC 0x0c0437b4 */
if(!s->budget--) { s->failed_pc=0x0c0437b4u; return 0; }
tmp=read(ram,r[5],4);
r[10]=tmp;
goto P_0c0437b6;
P_0c0437b6: /* original bf28, guest PC 0x0c0437b6 */
if(!s->budget--) { s->failed_pc=0x0c0437b6u; return 0; }
target=code_base|0x0c04360au; r[16]=code_base|0x0c0437bau;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0437bau) { target=s->pc; goto dispatch; }
goto P_0c0437ba;
P_0c0437b8: /* original 64b3, guest PC 0x0c0437b8 */
if(!s->budget--) { s->failed_pc=0x0c0437b8u; return 0; }
r[4]=r[11];
goto P_0c0437ba;
P_0c0437ba: /* original 4a15, guest PC 0x0c0437ba */
if(!s->budget--) { s->failed_pc=0x0c0437bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c0437bc;
P_0c0437bc: /* original 6903, guest PC 0x0c0437bc */
if(!s->budget--) { s->failed_pc=0x0c0437bcu; return 0; }
r[9]=r[0];
goto P_0c0437be;
P_0c0437be: /* original 8f1f, guest PC 0x0c0437be */
if(!s->budget--) { s->failed_pc=0x0c0437beu; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(!cond) { goto P_0c043800; }
goto P_0c0437c2;
P_0c0437c0: /* original ed00, guest PC 0x0c0437c0 */
if(!s->budget--) { s->failed_pc=0x0c0437c0u; return 0; }
r[13]=0x00000000u;
goto P_0c0437c2;
P_0c0437c2: /* original 84e9, guest PC 0x0c0437c2 */
if(!s->budget--) { s->failed_pc=0x0c0437c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+9,1);
goto P_0c0437c4;
P_0c0437c4: /* original 639c, guest PC 0x0c0437c4 */
if(!s->budget--) { s->failed_pc=0x0c0437c4u; return 0; }
r[3]=r[9]&255u;
goto P_0c0437c6;
P_0c0437c6: /* original 600c, guest PC 0x0c0437c6 */
if(!s->budget--) { s->failed_pc=0x0c0437c6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0437c8;
P_0c0437c8: /* original 3030, guest PC 0x0c0437c8 */
if(!s->budget--) { s->failed_pc=0x0c0437c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c0437ca;
P_0c0437ca: /* original 8b15, guest PC 0x0c0437ca */
if(!s->budget--) { s->failed_pc=0x0c0437cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0437f8; }
goto P_0c0437cc;
P_0c0437cc: /* original 60f2, guest PC 0x0c0437cc */
if(!s->budget--) { s->failed_pc=0x0c0437ccu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0437ce;
P_0c0437ce: /* original 6cd3, guest PC 0x0c0437ce */
if(!s->budget--) { s->failed_pc=0x0c0437ceu; return 0; }
r[12]=r[13];
goto P_0c0437d0;
P_0c0437d0: /* original 8801, guest PC 0x0c0437d0 */
if(!s->budget--) { s->failed_pc=0x0c0437d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0437d2;
P_0c0437d2: /* original 8f08, guest PC 0x0c0437d2 */
if(!s->budget--) { s->failed_pc=0x0c0437d2u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c0437e6; }
goto P_0c0437d6;
P_0c0437d4: /* original 7c01, guest PC 0x0c0437d4 */
if(!s->budget--) { s->failed_pc=0x0c0437d4u; return 0; }
r[12]+=0x00000001u;
goto P_0c0437d6;
P_0c0437d6: /* original 65e3, guest PC 0x0c0437d6 */
if(!s->budget--) { s->failed_pc=0x0c0437d6u; return 0; }
r[5]=r[14];
goto P_0c0437d8;
P_0c0437d8: /* original 750a, guest PC 0x0c0437d8 */
if(!s->budget--) { s->failed_pc=0x0c0437d8u; return 0; }
r[5]+=0x0000000au;
goto P_0c0437da;
P_0c0437da: /* original bec8, guest PC 0x0c0437da */
if(!s->budget--) { s->failed_pc=0x0c0437dau; return 0; }
target=code_base|0x0c04356eu; r[16]=code_base|0x0c0437deu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0437deu) { target=s->pc; goto dispatch; }
goto P_0c0437de;
P_0c0437dc: /* original 64b3, guest PC 0x0c0437dc */
if(!s->budget--) { s->failed_pc=0x0c0437dcu; return 0; }
r[4]=r[11];
goto P_0c0437de;
P_0c0437de: /* original 8801, guest PC 0x0c0437de */
if(!s->budget--) { s->failed_pc=0x0c0437deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0437e0;
P_0c0437e0: /* original 8b0a, guest PC 0x0c0437e0 */
if(!s->budget--) { s->failed_pc=0x0c0437e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0437f8; }
goto P_0c0437e2;
P_0c0437e2: /* original a006, guest PC 0x0c0437e2 */
if(!s->budget--) { s->failed_pc=0x0c0437e2u; return 0; }
goto P_0c0437f2;
P_0c0437e4: /* original 0009, guest PC 0x0c0437e4 */
if(!s->budget--) { s->failed_pc=0x0c0437e4u; return 0; }
goto P_0c0437e6;
P_0c0437e6: /* original 65e3, guest PC 0x0c0437e6 */
if(!s->budget--) { s->failed_pc=0x0c0437e6u; return 0; }
r[5]=r[14];
goto P_0c0437e8;
P_0c0437e8: /* original 750a, guest PC 0x0c0437e8 */
if(!s->budget--) { s->failed_pc=0x0c0437e8u; return 0; }
r[5]+=0x0000000au;
goto P_0c0437ea;
P_0c0437ea: /* original bed2, guest PC 0x0c0437ea */
if(!s->budget--) { s->failed_pc=0x0c0437eau; return 0; }
target=code_base|0x0c043592u; r[16]=code_base|0x0c0437eeu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0437eeu) { target=s->pc; goto dispatch; }
goto P_0c0437ee;
P_0c0437ec: /* original 64b3, guest PC 0x0c0437ec */
if(!s->budget--) { s->failed_pc=0x0c0437ecu; return 0; }
r[4]=r[11];
goto P_0c0437ee;
P_0c0437ee: /* original 8801, guest PC 0x0c0437ee */
if(!s->budget--) { s->failed_pc=0x0c0437eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0437f0;
P_0c0437f0: /* original 8b02, guest PC 0x0c0437f0 */
if(!s->budget--) { s->failed_pc=0x0c0437f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0437f8; }
goto P_0c0437f2;
P_0c0437f2: /* original a006, guest PC 0x0c0437f2 */
if(!s->budget--) { s->failed_pc=0x0c0437f2u; return 0; }
r[0]=r[12];
goto P_0c043802;
P_0c0437f4: /* original 60c3, guest PC 0x0c0437f4 */
if(!s->budget--) { s->failed_pc=0x0c0437f4u; return 0; }
r[0]=r[12];
if(!vf3_matrix_family(0x0c0437f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0437f6u; return 0; } return 1;
P_0c0437f8: /* original 7d01, guest PC 0x0c0437f8 */
if(!s->budget--) { s->failed_pc=0x0c0437f8u; return 0; }
r[13]+=0x00000001u;
goto P_0c0437fa;
P_0c0437fa: /* original 3da3, guest PC 0x0c0437fa */
if(!s->budget--) { s->failed_pc=0x0c0437fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[10])!=0);
goto P_0c0437fc;
P_0c0437fc: /* original 8fe1, guest PC 0x0c0437fc */
if(!s->budget--) { s->failed_pc=0x0c0437fcu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000002cu;
if(!cond) { goto P_0c0437c2; }
goto P_0c043800;
P_0c0437fe: /* original 7e2c, guest PC 0x0c0437fe */
if(!s->budget--) { s->failed_pc=0x0c0437feu; return 0; }
r[14]+=0x0000002cu;
goto P_0c043800;
P_0c043800: /* original e000, guest PC 0x0c043800 */
if(!s->budget--) { s->failed_pc=0x0c043800u; return 0; }
r[0]=0x00000000u;
goto P_0c043802;
P_0c043802: /* original 7f04, guest PC 0x0c043802 */
if(!s->budget--) { s->failed_pc=0x0c043802u; return 0; }
r[15]+=0x00000004u;
goto P_0c043804;
P_0c043804: /* original 4f26, guest PC 0x0c043804 */
if(!s->budget--) { s->failed_pc=0x0c043804u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043806;
P_0c043806: /* original 69f6, guest PC 0x0c043806 */
if(!s->budget--) { s->failed_pc=0x0c043806u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c043808;
P_0c043808: /* original 6af6, guest PC 0x0c043808 */
if(!s->budget--) { s->failed_pc=0x0c043808u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04380a;
P_0c04380a: /* original 6bf6, guest PC 0x0c04380a */
if(!s->budget--) { s->failed_pc=0x0c04380au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04380c;
P_0c04380c: /* original 6cf6, guest PC 0x0c04380c */
if(!s->budget--) { s->failed_pc=0x0c04380cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04380e;
P_0c04380e: /* original 6df6, guest PC 0x0c04380e */
if(!s->budget--) { s->failed_pc=0x0c04380eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043810;
P_0c043810: /* original 000b, guest PC 0x0c043810 */
if(!s->budget--) { s->failed_pc=0x0c043810u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043812: /* original 6ef6, guest PC 0x0c043812 */
if(!s->budget--) { s->failed_pc=0x0c043812u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c043814;
P_0c043814: /* original 2fe6, guest PC 0x0c043814 */
if(!s->budget--) { s->failed_pc=0x0c043814u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043816;
P_0c043816: /* original 2fd6, guest PC 0x0c043816 */
if(!s->budget--) { s->failed_pc=0x0c043816u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043818;
P_0c043818: /* original 2fc6, guest PC 0x0c043818 */
if(!s->budget--) { s->failed_pc=0x0c043818u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04381a;
P_0c04381a: /* original 6c73, guest PC 0x0c04381a */
if(!s->budget--) { s->failed_pc=0x0c04381au; return 0; }
r[12]=r[7];
goto P_0c04381c;
P_0c04381c: /* original 2fb6, guest PC 0x0c04381c */
if(!s->budget--) { s->failed_pc=0x0c04381cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04381e;
P_0c04381e: /* original 7c01, guest PC 0x0c04381e */
if(!s->budget--) { s->failed_pc=0x0c04381eu; return 0; }
r[12]+=0x00000001u;
goto P_0c043820;
P_0c043820: /* original 2fa6, guest PC 0x0c043820 */
if(!s->budget--) { s->failed_pc=0x0c043820u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043822;
P_0c043822: /* original 2f96, guest PC 0x0c043822 */
if(!s->budget--) { s->failed_pc=0x0c043822u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043824;
P_0c043824: /* original 6943, guest PC 0x0c043824 */
if(!s->budget--) { s->failed_pc=0x0c043824u; return 0; }
r[9]=r[4];
goto P_0c043826;
P_0c043826: /* original 2f86, guest PC 0x0c043826 */
if(!s->budget--) { s->failed_pc=0x0c043826u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043828;
P_0c043828: /* original e401, guest PC 0x0c043828 */
if(!s->budget--) { s->failed_pc=0x0c043828u; return 0; }
r[4]=0x00000001u;
goto P_0c04382a;
P_0c04382a: /* original 4f22, guest PC 0x0c04382a */
if(!s->budget--) { s->failed_pc=0x0c04382au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04382c;
P_0c04382c: /* original 6b43, guest PC 0x0c04382c */
if(!s->budget--) { s->failed_pc=0x0c04382cu; return 0; }
r[11]=r[4];
goto P_0c04382e;
P_0c04382e: /* original 6e93, guest PC 0x0c04382e */
if(!s->budget--) { s->failed_pc=0x0c04382eu; return 0; }
r[14]=r[9];
goto P_0c043830;
P_0c043830: /* original 7fe8, guest PC 0x0c043830 */
if(!s->budget--) { s->failed_pc=0x0c043830u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c043832;
P_0c043832: /* original 1f52, guest PC 0x0c043832 */
if(!s->budget--) { s->failed_pc=0x0c043832u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c043834;
P_0c043834: /* original 1f64, guest PC 0x0c043834 */
if(!s->budget--) { s->failed_pc=0x0c043834u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c043836;
P_0c043836: /* original 1f45, guest PC 0x0c043836 */
if(!s->budget--) { s->failed_pc=0x0c043836u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c043838;
P_0c043838: /* original e400, guest PC 0x0c043838 */
if(!s->budget--) { s->failed_pc=0x0c043838u; return 0; }
r[4]=0x00000000u;
goto P_0c04383a;
P_0c04383a: /* original 6a43, guest PC 0x0c04383a */
if(!s->budget--) { s->failed_pc=0x0c04383au; return 0; }
r[10]=r[4];
goto P_0c04383c;
P_0c04383c: /* original 1f43, guest PC 0x0c04383c */
if(!s->budget--) { s->failed_pc=0x0c04383cu; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c04383e;
P_0c04383e: /* original 986e, guest PC 0x0c04383e */
if(!s->budget--) { s->failed_pc=0x0c04383eu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04391eu,2);
goto P_0c043840;
P_0c043840: /* original 3e8c, guest PC 0x0c043840 */
if(!s->budget--) { s->failed_pc=0x0c043840u; return 0; }
r[14]+=r[8];
goto P_0c043842;
P_0c043842: /* original 2fe2, guest PC 0x0c043842 */
if(!s->budget--) { s->failed_pc=0x0c043842u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c043844;
P_0c043844: /* original 63f2, guest PC 0x0c043844 */
if(!s->budget--) { s->failed_pc=0x0c043844u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c043846;
P_0c043846: /* original 3e32, guest PC 0x0c043846 */
if(!s->budget--) { s->failed_pc=0x0c043846u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c043848;
P_0c043848: /* original 8d0d, guest PC 0x0c043848 */
if(!s->budget--) { s->failed_pc=0x0c043848u; return 0; }
cond=r[17]&1u;
r[13]=r[14];
if(cond) { goto P_0c043866; }
goto P_0c04384c;
P_0c04384a: /* original 6de3, guest PC 0x0c04384a */
if(!s->budget--) { s->failed_pc=0x0c04384au; return 0; }
r[13]=r[14];
goto P_0c04384c;
P_0c04384c: /* original 61d0, guest PC 0x0c04384c */
if(!s->budget--) { s->failed_pc=0x0c04384cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[1]=tmp;
goto P_0c04384e;
P_0c04384e: /* original d334, guest PC 0x0c04384e */
if(!s->budget--) { s->failed_pc=0x0c04384eu; return 0; }
r[3]=read(ram,0x0c043920u,4);
goto P_0c043850;
P_0c043850: /* original 611c, guest PC 0x0c043850 */
if(!s->budget--) { s->failed_pc=0x0c043850u; return 0; }
r[1]=r[1]&255u;
goto P_0c043852;
P_0c043852: /* original 430b, guest PC 0x0c043852 */
if(!s->budget--) { s->failed_pc=0x0c043852u; return 0; }
target=r[3];
r[16]=code_base|0x0c043856u;
r[0]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043856u) { target=s->pc; goto dispatch; }
goto P_0c043856;
P_0c043854: /* original e002, guest PC 0x0c043854 */
if(!s->budget--) { s->failed_pc=0x0c043854u; return 0; }
r[0]=0x00000002u;
goto P_0c043856;
P_0c043856: /* original 61d0, guest PC 0x0c043856 */
if(!s->budget--) { s->failed_pc=0x0c043856u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[1]=tmp;
goto P_0c043858;
P_0c043858: /* original 62f2, guest PC 0x0c043858 */
if(!s->budget--) { s->failed_pc=0x0c043858u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04385a;
P_0c04385a: /* original 611c, guest PC 0x0c04385a */
if(!s->budget--) { s->failed_pc=0x0c04385au; return 0; }
r[1]=r[1]&255u;
goto P_0c04385c;
P_0c04385c: /* original 310c, guest PC 0x0c04385c */
if(!s->budget--) { s->failed_pc=0x0c04385cu; return 0; }
r[1]+=r[0];
goto P_0c04385e;
P_0c04385e: /* original 7108, guest PC 0x0c04385e */
if(!s->budget--) { s->failed_pc=0x0c04385eu; return 0; }
r[1]+=0x00000008u;
goto P_0c043860;
P_0c043860: /* original 31ec, guest PC 0x0c043860 */
if(!s->budget--) { s->failed_pc=0x0c043860u; return 0; }
r[1]+=r[14];
goto P_0c043862;
P_0c043862: /* original 3122, guest PC 0x0c043862 */
if(!s->budget--) { s->failed_pc=0x0c043862u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[2])!=0);
goto P_0c043864;
P_0c043864: /* original 8b13, guest PC 0x0c043864 */
if(!s->budget--) { s->failed_pc=0x0c043864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04388e; }
goto P_0c043866;
P_0c043866: /* original 6693, guest PC 0x0c043866 */
if(!s->budget--) { s->failed_pc=0x0c043866u; return 0; }
r[6]=r[9];
goto P_0c043868;
P_0c043868: /* original 36e8, guest PC 0x0c043868 */
if(!s->budget--) { s->failed_pc=0x0c043868u; return 0; }
r[6]-=r[14];
goto P_0c04386a;
P_0c04386a: /* original 6d93, guest PC 0x0c04386a */
if(!s->budget--) { s->failed_pc=0x0c04386au; return 0; }
r[13]=r[9];
goto P_0c04386c;
P_0c04386c: /* original 368c, guest PC 0x0c04386c */
if(!s->budget--) { s->failed_pc=0x0c04386cu; return 0; }
r[6]+=r[8];
goto P_0c04386e;
P_0c04386e: /* original 3d68, guest PC 0x0c04386e */
if(!s->budget--) { s->failed_pc=0x0c04386eu; return 0; }
r[13]-=r[6];
goto P_0c043870;
P_0c043870: /* original 65d3, guest PC 0x0c043870 */
if(!s->budget--) { s->failed_pc=0x0c043870u; return 0; }
r[5]=r[13];
goto P_0c043872;
P_0c043872: /* original be45, guest PC 0x0c043872 */
if(!s->budget--) { s->failed_pc=0x0c043872u; return 0; }
target=code_base|0x0c043500u; r[16]=code_base|0x0c043876u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043876u) { target=s->pc; goto dispatch; }
goto P_0c043876;
P_0c043874: /* original 64e3, guest PC 0x0c043874 */
if(!s->budget--) { s->failed_pc=0x0c043874u; return 0; }
r[4]=r[14];
goto P_0c043876;
P_0c043876: /* original d32b, guest PC 0x0c043876 */
if(!s->budget--) { s->failed_pc=0x0c043876u; return 0; }
r[3]=read(ram,0x0c043924u,4);
goto P_0c043878;
P_0c043878: /* original e501, guest PC 0x0c043878 */
if(!s->budget--) { s->failed_pc=0x0c043878u; return 0; }
r[5]=0x00000001u;
goto P_0c04387a;
P_0c04387a: /* original 6693, guest PC 0x0c04387a */
if(!s->budget--) { s->failed_pc=0x0c04387au; return 0; }
r[6]=r[9];
goto P_0c04387c;
P_0c04387c: /* original 430b, guest PC 0x0c04387c */
if(!s->budget--) { s->failed_pc=0x0c04387cu; return 0; }
target=r[3];
r[16]=code_base|0x0c043880u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043880u) { target=s->pc; goto dispatch; }
goto P_0c043880;
P_0c04387e: /* original 54f2, guest PC 0x0c04387e */
if(!s->budget--) { s->failed_pc=0x0c04387eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c043880;
P_0c043880: /* original 6403, guest PC 0x0c043880 */
if(!s->budget--) { s->failed_pc=0x0c043880u; return 0; }
r[4]=r[0];
goto P_0c043882;
P_0c043882: /* original 2448, guest PC 0x0c043882 */
if(!s->budget--) { s->failed_pc=0x0c043882u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c043884;
P_0c043884: /* original 8b40, guest PC 0x0c043884 */
if(!s->budget--) { s->failed_pc=0x0c043884u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043908; }
goto P_0c043886;
P_0c043886: /* original 53f2, guest PC 0x0c043886 */
if(!s->budget--) { s->failed_pc=0x0c043886u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c043888;
P_0c043888: /* original 6ed3, guest PC 0x0c043888 */
if(!s->budget--) { s->failed_pc=0x0c043888u; return 0; }
r[14]=r[13];
goto P_0c04388a;
P_0c04388a: /* original 7301, guest PC 0x0c04388a */
if(!s->budget--) { s->failed_pc=0x0c04388au; return 0; }
r[3]+=0x00000001u;
goto P_0c04388c;
P_0c04388c: /* original 1f32, guest PC 0x0c04388c */
if(!s->budget--) { s->failed_pc=0x0c04388cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04388e;
P_0c04388e: /* original 65f3, guest PC 0x0c04388e */
if(!s->budget--) { s->failed_pc=0x0c04388eu; return 0; }
r[5]=r[15];
goto P_0c043890;
P_0c043890: /* original 64d3, guest PC 0x0c043890 */
if(!s->budget--) { s->failed_pc=0x0c043890u; return 0; }
r[4]=r[13];
goto P_0c043892;
P_0c043892: /* original 7504, guest PC 0x0c043892 */
if(!s->budget--) { s->failed_pc=0x0c043892u; return 0; }
r[5]+=0x00000004u;
goto P_0c043894;
P_0c043894: /* original e602, guest PC 0x0c043894 */
if(!s->budget--) { s->failed_pc=0x0c043894u; return 0; }
r[6]=0x00000002u;
goto P_0c043896;
P_0c043896: /* original be33, guest PC 0x0c043896 */
if(!s->budget--) { s->failed_pc=0x0c043896u; return 0; }
target=code_base|0x0c043500u; r[16]=code_base|0x0c04389au;
r[4]+=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04389au) { target=s->pc; goto dispatch; }
goto P_0c04389a;
P_0c043898: /* original 7406, guest PC 0x0c043898 */
if(!s->budget--) { s->failed_pc=0x0c043898u; return 0; }
r[4]+=0x00000006u;
goto P_0c04389a;
P_0c04389a: /* original 85f2, guest PC 0x0c04389a */
if(!s->budget--) { s->failed_pc=0x0c04389au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04389c;
P_0c04389c: /* original 53f5, guest PC 0x0c04389c */
if(!s->budget--) { s->failed_pc=0x0c04389cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c04389e;
P_0c04389e: /* original 600d, guest PC 0x0c04389e */
if(!s->budget--) { s->failed_pc=0x0c04389eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0438a0;
P_0c0438a0: /* original 3030, guest PC 0x0c0438a0 */
if(!s->budget--) { s->failed_pc=0x0c0438a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c0438a2;
P_0c0438a2: /* original 8b20, guest PC 0x0c0438a2 */
if(!s->budget--) { s->failed_pc=0x0c0438a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0438e6; }
goto P_0c0438a4;
P_0c0438a4: /* original 60b3, guest PC 0x0c0438a4 */
if(!s->budget--) { s->failed_pc=0x0c0438a4u; return 0; }
r[0]=r[11];
goto P_0c0438a6;
P_0c0438a6: /* original 8801, guest PC 0x0c0438a6 */
if(!s->budget--) { s->failed_pc=0x0c0438a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0438a8;
P_0c0438a8: /* original 890a, guest PC 0x0c0438a8 */
if(!s->budget--) { s->failed_pc=0x0c0438a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0438c0; }
goto P_0c0438aa;
P_0c0438aa: /* original 62d0, guest PC 0x0c0438aa */
if(!s->budget--) { s->failed_pc=0x0c0438aau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[2]=tmp;
goto P_0c0438ac;
P_0c0438ac: /* original 622c, guest PC 0x0c0438ac */
if(!s->budget--) { s->failed_pc=0x0c0438acu; return 0; }
r[2]=r[2]&255u;
goto P_0c0438ae;
P_0c0438ae: /* original 32a0, guest PC 0x0c0438ae */
if(!s->budget--) { s->failed_pc=0x0c0438aeu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[10])!=0);
goto P_0c0438b0;
P_0c0438b0: /* original 8b19, guest PC 0x0c0438b0 */
if(!s->budget--) { s->failed_pc=0x0c0438b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0438e6; }
goto P_0c0438b2;
P_0c0438b2: /* original 64d3, guest PC 0x0c0438b2 */
if(!s->budget--) { s->failed_pc=0x0c0438b2u; return 0; }
r[4]=r[13];
goto P_0c0438b4;
P_0c0438b4: /* original 65c3, guest PC 0x0c0438b4 */
if(!s->budget--) { s->failed_pc=0x0c0438b4u; return 0; }
r[5]=r[12];
goto P_0c0438b6;
P_0c0438b6: /* original 66a3, guest PC 0x0c0438b6 */
if(!s->budget--) { s->failed_pc=0x0c0438b6u; return 0; }
r[6]=r[10];
goto P_0c0438b8;
P_0c0438b8: /* original be2e, guest PC 0x0c0438b8 */
if(!s->budget--) { s->failed_pc=0x0c0438b8u; return 0; }
target=code_base|0x0c043518u; r[16]=code_base|0x0c0438bcu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0438bcu) { target=s->pc; goto dispatch; }
goto P_0c0438bc;
P_0c0438ba: /* original 7408, guest PC 0x0c0438ba */
if(!s->budget--) { s->failed_pc=0x0c0438bau; return 0; }
r[4]+=0x00000008u;
goto P_0c0438bc;
P_0c0438bc: /* original 2008, guest PC 0x0c0438bc */
if(!s->budget--) { s->failed_pc=0x0c0438bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0438be;
P_0c0438be: /* original 8912, guest PC 0x0c0438be */
if(!s->budget--) { s->failed_pc=0x0c0438beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0438e6; }
goto P_0c0438c0;
P_0c0438c0: /* original 3cac, guest PC 0x0c0438c0 */
if(!s->budget--) { s->failed_pc=0x0c0438c0u; return 0; }
r[12]+=r[10];
goto P_0c0438c2;
P_0c0438c2: /* original 1fb5, guest PC 0x0c0438c2 */
if(!s->budget--) { s->failed_pc=0x0c0438c2u; return 0; }
write(ram,r[15]+20,r[11],4);
goto P_0c0438c4;
P_0c0438c4: /* original 63c0, guest PC 0x0c0438c4 */
if(!s->budget--) { s->failed_pc=0x0c0438c4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[3]=tmp;
goto P_0c0438c6;
P_0c0438c6: /* original 2338, guest PC 0x0c0438c6 */
if(!s->budget--) { s->failed_pc=0x0c0438c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0438c8;
P_0c0438c8: /* original 8b05, guest PC 0x0c0438c8 */
if(!s->budget--) { s->failed_pc=0x0c0438c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0438d6; }
goto P_0c0438ca;
P_0c0438ca: /* original d317, guest PC 0x0c0438ca */
if(!s->budget--) { s->failed_pc=0x0c0438cau; return 0; }
r[3]=read(ram,0x0c043928u,4);
goto P_0c0438cc;
P_0c0438cc: /* original 64d3, guest PC 0x0c0438cc */
if(!s->budget--) { s->failed_pc=0x0c0438ccu; return 0; }
r[4]=r[13];
goto P_0c0438ce;
P_0c0438ce: /* original 430b, guest PC 0x0c0438ce */
if(!s->budget--) { s->failed_pc=0x0c0438ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0438d2u;
r[4]+=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0438d2u) { target=s->pc; goto dispatch; }
goto P_0c0438d2;
P_0c0438d0: /* original 7402, guest PC 0x0c0438d0 */
if(!s->budget--) { s->failed_pc=0x0c0438d0u; return 0; }
r[4]+=0x00000002u;
goto P_0c0438d2;
P_0c0438d2: /* original a01a, guest PC 0x0c0438d2 */
if(!s->budget--) { s->failed_pc=0x0c0438d2u; return 0; }
goto P_0c04390a;
P_0c0438d4: /* original 0009, guest PC 0x0c0438d4 */
if(!s->budget--) { s->failed_pc=0x0c0438d4u; return 0; }
goto P_0c0438d6;
P_0c0438d6: /* original 60b3, guest PC 0x0c0438d6 */
if(!s->budget--) { s->failed_pc=0x0c0438d6u; return 0; }
r[0]=r[11];
goto P_0c0438d8;
P_0c0438d8: /* original 8801, guest PC 0x0c0438d8 */
if(!s->budget--) { s->failed_pc=0x0c0438d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0438da;
P_0c0438da: /* original 8900, guest PC 0x0c0438da */
if(!s->budget--) { s->failed_pc=0x0c0438dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0438de; }
goto P_0c0438dc;
P_0c0438dc: /* original 7c01, guest PC 0x0c0438dc */
if(!s->budget--) { s->failed_pc=0x0c0438dcu; return 0; }
r[12]+=0x00000001u;
goto P_0c0438de;
P_0c0438de: /* original d513, guest PC 0x0c0438de */
if(!s->budget--) { s->failed_pc=0x0c0438deu; return 0; }
r[5]=read(ram,0x0c04392cu,4);
goto P_0c0438e0;
P_0c0438e0: /* original be7b, guest PC 0x0c0438e0 */
if(!s->budget--) { s->failed_pc=0x0c0438e0u; return 0; }
target=code_base|0x0c0435dau; r[16]=code_base|0x0c0438e4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0438e4u) { target=s->pc; goto dispatch; }
goto P_0c0438e4;
P_0c0438e2: /* original 64c3, guest PC 0x0c0438e2 */
if(!s->budget--) { s->failed_pc=0x0c0438e2u; return 0; }
r[4]=r[12];
goto P_0c0438e4;
P_0c0438e4: /* original 6a03, guest PC 0x0c0438e4 */
if(!s->budget--) { s->failed_pc=0x0c0438e4u; return 0; }
r[10]=r[0];
goto P_0c0438e6;
P_0c0438e6: /* original 65d0, guest PC 0x0c0438e6 */
if(!s->budget--) { s->failed_pc=0x0c0438e6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[5]=tmp;
goto P_0c0438e8;
P_0c0438e8: /* original 7b01, guest PC 0x0c0438e8 */
if(!s->budget--) { s->failed_pc=0x0c0438e8u; return 0; }
r[11]+=0x00000001u;
goto P_0c0438ea;
P_0c0438ea: /* original d20d, guest PC 0x0c0438ea */
if(!s->budget--) { s->failed_pc=0x0c0438eau; return 0; }
r[2]=read(ram,0x0c043920u,4);
goto P_0c0438ec;
P_0c0438ec: /* original 655c, guest PC 0x0c0438ec */
if(!s->budget--) { s->failed_pc=0x0c0438ecu; return 0; }
r[5]=r[5]&255u;
goto P_0c0438ee;
P_0c0438ee: /* original 6153, guest PC 0x0c0438ee */
if(!s->budget--) { s->failed_pc=0x0c0438eeu; return 0; }
r[1]=r[5];
goto P_0c0438f0;
P_0c0438f0: /* original 420b, guest PC 0x0c0438f0 */
if(!s->budget--) { s->failed_pc=0x0c0438f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0438f4u;
r[0]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0438f4u) { target=s->pc; goto dispatch; }
goto P_0c0438f4;
P_0c0438f2: /* original e002, guest PC 0x0c0438f2 */
if(!s->budget--) { s->failed_pc=0x0c0438f2u; return 0; }
r[0]=0x00000002u;
goto P_0c0438f4;
P_0c0438f4: /* original 6453, guest PC 0x0c0438f4 */
if(!s->budget--) { s->failed_pc=0x0c0438f4u; return 0; }
r[4]=r[5];
goto P_0c0438f6;
P_0c0438f6: /* original 53f3, guest PC 0x0c0438f6 */
if(!s->budget--) { s->failed_pc=0x0c0438f6u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0438f8;
P_0c0438f8: /* original 340c, guest PC 0x0c0438f8 */
if(!s->budget--) { s->failed_pc=0x0c0438f8u; return 0; }
r[4]+=r[0];
goto P_0c0438fa;
P_0c0438fa: /* original 7408, guest PC 0x0c0438fa */
if(!s->budget--) { s->failed_pc=0x0c0438fau; return 0; }
r[4]+=0x00000008u;
goto P_0c0438fc;
P_0c0438fc: /* original 334c, guest PC 0x0c0438fc */
if(!s->budget--) { s->failed_pc=0x0c0438fcu; return 0; }
r[3]+=r[4];
goto P_0c0438fe;
P_0c0438fe: /* original 1f33, guest PC 0x0c0438fe */
if(!s->budget--) { s->failed_pc=0x0c0438feu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c043900;
P_0c043900: /* original 52f4, guest PC 0x0c043900 */
if(!s->budget--) { s->failed_pc=0x0c043900u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c043902;
P_0c043902: /* original 3323, guest PC 0x0c043902 */
if(!s->budget--) { s->failed_pc=0x0c043902u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c043904;
P_0c043904: /* original 8f9e, guest PC 0x0c043904 */
if(!s->budget--) { s->failed_pc=0x0c043904u; return 0; }
cond=r[17]&1u;
r[14]+=r[4];
if(!cond) { goto P_0c043844; }
goto P_0c043908;
P_0c043906: /* original 3e4c, guest PC 0x0c043906 */
if(!s->budget--) { s->failed_pc=0x0c043906u; return 0; }
r[14]+=r[4];
goto P_0c043908;
P_0c043908: /* original e000, guest PC 0x0c043908 */
if(!s->budget--) { s->failed_pc=0x0c043908u; return 0; }
r[0]=0x00000000u;
goto P_0c04390a;
P_0c04390a: /* original 7f18, guest PC 0x0c04390a */
if(!s->budget--) { s->failed_pc=0x0c04390au; return 0; }
r[15]+=0x00000018u;
goto P_0c04390c;
P_0c04390c: /* original 4f26, guest PC 0x0c04390c */
if(!s->budget--) { s->failed_pc=0x0c04390cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04390e;
P_0c04390e: /* original 68f6, guest PC 0x0c04390e */
if(!s->budget--) { s->failed_pc=0x0c04390eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c043910;
P_0c043910: /* original 69f6, guest PC 0x0c043910 */
if(!s->budget--) { s->failed_pc=0x0c043910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c043912;
P_0c043912: /* original 6af6, guest PC 0x0c043912 */
if(!s->budget--) { s->failed_pc=0x0c043912u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c043914;
P_0c043914: /* original 6bf6, guest PC 0x0c043914 */
if(!s->budget--) { s->failed_pc=0x0c043914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c043916;
P_0c043916: /* original 6cf6, guest PC 0x0c043916 */
if(!s->budget--) { s->failed_pc=0x0c043916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043918;
P_0c043918: /* original 6df6, guest PC 0x0c043918 */
if(!s->budget--) { s->failed_pc=0x0c043918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04391a;
P_0c04391a: /* original 000b, guest PC 0x0c04391a */
if(!s->budget--) { s->failed_pc=0x0c04391au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04391c: /* original 6ef6, guest PC 0x0c04391c */
if(!s->budget--) { s->failed_pc=0x0c04391cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04391eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04391eu; return 0; } return 1;
P_0c043964: /* original 2fe6, guest PC 0x0c043964 */
if(!s->budget--) { s->failed_pc=0x0c043964u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043966;
P_0c043966: /* original 2fd6, guest PC 0x0c043966 */
if(!s->budget--) { s->failed_pc=0x0c043966u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043968;
P_0c043968: /* original d138, guest PC 0x0c043968 */
if(!s->budget--) { s->failed_pc=0x0c043968u; return 0; }
r[1]=read(ram,0x0c043a4cu,4);
goto P_0c04396a;
P_0c04396a: /* original d237, guest PC 0x0c04396a */
if(!s->budget--) { s->failed_pc=0x0c04396au; return 0; }
r[2]=read(ram,0x0c043a48u,4);
goto P_0c04396c;
P_0c04396c: /* original 6312, guest PC 0x0c04396c */
if(!s->budget--) { s->failed_pc=0x0c04396cu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c04396e;
P_0c04396e: /* original 4f22, guest PC 0x0c04396e */
if(!s->budget--) { s->failed_pc=0x0c04396eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043970;
P_0c043970: /* original 2232, guest PC 0x0c043970 */
if(!s->budget--) { s->failed_pc=0x0c043970u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c043972;
P_0c043972: /* original d037, guest PC 0x0c043972 */
if(!s->budget--) { s->failed_pc=0x0c043972u; return 0; }
r[0]=read(ram,0x0c043a50u,4);
goto P_0c043974;
P_0c043974: /* original 6302, guest PC 0x0c043974 */
if(!s->budget--) { s->failed_pc=0x0c043974u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c043976;
P_0c043976: /* original 7301, guest PC 0x0c043976 */
if(!s->budget--) { s->failed_pc=0x0c043976u; return 0; }
r[3]+=0x00000001u;
goto P_0c043978;
P_0c043978: /* original 2032, guest PC 0x0c043978 */
if(!s->budget--) { s->failed_pc=0x0c043978u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c04397a;
P_0c04397a: /* original de36, guest PC 0x0c04397a */
if(!s->budget--) { s->failed_pc=0x0c04397au; return 0; }
r[14]=read(ram,0x0c043a54u,4);
goto P_0c04397c;
P_0c04397c: /* original 52e2, guest PC 0x0c04397c */
if(!s->budget--) { s->failed_pc=0x0c04397cu; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c04397e;
P_0c04397e: /* original 7201, guest PC 0x0c04397e */
if(!s->budget--) { s->failed_pc=0x0c04397eu; return 0; }
r[2]+=0x00000001u;
goto P_0c043980;
P_0c043980: /* original 1e22, guest PC 0x0c043980 */
if(!s->budget--) { s->failed_pc=0x0c043980u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c043982;
P_0c043982: /* original d235, guest PC 0x0c043982 */
if(!s->budget--) { s->failed_pc=0x0c043982u; return 0; }
r[2]=read(ram,0x0c043a58u,4);
goto P_0c043984;
P_0c043984: /* original 6322, guest PC 0x0c043984 */
if(!s->budget--) { s->failed_pc=0x0c043984u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c043986;
P_0c043986: /* original 2338, guest PC 0x0c043986 */
if(!s->budget--) { s->failed_pc=0x0c043986u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c043988;
P_0c043988: /* original 890d, guest PC 0x0c043988 */
if(!s->budget--) { s->failed_pc=0x0c043988u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0439a6; }
goto P_0c04398a;
P_0c04398a: /* original 53e5, guest PC 0x0c04398a */
if(!s->budget--) { s->failed_pc=0x0c04398au; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c04398c;
P_0c04398c: /* original 7301, guest PC 0x0c04398c */
if(!s->budget--) { s->failed_pc=0x0c04398cu; return 0; }
r[3]+=0x00000001u;
goto P_0c04398e;
P_0c04398e: /* original 1e35, guest PC 0x0c04398e */
if(!s->budget--) { s->failed_pc=0x0c04398eu; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c043990;
P_0c043990: /* original d132, guest PC 0x0c043990 */
if(!s->budget--) { s->failed_pc=0x0c043990u; return 0; }
r[1]=read(ram,0x0c043a5cu,4);
goto P_0c043992;
P_0c043992: /* original 6d12, guest PC 0x0c043992 */
if(!s->budget--) { s->failed_pc=0x0c043992u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c043994;
P_0c043994: /* original 2dd8, guest PC 0x0c043994 */
if(!s->budget--) { s->failed_pc=0x0c043994u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c043996;
P_0c043996: /* original 890c, guest PC 0x0c043996 */
if(!s->budget--) { s->failed_pc=0x0c043996u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0439b2; }
goto P_0c043998;
P_0c043998: /* original 56e2, guest PC 0x0c043998 */
if(!s->budget--) { s->failed_pc=0x0c043998u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c04399a;
P_0c04399a: /* original e5ff, guest PC 0x0c04399a */
if(!s->budget--) { s->failed_pc=0x0c04399au; return 0; }
r[5]=0xffffffffu;
goto P_0c04399c;
P_0c04399c: /* original e700, guest PC 0x0c04399c */
if(!s->budget--) { s->failed_pc=0x0c04399cu; return 0; }
r[7]=0x00000000u;
goto P_0c04399e;
P_0c04399e: /* original 4d0b, guest PC 0x0c04399e */
if(!s->budget--) { s->failed_pc=0x0c04399eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0439a2u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0439a2u) { target=s->pc; goto dispatch; }
goto P_0c0439a2;
P_0c0439a0: /* original 6473, guest PC 0x0c0439a0 */
if(!s->budget--) { s->failed_pc=0x0c0439a0u; return 0; }
r[4]=r[7];
goto P_0c0439a2;
P_0c0439a2: /* original a006, guest PC 0x0c0439a2 */
if(!s->budget--) { s->failed_pc=0x0c0439a2u; return 0; }
goto P_0c0439b2;
P_0c0439a4: /* original 0009, guest PC 0x0c0439a4 */
if(!s->budget--) { s->failed_pc=0x0c0439a4u; return 0; }
goto P_0c0439a6;
P_0c0439a6: /* original b105, guest PC 0x0c0439a6 */
if(!s->budget--) { s->failed_pc=0x0c0439a6u; return 0; }
target=code_base|0x0c043bb4u; r[16]=code_base|0x0c0439aau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0439aau) { target=s->pc; goto dispatch; }
goto P_0c0439aa;
P_0c0439a8: /* original 0009, guest PC 0x0c0439a8 */
if(!s->budget--) { s->failed_pc=0x0c0439a8u; return 0; }
goto P_0c0439aa;
P_0c0439aa: /* original d128, guest PC 0x0c0439aa */
if(!s->budget--) { s->failed_pc=0x0c0439aau; return 0; }
r[1]=read(ram,0x0c043a4cu,4);
goto P_0c0439ac;
P_0c0439ac: /* original d32c, guest PC 0x0c0439ac */
if(!s->budget--) { s->failed_pc=0x0c0439acu; return 0; }
r[3]=read(ram,0x0c043a60u,4);
goto P_0c0439ae;
P_0c0439ae: /* original 6212, guest PC 0x0c0439ae */
if(!s->budget--) { s->failed_pc=0x0c0439aeu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0439b0;
P_0c0439b0: /* original 2322, guest PC 0x0c0439b0 */
if(!s->budget--) { s->failed_pc=0x0c0439b0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0439b2;
P_0c0439b2: /* original 4f26, guest PC 0x0c0439b2 */
if(!s->budget--) { s->failed_pc=0x0c0439b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0439b4;
P_0c0439b4: /* original 6df6, guest PC 0x0c0439b4 */
if(!s->budget--) { s->failed_pc=0x0c0439b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0439b6;
P_0c0439b6: /* original 000b, guest PC 0x0c0439b6 */
if(!s->budget--) { s->failed_pc=0x0c0439b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0439b8: /* original 6ef6, guest PC 0x0c0439b8 */
if(!s->budget--) { s->failed_pc=0x0c0439b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0439bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0439bau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
