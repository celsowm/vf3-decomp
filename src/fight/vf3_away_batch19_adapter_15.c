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
int vf3_away_batch19_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062bfau: goto P_0c062bfa;
case 0x0c062bfcu: goto P_0c062bfc;
case 0x0c062bfeu: goto P_0c062bfe;
case 0x0c062c00u: goto P_0c062c00;
case 0x0c062c02u: goto P_0c062c02;
case 0x0c062c04u: goto P_0c062c04;
case 0x0c062c06u: goto P_0c062c06;
case 0x0c062c08u: goto P_0c062c08;
case 0x0c062c0au: goto P_0c062c0a;
case 0x0c062c0cu: goto P_0c062c0c;
case 0x0c062c0eu: goto P_0c062c0e;
case 0x0c062c10u: goto P_0c062c10;
case 0x0c062c12u: goto P_0c062c12;
case 0x0c062c14u: goto P_0c062c14;
case 0x0c062c16u: goto P_0c062c16;
case 0x0c062c18u: goto P_0c062c18;
case 0x0c062c1au: goto P_0c062c1a;
case 0x0c062c1cu: goto P_0c062c1c;
case 0x0c062c1eu: goto P_0c062c1e;
case 0x0c062c20u: goto P_0c062c20;
case 0x0c062c22u: goto P_0c062c22;
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c062c4eu: goto P_0c062c4e;
case 0x0c062c50u: goto P_0c062c50;
case 0x0c062c52u: goto P_0c062c52;
case 0x0c062c54u: goto P_0c062c54;
case 0x0c062c56u: goto P_0c062c56;
case 0x0c062c58u: goto P_0c062c58;
case 0x0c062c5au: goto P_0c062c5a;
case 0x0c062c5cu: goto P_0c062c5c;
case 0x0c062c5eu: goto P_0c062c5e;
case 0x0c062c60u: goto P_0c062c60;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c0644bcu: goto P_0c0644bc;
case 0x0c0644beu: goto P_0c0644be;
case 0x0c0644c0u: goto P_0c0644c0;
case 0x0c0644c2u: goto P_0c0644c2;
case 0x0c0644c4u: goto P_0c0644c4;
case 0x0c0644c6u: goto P_0c0644c6;
case 0x0c0644c8u: goto P_0c0644c8;
case 0x0c0644cau: goto P_0c0644ca;
case 0x0c0644ccu: goto P_0c0644cc;
case 0x0c0644ceu: goto P_0c0644ce;
case 0x0c0644d0u: goto P_0c0644d0;
case 0x0c0644d2u: goto P_0c0644d2;
case 0x0c0644d4u: goto P_0c0644d4;
case 0x0c0696b0u: goto P_0c0696b0;
case 0x0c0696b2u: goto P_0c0696b2;
case 0x0c0696b4u: goto P_0c0696b4;
case 0x0c0696b6u: goto P_0c0696b6;
case 0x0c0696b8u: goto P_0c0696b8;
case 0x0c0696bau: goto P_0c0696ba;
case 0x0c0696bcu: goto P_0c0696bc;
case 0x0c0696beu: goto P_0c0696be;
case 0x0c0696c0u: goto P_0c0696c0;
case 0x0c0696c2u: goto P_0c0696c2;
case 0x0c0696c4u: goto P_0c0696c4;
case 0x0c072e24u: goto P_0c072e24;
case 0x0c072e26u: goto P_0c072e26;
case 0x0c072e28u: goto P_0c072e28;
case 0x0c072e2au: goto P_0c072e2a;
case 0x0c072e2cu: goto P_0c072e2c;
case 0x0c072e2eu: goto P_0c072e2e;
case 0x0c072e30u: goto P_0c072e30;
case 0x0c072e32u: goto P_0c072e32;
case 0x0c072e34u: goto P_0c072e34;
case 0x0c072e36u: goto P_0c072e36;
case 0x0c072e38u: goto P_0c072e38;
case 0x0c072e3au: goto P_0c072e3a;
case 0x0c072e3cu: goto P_0c072e3c;
case 0x0c072e3eu: goto P_0c072e3e;
case 0x0c072e40u: goto P_0c072e40;
case 0x0c072e42u: goto P_0c072e42;
case 0x0c072e44u: goto P_0c072e44;
case 0x0c072e46u: goto P_0c072e46;
case 0x0c072e48u: goto P_0c072e48;
case 0x0c072e4au: goto P_0c072e4a;
case 0x0c072e4cu: goto P_0c072e4c;
case 0x0c072e4eu: goto P_0c072e4e;
case 0x0c072e50u: goto P_0c072e50;
case 0x0c072e52u: goto P_0c072e52;
case 0x0c072e54u: goto P_0c072e54;
case 0x0c072e56u: goto P_0c072e56;
case 0x0c072e58u: goto P_0c072e58;
case 0x0c072e5au: goto P_0c072e5a;
case 0x0c072e5cu: goto P_0c072e5c;
case 0x0c072e5eu: goto P_0c072e5e;
case 0x0c072e60u: goto P_0c072e60;
case 0x0c072e62u: goto P_0c072e62;
case 0x0c072e64u: goto P_0c072e64;
case 0x0c072e66u: goto P_0c072e66;
case 0x0c072e68u: goto P_0c072e68;
case 0x0c072e6au: goto P_0c072e6a;
case 0x0c072e6cu: goto P_0c072e6c;
case 0x0c072e6eu: goto P_0c072e6e;
case 0x0c072e70u: goto P_0c072e70;
case 0x0c072e72u: goto P_0c072e72;
case 0x0c072e74u: goto P_0c072e74;
case 0x0c072e76u: goto P_0c072e76;
case 0x0c072e78u: goto P_0c072e78;
case 0x0c072e7au: goto P_0c072e7a;
case 0x0c072e7cu: goto P_0c072e7c;
case 0x0c072e7eu: goto P_0c072e7e;
case 0x0c072e80u: goto P_0c072e80;
case 0x0c072e82u: goto P_0c072e82;
case 0x0c072e84u: goto P_0c072e84;
case 0x0c072e86u: goto P_0c072e86;
case 0x0c072e88u: goto P_0c072e88;
case 0x0c072e8au: goto P_0c072e8a;
case 0x0c072e8cu: goto P_0c072e8c;
case 0x0c072e8eu: goto P_0c072e8e;
case 0x0c072e90u: goto P_0c072e90;
case 0x0c072e92u: goto P_0c072e92;
case 0x0c072e94u: goto P_0c072e94;
case 0x0c072e96u: goto P_0c072e96;
case 0x0c072e98u: goto P_0c072e98;
case 0x0c072e9au: goto P_0c072e9a;
case 0x0c072e9cu: goto P_0c072e9c;
case 0x0c072e9eu: goto P_0c072e9e;
case 0x0c072ea0u: goto P_0c072ea0;
case 0x0c072ea2u: goto P_0c072ea2;
case 0x0c072ea4u: goto P_0c072ea4;
case 0x0c072ea6u: goto P_0c072ea6;
case 0x0c072ea8u: goto P_0c072ea8;
case 0x0c072eaau: goto P_0c072eaa;
case 0x0c072eacu: goto P_0c072eac;
case 0x0c072eaeu: goto P_0c072eae;
case 0x0c072eb0u: goto P_0c072eb0;
case 0x0c072eb2u: goto P_0c072eb2;
case 0x0c072eb4u: goto P_0c072eb4;
case 0x0c072eb6u: goto P_0c072eb6;
case 0x0c072eb8u: goto P_0c072eb8;
case 0x0c072ebau: goto P_0c072eba;
case 0x0c072ebcu: goto P_0c072ebc;
case 0x0c072ebeu: goto P_0c072ebe;
case 0x0c072ec0u: goto P_0c072ec0;
case 0x0c073320u: goto P_0c073320;
case 0x0c073322u: goto P_0c073322;
case 0x0c073324u: goto P_0c073324;
case 0x0c073326u: goto P_0c073326;
case 0x0c073328u: goto P_0c073328;
case 0x0c07332au: goto P_0c07332a;
case 0x0c07332cu: goto P_0c07332c;
case 0x0c07332eu: goto P_0c07332e;
case 0x0c073330u: goto P_0c073330;
case 0x0c073332u: goto P_0c073332;
case 0x0c073334u: goto P_0c073334;
case 0x0c073336u: goto P_0c073336;
case 0x0c073338u: goto P_0c073338;
case 0x0c07333au: goto P_0c07333a;
case 0x0c07333cu: goto P_0c07333c;
case 0x0c07333eu: goto P_0c07333e;
case 0x0c073340u: goto P_0c073340;
case 0x0c073342u: goto P_0c073342;
case 0x0c073344u: goto P_0c073344;
case 0x0c073346u: goto P_0c073346;
case 0x0c073348u: goto P_0c073348;
case 0x0c07334au: goto P_0c07334a;
case 0x0c07334cu: goto P_0c07334c;
case 0x0c07334eu: goto P_0c07334e;
case 0x0c073350u: goto P_0c073350;
case 0x0c073352u: goto P_0c073352;
case 0x0c073354u: goto P_0c073354;
case 0x0c073356u: goto P_0c073356;
case 0x0c073358u: goto P_0c073358;
case 0x0c07335au: goto P_0c07335a;
case 0x0c07335cu: goto P_0c07335c;
case 0x0c07335eu: goto P_0c07335e;
case 0x0c073360u: goto P_0c073360;
case 0x0c073362u: goto P_0c073362;
case 0x0c073364u: goto P_0c073364;
case 0x0c073366u: goto P_0c073366;
case 0x0c073368u: goto P_0c073368;
case 0x0c07336au: goto P_0c07336a;
case 0x0c07336cu: goto P_0c07336c;
case 0x0c07336eu: goto P_0c07336e;
case 0x0c073370u: goto P_0c073370;
case 0x0c073372u: goto P_0c073372;
case 0x0c073374u: goto P_0c073374;
case 0x0c073376u: goto P_0c073376;
case 0x0c073378u: goto P_0c073378;
case 0x0c07337au: goto P_0c07337a;
case 0x0c07337cu: goto P_0c07337c;
case 0x0c07337eu: goto P_0c07337e;
case 0x0c073380u: goto P_0c073380;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062bfa: /* original e700, guest PC 0x0c062bfa */
if(!s->budget--) { s->failed_pc=0x0c062bfau; return 0; }
r[7]=0x00000000u;
goto P_0c062bfc;
P_0c062bfc: /* original d526, guest PC 0x0c062bfc */
if(!s->budget--) { s->failed_pc=0x0c062bfcu; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062bfe;
P_0c062bfe: /* original 6453, guest PC 0x0c062bfe */
if(!s->budget--) { s->failed_pc=0x0c062bfeu; return 0; }
r[4]=r[5];
goto P_0c062c00;
P_0c062c00: /* original 9047, guest PC 0x0c062c00 */
if(!s->budget--) { s->failed_pc=0x0c062c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c02;
P_0c062c02: /* original 6653, guest PC 0x0c062c02 */
if(!s->budget--) { s->failed_pc=0x0c062c02u; return 0; }
r[6]=r[5];
goto P_0c062c04;
P_0c062c04: /* original e501, guest PC 0x0c062c04 */
if(!s->budget--) { s->failed_pc=0x0c062c04u; return 0; }
r[5]=0x00000001u;
goto P_0c062c06;
P_0c062c06: /* original 6361, guest PC 0x0c062c06 */
if(!s->budget--) { s->failed_pc=0x0c062c06u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c062c08;
P_0c062c08: /* original 633d, guest PC 0x0c062c08 */
if(!s->budget--) { s->failed_pc=0x0c062c08u; return 0; }
r[3]=r[3]&65535u;
goto P_0c062c0a;
P_0c062c0a: /* original 2358, guest PC 0x0c062c0a */
if(!s->budget--) { s->failed_pc=0x0c062c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c062c0c;
P_0c062c0c: /* original 8b02, guest PC 0x0c062c0c */
if(!s->budget--) { s->failed_pc=0x0c062c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c14; }
goto P_0c062c0e;
P_0c062c0e: /* original 2451, guest PC 0x0c062c0e */
if(!s->budget--) { s->failed_pc=0x0c062c0eu; return 0; }
write(ram,r[4],r[5],2);
goto P_0c062c10;
P_0c062c10: /* original 000b, guest PC 0x0c062c10 */
if(!s->budget--) { s->failed_pc=0x0c062c10u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c062c12: /* original 6043, guest PC 0x0c062c12 */
if(!s->budget--) { s->failed_pc=0x0c062c12u; return 0; }
r[0]=r[4];
goto P_0c062c14;
P_0c062c14: /* original 7701, guest PC 0x0c062c14 */
if(!s->budget--) { s->failed_pc=0x0c062c14u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c16;
P_0c062c16: /* original 744c, guest PC 0x0c062c16 */
if(!s->budget--) { s->failed_pc=0x0c062c16u; return 0; }
r[4]+=0x0000004cu;
goto P_0c062c18;
P_0c062c18: /* original 3703, guest PC 0x0c062c18 */
if(!s->budget--) { s->failed_pc=0x0c062c18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c062c1a;
P_0c062c1a: /* original 8ff4, guest PC 0x0c062c1a */
if(!s->budget--) { s->failed_pc=0x0c062c1au; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c06; }
goto P_0c062c1e;
P_0c062c1c: /* original 764c, guest PC 0x0c062c1c */
if(!s->budget--) { s->failed_pc=0x0c062c1cu; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c1e;
P_0c062c1e: /* original e000, guest PC 0x0c062c1e */
if(!s->budget--) { s->failed_pc=0x0c062c1eu; return 0; }
r[0]=0x00000000u;
goto P_0c062c20;
P_0c062c20: /* original 000b, guest PC 0x0c062c20 */
if(!s->budget--) { s->failed_pc=0x0c062c20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062c22: /* original 0009, guest PC 0x0c062c22 */
if(!s->budget--) { s->failed_pc=0x0c062c22u; return 0; }
goto P_0c062c24;
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062c4e;
P_0c062c4e: /* original 6342, guest PC 0x0c062c4e */
if(!s->budget--) { s->failed_pc=0x0c062c4eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c062c50;
P_0c062c50: /* original 2338, guest PC 0x0c062c50 */
if(!s->budget--) { s->failed_pc=0x0c062c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062c52;
P_0c062c52: /* original 8b02, guest PC 0x0c062c52 */
if(!s->budget--) { s->failed_pc=0x0c062c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c5a; }
goto P_0c062c54;
P_0c062c54: /* original e300, guest PC 0x0c062c54 */
if(!s->budget--) { s->failed_pc=0x0c062c54u; return 0; }
r[3]=0x00000000u;
goto P_0c062c56;
P_0c062c56: /* original a002, guest PC 0x0c062c56 */
if(!s->budget--) { s->failed_pc=0x0c062c56u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5e;
P_0c062c58: /* original 1531, guest PC 0x0c062c58 */
if(!s->budget--) { s->failed_pc=0x0c062c58u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5a;
P_0c062c5a: /* original 6242, guest PC 0x0c062c5a */
if(!s->budget--) { s->failed_pc=0x0c062c5au; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c062c5c;
P_0c062c5c: /* original 1521, guest PC 0x0c062c5c */
if(!s->budget--) { s->failed_pc=0x0c062c5cu; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c062c5e;
P_0c062c5e: /* original 000b, guest PC 0x0c062c5e */
if(!s->budget--) { s->failed_pc=0x0c062c5eu; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c062c60: /* original 2452, guest PC 0x0c062c60 */
if(!s->budget--) { s->failed_pc=0x0c062c60u; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c062c62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062c62u; return 0; } return 1;
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
P_0c0644bc: /* original d009, guest PC 0x0c0644bc */
if(!s->budget--) { s->failed_pc=0x0c0644bcu; return 0; }
r[0]=read(ram,0x0c0644e4u,4);
goto P_0c0644be;
P_0c0644be: /* original 7ff8, guest PC 0x0c0644be */
if(!s->budget--) { s->failed_pc=0x0c0644beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0644c0;
P_0c0644c0: /* original 2f42, guest PC 0x0c0644c0 */
if(!s->budget--) { s->failed_pc=0x0c0644c0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0644c2;
P_0c0644c2: /* original 6343, guest PC 0x0c0644c2 */
if(!s->budget--) { s->failed_pc=0x0c0644c2u; return 0; }
r[3]=r[4];
goto P_0c0644c4;
P_0c0644c4: /* original 4308, guest PC 0x0c0644c4 */
if(!s->budget--) { s->failed_pc=0x0c0644c4u; return 0; }
r[3]<<=2;
goto P_0c0644c6;
P_0c0644c6: /* original 4300, guest PC 0x0c0644c6 */
if(!s->budget--) { s->failed_pc=0x0c0644c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0644c8;
P_0c0644c8: /* original 1f31, guest PC 0x0c0644c8 */
if(!s->budget--) { s->failed_pc=0x0c0644c8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0644ca;
P_0c0644ca: /* original 023e, guest PC 0x0c0644ca */
if(!s->budget--) { s->failed_pc=0x0c0644cau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0644cc;
P_0c0644cc: /* original 6403, guest PC 0x0c0644cc */
if(!s->budget--) { s->failed_pc=0x0c0644ccu; return 0; }
r[4]=r[0];
goto P_0c0644ce;
P_0c0644ce: /* original 343c, guest PC 0x0c0644ce */
if(!s->budget--) { s->failed_pc=0x0c0644ceu; return 0; }
r[4]+=r[3];
goto P_0c0644d0;
P_0c0644d0: /* original 5441, guest PC 0x0c0644d0 */
if(!s->budget--) { s->failed_pc=0x0c0644d0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0644d2;
P_0c0644d2: /* original 422b, guest PC 0x0c0644d2 */
if(!s->budget--) { s->failed_pc=0x0c0644d2u; return 0; }
target=r[2];
r[15]+=0x00000008u;
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
P_0c0644d4: /* original 7f08, guest PC 0x0c0644d4 */
if(!s->budget--) { s->failed_pc=0x0c0644d4u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0644d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0644d6u; return 0; } return 1;
P_0c0696b0: /* original d642, guest PC 0x0c0696b0 */
if(!s->budget--) { s->failed_pc=0x0c0696b0u; return 0; }
r[6]=read(ram,0x0c0697bcu,4);
goto P_0c0696b2;
P_0c0696b2: /* original 957c, guest PC 0x0c0696b2 */
if(!s->budget--) { s->failed_pc=0x0c0696b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697aeu,2);
goto P_0c0696b4;
P_0c0696b4: /* original a002, guest PC 0x0c0696b4 */
if(!s->budget--) { s->failed_pc=0x0c0696b4u; return 0; }
r[4]=0x00000000u;
goto P_0c0696bc;
P_0c0696b6: /* original e400, guest PC 0x0c0696b6 */
if(!s->budget--) { s->failed_pc=0x0c0696b6u; return 0; }
r[4]=0x00000000u;
goto P_0c0696b8;
P_0c0696b8: /* original 2642, guest PC 0x0c0696b8 */
if(!s->budget--) { s->failed_pc=0x0c0696b8u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0696ba;
P_0c0696ba: /* original 7604, guest PC 0x0c0696ba */
if(!s->budget--) { s->failed_pc=0x0c0696bau; return 0; }
r[6]+=0x00000004u;
goto P_0c0696bc;
P_0c0696bc: /* original 2558, guest PC 0x0c0696bc */
if(!s->budget--) { s->failed_pc=0x0c0696bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0696be;
P_0c0696be: /* original 8ffb, guest PC 0x0c0696be */
if(!s->budget--) { s->failed_pc=0x0c0696beu; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(!cond) { goto P_0c0696b8; }
goto P_0c0696c2;
P_0c0696c0: /* original 75ff, guest PC 0x0c0696c0 */
if(!s->budget--) { s->failed_pc=0x0c0696c0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0696c2;
P_0c0696c2: /* original 000b, guest PC 0x0c0696c2 */
if(!s->budget--) { s->failed_pc=0x0c0696c2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0696c4: /* original 0009, guest PC 0x0c0696c4 */
if(!s->budget--) { s->failed_pc=0x0c0696c4u; return 0; }
if(!vf3_matrix_family(0x0c0696c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0696c6u; return 0; } return 1;
P_0c072e24: /* original 2fe6, guest PC 0x0c072e24 */
if(!s->budget--) { s->failed_pc=0x0c072e24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072e26;
P_0c072e26: /* original e500, guest PC 0x0c072e26 */
if(!s->budget--) { s->failed_pc=0x0c072e26u; return 0; }
r[5]=0x00000000u;
goto P_0c072e28;
P_0c072e28: /* original 2fd6, guest PC 0x0c072e28 */
if(!s->budget--) { s->failed_pc=0x0c072e28u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072e2a;
P_0c072e2a: /* original de56, guest PC 0x0c072e2a */
if(!s->budget--) { s->failed_pc=0x0c072e2au; return 0; }
r[14]=read(ram,0x0c072f84u,4);
goto P_0c072e2c;
P_0c072e2c: /* original 4f22, guest PC 0x0c072e2c */
if(!s->budget--) { s->failed_pc=0x0c072e2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c072e2e;
P_0c072e2e: /* original dd56, guest PC 0x0c072e2e */
if(!s->budget--) { s->failed_pc=0x0c072e2eu; return 0; }
r[13]=read(ram,0x0c072f88u,4);
goto P_0c072e30;
P_0c072e30: /* original 64e3, guest PC 0x0c072e30 */
if(!s->budget--) { s->failed_pc=0x0c072e30u; return 0; }
r[4]=r[14];
goto P_0c072e32;
P_0c072e32: /* original 4d0b, guest PC 0x0c072e32 */
if(!s->budget--) { s->failed_pc=0x0c072e32u; return 0; }
target=r[13];
r[16]=code_base|0x0c072e36u;
r[4]+=0x00000017u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e36u) { target=s->pc; goto dispatch; }
goto P_0c072e36;
P_0c072e34: /* original 7417, guest PC 0x0c072e34 */
if(!s->budget--) { s->failed_pc=0x0c072e34u; return 0; }
r[4]+=0x00000017u;
goto P_0c072e36;
P_0c072e36: /* original 64e3, guest PC 0x0c072e36 */
if(!s->budget--) { s->failed_pc=0x0c072e36u; return 0; }
r[4]=r[14];
goto P_0c072e38;
P_0c072e38: /* original e502, guest PC 0x0c072e38 */
if(!s->budget--) { s->failed_pc=0x0c072e38u; return 0; }
r[5]=0x00000002u;
goto P_0c072e3a;
P_0c072e3a: /* original 4d0b, guest PC 0x0c072e3a */
if(!s->budget--) { s->failed_pc=0x0c072e3au; return 0; }
target=r[13];
r[16]=code_base|0x0c072e3eu;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e3eu) { target=s->pc; goto dispatch; }
goto P_0c072e3e;
P_0c072e3c: /* original 7418, guest PC 0x0c072e3c */
if(!s->budget--) { s->failed_pc=0x0c072e3cu; return 0; }
r[4]+=0x00000018u;
goto P_0c072e3e;
P_0c072e3e: /* original 64e3, guest PC 0x0c072e3e */
if(!s->budget--) { s->failed_pc=0x0c072e3eu; return 0; }
r[4]=r[14];
goto P_0c072e40;
P_0c072e40: /* original e502, guest PC 0x0c072e40 */
if(!s->budget--) { s->failed_pc=0x0c072e40u; return 0; }
r[5]=0x00000002u;
goto P_0c072e42;
P_0c072e42: /* original 4d0b, guest PC 0x0c072e42 */
if(!s->budget--) { s->failed_pc=0x0c072e42u; return 0; }
target=r[13];
r[16]=code_base|0x0c072e46u;
r[4]+=0x0000001au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e46u) { target=s->pc; goto dispatch; }
goto P_0c072e46;
P_0c072e44: /* original 741a, guest PC 0x0c072e44 */
if(!s->budget--) { s->failed_pc=0x0c072e44u; return 0; }
r[4]+=0x0000001au;
goto P_0c072e46;
P_0c072e46: /* original 64e3, guest PC 0x0c072e46 */
if(!s->budget--) { s->failed_pc=0x0c072e46u; return 0; }
r[4]=r[14];
goto P_0c072e48;
P_0c072e48: /* original e502, guest PC 0x0c072e48 */
if(!s->budget--) { s->failed_pc=0x0c072e48u; return 0; }
r[5]=0x00000002u;
goto P_0c072e4a;
P_0c072e4a: /* original 4d0b, guest PC 0x0c072e4a */
if(!s->budget--) { s->failed_pc=0x0c072e4au; return 0; }
target=r[13];
r[16]=code_base|0x0c072e4eu;
r[4]+=0x00000019u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e4eu) { target=s->pc; goto dispatch; }
goto P_0c072e4e;
P_0c072e4c: /* original 7419, guest PC 0x0c072e4c */
if(!s->budget--) { s->failed_pc=0x0c072e4cu; return 0; }
r[4]+=0x00000019u;
goto P_0c072e4e;
P_0c072e4e: /* original 64e3, guest PC 0x0c072e4e */
if(!s->budget--) { s->failed_pc=0x0c072e4eu; return 0; }
r[4]=r[14];
goto P_0c072e50;
P_0c072e50: /* original e502, guest PC 0x0c072e50 */
if(!s->budget--) { s->failed_pc=0x0c072e50u; return 0; }
r[5]=0x00000002u;
goto P_0c072e52;
P_0c072e52: /* original 4d0b, guest PC 0x0c072e52 */
if(!s->budget--) { s->failed_pc=0x0c072e52u; return 0; }
target=r[13];
r[16]=code_base|0x0c072e56u;
r[4]+=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e56u) { target=s->pc; goto dispatch; }
goto P_0c072e56;
P_0c072e54: /* original 741b, guest PC 0x0c072e54 */
if(!s->budget--) { s->failed_pc=0x0c072e54u; return 0; }
r[4]+=0x0000001bu;
goto P_0c072e56;
P_0c072e56: /* original 64e3, guest PC 0x0c072e56 */
if(!s->budget--) { s->failed_pc=0x0c072e56u; return 0; }
r[4]=r[14];
goto P_0c072e58;
P_0c072e58: /* original e500, guest PC 0x0c072e58 */
if(!s->budget--) { s->failed_pc=0x0c072e58u; return 0; }
r[5]=0x00000000u;
goto P_0c072e5a;
P_0c072e5a: /* original 4d0b, guest PC 0x0c072e5a */
if(!s->budget--) { s->failed_pc=0x0c072e5au; return 0; }
target=r[13];
r[16]=code_base|0x0c072e5eu;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e5eu) { target=s->pc; goto dispatch; }
goto P_0c072e5e;
P_0c072e5c: /* original 741c, guest PC 0x0c072e5c */
if(!s->budget--) { s->failed_pc=0x0c072e5cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c072e5e;
P_0c072e5e: /* original 64e3, guest PC 0x0c072e5e */
if(!s->budget--) { s->failed_pc=0x0c072e5eu; return 0; }
r[4]=r[14];
goto P_0c072e60;
P_0c072e60: /* original e51b, guest PC 0x0c072e60 */
if(!s->budget--) { s->failed_pc=0x0c072e60u; return 0; }
r[5]=0x0000001bu;
goto P_0c072e62;
P_0c072e62: /* original 4d0b, guest PC 0x0c072e62 */
if(!s->budget--) { s->failed_pc=0x0c072e62u; return 0; }
target=r[13];
r[16]=code_base|0x0c072e66u;
r[4]+=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e66u) { target=s->pc; goto dispatch; }
goto P_0c072e66;
P_0c072e64: /* original 741d, guest PC 0x0c072e64 */
if(!s->budget--) { s->failed_pc=0x0c072e64u; return 0; }
r[4]+=0x0000001du;
goto P_0c072e66;
P_0c072e66: /* original b25b, guest PC 0x0c072e66 */
if(!s->budget--) { s->failed_pc=0x0c072e66u; return 0; }
target=code_base|0x0c073320u; r[16]=code_base|0x0c072e6au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e6au) { target=s->pc; goto dispatch; }
goto P_0c072e6a;
P_0c072e68: /* original 64e3, guest PC 0x0c072e68 */
if(!s->budget--) { s->failed_pc=0x0c072e68u; return 0; }
r[4]=r[14];
goto P_0c072e6a;
P_0c072e6a: /* original 64e3, guest PC 0x0c072e6a */
if(!s->budget--) { s->failed_pc=0x0c072e6au; return 0; }
r[4]=r[14];
goto P_0c072e6c;
P_0c072e6c: /* original e501, guest PC 0x0c072e6c */
if(!s->budget--) { s->failed_pc=0x0c072e6cu; return 0; }
r[5]=0x00000001u;
goto P_0c072e6e;
P_0c072e6e: /* original 4d0b, guest PC 0x0c072e6e */
if(!s->budget--) { s->failed_pc=0x0c072e6eu; return 0; }
target=r[13];
r[16]=code_base|0x0c072e72u;
r[4]+=0x00000022u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e72u) { target=s->pc; goto dispatch; }
goto P_0c072e72;
P_0c072e70: /* original 7422, guest PC 0x0c072e70 */
if(!s->budget--) { s->failed_pc=0x0c072e70u; return 0; }
r[4]+=0x00000022u;
goto P_0c072e72;
P_0c072e72: /* original 64e3, guest PC 0x0c072e72 */
if(!s->budget--) { s->failed_pc=0x0c072e72u; return 0; }
r[4]=r[14];
goto P_0c072e74;
P_0c072e74: /* original e501, guest PC 0x0c072e74 */
if(!s->budget--) { s->failed_pc=0x0c072e74u; return 0; }
r[5]=0x00000001u;
goto P_0c072e76;
P_0c072e76: /* original 4d0b, guest PC 0x0c072e76 */
if(!s->budget--) { s->failed_pc=0x0c072e76u; return 0; }
target=r[13];
r[16]=code_base|0x0c072e7au;
r[4]+=0x00000023u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e7au) { target=s->pc; goto dispatch; }
goto P_0c072e7a;
P_0c072e78: /* original 7423, guest PC 0x0c072e78 */
if(!s->budget--) { s->failed_pc=0x0c072e78u; return 0; }
r[4]+=0x00000023u;
goto P_0c072e7a;
P_0c072e7a: /* original 64e3, guest PC 0x0c072e7a */
if(!s->budget--) { s->failed_pc=0x0c072e7au; return 0; }
r[4]=r[14];
goto P_0c072e7c;
P_0c072e7c: /* original e501, guest PC 0x0c072e7c */
if(!s->budget--) { s->failed_pc=0x0c072e7cu; return 0; }
r[5]=0x00000001u;
goto P_0c072e7e;
P_0c072e7e: /* original 4d0b, guest PC 0x0c072e7e */
if(!s->budget--) { s->failed_pc=0x0c072e7eu; return 0; }
target=r[13];
r[16]=code_base|0x0c072e82u;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e82u) { target=s->pc; goto dispatch; }
goto P_0c072e82;
P_0c072e80: /* original 7424, guest PC 0x0c072e80 */
if(!s->budget--) { s->failed_pc=0x0c072e80u; return 0; }
r[4]+=0x00000024u;
goto P_0c072e82;
P_0c072e82: /* original 64e3, guest PC 0x0c072e82 */
if(!s->budget--) { s->failed_pc=0x0c072e82u; return 0; }
r[4]=r[14];
goto P_0c072e84;
P_0c072e84: /* original e500, guest PC 0x0c072e84 */
if(!s->budget--) { s->failed_pc=0x0c072e84u; return 0; }
r[5]=0x00000000u;
goto P_0c072e86;
P_0c072e86: /* original 4d0b, guest PC 0x0c072e86 */
if(!s->budget--) { s->failed_pc=0x0c072e86u; return 0; }
target=r[13];
r[16]=code_base|0x0c072e8au;
r[4]+=0x00000025u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e8au) { target=s->pc; goto dispatch; }
goto P_0c072e8a;
P_0c072e88: /* original 7425, guest PC 0x0c072e88 */
if(!s->budget--) { s->failed_pc=0x0c072e88u; return 0; }
r[4]+=0x00000025u;
goto P_0c072e8a;
P_0c072e8a: /* original 64e3, guest PC 0x0c072e8a */
if(!s->budget--) { s->failed_pc=0x0c072e8au; return 0; }
r[4]=r[14];
goto P_0c072e8c;
P_0c072e8c: /* original e500, guest PC 0x0c072e8c */
if(!s->budget--) { s->failed_pc=0x0c072e8cu; return 0; }
r[5]=0x00000000u;
goto P_0c072e8e;
P_0c072e8e: /* original 4d0b, guest PC 0x0c072e8e */
if(!s->budget--) { s->failed_pc=0x0c072e8eu; return 0; }
target=r[13];
r[16]=code_base|0x0c072e92u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e92u) { target=s->pc; goto dispatch; }
goto P_0c072e92;
P_0c072e90: /* original 7426, guest PC 0x0c072e90 */
if(!s->budget--) { s->failed_pc=0x0c072e90u; return 0; }
r[4]+=0x00000026u;
goto P_0c072e92;
P_0c072e92: /* original 64e3, guest PC 0x0c072e92 */
if(!s->budget--) { s->failed_pc=0x0c072e92u; return 0; }
r[4]=r[14];
goto P_0c072e94;
P_0c072e94: /* original e500, guest PC 0x0c072e94 */
if(!s->budget--) { s->failed_pc=0x0c072e94u; return 0; }
r[5]=0x00000000u;
goto P_0c072e96;
P_0c072e96: /* original 4d0b, guest PC 0x0c072e96 */
if(!s->budget--) { s->failed_pc=0x0c072e96u; return 0; }
target=r[13];
r[16]=code_base|0x0c072e9au;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072e9au) { target=s->pc; goto dispatch; }
goto P_0c072e9a;
P_0c072e98: /* original 7427, guest PC 0x0c072e98 */
if(!s->budget--) { s->failed_pc=0x0c072e98u; return 0; }
r[4]+=0x00000027u;
goto P_0c072e9a;
P_0c072e9a: /* original 64e3, guest PC 0x0c072e9a */
if(!s->budget--) { s->failed_pc=0x0c072e9au; return 0; }
r[4]=r[14];
goto P_0c072e9c;
P_0c072e9c: /* original e500, guest PC 0x0c072e9c */
if(!s->budget--) { s->failed_pc=0x0c072e9cu; return 0; }
r[5]=0x00000000u;
goto P_0c072e9e;
P_0c072e9e: /* original 4d0b, guest PC 0x0c072e9e */
if(!s->budget--) { s->failed_pc=0x0c072e9eu; return 0; }
target=r[13];
r[16]=code_base|0x0c072ea2u;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072ea2u) { target=s->pc; goto dispatch; }
goto P_0c072ea2;
P_0c072ea0: /* original 7428, guest PC 0x0c072ea0 */
if(!s->budget--) { s->failed_pc=0x0c072ea0u; return 0; }
r[4]+=0x00000028u;
goto P_0c072ea2;
P_0c072ea2: /* original 64e3, guest PC 0x0c072ea2 */
if(!s->budget--) { s->failed_pc=0x0c072ea2u; return 0; }
r[4]=r[14];
goto P_0c072ea4;
P_0c072ea4: /* original e500, guest PC 0x0c072ea4 */
if(!s->budget--) { s->failed_pc=0x0c072ea4u; return 0; }
r[5]=0x00000000u;
goto P_0c072ea6;
P_0c072ea6: /* original 4d0b, guest PC 0x0c072ea6 */
if(!s->budget--) { s->failed_pc=0x0c072ea6u; return 0; }
target=r[13];
r[16]=code_base|0x0c072eaau;
r[4]+=0x00000029u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072eaau) { target=s->pc; goto dispatch; }
goto P_0c072eaa;
P_0c072ea8: /* original 7429, guest PC 0x0c072ea8 */
if(!s->budget--) { s->failed_pc=0x0c072ea8u; return 0; }
r[4]+=0x00000029u;
goto P_0c072eaa;
P_0c072eaa: /* original 64e3, guest PC 0x0c072eaa */
if(!s->budget--) { s->failed_pc=0x0c072eaau; return 0; }
r[4]=r[14];
goto P_0c072eac;
P_0c072eac: /* original e500, guest PC 0x0c072eac */
if(!s->budget--) { s->failed_pc=0x0c072eacu; return 0; }
r[5]=0x00000000u;
goto P_0c072eae;
P_0c072eae: /* original 4d0b, guest PC 0x0c072eae */
if(!s->budget--) { s->failed_pc=0x0c072eaeu; return 0; }
target=r[13];
r[16]=code_base|0x0c072eb2u;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072eb2u) { target=s->pc; goto dispatch; }
goto P_0c072eb2;
P_0c072eb0: /* original 742a, guest PC 0x0c072eb0 */
if(!s->budget--) { s->failed_pc=0x0c072eb0u; return 0; }
r[4]+=0x0000002au;
goto P_0c072eb2;
P_0c072eb2: /* original 64e3, guest PC 0x0c072eb2 */
if(!s->budget--) { s->failed_pc=0x0c072eb2u; return 0; }
r[4]=r[14];
goto P_0c072eb4;
P_0c072eb4: /* original e500, guest PC 0x0c072eb4 */
if(!s->budget--) { s->failed_pc=0x0c072eb4u; return 0; }
r[5]=0x00000000u;
goto P_0c072eb6;
P_0c072eb6: /* original 4d0b, guest PC 0x0c072eb6 */
if(!s->budget--) { s->failed_pc=0x0c072eb6u; return 0; }
target=r[13];
r[16]=code_base|0x0c072ebau;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c072ebau) { target=s->pc; goto dispatch; }
goto P_0c072eba;
P_0c072eb8: /* original 742b, guest PC 0x0c072eb8 */
if(!s->budget--) { s->failed_pc=0x0c072eb8u; return 0; }
r[4]+=0x0000002bu;
goto P_0c072eba;
P_0c072eba: /* original 4f26, guest PC 0x0c072eba */
if(!s->budget--) { s->failed_pc=0x0c072ebau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c072ebc;
P_0c072ebc: /* original 6df6, guest PC 0x0c072ebc */
if(!s->budget--) { s->failed_pc=0x0c072ebcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072ebe;
P_0c072ebe: /* original 000b, guest PC 0x0c072ebe */
if(!s->budget--) { s->failed_pc=0x0c072ebeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072ec0: /* original 6ef6, guest PC 0x0c072ec0 */
if(!s->budget--) { s->failed_pc=0x0c072ec0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c072ec2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c072ec2u; return 0; } return 1;
P_0c073320: /* original 2fe6, guest PC 0x0c073320 */
if(!s->budget--) { s->failed_pc=0x0c073320u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073322;
P_0c073322: /* original 6e43, guest PC 0x0c073322 */
if(!s->budget--) { s->failed_pc=0x0c073322u; return 0; }
r[14]=r[4];
goto P_0c073324;
P_0c073324: /* original 2fd6, guest PC 0x0c073324 */
if(!s->budget--) { s->failed_pc=0x0c073324u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073326;
P_0c073326: /* original 2fc6, guest PC 0x0c073326 */
if(!s->budget--) { s->failed_pc=0x0c073326u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073328;
P_0c073328: /* original 4f22, guest PC 0x0c073328 */
if(!s->budget--) { s->failed_pc=0x0c073328u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07332a;
P_0c07332a: /* original d31d, guest PC 0x0c07332a */
if(!s->budget--) { s->failed_pc=0x0c07332au; return 0; }
r[3]=read(ram,0x0c0733a0u,4);
goto P_0c07332c;
P_0c07332c: /* original 7ffc, guest PC 0x0c07332c */
if(!s->budget--) { s->failed_pc=0x0c07332cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07332e;
P_0c07332e: /* original 430b, guest PC 0x0c07332e */
if(!s->budget--) { s->failed_pc=0x0c07332eu; return 0; }
target=r[3];
r[16]=code_base|0x0c073332u;
r[4]+=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073332u) { target=s->pc; goto dispatch; }
goto P_0c073332;
P_0c073330: /* original 741d, guest PC 0x0c073330 */
if(!s->budget--) { s->failed_pc=0x0c073330u; return 0; }
r[4]+=0x0000001du;
goto P_0c073332;
P_0c073332: /* original 640c, guest PC 0x0c073332 */
if(!s->budget--) { s->failed_pc=0x0c073332u; return 0; }
r[4]=r[0]&255u;
goto P_0c073334;
P_0c073334: /* original dc1d, guest PC 0x0c073334 */
if(!s->budget--) { s->failed_pc=0x0c073334u; return 0; }
r[12]=read(ram,0x0c0733acu,4);
goto P_0c073336;
P_0c073336: /* original 74ff, guest PC 0x0c073336 */
if(!s->budget--) { s->failed_pc=0x0c073336u; return 0; }
r[4]+=0xffffffffu;
goto P_0c073338;
P_0c073338: /* original 4408, guest PC 0x0c073338 */
if(!s->budget--) { s->failed_pc=0x0c073338u; return 0; }
r[4]<<=2;
goto P_0c07333a;
P_0c07333a: /* original 3c4c, guest PC 0x0c07333a */
if(!s->budget--) { s->failed_pc=0x0c07333au; return 0; }
r[12]+=r[4];
goto P_0c07333c;
P_0c07333c: /* original 64e3, guest PC 0x0c07333c */
if(!s->budget--) { s->failed_pc=0x0c07333cu; return 0; }
r[4]=r[14];
goto P_0c07333e;
P_0c07333e: /* original 62c0, guest PC 0x0c07333e */
if(!s->budget--) { s->failed_pc=0x0c07333eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c073340;
P_0c073340: /* original 622c, guest PC 0x0c073340 */
if(!s->budget--) { s->failed_pc=0x0c073340u; return 0; }
r[2]=r[2]&255u;
goto P_0c073342;
P_0c073342: /* original 6523, guest PC 0x0c073342 */
if(!s->budget--) { s->failed_pc=0x0c073342u; return 0; }
r[5]=r[2];
goto P_0c073344;
P_0c073344: /* original 2f22, guest PC 0x0c073344 */
if(!s->budget--) { s->failed_pc=0x0c073344u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c073346;
P_0c073346: /* original dd18, guest PC 0x0c073346 */
if(!s->budget--) { s->failed_pc=0x0c073346u; return 0; }
r[13]=read(ram,0x0c0733a8u,4);
goto P_0c073348;
P_0c073348: /* original 4d0b, guest PC 0x0c073348 */
if(!s->budget--) { s->failed_pc=0x0c073348u; return 0; }
target=r[13];
r[16]=code_base|0x0c07334cu;
r[4]+=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07334cu) { target=s->pc; goto dispatch; }
goto P_0c07334c;
P_0c07334a: /* original 741e, guest PC 0x0c07334a */
if(!s->budget--) { s->failed_pc=0x0c07334au; return 0; }
r[4]+=0x0000001eu;
goto P_0c07334c;
P_0c07334c: /* original 84c1, guest PC 0x0c07334c */
if(!s->budget--) { s->failed_pc=0x0c07334cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+1,1);
goto P_0c07334e;
P_0c07334e: /* original 64e3, guest PC 0x0c07334e */
if(!s->budget--) { s->failed_pc=0x0c07334eu; return 0; }
r[4]=r[14];
goto P_0c073350;
P_0c073350: /* original 600c, guest PC 0x0c073350 */
if(!s->budget--) { s->failed_pc=0x0c073350u; return 0; }
r[0]=r[0]&255u;
goto P_0c073352;
P_0c073352: /* original 6503, guest PC 0x0c073352 */
if(!s->budget--) { s->failed_pc=0x0c073352u; return 0; }
r[5]=r[0];
goto P_0c073354;
P_0c073354: /* original 2f02, guest PC 0x0c073354 */
if(!s->budget--) { s->failed_pc=0x0c073354u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073356;
P_0c073356: /* original 4d0b, guest PC 0x0c073356 */
if(!s->budget--) { s->failed_pc=0x0c073356u; return 0; }
target=r[13];
r[16]=code_base|0x0c07335au;
r[4]+=0x0000001fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07335au) { target=s->pc; goto dispatch; }
goto P_0c07335a;
P_0c073358: /* original 741f, guest PC 0x0c073358 */
if(!s->budget--) { s->failed_pc=0x0c073358u; return 0; }
r[4]+=0x0000001fu;
goto P_0c07335a;
P_0c07335a: /* original 84c2, guest PC 0x0c07335a */
if(!s->budget--) { s->failed_pc=0x0c07335au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c07335c;
P_0c07335c: /* original 64e3, guest PC 0x0c07335c */
if(!s->budget--) { s->failed_pc=0x0c07335cu; return 0; }
r[4]=r[14];
goto P_0c07335e;
P_0c07335e: /* original 600c, guest PC 0x0c07335e */
if(!s->budget--) { s->failed_pc=0x0c07335eu; return 0; }
r[0]=r[0]&255u;
goto P_0c073360;
P_0c073360: /* original 6503, guest PC 0x0c073360 */
if(!s->budget--) { s->failed_pc=0x0c073360u; return 0; }
r[5]=r[0];
goto P_0c073362;
P_0c073362: /* original 2f02, guest PC 0x0c073362 */
if(!s->budget--) { s->failed_pc=0x0c073362u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073364;
P_0c073364: /* original 4d0b, guest PC 0x0c073364 */
if(!s->budget--) { s->failed_pc=0x0c073364u; return 0; }
target=r[13];
r[16]=code_base|0x0c073368u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073368u) { target=s->pc; goto dispatch; }
goto P_0c073368;
P_0c073366: /* original 7420, guest PC 0x0c073366 */
if(!s->budget--) { s->failed_pc=0x0c073366u; return 0; }
r[4]+=0x00000020u;
goto P_0c073368;
P_0c073368: /* original 84c3, guest PC 0x0c073368 */
if(!s->budget--) { s->failed_pc=0x0c073368u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c07336a;
P_0c07336a: /* original 64e3, guest PC 0x0c07336a */
if(!s->budget--) { s->failed_pc=0x0c07336au; return 0; }
r[4]=r[14];
goto P_0c07336c;
P_0c07336c: /* original 600c, guest PC 0x0c07336c */
if(!s->budget--) { s->failed_pc=0x0c07336cu; return 0; }
r[0]=r[0]&255u;
goto P_0c07336e;
P_0c07336e: /* original 6503, guest PC 0x0c07336e */
if(!s->budget--) { s->failed_pc=0x0c07336eu; return 0; }
r[5]=r[0];
goto P_0c073370;
P_0c073370: /* original 2f02, guest PC 0x0c073370 */
if(!s->budget--) { s->failed_pc=0x0c073370u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073372;
P_0c073372: /* original 4d0b, guest PC 0x0c073372 */
if(!s->budget--) { s->failed_pc=0x0c073372u; return 0; }
target=r[13];
r[16]=code_base|0x0c073376u;
r[4]+=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073376u) { target=s->pc; goto dispatch; }
goto P_0c073376;
P_0c073374: /* original 7421, guest PC 0x0c073374 */
if(!s->budget--) { s->failed_pc=0x0c073374u; return 0; }
r[4]+=0x00000021u;
goto P_0c073376;
P_0c073376: /* original 7f04, guest PC 0x0c073376 */
if(!s->budget--) { s->failed_pc=0x0c073376u; return 0; }
r[15]+=0x00000004u;
goto P_0c073378;
P_0c073378: /* original 4f26, guest PC 0x0c073378 */
if(!s->budget--) { s->failed_pc=0x0c073378u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07337a;
P_0c07337a: /* original 6cf6, guest PC 0x0c07337a */
if(!s->budget--) { s->failed_pc=0x0c07337au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07337c;
P_0c07337c: /* original 6df6, guest PC 0x0c07337c */
if(!s->budget--) { s->failed_pc=0x0c07337cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07337e;
P_0c07337e: /* original 000b, guest PC 0x0c07337e */
if(!s->budget--) { s->failed_pc=0x0c07337eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c073380: /* original 6ef6, guest PC 0x0c073380 */
if(!s->budget--) { s->failed_pc=0x0c073380u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c073382u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c073382u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
