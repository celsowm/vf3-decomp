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
int vf3_away_batch80_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09fc8eu: goto P_0c09fc8e;
case 0x0c09fc90u: goto P_0c09fc90;
case 0x0c09fc92u: goto P_0c09fc92;
case 0x0c09fc94u: goto P_0c09fc94;
case 0x0c09fc96u: goto P_0c09fc96;
case 0x0c09fc98u: goto P_0c09fc98;
case 0x0c09fc9au: goto P_0c09fc9a;
case 0x0c09fc9cu: goto P_0c09fc9c;
case 0x0c09fc9eu: goto P_0c09fc9e;
case 0x0c09fca0u: goto P_0c09fca0;
case 0x0c09fca2u: goto P_0c09fca2;
case 0x0c09fca4u: goto P_0c09fca4;
case 0x0c09fca6u: goto P_0c09fca6;
case 0x0c09fca8u: goto P_0c09fca8;
case 0x0c09fcaau: goto P_0c09fcaa;
case 0x0c09fcacu: goto P_0c09fcac;
case 0x0c09fcaeu: goto P_0c09fcae;
case 0x0c09fcb0u: goto P_0c09fcb0;
case 0x0c09fcb2u: goto P_0c09fcb2;
case 0x0c09fcb4u: goto P_0c09fcb4;
case 0x0c09fcb6u: goto P_0c09fcb6;
case 0x0c09fcb8u: goto P_0c09fcb8;
case 0x0c09fcbau: goto P_0c09fcba;
case 0x0c09fcbcu: goto P_0c09fcbc;
case 0x0c09fcbeu: goto P_0c09fcbe;
case 0x0c09fcc0u: goto P_0c09fcc0;
case 0x0c09fcc2u: goto P_0c09fcc2;
case 0x0c09fcc4u: goto P_0c09fcc4;
case 0x0c09fcc6u: goto P_0c09fcc6;
case 0x0c09fcc8u: goto P_0c09fcc8;
case 0x0c09fccau: goto P_0c09fcca;
case 0x0c09fcccu: goto P_0c09fccc;
case 0x0c09fcceu: goto P_0c09fcce;
case 0x0c09fcd0u: goto P_0c09fcd0;
case 0x0c09fcf4u: goto P_0c09fcf4;
case 0x0c09fcf6u: goto P_0c09fcf6;
case 0x0c09fcf8u: goto P_0c09fcf8;
case 0x0c09fcfau: goto P_0c09fcfa;
case 0x0c09fcfcu: goto P_0c09fcfc;
case 0x0c09fcfeu: goto P_0c09fcfe;
case 0x0c09fd00u: goto P_0c09fd00;
case 0x0c09fd02u: goto P_0c09fd02;
case 0x0c09fd04u: goto P_0c09fd04;
case 0x0c09fd06u: goto P_0c09fd06;
case 0x0c09fd08u: goto P_0c09fd08;
case 0x0c09fd0au: goto P_0c09fd0a;
case 0x0c09fd0cu: goto P_0c09fd0c;
case 0x0c09fd0eu: goto P_0c09fd0e;
case 0x0c09fd10u: goto P_0c09fd10;
case 0x0c09fd12u: goto P_0c09fd12;
case 0x0c09fd14u: goto P_0c09fd14;
case 0x0c09fd16u: goto P_0c09fd16;
case 0x0c09fd18u: goto P_0c09fd18;
case 0x0c09fd1au: goto P_0c09fd1a;
case 0x0c09fd1cu: goto P_0c09fd1c;
case 0x0c09fd1eu: goto P_0c09fd1e;
case 0x0c09fd20u: goto P_0c09fd20;
case 0x0c09fd22u: goto P_0c09fd22;
case 0x0c09fd24u: goto P_0c09fd24;
case 0x0c09fd26u: goto P_0c09fd26;
case 0x0c09fd28u: goto P_0c09fd28;
case 0x0c09fd2au: goto P_0c09fd2a;
case 0x0c09fd2cu: goto P_0c09fd2c;
case 0x0c09fd2eu: goto P_0c09fd2e;
case 0x0c09fd30u: goto P_0c09fd30;
case 0x0c09fd32u: goto P_0c09fd32;
case 0x0c09fd34u: goto P_0c09fd34;
case 0x0c09fd36u: goto P_0c09fd36;
case 0x0c09fd38u: goto P_0c09fd38;
case 0x0c09fd3au: goto P_0c09fd3a;
case 0x0c09fd3cu: goto P_0c09fd3c;
case 0x0c09fd3eu: goto P_0c09fd3e;
case 0x0c09fd40u: goto P_0c09fd40;
case 0x0c09fd42u: goto P_0c09fd42;
case 0x0c09fd44u: goto P_0c09fd44;
case 0x0c09fd46u: goto P_0c09fd46;
case 0x0c09fd48u: goto P_0c09fd48;
case 0x0c09fd4au: goto P_0c09fd4a;
case 0x0c09fd4cu: goto P_0c09fd4c;
case 0x0c09fd4eu: goto P_0c09fd4e;
case 0x0c09fd50u: goto P_0c09fd50;
case 0x0c09fd52u: goto P_0c09fd52;
case 0x0c09fd54u: goto P_0c09fd54;
case 0x0c09fd56u: goto P_0c09fd56;
case 0x0c09fd58u: goto P_0c09fd58;
case 0x0c09fd5au: goto P_0c09fd5a;
case 0x0c09fd5cu: goto P_0c09fd5c;
case 0x0c09fd5eu: goto P_0c09fd5e;
case 0x0c09fd60u: goto P_0c09fd60;
case 0x0c09fd62u: goto P_0c09fd62;
case 0x0c09fd64u: goto P_0c09fd64;
case 0x0c09fd66u: goto P_0c09fd66;
case 0x0c09fd68u: goto P_0c09fd68;
case 0x0c09fd6au: goto P_0c09fd6a;
case 0x0c09fd6cu: goto P_0c09fd6c;
case 0x0c09fd6eu: goto P_0c09fd6e;
case 0x0c09fd70u: goto P_0c09fd70;
case 0x0c09fd72u: goto P_0c09fd72;
case 0x0c09fd74u: goto P_0c09fd74;
case 0x0c09fd76u: goto P_0c09fd76;
case 0x0c09fd78u: goto P_0c09fd78;
case 0x0c09fd7au: goto P_0c09fd7a;
case 0x0c09fd7cu: goto P_0c09fd7c;
case 0x0c09fd7eu: goto P_0c09fd7e;
case 0x0c09fd80u: goto P_0c09fd80;
case 0x0c09fd82u: goto P_0c09fd82;
case 0x0c09fd84u: goto P_0c09fd84;
case 0x0c09fd86u: goto P_0c09fd86;
case 0x0c09fd88u: goto P_0c09fd88;
case 0x0c09fd8au: goto P_0c09fd8a;
case 0x0c09fd8cu: goto P_0c09fd8c;
case 0x0c09fd8eu: goto P_0c09fd8e;
case 0x0c09fd90u: goto P_0c09fd90;
case 0x0c09fd92u: goto P_0c09fd92;
case 0x0c09fd94u: goto P_0c09fd94;
case 0x0c09fd96u: goto P_0c09fd96;
case 0x0c09fd98u: goto P_0c09fd98;
case 0x0c09fd9au: goto P_0c09fd9a;
case 0x0c09fd9cu: goto P_0c09fd9c;
case 0x0c09fd9eu: goto P_0c09fd9e;
case 0x0c09fda0u: goto P_0c09fda0;
case 0x0c09fda2u: goto P_0c09fda2;
case 0x0c09fda4u: goto P_0c09fda4;
case 0x0c09fda6u: goto P_0c09fda6;
case 0x0c09fda8u: goto P_0c09fda8;
case 0x0c09fdaau: goto P_0c09fdaa;
case 0x0c09fdacu: goto P_0c09fdac;
case 0x0c09fdaeu: goto P_0c09fdae;
case 0x0c09fdb0u: goto P_0c09fdb0;
case 0x0c09fdb2u: goto P_0c09fdb2;
case 0x0c09fdb4u: goto P_0c09fdb4;
case 0x0c09fdb6u: goto P_0c09fdb6;
case 0x0c09fdb8u: goto P_0c09fdb8;
case 0x0c09fdbau: goto P_0c09fdba;
case 0x0c09fdbcu: goto P_0c09fdbc;
case 0x0c09fdbeu: goto P_0c09fdbe;
case 0x0c09fdc0u: goto P_0c09fdc0;
case 0x0c09fdc2u: goto P_0c09fdc2;
case 0x0c09fdc4u: goto P_0c09fdc4;
case 0x0c09fdc6u: goto P_0c09fdc6;
case 0x0c09fdc8u: goto P_0c09fdc8;
case 0x0c09fdcau: goto P_0c09fdca;
case 0x0c09fdccu: goto P_0c09fdcc;
case 0x0c09fdceu: goto P_0c09fdce;
case 0x0c09fdd0u: goto P_0c09fdd0;
case 0x0c09fdd2u: goto P_0c09fdd2;
case 0x0c09fdd4u: goto P_0c09fdd4;
case 0x0c09fdd6u: goto P_0c09fdd6;
case 0x0c09fdd8u: goto P_0c09fdd8;
case 0x0c09fddau: goto P_0c09fdda;
case 0x0c09fddcu: goto P_0c09fddc;
case 0x0c09fddeu: goto P_0c09fdde;
case 0x0c09fde0u: goto P_0c09fde0;
case 0x0c09fde2u: goto P_0c09fde2;
case 0x0c09fde4u: goto P_0c09fde4;
case 0x0c09fde6u: goto P_0c09fde6;
case 0x0c09fde8u: goto P_0c09fde8;
case 0x0c09fdeau: goto P_0c09fdea;
case 0x0c09fdecu: goto P_0c09fdec;
case 0x0c09fdeeu: goto P_0c09fdee;
case 0x0c09fdf0u: goto P_0c09fdf0;
case 0x0c09fdf2u: goto P_0c09fdf2;
case 0x0c09fdf4u: goto P_0c09fdf4;
case 0x0c09fdf6u: goto P_0c09fdf6;
case 0x0c09fdf8u: goto P_0c09fdf8;
case 0x0c09fdfau: goto P_0c09fdfa;
case 0x0c09fdfcu: goto P_0c09fdfc;
case 0x0c09fdfeu: goto P_0c09fdfe;
case 0x0c09fe00u: goto P_0c09fe00;
case 0x0c09fe02u: goto P_0c09fe02;
case 0x0c09fe04u: goto P_0c09fe04;
case 0x0c09fe06u: goto P_0c09fe06;
case 0x0c09fe08u: goto P_0c09fe08;
case 0x0c09fe0au: goto P_0c09fe0a;
case 0x0c09fe0cu: goto P_0c09fe0c;
case 0x0c09fe0eu: goto P_0c09fe0e;
case 0x0c09fe10u: goto P_0c09fe10;
case 0x0c09fe12u: goto P_0c09fe12;
case 0x0c09fe14u: goto P_0c09fe14;
case 0x0c09fe16u: goto P_0c09fe16;
case 0x0c09fe18u: goto P_0c09fe18;
case 0x0c09fe1au: goto P_0c09fe1a;
case 0x0c09fe1cu: goto P_0c09fe1c;
case 0x0c09fe1eu: goto P_0c09fe1e;
case 0x0c09fe20u: goto P_0c09fe20;
case 0x0c09fe22u: goto P_0c09fe22;
case 0x0c09fe24u: goto P_0c09fe24;
case 0x0c09fe26u: goto P_0c09fe26;
case 0x0c0a7f14u: goto P_0c0a7f14;
case 0x0c0a7f16u: goto P_0c0a7f16;
case 0x0c0a7f18u: goto P_0c0a7f18;
case 0x0c0a7f1au: goto P_0c0a7f1a;
case 0x0c0a7f1cu: goto P_0c0a7f1c;
case 0x0c0a7f1eu: goto P_0c0a7f1e;
case 0x0c0a7f20u: goto P_0c0a7f20;
case 0x0c0a7f22u: goto P_0c0a7f22;
case 0x0c0a7f24u: goto P_0c0a7f24;
case 0x0c0a7f26u: goto P_0c0a7f26;
case 0x0c0a7f28u: goto P_0c0a7f28;
case 0x0c0a7f2au: goto P_0c0a7f2a;
case 0x0c0a7f2cu: goto P_0c0a7f2c;
case 0x0c0a7f2eu: goto P_0c0a7f2e;
case 0x0c0a7f30u: goto P_0c0a7f30;
case 0x0c0a7f32u: goto P_0c0a7f32;
case 0x0c0a7f34u: goto P_0c0a7f34;
case 0x0c0a7f36u: goto P_0c0a7f36;
case 0x0c0a7f38u: goto P_0c0a7f38;
case 0x0c0a7f3au: goto P_0c0a7f3a;
case 0x0c0a7f3cu: goto P_0c0a7f3c;
case 0x0c0a7f3eu: goto P_0c0a7f3e;
case 0x0c0a7f40u: goto P_0c0a7f40;
case 0x0c0a7f42u: goto P_0c0a7f42;
case 0x0c0a7f44u: goto P_0c0a7f44;
case 0x0c0a7f46u: goto P_0c0a7f46;
case 0x0c0a7f48u: goto P_0c0a7f48;
case 0x0c0a7f4au: goto P_0c0a7f4a;
case 0x0c0a7f4cu: goto P_0c0a7f4c;
case 0x0c0a7f4eu: goto P_0c0a7f4e;
case 0x0c0a7f50u: goto P_0c0a7f50;
case 0x0c0a7f52u: goto P_0c0a7f52;
case 0x0c0a7f54u: goto P_0c0a7f54;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09fc8e: /* original 9024, guest PC 0x0c09fc8e */
if(!s->budget--) { s->failed_pc=0x0c09fc8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdau,2);
goto P_0c09fc90;
P_0c09fc90: /* original 9224, guest PC 0x0c09fc90 */
if(!s->budget--) { s->failed_pc=0x0c09fc90u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdcu,2);
goto P_0c09fc92;
P_0c09fc92: /* original 034d, guest PC 0x0c09fc92 */
if(!s->budget--) { s->failed_pc=0x0c09fc92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09fc94;
P_0c09fc94: /* original 633d, guest PC 0x0c09fc94 */
if(!s->budget--) { s->failed_pc=0x0c09fc94u; return 0; }
r[3]=r[3]&65535u;
goto P_0c09fc96;
P_0c09fc96: /* original 3320, guest PC 0x0c09fc96 */
if(!s->budget--) { s->failed_pc=0x0c09fc96u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09fc98;
P_0c09fc98: /* original 8b05, guest PC 0x0c09fc98 */
if(!s->budget--) { s->failed_pc=0x0c09fc98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09fca6; }
goto P_0c09fc9a;
P_0c09fc9a: /* original 9120, guest PC 0x0c09fc9a */
if(!s->budget--) { s->failed_pc=0x0c09fc9au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdeu,2);
goto P_0c09fc9c;
P_0c09fc9c: /* original e008, guest PC 0x0c09fc9c */
if(!s->budget--) { s->failed_pc=0x0c09fc9cu; return 0; }
r[0]=0x00000008u;
goto P_0c09fc9e;
P_0c09fc9e: /* original f48d, guest PC 0x0c09fc9e */
if(!s->budget--) { s->failed_pc=0x0c09fc9eu; return 0; }
fr[4]=0;
goto P_0c09fca0;
P_0c09fca0: /* original 341c, guest PC 0x0c09fca0 */
if(!s->budget--) { s->failed_pc=0x0c09fca0u; return 0; }
r[4]+=r[1];
goto P_0c09fca2;
P_0c09fca2: /* original f44a, guest PC 0x0c09fca2 */
if(!s->budget--) { s->failed_pc=0x0c09fca2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09fca4;
P_0c09fca4: /* original f447, guest PC 0x0c09fca4 */
if(!s->budget--) { s->failed_pc=0x0c09fca4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09fca6;
P_0c09fca6: /* original 000b, guest PC 0x0c09fca6 */
if(!s->budget--) { s->failed_pc=0x0c09fca6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09fca8: /* original 0009, guest PC 0x0c09fca8 */
if(!s->budget--) { s->failed_pc=0x0c09fca8u; return 0; }
goto P_0c09fcaa;
P_0c09fcaa: /* original c711, guest PC 0x0c09fcaa */
if(!s->budget--) { s->failed_pc=0x0c09fcaau; return 0; }
r[0]=code_base|0x0009fcf0u;
goto P_0c09fcac;
P_0c09fcac: /* original f448, guest PC 0x0c09fcac */
if(!s->budget--) { s->failed_pc=0x0c09fcacu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcae;
P_0c09fcae: /* original f508, guest PC 0x0c09fcae */
if(!s->budget--) { s->failed_pc=0x0c09fcaeu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09fcb0;
P_0c09fcb0: /* original f451, guest PC 0x0c09fcb0 */
if(!s->budget--) { s->failed_pc=0x0c09fcb0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c09fcb2;
P_0c09fcb2: /* original f44d, guest PC 0x0c09fcb2 */
if(!s->budget--) { s->failed_pc=0x0c09fcb2u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09fcb4;
P_0c09fcb4: /* original f450, guest PC 0x0c09fcb4 */
if(!s->budget--) { s->failed_pc=0x0c09fcb4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c09fcb6;
P_0c09fcb6: /* original 000b, guest PC 0x0c09fcb6 */
if(!s->budget--) { s->failed_pc=0x0c09fcb6u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[4]);
s->pc=target; return ram->oob==0;
P_0c09fcb8: /* original f44a, guest PC 0x0c09fcb8 */
if(!s->budget--) { s->failed_pc=0x0c09fcb8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09fcba;
P_0c09fcba: /* original f358, guest PC 0x0c09fcba */
if(!s->budget--) { s->failed_pc=0x0c09fcbau; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c09fcbc;
P_0c09fcbc: /* original f448, guest PC 0x0c09fcbc */
if(!s->budget--) { s->failed_pc=0x0c09fcbcu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcbe;
P_0c09fcbe: /* original f43a, guest PC 0x0c09fcbe */
if(!s->budget--) { s->failed_pc=0x0c09fcbeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09fcc0;
P_0c09fcc0: /* original 000b, guest PC 0x0c09fcc0 */
if(!s->budget--) { s->failed_pc=0x0c09fcc0u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[5]);
s->pc=target; return ram->oob==0;
P_0c09fcc2: /* original f54a, guest PC 0x0c09fcc2 */
if(!s->budget--) { s->failed_pc=0x0c09fcc2u; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09fcc4;
P_0c09fcc4: /* original f448, guest PC 0x0c09fcc4 */
if(!s->budget--) { s->failed_pc=0x0c09fcc4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcc6;
P_0c09fcc6: /* original f558, guest PC 0x0c09fcc6 */
if(!s->budget--) { s->failed_pc=0x0c09fcc6u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c09fcc8;
P_0c09fcc8: /* original f44d, guest PC 0x0c09fcc8 */
if(!s->budget--) { s->failed_pc=0x0c09fcc8u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09fcca;
P_0c09fcca: /* original f54d, guest PC 0x0c09fcca */
if(!s->budget--) { s->failed_pc=0x0c09fccau; return 0; }
fr[5]^=0x80000000u;
goto P_0c09fccc;
P_0c09fccc: /* original f54a, guest PC 0x0c09fccc */
if(!s->budget--) { s->failed_pc=0x0c09fcccu; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09fcce;
P_0c09fcce: /* original 000b, guest PC 0x0c09fcce */
if(!s->budget--) { s->failed_pc=0x0c09fcceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]);
s->pc=target; return ram->oob==0;
P_0c09fcd0: /* original f45a, guest PC 0x0c09fcd0 */
if(!s->budget--) { s->failed_pc=0x0c09fcd0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
if(!vf3_matrix_family(0x0c09fcd2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fcd2u; return 0; } return 1;
P_0c09fcf4: /* original 2fe6, guest PC 0x0c09fcf4 */
if(!s->budget--) { s->failed_pc=0x0c09fcf4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fcf6;
P_0c09fcf6: /* original e00c, guest PC 0x0c09fcf6 */
if(!s->budget--) { s->failed_pc=0x0c09fcf6u; return 0; }
r[0]=0x0000000cu;
goto P_0c09fcf8;
P_0c09fcf8: /* original 6e43, guest PC 0x0c09fcf8 */
if(!s->budget--) { s->failed_pc=0x0c09fcf8u; return 0; }
r[14]=r[4];
goto P_0c09fcfa;
P_0c09fcfa: /* original f3e8, guest PC 0x0c09fcfa */
if(!s->budget--) { s->failed_pc=0x0c09fcfau; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c09fcfc;
P_0c09fcfc: /* original 4f22, guest PC 0x0c09fcfc */
if(!s->budget--) { s->failed_pc=0x0c09fcfcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fcfe;
P_0c09fcfe: /* original f34d, guest PC 0x0c09fcfe */
if(!s->budget--) { s->failed_pc=0x0c09fcfeu; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd00;
P_0c09fd00: /* original 65e3, guest PC 0x0c09fd00 */
if(!s->budget--) { s->failed_pc=0x0c09fd00u; return 0; }
r[5]=r[14];
goto P_0c09fd02;
P_0c09fd02: /* original fe3a, guest PC 0x0c09fd02 */
if(!s->budget--) { s->failed_pc=0x0c09fd02u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c09fd04;
P_0c09fd04: /* original 64e3, guest PC 0x0c09fd04 */
if(!s->budget--) { s->failed_pc=0x0c09fd04u; return 0; }
r[4]=r[14];
goto P_0c09fd06;
P_0c09fd06: /* original f2e6, guest PC 0x0c09fd06 */
if(!s->budget--) { s->failed_pc=0x0c09fd06u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c09fd08;
P_0c09fd08: /* original 7524, guest PC 0x0c09fd08 */
if(!s->budget--) { s->failed_pc=0x0c09fd08u; return 0; }
r[5]+=0x00000024u;
goto P_0c09fd0a;
P_0c09fd0a: /* original f24d, guest PC 0x0c09fd0a */
if(!s->budget--) { s->failed_pc=0x0c09fd0au; return 0; }
fr[2]^=0x80000000u;
goto P_0c09fd0c;
P_0c09fd0c: /* original fe27, guest PC 0x0c09fd0c */
if(!s->budget--) { s->failed_pc=0x0c09fd0cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c09fd0e;
P_0c09fd0e: /* original e018, guest PC 0x0c09fd0e */
if(!s->budget--) { s->failed_pc=0x0c09fd0eu; return 0; }
r[0]=0x00000018u;
goto P_0c09fd10;
P_0c09fd10: /* original f3e6, guest PC 0x0c09fd10 */
if(!s->budget--) { s->failed_pc=0x0c09fd10u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd12;
P_0c09fd12: /* original f34d, guest PC 0x0c09fd12 */
if(!s->budget--) { s->failed_pc=0x0c09fd12u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd14;
P_0c09fd14: /* original fe37, guest PC 0x0c09fd14 */
if(!s->budget--) { s->failed_pc=0x0c09fd14u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd16;
P_0c09fd16: /* original bfd5, guest PC 0x0c09fd16 */
if(!s->budget--) { s->failed_pc=0x0c09fd16u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd1au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd1au) { target=s->pc; goto dispatch; }
goto P_0c09fd1a;
P_0c09fd18: /* original 7430, guest PC 0x0c09fd18 */
if(!s->budget--) { s->failed_pc=0x0c09fd18u; return 0; }
r[4]+=0x00000030u;
goto P_0c09fd1a;
P_0c09fd1a: /* original 65e3, guest PC 0x0c09fd1a */
if(!s->budget--) { s->failed_pc=0x0c09fd1au; return 0; }
r[5]=r[14];
goto P_0c09fd1c;
P_0c09fd1c: /* original 64e3, guest PC 0x0c09fd1c */
if(!s->budget--) { s->failed_pc=0x0c09fd1cu; return 0; }
r[4]=r[14];
goto P_0c09fd1e;
P_0c09fd1e: /* original 7528, guest PC 0x0c09fd1e */
if(!s->budget--) { s->failed_pc=0x0c09fd1eu; return 0; }
r[5]+=0x00000028u;
goto P_0c09fd20;
P_0c09fd20: /* original bfcb, guest PC 0x0c09fd20 */
if(!s->budget--) { s->failed_pc=0x0c09fd20u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd24u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd24u) { target=s->pc; goto dispatch; }
goto P_0c09fd24;
P_0c09fd22: /* original 7434, guest PC 0x0c09fd22 */
if(!s->budget--) { s->failed_pc=0x0c09fd22u; return 0; }
r[4]+=0x00000034u;
goto P_0c09fd24;
P_0c09fd24: /* original 65e3, guest PC 0x0c09fd24 */
if(!s->budget--) { s->failed_pc=0x0c09fd24u; return 0; }
r[5]=r[14];
goto P_0c09fd26;
P_0c09fd26: /* original 64e3, guest PC 0x0c09fd26 */
if(!s->budget--) { s->failed_pc=0x0c09fd26u; return 0; }
r[4]=r[14];
goto P_0c09fd28;
P_0c09fd28: /* original 752c, guest PC 0x0c09fd28 */
if(!s->budget--) { s->failed_pc=0x0c09fd28u; return 0; }
r[5]+=0x0000002cu;
goto P_0c09fd2a;
P_0c09fd2a: /* original bfc6, guest PC 0x0c09fd2a */
if(!s->budget--) { s->failed_pc=0x0c09fd2au; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd2eu;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd2eu) { target=s->pc; goto dispatch; }
goto P_0c09fd2e;
P_0c09fd2c: /* original 7438, guest PC 0x0c09fd2c */
if(!s->budget--) { s->failed_pc=0x0c09fd2cu; return 0; }
r[4]+=0x00000038u;
goto P_0c09fd2e;
P_0c09fd2e: /* original 65e3, guest PC 0x0c09fd2e */
if(!s->budget--) { s->failed_pc=0x0c09fd2eu; return 0; }
r[5]=r[14];
goto P_0c09fd30;
P_0c09fd30: /* original 64e3, guest PC 0x0c09fd30 */
if(!s->budget--) { s->failed_pc=0x0c09fd30u; return 0; }
r[4]=r[14];
goto P_0c09fd32;
P_0c09fd32: /* original 753c, guest PC 0x0c09fd32 */
if(!s->budget--) { s->failed_pc=0x0c09fd32u; return 0; }
r[5]+=0x0000003cu;
goto P_0c09fd34;
P_0c09fd34: /* original bfc6, guest PC 0x0c09fd34 */
if(!s->budget--) { s->failed_pc=0x0c09fd34u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd38u;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd38u) { target=s->pc; goto dispatch; }
goto P_0c09fd38;
P_0c09fd36: /* original 7448, guest PC 0x0c09fd36 */
if(!s->budget--) { s->failed_pc=0x0c09fd36u; return 0; }
r[4]+=0x00000048u;
goto P_0c09fd38;
P_0c09fd38: /* original 65e3, guest PC 0x0c09fd38 */
if(!s->budget--) { s->failed_pc=0x0c09fd38u; return 0; }
r[5]=r[14];
goto P_0c09fd3a;
P_0c09fd3a: /* original 64e3, guest PC 0x0c09fd3a */
if(!s->budget--) { s->failed_pc=0x0c09fd3au; return 0; }
r[4]=r[14];
goto P_0c09fd3c;
P_0c09fd3c: /* original 7540, guest PC 0x0c09fd3c */
if(!s->budget--) { s->failed_pc=0x0c09fd3cu; return 0; }
r[5]+=0x00000040u;
goto P_0c09fd3e;
P_0c09fd3e: /* original bfbc, guest PC 0x0c09fd3e */
if(!s->budget--) { s->failed_pc=0x0c09fd3eu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd42u;
r[4]+=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd42u) { target=s->pc; goto dispatch; }
goto P_0c09fd42;
P_0c09fd40: /* original 744c, guest PC 0x0c09fd40 */
if(!s->budget--) { s->failed_pc=0x0c09fd40u; return 0; }
r[4]+=0x0000004cu;
goto P_0c09fd42;
P_0c09fd42: /* original 65e3, guest PC 0x0c09fd42 */
if(!s->budget--) { s->failed_pc=0x0c09fd42u; return 0; }
r[5]=r[14];
goto P_0c09fd44;
P_0c09fd44: /* original 64e3, guest PC 0x0c09fd44 */
if(!s->budget--) { s->failed_pc=0x0c09fd44u; return 0; }
r[4]=r[14];
goto P_0c09fd46;
P_0c09fd46: /* original 7544, guest PC 0x0c09fd46 */
if(!s->budget--) { s->failed_pc=0x0c09fd46u; return 0; }
r[5]+=0x00000044u;
goto P_0c09fd48;
P_0c09fd48: /* original bfb7, guest PC 0x0c09fd48 */
if(!s->budget--) { s->failed_pc=0x0c09fd48u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd4cu;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd4cu) { target=s->pc; goto dispatch; }
goto P_0c09fd4c;
P_0c09fd4a: /* original 7450, guest PC 0x0c09fd4a */
if(!s->budget--) { s->failed_pc=0x0c09fd4au; return 0; }
r[4]+=0x00000050u;
goto P_0c09fd4c;
P_0c09fd4c: /* original e054, guest PC 0x0c09fd4c */
if(!s->budget--) { s->failed_pc=0x0c09fd4cu; return 0; }
r[0]=0x00000054u;
goto P_0c09fd4e;
P_0c09fd4e: /* original 64e3, guest PC 0x0c09fd4e */
if(!s->budget--) { s->failed_pc=0x0c09fd4eu; return 0; }
r[4]=r[14];
goto P_0c09fd50;
P_0c09fd50: /* original f3e6, guest PC 0x0c09fd50 */
if(!s->budget--) { s->failed_pc=0x0c09fd50u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd52;
P_0c09fd52: /* original f34d, guest PC 0x0c09fd52 */
if(!s->budget--) { s->failed_pc=0x0c09fd52u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd54;
P_0c09fd54: /* original fe37, guest PC 0x0c09fd54 */
if(!s->budget--) { s->failed_pc=0x0c09fd54u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd56;
P_0c09fd56: /* original e058, guest PC 0x0c09fd56 */
if(!s->budget--) { s->failed_pc=0x0c09fd56u; return 0; }
r[0]=0x00000058u;
goto P_0c09fd58;
P_0c09fd58: /* original f3e6, guest PC 0x0c09fd58 */
if(!s->budget--) { s->failed_pc=0x0c09fd58u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd5a;
P_0c09fd5a: /* original f34d, guest PC 0x0c09fd5a */
if(!s->budget--) { s->failed_pc=0x0c09fd5au; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd5c;
P_0c09fd5c: /* original fe37, guest PC 0x0c09fd5c */
if(!s->budget--) { s->failed_pc=0x0c09fd5cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd5e;
P_0c09fd5e: /* original e060, guest PC 0x0c09fd5e */
if(!s->budget--) { s->failed_pc=0x0c09fd5eu; return 0; }
r[0]=0x00000060u;
goto P_0c09fd60;
P_0c09fd60: /* original f3e6, guest PC 0x0c09fd60 */
if(!s->budget--) { s->failed_pc=0x0c09fd60u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd62;
P_0c09fd62: /* original f34d, guest PC 0x0c09fd62 */
if(!s->budget--) { s->failed_pc=0x0c09fd62u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd64;
P_0c09fd64: /* original fe37, guest PC 0x0c09fd64 */
if(!s->budget--) { s->failed_pc=0x0c09fd64u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd66;
P_0c09fd66: /* original bfa0, guest PC 0x0c09fd66 */
if(!s->budget--) { s->failed_pc=0x0c09fd66u; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fd6au;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd6au) { target=s->pc; goto dispatch; }
goto P_0c09fd6a;
P_0c09fd68: /* original 7464, guest PC 0x0c09fd68 */
if(!s->budget--) { s->failed_pc=0x0c09fd68u; return 0; }
r[4]+=0x00000064u;
goto P_0c09fd6a;
P_0c09fd6a: /* original e068, guest PC 0x0c09fd6a */
if(!s->budget--) { s->failed_pc=0x0c09fd6au; return 0; }
r[0]=0x00000068u;
goto P_0c09fd6c;
P_0c09fd6c: /* original 64e3, guest PC 0x0c09fd6c */
if(!s->budget--) { s->failed_pc=0x0c09fd6cu; return 0; }
r[4]=r[14];
goto P_0c09fd6e;
P_0c09fd6e: /* original f3e6, guest PC 0x0c09fd6e */
if(!s->budget--) { s->failed_pc=0x0c09fd6eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd70;
P_0c09fd70: /* original f34d, guest PC 0x0c09fd70 */
if(!s->budget--) { s->failed_pc=0x0c09fd70u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd72;
P_0c09fd72: /* original fe37, guest PC 0x0c09fd72 */
if(!s->budget--) { s->failed_pc=0x0c09fd72u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd74;
P_0c09fd74: /* original bf99, guest PC 0x0c09fd74 */
if(!s->budget--) { s->failed_pc=0x0c09fd74u; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fd78u;
r[4]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd78u) { target=s->pc; goto dispatch; }
goto P_0c09fd78;
P_0c09fd76: /* original 7470, guest PC 0x0c09fd76 */
if(!s->budget--) { s->failed_pc=0x0c09fd76u; return 0; }
r[4]+=0x00000070u;
goto P_0c09fd78;
P_0c09fd78: /* original 9556, guest PC 0x0c09fd78 */
if(!s->budget--) { s->failed_pc=0x0c09fd78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe28u,2);
goto P_0c09fd7a;
P_0c09fd7a: /* original 9456, guest PC 0x0c09fd7a */
if(!s->budget--) { s->failed_pc=0x0c09fd7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2au,2);
goto P_0c09fd7c;
P_0c09fd7c: /* original 35ec, guest PC 0x0c09fd7c */
if(!s->budget--) { s->failed_pc=0x0c09fd7cu; return 0; }
r[5]+=r[14];
goto P_0c09fd7e;
P_0c09fd7e: /* original bfa1, guest PC 0x0c09fd7e */
if(!s->budget--) { s->failed_pc=0x0c09fd7eu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd82u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd82u) { target=s->pc; goto dispatch; }
goto P_0c09fd82;
P_0c09fd80: /* original 34ec, guest PC 0x0c09fd80 */
if(!s->budget--) { s->failed_pc=0x0c09fd80u; return 0; }
r[4]+=r[14];
goto P_0c09fd82;
P_0c09fd82: /* original 9453, guest PC 0x0c09fd82 */
if(!s->budget--) { s->failed_pc=0x0c09fd82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2cu,2);
goto P_0c09fd84;
P_0c09fd84: /* original 65e3, guest PC 0x0c09fd84 */
if(!s->budget--) { s->failed_pc=0x0c09fd84u; return 0; }
r[5]=r[14];
goto P_0c09fd86;
P_0c09fd86: /* original 757c, guest PC 0x0c09fd86 */
if(!s->budget--) { s->failed_pc=0x0c09fd86u; return 0; }
r[5]+=0x0000007cu;
goto P_0c09fd88;
P_0c09fd88: /* original bf9c, guest PC 0x0c09fd88 */
if(!s->budget--) { s->failed_pc=0x0c09fd88u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd8cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd8cu) { target=s->pc; goto dispatch; }
goto P_0c09fd8c;
P_0c09fd8a: /* original 34ec, guest PC 0x0c09fd8a */
if(!s->budget--) { s->failed_pc=0x0c09fd8au; return 0; }
r[4]+=r[14];
goto P_0c09fd8c;
P_0c09fd8c: /* original 944f, guest PC 0x0c09fd8c */
if(!s->budget--) { s->failed_pc=0x0c09fd8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2eu,2);
goto P_0c09fd8e;
P_0c09fd8e: /* original 65e3, guest PC 0x0c09fd8e */
if(!s->budget--) { s->failed_pc=0x0c09fd8eu; return 0; }
r[5]=r[14];
goto P_0c09fd90;
P_0c09fd90: /* original 7578, guest PC 0x0c09fd90 */
if(!s->budget--) { s->failed_pc=0x0c09fd90u; return 0; }
r[5]+=0x00000078u;
goto P_0c09fd92;
P_0c09fd92: /* original bf92, guest PC 0x0c09fd92 */
if(!s->budget--) { s->failed_pc=0x0c09fd92u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd96u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd96u) { target=s->pc; goto dispatch; }
goto P_0c09fd96;
P_0c09fd94: /* original 34ec, guest PC 0x0c09fd94 */
if(!s->budget--) { s->failed_pc=0x0c09fd94u; return 0; }
r[4]+=r[14];
goto P_0c09fd96;
P_0c09fd96: /* original 954b, guest PC 0x0c09fd96 */
if(!s->budget--) { s->failed_pc=0x0c09fd96u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe30u,2);
goto P_0c09fd98;
P_0c09fd98: /* original 944b, guest PC 0x0c09fd98 */
if(!s->budget--) { s->failed_pc=0x0c09fd98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe32u,2);
goto P_0c09fd9a;
P_0c09fd9a: /* original 35ec, guest PC 0x0c09fd9a */
if(!s->budget--) { s->failed_pc=0x0c09fd9au; return 0; }
r[5]+=r[14];
goto P_0c09fd9c;
P_0c09fd9c: /* original bf92, guest PC 0x0c09fd9c */
if(!s->budget--) { s->failed_pc=0x0c09fd9cu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fda0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fda0u) { target=s->pc; goto dispatch; }
goto P_0c09fda0;
P_0c09fd9e: /* original 34ec, guest PC 0x0c09fd9e */
if(!s->budget--) { s->failed_pc=0x0c09fd9eu; return 0; }
r[4]+=r[14];
goto P_0c09fda0;
P_0c09fda0: /* original 9548, guest PC 0x0c09fda0 */
if(!s->budget--) { s->failed_pc=0x0c09fda0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe34u,2);
goto P_0c09fda2;
P_0c09fda2: /* original 9448, guest PC 0x0c09fda2 */
if(!s->budget--) { s->failed_pc=0x0c09fda2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe36u,2);
goto P_0c09fda4;
P_0c09fda4: /* original 35ec, guest PC 0x0c09fda4 */
if(!s->budget--) { s->failed_pc=0x0c09fda4u; return 0; }
r[5]+=r[14];
goto P_0c09fda6;
P_0c09fda6: /* original bf8d, guest PC 0x0c09fda6 */
if(!s->budget--) { s->failed_pc=0x0c09fda6u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdaau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdaau) { target=s->pc; goto dispatch; }
goto P_0c09fdaa;
P_0c09fda8: /* original 34ec, guest PC 0x0c09fda8 */
if(!s->budget--) { s->failed_pc=0x0c09fda8u; return 0; }
r[4]+=r[14];
goto P_0c09fdaa;
P_0c09fdaa: /* original 9545, guest PC 0x0c09fdaa */
if(!s->budget--) { s->failed_pc=0x0c09fdaau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe38u,2);
goto P_0c09fdac;
P_0c09fdac: /* original 9445, guest PC 0x0c09fdac */
if(!s->budget--) { s->failed_pc=0x0c09fdacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3au,2);
goto P_0c09fdae;
P_0c09fdae: /* original 35ec, guest PC 0x0c09fdae */
if(!s->budget--) { s->failed_pc=0x0c09fdaeu; return 0; }
r[5]+=r[14];
goto P_0c09fdb0;
P_0c09fdb0: /* original bf83, guest PC 0x0c09fdb0 */
if(!s->budget--) { s->failed_pc=0x0c09fdb0u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fdb4u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdb4u) { target=s->pc; goto dispatch; }
goto P_0c09fdb4;
P_0c09fdb2: /* original 34ec, guest PC 0x0c09fdb2 */
if(!s->budget--) { s->failed_pc=0x0c09fdb2u; return 0; }
r[4]+=r[14];
goto P_0c09fdb4;
P_0c09fdb4: /* original 9542, guest PC 0x0c09fdb4 */
if(!s->budget--) { s->failed_pc=0x0c09fdb4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3cu,2);
goto P_0c09fdb6;
P_0c09fdb6: /* original 9442, guest PC 0x0c09fdb6 */
if(!s->budget--) { s->failed_pc=0x0c09fdb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3eu,2);
goto P_0c09fdb8;
P_0c09fdb8: /* original 35ec, guest PC 0x0c09fdb8 */
if(!s->budget--) { s->failed_pc=0x0c09fdb8u; return 0; }
r[5]+=r[14];
goto P_0c09fdba;
P_0c09fdba: /* original bf83, guest PC 0x0c09fdba */
if(!s->budget--) { s->failed_pc=0x0c09fdbau; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdbeu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdbeu) { target=s->pc; goto dispatch; }
goto P_0c09fdbe;
P_0c09fdbc: /* original 34ec, guest PC 0x0c09fdbc */
if(!s->budget--) { s->failed_pc=0x0c09fdbcu; return 0; }
r[4]+=r[14];
goto P_0c09fdbe;
P_0c09fdbe: /* original 953f, guest PC 0x0c09fdbe */
if(!s->budget--) { s->failed_pc=0x0c09fdbeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe40u,2);
goto P_0c09fdc0;
P_0c09fdc0: /* original 943f, guest PC 0x0c09fdc0 */
if(!s->budget--) { s->failed_pc=0x0c09fdc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe42u,2);
goto P_0c09fdc2;
P_0c09fdc2: /* original 35ec, guest PC 0x0c09fdc2 */
if(!s->budget--) { s->failed_pc=0x0c09fdc2u; return 0; }
r[5]+=r[14];
goto P_0c09fdc4;
P_0c09fdc4: /* original bf7e, guest PC 0x0c09fdc4 */
if(!s->budget--) { s->failed_pc=0x0c09fdc4u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdc8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdc8u) { target=s->pc; goto dispatch; }
goto P_0c09fdc8;
P_0c09fdc6: /* original 34ec, guest PC 0x0c09fdc6 */
if(!s->budget--) { s->failed_pc=0x0c09fdc6u; return 0; }
r[4]+=r[14];
goto P_0c09fdc8;
P_0c09fdc8: /* original 953c, guest PC 0x0c09fdc8 */
if(!s->budget--) { s->failed_pc=0x0c09fdc8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe44u,2);
goto P_0c09fdca;
P_0c09fdca: /* original 943c, guest PC 0x0c09fdca */
if(!s->budget--) { s->failed_pc=0x0c09fdcau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe46u,2);
goto P_0c09fdcc;
P_0c09fdcc: /* original 35ec, guest PC 0x0c09fdcc */
if(!s->budget--) { s->failed_pc=0x0c09fdccu; return 0; }
r[5]+=r[14];
goto P_0c09fdce;
P_0c09fdce: /* original bf74, guest PC 0x0c09fdce */
if(!s->budget--) { s->failed_pc=0x0c09fdceu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fdd2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdd2u) { target=s->pc; goto dispatch; }
goto P_0c09fdd2;
P_0c09fdd0: /* original 34ec, guest PC 0x0c09fdd0 */
if(!s->budget--) { s->failed_pc=0x0c09fdd0u; return 0; }
r[4]+=r[14];
goto P_0c09fdd2;
P_0c09fdd2: /* original 9039, guest PC 0x0c09fdd2 */
if(!s->budget--) { s->failed_pc=0x0c09fdd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe48u,2);
goto P_0c09fdd4;
P_0c09fdd4: /* original f3e6, guest PC 0x0c09fdd4 */
if(!s->budget--) { s->failed_pc=0x0c09fdd4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fdd6;
P_0c09fdd6: /* original f34d, guest PC 0x0c09fdd6 */
if(!s->budget--) { s->failed_pc=0x0c09fdd6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fdd8;
P_0c09fdd8: /* original fe37, guest PC 0x0c09fdd8 */
if(!s->budget--) { s->failed_pc=0x0c09fdd8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fdda;
P_0c09fdda: /* original 9436, guest PC 0x0c09fdda */
if(!s->budget--) { s->failed_pc=0x0c09fddau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4au,2);
goto P_0c09fddc;
P_0c09fddc: /* original bf65, guest PC 0x0c09fddc */
if(!s->budget--) { s->failed_pc=0x0c09fddcu; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fde0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fde0u) { target=s->pc; goto dispatch; }
goto P_0c09fde0;
P_0c09fdde: /* original 34ec, guest PC 0x0c09fdde */
if(!s->budget--) { s->failed_pc=0x0c09fddeu; return 0; }
r[4]+=r[14];
goto P_0c09fde0;
P_0c09fde0: /* original 9034, guest PC 0x0c09fde0 */
if(!s->budget--) { s->failed_pc=0x0c09fde0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4cu,2);
goto P_0c09fde2;
P_0c09fde2: /* original f3e6, guest PC 0x0c09fde2 */
if(!s->budget--) { s->failed_pc=0x0c09fde2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fde4;
P_0c09fde4: /* original f34d, guest PC 0x0c09fde4 */
if(!s->budget--) { s->failed_pc=0x0c09fde4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fde6;
P_0c09fde6: /* original fe37, guest PC 0x0c09fde6 */
if(!s->budget--) { s->failed_pc=0x0c09fde6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fde8;
P_0c09fde8: /* original 9531, guest PC 0x0c09fde8 */
if(!s->budget--) { s->failed_pc=0x0c09fde8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4eu,2);
goto P_0c09fdea;
P_0c09fdea: /* original 9431, guest PC 0x0c09fdea */
if(!s->budget--) { s->failed_pc=0x0c09fdeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe50u,2);
goto P_0c09fdec;
P_0c09fdec: /* original 35ec, guest PC 0x0c09fdec */
if(!s->budget--) { s->failed_pc=0x0c09fdecu; return 0; }
r[5]+=r[14];
goto P_0c09fdee;
P_0c09fdee: /* original bf69, guest PC 0x0c09fdee */
if(!s->budget--) { s->failed_pc=0x0c09fdeeu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdf2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdf2u) { target=s->pc; goto dispatch; }
goto P_0c09fdf2;
P_0c09fdf0: /* original 34ec, guest PC 0x0c09fdf0 */
if(!s->budget--) { s->failed_pc=0x0c09fdf0u; return 0; }
r[4]+=r[14];
goto P_0c09fdf2;
P_0c09fdf2: /* original 952e, guest PC 0x0c09fdf2 */
if(!s->budget--) { s->failed_pc=0x0c09fdf2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe52u,2);
goto P_0c09fdf4;
P_0c09fdf4: /* original 942e, guest PC 0x0c09fdf4 */
if(!s->budget--) { s->failed_pc=0x0c09fdf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe54u,2);
goto P_0c09fdf6;
P_0c09fdf6: /* original 35ec, guest PC 0x0c09fdf6 */
if(!s->budget--) { s->failed_pc=0x0c09fdf6u; return 0; }
r[5]+=r[14];
goto P_0c09fdf8;
P_0c09fdf8: /* original bf64, guest PC 0x0c09fdf8 */
if(!s->budget--) { s->failed_pc=0x0c09fdf8u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdfcu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdfcu) { target=s->pc; goto dispatch; }
goto P_0c09fdfc;
P_0c09fdfa: /* original 34ec, guest PC 0x0c09fdfa */
if(!s->budget--) { s->failed_pc=0x0c09fdfau; return 0; }
r[4]+=r[14];
goto P_0c09fdfc;
P_0c09fdfc: /* original 952b, guest PC 0x0c09fdfc */
if(!s->budget--) { s->failed_pc=0x0c09fdfcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe56u,2);
goto P_0c09fdfe;
P_0c09fdfe: /* original 942b, guest PC 0x0c09fdfe */
if(!s->budget--) { s->failed_pc=0x0c09fdfeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe58u,2);
goto P_0c09fe00;
P_0c09fe00: /* original 35ec, guest PC 0x0c09fe00 */
if(!s->budget--) { s->failed_pc=0x0c09fe00u; return 0; }
r[5]+=r[14];
goto P_0c09fe02;
P_0c09fe02: /* original bf5a, guest PC 0x0c09fe02 */
if(!s->budget--) { s->failed_pc=0x0c09fe02u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fe06u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe06u) { target=s->pc; goto dispatch; }
goto P_0c09fe06;
P_0c09fe04: /* original 34ec, guest PC 0x0c09fe04 */
if(!s->budget--) { s->failed_pc=0x0c09fe04u; return 0; }
r[4]+=r[14];
goto P_0c09fe06;
P_0c09fe06: /* original 9528, guest PC 0x0c09fe06 */
if(!s->budget--) { s->failed_pc=0x0c09fe06u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5au,2);
goto P_0c09fe08;
P_0c09fe08: /* original 9428, guest PC 0x0c09fe08 */
if(!s->budget--) { s->failed_pc=0x0c09fe08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5cu,2);
goto P_0c09fe0a;
P_0c09fe0a: /* original 35ec, guest PC 0x0c09fe0a */
if(!s->budget--) { s->failed_pc=0x0c09fe0au; return 0; }
r[5]+=r[14];
goto P_0c09fe0c;
P_0c09fe0c: /* original bf55, guest PC 0x0c09fe0c */
if(!s->budget--) { s->failed_pc=0x0c09fe0cu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fe10u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe10u) { target=s->pc; goto dispatch; }
goto P_0c09fe10;
P_0c09fe0e: /* original 34ec, guest PC 0x0c09fe0e */
if(!s->budget--) { s->failed_pc=0x0c09fe0eu; return 0; }
r[4]+=r[14];
goto P_0c09fe10;
P_0c09fe10: /* original 9525, guest PC 0x0c09fe10 */
if(!s->budget--) { s->failed_pc=0x0c09fe10u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5eu,2);
goto P_0c09fe12;
P_0c09fe12: /* original 9425, guest PC 0x0c09fe12 */
if(!s->budget--) { s->failed_pc=0x0c09fe12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe60u,2);
goto P_0c09fe14;
P_0c09fe14: /* original 35ec, guest PC 0x0c09fe14 */
if(!s->budget--) { s->failed_pc=0x0c09fe14u; return 0; }
r[5]+=r[14];
goto P_0c09fe16;
P_0c09fe16: /* original bf55, guest PC 0x0c09fe16 */
if(!s->budget--) { s->failed_pc=0x0c09fe16u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fe1au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe1au) { target=s->pc; goto dispatch; }
goto P_0c09fe1a;
P_0c09fe18: /* original 34ec, guest PC 0x0c09fe18 */
if(!s->budget--) { s->failed_pc=0x0c09fe18u; return 0; }
r[4]+=r[14];
goto P_0c09fe1a;
P_0c09fe1a: /* original 9423, guest PC 0x0c09fe1a */
if(!s->budget--) { s->failed_pc=0x0c09fe1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe64u,2);
goto P_0c09fe1c;
P_0c09fe1c: /* original 4f26, guest PC 0x0c09fe1c */
if(!s->budget--) { s->failed_pc=0x0c09fe1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09fe1e;
P_0c09fe1e: /* original 9520, guest PC 0x0c09fe1e */
if(!s->budget--) { s->failed_pc=0x0c09fe1eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe62u,2);
goto P_0c09fe20;
P_0c09fe20: /* original 34ec, guest PC 0x0c09fe20 */
if(!s->budget--) { s->failed_pc=0x0c09fe20u; return 0; }
r[4]+=r[14];
goto P_0c09fe22;
P_0c09fe22: /* original 35ec, guest PC 0x0c09fe22 */
if(!s->budget--) { s->failed_pc=0x0c09fe22u; return 0; }
r[5]+=r[14];
goto P_0c09fe24;
P_0c09fe24: /* original af4e, guest PC 0x0c09fe24 */
if(!s->budget--) { s->failed_pc=0x0c09fe24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09fcc4;
P_0c09fe26: /* original 6ef6, guest PC 0x0c09fe26 */
if(!s->budget--) { s->failed_pc=0x0c09fe26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09fe28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fe28u; return 0; } return 1;
P_0c0a7f14: /* original 2fe6, guest PC 0x0c0a7f14 */
if(!s->budget--) { s->failed_pc=0x0c0a7f14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f16;
P_0c0a7f16: /* original d324, guest PC 0x0c0a7f16 */
if(!s->budget--) { s->failed_pc=0x0c0a7f16u; return 0; }
r[3]=read(ram,0x0c0a7fa8u,4);
goto P_0c0a7f18;
P_0c0a7f18: /* original 4f12, guest PC 0x0c0a7f18 */
if(!s->budget--) { s->failed_pc=0x0c0a7f18u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a7f1a;
P_0c0a7f1a: /* original 6632, guest PC 0x0c0a7f1a */
if(!s->budget--) { s->failed_pc=0x0c0a7f1au; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0a7f1c;
P_0c0a7f1c: /* original 856d, guest PC 0x0c0a7f1c */
if(!s->budget--) { s->failed_pc=0x0c0a7f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+26,2);
goto P_0c0a7f1e;
P_0c0a7f1e: /* original 670d, guest PC 0x0c0a7f1e */
if(!s->budget--) { s->failed_pc=0x0c0a7f1eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0a7f20;
P_0c0a7f20: /* original a012, guest PC 0x0c0a7f20 */
if(!s->budget--) { s->failed_pc=0x0c0a7f20u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f48;
P_0c0a7f22: /* original ee1f, guest PC 0x0c0a7f22 */
if(!s->budget--) { s->failed_pc=0x0c0a7f22u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f24;
P_0c0a7f24: /* original 856b, guest PC 0x0c0a7f24 */
if(!s->budget--) { s->failed_pc=0x0c0a7f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a7f26;
P_0c0a7f26: /* original 600d, guest PC 0x0c0a7f26 */
if(!s->budget--) { s->failed_pc=0x0c0a7f26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a7f28;
P_0c0a7f28: /* original 3500, guest PC 0x0c0a7f28 */
if(!s->budget--) { s->failed_pc=0x0c0a7f28u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c0a7f2a;
P_0c0a7f2a: /* original 8910, guest PC 0x0c0a7f2a */
if(!s->budget--) { s->failed_pc=0x0c0a7f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7f4e; }
goto P_0c0a7f2c;
P_0c0a7f2c: /* original e334, guest PC 0x0c0a7f2c */
if(!s->budget--) { s->failed_pc=0x0c0a7f2cu; return 0; }
r[3]=0x00000034u;
goto P_0c0a7f2e;
P_0c0a7f2e: /* original 6263, guest PC 0x0c0a7f2e */
if(!s->budget--) { s->failed_pc=0x0c0a7f2eu; return 0; }
r[2]=r[6];
goto P_0c0a7f30;
P_0c0a7f30: /* original 253f, guest PC 0x0c0a7f30 */
if(!s->budget--) { s->failed_pc=0x0c0a7f30u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[3]);
goto P_0c0a7f32;
P_0c0a7f32: /* original 721c, guest PC 0x0c0a7f32 */
if(!s->budget--) { s->failed_pc=0x0c0a7f32u; return 0; }
r[2]+=0x0000001cu;
goto P_0c0a7f34;
P_0c0a7f34: /* original e030, guest PC 0x0c0a7f34 */
if(!s->budget--) { s->failed_pc=0x0c0a7f34u; return 0; }
r[0]=0x00000030u;
goto P_0c0a7f36;
P_0c0a7f36: /* original 051a, guest PC 0x0c0a7f36 */
if(!s->budget--) { s->failed_pc=0x0c0a7f36u; return 0; }
r[5]=r[19];
goto P_0c0a7f38;
P_0c0a7f38: /* original 655f, guest PC 0x0c0a7f38 */
if(!s->budget--) { s->failed_pc=0x0c0a7f38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a7f3a;
P_0c0a7f3a: /* original 352c, guest PC 0x0c0a7f3a */
if(!s->budget--) { s->failed_pc=0x0c0a7f3au; return 0; }
r[5]+=r[2];
goto P_0c0a7f3c;
P_0c0a7f3c: /* original 015d, guest PC 0x0c0a7f3c */
if(!s->budget--) { s->failed_pc=0x0c0a7f3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7f3e;
P_0c0a7f3e: /* original 3140, guest PC 0x0c0a7f3e */
if(!s->budget--) { s->failed_pc=0x0c0a7f3eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c0a7f40;
P_0c0a7f40: /* original 8b01, guest PC 0x0c0a7f40 */
if(!s->budget--) { s->failed_pc=0x0c0a7f40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7f46; }
goto P_0c0a7f42;
P_0c0a7f42: /* original a005, guest PC 0x0c0a7f42 */
if(!s->budget--) { s->failed_pc=0x0c0a7f42u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f50;
P_0c0a7f44: /* original e001, guest PC 0x0c0a7f44 */
if(!s->budget--) { s->failed_pc=0x0c0a7f44u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f46;
P_0c0a7f46: /* original 77ff, guest PC 0x0c0a7f46 */
if(!s->budget--) { s->failed_pc=0x0c0a7f46u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0a7f48;
P_0c0a7f48: /* original 6573, guest PC 0x0c0a7f48 */
if(!s->budget--) { s->failed_pc=0x0c0a7f48u; return 0; }
r[5]=r[7];
goto P_0c0a7f4a;
P_0c0a7f4a: /* original afeb, guest PC 0x0c0a7f4a */
if(!s->budget--) { s->failed_pc=0x0c0a7f4au; return 0; }
r[5]&=r[14];
goto P_0c0a7f24;
P_0c0a7f4c: /* original 25e9, guest PC 0x0c0a7f4c */
if(!s->budget--) { s->failed_pc=0x0c0a7f4cu; return 0; }
r[5]&=r[14];
goto P_0c0a7f4e;
P_0c0a7f4e: /* original e000, guest PC 0x0c0a7f4e */
if(!s->budget--) { s->failed_pc=0x0c0a7f4eu; return 0; }
r[0]=0x00000000u;
goto P_0c0a7f50;
P_0c0a7f50: /* original 4f16, guest PC 0x0c0a7f50 */
if(!s->budget--) { s->failed_pc=0x0c0a7f50u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7f52;
P_0c0a7f52: /* original 000b, guest PC 0x0c0a7f52 */
if(!s->budget--) { s->failed_pc=0x0c0a7f52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7f54: /* original 6ef6, guest PC 0x0c0a7f54 */
if(!s->budget--) { s->failed_pc=0x0c0a7f54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7f56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7f56u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
