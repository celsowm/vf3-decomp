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
int vf3_away_batch6_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0507dcu: goto P_0c0507dc;
case 0x0c0507deu: goto P_0c0507de;
case 0x0c0507e0u: goto P_0c0507e0;
case 0x0c0507e2u: goto P_0c0507e2;
case 0x0c0507e4u: goto P_0c0507e4;
case 0x0c0507e6u: goto P_0c0507e6;
case 0x0c0507e8u: goto P_0c0507e8;
case 0x0c0507eau: goto P_0c0507ea;
case 0x0c0507ecu: goto P_0c0507ec;
case 0x0c0507eeu: goto P_0c0507ee;
case 0x0c0507f0u: goto P_0c0507f0;
case 0x0c0507f2u: goto P_0c0507f2;
case 0x0c0507f4u: goto P_0c0507f4;
case 0x0c0507f6u: goto P_0c0507f6;
case 0x0c0507f8u: goto P_0c0507f8;
case 0x0c0507fau: goto P_0c0507fa;
case 0x0c0507fcu: goto P_0c0507fc;
case 0x0c0507feu: goto P_0c0507fe;
case 0x0c050800u: goto P_0c050800;
case 0x0c050802u: goto P_0c050802;
case 0x0c050804u: goto P_0c050804;
case 0x0c050806u: goto P_0c050806;
case 0x0c050838u: goto P_0c050838;
case 0x0c05083au: goto P_0c05083a;
case 0x0c05083cu: goto P_0c05083c;
case 0x0c05083eu: goto P_0c05083e;
case 0x0c050840u: goto P_0c050840;
case 0x0c050842u: goto P_0c050842;
case 0x0c050844u: goto P_0c050844;
case 0x0c050846u: goto P_0c050846;
case 0x0c050848u: goto P_0c050848;
case 0x0c05084au: goto P_0c05084a;
case 0x0c05084cu: goto P_0c05084c;
case 0x0c05084eu: goto P_0c05084e;
case 0x0c050850u: goto P_0c050850;
case 0x0c050852u: goto P_0c050852;
case 0x0c050854u: goto P_0c050854;
case 0x0c050856u: goto P_0c050856;
case 0x0c050858u: goto P_0c050858;
case 0x0c05085au: goto P_0c05085a;
case 0x0c05085cu: goto P_0c05085c;
case 0x0c05085eu: goto P_0c05085e;
case 0x0c050860u: goto P_0c050860;
case 0x0c050862u: goto P_0c050862;
case 0x0c050864u: goto P_0c050864;
case 0x0c050866u: goto P_0c050866;
case 0x0c050868u: goto P_0c050868;
case 0x0c05086au: goto P_0c05086a;
case 0x0c05086cu: goto P_0c05086c;
case 0x0c05086eu: goto P_0c05086e;
case 0x0c050870u: goto P_0c050870;
case 0x0c050872u: goto P_0c050872;
case 0x0c050874u: goto P_0c050874;
case 0x0c050876u: goto P_0c050876;
case 0x0c050878u: goto P_0c050878;
case 0x0c05087au: goto P_0c05087a;
case 0x0c05087cu: goto P_0c05087c;
case 0x0c05087eu: goto P_0c05087e;
case 0x0c050880u: goto P_0c050880;
case 0x0c050882u: goto P_0c050882;
case 0x0c050884u: goto P_0c050884;
case 0x0c050886u: goto P_0c050886;
case 0x0c050888u: goto P_0c050888;
case 0x0c05088au: goto P_0c05088a;
case 0x0c05088cu: goto P_0c05088c;
case 0x0c05088eu: goto P_0c05088e;
case 0x0c050890u: goto P_0c050890;
case 0x0c050892u: goto P_0c050892;
case 0x0c050894u: goto P_0c050894;
case 0x0c050896u: goto P_0c050896;
case 0x0c050898u: goto P_0c050898;
case 0x0c05089au: goto P_0c05089a;
case 0x0c05089cu: goto P_0c05089c;
case 0x0c05089eu: goto P_0c05089e;
case 0x0c0508a0u: goto P_0c0508a0;
case 0x0c0508a2u: goto P_0c0508a2;
case 0x0c0508a4u: goto P_0c0508a4;
case 0x0c0508a6u: goto P_0c0508a6;
case 0x0c0508a8u: goto P_0c0508a8;
case 0x0c0508aau: goto P_0c0508aa;
case 0x0c0508acu: goto P_0c0508ac;
case 0x0c0508aeu: goto P_0c0508ae;
case 0x0c0508b0u: goto P_0c0508b0;
case 0x0c0508b2u: goto P_0c0508b2;
case 0x0c0508b4u: goto P_0c0508b4;
case 0x0c0508b6u: goto P_0c0508b6;
case 0x0c0508b8u: goto P_0c0508b8;
case 0x0c0508bau: goto P_0c0508ba;
case 0x0c0508bcu: goto P_0c0508bc;
case 0x0c0508beu: goto P_0c0508be;
case 0x0c0508c0u: goto P_0c0508c0;
case 0x0c0508c2u: goto P_0c0508c2;
case 0x0c0508c4u: goto P_0c0508c4;
case 0x0c0508c6u: goto P_0c0508c6;
case 0x0c0508c8u: goto P_0c0508c8;
case 0x0c0508cau: goto P_0c0508ca;
case 0x0c0508ccu: goto P_0c0508cc;
case 0x0c0508ceu: goto P_0c0508ce;
case 0x0c0508d0u: goto P_0c0508d0;
case 0x0c0508d2u: goto P_0c0508d2;
case 0x0c0508d4u: goto P_0c0508d4;
case 0x0c0508d6u: goto P_0c0508d6;
case 0x0c0508d8u: goto P_0c0508d8;
case 0x0c0508dau: goto P_0c0508da;
case 0x0c0508fcu: goto P_0c0508fc;
case 0x0c0508feu: goto P_0c0508fe;
case 0x0c050900u: goto P_0c050900;
case 0x0c050902u: goto P_0c050902;
case 0x0c050904u: goto P_0c050904;
case 0x0c050906u: goto P_0c050906;
case 0x0c050908u: goto P_0c050908;
case 0x0c05090au: goto P_0c05090a;
case 0x0c05090cu: goto P_0c05090c;
case 0x0c05090eu: goto P_0c05090e;
case 0x0c050910u: goto P_0c050910;
case 0x0c050912u: goto P_0c050912;
case 0x0c050914u: goto P_0c050914;
case 0x0c050916u: goto P_0c050916;
case 0x0c050918u: goto P_0c050918;
case 0x0c05091au: goto P_0c05091a;
case 0x0c05091cu: goto P_0c05091c;
case 0x0c05091eu: goto P_0c05091e;
case 0x0c050920u: goto P_0c050920;
case 0x0c050922u: goto P_0c050922;
case 0x0c050924u: goto P_0c050924;
case 0x0c050926u: goto P_0c050926;
case 0x0c050928u: goto P_0c050928;
case 0x0c05092au: goto P_0c05092a;
case 0x0c05092cu: goto P_0c05092c;
case 0x0c05092eu: goto P_0c05092e;
case 0x0c050930u: goto P_0c050930;
case 0x0c050932u: goto P_0c050932;
case 0x0c050934u: goto P_0c050934;
case 0x0c050936u: goto P_0c050936;
case 0x0c050938u: goto P_0c050938;
case 0x0c05093au: goto P_0c05093a;
case 0x0c05093cu: goto P_0c05093c;
case 0x0c05093eu: goto P_0c05093e;
case 0x0c050940u: goto P_0c050940;
case 0x0c050942u: goto P_0c050942;
case 0x0c050944u: goto P_0c050944;
case 0x0c050946u: goto P_0c050946;
case 0x0c050948u: goto P_0c050948;
case 0x0c05094au: goto P_0c05094a;
case 0x0c05094cu: goto P_0c05094c;
case 0x0c05094eu: goto P_0c05094e;
case 0x0c050950u: goto P_0c050950;
case 0x0c050952u: goto P_0c050952;
case 0x0c050954u: goto P_0c050954;
case 0x0c050956u: goto P_0c050956;
case 0x0c050958u: goto P_0c050958;
case 0x0c05095au: goto P_0c05095a;
case 0x0c05095cu: goto P_0c05095c;
case 0x0c05095eu: goto P_0c05095e;
case 0x0c050960u: goto P_0c050960;
case 0x0c050962u: goto P_0c050962;
case 0x0c050964u: goto P_0c050964;
case 0x0c050966u: goto P_0c050966;
case 0x0c050968u: goto P_0c050968;
case 0x0c05096au: goto P_0c05096a;
case 0x0c05096cu: goto P_0c05096c;
case 0x0c05096eu: goto P_0c05096e;
case 0x0c050970u: goto P_0c050970;
case 0x0c050972u: goto P_0c050972;
case 0x0c050974u: goto P_0c050974;
case 0x0c050976u: goto P_0c050976;
case 0x0c050978u: goto P_0c050978;
case 0x0c05097au: goto P_0c05097a;
case 0x0c05097cu: goto P_0c05097c;
case 0x0c05097eu: goto P_0c05097e;
case 0x0c050980u: goto P_0c050980;
case 0x0c050982u: goto P_0c050982;
case 0x0c050984u: goto P_0c050984;
case 0x0c050986u: goto P_0c050986;
case 0x0c050988u: goto P_0c050988;
case 0x0c05098au: goto P_0c05098a;
case 0x0c05098cu: goto P_0c05098c;
case 0x0c05098eu: goto P_0c05098e;
case 0x0c050990u: goto P_0c050990;
case 0x0c050992u: goto P_0c050992;
case 0x0c050994u: goto P_0c050994;
case 0x0c050996u: goto P_0c050996;
case 0x0c050998u: goto P_0c050998;
case 0x0c05099au: goto P_0c05099a;
case 0x0c05099cu: goto P_0c05099c;
case 0x0c05099eu: goto P_0c05099e;
case 0x0c0509a0u: goto P_0c0509a0;
case 0x0c0509a2u: goto P_0c0509a2;
case 0x0c0509a4u: goto P_0c0509a4;
case 0x0c0509a6u: goto P_0c0509a6;
case 0x0c0509a8u: goto P_0c0509a8;
case 0x0c0509aau: goto P_0c0509aa;
case 0x0c0509acu: goto P_0c0509ac;
case 0x0c0509aeu: goto P_0c0509ae;
case 0x0c0509b0u: goto P_0c0509b0;
case 0x0c0509b2u: goto P_0c0509b2;
case 0x0c0509b4u: goto P_0c0509b4;
case 0x0c0509b6u: goto P_0c0509b6;
case 0x0c0509b8u: goto P_0c0509b8;
case 0x0c0509bau: goto P_0c0509ba;
case 0x0c0509bcu: goto P_0c0509bc;
case 0x0c0509beu: goto P_0c0509be;
case 0x0c0509c0u: goto P_0c0509c0;
case 0x0c0509c2u: goto P_0c0509c2;
case 0x0c0509c4u: goto P_0c0509c4;
case 0x0c0509c6u: goto P_0c0509c6;
case 0x0c0509c8u: goto P_0c0509c8;
case 0x0c0509cau: goto P_0c0509ca;
case 0x0c0509ccu: goto P_0c0509cc;
case 0x0c0509ceu: goto P_0c0509ce;
case 0x0c0509d0u: goto P_0c0509d0;
case 0x0c0509d2u: goto P_0c0509d2;
case 0x0c0509d4u: goto P_0c0509d4;
case 0x0c0509d6u: goto P_0c0509d6;
case 0x0c0509d8u: goto P_0c0509d8;
case 0x0c0509dau: goto P_0c0509da;
case 0x0c0509dcu: goto P_0c0509dc;
case 0x0c0509deu: goto P_0c0509de;
case 0x0c0509e0u: goto P_0c0509e0;
case 0x0c0509e2u: goto P_0c0509e2;
case 0x0c0509e4u: goto P_0c0509e4;
case 0x0c0509e6u: goto P_0c0509e6;
case 0x0c0509e8u: goto P_0c0509e8;
case 0x0c0509eau: goto P_0c0509ea;
case 0x0c0509ecu: goto P_0c0509ec;
case 0x0c0509eeu: goto P_0c0509ee;
case 0x0c0509f0u: goto P_0c0509f0;
case 0x0c0509f2u: goto P_0c0509f2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0507dc: /* original 2fe6, guest PC 0x0c0507dc */
if(!s->budget--) { s->failed_pc=0x0c0507dcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0507de;
P_0c0507de: /* original 2fd6, guest PC 0x0c0507de */
if(!s->budget--) { s->failed_pc=0x0c0507deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0507e0;
P_0c0507e0: /* original 6d73, guest PC 0x0c0507e0 */
if(!s->budget--) { s->failed_pc=0x0c0507e0u; return 0; }
r[13]=r[7];
goto P_0c0507e2;
P_0c0507e2: /* original 2fc6, guest PC 0x0c0507e2 */
if(!s->budget--) { s->failed_pc=0x0c0507e2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0507e4;
P_0c0507e4: /* original 2fb6, guest PC 0x0c0507e4 */
if(!s->budget--) { s->failed_pc=0x0c0507e4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0507e6;
P_0c0507e6: /* original 6b43, guest PC 0x0c0507e6 */
if(!s->budget--) { s->failed_pc=0x0c0507e6u; return 0; }
r[11]=r[4];
goto P_0c0507e8;
P_0c0507e8: /* original 2fa6, guest PC 0x0c0507e8 */
if(!s->budget--) { s->failed_pc=0x0c0507e8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0507ea;
P_0c0507ea: /* original 4f22, guest PC 0x0c0507ea */
if(!s->budget--) { s->failed_pc=0x0c0507eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0507ec;
P_0c0507ec: /* original 4f12, guest PC 0x0c0507ec */
if(!s->budget--) { s->failed_pc=0x0c0507ecu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0507ee;
P_0c0507ee: /* original 7ff4, guest PC 0x0c0507ee */
if(!s->budget--) { s->failed_pc=0x0c0507eeu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0507f0;
P_0c0507f0: /* original 1f52, guest PC 0x0c0507f0 */
if(!s->budget--) { s->failed_pc=0x0c0507f0u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0507f2;
P_0c0507f2: /* original e501, guest PC 0x0c0507f2 */
if(!s->budget--) { s->failed_pc=0x0c0507f2u; return 0; }
r[5]=0x00000001u;
goto P_0c0507f4;
P_0c0507f4: /* original 1f61, guest PC 0x0c0507f4 */
if(!s->budget--) { s->failed_pc=0x0c0507f4u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0507f6;
P_0c0507f6: /* original 5cfb, guest PC 0x0c0507f6 */
if(!s->budget--) { s->failed_pc=0x0c0507f6u; return 0; }
r[12]=read(ram,r[15]+44,4);
goto P_0c0507f8;
P_0c0507f8: /* original d30e, guest PC 0x0c0507f8 */
if(!s->budget--) { s->failed_pc=0x0c0507f8u; return 0; }
r[3]=read(ram,0x0c050834u,4);
goto P_0c0507fa;
P_0c0507fa: /* original 430b, guest PC 0x0c0507fa */
if(!s->budget--) { s->failed_pc=0x0c0507fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0507feu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0507feu) { target=s->pc; goto dispatch; }
goto P_0c0507fe;
P_0c0507fc: /* original 64b3, guest PC 0x0c0507fc */
if(!s->budget--) { s->failed_pc=0x0c0507fcu; return 0; }
r[4]=r[11];
goto P_0c0507fe;
P_0c0507fe: /* original 6403, guest PC 0x0c0507fe */
if(!s->budget--) { s->failed_pc=0x0c0507feu; return 0; }
r[4]=r[0];
goto P_0c050800;
P_0c050800: /* original 4411, guest PC 0x0c050800 */
if(!s->budget--) { s->failed_pc=0x0c050800u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c050802;
P_0c050802: /* original 8919, guest PC 0x0c050802 */
if(!s->budget--) { s->failed_pc=0x0c050802u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050838; }
goto P_0c050804;
P_0c050804: /* original a061, guest PC 0x0c050804 */
if(!s->budget--) { s->failed_pc=0x0c050804u; return 0; }
r[0]=r[4];
goto P_0c0508ca;
P_0c050806: /* original 6043, guest PC 0x0c050806 */
if(!s->budget--) { s->failed_pc=0x0c050806u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c050808u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050808u; return 0; } return 1;
P_0c050838: /* original 34d2, guest PC 0x0c050838 */
if(!s->budget--) { s->failed_pc=0x0c050838u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[13])!=0);
goto P_0c05083a;
P_0c05083a: /* original 8902, guest PC 0x0c05083a */
if(!s->budget--) { s->failed_pc=0x0c05083au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050842; }
goto P_0c05083c;
P_0c05083c: /* original 904e, guest PC 0x0c05083c */
if(!s->budget--) { s->failed_pc=0x0c05083cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0508dcu,2);
goto P_0c05083e;
P_0c05083e: /* original a044, guest PC 0x0c05083e */
if(!s->budget--) { s->failed_pc=0x0c05083eu; return 0; }
goto P_0c0508ca;
P_0c050840: /* original 0009, guest PC 0x0c050840 */
if(!s->budget--) { s->failed_pc=0x0c050840u; return 0; }
goto P_0c050842;
P_0c050842: /* original d428, guest PC 0x0c050842 */
if(!s->budget--) { s->failed_pc=0x0c050842u; return 0; }
r[4]=read(ram,0x0c0508e4u,4);
goto P_0c050844;
P_0c050844: /* original 24c9, guest PC 0x0c050844 */
if(!s->budget--) { s->failed_pc=0x0c050844u; return 0; }
r[4]&=r[12];
goto P_0c050846;
P_0c050846: /* original 2448, guest PC 0x0c050846 */
if(!s->budget--) { s->failed_pc=0x0c050846u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c050848;
P_0c050848: /* original 8909, guest PC 0x0c050848 */
if(!s->budget--) { s->failed_pc=0x0c050848u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05085e; }
goto P_0c05084a;
P_0c05084a: /* original 2fc6, guest PC 0x0c05084a */
if(!s->budget--) { s->failed_pc=0x0c05084au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05084c;
P_0c05084c: /* original 67d3, guest PC 0x0c05084c */
if(!s->budget--) { s->failed_pc=0x0c05084cu; return 0; }
r[7]=r[13];
goto P_0c05084e;
P_0c05084e: /* original 53fb, guest PC 0x0c05084e */
if(!s->budget--) { s->failed_pc=0x0c05084eu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c050850;
P_0c050850: /* original 2f36, guest PC 0x0c050850 */
if(!s->budget--) { s->failed_pc=0x0c050850u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050852;
P_0c050852: /* original 55f4, guest PC 0x0c050852 */
if(!s->budget--) { s->failed_pc=0x0c050852u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c050854;
P_0c050854: /* original 56f3, guest PC 0x0c050854 */
if(!s->budget--) { s->failed_pc=0x0c050854u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c050856;
P_0c050856: /* original b051, guest PC 0x0c050856 */
if(!s->budget--) { s->failed_pc=0x0c050856u; return 0; }
target=code_base|0x0c0508fcu; r[16]=code_base|0x0c05085au;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05085au) { target=s->pc; goto dispatch; }
goto P_0c05085a;
P_0c050858: /* original 64b3, guest PC 0x0c050858 */
if(!s->budget--) { s->failed_pc=0x0c050858u; return 0; }
r[4]=r[11];
goto P_0c05085a;
P_0c05085a: /* original a036, guest PC 0x0c05085a */
if(!s->budget--) { s->failed_pc=0x0c05085au; return 0; }
r[15]+=0x00000008u;
goto P_0c0508ca;
P_0c05085c: /* original 7f08, guest PC 0x0c05085c */
if(!s->budget--) { s->failed_pc=0x0c05085cu; return 0; }
r[15]+=0x00000008u;
goto P_0c05085e;
P_0c05085e: /* original 55f2, guest PC 0x0c05085e */
if(!s->budget--) { s->failed_pc=0x0c05085eu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c050860;
P_0c050860: /* original 67f3, guest PC 0x0c050860 */
if(!s->budget--) { s->failed_pc=0x0c050860u; return 0; }
r[7]=r[15];
goto P_0c050862;
P_0c050862: /* original d321, guest PC 0x0c050862 */
if(!s->budget--) { s->failed_pc=0x0c050862u; return 0; }
r[3]=read(ram,0x0c0508e8u,4);
goto P_0c050864;
P_0c050864: /* original 56fa, guest PC 0x0c050864 */
if(!s->budget--) { s->failed_pc=0x0c050864u; return 0; }
r[6]=read(ram,r[15]+40,4);
goto P_0c050866;
P_0c050866: /* original 430b, guest PC 0x0c050866 */
if(!s->budget--) { s->failed_pc=0x0c050866u; return 0; }
target=r[3];
r[16]=code_base|0x0c05086au;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05086au) { target=s->pc; goto dispatch; }
goto P_0c05086a;
P_0c050868: /* original 64b3, guest PC 0x0c050868 */
if(!s->budget--) { s->failed_pc=0x0c050868u; return 0; }
r[4]=r[11];
goto P_0c05086a;
P_0c05086a: /* original 6e03, guest PC 0x0c05086a */
if(!s->budget--) { s->failed_pc=0x0c05086au; return 0; }
r[14]=r[0];
goto P_0c05086c;
P_0c05086c: /* original 4e11, guest PC 0x0c05086c */
if(!s->budget--) { s->failed_pc=0x0c05086cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c05086e;
P_0c05086e: /* original 8b2b, guest PC 0x0c05086e */
if(!s->budget--) { s->failed_pc=0x0c05086eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0508c8; }
goto P_0c050870;
P_0c050870: /* original 62f2, guest PC 0x0c050870 */
if(!s->budget--) { s->failed_pc=0x0c050870u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c050872;
P_0c050872: /* original 60c3, guest PC 0x0c050872 */
if(!s->budget--) { s->failed_pc=0x0c050872u; return 0; }
r[0]=r[12];
goto P_0c050874;
P_0c050874: /* original 8021, guest PC 0x0c050874 */
if(!s->budget--) { s->failed_pc=0x0c050874u; return 0; }
write(ram,r[2]+1,r[0],1);
goto P_0c050876;
P_0c050876: /* original e201, guest PC 0x0c050876 */
if(!s->budget--) { s->failed_pc=0x0c050876u; return 0; }
r[2]=0x00000001u;
goto P_0c050878;
P_0c050878: /* original 9431, guest PC 0x0c050878 */
if(!s->budget--) { s->failed_pc=0x0c050878u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0508deu,2);
goto P_0c05087a;
P_0c05087a: /* original d31c, guest PC 0x0c05087a */
if(!s->budget--) { s->failed_pc=0x0c05087au; return 0; }
r[3]=read(ram,0x0c0508ecu,4);
goto P_0c05087c;
P_0c05087c: /* original 2b4f, guest PC 0x0c05087c */
if(!s->budget--) { s->failed_pc=0x0c05087cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[4]);
goto P_0c05087e;
P_0c05087e: /* original eb00, guest PC 0x0c05087e */
if(!s->budget--) { s->failed_pc=0x0c05087eu; return 0; }
r[11]=0x00000000u;
goto P_0c050880;
P_0c050880: /* original 5cf1, guest PC 0x0c050880 */
if(!s->budget--) { s->failed_pc=0x0c050880u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c050882;
P_0c050882: /* original 041a, guest PC 0x0c050882 */
if(!s->budget--) { s->failed_pc=0x0c050882u; return 0; }
r[4]=r[19];
goto P_0c050884;
P_0c050884: /* original 644f, guest PC 0x0c050884 */
if(!s->budget--) { s->failed_pc=0x0c050884u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c050886;
P_0c050886: /* original 343c, guest PC 0x0c050886 */
if(!s->budget--) { s->failed_pc=0x0c050886u; return 0; }
r[4]+=r[3];
goto P_0c050888;
P_0c050888: /* original 142c, guest PC 0x0c050888 */
if(!s->budget--) { s->failed_pc=0x0c050888u; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c05088a;
P_0c05088a: /* original 5141, guest PC 0x0c05088a */
if(!s->budget--) { s->failed_pc=0x0c05088au; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c05088c;
P_0c05088c: /* original d018, guest PC 0x0c05088c */
if(!s->budget--) { s->failed_pc=0x0c05088cu; return 0; }
r[0]=read(ram,0x0c0508f0u,4);
goto P_0c05088e;
P_0c05088e: /* original 6213, guest PC 0x0c05088e */
if(!s->budget--) { s->failed_pc=0x0c05088eu; return 0; }
r[2]=r[1];
goto P_0c050890;
P_0c050890: /* original 4108, guest PC 0x0c050890 */
if(!s->budget--) { s->failed_pc=0x0c050890u; return 0; }
r[1]<<=2;
goto P_0c050892;
P_0c050892: /* original 312c, guest PC 0x0c050892 */
if(!s->budget--) { s->failed_pc=0x0c050892u; return 0; }
r[1]+=r[2];
goto P_0c050894;
P_0c050894: /* original 62b3, guest PC 0x0c050894 */
if(!s->budget--) { s->failed_pc=0x0c050894u; return 0; }
r[2]=r[11];
goto P_0c050896;
P_0c050896: /* original 4108, guest PC 0x0c050896 */
if(!s->budget--) { s->failed_pc=0x0c050896u; return 0; }
r[1]<<=2;
goto P_0c050898;
P_0c050898: /* original 32d2, guest PC 0x0c050898 */
if(!s->budget--) { s->failed_pc=0x0c050898u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[13])!=0);
goto P_0c05089a;
P_0c05089a: /* original 4108, guest PC 0x0c05089a */
if(!s->budget--) { s->failed_pc=0x0c05089au; return 0; }
r[1]<<=2;
goto P_0c05089c;
P_0c05089c: /* original 611f, guest PC 0x0c05089c */
if(!s->budget--) { s->failed_pc=0x0c05089cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c05089e;
P_0c05089e: /* original 001e, guest PC 0x0c05089e */
if(!s->budget--) { s->failed_pc=0x0c05089eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0508a0;
P_0c0508a0: /* original 30dc, guest PC 0x0c0508a0 */
if(!s->budget--) { s->failed_pc=0x0c0508a0u; return 0; }
r[0]+=r[13];
goto P_0c0508a2;
P_0c0508a2: /* original 8d0c, guest PC 0x0c0508a2 */
if(!s->budget--) { s->failed_pc=0x0c0508a2u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+52,r[0],4);
if(cond) { goto P_0c0508be; }
goto P_0c0508a6;
P_0c0508a4: /* original 140d, guest PC 0x0c0508a4 */
if(!s->budget--) { s->failed_pc=0x0c0508a4u; return 0; }
write(ram,r[4]+52,r[0],4);
goto P_0c0508a6;
P_0c0508a6: /* original 9a1b, guest PC 0x0c0508a6 */
if(!s->budget--) { s->failed_pc=0x0c0508a6u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0508e0u,2);
goto P_0c0508a8;
P_0c0508a8: /* original d312, guest PC 0x0c0508a8 */
if(!s->budget--) { s->failed_pc=0x0c0508a8u; return 0; }
r[3]=read(ram,0x0c0508f4u,4);
goto P_0c0508aa;
P_0c0508aa: /* original 65c3, guest PC 0x0c0508aa */
if(!s->budget--) { s->failed_pc=0x0c0508aau; return 0; }
r[5]=r[12];
goto P_0c0508ac;
P_0c0508ac: /* original 430b, guest PC 0x0c0508ac */
if(!s->budget--) { s->failed_pc=0x0c0508acu; return 0; }
target=r[3];
r[16]=code_base|0x0c0508b0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0508b0u) { target=s->pc; goto dispatch; }
goto P_0c0508b0;
P_0c0508ae: /* original 64f2, guest PC 0x0c0508ae */
if(!s->budget--) { s->failed_pc=0x0c0508aeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0508b0;
P_0c0508b0: /* original 6e03, guest PC 0x0c0508b0 */
if(!s->budget--) { s->failed_pc=0x0c0508b0u; return 0; }
r[14]=r[0];
goto P_0c0508b2;
P_0c0508b2: /* original 4e11, guest PC 0x0c0508b2 */
if(!s->budget--) { s->failed_pc=0x0c0508b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0508b4;
P_0c0508b4: /* original 8b04, guest PC 0x0c0508b4 */
if(!s->budget--) { s->failed_pc=0x0c0508b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0508c0; }
goto P_0c0508b6;
P_0c0508b6: /* original 7b01, guest PC 0x0c0508b6 */
if(!s->budget--) { s->failed_pc=0x0c0508b6u; return 0; }
r[11]+=0x00000001u;
goto P_0c0508b8;
P_0c0508b8: /* original 3bd2, guest PC 0x0c0508b8 */
if(!s->budget--) { s->failed_pc=0x0c0508b8u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[13])!=0);
goto P_0c0508ba;
P_0c0508ba: /* original 8ff5, guest PC 0x0c0508ba */
if(!s->budget--) { s->failed_pc=0x0c0508bau; return 0; }
cond=r[17]&1u;
r[12]+=r[10];
if(!cond) { goto P_0c0508a8; }
goto P_0c0508be;
P_0c0508bc: /* original 3cac, guest PC 0x0c0508bc */
if(!s->budget--) { s->failed_pc=0x0c0508bcu; return 0; }
r[12]+=r[10];
goto P_0c0508be;
P_0c0508be: /* original ee00, guest PC 0x0c0508be */
if(!s->budget--) { s->failed_pc=0x0c0508beu; return 0; }
r[14]=0x00000000u;
goto P_0c0508c0;
P_0c0508c0: /* original d30d, guest PC 0x0c0508c0 */
if(!s->budget--) { s->failed_pc=0x0c0508c0u; return 0; }
r[3]=read(ram,0x0c0508f8u,4);
goto P_0c0508c2;
P_0c0508c2: /* original e500, guest PC 0x0c0508c2 */
if(!s->budget--) { s->failed_pc=0x0c0508c2u; return 0; }
r[5]=0x00000000u;
goto P_0c0508c4;
P_0c0508c4: /* original 430b, guest PC 0x0c0508c4 */
if(!s->budget--) { s->failed_pc=0x0c0508c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0508c8u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0508c8u) { target=s->pc; goto dispatch; }
goto P_0c0508c8;
P_0c0508c6: /* original 64f2, guest PC 0x0c0508c6 */
if(!s->budget--) { s->failed_pc=0x0c0508c6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0508c8;
P_0c0508c8: /* original 60e3, guest PC 0x0c0508c8 */
if(!s->budget--) { s->failed_pc=0x0c0508c8u; return 0; }
r[0]=r[14];
goto P_0c0508ca;
P_0c0508ca: /* original 7f0c, guest PC 0x0c0508ca */
if(!s->budget--) { s->failed_pc=0x0c0508cau; return 0; }
r[15]+=0x0000000cu;
goto P_0c0508cc;
P_0c0508cc: /* original 4f16, guest PC 0x0c0508cc */
if(!s->budget--) { s->failed_pc=0x0c0508ccu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0508ce;
P_0c0508ce: /* original 4f26, guest PC 0x0c0508ce */
if(!s->budget--) { s->failed_pc=0x0c0508ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0508d0;
P_0c0508d0: /* original 6af6, guest PC 0x0c0508d0 */
if(!s->budget--) { s->failed_pc=0x0c0508d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0508d2;
P_0c0508d2: /* original 6bf6, guest PC 0x0c0508d2 */
if(!s->budget--) { s->failed_pc=0x0c0508d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0508d4;
P_0c0508d4: /* original 6cf6, guest PC 0x0c0508d4 */
if(!s->budget--) { s->failed_pc=0x0c0508d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0508d6;
P_0c0508d6: /* original 6df6, guest PC 0x0c0508d6 */
if(!s->budget--) { s->failed_pc=0x0c0508d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0508d8;
P_0c0508d8: /* original 000b, guest PC 0x0c0508d8 */
if(!s->budget--) { s->failed_pc=0x0c0508d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0508da: /* original 6ef6, guest PC 0x0c0508da */
if(!s->budget--) { s->failed_pc=0x0c0508dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0508dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0508dcu; return 0; } return 1;
P_0c0508fc: /* original 2fe6, guest PC 0x0c0508fc */
if(!s->budget--) { s->failed_pc=0x0c0508fcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0508fe;
P_0c0508fe: /* original 2fd6, guest PC 0x0c0508fe */
if(!s->budget--) { s->failed_pc=0x0c0508feu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050900;
P_0c050900: /* original 2fc6, guest PC 0x0c050900 */
if(!s->budget--) { s->failed_pc=0x0c050900u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050902;
P_0c050902: /* original 6c73, guest PC 0x0c050902 */
if(!s->budget--) { s->failed_pc=0x0c050902u; return 0; }
r[12]=r[7];
goto P_0c050904;
P_0c050904: /* original 2fb6, guest PC 0x0c050904 */
if(!s->budget--) { s->failed_pc=0x0c050904u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050906;
P_0c050906: /* original 2fa6, guest PC 0x0c050906 */
if(!s->budget--) { s->failed_pc=0x0c050906u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050908;
P_0c050908: /* original 2f96, guest PC 0x0c050908 */
if(!s->budget--) { s->failed_pc=0x0c050908u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05090a;
P_0c05090a: /* original 6943, guest PC 0x0c05090a */
if(!s->budget--) { s->failed_pc=0x0c05090au; return 0; }
r[9]=r[4];
goto P_0c05090c;
P_0c05090c: /* original 2f86, guest PC 0x0c05090c */
if(!s->budget--) { s->failed_pc=0x0c05090cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05090e;
P_0c05090e: /* original 4f22, guest PC 0x0c05090e */
if(!s->budget--) { s->failed_pc=0x0c05090eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050910;
P_0c050910: /* original 4f12, guest PC 0x0c050910 */
if(!s->budget--) { s->failed_pc=0x0c050910u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c050912;
P_0c050912: /* original 7ff4, guest PC 0x0c050912 */
if(!s->budget--) { s->failed_pc=0x0c050912u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c050914;
P_0c050914: /* original 1f51, guest PC 0x0c050914 */
if(!s->budget--) { s->failed_pc=0x0c050914u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c050916;
P_0c050916: /* original 67f3, guest PC 0x0c050916 */
if(!s->budget--) { s->failed_pc=0x0c050916u; return 0; }
r[7]=r[15];
goto P_0c050918;
P_0c050918: /* original 1f62, guest PC 0x0c050918 */
if(!s->budget--) { s->failed_pc=0x0c050918u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c05091a;
P_0c05091a: /* original 56fc, guest PC 0x0c05091a */
if(!s->budget--) { s->failed_pc=0x0c05091au; return 0; }
r[6]=read(ram,r[15]+48,4);
goto P_0c05091c;
P_0c05091c: /* original 55f1, guest PC 0x0c05091c */
if(!s->budget--) { s->failed_pc=0x0c05091cu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05091e;
P_0c05091e: /* original d337, guest PC 0x0c05091e */
if(!s->budget--) { s->failed_pc=0x0c05091eu; return 0; }
r[3]=read(ram,0x0c0509fcu,4);
goto P_0c050920;
P_0c050920: /* original 430b, guest PC 0x0c050920 */
if(!s->budget--) { s->failed_pc=0x0c050920u; return 0; }
target=r[3];
r[16]=code_base|0x0c050924u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050924u) { target=s->pc; goto dispatch; }
goto P_0c050924;
P_0c050922: /* original 6493, guest PC 0x0c050922 */
if(!s->budget--) { s->failed_pc=0x0c050922u; return 0; }
r[4]=r[9];
goto P_0c050924;
P_0c050924: /* original 6e03, guest PC 0x0c050924 */
if(!s->budget--) { s->failed_pc=0x0c050924u; return 0; }
r[14]=r[0];
goto P_0c050926;
P_0c050926: /* original 4e11, guest PC 0x0c050926 */
if(!s->budget--) { s->failed_pc=0x0c050926u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c050928;
P_0c050928: /* original 8b58, guest PC 0x0c050928 */
if(!s->budget--) { s->failed_pc=0x0c050928u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0509dc; }
goto P_0c05092a;
P_0c05092a: /* original 63f2, guest PC 0x0c05092a */
if(!s->budget--) { s->failed_pc=0x0c05092au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05092c;
P_0c05092c: /* original e201, guest PC 0x0c05092c */
if(!s->budget--) { s->failed_pc=0x0c05092cu; return 0; }
r[2]=0x00000001u;
goto P_0c05092e;
P_0c05092e: /* original 50fd, guest PC 0x0c05092e */
if(!s->budget--) { s->failed_pc=0x0c05092eu; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c050930;
P_0c050930: /* original 61c3, guest PC 0x0c050930 */
if(!s->budget--) { s->failed_pc=0x0c050930u; return 0; }
r[1]=r[12];
goto P_0c050932;
P_0c050932: /* original 4100, guest PC 0x0c050932 */
if(!s->budget--) { s->failed_pc=0x0c050932u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c050934;
P_0c050934: /* original 8031, guest PC 0x0c050934 */
if(!s->budget--) { s->failed_pc=0x0c050934u; return 0; }
write(ram,r[3]+1,r[0],1);
goto P_0c050936;
P_0c050936: /* original ea00, guest PC 0x0c050936 */
if(!s->budget--) { s->failed_pc=0x0c050936u; return 0; }
r[10]=0x00000000u;
goto P_0c050938;
P_0c050938: /* original 945c, guest PC 0x0c050938 */
if(!s->budget--) { s->failed_pc=0x0c050938u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0509f4u,2);
goto P_0c05093a;
P_0c05093a: /* original d331, guest PC 0x0c05093a */
if(!s->budget--) { s->failed_pc=0x0c05093au; return 0; }
r[3]=read(ram,0x0c050a00u,4);
goto P_0c05093c;
P_0c05093c: /* original 294f, guest PC 0x0c05093c */
if(!s->budget--) { s->failed_pc=0x0c05093cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[9]*(int32_t)(int16_t)r[4]);
goto P_0c05093e;
P_0c05093e: /* original 5bf2, guest PC 0x0c05093e */
if(!s->budget--) { s->failed_pc=0x0c05093eu; return 0; }
r[11]=read(ram,r[15]+8,4);
goto P_0c050940;
P_0c050940: /* original 041a, guest PC 0x0c050940 */
if(!s->budget--) { s->failed_pc=0x0c050940u; return 0; }
r[4]=r[19];
goto P_0c050942;
P_0c050942: /* original 644f, guest PC 0x0c050942 */
if(!s->budget--) { s->failed_pc=0x0c050942u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c050944;
P_0c050944: /* original 343c, guest PC 0x0c050944 */
if(!s->budget--) { s->failed_pc=0x0c050944u; return 0; }
r[4]+=r[3];
goto P_0c050946;
P_0c050946: /* original 142c, guest PC 0x0c050946 */
if(!s->budget--) { s->failed_pc=0x0c050946u; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c050948;
P_0c050948: /* original 5241, guest PC 0x0c050948 */
if(!s->budget--) { s->failed_pc=0x0c050948u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c05094a;
P_0c05094a: /* original 9d54, guest PC 0x0c05094a */
if(!s->budget--) { s->failed_pc=0x0c05094au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0509f6u,2);
goto P_0c05094c;
P_0c05094c: /* original 6023, guest PC 0x0c05094c */
if(!s->budget--) { s->failed_pc=0x0c05094cu; return 0; }
r[0]=r[2];
goto P_0c05094e;
P_0c05094e: /* original 4208, guest PC 0x0c05094e */
if(!s->budget--) { s->failed_pc=0x0c05094eu; return 0; }
r[2]<<=2;
goto P_0c050950;
P_0c050950: /* original 320c, guest PC 0x0c050950 */
if(!s->budget--) { s->failed_pc=0x0c050950u; return 0; }
r[2]+=r[0];
goto P_0c050952;
P_0c050952: /* original d02c, guest PC 0x0c050952 */
if(!s->budget--) { s->failed_pc=0x0c050952u; return 0; }
r[0]=read(ram,0x0c050a04u,4);
goto P_0c050954;
P_0c050954: /* original 4208, guest PC 0x0c050954 */
if(!s->budget--) { s->failed_pc=0x0c050954u; return 0; }
r[2]<<=2;
goto P_0c050956;
P_0c050956: /* original 4208, guest PC 0x0c050956 */
if(!s->budget--) { s->failed_pc=0x0c050956u; return 0; }
r[2]<<=2;
goto P_0c050958;
P_0c050958: /* original 622f, guest PC 0x0c050958 */
if(!s->budget--) { s->failed_pc=0x0c050958u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c05095a;
P_0c05095a: /* original 022e, guest PC 0x0c05095a */
if(!s->budget--) { s->failed_pc=0x0c05095au; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c05095c;
P_0c05095c: /* original 312c, guest PC 0x0c05095c */
if(!s->budget--) { s->failed_pc=0x0c05095cu; return 0; }
r[1]+=r[2];
goto P_0c05095e;
P_0c05095e: /* original 62a3, guest PC 0x0c05095e */
if(!s->budget--) { s->failed_pc=0x0c05095eu; return 0; }
r[2]=r[10];
goto P_0c050960;
P_0c050960: /* original 32c2, guest PC 0x0c050960 */
if(!s->budget--) { s->failed_pc=0x0c050960u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[12])!=0);
goto P_0c050962;
P_0c050962: /* original 8d0b, guest PC 0x0c050962 */
if(!s->budget--) { s->failed_pc=0x0c050962u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+52,r[1],4);
if(cond) { goto P_0c05097c; }
goto P_0c050966;
P_0c050964: /* original 141d, guest PC 0x0c050964 */
if(!s->budget--) { s->failed_pc=0x0c050964u; return 0; }
write(ram,r[4]+52,r[1],4);
goto P_0c050966;
P_0c050966: /* original d328, guest PC 0x0c050966 */
if(!s->budget--) { s->failed_pc=0x0c050966u; return 0; }
r[3]=read(ram,0x0c050a08u,4);
goto P_0c050968;
P_0c050968: /* original 65b3, guest PC 0x0c050968 */
if(!s->budget--) { s->failed_pc=0x0c050968u; return 0; }
r[5]=r[11];
goto P_0c05096a;
P_0c05096a: /* original 430b, guest PC 0x0c05096a */
if(!s->budget--) { s->failed_pc=0x0c05096au; return 0; }
target=r[3];
r[16]=code_base|0x0c05096eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05096eu) { target=s->pc; goto dispatch; }
goto P_0c05096e;
P_0c05096c: /* original 64f2, guest PC 0x0c05096c */
if(!s->budget--) { s->failed_pc=0x0c05096cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c05096e;
P_0c05096e: /* original 6e03, guest PC 0x0c05096e */
if(!s->budget--) { s->failed_pc=0x0c05096eu; return 0; }
r[14]=r[0];
goto P_0c050970;
P_0c050970: /* original 4e11, guest PC 0x0c050970 */
if(!s->budget--) { s->failed_pc=0x0c050970u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c050972;
P_0c050972: /* original 8b2f, guest PC 0x0c050972 */
if(!s->budget--) { s->failed_pc=0x0c050972u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0509d4; }
goto P_0c050974;
P_0c050974: /* original 7a01, guest PC 0x0c050974 */
if(!s->budget--) { s->failed_pc=0x0c050974u; return 0; }
r[10]+=0x00000001u;
goto P_0c050976;
P_0c050976: /* original 3ac2, guest PC 0x0c050976 */
if(!s->budget--) { s->failed_pc=0x0c050976u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[12])!=0);
goto P_0c050978;
P_0c050978: /* original 8ff5, guest PC 0x0c050978 */
if(!s->budget--) { s->failed_pc=0x0c050978u; return 0; }
cond=r[17]&1u;
r[11]+=r[13];
if(!cond) { goto P_0c050966; }
goto P_0c05097c;
P_0c05097a: /* original 3bdc, guest PC 0x0c05097a */
if(!s->budget--) { s->failed_pc=0x0c05097au; return 0; }
r[11]+=r[13];
goto P_0c05097c;
P_0c05097c: /* original d323, guest PC 0x0c05097c */
if(!s->budget--) { s->failed_pc=0x0c05097cu; return 0; }
r[3]=read(ram,0x0c050a0cu,4);
goto P_0c05097e;
P_0c05097e: /* original e500, guest PC 0x0c05097e */
if(!s->budget--) { s->failed_pc=0x0c05097eu; return 0; }
r[5]=0x00000000u;
goto P_0c050980;
P_0c050980: /* original 430b, guest PC 0x0c050980 */
if(!s->budget--) { s->failed_pc=0x0c050980u; return 0; }
target=r[3];
r[16]=code_base|0x0c050984u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050984u) { target=s->pc; goto dispatch; }
goto P_0c050984;
P_0c050982: /* original 64f2, guest PC 0x0c050982 */
if(!s->budget--) { s->failed_pc=0x0c050982u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c050984;
P_0c050984: /* original d322, guest PC 0x0c050984 */
if(!s->budget--) { s->failed_pc=0x0c050984u; return 0; }
r[3]=read(ram,0x0c050a10u,4);
goto P_0c050986;
P_0c050986: /* original 66f3, guest PC 0x0c050986 */
if(!s->budget--) { s->failed_pc=0x0c050986u; return 0; }
r[6]=r[15];
goto P_0c050988;
P_0c050988: /* original 55f1, guest PC 0x0c050988 */
if(!s->budget--) { s->failed_pc=0x0c050988u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05098a;
P_0c05098a: /* original 430b, guest PC 0x0c05098a */
if(!s->budget--) { s->failed_pc=0x0c05098au; return 0; }
target=r[3];
r[16]=code_base|0x0c05098eu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05098eu) { target=s->pc; goto dispatch; }
goto P_0c05098e;
P_0c05098c: /* original 6493, guest PC 0x0c05098c */
if(!s->budget--) { s->failed_pc=0x0c05098cu; return 0; }
r[4]=r[9];
goto P_0c05098e;
P_0c05098e: /* original 6e03, guest PC 0x0c05098e */
if(!s->budget--) { s->failed_pc=0x0c05098eu; return 0; }
r[14]=r[0];
goto P_0c050990;
P_0c050990: /* original 4e11, guest PC 0x0c050990 */
if(!s->budget--) { s->failed_pc=0x0c050990u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c050992;
P_0c050992: /* original 8b23, guest PC 0x0c050992 */
if(!s->budget--) { s->failed_pc=0x0c050992u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0509dc; }
goto P_0c050994;
P_0c050994: /* original 6893, guest PC 0x0c050994 */
if(!s->budget--) { s->failed_pc=0x0c050994u; return 0; }
r[8]=r[9];
goto P_0c050996;
P_0c050996: /* original 4818, guest PC 0x0c050996 */
if(!s->budget--) { s->failed_pc=0x0c050996u; return 0; }
r[8]<<=8;
goto P_0c050998;
P_0c050998: /* original eb00, guest PC 0x0c050998 */
if(!s->budget--) { s->failed_pc=0x0c050998u; return 0; }
r[11]=0x00000000u;
goto P_0c05099a;
P_0c05099a: /* original d31e, guest PC 0x0c05099a */
if(!s->budget--) { s->failed_pc=0x0c05099au; return 0; }
r[3]=read(ram,0x0c050a14u,4);
goto P_0c05099c;
P_0c05099c: /* original 62b3, guest PC 0x0c05099c */
if(!s->budget--) { s->failed_pc=0x0c05099cu; return 0; }
r[2]=r[11];
goto P_0c05099e;
P_0c05099e: /* original 5af2, guest PC 0x0c05099e */
if(!s->budget--) { s->failed_pc=0x0c05099eu; return 0; }
r[10]=read(ram,r[15]+8,4);
goto P_0c0509a0;
P_0c0509a0: /* original 4808, guest PC 0x0c0509a0 */
if(!s->budget--) { s->failed_pc=0x0c0509a0u; return 0; }
r[8]<<=2;
goto P_0c0509a2;
P_0c0509a2: /* original 4800, guest PC 0x0c0509a2 */
if(!s->budget--) { s->failed_pc=0x0c0509a2u; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c0509a4;
P_0c0509a4: /* original 32c2, guest PC 0x0c0509a4 */
if(!s->budget--) { s->failed_pc=0x0c0509a4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[12])!=0);
goto P_0c0509a6;
P_0c0509a6: /* original 8d14, guest PC 0x0c0509a6 */
if(!s->budget--) { s->failed_pc=0x0c0509a6u; return 0; }
cond=r[17]&1u;
r[8]+=r[3];
if(cond) { goto P_0c0509d2; }
goto P_0c0509aa;
P_0c0509a8: /* original 383c, guest PC 0x0c0509a8 */
if(!s->budget--) { s->failed_pc=0x0c0509a8u; return 0; }
r[8]+=r[3];
goto P_0c0509aa;
P_0c0509aa: /* original 9925, guest PC 0x0c0509aa */
if(!s->budget--) { s->failed_pc=0x0c0509aau; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0509f8u,2);
goto P_0c0509ac;
P_0c0509ac: /* original d31a, guest PC 0x0c0509ac */
if(!s->budget--) { s->failed_pc=0x0c0509acu; return 0; }
r[3]=read(ram,0x0c050a18u,4);
goto P_0c0509ae;
P_0c0509ae: /* original 6583, guest PC 0x0c0509ae */
if(!s->budget--) { s->failed_pc=0x0c0509aeu; return 0; }
r[5]=r[8];
goto P_0c0509b0;
P_0c0509b0: /* original 430b, guest PC 0x0c0509b0 */
if(!s->budget--) { s->failed_pc=0x0c0509b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0509b4u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0509b4u) { target=s->pc; goto dispatch; }
goto P_0c0509b4;
P_0c0509b2: /* original 64f2, guest PC 0x0c0509b2 */
if(!s->budget--) { s->failed_pc=0x0c0509b2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0509b4;
P_0c0509b4: /* original 6e03, guest PC 0x0c0509b4 */
if(!s->budget--) { s->failed_pc=0x0c0509b4u; return 0; }
r[14]=r[0];
goto P_0c0509b6;
P_0c0509b6: /* original 4e11, guest PC 0x0c0509b6 */
if(!s->budget--) { s->failed_pc=0x0c0509b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0509b8;
P_0c0509b8: /* original 8b0c, guest PC 0x0c0509b8 */
if(!s->budget--) { s->failed_pc=0x0c0509b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0509d4; }
goto P_0c0509ba;
P_0c0509ba: /* original d218, guest PC 0x0c0509ba */
if(!s->budget--) { s->failed_pc=0x0c0509bau; return 0; }
r[2]=read(ram,0x0c050a1cu,4);
goto P_0c0509bc;
P_0c0509bc: /* original 65a3, guest PC 0x0c0509bc */
if(!s->budget--) { s->failed_pc=0x0c0509bcu; return 0; }
r[5]=r[10];
goto P_0c0509be;
P_0c0509be: /* original 420b, guest PC 0x0c0509be */
if(!s->budget--) { s->failed_pc=0x0c0509beu; return 0; }
target=r[2];
r[16]=code_base|0x0c0509c2u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0509c2u) { target=s->pc; goto dispatch; }
goto P_0c0509c2;
P_0c0509c0: /* original 6483, guest PC 0x0c0509c0 */
if(!s->budget--) { s->failed_pc=0x0c0509c0u; return 0; }
r[4]=r[8];
goto P_0c0509c2;
P_0c0509c2: /* original 2008, guest PC 0x0c0509c2 */
if(!s->budget--) { s->failed_pc=0x0c0509c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0509c4;
P_0c0509c4: /* original 8901, guest PC 0x0c0509c4 */
if(!s->budget--) { s->failed_pc=0x0c0509c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0509ca; }
goto P_0c0509c6;
P_0c0509c6: /* original a005, guest PC 0x0c0509c6 */
if(!s->budget--) { s->failed_pc=0x0c0509c6u; return 0; }
r[14]=r[9];
goto P_0c0509d4;
P_0c0509c8: /* original 6e93, guest PC 0x0c0509c8 */
if(!s->budget--) { s->failed_pc=0x0c0509c8u; return 0; }
r[14]=r[9];
goto P_0c0509ca;
P_0c0509ca: /* original 7b01, guest PC 0x0c0509ca */
if(!s->budget--) { s->failed_pc=0x0c0509cau; return 0; }
r[11]+=0x00000001u;
goto P_0c0509cc;
P_0c0509cc: /* original 3bc2, guest PC 0x0c0509cc */
if(!s->budget--) { s->failed_pc=0x0c0509ccu; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[12])!=0);
goto P_0c0509ce;
P_0c0509ce: /* original 8fed, guest PC 0x0c0509ce */
if(!s->budget--) { s->failed_pc=0x0c0509ceu; return 0; }
cond=r[17]&1u;
r[10]+=r[13];
if(!cond) { goto P_0c0509ac; }
goto P_0c0509d2;
P_0c0509d0: /* original 3adc, guest PC 0x0c0509d0 */
if(!s->budget--) { s->failed_pc=0x0c0509d0u; return 0; }
r[10]+=r[13];
goto P_0c0509d2;
P_0c0509d2: /* original ee00, guest PC 0x0c0509d2 */
if(!s->budget--) { s->failed_pc=0x0c0509d2u; return 0; }
r[14]=0x00000000u;
goto P_0c0509d4;
P_0c0509d4: /* original d30d, guest PC 0x0c0509d4 */
if(!s->budget--) { s->failed_pc=0x0c0509d4u; return 0; }
r[3]=read(ram,0x0c050a0cu,4);
goto P_0c0509d6;
P_0c0509d6: /* original e500, guest PC 0x0c0509d6 */
if(!s->budget--) { s->failed_pc=0x0c0509d6u; return 0; }
r[5]=0x00000000u;
goto P_0c0509d8;
P_0c0509d8: /* original 430b, guest PC 0x0c0509d8 */
if(!s->budget--) { s->failed_pc=0x0c0509d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0509dcu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0509dcu) { target=s->pc; goto dispatch; }
goto P_0c0509dc;
P_0c0509da: /* original 64f2, guest PC 0x0c0509da */
if(!s->budget--) { s->failed_pc=0x0c0509dau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0509dc;
P_0c0509dc: /* original 7f0c, guest PC 0x0c0509dc */
if(!s->budget--) { s->failed_pc=0x0c0509dcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0509de;
P_0c0509de: /* original 60e3, guest PC 0x0c0509de */
if(!s->budget--) { s->failed_pc=0x0c0509deu; return 0; }
r[0]=r[14];
goto P_0c0509e0;
P_0c0509e0: /* original 4f16, guest PC 0x0c0509e0 */
if(!s->budget--) { s->failed_pc=0x0c0509e0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0509e2;
P_0c0509e2: /* original 4f26, guest PC 0x0c0509e2 */
if(!s->budget--) { s->failed_pc=0x0c0509e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0509e4;
P_0c0509e4: /* original 68f6, guest PC 0x0c0509e4 */
if(!s->budget--) { s->failed_pc=0x0c0509e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0509e6;
P_0c0509e6: /* original 69f6, guest PC 0x0c0509e6 */
if(!s->budget--) { s->failed_pc=0x0c0509e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0509e8;
P_0c0509e8: /* original 6af6, guest PC 0x0c0509e8 */
if(!s->budget--) { s->failed_pc=0x0c0509e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0509ea;
P_0c0509ea: /* original 6bf6, guest PC 0x0c0509ea */
if(!s->budget--) { s->failed_pc=0x0c0509eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0509ec;
P_0c0509ec: /* original 6cf6, guest PC 0x0c0509ec */
if(!s->budget--) { s->failed_pc=0x0c0509ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0509ee;
P_0c0509ee: /* original 6df6, guest PC 0x0c0509ee */
if(!s->budget--) { s->failed_pc=0x0c0509eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0509f0;
P_0c0509f0: /* original 000b, guest PC 0x0c0509f0 */
if(!s->budget--) { s->failed_pc=0x0c0509f0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0509f2: /* original 6ef6, guest PC 0x0c0509f2 */
if(!s->budget--) { s->failed_pc=0x0c0509f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0509f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0509f4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
