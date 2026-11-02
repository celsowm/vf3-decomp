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
int vf3_away_batch170_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c08e5c4u: goto P_0c08e5c4;
case 0x0c08e5c6u: goto P_0c08e5c6;
case 0x0c08e5c8u: goto P_0c08e5c8;
case 0x0c08e5cau: goto P_0c08e5ca;
case 0x0c08e5ccu: goto P_0c08e5cc;
case 0x0c08e5ceu: goto P_0c08e5ce;
case 0x0c08e5d0u: goto P_0c08e5d0;
case 0x0c08e5d2u: goto P_0c08e5d2;
case 0x0c08e5d4u: goto P_0c08e5d4;
case 0x0c08e5d6u: goto P_0c08e5d6;
case 0x0c08e5d8u: goto P_0c08e5d8;
case 0x0c08e5dau: goto P_0c08e5da;
case 0x0c08e5dcu: goto P_0c08e5dc;
case 0x0c08e5deu: goto P_0c08e5de;
case 0x0c08e5e0u: goto P_0c08e5e0;
case 0x0c08e5e2u: goto P_0c08e5e2;
case 0x0c08e5e4u: goto P_0c08e5e4;
case 0x0c08e5e6u: goto P_0c08e5e6;
case 0x0c08e5e8u: goto P_0c08e5e8;
case 0x0c08e5eau: goto P_0c08e5ea;
case 0x0c08e5ecu: goto P_0c08e5ec;
case 0x0c08e5eeu: goto P_0c08e5ee;
case 0x0c08e5f0u: goto P_0c08e5f0;
case 0x0c08e5f2u: goto P_0c08e5f2;
case 0x0c08e5f4u: goto P_0c08e5f4;
case 0x0c08e5f6u: goto P_0c08e5f6;
case 0x0c08e5f8u: goto P_0c08e5f8;
case 0x0c08e5fau: goto P_0c08e5fa;
case 0x0c08e5fcu: goto P_0c08e5fc;
case 0x0c08e5feu: goto P_0c08e5fe;
case 0x0c08e600u: goto P_0c08e600;
case 0x0c08e602u: goto P_0c08e602;
case 0x0c08e604u: goto P_0c08e604;
case 0x0c08e606u: goto P_0c08e606;
case 0x0c08e608u: goto P_0c08e608;
case 0x0c08e60au: goto P_0c08e60a;
case 0x0c08e60cu: goto P_0c08e60c;
case 0x0c08e60eu: goto P_0c08e60e;
case 0x0c08e610u: goto P_0c08e610;
case 0x0c08e612u: goto P_0c08e612;
case 0x0c08e614u: goto P_0c08e614;
case 0x0c08e616u: goto P_0c08e616;
case 0x0c08e618u: goto P_0c08e618;
case 0x0c08e61au: goto P_0c08e61a;
case 0x0c08e61cu: goto P_0c08e61c;
case 0x0c08e61eu: goto P_0c08e61e;
case 0x0c08e620u: goto P_0c08e620;
case 0x0c08e622u: goto P_0c08e622;
case 0x0c08e624u: goto P_0c08e624;
case 0x0c08e626u: goto P_0c08e626;
case 0x0c08e628u: goto P_0c08e628;
case 0x0c08e62au: goto P_0c08e62a;
case 0x0c08e62cu: goto P_0c08e62c;
case 0x0c08e62eu: goto P_0c08e62e;
case 0x0c08e630u: goto P_0c08e630;
case 0x0c08e632u: goto P_0c08e632;
case 0x0c08e634u: goto P_0c08e634;
case 0x0c08e636u: goto P_0c08e636;
case 0x0c08e638u: goto P_0c08e638;
case 0x0c08e63au: goto P_0c08e63a;
case 0x0c08e63cu: goto P_0c08e63c;
case 0x0c08e63eu: goto P_0c08e63e;
case 0x0c08e640u: goto P_0c08e640;
case 0x0c08e642u: goto P_0c08e642;
case 0x0c08e644u: goto P_0c08e644;
case 0x0c08e646u: goto P_0c08e646;
case 0x0c08e648u: goto P_0c08e648;
case 0x0c08e64au: goto P_0c08e64a;
case 0x0c08e64cu: goto P_0c08e64c;
case 0x0c08e64eu: goto P_0c08e64e;
case 0x0c08e650u: goto P_0c08e650;
case 0x0c08e652u: goto P_0c08e652;
case 0x0c08e654u: goto P_0c08e654;
case 0x0c08e656u: goto P_0c08e656;
case 0x0c08e658u: goto P_0c08e658;
case 0x0c08e65au: goto P_0c08e65a;
case 0x0c08e65cu: goto P_0c08e65c;
case 0x0c08e65eu: goto P_0c08e65e;
case 0x0c08e660u: goto P_0c08e660;
case 0x0c08e662u: goto P_0c08e662;
case 0x0c08e664u: goto P_0c08e664;
case 0x0c08e666u: goto P_0c08e666;
case 0x0c08e668u: goto P_0c08e668;
case 0x0c08e66au: goto P_0c08e66a;
case 0x0c08e66cu: goto P_0c08e66c;
case 0x0c08e66eu: goto P_0c08e66e;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c08e5c4: /* original 2fe6, guest PC 0x0c08e5c4 */
if(!s->budget--) { s->failed_pc=0x0c08e5c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5c6;
P_0c08e5c6: /* original e503, guest PC 0x0c08e5c6 */
if(!s->budget--) { s->failed_pc=0x0c08e5c6u; return 0; }
r[5]=0x00000003u;
goto P_0c08e5c8;
P_0c08e5c8: /* original 2fd6, guest PC 0x0c08e5c8 */
if(!s->budget--) { s->failed_pc=0x0c08e5c8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5ca;
P_0c08e5ca: /* original 2fc6, guest PC 0x0c08e5ca */
if(!s->budget--) { s->failed_pc=0x0c08e5cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5cc;
P_0c08e5cc: /* original 2fb6, guest PC 0x0c08e5cc */
if(!s->budget--) { s->failed_pc=0x0c08e5ccu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08e5ce;
P_0c08e5ce: /* original 4f22, guest PC 0x0c08e5ce */
if(!s->budget--) { s->failed_pc=0x0c08e5ceu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08e5d0;
P_0c08e5d0: /* original dd2b, guest PC 0x0c08e5d0 */
if(!s->budget--) { s->failed_pc=0x0c08e5d0u; return 0; }
r[13]=read(ram,0x0c08e680u,4);
goto P_0c08e5d2;
P_0c08e5d2: /* original de2a, guest PC 0x0c08e5d2 */
if(!s->budget--) { s->failed_pc=0x0c08e5d2u; return 0; }
r[14]=read(ram,0x0c08e67cu,4);
goto P_0c08e5d4;
P_0c08e5d4: /* original 4d0b, guest PC 0x0c08e5d4 */
if(!s->budget--) { s->failed_pc=0x0c08e5d4u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5d8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5d8u) { target=s->pc; goto dispatch; }
goto P_0c08e5d8;
P_0c08e5d6: /* original 64e3, guest PC 0x0c08e5d6 */
if(!s->budget--) { s->failed_pc=0x0c08e5d6u; return 0; }
r[4]=r[14];
goto P_0c08e5d8;
P_0c08e5d8: /* original 64e3, guest PC 0x0c08e5d8 */
if(!s->budget--) { s->failed_pc=0x0c08e5d8u; return 0; }
r[4]=r[14];
goto P_0c08e5da;
P_0c08e5da: /* original e503, guest PC 0x0c08e5da */
if(!s->budget--) { s->failed_pc=0x0c08e5dau; return 0; }
r[5]=0x00000003u;
goto P_0c08e5dc;
P_0c08e5dc: /* original 4d0b, guest PC 0x0c08e5dc */
if(!s->budget--) { s->failed_pc=0x0c08e5dcu; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5e0u;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5e0u) { target=s->pc; goto dispatch; }
goto P_0c08e5e0;
P_0c08e5de: /* original 7401, guest PC 0x0c08e5de */
if(!s->budget--) { s->failed_pc=0x0c08e5deu; return 0; }
r[4]+=0x00000001u;
goto P_0c08e5e0;
P_0c08e5e0: /* original 64e3, guest PC 0x0c08e5e0 */
if(!s->budget--) { s->failed_pc=0x0c08e5e0u; return 0; }
r[4]=r[14];
goto P_0c08e5e2;
P_0c08e5e2: /* original e501, guest PC 0x0c08e5e2 */
if(!s->budget--) { s->failed_pc=0x0c08e5e2u; return 0; }
r[5]=0x00000001u;
goto P_0c08e5e4;
P_0c08e5e4: /* original 4d0b, guest PC 0x0c08e5e4 */
if(!s->budget--) { s->failed_pc=0x0c08e5e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e5e8u;
r[4]+=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5e8u) { target=s->pc; goto dispatch; }
goto P_0c08e5e8;
P_0c08e5e6: /* original 7402, guest PC 0x0c08e5e6 */
if(!s->budget--) { s->failed_pc=0x0c08e5e6u; return 0; }
r[4]+=0x00000002u;
goto P_0c08e5e8;
P_0c08e5e8: /* original 9b46, guest PC 0x0c08e5e8 */
if(!s->budget--) { s->failed_pc=0x0c08e5e8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08e678u,2);
goto P_0c08e5ea;
P_0c08e5ea: /* original 64e3, guest PC 0x0c08e5ea */
if(!s->budget--) { s->failed_pc=0x0c08e5eau; return 0; }
r[4]=r[14];
goto P_0c08e5ec;
P_0c08e5ec: /* original dc25, guest PC 0x0c08e5ec */
if(!s->budget--) { s->failed_pc=0x0c08e5ecu; return 0; }
r[12]=read(ram,0x0c08e684u,4);
goto P_0c08e5ee;
P_0c08e5ee: /* original 65b3, guest PC 0x0c08e5ee */
if(!s->budget--) { s->failed_pc=0x0c08e5eeu; return 0; }
r[5]=r[11];
goto P_0c08e5f0;
P_0c08e5f0: /* original 4c0b, guest PC 0x0c08e5f0 */
if(!s->budget--) { s->failed_pc=0x0c08e5f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e5f4u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5f4u) { target=s->pc; goto dispatch; }
goto P_0c08e5f4;
P_0c08e5f2: /* original 7404, guest PC 0x0c08e5f2 */
if(!s->budget--) { s->failed_pc=0x0c08e5f2u; return 0; }
r[4]+=0x00000004u;
goto P_0c08e5f4;
P_0c08e5f4: /* original 64e3, guest PC 0x0c08e5f4 */
if(!s->budget--) { s->failed_pc=0x0c08e5f4u; return 0; }
r[4]=r[14];
goto P_0c08e5f6;
P_0c08e5f6: /* original 65b3, guest PC 0x0c08e5f6 */
if(!s->budget--) { s->failed_pc=0x0c08e5f6u; return 0; }
r[5]=r[11];
goto P_0c08e5f8;
P_0c08e5f8: /* original 4c0b, guest PC 0x0c08e5f8 */
if(!s->budget--) { s->failed_pc=0x0c08e5f8u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e5fcu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e5fcu) { target=s->pc; goto dispatch; }
goto P_0c08e5fc;
P_0c08e5fa: /* original 7408, guest PC 0x0c08e5fa */
if(!s->budget--) { s->failed_pc=0x0c08e5fau; return 0; }
r[4]+=0x00000008u;
goto P_0c08e5fc;
P_0c08e5fc: /* original 64e3, guest PC 0x0c08e5fc */
if(!s->budget--) { s->failed_pc=0x0c08e5fcu; return 0; }
r[4]=r[14];
goto P_0c08e5fe;
P_0c08e5fe: /* original 65b3, guest PC 0x0c08e5fe */
if(!s->budget--) { s->failed_pc=0x0c08e5feu; return 0; }
r[5]=r[11];
goto P_0c08e600;
P_0c08e600: /* original 4c0b, guest PC 0x0c08e600 */
if(!s->budget--) { s->failed_pc=0x0c08e600u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e604u;
r[4]+=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e604u) { target=s->pc; goto dispatch; }
goto P_0c08e604;
P_0c08e602: /* original 7406, guest PC 0x0c08e602 */
if(!s->budget--) { s->failed_pc=0x0c08e602u; return 0; }
r[4]+=0x00000006u;
goto P_0c08e604;
P_0c08e604: /* original 64e3, guest PC 0x0c08e604 */
if(!s->budget--) { s->failed_pc=0x0c08e604u; return 0; }
r[4]=r[14];
goto P_0c08e606;
P_0c08e606: /* original e501, guest PC 0x0c08e606 */
if(!s->budget--) { s->failed_pc=0x0c08e606u; return 0; }
r[5]=0x00000001u;
goto P_0c08e608;
P_0c08e608: /* original 4c0b, guest PC 0x0c08e608 */
if(!s->budget--) { s->failed_pc=0x0c08e608u; return 0; }
target=r[12];
r[16]=code_base|0x0c08e60cu;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e60cu) { target=s->pc; goto dispatch; }
goto P_0c08e60c;
P_0c08e60a: /* original 740a, guest PC 0x0c08e60a */
if(!s->budget--) { s->failed_pc=0x0c08e60au; return 0; }
r[4]+=0x0000000au;
goto P_0c08e60c;
P_0c08e60c: /* original 64e3, guest PC 0x0c08e60c */
if(!s->budget--) { s->failed_pc=0x0c08e60cu; return 0; }
r[4]=r[14];
goto P_0c08e60e;
P_0c08e60e: /* original e500, guest PC 0x0c08e60e */
if(!s->budget--) { s->failed_pc=0x0c08e60eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e610;
P_0c08e610: /* original 4d0b, guest PC 0x0c08e610 */
if(!s->budget--) { s->failed_pc=0x0c08e610u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e614u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e614u) { target=s->pc; goto dispatch; }
goto P_0c08e614;
P_0c08e612: /* original 7403, guest PC 0x0c08e612 */
if(!s->budget--) { s->failed_pc=0x0c08e612u; return 0; }
r[4]+=0x00000003u;
goto P_0c08e614;
P_0c08e614: /* original 64e3, guest PC 0x0c08e614 */
if(!s->budget--) { s->failed_pc=0x0c08e614u; return 0; }
r[4]=r[14];
goto P_0c08e616;
P_0c08e616: /* original e500, guest PC 0x0c08e616 */
if(!s->budget--) { s->failed_pc=0x0c08e616u; return 0; }
r[5]=0x00000000u;
goto P_0c08e618;
P_0c08e618: /* original 4d0b, guest PC 0x0c08e618 */
if(!s->budget--) { s->failed_pc=0x0c08e618u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e61cu;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e61cu) { target=s->pc; goto dispatch; }
goto P_0c08e61c;
P_0c08e61a: /* original 740c, guest PC 0x0c08e61a */
if(!s->budget--) { s->failed_pc=0x0c08e61au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08e61c;
P_0c08e61c: /* original 64e3, guest PC 0x0c08e61c */
if(!s->budget--) { s->failed_pc=0x0c08e61cu; return 0; }
r[4]=r[14];
goto P_0c08e61e;
P_0c08e61e: /* original e500, guest PC 0x0c08e61e */
if(!s->budget--) { s->failed_pc=0x0c08e61eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e620;
P_0c08e620: /* original 4d0b, guest PC 0x0c08e620 */
if(!s->budget--) { s->failed_pc=0x0c08e620u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e624u;
r[4]+=0x0000000eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e624u) { target=s->pc; goto dispatch; }
goto P_0c08e624;
P_0c08e622: /* original 740e, guest PC 0x0c08e622 */
if(!s->budget--) { s->failed_pc=0x0c08e622u; return 0; }
r[4]+=0x0000000eu;
goto P_0c08e624;
P_0c08e624: /* original 64e3, guest PC 0x0c08e624 */
if(!s->budget--) { s->failed_pc=0x0c08e624u; return 0; }
r[4]=r[14];
goto P_0c08e626;
P_0c08e626: /* original e500, guest PC 0x0c08e626 */
if(!s->budget--) { s->failed_pc=0x0c08e626u; return 0; }
r[5]=0x00000000u;
goto P_0c08e628;
P_0c08e628: /* original 4d0b, guest PC 0x0c08e628 */
if(!s->budget--) { s->failed_pc=0x0c08e628u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e62cu;
r[4]+=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e62cu) { target=s->pc; goto dispatch; }
goto P_0c08e62c;
P_0c08e62a: /* original 740f, guest PC 0x0c08e62a */
if(!s->budget--) { s->failed_pc=0x0c08e62au; return 0; }
r[4]+=0x0000000fu;
goto P_0c08e62c;
P_0c08e62c: /* original 64e3, guest PC 0x0c08e62c */
if(!s->budget--) { s->failed_pc=0x0c08e62cu; return 0; }
r[4]=r[14];
goto P_0c08e62e;
P_0c08e62e: /* original e501, guest PC 0x0c08e62e */
if(!s->budget--) { s->failed_pc=0x0c08e62eu; return 0; }
r[5]=0x00000001u;
goto P_0c08e630;
P_0c08e630: /* original 4d0b, guest PC 0x0c08e630 */
if(!s->budget--) { s->failed_pc=0x0c08e630u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e634u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e634u) { target=s->pc; goto dispatch; }
goto P_0c08e634;
P_0c08e632: /* original 7410, guest PC 0x0c08e632 */
if(!s->budget--) { s->failed_pc=0x0c08e632u; return 0; }
r[4]+=0x00000010u;
goto P_0c08e634;
P_0c08e634: /* original 64e3, guest PC 0x0c08e634 */
if(!s->budget--) { s->failed_pc=0x0c08e634u; return 0; }
r[4]=r[14];
goto P_0c08e636;
P_0c08e636: /* original e500, guest PC 0x0c08e636 */
if(!s->budget--) { s->failed_pc=0x0c08e636u; return 0; }
r[5]=0x00000000u;
goto P_0c08e638;
P_0c08e638: /* original 4d0b, guest PC 0x0c08e638 */
if(!s->budget--) { s->failed_pc=0x0c08e638u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e63cu;
r[4]+=0x00000011u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e63cu) { target=s->pc; goto dispatch; }
goto P_0c08e63c;
P_0c08e63a: /* original 7411, guest PC 0x0c08e63a */
if(!s->budget--) { s->failed_pc=0x0c08e63au; return 0; }
r[4]+=0x00000011u;
goto P_0c08e63c;
P_0c08e63c: /* original 64e3, guest PC 0x0c08e63c */
if(!s->budget--) { s->failed_pc=0x0c08e63cu; return 0; }
r[4]=r[14];
goto P_0c08e63e;
P_0c08e63e: /* original e501, guest PC 0x0c08e63e */
if(!s->budget--) { s->failed_pc=0x0c08e63eu; return 0; }
r[5]=0x00000001u;
goto P_0c08e640;
P_0c08e640: /* original 4d0b, guest PC 0x0c08e640 */
if(!s->budget--) { s->failed_pc=0x0c08e640u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e644u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e644u) { target=s->pc; goto dispatch; }
goto P_0c08e644;
P_0c08e642: /* original 7412, guest PC 0x0c08e642 */
if(!s->budget--) { s->failed_pc=0x0c08e642u; return 0; }
r[4]+=0x00000012u;
goto P_0c08e644;
P_0c08e644: /* original 64e3, guest PC 0x0c08e644 */
if(!s->budget--) { s->failed_pc=0x0c08e644u; return 0; }
r[4]=r[14];
goto P_0c08e646;
P_0c08e646: /* original e500, guest PC 0x0c08e646 */
if(!s->budget--) { s->failed_pc=0x0c08e646u; return 0; }
r[5]=0x00000000u;
goto P_0c08e648;
P_0c08e648: /* original 4d0b, guest PC 0x0c08e648 */
if(!s->budget--) { s->failed_pc=0x0c08e648u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e64cu;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e64cu) { target=s->pc; goto dispatch; }
goto P_0c08e64c;
P_0c08e64a: /* original 7413, guest PC 0x0c08e64a */
if(!s->budget--) { s->failed_pc=0x0c08e64au; return 0; }
r[4]+=0x00000013u;
goto P_0c08e64c;
P_0c08e64c: /* original 64e3, guest PC 0x0c08e64c */
if(!s->budget--) { s->failed_pc=0x0c08e64cu; return 0; }
r[4]=r[14];
goto P_0c08e64e;
P_0c08e64e: /* original e500, guest PC 0x0c08e64e */
if(!s->budget--) { s->failed_pc=0x0c08e64eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e650;
P_0c08e650: /* original 4d0b, guest PC 0x0c08e650 */
if(!s->budget--) { s->failed_pc=0x0c08e650u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e654u;
r[4]+=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e654u) { target=s->pc; goto dispatch; }
goto P_0c08e654;
P_0c08e652: /* original 7415, guest PC 0x0c08e652 */
if(!s->budget--) { s->failed_pc=0x0c08e652u; return 0; }
r[4]+=0x00000015u;
goto P_0c08e654;
P_0c08e654: /* original 64e3, guest PC 0x0c08e654 */
if(!s->budget--) { s->failed_pc=0x0c08e654u; return 0; }
r[4]=r[14];
goto P_0c08e656;
P_0c08e656: /* original e500, guest PC 0x0c08e656 */
if(!s->budget--) { s->failed_pc=0x0c08e656u; return 0; }
r[5]=0x00000000u;
goto P_0c08e658;
P_0c08e658: /* original 4d0b, guest PC 0x0c08e658 */
if(!s->budget--) { s->failed_pc=0x0c08e658u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e65cu;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e65cu) { target=s->pc; goto dispatch; }
goto P_0c08e65c;
P_0c08e65a: /* original 7414, guest PC 0x0c08e65a */
if(!s->budget--) { s->failed_pc=0x0c08e65au; return 0; }
r[4]+=0x00000014u;
goto P_0c08e65c;
P_0c08e65c: /* original 64e3, guest PC 0x0c08e65c */
if(!s->budget--) { s->failed_pc=0x0c08e65cu; return 0; }
r[4]=r[14];
goto P_0c08e65e;
P_0c08e65e: /* original e500, guest PC 0x0c08e65e */
if(!s->budget--) { s->failed_pc=0x0c08e65eu; return 0; }
r[5]=0x00000000u;
goto P_0c08e660;
P_0c08e660: /* original 4d0b, guest PC 0x0c08e660 */
if(!s->budget--) { s->failed_pc=0x0c08e660u; return 0; }
target=r[13];
r[16]=code_base|0x0c08e664u;
r[4]+=0x00000016u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08e664u) { target=s->pc; goto dispatch; }
goto P_0c08e664;
P_0c08e662: /* original 7416, guest PC 0x0c08e662 */
if(!s->budget--) { s->failed_pc=0x0c08e662u; return 0; }
r[4]+=0x00000016u;
goto P_0c08e664;
P_0c08e664: /* original 4f26, guest PC 0x0c08e664 */
if(!s->budget--) { s->failed_pc=0x0c08e664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08e666;
P_0c08e666: /* original 6bf6, guest PC 0x0c08e666 */
if(!s->budget--) { s->failed_pc=0x0c08e666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08e668;
P_0c08e668: /* original 6cf6, guest PC 0x0c08e668 */
if(!s->budget--) { s->failed_pc=0x0c08e668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08e66a;
P_0c08e66a: /* original 6df6, guest PC 0x0c08e66a */
if(!s->budget--) { s->failed_pc=0x0c08e66au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08e66c;
P_0c08e66c: /* original 000b, guest PC 0x0c08e66c */
if(!s->budget--) { s->failed_pc=0x0c08e66cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08e66e: /* original 6ef6, guest PC 0x0c08e66e */
if(!s->budget--) { s->failed_pc=0x0c08e66eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08e670u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08e670u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
