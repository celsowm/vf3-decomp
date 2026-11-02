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
int vf3_away_batch5_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04ef8cu: goto P_0c04ef8c;
case 0x0c04ef8eu: goto P_0c04ef8e;
case 0x0c04ef90u: goto P_0c04ef90;
case 0x0c04ef92u: goto P_0c04ef92;
case 0x0c04ef94u: goto P_0c04ef94;
case 0x0c04ef96u: goto P_0c04ef96;
case 0x0c04ef98u: goto P_0c04ef98;
case 0x0c04ef9au: goto P_0c04ef9a;
case 0x0c04ef9cu: goto P_0c04ef9c;
case 0x0c04ef9eu: goto P_0c04ef9e;
case 0x0c04efa0u: goto P_0c04efa0;
case 0x0c04efa2u: goto P_0c04efa2;
case 0x0c04efa4u: goto P_0c04efa4;
case 0x0c04efa6u: goto P_0c04efa6;
case 0x0c04efa8u: goto P_0c04efa8;
case 0x0c04efaau: goto P_0c04efaa;
case 0x0c04efacu: goto P_0c04efac;
case 0x0c04efaeu: goto P_0c04efae;
case 0x0c04efb0u: goto P_0c04efb0;
case 0x0c04efb2u: goto P_0c04efb2;
case 0x0c04efb4u: goto P_0c04efb4;
case 0x0c04efb6u: goto P_0c04efb6;
case 0x0c04efb8u: goto P_0c04efb8;
case 0x0c04efbau: goto P_0c04efba;
case 0x0c04efbcu: goto P_0c04efbc;
case 0x0c04efbeu: goto P_0c04efbe;
case 0x0c04efc0u: goto P_0c04efc0;
case 0x0c04efc2u: goto P_0c04efc2;
case 0x0c04efc4u: goto P_0c04efc4;
case 0x0c04efc6u: goto P_0c04efc6;
case 0x0c04efc8u: goto P_0c04efc8;
case 0x0c04efcau: goto P_0c04efca;
case 0x0c04efccu: goto P_0c04efcc;
case 0x0c04efceu: goto P_0c04efce;
case 0x0c04efd0u: goto P_0c04efd0;
case 0x0c04efd2u: goto P_0c04efd2;
case 0x0c04efd4u: goto P_0c04efd4;
case 0x0c04efd6u: goto P_0c04efd6;
case 0x0c04efd8u: goto P_0c04efd8;
case 0x0c04efdau: goto P_0c04efda;
case 0x0c04efdcu: goto P_0c04efdc;
case 0x0c04efdeu: goto P_0c04efde;
case 0x0c04efe0u: goto P_0c04efe0;
case 0x0c04efe2u: goto P_0c04efe2;
case 0x0c04efe4u: goto P_0c04efe4;
case 0x0c04efe6u: goto P_0c04efe6;
case 0x0c04efe8u: goto P_0c04efe8;
case 0x0c04efeau: goto P_0c04efea;
case 0x0c04efecu: goto P_0c04efec;
case 0x0c04efeeu: goto P_0c04efee;
case 0x0c04eff0u: goto P_0c04eff0;
case 0x0c04eff2u: goto P_0c04eff2;
case 0x0c04eff4u: goto P_0c04eff4;
case 0x0c04eff6u: goto P_0c04eff6;
case 0x0c04eff8u: goto P_0c04eff8;
case 0x0c04effau: goto P_0c04effa;
case 0x0c04effcu: goto P_0c04effc;
case 0x0c04effeu: goto P_0c04effe;
case 0x0c04f000u: goto P_0c04f000;
case 0x0c04f002u: goto P_0c04f002;
case 0x0c04f004u: goto P_0c04f004;
case 0x0c04f006u: goto P_0c04f006;
case 0x0c04f008u: goto P_0c04f008;
case 0x0c04f00au: goto P_0c04f00a;
case 0x0c04f00cu: goto P_0c04f00c;
case 0x0c04f00eu: goto P_0c04f00e;
case 0x0c04f010u: goto P_0c04f010;
case 0x0c04f012u: goto P_0c04f012;
case 0x0c04f014u: goto P_0c04f014;
case 0x0c04f016u: goto P_0c04f016;
case 0x0c04f018u: goto P_0c04f018;
case 0x0c04f01au: goto P_0c04f01a;
case 0x0c04f01cu: goto P_0c04f01c;
case 0x0c04f01eu: goto P_0c04f01e;
case 0x0c04f020u: goto P_0c04f020;
case 0x0c04f022u: goto P_0c04f022;
case 0x0c04f024u: goto P_0c04f024;
case 0x0c04f026u: goto P_0c04f026;
case 0x0c04f028u: goto P_0c04f028;
case 0x0c04f050u: goto P_0c04f050;
case 0x0c04f052u: goto P_0c04f052;
case 0x0c04f054u: goto P_0c04f054;
case 0x0c04f056u: goto P_0c04f056;
case 0x0c04f058u: goto P_0c04f058;
case 0x0c04f05au: goto P_0c04f05a;
case 0x0c04f05cu: goto P_0c04f05c;
case 0x0c04f05eu: goto P_0c04f05e;
case 0x0c04f060u: goto P_0c04f060;
case 0x0c04f062u: goto P_0c04f062;
case 0x0c04f064u: goto P_0c04f064;
case 0x0c04f066u: goto P_0c04f066;
case 0x0c04f068u: goto P_0c04f068;
case 0x0c04f06au: goto P_0c04f06a;
case 0x0c04f06cu: goto P_0c04f06c;
case 0x0c04f06eu: goto P_0c04f06e;
case 0x0c04f070u: goto P_0c04f070;
case 0x0c04f072u: goto P_0c04f072;
case 0x0c04f074u: goto P_0c04f074;
case 0x0c04f076u: goto P_0c04f076;
case 0x0c04f078u: goto P_0c04f078;
case 0x0c04f07au: goto P_0c04f07a;
case 0x0c04f07cu: goto P_0c04f07c;
case 0x0c04f07eu: goto P_0c04f07e;
case 0x0c04f080u: goto P_0c04f080;
case 0x0c04f082u: goto P_0c04f082;
case 0x0c04f084u: goto P_0c04f084;
case 0x0c04f086u: goto P_0c04f086;
case 0x0c04f088u: goto P_0c04f088;
case 0x0c04f08au: goto P_0c04f08a;
case 0x0c04f08cu: goto P_0c04f08c;
case 0x0c04f08eu: goto P_0c04f08e;
case 0x0c04f090u: goto P_0c04f090;
case 0x0c04f092u: goto P_0c04f092;
case 0x0c04f094u: goto P_0c04f094;
case 0x0c04f096u: goto P_0c04f096;
case 0x0c04f098u: goto P_0c04f098;
case 0x0c04f09au: goto P_0c04f09a;
case 0x0c04f09cu: goto P_0c04f09c;
case 0x0c04f09eu: goto P_0c04f09e;
case 0x0c04f0a0u: goto P_0c04f0a0;
case 0x0c04f0a2u: goto P_0c04f0a2;
case 0x0c04f0a4u: goto P_0c04f0a4;
case 0x0c04f0a6u: goto P_0c04f0a6;
case 0x0c04f0a8u: goto P_0c04f0a8;
case 0x0c04f0aau: goto P_0c04f0aa;
case 0x0c04f0acu: goto P_0c04f0ac;
case 0x0c04f0aeu: goto P_0c04f0ae;
case 0x0c04f0b0u: goto P_0c04f0b0;
case 0x0c04f0b2u: goto P_0c04f0b2;
case 0x0c04f0b4u: goto P_0c04f0b4;
case 0x0c04f0b6u: goto P_0c04f0b6;
case 0x0c04f0b8u: goto P_0c04f0b8;
case 0x0c04f0bau: goto P_0c04f0ba;
case 0x0c04f0bcu: goto P_0c04f0bc;
case 0x0c04f0beu: goto P_0c04f0be;
case 0x0c04f0c0u: goto P_0c04f0c0;
case 0x0c04f0c2u: goto P_0c04f0c2;
case 0x0c04f0c4u: goto P_0c04f0c4;
case 0x0c04f0c6u: goto P_0c04f0c6;
case 0x0c04f0c8u: goto P_0c04f0c8;
case 0x0c04f0cau: goto P_0c04f0ca;
case 0x0c04f0ccu: goto P_0c04f0cc;
case 0x0c04f0ceu: goto P_0c04f0ce;
case 0x0c04f0d0u: goto P_0c04f0d0;
case 0x0c04f0d2u: goto P_0c04f0d2;
case 0x0c04f0d4u: goto P_0c04f0d4;
case 0x0c04f0d6u: goto P_0c04f0d6;
case 0x0c04f0d8u: goto P_0c04f0d8;
case 0x0c04f0dau: goto P_0c04f0da;
case 0x0c04f0dcu: goto P_0c04f0dc;
case 0x0c04f250u: goto P_0c04f250;
case 0x0c04f252u: goto P_0c04f252;
case 0x0c04f254u: goto P_0c04f254;
case 0x0c04f256u: goto P_0c04f256;
case 0x0c04f258u: goto P_0c04f258;
case 0x0c04f25au: goto P_0c04f25a;
case 0x0c04f25cu: goto P_0c04f25c;
case 0x0c04f25eu: goto P_0c04f25e;
case 0x0c04f260u: goto P_0c04f260;
case 0x0c04f262u: goto P_0c04f262;
case 0x0c04f264u: goto P_0c04f264;
case 0x0c04f266u: goto P_0c04f266;
case 0x0c04f268u: goto P_0c04f268;
case 0x0c04f26au: goto P_0c04f26a;
case 0x0c04f26cu: goto P_0c04f26c;
case 0x0c04f26eu: goto P_0c04f26e;
case 0x0c04f270u: goto P_0c04f270;
case 0x0c04f272u: goto P_0c04f272;
case 0x0c04f274u: goto P_0c04f274;
case 0x0c04f276u: goto P_0c04f276;
case 0x0c04f278u: goto P_0c04f278;
case 0x0c04f27au: goto P_0c04f27a;
case 0x0c04f27cu: goto P_0c04f27c;
case 0x0c04f27eu: goto P_0c04f27e;
case 0x0c04f280u: goto P_0c04f280;
case 0x0c04f282u: goto P_0c04f282;
case 0x0c04f284u: goto P_0c04f284;
case 0x0c04f286u: goto P_0c04f286;
case 0x0c04f288u: goto P_0c04f288;
case 0x0c04f28au: goto P_0c04f28a;
case 0x0c04f28cu: goto P_0c04f28c;
case 0x0c04f28eu: goto P_0c04f28e;
case 0x0c04f290u: goto P_0c04f290;
case 0x0c04f292u: goto P_0c04f292;
case 0x0c04f294u: goto P_0c04f294;
case 0x0c04f296u: goto P_0c04f296;
case 0x0c04f298u: goto P_0c04f298;
case 0x0c04f29au: goto P_0c04f29a;
case 0x0c04f29cu: goto P_0c04f29c;
case 0x0c04f29eu: goto P_0c04f29e;
case 0x0c04f2a0u: goto P_0c04f2a0;
case 0x0c04f2a2u: goto P_0c04f2a2;
case 0x0c04f2a4u: goto P_0c04f2a4;
case 0x0c04f2a6u: goto P_0c04f2a6;
case 0x0c04f2a8u: goto P_0c04f2a8;
case 0x0c04f2aau: goto P_0c04f2aa;
case 0x0c04f2acu: goto P_0c04f2ac;
case 0x0c04f2aeu: goto P_0c04f2ae;
case 0x0c04f2b0u: goto P_0c04f2b0;
case 0x0c04f2b2u: goto P_0c04f2b2;
case 0x0c04f2b4u: goto P_0c04f2b4;
case 0x0c04f2b6u: goto P_0c04f2b6;
case 0x0c04f2b8u: goto P_0c04f2b8;
case 0x0c04f2bau: goto P_0c04f2ba;
case 0x0c04f2bcu: goto P_0c04f2bc;
case 0x0c04f2beu: goto P_0c04f2be;
case 0x0c04f2c0u: goto P_0c04f2c0;
case 0x0c04f2c2u: goto P_0c04f2c2;
case 0x0c04f2c4u: goto P_0c04f2c4;
case 0x0c04f2c6u: goto P_0c04f2c6;
case 0x0c04f2c8u: goto P_0c04f2c8;
case 0x0c04f2cau: goto P_0c04f2ca;
case 0x0c04f2ccu: goto P_0c04f2cc;
case 0x0c04f2ceu: goto P_0c04f2ce;
case 0x0c04f2d0u: goto P_0c04f2d0;
case 0x0c04f2d2u: goto P_0c04f2d2;
case 0x0c04f2d4u: goto P_0c04f2d4;
case 0x0c04f2d6u: goto P_0c04f2d6;
case 0x0c04f2d8u: goto P_0c04f2d8;
case 0x0c04f2dau: goto P_0c04f2da;
case 0x0c04f2dcu: goto P_0c04f2dc;
case 0x0c04f2deu: goto P_0c04f2de;
case 0x0c04f2e0u: goto P_0c04f2e0;
case 0x0c04f2e2u: goto P_0c04f2e2;
case 0x0c04f2e4u: goto P_0c04f2e4;
case 0x0c04f2e6u: goto P_0c04f2e6;
case 0x0c04f2e8u: goto P_0c04f2e8;
case 0x0c04f2eau: goto P_0c04f2ea;
case 0x0c04f2ecu: goto P_0c04f2ec;
case 0x0c04f2eeu: goto P_0c04f2ee;
case 0x0c04f2f0u: goto P_0c04f2f0;
case 0x0c04f2f2u: goto P_0c04f2f2;
case 0x0c04f2f4u: goto P_0c04f2f4;
case 0x0c04f2f6u: goto P_0c04f2f6;
case 0x0c04f2f8u: goto P_0c04f2f8;
case 0x0c04f2fau: goto P_0c04f2fa;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04ef8c: /* original 2fe6, guest PC 0x0c04ef8c */
if(!s->budget--) { s->failed_pc=0x0c04ef8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ef8e;
P_0c04ef8e: /* original 6e43, guest PC 0x0c04ef8e */
if(!s->budget--) { s->failed_pc=0x0c04ef8eu; return 0; }
r[14]=r[4];
goto P_0c04ef90;
P_0c04ef90: /* original 2fd6, guest PC 0x0c04ef90 */
if(!s->budget--) { s->failed_pc=0x0c04ef90u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ef92;
P_0c04ef92: /* original 4f22, guest PC 0x0c04ef92 */
if(!s->budget--) { s->failed_pc=0x0c04ef92u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ef94;
P_0c04ef94: /* original 934c, guest PC 0x0c04ef94 */
if(!s->budget--) { s->failed_pc=0x0c04ef94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f030u,2);
goto P_0c04ef96;
P_0c04ef96: /* original d029, guest PC 0x0c04ef96 */
if(!s->budget--) { s->failed_pc=0x0c04ef96u; return 0; }
r[0]=read(ram,0x0c04f03cu,4);
goto P_0c04ef98;
P_0c04ef98: /* original 4f12, guest PC 0x0c04ef98 */
if(!s->budget--) { s->failed_pc=0x0c04ef98u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ef9a;
P_0c04ef9a: /* original 2e3f, guest PC 0x0c04ef9a */
if(!s->budget--) { s->failed_pc=0x0c04ef9au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04ef9c;
P_0c04ef9c: /* original 7fd4, guest PC 0x0c04ef9c */
if(!s->budget--) { s->failed_pc=0x0c04ef9cu; return 0; }
r[15]+=0xffffffd4u;
goto P_0c04ef9e;
P_0c04ef9e: /* original 031a, guest PC 0x0c04ef9e */
if(!s->budget--) { s->failed_pc=0x0c04ef9eu; return 0; }
r[3]=r[19];
goto P_0c04efa0;
P_0c04efa0: /* original 633f, guest PC 0x0c04efa0 */
if(!s->budget--) { s->failed_pc=0x0c04efa0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04efa2;
P_0c04efa2: /* original 023c, guest PC 0x0c04efa2 */
if(!s->budget--) { s->failed_pc=0x0c04efa2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04efa4;
P_0c04efa4: /* original 2228, guest PC 0x0c04efa4 */
if(!s->budget--) { s->failed_pc=0x0c04efa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04efa6;
P_0c04efa6: /* original 8d17, guest PC 0x0c04efa6 */
if(!s->budget--) { s->failed_pc=0x0c04efa6u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c04efd8; }
goto P_0c04efaa;
P_0c04efa8: /* original 6d53, guest PC 0x0c04efa8 */
if(!s->budget--) { s->failed_pc=0x0c04efa8u; return 0; }
r[13]=r[5];
goto P_0c04efaa;
P_0c04efaa: /* original d325, guest PC 0x0c04efaa */
if(!s->budget--) { s->failed_pc=0x0c04efaau; return 0; }
r[3]=read(ram,0x0c04f040u,4);
goto P_0c04efac;
P_0c04efac: /* original 430b, guest PC 0x0c04efac */
if(!s->budget--) { s->failed_pc=0x0c04efacu; return 0; }
target=r[3];
r[16]=code_base|0x0c04efb0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04efb0u) { target=s->pc; goto dispatch; }
goto P_0c04efb0;
P_0c04efae: /* original 64e3, guest PC 0x0c04efae */
if(!s->budget--) { s->failed_pc=0x0c04efaeu; return 0; }
r[4]=r[14];
goto P_0c04efb0;
P_0c04efb0: /* original 2008, guest PC 0x0c04efb0 */
if(!s->budget--) { s->failed_pc=0x0c04efb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04efb2;
P_0c04efb2: /* original 8b04, guest PC 0x0c04efb2 */
if(!s->budget--) { s->failed_pc=0x0c04efb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04efbe; }
goto P_0c04efb4;
P_0c04efb4: /* original d323, guest PC 0x0c04efb4 */
if(!s->budget--) { s->failed_pc=0x0c04efb4u; return 0; }
r[3]=read(ram,0x0c04f044u,4);
goto P_0c04efb6;
P_0c04efb6: /* original 430b, guest PC 0x0c04efb6 */
if(!s->budget--) { s->failed_pc=0x0c04efb6u; return 0; }
target=r[3];
r[16]=code_base|0x0c04efbau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04efbau) { target=s->pc; goto dispatch; }
goto P_0c04efba;
P_0c04efb8: /* original 64e3, guest PC 0x0c04efb8 */
if(!s->budget--) { s->failed_pc=0x0c04efb8u; return 0; }
r[4]=r[14];
goto P_0c04efba;
P_0c04efba: /* original a00d, guest PC 0x0c04efba */
if(!s->budget--) { s->failed_pc=0x0c04efbau; return 0; }
goto P_0c04efd8;
P_0c04efbc: /* original 0009, guest PC 0x0c04efbc */
if(!s->budget--) { s->failed_pc=0x0c04efbcu; return 0; }
goto P_0c04efbe;
P_0c04efbe: /* original d222, guest PC 0x0c04efbe */
if(!s->budget--) { s->failed_pc=0x0c04efbeu; return 0; }
r[2]=read(ram,0x0c04f048u,4);
goto P_0c04efc0;
P_0c04efc0: /* original 420b, guest PC 0x0c04efc0 */
if(!s->budget--) { s->failed_pc=0x0c04efc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c04efc4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04efc4u) { target=s->pc; goto dispatch; }
goto P_0c04efc4;
P_0c04efc2: /* original 64e3, guest PC 0x0c04efc2 */
if(!s->budget--) { s->failed_pc=0x0c04efc2u; return 0; }
r[4]=r[14];
goto P_0c04efc4;
P_0c04efc4: /* original 2008, guest PC 0x0c04efc4 */
if(!s->budget--) { s->failed_pc=0x0c04efc4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04efc6;
P_0c04efc6: /* original 8907, guest PC 0x0c04efc6 */
if(!s->budget--) { s->failed_pc=0x0c04efc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04efd8; }
goto P_0c04efc8;
P_0c04efc8: /* original 9332, guest PC 0x0c04efc8 */
if(!s->budget--) { s->failed_pc=0x0c04efc8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f030u,2);
goto P_0c04efca;
P_0c04efca: /* original d020, guest PC 0x0c04efca */
if(!s->budget--) { s->failed_pc=0x0c04efcau; return 0; }
r[0]=read(ram,0x0c04f04cu,4);
goto P_0c04efcc;
P_0c04efcc: /* original 2e3f, guest PC 0x0c04efcc */
if(!s->budget--) { s->failed_pc=0x0c04efccu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04efce;
P_0c04efce: /* original 031a, guest PC 0x0c04efce */
if(!s->budget--) { s->failed_pc=0x0c04efceu; return 0; }
r[3]=r[19];
goto P_0c04efd0;
P_0c04efd0: /* original 633f, guest PC 0x0c04efd0 */
if(!s->budget--) { s->failed_pc=0x0c04efd0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04efd2;
P_0c04efd2: /* original 023c, guest PC 0x0c04efd2 */
if(!s->budget--) { s->failed_pc=0x0c04efd2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04efd4;
P_0c04efd4: /* original 2228, guest PC 0x0c04efd4 */
if(!s->budget--) { s->failed_pc=0x0c04efd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04efd6;
P_0c04efd6: /* original 8b02, guest PC 0x0c04efd6 */
if(!s->budget--) { s->failed_pc=0x0c04efd6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04efde; }
goto P_0c04efd8;
P_0c04efd8: /* original 902b, guest PC 0x0c04efd8 */
if(!s->budget--) { s->failed_pc=0x0c04efd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f032u,2);
goto P_0c04efda;
P_0c04efda: /* original a020, guest PC 0x0c04efda */
if(!s->budget--) { s->failed_pc=0x0c04efdau; return 0; }
goto P_0c04f01e;
P_0c04efdc: /* original 0009, guest PC 0x0c04efdc */
if(!s->budget--) { s->failed_pc=0x0c04efdcu; return 0; }
goto P_0c04efde;
P_0c04efde: /* original d315, guest PC 0x0c04efde */
if(!s->budget--) { s->failed_pc=0x0c04efdeu; return 0; }
r[3]=read(ram,0x0c04f034u,4);
goto P_0c04efe0;
P_0c04efe0: /* original 430b, guest PC 0x0c04efe0 */
if(!s->budget--) { s->failed_pc=0x0c04efe0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04efe4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04efe4u) { target=s->pc; goto dispatch; }
goto P_0c04efe4;
P_0c04efe2: /* original 64e3, guest PC 0x0c04efe2 */
if(!s->budget--) { s->failed_pc=0x0c04efe2u; return 0; }
r[4]=r[14];
goto P_0c04efe4;
P_0c04efe4: /* original 4011, guest PC 0x0c04efe4 */
if(!s->budget--) { s->failed_pc=0x0c04efe4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04efe6;
P_0c04efe6: /* original 8902, guest PC 0x0c04efe6 */
if(!s->budget--) { s->failed_pc=0x0c04efe6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04efee; }
goto P_0c04efe8;
P_0c04efe8: /* original 901f, guest PC 0x0c04efe8 */
if(!s->budget--) { s->failed_pc=0x0c04efe8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f02au,2);
goto P_0c04efea;
P_0c04efea: /* original a018, guest PC 0x0c04efea */
if(!s->budget--) { s->failed_pc=0x0c04efeau; return 0; }
goto P_0c04f01e;
P_0c04efec: /* original 0009, guest PC 0x0c04efec */
if(!s->budget--) { s->failed_pc=0x0c04efecu; return 0; }
goto P_0c04efee;
P_0c04efee: /* original 65f3, guest PC 0x0c04efee */
if(!s->budget--) { s->failed_pc=0x0c04efeeu; return 0; }
r[5]=r[15];
goto P_0c04eff0;
P_0c04eff0: /* original b522, guest PC 0x0c04eff0 */
if(!s->budget--) { s->failed_pc=0x0c04eff0u; return 0; }
target=code_base|0x0c04fa38u; r[16]=code_base|0x0c04eff4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eff4u) { target=s->pc; goto dispatch; }
goto P_0c04eff4;
P_0c04eff2: /* original 64e3, guest PC 0x0c04eff2 */
if(!s->budget--) { s->failed_pc=0x0c04eff2u; return 0; }
r[4]=r[14];
goto P_0c04eff4;
P_0c04eff4: /* original 6403, guest PC 0x0c04eff4 */
if(!s->budget--) { s->failed_pc=0x0c04eff4u; return 0; }
r[4]=r[0];
goto P_0c04eff6;
P_0c04eff6: /* original 4411, guest PC 0x0c04eff6 */
if(!s->budget--) { s->failed_pc=0x0c04eff6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04eff8;
P_0c04eff8: /* original 8902, guest PC 0x0c04eff8 */
if(!s->budget--) { s->failed_pc=0x0c04eff8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f000; }
goto P_0c04effa;
P_0c04effa: /* original 9018, guest PC 0x0c04effa */
if(!s->budget--) { s->failed_pc=0x0c04effau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f02eu,2);
goto P_0c04effc;
P_0c04effc: /* original a00f, guest PC 0x0c04effc */
if(!s->budget--) { s->failed_pc=0x0c04effcu; return 0; }
goto P_0c04f01e;
P_0c04effe: /* original 0009, guest PC 0x0c04effe */
if(!s->budget--) { s->failed_pc=0x0c04effeu; return 0; }
goto P_0c04f000;
P_0c04f000: /* original e600, guest PC 0x0c04f000 */
if(!s->budget--) { s->failed_pc=0x0c04f000u; return 0; }
r[6]=0x00000000u;
goto P_0c04f002;
P_0c04f002: /* original 6463, guest PC 0x0c04f002 */
if(!s->budget--) { s->failed_pc=0x0c04f002u; return 0; }
r[4]=r[6];
goto P_0c04f004;
P_0c04f004: /* original a006, guest PC 0x0c04f004 */
if(!s->budget--) { s->failed_pc=0x0c04f004u; return 0; }
r[5]=0x0000000cu;
goto P_0c04f014;
P_0c04f006: /* original e50c, guest PC 0x0c04f006 */
if(!s->budget--) { s->failed_pc=0x0c04f006u; return 0; }
r[5]=0x0000000cu;
goto P_0c04f008;
P_0c04f008: /* original 63f3, guest PC 0x0c04f008 */
if(!s->budget--) { s->failed_pc=0x0c04f008u; return 0; }
r[3]=r[15];
goto P_0c04f00a;
P_0c04f00a: /* original 7310, guest PC 0x0c04f00a */
if(!s->budget--) { s->failed_pc=0x0c04f00au; return 0; }
r[3]+=0x00000010u;
goto P_0c04f00c;
P_0c04f00c: /* original 6043, guest PC 0x0c04f00c */
if(!s->budget--) { s->failed_pc=0x0c04f00cu; return 0; }
r[0]=r[4];
goto P_0c04f00e;
P_0c04f00e: /* original 033c, guest PC 0x0c04f00e */
if(!s->budget--) { s->failed_pc=0x0c04f00eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04f010;
P_0c04f010: /* original 7401, guest PC 0x0c04f010 */
if(!s->budget--) { s->failed_pc=0x0c04f010u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f012;
P_0c04f012: /* original 0d34, guest PC 0x0c04f012 */
if(!s->budget--) { s->failed_pc=0x0c04f012u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c04f014;
P_0c04f014: /* original 3453, guest PC 0x0c04f014 */
if(!s->budget--) { s->failed_pc=0x0c04f014u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c04f016;
P_0c04f016: /* original 8bf7, guest PC 0x0c04f016 */
if(!s->budget--) { s->failed_pc=0x0c04f016u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f008; }
goto P_0c04f018;
P_0c04f018: /* original 6063, guest PC 0x0c04f018 */
if(!s->budget--) { s->failed_pc=0x0c04f018u; return 0; }
r[0]=r[6];
goto P_0c04f01a;
P_0c04f01a: /* original 80dc, guest PC 0x0c04f01a */
if(!s->budget--) { s->failed_pc=0x0c04f01au; return 0; }
write(ram,r[13]+12,r[0],1);
goto P_0c04f01c;
P_0c04f01c: /* original e000, guest PC 0x0c04f01c */
if(!s->budget--) { s->failed_pc=0x0c04f01cu; return 0; }
r[0]=0x00000000u;
goto P_0c04f01e;
P_0c04f01e: /* original 7f2c, guest PC 0x0c04f01e */
if(!s->budget--) { s->failed_pc=0x0c04f01eu; return 0; }
r[15]+=0x0000002cu;
goto P_0c04f020;
P_0c04f020: /* original 4f16, guest PC 0x0c04f020 */
if(!s->budget--) { s->failed_pc=0x0c04f020u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f022;
P_0c04f022: /* original 4f26, guest PC 0x0c04f022 */
if(!s->budget--) { s->failed_pc=0x0c04f022u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f024;
P_0c04f024: /* original 6df6, guest PC 0x0c04f024 */
if(!s->budget--) { s->failed_pc=0x0c04f024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f026;
P_0c04f026: /* original 000b, guest PC 0x0c04f026 */
if(!s->budget--) { s->failed_pc=0x0c04f026u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f028: /* original 6ef6, guest PC 0x0c04f028 */
if(!s->budget--) { s->failed_pc=0x0c04f028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04f02au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f02au; return 0; } return 1;
P_0c04f050: /* original 2fe6, guest PC 0x0c04f050 */
if(!s->budget--) { s->failed_pc=0x0c04f050u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f052;
P_0c04f052: /* original 2fd6, guest PC 0x0c04f052 */
if(!s->budget--) { s->failed_pc=0x0c04f052u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f054;
P_0c04f054: /* original 6d43, guest PC 0x0c04f054 */
if(!s->budget--) { s->failed_pc=0x0c04f054u; return 0; }
r[13]=r[4];
goto P_0c04f056;
P_0c04f056: /* original 4f22, guest PC 0x0c04f056 */
if(!s->budget--) { s->failed_pc=0x0c04f056u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f058;
P_0c04f058: /* original 9e6b, guest PC 0x0c04f058 */
if(!s->budget--) { s->failed_pc=0x0c04f058u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f132u,2);
goto P_0c04f05a;
P_0c04f05a: /* original 4f12, guest PC 0x0c04f05a */
if(!s->budget--) { s->failed_pc=0x0c04f05au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f05c;
P_0c04f05c: /* original 2def, guest PC 0x0c04f05c */
if(!s->budget--) { s->failed_pc=0x0c04f05cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[14]);
goto P_0c04f05e;
P_0c04f05e: /* original 7ffc, guest PC 0x0c04f05e */
if(!s->budget--) { s->failed_pc=0x0c04f05eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f060;
P_0c04f060: /* original 0e1a, guest PC 0x0c04f060 */
if(!s->budget--) { s->failed_pc=0x0c04f060u; return 0; }
r[14]=r[19];
goto P_0c04f062;
P_0c04f062: /* original 6eef, guest PC 0x0c04f062 */
if(!s->budget--) { s->failed_pc=0x0c04f062u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04f064;
P_0c04f064: /* original 2fe2, guest PC 0x0c04f064 */
if(!s->budget--) { s->failed_pc=0x0c04f064u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c04f066;
P_0c04f066: /* original d334, guest PC 0x0c04f066 */
if(!s->budget--) { s->failed_pc=0x0c04f066u; return 0; }
r[3]=read(ram,0x0c04f138u,4);
goto P_0c04f068;
P_0c04f068: /* original 3e3c, guest PC 0x0c04f068 */
if(!s->budget--) { s->failed_pc=0x0c04f068u; return 0; }
r[14]+=r[3];
goto P_0c04f06a;
P_0c04f06a: /* original 84e2, guest PC 0x0c04f06a */
if(!s->budget--) { s->failed_pc=0x0c04f06au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04f06c;
P_0c04f06c: /* original 2008, guest PC 0x0c04f06c */
if(!s->budget--) { s->failed_pc=0x0c04f06cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f06e;
P_0c04f06e: /* original 8914, guest PC 0x0c04f06e */
if(!s->budget--) { s->failed_pc=0x0c04f06eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f09a; }
goto P_0c04f070;
P_0c04f070: /* original d332, guest PC 0x0c04f070 */
if(!s->budget--) { s->failed_pc=0x0c04f070u; return 0; }
r[3]=read(ram,0x0c04f13cu,4);
goto P_0c04f072;
P_0c04f072: /* original 430b, guest PC 0x0c04f072 */
if(!s->budget--) { s->failed_pc=0x0c04f072u; return 0; }
target=r[3];
r[16]=code_base|0x0c04f076u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f076u) { target=s->pc; goto dispatch; }
goto P_0c04f076;
P_0c04f074: /* original 64d3, guest PC 0x0c04f074 */
if(!s->budget--) { s->failed_pc=0x0c04f074u; return 0; }
r[4]=r[13];
goto P_0c04f076;
P_0c04f076: /* original 2008, guest PC 0x0c04f076 */
if(!s->budget--) { s->failed_pc=0x0c04f076u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f078;
P_0c04f078: /* original 8b04, guest PC 0x0c04f078 */
if(!s->budget--) { s->failed_pc=0x0c04f078u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f084; }
goto P_0c04f07a;
P_0c04f07a: /* original d331, guest PC 0x0c04f07a */
if(!s->budget--) { s->failed_pc=0x0c04f07au; return 0; }
r[3]=read(ram,0x0c04f140u,4);
goto P_0c04f07c;
P_0c04f07c: /* original 430b, guest PC 0x0c04f07c */
if(!s->budget--) { s->failed_pc=0x0c04f07cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04f080u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f080u) { target=s->pc; goto dispatch; }
goto P_0c04f080;
P_0c04f07e: /* original 64d3, guest PC 0x0c04f07e */
if(!s->budget--) { s->failed_pc=0x0c04f07eu; return 0; }
r[4]=r[13];
goto P_0c04f080;
P_0c04f080: /* original a00b, guest PC 0x0c04f080 */
if(!s->budget--) { s->failed_pc=0x0c04f080u; return 0; }
goto P_0c04f09a;
P_0c04f082: /* original 0009, guest PC 0x0c04f082 */
if(!s->budget--) { s->failed_pc=0x0c04f082u; return 0; }
goto P_0c04f084;
P_0c04f084: /* original d22f, guest PC 0x0c04f084 */
if(!s->budget--) { s->failed_pc=0x0c04f084u; return 0; }
r[2]=read(ram,0x0c04f144u,4);
goto P_0c04f086;
P_0c04f086: /* original 420b, guest PC 0x0c04f086 */
if(!s->budget--) { s->failed_pc=0x0c04f086u; return 0; }
target=r[2];
r[16]=code_base|0x0c04f08au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f08au) { target=s->pc; goto dispatch; }
goto P_0c04f08a;
P_0c04f088: /* original 64d3, guest PC 0x0c04f088 */
if(!s->budget--) { s->failed_pc=0x0c04f088u; return 0; }
r[4]=r[13];
goto P_0c04f08a;
P_0c04f08a: /* original 2008, guest PC 0x0c04f08a */
if(!s->budget--) { s->failed_pc=0x0c04f08au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f08c;
P_0c04f08c: /* original 8905, guest PC 0x0c04f08c */
if(!s->budget--) { s->failed_pc=0x0c04f08cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f09a; }
goto P_0c04f08e;
P_0c04f08e: /* original 62f2, guest PC 0x0c04f08e */
if(!s->budget--) { s->failed_pc=0x0c04f08eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04f090;
P_0c04f090: /* original d329, guest PC 0x0c04f090 */
if(!s->budget--) { s->failed_pc=0x0c04f090u; return 0; }
r[3]=read(ram,0x0c04f138u,4);
goto P_0c04f092;
P_0c04f092: /* original 323c, guest PC 0x0c04f092 */
if(!s->budget--) { s->failed_pc=0x0c04f092u; return 0; }
r[2]+=r[3];
goto P_0c04f094;
P_0c04f094: /* original 8428, guest PC 0x0c04f094 */
if(!s->budget--) { s->failed_pc=0x0c04f094u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04f096;
P_0c04f096: /* original 2008, guest PC 0x0c04f096 */
if(!s->budget--) { s->failed_pc=0x0c04f096u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f098;
P_0c04f098: /* original 8b02, guest PC 0x0c04f098 */
if(!s->budget--) { s->failed_pc=0x0c04f098u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f0a0; }
goto P_0c04f09a;
P_0c04f09a: /* original 904b, guest PC 0x0c04f09a */
if(!s->budget--) { s->failed_pc=0x0c04f09au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f134u,2);
goto P_0c04f09c;
P_0c04f09c: /* original a019, guest PC 0x0c04f09c */
if(!s->budget--) { s->failed_pc=0x0c04f09cu; return 0; }
goto P_0c04f0d2;
P_0c04f09e: /* original 0009, guest PC 0x0c04f09e */
if(!s->budget--) { s->failed_pc=0x0c04f09eu; return 0; }
goto P_0c04f0a0;
P_0c04f0a0: /* original 55e8, guest PC 0x0c04f0a0 */
if(!s->budget--) { s->failed_pc=0x0c04f0a0u; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c04f0a2;
P_0c04f0a2: /* original e400, guest PC 0x0c04f0a2 */
if(!s->budget--) { s->failed_pc=0x0c04f0a2u; return 0; }
r[4]=0x00000000u;
goto P_0c04f0a4;
P_0c04f0a4: /* original e710, guest PC 0x0c04f0a4 */
if(!s->budget--) { s->failed_pc=0x0c04f0a4u; return 0; }
r[7]=0x00000010u;
goto P_0c04f0a6;
P_0c04f0a6: /* original 6643, guest PC 0x0c04f0a6 */
if(!s->budget--) { s->failed_pc=0x0c04f0a6u; return 0; }
r[6]=r[4];
goto P_0c04f0a8;
P_0c04f0a8: /* original 6050, guest PC 0x0c04f0a8 */
if(!s->budget--) { s->failed_pc=0x0c04f0a8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c04f0aa;
P_0c04f0aa: /* original 600c, guest PC 0x0c04f0aa */
if(!s->budget--) { s->failed_pc=0x0c04f0aau; return 0; }
r[0]=r[0]&255u;
goto P_0c04f0ac;
P_0c04f0ac: /* original 8855, guest PC 0x0c04f0ac */
if(!s->budget--) { s->failed_pc=0x0c04f0acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000055u)!=0);
goto P_0c04f0ae;
P_0c04f0ae: /* original 8903, guest PC 0x0c04f0ae */
if(!s->budget--) { s->failed_pc=0x0c04f0aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f0b8; }
goto P_0c04f0b0;
P_0c04f0b0: /* original 6043, guest PC 0x0c04f0b0 */
if(!s->budget--) { s->failed_pc=0x0c04f0b0u; return 0; }
r[0]=r[4];
goto P_0c04f0b2;
P_0c04f0b2: /* original 80eb, guest PC 0x0c04f0b2 */
if(!s->budget--) { s->failed_pc=0x0c04f0b2u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04f0b4;
P_0c04f0b4: /* original a009, guest PC 0x0c04f0b4 */
if(!s->budget--) { s->failed_pc=0x0c04f0b4u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04f0ca;
P_0c04f0b6: /* original 80ec, guest PC 0x0c04f0b6 */
if(!s->budget--) { s->failed_pc=0x0c04f0b6u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04f0b8;
P_0c04f0b8: /* original 7601, guest PC 0x0c04f0b8 */
if(!s->budget--) { s->failed_pc=0x0c04f0b8u; return 0; }
r[6]+=0x00000001u;
goto P_0c04f0ba;
P_0c04f0ba: /* original 3673, guest PC 0x0c04f0ba */
if(!s->budget--) { s->failed_pc=0x0c04f0bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f0bc;
P_0c04f0bc: /* original 8ff4, guest PC 0x0c04f0bc */
if(!s->budget--) { s->failed_pc=0x0c04f0bcu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c04f0a8; }
goto P_0c04f0c0;
P_0c04f0be: /* original 7501, guest PC 0x0c04f0be */
if(!s->budget--) { s->failed_pc=0x0c04f0beu; return 0; }
r[5]+=0x00000001u;
goto P_0c04f0c0;
P_0c04f0c0: /* original d021, guest PC 0x0c04f0c0 */
if(!s->budget--) { s->failed_pc=0x0c04f0c0u; return 0; }
r[0]=read(ram,0x0c04f148u,4);
goto P_0c04f0c2;
P_0c04f0c2: /* original 4d08, guest PC 0x0c04f0c2 */
if(!s->budget--) { s->failed_pc=0x0c04f0c2u; return 0; }
r[13]<<=2;
goto P_0c04f0c4;
P_0c04f0c4: /* original 03de, guest PC 0x0c04f0c4 */
if(!s->budget--) { s->failed_pc=0x0c04f0c4u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c04f0c6;
P_0c04f0c6: /* original 2338, guest PC 0x0c04f0c6 */
if(!s->budget--) { s->failed_pc=0x0c04f0c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04f0c8;
P_0c04f0c8: /* original 8902, guest PC 0x0c04f0c8 */
if(!s->budget--) { s->failed_pc=0x0c04f0c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f0d0; }
goto P_0c04f0ca;
P_0c04f0ca: /* original 9034, guest PC 0x0c04f0ca */
if(!s->budget--) { s->failed_pc=0x0c04f0cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f136u,2);
goto P_0c04f0cc;
P_0c04f0cc: /* original a001, guest PC 0x0c04f0cc */
if(!s->budget--) { s->failed_pc=0x0c04f0ccu; return 0; }
goto P_0c04f0d2;
P_0c04f0ce: /* original 0009, guest PC 0x0c04f0ce */
if(!s->budget--) { s->failed_pc=0x0c04f0ceu; return 0; }
goto P_0c04f0d0;
P_0c04f0d0: /* original e000, guest PC 0x0c04f0d0 */
if(!s->budget--) { s->failed_pc=0x0c04f0d0u; return 0; }
r[0]=0x00000000u;
goto P_0c04f0d2;
P_0c04f0d2: /* original 7f04, guest PC 0x0c04f0d2 */
if(!s->budget--) { s->failed_pc=0x0c04f0d2u; return 0; }
r[15]+=0x00000004u;
goto P_0c04f0d4;
P_0c04f0d4: /* original 4f16, guest PC 0x0c04f0d4 */
if(!s->budget--) { s->failed_pc=0x0c04f0d4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f0d6;
P_0c04f0d6: /* original 4f26, guest PC 0x0c04f0d6 */
if(!s->budget--) { s->failed_pc=0x0c04f0d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f0d8;
P_0c04f0d8: /* original 6df6, guest PC 0x0c04f0d8 */
if(!s->budget--) { s->failed_pc=0x0c04f0d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f0da;
P_0c04f0da: /* original 000b, guest PC 0x0c04f0da */
if(!s->budget--) { s->failed_pc=0x0c04f0dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f0dc: /* original 6ef6, guest PC 0x0c04f0dc */
if(!s->budget--) { s->failed_pc=0x0c04f0dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04f0deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f0deu; return 0; } return 1;
P_0c04f250: /* original 2fe6, guest PC 0x0c04f250 */
if(!s->budget--) { s->failed_pc=0x0c04f250u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f252;
P_0c04f252: /* original 2fd6, guest PC 0x0c04f252 */
if(!s->budget--) { s->failed_pc=0x0c04f252u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f254;
P_0c04f254: /* original 2fc6, guest PC 0x0c04f254 */
if(!s->budget--) { s->failed_pc=0x0c04f254u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f256;
P_0c04f256: /* original 4f22, guest PC 0x0c04f256 */
if(!s->budget--) { s->failed_pc=0x0c04f256u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f258;
P_0c04f258: /* original 9d80, guest PC 0x0c04f258 */
if(!s->budget--) { s->failed_pc=0x0c04f258u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f35cu,2);
goto P_0c04f25a;
P_0c04f25a: /* original d341, guest PC 0x0c04f25a */
if(!s->budget--) { s->failed_pc=0x0c04f25au; return 0; }
r[3]=read(ram,0x0c04f360u,4);
goto P_0c04f25c;
P_0c04f25c: /* original 4f12, guest PC 0x0c04f25c */
if(!s->budget--) { s->failed_pc=0x0c04f25cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f25e;
P_0c04f25e: /* original 24df, guest PC 0x0c04f25e */
if(!s->budget--) { s->failed_pc=0x0c04f25eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[13]);
goto P_0c04f260;
P_0c04f260: /* original dc40, guest PC 0x0c04f260 */
if(!s->budget--) { s->failed_pc=0x0c04f260u; return 0; }
r[12]=read(ram,0x0c04f364u,4);
goto P_0c04f262;
P_0c04f262: /* original 0d1a, guest PC 0x0c04f262 */
if(!s->budget--) { s->failed_pc=0x0c04f262u; return 0; }
r[13]=r[19];
goto P_0c04f264;
P_0c04f264: /* original 6ddf, guest PC 0x0c04f264 */
if(!s->budget--) { s->failed_pc=0x0c04f264u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04f266;
P_0c04f266: /* original 3d3c, guest PC 0x0c04f266 */
if(!s->budget--) { s->failed_pc=0x0c04f266u; return 0; }
r[13]+=r[3];
goto P_0c04f268;
P_0c04f268: /* original a011, guest PC 0x0c04f268 */
if(!s->budget--) { s->failed_pc=0x0c04f268u; return 0; }
r[14]=0x00000000u;
goto P_0c04f28e;
P_0c04f26a: /* original ee00, guest PC 0x0c04f26a */
if(!s->budget--) { s->failed_pc=0x0c04f26au; return 0; }
r[14]=0x00000000u;
goto P_0c04f26c;
P_0c04f26c: /* original 63c2, guest PC 0x0c04f26c */
if(!s->budget--) { s->failed_pc=0x0c04f26cu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04f26e;
P_0c04f26e: /* original 65e3, guest PC 0x0c04f26e */
if(!s->budget--) { s->failed_pc=0x0c04f26eu; return 0; }
r[5]=r[14];
goto P_0c04f270;
P_0c04f270: /* original 4500, guest PC 0x0c04f270 */
if(!s->budget--) { s->failed_pc=0x0c04f270u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04f272;
P_0c04f272: /* original 5233, guest PC 0x0c04f272 */
if(!s->budget--) { s->failed_pc=0x0c04f272u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f274;
P_0c04f274: /* original 420b, guest PC 0x0c04f274 */
if(!s->budget--) { s->failed_pc=0x0c04f274u; return 0; }
target=r[2];
r[16]=code_base|0x0c04f278u;
r[4]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f278u) { target=s->pc; goto dispatch; }
goto P_0c04f278;
P_0c04f276: /* original 54d9, guest PC 0x0c04f276 */
if(!s->budget--) { s->failed_pc=0x0c04f276u; return 0; }
r[4]=read(ram,r[13]+36,4);
goto P_0c04f278;
P_0c04f278: /* original d13b, guest PC 0x0c04f278 */
if(!s->budget--) { s->failed_pc=0x0c04f278u; return 0; }
r[1]=read(ram,0x0c04f368u,4);
goto P_0c04f27a;
P_0c04f27a: /* original 640d, guest PC 0x0c04f27a */
if(!s->budget--) { s->failed_pc=0x0c04f27au; return 0; }
r[4]=r[0]&65535u;
goto P_0c04f27c;
P_0c04f27c: /* original 6043, guest PC 0x0c04f27c */
if(!s->budget--) { s->failed_pc=0x0c04f27cu; return 0; }
r[0]=r[4];
goto P_0c04f27e;
P_0c04f27e: /* original 3010, guest PC 0x0c04f27e */
if(!s->budget--) { s->failed_pc=0x0c04f27eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f280;
P_0c04f280: /* original 8904, guest PC 0x0c04f280 */
if(!s->budget--) { s->failed_pc=0x0c04f280u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f28c; }
goto P_0c04f282;
P_0c04f282: /* original d13a, guest PC 0x0c04f282 */
if(!s->budget--) { s->failed_pc=0x0c04f282u; return 0; }
r[1]=read(ram,0x0c04f36cu,4);
goto P_0c04f284;
P_0c04f284: /* original 3010, guest PC 0x0c04f284 */
if(!s->budget--) { s->failed_pc=0x0c04f284u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f286;
P_0c04f286: /* original 8901, guest PC 0x0c04f286 */
if(!s->budget--) { s->failed_pc=0x0c04f286u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f28c; }
goto P_0c04f288;
P_0c04f288: /* original a006, guest PC 0x0c04f288 */
if(!s->budget--) { s->failed_pc=0x0c04f288u; return 0; }
r[0]=r[14];
goto P_0c04f298;
P_0c04f28a: /* original 60e3, guest PC 0x0c04f28a */
if(!s->budget--) { s->failed_pc=0x0c04f28au; return 0; }
r[0]=r[14];
goto P_0c04f28c;
P_0c04f28c: /* original 7e01, guest PC 0x0c04f28c */
if(!s->budget--) { s->failed_pc=0x0c04f28cu; return 0; }
r[14]+=0x00000001u;
goto P_0c04f28e;
P_0c04f28e: /* original 52d7, guest PC 0x0c04f28e */
if(!s->budget--) { s->failed_pc=0x0c04f28eu; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04f290;
P_0c04f290: /* original 532c, guest PC 0x0c04f290 */
if(!s->budget--) { s->failed_pc=0x0c04f290u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04f292;
P_0c04f292: /* original 3e33, guest PC 0x0c04f292 */
if(!s->budget--) { s->failed_pc=0x0c04f292u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c04f294;
P_0c04f294: /* original 8bea, guest PC 0x0c04f294 */
if(!s->budget--) { s->failed_pc=0x0c04f294u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f26c; }
goto P_0c04f296;
P_0c04f296: /* original e0ff, guest PC 0x0c04f296 */
if(!s->budget--) { s->failed_pc=0x0c04f296u; return 0; }
r[0]=0xffffffffu;
goto P_0c04f298;
P_0c04f298: /* original 4f16, guest PC 0x0c04f298 */
if(!s->budget--) { s->failed_pc=0x0c04f298u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f29a;
P_0c04f29a: /* original 4f26, guest PC 0x0c04f29a */
if(!s->budget--) { s->failed_pc=0x0c04f29au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f29c;
P_0c04f29c: /* original 6cf6, guest PC 0x0c04f29c */
if(!s->budget--) { s->failed_pc=0x0c04f29cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f29e;
P_0c04f29e: /* original 6df6, guest PC 0x0c04f29e */
if(!s->budget--) { s->failed_pc=0x0c04f29eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f2a0;
P_0c04f2a0: /* original 000b, guest PC 0x0c04f2a0 */
if(!s->budget--) { s->failed_pc=0x0c04f2a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f2a2: /* original 6ef6, guest PC 0x0c04f2a2 */
if(!s->budget--) { s->failed_pc=0x0c04f2a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f2a4;
P_0c04f2a4: /* original 2fe6, guest PC 0x0c04f2a4 */
if(!s->budget--) { s->failed_pc=0x0c04f2a4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f2a6;
P_0c04f2a6: /* original 2fd6, guest PC 0x0c04f2a6 */
if(!s->budget--) { s->failed_pc=0x0c04f2a6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f2a8;
P_0c04f2a8: /* original 2fc6, guest PC 0x0c04f2a8 */
if(!s->budget--) { s->failed_pc=0x0c04f2a8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f2aa;
P_0c04f2aa: /* original 2fb6, guest PC 0x0c04f2aa */
if(!s->budget--) { s->failed_pc=0x0c04f2aau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f2ac;
P_0c04f2ac: /* original 6b53, guest PC 0x0c04f2ac */
if(!s->budget--) { s->failed_pc=0x0c04f2acu; return 0; }
r[11]=r[5];
goto P_0c04f2ae;
P_0c04f2ae: /* original 2fa6, guest PC 0x0c04f2ae */
if(!s->budget--) { s->failed_pc=0x0c04f2aeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f2b0;
P_0c04f2b0: /* original 4f22, guest PC 0x0c04f2b0 */
if(!s->budget--) { s->failed_pc=0x0c04f2b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f2b2;
P_0c04f2b2: /* original 9d53, guest PC 0x0c04f2b2 */
if(!s->budget--) { s->failed_pc=0x0c04f2b2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f35cu,2);
goto P_0c04f2b4;
P_0c04f2b4: /* original d32a, guest PC 0x0c04f2b4 */
if(!s->budget--) { s->failed_pc=0x0c04f2b4u; return 0; }
r[3]=read(ram,0x0c04f360u,4);
goto P_0c04f2b6;
P_0c04f2b6: /* original 4f12, guest PC 0x0c04f2b6 */
if(!s->budget--) { s->failed_pc=0x0c04f2b6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f2b8;
P_0c04f2b8: /* original 24df, guest PC 0x0c04f2b8 */
if(!s->budget--) { s->failed_pc=0x0c04f2b8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[13]);
goto P_0c04f2ba;
P_0c04f2ba: /* original da2a, guest PC 0x0c04f2ba */
if(!s->budget--) { s->failed_pc=0x0c04f2bau; return 0; }
r[10]=read(ram,0x0c04f364u,4);
goto P_0c04f2bc;
P_0c04f2bc: /* original dc2a, guest PC 0x0c04f2bc */
if(!s->budget--) { s->failed_pc=0x0c04f2bcu; return 0; }
r[12]=read(ram,0x0c04f368u,4);
goto P_0c04f2be;
P_0c04f2be: /* original 0d1a, guest PC 0x0c04f2be */
if(!s->budget--) { s->failed_pc=0x0c04f2beu; return 0; }
r[13]=r[19];
goto P_0c04f2c0;
P_0c04f2c0: /* original 6ddf, guest PC 0x0c04f2c0 */
if(!s->budget--) { s->failed_pc=0x0c04f2c0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04f2c2;
P_0c04f2c2: /* original 3d3c, guest PC 0x0c04f2c2 */
if(!s->budget--) { s->failed_pc=0x0c04f2c2u; return 0; }
r[13]+=r[3];
goto P_0c04f2c4;
P_0c04f2c4: /* original 5ed7, guest PC 0x0c04f2c4 */
if(!s->budget--) { s->failed_pc=0x0c04f2c4u; return 0; }
r[14]=read(ram,r[13]+28,4);
goto P_0c04f2c6;
P_0c04f2c6: /* original 5eec, guest PC 0x0c04f2c6 */
if(!s->budget--) { s->failed_pc=0x0c04f2c6u; return 0; }
r[14]=read(ram,r[14]+48,4);
goto P_0c04f2c8;
P_0c04f2c8: /* original 7eff, guest PC 0x0c04f2c8 */
if(!s->budget--) { s->failed_pc=0x0c04f2c8u; return 0; }
r[14]+=0xffffffffu;
goto P_0c04f2ca;
P_0c04f2ca: /* original 3eb3, guest PC 0x0c04f2ca */
if(!s->budget--) { s->failed_pc=0x0c04f2cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c04f2cc;
P_0c04f2cc: /* original 8b0d, guest PC 0x0c04f2cc */
if(!s->budget--) { s->failed_pc=0x0c04f2ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f2ea; }
goto P_0c04f2ce;
P_0c04f2ce: /* original 63a2, guest PC 0x0c04f2ce */
if(!s->budget--) { s->failed_pc=0x0c04f2ceu; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c04f2d0;
P_0c04f2d0: /* original 65e3, guest PC 0x0c04f2d0 */
if(!s->budget--) { s->failed_pc=0x0c04f2d0u; return 0; }
r[5]=r[14];
goto P_0c04f2d2;
P_0c04f2d2: /* original 4500, guest PC 0x0c04f2d2 */
if(!s->budget--) { s->failed_pc=0x0c04f2d2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04f2d4;
P_0c04f2d4: /* original 5233, guest PC 0x0c04f2d4 */
if(!s->budget--) { s->failed_pc=0x0c04f2d4u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f2d6;
P_0c04f2d6: /* original 420b, guest PC 0x0c04f2d6 */
if(!s->budget--) { s->failed_pc=0x0c04f2d6u; return 0; }
target=r[2];
r[16]=code_base|0x0c04f2dau;
r[4]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f2dau) { target=s->pc; goto dispatch; }
goto P_0c04f2da;
P_0c04f2d8: /* original 54d9, guest PC 0x0c04f2d8 */
if(!s->budget--) { s->failed_pc=0x0c04f2d8u; return 0; }
r[4]=read(ram,r[13]+36,4);
goto P_0c04f2da;
P_0c04f2da: /* original 600d, guest PC 0x0c04f2da */
if(!s->budget--) { s->failed_pc=0x0c04f2dau; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f2dc;
P_0c04f2dc: /* original 30c0, guest PC 0x0c04f2dc */
if(!s->budget--) { s->failed_pc=0x0c04f2dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[12])!=0);
goto P_0c04f2de;
P_0c04f2de: /* original 8b01, guest PC 0x0c04f2de */
if(!s->budget--) { s->failed_pc=0x0c04f2deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f2e4; }
goto P_0c04f2e0;
P_0c04f2e0: /* original a004, guest PC 0x0c04f2e0 */
if(!s->budget--) { s->failed_pc=0x0c04f2e0u; return 0; }
r[0]=r[14];
goto P_0c04f2ec;
P_0c04f2e2: /* original 60e3, guest PC 0x0c04f2e2 */
if(!s->budget--) { s->failed_pc=0x0c04f2e2u; return 0; }
r[0]=r[14];
goto P_0c04f2e4;
P_0c04f2e4: /* original 7eff, guest PC 0x0c04f2e4 */
if(!s->budget--) { s->failed_pc=0x0c04f2e4u; return 0; }
r[14]+=0xffffffffu;
goto P_0c04f2e6;
P_0c04f2e6: /* original 3eb3, guest PC 0x0c04f2e6 */
if(!s->budget--) { s->failed_pc=0x0c04f2e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c04f2e8;
P_0c04f2e8: /* original 89f1, guest PC 0x0c04f2e8 */
if(!s->budget--) { s->failed_pc=0x0c04f2e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f2ce; }
goto P_0c04f2ea;
P_0c04f2ea: /* original e0ff, guest PC 0x0c04f2ea */
if(!s->budget--) { s->failed_pc=0x0c04f2eau; return 0; }
r[0]=0xffffffffu;
goto P_0c04f2ec;
P_0c04f2ec: /* original 4f16, guest PC 0x0c04f2ec */
if(!s->budget--) { s->failed_pc=0x0c04f2ecu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f2ee;
P_0c04f2ee: /* original 4f26, guest PC 0x0c04f2ee */
if(!s->budget--) { s->failed_pc=0x0c04f2eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f2f0;
P_0c04f2f0: /* original 6af6, guest PC 0x0c04f2f0 */
if(!s->budget--) { s->failed_pc=0x0c04f2f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04f2f2;
P_0c04f2f2: /* original 6bf6, guest PC 0x0c04f2f2 */
if(!s->budget--) { s->failed_pc=0x0c04f2f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04f2f4;
P_0c04f2f4: /* original 6cf6, guest PC 0x0c04f2f4 */
if(!s->budget--) { s->failed_pc=0x0c04f2f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f2f6;
P_0c04f2f6: /* original 6df6, guest PC 0x0c04f2f6 */
if(!s->budget--) { s->failed_pc=0x0c04f2f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f2f8;
P_0c04f2f8: /* original 000b, guest PC 0x0c04f2f8 */
if(!s->budget--) { s->failed_pc=0x0c04f2f8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f2fa: /* original 6ef6, guest PC 0x0c04f2fa */
if(!s->budget--) { s->failed_pc=0x0c04f2fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f2fcu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
