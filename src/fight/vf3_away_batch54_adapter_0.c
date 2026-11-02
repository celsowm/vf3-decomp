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
int vf3_away_batch54_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c03cce0u: goto P_0c03cce0;
case 0x0c03cce2u: goto P_0c03cce2;
case 0x0c03cce4u: goto P_0c03cce4;
case 0x0c03cce6u: goto P_0c03cce6;
case 0x0c03cce8u: goto P_0c03cce8;
case 0x0c03cceau: goto P_0c03ccea;
case 0x0c03ccecu: goto P_0c03ccec;
case 0x0c03cceeu: goto P_0c03ccee;
case 0x0c03ccf0u: goto P_0c03ccf0;
case 0x0c03ccf2u: goto P_0c03ccf2;
case 0x0c03ccf4u: goto P_0c03ccf4;
case 0x0c03ccf6u: goto P_0c03ccf6;
case 0x0c03ccf8u: goto P_0c03ccf8;
case 0x0c03ccfau: goto P_0c03ccfa;
case 0x0c0875f0u: goto P_0c0875f0;
case 0x0c0875f2u: goto P_0c0875f2;
case 0x0c0875f4u: goto P_0c0875f4;
case 0x0c0875f6u: goto P_0c0875f6;
case 0x0c0875f8u: goto P_0c0875f8;
case 0x0c0875fau: goto P_0c0875fa;
case 0x0c0875fcu: goto P_0c0875fc;
case 0x0c0875feu: goto P_0c0875fe;
case 0x0c087600u: goto P_0c087600;
case 0x0c087602u: goto P_0c087602;
case 0x0c087604u: goto P_0c087604;
case 0x0c087606u: goto P_0c087606;
case 0x0c087608u: goto P_0c087608;
case 0x0c08760au: goto P_0c08760a;
case 0x0c08760cu: goto P_0c08760c;
case 0x0c08760eu: goto P_0c08760e;
case 0x0c087610u: goto P_0c087610;
case 0x0c087612u: goto P_0c087612;
case 0x0c087614u: goto P_0c087614;
case 0x0c087616u: goto P_0c087616;
case 0x0c087618u: goto P_0c087618;
case 0x0c08761au: goto P_0c08761a;
case 0x0c08761cu: goto P_0c08761c;
case 0x0c08761eu: goto P_0c08761e;
case 0x0c087620u: goto P_0c087620;
case 0x0c087622u: goto P_0c087622;
case 0x0c087624u: goto P_0c087624;
case 0x0c087626u: goto P_0c087626;
case 0x0c087628u: goto P_0c087628;
case 0x0c08762au: goto P_0c08762a;
case 0x0c08762cu: goto P_0c08762c;
case 0x0c08762eu: goto P_0c08762e;
case 0x0c087630u: goto P_0c087630;
case 0x0c087632u: goto P_0c087632;
case 0x0c087634u: goto P_0c087634;
case 0x0c087636u: goto P_0c087636;
case 0x0c087638u: goto P_0c087638;
case 0x0c08763au: goto P_0c08763a;
case 0x0c08763cu: goto P_0c08763c;
case 0x0c08763eu: goto P_0c08763e;
case 0x0c087640u: goto P_0c087640;
case 0x0c087642u: goto P_0c087642;
case 0x0c087644u: goto P_0c087644;
case 0x0c087646u: goto P_0c087646;
case 0x0c087648u: goto P_0c087648;
case 0x0c08764au: goto P_0c08764a;
case 0x0c08764cu: goto P_0c08764c;
case 0x0c08764eu: goto P_0c08764e;
case 0x0c087650u: goto P_0c087650;
case 0x0c087652u: goto P_0c087652;
case 0x0c087654u: goto P_0c087654;
case 0x0c087656u: goto P_0c087656;
case 0x0c087658u: goto P_0c087658;
case 0x0c08765au: goto P_0c08765a;
case 0x0c08765cu: goto P_0c08765c;
case 0x0c08765eu: goto P_0c08765e;
case 0x0c087660u: goto P_0c087660;
case 0x0c087662u: goto P_0c087662;
case 0x0c087664u: goto P_0c087664;
case 0x0c087666u: goto P_0c087666;
case 0x0c087668u: goto P_0c087668;
case 0x0c08766au: goto P_0c08766a;
case 0x0c08766cu: goto P_0c08766c;
case 0x0c08766eu: goto P_0c08766e;
case 0x0c087670u: goto P_0c087670;
case 0x0c087672u: goto P_0c087672;
case 0x0c087674u: goto P_0c087674;
case 0x0c087676u: goto P_0c087676;
case 0x0c087678u: goto P_0c087678;
case 0x0c08767au: goto P_0c08767a;
case 0x0c08767cu: goto P_0c08767c;
case 0x0c08767eu: goto P_0c08767e;
case 0x0c087680u: goto P_0c087680;
case 0x0c087682u: goto P_0c087682;
case 0x0c087684u: goto P_0c087684;
case 0x0c087686u: goto P_0c087686;
case 0x0c087688u: goto P_0c087688;
case 0x0c08768au: goto P_0c08768a;
case 0x0c08768cu: goto P_0c08768c;
case 0x0c08768eu: goto P_0c08768e;
case 0x0c087690u: goto P_0c087690;
case 0x0c087692u: goto P_0c087692;
case 0x0c087694u: goto P_0c087694;
case 0x0c087696u: goto P_0c087696;
case 0x0c087698u: goto P_0c087698;
case 0x0c08769au: goto P_0c08769a;
case 0x0c08769cu: goto P_0c08769c;
case 0x0c08769eu: goto P_0c08769e;
case 0x0c0876a0u: goto P_0c0876a0;
case 0x0c0876a2u: goto P_0c0876a2;
case 0x0c0876a4u: goto P_0c0876a4;
case 0x0c0876a6u: goto P_0c0876a6;
case 0x0c0876a8u: goto P_0c0876a8;
case 0x0c0876aau: goto P_0c0876aa;
case 0x0c0876acu: goto P_0c0876ac;
case 0x0c0876aeu: goto P_0c0876ae;
case 0x0c0876b0u: goto P_0c0876b0;
case 0x0c0876b2u: goto P_0c0876b2;
case 0x0c0876b4u: goto P_0c0876b4;
case 0x0c0876b6u: goto P_0c0876b6;
case 0x0c0876b8u: goto P_0c0876b8;
case 0x0c0876bau: goto P_0c0876ba;
case 0x0c0876bcu: goto P_0c0876bc;
case 0x0c0876beu: goto P_0c0876be;
case 0x0c0876c0u: goto P_0c0876c0;
case 0x0c0876c2u: goto P_0c0876c2;
case 0x0c0876c4u: goto P_0c0876c4;
case 0x0c0876c6u: goto P_0c0876c6;
case 0x0c0876c8u: goto P_0c0876c8;
case 0x0c0876cau: goto P_0c0876ca;
case 0x0c0876ccu: goto P_0c0876cc;
case 0x0c0876ceu: goto P_0c0876ce;
case 0x0c0876d0u: goto P_0c0876d0;
case 0x0c0876d2u: goto P_0c0876d2;
case 0x0c0876d4u: goto P_0c0876d4;
case 0x0c0876d6u: goto P_0c0876d6;
case 0x0c0876d8u: goto P_0c0876d8;
case 0x0c0876dau: goto P_0c0876da;
case 0x0c0876dcu: goto P_0c0876dc;
case 0x0c0876deu: goto P_0c0876de;
case 0x0c0876e0u: goto P_0c0876e0;
case 0x0c0876e2u: goto P_0c0876e2;
case 0x0c0876e4u: goto P_0c0876e4;
case 0x0c0876e6u: goto P_0c0876e6;
case 0x0c0876e8u: goto P_0c0876e8;
case 0x0c0876eau: goto P_0c0876ea;
case 0x0c0876ecu: goto P_0c0876ec;
case 0x0c0876eeu: goto P_0c0876ee;
case 0x0c0876f0u: goto P_0c0876f0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c03cce0: /* original fbfd, guest PC 0x0c03cce0 */
if(!s->budget--) { s->failed_pc=0x0c03cce0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03cce2;
P_0c03cce2: /* original f09d, guest PC 0x0c03cce2 */
if(!s->budget--) { s->failed_pc=0x0c03cce2u; return 0; }
fr[0]=0x3f800000u;
goto P_0c03cce4;
P_0c03cce4: /* original f18d, guest PC 0x0c03cce4 */
if(!s->budget--) { s->failed_pc=0x0c03cce4u; return 0; }
fr[1]=0;
goto P_0c03cce6;
P_0c03cce6: /* original f28d, guest PC 0x0c03cce6 */
if(!s->budget--) { s->failed_pc=0x0c03cce6u; return 0; }
fr[2]=0;
goto P_0c03cce8;
P_0c03cce8: /* original f48d, guest PC 0x0c03cce8 */
if(!s->budget--) { s->failed_pc=0x0c03cce8u; return 0; }
fr[4]=0;
goto P_0c03ccea;
P_0c03ccea: /* original f59d, guest PC 0x0c03ccea */
if(!s->budget--) { s->failed_pc=0x0c03cceau; return 0; }
fr[5]=0x3f800000u;
goto P_0c03ccec;
P_0c03ccec: /* original f68d, guest PC 0x0c03ccec */
if(!s->budget--) { s->failed_pc=0x0c03ccecu; return 0; }
fr[6]=0;
goto P_0c03ccee;
P_0c03ccee: /* original f88d, guest PC 0x0c03ccee */
if(!s->budget--) { s->failed_pc=0x0c03cceeu; return 0; }
fr[8]=0;
goto P_0c03ccf0;
P_0c03ccf0: /* original f98d, guest PC 0x0c03ccf0 */
if(!s->budget--) { s->failed_pc=0x0c03ccf0u; return 0; }
fr[9]=0;
goto P_0c03ccf2;
P_0c03ccf2: /* original fa9d, guest PC 0x0c03ccf2 */
if(!s->budget--) { s->failed_pc=0x0c03ccf2u; return 0; }
fr[10]=0x3f800000u;
goto P_0c03ccf4;
P_0c03ccf4: /* original fbfd, guest PC 0x0c03ccf4 */
if(!s->budget--) { s->failed_pc=0x0c03ccf4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03ccf6;
P_0c03ccf6: /* original 0009, guest PC 0x0c03ccf6 */
if(!s->budget--) { s->failed_pc=0x0c03ccf6u; return 0; }
goto P_0c03ccf8;
P_0c03ccf8: /* original 000b, guest PC 0x0c03ccf8 */
if(!s->budget--) { s->failed_pc=0x0c03ccf8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03ccfa: /* original 0009, guest PC 0x0c03ccfa */
if(!s->budget--) { s->failed_pc=0x0c03ccfau; return 0; }
if(!vf3_matrix_family(0x0c03ccfcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ccfcu; return 0; } return 1;
P_0c0875f0: /* original 4f22, guest PC 0x0c0875f0 */
if(!s->budget--) { s->failed_pc=0x0c0875f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0875f2;
P_0c0875f2: /* original 90c6, guest PC 0x0c0875f2 */
if(!s->budget--) { s->failed_pc=0x0c0875f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087782u,2);
goto P_0c0875f4;
P_0c0875f4: /* original 3f0c, guest PC 0x0c0875f4 */
if(!s->budget--) { s->failed_pc=0x0c0875f4u; return 0; }
r[15]+=r[0];
goto P_0c0875f6;
P_0c0875f6: /* original 2f42, guest PC 0x0c0875f6 */
if(!s->budget--) { s->failed_pc=0x0c0875f6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0875f8;
P_0c0875f8: /* original 64f3, guest PC 0x0c0875f8 */
if(!s->budget--) { s->failed_pc=0x0c0875f8u; return 0; }
r[4]=r[15];
goto P_0c0875fa;
P_0c0875fa: /* original d363, guest PC 0x0c0875fa */
if(!s->budget--) { s->failed_pc=0x0c0875fau; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c0875fc;
P_0c0875fc: /* original 430b, guest PC 0x0c0875fc */
if(!s->budget--) { s->failed_pc=0x0c0875fcu; return 0; }
target=r[3];
r[16]=code_base|0x0c087600u;
r[4]+=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087600u) { target=s->pc; goto dispatch; }
goto P_0c087600;
P_0c0875fe: /* original 7444, guest PC 0x0c0875fe */
if(!s->budget--) { s->failed_pc=0x0c0875feu; return 0; }
r[4]+=0x00000044u;
goto P_0c087600;
P_0c087600: /* original d362, guest PC 0x0c087600 */
if(!s->budget--) { s->failed_pc=0x0c087600u; return 0; }
r[3]=read(ram,0x0c08778cu,4);
goto P_0c087602;
P_0c087602: /* original 430b, guest PC 0x0c087602 */
if(!s->budget--) { s->failed_pc=0x0c087602u; return 0; }
target=r[3];
r[16]=code_base|0x0c087606u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087606u) { target=s->pc; goto dispatch; }
goto P_0c087606;
P_0c087604: /* original 64f2, guest PC 0x0c087604 */
if(!s->budget--) { s->failed_pc=0x0c087604u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c087606;
P_0c087606: /* original d260, guest PC 0x0c087606 */
if(!s->budget--) { s->failed_pc=0x0c087606u; return 0; }
r[2]=read(ram,0x0c087788u,4);
goto P_0c087608;
P_0c087608: /* original 64f3, guest PC 0x0c087608 */
if(!s->budget--) { s->failed_pc=0x0c087608u; return 0; }
r[4]=r[15];
goto P_0c08760a;
P_0c08760a: /* original 420b, guest PC 0x0c08760a */
if(!s->budget--) { s->failed_pc=0x0c08760au; return 0; }
target=r[2];
r[16]=code_base|0x0c08760eu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08760eu) { target=s->pc; goto dispatch; }
goto P_0c08760e;
P_0c08760c: /* original 7404, guest PC 0x0c08760c */
if(!s->budget--) { s->failed_pc=0x0c08760cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08760e;
P_0c08760e: /* original e074, guest PC 0x0c08760e */
if(!s->budget--) { s->failed_pc=0x0c08760eu; return 0; }
r[0]=0x00000074u;
goto P_0c087610;
P_0c087610: /* original 64f3, guest PC 0x0c087610 */
if(!s->budget--) { s->failed_pc=0x0c087610u; return 0; }
r[4]=r[15];
goto P_0c087612;
P_0c087612: /* original f3f6, guest PC 0x0c087612 */
if(!s->budget--) { s->failed_pc=0x0c087612u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087614;
P_0c087614: /* original e034, guest PC 0x0c087614 */
if(!s->budget--) { s->failed_pc=0x0c087614u; return 0; }
r[0]=0x00000034u;
goto P_0c087616;
P_0c087616: /* original ff37, guest PC 0x0c087616 */
if(!s->budget--) { s->failed_pc=0x0c087616u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087618;
P_0c087618: /* original e078, guest PC 0x0c087618 */
if(!s->budget--) { s->failed_pc=0x0c087618u; return 0; }
r[0]=0x00000078u;
goto P_0c08761a;
P_0c08761a: /* original f3f6, guest PC 0x0c08761a */
if(!s->budget--) { s->failed_pc=0x0c08761au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08761c;
P_0c08761c: /* original e038, guest PC 0x0c08761c */
if(!s->budget--) { s->failed_pc=0x0c08761cu; return 0; }
r[0]=0x00000038u;
goto P_0c08761e;
P_0c08761e: /* original ff37, guest PC 0x0c08761e */
if(!s->budget--) { s->failed_pc=0x0c08761eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087620;
P_0c087620: /* original e07c, guest PC 0x0c087620 */
if(!s->budget--) { s->failed_pc=0x0c087620u; return 0; }
r[0]=0x0000007cu;
goto P_0c087622;
P_0c087622: /* original f3f6, guest PC 0x0c087622 */
if(!s->budget--) { s->failed_pc=0x0c087622u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087624;
P_0c087624: /* original e03c, guest PC 0x0c087624 */
if(!s->budget--) { s->failed_pc=0x0c087624u; return 0; }
r[0]=0x0000003cu;
goto P_0c087626;
P_0c087626: /* original ff37, guest PC 0x0c087626 */
if(!s->budget--) { s->failed_pc=0x0c087626u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087628;
P_0c087628: /* original d359, guest PC 0x0c087628 */
if(!s->budget--) { s->failed_pc=0x0c087628u; return 0; }
r[3]=read(ram,0x0c087790u,4);
goto P_0c08762a;
P_0c08762a: /* original 430b, guest PC 0x0c08762a */
if(!s->budget--) { s->failed_pc=0x0c08762au; return 0; }
target=r[3];
r[16]=code_base|0x0c08762eu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08762eu) { target=s->pc; goto dispatch; }
goto P_0c08762e;
P_0c08762c: /* original 7404, guest PC 0x0c08762c */
if(!s->budget--) { s->failed_pc=0x0c08762cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08762e;
P_0c08762e: /* original 91a9, guest PC 0x0c08762e */
if(!s->budget--) { s->failed_pc=0x0c08762eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087784u,2);
goto P_0c087630;
P_0c087630: /* original 3f1c, guest PC 0x0c087630 */
if(!s->budget--) { s->failed_pc=0x0c087630u; return 0; }
r[15]+=r[1];
goto P_0c087632;
P_0c087632: /* original 4f26, guest PC 0x0c087632 */
if(!s->budget--) { s->failed_pc=0x0c087632u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087634;
P_0c087634: /* original 000b, guest PC 0x0c087634 */
if(!s->budget--) { s->failed_pc=0x0c087634u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087636: /* original 0009, guest PC 0x0c087636 */
if(!s->budget--) { s->failed_pc=0x0c087636u; return 0; }
goto P_0c087638;
P_0c087638: /* original 2fe6, guest PC 0x0c087638 */
if(!s->budget--) { s->failed_pc=0x0c087638u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08763a;
P_0c08763a: /* original 6e43, guest PC 0x0c08763a */
if(!s->budget--) { s->failed_pc=0x0c08763au; return 0; }
r[14]=r[4];
goto P_0c08763c;
P_0c08763c: /* original 4f22, guest PC 0x0c08763c */
if(!s->budget--) { s->failed_pc=0x0c08763cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08763e;
P_0c08763e: /* original d352, guest PC 0x0c08763e */
if(!s->budget--) { s->failed_pc=0x0c08763eu; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c087640;
P_0c087640: /* original 7fc0, guest PC 0x0c087640 */
if(!s->budget--) { s->failed_pc=0x0c087640u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c087642;
P_0c087642: /* original 430b, guest PC 0x0c087642 */
if(!s->budget--) { s->failed_pc=0x0c087642u; return 0; }
target=r[3];
r[16]=code_base|0x0c087646u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087646u) { target=s->pc; goto dispatch; }
goto P_0c087646;
P_0c087644: /* original 64f3, guest PC 0x0c087644 */
if(!s->budget--) { s->failed_pc=0x0c087644u; return 0; }
r[4]=r[15];
goto P_0c087646;
P_0c087646: /* original f3e8, guest PC 0x0c087646 */
if(!s->budget--) { s->failed_pc=0x0c087646u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c087648;
P_0c087648: /* original e004, guest PC 0x0c087648 */
if(!s->budget--) { s->failed_pc=0x0c087648u; return 0; }
r[0]=0x00000004u;
goto P_0c08764a;
P_0c08764a: /* original ff3a, guest PC 0x0c08764a */
if(!s->budget--) { s->failed_pc=0x0c08764au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08764c;
P_0c08764c: /* original f3e6, guest PC 0x0c08764c */
if(!s->budget--) { s->failed_pc=0x0c08764cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08764e;
P_0c08764e: /* original e004, guest PC 0x0c08764e */
if(!s->budget--) { s->failed_pc=0x0c08764eu; return 0; }
r[0]=0x00000004u;
goto P_0c087650;
P_0c087650: /* original ff37, guest PC 0x0c087650 */
if(!s->budget--) { s->failed_pc=0x0c087650u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087652;
P_0c087652: /* original e008, guest PC 0x0c087652 */
if(!s->budget--) { s->failed_pc=0x0c087652u; return 0; }
r[0]=0x00000008u;
goto P_0c087654;
P_0c087654: /* original f3e6, guest PC 0x0c087654 */
if(!s->budget--) { s->failed_pc=0x0c087654u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087656;
P_0c087656: /* original e008, guest PC 0x0c087656 */
if(!s->budget--) { s->failed_pc=0x0c087656u; return 0; }
r[0]=0x00000008u;
goto P_0c087658;
P_0c087658: /* original ff37, guest PC 0x0c087658 */
if(!s->budget--) { s->failed_pc=0x0c087658u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08765a;
P_0c08765a: /* original e010, guest PC 0x0c08765a */
if(!s->budget--) { s->failed_pc=0x0c08765au; return 0; }
r[0]=0x00000010u;
goto P_0c08765c;
P_0c08765c: /* original f3e6, guest PC 0x0c08765c */
if(!s->budget--) { s->failed_pc=0x0c08765cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08765e;
P_0c08765e: /* original e010, guest PC 0x0c08765e */
if(!s->budget--) { s->failed_pc=0x0c08765eu; return 0; }
r[0]=0x00000010u;
goto P_0c087660;
P_0c087660: /* original ff37, guest PC 0x0c087660 */
if(!s->budget--) { s->failed_pc=0x0c087660u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087662;
P_0c087662: /* original e014, guest PC 0x0c087662 */
if(!s->budget--) { s->failed_pc=0x0c087662u; return 0; }
r[0]=0x00000014u;
goto P_0c087664;
P_0c087664: /* original f3e6, guest PC 0x0c087664 */
if(!s->budget--) { s->failed_pc=0x0c087664u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087666;
P_0c087666: /* original e014, guest PC 0x0c087666 */
if(!s->budget--) { s->failed_pc=0x0c087666u; return 0; }
r[0]=0x00000014u;
goto P_0c087668;
P_0c087668: /* original ff37, guest PC 0x0c087668 */
if(!s->budget--) { s->failed_pc=0x0c087668u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08766a;
P_0c08766a: /* original e018, guest PC 0x0c08766a */
if(!s->budget--) { s->failed_pc=0x0c08766au; return 0; }
r[0]=0x00000018u;
goto P_0c08766c;
P_0c08766c: /* original f3e6, guest PC 0x0c08766c */
if(!s->budget--) { s->failed_pc=0x0c08766cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08766e;
P_0c08766e: /* original e018, guest PC 0x0c08766e */
if(!s->budget--) { s->failed_pc=0x0c08766eu; return 0; }
r[0]=0x00000018u;
goto P_0c087670;
P_0c087670: /* original ff37, guest PC 0x0c087670 */
if(!s->budget--) { s->failed_pc=0x0c087670u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087672;
P_0c087672: /* original e020, guest PC 0x0c087672 */
if(!s->budget--) { s->failed_pc=0x0c087672u; return 0; }
r[0]=0x00000020u;
goto P_0c087674;
P_0c087674: /* original f3e6, guest PC 0x0c087674 */
if(!s->budget--) { s->failed_pc=0x0c087674u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087676;
P_0c087676: /* original e020, guest PC 0x0c087676 */
if(!s->budget--) { s->failed_pc=0x0c087676u; return 0; }
r[0]=0x00000020u;
goto P_0c087678;
P_0c087678: /* original ff37, guest PC 0x0c087678 */
if(!s->budget--) { s->failed_pc=0x0c087678u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08767a;
P_0c08767a: /* original e024, guest PC 0x0c08767a */
if(!s->budget--) { s->failed_pc=0x0c08767au; return 0; }
r[0]=0x00000024u;
goto P_0c08767c;
P_0c08767c: /* original f3e6, guest PC 0x0c08767c */
if(!s->budget--) { s->failed_pc=0x0c08767cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08767e;
P_0c08767e: /* original e024, guest PC 0x0c08767e */
if(!s->budget--) { s->failed_pc=0x0c08767eu; return 0; }
r[0]=0x00000024u;
goto P_0c087680;
P_0c087680: /* original ff37, guest PC 0x0c087680 */
if(!s->budget--) { s->failed_pc=0x0c087680u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087682;
P_0c087682: /* original e028, guest PC 0x0c087682 */
if(!s->budget--) { s->failed_pc=0x0c087682u; return 0; }
r[0]=0x00000028u;
goto P_0c087684;
P_0c087684: /* original f3e6, guest PC 0x0c087684 */
if(!s->budget--) { s->failed_pc=0x0c087684u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087686;
P_0c087686: /* original e028, guest PC 0x0c087686 */
if(!s->budget--) { s->failed_pc=0x0c087686u; return 0; }
r[0]=0x00000028u;
goto P_0c087688;
P_0c087688: /* original ff37, guest PC 0x0c087688 */
if(!s->budget--) { s->failed_pc=0x0c087688u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08768a;
P_0c08768a: /* original d341, guest PC 0x0c08768a */
if(!s->budget--) { s->failed_pc=0x0c08768au; return 0; }
r[3]=read(ram,0x0c087790u,4);
goto P_0c08768c;
P_0c08768c: /* original 430b, guest PC 0x0c08768c */
if(!s->budget--) { s->failed_pc=0x0c08768cu; return 0; }
target=r[3];
r[16]=code_base|0x0c087690u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087690u) { target=s->pc; goto dispatch; }
goto P_0c087690;
P_0c08768e: /* original 64f3, guest PC 0x0c08768e */
if(!s->budget--) { s->failed_pc=0x0c08768eu; return 0; }
r[4]=r[15];
goto P_0c087690;
P_0c087690: /* original 7f40, guest PC 0x0c087690 */
if(!s->budget--) { s->failed_pc=0x0c087690u; return 0; }
r[15]+=0x00000040u;
goto P_0c087692;
P_0c087692: /* original 4f26, guest PC 0x0c087692 */
if(!s->budget--) { s->failed_pc=0x0c087692u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087694;
P_0c087694: /* original 000b, guest PC 0x0c087694 */
if(!s->budget--) { s->failed_pc=0x0c087694u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087696: /* original 6ef6, guest PC 0x0c087696 */
if(!s->budget--) { s->failed_pc=0x0c087696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c087698;
P_0c087698: /* original 2fe6, guest PC 0x0c087698 */
if(!s->budget--) { s->failed_pc=0x0c087698u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08769a;
P_0c08769a: /* original 6e43, guest PC 0x0c08769a */
if(!s->budget--) { s->failed_pc=0x0c08769au; return 0; }
r[14]=r[4];
goto P_0c08769c;
P_0c08769c: /* original 4f22, guest PC 0x0c08769c */
if(!s->budget--) { s->failed_pc=0x0c08769cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08769e;
P_0c08769e: /* original d33a, guest PC 0x0c08769e */
if(!s->budget--) { s->failed_pc=0x0c08769eu; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c0876a0;
P_0c0876a0: /* original 7fc0, guest PC 0x0c0876a0 */
if(!s->budget--) { s->failed_pc=0x0c0876a0u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c0876a2;
P_0c0876a2: /* original 430b, guest PC 0x0c0876a2 */
if(!s->budget--) { s->failed_pc=0x0c0876a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0876a6u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0876a6u) { target=s->pc; goto dispatch; }
goto P_0c0876a6;
P_0c0876a4: /* original 64f3, guest PC 0x0c0876a4 */
if(!s->budget--) { s->failed_pc=0x0c0876a4u; return 0; }
r[4]=r[15];
goto P_0c0876a6;
P_0c0876a6: /* original f3f8, guest PC 0x0c0876a6 */
if(!s->budget--) { s->failed_pc=0x0c0876a6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0876a8;
P_0c0876a8: /* original e004, guest PC 0x0c0876a8 */
if(!s->budget--) { s->failed_pc=0x0c0876a8u; return 0; }
r[0]=0x00000004u;
goto P_0c0876aa;
P_0c0876aa: /* original fe3a, guest PC 0x0c0876aa */
if(!s->budget--) { s->failed_pc=0x0c0876aau; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0876ac;
P_0c0876ac: /* original f3f6, guest PC 0x0c0876ac */
if(!s->budget--) { s->failed_pc=0x0c0876acu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876ae;
P_0c0876ae: /* original e004, guest PC 0x0c0876ae */
if(!s->budget--) { s->failed_pc=0x0c0876aeu; return 0; }
r[0]=0x00000004u;
goto P_0c0876b0;
P_0c0876b0: /* original fe37, guest PC 0x0c0876b0 */
if(!s->budget--) { s->failed_pc=0x0c0876b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876b2;
P_0c0876b2: /* original e008, guest PC 0x0c0876b2 */
if(!s->budget--) { s->failed_pc=0x0c0876b2u; return 0; }
r[0]=0x00000008u;
goto P_0c0876b4;
P_0c0876b4: /* original f3f6, guest PC 0x0c0876b4 */
if(!s->budget--) { s->failed_pc=0x0c0876b4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876b6;
P_0c0876b6: /* original e008, guest PC 0x0c0876b6 */
if(!s->budget--) { s->failed_pc=0x0c0876b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0876b8;
P_0c0876b8: /* original fe37, guest PC 0x0c0876b8 */
if(!s->budget--) { s->failed_pc=0x0c0876b8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ba;
P_0c0876ba: /* original e010, guest PC 0x0c0876ba */
if(!s->budget--) { s->failed_pc=0x0c0876bau; return 0; }
r[0]=0x00000010u;
goto P_0c0876bc;
P_0c0876bc: /* original f3f6, guest PC 0x0c0876bc */
if(!s->budget--) { s->failed_pc=0x0c0876bcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876be;
P_0c0876be: /* original e010, guest PC 0x0c0876be */
if(!s->budget--) { s->failed_pc=0x0c0876beu; return 0; }
r[0]=0x00000010u;
goto P_0c0876c0;
P_0c0876c0: /* original fe37, guest PC 0x0c0876c0 */
if(!s->budget--) { s->failed_pc=0x0c0876c0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876c2;
P_0c0876c2: /* original e014, guest PC 0x0c0876c2 */
if(!s->budget--) { s->failed_pc=0x0c0876c2u; return 0; }
r[0]=0x00000014u;
goto P_0c0876c4;
P_0c0876c4: /* original f3f6, guest PC 0x0c0876c4 */
if(!s->budget--) { s->failed_pc=0x0c0876c4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876c6;
P_0c0876c6: /* original e014, guest PC 0x0c0876c6 */
if(!s->budget--) { s->failed_pc=0x0c0876c6u; return 0; }
r[0]=0x00000014u;
goto P_0c0876c8;
P_0c0876c8: /* original fe37, guest PC 0x0c0876c8 */
if(!s->budget--) { s->failed_pc=0x0c0876c8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ca;
P_0c0876ca: /* original e018, guest PC 0x0c0876ca */
if(!s->budget--) { s->failed_pc=0x0c0876cau; return 0; }
r[0]=0x00000018u;
goto P_0c0876cc;
P_0c0876cc: /* original f3f6, guest PC 0x0c0876cc */
if(!s->budget--) { s->failed_pc=0x0c0876ccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876ce;
P_0c0876ce: /* original e018, guest PC 0x0c0876ce */
if(!s->budget--) { s->failed_pc=0x0c0876ceu; return 0; }
r[0]=0x00000018u;
goto P_0c0876d0;
P_0c0876d0: /* original fe37, guest PC 0x0c0876d0 */
if(!s->budget--) { s->failed_pc=0x0c0876d0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876d2;
P_0c0876d2: /* original e020, guest PC 0x0c0876d2 */
if(!s->budget--) { s->failed_pc=0x0c0876d2u; return 0; }
r[0]=0x00000020u;
goto P_0c0876d4;
P_0c0876d4: /* original f3f6, guest PC 0x0c0876d4 */
if(!s->budget--) { s->failed_pc=0x0c0876d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876d6;
P_0c0876d6: /* original e020, guest PC 0x0c0876d6 */
if(!s->budget--) { s->failed_pc=0x0c0876d6u; return 0; }
r[0]=0x00000020u;
goto P_0c0876d8;
P_0c0876d8: /* original fe37, guest PC 0x0c0876d8 */
if(!s->budget--) { s->failed_pc=0x0c0876d8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876da;
P_0c0876da: /* original e024, guest PC 0x0c0876da */
if(!s->budget--) { s->failed_pc=0x0c0876dau; return 0; }
r[0]=0x00000024u;
goto P_0c0876dc;
P_0c0876dc: /* original f3f6, guest PC 0x0c0876dc */
if(!s->budget--) { s->failed_pc=0x0c0876dcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876de;
P_0c0876de: /* original e024, guest PC 0x0c0876de */
if(!s->budget--) { s->failed_pc=0x0c0876deu; return 0; }
r[0]=0x00000024u;
goto P_0c0876e0;
P_0c0876e0: /* original fe37, guest PC 0x0c0876e0 */
if(!s->budget--) { s->failed_pc=0x0c0876e0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876e2;
P_0c0876e2: /* original e028, guest PC 0x0c0876e2 */
if(!s->budget--) { s->failed_pc=0x0c0876e2u; return 0; }
r[0]=0x00000028u;
goto P_0c0876e4;
P_0c0876e4: /* original f3f6, guest PC 0x0c0876e4 */
if(!s->budget--) { s->failed_pc=0x0c0876e4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876e6;
P_0c0876e6: /* original 7f40, guest PC 0x0c0876e6 */
if(!s->budget--) { s->failed_pc=0x0c0876e6u; return 0; }
r[15]+=0x00000040u;
goto P_0c0876e8;
P_0c0876e8: /* original 4f26, guest PC 0x0c0876e8 */
if(!s->budget--) { s->failed_pc=0x0c0876e8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0876ea;
P_0c0876ea: /* original e028, guest PC 0x0c0876ea */
if(!s->budget--) { s->failed_pc=0x0c0876eau; return 0; }
r[0]=0x00000028u;
goto P_0c0876ec;
P_0c0876ec: /* original fe37, guest PC 0x0c0876ec */
if(!s->budget--) { s->failed_pc=0x0c0876ecu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ee;
P_0c0876ee: /* original 000b, guest PC 0x0c0876ee */
if(!s->budget--) { s->failed_pc=0x0c0876eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0876f0: /* original 6ef6, guest PC 0x0c0876f0 */
if(!s->budget--) { s->failed_pc=0x0c0876f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0876f2u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
