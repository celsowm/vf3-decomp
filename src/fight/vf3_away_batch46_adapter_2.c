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
int vf3_away_batch46_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0806cau: goto P_0c0806ca;
case 0x0c0806ccu: goto P_0c0806cc;
case 0x0c0806ceu: goto P_0c0806ce;
case 0x0c0806d0u: goto P_0c0806d0;
case 0x0c0806d2u: goto P_0c0806d2;
case 0x0c0806d4u: goto P_0c0806d4;
case 0x0c0806d6u: goto P_0c0806d6;
case 0x0c0806d8u: goto P_0c0806d8;
case 0x0c0806dau: goto P_0c0806da;
case 0x0c0806dcu: goto P_0c0806dc;
case 0x0c0806deu: goto P_0c0806de;
case 0x0c0806e0u: goto P_0c0806e0;
case 0x0c0806e2u: goto P_0c0806e2;
case 0x0c0806e4u: goto P_0c0806e4;
case 0x0c0806e6u: goto P_0c0806e6;
case 0x0c0806e8u: goto P_0c0806e8;
case 0x0c0806eau: goto P_0c0806ea;
case 0x0c0806ecu: goto P_0c0806ec;
case 0x0c0806eeu: goto P_0c0806ee;
case 0x0c0806f0u: goto P_0c0806f0;
case 0x0c0806f2u: goto P_0c0806f2;
case 0x0c0806f4u: goto P_0c0806f4;
case 0x0c0806f6u: goto P_0c0806f6;
case 0x0c0806f8u: goto P_0c0806f8;
case 0x0c0806fau: goto P_0c0806fa;
case 0x0c0806fcu: goto P_0c0806fc;
case 0x0c0806feu: goto P_0c0806fe;
case 0x0c080700u: goto P_0c080700;
case 0x0c080702u: goto P_0c080702;
case 0x0c080704u: goto P_0c080704;
case 0x0c080706u: goto P_0c080706;
case 0x0c080708u: goto P_0c080708;
case 0x0c08070au: goto P_0c08070a;
case 0x0c08070cu: goto P_0c08070c;
case 0x0c08070eu: goto P_0c08070e;
case 0x0c080710u: goto P_0c080710;
case 0x0c080712u: goto P_0c080712;
case 0x0c080714u: goto P_0c080714;
case 0x0c080716u: goto P_0c080716;
case 0x0c080718u: goto P_0c080718;
case 0x0c08071au: goto P_0c08071a;
case 0x0c08071cu: goto P_0c08071c;
case 0x0c08071eu: goto P_0c08071e;
case 0x0c080720u: goto P_0c080720;
case 0x0c080722u: goto P_0c080722;
case 0x0c080724u: goto P_0c080724;
case 0x0c080726u: goto P_0c080726;
case 0x0c080728u: goto P_0c080728;
case 0x0c08072au: goto P_0c08072a;
case 0x0c08072cu: goto P_0c08072c;
case 0x0c08072eu: goto P_0c08072e;
case 0x0c080730u: goto P_0c080730;
case 0x0c080732u: goto P_0c080732;
case 0x0c080734u: goto P_0c080734;
case 0x0c080736u: goto P_0c080736;
case 0x0c080738u: goto P_0c080738;
case 0x0c08073au: goto P_0c08073a;
case 0x0c08073cu: goto P_0c08073c;
case 0x0c08073eu: goto P_0c08073e;
case 0x0c080740u: goto P_0c080740;
case 0x0c080742u: goto P_0c080742;
case 0x0c080744u: goto P_0c080744;
case 0x0c080746u: goto P_0c080746;
case 0x0c080748u: goto P_0c080748;
case 0x0c08074au: goto P_0c08074a;
case 0x0c08074cu: goto P_0c08074c;
case 0x0c08074eu: goto P_0c08074e;
case 0x0c080750u: goto P_0c080750;
case 0x0c080752u: goto P_0c080752;
case 0x0c080754u: goto P_0c080754;
case 0x0c080756u: goto P_0c080756;
case 0x0c080758u: goto P_0c080758;
case 0x0c08075au: goto P_0c08075a;
case 0x0c08075cu: goto P_0c08075c;
case 0x0c08075eu: goto P_0c08075e;
case 0x0c080760u: goto P_0c080760;
case 0x0c080762u: goto P_0c080762;
case 0x0c080764u: goto P_0c080764;
case 0x0c080766u: goto P_0c080766;
case 0x0c080768u: goto P_0c080768;
case 0x0c08076au: goto P_0c08076a;
case 0x0c080920u: goto P_0c080920;
case 0x0c080922u: goto P_0c080922;
case 0x0c080924u: goto P_0c080924;
case 0x0c080926u: goto P_0c080926;
case 0x0c080928u: goto P_0c080928;
case 0x0c08092au: goto P_0c08092a;
case 0x0c08092cu: goto P_0c08092c;
case 0x0c08092eu: goto P_0c08092e;
case 0x0c080930u: goto P_0c080930;
case 0x0c080932u: goto P_0c080932;
case 0x0c080934u: goto P_0c080934;
case 0x0c080936u: goto P_0c080936;
case 0x0c080938u: goto P_0c080938;
case 0x0c08093au: goto P_0c08093a;
case 0x0c08093cu: goto P_0c08093c;
case 0x0c08093eu: goto P_0c08093e;
case 0x0c080940u: goto P_0c080940;
case 0x0c080942u: goto P_0c080942;
case 0x0c080944u: goto P_0c080944;
case 0x0c080946u: goto P_0c080946;
case 0x0c080948u: goto P_0c080948;
case 0x0c08094au: goto P_0c08094a;
case 0x0c08094cu: goto P_0c08094c;
case 0x0c08094eu: goto P_0c08094e;
case 0x0c080950u: goto P_0c080950;
case 0x0c080952u: goto P_0c080952;
case 0x0c080954u: goto P_0c080954;
case 0x0c080956u: goto P_0c080956;
case 0x0c080958u: goto P_0c080958;
case 0x0c08095au: goto P_0c08095a;
case 0x0c08095cu: goto P_0c08095c;
case 0x0c08095eu: goto P_0c08095e;
case 0x0c080960u: goto P_0c080960;
case 0x0c080962u: goto P_0c080962;
case 0x0c080964u: goto P_0c080964;
case 0x0c080966u: goto P_0c080966;
case 0x0c080968u: goto P_0c080968;
case 0x0c08096au: goto P_0c08096a;
case 0x0c08096cu: goto P_0c08096c;
case 0x0c08096eu: goto P_0c08096e;
case 0x0c080970u: goto P_0c080970;
case 0x0c080972u: goto P_0c080972;
case 0x0c080974u: goto P_0c080974;
case 0x0c080976u: goto P_0c080976;
case 0x0c080978u: goto P_0c080978;
case 0x0c08097au: goto P_0c08097a;
case 0x0c08097cu: goto P_0c08097c;
case 0x0c08097eu: goto P_0c08097e;
case 0x0c080980u: goto P_0c080980;
case 0x0c080982u: goto P_0c080982;
case 0x0c080984u: goto P_0c080984;
case 0x0c080986u: goto P_0c080986;
case 0x0c080988u: goto P_0c080988;
case 0x0c08098au: goto P_0c08098a;
case 0x0c08098cu: goto P_0c08098c;
case 0x0c08098eu: goto P_0c08098e;
case 0x0c080990u: goto P_0c080990;
case 0x0c080992u: goto P_0c080992;
case 0x0c080994u: goto P_0c080994;
case 0x0c080996u: goto P_0c080996;
case 0x0c080998u: goto P_0c080998;
case 0x0c08099au: goto P_0c08099a;
case 0x0c08099cu: goto P_0c08099c;
case 0x0c08099eu: goto P_0c08099e;
case 0x0c0809a0u: goto P_0c0809a0;
case 0x0c0809a2u: goto P_0c0809a2;
case 0x0c0809a4u: goto P_0c0809a4;
case 0x0c0809a6u: goto P_0c0809a6;
case 0x0c0809a8u: goto P_0c0809a8;
case 0x0c0809aau: goto P_0c0809aa;
case 0x0c0809acu: goto P_0c0809ac;
case 0x0c0809aeu: goto P_0c0809ae;
case 0x0c0809b0u: goto P_0c0809b0;
case 0x0c0809b2u: goto P_0c0809b2;
case 0x0c0809b4u: goto P_0c0809b4;
case 0x0c0809b6u: goto P_0c0809b6;
case 0x0c0809b8u: goto P_0c0809b8;
case 0x0c0809bau: goto P_0c0809ba;
case 0x0c0809bcu: goto P_0c0809bc;
case 0x0c0809beu: goto P_0c0809be;
case 0x0c0809c0u: goto P_0c0809c0;
case 0x0c0809c2u: goto P_0c0809c2;
case 0x0c0809c4u: goto P_0c0809c4;
case 0x0c0809c6u: goto P_0c0809c6;
case 0x0c0809c8u: goto P_0c0809c8;
case 0x0c0809cau: goto P_0c0809ca;
case 0x0c0809ccu: goto P_0c0809cc;
case 0x0c0809ceu: goto P_0c0809ce;
case 0x0c0809d0u: goto P_0c0809d0;
case 0x0c0809d2u: goto P_0c0809d2;
case 0x0c0809d4u: goto P_0c0809d4;
case 0x0c0809d6u: goto P_0c0809d6;
case 0x0c0809d8u: goto P_0c0809d8;
case 0x0c0809dau: goto P_0c0809da;
case 0x0c0809dcu: goto P_0c0809dc;
case 0x0c0809deu: goto P_0c0809de;
case 0x0c0809e0u: goto P_0c0809e0;
case 0x0c0809e2u: goto P_0c0809e2;
case 0x0c0809e4u: goto P_0c0809e4;
case 0x0c0809e6u: goto P_0c0809e6;
case 0x0c0809e8u: goto P_0c0809e8;
case 0x0c0809eau: goto P_0c0809ea;
case 0x0c0809ecu: goto P_0c0809ec;
case 0x0c0809eeu: goto P_0c0809ee;
case 0x0c0809f0u: goto P_0c0809f0;
case 0x0c0809f2u: goto P_0c0809f2;
case 0x0c0809f4u: goto P_0c0809f4;
case 0x0c0809f6u: goto P_0c0809f6;
case 0x0c0809f8u: goto P_0c0809f8;
case 0x0c0809fau: goto P_0c0809fa;
case 0x0c0809fcu: goto P_0c0809fc;
case 0x0c0809feu: goto P_0c0809fe;
case 0x0c080a00u: goto P_0c080a00;
case 0x0c080a02u: goto P_0c080a02;
case 0x0c080a04u: goto P_0c080a04;
case 0x0c080a06u: goto P_0c080a06;
case 0x0c080a08u: goto P_0c080a08;
case 0x0c080a0au: goto P_0c080a0a;
case 0x0c080a0cu: goto P_0c080a0c;
case 0x0c080a0eu: goto P_0c080a0e;
case 0x0c080a10u: goto P_0c080a10;
case 0x0c080a12u: goto P_0c080a12;
case 0x0c080a14u: goto P_0c080a14;
case 0x0c080a16u: goto P_0c080a16;
case 0x0c080a18u: goto P_0c080a18;
case 0x0c080a1au: goto P_0c080a1a;
case 0x0c080a1cu: goto P_0c080a1c;
case 0x0c080a1eu: goto P_0c080a1e;
case 0x0c080a20u: goto P_0c080a20;
case 0x0c080a22u: goto P_0c080a22;
case 0x0c080a24u: goto P_0c080a24;
case 0x0c080a26u: goto P_0c080a26;
case 0x0c080a28u: goto P_0c080a28;
case 0x0c080a2au: goto P_0c080a2a;
case 0x0c080a2cu: goto P_0c080a2c;
case 0x0c080a2eu: goto P_0c080a2e;
case 0x0c080a30u: goto P_0c080a30;
case 0x0c080a32u: goto P_0c080a32;
case 0x0c080a34u: goto P_0c080a34;
case 0x0c080a36u: goto P_0c080a36;
case 0x0c080a38u: goto P_0c080a38;
case 0x0c080a3au: goto P_0c080a3a;
case 0x0c080a3cu: goto P_0c080a3c;
case 0x0c080a3eu: goto P_0c080a3e;
case 0x0c080a40u: goto P_0c080a40;
case 0x0c080a42u: goto P_0c080a42;
case 0x0c080a44u: goto P_0c080a44;
case 0x0c080a46u: goto P_0c080a46;
case 0x0c080a48u: goto P_0c080a48;
case 0x0c080a4au: goto P_0c080a4a;
case 0x0c080a4cu: goto P_0c080a4c;
case 0x0c080a4eu: goto P_0c080a4e;
case 0x0c080a50u: goto P_0c080a50;
case 0x0c080a52u: goto P_0c080a52;
case 0x0c080a54u: goto P_0c080a54;
case 0x0c080a74u: goto P_0c080a74;
case 0x0c080a76u: goto P_0c080a76;
case 0x0c080a78u: goto P_0c080a78;
case 0x0c080a7au: goto P_0c080a7a;
case 0x0c080a7cu: goto P_0c080a7c;
case 0x0c080a7eu: goto P_0c080a7e;
case 0x0c080a80u: goto P_0c080a80;
case 0x0c080a82u: goto P_0c080a82;
case 0x0c080a84u: goto P_0c080a84;
case 0x0c080a86u: goto P_0c080a86;
case 0x0c080a88u: goto P_0c080a88;
case 0x0c080a8au: goto P_0c080a8a;
case 0x0c080a8cu: goto P_0c080a8c;
case 0x0c080a8eu: goto P_0c080a8e;
case 0x0c080a90u: goto P_0c080a90;
case 0x0c080a92u: goto P_0c080a92;
case 0x0c080a94u: goto P_0c080a94;
case 0x0c080a96u: goto P_0c080a96;
case 0x0c080a98u: goto P_0c080a98;
case 0x0c080a9au: goto P_0c080a9a;
case 0x0c080a9cu: goto P_0c080a9c;
case 0x0c080a9eu: goto P_0c080a9e;
case 0x0c080aa0u: goto P_0c080aa0;
case 0x0c080aa2u: goto P_0c080aa2;
case 0x0c080aa4u: goto P_0c080aa4;
case 0x0c080aa6u: goto P_0c080aa6;
case 0x0c080aa8u: goto P_0c080aa8;
case 0x0c080aaau: goto P_0c080aaa;
case 0x0c080aacu: goto P_0c080aac;
case 0x0c080aaeu: goto P_0c080aae;
case 0x0c080ab0u: goto P_0c080ab0;
case 0x0c080ab2u: goto P_0c080ab2;
case 0x0c080ab4u: goto P_0c080ab4;
case 0x0c080ab6u: goto P_0c080ab6;
case 0x0c080ab8u: goto P_0c080ab8;
case 0x0c080abau: goto P_0c080aba;
case 0x0c080abcu: goto P_0c080abc;
case 0x0c080abeu: goto P_0c080abe;
case 0x0c080ac0u: goto P_0c080ac0;
case 0x0c080ac2u: goto P_0c080ac2;
case 0x0c080ac4u: goto P_0c080ac4;
case 0x0c080ac6u: goto P_0c080ac6;
case 0x0c080ac8u: goto P_0c080ac8;
case 0x0c080acau: goto P_0c080aca;
case 0x0c080accu: goto P_0c080acc;
case 0x0c080aceu: goto P_0c080ace;
case 0x0c080ad0u: goto P_0c080ad0;
case 0x0c080ad2u: goto P_0c080ad2;
case 0x0c080ad4u: goto P_0c080ad4;
case 0x0c080ad6u: goto P_0c080ad6;
case 0x0c080ad8u: goto P_0c080ad8;
case 0x0c080adau: goto P_0c080ada;
case 0x0c080adcu: goto P_0c080adc;
case 0x0c080adeu: goto P_0c080ade;
case 0x0c080ae0u: goto P_0c080ae0;
case 0x0c080ae2u: goto P_0c080ae2;
case 0x0c080ae4u: goto P_0c080ae4;
case 0x0c080ae6u: goto P_0c080ae6;
case 0x0c080ae8u: goto P_0c080ae8;
case 0x0c080aeau: goto P_0c080aea;
case 0x0c080aecu: goto P_0c080aec;
case 0x0c080aeeu: goto P_0c080aee;
case 0x0c080af0u: goto P_0c080af0;
case 0x0c080af2u: goto P_0c080af2;
case 0x0c080af4u: goto P_0c080af4;
case 0x0c080af6u: goto P_0c080af6;
case 0x0c080af8u: goto P_0c080af8;
case 0x0c080afau: goto P_0c080afa;
case 0x0c080afcu: goto P_0c080afc;
case 0x0c080afeu: goto P_0c080afe;
case 0x0c080b00u: goto P_0c080b00;
case 0x0c080b02u: goto P_0c080b02;
case 0x0c080b04u: goto P_0c080b04;
case 0x0c080b06u: goto P_0c080b06;
case 0x0c080b08u: goto P_0c080b08;
case 0x0c080b0au: goto P_0c080b0a;
case 0x0c080b0cu: goto P_0c080b0c;
case 0x0c080b0eu: goto P_0c080b0e;
case 0x0c080b10u: goto P_0c080b10;
case 0x0c080b12u: goto P_0c080b12;
case 0x0c080b14u: goto P_0c080b14;
case 0x0c080b16u: goto P_0c080b16;
case 0x0c080b18u: goto P_0c080b18;
case 0x0c080b1au: goto P_0c080b1a;
case 0x0c080b1cu: goto P_0c080b1c;
case 0x0c080b1eu: goto P_0c080b1e;
case 0x0c080b20u: goto P_0c080b20;
case 0x0c080b22u: goto P_0c080b22;
case 0x0c080b24u: goto P_0c080b24;
case 0x0c080b26u: goto P_0c080b26;
case 0x0c080b28u: goto P_0c080b28;
case 0x0c080b2au: goto P_0c080b2a;
case 0x0c080b2cu: goto P_0c080b2c;
case 0x0c080b2eu: goto P_0c080b2e;
case 0x0c080b30u: goto P_0c080b30;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0806ca: /* original 2fe6, guest PC 0x0c0806ca */
if(!s->budget--) { s->failed_pc=0x0c0806cau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0806cc;
P_0c0806cc: /* original 7414, guest PC 0x0c0806cc */
if(!s->budget--) { s->failed_pc=0x0c0806ccu; return 0; }
r[4]+=0x00000014u;
goto P_0c0806ce;
P_0c0806ce: /* original 2fd6, guest PC 0x0c0806ce */
if(!s->budget--) { s->failed_pc=0x0c0806ceu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0806d0;
P_0c0806d0: /* original e207, guest PC 0x0c0806d0 */
if(!s->budget--) { s->failed_pc=0x0c0806d0u; return 0; }
r[2]=0x00000007u;
goto P_0c0806d2;
P_0c0806d2: /* original 2fc6, guest PC 0x0c0806d2 */
if(!s->budget--) { s->failed_pc=0x0c0806d2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0806d4;
P_0c0806d4: /* original 2fb6, guest PC 0x0c0806d4 */
if(!s->budget--) { s->failed_pc=0x0c0806d4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0806d6;
P_0c0806d6: /* original 2fa6, guest PC 0x0c0806d6 */
if(!s->budget--) { s->failed_pc=0x0c0806d6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0806d8;
P_0c0806d8: /* original 2f96, guest PC 0x0c0806d8 */
if(!s->budget--) { s->failed_pc=0x0c0806d8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0806da;
P_0c0806da: /* original e900, guest PC 0x0c0806da */
if(!s->budget--) { s->failed_pc=0x0c0806dau; return 0; }
r[9]=0x00000000u;
goto P_0c0806dc;
P_0c0806dc: /* original 6e41, guest PC 0x0c0806dc */
if(!s->budget--) { s->failed_pc=0x0c0806dcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[14]=tmp;
goto P_0c0806de;
P_0c0806de: /* original 6793, guest PC 0x0c0806de */
if(!s->budget--) { s->failed_pc=0x0c0806deu; return 0; }
r[7]=r[9];
goto P_0c0806e0;
P_0c0806e0: /* original 8541, guest PC 0x0c0806e0 */
if(!s->budget--) { s->failed_pc=0x0c0806e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c0806e2;
P_0c0806e2: /* original 6eed, guest PC 0x0c0806e2 */
if(!s->budget--) { s->failed_pc=0x0c0806e2u; return 0; }
r[14]=r[14]&65535u;
goto P_0c0806e4;
P_0c0806e4: /* original 4f22, guest PC 0x0c0806e4 */
if(!s->budget--) { s->failed_pc=0x0c0806e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0806e6;
P_0c0806e6: /* original 6c0d, guest PC 0x0c0806e6 */
if(!s->budget--) { s->failed_pc=0x0c0806e6u; return 0; }
r[12]=r[0]&65535u;
goto P_0c0806e8;
P_0c0806e8: /* original 63e3, guest PC 0x0c0806e8 */
if(!s->budget--) { s->failed_pc=0x0c0806e8u; return 0; }
r[3]=r[14];
goto P_0c0806ea;
P_0c0806ea: /* original 4300, guest PC 0x0c0806ea */
if(!s->budget--) { s->failed_pc=0x0c0806eau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0806ec;
P_0c0806ec: /* original 8542, guest PC 0x0c0806ec */
if(!s->budget--) { s->failed_pc=0x0c0806ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c0806ee;
P_0c0806ee: /* original 4c2d, guest PC 0x0c0806ee */
if(!s->budget--) { s->failed_pc=0x0c0806eeu; return 0; }
r[12]=(r[2]&0x80000000u)?((r[2]&31u)?r[12]>>((-r[2])&31u):0):r[12]<<(r[2]&31u);
goto P_0c0806f0;
P_0c0806f0: /* original 23cb, guest PC 0x0c0806f0 */
if(!s->budget--) { s->failed_pc=0x0c0806f0u; return 0; }
r[3]|=r[12];
goto P_0c0806f2;
P_0c0806f2: /* original 7ffc, guest PC 0x0c0806f2 */
if(!s->budget--) { s->failed_pc=0x0c0806f2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0806f4;
P_0c0806f4: /* original 6d0d, guest PC 0x0c0806f4 */
if(!s->budget--) { s->failed_pc=0x0c0806f4u; return 0; }
r[13]=r[0]&65535u;
goto P_0c0806f6;
P_0c0806f6: /* original 2f32, guest PC 0x0c0806f6 */
if(!s->budget--) { s->failed_pc=0x0c0806f6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0806f8;
P_0c0806f8: /* original db22, guest PC 0x0c0806f8 */
if(!s->budget--) { s->failed_pc=0x0c0806f8u; return 0; }
r[11]=read(ram,0x0c080784u,4);
goto P_0c0806fa;
P_0c0806fa: /* original 65d3, guest PC 0x0c0806fa */
if(!s->budget--) { s->failed_pc=0x0c0806fau; return 0; }
r[5]=r[13];
goto P_0c0806fc;
P_0c0806fc: /* original da23, guest PC 0x0c0806fc */
if(!s->budget--) { s->failed_pc=0x0c0806fcu; return 0; }
r[10]=read(ram,0x0c08078cu,4);
goto P_0c0806fe;
P_0c0806fe: /* original 66b3, guest PC 0x0c0806fe */
if(!s->budget--) { s->failed_pc=0x0c0806feu; return 0; }
r[6]=r[11];
goto P_0c080700;
P_0c080700: /* original 2f96, guest PC 0x0c080700 */
if(!s->budget--) { s->failed_pc=0x0c080700u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080702;
P_0c080702: /* original 4a0b, guest PC 0x0c080702 */
if(!s->budget--) { s->failed_pc=0x0c080702u; return 0; }
target=r[10];
r[16]=code_base|0x0c080706u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080706u) { target=s->pc; goto dispatch; }
goto P_0c080706;
P_0c080704: /* original 54f1, guest PC 0x0c080704 */
if(!s->budget--) { s->failed_pc=0x0c080704u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c080706;
P_0c080706: /* original 9334, guest PC 0x0c080706 */
if(!s->budget--) { s->failed_pc=0x0c080706u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080772u,2);
goto P_0c080708;
P_0c080708: /* original 3d30, guest PC 0x0c080708 */
if(!s->budget--) { s->failed_pc=0x0c080708u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c08070a;
P_0c08070a: /* original 8f09, guest PC 0x0c08070a */
if(!s->budget--) { s->failed_pc=0x0c08070au; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c080720; }
goto P_0c08070e;
P_0c08070c: /* original 7f04, guest PC 0x0c08070c */
if(!s->budget--) { s->failed_pc=0x0c08070cu; return 0; }
r[15]+=0x00000004u;
goto P_0c08070e;
P_0c08070e: /* original 7e0d, guest PC 0x0c08070e */
if(!s->budget--) { s->failed_pc=0x0c08070eu; return 0; }
r[14]+=0x0000000du;
goto P_0c080710;
P_0c080710: /* original 4e00, guest PC 0x0c080710 */
if(!s->budget--) { s->failed_pc=0x0c080710u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c080712;
P_0c080712: /* original 2ecb, guest PC 0x0c080712 */
if(!s->budget--) { s->failed_pc=0x0c080712u; return 0; }
r[14]|=r[12];
goto P_0c080714;
P_0c080714: /* original 2fe2, guest PC 0x0c080714 */
if(!s->budget--) { s->failed_pc=0x0c080714u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c080716;
P_0c080716: /* original e700, guest PC 0x0c080716 */
if(!s->budget--) { s->failed_pc=0x0c080716u; return 0; }
r[7]=0x00000000u;
goto P_0c080718;
P_0c080718: /* original 2f96, guest PC 0x0c080718 */
if(!s->budget--) { s->failed_pc=0x0c080718u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08071a;
P_0c08071a: /* original 952b, guest PC 0x0c08071a */
if(!s->budget--) { s->failed_pc=0x0c08071au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080774u,2);
goto P_0c08071c;
P_0c08071c: /* original a00b, guest PC 0x0c08071c */
if(!s->budget--) { s->failed_pc=0x0c08071cu; return 0; }
r[6]=r[11];
goto P_0c080736;
P_0c08071e: /* original 66b3, guest PC 0x0c08071e */
if(!s->budget--) { s->failed_pc=0x0c08071eu; return 0; }
r[6]=r[11];
goto P_0c080720;
P_0c080720: /* original 9229, guest PC 0x0c080720 */
if(!s->budget--) { s->failed_pc=0x0c080720u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080776u,2);
goto P_0c080722;
P_0c080722: /* original 3d20, guest PC 0x0c080722 */
if(!s->budget--) { s->failed_pc=0x0c080722u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c080724;
P_0c080724: /* original 8b0b, guest PC 0x0c080724 */
if(!s->budget--) { s->failed_pc=0x0c080724u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08073e; }
goto P_0c080726;
P_0c080726: /* original 7e0c, guest PC 0x0c080726 */
if(!s->budget--) { s->failed_pc=0x0c080726u; return 0; }
r[14]+=0x0000000cu;
goto P_0c080728;
P_0c080728: /* original 66b3, guest PC 0x0c080728 */
if(!s->budget--) { s->failed_pc=0x0c080728u; return 0; }
r[6]=r[11];
goto P_0c08072a;
P_0c08072a: /* original 4e00, guest PC 0x0c08072a */
if(!s->budget--) { s->failed_pc=0x0c08072au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c08072c;
P_0c08072c: /* original 2ecb, guest PC 0x0c08072c */
if(!s->budget--) { s->failed_pc=0x0c08072cu; return 0; }
r[14]|=r[12];
goto P_0c08072e;
P_0c08072e: /* original 2fe2, guest PC 0x0c08072e */
if(!s->budget--) { s->failed_pc=0x0c08072eu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c080730;
P_0c080730: /* original e700, guest PC 0x0c080730 */
if(!s->budget--) { s->failed_pc=0x0c080730u; return 0; }
r[7]=0x00000000u;
goto P_0c080732;
P_0c080732: /* original 2f96, guest PC 0x0c080732 */
if(!s->budget--) { s->failed_pc=0x0c080732u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080734;
P_0c080734: /* original 9520, guest PC 0x0c080734 */
if(!s->budget--) { s->failed_pc=0x0c080734u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080778u,2);
goto P_0c080736;
P_0c080736: /* original 4a0b, guest PC 0x0c080736 */
if(!s->budget--) { s->failed_pc=0x0c080736u; return 0; }
target=r[10];
r[16]=code_base|0x0c08073au;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08073au) { target=s->pc; goto dispatch; }
goto P_0c08073a;
P_0c080738: /* original 54f1, guest PC 0x0c080738 */
if(!s->budget--) { s->failed_pc=0x0c080738u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c08073a;
P_0c08073a: /* original a00e, guest PC 0x0c08073a */
if(!s->budget--) { s->failed_pc=0x0c08073au; return 0; }
r[15]+=0x00000004u;
goto P_0c08075a;
P_0c08073c: /* original 7f04, guest PC 0x0c08073c */
if(!s->budget--) { s->failed_pc=0x0c08073cu; return 0; }
r[15]+=0x00000004u;
goto P_0c08073e;
P_0c08073e: /* original 911c, guest PC 0x0c08073e */
if(!s->budget--) { s->failed_pc=0x0c08073eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08077au,2);
goto P_0c080740;
P_0c080740: /* original 3d10, guest PC 0x0c080740 */
if(!s->budget--) { s->failed_pc=0x0c080740u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c080742;
P_0c080742: /* original 8b0a, guest PC 0x0c080742 */
if(!s->budget--) { s->failed_pc=0x0c080742u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08075a; }
goto P_0c080744;
P_0c080744: /* original 7e0c, guest PC 0x0c080744 */
if(!s->budget--) { s->failed_pc=0x0c080744u; return 0; }
r[14]+=0x0000000cu;
goto P_0c080746;
P_0c080746: /* original 66b3, guest PC 0x0c080746 */
if(!s->budget--) { s->failed_pc=0x0c080746u; return 0; }
r[6]=r[11];
goto P_0c080748;
P_0c080748: /* original 4e00, guest PC 0x0c080748 */
if(!s->budget--) { s->failed_pc=0x0c080748u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c08074a;
P_0c08074a: /* original 2ecb, guest PC 0x0c08074a */
if(!s->budget--) { s->failed_pc=0x0c08074au; return 0; }
r[14]|=r[12];
goto P_0c08074c;
P_0c08074c: /* original 2fe2, guest PC 0x0c08074c */
if(!s->budget--) { s->failed_pc=0x0c08074cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08074e;
P_0c08074e: /* original e700, guest PC 0x0c08074e */
if(!s->budget--) { s->failed_pc=0x0c08074eu; return 0; }
r[7]=0x00000000u;
goto P_0c080750;
P_0c080750: /* original 2f96, guest PC 0x0c080750 */
if(!s->budget--) { s->failed_pc=0x0c080750u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080752;
P_0c080752: /* original 9513, guest PC 0x0c080752 */
if(!s->budget--) { s->failed_pc=0x0c080752u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08077cu,2);
goto P_0c080754;
P_0c080754: /* original 4a0b, guest PC 0x0c080754 */
if(!s->budget--) { s->failed_pc=0x0c080754u; return 0; }
target=r[10];
r[16]=code_base|0x0c080758u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080758u) { target=s->pc; goto dispatch; }
goto P_0c080758;
P_0c080756: /* original 54f1, guest PC 0x0c080756 */
if(!s->budget--) { s->failed_pc=0x0c080756u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c080758;
P_0c080758: /* original 7f04, guest PC 0x0c080758 */
if(!s->budget--) { s->failed_pc=0x0c080758u; return 0; }
r[15]+=0x00000004u;
goto P_0c08075a;
P_0c08075a: /* original 7f04, guest PC 0x0c08075a */
if(!s->budget--) { s->failed_pc=0x0c08075au; return 0; }
r[15]+=0x00000004u;
goto P_0c08075c;
P_0c08075c: /* original 4f26, guest PC 0x0c08075c */
if(!s->budget--) { s->failed_pc=0x0c08075cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08075e;
P_0c08075e: /* original 69f6, guest PC 0x0c08075e */
if(!s->budget--) { s->failed_pc=0x0c08075eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c080760;
P_0c080760: /* original 6af6, guest PC 0x0c080760 */
if(!s->budget--) { s->failed_pc=0x0c080760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c080762;
P_0c080762: /* original 6bf6, guest PC 0x0c080762 */
if(!s->budget--) { s->failed_pc=0x0c080762u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c080764;
P_0c080764: /* original 6cf6, guest PC 0x0c080764 */
if(!s->budget--) { s->failed_pc=0x0c080764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080766;
P_0c080766: /* original 6df6, guest PC 0x0c080766 */
if(!s->budget--) { s->failed_pc=0x0c080766u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080768;
P_0c080768: /* original 000b, guest PC 0x0c080768 */
if(!s->budget--) { s->failed_pc=0x0c080768u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08076a: /* original 6ef6, guest PC 0x0c08076a */
if(!s->budget--) { s->failed_pc=0x0c08076au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08076cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08076cu; return 0; } return 1;
P_0c080920: /* original 2fe6, guest PC 0x0c080920 */
if(!s->budget--) { s->failed_pc=0x0c080920u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080922;
P_0c080922: /* original 2fd6, guest PC 0x0c080922 */
if(!s->budget--) { s->failed_pc=0x0c080922u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080924;
P_0c080924: /* original 2fc6, guest PC 0x0c080924 */
if(!s->budget--) { s->failed_pc=0x0c080924u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080926;
P_0c080926: /* original 2fb6, guest PC 0x0c080926 */
if(!s->budget--) { s->failed_pc=0x0c080926u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080928;
P_0c080928: /* original 2fa6, guest PC 0x0c080928 */
if(!s->budget--) { s->failed_pc=0x0c080928u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092a;
P_0c08092a: /* original 2f96, guest PC 0x0c08092a */
if(!s->budget--) { s->failed_pc=0x0c08092au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092c;
P_0c08092c: /* original 2f86, guest PC 0x0c08092c */
if(!s->budget--) { s->failed_pc=0x0c08092cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092e;
P_0c08092e: /* original d44d, guest PC 0x0c08092e */
if(!s->budget--) { s->failed_pc=0x0c08092eu; return 0; }
r[4]=read(ram,0x0c080a64u,4);
goto P_0c080930;
P_0c080930: /* original 4f22, guest PC 0x0c080930 */
if(!s->budget--) { s->failed_pc=0x0c080930u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080932;
P_0c080932: /* original d54a, guest PC 0x0c080932 */
if(!s->budget--) { s->failed_pc=0x0c080932u; return 0; }
r[5]=read(ram,0x0c080a5cu,4);
goto P_0c080934;
P_0c080934: /* original 5344, guest PC 0x0c080934 */
if(!s->budget--) { s->failed_pc=0x0c080934u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c080936;
P_0c080936: /* original 6d53, guest PC 0x0c080936 */
if(!s->budget--) { s->failed_pc=0x0c080936u; return 0; }
r[13]=r[5];
goto P_0c080938;
P_0c080938: /* original 7fe0, guest PC 0x0c080938 */
if(!s->budget--) { s->failed_pc=0x0c080938u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c08093a;
P_0c08093a: /* original dc49, guest PC 0x0c08093a */
if(!s->budget--) { s->failed_pc=0x0c08093au; return 0; }
r[12]=read(ram,0x0c080a60u,4);
goto P_0c08093c;
P_0c08093c: /* original 1f37, guest PC 0x0c08093c */
if(!s->budget--) { s->failed_pc=0x0c08093cu; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c08093e;
P_0c08093e: /* original e304, guest PC 0x0c08093e */
if(!s->budget--) { s->failed_pc=0x0c08093eu; return 0; }
r[3]=0x00000004u;
goto P_0c080940;
P_0c080940: /* original 5245, guest PC 0x0c080940 */
if(!s->budget--) { s->failed_pc=0x0c080940u; return 0; }
r[2]=read(ram,r[4]+20,4);
goto P_0c080942;
P_0c080942: /* original 1f26, guest PC 0x0c080942 */
if(!s->budget--) { s->failed_pc=0x0c080942u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c080944;
P_0c080944: /* original 54d2, guest PC 0x0c080944 */
if(!s->budget--) { s->failed_pc=0x0c080944u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c080946;
P_0c080946: /* original da49, guest PC 0x0c080946 */
if(!s->budget--) { s->failed_pc=0x0c080946u; return 0; }
r[10]=read(ram,0x0c080a6cu,4);
goto P_0c080948;
P_0c080948: /* original db49, guest PC 0x0c080948 */
if(!s->budget--) { s->failed_pc=0x0c080948u; return 0; }
r[11]=read(ram,0x0c080a70u,4);
goto P_0c08094a;
P_0c08094a: /* original 2438, guest PC 0x0c08094a */
if(!s->budget--) { s->failed_pc=0x0c08094au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08094c;
P_0c08094c: /* original d946, guest PC 0x0c08094c */
if(!s->budget--) { s->failed_pc=0x0c08094cu; return 0; }
r[9]=read(ram,0x0c080a68u,4);
goto P_0c08094e;
P_0c08094e: /* original 8f02, guest PC 0x0c08094e */
if(!s->budget--) { s->failed_pc=0x0c08094eu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c080956; }
goto P_0c080952;
P_0c080950: /* original ee00, guest PC 0x0c080950 */
if(!s->budget--) { s->failed_pc=0x0c080950u; return 0; }
r[14]=0x00000000u;
goto P_0c080952;
P_0c080952: /* original a08f, guest PC 0x0c080952 */
if(!s->budget--) { s->failed_pc=0x0c080952u; return 0; }
goto P_0c080a74;
P_0c080954: /* original 0009, guest PC 0x0c080954 */
if(!s->budget--) { s->failed_pc=0x0c080954u; return 0; }
goto P_0c080956;
P_0c080956: /* original 907e, guest PC 0x0c080956 */
if(!s->budget--) { s->failed_pc=0x0c080956u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a56u,2);
goto P_0c080958;
P_0c080958: /* original 68e3, guest PC 0x0c080958 */
if(!s->budget--) { s->failed_pc=0x0c080958u; return 0; }
r[8]=r[14];
goto P_0c08095a;
P_0c08095a: /* original 04dc, guest PC 0x0c08095a */
if(!s->budget--) { s->failed_pc=0x0c08095au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08095c;
P_0c08095c: /* original e01b, guest PC 0x0c08095c */
if(!s->budget--) { s->failed_pc=0x0c08095cu; return 0; }
r[0]=0x0000001bu;
goto P_0c08095e;
P_0c08095e: /* original 02dc, guest PC 0x0c08095e */
if(!s->budget--) { s->failed_pc=0x0c08095eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c080960;
P_0c080960: /* original e014, guest PC 0x0c080960 */
if(!s->budget--) { s->failed_pc=0x0c080960u; return 0; }
r[0]=0x00000014u;
goto P_0c080962;
P_0c080962: /* original 0f24, guest PC 0x0c080962 */
if(!s->budget--) { s->failed_pc=0x0c080962u; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c080964;
P_0c080964: /* original 6243, guest PC 0x0c080964 */
if(!s->budget--) { s->failed_pc=0x0c080964u; return 0; }
r[2]=r[4];
goto P_0c080966;
P_0c080966: /* original 61b2, guest PC 0x0c080966 */
if(!s->budget--) { s->failed_pc=0x0c080966u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c080968;
P_0c080968: /* original 4215, guest PC 0x0c080968 */
if(!s->budget--) { s->failed_pc=0x0c080968u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c08096a;
P_0c08096a: /* original 7106, guest PC 0x0c08096a */
if(!s->budget--) { s->failed_pc=0x0c08096au; return 0; }
r[1]+=0x00000006u;
goto P_0c08096c;
P_0c08096c: /* original 2f10, guest PC 0x0c08096c */
if(!s->budget--) { s->failed_pc=0x0c08096cu; return 0; }
write(ram,r[15],r[1],1);
goto P_0c08096e;
P_0c08096e: /* original 8f2f, guest PC 0x0c08096e */
if(!s->budget--) { s->failed_pc=0x0c08096eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(!cond) { goto P_0c0809d0; }
goto P_0c080972;
P_0c080970: /* original 1f41, guest PC 0x0c080970 */
if(!s->budget--) { s->failed_pc=0x0c080970u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c080972;
P_0c080972: /* original 9371, guest PC 0x0c080972 */
if(!s->budget--) { s->failed_pc=0x0c080972u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a58u,2);
goto P_0c080974;
P_0c080974: /* original 648e, guest PC 0x0c080974 */
if(!s->budget--) { s->failed_pc=0x0c080974u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c080976;
P_0c080976: /* original 33dc, guest PC 0x0c080976 */
if(!s->budget--) { s->failed_pc=0x0c080976u; return 0; }
r[3]+=r[13];
goto P_0c080978;
P_0c080978: /* original 343c, guest PC 0x0c080978 */
if(!s->budget--) { s->failed_pc=0x0c080978u; return 0; }
r[4]+=r[3];
goto P_0c08097a;
P_0c08097a: /* original 6440, guest PC 0x0c08097a */
if(!s->budget--) { s->failed_pc=0x0c08097au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c08097c;
P_0c08097c: /* original e30d, guest PC 0x0c08097c */
if(!s->budget--) { s->failed_pc=0x0c08097cu; return 0; }
r[3]=0x0000000du;
goto P_0c08097e;
P_0c08097e: /* original 3433, guest PC 0x0c08097e */
if(!s->budget--) { s->failed_pc=0x0c08097eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c080980;
P_0c080980: /* original 8b00, guest PC 0x0c080980 */
if(!s->budget--) { s->failed_pc=0x0c080980u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080984; }
goto P_0c080982;
P_0c080982: /* original 3438, guest PC 0x0c080982 */
if(!s->budget--) { s->failed_pc=0x0c080982u; return 0; }
r[4]-=r[3];
goto P_0c080984;
P_0c080984: /* original 604e, guest PC 0x0c080984 */
if(!s->budget--) { s->failed_pc=0x0c080984u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080986;
P_0c080986: /* original 4000, guest PC 0x0c080986 */
if(!s->budget--) { s->failed_pc=0x0c080986u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080988;
P_0c080988: /* original 00ad, guest PC 0x0c080988 */
if(!s->budget--) { s->failed_pc=0x0c080988u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c08098a;
P_0c08098a: /* original e307, guest PC 0x0c08098a */
if(!s->budget--) { s->failed_pc=0x0c08098au; return 0; }
r[3]=0x00000007u;
goto P_0c08098c;
P_0c08098c: /* original 628e, guest PC 0x0c08098c */
if(!s->budget--) { s->failed_pc=0x0c08098cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c08098e;
P_0c08098e: /* original 81f6, guest PC 0x0c08098e */
if(!s->budget--) { s->failed_pc=0x0c08098eu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c080990;
P_0c080990: /* original 60f0, guest PC 0x0c080990 */
if(!s->budget--) { s->failed_pc=0x0c080990u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[0]=tmp;
goto P_0c080992;
P_0c080992: /* original 403c, guest PC 0x0c080992 */
if(!s->budget--) { s->failed_pc=0x0c080992u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080994;
P_0c080994: /* original cb04, guest PC 0x0c080994 */
if(!s->budget--) { s->failed_pc=0x0c080994u; return 0; }
r[0]|=4u;
goto P_0c080996;
P_0c080996: /* original 1f04, guest PC 0x0c080996 */
if(!s->budget--) { s->failed_pc=0x0c080996u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c080998;
P_0c080998: /* original 60e3, guest PC 0x0c080998 */
if(!s->budget--) { s->failed_pc=0x0c080998u; return 0; }
r[0]=r[14];
goto P_0c08099a;
P_0c08099a: /* original 80f8, guest PC 0x0c08099a */
if(!s->budget--) { s->failed_pc=0x0c08099au; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c08099c;
P_0c08099c: /* original e014, guest PC 0x0c08099c */
if(!s->budget--) { s->failed_pc=0x0c08099cu; return 0; }
r[0]=0x00000014u;
goto P_0c08099e;
P_0c08099e: /* original 01fc, guest PC 0x0c08099e */
if(!s->budget--) { s->failed_pc=0x0c08099eu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0809a0;
P_0c0809a0: /* original 3213, guest PC 0x0c0809a0 */
if(!s->budget--) { s->failed_pc=0x0c0809a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0809a2;
P_0c0809a2: /* original 8901, guest PC 0x0c0809a2 */
if(!s->budget--) { s->failed_pc=0x0c0809a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0809a8; }
goto P_0c0809a4;
P_0c0809a4: /* original e001, guest PC 0x0c0809a4 */
if(!s->budget--) { s->failed_pc=0x0c0809a4u; return 0; }
r[0]=0x00000001u;
goto P_0c0809a6;
P_0c0809a6: /* original 80f8, guest PC 0x0c0809a6 */
if(!s->budget--) { s->failed_pc=0x0c0809a6u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0809a8;
P_0c0809a8: /* original 2fe6, guest PC 0x0c0809a8 */
if(!s->budget--) { s->failed_pc=0x0c0809a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0809aa;
P_0c0809aa: /* original 66c3, guest PC 0x0c0809aa */
if(!s->budget--) { s->failed_pc=0x0c0809aau; return 0; }
r[6]=r[12];
goto P_0c0809ac;
P_0c0809ac: /* original 85f8, guest PC 0x0c0809ac */
if(!s->budget--) { s->failed_pc=0x0c0809acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0809ae;
P_0c0809ae: /* original e700, guest PC 0x0c0809ae */
if(!s->budget--) { s->failed_pc=0x0c0809aeu; return 0; }
r[7]=0x00000000u;
goto P_0c0809b0;
P_0c0809b0: /* original 6303, guest PC 0x0c0809b0 */
if(!s->budget--) { s->failed_pc=0x0c0809b0u; return 0; }
r[3]=r[0];
goto P_0c0809b2;
P_0c0809b2: /* original 84fc, guest PC 0x0c0809b2 */
if(!s->budget--) { s->failed_pc=0x0c0809b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c0809b4;
P_0c0809b4: /* original 3308, guest PC 0x0c0809b4 */
if(!s->budget--) { s->failed_pc=0x0c0809b4u; return 0; }
r[3]-=r[0];
goto P_0c0809b6;
P_0c0809b6: /* original 6533, guest PC 0x0c0809b6 */
if(!s->budget--) { s->failed_pc=0x0c0809b6u; return 0; }
r[5]=r[3];
goto P_0c0809b8;
P_0c0809b8: /* original 7502, guest PC 0x0c0809b8 */
if(!s->budget--) { s->failed_pc=0x0c0809b8u; return 0; }
r[5]+=0x00000002u;
goto P_0c0809ba;
P_0c0809ba: /* original 490b, guest PC 0x0c0809ba */
if(!s->budget--) { s->failed_pc=0x0c0809bau; return 0; }
target=r[9];
r[16]=code_base|0x0c0809beu;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0809beu) { target=s->pc; goto dispatch; }
goto P_0c0809be;
P_0c0809bc: /* original 54f5, guest PC 0x0c0809bc */
if(!s->budget--) { s->failed_pc=0x0c0809bcu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0809be;
P_0c0809be: /* original 7f04, guest PC 0x0c0809be */
if(!s->budget--) { s->failed_pc=0x0c0809beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0809c0;
P_0c0809c0: /* original 63f0, guest PC 0x0c0809c0 */
if(!s->budget--) { s->failed_pc=0x0c0809c0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c0809c2;
P_0c0809c2: /* original 7801, guest PC 0x0c0809c2 */
if(!s->budget--) { s->failed_pc=0x0c0809c2u; return 0; }
r[8]+=0x00000001u;
goto P_0c0809c4;
P_0c0809c4: /* original 628e, guest PC 0x0c0809c4 */
if(!s->budget--) { s->failed_pc=0x0c0809c4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c0809c6;
P_0c0809c6: /* original 7302, guest PC 0x0c0809c6 */
if(!s->budget--) { s->failed_pc=0x0c0809c6u; return 0; }
r[3]+=0x00000002u;
goto P_0c0809c8;
P_0c0809c8: /* original 2f30, guest PC 0x0c0809c8 */
if(!s->budget--) { s->failed_pc=0x0c0809c8u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0809ca;
P_0c0809ca: /* original 51f1, guest PC 0x0c0809ca */
if(!s->budget--) { s->failed_pc=0x0c0809cau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0809cc;
P_0c0809cc: /* original 3213, guest PC 0x0c0809cc */
if(!s->budget--) { s->failed_pc=0x0c0809ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0809ce;
P_0c0809ce: /* original 8bd0, guest PC 0x0c0809ce */
if(!s->budget--) { s->failed_pc=0x0c0809ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080972; }
goto P_0c0809d0;
P_0c0809d0: /* original 9041, guest PC 0x0c0809d0 */
if(!s->budget--) { s->failed_pc=0x0c0809d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a56u,2);
goto P_0c0809d2;
P_0c0809d2: /* original 04dc, guest PC 0x0c0809d2 */
if(!s->budget--) { s->failed_pc=0x0c0809d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0809d4;
P_0c0809d4: /* original e01a, guest PC 0x0c0809d4 */
if(!s->budget--) { s->failed_pc=0x0c0809d4u; return 0; }
r[0]=0x0000001au;
goto P_0c0809d6;
P_0c0809d6: /* original 00dc, guest PC 0x0c0809d6 */
if(!s->budget--) { s->failed_pc=0x0c0809d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0809d8;
P_0c0809d8: /* original 6243, guest PC 0x0c0809d8 */
if(!s->budget--) { s->failed_pc=0x0c0809d8u; return 0; }
r[2]=r[4];
goto P_0c0809da;
P_0c0809da: /* original 4215, guest PC 0x0c0809da */
if(!s->budget--) { s->failed_pc=0x0c0809dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0809dc;
P_0c0809dc: /* original 80fc, guest PC 0x0c0809dc */
if(!s->budget--) { s->failed_pc=0x0c0809dcu; return 0; }
write(ram,r[15]+12,r[0],1);
goto P_0c0809de;
P_0c0809de: /* original 63b2, guest PC 0x0c0809de */
if(!s->budget--) { s->failed_pc=0x0c0809deu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c0809e0;
P_0c0809e0: /* original 6be3, guest PC 0x0c0809e0 */
if(!s->budget--) { s->failed_pc=0x0c0809e0u; return 0; }
r[11]=r[14];
goto P_0c0809e2;
P_0c0809e2: /* original 7306, guest PC 0x0c0809e2 */
if(!s->budget--) { s->failed_pc=0x0c0809e2u; return 0; }
r[3]+=0x00000006u;
goto P_0c0809e4;
P_0c0809e4: /* original 2f30, guest PC 0x0c0809e4 */
if(!s->budget--) { s->failed_pc=0x0c0809e4u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0809e6;
P_0c0809e6: /* original 8d02, guest PC 0x0c0809e6 */
if(!s->budget--) { s->failed_pc=0x0c0809e6u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(cond) { goto P_0c0809ee; }
goto P_0c0809ea;
P_0c0809e8: /* original 1f41, guest PC 0x0c0809e8 */
if(!s->budget--) { s->failed_pc=0x0c0809e8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0809ea;
P_0c0809ea: /* original a097, guest PC 0x0c0809ea */
if(!s->budget--) { s->failed_pc=0x0c0809eau; return 0; }
goto P_0c080b1c;
P_0c0809ec: /* original 0009, guest PC 0x0c0809ec */
if(!s->budget--) { s->failed_pc=0x0c0809ecu; return 0; }
goto P_0c0809ee;
P_0c0809ee: /* original 9334, guest PC 0x0c0809ee */
if(!s->budget--) { s->failed_pc=0x0c0809eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a5au,2);
goto P_0c0809f0;
P_0c0809f0: /* original 64be, guest PC 0x0c0809f0 */
if(!s->budget--) { s->failed_pc=0x0c0809f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c0809f2;
P_0c0809f2: /* original 33dc, guest PC 0x0c0809f2 */
if(!s->budget--) { s->failed_pc=0x0c0809f2u; return 0; }
r[3]+=r[13];
goto P_0c0809f4;
P_0c0809f4: /* original 343c, guest PC 0x0c0809f4 */
if(!s->budget--) { s->failed_pc=0x0c0809f4u; return 0; }
r[4]+=r[3];
goto P_0c0809f6;
P_0c0809f6: /* original 6440, guest PC 0x0c0809f6 */
if(!s->budget--) { s->failed_pc=0x0c0809f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0809f8;
P_0c0809f8: /* original e30d, guest PC 0x0c0809f8 */
if(!s->budget--) { s->failed_pc=0x0c0809f8u; return 0; }
r[3]=0x0000000du;
goto P_0c0809fa;
P_0c0809fa: /* original 3433, guest PC 0x0c0809fa */
if(!s->budget--) { s->failed_pc=0x0c0809fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0809fc;
P_0c0809fc: /* original 8f01, guest PC 0x0c0809fc */
if(!s->budget--) { s->failed_pc=0x0c0809fcu; return 0; }
cond=r[17]&1u;
r[5]=0x00000036u;
if(!cond) { goto P_0c080a02; }
goto P_0c080a00;
P_0c0809fe: /* original e536, guest PC 0x0c0809fe */
if(!s->budget--) { s->failed_pc=0x0c0809feu; return 0; }
r[5]=0x00000036u;
goto P_0c080a00;
P_0c080a00: /* original 3438, guest PC 0x0c080a00 */
if(!s->budget--) { s->failed_pc=0x0c080a00u; return 0; }
r[4]-=r[3];
goto P_0c080a02;
P_0c080a02: /* original 604e, guest PC 0x0c080a02 */
if(!s->budget--) { s->failed_pc=0x0c080a02u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080a04;
P_0c080a04: /* original 880c, guest PC 0x0c080a04 */
if(!s->budget--) { s->failed_pc=0x0c080a04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c080a06;
P_0c080a06: /* original 8f01, guest PC 0x0c080a06 */
if(!s->budget--) { s->failed_pc=0x0c080a06u; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
if(!cond) { goto P_0c080a0c; }
goto P_0c080a0a;
P_0c080a08: /* original 604e, guest PC 0x0c080a08 */
if(!s->budget--) { s->failed_pc=0x0c080a08u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080a0a;
P_0c080a0a: /* original e535, guest PC 0x0c080a0a */
if(!s->budget--) { s->failed_pc=0x0c080a0au; return 0; }
r[5]=0x00000035u;
goto P_0c080a0c;
P_0c080a0c: /* original 4000, guest PC 0x0c080a0c */
if(!s->budget--) { s->failed_pc=0x0c080a0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080a0e;
P_0c080a0e: /* original 00ad, guest PC 0x0c080a0e */
if(!s->budget--) { s->failed_pc=0x0c080a0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080a10;
P_0c080a10: /* original e207, guest PC 0x0c080a10 */
if(!s->budget--) { s->failed_pc=0x0c080a10u; return 0; }
r[2]=0x00000007u;
goto P_0c080a12;
P_0c080a12: /* original 655e, guest PC 0x0c080a12 */
if(!s->budget--) { s->failed_pc=0x0c080a12u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c080a14;
P_0c080a14: /* original 81f4, guest PC 0x0c080a14 */
if(!s->budget--) { s->failed_pc=0x0c080a14u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c080a16;
P_0c080a16: /* original 4500, guest PC 0x0c080a16 */
if(!s->budget--) { s->failed_pc=0x0c080a16u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c080a18;
P_0c080a18: /* original 63f0, guest PC 0x0c080a18 */
if(!s->budget--) { s->failed_pc=0x0c080a18u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c080a1a;
P_0c080a1a: /* original 432c, guest PC 0x0c080a1a */
if(!s->budget--) { s->failed_pc=0x0c080a1au; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c080a1c;
P_0c080a1c: /* original 253b, guest PC 0x0c080a1c */
if(!s->budget--) { s->failed_pc=0x0c080a1cu; return 0; }
r[5]|=r[3];
goto P_0c080a1e;
P_0c080a1e: /* original 63be, guest PC 0x0c080a1e */
if(!s->budget--) { s->failed_pc=0x0c080a1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c080a20;
P_0c080a20: /* original 1f54, guest PC 0x0c080a20 */
if(!s->budget--) { s->failed_pc=0x0c080a20u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c080a22;
P_0c080a22: /* original 84fc, guest PC 0x0c080a22 */
if(!s->budget--) { s->failed_pc=0x0c080a22u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c080a24;
P_0c080a24: /* original 3303, guest PC 0x0c080a24 */
if(!s->budget--) { s->failed_pc=0x0c080a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[0])!=0);
goto P_0c080a26;
P_0c080a26: /* original 8d01, guest PC 0x0c080a26 */
if(!s->budget--) { s->failed_pc=0x0c080a26u; return 0; }
cond=r[17]&1u;
r[8]=r[14];
if(cond) { goto P_0c080a2c; }
goto P_0c080a2a;
P_0c080a28: /* original 68e3, guest PC 0x0c080a28 */
if(!s->budget--) { s->failed_pc=0x0c080a28u; return 0; }
r[8]=r[14];
goto P_0c080a2a;
P_0c080a2a: /* original e801, guest PC 0x0c080a2a */
if(!s->budget--) { s->failed_pc=0x0c080a2au; return 0; }
r[8]=0x00000001u;
goto P_0c080a2c;
P_0c080a2c: /* original 2fe6, guest PC 0x0c080a2c */
if(!s->budget--) { s->failed_pc=0x0c080a2cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080a2e;
P_0c080a2e: /* original 688e, guest PC 0x0c080a2e */
if(!s->budget--) { s->failed_pc=0x0c080a2eu; return 0; }
r[8]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c080a30;
P_0c080a30: /* original 85f6, guest PC 0x0c080a30 */
if(!s->budget--) { s->failed_pc=0x0c080a30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c080a32;
P_0c080a32: /* original 66c3, guest PC 0x0c080a32 */
if(!s->budget--) { s->failed_pc=0x0c080a32u; return 0; }
r[6]=r[12];
goto P_0c080a34;
P_0c080a34: /* original e700, guest PC 0x0c080a34 */
if(!s->budget--) { s->failed_pc=0x0c080a34u; return 0; }
r[7]=0x00000000u;
goto P_0c080a36;
P_0c080a36: /* original 3088, guest PC 0x0c080a36 */
if(!s->budget--) { s->failed_pc=0x0c080a36u; return 0; }
r[0]-=r[8];
goto P_0c080a38;
P_0c080a38: /* original 6503, guest PC 0x0c080a38 */
if(!s->budget--) { s->failed_pc=0x0c080a38u; return 0; }
r[5]=r[0];
goto P_0c080a3a;
P_0c080a3a: /* original 7502, guest PC 0x0c080a3a */
if(!s->budget--) { s->failed_pc=0x0c080a3au; return 0; }
r[5]+=0x00000002u;
goto P_0c080a3c;
P_0c080a3c: /* original 490b, guest PC 0x0c080a3c */
if(!s->budget--) { s->failed_pc=0x0c080a3cu; return 0; }
target=r[9];
r[16]=code_base|0x0c080a40u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080a40u) { target=s->pc; goto dispatch; }
goto P_0c080a40;
P_0c080a3e: /* original 54f5, guest PC 0x0c080a3e */
if(!s->budget--) { s->failed_pc=0x0c080a3eu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c080a40;
P_0c080a40: /* original 7f04, guest PC 0x0c080a40 */
if(!s->budget--) { s->failed_pc=0x0c080a40u; return 0; }
r[15]+=0x00000004u;
goto P_0c080a42;
P_0c080a42: /* original 63f0, guest PC 0x0c080a42 */
if(!s->budget--) { s->failed_pc=0x0c080a42u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c080a44;
P_0c080a44: /* original 7b01, guest PC 0x0c080a44 */
if(!s->budget--) { s->failed_pc=0x0c080a44u; return 0; }
r[11]+=0x00000001u;
goto P_0c080a46;
P_0c080a46: /* original 62be, guest PC 0x0c080a46 */
if(!s->budget--) { s->failed_pc=0x0c080a46u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c080a48;
P_0c080a48: /* original 7302, guest PC 0x0c080a48 */
if(!s->budget--) { s->failed_pc=0x0c080a48u; return 0; }
r[3]+=0x00000002u;
goto P_0c080a4a;
P_0c080a4a: /* original 2f30, guest PC 0x0c080a4a */
if(!s->budget--) { s->failed_pc=0x0c080a4au; return 0; }
write(ram,r[15],r[3],1);
goto P_0c080a4c;
P_0c080a4c: /* original 51f1, guest PC 0x0c080a4c */
if(!s->budget--) { s->failed_pc=0x0c080a4cu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c080a4e;
P_0c080a4e: /* original 3213, guest PC 0x0c080a4e */
if(!s->budget--) { s->failed_pc=0x0c080a4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c080a50;
P_0c080a50: /* original 8bcd, guest PC 0x0c080a50 */
if(!s->budget--) { s->failed_pc=0x0c080a50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0809ee; }
goto P_0c080a52;
P_0c080a52: /* original a063, guest PC 0x0c080a52 */
if(!s->budget--) { s->failed_pc=0x0c080a52u; return 0; }
goto P_0c080b1c;
P_0c080a54: /* original 0009, guest PC 0x0c080a54 */
if(!s->budget--) { s->failed_pc=0x0c080a54u; return 0; }
if(!vf3_matrix_family(0x0c080a56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080a56u; return 0; } return 1;
P_0c080a74: /* original 5152, guest PC 0x0c080a74 */
if(!s->budget--) { s->failed_pc=0x0c080a74u; return 0; }
r[1]=read(ram,r[5]+8,4);
goto P_0c080a76;
P_0c080a76: /* original d22f, guest PC 0x0c080a76 */
if(!s->budget--) { s->failed_pc=0x0c080a76u; return 0; }
r[2]=read(ram,0x0c080b34u,4);
goto P_0c080a78;
P_0c080a78: /* original 2128, guest PC 0x0c080a78 */
if(!s->budget--) { s->failed_pc=0x0c080a78u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c080a7a;
P_0c080a7a: /* original 8b4f, guest PC 0x0c080a7a */
if(!s->budget--) { s->failed_pc=0x0c080a7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080b1c; }
goto P_0c080a7c;
P_0c080a7c: /* original 60b2, guest PC 0x0c080a7c */
if(!s->budget--) { s->failed_pc=0x0c080a7cu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080a7e;
P_0c080a7e: /* original e307, guest PC 0x0c080a7e */
if(!s->budget--) { s->failed_pc=0x0c080a7eu; return 0; }
r[3]=0x00000007u;
goto P_0c080a80;
P_0c080a80: /* original e220, guest PC 0x0c080a80 */
if(!s->budget--) { s->failed_pc=0x0c080a80u; return 0; }
r[2]=0x00000020u;
goto P_0c080a82;
P_0c080a82: /* original 7006, guest PC 0x0c080a82 */
if(!s->budget--) { s->failed_pc=0x0c080a82u; return 0; }
r[0]+=0x00000006u;
goto P_0c080a84;
P_0c080a84: /* original 403c, guest PC 0x0c080a84 */
if(!s->budget--) { s->failed_pc=0x0c080a84u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080a86;
P_0c080a86: /* original cb04, guest PC 0x0c080a86 */
if(!s->budget--) { s->failed_pc=0x0c080a86u; return 0; }
r[0]|=4u;
goto P_0c080a88;
P_0c080a88: /* original 2f02, guest PC 0x0c080a88 */
if(!s->budget--) { s->failed_pc=0x0c080a88u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c080a8a;
P_0c080a8a: /* original 6503, guest PC 0x0c080a8a */
if(!s->budget--) { s->failed_pc=0x0c080a8au; return 0; }
r[5]=r[0];
goto P_0c080a8c;
P_0c080a8c: /* original e615, guest PC 0x0c080a8c */
if(!s->budget--) { s->failed_pc=0x0c080a8cu; return 0; }
r[6]=0x00000015u;
goto P_0c080a8e;
P_0c080a8e: /* original 2f26, guest PC 0x0c080a8e */
if(!s->budget--) { s->failed_pc=0x0c080a8eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080a90;
P_0c080a90: /* original d329, guest PC 0x0c080a90 */
if(!s->budget--) { s->failed_pc=0x0c080a90u; return 0; }
r[3]=read(ram,0x0c080b38u,4);
goto P_0c080a92;
P_0c080a92: /* original e701, guest PC 0x0c080a92 */
if(!s->budget--) { s->failed_pc=0x0c080a92u; return 0; }
r[7]=0x00000001u;
goto P_0c080a94;
P_0c080a94: /* original 430b, guest PC 0x0c080a94 */
if(!s->budget--) { s->failed_pc=0x0c080a94u; return 0; }
target=r[3];
r[16]=code_base|0x0c080a98u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080a98u) { target=s->pc; goto dispatch; }
goto P_0c080a98;
P_0c080a96: /* original 64c3, guest PC 0x0c080a96 */
if(!s->budget--) { s->failed_pc=0x0c080a96u; return 0; }
r[4]=r[12];
goto P_0c080a98;
P_0c080a98: /* original 60b2, guest PC 0x0c080a98 */
if(!s->budget--) { s->failed_pc=0x0c080a98u; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080a9a;
P_0c080a9a: /* original e307, guest PC 0x0c080a9a */
if(!s->budget--) { s->failed_pc=0x0c080a9au; return 0; }
r[3]=0x00000007u;
goto P_0c080a9c;
P_0c080a9c: /* original e220, guest PC 0x0c080a9c */
if(!s->budget--) { s->failed_pc=0x0c080a9cu; return 0; }
r[2]=0x00000020u;
goto P_0c080a9e;
P_0c080a9e: /* original 7006, guest PC 0x0c080a9e */
if(!s->budget--) { s->failed_pc=0x0c080a9eu; return 0; }
r[0]+=0x00000006u;
goto P_0c080aa0;
P_0c080aa0: /* original 403c, guest PC 0x0c080aa0 */
if(!s->budget--) { s->failed_pc=0x0c080aa0u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080aa2;
P_0c080aa2: /* original cb5c, guest PC 0x0c080aa2 */
if(!s->budget--) { s->failed_pc=0x0c080aa2u; return 0; }
r[0]|=92u;
goto P_0c080aa4;
P_0c080aa4: /* original 1f01, guest PC 0x0c080aa4 */
if(!s->budget--) { s->failed_pc=0x0c080aa4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c080aa6;
P_0c080aa6: /* original 6503, guest PC 0x0c080aa6 */
if(!s->budget--) { s->failed_pc=0x0c080aa6u; return 0; }
r[5]=r[0];
goto P_0c080aa8;
P_0c080aa8: /* original e615, guest PC 0x0c080aa8 */
if(!s->budget--) { s->failed_pc=0x0c080aa8u; return 0; }
r[6]=0x00000015u;
goto P_0c080aaa;
P_0c080aaa: /* original 2f26, guest PC 0x0c080aaa */
if(!s->budget--) { s->failed_pc=0x0c080aaau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080aac;
P_0c080aac: /* original d322, guest PC 0x0c080aac */
if(!s->budget--) { s->failed_pc=0x0c080aacu; return 0; }
r[3]=read(ram,0x0c080b38u,4);
goto P_0c080aae;
P_0c080aae: /* original e701, guest PC 0x0c080aae */
if(!s->budget--) { s->failed_pc=0x0c080aaeu; return 0; }
r[7]=0x00000001u;
goto P_0c080ab0;
P_0c080ab0: /* original 430b, guest PC 0x0c080ab0 */
if(!s->budget--) { s->failed_pc=0x0c080ab0u; return 0; }
target=r[3];
r[16]=code_base|0x0c080ab4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ab4u) { target=s->pc; goto dispatch; }
goto P_0c080ab4;
P_0c080ab2: /* original 64c3, guest PC 0x0c080ab2 */
if(!s->budget--) { s->failed_pc=0x0c080ab2u; return 0; }
r[4]=r[12];
goto P_0c080ab4;
P_0c080ab4: /* original 54f9, guest PC 0x0c080ab4 */
if(!s->budget--) { s->failed_pc=0x0c080ab4u; return 0; }
r[4]=read(ram,r[15]+36,4);
goto P_0c080ab6;
P_0c080ab6: /* original e061, guest PC 0x0c080ab6 */
if(!s->budget--) { s->failed_pc=0x0c080ab6u; return 0; }
r[0]=0x00000061u;
goto P_0c080ab8;
P_0c080ab8: /* original e207, guest PC 0x0c080ab8 */
if(!s->budget--) { s->failed_pc=0x0c080ab8u; return 0; }
r[2]=0x00000007u;
goto P_0c080aba;
P_0c080aba: /* original 66c3, guest PC 0x0c080aba */
if(!s->budget--) { s->failed_pc=0x0c080abau; return 0; }
r[6]=r[12];
goto P_0c080abc;
P_0c080abc: /* original 044c, guest PC 0x0c080abc */
if(!s->budget--) { s->failed_pc=0x0c080abcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080abe;
P_0c080abe: /* original e700, guest PC 0x0c080abe */
if(!s->budget--) { s->failed_pc=0x0c080abeu; return 0; }
r[7]=0x00000000u;
goto P_0c080ac0;
P_0c080ac0: /* original 604e, guest PC 0x0c080ac0 */
if(!s->budget--) { s->failed_pc=0x0c080ac0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080ac2;
P_0c080ac2: /* original 4000, guest PC 0x0c080ac2 */
if(!s->budget--) { s->failed_pc=0x0c080ac2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080ac4;
P_0c080ac4: /* original 03ad, guest PC 0x0c080ac4 */
if(!s->budget--) { s->failed_pc=0x0c080ac4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080ac6;
P_0c080ac6: /* original 6033, guest PC 0x0c080ac6 */
if(!s->budget--) { s->failed_pc=0x0c080ac6u; return 0; }
r[0]=r[3];
goto P_0c080ac8;
P_0c080ac8: /* original 81f4, guest PC 0x0c080ac8 */
if(!s->budget--) { s->failed_pc=0x0c080ac8u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c080aca;
P_0c080aca: /* original 60b2, guest PC 0x0c080aca */
if(!s->budget--) { s->failed_pc=0x0c080acau; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080acc;
P_0c080acc: /* original 7006, guest PC 0x0c080acc */
if(!s->budget--) { s->failed_pc=0x0c080accu; return 0; }
r[0]+=0x00000006u;
goto P_0c080ace;
P_0c080ace: /* original 402c, guest PC 0x0c080ace */
if(!s->budget--) { s->failed_pc=0x0c080aceu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c080ad0;
P_0c080ad0: /* original cb04, guest PC 0x0c080ad0 */
if(!s->budget--) { s->failed_pc=0x0c080ad0u; return 0; }
r[0]|=4u;
goto P_0c080ad2;
P_0c080ad2: /* original 1f04, guest PC 0x0c080ad2 */
if(!s->budget--) { s->failed_pc=0x0c080ad2u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c080ad4;
P_0c080ad4: /* original 2fe6, guest PC 0x0c080ad4 */
if(!s->budget--) { s->failed_pc=0x0c080ad4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080ad6;
P_0c080ad6: /* original 85f6, guest PC 0x0c080ad6 */
if(!s->budget--) { s->failed_pc=0x0c080ad6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c080ad8;
P_0c080ad8: /* original 6503, guest PC 0x0c080ad8 */
if(!s->budget--) { s->failed_pc=0x0c080ad8u; return 0; }
r[5]=r[0];
goto P_0c080ada;
P_0c080ada: /* original 7502, guest PC 0x0c080ada */
if(!s->budget--) { s->failed_pc=0x0c080adau; return 0; }
r[5]+=0x00000002u;
goto P_0c080adc;
P_0c080adc: /* original 490b, guest PC 0x0c080adc */
if(!s->budget--) { s->failed_pc=0x0c080adcu; return 0; }
target=r[9];
r[16]=code_base|0x0c080ae0u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ae0u) { target=s->pc; goto dispatch; }
goto P_0c080ae0;
P_0c080ade: /* original 54f5, guest PC 0x0c080ade */
if(!s->budget--) { s->failed_pc=0x0c080adeu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c080ae0;
P_0c080ae0: /* original 7f0c, guest PC 0x0c080ae0 */
if(!s->budget--) { s->failed_pc=0x0c080ae0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c080ae2;
P_0c080ae2: /* original 54f6, guest PC 0x0c080ae2 */
if(!s->budget--) { s->failed_pc=0x0c080ae2u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c080ae4;
P_0c080ae4: /* original e061, guest PC 0x0c080ae4 */
if(!s->budget--) { s->failed_pc=0x0c080ae4u; return 0; }
r[0]=0x00000061u;
goto P_0c080ae6;
P_0c080ae6: /* original e307, guest PC 0x0c080ae6 */
if(!s->budget--) { s->failed_pc=0x0c080ae6u; return 0; }
r[3]=0x00000007u;
goto P_0c080ae8;
P_0c080ae8: /* original 044c, guest PC 0x0c080ae8 */
if(!s->budget--) { s->failed_pc=0x0c080ae8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080aea;
P_0c080aea: /* original ed6c, guest PC 0x0c080aea */
if(!s->budget--) { s->failed_pc=0x0c080aeau; return 0; }
r[13]=0x0000006cu;
goto P_0c080aec;
P_0c080aec: /* original 60b2, guest PC 0x0c080aec */
if(!s->budget--) { s->failed_pc=0x0c080aecu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080aee;
P_0c080aee: /* original 7006, guest PC 0x0c080aee */
if(!s->budget--) { s->failed_pc=0x0c080aeeu; return 0; }
r[0]+=0x00000006u;
goto P_0c080af0;
P_0c080af0: /* original 403c, guest PC 0x0c080af0 */
if(!s->budget--) { s->failed_pc=0x0c080af0u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080af2;
P_0c080af2: /* original 2d0b, guest PC 0x0c080af2 */
if(!s->budget--) { s->failed_pc=0x0c080af2u; return 0; }
r[13]|=r[0];
goto P_0c080af4;
P_0c080af4: /* original 604e, guest PC 0x0c080af4 */
if(!s->budget--) { s->failed_pc=0x0c080af4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080af6;
P_0c080af6: /* original 880c, guest PC 0x0c080af6 */
if(!s->budget--) { s->failed_pc=0x0c080af6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c080af8;
P_0c080af8: /* original 8b04, guest PC 0x0c080af8 */
if(!s->budget--) { s->failed_pc=0x0c080af8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080b04; }
goto P_0c080afa;
P_0c080afa: /* original 60b2, guest PC 0x0c080afa */
if(!s->budget--) { s->failed_pc=0x0c080afau; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080afc;
P_0c080afc: /* original ed64, guest PC 0x0c080afc */
if(!s->budget--) { s->failed_pc=0x0c080afcu; return 0; }
r[13]=0x00000064u;
goto P_0c080afe;
P_0c080afe: /* original 7006, guest PC 0x0c080afe */
if(!s->budget--) { s->failed_pc=0x0c080afeu; return 0; }
r[0]+=0x00000006u;
goto P_0c080b00;
P_0c080b00: /* original 403c, guest PC 0x0c080b00 */
if(!s->budget--) { s->failed_pc=0x0c080b00u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080b02;
P_0c080b02: /* original 2d0b, guest PC 0x0c080b02 */
if(!s->budget--) { s->failed_pc=0x0c080b02u; return 0; }
r[13]|=r[0];
goto P_0c080b04;
P_0c080b04: /* original 604e, guest PC 0x0c080b04 */
if(!s->budget--) { s->failed_pc=0x0c080b04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080b06;
P_0c080b06: /* original 66c3, guest PC 0x0c080b06 */
if(!s->budget--) { s->failed_pc=0x0c080b06u; return 0; }
r[6]=r[12];
goto P_0c080b08;
P_0c080b08: /* original 4000, guest PC 0x0c080b08 */
if(!s->budget--) { s->failed_pc=0x0c080b08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080b0a;
P_0c080b0a: /* original 03ad, guest PC 0x0c080b0a */
if(!s->budget--) { s->failed_pc=0x0c080b0au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080b0c;
P_0c080b0c: /* original e700, guest PC 0x0c080b0c */
if(!s->budget--) { s->failed_pc=0x0c080b0cu; return 0; }
r[7]=0x00000000u;
goto P_0c080b0e;
P_0c080b0e: /* original 653f, guest PC 0x0c080b0e */
if(!s->budget--) { s->failed_pc=0x0c080b0eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c080b10;
P_0c080b10: /* original 2f31, guest PC 0x0c080b10 */
if(!s->budget--) { s->failed_pc=0x0c080b10u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c080b12;
P_0c080b12: /* original 7502, guest PC 0x0c080b12 */
if(!s->budget--) { s->failed_pc=0x0c080b12u; return 0; }
r[5]+=0x00000002u;
goto P_0c080b14;
P_0c080b14: /* original 2fe6, guest PC 0x0c080b14 */
if(!s->budget--) { s->failed_pc=0x0c080b14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b16;
P_0c080b16: /* original 490b, guest PC 0x0c080b16 */
if(!s->budget--) { s->failed_pc=0x0c080b16u; return 0; }
target=r[9];
r[16]=code_base|0x0c080b1au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080b1au) { target=s->pc; goto dispatch; }
goto P_0c080b1a;
P_0c080b18: /* original 64d3, guest PC 0x0c080b18 */
if(!s->budget--) { s->failed_pc=0x0c080b18u; return 0; }
r[4]=r[13];
goto P_0c080b1a;
P_0c080b1a: /* original 7f04, guest PC 0x0c080b1a */
if(!s->budget--) { s->failed_pc=0x0c080b1au; return 0; }
r[15]+=0x00000004u;
goto P_0c080b1c;
P_0c080b1c: /* original 7f20, guest PC 0x0c080b1c */
if(!s->budget--) { s->failed_pc=0x0c080b1cu; return 0; }
r[15]+=0x00000020u;
goto P_0c080b1e;
P_0c080b1e: /* original 4f26, guest PC 0x0c080b1e */
if(!s->budget--) { s->failed_pc=0x0c080b1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080b20;
P_0c080b20: /* original e000, guest PC 0x0c080b20 */
if(!s->budget--) { s->failed_pc=0x0c080b20u; return 0; }
r[0]=0x00000000u;
goto P_0c080b22;
P_0c080b22: /* original 68f6, guest PC 0x0c080b22 */
if(!s->budget--) { s->failed_pc=0x0c080b22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c080b24;
P_0c080b24: /* original 69f6, guest PC 0x0c080b24 */
if(!s->budget--) { s->failed_pc=0x0c080b24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c080b26;
P_0c080b26: /* original 6af6, guest PC 0x0c080b26 */
if(!s->budget--) { s->failed_pc=0x0c080b26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c080b28;
P_0c080b28: /* original 6bf6, guest PC 0x0c080b28 */
if(!s->budget--) { s->failed_pc=0x0c080b28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c080b2a;
P_0c080b2a: /* original 6cf6, guest PC 0x0c080b2a */
if(!s->budget--) { s->failed_pc=0x0c080b2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080b2c;
P_0c080b2c: /* original 6df6, guest PC 0x0c080b2c */
if(!s->budget--) { s->failed_pc=0x0c080b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080b2e;
P_0c080b2e: /* original 000b, guest PC 0x0c080b2e */
if(!s->budget--) { s->failed_pc=0x0c080b2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080b30: /* original 6ef6, guest PC 0x0c080b30 */
if(!s->budget--) { s->failed_pc=0x0c080b30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c080b32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080b32u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
