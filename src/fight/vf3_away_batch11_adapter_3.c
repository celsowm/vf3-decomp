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
int vf3_away_batch11_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03e8c0u: goto P_0c03e8c0;
case 0x0c03e8c2u: goto P_0c03e8c2;
case 0x0c03e8c4u: goto P_0c03e8c4;
case 0x0c03e8c6u: goto P_0c03e8c6;
case 0x0c03e8c8u: goto P_0c03e8c8;
case 0x0c03e8cau: goto P_0c03e8ca;
case 0x0c03e8ccu: goto P_0c03e8cc;
case 0x0c03e8ceu: goto P_0c03e8ce;
case 0x0c03e8d0u: goto P_0c03e8d0;
case 0x0c03e8d2u: goto P_0c03e8d2;
case 0x0c03e8d4u: goto P_0c03e8d4;
case 0x0c03e8d6u: goto P_0c03e8d6;
case 0x0c03e8d8u: goto P_0c03e8d8;
case 0x0c03e8dau: goto P_0c03e8da;
case 0x0c03e8dcu: goto P_0c03e8dc;
case 0x0c03e8deu: goto P_0c03e8de;
case 0x0c03e8e0u: goto P_0c03e8e0;
case 0x0c03e8e2u: goto P_0c03e8e2;
case 0x0c03e8e4u: goto P_0c03e8e4;
case 0x0c03e8e6u: goto P_0c03e8e6;
case 0x0c03e8e8u: goto P_0c03e8e8;
case 0x0c03e8eau: goto P_0c03e8ea;
case 0x0c03e8ecu: goto P_0c03e8ec;
case 0x0c03e8eeu: goto P_0c03e8ee;
case 0x0c03e8f0u: goto P_0c03e8f0;
case 0x0c03e8f2u: goto P_0c03e8f2;
case 0x0c03e8f4u: goto P_0c03e8f4;
case 0x0c03e8f6u: goto P_0c03e8f6;
case 0x0c03e8f8u: goto P_0c03e8f8;
case 0x0c03e8fau: goto P_0c03e8fa;
case 0x0c03e8fcu: goto P_0c03e8fc;
case 0x0c03e8feu: goto P_0c03e8fe;
case 0x0c03e900u: goto P_0c03e900;
case 0x0c03e902u: goto P_0c03e902;
case 0x0c03e904u: goto P_0c03e904;
case 0x0c03e906u: goto P_0c03e906;
case 0x0c03e908u: goto P_0c03e908;
case 0x0c03e90au: goto P_0c03e90a;
case 0x0c03e90cu: goto P_0c03e90c;
case 0x0c03e90eu: goto P_0c03e90e;
case 0x0c03e910u: goto P_0c03e910;
case 0x0c03e912u: goto P_0c03e912;
case 0x0c03e914u: goto P_0c03e914;
case 0x0c03e916u: goto P_0c03e916;
case 0x0c03e918u: goto P_0c03e918;
case 0x0c03e91au: goto P_0c03e91a;
case 0x0c03e91cu: goto P_0c03e91c;
case 0x0c03e91eu: goto P_0c03e91e;
case 0x0c03e920u: goto P_0c03e920;
case 0x0c03e922u: goto P_0c03e922;
case 0x0c03e924u: goto P_0c03e924;
case 0x0c03e926u: goto P_0c03e926;
case 0x0c03e928u: goto P_0c03e928;
case 0x0c03e92au: goto P_0c03e92a;
case 0x0c03e92cu: goto P_0c03e92c;
case 0x0c03e92eu: goto P_0c03e92e;
case 0x0c03e930u: goto P_0c03e930;
case 0x0c03e932u: goto P_0c03e932;
case 0x0c03e934u: goto P_0c03e934;
case 0x0c03e936u: goto P_0c03e936;
case 0x0c03e938u: goto P_0c03e938;
case 0x0c03e93au: goto P_0c03e93a;
case 0x0c03e93cu: goto P_0c03e93c;
case 0x0c03e93eu: goto P_0c03e93e;
case 0x0c03e940u: goto P_0c03e940;
case 0x0c03e942u: goto P_0c03e942;
case 0x0c03e944u: goto P_0c03e944;
case 0x0c03e946u: goto P_0c03e946;
case 0x0c03e948u: goto P_0c03e948;
case 0x0c03e94au: goto P_0c03e94a;
case 0x0c03e94cu: goto P_0c03e94c;
case 0x0c03e94eu: goto P_0c03e94e;
case 0x0c03e950u: goto P_0c03e950;
case 0x0c03e952u: goto P_0c03e952;
case 0x0c03e954u: goto P_0c03e954;
case 0x0c03e956u: goto P_0c03e956;
case 0x0c03e958u: goto P_0c03e958;
case 0x0c03e95au: goto P_0c03e95a;
case 0x0c03e95cu: goto P_0c03e95c;
case 0x0c03e95eu: goto P_0c03e95e;
case 0x0c03e960u: goto P_0c03e960;
case 0x0c03e962u: goto P_0c03e962;
case 0x0c03e964u: goto P_0c03e964;
case 0x0c03e966u: goto P_0c03e966;
case 0x0c03e968u: goto P_0c03e968;
case 0x0c03e96au: goto P_0c03e96a;
case 0x0c03e96cu: goto P_0c03e96c;
case 0x0c03e96eu: goto P_0c03e96e;
case 0x0c03e970u: goto P_0c03e970;
case 0x0c03e972u: goto P_0c03e972;
case 0x0c03e974u: goto P_0c03e974;
case 0x0c03e976u: goto P_0c03e976;
case 0x0c03f5a0u: goto P_0c03f5a0;
case 0x0c03f5a2u: goto P_0c03f5a2;
case 0x0c03f5a4u: goto P_0c03f5a4;
case 0x0c03f5a6u: goto P_0c03f5a6;
case 0x0c03f5a8u: goto P_0c03f5a8;
case 0x0c03f5aau: goto P_0c03f5aa;
case 0x0c03f5acu: goto P_0c03f5ac;
case 0x0c03f5aeu: goto P_0c03f5ae;
case 0x0c03f5b0u: goto P_0c03f5b0;
case 0x0c03f5b2u: goto P_0c03f5b2;
case 0x0c03f5b4u: goto P_0c03f5b4;
case 0x0c03f5b6u: goto P_0c03f5b6;
case 0x0c03f5b8u: goto P_0c03f5b8;
case 0x0c03f5bau: goto P_0c03f5ba;
case 0x0c03f5bcu: goto P_0c03f5bc;
case 0x0c03f5beu: goto P_0c03f5be;
case 0x0c03f5c0u: goto P_0c03f5c0;
case 0x0c03f5c2u: goto P_0c03f5c2;
case 0x0c03f5d0u: goto P_0c03f5d0;
case 0x0c03f5d2u: goto P_0c03f5d2;
case 0x0c03f5d4u: goto P_0c03f5d4;
case 0x0c03f5d6u: goto P_0c03f5d6;
case 0x0c03f5d8u: goto P_0c03f5d8;
case 0x0c03f5dau: goto P_0c03f5da;
case 0x0c03f5dcu: goto P_0c03f5dc;
case 0x0c03f5deu: goto P_0c03f5de;
case 0x0c03f5e0u: goto P_0c03f5e0;
case 0x0c03f5e2u: goto P_0c03f5e2;
case 0x0c03f5e4u: goto P_0c03f5e4;
case 0x0c03f5e6u: goto P_0c03f5e6;
case 0x0c03f5e8u: goto P_0c03f5e8;
case 0x0c03f5eau: goto P_0c03f5ea;
case 0x0c03f5ecu: goto P_0c03f5ec;
case 0x0c03f5eeu: goto P_0c03f5ee;
case 0x0c03f5f0u: goto P_0c03f5f0;
case 0x0c03f5f2u: goto P_0c03f5f2;
case 0x0c03f5f4u: goto P_0c03f5f4;
case 0x0c03f5f6u: goto P_0c03f5f6;
case 0x0c03f5f8u: goto P_0c03f5f8;
case 0x0c03f5fau: goto P_0c03f5fa;
case 0x0c03f5fcu: goto P_0c03f5fc;
case 0x0c03f5feu: goto P_0c03f5fe;
case 0x0c03f600u: goto P_0c03f600;
case 0x0c03f602u: goto P_0c03f602;
case 0x0c03f604u: goto P_0c03f604;
case 0x0c03f606u: goto P_0c03f606;
case 0x0c03f608u: goto P_0c03f608;
case 0x0c03f60au: goto P_0c03f60a;
case 0x0c03f60cu: goto P_0c03f60c;
case 0x0c03f60eu: goto P_0c03f60e;
case 0x0c03f610u: goto P_0c03f610;
case 0x0c03f612u: goto P_0c03f612;
case 0x0c03f614u: goto P_0c03f614;
case 0x0c03f616u: goto P_0c03f616;
case 0x0c03f618u: goto P_0c03f618;
case 0x0c03f61au: goto P_0c03f61a;
case 0x0c03f61cu: goto P_0c03f61c;
case 0x0c03f61eu: goto P_0c03f61e;
case 0x0c03f620u: goto P_0c03f620;
case 0x0c03f622u: goto P_0c03f622;
case 0x0c03f624u: goto P_0c03f624;
case 0x0c03f626u: goto P_0c03f626;
case 0x0c03f628u: goto P_0c03f628;
case 0x0c03f62au: goto P_0c03f62a;
case 0x0c03f62cu: goto P_0c03f62c;
case 0x0c03f62eu: goto P_0c03f62e;
case 0x0c03f630u: goto P_0c03f630;
case 0x0c03f632u: goto P_0c03f632;
case 0x0c03f634u: goto P_0c03f634;
case 0x0c03f636u: goto P_0c03f636;
case 0x0c03f638u: goto P_0c03f638;
case 0x0c03f63au: goto P_0c03f63a;
case 0x0c03f63cu: goto P_0c03f63c;
case 0x0c03f63eu: goto P_0c03f63e;
case 0x0c03f640u: goto P_0c03f640;
case 0x0c03f642u: goto P_0c03f642;
case 0x0c03f644u: goto P_0c03f644;
case 0x0c03f646u: goto P_0c03f646;
case 0x0c03f648u: goto P_0c03f648;
case 0x0c03f64au: goto P_0c03f64a;
case 0x0c03f64cu: goto P_0c03f64c;
case 0x0c03f64eu: goto P_0c03f64e;
case 0x0c03f650u: goto P_0c03f650;
case 0x0c03f652u: goto P_0c03f652;
case 0x0c03f654u: goto P_0c03f654;
case 0x0c03f656u: goto P_0c03f656;
case 0x0c03f658u: goto P_0c03f658;
case 0x0c03f65au: goto P_0c03f65a;
case 0x0c03f65cu: goto P_0c03f65c;
case 0x0c03f65eu: goto P_0c03f65e;
case 0x0c03f660u: goto P_0c03f660;
case 0x0c03f662u: goto P_0c03f662;
case 0x0c03f664u: goto P_0c03f664;
case 0x0c03f666u: goto P_0c03f666;
case 0x0c03f668u: goto P_0c03f668;
case 0x0c03f66au: goto P_0c03f66a;
case 0x0c03f66cu: goto P_0c03f66c;
case 0x0c03f66eu: goto P_0c03f66e;
case 0x0c03f670u: goto P_0c03f670;
case 0x0c03f672u: goto P_0c03f672;
case 0x0c03f674u: goto P_0c03f674;
case 0x0c03f676u: goto P_0c03f676;
case 0x0c03f678u: goto P_0c03f678;
case 0x0c03f67au: goto P_0c03f67a;
case 0x0c03f67cu: goto P_0c03f67c;
case 0x0c03f67eu: goto P_0c03f67e;
case 0x0c03f680u: goto P_0c03f680;
case 0x0c03f682u: goto P_0c03f682;
case 0x0c03f684u: goto P_0c03f684;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03e8c0: /* original 2fe6, guest PC 0x0c03e8c0 */
if(!s->budget--) { s->failed_pc=0x0c03e8c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8c2;
P_0c03e8c2: /* original 2fd6, guest PC 0x0c03e8c2 */
if(!s->budget--) { s->failed_pc=0x0c03e8c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8c4;
P_0c03e8c4: /* original 2fc6, guest PC 0x0c03e8c4 */
if(!s->budget--) { s->failed_pc=0x0c03e8c4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8c6;
P_0c03e8c6: /* original 2fb6, guest PC 0x0c03e8c6 */
if(!s->budget--) { s->failed_pc=0x0c03e8c6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8c8;
P_0c03e8c8: /* original 2fa6, guest PC 0x0c03e8c8 */
if(!s->budget--) { s->failed_pc=0x0c03e8c8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e8ca;
P_0c03e8ca: /* original 4f22, guest PC 0x0c03e8ca */
if(!s->budget--) { s->failed_pc=0x0c03e8cau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e8cc;
P_0c03e8cc: /* original d344, guest PC 0x0c03e8cc */
if(!s->budget--) { s->failed_pc=0x0c03e8ccu; return 0; }
r[3]=read(ram,0x0c03e9e0u,4);
goto P_0c03e8ce;
P_0c03e8ce: /* original 430b, guest PC 0x0c03e8ce */
if(!s->budget--) { s->failed_pc=0x0c03e8ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c03e8d2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e8d2u) { target=s->pc; goto dispatch; }
goto P_0c03e8d2;
P_0c03e8d0: /* original e400, guest PC 0x0c03e8d0 */
if(!s->budget--) { s->failed_pc=0x0c03e8d0u; return 0; }
r[4]=0x00000000u;
goto P_0c03e8d2;
P_0c03e8d2: /* original d244, guest PC 0x0c03e8d2 */
if(!s->budget--) { s->failed_pc=0x0c03e8d2u; return 0; }
r[2]=read(ram,0x0c03e9e4u,4);
goto P_0c03e8d4;
P_0c03e8d4: /* original 420b, guest PC 0x0c03e8d4 */
if(!s->budget--) { s->failed_pc=0x0c03e8d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c03e8d8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e8d8u) { target=s->pc; goto dispatch; }
goto P_0c03e8d8;
P_0c03e8d6: /* original 0009, guest PC 0x0c03e8d6 */
if(!s->budget--) { s->failed_pc=0x0c03e8d6u; return 0; }
goto P_0c03e8d8;
P_0c03e8d8: /* original dc44, guest PC 0x0c03e8d8 */
if(!s->budget--) { s->failed_pc=0x0c03e8d8u; return 0; }
r[12]=read(ram,0x0c03e9ecu,4);
goto P_0c03e8da;
P_0c03e8da: /* original eb00, guest PC 0x0c03e8da */
if(!s->budget--) { s->failed_pc=0x0c03e8dau; return 0; }
r[11]=0x00000000u;
goto P_0c03e8dc;
P_0c03e8dc: /* original de42, guest PC 0x0c03e8dc */
if(!s->budget--) { s->failed_pc=0x0c03e8dcu; return 0; }
r[14]=read(ram,0x0c03e9e8u,4);
goto P_0c03e8de;
P_0c03e8de: /* original ea10, guest PC 0x0c03e8de */
if(!s->budget--) { s->failed_pc=0x0c03e8deu; return 0; }
r[10]=0x00000010u;
goto P_0c03e8e0;
P_0c03e8e0: /* original dd43, guest PC 0x0c03e8e0 */
if(!s->budget--) { s->failed_pc=0x0c03e8e0u; return 0; }
r[13]=read(ram,0x0c03e9f0u,4);
goto P_0c03e8e2;
P_0c03e8e2: /* original 63e1, guest PC 0x0c03e8e2 */
if(!s->budget--) { s->failed_pc=0x0c03e8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c03e8e4;
P_0c03e8e4: /* original 2338, guest PC 0x0c03e8e4 */
if(!s->budget--) { s->failed_pc=0x0c03e8e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03e8e6;
P_0c03e8e6: /* original 8909, guest PC 0x0c03e8e6 */
if(!s->budget--) { s->failed_pc=0x0c03e8e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e8fc; }
goto P_0c03e8e8;
P_0c03e8e8: /* original 9577, guest PC 0x0c03e8e8 */
if(!s->budget--) { s->failed_pc=0x0c03e8e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e8ea;
P_0c03e8ea: /* original 64e3, guest PC 0x0c03e8ea */
if(!s->budget--) { s->failed_pc=0x0c03e8eau; return 0; }
r[4]=r[14];
goto P_0c03e8ec;
P_0c03e8ec: /* original 35ec, guest PC 0x0c03e8ec */
if(!s->budget--) { s->failed_pc=0x0c03e8ecu; return 0; }
r[5]+=r[14];
goto P_0c03e8ee;
P_0c03e8ee: /* original 4c0b, guest PC 0x0c03e8ee */
if(!s->budget--) { s->failed_pc=0x0c03e8eeu; return 0; }
target=r[12];
r[16]=code_base|0x0c03e8f2u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e8f2u) { target=s->pc; goto dispatch; }
goto P_0c03e8f2;
P_0c03e8f0: /* original 7468, guest PC 0x0c03e8f0 */
if(!s->budget--) { s->failed_pc=0x0c03e8f0u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e8f2;
P_0c03e8f2: /* original 65e3, guest PC 0x0c03e8f2 */
if(!s->budget--) { s->failed_pc=0x0c03e8f2u; return 0; }
r[5]=r[14];
goto P_0c03e8f4;
P_0c03e8f4: /* original 64e3, guest PC 0x0c03e8f4 */
if(!s->budget--) { s->failed_pc=0x0c03e8f4u; return 0; }
r[4]=r[14];
goto P_0c03e8f6;
P_0c03e8f6: /* original 7574, guest PC 0x0c03e8f6 */
if(!s->budget--) { s->failed_pc=0x0c03e8f6u; return 0; }
r[5]+=0x00000074u;
goto P_0c03e8f8;
P_0c03e8f8: /* original 4d0b, guest PC 0x0c03e8f8 */
if(!s->budget--) { s->failed_pc=0x0c03e8f8u; return 0; }
target=r[13];
r[16]=code_base|0x0c03e8fcu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e8fcu) { target=s->pc; goto dispatch; }
goto P_0c03e8fc;
P_0c03e8fa: /* original 745c, guest PC 0x0c03e8fa */
if(!s->budget--) { s->failed_pc=0x0c03e8fau; return 0; }
r[4]+=0x0000005cu;
goto P_0c03e8fc;
P_0c03e8fc: /* original 936e, guest PC 0x0c03e8fc */
if(!s->budget--) { s->failed_pc=0x0c03e8fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dcu,2);
goto P_0c03e8fe;
P_0c03e8fe: /* original 3e3c, guest PC 0x0c03e8fe */
if(!s->budget--) { s->failed_pc=0x0c03e8feu; return 0; }
r[14]+=r[3];
goto P_0c03e900;
P_0c03e900: /* original 62e1, guest PC 0x0c03e900 */
if(!s->budget--) { s->failed_pc=0x0c03e900u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c03e902;
P_0c03e902: /* original 2228, guest PC 0x0c03e902 */
if(!s->budget--) { s->failed_pc=0x0c03e902u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e904;
P_0c03e904: /* original 8d0a, guest PC 0x0c03e904 */
if(!s->budget--) { s->failed_pc=0x0c03e904u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(cond) { goto P_0c03e91c; }
goto P_0c03e908;
P_0c03e906: /* original 7b01, guest PC 0x0c03e906 */
if(!s->budget--) { s->failed_pc=0x0c03e906u; return 0; }
r[11]+=0x00000001u;
goto P_0c03e908;
P_0c03e908: /* original 9567, guest PC 0x0c03e908 */
if(!s->budget--) { s->failed_pc=0x0c03e908u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e90a;
P_0c03e90a: /* original 64e3, guest PC 0x0c03e90a */
if(!s->budget--) { s->failed_pc=0x0c03e90au; return 0; }
r[4]=r[14];
goto P_0c03e90c;
P_0c03e90c: /* original 35ec, guest PC 0x0c03e90c */
if(!s->budget--) { s->failed_pc=0x0c03e90cu; return 0; }
r[5]+=r[14];
goto P_0c03e90e;
P_0c03e90e: /* original 4c0b, guest PC 0x0c03e90e */
if(!s->budget--) { s->failed_pc=0x0c03e90eu; return 0; }
target=r[12];
r[16]=code_base|0x0c03e912u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e912u) { target=s->pc; goto dispatch; }
goto P_0c03e912;
P_0c03e910: /* original 7468, guest PC 0x0c03e910 */
if(!s->budget--) { s->failed_pc=0x0c03e910u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e912;
P_0c03e912: /* original 65e3, guest PC 0x0c03e912 */
if(!s->budget--) { s->failed_pc=0x0c03e912u; return 0; }
r[5]=r[14];
goto P_0c03e914;
P_0c03e914: /* original 64e3, guest PC 0x0c03e914 */
if(!s->budget--) { s->failed_pc=0x0c03e914u; return 0; }
r[4]=r[14];
goto P_0c03e916;
P_0c03e916: /* original 7574, guest PC 0x0c03e916 */
if(!s->budget--) { s->failed_pc=0x0c03e916u; return 0; }
r[5]+=0x00000074u;
goto P_0c03e918;
P_0c03e918: /* original 4d0b, guest PC 0x0c03e918 */
if(!s->budget--) { s->failed_pc=0x0c03e918u; return 0; }
target=r[13];
r[16]=code_base|0x0c03e91cu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e91cu) { target=s->pc; goto dispatch; }
goto P_0c03e91c;
P_0c03e91a: /* original 745c, guest PC 0x0c03e91a */
if(!s->budget--) { s->failed_pc=0x0c03e91au; return 0; }
r[4]+=0x0000005cu;
goto P_0c03e91c;
P_0c03e91c: /* original 935e, guest PC 0x0c03e91c */
if(!s->budget--) { s->failed_pc=0x0c03e91cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dcu,2);
goto P_0c03e91e;
P_0c03e91e: /* original 3e3c, guest PC 0x0c03e91e */
if(!s->budget--) { s->failed_pc=0x0c03e91eu; return 0; }
r[14]+=r[3];
goto P_0c03e920;
P_0c03e920: /* original 62e1, guest PC 0x0c03e920 */
if(!s->budget--) { s->failed_pc=0x0c03e920u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c03e922;
P_0c03e922: /* original 2228, guest PC 0x0c03e922 */
if(!s->budget--) { s->failed_pc=0x0c03e922u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e924;
P_0c03e924: /* original 8d0a, guest PC 0x0c03e924 */
if(!s->budget--) { s->failed_pc=0x0c03e924u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(cond) { goto P_0c03e93c; }
goto P_0c03e928;
P_0c03e926: /* original 7b01, guest PC 0x0c03e926 */
if(!s->budget--) { s->failed_pc=0x0c03e926u; return 0; }
r[11]+=0x00000001u;
goto P_0c03e928;
P_0c03e928: /* original 9557, guest PC 0x0c03e928 */
if(!s->budget--) { s->failed_pc=0x0c03e928u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e92a;
P_0c03e92a: /* original 64e3, guest PC 0x0c03e92a */
if(!s->budget--) { s->failed_pc=0x0c03e92au; return 0; }
r[4]=r[14];
goto P_0c03e92c;
P_0c03e92c: /* original 35ec, guest PC 0x0c03e92c */
if(!s->budget--) { s->failed_pc=0x0c03e92cu; return 0; }
r[5]+=r[14];
goto P_0c03e92e;
P_0c03e92e: /* original 4c0b, guest PC 0x0c03e92e */
if(!s->budget--) { s->failed_pc=0x0c03e92eu; return 0; }
target=r[12];
r[16]=code_base|0x0c03e932u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e932u) { target=s->pc; goto dispatch; }
goto P_0c03e932;
P_0c03e930: /* original 7468, guest PC 0x0c03e930 */
if(!s->budget--) { s->failed_pc=0x0c03e930u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e932;
P_0c03e932: /* original 65e3, guest PC 0x0c03e932 */
if(!s->budget--) { s->failed_pc=0x0c03e932u; return 0; }
r[5]=r[14];
goto P_0c03e934;
P_0c03e934: /* original 64e3, guest PC 0x0c03e934 */
if(!s->budget--) { s->failed_pc=0x0c03e934u; return 0; }
r[4]=r[14];
goto P_0c03e936;
P_0c03e936: /* original 7574, guest PC 0x0c03e936 */
if(!s->budget--) { s->failed_pc=0x0c03e936u; return 0; }
r[5]+=0x00000074u;
goto P_0c03e938;
P_0c03e938: /* original 4d0b, guest PC 0x0c03e938 */
if(!s->budget--) { s->failed_pc=0x0c03e938u; return 0; }
target=r[13];
r[16]=code_base|0x0c03e93cu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e93cu) { target=s->pc; goto dispatch; }
goto P_0c03e93c;
P_0c03e93a: /* original 745c, guest PC 0x0c03e93a */
if(!s->budget--) { s->failed_pc=0x0c03e93au; return 0; }
r[4]+=0x0000005cu;
goto P_0c03e93c;
P_0c03e93c: /* original 934e, guest PC 0x0c03e93c */
if(!s->budget--) { s->failed_pc=0x0c03e93cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dcu,2);
goto P_0c03e93e;
P_0c03e93e: /* original 3e3c, guest PC 0x0c03e93e */
if(!s->budget--) { s->failed_pc=0x0c03e93eu; return 0; }
r[14]+=r[3];
goto P_0c03e940;
P_0c03e940: /* original 62e1, guest PC 0x0c03e940 */
if(!s->budget--) { s->failed_pc=0x0c03e940u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c03e942;
P_0c03e942: /* original 2228, guest PC 0x0c03e942 */
if(!s->budget--) { s->failed_pc=0x0c03e942u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e944;
P_0c03e944: /* original 8d0a, guest PC 0x0c03e944 */
if(!s->budget--) { s->failed_pc=0x0c03e944u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(cond) { goto P_0c03e95c; }
goto P_0c03e948;
P_0c03e946: /* original 7b01, guest PC 0x0c03e946 */
if(!s->budget--) { s->failed_pc=0x0c03e946u; return 0; }
r[11]+=0x00000001u;
goto P_0c03e948;
P_0c03e948: /* original 9547, guest PC 0x0c03e948 */
if(!s->budget--) { s->failed_pc=0x0c03e948u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e94a;
P_0c03e94a: /* original 64e3, guest PC 0x0c03e94a */
if(!s->budget--) { s->failed_pc=0x0c03e94au; return 0; }
r[4]=r[14];
goto P_0c03e94c;
P_0c03e94c: /* original 35ec, guest PC 0x0c03e94c */
if(!s->budget--) { s->failed_pc=0x0c03e94cu; return 0; }
r[5]+=r[14];
goto P_0c03e94e;
P_0c03e94e: /* original 4c0b, guest PC 0x0c03e94e */
if(!s->budget--) { s->failed_pc=0x0c03e94eu; return 0; }
target=r[12];
r[16]=code_base|0x0c03e952u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e952u) { target=s->pc; goto dispatch; }
goto P_0c03e952;
P_0c03e950: /* original 7468, guest PC 0x0c03e950 */
if(!s->budget--) { s->failed_pc=0x0c03e950u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e952;
P_0c03e952: /* original 65e3, guest PC 0x0c03e952 */
if(!s->budget--) { s->failed_pc=0x0c03e952u; return 0; }
r[5]=r[14];
goto P_0c03e954;
P_0c03e954: /* original 64e3, guest PC 0x0c03e954 */
if(!s->budget--) { s->failed_pc=0x0c03e954u; return 0; }
r[4]=r[14];
goto P_0c03e956;
P_0c03e956: /* original 7574, guest PC 0x0c03e956 */
if(!s->budget--) { s->failed_pc=0x0c03e956u; return 0; }
r[5]+=0x00000074u;
goto P_0c03e958;
P_0c03e958: /* original 4d0b, guest PC 0x0c03e958 */
if(!s->budget--) { s->failed_pc=0x0c03e958u; return 0; }
target=r[13];
r[16]=code_base|0x0c03e95cu;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e95cu) { target=s->pc; goto dispatch; }
goto P_0c03e95c;
P_0c03e95a: /* original 745c, guest PC 0x0c03e95a */
if(!s->budget--) { s->failed_pc=0x0c03e95au; return 0; }
r[4]+=0x0000005cu;
goto P_0c03e95c;
P_0c03e95c: /* original 7b01, guest PC 0x0c03e95c */
if(!s->budget--) { s->failed_pc=0x0c03e95cu; return 0; }
r[11]+=0x00000001u;
goto P_0c03e95e;
P_0c03e95e: /* original 933d, guest PC 0x0c03e95e */
if(!s->budget--) { s->failed_pc=0x0c03e95eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dcu,2);
goto P_0c03e960;
P_0c03e960: /* original 3ba3, guest PC 0x0c03e960 */
if(!s->budget--) { s->failed_pc=0x0c03e960u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[10])!=0);
goto P_0c03e962;
P_0c03e962: /* original 8fbe, guest PC 0x0c03e962 */
if(!s->budget--) { s->failed_pc=0x0c03e962u; return 0; }
cond=r[17]&1u;
r[14]+=r[3];
if(!cond) { goto P_0c03e8e2; }
goto P_0c03e966;
P_0c03e964: /* original 3e3c, guest PC 0x0c03e964 */
if(!s->budget--) { s->failed_pc=0x0c03e964u; return 0; }
r[14]+=r[3];
goto P_0c03e966;
P_0c03e966: /* original 4f26, guest PC 0x0c03e966 */
if(!s->budget--) { s->failed_pc=0x0c03e966u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e968;
P_0c03e968: /* original d322, guest PC 0x0c03e968 */
if(!s->budget--) { s->failed_pc=0x0c03e968u; return 0; }
r[3]=read(ram,0x0c03e9f4u,4);
goto P_0c03e96a;
P_0c03e96a: /* original e401, guest PC 0x0c03e96a */
if(!s->budget--) { s->failed_pc=0x0c03e96au; return 0; }
r[4]=0x00000001u;
goto P_0c03e96c;
P_0c03e96c: /* original 6af6, guest PC 0x0c03e96c */
if(!s->budget--) { s->failed_pc=0x0c03e96cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03e96e;
P_0c03e96e: /* original 6bf6, guest PC 0x0c03e96e */
if(!s->budget--) { s->failed_pc=0x0c03e96eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03e970;
P_0c03e970: /* original 6cf6, guest PC 0x0c03e970 */
if(!s->budget--) { s->failed_pc=0x0c03e970u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e972;
P_0c03e972: /* original 6df6, guest PC 0x0c03e972 */
if(!s->budget--) { s->failed_pc=0x0c03e972u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e974;
P_0c03e974: /* original 432b, guest PC 0x0c03e974 */
if(!s->budget--) { s->failed_pc=0x0c03e974u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c03e976: /* original 6ef6, guest PC 0x0c03e976 */
if(!s->budget--) { s->failed_pc=0x0c03e976u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e978u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e978u; return 0; } return 1;
P_0c03f5a0: /* original 2fe6, guest PC 0x0c03f5a0 */
if(!s->budget--) { s->failed_pc=0x0c03f5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a2;
P_0c03f5a2: /* original e300, guest PC 0x0c03f5a2 */
if(!s->budget--) { s->failed_pc=0x0c03f5a2u; return 0; }
r[3]=0x00000000u;
goto P_0c03f5a4;
P_0c03f5a4: /* original 2fd6, guest PC 0x0c03f5a4 */
if(!s->budget--) { s->failed_pc=0x0c03f5a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a6;
P_0c03f5a6: /* original 2fc6, guest PC 0x0c03f5a6 */
if(!s->budget--) { s->failed_pc=0x0c03f5a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a8;
P_0c03f5a8: /* original 6c43, guest PC 0x0c03f5a8 */
if(!s->budget--) { s->failed_pc=0x0c03f5a8u; return 0; }
r[12]=r[4];
goto P_0c03f5aa;
P_0c03f5aa: /* original 2fb6, guest PC 0x0c03f5aa */
if(!s->budget--) { s->failed_pc=0x0c03f5aau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ac;
P_0c03f5ac: /* original 2fa6, guest PC 0x0c03f5ac */
if(!s->budget--) { s->failed_pc=0x0c03f5acu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ae;
P_0c03f5ae: /* original 2f96, guest PC 0x0c03f5ae */
if(!s->budget--) { s->failed_pc=0x0c03f5aeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b0;
P_0c03f5b0: /* original 2f86, guest PC 0x0c03f5b0 */
if(!s->budget--) { s->failed_pc=0x0c03f5b0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b2;
P_0c03f5b2: /* original 4f22, guest PC 0x0c03f5b2 */
if(!s->budget--) { s->failed_pc=0x0c03f5b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f5b4;
P_0c03f5b4: /* original 4f12, guest PC 0x0c03f5b4 */
if(!s->budget--) { s->failed_pc=0x0c03f5b4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f5b6;
P_0c03f5b6: /* original 7ffc, guest PC 0x0c03f5b6 */
if(!s->budget--) { s->failed_pc=0x0c03f5b6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03f5b8;
P_0c03f5b8: /* original 2f32, guest PC 0x0c03f5b8 */
if(!s->budget--) { s->failed_pc=0x0c03f5b8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f5ba;
P_0c03f5ba: /* original d37a, guest PC 0x0c03f5ba */
if(!s->budget--) { s->failed_pc=0x0c03f5bau; return 0; }
r[3]=read(ram,0x0c03f7a4u,4);
goto P_0c03f5bc;
P_0c03f5bc: /* original de78, guest PC 0x0c03f5bc */
if(!s->budget--) { s->failed_pc=0x0c03f5bcu; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f5be;
P_0c03f5be: /* original d974, guest PC 0x0c03f5be */
if(!s->budget--) { s->failed_pc=0x0c03f5beu; return 0; }
r[9]=read(ram,0x0c03f790u,4);
goto P_0c03f5c0;
P_0c03f5c0: /* original a052, guest PC 0x0c03f5c0 */
if(!s->budget--) { s->failed_pc=0x0c03f5c0u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
goto P_0c03f668;
P_0c03f5c2: /* original 6b32, guest PC 0x0c03f5c2 */
if(!s->budget--) { s->failed_pc=0x0c03f5c2u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
if(!vf3_matrix_family(0x0c03f5c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f5c4u; return 0; } return 1;
P_0c03f5d0: /* original 6db3, guest PC 0x0c03f5d0 */
if(!s->budget--) { s->failed_pc=0x0c03f5d0u; return 0; }
r[13]=r[11];
goto P_0c03f5d2;
P_0c03f5d2: /* original 63e2, guest PC 0x0c03f5d2 */
if(!s->budget--) { s->failed_pc=0x0c03f5d2u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f5d4;
P_0c03f5d4: /* original 4d08, guest PC 0x0c03f5d4 */
if(!s->budget--) { s->failed_pc=0x0c03f5d4u; return 0; }
r[13]<<=2;
goto P_0c03f5d6;
P_0c03f5d6: /* original 4d00, guest PC 0x0c03f5d6 */
if(!s->budget--) { s->failed_pc=0x0c03f5d6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c03f5d8;
P_0c03f5d8: /* original 33dc, guest PC 0x0c03f5d8 */
if(!s->budget--) { s->failed_pc=0x0c03f5d8u; return 0; }
r[3]+=r[13];
goto P_0c03f5da;
P_0c03f5da: /* original 6232, guest PC 0x0c03f5da */
if(!s->budget--) { s->failed_pc=0x0c03f5dau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f5dc;
P_0c03f5dc: /* original 2228, guest PC 0x0c03f5dc */
if(!s->budget--) { s->failed_pc=0x0c03f5dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f5de;
P_0c03f5de: /* original 8f09, guest PC 0x0c03f5de */
if(!s->budget--) { s->failed_pc=0x0c03f5deu; return 0; }
cond=r[17]&1u;
r[4]=r[11];
if(!cond) { goto P_0c03f5f4; }
goto P_0c03f5e2;
P_0c03f5e0: /* original 64b3, guest PC 0x0c03f5e0 */
if(!s->budget--) { s->failed_pc=0x0c03f5e0u; return 0; }
r[4]=r[11];
goto P_0c03f5e2;
P_0c03f5e2: /* original 62e2, guest PC 0x0c03f5e2 */
if(!s->budget--) { s->failed_pc=0x0c03f5e2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5e4;
P_0c03f5e4: /* original e104, guest PC 0x0c03f5e4 */
if(!s->budget--) { s->failed_pc=0x0c03f5e4u; return 0; }
r[1]=0x00000004u;
goto P_0c03f5e6;
P_0c03f5e6: /* original d370, guest PC 0x0c03f5e6 */
if(!s->budget--) { s->failed_pc=0x0c03f5e6u; return 0; }
r[3]=read(ram,0x0c03f7a8u,4);
goto P_0c03f5e8;
P_0c03f5e8: /* original 32dc, guest PC 0x0c03f5e8 */
if(!s->budget--) { s->failed_pc=0x0c03f5e8u; return 0; }
r[2]+=r[13];
goto P_0c03f5ea;
P_0c03f5ea: /* original 312c, guest PC 0x0c03f5ea */
if(!s->budget--) { s->failed_pc=0x0c03f5eau; return 0; }
r[1]+=r[2];
goto P_0c03f5ec;
P_0c03f5ec: /* original 430b, guest PC 0x0c03f5ec */
if(!s->budget--) { s->failed_pc=0x0c03f5ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f5f0u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f5f0u) { target=s->pc; goto dispatch; }
goto P_0c03f5f0;
P_0c03f5ee: /* original 2f16, guest PC 0x0c03f5ee */
if(!s->budget--) { s->failed_pc=0x0c03f5eeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5f0;
P_0c03f5f0: /* original 63f6, guest PC 0x0c03f5f0 */
if(!s->budget--) { s->failed_pc=0x0c03f5f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c03f5f2;
P_0c03f5f2: /* original 2302, guest PC 0x0c03f5f2 */
if(!s->budget--) { s->failed_pc=0x0c03f5f2u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c03f5f4;
P_0c03f5f4: /* original 62e2, guest PC 0x0c03f5f4 */
if(!s->budget--) { s->failed_pc=0x0c03f5f4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5f6;
P_0c03f5f6: /* original ea3c, guest PC 0x0c03f5f6 */
if(!s->budget--) { s->failed_pc=0x0c03f5f6u; return 0; }
r[10]=0x0000003cu;
goto P_0c03f5f8;
P_0c03f5f8: /* original 68b3, guest PC 0x0c03f5f8 */
if(!s->budget--) { s->failed_pc=0x0c03f5f8u; return 0; }
r[8]=r[11];
goto P_0c03f5fa;
P_0c03f5fa: /* original 4800, guest PC 0x0c03f5fa */
if(!s->budget--) { s->failed_pc=0x0c03f5fau; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c03f5fc;
P_0c03f5fc: /* original 32dc, guest PC 0x0c03f5fc */
if(!s->budget--) { s->failed_pc=0x0c03f5fcu; return 0; }
r[2]+=r[13];
goto P_0c03f5fe;
P_0c03f5fe: /* original 6322, guest PC 0x0c03f5fe */
if(!s->budget--) { s->failed_pc=0x0c03f5feu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f600;
P_0c03f600: /* original 7301, guest PC 0x0c03f600 */
if(!s->budget--) { s->failed_pc=0x0c03f600u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f602;
P_0c03f602: /* original 2232, guest PC 0x0c03f602 */
if(!s->budget--) { s->failed_pc=0x0c03f602u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03f604;
P_0c03f604: /* original 62e2, guest PC 0x0c03f604 */
if(!s->budget--) { s->failed_pc=0x0c03f604u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f606;
P_0c03f606: /* original 6192, guest PC 0x0c03f606 */
if(!s->budget--) { s->failed_pc=0x0c03f606u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c03f608;
P_0c03f608: /* original 32dc, guest PC 0x0c03f608 */
if(!s->budget--) { s->failed_pc=0x0c03f608u; return 0; }
r[2]+=r[13];
goto P_0c03f60a;
P_0c03f60a: /* original 5d21, guest PC 0x0c03f60a */
if(!s->budget--) { s->failed_pc=0x0c03f60au; return 0; }
r[13]=read(ram,r[2]+4,4);
goto P_0c03f60c;
P_0c03f60c: /* original 381c, guest PC 0x0c03f60c */
if(!s->budget--) { s->failed_pc=0x0c03f60cu; return 0; }
r[8]+=r[1];
goto P_0c03f60e;
P_0c03f60e: /* original d267, guest PC 0x0c03f60e */
if(!s->budget--) { s->failed_pc=0x0c03f60eu; return 0; }
r[2]=read(ram,0x0c03f7acu,4);
goto P_0c03f610;
P_0c03f610: /* original 0da7, guest PC 0x0c03f610 */
if(!s->budget--) { s->failed_pc=0x0c03f610u; return 0; }
r[19]=r[13]*r[10];
goto P_0c03f612;
P_0c03f612: /* original 6081, guest PC 0x0c03f612 */
if(!s->budget--) { s->failed_pc=0x0c03f612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c03f614;
P_0c03f614: /* original 6322, guest PC 0x0c03f614 */
if(!s->budget--) { s->failed_pc=0x0c03f614u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f616;
P_0c03f616: /* original 88ff, guest PC 0x0c03f616 */
if(!s->budget--) { s->failed_pc=0x0c03f616u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f618;
P_0c03f618: /* original 0a1a, guest PC 0x0c03f618 */
if(!s->budget--) { s->failed_pc=0x0c03f618u; return 0; }
r[10]=r[19];
goto P_0c03f61a;
P_0c03f61a: /* original 8f03, guest PC 0x0c03f61a */
if(!s->budget--) { s->failed_pc=0x0c03f61au; return 0; }
cond=r[17]&1u;
r[10]+=r[3];
if(!cond) { goto P_0c03f624; }
goto P_0c03f61e;
P_0c03f61c: /* original 3a3c, guest PC 0x0c03f61c */
if(!s->budget--) { s->failed_pc=0x0c03f61cu; return 0; }
r[10]+=r[3];
goto P_0c03f61e;
P_0c03f61e: /* original b367, guest PC 0x0c03f61e */
if(!s->budget--) { s->failed_pc=0x0c03f61eu; return 0; }
target=code_base|0x0c03fcf0u; r[16]=code_base|0x0c03f622u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f622u) { target=s->pc; goto dispatch; }
goto P_0c03f622;
P_0c03f620: /* original 0009, guest PC 0x0c03f620 */
if(!s->budget--) { s->failed_pc=0x0c03f620u; return 0; }
goto P_0c03f622;
P_0c03f622: /* original 2801, guest PC 0x0c03f622 */
if(!s->budget--) { s->failed_pc=0x0c03f622u; return 0; }
write(ram,r[8],r[0],2);
goto P_0c03f624;
P_0c03f624: /* original 60b3, guest PC 0x0c03f624 */
if(!s->budget--) { s->failed_pc=0x0c03f624u; return 0; }
r[0]=r[11];
goto P_0c03f626;
P_0c03f626: /* original 0009, guest PC 0x0c03f626 */
if(!s->budget--) { s->failed_pc=0x0c03f626u; return 0; }
goto P_0c03f628;
P_0c03f628: /* original 6392, guest PC 0x0c03f628 */
if(!s->budget--) { s->failed_pc=0x0c03f628u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f62a;
P_0c03f62a: /* original 4000, guest PC 0x0c03f62a */
if(!s->budget--) { s->failed_pc=0x0c03f62au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03f62c;
P_0c03f62c: /* original 083d, guest PC 0x0c03f62c */
if(!s->budget--) { s->failed_pc=0x0c03f62cu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c03f62e;
P_0c03f62e: /* original 53ab, guest PC 0x0c03f62e */
if(!s->budget--) { s->failed_pc=0x0c03f62eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f630;
P_0c03f630: /* original 2338, guest PC 0x0c03f630 */
if(!s->budget--) { s->failed_pc=0x0c03f630u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f632;
P_0c03f632: /* original 8b0b, guest PC 0x0c03f632 */
if(!s->budget--) { s->failed_pc=0x0c03f632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f64c; }
goto P_0c03f634;
P_0c03f634: /* original d35e, guest PC 0x0c03f634 */
if(!s->budget--) { s->failed_pc=0x0c03f634u; return 0; }
r[3]=read(ram,0x0c03f7b0u,4);
goto P_0c03f636;
P_0c03f636: /* original 65d3, guest PC 0x0c03f636 */
if(!s->budget--) { s->failed_pc=0x0c03f636u; return 0; }
r[5]=r[13];
goto P_0c03f638;
P_0c03f638: /* original 56c2, guest PC 0x0c03f638 */
if(!s->budget--) { s->failed_pc=0x0c03f638u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c03f63a;
P_0c03f63a: /* original 430b, guest PC 0x0c03f63a */
if(!s->budget--) { s->failed_pc=0x0c03f63au; return 0; }
target=r[3];
r[16]=code_base|0x0c03f63eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f63eu) { target=s->pc; goto dispatch; }
goto P_0c03f63e;
P_0c03f63c: /* original 64c3, guest PC 0x0c03f63c */
if(!s->budget--) { s->failed_pc=0x0c03f63cu; return 0; }
r[4]=r[12];
goto P_0c03f63e;
P_0c03f63e: /* original 62f2, guest PC 0x0c03f63e */
if(!s->budget--) { s->failed_pc=0x0c03f63eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03f640;
P_0c03f640: /* original 220b, guest PC 0x0c03f640 */
if(!s->budget--) { s->failed_pc=0x0c03f640u; return 0; }
r[2]|=r[0];
goto P_0c03f642;
P_0c03f642: /* original 2f22, guest PC 0x0c03f642 */
if(!s->budget--) { s->failed_pc=0x0c03f642u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c03f644;
P_0c03f644: /* original d35b, guest PC 0x0c03f644 */
if(!s->budget--) { s->failed_pc=0x0c03f644u; return 0; }
r[3]=read(ram,0x0c03f7b4u,4);
goto P_0c03f646;
P_0c03f646: /* original 430b, guest PC 0x0c03f646 */
if(!s->budget--) { s->failed_pc=0x0c03f646u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f64au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f64au) { target=s->pc; goto dispatch; }
goto P_0c03f64a;
P_0c03f648: /* original 64d3, guest PC 0x0c03f648 */
if(!s->budget--) { s->failed_pc=0x0c03f648u; return 0; }
r[4]=r[13];
goto P_0c03f64a;
P_0c03f64a: /* original 1ade, guest PC 0x0c03f64a */
if(!s->budget--) { s->failed_pc=0x0c03f64au; return 0; }
write(ram,r[10]+56,r[13],4);
goto P_0c03f64c;
P_0c03f64c: /* original d253, guest PC 0x0c03f64c */
if(!s->budget--) { s->failed_pc=0x0c03f64cu; return 0; }
r[2]=read(ram,0x0c03f79cu,4);
goto P_0c03f64e;
P_0c03f64e: /* original 6483, guest PC 0x0c03f64e */
if(!s->budget--) { s->failed_pc=0x0c03f64eu; return 0; }
r[4]=r[8];
goto P_0c03f650;
P_0c03f650: /* original 4408, guest PC 0x0c03f650 */
if(!s->budget--) { s->failed_pc=0x0c03f650u; return 0; }
r[4]<<=2;
goto P_0c03f652;
P_0c03f652: /* original 65d3, guest PC 0x0c03f652 */
if(!s->budget--) { s->failed_pc=0x0c03f652u; return 0; }
r[5]=r[13];
goto P_0c03f654;
P_0c03f654: /* original 6322, guest PC 0x0c03f654 */
if(!s->budget--) { s->failed_pc=0x0c03f654u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f656;
P_0c03f656: /* original 4408, guest PC 0x0c03f656 */
if(!s->budget--) { s->failed_pc=0x0c03f656u; return 0; }
r[4]<<=2;
goto P_0c03f658;
P_0c03f658: /* original 4400, guest PC 0x0c03f658 */
if(!s->budget--) { s->failed_pc=0x0c03f658u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f65a;
P_0c03f65a: /* original b319, guest PC 0x0c03f65a */
if(!s->budget--) { s->failed_pc=0x0c03f65au; return 0; }
target=code_base|0x0c03fc90u; r[16]=code_base|0x0c03f65eu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f65eu) { target=s->pc; goto dispatch; }
goto P_0c03f65e;
P_0c03f65c: /* original 343c, guest PC 0x0c03f65c */
if(!s->budget--) { s->failed_pc=0x0c03f65cu; return 0; }
r[4]+=r[3];
goto P_0c03f65e;
P_0c03f65e: /* original 53ab, guest PC 0x0c03f65e */
if(!s->budget--) { s->failed_pc=0x0c03f65eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f660;
P_0c03f660: /* original 7b01, guest PC 0x0c03f660 */
if(!s->budget--) { s->failed_pc=0x0c03f660u; return 0; }
r[11]+=0x00000001u;
goto P_0c03f662;
P_0c03f662: /* original 7c10, guest PC 0x0c03f662 */
if(!s->budget--) { s->failed_pc=0x0c03f662u; return 0; }
r[12]+=0x00000010u;
goto P_0c03f664;
P_0c03f664: /* original 7301, guest PC 0x0c03f664 */
if(!s->budget--) { s->failed_pc=0x0c03f664u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f666;
P_0c03f666: /* original 1a3b, guest PC 0x0c03f666 */
if(!s->budget--) { s->failed_pc=0x0c03f666u; return 0; }
write(ram,r[10]+44,r[3],4);
goto P_0c03f668;
P_0c03f668: /* original 50c1, guest PC 0x0c03f668 */
if(!s->budget--) { s->failed_pc=0x0c03f668u; return 0; }
r[0]=read(ram,r[12]+4,4);
goto P_0c03f66a;
P_0c03f66a: /* original 88ff, guest PC 0x0c03f66a */
if(!s->budget--) { s->failed_pc=0x0c03f66au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f66c;
P_0c03f66c: /* original 8bb0, guest PC 0x0c03f66c */
if(!s->budget--) { s->failed_pc=0x0c03f66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f5d0; }
goto P_0c03f66e;
P_0c03f66e: /* original 60f2, guest PC 0x0c03f66e */
if(!s->budget--) { s->failed_pc=0x0c03f66eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f670;
P_0c03f670: /* original 7f04, guest PC 0x0c03f670 */
if(!s->budget--) { s->failed_pc=0x0c03f670u; return 0; }
r[15]+=0x00000004u;
goto P_0c03f672;
P_0c03f672: /* original 4f16, guest PC 0x0c03f672 */
if(!s->budget--) { s->failed_pc=0x0c03f672u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f674;
P_0c03f674: /* original 4f26, guest PC 0x0c03f674 */
if(!s->budget--) { s->failed_pc=0x0c03f674u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f676;
P_0c03f676: /* original 68f6, guest PC 0x0c03f676 */
if(!s->budget--) { s->failed_pc=0x0c03f676u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f678;
P_0c03f678: /* original 69f6, guest PC 0x0c03f678 */
if(!s->budget--) { s->failed_pc=0x0c03f678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f67a;
P_0c03f67a: /* original 6af6, guest PC 0x0c03f67a */
if(!s->budget--) { s->failed_pc=0x0c03f67au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f67c;
P_0c03f67c: /* original 6bf6, guest PC 0x0c03f67c */
if(!s->budget--) { s->failed_pc=0x0c03f67cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f67e;
P_0c03f67e: /* original 6cf6, guest PC 0x0c03f67e */
if(!s->budget--) { s->failed_pc=0x0c03f67eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f680;
P_0c03f680: /* original 6df6, guest PC 0x0c03f680 */
if(!s->budget--) { s->failed_pc=0x0c03f680u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f682;
P_0c03f682: /* original 000b, guest PC 0x0c03f682 */
if(!s->budget--) { s->failed_pc=0x0c03f682u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f684: /* original 6ef6, guest PC 0x0c03f684 */
if(!s->budget--) { s->failed_pc=0x0c03f684u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f686u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f686u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
