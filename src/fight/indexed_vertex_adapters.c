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
int vf3_indexed_vertex_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0567e0u: goto P_0c0567e0;
case 0x0c0567e2u: goto P_0c0567e2;
case 0x0c0567e4u: goto P_0c0567e4;
case 0x0c0567e6u: goto P_0c0567e6;
case 0x0c0567e8u: goto P_0c0567e8;
case 0x0c0567eau: goto P_0c0567ea;
case 0x0c0567ecu: goto P_0c0567ec;
case 0x0c0567eeu: goto P_0c0567ee;
case 0x0c0567f0u: goto P_0c0567f0;
case 0x0c0567f2u: goto P_0c0567f2;
case 0x0c0567f4u: goto P_0c0567f4;
case 0x0c0567f6u: goto P_0c0567f6;
case 0x0c0567f8u: goto P_0c0567f8;
case 0x0c0567fau: goto P_0c0567fa;
case 0x0c0567fcu: goto P_0c0567fc;
case 0x0c0567feu: goto P_0c0567fe;
case 0x0c056800u: goto P_0c056800;
case 0x0c056802u: goto P_0c056802;
case 0x0c056804u: goto P_0c056804;
case 0x0c056806u: goto P_0c056806;
case 0x0c056808u: goto P_0c056808;
case 0x0c05680au: goto P_0c05680a;
case 0x0c05680cu: goto P_0c05680c;
case 0x0c05680eu: goto P_0c05680e;
case 0x0c056820u: goto P_0c056820;
case 0x0c056822u: goto P_0c056822;
case 0x0c056824u: goto P_0c056824;
case 0x0c056826u: goto P_0c056826;
case 0x0c056828u: goto P_0c056828;
case 0x0c05682au: goto P_0c05682a;
case 0x0c05682cu: goto P_0c05682c;
case 0x0c05682eu: goto P_0c05682e;
case 0x0c056830u: goto P_0c056830;
case 0x0c056832u: goto P_0c056832;
case 0x0c056834u: goto P_0c056834;
case 0x0c056836u: goto P_0c056836;
case 0x0c056838u: goto P_0c056838;
case 0x0c05683au: goto P_0c05683a;
case 0x0c05683cu: goto P_0c05683c;
case 0x0c05683eu: goto P_0c05683e;
case 0x0c056840u: goto P_0c056840;
case 0x0c056842u: goto P_0c056842;
case 0x0c056844u: goto P_0c056844;
case 0x0c056846u: goto P_0c056846;
case 0x0c056848u: goto P_0c056848;
case 0x0c05684au: goto P_0c05684a;
case 0x0c05684cu: goto P_0c05684c;
case 0x0c05684eu: goto P_0c05684e;
case 0x0c056850u: goto P_0c056850;
case 0x0c056852u: goto P_0c056852;
case 0x0c056860u: goto P_0c056860;
case 0x0c056862u: goto P_0c056862;
case 0x0c056864u: goto P_0c056864;
case 0x0c056866u: goto P_0c056866;
case 0x0c056868u: goto P_0c056868;
case 0x0c05686au: goto P_0c05686a;
case 0x0c05686cu: goto P_0c05686c;
case 0x0c05686eu: goto P_0c05686e;
case 0x0c056870u: goto P_0c056870;
case 0x0c056872u: goto P_0c056872;
case 0x0c056874u: goto P_0c056874;
case 0x0c056876u: goto P_0c056876;
case 0x0c056878u: goto P_0c056878;
case 0x0c05687au: goto P_0c05687a;
case 0x0c05687cu: goto P_0c05687c;
case 0x0c05687eu: goto P_0c05687e;
case 0x0c056880u: goto P_0c056880;
case 0x0c056882u: goto P_0c056882;
case 0x0c056884u: goto P_0c056884;
case 0x0c056886u: goto P_0c056886;
case 0x0c056888u: goto P_0c056888;
case 0x0c05688au: goto P_0c05688a;
case 0x0c05688cu: goto P_0c05688c;
case 0x0c05688eu: goto P_0c05688e;
case 0x0c056890u: goto P_0c056890;
case 0x0c056892u: goto P_0c056892;
case 0x0c056b60u: goto P_0c056b60;
case 0x0c056b62u: goto P_0c056b62;
case 0x0c056b64u: goto P_0c056b64;
case 0x0c056b66u: goto P_0c056b66;
case 0x0c056b68u: goto P_0c056b68;
case 0x0c056b6au: goto P_0c056b6a;
case 0x0c056b6cu: goto P_0c056b6c;
case 0x0c056b6eu: goto P_0c056b6e;
case 0x0c056b70u: goto P_0c056b70;
case 0x0c056b72u: goto P_0c056b72;
case 0x0c056b74u: goto P_0c056b74;
case 0x0c056b76u: goto P_0c056b76;
case 0x0c056b78u: goto P_0c056b78;
case 0x0c056b7au: goto P_0c056b7a;
case 0x0c056b7cu: goto P_0c056b7c;
case 0x0c056b7eu: goto P_0c056b7e;
case 0x0c056b80u: goto P_0c056b80;
case 0x0c056b82u: goto P_0c056b82;
case 0x0c056b84u: goto P_0c056b84;
case 0x0c056b86u: goto P_0c056b86;
case 0x0c056b88u: goto P_0c056b88;
case 0x0c056b8au: goto P_0c056b8a;
case 0x0c056b8cu: goto P_0c056b8c;
case 0x0c056b8eu: goto P_0c056b8e;
case 0x0c056b90u: goto P_0c056b90;
case 0x0c056b92u: goto P_0c056b92;
case 0x0c056b94u: goto P_0c056b94;
case 0x0c056b96u: goto P_0c056b96;
case 0x0c056b98u: goto P_0c056b98;
case 0x0c056b9au: goto P_0c056b9a;
case 0x0c056b9cu: goto P_0c056b9c;
case 0x0c056b9eu: goto P_0c056b9e;
case 0x0c056ba0u: goto P_0c056ba0;
case 0x0c056bc0u: goto P_0c056bc0;
case 0x0c056bc2u: goto P_0c056bc2;
case 0x0c056bc4u: goto P_0c056bc4;
case 0x0c056bc6u: goto P_0c056bc6;
case 0x0c056bc8u: goto P_0c056bc8;
case 0x0c056bcau: goto P_0c056bca;
case 0x0c056bccu: goto P_0c056bcc;
case 0x0c056bceu: goto P_0c056bce;
case 0x0c056bd0u: goto P_0c056bd0;
case 0x0c056bd2u: goto P_0c056bd2;
case 0x0c056bd4u: goto P_0c056bd4;
case 0x0c056bd6u: goto P_0c056bd6;
case 0x0c056bd8u: goto P_0c056bd8;
case 0x0c056bdau: goto P_0c056bda;
case 0x0c056bdcu: goto P_0c056bdc;
case 0x0c056bdeu: goto P_0c056bde;
case 0x0c056be0u: goto P_0c056be0;
case 0x0c056be2u: goto P_0c056be2;
case 0x0c056be4u: goto P_0c056be4;
case 0x0c056be6u: goto P_0c056be6;
case 0x0c056be8u: goto P_0c056be8;
case 0x0c056beau: goto P_0c056bea;
case 0x0c056becu: goto P_0c056bec;
case 0x0c056beeu: goto P_0c056bee;
case 0x0c056bf0u: goto P_0c056bf0;
case 0x0c056bf2u: goto P_0c056bf2;
case 0x0c056bf4u: goto P_0c056bf4;
case 0x0c056bf6u: goto P_0c056bf6;
case 0x0c056bf8u: goto P_0c056bf8;
case 0x0c056bfau: goto P_0c056bfa;
case 0x0c056bfcu: goto P_0c056bfc;
case 0x0c056bfeu: goto P_0c056bfe;
case 0x0c056c00u: goto P_0c056c00;
case 0x0c056c02u: goto P_0c056c02;
case 0x0c056c04u: goto P_0c056c04;
case 0x0c056c20u: goto P_0c056c20;
case 0x0c056c22u: goto P_0c056c22;
case 0x0c056c24u: goto P_0c056c24;
case 0x0c056c26u: goto P_0c056c26;
case 0x0c056c28u: goto P_0c056c28;
case 0x0c056c2au: goto P_0c056c2a;
case 0x0c056c2cu: goto P_0c056c2c;
case 0x0c056c2eu: goto P_0c056c2e;
case 0x0c056c30u: goto P_0c056c30;
case 0x0c056c32u: goto P_0c056c32;
case 0x0c056c34u: goto P_0c056c34;
case 0x0c056c36u: goto P_0c056c36;
case 0x0c056c38u: goto P_0c056c38;
case 0x0c056c3au: goto P_0c056c3a;
case 0x0c056c3cu: goto P_0c056c3c;
case 0x0c056c3eu: goto P_0c056c3e;
case 0x0c056c40u: goto P_0c056c40;
case 0x0c056c42u: goto P_0c056c42;
case 0x0c056c44u: goto P_0c056c44;
case 0x0c056c46u: goto P_0c056c46;
case 0x0c056c48u: goto P_0c056c48;
case 0x0c056c4au: goto P_0c056c4a;
case 0x0c056c4cu: goto P_0c056c4c;
case 0x0c056c4eu: goto P_0c056c4e;
case 0x0c056c50u: goto P_0c056c50;
case 0x0c056c52u: goto P_0c056c52;
case 0x0c056c54u: goto P_0c056c54;
case 0x0c056c56u: goto P_0c056c56;
case 0x0c056c58u: goto P_0c056c58;
case 0x0c056c5au: goto P_0c056c5a;
case 0x0c056c5cu: goto P_0c056c5c;
case 0x0c056c5eu: goto P_0c056c5e;
case 0x0c056c60u: goto P_0c056c60;
case 0x0c056c62u: goto P_0c056c62;
case 0x0c056c64u: goto P_0c056c64;
case 0x0c056c66u: goto P_0c056c66;
case 0x0c056c68u: goto P_0c056c68;
case 0x0c056c6au: goto P_0c056c6a;
case 0x0c056c6cu: goto P_0c056c6c;
case 0x0c056c6eu: goto P_0c056c6e;
case 0x0c056c70u: goto P_0c056c70;
case 0x0c056c72u: goto P_0c056c72;
case 0x0c056c74u: goto P_0c056c74;
case 0x0c056c76u: goto P_0c056c76;
case 0x0c056c78u: goto P_0c056c78;
case 0x0c056c7au: goto P_0c056c7a;
case 0x0c056c7cu: goto P_0c056c7c;
case 0x0c056c7eu: goto P_0c056c7e;
case 0x0c056c80u: goto P_0c056c80;
case 0x0c056c82u: goto P_0c056c82;
case 0x0c056c84u: goto P_0c056c84;
case 0x0c056c86u: goto P_0c056c86;
case 0x0c056c88u: goto P_0c056c88;
case 0x0c056c8au: goto P_0c056c8a;
case 0x0c056c8cu: goto P_0c056c8c;
case 0x0c056c8eu: goto P_0c056c8e;
case 0x0c056c90u: goto P_0c056c90;
case 0x0c056c92u: goto P_0c056c92;
case 0x0c056c94u: goto P_0c056c94;
case 0x0c056c96u: goto P_0c056c96;
case 0x0c056c98u: goto P_0c056c98;
case 0x0c056c9au: goto P_0c056c9a;
case 0x0c056c9cu: goto P_0c056c9c;
case 0x0c056c9eu: goto P_0c056c9e;
case 0x0c056ca0u: goto P_0c056ca0;
case 0x0c056ca2u: goto P_0c056ca2;
case 0x0c056ca4u: goto P_0c056ca4;
case 0x0c056ca6u: goto P_0c056ca6;
case 0x0c056ca8u: goto P_0c056ca8;
case 0x0c056caau: goto P_0c056caa;
case 0x0c056cacu: goto P_0c056cac;
case 0x0c056caeu: goto P_0c056cae;
case 0x0c056cb0u: goto P_0c056cb0;
case 0x0c056cb2u: goto P_0c056cb2;
case 0x0c056cb4u: goto P_0c056cb4;
case 0x0c056cbcu: goto P_0c056cbc;
case 0x0c056cbeu: goto P_0c056cbe;
case 0x0c056cc0u: goto P_0c056cc0;
case 0x0c056cc6u: goto P_0c056cc6;
case 0x0c056cc8u: goto P_0c056cc8;
case 0x0c056ccau: goto P_0c056cca;
case 0x0c056cccu: goto P_0c056ccc;
case 0x0c056cceu: goto P_0c056cce;
case 0x0c056cd0u: goto P_0c056cd0;
case 0x0c056fa0u: goto P_0c056fa0;
case 0x0c056fa2u: goto P_0c056fa2;
case 0x0c056fa4u: goto P_0c056fa4;
case 0x0c056fa6u: goto P_0c056fa6;
case 0x0c056fa8u: goto P_0c056fa8;
case 0x0c056faau: goto P_0c056faa;
case 0x0c056facu: goto P_0c056fac;
case 0x0c056faeu: goto P_0c056fae;
case 0x0c056fb0u: goto P_0c056fb0;
case 0x0c056fb2u: goto P_0c056fb2;
case 0x0c056fb4u: goto P_0c056fb4;
case 0x0c056fb6u: goto P_0c056fb6;
case 0x0c056fb8u: goto P_0c056fb8;
case 0x0c056fbau: goto P_0c056fba;
case 0x0c056fbcu: goto P_0c056fbc;
case 0x0c056fbeu: goto P_0c056fbe;
case 0x0c056fc0u: goto P_0c056fc0;
case 0x0c056fc2u: goto P_0c056fc2;
case 0x0c056fc4u: goto P_0c056fc4;
case 0x0c056fc6u: goto P_0c056fc6;
case 0x0c056fc8u: goto P_0c056fc8;
case 0x0c056fcau: goto P_0c056fca;
case 0x0c056fccu: goto P_0c056fcc;
case 0x0c056fceu: goto P_0c056fce;
case 0x0c056fd0u: goto P_0c056fd0;
case 0x0c056fd2u: goto P_0c056fd2;
case 0x0c056fe0u: goto P_0c056fe0;
case 0x0c056fe2u: goto P_0c056fe2;
case 0x0c056fe4u: goto P_0c056fe4;
case 0x0c056fe6u: goto P_0c056fe6;
case 0x0c056fe8u: goto P_0c056fe8;
case 0x0c056feau: goto P_0c056fea;
case 0x0c056fecu: goto P_0c056fec;
case 0x0c056feeu: goto P_0c056fee;
case 0x0c056ff0u: goto P_0c056ff0;
case 0x0c056ff2u: goto P_0c056ff2;
case 0x0c056ff4u: goto P_0c056ff4;
case 0x0c056ff6u: goto P_0c056ff6;
case 0x0c056ff8u: goto P_0c056ff8;
case 0x0c056ffau: goto P_0c056ffa;
case 0x0c056ffcu: goto P_0c056ffc;
case 0x0c056ffeu: goto P_0c056ffe;
case 0x0c057000u: goto P_0c057000;
case 0x0c057002u: goto P_0c057002;
case 0x0c057004u: goto P_0c057004;
case 0x0c057006u: goto P_0c057006;
case 0x0c057008u: goto P_0c057008;
case 0x0c05700au: goto P_0c05700a;
case 0x0c05700cu: goto P_0c05700c;
case 0x0c05700eu: goto P_0c05700e;
case 0x0c057010u: goto P_0c057010;
case 0x0c057012u: goto P_0c057012;
case 0x0c057014u: goto P_0c057014;
case 0x0c057016u: goto P_0c057016;
case 0x0c057020u: goto P_0c057020;
case 0x0c057022u: goto P_0c057022;
case 0x0c057024u: goto P_0c057024;
case 0x0c057026u: goto P_0c057026;
case 0x0c057028u: goto P_0c057028;
case 0x0c05702au: goto P_0c05702a;
case 0x0c05702cu: goto P_0c05702c;
case 0x0c05702eu: goto P_0c05702e;
case 0x0c057030u: goto P_0c057030;
case 0x0c057032u: goto P_0c057032;
case 0x0c057034u: goto P_0c057034;
case 0x0c057036u: goto P_0c057036;
case 0x0c057038u: goto P_0c057038;
case 0x0c05703au: goto P_0c05703a;
case 0x0c05703cu: goto P_0c05703c;
case 0x0c05703eu: goto P_0c05703e;
case 0x0c057040u: goto P_0c057040;
case 0x0c057042u: goto P_0c057042;
case 0x0c057044u: goto P_0c057044;
case 0x0c057046u: goto P_0c057046;
case 0x0c057048u: goto P_0c057048;
case 0x0c05704au: goto P_0c05704a;
case 0x0c05704cu: goto P_0c05704c;
case 0x0c05704eu: goto P_0c05704e;
case 0x0c057050u: goto P_0c057050;
case 0x0c057052u: goto P_0c057052;
case 0x0c057054u: goto P_0c057054;
case 0x0c057056u: goto P_0c057056;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0567e0: /* original 4f22, guest PC 0x0c0567e0 */
if(!s->budget--) { s->failed_pc=0x0c0567e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0567e2;
P_0c0567e2: /* original 6085, guest PC 0x0c0567e2 */
if(!s->budget--) { s->failed_pc=0x0c0567e2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c0567e4;
P_0c0567e4: /* original 4008, guest PC 0x0c0567e4 */
if(!s->budget--) { s->failed_pc=0x0c0567e4u; return 0; }
r[0]<<=2;
goto P_0c0567e6;
P_0c0567e6: /* original 4000, guest PC 0x0c0567e6 */
if(!s->budget--) { s->failed_pc=0x0c0567e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0567e8;
P_0c0567e8: /* original 011a, guest PC 0x0c0567e8 */
if(!s->budget--) { s->failed_pc=0x0c0567e8u; return 0; }
r[1]=r[19];
goto P_0c0567ea;
P_0c0567ea: /* original f016, guest PC 0x0c0567ea */
if(!s->budget--) { s->failed_pc=0x0c0567eau; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c0567ec;
P_0c0567ec: /* original d308, guest PC 0x0c0567ec */
if(!s->budget--) { s->failed_pc=0x0c0567ecu; return 0; }
r[3]=read(ram,0x0c056810u,4);
goto P_0c0567ee;
P_0c0567ee: /* original 430b, guest PC 0x0c0567ee */
if(!s->budget--) { s->failed_pc=0x0c0567eeu; return 0; }
target=r[3];
r[16]=0x0c0567f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0567f2u) { target=s->pc; goto dispatch; }
goto P_0c0567f2;
P_0c0567f0: /* original 0009, guest PC 0x0c0567f0 */
if(!s->budget--) { s->failed_pc=0x0c0567f0u; return 0; }
goto P_0c0567f2;
P_0c0567f2: /* original 7c10, guest PC 0x0c0567f2 */
if(!s->budget--) { s->failed_pc=0x0c0567f2u; return 0; }
r[12]+=0x00000010u;
goto P_0c0567f4;
P_0c0567f4: /* original 78fe, guest PC 0x0c0567f4 */
if(!s->budget--) { s->failed_pc=0x0c0567f4u; return 0; }
r[8]+=0xfffffffeu;
goto P_0c0567f6;
P_0c0567f6: /* original fc6b, guest PC 0x0c0567f6 */
if(!s->budget--) { s->failed_pc=0x0c0567f6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c0567f8;
P_0c0567f8: /* original fc5b, guest PC 0x0c0567f8 */
if(!s->budget--) { s->failed_pc=0x0c0567f8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c0567fa;
P_0c0567fa: /* original fc4b, guest PC 0x0c0567fa */
if(!s->budget--) { s->failed_pc=0x0c0567fau; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c0567fc;
P_0c0567fc: /* original 2c66, guest PC 0x0c0567fc */
if(!s->budget--) { s->failed_pc=0x0c0567fcu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0567fe;
P_0c0567fe: /* original e000, guest PC 0x0c0567fe */
if(!s->budget--) { s->failed_pc=0x0c0567feu; return 0; }
r[0]=0x00000000u;
goto P_0c056800;
P_0c056800: /* original 1c04, guest PC 0x0c056800 */
if(!s->budget--) { s->failed_pc=0x0c056800u; return 0; }
write(ram,r[12]+16,r[0],4);
goto P_0c056802;
P_0c056802: /* original e018, guest PC 0x0c056802 */
if(!s->budget--) { s->failed_pc=0x0c056802u; return 0; }
r[0]=0x00000018u;
goto P_0c056804;
P_0c056804: /* original fc77, guest PC 0x0c056804 */
if(!s->budget--) { s->failed_pc=0x0c056804u; return 0; }
vf3_matrix_store(s,ram,7,r[12]+r[0]);
goto P_0c056806;
P_0c056806: /* original e01c, guest PC 0x0c056806 */
if(!s->budget--) { s->failed_pc=0x0c056806u; return 0; }
r[0]=0x0000001cu;
goto P_0c056808;
P_0c056808: /* original fc07, guest PC 0x0c056808 */
if(!s->budget--) { s->failed_pc=0x0c056808u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c05680a;
P_0c05680a: /* original 4f26, guest PC 0x0c05680a */
if(!s->budget--) { s->failed_pc=0x0c05680au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05680c;
P_0c05680c: /* original 000b, guest PC 0x0c05680c */
if(!s->budget--) { s->failed_pc=0x0c05680cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05680e: /* original 0009, guest PC 0x0c05680e */
if(!s->budget--) { s->failed_pc=0x0c05680eu; return 0; }
return vf3_matrix_family(0x0c056810u,s,ram);
P_0c056820: /* original 4f22, guest PC 0x0c056820 */
if(!s->budget--) { s->failed_pc=0x0c056820u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c056822;
P_0c056822: /* original 0c83, guest PC 0x0c056822 */
if(!s->budget--) { s->failed_pc=0x0c056822u; return 0; }
goto P_0c056824;
P_0c056824: /* original 7802, guest PC 0x0c056824 */
if(!s->budget--) { s->failed_pc=0x0c056824u; return 0; }
r[8]+=0x00000002u;
goto P_0c056826;
P_0c056826: /* original 6085, guest PC 0x0c056826 */
if(!s->budget--) { s->failed_pc=0x0c056826u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056828;
P_0c056828: /* original 4008, guest PC 0x0c056828 */
if(!s->budget--) { s->failed_pc=0x0c056828u; return 0; }
r[0]<<=2;
goto P_0c05682a;
P_0c05682a: /* original 4000, guest PC 0x0c05682a */
if(!s->budget--) { s->failed_pc=0x0c05682au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05682c;
P_0c05682c: /* original 011a, guest PC 0x0c05682c */
if(!s->budget--) { s->failed_pc=0x0c05682cu; return 0; }
r[1]=r[19];
goto P_0c05682e;
P_0c05682e: /* original f016, guest PC 0x0c05682e */
if(!s->budget--) { s->failed_pc=0x0c05682eu; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c056830;
P_0c056830: /* original d308, guest PC 0x0c056830 */
if(!s->budget--) { s->failed_pc=0x0c056830u; return 0; }
r[3]=read(ram,0x0c056854u,4);
goto P_0c056832;
P_0c056832: /* original 430b, guest PC 0x0c056832 */
if(!s->budget--) { s->failed_pc=0x0c056832u; return 0; }
target=r[3];
r[16]=0x0c056836u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056836u) { target=s->pc; goto dispatch; }
goto P_0c056836;
P_0c056834: /* original 0009, guest PC 0x0c056834 */
if(!s->budget--) { s->failed_pc=0x0c056834u; return 0; }
goto P_0c056836;
P_0c056836: /* original 7c30, guest PC 0x0c056836 */
if(!s->budget--) { s->failed_pc=0x0c056836u; return 0; }
r[12]+=0x00000030u;
goto P_0c056838;
P_0c056838: /* original fcab, guest PC 0x0c056838 */
if(!s->budget--) { s->failed_pc=0x0c056838u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c05683a;
P_0c05683a: /* original fc9b, guest PC 0x0c05683a */
if(!s->budget--) { s->failed_pc=0x0c05683au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c05683c;
P_0c05683c: /* original fc8b, guest PC 0x0c05683c */
if(!s->budget--) { s->failed_pc=0x0c05683cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c05683e;
P_0c05683e: /* original 78fc, guest PC 0x0c05683e */
if(!s->budget--) { s->failed_pc=0x0c05683eu; return 0; }
r[8]+=0xfffffffcu;
goto P_0c056840;
P_0c056840: /* original 2c66, guest PC 0x0c056840 */
if(!s->budget--) { s->failed_pc=0x0c056840u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c056842;
P_0c056842: /* original e000, guest PC 0x0c056842 */
if(!s->budget--) { s->failed_pc=0x0c056842u; return 0; }
r[0]=0x00000000u;
goto P_0c056844;
P_0c056844: /* original 1c04, guest PC 0x0c056844 */
if(!s->budget--) { s->failed_pc=0x0c056844u; return 0; }
write(ram,r[12]+16,r[0],4);
goto P_0c056846;
P_0c056846: /* original e018, guest PC 0x0c056846 */
if(!s->budget--) { s->failed_pc=0x0c056846u; return 0; }
r[0]=0x00000018u;
goto P_0c056848;
P_0c056848: /* original fcb7, guest PC 0x0c056848 */
if(!s->budget--) { s->failed_pc=0x0c056848u; return 0; }
vf3_matrix_store(s,ram,11,r[12]+r[0]);
goto P_0c05684a;
P_0c05684a: /* original e01c, guest PC 0x0c05684a */
if(!s->budget--) { s->failed_pc=0x0c05684au; return 0; }
r[0]=0x0000001cu;
goto P_0c05684c;
P_0c05684c: /* original fc07, guest PC 0x0c05684c */
if(!s->budget--) { s->failed_pc=0x0c05684cu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c05684e;
P_0c05684e: /* original 4f26, guest PC 0x0c05684e */
if(!s->budget--) { s->failed_pc=0x0c05684eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c056850;
P_0c056850: /* original 000b, guest PC 0x0c056850 */
if(!s->budget--) { s->failed_pc=0x0c056850u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c056852: /* original 0009, guest PC 0x0c056852 */
if(!s->budget--) { s->failed_pc=0x0c056852u; return 0; }
return vf3_matrix_family(0x0c056854u,s,ram);
P_0c056860: /* original 4f22, guest PC 0x0c056860 */
if(!s->budget--) { s->failed_pc=0x0c056860u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c056862;
P_0c056862: /* original 0c83, guest PC 0x0c056862 */
if(!s->budget--) { s->failed_pc=0x0c056862u; return 0; }
goto P_0c056864;
P_0c056864: /* original 7804, guest PC 0x0c056864 */
if(!s->budget--) { s->failed_pc=0x0c056864u; return 0; }
r[8]+=0x00000004u;
goto P_0c056866;
P_0c056866: /* original 6085, guest PC 0x0c056866 */
if(!s->budget--) { s->failed_pc=0x0c056866u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056868;
P_0c056868: /* original 4008, guest PC 0x0c056868 */
if(!s->budget--) { s->failed_pc=0x0c056868u; return 0; }
r[0]<<=2;
goto P_0c05686a;
P_0c05686a: /* original 4000, guest PC 0x0c05686a */
if(!s->budget--) { s->failed_pc=0x0c05686au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05686c;
P_0c05686c: /* original 011a, guest PC 0x0c05686c */
if(!s->budget--) { s->failed_pc=0x0c05686cu; return 0; }
r[1]=r[19];
goto P_0c05686e;
P_0c05686e: /* original f016, guest PC 0x0c05686e */
if(!s->budget--) { s->failed_pc=0x0c05686eu; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c056870;
P_0c056870: /* original d308, guest PC 0x0c056870 */
if(!s->budget--) { s->failed_pc=0x0c056870u; return 0; }
r[3]=read(ram,0x0c056894u,4);
goto P_0c056872;
P_0c056872: /* original 430b, guest PC 0x0c056872 */
if(!s->budget--) { s->failed_pc=0x0c056872u; return 0; }
target=r[3];
r[16]=0x0c056876u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056876u) { target=s->pc; goto dispatch; }
goto P_0c056876;
P_0c056874: /* original 0009, guest PC 0x0c056874 */
if(!s->budget--) { s->failed_pc=0x0c056874u; return 0; }
goto P_0c056876;
P_0c056876: /* original 7c30, guest PC 0x0c056876 */
if(!s->budget--) { s->failed_pc=0x0c056876u; return 0; }
r[12]+=0x00000030u;
goto P_0c056878;
P_0c056878: /* original fceb, guest PC 0x0c056878 */
if(!s->budget--) { s->failed_pc=0x0c056878u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c05687a;
P_0c05687a: /* original fcdb, guest PC 0x0c05687a */
if(!s->budget--) { s->failed_pc=0x0c05687au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c05687c;
P_0c05687c: /* original 78fa, guest PC 0x0c05687c */
if(!s->budget--) { s->failed_pc=0x0c05687cu; return 0; }
r[8]+=0xfffffffau;
goto P_0c05687e;
P_0c05687e: /* original fccb, guest PC 0x0c05687e */
if(!s->budget--) { s->failed_pc=0x0c05687eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c056880;
P_0c056880: /* original 2c66, guest PC 0x0c056880 */
if(!s->budget--) { s->failed_pc=0x0c056880u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c056882;
P_0c056882: /* original e000, guest PC 0x0c056882 */
if(!s->budget--) { s->failed_pc=0x0c056882u; return 0; }
r[0]=0x00000000u;
goto P_0c056884;
P_0c056884: /* original 1c04, guest PC 0x0c056884 */
if(!s->budget--) { s->failed_pc=0x0c056884u; return 0; }
write(ram,r[12]+16,r[0],4);
goto P_0c056886;
P_0c056886: /* original e018, guest PC 0x0c056886 */
if(!s->budget--) { s->failed_pc=0x0c056886u; return 0; }
r[0]=0x00000018u;
goto P_0c056888;
P_0c056888: /* original fcf7, guest PC 0x0c056888 */
if(!s->budget--) { s->failed_pc=0x0c056888u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c05688a;
P_0c05688a: /* original e01c, guest PC 0x0c05688a */
if(!s->budget--) { s->failed_pc=0x0c05688au; return 0; }
r[0]=0x0000001cu;
goto P_0c05688c;
P_0c05688c: /* original fc07, guest PC 0x0c05688c */
if(!s->budget--) { s->failed_pc=0x0c05688cu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c05688e;
P_0c05688e: /* original 4f26, guest PC 0x0c05688e */
if(!s->budget--) { s->failed_pc=0x0c05688eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c056890;
P_0c056890: /* original 000b, guest PC 0x0c056890 */
if(!s->budget--) { s->failed_pc=0x0c056890u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c056892: /* original 0009, guest PC 0x0c056892 */
if(!s->budget--) { s->failed_pc=0x0c056892u; return 0; }
return vf3_matrix_family(0x0c056894u,s,ram);
P_0c056b60: /* original 4f22, guest PC 0x0c056b60 */
if(!s->budget--) { s->failed_pc=0x0c056b60u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c056b62;
P_0c056b62: /* original 6085, guest PC 0x0c056b62 */
if(!s->budget--) { s->failed_pc=0x0c056b62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056b64;
P_0c056b64: /* original 4008, guest PC 0x0c056b64 */
if(!s->budget--) { s->failed_pc=0x0c056b64u; return 0; }
r[0]<<=2;
goto P_0c056b66;
P_0c056b66: /* original 4000, guest PC 0x0c056b66 */
if(!s->budget--) { s->failed_pc=0x0c056b66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c056b68;
P_0c056b68: /* original 011a, guest PC 0x0c056b68 */
if(!s->budget--) { s->failed_pc=0x0c056b68u; return 0; }
r[1]=r[19];
goto P_0c056b6a;
P_0c056b6a: /* original f016, guest PC 0x0c056b6a */
if(!s->budget--) { s->failed_pc=0x0c056b6au; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c056b6c;
P_0c056b6c: /* original b07b, guest PC 0x0c056b6c */
if(!s->budget--) { s->failed_pc=0x0c056b6cu; return 0; }
target=0x0c056c66u; r[16]=0x0c056b70u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056b70u) { target=s->pc; goto dispatch; }
goto P_0c056b70;
P_0c056b6e: /* original 0009, guest PC 0x0c056b6e */
if(!s->budget--) { s->failed_pc=0x0c056b6eu; return 0; }
goto P_0c056b70;
P_0c056b70: /* original 6385, guest PC 0x0c056b70 */
if(!s->budget--) { s->failed_pc=0x0c056b70u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c056b72;
P_0c056b72: /* original 6085, guest PC 0x0c056b72 */
if(!s->budget--) { s->failed_pc=0x0c056b72u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056b74;
P_0c056b74: /* original 7c10, guest PC 0x0c056b74 */
if(!s->budget--) { s->failed_pc=0x0c056b74u; return 0; }
r[12]+=0x00000010u;
goto P_0c056b76;
P_0c056b76: /* original 435a, guest PC 0x0c056b76 */
if(!s->budget--) { s->failed_pc=0x0c056b76u; return 0; }
r[53]=r[3];
goto P_0c056b78;
P_0c056b78: /* original 78fa, guest PC 0x0c056b78 */
if(!s->budget--) { s->failed_pc=0x0c056b78u; return 0; }
r[8]+=0xfffffffau;
goto P_0c056b7a;
P_0c056b7a: /* original f22d, guest PC 0x0c056b7a */
if(!s->budget--) { s->failed_pc=0x0c056b7au; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c056b7c;
P_0c056b7c: /* original 405a, guest PC 0x0c056b7c */
if(!s->budget--) { s->failed_pc=0x0c056b7cu; return 0; }
r[53]=r[0];
goto P_0c056b7e;
P_0c056b7e: /* original f12d, guest PC 0x0c056b7e */
if(!s->budget--) { s->failed_pc=0x0c056b7eu; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c056b80;
P_0c056b80: /* original fc6b, guest PC 0x0c056b80 */
if(!s->budget--) { s->failed_pc=0x0c056b80u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c056b82;
P_0c056b82: /* original f232, guest PC 0x0c056b82 */
if(!s->budget--) { s->failed_pc=0x0c056b82u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c056b84;
P_0c056b84: /* original fc5b, guest PC 0x0c056b84 */
if(!s->budget--) { s->failed_pc=0x0c056b84u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c056b86;
P_0c056b86: /* original f132, guest PC 0x0c056b86 */
if(!s->budget--) { s->failed_pc=0x0c056b86u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c056b88;
P_0c056b88: /* original e014, guest PC 0x0c056b88 */
if(!s->budget--) { s->failed_pc=0x0c056b88u; return 0; }
r[0]=0x00000014u;
goto P_0c056b8a;
P_0c056b8a: /* original fc4b, guest PC 0x0c056b8a */
if(!s->budget--) { s->failed_pc=0x0c056b8au; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c056b8c;
P_0c056b8c: /* original 2c66, guest PC 0x0c056b8c */
if(!s->budget--) { s->failed_pc=0x0c056b8cu; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c056b8e;
P_0c056b8e: /* original fc17, guest PC 0x0c056b8e */
if(!s->budget--) { s->failed_pc=0x0c056b8eu; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c056b90;
P_0c056b90: /* original e010, guest PC 0x0c056b90 */
if(!s->budget--) { s->failed_pc=0x0c056b90u; return 0; }
r[0]=0x00000010u;
goto P_0c056b92;
P_0c056b92: /* original fc27, guest PC 0x0c056b92 */
if(!s->budget--) { s->failed_pc=0x0c056b92u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c056b94;
P_0c056b94: /* original e018, guest PC 0x0c056b94 */
if(!s->budget--) { s->failed_pc=0x0c056b94u; return 0; }
r[0]=0x00000018u;
goto P_0c056b96;
P_0c056b96: /* original fc77, guest PC 0x0c056b96 */
if(!s->budget--) { s->failed_pc=0x0c056b96u; return 0; }
vf3_matrix_store(s,ram,7,r[12]+r[0]);
goto P_0c056b98;
P_0c056b98: /* original e01c, guest PC 0x0c056b98 */
if(!s->budget--) { s->failed_pc=0x0c056b98u; return 0; }
r[0]=0x0000001cu;
goto P_0c056b9a;
P_0c056b9a: /* original fc07, guest PC 0x0c056b9a */
if(!s->budget--) { s->failed_pc=0x0c056b9au; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c056b9c;
P_0c056b9c: /* original 4f26, guest PC 0x0c056b9c */
if(!s->budget--) { s->failed_pc=0x0c056b9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c056b9e;
P_0c056b9e: /* original 000b, guest PC 0x0c056b9e */
if(!s->budget--) { s->failed_pc=0x0c056b9eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c056ba0: /* original 0009, guest PC 0x0c056ba0 */
if(!s->budget--) { s->failed_pc=0x0c056ba0u; return 0; }
return vf3_matrix_family(0x0c056ba2u,s,ram);
P_0c056bc0: /* original 4f22, guest PC 0x0c056bc0 */
if(!s->budget--) { s->failed_pc=0x0c056bc0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c056bc2;
P_0c056bc2: /* original 0c83, guest PC 0x0c056bc2 */
if(!s->budget--) { s->failed_pc=0x0c056bc2u; return 0; }
goto P_0c056bc4;
P_0c056bc4: /* original 7806, guest PC 0x0c056bc4 */
if(!s->budget--) { s->failed_pc=0x0c056bc4u; return 0; }
r[8]+=0x00000006u;
goto P_0c056bc6;
P_0c056bc6: /* original 6085, guest PC 0x0c056bc6 */
if(!s->budget--) { s->failed_pc=0x0c056bc6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056bc8;
P_0c056bc8: /* original 4008, guest PC 0x0c056bc8 */
if(!s->budget--) { s->failed_pc=0x0c056bc8u; return 0; }
r[0]<<=2;
goto P_0c056bca;
P_0c056bca: /* original 4000, guest PC 0x0c056bca */
if(!s->budget--) { s->failed_pc=0x0c056bcau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c056bcc;
P_0c056bcc: /* original 011a, guest PC 0x0c056bcc */
if(!s->budget--) { s->failed_pc=0x0c056bccu; return 0; }
r[1]=r[19];
goto P_0c056bce;
P_0c056bce: /* original f016, guest PC 0x0c056bce */
if(!s->budget--) { s->failed_pc=0x0c056bceu; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c056bd0;
P_0c056bd0: /* original b049, guest PC 0x0c056bd0 */
if(!s->budget--) { s->failed_pc=0x0c056bd0u; return 0; }
target=0x0c056c66u; r[16]=0x0c056bd4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056bd4u) { target=s->pc; goto dispatch; }
goto P_0c056bd4;
P_0c056bd2: /* original 0009, guest PC 0x0c056bd2 */
if(!s->budget--) { s->failed_pc=0x0c056bd2u; return 0; }
goto P_0c056bd4;
P_0c056bd4: /* original 6385, guest PC 0x0c056bd4 */
if(!s->budget--) { s->failed_pc=0x0c056bd4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c056bd6;
P_0c056bd6: /* original 6085, guest PC 0x0c056bd6 */
if(!s->budget--) { s->failed_pc=0x0c056bd6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056bd8;
P_0c056bd8: /* original 7c30, guest PC 0x0c056bd8 */
if(!s->budget--) { s->failed_pc=0x0c056bd8u; return 0; }
r[12]+=0x00000030u;
goto P_0c056bda;
P_0c056bda: /* original 405a, guest PC 0x0c056bda */
if(!s->budget--) { s->failed_pc=0x0c056bdau; return 0; }
r[53]=r[0];
goto P_0c056bdc;
P_0c056bdc: /* original f12d, guest PC 0x0c056bdc */
if(!s->budget--) { s->failed_pc=0x0c056bdcu; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c056bde;
P_0c056bde: /* original 435a, guest PC 0x0c056bde */
if(!s->budget--) { s->failed_pc=0x0c056bdeu; return 0; }
r[53]=r[3];
goto P_0c056be0;
P_0c056be0: /* original f22d, guest PC 0x0c056be0 */
if(!s->budget--) { s->failed_pc=0x0c056be0u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c056be2;
P_0c056be2: /* original fcab, guest PC 0x0c056be2 */
if(!s->budget--) { s->failed_pc=0x0c056be2u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c056be4;
P_0c056be4: /* original f132, guest PC 0x0c056be4 */
if(!s->budget--) { s->failed_pc=0x0c056be4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c056be6;
P_0c056be6: /* original f232, guest PC 0x0c056be6 */
if(!s->budget--) { s->failed_pc=0x0c056be6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c056be8;
P_0c056be8: /* original fc9b, guest PC 0x0c056be8 */
if(!s->budget--) { s->failed_pc=0x0c056be8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c056bea;
P_0c056bea: /* original e014, guest PC 0x0c056bea */
if(!s->budget--) { s->failed_pc=0x0c056beau; return 0; }
r[0]=0x00000014u;
goto P_0c056bec;
P_0c056bec: /* original fc8b, guest PC 0x0c056bec */
if(!s->budget--) { s->failed_pc=0x0c056becu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c056bee;
P_0c056bee: /* original 78f4, guest PC 0x0c056bee */
if(!s->budget--) { s->failed_pc=0x0c056beeu; return 0; }
r[8]+=0xfffffff4u;
goto P_0c056bf0;
P_0c056bf0: /* original 2c66, guest PC 0x0c056bf0 */
if(!s->budget--) { s->failed_pc=0x0c056bf0u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c056bf2;
P_0c056bf2: /* original fc17, guest PC 0x0c056bf2 */
if(!s->budget--) { s->failed_pc=0x0c056bf2u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c056bf4;
P_0c056bf4: /* original e010, guest PC 0x0c056bf4 */
if(!s->budget--) { s->failed_pc=0x0c056bf4u; return 0; }
r[0]=0x00000010u;
goto P_0c056bf6;
P_0c056bf6: /* original fc27, guest PC 0x0c056bf6 */
if(!s->budget--) { s->failed_pc=0x0c056bf6u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c056bf8;
P_0c056bf8: /* original e018, guest PC 0x0c056bf8 */
if(!s->budget--) { s->failed_pc=0x0c056bf8u; return 0; }
r[0]=0x00000018u;
goto P_0c056bfa;
P_0c056bfa: /* original fcb7, guest PC 0x0c056bfa */
if(!s->budget--) { s->failed_pc=0x0c056bfau; return 0; }
vf3_matrix_store(s,ram,11,r[12]+r[0]);
goto P_0c056bfc;
P_0c056bfc: /* original e01c, guest PC 0x0c056bfc */
if(!s->budget--) { s->failed_pc=0x0c056bfcu; return 0; }
r[0]=0x0000001cu;
goto P_0c056bfe;
P_0c056bfe: /* original fc07, guest PC 0x0c056bfe */
if(!s->budget--) { s->failed_pc=0x0c056bfeu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c056c00;
P_0c056c00: /* original 4f26, guest PC 0x0c056c00 */
if(!s->budget--) { s->failed_pc=0x0c056c00u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c056c02;
P_0c056c02: /* original 000b, guest PC 0x0c056c02 */
if(!s->budget--) { s->failed_pc=0x0c056c02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c056c04: /* original 0009, guest PC 0x0c056c04 */
if(!s->budget--) { s->failed_pc=0x0c056c04u; return 0; }
return vf3_matrix_family(0x0c056c06u,s,ram);
P_0c056c20: /* original 4f22, guest PC 0x0c056c20 */
if(!s->budget--) { s->failed_pc=0x0c056c20u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c056c22;
P_0c056c22: /* original 0c83, guest PC 0x0c056c22 */
if(!s->budget--) { s->failed_pc=0x0c056c22u; return 0; }
goto P_0c056c24;
P_0c056c24: /* original 780c, guest PC 0x0c056c24 */
if(!s->budget--) { s->failed_pc=0x0c056c24u; return 0; }
r[8]+=0x0000000cu;
goto P_0c056c26;
P_0c056c26: /* original 6085, guest PC 0x0c056c26 */
if(!s->budget--) { s->failed_pc=0x0c056c26u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056c28;
P_0c056c28: /* original 4008, guest PC 0x0c056c28 */
if(!s->budget--) { s->failed_pc=0x0c056c28u; return 0; }
r[0]<<=2;
goto P_0c056c2a;
P_0c056c2a: /* original 4000, guest PC 0x0c056c2a */
if(!s->budget--) { s->failed_pc=0x0c056c2au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c056c2c;
P_0c056c2c: /* original 011a, guest PC 0x0c056c2c */
if(!s->budget--) { s->failed_pc=0x0c056c2cu; return 0; }
r[1]=r[19];
goto P_0c056c2e;
P_0c056c2e: /* original f016, guest PC 0x0c056c2e */
if(!s->budget--) { s->failed_pc=0x0c056c2eu; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c056c30;
P_0c056c30: /* original b019, guest PC 0x0c056c30 */
if(!s->budget--) { s->failed_pc=0x0c056c30u; return 0; }
target=0x0c056c66u; r[16]=0x0c056c34u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056c34u) { target=s->pc; goto dispatch; }
goto P_0c056c34;
P_0c056c32: /* original 0009, guest PC 0x0c056c32 */
if(!s->budget--) { s->failed_pc=0x0c056c32u; return 0; }
goto P_0c056c34;
P_0c056c34: /* original 6385, guest PC 0x0c056c34 */
if(!s->budget--) { s->failed_pc=0x0c056c34u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[3]=tmp;
goto P_0c056c36;
P_0c056c36: /* original 6085, guest PC 0x0c056c36 */
if(!s->budget--) { s->failed_pc=0x0c056c36u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056c38;
P_0c056c38: /* original 7c30, guest PC 0x0c056c38 */
if(!s->budget--) { s->failed_pc=0x0c056c38u; return 0; }
r[12]+=0x00000030u;
goto P_0c056c3a;
P_0c056c3a: /* original 405a, guest PC 0x0c056c3a */
if(!s->budget--) { s->failed_pc=0x0c056c3au; return 0; }
r[53]=r[0];
goto P_0c056c3c;
P_0c056c3c: /* original f12d, guest PC 0x0c056c3c */
if(!s->budget--) { s->failed_pc=0x0c056c3cu; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c056c3e;
P_0c056c3e: /* original 435a, guest PC 0x0c056c3e */
if(!s->budget--) { s->failed_pc=0x0c056c3eu; return 0; }
r[53]=r[3];
goto P_0c056c40;
P_0c056c40: /* original f22d, guest PC 0x0c056c40 */
if(!s->budget--) { s->failed_pc=0x0c056c40u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c056c42;
P_0c056c42: /* original fceb, guest PC 0x0c056c42 */
if(!s->budget--) { s->failed_pc=0x0c056c42u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c056c44;
P_0c056c44: /* original f132, guest PC 0x0c056c44 */
if(!s->budget--) { s->failed_pc=0x0c056c44u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c056c46;
P_0c056c46: /* original f232, guest PC 0x0c056c46 */
if(!s->budget--) { s->failed_pc=0x0c056c46u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c056c48;
P_0c056c48: /* original fcdb, guest PC 0x0c056c48 */
if(!s->budget--) { s->failed_pc=0x0c056c48u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c056c4a;
P_0c056c4a: /* original 78ee, guest PC 0x0c056c4a */
if(!s->budget--) { s->failed_pc=0x0c056c4au; return 0; }
r[8]+=0xffffffeeu;
goto P_0c056c4c;
P_0c056c4c: /* original fccb, guest PC 0x0c056c4c */
if(!s->budget--) { s->failed_pc=0x0c056c4cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c056c4e;
P_0c056c4e: /* original e014, guest PC 0x0c056c4e */
if(!s->budget--) { s->failed_pc=0x0c056c4eu; return 0; }
r[0]=0x00000014u;
goto P_0c056c50;
P_0c056c50: /* original 2c66, guest PC 0x0c056c50 */
if(!s->budget--) { s->failed_pc=0x0c056c50u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c056c52;
P_0c056c52: /* original fc17, guest PC 0x0c056c52 */
if(!s->budget--) { s->failed_pc=0x0c056c52u; return 0; }
vf3_matrix_store(s,ram,1,r[12]+r[0]);
goto P_0c056c54;
P_0c056c54: /* original e010, guest PC 0x0c056c54 */
if(!s->budget--) { s->failed_pc=0x0c056c54u; return 0; }
r[0]=0x00000010u;
goto P_0c056c56;
P_0c056c56: /* original fc27, guest PC 0x0c056c56 */
if(!s->budget--) { s->failed_pc=0x0c056c56u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c056c58;
P_0c056c58: /* original e018, guest PC 0x0c056c58 */
if(!s->budget--) { s->failed_pc=0x0c056c58u; return 0; }
r[0]=0x00000018u;
goto P_0c056c5a;
P_0c056c5a: /* original fcf7, guest PC 0x0c056c5a */
if(!s->budget--) { s->failed_pc=0x0c056c5au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c056c5c;
P_0c056c5c: /* original e01c, guest PC 0x0c056c5c */
if(!s->budget--) { s->failed_pc=0x0c056c5cu; return 0; }
r[0]=0x0000001cu;
goto P_0c056c5e;
P_0c056c5e: /* original fc07, guest PC 0x0c056c5e */
if(!s->budget--) { s->failed_pc=0x0c056c5eu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c056c60;
P_0c056c60: /* original 4f26, guest PC 0x0c056c60 */
if(!s->budget--) { s->failed_pc=0x0c056c60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c056c62;
P_0c056c62: /* original 000b, guest PC 0x0c056c62 */
if(!s->budget--) { s->failed_pc=0x0c056c62u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c056c64: /* original 0009, guest PC 0x0c056c64 */
if(!s->budget--) { s->failed_pc=0x0c056c64u; return 0; }
goto P_0c056c66;
P_0c056c66: /* original f18d, guest PC 0x0c056c66 */
if(!s->budget--) { s->failed_pc=0x0c056c66u; return 0; }
fr[1]=0;
goto P_0c056c68;
P_0c056c68: /* original f015, guest PC 0x0c056c68 */
if(!s->budget--) { s->failed_pc=0x0c056c68u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[1]))!=0);
goto P_0c056c6a;
P_0c056c6a: /* original f002, guest PC 0x0c056c6a */
if(!s->budget--) { s->failed_pc=0x0c056c6au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056c6c;
P_0c056c6c: /* original f19d, guest PC 0x0c056c6c */
if(!s->budget--) { s->failed_pc=0x0c056c6cu; return 0; }
fr[1]=0x3f800000u;
goto P_0c056c6e;
P_0c056c6e: /* original 8b2e, guest PC 0x0c056c6e */
if(!s->budget--) { s->failed_pc=0x0c056c6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c056cce; }
goto P_0c056c70;
P_0c056c70: /* original f000, guest PC 0x0c056c70 */
if(!s->budget--) { s->failed_pc=0x0c056c70u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'+');
goto P_0c056c72;
P_0c056c72: /* original f015, guest PC 0x0c056c72 */
if(!s->budget--) { s->failed_pc=0x0c056c72u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[1]))!=0);
goto P_0c056c74;
P_0c056c74: /* original f011, guest PC 0x0c056c74 */
if(!s->budget--) { s->failed_pc=0x0c056c74u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c056c76;
P_0c056c76: /* original 8b2a, guest PC 0x0c056c76 */
if(!s->budget--) { s->failed_pc=0x0c056c76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c056cce; }
goto P_0c056c78;
P_0c056c78: /* original f002, guest PC 0x0c056c78 */
if(!s->budget--) { s->failed_pc=0x0c056c78u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056c7a;
P_0c056c7a: /* original d00f, guest PC 0x0c056c7a */
if(!s->budget--) { s->failed_pc=0x0c056c7au; return 0; }
r[0]=read(ram,0x0c056cb8u,4);
goto P_0c056c7c;
P_0c056c7c: /* original 6002, guest PC 0x0c056c7c */
if(!s->budget--) { s->failed_pc=0x0c056c7cu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c056c7e;
P_0c056c7e: /* original 0023, guest PC 0x0c056c7e */
if(!s->budget--) { s->failed_pc=0x0c056c7eu; return 0; }
target=r[0]+0x0c056c82u;
vf3_matrix_move(s,1,0);
switch(target&0x1fffffffu) {
case 0x0c056c82u: goto P_0c056c82;
case 0x0c056c86u: goto P_0c056c86;
case 0x0c056c8au: goto P_0c056c8a;
case 0x0c056c8eu: goto P_0c056c8e;
case 0x0c056c92u: goto P_0c056c92;
case 0x0c056c96u: goto P_0c056c96;
case 0x0c056c9au: goto P_0c056c9a;
case 0x0c056c9eu: goto P_0c056c9e;
case 0x0c056ca2u: goto P_0c056ca2;
case 0x0c056ca6u: goto P_0c056ca6;
case 0x0c056caau: goto P_0c056caa;
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
P_0c056c80: /* original f10c, guest PC 0x0c056c80 */
if(!s->budget--) { s->failed_pc=0x0c056c80u; return 0; }
vf3_matrix_move(s,1,0);
goto P_0c056c82;
P_0c056c82: /* original a024, guest PC 0x0c056c82 */
if(!s->budget--) { s->failed_pc=0x0c056c82u; return 0; }
goto P_0c056cce;
P_0c056c84: /* original 0009, guest PC 0x0c056c84 */
if(!s->budget--) { s->failed_pc=0x0c056c84u; return 0; }
goto P_0c056c86;
P_0c056c86: /* original a022, guest PC 0x0c056c86 */
if(!s->budget--) { s->failed_pc=0x0c056c86u; return 0; }
goto P_0c056cce;
P_0c056c88: /* original 0009, guest PC 0x0c056c88 */
if(!s->budget--) { s->failed_pc=0x0c056c88u; return 0; }
goto P_0c056c8a;
P_0c056c8a: /* original a020, guest PC 0x0c056c8a */
if(!s->budget--) { s->failed_pc=0x0c056c8au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056cce;
P_0c056c8c: /* original f002, guest PC 0x0c056c8c */
if(!s->budget--) { s->failed_pc=0x0c056c8cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056c8e;
P_0c056c8e: /* original a016, guest PC 0x0c056c8e */
if(!s->budget--) { s->failed_pc=0x0c056c8eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056cbe;
P_0c056c90: /* original f112, guest PC 0x0c056c90 */
if(!s->budget--) { s->failed_pc=0x0c056c90u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056c92;
P_0c056c92: /* original a01b, guest PC 0x0c056c92 */
if(!s->budget--) { s->failed_pc=0x0c056c92u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056ccc;
P_0c056c94: /* original f002, guest PC 0x0c056c94 */
if(!s->budget--) { s->failed_pc=0x0c056c94u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056c96;
P_0c056c96: /* original a00b, guest PC 0x0c056c96 */
if(!s->budget--) { s->failed_pc=0x0c056c96u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056cb0;
P_0c056c98: /* original f112, guest PC 0x0c056c98 */
if(!s->budget--) { s->failed_pc=0x0c056c98u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056c9a;
P_0c056c9a: /* original a00f, guest PC 0x0c056c9a */
if(!s->budget--) { s->failed_pc=0x0c056c9au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056cbc;
P_0c056c9c: /* original f112, guest PC 0x0c056c9c */
if(!s->budget--) { s->failed_pc=0x0c056c9cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056c9e;
P_0c056c9e: /* original a006, guest PC 0x0c056c9e */
if(!s->budget--) { s->failed_pc=0x0c056c9eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056cae;
P_0c056ca0: /* original f112, guest PC 0x0c056ca0 */
if(!s->budget--) { s->failed_pc=0x0c056ca0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056ca2;
P_0c056ca2: /* original a012, guest PC 0x0c056ca2 */
if(!s->budget--) { s->failed_pc=0x0c056ca2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056cca;
P_0c056ca4: /* original f002, guest PC 0x0c056ca4 */
if(!s->budget--) { s->failed_pc=0x0c056ca4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056ca6;
P_0c056ca6: /* original a00f, guest PC 0x0c056ca6 */
if(!s->budget--) { s->failed_pc=0x0c056ca6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056cc8;
P_0c056ca8: /* original f002, guest PC 0x0c056ca8 */
if(!s->budget--) { s->failed_pc=0x0c056ca8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056caa;
P_0c056caa: /* original a00c, guest PC 0x0c056caa */
if(!s->budget--) { s->failed_pc=0x0c056caau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056cc6;
P_0c056cac: /* original f002, guest PC 0x0c056cac */
if(!s->budget--) { s->failed_pc=0x0c056cacu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056cae;
P_0c056cae: /* original f012, guest PC 0x0c056cae */
if(!s->budget--) { s->failed_pc=0x0c056caeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c056cb0;
P_0c056cb0: /* original f112, guest PC 0x0c056cb0 */
if(!s->budget--) { s->failed_pc=0x0c056cb0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[1],r[18],'*');
goto P_0c056cb2;
P_0c056cb2: /* original a00c, guest PC 0x0c056cb2 */
if(!s->budget--) { s->failed_pc=0x0c056cb2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c056cce;
P_0c056cb4: /* original f012, guest PC 0x0c056cb4 */
if(!s->budget--) { s->failed_pc=0x0c056cb4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
return vf3_matrix_family(0x0c056cb6u,s,ram);
P_0c056cbc: /* original f012, guest PC 0x0c056cbc */
if(!s->budget--) { s->failed_pc=0x0c056cbcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c056cbe;
P_0c056cbe: /* original a006, guest PC 0x0c056cbe */
if(!s->budget--) { s->failed_pc=0x0c056cbeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c056cce;
P_0c056cc0: /* original f012, guest PC 0x0c056cc0 */
if(!s->budget--) { s->failed_pc=0x0c056cc0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
return vf3_matrix_family(0x0c056cc2u,s,ram);
P_0c056cc6: /* original f002, guest PC 0x0c056cc6 */
if(!s->budget--) { s->failed_pc=0x0c056cc6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056cc8;
P_0c056cc8: /* original f002, guest PC 0x0c056cc8 */
if(!s->budget--) { s->failed_pc=0x0c056cc8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056cca;
P_0c056cca: /* original f002, guest PC 0x0c056cca */
if(!s->budget--) { s->failed_pc=0x0c056ccau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056ccc;
P_0c056ccc: /* original f002, guest PC 0x0c056ccc */
if(!s->budget--) { s->failed_pc=0x0c056cccu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[0],r[18],'*');
goto P_0c056cce;
P_0c056cce: /* original 000b, guest PC 0x0c056cce */
if(!s->budget--) { s->failed_pc=0x0c056cceu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c056cd0: /* original 0009, guest PC 0x0c056cd0 */
if(!s->budget--) { s->failed_pc=0x0c056cd0u; return 0; }
return vf3_matrix_family(0x0c056cd2u,s,ram);
P_0c056fa0: /* original 4f22, guest PC 0x0c056fa0 */
if(!s->budget--) { s->failed_pc=0x0c056fa0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c056fa2;
P_0c056fa2: /* original 6085, guest PC 0x0c056fa2 */
if(!s->budget--) { s->failed_pc=0x0c056fa2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056fa4;
P_0c056fa4: /* original 4008, guest PC 0x0c056fa4 */
if(!s->budget--) { s->failed_pc=0x0c056fa4u; return 0; }
r[0]<<=2;
goto P_0c056fa6;
P_0c056fa6: /* original 4000, guest PC 0x0c056fa6 */
if(!s->budget--) { s->failed_pc=0x0c056fa6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c056fa8;
P_0c056fa8: /* original 011a, guest PC 0x0c056fa8 */
if(!s->budget--) { s->failed_pc=0x0c056fa8u; return 0; }
r[1]=r[19];
goto P_0c056faa;
P_0c056faa: /* original f016, guest PC 0x0c056faa */
if(!s->budget--) { s->failed_pc=0x0c056faau; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c056fac;
P_0c056fac: /* original 71fc, guest PC 0x0c056fac */
if(!s->budget--) { s->failed_pc=0x0c056facu; return 0; }
r[1]+=0xfffffffcu;
goto P_0c056fae;
P_0c056fae: /* original f216, guest PC 0x0c056fae */
if(!s->budget--) { s->failed_pc=0x0c056faeu; return 0; }
vf3_matrix_load(s,ram,2,r[1]+r[0]);
goto P_0c056fb0;
P_0c056fb0: /* original d308, guest PC 0x0c056fb0 */
if(!s->budget--) { s->failed_pc=0x0c056fb0u; return 0; }
r[3]=read(ram,0x0c056fd4u,4);
goto P_0c056fb2;
P_0c056fb2: /* original 430b, guest PC 0x0c056fb2 */
if(!s->budget--) { s->failed_pc=0x0c056fb2u; return 0; }
target=r[3];
r[16]=0x0c056fb6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056fb6u) { target=s->pc; goto dispatch; }
goto P_0c056fb6;
P_0c056fb4: /* original 0009, guest PC 0x0c056fb4 */
if(!s->budget--) { s->failed_pc=0x0c056fb4u; return 0; }
goto P_0c056fb6;
P_0c056fb6: /* original 7c10, guest PC 0x0c056fb6 */
if(!s->budget--) { s->failed_pc=0x0c056fb6u; return 0; }
r[12]+=0x00000010u;
goto P_0c056fb8;
P_0c056fb8: /* original 78fe, guest PC 0x0c056fb8 */
if(!s->budget--) { s->failed_pc=0x0c056fb8u; return 0; }
r[8]+=0xfffffffeu;
goto P_0c056fba;
P_0c056fba: /* original fc6b, guest PC 0x0c056fba */
if(!s->budget--) { s->failed_pc=0x0c056fbau; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c056fbc;
P_0c056fbc: /* original fc5b, guest PC 0x0c056fbc */
if(!s->budget--) { s->failed_pc=0x0c056fbcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c056fbe;
P_0c056fbe: /* original fc4b, guest PC 0x0c056fbe */
if(!s->budget--) { s->failed_pc=0x0c056fbeu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[12]);
goto P_0c056fc0;
P_0c056fc0: /* original 2c66, guest PC 0x0c056fc0 */
if(!s->budget--) { s->failed_pc=0x0c056fc0u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c056fc2;
P_0c056fc2: /* original e010, guest PC 0x0c056fc2 */
if(!s->budget--) { s->failed_pc=0x0c056fc2u; return 0; }
r[0]=0x00000010u;
goto P_0c056fc4;
P_0c056fc4: /* original fc27, guest PC 0x0c056fc4 */
if(!s->budget--) { s->failed_pc=0x0c056fc4u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c056fc6;
P_0c056fc6: /* original e018, guest PC 0x0c056fc6 */
if(!s->budget--) { s->failed_pc=0x0c056fc6u; return 0; }
r[0]=0x00000018u;
goto P_0c056fc8;
P_0c056fc8: /* original fc77, guest PC 0x0c056fc8 */
if(!s->budget--) { s->failed_pc=0x0c056fc8u; return 0; }
vf3_matrix_store(s,ram,7,r[12]+r[0]);
goto P_0c056fca;
P_0c056fca: /* original e01c, guest PC 0x0c056fca */
if(!s->budget--) { s->failed_pc=0x0c056fcau; return 0; }
r[0]=0x0000001cu;
goto P_0c056fcc;
P_0c056fcc: /* original fc07, guest PC 0x0c056fcc */
if(!s->budget--) { s->failed_pc=0x0c056fccu; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c056fce;
P_0c056fce: /* original 4f26, guest PC 0x0c056fce */
if(!s->budget--) { s->failed_pc=0x0c056fceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c056fd0;
P_0c056fd0: /* original 000b, guest PC 0x0c056fd0 */
if(!s->budget--) { s->failed_pc=0x0c056fd0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c056fd2: /* original 0009, guest PC 0x0c056fd2 */
if(!s->budget--) { s->failed_pc=0x0c056fd2u; return 0; }
return vf3_matrix_family(0x0c056fd4u,s,ram);
P_0c056fe0: /* original 4f22, guest PC 0x0c056fe0 */
if(!s->budget--) { s->failed_pc=0x0c056fe0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c056fe2;
P_0c056fe2: /* original 0c83, guest PC 0x0c056fe2 */
if(!s->budget--) { s->failed_pc=0x0c056fe2u; return 0; }
goto P_0c056fe4;
P_0c056fe4: /* original 7802, guest PC 0x0c056fe4 */
if(!s->budget--) { s->failed_pc=0x0c056fe4u; return 0; }
r[8]+=0x00000002u;
goto P_0c056fe6;
P_0c056fe6: /* original 6085, guest PC 0x0c056fe6 */
if(!s->budget--) { s->failed_pc=0x0c056fe6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c056fe8;
P_0c056fe8: /* original 4008, guest PC 0x0c056fe8 */
if(!s->budget--) { s->failed_pc=0x0c056fe8u; return 0; }
r[0]<<=2;
goto P_0c056fea;
P_0c056fea: /* original 4000, guest PC 0x0c056fea */
if(!s->budget--) { s->failed_pc=0x0c056feau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c056fec;
P_0c056fec: /* original 011a, guest PC 0x0c056fec */
if(!s->budget--) { s->failed_pc=0x0c056fecu; return 0; }
r[1]=r[19];
goto P_0c056fee;
P_0c056fee: /* original f016, guest PC 0x0c056fee */
if(!s->budget--) { s->failed_pc=0x0c056feeu; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c056ff0;
P_0c056ff0: /* original 71fc, guest PC 0x0c056ff0 */
if(!s->budget--) { s->failed_pc=0x0c056ff0u; return 0; }
r[1]+=0xfffffffcu;
goto P_0c056ff2;
P_0c056ff2: /* original f216, guest PC 0x0c056ff2 */
if(!s->budget--) { s->failed_pc=0x0c056ff2u; return 0; }
vf3_matrix_load(s,ram,2,r[1]+r[0]);
goto P_0c056ff4;
P_0c056ff4: /* original d308, guest PC 0x0c056ff4 */
if(!s->budget--) { s->failed_pc=0x0c056ff4u; return 0; }
r[3]=read(ram,0x0c057018u,4);
goto P_0c056ff6;
P_0c056ff6: /* original 430b, guest PC 0x0c056ff6 */
if(!s->budget--) { s->failed_pc=0x0c056ff6u; return 0; }
target=r[3];
r[16]=0x0c056ffau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c056ffau) { target=s->pc; goto dispatch; }
goto P_0c056ffa;
P_0c056ff8: /* original 0009, guest PC 0x0c056ff8 */
if(!s->budget--) { s->failed_pc=0x0c056ff8u; return 0; }
goto P_0c056ffa;
P_0c056ffa: /* original 7c30, guest PC 0x0c056ffa */
if(!s->budget--) { s->failed_pc=0x0c056ffau; return 0; }
r[12]+=0x00000030u;
goto P_0c056ffc;
P_0c056ffc: /* original fcab, guest PC 0x0c056ffc */
if(!s->budget--) { s->failed_pc=0x0c056ffcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c056ffe;
P_0c056ffe: /* original fc9b, guest PC 0x0c056ffe */
if(!s->budget--) { s->failed_pc=0x0c056ffeu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c057000;
P_0c057000: /* original fc8b, guest PC 0x0c057000 */
if(!s->budget--) { s->failed_pc=0x0c057000u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c057002;
P_0c057002: /* original 78fc, guest PC 0x0c057002 */
if(!s->budget--) { s->failed_pc=0x0c057002u; return 0; }
r[8]+=0xfffffffcu;
goto P_0c057004;
P_0c057004: /* original 2c66, guest PC 0x0c057004 */
if(!s->budget--) { s->failed_pc=0x0c057004u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057006;
P_0c057006: /* original e010, guest PC 0x0c057006 */
if(!s->budget--) { s->failed_pc=0x0c057006u; return 0; }
r[0]=0x00000010u;
goto P_0c057008;
P_0c057008: /* original fc27, guest PC 0x0c057008 */
if(!s->budget--) { s->failed_pc=0x0c057008u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c05700a;
P_0c05700a: /* original e018, guest PC 0x0c05700a */
if(!s->budget--) { s->failed_pc=0x0c05700au; return 0; }
r[0]=0x00000018u;
goto P_0c05700c;
P_0c05700c: /* original fcb7, guest PC 0x0c05700c */
if(!s->budget--) { s->failed_pc=0x0c05700cu; return 0; }
vf3_matrix_store(s,ram,11,r[12]+r[0]);
goto P_0c05700e;
P_0c05700e: /* original e01c, guest PC 0x0c05700e */
if(!s->budget--) { s->failed_pc=0x0c05700eu; return 0; }
r[0]=0x0000001cu;
goto P_0c057010;
P_0c057010: /* original fc07, guest PC 0x0c057010 */
if(!s->budget--) { s->failed_pc=0x0c057010u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c057012;
P_0c057012: /* original 4f26, guest PC 0x0c057012 */
if(!s->budget--) { s->failed_pc=0x0c057012u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c057014;
P_0c057014: /* original 000b, guest PC 0x0c057014 */
if(!s->budget--) { s->failed_pc=0x0c057014u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c057016: /* original 0009, guest PC 0x0c057016 */
if(!s->budget--) { s->failed_pc=0x0c057016u; return 0; }
return vf3_matrix_family(0x0c057018u,s,ram);
P_0c057020: /* original 4f22, guest PC 0x0c057020 */
if(!s->budget--) { s->failed_pc=0x0c057020u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c057022;
P_0c057022: /* original 0c83, guest PC 0x0c057022 */
if(!s->budget--) { s->failed_pc=0x0c057022u; return 0; }
goto P_0c057024;
P_0c057024: /* original 7804, guest PC 0x0c057024 */
if(!s->budget--) { s->failed_pc=0x0c057024u; return 0; }
r[8]+=0x00000004u;
goto P_0c057026;
P_0c057026: /* original 6085, guest PC 0x0c057026 */
if(!s->budget--) { s->failed_pc=0x0c057026u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c057028;
P_0c057028: /* original 4008, guest PC 0x0c057028 */
if(!s->budget--) { s->failed_pc=0x0c057028u; return 0; }
r[0]<<=2;
goto P_0c05702a;
P_0c05702a: /* original 4000, guest PC 0x0c05702a */
if(!s->budget--) { s->failed_pc=0x0c05702au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05702c;
P_0c05702c: /* original 011a, guest PC 0x0c05702c */
if(!s->budget--) { s->failed_pc=0x0c05702cu; return 0; }
r[1]=r[19];
goto P_0c05702e;
P_0c05702e: /* original f016, guest PC 0x0c05702e */
if(!s->budget--) { s->failed_pc=0x0c05702eu; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c057030;
P_0c057030: /* original 71fc, guest PC 0x0c057030 */
if(!s->budget--) { s->failed_pc=0x0c057030u; return 0; }
r[1]+=0xfffffffcu;
goto P_0c057032;
P_0c057032: /* original f216, guest PC 0x0c057032 */
if(!s->budget--) { s->failed_pc=0x0c057032u; return 0; }
vf3_matrix_load(s,ram,2,r[1]+r[0]);
goto P_0c057034;
P_0c057034: /* original d308, guest PC 0x0c057034 */
if(!s->budget--) { s->failed_pc=0x0c057034u; return 0; }
r[3]=read(ram,0x0c057058u,4);
goto P_0c057036;
P_0c057036: /* original 430b, guest PC 0x0c057036 */
if(!s->budget--) { s->failed_pc=0x0c057036u; return 0; }
target=r[3];
r[16]=0x0c05703au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05703au) { target=s->pc; goto dispatch; }
goto P_0c05703a;
P_0c057038: /* original 0009, guest PC 0x0c057038 */
if(!s->budget--) { s->failed_pc=0x0c057038u; return 0; }
goto P_0c05703a;
P_0c05703a: /* original 7c30, guest PC 0x0c05703a */
if(!s->budget--) { s->failed_pc=0x0c05703au; return 0; }
r[12]+=0x00000030u;
goto P_0c05703c;
P_0c05703c: /* original fceb, guest PC 0x0c05703c */
if(!s->budget--) { s->failed_pc=0x0c05703cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c05703e;
P_0c05703e: /* original fcdb, guest PC 0x0c05703e */
if(!s->budget--) { s->failed_pc=0x0c05703eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c057040;
P_0c057040: /* original 78fa, guest PC 0x0c057040 */
if(!s->budget--) { s->failed_pc=0x0c057040u; return 0; }
r[8]+=0xfffffffau;
goto P_0c057042;
P_0c057042: /* original fccb, guest PC 0x0c057042 */
if(!s->budget--) { s->failed_pc=0x0c057042u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c057044;
P_0c057044: /* original 2c66, guest PC 0x0c057044 */
if(!s->budget--) { s->failed_pc=0x0c057044u; return 0; }
tmp=r[6]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c057046;
P_0c057046: /* original e010, guest PC 0x0c057046 */
if(!s->budget--) { s->failed_pc=0x0c057046u; return 0; }
r[0]=0x00000010u;
goto P_0c057048;
P_0c057048: /* original fc27, guest PC 0x0c057048 */
if(!s->budget--) { s->failed_pc=0x0c057048u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c05704a;
P_0c05704a: /* original e018, guest PC 0x0c05704a */
if(!s->budget--) { s->failed_pc=0x0c05704au; return 0; }
r[0]=0x00000018u;
goto P_0c05704c;
P_0c05704c: /* original fcf7, guest PC 0x0c05704c */
if(!s->budget--) { s->failed_pc=0x0c05704cu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c05704e;
P_0c05704e: /* original e01c, guest PC 0x0c05704e */
if(!s->budget--) { s->failed_pc=0x0c05704eu; return 0; }
r[0]=0x0000001cu;
goto P_0c057050;
P_0c057050: /* original fc07, guest PC 0x0c057050 */
if(!s->budget--) { s->failed_pc=0x0c057050u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c057052;
P_0c057052: /* original 4f26, guest PC 0x0c057052 */
if(!s->budget--) { s->failed_pc=0x0c057052u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c057054;
P_0c057054: /* original 000b, guest PC 0x0c057054 */
if(!s->budget--) { s->failed_pc=0x0c057054u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c057056: /* original 0009, guest PC 0x0c057056 */
if(!s->budget--) { s->failed_pc=0x0c057056u; return 0; }
return vf3_matrix_family(0x0c057058u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0567e0u,0x0c0567e2u,0x0c0567e4u,0x0c0567e6u,0x0c0567e8u,0x0c0567eau,0x0c0567ecu,0x0c0567eeu,0x0c0567f0u,0x0c0567f2u,0x0c0567f4u,0x0c0567f6u,0x0c0567f8u,0x0c0567fau,0x0c0567fcu,0x0c0567feu,
0x0c056800u,0x0c056802u,0x0c056804u,0x0c056806u,0x0c056808u,0x0c05680au,0x0c05680cu,0x0c05680eu,0x0c056820u,0x0c056822u,0x0c056824u,0x0c056826u,0x0c056828u,0x0c05682au,0x0c05682cu,0x0c05682eu,
0x0c056830u,0x0c056832u,0x0c056834u,0x0c056836u,0x0c056838u,0x0c05683au,0x0c05683cu,0x0c05683eu,0x0c056840u,0x0c056842u,0x0c056844u,0x0c056846u,0x0c056848u,0x0c05684au,0x0c05684cu,0x0c05684eu,
0x0c056850u,0x0c056852u,0x0c056860u,0x0c056862u,0x0c056864u,0x0c056866u,0x0c056868u,0x0c05686au,0x0c05686cu,0x0c05686eu,0x0c056870u,0x0c056872u,0x0c056874u,0x0c056876u,0x0c056878u,0x0c05687au,
0x0c05687cu,0x0c05687eu,0x0c056880u,0x0c056882u,0x0c056884u,0x0c056886u,0x0c056888u,0x0c05688au,0x0c05688cu,0x0c05688eu,0x0c056890u,0x0c056892u,0x0c056b60u,0x0c056b62u,0x0c056b64u,0x0c056b66u,
0x0c056b68u,0x0c056b6au,0x0c056b6cu,0x0c056b6eu,0x0c056b70u,0x0c056b72u,0x0c056b74u,0x0c056b76u,0x0c056b78u,0x0c056b7au,0x0c056b7cu,0x0c056b7eu,0x0c056b80u,0x0c056b82u,0x0c056b84u,0x0c056b86u,
0x0c056b88u,0x0c056b8au,0x0c056b8cu,0x0c056b8eu,0x0c056b90u,0x0c056b92u,0x0c056b94u,0x0c056b96u,0x0c056b98u,0x0c056b9au,0x0c056b9cu,0x0c056b9eu,0x0c056ba0u,0x0c056bc0u,0x0c056bc2u,0x0c056bc4u,
0x0c056bc6u,0x0c056bc8u,0x0c056bcau,0x0c056bccu,0x0c056bceu,0x0c056bd0u,0x0c056bd2u,0x0c056bd4u,0x0c056bd6u,0x0c056bd8u,0x0c056bdau,0x0c056bdcu,0x0c056bdeu,0x0c056be0u,0x0c056be2u,0x0c056be4u,
0x0c056be6u,0x0c056be8u,0x0c056beau,0x0c056becu,0x0c056beeu,0x0c056bf0u,0x0c056bf2u,0x0c056bf4u,0x0c056bf6u,0x0c056bf8u,0x0c056bfau,0x0c056bfcu,0x0c056bfeu,0x0c056c00u,0x0c056c02u,0x0c056c04u,
0x0c056c20u,0x0c056c22u,0x0c056c24u,0x0c056c26u,0x0c056c28u,0x0c056c2au,0x0c056c2cu,0x0c056c2eu,0x0c056c30u,0x0c056c32u,0x0c056c34u,0x0c056c36u,0x0c056c38u,0x0c056c3au,0x0c056c3cu,0x0c056c3eu,
0x0c056c40u,0x0c056c42u,0x0c056c44u,0x0c056c46u,0x0c056c48u,0x0c056c4au,0x0c056c4cu,0x0c056c4eu,0x0c056c50u,0x0c056c52u,0x0c056c54u,0x0c056c56u,0x0c056c58u,0x0c056c5au,0x0c056c5cu,0x0c056c5eu,
0x0c056c60u,0x0c056c62u,0x0c056c64u,0x0c056c66u,0x0c056c68u,0x0c056c6au,0x0c056c6cu,0x0c056c6eu,0x0c056c70u,0x0c056c72u,0x0c056c74u,0x0c056c76u,0x0c056c78u,0x0c056c7au,0x0c056c7cu,0x0c056c7eu,
0x0c056c80u,0x0c056c82u,0x0c056c84u,0x0c056c86u,0x0c056c88u,0x0c056c8au,0x0c056c8cu,0x0c056c8eu,0x0c056c90u,0x0c056c92u,0x0c056c94u,0x0c056c96u,0x0c056c98u,0x0c056c9au,0x0c056c9cu,0x0c056c9eu,
0x0c056ca0u,0x0c056ca2u,0x0c056ca4u,0x0c056ca6u,0x0c056ca8u,0x0c056caau,0x0c056cacu,0x0c056caeu,0x0c056cb0u,0x0c056cb2u,0x0c056cb4u,0x0c056cbcu,0x0c056cbeu,0x0c056cc0u,0x0c056cc6u,0x0c056cc8u,
0x0c056ccau,0x0c056cccu,0x0c056cceu,0x0c056cd0u,0x0c056fa0u,0x0c056fa2u,0x0c056fa4u,0x0c056fa6u,0x0c056fa8u,0x0c056faau,0x0c056facu,0x0c056faeu,0x0c056fb0u,0x0c056fb2u,0x0c056fb4u,0x0c056fb6u,
0x0c056fb8u,0x0c056fbau,0x0c056fbcu,0x0c056fbeu,0x0c056fc0u,0x0c056fc2u,0x0c056fc4u,0x0c056fc6u,0x0c056fc8u,0x0c056fcau,0x0c056fccu,0x0c056fceu,0x0c056fd0u,0x0c056fd2u,0x0c056fe0u,0x0c056fe2u,
0x0c056fe4u,0x0c056fe6u,0x0c056fe8u,0x0c056feau,0x0c056fecu,0x0c056feeu,0x0c056ff0u,0x0c056ff2u,0x0c056ff4u,0x0c056ff6u,0x0c056ff8u,0x0c056ffau,0x0c056ffcu,0x0c056ffeu,0x0c057000u,0x0c057002u,
0x0c057004u,0x0c057006u,0x0c057008u,0x0c05700au,0x0c05700cu,0x0c05700eu,0x0c057010u,0x0c057012u,0x0c057014u,0x0c057016u,0x0c057020u,0x0c057022u,0x0c057024u,0x0c057026u,0x0c057028u,0x0c05702au,
0x0c05702cu,0x0c05702eu,0x0c057030u,0x0c057032u,0x0c057034u,0x0c057036u,0x0c057038u,0x0c05703au,0x0c05703cu,0x0c05703eu,0x0c057040u,0x0c057042u,0x0c057044u,0x0c057046u,0x0c057048u,0x0c05704au,
0x0c05704cu,0x0c05704eu,0x0c057050u,0x0c057052u,0x0c057054u,0x0c057056u,
};
int vf3_indexed_vertex_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
