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
int vf3_away_batch62_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c069624u: goto P_0c069624;
case 0x0c069626u: goto P_0c069626;
case 0x0c069628u: goto P_0c069628;
case 0x0c06962au: goto P_0c06962a;
case 0x0c06962cu: goto P_0c06962c;
case 0x0c06962eu: goto P_0c06962e;
case 0x0c069630u: goto P_0c069630;
case 0x0c069632u: goto P_0c069632;
case 0x0c069634u: goto P_0c069634;
case 0x0c069636u: goto P_0c069636;
case 0x0c069638u: goto P_0c069638;
case 0x0c06963au: goto P_0c06963a;
case 0x0c06963cu: goto P_0c06963c;
case 0x0c06963eu: goto P_0c06963e;
case 0x0c069640u: goto P_0c069640;
case 0x0c069642u: goto P_0c069642;
case 0x0c069644u: goto P_0c069644;
case 0x0c069646u: goto P_0c069646;
case 0x0c069648u: goto P_0c069648;
case 0x0c06964au: goto P_0c06964a;
case 0x0c06964cu: goto P_0c06964c;
case 0x0c06964eu: goto P_0c06964e;
case 0x0c069650u: goto P_0c069650;
case 0x0c069652u: goto P_0c069652;
case 0x0c069654u: goto P_0c069654;
case 0x0c069656u: goto P_0c069656;
case 0x0c069658u: goto P_0c069658;
case 0x0c06965au: goto P_0c06965a;
case 0x0c06965cu: goto P_0c06965c;
case 0x0c06965eu: goto P_0c06965e;
case 0x0c069660u: goto P_0c069660;
case 0x0c069662u: goto P_0c069662;
case 0x0c069664u: goto P_0c069664;
case 0x0c069666u: goto P_0c069666;
case 0x0c069668u: goto P_0c069668;
case 0x0c06966au: goto P_0c06966a;
case 0x0c06966cu: goto P_0c06966c;
case 0x0c06966eu: goto P_0c06966e;
case 0x0c069670u: goto P_0c069670;
case 0x0c069672u: goto P_0c069672;
case 0x0c069674u: goto P_0c069674;
case 0x0c069676u: goto P_0c069676;
case 0x0c069678u: goto P_0c069678;
case 0x0c06967au: goto P_0c06967a;
case 0x0c06967cu: goto P_0c06967c;
case 0x0c06967eu: goto P_0c06967e;
case 0x0c069680u: goto P_0c069680;
case 0x0c069682u: goto P_0c069682;
case 0x0c069684u: goto P_0c069684;
case 0x0c069686u: goto P_0c069686;
case 0x0c069688u: goto P_0c069688;
case 0x0c06968au: goto P_0c06968a;
case 0x0c06968cu: goto P_0c06968c;
case 0x0c06968eu: goto P_0c06968e;
case 0x0c069690u: goto P_0c069690;
case 0x0c069692u: goto P_0c069692;
case 0x0c069694u: goto P_0c069694;
case 0x0c069696u: goto P_0c069696;
case 0x0c069698u: goto P_0c069698;
case 0x0c06969au: goto P_0c06969a;
case 0x0c06969cu: goto P_0c06969c;
case 0x0c08d898u: goto P_0c08d898;
case 0x0c08d89au: goto P_0c08d89a;
case 0x0c08d89cu: goto P_0c08d89c;
case 0x0c08d89eu: goto P_0c08d89e;
case 0x0c08d8a0u: goto P_0c08d8a0;
case 0x0c08d8a2u: goto P_0c08d8a2;
case 0x0c08d8a4u: goto P_0c08d8a4;
case 0x0c08d8a6u: goto P_0c08d8a6;
case 0x0c08d8a8u: goto P_0c08d8a8;
case 0x0c08d8aau: goto P_0c08d8aa;
case 0x0c08d8acu: goto P_0c08d8ac;
case 0x0c08d8aeu: goto P_0c08d8ae;
case 0x0c08d8b0u: goto P_0c08d8b0;
case 0x0c08d8b2u: goto P_0c08d8b2;
case 0x0c08d8b4u: goto P_0c08d8b4;
case 0x0c08d8b6u: goto P_0c08d8b6;
case 0x0c08d8b8u: goto P_0c08d8b8;
case 0x0c08d8bau: goto P_0c08d8ba;
case 0x0c08d8bcu: goto P_0c08d8bc;
case 0x0c08d8beu: goto P_0c08d8be;
case 0x0c08d8c0u: goto P_0c08d8c0;
case 0x0c08d8c2u: goto P_0c08d8c2;
case 0x0c08d8c4u: goto P_0c08d8c4;
case 0x0c08d8c6u: goto P_0c08d8c6;
case 0x0c08d8c8u: goto P_0c08d8c8;
case 0x0c08d8cau: goto P_0c08d8ca;
case 0x0c08d8ccu: goto P_0c08d8cc;
case 0x0c08d8ceu: goto P_0c08d8ce;
case 0x0c08d8d0u: goto P_0c08d8d0;
case 0x0c08d8d2u: goto P_0c08d8d2;
case 0x0c08d8d4u: goto P_0c08d8d4;
case 0x0c08d8d6u: goto P_0c08d8d6;
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
P_0c069624: /* original f38d, guest PC 0x0c069624 */
if(!s->budget--) { s->failed_pc=0x0c069624u; return 0; }
fr[3]=0;
goto P_0c069626;
P_0c069626: /* original f534, guest PC 0x0c069626 */
if(!s->budget--) { s->failed_pc=0x0c069626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c069628;
P_0c069628: /* original 8b03, guest PC 0x0c069628 */
if(!s->budget--) { s->failed_pc=0x0c069628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962a;
P_0c06962a: /* original f434, guest PC 0x0c06962a */
if(!s->budget--) { s->failed_pc=0x0c06962au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06962c;
P_0c06962c: /* original 8b01, guest PC 0x0c06962c */
if(!s->budget--) { s->failed_pc=0x0c06962cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962e;
P_0c06962e: /* original 000b, guest PC 0x0c06962e */
if(!s->budget--) { s->failed_pc=0x0c06962eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c069630: /* original e000, guest PC 0x0c069630 */
if(!s->budget--) { s->failed_pc=0x0c069630u; return 0; }
r[0]=0x00000000u;
goto P_0c069632;
P_0c069632: /* original f38d, guest PC 0x0c069632 */
if(!s->budget--) { s->failed_pc=0x0c069632u; return 0; }
fr[3]=0;
goto P_0c069634;
P_0c069634: /* original f355, guest PC 0x0c069634 */
if(!s->budget--) { s->failed_pc=0x0c069634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c069636;
P_0c069636: /* original 8f03, guest PC 0x0c069636 */
if(!s->budget--) { s->failed_pc=0x0c069636u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c069640; }
goto P_0c06963a;
P_0c069638: /* original f38d, guest PC 0x0c069638 */
if(!s->budget--) { s->failed_pc=0x0c069638u; return 0; }
fr[3]=0;
goto P_0c06963a;
P_0c06963a: /* original f65c, guest PC 0x0c06963a */
if(!s->budget--) { s->failed_pc=0x0c06963au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c06963c;
P_0c06963c: /* original a001, guest PC 0x0c06963c */
if(!s->budget--) { s->failed_pc=0x0c06963cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069642;
P_0c06963e: /* original f64d, guest PC 0x0c06963e */
if(!s->budget--) { s->failed_pc=0x0c06963eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069640;
P_0c069640: /* original f65c, guest PC 0x0c069640 */
if(!s->budget--) { s->failed_pc=0x0c069640u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c069642;
P_0c069642: /* original f345, guest PC 0x0c069642 */
if(!s->budget--) { s->failed_pc=0x0c069642u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069644;
P_0c069644: /* original 8b02, guest PC 0x0c069644 */
if(!s->budget--) { s->failed_pc=0x0c069644u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06964c; }
goto P_0c069646;
P_0c069646: /* original f74c, guest PC 0x0c069646 */
if(!s->budget--) { s->failed_pc=0x0c069646u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069648;
P_0c069648: /* original a001, guest PC 0x0c069648 */
if(!s->budget--) { s->failed_pc=0x0c069648u; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964e;
P_0c06964a: /* original f74d, guest PC 0x0c06964a */
if(!s->budget--) { s->failed_pc=0x0c06964au; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964c;
P_0c06964c: /* original f74c, guest PC 0x0c06964c */
if(!s->budget--) { s->failed_pc=0x0c06964cu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06964e;
P_0c06964e: /* original f675, guest PC 0x0c06964e */
if(!s->budget--) { s->failed_pc=0x0c06964eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c069650;
P_0c069650: /* original 8b02, guest PC 0x0c069650 */
if(!s->budget--) { s->failed_pc=0x0c069650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069658; }
goto P_0c069652;
P_0c069652: /* original f87c, guest PC 0x0c069652 */
if(!s->budget--) { s->failed_pc=0x0c069652u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c069654;
P_0c069654: /* original a002, guest PC 0x0c069654 */
if(!s->budget--) { s->failed_pc=0x0c069654u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c06965c;
P_0c069656: /* original f863, guest PC 0x0c069656 */
if(!s->budget--) { s->failed_pc=0x0c069656u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c069658;
P_0c069658: /* original f86c, guest PC 0x0c069658 */
if(!s->budget--) { s->failed_pc=0x0c069658u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06965a;
P_0c06965a: /* original f873, guest PC 0x0c06965a */
if(!s->budget--) { s->failed_pc=0x0c06965au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'/');
goto P_0c06965c;
P_0c06965c: /* original c711, guest PC 0x0c06965c */
if(!s->budget--) { s->failed_pc=0x0c06965cu; return 0; }
r[0]=code_base|0x000696a4u;
goto P_0c06965e;
P_0c06965e: /* original f28c, guest PC 0x0c06965e */
if(!s->budget--) { s->failed_pc=0x0c06965eu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c069660;
P_0c069660: /* original f308, guest PC 0x0c069660 */
if(!s->budget--) { s->failed_pc=0x0c069660u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069662;
P_0c069662: /* original d011, guest PC 0x0c069662 */
if(!s->budget--) { s->failed_pc=0x0c069662u; return 0; }
r[0]=read(ram,0x0c0696a8u,4);
goto P_0c069664;
P_0c069664: /* original f232, guest PC 0x0c069664 */
if(!s->budget--) { s->failed_pc=0x0c069664u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c069666;
P_0c069666: /* original f23d, guest PC 0x0c069666 */
if(!s->budget--) { s->failed_pc=0x0c069666u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c069668;
P_0c069668: /* original 045a, guest PC 0x0c069668 */
if(!s->budget--) { s->failed_pc=0x0c069668u; return 0; }
r[4]=r[53];
goto P_0c06966a;
P_0c06966a: /* original 4400, guest PC 0x0c06966a */
if(!s->budget--) { s->failed_pc=0x0c06966au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06966c;
P_0c06966c: /* original f765, guest PC 0x0c06966c */
if(!s->budget--) { s->failed_pc=0x0c06966cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c06966e;
P_0c06966e: /* original 8f03, guest PC 0x0c06966e */
if(!s->budget--) { s->failed_pc=0x0c06966eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!cond) { goto P_0c069678; }
goto P_0c069672;
P_0c069670: /* original 044d, guest PC 0x0c069670 */
if(!s->budget--) { s->failed_pc=0x0c069670u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c069672;
P_0c069672: /* original 9214, guest PC 0x0c069672 */
if(!s->budget--) { s->failed_pc=0x0c069672u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06969eu,2);
goto P_0c069674;
P_0c069674: /* original 3248, guest PC 0x0c069674 */
if(!s->budget--) { s->failed_pc=0x0c069674u; return 0; }
r[2]-=r[4];
goto P_0c069676;
P_0c069676: /* original 6423, guest PC 0x0c069676 */
if(!s->budget--) { s->failed_pc=0x0c069676u; return 0; }
r[4]=r[2];
goto P_0c069678;
P_0c069678: /* original f38d, guest PC 0x0c069678 */
if(!s->budget--) { s->failed_pc=0x0c069678u; return 0; }
fr[3]=0;
goto P_0c06967a;
P_0c06967a: /* original f355, guest PC 0x0c06967a */
if(!s->budget--) { s->failed_pc=0x0c06967au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c06967c;
P_0c06967c: /* original 8904, guest PC 0x0c06967c */
if(!s->budget--) { s->failed_pc=0x0c06967cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069688; }
goto P_0c06967e;
P_0c06967e: /* original f38d, guest PC 0x0c06967e */
if(!s->budget--) { s->failed_pc=0x0c06967eu; return 0; }
fr[3]=0;
goto P_0c069680;
P_0c069680: /* original f345, guest PC 0x0c069680 */
if(!s->budget--) { s->failed_pc=0x0c069680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069682;
P_0c069682: /* original 8b09, guest PC 0x0c069682 */
if(!s->budget--) { s->failed_pc=0x0c069682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069698; }
goto P_0c069684;
P_0c069684: /* original a008, guest PC 0x0c069684 */
if(!s->budget--) { s->failed_pc=0x0c069684u; return 0; }
r[4]=0u-r[4];
goto P_0c069698;
P_0c069686: /* original 644b, guest PC 0x0c069686 */
if(!s->budget--) { s->failed_pc=0x0c069686u; return 0; }
r[4]=0u-r[4];
goto P_0c069688;
P_0c069688: /* original f345, guest PC 0x0c069688 */
if(!s->budget--) { s->failed_pc=0x0c069688u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06968a;
P_0c06968a: /* original 8903, guest PC 0x0c06968a */
if(!s->budget--) { s->failed_pc=0x0c06968au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069694; }
goto P_0c06968c;
P_0c06968c: /* original d207, guest PC 0x0c06968c */
if(!s->budget--) { s->failed_pc=0x0c06968cu; return 0; }
r[2]=read(ram,0x0c0696acu,4);
goto P_0c06968e;
P_0c06968e: /* original 3248, guest PC 0x0c06968e */
if(!s->budget--) { s->failed_pc=0x0c06968eu; return 0; }
r[2]-=r[4];
goto P_0c069690;
P_0c069690: /* original a002, guest PC 0x0c069690 */
if(!s->budget--) { s->failed_pc=0x0c069690u; return 0; }
r[4]=r[2];
goto P_0c069698;
P_0c069692: /* original 6423, guest PC 0x0c069692 */
if(!s->budget--) { s->failed_pc=0x0c069692u; return 0; }
r[4]=r[2];
goto P_0c069694;
P_0c069694: /* original 9104, guest PC 0x0c069694 */
if(!s->budget--) { s->failed_pc=0x0c069694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0696a0u,2);
goto P_0c069696;
P_0c069696: /* original 341c, guest PC 0x0c069696 */
if(!s->budget--) { s->failed_pc=0x0c069696u; return 0; }
r[4]+=r[1];
goto P_0c069698;
P_0c069698: /* original 6043, guest PC 0x0c069698 */
if(!s->budget--) { s->failed_pc=0x0c069698u; return 0; }
r[0]=r[4];
goto P_0c06969a;
P_0c06969a: /* original 000b, guest PC 0x0c06969a */
if(!s->budget--) { s->failed_pc=0x0c06969au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06969c: /* original 0009, guest PC 0x0c06969c */
if(!s->budget--) { s->failed_pc=0x0c06969cu; return 0; }
if(!vf3_matrix_family(0x0c06969eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06969eu; return 0; } return 1;
P_0c08d898: /* original 2fe6, guest PC 0x0c08d898 */
if(!s->budget--) { s->failed_pc=0x0c08d898u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d89a;
P_0c08d89a: /* original d530, guest PC 0x0c08d89a */
if(!s->budget--) { s->failed_pc=0x0c08d89au; return 0; }
r[5]=read(ram,0x0c08d95cu,4);
goto P_0c08d89c;
P_0c08d89c: /* original 5354, guest PC 0x0c08d89c */
if(!s->budget--) { s->failed_pc=0x0c08d89cu; return 0; }
r[3]=read(ram,r[5]+16,4);
goto P_0c08d89e;
P_0c08d89e: /* original 3430, guest PC 0x0c08d89e */
if(!s->budget--) { s->failed_pc=0x0c08d89eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08d8a0;
P_0c08d8a0: /* original 8b01, guest PC 0x0c08d8a0 */
if(!s->budget--) { s->failed_pc=0x0c08d8a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d8a6; }
goto P_0c08d8a2;
P_0c08d8a2: /* original a001, guest PC 0x0c08d8a2 */
if(!s->budget--) { s->failed_pc=0x0c08d8a2u; return 0; }
r[14]=read(ram,r[5]+20,4);
goto P_0c08d8a8;
P_0c08d8a4: /* original 5e55, guest PC 0x0c08d8a4 */
if(!s->budget--) { s->failed_pc=0x0c08d8a4u; return 0; }
r[14]=read(ram,r[5]+20,4);
goto P_0c08d8a6;
P_0c08d8a6: /* original 5e54, guest PC 0x0c08d8a6 */
if(!s->budget--) { s->failed_pc=0x0c08d8a6u; return 0; }
r[14]=read(ram,r[5]+16,4);
goto P_0c08d8a8;
P_0c08d8a8: /* original d72d, guest PC 0x0c08d8a8 */
if(!s->budget--) { s->failed_pc=0x0c08d8a8u; return 0; }
r[7]=read(ram,0x0c08d960u,4);
goto P_0c08d8aa;
P_0c08d8aa: /* original d62e, guest PC 0x0c08d8aa */
if(!s->budget--) { s->failed_pc=0x0c08d8aau; return 0; }
r[6]=read(ram,0x0c08d964u,4);
goto P_0c08d8ac;
P_0c08d8ac: /* original 6572, guest PC 0x0c08d8ac */
if(!s->budget--) { s->failed_pc=0x0c08d8acu; return 0; }
tmp=read(ram,r[7],4);
r[5]=tmp;
goto P_0c08d8ae;
P_0c08d8ae: /* original 6253, guest PC 0x0c08d8ae */
if(!s->budget--) { s->failed_pc=0x0c08d8aeu; return 0; }
r[2]=r[5];
goto P_0c08d8b0;
P_0c08d8b0: /* original 2268, guest PC 0x0c08d8b0 */
if(!s->budget--) { s->failed_pc=0x0c08d8b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c08d8b2;
P_0c08d8b2: /* original 8b0c, guest PC 0x0c08d8b2 */
if(!s->budget--) { s->failed_pc=0x0c08d8b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d8ce; }
goto P_0c08d8b4;
P_0c08d8b4: /* original d32c, guest PC 0x0c08d8b4 */
if(!s->budget--) { s->failed_pc=0x0c08d8b4u; return 0; }
r[3]=read(ram,0x0c08d968u,4);
goto P_0c08d8b6;
P_0c08d8b6: /* original 2538, guest PC 0x0c08d8b6 */
if(!s->budget--) { s->failed_pc=0x0c08d8b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c08d8b8;
P_0c08d8b8: /* original 8902, guest PC 0x0c08d8b8 */
if(!s->budget--) { s->failed_pc=0x0c08d8b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d8c0; }
goto P_0c08d8ba;
P_0c08d8ba: /* original 5571, guest PC 0x0c08d8ba */
if(!s->budget--) { s->failed_pc=0x0c08d8bau; return 0; }
r[5]=read(ram,r[7]+4,4);
goto P_0c08d8bc;
P_0c08d8bc: /* original 2568, guest PC 0x0c08d8bc */
if(!s->budget--) { s->failed_pc=0x0c08d8bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[6])==0)!=0);
goto P_0c08d8be;
P_0c08d8be: /* original 8b06, guest PC 0x0c08d8be */
if(!s->budget--) { s->failed_pc=0x0c08d8beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d8ce; }
goto P_0c08d8c0;
P_0c08d8c0: /* original 6542, guest PC 0x0c08d8c0 */
if(!s->budget--) { s->failed_pc=0x0c08d8c0u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c08d8c2;
P_0c08d8c2: /* original e301, guest PC 0x0c08d8c2 */
if(!s->budget--) { s->failed_pc=0x0c08d8c2u; return 0; }
r[3]=0x00000001u;
goto P_0c08d8c4;
P_0c08d8c4: /* original 2358, guest PC 0x0c08d8c4 */
if(!s->budget--) { s->failed_pc=0x0c08d8c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c08d8c6;
P_0c08d8c6: /* original 8905, guest PC 0x0c08d8c6 */
if(!s->budget--) { s->failed_pc=0x0c08d8c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d8d4; }
goto P_0c08d8c8;
P_0c08d8c8: /* original d128, guest PC 0x0c08d8c8 */
if(!s->budget--) { s->failed_pc=0x0c08d8c8u; return 0; }
r[1]=read(ram,0x0c08d96cu,4);
goto P_0c08d8ca;
P_0c08d8ca: /* original 2518, guest PC 0x0c08d8ca */
if(!s->budget--) { s->failed_pc=0x0c08d8cau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c08d8cc;
P_0c08d8cc: /* original 8902, guest PC 0x0c08d8cc */
if(!s->budget--) { s->failed_pc=0x0c08d8ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d8d4; }
goto P_0c08d8ce;
P_0c08d8ce: /* original 65e3, guest PC 0x0c08d8ce */
if(!s->budget--) { s->failed_pc=0x0c08d8ceu; return 0; }
r[5]=r[14];
goto P_0c08d8d0;
P_0c08d8d0: /* original a002, guest PC 0x0c08d8d0 */
if(!s->budget--) { s->failed_pc=0x0c08d8d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d8d8u,s,ram);
P_0c08d8d2: /* original 6ef6, guest PC 0x0c08d8d2 */
if(!s->budget--) { s->failed_pc=0x0c08d8d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08d8d4;
P_0c08d8d4: /* original 000b, guest PC 0x0c08d8d4 */
if(!s->budget--) { s->failed_pc=0x0c08d8d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d8d6: /* original 6ef6, guest PC 0x0c08d8d6 */
if(!s->budget--) { s->failed_pc=0x0c08d8d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d8d8u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
