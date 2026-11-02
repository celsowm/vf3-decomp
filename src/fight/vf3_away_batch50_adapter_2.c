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
int vf3_away_batch50_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0558a0u: goto P_0c0558a0;
case 0x0c0558a2u: goto P_0c0558a2;
case 0x0c0558a4u: goto P_0c0558a4;
case 0x0c0558a6u: goto P_0c0558a6;
case 0x0c0558a8u: goto P_0c0558a8;
case 0x0c0558aau: goto P_0c0558aa;
case 0x0c0558acu: goto P_0c0558ac;
case 0x0c0558aeu: goto P_0c0558ae;
case 0x0c0558b0u: goto P_0c0558b0;
case 0x0c0558b2u: goto P_0c0558b2;
case 0x0c0558b4u: goto P_0c0558b4;
case 0x0c0558b6u: goto P_0c0558b6;
case 0x0c0558b8u: goto P_0c0558b8;
case 0x0c0558bau: goto P_0c0558ba;
case 0x0c0558bcu: goto P_0c0558bc;
case 0x0c0558beu: goto P_0c0558be;
case 0x0c0558c0u: goto P_0c0558c0;
case 0x0c0558c2u: goto P_0c0558c2;
case 0x0c0558c4u: goto P_0c0558c4;
case 0x0c0558c6u: goto P_0c0558c6;
case 0x0c0558c8u: goto P_0c0558c8;
case 0x0c0558cau: goto P_0c0558ca;
case 0x0c0558ccu: goto P_0c0558cc;
case 0x0c0558ceu: goto P_0c0558ce;
case 0x0c0558d0u: goto P_0c0558d0;
case 0x0c0558d2u: goto P_0c0558d2;
case 0x0c0558d4u: goto P_0c0558d4;
case 0x0c0558d6u: goto P_0c0558d6;
case 0x0c0558d8u: goto P_0c0558d8;
case 0x0c0558dau: goto P_0c0558da;
case 0x0c0558dcu: goto P_0c0558dc;
case 0x0c0558deu: goto P_0c0558de;
case 0x0c0558e0u: goto P_0c0558e0;
case 0x0c0558e2u: goto P_0c0558e2;
case 0x0c0558e4u: goto P_0c0558e4;
case 0x0c0558e6u: goto P_0c0558e6;
case 0x0c0558e8u: goto P_0c0558e8;
case 0x0c0558eau: goto P_0c0558ea;
case 0x0c0558ecu: goto P_0c0558ec;
case 0x0c0558eeu: goto P_0c0558ee;
case 0x0c0558f0u: goto P_0c0558f0;
case 0x0c0558f2u: goto P_0c0558f2;
case 0x0c0558f4u: goto P_0c0558f4;
case 0x0c0558f6u: goto P_0c0558f6;
case 0x0c0558f8u: goto P_0c0558f8;
case 0x0c0558fau: goto P_0c0558fa;
case 0x0c0558fcu: goto P_0c0558fc;
case 0x0c0558feu: goto P_0c0558fe;
case 0x0c055900u: goto P_0c055900;
case 0x0c055902u: goto P_0c055902;
case 0x0c055904u: goto P_0c055904;
case 0x0c055906u: goto P_0c055906;
case 0x0c055908u: goto P_0c055908;
case 0x0c05590au: goto P_0c05590a;
case 0x0c05590cu: goto P_0c05590c;
case 0x0c05590eu: goto P_0c05590e;
case 0x0c055910u: goto P_0c055910;
case 0x0c055912u: goto P_0c055912;
case 0x0c055914u: goto P_0c055914;
case 0x0c055916u: goto P_0c055916;
case 0x0c055918u: goto P_0c055918;
case 0x0c05591au: goto P_0c05591a;
case 0x0c05591cu: goto P_0c05591c;
case 0x0c05591eu: goto P_0c05591e;
case 0x0c055920u: goto P_0c055920;
case 0x0c055922u: goto P_0c055922;
case 0x0c055924u: goto P_0c055924;
case 0x0c055926u: goto P_0c055926;
case 0x0c055928u: goto P_0c055928;
case 0x0c05592au: goto P_0c05592a;
case 0x0c05592cu: goto P_0c05592c;
case 0x0c05592eu: goto P_0c05592e;
case 0x0c055930u: goto P_0c055930;
case 0x0c055932u: goto P_0c055932;
case 0x0c055934u: goto P_0c055934;
case 0x0c055936u: goto P_0c055936;
case 0x0c055938u: goto P_0c055938;
case 0x0c05593au: goto P_0c05593a;
case 0x0c05593cu: goto P_0c05593c;
case 0x0c05593eu: goto P_0c05593e;
case 0x0c055940u: goto P_0c055940;
case 0x0c055942u: goto P_0c055942;
case 0x0c055944u: goto P_0c055944;
case 0x0c055946u: goto P_0c055946;
case 0x0c055948u: goto P_0c055948;
case 0x0c05594au: goto P_0c05594a;
case 0x0c05594cu: goto P_0c05594c;
case 0x0c05594eu: goto P_0c05594e;
case 0x0c055950u: goto P_0c055950;
case 0x0c055952u: goto P_0c055952;
case 0x0c055954u: goto P_0c055954;
case 0x0c055956u: goto P_0c055956;
case 0x0c055958u: goto P_0c055958;
case 0x0c05595au: goto P_0c05595a;
case 0x0c05595cu: goto P_0c05595c;
case 0x0c05595eu: goto P_0c05595e;
case 0x0c055960u: goto P_0c055960;
case 0x0c055962u: goto P_0c055962;
case 0x0c055964u: goto P_0c055964;
case 0x0c055966u: goto P_0c055966;
case 0x0c055968u: goto P_0c055968;
case 0x0c05596au: goto P_0c05596a;
case 0x0c05596cu: goto P_0c05596c;
case 0x0c05596eu: goto P_0c05596e;
case 0x0c055970u: goto P_0c055970;
case 0x0c055972u: goto P_0c055972;
case 0x0c055974u: goto P_0c055974;
case 0x0c055976u: goto P_0c055976;
case 0x0c055978u: goto P_0c055978;
case 0x0c05597au: goto P_0c05597a;
case 0x0c05597cu: goto P_0c05597c;
case 0x0c05597eu: goto P_0c05597e;
case 0x0c055980u: goto P_0c055980;
case 0x0c055982u: goto P_0c055982;
case 0x0c055984u: goto P_0c055984;
case 0x0c055986u: goto P_0c055986;
case 0x0c055988u: goto P_0c055988;
case 0x0c07b398u: goto P_0c07b398;
case 0x0c07b39au: goto P_0c07b39a;
case 0x0c07b39cu: goto P_0c07b39c;
case 0x0c07b39eu: goto P_0c07b39e;
case 0x0c07b3a0u: goto P_0c07b3a0;
case 0x0c07b3a2u: goto P_0c07b3a2;
case 0x0c07b3a4u: goto P_0c07b3a4;
case 0x0c07b3a6u: goto P_0c07b3a6;
case 0x0c07b3a8u: goto P_0c07b3a8;
case 0x0c07b3aau: goto P_0c07b3aa;
case 0x0c07b3acu: goto P_0c07b3ac;
case 0x0c07b3aeu: goto P_0c07b3ae;
case 0x0c07b3b0u: goto P_0c07b3b0;
case 0x0c07b3b2u: goto P_0c07b3b2;
case 0x0c07b3b4u: goto P_0c07b3b4;
case 0x0c07b3b6u: goto P_0c07b3b6;
case 0x0c07b3b8u: goto P_0c07b3b8;
case 0x0c07b3bau: goto P_0c07b3ba;
case 0x0c07b3bcu: goto P_0c07b3bc;
case 0x0c07b3beu: goto P_0c07b3be;
case 0x0c07b3c0u: goto P_0c07b3c0;
case 0x0c07b3c2u: goto P_0c07b3c2;
case 0x0c07b3c4u: goto P_0c07b3c4;
case 0x0c07b3c6u: goto P_0c07b3c6;
case 0x0c07b3c8u: goto P_0c07b3c8;
case 0x0c07b3cau: goto P_0c07b3ca;
case 0x0c07b3ccu: goto P_0c07b3cc;
case 0x0c07b3ceu: goto P_0c07b3ce;
case 0x0c07b3d0u: goto P_0c07b3d0;
case 0x0c07b4d4u: goto P_0c07b4d4;
case 0x0c07b4d6u: goto P_0c07b4d6;
case 0x0c07b4d8u: goto P_0c07b4d8;
case 0x0c07b4dau: goto P_0c07b4da;
case 0x0c07b4dcu: goto P_0c07b4dc;
case 0x0c07b4deu: goto P_0c07b4de;
case 0x0c07b4e0u: goto P_0c07b4e0;
case 0x0c07b4e2u: goto P_0c07b4e2;
case 0x0c07b4e4u: goto P_0c07b4e4;
case 0x0c07b4e6u: goto P_0c07b4e6;
case 0x0c07b4e8u: goto P_0c07b4e8;
case 0x0c07b4eau: goto P_0c07b4ea;
case 0x0c07b4ecu: goto P_0c07b4ec;
case 0x0c07b4eeu: goto P_0c07b4ee;
case 0x0c07b4f0u: goto P_0c07b4f0;
case 0x0c07b4f2u: goto P_0c07b4f2;
case 0x0c07b4f4u: goto P_0c07b4f4;
case 0x0c07b4f6u: goto P_0c07b4f6;
case 0x0c07b4f8u: goto P_0c07b4f8;
case 0x0c07b4fau: goto P_0c07b4fa;
case 0x0c07b4fcu: goto P_0c07b4fc;
case 0x0c07b4feu: goto P_0c07b4fe;
case 0x0c07b500u: goto P_0c07b500;
case 0x0c07b502u: goto P_0c07b502;
case 0x0c07b504u: goto P_0c07b504;
case 0x0c07b506u: goto P_0c07b506;
case 0x0c07b508u: goto P_0c07b508;
case 0x0c07b50au: goto P_0c07b50a;
case 0x0c07b50cu: goto P_0c07b50c;
case 0x0c07b50eu: goto P_0c07b50e;
case 0x0c07b510u: goto P_0c07b510;
case 0x0c07b512u: goto P_0c07b512;
case 0x0c07b514u: goto P_0c07b514;
case 0x0c07b516u: goto P_0c07b516;
case 0x0c07b518u: goto P_0c07b518;
case 0x0c07b51au: goto P_0c07b51a;
case 0x0c07b51cu: goto P_0c07b51c;
case 0x0c07b51eu: goto P_0c07b51e;
case 0x0c07b520u: goto P_0c07b520;
case 0x0c07b522u: goto P_0c07b522;
case 0x0c07b524u: goto P_0c07b524;
case 0x0c07b526u: goto P_0c07b526;
case 0x0c07b528u: goto P_0c07b528;
case 0x0c07b52au: goto P_0c07b52a;
case 0x0c07b52cu: goto P_0c07b52c;
case 0x0c07b52eu: goto P_0c07b52e;
case 0x0c07b530u: goto P_0c07b530;
case 0x0c07b532u: goto P_0c07b532;
case 0x0c07b534u: goto P_0c07b534;
case 0x0c07b536u: goto P_0c07b536;
case 0x0c07b538u: goto P_0c07b538;
case 0x0c07b53au: goto P_0c07b53a;
case 0x0c07b53cu: goto P_0c07b53c;
case 0x0c07b53eu: goto P_0c07b53e;
case 0x0c07b540u: goto P_0c07b540;
case 0x0c07b542u: goto P_0c07b542;
case 0x0c07b544u: goto P_0c07b544;
case 0x0c07b546u: goto P_0c07b546;
case 0x0c07b548u: goto P_0c07b548;
case 0x0c07b54au: goto P_0c07b54a;
case 0x0c07b54cu: goto P_0c07b54c;
case 0x0c07b54eu: goto P_0c07b54e;
case 0x0c07b550u: goto P_0c07b550;
case 0x0c07b552u: goto P_0c07b552;
case 0x0c07b554u: goto P_0c07b554;
case 0x0c07b556u: goto P_0c07b556;
case 0x0c07b558u: goto P_0c07b558;
case 0x0c07b55au: goto P_0c07b55a;
case 0x0c07b55cu: goto P_0c07b55c;
case 0x0c07b55eu: goto P_0c07b55e;
case 0x0c07b560u: goto P_0c07b560;
case 0x0c07b562u: goto P_0c07b562;
case 0x0c07b564u: goto P_0c07b564;
case 0x0c07b566u: goto P_0c07b566;
case 0x0c07b568u: goto P_0c07b568;
case 0x0c07b56au: goto P_0c07b56a;
case 0x0c07b56cu: goto P_0c07b56c;
case 0x0c07b56eu: goto P_0c07b56e;
case 0x0c07b570u: goto P_0c07b570;
case 0x0c07b572u: goto P_0c07b572;
case 0x0c07b574u: goto P_0c07b574;
case 0x0c07b576u: goto P_0c07b576;
case 0x0c07b578u: goto P_0c07b578;
case 0x0c07b57au: goto P_0c07b57a;
case 0x0c07b57cu: goto P_0c07b57c;
case 0x0c07b57eu: goto P_0c07b57e;
case 0x0c07b580u: goto P_0c07b580;
case 0x0c07b582u: goto P_0c07b582;
case 0x0c07b584u: goto P_0c07b584;
case 0x0c07b586u: goto P_0c07b586;
case 0x0c07b588u: goto P_0c07b588;
case 0x0c07b58au: goto P_0c07b58a;
case 0x0c07b58cu: goto P_0c07b58c;
case 0x0c07b58eu: goto P_0c07b58e;
case 0x0c07b590u: goto P_0c07b590;
case 0x0c07b592u: goto P_0c07b592;
case 0x0c07b594u: goto P_0c07b594;
case 0x0c07b596u: goto P_0c07b596;
case 0x0c07b598u: goto P_0c07b598;
case 0x0c07b59au: goto P_0c07b59a;
case 0x0c07b59cu: goto P_0c07b59c;
case 0x0c07b59eu: goto P_0c07b59e;
case 0x0c07b5a0u: goto P_0c07b5a0;
case 0x0c07b5a2u: goto P_0c07b5a2;
case 0x0c07b5a4u: goto P_0c07b5a4;
case 0x0c07b5a6u: goto P_0c07b5a6;
case 0x0c07b5a8u: goto P_0c07b5a8;
case 0x0c07b5aau: goto P_0c07b5aa;
case 0x0c07b5acu: goto P_0c07b5ac;
case 0x0c07b5aeu: goto P_0c07b5ae;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0558a0: /* original d03a, guest PC 0x0c0558a0 */
if(!s->budget--) { s->failed_pc=0x0c0558a0u; return 0; }
r[0]=read(ram,0x0c05598cu,4);
goto P_0c0558a2;
P_0c0558a2: /* original e100, guest PC 0x0c0558a2 */
if(!s->budget--) { s->failed_pc=0x0c0558a2u; return 0; }
r[1]=0x00000000u;
goto P_0c0558a4;
P_0c0558a4: /* original 2012, guest PC 0x0c0558a4 */
if(!s->budget--) { s->failed_pc=0x0c0558a4u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c0558a6;
P_0c0558a6: /* original d141, guest PC 0x0c0558a6 */
if(!s->budget--) { s->failed_pc=0x0c0558a6u; return 0; }
r[1]=read(ram,0x0c0559acu,4);
goto P_0c0558a8;
P_0c0558a8: /* original fffb, guest PC 0x0c0558a8 */
if(!s->budget--) { s->failed_pc=0x0c0558a8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0558aa;
P_0c0558aa: /* original e7e0, guest PC 0x0c0558aa */
if(!s->budget--) { s->failed_pc=0x0c0558aau; return 0; }
r[7]=0xffffffe0u;
goto P_0c0558ac;
P_0c0558ac: /* original ffeb, guest PC 0x0c0558ac */
if(!s->budget--) { s->failed_pc=0x0c0558acu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0558ae;
P_0c0558ae: /* original 4728, guest PC 0x0c0558ae */
if(!s->budget--) { s->failed_pc=0x0c0558aeu; return 0; }
r[7]<<=16;
goto P_0c0558b0;
P_0c0558b0: /* original ffdb, guest PC 0x0c0558b0 */
if(!s->budget--) { s->failed_pc=0x0c0558b0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0558b2;
P_0c0558b2: /* original 4718, guest PC 0x0c0558b2 */
if(!s->budget--) { s->failed_pc=0x0c0558b2u; return 0; }
r[7]<<=8;
goto P_0c0558b4;
P_0c0558b4: /* original ffcb, guest PC 0x0c0558b4 */
if(!s->budget--) { s->failed_pc=0x0c0558b4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0558b6;
P_0c0558b6: /* original 6277, guest PC 0x0c0558b6 */
if(!s->budget--) { s->failed_pc=0x0c0558b6u; return 0; }
r[2]=~r[7];
goto P_0c0558b8;
P_0c0558b8: /* original 6112, guest PC 0x0c0558b8 */
if(!s->budget--) { s->failed_pc=0x0c0558b8u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0558ba;
P_0c0558ba: /* original 4201, guest PC 0x0c0558ba */
if(!s->budget--) { s->failed_pc=0x0c0558bau; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c0558bc;
P_0c0558bc: /* original 2fe6, guest PC 0x0c0558bc */
if(!s->budget--) { s->failed_pc=0x0c0558bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558be;
P_0c0558be: /* original 4209, guest PC 0x0c0558be */
if(!s->budget--) { s->failed_pc=0x0c0558beu; return 0; }
r[2]>>=2;
goto P_0c0558c0;
P_0c0558c0: /* original 2fd6, guest PC 0x0c0558c0 */
if(!s->budget--) { s->failed_pc=0x0c0558c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558c2;
P_0c0558c2: /* original 2fc6, guest PC 0x0c0558c2 */
if(!s->budget--) { s->failed_pc=0x0c0558c2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558c4;
P_0c0558c4: /* original 5610, guest PC 0x0c0558c4 */
if(!s->budget--) { s->failed_pc=0x0c0558c4u; return 0; }
r[6]=read(ram,r[1]+0,4);
goto P_0c0558c6;
P_0c0558c6: /* original 5312, guest PC 0x0c0558c6 */
if(!s->budget--) { s->failed_pc=0x0c0558c6u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0558c8;
P_0c0558c8: /* original 2fb6, guest PC 0x0c0558c8 */
if(!s->budget--) { s->failed_pc=0x0c0558c8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558ca;
P_0c0558ca: /* original c739, guest PC 0x0c0558ca */
if(!s->budget--) { s->failed_pc=0x0c0558cau; return 0; }
r[0]=code_base|0x000559b0u;
goto P_0c0558cc;
P_0c0558cc: /* original 2fa6, guest PC 0x0c0558cc */
if(!s->budget--) { s->failed_pc=0x0c0558ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558ce;
P_0c0558ce: /* original 2f96, guest PC 0x0c0558ce */
if(!s->budget--) { s->failed_pc=0x0c0558ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558d0;
P_0c0558d0: /* original 2629, guest PC 0x0c0558d0 */
if(!s->budget--) { s->failed_pc=0x0c0558d0u; return 0; }
r[6]&=r[2];
goto P_0c0558d2;
P_0c0558d2: /* original 2f86, guest PC 0x0c0558d2 */
if(!s->budget--) { s->failed_pc=0x0c0558d2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558d4;
P_0c0558d4: /* original 5814, guest PC 0x0c0558d4 */
if(!s->budget--) { s->failed_pc=0x0c0558d4u; return 0; }
r[8]=read(ram,r[1]+16,4);
goto P_0c0558d6;
P_0c0558d6: /* original 2329, guest PC 0x0c0558d6 */
if(!s->budget--) { s->failed_pc=0x0c0558d6u; return 0; }
r[3]&=r[2];
goto P_0c0558d8;
P_0c0558d8: /* original 2829, guest PC 0x0c0558d8 */
if(!s->budget--) { s->failed_pc=0x0c0558d8u; return 0; }
r[8]&=r[2];
goto P_0c0558da;
P_0c0558da: /* original 4f22, guest PC 0x0c0558da */
if(!s->budget--) { s->failed_pc=0x0c0558dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0558dc;
P_0c0558dc: /* original 4f13, guest PC 0x0c0558dc */
if(!s->budget--) { s->failed_pc=0x0c0558dcu; return 0; }
if(!s->gbr_known) goto unsupported;
r[15]-=4; write(ram,r[15],s->gbr,4);
goto P_0c0558de;
P_0c0558de: /* original 4017, guest PC 0x0c0558de */
if(!s->budget--) { s->failed_pc=0x0c0558deu; return 0; }
s->gbr=read(ram,r[0],4); r[0]+=4; s->gbr_known=1;
goto P_0c0558e0;
P_0c0558e0: /* original 402a, guest PC 0x0c0558e0 */
if(!s->budget--) { s->failed_pc=0x0c0558e0u; return 0; }
r[16]=r[0];
goto P_0c0558e2;
P_0c0558e2: /* original 267b, guest PC 0x0c0558e2 */
if(!s->budget--) { s->failed_pc=0x0c0558e2u; return 0; }
r[6]|=r[7];
goto P_0c0558e4;
P_0c0558e4: /* original 237b, guest PC 0x0c0558e4 */
if(!s->budget--) { s->failed_pc=0x0c0558e4u; return 0; }
r[3]|=r[7];
goto P_0c0558e6;
P_0c0558e6: /* original 287b, guest PC 0x0c0558e6 */
if(!s->budget--) { s->failed_pc=0x0c0558e6u; return 0; }
r[8]|=r[7];
goto P_0c0558e8;
P_0c0558e8: /* original 6063, guest PC 0x0c0558e8 */
if(!s->budget--) { s->failed_pc=0x0c0558e8u; return 0; }
r[0]=r[6];
goto P_0c0558ea;
P_0c0558ea: /* original c212, guest PC 0x0c0558ea */
if(!s->budget--) { s->failed_pc=0x0c0558eau; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+72,r[0],4);
goto P_0c0558ec;
P_0c0558ec: /* original 6033, guest PC 0x0c0558ec */
if(!s->budget--) { s->failed_pc=0x0c0558ecu; return 0; }
r[0]=r[3];
goto P_0c0558ee;
P_0c0558ee: /* original c214, guest PC 0x0c0558ee */
if(!s->budget--) { s->failed_pc=0x0c0558eeu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+80,r[0],4);
goto P_0c0558f0;
P_0c0558f0: /* original 6083, guest PC 0x0c0558f0 */
if(!s->budget--) { s->failed_pc=0x0c0558f0u; return 0; }
r[0]=r[8];
goto P_0c0558f2;
P_0c0558f2: /* original c216, guest PC 0x0c0558f2 */
if(!s->budget--) { s->failed_pc=0x0c0558f2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+88,r[0],4);
goto P_0c0558f4;
P_0c0558f4: /* original 5d40, guest PC 0x0c0558f4 */
if(!s->budget--) { s->failed_pc=0x0c0558f4u; return 0; }
r[13]=read(ram,r[4]+0,4);
goto P_0c0558f6;
P_0c0558f6: /* original 6e43, guest PC 0x0c0558f6 */
if(!s->budget--) { s->failed_pc=0x0c0558f6u; return 0; }
r[14]=r[4];
goto P_0c0558f8;
P_0c0558f8: /* original 4f22, guest PC 0x0c0558f8 */
if(!s->budget--) { s->failed_pc=0x0c0558f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0558fa;
P_0c0558fa: /* original 60d3, guest PC 0x0c0558fa */
if(!s->budget--) { s->failed_pc=0x0c0558fau; return 0; }
r[0]=r[13];
goto P_0c0558fc;
P_0c0558fc: /* original c83e, guest PC 0x0c0558fc */
if(!s->budget--) { s->failed_pc=0x0c0558fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c0558fe;
P_0c0558fe: /* original 2fd6, guest PC 0x0c0558fe */
if(!s->budget--) { s->failed_pc=0x0c0558feu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055900;
P_0c055900: /* original 8927, guest PC 0x0c055900 */
if(!s->budget--) { s->failed_pc=0x0c055900u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055952; }
goto P_0c055902;
P_0c055902: /* original d123, guest PC 0x0c055902 */
if(!s->budget--) { s->failed_pc=0x0c055902u; return 0; }
r[1]=read(ram,0x0c055990u,4);
goto P_0c055904;
P_0c055904: /* original 410b, guest PC 0x0c055904 */
if(!s->budget--) { s->failed_pc=0x0c055904u; return 0; }
target=r[1];
r[16]=code_base|0x0c055908u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055908u) { target=s->pc; goto dispatch; }
goto P_0c055908;
P_0c055906: /* original e400, guest PC 0x0c055906 */
if(!s->budget--) { s->failed_pc=0x0c055906u; return 0; }
r[4]=0x00000000u;
goto P_0c055908;
P_0c055908: /* original 60d3, guest PC 0x0c055908 */
if(!s->budget--) { s->failed_pc=0x0c055908u; return 0; }
r[0]=r[13];
goto P_0c05590a;
P_0c05590a: /* original c802, guest PC 0x0c05590a */
if(!s->budget--) { s->failed_pc=0x0c05590au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c05590c;
P_0c05590c: /* original d121, guest PC 0x0c05590c */
if(!s->budget--) { s->failed_pc=0x0c05590cu; return 0; }
r[1]=read(ram,0x0c055994u,4);
goto P_0c05590e;
P_0c05590e: /* original 64e3, guest PC 0x0c05590e */
if(!s->budget--) { s->failed_pc=0x0c05590eu; return 0; }
r[4]=r[14];
goto P_0c055910;
P_0c055910: /* original 8d05, guest PC 0x0c055910 */
if(!s->budget--) { s->failed_pc=0x0c055910u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(cond) { goto P_0c05591e; }
goto P_0c055914;
P_0c055912: /* original 7408, guest PC 0x0c055912 */
if(!s->budget--) { s->failed_pc=0x0c055912u; return 0; }
r[4]+=0x00000008u;
goto P_0c055914;
P_0c055914: /* original f449, guest PC 0x0c055914 */
if(!s->budget--) { s->failed_pc=0x0c055914u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055916;
P_0c055916: /* original f549, guest PC 0x0c055916 */
if(!s->budget--) { s->failed_pc=0x0c055916u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055918;
P_0c055918: /* original 410b, guest PC 0x0c055918 */
if(!s->budget--) { s->failed_pc=0x0c055918u; return 0; }
target=r[1];
r[16]=code_base|0x0c05591cu;
vf3_matrix_load(s,ram,6,r[4]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05591cu) { target=s->pc; goto dispatch; }
goto P_0c05591c;
P_0c05591a: /* original f648, guest PC 0x0c05591a */
if(!s->budget--) { s->failed_pc=0x0c05591au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c05591c;
P_0c05591c: /* original 60d3, guest PC 0x0c05591c */
if(!s->budget--) { s->failed_pc=0x0c05591cu; return 0; }
r[0]=r[13];
goto P_0c05591e;
P_0c05591e: /* original c838, guest PC 0x0c05591e */
if(!s->budget--) { s->failed_pc=0x0c05591eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&56u)==0)!=0);
goto P_0c055920;
P_0c055920: /* original 8d11, guest PC 0x0c055920 */
if(!s->budget--) { s->failed_pc=0x0c055920u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(cond) { goto P_0c055946; }
goto P_0c055924;
P_0c055922: /* original c820, guest PC 0x0c055922 */
if(!s->budget--) { s->failed_pc=0x0c055922u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c055924;
P_0c055924: /* original d31c, guest PC 0x0c055924 */
if(!s->budget--) { s->failed_pc=0x0c055924u; return 0; }
r[3]=read(ram,0x0c055998u,4);
goto P_0c055926;
P_0c055926: /* original 8902, guest PC 0x0c055926 */
if(!s->budget--) { s->failed_pc=0x0c055926u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05592e; }
goto P_0c055928;
P_0c055928: /* original 430b, guest PC 0x0c055928 */
if(!s->budget--) { s->failed_pc=0x0c055928u; return 0; }
target=r[3];
r[16]=code_base|0x0c05592cu;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05592cu) { target=s->pc; goto dispatch; }
goto P_0c05592c;
P_0c05592a: /* original 54e7, guest PC 0x0c05592a */
if(!s->budget--) { s->failed_pc=0x0c05592au; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05592c;
P_0c05592c: /* original 60d3, guest PC 0x0c05592c */
if(!s->budget--) { s->failed_pc=0x0c05592cu; return 0; }
r[0]=r[13];
goto P_0c05592e;
P_0c05592e: /* original c810, guest PC 0x0c05592e */
if(!s->budget--) { s->failed_pc=0x0c05592eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c055930;
P_0c055930: /* original d21a, guest PC 0x0c055930 */
if(!s->budget--) { s->failed_pc=0x0c055930u; return 0; }
r[2]=read(ram,0x0c05599cu,4);
goto P_0c055932;
P_0c055932: /* original 8902, guest PC 0x0c055932 */
if(!s->budget--) { s->failed_pc=0x0c055932u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05593a; }
goto P_0c055934;
P_0c055934: /* original 420b, guest PC 0x0c055934 */
if(!s->budget--) { s->failed_pc=0x0c055934u; return 0; }
target=r[2];
r[16]=code_base|0x0c055938u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055938u) { target=s->pc; goto dispatch; }
goto P_0c055938;
P_0c055936: /* original 54e6, guest PC 0x0c055936 */
if(!s->budget--) { s->failed_pc=0x0c055936u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c055938;
P_0c055938: /* original 60d3, guest PC 0x0c055938 */
if(!s->budget--) { s->failed_pc=0x0c055938u; return 0; }
r[0]=r[13];
goto P_0c05593a;
P_0c05593a: /* original c808, guest PC 0x0c05593a */
if(!s->budget--) { s->failed_pc=0x0c05593au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c05593c;
P_0c05593c: /* original d118, guest PC 0x0c05593c */
if(!s->budget--) { s->failed_pc=0x0c05593cu; return 0; }
r[1]=read(ram,0x0c0559a0u,4);
goto P_0c05593e;
P_0c05593e: /* original 8902, guest PC 0x0c05593e */
if(!s->budget--) { s->failed_pc=0x0c05593eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055946; }
goto P_0c055940;
P_0c055940: /* original 410b, guest PC 0x0c055940 */
if(!s->budget--) { s->failed_pc=0x0c055940u; return 0; }
target=r[1];
r[16]=code_base|0x0c055944u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055944u) { target=s->pc; goto dispatch; }
goto P_0c055944;
P_0c055942: /* original 54e5, guest PC 0x0c055942 */
if(!s->budget--) { s->failed_pc=0x0c055942u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c055944;
P_0c055944: /* original 60d3, guest PC 0x0c055944 */
if(!s->budget--) { s->failed_pc=0x0c055944u; return 0; }
r[0]=r[13];
goto P_0c055946;
P_0c055946: /* original c804, guest PC 0x0c055946 */
if(!s->budget--) { s->failed_pc=0x0c055946u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c055948;
P_0c055948: /* original d316, guest PC 0x0c055948 */
if(!s->budget--) { s->failed_pc=0x0c055948u; return 0; }
r[3]=read(ram,0x0c0559a4u,4);
goto P_0c05594a;
P_0c05594a: /* original 8902, guest PC 0x0c05594a */
if(!s->budget--) { s->failed_pc=0x0c05594au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055952; }
goto P_0c05594c;
P_0c05594c: /* original 64e3, guest PC 0x0c05594c */
if(!s->budget--) { s->failed_pc=0x0c05594cu; return 0; }
r[4]=r[14];
goto P_0c05594e;
P_0c05594e: /* original 430b, guest PC 0x0c05594e */
if(!s->budget--) { s->failed_pc=0x0c05594eu; return 0; }
target=r[3];
r[16]=code_base|0x0c055952u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055952u) { target=s->pc; goto dispatch; }
goto P_0c055952;
P_0c055950: /* original 7420, guest PC 0x0c055950 */
if(!s->budget--) { s->failed_pc=0x0c055950u; return 0; }
r[4]+=0x00000020u;
goto P_0c055952;
P_0c055952: /* original 54e1, guest PC 0x0c055952 */
if(!s->budget--) { s->failed_pc=0x0c055952u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c055954;
P_0c055954: /* original 2448, guest PC 0x0c055954 */
if(!s->budget--) { s->failed_pc=0x0c055954u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055956;
P_0c055956: /* original 2fe6, guest PC 0x0c055956 */
if(!s->budget--) { s->failed_pc=0x0c055956u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055958;
P_0c055958: /* original 8903, guest PC 0x0c055958 */
if(!s->budget--) { s->failed_pc=0x0c055958u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055962; }
goto P_0c05595a;
P_0c05595a: /* original bea1, guest PC 0x0c05595a */
if(!s->budget--) { s->failed_pc=0x0c05595au; return 0; }
target=code_base|0x0c0556a0u; r[16]=code_base|0x0c05595eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05595eu) { target=s->pc; goto dispatch; }
goto P_0c05595e;
P_0c05595c: /* original 0009, guest PC 0x0c05595c */
if(!s->budget--) { s->failed_pc=0x0c05595cu; return 0; }
goto P_0c05595e;
P_0c05595e: /* original 5ef0, guest PC 0x0c05595e */
if(!s->budget--) { s->failed_pc=0x0c05595eu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c055960;
P_0c055960: /* original 5df1, guest PC 0x0c055960 */
if(!s->budget--) { s->failed_pc=0x0c055960u; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c055962;
P_0c055962: /* original 54eb, guest PC 0x0c055962 */
if(!s->budget--) { s->failed_pc=0x0c055962u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c055964;
P_0c055964: /* original 2448, guest PC 0x0c055964 */
if(!s->budget--) { s->failed_pc=0x0c055964u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055966;
P_0c055966: /* original 8903, guest PC 0x0c055966 */
if(!s->budget--) { s->failed_pc=0x0c055966u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055970; }
goto P_0c055968;
P_0c055968: /* original bfc4, guest PC 0x0c055968 */
if(!s->budget--) { s->failed_pc=0x0c055968u; return 0; }
target=code_base|0x0c0558f4u; r[16]=code_base|0x0c05596cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05596cu) { target=s->pc; goto dispatch; }
goto P_0c05596c;
P_0c05596a: /* original 0009, guest PC 0x0c05596a */
if(!s->budget--) { s->failed_pc=0x0c05596au; return 0; }
goto P_0c05596c;
P_0c05596c: /* original 5df1, guest PC 0x0c05596c */
if(!s->budget--) { s->failed_pc=0x0c05596cu; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c05596e;
P_0c05596e: /* original 5ef0, guest PC 0x0c05596e */
if(!s->budget--) { s->failed_pc=0x0c05596eu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c055970;
P_0c055970: /* original 60d3, guest PC 0x0c055970 */
if(!s->budget--) { s->failed_pc=0x0c055970u; return 0; }
r[0]=r[13];
goto P_0c055972;
P_0c055972: /* original c83e, guest PC 0x0c055972 */
if(!s->budget--) { s->failed_pc=0x0c055972u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c055974;
P_0c055974: /* original d10c, guest PC 0x0c055974 */
if(!s->budget--) { s->failed_pc=0x0c055974u; return 0; }
r[1]=read(ram,0x0c0559a8u,4);
goto P_0c055976;
P_0c055976: /* original 7f08, guest PC 0x0c055976 */
if(!s->budget--) { s->failed_pc=0x0c055976u; return 0; }
r[15]+=0x00000008u;
goto P_0c055978;
P_0c055978: /* original 8901, guest PC 0x0c055978 */
if(!s->budget--) { s->failed_pc=0x0c055978u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05597e; }
goto P_0c05597a;
P_0c05597a: /* original 410b, guest PC 0x0c05597a */
if(!s->budget--) { s->failed_pc=0x0c05597au; return 0; }
target=r[1];
r[16]=code_base|0x0c05597eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05597eu) { target=s->pc; goto dispatch; }
goto P_0c05597e;
P_0c05597c: /* original e401, guest PC 0x0c05597c */
if(!s->budget--) { s->failed_pc=0x0c05597cu; return 0; }
r[4]=0x00000001u;
goto P_0c05597e;
P_0c05597e: /* original 54ec, guest PC 0x0c05597e */
if(!s->budget--) { s->failed_pc=0x0c05597eu; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c055980;
P_0c055980: /* original 4f26, guest PC 0x0c055980 */
if(!s->budget--) { s->failed_pc=0x0c055980u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055982;
P_0c055982: /* original 2448, guest PC 0x0c055982 */
if(!s->budget--) { s->failed_pc=0x0c055982u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055984;
P_0c055984: /* original 8bb6, guest PC 0x0c055984 */
if(!s->budget--) { s->failed_pc=0x0c055984u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0558f4; }
goto P_0c055986;
P_0c055986: /* original 000b, guest PC 0x0c055986 */
if(!s->budget--) { s->failed_pc=0x0c055986u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055988: /* original 0009, guest PC 0x0c055988 */
if(!s->budget--) { s->failed_pc=0x0c055988u; return 0; }
if(!vf3_matrix_family(0x0c05598au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05598au; return 0; } return 1;
P_0c07b398: /* original c748, guest PC 0x0c07b398 */
if(!s->budget--) { s->failed_pc=0x0c07b398u; return 0; }
r[0]=code_base|0x0007b4bcu;
goto P_0c07b39a;
P_0c07b39a: /* original f24c, guest PC 0x0c07b39a */
if(!s->budget--) { s->failed_pc=0x0c07b39au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b39c;
P_0c07b39c: /* original f308, guest PC 0x0c07b39c */
if(!s->budget--) { s->failed_pc=0x0c07b39cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b39e;
P_0c07b39e: /* original e018, guest PC 0x0c07b39e */
if(!s->budget--) { s->failed_pc=0x0c07b39eu; return 0; }
r[0]=0x00000018u;
goto P_0c07b3a0;
P_0c07b3a0: /* original f460, guest PC 0x0c07b3a0 */
if(!s->budget--) { s->failed_pc=0x0c07b3a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07b3a2;
P_0c07b3a2: /* original f230, guest PC 0x0c07b3a2 */
if(!s->budget--) { s->failed_pc=0x0c07b3a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c07b3a4;
P_0c07b3a4: /* original f282, guest PC 0x0c07b3a4 */
if(!s->budget--) { s->failed_pc=0x0c07b3a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c07b3a6;
P_0c07b3a6: /* original f427, guest PC 0x0c07b3a6 */
if(!s->budget--) { s->failed_pc=0x0c07b3a6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07b3a8;
P_0c07b3a8: /* original c745, guest PC 0x0c07b3a8 */
if(!s->budget--) { s->failed_pc=0x0c07b3a8u; return 0; }
r[0]=code_base|0x0007b4c0u;
goto P_0c07b3aa;
P_0c07b3aa: /* original f208, guest PC 0x0c07b3aa */
if(!s->budget--) { s->failed_pc=0x0c07b3aau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b3ac;
P_0c07b3ac: /* original e01c, guest PC 0x0c07b3ac */
if(!s->budget--) { s->failed_pc=0x0c07b3acu; return 0; }
r[0]=0x0000001cu;
goto P_0c07b3ae;
P_0c07b3ae: /* original f15c, guest PC 0x0c07b3ae */
if(!s->budget--) { s->failed_pc=0x0c07b3aeu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c07b3b0;
P_0c07b3b0: /* original f570, guest PC 0x0c07b3b0 */
if(!s->budget--) { s->failed_pc=0x0c07b3b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c07b3b2;
P_0c07b3b2: /* original f120, guest PC 0x0c07b3b2 */
if(!s->budget--) { s->failed_pc=0x0c07b3b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c07b3b4;
P_0c07b3b4: /* original f192, guest PC 0x0c07b3b4 */
if(!s->budget--) { s->failed_pc=0x0c07b3b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07b3b6;
P_0c07b3b6: /* original f417, guest PC 0x0c07b3b6 */
if(!s->budget--) { s->failed_pc=0x0c07b3b6u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c07b3b8;
P_0c07b3b8: /* original c742, guest PC 0x0c07b3b8 */
if(!s->budget--) { s->failed_pc=0x0c07b3b8u; return 0; }
r[0]=code_base|0x0007b4c4u;
goto P_0c07b3ba;
P_0c07b3ba: /* original f108, guest PC 0x0c07b3ba */
if(!s->budget--) { s->failed_pc=0x0c07b3bau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c07b3bc;
P_0c07b3bc: /* original e020, guest PC 0x0c07b3bc */
if(!s->budget--) { s->failed_pc=0x0c07b3bcu; return 0; }
r[0]=0x00000020u;
goto P_0c07b3be;
P_0c07b3be: /* original f410, guest PC 0x0c07b3be */
if(!s->budget--) { s->failed_pc=0x0c07b3beu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c07b3c0;
P_0c07b3c0: /* original f482, guest PC 0x0c07b3c0 */
if(!s->budget--) { s->failed_pc=0x0c07b3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c07b3c2;
P_0c07b3c2: /* original f447, guest PC 0x0c07b3c2 */
if(!s->budget--) { s->failed_pc=0x0c07b3c2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b3c4;
P_0c07b3c4: /* original c740, guest PC 0x0c07b3c4 */
if(!s->budget--) { s->failed_pc=0x0c07b3c4u; return 0; }
r[0]=code_base|0x0007b4c8u;
goto P_0c07b3c6;
P_0c07b3c6: /* original f308, guest PC 0x0c07b3c6 */
if(!s->budget--) { s->failed_pc=0x0c07b3c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b3c8;
P_0c07b3c8: /* original e024, guest PC 0x0c07b3c8 */
if(!s->budget--) { s->failed_pc=0x0c07b3c8u; return 0; }
r[0]=0x00000024u;
goto P_0c07b3ca;
P_0c07b3ca: /* original f530, guest PC 0x0c07b3ca */
if(!s->budget--) { s->failed_pc=0x0c07b3cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c07b3cc;
P_0c07b3cc: /* original f592, guest PC 0x0c07b3cc */
if(!s->budget--) { s->failed_pc=0x0c07b3ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b3ce;
P_0c07b3ce: /* original 000b, guest PC 0x0c07b3ce */
if(!s->budget--) { s->failed_pc=0x0c07b3ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c07b3d0: /* original f457, guest PC 0x0c07b3d0 */
if(!s->budget--) { s->failed_pc=0x0c07b3d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07b3d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b3d2u; return 0; } return 1;
P_0c07b4d4: /* original 654d, guest PC 0x0c07b4d4 */
if(!s->budget--) { s->failed_pc=0x0c07b4d4u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b4d6;
P_0c07b4d6: /* original 2fe6, guest PC 0x0c07b4d6 */
if(!s->budget--) { s->failed_pc=0x0c07b4d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4d8;
P_0c07b4d8: /* original 2fd6, guest PC 0x0c07b4d8 */
if(!s->budget--) { s->failed_pc=0x0c07b4d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4da;
P_0c07b4da: /* original 9378, guest PC 0x0c07b4da */
if(!s->budget--) { s->failed_pc=0x0c07b4dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b4dc;
P_0c07b4dc: /* original 2358, guest PC 0x0c07b4dc */
if(!s->budget--) { s->failed_pc=0x0c07b4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c07b4de;
P_0c07b4de: /* original 8912, guest PC 0x0c07b4de */
if(!s->budget--) { s->failed_pc=0x0c07b4deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b506; }
goto P_0c07b4e0;
P_0c07b4e0: /* original 9476, guest PC 0x0c07b4e0 */
if(!s->budget--) { s->failed_pc=0x0c07b4e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b4e2;
P_0c07b4e2: /* original d23c, guest PC 0x0c07b4e2 */
if(!s->budget--) { s->failed_pc=0x0c07b4e2u; return 0; }
r[2]=read(ram,0x0c07b5d4u,4);
goto P_0c07b4e4;
P_0c07b4e4: /* original 2459, guest PC 0x0c07b4e4 */
if(!s->budget--) { s->failed_pc=0x0c07b4e4u; return 0; }
r[4]&=r[5];
goto P_0c07b4e6;
P_0c07b4e6: /* original 6343, guest PC 0x0c07b4e6 */
if(!s->budget--) { s->failed_pc=0x0c07b4e6u; return 0; }
r[3]=r[4];
goto P_0c07b4e8;
P_0c07b4e8: /* original 6543, guest PC 0x0c07b4e8 */
if(!s->budget--) { s->failed_pc=0x0c07b4e8u; return 0; }
r[5]=r[4];
goto P_0c07b4ea;
P_0c07b4ea: /* original 4308, guest PC 0x0c07b4ea */
if(!s->budget--) { s->failed_pc=0x0c07b4eau; return 0; }
r[3]<<=2;
goto P_0c07b4ec;
P_0c07b4ec: /* original 4500, guest PC 0x0c07b4ec */
if(!s->budget--) { s->failed_pc=0x0c07b4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b4ee;
P_0c07b4ee: /* original 353c, guest PC 0x0c07b4ee */
if(!s->budget--) { s->failed_pc=0x0c07b4eeu; return 0; }
r[5]+=r[3];
goto P_0c07b4f0;
P_0c07b4f0: /* original 352c, guest PC 0x0c07b4f0 */
if(!s->budget--) { s->failed_pc=0x0c07b4f0u; return 0; }
r[5]+=r[2];
goto P_0c07b4f2;
P_0c07b4f2: /* original 8452, guest PC 0x0c07b4f2 */
if(!s->budget--) { s->failed_pc=0x0c07b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c07b4f4;
P_0c07b4f4: /* original 6451, guest PC 0x0c07b4f4 */
if(!s->budget--) { s->failed_pc=0x0c07b4f4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c07b4f6;
P_0c07b4f6: /* original 660c, guest PC 0x0c07b4f6 */
if(!s->budget--) { s->failed_pc=0x0c07b4f6u; return 0; }
r[6]=r[0]&255u;
goto P_0c07b4f8;
P_0c07b4f8: /* original 8453, guest PC 0x0c07b4f8 */
if(!s->budget--) { s->failed_pc=0x0c07b4f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c07b4fa;
P_0c07b4fa: /* original 670c, guest PC 0x0c07b4fa */
if(!s->budget--) { s->failed_pc=0x0c07b4fau; return 0; }
r[7]=r[0]&255u;
goto P_0c07b4fc;
P_0c07b4fc: /* original 8454, guest PC 0x0c07b4fc */
if(!s->budget--) { s->failed_pc=0x0c07b4fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c07b4fe;
P_0c07b4fe: /* original 6e0c, guest PC 0x0c07b4fe */
if(!s->budget--) { s->failed_pc=0x0c07b4feu; return 0; }
r[14]=r[0]&255u;
goto P_0c07b500;
P_0c07b500: /* original 8455, guest PC 0x0c07b500 */
if(!s->budget--) { s->failed_pc=0x0c07b500u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c07b502;
P_0c07b502: /* original a00a, guest PC 0x0c07b502 */
if(!s->budget--) { s->failed_pc=0x0c07b502u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b51a;
P_0c07b504: /* original 6d0c, guest PC 0x0c07b504 */
if(!s->budget--) { s->failed_pc=0x0c07b504u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b506;
P_0c07b506: /* original e500, guest PC 0x0c07b506 */
if(!s->budget--) { s->failed_pc=0x0c07b506u; return 0; }
r[5]=0x00000000u;
goto P_0c07b508;
P_0c07b508: /* original d333, guest PC 0x0c07b508 */
if(!s->budget--) { s->failed_pc=0x0c07b508u; return 0; }
r[3]=read(ram,0x0c07b5d8u,4);
goto P_0c07b50a;
P_0c07b50a: /* original 6753, guest PC 0x0c07b50a */
if(!s->budget--) { s->failed_pc=0x0c07b50au; return 0; }
r[7]=r[5];
goto P_0c07b50c;
P_0c07b50c: /* original 6653, guest PC 0x0c07b50c */
if(!s->budget--) { s->failed_pc=0x0c07b50cu; return 0; }
r[6]=r[5];
goto P_0c07b50e;
P_0c07b50e: /* original 654d, guest PC 0x0c07b50e */
if(!s->budget--) { s->failed_pc=0x0c07b50eu; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b510;
P_0c07b510: /* original 4508, guest PC 0x0c07b510 */
if(!s->budget--) { s->failed_pc=0x0c07b510u; return 0; }
r[5]<<=2;
goto P_0c07b512;
P_0c07b512: /* original 353c, guest PC 0x0c07b512 */
if(!s->budget--) { s->failed_pc=0x0c07b512u; return 0; }
r[5]+=r[3];
goto P_0c07b514;
P_0c07b514: /* original 8551, guest PC 0x0c07b514 */
if(!s->budget--) { s->failed_pc=0x0c07b514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b516;
P_0c07b516: /* original 6e51, guest PC 0x0c07b516 */
if(!s->budget--) { s->failed_pc=0x0c07b516u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[14]=tmp;
goto P_0c07b518;
P_0c07b518: /* original 6d03, guest PC 0x0c07b518 */
if(!s->budget--) { s->failed_pc=0x0c07b518u; return 0; }
r[13]=r[0];
goto P_0c07b51a;
P_0c07b51a: /* original 666d, guest PC 0x0c07b51a */
if(!s->budget--) { s->failed_pc=0x0c07b51au; return 0; }
r[6]=r[6]&65535u;
goto P_0c07b51c;
P_0c07b51c: /* original d22f, guest PC 0x0c07b51c */
if(!s->budget--) { s->failed_pc=0x0c07b51cu; return 0; }
r[2]=read(ram,0x0c07b5dcu,4);
goto P_0c07b51e;
P_0c07b51e: /* original 4608, guest PC 0x0c07b51e */
if(!s->budget--) { s->failed_pc=0x0c07b51eu; return 0; }
r[6]<<=2;
goto P_0c07b520;
P_0c07b520: /* original 4600, guest PC 0x0c07b520 */
if(!s->budget--) { s->failed_pc=0x0c07b520u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b522;
P_0c07b522: /* original 677d, guest PC 0x0c07b522 */
if(!s->budget--) { s->failed_pc=0x0c07b522u; return 0; }
r[7]=r[7]&65535u;
goto P_0c07b524;
P_0c07b524: /* original 4708, guest PC 0x0c07b524 */
if(!s->budget--) { s->failed_pc=0x0c07b524u; return 0; }
r[7]<<=2;
goto P_0c07b526;
P_0c07b526: /* original 634d, guest PC 0x0c07b526 */
if(!s->budget--) { s->failed_pc=0x0c07b526u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b528;
P_0c07b528: /* original 2232, guest PC 0x0c07b528 */
if(!s->budget--) { s->failed_pc=0x0c07b528u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07b52a;
P_0c07b52a: /* original 4700, guest PC 0x0c07b52a */
if(!s->budget--) { s->failed_pc=0x0c07b52au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c07b52c;
P_0c07b52c: /* original 465a, guest PC 0x0c07b52c */
if(!s->budget--) { s->failed_pc=0x0c07b52cu; return 0; }
r[53]=r[6];
goto P_0c07b52e;
P_0c07b52e: /* original 6eed, guest PC 0x0c07b52e */
if(!s->budget--) { s->failed_pc=0x0c07b52eu; return 0; }
r[14]=r[14]&65535u;
goto P_0c07b530;
P_0c07b530: /* original d32b, guest PC 0x0c07b530 */
if(!s->budget--) { s->failed_pc=0x0c07b530u; return 0; }
r[3]=read(ram,0x0c07b5e0u,4);
goto P_0c07b532;
P_0c07b532: /* original 4e08, guest PC 0x0c07b532 */
if(!s->budget--) { s->failed_pc=0x0c07b532u; return 0; }
r[14]<<=2;
goto P_0c07b534;
P_0c07b534: /* original 4e00, guest PC 0x0c07b534 */
if(!s->budget--) { s->failed_pc=0x0c07b534u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07b536;
P_0c07b536: /* original f32d, guest PC 0x0c07b536 */
if(!s->budget--) { s->failed_pc=0x0c07b536u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b538;
P_0c07b538: /* original 6ddd, guest PC 0x0c07b538 */
if(!s->budget--) { s->failed_pc=0x0c07b538u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b53a;
P_0c07b53a: /* original 4d08, guest PC 0x0c07b53a */
if(!s->budget--) { s->failed_pc=0x0c07b53au; return 0; }
r[13]<<=2;
goto P_0c07b53c;
P_0c07b53c: /* original 4d00, guest PC 0x0c07b53c */
if(!s->budget--) { s->failed_pc=0x0c07b53cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b53e;
P_0c07b53e: /* original 72e8, guest PC 0x0c07b53e */
if(!s->budget--) { s->failed_pc=0x0c07b53eu; return 0; }
r[2]+=0xffffffe8u;
goto P_0c07b540;
P_0c07b540: /* original 654d, guest PC 0x0c07b540 */
if(!s->budget--) { s->failed_pc=0x0c07b540u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b542;
P_0c07b542: /* original f33a, guest PC 0x0c07b542 */
if(!s->budget--) { s->failed_pc=0x0c07b542u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b544;
P_0c07b544: /* original 730c, guest PC 0x0c07b544 */
if(!s->budget--) { s->failed_pc=0x0c07b544u; return 0; }
r[3]+=0x0000000cu;
goto P_0c07b546;
P_0c07b546: /* original 475a, guest PC 0x0c07b546 */
if(!s->budget--) { s->failed_pc=0x0c07b546u; return 0; }
r[53]=r[7];
goto P_0c07b548;
P_0c07b548: /* original d126, guest PC 0x0c07b548 */
if(!s->budget--) { s->failed_pc=0x0c07b548u; return 0; }
r[1]=read(ram,0x0c07b5e4u,4);
goto P_0c07b54a;
P_0c07b54a: /* original f32d, guest PC 0x0c07b54a */
if(!s->budget--) { s->failed_pc=0x0c07b54au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b54c;
P_0c07b54c: /* original f13a, guest PC 0x0c07b54c */
if(!s->budget--) { s->failed_pc=0x0c07b54cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c07b54e;
P_0c07b54e: /* original 4e5a, guest PC 0x0c07b54e */
if(!s->budget--) { s->failed_pc=0x0c07b54eu; return 0; }
r[53]=r[14];
goto P_0c07b550;
P_0c07b550: /* original f32d, guest PC 0x0c07b550 */
if(!s->budget--) { s->failed_pc=0x0c07b550u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b552;
P_0c07b552: /* original f23a, guest PC 0x0c07b552 */
if(!s->budget--) { s->failed_pc=0x0c07b552u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c07b554;
P_0c07b554: /* original 4d5a, guest PC 0x0c07b554 */
if(!s->budget--) { s->failed_pc=0x0c07b554u; return 0; }
r[53]=r[13];
goto P_0c07b556;
P_0c07b556: /* original f32d, guest PC 0x0c07b556 */
if(!s->budget--) { s->failed_pc=0x0c07b556u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b558;
P_0c07b558: /* original f33a, guest PC 0x0c07b558 */
if(!s->budget--) { s->failed_pc=0x0c07b558u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b55a;
P_0c07b55a: /* original d11f, guest PC 0x0c07b55a */
if(!s->budget--) { s->failed_pc=0x0c07b55au; return 0; }
r[1]=read(ram,0x0c07b5d8u,4);
goto P_0c07b55c;
P_0c07b55c: /* original 4508, guest PC 0x0c07b55c */
if(!s->budget--) { s->failed_pc=0x0c07b55cu; return 0; }
r[5]<<=2;
goto P_0c07b55e;
P_0c07b55e: /* original f49d, guest PC 0x0c07b55e */
if(!s->budget--) { s->failed_pc=0x0c07b55eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c07b560;
P_0c07b560: /* original 7308, guest PC 0x0c07b560 */
if(!s->budget--) { s->failed_pc=0x0c07b560u; return 0; }
r[3]+=0x00000008u;
goto P_0c07b562;
P_0c07b562: /* original 351c, guest PC 0x0c07b562 */
if(!s->budget--) { s->failed_pc=0x0c07b562u; return 0; }
r[5]+=r[1];
goto P_0c07b564;
P_0c07b564: /* original f24c, guest PC 0x0c07b564 */
if(!s->budget--) { s->failed_pc=0x0c07b564u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b566;
P_0c07b566: /* original 6251, guest PC 0x0c07b566 */
if(!s->budget--) { s->failed_pc=0x0c07b566u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b568;
P_0c07b568: /* original 8551, guest PC 0x0c07b568 */
if(!s->budget--) { s->failed_pc=0x0c07b568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b56a;
P_0c07b56a: /* original 642d, guest PC 0x0c07b56a */
if(!s->budget--) { s->failed_pc=0x0c07b56au; return 0; }
r[4]=r[2]&65535u;
goto P_0c07b56c;
P_0c07b56c: /* original d21e, guest PC 0x0c07b56c */
if(!s->budget--) { s->failed_pc=0x0c07b56cu; return 0; }
r[2]=read(ram,0x0c07b5e8u,4);
goto P_0c07b56e;
P_0c07b56e: /* original 4408, guest PC 0x0c07b56e */
if(!s->budget--) { s->failed_pc=0x0c07b56eu; return 0; }
r[4]<<=2;
goto P_0c07b570;
P_0c07b570: /* original 4400, guest PC 0x0c07b570 */
if(!s->budget--) { s->failed_pc=0x0c07b570u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b572;
P_0c07b572: /* original 6123, guest PC 0x0c07b572 */
if(!s->budget--) { s->failed_pc=0x0c07b572u; return 0; }
r[1]=r[2];
goto P_0c07b574;
P_0c07b574: /* original 644d, guest PC 0x0c07b574 */
if(!s->budget--) { s->failed_pc=0x0c07b574u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b576;
P_0c07b576: /* original 445a, guest PC 0x0c07b576 */
if(!s->budget--) { s->failed_pc=0x0c07b576u; return 0; }
r[53]=r[4];
goto P_0c07b578;
P_0c07b578: /* original 650d, guest PC 0x0c07b578 */
if(!s->budget--) { s->failed_pc=0x0c07b578u; return 0; }
r[5]=r[0]&65535u;
goto P_0c07b57a;
P_0c07b57a: /* original 4508, guest PC 0x0c07b57a */
if(!s->budget--) { s->failed_pc=0x0c07b57au; return 0; }
r[5]<<=2;
goto P_0c07b57c;
P_0c07b57c: /* original 4500, guest PC 0x0c07b57c */
if(!s->budget--) { s->failed_pc=0x0c07b57cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b57e;
P_0c07b57e: /* original f32d, guest PC 0x0c07b57e */
if(!s->budget--) { s->failed_pc=0x0c07b57eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b580;
P_0c07b580: /* original 655d, guest PC 0x0c07b580 */
if(!s->budget--) { s->failed_pc=0x0c07b580u; return 0; }
r[5]=r[5]&65535u;
goto P_0c07b582;
P_0c07b582: /* original f233, guest PC 0x0c07b582 */
if(!s->budget--) { s->failed_pc=0x0c07b582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c07b584;
P_0c07b584: /* original f22a, guest PC 0x0c07b584 */
if(!s->budget--) { s->failed_pc=0x0c07b584u; return 0; }
vf3_matrix_store(s,ram,2,r[2]);
goto P_0c07b586;
P_0c07b586: /* original 72f8, guest PC 0x0c07b586 */
if(!s->budget--) { s->failed_pc=0x0c07b586u; return 0; }
r[2]+=0xfffffff8u;
goto P_0c07b588;
P_0c07b588: /* original 455a, guest PC 0x0c07b588 */
if(!s->budget--) { s->failed_pc=0x0c07b588u; return 0; }
r[53]=r[5];
goto P_0c07b58a;
P_0c07b58a: /* original f32d, guest PC 0x0c07b58a */
if(!s->budget--) { s->failed_pc=0x0c07b58au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b58c;
P_0c07b58c: /* original f433, guest PC 0x0c07b58c */
if(!s->budget--) { s->failed_pc=0x0c07b58cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c07b58e;
P_0c07b58e: /* original f34a, guest PC 0x0c07b58e */
if(!s->budget--) { s->failed_pc=0x0c07b58eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c07b590;
P_0c07b590: /* original 7304, guest PC 0x0c07b590 */
if(!s->budget--) { s->failed_pc=0x0c07b590u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b592;
P_0c07b592: /* original f318, guest PC 0x0c07b592 */
if(!s->budget--) { s->failed_pc=0x0c07b592u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c07b594;
P_0c07b594: /* original f228, guest PC 0x0c07b594 */
if(!s->budget--) { s->failed_pc=0x0c07b594u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c07b596;
P_0c07b596: /* original f232, guest PC 0x0c07b596 */
if(!s->budget--) { s->failed_pc=0x0c07b596u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b598;
P_0c07b598: /* original f32a, guest PC 0x0c07b598 */
if(!s->budget--) { s->failed_pc=0x0c07b598u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b59a;
P_0c07b59a: /* original d014, guest PC 0x0c07b59a */
if(!s->budget--) { s->failed_pc=0x0c07b59au; return 0; }
r[0]=read(ram,0x0c07b5ecu,4);
goto P_0c07b59c;
P_0c07b59c: /* original 720c, guest PC 0x0c07b59c */
if(!s->budget--) { s->failed_pc=0x0c07b59cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c07b59e;
P_0c07b59e: /* original f328, guest PC 0x0c07b59e */
if(!s->budget--) { s->failed_pc=0x0c07b59eu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07b5a0;
P_0c07b5a0: /* original 7304, guest PC 0x0c07b5a0 */
if(!s->budget--) { s->failed_pc=0x0c07b5a0u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b5a2;
P_0c07b5a2: /* original f208, guest PC 0x0c07b5a2 */
if(!s->budget--) { s->failed_pc=0x0c07b5a2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b5a4;
P_0c07b5a4: /* original 70f4, guest PC 0x0c07b5a4 */
if(!s->budget--) { s->failed_pc=0x0c07b5a4u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c07b5a6;
P_0c07b5a6: /* original f232, guest PC 0x0c07b5a6 */
if(!s->budget--) { s->failed_pc=0x0c07b5a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b5a8;
P_0c07b5a8: /* original f32a, guest PC 0x0c07b5a8 */
if(!s->budget--) { s->failed_pc=0x0c07b5a8u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b5aa;
P_0c07b5aa: /* original 6df6, guest PC 0x0c07b5aa */
if(!s->budget--) { s->failed_pc=0x0c07b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b5ac;
P_0c07b5ac: /* original 000b, guest PC 0x0c07b5ac */
if(!s->budget--) { s->failed_pc=0x0c07b5acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b5ae: /* original 6ef6, guest PC 0x0c07b5ae */
if(!s->budget--) { s->failed_pc=0x0c07b5aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b5b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5b0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
