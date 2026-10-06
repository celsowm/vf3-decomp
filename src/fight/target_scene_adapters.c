/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_target_scene_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c06c63au: goto P_0c06c63a;
case 0x0c06c63cu: goto P_0c06c63c;
case 0x0c06c63eu: goto P_0c06c63e;
case 0x0c06c640u: goto P_0c06c640;
case 0x0c06c642u: goto P_0c06c642;
case 0x0c06c644u: goto P_0c06c644;
case 0x0c06c646u: goto P_0c06c646;
case 0x0c06c648u: goto P_0c06c648;
case 0x0c06c64au: goto P_0c06c64a;
case 0x0c06c64cu: goto P_0c06c64c;
case 0x0c06c64eu: goto P_0c06c64e;
case 0x0c06c650u: goto P_0c06c650;
case 0x0c06c652u: goto P_0c06c652;
case 0x0c06c654u: goto P_0c06c654;
case 0x0c06c656u: goto P_0c06c656;
case 0x0c06c658u: goto P_0c06c658;
case 0x0c06c65au: goto P_0c06c65a;
case 0x0c06c65cu: goto P_0c06c65c;
case 0x0c06c65eu: goto P_0c06c65e;
case 0x0c06c660u: goto P_0c06c660;
case 0x0c06c662u: goto P_0c06c662;
case 0x0c06c664u: goto P_0c06c664;
case 0x0c06c666u: goto P_0c06c666;
case 0x0c06c668u: goto P_0c06c668;
case 0x0c06c66au: goto P_0c06c66a;
case 0x0c06c66cu: goto P_0c06c66c;
case 0x0c06c66eu: goto P_0c06c66e;
case 0x0c06c670u: goto P_0c06c670;
case 0x0c06c672u: goto P_0c06c672;
case 0x0c06c674u: goto P_0c06c674;
case 0x0c06c676u: goto P_0c06c676;
case 0x0c06c678u: goto P_0c06c678;
case 0x0c06c67au: goto P_0c06c67a;
case 0x0c06c67cu: goto P_0c06c67c;
case 0x0c06c67eu: goto P_0c06c67e;
case 0x0c06c680u: goto P_0c06c680;
case 0x0c06c682u: goto P_0c06c682;
case 0x0c06c684u: goto P_0c06c684;
case 0x0c06c686u: goto P_0c06c686;
case 0x0c06c688u: goto P_0c06c688;
case 0x0c06c68au: goto P_0c06c68a;
case 0x0c06c68cu: goto P_0c06c68c;
case 0x0c06c68eu: goto P_0c06c68e;
case 0x0c06c690u: goto P_0c06c690;
case 0x0c06c692u: goto P_0c06c692;
case 0x0c06c694u: goto P_0c06c694;
case 0x0c06c696u: goto P_0c06c696;
case 0x0c06c698u: goto P_0c06c698;
case 0x0c06c69au: goto P_0c06c69a;
case 0x0c06c69cu: goto P_0c06c69c;
case 0x0c06c69eu: goto P_0c06c69e;
case 0x0c06c6a0u: goto P_0c06c6a0;
case 0x0c06c6a2u: goto P_0c06c6a2;
case 0x0c06c6a4u: goto P_0c06c6a4;
case 0x0c06c6a6u: goto P_0c06c6a6;
case 0x0c06c6a8u: goto P_0c06c6a8;
case 0x0c07ed74u: goto P_0c07ed74;
case 0x0c07ed76u: goto P_0c07ed76;
case 0x0c07ed78u: goto P_0c07ed78;
case 0x0c07ed7au: goto P_0c07ed7a;
case 0x0c07ed7cu: goto P_0c07ed7c;
case 0x0c07ed7eu: goto P_0c07ed7e;
case 0x0c07ed80u: goto P_0c07ed80;
case 0x0c07ed82u: goto P_0c07ed82;
case 0x0c07ed84u: goto P_0c07ed84;
case 0x0c07ed86u: goto P_0c07ed86;
case 0x0c07ed88u: goto P_0c07ed88;
case 0x0c07ed8au: goto P_0c07ed8a;
case 0x0c07ed8cu: goto P_0c07ed8c;
case 0x0c07ed8eu: goto P_0c07ed8e;
case 0x0c07ed90u: goto P_0c07ed90;
case 0x0c07ed92u: goto P_0c07ed92;
case 0x0c07ed94u: goto P_0c07ed94;
case 0x0c07ed96u: goto P_0c07ed96;
case 0x0c07ed98u: goto P_0c07ed98;
case 0x0c07ed9au: goto P_0c07ed9a;
case 0x0c07ed9cu: goto P_0c07ed9c;
case 0x0c07ed9eu: goto P_0c07ed9e;
case 0x0c07eda0u: goto P_0c07eda0;
case 0x0c07eda2u: goto P_0c07eda2;
case 0x0c07eda4u: goto P_0c07eda4;
case 0x0c07eda6u: goto P_0c07eda6;
case 0x0c07eda8u: goto P_0c07eda8;
case 0x0c07edaau: goto P_0c07edaa;
case 0x0c07edacu: goto P_0c07edac;
case 0x0c07edaeu: goto P_0c07edae;
case 0x0c07edb0u: goto P_0c07edb0;
case 0x0c07edb2u: goto P_0c07edb2;
case 0x0c07edb4u: goto P_0c07edb4;
case 0x0c07edb6u: goto P_0c07edb6;
case 0x0c07edb8u: goto P_0c07edb8;
case 0x0c07edbau: goto P_0c07edba;
case 0x0c07edbcu: goto P_0c07edbc;
case 0x0c07edbeu: goto P_0c07edbe;
case 0x0c07edc0u: goto P_0c07edc0;
case 0x0c07edc2u: goto P_0c07edc2;
case 0x0c07edc4u: goto P_0c07edc4;
case 0x0c07edc6u: goto P_0c07edc6;
case 0x0c07edc8u: goto P_0c07edc8;
case 0x0c07edcau: goto P_0c07edca;
case 0x0c07edccu: goto P_0c07edcc;
case 0x0c07edceu: goto P_0c07edce;
case 0x0c07edd0u: goto P_0c07edd0;
case 0x0c07edd2u: goto P_0c07edd2;
case 0x0c07edd4u: goto P_0c07edd4;
case 0x0c07edd6u: goto P_0c07edd6;
case 0x0c07edd8u: goto P_0c07edd8;
case 0x0c07eddau: goto P_0c07edda;
case 0x0c07eddcu: goto P_0c07eddc;
case 0x0c07eddeu: goto P_0c07edde;
case 0x0c07ede0u: goto P_0c07ede0;
case 0x0c07ede2u: goto P_0c07ede2;
case 0x0c07ede4u: goto P_0c07ede4;
case 0x0c07ede6u: goto P_0c07ede6;
case 0x0c07ede8u: goto P_0c07ede8;
case 0x0c07edeau: goto P_0c07edea;
case 0x0c07edecu: goto P_0c07edec;
case 0x0c07edeeu: goto P_0c07edee;
case 0x0c07edf0u: goto P_0c07edf0;
case 0x0c07edf2u: goto P_0c07edf2;
case 0x0c07edf4u: goto P_0c07edf4;
case 0x0c07edf6u: goto P_0c07edf6;
case 0x0c07edf8u: goto P_0c07edf8;
case 0x0c07edfau: goto P_0c07edfa;
case 0x0c07edfcu: goto P_0c07edfc;
case 0x0c07edfeu: goto P_0c07edfe;
case 0x0c07ee00u: goto P_0c07ee00;
case 0x0c07ee02u: goto P_0c07ee02;
case 0x0c07ee04u: goto P_0c07ee04;
case 0x0c07ee06u: goto P_0c07ee06;
case 0x0c07ee08u: goto P_0c07ee08;
case 0x0c07ee0au: goto P_0c07ee0a;
case 0x0c07ee0cu: goto P_0c07ee0c;
case 0x0c07ee0eu: goto P_0c07ee0e;
case 0x0c07ee10u: goto P_0c07ee10;
case 0x0c07ee12u: goto P_0c07ee12;
case 0x0c07ee14u: goto P_0c07ee14;
case 0x0c07ee16u: goto P_0c07ee16;
case 0x0c07ee18u: goto P_0c07ee18;
case 0x0c07ee1au: goto P_0c07ee1a;
case 0x0c07ee1cu: goto P_0c07ee1c;
case 0x0c07ee1eu: goto P_0c07ee1e;
case 0x0c07ee20u: goto P_0c07ee20;
case 0x0c07ee22u: goto P_0c07ee22;
case 0x0c07ee24u: goto P_0c07ee24;
case 0x0c07ee26u: goto P_0c07ee26;
case 0x0c07ee28u: goto P_0c07ee28;
case 0x0c07ee2au: goto P_0c07ee2a;
case 0x0c07ee2cu: goto P_0c07ee2c;
case 0x0c07ee2eu: goto P_0c07ee2e;
case 0x0c07ee30u: goto P_0c07ee30;
case 0x0c07ee32u: goto P_0c07ee32;
case 0x0c080b3cu: goto P_0c080b3c;
case 0x0c080b3eu: goto P_0c080b3e;
case 0x0c080b40u: goto P_0c080b40;
case 0x0c080b42u: goto P_0c080b42;
case 0x0c080b44u: goto P_0c080b44;
case 0x0c080b46u: goto P_0c080b46;
case 0x0c080b48u: goto P_0c080b48;
case 0x0c080b4au: goto P_0c080b4a;
case 0x0c080b4cu: goto P_0c080b4c;
case 0x0c080b4eu: goto P_0c080b4e;
case 0x0c080b50u: goto P_0c080b50;
case 0x0c080b52u: goto P_0c080b52;
case 0x0c080b54u: goto P_0c080b54;
case 0x0c080b56u: goto P_0c080b56;
case 0x0c080b58u: goto P_0c080b58;
case 0x0c080b5au: goto P_0c080b5a;
case 0x0c080b5cu: goto P_0c080b5c;
case 0x0c080b5eu: goto P_0c080b5e;
case 0x0c080b60u: goto P_0c080b60;
case 0x0c080b62u: goto P_0c080b62;
case 0x0c080b64u: goto P_0c080b64;
case 0x0c080b66u: goto P_0c080b66;
case 0x0c080b68u: goto P_0c080b68;
case 0x0c080b6au: goto P_0c080b6a;
case 0x0c080b6cu: goto P_0c080b6c;
case 0x0c080b6eu: goto P_0c080b6e;
case 0x0c080b70u: goto P_0c080b70;
case 0x0c080b72u: goto P_0c080b72;
case 0x0c080b74u: goto P_0c080b74;
case 0x0c080b76u: goto P_0c080b76;
case 0x0c080b78u: goto P_0c080b78;
case 0x0c080b7au: goto P_0c080b7a;
case 0x0c080b7cu: goto P_0c080b7c;
case 0x0c080b7eu: goto P_0c080b7e;
case 0x0c080b80u: goto P_0c080b80;
case 0x0c080b82u: goto P_0c080b82;
case 0x0c080b84u: goto P_0c080b84;
case 0x0c080b86u: goto P_0c080b86;
case 0x0c080b88u: goto P_0c080b88;
case 0x0c080b8au: goto P_0c080b8a;
case 0x0c080b8cu: goto P_0c080b8c;
case 0x0c080b8eu: goto P_0c080b8e;
case 0x0c080b90u: goto P_0c080b90;
case 0x0c080b92u: goto P_0c080b92;
case 0x0c080b94u: goto P_0c080b94;
case 0x0c080b96u: goto P_0c080b96;
case 0x0c080b98u: goto P_0c080b98;
case 0x0c080b9au: goto P_0c080b9a;
case 0x0c080b9cu: goto P_0c080b9c;
case 0x0c080b9eu: goto P_0c080b9e;
case 0x0c080ba0u: goto P_0c080ba0;
case 0x0c080ba2u: goto P_0c080ba2;
case 0x0c080ba4u: goto P_0c080ba4;
case 0x0c080ba6u: goto P_0c080ba6;
case 0x0c080ba8u: goto P_0c080ba8;
case 0x0c080baau: goto P_0c080baa;
case 0x0c080bacu: goto P_0c080bac;
case 0x0c080baeu: goto P_0c080bae;
case 0x0c080bb0u: goto P_0c080bb0;
case 0x0c080bb2u: goto P_0c080bb2;
case 0x0c080bb4u: goto P_0c080bb4;
case 0x0c080bb6u: goto P_0c080bb6;
case 0x0c080bb8u: goto P_0c080bb8;
case 0x0c080bbau: goto P_0c080bba;
case 0x0c080bbcu: goto P_0c080bbc;
case 0x0c080bbeu: goto P_0c080bbe;
case 0x0c080bc0u: goto P_0c080bc0;
case 0x0c080bc2u: goto P_0c080bc2;
case 0x0c080bc4u: goto P_0c080bc4;
case 0x0c080bc6u: goto P_0c080bc6;
case 0x0c080bc8u: goto P_0c080bc8;
case 0x0c080bcau: goto P_0c080bca;
case 0x0c080bccu: goto P_0c080bcc;
case 0x0c080bceu: goto P_0c080bce;
case 0x0c080bd0u: goto P_0c080bd0;
case 0x0c080bd2u: goto P_0c080bd2;
case 0x0c080bd4u: goto P_0c080bd4;
case 0x0c080bd6u: goto P_0c080bd6;
case 0x0c080bd8u: goto P_0c080bd8;
case 0x0c080bdau: goto P_0c080bda;
case 0x0c080bdcu: goto P_0c080bdc;
case 0x0c080bdeu: goto P_0c080bde;
case 0x0c080be0u: goto P_0c080be0;
case 0x0c080be2u: goto P_0c080be2;
case 0x0c080be4u: goto P_0c080be4;
case 0x0c080be6u: goto P_0c080be6;
case 0x0c080be8u: goto P_0c080be8;
case 0x0c080beau: goto P_0c080bea;
case 0x0c080becu: goto P_0c080bec;
case 0x0c080beeu: goto P_0c080bee;
case 0x0c080bf0u: goto P_0c080bf0;
case 0x0c080bf2u: goto P_0c080bf2;
case 0x0c080bf4u: goto P_0c080bf4;
case 0x0c080bf6u: goto P_0c080bf6;
case 0x0c080bf8u: goto P_0c080bf8;
case 0x0c080bfau: goto P_0c080bfa;
case 0x0c080bfcu: goto P_0c080bfc;
case 0x0c080bfeu: goto P_0c080bfe;
case 0x0c080c00u: goto P_0c080c00;
case 0x0c080c02u: goto P_0c080c02;
case 0x0c080c04u: goto P_0c080c04;
case 0x0c080c06u: goto P_0c080c06;
case 0x0c080c08u: goto P_0c080c08;
case 0x0c080c0au: goto P_0c080c0a;
case 0x0c080c0cu: goto P_0c080c0c;
case 0x0c080c0eu: goto P_0c080c0e;
case 0x0c080c10u: goto P_0c080c10;
case 0x0c080c12u: goto P_0c080c12;
case 0x0c080c14u: goto P_0c080c14;
case 0x0c080c16u: goto P_0c080c16;
case 0x0c080c18u: goto P_0c080c18;
case 0x0c080c1au: goto P_0c080c1a;
case 0x0c080c1cu: goto P_0c080c1c;
case 0x0c080c1eu: goto P_0c080c1e;
case 0x0c080c20u: goto P_0c080c20;
case 0x0c080c22u: goto P_0c080c22;
case 0x0c080c24u: goto P_0c080c24;
case 0x0c080c26u: goto P_0c080c26;
case 0x0c080c28u: goto P_0c080c28;
case 0x0c080c2au: goto P_0c080c2a;
case 0x0c080c2cu: goto P_0c080c2c;
case 0x0c080c2eu: goto P_0c080c2e;
case 0x0c080c30u: goto P_0c080c30;
case 0x0c080c32u: goto P_0c080c32;
case 0x0c080c34u: goto P_0c080c34;
case 0x0c080c36u: goto P_0c080c36;
case 0x0c080c38u: goto P_0c080c38;
case 0x0c080c3au: goto P_0c080c3a;
case 0x0c080c3cu: goto P_0c080c3c;
case 0x0c080c3eu: goto P_0c080c3e;
case 0x0c080c40u: goto P_0c080c40;
case 0x0c080c42u: goto P_0c080c42;
case 0x0c080c44u: goto P_0c080c44;
case 0x0c080c46u: goto P_0c080c46;
case 0x0c080c48u: goto P_0c080c48;
case 0x0c080c4au: goto P_0c080c4a;
case 0x0c080d14u: goto P_0c080d14;
case 0x0c080d16u: goto P_0c080d16;
case 0x0c080d18u: goto P_0c080d18;
case 0x0c080d1au: goto P_0c080d1a;
case 0x0c080d1cu: goto P_0c080d1c;
case 0x0c080d1eu: goto P_0c080d1e;
case 0x0c080d20u: goto P_0c080d20;
case 0x0c080d22u: goto P_0c080d22;
case 0x0c080d24u: goto P_0c080d24;
case 0x0c080d26u: goto P_0c080d26;
case 0x0c080d28u: goto P_0c080d28;
case 0x0c080d2au: goto P_0c080d2a;
case 0x0c089ab2u: goto P_0c089ab2;
case 0x0c089ab4u: goto P_0c089ab4;
case 0x0c089ab6u: goto P_0c089ab6;
case 0x0c089ab8u: goto P_0c089ab8;
case 0x0c089abau: goto P_0c089aba;
case 0x0c089abcu: goto P_0c089abc;
case 0x0c089abeu: goto P_0c089abe;
case 0x0c089ac0u: goto P_0c089ac0;
case 0x0c089ac2u: goto P_0c089ac2;
case 0x0c089ac4u: goto P_0c089ac4;
case 0x0c089ac6u: goto P_0c089ac6;
case 0x0c089ac8u: goto P_0c089ac8;
case 0x0c089acau: goto P_0c089aca;
case 0x0c089accu: goto P_0c089acc;
case 0x0c089aceu: goto P_0c089ace;
case 0x0c089ad0u: goto P_0c089ad0;
case 0x0c089ad2u: goto P_0c089ad2;
case 0x0c089ad4u: goto P_0c089ad4;
case 0x0c089ad6u: goto P_0c089ad6;
case 0x0c089ad8u: goto P_0c089ad8;
case 0x0c089adau: goto P_0c089ada;
case 0x0c089adcu: goto P_0c089adc;
case 0x0c089adeu: goto P_0c089ade;
case 0x0c089ae0u: goto P_0c089ae0;
case 0x0c089ae2u: goto P_0c089ae2;
case 0x0c089ae4u: goto P_0c089ae4;
case 0x0c089ae6u: goto P_0c089ae6;
case 0x0c089ae8u: goto P_0c089ae8;
case 0x0c089aeau: goto P_0c089aea;
case 0x0c089aecu: goto P_0c089aec;
case 0x0c089aeeu: goto P_0c089aee;
case 0x0c089af0u: goto P_0c089af0;
case 0x0c089af2u: goto P_0c089af2;
case 0x0c089af4u: goto P_0c089af4;
case 0x0c089af6u: goto P_0c089af6;
case 0x0c089af8u: goto P_0c089af8;
case 0x0c089afau: goto P_0c089afa;
case 0x0c089afcu: goto P_0c089afc;
case 0x0c089afeu: goto P_0c089afe;
case 0x0c089b00u: goto P_0c089b00;
case 0x0c089b02u: goto P_0c089b02;
case 0x0c089b04u: goto P_0c089b04;
case 0x0c089b06u: goto P_0c089b06;
case 0x0c089b08u: goto P_0c089b08;
case 0x0c089b0au: goto P_0c089b0a;
case 0x0c089b0cu: goto P_0c089b0c;
case 0x0c089b0eu: goto P_0c089b0e;
case 0x0c089b10u: goto P_0c089b10;
case 0x0c089b12u: goto P_0c089b12;
case 0x0c089b14u: goto P_0c089b14;
case 0x0c089b16u: goto P_0c089b16;
case 0x0c089b18u: goto P_0c089b18;
case 0x0c089b1au: goto P_0c089b1a;
case 0x0c089b1cu: goto P_0c089b1c;
case 0x0c0c66c0u: goto P_0c0c66c0;
case 0x0c0c66c2u: goto P_0c0c66c2;
case 0x0c0c7fbcu: goto P_0c0c7fbc;
case 0x0c0c7fbeu: goto P_0c0c7fbe;
case 0x0c0c7fc0u: goto P_0c0c7fc0;
case 0x0c0c7fc2u: goto P_0c0c7fc2;
case 0x0c0c7fc4u: goto P_0c0c7fc4;
case 0x0c0c7fc6u: goto P_0c0c7fc6;
case 0x0c0c7fc8u: goto P_0c0c7fc8;
case 0x0c0c7fcau: goto P_0c0c7fca;
case 0x0c0c7fccu: goto P_0c0c7fcc;
case 0x0c0c7fceu: goto P_0c0c7fce;
case 0x0c0c7fd0u: goto P_0c0c7fd0;
case 0x0c0c7fd2u: goto P_0c0c7fd2;
case 0x0c0c7fd4u: goto P_0c0c7fd4;
case 0x0c0c7fd6u: goto P_0c0c7fd6;
case 0x0c0c7fd8u: goto P_0c0c7fd8;
case 0x0c0c7fdau: goto P_0c0c7fda;
case 0x0c0c7fdcu: goto P_0c0c7fdc;
case 0x0c0c7fdeu: goto P_0c0c7fde;
case 0x0c0c7fe0u: goto P_0c0c7fe0;
case 0x0c0c7fe2u: goto P_0c0c7fe2;
case 0x0c0c7fe4u: goto P_0c0c7fe4;
case 0x0c0c7fe6u: goto P_0c0c7fe6;
case 0x0c0c7fe8u: goto P_0c0c7fe8;
case 0x0c0c7feau: goto P_0c0c7fea;
case 0x0c0c7fecu: goto P_0c0c7fec;
case 0x0c0c7feeu: goto P_0c0c7fee;
case 0x0c0c7ff0u: goto P_0c0c7ff0;
case 0x0c0c7ff2u: goto P_0c0c7ff2;
case 0x0c0c7ff4u: goto P_0c0c7ff4;
case 0x0c0c7ff6u: goto P_0c0c7ff6;
case 0x0c0c7ff8u: goto P_0c0c7ff8;
case 0x0c0c7ffau: goto P_0c0c7ffa;
case 0x0c0c7ffcu: goto P_0c0c7ffc;
case 0x0c0c7ffeu: goto P_0c0c7ffe;
case 0x0c0c8000u: goto P_0c0c8000;
case 0x0c0c8002u: goto P_0c0c8002;
case 0x0c0c8004u: goto P_0c0c8004;
case 0x0c0c8006u: goto P_0c0c8006;
case 0x0c0c8008u: goto P_0c0c8008;
case 0x0c0c800au: goto P_0c0c800a;
case 0x0c0c800cu: goto P_0c0c800c;
case 0x0c0c800eu: goto P_0c0c800e;
case 0x0c0c8010u: goto P_0c0c8010;
case 0x0c0c8012u: goto P_0c0c8012;
case 0x0c0c8014u: goto P_0c0c8014;
case 0x0c0c8016u: goto P_0c0c8016;
case 0x0c0c8018u: goto P_0c0c8018;
case 0x0c0c801au: goto P_0c0c801a;
case 0x0c0c801cu: goto P_0c0c801c;
case 0x0c0c801eu: goto P_0c0c801e;
case 0x0c0c8020u: goto P_0c0c8020;
case 0x0c0c8022u: goto P_0c0c8022;
case 0x0c0c8024u: goto P_0c0c8024;
case 0x0c0c8026u: goto P_0c0c8026;
case 0x0c0c8028u: goto P_0c0c8028;
case 0x0c0c802au: goto P_0c0c802a;
case 0x0c0c802cu: goto P_0c0c802c;
case 0x0c0c802eu: goto P_0c0c802e;
case 0x0c0c8030u: goto P_0c0c8030;
case 0x0c0c8032u: goto P_0c0c8032;
case 0x0c0c8034u: goto P_0c0c8034;
case 0x0c0c8036u: goto P_0c0c8036;
case 0x0c0c8038u: goto P_0c0c8038;
case 0x0c0c803au: goto P_0c0c803a;
case 0x0c0c803cu: goto P_0c0c803c;
case 0x0c0c803eu: goto P_0c0c803e;
case 0x0c0c8040u: goto P_0c0c8040;
case 0x0c0c8042u: goto P_0c0c8042;
case 0x0c0c8044u: goto P_0c0c8044;
case 0x0c0c8046u: goto P_0c0c8046;
case 0x0c0c8048u: goto P_0c0c8048;
case 0x0c0c804au: goto P_0c0c804a;
case 0x0c0c804cu: goto P_0c0c804c;
case 0x0c0c804eu: goto P_0c0c804e;
case 0x0c0c8050u: goto P_0c0c8050;
case 0x0c0c8052u: goto P_0c0c8052;
case 0x0c0c8054u: goto P_0c0c8054;
case 0x0c0c8056u: goto P_0c0c8056;
case 0x0c0c8058u: goto P_0c0c8058;
case 0x0c0c805au: goto P_0c0c805a;
default: return vf3_matrix_family(target,s,ram);
}
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
return vf3_matrix_family(0x0c03ccfcu,s,ram);
P_0c06c63a: /* original 4f22, guest PC 0x0c06c63a */
if(!s->budget--) { s->failed_pc=0x0c06c63au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c63c;
P_0c06c63c: /* original e101, guest PC 0x0c06c63c */
if(!s->budget--) { s->failed_pc=0x0c06c63cu; return 0; }
r[1]=0x00000001u;
goto P_0c06c63e;
P_0c06c63e: /* original 6e53, guest PC 0x0c06c63e */
if(!s->budget--) { s->failed_pc=0x0c06c63eu; return 0; }
r[14]=r[5];
goto P_0c06c640;
P_0c06c640: /* original 7ff8, guest PC 0x0c06c640 */
if(!s->budget--) { s->failed_pc=0x0c06c640u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c642;
P_0c06c642: /* original 2f62, guest PC 0x0c06c642 */
if(!s->budget--) { s->failed_pc=0x0c06c642u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c06c644;
P_0c06c644: /* original 6643, guest PC 0x0c06c644 */
if(!s->budget--) { s->failed_pc=0x0c06c644u; return 0; }
r[6]=r[4];
goto P_0c06c646;
P_0c06c646: /* original d326, guest PC 0x0c06c646 */
if(!s->budget--) { s->failed_pc=0x0c06c646u; return 0; }
r[3]=read(ram,0x0c06c6e0u,4);
goto P_0c06c648;
P_0c06c648: /* original 1f31, guest PC 0x0c06c648 */
if(!s->budget--) { s->failed_pc=0x0c06c648u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06c64a;
P_0c06c64a: /* original e307, guest PC 0x0c06c64a */
if(!s->budget--) { s->failed_pc=0x0c06c64au; return 0; }
r[3]=0x00000007u;
goto P_0c06c64c;
P_0c06c64c: /* original d228, guest PC 0x0c06c64c */
if(!s->budget--) { s->failed_pc=0x0c06c64cu; return 0; }
r[2]=read(ram,0x0c06c6f0u,4);
goto P_0c06c64e;
P_0c06c64e: /* original 4e3d, guest PC 0x0c06c64e */
if(!s->budget--) { s->failed_pc=0x0c06c64eu; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?r[14]>>((-r[3])&31u):0):r[14]<<(r[3]&31u);
goto P_0c06c650;
P_0c06c650: /* original 6422, guest PC 0x0c06c650 */
if(!s->budget--) { s->failed_pc=0x0c06c650u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c652;
P_0c06c652: /* original 3416, guest PC 0x0c06c652 */
if(!s->budget--) { s->failed_pc=0x0c06c652u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[1])!=0);
goto P_0c06c654;
P_0c06c654: /* original 8d03, guest PC 0x0c06c654 */
if(!s->budget--) { s->failed_pc=0x0c06c654u; return 0; }
cond=r[17]&1u;
r[6]|=r[14];
if(cond) { goto P_0c06c65e; }
goto P_0c06c658;
P_0c06c656: /* original 26eb, guest PC 0x0c06c656 */
if(!s->budget--) { s->failed_pc=0x0c06c656u; return 0; }
r[6]|=r[14];
goto P_0c06c658;
P_0c06c658: /* original d526, guest PC 0x0c06c658 */
if(!s->budget--) { s->failed_pc=0x0c06c658u; return 0; }
r[5]=read(ram,0x0c06c6f4u,4);
goto P_0c06c65a;
P_0c06c65a: /* original a001, guest PC 0x0c06c65a */
if(!s->budget--) { s->failed_pc=0x0c06c65au; return 0; }
goto P_0c06c660;
P_0c06c65c: /* original 0009, guest PC 0x0c06c65c */
if(!s->budget--) { s->failed_pc=0x0c06c65cu; return 0; }
goto P_0c06c65e;
P_0c06c65e: /* original d526, guest PC 0x0c06c65e */
if(!s->budget--) { s->failed_pc=0x0c06c65eu; return 0; }
r[5]=read(ram,0x0c06c6f8u,4);
goto P_0c06c660;
P_0c06c660: /* original b023, guest PC 0x0c06c660 */
if(!s->budget--) { s->failed_pc=0x0c06c660u; return 0; }
target=0x0c06c6aau; r[16]=0x0c06c664u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c664u) { target=s->pc; goto dispatch; }
goto P_0c06c664;
P_0c06c662: /* original 0009, guest PC 0x0c06c662 */
if(!s->budget--) { s->failed_pc=0x0c06c662u; return 0; }
goto P_0c06c664;
P_0c06c664: /* original d225, guest PC 0x0c06c664 */
if(!s->budget--) { s->failed_pc=0x0c06c664u; return 0; }
r[2]=read(ram,0x0c06c6fcu,4);
goto P_0c06c666;
P_0c06c666: /* original d326, guest PC 0x0c06c666 */
if(!s->budget--) { s->failed_pc=0x0c06c666u; return 0; }
r[3]=read(ram,0x0c06c700u,4);
goto P_0c06c668;
P_0c06c668: /* original 6422, guest PC 0x0c06c668 */
if(!s->budget--) { s->failed_pc=0x0c06c668u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c66a;
P_0c06c66a: /* original 2438, guest PC 0x0c06c66a */
if(!s->budget--) { s->failed_pc=0x0c06c66au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06c66c;
P_0c06c66c: /* original 8b0e, guest PC 0x0c06c66c */
if(!s->budget--) { s->failed_pc=0x0c06c66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c68c; }
goto P_0c06c66e;
P_0c06c66e: /* original d125, guest PC 0x0c06c66e */
if(!s->budget--) { s->failed_pc=0x0c06c66eu; return 0; }
r[1]=read(ram,0x0c06c704u,4);
goto P_0c06c670;
P_0c06c670: /* original 6010, guest PC 0x0c06c670 */
if(!s->budget--) { s->failed_pc=0x0c06c670u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c06c672;
P_0c06c672: /* original 600c, guest PC 0x0c06c672 */
if(!s->budget--) { s->failed_pc=0x0c06c672u; return 0; }
r[0]=r[0]&255u;
goto P_0c06c674;
P_0c06c674: /* original 8803, guest PC 0x0c06c674 */
if(!s->budget--) { s->failed_pc=0x0c06c674u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c676;
P_0c06c676: /* original 8b14, guest PC 0x0c06c676 */
if(!s->budget--) { s->failed_pc=0x0c06c676u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c6a2; }
goto P_0c06c678;
P_0c06c678: /* original 64f2, guest PC 0x0c06c678 */
if(!s->budget--) { s->failed_pc=0x0c06c678u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c67a;
P_0c06c67a: /* original d523, guest PC 0x0c06c67a */
if(!s->budget--) { s->failed_pc=0x0c06c67au; return 0; }
r[5]=read(ram,0x0c06c708u,4);
goto P_0c06c67c;
P_0c06c67c: /* original 7403, guest PC 0x0c06c67c */
if(!s->budget--) { s->failed_pc=0x0c06c67cu; return 0; }
r[4]+=0x00000003u;
goto P_0c06c67e;
P_0c06c67e: /* original d223, guest PC 0x0c06c67e */
if(!s->budget--) { s->failed_pc=0x0c06c67eu; return 0; }
r[2]=read(ram,0x0c06c70cu,4);
goto P_0c06c680;
P_0c06c680: /* original 4400, guest PC 0x0c06c680 */
if(!s->budget--) { s->failed_pc=0x0c06c680u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c682;
P_0c06c682: /* original 24eb, guest PC 0x0c06c682 */
if(!s->budget--) { s->failed_pc=0x0c06c682u; return 0; }
r[4]|=r[14];
goto P_0c06c684;
P_0c06c684: /* original 420b, guest PC 0x0c06c684 */
if(!s->budget--) { s->failed_pc=0x0c06c684u; return 0; }
target=r[2];
r[16]=0x0c06c688u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c688u) { target=s->pc; goto dispatch; }
goto P_0c06c688;
P_0c06c686: /* original e601, guest PC 0x0c06c686 */
if(!s->budget--) { s->failed_pc=0x0c06c686u; return 0; }
r[6]=0x00000001u;
goto P_0c06c688;
P_0c06c688: /* original a00b, guest PC 0x0c06c688 */
if(!s->budget--) { s->failed_pc=0x0c06c688u; return 0; }
goto P_0c06c6a2;
P_0c06c68a: /* original 0009, guest PC 0x0c06c68a */
if(!s->budget--) { s->failed_pc=0x0c06c68au; return 0; }
goto P_0c06c68c;
P_0c06c68c: /* original 65f2, guest PC 0x0c06c68c */
if(!s->budget--) { s->failed_pc=0x0c06c68cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06c68e;
P_0c06c68e: /* original e120, guest PC 0x0c06c68e */
if(!s->budget--) { s->failed_pc=0x0c06c68eu; return 0; }
r[1]=0x00000020u;
goto P_0c06c690;
P_0c06c690: /* original e615, guest PC 0x0c06c690 */
if(!s->budget--) { s->failed_pc=0x0c06c690u; return 0; }
r[6]=0x00000015u;
goto P_0c06c692;
P_0c06c692: /* original 2f16, guest PC 0x0c06c692 */
if(!s->budget--) { s->failed_pc=0x0c06c692u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c694;
P_0c06c694: /* original d215, guest PC 0x0c06c694 */
if(!s->budget--) { s->failed_pc=0x0c06c694u; return 0; }
r[2]=read(ram,0x0c06c6ecu,4);
goto P_0c06c696;
P_0c06c696: /* original 4500, guest PC 0x0c06c696 */
if(!s->budget--) { s->failed_pc=0x0c06c696u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06c698;
P_0c06c698: /* original e701, guest PC 0x0c06c698 */
if(!s->budget--) { s->failed_pc=0x0c06c698u; return 0; }
r[7]=0x00000001u;
goto P_0c06c69a;
P_0c06c69a: /* original 25eb, guest PC 0x0c06c69a */
if(!s->budget--) { s->failed_pc=0x0c06c69au; return 0; }
r[5]|=r[14];
goto P_0c06c69c;
P_0c06c69c: /* original 420b, guest PC 0x0c06c69c */
if(!s->budget--) { s->failed_pc=0x0c06c69cu; return 0; }
target=r[2];
r[16]=0x0c06c6a0u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c6a0u) { target=s->pc; goto dispatch; }
goto P_0c06c6a0;
P_0c06c69e: /* original 54f2, guest PC 0x0c06c69e */
if(!s->budget--) { s->failed_pc=0x0c06c69eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06c6a0;
P_0c06c6a0: /* original 7f04, guest PC 0x0c06c6a0 */
if(!s->budget--) { s->failed_pc=0x0c06c6a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c6a2;
P_0c06c6a2: /* original 7f08, guest PC 0x0c06c6a2 */
if(!s->budget--) { s->failed_pc=0x0c06c6a2u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c6a4;
P_0c06c6a4: /* original 4f26, guest PC 0x0c06c6a4 */
if(!s->budget--) { s->failed_pc=0x0c06c6a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c6a6;
P_0c06c6a6: /* original 000b, guest PC 0x0c06c6a6 */
if(!s->budget--) { s->failed_pc=0x0c06c6a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c6a8: /* original 6ef6, guest PC 0x0c06c6a8 */
if(!s->budget--) { s->failed_pc=0x0c06c6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c6aau,s,ram);
P_0c07ed74: /* original 4f22, guest PC 0x0c07ed74 */
if(!s->budget--) { s->failed_pc=0x0c07ed74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ed76;
P_0c07ed76: /* original 4c3c, guest PC 0x0c07ed76 */
if(!s->budget--) { s->failed_pc=0x0c07ed76u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c07ed78;
P_0c07ed78: /* original 6723, guest PC 0x0c07ed78 */
if(!s->budget--) { s->failed_pc=0x0c07ed78u; return 0; }
r[7]=r[2];
goto P_0c07ed7a;
P_0c07ed7a: /* original 4e00, guest PC 0x0c07ed7a */
if(!s->budget--) { s->failed_pc=0x0c07ed7au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ed7c;
P_0c07ed7c: /* original 7ffc, guest PC 0x0c07ed7c */
if(!s->budget--) { s->failed_pc=0x0c07ed7cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ed7e;
P_0c07ed7e: /* original 2f42, guest PC 0x0c07ed7e */
if(!s->budget--) { s->failed_pc=0x0c07ed7eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07ed80;
P_0c07ed80: /* original 659d, guest PC 0x0c07ed80 */
if(!s->budget--) { s->failed_pc=0x0c07ed80u; return 0; }
r[5]=r[9]&65535u;
goto P_0c07ed82;
P_0c07ed82: /* original 814a, guest PC 0x0c07ed82 */
if(!s->budget--) { s->failed_pc=0x0c07ed82u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c07ed84;
P_0c07ed84: /* original 6063, guest PC 0x0c07ed84 */
if(!s->budget--) { s->failed_pc=0x0c07ed84u; return 0; }
r[0]=r[6];
goto P_0c07ed86;
P_0c07ed86: /* original 814b, guest PC 0x0c07ed86 */
if(!s->budget--) { s->failed_pc=0x0c07ed86u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c07ed88;
P_0c07ed88: /* original 6093, guest PC 0x0c07ed88 */
if(!s->budget--) { s->failed_pc=0x0c07ed88u; return 0; }
r[0]=r[9];
goto P_0c07ed8a;
P_0c07ed8a: /* original 814c, guest PC 0x0c07ed8a */
if(!s->budget--) { s->failed_pc=0x0c07ed8au; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c07ed8c;
P_0c07ed8c: /* original 2ecb, guest PC 0x0c07ed8c */
if(!s->budget--) { s->failed_pc=0x0c07ed8cu; return 0; }
r[14]|=r[12];
goto P_0c07ed8e;
P_0c07ed8e: /* original da39, guest PC 0x0c07ed8e */
if(!s->budget--) { s->failed_pc=0x0c07ed8eu; return 0; }
r[10]=read(ram,0x0c07ee74u,4);
goto P_0c07ed90;
P_0c07ed90: /* original d837, guest PC 0x0c07ed90 */
if(!s->budget--) { s->failed_pc=0x0c07ed90u; return 0; }
r[8]=read(ram,0x0c07ee70u,4);
goto P_0c07ed92;
P_0c07ed92: /* original 66a3, guest PC 0x0c07ed92 */
if(!s->budget--) { s->failed_pc=0x0c07ed92u; return 0; }
r[6]=r[10];
goto P_0c07ed94;
P_0c07ed94: /* original 2f26, guest PC 0x0c07ed94 */
if(!s->budget--) { s->failed_pc=0x0c07ed94u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed96;
P_0c07ed96: /* original 480b, guest PC 0x0c07ed96 */
if(!s->budget--) { s->failed_pc=0x0c07ed96u; return 0; }
target=r[8];
r[16]=0x0c07ed9au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ed9au) { target=s->pc; goto dispatch; }
goto P_0c07ed9a;
P_0c07ed98: /* original 64e3, guest PC 0x0c07ed98 */
if(!s->budget--) { s->failed_pc=0x0c07ed98u; return 0; }
r[4]=r[14];
goto P_0c07ed9a;
P_0c07ed9a: /* original 9361, guest PC 0x0c07ed9a */
if(!s->budget--) { s->failed_pc=0x0c07ed9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee60u,2);
goto P_0c07ed9c;
P_0c07ed9c: /* original 6d9f, guest PC 0x0c07ed9c */
if(!s->budget--) { s->failed_pc=0x0c07ed9cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c07ed9e;
P_0c07ed9e: /* original 3d30, guest PC 0x0c07ed9e */
if(!s->budget--) { s->failed_pc=0x0c07ed9eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c07eda0;
P_0c07eda0: /* original 8f0a, guest PC 0x0c07eda0 */
if(!s->budget--) { s->failed_pc=0x0c07eda0u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c07edb8; }
goto P_0c07eda4;
P_0c07eda2: /* original 7f04, guest PC 0x0c07eda2 */
if(!s->budget--) { s->failed_pc=0x0c07eda2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07eda4;
P_0c07eda4: /* original 6eb3, guest PC 0x0c07eda4 */
if(!s->budget--) { s->failed_pc=0x0c07eda4u; return 0; }
r[14]=r[11];
goto P_0c07eda6;
P_0c07eda6: /* original 7e0d, guest PC 0x0c07eda6 */
if(!s->budget--) { s->failed_pc=0x0c07eda6u; return 0; }
r[14]+=0x0000000du;
goto P_0c07eda8;
P_0c07eda8: /* original e200, guest PC 0x0c07eda8 */
if(!s->budget--) { s->failed_pc=0x0c07eda8u; return 0; }
r[2]=0x00000000u;
goto P_0c07edaa;
P_0c07edaa: /* original 4e00, guest PC 0x0c07edaa */
if(!s->budget--) { s->failed_pc=0x0c07edaau; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07edac;
P_0c07edac: /* original 6723, guest PC 0x0c07edac */
if(!s->budget--) { s->failed_pc=0x0c07edacu; return 0; }
r[7]=r[2];
goto P_0c07edae;
P_0c07edae: /* original 2ecb, guest PC 0x0c07edae */
if(!s->budget--) { s->failed_pc=0x0c07edaeu; return 0; }
r[14]|=r[12];
goto P_0c07edb0;
P_0c07edb0: /* original 2f26, guest PC 0x0c07edb0 */
if(!s->budget--) { s->failed_pc=0x0c07edb0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edb2;
P_0c07edb2: /* original 9556, guest PC 0x0c07edb2 */
if(!s->budget--) { s->failed_pc=0x0c07edb2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee62u,2);
goto P_0c07edb4;
P_0c07edb4: /* original a00c, guest PC 0x0c07edb4 */
if(!s->budget--) { s->failed_pc=0x0c07edb4u; return 0; }
r[6]=r[10];
goto P_0c07edd0;
P_0c07edb6: /* original 66a3, guest PC 0x0c07edb6 */
if(!s->budget--) { s->failed_pc=0x0c07edb6u; return 0; }
r[6]=r[10];
goto P_0c07edb8;
P_0c07edb8: /* original 9254, guest PC 0x0c07edb8 */
if(!s->budget--) { s->failed_pc=0x0c07edb8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee64u,2);
goto P_0c07edba;
P_0c07edba: /* original 3d20, guest PC 0x0c07edba */
if(!s->budget--) { s->failed_pc=0x0c07edbau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c07edbc;
P_0c07edbc: /* original 8b0c, guest PC 0x0c07edbc */
if(!s->budget--) { s->failed_pc=0x0c07edbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07edd8; }
goto P_0c07edbe;
P_0c07edbe: /* original 6eb3, guest PC 0x0c07edbe */
if(!s->budget--) { s->failed_pc=0x0c07edbeu; return 0; }
r[14]=r[11];
goto P_0c07edc0;
P_0c07edc0: /* original 7e0c, guest PC 0x0c07edc0 */
if(!s->budget--) { s->failed_pc=0x0c07edc0u; return 0; }
r[14]+=0x0000000cu;
goto P_0c07edc2;
P_0c07edc2: /* original e100, guest PC 0x0c07edc2 */
if(!s->budget--) { s->failed_pc=0x0c07edc2u; return 0; }
r[1]=0x00000000u;
goto P_0c07edc4;
P_0c07edc4: /* original 66a3, guest PC 0x0c07edc4 */
if(!s->budget--) { s->failed_pc=0x0c07edc4u; return 0; }
r[6]=r[10];
goto P_0c07edc6;
P_0c07edc6: /* original 4e00, guest PC 0x0c07edc6 */
if(!s->budget--) { s->failed_pc=0x0c07edc6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07edc8;
P_0c07edc8: /* original 6713, guest PC 0x0c07edc8 */
if(!s->budget--) { s->failed_pc=0x0c07edc8u; return 0; }
r[7]=r[1];
goto P_0c07edca;
P_0c07edca: /* original 2ecb, guest PC 0x0c07edca */
if(!s->budget--) { s->failed_pc=0x0c07edcau; return 0; }
r[14]|=r[12];
goto P_0c07edcc;
P_0c07edcc: /* original 2f16, guest PC 0x0c07edcc */
if(!s->budget--) { s->failed_pc=0x0c07edccu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edce;
P_0c07edce: /* original 954a, guest PC 0x0c07edce */
if(!s->budget--) { s->failed_pc=0x0c07edceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee66u,2);
goto P_0c07edd0;
P_0c07edd0: /* original 480b, guest PC 0x0c07edd0 */
if(!s->budget--) { s->failed_pc=0x0c07edd0u; return 0; }
target=r[8];
r[16]=0x0c07edd4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07edd4u) { target=s->pc; goto dispatch; }
goto P_0c07edd4;
P_0c07edd2: /* original 64e3, guest PC 0x0c07edd2 */
if(!s->budget--) { s->failed_pc=0x0c07edd2u; return 0; }
r[4]=r[14];
goto P_0c07edd4;
P_0c07edd4: /* original a00f, guest PC 0x0c07edd4 */
if(!s->budget--) { s->failed_pc=0x0c07edd4u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edf6;
P_0c07edd6: /* original 7f04, guest PC 0x0c07edd6 */
if(!s->budget--) { s->failed_pc=0x0c07edd6u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edd8;
P_0c07edd8: /* original 9146, guest PC 0x0c07edd8 */
if(!s->budget--) { s->failed_pc=0x0c07edd8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee68u,2);
goto P_0c07edda;
P_0c07edda: /* original 3d10, guest PC 0x0c07edda */
if(!s->budget--) { s->failed_pc=0x0c07eddau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c07eddc;
P_0c07eddc: /* original 8b0b, guest PC 0x0c07eddc */
if(!s->budget--) { s->failed_pc=0x0c07eddcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07edf6; }
goto P_0c07edde;
P_0c07edde: /* original 6eb3, guest PC 0x0c07edde */
if(!s->budget--) { s->failed_pc=0x0c07eddeu; return 0; }
r[14]=r[11];
goto P_0c07ede0;
P_0c07ede0: /* original 7e0c, guest PC 0x0c07ede0 */
if(!s->budget--) { s->failed_pc=0x0c07ede0u; return 0; }
r[14]+=0x0000000cu;
goto P_0c07ede2;
P_0c07ede2: /* original e300, guest PC 0x0c07ede2 */
if(!s->budget--) { s->failed_pc=0x0c07ede2u; return 0; }
r[3]=0x00000000u;
goto P_0c07ede4;
P_0c07ede4: /* original 66a3, guest PC 0x0c07ede4 */
if(!s->budget--) { s->failed_pc=0x0c07ede4u; return 0; }
r[6]=r[10];
goto P_0c07ede6;
P_0c07ede6: /* original 4e00, guest PC 0x0c07ede6 */
if(!s->budget--) { s->failed_pc=0x0c07ede6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ede8;
P_0c07ede8: /* original 6733, guest PC 0x0c07ede8 */
if(!s->budget--) { s->failed_pc=0x0c07ede8u; return 0; }
r[7]=r[3];
goto P_0c07edea;
P_0c07edea: /* original 2ecb, guest PC 0x0c07edea */
if(!s->budget--) { s->failed_pc=0x0c07edeau; return 0; }
r[14]|=r[12];
goto P_0c07edec;
P_0c07edec: /* original 2f36, guest PC 0x0c07edec */
if(!s->budget--) { s->failed_pc=0x0c07edecu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edee;
P_0c07edee: /* original 953c, guest PC 0x0c07edee */
if(!s->budget--) { s->failed_pc=0x0c07edeeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6au,2);
goto P_0c07edf0;
P_0c07edf0: /* original 480b, guest PC 0x0c07edf0 */
if(!s->budget--) { s->failed_pc=0x0c07edf0u; return 0; }
target=r[8];
r[16]=0x0c07edf4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07edf4u) { target=s->pc; goto dispatch; }
goto P_0c07edf4;
P_0c07edf2: /* original 64e3, guest PC 0x0c07edf2 */
if(!s->budget--) { s->failed_pc=0x0c07edf2u; return 0; }
r[4]=r[14];
goto P_0c07edf4;
P_0c07edf4: /* original 7f04, guest PC 0x0c07edf4 */
if(!s->budget--) { s->failed_pc=0x0c07edf4u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edf6;
P_0c07edf6: /* original d420, guest PC 0x0c07edf6 */
if(!s->budget--) { s->failed_pc=0x0c07edf6u; return 0; }
r[4]=read(ram,0x0c07ee78u,4);
goto P_0c07edf8;
P_0c07edf8: /* original e20f, guest PC 0x0c07edf8 */
if(!s->budget--) { s->failed_pc=0x0c07edf8u; return 0; }
r[2]=0x0000000fu;
goto P_0c07edfa;
P_0c07edfa: /* original 1425, guest PC 0x0c07edfa */
if(!s->budget--) { s->failed_pc=0x0c07edfau; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c07edfc;
P_0c07edfc: /* original 9330, guest PC 0x0c07edfc */
if(!s->budget--) { s->failed_pc=0x0c07edfcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee60u,2);
goto P_0c07edfe;
P_0c07edfe: /* original 3d30, guest PC 0x0c07edfe */
if(!s->budget--) { s->failed_pc=0x0c07edfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c07ee00;
P_0c07ee00: /* original 8908, guest PC 0x0c07ee00 */
if(!s->budget--) { s->failed_pc=0x0c07ee00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee02;
P_0c07ee02: /* original 9133, guest PC 0x0c07ee02 */
if(!s->budget--) { s->failed_pc=0x0c07ee02u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6cu,2);
goto P_0c07ee04;
P_0c07ee04: /* original 3d10, guest PC 0x0c07ee04 */
if(!s->budget--) { s->failed_pc=0x0c07ee04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c07ee06;
P_0c07ee06: /* original 8905, guest PC 0x0c07ee06 */
if(!s->budget--) { s->failed_pc=0x0c07ee06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee08;
P_0c07ee08: /* original 902e, guest PC 0x0c07ee08 */
if(!s->budget--) { s->failed_pc=0x0c07ee08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee68u,2);
goto P_0c07ee0a;
P_0c07ee0a: /* original 3d00, guest PC 0x0c07ee0a */
if(!s->budget--) { s->failed_pc=0x0c07ee0au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c07ee0c;
P_0c07ee0c: /* original 8902, guest PC 0x0c07ee0c */
if(!s->budget--) { s->failed_pc=0x0c07ee0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee0e;
P_0c07ee0e: /* original 922e, guest PC 0x0c07ee0e */
if(!s->budget--) { s->failed_pc=0x0c07ee0eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6eu,2);
goto P_0c07ee10;
P_0c07ee10: /* original 3d20, guest PC 0x0c07ee10 */
if(!s->budget--) { s->failed_pc=0x0c07ee10u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c07ee12;
P_0c07ee12: /* original 8b02, guest PC 0x0c07ee12 */
if(!s->budget--) { s->failed_pc=0x0c07ee12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ee1a; }
goto P_0c07ee14;
P_0c07ee14: /* original 5045, guest PC 0x0c07ee14 */
if(!s->budget--) { s->failed_pc=0x0c07ee14u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c07ee16;
P_0c07ee16: /* original cb80, guest PC 0x0c07ee16 */
if(!s->budget--) { s->failed_pc=0x0c07ee16u; return 0; }
r[0]|=128u;
goto P_0c07ee18;
P_0c07ee18: /* original 1405, guest PC 0x0c07ee18 */
if(!s->budget--) { s->failed_pc=0x0c07ee18u; return 0; }
write(ram,r[4]+20,r[0],4);
goto P_0c07ee1a;
P_0c07ee1a: /* original 64f2, guest PC 0x0c07ee1a */
if(!s->budget--) { s->failed_pc=0x0c07ee1au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07ee1c;
P_0c07ee1c: /* original 7f04, guest PC 0x0c07ee1c */
if(!s->budget--) { s->failed_pc=0x0c07ee1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c07ee1e;
P_0c07ee1e: /* original 4f26, guest PC 0x0c07ee1e */
if(!s->budget--) { s->failed_pc=0x0c07ee1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ee20;
P_0c07ee20: /* original d316, guest PC 0x0c07ee20 */
if(!s->budget--) { s->failed_pc=0x0c07ee20u; return 0; }
r[3]=read(ram,0x0c07ee7cu,4);
goto P_0c07ee22;
P_0c07ee22: /* original 65e3, guest PC 0x0c07ee22 */
if(!s->budget--) { s->failed_pc=0x0c07ee22u; return 0; }
r[5]=r[14];
goto P_0c07ee24;
P_0c07ee24: /* original 68f6, guest PC 0x0c07ee24 */
if(!s->budget--) { s->failed_pc=0x0c07ee24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07ee26;
P_0c07ee26: /* original 69f6, guest PC 0x0c07ee26 */
if(!s->budget--) { s->failed_pc=0x0c07ee26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07ee28;
P_0c07ee28: /* original 6af6, guest PC 0x0c07ee28 */
if(!s->budget--) { s->failed_pc=0x0c07ee28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07ee2a;
P_0c07ee2a: /* original 6bf6, guest PC 0x0c07ee2a */
if(!s->budget--) { s->failed_pc=0x0c07ee2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07ee2c;
P_0c07ee2c: /* original 6cf6, guest PC 0x0c07ee2c */
if(!s->budget--) { s->failed_pc=0x0c07ee2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ee2e;
P_0c07ee2e: /* original 6df6, guest PC 0x0c07ee2e */
if(!s->budget--) { s->failed_pc=0x0c07ee2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ee30;
P_0c07ee30: /* original 432b, guest PC 0x0c07ee30 */
if(!s->budget--) { s->failed_pc=0x0c07ee30u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c07ee32: /* original 6ef6, guest PC 0x0c07ee32 */
if(!s->budget--) { s->failed_pc=0x0c07ee32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ee34u,s,ram);
P_0c080b3c: /* original 2fe6, guest PC 0x0c080b3c */
if(!s->budget--) { s->failed_pc=0x0c080b3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b3e;
P_0c080b3e: /* original e2fa, guest PC 0x0c080b3e */
if(!s->budget--) { s->failed_pc=0x0c080b3eu; return 0; }
r[2]=0xfffffffau;
goto P_0c080b40;
P_0c080b40: /* original 2fd6, guest PC 0x0c080b40 */
if(!s->budget--) { s->failed_pc=0x0c080b40u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b42;
P_0c080b42: /* original e164, guest PC 0x0c080b42 */
if(!s->budget--) { s->failed_pc=0x0c080b42u; return 0; }
r[1]=0x00000064u;
goto P_0c080b44;
P_0c080b44: /* original 2fc6, guest PC 0x0c080b44 */
if(!s->budget--) { s->failed_pc=0x0c080b44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b46;
P_0c080b46: /* original e60a, guest PC 0x0c080b46 */
if(!s->budget--) { s->failed_pc=0x0c080b46u; return 0; }
r[6]=0x0000000au;
goto P_0c080b48;
P_0c080b48: /* original d346, guest PC 0x0c080b48 */
if(!s->budget--) { s->failed_pc=0x0c080b48u; return 0; }
r[3]=read(ram,0x0c080c64u,4);
goto P_0c080b4a;
P_0c080b4a: /* original 4f22, guest PC 0x0c080b4a */
if(!s->budget--) { s->failed_pc=0x0c080b4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080b4c;
P_0c080b4c: /* original 6432, guest PC 0x0c080b4c */
if(!s->budget--) { s->failed_pc=0x0c080b4cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c080b4e;
P_0c080b4e: /* original e3fa, guest PC 0x0c080b4e */
if(!s->budget--) { s->failed_pc=0x0c080b4eu; return 0; }
r[3]=0xfffffffau;
goto P_0c080b50;
P_0c080b50: /* original de43, guest PC 0x0c080b50 */
if(!s->budget--) { s->failed_pc=0x0c080b50u; return 0; }
r[14]=read(ram,0x0c080c60u,4);
goto P_0c080b52;
P_0c080b52: /* original 6543, guest PC 0x0c080b52 */
if(!s->budget--) { s->failed_pc=0x0c080b52u; return 0; }
r[5]=r[4];
goto P_0c080b54;
P_0c080b54: /* original 452c, guest PC 0x0c080b54 */
if(!s->budget--) { s->failed_pc=0x0c080b54u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c080b56;
P_0c080b56: /* original e23f, guest PC 0x0c080b56 */
if(!s->budget--) { s->failed_pc=0x0c080b56u; return 0; }
r[2]=0x0000003fu;
goto P_0c080b58;
P_0c080b58: /* original 2429, guest PC 0x0c080b58 */
if(!s->budget--) { s->failed_pc=0x0c080b58u; return 0; }
r[4]&=r[2];
goto P_0c080b5a;
P_0c080b5a: /* original 4f12, guest PC 0x0c080b5a */
if(!s->budget--) { s->failed_pc=0x0c080b5au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c080b5c;
P_0c080b5c: /* original 0417, guest PC 0x0c080b5c */
if(!s->budget--) { s->failed_pc=0x0c080b5cu; return 0; }
r[19]=r[4]*r[1];
goto P_0c080b5e;
P_0c080b5e: /* original 6153, guest PC 0x0c080b5e */
if(!s->budget--) { s->failed_pc=0x0c080b5eu; return 0; }
r[1]=r[5];
goto P_0c080b60;
P_0c080b60: /* original 7fec, guest PC 0x0c080b60 */
if(!s->budget--) { s->failed_pc=0x0c080b60u; return 0; }
r[15]+=0xffffffecu;
goto P_0c080b62;
P_0c080b62: /* original 1f52, guest PC 0x0c080b62 */
if(!s->budget--) { s->failed_pc=0x0c080b62u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c080b64;
P_0c080b64: /* original 041a, guest PC 0x0c080b64 */
if(!s->budget--) { s->failed_pc=0x0c080b64u; return 0; }
r[4]=r[19];
goto P_0c080b66;
P_0c080b66: /* original 443c, guest PC 0x0c080b66 */
if(!s->budget--) { s->failed_pc=0x0c080b66u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c080b68;
P_0c080b68: /* original d33f, guest PC 0x0c080b68 */
if(!s->budget--) { s->failed_pc=0x0c080b68u; return 0; }
r[3]=read(ram,0x0c080c68u,4);
goto P_0c080b6a;
P_0c080b6a: /* original 430b, guest PC 0x0c080b6a */
if(!s->budget--) { s->failed_pc=0x0c080b6au; return 0; }
target=r[3];
r[16]=0x0c080b6eu;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080b6eu) { target=s->pc; goto dispatch; }
goto P_0c080b6e;
P_0c080b6c: /* original 6063, guest PC 0x0c080b6c */
if(!s->budget--) { s->failed_pc=0x0c080b6cu; return 0; }
r[0]=r[6];
goto P_0c080b6e;
P_0c080b6e: /* original d33e, guest PC 0x0c080b6e */
if(!s->budget--) { s->failed_pc=0x0c080b6eu; return 0; }
r[3]=read(ram,0x0c080c68u,4);
goto P_0c080b70;
P_0c080b70: /* original 6143, guest PC 0x0c080b70 */
if(!s->budget--) { s->failed_pc=0x0c080b70u; return 0; }
r[1]=r[4];
goto P_0c080b72;
P_0c080b72: /* original 6c03, guest PC 0x0c080b72 */
if(!s->budget--) { s->failed_pc=0x0c080b72u; return 0; }
r[12]=r[0];
goto P_0c080b74;
P_0c080b74: /* original 430b, guest PC 0x0c080b74 */
if(!s->budget--) { s->failed_pc=0x0c080b74u; return 0; }
target=r[3];
r[16]=0x0c080b78u;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080b78u) { target=s->pc; goto dispatch; }
goto P_0c080b78;
P_0c080b76: /* original 6063, guest PC 0x0c080b76 */
if(!s->budget--) { s->failed_pc=0x0c080b76u; return 0; }
r[0]=r[6];
goto P_0c080b78;
P_0c080b78: /* original 61c3, guest PC 0x0c080b78 */
if(!s->budget--) { s->failed_pc=0x0c080b78u; return 0; }
r[1]=r[12];
goto P_0c080b7a;
P_0c080b7a: /* original 4108, guest PC 0x0c080b7a */
if(!s->budget--) { s->failed_pc=0x0c080b7au; return 0; }
r[1]<<=2;
goto P_0c080b7c;
P_0c080b7c: /* original 63c3, guest PC 0x0c080b7c */
if(!s->budget--) { s->failed_pc=0x0c080b7cu; return 0; }
r[3]=r[12];
goto P_0c080b7e;
P_0c080b7e: /* original 6603, guest PC 0x0c080b7e */
if(!s->budget--) { s->failed_pc=0x0c080b7eu; return 0; }
r[6]=r[0];
goto P_0c080b80;
P_0c080b80: /* original 6763, guest PC 0x0c080b80 */
if(!s->budget--) { s->failed_pc=0x0c080b80u; return 0; }
r[7]=r[6];
goto P_0c080b82;
P_0c080b82: /* original 313c, guest PC 0x0c080b82 */
if(!s->budget--) { s->failed_pc=0x0c080b82u; return 0; }
r[1]+=r[3];
goto P_0c080b84;
P_0c080b84: /* original 6363, guest PC 0x0c080b84 */
if(!s->budget--) { s->failed_pc=0x0c080b84u; return 0; }
r[3]=r[6];
goto P_0c080b86;
P_0c080b86: /* original 4708, guest PC 0x0c080b86 */
if(!s->budget--) { s->failed_pc=0x0c080b86u; return 0; }
r[7]<<=2;
goto P_0c080b88;
P_0c080b88: /* original 373c, guest PC 0x0c080b88 */
if(!s->budget--) { s->failed_pc=0x0c080b88u; return 0; }
r[7]+=r[3];
goto P_0c080b8a;
P_0c080b8a: /* original 4100, guest PC 0x0c080b8a */
if(!s->budget--) { s->failed_pc=0x0c080b8au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c080b8c;
P_0c080b8c: /* original 4700, guest PC 0x0c080b8c */
if(!s->budget--) { s->failed_pc=0x0c080b8cu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c080b8e;
P_0c080b8e: /* original 2f12, guest PC 0x0c080b8e */
if(!s->budget--) { s->failed_pc=0x0c080b8eu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c080b90;
P_0c080b90: /* original 3478, guest PC 0x0c080b90 */
if(!s->budget--) { s->failed_pc=0x0c080b90u; return 0; }
r[4]-=r[7];
goto P_0c080b92;
P_0c080b92: /* original 3518, guest PC 0x0c080b92 */
if(!s->budget--) { s->failed_pc=0x0c080b92u; return 0; }
r[5]-=r[1];
goto P_0c080b94;
P_0c080b94: /* original 1f51, guest PC 0x0c080b94 */
if(!s->budget--) { s->failed_pc=0x0c080b94u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c080b96;
P_0c080b96: /* original 1f64, guest PC 0x0c080b96 */
if(!s->budget--) { s->failed_pc=0x0c080b96u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c080b98;
P_0c080b98: /* original 1f43, guest PC 0x0c080b98 */
if(!s->budget--) { s->failed_pc=0x0c080b98u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c080b9a;
P_0c080b9a: /* original d334, guest PC 0x0c080b9a */
if(!s->budget--) { s->failed_pc=0x0c080b9au; return 0; }
r[3]=read(ram,0x0c080c6cu,4);
goto P_0c080b9c;
P_0c080b9c: /* original 9d56, guest PC 0x0c080b9c */
if(!s->budget--) { s->failed_pc=0x0c080b9cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c4cu,2);
goto P_0c080b9e;
P_0c080b9e: /* original 2f32, guest PC 0x0c080b9e */
if(!s->budget--) { s->failed_pc=0x0c080b9eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c080ba0;
P_0c080ba0: /* original 6433, guest PC 0x0c080ba0 */
if(!s->budget--) { s->failed_pc=0x0c080ba0u; return 0; }
r[4]=r[3];
goto P_0c080ba2;
P_0c080ba2: /* original d333, guest PC 0x0c080ba2 */
if(!s->budget--) { s->failed_pc=0x0c080ba2u; return 0; }
r[3]=read(ram,0x0c080c70u,4);
goto P_0c080ba4;
P_0c080ba4: /* original 430b, guest PC 0x0c080ba4 */
if(!s->budget--) { s->failed_pc=0x0c080ba4u; return 0; }
target=r[3];
r[16]=0x0c080ba8u;
r[4]+=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080ba8u) { target=s->pc; goto dispatch; }
goto P_0c080ba8;
P_0c080ba6: /* original 740a, guest PC 0x0c080ba6 */
if(!s->budget--) { s->failed_pc=0x0c080ba6u; return 0; }
r[4]+=0x0000000au;
goto P_0c080ba8;
P_0c080ba8: /* original 600d, guest PC 0x0c080ba8 */
if(!s->budget--) { s->failed_pc=0x0c080ba8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c080baa;
P_0c080baa: /* original 8803, guest PC 0x0c080baa */
if(!s->budget--) { s->failed_pc=0x0c080baau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c080bac;
P_0c080bac: /* original 8f01, guest PC 0x0c080bac */
if(!s->budget--) { s->failed_pc=0x0c080bacu; return 0; }
cond=r[17]&1u;
r[3]=0x00000000u;
if(!cond) { goto P_0c080bb2; }
goto P_0c080bb0;
P_0c080bae: /* original e300, guest PC 0x0c080bae */
if(!s->budget--) { s->failed_pc=0x0c080baeu; return 0; }
r[3]=0x00000000u;
goto P_0c080bb0;
P_0c080bb0: /* original 9d4d, guest PC 0x0c080bb0 */
if(!s->budget--) { s->failed_pc=0x0c080bb0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c4eu,2);
goto P_0c080bb2;
P_0c080bb2: /* original 66e3, guest PC 0x0c080bb2 */
if(!s->budget--) { s->failed_pc=0x0c080bb2u; return 0; }
r[6]=r[14];
goto P_0c080bb4;
P_0c080bb4: /* original 2f36, guest PC 0x0c080bb4 */
if(!s->budget--) { s->failed_pc=0x0c080bb4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080bb6;
P_0c080bb6: /* original 944b, guest PC 0x0c080bb6 */
if(!s->budget--) { s->failed_pc=0x0c080bb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c50u,2);
goto P_0c080bb8;
P_0c080bb8: /* original 6733, guest PC 0x0c080bb8 */
if(!s->budget--) { s->failed_pc=0x0c080bb8u; return 0; }
r[7]=r[3];
goto P_0c080bba;
P_0c080bba: /* original d22e, guest PC 0x0c080bba */
if(!s->budget--) { s->failed_pc=0x0c080bbau; return 0; }
r[2]=read(ram,0x0c080c74u,4);
goto P_0c080bbc;
P_0c080bbc: /* original 420b, guest PC 0x0c080bbc */
if(!s->budget--) { s->failed_pc=0x0c080bbcu; return 0; }
target=r[2];
r[16]=0x0c080bc0u;
r[5]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080bc0u) { target=s->pc; goto dispatch; }
goto P_0c080bc0;
P_0c080bbe: /* original 65d3, guest PC 0x0c080bbe */
if(!s->budget--) { s->failed_pc=0x0c080bbeu; return 0; }
r[5]=r[13];
goto P_0c080bc0;
P_0c080bc0: /* original d32a, guest PC 0x0c080bc0 */
if(!s->budget--) { s->failed_pc=0x0c080bc0u; return 0; }
r[3]=read(ram,0x0c080c6cu,4);
goto P_0c080bc2;
P_0c080bc2: /* original 7f04, guest PC 0x0c080bc2 */
if(!s->budget--) { s->failed_pc=0x0c080bc2u; return 0; }
r[15]+=0x00000004u;
goto P_0c080bc4;
P_0c080bc4: /* original 6433, guest PC 0x0c080bc4 */
if(!s->budget--) { s->failed_pc=0x0c080bc4u; return 0; }
r[4]=r[3];
goto P_0c080bc6;
P_0c080bc6: /* original 2f32, guest PC 0x0c080bc6 */
if(!s->budget--) { s->failed_pc=0x0c080bc6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c080bc8;
P_0c080bc8: /* original d329, guest PC 0x0c080bc8 */
if(!s->budget--) { s->failed_pc=0x0c080bc8u; return 0; }
r[3]=read(ram,0x0c080c70u,4);
goto P_0c080bca;
P_0c080bca: /* original 430b, guest PC 0x0c080bca */
if(!s->budget--) { s->failed_pc=0x0c080bcau; return 0; }
target=r[3];
r[16]=0x0c080bceu;
r[4]+=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080bceu) { target=s->pc; goto dispatch; }
goto P_0c080bce;
P_0c080bcc: /* original 740a, guest PC 0x0c080bcc */
if(!s->budget--) { s->failed_pc=0x0c080bccu; return 0; }
r[4]+=0x0000000au;
goto P_0c080bce;
P_0c080bce: /* original e203, guest PC 0x0c080bce */
if(!s->budget--) { s->failed_pc=0x0c080bceu; return 0; }
r[2]=0x00000003u;
goto P_0c080bd0;
P_0c080bd0: /* original 600d, guest PC 0x0c080bd0 */
if(!s->budget--) { s->failed_pc=0x0c080bd0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c080bd2;
P_0c080bd2: /* original 3023, guest PC 0x0c080bd2 */
if(!s->budget--) { s->failed_pc=0x0c080bd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[2])!=0);
goto P_0c080bd4;
P_0c080bd4: /* original 8933, guest PC 0x0c080bd4 */
if(!s->budget--) { s->failed_pc=0x0c080bd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c080c3e; }
goto P_0c080bd6;
P_0c080bd6: /* original d428, guest PC 0x0c080bd6 */
if(!s->budget--) { s->failed_pc=0x0c080bd6u; return 0; }
r[4]=read(ram,0x0c080c78u,4);
goto P_0c080bd8;
P_0c080bd8: /* original e208, guest PC 0x0c080bd8 */
if(!s->budget--) { s->failed_pc=0x0c080bd8u; return 0; }
r[2]=0x00000008u;
goto P_0c080bda;
P_0c080bda: /* original d328, guest PC 0x0c080bda */
if(!s->budget--) { s->failed_pc=0x0c080bdau; return 0; }
r[3]=read(ram,0x0c080c7cu,4);
goto P_0c080bdc;
P_0c080bdc: /* original 8448, guest PC 0x0c080bdc */
if(!s->budget--) { s->failed_pc=0x0c080bdcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c080bde;
P_0c080bde: /* original dd28, guest PC 0x0c080bde */
if(!s->budget--) { s->failed_pc=0x0c080bdeu; return 0; }
r[13]=read(ram,0x0c080c80u,4);
goto P_0c080be0;
P_0c080be0: /* original 650c, guest PC 0x0c080be0 */
if(!s->budget--) { s->failed_pc=0x0c080be0u; return 0; }
r[5]=r[0]&255u;
goto P_0c080be2;
P_0c080be2: /* original 8449, guest PC 0x0c080be2 */
if(!s->budget--) { s->failed_pc=0x0c080be2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c080be4;
P_0c080be4: /* original 6432, guest PC 0x0c080be4 */
if(!s->budget--) { s->failed_pc=0x0c080be4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c080be6;
P_0c080be6: /* original 2429, guest PC 0x0c080be6 */
if(!s->budget--) { s->failed_pc=0x0c080be6u; return 0; }
r[4]&=r[2];
goto P_0c080be8;
P_0c080be8: /* original 2448, guest PC 0x0c080be8 */
if(!s->budget--) { s->failed_pc=0x0c080be8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c080bea;
P_0c080bea: /* original 8f14, guest PC 0x0c080bea */
if(!s->budget--) { s->failed_pc=0x0c080beau; return 0; }
cond=r[17]&1u;
r[6]=r[0]&255u;
if(!cond) { goto P_0c080c16; }
goto P_0c080bee;
P_0c080bec: /* original 660c, guest PC 0x0c080bec */
if(!s->budget--) { s->failed_pc=0x0c080becu; return 0; }
r[6]=r[0]&255u;
goto P_0c080bee;
P_0c080bee: /* original 51f2, guest PC 0x0c080bee */
if(!s->budget--) { s->failed_pc=0x0c080beeu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c080bf0;
P_0c080bf0: /* original e006, guest PC 0x0c080bf0 */
if(!s->budget--) { s->failed_pc=0x0c080bf0u; return 0; }
r[0]=0x00000006u;
goto P_0c080bf2;
P_0c080bf2: /* original 3103, guest PC 0x0c080bf2 */
if(!s->budget--) { s->failed_pc=0x0c080bf2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[0])!=0);
goto P_0c080bf4;
P_0c080bf4: /* original 890f, guest PC 0x0c080bf4 */
if(!s->budget--) { s->failed_pc=0x0c080bf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c080c16; }
goto P_0c080bf6;
P_0c080bf6: /* original 6053, guest PC 0x0c080bf6 */
if(!s->budget--) { s->failed_pc=0x0c080bf6u; return 0; }
r[0]=r[5];
goto P_0c080bf8;
P_0c080bf8: /* original 8807, guest PC 0x0c080bf8 */
if(!s->budget--) { s->failed_pc=0x0c080bf8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c080bfa;
P_0c080bfa: /* original 8b0c, guest PC 0x0c080bfa */
if(!s->budget--) { s->failed_pc=0x0c080bfau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080c16; }
goto P_0c080bfc;
P_0c080bfc: /* original 6063, guest PC 0x0c080bfc */
if(!s->budget--) { s->failed_pc=0x0c080bfcu; return 0; }
r[0]=r[6];
goto P_0c080bfe;
P_0c080bfe: /* original 8809, guest PC 0x0c080bfe */
if(!s->budget--) { s->failed_pc=0x0c080bfeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c080c00;
P_0c080c00: /* original 8b09, guest PC 0x0c080c00 */
if(!s->budget--) { s->failed_pc=0x0c080c00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080c16; }
goto P_0c080c02;
P_0c080c02: /* original e220, guest PC 0x0c080c02 */
if(!s->budget--) { s->failed_pc=0x0c080c02u; return 0; }
r[2]=0x00000020u;
goto P_0c080c04;
P_0c080c04: /* original e604, guest PC 0x0c080c04 */
if(!s->budget--) { s->failed_pc=0x0c080c04u; return 0; }
r[6]=0x00000004u;
goto P_0c080c06;
P_0c080c06: /* original 2f26, guest PC 0x0c080c06 */
if(!s->budget--) { s->failed_pc=0x0c080c06u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080c08;
P_0c080c08: /* original 9523, guest PC 0x0c080c08 */
if(!s->budget--) { s->failed_pc=0x0c080c08u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c52u,2);
goto P_0c080c0a;
P_0c080c0a: /* original e703, guest PC 0x0c080c0a */
if(!s->budget--) { s->failed_pc=0x0c080c0au; return 0; }
r[7]=0x00000003u;
goto P_0c080c0c;
P_0c080c0c: /* original d31d, guest PC 0x0c080c0c */
if(!s->budget--) { s->failed_pc=0x0c080c0cu; return 0; }
r[3]=read(ram,0x0c080c84u,4);
goto P_0c080c0e;
P_0c080c0e: /* original 430b, guest PC 0x0c080c0e */
if(!s->budget--) { s->failed_pc=0x0c080c0eu; return 0; }
target=r[3];
r[16]=0x0c080c12u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080c12u) { target=s->pc; goto dispatch; }
goto P_0c080c12;
P_0c080c10: /* original 64e3, guest PC 0x0c080c10 */
if(!s->budget--) { s->failed_pc=0x0c080c10u; return 0; }
r[4]=r[14];
goto P_0c080c12;
P_0c080c12: /* original a00a, guest PC 0x0c080c12 */
if(!s->budget--) { s->failed_pc=0x0c080c12u; return 0; }
r[15]+=0x00000004u;
goto P_0c080c2a;
P_0c080c14: /* original 7f04, guest PC 0x0c080c14 */
if(!s->budget--) { s->failed_pc=0x0c080c14u; return 0; }
r[15]+=0x00000004u;
goto P_0c080c16;
P_0c080c16: /* original 951c, guest PC 0x0c080c16 */
if(!s->budget--) { s->failed_pc=0x0c080c16u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c52u,2);
goto P_0c080c18;
P_0c080c18: /* original 66c3, guest PC 0x0c080c18 */
if(!s->budget--) { s->failed_pc=0x0c080c18u; return 0; }
r[6]=r[12];
goto P_0c080c1a;
P_0c080c1a: /* original 971b, guest PC 0x0c080c1a */
if(!s->budget--) { s->failed_pc=0x0c080c1au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c54u,2);
goto P_0c080c1c;
P_0c080c1c: /* original 4d0b, guest PC 0x0c080c1c */
if(!s->budget--) { s->failed_pc=0x0c080c1cu; return 0; }
target=r[13];
r[16]=0x0c080c20u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080c20u) { target=s->pc; goto dispatch; }
goto P_0c080c20;
P_0c080c1e: /* original 64e3, guest PC 0x0c080c1e */
if(!s->budget--) { s->failed_pc=0x0c080c1eu; return 0; }
r[4]=r[14];
goto P_0c080c20;
P_0c080c20: /* original 9519, guest PC 0x0c080c20 */
if(!s->budget--) { s->failed_pc=0x0c080c20u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c56u,2);
goto P_0c080c22;
P_0c080c22: /* original 56f1, guest PC 0x0c080c22 */
if(!s->budget--) { s->failed_pc=0x0c080c22u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c080c24;
P_0c080c24: /* original 9716, guest PC 0x0c080c24 */
if(!s->budget--) { s->failed_pc=0x0c080c24u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c54u,2);
goto P_0c080c26;
P_0c080c26: /* original 4d0b, guest PC 0x0c080c26 */
if(!s->budget--) { s->failed_pc=0x0c080c26u; return 0; }
target=r[13];
r[16]=0x0c080c2au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080c2au) { target=s->pc; goto dispatch; }
goto P_0c080c2a;
P_0c080c28: /* original 64e3, guest PC 0x0c080c28 */
if(!s->budget--) { s->failed_pc=0x0c080c28u; return 0; }
r[4]=r[14];
goto P_0c080c2a;
P_0c080c2a: /* original 9516, guest PC 0x0c080c2a */
if(!s->budget--) { s->failed_pc=0x0c080c2au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c5au,2);
goto P_0c080c2c;
P_0c080c2c: /* original 56f4, guest PC 0x0c080c2c */
if(!s->budget--) { s->failed_pc=0x0c080c2cu; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c080c2e;
P_0c080c2e: /* original 9713, guest PC 0x0c080c2e */
if(!s->budget--) { s->failed_pc=0x0c080c2eu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c58u,2);
goto P_0c080c30;
P_0c080c30: /* original 4d0b, guest PC 0x0c080c30 */
if(!s->budget--) { s->failed_pc=0x0c080c30u; return 0; }
target=r[13];
r[16]=0x0c080c34u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080c34u) { target=s->pc; goto dispatch; }
goto P_0c080c34;
P_0c080c32: /* original 64e3, guest PC 0x0c080c32 */
if(!s->budget--) { s->failed_pc=0x0c080c32u; return 0; }
r[4]=r[14];
goto P_0c080c34;
P_0c080c34: /* original 9512, guest PC 0x0c080c34 */
if(!s->budget--) { s->failed_pc=0x0c080c34u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c5cu,2);
goto P_0c080c36;
P_0c080c36: /* original 56f3, guest PC 0x0c080c36 */
if(!s->budget--) { s->failed_pc=0x0c080c36u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c080c38;
P_0c080c38: /* original 970e, guest PC 0x0c080c38 */
if(!s->budget--) { s->failed_pc=0x0c080c38u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c58u,2);
goto P_0c080c3a;
P_0c080c3a: /* original 4d0b, guest PC 0x0c080c3a */
if(!s->budget--) { s->failed_pc=0x0c080c3au; return 0; }
target=r[13];
r[16]=0x0c080c3eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080c3eu) { target=s->pc; goto dispatch; }
goto P_0c080c3e;
P_0c080c3c: /* original 64e3, guest PC 0x0c080c3c */
if(!s->budget--) { s->failed_pc=0x0c080c3cu; return 0; }
r[4]=r[14];
goto P_0c080c3e;
P_0c080c3e: /* original 7f14, guest PC 0x0c080c3e */
if(!s->budget--) { s->failed_pc=0x0c080c3eu; return 0; }
r[15]+=0x00000014u;
goto P_0c080c40;
P_0c080c40: /* original 4f16, guest PC 0x0c080c40 */
if(!s->budget--) { s->failed_pc=0x0c080c40u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c080c42;
P_0c080c42: /* original 4f26, guest PC 0x0c080c42 */
if(!s->budget--) { s->failed_pc=0x0c080c42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080c44;
P_0c080c44: /* original 6cf6, guest PC 0x0c080c44 */
if(!s->budget--) { s->failed_pc=0x0c080c44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080c46;
P_0c080c46: /* original 6df6, guest PC 0x0c080c46 */
if(!s->budget--) { s->failed_pc=0x0c080c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080c48;
P_0c080c48: /* original 000b, guest PC 0x0c080c48 */
if(!s->budget--) { s->failed_pc=0x0c080c48u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080c4a: /* original 6ef6, guest PC 0x0c080c4a */
if(!s->budget--) { s->failed_pc=0x0c080c4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c080c4cu,s,ram);
P_0c080d14: /* original 2fe6, guest PC 0x0c080d14 */
if(!s->budget--) { s->failed_pc=0x0c080d14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d16;
P_0c080d16: /* original e01a, guest PC 0x0c080d16 */
if(!s->budget--) { s->failed_pc=0x0c080d16u; return 0; }
r[0]=0x0000001au;
goto P_0c080d18;
P_0c080d18: /* original 2fd6, guest PC 0x0c080d18 */
if(!s->budget--) { s->failed_pc=0x0c080d18u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d1a;
P_0c080d1a: /* original ee00, guest PC 0x0c080d1a */
if(!s->budget--) { s->failed_pc=0x0c080d1au; return 0; }
r[14]=0x00000000u;
goto P_0c080d1c;
P_0c080d1c: /* original 2fc6, guest PC 0x0c080d1c */
if(!s->budget--) { s->failed_pc=0x0c080d1cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d1e;
P_0c080d1e: /* original 2fb6, guest PC 0x0c080d1e */
if(!s->budget--) { s->failed_pc=0x0c080d1eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d20;
P_0c080d20: /* original 2fa6, guest PC 0x0c080d20 */
if(!s->budget--) { s->failed_pc=0x0c080d20u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d22;
P_0c080d22: /* original ea30, guest PC 0x0c080d22 */
if(!s->budget--) { s->failed_pc=0x0c080d22u; return 0; }
r[10]=0x00000030u;
goto P_0c080d24;
P_0c080d24: /* original 2f96, guest PC 0x0c080d24 */
if(!s->budget--) { s->failed_pc=0x0c080d24u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d26;
P_0c080d26: /* original e948, guest PC 0x0c080d26 */
if(!s->budget--) { s->failed_pc=0x0c080d26u; return 0; }
r[9]=0x00000048u;
goto P_0c080d28;
P_0c080d28: /* original 2f86, guest PC 0x0c080d28 */
if(!s->budget--) { s->failed_pc=0x0c080d28u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d2a;
P_0c080d2a: /* original e801, guest PC 0x0c080d2a */
if(!s->budget--) { s->failed_pc=0x0c080d2au; return 0; }
r[8]=0x00000001u;
return vf3_matrix_family(0x0c080d2cu,s,ram);
P_0c089ab2: /* original 4f22, guest PC 0x0c089ab2 */
if(!s->budget--) { s->failed_pc=0x0c089ab2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089ab4;
P_0c089ab4: /* original d31c, guest PC 0x0c089ab4 */
if(!s->budget--) { s->failed_pc=0x0c089ab4u; return 0; }
r[3]=read(ram,0x0c089b28u,4);
goto P_0c089ab6;
P_0c089ab6: /* original 430b, guest PC 0x0c089ab6 */
if(!s->budget--) { s->failed_pc=0x0c089ab6u; return 0; }
target=r[3];
r[16]=0x0c089abau;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089abau) { target=s->pc; goto dispatch; }
goto P_0c089aba;
P_0c089ab8: /* original e400, guest PC 0x0c089ab8 */
if(!s->budget--) { s->failed_pc=0x0c089ab8u; return 0; }
r[4]=0x00000000u;
goto P_0c089aba;
P_0c089aba: /* original d21c, guest PC 0x0c089aba */
if(!s->budget--) { s->failed_pc=0x0c089abau; return 0; }
r[2]=read(ram,0x0c089b2cu,4);
goto P_0c089abc;
P_0c089abc: /* original 420b, guest PC 0x0c089abc */
if(!s->budget--) { s->failed_pc=0x0c089abcu; return 0; }
target=r[2];
r[16]=0x0c089ac0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089ac0u) { target=s->pc; goto dispatch; }
goto P_0c089ac0;
P_0c089abe: /* original 0009, guest PC 0x0c089abe */
if(!s->budget--) { s->failed_pc=0x0c089abeu; return 0; }
goto P_0c089ac0;
P_0c089ac0: /* original da1d, guest PC 0x0c089ac0 */
if(!s->budget--) { s->failed_pc=0x0c089ac0u; return 0; }
r[10]=read(ram,0x0c089b38u,4);
goto P_0c089ac2;
P_0c089ac2: /* original ed20, guest PC 0x0c089ac2 */
if(!s->budget--) { s->failed_pc=0x0c089ac2u; return 0; }
r[13]=0x00000020u;
goto P_0c089ac4;
P_0c089ac4: /* original d91b, guest PC 0x0c089ac4 */
if(!s->budget--) { s->failed_pc=0x0c089ac4u; return 0; }
r[9]=read(ram,0x0c089b34u,4);
goto P_0c089ac6;
P_0c089ac6: /* original eb0f, guest PC 0x0c089ac6 */
if(!s->budget--) { s->failed_pc=0x0c089ac6u; return 0; }
r[11]=0x0000000fu;
goto P_0c089ac8;
P_0c089ac8: /* original d819, guest PC 0x0c089ac8 */
if(!s->budget--) { s->failed_pc=0x0c089ac8u; return 0; }
r[8]=read(ram,0x0c089b30u,4);
goto P_0c089aca;
P_0c089aca: /* original 84eb, guest PC 0x0c089aca */
if(!s->budget--) { s->failed_pc=0x0c089acau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c089acc;
P_0c089acc: /* original 64a3, guest PC 0x0c089acc */
if(!s->budget--) { s->failed_pc=0x0c089accu; return 0; }
r[4]=r[10];
goto P_0c089ace;
P_0c089ace: /* original 6603, guest PC 0x0c089ace */
if(!s->budget--) { s->failed_pc=0x0c089aceu; return 0; }
r[6]=r[0];
goto P_0c089ad0;
P_0c089ad0: /* original 666e, guest PC 0x0c089ad0 */
if(!s->budget--) { s->failed_pc=0x0c089ad0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c089ad2;
P_0c089ad2: /* original 2668, guest PC 0x0c089ad2 */
if(!s->budget--) { s->failed_pc=0x0c089ad2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c089ad4;
P_0c089ad4: /* original 8d06, guest PC 0x0c089ad4 */
if(!s->budget--) { s->failed_pc=0x0c089ad4u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
if(cond) { goto P_0c089ae4; }
goto P_0c089ad8;
P_0c089ad6: /* original 65e1, guest PC 0x0c089ad6 */
if(!s->budget--) { s->failed_pc=0x0c089ad6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
goto P_0c089ad8;
P_0c089ad8: /* original 85e4, guest PC 0x0c089ad8 */
if(!s->budget--) { s->failed_pc=0x0c089ad8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c089ada;
P_0c089ada: /* original d418, guest PC 0x0c089ada */
if(!s->budget--) { s->failed_pc=0x0c089adau; return 0; }
r[4]=read(ram,0x0c089b3cu,4);
goto P_0c089adc;
P_0c089adc: /* original 4015, guest PC 0x0c089adc */
if(!s->budget--) { s->failed_pc=0x0c089adcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c089ade;
P_0c089ade: /* original 8d01, guest PC 0x0c089ade */
if(!s->budget--) { s->failed_pc=0x0c089adeu; return 0; }
cond=r[17]&1u;
r[5]&=r[11];
if(cond) { goto P_0c089ae4; }
goto P_0c089ae2;
P_0c089ae0: /* original 25b9, guest PC 0x0c089ae0 */
if(!s->budget--) { s->failed_pc=0x0c089ae0u; return 0; }
r[5]&=r[11];
goto P_0c089ae2;
P_0c089ae2: /* original 6493, guest PC 0x0c089ae2 */
if(!s->budget--) { s->failed_pc=0x0c089ae2u; return 0; }
r[4]=r[9];
goto P_0c089ae4;
P_0c089ae4: /* original 6053, guest PC 0x0c089ae4 */
if(!s->budget--) { s->failed_pc=0x0c089ae4u; return 0; }
r[0]=r[5];
goto P_0c089ae6;
P_0c089ae6: /* original 4000, guest PC 0x0c089ae6 */
if(!s->budget--) { s->failed_pc=0x0c089ae6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c089ae8;
P_0c089ae8: /* original 480b, guest PC 0x0c089ae8 */
if(!s->budget--) { s->failed_pc=0x0c089ae8u; return 0; }
target=r[8];
r[16]=0x0c089aecu;
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089aecu) { target=s->pc; goto dispatch; }
goto P_0c089aec;
P_0c089aea: /* original 0c4d, guest PC 0x0c089aea */
if(!s->budget--) { s->failed_pc=0x0c089aeau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c089aec;
P_0c089aec: /* original d314, guest PC 0x0c089aec */
if(!s->budget--) { s->failed_pc=0x0c089aecu; return 0; }
r[3]=read(ram,0x0c089b40u,4);
goto P_0c089aee;
P_0c089aee: /* original 64e3, guest PC 0x0c089aee */
if(!s->budget--) { s->failed_pc=0x0c089aeeu; return 0; }
r[4]=r[14];
goto P_0c089af0;
P_0c089af0: /* original 430b, guest PC 0x0c089af0 */
if(!s->budget--) { s->failed_pc=0x0c089af0u; return 0; }
target=r[3];
r[16]=0x0c089af4u;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089af4u) { target=s->pc; goto dispatch; }
goto P_0c089af4;
P_0c089af2: /* original 740c, guest PC 0x0c089af2 */
if(!s->budget--) { s->failed_pc=0x0c089af2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c089af4;
P_0c089af4: /* original d313, guest PC 0x0c089af4 */
if(!s->budget--) { s->failed_pc=0x0c089af4u; return 0; }
r[3]=read(ram,0x0c089b44u,4);
goto P_0c089af6;
P_0c089af6: /* original 85e3, guest PC 0x0c089af6 */
if(!s->budget--) { s->failed_pc=0x0c089af6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c089af8;
P_0c089af8: /* original 430b, guest PC 0x0c089af8 */
if(!s->budget--) { s->failed_pc=0x0c089af8u; return 0; }
target=r[3];
r[16]=0x0c089afcu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089afcu) { target=s->pc; goto dispatch; }
goto P_0c089afc;
P_0c089afa: /* original 6403, guest PC 0x0c089afa */
if(!s->budget--) { s->failed_pc=0x0c089afau; return 0; }
r[4]=r[0];
goto P_0c089afc;
P_0c089afc: /* original d212, guest PC 0x0c089afc */
if(!s->budget--) { s->failed_pc=0x0c089afcu; return 0; }
r[2]=read(ram,0x0c089b48u,4);
goto P_0c089afe;
P_0c089afe: /* original 420b, guest PC 0x0c089afe */
if(!s->budget--) { s->failed_pc=0x0c089afeu; return 0; }
target=r[2];
r[16]=0x0c089b02u;
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089b02u) { target=s->pc; goto dispatch; }
goto P_0c089b02;
P_0c089b00: /* original 64cf, guest PC 0x0c089b00 */
if(!s->budget--) { s->failed_pc=0x0c089b00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c089b02;
P_0c089b02: /* original 4d10, guest PC 0x0c089b02 */
if(!s->budget--) { s->failed_pc=0x0c089b02u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c089b04;
P_0c089b04: /* original 8fe1, guest PC 0x0c089b04 */
if(!s->budget--) { s->failed_pc=0x0c089b04u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000028u;
if(!cond) { goto P_0c089aca; }
goto P_0c089b08;
P_0c089b06: /* original 7e28, guest PC 0x0c089b06 */
if(!s->budget--) { s->failed_pc=0x0c089b06u; return 0; }
r[14]+=0x00000028u;
goto P_0c089b08;
P_0c089b08: /* original 4f26, guest PC 0x0c089b08 */
if(!s->budget--) { s->failed_pc=0x0c089b08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089b0a;
P_0c089b0a: /* original d210, guest PC 0x0c089b0a */
if(!s->budget--) { s->failed_pc=0x0c089b0au; return 0; }
r[2]=read(ram,0x0c089b4cu,4);
goto P_0c089b0c;
P_0c089b0c: /* original e401, guest PC 0x0c089b0c */
if(!s->budget--) { s->failed_pc=0x0c089b0cu; return 0; }
r[4]=0x00000001u;
goto P_0c089b0e;
P_0c089b0e: /* original 68f6, guest PC 0x0c089b0e */
if(!s->budget--) { s->failed_pc=0x0c089b0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c089b10;
P_0c089b10: /* original 69f6, guest PC 0x0c089b10 */
if(!s->budget--) { s->failed_pc=0x0c089b10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089b12;
P_0c089b12: /* original 6af6, guest PC 0x0c089b12 */
if(!s->budget--) { s->failed_pc=0x0c089b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089b14;
P_0c089b14: /* original 6bf6, guest PC 0x0c089b14 */
if(!s->budget--) { s->failed_pc=0x0c089b14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089b16;
P_0c089b16: /* original 6cf6, guest PC 0x0c089b16 */
if(!s->budget--) { s->failed_pc=0x0c089b16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089b18;
P_0c089b18: /* original 6df6, guest PC 0x0c089b18 */
if(!s->budget--) { s->failed_pc=0x0c089b18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089b1a;
P_0c089b1a: /* original 422b, guest PC 0x0c089b1a */
if(!s->budget--) { s->failed_pc=0x0c089b1au; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c089b1c: /* original 6ef6, guest PC 0x0c089b1c */
if(!s->budget--) { s->failed_pc=0x0c089b1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089b1eu,s,ram);
P_0c0c66c0: /* original 000b, guest PC 0x0c0c66c0 */
if(!s->budget--) { s->failed_pc=0x0c0c66c0u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66c2: /* original 6041, guest PC 0x0c0c66c2 */
if(!s->budget--) { s->failed_pc=0x0c0c66c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
return vf3_matrix_family(0x0c0c66c4u,s,ram);
P_0c0c7fbc: /* original 4f22, guest PC 0x0c0c7fbc */
if(!s->budget--) { s->failed_pc=0x0c0c7fbcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7fbe;
P_0c0c7fbe: /* original d334, guest PC 0x0c0c7fbe */
if(!s->budget--) { s->failed_pc=0x0c0c7fbeu; return 0; }
r[3]=read(ram,0x0c0c8090u,4);
goto P_0c0c7fc0;
P_0c0c7fc0: /* original 7ff4, guest PC 0x0c0c7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fc0u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c7fc2;
P_0c0c7fc2: /* original 430b, guest PC 0x0c0c7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fc2u; return 0; }
target=r[3];
r[16]=0x0c0c7fc6u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7fc6u) { target=s->pc; goto dispatch; }
goto P_0c0c7fc6;
P_0c0c7fc4: /* original e400, guest PC 0x0c0c7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fc4u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7fc6;
P_0c0c7fc6: /* original 85df, guest PC 0x0c0c7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c7fc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+30,2);
goto P_0c0c7fc8;
P_0c0c7fc8: /* original e2f2, guest PC 0x0c0c7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c7fc8u; return 0; }
r[2]=0xfffffff2u;
goto P_0c0c7fca;
P_0c0c7fca: /* original 9348, guest PC 0x0c0c7fca */
if(!s->budget--) { s->failed_pc=0x0c0c7fcau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c805eu,2);
goto P_0c0c7fcc;
P_0c0c7fcc: /* original e103, guest PC 0x0c0c7fcc */
if(!s->budget--) { s->failed_pc=0x0c0c7fccu; return 0; }
r[1]=0x00000003u;
goto P_0c0c7fce;
P_0c0c7fce: /* original 6e03, guest PC 0x0c0c7fce */
if(!s->budget--) { s->failed_pc=0x0c0c7fceu; return 0; }
r[14]=r[0];
goto P_0c0c7fd0;
P_0c0c7fd0: /* original e010, guest PC 0x0c0c7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fd0u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7fd2;
P_0c0c7fd2: /* original f4d6, guest PC 0x0c0c7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fd2u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0c7fd4;
P_0c0c7fd4: /* original e018, guest PC 0x0c0c7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fd4u; return 0; }
r[0]=0x00000018u;
goto P_0c0c7fd6;
P_0c0c7fd6: /* original f5d6, guest PC 0x0c0c7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c7fd6u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0c7fd8;
P_0c0c7fd8: /* original 3e3c, guest PC 0x0c0c7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c7fd8u; return 0; }
r[14]+=r[3];
goto P_0c0c7fda;
P_0c0c7fda: /* original f43d, guest PC 0x0c0c7fda */
if(!s->budget--) { s->failed_pc=0x0c0c7fdau; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c7fdc;
P_0c0c7fdc: /* original 4e2c, guest PC 0x0c0c7fdc */
if(!s->budget--) { s->failed_pc=0x0c0c7fdcu; return 0; }
r[14]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[14]>>((-r[2])&31u)):((int32_t)r[14]<0?0xffffffffu:0)):r[14]<<(r[2]&31u);
goto P_0c0c7fde;
P_0c0c7fde: /* original 2e19, guest PC 0x0c0c7fde */
if(!s->budget--) { s->failed_pc=0x0c0c7fdeu; return 0; }
r[14]&=r[1];
goto P_0c0c7fe0;
P_0c0c7fe0: /* original e614, guest PC 0x0c0c7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fe0u; return 0; }
r[6]=0x00000014u;
goto P_0c0c7fe2;
P_0c0c7fe2: /* original 045a, guest PC 0x0c0c7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fe2u; return 0; }
r[4]=r[53];
goto P_0c0c7fe4;
P_0c0c7fe4: /* original f53d, guest PC 0x0c0c7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fe4u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c0c7fe6;
P_0c0c7fe6: /* original 055a, guest PC 0x0c0c7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c7fe6u; return 0; }
r[5]=r[53];
goto P_0c0c7fe8;
P_0c0c7fe8: /* original 2f42, guest PC 0x0c0c7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c7fe8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c7fea;
P_0c0c7fea: /* original 62f2, guest PC 0x0c0c7fea */
if(!s->budget--) { s->failed_pc=0x0c0c7feau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c7fec;
P_0c0c7fec: /* original 6753, guest PC 0x0c0c7fec */
if(!s->budget--) { s->failed_pc=0x0c0c7fecu; return 0; }
r[7]=r[5];
goto P_0c0c7fee;
P_0c0c7fee: /* original 4215, guest PC 0x0c0c7fee */
if(!s->budget--) { s->failed_pc=0x0c0c7feeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0c7ff0;
P_0c0c7ff0: /* original 8d01, guest PC 0x0c0c7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ff0u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000au;
if(cond) { goto P_0c0c7ff6; }
goto P_0c0c7ff4;
P_0c0c7ff2: /* original 740a, guest PC 0x0c0c7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ff2u; return 0; }
r[4]+=0x0000000au;
goto P_0c0c7ff4;
P_0c0c7ff4: /* original 74ec, guest PC 0x0c0c7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ff4u; return 0; }
r[4]+=0xffffffecu;
goto P_0c0c7ff6;
P_0c0c7ff6: /* original 4715, guest PC 0x0c0c7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ff6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0c7ff8;
P_0c0c7ff8: /* original 8d01, guest PC 0x0c0c7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ff8u; return 0; }
cond=r[17]&1u;
r[5]+=0x0000000au;
if(cond) { goto P_0c0c7ffe; }
goto P_0c0c7ffc;
P_0c0c7ffa: /* original 750a, guest PC 0x0c0c7ffa */
if(!s->budget--) { s->failed_pc=0x0c0c7ffau; return 0; }
r[5]+=0x0000000au;
goto P_0c0c7ffc;
P_0c0c7ffc: /* original 75ec, guest PC 0x0c0c7ffc */
if(!s->budget--) { s->failed_pc=0x0c0c7ffcu; return 0; }
r[5]+=0xffffffecu;
goto P_0c0c7ffe;
P_0c0c7ffe: /* original d225, guest PC 0x0c0c7ffe */
if(!s->budget--) { s->failed_pc=0x0c0c7ffeu; return 0; }
r[2]=read(ram,0x0c0c8094u,4);
goto P_0c0c8000;
P_0c0c8000: /* original 6143, guest PC 0x0c0c8000 */
if(!s->budget--) { s->failed_pc=0x0c0c8000u; return 0; }
r[1]=r[4];
goto P_0c0c8002;
P_0c0c8002: /* original 420b, guest PC 0x0c0c8002 */
if(!s->budget--) { s->failed_pc=0x0c0c8002u; return 0; }
target=r[2];
r[16]=0x0c0c8006u;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8006u) { target=s->pc; goto dispatch; }
goto P_0c0c8006;
P_0c0c8004: /* original 6063, guest PC 0x0c0c8004 */
if(!s->budget--) { s->failed_pc=0x0c0c8004u; return 0; }
r[0]=r[6];
goto P_0c0c8006;
P_0c0c8006: /* original 6303, guest PC 0x0c0c8006 */
if(!s->budget--) { s->failed_pc=0x0c0c8006u; return 0; }
r[3]=r[0];
goto P_0c0c8008;
P_0c0c8008: /* original 4008, guest PC 0x0c0c8008 */
if(!s->budget--) { s->failed_pc=0x0c0c8008u; return 0; }
r[0]<<=2;
goto P_0c0c800a;
P_0c0c800a: /* original 303c, guest PC 0x0c0c800a */
if(!s->budget--) { s->failed_pc=0x0c0c800au; return 0; }
r[0]+=r[3];
goto P_0c0c800c;
P_0c0c800c: /* original d221, guest PC 0x0c0c800c */
if(!s->budget--) { s->failed_pc=0x0c0c800cu; return 0; }
r[2]=read(ram,0x0c0c8094u,4);
goto P_0c0c800e;
P_0c0c800e: /* original 4008, guest PC 0x0c0c800e */
if(!s->budget--) { s->failed_pc=0x0c0c800eu; return 0; }
r[0]<<=2;
goto P_0c0c8010;
P_0c0c8010: /* original 6153, guest PC 0x0c0c8010 */
if(!s->budget--) { s->failed_pc=0x0c0c8010u; return 0; }
r[1]=r[5];
goto P_0c0c8012;
P_0c0c8012: /* original 6703, guest PC 0x0c0c8012 */
if(!s->budget--) { s->failed_pc=0x0c0c8012u; return 0; }
r[7]=r[0];
goto P_0c0c8014;
P_0c0c8014: /* original 420b, guest PC 0x0c0c8014 */
if(!s->budget--) { s->failed_pc=0x0c0c8014u; return 0; }
target=r[2];
r[16]=0x0c0c8018u;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8018u) { target=s->pc; goto dispatch; }
goto P_0c0c8018;
P_0c0c8016: /* original 6063, guest PC 0x0c0c8016 */
if(!s->budget--) { s->failed_pc=0x0c0c8016u; return 0; }
r[0]=r[6];
goto P_0c0c8018;
P_0c0c8018: /* original 6303, guest PC 0x0c0c8018 */
if(!s->budget--) { s->failed_pc=0x0c0c8018u; return 0; }
r[3]=r[0];
goto P_0c0c801a;
P_0c0c801a: /* original 475a, guest PC 0x0c0c801a */
if(!s->budget--) { s->failed_pc=0x0c0c801au; return 0; }
r[53]=r[7];
goto P_0c0c801c;
P_0c0c801c: /* original 4008, guest PC 0x0c0c801c */
if(!s->budget--) { s->failed_pc=0x0c0c801cu; return 0; }
r[0]<<=2;
goto P_0c0c801e;
P_0c0c801e: /* original 303c, guest PC 0x0c0c801e */
if(!s->budget--) { s->failed_pc=0x0c0c801eu; return 0; }
r[0]+=r[3];
goto P_0c0c8020;
P_0c0c8020: /* original 4008, guest PC 0x0c0c8020 */
if(!s->budget--) { s->failed_pc=0x0c0c8020u; return 0; }
r[0]<<=2;
goto P_0c0c8022;
P_0c0c8022: /* original f32d, guest PC 0x0c0c8022 */
if(!s->budget--) { s->failed_pc=0x0c0c8022u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c8024;
P_0c0c8024: /* original 6403, guest PC 0x0c0c8024 */
if(!s->budget--) { s->failed_pc=0x0c0c8024u; return 0; }
r[4]=r[0];
goto P_0c0c8026;
P_0c0c8026: /* original e008, guest PC 0x0c0c8026 */
if(!s->budget--) { s->failed_pc=0x0c0c8026u; return 0; }
r[0]=0x00000008u;
goto P_0c0c8028;
P_0c0c8028: /* original ff37, guest PC 0x0c0c8028 */
if(!s->budget--) { s->failed_pc=0x0c0c8028u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c802a;
P_0c0c802a: /* original e004, guest PC 0x0c0c802a */
if(!s->budget--) { s->failed_pc=0x0c0c802au; return 0; }
r[0]=0x00000004u;
goto P_0c0c802c;
P_0c0c802c: /* original 445a, guest PC 0x0c0c802c */
if(!s->budget--) { s->failed_pc=0x0c0c802cu; return 0; }
r[53]=r[4];
goto P_0c0c802e;
P_0c0c802e: /* original d31a, guest PC 0x0c0c802e */
if(!s->budget--) { s->failed_pc=0x0c0c802eu; return 0; }
r[3]=read(ram,0x0c0c8098u,4);
goto P_0c0c8030;
P_0c0c8030: /* original f22d, guest PC 0x0c0c8030 */
if(!s->budget--) { s->failed_pc=0x0c0c8030u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c8032;
P_0c0c8032: /* original 430b, guest PC 0x0c0c8032 */
if(!s->budget--) { s->failed_pc=0x0c0c8032u; return 0; }
target=r[3];
r[16]=0x0c0c8036u;
vf3_matrix_store(s,ram,2,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8036u) { target=s->pc; goto dispatch; }
goto P_0c0c8036;
P_0c0c8034: /* original ff27, guest PC 0x0c0c8034 */
if(!s->budget--) { s->failed_pc=0x0c0c8034u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c8036;
P_0c0c8036: /* original e004, guest PC 0x0c0c8036 */
if(!s->budget--) { s->failed_pc=0x0c0c8036u; return 0; }
r[0]=0x00000004u;
goto P_0c0c8038;
P_0c0c8038: /* original d318, guest PC 0x0c0c8038 */
if(!s->budget--) { s->failed_pc=0x0c0c8038u; return 0; }
r[3]=read(ram,0x0c0c809cu,4);
goto P_0c0c803a;
P_0c0c803a: /* original f6f6, guest PC 0x0c0c803a */
if(!s->budget--) { s->failed_pc=0x0c0c803au; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c803c;
P_0c0c803c: /* original e008, guest PC 0x0c0c803c */
if(!s->budget--) { s->failed_pc=0x0c0c803cu; return 0; }
r[0]=0x00000008u;
goto P_0c0c803e;
P_0c0c803e: /* original f58d, guest PC 0x0c0c803e */
if(!s->budget--) { s->failed_pc=0x0c0c803eu; return 0; }
fr[5]=0;
goto P_0c0c8040;
P_0c0c8040: /* original f64d, guest PC 0x0c0c8040 */
if(!s->budget--) { s->failed_pc=0x0c0c8040u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0c8042;
P_0c0c8042: /* original 430b, guest PC 0x0c0c8042 */
if(!s->budget--) { s->failed_pc=0x0c0c8042u; return 0; }
target=r[3];
r[16]=0x0c0c8046u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8046u) { target=s->pc; goto dispatch; }
goto P_0c0c8046;
P_0c0c8044: /* original f4f6, guest PC 0x0c0c8044 */
if(!s->budget--) { s->failed_pc=0x0c0c8044u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c8046;
P_0c0c8046: /* original d216, guest PC 0x0c0c8046 */
if(!s->budget--) { s->failed_pc=0x0c0c8046u; return 0; }
r[2]=read(ram,0x0c0c80a0u,4);
goto P_0c0c8048;
P_0c0c8048: /* original 940a, guest PC 0x0c0c8048 */
if(!s->budget--) { s->failed_pc=0x0c0c8048u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8060u,2);
goto P_0c0c804a;
P_0c0c804a: /* original 420b, guest PC 0x0c0c804a */
if(!s->budget--) { s->failed_pc=0x0c0c804au; return 0; }
target=r[2];
r[16]=0x0c0c804eu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c804eu) { target=s->pc; goto dispatch; }
goto P_0c0c804e;
P_0c0c804c: /* original 34ec, guest PC 0x0c0c804c */
if(!s->budget--) { s->failed_pc=0x0c0c804cu; return 0; }
r[4]+=r[14];
goto P_0c0c804e;
P_0c0c804e: /* original 7f0c, guest PC 0x0c0c804e */
if(!s->budget--) { s->failed_pc=0x0c0c804eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c8050;
P_0c0c8050: /* original d314, guest PC 0x0c0c8050 */
if(!s->budget--) { s->failed_pc=0x0c0c8050u; return 0; }
r[3]=read(ram,0x0c0c80a4u,4);
goto P_0c0c8052;
P_0c0c8052: /* original 4f26, guest PC 0x0c0c8052 */
if(!s->budget--) { s->failed_pc=0x0c0c8052u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8054;
P_0c0c8054: /* original e401, guest PC 0x0c0c8054 */
if(!s->budget--) { s->failed_pc=0x0c0c8054u; return 0; }
r[4]=0x00000001u;
goto P_0c0c8056;
P_0c0c8056: /* original 6df6, guest PC 0x0c0c8056 */
if(!s->budget--) { s->failed_pc=0x0c0c8056u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8058;
P_0c0c8058: /* original 432b, guest PC 0x0c0c8058 */
if(!s->budget--) { s->failed_pc=0x0c0c8058u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0c805a: /* original 6ef6, guest PC 0x0c0c805a */
if(!s->budget--) { s->failed_pc=0x0c0c805au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c805cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03cce0u,0x0c03cce2u,0x0c03cce4u,0x0c03cce6u,0x0c03cce8u,0x0c03cceau,0x0c03ccecu,0x0c03cceeu,0x0c03ccf0u,0x0c03ccf2u,0x0c03ccf4u,0x0c03ccf6u,0x0c03ccf8u,0x0c03ccfau,0x0c06c63au,0x0c06c63cu,
0x0c06c63eu,0x0c06c640u,0x0c06c642u,0x0c06c644u,0x0c06c646u,0x0c06c648u,0x0c06c64au,0x0c06c64cu,0x0c06c64eu,0x0c06c650u,0x0c06c652u,0x0c06c654u,0x0c06c656u,0x0c06c658u,0x0c06c65au,0x0c06c65cu,
0x0c06c65eu,0x0c06c660u,0x0c06c662u,0x0c06c664u,0x0c06c666u,0x0c06c668u,0x0c06c66au,0x0c06c66cu,0x0c06c66eu,0x0c06c670u,0x0c06c672u,0x0c06c674u,0x0c06c676u,0x0c06c678u,0x0c06c67au,0x0c06c67cu,
0x0c06c67eu,0x0c06c680u,0x0c06c682u,0x0c06c684u,0x0c06c686u,0x0c06c688u,0x0c06c68au,0x0c06c68cu,0x0c06c68eu,0x0c06c690u,0x0c06c692u,0x0c06c694u,0x0c06c696u,0x0c06c698u,0x0c06c69au,0x0c06c69cu,
0x0c06c69eu,0x0c06c6a0u,0x0c06c6a2u,0x0c06c6a4u,0x0c06c6a6u,0x0c06c6a8u,0x0c07ed74u,0x0c07ed76u,0x0c07ed78u,0x0c07ed7au,0x0c07ed7cu,0x0c07ed7eu,0x0c07ed80u,0x0c07ed82u,0x0c07ed84u,0x0c07ed86u,
0x0c07ed88u,0x0c07ed8au,0x0c07ed8cu,0x0c07ed8eu,0x0c07ed90u,0x0c07ed92u,0x0c07ed94u,0x0c07ed96u,0x0c07ed98u,0x0c07ed9au,0x0c07ed9cu,0x0c07ed9eu,0x0c07eda0u,0x0c07eda2u,0x0c07eda4u,0x0c07eda6u,
0x0c07eda8u,0x0c07edaau,0x0c07edacu,0x0c07edaeu,0x0c07edb0u,0x0c07edb2u,0x0c07edb4u,0x0c07edb6u,0x0c07edb8u,0x0c07edbau,0x0c07edbcu,0x0c07edbeu,0x0c07edc0u,0x0c07edc2u,0x0c07edc4u,0x0c07edc6u,
0x0c07edc8u,0x0c07edcau,0x0c07edccu,0x0c07edceu,0x0c07edd0u,0x0c07edd2u,0x0c07edd4u,0x0c07edd6u,0x0c07edd8u,0x0c07eddau,0x0c07eddcu,0x0c07eddeu,0x0c07ede0u,0x0c07ede2u,0x0c07ede4u,0x0c07ede6u,
0x0c07ede8u,0x0c07edeau,0x0c07edecu,0x0c07edeeu,0x0c07edf0u,0x0c07edf2u,0x0c07edf4u,0x0c07edf6u,0x0c07edf8u,0x0c07edfau,0x0c07edfcu,0x0c07edfeu,0x0c07ee00u,0x0c07ee02u,0x0c07ee04u,0x0c07ee06u,
0x0c07ee08u,0x0c07ee0au,0x0c07ee0cu,0x0c07ee0eu,0x0c07ee10u,0x0c07ee12u,0x0c07ee14u,0x0c07ee16u,0x0c07ee18u,0x0c07ee1au,0x0c07ee1cu,0x0c07ee1eu,0x0c07ee20u,0x0c07ee22u,0x0c07ee24u,0x0c07ee26u,
0x0c07ee28u,0x0c07ee2au,0x0c07ee2cu,0x0c07ee2eu,0x0c07ee30u,0x0c07ee32u,0x0c080b3cu,0x0c080b3eu,0x0c080b40u,0x0c080b42u,0x0c080b44u,0x0c080b46u,0x0c080b48u,0x0c080b4au,0x0c080b4cu,0x0c080b4eu,
0x0c080b50u,0x0c080b52u,0x0c080b54u,0x0c080b56u,0x0c080b58u,0x0c080b5au,0x0c080b5cu,0x0c080b5eu,0x0c080b60u,0x0c080b62u,0x0c080b64u,0x0c080b66u,0x0c080b68u,0x0c080b6au,0x0c080b6cu,0x0c080b6eu,
0x0c080b70u,0x0c080b72u,0x0c080b74u,0x0c080b76u,0x0c080b78u,0x0c080b7au,0x0c080b7cu,0x0c080b7eu,0x0c080b80u,0x0c080b82u,0x0c080b84u,0x0c080b86u,0x0c080b88u,0x0c080b8au,0x0c080b8cu,0x0c080b8eu,
0x0c080b90u,0x0c080b92u,0x0c080b94u,0x0c080b96u,0x0c080b98u,0x0c080b9au,0x0c080b9cu,0x0c080b9eu,0x0c080ba0u,0x0c080ba2u,0x0c080ba4u,0x0c080ba6u,0x0c080ba8u,0x0c080baau,0x0c080bacu,0x0c080baeu,
0x0c080bb0u,0x0c080bb2u,0x0c080bb4u,0x0c080bb6u,0x0c080bb8u,0x0c080bbau,0x0c080bbcu,0x0c080bbeu,0x0c080bc0u,0x0c080bc2u,0x0c080bc4u,0x0c080bc6u,0x0c080bc8u,0x0c080bcau,0x0c080bccu,0x0c080bceu,
0x0c080bd0u,0x0c080bd2u,0x0c080bd4u,0x0c080bd6u,0x0c080bd8u,0x0c080bdau,0x0c080bdcu,0x0c080bdeu,0x0c080be0u,0x0c080be2u,0x0c080be4u,0x0c080be6u,0x0c080be8u,0x0c080beau,0x0c080becu,0x0c080beeu,
0x0c080bf0u,0x0c080bf2u,0x0c080bf4u,0x0c080bf6u,0x0c080bf8u,0x0c080bfau,0x0c080bfcu,0x0c080bfeu,0x0c080c00u,0x0c080c02u,0x0c080c04u,0x0c080c06u,0x0c080c08u,0x0c080c0au,0x0c080c0cu,0x0c080c0eu,
0x0c080c10u,0x0c080c12u,0x0c080c14u,0x0c080c16u,0x0c080c18u,0x0c080c1au,0x0c080c1cu,0x0c080c1eu,0x0c080c20u,0x0c080c22u,0x0c080c24u,0x0c080c26u,0x0c080c28u,0x0c080c2au,0x0c080c2cu,0x0c080c2eu,
0x0c080c30u,0x0c080c32u,0x0c080c34u,0x0c080c36u,0x0c080c38u,0x0c080c3au,0x0c080c3cu,0x0c080c3eu,0x0c080c40u,0x0c080c42u,0x0c080c44u,0x0c080c46u,0x0c080c48u,0x0c080c4au,0x0c080d14u,0x0c080d16u,
0x0c080d18u,0x0c080d1au,0x0c080d1cu,0x0c080d1eu,0x0c080d20u,0x0c080d22u,0x0c080d24u,0x0c080d26u,0x0c080d28u,0x0c080d2au,0x0c089ab2u,0x0c089ab4u,0x0c089ab6u,0x0c089ab8u,0x0c089abau,0x0c089abcu,
0x0c089abeu,0x0c089ac0u,0x0c089ac2u,0x0c089ac4u,0x0c089ac6u,0x0c089ac8u,0x0c089acau,0x0c089accu,0x0c089aceu,0x0c089ad0u,0x0c089ad2u,0x0c089ad4u,0x0c089ad6u,0x0c089ad8u,0x0c089adau,0x0c089adcu,
0x0c089adeu,0x0c089ae0u,0x0c089ae2u,0x0c089ae4u,0x0c089ae6u,0x0c089ae8u,0x0c089aeau,0x0c089aecu,0x0c089aeeu,0x0c089af0u,0x0c089af2u,0x0c089af4u,0x0c089af6u,0x0c089af8u,0x0c089afau,0x0c089afcu,
0x0c089afeu,0x0c089b00u,0x0c089b02u,0x0c089b04u,0x0c089b06u,0x0c089b08u,0x0c089b0au,0x0c089b0cu,0x0c089b0eu,0x0c089b10u,0x0c089b12u,0x0c089b14u,0x0c089b16u,0x0c089b18u,0x0c089b1au,0x0c089b1cu,
0x0c0c66c0u,0x0c0c66c2u,0x0c0c7fbcu,0x0c0c7fbeu,0x0c0c7fc0u,0x0c0c7fc2u,0x0c0c7fc4u,0x0c0c7fc6u,0x0c0c7fc8u,0x0c0c7fcau,0x0c0c7fccu,0x0c0c7fceu,0x0c0c7fd0u,0x0c0c7fd2u,0x0c0c7fd4u,0x0c0c7fd6u,
0x0c0c7fd8u,0x0c0c7fdau,0x0c0c7fdcu,0x0c0c7fdeu,0x0c0c7fe0u,0x0c0c7fe2u,0x0c0c7fe4u,0x0c0c7fe6u,0x0c0c7fe8u,0x0c0c7feau,0x0c0c7fecu,0x0c0c7feeu,0x0c0c7ff0u,0x0c0c7ff2u,0x0c0c7ff4u,0x0c0c7ff6u,
0x0c0c7ff8u,0x0c0c7ffau,0x0c0c7ffcu,0x0c0c7ffeu,0x0c0c8000u,0x0c0c8002u,0x0c0c8004u,0x0c0c8006u,0x0c0c8008u,0x0c0c800au,0x0c0c800cu,0x0c0c800eu,0x0c0c8010u,0x0c0c8012u,0x0c0c8014u,0x0c0c8016u,
0x0c0c8018u,0x0c0c801au,0x0c0c801cu,0x0c0c801eu,0x0c0c8020u,0x0c0c8022u,0x0c0c8024u,0x0c0c8026u,0x0c0c8028u,0x0c0c802au,0x0c0c802cu,0x0c0c802eu,0x0c0c8030u,0x0c0c8032u,0x0c0c8034u,0x0c0c8036u,
0x0c0c8038u,0x0c0c803au,0x0c0c803cu,0x0c0c803eu,0x0c0c8040u,0x0c0c8042u,0x0c0c8044u,0x0c0c8046u,0x0c0c8048u,0x0c0c804au,0x0c0c804cu,0x0c0c804eu,0x0c0c8050u,0x0c0c8052u,0x0c0c8054u,0x0c0c8056u,
0x0c0c8058u,0x0c0c805au,
};
int vf3_target_scene_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
