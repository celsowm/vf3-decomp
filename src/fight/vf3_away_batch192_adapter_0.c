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
int vf3_away_batch192_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c036794u: goto P_0c036794;
case 0x0c036796u: goto P_0c036796;
case 0x0c036798u: goto P_0c036798;
case 0x0c0368aau: goto P_0c0368aa;
case 0x0c0368acu: goto P_0c0368ac;
case 0x0c0368aeu: goto P_0c0368ae;
case 0x0c0368b0u: goto P_0c0368b0;
case 0x0c0368b2u: goto P_0c0368b2;
case 0x0c0368b4u: goto P_0c0368b4;
case 0x0c0368b6u: goto P_0c0368b6;
case 0x0c0368b8u: goto P_0c0368b8;
case 0x0c0368bau: goto P_0c0368ba;
case 0x0c0368bcu: goto P_0c0368bc;
case 0x0c0368beu: goto P_0c0368be;
case 0x0c0368c0u: goto P_0c0368c0;
case 0x0c0368c2u: goto P_0c0368c2;
case 0x0c0368c4u: goto P_0c0368c4;
case 0x0c0368c6u: goto P_0c0368c6;
case 0x0c0368c8u: goto P_0c0368c8;
case 0x0c0368cau: goto P_0c0368ca;
case 0x0c0368ccu: goto P_0c0368cc;
case 0x0c0368ceu: goto P_0c0368ce;
case 0x0c0368d0u: goto P_0c0368d0;
case 0x0c0368d2u: goto P_0c0368d2;
case 0x0c0368d4u: goto P_0c0368d4;
case 0x0c0368d6u: goto P_0c0368d6;
case 0x0c0368d8u: goto P_0c0368d8;
case 0x0c0368dau: goto P_0c0368da;
case 0x0c0368dcu: goto P_0c0368dc;
case 0x0c0368deu: goto P_0c0368de;
case 0x0c0368e0u: goto P_0c0368e0;
case 0x0c0368e2u: goto P_0c0368e2;
case 0x0c0368e4u: goto P_0c0368e4;
case 0x0c0368e6u: goto P_0c0368e6;
case 0x0c0368e8u: goto P_0c0368e8;
case 0x0c0368eau: goto P_0c0368ea;
case 0x0c0368ecu: goto P_0c0368ec;
case 0x0c0368eeu: goto P_0c0368ee;
case 0x0c0368f0u: goto P_0c0368f0;
case 0x0c0368f2u: goto P_0c0368f2;
case 0x0c0368f4u: goto P_0c0368f4;
case 0x0c0368f6u: goto P_0c0368f6;
case 0x0c0368f8u: goto P_0c0368f8;
case 0x0c0368fau: goto P_0c0368fa;
case 0x0c0368fcu: goto P_0c0368fc;
case 0x0c0368feu: goto P_0c0368fe;
case 0x0c036900u: goto P_0c036900;
case 0x0c036902u: goto P_0c036902;
case 0x0c036904u: goto P_0c036904;
case 0x0c036906u: goto P_0c036906;
case 0x0c036908u: goto P_0c036908;
case 0x0c03690au: goto P_0c03690a;
case 0x0c03690cu: goto P_0c03690c;
case 0x0c03690eu: goto P_0c03690e;
case 0x0c036910u: goto P_0c036910;
case 0x0c036912u: goto P_0c036912;
case 0x0c036914u: goto P_0c036914;
case 0x0c036916u: goto P_0c036916;
case 0x0c036918u: goto P_0c036918;
case 0x0c03691au: goto P_0c03691a;
case 0x0c03691cu: goto P_0c03691c;
case 0x0c03691eu: goto P_0c03691e;
case 0x0c036920u: goto P_0c036920;
case 0x0c036922u: goto P_0c036922;
case 0x0c036924u: goto P_0c036924;
case 0x0c036926u: goto P_0c036926;
case 0x0c036928u: goto P_0c036928;
case 0x0c03692au: goto P_0c03692a;
case 0x0c03692cu: goto P_0c03692c;
case 0x0c03692eu: goto P_0c03692e;
case 0x0c036930u: goto P_0c036930;
case 0x0c036932u: goto P_0c036932;
case 0x0c036934u: goto P_0c036934;
case 0x0c036936u: goto P_0c036936;
case 0x0c036938u: goto P_0c036938;
case 0x0c03693au: goto P_0c03693a;
case 0x0c03693cu: goto P_0c03693c;
case 0x0c03693eu: goto P_0c03693e;
case 0x0c036940u: goto P_0c036940;
case 0x0c036942u: goto P_0c036942;
case 0x0c036944u: goto P_0c036944;
case 0x0c036946u: goto P_0c036946;
case 0x0c036948u: goto P_0c036948;
case 0x0c03694au: goto P_0c03694a;
case 0x0c03694cu: goto P_0c03694c;
case 0x0c03694eu: goto P_0c03694e;
case 0x0c036950u: goto P_0c036950;
case 0x0c036952u: goto P_0c036952;
case 0x0c036954u: goto P_0c036954;
case 0x0c036956u: goto P_0c036956;
case 0x0c036958u: goto P_0c036958;
case 0x0c03695au: goto P_0c03695a;
case 0x0c03695cu: goto P_0c03695c;
case 0x0c03695eu: goto P_0c03695e;
case 0x0c036960u: goto P_0c036960;
case 0x0c036962u: goto P_0c036962;
case 0x0c036964u: goto P_0c036964;
case 0x0c036966u: goto P_0c036966;
case 0x0c036db8u: goto P_0c036db8;
case 0x0c036dbau: goto P_0c036dba;
case 0x0c036dbcu: goto P_0c036dbc;
case 0x0c036dbeu: goto P_0c036dbe;
case 0x0c036dc0u: goto P_0c036dc0;
case 0x0c036dc2u: goto P_0c036dc2;
case 0x0c036dc4u: goto P_0c036dc4;
case 0x0c036dc6u: goto P_0c036dc6;
case 0x0c036dc8u: goto P_0c036dc8;
case 0x0c0371ecu: goto P_0c0371ec;
case 0x0c0371eeu: goto P_0c0371ee;
case 0x0c0371f0u: goto P_0c0371f0;
case 0x0c0371f2u: goto P_0c0371f2;
case 0x0c0371f4u: goto P_0c0371f4;
case 0x0c0371f6u: goto P_0c0371f6;
case 0x0c038cb0u: goto P_0c038cb0;
case 0x0c038cb2u: goto P_0c038cb2;
case 0x0c038cb4u: goto P_0c038cb4;
case 0x0c038cb6u: goto P_0c038cb6;
case 0x0c038cb8u: goto P_0c038cb8;
case 0x0c038cbau: goto P_0c038cba;
case 0x0c038cbcu: goto P_0c038cbc;
case 0x0c038cbeu: goto P_0c038cbe;
case 0x0c038cc0u: goto P_0c038cc0;
case 0x0c038cc2u: goto P_0c038cc2;
case 0x0c038cc4u: goto P_0c038cc4;
case 0x0c038cc6u: goto P_0c038cc6;
case 0x0c038cc8u: goto P_0c038cc8;
case 0x0c038ccau: goto P_0c038cca;
case 0x0c038cccu: goto P_0c038ccc;
case 0x0c038cceu: goto P_0c038cce;
case 0x0c038cd0u: goto P_0c038cd0;
case 0x0c038cd2u: goto P_0c038cd2;
case 0x0c038cd4u: goto P_0c038cd4;
case 0x0c038cd6u: goto P_0c038cd6;
case 0x0c038cd8u: goto P_0c038cd8;
case 0x0c038ce0u: goto P_0c038ce0;
case 0x0c038ce2u: goto P_0c038ce2;
case 0x0c038ce4u: goto P_0c038ce4;
case 0x0c042460u: goto P_0c042460;
case 0x0c042462u: goto P_0c042462;
case 0x0c042464u: goto P_0c042464;
case 0x0c042466u: goto P_0c042466;
case 0x0c042468u: goto P_0c042468;
case 0x0c04246au: goto P_0c04246a;
case 0x0c04246cu: goto P_0c04246c;
case 0x0c04246eu: goto P_0c04246e;
case 0x0c042490u: goto P_0c042490;
case 0x0c042492u: goto P_0c042492;
case 0x0c042494u: goto P_0c042494;
case 0x0c042496u: goto P_0c042496;
case 0x0c042498u: goto P_0c042498;
case 0x0c04249au: goto P_0c04249a;
case 0x0c04249cu: goto P_0c04249c;
case 0x0c04249eu: goto P_0c04249e;
case 0x0c0424a0u: goto P_0c0424a0;
case 0x0c0424a2u: goto P_0c0424a2;
case 0x0c0424a4u: goto P_0c0424a4;
case 0x0c0424a6u: goto P_0c0424a6;
case 0x0c0424a8u: goto P_0c0424a8;
case 0x0c0424aau: goto P_0c0424aa;
case 0x0c0424acu: goto P_0c0424ac;
case 0x0c0424aeu: goto P_0c0424ae;
case 0x0c0424b0u: goto P_0c0424b0;
case 0x0c0424b2u: goto P_0c0424b2;
case 0x0c0424b4u: goto P_0c0424b4;
case 0x0c0424b6u: goto P_0c0424b6;
case 0x0c042950u: goto P_0c042950;
case 0x0c042952u: goto P_0c042952;
case 0x0c042954u: goto P_0c042954;
case 0x0c042960u: goto P_0c042960;
case 0x0c042962u: goto P_0c042962;
case 0x0c042964u: goto P_0c042964;
case 0x0c042970u: goto P_0c042970;
case 0x0c042972u: goto P_0c042972;
case 0x0c042974u: goto P_0c042974;
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c036794: /* original d374, guest PC 0x0c036794 */
if(!s->budget--) { s->failed_pc=0x0c036794u; return 0; }
r[3]=read(ram,0x0c036968u,4);
goto P_0c036796;
P_0c036796: /* original 432b, guest PC 0x0c036796 */
if(!s->budget--) { s->failed_pc=0x0c036796u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c036db8u: goto P_0c036db8;
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
P_0c036798: /* original 0009, guest PC 0x0c036798 */
if(!s->budget--) { s->failed_pc=0x0c036798u; return 0; }
if(!vf3_matrix_family(0x0c03679au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03679au; return 0; } return 1;
P_0c0368aa: /* original 000b, guest PC 0x0c0368aa */
if(!s->budget--) { s->failed_pc=0x0c0368aau; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c0368ac: /* original e000, guest PC 0x0c0368ac */
if(!s->budget--) { s->failed_pc=0x0c0368acu; return 0; }
r[0]=0x00000000u;
goto P_0c0368ae;
P_0c0368ae: /* original affc, guest PC 0x0c0368ae */
if(!s->budget--) { s->failed_pc=0x0c0368aeu; return 0; }
goto P_0c0368aa;
P_0c0368b0: /* original 0009, guest PC 0x0c0368b0 */
if(!s->budget--) { s->failed_pc=0x0c0368b0u; return 0; }
goto P_0c0368b2;
P_0c0368b2: /* original 2fe6, guest PC 0x0c0368b2 */
if(!s->budget--) { s->failed_pc=0x0c0368b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b4;
P_0c0368b4: /* original 2fd6, guest PC 0x0c0368b4 */
if(!s->budget--) { s->failed_pc=0x0c0368b4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b6;
P_0c0368b6: /* original 2fc6, guest PC 0x0c0368b6 */
if(!s->budget--) { s->failed_pc=0x0c0368b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b8;
P_0c0368b8: /* original 2fb6, guest PC 0x0c0368b8 */
if(!s->budget--) { s->failed_pc=0x0c0368b8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368ba;
P_0c0368ba: /* original 2fa6, guest PC 0x0c0368ba */
if(!s->budget--) { s->failed_pc=0x0c0368bau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368bc;
P_0c0368bc: /* original 2f96, guest PC 0x0c0368bc */
if(!s->budget--) { s->failed_pc=0x0c0368bcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368be;
P_0c0368be: /* original d439, guest PC 0x0c0368be */
if(!s->budget--) { s->failed_pc=0x0c0368beu; return 0; }
r[4]=read(ram,0x0c0369a4u,4);
goto P_0c0368c0;
P_0c0368c0: /* original 4f22, guest PC 0x0c0368c0 */
if(!s->budget--) { s->failed_pc=0x0c0368c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0368c2;
P_0c0368c2: /* original 6342, guest PC 0x0c0368c2 */
if(!s->budget--) { s->failed_pc=0x0c0368c2u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0368c4;
P_0c0368c4: /* original d238, guest PC 0x0c0368c4 */
if(!s->budget--) { s->failed_pc=0x0c0368c4u; return 0; }
r[2]=read(ram,0x0c0369a8u,4);
goto P_0c0368c6;
P_0c0368c6: /* original 7301, guest PC 0x0c0368c6 */
if(!s->budget--) { s->failed_pc=0x0c0368c6u; return 0; }
r[3]+=0x00000001u;
goto P_0c0368c8;
P_0c0368c8: /* original 420b, guest PC 0x0c0368c8 */
if(!s->budget--) { s->failed_pc=0x0c0368c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0368ccu;
write(ram,r[4],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0368ccu) { target=s->pc; goto dispatch; }
goto P_0c0368cc;
P_0c0368ca: /* original 2432, guest PC 0x0c0368ca */
if(!s->budget--) { s->failed_pc=0x0c0368cau; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0368cc;
P_0c0368cc: /* original d238, guest PC 0x0c0368cc */
if(!s->budget--) { s->failed_pc=0x0c0368ccu; return 0; }
r[2]=read(ram,0x0c0369b0u,4);
goto P_0c0368ce;
P_0c0368ce: /* original d137, guest PC 0x0c0368ce */
if(!s->budget--) { s->failed_pc=0x0c0368ceu; return 0; }
r[1]=read(ram,0x0c0369acu,4);
goto P_0c0368d0;
P_0c0368d0: /* original 6322, guest PC 0x0c0368d0 */
if(!s->budget--) { s->failed_pc=0x0c0368d0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0368d2;
P_0c0368d2: /* original 2132, guest PC 0x0c0368d2 */
if(!s->budget--) { s->failed_pc=0x0c0368d2u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0368d4;
P_0c0368d4: /* original ea00, guest PC 0x0c0368d4 */
if(!s->budget--) { s->failed_pc=0x0c0368d4u; return 0; }
r[10]=0x00000000u;
goto P_0c0368d6;
P_0c0368d6: /* original dd39, guest PC 0x0c0368d6 */
if(!s->budget--) { s->failed_pc=0x0c0368d6u; return 0; }
r[13]=read(ram,0x0c0369bcu,4);
goto P_0c0368d8;
P_0c0368d8: /* original e902, guest PC 0x0c0368d8 */
if(!s->budget--) { s->failed_pc=0x0c0368d8u; return 0; }
r[9]=0x00000002u;
goto P_0c0368da;
P_0c0368da: /* original db37, guest PC 0x0c0368da */
if(!s->budget--) { s->failed_pc=0x0c0368dau; return 0; }
r[11]=read(ram,0x0c0369b8u,4);
goto P_0c0368dc;
P_0c0368dc: /* original dc38, guest PC 0x0c0368dc */
if(!s->budget--) { s->failed_pc=0x0c0368dcu; return 0; }
r[12]=read(ram,0x0c0369c0u,4);
goto P_0c0368de;
P_0c0368de: /* original de35, guest PC 0x0c0368de */
if(!s->budget--) { s->failed_pc=0x0c0368deu; return 0; }
r[14]=read(ram,0x0c0369b4u,4);
goto P_0c0368e0;
P_0c0368e0: /* original bf58, guest PC 0x0c0368e0 */
if(!s->budget--) { s->failed_pc=0x0c0368e0u; return 0; }
target=code_base|0x0c036794u; r[16]=code_base|0x0c0368e4u;
tmp=read(ram,r[12],4);
r[12]+=4;
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0368e4u) { target=s->pc; goto dispatch; }
goto P_0c0368e4;
P_0c0368e2: /* original 64c6, guest PC 0x0c0368e2 */
if(!s->budget--) { s->failed_pc=0x0c0368e2u; return 0; }
tmp=read(ram,r[12],4);
r[12]+=4;
r[4]=tmp;
goto P_0c0368e4;
P_0c0368e4: /* original 6403, guest PC 0x0c0368e4 */
if(!s->budget--) { s->failed_pc=0x0c0368e4u; return 0; }
r[4]=r[0];
goto P_0c0368e6;
P_0c0368e6: /* original 60b1, guest PC 0x0c0368e6 */
if(!s->budget--) { s->failed_pc=0x0c0368e6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[0]=tmp;
goto P_0c0368e8;
P_0c0368e8: /* original e2f8, guest PC 0x0c0368e8 */
if(!s->budget--) { s->failed_pc=0x0c0368e8u; return 0; }
r[2]=0xfffffff8u;
goto P_0c0368ea;
P_0c0368ea: /* original 81e2, guest PC 0x0c0368ea */
if(!s->budget--) { s->failed_pc=0x0c0368eau; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c0368ec;
P_0c0368ec: /* original 5542, guest PC 0x0c0368ec */
if(!s->budget--) { s->failed_pc=0x0c0368ecu; return 0; }
r[5]=read(ram,r[4]+8,4);
goto P_0c0368ee;
P_0c0368ee: /* original 655d, guest PC 0x0c0368ee */
if(!s->budget--) { s->failed_pc=0x0c0368eeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0368f0;
P_0c0368f0: /* original 6353, guest PC 0x0c0368f0 */
if(!s->budget--) { s->failed_pc=0x0c0368f0u; return 0; }
r[3]=r[5];
goto P_0c0368f2;
P_0c0368f2: /* original 6053, guest PC 0x0c0368f2 */
if(!s->budget--) { s->failed_pc=0x0c0368f2u; return 0; }
r[0]=r[5];
goto P_0c0368f4;
P_0c0368f4: /* original 432c, guest PC 0x0c0368f4 */
if(!s->budget--) { s->failed_pc=0x0c0368f4u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0368f6;
P_0c0368f6: /* original 4018, guest PC 0x0c0368f6 */
if(!s->budget--) { s->failed_pc=0x0c0368f6u; return 0; }
r[0]<<=8;
goto P_0c0368f8;
P_0c0368f8: /* original 633c, guest PC 0x0c0368f8 */
if(!s->budget--) { s->failed_pc=0x0c0368f8u; return 0; }
r[3]=r[3]&255u;
goto P_0c0368fa;
P_0c0368fa: /* original 20d9, guest PC 0x0c0368fa */
if(!s->budget--) { s->failed_pc=0x0c0368fau; return 0; }
r[0]&=r[13];
goto P_0c0368fc;
P_0c0368fc: /* original 203b, guest PC 0x0c0368fc */
if(!s->budget--) { s->failed_pc=0x0c0368fcu; return 0; }
r[0]|=r[3];
goto P_0c0368fe;
P_0c0368fe: /* original 81e1, guest PC 0x0c0368fe */
if(!s->budget--) { s->failed_pc=0x0c0368feu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c036900;
P_0c036900: /* original 5544, guest PC 0x0c036900 */
if(!s->budget--) { s->failed_pc=0x0c036900u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c036902;
P_0c036902: /* original 655d, guest PC 0x0c036902 */
if(!s->budget--) { s->failed_pc=0x0c036902u; return 0; }
r[5]=r[5]&65535u;
goto P_0c036904;
P_0c036904: /* original 6353, guest PC 0x0c036904 */
if(!s->budget--) { s->failed_pc=0x0c036904u; return 0; }
r[3]=r[5];
goto P_0c036906;
P_0c036906: /* original 6053, guest PC 0x0c036906 */
if(!s->budget--) { s->failed_pc=0x0c036906u; return 0; }
r[0]=r[5];
goto P_0c036908;
P_0c036908: /* original 432c, guest PC 0x0c036908 */
if(!s->budget--) { s->failed_pc=0x0c036908u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c03690a;
P_0c03690a: /* original 4018, guest PC 0x0c03690a */
if(!s->budget--) { s->failed_pc=0x0c03690au; return 0; }
r[0]<<=8;
goto P_0c03690c;
P_0c03690c: /* original 633c, guest PC 0x0c03690c */
if(!s->budget--) { s->failed_pc=0x0c03690cu; return 0; }
r[3]=r[3]&255u;
goto P_0c03690e;
P_0c03690e: /* original 20d9, guest PC 0x0c03690e */
if(!s->budget--) { s->failed_pc=0x0c03690eu; return 0; }
r[0]&=r[13];
goto P_0c036910;
P_0c036910: /* original 203b, guest PC 0x0c036910 */
if(!s->budget--) { s->failed_pc=0x0c036910u; return 0; }
r[0]|=r[3];
goto P_0c036912;
P_0c036912: /* original 81e3, guest PC 0x0c036912 */
if(!s->budget--) { s->failed_pc=0x0c036912u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c036914;
P_0c036914: /* original 5545, guest PC 0x0c036914 */
if(!s->budget--) { s->failed_pc=0x0c036914u; return 0; }
r[5]=read(ram,r[4]+20,4);
goto P_0c036916;
P_0c036916: /* original 655d, guest PC 0x0c036916 */
if(!s->budget--) { s->failed_pc=0x0c036916u; return 0; }
r[5]=r[5]&65535u;
goto P_0c036918;
P_0c036918: /* original 6353, guest PC 0x0c036918 */
if(!s->budget--) { s->failed_pc=0x0c036918u; return 0; }
r[3]=r[5];
goto P_0c03691a;
P_0c03691a: /* original 6053, guest PC 0x0c03691a */
if(!s->budget--) { s->failed_pc=0x0c03691au; return 0; }
r[0]=r[5];
goto P_0c03691c;
P_0c03691c: /* original 432c, guest PC 0x0c03691c */
if(!s->budget--) { s->failed_pc=0x0c03691cu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c03691e;
P_0c03691e: /* original 4018, guest PC 0x0c03691e */
if(!s->budget--) { s->failed_pc=0x0c03691eu; return 0; }
r[0]<<=8;
goto P_0c036920;
P_0c036920: /* original 633c, guest PC 0x0c036920 */
if(!s->budget--) { s->failed_pc=0x0c036920u; return 0; }
r[3]=r[3]&255u;
goto P_0c036922;
P_0c036922: /* original 20d9, guest PC 0x0c036922 */
if(!s->budget--) { s->failed_pc=0x0c036922u; return 0; }
r[0]&=r[13];
goto P_0c036924;
P_0c036924: /* original 203b, guest PC 0x0c036924 */
if(!s->budget--) { s->failed_pc=0x0c036924u; return 0; }
r[0]|=r[3];
goto P_0c036926;
P_0c036926: /* original 81e4, guest PC 0x0c036926 */
if(!s->budget--) { s->failed_pc=0x0c036926u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c036928;
P_0c036928: /* original 7a01, guest PC 0x0c036928 */
if(!s->budget--) { s->failed_pc=0x0c036928u; return 0; }
r[10]+=0x00000001u;
goto P_0c03692a;
P_0c03692a: /* original 854c, guest PC 0x0c03692a */
if(!s->budget--) { s->failed_pc=0x0c03692au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c03692c;
P_0c03692c: /* original 3a93, guest PC 0x0c03692c */
if(!s->budget--) { s->failed_pc=0x0c03692cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c03692e;
P_0c03692e: /* original 80ea, guest PC 0x0c03692e */
if(!s->budget--) { s->failed_pc=0x0c03692eu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c036930;
P_0c036930: /* original 854d, guest PC 0x0c036930 */
if(!s->budget--) { s->failed_pc=0x0c036930u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+26,2);
goto P_0c036932;
P_0c036932: /* original 80eb, guest PC 0x0c036932 */
if(!s->budget--) { s->failed_pc=0x0c036932u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c036934;
P_0c036934: /* original 854e, guest PC 0x0c036934 */
if(!s->budget--) { s->failed_pc=0x0c036934u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c036936;
P_0c036936: /* original 80ec, guest PC 0x0c036936 */
if(!s->budget--) { s->failed_pc=0x0c036936u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c036938;
P_0c036938: /* original 854f, guest PC 0x0c036938 */
if(!s->budget--) { s->failed_pc=0x0c036938u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c03693a;
P_0c03693a: /* original 80ed, guest PC 0x0c03693a */
if(!s->budget--) { s->failed_pc=0x0c03693au; return 0; }
write(ram,r[14]+13,r[0],1);
goto P_0c03693c;
P_0c03693c: /* original e020, guest PC 0x0c03693c */
if(!s->budget--) { s->failed_pc=0x0c03693cu; return 0; }
r[0]=0x00000020u;
goto P_0c03693e;
P_0c03693e: /* original 004c, guest PC 0x0c03693e */
if(!s->budget--) { s->failed_pc=0x0c03693eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c036940;
P_0c036940: /* original 80ee, guest PC 0x0c036940 */
if(!s->budget--) { s->failed_pc=0x0c036940u; return 0; }
write(ram,r[14]+14,r[0],1);
goto P_0c036942;
P_0c036942: /* original e022, guest PC 0x0c036942 */
if(!s->budget--) { s->failed_pc=0x0c036942u; return 0; }
r[0]=0x00000022u;
goto P_0c036944;
P_0c036944: /* original 004c, guest PC 0x0c036944 */
if(!s->budget--) { s->failed_pc=0x0c036944u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c036946;
P_0c036946: /* original 80ef, guest PC 0x0c036946 */
if(!s->budget--) { s->failed_pc=0x0c036946u; return 0; }
write(ram,r[14]+15,r[0],1);
goto P_0c036948;
P_0c036948: /* original 85e1, guest PC 0x0c036948 */
if(!s->budget--) { s->failed_pc=0x0c036948u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c03694a;
P_0c03694a: /* original 2b01, guest PC 0x0c03694a */
if(!s->budget--) { s->failed_pc=0x0c03694au; return 0; }
write(ram,r[11],r[0],2);
goto P_0c03694c;
P_0c03694c: /* original 8fc8, guest PC 0x0c03694c */
if(!s->budget--) { s->failed_pc=0x0c03694cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000010u;
if(!cond) { goto P_0c0368e0; }
goto P_0c036950;
P_0c03694e: /* original 7e10, guest PC 0x0c03694e */
if(!s->budget--) { s->failed_pc=0x0c03694eu; return 0; }
r[14]+=0x00000010u;
goto P_0c036950;
P_0c036950: /* original d117, guest PC 0x0c036950 */
if(!s->budget--) { s->failed_pc=0x0c036950u; return 0; }
r[1]=read(ram,0x0c0369b0u,4);
goto P_0c036952;
P_0c036952: /* original d21c, guest PC 0x0c036952 */
if(!s->budget--) { s->failed_pc=0x0c036952u; return 0; }
r[2]=read(ram,0x0c0369c4u,4);
goto P_0c036954;
P_0c036954: /* original 6312, guest PC 0x0c036954 */
if(!s->budget--) { s->failed_pc=0x0c036954u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c036956;
P_0c036956: /* original 4f26, guest PC 0x0c036956 */
if(!s->budget--) { s->failed_pc=0x0c036956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036958;
P_0c036958: /* original 2232, guest PC 0x0c036958 */
if(!s->budget--) { s->failed_pc=0x0c036958u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03695a;
P_0c03695a: /* original 69f6, guest PC 0x0c03695a */
if(!s->budget--) { s->failed_pc=0x0c03695au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03695c;
P_0c03695c: /* original 6af6, guest PC 0x0c03695c */
if(!s->budget--) { s->failed_pc=0x0c03695cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03695e;
P_0c03695e: /* original 6bf6, guest PC 0x0c03695e */
if(!s->budget--) { s->failed_pc=0x0c03695eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c036960;
P_0c036960: /* original 6cf6, guest PC 0x0c036960 */
if(!s->budget--) { s->failed_pc=0x0c036960u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036962;
P_0c036962: /* original 6df6, guest PC 0x0c036962 */
if(!s->budget--) { s->failed_pc=0x0c036962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036964;
P_0c036964: /* original 000b, guest PC 0x0c036964 */
if(!s->budget--) { s->failed_pc=0x0c036964u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036966: /* original 6ef6, guest PC 0x0c036966 */
if(!s->budget--) { s->failed_pc=0x0c036966u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c036968u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036968u; return 0; } return 1;
P_0c036db8: /* original e034, guest PC 0x0c036db8 */
if(!s->budget--) { s->failed_pc=0x0c036db8u; return 0; }
r[0]=0x00000034u;
goto P_0c036dba;
P_0c036dba: /* original d327, guest PC 0x0c036dba */
if(!s->budget--) { s->failed_pc=0x0c036dbau; return 0; }
r[3]=read(ram,0x0c036e58u,4);
goto P_0c036dbc;
P_0c036dbc: /* original 4f12, guest PC 0x0c036dbc */
if(!s->budget--) { s->failed_pc=0x0c036dbcu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c036dbe;
P_0c036dbe: /* original 240f, guest PC 0x0c036dbe */
if(!s->budget--) { s->failed_pc=0x0c036dbeu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[0]);
goto P_0c036dc0;
P_0c036dc0: /* original 001a, guest PC 0x0c036dc0 */
if(!s->budget--) { s->failed_pc=0x0c036dc0u; return 0; }
r[0]=r[19];
goto P_0c036dc2;
P_0c036dc2: /* original 600f, guest PC 0x0c036dc2 */
if(!s->budget--) { s->failed_pc=0x0c036dc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c036dc4;
P_0c036dc4: /* original 303c, guest PC 0x0c036dc4 */
if(!s->budget--) { s->failed_pc=0x0c036dc4u; return 0; }
r[0]+=r[3];
goto P_0c036dc6;
P_0c036dc6: /* original 000b, guest PC 0x0c036dc6 */
if(!s->budget--) { s->failed_pc=0x0c036dc6u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c036dc8: /* original 4f16, guest PC 0x0c036dc8 */
if(!s->budget--) { s->failed_pc=0x0c036dc8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c036dcau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036dcau; return 0; } return 1;
P_0c0371ec: /* original d312, guest PC 0x0c0371ec */
if(!s->budget--) { s->failed_pc=0x0c0371ecu; return 0; }
r[3]=read(ram,0x0c037238u,4);
goto P_0c0371ee;
P_0c0371ee: /* original 432b, guest PC 0x0c0371ee */
if(!s->budget--) { s->failed_pc=0x0c0371eeu; return 0; }
target=r[3];
r[4]=0x00000000u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c046aeeu: return vf3_matrix_family(0x0c046aeeu,s,ram);
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
P_0c0371f0: /* original e400, guest PC 0x0c0371f0 */
if(!s->budget--) { s->failed_pc=0x0c0371f0u; return 0; }
r[4]=0x00000000u;
goto P_0c0371f2;
P_0c0371f2: /* original d312, guest PC 0x0c0371f2 */
if(!s->budget--) { s->failed_pc=0x0c0371f2u; return 0; }
r[3]=read(ram,0x0c03723cu,4);
goto P_0c0371f4;
P_0c0371f4: /* original 432b, guest PC 0x0c0371f4 */
if(!s->budget--) { s->failed_pc=0x0c0371f4u; return 0; }
target=r[3];
r[4]=0x00000000u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c046b08u: return vf3_matrix_family(0x0c046b08u,s,ram);
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
P_0c0371f6: /* original e400, guest PC 0x0c0371f6 */
if(!s->budget--) { s->failed_pc=0x0c0371f6u; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c0371f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0371f8u; return 0; } return 1;
P_0c038cb0: /* original 4f22, guest PC 0x0c038cb0 */
if(!s->budget--) { s->failed_pc=0x0c038cb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038cb2;
P_0c038cb2: /* original d118, guest PC 0x0c038cb2 */
if(!s->budget--) { s->failed_pc=0x0c038cb2u; return 0; }
r[1]=read(ram,0x0c038d14u,4);
goto P_0c038cb4;
P_0c038cb4: /* original e301, guest PC 0x0c038cb4 */
if(!s->budget--) { s->failed_pc=0x0c038cb4u; return 0; }
r[3]=0x00000001u;
goto P_0c038cb6;
P_0c038cb6: /* original d218, guest PC 0x0c038cb6 */
if(!s->budget--) { s->failed_pc=0x0c038cb6u; return 0; }
r[2]=read(ram,0x0c038d18u,4);
goto P_0c038cb8;
P_0c038cb8: /* original 420b, guest PC 0x0c038cb8 */
if(!s->budget--) { s->failed_pc=0x0c038cb8u; return 0; }
target=r[2];
r[16]=code_base|0x0c038cbcu;
write(ram,r[1],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038cbcu) { target=s->pc; goto dispatch; }
goto P_0c038cbc;
P_0c038cba: /* original 2132, guest PC 0x0c038cba */
if(!s->budget--) { s->failed_pc=0x0c038cbau; return 0; }
write(ram,r[1],r[3],4);
goto P_0c038cbc;
P_0c038cbc: /* original d317, guest PC 0x0c038cbc */
if(!s->budget--) { s->failed_pc=0x0c038cbcu; return 0; }
r[3]=read(ram,0x0c038d1cu,4);
goto P_0c038cbe;
P_0c038cbe: /* original e000, guest PC 0x0c038cbe */
if(!s->budget--) { s->failed_pc=0x0c038cbeu; return 0; }
r[0]=0x00000000u;
goto P_0c038cc0;
P_0c038cc0: /* original d214, guest PC 0x0c038cc0 */
if(!s->budget--) { s->failed_pc=0x0c038cc0u; return 0; }
r[2]=read(ram,0x0c038d14u,4);
goto P_0c038cc2;
P_0c038cc2: /* original 430b, guest PC 0x0c038cc2 */
if(!s->budget--) { s->failed_pc=0x0c038cc2u; return 0; }
target=r[3];
r[16]=code_base|0x0c038cc6u;
write(ram,r[2],r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038cc6u) { target=s->pc; goto dispatch; }
goto P_0c038cc6;
P_0c038cc4: /* original 2202, guest PC 0x0c038cc4 */
if(!s->budget--) { s->failed_pc=0x0c038cc4u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c038cc6;
P_0c038cc6: /* original d416, guest PC 0x0c038cc6 */
if(!s->budget--) { s->failed_pc=0x0c038cc6u; return 0; }
r[4]=read(ram,0x0c038d20u,4);
goto P_0c038cc8;
P_0c038cc8: /* original 6240, guest PC 0x0c038cc8 */
if(!s->budget--) { s->failed_pc=0x0c038cc8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c038cca;
P_0c038cca: /* original 2228, guest PC 0x0c038cca */
if(!s->budget--) { s->failed_pc=0x0c038ccau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c038ccc;
P_0c038ccc: /* original 8908, guest PC 0x0c038ccc */
if(!s->budget--) { s->failed_pc=0x0c038cccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c038ce0; }
goto P_0c038cce;
P_0c038cce: /* original e100, guest PC 0x0c038cce */
if(!s->budget--) { s->failed_pc=0x0c038cceu; return 0; }
r[1]=0x00000000u;
goto P_0c038cd0;
P_0c038cd0: /* original 2410, guest PC 0x0c038cd0 */
if(!s->budget--) { s->failed_pc=0x0c038cd0u; return 0; }
write(ram,r[4],r[1],1);
goto P_0c038cd2;
P_0c038cd2: /* original d315, guest PC 0x0c038cd2 */
if(!s->budget--) { s->failed_pc=0x0c038cd2u; return 0; }
r[3]=read(ram,0x0c038d28u,4);
goto P_0c038cd4;
P_0c038cd4: /* original d413, guest PC 0x0c038cd4 */
if(!s->budget--) { s->failed_pc=0x0c038cd4u; return 0; }
r[4]=read(ram,0x0c038d24u,4);
goto P_0c038cd6;
P_0c038cd6: /* original 432b, guest PC 0x0c038cd6 */
if(!s->budget--) { s->failed_pc=0x0c038cd6u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c038cd8: /* original 4f26, guest PC 0x0c038cd8 */
if(!s->budget--) { s->failed_pc=0x0c038cd8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038cdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038cdau; return 0; } return 1;
P_0c038ce0: /* original 4f26, guest PC 0x0c038ce0 */
if(!s->budget--) { s->failed_pc=0x0c038ce0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038ce2;
P_0c038ce2: /* original 000b, guest PC 0x0c038ce2 */
if(!s->budget--) { s->failed_pc=0x0c038ce2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c038ce4: /* original 0009, guest PC 0x0c038ce4 */
if(!s->budget--) { s->failed_pc=0x0c038ce4u; return 0; }
if(!vf3_matrix_family(0x0c038ce6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038ce6u; return 0; } return 1;
P_0c042460: /* original d207, guest PC 0x0c042460 */
if(!s->budget--) { s->failed_pc=0x0c042460u; return 0; }
r[2]=read(ram,0x0c042480u,4);
goto P_0c042462;
P_0c042462: /* original e303, guest PC 0x0c042462 */
if(!s->budget--) { s->failed_pc=0x0c042462u; return 0; }
r[3]=0x00000003u;
goto P_0c042464;
P_0c042464: /* original 2439, guest PC 0x0c042464 */
if(!s->budget--) { s->failed_pc=0x0c042464u; return 0; }
r[4]&=r[3];
goto P_0c042466;
P_0c042466: /* original 2539, guest PC 0x0c042466 */
if(!s->budget--) { s->failed_pc=0x0c042466u; return 0; }
r[5]&=r[3];
goto P_0c042468;
P_0c042468: /* original 2240, guest PC 0x0c042468 */
if(!s->budget--) { s->failed_pc=0x0c042468u; return 0; }
write(ram,r[2],r[4],1);
goto P_0c04246a;
P_0c04246a: /* original d106, guest PC 0x0c04246a */
if(!s->budget--) { s->failed_pc=0x0c04246au; return 0; }
r[1]=read(ram,0x0c042484u,4);
goto P_0c04246c;
P_0c04246c: /* original 000b, guest PC 0x0c04246c */
if(!s->budget--) { s->failed_pc=0x0c04246cu; return 0; }
target=r[16];
write(ram,r[1],r[5],1);
s->pc=target; return ram->oob==0;
P_0c04246e: /* original 2150, guest PC 0x0c04246e */
if(!s->budget--) { s->failed_pc=0x0c04246eu; return 0; }
write(ram,r[1],r[5],1);
if(!vf3_matrix_family(0x0c042470u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042470u; return 0; } return 1;
P_0c042490: /* original d30a, guest PC 0x0c042490 */
if(!s->budget--) { s->failed_pc=0x0c042490u; return 0; }
r[3]=read(ram,0x0c0424bcu,4);
goto P_0c042492;
P_0c042492: /* original d20b, guest PC 0x0c042492 */
if(!s->budget--) { s->failed_pc=0x0c042492u; return 0; }
r[2]=read(ram,0x0c0424c0u,4);
goto P_0c042494;
P_0c042494: /* original 6530, guest PC 0x0c042494 */
if(!s->budget--) { s->failed_pc=0x0c042494u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c042496;
P_0c042496: /* original d10b, guest PC 0x0c042496 */
if(!s->budget--) { s->failed_pc=0x0c042496u; return 0; }
r[1]=read(ram,0x0c0424c4u,4);
goto P_0c042498;
P_0c042498: /* original 4f12, guest PC 0x0c042498 */
if(!s->budget--) { s->failed_pc=0x0c042498u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04249a;
P_0c04249a: /* original 0527, guest PC 0x0c04249a */
if(!s->budget--) { s->failed_pc=0x0c04249au; return 0; }
r[19]=r[5]*r[2];
goto P_0c04249c;
P_0c04249c: /* original 6412, guest PC 0x0c04249c */
if(!s->budget--) { s->failed_pc=0x0c04249cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c04249e;
P_0c04249e: /* original 2448, guest PC 0x0c04249e */
if(!s->budget--) { s->failed_pc=0x0c04249eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0424a0;
P_0c0424a0: /* original 8d08, guest PC 0x0c0424a0 */
if(!s->budget--) { s->failed_pc=0x0c0424a0u; return 0; }
cond=r[17]&1u;
r[5]=r[19];
if(cond) { goto P_0c0424b4; }
goto P_0c0424a4;
P_0c0424a2: /* original 051a, guest PC 0x0c0424a2 */
if(!s->budget--) { s->failed_pc=0x0c0424a2u; return 0; }
r[5]=r[19];
goto P_0c0424a4;
P_0c0424a4: /* original 9608, guest PC 0x0c0424a4 */
if(!s->budget--) { s->failed_pc=0x0c0424a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0424b8u,2);
goto P_0c0424a6;
P_0c0424a6: /* original 364c, guest PC 0x0c0424a6 */
if(!s->budget--) { s->failed_pc=0x0c0424a6u; return 0; }
r[6]+=r[4];
goto P_0c0424a8;
P_0c0424a8: /* original d407, guest PC 0x0c0424a8 */
if(!s->budget--) { s->failed_pc=0x0c0424a8u; return 0; }
r[4]=read(ram,0x0c0424c8u,4);
goto P_0c0424aa;
P_0c0424aa: /* original 74ff, guest PC 0x0c0424aa */
if(!s->budget--) { s->failed_pc=0x0c0424aau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0424ac;
P_0c0424ac: /* original 2652, guest PC 0x0c0424ac */
if(!s->budget--) { s->failed_pc=0x0c0424acu; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0424ae;
P_0c0424ae: /* original 4411, guest PC 0x0c0424ae */
if(!s->budget--) { s->failed_pc=0x0c0424aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0424b0;
P_0c0424b0: /* original 8dfb, guest PC 0x0c0424b0 */
if(!s->budget--) { s->failed_pc=0x0c0424b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(cond) { goto P_0c0424aa; }
goto P_0c0424b4;
P_0c0424b2: /* original 7604, guest PC 0x0c0424b2 */
if(!s->budget--) { s->failed_pc=0x0c0424b2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0424b4;
P_0c0424b4: /* original 000b, guest PC 0x0c0424b4 */
if(!s->budget--) { s->failed_pc=0x0c0424b4u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0424b6: /* original 4f16, guest PC 0x0c0424b6 */
if(!s->budget--) { s->failed_pc=0x0c0424b6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0424b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0424b8u; return 0; } return 1;
P_0c042950: /* original d312, guest PC 0x0c042950 */
if(!s->budget--) { s->failed_pc=0x0c042950u; return 0; }
r[3]=read(ram,0x0c04299cu,4);
goto P_0c042952;
P_0c042952: /* original 000b, guest PC 0x0c042952 */
if(!s->budget--) { s->failed_pc=0x0c042952u; return 0; }
target=r[16];
write(ram,r[3],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042954: /* original 2340, guest PC 0x0c042954 */
if(!s->budget--) { s->failed_pc=0x0c042954u; return 0; }
write(ram,r[3],r[4],1);
if(!vf3_matrix_family(0x0c042956u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042956u; return 0; } return 1;
P_0c042960: /* original d20f, guest PC 0x0c042960 */
if(!s->budget--) { s->failed_pc=0x0c042960u; return 0; }
r[2]=read(ram,0x0c0429a0u,4);
goto P_0c042962;
P_0c042962: /* original 000b, guest PC 0x0c042962 */
if(!s->budget--) { s->failed_pc=0x0c042962u; return 0; }
target=r[16];
write(ram,r[2],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042964: /* original 2240, guest PC 0x0c042964 */
if(!s->budget--) { s->failed_pc=0x0c042964u; return 0; }
write(ram,r[2],r[4],1);
if(!vf3_matrix_family(0x0c042966u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042966u; return 0; } return 1;
P_0c042970: /* original d30c, guest PC 0x0c042970 */
if(!s->budget--) { s->failed_pc=0x0c042970u; return 0; }
r[3]=read(ram,0x0c0429a4u,4);
goto P_0c042972;
P_0c042972: /* original 000b, guest PC 0x0c042972 */
if(!s->budget--) { s->failed_pc=0x0c042972u; return 0; }
target=r[16];
write(ram,r[3],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042974: /* original 2340, guest PC 0x0c042974 */
if(!s->budget--) { s->failed_pc=0x0c042974u; return 0; }
write(ram,r[3],r[4],1);
if(!vf3_matrix_family(0x0c042976u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042976u; return 0; } return 1;
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c042cc0u,s,ram); }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
return vf3_matrix_family(0x0c042cc0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
