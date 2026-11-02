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
int vf3_away_batch5_adapter_21(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04fbdcu: goto P_0c04fbdc;
case 0x0c04fbdeu: goto P_0c04fbde;
case 0x0c04fbe0u: goto P_0c04fbe0;
case 0x0c04fbe2u: goto P_0c04fbe2;
case 0x0c04fbe4u: goto P_0c04fbe4;
case 0x0c04fbe6u: goto P_0c04fbe6;
case 0x0c04fbe8u: goto P_0c04fbe8;
case 0x0c04fbeau: goto P_0c04fbea;
case 0x0c04fbecu: goto P_0c04fbec;
case 0x0c04fbeeu: goto P_0c04fbee;
case 0x0c04fbf0u: goto P_0c04fbf0;
case 0x0c04fbf2u: goto P_0c04fbf2;
case 0x0c04fbf4u: goto P_0c04fbf4;
case 0x0c04fbf6u: goto P_0c04fbf6;
case 0x0c04fbf8u: goto P_0c04fbf8;
case 0x0c04fbfau: goto P_0c04fbfa;
case 0x0c04fbfcu: goto P_0c04fbfc;
case 0x0c04fbfeu: goto P_0c04fbfe;
case 0x0c04fc00u: goto P_0c04fc00;
case 0x0c04fc02u: goto P_0c04fc02;
case 0x0c04fc04u: goto P_0c04fc04;
case 0x0c04fc06u: goto P_0c04fc06;
case 0x0c04fc08u: goto P_0c04fc08;
case 0x0c04fc0au: goto P_0c04fc0a;
case 0x0c04fc0cu: goto P_0c04fc0c;
case 0x0c04fc0eu: goto P_0c04fc0e;
case 0x0c04fc10u: goto P_0c04fc10;
case 0x0c04fc12u: goto P_0c04fc12;
case 0x0c04fc14u: goto P_0c04fc14;
case 0x0c04fc16u: goto P_0c04fc16;
case 0x0c04fc18u: goto P_0c04fc18;
case 0x0c04fc1au: goto P_0c04fc1a;
case 0x0c04fc1cu: goto P_0c04fc1c;
case 0x0c04fc1eu: goto P_0c04fc1e;
case 0x0c04fc20u: goto P_0c04fc20;
case 0x0c04fc22u: goto P_0c04fc22;
case 0x0c04fc24u: goto P_0c04fc24;
case 0x0c04fc26u: goto P_0c04fc26;
case 0x0c04fc28u: goto P_0c04fc28;
case 0x0c04fc2au: goto P_0c04fc2a;
case 0x0c04fc2cu: goto P_0c04fc2c;
case 0x0c04fc2eu: goto P_0c04fc2e;
case 0x0c04fc30u: goto P_0c04fc30;
case 0x0c04fc32u: goto P_0c04fc32;
case 0x0c04fc34u: goto P_0c04fc34;
case 0x0c04fc36u: goto P_0c04fc36;
case 0x0c04fc38u: goto P_0c04fc38;
case 0x0c04fc3au: goto P_0c04fc3a;
case 0x0c04fc3cu: goto P_0c04fc3c;
case 0x0c04fc3eu: goto P_0c04fc3e;
case 0x0c04fc40u: goto P_0c04fc40;
case 0x0c04fc42u: goto P_0c04fc42;
case 0x0c04fc44u: goto P_0c04fc44;
case 0x0c04fc46u: goto P_0c04fc46;
case 0x0c04fc48u: goto P_0c04fc48;
case 0x0c04fc4au: goto P_0c04fc4a;
case 0x0c04fc4cu: goto P_0c04fc4c;
case 0x0c04fc4eu: goto P_0c04fc4e;
case 0x0c04fc50u: goto P_0c04fc50;
case 0x0c04fc52u: goto P_0c04fc52;
case 0x0c04fc54u: goto P_0c04fc54;
case 0x0c04fc56u: goto P_0c04fc56;
case 0x0c04fc58u: goto P_0c04fc58;
case 0x0c04fc5au: goto P_0c04fc5a;
case 0x0c04fc5cu: goto P_0c04fc5c;
case 0x0c04fc5eu: goto P_0c04fc5e;
case 0x0c04fc60u: goto P_0c04fc60;
case 0x0c04fc62u: goto P_0c04fc62;
case 0x0c04fc64u: goto P_0c04fc64;
case 0x0c04fc66u: goto P_0c04fc66;
case 0x0c04fc68u: goto P_0c04fc68;
case 0x0c04fc6au: goto P_0c04fc6a;
case 0x0c04fc6cu: goto P_0c04fc6c;
case 0x0c04fc6eu: goto P_0c04fc6e;
case 0x0c04fc70u: goto P_0c04fc70;
case 0x0c04fc72u: goto P_0c04fc72;
case 0x0c04fc74u: goto P_0c04fc74;
case 0x0c04fc76u: goto P_0c04fc76;
case 0x0c04fc78u: goto P_0c04fc78;
case 0x0c04fc7au: goto P_0c04fc7a;
case 0x0c04fc7cu: goto P_0c04fc7c;
case 0x0c04fc7eu: goto P_0c04fc7e;
case 0x0c04fc80u: goto P_0c04fc80;
case 0x0c04fc82u: goto P_0c04fc82;
case 0x0c04fc84u: goto P_0c04fc84;
case 0x0c04fc86u: goto P_0c04fc86;
case 0x0c04fc88u: goto P_0c04fc88;
case 0x0c04fc8au: goto P_0c04fc8a;
case 0x0c04fc8cu: goto P_0c04fc8c;
case 0x0c04fc8eu: goto P_0c04fc8e;
case 0x0c04fc90u: goto P_0c04fc90;
case 0x0c04fc92u: goto P_0c04fc92;
case 0x0c04fc94u: goto P_0c04fc94;
case 0x0c04fc96u: goto P_0c04fc96;
case 0x0c04fc98u: goto P_0c04fc98;
case 0x0c04fc9au: goto P_0c04fc9a;
case 0x0c04fc9cu: goto P_0c04fc9c;
case 0x0c04fc9eu: goto P_0c04fc9e;
case 0x0c04fca0u: goto P_0c04fca0;
case 0x0c04fca2u: goto P_0c04fca2;
case 0x0c04fca4u: goto P_0c04fca4;
case 0x0c04fca6u: goto P_0c04fca6;
case 0x0c04fca8u: goto P_0c04fca8;
case 0x0c04fcaau: goto P_0c04fcaa;
case 0x0c04fcacu: goto P_0c04fcac;
case 0x0c04fcaeu: goto P_0c04fcae;
case 0x0c04fcb0u: goto P_0c04fcb0;
case 0x0c04fcb2u: goto P_0c04fcb2;
case 0x0c04fcb4u: goto P_0c04fcb4;
case 0x0c04fcb6u: goto P_0c04fcb6;
case 0x0c04fcb8u: goto P_0c04fcb8;
case 0x0c04fcbau: goto P_0c04fcba;
case 0x0c04fcbcu: goto P_0c04fcbc;
case 0x0c04fcbeu: goto P_0c04fcbe;
case 0x0c04fcc0u: goto P_0c04fcc0;
case 0x0c04fcc2u: goto P_0c04fcc2;
case 0x0c04fcc4u: goto P_0c04fcc4;
case 0x0c04fcc6u: goto P_0c04fcc6;
case 0x0c04fcc8u: goto P_0c04fcc8;
case 0x0c04fccau: goto P_0c04fcca;
case 0x0c04fcccu: goto P_0c04fccc;
case 0x0c04fcceu: goto P_0c04fcce;
case 0x0c04fcd0u: goto P_0c04fcd0;
case 0x0c04fcd2u: goto P_0c04fcd2;
case 0x0c04fcd4u: goto P_0c04fcd4;
case 0x0c04fcd6u: goto P_0c04fcd6;
case 0x0c04fcd8u: goto P_0c04fcd8;
case 0x0c04fcdau: goto P_0c04fcda;
case 0x0c04fcdcu: goto P_0c04fcdc;
case 0x0c04fcdeu: goto P_0c04fcde;
case 0x0c04fce0u: goto P_0c04fce0;
case 0x0c04fce2u: goto P_0c04fce2;
case 0x0c04fce4u: goto P_0c04fce4;
case 0x0c04fd0cu: goto P_0c04fd0c;
case 0x0c04fd0eu: goto P_0c04fd0e;
case 0x0c04fd10u: goto P_0c04fd10;
case 0x0c04fd12u: goto P_0c04fd12;
case 0x0c04fd14u: goto P_0c04fd14;
case 0x0c04fd16u: goto P_0c04fd16;
case 0x0c04fd18u: goto P_0c04fd18;
case 0x0c04fd1au: goto P_0c04fd1a;
case 0x0c04fd1cu: goto P_0c04fd1c;
case 0x0c04fd1eu: goto P_0c04fd1e;
case 0x0c04fd20u: goto P_0c04fd20;
case 0x0c04fd22u: goto P_0c04fd22;
case 0x0c04fd24u: goto P_0c04fd24;
case 0x0c04fd26u: goto P_0c04fd26;
case 0x0c04fd28u: goto P_0c04fd28;
case 0x0c04fd2au: goto P_0c04fd2a;
case 0x0c04fd2cu: goto P_0c04fd2c;
case 0x0c04fd2eu: goto P_0c04fd2e;
case 0x0c04fd30u: goto P_0c04fd30;
case 0x0c04fd32u: goto P_0c04fd32;
case 0x0c04fd34u: goto P_0c04fd34;
case 0x0c04fd36u: goto P_0c04fd36;
case 0x0c04fd38u: goto P_0c04fd38;
case 0x0c04fd3au: goto P_0c04fd3a;
case 0x0c04fd3cu: goto P_0c04fd3c;
case 0x0c04fd3eu: goto P_0c04fd3e;
case 0x0c04fd40u: goto P_0c04fd40;
case 0x0c04fd42u: goto P_0c04fd42;
case 0x0c04fd44u: goto P_0c04fd44;
case 0x0c04fd46u: goto P_0c04fd46;
case 0x0c04fd48u: goto P_0c04fd48;
case 0x0c04fd4au: goto P_0c04fd4a;
case 0x0c04fd4cu: goto P_0c04fd4c;
case 0x0c04fd4eu: goto P_0c04fd4e;
case 0x0c04fd50u: goto P_0c04fd50;
case 0x0c04fd52u: goto P_0c04fd52;
case 0x0c04fd54u: goto P_0c04fd54;
case 0x0c04fd56u: goto P_0c04fd56;
case 0x0c04fd58u: goto P_0c04fd58;
case 0x0c04fd5au: goto P_0c04fd5a;
case 0x0c04fd5cu: goto P_0c04fd5c;
case 0x0c04fd5eu: goto P_0c04fd5e;
case 0x0c04fd60u: goto P_0c04fd60;
case 0x0c04fd62u: goto P_0c04fd62;
case 0x0c04fd64u: goto P_0c04fd64;
case 0x0c04fd66u: goto P_0c04fd66;
case 0x0c04fd68u: goto P_0c04fd68;
case 0x0c04fd6au: goto P_0c04fd6a;
case 0x0c04fd6cu: goto P_0c04fd6c;
case 0x0c04fd6eu: goto P_0c04fd6e;
case 0x0c04fd70u: goto P_0c04fd70;
case 0x0c04fd72u: goto P_0c04fd72;
case 0x0c04fd74u: goto P_0c04fd74;
case 0x0c04fd76u: goto P_0c04fd76;
case 0x0c04fd78u: goto P_0c04fd78;
case 0x0c04fd7au: goto P_0c04fd7a;
case 0x0c04fd7cu: goto P_0c04fd7c;
case 0x0c04fd7eu: goto P_0c04fd7e;
case 0x0c04fd80u: goto P_0c04fd80;
case 0x0c04fd82u: goto P_0c04fd82;
case 0x0c04fd84u: goto P_0c04fd84;
case 0x0c04fd86u: goto P_0c04fd86;
case 0x0c04fd88u: goto P_0c04fd88;
case 0x0c04fd8au: goto P_0c04fd8a;
case 0x0c04fd8cu: goto P_0c04fd8c;
case 0x0c04fd8eu: goto P_0c04fd8e;
case 0x0c04fd90u: goto P_0c04fd90;
case 0x0c04fd92u: goto P_0c04fd92;
case 0x0c04fd94u: goto P_0c04fd94;
case 0x0c04fd96u: goto P_0c04fd96;
case 0x0c04fd98u: goto P_0c04fd98;
case 0x0c04fd9au: goto P_0c04fd9a;
case 0x0c04fd9cu: goto P_0c04fd9c;
case 0x0c04fd9eu: goto P_0c04fd9e;
case 0x0c04fda0u: goto P_0c04fda0;
case 0x0c04fda2u: goto P_0c04fda2;
case 0x0c04fda4u: goto P_0c04fda4;
case 0x0c04fda6u: goto P_0c04fda6;
case 0x0c04fda8u: goto P_0c04fda8;
case 0x0c04fdaau: goto P_0c04fdaa;
case 0x0c04fdacu: goto P_0c04fdac;
case 0x0c04fdaeu: goto P_0c04fdae;
case 0x0c04fdb0u: goto P_0c04fdb0;
case 0x0c04fdb2u: goto P_0c04fdb2;
case 0x0c04fdb4u: goto P_0c04fdb4;
case 0x0c04fdb6u: goto P_0c04fdb6;
case 0x0c04fdb8u: goto P_0c04fdb8;
case 0x0c04fdbau: goto P_0c04fdba;
case 0x0c04fdbcu: goto P_0c04fdbc;
case 0x0c04fdbeu: goto P_0c04fdbe;
case 0x0c04fdc0u: goto P_0c04fdc0;
case 0x0c04fdc2u: goto P_0c04fdc2;
case 0x0c04fdc4u: goto P_0c04fdc4;
case 0x0c04fdc6u: goto P_0c04fdc6;
case 0x0c04fdc8u: goto P_0c04fdc8;
case 0x0c04fdcau: goto P_0c04fdca;
case 0x0c04fdccu: goto P_0c04fdcc;
case 0x0c04fdceu: goto P_0c04fdce;
case 0x0c04fdd0u: goto P_0c04fdd0;
case 0x0c04fdd2u: goto P_0c04fdd2;
case 0x0c04fdd4u: goto P_0c04fdd4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04fbdc: /* original 2fe6, guest PC 0x0c04fbdc */
if(!s->budget--) { s->failed_pc=0x0c04fbdcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fbde;
P_0c04fbde: /* original 2fd6, guest PC 0x0c04fbde */
if(!s->budget--) { s->failed_pc=0x0c04fbdeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fbe0;
P_0c04fbe0: /* original 2fc6, guest PC 0x0c04fbe0 */
if(!s->budget--) { s->failed_pc=0x0c04fbe0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fbe2;
P_0c04fbe2: /* original 6c43, guest PC 0x0c04fbe2 */
if(!s->budget--) { s->failed_pc=0x0c04fbe2u; return 0; }
r[12]=r[4];
goto P_0c04fbe4;
P_0c04fbe4: /* original 2fb6, guest PC 0x0c04fbe4 */
if(!s->budget--) { s->failed_pc=0x0c04fbe4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fbe6;
P_0c04fbe6: /* original 2fa6, guest PC 0x0c04fbe6 */
if(!s->budget--) { s->failed_pc=0x0c04fbe6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fbe8;
P_0c04fbe8: /* original 2f96, guest PC 0x0c04fbe8 */
if(!s->budget--) { s->failed_pc=0x0c04fbe8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fbea;
P_0c04fbea: /* original 2f86, guest PC 0x0c04fbea */
if(!s->budget--) { s->failed_pc=0x0c04fbeau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fbec;
P_0c04fbec: /* original 4f22, guest PC 0x0c04fbec */
if(!s->budget--) { s->failed_pc=0x0c04fbecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fbee;
P_0c04fbee: /* original 9d7a, guest PC 0x0c04fbee */
if(!s->budget--) { s->failed_pc=0x0c04fbeeu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fce6u,2);
goto P_0c04fbf0;
P_0c04fbf0: /* original d33d, guest PC 0x0c04fbf0 */
if(!s->budget--) { s->failed_pc=0x0c04fbf0u; return 0; }
r[3]=read(ram,0x0c04fce8u,4);
goto P_0c04fbf2;
P_0c04fbf2: /* original 4f12, guest PC 0x0c04fbf2 */
if(!s->budget--) { s->failed_pc=0x0c04fbf2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fbf4;
P_0c04fbf4: /* original 2cdf, guest PC 0x0c04fbf4 */
if(!s->budget--) { s->failed_pc=0x0c04fbf4u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[13]);
goto P_0c04fbf6;
P_0c04fbf6: /* original d23d, guest PC 0x0c04fbf6 */
if(!s->budget--) { s->failed_pc=0x0c04fbf6u; return 0; }
r[2]=read(ram,0x0c04fcecu,4);
goto P_0c04fbf8;
P_0c04fbf8: /* original d13d, guest PC 0x0c04fbf8 */
if(!s->budget--) { s->failed_pc=0x0c04fbf8u; return 0; }
r[1]=read(ram,0x0c04fcf0u,4);
goto P_0c04fbfa;
P_0c04fbfa: /* original 0d1a, guest PC 0x0c04fbfa */
if(!s->budget--) { s->failed_pc=0x0c04fbfau; return 0; }
r[13]=r[19];
goto P_0c04fbfc;
P_0c04fbfc: /* original 6ddf, guest PC 0x0c04fbfc */
if(!s->budget--) { s->failed_pc=0x0c04fbfcu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04fbfe;
P_0c04fbfe: /* original 3d3c, guest PC 0x0c04fbfe */
if(!s->budget--) { s->failed_pc=0x0c04fbfeu; return 0; }
r[13]+=r[3];
goto P_0c04fc00;
P_0c04fc00: /* original 410b, guest PC 0x0c04fc00 */
if(!s->budget--) { s->failed_pc=0x0c04fc00u; return 0; }
target=r[1];
r[16]=code_base|0x0c04fc04u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fc04u) { target=s->pc; goto dispatch; }
goto P_0c04fc04;
P_0c04fc02: /* original 2f26, guest PC 0x0c04fc02 */
if(!s->budget--) { s->failed_pc=0x0c04fc02u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc04;
P_0c04fc04: /* original 5ad7, guest PC 0x0c04fc04 */
if(!s->budget--) { s->failed_pc=0x0c04fc04u; return 0; }
r[10]=read(ram,r[13]+28,4);
goto P_0c04fc06;
P_0c04fc06: /* original 5aa4, guest PC 0x0c04fc06 */
if(!s->budget--) { s->failed_pc=0x0c04fc06u; return 0; }
r[10]=read(ram,r[10]+16,4);
goto P_0c04fc08;
P_0c04fc08: /* original 2fa6, guest PC 0x0c04fc08 */
if(!s->budget--) { s->failed_pc=0x0c04fc08u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc0a;
P_0c04fc0a: /* original d33a, guest PC 0x0c04fc0a */
if(!s->budget--) { s->failed_pc=0x0c04fc0au; return 0; }
r[3]=read(ram,0x0c04fcf4u,4);
goto P_0c04fc0c;
P_0c04fc0c: /* original d238, guest PC 0x0c04fc0c */
if(!s->budget--) { s->failed_pc=0x0c04fc0cu; return 0; }
r[2]=read(ram,0x0c04fcf0u,4);
goto P_0c04fc0e;
P_0c04fc0e: /* original 420b, guest PC 0x0c04fc0e */
if(!s->budget--) { s->failed_pc=0x0c04fc0eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04fc12u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fc12u) { target=s->pc; goto dispatch; }
goto P_0c04fc12;
P_0c04fc10: /* original 2f36, guest PC 0x0c04fc10 */
if(!s->budget--) { s->failed_pc=0x0c04fc10u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc12;
P_0c04fc12: /* original d839, guest PC 0x0c04fc12 */
if(!s->budget--) { s->failed_pc=0x0c04fc12u; return 0; }
r[8]=read(ram,0x0c04fcf8u,4);
goto P_0c04fc14;
P_0c04fc14: /* original 4a15, guest PC 0x0c04fc14 */
if(!s->budget--) { s->failed_pc=0x0c04fc14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c04fc16;
P_0c04fc16: /* original ee00, guest PC 0x0c04fc16 */
if(!s->budget--) { s->failed_pc=0x0c04fc16u; return 0; }
r[14]=0x00000000u;
goto P_0c04fc18;
P_0c04fc18: /* original 6983, guest PC 0x0c04fc18 */
if(!s->budget--) { s->failed_pc=0x0c04fc18u; return 0; }
r[9]=r[8];
goto P_0c04fc1a;
P_0c04fc1a: /* original 7f0c, guest PC 0x0c04fc1a */
if(!s->budget--) { s->failed_pc=0x0c04fc1au; return 0; }
r[15]+=0x0000000cu;
goto P_0c04fc1c;
P_0c04fc1c: /* original 8f28, guest PC 0x0c04fc1c */
if(!s->budget--) { s->failed_pc=0x0c04fc1cu; return 0; }
cond=r[17]&1u;
r[9]+=0xfffffffbu;
if(!cond) { goto P_0c04fc70; }
goto P_0c04fc20;
P_0c04fc1e: /* original 79fb, guest PC 0x0c04fc1e */
if(!s->budget--) { s->failed_pc=0x0c04fc1eu; return 0; }
r[9]+=0xfffffffbu;
goto P_0c04fc20;
P_0c04fc20: /* original 52d7, guest PC 0x0c04fc20 */
if(!s->budget--) { s->failed_pc=0x0c04fc20u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04fc22;
P_0c04fc22: /* original 5323, guest PC 0x0c04fc22 */
if(!s->budget--) { s->failed_pc=0x0c04fc22u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c04fc24;
P_0c04fc24: /* original 33ec, guest PC 0x0c04fc24 */
if(!s->budget--) { s->failed_pc=0x0c04fc24u; return 0; }
r[3]+=r[14];
goto P_0c04fc26;
P_0c04fc26: /* original 2f36, guest PC 0x0c04fc26 */
if(!s->budget--) { s->failed_pc=0x0c04fc26u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc28;
P_0c04fc28: /* original d331, guest PC 0x0c04fc28 */
if(!s->budget--) { s->failed_pc=0x0c04fc28u; return 0; }
r[3]=read(ram,0x0c04fcf0u,4);
goto P_0c04fc2a;
P_0c04fc2a: /* original d234, guest PC 0x0c04fc2a */
if(!s->budget--) { s->failed_pc=0x0c04fc2au; return 0; }
r[2]=read(ram,0x0c04fcfcu,4);
goto P_0c04fc2c;
P_0c04fc2c: /* original 430b, guest PC 0x0c04fc2c */
if(!s->budget--) { s->failed_pc=0x0c04fc2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04fc30u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fc30u) { target=s->pc; goto dispatch; }
goto P_0c04fc30;
P_0c04fc2e: /* original 2f26, guest PC 0x0c04fc2e */
if(!s->budget--) { s->failed_pc=0x0c04fc2eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc30;
P_0c04fc30: /* original 66e3, guest PC 0x0c04fc30 */
if(!s->budget--) { s->failed_pc=0x0c04fc30u; return 0; }
r[6]=r[14];
goto P_0c04fc32;
P_0c04fc32: /* original 53d9, guest PC 0x0c04fc32 */
if(!s->budget--) { s->failed_pc=0x0c04fc32u; return 0; }
r[3]=read(ram,r[13]+36,4);
goto P_0c04fc34;
P_0c04fc34: /* original 55d7, guest PC 0x0c04fc34 */
if(!s->budget--) { s->failed_pc=0x0c04fc34u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c04fc36;
P_0c04fc36: /* original 4618, guest PC 0x0c04fc36 */
if(!s->budget--) { s->failed_pc=0x0c04fc36u; return 0; }
r[6]<<=8;
goto P_0c04fc38;
P_0c04fc38: /* original 4600, guest PC 0x0c04fc38 */
if(!s->budget--) { s->failed_pc=0x0c04fc38u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c04fc3a;
P_0c04fc3a: /* original 5553, guest PC 0x0c04fc3a */
if(!s->budget--) { s->failed_pc=0x0c04fc3au; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fc3c;
P_0c04fc3c: /* original 363c, guest PC 0x0c04fc3c */
if(!s->budget--) { s->failed_pc=0x0c04fc3cu; return 0; }
r[6]+=r[3];
goto P_0c04fc3e;
P_0c04fc3e: /* original d330, guest PC 0x0c04fc3e */
if(!s->budget--) { s->failed_pc=0x0c04fc3eu; return 0; }
r[3]=read(ram,0x0c04fd00u,4);
goto P_0c04fc40;
P_0c04fc40: /* original 7f08, guest PC 0x0c04fc40 */
if(!s->budget--) { s->failed_pc=0x0c04fc40u; return 0; }
r[15]+=0x00000008u;
goto P_0c04fc42;
P_0c04fc42: /* original 35ec, guest PC 0x0c04fc42 */
if(!s->budget--) { s->failed_pc=0x0c04fc42u; return 0; }
r[5]+=r[14];
goto P_0c04fc44;
P_0c04fc44: /* original 430b, guest PC 0x0c04fc44 */
if(!s->budget--) { s->failed_pc=0x0c04fc44u; return 0; }
target=r[3];
r[16]=code_base|0x0c04fc48u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fc48u) { target=s->pc; goto dispatch; }
goto P_0c04fc48;
P_0c04fc46: /* original 64c3, guest PC 0x0c04fc46 */
if(!s->budget--) { s->failed_pc=0x0c04fc46u; return 0; }
r[4]=r[12];
goto P_0c04fc48;
P_0c04fc48: /* original 6b03, guest PC 0x0c04fc48 */
if(!s->budget--) { s->failed_pc=0x0c04fc48u; return 0; }
r[11]=r[0];
goto P_0c04fc4a;
P_0c04fc4a: /* original 4b11, guest PC 0x0c04fc4a */
if(!s->budget--) { s->failed_pc=0x0c04fc4au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=0)!=0);
goto P_0c04fc4c;
P_0c04fc4c: /* original 8907, guest PC 0x0c04fc4c */
if(!s->budget--) { s->failed_pc=0x0c04fc4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fc5e; }
goto P_0c04fc4e;
P_0c04fc4e: /* original 55d7, guest PC 0x0c04fc4e */
if(!s->budget--) { s->failed_pc=0x0c04fc4eu; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c04fc50;
P_0c04fc50: /* original 6683, guest PC 0x0c04fc50 */
if(!s->budget--) { s->failed_pc=0x0c04fc50u; return 0; }
r[6]=r[8];
goto P_0c04fc52;
P_0c04fc52: /* original 5553, guest PC 0x0c04fc52 */
if(!s->budget--) { s->failed_pc=0x0c04fc52u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fc54;
P_0c04fc54: /* original 35ec, guest PC 0x0c04fc54 */
if(!s->budget--) { s->failed_pc=0x0c04fc54u; return 0; }
r[5]+=r[14];
goto P_0c04fc56;
P_0c04fc56: /* original b0f3, guest PC 0x0c04fc56 */
if(!s->budget--) { s->failed_pc=0x0c04fc56u; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04fc5au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fc5au) { target=s->pc; goto dispatch; }
goto P_0c04fc5a;
P_0c04fc58: /* original 64c3, guest PC 0x0c04fc58 */
if(!s->budget--) { s->failed_pc=0x0c04fc58u; return 0; }
r[4]=r[12];
goto P_0c04fc5a;
P_0c04fc5a: /* original a00a, guest PC 0x0c04fc5a */
if(!s->budget--) { s->failed_pc=0x0c04fc5au; return 0; }
r[0]=r[11];
goto P_0c04fc72;
P_0c04fc5c: /* original 60b3, guest PC 0x0c04fc5c */
if(!s->budget--) { s->failed_pc=0x0c04fc5cu; return 0; }
r[0]=r[11];
goto P_0c04fc5e;
P_0c04fc5e: /* original 55d7, guest PC 0x0c04fc5e */
if(!s->budget--) { s->failed_pc=0x0c04fc5eu; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c04fc60;
P_0c04fc60: /* original 6693, guest PC 0x0c04fc60 */
if(!s->budget--) { s->failed_pc=0x0c04fc60u; return 0; }
r[6]=r[9];
goto P_0c04fc62;
P_0c04fc62: /* original 5553, guest PC 0x0c04fc62 */
if(!s->budget--) { s->failed_pc=0x0c04fc62u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fc64;
P_0c04fc64: /* original 35ec, guest PC 0x0c04fc64 */
if(!s->budget--) { s->failed_pc=0x0c04fc64u; return 0; }
r[5]+=r[14];
goto P_0c04fc66;
P_0c04fc66: /* original b0eb, guest PC 0x0c04fc66 */
if(!s->budget--) { s->failed_pc=0x0c04fc66u; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04fc6au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fc6au) { target=s->pc; goto dispatch; }
goto P_0c04fc6a;
P_0c04fc68: /* original 64c3, guest PC 0x0c04fc68 */
if(!s->budget--) { s->failed_pc=0x0c04fc68u; return 0; }
r[4]=r[12];
goto P_0c04fc6a;
P_0c04fc6a: /* original 7e01, guest PC 0x0c04fc6a */
if(!s->budget--) { s->failed_pc=0x0c04fc6au; return 0; }
r[14]+=0x00000001u;
goto P_0c04fc6c;
P_0c04fc6c: /* original 3ea3, guest PC 0x0c04fc6c */
if(!s->budget--) { s->failed_pc=0x0c04fc6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[10])!=0);
goto P_0c04fc6e;
P_0c04fc6e: /* original 8bd7, guest PC 0x0c04fc6e */
if(!s->budget--) { s->failed_pc=0x0c04fc6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fc20; }
goto P_0c04fc70;
P_0c04fc70: /* original e000, guest PC 0x0c04fc70 */
if(!s->budget--) { s->failed_pc=0x0c04fc70u; return 0; }
r[0]=0x00000000u;
goto P_0c04fc72;
P_0c04fc72: /* original 4f16, guest PC 0x0c04fc72 */
if(!s->budget--) { s->failed_pc=0x0c04fc72u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fc74;
P_0c04fc74: /* original 4f26, guest PC 0x0c04fc74 */
if(!s->budget--) { s->failed_pc=0x0c04fc74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fc76;
P_0c04fc76: /* original 68f6, guest PC 0x0c04fc76 */
if(!s->budget--) { s->failed_pc=0x0c04fc76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04fc78;
P_0c04fc78: /* original 69f6, guest PC 0x0c04fc78 */
if(!s->budget--) { s->failed_pc=0x0c04fc78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04fc7a;
P_0c04fc7a: /* original 6af6, guest PC 0x0c04fc7a */
if(!s->budget--) { s->failed_pc=0x0c04fc7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fc7c;
P_0c04fc7c: /* original 6bf6, guest PC 0x0c04fc7c */
if(!s->budget--) { s->failed_pc=0x0c04fc7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fc7e;
P_0c04fc7e: /* original 6cf6, guest PC 0x0c04fc7e */
if(!s->budget--) { s->failed_pc=0x0c04fc7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fc80;
P_0c04fc80: /* original 6df6, guest PC 0x0c04fc80 */
if(!s->budget--) { s->failed_pc=0x0c04fc80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fc82;
P_0c04fc82: /* original 000b, guest PC 0x0c04fc82 */
if(!s->budget--) { s->failed_pc=0x0c04fc82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fc84: /* original 6ef6, guest PC 0x0c04fc84 */
if(!s->budget--) { s->failed_pc=0x0c04fc84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fc86;
P_0c04fc86: /* original 2fe6, guest PC 0x0c04fc86 */
if(!s->budget--) { s->failed_pc=0x0c04fc86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc88;
P_0c04fc88: /* original 2fd6, guest PC 0x0c04fc88 */
if(!s->budget--) { s->failed_pc=0x0c04fc88u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc8a;
P_0c04fc8a: /* original 2fc6, guest PC 0x0c04fc8a */
if(!s->budget--) { s->failed_pc=0x0c04fc8au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc8c;
P_0c04fc8c: /* original 2fb6, guest PC 0x0c04fc8c */
if(!s->budget--) { s->failed_pc=0x0c04fc8cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc8e;
P_0c04fc8e: /* original 2fa6, guest PC 0x0c04fc8e */
if(!s->budget--) { s->failed_pc=0x0c04fc8eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc90;
P_0c04fc90: /* original 6a43, guest PC 0x0c04fc90 */
if(!s->budget--) { s->failed_pc=0x0c04fc90u; return 0; }
r[10]=r[4];
goto P_0c04fc92;
P_0c04fc92: /* original 2f96, guest PC 0x0c04fc92 */
if(!s->budget--) { s->failed_pc=0x0c04fc92u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc94;
P_0c04fc94: /* original 2f86, guest PC 0x0c04fc94 */
if(!s->budget--) { s->failed_pc=0x0c04fc94u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc96;
P_0c04fc96: /* original 4f22, guest PC 0x0c04fc96 */
if(!s->budget--) { s->failed_pc=0x0c04fc96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fc98;
P_0c04fc98: /* original 9525, guest PC 0x0c04fc98 */
if(!s->budget--) { s->failed_pc=0x0c04fc98u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fce6u,2);
goto P_0c04fc9a;
P_0c04fc9a: /* original d313, guest PC 0x0c04fc9a */
if(!s->budget--) { s->failed_pc=0x0c04fc9au; return 0; }
r[3]=read(ram,0x0c04fce8u,4);
goto P_0c04fc9c;
P_0c04fc9c: /* original 4f12, guest PC 0x0c04fc9c */
if(!s->budget--) { s->failed_pc=0x0c04fc9cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fc9e;
P_0c04fc9e: /* original 2a5f, guest PC 0x0c04fc9e */
if(!s->budget--) { s->failed_pc=0x0c04fc9eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[10]*(int32_t)(int16_t)r[5]);
goto P_0c04fca0;
P_0c04fca0: /* original db18, guest PC 0x0c04fca0 */
if(!s->budget--) { s->failed_pc=0x0c04fca0u; return 0; }
r[11]=read(ram,0x0c04fd04u,4);
goto P_0c04fca2;
P_0c04fca2: /* original 051a, guest PC 0x0c04fca2 */
if(!s->budget--) { s->failed_pc=0x0c04fca2u; return 0; }
r[5]=r[19];
goto P_0c04fca4;
P_0c04fca4: /* original 655f, guest PC 0x0c04fca4 */
if(!s->budget--) { s->failed_pc=0x0c04fca4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c04fca6;
P_0c04fca6: /* original 353c, guest PC 0x0c04fca6 */
if(!s->budget--) { s->failed_pc=0x0c04fca6u; return 0; }
r[5]+=r[3];
goto P_0c04fca8;
P_0c04fca8: /* original 5457, guest PC 0x0c04fca8 */
if(!s->budget--) { s->failed_pc=0x0c04fca8u; return 0; }
r[4]=read(ram,r[5]+28,4);
goto P_0c04fcaa;
P_0c04fcaa: /* original 5948, guest PC 0x0c04fcaa */
if(!s->budget--) { s->failed_pc=0x0c04fcaau; return 0; }
r[9]=read(ram,r[4]+32,4);
goto P_0c04fcac;
P_0c04fcac: /* original 5847, guest PC 0x0c04fcac */
if(!s->budget--) { s->failed_pc=0x0c04fcacu; return 0; }
r[8]=read(ram,r[4]+28,4);
goto P_0c04fcae;
P_0c04fcae: /* original 5c44, guest PC 0x0c04fcae */
if(!s->budget--) { s->failed_pc=0x0c04fcaeu; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c04fcb0;
P_0c04fcb0: /* original 398c, guest PC 0x0c04fcb0 */
if(!s->budget--) { s->failed_pc=0x0c04fcb0u; return 0; }
r[9]+=r[8];
goto P_0c04fcb2;
P_0c04fcb2: /* original 79ff, guest PC 0x0c04fcb2 */
if(!s->budget--) { s->failed_pc=0x0c04fcb2u; return 0; }
r[9]+=0xffffffffu;
goto P_0c04fcb4;
P_0c04fcb4: /* original d314, guest PC 0x0c04fcb4 */
if(!s->budget--) { s->failed_pc=0x0c04fcb4u; return 0; }
r[3]=read(ram,0x0c04fd08u,4);
goto P_0c04fcb6;
P_0c04fcb6: /* original 65b3, guest PC 0x0c04fcb6 */
if(!s->budget--) { s->failed_pc=0x0c04fcb6u; return 0; }
r[5]=r[11];
goto P_0c04fcb8;
P_0c04fcb8: /* original 6793, guest PC 0x0c04fcb8 */
if(!s->budget--) { s->failed_pc=0x0c04fcb8u; return 0; }
r[7]=r[9];
goto P_0c04fcba;
P_0c04fcba: /* original 6683, guest PC 0x0c04fcba */
if(!s->budget--) { s->failed_pc=0x0c04fcbau; return 0; }
r[6]=r[8];
goto P_0c04fcbc;
P_0c04fcbc: /* original 430b, guest PC 0x0c04fcbc */
if(!s->budget--) { s->failed_pc=0x0c04fcbcu; return 0; }
target=r[3];
r[16]=code_base|0x0c04fcc0u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fcc0u) { target=s->pc; goto dispatch; }
goto P_0c04fcc0;
P_0c04fcbe: /* original 64a3, guest PC 0x0c04fcbe */
if(!s->budget--) { s->failed_pc=0x0c04fcbeu; return 0; }
r[4]=r[10];
goto P_0c04fcc0;
P_0c04fcc0: /* original 6d03, guest PC 0x0c04fcc0 */
if(!s->budget--) { s->failed_pc=0x0c04fcc0u; return 0; }
r[13]=r[0];
goto P_0c04fcc2;
P_0c04fcc2: /* original 4d11, guest PC 0x0c04fcc2 */
if(!s->budget--) { s->failed_pc=0x0c04fcc2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c04fcc4;
P_0c04fcc4: /* original 8901, guest PC 0x0c04fcc4 */
if(!s->budget--) { s->failed_pc=0x0c04fcc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fcca; }
goto P_0c04fcc6;
P_0c04fcc6: /* original a029, guest PC 0x0c04fcc6 */
if(!s->budget--) { s->failed_pc=0x0c04fcc6u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fd1c;
P_0c04fcc8: /* original e0ff, guest PC 0x0c04fcc8 */
if(!s->budget--) { s->failed_pc=0x0c04fcc8u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fcca;
P_0c04fcca: /* original 4c15, guest PC 0x0c04fcca */
if(!s->budget--) { s->failed_pc=0x0c04fccau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c04fccc;
P_0c04fccc: /* original 8f21, guest PC 0x0c04fccc */
if(!s->budget--) { s->failed_pc=0x0c04fcccu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c04fd12; }
goto P_0c04fcd0;
P_0c04fcce: /* original ee00, guest PC 0x0c04fcce */
if(!s->budget--) { s->failed_pc=0x0c04fcceu; return 0; }
r[14]=0x00000000u;
goto P_0c04fcd0;
P_0c04fcd0: /* original 65d3, guest PC 0x0c04fcd0 */
if(!s->budget--) { s->failed_pc=0x0c04fcd0u; return 0; }
r[5]=r[13];
goto P_0c04fcd2;
P_0c04fcd2: /* original 35e8, guest PC 0x0c04fcd2 */
if(!s->budget--) { s->failed_pc=0x0c04fcd2u; return 0; }
r[5]-=r[14];
goto P_0c04fcd4;
P_0c04fcd4: /* original b0e3, guest PC 0x0c04fcd4 */
if(!s->budget--) { s->failed_pc=0x0c04fcd4u; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c04fcd8u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fcd8u) { target=s->pc; goto dispatch; }
goto P_0c04fcd8;
P_0c04fcd6: /* original 64a3, guest PC 0x0c04fcd6 */
if(!s->budget--) { s->failed_pc=0x0c04fcd6u; return 0; }
r[4]=r[10];
goto P_0c04fcd8;
P_0c04fcd8: /* original 600d, guest PC 0x0c04fcd8 */
if(!s->budget--) { s->failed_pc=0x0c04fcd8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04fcda;
P_0c04fcda: /* original 30b0, guest PC 0x0c04fcda */
if(!s->budget--) { s->failed_pc=0x0c04fcdau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[11])!=0);
goto P_0c04fcdc;
P_0c04fcdc: /* original 8916, guest PC 0x0c04fcdc */
if(!s->budget--) { s->failed_pc=0x0c04fcdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fd0c; }
goto P_0c04fcde;
P_0c04fcde: /* original 69d3, guest PC 0x0c04fcde */
if(!s->budget--) { s->failed_pc=0x0c04fcdeu; return 0; }
r[9]=r[13];
goto P_0c04fce0;
P_0c04fce0: /* original 39e8, guest PC 0x0c04fce0 */
if(!s->budget--) { s->failed_pc=0x0c04fce0u; return 0; }
r[9]-=r[14];
goto P_0c04fce2;
P_0c04fce2: /* original a016, guest PC 0x0c04fce2 */
if(!s->budget--) { s->failed_pc=0x0c04fce2u; return 0; }
r[9]+=0xffffffffu;
goto P_0c04fd12;
P_0c04fce4: /* original 79ff, guest PC 0x0c04fce4 */
if(!s->budget--) { s->failed_pc=0x0c04fce4u; return 0; }
r[9]+=0xffffffffu;
if(!vf3_matrix_family(0x0c04fce6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fce6u; return 0; } return 1;
P_0c04fd0c: /* original 7e01, guest PC 0x0c04fd0c */
if(!s->budget--) { s->failed_pc=0x0c04fd0cu; return 0; }
r[14]+=0x00000001u;
goto P_0c04fd0e;
P_0c04fd0e: /* original 3ec3, guest PC 0x0c04fd0e */
if(!s->budget--) { s->failed_pc=0x0c04fd0eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c04fd10;
P_0c04fd10: /* original 8bde, guest PC 0x0c04fd10 */
if(!s->budget--) { s->failed_pc=0x0c04fd10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fcd0; }
goto P_0c04fd12;
P_0c04fd12: /* original 3ec0, guest PC 0x0c04fd12 */
if(!s->budget--) { s->failed_pc=0x0c04fd12u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[12])!=0);
goto P_0c04fd14;
P_0c04fd14: /* original 8bce, guest PC 0x0c04fd14 */
if(!s->budget--) { s->failed_pc=0x0c04fd14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fcb4; }
goto P_0c04fd16;
P_0c04fd16: /* original 3dc8, guest PC 0x0c04fd16 */
if(!s->budget--) { s->failed_pc=0x0c04fd16u; return 0; }
r[13]-=r[12];
goto P_0c04fd18;
P_0c04fd18: /* original 60d3, guest PC 0x0c04fd18 */
if(!s->budget--) { s->failed_pc=0x0c04fd18u; return 0; }
r[0]=r[13];
goto P_0c04fd1a;
P_0c04fd1a: /* original 7001, guest PC 0x0c04fd1a */
if(!s->budget--) { s->failed_pc=0x0c04fd1au; return 0; }
r[0]+=0x00000001u;
goto P_0c04fd1c;
P_0c04fd1c: /* original 4f16, guest PC 0x0c04fd1c */
if(!s->budget--) { s->failed_pc=0x0c04fd1cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fd1e;
P_0c04fd1e: /* original 4f26, guest PC 0x0c04fd1e */
if(!s->budget--) { s->failed_pc=0x0c04fd1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fd20;
P_0c04fd20: /* original 68f6, guest PC 0x0c04fd20 */
if(!s->budget--) { s->failed_pc=0x0c04fd20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04fd22;
P_0c04fd22: /* original 69f6, guest PC 0x0c04fd22 */
if(!s->budget--) { s->failed_pc=0x0c04fd22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04fd24;
P_0c04fd24: /* original 6af6, guest PC 0x0c04fd24 */
if(!s->budget--) { s->failed_pc=0x0c04fd24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fd26;
P_0c04fd26: /* original 6bf6, guest PC 0x0c04fd26 */
if(!s->budget--) { s->failed_pc=0x0c04fd26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fd28;
P_0c04fd28: /* original 6cf6, guest PC 0x0c04fd28 */
if(!s->budget--) { s->failed_pc=0x0c04fd28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fd2a;
P_0c04fd2a: /* original 6df6, guest PC 0x0c04fd2a */
if(!s->budget--) { s->failed_pc=0x0c04fd2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fd2c;
P_0c04fd2c: /* original 000b, guest PC 0x0c04fd2c */
if(!s->budget--) { s->failed_pc=0x0c04fd2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fd2e: /* original 6ef6, guest PC 0x0c04fd2e */
if(!s->budget--) { s->failed_pc=0x0c04fd2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fd30;
P_0c04fd30: /* original 2fe6, guest PC 0x0c04fd30 */
if(!s->budget--) { s->failed_pc=0x0c04fd30u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd32;
P_0c04fd32: /* original 2fd6, guest PC 0x0c04fd32 */
if(!s->budget--) { s->failed_pc=0x0c04fd32u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd34;
P_0c04fd34: /* original 2fc6, guest PC 0x0c04fd34 */
if(!s->budget--) { s->failed_pc=0x0c04fd34u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd36;
P_0c04fd36: /* original 6c43, guest PC 0x0c04fd36 */
if(!s->budget--) { s->failed_pc=0x0c04fd36u; return 0; }
r[12]=r[4];
goto P_0c04fd38;
P_0c04fd38: /* original 2fb6, guest PC 0x0c04fd38 */
if(!s->budget--) { s->failed_pc=0x0c04fd38u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd3a;
P_0c04fd3a: /* original 2fa6, guest PC 0x0c04fd3a */
if(!s->budget--) { s->failed_pc=0x0c04fd3au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd3c;
P_0c04fd3c: /* original ea00, guest PC 0x0c04fd3c */
if(!s->budget--) { s->failed_pc=0x0c04fd3cu; return 0; }
r[10]=0x00000000u;
goto P_0c04fd3e;
P_0c04fd3e: /* original 2f96, guest PC 0x0c04fd3e */
if(!s->budget--) { s->failed_pc=0x0c04fd3eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd40;
P_0c04fd40: /* original e901, guest PC 0x0c04fd40 */
if(!s->budget--) { s->failed_pc=0x0c04fd40u; return 0; }
r[9]=0x00000001u;
goto P_0c04fd42;
P_0c04fd42: /* original 2f86, guest PC 0x0c04fd42 */
if(!s->budget--) { s->failed_pc=0x0c04fd42u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fd44;
P_0c04fd44: /* original 6da3, guest PC 0x0c04fd44 */
if(!s->budget--) { s->failed_pc=0x0c04fd44u; return 0; }
r[13]=r[10];
goto P_0c04fd46;
P_0c04fd46: /* original 4f22, guest PC 0x0c04fd46 */
if(!s->budget--) { s->failed_pc=0x0c04fd46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fd48;
P_0c04fd48: /* original 9e45, guest PC 0x0c04fd48 */
if(!s->budget--) { s->failed_pc=0x0c04fd48u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fdd6u,2);
goto P_0c04fd4a;
P_0c04fd4a: /* original d324, guest PC 0x0c04fd4a */
if(!s->budget--) { s->failed_pc=0x0c04fd4au; return 0; }
r[3]=read(ram,0x0c04fddcu,4);
goto P_0c04fd4c;
P_0c04fd4c: /* original 4f12, guest PC 0x0c04fd4c */
if(!s->budget--) { s->failed_pc=0x0c04fd4cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fd4e;
P_0c04fd4e: /* original 2cef, guest PC 0x0c04fd4e */
if(!s->budget--) { s->failed_pc=0x0c04fd4eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[14]);
goto P_0c04fd50;
P_0c04fd50: /* original d823, guest PC 0x0c04fd50 */
if(!s->budget--) { s->failed_pc=0x0c04fd50u; return 0; }
r[8]=read(ram,0x0c04fde0u,4);
goto P_0c04fd52;
P_0c04fd52: /* original db24, guest PC 0x0c04fd52 */
if(!s->budget--) { s->failed_pc=0x0c04fd52u; return 0; }
r[11]=read(ram,0x0c04fde4u,4);
goto P_0c04fd54;
P_0c04fd54: /* original 0e1a, guest PC 0x0c04fd54 */
if(!s->budget--) { s->failed_pc=0x0c04fd54u; return 0; }
r[14]=r[19];
goto P_0c04fd56;
P_0c04fd56: /* original 6eef, guest PC 0x0c04fd56 */
if(!s->budget--) { s->failed_pc=0x0c04fd56u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fd58;
P_0c04fd58: /* original 3e3c, guest PC 0x0c04fd58 */
if(!s->budget--) { s->failed_pc=0x0c04fd58u; return 0; }
r[14]+=r[3];
goto P_0c04fd5a;
P_0c04fd5a: /* original bf3f, guest PC 0x0c04fd5a */
if(!s->budget--) { s->failed_pc=0x0c04fd5au; return 0; }
target=code_base|0x0c04fbdcu; r[16]=code_base|0x0c04fd5eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fd5eu) { target=s->pc; goto dispatch; }
goto P_0c04fd5e;
P_0c04fd5c: /* original 64c3, guest PC 0x0c04fd5c */
if(!s->budget--) { s->failed_pc=0x0c04fd5cu; return 0; }
r[4]=r[12];
goto P_0c04fd5e;
P_0c04fd5e: /* original 913b, guest PC 0x0c04fd5e */
if(!s->budget--) { s->failed_pc=0x0c04fd5eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fdd8u,2);
goto P_0c04fd60;
P_0c04fd60: /* original 3010, guest PC 0x0c04fd60 */
if(!s->budget--) { s->failed_pc=0x0c04fd60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04fd62;
P_0c04fd62: /* original 8d07, guest PC 0x0c04fd62 */
if(!s->budget--) { s->failed_pc=0x0c04fd62u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04fd74; }
goto P_0c04fd66;
P_0c04fd64: /* original 6403, guest PC 0x0c04fd64 */
if(!s->budget--) { s->failed_pc=0x0c04fd64u; return 0; }
r[4]=r[0];
goto P_0c04fd66;
P_0c04fd66: /* original 9138, guest PC 0x0c04fd66 */
if(!s->budget--) { s->failed_pc=0x0c04fd66u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fddau,2);
goto P_0c04fd68;
P_0c04fd68: /* original 3010, guest PC 0x0c04fd68 */
if(!s->budget--) { s->failed_pc=0x0c04fd68u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04fd6a;
P_0c04fd6a: /* original 8906, guest PC 0x0c04fd6a */
if(!s->budget--) { s->failed_pc=0x0c04fd6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fd7a; }
goto P_0c04fd6c;
P_0c04fd6c: /* original 8800, guest PC 0x0c04fd6c */
if(!s->budget--) { s->failed_pc=0x0c04fd6cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04fd6e;
P_0c04fd6e: /* original 8923, guest PC 0x0c04fd6e */
if(!s->budget--) { s->failed_pc=0x0c04fd6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fdb8; }
goto P_0c04fd70;
P_0c04fd70: /* original a022, guest PC 0x0c04fd70 */
if(!s->budget--) { s->failed_pc=0x0c04fd70u; return 0; }
goto P_0c04fdb8;
P_0c04fd72: /* original 0009, guest PC 0x0c04fd72 */
if(!s->budget--) { s->failed_pc=0x0c04fd72u; return 0; }
goto P_0c04fd74;
P_0c04fd74: /* original 9030, guest PC 0x0c04fd74 */
if(!s->budget--) { s->failed_pc=0x0c04fd74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fdd8u,2);
goto P_0c04fd76;
P_0c04fd76: /* original a024, guest PC 0x0c04fd76 */
if(!s->budget--) { s->failed_pc=0x0c04fd76u; return 0; }
goto P_0c04fdc2;
P_0c04fd78: /* original 0009, guest PC 0x0c04fd78 */
if(!s->budget--) { s->failed_pc=0x0c04fd78u; return 0; }
goto P_0c04fd7a;
P_0c04fd7a: /* original bf84, guest PC 0x0c04fd7a */
if(!s->budget--) { s->failed_pc=0x0c04fd7au; return 0; }
target=code_base|0x0c04fc86u; r[16]=code_base|0x0c04fd7eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fd7eu) { target=s->pc; goto dispatch; }
goto P_0c04fd7e;
P_0c04fd7c: /* original 64c3, guest PC 0x0c04fd7c */
if(!s->budget--) { s->failed_pc=0x0c04fd7cu; return 0; }
r[4]=r[12];
goto P_0c04fd7e;
P_0c04fd7e: /* original 6d03, guest PC 0x0c04fd7e */
if(!s->budget--) { s->failed_pc=0x0c04fd7eu; return 0; }
r[13]=r[0];
goto P_0c04fd80;
P_0c04fd80: /* original 4d11, guest PC 0x0c04fd80 */
if(!s->budget--) { s->failed_pc=0x0c04fd80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c04fd82;
P_0c04fd82: /* original 8902, guest PC 0x0c04fd82 */
if(!s->budget--) { s->failed_pc=0x0c04fd82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fd8a; }
goto P_0c04fd84;
P_0c04fd84: /* original 9029, guest PC 0x0c04fd84 */
if(!s->budget--) { s->failed_pc=0x0c04fd84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fddau,2);
goto P_0c04fd86;
P_0c04fd86: /* original a01c, guest PC 0x0c04fd86 */
if(!s->budget--) { s->failed_pc=0x0c04fd86u; return 0; }
goto P_0c04fdc2;
P_0c04fd88: /* original 0009, guest PC 0x0c04fd88 */
if(!s->budget--) { s->failed_pc=0x0c04fd88u; return 0; }
goto P_0c04fd8a;
P_0c04fd8a: /* original 52e7, guest PC 0x0c04fd8a */
if(!s->budget--) { s->failed_pc=0x0c04fd8au; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04fd8c;
P_0c04fd8c: /* original e546, guest PC 0x0c04fd8c */
if(!s->budget--) { s->failed_pc=0x0c04fd8cu; return 0; }
r[5]=0x00000046u;
goto P_0c04fd8e;
P_0c04fd8e: /* original 66d3, guest PC 0x0c04fd8e */
if(!s->budget--) { s->failed_pc=0x0c04fd8eu; return 0; }
r[6]=r[13];
goto P_0c04fd90;
P_0c04fd90: /* original 12d3, guest PC 0x0c04fd90 */
if(!s->budget--) { s->failed_pc=0x0c04fd90u; return 0; }
write(ram,r[2]+12,r[13],4);
goto P_0c04fd92;
P_0c04fd92: /* original 6382, guest PC 0x0c04fd92 */
if(!s->budget--) { s->failed_pc=0x0c04fd92u; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c04fd94;
P_0c04fd94: /* original 5234, guest PC 0x0c04fd94 */
if(!s->budget--) { s->failed_pc=0x0c04fd94u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04fd96;
P_0c04fd96: /* original 420b, guest PC 0x0c04fd96 */
if(!s->budget--) { s->failed_pc=0x0c04fd96u; return 0; }
target=r[2];
r[16]=code_base|0x0c04fd9au;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fd9au) { target=s->pc; goto dispatch; }
goto P_0c04fd9a;
P_0c04fd98: /* original 54e8, guest PC 0x0c04fd98 */
if(!s->budget--) { s->failed_pc=0x0c04fd98u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04fd9a;
P_0c04fd9a: /* original a007, guest PC 0x0c04fd9a */
if(!s->budget--) { s->failed_pc=0x0c04fd9au; return 0; }
r[13]=r[10];
goto P_0c04fdac;
P_0c04fd9c: /* original 6da3, guest PC 0x0c04fd9c */
if(!s->budget--) { s->failed_pc=0x0c04fd9cu; return 0; }
r[13]=r[10];
goto P_0c04fd9e;
P_0c04fd9e: /* original 55e7, guest PC 0x0c04fd9e */
if(!s->budget--) { s->failed_pc=0x0c04fd9eu; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04fda0;
P_0c04fda0: /* original 66b3, guest PC 0x0c04fda0 */
if(!s->budget--) { s->failed_pc=0x0c04fda0u; return 0; }
r[6]=r[11];
goto P_0c04fda2;
P_0c04fda2: /* original 5553, guest PC 0x0c04fda2 */
if(!s->budget--) { s->failed_pc=0x0c04fda2u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fda4;
P_0c04fda4: /* original 35dc, guest PC 0x0c04fda4 */
if(!s->budget--) { s->failed_pc=0x0c04fda4u; return 0; }
r[5]+=r[13];
goto P_0c04fda6;
P_0c04fda6: /* original b04b, guest PC 0x0c04fda6 */
if(!s->budget--) { s->failed_pc=0x0c04fda6u; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04fdaau;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fdaau) { target=s->pc; goto dispatch; }
goto P_0c04fdaa;
P_0c04fda8: /* original 64c3, guest PC 0x0c04fda8 */
if(!s->budget--) { s->failed_pc=0x0c04fda8u; return 0; }
r[4]=r[12];
goto P_0c04fdaa;
P_0c04fdaa: /* original 7d01, guest PC 0x0c04fdaa */
if(!s->budget--) { s->failed_pc=0x0c04fdaau; return 0; }
r[13]+=0x00000001u;
goto P_0c04fdac;
P_0c04fdac: /* original 52e7, guest PC 0x0c04fdac */
if(!s->budget--) { s->failed_pc=0x0c04fdacu; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04fdae;
P_0c04fdae: /* original 5324, guest PC 0x0c04fdae */
if(!s->budget--) { s->failed_pc=0x0c04fdaeu; return 0; }
r[3]=read(ram,r[2]+16,4);
goto P_0c04fdb0;
P_0c04fdb0: /* original 3d33, guest PC 0x0c04fdb0 */
if(!s->budget--) { s->failed_pc=0x0c04fdb0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c04fdb2;
P_0c04fdb2: /* original 8bf4, guest PC 0x0c04fdb2 */
if(!s->budget--) { s->failed_pc=0x0c04fdb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fd9e; }
goto P_0c04fdb4;
P_0c04fdb4: /* original afd1, guest PC 0x0c04fdb4 */
if(!s->budget--) { s->failed_pc=0x0c04fdb4u; return 0; }
r[13]=r[9];
goto P_0c04fd5a;
P_0c04fdb6: /* original 6d93, guest PC 0x0c04fdb6 */
if(!s->budget--) { s->failed_pc=0x0c04fdb6u; return 0; }
r[13]=r[9];
goto P_0c04fdb8;
P_0c04fdb8: /* original 2dd8, guest PC 0x0c04fdb8 */
if(!s->budget--) { s->failed_pc=0x0c04fdb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04fdba;
P_0c04fdba: /* original 8901, guest PC 0x0c04fdba */
if(!s->budget--) { s->failed_pc=0x0c04fdbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fdc0; }
goto P_0c04fdbc;
P_0c04fdbc: /* original be9e, guest PC 0x0c04fdbc */
if(!s->budget--) { s->failed_pc=0x0c04fdbcu; return 0; }
target=code_base|0x0c04fafcu; r[16]=code_base|0x0c04fdc0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fdc0u) { target=s->pc; goto dispatch; }
goto P_0c04fdc0;
P_0c04fdbe: /* original 64c3, guest PC 0x0c04fdbe */
if(!s->budget--) { s->failed_pc=0x0c04fdbeu; return 0; }
r[4]=r[12];
goto P_0c04fdc0;
P_0c04fdc0: /* original e000, guest PC 0x0c04fdc0 */
if(!s->budget--) { s->failed_pc=0x0c04fdc0u; return 0; }
r[0]=0x00000000u;
goto P_0c04fdc2;
P_0c04fdc2: /* original 4f16, guest PC 0x0c04fdc2 */
if(!s->budget--) { s->failed_pc=0x0c04fdc2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fdc4;
P_0c04fdc4: /* original 4f26, guest PC 0x0c04fdc4 */
if(!s->budget--) { s->failed_pc=0x0c04fdc4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fdc6;
P_0c04fdc6: /* original 68f6, guest PC 0x0c04fdc6 */
if(!s->budget--) { s->failed_pc=0x0c04fdc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04fdc8;
P_0c04fdc8: /* original 69f6, guest PC 0x0c04fdc8 */
if(!s->budget--) { s->failed_pc=0x0c04fdc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04fdca;
P_0c04fdca: /* original 6af6, guest PC 0x0c04fdca */
if(!s->budget--) { s->failed_pc=0x0c04fdcau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fdcc;
P_0c04fdcc: /* original 6bf6, guest PC 0x0c04fdcc */
if(!s->budget--) { s->failed_pc=0x0c04fdccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fdce;
P_0c04fdce: /* original 6cf6, guest PC 0x0c04fdce */
if(!s->budget--) { s->failed_pc=0x0c04fdceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fdd0;
P_0c04fdd0: /* original 6df6, guest PC 0x0c04fdd0 */
if(!s->budget--) { s->failed_pc=0x0c04fdd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fdd2;
P_0c04fdd2: /* original 000b, guest PC 0x0c04fdd2 */
if(!s->budget--) { s->failed_pc=0x0c04fdd2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fdd4: /* original 6ef6, guest PC 0x0c04fdd4 */
if(!s->budget--) { s->failed_pc=0x0c04fdd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04fdd6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fdd6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
