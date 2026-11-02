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
int vf3_away_batch17_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
return vf3_matrix_family(0x0c0926bau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
