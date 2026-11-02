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
int vf3_away_batch131_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03eda0u: goto P_0c03eda0;
case 0x0c03eda2u: goto P_0c03eda2;
case 0x0c03eda4u: goto P_0c03eda4;
case 0x0c03eda6u: goto P_0c03eda6;
case 0x0c03eda8u: goto P_0c03eda8;
case 0x0c03edaau: goto P_0c03edaa;
case 0x0c03edacu: goto P_0c03edac;
case 0x0c055d40u: goto P_0c055d40;
case 0x0c055d42u: goto P_0c055d42;
case 0x0c055d44u: goto P_0c055d44;
case 0x0c055d46u: goto P_0c055d46;
case 0x0c055d48u: goto P_0c055d48;
case 0x0c055d4au: goto P_0c055d4a;
case 0x0c055d4cu: goto P_0c055d4c;
case 0x0c055d4eu: goto P_0c055d4e;
case 0x0c055d50u: goto P_0c055d50;
case 0x0c055d52u: goto P_0c055d52;
case 0x0c055d54u: goto P_0c055d54;
case 0x0c055d56u: goto P_0c055d56;
case 0x0c055d58u: goto P_0c055d58;
case 0x0c055d5au: goto P_0c055d5a;
case 0x0c055d5cu: goto P_0c055d5c;
case 0x0c055d5eu: goto P_0c055d5e;
case 0x0c055d60u: goto P_0c055d60;
case 0x0c055d62u: goto P_0c055d62;
case 0x0c055d64u: goto P_0c055d64;
case 0x0c055d66u: goto P_0c055d66;
case 0x0c055d68u: goto P_0c055d68;
case 0x0c055d6au: goto P_0c055d6a;
case 0x0c055d6cu: goto P_0c055d6c;
case 0x0c055d6eu: goto P_0c055d6e;
case 0x0c055d70u: goto P_0c055d70;
case 0x0c055d72u: goto P_0c055d72;
case 0x0c055d74u: goto P_0c055d74;
case 0x0c055d76u: goto P_0c055d76;
case 0x0c055d78u: goto P_0c055d78;
case 0x0c055d7au: goto P_0c055d7a;
case 0x0c055d7cu: goto P_0c055d7c;
case 0x0c055d7eu: goto P_0c055d7e;
case 0x0c055d80u: goto P_0c055d80;
case 0x0c055d82u: goto P_0c055d82;
case 0x0c055d84u: goto P_0c055d84;
case 0x0c055d86u: goto P_0c055d86;
case 0x0c055d88u: goto P_0c055d88;
case 0x0c055d8au: goto P_0c055d8a;
case 0x0c055d8cu: goto P_0c055d8c;
case 0x0c055d8eu: goto P_0c055d8e;
case 0x0c055d90u: goto P_0c055d90;
case 0x0c055d92u: goto P_0c055d92;
case 0x0c055d94u: goto P_0c055d94;
case 0x0c055d96u: goto P_0c055d96;
case 0x0c055d98u: goto P_0c055d98;
case 0x0c055d9au: goto P_0c055d9a;
case 0x0c055d9cu: goto P_0c055d9c;
case 0x0c055d9eu: goto P_0c055d9e;
case 0x0c055da0u: goto P_0c055da0;
case 0x0c055da2u: goto P_0c055da2;
case 0x0c055da4u: goto P_0c055da4;
case 0x0c055da6u: goto P_0c055da6;
case 0x0c055da8u: goto P_0c055da8;
case 0x0c055daau: goto P_0c055daa;
case 0x0c055dacu: goto P_0c055dac;
case 0x0c055daeu: goto P_0c055dae;
case 0x0c055db0u: goto P_0c055db0;
case 0x0c055db2u: goto P_0c055db2;
case 0x0c055db4u: goto P_0c055db4;
case 0x0c055db6u: goto P_0c055db6;
case 0x0c055db8u: goto P_0c055db8;
case 0x0c05e1b2u: goto P_0c05e1b2;
case 0x0c05e1b4u: goto P_0c05e1b4;
case 0x0c05e1b6u: goto P_0c05e1b6;
case 0x0c05e1b8u: goto P_0c05e1b8;
case 0x0c05e1bau: goto P_0c05e1ba;
case 0x0c05e1bcu: goto P_0c05e1bc;
case 0x0c05e1beu: goto P_0c05e1be;
case 0x0c05e1c0u: goto P_0c05e1c0;
case 0x0c05e3d6u: goto P_0c05e3d6;
case 0x0c05e3d8u: goto P_0c05e3d8;
case 0x0c05e3dau: goto P_0c05e3da;
case 0x0c05e3dcu: goto P_0c05e3dc;
case 0x0c05e3deu: goto P_0c05e3de;
case 0x0c05e3e0u: goto P_0c05e3e0;
case 0x0c05e3e2u: goto P_0c05e3e2;
case 0x0c05e3e4u: goto P_0c05e3e4;
case 0x0c05e3e6u: goto P_0c05e3e6;
case 0x0c05e3e8u: goto P_0c05e3e8;
case 0x0c05e3eau: goto P_0c05e3ea;
case 0x0c05e3ecu: goto P_0c05e3ec;
case 0x0c05e3eeu: goto P_0c05e3ee;
case 0x0c05e3f0u: goto P_0c05e3f0;
case 0x0c05e3f2u: goto P_0c05e3f2;
case 0x0c05e3f4u: goto P_0c05e3f4;
case 0x0c05e3f6u: goto P_0c05e3f6;
case 0x0c05e3f8u: goto P_0c05e3f8;
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
case 0x0c0955b0u: goto P_0c0955b0;
case 0x0c0955b2u: goto P_0c0955b2;
case 0x0c0955b4u: goto P_0c0955b4;
case 0x0c0955b6u: goto P_0c0955b6;
case 0x0c0955b8u: goto P_0c0955b8;
case 0x0c0955bau: goto P_0c0955ba;
case 0x0c0955bcu: goto P_0c0955bc;
case 0x0c0955beu: goto P_0c0955be;
case 0x0c0955c0u: goto P_0c0955c0;
case 0x0c0955c2u: goto P_0c0955c2;
case 0x0c0955c4u: goto P_0c0955c4;
case 0x0c0955c6u: goto P_0c0955c6;
case 0x0c0955c8u: goto P_0c0955c8;
case 0x0c0955cau: goto P_0c0955ca;
case 0x0c0955ccu: goto P_0c0955cc;
case 0x0c0955ceu: goto P_0c0955ce;
case 0x0c0955d0u: goto P_0c0955d0;
case 0x0c0955d2u: goto P_0c0955d2;
case 0x0c0955d4u: goto P_0c0955d4;
case 0x0c0955d6u: goto P_0c0955d6;
case 0x0c0955d8u: goto P_0c0955d8;
case 0x0c0955dau: goto P_0c0955da;
case 0x0c0955dcu: goto P_0c0955dc;
case 0x0c0955deu: goto P_0c0955de;
case 0x0c0955e0u: goto P_0c0955e0;
case 0x0c0955e2u: goto P_0c0955e2;
case 0x0c0955e4u: goto P_0c0955e4;
case 0x0c0955e6u: goto P_0c0955e6;
case 0x0c0955e8u: goto P_0c0955e8;
case 0x0c0955eau: goto P_0c0955ea;
case 0x0c0955ecu: goto P_0c0955ec;
case 0x0c0955eeu: goto P_0c0955ee;
case 0x0c0955f0u: goto P_0c0955f0;
case 0x0c0955f2u: goto P_0c0955f2;
case 0x0c0955f4u: goto P_0c0955f4;
case 0x0c0955f6u: goto P_0c0955f6;
case 0x0c0955f8u: goto P_0c0955f8;
case 0x0c0955fau: goto P_0c0955fa;
case 0x0c0955fcu: goto P_0c0955fc;
case 0x0c0955feu: goto P_0c0955fe;
case 0x0c095600u: goto P_0c095600;
case 0x0c095602u: goto P_0c095602;
case 0x0c0a7784u: goto P_0c0a7784;
case 0x0c0a7786u: goto P_0c0a7786;
case 0x0c0a7788u: goto P_0c0a7788;
case 0x0c0a778au: goto P_0c0a778a;
case 0x0c0a778cu: goto P_0c0a778c;
case 0x0c0a778eu: goto P_0c0a778e;
case 0x0c0a7790u: goto P_0c0a7790;
case 0x0c0a7792u: goto P_0c0a7792;
case 0x0c0a7794u: goto P_0c0a7794;
case 0x0c0a7796u: goto P_0c0a7796;
case 0x0c0a7798u: goto P_0c0a7798;
case 0x0c0a779au: goto P_0c0a779a;
case 0x0c0a779cu: goto P_0c0a779c;
case 0x0c0a779eu: goto P_0c0a779e;
case 0x0c0a77a0u: goto P_0c0a77a0;
case 0x0c0a77a2u: goto P_0c0a77a2;
case 0x0c0a77a4u: goto P_0c0a77a4;
case 0x0c0a77a6u: goto P_0c0a77a6;
case 0x0c0a77a8u: goto P_0c0a77a8;
case 0x0c0a77aau: goto P_0c0a77aa;
case 0x0c0a77acu: goto P_0c0a77ac;
case 0x0c0a77aeu: goto P_0c0a77ae;
case 0x0c0a77b0u: goto P_0c0a77b0;
case 0x0c0a77b2u: goto P_0c0a77b2;
case 0x0c0a77b4u: goto P_0c0a77b4;
case 0x0c0a77b6u: goto P_0c0a77b6;
case 0x0c0a77b8u: goto P_0c0a77b8;
case 0x0c0a77bau: goto P_0c0a77ba;
case 0x0c0a77bcu: goto P_0c0a77bc;
case 0x0c0a77beu: goto P_0c0a77be;
case 0x0c0a77c0u: goto P_0c0a77c0;
case 0x0c0a77c2u: goto P_0c0a77c2;
case 0x0c0a77c4u: goto P_0c0a77c4;
case 0x0c0a77c6u: goto P_0c0a77c6;
case 0x0c0a77c8u: goto P_0c0a77c8;
case 0x0c0a77cau: goto P_0c0a77ca;
case 0x0c0a77ccu: goto P_0c0a77cc;
case 0x0c0a77ceu: goto P_0c0a77ce;
case 0x0c0a77d0u: goto P_0c0a77d0;
case 0x0c0a77d2u: goto P_0c0a77d2;
case 0x0c0a77d4u: goto P_0c0a77d4;
case 0x0c0a77d6u: goto P_0c0a77d6;
case 0x0c0a77d8u: goto P_0c0a77d8;
case 0x0c0a77dau: goto P_0c0a77da;
case 0x0c0a77dcu: goto P_0c0a77dc;
case 0x0c0a77e2u: goto P_0c0a77e2;
case 0x0c0a77e4u: goto P_0c0a77e4;
case 0x0c0a77e6u: goto P_0c0a77e6;
case 0x0c0a77e8u: goto P_0c0a77e8;
case 0x0c0a77eau: goto P_0c0a77ea;
case 0x0c0a77ecu: goto P_0c0a77ec;
case 0x0c0a77eeu: goto P_0c0a77ee;
case 0x0c0a77f0u: goto P_0c0a77f0;
case 0x0c0a77f2u: goto P_0c0a77f2;
case 0x0c0a77f4u: goto P_0c0a77f4;
case 0x0c0a77f6u: goto P_0c0a77f6;
case 0x0c0a77f8u: goto P_0c0a77f8;
case 0x0c0a77fau: goto P_0c0a77fa;
case 0x0c0a77fcu: goto P_0c0a77fc;
case 0x0c0a77feu: goto P_0c0a77fe;
case 0x0c0a7800u: goto P_0c0a7800;
case 0x0c0a7802u: goto P_0c0a7802;
case 0x0c0a7804u: goto P_0c0a7804;
case 0x0c0a7806u: goto P_0c0a7806;
case 0x0c0a7808u: goto P_0c0a7808;
case 0x0c0a780au: goto P_0c0a780a;
case 0x0c0a780cu: goto P_0c0a780c;
case 0x0c0a780eu: goto P_0c0a780e;
case 0x0c0a7810u: goto P_0c0a7810;
case 0x0c0a7812u: goto P_0c0a7812;
case 0x0c0a7814u: goto P_0c0a7814;
case 0x0c0a7816u: goto P_0c0a7816;
case 0x0c0a7818u: goto P_0c0a7818;
case 0x0c0a781au: goto P_0c0a781a;
case 0x0c0a781cu: goto P_0c0a781c;
case 0x0c0a781eu: goto P_0c0a781e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03eda0: /* original d431, guest PC 0x0c03eda0 */
if(!s->budget--) { s->failed_pc=0x0c03eda0u; return 0; }
r[4]=read(ram,0x0c03ee68u,4);
goto P_0c03eda2;
P_0c03eda2: /* original e004, guest PC 0x0c03eda2 */
if(!s->budget--) { s->failed_pc=0x0c03eda2u; return 0; }
r[0]=0x00000004u;
goto P_0c03eda4;
P_0c03eda4: /* original f44a, guest PC 0x0c03eda4 */
if(!s->budget--) { s->failed_pc=0x0c03eda4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c03eda6;
P_0c03eda6: /* original f457, guest PC 0x0c03eda6 */
if(!s->budget--) { s->failed_pc=0x0c03eda6u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03eda8;
P_0c03eda8: /* original e008, guest PC 0x0c03eda8 */
if(!s->budget--) { s->failed_pc=0x0c03eda8u; return 0; }
r[0]=0x00000008u;
goto P_0c03edaa;
P_0c03edaa: /* original 000b, guest PC 0x0c03edaa */
if(!s->budget--) { s->failed_pc=0x0c03edaau; return 0; }
target=r[16];
vf3_matrix_store(s,ram,6,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c03edac: /* original f467, guest PC 0x0c03edac */
if(!s->budget--) { s->failed_pc=0x0c03edacu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
if(!vf3_matrix_family(0x0c03edaeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03edaeu; return 0; } return 1;
P_0c055d40: /* original 4f22, guest PC 0x0c055d40 */
if(!s->budget--) { s->failed_pc=0x0c055d40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055d42;
P_0c055d42: /* original d01f, guest PC 0x0c055d42 */
if(!s->budget--) { s->failed_pc=0x0c055d42u; return 0; }
r[0]=read(ram,0x0c055dc0u,4);
goto P_0c055d44;
P_0c055d44: /* original 6102, guest PC 0x0c055d44 */
if(!s->budget--) { s->failed_pc=0x0c055d44u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c055d46;
P_0c055d46: /* original 4115, guest PC 0x0c055d46 */
if(!s->budget--) { s->failed_pc=0x0c055d46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d48;
P_0c055d48: /* original d01c, guest PC 0x0c055d48 */
if(!s->budget--) { s->failed_pc=0x0c055d48u; return 0; }
r[0]=read(ram,0x0c055dbcu,4);
goto P_0c055d4a;
P_0c055d4a: /* original 8d0e, guest PC 0x0c055d4a */
if(!s->budget--) { s->failed_pc=0x0c055d4au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c055d6a; }
goto P_0c055d4e;
P_0c055d4c: /* original 6403, guest PC 0x0c055d4c */
if(!s->budget--) { s->failed_pc=0x0c055d4cu; return 0; }
r[4]=r[0];
goto P_0c055d4e;
P_0c055d4e: /* original 7440, guest PC 0x0c055d4e */
if(!s->budget--) { s->failed_pc=0x0c055d4eu; return 0; }
r[4]+=0x00000040u;
goto P_0c055d50;
P_0c055d50: /* original 6503, guest PC 0x0c055d50 */
if(!s->budget--) { s->failed_pc=0x0c055d50u; return 0; }
r[5]=r[0];
goto P_0c055d52;
P_0c055d52: /* original d31c, guest PC 0x0c055d52 */
if(!s->budget--) { s->failed_pc=0x0c055d52u; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d54;
P_0c055d54: /* original 430b, guest PC 0x0c055d54 */
if(!s->budget--) { s->failed_pc=0x0c055d54u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d58u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d58u) { target=s->pc; goto dispatch; }
goto P_0c055d58;
P_0c055d56: /* original 7568, guest PC 0x0c055d56 */
if(!s->budget--) { s->failed_pc=0x0c055d56u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d58;
P_0c055d58: /* original d01c, guest PC 0x0c055d58 */
if(!s->budget--) { s->failed_pc=0x0c055d58u; return 0; }
r[0]=read(ram,0x0c055dccu,4);
goto P_0c055d5a;
P_0c055d5a: /* original d11f, guest PC 0x0c055d5a */
if(!s->budget--) { s->failed_pc=0x0c055d5au; return 0; }
r[1]=read(ram,0x0c055dd8u,4);
goto P_0c055d5c;
P_0c055d5c: /* original d220, guest PC 0x0c055d5c */
if(!s->budget--) { s->failed_pc=0x0c055d5cu; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055d5e;
P_0c055d5e: /* original c204, guest PC 0x0c055d5e */
if(!s->budget--) { s->failed_pc=0x0c055d5eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055d60;
P_0c055d60: /* original 6013, guest PC 0x0c055d60 */
if(!s->budget--) { s->failed_pc=0x0c055d60u; return 0; }
r[0]=r[1];
goto P_0c055d62;
P_0c055d62: /* original c205, guest PC 0x0c055d62 */
if(!s->budget--) { s->failed_pc=0x0c055d62u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055d64;
P_0c055d64: /* original 6023, guest PC 0x0c055d64 */
if(!s->budget--) { s->failed_pc=0x0c055d64u; return 0; }
r[0]=r[2];
goto P_0c055d66;
P_0c055d66: /* original a025, guest PC 0x0c055d66 */
if(!s->budget--) { s->failed_pc=0x0c055d66u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055d68: /* original c203, guest PC 0x0c055d68 */
if(!s->budget--) { s->failed_pc=0x0c055d68u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055d6a;
P_0c055d6a: /* original 2fe6, guest PC 0x0c055d6a */
if(!s->budget--) { s->failed_pc=0x0c055d6au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6c;
P_0c055d6c: /* original 2fd6, guest PC 0x0c055d6c */
if(!s->budget--) { s->failed_pc=0x0c055d6cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6e;
P_0c055d6e: /* original 6e03, guest PC 0x0c055d6e */
if(!s->budget--) { s->failed_pc=0x0c055d6eu; return 0; }
r[14]=r[0];
goto P_0c055d70;
P_0c055d70: /* original ed10, guest PC 0x0c055d70 */
if(!s->budget--) { s->failed_pc=0x0c055d70u; return 0; }
r[13]=0x00000010u;
goto P_0c055d72;
P_0c055d72: /* original 61e2, guest PC 0x0c055d72 */
if(!s->budget--) { s->failed_pc=0x0c055d72u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c055d74;
P_0c055d74: /* original 4115, guest PC 0x0c055d74 */
if(!s->budget--) { s->failed_pc=0x0c055d74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d76;
P_0c055d76: /* original 8f0b, guest PC 0x0c055d76 */
if(!s->budget--) { s->failed_pc=0x0c055d76u; return 0; }
cond=r[17]&1u;
r[4]=r[14];
if(!cond) { goto P_0c055d90; }
goto P_0c055d7a;
P_0c055d78: /* original 64e3, guest PC 0x0c055d78 */
if(!s->budget--) { s->failed_pc=0x0c055d78u; return 0; }
r[4]=r[14];
goto P_0c055d7a;
P_0c055d7a: /* original 7440, guest PC 0x0c055d7a */
if(!s->budget--) { s->failed_pc=0x0c055d7au; return 0; }
r[4]+=0x00000040u;
goto P_0c055d7c;
P_0c055d7c: /* original 65e3, guest PC 0x0c055d7c */
if(!s->budget--) { s->failed_pc=0x0c055d7cu; return 0; }
r[5]=r[14];
goto P_0c055d7e;
P_0c055d7e: /* original d311, guest PC 0x0c055d7e */
if(!s->budget--) { s->failed_pc=0x0c055d7eu; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d80;
P_0c055d80: /* original 430b, guest PC 0x0c055d80 */
if(!s->budget--) { s->failed_pc=0x0c055d80u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d84u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d84u) { target=s->pc; goto dispatch; }
goto P_0c055d84;
P_0c055d82: /* original 7568, guest PC 0x0c055d82 */
if(!s->budget--) { s->failed_pc=0x0c055d82u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d84;
P_0c055d84: /* original 64e3, guest PC 0x0c055d84 */
if(!s->budget--) { s->failed_pc=0x0c055d84u; return 0; }
r[4]=r[14];
goto P_0c055d86;
P_0c055d86: /* original 7434, guest PC 0x0c055d86 */
if(!s->budget--) { s->failed_pc=0x0c055d86u; return 0; }
r[4]+=0x00000034u;
goto P_0c055d88;
P_0c055d88: /* original 65e3, guest PC 0x0c055d88 */
if(!s->budget--) { s->failed_pc=0x0c055d88u; return 0; }
r[5]=r[14];
goto P_0c055d8a;
P_0c055d8a: /* original d30f, guest PC 0x0c055d8a */
if(!s->budget--) { s->failed_pc=0x0c055d8au; return 0; }
r[3]=read(ram,0x0c055dc8u,4);
goto P_0c055d8c;
P_0c055d8c: /* original 430b, guest PC 0x0c055d8c */
if(!s->budget--) { s->failed_pc=0x0c055d8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c055d90u;
r[5]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d90u) { target=s->pc; goto dispatch; }
goto P_0c055d90;
P_0c055d8e: /* original 755c, guest PC 0x0c055d8e */
if(!s->budget--) { s->failed_pc=0x0c055d8eu; return 0; }
r[5]+=0x0000005cu;
goto P_0c055d90;
P_0c055d90: /* original e3b0, guest PC 0x0c055d90 */
if(!s->budget--) { s->failed_pc=0x0c055d90u; return 0; }
r[3]=0xffffffb0u;
goto P_0c055d92;
P_0c055d92: /* original 623c, guest PC 0x0c055d92 */
if(!s->budget--) { s->failed_pc=0x0c055d92u; return 0; }
r[2]=r[3]&255u;
goto P_0c055d94;
P_0c055d94: /* original 4d10, guest PC 0x0c055d94 */
if(!s->budget--) { s->failed_pc=0x0c055d94u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c055d96;
P_0c055d96: /* original 8fec, guest PC 0x0c055d96 */
if(!s->budget--) { s->failed_pc=0x0c055d96u; return 0; }
cond=r[17]&1u;
r[14]+=r[2];
if(!cond) { goto P_0c055d72; }
goto P_0c055d9a;
P_0c055d98: /* original 3e2c, guest PC 0x0c055d98 */
if(!s->budget--) { s->failed_pc=0x0c055d98u; return 0; }
r[14]+=r[2];
goto P_0c055d9a;
P_0c055d9a: /* original 6df6, guest PC 0x0c055d9a */
if(!s->budget--) { s->failed_pc=0x0c055d9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055d9c;
P_0c055d9c: /* original 6ef6, guest PC 0x0c055d9c */
if(!s->budget--) { s->failed_pc=0x0c055d9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055d9e;
P_0c055d9e: /* original d00c, guest PC 0x0c055d9e */
if(!s->budget--) { s->failed_pc=0x0c055d9eu; return 0; }
r[0]=read(ram,0x0c055dd0u,4);
goto P_0c055da0;
P_0c055da0: /* original e380, guest PC 0x0c055da0 */
if(!s->budget--) { s->failed_pc=0x0c055da0u; return 0; }
r[3]=0xffffff80u;
goto P_0c055da2;
P_0c055da2: /* original d10e, guest PC 0x0c055da2 */
if(!s->budget--) { s->failed_pc=0x0c055da2u; return 0; }
r[1]=read(ram,0x0c055ddcu,4);
goto P_0c055da4;
P_0c055da4: /* original 633c, guest PC 0x0c055da4 */
if(!s->budget--) { s->failed_pc=0x0c055da4u; return 0; }
r[3]=r[3]&255u;
goto P_0c055da6;
P_0c055da6: /* original d20e, guest PC 0x0c055da6 */
if(!s->budget--) { s->failed_pc=0x0c055da6u; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055da8;
P_0c055da8: /* original c204, guest PC 0x0c055da8 */
if(!s->budget--) { s->failed_pc=0x0c055da8u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055daa;
P_0c055daa: /* original 6013, guest PC 0x0c055daa */
if(!s->budget--) { s->failed_pc=0x0c055daau; return 0; }
r[0]=r[1];
goto P_0c055dac;
P_0c055dac: /* original c205, guest PC 0x0c055dac */
if(!s->budget--) { s->failed_pc=0x0c055dacu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055dae;
P_0c055dae: /* original 6023, guest PC 0x0c055dae */
if(!s->budget--) { s->failed_pc=0x0c055daeu; return 0; }
r[0]=r[2];
goto P_0c055db0;
P_0c055db0: /* original 303c, guest PC 0x0c055db0 */
if(!s->budget--) { s->failed_pc=0x0c055db0u; return 0; }
r[0]+=r[3];
goto P_0c055db2;
P_0c055db2: /* original c203, guest PC 0x0c055db2 */
if(!s->budget--) { s->failed_pc=0x0c055db2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055db4: /* original 4f26, guest PC 0x0c055db4 */
if(!s->budget--) { s->failed_pc=0x0c055db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055db6;
P_0c055db6: /* original 000b, guest PC 0x0c055db6 */
if(!s->budget--) { s->failed_pc=0x0c055db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055db8: /* original 0009, guest PC 0x0c055db8 */
if(!s->budget--) { s->failed_pc=0x0c055db8u; return 0; }
if(!vf3_matrix_family(0x0c055dbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055dbau; return 0; } return 1;
P_0c05e1b2: /* original 4f22, guest PC 0x0c05e1b2 */
if(!s->budget--) { s->failed_pc=0x0c05e1b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e1b4;
P_0c05e1b4: /* original 9461, guest PC 0x0c05e1b4 */
if(!s->budget--) { s->failed_pc=0x0c05e1b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e27au,2);
goto P_0c05e1b6;
P_0c05e1b6: /* original d339, guest PC 0x0c05e1b6 */
if(!s->budget--) { s->failed_pc=0x0c05e1b6u; return 0; }
r[3]=read(ram,0x0c05e29cu,4);
goto P_0c05e1b8;
P_0c05e1b8: /* original 430b, guest PC 0x0c05e1b8 */
if(!s->budget--) { s->failed_pc=0x0c05e1b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e1bcu;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e1bcu) { target=s->pc; goto dispatch; }
goto P_0c05e1bc;
P_0c05e1ba: /* original 55f1, guest PC 0x0c05e1ba */
if(!s->budget--) { s->failed_pc=0x0c05e1bau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e1bc;
P_0c05e1bc: /* original 4f26, guest PC 0x0c05e1bc */
if(!s->budget--) { s->failed_pc=0x0c05e1bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e1be;
P_0c05e1be: /* original 000b, guest PC 0x0c05e1be */
if(!s->budget--) { s->failed_pc=0x0c05e1beu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e1c0: /* original e000, guest PC 0x0c05e1c0 */
if(!s->budget--) { s->failed_pc=0x0c05e1c0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c05e1c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e1c2u; return 0; } return 1;
P_0c05e3d6: /* original 6353, guest PC 0x0c05e3d6 */
if(!s->budget--) { s->failed_pc=0x0c05e3d6u; return 0; }
r[3]=r[5];
goto P_0c05e3d8;
P_0c05e3d8: /* original d011, guest PC 0x0c05e3d8 */
if(!s->budget--) { s->failed_pc=0x0c05e3d8u; return 0; }
r[0]=read(ram,0x0c05e420u,4);
goto P_0c05e3da;
P_0c05e3da: /* original 4308, guest PC 0x0c05e3da */
if(!s->budget--) { s->failed_pc=0x0c05e3dau; return 0; }
r[3]<<=2;
goto P_0c05e3dc;
P_0c05e3dc: /* original 4f22, guest PC 0x0c05e3dc */
if(!s->budget--) { s->failed_pc=0x0c05e3dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e3de;
P_0c05e3de: /* original 7ffc, guest PC 0x0c05e3de */
if(!s->budget--) { s->failed_pc=0x0c05e3deu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05e3e0;
P_0c05e3e0: /* original 2f52, guest PC 0x0c05e3e0 */
if(!s->budget--) { s->failed_pc=0x0c05e3e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05e3e2;
P_0c05e3e2: /* original 033e, guest PC 0x0c05e3e2 */
if(!s->budget--) { s->failed_pc=0x0c05e3e2u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05e3e4;
P_0c05e3e4: /* original 430b, guest PC 0x0c05e3e4 */
if(!s->budget--) { s->failed_pc=0x0c05e3e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e3e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e3e8u) { target=s->pc; goto dispatch; }
goto P_0c05e3e8;
P_0c05e3e6: /* original 0009, guest PC 0x0c05e3e6 */
if(!s->budget--) { s->failed_pc=0x0c05e3e6u; return 0; }
goto P_0c05e3e8;
P_0c05e3e8: /* original d30e, guest PC 0x0c05e3e8 */
if(!s->budget--) { s->failed_pc=0x0c05e3e8u; return 0; }
r[3]=read(ram,0x0c05e424u,4);
goto P_0c05e3ea;
P_0c05e3ea: /* original d20f, guest PC 0x0c05e3ea */
if(!s->budget--) { s->failed_pc=0x0c05e3eau; return 0; }
r[2]=read(ram,0x0c05e428u,4);
goto P_0c05e3ec;
P_0c05e3ec: /* original 6132, guest PC 0x0c05e3ec */
if(!s->budget--) { s->failed_pc=0x0c05e3ecu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05e3ee;
P_0c05e3ee: /* original 2129, guest PC 0x0c05e3ee */
if(!s->budget--) { s->failed_pc=0x0c05e3eeu; return 0; }
r[1]&=r[2];
goto P_0c05e3f0;
P_0c05e3f0: /* original 2312, guest PC 0x0c05e3f0 */
if(!s->budget--) { s->failed_pc=0x0c05e3f0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05e3f2;
P_0c05e3f2: /* original 7f04, guest PC 0x0c05e3f2 */
if(!s->budget--) { s->failed_pc=0x0c05e3f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c05e3f4;
P_0c05e3f4: /* original 4f26, guest PC 0x0c05e3f4 */
if(!s->budget--) { s->failed_pc=0x0c05e3f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e3f6;
P_0c05e3f6: /* original 000b, guest PC 0x0c05e3f6 */
if(!s->budget--) { s->failed_pc=0x0c05e3f6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05e3f8: /* original 0009, guest PC 0x0c05e3f8 */
if(!s->budget--) { s->failed_pc=0x0c05e3f8u; return 0; }
if(!vf3_matrix_family(0x0c05e3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e3fau; return 0; } return 1;
P_0c060d14: /* original d344, guest PC 0x0c060d14 */
if(!s->budget--) { s->failed_pc=0x0c060d14u; return 0; }
r[3]=read(ram,0x0c060e28u,4);
goto P_0c060d16;
P_0c060d16: /* original 343c, guest PC 0x0c060d16 */
if(!s->budget--) { s->failed_pc=0x0c060d16u; return 0; }
r[4]+=r[3];
goto P_0c060d18;
P_0c060d18: /* original 2452, guest PC 0x0c060d18 */
if(!s->budget--) { s->failed_pc=0x0c060d18u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c060d1a;
P_0c060d1a: /* original 000b, guest PC 0x0c060d1a */
if(!s->budget--) { s->failed_pc=0x0c060d1au; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060d1c: /* original e001, guest PC 0x0c060d1c */
if(!s->budget--) { s->failed_pc=0x0c060d1cu; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c060d1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d1eu; return 0; } return 1;
P_0c0955b0: /* original 4f22, guest PC 0x0c0955b0 */
if(!s->budget--) { s->failed_pc=0x0c0955b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0955b2;
P_0c0955b2: /* original 7ff0, guest PC 0x0c0955b2 */
if(!s->budget--) { s->failed_pc=0x0c0955b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0955b4;
P_0c0955b4: /* original 1f42, guest PC 0x0c0955b4 */
if(!s->budget--) { s->failed_pc=0x0c0955b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0955b6;
P_0c0955b6: /* original 1f51, guest PC 0x0c0955b6 */
if(!s->budget--) { s->failed_pc=0x0c0955b6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0955b8;
P_0c0955b8: /* original 2f62, guest PC 0x0c0955b8 */
if(!s->budget--) { s->failed_pc=0x0c0955b8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0955ba;
P_0c0955ba: /* original 1f73, guest PC 0x0c0955ba */
if(!s->budget--) { s->failed_pc=0x0c0955bau; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0955bc;
P_0c0955bc: /* original d34e, guest PC 0x0c0955bc */
if(!s->budget--) { s->failed_pc=0x0c0955bcu; return 0; }
r[3]=read(ram,0x0c0956f8u,4);
goto P_0c0955be;
P_0c0955be: /* original 430b, guest PC 0x0c0955be */
if(!s->budget--) { s->failed_pc=0x0c0955beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0955c2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c2u) { target=s->pc; goto dispatch; }
goto P_0c0955c2;
P_0c0955c0: /* original e400, guest PC 0x0c0955c0 */
if(!s->budget--) { s->failed_pc=0x0c0955c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0955c2;
P_0c0955c2: /* original d24e, guest PC 0x0c0955c2 */
if(!s->budget--) { s->failed_pc=0x0c0955c2u; return 0; }
r[2]=read(ram,0x0c0956fcu,4);
goto P_0c0955c4;
P_0c0955c4: /* original 420b, guest PC 0x0c0955c4 */
if(!s->budget--) { s->failed_pc=0x0c0955c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0955c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c8u) { target=s->pc; goto dispatch; }
goto P_0c0955c8;
P_0c0955c6: /* original 0009, guest PC 0x0c0955c6 */
if(!s->budget--) { s->failed_pc=0x0c0955c6u; return 0; }
goto P_0c0955c8;
P_0c0955c8: /* original d34d, guest PC 0x0c0955c8 */
if(!s->budget--) { s->failed_pc=0x0c0955c8u; return 0; }
r[3]=read(ram,0x0c095700u,4);
goto P_0c0955ca;
P_0c0955ca: /* original 430b, guest PC 0x0c0955ca */
if(!s->budget--) { s->failed_pc=0x0c0955cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0955ceu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955ceu) { target=s->pc; goto dispatch; }
goto P_0c0955ce;
P_0c0955cc: /* original 54f6, guest PC 0x0c0955cc */
if(!s->budget--) { s->failed_pc=0x0c0955ccu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0955ce;
P_0c0955ce: /* original d34d, guest PC 0x0c0955ce */
if(!s->budget--) { s->failed_pc=0x0c0955ceu; return 0; }
r[3]=read(ram,0x0c095704u,4);
goto P_0c0955d0;
P_0c0955d0: /* original 430b, guest PC 0x0c0955d0 */
if(!s->budget--) { s->failed_pc=0x0c0955d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955d4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955d4u) { target=s->pc; goto dispatch; }
goto P_0c0955d4;
P_0c0955d2: /* original 54f5, guest PC 0x0c0955d2 */
if(!s->budget--) { s->failed_pc=0x0c0955d2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0955d4;
P_0c0955d4: /* original d34c, guest PC 0x0c0955d4 */
if(!s->budget--) { s->failed_pc=0x0c0955d4u; return 0; }
r[3]=read(ram,0x0c095708u,4);
goto P_0c0955d6;
P_0c0955d6: /* original 430b, guest PC 0x0c0955d6 */
if(!s->budget--) { s->failed_pc=0x0c0955d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955dau;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955dau) { target=s->pc; goto dispatch; }
goto P_0c0955da;
P_0c0955d8: /* original 54f3, guest PC 0x0c0955d8 */
if(!s->budget--) { s->failed_pc=0x0c0955d8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0955da;
P_0c0955da: /* original d24c, guest PC 0x0c0955da */
if(!s->budget--) { s->failed_pc=0x0c0955dau; return 0; }
r[2]=read(ram,0x0c09570cu,4);
goto P_0c0955dc;
P_0c0955dc: /* original 420b, guest PC 0x0c0955dc */
if(!s->budget--) { s->failed_pc=0x0c0955dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0955e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955e0u) { target=s->pc; goto dispatch; }
goto P_0c0955e0;
P_0c0955de: /* original e400, guest PC 0x0c0955de */
if(!s->budget--) { s->failed_pc=0x0c0955deu; return 0; }
r[4]=0x00000000u;
goto P_0c0955e0;
P_0c0955e0: /* original 6403, guest PC 0x0c0955e0 */
if(!s->budget--) { s->failed_pc=0x0c0955e0u; return 0; }
r[4]=r[0];
goto P_0c0955e2;
P_0c0955e2: /* original e020, guest PC 0x0c0955e2 */
if(!s->budget--) { s->failed_pc=0x0c0955e2u; return 0; }
r[0]=0x00000020u;
goto P_0c0955e4;
P_0c0955e4: /* original f346, guest PC 0x0c0955e4 */
if(!s->budget--) { s->failed_pc=0x0c0955e4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955e6;
P_0c0955e6: /* original e024, guest PC 0x0c0955e6 */
if(!s->budget--) { s->failed_pc=0x0c0955e6u; return 0; }
r[0]=0x00000024u;
goto P_0c0955e8;
P_0c0955e8: /* original 53f2, guest PC 0x0c0955e8 */
if(!s->budget--) { s->failed_pc=0x0c0955e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0955ea;
P_0c0955ea: /* original f33a, guest PC 0x0c0955ea */
if(!s->budget--) { s->failed_pc=0x0c0955eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955ec;
P_0c0955ec: /* original f346, guest PC 0x0c0955ec */
if(!s->budget--) { s->failed_pc=0x0c0955ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955ee;
P_0c0955ee: /* original e028, guest PC 0x0c0955ee */
if(!s->budget--) { s->failed_pc=0x0c0955eeu; return 0; }
r[0]=0x00000028u;
goto P_0c0955f0;
P_0c0955f0: /* original 53f1, guest PC 0x0c0955f0 */
if(!s->budget--) { s->failed_pc=0x0c0955f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0955f2;
P_0c0955f2: /* original f33a, guest PC 0x0c0955f2 */
if(!s->budget--) { s->failed_pc=0x0c0955f2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955f4;
P_0c0955f4: /* original f346, guest PC 0x0c0955f4 */
if(!s->budget--) { s->failed_pc=0x0c0955f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955f6;
P_0c0955f6: /* original e401, guest PC 0x0c0955f6 */
if(!s->budget--) { s->failed_pc=0x0c0955f6u; return 0; }
r[4]=0x00000001u;
goto P_0c0955f8;
P_0c0955f8: /* original 63f2, guest PC 0x0c0955f8 */
if(!s->budget--) { s->failed_pc=0x0c0955f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0955fa;
P_0c0955fa: /* original 7f10, guest PC 0x0c0955fa */
if(!s->budget--) { s->failed_pc=0x0c0955fau; return 0; }
r[15]+=0x00000010u;
goto P_0c0955fc;
P_0c0955fc: /* original f33a, guest PC 0x0c0955fc */
if(!s->budget--) { s->failed_pc=0x0c0955fcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955fe;
P_0c0955fe: /* original d344, guest PC 0x0c0955fe */
if(!s->budget--) { s->failed_pc=0x0c0955feu; return 0; }
r[3]=read(ram,0x0c095710u,4);
goto P_0c095600;
P_0c095600: /* original 432b, guest PC 0x0c095600 */
if(!s->budget--) { s->failed_pc=0x0c095600u; return 0; }
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
P_0c095602: /* original 4f26, guest PC 0x0c095602 */
if(!s->budget--) { s->failed_pc=0x0c095602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c095604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095604u; return 0; } return 1;
P_0c0a7784: /* original 2fe6, guest PC 0x0c0a7784 */
if(!s->budget--) { s->failed_pc=0x0c0a7784u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7786;
P_0c0a7786: /* original 904b, guest PC 0x0c0a7786 */
if(!s->budget--) { s->failed_pc=0x0c0a7786u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7820u,2);
goto P_0c0a7788;
P_0c0a7788: /* original de2f, guest PC 0x0c0a7788 */
if(!s->budget--) { s->failed_pc=0x0c0a7788u; return 0; }
r[14]=read(ram,0x0c0a7848u,4);
goto P_0c0a778a;
P_0c0a778a: /* original 05ee, guest PC 0x0c0a778a */
if(!s->budget--) { s->failed_pc=0x0c0a778au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a778c;
P_0c0a778c: /* original 70fc, guest PC 0x0c0a778c */
if(!s->budget--) { s->failed_pc=0x0c0a778cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0a778e;
P_0c0a778e: /* original 04ee, guest PC 0x0c0a778e */
if(!s->budget--) { s->failed_pc=0x0c0a778eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a7790;
P_0c0a7790: /* original a000, guest PC 0x0c0a7790 */
if(!s->budget--) { s->failed_pc=0x0c0a7790u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7794;
P_0c0a7792: /* original 6ef6, guest PC 0x0c0a7792 */
if(!s->budget--) { s->failed_pc=0x0c0a7792u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7794;
P_0c0a7794: /* original 2fe6, guest PC 0x0c0a7794 */
if(!s->budget--) { s->failed_pc=0x0c0a7794u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7796;
P_0c0a7796: /* original 6e43, guest PC 0x0c0a7796 */
if(!s->budget--) { s->failed_pc=0x0c0a7796u; return 0; }
r[14]=r[4];
goto P_0c0a7798;
P_0c0a7798: /* original 4f22, guest PC 0x0c0a7798 */
if(!s->budget--) { s->failed_pc=0x0c0a7798u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a779a;
P_0c0a779a: /* original 2ee8, guest PC 0x0c0a779a */
if(!s->budget--) { s->failed_pc=0x0c0a779au; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a779c;
P_0c0a779c: /* original 7ffc, guest PC 0x0c0a779c */
if(!s->budget--) { s->failed_pc=0x0c0a779cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a779e;
P_0c0a779e: /* original 8d1a, guest PC 0x0c0a779e */
if(!s->budget--) { s->failed_pc=0x0c0a779eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[5],4);
if(cond) { goto P_0c0a77d6; }
goto P_0c0a77a2;
P_0c0a77a0: /* original 2f52, guest PC 0x0c0a77a0 */
if(!s->budget--) { s->failed_pc=0x0c0a77a0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a77a2;
P_0c0a77a2: /* original e024, guest PC 0x0c0a77a2 */
if(!s->budget--) { s->failed_pc=0x0c0a77a2u; return 0; }
r[0]=0x00000024u;
goto P_0c0a77a4;
P_0c0a77a4: /* original f5e6, guest PC 0x0c0a77a4 */
if(!s->budget--) { s->failed_pc=0x0c0a77a4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a77a6;
P_0c0a77a6: /* original e01c, guest PC 0x0c0a77a6 */
if(!s->budget--) { s->failed_pc=0x0c0a77a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a77a8;
P_0c0a77a8: /* original f4e6, guest PC 0x0c0a77a8 */
if(!s->budget--) { s->failed_pc=0x0c0a77a8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a77aa;
P_0c0a77aa: /* original 84e7, guest PC 0x0c0a77aa */
if(!s->budget--) { s->failed_pc=0x0c0a77aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c0a77ac;
P_0c0a77ac: /* original 660c, guest PC 0x0c0a77ac */
if(!s->budget--) { s->failed_pc=0x0c0a77acu; return 0; }
r[6]=r[0]&255u;
goto P_0c0a77ae;
P_0c0a77ae: /* original 84e6, guest PC 0x0c0a77ae */
if(!s->budget--) { s->failed_pc=0x0c0a77aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+6,1);
goto P_0c0a77b0;
P_0c0a77b0: /* original 650c, guest PC 0x0c0a77b0 */
if(!s->budget--) { s->failed_pc=0x0c0a77b0u; return 0; }
r[5]=r[0]&255u;
goto P_0c0a77b2;
P_0c0a77b2: /* original 84e5, guest PC 0x0c0a77b2 */
if(!s->budget--) { s->failed_pc=0x0c0a77b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c0a77b4;
P_0c0a77b4: /* original b12a, guest PC 0x0c0a77b4 */
if(!s->budget--) { s->failed_pc=0x0c0a77b4u; return 0; }
target=code_base|0x0c0a7a0cu; r[16]=code_base|0x0c0a77b8u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a77b8u) { target=s->pc; goto dispatch; }
goto P_0c0a77b8;
P_0c0a77b6: /* original 640c, guest PC 0x0c0a77b6 */
if(!s->budget--) { s->failed_pc=0x0c0a77b6u; return 0; }
r[4]=r[0]&255u;
goto P_0c0a77b8;
P_0c0a77b8: /* original 64f2, guest PC 0x0c0a77b8 */
if(!s->budget--) { s->failed_pc=0x0c0a77b8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a77ba;
P_0c0a77ba: /* original e010, guest PC 0x0c0a77ba */
if(!s->budget--) { s->failed_pc=0x0c0a77bau; return 0; }
r[0]=0x00000010u;
goto P_0c0a77bc;
P_0c0a77bc: /* original f5e6, guest PC 0x0c0a77bc */
if(!s->budget--) { s->failed_pc=0x0c0a77bcu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a77be;
P_0c0a77be: /* original 044c, guest PC 0x0c0a77be */
if(!s->budget--) { s->failed_pc=0x0c0a77beu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a77c0;
P_0c0a77c0: /* original e014, guest PC 0x0c0a77c0 */
if(!s->budget--) { s->failed_pc=0x0c0a77c0u; return 0; }
r[0]=0x00000014u;
goto P_0c0a77c2;
P_0c0a77c2: /* original b0a1, guest PC 0x0c0a77c2 */
if(!s->budget--) { s->failed_pc=0x0c0a77c2u; return 0; }
target=code_base|0x0c0a7908u; r[16]=code_base|0x0c0a77c6u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a77c6u) { target=s->pc; goto dispatch; }
goto P_0c0a77c6;
P_0c0a77c4: /* original f4e6, guest PC 0x0c0a77c4 */
if(!s->budget--) { s->failed_pc=0x0c0a77c4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a77c6;
P_0c0a77c6: /* original 85e7, guest PC 0x0c0a77c6 */
if(!s->budget--) { s->failed_pc=0x0c0a77c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a77c8;
P_0c0a77c8: /* original 7f04, guest PC 0x0c0a77c8 */
if(!s->budget--) { s->failed_pc=0x0c0a77c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a77ca;
P_0c0a77ca: /* original 4f26, guest PC 0x0c0a77ca */
if(!s->budget--) { s->failed_pc=0x0c0a77cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a77cc;
P_0c0a77cc: /* original 6503, guest PC 0x0c0a77cc */
if(!s->budget--) { s->failed_pc=0x0c0a77ccu; return 0; }
r[5]=r[0];
goto P_0c0a77ce;
P_0c0a77ce: /* original 85e6, guest PC 0x0c0a77ce */
if(!s->budget--) { s->failed_pc=0x0c0a77ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a77d0;
P_0c0a77d0: /* original 6403, guest PC 0x0c0a77d0 */
if(!s->budget--) { s->failed_pc=0x0c0a77d0u; return 0; }
r[4]=r[0];
goto P_0c0a77d2;
P_0c0a77d2: /* original a006, guest PC 0x0c0a77d2 */
if(!s->budget--) { s->failed_pc=0x0c0a77d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a77e2;
P_0c0a77d4: /* original 6ef6, guest PC 0x0c0a77d4 */
if(!s->budget--) { s->failed_pc=0x0c0a77d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a77d6;
P_0c0a77d6: /* original 7f04, guest PC 0x0c0a77d6 */
if(!s->budget--) { s->failed_pc=0x0c0a77d6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a77d8;
P_0c0a77d8: /* original 4f26, guest PC 0x0c0a77d8 */
if(!s->budget--) { s->failed_pc=0x0c0a77d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a77da;
P_0c0a77da: /* original 000b, guest PC 0x0c0a77da */
if(!s->budget--) { s->failed_pc=0x0c0a77dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a77dc: /* original 6ef6, guest PC 0x0c0a77dc */
if(!s->budget--) { s->failed_pc=0x0c0a77dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a77deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a77deu; return 0; } return 1;
P_0c0a77e2: /* original 4f22, guest PC 0x0c0a77e2 */
if(!s->budget--) { s->failed_pc=0x0c0a77e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a77e4;
P_0c0a77e4: /* original 6043, guest PC 0x0c0a77e4 */
if(!s->budget--) { s->failed_pc=0x0c0a77e4u; return 0; }
r[0]=r[4];
goto P_0c0a77e6;
P_0c0a77e6: /* original e300, guest PC 0x0c0a77e6 */
if(!s->budget--) { s->failed_pc=0x0c0a77e6u; return 0; }
r[3]=0x00000000u;
goto P_0c0a77e8;
P_0c0a77e8: /* original 7fec, guest PC 0x0c0a77e8 */
if(!s->budget--) { s->failed_pc=0x0c0a77e8u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0a77ea;
P_0c0a77ea: /* original 81f6, guest PC 0x0c0a77ea */
if(!s->budget--) { s->failed_pc=0x0c0a77eau; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0a77ec;
P_0c0a77ec: /* original 6053, guest PC 0x0c0a77ec */
if(!s->budget--) { s->failed_pc=0x0c0a77ecu; return 0; }
r[0]=r[5];
goto P_0c0a77ee;
P_0c0a77ee: /* original 81f8, guest PC 0x0c0a77ee */
if(!s->budget--) { s->failed_pc=0x0c0a77eeu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0a77f0;
P_0c0a77f0: /* original 2f36, guest PC 0x0c0a77f0 */
if(!s->budget--) { s->failed_pc=0x0c0a77f0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a77f2;
P_0c0a77f2: /* original 85fa, guest PC 0x0c0a77f2 */
if(!s->budget--) { s->failed_pc=0x0c0a77f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0a77f4;
P_0c0a77f4: /* original 2f06, guest PC 0x0c0a77f4 */
if(!s->budget--) { s->failed_pc=0x0c0a77f4u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a77f6;
P_0c0a77f6: /* original 85fa, guest PC 0x0c0a77f6 */
if(!s->budget--) { s->failed_pc=0x0c0a77f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0a77f8;
P_0c0a77f8: /* original 65f3, guest PC 0x0c0a77f8 */
if(!s->budget--) { s->failed_pc=0x0c0a77f8u; return 0; }
r[5]=r[15];
goto P_0c0a77fa;
P_0c0a77fa: /* original 66f3, guest PC 0x0c0a77fa */
if(!s->budget--) { s->failed_pc=0x0c0a77fau; return 0; }
r[6]=r[15];
goto P_0c0a77fc;
P_0c0a77fc: /* original d213, guest PC 0x0c0a77fc */
if(!s->budget--) { s->failed_pc=0x0c0a77fcu; return 0; }
r[2]=read(ram,0x0c0a784cu,4);
goto P_0c0a77fe;
P_0c0a77fe: /* original 64f3, guest PC 0x0c0a77fe */
if(!s->budget--) { s->failed_pc=0x0c0a77feu; return 0; }
r[4]=r[15];
goto P_0c0a7800;
P_0c0a7800: /* original 750c, guest PC 0x0c0a7800 */
if(!s->budget--) { s->failed_pc=0x0c0a7800u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0a7802;
P_0c0a7802: /* original 6703, guest PC 0x0c0a7802 */
if(!s->budget--) { s->failed_pc=0x0c0a7802u; return 0; }
r[7]=r[0];
goto P_0c0a7804;
P_0c0a7804: /* original 7610, guest PC 0x0c0a7804 */
if(!s->budget--) { s->failed_pc=0x0c0a7804u; return 0; }
r[6]+=0x00000010u;
goto P_0c0a7806;
P_0c0a7806: /* original 420b, guest PC 0x0c0a7806 */
if(!s->budget--) { s->failed_pc=0x0c0a7806u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a780au;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a780au) { target=s->pc; goto dispatch; }
goto P_0c0a780a;
P_0c0a7808: /* original 7408, guest PC 0x0c0a7808 */
if(!s->budget--) { s->failed_pc=0x0c0a7808u; return 0; }
r[4]+=0x00000008u;
goto P_0c0a780a;
P_0c0a780a: /* original e010, guest PC 0x0c0a780a */
if(!s->budget--) { s->failed_pc=0x0c0a780au; return 0; }
r[0]=0x00000010u;
goto P_0c0a780c;
P_0c0a780c: /* original f6f6, guest PC 0x0c0a780c */
if(!s->budget--) { s->failed_pc=0x0c0a780cu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0a780e;
P_0c0a780e: /* original e00c, guest PC 0x0c0a780e */
if(!s->budget--) { s->failed_pc=0x0c0a780eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a7810;
P_0c0a7810: /* original f5f6, guest PC 0x0c0a7810 */
if(!s->budget--) { s->failed_pc=0x0c0a7810u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a7812;
P_0c0a7812: /* original e008, guest PC 0x0c0a7812 */
if(!s->budget--) { s->failed_pc=0x0c0a7812u; return 0; }
r[0]=0x00000008u;
goto P_0c0a7814;
P_0c0a7814: /* original b01c, guest PC 0x0c0a7814 */
if(!s->budget--) { s->failed_pc=0x0c0a7814u; return 0; }
target=code_base|0x0c0a7850u; r[16]=code_base|0x0c0a7818u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7818u) { target=s->pc; goto dispatch; }
goto P_0c0a7818;
P_0c0a7816: /* original f4f6, guest PC 0x0c0a7816 */
if(!s->budget--) { s->failed_pc=0x0c0a7816u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0a7818;
P_0c0a7818: /* original 7f1c, guest PC 0x0c0a7818 */
if(!s->budget--) { s->failed_pc=0x0c0a7818u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0a781a;
P_0c0a781a: /* original 4f26, guest PC 0x0c0a781a */
if(!s->budget--) { s->failed_pc=0x0c0a781au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a781c;
P_0c0a781c: /* original 000b, guest PC 0x0c0a781c */
if(!s->budget--) { s->failed_pc=0x0c0a781cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a781e: /* original 0009, guest PC 0x0c0a781e */
if(!s->budget--) { s->failed_pc=0x0c0a781eu; return 0; }
if(!vf3_matrix_family(0x0c0a7820u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7820u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
