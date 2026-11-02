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
int vf3_away_batch118_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a876au: goto P_0c0a876a;
case 0x0c0a876cu: goto P_0c0a876c;
case 0x0c0a876eu: goto P_0c0a876e;
case 0x0c0a8770u: goto P_0c0a8770;
case 0x0c0a8772u: goto P_0c0a8772;
case 0x0c0a8774u: goto P_0c0a8774;
case 0x0c0a8776u: goto P_0c0a8776;
case 0x0c0a8778u: goto P_0c0a8778;
case 0x0c0a877au: goto P_0c0a877a;
case 0x0c0a877cu: goto P_0c0a877c;
case 0x0c0a877eu: goto P_0c0a877e;
case 0x0c0a8780u: goto P_0c0a8780;
case 0x0c0a8782u: goto P_0c0a8782;
case 0x0c0a8794u: goto P_0c0a8794;
case 0x0c0a8796u: goto P_0c0a8796;
case 0x0c0a8798u: goto P_0c0a8798;
case 0x0c0a879au: goto P_0c0a879a;
case 0x0c0a879cu: goto P_0c0a879c;
case 0x0c0a879eu: goto P_0c0a879e;
case 0x0c0a87a0u: goto P_0c0a87a0;
case 0x0c0a87a2u: goto P_0c0a87a2;
case 0x0c0a87a4u: goto P_0c0a87a4;
case 0x0c0a87a6u: goto P_0c0a87a6;
case 0x0c0a87a8u: goto P_0c0a87a8;
case 0x0c0a87fcu: goto P_0c0a87fc;
case 0x0c0a87feu: goto P_0c0a87fe;
case 0x0c0a8800u: goto P_0c0a8800;
case 0x0c0a8802u: goto P_0c0a8802;
case 0x0c0a8804u: goto P_0c0a8804;
case 0x0c0a8806u: goto P_0c0a8806;
case 0x0c0a8808u: goto P_0c0a8808;
case 0x0c0a880au: goto P_0c0a880a;
case 0x0c0a880cu: goto P_0c0a880c;
case 0x0c0a880eu: goto P_0c0a880e;
case 0x0c0a8810u: goto P_0c0a8810;
case 0x0c0a8812u: goto P_0c0a8812;
case 0x0c0a8814u: goto P_0c0a8814;
case 0x0c0a8816u: goto P_0c0a8816;
case 0x0c0a8818u: goto P_0c0a8818;
case 0x0c0a881au: goto P_0c0a881a;
case 0x0c0a881cu: goto P_0c0a881c;
case 0x0c0a881eu: goto P_0c0a881e;
case 0x0c0a8820u: goto P_0c0a8820;
case 0x0c0a8822u: goto P_0c0a8822;
case 0x0c0a8824u: goto P_0c0a8824;
case 0x0c0a8826u: goto P_0c0a8826;
case 0x0c0a8828u: goto P_0c0a8828;
case 0x0c0a882au: goto P_0c0a882a;
case 0x0c0a882cu: goto P_0c0a882c;
case 0x0c0a882eu: goto P_0c0a882e;
case 0x0c0a8830u: goto P_0c0a8830;
case 0x0c0a8832u: goto P_0c0a8832;
case 0x0c0a8834u: goto P_0c0a8834;
case 0x0c0a8836u: goto P_0c0a8836;
case 0x0c0a8838u: goto P_0c0a8838;
case 0x0c0a883au: goto P_0c0a883a;
case 0x0c0a883cu: goto P_0c0a883c;
case 0x0c0a883eu: goto P_0c0a883e;
case 0x0c0a8840u: goto P_0c0a8840;
case 0x0c0a8842u: goto P_0c0a8842;
case 0x0c0a8844u: goto P_0c0a8844;
case 0x0c0a8846u: goto P_0c0a8846;
case 0x0c0a8848u: goto P_0c0a8848;
case 0x0c0a884au: goto P_0c0a884a;
case 0x0c0a884cu: goto P_0c0a884c;
case 0x0c0a884eu: goto P_0c0a884e;
case 0x0c0a8850u: goto P_0c0a8850;
case 0x0c0a8852u: goto P_0c0a8852;
case 0x0c0a8854u: goto P_0c0a8854;
case 0x0c0a8856u: goto P_0c0a8856;
case 0x0c0a8858u: goto P_0c0a8858;
case 0x0c0a885au: goto P_0c0a885a;
case 0x0c0a885cu: goto P_0c0a885c;
case 0x0c0a885eu: goto P_0c0a885e;
case 0x0c0a8860u: goto P_0c0a8860;
case 0x0c0a8862u: goto P_0c0a8862;
case 0x0c0a8864u: goto P_0c0a8864;
case 0x0c0a8866u: goto P_0c0a8866;
case 0x0c0a8868u: goto P_0c0a8868;
case 0x0c0a886au: goto P_0c0a886a;
case 0x0c0a886cu: goto P_0c0a886c;
case 0x0c0a886eu: goto P_0c0a886e;
case 0x0c0a8870u: goto P_0c0a8870;
case 0x0c0a8872u: goto P_0c0a8872;
case 0x0c0a8874u: goto P_0c0a8874;
case 0x0c0a8876u: goto P_0c0a8876;
case 0x0c0a8878u: goto P_0c0a8878;
case 0x0c0a887au: goto P_0c0a887a;
case 0x0c0a887cu: goto P_0c0a887c;
case 0x0c0a887eu: goto P_0c0a887e;
case 0x0c0a8880u: goto P_0c0a8880;
case 0x0c0a8882u: goto P_0c0a8882;
case 0x0c0a8884u: goto P_0c0a8884;
case 0x0c0a8886u: goto P_0c0a8886;
case 0x0c0a8888u: goto P_0c0a8888;
case 0x0c0a888au: goto P_0c0a888a;
case 0x0c0a888cu: goto P_0c0a888c;
case 0x0c0a888eu: goto P_0c0a888e;
case 0x0c0a8890u: goto P_0c0a8890;
case 0x0c0a8892u: goto P_0c0a8892;
case 0x0c0a8894u: goto P_0c0a8894;
case 0x0c0a8896u: goto P_0c0a8896;
case 0x0c0a8898u: goto P_0c0a8898;
case 0x0c0a889au: goto P_0c0a889a;
case 0x0c0a889cu: goto P_0c0a889c;
case 0x0c0a889eu: goto P_0c0a889e;
case 0x0c0a88a0u: goto P_0c0a88a0;
case 0x0c0a88a2u: goto P_0c0a88a2;
case 0x0c0a88a4u: goto P_0c0a88a4;
case 0x0c0a88a6u: goto P_0c0a88a6;
case 0x0c0a88a8u: goto P_0c0a88a8;
case 0x0c0a88aau: goto P_0c0a88aa;
case 0x0c0a88acu: goto P_0c0a88ac;
case 0x0c0a88aeu: goto P_0c0a88ae;
case 0x0c0a88b0u: goto P_0c0a88b0;
case 0x0c0a88b2u: goto P_0c0a88b2;
case 0x0c0a88b4u: goto P_0c0a88b4;
case 0x0c0a88b6u: goto P_0c0a88b6;
case 0x0c0a88b8u: goto P_0c0a88b8;
case 0x0c0a88bau: goto P_0c0a88ba;
case 0x0c0a88bcu: goto P_0c0a88bc;
case 0x0c0a88beu: goto P_0c0a88be;
case 0x0c0a88c0u: goto P_0c0a88c0;
case 0x0c0a88c2u: goto P_0c0a88c2;
case 0x0c0a88c4u: goto P_0c0a88c4;
case 0x0c0a88c6u: goto P_0c0a88c6;
case 0x0c0a88c8u: goto P_0c0a88c8;
case 0x0c0a88cau: goto P_0c0a88ca;
case 0x0c0a88ccu: goto P_0c0a88cc;
case 0x0c0a88ceu: goto P_0c0a88ce;
case 0x0c0a88d0u: goto P_0c0a88d0;
case 0x0c0a88d2u: goto P_0c0a88d2;
case 0x0c0a88d4u: goto P_0c0a88d4;
case 0x0c0a88d6u: goto P_0c0a88d6;
case 0x0c0a88d8u: goto P_0c0a88d8;
case 0x0c0a88dau: goto P_0c0a88da;
case 0x0c0a88dcu: goto P_0c0a88dc;
case 0x0c0a88deu: goto P_0c0a88de;
case 0x0c0a88e0u: goto P_0c0a88e0;
case 0x0c0a88e2u: goto P_0c0a88e2;
case 0x0c0a88e4u: goto P_0c0a88e4;
case 0x0c0a8908u: goto P_0c0a8908;
case 0x0c0a890au: goto P_0c0a890a;
case 0x0c0a890cu: goto P_0c0a890c;
case 0x0c0a890eu: goto P_0c0a890e;
case 0x0c0a8910u: goto P_0c0a8910;
case 0x0c0a8912u: goto P_0c0a8912;
case 0x0c0a8914u: goto P_0c0a8914;
case 0x0c0a8916u: goto P_0c0a8916;
case 0x0c0a8918u: goto P_0c0a8918;
case 0x0c0a891au: goto P_0c0a891a;
case 0x0c0a891cu: goto P_0c0a891c;
case 0x0c0a891eu: goto P_0c0a891e;
case 0x0c0a8920u: goto P_0c0a8920;
case 0x0c0a8922u: goto P_0c0a8922;
case 0x0c0a8924u: goto P_0c0a8924;
case 0x0c0a8926u: goto P_0c0a8926;
case 0x0c0a8928u: goto P_0c0a8928;
case 0x0c0a892au: goto P_0c0a892a;
case 0x0c0a892cu: goto P_0c0a892c;
case 0x0c0a892eu: goto P_0c0a892e;
case 0x0c0a8930u: goto P_0c0a8930;
case 0x0c0a8932u: goto P_0c0a8932;
case 0x0c0a8934u: goto P_0c0a8934;
case 0x0c0a8936u: goto P_0c0a8936;
case 0x0c0a8938u: goto P_0c0a8938;
case 0x0c0a893au: goto P_0c0a893a;
case 0x0c0a893cu: goto P_0c0a893c;
case 0x0c0a893eu: goto P_0c0a893e;
case 0x0c0a8940u: goto P_0c0a8940;
case 0x0c0a8942u: goto P_0c0a8942;
case 0x0c0a8944u: goto P_0c0a8944;
case 0x0c0a8946u: goto P_0c0a8946;
case 0x0c0a8948u: goto P_0c0a8948;
case 0x0c0a894au: goto P_0c0a894a;
case 0x0c0a894cu: goto P_0c0a894c;
case 0x0c0a894eu: goto P_0c0a894e;
case 0x0c0a8950u: goto P_0c0a8950;
case 0x0c0a8952u: goto P_0c0a8952;
case 0x0c0a8954u: goto P_0c0a8954;
case 0x0c0a8956u: goto P_0c0a8956;
case 0x0c0a8958u: goto P_0c0a8958;
case 0x0c0a895au: goto P_0c0a895a;
case 0x0c0a895cu: goto P_0c0a895c;
case 0x0c0a895eu: goto P_0c0a895e;
case 0x0c0a8960u: goto P_0c0a8960;
case 0x0c0a8962u: goto P_0c0a8962;
case 0x0c0a8964u: goto P_0c0a8964;
case 0x0c0a8966u: goto P_0c0a8966;
case 0x0c0a8968u: goto P_0c0a8968;
case 0x0c0a896au: goto P_0c0a896a;
case 0x0c0a896cu: goto P_0c0a896c;
case 0x0c0a896eu: goto P_0c0a896e;
case 0x0c0a8970u: goto P_0c0a8970;
case 0x0c0a8972u: goto P_0c0a8972;
case 0x0c0a8974u: goto P_0c0a8974;
case 0x0c0a8976u: goto P_0c0a8976;
case 0x0c0a8978u: goto P_0c0a8978;
case 0x0c0a897au: goto P_0c0a897a;
case 0x0c0a897cu: goto P_0c0a897c;
case 0x0c0a897eu: goto P_0c0a897e;
case 0x0c0a8980u: goto P_0c0a8980;
case 0x0c0a8982u: goto P_0c0a8982;
case 0x0c0a8984u: goto P_0c0a8984;
case 0x0c0a8986u: goto P_0c0a8986;
case 0x0c0a8988u: goto P_0c0a8988;
case 0x0c0a898au: goto P_0c0a898a;
case 0x0c0a898cu: goto P_0c0a898c;
case 0x0c0a898eu: goto P_0c0a898e;
case 0x0c0a8990u: goto P_0c0a8990;
case 0x0c0a8992u: goto P_0c0a8992;
case 0x0c0a8994u: goto P_0c0a8994;
case 0x0c0a8996u: goto P_0c0a8996;
case 0x0c0a8998u: goto P_0c0a8998;
case 0x0c0a899au: goto P_0c0a899a;
case 0x0c0a899cu: goto P_0c0a899c;
case 0x0c0a899eu: goto P_0c0a899e;
case 0x0c0a89a0u: goto P_0c0a89a0;
case 0x0c0a89a2u: goto P_0c0a89a2;
case 0x0c0a89a4u: goto P_0c0a89a4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a876a: /* original 2448, guest PC 0x0c0a876a */
if(!s->budget--) { s->failed_pc=0x0c0a876au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a876c;
P_0c0a876c: /* original 8f12, guest PC 0x0c0a876c */
if(!s->budget--) { s->failed_pc=0x0c0a876cu; return 0; }
cond=r[17]&1u;
r[7]=r[6];
if(!cond) { goto P_0c0a8794; }
goto P_0c0a8770;
P_0c0a876e: /* original 6763, guest PC 0x0c0a876e */
if(!s->budget--) { s->failed_pc=0x0c0a876eu; return 0; }
r[7]=r[6];
goto P_0c0a8770;
P_0c0a8770: /* original 2558, guest PC 0x0c0a8770 */
if(!s->budget--) { s->failed_pc=0x0c0a8770u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a8772;
P_0c0a8772: /* original 8901, guest PC 0x0c0a8772 */
if(!s->budget--) { s->failed_pc=0x0c0a8772u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8778; }
goto P_0c0a8774;
P_0c0a8774: /* original 6763, guest PC 0x0c0a8774 */
if(!s->budget--) { s->failed_pc=0x0c0a8774u; return 0; }
r[7]=r[6];
goto P_0c0a8776;
P_0c0a8776: /* original 7740, guest PC 0x0c0a8776 */
if(!s->budget--) { s->failed_pc=0x0c0a8776u; return 0; }
r[7]+=0x00000040u;
goto P_0c0a8778;
P_0c0a8778: /* original d605, guest PC 0x0c0a8778 */
if(!s->budget--) { s->failed_pc=0x0c0a8778u; return 0; }
r[6]=read(ram,0x0c0a8790u,4);
goto P_0c0a877a;
P_0c0a877a: /* original 5574, guest PC 0x0c0a877a */
if(!s->budget--) { s->failed_pc=0x0c0a877au; return 0; }
r[5]=read(ram,r[7]+16,4);
goto P_0c0a877c;
P_0c0a877c: /* original 2568, guest PC 0x0c0a877c */
if(!s->budget--) { s->failed_pc=0x0c0a877cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[6])==0)!=0);
goto P_0c0a877e;
P_0c0a877e: /* original 8b12, guest PC 0x0c0a877e */
if(!s->budget--) { s->failed_pc=0x0c0a877eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a87a6; }
goto P_0c0a8780;
P_0c0a8780: /* original a011, guest PC 0x0c0a8780 */
if(!s->budget--) { s->failed_pc=0x0c0a8780u; return 0; }
r[4]=0x00000001u;
goto P_0c0a87a6;
P_0c0a8782: /* original e401, guest PC 0x0c0a8782 */
if(!s->budget--) { s->failed_pc=0x0c0a8782u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c0a8784u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8784u; return 0; } return 1;
P_0c0a8794: /* original 2558, guest PC 0x0c0a8794 */
if(!s->budget--) { s->failed_pc=0x0c0a8794u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a8796;
P_0c0a8796: /* original 8b01, guest PC 0x0c0a8796 */
if(!s->budget--) { s->failed_pc=0x0c0a8796u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a879c; }
goto P_0c0a8798;
P_0c0a8798: /* original 6763, guest PC 0x0c0a8798 */
if(!s->budget--) { s->failed_pc=0x0c0a8798u; return 0; }
r[7]=r[6];
goto P_0c0a879a;
P_0c0a879a: /* original 7740, guest PC 0x0c0a879a */
if(!s->budget--) { s->failed_pc=0x0c0a879au; return 0; }
r[7]+=0x00000040u;
goto P_0c0a879c;
P_0c0a879c: /* original d514, guest PC 0x0c0a879c */
if(!s->budget--) { s->failed_pc=0x0c0a879cu; return 0; }
r[5]=read(ram,0x0c0a87f0u,4);
goto P_0c0a879e;
P_0c0a879e: /* original 5674, guest PC 0x0c0a879e */
if(!s->budget--) { s->failed_pc=0x0c0a879eu; return 0; }
r[6]=read(ram,r[7]+16,4);
goto P_0c0a87a0;
P_0c0a87a0: /* original 2658, guest PC 0x0c0a87a0 */
if(!s->budget--) { s->failed_pc=0x0c0a87a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c0a87a2;
P_0c0a87a2: /* original 8b00, guest PC 0x0c0a87a2 */
if(!s->budget--) { s->failed_pc=0x0c0a87a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a87a6; }
goto P_0c0a87a4;
P_0c0a87a4: /* original e402, guest PC 0x0c0a87a4 */
if(!s->budget--) { s->failed_pc=0x0c0a87a4u; return 0; }
r[4]=0x00000002u;
goto P_0c0a87a6;
P_0c0a87a6: /* original 000b, guest PC 0x0c0a87a6 */
if(!s->budget--) { s->failed_pc=0x0c0a87a6u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0a87a8: /* original 6043, guest PC 0x0c0a87a8 */
if(!s->budget--) { s->failed_pc=0x0c0a87a8u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c0a87aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a87aau; return 0; } return 1;
P_0c0a87fc: /* original 2fe6, guest PC 0x0c0a87fc */
if(!s->budget--) { s->failed_pc=0x0c0a87fcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a87fe;
P_0c0a87fe: /* original e050, guest PC 0x0c0a87fe */
if(!s->budget--) { s->failed_pc=0x0c0a87feu; return 0; }
r[0]=0x00000050u;
goto P_0c0a8800;
P_0c0a8800: /* original 2fd6, guest PC 0x0c0a8800 */
if(!s->budget--) { s->failed_pc=0x0c0a8800u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8802;
P_0c0a8802: /* original 2fc6, guest PC 0x0c0a8802 */
if(!s->budget--) { s->failed_pc=0x0c0a8802u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8804;
P_0c0a8804: /* original 2fb6, guest PC 0x0c0a8804 */
if(!s->budget--) { s->failed_pc=0x0c0a8804u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8806;
P_0c0a8806: /* original 2fa6, guest PC 0x0c0a8806 */
if(!s->budget--) { s->failed_pc=0x0c0a8806u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8808;
P_0c0a8808: /* original 4f22, guest PC 0x0c0a8808 */
if(!s->budget--) { s->failed_pc=0x0c0a8808u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a880a;
P_0c0a880a: /* original 4f12, guest PC 0x0c0a880a */
if(!s->budget--) { s->failed_pc=0x0c0a880au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a880c;
P_0c0a880c: /* original 7ff8, guest PC 0x0c0a880c */
if(!s->budget--) { s->failed_pc=0x0c0a880cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a880e;
P_0c0a880e: /* original 1f41, guest PC 0x0c0a880e */
if(!s->budget--) { s->failed_pc=0x0c0a880eu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a8810;
P_0c0a8810: /* original 2f52, guest PC 0x0c0a8810 */
if(!s->budget--) { s->failed_pc=0x0c0a8810u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a8812;
P_0c0a8812: /* original d538, guest PC 0x0c0a8812 */
if(!s->budget--) { s->failed_pc=0x0c0a8812u; return 0; }
r[5]=read(ram,0x0c0a88f4u,4);
goto P_0c0a8814;
P_0c0a8814: /* original 9a67, guest PC 0x0c0a8814 */
if(!s->budget--) { s->failed_pc=0x0c0a8814u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88e6u,2);
goto P_0c0a8816;
P_0c0a8816: /* original 045e, guest PC 0x0c0a8816 */
if(!s->budget--) { s->failed_pc=0x0c0a8816u; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c0a8818;
P_0c0a8818: /* original 5e44, guest PC 0x0c0a8818 */
if(!s->budget--) { s->failed_pc=0x0c0a8818u; return 0; }
r[14]=read(ram,r[4]+16,4);
goto P_0c0a881a;
P_0c0a881a: /* original 7eff, guest PC 0x0c0a881a */
if(!s->budget--) { s->failed_pc=0x0c0a881au; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a881c;
P_0c0a881c: /* original 4e11, guest PC 0x0c0a881c */
if(!s->budget--) { s->failed_pc=0x0c0a881cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a881e;
P_0c0a881e: /* original 8900, guest PC 0x0c0a881e */
if(!s->budget--) { s->failed_pc=0x0c0a881eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8822; }
goto P_0c0a8820;
P_0c0a8820: /* original 6ea3, guest PC 0x0c0a8820 */
if(!s->budget--) { s->failed_pc=0x0c0a8820u; return 0; }
r[14]=r[10];
goto P_0c0a8822;
P_0c0a8822: /* original 9061, guest PC 0x0c0a8822 */
if(!s->budget--) { s->failed_pc=0x0c0a8822u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88e8u,2);
goto P_0c0a8824;
P_0c0a8824: /* original dd34, guest PC 0x0c0a8824 */
if(!s->budget--) { s->failed_pc=0x0c0a8824u; return 0; }
r[13]=read(ram,0x0c0a88f8u,4);
goto P_0c0a8826;
P_0c0a8826: /* original 0de6, guest PC 0x0c0a8826 */
if(!s->budget--) { s->failed_pc=0x0c0a8826u; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c0a8828;
P_0c0a8828: /* original 905f, guest PC 0x0c0a8828 */
if(!s->budget--) { s->failed_pc=0x0c0a8828u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88eau,2);
goto P_0c0a882a;
P_0c0a882a: /* original 5554, guest PC 0x0c0a882a */
if(!s->budget--) { s->failed_pc=0x0c0a882au; return 0; }
r[5]=read(ram,r[5]+16,4);
goto P_0c0a882c;
P_0c0a882c: /* original 04de, guest PC 0x0c0a882c */
if(!s->budget--) { s->failed_pc=0x0c0a882cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0a882e;
P_0c0a882e: /* original 3450, guest PC 0x0c0a882e */
if(!s->budget--) { s->failed_pc=0x0c0a882eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0a8830;
P_0c0a8830: /* original 8d01, guest PC 0x0c0a8830 */
if(!s->budget--) { s->failed_pc=0x0c0a8830u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c0a8836; }
goto P_0c0a8834;
P_0c0a8832: /* original e600, guest PC 0x0c0a8832 */
if(!s->budget--) { s->failed_pc=0x0c0a8832u; return 0; }
r[6]=0x00000000u;
goto P_0c0a8834;
P_0c0a8834: /* original e601, guest PC 0x0c0a8834 */
if(!s->budget--) { s->failed_pc=0x0c0a8834u; return 0; }
r[6]=0x00000001u;
goto P_0c0a8836;
P_0c0a8836: /* original e700, guest PC 0x0c0a8836 */
if(!s->budget--) { s->failed_pc=0x0c0a8836u; return 0; }
r[7]=0x00000000u;
goto P_0c0a8838;
P_0c0a8838: /* original 65e3, guest PC 0x0c0a8838 */
if(!s->budget--) { s->failed_pc=0x0c0a8838u; return 0; }
r[5]=r[14];
goto P_0c0a883a;
P_0c0a883a: /* original bf37, guest PC 0x0c0a883a */
if(!s->budget--) { s->failed_pc=0x0c0a883au; return 0; }
target=code_base|0x0c0a86acu; r[16]=code_base|0x0c0a883eu;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a883eu) { target=s->pc; goto dispatch; }
goto P_0c0a883e;
P_0c0a883c: /* original 6473, guest PC 0x0c0a883c */
if(!s->budget--) { s->failed_pc=0x0c0a883cu; return 0; }
r[4]=r[7];
goto P_0c0a883e;
P_0c0a883e: /* original 6403, guest PC 0x0c0a883e */
if(!s->budget--) { s->failed_pc=0x0c0a883eu; return 0; }
r[4]=r[0];
goto P_0c0a8840;
P_0c0a8840: /* original 7eff, guest PC 0x0c0a8840 */
if(!s->budget--) { s->failed_pc=0x0c0a8840u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a8842;
P_0c0a8842: /* original 4e11, guest PC 0x0c0a8842 */
if(!s->budget--) { s->failed_pc=0x0c0a8842u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a8844;
P_0c0a8844: /* original 8900, guest PC 0x0c0a8844 */
if(!s->budget--) { s->failed_pc=0x0c0a8844u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8848; }
goto P_0c0a8846;
P_0c0a8846: /* original 6ea3, guest PC 0x0c0a8846 */
if(!s->budget--) { s->failed_pc=0x0c0a8846u; return 0; }
r[14]=r[10];
goto P_0c0a8848;
P_0c0a8848: /* original 4410, guest PC 0x0c0a8848 */
if(!s->budget--) { s->failed_pc=0x0c0a8848u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0a884a;
P_0c0a884a: /* original 8bf9, guest PC 0x0c0a884a */
if(!s->budget--) { s->failed_pc=0x0c0a884au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8840; }
goto P_0c0a884c;
P_0c0a884c: /* original 904e, guest PC 0x0c0a884c */
if(!s->budget--) { s->failed_pc=0x0c0a884cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88ecu,2);
goto P_0c0a884e;
P_0c0a884e: /* original e160, guest PC 0x0c0a884e */
if(!s->budget--) { s->failed_pc=0x0c0a884eu; return 0; }
r[1]=0x00000060u;
goto P_0c0a8850;
P_0c0a8850: /* original 0de6, guest PC 0x0c0a8850 */
if(!s->budget--) { s->failed_pc=0x0c0a8850u; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c0a8852;
P_0c0a8852: /* original e02b, guest PC 0x0c0a8852 */
if(!s->budget--) { s->failed_pc=0x0c0a8852u; return 0; }
r[0]=0x0000002bu;
goto P_0c0a8854;
P_0c0a8854: /* original 04dc, guest PC 0x0c0a8854 */
if(!s->budget--) { s->failed_pc=0x0c0a8854u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a8856;
P_0c0a8856: /* original d329, guest PC 0x0c0a8856 */
if(!s->budget--) { s->failed_pc=0x0c0a8856u; return 0; }
r[3]=read(ram,0x0c0a88fcu,4);
goto P_0c0a8858;
P_0c0a8858: /* original 50f1, guest PC 0x0c0a8858 */
if(!s->budget--) { s->failed_pc=0x0c0a8858u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a885a;
P_0c0a885a: /* original 74ff, guest PC 0x0c0a885a */
if(!s->budget--) { s->failed_pc=0x0c0a885au; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a885c;
P_0c0a885c: /* original 6643, guest PC 0x0c0a885c */
if(!s->budget--) { s->failed_pc=0x0c0a885cu; return 0; }
r[6]=r[4];
goto P_0c0a885e;
P_0c0a885e: /* original 6730, guest PC 0x0c0a885e */
if(!s->budget--) { s->failed_pc=0x0c0a885eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[7]=tmp;
goto P_0c0a8860;
P_0c0a8860: /* original 6343, guest PC 0x0c0a8860 */
if(!s->budget--) { s->failed_pc=0x0c0a8860u; return 0; }
r[3]=r[4];
goto P_0c0a8862;
P_0c0a8862: /* original 4600, guest PC 0x0c0a8862 */
if(!s->budget--) { s->failed_pc=0x0c0a8862u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0a8864;
P_0c0a8864: /* original 001c, guest PC 0x0c0a8864 */
if(!s->budget--) { s->failed_pc=0x0c0a8864u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0a8866;
P_0c0a8866: /* original 363c, guest PC 0x0c0a8866 */
if(!s->budget--) { s->failed_pc=0x0c0a8866u; return 0; }
r[6]+=r[3];
goto P_0c0a8868;
P_0c0a8868: /* original 9541, guest PC 0x0c0a8868 */
if(!s->budget--) { s->failed_pc=0x0c0a8868u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88eeu,2);
goto P_0c0a886a;
P_0c0a886a: /* original 644e, guest PC 0x0c0a886a */
if(!s->budget--) { s->failed_pc=0x0c0a886au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a886c;
P_0c0a886c: /* original 80f4, guest PC 0x0c0a886c */
if(!s->budget--) { s->failed_pc=0x0c0a886cu; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c0a886e;
P_0c0a886e: /* original 6013, guest PC 0x0c0a886e */
if(!s->budget--) { s->failed_pc=0x0c0a886eu; return 0; }
r[0]=r[1];
goto P_0c0a8870;
P_0c0a8870: /* original 62f2, guest PC 0x0c0a8870 */
if(!s->budget--) { s->failed_pc=0x0c0a8870u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a8872;
P_0c0a8872: /* original 35dc, guest PC 0x0c0a8872 */
if(!s->budget--) { s->failed_pc=0x0c0a8872u; return 0; }
r[5]+=r[13];
goto P_0c0a8874;
P_0c0a8874: /* original 666e, guest PC 0x0c0a8874 */
if(!s->budget--) { s->failed_pc=0x0c0a8874u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c0a8876;
P_0c0a8876: /* original 022c, guest PC 0x0c0a8876 */
if(!s->budget--) { s->failed_pc=0x0c0a8876u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0a8878;
P_0c0a8878: /* original 356c, guest PC 0x0c0a8878 */
if(!s->budget--) { s->failed_pc=0x0c0a8878u; return 0; }
r[5]+=r[6];
goto P_0c0a887a;
P_0c0a887a: /* original 2f20, guest PC 0x0c0a887a */
if(!s->budget--) { s->failed_pc=0x0c0a887au; return 0; }
write(ram,r[15],r[2],1);
goto P_0c0a887c;
P_0c0a887c: /* original 2570, guest PC 0x0c0a887c */
if(!s->budget--) { s->failed_pc=0x0c0a887cu; return 0; }
write(ram,r[5],r[7],1);
goto P_0c0a887e;
P_0c0a887e: /* original 84f4, guest PC 0x0c0a887e */
if(!s->budget--) { s->failed_pc=0x0c0a887eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0a8880;
P_0c0a8880: /* original 8051, guest PC 0x0c0a8880 */
if(!s->budget--) { s->failed_pc=0x0c0a8880u; return 0; }
write(ram,r[5]+1,r[0],1);
goto P_0c0a8882;
P_0c0a8882: /* original 60f0, guest PC 0x0c0a8882 */
if(!s->budget--) { s->failed_pc=0x0c0a8882u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[0]=tmp;
goto P_0c0a8884;
P_0c0a8884: /* original 8052, guest PC 0x0c0a8884 */
if(!s->budget--) { s->failed_pc=0x0c0a8884u; return 0; }
write(ram,r[5]+2,r[0],1);
goto P_0c0a8886;
P_0c0a8886: /* original 9333, guest PC 0x0c0a8886 */
if(!s->budget--) { s->failed_pc=0x0c0a8886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88f0u,2);
goto P_0c0a8888;
P_0c0a8888: /* original 243f, guest PC 0x0c0a8888 */
if(!s->budget--) { s->failed_pc=0x0c0a8888u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0a888a;
P_0c0a888a: /* original 041a, guest PC 0x0c0a888a */
if(!s->budget--) { s->failed_pc=0x0c0a888au; return 0; }
r[4]=r[19];
goto P_0c0a888c;
P_0c0a888c: /* original 902e, guest PC 0x0c0a888c */
if(!s->budget--) { s->failed_pc=0x0c0a888cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88ecu,2);
goto P_0c0a888e;
P_0c0a888e: /* original de1c, guest PC 0x0c0a888e */
if(!s->budget--) { s->failed_pc=0x0c0a888eu; return 0; }
r[14]=read(ram,0x0c0a8900u,4);
goto P_0c0a8890;
P_0c0a8890: /* original 0cde, guest PC 0x0c0a8890 */
if(!s->budget--) { s->failed_pc=0x0c0a8890u; return 0; }
r[12]=read(ram,r[13]+r[0],4);
goto P_0c0a8892;
P_0c0a8892: /* original 3e4c, guest PC 0x0c0a8892 */
if(!s->budget--) { s->failed_pc=0x0c0a8892u; return 0; }
r[14]+=r[4];
goto P_0c0a8894;
P_0c0a8894: /* original 64c3, guest PC 0x0c0a8894 */
if(!s->budget--) { s->failed_pc=0x0c0a8894u; return 0; }
r[4]=r[12];
goto P_0c0a8896;
P_0c0a8896: /* original 4408, guest PC 0x0c0a8896 */
if(!s->budget--) { s->failed_pc=0x0c0a8896u; return 0; }
r[4]<<=2;
goto P_0c0a8898;
P_0c0a8898: /* original 4408, guest PC 0x0c0a8898 */
if(!s->budget--) { s->failed_pc=0x0c0a8898u; return 0; }
r[4]<<=2;
goto P_0c0a889a;
P_0c0a889a: /* original db1a, guest PC 0x0c0a889a */
if(!s->budget--) { s->failed_pc=0x0c0a889au; return 0; }
r[11]=read(ram,0x0c0a8904u,4);
goto P_0c0a889c;
P_0c0a889c: /* original 4408, guest PC 0x0c0a889c */
if(!s->budget--) { s->failed_pc=0x0c0a889cu; return 0; }
r[4]<<=2;
goto P_0c0a889e;
P_0c0a889e: /* original 65e3, guest PC 0x0c0a889e */
if(!s->budget--) { s->failed_pc=0x0c0a889eu; return 0; }
r[5]=r[14];
goto P_0c0a88a0;
P_0c0a88a0: /* original 4400, guest PC 0x0c0a88a0 */
if(!s->budget--) { s->failed_pc=0x0c0a88a0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a88a2;
P_0c0a88a2: /* original 3b4c, guest PC 0x0c0a88a2 */
if(!s->budget--) { s->failed_pc=0x0c0a88a2u; return 0; }
r[11]+=r[4];
goto P_0c0a88a4;
P_0c0a88a4: /* original b055, guest PC 0x0c0a88a4 */
if(!s->budget--) { s->failed_pc=0x0c0a88a4u; return 0; }
target=code_base|0x0c0a8952u; r[16]=code_base|0x0c0a88a8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a88a8u) { target=s->pc; goto dispatch; }
goto P_0c0a88a8;
P_0c0a88a6: /* original 64b3, guest PC 0x0c0a88a6 */
if(!s->budget--) { s->failed_pc=0x0c0a88a6u; return 0; }
r[4]=r[11];
goto P_0c0a88a8;
P_0c0a88a8: /* original 7e20, guest PC 0x0c0a88a8 */
if(!s->budget--) { s->failed_pc=0x0c0a88a8u; return 0; }
r[14]+=0x00000020u;
goto P_0c0a88aa;
P_0c0a88aa: /* original 65e3, guest PC 0x0c0a88aa */
if(!s->budget--) { s->failed_pc=0x0c0a88aau; return 0; }
r[5]=r[14];
goto P_0c0a88ac;
P_0c0a88ac: /* original 7b40, guest PC 0x0c0a88ac */
if(!s->budget--) { s->failed_pc=0x0c0a88acu; return 0; }
r[11]+=0x00000040u;
goto P_0c0a88ae;
P_0c0a88ae: /* original b050, guest PC 0x0c0a88ae */
if(!s->budget--) { s->failed_pc=0x0c0a88aeu; return 0; }
target=code_base|0x0c0a8952u; r[16]=code_base|0x0c0a88b2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a88b2u) { target=s->pc; goto dispatch; }
goto P_0c0a88b2;
P_0c0a88b0: /* original 64b3, guest PC 0x0c0a88b0 */
if(!s->budget--) { s->failed_pc=0x0c0a88b0u; return 0; }
r[4]=r[11];
goto P_0c0a88b2;
P_0c0a88b2: /* original 7c01, guest PC 0x0c0a88b2 */
if(!s->budget--) { s->failed_pc=0x0c0a88b2u; return 0; }
r[12]+=0x00000001u;
goto P_0c0a88b4;
P_0c0a88b4: /* original 3ca6, guest PC 0x0c0a88b4 */
if(!s->budget--) { s->failed_pc=0x0c0a88b4u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>r[10])!=0);
goto P_0c0a88b6;
P_0c0a88b6: /* original 8f01, guest PC 0x0c0a88b6 */
if(!s->budget--) { s->failed_pc=0x0c0a88b6u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000020u;
if(!cond) { goto P_0c0a88bc; }
goto P_0c0a88ba;
P_0c0a88b8: /* original 7e20, guest PC 0x0c0a88b8 */
if(!s->budget--) { s->failed_pc=0x0c0a88b8u; return 0; }
r[14]+=0x00000020u;
goto P_0c0a88ba;
P_0c0a88ba: /* original ec00, guest PC 0x0c0a88ba */
if(!s->budget--) { s->failed_pc=0x0c0a88bau; return 0; }
r[12]=0x00000000u;
goto P_0c0a88bc;
P_0c0a88bc: /* original 9014, guest PC 0x0c0a88bc */
if(!s->budget--) { s->failed_pc=0x0c0a88bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88e8u,2);
goto P_0c0a88be;
P_0c0a88be: /* original 04de, guest PC 0x0c0a88be */
if(!s->budget--) { s->failed_pc=0x0c0a88beu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0a88c0;
P_0c0a88c0: /* original 7004, guest PC 0x0c0a88c0 */
if(!s->budget--) { s->failed_pc=0x0c0a88c0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a88c2;
P_0c0a88c2: /* original 03dc, guest PC 0x0c0a88c2 */
if(!s->budget--) { s->failed_pc=0x0c0a88c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a88c4;
P_0c0a88c4: /* original 7301, guest PC 0x0c0a88c4 */
if(!s->budget--) { s->failed_pc=0x0c0a88c4u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a88c6;
P_0c0a88c6: /* original 0d34, guest PC 0x0c0a88c6 */
if(!s->budget--) { s->failed_pc=0x0c0a88c6u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0a88c8;
P_0c0a88c8: /* original 9313, guest PC 0x0c0a88c8 */
if(!s->budget--) { s->failed_pc=0x0c0a88c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a88f2u,2);
goto P_0c0a88ca;
P_0c0a88ca: /* original 02dc, guest PC 0x0c0a88ca */
if(!s->budget--) { s->failed_pc=0x0c0a88cau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a88cc;
P_0c0a88cc: /* original 3233, guest PC 0x0c0a88cc */
if(!s->budget--) { s->failed_pc=0x0c0a88ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0a88ce;
P_0c0a88ce: /* original 8901, guest PC 0x0c0a88ce */
if(!s->budget--) { s->failed_pc=0x0c0a88ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a88d4; }
goto P_0c0a88d0;
P_0c0a88d0: /* original 34c0, guest PC 0x0c0a88d0 */
if(!s->budget--) { s->failed_pc=0x0c0a88d0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[12])!=0);
goto P_0c0a88d2;
P_0c0a88d2: /* original 8bdf, guest PC 0x0c0a88d2 */
if(!s->budget--) { s->failed_pc=0x0c0a88d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8894; }
goto P_0c0a88d4;
P_0c0a88d4: /* original 7f08, guest PC 0x0c0a88d4 */
if(!s->budget--) { s->failed_pc=0x0c0a88d4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a88d6;
P_0c0a88d6: /* original 4f16, guest PC 0x0c0a88d6 */
if(!s->budget--) { s->failed_pc=0x0c0a88d6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a88d8;
P_0c0a88d8: /* original 4f26, guest PC 0x0c0a88d8 */
if(!s->budget--) { s->failed_pc=0x0c0a88d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a88da;
P_0c0a88da: /* original 6af6, guest PC 0x0c0a88da */
if(!s->budget--) { s->failed_pc=0x0c0a88dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a88dc;
P_0c0a88dc: /* original 6bf6, guest PC 0x0c0a88dc */
if(!s->budget--) { s->failed_pc=0x0c0a88dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a88de;
P_0c0a88de: /* original 6cf6, guest PC 0x0c0a88de */
if(!s->budget--) { s->failed_pc=0x0c0a88deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a88e0;
P_0c0a88e0: /* original 6df6, guest PC 0x0c0a88e0 */
if(!s->budget--) { s->failed_pc=0x0c0a88e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a88e2;
P_0c0a88e2: /* original 000b, guest PC 0x0c0a88e2 */
if(!s->budget--) { s->failed_pc=0x0c0a88e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a88e4: /* original 6ef6, guest PC 0x0c0a88e4 */
if(!s->budget--) { s->failed_pc=0x0c0a88e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a88e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a88e6u; return 0; } return 1;
P_0c0a8908: /* original d328, guest PC 0x0c0a8908 */
if(!s->budget--) { s->failed_pc=0x0c0a8908u; return 0; }
r[3]=read(ram,0x0c0a89acu,4);
goto P_0c0a890a;
P_0c0a890a: /* original 924c, guest PC 0x0c0a890a */
if(!s->budget--) { s->failed_pc=0x0c0a890au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a89a6u,2);
goto P_0c0a890c;
P_0c0a890c: /* original 6430, guest PC 0x0c0a890c */
if(!s->budget--) { s->failed_pc=0x0c0a890cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[4]=tmp;
goto P_0c0a890e;
P_0c0a890e: /* original 4f12, guest PC 0x0c0a890e */
if(!s->budget--) { s->failed_pc=0x0c0a890eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8910;
P_0c0a8910: /* original 74ff, guest PC 0x0c0a8910 */
if(!s->budget--) { s->failed_pc=0x0c0a8910u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a8912;
P_0c0a8912: /* original d527, guest PC 0x0c0a8912 */
if(!s->budget--) { s->failed_pc=0x0c0a8912u; return 0; }
r[5]=read(ram,0x0c0a89b0u,4);
goto P_0c0a8914;
P_0c0a8914: /* original 644e, guest PC 0x0c0a8914 */
if(!s->budget--) { s->failed_pc=0x0c0a8914u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a8916;
P_0c0a8916: /* original 9747, guest PC 0x0c0a8916 */
if(!s->budget--) { s->failed_pc=0x0c0a8916u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a89a8u,2);
goto P_0c0a8918;
P_0c0a8918: /* original 242f, guest PC 0x0c0a8918 */
if(!s->budget--) { s->failed_pc=0x0c0a8918u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[2]);
goto P_0c0a891a;
P_0c0a891a: /* original 041a, guest PC 0x0c0a891a */
if(!s->budget--) { s->failed_pc=0x0c0a891au; return 0; }
r[4]=r[19];
goto P_0c0a891c;
P_0c0a891c: /* original 4408, guest PC 0x0c0a891c */
if(!s->budget--) { s->failed_pc=0x0c0a891cu; return 0; }
r[4]<<=2;
goto P_0c0a891e;
P_0c0a891e: /* original 4408, guest PC 0x0c0a891e */
if(!s->budget--) { s->failed_pc=0x0c0a891eu; return 0; }
r[4]<<=2;
goto P_0c0a8920;
P_0c0a8920: /* original 4408, guest PC 0x0c0a8920 */
if(!s->budget--) { s->failed_pc=0x0c0a8920u; return 0; }
r[4]<<=2;
goto P_0c0a8922;
P_0c0a8922: /* original 354c, guest PC 0x0c0a8922 */
if(!s->budget--) { s->failed_pc=0x0c0a8922u; return 0; }
r[5]+=r[4];
goto P_0c0a8924;
P_0c0a8924: /* original e400, guest PC 0x0c0a8924 */
if(!s->budget--) { s->failed_pc=0x0c0a8924u; return 0; }
r[4]=0x00000000u;
goto P_0c0a8926;
P_0c0a8926: /* original 6643, guest PC 0x0c0a8926 */
if(!s->budget--) { s->failed_pc=0x0c0a8926u; return 0; }
r[6]=r[4];
goto P_0c0a8928;
P_0c0a8928: /* original 2542, guest PC 0x0c0a8928 */
if(!s->budget--) { s->failed_pc=0x0c0a8928u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a892a;
P_0c0a892a: /* original 7504, guest PC 0x0c0a892a */
if(!s->budget--) { s->failed_pc=0x0c0a892au; return 0; }
r[5]+=0x00000004u;
goto P_0c0a892c;
P_0c0a892c: /* original 2542, guest PC 0x0c0a892c */
if(!s->budget--) { s->failed_pc=0x0c0a892cu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a892e;
P_0c0a892e: /* original 7504, guest PC 0x0c0a892e */
if(!s->budget--) { s->failed_pc=0x0c0a892eu; return 0; }
r[5]+=0x00000004u;
goto P_0c0a8930;
P_0c0a8930: /* original 2542, guest PC 0x0c0a8930 */
if(!s->budget--) { s->failed_pc=0x0c0a8930u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a8932;
P_0c0a8932: /* original 7504, guest PC 0x0c0a8932 */
if(!s->budget--) { s->failed_pc=0x0c0a8932u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a8934;
P_0c0a8934: /* original 2542, guest PC 0x0c0a8934 */
if(!s->budget--) { s->failed_pc=0x0c0a8934u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a8936;
P_0c0a8936: /* original 7504, guest PC 0x0c0a8936 */
if(!s->budget--) { s->failed_pc=0x0c0a8936u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a8938;
P_0c0a8938: /* original 2542, guest PC 0x0c0a8938 */
if(!s->budget--) { s->failed_pc=0x0c0a8938u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a893a;
P_0c0a893a: /* original 7504, guest PC 0x0c0a893a */
if(!s->budget--) { s->failed_pc=0x0c0a893au; return 0; }
r[5]+=0x00000004u;
goto P_0c0a893c;
P_0c0a893c: /* original 2542, guest PC 0x0c0a893c */
if(!s->budget--) { s->failed_pc=0x0c0a893cu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a893e;
P_0c0a893e: /* original 7504, guest PC 0x0c0a893e */
if(!s->budget--) { s->failed_pc=0x0c0a893eu; return 0; }
r[5]+=0x00000004u;
goto P_0c0a8940;
P_0c0a8940: /* original 2542, guest PC 0x0c0a8940 */
if(!s->budget--) { s->failed_pc=0x0c0a8940u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a8942;
P_0c0a8942: /* original 7601, guest PC 0x0c0a8942 */
if(!s->budget--) { s->failed_pc=0x0c0a8942u; return 0; }
r[6]+=0x00000001u;
goto P_0c0a8944;
P_0c0a8944: /* original 7504, guest PC 0x0c0a8944 */
if(!s->budget--) { s->failed_pc=0x0c0a8944u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a8946;
P_0c0a8946: /* original 3673, guest PC 0x0c0a8946 */
if(!s->budget--) { s->failed_pc=0x0c0a8946u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c0a8948;
P_0c0a8948: /* original 2542, guest PC 0x0c0a8948 */
if(!s->budget--) { s->failed_pc=0x0c0a8948u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a894a;
P_0c0a894a: /* original 8fed, guest PC 0x0c0a894a */
if(!s->budget--) { s->failed_pc=0x0c0a894au; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c0a8928; }
goto P_0c0a894e;
P_0c0a894c: /* original 7504, guest PC 0x0c0a894c */
if(!s->budget--) { s->failed_pc=0x0c0a894cu; return 0; }
r[5]+=0x00000004u;
goto P_0c0a894e;
P_0c0a894e: /* original 000b, guest PC 0x0c0a894e */
if(!s->budget--) { s->failed_pc=0x0c0a894eu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0a8950: /* original 4f16, guest PC 0x0c0a8950 */
if(!s->budget--) { s->failed_pc=0x0c0a8950u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8952;
P_0c0a8952: /* original e004, guest PC 0x0c0a8952 */
if(!s->budget--) { s->failed_pc=0x0c0a8952u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8954;
P_0c0a8954: /* original 5744, guest PC 0x0c0a8954 */
if(!s->budget--) { s->failed_pc=0x0c0a8954u; return 0; }
r[7]=read(ram,r[4]+16,4);
goto P_0c0a8956;
P_0c0a8956: /* original f446, guest PC 0x0c0a8956 */
if(!s->budget--) { s->failed_pc=0x0c0a8956u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0a8958;
P_0c0a8958: /* original e008, guest PC 0x0c0a8958 */
if(!s->budget--) { s->failed_pc=0x0c0a8958u; return 0; }
r[0]=0x00000008u;
goto P_0c0a895a;
P_0c0a895a: /* original f646, guest PC 0x0c0a895a */
if(!s->budget--) { s->failed_pc=0x0c0a895au; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0a895c;
P_0c0a895c: /* original e00c, guest PC 0x0c0a895c */
if(!s->budget--) { s->failed_pc=0x0c0a895cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a895e;
P_0c0a895e: /* original f546, guest PC 0x0c0a895e */
if(!s->budget--) { s->failed_pc=0x0c0a895eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0a8960;
P_0c0a8960: /* original e020, guest PC 0x0c0a8960 */
if(!s->budget--) { s->failed_pc=0x0c0a8960u; return 0; }
r[0]=0x00000020u;
goto P_0c0a8962;
P_0c0a8962: /* original 004d, guest PC 0x0c0a8962 */
if(!s->budget--) { s->failed_pc=0x0c0a8962u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a8964;
P_0c0a8964: /* original 7ff0, guest PC 0x0c0a8964 */
if(!s->budget--) { s->failed_pc=0x0c0a8964u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8966;
P_0c0a8966: /* original 6642, guest PC 0x0c0a8966 */
if(!s->budget--) { s->failed_pc=0x0c0a8966u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c0a8968;
P_0c0a8968: /* original 81f6, guest PC 0x0c0a8968 */
if(!s->budget--) { s->failed_pc=0x0c0a8968u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0a896a;
P_0c0a896a: /* original e022, guest PC 0x0c0a896a */
if(!s->budget--) { s->failed_pc=0x0c0a896au; return 0; }
r[0]=0x00000022u;
goto P_0c0a896c;
P_0c0a896c: /* original 004d, guest PC 0x0c0a896c */
if(!s->budget--) { s->failed_pc=0x0c0a896cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a896e;
P_0c0a896e: /* original 81f4, guest PC 0x0c0a896e */
if(!s->budget--) { s->failed_pc=0x0c0a896eu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0a8970;
P_0c0a8970: /* original e024, guest PC 0x0c0a8970 */
if(!s->budget--) { s->failed_pc=0x0c0a8970u; return 0; }
r[0]=0x00000024u;
goto P_0c0a8972;
P_0c0a8972: /* original 004d, guest PC 0x0c0a8972 */
if(!s->budget--) { s->failed_pc=0x0c0a8972u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a8974;
P_0c0a8974: /* original 81f2, guest PC 0x0c0a8974 */
if(!s->budget--) { s->failed_pc=0x0c0a8974u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0a8976;
P_0c0a8976: /* original e03b, guest PC 0x0c0a8976 */
if(!s->budget--) { s->failed_pc=0x0c0a8976u; return 0; }
r[0]=0x0000003bu;
goto P_0c0a8978;
P_0c0a8978: /* original 034c, guest PC 0x0c0a8978 */
if(!s->budget--) { s->failed_pc=0x0c0a8978u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a897a;
P_0c0a897a: /* original e004, guest PC 0x0c0a897a */
if(!s->budget--) { s->failed_pc=0x0c0a897au; return 0; }
r[0]=0x00000004u;
goto P_0c0a897c;
P_0c0a897c: /* original 2f30, guest PC 0x0c0a897c */
if(!s->budget--) { s->failed_pc=0x0c0a897cu; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0a897e;
P_0c0a897e: /* original 544b, guest PC 0x0c0a897e */
if(!s->budget--) { s->failed_pc=0x0c0a897eu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0a8980;
P_0c0a8980: /* original f547, guest PC 0x0c0a8980 */
if(!s->budget--) { s->failed_pc=0x0c0a8980u; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c0a8982;
P_0c0a8982: /* original e008, guest PC 0x0c0a8982 */
if(!s->budget--) { s->failed_pc=0x0c0a8982u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8984;
P_0c0a8984: /* original f567, guest PC 0x0c0a8984 */
if(!s->budget--) { s->failed_pc=0x0c0a8984u; return 0; }
vf3_matrix_store(s,ram,6,r[5]+r[0]);
goto P_0c0a8986;
P_0c0a8986: /* original e00c, guest PC 0x0c0a8986 */
if(!s->budget--) { s->failed_pc=0x0c0a8986u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8988;
P_0c0a8988: /* original f557, guest PC 0x0c0a8988 */
if(!s->budget--) { s->failed_pc=0x0c0a8988u; return 0; }
vf3_matrix_store(s,ram,5,r[5]+r[0]);
goto P_0c0a898a;
P_0c0a898a: /* original 2562, guest PC 0x0c0a898a */
if(!s->budget--) { s->failed_pc=0x0c0a898au; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0a898c;
P_0c0a898c: /* original 1574, guest PC 0x0c0a898c */
if(!s->budget--) { s->failed_pc=0x0c0a898cu; return 0; }
write(ram,r[5]+16,r[7],4);
goto P_0c0a898e;
P_0c0a898e: /* original 85f6, guest PC 0x0c0a898e */
if(!s->budget--) { s->failed_pc=0x0c0a898eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c0a8990;
P_0c0a8990: /* original 815a, guest PC 0x0c0a8990 */
if(!s->budget--) { s->failed_pc=0x0c0a8990u; return 0; }
write(ram,r[5]+20,r[0],2);
goto P_0c0a8992;
P_0c0a8992: /* original 85f4, guest PC 0x0c0a8992 */
if(!s->budget--) { s->failed_pc=0x0c0a8992u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0a8994;
P_0c0a8994: /* original 815b, guest PC 0x0c0a8994 */
if(!s->budget--) { s->failed_pc=0x0c0a8994u; return 0; }
write(ram,r[5]+22,r[0],2);
goto P_0c0a8996;
P_0c0a8996: /* original 85f2, guest PC 0x0c0a8996 */
if(!s->budget--) { s->failed_pc=0x0c0a8996u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0a8998;
P_0c0a8998: /* original 815c, guest PC 0x0c0a8998 */
if(!s->budget--) { s->failed_pc=0x0c0a8998u; return 0; }
write(ram,r[5]+24,r[0],2);
goto P_0c0a899a;
P_0c0a899a: /* original e01a, guest PC 0x0c0a899a */
if(!s->budget--) { s->failed_pc=0x0c0a899au; return 0; }
r[0]=0x0000001au;
goto P_0c0a899c;
P_0c0a899c: /* original 63f0, guest PC 0x0c0a899c */
if(!s->budget--) { s->failed_pc=0x0c0a899cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c0a899e;
P_0c0a899e: /* original 0534, guest PC 0x0c0a899e */
if(!s->budget--) { s->failed_pc=0x0c0a899eu; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c0a89a0;
P_0c0a89a0: /* original 1547, guest PC 0x0c0a89a0 */
if(!s->budget--) { s->failed_pc=0x0c0a89a0u; return 0; }
write(ram,r[5]+28,r[4],4);
goto P_0c0a89a2;
P_0c0a89a2: /* original 000b, guest PC 0x0c0a89a2 */
if(!s->budget--) { s->failed_pc=0x0c0a89a2u; return 0; }
target=r[16];
r[15]+=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c0a89a4: /* original 7f10, guest PC 0x0c0a89a4 */
if(!s->budget--) { s->failed_pc=0x0c0a89a4u; return 0; }
r[15]+=0x00000010u;
if(!vf3_matrix_family(0x0c0a89a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a89a6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
