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
int vf3_away_batch162_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c0a2b98u: goto P_0c0a2b98;
case 0x0c0a2b9au: goto P_0c0a2b9a;
case 0x0c0a2b9cu: goto P_0c0a2b9c;
case 0x0c0a2b9eu: goto P_0c0a2b9e;
case 0x0c0a2ba0u: goto P_0c0a2ba0;
case 0x0c0a2ba2u: goto P_0c0a2ba2;
case 0x0c0a2ba4u: goto P_0c0a2ba4;
case 0x0c0a2ba6u: goto P_0c0a2ba6;
case 0x0c0a2ba8u: goto P_0c0a2ba8;
case 0x0c0a2baau: goto P_0c0a2baa;
case 0x0c0a2bacu: goto P_0c0a2bac;
case 0x0c0a2baeu: goto P_0c0a2bae;
case 0x0c0a2bb0u: goto P_0c0a2bb0;
case 0x0c0a2bb2u: goto P_0c0a2bb2;
case 0x0c0a2bb4u: goto P_0c0a2bb4;
case 0x0c0a2bb6u: goto P_0c0a2bb6;
case 0x0c0a2bb8u: goto P_0c0a2bb8;
case 0x0c0a2bbau: goto P_0c0a2bba;
case 0x0c0a2bbcu: goto P_0c0a2bbc;
case 0x0c0a2bbeu: goto P_0c0a2bbe;
case 0x0c0a2bc0u: goto P_0c0a2bc0;
case 0x0c0a2bc2u: goto P_0c0a2bc2;
case 0x0c0a2bc4u: goto P_0c0a2bc4;
case 0x0c0a2bc6u: goto P_0c0a2bc6;
case 0x0c0a2bc8u: goto P_0c0a2bc8;
case 0x0c0a2bcau: goto P_0c0a2bca;
case 0x0c0a2bccu: goto P_0c0a2bcc;
case 0x0c0a2bceu: goto P_0c0a2bce;
case 0x0c0a2bd0u: goto P_0c0a2bd0;
case 0x0c0a2bd2u: goto P_0c0a2bd2;
case 0x0c0a2bd4u: goto P_0c0a2bd4;
case 0x0c0a2bd6u: goto P_0c0a2bd6;
case 0x0c0a2bd8u: goto P_0c0a2bd8;
case 0x0c0a2bdau: goto P_0c0a2bda;
case 0x0c0a2bdcu: goto P_0c0a2bdc;
case 0x0c0a2bdeu: goto P_0c0a2bde;
case 0x0c0a2be0u: goto P_0c0a2be0;
case 0x0c0a2be2u: goto P_0c0a2be2;
case 0x0c0a2be4u: goto P_0c0a2be4;
case 0x0c0a2be6u: goto P_0c0a2be6;
case 0x0c0a2be8u: goto P_0c0a2be8;
case 0x0c0a2beau: goto P_0c0a2bea;
case 0x0c0a2becu: goto P_0c0a2bec;
case 0x0c0a2beeu: goto P_0c0a2bee;
case 0x0c0a2bf0u: goto P_0c0a2bf0;
case 0x0c0a2bf2u: goto P_0c0a2bf2;
case 0x0c0a2bf4u: goto P_0c0a2bf4;
case 0x0c0a2bf6u: goto P_0c0a2bf6;
case 0x0c0a2bf8u: goto P_0c0a2bf8;
case 0x0c0a2bfau: goto P_0c0a2bfa;
case 0x0c0a2bfcu: goto P_0c0a2bfc;
case 0x0c0a2bfeu: goto P_0c0a2bfe;
case 0x0c0a2c00u: goto P_0c0a2c00;
case 0x0c0a2c02u: goto P_0c0a2c02;
case 0x0c0a2c04u: goto P_0c0a2c04;
case 0x0c0a2c06u: goto P_0c0a2c06;
case 0x0c0a2c08u: goto P_0c0a2c08;
case 0x0c0a2c0au: goto P_0c0a2c0a;
case 0x0c0a2c0cu: goto P_0c0a2c0c;
case 0x0c0a2c0eu: goto P_0c0a2c0e;
case 0x0c0a2c10u: goto P_0c0a2c10;
case 0x0c0a2c12u: goto P_0c0a2c12;
case 0x0c0a2c14u: goto P_0c0a2c14;
case 0x0c0a2c16u: goto P_0c0a2c16;
case 0x0c0a2c18u: goto P_0c0a2c18;
case 0x0c0a2c1au: goto P_0c0a2c1a;
case 0x0c0a2c1cu: goto P_0c0a2c1c;
case 0x0c0a2c1eu: goto P_0c0a2c1e;
case 0x0c0a2c20u: goto P_0c0a2c20;
case 0x0c0a2c22u: goto P_0c0a2c22;
case 0x0c0a2c24u: goto P_0c0a2c24;
case 0x0c0a2c26u: goto P_0c0a2c26;
case 0x0c0a2c28u: goto P_0c0a2c28;
case 0x0c0a2c2au: goto P_0c0a2c2a;
case 0x0c0a2c2cu: goto P_0c0a2c2c;
case 0x0c0a2c2eu: goto P_0c0a2c2e;
case 0x0c0a2c30u: goto P_0c0a2c30;
case 0x0c0a2c32u: goto P_0c0a2c32;
case 0x0c0a2c34u: goto P_0c0a2c34;
case 0x0c0a2e86u: goto P_0c0a2e86;
case 0x0c0a2e88u: goto P_0c0a2e88;
case 0x0c0a2e8au: goto P_0c0a2e8a;
case 0x0c0a2e8cu: goto P_0c0a2e8c;
case 0x0c0a2e8eu: goto P_0c0a2e8e;
case 0x0c0a2e90u: goto P_0c0a2e90;
case 0x0c0a2e92u: goto P_0c0a2e92;
case 0x0c0a2e94u: goto P_0c0a2e94;
case 0x0c0a2e96u: goto P_0c0a2e96;
case 0x0c0a2e98u: goto P_0c0a2e98;
case 0x0c0a2e9au: goto P_0c0a2e9a;
case 0x0c0a2e9cu: goto P_0c0a2e9c;
case 0x0c0a2e9eu: goto P_0c0a2e9e;
case 0x0c0a2ea0u: goto P_0c0a2ea0;
case 0x0c0a2ea2u: goto P_0c0a2ea2;
case 0x0c0a2ea4u: goto P_0c0a2ea4;
case 0x0c0a2ea6u: goto P_0c0a2ea6;
case 0x0c0a2ea8u: goto P_0c0a2ea8;
case 0x0c0a2eaau: goto P_0c0a2eaa;
case 0x0c0a2eacu: goto P_0c0a2eac;
case 0x0c0a2eaeu: goto P_0c0a2eae;
case 0x0c0a2eb0u: goto P_0c0a2eb0;
case 0x0c0a2eb2u: goto P_0c0a2eb2;
case 0x0c0a2eb4u: goto P_0c0a2eb4;
case 0x0c0a2eb6u: goto P_0c0a2eb6;
case 0x0c0a2eb8u: goto P_0c0a2eb8;
case 0x0c0a2ebau: goto P_0c0a2eba;
case 0x0c0a2ebcu: goto P_0c0a2ebc;
case 0x0c0a2ebeu: goto P_0c0a2ebe;
case 0x0c0a2ec0u: goto P_0c0a2ec0;
case 0x0c0a2ec2u: goto P_0c0a2ec2;
case 0x0c0a2ec4u: goto P_0c0a2ec4;
case 0x0c0a2ec6u: goto P_0c0a2ec6;
case 0x0c0a2ec8u: goto P_0c0a2ec8;
case 0x0c0a2ecau: goto P_0c0a2eca;
case 0x0c0a2eccu: goto P_0c0a2ecc;
case 0x0c0a2eceu: goto P_0c0a2ece;
case 0x0c0a2ed0u: goto P_0c0a2ed0;
case 0x0c0c124eu: goto P_0c0c124e;
case 0x0c0c1250u: goto P_0c0c1250;
case 0x0c0c1252u: goto P_0c0c1252;
case 0x0c0c1254u: goto P_0c0c1254;
case 0x0c0c1256u: goto P_0c0c1256;
case 0x0c0c1258u: goto P_0c0c1258;
case 0x0c0c125au: goto P_0c0c125a;
case 0x0c0c125cu: goto P_0c0c125c;
case 0x0c0c125eu: goto P_0c0c125e;
case 0x0c0c1260u: goto P_0c0c1260;
case 0x0c0c1262u: goto P_0c0c1262;
case 0x0c0c1264u: goto P_0c0c1264;
case 0x0c0c1266u: goto P_0c0c1266;
case 0x0c0c1268u: goto P_0c0c1268;
case 0x0c0c126au: goto P_0c0c126a;
case 0x0c0c126cu: goto P_0c0c126c;
case 0x0c0c126eu: goto P_0c0c126e;
case 0x0c0c1270u: goto P_0c0c1270;
case 0x0c0c1272u: goto P_0c0c1272;
case 0x0c0c1274u: goto P_0c0c1274;
case 0x0c0c1276u: goto P_0c0c1276;
case 0x0c0c1278u: goto P_0c0c1278;
case 0x0c0c127au: goto P_0c0c127a;
case 0x0c0c127cu: goto P_0c0c127c;
case 0x0c0c127eu: goto P_0c0c127e;
case 0x0c0c1280u: goto P_0c0c1280;
case 0x0c0c1282u: goto P_0c0c1282;
case 0x0c0c1284u: goto P_0c0c1284;
case 0x0c0c1286u: goto P_0c0c1286;
case 0x0c0c1288u: goto P_0c0c1288;
case 0x0c0c128au: goto P_0c0c128a;
case 0x0c0c128cu: goto P_0c0c128c;
case 0x0c0c128eu: goto P_0c0c128e;
case 0x0c0c1290u: goto P_0c0c1290;
case 0x0c0c1292u: goto P_0c0c1292;
case 0x0c0c1294u: goto P_0c0c1294;
case 0x0c0c1296u: goto P_0c0c1296;
case 0x0c0c1298u: goto P_0c0c1298;
case 0x0c0c129au: goto P_0c0c129a;
case 0x0c0c129cu: goto P_0c0c129c;
case 0x0c0c129eu: goto P_0c0c129e;
case 0x0c0c12a0u: goto P_0c0c12a0;
case 0x0c0c12a2u: goto P_0c0c12a2;
case 0x0c0c12a4u: goto P_0c0c12a4;
case 0x0c0c12a6u: goto P_0c0c12a6;
case 0x0c0c12a8u: goto P_0c0c12a8;
case 0x0c0c12aau: goto P_0c0c12aa;
case 0x0c0c12acu: goto P_0c0c12ac;
case 0x0c0c12aeu: goto P_0c0c12ae;
case 0x0c0c12b0u: goto P_0c0c12b0;
case 0x0c0c12b2u: goto P_0c0c12b2;
case 0x0c0c12b4u: goto P_0c0c12b4;
case 0x0c0c12b6u: goto P_0c0c12b6;
case 0x0c0c12b8u: goto P_0c0c12b8;
case 0x0c0c12bau: goto P_0c0c12ba;
case 0x0c0c12bcu: goto P_0c0c12bc;
case 0x0c0c12beu: goto P_0c0c12be;
case 0x0c0c12c0u: goto P_0c0c12c0;
case 0x0c0c12c2u: goto P_0c0c12c2;
case 0x0c0c12c4u: goto P_0c0c12c4;
case 0x0c0c12c6u: goto P_0c0c12c6;
case 0x0c0c12c8u: goto P_0c0c12c8;
case 0x0c0c12cau: goto P_0c0c12ca;
case 0x0c0c12ccu: goto P_0c0c12cc;
case 0x0c0c12ceu: goto P_0c0c12ce;
case 0x0c0c12d0u: goto P_0c0c12d0;
case 0x0c0c12d2u: goto P_0c0c12d2;
case 0x0c0c12d4u: goto P_0c0c12d4;
case 0x0c0c12d6u: goto P_0c0c12d6;
case 0x0c0c2d06u: goto P_0c0c2d06;
case 0x0c0c2d08u: goto P_0c0c2d08;
case 0x0c0c2d0au: goto P_0c0c2d0a;
case 0x0c0c2d0cu: goto P_0c0c2d0c;
case 0x0c0c2d0eu: goto P_0c0c2d0e;
case 0x0c0c2d10u: goto P_0c0c2d10;
case 0x0c0c2d12u: goto P_0c0c2d12;
case 0x0c0c2d14u: goto P_0c0c2d14;
case 0x0c0c2d16u: goto P_0c0c2d16;
case 0x0c0c2d18u: goto P_0c0c2d18;
case 0x0c0c2d1au: goto P_0c0c2d1a;
case 0x0c0c2d1cu: goto P_0c0c2d1c;
case 0x0c0c2d1eu: goto P_0c0c2d1e;
case 0x0c0c2d20u: goto P_0c0c2d20;
case 0x0c0c2d22u: goto P_0c0c2d22;
case 0x0c0c2d24u: goto P_0c0c2d24;
case 0x0c0c2d26u: goto P_0c0c2d26;
case 0x0c0c2d28u: goto P_0c0c2d28;
case 0x0c0c2d2au: goto P_0c0c2d2a;
case 0x0c0c2d2cu: goto P_0c0c2d2c;
case 0x0c0c2d2eu: goto P_0c0c2d2e;
case 0x0c0c2d30u: goto P_0c0c2d30;
case 0x0c0c2d32u: goto P_0c0c2d32;
case 0x0c0c2d34u: goto P_0c0c2d34;
case 0x0c0c2d36u: goto P_0c0c2d36;
case 0x0c0c2d38u: goto P_0c0c2d38;
case 0x0c0c2d3au: goto P_0c0c2d3a;
case 0x0c0c2d3cu: goto P_0c0c2d3c;
case 0x0c0c2d3eu: goto P_0c0c2d3e;
case 0x0c0c2d40u: goto P_0c0c2d40;
case 0x0c0c2d42u: goto P_0c0c2d42;
case 0x0c0c2d44u: goto P_0c0c2d44;
case 0x0c0c2d46u: goto P_0c0c2d46;
case 0x0c0c2d48u: goto P_0c0c2d48;
case 0x0c0c2d4au: goto P_0c0c2d4a;
case 0x0c0c2d4cu: goto P_0c0c2d4c;
case 0x0c0c2d4eu: goto P_0c0c2d4e;
case 0x0c0c2d50u: goto P_0c0c2d50;
case 0x0c0c2d52u: goto P_0c0c2d52;
case 0x0c0c2d54u: goto P_0c0c2d54;
case 0x0c0c2d56u: goto P_0c0c2d56;
case 0x0c0c2d58u: goto P_0c0c2d58;
case 0x0c0c2d5au: goto P_0c0c2d5a;
case 0x0c0c2d5cu: goto P_0c0c2d5c;
case 0x0c0c2d5eu: goto P_0c0c2d5e;
case 0x0c0c2d60u: goto P_0c0c2d60;
case 0x0c0c2d62u: goto P_0c0c2d62;
case 0x0c0c2d64u: goto P_0c0c2d64;
case 0x0c0c2d66u: goto P_0c0c2d66;
case 0x0c0c2d68u: goto P_0c0c2d68;
case 0x0c0c2d6au: goto P_0c0c2d6a;
case 0x0c0c2d6cu: goto P_0c0c2d6c;
case 0x0c0c2d6eu: goto P_0c0c2d6e;
case 0x0c0c2d70u: goto P_0c0c2d70;
case 0x0c0c2d72u: goto P_0c0c2d72;
case 0x0c0c2d74u: goto P_0c0c2d74;
case 0x0c0c2d76u: goto P_0c0c2d76;
case 0x0c0c2d78u: goto P_0c0c2d78;
case 0x0c0c2d7au: goto P_0c0c2d7a;
case 0x0c0c2d7cu: goto P_0c0c2d7c;
case 0x0c0c2d7eu: goto P_0c0c2d7e;
case 0x0c0c2d80u: goto P_0c0c2d80;
case 0x0c0c2d82u: goto P_0c0c2d82;
case 0x0c0c2d84u: goto P_0c0c2d84;
case 0x0c0c2d86u: goto P_0c0c2d86;
case 0x0c0c2dccu: goto P_0c0c2dcc;
case 0x0c0c2dceu: goto P_0c0c2dce;
case 0x0c0c2dd0u: goto P_0c0c2dd0;
case 0x0c0c2dd2u: goto P_0c0c2dd2;
case 0x0c0c2dd4u: goto P_0c0c2dd4;
case 0x0c0c2dd6u: goto P_0c0c2dd6;
case 0x0c0c2dd8u: goto P_0c0c2dd8;
case 0x0c0c2ddau: goto P_0c0c2dda;
case 0x0c0c2ddcu: goto P_0c0c2ddc;
case 0x0c0c2ddeu: goto P_0c0c2dde;
case 0x0c0c2de0u: goto P_0c0c2de0;
case 0x0c0c2de2u: goto P_0c0c2de2;
case 0x0c0c2de4u: goto P_0c0c2de4;
case 0x0c0c2de6u: goto P_0c0c2de6;
case 0x0c0c2de8u: goto P_0c0c2de8;
case 0x0c0c2deau: goto P_0c0c2dea;
case 0x0c0c2decu: goto P_0c0c2dec;
case 0x0c0c2deeu: goto P_0c0c2dee;
case 0x0c0c2df0u: goto P_0c0c2df0;
case 0x0c0c2df2u: goto P_0c0c2df2;
case 0x0c0c2df4u: goto P_0c0c2df4;
case 0x0c0c2df6u: goto P_0c0c2df6;
case 0x0c0c2df8u: goto P_0c0c2df8;
case 0x0c0c2dfau: goto P_0c0c2dfa;
case 0x0c0c2dfcu: goto P_0c0c2dfc;
case 0x0c0c2dfeu: goto P_0c0c2dfe;
case 0x0c0c2e00u: goto P_0c0c2e00;
case 0x0c0c2e02u: goto P_0c0c2e02;
case 0x0c0c2e04u: goto P_0c0c2e04;
case 0x0c0c2e06u: goto P_0c0c2e06;
case 0x0c0c2e08u: goto P_0c0c2e08;
case 0x0c0c2e0au: goto P_0c0c2e0a;
case 0x0c0c2e0cu: goto P_0c0c2e0c;
case 0x0c0c2e0eu: goto P_0c0c2e0e;
case 0x0c0c2e10u: goto P_0c0c2e10;
case 0x0c0c2e12u: goto P_0c0c2e12;
case 0x0c0c2e14u: goto P_0c0c2e14;
case 0x0c0c2e16u: goto P_0c0c2e16;
case 0x0c0c2e18u: goto P_0c0c2e18;
case 0x0c0c2e1au: goto P_0c0c2e1a;
case 0x0c0c2e1cu: goto P_0c0c2e1c;
case 0x0c0c2e1eu: goto P_0c0c2e1e;
case 0x0c0c2e20u: goto P_0c0c2e20;
case 0x0c0c2e22u: goto P_0c0c2e22;
case 0x0c0c2e24u: goto P_0c0c2e24;
case 0x0c0c2e26u: goto P_0c0c2e26;
case 0x0c0c2e28u: goto P_0c0c2e28;
case 0x0c0c2e2au: goto P_0c0c2e2a;
case 0x0c0c2e2cu: goto P_0c0c2e2c;
case 0x0c0c2e2eu: goto P_0c0c2e2e;
case 0x0c0c2e30u: goto P_0c0c2e30;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c0a2b98: /* original 2fe6, guest PC 0x0c0a2b98 */
if(!s->budget--) { s->failed_pc=0x0c0a2b98u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9a;
P_0c0a2b9a: /* original 6e43, guest PC 0x0c0a2b9a */
if(!s->budget--) { s->failed_pc=0x0c0a2b9au; return 0; }
r[14]=r[4];
goto P_0c0a2b9c;
P_0c0a2b9c: /* original 2fd6, guest PC 0x0c0a2b9c */
if(!s->budget--) { s->failed_pc=0x0c0a2b9cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9e;
P_0c0a2b9e: /* original 2fc6, guest PC 0x0c0a2b9e */
if(!s->budget--) { s->failed_pc=0x0c0a2b9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba0;
P_0c0a2ba0: /* original 2fb6, guest PC 0x0c0a2ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba2;
P_0c0a2ba2: /* original 2fa6, guest PC 0x0c0a2ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba4;
P_0c0a2ba4: /* original 2f96, guest PC 0x0c0a2ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba6;
P_0c0a2ba6: /* original 2f86, guest PC 0x0c0a2ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba8;
P_0c0a2ba8: /* original 60e2, guest PC 0x0c0a2ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a2baa;
P_0c0a2baa: /* original 4f22, guest PC 0x0c0a2baa */
if(!s->budget--) { s->failed_pc=0x0c0a2baau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2bac;
P_0c0a2bac: /* original c880, guest PC 0x0c0a2bac */
if(!s->budget--) { s->failed_pc=0x0c0a2bacu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2bae;
P_0c0a2bae: /* original 8938, guest PC 0x0c0a2bae */
if(!s->budget--) { s->failed_pc=0x0c0a2baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bb0;
P_0c0a2bb0: /* original 62e2, guest PC 0x0c0a2bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a2bb2;
P_0c0a2bb2: /* original d33b, guest PC 0x0c0a2bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb2u; return 0; }
r[3]=read(ram,0x0c0a2ca0u,4);
goto P_0c0a2bb4;
P_0c0a2bb4: /* original 9173, guest PC 0x0c0a2bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2c9eu,2);
goto P_0c0a2bb6;
P_0c0a2bb6: /* original 2239, guest PC 0x0c0a2bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb6u; return 0; }
r[2]&=r[3];
goto P_0c0a2bb8;
P_0c0a2bb8: /* original 3210, guest PC 0x0c0a2bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a2bba;
P_0c0a2bba: /* original 8905, guest PC 0x0c0a2bba */
if(!s->budget--) { s->failed_pc=0x0c0a2bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2bc8; }
goto P_0c0a2bbc;
P_0c0a2bbc: /* original d239, guest PC 0x0c0a2bbc */
if(!s->budget--) { s->failed_pc=0x0c0a2bbcu; return 0; }
r[2]=read(ram,0x0c0a2ca4u,4);
goto P_0c0a2bbe;
P_0c0a2bbe: /* original e56a, guest PC 0x0c0a2bbe */
if(!s->budget--) { s->failed_pc=0x0c0a2bbeu; return 0; }
r[5]=0x0000006au;
goto P_0c0a2bc0;
P_0c0a2bc0: /* original 420b, guest PC 0x0c0a2bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2bc4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2bc4u) { target=s->pc; goto dispatch; }
goto P_0c0a2bc4;
P_0c0a2bc2: /* original e401, guest PC 0x0c0a2bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2bc4;
P_0c0a2bc4: /* original a02e, guest PC 0x0c0a2bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2c24;
P_0c0a2bc6: /* original e0ff, guest PC 0x0c0a2bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2bc8;
P_0c0a2bc8: /* original e020, guest PC 0x0c0a2bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc8u; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bca;
P_0c0a2bca: /* original 03ed, guest PC 0x0c0a2bca */
if(!s->budget--) { s->failed_pc=0x0c0a2bcau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bcc;
P_0c0a2bcc: /* original e022, guest PC 0x0c0a2bcc */
if(!s->budget--) { s->failed_pc=0x0c0a2bccu; return 0; }
r[0]=0x00000022u;
goto P_0c0a2bce;
P_0c0a2bce: /* original 02ed, guest PC 0x0c0a2bce */
if(!s->budget--) { s->failed_pc=0x0c0a2bceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bd0;
P_0c0a2bd0: /* original 633d, guest PC 0x0c0a2bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2bd2;
P_0c0a2bd2: /* original 622d, guest PC 0x0c0a2bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd2u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2bd4;
P_0c0a2bd4: /* original 232b, guest PC 0x0c0a2bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd4u; return 0; }
r[3]|=r[2];
goto P_0c0a2bd6;
P_0c0a2bd6: /* original 2338, guest PC 0x0c0a2bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2bd8;
P_0c0a2bd8: /* original 8923, guest PC 0x0c0a2bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bda;
P_0c0a2bda: /* original e020, guest PC 0x0c0a2bda */
if(!s->budget--) { s->failed_pc=0x0c0a2bdau; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bdc;
P_0c0a2bdc: /* original d332, guest PC 0x0c0a2bdc */
if(!s->budget--) { s->failed_pc=0x0c0a2bdcu; return 0; }
r[3]=read(ram,0x0c0a2ca8u,4);
goto P_0c0a2bde;
P_0c0a2bde: /* original 04ed, guest PC 0x0c0a2bde */
if(!s->budget--) { s->failed_pc=0x0c0a2bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2be0;
P_0c0a2be0: /* original 430b, guest PC 0x0c0a2be0 */
if(!s->budget--) { s->failed_pc=0x0c0a2be0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2be4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2be4u) { target=s->pc; goto dispatch; }
goto P_0c0a2be4;
P_0c0a2be2: /* original 644d, guest PC 0x0c0a2be2 */
if(!s->budget--) { s->failed_pc=0x0c0a2be2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2be4;
P_0c0a2be4: /* original d932, guest PC 0x0c0a2be4 */
if(!s->budget--) { s->failed_pc=0x0c0a2be4u; return 0; }
r[9]=read(ram,0x0c0a2cb0u,4);
goto P_0c0a2be6;
P_0c0a2be6: /* original eb01, guest PC 0x0c0a2be6 */
if(!s->budget--) { s->failed_pc=0x0c0a2be6u; return 0; }
r[11]=0x00000001u;
goto P_0c0a2be8;
P_0c0a2be8: /* original d830, guest PC 0x0c0a2be8 */
if(!s->budget--) { s->failed_pc=0x0c0a2be8u; return 0; }
r[8]=read(ram,0x0c0a2cacu,4);
goto P_0c0a2bea;
P_0c0a2bea: /* original 5ae4, guest PC 0x0c0a2bea */
if(!s->budget--) { s->failed_pc=0x0c0a2beau; return 0; }
r[10]=read(ram,r[14]+16,4);
goto P_0c0a2bec;
P_0c0a2bec: /* original a010, guest PC 0x0c0a2bec */
if(!s->budget--) { s->failed_pc=0x0c0a2becu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2c10;
P_0c0a2bee: /* original ec00, guest PC 0x0c0a2bee */
if(!s->budget--) { s->failed_pc=0x0c0a2beeu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2bf0;
P_0c0a2bf0: /* original 6dc3, guest PC 0x0c0a2bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf0u; return 0; }
r[13]=r[12];
goto P_0c0a2bf2;
P_0c0a2bf2: /* original 4d08, guest PC 0x0c0a2bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf2u; return 0; }
r[13]<<=2;
goto P_0c0a2bf4;
P_0c0a2bf4: /* original 3dac, guest PC 0x0c0a2bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf4u; return 0; }
r[13]+=r[10];
goto P_0c0a2bf6;
P_0c0a2bf6: /* original 63d2, guest PC 0x0c0a2bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0a2bf8;
P_0c0a2bf8: /* original 5231, guest PC 0x0c0a2bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2bfa;
P_0c0a2bfa: /* original 22b8, guest PC 0x0c0a2bfa */
if(!s->budget--) { s->failed_pc=0x0c0a2bfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0a2bfc;
P_0c0a2bfc: /* original 8903, guest PC 0x0c0a2bfc */
if(!s->budget--) { s->failed_pc=0x0c0a2bfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c06; }
goto P_0c0a2bfe;
P_0c0a2bfe: /* original 480b, guest PC 0x0c0a2bfe */
if(!s->budget--) { s->failed_pc=0x0c0a2bfeu; return 0; }
target=r[8];
r[16]=code_base|0x0c0a2c02u;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c02u) { target=s->pc; goto dispatch; }
goto P_0c0a2c02;
P_0c0a2c00: /* original 64d2, guest PC 0x0c0a2c00 */
if(!s->budget--) { s->failed_pc=0x0c0a2c00u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c02;
P_0c0a2c02: /* original a004, guest PC 0x0c0a2c02 */
if(!s->budget--) { s->failed_pc=0x0c0a2c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c04: /* original 2008, guest PC 0x0c0a2c04 */
if(!s->budget--) { s->failed_pc=0x0c0a2c04u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c06;
P_0c0a2c06: /* original 64d2, guest PC 0x0c0a2c06 */
if(!s->budget--) { s->failed_pc=0x0c0a2c06u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c08;
P_0c0a2c08: /* original 490b, guest PC 0x0c0a2c08 */
if(!s->budget--) { s->failed_pc=0x0c0a2c08u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a2c0cu;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c0cu) { target=s->pc; goto dispatch; }
goto P_0c0a2c0c;
P_0c0a2c0a: /* original 5441, guest PC 0x0c0a2c0a */
if(!s->budget--) { s->failed_pc=0x0c0a2c0au; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2c0c;
P_0c0a2c0c: /* original 2008, guest PC 0x0c0a2c0c */
if(!s->budget--) { s->failed_pc=0x0c0a2c0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c0e: /* original 7c01, guest PC 0x0c0a2c0e */
if(!s->budget--) { s->failed_pc=0x0c0a2c0eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a2c10;
P_0c0a2c10: /* original 85e6, guest PC 0x0c0a2c10 */
if(!s->budget--) { s->failed_pc=0x0c0a2c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2c12;
P_0c0a2c12: /* original 600d, guest PC 0x0c0a2c12 */
if(!s->budget--) { s->failed_pc=0x0c0a2c12u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2c14;
P_0c0a2c14: /* original 3c03, guest PC 0x0c0a2c14 */
if(!s->budget--) { s->failed_pc=0x0c0a2c14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a2c16;
P_0c0a2c16: /* original 8beb, guest PC 0x0c0a2c16 */
if(!s->budget--) { s->failed_pc=0x0c0a2c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2bf0; }
goto P_0c0a2c18;
P_0c0a2c18: /* original e022, guest PC 0x0c0a2c18 */
if(!s->budget--) { s->failed_pc=0x0c0a2c18u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2c1a;
P_0c0a2c1a: /* original e200, guest PC 0x0c0a2c1a */
if(!s->budget--) { s->failed_pc=0x0c0a2c1au; return 0; }
r[2]=0x00000000u;
goto P_0c0a2c1c;
P_0c0a2c1c: /* original 0e25, guest PC 0x0c0a2c1c */
if(!s->budget--) { s->failed_pc=0x0c0a2c1cu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c1e;
P_0c0a2c1e: /* original e020, guest PC 0x0c0a2c1e */
if(!s->budget--) { s->failed_pc=0x0c0a2c1eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2c20;
P_0c0a2c20: /* original 0e25, guest PC 0x0c0a2c20 */
if(!s->budget--) { s->failed_pc=0x0c0a2c20u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c22;
P_0c0a2c22: /* original e000, guest PC 0x0c0a2c22 */
if(!s->budget--) { s->failed_pc=0x0c0a2c22u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2c24;
P_0c0a2c24: /* original 4f26, guest PC 0x0c0a2c24 */
if(!s->budget--) { s->failed_pc=0x0c0a2c24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2c26;
P_0c0a2c26: /* original 68f6, guest PC 0x0c0a2c26 */
if(!s->budget--) { s->failed_pc=0x0c0a2c26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2c28;
P_0c0a2c28: /* original 69f6, guest PC 0x0c0a2c28 */
if(!s->budget--) { s->failed_pc=0x0c0a2c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2c2a;
P_0c0a2c2a: /* original 6af6, guest PC 0x0c0a2c2a */
if(!s->budget--) { s->failed_pc=0x0c0a2c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2c2c;
P_0c0a2c2c: /* original 6bf6, guest PC 0x0c0a2c2c */
if(!s->budget--) { s->failed_pc=0x0c0a2c2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2c2e;
P_0c0a2c2e: /* original 6cf6, guest PC 0x0c0a2c2e */
if(!s->budget--) { s->failed_pc=0x0c0a2c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2c30;
P_0c0a2c30: /* original 6df6, guest PC 0x0c0a2c30 */
if(!s->budget--) { s->failed_pc=0x0c0a2c30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2c32;
P_0c0a2c32: /* original 000b, guest PC 0x0c0a2c32 */
if(!s->budget--) { s->failed_pc=0x0c0a2c32u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2c34: /* original 6ef6, guest PC 0x0c0a2c34 */
if(!s->budget--) { s->failed_pc=0x0c0a2c34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2c36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2c36u; return 0; } return 1;
P_0c0a2e86: /* original 2fe6, guest PC 0x0c0a2e86 */
if(!s->budget--) { s->failed_pc=0x0c0a2e86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2e88;
P_0c0a2e88: /* original 4411, guest PC 0x0c0a2e88 */
if(!s->budget--) { s->failed_pc=0x0c0a2e88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a2e8a;
P_0c0a2e8a: /* original 2fd6, guest PC 0x0c0a2e8a */
if(!s->budget--) { s->failed_pc=0x0c0a2e8au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2e8c;
P_0c0a2e8c: /* original 4f22, guest PC 0x0c0a2e8c */
if(!s->budget--) { s->failed_pc=0x0c0a2e8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2e8e;
P_0c0a2e8e: /* original 8b1c, guest PC 0x0c0a2e8e */
if(!s->budget--) { s->failed_pc=0x0c0a2e8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2eca; }
goto P_0c0a2e90;
P_0c0a2e90: /* original e21a, guest PC 0x0c0a2e90 */
if(!s->budget--) { s->failed_pc=0x0c0a2e90u; return 0; }
r[2]=0x0000001au;
goto P_0c0a2e92;
P_0c0a2e92: /* original 3423, guest PC 0x0c0a2e92 */
if(!s->budget--) { s->failed_pc=0x0c0a2e92u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0a2e94;
P_0c0a2e94: /* original 8919, guest PC 0x0c0a2e94 */
if(!s->budget--) { s->failed_pc=0x0c0a2e94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2eca; }
goto P_0c0a2e96;
P_0c0a2e96: /* original 6e43, guest PC 0x0c0a2e96 */
if(!s->budget--) { s->failed_pc=0x0c0a2e96u; return 0; }
r[14]=r[4];
goto P_0c0a2e98;
P_0c0a2e98: /* original 4e08, guest PC 0x0c0a2e98 */
if(!s->budget--) { s->failed_pc=0x0c0a2e98u; return 0; }
r[14]<<=2;
goto P_0c0a2e9a;
P_0c0a2e9a: /* original 4e00, guest PC 0x0c0a2e9a */
if(!s->budget--) { s->failed_pc=0x0c0a2e9au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0a2e9c;
P_0c0a2e9c: /* original 6343, guest PC 0x0c0a2e9c */
if(!s->budget--) { s->failed_pc=0x0c0a2e9cu; return 0; }
r[3]=r[4];
goto P_0c0a2e9e;
P_0c0a2e9e: /* original 3e3c, guest PC 0x0c0a2e9e */
if(!s->budget--) { s->failed_pc=0x0c0a2e9eu; return 0; }
r[14]+=r[3];
goto P_0c0a2ea0;
P_0c0a2ea0: /* original d233, guest PC 0x0c0a2ea0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea0u; return 0; }
r[2]=read(ram,0x0c0a2f70u,4);
goto P_0c0a2ea2;
P_0c0a2ea2: /* original 4e08, guest PC 0x0c0a2ea2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea2u; return 0; }
r[14]<<=2;
goto P_0c0a2ea4;
P_0c0a2ea4: /* original 6eef, guest PC 0x0c0a2ea4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0a2ea6;
P_0c0a2ea6: /* original 3e2c, guest PC 0x0c0a2ea6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea6u; return 0; }
r[14]+=r[2];
goto P_0c0a2ea8;
P_0c0a2ea8: /* original 53e6, guest PC 0x0c0a2ea8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea8u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0a2eaa;
P_0c0a2eaa: /* original 2338, guest PC 0x0c0a2eaa */
if(!s->budget--) { s->failed_pc=0x0c0a2eaau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2eac;
P_0c0a2eac: /* original 890d, guest PC 0x0c0a2eac */
if(!s->budget--) { s->failed_pc=0x0c0a2eacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2eca; }
goto P_0c0a2eae;
P_0c0a2eae: /* original 5de6, guest PC 0x0c0a2eae */
if(!s->budget--) { s->failed_pc=0x0c0a2eaeu; return 0; }
r[13]=read(ram,r[14]+24,4);
goto P_0c0a2eb0;
P_0c0a2eb0: /* original d330, guest PC 0x0c0a2eb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb0u; return 0; }
r[3]=read(ram,0x0c0a2f74u,4);
goto P_0c0a2eb2;
P_0c0a2eb2: /* original 2d3b, guest PC 0x0c0a2eb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb2u; return 0; }
r[13]|=r[3];
goto P_0c0a2eb4;
P_0c0a2eb4: /* original 62d2, guest PC 0x0c0a2eb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb4u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a2eb6;
P_0c0a2eb6: /* original 2228, guest PC 0x0c0a2eb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2eb8;
P_0c0a2eb8: /* original 8905, guest PC 0x0c0a2eb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2ec6; }
goto P_0c0a2eba;
P_0c0a2eba: /* original 52e8, guest PC 0x0c0a2eba */
if(!s->budget--) { s->failed_pc=0x0c0a2ebau; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c0a2ebc;
P_0c0a2ebc: /* original 420b, guest PC 0x0c0a2ebc */
if(!s->budget--) { s->failed_pc=0x0c0a2ebcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2ec0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ec0u) { target=s->pc; goto dispatch; }
goto P_0c0a2ec0;
P_0c0a2ebe: /* original 0009, guest PC 0x0c0a2ebe */
if(!s->budget--) { s->failed_pc=0x0c0a2ebeu; return 0; }
goto P_0c0a2ec0;
P_0c0a2ec0: /* original d32d, guest PC 0x0c0a2ec0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec0u; return 0; }
r[3]=read(ram,0x0c0a2f78u,4);
goto P_0c0a2ec2;
P_0c0a2ec2: /* original 430b, guest PC 0x0c0a2ec2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ec6u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ec6u) { target=s->pc; goto dispatch; }
goto P_0c0a2ec6;
P_0c0a2ec4: /* original 54e6, guest PC 0x0c0a2ec4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec4u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c0a2ec6;
P_0c0a2ec6: /* original e200, guest PC 0x0c0a2ec6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec6u; return 0; }
r[2]=0x00000000u;
goto P_0c0a2ec8;
P_0c0a2ec8: /* original 2d22, guest PC 0x0c0a2ec8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec8u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0a2eca;
P_0c0a2eca: /* original 4f26, guest PC 0x0c0a2eca */
if(!s->budget--) { s->failed_pc=0x0c0a2ecau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2ecc;
P_0c0a2ecc: /* original 6df6, guest PC 0x0c0a2ecc */
if(!s->budget--) { s->failed_pc=0x0c0a2eccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2ece;
P_0c0a2ece: /* original 000b, guest PC 0x0c0a2ece */
if(!s->budget--) { s->failed_pc=0x0c0a2eceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2ed0: /* original 6ef6, guest PC 0x0c0a2ed0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ed0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2ed2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2ed2u; return 0; } return 1;
P_0c0c124e: /* original e100, guest PC 0x0c0c124e */
if(!s->budget--) { s->failed_pc=0x0c0c124eu; return 0; }
r[1]=0x00000000u;
goto P_0c0c1250;
P_0c0c1250: /* original d324, guest PC 0x0c0c1250 */
if(!s->budget--) { s->failed_pc=0x0c0c1250u; return 0; }
r[3]=read(ram,0x0c0c12e4u,4);
goto P_0c0c1252;
P_0c0c1252: /* original e022, guest PC 0x0c0c1252 */
if(!s->budget--) { s->failed_pc=0x0c0c1252u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1254;
P_0c0c1254: /* original 7ffc, guest PC 0x0c0c1254 */
if(!s->budget--) { s->failed_pc=0x0c0c1254u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1256;
P_0c0c1256: /* original 2f32, guest PC 0x0c0c1256 */
if(!s->budget--) { s->failed_pc=0x0c0c1256u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c1258;
P_0c0c1258: /* original 0415, guest PC 0x0c0c1258 */
if(!s->budget--) { s->failed_pc=0x0c0c1258u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c0c125a;
P_0c0c125a: /* original 6063, guest PC 0x0c0c125a */
if(!s->budget--) { s->failed_pc=0x0c0c125au; return 0; }
r[0]=r[6];
goto P_0c0c125c;
P_0c0c125c: /* original 1474, guest PC 0x0c0c125c */
if(!s->budget--) { s->failed_pc=0x0c0c125cu; return 0; }
write(ram,r[4]+16,r[7],4);
goto P_0c0c125e;
P_0c0c125e: /* original 53f1, guest PC 0x0c0c125e */
if(!s->budget--) { s->failed_pc=0x0c0c125eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1260;
P_0c0c1260: /* original 1433, guest PC 0x0c0c1260 */
if(!s->budget--) { s->failed_pc=0x0c0c1260u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0c1262;
P_0c0c1262: /* original 2451, guest PC 0x0c0c1262 */
if(!s->budget--) { s->failed_pc=0x0c0c1262u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c1264;
P_0c0c1264: /* original 8141, guest PC 0x0c0c1264 */
if(!s->budget--) { s->failed_pc=0x0c0c1264u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c0c1266;
P_0c0c1266: /* original e040, guest PC 0x0c0c1266 */
if(!s->budget--) { s->failed_pc=0x0c0c1266u; return 0; }
r[0]=0x00000040u;
goto P_0c0c1268;
P_0c0c1268: /* original 53f2, guest PC 0x0c0c1268 */
if(!s->budget--) { s->failed_pc=0x0c0c1268u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c126a;
P_0c0c126a: /* original 1436, guest PC 0x0c0c126a */
if(!s->budget--) { s->failed_pc=0x0c0c126au; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0c126c;
P_0c0c126c: /* original 52f3, guest PC 0x0c0c126c */
if(!s->budget--) { s->failed_pc=0x0c0c126cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c126e;
P_0c0c126e: /* original 1427, guest PC 0x0c0c126e */
if(!s->budget--) { s->failed_pc=0x0c0c126eu; return 0; }
write(ram,r[4]+28,r[2],4);
goto P_0c0c1270;
P_0c0c1270: /* original 8142, guest PC 0x0c0c1270 */
if(!s->budget--) { s->failed_pc=0x0c0c1270u; return 0; }
write(ram,r[4]+4,r[0],2);
goto P_0c0c1272;
P_0c0c1272: /* original e030, guest PC 0x0c0c1272 */
if(!s->budget--) { s->failed_pc=0x0c0c1272u; return 0; }
r[0]=0x00000030u;
goto P_0c0c1274;
P_0c0c1274: /* original 8143, guest PC 0x0c0c1274 */
if(!s->budget--) { s->failed_pc=0x0c0c1274u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0c1276;
P_0c0c1276: /* original e03e, guest PC 0x0c0c1276 */
if(!s->budget--) { s->failed_pc=0x0c0c1276u; return 0; }
r[0]=0x0000003eu;
goto P_0c0c1278;
P_0c0c1278: /* original 8144, guest PC 0x0c0c1278 */
if(!s->budget--) { s->failed_pc=0x0c0c1278u; return 0; }
write(ram,r[4]+8,r[0],2);
goto P_0c0c127a;
P_0c0c127a: /* original e02e, guest PC 0x0c0c127a */
if(!s->budget--) { s->failed_pc=0x0c0c127au; return 0; }
r[0]=0x0000002eu;
goto P_0c0c127c;
P_0c0c127c: /* original 8145, guest PC 0x0c0c127c */
if(!s->budget--) { s->failed_pc=0x0c0c127cu; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c0c127e;
P_0c0c127e: /* original 6013, guest PC 0x0c0c127e */
if(!s->budget--) { s->failed_pc=0x0c0c127eu; return 0; }
r[0]=r[1];
goto P_0c0c1280;
P_0c0c1280: /* original 814a, guest PC 0x0c0c1280 */
if(!s->budget--) { s->failed_pc=0x0c0c1280u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c0c1282;
P_0c0c1282: /* original 814b, guest PC 0x0c0c1282 */
if(!s->budget--) { s->failed_pc=0x0c0c1282u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c0c1284;
P_0c0c1284: /* original e020, guest PC 0x0c0c1284 */
if(!s->budget--) { s->failed_pc=0x0c0c1284u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1286;
P_0c0c1286: /* original 932a, guest PC 0x0c0c1286 */
if(!s->budget--) { s->failed_pc=0x0c0c1286u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12deu,2);
goto P_0c0c1288;
P_0c0c1288: /* original 0435, guest PC 0x0c0c1288 */
if(!s->budget--) { s->failed_pc=0x0c0c1288u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0c128a;
P_0c0c128a: /* original e3ff, guest PC 0x0c0c128a */
if(!s->budget--) { s->failed_pc=0x0c0c128au; return 0; }
r[3]=0xffffffffu;
goto P_0c0c128c;
P_0c0c128c: /* original 62f2, guest PC 0x0c0c128c */
if(!s->budget--) { s->failed_pc=0x0c0c128cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c128e;
P_0c0c128e: /* original 9027, guest PC 0x0c0c128e */
if(!s->budget--) { s->failed_pc=0x0c0c128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12e0u,2);
goto P_0c0c1290;
P_0c0c1290: /* original 0236, guest PC 0x0c0c1290 */
if(!s->budget--) { s->failed_pc=0x0c0c1290u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c1292;
P_0c0c1292: /* original a000, guest PC 0x0c0c1292 */
if(!s->budget--) { s->failed_pc=0x0c0c1292u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1294: /* original 7f04, guest PC 0x0c0c1294 */
if(!s->budget--) { s->failed_pc=0x0c0c1294u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1296: /* original 2fe6, guest PC 0x0c0c1296 */
if(!s->budget--) { s->failed_pc=0x0c0c1296u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1298;
P_0c0c1298: /* original 6e43, guest PC 0x0c0c1298 */
if(!s->budget--) { s->failed_pc=0x0c0c1298u; return 0; }
r[14]=r[4];
goto P_0c0c129a;
P_0c0c129a: /* original 2fd6, guest PC 0x0c0c129a */
if(!s->budget--) { s->failed_pc=0x0c0c129au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c129c;
P_0c0c129c: /* original ed00, guest PC 0x0c0c129c */
if(!s->budget--) { s->failed_pc=0x0c0c129cu; return 0; }
r[13]=0x00000000u;
goto P_0c0c129e;
P_0c0c129e: /* original 2fc6, guest PC 0x0c0c129e */
if(!s->budget--) { s->failed_pc=0x0c0c129eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12a0;
P_0c0c12a0: /* original ec78, guest PC 0x0c0c12a0 */
if(!s->budget--) { s->failed_pc=0x0c0c12a0u; return 0; }
r[12]=0x00000078u;
goto P_0c0c12a2;
P_0c0c12a2: /* original 2fb6, guest PC 0x0c0c12a2 */
if(!s->budget--) { s->failed_pc=0x0c0c12a2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12a4;
P_0c0c12a4: /* original 4f22, guest PC 0x0c0c12a4 */
if(!s->budget--) { s->failed_pc=0x0c0c12a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c12a6;
P_0c0c12a6: /* original 7ffc, guest PC 0x0c0c12a6 */
if(!s->budget--) { s->failed_pc=0x0c0c12a6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c12a8;
P_0c0c12a8: /* original 2f42, guest PC 0x0c0c12a8 */
if(!s->budget--) { s->failed_pc=0x0c0c12a8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c12aa;
P_0c0c12aa: /* original 5ee3, guest PC 0x0c0c12aa */
if(!s->budget--) { s->failed_pc=0x0c0c12aau; return 0; }
r[14]=read(ram,r[14]+12,4);
goto P_0c0c12ac;
P_0c0c12ac: /* original db0f, guest PC 0x0c0c12ac */
if(!s->budget--) { s->failed_pc=0x0c0c12acu; return 0; }
r[11]=read(ram,0x0c0c12ecu,4);
goto P_0c0c12ae;
P_0c0c12ae: /* original e500, guest PC 0x0c0c12ae */
if(!s->budget--) { s->failed_pc=0x0c0c12aeu; return 0; }
r[5]=0x00000000u;
goto P_0c0c12b0;
P_0c0c12b0: /* original e644, guest PC 0x0c0c12b0 */
if(!s->budget--) { s->failed_pc=0x0c0c12b0u; return 0; }
r[6]=0x00000044u;
goto P_0c0c12b2;
P_0c0c12b2: /* original 4b0b, guest PC 0x0c0c12b2 */
if(!s->budget--) { s->failed_pc=0x0c0c12b2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c12b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c12b6u) { target=s->pc; goto dispatch; }
goto P_0c0c12b6;
P_0c0c12b4: /* original 64e3, guest PC 0x0c0c12b4 */
if(!s->budget--) { s->failed_pc=0x0c0c12b4u; return 0; }
r[4]=r[14];
goto P_0c0c12b6;
P_0c0c12b6: /* original 7d01, guest PC 0x0c0c12b6 */
if(!s->budget--) { s->failed_pc=0x0c0c12b6u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c12b8;
P_0c0c12b8: /* original 3dc2, guest PC 0x0c0c12b8 */
if(!s->budget--) { s->failed_pc=0x0c0c12b8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[12])!=0);
goto P_0c0c12ba;
P_0c0c12ba: /* original 8ff8, guest PC 0x0c0c12ba */
if(!s->budget--) { s->failed_pc=0x0c0c12bau; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(!cond) { goto P_0c0c12ae; }
goto P_0c0c12be;
P_0c0c12bc: /* original 7e44, guest PC 0x0c0c12bc */
if(!s->budget--) { s->failed_pc=0x0c0c12bcu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c12be;
P_0c0c12be: /* original 63f2, guest PC 0x0c0c12be */
if(!s->budget--) { s->failed_pc=0x0c0c12beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c12c0;
P_0c0c12c0: /* original 7f04, guest PC 0x0c0c12c0 */
if(!s->budget--) { s->failed_pc=0x0c0c12c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c12c2;
P_0c0c12c2: /* original 4f26, guest PC 0x0c0c12c2 */
if(!s->budget--) { s->failed_pc=0x0c0c12c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c12c4;
P_0c0c12c4: /* original e022, guest PC 0x0c0c12c4 */
if(!s->budget--) { s->failed_pc=0x0c0c12c4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c12c6;
P_0c0c12c6: /* original 013d, guest PC 0x0c0c12c6 */
if(!s->budget--) { s->failed_pc=0x0c0c12c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c12c8;
P_0c0c12c8: /* original e201, guest PC 0x0c0c12c8 */
if(!s->budget--) { s->failed_pc=0x0c0c12c8u; return 0; }
r[2]=0x00000001u;
goto P_0c0c12ca;
P_0c0c12ca: /* original 212b, guest PC 0x0c0c12ca */
if(!s->budget--) { s->failed_pc=0x0c0c12cau; return 0; }
r[1]|=r[2];
goto P_0c0c12cc;
P_0c0c12cc: /* original 0315, guest PC 0x0c0c12cc */
if(!s->budget--) { s->failed_pc=0x0c0c12ccu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c12ce;
P_0c0c12ce: /* original 6bf6, guest PC 0x0c0c12ce */
if(!s->budget--) { s->failed_pc=0x0c0c12ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c12d0;
P_0c0c12d0: /* original 6cf6, guest PC 0x0c0c12d0 */
if(!s->budget--) { s->failed_pc=0x0c0c12d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c12d2;
P_0c0c12d2: /* original 6df6, guest PC 0x0c0c12d2 */
if(!s->budget--) { s->failed_pc=0x0c0c12d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c12d4;
P_0c0c12d4: /* original 000b, guest PC 0x0c0c12d4 */
if(!s->budget--) { s->failed_pc=0x0c0c12d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c12d6: /* original 6ef6, guest PC 0x0c0c12d6 */
if(!s->budget--) { s->failed_pc=0x0c0c12d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c12d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c12d8u; return 0; } return 1;
P_0c0c2d06: /* original 2fe6, guest PC 0x0c0c2d06 */
if(!s->budget--) { s->failed_pc=0x0c0c2d06u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d08;
P_0c0c2d08: /* original 2fd6, guest PC 0x0c0c2d08 */
if(!s->budget--) { s->failed_pc=0x0c0c2d08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0a;
P_0c0c2d0a: /* original 2fc6, guest PC 0x0c0c2d0a */
if(!s->budget--) { s->failed_pc=0x0c0c2d0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0c;
P_0c0c2d0c: /* original 2fb6, guest PC 0x0c0c2d0c */
if(!s->budget--) { s->failed_pc=0x0c0c2d0cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0e;
P_0c0c2d0e: /* original fffb, guest PC 0x0c0c2d0e */
if(!s->budget--) { s->failed_pc=0x0c0c2d0eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c2d10;
P_0c0c2d10: /* original 4f22, guest PC 0x0c0c2d10 */
if(!s->budget--) { s->failed_pc=0x0c0c2d10u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2d12;
P_0c0c2d12: /* original de28, guest PC 0x0c0c2d12 */
if(!s->budget--) { s->failed_pc=0x0c0c2d12u; return 0; }
r[14]=read(ram,0x0c0c2db4u,4);
goto P_0c0c2d14;
P_0c0c2d14: /* original d328, guest PC 0x0c0c2d14 */
if(!s->budget--) { s->failed_pc=0x0c0c2d14u; return 0; }
r[3]=read(ram,0x0c0c2db8u,4);
goto P_0c0c2d16;
P_0c0c2d16: /* original 65e3, guest PC 0x0c0c2d16 */
if(!s->budget--) { s->failed_pc=0x0c0c2d16u; return 0; }
r[5]=r[14];
goto P_0c0c2d18;
P_0c0c2d18: /* original 7ff8, guest PC 0x0c0c2d18 */
if(!s->budget--) { s->failed_pc=0x0c0c2d18u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c2d1a;
P_0c0c2d1a: /* original 66e3, guest PC 0x0c0c2d1a */
if(!s->budget--) { s->failed_pc=0x0c0c2d1au; return 0; }
r[6]=r[14];
goto P_0c0c2d1c;
P_0c0c2d1c: /* original 430b, guest PC 0x0c0c2d1c */
if(!s->budget--) { s->failed_pc=0x0c0c2d1cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2d20u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d20u) { target=s->pc; goto dispatch; }
goto P_0c0c2d20;
P_0c0c2d1e: /* original 64e3, guest PC 0x0c0c2d1e */
if(!s->budget--) { s->failed_pc=0x0c0c2d1eu; return 0; }
r[4]=r[14];
goto P_0c0c2d20;
P_0c0c2d20: /* original de22, guest PC 0x0c0c2d20 */
if(!s->budget--) { s->failed_pc=0x0c0c2d20u; return 0; }
r[14]=read(ram,0x0c0c2dacu,4);
goto P_0c0c2d22;
P_0c0c2d22: /* original db20, guest PC 0x0c0c2d22 */
if(!s->budget--) { s->failed_pc=0x0c0c2d22u; return 0; }
r[11]=read(ram,0x0c0c2da4u,4);
goto P_0c0c2d24;
P_0c0c2d24: /* original 54e2, guest PC 0x0c0c2d24 */
if(!s->budget--) { s->failed_pc=0x0c0c2d24u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0c2d26;
P_0c0c2d26: /* original dc1e, guest PC 0x0c0c2d26 */
if(!s->budget--) { s->failed_pc=0x0c0c2d26u; return 0; }
r[12]=read(ram,0x0c0c2da0u,4);
goto P_0c0c2d28;
P_0c0c2d28: /* original 6243, guest PC 0x0c0c2d28 */
if(!s->budget--) { s->failed_pc=0x0c0c2d28u; return 0; }
r[2]=r[4];
goto P_0c0c2d2a;
P_0c0c2d2a: /* original 2448, guest PC 0x0c0c2d2a */
if(!s->budget--) { s->failed_pc=0x0c0c2d2au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c2d2c;
P_0c0c2d2c: /* original 7201, guest PC 0x0c0c2d2c */
if(!s->budget--) { s->failed_pc=0x0c0c2d2cu; return 0; }
r[2]+=0x00000001u;
goto P_0c0c2d2e;
P_0c0c2d2e: /* original 8f08, guest PC 0x0c0c2d2e */
if(!s->budget--) { s->failed_pc=0x0c0c2d2eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+8,r[2],4);
if(!cond) { goto P_0c0c2d42; }
goto P_0c0c2d32;
P_0c0c2d30: /* original 1e22, guest PC 0x0c0c2d30 */
if(!s->budget--) { s->failed_pc=0x0c0c2d30u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0c2d32;
P_0c0c2d32: /* original 942c, guest PC 0x0c0c2d32 */
if(!s->budget--) { s->failed_pc=0x0c0c2d32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d8eu,2);
goto P_0c0c2d34;
P_0c0c2d34: /* original e700, guest PC 0x0c0c2d34 */
if(!s->budget--) { s->failed_pc=0x0c0c2d34u; return 0; }
r[7]=0x00000000u;
goto P_0c0c2d36;
P_0c0c2d36: /* original 6573, guest PC 0x0c0c2d36 */
if(!s->budget--) { s->failed_pc=0x0c0c2d36u; return 0; }
r[5]=r[7];
goto P_0c0c2d38;
P_0c0c2d38: /* original 6673, guest PC 0x0c0c2d38 */
if(!s->budget--) { s->failed_pc=0x0c0c2d38u; return 0; }
r[6]=r[7];
goto P_0c0c2d3a;
P_0c0c2d3a: /* original 4b0b, guest PC 0x0c0c2d3a */
if(!s->budget--) { s->failed_pc=0x0c0c2d3au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2d3eu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d3eu) { target=s->pc; goto dispatch; }
goto P_0c0c2d3e;
P_0c0c2d3c: /* original 34cc, guest PC 0x0c0c2d3c */
if(!s->budget--) { s->failed_pc=0x0c0c2d3cu; return 0; }
r[4]+=r[12];
goto P_0c0c2d3e;
P_0c0c2d3e: /* original a070, guest PC 0x0c0c2d3e */
if(!s->budget--) { s->failed_pc=0x0c0c2d3eu; return 0; }
goto P_0c0c2e22;
P_0c0c2d40: /* original 0009, guest PC 0x0c0c2d40 */
if(!s->budget--) { s->failed_pc=0x0c0c2d40u; return 0; }
goto P_0c0c2d42;
P_0c0c2d42: /* original e308, guest PC 0x0c0c2d42 */
if(!s->budget--) { s->failed_pc=0x0c0c2d42u; return 0; }
r[3]=0x00000008u;
goto P_0c0c2d44;
P_0c0c2d44: /* original 3433, guest PC 0x0c0c2d44 */
if(!s->budget--) { s->failed_pc=0x0c0c2d44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c2d46;
P_0c0c2d46: /* original 8941, guest PC 0x0c0c2d46 */
if(!s->budget--) { s->failed_pc=0x0c0c2d46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2dcc; }
goto P_0c0c2d48;
P_0c0c2d48: /* original c71c, guest PC 0x0c0c2d48 */
if(!s->budget--) { s->failed_pc=0x0c0c2d48u; return 0; }
r[0]=code_base|0x000c2dbcu;
goto P_0c0c2d4a;
P_0c0c2d4a: /* original ffe8, guest PC 0x0c0c2d4a */
if(!s->budget--) { s->failed_pc=0x0c0c2d4au; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c0c2d4c;
P_0c0c2d4c: /* original f408, guest PC 0x0c0c2d4c */
if(!s->budget--) { s->failed_pc=0x0c0c2d4cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c2d4e;
P_0c0c2d4e: /* original 52e1, guest PC 0x0c0c2d4e */
if(!s->budget--) { s->failed_pc=0x0c0c2d4eu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c2d50;
P_0c0c2d50: /* original ff45, guest PC 0x0c0c2d50 */
if(!s->budget--) { s->failed_pc=0x0c0c2d50u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c0c2d52;
P_0c0c2d52: /* original 1f21, guest PC 0x0c0c2d52 */
if(!s->budget--) { s->failed_pc=0x0c0c2d52u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0c2d54;
P_0c0c2d54: /* original 8b65, guest PC 0x0c0c2d54 */
if(!s->budget--) { s->failed_pc=0x0c0c2d54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2e22; }
goto P_0c0c2d56;
P_0c0c2d56: /* original f39d, guest PC 0x0c0c2d56 */
if(!s->budget--) { s->failed_pc=0x0c0c2d56u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c2d58;
P_0c0c2d58: /* original f3f1, guest PC 0x0c0c2d58 */
if(!s->budget--) { s->failed_pc=0x0c0c2d58u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'-');
goto P_0c0c2d5a;
P_0c0c2d5a: /* original c719, guest PC 0x0c0c2d5a */
if(!s->budget--) { s->failed_pc=0x0c0c2d5au; return 0; }
r[0]=code_base|0x000c2dc0u;
goto P_0c0c2d5c;
P_0c0c2d5c: /* original 64c3, guest PC 0x0c0c2d5c */
if(!s->budget--) { s->failed_pc=0x0c0c2d5cu; return 0; }
r[4]=r[12];
goto P_0c0c2d5e;
P_0c0c2d5e: /* original f6fc, guest PC 0x0c0c2d5e */
if(!s->budget--) { s->failed_pc=0x0c0c2d5eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0c2d60;
P_0c0c2d60: /* original e600, guest PC 0x0c0c2d60 */
if(!s->budget--) { s->failed_pc=0x0c0c2d60u; return 0; }
r[6]=0x00000000u;
goto P_0c0c2d62;
P_0c0c2d62: /* original ff3a, guest PC 0x0c0c2d62 */
if(!s->budget--) { s->failed_pc=0x0c0c2d62u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c2d64;
P_0c0c2d64: /* original f208, guest PC 0x0c0c2d64 */
if(!s->budget--) { s->failed_pc=0x0c0c2d64u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c2d66;
P_0c0c2d66: /* original c717, guest PC 0x0c0c2d66 */
if(!s->budget--) { s->failed_pc=0x0c0c2d66u; return 0; }
r[0]=code_base|0x000c2dc4u;
goto P_0c0c2d68;
P_0c0c2d68: /* original f108, guest PC 0x0c0c2d68 */
if(!s->budget--) { s->failed_pc=0x0c0c2d68u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c2d6a;
P_0c0c2d6a: /* original f43c, guest PC 0x0c0c2d6a */
if(!s->budget--) { s->failed_pc=0x0c0c2d6au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c2d6c;
P_0c0c2d6c: /* original f53c, guest PC 0x0c0c2d6c */
if(!s->budget--) { s->failed_pc=0x0c0c2d6cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c2d6e;
P_0c0c2d6e: /* original f412, guest PC 0x0c0c2d6e */
if(!s->budget--) { s->failed_pc=0x0c0c2d6eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'*');
goto P_0c0c2d70;
P_0c0c2d70: /* original f522, guest PC 0x0c0c2d70 */
if(!s->budget--) { s->failed_pc=0x0c0c2d70u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0c2d72;
P_0c0c2d72: /* original 950e, guest PC 0x0c0c2d72 */
if(!s->budget--) { s->failed_pc=0x0c0c2d72u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d92u,2);
goto P_0c0c2d74;
P_0c0c2d74: /* original b05d, guest PC 0x0c0c2d74 */
if(!s->budget--) { s->failed_pc=0x0c0c2d74u; return 0; }
target=code_base|0x0c0c2e32u; r[16]=code_base|0x0c0c2d78u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2d78u) { target=s->pc; goto dispatch; }
goto P_0c0c2d78;
P_0c0c2d76: /* original 7458, guest PC 0x0c0c2d76 */
if(!s->budget--) { s->failed_pc=0x0c0c2d76u; return 0; }
r[4]+=0x00000058u;
goto P_0c0c2d78;
P_0c0c2d78: /* original c713, guest PC 0x0c0c2d78 */
if(!s->budget--) { s->failed_pc=0x0c0c2d78u; return 0; }
r[0]=code_base|0x000c2dc8u;
goto P_0c0c2d7a;
P_0c0c2d7a: /* original f308, guest PC 0x0c0c2d7a */
if(!s->budget--) { s->failed_pc=0x0c0c2d7au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c2d7c;
P_0c0c2d7c: /* original ff30, guest PC 0x0c0c2d7c */
if(!s->budget--) { s->failed_pc=0x0c0c2d7cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c2d7e;
P_0c0c2d7e: /* original fefa, guest PC 0x0c0c2d7e */
if(!s->budget--) { s->failed_pc=0x0c0c2d7eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c0c2d80;
P_0c0c2d80: /* original 53f1, guest PC 0x0c0c2d80 */
if(!s->budget--) { s->failed_pc=0x0c0c2d80u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c2d82;
P_0c0c2d82: /* original 73ff, guest PC 0x0c0c2d82 */
if(!s->budget--) { s->failed_pc=0x0c0c2d82u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0c2d84;
P_0c0c2d84: /* original a04d, guest PC 0x0c0c2d84 */
if(!s->budget--) { s->failed_pc=0x0c0c2d84u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2e22;
P_0c0c2d86: /* original 1e31, guest PC 0x0c0c2d86 */
if(!s->budget--) { s->failed_pc=0x0c0c2d86u; return 0; }
write(ram,r[14]+4,r[3],4);
if(!vf3_matrix_family(0x0c0c2d88u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2d88u; return 0; } return 1;
P_0c0c2dcc: /* original 6043, guest PC 0x0c0c2dcc */
if(!s->budget--) { s->failed_pc=0x0c0c2dccu; return 0; }
r[0]=r[4];
goto P_0c0c2dce;
P_0c0c2dce: /* original 8808, guest PC 0x0c0c2dce */
if(!s->budget--) { s->failed_pc=0x0c0c2dceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c2dd0;
P_0c0c2dd0: /* original 8b0c, guest PC 0x0c0c2dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2dec; }
goto P_0c0c2dd2;
P_0c0c2dd2: /* original d252, guest PC 0x0c0c2dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd2u; return 0; }
r[2]=read(ram,0x0c0c2f1cu,4);
goto P_0c0c2dd4;
P_0c0c2dd4: /* original 64c3, guest PC 0x0c0c2dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd4u; return 0; }
r[4]=r[12];
goto P_0c0c2dd6;
P_0c0c2dd6: /* original 420b, guest PC 0x0c0c2dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c2ddau;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2ddau) { target=s->pc; goto dispatch; }
goto P_0c0c2dda;
P_0c0c2dd8: /* original 7458, guest PC 0x0c0c2dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c2dd8u; return 0; }
r[4]+=0x00000058u;
goto P_0c0c2dda;
P_0c0c2dda: /* original 949b, guest PC 0x0c0c2dda */
if(!s->budget--) { s->failed_pc=0x0c0c2ddau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f14u,2);
goto P_0c0c2ddc;
P_0c0c2ddc: /* original e71f, guest PC 0x0c0c2ddc */
if(!s->budget--) { s->failed_pc=0x0c0c2ddcu; return 0; }
r[7]=0x0000001fu;
goto P_0c0c2dde;
P_0c0c2dde: /* original 6573, guest PC 0x0c0c2dde */
if(!s->budget--) { s->failed_pc=0x0c0c2ddeu; return 0; }
r[5]=r[7];
goto P_0c0c2de0;
P_0c0c2de0: /* original 6673, guest PC 0x0c0c2de0 */
if(!s->budget--) { s->failed_pc=0x0c0c2de0u; return 0; }
r[6]=r[7];
goto P_0c0c2de2;
P_0c0c2de2: /* original 4b0b, guest PC 0x0c0c2de2 */
if(!s->budget--) { s->failed_pc=0x0c0c2de2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2de6u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2de6u) { target=s->pc; goto dispatch; }
goto P_0c0c2de6;
P_0c0c2de4: /* original 34cc, guest PC 0x0c0c2de4 */
if(!s->budget--) { s->failed_pc=0x0c0c2de4u; return 0; }
r[4]+=r[12];
goto P_0c0c2de6;
P_0c0c2de6: /* original e31f, guest PC 0x0c0c2de6 */
if(!s->budget--) { s->failed_pc=0x0c0c2de6u; return 0; }
r[3]=0x0000001fu;
goto P_0c0c2de8;
P_0c0c2de8: /* original a01b, guest PC 0x0c0c2de8 */
if(!s->budget--) { s->failed_pc=0x0c0c2de8u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2e22;
P_0c0c2dea: /* original 1e31, guest PC 0x0c0c2dea */
if(!s->budget--) { s->failed_pc=0x0c0c2deau; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2dec;
P_0c0c2dec: /* original 8809, guest PC 0x0c0c2dec */
if(!s->budget--) { s->failed_pc=0x0c0c2decu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c2dee;
P_0c0c2dee: /* original 8b0a, guest PC 0x0c0c2dee */
if(!s->budget--) { s->failed_pc=0x0c0c2deeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2e06; }
goto P_0c0c2df0;
P_0c0c2df0: /* original 66c3, guest PC 0x0c0c2df0 */
if(!s->budget--) { s->failed_pc=0x0c0c2df0u; return 0; }
r[6]=r[12];
goto P_0c0c2df2;
P_0c0c2df2: /* original e201, guest PC 0x0c0c2df2 */
if(!s->budget--) { s->failed_pc=0x0c0c2df2u; return 0; }
r[2]=0x00000001u;
goto P_0c0c2df4;
P_0c0c2df4: /* original 2f26, guest PC 0x0c0c2df4 */
if(!s->budget--) { s->failed_pc=0x0c0c2df4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2df6;
P_0c0c2df6: /* original e700, guest PC 0x0c0c2df6 */
if(!s->budget--) { s->failed_pc=0x0c0c2df6u; return 0; }
r[7]=0x00000000u;
goto P_0c0c2df8;
P_0c0c2df8: /* original 958d, guest PC 0x0c0c2df8 */
if(!s->budget--) { s->failed_pc=0x0c0c2df8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f16u,2);
goto P_0c0c2dfa;
P_0c0c2dfa: /* original 7658, guest PC 0x0c0c2dfa */
if(!s->budget--) { s->failed_pc=0x0c0c2dfau; return 0; }
r[6]+=0x00000058u;
goto P_0c0c2dfc;
P_0c0c2dfc: /* original d148, guest PC 0x0c0c2dfc */
if(!s->budget--) { s->failed_pc=0x0c0c2dfcu; return 0; }
r[1]=read(ram,0x0c0c2f20u,4);
goto P_0c0c2dfe;
P_0c0c2dfe: /* original 410b, guest PC 0x0c0c2dfe */
if(!s->budget--) { s->failed_pc=0x0c0c2dfeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0c2e02u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2e02u) { target=s->pc; goto dispatch; }
goto P_0c0c2e02;
P_0c0c2e00: /* original 6473, guest PC 0x0c0c2e00 */
if(!s->budget--) { s->failed_pc=0x0c0c2e00u; return 0; }
r[4]=r[7];
goto P_0c0c2e02;
P_0c0c2e02: /* original a00e, guest PC 0x0c0c2e02 */
if(!s->budget--) { s->failed_pc=0x0c0c2e02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c2e22;
P_0c0c2e04: /* original 7f04, guest PC 0x0c0c2e04 */
if(!s->budget--) { s->failed_pc=0x0c0c2e04u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c2e06;
P_0c0c2e06: /* original e229, guest PC 0x0c0c2e06 */
if(!s->budget--) { s->failed_pc=0x0c0c2e06u; return 0; }
r[2]=0x00000029u;
goto P_0c0c2e08;
P_0c0c2e08: /* original 3423, guest PC 0x0c0c2e08 */
if(!s->budget--) { s->failed_pc=0x0c0c2e08u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c2e0a;
P_0c0c2e0a: /* original 890a, guest PC 0x0c0c2e0a */
if(!s->budget--) { s->failed_pc=0x0c0c2e0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2e22; }
goto P_0c0c2e0c;
P_0c0c2e0c: /* original 5de1, guest PC 0x0c0c2e0c */
if(!s->budget--) { s->failed_pc=0x0c0c2e0cu; return 0; }
r[13]=read(ram,r[14]+4,4);
goto P_0c0c2e0e;
P_0c0c2e0e: /* original 2dd8, guest PC 0x0c0c2e0e */
if(!s->budget--) { s->failed_pc=0x0c0c2e0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c2e10;
P_0c0c2e10: /* original 8907, guest PC 0x0c0c2e10 */
if(!s->budget--) { s->failed_pc=0x0c0c2e10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2e22; }
goto P_0c0c2e12;
P_0c0c2e12: /* original 947f, guest PC 0x0c0c2e12 */
if(!s->budget--) { s->failed_pc=0x0c0c2e12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2f14u,2);
goto P_0c0c2e14;
P_0c0c2e14: /* original 65d3, guest PC 0x0c0c2e14 */
if(!s->budget--) { s->failed_pc=0x0c0c2e14u; return 0; }
r[5]=r[13];
goto P_0c0c2e16;
P_0c0c2e16: /* original 67d3, guest PC 0x0c0c2e16 */
if(!s->budget--) { s->failed_pc=0x0c0c2e16u; return 0; }
r[7]=r[13];
goto P_0c0c2e18;
P_0c0c2e18: /* original 66d3, guest PC 0x0c0c2e18 */
if(!s->budget--) { s->failed_pc=0x0c0c2e18u; return 0; }
r[6]=r[13];
goto P_0c0c2e1a;
P_0c0c2e1a: /* original 4b0b, guest PC 0x0c0c2e1a */
if(!s->budget--) { s->failed_pc=0x0c0c2e1au; return 0; }
target=r[11];
r[16]=code_base|0x0c0c2e1eu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2e1eu) { target=s->pc; goto dispatch; }
goto P_0c0c2e1e;
P_0c0c2e1c: /* original 34cc, guest PC 0x0c0c2e1c */
if(!s->budget--) { s->failed_pc=0x0c0c2e1cu; return 0; }
r[4]+=r[12];
goto P_0c0c2e1e;
P_0c0c2e1e: /* original 7dff, guest PC 0x0c0c2e1e */
if(!s->budget--) { s->failed_pc=0x0c0c2e1eu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0c2e20;
P_0c0c2e20: /* original 1ed1, guest PC 0x0c0c2e20 */
if(!s->budget--) { s->failed_pc=0x0c0c2e20u; return 0; }
write(ram,r[14]+4,r[13],4);
goto P_0c0c2e22;
P_0c0c2e22: /* original 7f08, guest PC 0x0c0c2e22 */
if(!s->budget--) { s->failed_pc=0x0c0c2e22u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c2e24;
P_0c0c2e24: /* original 4f26, guest PC 0x0c0c2e24 */
if(!s->budget--) { s->failed_pc=0x0c0c2e24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2e26;
P_0c0c2e26: /* original fff9, guest PC 0x0c0c2e26 */
if(!s->budget--) { s->failed_pc=0x0c0c2e26u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2e28;
P_0c0c2e28: /* original 6bf6, guest PC 0x0c0c2e28 */
if(!s->budget--) { s->failed_pc=0x0c0c2e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c2e2a;
P_0c0c2e2a: /* original 6cf6, guest PC 0x0c0c2e2a */
if(!s->budget--) { s->failed_pc=0x0c0c2e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2e2c;
P_0c0c2e2c: /* original 6df6, guest PC 0x0c0c2e2c */
if(!s->budget--) { s->failed_pc=0x0c0c2e2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2e2e;
P_0c0c2e2e: /* original 000b, guest PC 0x0c0c2e2e */
if(!s->budget--) { s->failed_pc=0x0c0c2e2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2e30: /* original 6ef6, guest PC 0x0c0c2e30 */
if(!s->budget--) { s->failed_pc=0x0c0c2e30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c2e32u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
