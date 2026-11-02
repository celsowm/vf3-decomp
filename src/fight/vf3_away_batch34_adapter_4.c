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
int vf3_away_batch34_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0698ecu: goto P_0c0698ec;
case 0x0c0698eeu: goto P_0c0698ee;
case 0x0c0698f0u: goto P_0c0698f0;
case 0x0c0698f2u: goto P_0c0698f2;
case 0x0c0698f4u: goto P_0c0698f4;
case 0x0c0698f6u: goto P_0c0698f6;
case 0x0c0698f8u: goto P_0c0698f8;
case 0x0c0698fau: goto P_0c0698fa;
case 0x0c0698fcu: goto P_0c0698fc;
case 0x0c0698feu: goto P_0c0698fe;
case 0x0c069900u: goto P_0c069900;
case 0x0c069902u: goto P_0c069902;
case 0x0c069904u: goto P_0c069904;
case 0x0c069906u: goto P_0c069906;
case 0x0c069908u: goto P_0c069908;
case 0x0c06990au: goto P_0c06990a;
case 0x0c06990cu: goto P_0c06990c;
case 0x0c06990eu: goto P_0c06990e;
case 0x0c069910u: goto P_0c069910;
case 0x0c069912u: goto P_0c069912;
case 0x0c069914u: goto P_0c069914;
case 0x0c069916u: goto P_0c069916;
case 0x0c069918u: goto P_0c069918;
case 0x0c06991au: goto P_0c06991a;
case 0x0c06991cu: goto P_0c06991c;
case 0x0c06991eu: goto P_0c06991e;
case 0x0c069920u: goto P_0c069920;
case 0x0c069922u: goto P_0c069922;
case 0x0c069924u: goto P_0c069924;
case 0x0c069926u: goto P_0c069926;
case 0x0c069928u: goto P_0c069928;
case 0x0c06992au: goto P_0c06992a;
case 0x0c06992cu: goto P_0c06992c;
case 0x0c06992eu: goto P_0c06992e;
case 0x0c069930u: goto P_0c069930;
case 0x0c069932u: goto P_0c069932;
case 0x0c069934u: goto P_0c069934;
case 0x0c069936u: goto P_0c069936;
case 0x0c069938u: goto P_0c069938;
case 0x0c06993au: goto P_0c06993a;
case 0x0c06993cu: goto P_0c06993c;
case 0x0c06993eu: goto P_0c06993e;
case 0x0c069940u: goto P_0c069940;
case 0x0c069942u: goto P_0c069942;
case 0x0c069944u: goto P_0c069944;
case 0x0c069946u: goto P_0c069946;
case 0x0c069948u: goto P_0c069948;
case 0x0c06994au: goto P_0c06994a;
case 0x0c06994cu: goto P_0c06994c;
case 0x0c06994eu: goto P_0c06994e;
case 0x0c069950u: goto P_0c069950;
case 0x0c069952u: goto P_0c069952;
case 0x0c069954u: goto P_0c069954;
case 0x0c069956u: goto P_0c069956;
case 0x0c069958u: goto P_0c069958;
case 0x0c06995au: goto P_0c06995a;
case 0x0c06995cu: goto P_0c06995c;
case 0x0c06995eu: goto P_0c06995e;
case 0x0c069960u: goto P_0c069960;
case 0x0c069962u: goto P_0c069962;
case 0x0c069964u: goto P_0c069964;
case 0x0c069966u: goto P_0c069966;
case 0x0c069968u: goto P_0c069968;
case 0x0c06996au: goto P_0c06996a;
case 0x0c06996cu: goto P_0c06996c;
case 0x0c06996eu: goto P_0c06996e;
case 0x0c069970u: goto P_0c069970;
case 0x0c069972u: goto P_0c069972;
case 0x0c069974u: goto P_0c069974;
case 0x0c069976u: goto P_0c069976;
case 0x0c069978u: goto P_0c069978;
case 0x0c06997au: goto P_0c06997a;
case 0x0c06997cu: goto P_0c06997c;
case 0x0c06997eu: goto P_0c06997e;
case 0x0c069980u: goto P_0c069980;
case 0x0c069982u: goto P_0c069982;
case 0x0c069984u: goto P_0c069984;
case 0x0c069986u: goto P_0c069986;
case 0x0c069988u: goto P_0c069988;
case 0x0c06998au: goto P_0c06998a;
case 0x0c06998cu: goto P_0c06998c;
case 0x0c06998eu: goto P_0c06998e;
case 0x0c069990u: goto P_0c069990;
case 0x0c069992u: goto P_0c069992;
case 0x0c069994u: goto P_0c069994;
case 0x0c069996u: goto P_0c069996;
case 0x0c069998u: goto P_0c069998;
case 0x0c06999au: goto P_0c06999a;
case 0x0c06999cu: goto P_0c06999c;
case 0x0c06999eu: goto P_0c06999e;
case 0x0c0699a0u: goto P_0c0699a0;
case 0x0c0699a2u: goto P_0c0699a2;
case 0x0c0699a4u: goto P_0c0699a4;
case 0x0c0699a6u: goto P_0c0699a6;
case 0x0c0699a8u: goto P_0c0699a8;
case 0x0c0699aau: goto P_0c0699aa;
case 0x0c0699acu: goto P_0c0699ac;
case 0x0c0699aeu: goto P_0c0699ae;
case 0x0c0699b0u: goto P_0c0699b0;
case 0x0c0699b2u: goto P_0c0699b2;
case 0x0c0699b4u: goto P_0c0699b4;
case 0x0c0699b6u: goto P_0c0699b6;
case 0x0c0699b8u: goto P_0c0699b8;
case 0x0c0699bau: goto P_0c0699ba;
case 0x0c0699bcu: goto P_0c0699bc;
case 0x0c0699beu: goto P_0c0699be;
case 0x0c0699c0u: goto P_0c0699c0;
case 0x0c0699c2u: goto P_0c0699c2;
case 0x0c0699c4u: goto P_0c0699c4;
case 0x0c0699c6u: goto P_0c0699c6;
case 0x0c0699c8u: goto P_0c0699c8;
case 0x0c0699cau: goto P_0c0699ca;
case 0x0c0699ccu: goto P_0c0699cc;
case 0x0c0699ceu: goto P_0c0699ce;
case 0x0c0699d0u: goto P_0c0699d0;
case 0x0c0699d2u: goto P_0c0699d2;
case 0x0c0699d4u: goto P_0c0699d4;
case 0x0c0699d6u: goto P_0c0699d6;
case 0x0c0699d8u: goto P_0c0699d8;
case 0x0c0699dau: goto P_0c0699da;
case 0x0c0699dcu: goto P_0c0699dc;
case 0x0c0699deu: goto P_0c0699de;
case 0x0c0699e0u: goto P_0c0699e0;
case 0x0c0699e2u: goto P_0c0699e2;
case 0x0c0699e4u: goto P_0c0699e4;
case 0x0c0699e6u: goto P_0c0699e6;
case 0x0c0699e8u: goto P_0c0699e8;
case 0x0c0699eau: goto P_0c0699ea;
case 0x0c0699ecu: goto P_0c0699ec;
case 0x0c0699eeu: goto P_0c0699ee;
case 0x0c0699f0u: goto P_0c0699f0;
case 0x0c0699f2u: goto P_0c0699f2;
case 0x0c0699f4u: goto P_0c0699f4;
case 0x0c0699f6u: goto P_0c0699f6;
case 0x0c0699f8u: goto P_0c0699f8;
case 0x0c0699fau: goto P_0c0699fa;
case 0x0c0699fcu: goto P_0c0699fc;
case 0x0c0699feu: goto P_0c0699fe;
case 0x0c069a00u: goto P_0c069a00;
case 0x0c069a02u: goto P_0c069a02;
case 0x0c069a04u: goto P_0c069a04;
case 0x0c069a06u: goto P_0c069a06;
case 0x0c069a08u: goto P_0c069a08;
case 0x0c069a0au: goto P_0c069a0a;
case 0x0c069a0cu: goto P_0c069a0c;
case 0x0c069a0eu: goto P_0c069a0e;
case 0x0c069a10u: goto P_0c069a10;
case 0x0c069a12u: goto P_0c069a12;
case 0x0c069a14u: goto P_0c069a14;
case 0x0c069a16u: goto P_0c069a16;
case 0x0c069a18u: goto P_0c069a18;
case 0x0c069a1au: goto P_0c069a1a;
case 0x0c069a1cu: goto P_0c069a1c;
case 0x0c069a1eu: goto P_0c069a1e;
case 0x0c069a20u: goto P_0c069a20;
case 0x0c069a22u: goto P_0c069a22;
case 0x0c069a24u: goto P_0c069a24;
case 0x0c069a26u: goto P_0c069a26;
case 0x0c069a60u: goto P_0c069a60;
case 0x0c069a62u: goto P_0c069a62;
case 0x0c069a64u: goto P_0c069a64;
case 0x0c069a66u: goto P_0c069a66;
case 0x0c069a68u: goto P_0c069a68;
case 0x0c069a6au: goto P_0c069a6a;
case 0x0c069a6cu: goto P_0c069a6c;
case 0x0c069a6eu: goto P_0c069a6e;
case 0x0c069a70u: goto P_0c069a70;
case 0x0c069a72u: goto P_0c069a72;
case 0x0c069a74u: goto P_0c069a74;
case 0x0c069a76u: goto P_0c069a76;
case 0x0c069a78u: goto P_0c069a78;
case 0x0c069a7au: goto P_0c069a7a;
case 0x0c069a7cu: goto P_0c069a7c;
case 0x0c069a7eu: goto P_0c069a7e;
case 0x0c069a80u: goto P_0c069a80;
case 0x0c069a82u: goto P_0c069a82;
case 0x0c069a84u: goto P_0c069a84;
case 0x0c069a86u: goto P_0c069a86;
case 0x0c069a88u: goto P_0c069a88;
case 0x0c069a8au: goto P_0c069a8a;
case 0x0c069a8cu: goto P_0c069a8c;
case 0x0c069a8eu: goto P_0c069a8e;
case 0x0c069a90u: goto P_0c069a90;
case 0x0c069a92u: goto P_0c069a92;
case 0x0c069a94u: goto P_0c069a94;
case 0x0c069a96u: goto P_0c069a96;
case 0x0c069a98u: goto P_0c069a98;
case 0x0c069a9au: goto P_0c069a9a;
case 0x0c069a9cu: goto P_0c069a9c;
case 0x0c069a9eu: goto P_0c069a9e;
case 0x0c069aa0u: goto P_0c069aa0;
case 0x0c069aa2u: goto P_0c069aa2;
case 0x0c069aa4u: goto P_0c069aa4;
case 0x0c069aa6u: goto P_0c069aa6;
case 0x0c069aa8u: goto P_0c069aa8;
case 0x0c069aaau: goto P_0c069aaa;
case 0x0c069aacu: goto P_0c069aac;
case 0x0c069aaeu: goto P_0c069aae;
case 0x0c069ab0u: goto P_0c069ab0;
case 0x0c069ab2u: goto P_0c069ab2;
case 0x0c069ab4u: goto P_0c069ab4;
case 0x0c069ab6u: goto P_0c069ab6;
case 0x0c069ab8u: goto P_0c069ab8;
case 0x0c069abau: goto P_0c069aba;
case 0x0c069abcu: goto P_0c069abc;
case 0x0c069abeu: goto P_0c069abe;
case 0x0c069ac0u: goto P_0c069ac0;
case 0x0c069ac2u: goto P_0c069ac2;
case 0x0c069ac4u: goto P_0c069ac4;
case 0x0c069ac6u: goto P_0c069ac6;
case 0x0c069ac8u: goto P_0c069ac8;
case 0x0c069acau: goto P_0c069aca;
case 0x0c069accu: goto P_0c069acc;
case 0x0c069aceu: goto P_0c069ace;
case 0x0c069ad0u: goto P_0c069ad0;
case 0x0c069ad2u: goto P_0c069ad2;
case 0x0c069ad4u: goto P_0c069ad4;
case 0x0c069ad6u: goto P_0c069ad6;
case 0x0c069ad8u: goto P_0c069ad8;
case 0x0c069adau: goto P_0c069ada;
case 0x0c069adcu: goto P_0c069adc;
case 0x0c069adeu: goto P_0c069ade;
case 0x0c069ae0u: goto P_0c069ae0;
case 0x0c069ae2u: goto P_0c069ae2;
case 0x0c069ae4u: goto P_0c069ae4;
case 0x0c069ae6u: goto P_0c069ae6;
case 0x0c069ae8u: goto P_0c069ae8;
case 0x0c069aeau: goto P_0c069aea;
case 0x0c069aecu: goto P_0c069aec;
case 0x0c069aeeu: goto P_0c069aee;
case 0x0c069af0u: goto P_0c069af0;
case 0x0c069af2u: goto P_0c069af2;
case 0x0c069af4u: goto P_0c069af4;
case 0x0c069af6u: goto P_0c069af6;
case 0x0c069af8u: goto P_0c069af8;
case 0x0c069afau: goto P_0c069afa;
case 0x0c069afcu: goto P_0c069afc;
case 0x0c069afeu: goto P_0c069afe;
case 0x0c069b00u: goto P_0c069b00;
case 0x0c069b02u: goto P_0c069b02;
case 0x0c069b04u: goto P_0c069b04;
case 0x0c069b06u: goto P_0c069b06;
case 0x0c069b08u: goto P_0c069b08;
case 0x0c069b0au: goto P_0c069b0a;
case 0x0c069b0cu: goto P_0c069b0c;
case 0x0c069b0eu: goto P_0c069b0e;
case 0x0c069b10u: goto P_0c069b10;
case 0x0c069b12u: goto P_0c069b12;
case 0x0c069b14u: goto P_0c069b14;
case 0x0c069b16u: goto P_0c069b16;
case 0x0c069b18u: goto P_0c069b18;
case 0x0c069b1au: goto P_0c069b1a;
case 0x0c069b1cu: goto P_0c069b1c;
case 0x0c069b1eu: goto P_0c069b1e;
case 0x0c069b20u: goto P_0c069b20;
case 0x0c069b22u: goto P_0c069b22;
case 0x0c069b24u: goto P_0c069b24;
case 0x0c069b26u: goto P_0c069b26;
case 0x0c069b28u: goto P_0c069b28;
case 0x0c069b2au: goto P_0c069b2a;
case 0x0c069b2cu: goto P_0c069b2c;
case 0x0c069b2eu: goto P_0c069b2e;
case 0x0c069b30u: goto P_0c069b30;
case 0x0c069b32u: goto P_0c069b32;
case 0x0c069b34u: goto P_0c069b34;
case 0x0c069b36u: goto P_0c069b36;
case 0x0c069b38u: goto P_0c069b38;
case 0x0c069b3au: goto P_0c069b3a;
case 0x0c069b3cu: goto P_0c069b3c;
case 0x0c069b3eu: goto P_0c069b3e;
case 0x0c069b40u: goto P_0c069b40;
case 0x0c069b42u: goto P_0c069b42;
case 0x0c069b44u: goto P_0c069b44;
case 0x0c069b46u: goto P_0c069b46;
case 0x0c069b48u: goto P_0c069b48;
case 0x0c069b4au: goto P_0c069b4a;
case 0x0c069b4cu: goto P_0c069b4c;
case 0x0c069b4eu: goto P_0c069b4e;
case 0x0c069b50u: goto P_0c069b50;
case 0x0c069b52u: goto P_0c069b52;
case 0x0c069b54u: goto P_0c069b54;
case 0x0c069b56u: goto P_0c069b56;
case 0x0c069b58u: goto P_0c069b58;
case 0x0c069b5au: goto P_0c069b5a;
case 0x0c069b5cu: goto P_0c069b5c;
case 0x0c069b5eu: goto P_0c069b5e;
case 0x0c069b60u: goto P_0c069b60;
case 0x0c069b62u: goto P_0c069b62;
case 0x0c069b64u: goto P_0c069b64;
case 0x0c069b66u: goto P_0c069b66;
case 0x0c069b68u: goto P_0c069b68;
case 0x0c069b6au: goto P_0c069b6a;
case 0x0c069b6cu: goto P_0c069b6c;
case 0x0c069b6eu: goto P_0c069b6e;
case 0x0c069b70u: goto P_0c069b70;
case 0x0c069b72u: goto P_0c069b72;
case 0x0c069b74u: goto P_0c069b74;
case 0x0c069b76u: goto P_0c069b76;
case 0x0c069b78u: goto P_0c069b78;
case 0x0c069b7au: goto P_0c069b7a;
case 0x0c069b7cu: goto P_0c069b7c;
case 0x0c069b7eu: goto P_0c069b7e;
case 0x0c069b80u: goto P_0c069b80;
case 0x0c069b82u: goto P_0c069b82;
case 0x0c069b84u: goto P_0c069b84;
case 0x0c069b86u: goto P_0c069b86;
case 0x0c069b88u: goto P_0c069b88;
case 0x0c069b8au: goto P_0c069b8a;
case 0x0c069b8cu: goto P_0c069b8c;
case 0x0c069b8eu: goto P_0c069b8e;
case 0x0c069b90u: goto P_0c069b90;
case 0x0c069b92u: goto P_0c069b92;
case 0x0c069b94u: goto P_0c069b94;
case 0x0c069b96u: goto P_0c069b96;
case 0x0c069b98u: goto P_0c069b98;
case 0x0c069b9au: goto P_0c069b9a;
case 0x0c069b9cu: goto P_0c069b9c;
case 0x0c069b9eu: goto P_0c069b9e;
case 0x0c069ba0u: goto P_0c069ba0;
case 0x0c069ba2u: goto P_0c069ba2;
case 0x0c069ba4u: goto P_0c069ba4;
case 0x0c069ba6u: goto P_0c069ba6;
case 0x0c069bc4u: goto P_0c069bc4;
case 0x0c069bc6u: goto P_0c069bc6;
case 0x0c069bc8u: goto P_0c069bc8;
case 0x0c069bcau: goto P_0c069bca;
case 0x0c069bccu: goto P_0c069bcc;
case 0x0c069bceu: goto P_0c069bce;
case 0x0c069bd0u: goto P_0c069bd0;
case 0x0c069bd2u: goto P_0c069bd2;
case 0x0c069bd4u: goto P_0c069bd4;
case 0x0c069bd6u: goto P_0c069bd6;
case 0x0c069bd8u: goto P_0c069bd8;
case 0x0c069bdau: goto P_0c069bda;
case 0x0c069bdcu: goto P_0c069bdc;
case 0x0c069bdeu: goto P_0c069bde;
case 0x0c069be0u: goto P_0c069be0;
case 0x0c069be2u: goto P_0c069be2;
case 0x0c069be4u: goto P_0c069be4;
case 0x0c069be6u: goto P_0c069be6;
case 0x0c069be8u: goto P_0c069be8;
case 0x0c069beau: goto P_0c069bea;
case 0x0c069becu: goto P_0c069bec;
case 0x0c069beeu: goto P_0c069bee;
case 0x0c069bf0u: goto P_0c069bf0;
case 0x0c069bf2u: goto P_0c069bf2;
case 0x0c069bf4u: goto P_0c069bf4;
case 0x0c069bf6u: goto P_0c069bf6;
case 0x0c069bf8u: goto P_0c069bf8;
case 0x0c069bfau: goto P_0c069bfa;
case 0x0c069bfcu: goto P_0c069bfc;
case 0x0c069bfeu: goto P_0c069bfe;
case 0x0c069c00u: goto P_0c069c00;
case 0x0c069c02u: goto P_0c069c02;
case 0x0c069c04u: goto P_0c069c04;
case 0x0c069c06u: goto P_0c069c06;
case 0x0c069c08u: goto P_0c069c08;
case 0x0c069c0au: goto P_0c069c0a;
case 0x0c069c0cu: goto P_0c069c0c;
case 0x0c069c0eu: goto P_0c069c0e;
case 0x0c069c10u: goto P_0c069c10;
case 0x0c069c12u: goto P_0c069c12;
case 0x0c069c14u: goto P_0c069c14;
case 0x0c069c16u: goto P_0c069c16;
case 0x0c069c18u: goto P_0c069c18;
case 0x0c069c1au: goto P_0c069c1a;
case 0x0c069c1cu: goto P_0c069c1c;
case 0x0c069c1eu: goto P_0c069c1e;
case 0x0c069c20u: goto P_0c069c20;
case 0x0c069c22u: goto P_0c069c22;
case 0x0c069c24u: goto P_0c069c24;
case 0x0c069c26u: goto P_0c069c26;
case 0x0c069c28u: goto P_0c069c28;
case 0x0c069c2au: goto P_0c069c2a;
case 0x0c069c2cu: goto P_0c069c2c;
case 0x0c069c2eu: goto P_0c069c2e;
case 0x0c069c30u: goto P_0c069c30;
case 0x0c069c32u: goto P_0c069c32;
case 0x0c069c34u: goto P_0c069c34;
case 0x0c069c36u: goto P_0c069c36;
case 0x0c069c38u: goto P_0c069c38;
case 0x0c069c3au: goto P_0c069c3a;
case 0x0c069c3cu: goto P_0c069c3c;
case 0x0c069c3eu: goto P_0c069c3e;
case 0x0c069c40u: goto P_0c069c40;
case 0x0c069c42u: goto P_0c069c42;
case 0x0c069c44u: goto P_0c069c44;
case 0x0c069c46u: goto P_0c069c46;
case 0x0c069c48u: goto P_0c069c48;
case 0x0c069c4au: goto P_0c069c4a;
case 0x0c069c4cu: goto P_0c069c4c;
case 0x0c069c4eu: goto P_0c069c4e;
case 0x0c069c50u: goto P_0c069c50;
case 0x0c069c52u: goto P_0c069c52;
case 0x0c069c54u: goto P_0c069c54;
case 0x0c069c56u: goto P_0c069c56;
case 0x0c069c58u: goto P_0c069c58;
case 0x0c069c5au: goto P_0c069c5a;
case 0x0c069c5cu: goto P_0c069c5c;
case 0x0c069c5eu: goto P_0c069c5e;
case 0x0c069c60u: goto P_0c069c60;
case 0x0c069c62u: goto P_0c069c62;
case 0x0c069c64u: goto P_0c069c64;
case 0x0c069c66u: goto P_0c069c66;
case 0x0c069c68u: goto P_0c069c68;
case 0x0c069c6au: goto P_0c069c6a;
case 0x0c069c6cu: goto P_0c069c6c;
case 0x0c069c6eu: goto P_0c069c6e;
case 0x0c069c70u: goto P_0c069c70;
case 0x0c069c72u: goto P_0c069c72;
case 0x0c069c74u: goto P_0c069c74;
case 0x0c069c76u: goto P_0c069c76;
case 0x0c069c78u: goto P_0c069c78;
case 0x0c069c7au: goto P_0c069c7a;
case 0x0c069c7cu: goto P_0c069c7c;
case 0x0c069c7eu: goto P_0c069c7e;
case 0x0c069c80u: goto P_0c069c80;
case 0x0c069c82u: goto P_0c069c82;
case 0x0c069c84u: goto P_0c069c84;
case 0x0c069c86u: goto P_0c069c86;
case 0x0c069c88u: goto P_0c069c88;
case 0x0c069c8au: goto P_0c069c8a;
case 0x0c069c8cu: goto P_0c069c8c;
case 0x0c069c8eu: goto P_0c069c8e;
case 0x0c069c90u: goto P_0c069c90;
case 0x0c069c92u: goto P_0c069c92;
case 0x0c069c94u: goto P_0c069c94;
case 0x0c069c96u: goto P_0c069c96;
case 0x0c069c98u: goto P_0c069c98;
case 0x0c069c9au: goto P_0c069c9a;
case 0x0c069c9cu: goto P_0c069c9c;
case 0x0c069c9eu: goto P_0c069c9e;
case 0x0c069ca0u: goto P_0c069ca0;
case 0x0c069ca2u: goto P_0c069ca2;
case 0x0c069ca4u: goto P_0c069ca4;
case 0x0c069ca6u: goto P_0c069ca6;
case 0x0c069ca8u: goto P_0c069ca8;
case 0x0c069caau: goto P_0c069caa;
case 0x0c069cacu: goto P_0c069cac;
case 0x0c069caeu: goto P_0c069cae;
case 0x0c069cb0u: goto P_0c069cb0;
case 0x0c069cb2u: goto P_0c069cb2;
case 0x0c069cb4u: goto P_0c069cb4;
case 0x0c069cb6u: goto P_0c069cb6;
case 0x0c069cb8u: goto P_0c069cb8;
case 0x0c069cbau: goto P_0c069cba;
case 0x0c069cbcu: goto P_0c069cbc;
case 0x0c069cbeu: goto P_0c069cbe;
case 0x0c069cc0u: goto P_0c069cc0;
case 0x0c069cc2u: goto P_0c069cc2;
case 0x0c069cc4u: goto P_0c069cc4;
case 0x0c069cc6u: goto P_0c069cc6;
case 0x0c069cc8u: goto P_0c069cc8;
case 0x0c069ccau: goto P_0c069cca;
case 0x0c069cccu: goto P_0c069ccc;
case 0x0c069cceu: goto P_0c069cce;
case 0x0c069cd0u: goto P_0c069cd0;
case 0x0c069cd2u: goto P_0c069cd2;
case 0x0c069cd4u: goto P_0c069cd4;
case 0x0c069cd6u: goto P_0c069cd6;
case 0x0c069cd8u: goto P_0c069cd8;
case 0x0c069cdau: goto P_0c069cda;
case 0x0c069cdcu: goto P_0c069cdc;
case 0x0c069cdeu: goto P_0c069cde;
case 0x0c069ce0u: goto P_0c069ce0;
case 0x0c069ce2u: goto P_0c069ce2;
case 0x0c069ce4u: goto P_0c069ce4;
case 0x0c069ce6u: goto P_0c069ce6;
case 0x0c069ce8u: goto P_0c069ce8;
case 0x0c069ceau: goto P_0c069cea;
case 0x0c069cecu: goto P_0c069cec;
case 0x0c069ceeu: goto P_0c069cee;
case 0x0c069cf0u: goto P_0c069cf0;
case 0x0c069cf2u: goto P_0c069cf2;
case 0x0c069cf4u: goto P_0c069cf4;
case 0x0c069cf6u: goto P_0c069cf6;
case 0x0c069cf8u: goto P_0c069cf8;
case 0x0c069cfau: goto P_0c069cfa;
case 0x0c069cfcu: goto P_0c069cfc;
case 0x0c069cfeu: goto P_0c069cfe;
case 0x0c069d00u: goto P_0c069d00;
case 0x0c069d02u: goto P_0c069d02;
case 0x0c069d04u: goto P_0c069d04;
case 0x0c069d06u: goto P_0c069d06;
case 0x0c069d08u: goto P_0c069d08;
case 0x0c069d3cu: goto P_0c069d3c;
case 0x0c069d3eu: goto P_0c069d3e;
case 0x0c069d40u: goto P_0c069d40;
case 0x0c069d42u: goto P_0c069d42;
case 0x0c069d44u: goto P_0c069d44;
case 0x0c069d46u: goto P_0c069d46;
case 0x0c069d48u: goto P_0c069d48;
case 0x0c069d4au: goto P_0c069d4a;
case 0x0c069d4cu: goto P_0c069d4c;
case 0x0c069d4eu: goto P_0c069d4e;
case 0x0c069d50u: goto P_0c069d50;
case 0x0c069d52u: goto P_0c069d52;
case 0x0c069d54u: goto P_0c069d54;
case 0x0c069d56u: goto P_0c069d56;
case 0x0c069d58u: goto P_0c069d58;
case 0x0c069d5au: goto P_0c069d5a;
case 0x0c069d5cu: goto P_0c069d5c;
case 0x0c069d5eu: goto P_0c069d5e;
case 0x0c069d60u: goto P_0c069d60;
case 0x0c069d62u: goto P_0c069d62;
case 0x0c069d64u: goto P_0c069d64;
case 0x0c069d66u: goto P_0c069d66;
case 0x0c069d68u: goto P_0c069d68;
case 0x0c069d6au: goto P_0c069d6a;
case 0x0c069d6cu: goto P_0c069d6c;
case 0x0c069d6eu: goto P_0c069d6e;
case 0x0c069d70u: goto P_0c069d70;
case 0x0c069d72u: goto P_0c069d72;
case 0x0c069d74u: goto P_0c069d74;
case 0x0c069d76u: goto P_0c069d76;
case 0x0c069d78u: goto P_0c069d78;
case 0x0c069d7au: goto P_0c069d7a;
case 0x0c069d7cu: goto P_0c069d7c;
case 0x0c069d7eu: goto P_0c069d7e;
case 0x0c069d80u: goto P_0c069d80;
case 0x0c069d82u: goto P_0c069d82;
case 0x0c069d84u: goto P_0c069d84;
case 0x0c069d86u: goto P_0c069d86;
case 0x0c069d88u: goto P_0c069d88;
case 0x0c069d8au: goto P_0c069d8a;
case 0x0c069d8cu: goto P_0c069d8c;
case 0x0c069d8eu: goto P_0c069d8e;
case 0x0c069d90u: goto P_0c069d90;
case 0x0c069d92u: goto P_0c069d92;
case 0x0c069d94u: goto P_0c069d94;
case 0x0c069d96u: goto P_0c069d96;
case 0x0c069d98u: goto P_0c069d98;
case 0x0c069d9au: goto P_0c069d9a;
case 0x0c069d9cu: goto P_0c069d9c;
case 0x0c069d9eu: goto P_0c069d9e;
case 0x0c069da0u: goto P_0c069da0;
case 0x0c069da2u: goto P_0c069da2;
case 0x0c069da4u: goto P_0c069da4;
case 0x0c069da6u: goto P_0c069da6;
case 0x0c069da8u: goto P_0c069da8;
case 0x0c069daau: goto P_0c069daa;
case 0x0c069dacu: goto P_0c069dac;
case 0x0c069daeu: goto P_0c069dae;
case 0x0c069db0u: goto P_0c069db0;
case 0x0c069db2u: goto P_0c069db2;
case 0x0c069db4u: goto P_0c069db4;
case 0x0c069db6u: goto P_0c069db6;
case 0x0c069db8u: goto P_0c069db8;
case 0x0c069dbau: goto P_0c069dba;
case 0x0c069dbcu: goto P_0c069dbc;
case 0x0c069dbeu: goto P_0c069dbe;
case 0x0c069dc0u: goto P_0c069dc0;
case 0x0c069dc2u: goto P_0c069dc2;
case 0x0c069dc4u: goto P_0c069dc4;
case 0x0c069dc6u: goto P_0c069dc6;
case 0x0c069dc8u: goto P_0c069dc8;
case 0x0c069dcau: goto P_0c069dca;
case 0x0c069dccu: goto P_0c069dcc;
case 0x0c069dceu: goto P_0c069dce;
case 0x0c069dd0u: goto P_0c069dd0;
case 0x0c069dd2u: goto P_0c069dd2;
case 0x0c069dd4u: goto P_0c069dd4;
case 0x0c069dd6u: goto P_0c069dd6;
case 0x0c069dd8u: goto P_0c069dd8;
case 0x0c069ddau: goto P_0c069dda;
case 0x0c069ddcu: goto P_0c069ddc;
case 0x0c069ddeu: goto P_0c069dde;
case 0x0c069de0u: goto P_0c069de0;
case 0x0c069de2u: goto P_0c069de2;
case 0x0c069de4u: goto P_0c069de4;
case 0x0c069de6u: goto P_0c069de6;
case 0x0c069de8u: goto P_0c069de8;
case 0x0c069deau: goto P_0c069dea;
case 0x0c069decu: goto P_0c069dec;
case 0x0c069deeu: goto P_0c069dee;
case 0x0c069df0u: goto P_0c069df0;
case 0x0c069df2u: goto P_0c069df2;
case 0x0c069df4u: goto P_0c069df4;
case 0x0c069df6u: goto P_0c069df6;
case 0x0c069df8u: goto P_0c069df8;
case 0x0c069dfau: goto P_0c069dfa;
case 0x0c069dfcu: goto P_0c069dfc;
case 0x0c069dfeu: goto P_0c069dfe;
case 0x0c069e00u: goto P_0c069e00;
case 0x0c069e02u: goto P_0c069e02;
case 0x0c069e04u: goto P_0c069e04;
case 0x0c069e06u: goto P_0c069e06;
case 0x0c069e08u: goto P_0c069e08;
case 0x0c069e0au: goto P_0c069e0a;
case 0x0c069e0cu: goto P_0c069e0c;
case 0x0c069e0eu: goto P_0c069e0e;
case 0x0c069e10u: goto P_0c069e10;
case 0x0c069e12u: goto P_0c069e12;
case 0x0c069e14u: goto P_0c069e14;
case 0x0c069e16u: goto P_0c069e16;
case 0x0c069e18u: goto P_0c069e18;
case 0x0c069e1au: goto P_0c069e1a;
case 0x0c069e1cu: goto P_0c069e1c;
case 0x0c069e1eu: goto P_0c069e1e;
case 0x0c069e20u: goto P_0c069e20;
case 0x0c069e22u: goto P_0c069e22;
case 0x0c069e24u: goto P_0c069e24;
case 0x0c069e26u: goto P_0c069e26;
case 0x0c069e28u: goto P_0c069e28;
case 0x0c069e2au: goto P_0c069e2a;
case 0x0c069e2cu: goto P_0c069e2c;
case 0x0c069e2eu: goto P_0c069e2e;
case 0x0c069e30u: goto P_0c069e30;
case 0x0c069e32u: goto P_0c069e32;
case 0x0c069e34u: goto P_0c069e34;
case 0x0c069e36u: goto P_0c069e36;
case 0x0c069e38u: goto P_0c069e38;
case 0x0c069e3au: goto P_0c069e3a;
case 0x0c069e3cu: goto P_0c069e3c;
case 0x0c069e3eu: goto P_0c069e3e;
case 0x0c069e40u: goto P_0c069e40;
case 0x0c069e42u: goto P_0c069e42;
case 0x0c069e44u: goto P_0c069e44;
case 0x0c069e46u: goto P_0c069e46;
case 0x0c069e48u: goto P_0c069e48;
case 0x0c069e4au: goto P_0c069e4a;
case 0x0c069e4cu: goto P_0c069e4c;
case 0x0c069e4eu: goto P_0c069e4e;
case 0x0c069e50u: goto P_0c069e50;
case 0x0c069e52u: goto P_0c069e52;
case 0x0c069e54u: goto P_0c069e54;
case 0x0c069e56u: goto P_0c069e56;
case 0x0c069e58u: goto P_0c069e58;
case 0x0c069e5au: goto P_0c069e5a;
case 0x0c069e68u: goto P_0c069e68;
case 0x0c069e6au: goto P_0c069e6a;
case 0x0c069e6cu: goto P_0c069e6c;
case 0x0c069e6eu: goto P_0c069e6e;
case 0x0c069e70u: goto P_0c069e70;
case 0x0c069e72u: goto P_0c069e72;
case 0x0c069e74u: goto P_0c069e74;
case 0x0c069e76u: goto P_0c069e76;
case 0x0c069e78u: goto P_0c069e78;
case 0x0c069e7au: goto P_0c069e7a;
case 0x0c069e7cu: goto P_0c069e7c;
case 0x0c069e7eu: goto P_0c069e7e;
case 0x0c069e80u: goto P_0c069e80;
case 0x0c069e82u: goto P_0c069e82;
case 0x0c069e84u: goto P_0c069e84;
case 0x0c069e86u: goto P_0c069e86;
case 0x0c069e88u: goto P_0c069e88;
case 0x0c069e8au: goto P_0c069e8a;
case 0x0c069e8cu: goto P_0c069e8c;
case 0x0c069e8eu: goto P_0c069e8e;
case 0x0c069e90u: goto P_0c069e90;
case 0x0c069e92u: goto P_0c069e92;
case 0x0c069e94u: goto P_0c069e94;
case 0x0c069e96u: goto P_0c069e96;
case 0x0c069e98u: goto P_0c069e98;
case 0x0c069e9au: goto P_0c069e9a;
case 0x0c069e9cu: goto P_0c069e9c;
case 0x0c069e9eu: goto P_0c069e9e;
case 0x0c069ea0u: goto P_0c069ea0;
case 0x0c069ea2u: goto P_0c069ea2;
case 0x0c069ea4u: goto P_0c069ea4;
case 0x0c069ea6u: goto P_0c069ea6;
case 0x0c069ea8u: goto P_0c069ea8;
case 0x0c069eaau: goto P_0c069eaa;
case 0x0c069eacu: goto P_0c069eac;
case 0x0c069eaeu: goto P_0c069eae;
case 0x0c069eb0u: goto P_0c069eb0;
case 0x0c069eb2u: goto P_0c069eb2;
case 0x0c069eb4u: goto P_0c069eb4;
case 0x0c069eb6u: goto P_0c069eb6;
case 0x0c069eb8u: goto P_0c069eb8;
case 0x0c069ebau: goto P_0c069eba;
case 0x0c069ebcu: goto P_0c069ebc;
case 0x0c069ebeu: goto P_0c069ebe;
case 0x0c069ec0u: goto P_0c069ec0;
case 0x0c069ec2u: goto P_0c069ec2;
case 0x0c069ec4u: goto P_0c069ec4;
case 0x0c069ec6u: goto P_0c069ec6;
case 0x0c069ec8u: goto P_0c069ec8;
case 0x0c069ecau: goto P_0c069eca;
case 0x0c069eccu: goto P_0c069ecc;
case 0x0c069eceu: goto P_0c069ece;
case 0x0c069ed0u: goto P_0c069ed0;
case 0x0c069ed2u: goto P_0c069ed2;
case 0x0c069ed4u: goto P_0c069ed4;
case 0x0c069ed6u: goto P_0c069ed6;
case 0x0c069ed8u: goto P_0c069ed8;
case 0x0c069edau: goto P_0c069eda;
case 0x0c069edcu: goto P_0c069edc;
case 0x0c069edeu: goto P_0c069ede;
case 0x0c069ee0u: goto P_0c069ee0;
case 0x0c069ee2u: goto P_0c069ee2;
case 0x0c069ee4u: goto P_0c069ee4;
case 0x0c069ee6u: goto P_0c069ee6;
case 0x0c069ee8u: goto P_0c069ee8;
case 0x0c069eeau: goto P_0c069eea;
case 0x0c069eecu: goto P_0c069eec;
case 0x0c069eeeu: goto P_0c069eee;
case 0x0c069ef0u: goto P_0c069ef0;
case 0x0c069ef2u: goto P_0c069ef2;
case 0x0c069ef4u: goto P_0c069ef4;
case 0x0c069ef6u: goto P_0c069ef6;
case 0x0c069ef8u: goto P_0c069ef8;
case 0x0c069efau: goto P_0c069efa;
case 0x0c069efcu: goto P_0c069efc;
case 0x0c069efeu: goto P_0c069efe;
case 0x0c069f00u: goto P_0c069f00;
case 0x0c069f02u: goto P_0c069f02;
case 0x0c069f04u: goto P_0c069f04;
case 0x0c069f06u: goto P_0c069f06;
case 0x0c069f08u: goto P_0c069f08;
case 0x0c069f0au: goto P_0c069f0a;
case 0x0c069f0cu: goto P_0c069f0c;
case 0x0c069f0eu: goto P_0c069f0e;
case 0x0c069f10u: goto P_0c069f10;
case 0x0c069f12u: goto P_0c069f12;
case 0x0c069f14u: goto P_0c069f14;
case 0x0c069f16u: goto P_0c069f16;
case 0x0c069f18u: goto P_0c069f18;
case 0x0c069f1au: goto P_0c069f1a;
case 0x0c069f1cu: goto P_0c069f1c;
case 0x0c069f1eu: goto P_0c069f1e;
case 0x0c069f20u: goto P_0c069f20;
case 0x0c069f22u: goto P_0c069f22;
case 0x0c069f24u: goto P_0c069f24;
case 0x0c069f26u: goto P_0c069f26;
case 0x0c069f28u: goto P_0c069f28;
case 0x0c069f2au: goto P_0c069f2a;
case 0x0c069f2cu: goto P_0c069f2c;
case 0x0c069f2eu: goto P_0c069f2e;
case 0x0c069f30u: goto P_0c069f30;
case 0x0c069f32u: goto P_0c069f32;
case 0x0c069f34u: goto P_0c069f34;
case 0x0c069f36u: goto P_0c069f36;
case 0x0c069f38u: goto P_0c069f38;
case 0x0c069f3au: goto P_0c069f3a;
case 0x0c069f3cu: goto P_0c069f3c;
case 0x0c069f3eu: goto P_0c069f3e;
case 0x0c069f40u: goto P_0c069f40;
case 0x0c069f42u: goto P_0c069f42;
case 0x0c069f44u: goto P_0c069f44;
case 0x0c069f46u: goto P_0c069f46;
case 0x0c069f48u: goto P_0c069f48;
case 0x0c069f4au: goto P_0c069f4a;
case 0x0c069f4cu: goto P_0c069f4c;
case 0x0c069f4eu: goto P_0c069f4e;
case 0x0c069f50u: goto P_0c069f50;
case 0x0c069f52u: goto P_0c069f52;
case 0x0c069f54u: goto P_0c069f54;
case 0x0c069f56u: goto P_0c069f56;
case 0x0c069f58u: goto P_0c069f58;
case 0x0c069f5au: goto P_0c069f5a;
case 0x0c069f5cu: goto P_0c069f5c;
case 0x0c069f5eu: goto P_0c069f5e;
case 0x0c069f60u: goto P_0c069f60;
case 0x0c069f62u: goto P_0c069f62;
case 0x0c069f64u: goto P_0c069f64;
case 0x0c069f66u: goto P_0c069f66;
case 0x0c069f68u: goto P_0c069f68;
case 0x0c069f6au: goto P_0c069f6a;
case 0x0c069f6cu: goto P_0c069f6c;
case 0x0c069f6eu: goto P_0c069f6e;
case 0x0c069f70u: goto P_0c069f70;
case 0x0c069f72u: goto P_0c069f72;
case 0x0c069f74u: goto P_0c069f74;
case 0x0c069f76u: goto P_0c069f76;
case 0x0c069f78u: goto P_0c069f78;
case 0x0c069f7au: goto P_0c069f7a;
case 0x0c069f7cu: goto P_0c069f7c;
case 0x0c069f7eu: goto P_0c069f7e;
case 0x0c069f80u: goto P_0c069f80;
case 0x0c069f82u: goto P_0c069f82;
case 0x0c069f84u: goto P_0c069f84;
case 0x0c069f86u: goto P_0c069f86;
case 0x0c069f88u: goto P_0c069f88;
case 0x0c069f8au: goto P_0c069f8a;
case 0x0c069f8cu: goto P_0c069f8c;
case 0x0c069f8eu: goto P_0c069f8e;
case 0x0c069f90u: goto P_0c069f90;
case 0x0c069f92u: goto P_0c069f92;
case 0x0c069f94u: goto P_0c069f94;
case 0x0c069f96u: goto P_0c069f96;
case 0x0c069f98u: goto P_0c069f98;
case 0x0c069fbcu: goto P_0c069fbc;
case 0x0c069fbeu: goto P_0c069fbe;
case 0x0c069fc0u: goto P_0c069fc0;
case 0x0c069fc2u: goto P_0c069fc2;
case 0x0c069fc4u: goto P_0c069fc4;
case 0x0c069fc6u: goto P_0c069fc6;
case 0x0c069fc8u: goto P_0c069fc8;
case 0x0c069fcau: goto P_0c069fca;
case 0x0c069fccu: goto P_0c069fcc;
case 0x0c069fceu: goto P_0c069fce;
case 0x0c069fd0u: goto P_0c069fd0;
case 0x0c069fd2u: goto P_0c069fd2;
case 0x0c069fd4u: goto P_0c069fd4;
case 0x0c069fd6u: goto P_0c069fd6;
case 0x0c069fd8u: goto P_0c069fd8;
case 0x0c069fdau: goto P_0c069fda;
case 0x0c069fdcu: goto P_0c069fdc;
case 0x0c069fdeu: goto P_0c069fde;
case 0x0c069fe0u: goto P_0c069fe0;
case 0x0c069fe2u: goto P_0c069fe2;
case 0x0c069fe4u: goto P_0c069fe4;
case 0x0c069fe6u: goto P_0c069fe6;
case 0x0c069fe8u: goto P_0c069fe8;
case 0x0c069feau: goto P_0c069fea;
case 0x0c069fecu: goto P_0c069fec;
case 0x0c069feeu: goto P_0c069fee;
case 0x0c069ff0u: goto P_0c069ff0;
case 0x0c069ff2u: goto P_0c069ff2;
case 0x0c069ff4u: goto P_0c069ff4;
case 0x0c069ff6u: goto P_0c069ff6;
case 0x0c069ff8u: goto P_0c069ff8;
case 0x0c069ffau: goto P_0c069ffa;
case 0x0c069ffcu: goto P_0c069ffc;
case 0x0c069ffeu: goto P_0c069ffe;
case 0x0c06a000u: goto P_0c06a000;
case 0x0c06a002u: goto P_0c06a002;
case 0x0c06a004u: goto P_0c06a004;
case 0x0c06a006u: goto P_0c06a006;
case 0x0c06a008u: goto P_0c06a008;
case 0x0c06a00au: goto P_0c06a00a;
case 0x0c06a00cu: goto P_0c06a00c;
case 0x0c06a00eu: goto P_0c06a00e;
case 0x0c06a010u: goto P_0c06a010;
case 0x0c06a012u: goto P_0c06a012;
case 0x0c06a014u: goto P_0c06a014;
case 0x0c06a016u: goto P_0c06a016;
case 0x0c06a018u: goto P_0c06a018;
case 0x0c06a01au: goto P_0c06a01a;
case 0x0c06a01cu: goto P_0c06a01c;
case 0x0c06a01eu: goto P_0c06a01e;
case 0x0c06a020u: goto P_0c06a020;
case 0x0c06a022u: goto P_0c06a022;
case 0x0c06a024u: goto P_0c06a024;
case 0x0c06a026u: goto P_0c06a026;
case 0x0c06a028u: goto P_0c06a028;
case 0x0c06a02au: goto P_0c06a02a;
case 0x0c06a02cu: goto P_0c06a02c;
case 0x0c06a02eu: goto P_0c06a02e;
case 0x0c06a030u: goto P_0c06a030;
case 0x0c06a032u: goto P_0c06a032;
case 0x0c06a034u: goto P_0c06a034;
case 0x0c06a036u: goto P_0c06a036;
case 0x0c06a038u: goto P_0c06a038;
case 0x0c06a03au: goto P_0c06a03a;
case 0x0c06a03cu: goto P_0c06a03c;
case 0x0c06a03eu: goto P_0c06a03e;
case 0x0c06a040u: goto P_0c06a040;
case 0x0c06a042u: goto P_0c06a042;
case 0x0c06a044u: goto P_0c06a044;
case 0x0c06a046u: goto P_0c06a046;
case 0x0c06a048u: goto P_0c06a048;
case 0x0c06a04au: goto P_0c06a04a;
case 0x0c06a04cu: goto P_0c06a04c;
case 0x0c06a04eu: goto P_0c06a04e;
case 0x0c06a050u: goto P_0c06a050;
case 0x0c06a052u: goto P_0c06a052;
case 0x0c06a054u: goto P_0c06a054;
case 0x0c06a056u: goto P_0c06a056;
case 0x0c06a058u: goto P_0c06a058;
case 0x0c06a05au: goto P_0c06a05a;
case 0x0c06a05cu: goto P_0c06a05c;
case 0x0c06a05eu: goto P_0c06a05e;
case 0x0c06a060u: goto P_0c06a060;
case 0x0c06a062u: goto P_0c06a062;
case 0x0c06a064u: goto P_0c06a064;
case 0x0c06a066u: goto P_0c06a066;
case 0x0c06a068u: goto P_0c06a068;
case 0x0c06a06au: goto P_0c06a06a;
case 0x0c06a06cu: goto P_0c06a06c;
case 0x0c06a06eu: goto P_0c06a06e;
case 0x0c06a070u: goto P_0c06a070;
case 0x0c06a072u: goto P_0c06a072;
case 0x0c06a074u: goto P_0c06a074;
case 0x0c06a076u: goto P_0c06a076;
case 0x0c06a078u: goto P_0c06a078;
case 0x0c06a07au: goto P_0c06a07a;
case 0x0c06a07cu: goto P_0c06a07c;
case 0x0c06a07eu: goto P_0c06a07e;
case 0x0c06a080u: goto P_0c06a080;
case 0x0c06a082u: goto P_0c06a082;
case 0x0c06a084u: goto P_0c06a084;
case 0x0c06a086u: goto P_0c06a086;
case 0x0c06a088u: goto P_0c06a088;
case 0x0c06a08au: goto P_0c06a08a;
case 0x0c06a08cu: goto P_0c06a08c;
case 0x0c06a08eu: goto P_0c06a08e;
case 0x0c06a090u: goto P_0c06a090;
case 0x0c06a092u: goto P_0c06a092;
case 0x0c06a094u: goto P_0c06a094;
case 0x0c06a096u: goto P_0c06a096;
case 0x0c06a098u: goto P_0c06a098;
case 0x0c06a09au: goto P_0c06a09a;
case 0x0c06a09cu: goto P_0c06a09c;
case 0x0c06a09eu: goto P_0c06a09e;
case 0x0c06a0b0u: goto P_0c06a0b0;
case 0x0c06a0b2u: goto P_0c06a0b2;
case 0x0c06a0b4u: goto P_0c06a0b4;
case 0x0c06a0b6u: goto P_0c06a0b6;
case 0x0c06a0b8u: goto P_0c06a0b8;
case 0x0c06a0bau: goto P_0c06a0ba;
case 0x0c06a0bcu: goto P_0c06a0bc;
case 0x0c06a0beu: goto P_0c06a0be;
case 0x0c06a0c0u: goto P_0c06a0c0;
case 0x0c06a0c2u: goto P_0c06a0c2;
case 0x0c06a0c4u: goto P_0c06a0c4;
case 0x0c06a0c6u: goto P_0c06a0c6;
case 0x0c06a0c8u: goto P_0c06a0c8;
case 0x0c06a0cau: goto P_0c06a0ca;
case 0x0c06a0ccu: goto P_0c06a0cc;
case 0x0c06a0ceu: goto P_0c06a0ce;
case 0x0c06a0d0u: goto P_0c06a0d0;
case 0x0c06a0d2u: goto P_0c06a0d2;
case 0x0c06a0d4u: goto P_0c06a0d4;
case 0x0c06a0d6u: goto P_0c06a0d6;
case 0x0c06a0d8u: goto P_0c06a0d8;
case 0x0c06a0dau: goto P_0c06a0da;
case 0x0c06a0dcu: goto P_0c06a0dc;
case 0x0c06a0deu: goto P_0c06a0de;
case 0x0c06a0e0u: goto P_0c06a0e0;
case 0x0c06a0e2u: goto P_0c06a0e2;
case 0x0c06a0e4u: goto P_0c06a0e4;
case 0x0c06a0e6u: goto P_0c06a0e6;
case 0x0c06a0e8u: goto P_0c06a0e8;
case 0x0c06a0eau: goto P_0c06a0ea;
case 0x0c06a0ecu: goto P_0c06a0ec;
case 0x0c06a0eeu: goto P_0c06a0ee;
case 0x0c06a0f0u: goto P_0c06a0f0;
case 0x0c06a0f2u: goto P_0c06a0f2;
case 0x0c06a0f4u: goto P_0c06a0f4;
case 0x0c06a0f6u: goto P_0c06a0f6;
case 0x0c06a0f8u: goto P_0c06a0f8;
case 0x0c06a0fau: goto P_0c06a0fa;
case 0x0c06a0fcu: goto P_0c06a0fc;
case 0x0c06a0feu: goto P_0c06a0fe;
case 0x0c06a100u: goto P_0c06a100;
case 0x0c06a102u: goto P_0c06a102;
case 0x0c06a104u: goto P_0c06a104;
case 0x0c06a106u: goto P_0c06a106;
case 0x0c06a108u: goto P_0c06a108;
case 0x0c06a10au: goto P_0c06a10a;
case 0x0c06a10cu: goto P_0c06a10c;
case 0x0c06a10eu: goto P_0c06a10e;
case 0x0c06a110u: goto P_0c06a110;
case 0x0c06a112u: goto P_0c06a112;
case 0x0c06a114u: goto P_0c06a114;
case 0x0c06a116u: goto P_0c06a116;
case 0x0c06a118u: goto P_0c06a118;
case 0x0c06a11au: goto P_0c06a11a;
case 0x0c06a11cu: goto P_0c06a11c;
case 0x0c06a11eu: goto P_0c06a11e;
case 0x0c06a120u: goto P_0c06a120;
case 0x0c06a122u: goto P_0c06a122;
case 0x0c06a134u: goto P_0c06a134;
case 0x0c06a136u: goto P_0c06a136;
case 0x0c06a138u: goto P_0c06a138;
case 0x0c06a13au: goto P_0c06a13a;
case 0x0c06a13cu: goto P_0c06a13c;
case 0x0c06a13eu: goto P_0c06a13e;
case 0x0c06a140u: goto P_0c06a140;
case 0x0c06a142u: goto P_0c06a142;
case 0x0c06a144u: goto P_0c06a144;
case 0x0c06a146u: goto P_0c06a146;
case 0x0c06a148u: goto P_0c06a148;
case 0x0c06a14au: goto P_0c06a14a;
case 0x0c06a14cu: goto P_0c06a14c;
case 0x0c06a14eu: goto P_0c06a14e;
case 0x0c06a150u: goto P_0c06a150;
case 0x0c06a152u: goto P_0c06a152;
case 0x0c06a154u: goto P_0c06a154;
case 0x0c06a156u: goto P_0c06a156;
case 0x0c06a158u: goto P_0c06a158;
case 0x0c06a15au: goto P_0c06a15a;
case 0x0c06a15cu: goto P_0c06a15c;
case 0x0c06a15eu: goto P_0c06a15e;
case 0x0c06a160u: goto P_0c06a160;
case 0x0c06a162u: goto P_0c06a162;
case 0x0c06a164u: goto P_0c06a164;
case 0x0c06a166u: goto P_0c06a166;
case 0x0c06a168u: goto P_0c06a168;
case 0x0c06a16au: goto P_0c06a16a;
case 0x0c06a16cu: goto P_0c06a16c;
case 0x0c06a16eu: goto P_0c06a16e;
case 0x0c06a170u: goto P_0c06a170;
case 0x0c06a172u: goto P_0c06a172;
case 0x0c06a174u: goto P_0c06a174;
case 0x0c06a176u: goto P_0c06a176;
case 0x0c06a178u: goto P_0c06a178;
case 0x0c06a17au: goto P_0c06a17a;
case 0x0c06a17cu: goto P_0c06a17c;
case 0x0c06a17eu: goto P_0c06a17e;
case 0x0c06a180u: goto P_0c06a180;
case 0x0c06a182u: goto P_0c06a182;
case 0x0c06a184u: goto P_0c06a184;
case 0x0c06a186u: goto P_0c06a186;
case 0x0c06a188u: goto P_0c06a188;
case 0x0c06a18au: goto P_0c06a18a;
case 0x0c06a18cu: goto P_0c06a18c;
case 0x0c06a18eu: goto P_0c06a18e;
case 0x0c06a190u: goto P_0c06a190;
case 0x0c06a192u: goto P_0c06a192;
case 0x0c06a194u: goto P_0c06a194;
case 0x0c06a196u: goto P_0c06a196;
case 0x0c06a198u: goto P_0c06a198;
case 0x0c06a19au: goto P_0c06a19a;
case 0x0c06a19cu: goto P_0c06a19c;
case 0x0c06a19eu: goto P_0c06a19e;
case 0x0c06a1a0u: goto P_0c06a1a0;
case 0x0c06a1a2u: goto P_0c06a1a2;
case 0x0c06a1a4u: goto P_0c06a1a4;
case 0x0c06a1a6u: goto P_0c06a1a6;
case 0x0c06a1a8u: goto P_0c06a1a8;
case 0x0c06a1aau: goto P_0c06a1aa;
case 0x0c06a1acu: goto P_0c06a1ac;
case 0x0c06a1aeu: goto P_0c06a1ae;
case 0x0c06a1b0u: goto P_0c06a1b0;
case 0x0c06a1b2u: goto P_0c06a1b2;
case 0x0c06a1b4u: goto P_0c06a1b4;
case 0x0c06a1b6u: goto P_0c06a1b6;
case 0x0c06a1b8u: goto P_0c06a1b8;
case 0x0c06a1bau: goto P_0c06a1ba;
case 0x0c06a1bcu: goto P_0c06a1bc;
case 0x0c06a1beu: goto P_0c06a1be;
case 0x0c06a1c0u: goto P_0c06a1c0;
case 0x0c06a1c2u: goto P_0c06a1c2;
case 0x0c06a1c4u: goto P_0c06a1c4;
case 0x0c06a1c6u: goto P_0c06a1c6;
case 0x0c06a1c8u: goto P_0c06a1c8;
case 0x0c06a1cau: goto P_0c06a1ca;
case 0x0c06a1ccu: goto P_0c06a1cc;
case 0x0c06a1ceu: goto P_0c06a1ce;
case 0x0c06a1d0u: goto P_0c06a1d0;
case 0x0c06a1d2u: goto P_0c06a1d2;
case 0x0c06a1d4u: goto P_0c06a1d4;
case 0x0c06a1d6u: goto P_0c06a1d6;
case 0x0c06a1d8u: goto P_0c06a1d8;
case 0x0c06a1dau: goto P_0c06a1da;
case 0x0c06a1dcu: goto P_0c06a1dc;
case 0x0c06a1deu: goto P_0c06a1de;
case 0x0c06a1e0u: goto P_0c06a1e0;
case 0x0c06a1e2u: goto P_0c06a1e2;
case 0x0c06a1e4u: goto P_0c06a1e4;
case 0x0c06a1e6u: goto P_0c06a1e6;
case 0x0c06a1e8u: goto P_0c06a1e8;
case 0x0c06a1eau: goto P_0c06a1ea;
case 0x0c06a1ecu: goto P_0c06a1ec;
case 0x0c06a1eeu: goto P_0c06a1ee;
case 0x0c06a1f0u: goto P_0c06a1f0;
case 0x0c06a1f2u: goto P_0c06a1f2;
case 0x0c06a1f4u: goto P_0c06a1f4;
case 0x0c06a1f6u: goto P_0c06a1f6;
case 0x0c06a1f8u: goto P_0c06a1f8;
case 0x0c06a1fau: goto P_0c06a1fa;
case 0x0c06a1fcu: goto P_0c06a1fc;
case 0x0c06a1feu: goto P_0c06a1fe;
case 0x0c06a200u: goto P_0c06a200;
case 0x0c06a202u: goto P_0c06a202;
case 0x0c06a204u: goto P_0c06a204;
case 0x0c06a206u: goto P_0c06a206;
case 0x0c06a208u: goto P_0c06a208;
case 0x0c06a20au: goto P_0c06a20a;
case 0x0c06a20cu: goto P_0c06a20c;
case 0x0c06a20eu: goto P_0c06a20e;
case 0x0c06a210u: goto P_0c06a210;
case 0x0c06a212u: goto P_0c06a212;
case 0x0c06a214u: goto P_0c06a214;
case 0x0c06a216u: goto P_0c06a216;
case 0x0c06a218u: goto P_0c06a218;
case 0x0c06a21au: goto P_0c06a21a;
case 0x0c06a21cu: goto P_0c06a21c;
case 0x0c06a21eu: goto P_0c06a21e;
case 0x0c06a220u: goto P_0c06a220;
case 0x0c06a222u: goto P_0c06a222;
case 0x0c06a224u: goto P_0c06a224;
case 0x0c06a226u: goto P_0c06a226;
case 0x0c06a228u: goto P_0c06a228;
case 0x0c06a22au: goto P_0c06a22a;
case 0x0c06a22cu: goto P_0c06a22c;
case 0x0c06a22eu: goto P_0c06a22e;
case 0x0c06a230u: goto P_0c06a230;
case 0x0c06a232u: goto P_0c06a232;
case 0x0c06a234u: goto P_0c06a234;
case 0x0c06a236u: goto P_0c06a236;
case 0x0c06a238u: goto P_0c06a238;
case 0x0c06a23au: goto P_0c06a23a;
case 0x0c06a23cu: goto P_0c06a23c;
case 0x0c06a23eu: goto P_0c06a23e;
case 0x0c06a240u: goto P_0c06a240;
case 0x0c06a242u: goto P_0c06a242;
case 0x0c06a244u: goto P_0c06a244;
case 0x0c06a246u: goto P_0c06a246;
case 0x0c06a248u: goto P_0c06a248;
case 0x0c06a24au: goto P_0c06a24a;
case 0x0c06a24cu: goto P_0c06a24c;
case 0x0c06a24eu: goto P_0c06a24e;
case 0x0c06a250u: goto P_0c06a250;
case 0x0c06a252u: goto P_0c06a252;
case 0x0c06a254u: goto P_0c06a254;
case 0x0c06a256u: goto P_0c06a256;
case 0x0c06a258u: goto P_0c06a258;
case 0x0c06a25au: goto P_0c06a25a;
case 0x0c06a25cu: goto P_0c06a25c;
case 0x0c06a25eu: goto P_0c06a25e;
case 0x0c06a260u: goto P_0c06a260;
case 0x0c06a262u: goto P_0c06a262;
case 0x0c06a28cu: goto P_0c06a28c;
case 0x0c06a28eu: goto P_0c06a28e;
case 0x0c06a290u: goto P_0c06a290;
case 0x0c06a292u: goto P_0c06a292;
case 0x0c06a294u: goto P_0c06a294;
case 0x0c06a296u: goto P_0c06a296;
case 0x0c06a298u: goto P_0c06a298;
case 0x0c06a29au: goto P_0c06a29a;
case 0x0c06a29cu: goto P_0c06a29c;
case 0x0c06a29eu: goto P_0c06a29e;
case 0x0c06a2a0u: goto P_0c06a2a0;
case 0x0c06a2a2u: goto P_0c06a2a2;
case 0x0c06a2a4u: goto P_0c06a2a4;
case 0x0c06a2a6u: goto P_0c06a2a6;
case 0x0c06a2a8u: goto P_0c06a2a8;
case 0x0c06a2aau: goto P_0c06a2aa;
case 0x0c06a2acu: goto P_0c06a2ac;
case 0x0c06a2aeu: goto P_0c06a2ae;
case 0x0c06a2b0u: goto P_0c06a2b0;
case 0x0c06a2b2u: goto P_0c06a2b2;
case 0x0c06a2b4u: goto P_0c06a2b4;
case 0x0c06a2b6u: goto P_0c06a2b6;
case 0x0c06a2b8u: goto P_0c06a2b8;
case 0x0c06a2bau: goto P_0c06a2ba;
case 0x0c06a2bcu: goto P_0c06a2bc;
case 0x0c06a2beu: goto P_0c06a2be;
case 0x0c06a2c0u: goto P_0c06a2c0;
case 0x0c06a2c2u: goto P_0c06a2c2;
case 0x0c06a2c4u: goto P_0c06a2c4;
case 0x0c06a2c6u: goto P_0c06a2c6;
case 0x0c06a2c8u: goto P_0c06a2c8;
case 0x0c06a2cau: goto P_0c06a2ca;
case 0x0c06a2ccu: goto P_0c06a2cc;
case 0x0c06a2ceu: goto P_0c06a2ce;
case 0x0c06a2d0u: goto P_0c06a2d0;
case 0x0c06a2d2u: goto P_0c06a2d2;
case 0x0c06a2d4u: goto P_0c06a2d4;
case 0x0c06a2d6u: goto P_0c06a2d6;
case 0x0c06a2d8u: goto P_0c06a2d8;
case 0x0c06a2dau: goto P_0c06a2da;
case 0x0c06a2dcu: goto P_0c06a2dc;
case 0x0c06a2deu: goto P_0c06a2de;
case 0x0c06a2e0u: goto P_0c06a2e0;
case 0x0c06a2e2u: goto P_0c06a2e2;
case 0x0c06a2e4u: goto P_0c06a2e4;
case 0x0c06a2e6u: goto P_0c06a2e6;
case 0x0c06a2e8u: goto P_0c06a2e8;
case 0x0c06a2eau: goto P_0c06a2ea;
case 0x0c06a2ecu: goto P_0c06a2ec;
case 0x0c06a2eeu: goto P_0c06a2ee;
case 0x0c06a2f0u: goto P_0c06a2f0;
case 0x0c06a2f2u: goto P_0c06a2f2;
case 0x0c06a2f4u: goto P_0c06a2f4;
case 0x0c06a2f6u: goto P_0c06a2f6;
case 0x0c06a2f8u: goto P_0c06a2f8;
case 0x0c06a2fau: goto P_0c06a2fa;
case 0x0c06a2fcu: goto P_0c06a2fc;
case 0x0c06a2feu: goto P_0c06a2fe;
case 0x0c06a300u: goto P_0c06a300;
case 0x0c06a302u: goto P_0c06a302;
case 0x0c06a304u: goto P_0c06a304;
case 0x0c06a306u: goto P_0c06a306;
case 0x0c06a308u: goto P_0c06a308;
case 0x0c06a30au: goto P_0c06a30a;
case 0x0c06a30cu: goto P_0c06a30c;
case 0x0c06a30eu: goto P_0c06a30e;
case 0x0c06a310u: goto P_0c06a310;
case 0x0c06a312u: goto P_0c06a312;
case 0x0c06a314u: goto P_0c06a314;
case 0x0c06a316u: goto P_0c06a316;
case 0x0c06a318u: goto P_0c06a318;
case 0x0c06a31au: goto P_0c06a31a;
case 0x0c06a31cu: goto P_0c06a31c;
case 0x0c06a31eu: goto P_0c06a31e;
case 0x0c06a320u: goto P_0c06a320;
case 0x0c06a322u: goto P_0c06a322;
case 0x0c06a324u: goto P_0c06a324;
case 0x0c06a326u: goto P_0c06a326;
case 0x0c06a328u: goto P_0c06a328;
case 0x0c06a32au: goto P_0c06a32a;
case 0x0c06a32cu: goto P_0c06a32c;
case 0x0c06a32eu: goto P_0c06a32e;
case 0x0c06a330u: goto P_0c06a330;
case 0x0c06a332u: goto P_0c06a332;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0698ec: /* original 2fe6, guest PC 0x0c0698ec */
if(!s->budget--) { s->failed_pc=0x0c0698ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0698ee;
P_0c0698ee: /* original e078, guest PC 0x0c0698ee */
if(!s->budget--) { s->failed_pc=0x0c0698eeu; return 0; }
r[0]=0x00000078u;
goto P_0c0698f0;
P_0c0698f0: /* original 2fd6, guest PC 0x0c0698f0 */
if(!s->budget--) { s->failed_pc=0x0c0698f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0698f2;
P_0c0698f2: /* original 2fc6, guest PC 0x0c0698f2 */
if(!s->budget--) { s->failed_pc=0x0c0698f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0698f4;
P_0c0698f4: /* original 2fb6, guest PC 0x0c0698f4 */
if(!s->budget--) { s->failed_pc=0x0c0698f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0698f6;
P_0c0698f6: /* original 2fa6, guest PC 0x0c0698f6 */
if(!s->budget--) { s->failed_pc=0x0c0698f6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0698f8;
P_0c0698f8: /* original 2f96, guest PC 0x0c0698f8 */
if(!s->budget--) { s->failed_pc=0x0c0698f8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0698fa;
P_0c0698fa: /* original 2f86, guest PC 0x0c0698fa */
if(!s->budget--) { s->failed_pc=0x0c0698fau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0698fc;
P_0c0698fc: /* original 4f22, guest PC 0x0c0698fc */
if(!s->budget--) { s->failed_pc=0x0c0698fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0698fe;
P_0c0698fe: /* original d251, guest PC 0x0c0698fe */
if(!s->budget--) { s->failed_pc=0x0c0698feu; return 0; }
r[2]=read(ram,0x0c069a44u,4);
goto P_0c069900;
P_0c069900: /* original d44f, guest PC 0x0c069900 */
if(!s->budget--) { s->failed_pc=0x0c069900u; return 0; }
r[4]=read(ram,0x0c069a40u,4);
goto P_0c069902;
P_0c069902: /* original 4f12, guest PC 0x0c069902 */
if(!s->budget--) { s->failed_pc=0x0c069902u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c069904;
P_0c069904: /* original 6322, guest PC 0x0c069904 */
if(!s->budget--) { s->failed_pc=0x0c069904u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c069906;
P_0c069906: /* original 9e8f, guest PC 0x0c069906 */
if(!s->budget--) { s->failed_pc=0x0c069906u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a28u,2);
goto P_0c069908;
P_0c069908: /* original 7f84, guest PC 0x0c069908 */
if(!s->budget--) { s->failed_pc=0x0c069908u; return 0; }
r[15]+=0xffffff84u;
goto P_0c06990a;
P_0c06990a: /* original 0f36, guest PC 0x0c06990a */
if(!s->budget--) { s->failed_pc=0x0c06990au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06990c;
P_0c06990c: /* original e02b, guest PC 0x0c06990c */
if(!s->budget--) { s->failed_pc=0x0c06990cu; return 0; }
r[0]=0x0000002bu;
goto P_0c06990e;
P_0c06990e: /* original d34e, guest PC 0x0c06990e */
if(!s->budget--) { s->failed_pc=0x0c06990eu; return 0; }
r[3]=read(ram,0x0c069a48u,4);
goto P_0c069910;
P_0c069910: /* original 3e4c, guest PC 0x0c069910 */
if(!s->budget--) { s->failed_pc=0x0c069910u; return 0; }
r[14]+=r[4];
goto P_0c069912;
P_0c069912: /* original 6132, guest PC 0x0c069912 */
if(!s->budget--) { s->failed_pc=0x0c069912u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c069914;
P_0c069914: /* original 1f16, guest PC 0x0c069914 */
if(!s->budget--) { s->failed_pc=0x0c069914u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c069916;
P_0c069916: /* original dd4d, guest PC 0x0c069916 */
if(!s->budget--) { s->failed_pc=0x0c069916u; return 0; }
r[13]=read(ram,0x0c069a4cu,4);
goto P_0c069918;
P_0c069918: /* original 51d2, guest PC 0x0c069918 */
if(!s->budget--) { s->failed_pc=0x0c069918u; return 0; }
r[1]=read(ram,r[13]+8,4);
goto P_0c06991a;
P_0c06991a: /* original 1f15, guest PC 0x0c06991a */
if(!s->budget--) { s->failed_pc=0x0c06991au; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c06991c;
P_0c06991c: /* original 04dc, guest PC 0x0c06991c */
if(!s->budget--) { s->failed_pc=0x0c06991cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06991e;
P_0c06991e: /* original e018, guest PC 0x0c06991e */
if(!s->budget--) { s->failed_pc=0x0c06991eu; return 0; }
r[0]=0x00000018u;
goto P_0c069920;
P_0c069920: /* original 07dc, guest PC 0x0c069920 */
if(!s->budget--) { s->failed_pc=0x0c069920u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c069922;
P_0c069922: /* original e019, guest PC 0x0c069922 */
if(!s->budget--) { s->failed_pc=0x0c069922u; return 0; }
r[0]=0x00000019u;
goto P_0c069924;
P_0c069924: /* original 08dc, guest PC 0x0c069924 */
if(!s->budget--) { s->failed_pc=0x0c069924u; return 0; }
r[8]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c069926;
P_0c069926: /* original 74ff, guest PC 0x0c069926 */
if(!s->budget--) { s->failed_pc=0x0c069926u; return 0; }
r[4]+=0xffffffffu;
goto P_0c069928;
P_0c069928: /* original 677c, guest PC 0x0c069928 */
if(!s->budget--) { s->failed_pc=0x0c069928u; return 0; }
r[7]=r[7]&255u;
goto P_0c06992a;
P_0c06992a: /* original 688c, guest PC 0x0c06992a */
if(!s->budget--) { s->failed_pc=0x0c06992au; return 0; }
r[8]=r[8]&255u;
goto P_0c06992c;
P_0c06992c: /* original e01d, guest PC 0x0c06992c */
if(!s->budget--) { s->failed_pc=0x0c06992cu; return 0; }
r[0]=0x0000001du;
goto P_0c06992e;
P_0c06992e: /* original 61f3, guest PC 0x0c06992e */
if(!s->budget--) { s->failed_pc=0x0c06992eu; return 0; }
r[1]=r[15];
goto P_0c069930;
P_0c069930: /* original 05dc, guest PC 0x0c069930 */
if(!s->budget--) { s->failed_pc=0x0c069930u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c069932;
P_0c069932: /* original e029, guest PC 0x0c069932 */
if(!s->budget--) { s->failed_pc=0x0c069932u; return 0; }
r[0]=0x00000029u;
goto P_0c069934;
P_0c069934: /* original 06dc, guest PC 0x0c069934 */
if(!s->budget--) { s->failed_pc=0x0c069934u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c069936;
P_0c069936: /* original 6083, guest PC 0x0c069936 */
if(!s->budget--) { s->failed_pc=0x0c069936u; return 0; }
r[0]=r[8];
goto P_0c069938;
P_0c069938: /* original 8802, guest PC 0x0c069938 */
if(!s->budget--) { s->failed_pc=0x0c069938u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c06993a;
P_0c06993a: /* original 7140, guest PC 0x0c06993a */
if(!s->budget--) { s->failed_pc=0x0c06993au; return 0; }
r[1]+=0x00000040u;
goto P_0c06993c;
P_0c06993c: /* original 0029, guest PC 0x0c06993c */
if(!s->budget--) { s->failed_pc=0x0c06993cu; return 0; }
r[0]=r[17]&1u;
goto P_0c06993e;
P_0c06993e: /* original 1f0e, guest PC 0x0c06993e */
if(!s->budget--) { s->failed_pc=0x0c06993eu; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c069940;
P_0c069940: /* original 2778, guest PC 0x0c069940 */
if(!s->budget--) { s->failed_pc=0x0c069940u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c069942;
P_0c069942: /* original 0029, guest PC 0x0c069942 */
if(!s->budget--) { s->failed_pc=0x0c069942u; return 0; }
r[0]=r[17]&1u;
goto P_0c069944;
P_0c069944: /* original 1f0f, guest PC 0x0c069944 */
if(!s->budget--) { s->failed_pc=0x0c069944u; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c069946;
P_0c069946: /* original 6073, guest PC 0x0c069946 */
if(!s->budget--) { s->failed_pc=0x0c069946u; return 0; }
r[0]=r[7];
goto P_0c069948;
P_0c069948: /* original 8801, guest PC 0x0c069948 */
if(!s->budget--) { s->failed_pc=0x0c069948u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06994a;
P_0c06994a: /* original 655c, guest PC 0x0c06994a */
if(!s->budget--) { s->failed_pc=0x0c06994au; return 0; }
r[5]=r[5]&255u;
goto P_0c06994c;
P_0c06994c: /* original 0029, guest PC 0x0c06994c */
if(!s->budget--) { s->failed_pc=0x0c06994cu; return 0; }
r[0]=r[17]&1u;
goto P_0c06994e;
P_0c06994e: /* original 2102, guest PC 0x0c06994e */
if(!s->budget--) { s->failed_pc=0x0c06994eu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c069950;
P_0c069950: /* original 6073, guest PC 0x0c069950 */
if(!s->budget--) { s->failed_pc=0x0c069950u; return 0; }
r[0]=r[7];
goto P_0c069952;
P_0c069952: /* original 8802, guest PC 0x0c069952 */
if(!s->budget--) { s->failed_pc=0x0c069952u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c069954;
P_0c069954: /* original 666c, guest PC 0x0c069954 */
if(!s->budget--) { s->failed_pc=0x0c069954u; return 0; }
r[6]=r[6]&255u;
goto P_0c069956;
P_0c069956: /* original 0029, guest PC 0x0c069956 */
if(!s->budget--) { s->failed_pc=0x0c069956u; return 0; }
r[0]=r[17]&1u;
goto P_0c069958;
P_0c069958: /* original 2558, guest PC 0x0c069958 */
if(!s->budget--) { s->failed_pc=0x0c069958u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06995a;
P_0c06995a: /* original 1f07, guest PC 0x0c06995a */
if(!s->budget--) { s->failed_pc=0x0c06995au; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c06995c;
P_0c06995c: /* original 0029, guest PC 0x0c06995c */
if(!s->budget--) { s->failed_pc=0x0c06995cu; return 0; }
r[0]=r[17]&1u;
goto P_0c06995e;
P_0c06995e: /* original 1f09, guest PC 0x0c06995e */
if(!s->budget--) { s->failed_pc=0x0c06995eu; return 0; }
write(ram,r[15]+36,r[0],4);
goto P_0c069960;
P_0c069960: /* original 6063, guest PC 0x0c069960 */
if(!s->budget--) { s->failed_pc=0x0c069960u; return 0; }
r[0]=r[6];
goto P_0c069962;
P_0c069962: /* original dc3c, guest PC 0x0c069962 */
if(!s->budget--) { s->failed_pc=0x0c069962u; return 0; }
r[12]=read(ram,0x0c069a54u,4);
goto P_0c069964;
P_0c069964: /* original 8803, guest PC 0x0c069964 */
if(!s->budget--) { s->failed_pc=0x0c069964u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c069966;
P_0c069966: /* original db3a, guest PC 0x0c069966 */
if(!s->budget--) { s->failed_pc=0x0c069966u; return 0; }
r[11]=read(ram,0x0c069a50u,4);
goto P_0c069968;
P_0c069968: /* original e914, guest PC 0x0c069968 */
if(!s->budget--) { s->failed_pc=0x0c069968u; return 0; }
r[9]=0x00000014u;
goto P_0c06996a;
P_0c06996a: /* original 8f02, guest PC 0x0c06996a */
if(!s->budget--) { s->failed_pc=0x0c06996au; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(!cond) { goto P_0c069972; }
goto P_0c06996e;
P_0c06996c: /* original ea00, guest PC 0x0c06996c */
if(!s->budget--) { s->failed_pc=0x0c06996cu; return 0; }
r[10]=0x00000000u;
goto P_0c06996e;
P_0c06996e: /* original a290, guest PC 0x0c06996e */
if(!s->budget--) { s->failed_pc=0x0c06996eu; return 0; }
goto P_0c069e92;
P_0c069970: /* original 0009, guest PC 0x0c069970 */
if(!s->budget--) { s->failed_pc=0x0c069970u; return 0; }
goto P_0c069972;
P_0c069972: /* original 76ff, guest PC 0x0c069972 */
if(!s->budget--) { s->failed_pc=0x0c069972u; return 0; }
r[6]+=0xffffffffu;
goto P_0c069974;
P_0c069974: /* original 3650, guest PC 0x0c069974 */
if(!s->budget--) { s->failed_pc=0x0c069974u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[5])!=0);
goto P_0c069976;
P_0c069976: /* original 0029, guest PC 0x0c069976 */
if(!s->budget--) { s->failed_pc=0x0c069976u; return 0; }
r[0]=r[17]&1u;
goto P_0c069978;
P_0c069978: /* original 2f02, guest PC 0x0c069978 */
if(!s->budget--) { s->failed_pc=0x0c069978u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06997a;
P_0c06997a: /* original 9056, guest PC 0x0c06997a */
if(!s->budget--) { s->failed_pc=0x0c06997au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a2au,2);
goto P_0c06997c;
P_0c06997c: /* original 03de, guest PC 0x0c06997c */
if(!s->budget--) { s->failed_pc=0x0c06997cu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c06997e;
P_0c06997e: /* original 7301, guest PC 0x0c06997e */
if(!s->budget--) { s->failed_pc=0x0c06997eu; return 0; }
r[3]+=0x00000001u;
goto P_0c069980;
P_0c069980: /* original 0d36, guest PC 0x0c069980 */
if(!s->budget--) { s->failed_pc=0x0c069980u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c069982;
P_0c069982: /* original 52fe, guest PC 0x0c069982 */
if(!s->budget--) { s->failed_pc=0x0c069982u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c069984;
P_0c069984: /* original 2228, guest PC 0x0c069984 */
if(!s->budget--) { s->failed_pc=0x0c069984u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c069986;
P_0c069986: /* original 8903, guest PC 0x0c069986 */
if(!s->budget--) { s->failed_pc=0x0c069986u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069990; }
goto P_0c069988;
P_0c069988: /* original 9050, guest PC 0x0c069988 */
if(!s->budget--) { s->failed_pc=0x0c069988u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a2cu,2);
goto P_0c06998a;
P_0c06998a: /* original 03de, guest PC 0x0c06998a */
if(!s->budget--) { s->failed_pc=0x0c06998au; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c06998c;
P_0c06998c: /* original 7301, guest PC 0x0c06998c */
if(!s->budget--) { s->failed_pc=0x0c06998cu; return 0; }
r[3]+=0x00000001u;
goto P_0c06998e;
P_0c06998e: /* original 0d36, guest PC 0x0c06998e */
if(!s->budget--) { s->failed_pc=0x0c06998eu; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c069990;
P_0c069990: /* original 52ff, guest PC 0x0c069990 */
if(!s->budget--) { s->failed_pc=0x0c069990u; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c069992;
P_0c069992: /* original 2228, guest PC 0x0c069992 */
if(!s->budget--) { s->failed_pc=0x0c069992u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c069994;
P_0c069994: /* original 8903, guest PC 0x0c069994 */
if(!s->budget--) { s->failed_pc=0x0c069994u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06999e; }
goto P_0c069996;
P_0c069996: /* original 904a, guest PC 0x0c069996 */
if(!s->budget--) { s->failed_pc=0x0c069996u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a2eu,2);
goto P_0c069998;
P_0c069998: /* original 03de, guest PC 0x0c069998 */
if(!s->budget--) { s->failed_pc=0x0c069998u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c06999a;
P_0c06999a: /* original 7301, guest PC 0x0c06999a */
if(!s->budget--) { s->failed_pc=0x0c06999au; return 0; }
r[3]+=0x00000001u;
goto P_0c06999c;
P_0c06999c: /* original 0d36, guest PC 0x0c06999c */
if(!s->budget--) { s->failed_pc=0x0c06999cu; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c06999e;
P_0c06999e: /* original e040, guest PC 0x0c06999e */
if(!s->budget--) { s->failed_pc=0x0c06999eu; return 0; }
r[0]=0x00000040u;
goto P_0c0699a0;
P_0c0699a0: /* original 02fe, guest PC 0x0c0699a0 */
if(!s->budget--) { s->failed_pc=0x0c0699a0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0699a2;
P_0c0699a2: /* original 2228, guest PC 0x0c0699a2 */
if(!s->budget--) { s->failed_pc=0x0c0699a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0699a4;
P_0c0699a4: /* original 8903, guest PC 0x0c0699a4 */
if(!s->budget--) { s->failed_pc=0x0c0699a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0699ae; }
goto P_0c0699a6;
P_0c0699a6: /* original 9043, guest PC 0x0c0699a6 */
if(!s->budget--) { s->failed_pc=0x0c0699a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a30u,2);
goto P_0c0699a8;
P_0c0699a8: /* original 03de, guest PC 0x0c0699a8 */
if(!s->budget--) { s->failed_pc=0x0c0699a8u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c0699aa;
P_0c0699aa: /* original 7301, guest PC 0x0c0699aa */
if(!s->budget--) { s->failed_pc=0x0c0699aau; return 0; }
r[3]+=0x00000001u;
goto P_0c0699ac;
P_0c0699ac: /* original 0d36, guest PC 0x0c0699ac */
if(!s->budget--) { s->failed_pc=0x0c0699acu; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c0699ae;
P_0c0699ae: /* original 52f7, guest PC 0x0c0699ae */
if(!s->budget--) { s->failed_pc=0x0c0699aeu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c0699b0;
P_0c0699b0: /* original 2228, guest PC 0x0c0699b0 */
if(!s->budget--) { s->failed_pc=0x0c0699b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0699b2;
P_0c0699b2: /* original 8903, guest PC 0x0c0699b2 */
if(!s->budget--) { s->failed_pc=0x0c0699b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0699bc; }
goto P_0c0699b4;
P_0c0699b4: /* original 903d, guest PC 0x0c0699b4 */
if(!s->budget--) { s->failed_pc=0x0c0699b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a32u,2);
goto P_0c0699b6;
P_0c0699b6: /* original 03de, guest PC 0x0c0699b6 */
if(!s->budget--) { s->failed_pc=0x0c0699b6u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c0699b8;
P_0c0699b8: /* original 7301, guest PC 0x0c0699b8 */
if(!s->budget--) { s->failed_pc=0x0c0699b8u; return 0; }
r[3]+=0x00000001u;
goto P_0c0699ba;
P_0c0699ba: /* original 0d36, guest PC 0x0c0699ba */
if(!s->budget--) { s->failed_pc=0x0c0699bau; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c0699bc;
P_0c0699bc: /* original 52f5, guest PC 0x0c0699bc */
if(!s->budget--) { s->failed_pc=0x0c0699bcu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0699be;
P_0c0699be: /* original d326, guest PC 0x0c0699be */
if(!s->budget--) { s->failed_pc=0x0c0699beu; return 0; }
r[3]=read(ram,0x0c069a58u,4);
goto P_0c0699c0;
P_0c0699c0: /* original 2238, guest PC 0x0c0699c0 */
if(!s->budget--) { s->failed_pc=0x0c0699c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0699c2;
P_0c0699c2: /* original 8b01, guest PC 0x0c0699c2 */
if(!s->budget--) { s->failed_pc=0x0c0699c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0699c8; }
goto P_0c0699c4;
P_0c0699c4: /* original a4ab, guest PC 0x0c0699c4 */
if(!s->budget--) { s->failed_pc=0x0c0699c4u; return 0; }
goto P_0c06a31e;
P_0c0699c6: /* original 0009, guest PC 0x0c0699c6 */
if(!s->budget--) { s->failed_pc=0x0c0699c6u; return 0; }
goto P_0c0699c8;
P_0c0699c8: /* original 51f5, guest PC 0x0c0699c8 */
if(!s->budget--) { s->failed_pc=0x0c0699c8u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c0699ca;
P_0c0699ca: /* original d324, guest PC 0x0c0699ca */
if(!s->budget--) { s->failed_pc=0x0c0699cau; return 0; }
r[3]=read(ram,0x0c069a5cu,4);
goto P_0c0699cc;
P_0c0699cc: /* original 2139, guest PC 0x0c0699cc */
if(!s->budget--) { s->failed_pc=0x0c0699ccu; return 0; }
r[1]&=r[3];
goto P_0c0699ce;
P_0c0699ce: /* original 2118, guest PC 0x0c0699ce */
if(!s->budget--) { s->failed_pc=0x0c0699ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0699d0;
P_0c0699d0: /* original 8f19, guest PC 0x0c0699d0 */
if(!s->budget--) { s->failed_pc=0x0c0699d0u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[1],4);
if(!cond) { goto P_0c069a06; }
goto P_0c0699d4;
P_0c0699d2: /* original 1f11, guest PC 0x0c0699d2 */
if(!s->budget--) { s->failed_pc=0x0c0699d2u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0699d4;
P_0c0699d4: /* original 4408, guest PC 0x0c0699d4 */
if(!s->budget--) { s->failed_pc=0x0c0699d4u; return 0; }
r[4]<<=2;
goto P_0c0699d6;
P_0c0699d6: /* original 1f42, guest PC 0x0c0699d6 */
if(!s->budget--) { s->failed_pc=0x0c0699d6u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0699d8;
P_0c0699d8: /* original 932c, guest PC 0x0c0699d8 */
if(!s->budget--) { s->failed_pc=0x0c0699d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a34u,2);
goto P_0c0699da;
P_0c0699da: /* original 33dc, guest PC 0x0c0699da */
if(!s->budget--) { s->failed_pc=0x0c0699dau; return 0; }
r[3]+=r[13];
goto P_0c0699dc;
P_0c0699dc: /* original 343c, guest PC 0x0c0699dc */
if(!s->budget--) { s->failed_pc=0x0c0699dcu; return 0; }
r[4]+=r[3];
goto P_0c0699de;
P_0c0699de: /* original 6242, guest PC 0x0c0699de */
if(!s->budget--) { s->failed_pc=0x0c0699deu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0699e0;
P_0c0699e0: /* original 7201, guest PC 0x0c0699e0 */
if(!s->budget--) { s->failed_pc=0x0c0699e0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0699e2;
P_0c0699e2: /* original 2422, guest PC 0x0c0699e2 */
if(!s->budget--) { s->failed_pc=0x0c0699e2u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0699e4;
P_0c0699e4: /* original 63f2, guest PC 0x0c0699e4 */
if(!s->budget--) { s->failed_pc=0x0c0699e4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0699e6;
P_0c0699e6: /* original 2338, guest PC 0x0c0699e6 */
if(!s->budget--) { s->failed_pc=0x0c0699e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0699e8;
P_0c0699e8: /* original 890d, guest PC 0x0c0699e8 */
if(!s->budget--) { s->failed_pc=0x0c0699e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069a06; }
goto P_0c0699ea;
P_0c0699ea: /* original 9124, guest PC 0x0c0699ea */
if(!s->budget--) { s->failed_pc=0x0c0699eau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a36u,2);
goto P_0c0699ec;
P_0c0699ec: /* original 53f2, guest PC 0x0c0699ec */
if(!s->budget--) { s->failed_pc=0x0c0699ecu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0699ee;
P_0c0699ee: /* original 31dc, guest PC 0x0c0699ee */
if(!s->budget--) { s->failed_pc=0x0c0699eeu; return 0; }
r[1]+=r[13];
goto P_0c0699f0;
P_0c0699f0: /* original 313c, guest PC 0x0c0699f0 */
if(!s->budget--) { s->failed_pc=0x0c0699f0u; return 0; }
r[1]+=r[3];
goto P_0c0699f2;
P_0c0699f2: /* original 6212, guest PC 0x0c0699f2 */
if(!s->budget--) { s->failed_pc=0x0c0699f2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0699f4;
P_0c0699f4: /* original 7201, guest PC 0x0c0699f4 */
if(!s->budget--) { s->failed_pc=0x0c0699f4u; return 0; }
r[2]+=0x00000001u;
goto P_0c0699f6;
P_0c0699f6: /* original 2122, guest PC 0x0c0699f6 */
if(!s->budget--) { s->failed_pc=0x0c0699f6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0699f8;
P_0c0699f8: /* original 921f, guest PC 0x0c0699f8 */
if(!s->budget--) { s->failed_pc=0x0c0699f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a3au,2);
goto P_0c0699fa;
P_0c0699fa: /* original 901d, guest PC 0x0c0699fa */
if(!s->budget--) { s->failed_pc=0x0c0699fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a38u,2);
goto P_0c0699fc;
P_0c0699fc: /* original 53f2, guest PC 0x0c0699fc */
if(!s->budget--) { s->failed_pc=0x0c0699fcu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0699fe;
P_0c0699fe: /* original 32dc, guest PC 0x0c0699fe */
if(!s->budget--) { s->failed_pc=0x0c0699feu; return 0; }
r[2]+=r[13];
goto P_0c069a00;
P_0c069a00: /* original 04de, guest PC 0x0c069a00 */
if(!s->budget--) { s->failed_pc=0x0c069a00u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c069a02;
P_0c069a02: /* original 323c, guest PC 0x0c069a02 */
if(!s->budget--) { s->failed_pc=0x0c069a02u; return 0; }
r[2]+=r[3];
goto P_0c069a04;
P_0c069a04: /* original 2242, guest PC 0x0c069a04 */
if(!s->budget--) { s->failed_pc=0x0c069a04u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c069a06;
P_0c069a06: /* original 50f5, guest PC 0x0c069a06 */
if(!s->budget--) { s->failed_pc=0x0c069a06u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c069a08;
P_0c069a08: /* original c810, guest PC 0x0c069a08 */
if(!s->budget--) { s->failed_pc=0x0c069a08u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c069a0a;
P_0c069a0a: /* original 8b04, guest PC 0x0c069a0a */
if(!s->budget--) { s->failed_pc=0x0c069a0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069a16; }
goto P_0c069a0c;
P_0c069a0c: /* original 63f2, guest PC 0x0c069a0c */
if(!s->budget--) { s->failed_pc=0x0c069a0cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c069a0e;
P_0c069a0e: /* original 2338, guest PC 0x0c069a0e */
if(!s->budget--) { s->failed_pc=0x0c069a0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c069a10;
P_0c069a10: /* original 8901, guest PC 0x0c069a10 */
if(!s->budget--) { s->failed_pc=0x0c069a10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069a16; }
goto P_0c069a12;
P_0c069a12: /* original a484, guest PC 0x0c069a12 */
if(!s->budget--) { s->failed_pc=0x0c069a12u; return 0; }
goto P_0c06a31e;
P_0c069a14: /* original 0009, guest PC 0x0c069a14 */
if(!s->budget--) { s->failed_pc=0x0c069a14u; return 0; }
goto P_0c069a16;
P_0c069a16: /* original 900f, guest PC 0x0c069a16 */
if(!s->budget--) { s->failed_pc=0x0c069a16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a38u,2);
goto P_0c069a18;
P_0c069a18: /* original 03de, guest PC 0x0c069a18 */
if(!s->budget--) { s->failed_pc=0x0c069a18u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069a1a;
P_0c069a1a: /* original 1f33, guest PC 0x0c069a1a */
if(!s->budget--) { s->failed_pc=0x0c069a1au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c069a1c;
P_0c069a1c: /* original 900e, guest PC 0x0c069a1c */
if(!s->budget--) { s->failed_pc=0x0c069a1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069a3cu,2);
goto P_0c069a1e;
P_0c069a1e: /* original 02de, guest PC 0x0c069a1e */
if(!s->budget--) { s->failed_pc=0x0c069a1eu; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c069a20;
P_0c069a20: /* original 6323, guest PC 0x0c069a20 */
if(!s->budget--) { s->failed_pc=0x0c069a20u; return 0; }
r[3]=r[2];
goto P_0c069a22;
P_0c069a22: /* original 1f22, guest PC 0x0c069a22 */
if(!s->budget--) { s->failed_pc=0x0c069a22u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c069a24;
P_0c069a24: /* original a01c, guest PC 0x0c069a24 */
if(!s->budget--) { s->failed_pc=0x0c069a24u; return 0; }
goto P_0c069a60;
P_0c069a26: /* original 0009, guest PC 0x0c069a26 */
if(!s->budget--) { s->failed_pc=0x0c069a26u; return 0; }
if(!vf3_matrix_family(0x0c069a28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069a28u; return 0; } return 1;
P_0c069a60: /* original 55f3, guest PC 0x0c069a60 */
if(!s->budget--) { s->failed_pc=0x0c069a60u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c069a62;
P_0c069a62: /* original 64e3, guest PC 0x0c069a62 */
if(!s->budget--) { s->failed_pc=0x0c069a62u; return 0; }
r[4]=r[14];
goto P_0c069a64;
P_0c069a64: /* original 353c, guest PC 0x0c069a64 */
if(!s->budget--) { s->failed_pc=0x0c069a64u; return 0; }
r[5]+=r[3];
goto P_0c069a66;
P_0c069a66: /* original be2e, guest PC 0x0c069a66 */
if(!s->budget--) { s->failed_pc=0x0c069a66u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069a6au;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069a6au) { target=s->pc; goto dispatch; }
goto P_0c069a6a;
P_0c069a68: /* original 7424, guest PC 0x0c069a68 */
if(!s->budget--) { s->failed_pc=0x0c069a68u; return 0; }
r[4]+=0x00000024u;
goto P_0c069a6a;
P_0c069a6a: /* original 55f3, guest PC 0x0c069a6a */
if(!s->budget--) { s->failed_pc=0x0c069a6au; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c069a6c;
P_0c069a6c: /* original 64e3, guest PC 0x0c069a6c */
if(!s->budget--) { s->failed_pc=0x0c069a6cu; return 0; }
r[4]=r[14];
goto P_0c069a6e;
P_0c069a6e: /* original be2a, guest PC 0x0c069a6e */
if(!s->budget--) { s->failed_pc=0x0c069a6eu; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069a72u;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069a72u) { target=s->pc; goto dispatch; }
goto P_0c069a72;
P_0c069a70: /* original 7428, guest PC 0x0c069a70 */
if(!s->budget--) { s->failed_pc=0x0c069a70u; return 0; }
r[4]+=0x00000028u;
goto P_0c069a72;
P_0c069a72: /* original 55f2, guest PC 0x0c069a72 */
if(!s->budget--) { s->failed_pc=0x0c069a72u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c069a74;
P_0c069a74: /* original 64e3, guest PC 0x0c069a74 */
if(!s->budget--) { s->failed_pc=0x0c069a74u; return 0; }
r[4]=r[14];
goto P_0c069a76;
P_0c069a76: /* original be26, guest PC 0x0c069a76 */
if(!s->budget--) { s->failed_pc=0x0c069a76u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069a7au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069a7au) { target=s->pc; goto dispatch; }
goto P_0c069a7a;
P_0c069a78: /* original 7430, guest PC 0x0c069a78 */
if(!s->budget--) { s->failed_pc=0x0c069a78u; return 0; }
r[4]+=0x00000030u;
goto P_0c069a7a;
P_0c069a7a: /* original 64e3, guest PC 0x0c069a7a */
if(!s->budget--) { s->failed_pc=0x0c069a7au; return 0; }
r[4]=r[14];
goto P_0c069a7c;
P_0c069a7c: /* original 4b0b, guest PC 0x0c069a7c */
if(!s->budget--) { s->failed_pc=0x0c069a7cu; return 0; }
target=r[11];
r[16]=code_base|0x0c069a80u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069a80u) { target=s->pc; goto dispatch; }
goto P_0c069a80;
P_0c069a7e: /* original 741c, guest PC 0x0c069a7e */
if(!s->budget--) { s->failed_pc=0x0c069a7eu; return 0; }
r[4]+=0x0000001cu;
goto P_0c069a80;
P_0c069a80: /* original 64e3, guest PC 0x0c069a80 */
if(!s->budget--) { s->failed_pc=0x0c069a80u; return 0; }
r[4]=r[14];
goto P_0c069a82;
P_0c069a82: /* original 1f02, guest PC 0x0c069a82 */
if(!s->budget--) { s->failed_pc=0x0c069a82u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c069a84;
P_0c069a84: /* original 4b0b, guest PC 0x0c069a84 */
if(!s->budget--) { s->failed_pc=0x0c069a84u; return 0; }
target=r[11];
r[16]=code_base|0x0c069a88u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069a88u) { target=s->pc; goto dispatch; }
goto P_0c069a88;
P_0c069a86: /* original 7434, guest PC 0x0c069a86 */
if(!s->budget--) { s->failed_pc=0x0c069a86u; return 0; }
r[4]+=0x00000034u;
goto P_0c069a88;
P_0c069a88: /* original 53f2, guest PC 0x0c069a88 */
if(!s->budget--) { s->failed_pc=0x0c069a88u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c069a8a;
P_0c069a8a: /* original 6403, guest PC 0x0c069a8a */
if(!s->budget--) { s->failed_pc=0x0c069a8au; return 0; }
r[4]=r[0];
goto P_0c069a8c;
P_0c069a8c: /* original 3348, guest PC 0x0c069a8c */
if(!s->budget--) { s->failed_pc=0x0c069a8cu; return 0; }
r[3]-=r[4];
goto P_0c069a8e;
P_0c069a8e: /* original 64e3, guest PC 0x0c069a8e */
if(!s->budget--) { s->failed_pc=0x0c069a8eu; return 0; }
r[4]=r[14];
goto P_0c069a90;
P_0c069a90: /* original 1f32, guest PC 0x0c069a90 */
if(!s->budget--) { s->failed_pc=0x0c069a90u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c069a92;
P_0c069a92: /* original 4b0b, guest PC 0x0c069a92 */
if(!s->budget--) { s->failed_pc=0x0c069a92u; return 0; }
target=r[11];
r[16]=code_base|0x0c069a96u;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069a96u) { target=s->pc; goto dispatch; }
goto P_0c069a96;
P_0c069a94: /* original 7424, guest PC 0x0c069a94 */
if(!s->budget--) { s->failed_pc=0x0c069a94u; return 0; }
r[4]+=0x00000024u;
goto P_0c069a96;
P_0c069a96: /* original 53f2, guest PC 0x0c069a96 */
if(!s->budget--) { s->failed_pc=0x0c069a96u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c069a98;
P_0c069a98: /* original 6403, guest PC 0x0c069a98 */
if(!s->budget--) { s->failed_pc=0x0c069a98u; return 0; }
r[4]=r[0];
goto P_0c069a9a;
P_0c069a9a: /* original f28d, guest PC 0x0c069a9a */
if(!s->budget--) { s->failed_pc=0x0c069a9au; return 0; }
fr[2]=0;
goto P_0c069a9c;
P_0c069a9c: /* original c744, guest PC 0x0c069a9c */
if(!s->budget--) { s->failed_pc=0x0c069a9cu; return 0; }
r[0]=code_base|0x00069bb0u;
goto P_0c069a9e;
P_0c069a9e: /* original 435a, guest PC 0x0c069a9e */
if(!s->budget--) { s->failed_pc=0x0c069a9eu; return 0; }
r[53]=r[3];
goto P_0c069aa0;
P_0c069aa0: /* original f608, guest PC 0x0c069aa0 */
if(!s->budget--) { s->failed_pc=0x0c069aa0u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c069aa2;
P_0c069aa2: /* original f32d, guest PC 0x0c069aa2 */
if(!s->budget--) { s->failed_pc=0x0c069aa2u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c069aa4;
P_0c069aa4: /* original f235, guest PC 0x0c069aa4 */
if(!s->budget--) { s->failed_pc=0x0c069aa4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c069aa6;
P_0c069aa6: /* original 8f05, guest PC 0x0c069aa6 */
if(!s->budget--) { s->failed_pc=0x0c069aa6u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c069ab4; }
goto P_0c069aaa;
P_0c069aa8: /* original f43c, guest PC 0x0c069aa8 */
if(!s->budget--) { s->failed_pc=0x0c069aa8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c069aaa;
P_0c069aaa: /* original c742, guest PC 0x0c069aaa */
if(!s->budget--) { s->failed_pc=0x0c069aaau; return 0; }
r[0]=code_base|0x00069bb4u;
goto P_0c069aac;
P_0c069aac: /* original f54c, guest PC 0x0c069aac */
if(!s->budget--) { s->failed_pc=0x0c069aacu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c069aae;
P_0c069aae: /* original f308, guest PC 0x0c069aae */
if(!s->budget--) { s->failed_pc=0x0c069aaeu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069ab0;
P_0c069ab0: /* original a001, guest PC 0x0c069ab0 */
if(!s->budget--) { s->failed_pc=0x0c069ab0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c069ab6;
P_0c069ab2: /* original f530, guest PC 0x0c069ab2 */
if(!s->budget--) { s->failed_pc=0x0c069ab2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c069ab4;
P_0c069ab4: /* original f54c, guest PC 0x0c069ab4 */
if(!s->budget--) { s->failed_pc=0x0c069ab4u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c069ab6;
P_0c069ab6: /* original 445a, guest PC 0x0c069ab6 */
if(!s->budget--) { s->failed_pc=0x0c069ab6u; return 0; }
r[53]=r[4];
goto P_0c069ab8;
P_0c069ab8: /* original f28d, guest PC 0x0c069ab8 */
if(!s->budget--) { s->failed_pc=0x0c069ab8u; return 0; }
fr[2]=0;
goto P_0c069aba;
P_0c069aba: /* original f32d, guest PC 0x0c069aba */
if(!s->budget--) { s->failed_pc=0x0c069abau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c069abc;
P_0c069abc: /* original f235, guest PC 0x0c069abc */
if(!s->budget--) { s->failed_pc=0x0c069abcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c069abe;
P_0c069abe: /* original 8f03, guest PC 0x0c069abe */
if(!s->budget--) { s->failed_pc=0x0c069abeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c069ac8; }
goto P_0c069ac2;
P_0c069ac0: /* original f43c, guest PC 0x0c069ac0 */
if(!s->budget--) { s->failed_pc=0x0c069ac0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c069ac2;
P_0c069ac2: /* original c73c, guest PC 0x0c069ac2 */
if(!s->budget--) { s->failed_pc=0x0c069ac2u; return 0; }
r[0]=code_base|0x00069bb4u;
goto P_0c069ac4;
P_0c069ac4: /* original f308, guest PC 0x0c069ac4 */
if(!s->budget--) { s->failed_pc=0x0c069ac4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069ac6;
P_0c069ac6: /* original f430, guest PC 0x0c069ac6 */
if(!s->budget--) { s->failed_pc=0x0c069ac6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c069ac8;
P_0c069ac8: /* original f462, guest PC 0x0c069ac8 */
if(!s->budget--) { s->failed_pc=0x0c069ac8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c069aca;
P_0c069aca: /* original c73b, guest PC 0x0c069aca */
if(!s->budget--) { s->failed_pc=0x0c069acau; return 0; }
r[0]=code_base|0x00069bb8u;
goto P_0c069acc;
P_0c069acc: /* original f208, guest PC 0x0c069acc */
if(!s->budget--) { s->failed_pc=0x0c069accu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c069ace;
P_0c069ace: /* original f453, guest PC 0x0c069ace */
if(!s->budget--) { s->failed_pc=0x0c069aceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c069ad0;
P_0c069ad0: /* original f425, guest PC 0x0c069ad0 */
if(!s->budget--) { s->failed_pc=0x0c069ad0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c069ad2;
P_0c069ad2: /* original 8f05, guest PC 0x0c069ad2 */
if(!s->budget--) { s->failed_pc=0x0c069ad2u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,4);
if(!cond) { goto P_0c069ae0; }
goto P_0c069ad6;
P_0c069ad4: /* original f54c, guest PC 0x0c069ad4 */
if(!s->budget--) { s->failed_pc=0x0c069ad4u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c069ad6;
P_0c069ad6: /* original c739, guest PC 0x0c069ad6 */
if(!s->budget--) { s->failed_pc=0x0c069ad6u; return 0; }
r[0]=code_base|0x00069bbcu;
goto P_0c069ad8;
P_0c069ad8: /* original f35c, guest PC 0x0c069ad8 */
if(!s->budget--) { s->failed_pc=0x0c069ad8u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c069ada;
P_0c069ada: /* original f208, guest PC 0x0c069ada */
if(!s->budget--) { s->failed_pc=0x0c069adau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c069adc;
P_0c069adc: /* original a001, guest PC 0x0c069adc */
if(!s->budget--) { s->failed_pc=0x0c069adcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c069ae2;
P_0c069ade: /* original f320, guest PC 0x0c069ade */
if(!s->budget--) { s->failed_pc=0x0c069adeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c069ae0;
P_0c069ae0: /* original f35c, guest PC 0x0c069ae0 */
if(!s->budget--) { s->failed_pc=0x0c069ae0u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c069ae2;
P_0c069ae2: /* original f33d, guest PC 0x0c069ae2 */
if(!s->budget--) { s->failed_pc=0x0c069ae2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c069ae4;
P_0c069ae4: /* original 64e3, guest PC 0x0c069ae4 */
if(!s->budget--) { s->failed_pc=0x0c069ae4u; return 0; }
r[4]=r[14];
goto P_0c069ae6;
P_0c069ae6: /* original 025a, guest PC 0x0c069ae6 */
if(!s->budget--) { s->failed_pc=0x0c069ae6u; return 0; }
r[2]=r[53];
goto P_0c069ae8;
P_0c069ae8: /* original 6523, guest PC 0x0c069ae8 */
if(!s->budget--) { s->failed_pc=0x0c069ae8u; return 0; }
r[5]=r[2];
goto P_0c069aea;
P_0c069aea: /* original 1f24, guest PC 0x0c069aea */
if(!s->budget--) { s->failed_pc=0x0c069aeau; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c069aec;
P_0c069aec: /* original 4c0b, guest PC 0x0c069aec */
if(!s->budget--) { s->failed_pc=0x0c069aecu; return 0; }
target=r[12];
r[16]=code_base|0x0c069af0u;
r[4]+=0x0000003cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069af0u) { target=s->pc; goto dispatch; }
goto P_0c069af0;
P_0c069aee: /* original 743c, guest PC 0x0c069aee */
if(!s->budget--) { s->failed_pc=0x0c069aeeu; return 0; }
r[4]+=0x0000003cu;
goto P_0c069af0;
P_0c069af0: /* original 945a, guest PC 0x0c069af0 */
if(!s->budget--) { s->failed_pc=0x0c069af0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069ba8u,2);
goto P_0c069af2;
P_0c069af2: /* original e500, guest PC 0x0c069af2 */
if(!s->budget--) { s->failed_pc=0x0c069af2u; return 0; }
r[5]=0x00000000u;
goto P_0c069af4;
P_0c069af4: /* original 4c0b, guest PC 0x0c069af4 */
if(!s->budget--) { s->failed_pc=0x0c069af4u; return 0; }
target=r[12];
r[16]=code_base|0x0c069af8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069af8u) { target=s->pc; goto dispatch; }
goto P_0c069af8;
P_0c069af6: /* original 34ec, guest PC 0x0c069af6 */
if(!s->budget--) { s->failed_pc=0x0c069af6u; return 0; }
r[4]+=r[14];
goto P_0c069af8;
P_0c069af8: /* original 64e3, guest PC 0x0c069af8 */
if(!s->budget--) { s->failed_pc=0x0c069af8u; return 0; }
r[4]=r[14];
goto P_0c069afa;
P_0c069afa: /* original e501, guest PC 0x0c069afa */
if(!s->budget--) { s->failed_pc=0x0c069afau; return 0; }
r[5]=0x00000001u;
goto P_0c069afc;
P_0c069afc: /* original bde3, guest PC 0x0c069afc */
if(!s->budget--) { s->failed_pc=0x0c069afcu; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069b00u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b00u) { target=s->pc; goto dispatch; }
goto P_0c069b00;
P_0c069afe: /* original 7440, guest PC 0x0c069afe */
if(!s->budget--) { s->failed_pc=0x0c069afeu; return 0; }
r[4]+=0x00000040u;
goto P_0c069b00;
P_0c069b00: /* original 64e3, guest PC 0x0c069b00 */
if(!s->budget--) { s->failed_pc=0x0c069b00u; return 0; }
r[4]=r[14];
goto P_0c069b02;
P_0c069b02: /* original e501, guest PC 0x0c069b02 */
if(!s->budget--) { s->failed_pc=0x0c069b02u; return 0; }
r[5]=0x00000001u;
goto P_0c069b04;
P_0c069b04: /* original bddf, guest PC 0x0c069b04 */
if(!s->budget--) { s->failed_pc=0x0c069b04u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069b08u;
r[4]+=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b08u) { target=s->pc; goto dispatch; }
goto P_0c069b08;
P_0c069b06: /* original 7444, guest PC 0x0c069b06 */
if(!s->budget--) { s->failed_pc=0x0c069b06u; return 0; }
r[4]+=0x00000044u;
goto P_0c069b08;
P_0c069b08: /* original 64e3, guest PC 0x0c069b08 */
if(!s->budget--) { s->failed_pc=0x0c069b08u; return 0; }
r[4]=r[14];
goto P_0c069b0a;
P_0c069b0a: /* original 4b0b, guest PC 0x0c069b0a */
if(!s->budget--) { s->failed_pc=0x0c069b0au; return 0; }
target=r[11];
r[16]=code_base|0x0c069b0eu;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b0eu) { target=s->pc; goto dispatch; }
goto P_0c069b0e;
P_0c069b0c: /* original 7428, guest PC 0x0c069b0c */
if(!s->budget--) { s->failed_pc=0x0c069b0cu; return 0; }
r[4]+=0x00000028u;
goto P_0c069b0e;
P_0c069b0e: /* original 64e3, guest PC 0x0c069b0e */
if(!s->budget--) { s->failed_pc=0x0c069b0eu; return 0; }
r[4]=r[14];
goto P_0c069b10;
P_0c069b10: /* original 1f04, guest PC 0x0c069b10 */
if(!s->budget--) { s->failed_pc=0x0c069b10u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c069b12;
P_0c069b12: /* original 4b0b, guest PC 0x0c069b12 */
if(!s->budget--) { s->failed_pc=0x0c069b12u; return 0; }
target=r[11];
r[16]=code_base|0x0c069b16u;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b16u) { target=s->pc; goto dispatch; }
goto P_0c069b16;
P_0c069b14: /* original 742c, guest PC 0x0c069b14 */
if(!s->budget--) { s->failed_pc=0x0c069b14u; return 0; }
r[4]+=0x0000002cu;
goto P_0c069b16;
P_0c069b16: /* original 53f4, guest PC 0x0c069b16 */
if(!s->budget--) { s->failed_pc=0x0c069b16u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c069b18;
P_0c069b18: /* original 6403, guest PC 0x0c069b18 */
if(!s->budget--) { s->failed_pc=0x0c069b18u; return 0; }
r[4]=r[0];
goto P_0c069b1a;
P_0c069b1a: /* original d229, guest PC 0x0c069b1a */
if(!s->budget--) { s->failed_pc=0x0c069b1au; return 0; }
r[2]=read(ram,0x0c069bc0u,4);
goto P_0c069b1c;
P_0c069b1c: /* original 343c, guest PC 0x0c069b1c */
if(!s->budget--) { s->failed_pc=0x0c069b1cu; return 0; }
r[4]+=r[3];
goto P_0c069b1e;
P_0c069b1e: /* original 6143, guest PC 0x0c069b1e */
if(!s->budget--) { s->failed_pc=0x0c069b1eu; return 0; }
r[1]=r[4];
goto P_0c069b20;
P_0c069b20: /* original 420b, guest PC 0x0c069b20 */
if(!s->budget--) { s->failed_pc=0x0c069b20u; return 0; }
target=r[2];
r[16]=code_base|0x0c069b24u;
r[0]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b24u) { target=s->pc; goto dispatch; }
goto P_0c069b24;
P_0c069b22: /* original 50f2, guest PC 0x0c069b22 */
if(!s->budget--) { s->failed_pc=0x0c069b22u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c069b24;
P_0c069b24: /* original 64e3, guest PC 0x0c069b24 */
if(!s->budget--) { s->failed_pc=0x0c069b24u; return 0; }
r[4]=r[14];
goto P_0c069b26;
P_0c069b26: /* original 6503, guest PC 0x0c069b26 */
if(!s->budget--) { s->failed_pc=0x0c069b26u; return 0; }
r[5]=r[0];
goto P_0c069b28;
P_0c069b28: /* original 1f02, guest PC 0x0c069b28 */
if(!s->budget--) { s->failed_pc=0x0c069b28u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c069b2a;
P_0c069b2a: /* original 4c0b, guest PC 0x0c069b2a */
if(!s->budget--) { s->failed_pc=0x0c069b2au; return 0; }
target=r[12];
r[16]=code_base|0x0c069b2eu;
r[4]+=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b2eu) { target=s->pc; goto dispatch; }
goto P_0c069b2e;
P_0c069b2c: /* original 744c, guest PC 0x0c069b2c */
if(!s->budget--) { s->failed_pc=0x0c069b2cu; return 0; }
r[4]+=0x0000004cu;
goto P_0c069b2e;
P_0c069b2e: /* original d324, guest PC 0x0c069b2e */
if(!s->budget--) { s->failed_pc=0x0c069b2eu; return 0; }
r[3]=read(ram,0x0c069bc0u,4);
goto P_0c069b30;
P_0c069b30: /* original 51f4, guest PC 0x0c069b30 */
if(!s->budget--) { s->failed_pc=0x0c069b30u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c069b32;
P_0c069b32: /* original 430b, guest PC 0x0c069b32 */
if(!s->budget--) { s->failed_pc=0x0c069b32u; return 0; }
target=r[3];
r[16]=code_base|0x0c069b36u;
r[0]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b36u) { target=s->pc; goto dispatch; }
goto P_0c069b36;
P_0c069b34: /* original 50f3, guest PC 0x0c069b34 */
if(!s->budget--) { s->failed_pc=0x0c069b34u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c069b36;
P_0c069b36: /* original 64e3, guest PC 0x0c069b36 */
if(!s->budget--) { s->failed_pc=0x0c069b36u; return 0; }
r[4]=r[14];
goto P_0c069b38;
P_0c069b38: /* original 6503, guest PC 0x0c069b38 */
if(!s->budget--) { s->failed_pc=0x0c069b38u; return 0; }
r[5]=r[0];
goto P_0c069b3a;
P_0c069b3a: /* original 1f02, guest PC 0x0c069b3a */
if(!s->budget--) { s->failed_pc=0x0c069b3au; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c069b3c;
P_0c069b3c: /* original 4c0b, guest PC 0x0c069b3c */
if(!s->budget--) { s->failed_pc=0x0c069b3cu; return 0; }
target=r[12];
r[16]=code_base|0x0c069b40u;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b40u) { target=s->pc; goto dispatch; }
goto P_0c069b40;
P_0c069b3e: /* original 7450, guest PC 0x0c069b3e */
if(!s->budget--) { s->failed_pc=0x0c069b3eu; return 0; }
r[4]+=0x00000050u;
goto P_0c069b40;
P_0c069b40: /* original 53f1, guest PC 0x0c069b40 */
if(!s->budget--) { s->failed_pc=0x0c069b40u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c069b42;
P_0c069b42: /* original 2338, guest PC 0x0c069b42 */
if(!s->budget--) { s->failed_pc=0x0c069b42u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c069b44;
P_0c069b44: /* original 8b3e, guest PC 0x0c069b44 */
if(!s->budget--) { s->failed_pc=0x0c069b44u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069bc4; }
goto P_0c069b46;
P_0c069b46: /* original 64e3, guest PC 0x0c069b46 */
if(!s->budget--) { s->failed_pc=0x0c069b46u; return 0; }
r[4]=r[14];
goto P_0c069b48;
P_0c069b48: /* original 4b0b, guest PC 0x0c069b48 */
if(!s->budget--) { s->failed_pc=0x0c069b48u; return 0; }
target=r[11];
r[16]=code_base|0x0c069b4cu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b4cu) { target=s->pc; goto dispatch; }
goto P_0c069b4c;
P_0c069b4a: /* original 7458, guest PC 0x0c069b4a */
if(!s->budget--) { s->failed_pc=0x0c069b4au; return 0; }
r[4]+=0x00000058u;
goto P_0c069b4c;
P_0c069b4c: /* original 6403, guest PC 0x0c069b4c */
if(!s->budget--) { s->failed_pc=0x0c069b4cu; return 0; }
r[4]=r[0];
goto P_0c069b4e;
P_0c069b4e: /* original 7401, guest PC 0x0c069b4e */
if(!s->budget--) { s->failed_pc=0x0c069b4eu; return 0; }
r[4]+=0x00000001u;
goto P_0c069b50;
P_0c069b50: /* original 6543, guest PC 0x0c069b50 */
if(!s->budget--) { s->failed_pc=0x0c069b50u; return 0; }
r[5]=r[4];
goto P_0c069b52;
P_0c069b52: /* original 1f43, guest PC 0x0c069b52 */
if(!s->budget--) { s->failed_pc=0x0c069b52u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c069b54;
P_0c069b54: /* original 64e3, guest PC 0x0c069b54 */
if(!s->budget--) { s->failed_pc=0x0c069b54u; return 0; }
r[4]=r[14];
goto P_0c069b56;
P_0c069b56: /* original 4c0b, guest PC 0x0c069b56 */
if(!s->budget--) { s->failed_pc=0x0c069b56u; return 0; }
target=r[12];
r[16]=code_base|0x0c069b5au;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b5au) { target=s->pc; goto dispatch; }
goto P_0c069b5a;
P_0c069b58: /* original 7458, guest PC 0x0c069b58 */
if(!s->budget--) { s->failed_pc=0x0c069b58u; return 0; }
r[4]+=0x00000058u;
goto P_0c069b5a;
P_0c069b5a: /* original 64e3, guest PC 0x0c069b5a */
if(!s->budget--) { s->failed_pc=0x0c069b5au; return 0; }
r[4]=r[14];
goto P_0c069b5c;
P_0c069b5c: /* original 4b0b, guest PC 0x0c069b5c */
if(!s->budget--) { s->failed_pc=0x0c069b5cu; return 0; }
target=r[11];
r[16]=code_base|0x0c069b60u;
r[4]+=0x00000078u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b60u) { target=s->pc; goto dispatch; }
goto P_0c069b60;
P_0c069b5e: /* original 7478, guest PC 0x0c069b5e */
if(!s->budget--) { s->failed_pc=0x0c069b5eu; return 0; }
r[4]+=0x00000078u;
goto P_0c069b60;
P_0c069b60: /* original 6403, guest PC 0x0c069b60 */
if(!s->budget--) { s->failed_pc=0x0c069b60u; return 0; }
r[4]=r[0];
goto P_0c069b62;
P_0c069b62: /* original 9022, guest PC 0x0c069b62 */
if(!s->budget--) { s->failed_pc=0x0c069b62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069baau,2);
goto P_0c069b64;
P_0c069b64: /* original 03de, guest PC 0x0c069b64 */
if(!s->budget--) { s->failed_pc=0x0c069b64u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069b66;
P_0c069b66: /* original 6233, guest PC 0x0c069b66 */
if(!s->budget--) { s->failed_pc=0x0c069b66u; return 0; }
r[2]=r[3];
goto P_0c069b68;
P_0c069b68: /* original 342c, guest PC 0x0c069b68 */
if(!s->budget--) { s->failed_pc=0x0c069b68u; return 0; }
r[4]+=r[2];
goto P_0c069b6a;
P_0c069b6a: /* original 6543, guest PC 0x0c069b6a */
if(!s->budget--) { s->failed_pc=0x0c069b6au; return 0; }
r[5]=r[4];
goto P_0c069b6c;
P_0c069b6c: /* original 1f32, guest PC 0x0c069b6c */
if(!s->budget--) { s->failed_pc=0x0c069b6cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c069b6e;
P_0c069b6e: /* original 1f44, guest PC 0x0c069b6e */
if(!s->budget--) { s->failed_pc=0x0c069b6eu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c069b70;
P_0c069b70: /* original 64e3, guest PC 0x0c069b70 */
if(!s->budget--) { s->failed_pc=0x0c069b70u; return 0; }
r[4]=r[14];
goto P_0c069b72;
P_0c069b72: /* original 4c0b, guest PC 0x0c069b72 */
if(!s->budget--) { s->failed_pc=0x0c069b72u; return 0; }
target=r[12];
r[16]=code_base|0x0c069b76u;
r[4]+=0x00000078u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b76u) { target=s->pc; goto dispatch; }
goto P_0c069b76;
P_0c069b74: /* original 7478, guest PC 0x0c069b74 */
if(!s->budget--) { s->failed_pc=0x0c069b74u; return 0; }
r[4]+=0x00000078u;
goto P_0c069b76;
P_0c069b76: /* original d312, guest PC 0x0c069b76 */
if(!s->budget--) { s->failed_pc=0x0c069b76u; return 0; }
r[3]=read(ram,0x0c069bc0u,4);
goto P_0c069b78;
P_0c069b78: /* original 51f4, guest PC 0x0c069b78 */
if(!s->budget--) { s->failed_pc=0x0c069b78u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c069b7a;
P_0c069b7a: /* original 430b, guest PC 0x0c069b7a */
if(!s->budget--) { s->failed_pc=0x0c069b7au; return 0; }
target=r[3];
r[16]=code_base|0x0c069b7eu;
r[0]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b7eu) { target=s->pc; goto dispatch; }
goto P_0c069b7e;
P_0c069b7c: /* original 50f3, guest PC 0x0c069b7c */
if(!s->budget--) { s->failed_pc=0x0c069b7cu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c069b7e;
P_0c069b7e: /* original 64e3, guest PC 0x0c069b7e */
if(!s->budget--) { s->failed_pc=0x0c069b7eu; return 0; }
r[4]=r[14];
goto P_0c069b80;
P_0c069b80: /* original 6503, guest PC 0x0c069b80 */
if(!s->budget--) { s->failed_pc=0x0c069b80u; return 0; }
r[5]=r[0];
goto P_0c069b82;
P_0c069b82: /* original 1f03, guest PC 0x0c069b82 */
if(!s->budget--) { s->failed_pc=0x0c069b82u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c069b84;
P_0c069b84: /* original 4c0b, guest PC 0x0c069b84 */
if(!s->budget--) { s->failed_pc=0x0c069b84u; return 0; }
target=r[12];
r[16]=code_base|0x0c069b88u;
r[4]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b88u) { target=s->pc; goto dispatch; }
goto P_0c069b88;
P_0c069b86: /* original 7468, guest PC 0x0c069b86 */
if(!s->budget--) { s->failed_pc=0x0c069b86u; return 0; }
r[4]+=0x00000068u;
goto P_0c069b88;
P_0c069b88: /* original d30d, guest PC 0x0c069b88 */
if(!s->budget--) { s->failed_pc=0x0c069b88u; return 0; }
r[3]=read(ram,0x0c069bc0u,4);
goto P_0c069b8a;
P_0c069b8a: /* original 51f2, guest PC 0x0c069b8a */
if(!s->budget--) { s->failed_pc=0x0c069b8au; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c069b8c;
P_0c069b8c: /* original 940e, guest PC 0x0c069b8c */
if(!s->budget--) { s->failed_pc=0x0c069b8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069bacu,2);
goto P_0c069b8e;
P_0c069b8e: /* original 430b, guest PC 0x0c069b8e */
if(!s->budget--) { s->failed_pc=0x0c069b8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c069b92u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069b92u) { target=s->pc; goto dispatch; }
goto P_0c069b92;
P_0c069b90: /* original 6043, guest PC 0x0c069b90 */
if(!s->budget--) { s->failed_pc=0x0c069b90u; return 0; }
r[0]=r[4];
goto P_0c069b92;
P_0c069b92: /* original 3096, guest PC 0x0c069b92 */
if(!s->budget--) { s->failed_pc=0x0c069b92u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[9])!=0);
goto P_0c069b94;
P_0c069b94: /* original 8f01, guest PC 0x0c069b94 */
if(!s->budget--) { s->failed_pc=0x0c069b94u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[0],4);
if(!cond) { goto P_0c069b9a; }
goto P_0c069b98;
P_0c069b96: /* original 1f02, guest PC 0x0c069b96 */
if(!s->budget--) { s->failed_pc=0x0c069b96u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c069b98;
P_0c069b98: /* original 1f92, guest PC 0x0c069b98 */
if(!s->budget--) { s->failed_pc=0x0c069b98u; return 0; }
write(ram,r[15]+8,r[9],4);
goto P_0c069b9a;
P_0c069b9a: /* original 9308, guest PC 0x0c069b9a */
if(!s->budget--) { s->failed_pc=0x0c069b9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069baeu,2);
goto P_0c069b9c;
P_0c069b9c: /* original 54f2, guest PC 0x0c069b9c */
if(!s->budget--) { s->failed_pc=0x0c069b9cu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c069b9e;
P_0c069b9e: /* original 33ec, guest PC 0x0c069b9e */
if(!s->budget--) { s->failed_pc=0x0c069b9eu; return 0; }
r[3]+=r[14];
goto P_0c069ba0;
P_0c069ba0: /* original 4408, guest PC 0x0c069ba0 */
if(!s->budget--) { s->failed_pc=0x0c069ba0u; return 0; }
r[4]<<=2;
goto P_0c069ba2;
P_0c069ba2: /* original 343c, guest PC 0x0c069ba2 */
if(!s->budget--) { s->failed_pc=0x0c069ba2u; return 0; }
r[4]+=r[3];
goto P_0c069ba4;
P_0c069ba4: /* original a03e, guest PC 0x0c069ba4 */
if(!s->budget--) { s->failed_pc=0x0c069ba4u; return 0; }
r[5]=0x00000001u;
goto P_0c069c24;
P_0c069ba6: /* original e501, guest PC 0x0c069ba6 */
if(!s->budget--) { s->failed_pc=0x0c069ba6u; return 0; }
r[5]=0x00000001u;
if(!vf3_matrix_family(0x0c069ba8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069ba8u; return 0; } return 1;
P_0c069bc4: /* original 64e3, guest PC 0x0c069bc4 */
if(!s->budget--) { s->failed_pc=0x0c069bc4u; return 0; }
r[4]=r[14];
goto P_0c069bc6;
P_0c069bc6: /* original 4b0b, guest PC 0x0c069bc6 */
if(!s->budget--) { s->failed_pc=0x0c069bc6u; return 0; }
target=r[11];
r[16]=code_base|0x0c069bcau;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069bcau) { target=s->pc; goto dispatch; }
goto P_0c069bca;
P_0c069bc8: /* original 745c, guest PC 0x0c069bc8 */
if(!s->budget--) { s->failed_pc=0x0c069bc8u; return 0; }
r[4]+=0x0000005cu;
goto P_0c069bca;
P_0c069bca: /* original 6403, guest PC 0x0c069bca */
if(!s->budget--) { s->failed_pc=0x0c069bcau; return 0; }
r[4]=r[0];
goto P_0c069bcc;
P_0c069bcc: /* original 7401, guest PC 0x0c069bcc */
if(!s->budget--) { s->failed_pc=0x0c069bccu; return 0; }
r[4]+=0x00000001u;
goto P_0c069bce;
P_0c069bce: /* original 6543, guest PC 0x0c069bce */
if(!s->budget--) { s->failed_pc=0x0c069bceu; return 0; }
r[5]=r[4];
goto P_0c069bd0;
P_0c069bd0: /* original 1f43, guest PC 0x0c069bd0 */
if(!s->budget--) { s->failed_pc=0x0c069bd0u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c069bd2;
P_0c069bd2: /* original 64e3, guest PC 0x0c069bd2 */
if(!s->budget--) { s->failed_pc=0x0c069bd2u; return 0; }
r[4]=r[14];
goto P_0c069bd4;
P_0c069bd4: /* original 4c0b, guest PC 0x0c069bd4 */
if(!s->budget--) { s->failed_pc=0x0c069bd4u; return 0; }
target=r[12];
r[16]=code_base|0x0c069bd8u;
r[4]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069bd8u) { target=s->pc; goto dispatch; }
goto P_0c069bd8;
P_0c069bd6: /* original 745c, guest PC 0x0c069bd6 */
if(!s->budget--) { s->failed_pc=0x0c069bd6u; return 0; }
r[4]+=0x0000005cu;
goto P_0c069bd8;
P_0c069bd8: /* original 64e3, guest PC 0x0c069bd8 */
if(!s->budget--) { s->failed_pc=0x0c069bd8u; return 0; }
r[4]=r[14];
goto P_0c069bda;
P_0c069bda: /* original 4b0b, guest PC 0x0c069bda */
if(!s->budget--) { s->failed_pc=0x0c069bdau; return 0; }
target=r[11];
r[16]=code_base|0x0c069bdeu;
r[4]+=0x0000007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069bdeu) { target=s->pc; goto dispatch; }
goto P_0c069bde;
P_0c069bdc: /* original 747c, guest PC 0x0c069bdc */
if(!s->budget--) { s->failed_pc=0x0c069bdcu; return 0; }
r[4]+=0x0000007cu;
goto P_0c069bde;
P_0c069bde: /* original 6403, guest PC 0x0c069bde */
if(!s->budget--) { s->failed_pc=0x0c069bdeu; return 0; }
r[4]=r[0];
goto P_0c069be0;
P_0c069be0: /* original 9093, guest PC 0x0c069be0 */
if(!s->budget--) { s->failed_pc=0x0c069be0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d0au,2);
goto P_0c069be2;
P_0c069be2: /* original 03de, guest PC 0x0c069be2 */
if(!s->budget--) { s->failed_pc=0x0c069be2u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069be4;
P_0c069be4: /* original 6233, guest PC 0x0c069be4 */
if(!s->budget--) { s->failed_pc=0x0c069be4u; return 0; }
r[2]=r[3];
goto P_0c069be6;
P_0c069be6: /* original 342c, guest PC 0x0c069be6 */
if(!s->budget--) { s->failed_pc=0x0c069be6u; return 0; }
r[4]+=r[2];
goto P_0c069be8;
P_0c069be8: /* original 6543, guest PC 0x0c069be8 */
if(!s->budget--) { s->failed_pc=0x0c069be8u; return 0; }
r[5]=r[4];
goto P_0c069bea;
P_0c069bea: /* original 1f32, guest PC 0x0c069bea */
if(!s->budget--) { s->failed_pc=0x0c069beau; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c069bec;
P_0c069bec: /* original 1f44, guest PC 0x0c069bec */
if(!s->budget--) { s->failed_pc=0x0c069becu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c069bee;
P_0c069bee: /* original 64e3, guest PC 0x0c069bee */
if(!s->budget--) { s->failed_pc=0x0c069beeu; return 0; }
r[4]=r[14];
goto P_0c069bf0;
P_0c069bf0: /* original 4c0b, guest PC 0x0c069bf0 */
if(!s->budget--) { s->failed_pc=0x0c069bf0u; return 0; }
target=r[12];
r[16]=code_base|0x0c069bf4u;
r[4]+=0x0000007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069bf4u) { target=s->pc; goto dispatch; }
goto P_0c069bf4;
P_0c069bf2: /* original 747c, guest PC 0x0c069bf2 */
if(!s->budget--) { s->failed_pc=0x0c069bf2u; return 0; }
r[4]+=0x0000007cu;
goto P_0c069bf4;
P_0c069bf4: /* original d350, guest PC 0x0c069bf4 */
if(!s->budget--) { s->failed_pc=0x0c069bf4u; return 0; }
r[3]=read(ram,0x0c069d38u,4);
goto P_0c069bf6;
P_0c069bf6: /* original 51f4, guest PC 0x0c069bf6 */
if(!s->budget--) { s->failed_pc=0x0c069bf6u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c069bf8;
P_0c069bf8: /* original 430b, guest PC 0x0c069bf8 */
if(!s->budget--) { s->failed_pc=0x0c069bf8u; return 0; }
target=r[3];
r[16]=code_base|0x0c069bfcu;
r[0]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069bfcu) { target=s->pc; goto dispatch; }
goto P_0c069bfc;
P_0c069bfa: /* original 50f3, guest PC 0x0c069bfa */
if(!s->budget--) { s->failed_pc=0x0c069bfau; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c069bfc;
P_0c069bfc: /* original 64e3, guest PC 0x0c069bfc */
if(!s->budget--) { s->failed_pc=0x0c069bfcu; return 0; }
r[4]=r[14];
goto P_0c069bfe;
P_0c069bfe: /* original 6503, guest PC 0x0c069bfe */
if(!s->budget--) { s->failed_pc=0x0c069bfeu; return 0; }
r[5]=r[0];
goto P_0c069c00;
P_0c069c00: /* original 1f03, guest PC 0x0c069c00 */
if(!s->budget--) { s->failed_pc=0x0c069c00u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c069c02;
P_0c069c02: /* original 4c0b, guest PC 0x0c069c02 */
if(!s->budget--) { s->failed_pc=0x0c069c02u; return 0; }
target=r[12];
r[16]=code_base|0x0c069c06u;
r[4]+=0x0000006cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c06u) { target=s->pc; goto dispatch; }
goto P_0c069c06;
P_0c069c04: /* original 746c, guest PC 0x0c069c04 */
if(!s->budget--) { s->failed_pc=0x0c069c04u; return 0; }
r[4]+=0x0000006cu;
goto P_0c069c06;
P_0c069c06: /* original d34c, guest PC 0x0c069c06 */
if(!s->budget--) { s->failed_pc=0x0c069c06u; return 0; }
r[3]=read(ram,0x0c069d38u,4);
goto P_0c069c08;
P_0c069c08: /* original 51f2, guest PC 0x0c069c08 */
if(!s->budget--) { s->failed_pc=0x0c069c08u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c069c0a;
P_0c069c0a: /* original 947f, guest PC 0x0c069c0a */
if(!s->budget--) { s->failed_pc=0x0c069c0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d0cu,2);
goto P_0c069c0c;
P_0c069c0c: /* original 430b, guest PC 0x0c069c0c */
if(!s->budget--) { s->failed_pc=0x0c069c0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c069c10u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c10u) { target=s->pc; goto dispatch; }
goto P_0c069c10;
P_0c069c0e: /* original 6043, guest PC 0x0c069c0e */
if(!s->budget--) { s->failed_pc=0x0c069c0eu; return 0; }
r[0]=r[4];
goto P_0c069c10;
P_0c069c10: /* original 3096, guest PC 0x0c069c10 */
if(!s->budget--) { s->failed_pc=0x0c069c10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[9])!=0);
goto P_0c069c12;
P_0c069c12: /* original 8f01, guest PC 0x0c069c12 */
if(!s->budget--) { s->failed_pc=0x0c069c12u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[0],4);
if(!cond) { goto P_0c069c18; }
goto P_0c069c16;
P_0c069c14: /* original 1f02, guest PC 0x0c069c14 */
if(!s->budget--) { s->failed_pc=0x0c069c14u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c069c16;
P_0c069c16: /* original 1f92, guest PC 0x0c069c16 */
if(!s->budget--) { s->failed_pc=0x0c069c16u; return 0; }
write(ram,r[15]+8,r[9],4);
goto P_0c069c18;
P_0c069c18: /* original 9379, guest PC 0x0c069c18 */
if(!s->budget--) { s->failed_pc=0x0c069c18u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d0eu,2);
goto P_0c069c1a;
P_0c069c1a: /* original e501, guest PC 0x0c069c1a */
if(!s->budget--) { s->failed_pc=0x0c069c1au; return 0; }
r[5]=0x00000001u;
goto P_0c069c1c;
P_0c069c1c: /* original 54f2, guest PC 0x0c069c1c */
if(!s->budget--) { s->failed_pc=0x0c069c1cu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c069c1e;
P_0c069c1e: /* original 33ec, guest PC 0x0c069c1e */
if(!s->budget--) { s->failed_pc=0x0c069c1eu; return 0; }
r[3]+=r[14];
goto P_0c069c20;
P_0c069c20: /* original 4408, guest PC 0x0c069c20 */
if(!s->budget--) { s->failed_pc=0x0c069c20u; return 0; }
r[4]<<=2;
goto P_0c069c22;
P_0c069c22: /* original 343c, guest PC 0x0c069c22 */
if(!s->budget--) { s->failed_pc=0x0c069c22u; return 0; }
r[4]+=r[3];
goto P_0c069c24;
P_0c069c24: /* original bd4f, guest PC 0x0c069c24 */
if(!s->budget--) { s->failed_pc=0x0c069c24u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069c28u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c28u) { target=s->pc; goto dispatch; }
goto P_0c069c28;
P_0c069c26: /* original 0009, guest PC 0x0c069c26 */
if(!s->budget--) { s->failed_pc=0x0c069c26u; return 0; }
goto P_0c069c28;
P_0c069c28: /* original 9472, guest PC 0x0c069c28 */
if(!s->budget--) { s->failed_pc=0x0c069c28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d10u,2);
goto P_0c069c2a;
P_0c069c2a: /* original 4b0b, guest PC 0x0c069c2a */
if(!s->budget--) { s->failed_pc=0x0c069c2au; return 0; }
target=r[11];
r[16]=code_base|0x0c069c2eu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c2eu) { target=s->pc; goto dispatch; }
goto P_0c069c2e;
P_0c069c2c: /* original 34ec, guest PC 0x0c069c2c */
if(!s->budget--) { s->failed_pc=0x0c069c2cu; return 0; }
r[4]+=r[14];
goto P_0c069c2e;
P_0c069c2e: /* original 6403, guest PC 0x0c069c2e */
if(!s->budget--) { s->failed_pc=0x0c069c2eu; return 0; }
r[4]=r[0];
goto P_0c069c30;
P_0c069c30: /* original 906b, guest PC 0x0c069c30 */
if(!s->budget--) { s->failed_pc=0x0c069c30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d0au,2);
goto P_0c069c32;
P_0c069c32: /* original 03de, guest PC 0x0c069c32 */
if(!s->budget--) { s->failed_pc=0x0c069c32u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069c34;
P_0c069c34: /* original 6233, guest PC 0x0c069c34 */
if(!s->budget--) { s->failed_pc=0x0c069c34u; return 0; }
r[2]=r[3];
goto P_0c069c36;
P_0c069c36: /* original 342c, guest PC 0x0c069c36 */
if(!s->budget--) { s->failed_pc=0x0c069c36u; return 0; }
r[4]+=r[2];
goto P_0c069c38;
P_0c069c38: /* original 6543, guest PC 0x0c069c38 */
if(!s->budget--) { s->failed_pc=0x0c069c38u; return 0; }
r[5]=r[4];
goto P_0c069c3a;
P_0c069c3a: /* original 1f33, guest PC 0x0c069c3a */
if(!s->budget--) { s->failed_pc=0x0c069c3au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c069c3c;
P_0c069c3c: /* original 1f42, guest PC 0x0c069c3c */
if(!s->budget--) { s->failed_pc=0x0c069c3cu; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c069c3e;
P_0c069c3e: /* original 9467, guest PC 0x0c069c3e */
if(!s->budget--) { s->failed_pc=0x0c069c3eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d10u,2);
goto P_0c069c40;
P_0c069c40: /* original 4c0b, guest PC 0x0c069c40 */
if(!s->budget--) { s->failed_pc=0x0c069c40u; return 0; }
target=r[12];
r[16]=code_base|0x0c069c44u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c44u) { target=s->pc; goto dispatch; }
goto P_0c069c44;
P_0c069c42: /* original 34ec, guest PC 0x0c069c42 */
if(!s->budget--) { s->failed_pc=0x0c069c42u; return 0; }
r[4]+=r[14];
goto P_0c069c44;
P_0c069c44: /* original 9465, guest PC 0x0c069c44 */
if(!s->budget--) { s->failed_pc=0x0c069c44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d12u,2);
goto P_0c069c46;
P_0c069c46: /* original 4b0b, guest PC 0x0c069c46 */
if(!s->budget--) { s->failed_pc=0x0c069c46u; return 0; }
target=r[11];
r[16]=code_base|0x0c069c4au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c4au) { target=s->pc; goto dispatch; }
goto P_0c069c4a;
P_0c069c48: /* original 34ec, guest PC 0x0c069c48 */
if(!s->budget--) { s->failed_pc=0x0c069c48u; return 0; }
r[4]+=r[14];
goto P_0c069c4a;
P_0c069c4a: /* original 6303, guest PC 0x0c069c4a */
if(!s->budget--) { s->failed_pc=0x0c069c4au; return 0; }
r[3]=r[0];
goto P_0c069c4c;
P_0c069c4c: /* original 7301, guest PC 0x0c069c4c */
if(!s->budget--) { s->failed_pc=0x0c069c4cu; return 0; }
r[3]+=0x00000001u;
goto P_0c069c4e;
P_0c069c4e: /* original 6533, guest PC 0x0c069c4e */
if(!s->budget--) { s->failed_pc=0x0c069c4eu; return 0; }
r[5]=r[3];
goto P_0c069c50;
P_0c069c50: /* original 1f34, guest PC 0x0c069c50 */
if(!s->budget--) { s->failed_pc=0x0c069c50u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c069c52;
P_0c069c52: /* original 945e, guest PC 0x0c069c52 */
if(!s->budget--) { s->failed_pc=0x0c069c52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d12u,2);
goto P_0c069c54;
P_0c069c54: /* original 4c0b, guest PC 0x0c069c54 */
if(!s->budget--) { s->failed_pc=0x0c069c54u; return 0; }
target=r[12];
r[16]=code_base|0x0c069c58u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c58u) { target=s->pc; goto dispatch; }
goto P_0c069c58;
P_0c069c56: /* original 34ec, guest PC 0x0c069c56 */
if(!s->budget--) { s->failed_pc=0x0c069c56u; return 0; }
r[4]+=r[14];
goto P_0c069c58;
P_0c069c58: /* original d337, guest PC 0x0c069c58 */
if(!s->budget--) { s->failed_pc=0x0c069c58u; return 0; }
r[3]=read(ram,0x0c069d38u,4);
goto P_0c069c5a;
P_0c069c5a: /* original 51f2, guest PC 0x0c069c5a */
if(!s->budget--) { s->failed_pc=0x0c069c5au; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c069c5c;
P_0c069c5c: /* original 430b, guest PC 0x0c069c5c */
if(!s->budget--) { s->failed_pc=0x0c069c5cu; return 0; }
target=r[3];
r[16]=code_base|0x0c069c60u;
r[0]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c60u) { target=s->pc; goto dispatch; }
goto P_0c069c60;
P_0c069c5e: /* original 50f4, guest PC 0x0c069c5e */
if(!s->budget--) { s->failed_pc=0x0c069c5eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c069c60;
P_0c069c60: /* original 6503, guest PC 0x0c069c60 */
if(!s->budget--) { s->failed_pc=0x0c069c60u; return 0; }
r[5]=r[0];
goto P_0c069c62;
P_0c069c62: /* original 1f04, guest PC 0x0c069c62 */
if(!s->budget--) { s->failed_pc=0x0c069c62u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c069c64;
P_0c069c64: /* original 9456, guest PC 0x0c069c64 */
if(!s->budget--) { s->failed_pc=0x0c069c64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d14u,2);
goto P_0c069c66;
P_0c069c66: /* original 4c0b, guest PC 0x0c069c66 */
if(!s->budget--) { s->failed_pc=0x0c069c66u; return 0; }
target=r[12];
r[16]=code_base|0x0c069c6au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c6au) { target=s->pc; goto dispatch; }
goto P_0c069c6a;
P_0c069c68: /* original 34ec, guest PC 0x0c069c68 */
if(!s->budget--) { s->failed_pc=0x0c069c68u; return 0; }
r[4]+=r[14];
goto P_0c069c6a;
P_0c069c6a: /* original 9454, guest PC 0x0c069c6a */
if(!s->budget--) { s->failed_pc=0x0c069c6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d16u,2);
goto P_0c069c6c;
P_0c069c6c: /* original 4b0b, guest PC 0x0c069c6c */
if(!s->budget--) { s->failed_pc=0x0c069c6cu; return 0; }
target=r[11];
r[16]=code_base|0x0c069c70u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c70u) { target=s->pc; goto dispatch; }
goto P_0c069c70;
P_0c069c6e: /* original 34ec, guest PC 0x0c069c6e */
if(!s->budget--) { s->failed_pc=0x0c069c6eu; return 0; }
r[4]+=r[14];
goto P_0c069c70;
P_0c069c70: /* original 6403, guest PC 0x0c069c70 */
if(!s->budget--) { s->failed_pc=0x0c069c70u; return 0; }
r[4]=r[0];
goto P_0c069c72;
P_0c069c72: /* original 2448, guest PC 0x0c069c72 */
if(!s->budget--) { s->failed_pc=0x0c069c72u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c069c74;
P_0c069c74: /* original 8902, guest PC 0x0c069c74 */
if(!s->budget--) { s->failed_pc=0x0c069c74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069c7c; }
goto P_0c069c76;
P_0c069c76: /* original 53f3, guest PC 0x0c069c76 */
if(!s->budget--) { s->failed_pc=0x0c069c76u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c069c78;
P_0c069c78: /* original 3436, guest PC 0x0c069c78 */
if(!s->budget--) { s->failed_pc=0x0c069c78u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c069c7a;
P_0c069c7a: /* original 8b03, guest PC 0x0c069c7a */
if(!s->budget--) { s->failed_pc=0x0c069c7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069c84; }
goto P_0c069c7c;
P_0c069c7c: /* original 944b, guest PC 0x0c069c7c */
if(!s->budget--) { s->failed_pc=0x0c069c7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d16u,2);
goto P_0c069c7e;
P_0c069c7e: /* original 55f3, guest PC 0x0c069c7e */
if(!s->budget--) { s->failed_pc=0x0c069c7eu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c069c80;
P_0c069c80: /* original 4c0b, guest PC 0x0c069c80 */
if(!s->budget--) { s->failed_pc=0x0c069c80u; return 0; }
target=r[12];
r[16]=code_base|0x0c069c84u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c84u) { target=s->pc; goto dispatch; }
goto P_0c069c84;
P_0c069c82: /* original 34ec, guest PC 0x0c069c82 */
if(!s->budget--) { s->failed_pc=0x0c069c82u; return 0; }
r[4]+=r[14];
goto P_0c069c84;
P_0c069c84: /* original 9448, guest PC 0x0c069c84 */
if(!s->budget--) { s->failed_pc=0x0c069c84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d18u,2);
goto P_0c069c86;
P_0c069c86: /* original 4b0b, guest PC 0x0c069c86 */
if(!s->budget--) { s->failed_pc=0x0c069c86u; return 0; }
target=r[11];
r[16]=code_base|0x0c069c8au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c8au) { target=s->pc; goto dispatch; }
goto P_0c069c8a;
P_0c069c88: /* original 34ec, guest PC 0x0c069c88 */
if(!s->budget--) { s->failed_pc=0x0c069c88u; return 0; }
r[4]+=r[14];
goto P_0c069c8a;
P_0c069c8a: /* original 6403, guest PC 0x0c069c8a */
if(!s->budget--) { s->failed_pc=0x0c069c8au; return 0; }
r[4]=r[0];
goto P_0c069c8c;
P_0c069c8c: /* original 2448, guest PC 0x0c069c8c */
if(!s->budget--) { s->failed_pc=0x0c069c8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c069c8e;
P_0c069c8e: /* original 8902, guest PC 0x0c069c8e */
if(!s->budget--) { s->failed_pc=0x0c069c8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069c96; }
goto P_0c069c90;
P_0c069c90: /* original 53f3, guest PC 0x0c069c90 */
if(!s->budget--) { s->failed_pc=0x0c069c90u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c069c92;
P_0c069c92: /* original 3432, guest PC 0x0c069c92 */
if(!s->budget--) { s->failed_pc=0x0c069c92u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c069c94;
P_0c069c94: /* original 8903, guest PC 0x0c069c94 */
if(!s->budget--) { s->failed_pc=0x0c069c94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069c9e; }
goto P_0c069c96;
P_0c069c96: /* original 943f, guest PC 0x0c069c96 */
if(!s->budget--) { s->failed_pc=0x0c069c96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d18u,2);
goto P_0c069c98;
P_0c069c98: /* original 55f3, guest PC 0x0c069c98 */
if(!s->budget--) { s->failed_pc=0x0c069c98u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c069c9a;
P_0c069c9a: /* original 4c0b, guest PC 0x0c069c9a */
if(!s->budget--) { s->failed_pc=0x0c069c9au; return 0; }
target=r[12];
r[16]=code_base|0x0c069c9eu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069c9eu) { target=s->pc; goto dispatch; }
goto P_0c069c9e;
P_0c069c9c: /* original 34ec, guest PC 0x0c069c9c */
if(!s->budget--) { s->failed_pc=0x0c069c9cu; return 0; }
r[4]+=r[14];
goto P_0c069c9e;
P_0c069c9e: /* original 53f1, guest PC 0x0c069c9e */
if(!s->budget--) { s->failed_pc=0x0c069c9eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c069ca0;
P_0c069ca0: /* original 2338, guest PC 0x0c069ca0 */
if(!s->budget--) { s->failed_pc=0x0c069ca0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c069ca2;
P_0c069ca2: /* original 8903, guest PC 0x0c069ca2 */
if(!s->budget--) { s->failed_pc=0x0c069ca2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069cac; }
goto P_0c069ca4;
P_0c069ca4: /* original 9439, guest PC 0x0c069ca4 */
if(!s->budget--) { s->failed_pc=0x0c069ca4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d1au,2);
goto P_0c069ca6;
P_0c069ca6: /* original e501, guest PC 0x0c069ca6 */
if(!s->budget--) { s->failed_pc=0x0c069ca6u; return 0; }
r[5]=0x00000001u;
goto P_0c069ca8;
P_0c069ca8: /* original bd0d, guest PC 0x0c069ca8 */
if(!s->budget--) { s->failed_pc=0x0c069ca8u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069cacu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069cacu) { target=s->pc; goto dispatch; }
goto P_0c069cac;
P_0c069caa: /* original 34ec, guest PC 0x0c069caa */
if(!s->budget--) { s->failed_pc=0x0c069caau; return 0; }
r[4]+=r[14];
goto P_0c069cac;
P_0c069cac: /* original 9036, guest PC 0x0c069cac */
if(!s->budget--) { s->failed_pc=0x0c069cacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d1cu,2);
goto P_0c069cae;
P_0c069cae: /* original 9436, guest PC 0x0c069cae */
if(!s->budget--) { s->failed_pc=0x0c069caeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d1eu,2);
goto P_0c069cb0;
P_0c069cb0: /* original 05de, guest PC 0x0c069cb0 */
if(!s->budget--) { s->failed_pc=0x0c069cb0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c069cb2;
P_0c069cb2: /* original bd08, guest PC 0x0c069cb2 */
if(!s->budget--) { s->failed_pc=0x0c069cb2u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069cb6u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069cb6u) { target=s->pc; goto dispatch; }
goto P_0c069cb6;
P_0c069cb4: /* original 34ec, guest PC 0x0c069cb4 */
if(!s->budget--) { s->failed_pc=0x0c069cb4u; return 0; }
r[4]+=r[14];
goto P_0c069cb6;
P_0c069cb6: /* original 9033, guest PC 0x0c069cb6 */
if(!s->budget--) { s->failed_pc=0x0c069cb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d20u,2);
goto P_0c069cb8;
P_0c069cb8: /* original 9433, guest PC 0x0c069cb8 */
if(!s->budget--) { s->failed_pc=0x0c069cb8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d22u,2);
goto P_0c069cba;
P_0c069cba: /* original 05de, guest PC 0x0c069cba */
if(!s->budget--) { s->failed_pc=0x0c069cbau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c069cbc;
P_0c069cbc: /* original bd03, guest PC 0x0c069cbc */
if(!s->budget--) { s->failed_pc=0x0c069cbcu; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069cc0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069cc0u) { target=s->pc; goto dispatch; }
goto P_0c069cc0;
P_0c069cbe: /* original 34ec, guest PC 0x0c069cbe */
if(!s->budget--) { s->failed_pc=0x0c069cbeu; return 0; }
r[4]+=r[14];
goto P_0c069cc0;
P_0c069cc0: /* original 9030, guest PC 0x0c069cc0 */
if(!s->budget--) { s->failed_pc=0x0c069cc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d24u,2);
goto P_0c069cc2;
P_0c069cc2: /* original 9430, guest PC 0x0c069cc2 */
if(!s->budget--) { s->failed_pc=0x0c069cc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d26u,2);
goto P_0c069cc4;
P_0c069cc4: /* original 05de, guest PC 0x0c069cc4 */
if(!s->budget--) { s->failed_pc=0x0c069cc4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c069cc6;
P_0c069cc6: /* original bcfe, guest PC 0x0c069cc6 */
if(!s->budget--) { s->failed_pc=0x0c069cc6u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069ccau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069ccau) { target=s->pc; goto dispatch; }
goto P_0c069cca;
P_0c069cc8: /* original 34ec, guest PC 0x0c069cc8 */
if(!s->budget--) { s->failed_pc=0x0c069cc8u; return 0; }
r[4]+=r[14];
goto P_0c069cca;
P_0c069cca: /* original 902d, guest PC 0x0c069cca */
if(!s->budget--) { s->failed_pc=0x0c069ccau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d28u,2);
goto P_0c069ccc;
P_0c069ccc: /* original 942d, guest PC 0x0c069ccc */
if(!s->budget--) { s->failed_pc=0x0c069cccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d2au,2);
goto P_0c069cce;
P_0c069cce: /* original 05de, guest PC 0x0c069cce */
if(!s->budget--) { s->failed_pc=0x0c069cceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c069cd0;
P_0c069cd0: /* original bcf9, guest PC 0x0c069cd0 */
if(!s->budget--) { s->failed_pc=0x0c069cd0u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069cd4u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069cd4u) { target=s->pc; goto dispatch; }
goto P_0c069cd4;
P_0c069cd2: /* original 34ec, guest PC 0x0c069cd2 */
if(!s->budget--) { s->failed_pc=0x0c069cd2u; return 0; }
r[4]+=r[14];
goto P_0c069cd4;
P_0c069cd4: /* original 902a, guest PC 0x0c069cd4 */
if(!s->budget--) { s->failed_pc=0x0c069cd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d2cu,2);
goto P_0c069cd6;
P_0c069cd6: /* original 942a, guest PC 0x0c069cd6 */
if(!s->budget--) { s->failed_pc=0x0c069cd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d2eu,2);
goto P_0c069cd8;
P_0c069cd8: /* original 05de, guest PC 0x0c069cd8 */
if(!s->budget--) { s->failed_pc=0x0c069cd8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c069cda;
P_0c069cda: /* original bcf4, guest PC 0x0c069cda */
if(!s->budget--) { s->failed_pc=0x0c069cdau; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069cdeu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069cdeu) { target=s->pc; goto dispatch; }
goto P_0c069cde;
P_0c069cdc: /* original 34ec, guest PC 0x0c069cdc */
if(!s->budget--) { s->failed_pc=0x0c069cdcu; return 0; }
r[4]+=r[14];
goto P_0c069cde;
P_0c069cde: /* original e209, guest PC 0x0c069cde */
if(!s->budget--) { s->failed_pc=0x0c069cdeu; return 0; }
r[2]=0x00000009u;
goto P_0c069ce0;
P_0c069ce0: /* original 64e3, guest PC 0x0c069ce0 */
if(!s->budget--) { s->failed_pc=0x0c069ce0u; return 0; }
r[4]=r[14];
goto P_0c069ce2;
P_0c069ce2: /* original 1f2c, guest PC 0x0c069ce2 */
if(!s->budget--) { s->failed_pc=0x0c069ce2u; return 0; }
write(ram,r[15]+48,r[2],4);
goto P_0c069ce4;
P_0c069ce4: /* original 4b0b, guest PC 0x0c069ce4 */
if(!s->budget--) { s->failed_pc=0x0c069ce4u; return 0; }
target=r[11];
r[16]=code_base|0x0c069ce8u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069ce8u) { target=s->pc; goto dispatch; }
goto P_0c069ce8;
P_0c069ce6: /* original 7458, guest PC 0x0c069ce6 */
if(!s->budget--) { s->failed_pc=0x0c069ce6u; return 0; }
r[4]+=0x00000058u;
goto P_0c069ce8;
P_0c069ce8: /* original 1f0a, guest PC 0x0c069ce8 */
if(!s->budget--) { s->failed_pc=0x0c069ce8u; return 0; }
write(ram,r[15]+40,r[0],4);
goto P_0c069cea;
P_0c069cea: /* original e058, guest PC 0x0c069cea */
if(!s->budget--) { s->failed_pc=0x0c069ceau; return 0; }
r[0]=0x00000058u;
goto P_0c069cec;
P_0c069cec: /* original 9320, guest PC 0x0c069cec */
if(!s->budget--) { s->failed_pc=0x0c069cecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d30u,2);
goto P_0c069cee;
P_0c069cee: /* original 33dc, guest PC 0x0c069cee */
if(!s->budget--) { s->failed_pc=0x0c069ceeu; return 0; }
r[3]+=r[13];
goto P_0c069cf0;
P_0c069cf0: /* original 0f36, guest PC 0x0c069cf0 */
if(!s->budget--) { s->failed_pc=0x0c069cf0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c069cf2;
P_0c069cf2: /* original e05c, guest PC 0x0c069cf2 */
if(!s->budget--) { s->failed_pc=0x0c069cf2u; return 0; }
r[0]=0x0000005cu;
goto P_0c069cf4;
P_0c069cf4: /* original 921d, guest PC 0x0c069cf4 */
if(!s->budget--) { s->failed_pc=0x0c069cf4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d32u,2);
goto P_0c069cf6;
P_0c069cf6: /* original 32dc, guest PC 0x0c069cf6 */
if(!s->budget--) { s->failed_pc=0x0c069cf6u; return 0; }
r[2]+=r[13];
goto P_0c069cf8;
P_0c069cf8: /* original 0f26, guest PC 0x0c069cf8 */
if(!s->budget--) { s->failed_pc=0x0c069cf8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c069cfa;
P_0c069cfa: /* original e060, guest PC 0x0c069cfa */
if(!s->budget--) { s->failed_pc=0x0c069cfau; return 0; }
r[0]=0x00000060u;
goto P_0c069cfc;
P_0c069cfc: /* original 931a, guest PC 0x0c069cfc */
if(!s->budget--) { s->failed_pc=0x0c069cfcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d34u,2);
goto P_0c069cfe;
P_0c069cfe: /* original 33dc, guest PC 0x0c069cfe */
if(!s->budget--) { s->failed_pc=0x0c069cfeu; return 0; }
r[3]+=r[13];
goto P_0c069d00;
P_0c069d00: /* original 0f36, guest PC 0x0c069d00 */
if(!s->budget--) { s->failed_pc=0x0c069d00u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c069d02;
P_0c069d02: /* original 9218, guest PC 0x0c069d02 */
if(!s->budget--) { s->failed_pc=0x0c069d02u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069d36u,2);
goto P_0c069d04;
P_0c069d04: /* original 32ec, guest PC 0x0c069d04 */
if(!s->budget--) { s->failed_pc=0x0c069d04u; return 0; }
r[2]+=r[14];
goto P_0c069d06;
P_0c069d06: /* original a019, guest PC 0x0c069d06 */
if(!s->budget--) { s->failed_pc=0x0c069d06u; return 0; }
goto P_0c069d3c;
P_0c069d08: /* original 0009, guest PC 0x0c069d08 */
if(!s->budget--) { s->failed_pc=0x0c069d08u; return 0; }
if(!vf3_matrix_family(0x0c069d0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069d0au; return 0; } return 1;
P_0c069d3c: /* original e054, guest PC 0x0c069d3c */
if(!s->budget--) { s->failed_pc=0x0c069d3cu; return 0; }
r[0]=0x00000054u;
goto P_0c069d3e;
P_0c069d3e: /* original 0f26, guest PC 0x0c069d3e */
if(!s->budget--) { s->failed_pc=0x0c069d3eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c069d40;
P_0c069d40: /* original e048, guest PC 0x0c069d40 */
if(!s->budget--) { s->failed_pc=0x0c069d40u; return 0; }
r[0]=0x00000048u;
goto P_0c069d42;
P_0c069d42: /* original 938b, guest PC 0x0c069d42 */
if(!s->budget--) { s->failed_pc=0x0c069d42u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069e5cu,2);
goto P_0c069d44;
P_0c069d44: /* original 33ec, guest PC 0x0c069d44 */
if(!s->budget--) { s->failed_pc=0x0c069d44u; return 0; }
r[3]+=r[14];
goto P_0c069d46;
P_0c069d46: /* original 1f38, guest PC 0x0c069d46 */
if(!s->budget--) { s->failed_pc=0x0c069d46u; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c069d48;
P_0c069d48: /* original 9289, guest PC 0x0c069d48 */
if(!s->budget--) { s->failed_pc=0x0c069d48u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069e5eu,2);
goto P_0c069d4a;
P_0c069d4a: /* original 32ec, guest PC 0x0c069d4a */
if(!s->budget--) { s->failed_pc=0x0c069d4au; return 0; }
r[2]+=r[14];
goto P_0c069d4c;
P_0c069d4c: /* original 0f26, guest PC 0x0c069d4c */
if(!s->budget--) { s->failed_pc=0x0c069d4cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c069d4e;
P_0c069d4e: /* original e200, guest PC 0x0c069d4e */
if(!s->budget--) { s->failed_pc=0x0c069d4eu; return 0; }
r[2]=0x00000000u;
goto P_0c069d50;
P_0c069d50: /* original 9386, guest PC 0x0c069d50 */
if(!s->budget--) { s->failed_pc=0x0c069d50u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069e60u,2);
goto P_0c069d52;
P_0c069d52: /* original 6123, guest PC 0x0c069d52 */
if(!s->budget--) { s->failed_pc=0x0c069d52u; return 0; }
r[1]=r[2];
goto P_0c069d54;
P_0c069d54: /* original e04c, guest PC 0x0c069d54 */
if(!s->budget--) { s->failed_pc=0x0c069d54u; return 0; }
r[0]=0x0000004cu;
goto P_0c069d56;
P_0c069d56: /* original 33ec, guest PC 0x0c069d56 */
if(!s->budget--) { s->failed_pc=0x0c069d56u; return 0; }
r[3]+=r[14];
goto P_0c069d58;
P_0c069d58: /* original 0f36, guest PC 0x0c069d58 */
if(!s->budget--) { s->failed_pc=0x0c069d58u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c069d5a;
P_0c069d5a: /* original 1f23, guest PC 0x0c069d5a */
if(!s->budget--) { s->failed_pc=0x0c069d5au; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c069d5c;
P_0c069d5c: /* original 1f1b, guest PC 0x0c069d5c */
if(!s->budget--) { s->failed_pc=0x0c069d5cu; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c069d5e;
P_0c069d5e: /* original e048, guest PC 0x0c069d5e */
if(!s->budget--) { s->failed_pc=0x0c069d5eu; return 0; }
r[0]=0x00000048u;
goto P_0c069d60;
P_0c069d60: /* original 56fb, guest PC 0x0c069d60 */
if(!s->budget--) { s->failed_pc=0x0c069d60u; return 0; }
r[6]=read(ram,r[15]+44,4);
goto P_0c069d62;
P_0c069d62: /* original 53f8, guest PC 0x0c069d62 */
if(!s->budget--) { s->failed_pc=0x0c069d62u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c069d64;
P_0c069d64: /* original 4608, guest PC 0x0c069d64 */
if(!s->budget--) { s->failed_pc=0x0c069d64u; return 0; }
r[6]<<=2;
goto P_0c069d66;
P_0c069d66: /* original 54f8, guest PC 0x0c069d66 */
if(!s->budget--) { s->failed_pc=0x0c069d66u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c069d68;
P_0c069d68: /* original 336c, guest PC 0x0c069d68 */
if(!s->budget--) { s->failed_pc=0x0c069d68u; return 0; }
r[3]+=r[6];
goto P_0c069d6a;
P_0c069d6a: /* original 1f3d, guest PC 0x0c069d6a */
if(!s->budget--) { s->failed_pc=0x0c069d6au; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c069d6c;
P_0c069d6c: /* original 346c, guest PC 0x0c069d6c */
if(!s->budget--) { s->failed_pc=0x0c069d6cu; return 0; }
r[4]+=r[6];
goto P_0c069d6e;
P_0c069d6e: /* original 02fe, guest PC 0x0c069d6e */
if(!s->budget--) { s->failed_pc=0x0c069d6eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c069d70;
P_0c069d70: /* original e068, guest PC 0x0c069d70 */
if(!s->budget--) { s->failed_pc=0x0c069d70u; return 0; }
r[0]=0x00000068u;
goto P_0c069d72;
P_0c069d72: /* original 326c, guest PC 0x0c069d72 */
if(!s->budget--) { s->failed_pc=0x0c069d72u; return 0; }
r[2]+=r[6];
goto P_0c069d74;
P_0c069d74: /* original 0f26, guest PC 0x0c069d74 */
if(!s->budget--) { s->failed_pc=0x0c069d74u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c069d76;
P_0c069d76: /* original e04c, guest PC 0x0c069d76 */
if(!s->budget--) { s->failed_pc=0x0c069d76u; return 0; }
r[0]=0x0000004cu;
goto P_0c069d78;
P_0c069d78: /* original 01fe, guest PC 0x0c069d78 */
if(!s->budget--) { s->failed_pc=0x0c069d78u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c069d7a;
P_0c069d7a: /* original e074, guest PC 0x0c069d7a */
if(!s->budget--) { s->failed_pc=0x0c069d7au; return 0; }
r[0]=0x00000074u;
goto P_0c069d7c;
P_0c069d7c: /* original 316c, guest PC 0x0c069d7c */
if(!s->budget--) { s->failed_pc=0x0c069d7cu; return 0; }
r[1]+=r[6];
goto P_0c069d7e;
P_0c069d7e: /* original 0f16, guest PC 0x0c069d7e */
if(!s->budget--) { s->failed_pc=0x0c069d7eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c069d80;
P_0c069d80: /* original e054, guest PC 0x0c069d80 */
if(!s->budget--) { s->failed_pc=0x0c069d80u; return 0; }
r[0]=0x00000054u;
goto P_0c069d82;
P_0c069d82: /* original 03fe, guest PC 0x0c069d82 */
if(!s->budget--) { s->failed_pc=0x0c069d82u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c069d84;
P_0c069d84: /* original e058, guest PC 0x0c069d84 */
if(!s->budget--) { s->failed_pc=0x0c069d84u; return 0; }
r[0]=0x00000058u;
goto P_0c069d86;
P_0c069d86: /* original 336c, guest PC 0x0c069d86 */
if(!s->budget--) { s->failed_pc=0x0c069d86u; return 0; }
r[3]+=r[6];
goto P_0c069d88;
P_0c069d88: /* original 1f34, guest PC 0x0c069d88 */
if(!s->budget--) { s->failed_pc=0x0c069d88u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c069d8a;
P_0c069d8a: /* original 05fe, guest PC 0x0c069d8a */
if(!s->budget--) { s->failed_pc=0x0c069d8au; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c069d8c;
P_0c069d8c: /* original e064, guest PC 0x0c069d8c */
if(!s->budget--) { s->failed_pc=0x0c069d8cu; return 0; }
r[0]=0x00000064u;
goto P_0c069d8e;
P_0c069d8e: /* original 356c, guest PC 0x0c069d8e */
if(!s->budget--) { s->failed_pc=0x0c069d8eu; return 0; }
r[5]+=r[6];
goto P_0c069d90;
P_0c069d90: /* original 0f56, guest PC 0x0c069d90 */
if(!s->budget--) { s->failed_pc=0x0c069d90u; return 0; }
write(ram,r[15]+r[0],r[5],4);
goto P_0c069d92;
P_0c069d92: /* original e05c, guest PC 0x0c069d92 */
if(!s->budget--) { s->failed_pc=0x0c069d92u; return 0; }
r[0]=0x0000005cu;
goto P_0c069d94;
P_0c069d94: /* original 02fe, guest PC 0x0c069d94 */
if(!s->budget--) { s->failed_pc=0x0c069d94u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c069d96;
P_0c069d96: /* original e050, guest PC 0x0c069d96 */
if(!s->budget--) { s->failed_pc=0x0c069d96u; return 0; }
r[0]=0x00000050u;
goto P_0c069d98;
P_0c069d98: /* original 6552, guest PC 0x0c069d98 */
if(!s->budget--) { s->failed_pc=0x0c069d98u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c069d9a;
P_0c069d9a: /* original 326c, guest PC 0x0c069d9a */
if(!s->budget--) { s->failed_pc=0x0c069d9au; return 0; }
r[2]+=r[6];
goto P_0c069d9c;
P_0c069d9c: /* original 0f26, guest PC 0x0c069d9c */
if(!s->budget--) { s->failed_pc=0x0c069d9cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c069d9e;
P_0c069d9e: /* original 6122, guest PC 0x0c069d9e */
if(!s->budget--) { s->failed_pc=0x0c069d9eu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c069da0;
P_0c069da0: /* original e06c, guest PC 0x0c069da0 */
if(!s->budget--) { s->failed_pc=0x0c069da0u; return 0; }
r[0]=0x0000006cu;
goto P_0c069da2;
P_0c069da2: /* original 0f16, guest PC 0x0c069da2 */
if(!s->budget--) { s->failed_pc=0x0c069da2u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c069da4;
P_0c069da4: /* original e060, guest PC 0x0c069da4 */
if(!s->budget--) { s->failed_pc=0x0c069da4u; return 0; }
r[0]=0x00000060u;
goto P_0c069da6;
P_0c069da6: /* original 01fe, guest PC 0x0c069da6 */
if(!s->budget--) { s->failed_pc=0x0c069da6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c069da8;
P_0c069da8: /* original e044, guest PC 0x0c069da8 */
if(!s->budget--) { s->failed_pc=0x0c069da8u; return 0; }
r[0]=0x00000044u;
goto P_0c069daa;
P_0c069daa: /* original 361c, guest PC 0x0c069daa */
if(!s->budget--) { s->failed_pc=0x0c069daau; return 0; }
r[6]+=r[1];
goto P_0c069dac;
P_0c069dac: /* original 0f66, guest PC 0x0c069dac */
if(!s->budget--) { s->failed_pc=0x0c069dacu; return 0; }
write(ram,r[15]+r[0],r[6],4);
goto P_0c069dae;
P_0c069dae: /* original e070, guest PC 0x0c069dae */
if(!s->budget--) { s->failed_pc=0x0c069daeu; return 0; }
r[0]=0x00000070u;
goto P_0c069db0;
P_0c069db0: /* original 6362, guest PC 0x0c069db0 */
if(!s->budget--) { s->failed_pc=0x0c069db0u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c069db2;
P_0c069db2: /* original 0f36, guest PC 0x0c069db2 */
if(!s->budget--) { s->failed_pc=0x0c069db2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c069db4;
P_0c069db4: /* original bc87, guest PC 0x0c069db4 */
if(!s->budget--) { s->failed_pc=0x0c069db4u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069db8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069db8u) { target=s->pc; goto dispatch; }
goto P_0c069db8;
P_0c069db6: /* original 0009, guest PC 0x0c069db6 */
if(!s->budget--) { s->failed_pc=0x0c069db6u; return 0; }
goto P_0c069db8;
P_0c069db8: /* original 4b0b, guest PC 0x0c069db8 */
if(!s->budget--) { s->failed_pc=0x0c069db8u; return 0; }
target=r[11];
r[16]=code_base|0x0c069dbcu;
r[4]=read(ram,r[15]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069dbcu) { target=s->pc; goto dispatch; }
goto P_0c069dbc;
P_0c069dba: /* original 54fd, guest PC 0x0c069dba */
if(!s->budget--) { s->failed_pc=0x0c069dbau; return 0; }
r[4]=read(ram,r[15]+52,4);
goto P_0c069dbc;
P_0c069dbc: /* original 62f3, guest PC 0x0c069dbc */
if(!s->budget--) { s->failed_pc=0x0c069dbcu; return 0; }
r[2]=r[15];
goto P_0c069dbe;
P_0c069dbe: /* original 726c, guest PC 0x0c069dbe */
if(!s->budget--) { s->failed_pc=0x0c069dbeu; return 0; }
r[2]+=0x0000006cu;
goto P_0c069dc0;
P_0c069dc0: /* original 1f01, guest PC 0x0c069dc0 */
if(!s->budget--) { s->failed_pc=0x0c069dc0u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c069dc2;
P_0c069dc2: /* original 6322, guest PC 0x0c069dc2 */
if(!s->budget--) { s->failed_pc=0x0c069dc2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c069dc4;
P_0c069dc4: /* original 303c, guest PC 0x0c069dc4 */
if(!s->budget--) { s->failed_pc=0x0c069dc4u; return 0; }
r[0]+=r[3];
goto P_0c069dc6;
P_0c069dc6: /* original 6503, guest PC 0x0c069dc6 */
if(!s->budget--) { s->failed_pc=0x0c069dc6u; return 0; }
r[5]=r[0];
goto P_0c069dc8;
P_0c069dc8: /* original 1f01, guest PC 0x0c069dc8 */
if(!s->budget--) { s->failed_pc=0x0c069dc8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c069dca;
P_0c069dca: /* original 4c0b, guest PC 0x0c069dca */
if(!s->budget--) { s->failed_pc=0x0c069dcau; return 0; }
target=r[12];
r[16]=code_base|0x0c069dceu;
r[4]=read(ram,r[15]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069dceu) { target=s->pc; goto dispatch; }
goto P_0c069dce;
P_0c069dcc: /* original 54fd, guest PC 0x0c069dcc */
if(!s->budget--) { s->failed_pc=0x0c069dccu; return 0; }
r[4]=read(ram,r[15]+52,4);
goto P_0c069dce;
P_0c069dce: /* original 52f1, guest PC 0x0c069dce */
if(!s->budget--) { s->failed_pc=0x0c069dceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c069dd0;
P_0c069dd0: /* original e364, guest PC 0x0c069dd0 */
if(!s->budget--) { s->failed_pc=0x0c069dd0u; return 0; }
r[3]=0x00000064u;
goto P_0c069dd2;
P_0c069dd2: /* original 0237, guest PC 0x0c069dd2 */
if(!s->budget--) { s->failed_pc=0x0c069dd2u; return 0; }
r[19]=r[2]*r[3];
goto P_0c069dd4;
P_0c069dd4: /* original 031a, guest PC 0x0c069dd4 */
if(!s->budget--) { s->failed_pc=0x0c069dd4u; return 0; }
r[3]=r[19];
goto P_0c069dd6;
P_0c069dd6: /* original 6133, guest PC 0x0c069dd6 */
if(!s->budget--) { s->failed_pc=0x0c069dd6u; return 0; }
r[1]=r[3];
goto P_0c069dd8;
P_0c069dd8: /* original 1f31, guest PC 0x0c069dd8 */
if(!s->budget--) { s->failed_pc=0x0c069dd8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c069dda;
P_0c069dda: /* original d222, guest PC 0x0c069dda */
if(!s->budget--) { s->failed_pc=0x0c069ddau; return 0; }
r[2]=read(ram,0x0c069e64u,4);
goto P_0c069ddc;
P_0c069ddc: /* original 420b, guest PC 0x0c069ddc */
if(!s->budget--) { s->failed_pc=0x0c069ddcu; return 0; }
target=r[2];
r[16]=code_base|0x0c069de0u;
r[0]=read(ram,r[15]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069de0u) { target=s->pc; goto dispatch; }
goto P_0c069de0;
P_0c069dde: /* original 50fa, guest PC 0x0c069dde */
if(!s->budget--) { s->failed_pc=0x0c069ddeu; return 0; }
r[0]=read(ram,r[15]+40,4);
goto P_0c069de0;
P_0c069de0: /* original 6503, guest PC 0x0c069de0 */
if(!s->budget--) { s->failed_pc=0x0c069de0u; return 0; }
r[5]=r[0];
goto P_0c069de2;
P_0c069de2: /* original 1f01, guest PC 0x0c069de2 */
if(!s->budget--) { s->failed_pc=0x0c069de2u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c069de4;
P_0c069de4: /* original e074, guest PC 0x0c069de4 */
if(!s->budget--) { s->failed_pc=0x0c069de4u; return 0; }
r[0]=0x00000074u;
goto P_0c069de6;
P_0c069de6: /* original 4c0b, guest PC 0x0c069de6 */
if(!s->budget--) { s->failed_pc=0x0c069de6u; return 0; }
target=r[12];
r[16]=code_base|0x0c069deau;
r[4]=read(ram,r[15]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069deau) { target=s->pc; goto dispatch; }
goto P_0c069dea;
P_0c069de8: /* original 04fe, guest PC 0x0c069de8 */
if(!s->budget--) { s->failed_pc=0x0c069de8u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c069dea;
P_0c069dea: /* original 4b0b, guest PC 0x0c069dea */
if(!s->budget--) { s->failed_pc=0x0c069deau; return 0; }
target=r[11];
r[16]=code_base|0x0c069deeu;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069deeu) { target=s->pc; goto dispatch; }
goto P_0c069dee;
P_0c069dec: /* original 54f4, guest PC 0x0c069dec */
if(!s->budget--) { s->failed_pc=0x0c069decu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c069dee;
P_0c069dee: /* original 62f3, guest PC 0x0c069dee */
if(!s->budget--) { s->failed_pc=0x0c069deeu; return 0; }
r[2]=r[15];
goto P_0c069df0;
P_0c069df0: /* original 7270, guest PC 0x0c069df0 */
if(!s->budget--) { s->failed_pc=0x0c069df0u; return 0; }
r[2]+=0x00000070u;
goto P_0c069df2;
P_0c069df2: /* original 1f01, guest PC 0x0c069df2 */
if(!s->budget--) { s->failed_pc=0x0c069df2u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c069df4;
P_0c069df4: /* original 6322, guest PC 0x0c069df4 */
if(!s->budget--) { s->failed_pc=0x0c069df4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c069df6;
P_0c069df6: /* original 303c, guest PC 0x0c069df6 */
if(!s->budget--) { s->failed_pc=0x0c069df6u; return 0; }
r[0]+=r[3];
goto P_0c069df8;
P_0c069df8: /* original 6503, guest PC 0x0c069df8 */
if(!s->budget--) { s->failed_pc=0x0c069df8u; return 0; }
r[5]=r[0];
goto P_0c069dfa;
P_0c069dfa: /* original 1f01, guest PC 0x0c069dfa */
if(!s->budget--) { s->failed_pc=0x0c069dfau; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c069dfc;
P_0c069dfc: /* original 4c0b, guest PC 0x0c069dfc */
if(!s->budget--) { s->failed_pc=0x0c069dfcu; return 0; }
target=r[12];
r[16]=code_base|0x0c069e00u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069e00u) { target=s->pc; goto dispatch; }
goto P_0c069e00;
P_0c069dfe: /* original 54f4, guest PC 0x0c069dfe */
if(!s->budget--) { s->failed_pc=0x0c069dfeu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c069e00;
P_0c069e00: /* original d318, guest PC 0x0c069e00 */
if(!s->budget--) { s->failed_pc=0x0c069e00u; return 0; }
r[3]=read(ram,0x0c069e64u,4);
goto P_0c069e02;
P_0c069e02: /* original 51f1, guest PC 0x0c069e02 */
if(!s->budget--) { s->failed_pc=0x0c069e02u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c069e04;
P_0c069e04: /* original 430b, guest PC 0x0c069e04 */
if(!s->budget--) { s->failed_pc=0x0c069e04u; return 0; }
target=r[3];
r[16]=code_base|0x0c069e08u;
r[0]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069e08u) { target=s->pc; goto dispatch; }
goto P_0c069e08;
P_0c069e06: /* original 50f2, guest PC 0x0c069e06 */
if(!s->budget--) { s->failed_pc=0x0c069e06u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c069e08;
P_0c069e08: /* original 6503, guest PC 0x0c069e08 */
if(!s->budget--) { s->failed_pc=0x0c069e08u; return 0; }
r[5]=r[0];
goto P_0c069e0a;
P_0c069e0a: /* original 1f01, guest PC 0x0c069e0a */
if(!s->budget--) { s->failed_pc=0x0c069e0au; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c069e0c;
P_0c069e0c: /* original e068, guest PC 0x0c069e0c */
if(!s->budget--) { s->failed_pc=0x0c069e0cu; return 0; }
r[0]=0x00000068u;
goto P_0c069e0e;
P_0c069e0e: /* original 4c0b, guest PC 0x0c069e0e */
if(!s->budget--) { s->failed_pc=0x0c069e0eu; return 0; }
target=r[12];
r[16]=code_base|0x0c069e12u;
r[4]=read(ram,r[15]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069e12u) { target=s->pc; goto dispatch; }
goto P_0c069e12;
P_0c069e10: /* original 04fe, guest PC 0x0c069e10 */
if(!s->budget--) { s->failed_pc=0x0c069e10u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c069e12;
P_0c069e12: /* original e064, guest PC 0x0c069e12 */
if(!s->budget--) { s->failed_pc=0x0c069e12u; return 0; }
r[0]=0x00000064u;
goto P_0c069e14;
P_0c069e14: /* original 52f3, guest PC 0x0c069e14 */
if(!s->budget--) { s->failed_pc=0x0c069e14u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c069e16;
P_0c069e16: /* original 03fe, guest PC 0x0c069e16 */
if(!s->budget--) { s->failed_pc=0x0c069e16u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c069e18;
P_0c069e18: /* original e050, guest PC 0x0c069e18 */
if(!s->budget--) { s->failed_pc=0x0c069e18u; return 0; }
r[0]=0x00000050u;
goto P_0c069e1a;
P_0c069e1a: /* original 2322, guest PC 0x0c069e1a */
if(!s->budget--) { s->failed_pc=0x0c069e1au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c069e1c;
P_0c069e1c: /* original 52f3, guest PC 0x0c069e1c */
if(!s->budget--) { s->failed_pc=0x0c069e1cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c069e1e;
P_0c069e1e: /* original 03fe, guest PC 0x0c069e1e */
if(!s->budget--) { s->failed_pc=0x0c069e1eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c069e20;
P_0c069e20: /* original e044, guest PC 0x0c069e20 */
if(!s->budget--) { s->failed_pc=0x0c069e20u; return 0; }
r[0]=0x00000044u;
goto P_0c069e22;
P_0c069e22: /* original 2322, guest PC 0x0c069e22 */
if(!s->budget--) { s->failed_pc=0x0c069e22u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c069e24;
P_0c069e24: /* original 52f3, guest PC 0x0c069e24 */
if(!s->budget--) { s->failed_pc=0x0c069e24u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c069e26;
P_0c069e26: /* original 03fe, guest PC 0x0c069e26 */
if(!s->budget--) { s->failed_pc=0x0c069e26u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c069e28;
P_0c069e28: /* original 2322, guest PC 0x0c069e28 */
if(!s->budget--) { s->failed_pc=0x0c069e28u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c069e2a;
P_0c069e2a: /* original 53fb, guest PC 0x0c069e2a */
if(!s->budget--) { s->failed_pc=0x0c069e2au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c069e2c;
P_0c069e2c: /* original 7301, guest PC 0x0c069e2c */
if(!s->budget--) { s->failed_pc=0x0c069e2cu; return 0; }
r[3]+=0x00000001u;
goto P_0c069e2e;
P_0c069e2e: /* original 1f3b, guest PC 0x0c069e2e */
if(!s->budget--) { s->failed_pc=0x0c069e2eu; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c069e30;
P_0c069e30: /* original 52fc, guest PC 0x0c069e30 */
if(!s->budget--) { s->failed_pc=0x0c069e30u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c069e32;
P_0c069e32: /* original 72ff, guest PC 0x0c069e32 */
if(!s->budget--) { s->failed_pc=0x0c069e32u; return 0; }
r[2]+=0xffffffffu;
goto P_0c069e34;
P_0c069e34: /* original 2228, guest PC 0x0c069e34 */
if(!s->budget--) { s->failed_pc=0x0c069e34u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c069e36;
P_0c069e36: /* original 8f92, guest PC 0x0c069e36 */
if(!s->budget--) { s->failed_pc=0x0c069e36u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+48,r[2],4);
if(!cond) { goto P_0c069d5e; }
goto P_0c069e3a;
P_0c069e38: /* original 1f2c, guest PC 0x0c069e38 */
if(!s->budget--) { s->failed_pc=0x0c069e38u; return 0; }
write(ram,r[15]+48,r[2],4);
goto P_0c069e3a;
P_0c069e3a: /* original 54d2, guest PC 0x0c069e3a */
if(!s->budget--) { s->failed_pc=0x0c069e3au; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c069e3c;
P_0c069e3c: /* original e304, guest PC 0x0c069e3c */
if(!s->budget--) { s->failed_pc=0x0c069e3cu; return 0; }
r[3]=0x00000004u;
goto P_0c069e3e;
P_0c069e3e: /* original 2438, guest PC 0x0c069e3e */
if(!s->budget--) { s->failed_pc=0x0c069e3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c069e40;
P_0c069e40: /* original 8b19, guest PC 0x0c069e40 */
if(!s->budget--) { s->failed_pc=0x0c069e40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069e76; }
goto P_0c069e42;
P_0c069e42: /* original e078, guest PC 0x0c069e42 */
if(!s->budget--) { s->failed_pc=0x0c069e42u; return 0; }
r[0]=0x00000078u;
goto P_0c069e44;
P_0c069e44: /* original 63f2, guest PC 0x0c069e44 */
if(!s->budget--) { s->failed_pc=0x0c069e44u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c069e46;
P_0c069e46: /* original 08fe, guest PC 0x0c069e46 */
if(!s->budget--) { s->failed_pc=0x0c069e46u; return 0; }
r[8]=read(ram,r[15]+r[0],4);
goto P_0c069e48;
P_0c069e48: /* original e061, guest PC 0x0c069e48 */
if(!s->budget--) { s->failed_pc=0x0c069e48u; return 0; }
r[0]=0x00000061u;
goto P_0c069e4a;
P_0c069e4a: /* original 2338, guest PC 0x0c069e4a */
if(!s->budget--) { s->failed_pc=0x0c069e4au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c069e4c;
P_0c069e4c: /* original 088c, guest PC 0x0c069e4c */
if(!s->budget--) { s->failed_pc=0x0c069e4cu; return 0; }
r[8]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c069e4e;
P_0c069e4e: /* original 8f0b, guest PC 0x0c069e4e */
if(!s->budget--) { s->failed_pc=0x0c069e4eu; return 0; }
cond=r[17]&1u;
r[8]=r[8]&255u;
if(!cond) { goto P_0c069e68; }
goto P_0c069e52;
P_0c069e50: /* original 688c, guest PC 0x0c069e50 */
if(!s->budget--) { s->failed_pc=0x0c069e50u; return 0; }
r[8]=r[8]&255u;
goto P_0c069e52;
P_0c069e52: /* original 52f9, guest PC 0x0c069e52 */
if(!s->budget--) { s->failed_pc=0x0c069e52u; return 0; }
r[2]=read(ram,r[15]+36,4);
goto P_0c069e54;
P_0c069e54: /* original 2228, guest PC 0x0c069e54 */
if(!s->budget--) { s->failed_pc=0x0c069e54u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c069e56;
P_0c069e56: /* original 890e, guest PC 0x0c069e56 */
if(!s->budget--) { s->failed_pc=0x0c069e56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069e76; }
goto P_0c069e58;
P_0c069e58: /* original a009, guest PC 0x0c069e58 */
if(!s->budget--) { s->failed_pc=0x0c069e58u; return 0; }
goto P_0c069e6e;
P_0c069e5a: /* original 0009, guest PC 0x0c069e5a */
if(!s->budget--) { s->failed_pc=0x0c069e5au; return 0; }
if(!vf3_matrix_family(0x0c069e5cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069e5cu; return 0; } return 1;
P_0c069e68: /* original 52f9, guest PC 0x0c069e68 */
if(!s->budget--) { s->failed_pc=0x0c069e68u; return 0; }
r[2]=read(ram,r[15]+36,4);
goto P_0c069e6a;
P_0c069e6a: /* original 2228, guest PC 0x0c069e6a */
if(!s->budget--) { s->failed_pc=0x0c069e6au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c069e6c;
P_0c069e6c: /* original 8b03, guest PC 0x0c069e6c */
if(!s->budget--) { s->failed_pc=0x0c069e6cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069e76; }
goto P_0c069e6e;
P_0c069e6e: /* original 58f6, guest PC 0x0c069e6e */
if(!s->budget--) { s->failed_pc=0x0c069e6eu; return 0; }
r[8]=read(ram,r[15]+24,4);
goto P_0c069e70;
P_0c069e70: /* original e061, guest PC 0x0c069e70 */
if(!s->budget--) { s->failed_pc=0x0c069e70u; return 0; }
r[0]=0x00000061u;
goto P_0c069e72;
P_0c069e72: /* original 088c, guest PC 0x0c069e72 */
if(!s->budget--) { s->failed_pc=0x0c069e72u; return 0; }
r[8]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c069e74;
P_0c069e74: /* original 688c, guest PC 0x0c069e74 */
if(!s->budget--) { s->failed_pc=0x0c069e74u; return 0; }
r[8]=r[8]&255u;
goto P_0c069e76;
P_0c069e76: /* original 9090, guest PC 0x0c069e76 */
if(!s->budget--) { s->failed_pc=0x0c069e76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069f9au,2);
goto P_0c069e78;
P_0c069e78: /* original 0da6, guest PC 0x0c069e78 */
if(!s->budget--) { s->failed_pc=0x0c069e78u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c069e7a;
P_0c069e7a: /* original 7008, guest PC 0x0c069e7a */
if(!s->budget--) { s->failed_pc=0x0c069e7au; return 0; }
r[0]+=0x00000008u;
goto P_0c069e7c;
P_0c069e7c: /* original 0da6, guest PC 0x0c069e7c */
if(!s->budget--) { s->failed_pc=0x0c069e7cu; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c069e7e;
P_0c069e7e: /* original 7004, guest PC 0x0c069e7e */
if(!s->budget--) { s->failed_pc=0x0c069e7eu; return 0; }
r[0]+=0x00000004u;
goto P_0c069e80;
P_0c069e80: /* original 0da6, guest PC 0x0c069e80 */
if(!s->budget--) { s->failed_pc=0x0c069e80u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c069e82;
P_0c069e82: /* original 7004, guest PC 0x0c069e82 */
if(!s->budget--) { s->failed_pc=0x0c069e82u; return 0; }
r[0]+=0x00000004u;
goto P_0c069e84;
P_0c069e84: /* original 0da6, guest PC 0x0c069e84 */
if(!s->budget--) { s->failed_pc=0x0c069e84u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c069e86;
P_0c069e86: /* original 7004, guest PC 0x0c069e86 */
if(!s->budget--) { s->failed_pc=0x0c069e86u; return 0; }
r[0]+=0x00000004u;
goto P_0c069e88;
P_0c069e88: /* original 0da6, guest PC 0x0c069e88 */
if(!s->budget--) { s->failed_pc=0x0c069e88u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c069e8a;
P_0c069e8a: /* original 7004, guest PC 0x0c069e8a */
if(!s->budget--) { s->failed_pc=0x0c069e8au; return 0; }
r[0]+=0x00000004u;
goto P_0c069e8c;
P_0c069e8c: /* original 0da6, guest PC 0x0c069e8c */
if(!s->budget--) { s->failed_pc=0x0c069e8cu; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c069e8e;
P_0c069e8e: /* original 7004, guest PC 0x0c069e8e */
if(!s->budget--) { s->failed_pc=0x0c069e8eu; return 0; }
r[0]+=0x00000004u;
goto P_0c069e90;
P_0c069e90: /* original 0da6, guest PC 0x0c069e90 */
if(!s->budget--) { s->failed_pc=0x0c069e90u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c069e92;
P_0c069e92: /* original 9083, guest PC 0x0c069e92 */
if(!s->budget--) { s->failed_pc=0x0c069e92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069f9cu,2);
goto P_0c069e94;
P_0c069e94: /* original 2888, guest PC 0x0c069e94 */
if(!s->budget--) { s->failed_pc=0x0c069e94u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c069e96;
P_0c069e96: /* original 0429, guest PC 0x0c069e96 */
if(!s->budget--) { s->failed_pc=0x0c069e96u; return 0; }
r[4]=r[17]&1u;
goto P_0c069e98;
P_0c069e98: /* original 03de, guest PC 0x0c069e98 */
if(!s->budget--) { s->failed_pc=0x0c069e98u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069e9a;
P_0c069e9a: /* original 7301, guest PC 0x0c069e9a */
if(!s->budget--) { s->failed_pc=0x0c069e9au; return 0; }
r[3]+=0x00000001u;
goto P_0c069e9c;
P_0c069e9c: /* original 0d36, guest PC 0x0c069e9c */
if(!s->budget--) { s->failed_pc=0x0c069e9cu; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c069e9e;
P_0c069e9e: /* original 52fe, guest PC 0x0c069e9e */
if(!s->budget--) { s->failed_pc=0x0c069e9eu; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c069ea0;
P_0c069ea0: /* original 2228, guest PC 0x0c069ea0 */
if(!s->budget--) { s->failed_pc=0x0c069ea0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c069ea2;
P_0c069ea2: /* original 8d04, guest PC 0x0c069ea2 */
if(!s->budget--) { s->failed_pc=0x0c069ea2u; return 0; }
cond=r[17]&1u;
r[8]=0x00000001u;
if(cond) { goto P_0c069eae; }
goto P_0c069ea6;
P_0c069ea4: /* original e801, guest PC 0x0c069ea4 */
if(!s->budget--) { s->failed_pc=0x0c069ea4u; return 0; }
r[8]=0x00000001u;
goto P_0c069ea6;
P_0c069ea6: /* original 907a, guest PC 0x0c069ea6 */
if(!s->budget--) { s->failed_pc=0x0c069ea6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069f9eu,2);
goto P_0c069ea8;
P_0c069ea8: /* original 03de, guest PC 0x0c069ea8 */
if(!s->budget--) { s->failed_pc=0x0c069ea8u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069eaa;
P_0c069eaa: /* original 7301, guest PC 0x0c069eaa */
if(!s->budget--) { s->failed_pc=0x0c069eaau; return 0; }
r[3]+=0x00000001u;
goto P_0c069eac;
P_0c069eac: /* original 0d36, guest PC 0x0c069eac */
if(!s->budget--) { s->failed_pc=0x0c069eacu; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c069eae;
P_0c069eae: /* original 52ff, guest PC 0x0c069eae */
if(!s->budget--) { s->failed_pc=0x0c069eaeu; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c069eb0;
P_0c069eb0: /* original 2228, guest PC 0x0c069eb0 */
if(!s->budget--) { s->failed_pc=0x0c069eb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c069eb2;
P_0c069eb2: /* original 890e, guest PC 0x0c069eb2 */
if(!s->budget--) { s->failed_pc=0x0c069eb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069ed2; }
goto P_0c069eb4;
P_0c069eb4: /* original 9074, guest PC 0x0c069eb4 */
if(!s->budget--) { s->failed_pc=0x0c069eb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069fa0u,2);
goto P_0c069eb6;
P_0c069eb6: /* original 2448, guest PC 0x0c069eb6 */
if(!s->budget--) { s->failed_pc=0x0c069eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c069eb8;
P_0c069eb8: /* original 03de, guest PC 0x0c069eb8 */
if(!s->budget--) { s->failed_pc=0x0c069eb8u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069eba;
P_0c069eba: /* original 7301, guest PC 0x0c069eba */
if(!s->budget--) { s->failed_pc=0x0c069ebau; return 0; }
r[3]+=0x00000001u;
goto P_0c069ebc;
P_0c069ebc: /* original 0d36, guest PC 0x0c069ebc */
if(!s->budget--) { s->failed_pc=0x0c069ebcu; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c069ebe;
P_0c069ebe: /* original 8f01, guest PC 0x0c069ebe */
if(!s->budget--) { s->failed_pc=0x0c069ebeu; return 0; }
cond=r[17]&1u;
r[5]=r[10];
if(!cond) { goto P_0c069ec4; }
goto P_0c069ec2;
P_0c069ec0: /* original 65a3, guest PC 0x0c069ec0 */
if(!s->budget--) { s->failed_pc=0x0c069ec0u; return 0; }
r[5]=r[10];
goto P_0c069ec2;
P_0c069ec2: /* original 6583, guest PC 0x0c069ec2 */
if(!s->budget--) { s->failed_pc=0x0c069ec2u; return 0; }
r[5]=r[8];
goto P_0c069ec4;
P_0c069ec4: /* original 936d, guest PC 0x0c069ec4 */
if(!s->budget--) { s->failed_pc=0x0c069ec4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069fa2u,2);
goto P_0c069ec6;
P_0c069ec6: /* original 4508, guest PC 0x0c069ec6 */
if(!s->budget--) { s->failed_pc=0x0c069ec6u; return 0; }
r[5]<<=2;
goto P_0c069ec8;
P_0c069ec8: /* original 33dc, guest PC 0x0c069ec8 */
if(!s->budget--) { s->failed_pc=0x0c069ec8u; return 0; }
r[3]+=r[13];
goto P_0c069eca;
P_0c069eca: /* original 353c, guest PC 0x0c069eca */
if(!s->budget--) { s->failed_pc=0x0c069ecau; return 0; }
r[5]+=r[3];
goto P_0c069ecc;
P_0c069ecc: /* original 6252, guest PC 0x0c069ecc */
if(!s->budget--) { s->failed_pc=0x0c069eccu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c069ece;
P_0c069ece: /* original 7201, guest PC 0x0c069ece */
if(!s->budget--) { s->failed_pc=0x0c069eceu; return 0; }
r[2]+=0x00000001u;
goto P_0c069ed0;
P_0c069ed0: /* original 2522, guest PC 0x0c069ed0 */
if(!s->budget--) { s->failed_pc=0x0c069ed0u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c069ed2;
P_0c069ed2: /* original e040, guest PC 0x0c069ed2 */
if(!s->budget--) { s->failed_pc=0x0c069ed2u; return 0; }
r[0]=0x00000040u;
goto P_0c069ed4;
P_0c069ed4: /* original 03fe, guest PC 0x0c069ed4 */
if(!s->budget--) { s->failed_pc=0x0c069ed4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c069ed6;
P_0c069ed6: /* original 2338, guest PC 0x0c069ed6 */
if(!s->budget--) { s->failed_pc=0x0c069ed6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c069ed8;
P_0c069ed8: /* original 890e, guest PC 0x0c069ed8 */
if(!s->budget--) { s->failed_pc=0x0c069ed8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069ef8; }
goto P_0c069eda;
P_0c069eda: /* original 9063, guest PC 0x0c069eda */
if(!s->budget--) { s->failed_pc=0x0c069edau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069fa4u,2);
goto P_0c069edc;
P_0c069edc: /* original 2448, guest PC 0x0c069edc */
if(!s->budget--) { s->failed_pc=0x0c069edcu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c069ede;
P_0c069ede: /* original 03de, guest PC 0x0c069ede */
if(!s->budget--) { s->failed_pc=0x0c069edeu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069ee0;
P_0c069ee0: /* original 7301, guest PC 0x0c069ee0 */
if(!s->budget--) { s->failed_pc=0x0c069ee0u; return 0; }
r[3]+=0x00000001u;
goto P_0c069ee2;
P_0c069ee2: /* original 0d36, guest PC 0x0c069ee2 */
if(!s->budget--) { s->failed_pc=0x0c069ee2u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c069ee4;
P_0c069ee4: /* original 8f01, guest PC 0x0c069ee4 */
if(!s->budget--) { s->failed_pc=0x0c069ee4u; return 0; }
cond=r[17]&1u;
r[5]=r[10];
if(!cond) { goto P_0c069eea; }
goto P_0c069ee8;
P_0c069ee6: /* original 65a3, guest PC 0x0c069ee6 */
if(!s->budget--) { s->failed_pc=0x0c069ee6u; return 0; }
r[5]=r[10];
goto P_0c069ee8;
P_0c069ee8: /* original 6583, guest PC 0x0c069ee8 */
if(!s->budget--) { s->failed_pc=0x0c069ee8u; return 0; }
r[5]=r[8];
goto P_0c069eea;
P_0c069eea: /* original 935c, guest PC 0x0c069eea */
if(!s->budget--) { s->failed_pc=0x0c069eeau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069fa6u,2);
goto P_0c069eec;
P_0c069eec: /* original 4508, guest PC 0x0c069eec */
if(!s->budget--) { s->failed_pc=0x0c069eecu; return 0; }
r[5]<<=2;
goto P_0c069eee;
P_0c069eee: /* original 33dc, guest PC 0x0c069eee */
if(!s->budget--) { s->failed_pc=0x0c069eeeu; return 0; }
r[3]+=r[13];
goto P_0c069ef0;
P_0c069ef0: /* original 353c, guest PC 0x0c069ef0 */
if(!s->budget--) { s->failed_pc=0x0c069ef0u; return 0; }
r[5]+=r[3];
goto P_0c069ef2;
P_0c069ef2: /* original 6252, guest PC 0x0c069ef2 */
if(!s->budget--) { s->failed_pc=0x0c069ef2u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c069ef4;
P_0c069ef4: /* original 7201, guest PC 0x0c069ef4 */
if(!s->budget--) { s->failed_pc=0x0c069ef4u; return 0; }
r[2]+=0x00000001u;
goto P_0c069ef6;
P_0c069ef6: /* original 2522, guest PC 0x0c069ef6 */
if(!s->budget--) { s->failed_pc=0x0c069ef6u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c069ef8;
P_0c069ef8: /* original 53f7, guest PC 0x0c069ef8 */
if(!s->budget--) { s->failed_pc=0x0c069ef8u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c069efa;
P_0c069efa: /* original 2338, guest PC 0x0c069efa */
if(!s->budget--) { s->failed_pc=0x0c069efau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c069efc;
P_0c069efc: /* original 890e, guest PC 0x0c069efc */
if(!s->budget--) { s->failed_pc=0x0c069efcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069f1c; }
goto P_0c069efe;
P_0c069efe: /* original 9053, guest PC 0x0c069efe */
if(!s->budget--) { s->failed_pc=0x0c069efeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069fa8u,2);
goto P_0c069f00;
P_0c069f00: /* original 2448, guest PC 0x0c069f00 */
if(!s->budget--) { s->failed_pc=0x0c069f00u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c069f02;
P_0c069f02: /* original 03de, guest PC 0x0c069f02 */
if(!s->budget--) { s->failed_pc=0x0c069f02u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069f04;
P_0c069f04: /* original 7301, guest PC 0x0c069f04 */
if(!s->budget--) { s->failed_pc=0x0c069f04u; return 0; }
r[3]+=0x00000001u;
goto P_0c069f06;
P_0c069f06: /* original 0d36, guest PC 0x0c069f06 */
if(!s->budget--) { s->failed_pc=0x0c069f06u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c069f08;
P_0c069f08: /* original 8f01, guest PC 0x0c069f08 */
if(!s->budget--) { s->failed_pc=0x0c069f08u; return 0; }
cond=r[17]&1u;
r[5]=r[10];
if(!cond) { goto P_0c069f0e; }
goto P_0c069f0c;
P_0c069f0a: /* original 65a3, guest PC 0x0c069f0a */
if(!s->budget--) { s->failed_pc=0x0c069f0au; return 0; }
r[5]=r[10];
goto P_0c069f0c;
P_0c069f0c: /* original 6583, guest PC 0x0c069f0c */
if(!s->budget--) { s->failed_pc=0x0c069f0cu; return 0; }
r[5]=r[8];
goto P_0c069f0e;
P_0c069f0e: /* original 934c, guest PC 0x0c069f0e */
if(!s->budget--) { s->failed_pc=0x0c069f0eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069faau,2);
goto P_0c069f10;
P_0c069f10: /* original 4508, guest PC 0x0c069f10 */
if(!s->budget--) { s->failed_pc=0x0c069f10u; return 0; }
r[5]<<=2;
goto P_0c069f12;
P_0c069f12: /* original 33dc, guest PC 0x0c069f12 */
if(!s->budget--) { s->failed_pc=0x0c069f12u; return 0; }
r[3]+=r[13];
goto P_0c069f14;
P_0c069f14: /* original 353c, guest PC 0x0c069f14 */
if(!s->budget--) { s->failed_pc=0x0c069f14u; return 0; }
r[5]+=r[3];
goto P_0c069f16;
P_0c069f16: /* original 6252, guest PC 0x0c069f16 */
if(!s->budget--) { s->failed_pc=0x0c069f16u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c069f18;
P_0c069f18: /* original 7201, guest PC 0x0c069f18 */
if(!s->budget--) { s->failed_pc=0x0c069f18u; return 0; }
r[2]+=0x00000001u;
goto P_0c069f1a;
P_0c069f1a: /* original 2522, guest PC 0x0c069f1a */
if(!s->budget--) { s->failed_pc=0x0c069f1au; return 0; }
write(ram,r[5],r[2],4);
goto P_0c069f1c;
P_0c069f1c: /* original 51f5, guest PC 0x0c069f1c */
if(!s->budget--) { s->failed_pc=0x0c069f1cu; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c069f1e;
P_0c069f1e: /* original d324, guest PC 0x0c069f1e */
if(!s->budget--) { s->failed_pc=0x0c069f1eu; return 0; }
r[3]=read(ram,0x0c069fb0u,4);
goto P_0c069f20;
P_0c069f20: /* original 2138, guest PC 0x0c069f20 */
if(!s->budget--) { s->failed_pc=0x0c069f20u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c069f22;
P_0c069f22: /* original 8b01, guest PC 0x0c069f22 */
if(!s->budget--) { s->failed_pc=0x0c069f22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069f28; }
goto P_0c069f24;
P_0c069f24: /* original a1fb, guest PC 0x0c069f24 */
if(!s->budget--) { s->failed_pc=0x0c069f24u; return 0; }
goto P_0c06a31e;
P_0c069f26: /* original 0009, guest PC 0x0c069f26 */
if(!s->budget--) { s->failed_pc=0x0c069f26u; return 0; }
goto P_0c069f28;
P_0c069f28: /* original 64e3, guest PC 0x0c069f28 */
if(!s->budget--) { s->failed_pc=0x0c069f28u; return 0; }
r[4]=r[14];
goto P_0c069f2a;
P_0c069f2a: /* original 4b0b, guest PC 0x0c069f2a */
if(!s->budget--) { s->failed_pc=0x0c069f2au; return 0; }
target=r[11];
r[16]=code_base|0x0c069f2eu;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069f2eu) { target=s->pc; goto dispatch; }
goto P_0c069f2e;
P_0c069f2c: /* original 7424, guest PC 0x0c069f2c */
if(!s->budget--) { s->failed_pc=0x0c069f2cu; return 0; }
r[4]+=0x00000024u;
goto P_0c069f2e;
P_0c069f2e: /* original 2f02, guest PC 0x0c069f2e */
if(!s->budget--) { s->failed_pc=0x0c069f2eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c069f30;
P_0c069f30: /* original 903c, guest PC 0x0c069f30 */
if(!s->budget--) { s->failed_pc=0x0c069f30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069facu,2);
goto P_0c069f32;
P_0c069f32: /* original 03de, guest PC 0x0c069f32 */
if(!s->budget--) { s->failed_pc=0x0c069f32u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c069f34;
P_0c069f34: /* original 1f35, guest PC 0x0c069f34 */
if(!s->budget--) { s->failed_pc=0x0c069f34u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c069f36;
P_0c069f36: /* original 903a, guest PC 0x0c069f36 */
if(!s->budget--) { s->failed_pc=0x0c069f36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069faeu,2);
goto P_0c069f38;
P_0c069f38: /* original 02de, guest PC 0x0c069f38 */
if(!s->budget--) { s->failed_pc=0x0c069f38u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c069f3a;
P_0c069f3a: /* original 6323, guest PC 0x0c069f3a */
if(!s->budget--) { s->failed_pc=0x0c069f3au; return 0; }
r[3]=r[2];
goto P_0c069f3c;
P_0c069f3c: /* original 1f21, guest PC 0x0c069f3c */
if(!s->budget--) { s->failed_pc=0x0c069f3cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c069f3e;
P_0c069f3e: /* original 54f5, guest PC 0x0c069f3e */
if(!s->budget--) { s->failed_pc=0x0c069f3eu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c069f40;
P_0c069f40: /* original 62f2, guest PC 0x0c069f40 */
if(!s->budget--) { s->failed_pc=0x0c069f40u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c069f42;
P_0c069f42: /* original 343c, guest PC 0x0c069f42 */
if(!s->budget--) { s->failed_pc=0x0c069f42u; return 0; }
r[4]+=r[3];
goto P_0c069f44;
P_0c069f44: /* original 342c, guest PC 0x0c069f44 */
if(!s->budget--) { s->failed_pc=0x0c069f44u; return 0; }
r[4]+=r[2];
goto P_0c069f46;
P_0c069f46: /* original 6543, guest PC 0x0c069f46 */
if(!s->budget--) { s->failed_pc=0x0c069f46u; return 0; }
r[5]=r[4];
goto P_0c069f48;
P_0c069f48: /* original 2f42, guest PC 0x0c069f48 */
if(!s->budget--) { s->failed_pc=0x0c069f48u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c069f4a;
P_0c069f4a: /* original 64e3, guest PC 0x0c069f4a */
if(!s->budget--) { s->failed_pc=0x0c069f4au; return 0; }
r[4]=r[14];
goto P_0c069f4c;
P_0c069f4c: /* original 4c0b, guest PC 0x0c069f4c */
if(!s->budget--) { s->failed_pc=0x0c069f4cu; return 0; }
target=r[12];
r[16]=code_base|0x0c069f50u;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069f50u) { target=s->pc; goto dispatch; }
goto P_0c069f50;
P_0c069f4e: /* original 7424, guest PC 0x0c069f4e */
if(!s->budget--) { s->failed_pc=0x0c069f4eu; return 0; }
r[4]+=0x00000024u;
goto P_0c069f50;
P_0c069f50: /* original 55f5, guest PC 0x0c069f50 */
if(!s->budget--) { s->failed_pc=0x0c069f50u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c069f52;
P_0c069f52: /* original 64e3, guest PC 0x0c069f52 */
if(!s->budget--) { s->failed_pc=0x0c069f52u; return 0; }
r[4]=r[14];
goto P_0c069f54;
P_0c069f54: /* original bbb7, guest PC 0x0c069f54 */
if(!s->budget--) { s->failed_pc=0x0c069f54u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069f58u;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069f58u) { target=s->pc; goto dispatch; }
goto P_0c069f58;
P_0c069f56: /* original 742c, guest PC 0x0c069f56 */
if(!s->budget--) { s->failed_pc=0x0c069f56u; return 0; }
r[4]+=0x0000002cu;
goto P_0c069f58;
P_0c069f58: /* original 55f1, guest PC 0x0c069f58 */
if(!s->budget--) { s->failed_pc=0x0c069f58u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c069f5a;
P_0c069f5a: /* original 64e3, guest PC 0x0c069f5a */
if(!s->budget--) { s->failed_pc=0x0c069f5au; return 0; }
r[4]=r[14];
goto P_0c069f5c;
P_0c069f5c: /* original bbb3, guest PC 0x0c069f5c */
if(!s->budget--) { s->failed_pc=0x0c069f5cu; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069f60u;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069f60u) { target=s->pc; goto dispatch; }
goto P_0c069f60;
P_0c069f5e: /* original 7430, guest PC 0x0c069f5e */
if(!s->budget--) { s->failed_pc=0x0c069f5eu; return 0; }
r[4]+=0x00000030u;
goto P_0c069f60;
P_0c069f60: /* original 64e3, guest PC 0x0c069f60 */
if(!s->budget--) { s->failed_pc=0x0c069f60u; return 0; }
r[4]=r[14];
goto P_0c069f62;
P_0c069f62: /* original 4b0b, guest PC 0x0c069f62 */
if(!s->budget--) { s->failed_pc=0x0c069f62u; return 0; }
target=r[11];
r[16]=code_base|0x0c069f66u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069f66u) { target=s->pc; goto dispatch; }
goto P_0c069f66;
P_0c069f64: /* original 741c, guest PC 0x0c069f64 */
if(!s->budget--) { s->failed_pc=0x0c069f64u; return 0; }
r[4]+=0x0000001cu;
goto P_0c069f66;
P_0c069f66: /* original 64e3, guest PC 0x0c069f66 */
if(!s->budget--) { s->failed_pc=0x0c069f66u; return 0; }
r[4]=r[14];
goto P_0c069f68;
P_0c069f68: /* original 2f02, guest PC 0x0c069f68 */
if(!s->budget--) { s->failed_pc=0x0c069f68u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c069f6a;
P_0c069f6a: /* original 4b0b, guest PC 0x0c069f6a */
if(!s->budget--) { s->failed_pc=0x0c069f6au; return 0; }
target=r[11];
r[16]=code_base|0x0c069f6eu;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069f6eu) { target=s->pc; goto dispatch; }
goto P_0c069f6e;
P_0c069f6c: /* original 7434, guest PC 0x0c069f6c */
if(!s->budget--) { s->failed_pc=0x0c069f6cu; return 0; }
r[4]+=0x00000034u;
goto P_0c069f6e;
P_0c069f6e: /* original 63f2, guest PC 0x0c069f6e */
if(!s->budget--) { s->failed_pc=0x0c069f6eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c069f70;
P_0c069f70: /* original 6403, guest PC 0x0c069f70 */
if(!s->budget--) { s->failed_pc=0x0c069f70u; return 0; }
r[4]=r[0];
goto P_0c069f72;
P_0c069f72: /* original 3348, guest PC 0x0c069f72 */
if(!s->budget--) { s->failed_pc=0x0c069f72u; return 0; }
r[3]-=r[4];
goto P_0c069f74;
P_0c069f74: /* original 64e3, guest PC 0x0c069f74 */
if(!s->budget--) { s->failed_pc=0x0c069f74u; return 0; }
r[4]=r[14];
goto P_0c069f76;
P_0c069f76: /* original 2f32, guest PC 0x0c069f76 */
if(!s->budget--) { s->failed_pc=0x0c069f76u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c069f78;
P_0c069f78: /* original 4b0b, guest PC 0x0c069f78 */
if(!s->budget--) { s->failed_pc=0x0c069f78u; return 0; }
target=r[11];
r[16]=code_base|0x0c069f7cu;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069f7cu) { target=s->pc; goto dispatch; }
goto P_0c069f7c;
P_0c069f7a: /* original 7424, guest PC 0x0c069f7a */
if(!s->budget--) { s->failed_pc=0x0c069f7au; return 0; }
r[4]+=0x00000024u;
goto P_0c069f7c;
P_0c069f7c: /* original 63f2, guest PC 0x0c069f7c */
if(!s->budget--) { s->failed_pc=0x0c069f7cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c069f7e;
P_0c069f7e: /* original 6403, guest PC 0x0c069f7e */
if(!s->budget--) { s->failed_pc=0x0c069f7eu; return 0; }
r[4]=r[0];
goto P_0c069f80;
P_0c069f80: /* original f28d, guest PC 0x0c069f80 */
if(!s->budget--) { s->failed_pc=0x0c069f80u; return 0; }
fr[2]=0;
goto P_0c069f82;
P_0c069f82: /* original c70c, guest PC 0x0c069f82 */
if(!s->budget--) { s->failed_pc=0x0c069f82u; return 0; }
r[0]=code_base|0x00069fb4u;
goto P_0c069f84;
P_0c069f84: /* original 435a, guest PC 0x0c069f84 */
if(!s->budget--) { s->failed_pc=0x0c069f84u; return 0; }
r[53]=r[3];
goto P_0c069f86;
P_0c069f86: /* original f508, guest PC 0x0c069f86 */
if(!s->budget--) { s->failed_pc=0x0c069f86u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c069f88;
P_0c069f88: /* original f32d, guest PC 0x0c069f88 */
if(!s->budget--) { s->failed_pc=0x0c069f88u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c069f8a;
P_0c069f8a: /* original f235, guest PC 0x0c069f8a */
if(!s->budget--) { s->failed_pc=0x0c069f8au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c069f8c;
P_0c069f8c: /* original 8f16, guest PC 0x0c069f8c */
if(!s->budget--) { s->failed_pc=0x0c069f8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c069fbc; }
goto P_0c069f90;
P_0c069f8e: /* original f43c, guest PC 0x0c069f8e */
if(!s->budget--) { s->failed_pc=0x0c069f8eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c069f90;
P_0c069f90: /* original c709, guest PC 0x0c069f90 */
if(!s->budget--) { s->failed_pc=0x0c069f90u; return 0; }
r[0]=code_base|0x00069fb8u;
goto P_0c069f92;
P_0c069f92: /* original f64c, guest PC 0x0c069f92 */
if(!s->budget--) { s->failed_pc=0x0c069f92u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c069f94;
P_0c069f94: /* original f308, guest PC 0x0c069f94 */
if(!s->budget--) { s->failed_pc=0x0c069f94u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069f96;
P_0c069f96: /* original a012, guest PC 0x0c069f96 */
if(!s->budget--) { s->failed_pc=0x0c069f96u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c069fbe;
P_0c069f98: /* original f630, guest PC 0x0c069f98 */
if(!s->budget--) { s->failed_pc=0x0c069f98u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
if(!vf3_matrix_family(0x0c069f9au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069f9au; return 0; } return 1;
P_0c069fbc: /* original f64c, guest PC 0x0c069fbc */
if(!s->budget--) { s->failed_pc=0x0c069fbcu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c069fbe;
P_0c069fbe: /* original 445a, guest PC 0x0c069fbe */
if(!s->budget--) { s->failed_pc=0x0c069fbeu; return 0; }
r[53]=r[4];
goto P_0c069fc0;
P_0c069fc0: /* original f28d, guest PC 0x0c069fc0 */
if(!s->budget--) { s->failed_pc=0x0c069fc0u; return 0; }
fr[2]=0;
goto P_0c069fc2;
P_0c069fc2: /* original f32d, guest PC 0x0c069fc2 */
if(!s->budget--) { s->failed_pc=0x0c069fc2u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c069fc4;
P_0c069fc4: /* original f235, guest PC 0x0c069fc4 */
if(!s->budget--) { s->failed_pc=0x0c069fc4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c069fc6;
P_0c069fc6: /* original 8f03, guest PC 0x0c069fc6 */
if(!s->budget--) { s->failed_pc=0x0c069fc6u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c069fd0; }
goto P_0c069fca;
P_0c069fc8: /* original f43c, guest PC 0x0c069fc8 */
if(!s->budget--) { s->failed_pc=0x0c069fc8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c069fca;
P_0c069fca: /* original c737, guest PC 0x0c069fca */
if(!s->budget--) { s->failed_pc=0x0c069fcau; return 0; }
r[0]=code_base|0x0006a0a8u;
goto P_0c069fcc;
P_0c069fcc: /* original f308, guest PC 0x0c069fcc */
if(!s->budget--) { s->failed_pc=0x0c069fccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069fce;
P_0c069fce: /* original f430, guest PC 0x0c069fce */
if(!s->budget--) { s->failed_pc=0x0c069fceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c069fd0;
P_0c069fd0: /* original f452, guest PC 0x0c069fd0 */
if(!s->budget--) { s->failed_pc=0x0c069fd0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c069fd2;
P_0c069fd2: /* original 64e3, guest PC 0x0c069fd2 */
if(!s->budget--) { s->failed_pc=0x0c069fd2u; return 0; }
r[4]=r[14];
goto P_0c069fd4;
P_0c069fd4: /* original f463, guest PC 0x0c069fd4 */
if(!s->budget--) { s->failed_pc=0x0c069fd4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c069fd6;
P_0c069fd6: /* original f43d, guest PC 0x0c069fd6 */
if(!s->budget--) { s->failed_pc=0x0c069fd6u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c069fd8;
P_0c069fd8: /* original 025a, guest PC 0x0c069fd8 */
if(!s->budget--) { s->failed_pc=0x0c069fd8u; return 0; }
r[2]=r[53];
goto P_0c069fda;
P_0c069fda: /* original 6523, guest PC 0x0c069fda */
if(!s->budget--) { s->failed_pc=0x0c069fdau; return 0; }
r[5]=r[2];
goto P_0c069fdc;
P_0c069fdc: /* original 2f22, guest PC 0x0c069fdc */
if(!s->budget--) { s->failed_pc=0x0c069fdcu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c069fde;
P_0c069fde: /* original 4c0b, guest PC 0x0c069fde */
if(!s->budget--) { s->failed_pc=0x0c069fdeu; return 0; }
target=r[12];
r[16]=code_base|0x0c069fe2u;
r[4]+=0x0000003cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069fe2u) { target=s->pc; goto dispatch; }
goto P_0c069fe2;
P_0c069fe0: /* original 743c, guest PC 0x0c069fe0 */
if(!s->budget--) { s->failed_pc=0x0c069fe0u; return 0; }
r[4]+=0x0000003cu;
goto P_0c069fe2;
P_0c069fe2: /* original 945d, guest PC 0x0c069fe2 */
if(!s->budget--) { s->failed_pc=0x0c069fe2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a0a0u,2);
goto P_0c069fe4;
P_0c069fe4: /* original 4b0b, guest PC 0x0c069fe4 */
if(!s->budget--) { s->failed_pc=0x0c069fe4u; return 0; }
target=r[11];
r[16]=code_base|0x0c069fe8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069fe8u) { target=s->pc; goto dispatch; }
goto P_0c069fe8;
P_0c069fe6: /* original 34ec, guest PC 0x0c069fe6 */
if(!s->budget--) { s->failed_pc=0x0c069fe6u; return 0; }
r[4]+=r[14];
goto P_0c069fe8;
P_0c069fe8: /* original 2f02, guest PC 0x0c069fe8 */
if(!s->budget--) { s->failed_pc=0x0c069fe8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c069fea;
P_0c069fea: /* original 62f2, guest PC 0x0c069fea */
if(!s->budget--) { s->failed_pc=0x0c069feau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c069fec;
P_0c069fec: /* original 53f5, guest PC 0x0c069fec */
if(!s->budget--) { s->failed_pc=0x0c069fecu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c069fee;
P_0c069fee: /* original 3238, guest PC 0x0c069fee */
if(!s->budget--) { s->failed_pc=0x0c069feeu; return 0; }
r[2]-=r[3];
goto P_0c069ff0;
P_0c069ff0: /* original 6023, guest PC 0x0c069ff0 */
if(!s->budget--) { s->failed_pc=0x0c069ff0u; return 0; }
r[0]=r[2];
goto P_0c069ff2;
P_0c069ff2: /* original 2f22, guest PC 0x0c069ff2 */
if(!s->budget--) { s->failed_pc=0x0c069ff2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c069ff4;
P_0c069ff4: /* original 51f1, guest PC 0x0c069ff4 */
if(!s->budget--) { s->failed_pc=0x0c069ff4u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c069ff6;
P_0c069ff6: /* original 3018, guest PC 0x0c069ff6 */
if(!s->budget--) { s->failed_pc=0x0c069ff6u; return 0; }
r[0]-=r[1];
goto P_0c069ff8;
P_0c069ff8: /* original 6503, guest PC 0x0c069ff8 */
if(!s->budget--) { s->failed_pc=0x0c069ff8u; return 0; }
r[5]=r[0];
goto P_0c069ffa;
P_0c069ffa: /* original 2f02, guest PC 0x0c069ffa */
if(!s->budget--) { s->failed_pc=0x0c069ffau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c069ffc;
P_0c069ffc: /* original 9450, guest PC 0x0c069ffc */
if(!s->budget--) { s->failed_pc=0x0c069ffcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a0a0u,2);
goto P_0c069ffe;
P_0c069ffe: /* original 4c0b, guest PC 0x0c069ffe */
if(!s->budget--) { s->failed_pc=0x0c069ffeu; return 0; }
target=r[12];
r[16]=code_base|0x0c06a002u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a002u) { target=s->pc; goto dispatch; }
goto P_0c06a002;
P_0c06a000: /* original 34ec, guest PC 0x0c06a000 */
if(!s->budget--) { s->failed_pc=0x0c06a000u; return 0; }
r[4]+=r[14];
goto P_0c06a002;
P_0c06a002: /* original 64e3, guest PC 0x0c06a002 */
if(!s->budget--) { s->failed_pc=0x0c06a002u; return 0; }
r[4]=r[14];
goto P_0c06a004;
P_0c06a004: /* original 4b0b, guest PC 0x0c06a004 */
if(!s->budget--) { s->failed_pc=0x0c06a004u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a008u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a008u) { target=s->pc; goto dispatch; }
goto P_0c06a008;
P_0c06a006: /* original 7440, guest PC 0x0c06a006 */
if(!s->budget--) { s->failed_pc=0x0c06a006u; return 0; }
r[4]+=0x00000040u;
goto P_0c06a008;
P_0c06a008: /* original 6403, guest PC 0x0c06a008 */
if(!s->budget--) { s->failed_pc=0x0c06a008u; return 0; }
r[4]=r[0];
goto P_0c06a00a;
P_0c06a00a: /* original 7401, guest PC 0x0c06a00a */
if(!s->budget--) { s->failed_pc=0x0c06a00au; return 0; }
r[4]+=0x00000001u;
goto P_0c06a00c;
P_0c06a00c: /* original 6543, guest PC 0x0c06a00c */
if(!s->budget--) { s->failed_pc=0x0c06a00cu; return 0; }
r[5]=r[4];
goto P_0c06a00e;
P_0c06a00e: /* original 1f41, guest PC 0x0c06a00e */
if(!s->budget--) { s->failed_pc=0x0c06a00eu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06a010;
P_0c06a010: /* original 64e3, guest PC 0x0c06a010 */
if(!s->budget--) { s->failed_pc=0x0c06a010u; return 0; }
r[4]=r[14];
goto P_0c06a012;
P_0c06a012: /* original 4c0b, guest PC 0x0c06a012 */
if(!s->budget--) { s->failed_pc=0x0c06a012u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a016u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a016u) { target=s->pc; goto dispatch; }
goto P_0c06a016;
P_0c06a014: /* original 7440, guest PC 0x0c06a014 */
if(!s->budget--) { s->failed_pc=0x0c06a014u; return 0; }
r[4]+=0x00000040u;
goto P_0c06a016;
P_0c06a016: /* original 64e3, guest PC 0x0c06a016 */
if(!s->budget--) { s->failed_pc=0x0c06a016u; return 0; }
r[4]=r[14];
goto P_0c06a018;
P_0c06a018: /* original 4b0b, guest PC 0x0c06a018 */
if(!s->budget--) { s->failed_pc=0x0c06a018u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a01cu;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a01cu) { target=s->pc; goto dispatch; }
goto P_0c06a01c;
P_0c06a01a: /* original 7448, guest PC 0x0c06a01a */
if(!s->budget--) { s->failed_pc=0x0c06a01au; return 0; }
r[4]+=0x00000048u;
goto P_0c06a01c;
P_0c06a01c: /* original 6403, guest PC 0x0c06a01c */
if(!s->budget--) { s->failed_pc=0x0c06a01cu; return 0; }
r[4]=r[0];
goto P_0c06a01e;
P_0c06a01e: /* original 7401, guest PC 0x0c06a01e */
if(!s->budget--) { s->failed_pc=0x0c06a01eu; return 0; }
r[4]+=0x00000001u;
goto P_0c06a020;
P_0c06a020: /* original 6543, guest PC 0x0c06a020 */
if(!s->budget--) { s->failed_pc=0x0c06a020u; return 0; }
r[5]=r[4];
goto P_0c06a022;
P_0c06a022: /* original 1f45, guest PC 0x0c06a022 */
if(!s->budget--) { s->failed_pc=0x0c06a022u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c06a024;
P_0c06a024: /* original 64e3, guest PC 0x0c06a024 */
if(!s->budget--) { s->failed_pc=0x0c06a024u; return 0; }
r[4]=r[14];
goto P_0c06a026;
P_0c06a026: /* original 4c0b, guest PC 0x0c06a026 */
if(!s->budget--) { s->failed_pc=0x0c06a026u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a02au;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a02au) { target=s->pc; goto dispatch; }
goto P_0c06a02a;
P_0c06a028: /* original 7448, guest PC 0x0c06a028 */
if(!s->budget--) { s->failed_pc=0x0c06a028u; return 0; }
r[4]+=0x00000048u;
goto P_0c06a02a;
P_0c06a02a: /* original 64e3, guest PC 0x0c06a02a */
if(!s->budget--) { s->failed_pc=0x0c06a02au; return 0; }
r[4]=r[14];
goto P_0c06a02c;
P_0c06a02c: /* original 4b0b, guest PC 0x0c06a02c */
if(!s->budget--) { s->failed_pc=0x0c06a02cu; return 0; }
target=r[11];
r[16]=code_base|0x0c06a030u;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a030u) { target=s->pc; goto dispatch; }
goto P_0c06a030;
P_0c06a02e: /* original 742c, guest PC 0x0c06a02e */
if(!s->budget--) { s->failed_pc=0x0c06a02eu; return 0; }
r[4]+=0x0000002cu;
goto P_0c06a030;
P_0c06a030: /* original 64e3, guest PC 0x0c06a030 */
if(!s->budget--) { s->failed_pc=0x0c06a030u; return 0; }
r[4]=r[14];
goto P_0c06a032;
P_0c06a032: /* original 2f02, guest PC 0x0c06a032 */
if(!s->budget--) { s->failed_pc=0x0c06a032u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a034;
P_0c06a034: /* original 4b0b, guest PC 0x0c06a034 */
if(!s->budget--) { s->failed_pc=0x0c06a034u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a038u;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a038u) { target=s->pc; goto dispatch; }
goto P_0c06a038;
P_0c06a036: /* original 7428, guest PC 0x0c06a036 */
if(!s->budget--) { s->failed_pc=0x0c06a036u; return 0; }
r[4]+=0x00000028u;
goto P_0c06a038;
P_0c06a038: /* original 63f2, guest PC 0x0c06a038 */
if(!s->budget--) { s->failed_pc=0x0c06a038u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a03a;
P_0c06a03a: /* original 6403, guest PC 0x0c06a03a */
if(!s->budget--) { s->failed_pc=0x0c06a03au; return 0; }
r[4]=r[0];
goto P_0c06a03c;
P_0c06a03c: /* original d21b, guest PC 0x0c06a03c */
if(!s->budget--) { s->failed_pc=0x0c06a03cu; return 0; }
r[2]=read(ram,0x0c06a0acu,4);
goto P_0c06a03e;
P_0c06a03e: /* original 343c, guest PC 0x0c06a03e */
if(!s->budget--) { s->failed_pc=0x0c06a03eu; return 0; }
r[4]+=r[3];
goto P_0c06a040;
P_0c06a040: /* original 6143, guest PC 0x0c06a040 */
if(!s->budget--) { s->failed_pc=0x0c06a040u; return 0; }
r[1]=r[4];
goto P_0c06a042;
P_0c06a042: /* original 420b, guest PC 0x0c06a042 */
if(!s->budget--) { s->failed_pc=0x0c06a042u; return 0; }
target=r[2];
r[16]=code_base|0x0c06a046u;
r[0]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a046u) { target=s->pc; goto dispatch; }
goto P_0c06a046;
P_0c06a044: /* original 50f1, guest PC 0x0c06a044 */
if(!s->budget--) { s->failed_pc=0x0c06a044u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c06a046;
P_0c06a046: /* original 64e3, guest PC 0x0c06a046 */
if(!s->budget--) { s->failed_pc=0x0c06a046u; return 0; }
r[4]=r[14];
goto P_0c06a048;
P_0c06a048: /* original 6503, guest PC 0x0c06a048 */
if(!s->budget--) { s->failed_pc=0x0c06a048u; return 0; }
r[5]=r[0];
goto P_0c06a04a;
P_0c06a04a: /* original 1f01, guest PC 0x0c06a04a */
if(!s->budget--) { s->failed_pc=0x0c06a04au; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a04c;
P_0c06a04c: /* original 4c0b, guest PC 0x0c06a04c */
if(!s->budget--) { s->failed_pc=0x0c06a04cu; return 0; }
target=r[12];
r[16]=code_base|0x0c06a050u;
r[4]+=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a050u) { target=s->pc; goto dispatch; }
goto P_0c06a050;
P_0c06a04e: /* original 744c, guest PC 0x0c06a04e */
if(!s->budget--) { s->failed_pc=0x0c06a04eu; return 0; }
r[4]+=0x0000004cu;
goto P_0c06a050;
P_0c06a050: /* original d316, guest PC 0x0c06a050 */
if(!s->budget--) { s->failed_pc=0x0c06a050u; return 0; }
r[3]=read(ram,0x0c06a0acu,4);
goto P_0c06a052;
P_0c06a052: /* original 61f2, guest PC 0x0c06a052 */
if(!s->budget--) { s->failed_pc=0x0c06a052u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a054;
P_0c06a054: /* original 430b, guest PC 0x0c06a054 */
if(!s->budget--) { s->failed_pc=0x0c06a054u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a058u;
r[0]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a058u) { target=s->pc; goto dispatch; }
goto P_0c06a058;
P_0c06a056: /* original 50f5, guest PC 0x0c06a056 */
if(!s->budget--) { s->failed_pc=0x0c06a056u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c06a058;
P_0c06a058: /* original 64e3, guest PC 0x0c06a058 */
if(!s->budget--) { s->failed_pc=0x0c06a058u; return 0; }
r[4]=r[14];
goto P_0c06a05a;
P_0c06a05a: /* original 6503, guest PC 0x0c06a05a */
if(!s->budget--) { s->failed_pc=0x0c06a05au; return 0; }
r[5]=r[0];
goto P_0c06a05c;
P_0c06a05c: /* original 1f01, guest PC 0x0c06a05c */
if(!s->budget--) { s->failed_pc=0x0c06a05cu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a05e;
P_0c06a05e: /* original 4c0b, guest PC 0x0c06a05e */
if(!s->budget--) { s->failed_pc=0x0c06a05eu; return 0; }
target=r[12];
r[16]=code_base|0x0c06a062u;
r[4]+=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a062u) { target=s->pc; goto dispatch; }
goto P_0c06a062;
P_0c06a060: /* original 7454, guest PC 0x0c06a060 */
if(!s->budget--) { s->failed_pc=0x0c06a060u; return 0; }
r[4]+=0x00000054u;
goto P_0c06a062;
P_0c06a062: /* original 901e, guest PC 0x0c06a062 */
if(!s->budget--) { s->failed_pc=0x0c06a062u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a0a2u,2);
goto P_0c06a064;
P_0c06a064: /* original 03dc, guest PC 0x0c06a064 */
if(!s->budget--) { s->failed_pc=0x0c06a064u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06a066;
P_0c06a066: /* original 1f31, guest PC 0x0c06a066 */
if(!s->budget--) { s->failed_pc=0x0c06a066u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06a068;
P_0c06a068: /* original 901c, guest PC 0x0c06a068 */
if(!s->budget--) { s->failed_pc=0x0c06a068u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a0a4u,2);
goto P_0c06a06a;
P_0c06a06a: /* original 06dc, guest PC 0x0c06a06a */
if(!s->budget--) { s->failed_pc=0x0c06a06au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06a06c;
P_0c06a06c: /* original 7001, guest PC 0x0c06a06c */
if(!s->budget--) { s->failed_pc=0x0c06a06cu; return 0; }
r[0]+=0x00000001u;
goto P_0c06a06e;
P_0c06a06e: /* original 04dc, guest PC 0x0c06a06e */
if(!s->budget--) { s->failed_pc=0x0c06a06eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06a070;
P_0c06a070: /* original 9019, guest PC 0x0c06a070 */
if(!s->budget--) { s->failed_pc=0x0c06a070u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a0a6u,2);
goto P_0c06a072;
P_0c06a072: /* original 2448, guest PC 0x0c06a072 */
if(!s->budget--) { s->failed_pc=0x0c06a072u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a074;
P_0c06a074: /* original 0529, guest PC 0x0c06a074 */
if(!s->budget--) { s->failed_pc=0x0c06a074u; return 0; }
r[5]=r[17]&1u;
goto P_0c06a076;
P_0c06a076: /* original 3630, guest PC 0x0c06a076 */
if(!s->budget--) { s->failed_pc=0x0c06a076u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[3])!=0);
goto P_0c06a078;
P_0c06a078: /* original 07dc, guest PC 0x0c06a078 */
if(!s->budget--) { s->failed_pc=0x0c06a078u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06a07a;
P_0c06a07a: /* original 0029, guest PC 0x0c06a07a */
if(!s->budget--) { s->failed_pc=0x0c06a07au; return 0; }
r[0]=r[17]&1u;
goto P_0c06a07c;
P_0c06a07c: /* original 3460, guest PC 0x0c06a07c */
if(!s->budget--) { s->failed_pc=0x0c06a07cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[6])!=0);
goto P_0c06a07e;
P_0c06a07e: /* original 1f01, guest PC 0x0c06a07e */
if(!s->budget--) { s->failed_pc=0x0c06a07eu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a080;
P_0c06a080: /* original 0629, guest PC 0x0c06a080 */
if(!s->budget--) { s->failed_pc=0x0c06a080u; return 0; }
r[6]=r[17]&1u;
goto P_0c06a082;
P_0c06a082: /* original 2778, guest PC 0x0c06a082 */
if(!s->budget--) { s->failed_pc=0x0c06a082u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06a084;
P_0c06a084: /* original 0029, guest PC 0x0c06a084 */
if(!s->budget--) { s->failed_pc=0x0c06a084u; return 0; }
r[0]=r[17]&1u;
goto P_0c06a086;
P_0c06a086: /* original 1f05, guest PC 0x0c06a086 */
if(!s->budget--) { s->failed_pc=0x0c06a086u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c06a088;
P_0c06a088: /* original 6043, guest PC 0x0c06a088 */
if(!s->budget--) { s->failed_pc=0x0c06a088u; return 0; }
r[0]=r[4];
goto P_0c06a08a;
P_0c06a08a: /* original 8803, guest PC 0x0c06a08a */
if(!s->budget--) { s->failed_pc=0x0c06a08au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06a08c;
P_0c06a08c: /* original 8952, guest PC 0x0c06a08c */
if(!s->budget--) { s->failed_pc=0x0c06a08cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a134; }
goto P_0c06a08e;
P_0c06a08e: /* original 2558, guest PC 0x0c06a08e */
if(!s->budget--) { s->failed_pc=0x0c06a08eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06a090;
P_0c06a090: /* original 8b10, guest PC 0x0c06a090 */
if(!s->budget--) { s->failed_pc=0x0c06a090u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a0b4; }
goto P_0c06a092;
P_0c06a092: /* original 53f1, guest PC 0x0c06a092 */
if(!s->budget--) { s->failed_pc=0x0c06a092u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06a094;
P_0c06a094: /* original 2338, guest PC 0x0c06a094 */
if(!s->budget--) { s->failed_pc=0x0c06a094u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06a096;
P_0c06a096: /* original 8b0b, guest PC 0x0c06a096 */
if(!s->budget--) { s->failed_pc=0x0c06a096u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a0b0; }
goto P_0c06a098;
P_0c06a098: /* original 2668, guest PC 0x0c06a098 */
if(!s->budget--) { s->failed_pc=0x0c06a098u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06a09a;
P_0c06a09a: /* original 8b4b, guest PC 0x0c06a09a */
if(!s->budget--) { s->failed_pc=0x0c06a09au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a134; }
goto P_0c06a09c;
P_0c06a09c: /* original a00a, guest PC 0x0c06a09c */
if(!s->budget--) { s->failed_pc=0x0c06a09cu; return 0; }
goto P_0c06a0b4;
P_0c06a09e: /* original 0009, guest PC 0x0c06a09e */
if(!s->budget--) { s->failed_pc=0x0c06a09eu; return 0; }
if(!vf3_matrix_family(0x0c06a0a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a0a0u; return 0; } return 1;
P_0c06a0b0: /* original 2668, guest PC 0x0c06a0b0 */
if(!s->budget--) { s->failed_pc=0x0c06a0b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06a0b2;
P_0c06a0b2: /* original 893f, guest PC 0x0c06a0b2 */
if(!s->budget--) { s->failed_pc=0x0c06a0b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a134; }
goto P_0c06a0b4;
P_0c06a0b4: /* original 64e3, guest PC 0x0c06a0b4 */
if(!s->budget--) { s->failed_pc=0x0c06a0b4u; return 0; }
r[4]=r[14];
goto P_0c06a0b6;
P_0c06a0b6: /* original 4b0b, guest PC 0x0c06a0b6 */
if(!s->budget--) { s->failed_pc=0x0c06a0b6u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a0bau;
r[4]+=0x00000060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a0bau) { target=s->pc; goto dispatch; }
goto P_0c06a0ba;
P_0c06a0b8: /* original 7460, guest PC 0x0c06a0b8 */
if(!s->budget--) { s->failed_pc=0x0c06a0b8u; return 0; }
r[4]+=0x00000060u;
goto P_0c06a0ba;
P_0c06a0ba: /* original 6403, guest PC 0x0c06a0ba */
if(!s->budget--) { s->failed_pc=0x0c06a0bau; return 0; }
r[4]=r[0];
goto P_0c06a0bc;
P_0c06a0bc: /* original 7401, guest PC 0x0c06a0bc */
if(!s->budget--) { s->failed_pc=0x0c06a0bcu; return 0; }
r[4]+=0x00000001u;
goto P_0c06a0be;
P_0c06a0be: /* original 6543, guest PC 0x0c06a0be */
if(!s->budget--) { s->failed_pc=0x0c06a0beu; return 0; }
r[5]=r[4];
goto P_0c06a0c0;
P_0c06a0c0: /* original 1f47, guest PC 0x0c06a0c0 */
if(!s->budget--) { s->failed_pc=0x0c06a0c0u; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c06a0c2;
P_0c06a0c2: /* original 64e3, guest PC 0x0c06a0c2 */
if(!s->budget--) { s->failed_pc=0x0c06a0c2u; return 0; }
r[4]=r[14];
goto P_0c06a0c4;
P_0c06a0c4: /* original 4c0b, guest PC 0x0c06a0c4 */
if(!s->budget--) { s->failed_pc=0x0c06a0c4u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a0c8u;
r[4]+=0x00000060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a0c8u) { target=s->pc; goto dispatch; }
goto P_0c06a0c8;
P_0c06a0c6: /* original 7460, guest PC 0x0c06a0c6 */
if(!s->budget--) { s->failed_pc=0x0c06a0c6u; return 0; }
r[4]+=0x00000060u;
goto P_0c06a0c8;
P_0c06a0c8: /* original 902c, guest PC 0x0c06a0c8 */
if(!s->budget--) { s->failed_pc=0x0c06a0c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a124u,2);
goto P_0c06a0ca;
P_0c06a0ca: /* original 03de, guest PC 0x0c06a0ca */
if(!s->budget--) { s->failed_pc=0x0c06a0cau; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c06a0cc;
P_0c06a0cc: /* original 1f36, guest PC 0x0c06a0cc */
if(!s->budget--) { s->failed_pc=0x0c06a0ccu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c06a0ce;
P_0c06a0ce: /* original 52f1, guest PC 0x0c06a0ce */
if(!s->budget--) { s->failed_pc=0x0c06a0ceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06a0d0;
P_0c06a0d0: /* original 2228, guest PC 0x0c06a0d0 */
if(!s->budget--) { s->failed_pc=0x0c06a0d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06a0d2;
P_0c06a0d2: /* original 8b02, guest PC 0x0c06a0d2 */
if(!s->budget--) { s->failed_pc=0x0c06a0d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a0da; }
goto P_0c06a0d4;
P_0c06a0d4: /* original 9027, guest PC 0x0c06a0d4 */
if(!s->budget--) { s->failed_pc=0x0c06a0d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a126u,2);
goto P_0c06a0d6;
P_0c06a0d6: /* original 01de, guest PC 0x0c06a0d6 */
if(!s->budget--) { s->failed_pc=0x0c06a0d6u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c06a0d8;
P_0c06a0d8: /* original 1f16, guest PC 0x0c06a0d8 */
if(!s->budget--) { s->failed_pc=0x0c06a0d8u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c06a0da;
P_0c06a0da: /* original 9425, guest PC 0x0c06a0da */
if(!s->budget--) { s->failed_pc=0x0c06a0dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a128u,2);
goto P_0c06a0dc;
P_0c06a0dc: /* original 4b0b, guest PC 0x0c06a0dc */
if(!s->budget--) { s->failed_pc=0x0c06a0dcu; return 0; }
target=r[11];
r[16]=code_base|0x0c06a0e0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a0e0u) { target=s->pc; goto dispatch; }
goto P_0c06a0e0;
P_0c06a0de: /* original 34ec, guest PC 0x0c06a0de */
if(!s->budget--) { s->failed_pc=0x0c06a0deu; return 0; }
r[4]+=r[14];
goto P_0c06a0e0;
P_0c06a0e0: /* original 2f02, guest PC 0x0c06a0e0 */
if(!s->budget--) { s->failed_pc=0x0c06a0e0u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a0e2;
P_0c06a0e2: /* original 62f2, guest PC 0x0c06a0e2 */
if(!s->budget--) { s->failed_pc=0x0c06a0e2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06a0e4;
P_0c06a0e4: /* original 53f6, guest PC 0x0c06a0e4 */
if(!s->budget--) { s->failed_pc=0x0c06a0e4u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c06a0e6;
P_0c06a0e6: /* original 323c, guest PC 0x0c06a0e6 */
if(!s->budget--) { s->failed_pc=0x0c06a0e6u; return 0; }
r[2]+=r[3];
goto P_0c06a0e8;
P_0c06a0e8: /* original 6523, guest PC 0x0c06a0e8 */
if(!s->budget--) { s->failed_pc=0x0c06a0e8u; return 0; }
r[5]=r[2];
goto P_0c06a0ea;
P_0c06a0ea: /* original 2f22, guest PC 0x0c06a0ea */
if(!s->budget--) { s->failed_pc=0x0c06a0eau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06a0ec;
P_0c06a0ec: /* original 941c, guest PC 0x0c06a0ec */
if(!s->budget--) { s->failed_pc=0x0c06a0ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a128u,2);
goto P_0c06a0ee;
P_0c06a0ee: /* original 4c0b, guest PC 0x0c06a0ee */
if(!s->budget--) { s->failed_pc=0x0c06a0eeu; return 0; }
target=r[12];
r[16]=code_base|0x0c06a0f2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a0f2u) { target=s->pc; goto dispatch; }
goto P_0c06a0f2;
P_0c06a0f0: /* original 34ec, guest PC 0x0c06a0f0 */
if(!s->budget--) { s->failed_pc=0x0c06a0f0u; return 0; }
r[4]+=r[14];
goto P_0c06a0f2;
P_0c06a0f2: /* original d30f, guest PC 0x0c06a0f2 */
if(!s->budget--) { s->failed_pc=0x0c06a0f2u; return 0; }
r[3]=read(ram,0x0c06a130u,4);
goto P_0c06a0f4;
P_0c06a0f4: /* original 61f2, guest PC 0x0c06a0f4 */
if(!s->budget--) { s->failed_pc=0x0c06a0f4u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a0f6;
P_0c06a0f6: /* original 430b, guest PC 0x0c06a0f6 */
if(!s->budget--) { s->failed_pc=0x0c06a0f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a0fau;
r[0]=read(ram,r[15]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a0fau) { target=s->pc; goto dispatch; }
goto P_0c06a0fa;
P_0c06a0f8: /* original 50f7, guest PC 0x0c06a0f8 */
if(!s->budget--) { s->failed_pc=0x0c06a0f8u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c06a0fa;
P_0c06a0fa: /* original 64e3, guest PC 0x0c06a0fa */
if(!s->budget--) { s->failed_pc=0x0c06a0fau; return 0; }
r[4]=r[14];
goto P_0c06a0fc;
P_0c06a0fc: /* original 6503, guest PC 0x0c06a0fc */
if(!s->budget--) { s->failed_pc=0x0c06a0fcu; return 0; }
r[5]=r[0];
goto P_0c06a0fe;
P_0c06a0fe: /* original 2f02, guest PC 0x0c06a0fe */
if(!s->budget--) { s->failed_pc=0x0c06a0feu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a100;
P_0c06a100: /* original 4c0b, guest PC 0x0c06a100 */
if(!s->budget--) { s->failed_pc=0x0c06a100u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a104u;
r[4]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a104u) { target=s->pc; goto dispatch; }
goto P_0c06a104;
P_0c06a102: /* original 7470, guest PC 0x0c06a102 */
if(!s->budget--) { s->failed_pc=0x0c06a102u; return 0; }
r[4]+=0x00000070u;
goto P_0c06a104;
P_0c06a104: /* original d30a, guest PC 0x0c06a104 */
if(!s->budget--) { s->failed_pc=0x0c06a104u; return 0; }
r[3]=read(ram,0x0c06a130u,4);
goto P_0c06a106;
P_0c06a106: /* original 51f6, guest PC 0x0c06a106 */
if(!s->budget--) { s->failed_pc=0x0c06a106u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c06a108;
P_0c06a108: /* original 940f, guest PC 0x0c06a108 */
if(!s->budget--) { s->failed_pc=0x0c06a108u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a12au,2);
goto P_0c06a10a;
P_0c06a10a: /* original 430b, guest PC 0x0c06a10a */
if(!s->budget--) { s->failed_pc=0x0c06a10au; return 0; }
target=r[3];
r[16]=code_base|0x0c06a10eu;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a10eu) { target=s->pc; goto dispatch; }
goto P_0c06a10e;
P_0c06a10c: /* original 6043, guest PC 0x0c06a10c */
if(!s->budget--) { s->failed_pc=0x0c06a10cu; return 0; }
r[0]=r[4];
goto P_0c06a10e;
P_0c06a10e: /* original 3096, guest PC 0x0c06a10e */
if(!s->budget--) { s->failed_pc=0x0c06a10eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[9])!=0);
goto P_0c06a110;
P_0c06a110: /* original 8f01, guest PC 0x0c06a110 */
if(!s->budget--) { s->failed_pc=0x0c06a110u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c06a116; }
goto P_0c06a114;
P_0c06a112: /* original 2f02, guest PC 0x0c06a112 */
if(!s->budget--) { s->failed_pc=0x0c06a112u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a114;
P_0c06a114: /* original 2f92, guest PC 0x0c06a114 */
if(!s->budget--) { s->failed_pc=0x0c06a114u; return 0; }
write(ram,r[15],r[9],4);
goto P_0c06a116;
P_0c06a116: /* original 9309, guest PC 0x0c06a116 */
if(!s->budget--) { s->failed_pc=0x0c06a116u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a12cu,2);
goto P_0c06a118;
P_0c06a118: /* original 64f2, guest PC 0x0c06a118 */
if(!s->budget--) { s->failed_pc=0x0c06a118u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a11a;
P_0c06a11a: /* original 33ec, guest PC 0x0c06a11a */
if(!s->budget--) { s->failed_pc=0x0c06a11au; return 0; }
r[3]+=r[14];
goto P_0c06a11c;
P_0c06a11c: /* original 4408, guest PC 0x0c06a11c */
if(!s->budget--) { s->failed_pc=0x0c06a11cu; return 0; }
r[4]<<=2;
goto P_0c06a11e;
P_0c06a11e: /* original 343c, guest PC 0x0c06a11e */
if(!s->budget--) { s->failed_pc=0x0c06a11eu; return 0; }
r[4]+=r[3];
goto P_0c06a120;
P_0c06a120: /* original a042, guest PC 0x0c06a120 */
if(!s->budget--) { s->failed_pc=0x0c06a120u; return 0; }
r[5]=0x00000001u;
goto P_0c06a1a8;
P_0c06a122: /* original e501, guest PC 0x0c06a122 */
if(!s->budget--) { s->failed_pc=0x0c06a122u; return 0; }
r[5]=0x00000001u;
if(!vf3_matrix_family(0x0c06a124u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a124u; return 0; } return 1;
P_0c06a134: /* original 64e3, guest PC 0x0c06a134 */
if(!s->budget--) { s->failed_pc=0x0c06a134u; return 0; }
r[4]=r[14];
goto P_0c06a136;
P_0c06a136: /* original 4b0b, guest PC 0x0c06a136 */
if(!s->budget--) { s->failed_pc=0x0c06a136u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a13au;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a13au) { target=s->pc; goto dispatch; }
goto P_0c06a13a;
P_0c06a138: /* original 7464, guest PC 0x0c06a138 */
if(!s->budget--) { s->failed_pc=0x0c06a138u; return 0; }
r[4]+=0x00000064u;
goto P_0c06a13a;
P_0c06a13a: /* original 6403, guest PC 0x0c06a13a */
if(!s->budget--) { s->failed_pc=0x0c06a13au; return 0; }
r[4]=r[0];
goto P_0c06a13c;
P_0c06a13c: /* original 7401, guest PC 0x0c06a13c */
if(!s->budget--) { s->failed_pc=0x0c06a13cu; return 0; }
r[4]+=0x00000001u;
goto P_0c06a13e;
P_0c06a13e: /* original 6543, guest PC 0x0c06a13e */
if(!s->budget--) { s->failed_pc=0x0c06a13eu; return 0; }
r[5]=r[4];
goto P_0c06a140;
P_0c06a140: /* original 1f47, guest PC 0x0c06a140 */
if(!s->budget--) { s->failed_pc=0x0c06a140u; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c06a142;
P_0c06a142: /* original 64e3, guest PC 0x0c06a142 */
if(!s->budget--) { s->failed_pc=0x0c06a142u; return 0; }
r[4]=r[14];
goto P_0c06a144;
P_0c06a144: /* original 4c0b, guest PC 0x0c06a144 */
if(!s->budget--) { s->failed_pc=0x0c06a144u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a148u;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a148u) { target=s->pc; goto dispatch; }
goto P_0c06a148;
P_0c06a146: /* original 7464, guest PC 0x0c06a146 */
if(!s->budget--) { s->failed_pc=0x0c06a146u; return 0; }
r[4]+=0x00000064u;
goto P_0c06a148;
P_0c06a148: /* original 948c, guest PC 0x0c06a148 */
if(!s->budget--) { s->failed_pc=0x0c06a148u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a264u,2);
goto P_0c06a14a;
P_0c06a14a: /* original 55f7, guest PC 0x0c06a14a */
if(!s->budget--) { s->failed_pc=0x0c06a14au; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c06a14c;
P_0c06a14c: /* original 4c0b, guest PC 0x0c06a14c */
if(!s->budget--) { s->failed_pc=0x0c06a14cu; return 0; }
target=r[12];
r[16]=code_base|0x0c06a150u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a150u) { target=s->pc; goto dispatch; }
goto P_0c06a150;
P_0c06a14e: /* original 34ec, guest PC 0x0c06a14e */
if(!s->budget--) { s->failed_pc=0x0c06a14eu; return 0; }
r[4]+=r[14];
goto P_0c06a150;
P_0c06a150: /* original 9089, guest PC 0x0c06a150 */
if(!s->budget--) { s->failed_pc=0x0c06a150u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a266u,2);
goto P_0c06a152;
P_0c06a152: /* original 03de, guest PC 0x0c06a152 */
if(!s->budget--) { s->failed_pc=0x0c06a152u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c06a154;
P_0c06a154: /* original 1f36, guest PC 0x0c06a154 */
if(!s->budget--) { s->failed_pc=0x0c06a154u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c06a156;
P_0c06a156: /* original 52f1, guest PC 0x0c06a156 */
if(!s->budget--) { s->failed_pc=0x0c06a156u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06a158;
P_0c06a158: /* original 2228, guest PC 0x0c06a158 */
if(!s->budget--) { s->failed_pc=0x0c06a158u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06a15a;
P_0c06a15a: /* original 8b02, guest PC 0x0c06a15a */
if(!s->budget--) { s->failed_pc=0x0c06a15au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a162; }
goto P_0c06a15c;
P_0c06a15c: /* original 9082, guest PC 0x0c06a15c */
if(!s->budget--) { s->failed_pc=0x0c06a15cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a264u,2);
goto P_0c06a15e;
P_0c06a15e: /* original 02de, guest PC 0x0c06a15e */
if(!s->budget--) { s->failed_pc=0x0c06a15eu; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c06a160;
P_0c06a160: /* original 1f26, guest PC 0x0c06a160 */
if(!s->budget--) { s->failed_pc=0x0c06a160u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c06a162;
P_0c06a162: /* original 9481, guest PC 0x0c06a162 */
if(!s->budget--) { s->failed_pc=0x0c06a162u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a268u,2);
goto P_0c06a164;
P_0c06a164: /* original 4b0b, guest PC 0x0c06a164 */
if(!s->budget--) { s->failed_pc=0x0c06a164u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a168u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a168u) { target=s->pc; goto dispatch; }
goto P_0c06a168;
P_0c06a166: /* original 34ec, guest PC 0x0c06a166 */
if(!s->budget--) { s->failed_pc=0x0c06a166u; return 0; }
r[4]+=r[14];
goto P_0c06a168;
P_0c06a168: /* original 2f02, guest PC 0x0c06a168 */
if(!s->budget--) { s->failed_pc=0x0c06a168u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a16a;
P_0c06a16a: /* original 53f6, guest PC 0x0c06a16a */
if(!s->budget--) { s->failed_pc=0x0c06a16au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c06a16c;
P_0c06a16c: /* original 303c, guest PC 0x0c06a16c */
if(!s->budget--) { s->failed_pc=0x0c06a16cu; return 0; }
r[0]+=r[3];
goto P_0c06a16e;
P_0c06a16e: /* original 6503, guest PC 0x0c06a16e */
if(!s->budget--) { s->failed_pc=0x0c06a16eu; return 0; }
r[5]=r[0];
goto P_0c06a170;
P_0c06a170: /* original 2f02, guest PC 0x0c06a170 */
if(!s->budget--) { s->failed_pc=0x0c06a170u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a172;
P_0c06a172: /* original 9479, guest PC 0x0c06a172 */
if(!s->budget--) { s->failed_pc=0x0c06a172u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a268u,2);
goto P_0c06a174;
P_0c06a174: /* original 4c0b, guest PC 0x0c06a174 */
if(!s->budget--) { s->failed_pc=0x0c06a174u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a178u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a178u) { target=s->pc; goto dispatch; }
goto P_0c06a178;
P_0c06a176: /* original 34ec, guest PC 0x0c06a176 */
if(!s->budget--) { s->failed_pc=0x0c06a176u; return 0; }
r[4]+=r[14];
goto P_0c06a178;
P_0c06a178: /* original d342, guest PC 0x0c06a178 */
if(!s->budget--) { s->failed_pc=0x0c06a178u; return 0; }
r[3]=read(ram,0x0c06a284u,4);
goto P_0c06a17a;
P_0c06a17a: /* original 61f2, guest PC 0x0c06a17a */
if(!s->budget--) { s->failed_pc=0x0c06a17au; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a17c;
P_0c06a17c: /* original 430b, guest PC 0x0c06a17c */
if(!s->budget--) { s->failed_pc=0x0c06a17cu; return 0; }
target=r[3];
r[16]=code_base|0x0c06a180u;
r[0]=read(ram,r[15]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a180u) { target=s->pc; goto dispatch; }
goto P_0c06a180;
P_0c06a17e: /* original 50f7, guest PC 0x0c06a17e */
if(!s->budget--) { s->failed_pc=0x0c06a17eu; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c06a180;
P_0c06a180: /* original 64e3, guest PC 0x0c06a180 */
if(!s->budget--) { s->failed_pc=0x0c06a180u; return 0; }
r[4]=r[14];
goto P_0c06a182;
P_0c06a182: /* original 6503, guest PC 0x0c06a182 */
if(!s->budget--) { s->failed_pc=0x0c06a182u; return 0; }
r[5]=r[0];
goto P_0c06a184;
P_0c06a184: /* original 2f02, guest PC 0x0c06a184 */
if(!s->budget--) { s->failed_pc=0x0c06a184u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a186;
P_0c06a186: /* original 4c0b, guest PC 0x0c06a186 */
if(!s->budget--) { s->failed_pc=0x0c06a186u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a18au;
r[4]+=0x00000074u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a18au) { target=s->pc; goto dispatch; }
goto P_0c06a18a;
P_0c06a188: /* original 7474, guest PC 0x0c06a188 */
if(!s->budget--) { s->failed_pc=0x0c06a188u; return 0; }
r[4]+=0x00000074u;
goto P_0c06a18a;
P_0c06a18a: /* original d33e, guest PC 0x0c06a18a */
if(!s->budget--) { s->failed_pc=0x0c06a18au; return 0; }
r[3]=read(ram,0x0c06a284u,4);
goto P_0c06a18c;
P_0c06a18c: /* original 51f6, guest PC 0x0c06a18c */
if(!s->budget--) { s->failed_pc=0x0c06a18cu; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c06a18e;
P_0c06a18e: /* original 946c, guest PC 0x0c06a18e */
if(!s->budget--) { s->failed_pc=0x0c06a18eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a26au,2);
goto P_0c06a190;
P_0c06a190: /* original 430b, guest PC 0x0c06a190 */
if(!s->budget--) { s->failed_pc=0x0c06a190u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a194u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a194u) { target=s->pc; goto dispatch; }
goto P_0c06a194;
P_0c06a192: /* original 6043, guest PC 0x0c06a192 */
if(!s->budget--) { s->failed_pc=0x0c06a192u; return 0; }
r[0]=r[4];
goto P_0c06a194;
P_0c06a194: /* original 3096, guest PC 0x0c06a194 */
if(!s->budget--) { s->failed_pc=0x0c06a194u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[9])!=0);
goto P_0c06a196;
P_0c06a196: /* original 8f01, guest PC 0x0c06a196 */
if(!s->budget--) { s->failed_pc=0x0c06a196u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c06a19c; }
goto P_0c06a19a;
P_0c06a198: /* original 2f02, guest PC 0x0c06a198 */
if(!s->budget--) { s->failed_pc=0x0c06a198u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a19a;
P_0c06a19a: /* original 2f92, guest PC 0x0c06a19a */
if(!s->budget--) { s->failed_pc=0x0c06a19au; return 0; }
write(ram,r[15],r[9],4);
goto P_0c06a19c;
P_0c06a19c: /* original 9366, guest PC 0x0c06a19c */
if(!s->budget--) { s->failed_pc=0x0c06a19cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a26cu,2);
goto P_0c06a19e;
P_0c06a19e: /* original e501, guest PC 0x0c06a19e */
if(!s->budget--) { s->failed_pc=0x0c06a19eu; return 0; }
r[5]=0x00000001u;
goto P_0c06a1a0;
P_0c06a1a0: /* original 64f2, guest PC 0x0c06a1a0 */
if(!s->budget--) { s->failed_pc=0x0c06a1a0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a1a2;
P_0c06a1a2: /* original 33ec, guest PC 0x0c06a1a2 */
if(!s->budget--) { s->failed_pc=0x0c06a1a2u; return 0; }
r[3]+=r[14];
goto P_0c06a1a4;
P_0c06a1a4: /* original 4408, guest PC 0x0c06a1a4 */
if(!s->budget--) { s->failed_pc=0x0c06a1a4u; return 0; }
r[4]<<=2;
goto P_0c06a1a6;
P_0c06a1a6: /* original 343c, guest PC 0x0c06a1a6 */
if(!s->budget--) { s->failed_pc=0x0c06a1a6u; return 0; }
r[4]+=r[3];
goto P_0c06a1a8;
P_0c06a1a8: /* original ba8d, guest PC 0x0c06a1a8 */
if(!s->budget--) { s->failed_pc=0x0c06a1a8u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a1acu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a1acu) { target=s->pc; goto dispatch; }
goto P_0c06a1ac;
P_0c06a1aa: /* original 0009, guest PC 0x0c06a1aa */
if(!s->budget--) { s->failed_pc=0x0c06a1aau; return 0; }
goto P_0c06a1ac;
P_0c06a1ac: /* original 905b, guest PC 0x0c06a1ac */
if(!s->budget--) { s->failed_pc=0x0c06a1acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a266u,2);
goto P_0c06a1ae;
P_0c06a1ae: /* original 53f1, guest PC 0x0c06a1ae */
if(!s->budget--) { s->failed_pc=0x0c06a1aeu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06a1b0;
P_0c06a1b0: /* original 09de, guest PC 0x0c06a1b0 */
if(!s->budget--) { s->failed_pc=0x0c06a1b0u; return 0; }
r[9]=read(ram,r[13]+r[0],4);
goto P_0c06a1b2;
P_0c06a1b2: /* original 2338, guest PC 0x0c06a1b2 */
if(!s->budget--) { s->failed_pc=0x0c06a1b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06a1b4;
P_0c06a1b4: /* original 8b03, guest PC 0x0c06a1b4 */
if(!s->budget--) { s->failed_pc=0x0c06a1b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a1be; }
goto P_0c06a1b6;
P_0c06a1b6: /* original 9055, guest PC 0x0c06a1b6 */
if(!s->budget--) { s->failed_pc=0x0c06a1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a264u,2);
goto P_0c06a1b8;
P_0c06a1b8: /* original 6493, guest PC 0x0c06a1b8 */
if(!s->budget--) { s->failed_pc=0x0c06a1b8u; return 0; }
r[4]=r[9];
goto P_0c06a1ba;
P_0c06a1ba: /* original 09de, guest PC 0x0c06a1ba */
if(!s->budget--) { s->failed_pc=0x0c06a1bau; return 0; }
r[9]=read(ram,r[13]+r[0],4);
goto P_0c06a1bc;
P_0c06a1bc: /* original 0d46, guest PC 0x0c06a1bc */
if(!s->budget--) { s->failed_pc=0x0c06a1bcu; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c06a1be;
P_0c06a1be: /* original 9456, guest PC 0x0c06a1be */
if(!s->budget--) { s->failed_pc=0x0c06a1beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a26eu,2);
goto P_0c06a1c0;
P_0c06a1c0: /* original 4b0b, guest PC 0x0c06a1c0 */
if(!s->budget--) { s->failed_pc=0x0c06a1c0u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a1c4u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a1c4u) { target=s->pc; goto dispatch; }
goto P_0c06a1c4;
P_0c06a1c2: /* original 34ec, guest PC 0x0c06a1c2 */
if(!s->budget--) { s->failed_pc=0x0c06a1c2u; return 0; }
r[4]+=r[14];
goto P_0c06a1c4;
P_0c06a1c4: /* original 6403, guest PC 0x0c06a1c4 */
if(!s->budget--) { s->failed_pc=0x0c06a1c4u; return 0; }
r[4]=r[0];
goto P_0c06a1c6;
P_0c06a1c6: /* original 349c, guest PC 0x0c06a1c6 */
if(!s->budget--) { s->failed_pc=0x0c06a1c6u; return 0; }
r[4]+=r[9];
goto P_0c06a1c8;
P_0c06a1c8: /* original 6543, guest PC 0x0c06a1c8 */
if(!s->budget--) { s->failed_pc=0x0c06a1c8u; return 0; }
r[5]=r[4];
goto P_0c06a1ca;
P_0c06a1ca: /* original 1f46, guest PC 0x0c06a1ca */
if(!s->budget--) { s->failed_pc=0x0c06a1cau; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c06a1cc;
P_0c06a1cc: /* original 944f, guest PC 0x0c06a1cc */
if(!s->budget--) { s->failed_pc=0x0c06a1ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a26eu,2);
goto P_0c06a1ce;
P_0c06a1ce: /* original 4c0b, guest PC 0x0c06a1ce */
if(!s->budget--) { s->failed_pc=0x0c06a1ceu; return 0; }
target=r[12];
r[16]=code_base|0x0c06a1d2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a1d2u) { target=s->pc; goto dispatch; }
goto P_0c06a1d2;
P_0c06a1d0: /* original 34ec, guest PC 0x0c06a1d0 */
if(!s->budget--) { s->failed_pc=0x0c06a1d0u; return 0; }
r[4]+=r[14];
goto P_0c06a1d2;
P_0c06a1d2: /* original 944d, guest PC 0x0c06a1d2 */
if(!s->budget--) { s->failed_pc=0x0c06a1d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a270u,2);
goto P_0c06a1d4;
P_0c06a1d4: /* original 4b0b, guest PC 0x0c06a1d4 */
if(!s->budget--) { s->failed_pc=0x0c06a1d4u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a1d8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a1d8u) { target=s->pc; goto dispatch; }
goto P_0c06a1d8;
P_0c06a1d6: /* original 34ec, guest PC 0x0c06a1d6 */
if(!s->budget--) { s->failed_pc=0x0c06a1d6u; return 0; }
r[4]+=r[14];
goto P_0c06a1d8;
P_0c06a1d8: /* original 6303, guest PC 0x0c06a1d8 */
if(!s->budget--) { s->failed_pc=0x0c06a1d8u; return 0; }
r[3]=r[0];
goto P_0c06a1da;
P_0c06a1da: /* original 7301, guest PC 0x0c06a1da */
if(!s->budget--) { s->failed_pc=0x0c06a1dau; return 0; }
r[3]+=0x00000001u;
goto P_0c06a1dc;
P_0c06a1dc: /* original 6533, guest PC 0x0c06a1dc */
if(!s->budget--) { s->failed_pc=0x0c06a1dcu; return 0; }
r[5]=r[3];
goto P_0c06a1de;
P_0c06a1de: /* original 2f32, guest PC 0x0c06a1de */
if(!s->budget--) { s->failed_pc=0x0c06a1deu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06a1e0;
P_0c06a1e0: /* original 9446, guest PC 0x0c06a1e0 */
if(!s->budget--) { s->failed_pc=0x0c06a1e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a270u,2);
goto P_0c06a1e2;
P_0c06a1e2: /* original 4c0b, guest PC 0x0c06a1e2 */
if(!s->budget--) { s->failed_pc=0x0c06a1e2u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a1e6u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a1e6u) { target=s->pc; goto dispatch; }
goto P_0c06a1e6;
P_0c06a1e4: /* original 34ec, guest PC 0x0c06a1e4 */
if(!s->budget--) { s->failed_pc=0x0c06a1e4u; return 0; }
r[4]+=r[14];
goto P_0c06a1e6;
P_0c06a1e6: /* original d327, guest PC 0x0c06a1e6 */
if(!s->budget--) { s->failed_pc=0x0c06a1e6u; return 0; }
r[3]=read(ram,0x0c06a284u,4);
goto P_0c06a1e8;
P_0c06a1e8: /* original 51f6, guest PC 0x0c06a1e8 */
if(!s->budget--) { s->failed_pc=0x0c06a1e8u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c06a1ea;
P_0c06a1ea: /* original 430b, guest PC 0x0c06a1ea */
if(!s->budget--) { s->failed_pc=0x0c06a1eau; return 0; }
target=r[3];
r[16]=code_base|0x0c06a1eeu;
tmp=read(ram,r[15],4);
r[0]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a1eeu) { target=s->pc; goto dispatch; }
goto P_0c06a1ee;
P_0c06a1ec: /* original 60f2, guest PC 0x0c06a1ec */
if(!s->budget--) { s->failed_pc=0x0c06a1ecu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c06a1ee;
P_0c06a1ee: /* original 6503, guest PC 0x0c06a1ee */
if(!s->budget--) { s->failed_pc=0x0c06a1eeu; return 0; }
r[5]=r[0];
goto P_0c06a1f0;
P_0c06a1f0: /* original 2f02, guest PC 0x0c06a1f0 */
if(!s->budget--) { s->failed_pc=0x0c06a1f0u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a1f2;
P_0c06a1f2: /* original 943e, guest PC 0x0c06a1f2 */
if(!s->budget--) { s->failed_pc=0x0c06a1f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a272u,2);
goto P_0c06a1f4;
P_0c06a1f4: /* original 4c0b, guest PC 0x0c06a1f4 */
if(!s->budget--) { s->failed_pc=0x0c06a1f4u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a1f8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a1f8u) { target=s->pc; goto dispatch; }
goto P_0c06a1f8;
P_0c06a1f6: /* original 34ec, guest PC 0x0c06a1f6 */
if(!s->budget--) { s->failed_pc=0x0c06a1f6u; return 0; }
r[4]+=r[14];
goto P_0c06a1f8;
P_0c06a1f8: /* original 943c, guest PC 0x0c06a1f8 */
if(!s->budget--) { s->failed_pc=0x0c06a1f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a274u,2);
goto P_0c06a1fa;
P_0c06a1fa: /* original 4b0b, guest PC 0x0c06a1fa */
if(!s->budget--) { s->failed_pc=0x0c06a1fau; return 0; }
target=r[11];
r[16]=code_base|0x0c06a1feu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a1feu) { target=s->pc; goto dispatch; }
goto P_0c06a1fe;
P_0c06a1fc: /* original 34ec, guest PC 0x0c06a1fc */
if(!s->budget--) { s->failed_pc=0x0c06a1fcu; return 0; }
r[4]+=r[14];
goto P_0c06a1fe;
P_0c06a1fe: /* original 6403, guest PC 0x0c06a1fe */
if(!s->budget--) { s->failed_pc=0x0c06a1feu; return 0; }
r[4]=r[0];
goto P_0c06a200;
P_0c06a200: /* original 2448, guest PC 0x0c06a200 */
if(!s->budget--) { s->failed_pc=0x0c06a200u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a202;
P_0c06a202: /* original 8901, guest PC 0x0c06a202 */
if(!s->budget--) { s->failed_pc=0x0c06a202u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a208; }
goto P_0c06a204;
P_0c06a204: /* original 3496, guest PC 0x0c06a204 */
if(!s->budget--) { s->failed_pc=0x0c06a204u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[9])!=0);
goto P_0c06a206;
P_0c06a206: /* original 8b03, guest PC 0x0c06a206 */
if(!s->budget--) { s->failed_pc=0x0c06a206u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a210; }
goto P_0c06a208;
P_0c06a208: /* original 9434, guest PC 0x0c06a208 */
if(!s->budget--) { s->failed_pc=0x0c06a208u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a274u,2);
goto P_0c06a20a;
P_0c06a20a: /* original 6593, guest PC 0x0c06a20a */
if(!s->budget--) { s->failed_pc=0x0c06a20au; return 0; }
r[5]=r[9];
goto P_0c06a20c;
P_0c06a20c: /* original 4c0b, guest PC 0x0c06a20c */
if(!s->budget--) { s->failed_pc=0x0c06a20cu; return 0; }
target=r[12];
r[16]=code_base|0x0c06a210u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a210u) { target=s->pc; goto dispatch; }
goto P_0c06a210;
P_0c06a20e: /* original 34ec, guest PC 0x0c06a20e */
if(!s->budget--) { s->failed_pc=0x0c06a20eu; return 0; }
r[4]+=r[14];
goto P_0c06a210;
P_0c06a210: /* original 9431, guest PC 0x0c06a210 */
if(!s->budget--) { s->failed_pc=0x0c06a210u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a276u,2);
goto P_0c06a212;
P_0c06a212: /* original 4b0b, guest PC 0x0c06a212 */
if(!s->budget--) { s->failed_pc=0x0c06a212u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a216u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a216u) { target=s->pc; goto dispatch; }
goto P_0c06a216;
P_0c06a214: /* original 34ec, guest PC 0x0c06a214 */
if(!s->budget--) { s->failed_pc=0x0c06a214u; return 0; }
r[4]+=r[14];
goto P_0c06a216;
P_0c06a216: /* original 6403, guest PC 0x0c06a216 */
if(!s->budget--) { s->failed_pc=0x0c06a216u; return 0; }
r[4]=r[0];
goto P_0c06a218;
P_0c06a218: /* original 2448, guest PC 0x0c06a218 */
if(!s->budget--) { s->failed_pc=0x0c06a218u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a21a;
P_0c06a21a: /* original 8901, guest PC 0x0c06a21a */
if(!s->budget--) { s->failed_pc=0x0c06a21au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a220; }
goto P_0c06a21c;
P_0c06a21c: /* original 3492, guest PC 0x0c06a21c */
if(!s->budget--) { s->failed_pc=0x0c06a21cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[9])!=0);
goto P_0c06a21e;
P_0c06a21e: /* original 8903, guest PC 0x0c06a21e */
if(!s->budget--) { s->failed_pc=0x0c06a21eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a228; }
goto P_0c06a220;
P_0c06a220: /* original 9429, guest PC 0x0c06a220 */
if(!s->budget--) { s->failed_pc=0x0c06a220u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a276u,2);
goto P_0c06a222;
P_0c06a222: /* original 6593, guest PC 0x0c06a222 */
if(!s->budget--) { s->failed_pc=0x0c06a222u; return 0; }
r[5]=r[9];
goto P_0c06a224;
P_0c06a224: /* original 4c0b, guest PC 0x0c06a224 */
if(!s->budget--) { s->failed_pc=0x0c06a224u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a228u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a228u) { target=s->pc; goto dispatch; }
goto P_0c06a228;
P_0c06a226: /* original 34ec, guest PC 0x0c06a226 */
if(!s->budget--) { s->failed_pc=0x0c06a226u; return 0; }
r[4]+=r[14];
goto P_0c06a228;
P_0c06a228: /* original 9026, guest PC 0x0c06a228 */
if(!s->budget--) { s->failed_pc=0x0c06a228u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a278u,2);
goto P_0c06a22a;
P_0c06a22a: /* original 9426, guest PC 0x0c06a22a */
if(!s->budget--) { s->failed_pc=0x0c06a22au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a27au,2);
goto P_0c06a22c;
P_0c06a22c: /* original 05de, guest PC 0x0c06a22c */
if(!s->budget--) { s->failed_pc=0x0c06a22cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c06a22e;
P_0c06a22e: /* original ba4a, guest PC 0x0c06a22e */
if(!s->budget--) { s->failed_pc=0x0c06a22eu; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a232u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a232u) { target=s->pc; goto dispatch; }
goto P_0c06a232;
P_0c06a230: /* original 34ec, guest PC 0x0c06a230 */
if(!s->budget--) { s->failed_pc=0x0c06a230u; return 0; }
r[4]+=r[14];
goto P_0c06a232;
P_0c06a232: /* original 9023, guest PC 0x0c06a232 */
if(!s->budget--) { s->failed_pc=0x0c06a232u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a27cu,2);
goto P_0c06a234;
P_0c06a234: /* original 9420, guest PC 0x0c06a234 */
if(!s->budget--) { s->failed_pc=0x0c06a234u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a278u,2);
goto P_0c06a236;
P_0c06a236: /* original 05de, guest PC 0x0c06a236 */
if(!s->budget--) { s->failed_pc=0x0c06a236u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c06a238;
P_0c06a238: /* original ba45, guest PC 0x0c06a238 */
if(!s->budget--) { s->failed_pc=0x0c06a238u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a23cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a23cu) { target=s->pc; goto dispatch; }
goto P_0c06a23c;
P_0c06a23a: /* original 34ec, guest PC 0x0c06a23a */
if(!s->budget--) { s->failed_pc=0x0c06a23au; return 0; }
r[4]+=r[14];
goto P_0c06a23c;
P_0c06a23c: /* original 901f, guest PC 0x0c06a23c */
if(!s->budget--) { s->failed_pc=0x0c06a23cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a27eu,2);
goto P_0c06a23e;
P_0c06a23e: /* original 941d, guest PC 0x0c06a23e */
if(!s->budget--) { s->failed_pc=0x0c06a23eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a27cu,2);
goto P_0c06a240;
P_0c06a240: /* original 05de, guest PC 0x0c06a240 */
if(!s->budget--) { s->failed_pc=0x0c06a240u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c06a242;
P_0c06a242: /* original ba40, guest PC 0x0c06a242 */
if(!s->budget--) { s->failed_pc=0x0c06a242u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a246u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a246u) { target=s->pc; goto dispatch; }
goto P_0c06a246;
P_0c06a244: /* original 34ec, guest PC 0x0c06a244 */
if(!s->budget--) { s->failed_pc=0x0c06a244u; return 0; }
r[4]+=r[14];
goto P_0c06a246;
P_0c06a246: /* original 901b, guest PC 0x0c06a246 */
if(!s->budget--) { s->failed_pc=0x0c06a246u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a280u,2);
goto P_0c06a248;
P_0c06a248: /* original 9419, guest PC 0x0c06a248 */
if(!s->budget--) { s->failed_pc=0x0c06a248u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a27eu,2);
goto P_0c06a24a;
P_0c06a24a: /* original 05de, guest PC 0x0c06a24a */
if(!s->budget--) { s->failed_pc=0x0c06a24au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c06a24c;
P_0c06a24c: /* original ba3b, guest PC 0x0c06a24c */
if(!s->budget--) { s->failed_pc=0x0c06a24cu; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a250u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a250u) { target=s->pc; goto dispatch; }
goto P_0c06a250;
P_0c06a24e: /* original 34ec, guest PC 0x0c06a24e */
if(!s->budget--) { s->failed_pc=0x0c06a24eu; return 0; }
r[4]+=r[14];
goto P_0c06a250;
P_0c06a250: /* original 9017, guest PC 0x0c06a250 */
if(!s->budget--) { s->failed_pc=0x0c06a250u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a282u,2);
goto P_0c06a252;
P_0c06a252: /* original 9415, guest PC 0x0c06a252 */
if(!s->budget--) { s->failed_pc=0x0c06a252u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a280u,2);
goto P_0c06a254;
P_0c06a254: /* original 0cde, guest PC 0x0c06a254 */
if(!s->budget--) { s->failed_pc=0x0c06a254u; return 0; }
r[12]=read(ram,r[13]+r[0],4);
goto P_0c06a256;
P_0c06a256: /* original 65c3, guest PC 0x0c06a256 */
if(!s->budget--) { s->failed_pc=0x0c06a256u; return 0; }
r[5]=r[12];
goto P_0c06a258;
P_0c06a258: /* original ba35, guest PC 0x0c06a258 */
if(!s->budget--) { s->failed_pc=0x0c06a258u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a25cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a25cu) { target=s->pc; goto dispatch; }
goto P_0c06a25c;
P_0c06a25a: /* original 34ec, guest PC 0x0c06a25a */
if(!s->budget--) { s->failed_pc=0x0c06a25au; return 0; }
r[4]+=r[14];
goto P_0c06a25c;
P_0c06a25c: /* original d70a, guest PC 0x0c06a25c */
if(!s->budget--) { s->failed_pc=0x0c06a25cu; return 0; }
r[7]=read(ram,0x0c06a288u,4);
goto P_0c06a25e;
P_0c06a25e: /* original 64a3, guest PC 0x0c06a25e */
if(!s->budget--) { s->failed_pc=0x0c06a25eu; return 0; }
r[4]=r[10];
goto P_0c06a260;
P_0c06a260: /* original a019, guest PC 0x0c06a260 */
if(!s->budget--) { s->failed_pc=0x0c06a260u; return 0; }
r[6]=0x0000000du;
goto P_0c06a296;
P_0c06a262: /* original e60d, guest PC 0x0c06a262 */
if(!s->budget--) { s->failed_pc=0x0c06a262u; return 0; }
r[6]=0x0000000du;
if(!vf3_matrix_family(0x0c06a264u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a264u; return 0; } return 1;
P_0c06a28c: /* original 6576, guest PC 0x0c06a28c */
if(!s->budget--) { s->failed_pc=0x0c06a28cu; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[5]=tmp;
goto P_0c06a28e;
P_0c06a28e: /* original 3547, guest PC 0x0c06a28e */
if(!s->budget--) { s->failed_pc=0x0c06a28eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[4])!=0);
goto P_0c06a290;
P_0c06a290: /* original 8f01, guest PC 0x0c06a290 */
if(!s->budget--) { s->failed_pc=0x0c06a290u; return 0; }
cond=r[17]&1u;
r[6]+=0xffffffffu;
if(!cond) { goto P_0c06a296; }
goto P_0c06a294;
P_0c06a292: /* original 76ff, guest PC 0x0c06a292 */
if(!s->budget--) { s->failed_pc=0x0c06a292u; return 0; }
r[6]+=0xffffffffu;
goto P_0c06a294;
P_0c06a294: /* original 6453, guest PC 0x0c06a294 */
if(!s->budget--) { s->failed_pc=0x0c06a294u; return 0; }
r[4]=r[5];
goto P_0c06a296;
P_0c06a296: /* original 2668, guest PC 0x0c06a296 */
if(!s->budget--) { s->failed_pc=0x0c06a296u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06a298;
P_0c06a298: /* original 8bf8, guest PC 0x0c06a298 */
if(!s->budget--) { s->failed_pc=0x0c06a298u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a28c; }
goto P_0c06a29a;
P_0c06a29a: /* original 904b, guest PC 0x0c06a29a */
if(!s->budget--) { s->failed_pc=0x0c06a29au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a334u,2);
goto P_0c06a29c;
P_0c06a29c: /* original 0e46, guest PC 0x0c06a29c */
if(!s->budget--) { s->failed_pc=0x0c06a29cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c06a29e;
P_0c06a29e: /* original 53f1, guest PC 0x0c06a29e */
if(!s->budget--) { s->failed_pc=0x0c06a29eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06a2a0;
P_0c06a2a0: /* original 2338, guest PC 0x0c06a2a0 */
if(!s->budget--) { s->failed_pc=0x0c06a2a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06a2a2;
P_0c06a2a2: /* original 8b18, guest PC 0x0c06a2a2 */
if(!s->budget--) { s->failed_pc=0x0c06a2a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a2d6; }
goto P_0c06a2a4;
P_0c06a2a4: /* original 53f5, guest PC 0x0c06a2a4 */
if(!s->budget--) { s->failed_pc=0x0c06a2a4u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c06a2a6;
P_0c06a2a6: /* original 9446, guest PC 0x0c06a2a6 */
if(!s->budget--) { s->failed_pc=0x0c06a2a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a336u,2);
goto P_0c06a2a8;
P_0c06a2a8: /* original 2338, guest PC 0x0c06a2a8 */
if(!s->budget--) { s->failed_pc=0x0c06a2a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06a2aa;
P_0c06a2aa: /* original 8d14, guest PC 0x0c06a2aa */
if(!s->budget--) { s->failed_pc=0x0c06a2aau; return 0; }
cond=r[17]&1u;
r[4]+=r[14];
if(cond) { goto P_0c06a2d6; }
goto P_0c06a2ae;
P_0c06a2ac: /* original 34ec, guest PC 0x0c06a2ac */
if(!s->budget--) { s->failed_pc=0x0c06a2acu; return 0; }
r[4]+=r[14];
goto P_0c06a2ae;
P_0c06a2ae: /* original 60c3, guest PC 0x0c06a2ae */
if(!s->budget--) { s->failed_pc=0x0c06a2aeu; return 0; }
r[0]=r[12];
goto P_0c06a2b0;
P_0c06a2b0: /* original 8801, guest PC 0x0c06a2b0 */
if(!s->budget--) { s->failed_pc=0x0c06a2b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06a2b2;
P_0c06a2b2: /* original 8d0a, guest PC 0x0c06a2b2 */
if(!s->budget--) { s->failed_pc=0x0c06a2b2u; return 0; }
cond=r[17]&1u;
r[5]=r[10];
if(cond) { goto P_0c06a2ca; }
goto P_0c06a2b6;
P_0c06a2b4: /* original 65a3, guest PC 0x0c06a2b4 */
if(!s->budget--) { s->failed_pc=0x0c06a2b4u; return 0; }
r[5]=r[10];
goto P_0c06a2b6;
P_0c06a2b6: /* original e205, guest PC 0x0c06a2b6 */
if(!s->budget--) { s->failed_pc=0x0c06a2b6u; return 0; }
r[2]=0x00000005u;
goto P_0c06a2b8;
P_0c06a2b8: /* original 3c22, guest PC 0x0c06a2b8 */
if(!s->budget--) { s->failed_pc=0x0c06a2b8u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[2])!=0);
goto P_0c06a2ba;
P_0c06a2ba: /* original 8f06, guest PC 0x0c06a2ba */
if(!s->budget--) { s->failed_pc=0x0c06a2bau; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c06a2ca; }
goto P_0c06a2be;
P_0c06a2bc: /* original 7501, guest PC 0x0c06a2bc */
if(!s->budget--) { s->failed_pc=0x0c06a2bcu; return 0; }
r[5]+=0x00000001u;
goto P_0c06a2be;
P_0c06a2be: /* original d31f, guest PC 0x0c06a2be */
if(!s->budget--) { s->failed_pc=0x0c06a2beu; return 0; }
r[3]=read(ram,0x0c06a33cu,4);
goto P_0c06a2c0;
P_0c06a2c0: /* original e00a, guest PC 0x0c06a2c0 */
if(!s->budget--) { s->failed_pc=0x0c06a2c0u; return 0; }
r[0]=0x0000000au;
goto P_0c06a2c2;
P_0c06a2c2: /* original 430b, guest PC 0x0c06a2c2 */
if(!s->budget--) { s->failed_pc=0x0c06a2c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06a2c6u;
r[1]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a2c6u) { target=s->pc; goto dispatch; }
goto P_0c06a2c6;
P_0c06a2c4: /* original 61c3, guest PC 0x0c06a2c4 */
if(!s->budget--) { s->failed_pc=0x0c06a2c4u; return 0; }
r[1]=r[12];
goto P_0c06a2c6;
P_0c06a2c6: /* original 6503, guest PC 0x0c06a2c6 */
if(!s->budget--) { s->failed_pc=0x0c06a2c6u; return 0; }
r[5]=r[0];
goto P_0c06a2c8;
P_0c06a2c8: /* original 7502, guest PC 0x0c06a2c8 */
if(!s->budget--) { s->failed_pc=0x0c06a2c8u; return 0; }
r[5]+=0x00000002u;
goto P_0c06a2ca;
P_0c06a2ca: /* original 4508, guest PC 0x0c06a2ca */
if(!s->budget--) { s->failed_pc=0x0c06a2cau; return 0; }
r[5]<<=2;
goto P_0c06a2cc;
P_0c06a2cc: /* original 345c, guest PC 0x0c06a2cc */
if(!s->budget--) { s->failed_pc=0x0c06a2ccu; return 0; }
r[4]+=r[5];
goto P_0c06a2ce;
P_0c06a2ce: /* original b9fa, guest PC 0x0c06a2ce */
if(!s->budget--) { s->failed_pc=0x0c06a2ceu; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06a2d2u;
r[5]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a2d2u) { target=s->pc; goto dispatch; }
goto P_0c06a2d2;
P_0c06a2d0: /* original e501, guest PC 0x0c06a2d0 */
if(!s->budget--) { s->failed_pc=0x0c06a2d0u; return 0; }
r[5]=0x00000001u;
goto P_0c06a2d2;
P_0c06a2d2: /* original 9030, guest PC 0x0c06a2d2 */
if(!s->budget--) { s->failed_pc=0x0c06a2d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a336u,2);
goto P_0c06a2d4;
P_0c06a2d4: /* original 0d86, guest PC 0x0c06a2d4 */
if(!s->budget--) { s->failed_pc=0x0c06a2d4u; return 0; }
write(ram,r[13]+r[0],r[8],4);
goto P_0c06a2d6;
P_0c06a2d6: /* original 54d2, guest PC 0x0c06a2d6 */
if(!s->budget--) { s->failed_pc=0x0c06a2d6u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c06a2d8;
P_0c06a2d8: /* original e304, guest PC 0x0c06a2d8 */
if(!s->budget--) { s->failed_pc=0x0c06a2d8u; return 0; }
r[3]=0x00000004u;
goto P_0c06a2da;
P_0c06a2da: /* original 2438, guest PC 0x0c06a2da */
if(!s->budget--) { s->failed_pc=0x0c06a2dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06a2dc;
P_0c06a2dc: /* original 8b05, guest PC 0x0c06a2dc */
if(!s->budget--) { s->failed_pc=0x0c06a2dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a2ea; }
goto P_0c06a2de;
P_0c06a2de: /* original d219, guest PC 0x0c06a2de */
if(!s->budget--) { s->failed_pc=0x0c06a2deu; return 0; }
r[2]=read(ram,0x0c06a344u,4);
goto P_0c06a2e0;
P_0c06a2e0: /* original d117, guest PC 0x0c06a2e0 */
if(!s->budget--) { s->failed_pc=0x0c06a2e0u; return 0; }
r[1]=read(ram,0x0c06a340u,4);
goto P_0c06a2e2;
P_0c06a2e2: /* original 53f9, guest PC 0x0c06a2e2 */
if(!s->budget--) { s->failed_pc=0x0c06a2e2u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c06a2e4;
P_0c06a2e4: /* original 6522, guest PC 0x0c06a2e4 */
if(!s->budget--) { s->failed_pc=0x0c06a2e4u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c06a2e6;
P_0c06a2e6: /* original 6412, guest PC 0x0c06a2e6 */
if(!s->budget--) { s->failed_pc=0x0c06a2e6u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c06a2e8;
P_0c06a2e8: /* original 2338, guest PC 0x0c06a2e8 */
if(!s->budget--) { s->failed_pc=0x0c06a2e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06a2ea;
P_0c06a2ea: /* original 9025, guest PC 0x0c06a2ea */
if(!s->budget--) { s->failed_pc=0x0c06a2eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a338u,2);
goto P_0c06a2ec;
P_0c06a2ec: /* original 0da6, guest PC 0x0c06a2ec */
if(!s->budget--) { s->failed_pc=0x0c06a2ecu; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a2ee;
P_0c06a2ee: /* original 7004, guest PC 0x0c06a2ee */
if(!s->budget--) { s->failed_pc=0x0c06a2eeu; return 0; }
r[0]+=0x00000004u;
goto P_0c06a2f0;
P_0c06a2f0: /* original 0da6, guest PC 0x0c06a2f0 */
if(!s->budget--) { s->failed_pc=0x0c06a2f0u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a2f2;
P_0c06a2f2: /* original 7004, guest PC 0x0c06a2f2 */
if(!s->budget--) { s->failed_pc=0x0c06a2f2u; return 0; }
r[0]+=0x00000004u;
goto P_0c06a2f4;
P_0c06a2f4: /* original 0da6, guest PC 0x0c06a2f4 */
if(!s->budget--) { s->failed_pc=0x0c06a2f4u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a2f6;
P_0c06a2f6: /* original 7004, guest PC 0x0c06a2f6 */
if(!s->budget--) { s->failed_pc=0x0c06a2f6u; return 0; }
r[0]+=0x00000004u;
goto P_0c06a2f8;
P_0c06a2f8: /* original 0da6, guest PC 0x0c06a2f8 */
if(!s->budget--) { s->failed_pc=0x0c06a2f8u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a2fa;
P_0c06a2fa: /* original 7004, guest PC 0x0c06a2fa */
if(!s->budget--) { s->failed_pc=0x0c06a2fau; return 0; }
r[0]+=0x00000004u;
goto P_0c06a2fc;
P_0c06a2fc: /* original 0da6, guest PC 0x0c06a2fc */
if(!s->budget--) { s->failed_pc=0x0c06a2fcu; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a2fe;
P_0c06a2fe: /* original 901c, guest PC 0x0c06a2fe */
if(!s->budget--) { s->failed_pc=0x0c06a2feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a33au,2);
goto P_0c06a300;
P_0c06a300: /* original 0da6, guest PC 0x0c06a300 */
if(!s->budget--) { s->failed_pc=0x0c06a300u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a302;
P_0c06a302: /* original 7004, guest PC 0x0c06a302 */
if(!s->budget--) { s->failed_pc=0x0c06a302u; return 0; }
r[0]+=0x00000004u;
goto P_0c06a304;
P_0c06a304: /* original 0da6, guest PC 0x0c06a304 */
if(!s->budget--) { s->failed_pc=0x0c06a304u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a306;
P_0c06a306: /* original 70e0, guest PC 0x0c06a306 */
if(!s->budget--) { s->failed_pc=0x0c06a306u; return 0; }
r[0]+=0xffffffe0u;
goto P_0c06a308;
P_0c06a308: /* original 0da6, guest PC 0x0c06a308 */
if(!s->budget--) { s->failed_pc=0x0c06a308u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a30a;
P_0c06a30a: /* original 7004, guest PC 0x0c06a30a */
if(!s->budget--) { s->failed_pc=0x0c06a30au; return 0; }
r[0]+=0x00000004u;
goto P_0c06a30c;
P_0c06a30c: /* original 0da6, guest PC 0x0c06a30c */
if(!s->budget--) { s->failed_pc=0x0c06a30cu; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a30e;
P_0c06a30e: /* original 7004, guest PC 0x0c06a30e */
if(!s->budget--) { s->failed_pc=0x0c06a30eu; return 0; }
r[0]+=0x00000004u;
goto P_0c06a310;
P_0c06a310: /* original 0da6, guest PC 0x0c06a310 */
if(!s->budget--) { s->failed_pc=0x0c06a310u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a312;
P_0c06a312: /* original 7004, guest PC 0x0c06a312 */
if(!s->budget--) { s->failed_pc=0x0c06a312u; return 0; }
r[0]+=0x00000004u;
goto P_0c06a314;
P_0c06a314: /* original 0da6, guest PC 0x0c06a314 */
if(!s->budget--) { s->failed_pc=0x0c06a314u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a316;
P_0c06a316: /* original 7004, guest PC 0x0c06a316 */
if(!s->budget--) { s->failed_pc=0x0c06a316u; return 0; }
r[0]+=0x00000004u;
goto P_0c06a318;
P_0c06a318: /* original 0da6, guest PC 0x0c06a318 */
if(!s->budget--) { s->failed_pc=0x0c06a318u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a31a;
P_0c06a31a: /* original 7004, guest PC 0x0c06a31a */
if(!s->budget--) { s->failed_pc=0x0c06a31au; return 0; }
r[0]+=0x00000004u;
goto P_0c06a31c;
P_0c06a31c: /* original 0da6, guest PC 0x0c06a31c */
if(!s->budget--) { s->failed_pc=0x0c06a31cu; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c06a31e;
P_0c06a31e: /* original 7f7c, guest PC 0x0c06a31e */
if(!s->budget--) { s->failed_pc=0x0c06a31eu; return 0; }
r[15]+=0x0000007cu;
goto P_0c06a320;
P_0c06a320: /* original 4f16, guest PC 0x0c06a320 */
if(!s->budget--) { s->failed_pc=0x0c06a320u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06a322;
P_0c06a322: /* original 4f26, guest PC 0x0c06a322 */
if(!s->budget--) { s->failed_pc=0x0c06a322u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06a324;
P_0c06a324: /* original 68f6, guest PC 0x0c06a324 */
if(!s->budget--) { s->failed_pc=0x0c06a324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06a326;
P_0c06a326: /* original 69f6, guest PC 0x0c06a326 */
if(!s->budget--) { s->failed_pc=0x0c06a326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06a328;
P_0c06a328: /* original 6af6, guest PC 0x0c06a328 */
if(!s->budget--) { s->failed_pc=0x0c06a328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06a32a;
P_0c06a32a: /* original 6bf6, guest PC 0x0c06a32a */
if(!s->budget--) { s->failed_pc=0x0c06a32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06a32c;
P_0c06a32c: /* original 6cf6, guest PC 0x0c06a32c */
if(!s->budget--) { s->failed_pc=0x0c06a32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06a32e;
P_0c06a32e: /* original 6df6, guest PC 0x0c06a32e */
if(!s->budget--) { s->failed_pc=0x0c06a32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06a330;
P_0c06a330: /* original 000b, guest PC 0x0c06a330 */
if(!s->budget--) { s->failed_pc=0x0c06a330u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06a332: /* original 6ef6, guest PC 0x0c06a332 */
if(!s->budget--) { s->failed_pc=0x0c06a332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06a334u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a334u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
