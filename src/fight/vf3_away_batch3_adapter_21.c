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
int vf3_away_batch3_adapter_21(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04580eu: goto P_0c04580e;
case 0x0c045810u: goto P_0c045810;
case 0x0c045812u: goto P_0c045812;
case 0x0c045814u: goto P_0c045814;
case 0x0c045816u: goto P_0c045816;
case 0x0c045818u: goto P_0c045818;
case 0x0c04581au: goto P_0c04581a;
case 0x0c04581cu: goto P_0c04581c;
case 0x0c04581eu: goto P_0c04581e;
case 0x0c045820u: goto P_0c045820;
case 0x0c045822u: goto P_0c045822;
case 0x0c045824u: goto P_0c045824;
case 0x0c045826u: goto P_0c045826;
case 0x0c045828u: goto P_0c045828;
case 0x0c04582au: goto P_0c04582a;
case 0x0c04582cu: goto P_0c04582c;
case 0x0c04582eu: goto P_0c04582e;
case 0x0c045830u: goto P_0c045830;
case 0x0c045832u: goto P_0c045832;
case 0x0c045834u: goto P_0c045834;
case 0x0c045836u: goto P_0c045836;
case 0x0c045838u: goto P_0c045838;
case 0x0c04583au: goto P_0c04583a;
case 0x0c04583cu: goto P_0c04583c;
case 0x0c04583eu: goto P_0c04583e;
case 0x0c045840u: goto P_0c045840;
case 0x0c045842u: goto P_0c045842;
case 0x0c045844u: goto P_0c045844;
case 0x0c045846u: goto P_0c045846;
case 0x0c045848u: goto P_0c045848;
case 0x0c04584au: goto P_0c04584a;
case 0x0c04584cu: goto P_0c04584c;
case 0x0c04584eu: goto P_0c04584e;
case 0x0c045850u: goto P_0c045850;
case 0x0c045852u: goto P_0c045852;
case 0x0c045854u: goto P_0c045854;
case 0x0c045856u: goto P_0c045856;
case 0x0c045858u: goto P_0c045858;
case 0x0c04585au: goto P_0c04585a;
case 0x0c04585cu: goto P_0c04585c;
case 0x0c04585eu: goto P_0c04585e;
case 0x0c045860u: goto P_0c045860;
case 0x0c045862u: goto P_0c045862;
case 0x0c045864u: goto P_0c045864;
case 0x0c045866u: goto P_0c045866;
case 0x0c045868u: goto P_0c045868;
case 0x0c04586au: goto P_0c04586a;
case 0x0c04586cu: goto P_0c04586c;
case 0x0c04586eu: goto P_0c04586e;
case 0x0c045870u: goto P_0c045870;
case 0x0c045872u: goto P_0c045872;
case 0x0c045874u: goto P_0c045874;
case 0x0c045876u: goto P_0c045876;
case 0x0c045878u: goto P_0c045878;
case 0x0c04587au: goto P_0c04587a;
case 0x0c04587cu: goto P_0c04587c;
case 0x0c04587eu: goto P_0c04587e;
case 0x0c045880u: goto P_0c045880;
case 0x0c045882u: goto P_0c045882;
case 0x0c045884u: goto P_0c045884;
case 0x0c045886u: goto P_0c045886;
case 0x0c045888u: goto P_0c045888;
case 0x0c04588au: goto P_0c04588a;
case 0x0c04588cu: goto P_0c04588c;
case 0x0c04588eu: goto P_0c04588e;
case 0x0c045890u: goto P_0c045890;
case 0x0c045892u: goto P_0c045892;
case 0x0c045894u: goto P_0c045894;
case 0x0c045896u: goto P_0c045896;
case 0x0c045898u: goto P_0c045898;
case 0x0c04589au: goto P_0c04589a;
case 0x0c04589cu: goto P_0c04589c;
case 0x0c04589eu: goto P_0c04589e;
case 0x0c0458a0u: goto P_0c0458a0;
case 0x0c0458a2u: goto P_0c0458a2;
case 0x0c0458a4u: goto P_0c0458a4;
case 0x0c0458a6u: goto P_0c0458a6;
case 0x0c0458a8u: goto P_0c0458a8;
case 0x0c0458aau: goto P_0c0458aa;
case 0x0c0458acu: goto P_0c0458ac;
case 0x0c0458c8u: goto P_0c0458c8;
case 0x0c0458cau: goto P_0c0458ca;
case 0x0c0458ccu: goto P_0c0458cc;
case 0x0c0458ceu: goto P_0c0458ce;
case 0x0c0458d0u: goto P_0c0458d0;
case 0x0c0458d2u: goto P_0c0458d2;
case 0x0c0458d4u: goto P_0c0458d4;
case 0x0c0458d6u: goto P_0c0458d6;
case 0x0c0458d8u: goto P_0c0458d8;
case 0x0c0458dau: goto P_0c0458da;
case 0x0c0458dcu: goto P_0c0458dc;
case 0x0c0458deu: goto P_0c0458de;
case 0x0c0458e0u: goto P_0c0458e0;
case 0x0c0458e2u: goto P_0c0458e2;
case 0x0c0458e4u: goto P_0c0458e4;
case 0x0c0458e6u: goto P_0c0458e6;
case 0x0c0458e8u: goto P_0c0458e8;
case 0x0c0458eau: goto P_0c0458ea;
case 0x0c0458ecu: goto P_0c0458ec;
case 0x0c0458eeu: goto P_0c0458ee;
case 0x0c0458f0u: goto P_0c0458f0;
case 0x0c0458f2u: goto P_0c0458f2;
case 0x0c0458f4u: goto P_0c0458f4;
case 0x0c0458f6u: goto P_0c0458f6;
case 0x0c0458f8u: goto P_0c0458f8;
case 0x0c0458fau: goto P_0c0458fa;
case 0x0c0458fcu: goto P_0c0458fc;
case 0x0c0458feu: goto P_0c0458fe;
case 0x0c045900u: goto P_0c045900;
case 0x0c045902u: goto P_0c045902;
case 0x0c045904u: goto P_0c045904;
case 0x0c045906u: goto P_0c045906;
case 0x0c045908u: goto P_0c045908;
case 0x0c04590au: goto P_0c04590a;
case 0x0c04590cu: goto P_0c04590c;
case 0x0c04590eu: goto P_0c04590e;
case 0x0c045910u: goto P_0c045910;
case 0x0c045912u: goto P_0c045912;
case 0x0c045914u: goto P_0c045914;
case 0x0c045916u: goto P_0c045916;
case 0x0c045918u: goto P_0c045918;
case 0x0c04591au: goto P_0c04591a;
case 0x0c04591cu: goto P_0c04591c;
case 0x0c04591eu: goto P_0c04591e;
case 0x0c045920u: goto P_0c045920;
case 0x0c045922u: goto P_0c045922;
case 0x0c045924u: goto P_0c045924;
case 0x0c045926u: goto P_0c045926;
case 0x0c045928u: goto P_0c045928;
case 0x0c04592au: goto P_0c04592a;
case 0x0c04592cu: goto P_0c04592c;
case 0x0c04592eu: goto P_0c04592e;
case 0x0c045930u: goto P_0c045930;
case 0x0c045932u: goto P_0c045932;
case 0x0c045934u: goto P_0c045934;
case 0x0c045936u: goto P_0c045936;
case 0x0c045938u: goto P_0c045938;
case 0x0c04593au: goto P_0c04593a;
case 0x0c04593cu: goto P_0c04593c;
case 0x0c04593eu: goto P_0c04593e;
case 0x0c045940u: goto P_0c045940;
case 0x0c045942u: goto P_0c045942;
case 0x0c045944u: goto P_0c045944;
case 0x0c045946u: goto P_0c045946;
case 0x0c045948u: goto P_0c045948;
case 0x0c04594au: goto P_0c04594a;
case 0x0c04594cu: goto P_0c04594c;
case 0x0c04594eu: goto P_0c04594e;
case 0x0c045950u: goto P_0c045950;
case 0x0c045952u: goto P_0c045952;
case 0x0c045954u: goto P_0c045954;
case 0x0c045956u: goto P_0c045956;
case 0x0c045958u: goto P_0c045958;
case 0x0c04595au: goto P_0c04595a;
case 0x0c04595cu: goto P_0c04595c;
case 0x0c04595eu: goto P_0c04595e;
case 0x0c045960u: goto P_0c045960;
case 0x0c045962u: goto P_0c045962;
case 0x0c045964u: goto P_0c045964;
case 0x0c045966u: goto P_0c045966;
case 0x0c045968u: goto P_0c045968;
case 0x0c04596au: goto P_0c04596a;
case 0x0c04596cu: goto P_0c04596c;
case 0x0c04596eu: goto P_0c04596e;
case 0x0c045970u: goto P_0c045970;
case 0x0c045972u: goto P_0c045972;
case 0x0c045974u: goto P_0c045974;
case 0x0c045976u: goto P_0c045976;
case 0x0c045978u: goto P_0c045978;
case 0x0c04597au: goto P_0c04597a;
case 0x0c04597cu: goto P_0c04597c;
case 0x0c04597eu: goto P_0c04597e;
case 0x0c045980u: goto P_0c045980;
case 0x0c045982u: goto P_0c045982;
case 0x0c045984u: goto P_0c045984;
case 0x0c045986u: goto P_0c045986;
case 0x0c045988u: goto P_0c045988;
case 0x0c04598au: goto P_0c04598a;
case 0x0c04598cu: goto P_0c04598c;
case 0x0c04598eu: goto P_0c04598e;
case 0x0c045990u: goto P_0c045990;
case 0x0c045992u: goto P_0c045992;
case 0x0c045994u: goto P_0c045994;
case 0x0c045996u: goto P_0c045996;
case 0x0c045998u: goto P_0c045998;
case 0x0c04599au: goto P_0c04599a;
case 0x0c04599cu: goto P_0c04599c;
case 0x0c04599eu: goto P_0c04599e;
case 0x0c0459a0u: goto P_0c0459a0;
case 0x0c0459a2u: goto P_0c0459a2;
case 0x0c0459a4u: goto P_0c0459a4;
case 0x0c0459a6u: goto P_0c0459a6;
case 0x0c0459a8u: goto P_0c0459a8;
case 0x0c0459aau: goto P_0c0459aa;
case 0x0c0459acu: goto P_0c0459ac;
case 0x0c0459aeu: goto P_0c0459ae;
case 0x0c0459b0u: goto P_0c0459b0;
case 0x0c0459b2u: goto P_0c0459b2;
case 0x0c0459b4u: goto P_0c0459b4;
case 0x0c0459b6u: goto P_0c0459b6;
case 0x0c0459b8u: goto P_0c0459b8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04580e: /* original 7604, guest PC 0x0c04580e */
if(!s->budget--) { s->failed_pc=0x0c04580eu; return 0; }
r[6]+=0x00000004u;
goto P_0c045810;
P_0c045810: /* original 2fe6, guest PC 0x0c045810 */
if(!s->budget--) { s->failed_pc=0x0c045810u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045812;
P_0c045812: /* original 6563, guest PC 0x0c045812 */
if(!s->budget--) { s->failed_pc=0x0c045812u; return 0; }
r[5]=r[6];
goto P_0c045814;
P_0c045814: /* original 6e43, guest PC 0x0c045814 */
if(!s->budget--) { s->failed_pc=0x0c045814u; return 0; }
r[14]=r[4];
goto P_0c045816;
P_0c045816: /* original 2fd6, guest PC 0x0c045816 */
if(!s->budget--) { s->failed_pc=0x0c045816u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045818;
P_0c045818: /* original e700, guest PC 0x0c045818 */
if(!s->budget--) { s->failed_pc=0x0c045818u; return 0; }
r[7]=0x00000000u;
goto P_0c04581a;
P_0c04581a: /* original 8451, guest PC 0x0c04581a */
if(!s->budget--) { s->failed_pc=0x0c04581au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c04581c;
P_0c04581c: /* original 7e04, guest PC 0x0c04581c */
if(!s->budget--) { s->failed_pc=0x0c04581cu; return 0; }
r[14]+=0x00000004u;
goto P_0c04581e;
P_0c04581e: /* original d328, guest PC 0x0c04581e */
if(!s->budget--) { s->failed_pc=0x0c04581eu; return 0; }
r[3]=read(ram,0x0c0458c0u,4);
goto P_0c045820;
P_0c045820: /* original 6d73, guest PC 0x0c045820 */
if(!s->budget--) { s->failed_pc=0x0c045820u; return 0; }
r[13]=r[7];
goto P_0c045822;
P_0c045822: /* original 600c, guest PC 0x0c045822 */
if(!s->budget--) { s->failed_pc=0x0c045822u; return 0; }
r[0]=r[0]&255u;
goto P_0c045824;
P_0c045824: /* original d227, guest PC 0x0c045824 */
if(!s->budget--) { s->failed_pc=0x0c045824u; return 0; }
r[2]=read(ram,0x0c0458c4u,4);
goto P_0c045826;
P_0c045826: /* original 4028, guest PC 0x0c045826 */
if(!s->budget--) { s->failed_pc=0x0c045826u; return 0; }
r[0]<<=16;
goto P_0c045828;
P_0c045828: /* original 2039, guest PC 0x0c045828 */
if(!s->budget--) { s->failed_pc=0x0c045828u; return 0; }
r[0]&=r[3];
goto P_0c04582a;
P_0c04582a: /* original 6103, guest PC 0x0c04582a */
if(!s->budget--) { s->failed_pc=0x0c04582au; return 0; }
r[1]=r[0];
goto P_0c04582c;
P_0c04582c: /* original 8452, guest PC 0x0c04582c */
if(!s->budget--) { s->failed_pc=0x0c04582cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c04582e;
P_0c04582e: /* original 4318, guest PC 0x0c04582e */
if(!s->budget--) { s->failed_pc=0x0c04582eu; return 0; }
r[3]<<=8;
goto P_0c045830;
P_0c045830: /* original 600c, guest PC 0x0c045830 */
if(!s->budget--) { s->failed_pc=0x0c045830u; return 0; }
r[0]=r[0]&255u;
goto P_0c045832;
P_0c045832: /* original 4018, guest PC 0x0c045832 */
if(!s->budget--) { s->failed_pc=0x0c045832u; return 0; }
r[0]<<=8;
goto P_0c045834;
P_0c045834: /* original 2029, guest PC 0x0c045834 */
if(!s->budget--) { s->failed_pc=0x0c045834u; return 0; }
r[0]&=r[2];
goto P_0c045836;
P_0c045836: /* original 210b, guest PC 0x0c045836 */
if(!s->budget--) { s->failed_pc=0x0c045836u; return 0; }
r[1]|=r[0];
goto P_0c045838;
P_0c045838: /* original 6050, guest PC 0x0c045838 */
if(!s->budget--) { s->failed_pc=0x0c045838u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c04583a;
P_0c04583a: /* original 600c, guest PC 0x0c04583a */
if(!s->budget--) { s->failed_pc=0x0c04583au; return 0; }
r[0]=r[0]&255u;
goto P_0c04583c;
P_0c04583c: /* original 4028, guest PC 0x0c04583c */
if(!s->budget--) { s->failed_pc=0x0c04583cu; return 0; }
r[0]<<=16;
goto P_0c04583e;
P_0c04583e: /* original 4018, guest PC 0x0c04583e */
if(!s->budget--) { s->failed_pc=0x0c04583eu; return 0; }
r[0]<<=8;
goto P_0c045840;
P_0c045840: /* original 2039, guest PC 0x0c045840 */
if(!s->budget--) { s->failed_pc=0x0c045840u; return 0; }
r[0]&=r[3];
goto P_0c045842;
P_0c045842: /* original 210b, guest PC 0x0c045842 */
if(!s->budget--) { s->failed_pc=0x0c045842u; return 0; }
r[1]|=r[0];
goto P_0c045844;
P_0c045844: /* original 8453, guest PC 0x0c045844 */
if(!s->budget--) { s->failed_pc=0x0c045844u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c045846;
P_0c045846: /* original 7504, guest PC 0x0c045846 */
if(!s->budget--) { s->failed_pc=0x0c045846u; return 0; }
r[5]+=0x00000004u;
goto P_0c045848;
P_0c045848: /* original 600c, guest PC 0x0c045848 */
if(!s->budget--) { s->failed_pc=0x0c045848u; return 0; }
r[0]=r[0]&255u;
goto P_0c04584a;
P_0c04584a: /* original 210b, guest PC 0x0c04584a */
if(!s->budget--) { s->failed_pc=0x0c04584au; return 0; }
r[1]|=r[0];
goto P_0c04584c;
P_0c04584c: /* original 2412, guest PC 0x0c04584c */
if(!s->budget--) { s->failed_pc=0x0c04584cu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c04584e;
P_0c04584e: /* original a004, guest PC 0x0c04584e */
if(!s->budget--) { s->failed_pc=0x0c04584eu; return 0; }
r[6]=0x00000004u;
goto P_0c04585a;
P_0c045850: /* original e604, guest PC 0x0c045850 */
if(!s->budget--) { s->failed_pc=0x0c045850u; return 0; }
r[6]=0x00000004u;
goto P_0c045852;
P_0c045852: /* original 6354, guest PC 0x0c045852 */
if(!s->budget--) { s->failed_pc=0x0c045852u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c045854;
P_0c045854: /* original 7d01, guest PC 0x0c045854 */
if(!s->budget--) { s->failed_pc=0x0c045854u; return 0; }
r[13]+=0x00000001u;
goto P_0c045856;
P_0c045856: /* original 2e30, guest PC 0x0c045856 */
if(!s->budget--) { s->failed_pc=0x0c045856u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c045858;
P_0c045858: /* original 7e01, guest PC 0x0c045858 */
if(!s->budget--) { s->failed_pc=0x0c045858u; return 0; }
r[14]+=0x00000001u;
goto P_0c04585a;
P_0c04585a: /* original 3d63, guest PC 0x0c04585a */
if(!s->budget--) { s->failed_pc=0x0c04585au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[6])!=0);
goto P_0c04585c;
P_0c04585c: /* original 8bf9, guest PC 0x0c04585c */
if(!s->budget--) { s->failed_pc=0x0c04585cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045852; }
goto P_0c04585e;
P_0c04585e: /* original 6e43, guest PC 0x0c04585e */
if(!s->budget--) { s->failed_pc=0x0c04585eu; return 0; }
r[14]=r[4];
goto P_0c045860;
P_0c045860: /* original 6d73, guest PC 0x0c045860 */
if(!s->budget--) { s->failed_pc=0x0c045860u; return 0; }
r[13]=r[7];
goto P_0c045862;
P_0c045862: /* original a004, guest PC 0x0c045862 */
if(!s->budget--) { s->failed_pc=0x0c045862u; return 0; }
r[14]+=0x00000008u;
goto P_0c04586e;
P_0c045864: /* original 7e08, guest PC 0x0c045864 */
if(!s->budget--) { s->failed_pc=0x0c045864u; return 0; }
r[14]+=0x00000008u;
goto P_0c045866;
P_0c045866: /* original 6354, guest PC 0x0c045866 */
if(!s->budget--) { s->failed_pc=0x0c045866u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c045868;
P_0c045868: /* original 7d01, guest PC 0x0c045868 */
if(!s->budget--) { s->failed_pc=0x0c045868u; return 0; }
r[13]+=0x00000001u;
goto P_0c04586a;
P_0c04586a: /* original 2e30, guest PC 0x0c04586a */
if(!s->budget--) { s->failed_pc=0x0c04586au; return 0; }
write(ram,r[14],r[3],1);
goto P_0c04586c;
P_0c04586c: /* original 7e01, guest PC 0x0c04586c */
if(!s->budget--) { s->failed_pc=0x0c04586cu; return 0; }
r[14]+=0x00000001u;
goto P_0c04586e;
P_0c04586e: /* original 3d63, guest PC 0x0c04586e */
if(!s->budget--) { s->failed_pc=0x0c04586eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[6])!=0);
goto P_0c045870;
P_0c045870: /* original 8bf9, guest PC 0x0c045870 */
if(!s->budget--) { s->failed_pc=0x0c045870u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045866; }
goto P_0c045872;
P_0c045872: /* original 6e43, guest PC 0x0c045872 */
if(!s->budget--) { s->failed_pc=0x0c045872u; return 0; }
r[14]=r[4];
goto P_0c045874;
P_0c045874: /* original 6d73, guest PC 0x0c045874 */
if(!s->budget--) { s->failed_pc=0x0c045874u; return 0; }
r[13]=r[7];
goto P_0c045876;
P_0c045876: /* original a004, guest PC 0x0c045876 */
if(!s->budget--) { s->failed_pc=0x0c045876u; return 0; }
r[14]+=0x0000000cu;
goto P_0c045882;
P_0c045878: /* original 7e0c, guest PC 0x0c045878 */
if(!s->budget--) { s->failed_pc=0x0c045878u; return 0; }
r[14]+=0x0000000cu;
goto P_0c04587a;
P_0c04587a: /* original 6354, guest PC 0x0c04587a */
if(!s->budget--) { s->failed_pc=0x0c04587au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04587c;
P_0c04587c: /* original 7d01, guest PC 0x0c04587c */
if(!s->budget--) { s->failed_pc=0x0c04587cu; return 0; }
r[13]+=0x00000001u;
goto P_0c04587e;
P_0c04587e: /* original 2e30, guest PC 0x0c04587e */
if(!s->budget--) { s->failed_pc=0x0c04587eu; return 0; }
write(ram,r[14],r[3],1);
goto P_0c045880;
P_0c045880: /* original 7e01, guest PC 0x0c045880 */
if(!s->budget--) { s->failed_pc=0x0c045880u; return 0; }
r[14]+=0x00000001u;
goto P_0c045882;
P_0c045882: /* original 3d63, guest PC 0x0c045882 */
if(!s->budget--) { s->failed_pc=0x0c045882u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[6])!=0);
goto P_0c045884;
P_0c045884: /* original 8bf9, guest PC 0x0c045884 */
if(!s->budget--) { s->failed_pc=0x0c045884u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04587a; }
goto P_0c045886;
P_0c045886: /* original 6354, guest PC 0x0c045886 */
if(!s->budget--) { s->failed_pc=0x0c045886u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c045888;
P_0c045888: /* original e011, guest PC 0x0c045888 */
if(!s->budget--) { s->failed_pc=0x0c045888u; return 0; }
r[0]=0x00000011u;
goto P_0c04588a;
P_0c04588a: /* original 0434, guest PC 0x0c04588a */
if(!s->budget--) { s->failed_pc=0x0c04588au; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c04588c;
P_0c04588c: /* original e010, guest PC 0x0c04588c */
if(!s->budget--) { s->failed_pc=0x0c04588cu; return 0; }
r[0]=0x00000010u;
goto P_0c04588e;
P_0c04588e: /* original 024c, guest PC 0x0c04588e */
if(!s->budget--) { s->failed_pc=0x0c04588eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c045890;
P_0c045890: /* original 2228, guest PC 0x0c045890 */
if(!s->budget--) { s->failed_pc=0x0c045890u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c045892;
P_0c045892: /* original 8919, guest PC 0x0c045892 */
if(!s->budget--) { s->failed_pc=0x0c045892u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0458c8; }
goto P_0c045894;
P_0c045894: /* original 6050, guest PC 0x0c045894 */
if(!s->budget--) { s->failed_pc=0x0c045894u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c045896;
P_0c045896: /* original 6243, guest PC 0x0c045896 */
if(!s->budget--) { s->failed_pc=0x0c045896u; return 0; }
r[2]=r[4];
goto P_0c045898;
P_0c045898: /* original 7212, guest PC 0x0c045898 */
if(!s->budget--) { s->failed_pc=0x0c045898u; return 0; }
r[2]+=0x00000012u;
goto P_0c04589a;
P_0c04589a: /* original c903, guest PC 0x0c04589a */
if(!s->budget--) { s->failed_pc=0x0c04589au; return 0; }
r[0]&=3u;
goto P_0c04589c;
P_0c04589c: /* original 2200, guest PC 0x0c04589c */
if(!s->budget--) { s->failed_pc=0x0c04589cu; return 0; }
write(ram,r[2],r[0],1);
goto P_0c04589e;
P_0c04589e: /* original e113, guest PC 0x0c04589e */
if(!s->budget--) { s->failed_pc=0x0c04589eu; return 0; }
r[1]=0x00000013u;
goto P_0c0458a0;
P_0c0458a0: /* original 6050, guest PC 0x0c0458a0 */
if(!s->budget--) { s->failed_pc=0x0c0458a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0458a2;
P_0c0458a2: /* original 314c, guest PC 0x0c0458a2 */
if(!s->budget--) { s->failed_pc=0x0c0458a2u; return 0; }
r[1]+=r[4];
goto P_0c0458a4;
P_0c0458a4: /* original 600c, guest PC 0x0c0458a4 */
if(!s->budget--) { s->failed_pc=0x0c0458a4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0458a6;
P_0c0458a6: /* original 4009, guest PC 0x0c0458a6 */
if(!s->budget--) { s->failed_pc=0x0c0458a6u; return 0; }
r[0]>>=2;
goto P_0c0458a8;
P_0c0458a8: /* original c903, guest PC 0x0c0458a8 */
if(!s->budget--) { s->failed_pc=0x0c0458a8u; return 0; }
r[0]&=3u;
goto P_0c0458aa;
P_0c0458aa: /* original a017, guest PC 0x0c0458aa */
if(!s->budget--) { s->failed_pc=0x0c0458aau; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0458dc;
P_0c0458ac: /* original 2100, guest PC 0x0c0458ac */
if(!s->budget--) { s->failed_pc=0x0c0458acu; return 0; }
write(ram,r[1],r[0],1);
if(!vf3_matrix_family(0x0c0458aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0458aeu; return 0; } return 1;
P_0c0458c8: /* original 6050, guest PC 0x0c0458c8 */
if(!s->budget--) { s->failed_pc=0x0c0458c8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0458ca;
P_0c0458ca: /* original 6243, guest PC 0x0c0458ca */
if(!s->budget--) { s->failed_pc=0x0c0458cau; return 0; }
r[2]=r[4];
goto P_0c0458cc;
P_0c0458cc: /* original d146, guest PC 0x0c0458cc */
if(!s->budget--) { s->failed_pc=0x0c0458ccu; return 0; }
r[1]=read(ram,0x0c0459e8u,4);
goto P_0c0458ce;
P_0c0458ce: /* original 7212, guest PC 0x0c0458ce */
if(!s->budget--) { s->failed_pc=0x0c0458ceu; return 0; }
r[2]+=0x00000012u;
goto P_0c0458d0;
P_0c0458d0: /* original 600c, guest PC 0x0c0458d0 */
if(!s->budget--) { s->failed_pc=0x0c0458d0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0458d2;
P_0c0458d2: /* original c90f, guest PC 0x0c0458d2 */
if(!s->budget--) { s->failed_pc=0x0c0458d2u; return 0; }
r[0]&=15u;
goto P_0c0458d4;
P_0c0458d4: /* original 031c, guest PC 0x0c0458d4 */
if(!s->budget--) { s->failed_pc=0x0c0458d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0458d6;
P_0c0458d6: /* original e013, guest PC 0x0c0458d6 */
if(!s->budget--) { s->failed_pc=0x0c0458d6u; return 0; }
r[0]=0x00000013u;
goto P_0c0458d8;
P_0c0458d8: /* original 2230, guest PC 0x0c0458d8 */
if(!s->budget--) { s->failed_pc=0x0c0458d8u; return 0; }
write(ram,r[2],r[3],1);
goto P_0c0458da;
P_0c0458da: /* original 0474, guest PC 0x0c0458da */
if(!s->budget--) { s->failed_pc=0x0c0458dau; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0458dc;
P_0c0458dc: /* original d343, guest PC 0x0c0458dc */
if(!s->budget--) { s->failed_pc=0x0c0458dcu; return 0; }
r[3]=read(ram,0x0c0459ecu,4);
goto P_0c0458de;
P_0c0458de: /* original 9182, guest PC 0x0c0458de */
if(!s->budget--) { s->failed_pc=0x0c0458deu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0459e6u,2);
goto P_0c0458e0;
P_0c0458e0: /* original 6032, guest PC 0x0c0458e0 */
if(!s->budget--) { s->failed_pc=0x0c0458e0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0458e2;
P_0c0458e2: /* original 001e, guest PC 0x0c0458e2 */
if(!s->budget--) { s->failed_pc=0x0c0458e2u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0458e4;
P_0c0458e4: /* original 8801, guest PC 0x0c0458e4 */
if(!s->budget--) { s->failed_pc=0x0c0458e4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0458e6;
P_0c0458e6: /* original 8b0c, guest PC 0x0c0458e6 */
if(!s->budget--) { s->failed_pc=0x0c0458e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045902; }
goto P_0c0458e8;
P_0c0458e8: /* original 6643, guest PC 0x0c0458e8 */
if(!s->budget--) { s->failed_pc=0x0c0458e8u; return 0; }
r[6]=r[4];
goto P_0c0458ea;
P_0c0458ea: /* original 7614, guest PC 0x0c0458ea */
if(!s->budget--) { s->failed_pc=0x0c0458eau; return 0; }
r[6]+=0x00000014u;
goto P_0c0458ec;
P_0c0458ec: /* original 6e73, guest PC 0x0c0458ec */
if(!s->budget--) { s->failed_pc=0x0c0458ecu; return 0; }
r[14]=r[7];
goto P_0c0458ee;
P_0c0458ee: /* original a004, guest PC 0x0c0458ee */
if(!s->budget--) { s->failed_pc=0x0c0458eeu; return 0; }
r[13]=0x0000001fu;
goto P_0c0458fa;
P_0c0458f0: /* original ed1f, guest PC 0x0c0458f0 */
if(!s->budget--) { s->failed_pc=0x0c0458f0u; return 0; }
r[13]=0x0000001fu;
goto P_0c0458f2;
P_0c0458f2: /* original 6354, guest PC 0x0c0458f2 */
if(!s->budget--) { s->failed_pc=0x0c0458f2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c0458f4;
P_0c0458f4: /* original 7e01, guest PC 0x0c0458f4 */
if(!s->budget--) { s->failed_pc=0x0c0458f4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0458f6;
P_0c0458f6: /* original 2630, guest PC 0x0c0458f6 */
if(!s->budget--) { s->failed_pc=0x0c0458f6u; return 0; }
write(ram,r[6],r[3],1);
goto P_0c0458f8;
P_0c0458f8: /* original 7601, guest PC 0x0c0458f8 */
if(!s->budget--) { s->failed_pc=0x0c0458f8u; return 0; }
r[6]+=0x00000001u;
goto P_0c0458fa;
P_0c0458fa: /* original 3ed3, guest PC 0x0c0458fa */
if(!s->budget--) { s->failed_pc=0x0c0458fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c0458fc;
P_0c0458fc: /* original 8bf9, guest PC 0x0c0458fc */
if(!s->budget--) { s->failed_pc=0x0c0458fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0458f2; }
goto P_0c0458fe;
P_0c0458fe: /* original a00e, guest PC 0x0c0458fe */
if(!s->budget--) { s->failed_pc=0x0c0458feu; return 0; }
goto P_0c04591e;
P_0c045900: /* original 0009, guest PC 0x0c045900 */
if(!s->budget--) { s->failed_pc=0x0c045900u; return 0; }
goto P_0c045902;
P_0c045902: /* original 6643, guest PC 0x0c045902 */
if(!s->budget--) { s->failed_pc=0x0c045902u; return 0; }
r[6]=r[4];
goto P_0c045904;
P_0c045904: /* original 7614, guest PC 0x0c045904 */
if(!s->budget--) { s->failed_pc=0x0c045904u; return 0; }
r[6]+=0x00000014u;
goto P_0c045906;
P_0c045906: /* original 7501, guest PC 0x0c045906 */
if(!s->budget--) { s->failed_pc=0x0c045906u; return 0; }
r[5]+=0x00000001u;
goto P_0c045908;
P_0c045908: /* original 6e73, guest PC 0x0c045908 */
if(!s->budget--) { s->failed_pc=0x0c045908u; return 0; }
r[14]=r[7];
goto P_0c04590a;
P_0c04590a: /* original a004, guest PC 0x0c04590a */
if(!s->budget--) { s->failed_pc=0x0c04590au; return 0; }
r[13]=0x0000001eu;
goto P_0c045916;
P_0c04590c: /* original ed1e, guest PC 0x0c04590c */
if(!s->budget--) { s->failed_pc=0x0c04590cu; return 0; }
r[13]=0x0000001eu;
goto P_0c04590e;
P_0c04590e: /* original 6354, guest PC 0x0c04590e */
if(!s->budget--) { s->failed_pc=0x0c04590eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c045910;
P_0c045910: /* original 7e01, guest PC 0x0c045910 */
if(!s->budget--) { s->failed_pc=0x0c045910u; return 0; }
r[14]+=0x00000001u;
goto P_0c045912;
P_0c045912: /* original 2630, guest PC 0x0c045912 */
if(!s->budget--) { s->failed_pc=0x0c045912u; return 0; }
write(ram,r[6],r[3],1);
goto P_0c045914;
P_0c045914: /* original 7601, guest PC 0x0c045914 */
if(!s->budget--) { s->failed_pc=0x0c045914u; return 0; }
r[6]+=0x00000001u;
goto P_0c045916;
P_0c045916: /* original 3ed3, guest PC 0x0c045916 */
if(!s->budget--) { s->failed_pc=0x0c045916u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c045918;
P_0c045918: /* original 8bf9, guest PC 0x0c045918 */
if(!s->budget--) { s->failed_pc=0x0c045918u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04590e; }
goto P_0c04591a;
P_0c04591a: /* original e032, guest PC 0x0c04591a */
if(!s->budget--) { s->failed_pc=0x0c04591au; return 0; }
r[0]=0x00000032u;
goto P_0c04591c;
P_0c04591c: /* original 0474, guest PC 0x0c04591c */
if(!s->budget--) { s->failed_pc=0x0c04591cu; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c04591e;
P_0c04591e: /* original 6643, guest PC 0x0c04591e */
if(!s->budget--) { s->failed_pc=0x0c04591eu; return 0; }
r[6]=r[4];
goto P_0c045920;
P_0c045920: /* original e033, guest PC 0x0c045920 */
if(!s->budget--) { s->failed_pc=0x0c045920u; return 0; }
r[0]=0x00000033u;
goto P_0c045922;
P_0c045922: /* original 7634, guest PC 0x0c045922 */
if(!s->budget--) { s->failed_pc=0x0c045922u; return 0; }
r[6]+=0x00000034u;
goto P_0c045924;
P_0c045924: /* original 0474, guest PC 0x0c045924 */
if(!s->budget--) { s->failed_pc=0x0c045924u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c045926;
P_0c045926: /* original 6e73, guest PC 0x0c045926 */
if(!s->budget--) { s->failed_pc=0x0c045926u; return 0; }
r[14]=r[7];
goto P_0c045928;
P_0c045928: /* original a004, guest PC 0x0c045928 */
if(!s->budget--) { s->failed_pc=0x0c045928u; return 0; }
r[13]=0x0000003cu;
goto P_0c045934;
P_0c04592a: /* original ed3c, guest PC 0x0c04592a */
if(!s->budget--) { s->failed_pc=0x0c04592au; return 0; }
r[13]=0x0000003cu;
goto P_0c04592c;
P_0c04592c: /* original 6354, guest PC 0x0c04592c */
if(!s->budget--) { s->failed_pc=0x0c04592cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04592e;
P_0c04592e: /* original 7e01, guest PC 0x0c04592e */
if(!s->budget--) { s->failed_pc=0x0c04592eu; return 0; }
r[14]+=0x00000001u;
goto P_0c045930;
P_0c045930: /* original 2630, guest PC 0x0c045930 */
if(!s->budget--) { s->failed_pc=0x0c045930u; return 0; }
write(ram,r[6],r[3],1);
goto P_0c045932;
P_0c045932: /* original 7601, guest PC 0x0c045932 */
if(!s->budget--) { s->failed_pc=0x0c045932u; return 0; }
r[6]+=0x00000001u;
goto P_0c045934;
P_0c045934: /* original 3ed3, guest PC 0x0c045934 */
if(!s->budget--) { s->failed_pc=0x0c045934u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c045936;
P_0c045936: /* original 8bf9, guest PC 0x0c045936 */
if(!s->budget--) { s->failed_pc=0x0c045936u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04592c; }
goto P_0c045938;
P_0c045938: /* original e070, guest PC 0x0c045938 */
if(!s->budget--) { s->failed_pc=0x0c045938u; return 0; }
r[0]=0x00000070u;
goto P_0c04593a;
P_0c04593a: /* original 0474, guest PC 0x0c04593a */
if(!s->budget--) { s->failed_pc=0x0c04593au; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c04593c;
P_0c04593c: /* original e174, guest PC 0x0c04593c */
if(!s->budget--) { s->failed_pc=0x0c04593cu; return 0; }
r[1]=0x00000074u;
goto P_0c04593e;
P_0c04593e: /* original 8451, guest PC 0x0c04593e */
if(!s->budget--) { s->failed_pc=0x0c04593eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+1,1);
goto P_0c045940;
P_0c045940: /* original 314c, guest PC 0x0c045940 */
if(!s->budget--) { s->failed_pc=0x0c045940u; return 0; }
r[1]+=r[4];
goto P_0c045942;
P_0c045942: /* original 6350, guest PC 0x0c045942 */
if(!s->budget--) { s->failed_pc=0x0c045942u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c045944;
P_0c045944: /* original 600c, guest PC 0x0c045944 */
if(!s->budget--) { s->failed_pc=0x0c045944u; return 0; }
r[0]=r[0]&255u;
goto P_0c045946;
P_0c045946: /* original 633c, guest PC 0x0c045946 */
if(!s->budget--) { s->failed_pc=0x0c045946u; return 0; }
r[3]=r[3]&255u;
goto P_0c045948;
P_0c045948: /* original 4018, guest PC 0x0c045948 */
if(!s->budget--) { s->failed_pc=0x0c045948u; return 0; }
r[0]<<=8;
goto P_0c04594a;
P_0c04594a: /* original 203b, guest PC 0x0c04594a */
if(!s->budget--) { s->failed_pc=0x0c04594au; return 0; }
r[0]|=r[3];
goto P_0c04594c;
P_0c04594c: /* original 2101, guest PC 0x0c04594c */
if(!s->budget--) { s->failed_pc=0x0c04594cu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c04594e;
P_0c04594e: /* original 8453, guest PC 0x0c04594e */
if(!s->budget--) { s->failed_pc=0x0c04594eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c045950;
P_0c045950: /* original 600c, guest PC 0x0c045950 */
if(!s->budget--) { s->failed_pc=0x0c045950u; return 0; }
r[0]=r[0]&255u;
goto P_0c045952;
P_0c045952: /* original 4018, guest PC 0x0c045952 */
if(!s->budget--) { s->failed_pc=0x0c045952u; return 0; }
r[0]<<=8;
goto P_0c045954;
P_0c045954: /* original 6303, guest PC 0x0c045954 */
if(!s->budget--) { s->failed_pc=0x0c045954u; return 0; }
r[3]=r[0];
goto P_0c045956;
P_0c045956: /* original 8452, guest PC 0x0c045956 */
if(!s->budget--) { s->failed_pc=0x0c045956u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c045958;
P_0c045958: /* original 600c, guest PC 0x0c045958 */
if(!s->budget--) { s->failed_pc=0x0c045958u; return 0; }
r[0]=r[0]&255u;
goto P_0c04595a;
P_0c04595a: /* original 230b, guest PC 0x0c04595a */
if(!s->budget--) { s->failed_pc=0x0c04595au; return 0; }
r[3]|=r[0];
goto P_0c04595c;
P_0c04595c: /* original e076, guest PC 0x0c04595c */
if(!s->budget--) { s->failed_pc=0x0c04595cu; return 0; }
r[0]=0x00000076u;
goto P_0c04595e;
P_0c04595e: /* original 0435, guest PC 0x0c04595e */
if(!s->budget--) { s->failed_pc=0x0c04595eu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c045960;
P_0c045960: /* original e000, guest PC 0x0c045960 */
if(!s->budget--) { s->failed_pc=0x0c045960u; return 0; }
r[0]=0x00000000u;
goto P_0c045962;
P_0c045962: /* original 6df6, guest PC 0x0c045962 */
if(!s->budget--) { s->failed_pc=0x0c045962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c045964;
P_0c045964: /* original 000b, guest PC 0x0c045964 */
if(!s->budget--) { s->failed_pc=0x0c045964u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045966: /* original 6ef6, guest PC 0x0c045966 */
if(!s->budget--) { s->failed_pc=0x0c045966u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c045968;
P_0c045968: /* original 2fe6, guest PC 0x0c045968 */
if(!s->budget--) { s->failed_pc=0x0c045968u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04596a;
P_0c04596a: /* original e61e, guest PC 0x0c04596a */
if(!s->budget--) { s->failed_pc=0x0c04596au; return 0; }
r[6]=0x0000001eu;
goto P_0c04596c;
P_0c04596c: /* original 4f22, guest PC 0x0c04596c */
if(!s->budget--) { s->failed_pc=0x0c04596cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04596e;
P_0c04596e: /* original 6e43, guest PC 0x0c04596e */
if(!s->budget--) { s->failed_pc=0x0c04596eu; return 0; }
r[14]=r[4];
goto P_0c045970;
P_0c045970: /* original b2c0, guest PC 0x0c045970 */
if(!s->budget--) { s->failed_pc=0x0c045970u; return 0; }
target=code_base|0x0c045ef4u; r[16]=code_base|0x0c045974u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045974u) { target=s->pc; goto dispatch; }
goto P_0c045974;
P_0c045972: /* original e500, guest PC 0x0c045972 */
if(!s->budget--) { s->failed_pc=0x0c045972u; return 0; }
r[5]=0x00000000u;
goto P_0c045974;
P_0c045974: /* original 62e3, guest PC 0x0c045974 */
if(!s->budget--) { s->failed_pc=0x0c045974u; return 0; }
r[2]=r[14];
goto P_0c045976;
P_0c045976: /* original e46e, guest PC 0x0c045976 */
if(!s->budget--) { s->failed_pc=0x0c045976u; return 0; }
r[4]=0x0000006eu;
goto P_0c045978;
P_0c045978: /* original e015, guest PC 0x0c045978 */
if(!s->budget--) { s->failed_pc=0x0c045978u; return 0; }
r[0]=0x00000015u;
goto P_0c04597a;
P_0c04597a: /* original 7214, guest PC 0x0c04597a */
if(!s->budget--) { s->failed_pc=0x0c04597au; return 0; }
r[2]+=0x00000014u;
goto P_0c04597c;
P_0c04597c: /* original e328, guest PC 0x0c04597c */
if(!s->budget--) { s->failed_pc=0x0c04597cu; return 0; }
r[3]=0x00000028u;
goto P_0c04597e;
P_0c04597e: /* original 2230, guest PC 0x0c04597e */
if(!s->budget--) { s->failed_pc=0x0c04597eu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c045980;
P_0c045980: /* original e36f, guest PC 0x0c045980 */
if(!s->budget--) { s->failed_pc=0x0c045980u; return 0; }
r[3]=0x0000006fu;
goto P_0c045982;
P_0c045982: /* original 0e44, guest PC 0x0c045982 */
if(!s->budget--) { s->failed_pc=0x0c045982u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c045984;
P_0c045984: /* original e016, guest PC 0x0c045984 */
if(!s->budget--) { s->failed_pc=0x0c045984u; return 0; }
r[0]=0x00000016u;
goto P_0c045986;
P_0c045986: /* original 0e34, guest PC 0x0c045986 */
if(!s->budget--) { s->failed_pc=0x0c045986u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c045988;
P_0c045988: /* original e017, guest PC 0x0c045988 */
if(!s->budget--) { s->failed_pc=0x0c045988u; return 0; }
r[0]=0x00000017u;
goto P_0c04598a;
P_0c04598a: /* original 0e44, guest PC 0x0c04598a */
if(!s->budget--) { s->failed_pc=0x0c04598au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c04598c;
P_0c04598c: /* original e018, guest PC 0x0c04598c */
if(!s->budget--) { s->failed_pc=0x0c04598cu; return 0; }
r[0]=0x00000018u;
goto P_0c04598e;
P_0c04598e: /* original e365, guest PC 0x0c04598e */
if(!s->budget--) { s->failed_pc=0x0c04598eu; return 0; }
r[3]=0x00000065u;
goto P_0c045990;
P_0c045990: /* original 64e3, guest PC 0x0c045990 */
if(!s->budget--) { s->failed_pc=0x0c045990u; return 0; }
r[4]=r[14];
goto P_0c045992;
P_0c045992: /* original 0e34, guest PC 0x0c045992 */
if(!s->budget--) { s->failed_pc=0x0c045992u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c045994;
P_0c045994: /* original e019, guest PC 0x0c045994 */
if(!s->budget--) { s->failed_pc=0x0c045994u; return 0; }
r[0]=0x00000019u;
goto P_0c045996;
P_0c045996: /* original e229, guest PC 0x0c045996 */
if(!s->budget--) { s->failed_pc=0x0c045996u; return 0; }
r[2]=0x00000029u;
goto P_0c045998;
P_0c045998: /* original e61f, guest PC 0x0c045998 */
if(!s->budget--) { s->failed_pc=0x0c045998u; return 0; }
r[6]=0x0000001fu;
goto P_0c04599a;
P_0c04599a: /* original 0e24, guest PC 0x0c04599a */
if(!s->budget--) { s->failed_pc=0x0c04599au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c04599c;
P_0c04599c: /* original 741a, guest PC 0x0c04599c */
if(!s->budget--) { s->failed_pc=0x0c04599cu; return 0; }
r[4]+=0x0000001au;
goto P_0c04599e;
P_0c04599e: /* original e506, guest PC 0x0c04599e */
if(!s->budget--) { s->failed_pc=0x0c04599eu; return 0; }
r[5]=0x00000006u;
goto P_0c0459a0;
P_0c0459a0: /* original e720, guest PC 0x0c0459a0 */
if(!s->budget--) { s->failed_pc=0x0c0459a0u; return 0; }
r[7]=0x00000020u;
goto P_0c0459a2;
P_0c0459a2: /* original 7501, guest PC 0x0c0459a2 */
if(!s->budget--) { s->failed_pc=0x0c0459a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0459a4;
P_0c0459a4: /* original 2470, guest PC 0x0c0459a4 */
if(!s->budget--) { s->failed_pc=0x0c0459a4u; return 0; }
write(ram,r[4],r[7],1);
goto P_0c0459a6;
P_0c0459a6: /* original 3563, guest PC 0x0c0459a6 */
if(!s->budget--) { s->failed_pc=0x0c0459a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0459a8;
P_0c0459a8: /* original 8ffb, guest PC 0x0c0459a8 */
if(!s->budget--) { s->failed_pc=0x0c0459a8u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c0459a2; }
goto P_0c0459ac;
P_0c0459aa: /* original 7401, guest PC 0x0c0459aa */
if(!s->budget--) { s->failed_pc=0x0c0459aau; return 0; }
r[4]+=0x00000001u;
goto P_0c0459ac;
P_0c0459ac: /* original 4f26, guest PC 0x0c0459ac */
if(!s->budget--) { s->failed_pc=0x0c0459acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0459ae;
P_0c0459ae: /* original e033, guest PC 0x0c0459ae */
if(!s->budget--) { s->failed_pc=0x0c0459aeu; return 0; }
r[0]=0x00000033u;
goto P_0c0459b0;
P_0c0459b0: /* original e200, guest PC 0x0c0459b0 */
if(!s->budget--) { s->failed_pc=0x0c0459b0u; return 0; }
r[2]=0x00000000u;
goto P_0c0459b2;
P_0c0459b2: /* original 0e24, guest PC 0x0c0459b2 */
if(!s->budget--) { s->failed_pc=0x0c0459b2u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0459b4;
P_0c0459b4: /* original 6023, guest PC 0x0c0459b4 */
if(!s->budget--) { s->failed_pc=0x0c0459b4u; return 0; }
r[0]=r[2];
goto P_0c0459b6;
P_0c0459b6: /* original 000b, guest PC 0x0c0459b6 */
if(!s->budget--) { s->failed_pc=0x0c0459b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0459b8: /* original 6ef6, guest PC 0x0c0459b8 */
if(!s->budget--) { s->failed_pc=0x0c0459b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0459bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0459bau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
