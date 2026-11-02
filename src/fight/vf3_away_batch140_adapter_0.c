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
int vf3_away_batch140_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c068d54u: goto P_0c068d54;
case 0x0c068d56u: goto P_0c068d56;
case 0x0c068d58u: goto P_0c068d58;
case 0x0c068d5au: goto P_0c068d5a;
case 0x0c068d5cu: goto P_0c068d5c;
case 0x0c068d5eu: goto P_0c068d5e;
case 0x0c068d60u: goto P_0c068d60;
case 0x0c068d62u: goto P_0c068d62;
case 0x0c068d64u: goto P_0c068d64;
case 0x0c068d66u: goto P_0c068d66;
case 0x0c068d68u: goto P_0c068d68;
case 0x0c068d6au: goto P_0c068d6a;
case 0x0c068d6cu: goto P_0c068d6c;
case 0x0c068d6eu: goto P_0c068d6e;
case 0x0c068d70u: goto P_0c068d70;
case 0x0c068d72u: goto P_0c068d72;
case 0x0c068d74u: goto P_0c068d74;
case 0x0c068d76u: goto P_0c068d76;
case 0x0c068d78u: goto P_0c068d78;
case 0x0c068d7au: goto P_0c068d7a;
case 0x0c068d7cu: goto P_0c068d7c;
case 0x0c068d7eu: goto P_0c068d7e;
case 0x0c068d80u: goto P_0c068d80;
case 0x0c068d82u: goto P_0c068d82;
case 0x0c068d84u: goto P_0c068d84;
case 0x0c068d86u: goto P_0c068d86;
case 0x0c068d88u: goto P_0c068d88;
case 0x0c068d8au: goto P_0c068d8a;
case 0x0c068d8cu: goto P_0c068d8c;
case 0x0c068d8eu: goto P_0c068d8e;
case 0x0c068d90u: goto P_0c068d90;
case 0x0c068d92u: goto P_0c068d92;
case 0x0c068d94u: goto P_0c068d94;
case 0x0c068d96u: goto P_0c068d96;
case 0x0c068d98u: goto P_0c068d98;
case 0x0c068d9au: goto P_0c068d9a;
case 0x0c068d9cu: goto P_0c068d9c;
case 0x0c068d9eu: goto P_0c068d9e;
case 0x0c068da0u: goto P_0c068da0;
case 0x0c068da2u: goto P_0c068da2;
case 0x0c068da4u: goto P_0c068da4;
case 0x0c068da6u: goto P_0c068da6;
case 0x0c068da8u: goto P_0c068da8;
case 0x0c068daau: goto P_0c068daa;
case 0x0c068dacu: goto P_0c068dac;
case 0x0c068daeu: goto P_0c068dae;
case 0x0c068db0u: goto P_0c068db0;
case 0x0c068db2u: goto P_0c068db2;
case 0x0c068db4u: goto P_0c068db4;
case 0x0c068db6u: goto P_0c068db6;
case 0x0c068db8u: goto P_0c068db8;
case 0x0c068dbau: goto P_0c068dba;
case 0x0c068dbcu: goto P_0c068dbc;
case 0x0c068dbeu: goto P_0c068dbe;
case 0x0c068dc0u: goto P_0c068dc0;
case 0x0c068dc2u: goto P_0c068dc2;
case 0x0c068dc4u: goto P_0c068dc4;
case 0x0c068dc6u: goto P_0c068dc6;
case 0x0c068dc8u: goto P_0c068dc8;
case 0x0c068dcau: goto P_0c068dca;
case 0x0c068dccu: goto P_0c068dcc;
case 0x0c068dceu: goto P_0c068dce;
case 0x0c068dd0u: goto P_0c068dd0;
case 0x0c068dd2u: goto P_0c068dd2;
case 0x0c068dd4u: goto P_0c068dd4;
case 0x0c068dd6u: goto P_0c068dd6;
case 0x0c068dd8u: goto P_0c068dd8;
case 0x0c068ddau: goto P_0c068dda;
case 0x0c068ddcu: goto P_0c068ddc;
case 0x0c068ddeu: goto P_0c068dde;
case 0x0c068de0u: goto P_0c068de0;
case 0x0c068de2u: goto P_0c068de2;
case 0x0c068de4u: goto P_0c068de4;
case 0x0c068de6u: goto P_0c068de6;
case 0x0c068de8u: goto P_0c068de8;
case 0x0c068deau: goto P_0c068dea;
case 0x0c068decu: goto P_0c068dec;
case 0x0c068deeu: goto P_0c068dee;
case 0x0c068df0u: goto P_0c068df0;
case 0x0c068df2u: goto P_0c068df2;
case 0x0c068df4u: goto P_0c068df4;
case 0x0c068df6u: goto P_0c068df6;
case 0x0c068df8u: goto P_0c068df8;
case 0x0c068dfau: goto P_0c068dfa;
case 0x0c068dfcu: goto P_0c068dfc;
case 0x0c068dfeu: goto P_0c068dfe;
case 0x0c068e00u: goto P_0c068e00;
case 0x0c068e02u: goto P_0c068e02;
case 0x0c068e04u: goto P_0c068e04;
case 0x0c068e06u: goto P_0c068e06;
case 0x0c068e08u: goto P_0c068e08;
case 0x0c068e0au: goto P_0c068e0a;
case 0x0c068e0cu: goto P_0c068e0c;
case 0x0c068f92u: goto P_0c068f92;
case 0x0c068f94u: goto P_0c068f94;
case 0x0c068f96u: goto P_0c068f96;
case 0x0c068f98u: goto P_0c068f98;
case 0x0c068f9au: goto P_0c068f9a;
case 0x0c068f9cu: goto P_0c068f9c;
case 0x0c068f9eu: goto P_0c068f9e;
case 0x0c068fa0u: goto P_0c068fa0;
case 0x0c068fa2u: goto P_0c068fa2;
case 0x0c068fa4u: goto P_0c068fa4;
case 0x0c068fa6u: goto P_0c068fa6;
case 0x0c068fa8u: goto P_0c068fa8;
case 0x0c068faau: goto P_0c068faa;
case 0x0c068facu: goto P_0c068fac;
case 0x0c068faeu: goto P_0c068fae;
case 0x0c068fb0u: goto P_0c068fb0;
case 0x0c068fb2u: goto P_0c068fb2;
case 0x0c068fb4u: goto P_0c068fb4;
case 0x0c068fb6u: goto P_0c068fb6;
case 0x0c068fb8u: goto P_0c068fb8;
case 0x0c068fbau: goto P_0c068fba;
case 0x0c068fbcu: goto P_0c068fbc;
case 0x0c068fbeu: goto P_0c068fbe;
case 0x0c068fc0u: goto P_0c068fc0;
case 0x0c068fc2u: goto P_0c068fc2;
case 0x0c068fc4u: goto P_0c068fc4;
case 0x0c068fc6u: goto P_0c068fc6;
case 0x0c068fe4u: goto P_0c068fe4;
case 0x0c068fe6u: goto P_0c068fe6;
case 0x0c068fe8u: goto P_0c068fe8;
case 0x0c068feau: goto P_0c068fea;
case 0x0c068fecu: goto P_0c068fec;
case 0x0c068feeu: goto P_0c068fee;
case 0x0c068ff0u: goto P_0c068ff0;
case 0x0c068ff2u: goto P_0c068ff2;
case 0x0c068ff4u: goto P_0c068ff4;
case 0x0c068ff6u: goto P_0c068ff6;
case 0x0c068ff8u: goto P_0c068ff8;
case 0x0c068ffau: goto P_0c068ffa;
case 0x0c068ffcu: goto P_0c068ffc;
case 0x0c068ffeu: goto P_0c068ffe;
case 0x0c069000u: goto P_0c069000;
case 0x0c069002u: goto P_0c069002;
case 0x0c069004u: goto P_0c069004;
case 0x0c069006u: goto P_0c069006;
case 0x0c069008u: goto P_0c069008;
case 0x0c06900au: goto P_0c06900a;
case 0x0c06900cu: goto P_0c06900c;
case 0x0c06900eu: goto P_0c06900e;
case 0x0c069010u: goto P_0c069010;
case 0x0c069012u: goto P_0c069012;
case 0x0c069014u: goto P_0c069014;
case 0x0c069016u: goto P_0c069016;
case 0x0c069018u: goto P_0c069018;
case 0x0c06901au: goto P_0c06901a;
case 0x0c06901cu: goto P_0c06901c;
case 0x0c06901eu: goto P_0c06901e;
case 0x0c069020u: goto P_0c069020;
case 0x0c069022u: goto P_0c069022;
case 0x0c069024u: goto P_0c069024;
case 0x0c069026u: goto P_0c069026;
case 0x0c069028u: goto P_0c069028;
case 0x0c06902au: goto P_0c06902a;
case 0x0c06902cu: goto P_0c06902c;
case 0x0c06902eu: goto P_0c06902e;
case 0x0c069030u: goto P_0c069030;
case 0x0c069032u: goto P_0c069032;
case 0x0c069034u: goto P_0c069034;
case 0x0c069036u: goto P_0c069036;
case 0x0c069038u: goto P_0c069038;
case 0x0c06903au: goto P_0c06903a;
case 0x0c06903cu: goto P_0c06903c;
case 0x0c06903eu: goto P_0c06903e;
case 0x0c069040u: goto P_0c069040;
case 0x0c069042u: goto P_0c069042;
case 0x0c069044u: goto P_0c069044;
case 0x0c069046u: goto P_0c069046;
case 0x0c069048u: goto P_0c069048;
case 0x0c06904au: goto P_0c06904a;
case 0x0c06904cu: goto P_0c06904c;
case 0x0c06904eu: goto P_0c06904e;
case 0x0c069050u: goto P_0c069050;
case 0x0c069052u: goto P_0c069052;
case 0x0c069054u: goto P_0c069054;
case 0x0c069056u: goto P_0c069056;
case 0x0c069058u: goto P_0c069058;
case 0x0c06905au: goto P_0c06905a;
case 0x0c06905cu: goto P_0c06905c;
case 0x0c06905eu: goto P_0c06905e;
case 0x0c069060u: goto P_0c069060;
case 0x0c069062u: goto P_0c069062;
case 0x0c069064u: goto P_0c069064;
case 0x0c069066u: goto P_0c069066;
case 0x0c069068u: goto P_0c069068;
case 0x0c06906au: goto P_0c06906a;
case 0x0c06906cu: goto P_0c06906c;
case 0x0c06906eu: goto P_0c06906e;
case 0x0c069070u: goto P_0c069070;
case 0x0c069072u: goto P_0c069072;
case 0x0c069074u: goto P_0c069074;
case 0x0c069076u: goto P_0c069076;
case 0x0c069078u: goto P_0c069078;
case 0x0c06907au: goto P_0c06907a;
case 0x0c06907cu: goto P_0c06907c;
case 0x0c06907eu: goto P_0c06907e;
case 0x0c069080u: goto P_0c069080;
case 0x0c069082u: goto P_0c069082;
case 0x0c069084u: goto P_0c069084;
case 0x0c069086u: goto P_0c069086;
case 0x0c069088u: goto P_0c069088;
case 0x0c06908au: goto P_0c06908a;
case 0x0c06908cu: goto P_0c06908c;
case 0x0c06908eu: goto P_0c06908e;
case 0x0c069090u: goto P_0c069090;
case 0x0c069092u: goto P_0c069092;
case 0x0c069094u: goto P_0c069094;
case 0x0c069096u: goto P_0c069096;
case 0x0c069098u: goto P_0c069098;
case 0x0c06909au: goto P_0c06909a;
case 0x0c06909cu: goto P_0c06909c;
case 0x0c06909eu: goto P_0c06909e;
case 0x0c0690a0u: goto P_0c0690a0;
case 0x0c0690a2u: goto P_0c0690a2;
case 0x0c0690a4u: goto P_0c0690a4;
case 0x0c0690a6u: goto P_0c0690a6;
case 0x0c0690a8u: goto P_0c0690a8;
case 0x0c0690aau: goto P_0c0690aa;
case 0x0c0690acu: goto P_0c0690ac;
case 0x0c0690aeu: goto P_0c0690ae;
case 0x0c0690b0u: goto P_0c0690b0;
case 0x0c0690b2u: goto P_0c0690b2;
case 0x0c0690b4u: goto P_0c0690b4;
case 0x0c0690b6u: goto P_0c0690b6;
case 0x0c0690b8u: goto P_0c0690b8;
case 0x0c0690bau: goto P_0c0690ba;
case 0x0c0690bcu: goto P_0c0690bc;
case 0x0c0690beu: goto P_0c0690be;
case 0x0c0690c0u: goto P_0c0690c0;
case 0x0c0690c2u: goto P_0c0690c2;
case 0x0c0690c4u: goto P_0c0690c4;
case 0x0c0690c6u: goto P_0c0690c6;
case 0x0c0690c8u: goto P_0c0690c8;
case 0x0c0690cau: goto P_0c0690ca;
case 0x0c0690ccu: goto P_0c0690cc;
case 0x0c0690ceu: goto P_0c0690ce;
case 0x0c0690d0u: goto P_0c0690d0;
case 0x0c0690d2u: goto P_0c0690d2;
case 0x0c0690d4u: goto P_0c0690d4;
case 0x0c0690d6u: goto P_0c0690d6;
case 0x0c0690d8u: goto P_0c0690d8;
case 0x0c0690dau: goto P_0c0690da;
case 0x0c0690dcu: goto P_0c0690dc;
case 0x0c0690deu: goto P_0c0690de;
case 0x0c0690e0u: goto P_0c0690e0;
case 0x0c0690e2u: goto P_0c0690e2;
case 0x0c0690e4u: goto P_0c0690e4;
case 0x0c0690e6u: goto P_0c0690e6;
case 0x0c0690e8u: goto P_0c0690e8;
case 0x0c0690eau: goto P_0c0690ea;
case 0x0c0690ecu: goto P_0c0690ec;
case 0x0c0690eeu: goto P_0c0690ee;
case 0x0c0690f0u: goto P_0c0690f0;
case 0x0c0690f2u: goto P_0c0690f2;
case 0x0c0690f4u: goto P_0c0690f4;
case 0x0c0690f6u: goto P_0c0690f6;
case 0x0c0690f8u: goto P_0c0690f8;
case 0x0c0690fau: goto P_0c0690fa;
case 0x0c0690fcu: goto P_0c0690fc;
case 0x0c0690feu: goto P_0c0690fe;
case 0x0c069100u: goto P_0c069100;
case 0x0c069102u: goto P_0c069102;
case 0x0c069104u: goto P_0c069104;
case 0x0c069106u: goto P_0c069106;
case 0x0c069108u: goto P_0c069108;
case 0x0c06910au: goto P_0c06910a;
case 0x0c06910cu: goto P_0c06910c;
case 0x0c06910eu: goto P_0c06910e;
case 0x0c069110u: goto P_0c069110;
case 0x0c069112u: goto P_0c069112;
case 0x0c069114u: goto P_0c069114;
default: return vf3_matrix_family(target,s,ram);
}
P_0c068d54: /* original 6043, guest PC 0x0c068d54 */
if(!s->budget--) { s->failed_pc=0x0c068d54u; return 0; }
r[0]=r[4];
goto P_0c068d56;
P_0c068d56: /* original 8802, guest PC 0x0c068d56 */
if(!s->budget--) { s->failed_pc=0x0c068d56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c068d58;
P_0c068d58: /* original 8902, guest PC 0x0c068d58 */
if(!s->budget--) { s->failed_pc=0x0c068d58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068d60; }
goto P_0c068d5a;
P_0c068d5a: /* original 6043, guest PC 0x0c068d5a */
if(!s->budget--) { s->failed_pc=0x0c068d5au; return 0; }
r[0]=r[4];
goto P_0c068d5c;
P_0c068d5c: /* original 8807, guest PC 0x0c068d5c */
if(!s->budget--) { s->failed_pc=0x0c068d5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c068d5e;
P_0c068d5e: /* original 8b08, guest PC 0x0c068d5e */
if(!s->budget--) { s->failed_pc=0x0c068d5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068d72; }
goto P_0c068d60;
P_0c068d60: /* original c73b, guest PC 0x0c068d60 */
if(!s->budget--) { s->failed_pc=0x0c068d60u; return 0; }
r[0]=code_base|0x00068e50u;
goto P_0c068d62;
P_0c068d62: /* original f358, guest PC 0x0c068d62 */
if(!s->budget--) { s->failed_pc=0x0c068d62u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c068d64;
P_0c068d64: /* original f408, guest PC 0x0c068d64 */
if(!s->budget--) { s->failed_pc=0x0c068d64u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068d66;
P_0c068d66: /* original f342, guest PC 0x0c068d66 */
if(!s->budget--) { s->failed_pc=0x0c068d66u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c068d68;
P_0c068d68: /* original f53a, guest PC 0x0c068d68 */
if(!s->budget--) { s->failed_pc=0x0c068d68u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c068d6a;
P_0c068d6a: /* original f268, guest PC 0x0c068d6a */
if(!s->budget--) { s->failed_pc=0x0c068d6au; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c068d6c;
P_0c068d6c: /* original f242, guest PC 0x0c068d6c */
if(!s->budget--) { s->failed_pc=0x0c068d6cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c068d6e;
P_0c068d6e: /* original 000b, guest PC 0x0c068d6e */
if(!s->budget--) { s->failed_pc=0x0c068d6eu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[6]);
s->pc=target; return ram->oob==0;
P_0c068d70: /* original f62a, guest PC 0x0c068d70 */
if(!s->budget--) { s->failed_pc=0x0c068d70u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c068d72;
P_0c068d72: /* original 880d, guest PC 0x0c068d72 */
if(!s->budget--) { s->failed_pc=0x0c068d72u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c068d74;
P_0c068d74: /* original 8b34, guest PC 0x0c068d74 */
if(!s->budget--) { s->failed_pc=0x0c068d74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068de0; }
goto P_0c068d76;
P_0c068d76: /* original c737, guest PC 0x0c068d76 */
if(!s->budget--) { s->failed_pc=0x0c068d76u; return 0; }
r[0]=code_base|0x00068e54u;
goto P_0c068d78;
P_0c068d78: /* original f458, guest PC 0x0c068d78 */
if(!s->budget--) { s->failed_pc=0x0c068d78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c068d7a;
P_0c068d7a: /* original f508, guest PC 0x0c068d7a */
if(!s->budget--) { s->failed_pc=0x0c068d7au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c068d7c;
P_0c068d7c: /* original f452, guest PC 0x0c068d7c */
if(!s->budget--) { s->failed_pc=0x0c068d7cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c068d7e;
P_0c068d7e: /* original f35c, guest PC 0x0c068d7e */
if(!s->budget--) { s->failed_pc=0x0c068d7eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068d80;
P_0c068d80: /* original f568, guest PC 0x0c068d80 */
if(!s->budget--) { s->failed_pc=0x0c068d80u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c068d82;
P_0c068d82: /* original f532, guest PC 0x0c068d82 */
if(!s->budget--) { s->failed_pc=0x0c068d82u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c068d84;
P_0c068d84: /* original f43d, guest PC 0x0c068d84 */
if(!s->budget--) { s->failed_pc=0x0c068d84u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c068d86;
P_0c068d86: /* original 045a, guest PC 0x0c068d86 */
if(!s->budget--) { s->failed_pc=0x0c068d86u; return 0; }
r[4]=r[53];
goto P_0c068d88;
P_0c068d88: /* original f53d, guest PC 0x0c068d88 */
if(!s->budget--) { s->failed_pc=0x0c068d88u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c068d8a;
P_0c068d8a: /* original 2448, guest PC 0x0c068d8a */
if(!s->budget--) { s->failed_pc=0x0c068d8au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c068d8c;
P_0c068d8c: /* original 8d13, guest PC 0x0c068d8c */
if(!s->budget--) { s->failed_pc=0x0c068d8cu; return 0; }
cond=r[17]&1u;
r[7]=r[53];
if(cond) { goto P_0c068db6; }
goto P_0c068d90;
P_0c068d8e: /* original 075a, guest PC 0x0c068d8e */
if(!s->budget--) { s->failed_pc=0x0c068d8eu; return 0; }
r[7]=r[53];
goto P_0c068d90;
P_0c068d90: /* original e201, guest PC 0x0c068d90 */
if(!s->budget--) { s->failed_pc=0x0c068d90u; return 0; }
r[2]=0x00000001u;
goto P_0c068d92;
P_0c068d92: /* original 2248, guest PC 0x0c068d92 */
if(!s->budget--) { s->failed_pc=0x0c068d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c068d94;
P_0c068d94: /* original 8905, guest PC 0x0c068d94 */
if(!s->budget--) { s->failed_pc=0x0c068d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068da2; }
goto P_0c068d96;
P_0c068d96: /* original d130, guest PC 0x0c068d96 */
if(!s->budget--) { s->failed_pc=0x0c068d96u; return 0; }
r[1]=read(ram,0x0c068e58u,4);
goto P_0c068d98;
P_0c068d98: /* original 2148, guest PC 0x0c068d98 */
if(!s->budget--) { s->failed_pc=0x0c068d98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c068d9a;
P_0c068d9a: /* original 8901, guest PC 0x0c068d9a */
if(!s->budget--) { s->failed_pc=0x0c068d9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068da0; }
goto P_0c068d9c;
P_0c068d9c: /* original a001, guest PC 0x0c068d9c */
if(!s->budget--) { s->failed_pc=0x0c068d9cu; return 0; }
r[4]+=0xffffffffu;
goto P_0c068da2;
P_0c068d9e: /* original 74ff, guest PC 0x0c068d9e */
if(!s->budget--) { s->failed_pc=0x0c068d9eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c068da0;
P_0c068da0: /* original 7401, guest PC 0x0c068da0 */
if(!s->budget--) { s->failed_pc=0x0c068da0u; return 0; }
r[4]+=0x00000001u;
goto P_0c068da2;
P_0c068da2: /* original 6343, guest PC 0x0c068da2 */
if(!s->budget--) { s->failed_pc=0x0c068da2u; return 0; }
r[3]=r[4];
goto P_0c068da4;
P_0c068da4: /* original 4408, guest PC 0x0c068da4 */
if(!s->budget--) { s->failed_pc=0x0c068da4u; return 0; }
r[4]<<=2;
goto P_0c068da6;
P_0c068da6: /* original 343c, guest PC 0x0c068da6 */
if(!s->budget--) { s->failed_pc=0x0c068da6u; return 0; }
r[4]+=r[3];
goto P_0c068da8;
P_0c068da8: /* original f258, guest PC 0x0c068da8 */
if(!s->budget--) { s->failed_pc=0x0c068da8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c068daa;
P_0c068daa: /* original 4400, guest PC 0x0c068daa */
if(!s->budget--) { s->failed_pc=0x0c068daau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c068dac;
P_0c068dac: /* original 445a, guest PC 0x0c068dac */
if(!s->budget--) { s->failed_pc=0x0c068dacu; return 0; }
r[53]=r[4];
goto P_0c068dae;
P_0c068dae: /* original f32d, guest PC 0x0c068dae */
if(!s->budget--) { s->failed_pc=0x0c068daeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068db0;
P_0c068db0: /* original f43c, guest PC 0x0c068db0 */
if(!s->budget--) { s->failed_pc=0x0c068db0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c068db2;
P_0c068db2: /* original f241, guest PC 0x0c068db2 */
if(!s->budget--) { s->failed_pc=0x0c068db2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c068db4;
P_0c068db4: /* original f52a, guest PC 0x0c068db4 */
if(!s->budget--) { s->failed_pc=0x0c068db4u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c068db6;
P_0c068db6: /* original 2778, guest PC 0x0c068db6 */
if(!s->budget--) { s->failed_pc=0x0c068db6u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c068db8;
P_0c068db8: /* original 8912, guest PC 0x0c068db8 */
if(!s->budget--) { s->failed_pc=0x0c068db8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068de0; }
goto P_0c068dba;
P_0c068dba: /* original e201, guest PC 0x0c068dba */
if(!s->budget--) { s->failed_pc=0x0c068dbau; return 0; }
r[2]=0x00000001u;
goto P_0c068dbc;
P_0c068dbc: /* original 2278, guest PC 0x0c068dbc */
if(!s->budget--) { s->failed_pc=0x0c068dbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c068dbe;
P_0c068dbe: /* original 8905, guest PC 0x0c068dbe */
if(!s->budget--) { s->failed_pc=0x0c068dbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068dcc; }
goto P_0c068dc0;
P_0c068dc0: /* original d125, guest PC 0x0c068dc0 */
if(!s->budget--) { s->failed_pc=0x0c068dc0u; return 0; }
r[1]=read(ram,0x0c068e58u,4);
goto P_0c068dc2;
P_0c068dc2: /* original 2178, guest PC 0x0c068dc2 */
if(!s->budget--) { s->failed_pc=0x0c068dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[7])==0)!=0);
goto P_0c068dc4;
P_0c068dc4: /* original 8901, guest PC 0x0c068dc4 */
if(!s->budget--) { s->failed_pc=0x0c068dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068dca; }
goto P_0c068dc6;
P_0c068dc6: /* original a001, guest PC 0x0c068dc6 */
if(!s->budget--) { s->failed_pc=0x0c068dc6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c068dcc;
P_0c068dc8: /* original 77ff, guest PC 0x0c068dc8 */
if(!s->budget--) { s->failed_pc=0x0c068dc8u; return 0; }
r[7]+=0xffffffffu;
goto P_0c068dca;
P_0c068dca: /* original 7701, guest PC 0x0c068dca */
if(!s->budget--) { s->failed_pc=0x0c068dcau; return 0; }
r[7]+=0x00000001u;
goto P_0c068dcc;
P_0c068dcc: /* original 6373, guest PC 0x0c068dcc */
if(!s->budget--) { s->failed_pc=0x0c068dccu; return 0; }
r[3]=r[7];
goto P_0c068dce;
P_0c068dce: /* original 4708, guest PC 0x0c068dce */
if(!s->budget--) { s->failed_pc=0x0c068dceu; return 0; }
r[7]<<=2;
goto P_0c068dd0;
P_0c068dd0: /* original 373c, guest PC 0x0c068dd0 */
if(!s->budget--) { s->failed_pc=0x0c068dd0u; return 0; }
r[7]+=r[3];
goto P_0c068dd2;
P_0c068dd2: /* original f268, guest PC 0x0c068dd2 */
if(!s->budget--) { s->failed_pc=0x0c068dd2u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c068dd4;
P_0c068dd4: /* original 4700, guest PC 0x0c068dd4 */
if(!s->budget--) { s->failed_pc=0x0c068dd4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c068dd6;
P_0c068dd6: /* original 475a, guest PC 0x0c068dd6 */
if(!s->budget--) { s->failed_pc=0x0c068dd6u; return 0; }
r[53]=r[7];
goto P_0c068dd8;
P_0c068dd8: /* original f32d, guest PC 0x0c068dd8 */
if(!s->budget--) { s->failed_pc=0x0c068dd8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068dda;
P_0c068dda: /* original f43c, guest PC 0x0c068dda */
if(!s->budget--) { s->failed_pc=0x0c068ddau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c068ddc;
P_0c068ddc: /* original f241, guest PC 0x0c068ddc */
if(!s->budget--) { s->failed_pc=0x0c068ddcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c068dde;
P_0c068dde: /* original f62a, guest PC 0x0c068dde */
if(!s->budget--) { s->failed_pc=0x0c068ddeu; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c068de0;
P_0c068de0: /* original 000b, guest PC 0x0c068de0 */
if(!s->budget--) { s->failed_pc=0x0c068de0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068de2: /* original 0009, guest PC 0x0c068de2 */
if(!s->budget--) { s->failed_pc=0x0c068de2u; return 0; }
goto P_0c068de4;
P_0c068de4: /* original c71d, guest PC 0x0c068de4 */
if(!s->budget--) { s->failed_pc=0x0c068de4u; return 0; }
r[0]=code_base|0x00068e5cu;
goto P_0c068de6;
P_0c068de6: /* original f45d, guest PC 0x0c068de6 */
if(!s->budget--) { s->failed_pc=0x0c068de6u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c068de8;
P_0c068de8: /* original f608, guest PC 0x0c068de8 */
if(!s->budget--) { s->failed_pc=0x0c068de8u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c068dea;
P_0c068dea: /* original f55d, guest PC 0x0c068dea */
if(!s->budget--) { s->failed_pc=0x0c068deau; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c068dec;
P_0c068dec: /* original f465, guest PC 0x0c068dec */
if(!s->budget--) { s->failed_pc=0x0c068decu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c068dee;
P_0c068dee: /* original 8d02, guest PC 0x0c068dee */
if(!s->budget--) { s->failed_pc=0x0c068deeu; return 0; }
cond=r[17]&1u;
fr[7]=0;
if(cond) { goto P_0c068df6; }
goto P_0c068df2;
P_0c068df0: /* original f78d, guest PC 0x0c068df0 */
if(!s->budget--) { s->failed_pc=0x0c068df0u; return 0; }
fr[7]=0;
goto P_0c068df2;
P_0c068df2: /* original f565, guest PC 0x0c068df2 */
if(!s->budget--) { s->failed_pc=0x0c068df2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c068df4;
P_0c068df4: /* original 8b02, guest PC 0x0c068df4 */
if(!s->budget--) { s->failed_pc=0x0c068df4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068dfc; }
goto P_0c068df6;
P_0c068df6: /* original c71a, guest PC 0x0c068df6 */
if(!s->budget--) { s->failed_pc=0x0c068df6u; return 0; }
r[0]=code_base|0x00068e60u;
goto P_0c068df8;
P_0c068df8: /* original a001, guest PC 0x0c068df8 */
if(!s->budget--) { s->failed_pc=0x0c068df8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068dfe;
P_0c068dfa: /* original f408, guest PC 0x0c068dfa */
if(!s->budget--) { s->failed_pc=0x0c068dfau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068dfc;
P_0c068dfc: /* original f47c, guest PC 0x0c068dfc */
if(!s->budget--) { s->failed_pc=0x0c068dfcu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c068dfe;
P_0c068dfe: /* original e008, guest PC 0x0c068dfe */
if(!s->budget--) { s->failed_pc=0x0c068dfeu; return 0; }
r[0]=0x00000008u;
goto P_0c068e00;
P_0c068e00: /* original f477, guest PC 0x0c068e00 */
if(!s->budget--) { s->failed_pc=0x0c068e00u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c068e02;
P_0c068e02: /* original e004, guest PC 0x0c068e02 */
if(!s->budget--) { s->failed_pc=0x0c068e02u; return 0; }
r[0]=0x00000004u;
goto P_0c068e04;
P_0c068e04: /* original f47a, guest PC 0x0c068e04 */
if(!s->budget--) { s->failed_pc=0x0c068e04u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c068e06;
P_0c068e06: /* original f39d, guest PC 0x0c068e06 */
if(!s->budget--) { s->failed_pc=0x0c068e06u; return 0; }
fr[3]=0x3f800000u;
goto P_0c068e08;
P_0c068e08: /* original f437, guest PC 0x0c068e08 */
if(!s->budget--) { s->failed_pc=0x0c068e08u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c068e0a;
P_0c068e0a: /* original 000b, guest PC 0x0c068e0a */
if(!s->budget--) { s->failed_pc=0x0c068e0au; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c068e0c: /* original f04c, guest PC 0x0c068e0c */
if(!s->budget--) { s->failed_pc=0x0c068e0cu; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c068e0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068e0eu; return 0; } return 1;
P_0c068f92: /* original f35c, guest PC 0x0c068f92 */
if(!s->budget--) { s->failed_pc=0x0c068f92u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068f94;
P_0c068f94: /* original f861, guest PC 0x0c068f94 */
if(!s->budget--) { s->failed_pc=0x0c068f94u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c068f96;
P_0c068f96: /* original f57c, guest PC 0x0c068f96 */
if(!s->budget--) { s->failed_pc=0x0c068f96u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c068f98;
P_0c068f98: /* original f531, guest PC 0x0c068f98 */
if(!s->budget--) { s->failed_pc=0x0c068f98u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c068f9a;
P_0c068f9a: /* original f34c, guest PC 0x0c068f9a */
if(!s->budget--) { s->failed_pc=0x0c068f9au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c068f9c;
P_0c068f9c: /* original f46c, guest PC 0x0c068f9c */
if(!s->budget--) { s->failed_pc=0x0c068f9cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c068f9e;
P_0c068f9e: /* original f431, guest PC 0x0c068f9e */
if(!s->budget--) { s->failed_pc=0x0c068f9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c068fa0;
P_0c068fa0: /* original f69c, guest PC 0x0c068fa0 */
if(!s->budget--) { s->failed_pc=0x0c068fa0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c068fa2;
P_0c068fa2: /* original f671, guest PC 0x0c068fa2 */
if(!s->budget--) { s->failed_pc=0x0c068fa2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c068fa4;
P_0c068fa4: /* original f582, guest PC 0x0c068fa4 */
if(!s->budget--) { s->failed_pc=0x0c068fa4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c068fa6;
P_0c068fa6: /* original f28d, guest PC 0x0c068fa6 */
if(!s->budget--) { s->failed_pc=0x0c068fa6u; return 0; }
fr[2]=0;
goto P_0c068fa8;
P_0c068fa8: /* original f462, guest PC 0x0c068fa8 */
if(!s->budget--) { s->failed_pc=0x0c068fa8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c068faa;
P_0c068faa: /* original f34c, guest PC 0x0c068faa */
if(!s->budget--) { s->failed_pc=0x0c068faau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c068fac;
P_0c068fac: /* original f45c, guest PC 0x0c068fac */
if(!s->budget--) { s->failed_pc=0x0c068facu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c068fae;
P_0c068fae: /* original f431, guest PC 0x0c068fae */
if(!s->budget--) { s->failed_pc=0x0c068faeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c068fb0;
P_0c068fb0: /* original f425, guest PC 0x0c068fb0 */
if(!s->budget--) { s->failed_pc=0x0c068fb0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c068fb2;
P_0c068fb2: /* original 8b01, guest PC 0x0c068fb2 */
if(!s->budget--) { s->failed_pc=0x0c068fb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068fb8; }
goto P_0c068fb4;
P_0c068fb4: /* original 000b, guest PC 0x0c068fb4 */
if(!s->budget--) { s->failed_pc=0x0c068fb4u; return 0; }
target=r[16];
r[0]=0x00000002u;
s->pc=target; return ram->oob==0;
P_0c068fb6: /* original e002, guest PC 0x0c068fb6 */
if(!s->budget--) { s->failed_pc=0x0c068fb6u; return 0; }
r[0]=0x00000002u;
goto P_0c068fb8;
P_0c068fb8: /* original f38d, guest PC 0x0c068fb8 */
if(!s->budget--) { s->failed_pc=0x0c068fb8u; return 0; }
fr[3]=0;
goto P_0c068fba;
P_0c068fba: /* original f434, guest PC 0x0c068fba */
if(!s->budget--) { s->failed_pc=0x0c068fbau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c068fbc;
P_0c068fbc: /* original 8b01, guest PC 0x0c068fbc */
if(!s->budget--) { s->failed_pc=0x0c068fbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068fc2; }
goto P_0c068fbe;
P_0c068fbe: /* original 000b, guest PC 0x0c068fbe */
if(!s->budget--) { s->failed_pc=0x0c068fbeu; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c068fc0: /* original e001, guest PC 0x0c068fc0 */
if(!s->budget--) { s->failed_pc=0x0c068fc0u; return 0; }
r[0]=0x00000001u;
goto P_0c068fc2;
P_0c068fc2: /* original e004, guest PC 0x0c068fc2 */
if(!s->budget--) { s->failed_pc=0x0c068fc2u; return 0; }
r[0]=0x00000004u;
goto P_0c068fc4;
P_0c068fc4: /* original 000b, guest PC 0x0c068fc4 */
if(!s->budget--) { s->failed_pc=0x0c068fc4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068fc6: /* original 0009, guest PC 0x0c068fc6 */
if(!s->budget--) { s->failed_pc=0x0c068fc6u; return 0; }
if(!vf3_matrix_family(0x0c068fc8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068fc8u; return 0; } return 1;
P_0c068fe4: /* original 2fe6, guest PC 0x0c068fe4 */
if(!s->budget--) { s->failed_pc=0x0c068fe4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fe6;
P_0c068fe6: /* original 2fd6, guest PC 0x0c068fe6 */
if(!s->budget--) { s->failed_pc=0x0c068fe6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fe8;
P_0c068fe8: /* original 2fc6, guest PC 0x0c068fe8 */
if(!s->budget--) { s->failed_pc=0x0c068fe8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fea;
P_0c068fea: /* original 2fb6, guest PC 0x0c068fea */
if(!s->budget--) { s->failed_pc=0x0c068feau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fec;
P_0c068fec: /* original 2fa6, guest PC 0x0c068fec */
if(!s->budget--) { s->failed_pc=0x0c068fecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fee;
P_0c068fee: /* original 2f96, guest PC 0x0c068fee */
if(!s->budget--) { s->failed_pc=0x0c068feeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ff0;
P_0c068ff0: /* original fffb, guest PC 0x0c068ff0 */
if(!s->budget--) { s->failed_pc=0x0c068ff0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c068ff2;
P_0c068ff2: /* original ffeb, guest PC 0x0c068ff2 */
if(!s->budget--) { s->failed_pc=0x0c068ff2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c068ff4;
P_0c068ff4: /* original d348, guest PC 0x0c068ff4 */
if(!s->budget--) { s->failed_pc=0x0c068ff4u; return 0; }
r[3]=read(ram,0x0c069118u,4);
goto P_0c068ff6;
P_0c068ff6: /* original 4f22, guest PC 0x0c068ff6 */
if(!s->budget--) { s->failed_pc=0x0c068ff6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068ff8;
P_0c068ff8: /* original 6742, guest PC 0x0c068ff8 */
if(!s->budget--) { s->failed_pc=0x0c068ff8u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c068ffa;
P_0c068ffa: /* original 5541, guest PC 0x0c068ffa */
if(!s->budget--) { s->failed_pc=0x0c068ffau; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c068ffc;
P_0c068ffc: /* original e401, guest PC 0x0c068ffc */
if(!s->budget--) { s->failed_pc=0x0c068ffcu; return 0; }
r[4]=0x00000001u;
goto P_0c068ffe;
P_0c068ffe: /* original 6632, guest PC 0x0c068ffe */
if(!s->budget--) { s->failed_pc=0x0c068ffeu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c069000;
P_0c069000: /* original 2748, guest PC 0x0c069000 */
if(!s->budget--) { s->failed_pc=0x0c069000u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[4])==0)!=0);
goto P_0c069002;
P_0c069002: /* original 7ffc, guest PC 0x0c069002 */
if(!s->budget--) { s->failed_pc=0x0c069002u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c069004;
P_0c069004: /* original 8d02, guest PC 0x0c069004 */
if(!s->budget--) { s->failed_pc=0x0c069004u; return 0; }
cond=r[17]&1u;
r[5]+=r[6];
if(cond) { goto P_0c06900c; }
goto P_0c069008;
P_0c069006: /* original 356c, guest PC 0x0c069006 */
if(!s->budget--) { s->failed_pc=0x0c069006u; return 0; }
r[5]+=r[6];
goto P_0c069008;
P_0c069008: /* original a07a, guest PC 0x0c069008 */
if(!s->budget--) { s->failed_pc=0x0c069008u; return 0; }
r[0]=0x00000001u;
goto P_0c069100;
P_0c06900a: /* original e001, guest PC 0x0c06900a */
if(!s->budget--) { s->failed_pc=0x0c06900au; return 0; }
r[0]=0x00000001u;
goto P_0c06900c;
P_0c06900c: /* original e018, guest PC 0x0c06900c */
if(!s->budget--) { s->failed_pc=0x0c06900cu; return 0; }
r[0]=0x00000018u;
goto P_0c06900e;
P_0c06900e: /* original fe4c, guest PC 0x0c06900e */
if(!s->budget--) { s->failed_pc=0x0c06900eu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c069010;
P_0c069010: /* original 6752, guest PC 0x0c069010 */
if(!s->budget--) { s->failed_pc=0x0c069010u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c069012;
P_0c069012: /* original 2749, guest PC 0x0c069012 */
if(!s->budget--) { s->failed_pc=0x0c069012u; return 0; }
r[7]&=r[4];
goto P_0c069014;
P_0c069014: /* original 2f72, guest PC 0x0c069014 */
if(!s->budget--) { s->failed_pc=0x0c069014u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c069016;
P_0c069016: /* original f456, guest PC 0x0c069016 */
if(!s->budget--) { s->failed_pc=0x0c069016u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c069018;
P_0c069018: /* original f38d, guest PC 0x0c069018 */
if(!s->budget--) { s->failed_pc=0x0c069018u; return 0; }
fr[3]=0;
goto P_0c06901a;
P_0c06901a: /* original f434, guest PC 0x0c06901a */
if(!s->budget--) { s->failed_pc=0x0c06901au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06901c;
P_0c06901c: /* original 8d6f, guest PC 0x0c06901c */
if(!s->budget--) { s->failed_pc=0x0c06901cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,5);
if(cond) { goto P_0c0690fe; }
goto P_0c069020;
P_0c06901e: /* original ff5c, guest PC 0x0c06901e */
if(!s->budget--) { s->failed_pc=0x0c06901eu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c069020;
P_0c069020: /* original 5451, guest PC 0x0c069020 */
if(!s->budget--) { s->failed_pc=0x0c069020u; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c069022;
P_0c069022: /* original e008, guest PC 0x0c069022 */
if(!s->budget--) { s->failed_pc=0x0c069022u; return 0; }
r[0]=0x00000008u;
goto P_0c069024;
P_0c069024: /* original f5fc, guest PC 0x0c069024 */
if(!s->budget--) { s->failed_pc=0x0c069024u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069026;
P_0c069026: /* original 346c, guest PC 0x0c069026 */
if(!s->budget--) { s->failed_pc=0x0c069026u; return 0; }
r[4]+=r[6];
goto P_0c069028;
P_0c069028: /* original 6d43, guest PC 0x0c069028 */
if(!s->budget--) { s->failed_pc=0x0c069028u; return 0; }
r[13]=r[4];
goto P_0c06902a;
P_0c06902a: /* original 5452, guest PC 0x0c06902a */
if(!s->budget--) { s->failed_pc=0x0c06902au; return 0; }
r[4]=read(ram,r[5]+8,4);
goto P_0c06902c;
P_0c06902c: /* original f6d8, guest PC 0x0c06902c */
if(!s->budget--) { s->failed_pc=0x0c06902cu; return 0; }
vf3_matrix_load(s,ram,6,r[13]);
goto P_0c06902e;
P_0c06902e: /* original 346c, guest PC 0x0c06902e */
if(!s->budget--) { s->failed_pc=0x0c06902eu; return 0; }
r[4]+=r[6];
goto P_0c069030;
P_0c069030: /* original f7d6, guest PC 0x0c069030 */
if(!s->budget--) { s->failed_pc=0x0c069030u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c069032;
P_0c069032: /* original 6b43, guest PC 0x0c069032 */
if(!s->budget--) { s->failed_pc=0x0c069032u; return 0; }
r[11]=r[4];
goto P_0c069034;
P_0c069034: /* original 5453, guest PC 0x0c069034 */
if(!s->budget--) { s->failed_pc=0x0c069034u; return 0; }
r[4]=read(ram,r[5]+12,4);
goto P_0c069036;
P_0c069036: /* original f8b8, guest PC 0x0c069036 */
if(!s->budget--) { s->failed_pc=0x0c069036u; return 0; }
vf3_matrix_load(s,ram,8,r[11]);
goto P_0c069038;
P_0c069038: /* original 346c, guest PC 0x0c069038 */
if(!s->budget--) { s->failed_pc=0x0c069038u; return 0; }
r[4]+=r[6];
goto P_0c06903a;
P_0c06903a: /* original f9b6, guest PC 0x0c06903a */
if(!s->budget--) { s->failed_pc=0x0c06903au; return 0; }
vf3_matrix_load(s,ram,9,r[11]+r[0]);
goto P_0c06903c;
P_0c06903c: /* original 6c43, guest PC 0x0c06903c */
if(!s->budget--) { s->failed_pc=0x0c06903cu; return 0; }
r[12]=r[4];
goto P_0c06903e;
P_0c06903e: /* original 5454, guest PC 0x0c06903e */
if(!s->budget--) { s->failed_pc=0x0c06903eu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c069040;
P_0c069040: /* original 346c, guest PC 0x0c069040 */
if(!s->budget--) { s->failed_pc=0x0c069040u; return 0; }
r[4]+=r[6];
goto P_0c069042;
P_0c069042: /* original 6a43, guest PC 0x0c069042 */
if(!s->budget--) { s->failed_pc=0x0c069042u; return 0; }
r[10]=r[4];
goto P_0c069044;
P_0c069044: /* original bfa5, guest PC 0x0c069044 */
if(!s->budget--) { s->failed_pc=0x0c069044u; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c069048u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069048u) { target=s->pc; goto dispatch; }
goto P_0c069048;
P_0c069046: /* original f4ec, guest PC 0x0c069046 */
if(!s->budget--) { s->failed_pc=0x0c069046u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c069048;
P_0c069048: /* original 6e03, guest PC 0x0c069048 */
if(!s->budget--) { s->failed_pc=0x0c069048u; return 0; }
r[14]=r[0];
goto P_0c06904a;
P_0c06904a: /* original e008, guest PC 0x0c06904a */
if(!s->budget--) { s->failed_pc=0x0c06904au; return 0; }
r[0]=0x00000008u;
goto P_0c06904c;
P_0c06904c: /* original f7b6, guest PC 0x0c06904c */
if(!s->budget--) { s->failed_pc=0x0c06904cu; return 0; }
vf3_matrix_load(s,ram,7,r[11]+r[0]);
goto P_0c06904e;
P_0c06904e: /* original f6b8, guest PC 0x0c06904e */
if(!s->budget--) { s->failed_pc=0x0c06904eu; return 0; }
vf3_matrix_load(s,ram,6,r[11]);
goto P_0c069050;
P_0c069050: /* original f9c6, guest PC 0x0c069050 */
if(!s->budget--) { s->failed_pc=0x0c069050u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c069052;
P_0c069052: /* original f8c8, guest PC 0x0c069052 */
if(!s->budget--) { s->failed_pc=0x0c069052u; return 0; }
vf3_matrix_load(s,ram,8,r[12]);
goto P_0c069054;
P_0c069054: /* original f5fc, guest PC 0x0c069054 */
if(!s->budget--) { s->failed_pc=0x0c069054u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069056;
P_0c069056: /* original bf9c, guest PC 0x0c069056 */
if(!s->budget--) { s->failed_pc=0x0c069056u; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c06905au;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06905au) { target=s->pc; goto dispatch; }
goto P_0c06905a;
P_0c069058: /* original f4ec, guest PC 0x0c069058 */
if(!s->budget--) { s->failed_pc=0x0c069058u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06905a;
P_0c06905a: /* original 6903, guest PC 0x0c06905a */
if(!s->budget--) { s->failed_pc=0x0c06905au; return 0; }
r[9]=r[0];
goto P_0c06905c;
P_0c06905c: /* original e008, guest PC 0x0c06905c */
if(!s->budget--) { s->failed_pc=0x0c06905cu; return 0; }
r[0]=0x00000008u;
goto P_0c06905e;
P_0c06905e: /* original f7c6, guest PC 0x0c06905e */
if(!s->budget--) { s->failed_pc=0x0c06905eu; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c069060;
P_0c069060: /* original f6c8, guest PC 0x0c069060 */
if(!s->budget--) { s->failed_pc=0x0c069060u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c069062;
P_0c069062: /* original f9d6, guest PC 0x0c069062 */
if(!s->budget--) { s->failed_pc=0x0c069062u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c069064;
P_0c069064: /* original f8d8, guest PC 0x0c069064 */
if(!s->budget--) { s->failed_pc=0x0c069064u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c069066;
P_0c069066: /* original f5fc, guest PC 0x0c069066 */
if(!s->budget--) { s->failed_pc=0x0c069066u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069068;
P_0c069068: /* original bf93, guest PC 0x0c069068 */
if(!s->budget--) { s->failed_pc=0x0c069068u; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c06906cu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06906cu) { target=s->pc; goto dispatch; }
goto P_0c06906c;
P_0c06906a: /* original f4ec, guest PC 0x0c06906a */
if(!s->budget--) { s->failed_pc=0x0c06906au; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06906c;
P_0c06906c: /* original 6b03, guest PC 0x0c06906c */
if(!s->budget--) { s->failed_pc=0x0c06906cu; return 0; }
r[11]=r[0];
goto P_0c06906e;
P_0c06906e: /* original e008, guest PC 0x0c06906e */
if(!s->budget--) { s->failed_pc=0x0c06906eu; return 0; }
r[0]=0x00000008u;
goto P_0c069070;
P_0c069070: /* original f7c6, guest PC 0x0c069070 */
if(!s->budget--) { s->failed_pc=0x0c069070u; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c069072;
P_0c069072: /* original f6c8, guest PC 0x0c069072 */
if(!s->budget--) { s->failed_pc=0x0c069072u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c069074;
P_0c069074: /* original f9a6, guest PC 0x0c069074 */
if(!s->budget--) { s->failed_pc=0x0c069074u; return 0; }
vf3_matrix_load(s,ram,9,r[10]+r[0]);
goto P_0c069076;
P_0c069076: /* original f8a8, guest PC 0x0c069076 */
if(!s->budget--) { s->failed_pc=0x0c069076u; return 0; }
vf3_matrix_load(s,ram,8,r[10]);
goto P_0c069078;
P_0c069078: /* original f5fc, guest PC 0x0c069078 */
if(!s->budget--) { s->failed_pc=0x0c069078u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06907a;
P_0c06907a: /* original bf8a, guest PC 0x0c06907a */
if(!s->budget--) { s->failed_pc=0x0c06907au; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c06907eu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06907eu) { target=s->pc; goto dispatch; }
goto P_0c06907e;
P_0c06907c: /* original f4ec, guest PC 0x0c06907c */
if(!s->budget--) { s->failed_pc=0x0c06907cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06907e;
P_0c06907e: /* original 6c03, guest PC 0x0c06907e */
if(!s->budget--) { s->failed_pc=0x0c06907eu; return 0; }
r[12]=r[0];
goto P_0c069080;
P_0c069080: /* original e008, guest PC 0x0c069080 */
if(!s->budget--) { s->failed_pc=0x0c069080u; return 0; }
r[0]=0x00000008u;
goto P_0c069082;
P_0c069082: /* original f7a6, guest PC 0x0c069082 */
if(!s->budget--) { s->failed_pc=0x0c069082u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c069084;
P_0c069084: /* original f6a8, guest PC 0x0c069084 */
if(!s->budget--) { s->failed_pc=0x0c069084u; return 0; }
vf3_matrix_load(s,ram,6,r[10]);
goto P_0c069086;
P_0c069086: /* original f9d6, guest PC 0x0c069086 */
if(!s->budget--) { s->failed_pc=0x0c069086u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c069088;
P_0c069088: /* original f8d8, guest PC 0x0c069088 */
if(!s->budget--) { s->failed_pc=0x0c069088u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c06908a;
P_0c06908a: /* original f5fc, guest PC 0x0c06908a */
if(!s->budget--) { s->failed_pc=0x0c06908au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06908c;
P_0c06908c: /* original bf81, guest PC 0x0c06908c */
if(!s->budget--) { s->failed_pc=0x0c06908cu; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c069090u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069090u) { target=s->pc; goto dispatch; }
goto P_0c069090;
P_0c06908e: /* original f4ec, guest PC 0x0c06908e */
if(!s->budget--) { s->failed_pc=0x0c06908eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c069090;
P_0c069090: /* original 6293, guest PC 0x0c069090 */
if(!s->budget--) { s->failed_pc=0x0c069090u; return 0; }
r[2]=r[9];
goto P_0c069092;
P_0c069092: /* original e402, guest PC 0x0c069092 */
if(!s->budget--) { s->failed_pc=0x0c069092u; return 0; }
r[4]=0x00000002u;
goto P_0c069094;
P_0c069094: /* original e504, guest PC 0x0c069094 */
if(!s->budget--) { s->failed_pc=0x0c069094u; return 0; }
r[5]=0x00000004u;
goto P_0c069096;
P_0c069096: /* original 6303, guest PC 0x0c069096 */
if(!s->budget--) { s->failed_pc=0x0c069096u; return 0; }
r[3]=r[0];
goto P_0c069098;
P_0c069098: /* original 2249, guest PC 0x0c069098 */
if(!s->budget--) { s->failed_pc=0x0c069098u; return 0; }
r[2]&=r[4];
goto P_0c06909a;
P_0c06909a: /* original 6603, guest PC 0x0c06909a */
if(!s->budget--) { s->failed_pc=0x0c06909au; return 0; }
r[6]=r[0];
goto P_0c06909c;
P_0c06909c: /* original 2959, guest PC 0x0c06909c */
if(!s->budget--) { s->failed_pc=0x0c06909cu; return 0; }
r[9]&=r[5];
goto P_0c06909e;
P_0c06909e: /* original 2e2b, guest PC 0x0c06909e */
if(!s->budget--) { s->failed_pc=0x0c06909eu; return 0; }
r[14]|=r[2];
goto P_0c0690a0;
P_0c0690a0: /* original 2349, guest PC 0x0c0690a0 */
if(!s->budget--) { s->failed_pc=0x0c0690a0u; return 0; }
r[3]&=r[4];
goto P_0c0690a2;
P_0c0690a2: /* original 2e9b, guest PC 0x0c0690a2 */
if(!s->budget--) { s->failed_pc=0x0c0690a2u; return 0; }
r[14]|=r[9];
goto P_0c0690a4;
P_0c0690a4: /* original 62e3, guest PC 0x0c0690a4 */
if(!s->budget--) { s->failed_pc=0x0c0690a4u; return 0; }
r[2]=r[14];
goto P_0c0690a6;
P_0c0690a6: /* original 2c3b, guest PC 0x0c0690a6 */
if(!s->budget--) { s->failed_pc=0x0c0690a6u; return 0; }
r[12]|=r[3];
goto P_0c0690a8;
P_0c0690a8: /* original 2249, guest PC 0x0c0690a8 */
if(!s->budget--) { s->failed_pc=0x0c0690a8u; return 0; }
r[2]&=r[4];
goto P_0c0690aa;
P_0c0690aa: /* original 63e3, guest PC 0x0c0690aa */
if(!s->budget--) { s->failed_pc=0x0c0690aau; return 0; }
r[3]=r[14];
goto P_0c0690ac;
P_0c0690ac: /* original 2659, guest PC 0x0c0690ac */
if(!s->budget--) { s->failed_pc=0x0c0690acu; return 0; }
r[6]&=r[5];
goto P_0c0690ae;
P_0c0690ae: /* original 2359, guest PC 0x0c0690ae */
if(!s->budget--) { s->failed_pc=0x0c0690aeu; return 0; }
r[3]&=r[5];
goto P_0c0690b0;
P_0c0690b0: /* original 2b2b, guest PC 0x0c0690b0 */
if(!s->budget--) { s->failed_pc=0x0c0690b0u; return 0; }
r[11]|=r[2];
goto P_0c0690b2;
P_0c0690b2: /* original 2b3b, guest PC 0x0c0690b2 */
if(!s->budget--) { s->failed_pc=0x0c0690b2u; return 0; }
r[11]|=r[3];
goto P_0c0690b4;
P_0c0690b4: /* original 2c6b, guest PC 0x0c0690b4 */
if(!s->budget--) { s->failed_pc=0x0c0690b4u; return 0; }
r[12]|=r[6];
goto P_0c0690b6;
P_0c0690b6: /* original 66b3, guest PC 0x0c0690b6 */
if(!s->budget--) { s->failed_pc=0x0c0690b6u; return 0; }
r[6]=r[11];
goto P_0c0690b8;
P_0c0690b8: /* original 2659, guest PC 0x0c0690b8 */
if(!s->budget--) { s->failed_pc=0x0c0690b8u; return 0; }
r[6]&=r[5];
goto P_0c0690ba;
P_0c0690ba: /* original 2668, guest PC 0x0c0690ba */
if(!s->budget--) { s->failed_pc=0x0c0690bau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690bc;
P_0c0690bc: /* original 8b02, guest PC 0x0c0690bc */
if(!s->budget--) { s->failed_pc=0x0c0690bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690c4; }
goto P_0c0690be;
P_0c0690be: /* original 63b3, guest PC 0x0c0690be */
if(!s->budget--) { s->failed_pc=0x0c0690beu; return 0; }
r[3]=r[11];
goto P_0c0690c0;
P_0c0690c0: /* original 2348, guest PC 0x0c0690c0 */
if(!s->budget--) { s->failed_pc=0x0c0690c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0690c2;
P_0c0690c2: /* original 8b04, guest PC 0x0c0690c2 */
if(!s->budget--) { s->failed_pc=0x0c0690c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690ce; }
goto P_0c0690c4;
P_0c0690c4: /* original 2668, guest PC 0x0c0690c4 */
if(!s->budget--) { s->failed_pc=0x0c0690c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690c6;
P_0c0690c6: /* original 8904, guest PC 0x0c0690c6 */
if(!s->budget--) { s->failed_pc=0x0c0690c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0690d2; }
goto P_0c0690c8;
P_0c0690c8: /* original 62b3, guest PC 0x0c0690c8 */
if(!s->budget--) { s->failed_pc=0x0c0690c8u; return 0; }
r[2]=r[11];
goto P_0c0690ca;
P_0c0690ca: /* original 2248, guest PC 0x0c0690ca */
if(!s->budget--) { s->failed_pc=0x0c0690cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0690cc;
P_0c0690cc: /* original 8b01, guest PC 0x0c0690cc */
if(!s->budget--) { s->failed_pc=0x0c0690ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690d2; }
goto P_0c0690ce;
P_0c0690ce: /* original a017, guest PC 0x0c0690ce */
if(!s->budget--) { s->failed_pc=0x0c0690ceu; return 0; }
r[0]=0x00000002u;
goto P_0c069100;
P_0c0690d0: /* original e002, guest PC 0x0c0690d0 */
if(!s->budget--) { s->failed_pc=0x0c0690d0u; return 0; }
r[0]=0x00000002u;
goto P_0c0690d2;
P_0c0690d2: /* original 62f2, guest PC 0x0c0690d2 */
if(!s->budget--) { s->failed_pc=0x0c0690d2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0690d4;
P_0c0690d4: /* original 2228, guest PC 0x0c0690d4 */
if(!s->budget--) { s->failed_pc=0x0c0690d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0690d6;
P_0c0690d6: /* original 8b12, guest PC 0x0c0690d6 */
if(!s->budget--) { s->failed_pc=0x0c0690d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fe; }
goto P_0c0690d8;
P_0c0690d8: /* original 62c3, guest PC 0x0c0690d8 */
if(!s->budget--) { s->failed_pc=0x0c0690d8u; return 0; }
r[2]=r[12];
goto P_0c0690da;
P_0c0690da: /* original 2249, guest PC 0x0c0690da */
if(!s->budget--) { s->failed_pc=0x0c0690dau; return 0; }
r[2]&=r[4];
goto P_0c0690dc;
P_0c0690dc: /* original 2c59, guest PC 0x0c0690dc */
if(!s->budget--) { s->failed_pc=0x0c0690dcu; return 0; }
r[12]&=r[5];
goto P_0c0690de;
P_0c0690de: /* original 2e2b, guest PC 0x0c0690de */
if(!s->budget--) { s->failed_pc=0x0c0690deu; return 0; }
r[14]|=r[2];
goto P_0c0690e0;
P_0c0690e0: /* original 2ecb, guest PC 0x0c0690e0 */
if(!s->budget--) { s->failed_pc=0x0c0690e0u; return 0; }
r[14]|=r[12];
goto P_0c0690e2;
P_0c0690e2: /* original 66e3, guest PC 0x0c0690e2 */
if(!s->budget--) { s->failed_pc=0x0c0690e2u; return 0; }
r[6]=r[14];
goto P_0c0690e4;
P_0c0690e4: /* original 2659, guest PC 0x0c0690e4 */
if(!s->budget--) { s->failed_pc=0x0c0690e4u; return 0; }
r[6]&=r[5];
goto P_0c0690e6;
P_0c0690e6: /* original 2668, guest PC 0x0c0690e6 */
if(!s->budget--) { s->failed_pc=0x0c0690e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690e8;
P_0c0690e8: /* original 8b02, guest PC 0x0c0690e8 */
if(!s->budget--) { s->failed_pc=0x0c0690e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690f0; }
goto P_0c0690ea;
P_0c0690ea: /* original 62e3, guest PC 0x0c0690ea */
if(!s->budget--) { s->failed_pc=0x0c0690eau; return 0; }
r[2]=r[14];
goto P_0c0690ec;
P_0c0690ec: /* original 2248, guest PC 0x0c0690ec */
if(!s->budget--) { s->failed_pc=0x0c0690ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0690ee;
P_0c0690ee: /* original 8b04, guest PC 0x0c0690ee */
if(!s->budget--) { s->failed_pc=0x0c0690eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fa; }
goto P_0c0690f0;
P_0c0690f0: /* original 2668, guest PC 0x0c0690f0 */
if(!s->budget--) { s->failed_pc=0x0c0690f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690f2;
P_0c0690f2: /* original 8904, guest PC 0x0c0690f2 */
if(!s->budget--) { s->failed_pc=0x0c0690f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0690fe; }
goto P_0c0690f4;
P_0c0690f4: /* original 63e3, guest PC 0x0c0690f4 */
if(!s->budget--) { s->failed_pc=0x0c0690f4u; return 0; }
r[3]=r[14];
goto P_0c0690f6;
P_0c0690f6: /* original 2348, guest PC 0x0c0690f6 */
if(!s->budget--) { s->failed_pc=0x0c0690f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0690f8;
P_0c0690f8: /* original 8b01, guest PC 0x0c0690f8 */
if(!s->budget--) { s->failed_pc=0x0c0690f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fe; }
goto P_0c0690fa;
P_0c0690fa: /* original a001, guest PC 0x0c0690fa */
if(!s->budget--) { s->failed_pc=0x0c0690fau; return 0; }
r[0]=0x00000004u;
goto P_0c069100;
P_0c0690fc: /* original e004, guest PC 0x0c0690fc */
if(!s->budget--) { s->failed_pc=0x0c0690fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0690fe;
P_0c0690fe: /* original e000, guest PC 0x0c0690fe */
if(!s->budget--) { s->failed_pc=0x0c0690feu; return 0; }
r[0]=0x00000000u;
goto P_0c069100;
P_0c069100: /* original 7f04, guest PC 0x0c069100 */
if(!s->budget--) { s->failed_pc=0x0c069100u; return 0; }
r[15]+=0x00000004u;
goto P_0c069102;
P_0c069102: /* original 4f26, guest PC 0x0c069102 */
if(!s->budget--) { s->failed_pc=0x0c069102u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c069104;
P_0c069104: /* original fef9, guest PC 0x0c069104 */
if(!s->budget--) { s->failed_pc=0x0c069104u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069106;
P_0c069106: /* original fff9, guest PC 0x0c069106 */
if(!s->budget--) { s->failed_pc=0x0c069106u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069108;
P_0c069108: /* original 69f6, guest PC 0x0c069108 */
if(!s->budget--) { s->failed_pc=0x0c069108u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06910a;
P_0c06910a: /* original 6af6, guest PC 0x0c06910a */
if(!s->budget--) { s->failed_pc=0x0c06910au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06910c;
P_0c06910c: /* original 6bf6, guest PC 0x0c06910c */
if(!s->budget--) { s->failed_pc=0x0c06910cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06910e;
P_0c06910e: /* original 6cf6, guest PC 0x0c06910e */
if(!s->budget--) { s->failed_pc=0x0c06910eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c069110;
P_0c069110: /* original 6df6, guest PC 0x0c069110 */
if(!s->budget--) { s->failed_pc=0x0c069110u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c069112;
P_0c069112: /* original 000b, guest PC 0x0c069112 */
if(!s->budget--) { s->failed_pc=0x0c069112u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c069114: /* original 6ef6, guest PC 0x0c069114 */
if(!s->budget--) { s->failed_pc=0x0c069114u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c069116u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069116u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
