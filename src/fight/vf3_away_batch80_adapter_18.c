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
int vf3_away_batch80_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a86acu: goto P_0c0a86ac;
case 0x0c0a86aeu: goto P_0c0a86ae;
case 0x0c0a86b0u: goto P_0c0a86b0;
case 0x0c0a86b2u: goto P_0c0a86b2;
case 0x0c0a86b4u: goto P_0c0a86b4;
case 0x0c0a86b6u: goto P_0c0a86b6;
case 0x0c0a86b8u: goto P_0c0a86b8;
case 0x0c0a86bau: goto P_0c0a86ba;
case 0x0c0a86bcu: goto P_0c0a86bc;
case 0x0c0a86beu: goto P_0c0a86be;
case 0x0c0a86c0u: goto P_0c0a86c0;
case 0x0c0a86c2u: goto P_0c0a86c2;
case 0x0c0a86c4u: goto P_0c0a86c4;
case 0x0c0a86c6u: goto P_0c0a86c6;
case 0x0c0a86c8u: goto P_0c0a86c8;
case 0x0c0a86cau: goto P_0c0a86ca;
case 0x0c0a86ccu: goto P_0c0a86cc;
case 0x0c0a86ceu: goto P_0c0a86ce;
case 0x0c0a86d0u: goto P_0c0a86d0;
case 0x0c0a86d2u: goto P_0c0a86d2;
case 0x0c0a86d4u: goto P_0c0a86d4;
case 0x0c0a86d6u: goto P_0c0a86d6;
case 0x0c0a86d8u: goto P_0c0a86d8;
case 0x0c0a86dau: goto P_0c0a86da;
case 0x0c0a86dcu: goto P_0c0a86dc;
case 0x0c0a86deu: goto P_0c0a86de;
case 0x0c0a86e0u: goto P_0c0a86e0;
case 0x0c0a86e2u: goto P_0c0a86e2;
case 0x0c0a86e4u: goto P_0c0a86e4;
case 0x0c0a86e6u: goto P_0c0a86e6;
case 0x0c0a86e8u: goto P_0c0a86e8;
case 0x0c0a86eau: goto P_0c0a86ea;
case 0x0c0a86ecu: goto P_0c0a86ec;
case 0x0c0a86eeu: goto P_0c0a86ee;
case 0x0c0a86f0u: goto P_0c0a86f0;
case 0x0c0a86f2u: goto P_0c0a86f2;
case 0x0c0a86f4u: goto P_0c0a86f4;
case 0x0c0a86f6u: goto P_0c0a86f6;
case 0x0c0a86f8u: goto P_0c0a86f8;
case 0x0c0a86fau: goto P_0c0a86fa;
case 0x0c0a86fcu: goto P_0c0a86fc;
case 0x0c0a86feu: goto P_0c0a86fe;
case 0x0c0a8700u: goto P_0c0a8700;
case 0x0c0a8702u: goto P_0c0a8702;
case 0x0c0a8704u: goto P_0c0a8704;
case 0x0c0a8706u: goto P_0c0a8706;
case 0x0c0a8708u: goto P_0c0a8708;
case 0x0c0a870au: goto P_0c0a870a;
case 0x0c0a870cu: goto P_0c0a870c;
case 0x0c0a870eu: goto P_0c0a870e;
case 0x0c0a8710u: goto P_0c0a8710;
case 0x0c0a8712u: goto P_0c0a8712;
case 0x0c0a8714u: goto P_0c0a8714;
case 0x0c0a8716u: goto P_0c0a8716;
case 0x0c0a8718u: goto P_0c0a8718;
case 0x0c0a871au: goto P_0c0a871a;
case 0x0c0a871cu: goto P_0c0a871c;
case 0x0c0a871eu: goto P_0c0a871e;
case 0x0c0a8720u: goto P_0c0a8720;
case 0x0c0a8722u: goto P_0c0a8722;
case 0x0c0a8724u: goto P_0c0a8724;
case 0x0c0a8726u: goto P_0c0a8726;
case 0x0c0a8728u: goto P_0c0a8728;
case 0x0c0a872au: goto P_0c0a872a;
case 0x0c0a872cu: goto P_0c0a872c;
case 0x0c0a872eu: goto P_0c0a872e;
case 0x0c0a8730u: goto P_0c0a8730;
case 0x0c0a8732u: goto P_0c0a8732;
case 0x0c0a8734u: goto P_0c0a8734;
case 0x0c0a8736u: goto P_0c0a8736;
case 0x0c0a8738u: goto P_0c0a8738;
case 0x0c0a873au: goto P_0c0a873a;
case 0x0c0a873cu: goto P_0c0a873c;
case 0x0c0a873eu: goto P_0c0a873e;
case 0x0c0a8740u: goto P_0c0a8740;
case 0x0c0a8742u: goto P_0c0a8742;
case 0x0c0a8744u: goto P_0c0a8744;
case 0x0c0a8746u: goto P_0c0a8746;
case 0x0c0a8748u: goto P_0c0a8748;
case 0x0c0a874au: goto P_0c0a874a;
case 0x0c0a874cu: goto P_0c0a874c;
case 0x0c0a874eu: goto P_0c0a874e;
case 0x0c0a8750u: goto P_0c0a8750;
case 0x0c0a8752u: goto P_0c0a8752;
case 0x0c0a8754u: goto P_0c0a8754;
case 0x0c0a8756u: goto P_0c0a8756;
case 0x0c0a8758u: goto P_0c0a8758;
case 0x0c0a875au: goto P_0c0a875a;
case 0x0c0a875cu: goto P_0c0a875c;
case 0x0c0a875eu: goto P_0c0a875e;
case 0x0c0a8760u: goto P_0c0a8760;
case 0x0c0a8762u: goto P_0c0a8762;
case 0x0c0a8764u: goto P_0c0a8764;
case 0x0c0a8766u: goto P_0c0a8766;
case 0x0c0a8768u: goto P_0c0a8768;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a86ac: /* original 2fe6, guest PC 0x0c0a86ac */
if(!s->budget--) { s->failed_pc=0x0c0a86acu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86ae;
P_0c0a86ae: /* original 6e53, guest PC 0x0c0a86ae */
if(!s->budget--) { s->failed_pc=0x0c0a86aeu; return 0; }
r[14]=r[5];
goto P_0c0a86b0;
P_0c0a86b0: /* original 2fd6, guest PC 0x0c0a86b0 */
if(!s->budget--) { s->failed_pc=0x0c0a86b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b2;
P_0c0a86b2: /* original 6d73, guest PC 0x0c0a86b2 */
if(!s->budget--) { s->failed_pc=0x0c0a86b2u; return 0; }
r[13]=r[7];
goto P_0c0a86b4;
P_0c0a86b4: /* original 2fc6, guest PC 0x0c0a86b4 */
if(!s->budget--) { s->failed_pc=0x0c0a86b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b6;
P_0c0a86b6: /* original 2fb6, guest PC 0x0c0a86b6 */
if(!s->budget--) { s->failed_pc=0x0c0a86b6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b8;
P_0c0a86b8: /* original 6b43, guest PC 0x0c0a86b8 */
if(!s->budget--) { s->failed_pc=0x0c0a86b8u; return 0; }
r[11]=r[4];
goto P_0c0a86ba;
P_0c0a86ba: /* original 4f22, guest PC 0x0c0a86ba */
if(!s->budget--) { s->failed_pc=0x0c0a86bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a86bc;
P_0c0a86bc: /* original 7ffc, guest PC 0x0c0a86bc */
if(!s->budget--) { s->failed_pc=0x0c0a86bcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a86be;
P_0c0a86be: /* original 2f62, guest PC 0x0c0a86be */
if(!s->budget--) { s->failed_pc=0x0c0a86beu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a86c0;
P_0c0a86c0: /* original 64e3, guest PC 0x0c0a86c0 */
if(!s->budget--) { s->failed_pc=0x0c0a86c0u; return 0; }
r[4]=r[14];
goto P_0c0a86c2;
P_0c0a86c2: /* original 4408, guest PC 0x0c0a86c2 */
if(!s->budget--) { s->failed_pc=0x0c0a86c2u; return 0; }
r[4]<<=2;
goto P_0c0a86c4;
P_0c0a86c4: /* original 4408, guest PC 0x0c0a86c4 */
if(!s->budget--) { s->failed_pc=0x0c0a86c4u; return 0; }
r[4]<<=2;
goto P_0c0a86c6;
P_0c0a86c6: /* original dc31, guest PC 0x0c0a86c6 */
if(!s->budget--) { s->failed_pc=0x0c0a86c6u; return 0; }
r[12]=read(ram,0x0c0a878cu,4);
goto P_0c0a86c8;
P_0c0a86c8: /* original 4408, guest PC 0x0c0a86c8 */
if(!s->budget--) { s->failed_pc=0x0c0a86c8u; return 0; }
r[4]<<=2;
goto P_0c0a86ca;
P_0c0a86ca: /* original 4400, guest PC 0x0c0a86ca */
if(!s->budget--) { s->failed_pc=0x0c0a86cau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a86cc;
P_0c0a86cc: /* original 6643, guest PC 0x0c0a86cc */
if(!s->budget--) { s->failed_pc=0x0c0a86ccu; return 0; }
r[6]=r[4];
goto P_0c0a86ce;
P_0c0a86ce: /* original e03b, guest PC 0x0c0a86ce */
if(!s->budget--) { s->failed_pc=0x0c0a86ceu; return 0; }
r[0]=0x0000003bu;
goto P_0c0a86d0;
P_0c0a86d0: /* original 36cc, guest PC 0x0c0a86d0 */
if(!s->budget--) { s->failed_pc=0x0c0a86d0u; return 0; }
r[6]+=r[12];
goto P_0c0a86d2;
P_0c0a86d2: /* original 046c, guest PC 0x0c0a86d2 */
if(!s->budget--) { s->failed_pc=0x0c0a86d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0a86d4;
P_0c0a86d4: /* original 2448, guest PC 0x0c0a86d4 */
if(!s->budget--) { s->failed_pc=0x0c0a86d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a86d6;
P_0c0a86d6: /* original 8b01, guest PC 0x0c0a86d6 */
if(!s->budget--) { s->failed_pc=0x0c0a86d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86dc; }
goto P_0c0a86d8;
P_0c0a86d8: /* original a040, guest PC 0x0c0a86d8 */
if(!s->budget--) { s->failed_pc=0x0c0a86d8u; return 0; }
r[0]=0x00000001u;
goto P_0c0a875c;
P_0c0a86da: /* original e001, guest PC 0x0c0a86da */
if(!s->budget--) { s->failed_pc=0x0c0a86dau; return 0; }
r[0]=0x00000001u;
goto P_0c0a86dc;
P_0c0a86dc: /* original 60b3, guest PC 0x0c0a86dc */
if(!s->budget--) { s->failed_pc=0x0c0a86dcu; return 0; }
r[0]=r[11];
goto P_0c0a86de;
P_0c0a86de: /* original 8802, guest PC 0x0c0a86de */
if(!s->budget--) { s->failed_pc=0x0c0a86deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a86e0;
P_0c0a86e0: /* original 8903, guest PC 0x0c0a86e0 */
if(!s->budget--) { s->failed_pc=0x0c0a86e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a86ea; }
goto P_0c0a86e2;
P_0c0a86e2: /* original 65f2, guest PC 0x0c0a86e2 */
if(!s->budget--) { s->failed_pc=0x0c0a86e2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0a86e4;
P_0c0a86e4: /* original b041, guest PC 0x0c0a86e4 */
if(!s->budget--) { s->failed_pc=0x0c0a86e4u; return 0; }
target=code_base|0x0c0a876au; r[16]=code_base|0x0c0a86e8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a86e8u) { target=s->pc; goto dispatch; }
goto P_0c0a86e8;
P_0c0a86e6: /* original 64b3, guest PC 0x0c0a86e6 */
if(!s->budget--) { s->failed_pc=0x0c0a86e6u; return 0; }
r[4]=r[11];
goto P_0c0a86e8;
P_0c0a86e8: /* original 6b03, guest PC 0x0c0a86e8 */
if(!s->budget--) { s->failed_pc=0x0c0a86e8u; return 0; }
r[11]=r[0];
goto P_0c0a86ea;
P_0c0a86ea: /* original 60b3, guest PC 0x0c0a86ea */
if(!s->budget--) { s->failed_pc=0x0c0a86eau; return 0; }
r[0]=r[11];
goto P_0c0a86ec;
P_0c0a86ec: /* original 954a, guest PC 0x0c0a86ec */
if(!s->budget--) { s->failed_pc=0x0c0a86ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8784u,2);
goto P_0c0a86ee;
P_0c0a86ee: /* original 8802, guest PC 0x0c0a86ee */
if(!s->budget--) { s->failed_pc=0x0c0a86eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a86f0;
P_0c0a86f0: /* original 8b15, guest PC 0x0c0a86f0 */
if(!s->budget--) { s->failed_pc=0x0c0a86f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a871e; }
goto P_0c0a86f2;
P_0c0a86f2: /* original e400, guest PC 0x0c0a86f2 */
if(!s->budget--) { s->failed_pc=0x0c0a86f2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a86f4;
P_0c0a86f4: /* original 66e3, guest PC 0x0c0a86f4 */
if(!s->budget--) { s->failed_pc=0x0c0a86f4u; return 0; }
r[6]=r[14];
goto P_0c0a86f6;
P_0c0a86f6: /* original 4608, guest PC 0x0c0a86f6 */
if(!s->budget--) { s->failed_pc=0x0c0a86f6u; return 0; }
r[6]<<=2;
goto P_0c0a86f8;
P_0c0a86f8: /* original 4608, guest PC 0x0c0a86f8 */
if(!s->budget--) { s->failed_pc=0x0c0a86f8u; return 0; }
r[6]<<=2;
goto P_0c0a86fa;
P_0c0a86fa: /* original 4608, guest PC 0x0c0a86fa */
if(!s->budget--) { s->failed_pc=0x0c0a86fau; return 0; }
r[6]<<=2;
goto P_0c0a86fc;
P_0c0a86fc: /* original 4600, guest PC 0x0c0a86fc */
if(!s->budget--) { s->failed_pc=0x0c0a86fcu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0a86fe;
P_0c0a86fe: /* original e03b, guest PC 0x0c0a86fe */
if(!s->budget--) { s->failed_pc=0x0c0a86feu; return 0; }
r[0]=0x0000003bu;
goto P_0c0a8700;
P_0c0a8700: /* original 36cc, guest PC 0x0c0a8700 */
if(!s->budget--) { s->failed_pc=0x0c0a8700u; return 0; }
r[6]+=r[12];
goto P_0c0a8702;
P_0c0a8702: /* original 066c, guest PC 0x0c0a8702 */
if(!s->budget--) { s->failed_pc=0x0c0a8702u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0a8704;
P_0c0a8704: /* original 2668, guest PC 0x0c0a8704 */
if(!s->budget--) { s->failed_pc=0x0c0a8704u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a8706;
P_0c0a8706: /* original 8908, guest PC 0x0c0a8706 */
if(!s->budget--) { s->failed_pc=0x0c0a8706u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a871a; }
goto P_0c0a8708;
P_0c0a8708: /* original 7eff, guest PC 0x0c0a8708 */
if(!s->budget--) { s->failed_pc=0x0c0a8708u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a870a;
P_0c0a870a: /* original 4e11, guest PC 0x0c0a870a */
if(!s->budget--) { s->failed_pc=0x0c0a870au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a870c;
P_0c0a870c: /* original 8d01, guest PC 0x0c0a870c */
if(!s->budget--) { s->failed_pc=0x0c0a870cu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(cond) { goto P_0c0a8712; }
goto P_0c0a8710;
P_0c0a870e: /* original 7d01, guest PC 0x0c0a870e */
if(!s->budget--) { s->failed_pc=0x0c0a870eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8710;
P_0c0a8710: /* original 6e53, guest PC 0x0c0a8710 */
if(!s->budget--) { s->failed_pc=0x0c0a8710u; return 0; }
r[14]=r[5];
goto P_0c0a8712;
P_0c0a8712: /* original e31e, guest PC 0x0c0a8712 */
if(!s->budget--) { s->failed_pc=0x0c0a8712u; return 0; }
r[3]=0x0000001eu;
goto P_0c0a8714;
P_0c0a8714: /* original 7401, guest PC 0x0c0a8714 */
if(!s->budget--) { s->failed_pc=0x0c0a8714u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8716;
P_0c0a8716: /* original 3433, guest PC 0x0c0a8716 */
if(!s->budget--) { s->failed_pc=0x0c0a8716u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a8718;
P_0c0a8718: /* original 8bec, guest PC 0x0c0a8718 */
if(!s->budget--) { s->failed_pc=0x0c0a8718u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86f4; }
goto P_0c0a871a;
P_0c0a871a: /* original a009, guest PC 0x0c0a871a */
if(!s->budget--) { s->failed_pc=0x0c0a871au; return 0; }
r[4]=r[13];
goto P_0c0a8730;
P_0c0a871c: /* original 64d3, guest PC 0x0c0a871c */
if(!s->budget--) { s->failed_pc=0x0c0a871cu; return 0; }
r[4]=r[13];
goto P_0c0a871e;
P_0c0a871e: /* original 7eff, guest PC 0x0c0a871e */
if(!s->budget--) { s->failed_pc=0x0c0a871eu; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a8720;
P_0c0a8720: /* original 4e11, guest PC 0x0c0a8720 */
if(!s->budget--) { s->failed_pc=0x0c0a8720u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a8722;
P_0c0a8722: /* original 8d01, guest PC 0x0c0a8722 */
if(!s->budget--) { s->failed_pc=0x0c0a8722u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(cond) { goto P_0c0a8728; }
goto P_0c0a8726;
P_0c0a8724: /* original 7d01, guest PC 0x0c0a8724 */
if(!s->budget--) { s->failed_pc=0x0c0a8724u; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8726;
P_0c0a8726: /* original 6e53, guest PC 0x0c0a8726 */
if(!s->budget--) { s->failed_pc=0x0c0a8726u; return 0; }
r[14]=r[5];
goto P_0c0a8728;
P_0c0a8728: /* original 962d, guest PC 0x0c0a8728 */
if(!s->budget--) { s->failed_pc=0x0c0a8728u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8786u,2);
goto P_0c0a872a;
P_0c0a872a: /* original 3d63, guest PC 0x0c0a872a */
if(!s->budget--) { s->failed_pc=0x0c0a872au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[6])!=0);
goto P_0c0a872c;
P_0c0a872c: /* original 8bc8, guest PC 0x0c0a872c */
if(!s->budget--) { s->failed_pc=0x0c0a872cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86c0; }
goto P_0c0a872e;
P_0c0a872e: /* original 6463, guest PC 0x0c0a872e */
if(!s->budget--) { s->failed_pc=0x0c0a872eu; return 0; }
r[4]=r[6];
goto P_0c0a8730;
P_0c0a8730: /* original 962a, guest PC 0x0c0a8730 */
if(!s->budget--) { s->failed_pc=0x0c0a8730u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8788u,2);
goto P_0c0a8732;
P_0c0a8732: /* original 3463, guest PC 0x0c0a8732 */
if(!s->budget--) { s->failed_pc=0x0c0a8732u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c0a8734;
P_0c0a8734: /* original 8911, guest PC 0x0c0a8734 */
if(!s->budget--) { s->failed_pc=0x0c0a8734u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a875a; }
goto P_0c0a8736;
P_0c0a8736: /* original 67e3, guest PC 0x0c0a8736 */
if(!s->budget--) { s->failed_pc=0x0c0a8736u; return 0; }
r[7]=r[14];
goto P_0c0a8738;
P_0c0a8738: /* original 4708, guest PC 0x0c0a8738 */
if(!s->budget--) { s->failed_pc=0x0c0a8738u; return 0; }
r[7]<<=2;
goto P_0c0a873a;
P_0c0a873a: /* original 4708, guest PC 0x0c0a873a */
if(!s->budget--) { s->failed_pc=0x0c0a873au; return 0; }
r[7]<<=2;
goto P_0c0a873c;
P_0c0a873c: /* original 4708, guest PC 0x0c0a873c */
if(!s->budget--) { s->failed_pc=0x0c0a873cu; return 0; }
r[7]<<=2;
goto P_0c0a873e;
P_0c0a873e: /* original 4700, guest PC 0x0c0a873e */
if(!s->budget--) { s->failed_pc=0x0c0a873eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0a8740;
P_0c0a8740: /* original e03b, guest PC 0x0c0a8740 */
if(!s->budget--) { s->failed_pc=0x0c0a8740u; return 0; }
r[0]=0x0000003bu;
goto P_0c0a8742;
P_0c0a8742: /* original 37cc, guest PC 0x0c0a8742 */
if(!s->budget--) { s->failed_pc=0x0c0a8742u; return 0; }
r[7]+=r[12];
goto P_0c0a8744;
P_0c0a8744: /* original 077c, guest PC 0x0c0a8744 */
if(!s->budget--) { s->failed_pc=0x0c0a8744u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0a8746;
P_0c0a8746: /* original 2778, guest PC 0x0c0a8746 */
if(!s->budget--) { s->failed_pc=0x0c0a8746u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0a8748;
P_0c0a8748: /* original 8907, guest PC 0x0c0a8748 */
if(!s->budget--) { s->failed_pc=0x0c0a8748u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a875a; }
goto P_0c0a874a;
P_0c0a874a: /* original 7eff, guest PC 0x0c0a874a */
if(!s->budget--) { s->failed_pc=0x0c0a874au; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a874c;
P_0c0a874c: /* original 4e11, guest PC 0x0c0a874c */
if(!s->budget--) { s->failed_pc=0x0c0a874cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a874e;
P_0c0a874e: /* original 7d01, guest PC 0x0c0a874e */
if(!s->budget--) { s->failed_pc=0x0c0a874eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8750;
P_0c0a8750: /* original 8d01, guest PC 0x0c0a8750 */
if(!s->budget--) { s->failed_pc=0x0c0a8750u; return 0; }
cond=r[17]&1u;
r[4]=r[13];
if(cond) { goto P_0c0a8756; }
goto P_0c0a8754;
P_0c0a8752: /* original 64d3, guest PC 0x0c0a8752 */
if(!s->budget--) { s->failed_pc=0x0c0a8752u; return 0; }
r[4]=r[13];
goto P_0c0a8754;
P_0c0a8754: /* original 6e53, guest PC 0x0c0a8754 */
if(!s->budget--) { s->failed_pc=0x0c0a8754u; return 0; }
r[14]=r[5];
goto P_0c0a8756;
P_0c0a8756: /* original 3467, guest PC 0x0c0a8756 */
if(!s->budget--) { s->failed_pc=0x0c0a8756u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c0a8758;
P_0c0a8758: /* original 8bed, guest PC 0x0c0a8758 */
if(!s->budget--) { s->failed_pc=0x0c0a8758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8736; }
goto P_0c0a875a;
P_0c0a875a: /* original 6043, guest PC 0x0c0a875a */
if(!s->budget--) { s->failed_pc=0x0c0a875au; return 0; }
r[0]=r[4];
goto P_0c0a875c;
P_0c0a875c: /* original 7f04, guest PC 0x0c0a875c */
if(!s->budget--) { s->failed_pc=0x0c0a875cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a875e;
P_0c0a875e: /* original 4f26, guest PC 0x0c0a875e */
if(!s->budget--) { s->failed_pc=0x0c0a875eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8760;
P_0c0a8760: /* original 6bf6, guest PC 0x0c0a8760 */
if(!s->budget--) { s->failed_pc=0x0c0a8760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8762;
P_0c0a8762: /* original 6cf6, guest PC 0x0c0a8762 */
if(!s->budget--) { s->failed_pc=0x0c0a8762u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8764;
P_0c0a8764: /* original 6df6, guest PC 0x0c0a8764 */
if(!s->budget--) { s->failed_pc=0x0c0a8764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8766;
P_0c0a8766: /* original 000b, guest PC 0x0c0a8766 */
if(!s->budget--) { s->failed_pc=0x0c0a8766u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8768: /* original 6ef6, guest PC 0x0c0a8768 */
if(!s->budget--) { s->failed_pc=0x0c0a8768u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a876a;
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
unsupported: s->failed_pc=target; return 0;
}
