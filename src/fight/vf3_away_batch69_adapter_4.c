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
int vf3_away_batch69_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03f690u: goto P_0c03f690;
case 0x0c03f692u: goto P_0c03f692;
case 0x0c03f694u: goto P_0c03f694;
case 0x0c03f696u: goto P_0c03f696;
case 0x0c03f698u: goto P_0c03f698;
case 0x0c03f69au: goto P_0c03f69a;
case 0x0c03f69cu: goto P_0c03f69c;
case 0x0c03f69eu: goto P_0c03f69e;
case 0x0c03f6a0u: goto P_0c03f6a0;
case 0x0c03f6a2u: goto P_0c03f6a2;
case 0x0c03f6a4u: goto P_0c03f6a4;
case 0x0c03f6a6u: goto P_0c03f6a6;
case 0x0c03f6a8u: goto P_0c03f6a8;
case 0x0c03f6aau: goto P_0c03f6aa;
case 0x0c03f6acu: goto P_0c03f6ac;
case 0x0c03f6aeu: goto P_0c03f6ae;
case 0x0c03f6b0u: goto P_0c03f6b0;
case 0x0c03f6b2u: goto P_0c03f6b2;
case 0x0c03f6b4u: goto P_0c03f6b4;
case 0x0c03f6b6u: goto P_0c03f6b6;
case 0x0c03f6b8u: goto P_0c03f6b8;
case 0x0c03f6c0u: goto P_0c03f6c0;
case 0x0c03f6c2u: goto P_0c03f6c2;
case 0x0c03f6c4u: goto P_0c03f6c4;
case 0x0c03f6c6u: goto P_0c03f6c6;
case 0x0c03f6c8u: goto P_0c03f6c8;
case 0x0c03f6cau: goto P_0c03f6ca;
case 0x0c03f6ccu: goto P_0c03f6cc;
case 0x0c03f6ceu: goto P_0c03f6ce;
case 0x0c03f6d0u: goto P_0c03f6d0;
case 0x0c03f6d2u: goto P_0c03f6d2;
case 0x0c03f6d4u: goto P_0c03f6d4;
case 0x0c03f6d6u: goto P_0c03f6d6;
case 0x0c03f6d8u: goto P_0c03f6d8;
case 0x0c03f6dau: goto P_0c03f6da;
case 0x0c03f6dcu: goto P_0c03f6dc;
case 0x0c03f6deu: goto P_0c03f6de;
case 0x0c03f6e0u: goto P_0c03f6e0;
case 0x0c03f6e2u: goto P_0c03f6e2;
case 0x0c03f6e4u: goto P_0c03f6e4;
case 0x0c03f6e6u: goto P_0c03f6e6;
case 0x0c03f6e8u: goto P_0c03f6e8;
case 0x0c03f6eau: goto P_0c03f6ea;
case 0x0c03f6ecu: goto P_0c03f6ec;
case 0x0c03f6eeu: goto P_0c03f6ee;
case 0x0c03f6f0u: goto P_0c03f6f0;
case 0x0c03f6f2u: goto P_0c03f6f2;
case 0x0c03f6f4u: goto P_0c03f6f4;
case 0x0c03f6f6u: goto P_0c03f6f6;
case 0x0c03f6f8u: goto P_0c03f6f8;
case 0x0c03f6fau: goto P_0c03f6fa;
case 0x0c03f6fcu: goto P_0c03f6fc;
case 0x0c03f6feu: goto P_0c03f6fe;
case 0x0c03f700u: goto P_0c03f700;
case 0x0c03f702u: goto P_0c03f702;
case 0x0c03f704u: goto P_0c03f704;
case 0x0c03f706u: goto P_0c03f706;
case 0x0c03f708u: goto P_0c03f708;
case 0x0c03f70au: goto P_0c03f70a;
case 0x0c03f70cu: goto P_0c03f70c;
case 0x0c03f70eu: goto P_0c03f70e;
case 0x0c03f710u: goto P_0c03f710;
case 0x0c03f712u: goto P_0c03f712;
case 0x0c03f714u: goto P_0c03f714;
case 0x0c03f716u: goto P_0c03f716;
case 0x0c03f718u: goto P_0c03f718;
case 0x0c03f71au: goto P_0c03f71a;
case 0x0c03f71cu: goto P_0c03f71c;
case 0x0c03f71eu: goto P_0c03f71e;
case 0x0c03f720u: goto P_0c03f720;
case 0x0c03f722u: goto P_0c03f722;
case 0x0c03f724u: goto P_0c03f724;
case 0x0c03f726u: goto P_0c03f726;
case 0x0c03f728u: goto P_0c03f728;
case 0x0c03f72au: goto P_0c03f72a;
case 0x0c03f72cu: goto P_0c03f72c;
case 0x0c03f72eu: goto P_0c03f72e;
case 0x0c03f730u: goto P_0c03f730;
case 0x0c03f732u: goto P_0c03f732;
case 0x0c03f734u: goto P_0c03f734;
case 0x0c03f736u: goto P_0c03f736;
case 0x0c03f738u: goto P_0c03f738;
case 0x0c03f73au: goto P_0c03f73a;
case 0x0c03f73cu: goto P_0c03f73c;
case 0x0c03f73eu: goto P_0c03f73e;
case 0x0c03f740u: goto P_0c03f740;
case 0x0c03f742u: goto P_0c03f742;
case 0x0c03f744u: goto P_0c03f744;
case 0x0c03f746u: goto P_0c03f746;
case 0x0c03f748u: goto P_0c03f748;
case 0x0c03f74au: goto P_0c03f74a;
case 0x0c03f74cu: goto P_0c03f74c;
case 0x0c03f74eu: goto P_0c03f74e;
case 0x0c03f750u: goto P_0c03f750;
case 0x0c03f752u: goto P_0c03f752;
case 0x0c03f754u: goto P_0c03f754;
case 0x0c03f756u: goto P_0c03f756;
case 0x0c03f758u: goto P_0c03f758;
case 0x0c03f75au: goto P_0c03f75a;
case 0x0c03f75cu: goto P_0c03f75c;
case 0x0c03f75eu: goto P_0c03f75e;
case 0x0c03f760u: goto P_0c03f760;
case 0x0c03f762u: goto P_0c03f762;
case 0x0c03f764u: goto P_0c03f764;
case 0x0c03fc90u: goto P_0c03fc90;
case 0x0c03fc92u: goto P_0c03fc92;
case 0x0c03fc94u: goto P_0c03fc94;
case 0x0c03fc96u: goto P_0c03fc96;
case 0x0c03fc98u: goto P_0c03fc98;
case 0x0c03fc9au: goto P_0c03fc9a;
case 0x0c03fc9cu: goto P_0c03fc9c;
case 0x0c03fc9eu: goto P_0c03fc9e;
case 0x0c03fca0u: goto P_0c03fca0;
case 0x0c03fca2u: goto P_0c03fca2;
case 0x0c03fca4u: goto P_0c03fca4;
case 0x0c03fca6u: goto P_0c03fca6;
case 0x0c03fca8u: goto P_0c03fca8;
case 0x0c03fcaau: goto P_0c03fcaa;
case 0x0c03fcacu: goto P_0c03fcac;
case 0x0c03fcaeu: goto P_0c03fcae;
case 0x0c03fcb0u: goto P_0c03fcb0;
case 0x0c03fcb2u: goto P_0c03fcb2;
case 0x0c03fcb4u: goto P_0c03fcb4;
case 0x0c03fcb6u: goto P_0c03fcb6;
case 0x0c03fcb8u: goto P_0c03fcb8;
case 0x0c03fcbau: goto P_0c03fcba;
case 0x0c03fcbcu: goto P_0c03fcbc;
case 0x0c03fcbeu: goto P_0c03fcbe;
case 0x0c03fcc0u: goto P_0c03fcc0;
case 0x0c03fcc2u: goto P_0c03fcc2;
case 0x0c03fcc4u: goto P_0c03fcc4;
case 0x0c03fcc6u: goto P_0c03fcc6;
case 0x0c03fcc8u: goto P_0c03fcc8;
case 0x0c03fccau: goto P_0c03fcca;
case 0x0c03fcccu: goto P_0c03fccc;
case 0x0c03fcceu: goto P_0c03fcce;
case 0x0c03fcd0u: goto P_0c03fcd0;
case 0x0c03fcd2u: goto P_0c03fcd2;
case 0x0c03fcd4u: goto P_0c03fcd4;
case 0x0c03fcd6u: goto P_0c03fcd6;
case 0x0c03fcd8u: goto P_0c03fcd8;
case 0x0c03fcdau: goto P_0c03fcda;
case 0x0c03fcdcu: goto P_0c03fcdc;
case 0x0c03fcdeu: goto P_0c03fcde;
case 0x0c03fce0u: goto P_0c03fce0;
case 0x0c03fce2u: goto P_0c03fce2;
case 0x0c03fce4u: goto P_0c03fce4;
case 0x0c03fce6u: goto P_0c03fce6;
case 0x0c03fce8u: goto P_0c03fce8;
case 0x0c03fceau: goto P_0c03fcea;
case 0x0c03fcecu: goto P_0c03fcec;
case 0x0c03fcf0u: goto P_0c03fcf0;
case 0x0c03fcf2u: goto P_0c03fcf2;
case 0x0c03fcf4u: goto P_0c03fcf4;
case 0x0c03fcf6u: goto P_0c03fcf6;
case 0x0c03fcf8u: goto P_0c03fcf8;
case 0x0c03fcfau: goto P_0c03fcfa;
case 0x0c03fcfcu: goto P_0c03fcfc;
case 0x0c03fcfeu: goto P_0c03fcfe;
case 0x0c03fd00u: goto P_0c03fd00;
case 0x0c03fd02u: goto P_0c03fd02;
case 0x0c03fd04u: goto P_0c03fd04;
case 0x0c03fd06u: goto P_0c03fd06;
case 0x0c03fd08u: goto P_0c03fd08;
case 0x0c03fd0au: goto P_0c03fd0a;
case 0x0c03fd10u: goto P_0c03fd10;
case 0x0c03fd12u: goto P_0c03fd12;
case 0x0c03fd14u: goto P_0c03fd14;
case 0x0c03fd16u: goto P_0c03fd16;
case 0x0c03fd18u: goto P_0c03fd18;
case 0x0c03fd1au: goto P_0c03fd1a;
case 0x0c03fd1cu: goto P_0c03fd1c;
case 0x0c03fd1eu: goto P_0c03fd1e;
case 0x0c03fd20u: goto P_0c03fd20;
case 0x0c03fd22u: goto P_0c03fd22;
case 0x0c03fd24u: goto P_0c03fd24;
case 0x0c03fd26u: goto P_0c03fd26;
case 0x0c03fd28u: goto P_0c03fd28;
case 0x0c03fd2au: goto P_0c03fd2a;
case 0x0c03fd2cu: goto P_0c03fd2c;
case 0x0c03fd2eu: goto P_0c03fd2e;
case 0x0c03fd30u: goto P_0c03fd30;
case 0x0c03fd32u: goto P_0c03fd32;
case 0x0c03fd34u: goto P_0c03fd34;
case 0x0c03fd36u: goto P_0c03fd36;
case 0x0c03fd38u: goto P_0c03fd38;
case 0x0c03fd3au: goto P_0c03fd3a;
case 0x0c03fd3cu: goto P_0c03fd3c;
case 0x0c03fd3eu: goto P_0c03fd3e;
case 0x0c03fd40u: goto P_0c03fd40;
case 0x0c03fd42u: goto P_0c03fd42;
case 0x0c03fd44u: goto P_0c03fd44;
case 0x0c03fd70u: goto P_0c03fd70;
case 0x0c03fd72u: goto P_0c03fd72;
case 0x0c03fd74u: goto P_0c03fd74;
case 0x0c03fd76u: goto P_0c03fd76;
case 0x0c03fd78u: goto P_0c03fd78;
case 0x0c03fd7au: goto P_0c03fd7a;
case 0x0c03fd7cu: goto P_0c03fd7c;
case 0x0c03fd7eu: goto P_0c03fd7e;
case 0x0c03fd80u: goto P_0c03fd80;
case 0x0c03fd82u: goto P_0c03fd82;
case 0x0c03fd84u: goto P_0c03fd84;
case 0x0c03fd86u: goto P_0c03fd86;
case 0x0c03fd88u: goto P_0c03fd88;
case 0x0c03fd8au: goto P_0c03fd8a;
case 0x0c03fd8cu: goto P_0c03fd8c;
case 0x0c03fd8eu: goto P_0c03fd8e;
case 0x0c03fd90u: goto P_0c03fd90;
case 0x0c03fd92u: goto P_0c03fd92;
case 0x0c03fd94u: goto P_0c03fd94;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03f690: /* original 2fe6, guest PC 0x0c03f690 */
if(!s->budget--) { s->failed_pc=0x0c03f690u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f692;
P_0c03f692: /* original e300, guest PC 0x0c03f692 */
if(!s->budget--) { s->failed_pc=0x0c03f692u; return 0; }
r[3]=0x00000000u;
goto P_0c03f694;
P_0c03f694: /* original 2fd6, guest PC 0x0c03f694 */
if(!s->budget--) { s->failed_pc=0x0c03f694u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f696;
P_0c03f696: /* original edff, guest PC 0x0c03f696 */
if(!s->budget--) { s->failed_pc=0x0c03f696u; return 0; }
r[13]=0xffffffffu;
goto P_0c03f698;
P_0c03f698: /* original 2fc6, guest PC 0x0c03f698 */
if(!s->budget--) { s->failed_pc=0x0c03f698u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69a;
P_0c03f69a: /* original 2fb6, guest PC 0x0c03f69a */
if(!s->budget--) { s->failed_pc=0x0c03f69au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69c;
P_0c03f69c: /* original 2fa6, guest PC 0x0c03f69c */
if(!s->budget--) { s->failed_pc=0x0c03f69cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69e;
P_0c03f69e: /* original 2f96, guest PC 0x0c03f69e */
if(!s->budget--) { s->failed_pc=0x0c03f69eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f6a0;
P_0c03f6a0: /* original 2f86, guest PC 0x0c03f6a0 */
if(!s->budget--) { s->failed_pc=0x0c03f6a0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f6a2;
P_0c03f6a2: /* original 4f22, guest PC 0x0c03f6a2 */
if(!s->budget--) { s->failed_pc=0x0c03f6a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f6a4;
P_0c03f6a4: /* original 4f12, guest PC 0x0c03f6a4 */
if(!s->budget--) { s->failed_pc=0x0c03f6a4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f6a6;
P_0c03f6a6: /* original 7ff0, guest PC 0x0c03f6a6 */
if(!s->budget--) { s->failed_pc=0x0c03f6a6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03f6a8;
P_0c03f6a8: /* original 1f33, guest PC 0x0c03f6a8 */
if(!s->budget--) { s->failed_pc=0x0c03f6a8u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c03f6aa;
P_0c03f6aa: /* original de3d, guest PC 0x0c03f6aa */
if(!s->budget--) { s->failed_pc=0x0c03f6aau; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f6ac;
P_0c03f6ac: /* original d838, guest PC 0x0c03f6ac */
if(!s->budget--) { s->failed_pc=0x0c03f6acu; return 0; }
r[8]=read(ram,0x0c03f790u,4);
goto P_0c03f6ae;
P_0c03f6ae: /* original dc3f, guest PC 0x0c03f6ae */
if(!s->budget--) { s->failed_pc=0x0c03f6aeu; return 0; }
r[12]=read(ram,0x0c03f7acu,4);
goto P_0c03f6b0;
P_0c03f6b0: /* original 2f42, guest PC 0x0c03f6b0 */
if(!s->budget--) { s->failed_pc=0x0c03f6b0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03f6b2;
P_0c03f6b2: /* original d23c, guest PC 0x0c03f6b2 */
if(!s->budget--) { s->failed_pc=0x0c03f6b2u; return 0; }
r[2]=read(ram,0x0c03f7a4u,4);
goto P_0c03f6b4;
P_0c03f6b4: /* original 6322, guest PC 0x0c03f6b4 */
if(!s->budget--) { s->failed_pc=0x0c03f6b4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f6b6;
P_0c03f6b6: /* original a046, guest PC 0x0c03f6b6 */
if(!s->budget--) { s->failed_pc=0x0c03f6b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03f746;
P_0c03f6b8: /* original 1f31, guest PC 0x0c03f6b8 */
if(!s->budget--) { s->failed_pc=0x0c03f6b8u; return 0; }
write(ram,r[15]+4,r[3],4);
if(!vf3_matrix_family(0x0c03f6bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f6bau; return 0; } return 1;
P_0c03f6c0: /* original 59f1, guest PC 0x0c03f6c0 */
if(!s->budget--) { s->failed_pc=0x0c03f6c0u; return 0; }
r[9]=read(ram,r[15]+4,4);
goto P_0c03f6c2;
P_0c03f6c2: /* original e200, guest PC 0x0c03f6c2 */
if(!s->budget--) { s->failed_pc=0x0c03f6c2u; return 0; }
r[2]=0x00000000u;
goto P_0c03f6c4;
P_0c03f6c4: /* original 63e2, guest PC 0x0c03f6c4 */
if(!s->budget--) { s->failed_pc=0x0c03f6c4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f6c6;
P_0c03f6c6: /* original 6b93, guest PC 0x0c03f6c6 */
if(!s->budget--) { s->failed_pc=0x0c03f6c6u; return 0; }
r[11]=r[9];
goto P_0c03f6c8;
P_0c03f6c8: /* original 4b08, guest PC 0x0c03f6c8 */
if(!s->budget--) { s->failed_pc=0x0c03f6c8u; return 0; }
r[11]<<=2;
goto P_0c03f6ca;
P_0c03f6ca: /* original 4b00, guest PC 0x0c03f6ca */
if(!s->budget--) { s->failed_pc=0x0c03f6cau; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c03f6cc;
P_0c03f6cc: /* original 33bc, guest PC 0x0c03f6cc */
if(!s->budget--) { s->failed_pc=0x0c03f6ccu; return 0; }
r[3]+=r[11];
goto P_0c03f6ce;
P_0c03f6ce: /* original 6132, guest PC 0x0c03f6ce */
if(!s->budget--) { s->failed_pc=0x0c03f6ceu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c03f6d0;
P_0c03f6d0: /* original 3126, guest PC 0x0c03f6d0 */
if(!s->budget--) { s->failed_pc=0x0c03f6d0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c03f6d2;
P_0c03f6d2: /* original 8b32, guest PC 0x0c03f6d2 */
if(!s->budget--) { s->failed_pc=0x0c03f6d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f73a; }
goto P_0c03f6d4;
P_0c03f6d4: /* original 60e2, guest PC 0x0c03f6d4 */
if(!s->budget--) { s->failed_pc=0x0c03f6d4u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03f6d6;
P_0c03f6d6: /* original 30bc, guest PC 0x0c03f6d6 */
if(!s->budget--) { s->failed_pc=0x0c03f6d6u; return 0; }
r[0]+=r[11];
goto P_0c03f6d8;
P_0c03f6d8: /* original 6302, guest PC 0x0c03f6d8 */
if(!s->budget--) { s->failed_pc=0x0c03f6d8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c03f6da;
P_0c03f6da: /* original 73ff, guest PC 0x0c03f6da */
if(!s->budget--) { s->failed_pc=0x0c03f6dau; return 0; }
r[3]+=0xffffffffu;
goto P_0c03f6dc;
P_0c03f6dc: /* original 2032, guest PC 0x0c03f6dc */
if(!s->budget--) { s->failed_pc=0x0c03f6dcu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c03f6de;
P_0c03f6de: /* original 61e2, guest PC 0x0c03f6de */
if(!s->budget--) { s->failed_pc=0x0c03f6deu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f6e0;
P_0c03f6e0: /* original 31bc, guest PC 0x0c03f6e0 */
if(!s->budget--) { s->failed_pc=0x0c03f6e0u; return 0; }
r[1]+=r[11];
goto P_0c03f6e2;
P_0c03f6e2: /* original 6312, guest PC 0x0c03f6e2 */
if(!s->budget--) { s->failed_pc=0x0c03f6e2u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c03f6e4;
P_0c03f6e4: /* original 2338, guest PC 0x0c03f6e4 */
if(!s->budget--) { s->failed_pc=0x0c03f6e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f6e6;
P_0c03f6e6: /* original 8b28, guest PC 0x0c03f6e6 */
if(!s->budget--) { s->failed_pc=0x0c03f6e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f73a; }
goto P_0c03f6e8;
P_0c03f6e8: /* original 63e2, guest PC 0x0c03f6e8 */
if(!s->budget--) { s->failed_pc=0x0c03f6e8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f6ea;
P_0c03f6ea: /* original 33bc, guest PC 0x0c03f6ea */
if(!s->budget--) { s->failed_pc=0x0c03f6eau; return 0; }
r[3]+=r[11];
goto P_0c03f6ec;
P_0c03f6ec: /* original 5131, guest PC 0x0c03f6ec */
if(!s->budget--) { s->failed_pc=0x0c03f6ecu; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c03f6ee;
P_0c03f6ee: /* original e33c, guest PC 0x0c03f6ee */
if(!s->budget--) { s->failed_pc=0x0c03f6eeu; return 0; }
r[3]=0x0000003cu;
goto P_0c03f6f0;
P_0c03f6f0: /* original 0137, guest PC 0x0c03f6f0 */
if(!s->budget--) { s->failed_pc=0x0c03f6f0u; return 0; }
r[19]=r[1]*r[3];
goto P_0c03f6f2;
P_0c03f6f2: /* original 1f12, guest PC 0x0c03f6f2 */
if(!s->budget--) { s->failed_pc=0x0c03f6f2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c03f6f4;
P_0c03f6f4: /* original 61c2, guest PC 0x0c03f6f4 */
if(!s->budget--) { s->failed_pc=0x0c03f6f4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c03f6f6;
P_0c03f6f6: /* original 0a1a, guest PC 0x0c03f6f6 */
if(!s->budget--) { s->failed_pc=0x0c03f6f6u; return 0; }
r[10]=r[19];
goto P_0c03f6f8;
P_0c03f6f8: /* original 31ac, guest PC 0x0c03f6f8 */
if(!s->budget--) { s->failed_pc=0x0c03f6f8u; return 0; }
r[1]+=r[10];
goto P_0c03f6fa;
P_0c03f6fa: /* original 501a, guest PC 0x0c03f6fa */
if(!s->budget--) { s->failed_pc=0x0c03f6fau; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c03f6fc;
P_0c03f6fc: /* original 2008, guest PC 0x0c03f6fc */
if(!s->budget--) { s->failed_pc=0x0c03f6fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f6fe;
P_0c03f6fe: /* original 8b08, guest PC 0x0c03f6fe */
if(!s->budget--) { s->failed_pc=0x0c03f6feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f712; }
goto P_0c03f700;
P_0c03f700: /* original d12d, guest PC 0x0c03f700 */
if(!s->budget--) { s->failed_pc=0x0c03f700u; return 0; }
r[1]=read(ram,0x0c03f7b8u,4);
goto P_0c03f702;
P_0c03f702: /* original 64c2, guest PC 0x0c03f702 */
if(!s->budget--) { s->failed_pc=0x0c03f702u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c03f704;
P_0c03f704: /* original 410b, guest PC 0x0c03f704 */
if(!s->budget--) { s->failed_pc=0x0c03f704u; return 0; }
target=r[1];
r[16]=code_base|0x0c03f708u;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f708u) { target=s->pc; goto dispatch; }
goto P_0c03f708;
P_0c03f706: /* original 34ac, guest PC 0x0c03f706 */
if(!s->budget--) { s->failed_pc=0x0c03f706u; return 0; }
r[4]+=r[10];
goto P_0c03f708;
P_0c03f708: /* original 6403, guest PC 0x0c03f708 */
if(!s->budget--) { s->failed_pc=0x0c03f708u; return 0; }
r[4]=r[0];
goto P_0c03f70a;
P_0c03f70a: /* original 2448, guest PC 0x0c03f70a */
if(!s->budget--) { s->failed_pc=0x0c03f70au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f70c;
P_0c03f70c: /* original 8901, guest PC 0x0c03f70c */
if(!s->budget--) { s->failed_pc=0x0c03f70cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f712; }
goto P_0c03f70e;
P_0c03f70e: /* original e201, guest PC 0x0c03f70e */
if(!s->budget--) { s->failed_pc=0x0c03f70eu; return 0; }
r[2]=0x00000001u;
goto P_0c03f710;
P_0c03f710: /* original 1f23, guest PC 0x0c03f710 */
if(!s->budget--) { s->failed_pc=0x0c03f710u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c03f712;
P_0c03f712: /* original 63c2, guest PC 0x0c03f712 */
if(!s->budget--) { s->failed_pc=0x0c03f712u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f714;
P_0c03f714: /* original e200, guest PC 0x0c03f714 */
if(!s->budget--) { s->failed_pc=0x0c03f714u; return 0; }
r[2]=0x00000000u;
goto P_0c03f716;
P_0c03f716: /* original 33ac, guest PC 0x0c03f716 */
if(!s->budget--) { s->failed_pc=0x0c03f716u; return 0; }
r[3]+=r[10];
goto P_0c03f718;
P_0c03f718: /* original 132b, guest PC 0x0c03f718 */
if(!s->budget--) { s->failed_pc=0x0c03f718u; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c03f71a;
P_0c03f71a: /* original 63c2, guest PC 0x0c03f71a */
if(!s->budget--) { s->failed_pc=0x0c03f71au; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f71c;
P_0c03f71c: /* original 33ac, guest PC 0x0c03f71c */
if(!s->budget--) { s->failed_pc=0x0c03f71cu; return 0; }
r[3]+=r[10];
goto P_0c03f71e;
P_0c03f71e: /* original 13de, guest PC 0x0c03f71e */
if(!s->budget--) { s->failed_pc=0x0c03f71eu; return 0; }
write(ram,r[3]+56,r[13],4);
goto P_0c03f720;
P_0c03f720: /* original d326, guest PC 0x0c03f720 */
if(!s->budget--) { s->failed_pc=0x0c03f720u; return 0; }
r[3]=read(ram,0x0c03f7bcu,4);
goto P_0c03f722;
P_0c03f722: /* original 430b, guest PC 0x0c03f722 */
if(!s->budget--) { s->failed_pc=0x0c03f722u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f726u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f726u) { target=s->pc; goto dispatch; }
goto P_0c03f726;
P_0c03f724: /* original 54f2, guest PC 0x0c03f724 */
if(!s->budget--) { s->failed_pc=0x0c03f724u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c03f726;
P_0c03f726: /* original 6082, guest PC 0x0c03f726 */
if(!s->budget--) { s->failed_pc=0x0c03f726u; return 0; }
tmp=read(ram,r[8],4);
r[0]=tmp;
goto P_0c03f728;
P_0c03f728: /* original 6a93, guest PC 0x0c03f728 */
if(!s->budget--) { s->failed_pc=0x0c03f728u; return 0; }
r[10]=r[9];
goto P_0c03f72a;
P_0c03f72a: /* original 4a00, guest PC 0x0c03f72a */
if(!s->budget--) { s->failed_pc=0x0c03f72au; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c03f72c;
P_0c03f72c: /* original b338, guest PC 0x0c03f72c */
if(!s->budget--) { s->failed_pc=0x0c03f72cu; return 0; }
target=code_base|0x0c03fda0u; r[16]=code_base|0x0c03f730u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f730u) { target=s->pc; goto dispatch; }
goto P_0c03f730;
P_0c03f72e: /* original 04ad, guest PC 0x0c03f72e */
if(!s->budget--) { s->failed_pc=0x0c03f72eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c03f730;
P_0c03f730: /* original 62e2, guest PC 0x0c03f730 */
if(!s->budget--) { s->failed_pc=0x0c03f730u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f732;
P_0c03f732: /* original 32bc, guest PC 0x0c03f732 */
if(!s->budget--) { s->failed_pc=0x0c03f732u; return 0; }
r[2]+=r[11];
goto P_0c03f734;
P_0c03f734: /* original 12d1, guest PC 0x0c03f734 */
if(!s->budget--) { s->failed_pc=0x0c03f734u; return 0; }
write(ram,r[2]+4,r[13],4);
goto P_0c03f736;
P_0c03f736: /* original 6082, guest PC 0x0c03f736 */
if(!s->budget--) { s->failed_pc=0x0c03f736u; return 0; }
tmp=read(ram,r[8],4);
r[0]=tmp;
goto P_0c03f738;
P_0c03f738: /* original 0ad5, guest PC 0x0c03f738 */
if(!s->budget--) { s->failed_pc=0x0c03f738u; return 0; }
write(ram,r[10]+r[0],r[13],2);
goto P_0c03f73a;
P_0c03f73a: /* original 63f2, guest PC 0x0c03f73a */
if(!s->budget--) { s->failed_pc=0x0c03f73au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c03f73c;
P_0c03f73c: /* original 7310, guest PC 0x0c03f73c */
if(!s->budget--) { s->failed_pc=0x0c03f73cu; return 0; }
r[3]+=0x00000010u;
goto P_0c03f73e;
P_0c03f73e: /* original 2f32, guest PC 0x0c03f73e */
if(!s->budget--) { s->failed_pc=0x0c03f73eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f740;
P_0c03f740: /* original 52f1, guest PC 0x0c03f740 */
if(!s->budget--) { s->failed_pc=0x0c03f740u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c03f742;
P_0c03f742: /* original 7201, guest PC 0x0c03f742 */
if(!s->budget--) { s->failed_pc=0x0c03f742u; return 0; }
r[2]+=0x00000001u;
goto P_0c03f744;
P_0c03f744: /* original 1f21, guest PC 0x0c03f744 */
if(!s->budget--) { s->failed_pc=0x0c03f744u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03f746;
P_0c03f746: /* original 60f2, guest PC 0x0c03f746 */
if(!s->budget--) { s->failed_pc=0x0c03f746u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f748;
P_0c03f748: /* original 5001, guest PC 0x0c03f748 */
if(!s->budget--) { s->failed_pc=0x0c03f748u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c03f74a;
P_0c03f74a: /* original 88ff, guest PC 0x0c03f74a */
if(!s->budget--) { s->failed_pc=0x0c03f74au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f74c;
P_0c03f74c: /* original 8bb8, guest PC 0x0c03f74c */
if(!s->budget--) { s->failed_pc=0x0c03f74cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f6c0; }
goto P_0c03f74e;
P_0c03f74e: /* original 50f3, guest PC 0x0c03f74e */
if(!s->budget--) { s->failed_pc=0x0c03f74eu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c03f750;
P_0c03f750: /* original 7f10, guest PC 0x0c03f750 */
if(!s->budget--) { s->failed_pc=0x0c03f750u; return 0; }
r[15]+=0x00000010u;
goto P_0c03f752;
P_0c03f752: /* original 4f16, guest PC 0x0c03f752 */
if(!s->budget--) { s->failed_pc=0x0c03f752u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f754;
P_0c03f754: /* original 4f26, guest PC 0x0c03f754 */
if(!s->budget--) { s->failed_pc=0x0c03f754u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f756;
P_0c03f756: /* original 68f6, guest PC 0x0c03f756 */
if(!s->budget--) { s->failed_pc=0x0c03f756u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f758;
P_0c03f758: /* original 69f6, guest PC 0x0c03f758 */
if(!s->budget--) { s->failed_pc=0x0c03f758u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f75a;
P_0c03f75a: /* original 6af6, guest PC 0x0c03f75a */
if(!s->budget--) { s->failed_pc=0x0c03f75au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f75c;
P_0c03f75c: /* original 6bf6, guest PC 0x0c03f75c */
if(!s->budget--) { s->failed_pc=0x0c03f75cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f75e;
P_0c03f75e: /* original 6cf6, guest PC 0x0c03f75e */
if(!s->budget--) { s->failed_pc=0x0c03f75eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f760;
P_0c03f760: /* original 6df6, guest PC 0x0c03f760 */
if(!s->budget--) { s->failed_pc=0x0c03f760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f762;
P_0c03f762: /* original 000b, guest PC 0x0c03f762 */
if(!s->budget--) { s->failed_pc=0x0c03f762u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f764: /* original 6ef6, guest PC 0x0c03f764 */
if(!s->budget--) { s->failed_pc=0x0c03f764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f766u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f766u; return 0; } return 1;
P_0c03fc90: /* original 2fe6, guest PC 0x0c03fc90 */
if(!s->budget--) { s->failed_pc=0x0c03fc90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fc92;
P_0c03fc92: /* original 6e43, guest PC 0x0c03fc92 */
if(!s->budget--) { s->failed_pc=0x0c03fc92u; return 0; }
r[14]=r[4];
goto P_0c03fc94;
P_0c03fc94: /* original d32d, guest PC 0x0c03fc94 */
if(!s->budget--) { s->failed_pc=0x0c03fc94u; return 0; }
r[3]=read(ram,0x0c03fd4cu,4);
goto P_0c03fc96;
P_0c03fc96: /* original 4f22, guest PC 0x0c03fc96 */
if(!s->budget--) { s->failed_pc=0x0c03fc96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fc98;
P_0c03fc98: /* original 2e32, guest PC 0x0c03fc98 */
if(!s->budget--) { s->failed_pc=0x0c03fc98u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c03fc9a;
P_0c03fc9a: /* original d22d, guest PC 0x0c03fc9a */
if(!s->budget--) { s->failed_pc=0x0c03fc9au; return 0; }
r[2]=read(ram,0x0c03fd50u,4);
goto P_0c03fc9c;
P_0c03fc9c: /* original 1e21, guest PC 0x0c03fc9c */
if(!s->budget--) { s->failed_pc=0x0c03fc9cu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c03fc9e;
P_0c03fc9e: /* original e200, guest PC 0x0c03fc9e */
if(!s->budget--) { s->failed_pc=0x0c03fc9eu; return 0; }
r[2]=0x00000000u;
goto P_0c03fca0;
P_0c03fca0: /* original 9352, guest PC 0x0c03fca0 */
if(!s->budget--) { s->failed_pc=0x0c03fca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03fd48u,2);
goto P_0c03fca2;
P_0c03fca2: /* original 1e32, guest PC 0x0c03fca2 */
if(!s->budget--) { s->failed_pc=0x0c03fca2u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c03fca4;
P_0c03fca4: /* original 1e23, guest PC 0x0c03fca4 */
if(!s->budget--) { s->failed_pc=0x0c03fca4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03fca6;
P_0c03fca6: /* original d32b, guest PC 0x0c03fca6 */
if(!s->budget--) { s->failed_pc=0x0c03fca6u; return 0; }
r[3]=read(ram,0x0c03fd54u,4);
goto P_0c03fca8;
P_0c03fca8: /* original 430b, guest PC 0x0c03fca8 */
if(!s->budget--) { s->failed_pc=0x0c03fca8u; return 0; }
target=r[3];
r[16]=code_base|0x0c03fcacu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fcacu) { target=s->pc; goto dispatch; }
goto P_0c03fcac;
P_0c03fcaa: /* original 64e3, guest PC 0x0c03fcaa */
if(!s->budget--) { s->failed_pc=0x0c03fcaau; return 0; }
r[4]=r[14];
goto P_0c03fcac;
P_0c03fcac: /* original 55e3, guest PC 0x0c03fcac */
if(!s->budget--) { s->failed_pc=0x0c03fcacu; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c03fcae;
P_0c03fcae: /* original e3e5, guest PC 0x0c03fcae */
if(!s->budget--) { s->failed_pc=0x0c03fcaeu; return 0; }
r[3]=0xffffffe5u;
goto P_0c03fcb0;
P_0c03fcb0: /* original e407, guest PC 0x0c03fcb0 */
if(!s->budget--) { s->failed_pc=0x0c03fcb0u; return 0; }
r[4]=0x00000007u;
goto P_0c03fcb2;
P_0c03fcb2: /* original 453d, guest PC 0x0c03fcb2 */
if(!s->budget--) { s->failed_pc=0x0c03fcb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c03fcb4;
P_0c03fcb4: /* original 2549, guest PC 0x0c03fcb4 */
if(!s->budget--) { s->failed_pc=0x0c03fcb4u; return 0; }
r[5]&=r[4];
goto P_0c03fcb6;
P_0c03fcb6: /* original 2558, guest PC 0x0c03fcb6 */
if(!s->budget--) { s->failed_pc=0x0c03fcb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03fcb8;
P_0c03fcb8: /* original e200, guest PC 0x0c03fcb8 */
if(!s->budget--) { s->failed_pc=0x0c03fcb8u; return 0; }
r[2]=0x00000000u;
goto P_0c03fcba;
P_0c03fcba: /* original 8d04, guest PC 0x0c03fcba */
if(!s->budget--) { s->failed_pc=0x0c03fcbau; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[2],4);
if(cond) { goto P_0c03fcc6; }
goto P_0c03fcbe;
P_0c03fcbc: /* original 1e25, guest PC 0x0c03fcbc */
if(!s->budget--) { s->failed_pc=0x0c03fcbcu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c03fcbe;
P_0c03fcbe: /* original 6053, guest PC 0x0c03fcbe */
if(!s->budget--) { s->failed_pc=0x0c03fcbeu; return 0; }
r[0]=r[5];
goto P_0c03fcc0;
P_0c03fcc0: /* original 0009, guest PC 0x0c03fcc0 */
if(!s->budget--) { s->failed_pc=0x0c03fcc0u; return 0; }
goto P_0c03fcc2;
P_0c03fcc2: /* original 8802, guest PC 0x0c03fcc2 */
if(!s->budget--) { s->failed_pc=0x0c03fcc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03fcc4;
P_0c03fcc4: /* original 8b01, guest PC 0x0c03fcc4 */
if(!s->budget--) { s->failed_pc=0x0c03fcc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fcca; }
goto P_0c03fcc6;
P_0c03fcc6: /* original e301, guest PC 0x0c03fcc6 */
if(!s->budget--) { s->failed_pc=0x0c03fcc6u; return 0; }
r[3]=0x00000001u;
goto P_0c03fcc8;
P_0c03fcc8: /* original 1e35, guest PC 0x0c03fcc8 */
if(!s->budget--) { s->failed_pc=0x0c03fcc8u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c03fcca;
P_0c03fcca: /* original 50e2, guest PC 0x0c03fcca */
if(!s->budget--) { s->failed_pc=0x0c03fccau; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fccc;
P_0c03fccc: /* original d522, guest PC 0x0c03fccc */
if(!s->budget--) { s->failed_pc=0x0c03fcccu; return 0; }
r[5]=read(ram,0x0c03fd58u,4);
goto P_0c03fcce;
P_0c03fcce: /* original 4009, guest PC 0x0c03fcce */
if(!s->budget--) { s->failed_pc=0x0c03fcceu; return 0; }
r[0]>>=2;
goto P_0c03fcd0;
P_0c03fcd0: /* original 4001, guest PC 0x0c03fcd0 */
if(!s->budget--) { s->failed_pc=0x0c03fcd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c03fcd2;
P_0c03fcd2: /* original 2049, guest PC 0x0c03fcd2 */
if(!s->budget--) { s->failed_pc=0x0c03fcd2u; return 0; }
r[0]&=r[4];
goto P_0c03fcd4;
P_0c03fcd4: /* original 4008, guest PC 0x0c03fcd4 */
if(!s->budget--) { s->failed_pc=0x0c03fcd4u; return 0; }
r[0]<<=2;
goto P_0c03fcd6;
P_0c03fcd6: /* original f356, guest PC 0x0c03fcd6 */
if(!s->budget--) { s->failed_pc=0x0c03fcd6u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fcd8;
P_0c03fcd8: /* original e018, guest PC 0x0c03fcd8 */
if(!s->budget--) { s->failed_pc=0x0c03fcd8u; return 0; }
r[0]=0x00000018u;
goto P_0c03fcda;
P_0c03fcda: /* original 4f26, guest PC 0x0c03fcda */
if(!s->budget--) { s->failed_pc=0x0c03fcdau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fcdc;
P_0c03fcdc: /* original fe37, guest PC 0x0c03fcdc */
if(!s->budget--) { s->failed_pc=0x0c03fcdcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcde;
P_0c03fcde: /* original 50e2, guest PC 0x0c03fcde */
if(!s->budget--) { s->failed_pc=0x0c03fcdeu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fce0;
P_0c03fce0: /* original 2049, guest PC 0x0c03fce0 */
if(!s->budget--) { s->failed_pc=0x0c03fce0u; return 0; }
r[0]&=r[4];
goto P_0c03fce2;
P_0c03fce2: /* original 4008, guest PC 0x0c03fce2 */
if(!s->budget--) { s->failed_pc=0x0c03fce2u; return 0; }
r[0]<<=2;
goto P_0c03fce4;
P_0c03fce4: /* original f356, guest PC 0x0c03fce4 */
if(!s->budget--) { s->failed_pc=0x0c03fce4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fce6;
P_0c03fce6: /* original e01c, guest PC 0x0c03fce6 */
if(!s->budget--) { s->failed_pc=0x0c03fce6u; return 0; }
r[0]=0x0000001cu;
goto P_0c03fce8;
P_0c03fce8: /* original fe37, guest PC 0x0c03fce8 */
if(!s->budget--) { s->failed_pc=0x0c03fce8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcea;
P_0c03fcea: /* original 000b, guest PC 0x0c03fcea */
if(!s->budget--) { s->failed_pc=0x0c03fceau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fcec: /* original 6ef6, guest PC 0x0c03fcec */
if(!s->budget--) { s->failed_pc=0x0c03fcecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fceeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fceeu; return 0; } return 1;
P_0c03fcf0: /* original 2fe6, guest PC 0x0c03fcf0 */
if(!s->budget--) { s->failed_pc=0x0c03fcf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf2;
P_0c03fcf2: /* original 2fd6, guest PC 0x0c03fcf2 */
if(!s->budget--) { s->failed_pc=0x0c03fcf2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf4;
P_0c03fcf4: /* original 2fb6, guest PC 0x0c03fcf4 */
if(!s->budget--) { s->failed_pc=0x0c03fcf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf6;
P_0c03fcf6: /* original eb00, guest PC 0x0c03fcf6 */
if(!s->budget--) { s->failed_pc=0x0c03fcf6u; return 0; }
r[11]=0x00000000u;
goto P_0c03fcf8;
P_0c03fcf8: /* original 2fa6, guest PC 0x0c03fcf8 */
if(!s->budget--) { s->failed_pc=0x0c03fcf8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfa;
P_0c03fcfa: /* original ea01, guest PC 0x0c03fcfa */
if(!s->budget--) { s->failed_pc=0x0c03fcfau; return 0; }
r[10]=0x00000001u;
goto P_0c03fcfc;
P_0c03fcfc: /* original 2f96, guest PC 0x0c03fcfc */
if(!s->budget--) { s->failed_pc=0x0c03fcfcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfe;
P_0c03fcfe: /* original e920, guest PC 0x0c03fcfe */
if(!s->budget--) { s->failed_pc=0x0c03fcfeu; return 0; }
r[9]=0x00000020u;
goto P_0c03fd00;
P_0c03fd00: /* original 2f86, guest PC 0x0c03fd00 */
if(!s->budget--) { s->failed_pc=0x0c03fd00u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fd02;
P_0c03fd02: /* original 4f22, guest PC 0x0c03fd02 */
if(!s->budget--) { s->failed_pc=0x0c03fd02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fd04;
P_0c03fd04: /* original d716, guest PC 0x0c03fd04 */
if(!s->budget--) { s->failed_pc=0x0c03fd04u; return 0; }
r[7]=read(ram,0x0c03fd60u,4);
goto P_0c03fd06;
P_0c03fd06: /* original d815, guest PC 0x0c03fd06 */
if(!s->budget--) { s->failed_pc=0x0c03fd06u; return 0; }
r[8]=read(ram,0x0c03fd5cu,4);
goto P_0c03fd08;
P_0c03fd08: /* original a033, guest PC 0x0c03fd08 */
if(!s->budget--) { s->failed_pc=0x0c03fd08u; return 0; }
r[5]=r[11];
goto P_0c03fd72;
P_0c03fd0a: /* original 65b3, guest PC 0x0c03fd0a */
if(!s->budget--) { s->failed_pc=0x0c03fd0au; return 0; }
r[5]=r[11];
if(!vf3_matrix_family(0x0c03fd0cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd0cu; return 0; } return 1;
P_0c03fd10: /* original 6072, guest PC 0x0c03fd10 */
if(!s->budget--) { s->failed_pc=0x0c03fd10u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd12;
P_0c03fd12: /* original 6e53, guest PC 0x0c03fd12 */
if(!s->budget--) { s->failed_pc=0x0c03fd12u; return 0; }
r[14]=r[5];
goto P_0c03fd14;
P_0c03fd14: /* original 4e08, guest PC 0x0c03fd14 */
if(!s->budget--) { s->failed_pc=0x0c03fd14u; return 0; }
r[14]<<=2;
goto P_0c03fd16;
P_0c03fd16: /* original 00ee, guest PC 0x0c03fd16 */
if(!s->budget--) { s->failed_pc=0x0c03fd16u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c03fd18;
P_0c03fd18: /* original 88ff, guest PC 0x0c03fd18 */
if(!s->budget--) { s->failed_pc=0x0c03fd18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03fd1a;
P_0c03fd1a: /* original 8d29, guest PC 0x0c03fd1a */
if(!s->budget--) { s->failed_pc=0x0c03fd1au; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c03fd70; }
goto P_0c03fd1e;
P_0c03fd1c: /* original 6d03, guest PC 0x0c03fd1c */
if(!s->budget--) { s->failed_pc=0x0c03fd1cu; return 0; }
r[13]=r[0];
goto P_0c03fd1e;
P_0c03fd1e: /* original 6153, guest PC 0x0c03fd1e */
if(!s->budget--) { s->failed_pc=0x0c03fd1eu; return 0; }
r[1]=r[5];
goto P_0c03fd20;
P_0c03fd20: /* original 4108, guest PC 0x0c03fd20 */
if(!s->budget--) { s->failed_pc=0x0c03fd20u; return 0; }
r[1]<<=2;
goto P_0c03fd22;
P_0c03fd22: /* original 4108, guest PC 0x0c03fd22 */
if(!s->budget--) { s->failed_pc=0x0c03fd22u; return 0; }
r[1]<<=2;
goto P_0c03fd24;
P_0c03fd24: /* original 66b3, guest PC 0x0c03fd24 */
if(!s->budget--) { s->failed_pc=0x0c03fd24u; return 0; }
r[6]=r[11];
goto P_0c03fd26;
P_0c03fd26: /* original 4100, guest PC 0x0c03fd26 */
if(!s->budget--) { s->failed_pc=0x0c03fd26u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c03fd28;
P_0c03fd28: /* original 64a3, guest PC 0x0c03fd28 */
if(!s->budget--) { s->failed_pc=0x0c03fd28u; return 0; }
r[4]=r[10];
goto P_0c03fd2a;
P_0c03fd2a: /* original 62d3, guest PC 0x0c03fd2a */
if(!s->budget--) { s->failed_pc=0x0c03fd2au; return 0; }
r[2]=r[13];
goto P_0c03fd2c;
P_0c03fd2c: /* original 2248, guest PC 0x0c03fd2c */
if(!s->budget--) { s->failed_pc=0x0c03fd2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c03fd2e;
P_0c03fd2e: /* original 8b07, guest PC 0x0c03fd2e */
if(!s->budget--) { s->failed_pc=0x0c03fd2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd40; }
goto P_0c03fd30;
P_0c03fd30: /* original 6072, guest PC 0x0c03fd30 */
if(!s->budget--) { s->failed_pc=0x0c03fd30u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd32;
P_0c03fd32: /* original 02ee, guest PC 0x0c03fd32 */
if(!s->budget--) { s->failed_pc=0x0c03fd32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c03fd34;
P_0c03fd34: /* original 224b, guest PC 0x0c03fd34 */
if(!s->budget--) { s->failed_pc=0x0c03fd34u; return 0; }
r[2]|=r[4];
goto P_0c03fd36;
P_0c03fd36: /* original 0e26, guest PC 0x0c03fd36 */
if(!s->budget--) { s->failed_pc=0x0c03fd36u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03fd38;
P_0c03fd38: /* original 6013, guest PC 0x0c03fd38 */
if(!s->budget--) { s->failed_pc=0x0c03fd38u; return 0; }
r[0]=r[1];
goto P_0c03fd3a;
P_0c03fd3a: /* original 0009, guest PC 0x0c03fd3a */
if(!s->budget--) { s->failed_pc=0x0c03fd3au; return 0; }
goto P_0c03fd3c;
P_0c03fd3c: /* original a023, guest PC 0x0c03fd3c */
if(!s->budget--) { s->failed_pc=0x0c03fd3cu; return 0; }
r[0]+=r[6];
goto P_0c03fd86;
P_0c03fd3e: /* original 306c, guest PC 0x0c03fd3e */
if(!s->budget--) { s->failed_pc=0x0c03fd3eu; return 0; }
r[0]+=r[6];
goto P_0c03fd40;
P_0c03fd40: /* original 4400, guest PC 0x0c03fd40 */
if(!s->budget--) { s->failed_pc=0x0c03fd40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03fd42;
P_0c03fd42: /* original aff2, guest PC 0x0c03fd42 */
if(!s->budget--) { s->failed_pc=0x0c03fd42u; return 0; }
r[6]+=0x00000001u;
goto P_0c03fd2a;
P_0c03fd44: /* original 7601, guest PC 0x0c03fd44 */
if(!s->budget--) { s->failed_pc=0x0c03fd44u; return 0; }
r[6]+=0x00000001u;
if(!vf3_matrix_family(0x0c03fd46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd46u; return 0; } return 1;
P_0c03fd70: /* original 7501, guest PC 0x0c03fd70 */
if(!s->budget--) { s->failed_pc=0x0c03fd70u; return 0; }
r[5]+=0x00000001u;
goto P_0c03fd72;
P_0c03fd72: /* original 6182, guest PC 0x0c03fd72 */
if(!s->budget--) { s->failed_pc=0x0c03fd72u; return 0; }
tmp=read(ram,r[8],4);
r[1]=tmp;
goto P_0c03fd74;
P_0c03fd74: /* original 711f, guest PC 0x0c03fd74 */
if(!s->budget--) { s->failed_pc=0x0c03fd74u; return 0; }
r[1]+=0x0000001fu;
goto P_0c03fd76;
P_0c03fd76: /* original 6093, guest PC 0x0c03fd76 */
if(!s->budget--) { s->failed_pc=0x0c03fd76u; return 0; }
r[0]=r[9];
goto P_0c03fd78;
P_0c03fd78: /* original 0009, guest PC 0x0c03fd78 */
if(!s->budget--) { s->failed_pc=0x0c03fd78u; return 0; }
goto P_0c03fd7a;
P_0c03fd7a: /* original d311, guest PC 0x0c03fd7a */
if(!s->budget--) { s->failed_pc=0x0c03fd7au; return 0; }
r[3]=read(ram,0x0c03fdc0u,4);
goto P_0c03fd7c;
P_0c03fd7c: /* original 430b, guest PC 0x0c03fd7c */
if(!s->budget--) { s->failed_pc=0x0c03fd7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03fd80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fd80u) { target=s->pc; goto dispatch; }
goto P_0c03fd80;
P_0c03fd7e: /* original 0009, guest PC 0x0c03fd7e */
if(!s->budget--) { s->failed_pc=0x0c03fd7eu; return 0; }
goto P_0c03fd80;
P_0c03fd80: /* original 3503, guest PC 0x0c03fd80 */
if(!s->budget--) { s->failed_pc=0x0c03fd80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[0])!=0);
goto P_0c03fd82;
P_0c03fd82: /* original 8bc5, guest PC 0x0c03fd82 */
if(!s->budget--) { s->failed_pc=0x0c03fd82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd10; }
goto P_0c03fd84;
P_0c03fd84: /* original e0ff, guest PC 0x0c03fd84 */
if(!s->budget--) { s->failed_pc=0x0c03fd84u; return 0; }
r[0]=0xffffffffu;
goto P_0c03fd86;
P_0c03fd86: /* original 4f26, guest PC 0x0c03fd86 */
if(!s->budget--) { s->failed_pc=0x0c03fd86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fd88;
P_0c03fd88: /* original 68f6, guest PC 0x0c03fd88 */
if(!s->budget--) { s->failed_pc=0x0c03fd88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03fd8a;
P_0c03fd8a: /* original 69f6, guest PC 0x0c03fd8a */
if(!s->budget--) { s->failed_pc=0x0c03fd8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03fd8c;
P_0c03fd8c: /* original 6af6, guest PC 0x0c03fd8c */
if(!s->budget--) { s->failed_pc=0x0c03fd8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03fd8e;
P_0c03fd8e: /* original 6bf6, guest PC 0x0c03fd8e */
if(!s->budget--) { s->failed_pc=0x0c03fd8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03fd90;
P_0c03fd90: /* original 6df6, guest PC 0x0c03fd90 */
if(!s->budget--) { s->failed_pc=0x0c03fd90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03fd92;
P_0c03fd92: /* original 000b, guest PC 0x0c03fd92 */
if(!s->budget--) { s->failed_pc=0x0c03fd92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fd94: /* original 6ef6, guest PC 0x0c03fd94 */
if(!s->budget--) { s->failed_pc=0x0c03fd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fd96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd96u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
