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
int vf3_away_batch113_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c094884u: goto P_0c094884;
case 0x0c094886u: goto P_0c094886;
case 0x0c094888u: goto P_0c094888;
case 0x0c09488au: goto P_0c09488a;
case 0x0c09488cu: goto P_0c09488c;
case 0x0c09488eu: goto P_0c09488e;
case 0x0c094890u: goto P_0c094890;
case 0x0c094892u: goto P_0c094892;
case 0x0c094894u: goto P_0c094894;
case 0x0c094896u: goto P_0c094896;
case 0x0c094898u: goto P_0c094898;
case 0x0c09489au: goto P_0c09489a;
case 0x0c09489cu: goto P_0c09489c;
case 0x0c09489eu: goto P_0c09489e;
case 0x0c0948a0u: goto P_0c0948a0;
case 0x0c0948a2u: goto P_0c0948a2;
case 0x0c0948a4u: goto P_0c0948a4;
case 0x0c0948a6u: goto P_0c0948a6;
case 0x0c0948a8u: goto P_0c0948a8;
case 0x0c0948aau: goto P_0c0948aa;
case 0x0c0948acu: goto P_0c0948ac;
case 0x0c0948aeu: goto P_0c0948ae;
case 0x0c0948b0u: goto P_0c0948b0;
case 0x0c0948b2u: goto P_0c0948b2;
case 0x0c0948b4u: goto P_0c0948b4;
case 0x0c0948b6u: goto P_0c0948b6;
case 0x0c0948b8u: goto P_0c0948b8;
case 0x0c0948bau: goto P_0c0948ba;
case 0x0c0948bcu: goto P_0c0948bc;
case 0x0c0948beu: goto P_0c0948be;
case 0x0c0948c0u: goto P_0c0948c0;
case 0x0c0948c2u: goto P_0c0948c2;
case 0x0c0948c4u: goto P_0c0948c4;
case 0x0c0948c6u: goto P_0c0948c6;
case 0x0c0948c8u: goto P_0c0948c8;
case 0x0c0948cau: goto P_0c0948ca;
case 0x0c0948ccu: goto P_0c0948cc;
case 0x0c0948ceu: goto P_0c0948ce;
case 0x0c0948d0u: goto P_0c0948d0;
case 0x0c0948d2u: goto P_0c0948d2;
case 0x0c0948d4u: goto P_0c0948d4;
case 0x0c0948d6u: goto P_0c0948d6;
case 0x0c0948d8u: goto P_0c0948d8;
case 0x0c0948dau: goto P_0c0948da;
case 0x0c0948dcu: goto P_0c0948dc;
case 0x0c0948deu: goto P_0c0948de;
case 0x0c0948e0u: goto P_0c0948e0;
case 0x0c0948e2u: goto P_0c0948e2;
case 0x0c0948e4u: goto P_0c0948e4;
case 0x0c0948e6u: goto P_0c0948e6;
case 0x0c0948e8u: goto P_0c0948e8;
case 0x0c0948eau: goto P_0c0948ea;
case 0x0c0948ecu: goto P_0c0948ec;
case 0x0c0948eeu: goto P_0c0948ee;
case 0x0c0948f0u: goto P_0c0948f0;
case 0x0c0948f2u: goto P_0c0948f2;
case 0x0c0948f4u: goto P_0c0948f4;
case 0x0c0948f6u: goto P_0c0948f6;
case 0x0c0948f8u: goto P_0c0948f8;
case 0x0c0948fau: goto P_0c0948fa;
case 0x0c0948fcu: goto P_0c0948fc;
case 0x0c0948feu: goto P_0c0948fe;
case 0x0c094900u: goto P_0c094900;
case 0x0c094902u: goto P_0c094902;
case 0x0c094904u: goto P_0c094904;
case 0x0c094906u: goto P_0c094906;
case 0x0c094908u: goto P_0c094908;
case 0x0c09490au: goto P_0c09490a;
case 0x0c09490cu: goto P_0c09490c;
case 0x0c09490eu: goto P_0c09490e;
case 0x0c094910u: goto P_0c094910;
case 0x0c094912u: goto P_0c094912;
case 0x0c094914u: goto P_0c094914;
case 0x0c094916u: goto P_0c094916;
case 0x0c09493cu: goto P_0c09493c;
case 0x0c09493eu: goto P_0c09493e;
case 0x0c094940u: goto P_0c094940;
case 0x0c094942u: goto P_0c094942;
case 0x0c094944u: goto P_0c094944;
case 0x0c094946u: goto P_0c094946;
case 0x0c094948u: goto P_0c094948;
case 0x0c09494au: goto P_0c09494a;
case 0x0c09494cu: goto P_0c09494c;
case 0x0c09494eu: goto P_0c09494e;
case 0x0c094950u: goto P_0c094950;
case 0x0c094952u: goto P_0c094952;
case 0x0c094954u: goto P_0c094954;
case 0x0c094956u: goto P_0c094956;
case 0x0c094958u: goto P_0c094958;
case 0x0c09495au: goto P_0c09495a;
case 0x0c09495cu: goto P_0c09495c;
case 0x0c09495eu: goto P_0c09495e;
case 0x0c094960u: goto P_0c094960;
case 0x0c094962u: goto P_0c094962;
case 0x0c094964u: goto P_0c094964;
case 0x0c094966u: goto P_0c094966;
case 0x0c094968u: goto P_0c094968;
case 0x0c09496au: goto P_0c09496a;
case 0x0c09496cu: goto P_0c09496c;
case 0x0c09496eu: goto P_0c09496e;
case 0x0c094970u: goto P_0c094970;
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
P_0c094884: /* original 2fe6, guest PC 0x0c094884 */
if(!s->budget--) { s->failed_pc=0x0c094884u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094886;
P_0c094886: /* original e061, guest PC 0x0c094886 */
if(!s->budget--) { s->failed_pc=0x0c094886u; return 0; }
r[0]=0x00000061u;
goto P_0c094888;
P_0c094888: /* original 2fd6, guest PC 0x0c094888 */
if(!s->budget--) { s->failed_pc=0x0c094888u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09488a;
P_0c09488a: /* original 2fc6, guest PC 0x0c09488a */
if(!s->budget--) { s->failed_pc=0x0c09488au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09488c;
P_0c09488c: /* original 2fb6, guest PC 0x0c09488c */
if(!s->budget--) { s->failed_pc=0x0c09488cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09488e;
P_0c09488e: /* original 2fa6, guest PC 0x0c09488e */
if(!s->budget--) { s->failed_pc=0x0c09488eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094890;
P_0c094890: /* original 2f96, guest PC 0x0c094890 */
if(!s->budget--) { s->failed_pc=0x0c094890u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094892;
P_0c094892: /* original 2f86, guest PC 0x0c094892 */
if(!s->budget--) { s->failed_pc=0x0c094892u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094894;
P_0c094894: /* original d621, guest PC 0x0c094894 */
if(!s->budget--) { s->failed_pc=0x0c094894u; return 0; }
r[6]=read(ram,0x0c09491cu,4);
goto P_0c094896;
P_0c094896: /* original 4f22, guest PC 0x0c094896 */
if(!s->budget--) { s->failed_pc=0x0c094896u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094898;
P_0c094898: /* original 5564, guest PC 0x0c094898 */
if(!s->budget--) { s->failed_pc=0x0c094898u; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c09489a;
P_0c09489a: /* original 005c, guest PC 0x0c09489a */
if(!s->budget--) { s->failed_pc=0x0c09489au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c09489c;
P_0c09489c: /* original 600c, guest PC 0x0c09489c */
if(!s->budget--) { s->failed_pc=0x0c09489cu; return 0; }
r[0]=r[0]&255u;
goto P_0c09489e;
P_0c09489e: /* original 880b, guest PC 0x0c09489e */
if(!s->budget--) { s->failed_pc=0x0c09489eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0948a0;
P_0c0948a0: /* original 8f05, guest PC 0x0c0948a0 */
if(!s->budget--) { s->failed_pc=0x0c0948a0u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+20,4);
if(!cond) { goto P_0c0948ae; }
goto P_0c0948a4;
P_0c0948a2: /* original 5665, guest PC 0x0c0948a2 */
if(!s->budget--) { s->failed_pc=0x0c0948a2u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c0948a4;
P_0c0948a4: /* original e061, guest PC 0x0c0948a4 */
if(!s->budget--) { s->failed_pc=0x0c0948a4u; return 0; }
r[0]=0x00000061u;
goto P_0c0948a6;
P_0c0948a6: /* original 006c, guest PC 0x0c0948a6 */
if(!s->budget--) { s->failed_pc=0x0c0948a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0948a8;
P_0c0948a8: /* original 600c, guest PC 0x0c0948a8 */
if(!s->budget--) { s->failed_pc=0x0c0948a8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0948aa;
P_0c0948aa: /* original 8806, guest PC 0x0c0948aa */
if(!s->budget--) { s->failed_pc=0x0c0948aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0948ac;
P_0c0948ac: /* original 892b, guest PC 0x0c0948ac */
if(!s->budget--) { s->failed_pc=0x0c0948acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094906; }
goto P_0c0948ae;
P_0c0948ae: /* original d21c, guest PC 0x0c0948ae */
if(!s->budget--) { s->failed_pc=0x0c0948aeu; return 0; }
r[2]=read(ram,0x0c094920u,4);
goto P_0c0948b0;
P_0c0948b0: /* original 6e43, guest PC 0x0c0948b0 */
if(!s->budget--) { s->failed_pc=0x0c0948b0u; return 0; }
r[14]=r[4];
goto P_0c0948b2;
P_0c0948b2: /* original 420b, guest PC 0x0c0948b2 */
if(!s->budget--) { s->failed_pc=0x0c0948b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0948b6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948b6u) { target=s->pc; goto dispatch; }
goto P_0c0948b6;
P_0c0948b4: /* original e400, guest PC 0x0c0948b4 */
if(!s->budget--) { s->failed_pc=0x0c0948b4u; return 0; }
r[4]=0x00000000u;
goto P_0c0948b6;
P_0c0948b6: /* original 9a2f, guest PC 0x0c0948b6 */
if(!s->budget--) { s->failed_pc=0x0c0948b6u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094918u,2);
goto P_0c0948b8;
P_0c0948b8: /* original ed32, guest PC 0x0c0948b8 */
if(!s->budget--) { s->failed_pc=0x0c0948b8u; return 0; }
r[13]=0x00000032u;
goto P_0c0948ba;
P_0c0948ba: /* original d91b, guest PC 0x0c0948ba */
if(!s->budget--) { s->failed_pc=0x0c0948bau; return 0; }
r[9]=read(ram,0x0c094928u,4);
goto P_0c0948bc;
P_0c0948bc: /* original d819, guest PC 0x0c0948bc */
if(!s->budget--) { s->failed_pc=0x0c0948bcu; return 0; }
r[8]=read(ram,0x0c094924u,4);
goto P_0c0948be;
P_0c0948be: /* original 490b, guest PC 0x0c0948be */
if(!s->budget--) { s->failed_pc=0x0c0948beu; return 0; }
target=r[9];
r[16]=code_base|0x0c0948c2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948c2u) { target=s->pc; goto dispatch; }
goto P_0c0948c2;
P_0c0948c0: /* original 0009, guest PC 0x0c0948c0 */
if(!s->budget--) { s->failed_pc=0x0c0948c0u; return 0; }
goto P_0c0948c2;
P_0c0948c2: /* original e004, guest PC 0x0c0948c2 */
if(!s->budget--) { s->failed_pc=0x0c0948c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0948c4;
P_0c0948c4: /* original f4e8, guest PC 0x0c0948c4 */
if(!s->budget--) { s->failed_pc=0x0c0948c4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0948c6;
P_0c0948c6: /* original f5e6, guest PC 0x0c0948c6 */
if(!s->budget--) { s->failed_pc=0x0c0948c6u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0948c8;
P_0c0948c8: /* original e008, guest PC 0x0c0948c8 */
if(!s->budget--) { s->failed_pc=0x0c0948c8u; return 0; }
r[0]=0x00000008u;
goto P_0c0948ca;
P_0c0948ca: /* original f6e6, guest PC 0x0c0948ca */
if(!s->budget--) { s->failed_pc=0x0c0948cau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0948cc;
P_0c0948cc: /* original 85e8, guest PC 0x0c0948cc */
if(!s->budget--) { s->failed_pc=0x0c0948ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c0948ce;
P_0c0948ce: /* original 6c03, guest PC 0x0c0948ce */
if(!s->budget--) { s->failed_pc=0x0c0948ceu; return 0; }
r[12]=r[0];
goto P_0c0948d0;
P_0c0948d0: /* original e016, guest PC 0x0c0948d0 */
if(!s->budget--) { s->failed_pc=0x0c0948d0u; return 0; }
r[0]=0x00000016u;
goto P_0c0948d2;
P_0c0948d2: /* original 480b, guest PC 0x0c0948d2 */
if(!s->budget--) { s->failed_pc=0x0c0948d2u; return 0; }
target=r[8];
r[16]=code_base|0x0c0948d6u;
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948d6u) { target=s->pc; goto dispatch; }
goto P_0c0948d6;
P_0c0948d4: /* original 0bec, guest PC 0x0c0948d4 */
if(!s->budget--) { s->failed_pc=0x0c0948d4u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0948d6;
P_0c0948d6: /* original d315, guest PC 0x0c0948d6 */
if(!s->budget--) { s->failed_pc=0x0c0948d6u; return 0; }
r[3]=read(ram,0x0c09492cu,4);
goto P_0c0948d8;
P_0c0948d8: /* original 64cf, guest PC 0x0c0948d8 */
if(!s->budget--) { s->failed_pc=0x0c0948d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0948da;
P_0c0948da: /* original 430b, guest PC 0x0c0948da */
if(!s->budget--) { s->failed_pc=0x0c0948dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0948deu;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948deu) { target=s->pc; goto dispatch; }
goto P_0c0948de;
P_0c0948dc: /* original 34ac, guest PC 0x0c0948dc */
if(!s->budget--) { s->failed_pc=0x0c0948dcu; return 0; }
r[4]+=r[10];
goto P_0c0948de;
P_0c0948de: /* original d014, guest PC 0x0c0948de */
if(!s->budget--) { s->failed_pc=0x0c0948deu; return 0; }
r[0]=read(ram,0x0c094930u,4);
goto P_0c0948e0;
P_0c0948e0: /* original 64be, guest PC 0x0c0948e0 */
if(!s->budget--) { s->failed_pc=0x0c0948e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c0948e2;
P_0c0948e2: /* original d314, guest PC 0x0c0948e2 */
if(!s->budget--) { s->failed_pc=0x0c0948e2u; return 0; }
r[3]=read(ram,0x0c094934u,4);
goto P_0c0948e4;
P_0c0948e4: /* original 4400, guest PC 0x0c0948e4 */
if(!s->budget--) { s->failed_pc=0x0c0948e4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0948e6;
P_0c0948e6: /* original 430b, guest PC 0x0c0948e6 */
if(!s->budget--) { s->failed_pc=0x0c0948e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0948eau;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0948eau) { target=s->pc; goto dispatch; }
goto P_0c0948ea;
P_0c0948e8: /* original 044d, guest PC 0x0c0948e8 */
if(!s->budget--) { s->failed_pc=0x0c0948e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0948ea;
P_0c0948ea: /* original 4d10, guest PC 0x0c0948ea */
if(!s->budget--) { s->failed_pc=0x0c0948eau; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c0948ec;
P_0c0948ec: /* original 8fe7, guest PC 0x0c0948ec */
if(!s->budget--) { s->failed_pc=0x0c0948ecu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c0948be; }
goto P_0c0948f0;
P_0c0948ee: /* original 7e18, guest PC 0x0c0948ee */
if(!s->budget--) { s->failed_pc=0x0c0948eeu; return 0; }
r[14]+=0x00000018u;
goto P_0c0948f0;
P_0c0948f0: /* original 4f26, guest PC 0x0c0948f0 */
if(!s->budget--) { s->failed_pc=0x0c0948f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0948f2;
P_0c0948f2: /* original d311, guest PC 0x0c0948f2 */
if(!s->budget--) { s->failed_pc=0x0c0948f2u; return 0; }
r[3]=read(ram,0x0c094938u,4);
goto P_0c0948f4;
P_0c0948f4: /* original e401, guest PC 0x0c0948f4 */
if(!s->budget--) { s->failed_pc=0x0c0948f4u; return 0; }
r[4]=0x00000001u;
goto P_0c0948f6;
P_0c0948f6: /* original 68f6, guest PC 0x0c0948f6 */
if(!s->budget--) { s->failed_pc=0x0c0948f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0948f8;
P_0c0948f8: /* original 69f6, guest PC 0x0c0948f8 */
if(!s->budget--) { s->failed_pc=0x0c0948f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0948fa;
P_0c0948fa: /* original 6af6, guest PC 0x0c0948fa */
if(!s->budget--) { s->failed_pc=0x0c0948fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0948fc;
P_0c0948fc: /* original 6bf6, guest PC 0x0c0948fc */
if(!s->budget--) { s->failed_pc=0x0c0948fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0948fe;
P_0c0948fe: /* original 6cf6, guest PC 0x0c0948fe */
if(!s->budget--) { s->failed_pc=0x0c0948feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094900;
P_0c094900: /* original 6df6, guest PC 0x0c094900 */
if(!s->budget--) { s->failed_pc=0x0c094900u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094902;
P_0c094902: /* original 432b, guest PC 0x0c094902 */
if(!s->budget--) { s->failed_pc=0x0c094902u; return 0; }
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
P_0c094904: /* original 6ef6, guest PC 0x0c094904 */
if(!s->budget--) { s->failed_pc=0x0c094904u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094906;
P_0c094906: /* original 4f26, guest PC 0x0c094906 */
if(!s->budget--) { s->failed_pc=0x0c094906u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094908;
P_0c094908: /* original 68f6, guest PC 0x0c094908 */
if(!s->budget--) { s->failed_pc=0x0c094908u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09490a;
P_0c09490a: /* original 69f6, guest PC 0x0c09490a */
if(!s->budget--) { s->failed_pc=0x0c09490au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09490c;
P_0c09490c: /* original 6af6, guest PC 0x0c09490c */
if(!s->budget--) { s->failed_pc=0x0c09490cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09490e;
P_0c09490e: /* original 6bf6, guest PC 0x0c09490e */
if(!s->budget--) { s->failed_pc=0x0c09490eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094910;
P_0c094910: /* original 6cf6, guest PC 0x0c094910 */
if(!s->budget--) { s->failed_pc=0x0c094910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094912;
P_0c094912: /* original 6df6, guest PC 0x0c094912 */
if(!s->budget--) { s->failed_pc=0x0c094912u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094914;
P_0c094914: /* original 000b, guest PC 0x0c094914 */
if(!s->budget--) { s->failed_pc=0x0c094914u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094916: /* original 6ef6, guest PC 0x0c094916 */
if(!s->budget--) { s->failed_pc=0x0c094916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c094918u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094918u; return 0; } return 1;
P_0c09493c: /* original 4715, guest PC 0x0c09493c */
if(!s->budget--) { s->failed_pc=0x0c09493cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09493e;
P_0c09493e: /* original 6453, guest PC 0x0c09493e */
if(!s->budget--) { s->failed_pc=0x0c09493eu; return 0; }
r[4]=r[5];
goto P_0c094940;
P_0c094940: /* original 8f15, guest PC 0x0c094940 */
if(!s->budget--) { s->failed_pc=0x0c094940u; return 0; }
cond=r[17]&1u;
r[5]=r[6];
if(!cond) { goto P_0c09496e; }
goto P_0c094944;
P_0c094942: /* original 6563, guest PC 0x0c094942 */
if(!s->budget--) { s->failed_pc=0x0c094942u; return 0; }
r[5]=r[6];
goto P_0c094944;
P_0c094944: /* original f549, guest PC 0x0c094944 */
if(!s->budget--) { s->failed_pc=0x0c094944u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094946;
P_0c094946: /* original 77ff, guest PC 0x0c094946 */
if(!s->budget--) { s->failed_pc=0x0c094946u; return 0; }
r[7]+=0xffffffffu;
goto P_0c094948;
P_0c094948: /* original 4715, guest PC 0x0c094948 */
if(!s->budget--) { s->failed_pc=0x0c094948u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09494a;
P_0c09494a: /* original f649, guest PC 0x0c09494a */
if(!s->budget--) { s->failed_pc=0x0c09494au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09494c;
P_0c09494c: /* original f749, guest PC 0x0c09494c */
if(!s->budget--) { s->failed_pc=0x0c09494cu; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09494e;
P_0c09494e: /* original f849, guest PC 0x0c09494e */
if(!s->budget--) { s->failed_pc=0x0c09494eu; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094950;
P_0c094950: /* original f949, guest PC 0x0c094950 */
if(!s->budget--) { s->failed_pc=0x0c094950u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094952;
P_0c094952: /* original f449, guest PC 0x0c094952 */
if(!s->budget--) { s->failed_pc=0x0c094952u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094954;
P_0c094954: /* original f55a, guest PC 0x0c094954 */
if(!s->budget--) { s->failed_pc=0x0c094954u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c094956;
P_0c094956: /* original 7504, guest PC 0x0c094956 */
if(!s->budget--) { s->failed_pc=0x0c094956u; return 0; }
r[5]+=0x00000004u;
goto P_0c094958;
P_0c094958: /* original f56a, guest PC 0x0c094958 */
if(!s->budget--) { s->failed_pc=0x0c094958u; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c09495a;
P_0c09495a: /* original 7504, guest PC 0x0c09495a */
if(!s->budget--) { s->failed_pc=0x0c09495au; return 0; }
r[5]+=0x00000004u;
goto P_0c09495c;
P_0c09495c: /* original f57a, guest PC 0x0c09495c */
if(!s->budget--) { s->failed_pc=0x0c09495cu; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c09495e;
P_0c09495e: /* original 7504, guest PC 0x0c09495e */
if(!s->budget--) { s->failed_pc=0x0c09495eu; return 0; }
r[5]+=0x00000004u;
goto P_0c094960;
P_0c094960: /* original f58a, guest PC 0x0c094960 */
if(!s->budget--) { s->failed_pc=0x0c094960u; return 0; }
vf3_matrix_store(s,ram,8,r[5]);
goto P_0c094962;
P_0c094962: /* original 7504, guest PC 0x0c094962 */
if(!s->budget--) { s->failed_pc=0x0c094962u; return 0; }
r[5]+=0x00000004u;
goto P_0c094964;
P_0c094964: /* original f59a, guest PC 0x0c094964 */
if(!s->budget--) { s->failed_pc=0x0c094964u; return 0; }
vf3_matrix_store(s,ram,9,r[5]);
goto P_0c094966;
P_0c094966: /* original 7504, guest PC 0x0c094966 */
if(!s->budget--) { s->failed_pc=0x0c094966u; return 0; }
r[5]+=0x00000004u;
goto P_0c094968;
P_0c094968: /* original f54a, guest PC 0x0c094968 */
if(!s->budget--) { s->failed_pc=0x0c094968u; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09496a;
P_0c09496a: /* original 8deb, guest PC 0x0c09496a */
if(!s->budget--) { s->failed_pc=0x0c09496au; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(cond) { goto P_0c094944; }
goto P_0c09496e;
P_0c09496c: /* original 7504, guest PC 0x0c09496c */
if(!s->budget--) { s->failed_pc=0x0c09496cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09496e;
P_0c09496e: /* original 000b, guest PC 0x0c09496e */
if(!s->budget--) { s->failed_pc=0x0c09496eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c094970: /* original 0009, guest PC 0x0c094970 */
if(!s->budget--) { s->failed_pc=0x0c094970u; return 0; }
if(!vf3_matrix_family(0x0c094972u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c094972u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
