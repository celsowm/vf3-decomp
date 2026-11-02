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
int vf3_away_batch21_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ae29cu: goto P_0c0ae29c;
case 0x0c0ae29eu: goto P_0c0ae29e;
case 0x0c0ae2a0u: goto P_0c0ae2a0;
case 0x0c0ae2a2u: goto P_0c0ae2a2;
case 0x0c0ae2a4u: goto P_0c0ae2a4;
case 0x0c0ae2a6u: goto P_0c0ae2a6;
case 0x0c0ae2a8u: goto P_0c0ae2a8;
case 0x0c0ae2aau: goto P_0c0ae2aa;
case 0x0c0ae2acu: goto P_0c0ae2ac;
case 0x0c0ae2aeu: goto P_0c0ae2ae;
case 0x0c0ae2b0u: goto P_0c0ae2b0;
case 0x0c0ae2b2u: goto P_0c0ae2b2;
case 0x0c0ae2b4u: goto P_0c0ae2b4;
case 0x0c0ae2b6u: goto P_0c0ae2b6;
case 0x0c0ae2b8u: goto P_0c0ae2b8;
case 0x0c0ae2bau: goto P_0c0ae2ba;
case 0x0c0ae2bcu: goto P_0c0ae2bc;
case 0x0c0ae2beu: goto P_0c0ae2be;
case 0x0c0ae2c0u: goto P_0c0ae2c0;
case 0x0c0ae2c2u: goto P_0c0ae2c2;
case 0x0c0ae2c4u: goto P_0c0ae2c4;
case 0x0c0ae2c6u: goto P_0c0ae2c6;
case 0x0c0ae2c8u: goto P_0c0ae2c8;
case 0x0c0ae2cau: goto P_0c0ae2ca;
case 0x0c0ae2ccu: goto P_0c0ae2cc;
case 0x0c0ae2ceu: goto P_0c0ae2ce;
case 0x0c0ae2d0u: goto P_0c0ae2d0;
case 0x0c0ae2d2u: goto P_0c0ae2d2;
case 0x0c0ae2d4u: goto P_0c0ae2d4;
case 0x0c0ae2d6u: goto P_0c0ae2d6;
case 0x0c0ae2d8u: goto P_0c0ae2d8;
case 0x0c0ae2dau: goto P_0c0ae2da;
case 0x0c0af728u: goto P_0c0af728;
case 0x0c0af72au: goto P_0c0af72a;
case 0x0c0af72cu: goto P_0c0af72c;
case 0x0c0af72eu: goto P_0c0af72e;
case 0x0c0af730u: goto P_0c0af730;
case 0x0c0af732u: goto P_0c0af732;
case 0x0c0af734u: goto P_0c0af734;
case 0x0c0af736u: goto P_0c0af736;
case 0x0c0af738u: goto P_0c0af738;
case 0x0c0af73au: goto P_0c0af73a;
case 0x0c0af73cu: goto P_0c0af73c;
case 0x0c0af73eu: goto P_0c0af73e;
case 0x0c0af740u: goto P_0c0af740;
case 0x0c0af742u: goto P_0c0af742;
case 0x0c0af744u: goto P_0c0af744;
case 0x0c0af746u: goto P_0c0af746;
case 0x0c0af748u: goto P_0c0af748;
case 0x0c0af74au: goto P_0c0af74a;
case 0x0c0af74cu: goto P_0c0af74c;
case 0x0c0af74eu: goto P_0c0af74e;
case 0x0c0af750u: goto P_0c0af750;
case 0x0c0af752u: goto P_0c0af752;
case 0x0c0af754u: goto P_0c0af754;
case 0x0c0af756u: goto P_0c0af756;
case 0x0c0af758u: goto P_0c0af758;
case 0x0c0af75au: goto P_0c0af75a;
case 0x0c0af75cu: goto P_0c0af75c;
case 0x0c0af75eu: goto P_0c0af75e;
case 0x0c0af760u: goto P_0c0af760;
case 0x0c0af762u: goto P_0c0af762;
case 0x0c0af764u: goto P_0c0af764;
case 0x0c0af766u: goto P_0c0af766;
case 0x0c0af768u: goto P_0c0af768;
case 0x0c0af76au: goto P_0c0af76a;
case 0x0c0af76cu: goto P_0c0af76c;
case 0x0c0af76eu: goto P_0c0af76e;
case 0x0c0af770u: goto P_0c0af770;
case 0x0c0af772u: goto P_0c0af772;
case 0x0c0af774u: goto P_0c0af774;
case 0x0c0af776u: goto P_0c0af776;
case 0x0c0af778u: goto P_0c0af778;
case 0x0c0af77au: goto P_0c0af77a;
case 0x0c0af77cu: goto P_0c0af77c;
case 0x0c0af77eu: goto P_0c0af77e;
case 0x0c0af780u: goto P_0c0af780;
case 0x0c0af782u: goto P_0c0af782;
case 0x0c0af784u: goto P_0c0af784;
case 0x0c0af786u: goto P_0c0af786;
case 0x0c0af788u: goto P_0c0af788;
case 0x0c0af78au: goto P_0c0af78a;
case 0x0c0af78cu: goto P_0c0af78c;
case 0x0c0af78eu: goto P_0c0af78e;
case 0x0c0af790u: goto P_0c0af790;
case 0x0c0af792u: goto P_0c0af792;
case 0x0c0af794u: goto P_0c0af794;
case 0x0c0af796u: goto P_0c0af796;
case 0x0c0af798u: goto P_0c0af798;
case 0x0c0af79au: goto P_0c0af79a;
case 0x0c0af79cu: goto P_0c0af79c;
case 0x0c0af79eu: goto P_0c0af79e;
case 0x0c0af7a0u: goto P_0c0af7a0;
case 0x0c0af7a2u: goto P_0c0af7a2;
case 0x0c0af7a4u: goto P_0c0af7a4;
case 0x0c0af7a6u: goto P_0c0af7a6;
case 0x0c0af7a8u: goto P_0c0af7a8;
case 0x0c0af7aau: goto P_0c0af7aa;
case 0x0c0af7acu: goto P_0c0af7ac;
case 0x0c0af7aeu: goto P_0c0af7ae;
case 0x0c0af7b0u: goto P_0c0af7b0;
case 0x0c0af7b2u: goto P_0c0af7b2;
case 0x0c0af7b4u: goto P_0c0af7b4;
case 0x0c0af7b6u: goto P_0c0af7b6;
case 0x0c0af7b8u: goto P_0c0af7b8;
case 0x0c0af7bau: goto P_0c0af7ba;
case 0x0c0af7bcu: goto P_0c0af7bc;
case 0x0c0af7beu: goto P_0c0af7be;
case 0x0c0af7c0u: goto P_0c0af7c0;
case 0x0c0af7c2u: goto P_0c0af7c2;
case 0x0c0af7c4u: goto P_0c0af7c4;
case 0x0c0af7c6u: goto P_0c0af7c6;
case 0x0c0af7c8u: goto P_0c0af7c8;
case 0x0c0af7cau: goto P_0c0af7ca;
case 0x0c0af7ccu: goto P_0c0af7cc;
case 0x0c0af7ceu: goto P_0c0af7ce;
case 0x0c0af7d0u: goto P_0c0af7d0;
case 0x0c0af7d2u: goto P_0c0af7d2;
case 0x0c0af7d4u: goto P_0c0af7d4;
case 0x0c0af7d6u: goto P_0c0af7d6;
case 0x0c0af7d8u: goto P_0c0af7d8;
case 0x0c0af7dau: goto P_0c0af7da;
case 0x0c0af9d0u: goto P_0c0af9d0;
case 0x0c0af9d2u: goto P_0c0af9d2;
case 0x0c0af9d4u: goto P_0c0af9d4;
case 0x0c0af9d6u: goto P_0c0af9d6;
case 0x0c0af9d8u: goto P_0c0af9d8;
case 0x0c0af9dau: goto P_0c0af9da;
case 0x0c0af9dcu: goto P_0c0af9dc;
case 0x0c0af9deu: goto P_0c0af9de;
case 0x0c0af9e0u: goto P_0c0af9e0;
case 0x0c0af9e2u: goto P_0c0af9e2;
case 0x0c0af9e4u: goto P_0c0af9e4;
case 0x0c0af9e6u: goto P_0c0af9e6;
case 0x0c0af9e8u: goto P_0c0af9e8;
case 0x0c0af9eau: goto P_0c0af9ea;
case 0x0c0af9ecu: goto P_0c0af9ec;
case 0x0c0af9eeu: goto P_0c0af9ee;
case 0x0c0af9f0u: goto P_0c0af9f0;
case 0x0c0af9f2u: goto P_0c0af9f2;
case 0x0c0af9f4u: goto P_0c0af9f4;
case 0x0c0af9f6u: goto P_0c0af9f6;
case 0x0c0af9f8u: goto P_0c0af9f8;
case 0x0c0af9fau: goto P_0c0af9fa;
case 0x0c0af9fcu: goto P_0c0af9fc;
case 0x0c0af9feu: goto P_0c0af9fe;
case 0x0c0afa00u: goto P_0c0afa00;
case 0x0c0afa02u: goto P_0c0afa02;
case 0x0c0afa04u: goto P_0c0afa04;
case 0x0c0afa06u: goto P_0c0afa06;
case 0x0c0afa08u: goto P_0c0afa08;
case 0x0c0afa0au: goto P_0c0afa0a;
case 0x0c0afa0cu: goto P_0c0afa0c;
case 0x0c0afa0eu: goto P_0c0afa0e;
case 0x0c0afa10u: goto P_0c0afa10;
case 0x0c0afa12u: goto P_0c0afa12;
case 0x0c0afa14u: goto P_0c0afa14;
case 0x0c0afa16u: goto P_0c0afa16;
case 0x0c0afa18u: goto P_0c0afa18;
case 0x0c0afa1au: goto P_0c0afa1a;
case 0x0c0afa1cu: goto P_0c0afa1c;
case 0x0c0afa1eu: goto P_0c0afa1e;
case 0x0c0afa20u: goto P_0c0afa20;
case 0x0c0afa22u: goto P_0c0afa22;
case 0x0c0afa24u: goto P_0c0afa24;
case 0x0c0afa26u: goto P_0c0afa26;
case 0x0c0afa28u: goto P_0c0afa28;
case 0x0c0afa2au: goto P_0c0afa2a;
case 0x0c0afa2cu: goto P_0c0afa2c;
case 0x0c0afa2eu: goto P_0c0afa2e;
case 0x0c0afa30u: goto P_0c0afa30;
case 0x0c0afa32u: goto P_0c0afa32;
case 0x0c0afa34u: goto P_0c0afa34;
case 0x0c0afa36u: goto P_0c0afa36;
case 0x0c0afa38u: goto P_0c0afa38;
case 0x0c0afa3au: goto P_0c0afa3a;
case 0x0c0afa3cu: goto P_0c0afa3c;
case 0x0c0afa3eu: goto P_0c0afa3e;
case 0x0c0afa40u: goto P_0c0afa40;
case 0x0c0afa42u: goto P_0c0afa42;
case 0x0c0afa44u: goto P_0c0afa44;
case 0x0c0afa46u: goto P_0c0afa46;
case 0x0c0afa48u: goto P_0c0afa48;
case 0x0c0afa4au: goto P_0c0afa4a;
case 0x0c0afa4cu: goto P_0c0afa4c;
case 0x0c0afa4eu: goto P_0c0afa4e;
case 0x0c0afa50u: goto P_0c0afa50;
case 0x0c0afa52u: goto P_0c0afa52;
case 0x0c0afa54u: goto P_0c0afa54;
case 0x0c0afa56u: goto P_0c0afa56;
case 0x0c0afa58u: goto P_0c0afa58;
case 0x0c0afa5au: goto P_0c0afa5a;
case 0x0c0afa5cu: goto P_0c0afa5c;
case 0x0c0afa5eu: goto P_0c0afa5e;
case 0x0c0afa60u: goto P_0c0afa60;
case 0x0c0afa62u: goto P_0c0afa62;
case 0x0c0afa64u: goto P_0c0afa64;
case 0x0c0afa66u: goto P_0c0afa66;
case 0x0c0afa68u: goto P_0c0afa68;
case 0x0c0afa6au: goto P_0c0afa6a;
case 0x0c0afa6cu: goto P_0c0afa6c;
case 0x0c0afa6eu: goto P_0c0afa6e;
case 0x0c0afa70u: goto P_0c0afa70;
case 0x0c0afa72u: goto P_0c0afa72;
case 0x0c0afa74u: goto P_0c0afa74;
case 0x0c0afa76u: goto P_0c0afa76;
case 0x0c0afa78u: goto P_0c0afa78;
case 0x0c0afa7au: goto P_0c0afa7a;
case 0x0c0afa7cu: goto P_0c0afa7c;
case 0x0c0afa7eu: goto P_0c0afa7e;
case 0x0c0afa80u: goto P_0c0afa80;
case 0x0c0afa82u: goto P_0c0afa82;
case 0x0c0afa84u: goto P_0c0afa84;
case 0x0c0afa86u: goto P_0c0afa86;
case 0x0c0afa88u: goto P_0c0afa88;
case 0x0c0afa8au: goto P_0c0afa8a;
case 0x0c0afa8cu: goto P_0c0afa8c;
case 0x0c0afa8eu: goto P_0c0afa8e;
case 0x0c0afa90u: goto P_0c0afa90;
case 0x0c0afa92u: goto P_0c0afa92;
case 0x0c0afa94u: goto P_0c0afa94;
case 0x0c0afa96u: goto P_0c0afa96;
case 0x0c0afa98u: goto P_0c0afa98;
case 0x0c0afa9au: goto P_0c0afa9a;
case 0x0c0afa9cu: goto P_0c0afa9c;
case 0x0c0afa9eu: goto P_0c0afa9e;
case 0x0c0afaa0u: goto P_0c0afaa0;
case 0x0c0afaa2u: goto P_0c0afaa2;
case 0x0c0afaa4u: goto P_0c0afaa4;
case 0x0c0afaa6u: goto P_0c0afaa6;
case 0x0c0afaa8u: goto P_0c0afaa8;
case 0x0c0afaaau: goto P_0c0afaaa;
case 0x0c0afaacu: goto P_0c0afaac;
case 0x0c0afaaeu: goto P_0c0afaae;
case 0x0c0afab0u: goto P_0c0afab0;
case 0x0c0afab2u: goto P_0c0afab2;
case 0x0c0afab4u: goto P_0c0afab4;
case 0x0c0afab6u: goto P_0c0afab6;
case 0x0c0afaf0u: goto P_0c0afaf0;
case 0x0c0afaf2u: goto P_0c0afaf2;
case 0x0c0afaf4u: goto P_0c0afaf4;
case 0x0c0afaf6u: goto P_0c0afaf6;
case 0x0c0afaf8u: goto P_0c0afaf8;
case 0x0c0afafau: goto P_0c0afafa;
case 0x0c0afafcu: goto P_0c0afafc;
case 0x0c0afafeu: goto P_0c0afafe;
case 0x0c0afb00u: goto P_0c0afb00;
case 0x0c0afb02u: goto P_0c0afb02;
case 0x0c0afb04u: goto P_0c0afb04;
case 0x0c0afb06u: goto P_0c0afb06;
case 0x0c0afb08u: goto P_0c0afb08;
case 0x0c0afb0au: goto P_0c0afb0a;
case 0x0c0afb0cu: goto P_0c0afb0c;
case 0x0c0afb0eu: goto P_0c0afb0e;
case 0x0c0afb10u: goto P_0c0afb10;
case 0x0c0afb12u: goto P_0c0afb12;
case 0x0c0afb14u: goto P_0c0afb14;
case 0x0c0afb16u: goto P_0c0afb16;
case 0x0c0afb18u: goto P_0c0afb18;
case 0x0c0afb1au: goto P_0c0afb1a;
case 0x0c0afb1cu: goto P_0c0afb1c;
case 0x0c0afb1eu: goto P_0c0afb1e;
case 0x0c0afb20u: goto P_0c0afb20;
case 0x0c0afb22u: goto P_0c0afb22;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ae29c: /* original 5762, guest PC 0x0c0ae29c */
if(!s->budget--) { s->failed_pc=0x0c0ae29cu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae29e;
P_0c0ae29e: /* original 7ffc, guest PC 0x0c0ae29e */
if(!s->budget--) { s->failed_pc=0x0c0ae29eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae2a0;
P_0c0ae2a0: /* original 6770, guest PC 0x0c0ae2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0ae2a2;
P_0c0ae2a2: /* original 677c, guest PC 0x0c0ae2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae2a4;
P_0c0ae2a4: /* original 2778, guest PC 0x0c0ae2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0ae2a6;
P_0c0ae2a6: /* original 8910, guest PC 0x0c0ae2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2ca; }
goto P_0c0ae2a8;
P_0c0ae2a8: /* original 5362, guest PC 0x0c0ae2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a8u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2aa;
P_0c0ae2aa: /* original 2f32, guest PC 0x0c0ae2aa */
if(!s->budget--) { s->failed_pc=0x0c0ae2aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae2ac;
P_0c0ae2ac: /* original 62f2, guest PC 0x0c0ae2ac */
if(!s->budget--) { s->failed_pc=0x0c0ae2acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ae2ae;
P_0c0ae2ae: /* original 8432, guest PC 0x0c0ae2ae */
if(!s->budget--) { s->failed_pc=0x0c0ae2aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0ae2b0;
P_0c0ae2b0: /* original 7201, guest PC 0x0c0ae2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae2b2;
P_0c0ae2b2: /* original d315, guest PC 0x0c0ae2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b2u; return 0; }
r[3]=read(ram,0x0c0ae308u,4);
goto P_0c0ae2b4;
P_0c0ae2b4: /* original 600c, guest PC 0x0c0ae2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae2b6;
P_0c0ae2b6: /* original 6220, guest PC 0x0c0ae2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0ae2b8;
P_0c0ae2b8: /* original 4018, guest PC 0x0c0ae2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b8u; return 0; }
r[0]<<=8;
goto P_0c0ae2ba;
P_0c0ae2ba: /* original 622c, guest PC 0x0c0ae2ba */
if(!s->budget--) { s->failed_pc=0x0c0ae2bau; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae2bc;
P_0c0ae2bc: /* original 2039, guest PC 0x0c0ae2bc */
if(!s->budget--) { s->failed_pc=0x0c0ae2bcu; return 0; }
r[0]&=r[3];
goto P_0c0ae2be;
P_0c0ae2be: /* original 202b, guest PC 0x0c0ae2be */
if(!s->budget--) { s->failed_pc=0x0c0ae2beu; return 0; }
r[0]|=r[2];
goto P_0c0ae2c0;
P_0c0ae2c0: /* original 6103, guest PC 0x0c0ae2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c0u; return 0; }
r[1]=r[0];
goto P_0c0ae2c2;
P_0c0ae2c2: /* original 1601, guest PC 0x0c0ae2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c2u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0ae2c4;
P_0c0ae2c4: /* original 6262, guest PC 0x0c0ae2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c4u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae2c6;
P_0c0ae2c6: /* original 3212, guest PC 0x0c0ae2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c0ae2c8;
P_0c0ae2c8: /* original 8902, guest PC 0x0c0ae2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2d0; }
goto P_0c0ae2ca;
P_0c0ae2ca: /* original d310, guest PC 0x0c0ae2ca */
if(!s->budget--) { s->failed_pc=0x0c0ae2cau; return 0; }
r[3]=read(ram,0x0c0ae30cu,4);
goto P_0c0ae2cc;
P_0c0ae2cc: /* original 432b, guest PC 0x0c0ae2cc */
if(!s->budget--) { s->failed_pc=0x0c0ae2ccu; return 0; }
target=r[3];
r[15]+=0x00000004u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0af728u: goto P_0c0af728;
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
P_0c0ae2ce: /* original 7f04, guest PC 0x0c0ae2ce */
if(!s->budget--) { s->failed_pc=0x0c0ae2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae2d0;
P_0c0ae2d0: /* original d00f, guest PC 0x0c0ae2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d0u; return 0; }
r[0]=read(ram,0x0c0ae310u,4);
goto P_0c0ae2d2;
P_0c0ae2d2: /* original 4708, guest PC 0x0c0ae2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d2u; return 0; }
r[7]<<=2;
goto P_0c0ae2d4;
P_0c0ae2d4: /* original 027e, guest PC 0x0c0ae2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d4u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c0ae2d6;
P_0c0ae2d6: /* original 2f22, guest PC 0x0c0ae2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae2d8;
P_0c0ae2d8: /* original 422b, guest PC 0x0c0ae2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ae2da: /* original 7f04, guest PC 0x0c0ae2da */
if(!s->budget--) { s->failed_pc=0x0c0ae2dau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ae2dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae2dcu; return 0; } return 1;
P_0c0af728: /* original 2fe6, guest PC 0x0c0af728 */
if(!s->budget--) { s->failed_pc=0x0c0af728u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72a;
P_0c0af72a: /* original 6e43, guest PC 0x0c0af72a */
if(!s->budget--) { s->failed_pc=0x0c0af72au; return 0; }
r[14]=r[4];
goto P_0c0af72c;
P_0c0af72c: /* original 2fd6, guest PC 0x0c0af72c */
if(!s->budget--) { s->failed_pc=0x0c0af72cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72e;
P_0c0af72e: /* original 6d63, guest PC 0x0c0af72e */
if(!s->budget--) { s->failed_pc=0x0c0af72eu; return 0; }
r[13]=r[6];
goto P_0c0af730;
P_0c0af730: /* original 53d2, guest PC 0x0c0af730 */
if(!s->budget--) { s->failed_pc=0x0c0af730u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0af732;
P_0c0af732: /* original 907a, guest PC 0x0c0af732 */
if(!s->budget--) { s->failed_pc=0x0c0af732u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82au,2);
goto P_0c0af734;
P_0c0af734: /* original 4f22, guest PC 0x0c0af734 */
if(!s->budget--) { s->failed_pc=0x0c0af734u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af736;
P_0c0af736: /* original d441, guest PC 0x0c0af736 */
if(!s->budget--) { s->failed_pc=0x0c0af736u; return 0; }
r[4]=read(ram,0x0c0af83cu,4);
goto P_0c0af738;
P_0c0af738: /* original 0e36, guest PC 0x0c0af738 */
if(!s->budget--) { s->failed_pc=0x0c0af738u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0af73a;
P_0c0af73a: /* original 9377, guest PC 0x0c0af73a */
if(!s->budget--) { s->failed_pc=0x0c0af73au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82cu,2);
goto P_0c0af73c;
P_0c0af73c: /* original 7ff8, guest PC 0x0c0af73c */
if(!s->budget--) { s->failed_pc=0x0c0af73cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0af73e;
P_0c0af73e: /* original 52d3, guest PC 0x0c0af73e */
if(!s->budget--) { s->failed_pc=0x0c0af73eu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af740;
P_0c0af740: /* original 2238, guest PC 0x0c0af740 */
if(!s->budget--) { s->failed_pc=0x0c0af740u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0af742;
P_0c0af742: /* original 890e, guest PC 0x0c0af742 */
if(!s->budget--) { s->failed_pc=0x0c0af742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af762; }
goto P_0c0af744;
P_0c0af744: /* original 51d3, guest PC 0x0c0af744 */
if(!s->budget--) { s->failed_pc=0x0c0af744u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af746;
P_0c0af746: /* original 9372, guest PC 0x0c0af746 */
if(!s->budget--) { s->failed_pc=0x0c0af746u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82eu,2);
goto P_0c0af748;
P_0c0af748: /* original 2139, guest PC 0x0c0af748 */
if(!s->budget--) { s->failed_pc=0x0c0af748u; return 0; }
r[1]&=r[3];
goto P_0c0af74a;
P_0c0af74a: /* original 1d13, guest PC 0x0c0af74a */
if(!s->budget--) { s->failed_pc=0x0c0af74au; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af74c;
P_0c0af74c: /* original d53c, guest PC 0x0c0af74c */
if(!s->budget--) { s->failed_pc=0x0c0af74cu; return 0; }
r[5]=read(ram,0x0c0af840u,4);
goto P_0c0af74e;
P_0c0af74e: /* original 5241, guest PC 0x0c0af74e */
if(!s->budget--) { s->failed_pc=0x0c0af74eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0af750;
P_0c0af750: /* original 2258, guest PC 0x0c0af750 */
if(!s->budget--) { s->failed_pc=0x0c0af750u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0af752;
P_0c0af752: /* original 8b06, guest PC 0x0c0af752 */
if(!s->budget--) { s->failed_pc=0x0c0af752u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af754;
P_0c0af754: /* original 6342, guest PC 0x0c0af754 */
if(!s->budget--) { s->failed_pc=0x0c0af754u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0af756;
P_0c0af756: /* original 2538, guest PC 0x0c0af756 */
if(!s->budget--) { s->failed_pc=0x0c0af756u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0af758;
P_0c0af758: /* original 8b03, guest PC 0x0c0af758 */
if(!s->budget--) { s->failed_pc=0x0c0af758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af75a;
P_0c0af75a: /* original 85ef, guest PC 0x0c0af75a */
if(!s->budget--) { s->failed_pc=0x0c0af75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af75c;
P_0c0af75c: /* original 9368, guest PC 0x0c0af75c */
if(!s->budget--) { s->failed_pc=0x0c0af75cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af830u,2);
goto P_0c0af75e;
P_0c0af75e: /* original 303c, guest PC 0x0c0af75e */
if(!s->budget--) { s->failed_pc=0x0c0af75eu; return 0; }
r[0]+=r[3];
goto P_0c0af760;
P_0c0af760: /* original 81ef, guest PC 0x0c0af760 */
if(!s->budget--) { s->failed_pc=0x0c0af760u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0af762;
P_0c0af762: /* original 53d4, guest PC 0x0c0af762 */
if(!s->budget--) { s->failed_pc=0x0c0af762u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0af764;
P_0c0af764: /* original d437, guest PC 0x0c0af764 */
if(!s->budget--) { s->failed_pc=0x0c0af764u; return 0; }
r[4]=read(ram,0x0c0af844u,4);
goto P_0c0af766;
P_0c0af766: /* original 2348, guest PC 0x0c0af766 */
if(!s->budget--) { s->failed_pc=0x0c0af766u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af768;
P_0c0af768: /* original 8903, guest PC 0x0c0af768 */
if(!s->budget--) { s->failed_pc=0x0c0af768u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af772; }
goto P_0c0af76a;
P_0c0af76a: /* original 52d3, guest PC 0x0c0af76a */
if(!s->budget--) { s->failed_pc=0x0c0af76au; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af76c;
P_0c0af76c: /* original d336, guest PC 0x0c0af76c */
if(!s->budget--) { s->failed_pc=0x0c0af76cu; return 0; }
r[3]=read(ram,0x0c0af848u,4);
goto P_0c0af76e;
P_0c0af76e: /* original 223b, guest PC 0x0c0af76e */
if(!s->budget--) { s->failed_pc=0x0c0af76eu; return 0; }
r[2]|=r[3];
goto P_0c0af770;
P_0c0af770: /* original 1d23, guest PC 0x0c0af770 */
if(!s->budget--) { s->failed_pc=0x0c0af770u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af772;
P_0c0af772: /* original 51d3, guest PC 0x0c0af772 */
if(!s->budget--) { s->failed_pc=0x0c0af772u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af774;
P_0c0af774: /* original 2418, guest PC 0x0c0af774 */
if(!s->budget--) { s->failed_pc=0x0c0af774u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0af776;
P_0c0af776: /* original 891e, guest PC 0x0c0af776 */
if(!s->budget--) { s->failed_pc=0x0c0af776u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7b6; }
goto P_0c0af778;
P_0c0af778: /* original d334, guest PC 0x0c0af778 */
if(!s->budget--) { s->failed_pc=0x0c0af778u; return 0; }
r[3]=read(ram,0x0c0af84cu,4);
goto P_0c0af77a;
P_0c0af77a: /* original 65f3, guest PC 0x0c0af77a */
if(!s->budget--) { s->failed_pc=0x0c0af77au; return 0; }
r[5]=r[15];
goto P_0c0af77c;
P_0c0af77c: /* original 52d3, guest PC 0x0c0af77c */
if(!s->budget--) { s->failed_pc=0x0c0af77cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af77e;
P_0c0af77e: /* original 66f3, guest PC 0x0c0af77e */
if(!s->budget--) { s->failed_pc=0x0c0af77eu; return 0; }
r[6]=r[15];
goto P_0c0af780;
P_0c0af780: /* original 2239, guest PC 0x0c0af780 */
if(!s->budget--) { s->failed_pc=0x0c0af780u; return 0; }
r[2]&=r[3];
goto P_0c0af782;
P_0c0af782: /* original 1d23, guest PC 0x0c0af782 */
if(!s->budget--) { s->failed_pc=0x0c0af782u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af784;
P_0c0af784: /* original 85ef, guest PC 0x0c0af784 */
if(!s->budget--) { s->failed_pc=0x0c0af784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af786;
P_0c0af786: /* original 640d, guest PC 0x0c0af786 */
if(!s->budget--) { s->failed_pc=0x0c0af786u; return 0; }
r[4]=r[0]&65535u;
goto P_0c0af788;
P_0c0af788: /* original 9053, guest PC 0x0c0af788 */
if(!s->budget--) { s->failed_pc=0x0c0af788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af832u,2);
goto P_0c0af78a;
P_0c0af78a: /* original f3e6, guest PC 0x0c0af78a */
if(!s->budget--) { s->failed_pc=0x0c0af78au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af78c;
P_0c0af78c: /* original e004, guest PC 0x0c0af78c */
if(!s->budget--) { s->failed_pc=0x0c0af78cu; return 0; }
r[0]=0x00000004u;
goto P_0c0af78e;
P_0c0af78e: /* original ff37, guest PC 0x0c0af78e */
if(!s->budget--) { s->failed_pc=0x0c0af78eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0af790;
P_0c0af790: /* original 9050, guest PC 0x0c0af790 */
if(!s->budget--) { s->failed_pc=0x0c0af790u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af834u,2);
goto P_0c0af792;
P_0c0af792: /* original f3e6, guest PC 0x0c0af792 */
if(!s->budget--) { s->failed_pc=0x0c0af792u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af794;
P_0c0af794: /* original ff3a, guest PC 0x0c0af794 */
if(!s->budget--) { s->failed_pc=0x0c0af794u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0af796;
P_0c0af796: /* original d22e, guest PC 0x0c0af796 */
if(!s->budget--) { s->failed_pc=0x0c0af796u; return 0; }
r[2]=read(ram,0x0c0af850u,4);
goto P_0c0af798;
P_0c0af798: /* original 420b, guest PC 0x0c0af798 */
if(!s->budget--) { s->failed_pc=0x0c0af798u; return 0; }
target=r[2];
r[16]=code_base|0x0c0af79cu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af79cu) { target=s->pc; goto dispatch; }
goto P_0c0af79c;
P_0c0af79a: /* original 7504, guest PC 0x0c0af79a */
if(!s->budget--) { s->failed_pc=0x0c0af79au; return 0; }
r[5]+=0x00000004u;
goto P_0c0af79c;
P_0c0af79c: /* original 904b, guest PC 0x0c0af79c */
if(!s->budget--) { s->failed_pc=0x0c0af79cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af836u,2);
goto P_0c0af79e;
P_0c0af79e: /* original f2f8, guest PC 0x0c0af79e */
if(!s->budget--) { s->failed_pc=0x0c0af79eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0af7a0;
P_0c0af7a0: /* original f5e6, guest PC 0x0c0af7a0 */
if(!s->budget--) { s->failed_pc=0x0c0af7a0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0af7a2;
P_0c0af7a2: /* original 7008, guest PC 0x0c0af7a2 */
if(!s->budget--) { s->failed_pc=0x0c0af7a2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0af7a4;
P_0c0af7a4: /* original f4e6, guest PC 0x0c0af7a4 */
if(!s->budget--) { s->failed_pc=0x0c0af7a4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0af7a6;
P_0c0af7a6: /* original e004, guest PC 0x0c0af7a6 */
if(!s->budget--) { s->failed_pc=0x0c0af7a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0af7a8;
P_0c0af7a8: /* original f3f6, guest PC 0x0c0af7a8 */
if(!s->budget--) { s->failed_pc=0x0c0af7a8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af7aa;
P_0c0af7aa: /* original e010, guest PC 0x0c0af7aa */
if(!s->budget--) { s->failed_pc=0x0c0af7aau; return 0; }
r[0]=0x00000010u;
goto P_0c0af7ac;
P_0c0af7ac: /* original f421, guest PC 0x0c0af7ac */
if(!s->budget--) { s->failed_pc=0x0c0af7acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0af7ae;
P_0c0af7ae: /* original f531, guest PC 0x0c0af7ae */
if(!s->budget--) { s->failed_pc=0x0c0af7aeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0af7b0;
P_0c0af7b0: /* original fe57, guest PC 0x0c0af7b0 */
if(!s->budget--) { s->failed_pc=0x0c0af7b0u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0af7b2;
P_0c0af7b2: /* original e018, guest PC 0x0c0af7b2 */
if(!s->budget--) { s->failed_pc=0x0c0af7b2u; return 0; }
r[0]=0x00000018u;
goto P_0c0af7b4;
P_0c0af7b4: /* original fe47, guest PC 0x0c0af7b4 */
if(!s->budget--) { s->failed_pc=0x0c0af7b4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0af7b6;
P_0c0af7b6: /* original d327, guest PC 0x0c0af7b6 */
if(!s->budget--) { s->failed_pc=0x0c0af7b6u; return 0; }
r[3]=read(ram,0x0c0af854u,4);
goto P_0c0af7b8;
P_0c0af7b8: /* original 64e2, guest PC 0x0c0af7b8 */
if(!s->budget--) { s->failed_pc=0x0c0af7b8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0af7ba;
P_0c0af7ba: /* original 2348, guest PC 0x0c0af7ba */
if(!s->budget--) { s->failed_pc=0x0c0af7bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af7bc;
P_0c0af7bc: /* original 8906, guest PC 0x0c0af7bc */
if(!s->budget--) { s->failed_pc=0x0c0af7bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7cc; }
goto P_0c0af7be;
P_0c0af7be: /* original d226, guest PC 0x0c0af7be */
if(!s->budget--) { s->failed_pc=0x0c0af7beu; return 0; }
r[2]=read(ram,0x0c0af858u,4);
goto P_0c0af7c0;
P_0c0af7c0: /* original 2429, guest PC 0x0c0af7c0 */
if(!s->budget--) { s->failed_pc=0x0c0af7c0u; return 0; }
r[4]&=r[2];
goto P_0c0af7c2;
P_0c0af7c2: /* original 2e42, guest PC 0x0c0af7c2 */
if(!s->budget--) { s->failed_pc=0x0c0af7c2u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0af7c4;
P_0c0af7c4: /* original d325, guest PC 0x0c0af7c4 */
if(!s->budget--) { s->failed_pc=0x0c0af7c4u; return 0; }
r[3]=read(ram,0x0c0af85cu,4);
goto P_0c0af7c6;
P_0c0af7c6: /* original 51d3, guest PC 0x0c0af7c6 */
if(!s->budget--) { s->failed_pc=0x0c0af7c6u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af7c8;
P_0c0af7c8: /* original 213b, guest PC 0x0c0af7c8 */
if(!s->budget--) { s->failed_pc=0x0c0af7c8u; return 0; }
r[1]|=r[3];
goto P_0c0af7ca;
P_0c0af7ca: /* original 1d13, guest PC 0x0c0af7ca */
if(!s->budget--) { s->failed_pc=0x0c0af7cau; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af7cc;
P_0c0af7cc: /* original 7f08, guest PC 0x0c0af7cc */
if(!s->budget--) { s->failed_pc=0x0c0af7ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c0af7ce;
P_0c0af7ce: /* original 52d3, guest PC 0x0c0af7ce */
if(!s->budget--) { s->failed_pc=0x0c0af7ceu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af7d0;
P_0c0af7d0: /* original 4f26, guest PC 0x0c0af7d0 */
if(!s->budget--) { s->failed_pc=0x0c0af7d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af7d2;
P_0c0af7d2: /* original e048, guest PC 0x0c0af7d2 */
if(!s->budget--) { s->failed_pc=0x0c0af7d2u; return 0; }
r[0]=0x00000048u;
goto P_0c0af7d4;
P_0c0af7d4: /* original 0e26, guest PC 0x0c0af7d4 */
if(!s->budget--) { s->failed_pc=0x0c0af7d4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0af7d6;
P_0c0af7d6: /* original 6df6, guest PC 0x0c0af7d6 */
if(!s->budget--) { s->failed_pc=0x0c0af7d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af7d8;
P_0c0af7d8: /* original 000b, guest PC 0x0c0af7d8 */
if(!s->budget--) { s->failed_pc=0x0c0af7d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af7da: /* original 6ef6, guest PC 0x0c0af7da */
if(!s->budget--) { s->failed_pc=0x0c0af7dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af7dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af7dcu; return 0; } return 1;
P_0c0af9d0: /* original 2fe6, guest PC 0x0c0af9d0 */
if(!s->budget--) { s->failed_pc=0x0c0af9d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af9d2;
P_0c0af9d2: /* original 6e43, guest PC 0x0c0af9d2 */
if(!s->budget--) { s->failed_pc=0x0c0af9d2u; return 0; }
r[14]=r[4];
goto P_0c0af9d4;
P_0c0af9d4: /* original 2fd6, guest PC 0x0c0af9d4 */
if(!s->budget--) { s->failed_pc=0x0c0af9d4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af9d6;
P_0c0af9d6: /* original 6d53, guest PC 0x0c0af9d6 */
if(!s->budget--) { s->failed_pc=0x0c0af9d6u; return 0; }
r[13]=r[5];
goto P_0c0af9d8;
P_0c0af9d8: /* original 2fc6, guest PC 0x0c0af9d8 */
if(!s->budget--) { s->failed_pc=0x0c0af9d8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af9da;
P_0c0af9da: /* original 2fb6, guest PC 0x0c0af9da */
if(!s->budget--) { s->failed_pc=0x0c0af9dau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af9dc;
P_0c0af9dc: /* original 906d, guest PC 0x0c0af9dc */
if(!s->budget--) { s->failed_pc=0x0c0af9dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afabau,2);
goto P_0c0af9de;
P_0c0af9de: /* original d33c, guest PC 0x0c0af9de */
if(!s->budget--) { s->failed_pc=0x0c0af9deu; return 0; }
r[3]=read(ram,0x0c0afad0u,4);
goto P_0c0af9e0;
P_0c0af9e0: /* original 0bdd, guest PC 0x0c0af9e0 */
if(!s->budget--) { s->failed_pc=0x0c0af9e0u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0af9e2;
P_0c0af9e2: /* original e048, guest PC 0x0c0af9e2 */
if(!s->budget--) { s->failed_pc=0x0c0af9e2u; return 0; }
r[0]=0x00000048u;
goto P_0c0af9e4;
P_0c0af9e4: /* original 4f22, guest PC 0x0c0af9e4 */
if(!s->budget--) { s->failed_pc=0x0c0af9e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af9e6;
P_0c0af9e6: /* original d23b, guest PC 0x0c0af9e6 */
if(!s->budget--) { s->failed_pc=0x0c0af9e6u; return 0; }
r[2]=read(ram,0x0c0afad4u,4);
goto P_0c0af9e8;
P_0c0af9e8: /* original 01ee, guest PC 0x0c0af9e8 */
if(!s->budget--) { s->failed_pc=0x0c0af9e8u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0af9ea;
P_0c0af9ea: /* original 6c32, guest PC 0x0c0af9ea */
if(!s->budget--) { s->failed_pc=0x0c0af9eau; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c0af9ec;
P_0c0af9ec: /* original 7ff8, guest PC 0x0c0af9ec */
if(!s->budget--) { s->failed_pc=0x0c0af9ecu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0af9ee;
P_0c0af9ee: /* original 2128, guest PC 0x0c0af9ee */
if(!s->budget--) { s->failed_pc=0x0c0af9eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0af9f0;
P_0c0af9f0: /* original 8d05, guest PC 0x0c0af9f0 */
if(!s->budget--) { s->failed_pc=0x0c0af9f0u; return 0; }
cond=r[17]&1u;
r[11]=r[11]&65535u;
if(cond) { goto P_0c0af9fe; }
goto P_0c0af9f4;
P_0c0af9f2: /* original 6bbd, guest PC 0x0c0af9f2 */
if(!s->budget--) { s->failed_pc=0x0c0af9f2u; return 0; }
r[11]=r[11]&65535u;
goto P_0c0af9f4;
P_0c0af9f4: /* original 9062, guest PC 0x0c0af9f4 */
if(!s->budget--) { s->failed_pc=0x0c0af9f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afabcu,2);
goto P_0c0af9f6;
P_0c0af9f6: /* original 03ed, guest PC 0x0c0af9f6 */
if(!s->budget--) { s->failed_pc=0x0c0af9f6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0af9f8;
P_0c0af9f8: /* original 633d, guest PC 0x0c0af9f8 */
if(!s->budget--) { s->failed_pc=0x0c0af9f8u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0af9fa;
P_0c0af9fa: /* original 3b30, guest PC 0x0c0af9fa */
if(!s->budget--) { s->failed_pc=0x0c0af9fau; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c0af9fc;
P_0c0af9fc: /* original 8978, guest PC 0x0c0af9fc */
if(!s->budget--) { s->failed_pc=0x0c0af9fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afaf0; }
goto P_0c0af9fe;
P_0c0af9fe: /* original e050, guest PC 0x0c0af9fe */
if(!s->budget--) { s->failed_pc=0x0c0af9feu; return 0; }
r[0]=0x00000050u;
goto P_0c0afa00;
P_0c0afa00: /* original d335, guest PC 0x0c0afa00 */
if(!s->budget--) { s->failed_pc=0x0c0afa00u; return 0; }
r[3]=read(ram,0x0c0afad8u,4);
goto P_0c0afa02;
P_0c0afa02: /* original 02ee, guest PC 0x0c0afa02 */
if(!s->budget--) { s->failed_pc=0x0c0afa02u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0afa04;
P_0c0afa04: /* original 2238, guest PC 0x0c0afa04 */
if(!s->budget--) { s->failed_pc=0x0c0afa04u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0afa06;
P_0c0afa06: /* original 8901, guest PC 0x0c0afa06 */
if(!s->budget--) { s->failed_pc=0x0c0afa06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afa0c; }
goto P_0c0afa08;
P_0c0afa08: /* original a083, guest PC 0x0c0afa08 */
if(!s->budget--) { s->failed_pc=0x0c0afa08u; return 0; }
goto P_0c0afb12;
P_0c0afa0a: /* original 0009, guest PC 0x0c0afa0a */
if(!s->budget--) { s->failed_pc=0x0c0afa0au; return 0; }
goto P_0c0afa0c;
P_0c0afa0c: /* original 61f3, guest PC 0x0c0afa0c */
if(!s->budget--) { s->failed_pc=0x0c0afa0cu; return 0; }
r[1]=r[15];
goto P_0c0afa0e;
P_0c0afa0e: /* original 7104, guest PC 0x0c0afa0e */
if(!s->budget--) { s->failed_pc=0x0c0afa0eu; return 0; }
r[1]+=0x00000004u;
goto P_0c0afa10;
P_0c0afa10: /* original e300, guest PC 0x0c0afa10 */
if(!s->budget--) { s->failed_pc=0x0c0afa10u; return 0; }
r[3]=0x00000000u;
goto P_0c0afa12;
P_0c0afa12: /* original 2f16, guest PC 0x0c0afa12 */
if(!s->budget--) { s->failed_pc=0x0c0afa12u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afa14;
P_0c0afa14: /* original 2f36, guest PC 0x0c0afa14 */
if(!s->budget--) { s->failed_pc=0x0c0afa14u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afa16;
P_0c0afa16: /* original 65e3, guest PC 0x0c0afa16 */
if(!s->budget--) { s->failed_pc=0x0c0afa16u; return 0; }
r[5]=r[14];
goto P_0c0afa18;
P_0c0afa18: /* original d230, guest PC 0x0c0afa18 */
if(!s->budget--) { s->failed_pc=0x0c0afa18u; return 0; }
r[2]=read(ram,0x0c0afadcu,4);
goto P_0c0afa1a;
P_0c0afa1a: /* original 67f3, guest PC 0x0c0afa1a */
if(!s->budget--) { s->failed_pc=0x0c0afa1au; return 0; }
r[7]=r[15];
goto P_0c0afa1c;
P_0c0afa1c: /* original 7708, guest PC 0x0c0afa1c */
if(!s->budget--) { s->failed_pc=0x0c0afa1cu; return 0; }
r[7]+=0x00000008u;
goto P_0c0afa1e;
P_0c0afa1e: /* original 6633, guest PC 0x0c0afa1e */
if(!s->budget--) { s->failed_pc=0x0c0afa1eu; return 0; }
r[6]=r[3];
goto P_0c0afa20;
P_0c0afa20: /* original 420b, guest PC 0x0c0afa20 */
if(!s->budget--) { s->failed_pc=0x0c0afa20u; return 0; }
target=r[2];
r[16]=code_base|0x0c0afa24u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0afa24u) { target=s->pc; goto dispatch; }
goto P_0c0afa24;
P_0c0afa22: /* original 64d3, guest PC 0x0c0afa22 */
if(!s->budget--) { s->failed_pc=0x0c0afa22u; return 0; }
r[4]=r[13];
goto P_0c0afa24;
P_0c0afa24: /* original 7f08, guest PC 0x0c0afa24 */
if(!s->budget--) { s->failed_pc=0x0c0afa24u; return 0; }
r[15]+=0x00000008u;
goto P_0c0afa26;
P_0c0afa26: /* original 63f2, guest PC 0x0c0afa26 */
if(!s->budget--) { s->failed_pc=0x0c0afa26u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0afa28;
P_0c0afa28: /* original 2338, guest PC 0x0c0afa28 */
if(!s->budget--) { s->failed_pc=0x0c0afa28u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0afa2a;
P_0c0afa2a: /* original 8972, guest PC 0x0c0afa2a */
if(!s->budget--) { s->failed_pc=0x0c0afa2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afb12; }
goto P_0c0afa2c;
P_0c0afa2c: /* original 64f2, guest PC 0x0c0afa2c */
if(!s->budget--) { s->failed_pc=0x0c0afa2cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0afa2e;
P_0c0afa2e: /* original 9346, guest PC 0x0c0afa2e */
if(!s->budget--) { s->failed_pc=0x0c0afa2eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afabeu,2);
goto P_0c0afa30;
P_0c0afa30: /* original d22b, guest PC 0x0c0afa30 */
if(!s->budget--) { s->failed_pc=0x0c0afa30u; return 0; }
r[2]=read(ram,0x0c0afae0u,4);
goto P_0c0afa32;
P_0c0afa32: /* original 2439, guest PC 0x0c0afa32 */
if(!s->budget--) { s->failed_pc=0x0c0afa32u; return 0; }
r[4]&=r[3];
goto P_0c0afa34;
P_0c0afa34: /* original d12b, guest PC 0x0c0afa34 */
if(!s->budget--) { s->failed_pc=0x0c0afa34u; return 0; }
r[1]=read(ram,0x0c0afae4u,4);
goto P_0c0afa36;
P_0c0afa36: /* original 6043, guest PC 0x0c0afa36 */
if(!s->budget--) { s->failed_pc=0x0c0afa36u; return 0; }
r[0]=r[4];
goto P_0c0afa38;
P_0c0afa38: /* original 70ff, guest PC 0x0c0afa38 */
if(!s->budget--) { s->failed_pc=0x0c0afa38u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0afa3a;
P_0c0afa3a: /* original 4008, guest PC 0x0c0afa3a */
if(!s->budget--) { s->failed_pc=0x0c0afa3au; return 0; }
r[0]<<=2;
goto P_0c0afa3c;
P_0c0afa3c: /* original 04ce, guest PC 0x0c0afa3c */
if(!s->budget--) { s->failed_pc=0x0c0afa3cu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0afa3e;
P_0c0afa3e: /* original 34cc, guest PC 0x0c0afa3e */
if(!s->budget--) { s->failed_pc=0x0c0afa3eu; return 0; }
r[4]+=r[12];
goto P_0c0afa40;
P_0c0afa40: /* original 8443, guest PC 0x0c0afa40 */
if(!s->budget--) { s->failed_pc=0x0c0afa40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0afa42;
P_0c0afa42: /* original 600c, guest PC 0x0c0afa42 */
if(!s->budget--) { s->failed_pc=0x0c0afa42u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa44;
P_0c0afa44: /* original 4028, guest PC 0x0c0afa44 */
if(!s->budget--) { s->failed_pc=0x0c0afa44u; return 0; }
r[0]<<=16;
goto P_0c0afa46;
P_0c0afa46: /* original 4018, guest PC 0x0c0afa46 */
if(!s->budget--) { s->failed_pc=0x0c0afa46u; return 0; }
r[0]<<=8;
goto P_0c0afa48;
P_0c0afa48: /* original 2029, guest PC 0x0c0afa48 */
if(!s->budget--) { s->failed_pc=0x0c0afa48u; return 0; }
r[0]&=r[2];
goto P_0c0afa4a;
P_0c0afa4a: /* original 6303, guest PC 0x0c0afa4a */
if(!s->budget--) { s->failed_pc=0x0c0afa4au; return 0; }
r[3]=r[0];
goto P_0c0afa4c;
P_0c0afa4c: /* original 8442, guest PC 0x0c0afa4c */
if(!s->budget--) { s->failed_pc=0x0c0afa4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0afa4e;
P_0c0afa4e: /* original 4229, guest PC 0x0c0afa4e */
if(!s->budget--) { s->failed_pc=0x0c0afa4eu; return 0; }
r[2]>>=16;
goto P_0c0afa50;
P_0c0afa50: /* original 600c, guest PC 0x0c0afa50 */
if(!s->budget--) { s->failed_pc=0x0c0afa50u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa52;
P_0c0afa52: /* original 4028, guest PC 0x0c0afa52 */
if(!s->budget--) { s->failed_pc=0x0c0afa52u; return 0; }
r[0]<<=16;
goto P_0c0afa54;
P_0c0afa54: /* original 2019, guest PC 0x0c0afa54 */
if(!s->budget--) { s->failed_pc=0x0c0afa54u; return 0; }
r[0]&=r[1];
goto P_0c0afa56;
P_0c0afa56: /* original 230b, guest PC 0x0c0afa56 */
if(!s->budget--) { s->failed_pc=0x0c0afa56u; return 0; }
r[3]|=r[0];
goto P_0c0afa58;
P_0c0afa58: /* original 8441, guest PC 0x0c0afa58 */
if(!s->budget--) { s->failed_pc=0x0c0afa58u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0afa5a;
P_0c0afa5a: /* original 600c, guest PC 0x0c0afa5a */
if(!s->budget--) { s->failed_pc=0x0c0afa5au; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa5c;
P_0c0afa5c: /* original 4018, guest PC 0x0c0afa5c */
if(!s->budget--) { s->failed_pc=0x0c0afa5cu; return 0; }
r[0]<<=8;
goto P_0c0afa5e;
P_0c0afa5e: /* original 2029, guest PC 0x0c0afa5e */
if(!s->budget--) { s->failed_pc=0x0c0afa5eu; return 0; }
r[0]&=r[2];
goto P_0c0afa60;
P_0c0afa60: /* original 230b, guest PC 0x0c0afa60 */
if(!s->budget--) { s->failed_pc=0x0c0afa60u; return 0; }
r[3]|=r[0];
goto P_0c0afa62;
P_0c0afa62: /* original 6040, guest PC 0x0c0afa62 */
if(!s->budget--) { s->failed_pc=0x0c0afa62u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c0afa64;
P_0c0afa64: /* original 6433, guest PC 0x0c0afa64 */
if(!s->budget--) { s->failed_pc=0x0c0afa64u; return 0; }
r[4]=r[3];
goto P_0c0afa66;
P_0c0afa66: /* original d31b, guest PC 0x0c0afa66 */
if(!s->budget--) { s->failed_pc=0x0c0afa66u; return 0; }
r[3]=read(ram,0x0c0afad4u,4);
goto P_0c0afa68;
P_0c0afa68: /* original 600c, guest PC 0x0c0afa68 */
if(!s->budget--) { s->failed_pc=0x0c0afa68u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa6a;
P_0c0afa6a: /* original 240b, guest PC 0x0c0afa6a */
if(!s->budget--) { s->failed_pc=0x0c0afa6au; return 0; }
r[4]|=r[0];
goto P_0c0afa6c;
P_0c0afa6c: /* original 2438, guest PC 0x0c0afa6c */
if(!s->budget--) { s->failed_pc=0x0c0afa6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0afa6e;
P_0c0afa6e: /* original 8950, guest PC 0x0c0afa6e */
if(!s->budget--) { s->failed_pc=0x0c0afa6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afb12; }
goto P_0c0afa70;
P_0c0afa70: /* original e03e, guest PC 0x0c0afa70 */
if(!s->budget--) { s->failed_pc=0x0c0afa70u; return 0; }
r[0]=0x0000003eu;
goto P_0c0afa72;
P_0c0afa72: /* original 0cdd, guest PC 0x0c0afa72 */
if(!s->budget--) { s->failed_pc=0x0c0afa72u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0afa74;
P_0c0afa74: /* original e502, guest PC 0x0c0afa74 */
if(!s->budget--) { s->failed_pc=0x0c0afa74u; return 0; }
r[5]=0x00000002u;
goto P_0c0afa76;
P_0c0afa76: /* original 84d4, guest PC 0x0c0afa76 */
if(!s->budget--) { s->failed_pc=0x0c0afa76u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c0afa78;
P_0c0afa78: /* original 6ccd, guest PC 0x0c0afa78 */
if(!s->budget--) { s->failed_pc=0x0c0afa78u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0afa7a;
P_0c0afa7a: /* original 600c, guest PC 0x0c0afa7a */
if(!s->budget--) { s->failed_pc=0x0c0afa7au; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa7c;
P_0c0afa7c: /* original 3c0c, guest PC 0x0c0afa7c */
if(!s->budget--) { s->failed_pc=0x0c0afa7cu; return 0; }
r[12]+=r[0];
goto P_0c0afa7e;
P_0c0afa7e: /* original 901f, guest PC 0x0c0afa7e */
if(!s->budget--) { s->failed_pc=0x0c0afa7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afac0u,2);
goto P_0c0afa80;
P_0c0afa80: /* original 03dd, guest PC 0x0c0afa80 */
if(!s->budget--) { s->failed_pc=0x0c0afa80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0afa82;
P_0c0afa82: /* original 623d, guest PC 0x0c0afa82 */
if(!s->budget--) { s->failed_pc=0x0c0afa82u; return 0; }
r[2]=r[3]&65535u;
goto P_0c0afa84;
P_0c0afa84: /* original d318, guest PC 0x0c0afa84 */
if(!s->budget--) { s->failed_pc=0x0c0afa84u; return 0; }
r[3]=read(ram,0x0c0afae8u,4);
goto P_0c0afa86;
P_0c0afa86: /* original 32c8, guest PC 0x0c0afa86 */
if(!s->budget--) { s->failed_pc=0x0c0afa86u; return 0; }
r[2]-=r[12];
goto P_0c0afa88;
P_0c0afa88: /* original 6c23, guest PC 0x0c0afa88 */
if(!s->budget--) { s->failed_pc=0x0c0afa88u; return 0; }
r[12]=r[2];
goto P_0c0afa8a;
P_0c0afa8a: /* original 430b, guest PC 0x0c0afa8a */
if(!s->budget--) { s->failed_pc=0x0c0afa8au; return 0; }
target=r[3];
r[16]=code_base|0x0c0afa8eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0afa8eu) { target=s->pc; goto dispatch; }
goto P_0c0afa8e;
P_0c0afa8c: /* original 64f2, guest PC 0x0c0afa8c */
if(!s->budget--) { s->failed_pc=0x0c0afa8cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0afa8e;
P_0c0afa8e: /* original 6403, guest PC 0x0c0afa8e */
if(!s->budget--) { s->failed_pc=0x0c0afa8eu; return 0; }
r[4]=r[0];
goto P_0c0afa90;
P_0c0afa90: /* original 8442, guest PC 0x0c0afa90 */
if(!s->budget--) { s->failed_pc=0x0c0afa90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0afa92;
P_0c0afa92: /* original d316, guest PC 0x0c0afa92 */
if(!s->budget--) { s->failed_pc=0x0c0afa92u; return 0; }
r[3]=read(ram,0x0c0afaecu,4);
goto P_0c0afa94;
P_0c0afa94: /* original 600c, guest PC 0x0c0afa94 */
if(!s->budget--) { s->failed_pc=0x0c0afa94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa96;
P_0c0afa96: /* original 4018, guest PC 0x0c0afa96 */
if(!s->budget--) { s->failed_pc=0x0c0afa96u; return 0; }
r[0]<<=8;
goto P_0c0afa98;
P_0c0afa98: /* original 2039, guest PC 0x0c0afa98 */
if(!s->budget--) { s->failed_pc=0x0c0afa98u; return 0; }
r[0]&=r[3];
goto P_0c0afa9a;
P_0c0afa9a: /* original 6203, guest PC 0x0c0afa9a */
if(!s->budget--) { s->failed_pc=0x0c0afa9au; return 0; }
r[2]=r[0];
goto P_0c0afa9c;
P_0c0afa9c: /* original 8441, guest PC 0x0c0afa9c */
if(!s->budget--) { s->failed_pc=0x0c0afa9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0afa9e;
P_0c0afa9e: /* original 6423, guest PC 0x0c0afa9e */
if(!s->budget--) { s->failed_pc=0x0c0afa9eu; return 0; }
r[4]=r[2];
goto P_0c0afaa0;
P_0c0afaa0: /* original 600c, guest PC 0x0c0afaa0 */
if(!s->budget--) { s->failed_pc=0x0c0afaa0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afaa2;
P_0c0afaa2: /* original 240b, guest PC 0x0c0afaa2 */
if(!s->budget--) { s->failed_pc=0x0c0afaa2u; return 0; }
r[4]|=r[0];
goto P_0c0afaa4;
P_0c0afaa4: /* original 74ff, guest PC 0x0c0afaa4 */
if(!s->budget--) { s->failed_pc=0x0c0afaa4u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0afaa6;
P_0c0afaa6: /* original 34c2, guest PC 0x0c0afaa6 */
if(!s->budget--) { s->failed_pc=0x0c0afaa6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[12])!=0);
goto P_0c0afaa8;
P_0c0afaa8: /* original 8b33, guest PC 0x0c0afaa8 */
if(!s->budget--) { s->failed_pc=0x0c0afaa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afb12; }
goto P_0c0afaaa;
P_0c0afaaa: /* original d307, guest PC 0x0c0afaaa */
if(!s->budget--) { s->failed_pc=0x0c0afaaau; return 0; }
r[3]=read(ram,0x0c0afac8u,4);
goto P_0c0afaac;
P_0c0afaac: /* original 65f2, guest PC 0x0c0afaac */
if(!s->budget--) { s->failed_pc=0x0c0afaacu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0afaae;
P_0c0afaae: /* original 430b, guest PC 0x0c0afaae */
if(!s->budget--) { s->failed_pc=0x0c0afaaeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0afab2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0afab2u) { target=s->pc; goto dispatch; }
goto P_0c0afab2;
P_0c0afab0: /* original 64e3, guest PC 0x0c0afab0 */
if(!s->budget--) { s->failed_pc=0x0c0afab0u; return 0; }
r[4]=r[14];
goto P_0c0afab2;
P_0c0afab2: /* original 9003, guest PC 0x0c0afab2 */
if(!s->budget--) { s->failed_pc=0x0c0afab2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afabcu,2);
goto P_0c0afab4;
P_0c0afab4: /* original a02b, guest PC 0x0c0afab4 */
if(!s->budget--) { s->failed_pc=0x0c0afab4u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c0afb0e;
P_0c0afab6: /* original 0eb5, guest PC 0x0c0afab6 */
if(!s->budget--) { s->failed_pc=0x0c0afab6u; return 0; }
write(ram,r[14]+r[0],r[11],2);
if(!vf3_matrix_family(0x0c0afab8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0afab8u; return 0; } return 1;
P_0c0afaf0: /* original 9034, guest PC 0x0c0afaf0 */
if(!s->budget--) { s->failed_pc=0x0c0afaf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afb5cu,2);
goto P_0c0afaf2;
P_0c0afaf2: /* original e300, guest PC 0x0c0afaf2 */
if(!s->budget--) { s->failed_pc=0x0c0afaf2u; return 0; }
r[3]=0x00000000u;
goto P_0c0afaf4;
P_0c0afaf4: /* original 04ed, guest PC 0x0c0afaf4 */
if(!s->budget--) { s->failed_pc=0x0c0afaf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0afaf6;
P_0c0afaf6: /* original 644d, guest PC 0x0c0afaf6 */
if(!s->budget--) { s->failed_pc=0x0c0afaf6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0afaf8;
P_0c0afaf8: /* original 74ff, guest PC 0x0c0afaf8 */
if(!s->budget--) { s->failed_pc=0x0c0afaf8u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0afafa;
P_0c0afafa: /* original 3436, guest PC 0x0c0afafa */
if(!s->budget--) { s->failed_pc=0x0c0afafau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c0afafc;
P_0c0afafc: /* original 8d01, guest PC 0x0c0afafc */
if(!s->budget--) { s->failed_pc=0x0c0afafcu; return 0; }
cond=r[17]&1u;
r[0]=0x0000003eu;
if(cond) { goto P_0c0afb02; }
goto P_0c0afb00;
P_0c0afafe: /* original e03e, guest PC 0x0c0afafe */
if(!s->budget--) { s->failed_pc=0x0c0afafeu; return 0; }
r[0]=0x0000003eu;
goto P_0c0afb00;
P_0c0afb00: /* original e401, guest PC 0x0c0afb00 */
if(!s->budget--) { s->failed_pc=0x0c0afb00u; return 0; }
r[4]=0x00000001u;
goto P_0c0afb02;
P_0c0afb02: /* original 05ed, guest PC 0x0c0afb02 */
if(!s->budget--) { s->failed_pc=0x0c0afb02u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0afb04;
P_0c0afb04: /* original 655d, guest PC 0x0c0afb04 */
if(!s->budget--) { s->failed_pc=0x0c0afb04u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0afb06;
P_0c0afb06: /* original 3546, guest PC 0x0c0afb06 */
if(!s->budget--) { s->failed_pc=0x0c0afb06u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[4])!=0);
goto P_0c0afb08;
P_0c0afb08: /* original 8b00, guest PC 0x0c0afb08 */
if(!s->budget--) { s->failed_pc=0x0c0afb08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afb0c; }
goto P_0c0afb0a;
P_0c0afb0a: /* original 6543, guest PC 0x0c0afb0a */
if(!s->budget--) { s->failed_pc=0x0c0afb0au; return 0; }
r[5]=r[4];
goto P_0c0afb0c;
P_0c0afb0c: /* original 0e55, guest PC 0x0c0afb0c */
if(!s->budget--) { s->failed_pc=0x0c0afb0cu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0afb0e;
P_0c0afb0e: /* original a001, guest PC 0x0c0afb0e */
if(!s->budget--) { s->failed_pc=0x0c0afb0eu; return 0; }
r[4]=0x00000001u;
goto P_0c0afb14;
P_0c0afb10: /* original e401, guest PC 0x0c0afb10 */
if(!s->budget--) { s->failed_pc=0x0c0afb10u; return 0; }
r[4]=0x00000001u;
goto P_0c0afb12;
P_0c0afb12: /* original e400, guest PC 0x0c0afb12 */
if(!s->budget--) { s->failed_pc=0x0c0afb12u; return 0; }
r[4]=0x00000000u;
goto P_0c0afb14;
P_0c0afb14: /* original 7f08, guest PC 0x0c0afb14 */
if(!s->budget--) { s->failed_pc=0x0c0afb14u; return 0; }
r[15]+=0x00000008u;
goto P_0c0afb16;
P_0c0afb16: /* original 6043, guest PC 0x0c0afb16 */
if(!s->budget--) { s->failed_pc=0x0c0afb16u; return 0; }
r[0]=r[4];
goto P_0c0afb18;
P_0c0afb18: /* original 4f26, guest PC 0x0c0afb18 */
if(!s->budget--) { s->failed_pc=0x0c0afb18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0afb1a;
P_0c0afb1a: /* original 6bf6, guest PC 0x0c0afb1a */
if(!s->budget--) { s->failed_pc=0x0c0afb1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0afb1c;
P_0c0afb1c: /* original 6cf6, guest PC 0x0c0afb1c */
if(!s->budget--) { s->failed_pc=0x0c0afb1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0afb1e;
P_0c0afb1e: /* original 6df6, guest PC 0x0c0afb1e */
if(!s->budget--) { s->failed_pc=0x0c0afb1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0afb20;
P_0c0afb20: /* original 000b, guest PC 0x0c0afb20 */
if(!s->budget--) { s->failed_pc=0x0c0afb20u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0afb22: /* original 6ef6, guest PC 0x0c0afb22 */
if(!s->budget--) { s->failed_pc=0x0c0afb22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0afb24u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0afb24u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
