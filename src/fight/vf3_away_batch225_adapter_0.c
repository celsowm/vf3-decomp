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
int vf3_away_batch225_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2e06u: goto P_0c0a2e06;
case 0x0c0a2e08u: goto P_0c0a2e08;
case 0x0c0a2e0au: goto P_0c0a2e0a;
case 0x0c0a2e0cu: goto P_0c0a2e0c;
case 0x0c0a2e0eu: goto P_0c0a2e0e;
case 0x0c0a2e10u: goto P_0c0a2e10;
case 0x0c0a2e12u: goto P_0c0a2e12;
case 0x0c0a2e14u: goto P_0c0a2e14;
case 0x0c0a2e16u: goto P_0c0a2e16;
case 0x0c0a2e18u: goto P_0c0a2e18;
case 0x0c0a2e1au: goto P_0c0a2e1a;
case 0x0c0a2e1cu: goto P_0c0a2e1c;
case 0x0c0a2e1eu: goto P_0c0a2e1e;
case 0x0c0a2e20u: goto P_0c0a2e20;
case 0x0c0a2e22u: goto P_0c0a2e22;
case 0x0c0a2e24u: goto P_0c0a2e24;
case 0x0c0a2e26u: goto P_0c0a2e26;
case 0x0c0a2e28u: goto P_0c0a2e28;
case 0x0c0a2e2au: goto P_0c0a2e2a;
case 0x0c0b36b6u: goto P_0c0b36b6;
case 0x0c0b36b8u: goto P_0c0b36b8;
case 0x0c0b36bau: goto P_0c0b36ba;
case 0x0c0b36bcu: goto P_0c0b36bc;
case 0x0c0b36beu: goto P_0c0b36be;
case 0x0c0b36c0u: goto P_0c0b36c0;
case 0x0c0b36c2u: goto P_0c0b36c2;
case 0x0c0b36c4u: goto P_0c0b36c4;
case 0x0c0b36c6u: goto P_0c0b36c6;
case 0x0c0b36c8u: goto P_0c0b36c8;
case 0x0c0b36cau: goto P_0c0b36ca;
case 0x0c0b36ccu: goto P_0c0b36cc;
case 0x0c0b36ceu: goto P_0c0b36ce;
case 0x0c0b36d0u: goto P_0c0b36d0;
case 0x0c0b36d2u: goto P_0c0b36d2;
case 0x0c0b36d4u: goto P_0c0b36d4;
case 0x0c0b36d6u: goto P_0c0b36d6;
case 0x0c0b36d8u: goto P_0c0b36d8;
case 0x0c0b36dau: goto P_0c0b36da;
case 0x0c0b36dcu: goto P_0c0b36dc;
case 0x0c0b36deu: goto P_0c0b36de;
case 0x0c0b36e0u: goto P_0c0b36e0;
case 0x0c0b36e2u: goto P_0c0b36e2;
case 0x0c0b36e4u: goto P_0c0b36e4;
case 0x0c0b36e6u: goto P_0c0b36e6;
case 0x0c0b36e8u: goto P_0c0b36e8;
case 0x0c0b36eau: goto P_0c0b36ea;
case 0x0c0b36ecu: goto P_0c0b36ec;
case 0x0c0b36eeu: goto P_0c0b36ee;
case 0x0c0b36f0u: goto P_0c0b36f0;
case 0x0c0b36f2u: goto P_0c0b36f2;
case 0x0c0b36f4u: goto P_0c0b36f4;
case 0x0c0b36f6u: goto P_0c0b36f6;
case 0x0c0b36f8u: goto P_0c0b36f8;
case 0x0c0b36fau: goto P_0c0b36fa;
case 0x0c0b36fcu: goto P_0c0b36fc;
case 0x0c0b36feu: goto P_0c0b36fe;
case 0x0c0b3700u: goto P_0c0b3700;
case 0x0c0b3702u: goto P_0c0b3702;
case 0x0c0b3704u: goto P_0c0b3704;
case 0x0c0b3706u: goto P_0c0b3706;
case 0x0c0b3708u: goto P_0c0b3708;
case 0x0c0b370au: goto P_0c0b370a;
case 0x0c0b370cu: goto P_0c0b370c;
case 0x0c0b370eu: goto P_0c0b370e;
case 0x0c0b3710u: goto P_0c0b3710;
case 0x0c0b3712u: goto P_0c0b3712;
case 0x0c0b3714u: goto P_0c0b3714;
case 0x0c0b3716u: goto P_0c0b3716;
case 0x0c0b3718u: goto P_0c0b3718;
case 0x0c0b371au: goto P_0c0b371a;
case 0x0c0b371cu: goto P_0c0b371c;
case 0x0c0b371eu: goto P_0c0b371e;
case 0x0c0b3720u: goto P_0c0b3720;
case 0x0c0b3722u: goto P_0c0b3722;
case 0x0c0b3724u: goto P_0c0b3724;
case 0x0c0b3726u: goto P_0c0b3726;
case 0x0c0b3728u: goto P_0c0b3728;
case 0x0c0b372au: goto P_0c0b372a;
case 0x0c0b372cu: goto P_0c0b372c;
case 0x0c0b372eu: goto P_0c0b372e;
case 0x0c0b3730u: goto P_0c0b3730;
case 0x0c0b3732u: goto P_0c0b3732;
case 0x0c0b3734u: goto P_0c0b3734;
case 0x0c0b3736u: goto P_0c0b3736;
case 0x0c0b3738u: goto P_0c0b3738;
case 0x0c0b373au: goto P_0c0b373a;
case 0x0c0b373cu: goto P_0c0b373c;
case 0x0c0b373eu: goto P_0c0b373e;
case 0x0c0b3740u: goto P_0c0b3740;
case 0x0c0b3742u: goto P_0c0b3742;
case 0x0c0b3744u: goto P_0c0b3744;
case 0x0c0b3746u: goto P_0c0b3746;
case 0x0c0b3748u: goto P_0c0b3748;
case 0x0c0b374au: goto P_0c0b374a;
case 0x0c0b374cu: goto P_0c0b374c;
case 0x0c0b374eu: goto P_0c0b374e;
case 0x0c0b3750u: goto P_0c0b3750;
case 0x0c0b3752u: goto P_0c0b3752;
case 0x0c0b3754u: goto P_0c0b3754;
case 0x0c0b3756u: goto P_0c0b3756;
case 0x0c0b3758u: goto P_0c0b3758;
case 0x0c0b375au: goto P_0c0b375a;
case 0x0c0b375cu: goto P_0c0b375c;
case 0x0c0b375eu: goto P_0c0b375e;
case 0x0c0b3760u: goto P_0c0b3760;
case 0x0c0b3762u: goto P_0c0b3762;
case 0x0c0b3764u: goto P_0c0b3764;
case 0x0c0b3766u: goto P_0c0b3766;
case 0x0c0b3768u: goto P_0c0b3768;
case 0x0c0b376au: goto P_0c0b376a;
case 0x0c0b376cu: goto P_0c0b376c;
case 0x0c0b376eu: goto P_0c0b376e;
case 0x0c0b3770u: goto P_0c0b3770;
case 0x0c0b3772u: goto P_0c0b3772;
case 0x0c0b3774u: goto P_0c0b3774;
case 0x0c0b3776u: goto P_0c0b3776;
case 0x0c0b3778u: goto P_0c0b3778;
case 0x0c0b377au: goto P_0c0b377a;
case 0x0c0b377cu: goto P_0c0b377c;
case 0x0c0b377eu: goto P_0c0b377e;
case 0x0c0b3780u: goto P_0c0b3780;
case 0x0c0b3782u: goto P_0c0b3782;
case 0x0c0b3784u: goto P_0c0b3784;
case 0x0c0b3786u: goto P_0c0b3786;
case 0x0c0b3788u: goto P_0c0b3788;
case 0x0c0b378au: goto P_0c0b378a;
case 0x0c0b378cu: goto P_0c0b378c;
case 0x0c0b378eu: goto P_0c0b378e;
case 0x0c0b3790u: goto P_0c0b3790;
case 0x0c0b3792u: goto P_0c0b3792;
case 0x0c0b3794u: goto P_0c0b3794;
case 0x0c0b3796u: goto P_0c0b3796;
case 0x0c0b3798u: goto P_0c0b3798;
case 0x0c0b379au: goto P_0c0b379a;
case 0x0c0b379cu: goto P_0c0b379c;
case 0x0c0b379eu: goto P_0c0b379e;
case 0x0c0b37a0u: goto P_0c0b37a0;
case 0x0c0b37a2u: goto P_0c0b37a2;
case 0x0c0b37a4u: goto P_0c0b37a4;
case 0x0c0b37a6u: goto P_0c0b37a6;
case 0x0c0b37a8u: goto P_0c0b37a8;
case 0x0c0b37aau: goto P_0c0b37aa;
case 0x0c0b37acu: goto P_0c0b37ac;
case 0x0c0b37aeu: goto P_0c0b37ae;
case 0x0c0b37b0u: goto P_0c0b37b0;
case 0x0c0b37b2u: goto P_0c0b37b2;
case 0x0c0b37b4u: goto P_0c0b37b4;
case 0x0c0b37b6u: goto P_0c0b37b6;
case 0x0c0b37b8u: goto P_0c0b37b8;
case 0x0c0b37bau: goto P_0c0b37ba;
case 0x0c0b37bcu: goto P_0c0b37bc;
case 0x0c0b37beu: goto P_0c0b37be;
case 0x0c0b37c0u: goto P_0c0b37c0;
case 0x0c0b37c2u: goto P_0c0b37c2;
case 0x0c0b37c4u: goto P_0c0b37c4;
case 0x0c0b37c6u: goto P_0c0b37c6;
case 0x0c0b37c8u: goto P_0c0b37c8;
case 0x0c0b37cau: goto P_0c0b37ca;
case 0x0c0b37ccu: goto P_0c0b37cc;
case 0x0c0b37ceu: goto P_0c0b37ce;
case 0x0c0b37d0u: goto P_0c0b37d0;
case 0x0c0b37d2u: goto P_0c0b37d2;
case 0x0c0b37d4u: goto P_0c0b37d4;
case 0x0c0b37d6u: goto P_0c0b37d6;
case 0x0c0b37d8u: goto P_0c0b37d8;
case 0x0c0b37dau: goto P_0c0b37da;
case 0x0c0b37dcu: goto P_0c0b37dc;
case 0x0c0b37deu: goto P_0c0b37de;
case 0x0c0b37e0u: goto P_0c0b37e0;
case 0x0c0b37e2u: goto P_0c0b37e2;
case 0x0c0b37e4u: goto P_0c0b37e4;
case 0x0c0b37e6u: goto P_0c0b37e6;
case 0x0c0b37e8u: goto P_0c0b37e8;
case 0x0c0b37eau: goto P_0c0b37ea;
case 0x0c0b37ecu: goto P_0c0b37ec;
case 0x0c0b37eeu: goto P_0c0b37ee;
case 0x0c0b37f0u: goto P_0c0b37f0;
case 0x0c0b37f2u: goto P_0c0b37f2;
case 0x0c0b37f4u: goto P_0c0b37f4;
case 0x0c0b37f6u: goto P_0c0b37f6;
case 0x0c0b37f8u: goto P_0c0b37f8;
case 0x0c0b37fau: goto P_0c0b37fa;
case 0x0c0b37fcu: goto P_0c0b37fc;
case 0x0c0b37feu: goto P_0c0b37fe;
case 0x0c0b3800u: goto P_0c0b3800;
case 0x0c0b3802u: goto P_0c0b3802;
case 0x0c0b3804u: goto P_0c0b3804;
case 0x0c0b3806u: goto P_0c0b3806;
case 0x0c0b3808u: goto P_0c0b3808;
case 0x0c0b380au: goto P_0c0b380a;
case 0x0c0b380cu: goto P_0c0b380c;
case 0x0c0b380eu: goto P_0c0b380e;
case 0x0c0b3810u: goto P_0c0b3810;
case 0x0c0b3812u: goto P_0c0b3812;
case 0x0c0b3814u: goto P_0c0b3814;
case 0x0c0b3816u: goto P_0c0b3816;
case 0x0c0b3818u: goto P_0c0b3818;
case 0x0c0b381au: goto P_0c0b381a;
case 0x0c0b381cu: goto P_0c0b381c;
case 0x0c0b381eu: goto P_0c0b381e;
case 0x0c0b3888u: goto P_0c0b3888;
case 0x0c0b388au: goto P_0c0b388a;
case 0x0c0b388cu: goto P_0c0b388c;
case 0x0c0b388eu: goto P_0c0b388e;
case 0x0c0b3890u: goto P_0c0b3890;
case 0x0c0b3892u: goto P_0c0b3892;
case 0x0c0b3894u: goto P_0c0b3894;
case 0x0c0b3896u: goto P_0c0b3896;
case 0x0c0b3898u: goto P_0c0b3898;
case 0x0c0b389au: goto P_0c0b389a;
case 0x0c0b389cu: goto P_0c0b389c;
case 0x0c0b389eu: goto P_0c0b389e;
case 0x0c0b38a0u: goto P_0c0b38a0;
case 0x0c0b38a2u: goto P_0c0b38a2;
case 0x0c0b38a4u: goto P_0c0b38a4;
case 0x0c0b38a6u: goto P_0c0b38a6;
case 0x0c0b38a8u: goto P_0c0b38a8;
case 0x0c0b38aau: goto P_0c0b38aa;
case 0x0c0b38acu: goto P_0c0b38ac;
case 0x0c0b38aeu: goto P_0c0b38ae;
case 0x0c0b38b0u: goto P_0c0b38b0;
case 0x0c0b38b2u: goto P_0c0b38b2;
case 0x0c0b38b4u: goto P_0c0b38b4;
case 0x0c0b38b6u: goto P_0c0b38b6;
case 0x0c0b38b8u: goto P_0c0b38b8;
case 0x0c0b38bau: goto P_0c0b38ba;
case 0x0c0b38bcu: goto P_0c0b38bc;
case 0x0c0b38beu: goto P_0c0b38be;
case 0x0c0b38c0u: goto P_0c0b38c0;
case 0x0c0b38c2u: goto P_0c0b38c2;
case 0x0c0b38c4u: goto P_0c0b38c4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2e06: /* original d359, guest PC 0x0c0a2e06 */
if(!s->budget--) { s->failed_pc=0x0c0a2e06u; return 0; }
r[3]=read(ram,0x0c0a2f6cu,4);
goto P_0c0a2e08;
P_0c0a2e08: /* original 6643, guest PC 0x0c0a2e08 */
if(!s->budget--) { s->failed_pc=0x0c0a2e08u; return 0; }
r[6]=r[4];
goto P_0c0a2e0a;
P_0c0a2e0a: /* original 4608, guest PC 0x0c0a2e0a */
if(!s->budget--) { s->failed_pc=0x0c0a2e0au; return 0; }
r[6]<<=2;
goto P_0c0a2e0c;
P_0c0a2e0c: /* original 363c, guest PC 0x0c0a2e0c */
if(!s->budget--) { s->failed_pc=0x0c0a2e0cu; return 0; }
r[6]+=r[3];
goto P_0c0a2e0e;
P_0c0a2e0e: /* original 6262, guest PC 0x0c0a2e0e */
if(!s->budget--) { s->failed_pc=0x0c0a2e0eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a2e10;
P_0c0a2e10: /* original 2228, guest PC 0x0c0a2e10 */
if(!s->budget--) { s->failed_pc=0x0c0a2e10u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2e12;
P_0c0a2e12: /* original 8b09, guest PC 0x0c0a2e12 */
if(!s->budget--) { s->failed_pc=0x0c0a2e12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2e28; }
goto P_0c0a2e14;
P_0c0a2e14: /* original 6062, guest PC 0x0c0a2e14 */
if(!s->budget--) { s->failed_pc=0x0c0a2e14u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c0a2e16;
P_0c0a2e16: /* original 88ff, guest PC 0x0c0a2e16 */
if(!s->budget--) { s->failed_pc=0x0c0a2e16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a2e18;
P_0c0a2e18: /* original 8906, guest PC 0x0c0a2e18 */
if(!s->budget--) { s->failed_pc=0x0c0a2e18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e28; }
goto P_0c0a2e1a;
P_0c0a2e1a: /* original 5051, guest PC 0x0c0a2e1a */
if(!s->budget--) { s->failed_pc=0x0c0a2e1au; return 0; }
r[0]=read(ram,r[5]+4,4);
goto P_0c0a2e1c;
P_0c0a2e1c: /* original c801, guest PC 0x0c0a2e1c */
if(!s->budget--) { s->failed_pc=0x0c0a2e1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2e1e;
P_0c0a2e1e: /* original 8901, guest PC 0x0c0a2e1e */
if(!s->budget--) { s->failed_pc=0x0c0a2e1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e24; }
goto P_0c0a2e20;
P_0c0a2e20: /* original a002, guest PC 0x0c0a2e20 */
if(!s->budget--) { s->failed_pc=0x0c0a2e20u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e28;
P_0c0a2e22: /* original 2652, guest PC 0x0c0a2e22 */
if(!s->budget--) { s->failed_pc=0x0c0a2e22u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e24;
P_0c0a2e24: /* original 6152, guest PC 0x0c0a2e24 */
if(!s->budget--) { s->failed_pc=0x0c0a2e24u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a2e26;
P_0c0a2e26: /* original 2612, guest PC 0x0c0a2e26 */
if(!s->budget--) { s->failed_pc=0x0c0a2e26u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c0a2e28;
P_0c0a2e28: /* original 000b, guest PC 0x0c0a2e28 */
if(!s->budget--) { s->failed_pc=0x0c0a2e28u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a2e2a: /* original 0009, guest PC 0x0c0a2e2a */
if(!s->budget--) { s->failed_pc=0x0c0a2e2au; return 0; }
if(!vf3_matrix_family(0x0c0a2e2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2e2cu; return 0; } return 1;
P_0c0b36b6: /* original 2fe6, guest PC 0x0c0b36b6 */
if(!s->budget--) { s->failed_pc=0x0c0b36b6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b36b8;
P_0c0b36b8: /* original 2fd6, guest PC 0x0c0b36b8 */
if(!s->budget--) { s->failed_pc=0x0c0b36b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b36ba;
P_0c0b36ba: /* original 2fc6, guest PC 0x0c0b36ba */
if(!s->budget--) { s->failed_pc=0x0c0b36bau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b36bc;
P_0c0b36bc: /* original 2fb6, guest PC 0x0c0b36bc */
if(!s->budget--) { s->failed_pc=0x0c0b36bcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b36be;
P_0c0b36be: /* original 2fa6, guest PC 0x0c0b36be */
if(!s->budget--) { s->failed_pc=0x0c0b36beu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b36c0;
P_0c0b36c0: /* original 2f96, guest PC 0x0c0b36c0 */
if(!s->budget--) { s->failed_pc=0x0c0b36c0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b36c2;
P_0c0b36c2: /* original 4f22, guest PC 0x0c0b36c2 */
if(!s->budget--) { s->failed_pc=0x0c0b36c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b36c4;
P_0c0b36c4: /* original 5d44, guest PC 0x0c0b36c4 */
if(!s->budget--) { s->failed_pc=0x0c0b36c4u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b36c6;
P_0c0b36c6: /* original 94ab, guest PC 0x0c0b36c6 */
if(!s->budget--) { s->failed_pc=0x0c0b36c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3820u,2);
goto P_0c0b36c8;
P_0c0b36c8: /* original de6e, guest PC 0x0c0b36c8 */
if(!s->budget--) { s->failed_pc=0x0c0b36c8u; return 0; }
r[14]=read(ram,0x0c0b3884u,4);
goto P_0c0b36ca;
P_0c0b36ca: /* original 7ffc, guest PC 0x0c0b36ca */
if(!s->budget--) { s->failed_pc=0x0c0b36cau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0b36cc;
P_0c0b36cc: /* original 4e0b, guest PC 0x0c0b36cc */
if(!s->budget--) { s->failed_pc=0x0c0b36ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b36d0u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b36d0u) { target=s->pc; goto dispatch; }
goto P_0c0b36d0;
P_0c0b36ce: /* original 65d2, guest PC 0x0c0b36ce */
if(!s->budget--) { s->failed_pc=0x0c0b36ceu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b36d0;
P_0c0b36d0: /* original 94a7, guest PC 0x0c0b36d0 */
if(!s->budget--) { s->failed_pc=0x0c0b36d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3822u,2);
goto P_0c0b36d2;
P_0c0b36d2: /* original 4e0b, guest PC 0x0c0b36d2 */
if(!s->budget--) { s->failed_pc=0x0c0b36d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b36d6u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b36d6u) { target=s->pc; goto dispatch; }
goto P_0c0b36d6;
P_0c0b36d4: /* original 55d1, guest PC 0x0c0b36d4 */
if(!s->budget--) { s->failed_pc=0x0c0b36d4u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b36d6;
P_0c0b36d6: /* original 94a5, guest PC 0x0c0b36d6 */
if(!s->budget--) { s->failed_pc=0x0c0b36d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3824u,2);
goto P_0c0b36d8;
P_0c0b36d8: /* original 4e0b, guest PC 0x0c0b36d8 */
if(!s->budget--) { s->failed_pc=0x0c0b36d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b36dcu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b36dcu) { target=s->pc; goto dispatch; }
goto P_0c0b36dc;
P_0c0b36da: /* original 55d2, guest PC 0x0c0b36da */
if(!s->budget--) { s->failed_pc=0x0c0b36dau; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b36dc;
P_0c0b36dc: /* original 94a3, guest PC 0x0c0b36dc */
if(!s->budget--) { s->failed_pc=0x0c0b36dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3826u,2);
goto P_0c0b36de;
P_0c0b36de: /* original 4e0b, guest PC 0x0c0b36de */
if(!s->budget--) { s->failed_pc=0x0c0b36deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b36e2u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b36e2u) { target=s->pc; goto dispatch; }
goto P_0c0b36e2;
P_0c0b36e0: /* original 55d3, guest PC 0x0c0b36e0 */
if(!s->budget--) { s->failed_pc=0x0c0b36e0u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b36e2;
P_0c0b36e2: /* original 94a1, guest PC 0x0c0b36e2 */
if(!s->budget--) { s->failed_pc=0x0c0b36e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3828u,2);
goto P_0c0b36e4;
P_0c0b36e4: /* original 4e0b, guest PC 0x0c0b36e4 */
if(!s->budget--) { s->failed_pc=0x0c0b36e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b36e8u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b36e8u) { target=s->pc; goto dispatch; }
goto P_0c0b36e8;
P_0c0b36e6: /* original 55d5, guest PC 0x0c0b36e6 */
if(!s->budget--) { s->failed_pc=0x0c0b36e6u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b36e8;
P_0c0b36e8: /* original 949f, guest PC 0x0c0b36e8 */
if(!s->budget--) { s->failed_pc=0x0c0b36e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b382au,2);
goto P_0c0b36ea;
P_0c0b36ea: /* original 4e0b, guest PC 0x0c0b36ea */
if(!s->budget--) { s->failed_pc=0x0c0b36eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b36eeu;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b36eeu) { target=s->pc; goto dispatch; }
goto P_0c0b36ee;
P_0c0b36ec: /* original 55d4, guest PC 0x0c0b36ec */
if(!s->budget--) { s->failed_pc=0x0c0b36ecu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b36ee;
P_0c0b36ee: /* original 949d, guest PC 0x0c0b36ee */
if(!s->budget--) { s->failed_pc=0x0c0b36eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b382cu,2);
goto P_0c0b36f0;
P_0c0b36f0: /* original 69d3, guest PC 0x0c0b36f0 */
if(!s->budget--) { s->failed_pc=0x0c0b36f0u; return 0; }
r[9]=r[13];
goto P_0c0b36f2;
P_0c0b36f2: /* original 7918, guest PC 0x0c0b36f2 */
if(!s->budget--) { s->failed_pc=0x0c0b36f2u; return 0; }
r[9]+=0x00000018u;
goto P_0c0b36f4;
P_0c0b36f4: /* original 4e0b, guest PC 0x0c0b36f4 */
if(!s->budget--) { s->failed_pc=0x0c0b36f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b36f8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b36f8u) { target=s->pc; goto dispatch; }
goto P_0c0b36f8;
P_0c0b36f6: /* original 6592, guest PC 0x0c0b36f6 */
if(!s->budget--) { s->failed_pc=0x0c0b36f6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b36f8;
P_0c0b36f8: /* original 9499, guest PC 0x0c0b36f8 */
if(!s->budget--) { s->failed_pc=0x0c0b36f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b382eu,2);
goto P_0c0b36fa;
P_0c0b36fa: /* original 4e0b, guest PC 0x0c0b36fa */
if(!s->budget--) { s->failed_pc=0x0c0b36fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b36feu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b36feu) { target=s->pc; goto dispatch; }
goto P_0c0b36fe;
P_0c0b36fc: /* original 6592, guest PC 0x0c0b36fc */
if(!s->budget--) { s->failed_pc=0x0c0b36fcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b36fe;
P_0c0b36fe: /* original 9497, guest PC 0x0c0b36fe */
if(!s->budget--) { s->failed_pc=0x0c0b36feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3830u,2);
goto P_0c0b3700;
P_0c0b3700: /* original 4e0b, guest PC 0x0c0b3700 */
if(!s->budget--) { s->failed_pc=0x0c0b3700u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3704u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3704u) { target=s->pc; goto dispatch; }
goto P_0c0b3704;
P_0c0b3702: /* original 6592, guest PC 0x0c0b3702 */
if(!s->budget--) { s->failed_pc=0x0c0b3702u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3704;
P_0c0b3704: /* original 9495, guest PC 0x0c0b3704 */
if(!s->budget--) { s->failed_pc=0x0c0b3704u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3832u,2);
goto P_0c0b3706;
P_0c0b3706: /* original 4e0b, guest PC 0x0c0b3706 */
if(!s->budget--) { s->failed_pc=0x0c0b3706u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b370au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b370au) { target=s->pc; goto dispatch; }
goto P_0c0b370a;
P_0c0b3708: /* original 6592, guest PC 0x0c0b3708 */
if(!s->budget--) { s->failed_pc=0x0c0b3708u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b370a;
P_0c0b370a: /* original 9493, guest PC 0x0c0b370a */
if(!s->budget--) { s->failed_pc=0x0c0b370au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3834u,2);
goto P_0c0b370c;
P_0c0b370c: /* original 6cd3, guest PC 0x0c0b370c */
if(!s->budget--) { s->failed_pc=0x0c0b370cu; return 0; }
r[12]=r[13];
goto P_0c0b370e;
P_0c0b370e: /* original 7c1c, guest PC 0x0c0b370e */
if(!s->budget--) { s->failed_pc=0x0c0b370eu; return 0; }
r[12]+=0x0000001cu;
goto P_0c0b3710;
P_0c0b3710: /* original 4e0b, guest PC 0x0c0b3710 */
if(!s->budget--) { s->failed_pc=0x0c0b3710u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3714u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3714u) { target=s->pc; goto dispatch; }
goto P_0c0b3714;
P_0c0b3712: /* original 65c2, guest PC 0x0c0b3712 */
if(!s->budget--) { s->failed_pc=0x0c0b3712u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3714;
P_0c0b3714: /* original 948f, guest PC 0x0c0b3714 */
if(!s->budget--) { s->failed_pc=0x0c0b3714u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3836u,2);
goto P_0c0b3716;
P_0c0b3716: /* original 4e0b, guest PC 0x0c0b3716 */
if(!s->budget--) { s->failed_pc=0x0c0b3716u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b371au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b371au) { target=s->pc; goto dispatch; }
goto P_0c0b371a;
P_0c0b3718: /* original 65c2, guest PC 0x0c0b3718 */
if(!s->budget--) { s->failed_pc=0x0c0b3718u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b371a;
P_0c0b371a: /* original 948d, guest PC 0x0c0b371a */
if(!s->budget--) { s->failed_pc=0x0c0b371au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3838u,2);
goto P_0c0b371c;
P_0c0b371c: /* original 4e0b, guest PC 0x0c0b371c */
if(!s->budget--) { s->failed_pc=0x0c0b371cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3720u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3720u) { target=s->pc; goto dispatch; }
goto P_0c0b3720;
P_0c0b371e: /* original 65c2, guest PC 0x0c0b371e */
if(!s->budget--) { s->failed_pc=0x0c0b371eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3720;
P_0c0b3720: /* original 948b, guest PC 0x0c0b3720 */
if(!s->budget--) { s->failed_pc=0x0c0b3720u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b383au,2);
goto P_0c0b3722;
P_0c0b3722: /* original 4e0b, guest PC 0x0c0b3722 */
if(!s->budget--) { s->failed_pc=0x0c0b3722u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3726u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3726u) { target=s->pc; goto dispatch; }
goto P_0c0b3726;
P_0c0b3724: /* original 65c2, guest PC 0x0c0b3724 */
if(!s->budget--) { s->failed_pc=0x0c0b3724u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3726;
P_0c0b3726: /* original 9489, guest PC 0x0c0b3726 */
if(!s->budget--) { s->failed_pc=0x0c0b3726u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b383cu,2);
goto P_0c0b3728;
P_0c0b3728: /* original 6bd3, guest PC 0x0c0b3728 */
if(!s->budget--) { s->failed_pc=0x0c0b3728u; return 0; }
r[11]=r[13];
goto P_0c0b372a;
P_0c0b372a: /* original 7b20, guest PC 0x0c0b372a */
if(!s->budget--) { s->failed_pc=0x0c0b372au; return 0; }
r[11]+=0x00000020u;
goto P_0c0b372c;
P_0c0b372c: /* original 4e0b, guest PC 0x0c0b372c */
if(!s->budget--) { s->failed_pc=0x0c0b372cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3730u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3730u) { target=s->pc; goto dispatch; }
goto P_0c0b3730;
P_0c0b372e: /* original 65b2, guest PC 0x0c0b372e */
if(!s->budget--) { s->failed_pc=0x0c0b372eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3730;
P_0c0b3730: /* original 9485, guest PC 0x0c0b3730 */
if(!s->budget--) { s->failed_pc=0x0c0b3730u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b383eu,2);
goto P_0c0b3732;
P_0c0b3732: /* original 4e0b, guest PC 0x0c0b3732 */
if(!s->budget--) { s->failed_pc=0x0c0b3732u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3736u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3736u) { target=s->pc; goto dispatch; }
goto P_0c0b3736;
P_0c0b3734: /* original 65b2, guest PC 0x0c0b3734 */
if(!s->budget--) { s->failed_pc=0x0c0b3734u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3736;
P_0c0b3736: /* original 9483, guest PC 0x0c0b3736 */
if(!s->budget--) { s->failed_pc=0x0c0b3736u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3840u,2);
goto P_0c0b3738;
P_0c0b3738: /* original 4e0b, guest PC 0x0c0b3738 */
if(!s->budget--) { s->failed_pc=0x0c0b3738u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b373cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b373cu) { target=s->pc; goto dispatch; }
goto P_0c0b373c;
P_0c0b373a: /* original 65b2, guest PC 0x0c0b373a */
if(!s->budget--) { s->failed_pc=0x0c0b373au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b373c;
P_0c0b373c: /* original 9481, guest PC 0x0c0b373c */
if(!s->budget--) { s->failed_pc=0x0c0b373cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3842u,2);
goto P_0c0b373e;
P_0c0b373e: /* original 4e0b, guest PC 0x0c0b373e */
if(!s->budget--) { s->failed_pc=0x0c0b373eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3742u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3742u) { target=s->pc; goto dispatch; }
goto P_0c0b3742;
P_0c0b3740: /* original 65b2, guest PC 0x0c0b3740 */
if(!s->budget--) { s->failed_pc=0x0c0b3740u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3742;
P_0c0b3742: /* original 947f, guest PC 0x0c0b3742 */
if(!s->budget--) { s->failed_pc=0x0c0b3742u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3844u,2);
goto P_0c0b3744;
P_0c0b3744: /* original 6ad3, guest PC 0x0c0b3744 */
if(!s->budget--) { s->failed_pc=0x0c0b3744u; return 0; }
r[10]=r[13];
goto P_0c0b3746;
P_0c0b3746: /* original 7a24, guest PC 0x0c0b3746 */
if(!s->budget--) { s->failed_pc=0x0c0b3746u; return 0; }
r[10]+=0x00000024u;
goto P_0c0b3748;
P_0c0b3748: /* original 4e0b, guest PC 0x0c0b3748 */
if(!s->budget--) { s->failed_pc=0x0c0b3748u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b374cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b374cu) { target=s->pc; goto dispatch; }
goto P_0c0b374c;
P_0c0b374a: /* original 65a2, guest PC 0x0c0b374a */
if(!s->budget--) { s->failed_pc=0x0c0b374au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b374c;
P_0c0b374c: /* original 947b, guest PC 0x0c0b374c */
if(!s->budget--) { s->failed_pc=0x0c0b374cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3846u,2);
goto P_0c0b374e;
P_0c0b374e: /* original 4e0b, guest PC 0x0c0b374e */
if(!s->budget--) { s->failed_pc=0x0c0b374eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3752u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3752u) { target=s->pc; goto dispatch; }
goto P_0c0b3752;
P_0c0b3750: /* original 65a2, guest PC 0x0c0b3750 */
if(!s->budget--) { s->failed_pc=0x0c0b3750u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3752;
P_0c0b3752: /* original 9479, guest PC 0x0c0b3752 */
if(!s->budget--) { s->failed_pc=0x0c0b3752u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3848u,2);
goto P_0c0b3754;
P_0c0b3754: /* original 4e0b, guest PC 0x0c0b3754 */
if(!s->budget--) { s->failed_pc=0x0c0b3754u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3758u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3758u) { target=s->pc; goto dispatch; }
goto P_0c0b3758;
P_0c0b3756: /* original 65a2, guest PC 0x0c0b3756 */
if(!s->budget--) { s->failed_pc=0x0c0b3756u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3758;
P_0c0b3758: /* original 9477, guest PC 0x0c0b3758 */
if(!s->budget--) { s->failed_pc=0x0c0b3758u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b384au,2);
goto P_0c0b375a;
P_0c0b375a: /* original 4e0b, guest PC 0x0c0b375a */
if(!s->budget--) { s->failed_pc=0x0c0b375au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b375eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b375eu) { target=s->pc; goto dispatch; }
goto P_0c0b375e;
P_0c0b375c: /* original 65a2, guest PC 0x0c0b375c */
if(!s->budget--) { s->failed_pc=0x0c0b375cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b375e;
P_0c0b375e: /* original 9475, guest PC 0x0c0b375e */
if(!s->budget--) { s->failed_pc=0x0c0b375eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b384cu,2);
goto P_0c0b3760;
P_0c0b3760: /* original 4e0b, guest PC 0x0c0b3760 */
if(!s->budget--) { s->failed_pc=0x0c0b3760u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3764u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3764u) { target=s->pc; goto dispatch; }
goto P_0c0b3764;
P_0c0b3762: /* original 6592, guest PC 0x0c0b3762 */
if(!s->budget--) { s->failed_pc=0x0c0b3762u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3764;
P_0c0b3764: /* original 9473, guest PC 0x0c0b3764 */
if(!s->budget--) { s->failed_pc=0x0c0b3764u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b384eu,2);
goto P_0c0b3766;
P_0c0b3766: /* original 4e0b, guest PC 0x0c0b3766 */
if(!s->budget--) { s->failed_pc=0x0c0b3766u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b376au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b376au) { target=s->pc; goto dispatch; }
goto P_0c0b376a;
P_0c0b3768: /* original 6592, guest PC 0x0c0b3768 */
if(!s->budget--) { s->failed_pc=0x0c0b3768u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b376a;
P_0c0b376a: /* original 9471, guest PC 0x0c0b376a */
if(!s->budget--) { s->failed_pc=0x0c0b376au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3850u,2);
goto P_0c0b376c;
P_0c0b376c: /* original 4e0b, guest PC 0x0c0b376c */
if(!s->budget--) { s->failed_pc=0x0c0b376cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3770u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3770u) { target=s->pc; goto dispatch; }
goto P_0c0b3770;
P_0c0b376e: /* original 6592, guest PC 0x0c0b376e */
if(!s->budget--) { s->failed_pc=0x0c0b376eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3770;
P_0c0b3770: /* original 946f, guest PC 0x0c0b3770 */
if(!s->budget--) { s->failed_pc=0x0c0b3770u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3852u,2);
goto P_0c0b3772;
P_0c0b3772: /* original 4e0b, guest PC 0x0c0b3772 */
if(!s->budget--) { s->failed_pc=0x0c0b3772u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3776u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3776u) { target=s->pc; goto dispatch; }
goto P_0c0b3776;
P_0c0b3774: /* original 6592, guest PC 0x0c0b3774 */
if(!s->budget--) { s->failed_pc=0x0c0b3774u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3776;
P_0c0b3776: /* original 946d, guest PC 0x0c0b3776 */
if(!s->budget--) { s->failed_pc=0x0c0b3776u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3854u,2);
goto P_0c0b3778;
P_0c0b3778: /* original 4e0b, guest PC 0x0c0b3778 */
if(!s->budget--) { s->failed_pc=0x0c0b3778u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b377cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b377cu) { target=s->pc; goto dispatch; }
goto P_0c0b377c;
P_0c0b377a: /* original 65c2, guest PC 0x0c0b377a */
if(!s->budget--) { s->failed_pc=0x0c0b377au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b377c;
P_0c0b377c: /* original 946b, guest PC 0x0c0b377c */
if(!s->budget--) { s->failed_pc=0x0c0b377cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3856u,2);
goto P_0c0b377e;
P_0c0b377e: /* original 4e0b, guest PC 0x0c0b377e */
if(!s->budget--) { s->failed_pc=0x0c0b377eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3782u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3782u) { target=s->pc; goto dispatch; }
goto P_0c0b3782;
P_0c0b3780: /* original 65c2, guest PC 0x0c0b3780 */
if(!s->budget--) { s->failed_pc=0x0c0b3780u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3782;
P_0c0b3782: /* original 9469, guest PC 0x0c0b3782 */
if(!s->budget--) { s->failed_pc=0x0c0b3782u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3858u,2);
goto P_0c0b3784;
P_0c0b3784: /* original 4e0b, guest PC 0x0c0b3784 */
if(!s->budget--) { s->failed_pc=0x0c0b3784u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3788u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3788u) { target=s->pc; goto dispatch; }
goto P_0c0b3788;
P_0c0b3786: /* original 65c2, guest PC 0x0c0b3786 */
if(!s->budget--) { s->failed_pc=0x0c0b3786u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3788;
P_0c0b3788: /* original 9467, guest PC 0x0c0b3788 */
if(!s->budget--) { s->failed_pc=0x0c0b3788u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b385au,2);
goto P_0c0b378a;
P_0c0b378a: /* original 4e0b, guest PC 0x0c0b378a */
if(!s->budget--) { s->failed_pc=0x0c0b378au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b378eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b378eu) { target=s->pc; goto dispatch; }
goto P_0c0b378e;
P_0c0b378c: /* original 65c2, guest PC 0x0c0b378c */
if(!s->budget--) { s->failed_pc=0x0c0b378cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b378e;
P_0c0b378e: /* original 9465, guest PC 0x0c0b378e */
if(!s->budget--) { s->failed_pc=0x0c0b378eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b385cu,2);
goto P_0c0b3790;
P_0c0b3790: /* original 4e0b, guest PC 0x0c0b3790 */
if(!s->budget--) { s->failed_pc=0x0c0b3790u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3794u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3794u) { target=s->pc; goto dispatch; }
goto P_0c0b3794;
P_0c0b3792: /* original 65b2, guest PC 0x0c0b3792 */
if(!s->budget--) { s->failed_pc=0x0c0b3792u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3794;
P_0c0b3794: /* original 9463, guest PC 0x0c0b3794 */
if(!s->budget--) { s->failed_pc=0x0c0b3794u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b385eu,2);
goto P_0c0b3796;
P_0c0b3796: /* original 4e0b, guest PC 0x0c0b3796 */
if(!s->budget--) { s->failed_pc=0x0c0b3796u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b379au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b379au) { target=s->pc; goto dispatch; }
goto P_0c0b379a;
P_0c0b3798: /* original 65b2, guest PC 0x0c0b3798 */
if(!s->budget--) { s->failed_pc=0x0c0b3798u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b379a;
P_0c0b379a: /* original 9461, guest PC 0x0c0b379a */
if(!s->budget--) { s->failed_pc=0x0c0b379au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3860u,2);
goto P_0c0b379c;
P_0c0b379c: /* original 4e0b, guest PC 0x0c0b379c */
if(!s->budget--) { s->failed_pc=0x0c0b379cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37a0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37a0u) { target=s->pc; goto dispatch; }
goto P_0c0b37a0;
P_0c0b379e: /* original 65b2, guest PC 0x0c0b379e */
if(!s->budget--) { s->failed_pc=0x0c0b379eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b37a0;
P_0c0b37a0: /* original 945f, guest PC 0x0c0b37a0 */
if(!s->budget--) { s->failed_pc=0x0c0b37a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3862u,2);
goto P_0c0b37a2;
P_0c0b37a2: /* original 4e0b, guest PC 0x0c0b37a2 */
if(!s->budget--) { s->failed_pc=0x0c0b37a2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37a6u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37a6u) { target=s->pc; goto dispatch; }
goto P_0c0b37a6;
P_0c0b37a4: /* original 65b2, guest PC 0x0c0b37a4 */
if(!s->budget--) { s->failed_pc=0x0c0b37a4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b37a6;
P_0c0b37a6: /* original 945d, guest PC 0x0c0b37a6 */
if(!s->budget--) { s->failed_pc=0x0c0b37a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3864u,2);
goto P_0c0b37a8;
P_0c0b37a8: /* original 4e0b, guest PC 0x0c0b37a8 */
if(!s->budget--) { s->failed_pc=0x0c0b37a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37acu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37acu) { target=s->pc; goto dispatch; }
goto P_0c0b37ac;
P_0c0b37aa: /* original 65a2, guest PC 0x0c0b37aa */
if(!s->budget--) { s->failed_pc=0x0c0b37aau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b37ac;
P_0c0b37ac: /* original 945b, guest PC 0x0c0b37ac */
if(!s->budget--) { s->failed_pc=0x0c0b37acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3866u,2);
goto P_0c0b37ae;
P_0c0b37ae: /* original 4e0b, guest PC 0x0c0b37ae */
if(!s->budget--) { s->failed_pc=0x0c0b37aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37b2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37b2u) { target=s->pc; goto dispatch; }
goto P_0c0b37b2;
P_0c0b37b0: /* original 65a2, guest PC 0x0c0b37b0 */
if(!s->budget--) { s->failed_pc=0x0c0b37b0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b37b2;
P_0c0b37b2: /* original 9459, guest PC 0x0c0b37b2 */
if(!s->budget--) { s->failed_pc=0x0c0b37b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3868u,2);
goto P_0c0b37b4;
P_0c0b37b4: /* original 4e0b, guest PC 0x0c0b37b4 */
if(!s->budget--) { s->failed_pc=0x0c0b37b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37b8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37b8u) { target=s->pc; goto dispatch; }
goto P_0c0b37b8;
P_0c0b37b6: /* original 65a2, guest PC 0x0c0b37b6 */
if(!s->budget--) { s->failed_pc=0x0c0b37b6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b37b8;
P_0c0b37b8: /* original 9457, guest PC 0x0c0b37b8 */
if(!s->budget--) { s->failed_pc=0x0c0b37b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b386au,2);
goto P_0c0b37ba;
P_0c0b37ba: /* original 4e0b, guest PC 0x0c0b37ba */
if(!s->budget--) { s->failed_pc=0x0c0b37bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37beu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37beu) { target=s->pc; goto dispatch; }
goto P_0c0b37be;
P_0c0b37bc: /* original 65a2, guest PC 0x0c0b37bc */
if(!s->budget--) { s->failed_pc=0x0c0b37bcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b37be;
P_0c0b37be: /* original 65d3, guest PC 0x0c0b37be */
if(!s->budget--) { s->failed_pc=0x0c0b37beu; return 0; }
r[5]=r[13];
goto P_0c0b37c0;
P_0c0b37c0: /* original 7548, guest PC 0x0c0b37c0 */
if(!s->budget--) { s->failed_pc=0x0c0b37c0u; return 0; }
r[5]+=0x00000048u;
goto P_0c0b37c2;
P_0c0b37c2: /* original 2f52, guest PC 0x0c0b37c2 */
if(!s->budget--) { s->failed_pc=0x0c0b37c2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b37c4;
P_0c0b37c4: /* original 9452, guest PC 0x0c0b37c4 */
if(!s->budget--) { s->failed_pc=0x0c0b37c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b386cu,2);
goto P_0c0b37c6;
P_0c0b37c6: /* original 4e0b, guest PC 0x0c0b37c6 */
if(!s->budget--) { s->failed_pc=0x0c0b37c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37cau;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37cau) { target=s->pc; goto dispatch; }
goto P_0c0b37ca;
P_0c0b37c8: /* original 6552, guest PC 0x0c0b37c8 */
if(!s->budget--) { s->failed_pc=0x0c0b37c8u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b37ca;
P_0c0b37ca: /* original 9450, guest PC 0x0c0b37ca */
if(!s->budget--) { s->failed_pc=0x0c0b37cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b386eu,2);
goto P_0c0b37cc;
P_0c0b37cc: /* original 65f2, guest PC 0x0c0b37cc */
if(!s->budget--) { s->failed_pc=0x0c0b37ccu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b37ce;
P_0c0b37ce: /* original 4e0b, guest PC 0x0c0b37ce */
if(!s->budget--) { s->failed_pc=0x0c0b37ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37d2u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37d2u) { target=s->pc; goto dispatch; }
goto P_0c0b37d2;
P_0c0b37d0: /* original 6552, guest PC 0x0c0b37d0 */
if(!s->budget--) { s->failed_pc=0x0c0b37d0u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b37d2;
P_0c0b37d2: /* original 65d3, guest PC 0x0c0b37d2 */
if(!s->budget--) { s->failed_pc=0x0c0b37d2u; return 0; }
r[5]=r[13];
goto P_0c0b37d4;
P_0c0b37d4: /* original 7544, guest PC 0x0c0b37d4 */
if(!s->budget--) { s->failed_pc=0x0c0b37d4u; return 0; }
r[5]+=0x00000044u;
goto P_0c0b37d6;
P_0c0b37d6: /* original 2f52, guest PC 0x0c0b37d6 */
if(!s->budget--) { s->failed_pc=0x0c0b37d6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b37d8;
P_0c0b37d8: /* original 944a, guest PC 0x0c0b37d8 */
if(!s->budget--) { s->failed_pc=0x0c0b37d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3870u,2);
goto P_0c0b37da;
P_0c0b37da: /* original 4e0b, guest PC 0x0c0b37da */
if(!s->budget--) { s->failed_pc=0x0c0b37dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37deu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37deu) { target=s->pc; goto dispatch; }
goto P_0c0b37de;
P_0c0b37dc: /* original 6552, guest PC 0x0c0b37dc */
if(!s->budget--) { s->failed_pc=0x0c0b37dcu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b37de;
P_0c0b37de: /* original 9448, guest PC 0x0c0b37de */
if(!s->budget--) { s->failed_pc=0x0c0b37deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3872u,2);
goto P_0c0b37e0;
P_0c0b37e0: /* original 65f2, guest PC 0x0c0b37e0 */
if(!s->budget--) { s->failed_pc=0x0c0b37e0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b37e2;
P_0c0b37e2: /* original 4e0b, guest PC 0x0c0b37e2 */
if(!s->budget--) { s->failed_pc=0x0c0b37e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37e6u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37e6u) { target=s->pc; goto dispatch; }
goto P_0c0b37e6;
P_0c0b37e4: /* original 6552, guest PC 0x0c0b37e4 */
if(!s->budget--) { s->failed_pc=0x0c0b37e4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b37e6;
P_0c0b37e6: /* original 9445, guest PC 0x0c0b37e6 */
if(!s->budget--) { s->failed_pc=0x0c0b37e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3874u,2);
goto P_0c0b37e8;
P_0c0b37e8: /* original 4e0b, guest PC 0x0c0b37e8 */
if(!s->budget--) { s->failed_pc=0x0c0b37e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37ecu;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37ecu) { target=s->pc; goto dispatch; }
goto P_0c0b37ec;
P_0c0b37ea: /* original 55db, guest PC 0x0c0b37ea */
if(!s->budget--) { s->failed_pc=0x0c0b37eau; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b37ec;
P_0c0b37ec: /* original 65d3, guest PC 0x0c0b37ec */
if(!s->budget--) { s->failed_pc=0x0c0b37ecu; return 0; }
r[5]=r[13];
goto P_0c0b37ee;
P_0c0b37ee: /* original 7530, guest PC 0x0c0b37ee */
if(!s->budget--) { s->failed_pc=0x0c0b37eeu; return 0; }
r[5]+=0x00000030u;
goto P_0c0b37f0;
P_0c0b37f0: /* original 2f52, guest PC 0x0c0b37f0 */
if(!s->budget--) { s->failed_pc=0x0c0b37f0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b37f2;
P_0c0b37f2: /* original 9440, guest PC 0x0c0b37f2 */
if(!s->budget--) { s->failed_pc=0x0c0b37f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3876u,2);
goto P_0c0b37f4;
P_0c0b37f4: /* original 4e0b, guest PC 0x0c0b37f4 */
if(!s->budget--) { s->failed_pc=0x0c0b37f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b37f8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b37f8u) { target=s->pc; goto dispatch; }
goto P_0c0b37f8;
P_0c0b37f6: /* original 6552, guest PC 0x0c0b37f6 */
if(!s->budget--) { s->failed_pc=0x0c0b37f6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b37f8;
P_0c0b37f8: /* original 943e, guest PC 0x0c0b37f8 */
if(!s->budget--) { s->failed_pc=0x0c0b37f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3878u,2);
goto P_0c0b37fa;
P_0c0b37fa: /* original 65f2, guest PC 0x0c0b37fa */
if(!s->budget--) { s->failed_pc=0x0c0b37fau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b37fc;
P_0c0b37fc: /* original 4e0b, guest PC 0x0c0b37fc */
if(!s->budget--) { s->failed_pc=0x0c0b37fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3800u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3800u) { target=s->pc; goto dispatch; }
goto P_0c0b3800;
P_0c0b37fe: /* original 6552, guest PC 0x0c0b37fe */
if(!s->budget--) { s->failed_pc=0x0c0b37feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3800;
P_0c0b3800: /* original 943b, guest PC 0x0c0b3800 */
if(!s->budget--) { s->failed_pc=0x0c0b3800u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b387au,2);
goto P_0c0b3802;
P_0c0b3802: /* original 4e0b, guest PC 0x0c0b3802 */
if(!s->budget--) { s->failed_pc=0x0c0b3802u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3806u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3806u) { target=s->pc; goto dispatch; }
goto P_0c0b3806;
P_0c0b3804: /* original 55df, guest PC 0x0c0b3804 */
if(!s->budget--) { s->failed_pc=0x0c0b3804u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b3806;
P_0c0b3806: /* original 65d3, guest PC 0x0c0b3806 */
if(!s->budget--) { s->failed_pc=0x0c0b3806u; return 0; }
r[5]=r[13];
goto P_0c0b3808;
P_0c0b3808: /* original 7540, guest PC 0x0c0b3808 */
if(!s->budget--) { s->failed_pc=0x0c0b3808u; return 0; }
r[5]+=0x00000040u;
goto P_0c0b380a;
P_0c0b380a: /* original 2f52, guest PC 0x0c0b380a */
if(!s->budget--) { s->failed_pc=0x0c0b380au; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b380c;
P_0c0b380c: /* original 9436, guest PC 0x0c0b380c */
if(!s->budget--) { s->failed_pc=0x0c0b380cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b387cu,2);
goto P_0c0b380e;
P_0c0b380e: /* original 4e0b, guest PC 0x0c0b380e */
if(!s->budget--) { s->failed_pc=0x0c0b380eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3812u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3812u) { target=s->pc; goto dispatch; }
goto P_0c0b3812;
P_0c0b3810: /* original 6552, guest PC 0x0c0b3810 */
if(!s->budget--) { s->failed_pc=0x0c0b3810u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3812;
P_0c0b3812: /* original 9434, guest PC 0x0c0b3812 */
if(!s->budget--) { s->failed_pc=0x0c0b3812u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b387eu,2);
goto P_0c0b3814;
P_0c0b3814: /* original 65f2, guest PC 0x0c0b3814 */
if(!s->budget--) { s->failed_pc=0x0c0b3814u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3816;
P_0c0b3816: /* original 4e0b, guest PC 0x0c0b3816 */
if(!s->budget--) { s->failed_pc=0x0c0b3816u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b381au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b381au) { target=s->pc; goto dispatch; }
goto P_0c0b381a;
P_0c0b3818: /* original 6552, guest PC 0x0c0b3818 */
if(!s->budget--) { s->failed_pc=0x0c0b3818u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b381a;
P_0c0b381a: /* original 9431, guest PC 0x0c0b381a */
if(!s->budget--) { s->failed_pc=0x0c0b381au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3880u,2);
goto P_0c0b381c;
P_0c0b381c: /* original a034, guest PC 0x0c0b381c */
if(!s->budget--) { s->failed_pc=0x0c0b381cu; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b3888;
P_0c0b381e: /* original 55da, guest PC 0x0c0b381e */
if(!s->budget--) { s->failed_pc=0x0c0b381eu; return 0; }
r[5]=read(ram,r[13]+40,4);
if(!vf3_matrix_family(0x0c0b3820u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b3820u; return 0; } return 1;
P_0c0b3888: /* original 4e0b, guest PC 0x0c0b3888 */
if(!s->budget--) { s->failed_pc=0x0c0b3888u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b388cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b388cu) { target=s->pc; goto dispatch; }
goto P_0c0b388c;
P_0c0b388a: /* original 0009, guest PC 0x0c0b388a */
if(!s->budget--) { s->failed_pc=0x0c0b388au; return 0; }
goto P_0c0b388c;
P_0c0b388c: /* original 65d3, guest PC 0x0c0b388c */
if(!s->budget--) { s->failed_pc=0x0c0b388cu; return 0; }
r[5]=r[13];
goto P_0c0b388e;
P_0c0b388e: /* original 7538, guest PC 0x0c0b388e */
if(!s->budget--) { s->failed_pc=0x0c0b388eu; return 0; }
r[5]+=0x00000038u;
goto P_0c0b3890;
P_0c0b3890: /* original 2f52, guest PC 0x0c0b3890 */
if(!s->budget--) { s->failed_pc=0x0c0b3890u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3892;
P_0c0b3892: /* original 9418, guest PC 0x0c0b3892 */
if(!s->budget--) { s->failed_pc=0x0c0b3892u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b38c6u,2);
goto P_0c0b3894;
P_0c0b3894: /* original 4e0b, guest PC 0x0c0b3894 */
if(!s->budget--) { s->failed_pc=0x0c0b3894u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3898u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3898u) { target=s->pc; goto dispatch; }
goto P_0c0b3898;
P_0c0b3896: /* original 6552, guest PC 0x0c0b3896 */
if(!s->budget--) { s->failed_pc=0x0c0b3896u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3898;
P_0c0b3898: /* original 9416, guest PC 0x0c0b3898 */
if(!s->budget--) { s->failed_pc=0x0c0b3898u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b38c8u,2);
goto P_0c0b389a;
P_0c0b389a: /* original 65f2, guest PC 0x0c0b389a */
if(!s->budget--) { s->failed_pc=0x0c0b389au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b389c;
P_0c0b389c: /* original 4e0b, guest PC 0x0c0b389c */
if(!s->budget--) { s->failed_pc=0x0c0b389cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b38a0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b38a0u) { target=s->pc; goto dispatch; }
goto P_0c0b38a0;
P_0c0b389e: /* original 6552, guest PC 0x0c0b389e */
if(!s->budget--) { s->failed_pc=0x0c0b389eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b38a0;
P_0c0b38a0: /* original 65d3, guest PC 0x0c0b38a0 */
if(!s->budget--) { s->failed_pc=0x0c0b38a0u; return 0; }
r[5]=r[13];
goto P_0c0b38a2;
P_0c0b38a2: /* original 7534, guest PC 0x0c0b38a2 */
if(!s->budget--) { s->failed_pc=0x0c0b38a2u; return 0; }
r[5]+=0x00000034u;
goto P_0c0b38a4;
P_0c0b38a4: /* original 2f52, guest PC 0x0c0b38a4 */
if(!s->budget--) { s->failed_pc=0x0c0b38a4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b38a6;
P_0c0b38a6: /* original 9410, guest PC 0x0c0b38a6 */
if(!s->budget--) { s->failed_pc=0x0c0b38a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b38cau,2);
goto P_0c0b38a8;
P_0c0b38a8: /* original 4e0b, guest PC 0x0c0b38a8 */
if(!s->budget--) { s->failed_pc=0x0c0b38a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b38acu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b38acu) { target=s->pc; goto dispatch; }
goto P_0c0b38ac;
P_0c0b38aa: /* original 6552, guest PC 0x0c0b38aa */
if(!s->budget--) { s->failed_pc=0x0c0b38aau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b38ac;
P_0c0b38ac: /* original 940e, guest PC 0x0c0b38ac */
if(!s->budget--) { s->failed_pc=0x0c0b38acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b38ccu,2);
goto P_0c0b38ae;
P_0c0b38ae: /* original 65f2, guest PC 0x0c0b38ae */
if(!s->budget--) { s->failed_pc=0x0c0b38aeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b38b0;
P_0c0b38b0: /* original 4e0b, guest PC 0x0c0b38b0 */
if(!s->budget--) { s->failed_pc=0x0c0b38b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b38b4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b38b4u) { target=s->pc; goto dispatch; }
goto P_0c0b38b4;
P_0c0b38b2: /* original 6552, guest PC 0x0c0b38b2 */
if(!s->budget--) { s->failed_pc=0x0c0b38b2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b38b4;
P_0c0b38b4: /* original 7f04, guest PC 0x0c0b38b4 */
if(!s->budget--) { s->failed_pc=0x0c0b38b4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0b38b6;
P_0c0b38b6: /* original 4f26, guest PC 0x0c0b38b6 */
if(!s->budget--) { s->failed_pc=0x0c0b38b6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b38b8;
P_0c0b38b8: /* original 69f6, guest PC 0x0c0b38b8 */
if(!s->budget--) { s->failed_pc=0x0c0b38b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b38ba;
P_0c0b38ba: /* original 6af6, guest PC 0x0c0b38ba */
if(!s->budget--) { s->failed_pc=0x0c0b38bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b38bc;
P_0c0b38bc: /* original 6bf6, guest PC 0x0c0b38bc */
if(!s->budget--) { s->failed_pc=0x0c0b38bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b38be;
P_0c0b38be: /* original 6cf6, guest PC 0x0c0b38be */
if(!s->budget--) { s->failed_pc=0x0c0b38beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b38c0;
P_0c0b38c0: /* original 6df6, guest PC 0x0c0b38c0 */
if(!s->budget--) { s->failed_pc=0x0c0b38c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b38c2;
P_0c0b38c2: /* original 000b, guest PC 0x0c0b38c2 */
if(!s->budget--) { s->failed_pc=0x0c0b38c2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b38c4: /* original 6ef6, guest PC 0x0c0b38c4 */
if(!s->budget--) { s->failed_pc=0x0c0b38c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b38c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b38c6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
