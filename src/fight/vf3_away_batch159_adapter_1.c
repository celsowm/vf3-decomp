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
int vf3_away_batch159_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c0482u: goto P_0c0c0482;
case 0x0c0c0484u: goto P_0c0c0484;
case 0x0c0c0486u: goto P_0c0c0486;
case 0x0c0c0488u: goto P_0c0c0488;
case 0x0c0c048au: goto P_0c0c048a;
case 0x0c0c048cu: goto P_0c0c048c;
case 0x0c0c048eu: goto P_0c0c048e;
case 0x0c0c0490u: goto P_0c0c0490;
case 0x0c0c0492u: goto P_0c0c0492;
case 0x0c0c0494u: goto P_0c0c0494;
case 0x0c0c0496u: goto P_0c0c0496;
case 0x0c0c0498u: goto P_0c0c0498;
case 0x0c0c049au: goto P_0c0c049a;
case 0x0c0c049cu: goto P_0c0c049c;
case 0x0c0c049eu: goto P_0c0c049e;
case 0x0c0c04a0u: goto P_0c0c04a0;
case 0x0c0c04a2u: goto P_0c0c04a2;
case 0x0c0c04a4u: goto P_0c0c04a4;
case 0x0c0c04a6u: goto P_0c0c04a6;
case 0x0c0c04a8u: goto P_0c0c04a8;
case 0x0c0c04aau: goto P_0c0c04aa;
case 0x0c0c04acu: goto P_0c0c04ac;
case 0x0c0c04aeu: goto P_0c0c04ae;
case 0x0c0c04b0u: goto P_0c0c04b0;
case 0x0c0c04b2u: goto P_0c0c04b2;
case 0x0c0c04b4u: goto P_0c0c04b4;
case 0x0c0c04b6u: goto P_0c0c04b6;
case 0x0c0c04b8u: goto P_0c0c04b8;
case 0x0c0c04bau: goto P_0c0c04ba;
case 0x0c0c04bcu: goto P_0c0c04bc;
case 0x0c0c04beu: goto P_0c0c04be;
case 0x0c0c04c0u: goto P_0c0c04c0;
case 0x0c0c04c2u: goto P_0c0c04c2;
case 0x0c0c04c4u: goto P_0c0c04c4;
case 0x0c0c04c6u: goto P_0c0c04c6;
case 0x0c0c04c8u: goto P_0c0c04c8;
case 0x0c0c04cau: goto P_0c0c04ca;
case 0x0c0c04ccu: goto P_0c0c04cc;
case 0x0c0c04ceu: goto P_0c0c04ce;
case 0x0c0c04d0u: goto P_0c0c04d0;
case 0x0c0c04d2u: goto P_0c0c04d2;
case 0x0c0c04d4u: goto P_0c0c04d4;
case 0x0c0c04d6u: goto P_0c0c04d6;
case 0x0c0c04d8u: goto P_0c0c04d8;
case 0x0c0c04dau: goto P_0c0c04da;
case 0x0c0c04dcu: goto P_0c0c04dc;
case 0x0c0c04deu: goto P_0c0c04de;
case 0x0c0c04e0u: goto P_0c0c04e0;
case 0x0c0c0508u: goto P_0c0c0508;
case 0x0c0c050au: goto P_0c0c050a;
case 0x0c0c050cu: goto P_0c0c050c;
case 0x0c0c050eu: goto P_0c0c050e;
case 0x0c0c0510u: goto P_0c0c0510;
case 0x0c0c0512u: goto P_0c0c0512;
case 0x0c0c0514u: goto P_0c0c0514;
case 0x0c0c0516u: goto P_0c0c0516;
case 0x0c0c0518u: goto P_0c0c0518;
case 0x0c0c051au: goto P_0c0c051a;
case 0x0c0c051cu: goto P_0c0c051c;
case 0x0c0c051eu: goto P_0c0c051e;
case 0x0c0c0520u: goto P_0c0c0520;
case 0x0c0c0522u: goto P_0c0c0522;
case 0x0c0c0524u: goto P_0c0c0524;
case 0x0c0c0526u: goto P_0c0c0526;
case 0x0c0c0528u: goto P_0c0c0528;
case 0x0c0c052au: goto P_0c0c052a;
case 0x0c0c052cu: goto P_0c0c052c;
case 0x0c0c052eu: goto P_0c0c052e;
case 0x0c0c0530u: goto P_0c0c0530;
case 0x0c0c0532u: goto P_0c0c0532;
case 0x0c0c0534u: goto P_0c0c0534;
case 0x0c0c0536u: goto P_0c0c0536;
case 0x0c0c0538u: goto P_0c0c0538;
case 0x0c0c053au: goto P_0c0c053a;
case 0x0c0c053cu: goto P_0c0c053c;
case 0x0c0c053eu: goto P_0c0c053e;
case 0x0c0c0540u: goto P_0c0c0540;
case 0x0c0c0542u: goto P_0c0c0542;
case 0x0c0c0544u: goto P_0c0c0544;
case 0x0c0c0546u: goto P_0c0c0546;
case 0x0c0c0548u: goto P_0c0c0548;
case 0x0c0c054au: goto P_0c0c054a;
case 0x0c0c054cu: goto P_0c0c054c;
case 0x0c0c054eu: goto P_0c0c054e;
case 0x0c0c0550u: goto P_0c0c0550;
case 0x0c0c0552u: goto P_0c0c0552;
case 0x0c0c0554u: goto P_0c0c0554;
case 0x0c0c0556u: goto P_0c0c0556;
case 0x0c0c0558u: goto P_0c0c0558;
case 0x0c0c055au: goto P_0c0c055a;
case 0x0c0c055cu: goto P_0c0c055c;
case 0x0c0c055eu: goto P_0c0c055e;
case 0x0c0c0560u: goto P_0c0c0560;
case 0x0c0c0562u: goto P_0c0c0562;
case 0x0c0c0564u: goto P_0c0c0564;
case 0x0c0c0566u: goto P_0c0c0566;
case 0x0c0c0568u: goto P_0c0c0568;
case 0x0c0c056au: goto P_0c0c056a;
case 0x0c0c056cu: goto P_0c0c056c;
case 0x0c0c056eu: goto P_0c0c056e;
case 0x0c0c0570u: goto P_0c0c0570;
case 0x0c0c0572u: goto P_0c0c0572;
case 0x0c0c0574u: goto P_0c0c0574;
case 0x0c0c0576u: goto P_0c0c0576;
case 0x0c0c0578u: goto P_0c0c0578;
case 0x0c0c057au: goto P_0c0c057a;
case 0x0c0c057cu: goto P_0c0c057c;
case 0x0c0c057eu: goto P_0c0c057e;
case 0x0c0c0580u: goto P_0c0c0580;
case 0x0c0c0582u: goto P_0c0c0582;
case 0x0c0c0584u: goto P_0c0c0584;
case 0x0c0c0586u: goto P_0c0c0586;
case 0x0c0c0588u: goto P_0c0c0588;
case 0x0c0c058au: goto P_0c0c058a;
case 0x0c0c058cu: goto P_0c0c058c;
case 0x0c0c058eu: goto P_0c0c058e;
case 0x0c0c0590u: goto P_0c0c0590;
case 0x0c0c0592u: goto P_0c0c0592;
case 0x0c0c0594u: goto P_0c0c0594;
case 0x0c0c0596u: goto P_0c0c0596;
case 0x0c0c0598u: goto P_0c0c0598;
case 0x0c0c059au: goto P_0c0c059a;
case 0x0c0c059cu: goto P_0c0c059c;
case 0x0c0c059eu: goto P_0c0c059e;
case 0x0c0c05a0u: goto P_0c0c05a0;
case 0x0c0c05a2u: goto P_0c0c05a2;
case 0x0c0c05a4u: goto P_0c0c05a4;
case 0x0c0c05a6u: goto P_0c0c05a6;
case 0x0c0c05a8u: goto P_0c0c05a8;
case 0x0c0c05aau: goto P_0c0c05aa;
case 0x0c0c05acu: goto P_0c0c05ac;
case 0x0c0c05aeu: goto P_0c0c05ae;
case 0x0c0c05b0u: goto P_0c0c05b0;
case 0x0c0c05b2u: goto P_0c0c05b2;
case 0x0c0c05b4u: goto P_0c0c05b4;
case 0x0c0c05b6u: goto P_0c0c05b6;
case 0x0c0c05b8u: goto P_0c0c05b8;
case 0x0c0c05bau: goto P_0c0c05ba;
case 0x0c0c05bcu: goto P_0c0c05bc;
case 0x0c0c05beu: goto P_0c0c05be;
case 0x0c0c05c0u: goto P_0c0c05c0;
case 0x0c0c05c2u: goto P_0c0c05c2;
case 0x0c0c05c4u: goto P_0c0c05c4;
case 0x0c0c05c6u: goto P_0c0c05c6;
case 0x0c0c05c8u: goto P_0c0c05c8;
case 0x0c0c05cau: goto P_0c0c05ca;
case 0x0c0c05ccu: goto P_0c0c05cc;
case 0x0c0c05ceu: goto P_0c0c05ce;
case 0x0c0c05d0u: goto P_0c0c05d0;
case 0x0c0c05d2u: goto P_0c0c05d2;
case 0x0c0c05d4u: goto P_0c0c05d4;
case 0x0c0c05ecu: goto P_0c0c05ec;
case 0x0c0c05eeu: goto P_0c0c05ee;
case 0x0c0c05f0u: goto P_0c0c05f0;
case 0x0c0c05f2u: goto P_0c0c05f2;
case 0x0c0c05f4u: goto P_0c0c05f4;
case 0x0c0c05f6u: goto P_0c0c05f6;
case 0x0c0c05f8u: goto P_0c0c05f8;
case 0x0c0c05fau: goto P_0c0c05fa;
case 0x0c0c05fcu: goto P_0c0c05fc;
case 0x0c0c05feu: goto P_0c0c05fe;
case 0x0c0c0600u: goto P_0c0c0600;
case 0x0c0c0602u: goto P_0c0c0602;
case 0x0c0c0604u: goto P_0c0c0604;
case 0x0c0c0606u: goto P_0c0c0606;
case 0x0c0c0608u: goto P_0c0c0608;
case 0x0c0c060au: goto P_0c0c060a;
case 0x0c0c060cu: goto P_0c0c060c;
case 0x0c0c060eu: goto P_0c0c060e;
case 0x0c0c0610u: goto P_0c0c0610;
case 0x0c0c0612u: goto P_0c0c0612;
case 0x0c0c0614u: goto P_0c0c0614;
case 0x0c0c0616u: goto P_0c0c0616;
case 0x0c0c0618u: goto P_0c0c0618;
case 0x0c0c061au: goto P_0c0c061a;
case 0x0c0c061cu: goto P_0c0c061c;
case 0x0c0c061eu: goto P_0c0c061e;
case 0x0c0c0620u: goto P_0c0c0620;
case 0x0c0c0622u: goto P_0c0c0622;
case 0x0c0c0624u: goto P_0c0c0624;
case 0x0c0c0626u: goto P_0c0c0626;
case 0x0c0c0628u: goto P_0c0c0628;
case 0x0c0c062au: goto P_0c0c062a;
case 0x0c0c062cu: goto P_0c0c062c;
case 0x0c0c062eu: goto P_0c0c062e;
case 0x0c0c0630u: goto P_0c0c0630;
case 0x0c0c0632u: goto P_0c0c0632;
case 0x0c0c0634u: goto P_0c0c0634;
case 0x0c0c0636u: goto P_0c0c0636;
case 0x0c0c0638u: goto P_0c0c0638;
case 0x0c0c063au: goto P_0c0c063a;
case 0x0c0c063cu: goto P_0c0c063c;
case 0x0c0c063eu: goto P_0c0c063e;
case 0x0c0c0640u: goto P_0c0c0640;
case 0x0c0c0642u: goto P_0c0c0642;
case 0x0c0c0644u: goto P_0c0c0644;
case 0x0c0c0646u: goto P_0c0c0646;
case 0x0c0c0648u: goto P_0c0c0648;
case 0x0c0c064au: goto P_0c0c064a;
case 0x0c0c064cu: goto P_0c0c064c;
case 0x0c0c064eu: goto P_0c0c064e;
case 0x0c0c0650u: goto P_0c0c0650;
case 0x0c0c0652u: goto P_0c0c0652;
case 0x0c0c0654u: goto P_0c0c0654;
case 0x0c0c0656u: goto P_0c0c0656;
case 0x0c0c0658u: goto P_0c0c0658;
case 0x0c0c065au: goto P_0c0c065a;
case 0x0c0c065cu: goto P_0c0c065c;
case 0x0c0c065eu: goto P_0c0c065e;
case 0x0c0c0660u: goto P_0c0c0660;
case 0x0c0c0662u: goto P_0c0c0662;
case 0x0c0c0664u: goto P_0c0c0664;
case 0x0c0c0666u: goto P_0c0c0666;
case 0x0c0c0668u: goto P_0c0c0668;
case 0x0c0c066au: goto P_0c0c066a;
case 0x0c0c066cu: goto P_0c0c066c;
case 0x0c0c066eu: goto P_0c0c066e;
case 0x0c0c0670u: goto P_0c0c0670;
case 0x0c0c0672u: goto P_0c0c0672;
case 0x0c0c0674u: goto P_0c0c0674;
case 0x0c0c0676u: goto P_0c0c0676;
case 0x0c0c0678u: goto P_0c0c0678;
case 0x0c0c067au: goto P_0c0c067a;
case 0x0c0c067cu: goto P_0c0c067c;
case 0x0c0c067eu: goto P_0c0c067e;
case 0x0c0c0680u: goto P_0c0c0680;
case 0x0c0c0682u: goto P_0c0c0682;
case 0x0c0c0684u: goto P_0c0c0684;
case 0x0c0c0686u: goto P_0c0c0686;
case 0x0c0c0688u: goto P_0c0c0688;
case 0x0c0c068au: goto P_0c0c068a;
case 0x0c0c068cu: goto P_0c0c068c;
case 0x0c0c068eu: goto P_0c0c068e;
case 0x0c0c0690u: goto P_0c0c0690;
case 0x0c0c0692u: goto P_0c0c0692;
case 0x0c0c0694u: goto P_0c0c0694;
case 0x0c0c0696u: goto P_0c0c0696;
case 0x0c0c0698u: goto P_0c0c0698;
case 0x0c0c069au: goto P_0c0c069a;
case 0x0c0c069cu: goto P_0c0c069c;
case 0x0c0c069eu: goto P_0c0c069e;
case 0x0c0c06a0u: goto P_0c0c06a0;
case 0x0c0c06a2u: goto P_0c0c06a2;
case 0x0c0c06a4u: goto P_0c0c06a4;
case 0x0c0c06a6u: goto P_0c0c06a6;
case 0x0c0c06a8u: goto P_0c0c06a8;
case 0x0c0c06aau: goto P_0c0c06aa;
case 0x0c0c06acu: goto P_0c0c06ac;
case 0x0c0c06aeu: goto P_0c0c06ae;
case 0x0c0c06b0u: goto P_0c0c06b0;
case 0x0c0c06b2u: goto P_0c0c06b2;
case 0x0c0c06b4u: goto P_0c0c06b4;
case 0x0c0c06b6u: goto P_0c0c06b6;
case 0x0c0c06b8u: goto P_0c0c06b8;
case 0x0c0c06bau: goto P_0c0c06ba;
case 0x0c0c06bcu: goto P_0c0c06bc;
case 0x0c0c06beu: goto P_0c0c06be;
case 0x0c0c06c0u: goto P_0c0c06c0;
case 0x0c0c06c2u: goto P_0c0c06c2;
case 0x0c0c06c4u: goto P_0c0c06c4;
case 0x0c0c06c6u: goto P_0c0c06c6;
case 0x0c0c06c8u: goto P_0c0c06c8;
case 0x0c0c06cau: goto P_0c0c06ca;
case 0x0c0c06ccu: goto P_0c0c06cc;
case 0x0c0c06ceu: goto P_0c0c06ce;
case 0x0c0c06d0u: goto P_0c0c06d0;
case 0x0c0c06d2u: goto P_0c0c06d2;
case 0x0c0c06d4u: goto P_0c0c06d4;
case 0x0c0c06d6u: goto P_0c0c06d6;
case 0x0c0c06d8u: goto P_0c0c06d8;
case 0x0c0c06dau: goto P_0c0c06da;
case 0x0c0c06dcu: goto P_0c0c06dc;
case 0x0c0c06deu: goto P_0c0c06de;
case 0x0c0c06e0u: goto P_0c0c06e0;
case 0x0c0c06e2u: goto P_0c0c06e2;
case 0x0c0c06e4u: goto P_0c0c06e4;
case 0x0c0c0718u: goto P_0c0c0718;
case 0x0c0c071au: goto P_0c0c071a;
case 0x0c0c071cu: goto P_0c0c071c;
case 0x0c0c071eu: goto P_0c0c071e;
case 0x0c0c0720u: goto P_0c0c0720;
case 0x0c0c0722u: goto P_0c0c0722;
case 0x0c0c0724u: goto P_0c0c0724;
case 0x0c0c0726u: goto P_0c0c0726;
case 0x0c0c0728u: goto P_0c0c0728;
case 0x0c0c072au: goto P_0c0c072a;
case 0x0c0c072cu: goto P_0c0c072c;
case 0x0c0c072eu: goto P_0c0c072e;
case 0x0c0c0730u: goto P_0c0c0730;
case 0x0c0c0732u: goto P_0c0c0732;
case 0x0c0c0734u: goto P_0c0c0734;
case 0x0c0c0736u: goto P_0c0c0736;
case 0x0c0c0738u: goto P_0c0c0738;
case 0x0c0c073au: goto P_0c0c073a;
case 0x0c0c073cu: goto P_0c0c073c;
case 0x0c0c073eu: goto P_0c0c073e;
case 0x0c0c0740u: goto P_0c0c0740;
case 0x0c0c0742u: goto P_0c0c0742;
case 0x0c0c0744u: goto P_0c0c0744;
case 0x0c0c0746u: goto P_0c0c0746;
case 0x0c0c0748u: goto P_0c0c0748;
case 0x0c0c074au: goto P_0c0c074a;
case 0x0c0c074cu: goto P_0c0c074c;
case 0x0c0c074eu: goto P_0c0c074e;
case 0x0c0c0750u: goto P_0c0c0750;
case 0x0c0c0752u: goto P_0c0c0752;
case 0x0c0c0754u: goto P_0c0c0754;
case 0x0c0c0756u: goto P_0c0c0756;
case 0x0c0c0758u: goto P_0c0c0758;
case 0x0c0c075au: goto P_0c0c075a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c0482: /* original 2fe6, guest PC 0x0c0c0482 */
if(!s->budget--) { s->failed_pc=0x0c0c0482u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0484;
P_0c0c0484: /* original 6e43, guest PC 0x0c0c0484 */
if(!s->budget--) { s->failed_pc=0x0c0c0484u; return 0; }
r[14]=r[4];
goto P_0c0c0486;
P_0c0c0486: /* original 2fd6, guest PC 0x0c0c0486 */
if(!s->budget--) { s->failed_pc=0x0c0c0486u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0488;
P_0c0c0488: /* original 2fc6, guest PC 0x0c0c0488 */
if(!s->budget--) { s->failed_pc=0x0c0c0488u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c048a;
P_0c0c048a: /* original d41b, guest PC 0x0c0c048a */
if(!s->budget--) { s->failed_pc=0x0c0c048au; return 0; }
r[4]=read(ram,0x0c0c04f8u,4);
goto P_0c0c048c;
P_0c0c048c: /* original 4f22, guest PC 0x0c0c048c */
if(!s->budget--) { s->failed_pc=0x0c0c048cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c048e;
P_0c0c048e: /* original 534b, guest PC 0x0c0c048e */
if(!s->budget--) { s->failed_pc=0x0c0c048eu; return 0; }
r[3]=read(ram,r[4]+44,4);
goto P_0c0c0490;
P_0c0c0490: /* original 5d45, guest PC 0x0c0c0490 */
if(!s->budget--) { s->failed_pc=0x0c0c0490u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c0c0492;
P_0c0c0492: /* original 7fd0, guest PC 0x0c0c0492 */
if(!s->budget--) { s->failed_pc=0x0c0c0492u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c0c0494;
P_0c0c0494: /* original 5c44, guest PC 0x0c0c0494 */
if(!s->budget--) { s->failed_pc=0x0c0c0494u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c0c0496;
P_0c0c0496: /* original 1f3b, guest PC 0x0c0c0496 */
if(!s->budget--) { s->failed_pc=0x0c0c0496u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0c0498;
P_0c0c0498: /* original d119, guest PC 0x0c0c0498 */
if(!s->budget--) { s->failed_pc=0x0c0c0498u; return 0; }
r[1]=read(ram,0x0c0c0500u,4);
goto P_0c0c049a;
P_0c0c049a: /* original d318, guest PC 0x0c0c049a */
if(!s->budget--) { s->failed_pc=0x0c0c049au; return 0; }
r[3]=read(ram,0x0c0c04fcu,4);
goto P_0c0c049c;
P_0c0c049c: /* original 6212, guest PC 0x0c0c049c */
if(!s->budget--) { s->failed_pc=0x0c0c049cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c049e;
P_0c0c049e: /* original 2238, guest PC 0x0c0c049e */
if(!s->budget--) { s->failed_pc=0x0c0c049eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c04a0;
P_0c0c04a0: /* original 8b19, guest PC 0x0c0c04a0 */
if(!s->budget--) { s->failed_pc=0x0c0c04a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c04d6; }
goto P_0c0c04a2;
P_0c0c04a2: /* original 65d3, guest PC 0x0c0c04a2 */
if(!s->budget--) { s->failed_pc=0x0c0c04a2u; return 0; }
r[5]=r[13];
goto P_0c0c04a4;
P_0c0c04a4: /* original 66c3, guest PC 0x0c0c04a4 */
if(!s->budget--) { s->failed_pc=0x0c0c04a4u; return 0; }
r[6]=r[12];
goto P_0c0c04a6;
P_0c0c04a6: /* original 67f3, guest PC 0x0c0c04a6 */
if(!s->budget--) { s->failed_pc=0x0c0c04a6u; return 0; }
r[7]=r[15];
goto P_0c0c04a8;
P_0c0c04a8: /* original b02e, guest PC 0x0c0c04a8 */
if(!s->budget--) { s->failed_pc=0x0c0c04a8u; return 0; }
target=code_base|0x0c0c0508u; r[16]=code_base|0x0c0c04acu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c04acu) { target=s->pc; goto dispatch; }
goto P_0c0c04ac;
P_0c0c04aa: /* original 64e3, guest PC 0x0c0c04aa */
if(!s->budget--) { s->failed_pc=0x0c0c04aau; return 0; }
r[4]=r[14];
goto P_0c0c04ac;
P_0c0c04ac: /* original 65d3, guest PC 0x0c0c04ac */
if(!s->budget--) { s->failed_pc=0x0c0c04acu; return 0; }
r[5]=r[13];
goto P_0c0c04ae;
P_0c0c04ae: /* original 66c3, guest PC 0x0c0c04ae */
if(!s->budget--) { s->failed_pc=0x0c0c04aeu; return 0; }
r[6]=r[12];
goto P_0c0c04b0;
P_0c0c04b0: /* original 67f3, guest PC 0x0c0c04b0 */
if(!s->budget--) { s->failed_pc=0x0c0c04b0u; return 0; }
r[7]=r[15];
goto P_0c0c04b2;
P_0c0c04b2: /* original b153, guest PC 0x0c0c04b2 */
if(!s->budget--) { s->failed_pc=0x0c0c04b2u; return 0; }
target=code_base|0x0c0c075cu; r[16]=code_base|0x0c0c04b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c04b6u) { target=s->pc; goto dispatch; }
goto P_0c0c04b6;
P_0c0c04b4: /* original 64e3, guest PC 0x0c0c04b4 */
if(!s->budget--) { s->failed_pc=0x0c0c04b4u; return 0; }
r[4]=r[14];
goto P_0c0c04b6;
P_0c0c04b6: /* original 65d3, guest PC 0x0c0c04b6 */
if(!s->budget--) { s->failed_pc=0x0c0c04b6u; return 0; }
r[5]=r[13];
goto P_0c0c04b8;
P_0c0c04b8: /* original 66c3, guest PC 0x0c0c04b8 */
if(!s->budget--) { s->failed_pc=0x0c0c04b8u; return 0; }
r[6]=r[12];
goto P_0c0c04ba;
P_0c0c04ba: /* original 67f3, guest PC 0x0c0c04ba */
if(!s->budget--) { s->failed_pc=0x0c0c04bau; return 0; }
r[7]=r[15];
goto P_0c0c04bc;
P_0c0c04bc: /* original b39a, guest PC 0x0c0c04bc */
if(!s->budget--) { s->failed_pc=0x0c0c04bcu; return 0; }
target=code_base|0x0c0c0bf4u; r[16]=code_base|0x0c0c04c0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c04c0u) { target=s->pc; goto dispatch; }
goto P_0c0c04c0;
P_0c0c04be: /* original 64e3, guest PC 0x0c0c04be */
if(!s->budget--) { s->failed_pc=0x0c0c04beu; return 0; }
r[4]=r[14];
goto P_0c0c04c0;
P_0c0c04c0: /* original 52f5, guest PC 0x0c0c04c0 */
if(!s->budget--) { s->failed_pc=0x0c0c04c0u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0c04c2;
P_0c0c04c2: /* original e04a, guest PC 0x0c0c04c2 */
if(!s->budget--) { s->failed_pc=0x0c0c04c2u; return 0; }
r[0]=0x0000004au;
goto P_0c0c04c4;
P_0c0c04c4: /* original 65c3, guest PC 0x0c0c04c4 */
if(!s->budget--) { s->failed_pc=0x0c0c04c4u; return 0; }
r[5]=r[12];
goto P_0c0c04c6;
P_0c0c04c6: /* original 0e24, guest PC 0x0c0c04c6 */
if(!s->budget--) { s->failed_pc=0x0c0c04c6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c04c8;
P_0c0c04c8: /* original 53f3, guest PC 0x0c0c04c8 */
if(!s->budget--) { s->failed_pc=0x0c0c04c8u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c04ca;
P_0c0c04ca: /* original 2e32, guest PC 0x0c0c04ca */
if(!s->budget--) { s->failed_pc=0x0c0c04cau; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0c04cc;
P_0c0c04cc: /* original 56f3, guest PC 0x0c0c04cc */
if(!s->budget--) { s->failed_pc=0x0c0c04ccu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0c04ce;
P_0c0c04ce: /* original d30d, guest PC 0x0c0c04ce */
if(!s->budget--) { s->failed_pc=0x0c0c04ceu; return 0; }
r[3]=read(ram,0x0c0c0504u,4);
goto P_0c0c04d0;
P_0c0c04d0: /* original 57f5, guest PC 0x0c0c04d0 */
if(!s->budget--) { s->failed_pc=0x0c0c04d0u; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c0c04d2;
P_0c0c04d2: /* original 430b, guest PC 0x0c0c04d2 */
if(!s->budget--) { s->failed_pc=0x0c0c04d2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c04d6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c04d6u) { target=s->pc; goto dispatch; }
goto P_0c0c04d6;
P_0c0c04d4: /* original 64d3, guest PC 0x0c0c04d4 */
if(!s->budget--) { s->failed_pc=0x0c0c04d4u; return 0; }
r[4]=r[13];
goto P_0c0c04d6;
P_0c0c04d6: /* original 7f30, guest PC 0x0c0c04d6 */
if(!s->budget--) { s->failed_pc=0x0c0c04d6u; return 0; }
r[15]+=0x00000030u;
goto P_0c0c04d8;
P_0c0c04d8: /* original 4f26, guest PC 0x0c0c04d8 */
if(!s->budget--) { s->failed_pc=0x0c0c04d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c04da;
P_0c0c04da: /* original 6cf6, guest PC 0x0c0c04da */
if(!s->budget--) { s->failed_pc=0x0c0c04dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c04dc;
P_0c0c04dc: /* original 6df6, guest PC 0x0c0c04dc */
if(!s->budget--) { s->failed_pc=0x0c0c04dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c04de;
P_0c0c04de: /* original 000b, guest PC 0x0c0c04de */
if(!s->budget--) { s->failed_pc=0x0c0c04deu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c04e0: /* original 6ef6, guest PC 0x0c0c04e0 */
if(!s->budget--) { s->failed_pc=0x0c0c04e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c04e2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c04e2u; return 0; } return 1;
P_0c0c0508: /* original 2fe6, guest PC 0x0c0c0508 */
if(!s->budget--) { s->failed_pc=0x0c0c0508u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c050a;
P_0c0c050a: /* original 6e73, guest PC 0x0c0c050a */
if(!s->budget--) { s->failed_pc=0x0c0c050au; return 0; }
r[14]=r[7];
goto P_0c0c050c;
P_0c0c050c: /* original e061, guest PC 0x0c0c050c */
if(!s->budget--) { s->failed_pc=0x0c0c050cu; return 0; }
r[0]=0x00000061u;
goto P_0c0c050e;
P_0c0c050e: /* original 2fd6, guest PC 0x0c0c050e */
if(!s->budget--) { s->failed_pc=0x0c0c050eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0510;
P_0c0c0510: /* original 2fc6, guest PC 0x0c0c0510 */
if(!s->budget--) { s->failed_pc=0x0c0c0510u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0512;
P_0c0c0512: /* original 2fb6, guest PC 0x0c0c0512 */
if(!s->budget--) { s->failed_pc=0x0c0c0512u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0514;
P_0c0c0514: /* original 2fa6, guest PC 0x0c0c0514 */
if(!s->budget--) { s->failed_pc=0x0c0c0514u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0516;
P_0c0c0516: /* original 2f86, guest PC 0x0c0c0516 */
if(!s->budget--) { s->failed_pc=0x0c0c0516u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0518;
P_0c0c0518: /* original 535e, guest PC 0x0c0c0518 */
if(!s->budget--) { s->failed_pc=0x0c0c0518u; return 0; }
r[3]=read(ram,r[5]+56,4);
goto P_0c0c051a;
P_0c0c051a: /* original 4f22, guest PC 0x0c0c051a */
if(!s->budget--) { s->failed_pc=0x0c0c051au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c051c;
P_0c0c051c: /* original 1e32, guest PC 0x0c0c051c */
if(!s->budget--) { s->failed_pc=0x0c0c051cu; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c0c051e;
P_0c0c051e: /* original 6242, guest PC 0x0c0c051e */
if(!s->budget--) { s->failed_pc=0x0c0c051eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0c0520;
P_0c0c0520: /* original 7ff0, guest PC 0x0c0c0520 */
if(!s->budget--) { s->failed_pc=0x0c0c0520u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c0522;
P_0c0c0522: /* original 1e23, guest PC 0x0c0c0522 */
if(!s->budget--) { s->failed_pc=0x0c0c0522u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0c0524;
P_0c0c0524: /* original 035c, guest PC 0x0c0c0524 */
if(!s->budget--) { s->failed_pc=0x0c0c0524u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c0526;
P_0c0c0526: /* original e04a, guest PC 0x0c0c0526 */
if(!s->budget--) { s->failed_pc=0x0c0c0526u; return 0; }
r[0]=0x0000004au;
goto P_0c0c0528;
P_0c0c0528: /* original 633c, guest PC 0x0c0c0528 */
if(!s->budget--) { s->failed_pc=0x0c0c0528u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c052a;
P_0c0c052a: /* original 1e34, guest PC 0x0c0c052a */
if(!s->budget--) { s->failed_pc=0x0c0c052au; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0c052c;
P_0c0c052c: /* original 024c, guest PC 0x0c0c052c */
if(!s->budget--) { s->failed_pc=0x0c0c052cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c052e;
P_0c0c052e: /* original 1e25, guest PC 0x0c0c052e */
if(!s->budget--) { s->failed_pc=0x0c0c052eu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c0c0530;
P_0c0c0530: /* original 9051, guest PC 0x0c0c0530 */
if(!s->budget--) { s->failed_pc=0x0c0c0530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c05d6u,2);
goto P_0c0c0532;
P_0c0c0532: /* original 035c, guest PC 0x0c0c0532 */
if(!s->budget--) { s->failed_pc=0x0c0c0532u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c0534;
P_0c0c0534: /* original e048, guest PC 0x0c0c0534 */
if(!s->budget--) { s->failed_pc=0x0c0c0534u; return 0; }
r[0]=0x00000048u;
goto P_0c0c0536;
P_0c0c0536: /* original 633c, guest PC 0x0c0c0536 */
if(!s->budget--) { s->failed_pc=0x0c0c0536u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c0538;
P_0c0c0538: /* original 1e37, guest PC 0x0c0c0538 */
if(!s->budget--) { s->failed_pc=0x0c0c0538u; return 0; }
write(ram,r[14]+28,r[3],4);
goto P_0c0c053a;
P_0c0c053a: /* original 025e, guest PC 0x0c0c053a */
if(!s->budget--) { s->failed_pc=0x0c0c053au; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0c053c;
P_0c0c053c: /* original 1e28, guest PC 0x0c0c053c */
if(!s->budget--) { s->failed_pc=0x0c0c053cu; return 0; }
write(ram,r[14]+32,r[2],4);
goto P_0c0c053e;
P_0c0c053e: /* original 036e, guest PC 0x0c0c053e */
if(!s->budget--) { s->failed_pc=0x0c0c053eu; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c0c0540;
P_0c0c0540: /* original e050, guest PC 0x0c0c0540 */
if(!s->budget--) { s->failed_pc=0x0c0c0540u; return 0; }
r[0]=0x00000050u;
goto P_0c0c0542;
P_0c0c0542: /* original 1e39, guest PC 0x0c0c0542 */
if(!s->budget--) { s->failed_pc=0x0c0c0542u; return 0; }
write(ram,r[14]+36,r[3],4);
goto P_0c0c0544;
P_0c0c0544: /* original 025e, guest PC 0x0c0c0544 */
if(!s->budget--) { s->failed_pc=0x0c0c0544u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0c0546;
P_0c0c0546: /* original 1e2a, guest PC 0x0c0c0546 */
if(!s->budget--) { s->failed_pc=0x0c0c0546u; return 0; }
write(ram,r[14]+40,r[2],4);
goto P_0c0c0548;
P_0c0c0548: /* original d626, guest PC 0x0c0c0548 */
if(!s->budget--) { s->failed_pc=0x0c0c0548u; return 0; }
r[6]=read(ram,0x0c0c05e4u,4);
goto P_0c0c054a;
P_0c0c054a: /* original e30d, guest PC 0x0c0c054a */
if(!s->budget--) { s->failed_pc=0x0c0c054au; return 0; }
r[3]=0x0000000du;
goto P_0c0c054c;
P_0c0c054c: /* original 2e62, guest PC 0x0c0c054c */
if(!s->budget--) { s->failed_pc=0x0c0c054cu; return 0; }
write(ram,r[14],r[6],4);
goto P_0c0c054e;
P_0c0c054e: /* original 1e61, guest PC 0x0c0c054e */
if(!s->budget--) { s->failed_pc=0x0c0c054eu; return 0; }
write(ram,r[14]+4,r[6],4);
goto P_0c0c0550;
P_0c0c0550: /* original 56e4, guest PC 0x0c0c0550 */
if(!s->budget--) { s->failed_pc=0x0c0c0550u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c0c0552;
P_0c0c0552: /* original 62e2, guest PC 0x0c0c0552 */
if(!s->budget--) { s->failed_pc=0x0c0c0552u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0c0554;
P_0c0c0554: /* original 463c, guest PC 0x0c0c0554 */
if(!s->budget--) { s->failed_pc=0x0c0c0554u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c0c0556;
P_0c0c0556: /* original 362c, guest PC 0x0c0c0556 */
if(!s->budget--) { s->failed_pc=0x0c0c0556u; return 0; }
r[6]+=r[2];
goto P_0c0c0558;
P_0c0c0558: /* original 2e62, guest PC 0x0c0c0558 */
if(!s->budget--) { s->failed_pc=0x0c0c0558u; return 0; }
write(ram,r[14],r[6],4);
goto P_0c0c055a;
P_0c0c055a: /* original 56e4, guest PC 0x0c0c055a */
if(!s->budget--) { s->failed_pc=0x0c0c055au; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c0c055c;
P_0c0c055c: /* original 51e1, guest PC 0x0c0c055c */
if(!s->budget--) { s->failed_pc=0x0c0c055cu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c0c055e;
P_0c0c055e: /* original 4618, guest PC 0x0c0c055e */
if(!s->budget--) { s->failed_pc=0x0c0c055eu; return 0; }
r[6]<<=8;
goto P_0c0c0560;
P_0c0c0560: /* original 4608, guest PC 0x0c0c0560 */
if(!s->budget--) { s->failed_pc=0x0c0c0560u; return 0; }
r[6]<<=2;
goto P_0c0c0562;
P_0c0c0562: /* original 4608, guest PC 0x0c0c0562 */
if(!s->budget--) { s->failed_pc=0x0c0c0562u; return 0; }
r[6]<<=2;
goto P_0c0c0564;
P_0c0c0564: /* original 361c, guest PC 0x0c0c0564 */
if(!s->budget--) { s->failed_pc=0x0c0c0564u; return 0; }
r[6]+=r[1];
goto P_0c0c0566;
P_0c0c0566: /* original 1e61, guest PC 0x0c0c0566 */
if(!s->budget--) { s->failed_pc=0x0c0c0566u; return 0; }
write(ram,r[14]+4,r[6],4);
goto P_0c0c0568;
P_0c0c0568: /* original 8543, guest PC 0x0c0c0568 */
if(!s->budget--) { s->failed_pc=0x0c0c0568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c0c056a;
P_0c0c056a: /* original 620d, guest PC 0x0c0c056a */
if(!s->budget--) { s->failed_pc=0x0c0c056au; return 0; }
r[2]=r[0]&65535u;
goto P_0c0c056c;
P_0c0c056c: /* original 7201, guest PC 0x0c0c056c */
if(!s->budget--) { s->failed_pc=0x0c0c056cu; return 0; }
r[2]+=0x00000001u;
goto P_0c0c056e;
P_0c0c056e: /* original 1e26, guest PC 0x0c0c056e */
if(!s->budget--) { s->failed_pc=0x0c0c056eu; return 0; }
write(ram,r[14]+24,r[2],4);
goto P_0c0c0570;
P_0c0c0570: /* original 85ec, guest PC 0x0c0c0570 */
if(!s->budget--) { s->failed_pc=0x0c0c0570u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c0c0572;
P_0c0c0572: /* original 8143, guest PC 0x0c0c0572 */
if(!s->budget--) { s->failed_pc=0x0c0c0572u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0c0574;
P_0c0c0574: /* original d21c, guest PC 0x0c0c0574 */
if(!s->budget--) { s->failed_pc=0x0c0c0574u; return 0; }
r[2]=read(ram,0x0c0c05e8u,4);
goto P_0c0c0576;
P_0c0c0576: /* original 51e3, guest PC 0x0c0c0576 */
if(!s->budget--) { s->failed_pc=0x0c0c0576u; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c0c0578;
P_0c0c0578: /* original 2129, guest PC 0x0c0c0578 */
if(!s->budget--) { s->failed_pc=0x0c0c0578u; return 0; }
r[1]&=r[2];
goto P_0c0c057a;
P_0c0c057a: /* original 1e13, guest PC 0x0c0c057a */
if(!s->budget--) { s->failed_pc=0x0c0c057au; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c0c057c;
P_0c0c057c: /* original 902c, guest PC 0x0c0c057c */
if(!s->budget--) { s->failed_pc=0x0c0c057cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c05d8u,2);
goto P_0c0c057e;
P_0c0c057e: /* original 0c5e, guest PC 0x0c0c057e */
if(!s->budget--) { s->failed_pc=0x0c0c057eu; return 0; }
r[12]=read(ram,r[5]+r[0],4);
goto P_0c0c0580;
P_0c0c0580: /* original 7004, guest PC 0x0c0c0580 */
if(!s->budget--) { s->failed_pc=0x0c0c0580u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0582;
P_0c0c0582: /* original 0a5e, guest PC 0x0c0c0582 */
if(!s->budget--) { s->failed_pc=0x0c0c0582u; return 0; }
r[10]=read(ram,r[5]+r[0],4);
goto P_0c0c0584;
P_0c0c0584: /* original 7004, guest PC 0x0c0c0584 */
if(!s->budget--) { s->failed_pc=0x0c0c0584u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0586;
P_0c0c0586: /* original 0d5e, guest PC 0x0c0c0586 */
if(!s->budget--) { s->failed_pc=0x0c0c0586u; return 0; }
r[13]=read(ram,r[5]+r[0],4);
goto P_0c0c0588;
P_0c0c0588: /* original 7004, guest PC 0x0c0c0588 */
if(!s->budget--) { s->failed_pc=0x0c0c0588u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c058a;
P_0c0c058a: /* original 0b5e, guest PC 0x0c0c058a */
if(!s->budget--) { s->failed_pc=0x0c0c058au; return 0; }
r[11]=read(ram,r[5]+r[0],4);
goto P_0c0c058c;
P_0c0c058c: /* original e700, guest PC 0x0c0c058c */
if(!s->budget--) { s->failed_pc=0x0c0c058cu; return 0; }
r[7]=0x00000000u;
goto P_0c0c058e;
P_0c0c058e: /* original 9024, guest PC 0x0c0c058e */
if(!s->budget--) { s->failed_pc=0x0c0c058eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c05dau,2);
goto P_0c0c0590;
P_0c0c0590: /* original 034e, guest PC 0x0c0c0590 */
if(!s->budget--) { s->failed_pc=0x0c0c0590u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c0592;
P_0c0c0592: /* original 1f33, guest PC 0x0c0c0592 */
if(!s->budget--) { s->failed_pc=0x0c0c0592u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0c0594;
P_0c0c0594: /* original 9022, guest PC 0x0c0c0594 */
if(!s->budget--) { s->failed_pc=0x0c0c0594u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c05dcu,2);
goto P_0c0c0596;
P_0c0c0596: /* original 014e, guest PC 0x0c0c0596 */
if(!s->budget--) { s->failed_pc=0x0c0c0596u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0c0598;
P_0c0c0598: /* original 1f11, guest PC 0x0c0c0598 */
if(!s->budget--) { s->failed_pc=0x0c0c0598u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0c059a;
P_0c0c059a: /* original 9020, guest PC 0x0c0c059a */
if(!s->budget--) { s->failed_pc=0x0c0c059au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c05deu,2);
goto P_0c0c059c;
P_0c0c059c: /* original 034e, guest PC 0x0c0c059c */
if(!s->budget--) { s->failed_pc=0x0c0c059cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c059e;
P_0c0c059e: /* original 1f32, guest PC 0x0c0c059e */
if(!s->budget--) { s->failed_pc=0x0c0c059eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c05a0;
P_0c0c05a0: /* original 901e, guest PC 0x0c0c05a0 */
if(!s->budget--) { s->failed_pc=0x0c0c05a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c05e0u,2);
goto P_0c0c05a2;
P_0c0c05a2: /* original 014e, guest PC 0x0c0c05a2 */
if(!s->budget--) { s->failed_pc=0x0c0c05a2u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0c05a4;
P_0c0c05a4: /* original 2f12, guest PC 0x0c0c05a4 */
if(!s->budget--) { s->failed_pc=0x0c0c05a4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c05a6;
P_0c0c05a6: /* original 53f3, guest PC 0x0c0c05a6 */
if(!s->budget--) { s->failed_pc=0x0c0c05a6u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c05a8;
P_0c0c05a8: /* original 3c30, guest PC 0x0c0c05a8 */
if(!s->budget--) { s->failed_pc=0x0c0c05a8u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[3])!=0);
goto P_0c0c05aa;
P_0c0c05aa: /* original 8f02, guest PC 0x0c0c05aa */
if(!s->budget--) { s->failed_pc=0x0c0c05aau; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(!cond) { goto P_0c0c05b2; }
goto P_0c0c05ae;
P_0c0c05ac: /* original e601, guest PC 0x0c0c05ac */
if(!s->budget--) { s->failed_pc=0x0c0c05acu; return 0; }
r[6]=0x00000001u;
goto P_0c0c05ae;
P_0c0c05ae: /* original a001, guest PC 0x0c0c05ae */
if(!s->budget--) { s->failed_pc=0x0c0c05aeu; return 0; }
r[1]=r[7];
goto P_0c0c05b4;
P_0c0c05b0: /* original 6173, guest PC 0x0c0c05b0 */
if(!s->budget--) { s->failed_pc=0x0c0c05b0u; return 0; }
r[1]=r[7];
goto P_0c0c05b2;
P_0c0c05b2: /* original 6163, guest PC 0x0c0c05b2 */
if(!s->budget--) { s->failed_pc=0x0c0c05b2u; return 0; }
r[1]=r[6];
goto P_0c0c05b4;
P_0c0c05b4: /* original 52f1, guest PC 0x0c0c05b4 */
if(!s->budget--) { s->failed_pc=0x0c0c05b4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c05b6;
P_0c0c05b6: /* original 3a20, guest PC 0x0c0c05b6 */
if(!s->budget--) { s->failed_pc=0x0c0c05b6u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[2])!=0);
goto P_0c0c05b8;
P_0c0c05b8: /* original 8b01, guest PC 0x0c0c05b8 */
if(!s->budget--) { s->failed_pc=0x0c0c05b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c05be; }
goto P_0c0c05ba;
P_0c0c05ba: /* original a001, guest PC 0x0c0c05ba */
if(!s->budget--) { s->failed_pc=0x0c0c05bau; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0c05c0;
P_0c0c05bc: /* original 1f71, guest PC 0x0c0c05bc */
if(!s->budget--) { s->failed_pc=0x0c0c05bcu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0c05be;
P_0c0c05be: /* original 1f61, guest PC 0x0c0c05be */
if(!s->budget--) { s->failed_pc=0x0c0c05beu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0c05c0;
P_0c0c05c0: /* original 53f2, guest PC 0x0c0c05c0 */
if(!s->budget--) { s->failed_pc=0x0c0c05c0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c05c2;
P_0c0c05c2: /* original 3d30, guest PC 0x0c0c05c2 */
if(!s->budget--) { s->failed_pc=0x0c0c05c2u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c05c4;
P_0c0c05c4: /* original 8b01, guest PC 0x0c0c05c4 */
if(!s->budget--) { s->failed_pc=0x0c0c05c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c05ca; }
goto P_0c0c05c6;
P_0c0c05c6: /* original a001, guest PC 0x0c0c05c6 */
if(!s->budget--) { s->failed_pc=0x0c0c05c6u; return 0; }
r[8]=r[7];
goto P_0c0c05cc;
P_0c0c05c8: /* original 6873, guest PC 0x0c0c05c8 */
if(!s->budget--) { s->failed_pc=0x0c0c05c8u; return 0; }
r[8]=r[7];
goto P_0c0c05ca;
P_0c0c05ca: /* original 6863, guest PC 0x0c0c05ca */
if(!s->budget--) { s->failed_pc=0x0c0c05cau; return 0; }
r[8]=r[6];
goto P_0c0c05cc;
P_0c0c05cc: /* original 62f2, guest PC 0x0c0c05cc */
if(!s->budget--) { s->failed_pc=0x0c0c05ccu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c05ce;
P_0c0c05ce: /* original 3b20, guest PC 0x0c0c05ce */
if(!s->budget--) { s->failed_pc=0x0c0c05ceu; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[2])!=0);
goto P_0c0c05d0;
P_0c0c05d0: /* original 8b0c, guest PC 0x0c0c05d0 */
if(!s->budget--) { s->failed_pc=0x0c0c05d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c05ec; }
goto P_0c0c05d2;
P_0c0c05d2: /* original a00c, guest PC 0x0c0c05d2 */
if(!s->budget--) { s->failed_pc=0x0c0c05d2u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0c05ee;
P_0c0c05d4: /* original 2f72, guest PC 0x0c0c05d4 */
if(!s->budget--) { s->failed_pc=0x0c0c05d4u; return 0; }
write(ram,r[15],r[7],4);
if(!vf3_matrix_family(0x0c0c05d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c05d6u; return 0; } return 1;
P_0c0c05ec: /* original 2f62, guest PC 0x0c0c05ec */
if(!s->budget--) { s->failed_pc=0x0c0c05ecu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c05ee;
P_0c0c05ee: /* original 2118, guest PC 0x0c0c05ee */
if(!s->budget--) { s->failed_pc=0x0c0c05eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c05f0;
P_0c0c05f0: /* original 8905, guest PC 0x0c0c05f0 */
if(!s->budget--) { s->failed_pc=0x0c0c05f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c05fe; }
goto P_0c0c05f2;
P_0c0c05f2: /* original 9078, guest PC 0x0c0c05f2 */
if(!s->budget--) { s->failed_pc=0x0c0c05f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06e6u,2);
goto P_0c0c05f4;
P_0c0c05f4: /* original 04c6, guest PC 0x0c0c05f4 */
if(!s->budget--) { s->failed_pc=0x0c0c05f4u; return 0; }
write(ram,r[4]+r[0],r[12],4);
goto P_0c0c05f6;
P_0c0c05f6: /* original d341, guest PC 0x0c0c05f6 */
if(!s->budget--) { s->failed_pc=0x0c0c05f6u; return 0; }
r[3]=read(ram,0x0c0c06fcu,4);
goto P_0c0c05f8;
P_0c0c05f8: /* original 52e3, guest PC 0x0c0c05f8 */
if(!s->budget--) { s->failed_pc=0x0c0c05f8u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0c05fa;
P_0c0c05fa: /* original 223b, guest PC 0x0c0c05fa */
if(!s->budget--) { s->failed_pc=0x0c0c05fau; return 0; }
r[2]|=r[3];
goto P_0c0c05fc;
P_0c0c05fc: /* original 1e23, guest PC 0x0c0c05fc */
if(!s->budget--) { s->failed_pc=0x0c0c05fcu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0c05fe;
P_0c0c05fe: /* original 53f1, guest PC 0x0c0c05fe */
if(!s->budget--) { s->failed_pc=0x0c0c05feu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c0600;
P_0c0c0600: /* original 2338, guest PC 0x0c0c0600 */
if(!s->budget--) { s->failed_pc=0x0c0c0600u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c0602;
P_0c0c0602: /* original 8905, guest PC 0x0c0c0602 */
if(!s->budget--) { s->failed_pc=0x0c0c0602u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0610; }
goto P_0c0c0604;
P_0c0c0604: /* original 9070, guest PC 0x0c0c0604 */
if(!s->budget--) { s->failed_pc=0x0c0c0604u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06e8u,2);
goto P_0c0c0606;
P_0c0c0606: /* original 04a6, guest PC 0x0c0c0606 */
if(!s->budget--) { s->failed_pc=0x0c0c0606u; return 0; }
write(ram,r[4]+r[0],r[10],4);
goto P_0c0c0608;
P_0c0c0608: /* original d33d, guest PC 0x0c0c0608 */
if(!s->budget--) { s->failed_pc=0x0c0c0608u; return 0; }
r[3]=read(ram,0x0c0c0700u,4);
goto P_0c0c060a;
P_0c0c060a: /* original 52e3, guest PC 0x0c0c060a */
if(!s->budget--) { s->failed_pc=0x0c0c060au; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0c060c;
P_0c0c060c: /* original 223b, guest PC 0x0c0c060c */
if(!s->budget--) { s->failed_pc=0x0c0c060cu; return 0; }
r[2]|=r[3];
goto P_0c0c060e;
P_0c0c060e: /* original 1e23, guest PC 0x0c0c060e */
if(!s->budget--) { s->failed_pc=0x0c0c060eu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0c0610;
P_0c0c0610: /* original 2888, guest PC 0x0c0c0610 */
if(!s->budget--) { s->failed_pc=0x0c0c0610u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0c0612;
P_0c0c0612: /* original 8905, guest PC 0x0c0c0612 */
if(!s->budget--) { s->failed_pc=0x0c0c0612u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0620; }
goto P_0c0c0614;
P_0c0c0614: /* original 9069, guest PC 0x0c0c0614 */
if(!s->budget--) { s->failed_pc=0x0c0c0614u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06eau,2);
goto P_0c0c0616;
P_0c0c0616: /* original 04d6, guest PC 0x0c0c0616 */
if(!s->budget--) { s->failed_pc=0x0c0c0616u; return 0; }
write(ram,r[4]+r[0],r[13],4);
goto P_0c0c0618;
P_0c0c0618: /* original d33a, guest PC 0x0c0c0618 */
if(!s->budget--) { s->failed_pc=0x0c0c0618u; return 0; }
r[3]=read(ram,0x0c0c0704u,4);
goto P_0c0c061a;
P_0c0c061a: /* original 52e3, guest PC 0x0c0c061a */
if(!s->budget--) { s->failed_pc=0x0c0c061au; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0c061c;
P_0c0c061c: /* original 223b, guest PC 0x0c0c061c */
if(!s->budget--) { s->failed_pc=0x0c0c061cu; return 0; }
r[2]|=r[3];
goto P_0c0c061e;
P_0c0c061e: /* original 1e23, guest PC 0x0c0c061e */
if(!s->budget--) { s->failed_pc=0x0c0c061eu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0c0620;
P_0c0c0620: /* original 63f2, guest PC 0x0c0c0620 */
if(!s->budget--) { s->failed_pc=0x0c0c0620u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c0622;
P_0c0c0622: /* original 2338, guest PC 0x0c0c0622 */
if(!s->budget--) { s->failed_pc=0x0c0c0622u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c0624;
P_0c0c0624: /* original 8905, guest PC 0x0c0c0624 */
if(!s->budget--) { s->failed_pc=0x0c0c0624u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0632; }
goto P_0c0c0626;
P_0c0c0626: /* original 9061, guest PC 0x0c0c0626 */
if(!s->budget--) { s->failed_pc=0x0c0c0626u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06ecu,2);
goto P_0c0c0628;
P_0c0c0628: /* original 04b6, guest PC 0x0c0c0628 */
if(!s->budget--) { s->failed_pc=0x0c0c0628u; return 0; }
write(ram,r[4]+r[0],r[11],4);
goto P_0c0c062a;
P_0c0c062a: /* original d337, guest PC 0x0c0c062a */
if(!s->budget--) { s->failed_pc=0x0c0c062au; return 0; }
r[3]=read(ram,0x0c0c0708u,4);
goto P_0c0c062c;
P_0c0c062c: /* original 52e3, guest PC 0x0c0c062c */
if(!s->budget--) { s->failed_pc=0x0c0c062cu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0c062e;
P_0c0c062e: /* original 223b, guest PC 0x0c0c062e */
if(!s->budget--) { s->failed_pc=0x0c0c062eu; return 0; }
r[2]|=r[3];
goto P_0c0c0630;
P_0c0c0630: /* original 1e23, guest PC 0x0c0c0630 */
if(!s->budget--) { s->failed_pc=0x0c0c0630u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0c0632;
P_0c0c0632: /* original 52e3, guest PC 0x0c0c0632 */
if(!s->budget--) { s->failed_pc=0x0c0c0632u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0c0634;
P_0c0c0634: /* original e3fd, guest PC 0x0c0c0634 */
if(!s->budget--) { s->failed_pc=0x0c0c0634u; return 0; }
r[3]=0xfffffffdu;
goto P_0c0c0636;
P_0c0c0636: /* original 6652, guest PC 0x0c0c0636 */
if(!s->budget--) { s->failed_pc=0x0c0c0636u; return 0; }
tmp=read(ram,r[5],4);
r[6]=tmp;
goto P_0c0c0638;
P_0c0c0638: /* original 2239, guest PC 0x0c0c0638 */
if(!s->budget--) { s->failed_pc=0x0c0c0638u; return 0; }
r[2]&=r[3];
goto P_0c0c063a;
P_0c0c063a: /* original 1e23, guest PC 0x0c0c063a */
if(!s->budget--) { s->failed_pc=0x0c0c063au; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0c063c;
P_0c0c063c: /* original d133, guest PC 0x0c0c063c */
if(!s->budget--) { s->failed_pc=0x0c0c063cu; return 0; }
r[1]=read(ram,0x0c0c070cu,4);
goto P_0c0c063e;
P_0c0c063e: /* original 2618, guest PC 0x0c0c063e */
if(!s->budget--) { s->failed_pc=0x0c0c063eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[1])==0)!=0);
goto P_0c0c0640;
P_0c0c0640: /* original 8902, guest PC 0x0c0c0640 */
if(!s->budget--) { s->failed_pc=0x0c0c0640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0648; }
goto P_0c0c0642;
P_0c0c0642: /* original 50e3, guest PC 0x0c0c0642 */
if(!s->budget--) { s->failed_pc=0x0c0c0642u; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c0c0644;
P_0c0c0644: /* original cb02, guest PC 0x0c0c0644 */
if(!s->budget--) { s->failed_pc=0x0c0c0644u; return 0; }
r[0]|=2u;
goto P_0c0c0646;
P_0c0c0646: /* original 1e03, guest PC 0x0c0c0646 */
if(!s->budget--) { s->failed_pc=0x0c0c0646u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c0c0648;
P_0c0c0648: /* original e03e, guest PC 0x0c0c0648 */
if(!s->budget--) { s->failed_pc=0x0c0c0648u; return 0; }
r[0]=0x0000003eu;
goto P_0c0c064a;
P_0c0c064a: /* original 065d, guest PC 0x0c0c064a */
if(!s->budget--) { s->failed_pc=0x0c0c064au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c064c;
P_0c0c064c: /* original 904f, guest PC 0x0c0c064c */
if(!s->budget--) { s->failed_pc=0x0c0c064cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06eeu,2);
goto P_0c0c064e;
P_0c0c064e: /* original 666d, guest PC 0x0c0c064e */
if(!s->budget--) { s->failed_pc=0x0c0c064eu; return 0; }
r[6]=r[6]&65535u;
goto P_0c0c0650;
P_0c0c0650: /* original 0d5d, guest PC 0x0c0c0650 */
if(!s->budget--) { s->failed_pc=0x0c0c0650u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c0652;
P_0c0c0652: /* original 7004, guest PC 0x0c0c0652 */
if(!s->budget--) { s->failed_pc=0x0c0c0652u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0654;
P_0c0c0654: /* original 075d, guest PC 0x0c0c0654 */
if(!s->budget--) { s->failed_pc=0x0c0c0654u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c0656;
P_0c0c0656: /* original 70f0, guest PC 0x0c0c0656 */
if(!s->budget--) { s->failed_pc=0x0c0c0656u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c0c0658;
P_0c0c0658: /* original 0c5d, guest PC 0x0c0c0658 */
if(!s->budget--) { s->failed_pc=0x0c0c0658u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c065a;
P_0c0c065a: /* original 677d, guest PC 0x0c0c065a */
if(!s->budget--) { s->failed_pc=0x0c0c065au; return 0; }
r[7]=r[7]&65535u;
goto P_0c0c065c;
P_0c0c065c: /* original 6ccd, guest PC 0x0c0c065c */
if(!s->budget--) { s->failed_pc=0x0c0c065cu; return 0; }
r[12]=r[12]&65535u;
goto P_0c0c065e;
P_0c0c065e: /* original 37c7, guest PC 0x0c0c065e */
if(!s->budget--) { s->failed_pc=0x0c0c065eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[12])!=0);
goto P_0c0c0660;
P_0c0c0660: /* original 8f01, guest PC 0x0c0c0660 */
if(!s->budget--) { s->failed_pc=0x0c0c0660u; return 0; }
cond=r[17]&1u;
r[13]=r[13]&65535u;
if(!cond) { goto P_0c0c0666; }
goto P_0c0c0664;
P_0c0c0662: /* original 6ddd, guest PC 0x0c0c0662 */
if(!s->budget--) { s->failed_pc=0x0c0c0662u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0c0664;
P_0c0c0664: /* original 67c3, guest PC 0x0c0c0664 */
if(!s->budget--) { s->failed_pc=0x0c0c0664u; return 0; }
r[7]=r[12];
goto P_0c0c0666;
P_0c0c0666: /* original 3670, guest PC 0x0c0c0666 */
if(!s->budget--) { s->failed_pc=0x0c0c0666u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[7])!=0);
goto P_0c0c0668;
P_0c0c0668: /* original 8b02, guest PC 0x0c0c0668 */
if(!s->budget--) { s->failed_pc=0x0c0c0668u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0670; }
goto P_0c0c066a;
P_0c0c066a: /* original 50e3, guest PC 0x0c0c066a */
if(!s->budget--) { s->failed_pc=0x0c0c066au; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c0c066c;
P_0c0c066c: /* original cb04, guest PC 0x0c0c066c */
if(!s->budget--) { s->failed_pc=0x0c0c066cu; return 0; }
r[0]|=4u;
goto P_0c0c066e;
P_0c0c066e: /* original 1e03, guest PC 0x0c0c066e */
if(!s->budget--) { s->failed_pc=0x0c0c066eu; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c0c0670;
P_0c0c0670: /* original 36d0, guest PC 0x0c0c0670 */
if(!s->budget--) { s->failed_pc=0x0c0c0670u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[13])!=0);
goto P_0c0c0672;
P_0c0c0672: /* original 8b02, guest PC 0x0c0c0672 */
if(!s->budget--) { s->failed_pc=0x0c0c0672u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c067a; }
goto P_0c0c0674;
P_0c0c0674: /* original 50e3, guest PC 0x0c0c0674 */
if(!s->budget--) { s->failed_pc=0x0c0c0674u; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c0c0676;
P_0c0c0676: /* original cb08, guest PC 0x0c0c0676 */
if(!s->budget--) { s->failed_pc=0x0c0c0676u; return 0; }
r[0]|=8u;
goto P_0c0c0678;
P_0c0c0678: /* original 1e03, guest PC 0x0c0c0678 */
if(!s->budget--) { s->failed_pc=0x0c0c0678u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c0c067a;
P_0c0c067a: /* original 9739, guest PC 0x0c0c067a */
if(!s->budget--) { s->failed_pc=0x0c0c067au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06f0u,2);
goto P_0c0c067c;
P_0c0c067c: /* original 36d3, guest PC 0x0c0c067c */
if(!s->budget--) { s->failed_pc=0x0c0c067cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[13])!=0);
goto P_0c0c067e;
P_0c0c067e: /* original 8b0a, guest PC 0x0c0c067e */
if(!s->budget--) { s->failed_pc=0x0c0c067eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0696; }
goto P_0c0c0680;
P_0c0c0680: /* original 52e3, guest PC 0x0c0c0680 */
if(!s->budget--) { s->failed_pc=0x0c0c0680u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0c0682;
P_0c0c0682: /* original 9336, guest PC 0x0c0c0682 */
if(!s->budget--) { s->failed_pc=0x0c0c0682u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06f2u,2);
goto P_0c0c0684;
P_0c0c0684: /* original 2239, guest PC 0x0c0c0684 */
if(!s->budget--) { s->failed_pc=0x0c0c0684u; return 0; }
r[2]&=r[3];
goto P_0c0c0686;
P_0c0c0686: /* original 1e23, guest PC 0x0c0c0686 */
if(!s->budget--) { s->failed_pc=0x0c0c0686u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0c0688;
P_0c0c0688: /* original 51e8, guest PC 0x0c0c0688 */
if(!s->budget--) { s->failed_pc=0x0c0c0688u; return 0; }
r[1]=read(ram,r[14]+32,4);
goto P_0c0c068a;
P_0c0c068a: /* original d221, guest PC 0x0c0c068a */
if(!s->budget--) { s->failed_pc=0x0c0c068au; return 0; }
r[2]=read(ram,0x0c0c0710u,4);
goto P_0c0c068c;
P_0c0c068c: /* original 2128, guest PC 0x0c0c068c */
if(!s->budget--) { s->failed_pc=0x0c0c068cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0c068e;
P_0c0c068e: /* original 8902, guest PC 0x0c0c068e */
if(!s->budget--) { s->failed_pc=0x0c0c068eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0696; }
goto P_0c0c0690;
P_0c0c0690: /* original 51e3, guest PC 0x0c0c0690 */
if(!s->budget--) { s->failed_pc=0x0c0c0690u; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c0c0692;
P_0c0c0692: /* original 217b, guest PC 0x0c0c0692 */
if(!s->budget--) { s->failed_pc=0x0c0c0692u; return 0; }
r[1]|=r[7];
goto P_0c0c0694;
P_0c0c0694: /* original 1e13, guest PC 0x0c0c0694 */
if(!s->budget--) { s->failed_pc=0x0c0c0694u; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c0c0696;
P_0c0c0696: /* original 52e8, guest PC 0x0c0c0696 */
if(!s->budget--) { s->failed_pc=0x0c0c0696u; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c0c0698;
P_0c0c0698: /* original d31e, guest PC 0x0c0c0698 */
if(!s->budget--) { s->failed_pc=0x0c0c0698u; return 0; }
r[3]=read(ram,0x0c0c0714u,4);
goto P_0c0c069a;
P_0c0c069a: /* original 2238, guest PC 0x0c0c069a */
if(!s->budget--) { s->failed_pc=0x0c0c069au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c069c;
P_0c0c069c: /* original 8903, guest PC 0x0c0c069c */
if(!s->budget--) { s->failed_pc=0x0c0c069cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c06a6; }
goto P_0c0c069e;
P_0c0c069e: /* original 51e3, guest PC 0x0c0c069e */
if(!s->budget--) { s->failed_pc=0x0c0c069eu; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c0c06a0;
P_0c0c06a0: /* original 9328, guest PC 0x0c0c06a0 */
if(!s->budget--) { s->failed_pc=0x0c0c06a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06f4u,2);
goto P_0c0c06a2;
P_0c0c06a2: /* original 213b, guest PC 0x0c0c06a2 */
if(!s->budget--) { s->failed_pc=0x0c0c06a2u; return 0; }
r[1]|=r[3];
goto P_0c0c06a4;
P_0c0c06a4: /* original 1e13, guest PC 0x0c0c06a4 */
if(!s->budget--) { s->failed_pc=0x0c0c06a4u; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c0c06a6;
P_0c0c06a6: /* original 53e2, guest PC 0x0c0c06a6 */
if(!s->budget--) { s->failed_pc=0x0c0c06a6u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0c06a8;
P_0c0c06a8: /* original 4329, guest PC 0x0c0c06a8 */
if(!s->budget--) { s->failed_pc=0x0c0c06a8u; return 0; }
r[3]>>=16;
goto P_0c0c06aa;
P_0c0c06aa: /* original 4319, guest PC 0x0c0c06aa */
if(!s->budget--) { s->failed_pc=0x0c0c06aau; return 0; }
r[3]>>=8;
goto P_0c0c06ac;
P_0c0c06ac: /* original 633e, guest PC 0x0c0c06ac */
if(!s->budget--) { s->failed_pc=0x0c0c06acu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c0c06ae;
P_0c0c06ae: /* original 1f31, guest PC 0x0c0c06ae */
if(!s->budget--) { s->failed_pc=0x0c0c06aeu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c06b0;
P_0c0c06b0: /* original 9021, guest PC 0x0c0c06b0 */
if(!s->budget--) { s->failed_pc=0x0c0c06b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06f6u,2);
goto P_0c0c06b2;
P_0c0c06b2: /* original 025c, guest PC 0x0c0c06b2 */
if(!s->budget--) { s->failed_pc=0x0c0c06b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c06b4;
P_0c0c06b4: /* original 622c, guest PC 0x0c0c06b4 */
if(!s->budget--) { s->failed_pc=0x0c0c06b4u; return 0; }
r[2]=r[2]&255u;
goto P_0c0c06b6;
P_0c0c06b6: /* original 1f22, guest PC 0x0c0c06b6 */
if(!s->budget--) { s->failed_pc=0x0c0c06b6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0c06b8;
P_0c0c06b8: /* original 901e, guest PC 0x0c0c06b8 */
if(!s->budget--) { s->failed_pc=0x0c0c06b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06f8u,2);
goto P_0c0c06ba;
P_0c0c06ba: /* original 035c, guest PC 0x0c0c06ba */
if(!s->budget--) { s->failed_pc=0x0c0c06bau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c06bc;
P_0c0c06bc: /* original 633c, guest PC 0x0c0c06bc */
if(!s->budget--) { s->failed_pc=0x0c0c06bcu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c06be;
P_0c0c06be: /* original 2f32, guest PC 0x0c0c06be */
if(!s->budget--) { s->failed_pc=0x0c0c06beu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c06c0;
P_0c0c06c0: /* original 50f1, guest PC 0x0c0c06c0 */
if(!s->budget--) { s->failed_pc=0x0c0c06c0u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0c06c2;
P_0c0c06c2: /* original 881a, guest PC 0x0c0c06c2 */
if(!s->budget--) { s->failed_pc=0x0c0c06c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001au)!=0);
goto P_0c0c06c4;
P_0c0c06c4: /* original 8b08, guest PC 0x0c0c06c4 */
if(!s->budget--) { s->failed_pc=0x0c0c06c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c06d8; }
goto P_0c0c06c6;
P_0c0c06c6: /* original 53f2, guest PC 0x0c0c06c6 */
if(!s->budget--) { s->failed_pc=0x0c0c06c6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c06c8;
P_0c0c06c8: /* original 2338, guest PC 0x0c0c06c8 */
if(!s->budget--) { s->failed_pc=0x0c0c06c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c06ca;
P_0c0c06ca: /* original 8b05, guest PC 0x0c0c06ca */
if(!s->budget--) { s->failed_pc=0x0c0c06cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c06d8; }
goto P_0c0c06cc;
P_0c0c06cc: /* original 62f2, guest PC 0x0c0c06cc */
if(!s->budget--) { s->failed_pc=0x0c0c06ccu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c06ce;
P_0c0c06ce: /* original 3260, guest PC 0x0c0c06ce */
if(!s->budget--) { s->failed_pc=0x0c0c06ceu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[6])!=0);
goto P_0c0c06d0;
P_0c0c06d0: /* original 8b02, guest PC 0x0c0c06d0 */
if(!s->budget--) { s->failed_pc=0x0c0c06d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c06d8; }
goto P_0c0c06d2;
P_0c0c06d2: /* original 50e3, guest PC 0x0c0c06d2 */
if(!s->budget--) { s->failed_pc=0x0c0c06d2u; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c0c06d4;
P_0c0c06d4: /* original cb10, guest PC 0x0c0c06d4 */
if(!s->budget--) { s->failed_pc=0x0c0c06d4u; return 0; }
r[0]|=16u;
goto P_0c0c06d6;
P_0c0c06d6: /* original 1e03, guest PC 0x0c0c06d6 */
if(!s->budget--) { s->failed_pc=0x0c0c06d6u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c0c06d8;
P_0c0c06d8: /* original 53e3, guest PC 0x0c0c06d8 */
if(!s->budget--) { s->failed_pc=0x0c0c06d8u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c0c06da;
P_0c0c06da: /* original 2738, guest PC 0x0c0c06da */
if(!s->budget--) { s->failed_pc=0x0c0c06dau; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0c06dc;
P_0c0c06dc: /* original 8920, guest PC 0x0c0c06dc */
if(!s->budget--) { s->failed_pc=0x0c0c06dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0720; }
goto P_0c0c06de;
P_0c0c06de: /* original 900c, guest PC 0x0c0c06de */
if(!s->budget--) { s->failed_pc=0x0c0c06deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c06fau,2);
goto P_0c0c06e0;
P_0c0c06e0: /* original 055e, guest PC 0x0c0c06e0 */
if(!s->budget--) { s->failed_pc=0x0c0c06e0u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0c06e2;
P_0c0c06e2: /* original a019, guest PC 0x0c0c06e2 */
if(!s->budget--) { s->failed_pc=0x0c0c06e2u; return 0; }
goto P_0c0c0718;
P_0c0c06e4: /* original 0009, guest PC 0x0c0c06e4 */
if(!s->budget--) { s->failed_pc=0x0c0c06e4u; return 0; }
if(!vf3_matrix_family(0x0c0c06e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c06e6u; return 0; } return 1;
P_0c0c0718: /* original e040, guest PC 0x0c0c0718 */
if(!s->budget--) { s->failed_pc=0x0c0c0718u; return 0; }
r[0]=0x00000040u;
goto P_0c0c071a;
P_0c0c071a: /* original 064e, guest PC 0x0c0c071a */
if(!s->budget--) { s->failed_pc=0x0c0c071au; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c0c071c;
P_0c0c071c: /* original 256b, guest PC 0x0c0c071c */
if(!s->budget--) { s->failed_pc=0x0c0c071cu; return 0; }
r[5]|=r[6];
goto P_0c0c071e;
P_0c0c071e: /* original 0456, guest PC 0x0c0c071e */
if(!s->budget--) { s->failed_pc=0x0c0c071eu; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c0720;
P_0c0c0720: /* original 52e3, guest PC 0x0c0c0720 */
if(!s->budget--) { s->failed_pc=0x0c0c0720u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c0c0722;
P_0c0c0722: /* original 9362, guest PC 0x0c0c0722 */
if(!s->budget--) { s->failed_pc=0x0c0c0722u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07eau,2);
goto P_0c0c0724;
P_0c0c0724: /* original 2238, guest PC 0x0c0c0724 */
if(!s->budget--) { s->failed_pc=0x0c0c0724u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c0726;
P_0c0c0726: /* original 8910, guest PC 0x0c0c0726 */
if(!s->budget--) { s->failed_pc=0x0c0c0726u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c074a; }
goto P_0c0c0728;
P_0c0c0728: /* original e046, guest PC 0x0c0c0728 */
if(!s->budget--) { s->failed_pc=0x0c0c0728u; return 0; }
r[0]=0x00000046u;
goto P_0c0c072a;
P_0c0c072a: /* original 53e6, guest PC 0x0c0c072a */
if(!s->budget--) { s->failed_pc=0x0c0c072au; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0c072c;
P_0c0c072c: /* original 054d, guest PC 0x0c0c072c */
if(!s->budget--) { s->failed_pc=0x0c0c072cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c072e;
P_0c0c072e: /* original e21e, guest PC 0x0c0c072e */
if(!s->budget--) { s->failed_pc=0x0c0c072eu; return 0; }
r[2]=0x0000001eu;
goto P_0c0c0730;
P_0c0c0730: /* original 3358, guest PC 0x0c0c0730 */
if(!s->budget--) { s->failed_pc=0x0c0c0730u; return 0; }
r[3]-=r[5];
goto P_0c0c0732;
P_0c0c0732: /* original 6533, guest PC 0x0c0c0732 */
if(!s->budget--) { s->failed_pc=0x0c0c0732u; return 0; }
r[5]=r[3];
goto P_0c0c0734;
P_0c0c0734: /* original 3527, guest PC 0x0c0c0734 */
if(!s->budget--) { s->failed_pc=0x0c0c0734u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[2])!=0);
goto P_0c0c0736;
P_0c0c0736: /* original 8b08, guest PC 0x0c0c0736 */
if(!s->budget--) { s->failed_pc=0x0c0c0736u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c074a; }
goto P_0c0c0738;
P_0c0c0738: /* original 51e3, guest PC 0x0c0c0738 */
if(!s->budget--) { s->failed_pc=0x0c0c0738u; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c0c073a;
P_0c0c073a: /* original 9357, guest PC 0x0c0c073a */
if(!s->budget--) { s->failed_pc=0x0c0c073au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07ecu,2);
goto P_0c0c073c;
P_0c0c073c: /* original 9257, guest PC 0x0c0c073c */
if(!s->budget--) { s->failed_pc=0x0c0c073cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c07eeu,2);
goto P_0c0c073e;
P_0c0c073e: /* original 2139, guest PC 0x0c0c073e */
if(!s->budget--) { s->failed_pc=0x0c0c073eu; return 0; }
r[1]&=r[3];
goto P_0c0c0740;
P_0c0c0740: /* original 6013, guest PC 0x0c0c0740 */
if(!s->budget--) { s->failed_pc=0x0c0c0740u; return 0; }
r[0]=r[1];
goto P_0c0c0742;
P_0c0c0742: /* original 202b, guest PC 0x0c0c0742 */
if(!s->budget--) { s->failed_pc=0x0c0c0742u; return 0; }
r[0]|=r[2];
goto P_0c0c0744;
P_0c0c0744: /* original 1e03, guest PC 0x0c0c0744 */
if(!s->budget--) { s->failed_pc=0x0c0c0744u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c0c0746;
P_0c0c0746: /* original b479, guest PC 0x0c0c0746 */
if(!s->budget--) { s->failed_pc=0x0c0c0746u; return 0; }
target=code_base|0x0c0c103cu; r[16]=code_base|0x0c0c074au;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c074au) { target=s->pc; goto dispatch; }
goto P_0c0c074a;
P_0c0c0748: /* original 65e3, guest PC 0x0c0c0748 */
if(!s->budget--) { s->failed_pc=0x0c0c0748u; return 0; }
r[5]=r[14];
goto P_0c0c074a;
P_0c0c074a: /* original 7f10, guest PC 0x0c0c074a */
if(!s->budget--) { s->failed_pc=0x0c0c074au; return 0; }
r[15]+=0x00000010u;
goto P_0c0c074c;
P_0c0c074c: /* original 4f26, guest PC 0x0c0c074c */
if(!s->budget--) { s->failed_pc=0x0c0c074cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c074e;
P_0c0c074e: /* original 68f6, guest PC 0x0c0c074e */
if(!s->budget--) { s->failed_pc=0x0c0c074eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c0750;
P_0c0c0750: /* original 6af6, guest PC 0x0c0c0750 */
if(!s->budget--) { s->failed_pc=0x0c0c0750u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c0752;
P_0c0c0752: /* original 6bf6, guest PC 0x0c0c0752 */
if(!s->budget--) { s->failed_pc=0x0c0c0752u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c0754;
P_0c0c0754: /* original 6cf6, guest PC 0x0c0c0754 */
if(!s->budget--) { s->failed_pc=0x0c0c0754u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c0756;
P_0c0c0756: /* original 6df6, guest PC 0x0c0c0756 */
if(!s->budget--) { s->failed_pc=0x0c0c0756u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c0758;
P_0c0c0758: /* original 000b, guest PC 0x0c0c0758 */
if(!s->budget--) { s->failed_pc=0x0c0c0758u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c075a: /* original 6ef6, guest PC 0x0c0c075a */
if(!s->budget--) { s->failed_pc=0x0c0c075au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c075cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
