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
int vf3_away_batch4_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c046bf0u: goto P_0c046bf0;
case 0x0c046bf2u: goto P_0c046bf2;
case 0x0c046bf4u: goto P_0c046bf4;
case 0x0c046bf6u: goto P_0c046bf6;
case 0x0c046bf8u: goto P_0c046bf8;
case 0x0c046bfau: goto P_0c046bfa;
case 0x0c046bfcu: goto P_0c046bfc;
case 0x0c046bfeu: goto P_0c046bfe;
case 0x0c046c00u: goto P_0c046c00;
case 0x0c046c02u: goto P_0c046c02;
case 0x0c046c04u: goto P_0c046c04;
case 0x0c046c06u: goto P_0c046c06;
case 0x0c046c08u: goto P_0c046c08;
case 0x0c046c0au: goto P_0c046c0a;
case 0x0c046c0cu: goto P_0c046c0c;
case 0x0c046c0eu: goto P_0c046c0e;
case 0x0c046c10u: goto P_0c046c10;
case 0x0c046c12u: goto P_0c046c12;
case 0x0c046c14u: goto P_0c046c14;
case 0x0c046c16u: goto P_0c046c16;
case 0x0c046c18u: goto P_0c046c18;
case 0x0c046c1au: goto P_0c046c1a;
case 0x0c046c1cu: goto P_0c046c1c;
case 0x0c046c1eu: goto P_0c046c1e;
case 0x0c046c20u: goto P_0c046c20;
case 0x0c046c22u: goto P_0c046c22;
case 0x0c046c24u: goto P_0c046c24;
case 0x0c046c26u: goto P_0c046c26;
case 0x0c046c28u: goto P_0c046c28;
case 0x0c046c2au: goto P_0c046c2a;
case 0x0c046c2cu: goto P_0c046c2c;
case 0x0c046c2eu: goto P_0c046c2e;
case 0x0c046c30u: goto P_0c046c30;
case 0x0c046c32u: goto P_0c046c32;
case 0x0c046c34u: goto P_0c046c34;
case 0x0c046c36u: goto P_0c046c36;
case 0x0c046c38u: goto P_0c046c38;
case 0x0c046c3au: goto P_0c046c3a;
case 0x0c046c3cu: goto P_0c046c3c;
case 0x0c046c3eu: goto P_0c046c3e;
case 0x0c046c40u: goto P_0c046c40;
case 0x0c046c42u: goto P_0c046c42;
case 0x0c046c44u: goto P_0c046c44;
case 0x0c046c46u: goto P_0c046c46;
case 0x0c047400u: goto P_0c047400;
case 0x0c047402u: goto P_0c047402;
case 0x0c047404u: goto P_0c047404;
case 0x0c047406u: goto P_0c047406;
case 0x0c047408u: goto P_0c047408;
case 0x0c04740au: goto P_0c04740a;
case 0x0c04740cu: goto P_0c04740c;
case 0x0c04740eu: goto P_0c04740e;
case 0x0c047410u: goto P_0c047410;
case 0x0c047412u: goto P_0c047412;
case 0x0c047414u: goto P_0c047414;
case 0x0c047416u: goto P_0c047416;
case 0x0c047418u: goto P_0c047418;
case 0x0c04741au: goto P_0c04741a;
case 0x0c04741cu: goto P_0c04741c;
case 0x0c04741eu: goto P_0c04741e;
case 0x0c047420u: goto P_0c047420;
case 0x0c047422u: goto P_0c047422;
case 0x0c047424u: goto P_0c047424;
case 0x0c047426u: goto P_0c047426;
case 0x0c047428u: goto P_0c047428;
case 0x0c04742au: goto P_0c04742a;
case 0x0c04742cu: goto P_0c04742c;
case 0x0c04742eu: goto P_0c04742e;
case 0x0c047430u: goto P_0c047430;
case 0x0c047432u: goto P_0c047432;
case 0x0c047434u: goto P_0c047434;
case 0x0c047436u: goto P_0c047436;
case 0x0c047438u: goto P_0c047438;
case 0x0c04743au: goto P_0c04743a;
case 0x0c04743cu: goto P_0c04743c;
case 0x0c04743eu: goto P_0c04743e;
case 0x0c047440u: goto P_0c047440;
case 0x0c047442u: goto P_0c047442;
case 0x0c047444u: goto P_0c047444;
case 0x0c047446u: goto P_0c047446;
case 0x0c047448u: goto P_0c047448;
case 0x0c04744au: goto P_0c04744a;
case 0x0c04744cu: goto P_0c04744c;
case 0x0c04744eu: goto P_0c04744e;
case 0x0c047450u: goto P_0c047450;
case 0x0c047452u: goto P_0c047452;
case 0x0c047454u: goto P_0c047454;
case 0x0c047456u: goto P_0c047456;
case 0x0c047458u: goto P_0c047458;
case 0x0c047460u: goto P_0c047460;
case 0x0c047462u: goto P_0c047462;
case 0x0c047464u: goto P_0c047464;
case 0x0c047466u: goto P_0c047466;
case 0x0c047468u: goto P_0c047468;
case 0x0c04746au: goto P_0c04746a;
case 0x0c04746cu: goto P_0c04746c;
case 0x0c04746eu: goto P_0c04746e;
case 0x0c047470u: goto P_0c047470;
case 0x0c047472u: goto P_0c047472;
case 0x0c047474u: goto P_0c047474;
case 0x0c047480u: goto P_0c047480;
case 0x0c047482u: goto P_0c047482;
case 0x0c047484u: goto P_0c047484;
case 0x0c047486u: goto P_0c047486;
case 0x0c047488u: goto P_0c047488;
case 0x0c04748au: goto P_0c04748a;
case 0x0c04748cu: goto P_0c04748c;
case 0x0c04748eu: goto P_0c04748e;
case 0x0c047490u: goto P_0c047490;
case 0x0c047492u: goto P_0c047492;
case 0x0c047494u: goto P_0c047494;
case 0x0c047496u: goto P_0c047496;
case 0x0c047498u: goto P_0c047498;
case 0x0c04749au: goto P_0c04749a;
case 0x0c0474a0u: goto P_0c0474a0;
case 0x0c0474a2u: goto P_0c0474a2;
case 0x0c0474a4u: goto P_0c0474a4;
case 0x0c0474a6u: goto P_0c0474a6;
case 0x0c0474a8u: goto P_0c0474a8;
case 0x0c0474aau: goto P_0c0474aa;
case 0x0c0474acu: goto P_0c0474ac;
case 0x0c0474aeu: goto P_0c0474ae;
case 0x0c0474b0u: goto P_0c0474b0;
case 0x0c0474b2u: goto P_0c0474b2;
case 0x0c0474b4u: goto P_0c0474b4;
case 0x0c0474b6u: goto P_0c0474b6;
case 0x0c0474b8u: goto P_0c0474b8;
case 0x0c0474bau: goto P_0c0474ba;
case 0x0c0474bcu: goto P_0c0474bc;
case 0x0c0474beu: goto P_0c0474be;
case 0x0c0474c0u: goto P_0c0474c0;
case 0x0c0474c2u: goto P_0c0474c2;
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
P_0c046bf0: /* original 2fe6, guest PC 0x0c046bf0 */
if(!s->budget--) { s->failed_pc=0x0c046bf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046bf2;
P_0c046bf2: /* original 6e43, guest PC 0x0c046bf2 */
if(!s->budget--) { s->failed_pc=0x0c046bf2u; return 0; }
r[14]=r[4];
goto P_0c046bf4;
P_0c046bf4: /* original 2fd6, guest PC 0x0c046bf4 */
if(!s->budget--) { s->failed_pc=0x0c046bf4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046bf6;
P_0c046bf6: /* original 6d53, guest PC 0x0c046bf6 */
if(!s->budget--) { s->failed_pc=0x0c046bf6u; return 0; }
r[13]=r[5];
goto P_0c046bf8;
P_0c046bf8: /* original 2fc6, guest PC 0x0c046bf8 */
if(!s->budget--) { s->failed_pc=0x0c046bf8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046bfa;
P_0c046bfa: /* original 4f22, guest PC 0x0c046bfa */
if(!s->budget--) { s->failed_pc=0x0c046bfau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046bfc;
P_0c046bfc: /* original 7ff8, guest PC 0x0c046bfc */
if(!s->budget--) { s->failed_pc=0x0c046bfcu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046bfe;
P_0c046bfe: /* original 2f62, guest PC 0x0c046bfe */
if(!s->budget--) { s->failed_pc=0x0c046bfeu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c046c00;
P_0c046c00: /* original 1f71, guest PC 0x0c046c00 */
if(!s->budget--) { s->failed_pc=0x0c046c00u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c046c02;
P_0c046c02: /* original d32b, guest PC 0x0c046c02 */
if(!s->budget--) { s->failed_pc=0x0c046c02u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046c04;
P_0c046c04: /* original 430b, guest PC 0x0c046c04 */
if(!s->budget--) { s->failed_pc=0x0c046c04u; return 0; }
target=r[3];
r[16]=code_base|0x0c046c08u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046c08u) { target=s->pc; goto dispatch; }
goto P_0c046c08;
P_0c046c06: /* original 64e3, guest PC 0x0c046c06 */
if(!s->budget--) { s->failed_pc=0x0c046c06u; return 0; }
r[4]=r[14];
goto P_0c046c08;
P_0c046c08: /* original 2008, guest PC 0x0c046c08 */
if(!s->budget--) { s->failed_pc=0x0c046c08u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046c0a;
P_0c046c0a: /* original 8901, guest PC 0x0c046c0a */
if(!s->budget--) { s->failed_pc=0x0c046c0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046c10; }
goto P_0c046c0c;
P_0c046c0c: /* original a016, guest PC 0x0c046c0c */
if(!s->budget--) { s->failed_pc=0x0c046c0cu; return 0; }
r[0]=0xffffffffu;
goto P_0c046c3c;
P_0c046c0e: /* original e0ff, guest PC 0x0c046c0e */
if(!s->budget--) { s->failed_pc=0x0c046c0eu; return 0; }
r[0]=0xffffffffu;
goto P_0c046c10;
P_0c046c10: /* original d325, guest PC 0x0c046c10 */
if(!s->budget--) { s->failed_pc=0x0c046c10u; return 0; }
r[3]=read(ram,0x0c046ca8u,4);
goto P_0c046c12;
P_0c046c12: /* original e50b, guest PC 0x0c046c12 */
if(!s->budget--) { s->failed_pc=0x0c046c12u; return 0; }
r[5]=0x0000000bu;
goto P_0c046c14;
P_0c046c14: /* original 430b, guest PC 0x0c046c14 */
if(!s->budget--) { s->failed_pc=0x0c046c14u; return 0; }
target=r[3];
r[16]=code_base|0x0c046c18u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046c18u) { target=s->pc; goto dispatch; }
goto P_0c046c18;
P_0c046c16: /* original 64e3, guest PC 0x0c046c16 */
if(!s->budget--) { s->failed_pc=0x0c046c16u; return 0; }
r[4]=r[14];
goto P_0c046c18;
P_0c046c18: /* original ec00, guest PC 0x0c046c18 */
if(!s->budget--) { s->failed_pc=0x0c046c18u; return 0; }
r[12]=0x00000000u;
goto P_0c046c1a;
P_0c046c1a: /* original 65e3, guest PC 0x0c046c1a */
if(!s->budget--) { s->failed_pc=0x0c046c1au; return 0; }
r[5]=r[14];
goto P_0c046c1c;
P_0c046c1c: /* original 2fc6, guest PC 0x0c046c1c */
if(!s->budget--) { s->failed_pc=0x0c046c1cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c1e;
P_0c046c1e: /* original 66d3, guest PC 0x0c046c1e */
if(!s->budget--) { s->failed_pc=0x0c046c1eu; return 0; }
r[6]=r[13];
goto P_0c046c20;
P_0c046c20: /* original 2fc6, guest PC 0x0c046c20 */
if(!s->budget--) { s->failed_pc=0x0c046c20u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c22;
P_0c046c22: /* original 52f3, guest PC 0x0c046c22 */
if(!s->budget--) { s->failed_pc=0x0c046c22u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c046c24;
P_0c046c24: /* original 2f26, guest PC 0x0c046c24 */
if(!s->budget--) { s->failed_pc=0x0c046c24u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c26;
P_0c046c26: /* original d321, guest PC 0x0c046c26 */
if(!s->budget--) { s->failed_pc=0x0c046c26u; return 0; }
r[3]=read(ram,0x0c046cacu,4);
goto P_0c046c28;
P_0c046c28: /* original 57f3, guest PC 0x0c046c28 */
if(!s->budget--) { s->failed_pc=0x0c046c28u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c046c2a;
P_0c046c2a: /* original 430b, guest PC 0x0c046c2a */
if(!s->budget--) { s->failed_pc=0x0c046c2au; return 0; }
target=r[3];
r[16]=code_base|0x0c046c2eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046c2eu) { target=s->pc; goto dispatch; }
goto P_0c046c2e;
P_0c046c2c: /* original 64e3, guest PC 0x0c046c2c */
if(!s->budget--) { s->failed_pc=0x0c046c2cu; return 0; }
r[4]=r[14];
goto P_0c046c2e;
P_0c046c2e: /* original d221, guest PC 0x0c046c2e */
if(!s->budget--) { s->failed_pc=0x0c046c2eu; return 0; }
r[2]=read(ram,0x0c046cb4u,4);
goto P_0c046c30;
P_0c046c30: /* original 65d3, guest PC 0x0c046c30 */
if(!s->budget--) { s->failed_pc=0x0c046c30u; return 0; }
r[5]=r[13];
goto P_0c046c32;
P_0c046c32: /* original 7f0c, guest PC 0x0c046c32 */
if(!s->budget--) { s->failed_pc=0x0c046c32u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046c34;
P_0c046c34: /* original 66d3, guest PC 0x0c046c34 */
if(!s->budget--) { s->failed_pc=0x0c046c34u; return 0; }
r[6]=r[13];
goto P_0c046c36;
P_0c046c36: /* original 420b, guest PC 0x0c046c36 */
if(!s->budget--) { s->failed_pc=0x0c046c36u; return 0; }
target=r[2];
r[16]=code_base|0x0c046c3au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046c3au) { target=s->pc; goto dispatch; }
goto P_0c046c3a;
P_0c046c38: /* original 64e3, guest PC 0x0c046c38 */
if(!s->budget--) { s->failed_pc=0x0c046c38u; return 0; }
r[4]=r[14];
goto P_0c046c3a;
P_0c046c3a: /* original 60c3, guest PC 0x0c046c3a */
if(!s->budget--) { s->failed_pc=0x0c046c3au; return 0; }
r[0]=r[12];
goto P_0c046c3c;
P_0c046c3c: /* original 7f08, guest PC 0x0c046c3c */
if(!s->budget--) { s->failed_pc=0x0c046c3cu; return 0; }
r[15]+=0x00000008u;
goto P_0c046c3e;
P_0c046c3e: /* original 4f26, guest PC 0x0c046c3e */
if(!s->budget--) { s->failed_pc=0x0c046c3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046c40;
P_0c046c40: /* original 6cf6, guest PC 0x0c046c40 */
if(!s->budget--) { s->failed_pc=0x0c046c40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c046c42;
P_0c046c42: /* original 6df6, guest PC 0x0c046c42 */
if(!s->budget--) { s->failed_pc=0x0c046c42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046c44;
P_0c046c44: /* original 000b, guest PC 0x0c046c44 */
if(!s->budget--) { s->failed_pc=0x0c046c44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046c46: /* original 6ef6, guest PC 0x0c046c46 */
if(!s->budget--) { s->failed_pc=0x0c046c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c046c48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c046c48u; return 0; } return 1;
P_0c047400: /* original 2fe6, guest PC 0x0c047400 */
if(!s->budget--) { s->failed_pc=0x0c047400u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047402;
P_0c047402: /* original 6043, guest PC 0x0c047402 */
if(!s->budget--) { s->failed_pc=0x0c047402u; return 0; }
r[0]=r[4];
goto P_0c047404;
P_0c047404: /* original 2fd6, guest PC 0x0c047404 */
if(!s->budget--) { s->failed_pc=0x0c047404u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047406;
P_0c047406: /* original e3fc, guest PC 0x0c047406 */
if(!s->budget--) { s->failed_pc=0x0c047406u; return 0; }
r[3]=0xfffffffcu;
goto P_0c047408;
P_0c047408: /* original 2fc6, guest PC 0x0c047408 */
if(!s->budget--) { s->failed_pc=0x0c047408u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04740a;
P_0c04740a: /* original 750f, guest PC 0x0c04740a */
if(!s->budget--) { s->failed_pc=0x0c04740au; return 0; }
r[5]+=0x0000000fu;
goto P_0c04740c;
P_0c04740c: /* original 2fb6, guest PC 0x0c04740c */
if(!s->budget--) { s->failed_pc=0x0c04740cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04740e;
P_0c04740e: /* original 453c, guest PC 0x0c04740e */
if(!s->budget--) { s->failed_pc=0x0c04740eu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c047410;
P_0c047410: /* original 2fa6, guest PC 0x0c047410 */
if(!s->budget--) { s->failed_pc=0x0c047410u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047412;
P_0c047412: /* original 8810, guest PC 0x0c047412 */
if(!s->budget--) { s->failed_pc=0x0c047412u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c047414;
P_0c047414: /* original 2f96, guest PC 0x0c047414 */
if(!s->budget--) { s->failed_pc=0x0c047414u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047416;
P_0c047416: /* original eb04, guest PC 0x0c047416 */
if(!s->budget--) { s->failed_pc=0x0c047416u; return 0; }
r[11]=0x00000004u;
goto P_0c047418;
P_0c047418: /* original 2f86, guest PC 0x0c047418 */
if(!s->budget--) { s->failed_pc=0x0c047418u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04741a;
P_0c04741a: /* original e901, guest PC 0x0c04741a */
if(!s->budget--) { s->failed_pc=0x0c04741au; return 0; }
r[9]=0x00000001u;
goto P_0c04741c;
P_0c04741c: /* original d239, guest PC 0x0c04741c */
if(!s->budget--) { s->failed_pc=0x0c04741cu; return 0; }
r[2]=read(ram,0x0c047504u,4);
goto P_0c04741e;
P_0c04741e: /* original 7ff8, guest PC 0x0c04741e */
if(!s->budget--) { s->failed_pc=0x0c04741eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c047420;
P_0c047420: /* original 2f22, guest PC 0x0c047420 */
if(!s->budget--) { s->failed_pc=0x0c047420u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c047422;
P_0c047422: /* original 8f2d, guest PC 0x0c047422 */
if(!s->budget--) { s->failed_pc=0x0c047422u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c047480; }
goto P_0c047426;
P_0c047424: /* original e600, guest PC 0x0c047424 */
if(!s->budget--) { s->failed_pc=0x0c047424u; return 0; }
r[6]=0x00000000u;
goto P_0c047426;
P_0c047426: /* original e810, guest PC 0x0c047426 */
if(!s->budget--) { s->failed_pc=0x0c047426u; return 0; }
r[8]=0x00000010u;
goto P_0c047428;
P_0c047428: /* original 6c63, guest PC 0x0c047428 */
if(!s->budget--) { s->failed_pc=0x0c047428u; return 0; }
r[12]=r[6];
goto P_0c04742a;
P_0c04742a: /* original 6463, guest PC 0x0c04742a */
if(!s->budget--) { s->failed_pc=0x0c04742au; return 0; }
r[4]=r[6];
goto P_0c04742c;
P_0c04742c: /* original edff, guest PC 0x0c04742c */
if(!s->budget--) { s->failed_pc=0x0c04742cu; return 0; }
r[13]=0xffffffffu;
goto P_0c04742e;
P_0c04742e: /* original 62f2, guest PC 0x0c04742e */
if(!s->budget--) { s->failed_pc=0x0c04742eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c047430;
P_0c047430: /* original 63c3, guest PC 0x0c047430 */
if(!s->budget--) { s->failed_pc=0x0c047430u; return 0; }
r[3]=r[12];
goto P_0c047432;
P_0c047432: /* original 4300, guest PC 0x0c047432 */
if(!s->budget--) { s->failed_pc=0x0c047432u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c047434;
P_0c047434: /* original 6ec3, guest PC 0x0c047434 */
if(!s->budget--) { s->failed_pc=0x0c047434u; return 0; }
r[14]=r[12];
goto P_0c047436;
P_0c047436: /* original 332c, guest PC 0x0c047436 */
if(!s->budget--) { s->failed_pc=0x0c047436u; return 0; }
r[3]+=r[2];
goto P_0c047438;
P_0c047438: /* original 6793, guest PC 0x0c047438 */
if(!s->budget--) { s->failed_pc=0x0c047438u; return 0; }
r[7]=r[9];
goto P_0c04743a;
P_0c04743a: /* original 4e08, guest PC 0x0c04743a */
if(!s->budget--) { s->failed_pc=0x0c04743au; return 0; }
r[14]<<=2;
goto P_0c04743c;
P_0c04743c: /* original 1f31, guest PC 0x0c04743c */
if(!s->budget--) { s->failed_pc=0x0c04743cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04743e;
P_0c04743e: /* original 6a63, guest PC 0x0c04743e */
if(!s->budget--) { s->failed_pc=0x0c04743eu; return 0; }
r[10]=r[6];
goto P_0c047440;
P_0c047440: /* original 4e08, guest PC 0x0c047440 */
if(!s->budget--) { s->failed_pc=0x0c047440u; return 0; }
r[14]<<=2;
goto P_0c047442;
P_0c047442: /* original 52f1, guest PC 0x0c047442 */
if(!s->budget--) { s->failed_pc=0x0c047442u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c047444;
P_0c047444: /* original 6321, guest PC 0x0c047444 */
if(!s->budget--) { s->failed_pc=0x0c047444u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[3]=tmp;
goto P_0c047446;
P_0c047446: /* original 2378, guest PC 0x0c047446 */
if(!s->budget--) { s->failed_pc=0x0c047446u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c047448;
P_0c047448: /* original 8b0a, guest PC 0x0c047448 */
if(!s->budget--) { s->failed_pc=0x0c047448u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047460; }
goto P_0c04744a;
P_0c04744a: /* original 2448, guest PC 0x0c04744a */
if(!s->budget--) { s->failed_pc=0x0c04744au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04744c;
P_0c04744c: /* original 8f01, guest PC 0x0c04744c */
if(!s->budget--) { s->failed_pc=0x0c04744cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c047452; }
goto P_0c047450;
P_0c04744e: /* original 7401, guest PC 0x0c04744e */
if(!s->budget--) { s->failed_pc=0x0c04744eu; return 0; }
r[4]+=0x00000001u;
goto P_0c047450;
P_0c047450: /* original 6de3, guest PC 0x0c047450 */
if(!s->budget--) { s->failed_pc=0x0c047450u; return 0; }
r[13]=r[14];
goto P_0c047452;
P_0c047452: /* original 3453, guest PC 0x0c047452 */
if(!s->budget--) { s->failed_pc=0x0c047452u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c047454;
P_0c047454: /* original 890a, guest PC 0x0c047454 */
if(!s->budget--) { s->failed_pc=0x0c047454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04746c; }
goto P_0c047456;
P_0c047456: /* original a004, guest PC 0x0c047456 */
if(!s->budget--) { s->failed_pc=0x0c047456u; return 0; }
goto P_0c047462;
P_0c047458: /* original 0009, guest PC 0x0c047458 */
if(!s->budget--) { s->failed_pc=0x0c047458u; return 0; }
if(!vf3_matrix_family(0x0c04745au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04745au; return 0; } return 1;
P_0c047460: /* original 6463, guest PC 0x0c047460 */
if(!s->budget--) { s->failed_pc=0x0c047460u; return 0; }
r[4]=r[6];
goto P_0c047462;
P_0c047462: /* original 7a01, guest PC 0x0c047462 */
if(!s->budget--) { s->failed_pc=0x0c047462u; return 0; }
r[10]+=0x00000001u;
goto P_0c047464;
P_0c047464: /* original 3a83, guest PC 0x0c047464 */
if(!s->budget--) { s->failed_pc=0x0c047464u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[8])!=0);
goto P_0c047466;
P_0c047466: /* original 377c, guest PC 0x0c047466 */
if(!s->budget--) { s->failed_pc=0x0c047466u; return 0; }
r[7]+=r[7];
goto P_0c047468;
P_0c047468: /* original 8feb, guest PC 0x0c047468 */
if(!s->budget--) { s->failed_pc=0x0c047468u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c047442; }
goto P_0c04746c;
P_0c04746a: /* original 7e01, guest PC 0x0c04746a */
if(!s->budget--) { s->failed_pc=0x0c04746au; return 0; }
r[14]+=0x00000001u;
goto P_0c04746c;
P_0c04746c: /* original 7c01, guest PC 0x0c04746c */
if(!s->budget--) { s->failed_pc=0x0c04746cu; return 0; }
r[12]+=0x00000001u;
goto P_0c04746e;
P_0c04746e: /* original 3cb3, guest PC 0x0c04746e */
if(!s->budget--) { s->failed_pc=0x0c04746eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[11])!=0);
goto P_0c047470;
P_0c047470: /* original 8bdd, guest PC 0x0c047470 */
if(!s->budget--) { s->failed_pc=0x0c047470u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04742e; }
goto P_0c047472;
P_0c047472: /* original a01a, guest PC 0x0c047472 */
if(!s->budget--) { s->failed_pc=0x0c047472u; return 0; }
goto P_0c0474aa;
P_0c047474: /* original 0009, guest PC 0x0c047474 */
if(!s->budget--) { s->failed_pc=0x0c047474u; return 0; }
if(!vf3_matrix_family(0x0c047476u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c047476u; return 0; } return 1;
P_0c047480: /* original 6763, guest PC 0x0c047480 */
if(!s->budget--) { s->failed_pc=0x0c047480u; return 0; }
r[7]=r[6];
goto P_0c047482;
P_0c047482: /* original 6e63, guest PC 0x0c047482 */
if(!s->budget--) { s->failed_pc=0x0c047482u; return 0; }
r[14]=r[6];
goto P_0c047484;
P_0c047484: /* original 495c, guest PC 0x0c047484 */
if(!s->budget--) { s->failed_pc=0x0c047484u; return 0; }
r[9]=(r[5]&0x80000000u)?((r[5]&31u)?(uint32_t)((int32_t)r[9]>>((-r[5])&31u)):((int32_t)r[9]<0?0xffffffffu:0)):r[9]<<(r[5]&31u);
goto P_0c047486;
P_0c047486: /* original 6463, guest PC 0x0c047486 */
if(!s->budget--) { s->failed_pc=0x0c047486u; return 0; }
r[4]=r[6];
goto P_0c047488;
P_0c047488: /* original 66f2, guest PC 0x0c047488 */
if(!s->budget--) { s->failed_pc=0x0c047488u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04748a;
P_0c04748a: /* original 6c93, guest PC 0x0c04748a */
if(!s->budget--) { s->failed_pc=0x0c04748au; return 0; }
r[12]=r[9];
goto P_0c04748c;
P_0c04748c: /* original edff, guest PC 0x0c04748c */
if(!s->budget--) { s->failed_pc=0x0c04748cu; return 0; }
r[13]=0xffffffffu;
goto P_0c04748e;
P_0c04748e: /* original 7cff, guest PC 0x0c04748e */
if(!s->budget--) { s->failed_pc=0x0c04748eu; return 0; }
r[12]+=0xffffffffu;
goto P_0c047490;
P_0c047490: /* original 6361, guest PC 0x0c047490 */
if(!s->budget--) { s->failed_pc=0x0c047490u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c047492;
P_0c047492: /* original 23c8, guest PC 0x0c047492 */
if(!s->budget--) { s->failed_pc=0x0c047492u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c047494;
P_0c047494: /* original 8b04, guest PC 0x0c047494 */
if(!s->budget--) { s->failed_pc=0x0c047494u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0474a0; }
goto P_0c047496;
P_0c047496: /* original 6d73, guest PC 0x0c047496 */
if(!s->budget--) { s->failed_pc=0x0c047496u; return 0; }
r[13]=r[7];
goto P_0c047498;
P_0c047498: /* original a007, guest PC 0x0c047498 */
if(!s->budget--) { s->failed_pc=0x0c047498u; return 0; }
r[4]=r[5];
goto P_0c0474aa;
P_0c04749a: /* original 6453, guest PC 0x0c04749a */
if(!s->budget--) { s->failed_pc=0x0c04749au; return 0; }
r[4]=r[5];
if(!vf3_matrix_family(0x0c04749cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04749cu; return 0; } return 1;
P_0c0474a0: /* original 7e01, guest PC 0x0c0474a0 */
if(!s->budget--) { s->failed_pc=0x0c0474a0u; return 0; }
r[14]+=0x00000001u;
goto P_0c0474a2;
P_0c0474a2: /* original 3eb3, guest PC 0x0c0474a2 */
if(!s->budget--) { s->failed_pc=0x0c0474a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c0474a4;
P_0c0474a4: /* original 7710, guest PC 0x0c0474a4 */
if(!s->budget--) { s->failed_pc=0x0c0474a4u; return 0; }
r[7]+=0x00000010u;
goto P_0c0474a6;
P_0c0474a6: /* original 8ff3, guest PC 0x0c0474a6 */
if(!s->budget--) { s->failed_pc=0x0c0474a6u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000002u;
if(!cond) { goto P_0c047490; }
goto P_0c0474aa;
P_0c0474a8: /* original 7602, guest PC 0x0c0474a8 */
if(!s->budget--) { s->failed_pc=0x0c0474a8u; return 0; }
r[6]+=0x00000002u;
goto P_0c0474aa;
P_0c0474aa: /* original 3453, guest PC 0x0c0474aa */
if(!s->budget--) { s->failed_pc=0x0c0474aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0474ac;
P_0c0474ac: /* original 8900, guest PC 0x0c0474ac */
if(!s->budget--) { s->failed_pc=0x0c0474acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0474b0; }
goto P_0c0474ae;
P_0c0474ae: /* original edff, guest PC 0x0c0474ae */
if(!s->budget--) { s->failed_pc=0x0c0474aeu; return 0; }
r[13]=0xffffffffu;
goto P_0c0474b0;
P_0c0474b0: /* original 7f08, guest PC 0x0c0474b0 */
if(!s->budget--) { s->failed_pc=0x0c0474b0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0474b2;
P_0c0474b2: /* original 60d3, guest PC 0x0c0474b2 */
if(!s->budget--) { s->failed_pc=0x0c0474b2u; return 0; }
r[0]=r[13];
goto P_0c0474b4;
P_0c0474b4: /* original 68f6, guest PC 0x0c0474b4 */
if(!s->budget--) { s->failed_pc=0x0c0474b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0474b6;
P_0c0474b6: /* original 69f6, guest PC 0x0c0474b6 */
if(!s->budget--) { s->failed_pc=0x0c0474b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0474b8;
P_0c0474b8: /* original 6af6, guest PC 0x0c0474b8 */
if(!s->budget--) { s->failed_pc=0x0c0474b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0474ba;
P_0c0474ba: /* original 6bf6, guest PC 0x0c0474ba */
if(!s->budget--) { s->failed_pc=0x0c0474bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0474bc;
P_0c0474bc: /* original 6cf6, guest PC 0x0c0474bc */
if(!s->budget--) { s->failed_pc=0x0c0474bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0474be;
P_0c0474be: /* original 6df6, guest PC 0x0c0474be */
if(!s->budget--) { s->failed_pc=0x0c0474beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0474c0;
P_0c0474c0: /* original 000b, guest PC 0x0c0474c0 */
if(!s->budget--) { s->failed_pc=0x0c0474c0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0474c2: /* original 6ef6, guest PC 0x0c0474c2 */
if(!s->budget--) { s->failed_pc=0x0c0474c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0474c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0474c4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
