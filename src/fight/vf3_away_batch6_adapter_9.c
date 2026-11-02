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
int vf3_away_batch6_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c045b78u: goto P_0c045b78;
case 0x0c045b7au: goto P_0c045b7a;
case 0x0c045b7cu: goto P_0c045b7c;
case 0x0c045b7eu: goto P_0c045b7e;
case 0x0c045b80u: goto P_0c045b80;
case 0x0c045b82u: goto P_0c045b82;
case 0x0c045b84u: goto P_0c045b84;
case 0x0c045b86u: goto P_0c045b86;
case 0x0c045b88u: goto P_0c045b88;
case 0x0c045b8au: goto P_0c045b8a;
case 0x0c045b8cu: goto P_0c045b8c;
case 0x0c045b8eu: goto P_0c045b8e;
case 0x0c045b90u: goto P_0c045b90;
case 0x0c045b92u: goto P_0c045b92;
case 0x0c045b94u: goto P_0c045b94;
case 0x0c045b96u: goto P_0c045b96;
case 0x0c045b98u: goto P_0c045b98;
case 0x0c045b9au: goto P_0c045b9a;
case 0x0c045b9cu: goto P_0c045b9c;
case 0x0c045b9eu: goto P_0c045b9e;
case 0x0c045ba0u: goto P_0c045ba0;
case 0x0c045ba2u: goto P_0c045ba2;
case 0x0c045ba4u: goto P_0c045ba4;
case 0x0c045ba6u: goto P_0c045ba6;
case 0x0c045ba8u: goto P_0c045ba8;
case 0x0c045baau: goto P_0c045baa;
case 0x0c045bacu: goto P_0c045bac;
case 0x0c045baeu: goto P_0c045bae;
case 0x0c045bb0u: goto P_0c045bb0;
case 0x0c045bb2u: goto P_0c045bb2;
case 0x0c045bb4u: goto P_0c045bb4;
case 0x0c045bb6u: goto P_0c045bb6;
case 0x0c045bb8u: goto P_0c045bb8;
case 0x0c045bbau: goto P_0c045bba;
case 0x0c045bbcu: goto P_0c045bbc;
case 0x0c045bbeu: goto P_0c045bbe;
case 0x0c045bc0u: goto P_0c045bc0;
case 0x0c045bc2u: goto P_0c045bc2;
case 0x0c045bc4u: goto P_0c045bc4;
case 0x0c045bc6u: goto P_0c045bc6;
case 0x0c045bc8u: goto P_0c045bc8;
case 0x0c045bcau: goto P_0c045bca;
case 0x0c045bccu: goto P_0c045bcc;
case 0x0c045bceu: goto P_0c045bce;
case 0x0c045bd0u: goto P_0c045bd0;
case 0x0c045bd2u: goto P_0c045bd2;
case 0x0c045bd4u: goto P_0c045bd4;
case 0x0c045bd6u: goto P_0c045bd6;
case 0x0c045bd8u: goto P_0c045bd8;
case 0x0c045bdau: goto P_0c045bda;
case 0x0c045bdcu: goto P_0c045bdc;
case 0x0c045bdeu: goto P_0c045bde;
case 0x0c045be0u: goto P_0c045be0;
case 0x0c045be2u: goto P_0c045be2;
case 0x0c045be4u: goto P_0c045be4;
case 0x0c045be6u: goto P_0c045be6;
case 0x0c045be8u: goto P_0c045be8;
case 0x0c045beau: goto P_0c045bea;
case 0x0c045becu: goto P_0c045bec;
case 0x0c045beeu: goto P_0c045bee;
case 0x0c045bf0u: goto P_0c045bf0;
case 0x0c045bf2u: goto P_0c045bf2;
case 0x0c045bf4u: goto P_0c045bf4;
case 0x0c045bf6u: goto P_0c045bf6;
case 0x0c045bf8u: goto P_0c045bf8;
case 0x0c045bfau: goto P_0c045bfa;
case 0x0c045bfcu: goto P_0c045bfc;
case 0x0c045bfeu: goto P_0c045bfe;
case 0x0c045c00u: goto P_0c045c00;
case 0x0c045c02u: goto P_0c045c02;
case 0x0c045c04u: goto P_0c045c04;
case 0x0c045c06u: goto P_0c045c06;
case 0x0c045c08u: goto P_0c045c08;
case 0x0c045c0au: goto P_0c045c0a;
case 0x0c045c0cu: goto P_0c045c0c;
case 0x0c045c0eu: goto P_0c045c0e;
case 0x0c045c10u: goto P_0c045c10;
case 0x0c045c12u: goto P_0c045c12;
case 0x0c045c14u: goto P_0c045c14;
case 0x0c045c16u: goto P_0c045c16;
case 0x0c045c18u: goto P_0c045c18;
case 0x0c045c1au: goto P_0c045c1a;
case 0x0c045c1cu: goto P_0c045c1c;
case 0x0c045c1eu: goto P_0c045c1e;
case 0x0c045c20u: goto P_0c045c20;
case 0x0c045c22u: goto P_0c045c22;
case 0x0c045c24u: goto P_0c045c24;
case 0x0c045c26u: goto P_0c045c26;
case 0x0c045c28u: goto P_0c045c28;
case 0x0c045ef4u: goto P_0c045ef4;
case 0x0c045ef6u: goto P_0c045ef6;
case 0x0c045ef8u: goto P_0c045ef8;
case 0x0c045efau: goto P_0c045efa;
case 0x0c045efcu: goto P_0c045efc;
case 0x0c045efeu: goto P_0c045efe;
case 0x0c045f00u: goto P_0c045f00;
case 0x0c045f02u: goto P_0c045f02;
case 0x0c045f04u: goto P_0c045f04;
case 0x0c045f06u: goto P_0c045f06;
case 0x0c045f08u: goto P_0c045f08;
case 0x0c04b9e4u: goto P_0c04b9e4;
case 0x0c04b9e6u: goto P_0c04b9e6;
case 0x0c04b9e8u: goto P_0c04b9e8;
case 0x0c04b9eau: goto P_0c04b9ea;
case 0x0c04b9ecu: goto P_0c04b9ec;
case 0x0c04b9eeu: goto P_0c04b9ee;
case 0x0c04b9f0u: goto P_0c04b9f0;
case 0x0c04b9f2u: goto P_0c04b9f2;
case 0x0c04b9f4u: goto P_0c04b9f4;
case 0x0c04b9f6u: goto P_0c04b9f6;
case 0x0c04b9f8u: goto P_0c04b9f8;
case 0x0c04b9fau: goto P_0c04b9fa;
case 0x0c04c5a0u: goto P_0c04c5a0;
case 0x0c04c5a2u: goto P_0c04c5a2;
case 0x0c04c5a4u: goto P_0c04c5a4;
case 0x0c04c5a6u: goto P_0c04c5a6;
case 0x0c04c5a8u: goto P_0c04c5a8;
case 0x0c04c5aau: goto P_0c04c5aa;
case 0x0c04c5acu: goto P_0c04c5ac;
case 0x0c04c5aeu: goto P_0c04c5ae;
case 0x0c04c5b0u: goto P_0c04c5b0;
case 0x0c04c5b2u: goto P_0c04c5b2;
case 0x0c04c5b4u: goto P_0c04c5b4;
case 0x0c04c5b6u: goto P_0c04c5b6;
case 0x0c04c5b8u: goto P_0c04c5b8;
case 0x0c04c5bau: goto P_0c04c5ba;
case 0x0c04c5bcu: goto P_0c04c5bc;
case 0x0c04c5beu: goto P_0c04c5be;
case 0x0c04c5c0u: goto P_0c04c5c0;
case 0x0c04c5c2u: goto P_0c04c5c2;
case 0x0c04c5c4u: goto P_0c04c5c4;
case 0x0c04c5c6u: goto P_0c04c5c6;
case 0x0c04c5c8u: goto P_0c04c5c8;
case 0x0c04c5cau: goto P_0c04c5ca;
case 0x0c04c5ccu: goto P_0c04c5cc;
case 0x0c04c5ceu: goto P_0c04c5ce;
case 0x0c04c5d0u: goto P_0c04c5d0;
case 0x0c04c5d2u: goto P_0c04c5d2;
case 0x0c04c5d4u: goto P_0c04c5d4;
case 0x0c04c5d6u: goto P_0c04c5d6;
case 0x0c04c5d8u: goto P_0c04c5d8;
case 0x0c04c5dau: goto P_0c04c5da;
case 0x0c04ceceu: goto P_0c04cece;
case 0x0c04ced0u: goto P_0c04ced0;
case 0x0c04ced2u: goto P_0c04ced2;
case 0x0c04ced4u: goto P_0c04ced4;
case 0x0c04ced6u: goto P_0c04ced6;
case 0x0c04ced8u: goto P_0c04ced8;
case 0x0c04cedau: goto P_0c04ceda;
case 0x0c04cedcu: goto P_0c04cedc;
case 0x0c04cedeu: goto P_0c04cede;
case 0x0c04cee0u: goto P_0c04cee0;
case 0x0c04cee2u: goto P_0c04cee2;
case 0x0c04cee4u: goto P_0c04cee4;
case 0x0c04cee6u: goto P_0c04cee6;
case 0x0c04cee8u: goto P_0c04cee8;
case 0x0c04ceeau: goto P_0c04ceea;
case 0x0c04ceecu: goto P_0c04ceec;
case 0x0c04ceeeu: goto P_0c04ceee;
case 0x0c04cef0u: goto P_0c04cef0;
case 0x0c04cef2u: goto P_0c04cef2;
case 0x0c04cef4u: goto P_0c04cef4;
case 0x0c04cef6u: goto P_0c04cef6;
case 0x0c04cef8u: goto P_0c04cef8;
case 0x0c04cefau: goto P_0c04cefa;
case 0x0c04cefcu: goto P_0c04cefc;
case 0x0c04cefeu: goto P_0c04cefe;
case 0x0c04cf00u: goto P_0c04cf00;
case 0x0c04cf02u: goto P_0c04cf02;
case 0x0c04cf04u: goto P_0c04cf04;
case 0x0c04cf06u: goto P_0c04cf06;
case 0x0c04cf08u: goto P_0c04cf08;
case 0x0c04cf0au: goto P_0c04cf0a;
case 0x0c04cf0cu: goto P_0c04cf0c;
case 0x0c04d62cu: goto P_0c04d62c;
case 0x0c04d62eu: goto P_0c04d62e;
case 0x0c04d630u: goto P_0c04d630;
case 0x0c04d632u: goto P_0c04d632;
case 0x0c04d634u: goto P_0c04d634;
case 0x0c04d636u: goto P_0c04d636;
case 0x0c04d638u: goto P_0c04d638;
case 0x0c04d63au: goto P_0c04d63a;
case 0x0c04d63cu: goto P_0c04d63c;
case 0x0c04d63eu: goto P_0c04d63e;
case 0x0c04d640u: goto P_0c04d640;
case 0x0c04d642u: goto P_0c04d642;
case 0x0c04d644u: goto P_0c04d644;
case 0x0c04d646u: goto P_0c04d646;
case 0x0c04d648u: goto P_0c04d648;
case 0x0c04d64au: goto P_0c04d64a;
case 0x0c04d64cu: goto P_0c04d64c;
case 0x0c04d64eu: goto P_0c04d64e;
case 0x0c04d650u: goto P_0c04d650;
case 0x0c04d652u: goto P_0c04d652;
case 0x0c04d654u: goto P_0c04d654;
case 0x0c04d656u: goto P_0c04d656;
case 0x0c04d658u: goto P_0c04d658;
case 0x0c04d65au: goto P_0c04d65a;
case 0x0c04d65cu: goto P_0c04d65c;
case 0x0c04d65eu: goto P_0c04d65e;
case 0x0c04d660u: goto P_0c04d660;
case 0x0c04d662u: goto P_0c04d662;
case 0x0c04d664u: goto P_0c04d664;
case 0x0c04d666u: goto P_0c04d666;
case 0x0c04d668u: goto P_0c04d668;
case 0x0c04d66au: goto P_0c04d66a;
case 0x0c04d66cu: goto P_0c04d66c;
case 0x0c04d66eu: goto P_0c04d66e;
case 0x0c04d670u: goto P_0c04d670;
case 0x0c04d672u: goto P_0c04d672;
case 0x0c04d674u: goto P_0c04d674;
case 0x0c04d698u: goto P_0c04d698;
case 0x0c04d69au: goto P_0c04d69a;
case 0x0c04d69cu: goto P_0c04d69c;
case 0x0c04d69eu: goto P_0c04d69e;
case 0x0c04d6a0u: goto P_0c04d6a0;
case 0x0c04d6a2u: goto P_0c04d6a2;
case 0x0c04d6a4u: goto P_0c04d6a4;
case 0x0c04d6a6u: goto P_0c04d6a6;
case 0x0c04d6a8u: goto P_0c04d6a8;
case 0x0c04d6aau: goto P_0c04d6aa;
case 0x0c04d6acu: goto P_0c04d6ac;
case 0x0c04d6aeu: goto P_0c04d6ae;
case 0x0c04d6b0u: goto P_0c04d6b0;
case 0x0c04d6b2u: goto P_0c04d6b2;
case 0x0c04d6b4u: goto P_0c04d6b4;
case 0x0c04d6b6u: goto P_0c04d6b6;
case 0x0c04d6b8u: goto P_0c04d6b8;
case 0x0c04d6bau: goto P_0c04d6ba;
case 0x0c04d6bcu: goto P_0c04d6bc;
case 0x0c04d6beu: goto P_0c04d6be;
case 0x0c04d6c0u: goto P_0c04d6c0;
case 0x0c04d6c2u: goto P_0c04d6c2;
case 0x0c04d6c4u: goto P_0c04d6c4;
case 0x0c04d6c6u: goto P_0c04d6c6;
case 0x0c04d6c8u: goto P_0c04d6c8;
case 0x0c04d6cau: goto P_0c04d6ca;
case 0x0c04d6ccu: goto P_0c04d6cc;
case 0x0c04d6ceu: goto P_0c04d6ce;
case 0x0c04d6d0u: goto P_0c04d6d0;
case 0x0c04d6d2u: goto P_0c04d6d2;
case 0x0c04d6d4u: goto P_0c04d6d4;
case 0x0c04d6d6u: goto P_0c04d6d6;
case 0x0c04d6d8u: goto P_0c04d6d8;
case 0x0c04d6dau: goto P_0c04d6da;
case 0x0c04d6dcu: goto P_0c04d6dc;
case 0x0c04d6deu: goto P_0c04d6de;
case 0x0c04d6e0u: goto P_0c04d6e0;
case 0x0c04d6e2u: goto P_0c04d6e2;
case 0x0c04d6e4u: goto P_0c04d6e4;
case 0x0c04d6e6u: goto P_0c04d6e6;
case 0x0c04d6e8u: goto P_0c04d6e8;
case 0x0c04d6eau: goto P_0c04d6ea;
case 0x0c04d6ecu: goto P_0c04d6ec;
case 0x0c04d6eeu: goto P_0c04d6ee;
case 0x0c04d6f0u: goto P_0c04d6f0;
case 0x0c04d6f2u: goto P_0c04d6f2;
case 0x0c04d6f4u: goto P_0c04d6f4;
case 0x0c04d6f6u: goto P_0c04d6f6;
case 0x0c04d6f8u: goto P_0c04d6f8;
case 0x0c04d6fau: goto P_0c04d6fa;
case 0x0c04d6fcu: goto P_0c04d6fc;
case 0x0c04d6feu: goto P_0c04d6fe;
case 0x0c04d700u: goto P_0c04d700;
case 0x0c04d702u: goto P_0c04d702;
case 0x0c04d704u: goto P_0c04d704;
case 0x0c04d706u: goto P_0c04d706;
case 0x0c04d708u: goto P_0c04d708;
case 0x0c04d70au: goto P_0c04d70a;
case 0x0c04d70cu: goto P_0c04d70c;
case 0x0c04d70eu: goto P_0c04d70e;
case 0x0c04d710u: goto P_0c04d710;
case 0x0c04d712u: goto P_0c04d712;
case 0x0c04d714u: goto P_0c04d714;
case 0x0c04d716u: goto P_0c04d716;
case 0x0c04d718u: goto P_0c04d718;
case 0x0c04d71au: goto P_0c04d71a;
case 0x0c04d71cu: goto P_0c04d71c;
case 0x0c04d71eu: goto P_0c04d71e;
case 0x0c04d720u: goto P_0c04d720;
default: return vf3_matrix_family(target,s,ram);
}
P_0c045b78: /* original d33c, guest PC 0x0c045b78 */
if(!s->budget--) { s->failed_pc=0x0c045b78u; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045b7a;
P_0c045b7a: /* original 4f22, guest PC 0x0c045b7a */
if(!s->budget--) { s->failed_pc=0x0c045b7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045b7c;
P_0c045b7c: /* original 6032, guest PC 0x0c045b7c */
if(!s->budget--) { s->failed_pc=0x0c045b7cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045b7e;
P_0c045b7e: /* original 401b, guest PC 0x0c045b7e */
if(!s->budget--) { s->failed_pc=0x0c045b7eu; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045b80;
P_0c045b80: /* original 8907, guest PC 0x0c045b80 */
if(!s->budget--) { s->failed_pc=0x0c045b80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045b92; }
goto P_0c045b82;
P_0c045b82: /* original d239, guest PC 0x0c045b82 */
if(!s->budget--) { s->failed_pc=0x0c045b82u; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045b84;
P_0c045b84: /* original d13a, guest PC 0x0c045b84 */
if(!s->budget--) { s->failed_pc=0x0c045b84u; return 0; }
r[1]=read(ram,0x0c045c70u,4);
goto P_0c045b86;
P_0c045b86: /* original 420b, guest PC 0x0c045b86 */
if(!s->budget--) { s->failed_pc=0x0c045b86u; return 0; }
target=r[2];
r[16]=code_base|0x0c045b8au;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045b8au) { target=s->pc; goto dispatch; }
goto P_0c045b8a;
P_0c045b88: /* original 2f16, guest PC 0x0c045b88 */
if(!s->budget--) { s->failed_pc=0x0c045b88u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045b8a;
P_0c045b8a: /* original 7f04, guest PC 0x0c045b8a */
if(!s->budget--) { s->failed_pc=0x0c045b8au; return 0; }
r[15]+=0x00000004u;
goto P_0c045b8c;
P_0c045b8c: /* original 4f26, guest PC 0x0c045b8c */
if(!s->budget--) { s->failed_pc=0x0c045b8cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045b8e;
P_0c045b8e: /* original 000b, guest PC 0x0c045b8e */
if(!s->budget--) { s->failed_pc=0x0c045b8eu; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045b90: /* original e0fe, guest PC 0x0c045b90 */
if(!s->budget--) { s->failed_pc=0x0c045b90u; return 0; }
r[0]=0xfffffffeu;
goto P_0c045b92;
P_0c045b92: /* original b007, guest PC 0x0c045b92 */
if(!s->budget--) { s->failed_pc=0x0c045b92u; return 0; }
target=code_base|0x0c045ba4u; r[16]=code_base|0x0c045b96u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045b96u) { target=s->pc; goto dispatch; }
goto P_0c045b96;
P_0c045b94: /* original 0009, guest PC 0x0c045b94 */
if(!s->budget--) { s->failed_pc=0x0c045b94u; return 0; }
goto P_0c045b96;
P_0c045b96: /* original d335, guest PC 0x0c045b96 */
if(!s->budget--) { s->failed_pc=0x0c045b96u; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045b98;
P_0c045b98: /* original e100, guest PC 0x0c045b98 */
if(!s->budget--) { s->failed_pc=0x0c045b98u; return 0; }
r[1]=0x00000000u;
goto P_0c045b9a;
P_0c045b9a: /* original 6232, guest PC 0x0c045b9a */
if(!s->budget--) { s->failed_pc=0x0c045b9au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045b9c;
P_0c045b9c: /* original 2210, guest PC 0x0c045b9c */
if(!s->budget--) { s->failed_pc=0x0c045b9cu; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045b9e;
P_0c045b9e: /* original 4f26, guest PC 0x0c045b9e */
if(!s->budget--) { s->failed_pc=0x0c045b9eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045ba0;
P_0c045ba0: /* original 000b, guest PC 0x0c045ba0 */
if(!s->budget--) { s->failed_pc=0x0c045ba0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045ba2: /* original 0009, guest PC 0x0c045ba2 */
if(!s->budget--) { s->failed_pc=0x0c045ba2u; return 0; }
goto P_0c045ba4;
P_0c045ba4: /* original 2fe6, guest PC 0x0c045ba4 */
if(!s->budget--) { s->failed_pc=0x0c045ba4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045ba6;
P_0c045ba6: /* original 4628, guest PC 0x0c045ba6 */
if(!s->budget--) { s->failed_pc=0x0c045ba6u; return 0; }
r[6]<<=16;
goto P_0c045ba8;
P_0c045ba8: /* original 4f22, guest PC 0x0c045ba8 */
if(!s->budget--) { s->failed_pc=0x0c045ba8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045baa;
P_0c045baa: /* original 4618, guest PC 0x0c045baa */
if(!s->budget--) { s->failed_pc=0x0c045baau; return 0; }
r[6]<<=8;
goto P_0c045bac;
P_0c045bac: /* original e300, guest PC 0x0c045bac */
if(!s->budget--) { s->failed_pc=0x0c045bacu; return 0; }
r[3]=0x00000000u;
goto P_0c045bae;
P_0c045bae: /* original 7ff8, guest PC 0x0c045bae */
if(!s->budget--) { s->failed_pc=0x0c045baeu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c045bb0;
P_0c045bb0: /* original 6ef3, guest PC 0x0c045bb0 */
if(!s->budget--) { s->failed_pc=0x0c045bb0u; return 0; }
r[14]=r[15];
goto P_0c045bb2;
P_0c045bb2: /* original e702, guest PC 0x0c045bb2 */
if(!s->budget--) { s->failed_pc=0x0c045bb2u; return 0; }
r[7]=0x00000002u;
goto P_0c045bb4;
P_0c045bb4: /* original 2e52, guest PC 0x0c045bb4 */
if(!s->budget--) { s->failed_pc=0x0c045bb4u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c045bb6;
P_0c045bb6: /* original 1e61, guest PC 0x0c045bb6 */
if(!s->budget--) { s->failed_pc=0x0c045bb6u; return 0; }
write(ram,r[14]+4,r[6],4);
goto P_0c045bb8;
P_0c045bb8: /* original 66e3, guest PC 0x0c045bb8 */
if(!s->budget--) { s->failed_pc=0x0c045bb8u; return 0; }
r[6]=r[14];
goto P_0c045bba;
P_0c045bba: /* original 2f36, guest PC 0x0c045bba */
if(!s->budget--) { s->failed_pc=0x0c045bbau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045bbc;
P_0c045bbc: /* original 2f36, guest PC 0x0c045bbc */
if(!s->budget--) { s->failed_pc=0x0c045bbcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045bbe;
P_0c045bbe: /* original b87f, guest PC 0x0c045bbe */
if(!s->budget--) { s->failed_pc=0x0c045bbeu; return 0; }
target=code_base|0x0c044cc0u; r[16]=code_base|0x0c045bc2u;
r[5]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045bc2u) { target=s->pc; goto dispatch; }
goto P_0c045bc2;
P_0c045bc0: /* original e50a, guest PC 0x0c045bc0 */
if(!s->budget--) { s->failed_pc=0x0c045bc0u; return 0; }
r[5]=0x0000000au;
goto P_0c045bc2;
P_0c045bc2: /* original 7f10, guest PC 0x0c045bc2 */
if(!s->budget--) { s->failed_pc=0x0c045bc2u; return 0; }
r[15]+=0x00000010u;
goto P_0c045bc4;
P_0c045bc4: /* original 4f26, guest PC 0x0c045bc4 */
if(!s->budget--) { s->failed_pc=0x0c045bc4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045bc6;
P_0c045bc6: /* original 000b, guest PC 0x0c045bc6 */
if(!s->budget--) { s->failed_pc=0x0c045bc6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045bc8: /* original 6ef6, guest PC 0x0c045bc8 */
if(!s->budget--) { s->failed_pc=0x0c045bc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c045bca;
P_0c045bca: /* original d328, guest PC 0x0c045bca */
if(!s->budget--) { s->failed_pc=0x0c045bcau; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045bcc;
P_0c045bcc: /* original 4f22, guest PC 0x0c045bcc */
if(!s->budget--) { s->failed_pc=0x0c045bccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045bce;
P_0c045bce: /* original 6032, guest PC 0x0c045bce */
if(!s->budget--) { s->failed_pc=0x0c045bceu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045bd0;
P_0c045bd0: /* original 401b, guest PC 0x0c045bd0 */
if(!s->budget--) { s->failed_pc=0x0c045bd0u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045bd2;
P_0c045bd2: /* original 8907, guest PC 0x0c045bd2 */
if(!s->budget--) { s->failed_pc=0x0c045bd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045be4; }
goto P_0c045bd4;
P_0c045bd4: /* original d224, guest PC 0x0c045bd4 */
if(!s->budget--) { s->failed_pc=0x0c045bd4u; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045bd6;
P_0c045bd6: /* original d126, guest PC 0x0c045bd6 */
if(!s->budget--) { s->failed_pc=0x0c045bd6u; return 0; }
r[1]=read(ram,0x0c045c70u,4);
goto P_0c045bd8;
P_0c045bd8: /* original 420b, guest PC 0x0c045bd8 */
if(!s->budget--) { s->failed_pc=0x0c045bd8u; return 0; }
target=r[2];
r[16]=code_base|0x0c045bdcu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045bdcu) { target=s->pc; goto dispatch; }
goto P_0c045bdc;
P_0c045bda: /* original 2f16, guest PC 0x0c045bda */
if(!s->budget--) { s->failed_pc=0x0c045bdau; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045bdc;
P_0c045bdc: /* original 7f04, guest PC 0x0c045bdc */
if(!s->budget--) { s->failed_pc=0x0c045bdcu; return 0; }
r[15]+=0x00000004u;
goto P_0c045bde;
P_0c045bde: /* original 4f26, guest PC 0x0c045bde */
if(!s->budget--) { s->failed_pc=0x0c045bdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045be0;
P_0c045be0: /* original 000b, guest PC 0x0c045be0 */
if(!s->budget--) { s->failed_pc=0x0c045be0u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045be2: /* original e0fe, guest PC 0x0c045be2 */
if(!s->budget--) { s->failed_pc=0x0c045be2u; return 0; }
r[0]=0xfffffffeu;
goto P_0c045be4;
P_0c045be4: /* original 53f1, guest PC 0x0c045be4 */
if(!s->budget--) { s->failed_pc=0x0c045be4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c045be6;
P_0c045be6: /* original 2f36, guest PC 0x0c045be6 */
if(!s->budget--) { s->failed_pc=0x0c045be6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045be8;
P_0c045be8: /* original b008, guest PC 0x0c045be8 */
if(!s->budget--) { s->failed_pc=0x0c045be8u; return 0; }
target=code_base|0x0c045bfcu; r[16]=code_base|0x0c045becu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045becu) { target=s->pc; goto dispatch; }
goto P_0c045bec;
P_0c045bea: /* original 0009, guest PC 0x0c045bea */
if(!s->budget--) { s->failed_pc=0x0c045beau; return 0; }
goto P_0c045bec;
P_0c045bec: /* original d31f, guest PC 0x0c045bec */
if(!s->budget--) { s->failed_pc=0x0c045becu; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045bee;
P_0c045bee: /* original e100, guest PC 0x0c045bee */
if(!s->budget--) { s->failed_pc=0x0c045beeu; return 0; }
r[1]=0x00000000u;
goto P_0c045bf0;
P_0c045bf0: /* original 7f04, guest PC 0x0c045bf0 */
if(!s->budget--) { s->failed_pc=0x0c045bf0u; return 0; }
r[15]+=0x00000004u;
goto P_0c045bf2;
P_0c045bf2: /* original 6232, guest PC 0x0c045bf2 */
if(!s->budget--) { s->failed_pc=0x0c045bf2u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045bf4;
P_0c045bf4: /* original 2210, guest PC 0x0c045bf4 */
if(!s->budget--) { s->failed_pc=0x0c045bf4u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045bf6;
P_0c045bf6: /* original 4f26, guest PC 0x0c045bf6 */
if(!s->budget--) { s->failed_pc=0x0c045bf6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045bf8;
P_0c045bf8: /* original 000b, guest PC 0x0c045bf8 */
if(!s->budget--) { s->failed_pc=0x0c045bf8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045bfa: /* original 0009, guest PC 0x0c045bfa */
if(!s->budget--) { s->failed_pc=0x0c045bfau; return 0; }
goto P_0c045bfc;
P_0c045bfc: /* original 2fe6, guest PC 0x0c045bfc */
if(!s->budget--) { s->failed_pc=0x0c045bfcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045bfe;
P_0c045bfe: /* original 4628, guest PC 0x0c045bfe */
if(!s->budget--) { s->failed_pc=0x0c045bfeu; return 0; }
r[6]<<=16;
goto P_0c045c00;
P_0c045c00: /* original 4f22, guest PC 0x0c045c00 */
if(!s->budget--) { s->failed_pc=0x0c045c00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045c02;
P_0c045c02: /* original 4618, guest PC 0x0c045c02 */
if(!s->budget--) { s->failed_pc=0x0c045c02u; return 0; }
r[6]<<=8;
goto P_0c045c04;
P_0c045c04: /* original 4728, guest PC 0x0c045c04 */
if(!s->budget--) { s->failed_pc=0x0c045c04u; return 0; }
r[7]<<=16;
goto P_0c045c06;
P_0c045c06: /* original 7ff8, guest PC 0x0c045c06 */
if(!s->budget--) { s->failed_pc=0x0c045c06u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c045c08;
P_0c045c08: /* original 267b, guest PC 0x0c045c08 */
if(!s->budget--) { s->failed_pc=0x0c045c08u; return 0; }
r[6]|=r[7];
goto P_0c045c0a;
P_0c045c0a: /* original 6ef3, guest PC 0x0c045c0a */
if(!s->budget--) { s->failed_pc=0x0c045c0au; return 0; }
r[14]=r[15];
goto P_0c045c0c;
P_0c045c0c: /* original e702, guest PC 0x0c045c0c */
if(!s->budget--) { s->failed_pc=0x0c045c0cu; return 0; }
r[7]=0x00000002u;
goto P_0c045c0e;
P_0c045c0e: /* original 2e52, guest PC 0x0c045c0e */
if(!s->budget--) { s->failed_pc=0x0c045c0eu; return 0; }
write(ram,r[14],r[5],4);
goto P_0c045c10;
P_0c045c10: /* original 53f4, guest PC 0x0c045c10 */
if(!s->budget--) { s->failed_pc=0x0c045c10u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c045c12;
P_0c045c12: /* original 263b, guest PC 0x0c045c12 */
if(!s->budget--) { s->failed_pc=0x0c045c12u; return 0; }
r[6]|=r[3];
goto P_0c045c14;
P_0c045c14: /* original e300, guest PC 0x0c045c14 */
if(!s->budget--) { s->failed_pc=0x0c045c14u; return 0; }
r[3]=0x00000000u;
goto P_0c045c16;
P_0c045c16: /* original 1e61, guest PC 0x0c045c16 */
if(!s->budget--) { s->failed_pc=0x0c045c16u; return 0; }
write(ram,r[14]+4,r[6],4);
goto P_0c045c18;
P_0c045c18: /* original 2f36, guest PC 0x0c045c18 */
if(!s->budget--) { s->failed_pc=0x0c045c18u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c1a;
P_0c045c1a: /* original 66e3, guest PC 0x0c045c1a */
if(!s->budget--) { s->failed_pc=0x0c045c1au; return 0; }
r[6]=r[14];
goto P_0c045c1c;
P_0c045c1c: /* original 2f36, guest PC 0x0c045c1c */
if(!s->budget--) { s->failed_pc=0x0c045c1cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c1e;
P_0c045c1e: /* original b84f, guest PC 0x0c045c1e */
if(!s->budget--) { s->failed_pc=0x0c045c1eu; return 0; }
target=code_base|0x0c044cc0u; r[16]=code_base|0x0c045c22u;
r[5]=0x0000000bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045c22u) { target=s->pc; goto dispatch; }
goto P_0c045c22;
P_0c045c20: /* original e50b, guest PC 0x0c045c20 */
if(!s->budget--) { s->failed_pc=0x0c045c20u; return 0; }
r[5]=0x0000000bu;
goto P_0c045c22;
P_0c045c22: /* original 7f10, guest PC 0x0c045c22 */
if(!s->budget--) { s->failed_pc=0x0c045c22u; return 0; }
r[15]+=0x00000010u;
goto P_0c045c24;
P_0c045c24: /* original 4f26, guest PC 0x0c045c24 */
if(!s->budget--) { s->failed_pc=0x0c045c24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045c26;
P_0c045c26: /* original 000b, guest PC 0x0c045c26 */
if(!s->budget--) { s->failed_pc=0x0c045c26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045c28: /* original 6ef6, guest PC 0x0c045c28 */
if(!s->budget--) { s->failed_pc=0x0c045c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c045c2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045c2au; return 0; } return 1;
P_0c045ef4: /* original 4615, guest PC 0x0c045ef4 */
if(!s->budget--) { s->failed_pc=0x0c045ef4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c045ef6;
P_0c045ef6: /* original e700, guest PC 0x0c045ef6 */
if(!s->budget--) { s->failed_pc=0x0c045ef6u; return 0; }
r[7]=0x00000000u;
goto P_0c045ef8;
P_0c045ef8: /* original 8f05, guest PC 0x0c045ef8 */
if(!s->budget--) { s->failed_pc=0x0c045ef8u; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c045f06; }
goto P_0c045efc;
P_0c045efa: /* original 6043, guest PC 0x0c045efa */
if(!s->budget--) { s->failed_pc=0x0c045efau; return 0; }
r[0]=r[4];
goto P_0c045efc;
P_0c045efc: /* original 7701, guest PC 0x0c045efc */
if(!s->budget--) { s->failed_pc=0x0c045efcu; return 0; }
r[7]+=0x00000001u;
goto P_0c045efe;
P_0c045efe: /* original 2052, guest PC 0x0c045efe */
if(!s->budget--) { s->failed_pc=0x0c045efeu; return 0; }
write(ram,r[0],r[5],4);
goto P_0c045f00;
P_0c045f00: /* original 3763, guest PC 0x0c045f00 */
if(!s->budget--) { s->failed_pc=0x0c045f00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[6])!=0);
goto P_0c045f02;
P_0c045f02: /* original 8ffb, guest PC 0x0c045f02 */
if(!s->budget--) { s->failed_pc=0x0c045f02u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000004u;
if(!cond) { goto P_0c045efc; }
goto P_0c045f06;
P_0c045f04: /* original 7004, guest PC 0x0c045f04 */
if(!s->budget--) { s->failed_pc=0x0c045f04u; return 0; }
r[0]+=0x00000004u;
goto P_0c045f06;
P_0c045f06: /* original 000b, guest PC 0x0c045f06 */
if(!s->budget--) { s->failed_pc=0x0c045f06u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c045f08: /* original 6063, guest PC 0x0c045f08 */
if(!s->budget--) { s->failed_pc=0x0c045f08u; return 0; }
r[0]=r[6];
if(!vf3_matrix_family(0x0c045f0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045f0au; return 0; } return 1;
P_0c04b9e4: /* original e700, guest PC 0x0c04b9e4 */
if(!s->budget--) { s->failed_pc=0x0c04b9e4u; return 0; }
r[7]=0x00000000u;
goto P_0c04b9e6;
P_0c04b9e6: /* original 6373, guest PC 0x0c04b9e6 */
if(!s->budget--) { s->failed_pc=0x0c04b9e6u; return 0; }
r[3]=r[7];
goto P_0c04b9e8;
P_0c04b9e8: /* original 3362, guest PC 0x0c04b9e8 */
if(!s->budget--) { s->failed_pc=0x0c04b9e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c04b9ea;
P_0c04b9ea: /* original 8d05, guest PC 0x0c04b9ea */
if(!s->budget--) { s->failed_pc=0x0c04b9eau; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c04b9f8; }
goto P_0c04b9ee;
P_0c04b9ec: /* original 6043, guest PC 0x0c04b9ec */
if(!s->budget--) { s->failed_pc=0x0c04b9ecu; return 0; }
r[0]=r[4];
goto P_0c04b9ee;
P_0c04b9ee: /* original 7701, guest PC 0x0c04b9ee */
if(!s->budget--) { s->failed_pc=0x0c04b9eeu; return 0; }
r[7]+=0x00000001u;
goto P_0c04b9f0;
P_0c04b9f0: /* original 2050, guest PC 0x0c04b9f0 */
if(!s->budget--) { s->failed_pc=0x0c04b9f0u; return 0; }
write(ram,r[0],r[5],1);
goto P_0c04b9f2;
P_0c04b9f2: /* original 3762, guest PC 0x0c04b9f2 */
if(!s->budget--) { s->failed_pc=0x0c04b9f2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[6])!=0);
goto P_0c04b9f4;
P_0c04b9f4: /* original 8ffb, guest PC 0x0c04b9f4 */
if(!s->budget--) { s->failed_pc=0x0c04b9f4u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c04b9ee; }
goto P_0c04b9f8;
P_0c04b9f6: /* original 7001, guest PC 0x0c04b9f6 */
if(!s->budget--) { s->failed_pc=0x0c04b9f6u; return 0; }
r[0]+=0x00000001u;
goto P_0c04b9f8;
P_0c04b9f8: /* original 000b, guest PC 0x0c04b9f8 */
if(!s->budget--) { s->failed_pc=0x0c04b9f8u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04b9fa: /* original 6043, guest PC 0x0c04b9fa */
if(!s->budget--) { s->failed_pc=0x0c04b9fau; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04b9fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04b9fcu; return 0; } return 1;
P_0c04c5a0: /* original 2fe6, guest PC 0x0c04c5a0 */
if(!s->budget--) { s->failed_pc=0x0c04c5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c5a2;
P_0c04c5a2: /* original e503, guest PC 0x0c04c5a2 */
if(!s->budget--) { s->failed_pc=0x0c04c5a2u; return 0; }
r[5]=0x00000003u;
goto P_0c04c5a4;
P_0c04c5a4: /* original 4f22, guest PC 0x0c04c5a4 */
if(!s->budget--) { s->failed_pc=0x0c04c5a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c5a6;
P_0c04c5a6: /* original 60f3, guest PC 0x0c04c5a6 */
if(!s->budget--) { s->failed_pc=0x0c04c5a6u; return 0; }
r[0]=r[15];
goto P_0c04c5a8;
P_0c04c5a8: /* original 7008, guest PC 0x0c04c5a8 */
if(!s->budget--) { s->failed_pc=0x0c04c5a8u; return 0; }
r[0]+=0x00000008u;
goto P_0c04c5aa;
P_0c04c5aa: /* original 7004, guest PC 0x0c04c5aa */
if(!s->budget--) { s->failed_pc=0x0c04c5aau; return 0; }
r[0]+=0x00000004u;
goto P_0c04c5ac;
P_0c04c5ac: /* original 2508, guest PC 0x0c04c5ac */
if(!s->budget--) { s->failed_pc=0x0c04c5acu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c04c5ae;
P_0c04c5ae: /* original 8903, guest PC 0x0c04c5ae */
if(!s->budget--) { s->failed_pc=0x0c04c5aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c5b8; }
goto P_0c04c5b0;
P_0c04c5b0: /* original 65f3, guest PC 0x0c04c5b0 */
if(!s->budget--) { s->failed_pc=0x0c04c5b0u; return 0; }
r[5]=r[15];
goto P_0c04c5b2;
P_0c04c5b2: /* original 7508, guest PC 0x0c04c5b2 */
if(!s->budget--) { s->failed_pc=0x0c04c5b2u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5b4;
P_0c04c5b4: /* original a003, guest PC 0x0c04c5b4 */
if(!s->budget--) { s->failed_pc=0x0c04c5b4u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5be;
P_0c04c5b6: /* original 7508, guest PC 0x0c04c5b6 */
if(!s->budget--) { s->failed_pc=0x0c04c5b6u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5b8;
P_0c04c5b8: /* original 65f3, guest PC 0x0c04c5b8 */
if(!s->budget--) { s->failed_pc=0x0c04c5b8u; return 0; }
r[5]=r[15];
goto P_0c04c5ba;
P_0c04c5ba: /* original 7508, guest PC 0x0c04c5ba */
if(!s->budget--) { s->failed_pc=0x0c04c5bau; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5bc;
P_0c04c5bc: /* original 7504, guest PC 0x0c04c5bc */
if(!s->budget--) { s->failed_pc=0x0c04c5bcu; return 0; }
r[5]+=0x00000004u;
goto P_0c04c5be;
P_0c04c5be: /* original d335, guest PC 0x0c04c5be */
if(!s->budget--) { s->failed_pc=0x0c04c5beu; return 0; }
r[3]=read(ram,0x0c04c694u,4);
goto P_0c04c5c0;
P_0c04c5c0: /* original 6653, guest PC 0x0c04c5c0 */
if(!s->budget--) { s->failed_pc=0x0c04c5c0u; return 0; }
r[6]=r[5];
goto P_0c04c5c2;
P_0c04c5c2: /* original d433, guest PC 0x0c04c5c2 */
if(!s->budget--) { s->failed_pc=0x0c04c5c2u; return 0; }
r[4]=read(ram,0x0c04c690u,4);
goto P_0c04c5c4;
P_0c04c5c4: /* original 430b, guest PC 0x0c04c5c4 */
if(!s->budget--) { s->failed_pc=0x0c04c5c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c04c5c8u;
r[5]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c5c8u) { target=s->pc; goto dispatch; }
goto P_0c04c5c8;
P_0c04c5c6: /* original 55f2, guest PC 0x0c04c5c6 */
if(!s->budget--) { s->failed_pc=0x0c04c5c6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c04c5c8;
P_0c04c5c8: /* original d233, guest PC 0x0c04c5c8 */
if(!s->budget--) { s->failed_pc=0x0c04c5c8u; return 0; }
r[2]=read(ram,0x0c04c698u,4);
goto P_0c04c5ca;
P_0c04c5ca: /* original 6e22, guest PC 0x0c04c5ca */
if(!s->budget--) { s->failed_pc=0x0c04c5cau; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c04c5cc;
P_0c04c5cc: /* original 2ee8, guest PC 0x0c04c5cc */
if(!s->budget--) { s->failed_pc=0x0c04c5ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04c5ce;
P_0c04c5ce: /* original 8902, guest PC 0x0c04c5ce */
if(!s->budget--) { s->failed_pc=0x0c04c5ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c5d6; }
goto P_0c04c5d0;
P_0c04c5d0: /* original d42f, guest PC 0x0c04c5d0 */
if(!s->budget--) { s->failed_pc=0x0c04c5d0u; return 0; }
r[4]=read(ram,0x0c04c690u,4);
goto P_0c04c5d2;
P_0c04c5d2: /* original 4e0b, guest PC 0x0c04c5d2 */
if(!s->budget--) { s->failed_pc=0x0c04c5d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c04c5d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c5d6u) { target=s->pc; goto dispatch; }
goto P_0c04c5d6;
P_0c04c5d4: /* original 0009, guest PC 0x0c04c5d4 */
if(!s->budget--) { s->failed_pc=0x0c04c5d4u; return 0; }
goto P_0c04c5d6;
P_0c04c5d6: /* original 4f26, guest PC 0x0c04c5d6 */
if(!s->budget--) { s->failed_pc=0x0c04c5d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c5d8;
P_0c04c5d8: /* original 000b, guest PC 0x0c04c5d8 */
if(!s->budget--) { s->failed_pc=0x0c04c5d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c5da: /* original 6ef6, guest PC 0x0c04c5da */
if(!s->budget--) { s->failed_pc=0x0c04c5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04c5dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c5dcu; return 0; } return 1;
P_0c04cece: /* original 2fe6, guest PC 0x0c04cece */
if(!s->budget--) { s->failed_pc=0x0c04ceceu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ced0;
P_0c04ced0: /* original 4f22, guest PC 0x0c04ced0 */
if(!s->budget--) { s->failed_pc=0x0c04ced0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ced2;
P_0c04ced2: /* original 9e41, guest PC 0x0c04ced2 */
if(!s->budget--) { s->failed_pc=0x0c04ced2u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf58u,2);
goto P_0c04ced4;
P_0c04ced4: /* original d321, guest PC 0x0c04ced4 */
if(!s->budget--) { s->failed_pc=0x0c04ced4u; return 0; }
r[3]=read(ram,0x0c04cf5cu,4);
goto P_0c04ced6;
P_0c04ced6: /* original 4f12, guest PC 0x0c04ced6 */
if(!s->budget--) { s->failed_pc=0x0c04ced6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ced8;
P_0c04ced8: /* original 24ef, guest PC 0x0c04ced8 */
if(!s->budget--) { s->failed_pc=0x0c04ced8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c04ceda;
P_0c04ceda: /* original 2f46, guest PC 0x0c04ceda */
if(!s->budget--) { s->failed_pc=0x0c04cedau; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cedc;
P_0c04cedc: /* original d225, guest PC 0x0c04cedc */
if(!s->budget--) { s->failed_pc=0x0c04cedcu; return 0; }
r[2]=read(ram,0x0c04cf74u,4);
goto P_0c04cede;
P_0c04cede: /* original 0e1a, guest PC 0x0c04cede */
if(!s->budget--) { s->failed_pc=0x0c04cedeu; return 0; }
r[14]=r[19];
goto P_0c04cee0;
P_0c04cee0: /* original 6eef, guest PC 0x0c04cee0 */
if(!s->budget--) { s->failed_pc=0x0c04cee0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04cee2;
P_0c04cee2: /* original 3e3c, guest PC 0x0c04cee2 */
if(!s->budget--) { s->failed_pc=0x0c04cee2u; return 0; }
r[14]+=r[3];
goto P_0c04cee4;
P_0c04cee4: /* original bb5c, guest PC 0x0c04cee4 */
if(!s->budget--) { s->failed_pc=0x0c04cee4u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cee8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cee8u) { target=s->pc; goto dispatch; }
goto P_0c04cee8;
P_0c04cee6: /* original 2f26, guest PC 0x0c04cee6 */
if(!s->budget--) { s->failed_pc=0x0c04cee6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cee8;
P_0c04cee8: /* original 84e2, guest PC 0x0c04cee8 */
if(!s->budget--) { s->failed_pc=0x0c04cee8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04ceea;
P_0c04ceea: /* original 2008, guest PC 0x0c04ceea */
if(!s->budget--) { s->failed_pc=0x0c04ceeau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ceec;
P_0c04ceec: /* original 8f03, guest PC 0x0c04ceec */
if(!s->budget--) { s->failed_pc=0x0c04ceecu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(!cond) { goto P_0c04cef6; }
goto P_0c04cef0;
P_0c04ceee: /* original 7f08, guest PC 0x0c04ceee */
if(!s->budget--) { s->failed_pc=0x0c04ceeeu; return 0; }
r[15]+=0x00000008u;
goto P_0c04cef0;
P_0c04cef0: /* original 9033, guest PC 0x0c04cef0 */
if(!s->budget--) { s->failed_pc=0x0c04cef0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf5au,2);
goto P_0c04cef2;
P_0c04cef2: /* original a008, guest PC 0x0c04cef2 */
if(!s->budget--) { s->failed_pc=0x0c04cef2u; return 0; }
goto P_0c04cf06;
P_0c04cef4: /* original 0009, guest PC 0x0c04cef4 */
if(!s->budget--) { s->failed_pc=0x0c04cef4u; return 0; }
goto P_0c04cef6;
P_0c04cef6: /* original e400, guest PC 0x0c04cef6 */
if(!s->budget--) { s->failed_pc=0x0c04cef6u; return 0; }
r[4]=0x00000000u;
goto P_0c04cef8;
P_0c04cef8: /* original 6043, guest PC 0x0c04cef8 */
if(!s->budget--) { s->failed_pc=0x0c04cef8u; return 0; }
r[0]=r[4];
goto P_0c04cefa;
P_0c04cefa: /* original 80e9, guest PC 0x0c04cefa */
if(!s->budget--) { s->failed_pc=0x0c04cefau; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c04cefc;
P_0c04cefc: /* original 80e8, guest PC 0x0c04cefc */
if(!s->budget--) { s->failed_pc=0x0c04cefcu; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c04cefe;
P_0c04cefe: /* original 80ea, guest PC 0x0c04cefe */
if(!s->budget--) { s->failed_pc=0x0c04cefeu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04cf00;
P_0c04cf00: /* original 80eb, guest PC 0x0c04cf00 */
if(!s->budget--) { s->failed_pc=0x0c04cf00u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04cf02;
P_0c04cf02: /* original 80ec, guest PC 0x0c04cf02 */
if(!s->budget--) { s->failed_pc=0x0c04cf02u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04cf04;
P_0c04cf04: /* original 1e01, guest PC 0x0c04cf04 */
if(!s->budget--) { s->failed_pc=0x0c04cf04u; return 0; }
write(ram,r[14]+4,r[0],4);
goto P_0c04cf06;
P_0c04cf06: /* original 4f16, guest PC 0x0c04cf06 */
if(!s->budget--) { s->failed_pc=0x0c04cf06u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cf08;
P_0c04cf08: /* original 4f26, guest PC 0x0c04cf08 */
if(!s->budget--) { s->failed_pc=0x0c04cf08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cf0a;
P_0c04cf0a: /* original 000b, guest PC 0x0c04cf0a */
if(!s->budget--) { s->failed_pc=0x0c04cf0au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04cf0c: /* original 6ef6, guest PC 0x0c04cf0c */
if(!s->budget--) { s->failed_pc=0x0c04cf0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04cf0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04cf0eu; return 0; } return 1;
P_0c04d62c: /* original 2fe6, guest PC 0x0c04d62c */
if(!s->budget--) { s->failed_pc=0x0c04d62cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d62e;
P_0c04d62e: /* original 6e43, guest PC 0x0c04d62e */
if(!s->budget--) { s->failed_pc=0x0c04d62eu; return 0; }
r[14]=r[4];
goto P_0c04d630;
P_0c04d630: /* original 2fd6, guest PC 0x0c04d630 */
if(!s->budget--) { s->failed_pc=0x0c04d630u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d632;
P_0c04d632: /* original 2fc6, guest PC 0x0c04d632 */
if(!s->budget--) { s->failed_pc=0x0c04d632u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d634;
P_0c04d634: /* original 2fb6, guest PC 0x0c04d634 */
if(!s->budget--) { s->failed_pc=0x0c04d634u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d636;
P_0c04d636: /* original 2fa6, guest PC 0x0c04d636 */
if(!s->budget--) { s->failed_pc=0x0c04d636u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d638;
P_0c04d638: /* original 4f22, guest PC 0x0c04d638 */
if(!s->budget--) { s->failed_pc=0x0c04d638u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d63a;
P_0c04d63a: /* original 4f12, guest PC 0x0c04d63a */
if(!s->budget--) { s->failed_pc=0x0c04d63au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d63c;
P_0c04d63c: /* original 7ff8, guest PC 0x0c04d63c */
if(!s->budget--) { s->failed_pc=0x0c04d63cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04d63e;
P_0c04d63e: /* original 2f52, guest PC 0x0c04d63e */
if(!s->budget--) { s->failed_pc=0x0c04d63eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04d640;
P_0c04d640: /* original 9b1b, guest PC 0x0c04d640 */
if(!s->budget--) { s->failed_pc=0x0c04d640u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d67au,2);
goto P_0c04d642;
P_0c04d642: /* original 2ebf, guest PC 0x0c04d642 */
if(!s->budget--) { s->failed_pc=0x0c04d642u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[11]);
goto P_0c04d644;
P_0c04d644: /* original 0b1a, guest PC 0x0c04d644 */
if(!s->budget--) { s->failed_pc=0x0c04d644u; return 0; }
r[11]=r[19];
goto P_0c04d646;
P_0c04d646: /* original 6bbf, guest PC 0x0c04d646 */
if(!s->budget--) { s->failed_pc=0x0c04d646u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c04d648;
P_0c04d648: /* original 1fb1, guest PC 0x0c04d648 */
if(!s->budget--) { s->failed_pc=0x0c04d648u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c04d64a;
P_0c04d64a: /* original 62f2, guest PC 0x0c04d64a */
if(!s->budget--) { s->failed_pc=0x0c04d64au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04d64c;
P_0c04d64c: /* original d30c, guest PC 0x0c04d64c */
if(!s->budget--) { s->failed_pc=0x0c04d64cu; return 0; }
r[3]=read(ram,0x0c04d680u,4);
goto P_0c04d64e;
P_0c04d64e: /* original 2f26, guest PC 0x0c04d64e */
if(!s->budget--) { s->failed_pc=0x0c04d64eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d650;
P_0c04d650: /* original 3b3c, guest PC 0x0c04d650 */
if(!s->budget--) { s->failed_pc=0x0c04d650u; return 0; }
r[11]+=r[3];
goto P_0c04d652;
P_0c04d652: /* original 2fe6, guest PC 0x0c04d652 */
if(!s->budget--) { s->failed_pc=0x0c04d652u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d654;
P_0c04d654: /* original d20d, guest PC 0x0c04d654 */
if(!s->budget--) { s->failed_pc=0x0c04d654u; return 0; }
r[2]=read(ram,0x0c04d68cu,4);
goto P_0c04d656;
P_0c04d656: /* original d10e, guest PC 0x0c04d656 */
if(!s->budget--) { s->failed_pc=0x0c04d656u; return 0; }
r[1]=read(ram,0x0c04d690u,4);
goto P_0c04d658;
P_0c04d658: /* original 410b, guest PC 0x0c04d658 */
if(!s->budget--) { s->failed_pc=0x0c04d658u; return 0; }
target=r[1];
r[16]=code_base|0x0c04d65cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d65cu) { target=s->pc; goto dispatch; }
goto P_0c04d65c;
P_0c04d65a: /* original 2f26, guest PC 0x0c04d65a */
if(!s->budget--) { s->failed_pc=0x0c04d65au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d65c;
P_0c04d65c: /* original 84b2, guest PC 0x0c04d65c */
if(!s->budget--) { s->failed_pc=0x0c04d65cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+2,1);
goto P_0c04d65e;
P_0c04d65e: /* original 2008, guest PC 0x0c04d65e */
if(!s->budget--) { s->failed_pc=0x0c04d65eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d660;
P_0c04d660: /* original 8d25, guest PC 0x0c04d660 */
if(!s->budget--) { s->failed_pc=0x0c04d660u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04d6ae; }
goto P_0c04d664;
P_0c04d662: /* original 7f0c, guest PC 0x0c04d662 */
if(!s->budget--) { s->failed_pc=0x0c04d662u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04d664;
P_0c04d664: /* original d20b, guest PC 0x0c04d664 */
if(!s->budget--) { s->failed_pc=0x0c04d664u; return 0; }
r[2]=read(ram,0x0c04d694u,4);
goto P_0c04d666;
P_0c04d666: /* original 420b, guest PC 0x0c04d666 */
if(!s->budget--) { s->failed_pc=0x0c04d666u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d66au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d66au) { target=s->pc; goto dispatch; }
goto P_0c04d66a;
P_0c04d668: /* original 64e3, guest PC 0x0c04d668 */
if(!s->budget--) { s->failed_pc=0x0c04d668u; return 0; }
r[4]=r[14];
goto P_0c04d66a;
P_0c04d66a: /* original 2008, guest PC 0x0c04d66a */
if(!s->budget--) { s->failed_pc=0x0c04d66au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d66c;
P_0c04d66c: /* original 8b14, guest PC 0x0c04d66c */
if(!s->budget--) { s->failed_pc=0x0c04d66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d698; }
goto P_0c04d66e;
P_0c04d66e: /* original bc2e, guest PC 0x0c04d66e */
if(!s->budget--) { s->failed_pc=0x0c04d66eu; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04d672u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d672u) { target=s->pc; goto dispatch; }
goto P_0c04d672;
P_0c04d670: /* original 64e3, guest PC 0x0c04d670 */
if(!s->budget--) { s->failed_pc=0x0c04d670u; return 0; }
r[4]=r[14];
goto P_0c04d672;
P_0c04d672: /* original a01c, guest PC 0x0c04d672 */
if(!s->budget--) { s->failed_pc=0x0c04d672u; return 0; }
goto P_0c04d6ae;
P_0c04d674: /* original 0009, guest PC 0x0c04d674 */
if(!s->budget--) { s->failed_pc=0x0c04d674u; return 0; }
if(!vf3_matrix_family(0x0c04d676u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d676u; return 0; } return 1;
P_0c04d698: /* original d334, guest PC 0x0c04d698 */
if(!s->budget--) { s->failed_pc=0x0c04d698u; return 0; }
r[3]=read(ram,0x0c04d76cu,4);
goto P_0c04d69a;
P_0c04d69a: /* original 430b, guest PC 0x0c04d69a */
if(!s->budget--) { s->failed_pc=0x0c04d69au; return 0; }
target=r[3];
r[16]=code_base|0x0c04d69eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d69eu) { target=s->pc; goto dispatch; }
goto P_0c04d69e;
P_0c04d69c: /* original 64e3, guest PC 0x0c04d69c */
if(!s->budget--) { s->failed_pc=0x0c04d69cu; return 0; }
r[4]=r[14];
goto P_0c04d69e;
P_0c04d69e: /* original 2008, guest PC 0x0c04d69e */
if(!s->budget--) { s->failed_pc=0x0c04d69eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d6a0;
P_0c04d6a0: /* original 8905, guest PC 0x0c04d6a0 */
if(!s->budget--) { s->failed_pc=0x0c04d6a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d6ae; }
goto P_0c04d6a2;
P_0c04d6a2: /* original 52f1, guest PC 0x0c04d6a2 */
if(!s->budget--) { s->failed_pc=0x0c04d6a2u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04d6a4;
P_0c04d6a4: /* original d332, guest PC 0x0c04d6a4 */
if(!s->budget--) { s->failed_pc=0x0c04d6a4u; return 0; }
r[3]=read(ram,0x0c04d770u,4);
goto P_0c04d6a6;
P_0c04d6a6: /* original 323c, guest PC 0x0c04d6a6 */
if(!s->budget--) { s->failed_pc=0x0c04d6a6u; return 0; }
r[2]+=r[3];
goto P_0c04d6a8;
P_0c04d6a8: /* original 8428, guest PC 0x0c04d6a8 */
if(!s->budget--) { s->failed_pc=0x0c04d6a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04d6aa;
P_0c04d6aa: /* original 2008, guest PC 0x0c04d6aa */
if(!s->budget--) { s->failed_pc=0x0c04d6aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d6ac;
P_0c04d6ac: /* original 8b02, guest PC 0x0c04d6ac */
if(!s->budget--) { s->failed_pc=0x0c04d6acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6b4; }
goto P_0c04d6ae;
P_0c04d6ae: /* original 905a, guest PC 0x0c04d6ae */
if(!s->budget--) { s->failed_pc=0x0c04d6aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d766u,2);
goto P_0c04d6b0;
P_0c04d6b0: /* original a02e, guest PC 0x0c04d6b0 */
if(!s->budget--) { s->failed_pc=0x0c04d6b0u; return 0; }
goto P_0c04d710;
P_0c04d6b2: /* original 0009, guest PC 0x0c04d6b2 */
if(!s->budget--) { s->failed_pc=0x0c04d6b2u; return 0; }
goto P_0c04d6b4;
P_0c04d6b4: /* original d32f, guest PC 0x0c04d6b4 */
if(!s->budget--) { s->failed_pc=0x0c04d6b4u; return 0; }
r[3]=read(ram,0x0c04d774u,4);
goto P_0c04d6b6;
P_0c04d6b6: /* original 430b, guest PC 0x0c04d6b6 */
if(!s->budget--) { s->failed_pc=0x0c04d6b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d6bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d6bau) { target=s->pc; goto dispatch; }
goto P_0c04d6ba;
P_0c04d6b8: /* original 64e3, guest PC 0x0c04d6b8 */
if(!s->budget--) { s->failed_pc=0x0c04d6b8u; return 0; }
r[4]=r[14];
goto P_0c04d6ba;
P_0c04d6ba: /* original 4011, guest PC 0x0c04d6ba */
if(!s->budget--) { s->failed_pc=0x0c04d6bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d6bc;
P_0c04d6bc: /* original 8902, guest PC 0x0c04d6bc */
if(!s->budget--) { s->failed_pc=0x0c04d6bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d6c4; }
goto P_0c04d6be;
P_0c04d6be: /* original 9053, guest PC 0x0c04d6be */
if(!s->budget--) { s->failed_pc=0x0c04d6beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d768u,2);
goto P_0c04d6c0;
P_0c04d6c0: /* original a026, guest PC 0x0c04d6c0 */
if(!s->budget--) { s->failed_pc=0x0c04d6c0u; return 0; }
goto P_0c04d710;
P_0c04d6c2: /* original 0009, guest PC 0x0c04d6c2 */
if(!s->budget--) { s->failed_pc=0x0c04d6c2u; return 0; }
goto P_0c04d6c4;
P_0c04d6c4: /* original 60f2, guest PC 0x0c04d6c4 */
if(!s->budget--) { s->failed_pc=0x0c04d6c4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04d6c6;
P_0c04d6c6: /* original e400, guest PC 0x0c04d6c6 */
if(!s->budget--) { s->failed_pc=0x0c04d6c6u; return 0; }
r[4]=0x00000000u;
goto P_0c04d6c8;
P_0c04d6c8: /* original dd2b, guest PC 0x0c04d6c8 */
if(!s->budget--) { s->failed_pc=0x0c04d6c8u; return 0; }
r[13]=read(ram,0x0c04d778u,4);
goto P_0c04d6ca;
P_0c04d6ca: /* original 8801, guest PC 0x0c04d6ca */
if(!s->budget--) { s->failed_pc=0x0c04d6cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04d6cc;
P_0c04d6cc: /* original 8f10, guest PC 0x0c04d6cc */
if(!s->budget--) { s->failed_pc=0x0c04d6ccu; return 0; }
cond=r[17]&1u;
r[10]=r[4];
if(!cond) { goto P_0c04d6f0; }
goto P_0c04d6d0;
P_0c04d6ce: /* original 6a43, guest PC 0x0c04d6ce */
if(!s->budget--) { s->failed_pc=0x0c04d6ceu; return 0; }
r[10]=r[4];
goto P_0c04d6d0;
P_0c04d6d0: /* original a008, guest PC 0x0c04d6d0 */
if(!s->budget--) { s->failed_pc=0x0c04d6d0u; return 0; }
r[12]=r[4];
goto P_0c04d6e4;
P_0c04d6d2: /* original 6c43, guest PC 0x0c04d6d2 */
if(!s->budget--) { s->failed_pc=0x0c04d6d2u; return 0; }
r[12]=r[4];
goto P_0c04d6d4;
P_0c04d6d4: /* original d329, guest PC 0x0c04d6d4 */
if(!s->budget--) { s->failed_pc=0x0c04d6d4u; return 0; }
r[3]=read(ram,0x0c04d77cu,4);
goto P_0c04d6d6;
P_0c04d6d6: /* original 65c3, guest PC 0x0c04d6d6 */
if(!s->budget--) { s->failed_pc=0x0c04d6d6u; return 0; }
r[5]=r[12];
goto P_0c04d6d8;
P_0c04d6d8: /* original 430b, guest PC 0x0c04d6d8 */
if(!s->budget--) { s->failed_pc=0x0c04d6d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d6dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d6dcu) { target=s->pc; goto dispatch; }
goto P_0c04d6dc;
P_0c04d6da: /* original 64e3, guest PC 0x0c04d6da */
if(!s->budget--) { s->failed_pc=0x0c04d6dau; return 0; }
r[4]=r[14];
goto P_0c04d6dc;
P_0c04d6dc: /* original 600d, guest PC 0x0c04d6dc */
if(!s->budget--) { s->failed_pc=0x0c04d6dcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d6de;
P_0c04d6de: /* original 30d0, guest PC 0x0c04d6de */
if(!s->budget--) { s->failed_pc=0x0c04d6deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c04d6e0;
P_0c04d6e0: /* original 8b04, guest PC 0x0c04d6e0 */
if(!s->budget--) { s->failed_pc=0x0c04d6e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6ec; }
goto P_0c04d6e2;
P_0c04d6e2: /* original 7c01, guest PC 0x0c04d6e2 */
if(!s->budget--) { s->failed_pc=0x0c04d6e2u; return 0; }
r[12]+=0x00000001u;
goto P_0c04d6e4;
P_0c04d6e4: /* original 52b7, guest PC 0x0c04d6e4 */
if(!s->budget--) { s->failed_pc=0x0c04d6e4u; return 0; }
r[2]=read(ram,r[11]+28,4);
goto P_0c04d6e6;
P_0c04d6e6: /* original 532e, guest PC 0x0c04d6e6 */
if(!s->budget--) { s->failed_pc=0x0c04d6e6u; return 0; }
r[3]=read(ram,r[2]+56,4);
goto P_0c04d6e8;
P_0c04d6e8: /* original 3c33, guest PC 0x0c04d6e8 */
if(!s->budget--) { s->failed_pc=0x0c04d6e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c04d6ea;
P_0c04d6ea: /* original 8bf3, guest PC 0x0c04d6ea */
if(!s->budget--) { s->failed_pc=0x0c04d6eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6d4; }
goto P_0c04d6ec;
P_0c04d6ec: /* original a00f, guest PC 0x0c04d6ec */
if(!s->budget--) { s->failed_pc=0x0c04d6ecu; return 0; }
r[10]=r[12];
goto P_0c04d70e;
P_0c04d6ee: /* original 6ac3, guest PC 0x0c04d6ee */
if(!s->budget--) { s->failed_pc=0x0c04d6eeu; return 0; }
r[10]=r[12];
goto P_0c04d6f0;
P_0c04d6f0: /* original a009, guest PC 0x0c04d6f0 */
if(!s->budget--) { s->failed_pc=0x0c04d6f0u; return 0; }
r[12]=r[4];
goto P_0c04d706;
P_0c04d6f2: /* original 6c43, guest PC 0x0c04d6f2 */
if(!s->budget--) { s->failed_pc=0x0c04d6f2u; return 0; }
r[12]=r[4];
goto P_0c04d6f4;
P_0c04d6f4: /* original d321, guest PC 0x0c04d6f4 */
if(!s->budget--) { s->failed_pc=0x0c04d6f4u; return 0; }
r[3]=read(ram,0x0c04d77cu,4);
goto P_0c04d6f6;
P_0c04d6f6: /* original 65c3, guest PC 0x0c04d6f6 */
if(!s->budget--) { s->failed_pc=0x0c04d6f6u; return 0; }
r[5]=r[12];
goto P_0c04d6f8;
P_0c04d6f8: /* original 430b, guest PC 0x0c04d6f8 */
if(!s->budget--) { s->failed_pc=0x0c04d6f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d6fcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d6fcu) { target=s->pc; goto dispatch; }
goto P_0c04d6fc;
P_0c04d6fa: /* original 64e3, guest PC 0x0c04d6fa */
if(!s->budget--) { s->failed_pc=0x0c04d6fau; return 0; }
r[4]=r[14];
goto P_0c04d6fc;
P_0c04d6fc: /* original 600d, guest PC 0x0c04d6fc */
if(!s->budget--) { s->failed_pc=0x0c04d6fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d6fe;
P_0c04d6fe: /* original 30d0, guest PC 0x0c04d6fe */
if(!s->budget--) { s->failed_pc=0x0c04d6feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c04d700;
P_0c04d700: /* original 8f01, guest PC 0x0c04d700 */
if(!s->budget--) { s->failed_pc=0x0c04d700u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c04d706; }
goto P_0c04d704;
P_0c04d702: /* original 7c01, guest PC 0x0c04d702 */
if(!s->budget--) { s->failed_pc=0x0c04d702u; return 0; }
r[12]+=0x00000001u;
goto P_0c04d704;
P_0c04d704: /* original 7a01, guest PC 0x0c04d704 */
if(!s->budget--) { s->failed_pc=0x0c04d704u; return 0; }
r[10]+=0x00000001u;
goto P_0c04d706;
P_0c04d706: /* original 53b7, guest PC 0x0c04d706 */
if(!s->budget--) { s->failed_pc=0x0c04d706u; return 0; }
r[3]=read(ram,r[11]+28,4);
goto P_0c04d708;
P_0c04d708: /* original 523c, guest PC 0x0c04d708 */
if(!s->budget--) { s->failed_pc=0x0c04d708u; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c04d70a;
P_0c04d70a: /* original 3c23, guest PC 0x0c04d70a */
if(!s->budget--) { s->failed_pc=0x0c04d70au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[2])!=0);
goto P_0c04d70c;
P_0c04d70c: /* original 8bf2, guest PC 0x0c04d70c */
if(!s->budget--) { s->failed_pc=0x0c04d70cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6f4; }
goto P_0c04d70e;
P_0c04d70e: /* original 60a3, guest PC 0x0c04d70e */
if(!s->budget--) { s->failed_pc=0x0c04d70eu; return 0; }
r[0]=r[10];
goto P_0c04d710;
P_0c04d710: /* original 7f08, guest PC 0x0c04d710 */
if(!s->budget--) { s->failed_pc=0x0c04d710u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d712;
P_0c04d712: /* original 4f16, guest PC 0x0c04d712 */
if(!s->budget--) { s->failed_pc=0x0c04d712u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d714;
P_0c04d714: /* original 4f26, guest PC 0x0c04d714 */
if(!s->budget--) { s->failed_pc=0x0c04d714u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d716;
P_0c04d716: /* original 6af6, guest PC 0x0c04d716 */
if(!s->budget--) { s->failed_pc=0x0c04d716u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d718;
P_0c04d718: /* original 6bf6, guest PC 0x0c04d718 */
if(!s->budget--) { s->failed_pc=0x0c04d718u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d71a;
P_0c04d71a: /* original 6cf6, guest PC 0x0c04d71a */
if(!s->budget--) { s->failed_pc=0x0c04d71au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d71c;
P_0c04d71c: /* original 6df6, guest PC 0x0c04d71c */
if(!s->budget--) { s->failed_pc=0x0c04d71cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d71e;
P_0c04d71e: /* original 000b, guest PC 0x0c04d71e */
if(!s->budget--) { s->failed_pc=0x0c04d71eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d720: /* original 6ef6, guest PC 0x0c04d720 */
if(!s->budget--) { s->failed_pc=0x0c04d720u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04d722u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d722u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
