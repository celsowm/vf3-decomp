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
int vf3_away_batch55_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0556a0u: goto P_0c0556a0;
case 0x0c0556a2u: goto P_0c0556a2;
case 0x0c0556a4u: goto P_0c0556a4;
case 0x0c0556a6u: goto P_0c0556a6;
case 0x0c0556a8u: goto P_0c0556a8;
case 0x0c0556aau: goto P_0c0556aa;
case 0x0c0556acu: goto P_0c0556ac;
case 0x0c0556aeu: goto P_0c0556ae;
case 0x0c0556b0u: goto P_0c0556b0;
case 0x0c0556b2u: goto P_0c0556b2;
case 0x0c0556b4u: goto P_0c0556b4;
case 0x0c0556b6u: goto P_0c0556b6;
case 0x0c0556b8u: goto P_0c0556b8;
case 0x0c0556bau: goto P_0c0556ba;
case 0x0c0556bcu: goto P_0c0556bc;
case 0x0c0556beu: goto P_0c0556be;
case 0x0c0556c0u: goto P_0c0556c0;
case 0x0c0556c2u: goto P_0c0556c2;
case 0x0c0556c4u: goto P_0c0556c4;
case 0x0c0556c6u: goto P_0c0556c6;
case 0x0c0556c8u: goto P_0c0556c8;
case 0x0c0556cau: goto P_0c0556ca;
case 0x0c0556ccu: goto P_0c0556cc;
case 0x0c0556ceu: goto P_0c0556ce;
case 0x0c0556d0u: goto P_0c0556d0;
case 0x0c0556d2u: goto P_0c0556d2;
case 0x0c0556d4u: goto P_0c0556d4;
case 0x0c0556d6u: goto P_0c0556d6;
case 0x0c0556d8u: goto P_0c0556d8;
case 0x0c0556dau: goto P_0c0556da;
case 0x0c0556dcu: goto P_0c0556dc;
case 0x0c0556deu: goto P_0c0556de;
case 0x0c0556e0u: goto P_0c0556e0;
case 0x0c0556e2u: goto P_0c0556e2;
case 0x0c0556e4u: goto P_0c0556e4;
case 0x0c0556e6u: goto P_0c0556e6;
case 0x0c0556e8u: goto P_0c0556e8;
case 0x0c0556eau: goto P_0c0556ea;
case 0x0c0556ecu: goto P_0c0556ec;
case 0x0c0556eeu: goto P_0c0556ee;
case 0x0c0556f0u: goto P_0c0556f0;
case 0x0c0556f2u: goto P_0c0556f2;
case 0x0c0556f4u: goto P_0c0556f4;
case 0x0c0556f6u: goto P_0c0556f6;
case 0x0c0556f8u: goto P_0c0556f8;
case 0x0c0556fau: goto P_0c0556fa;
case 0x0c055704u: goto P_0c055704;
case 0x0c055706u: goto P_0c055706;
case 0x0c055708u: goto P_0c055708;
case 0x0c05570au: goto P_0c05570a;
case 0x0c05570cu: goto P_0c05570c;
case 0x0c05570eu: goto P_0c05570e;
case 0x0c055710u: goto P_0c055710;
case 0x0c055712u: goto P_0c055712;
case 0x0c055714u: goto P_0c055714;
case 0x0c055716u: goto P_0c055716;
case 0x0c055718u: goto P_0c055718;
case 0x0c05571au: goto P_0c05571a;
case 0x0c05571cu: goto P_0c05571c;
case 0x0c05571eu: goto P_0c05571e;
case 0x0c055720u: goto P_0c055720;
case 0x0c055722u: goto P_0c055722;
case 0x0c055724u: goto P_0c055724;
case 0x0c055726u: goto P_0c055726;
case 0x0c055728u: goto P_0c055728;
case 0x0c05572au: goto P_0c05572a;
case 0x0c05572cu: goto P_0c05572c;
case 0x0c05572eu: goto P_0c05572e;
case 0x0c055730u: goto P_0c055730;
case 0x0c055732u: goto P_0c055732;
case 0x0c055734u: goto P_0c055734;
case 0x0c055736u: goto P_0c055736;
case 0x0c055738u: goto P_0c055738;
case 0x0c05573au: goto P_0c05573a;
case 0x0c05573cu: goto P_0c05573c;
case 0x0c05573eu: goto P_0c05573e;
case 0x0c055740u: goto P_0c055740;
case 0x0c055742u: goto P_0c055742;
case 0x0c055744u: goto P_0c055744;
case 0x0c055746u: goto P_0c055746;
case 0x0c055748u: goto P_0c055748;
case 0x0c05574au: goto P_0c05574a;
case 0x0c05574cu: goto P_0c05574c;
case 0x0c05574eu: goto P_0c05574e;
case 0x0c055750u: goto P_0c055750;
case 0x0c055752u: goto P_0c055752;
case 0x0c055754u: goto P_0c055754;
case 0x0c055756u: goto P_0c055756;
case 0x0c055758u: goto P_0c055758;
case 0x0c05575au: goto P_0c05575a;
case 0x0c05575cu: goto P_0c05575c;
case 0x0c05575eu: goto P_0c05575e;
case 0x0c055760u: goto P_0c055760;
case 0x0c055762u: goto P_0c055762;
case 0x0c055764u: goto P_0c055764;
case 0x0c055766u: goto P_0c055766;
case 0x0c055768u: goto P_0c055768;
case 0x0c05576au: goto P_0c05576a;
case 0x0c05576cu: goto P_0c05576c;
case 0x0c05576eu: goto P_0c05576e;
case 0x0c055770u: goto P_0c055770;
case 0x0c055772u: goto P_0c055772;
case 0x0c055774u: goto P_0c055774;
case 0x0c055776u: goto P_0c055776;
case 0x0c055778u: goto P_0c055778;
case 0x0c05577au: goto P_0c05577a;
case 0x0c05577cu: goto P_0c05577c;
case 0x0c05577eu: goto P_0c05577e;
case 0x0c055780u: goto P_0c055780;
case 0x0c055782u: goto P_0c055782;
case 0x0c055784u: goto P_0c055784;
case 0x0c055786u: goto P_0c055786;
case 0x0c055788u: goto P_0c055788;
case 0x0c05578au: goto P_0c05578a;
case 0x0c05578cu: goto P_0c05578c;
case 0x0c05578eu: goto P_0c05578e;
case 0x0c055790u: goto P_0c055790;
case 0x0c055792u: goto P_0c055792;
case 0x0c055794u: goto P_0c055794;
case 0x0c055796u: goto P_0c055796;
case 0x0c055798u: goto P_0c055798;
case 0x0c05579au: goto P_0c05579a;
case 0x0c0557a0u: goto P_0c0557a0;
case 0x0c0557a2u: goto P_0c0557a2;
case 0x0c0557a4u: goto P_0c0557a4;
case 0x0c0557a6u: goto P_0c0557a6;
case 0x0c0557a8u: goto P_0c0557a8;
case 0x0c0557aau: goto P_0c0557aa;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0556a0: /* original 6d43, guest PC 0x0c0556a0 */
if(!s->budget--) { s->failed_pc=0x0c0556a0u; return 0; }
r[13]=r[4];
goto P_0c0556a2;
P_0c0556a2: /* original 7410, guest PC 0x0c0556a2 */
if(!s->budget--) { s->failed_pc=0x0c0556a2u; return 0; }
r[4]+=0x00000010u;
goto P_0c0556a4;
P_0c0556a4: /* original c60a, guest PC 0x0c0556a4 */
if(!s->budget--) { s->failed_pc=0x0c0556a4u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+40,4);
goto P_0c0556a6;
P_0c0556a6: /* original f049, guest PC 0x0c0556a6 */
if(!s->budget--) { s->failed_pc=0x0c0556a6u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556a8;
P_0c0556a8: /* original f149, guest PC 0x0c0556a8 */
if(!s->budget--) { s->failed_pc=0x0c0556a8u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556aa;
P_0c0556aa: /* original f249, guest PC 0x0c0556aa */
if(!s->budget--) { s->failed_pc=0x0c0556aau; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0556ac;
P_0c0556ac: /* original f39d, guest PC 0x0c0556ac */
if(!s->budget--) { s->failed_pc=0x0c0556acu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0556ae;
P_0c0556ae: /* original d33f, guest PC 0x0c0556ae */
if(!s->budget--) { s->failed_pc=0x0c0556aeu; return 0; }
r[3]=read(ram,0x0c0557acu,4);
goto P_0c0556b0;
P_0c0556b0: /* original f1fd, guest PC 0x0c0556b0 */
if(!s->budget--) { s->failed_pc=0x0c0556b0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c0556b2;
P_0c0556b2: /* original 405a, guest PC 0x0c0556b2 */
if(!s->budget--) { s->failed_pc=0x0c0556b2u; return 0; }
r[53]=r[0];
goto P_0c0556b4;
P_0c0556b4: /* original f60d, guest PC 0x0c0556b4 */
if(!s->budget--) { s->failed_pc=0x0c0556b4u; return 0; }
fr[6]=r[53];
goto P_0c0556b6;
P_0c0556b6: /* original f448, guest PC 0x0c0556b6 */
if(!s->budget--) { s->failed_pc=0x0c0556b6u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0556b8;
P_0c0556b8: /* original f538, guest PC 0x0c0556b8 */
if(!s->budget--) { s->failed_pc=0x0c0556b8u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c0556ba;
P_0c0556ba: /* original f24d, guest PC 0x0c0556ba */
if(!s->budget--) { s->failed_pc=0x0c0556bau; return 0; }
fr[2]^=0x80000000u;
goto P_0c0556bc;
P_0c0556bc: /* original f462, guest PC 0x0c0556bc */
if(!s->budget--) { s->failed_pc=0x0c0556bcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0556be;
P_0c0556be: /* original f72c, guest PC 0x0c0556be */
if(!s->budget--) { s->failed_pc=0x0c0556beu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c0556c0;
P_0c0556c0: /* original f82c, guest PC 0x0c0556c0 */
if(!s->budget--) { s->failed_pc=0x0c0556c0u; return 0; }
vf3_matrix_move(s,8,2);
goto P_0c0556c2;
P_0c0556c2: /* original f740, guest PC 0x0c0556c2 */
if(!s->budget--) { s->failed_pc=0x0c0556c2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'+');
goto P_0c0556c4;
P_0c0556c4: /* original f98d, guest PC 0x0c0556c4 */
if(!s->budget--) { s->failed_pc=0x0c0556c4u; return 0; }
fr[9]=0;
goto P_0c0556c6;
P_0c0556c6: /* original f841, guest PC 0x0c0556c6 */
if(!s->budget--) { s->failed_pc=0x0c0556c6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0556c8;
P_0c0556c8: /* original f975, guest PC 0x0c0556c8 */
if(!s->budget--) { s->failed_pc=0x0c0556c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[7]))!=0);
goto P_0c0556ca;
P_0c0556ca: /* original d339, guest PC 0x0c0556ca */
if(!s->budget--) { s->failed_pc=0x0c0556cau; return 0; }
r[3]=read(ram,0x0c0557b0u,4);
goto P_0c0556cc;
P_0c0556cc: /* original 8b01, guest PC 0x0c0556cc */
if(!s->budget--) { s->failed_pc=0x0c0556ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0556d2; }
goto P_0c0556ce;
P_0c0556ce: /* original a06b, guest PC 0x0c0556ce */
if(!s->budget--) { s->failed_pc=0x0c0556ceu; return 0; }
goto P_0c0557a8;
P_0c0556d0: /* original 0009, guest PC 0x0c0556d0 */
if(!s->budget--) { s->failed_pc=0x0c0556d0u; return 0; }
goto P_0c0556d2;
P_0c0556d2: /* original f855, guest PC 0x0c0556d2 */
if(!s->budget--) { s->failed_pc=0x0c0556d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c0556d4;
P_0c0556d4: /* original 8b01, guest PC 0x0c0556d4 */
if(!s->budget--) { s->failed_pc=0x0c0556d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0556da; }
goto P_0c0556d6;
P_0c0556d6: /* original a067, guest PC 0x0c0556d6 */
if(!s->budget--) { s->failed_pc=0x0c0556d6u; return 0; }
goto P_0c0557a8;
P_0c0556d8: /* original 0009, guest PC 0x0c0556d8 */
if(!s->budget--) { s->failed_pc=0x0c0556d8u; return 0; }
goto P_0c0556da;
P_0c0556da: /* original 4f22, guest PC 0x0c0556da */
if(!s->budget--) { s->failed_pc=0x0c0556dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0556dc;
P_0c0556dc: /* original 430b, guest PC 0x0c0556dc */
if(!s->budget--) { s->failed_pc=0x0c0556dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0556e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0556e0u) { target=s->pc; goto dispatch; }
goto P_0c0556e0;
P_0c0556de: /* original e400, guest PC 0x0c0556de */
if(!s->budget--) { s->failed_pc=0x0c0556deu; return 0; }
r[4]=0x00000000u;
goto P_0c0556e0;
P_0c0556e0: /* original c605, guest PC 0x0c0556e0 */
if(!s->budget--) { s->failed_pc=0x0c0556e0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+20,4);
goto P_0c0556e2;
P_0c0556e2: /* original 400b, guest PC 0x0c0556e2 */
if(!s->budget--) { s->failed_pc=0x0c0556e2u; return 0; }
target=r[0];
r[16]=code_base|0x0c0556e6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0556e6u) { target=s->pc; goto dispatch; }
goto P_0c0556e6;
P_0c0556e4: /* original 0009, guest PC 0x0c0556e4 */
if(!s->budget--) { s->failed_pc=0x0c0556e4u; return 0; }
goto P_0c0556e6;
P_0c0556e6: /* original 50d0, guest PC 0x0c0556e6 */
if(!s->budget--) { s->failed_pc=0x0c0556e6u; return 0; }
r[0]=read(ram,r[13]+0,4);
goto P_0c0556e8;
P_0c0556e8: /* original e120, guest PC 0x0c0556e8 */
if(!s->budget--) { s->failed_pc=0x0c0556e8u; return 0; }
r[1]=0x00000020u;
goto P_0c0556ea;
P_0c0556ea: /* original 2108, guest PC 0x0c0556ea */
if(!s->budget--) { s->failed_pc=0x0c0556eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[0])==0)!=0);
goto P_0c0556ec;
P_0c0556ec: /* original 890e, guest PC 0x0c0556ec */
if(!s->budget--) { s->failed_pc=0x0c0556ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05570c; }
goto P_0c0556ee;
P_0c0556ee: /* original d003, guest PC 0x0c0556ee */
if(!s->budget--) { s->failed_pc=0x0c0556eeu; return 0; }
r[0]=read(ram,0x0c0556fcu,4);
goto P_0c0556f0;
P_0c0556f0: /* original 6002, guest PC 0x0c0556f0 */
if(!s->budget--) { s->failed_pc=0x0c0556f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0556f2;
P_0c0556f2: /* original 2008, guest PC 0x0c0556f2 */
if(!s->budget--) { s->failed_pc=0x0c0556f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0556f4;
P_0c0556f4: /* original 8b06, guest PC 0x0c0556f4 */
if(!s->budget--) { s->failed_pc=0x0c0556f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055704; }
goto P_0c0556f6;
P_0c0556f6: /* original d002, guest PC 0x0c0556f6 */
if(!s->budget--) { s->failed_pc=0x0c0556f6u; return 0; }
r[0]=read(ram,0x0c055700u,4);
goto P_0c0556f8;
P_0c0556f8: /* original a005, guest PC 0x0c0556f8 */
if(!s->budget--) { s->failed_pc=0x0c0556f8u; return 0; }
goto P_0c055706;
P_0c0556fa: /* original 0009, guest PC 0x0c0556fa */
if(!s->budget--) { s->failed_pc=0x0c0556fau; return 0; }
if(!vf3_matrix_family(0x0c0556fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0556fcu; return 0; } return 1;
P_0c055704: /* original d025, guest PC 0x0c055704 */
if(!s->budget--) { s->failed_pc=0x0c055704u; return 0; }
r[0]=read(ram,0x0c05579cu,4);
goto P_0c055706;
P_0c055706: /* original 54d1, guest PC 0x0c055706 */
if(!s->budget--) { s->failed_pc=0x0c055706u; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c055708;
P_0c055708: /* original 400b, guest PC 0x0c055708 */
if(!s->budget--) { s->failed_pc=0x0c055708u; return 0; }
target=r[0];
r[16]=code_base|0x0c05570cu;
r[6]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05570cu) { target=s->pc; goto dispatch; }
goto P_0c05570c;
P_0c05570a: /* original 56d2, guest PC 0x0c05570a */
if(!s->budget--) { s->failed_pc=0x0c05570au; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c05570c;
P_0c05570c: /* original 64d3, guest PC 0x0c05570c */
if(!s->budget--) { s->failed_pc=0x0c05570cu; return 0; }
r[4]=r[13];
goto P_0c05570e;
P_0c05570e: /* original 7410, guest PC 0x0c05570e */
if(!s->budget--) { s->failed_pc=0x0c05570eu; return 0; }
r[4]+=0x00000010u;
goto P_0c055710;
P_0c055710: /* original c60a, guest PC 0x0c055710 */
if(!s->budget--) { s->failed_pc=0x0c055710u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+40,4);
goto P_0c055712;
P_0c055712: /* original f049, guest PC 0x0c055712 */
if(!s->budget--) { s->failed_pc=0x0c055712u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055714;
P_0c055714: /* original f149, guest PC 0x0c055714 */
if(!s->budget--) { s->failed_pc=0x0c055714u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055716;
P_0c055716: /* original f249, guest PC 0x0c055716 */
if(!s->budget--) { s->failed_pc=0x0c055716u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055718;
P_0c055718: /* original f39d, guest PC 0x0c055718 */
if(!s->budget--) { s->failed_pc=0x0c055718u; return 0; }
fr[3]=0x3f800000u;
goto P_0c05571a;
P_0c05571a: /* original f1fd, guest PC 0x0c05571a */
if(!s->budget--) { s->failed_pc=0x0c05571au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c05571c;
P_0c05571c: /* original 405a, guest PC 0x0c05571c */
if(!s->budget--) { s->failed_pc=0x0c05571cu; return 0; }
r[53]=r[0];
goto P_0c05571e;
P_0c05571e: /* original f60d, guest PC 0x0c05571e */
if(!s->budget--) { s->failed_pc=0x0c05571eu; return 0; }
fr[6]=r[53];
goto P_0c055720;
P_0c055720: /* original c727, guest PC 0x0c055720 */
if(!s->budget--) { s->failed_pc=0x0c055720u; return 0; }
r[0]=code_base|0x000557c0u;
goto P_0c055722;
P_0c055722: /* original 6002, guest PC 0x0c055722 */
if(!s->budget--) { s->failed_pc=0x0c055722u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c055724;
P_0c055724: /* original e302, guest PC 0x0c055724 */
if(!s->budget--) { s->failed_pc=0x0c055724u; return 0; }
r[3]=0x00000002u;
goto P_0c055726;
P_0c055726: /* original ff49, guest PC 0x0c055726 */
if(!s->budget--) { s->failed_pc=0x0c055726u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055728;
P_0c055728: /* original ff62, guest PC 0x0c055728 */
if(!s->budget--) { s->failed_pc=0x0c055728u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c05572a;
P_0c05572a: /* original f3fd, guest PC 0x0c05572a */
if(!s->budget--) { s->failed_pc=0x0c05572au; return 0; }
r[18]^=0x100000u;
goto P_0c05572c;
P_0c05572c: /* original f409, guest PC 0x0c05572c */
if(!s->budget--) { s->failed_pc=0x0c05572cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c05572e;
P_0c05572e: /* original f609, guest PC 0x0c05572e */
if(!s->budget--) { s->failed_pc=0x0c05572eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055730;
P_0c055730: /* original f809, guest PC 0x0c055730 */
if(!s->budget--) { s->failed_pc=0x0c055730u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055732;
P_0c055732: /* original fa09, guest PC 0x0c055732 */
if(!s->budget--) { s->failed_pc=0x0c055732u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c055734;
P_0c055734: /* original f4ed, guest PC 0x0c055734 */
if(!s->budget--) { s->failed_pc=0x0c055734u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c055736;
P_0c055736: /* original f8ed, guest PC 0x0c055736 */
if(!s->budget--) { s->failed_pc=0x0c055736u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c055738;
P_0c055738: /* original ff75, guest PC 0x0c055738 */
if(!s->budget--) { s->failed_pc=0x0c055738u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[7]))!=0);
goto P_0c05573a;
P_0c05573a: /* original f3fd, guest PC 0x0c05573a */
if(!s->budget--) { s->failed_pc=0x0c05573au; return 0; }
r[18]^=0x100000u;
goto P_0c05573c;
P_0c05573c: /* original 8b30, guest PC 0x0c05573c */
if(!s->budget--) { s->failed_pc=0x0c05573cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0557a0; }
goto P_0c05573e;
P_0c05573e: /* original ffb5, guest PC 0x0c05573e */
if(!s->budget--) { s->failed_pc=0x0c05573eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[11]))!=0);
goto P_0c055740;
P_0c055740: /* original 8b2e, guest PC 0x0c055740 */
if(!s->budget--) { s->failed_pc=0x0c055740u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0557a0; }
goto P_0c055742;
P_0c055742: /* original 4310, guest PC 0x0c055742 */
if(!s->budget--) { s->failed_pc=0x0c055742u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c055744;
P_0c055744: /* original 8bf1, guest PC 0x0c055744 */
if(!s->budget--) { s->failed_pc=0x0c055744u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05572a; }
goto P_0c055746;
P_0c055746: /* original c71c, guest PC 0x0c055746 */
if(!s->budget--) { s->failed_pc=0x0c055746u; return 0; }
r[0]=code_base|0x000557b8u;
goto P_0c055748;
P_0c055748: /* original d31a, guest PC 0x0c055748 */
if(!s->budget--) { s->failed_pc=0x0c055748u; return 0; }
r[3]=read(ram,0x0c0557b4u,4);
goto P_0c05574a;
P_0c05574a: /* original 6106, guest PC 0x0c05574a */
if(!s->budget--) { s->failed_pc=0x0c05574au; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c05574c;
P_0c05574c: /* original f418, guest PC 0x0c05574c */
if(!s->budget--) { s->failed_pc=0x0c05574cu; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
goto P_0c05574e;
P_0c05574e: /* original 6106, guest PC 0x0c05574e */
if(!s->budget--) { s->failed_pc=0x0c05574eu; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055750;
P_0c055750: /* original 430b, guest PC 0x0c055750 */
if(!s->budget--) { s->failed_pc=0x0c055750u; return 0; }
target=r[3];
r[16]=code_base|0x0c055754u;
vf3_matrix_load(s,ram,5,r[1]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055754u) { target=s->pc; goto dispatch; }
goto P_0c055754;
P_0c055752: /* original f518, guest PC 0x0c055752 */
if(!s->budget--) { s->failed_pc=0x0c055752u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
goto P_0c055754;
P_0c055754: /* original d11b, guest PC 0x0c055754 */
if(!s->budget--) { s->failed_pc=0x0c055754u; return 0; }
r[1]=read(ram,0x0c0557c4u,4);
goto P_0c055756;
P_0c055756: /* original c611, guest PC 0x0c055756 */
if(!s->budget--) { s->failed_pc=0x0c055756u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+68,4);
goto P_0c055758;
P_0c055758: /* original 6303, guest PC 0x0c055758 */
if(!s->budget--) { s->failed_pc=0x0c055758u; return 0; }
r[3]=r[0];
goto P_0c05575a;
P_0c05575a: /* original c604, guest PC 0x0c05575a */
if(!s->budget--) { s->failed_pc=0x0c05575au; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+16,4);
goto P_0c05575c;
P_0c05575c: /* original 54d1, guest PC 0x0c05575c */
if(!s->budget--) { s->failed_pc=0x0c05575cu; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c05575e;
P_0c05575e: /* original 56d2, guest PC 0x0c05575e */
if(!s->budget--) { s->failed_pc=0x0c05575eu; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c055760;
P_0c055760: /* original 4315, guest PC 0x0c055760 */
if(!s->budget--) { s->failed_pc=0x0c055760u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c055762;
P_0c055762: /* original 67d3, guest PC 0x0c055762 */
if(!s->budget--) { s->failed_pc=0x0c055762u; return 0; }
r[7]=r[13];
goto P_0c055764;
P_0c055764: /* original 8901, guest PC 0x0c055764 */
if(!s->budget--) { s->failed_pc=0x0c055764u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05576a; }
goto P_0c055766;
P_0c055766: /* original 400b, guest PC 0x0c055766 */
if(!s->budget--) { s->failed_pc=0x0c055766u; return 0; }
target=r[0];
r[16]=code_base|0x0c05576au;
tmp=read(ram,r[1],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05576au) { target=s->pc; goto dispatch; }
goto P_0c05576a;
P_0c055768: /* original 6512, guest PC 0x0c055768 */
if(!s->budget--) { s->failed_pc=0x0c055768u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c05576a;
P_0c05576a: /* original c719, guest PC 0x0c05576a */
if(!s->budget--) { s->failed_pc=0x0c05576au; return 0; }
r[0]=code_base|0x000557d0u;
goto P_0c05576c;
P_0c05576c: /* original da19, guest PC 0x0c05576c */
if(!s->budget--) { s->failed_pc=0x0c05576cu; return 0; }
r[10]=read(ram,0x0c0557d4u,4);
goto P_0c05576e;
P_0c05576e: /* original f308, guest PC 0x0c05576e */
if(!s->budget--) { s->failed_pc=0x0c05576eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c055770;
P_0c055770: /* original d314, guest PC 0x0c055770 */
if(!s->budget--) { s->failed_pc=0x0c055770u; return 0; }
r[3]=read(ram,0x0c0557c4u,4);
goto P_0c055772;
P_0c055772: /* original e1f0, guest PC 0x0c055772 */
if(!s->budget--) { s->failed_pc=0x0c055772u; return 0; }
r[1]=0xfffffff0u;
goto P_0c055774;
P_0c055774: /* original c603, guest PC 0x0c055774 */
if(!s->budget--) { s->failed_pc=0x0c055774u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+12,4);
goto P_0c055776;
P_0c055776: /* original 4128, guest PC 0x0c055776 */
if(!s->budget--) { s->failed_pc=0x0c055776u; return 0; }
r[1]<<=16;
goto P_0c055778;
P_0c055778: /* original 54d3, guest PC 0x0c055778 */
if(!s->budget--) { s->failed_pc=0x0c055778u; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c05577a;
P_0c05577a: /* original 4118, guest PC 0x0c05577a */
if(!s->budget--) { s->failed_pc=0x0c05577au; return 0; }
r[1]<<=8;
goto P_0c05577c;
P_0c05577c: /* original 6aa2, guest PC 0x0c05577c */
if(!s->budget--) { s->failed_pc=0x0c05577cu; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c05577e;
P_0c05577e: /* original e200, guest PC 0x0c05577e */
if(!s->budget--) { s->failed_pc=0x0c05577eu; return 0; }
r[2]=0x00000000u;
goto P_0c055780;
P_0c055780: /* original 6e03, guest PC 0x0c055780 */
if(!s->budget--) { s->failed_pc=0x0c055780u; return 0; }
r[14]=r[0];
goto P_0c055782;
P_0c055782: /* original 42be, guest PC 0x0c055782 */
if(!s->budget--) { s->failed_pc=0x0c055782u; return 0; }
if(!s->bank_known) goto unsupported;
s->bank[3]=r[2];
goto P_0c055784;
P_0c055784: /* original 6d32, guest PC 0x0c055784 */
if(!s->budget--) { s->failed_pc=0x0c055784u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c055786;
P_0c055786: /* original 41ce, guest PC 0x0c055786 */
if(!s->budget--) { s->failed_pc=0x0c055786u; return 0; }
if(!s->bank_known) goto unsupported;
s->bank[4]=r[1];
goto P_0c055788;
P_0c055788: /* original 6041, guest PC 0x0c055788 */
if(!s->budget--) { s->failed_pc=0x0c055788u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c05578a;
P_0c05578a: /* original 4011, guest PC 0x0c05578a */
if(!s->budget--) { s->failed_pc=0x0c05578au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c05578c;
P_0c05578c: /* original 600c, guest PC 0x0c05578c */
if(!s->budget--) { s->failed_pc=0x0c05578cu; return 0; }
r[0]=r[0]&255u;
goto P_0c05578e;
P_0c05578e: /* original 8f07, guest PC 0x0c05578e */
if(!s->budget--) { s->failed_pc=0x0c05578eu; return 0; }
cond=r[17]&1u;
r[0]<<=2;
if(!cond) { goto P_0c0557a0; }
goto P_0c055792;
P_0c055790: /* original 4008, guest PC 0x0c055790 */
if(!s->budget--) { s->failed_pc=0x0c055790u; return 0; }
r[0]<<=2;
goto P_0c055792;
P_0c055792: /* original 03ee, guest PC 0x0c055792 */
if(!s->budget--) { s->failed_pc=0x0c055792u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c055794;
P_0c055794: /* original 430b, guest PC 0x0c055794 */
if(!s->budget--) { s->failed_pc=0x0c055794u; return 0; }
target=r[3];
r[16]=code_base|0x0c055798u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055798u) { target=s->pc; goto dispatch; }
goto P_0c055798;
P_0c055796: /* original 0009, guest PC 0x0c055796 */
if(!s->budget--) { s->failed_pc=0x0c055796u; return 0; }
goto P_0c055798;
P_0c055798: /* original aff7, guest PC 0x0c055798 */
if(!s->budget--) { s->failed_pc=0x0c055798u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c05578a;
P_0c05579a: /* original 6041, guest PC 0x0c05579a */
if(!s->budget--) { s->failed_pc=0x0c05579au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
if(!vf3_matrix_family(0x0c05579cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05579cu; return 0; } return 1;
P_0c0557a0: /* original d30d, guest PC 0x0c0557a0 */
if(!s->budget--) { s->failed_pc=0x0c0557a0u; return 0; }
r[3]=read(ram,0x0c0557d8u,4);
goto P_0c0557a2;
P_0c0557a2: /* original 4f26, guest PC 0x0c0557a2 */
if(!s->budget--) { s->failed_pc=0x0c0557a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0557a4;
P_0c0557a4: /* original 432b, guest PC 0x0c0557a4 */
if(!s->budget--) { s->failed_pc=0x0c0557a4u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c0557a6: /* original e401, guest PC 0x0c0557a6 */
if(!s->budget--) { s->failed_pc=0x0c0557a6u; return 0; }
r[4]=0x00000001u;
goto P_0c0557a8;
P_0c0557a8: /* original 000b, guest PC 0x0c0557a8 */
if(!s->budget--) { s->failed_pc=0x0c0557a8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0557aa: /* original 0009, guest PC 0x0c0557aa */
if(!s->budget--) { s->failed_pc=0x0c0557aau; return 0; }
if(!vf3_matrix_family(0x0c0557acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0557acu; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
