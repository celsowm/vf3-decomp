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
int vf3_away_batch127_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a647cu: goto P_0c0a647c;
case 0x0c0a647eu: goto P_0c0a647e;
case 0x0c0a6480u: goto P_0c0a6480;
case 0x0c0a6482u: goto P_0c0a6482;
case 0x0c0a6484u: goto P_0c0a6484;
case 0x0c0a6486u: goto P_0c0a6486;
case 0x0c0a6488u: goto P_0c0a6488;
case 0x0c0a648au: goto P_0c0a648a;
case 0x0c0a648cu: goto P_0c0a648c;
case 0x0c0a648eu: goto P_0c0a648e;
case 0x0c0a6490u: goto P_0c0a6490;
case 0x0c0a6492u: goto P_0c0a6492;
case 0x0c0a6494u: goto P_0c0a6494;
case 0x0c0a6496u: goto P_0c0a6496;
case 0x0c0a6498u: goto P_0c0a6498;
case 0x0c0a649au: goto P_0c0a649a;
case 0x0c0a649cu: goto P_0c0a649c;
case 0x0c0a649eu: goto P_0c0a649e;
case 0x0c0a64a0u: goto P_0c0a64a0;
case 0x0c0a64a2u: goto P_0c0a64a2;
case 0x0c0a64a4u: goto P_0c0a64a4;
case 0x0c0a64a6u: goto P_0c0a64a6;
case 0x0c0a64a8u: goto P_0c0a64a8;
case 0x0c0a64aau: goto P_0c0a64aa;
case 0x0c0a64acu: goto P_0c0a64ac;
case 0x0c0a64aeu: goto P_0c0a64ae;
case 0x0c0a64b0u: goto P_0c0a64b0;
case 0x0c0a64b2u: goto P_0c0a64b2;
case 0x0c0a64b4u: goto P_0c0a64b4;
case 0x0c0a64b6u: goto P_0c0a64b6;
case 0x0c0a64b8u: goto P_0c0a64b8;
case 0x0c0a64bau: goto P_0c0a64ba;
case 0x0c0a64bcu: goto P_0c0a64bc;
case 0x0c0a64beu: goto P_0c0a64be;
case 0x0c0a64c0u: goto P_0c0a64c0;
case 0x0c0a64c2u: goto P_0c0a64c2;
case 0x0c0a64c4u: goto P_0c0a64c4;
case 0x0c0a64c6u: goto P_0c0a64c6;
case 0x0c0a64c8u: goto P_0c0a64c8;
case 0x0c0a64cau: goto P_0c0a64ca;
case 0x0c0a64ccu: goto P_0c0a64cc;
case 0x0c0a64ceu: goto P_0c0a64ce;
case 0x0c0a64d0u: goto P_0c0a64d0;
case 0x0c0a64d2u: goto P_0c0a64d2;
case 0x0c0a64d4u: goto P_0c0a64d4;
case 0x0c0a64d6u: goto P_0c0a64d6;
case 0x0c0a64d8u: goto P_0c0a64d8;
case 0x0c0a64dau: goto P_0c0a64da;
case 0x0c0a64dcu: goto P_0c0a64dc;
case 0x0c0a64deu: goto P_0c0a64de;
case 0x0c0a64e0u: goto P_0c0a64e0;
case 0x0c0a64e2u: goto P_0c0a64e2;
case 0x0c0a64e4u: goto P_0c0a64e4;
case 0x0c0a64e6u: goto P_0c0a64e6;
case 0x0c0a64e8u: goto P_0c0a64e8;
case 0x0c0a64eau: goto P_0c0a64ea;
case 0x0c0a64ecu: goto P_0c0a64ec;
case 0x0c0a64eeu: goto P_0c0a64ee;
case 0x0c0a64f0u: goto P_0c0a64f0;
case 0x0c0a64f2u: goto P_0c0a64f2;
case 0x0c0a64f4u: goto P_0c0a64f4;
case 0x0c0a64f6u: goto P_0c0a64f6;
case 0x0c0a64f8u: goto P_0c0a64f8;
case 0x0c0a64fau: goto P_0c0a64fa;
case 0x0c0a64fcu: goto P_0c0a64fc;
case 0x0c0a64feu: goto P_0c0a64fe;
case 0x0c0a6500u: goto P_0c0a6500;
case 0x0c0a6502u: goto P_0c0a6502;
case 0x0c0a6504u: goto P_0c0a6504;
case 0x0c0a6506u: goto P_0c0a6506;
case 0x0c0a6508u: goto P_0c0a6508;
case 0x0c0a650au: goto P_0c0a650a;
case 0x0c0a650cu: goto P_0c0a650c;
case 0x0c0a650eu: goto P_0c0a650e;
case 0x0c0a6510u: goto P_0c0a6510;
case 0x0c0a6512u: goto P_0c0a6512;
case 0x0c0a6514u: goto P_0c0a6514;
case 0x0c0a6516u: goto P_0c0a6516;
case 0x0c0a6518u: goto P_0c0a6518;
case 0x0c0a651au: goto P_0c0a651a;
case 0x0c0a651cu: goto P_0c0a651c;
case 0x0c0a651eu: goto P_0c0a651e;
case 0x0c0a6520u: goto P_0c0a6520;
case 0x0c0a6522u: goto P_0c0a6522;
case 0x0c0a6524u: goto P_0c0a6524;
case 0x0c0a6526u: goto P_0c0a6526;
case 0x0c0a6528u: goto P_0c0a6528;
case 0x0c0a652au: goto P_0c0a652a;
case 0x0c0a652cu: goto P_0c0a652c;
case 0x0c0a652eu: goto P_0c0a652e;
case 0x0c0a6530u: goto P_0c0a6530;
case 0x0c0a6532u: goto P_0c0a6532;
case 0x0c0a6534u: goto P_0c0a6534;
case 0x0c0a6536u: goto P_0c0a6536;
case 0x0c0a6538u: goto P_0c0a6538;
case 0x0c0a653au: goto P_0c0a653a;
case 0x0c0a653cu: goto P_0c0a653c;
case 0x0c0a653eu: goto P_0c0a653e;
case 0x0c0a6540u: goto P_0c0a6540;
case 0x0c0a6542u: goto P_0c0a6542;
case 0x0c0a6544u: goto P_0c0a6544;
case 0x0c0a6546u: goto P_0c0a6546;
case 0x0c0a6548u: goto P_0c0a6548;
case 0x0c0a654au: goto P_0c0a654a;
case 0x0c0a654cu: goto P_0c0a654c;
case 0x0c0a654eu: goto P_0c0a654e;
case 0x0c0a6550u: goto P_0c0a6550;
case 0x0c0a6552u: goto P_0c0a6552;
case 0x0c0a6554u: goto P_0c0a6554;
case 0x0c0a6556u: goto P_0c0a6556;
case 0x0c0a6558u: goto P_0c0a6558;
case 0x0c0a655au: goto P_0c0a655a;
case 0x0c0a655cu: goto P_0c0a655c;
case 0x0c0a655eu: goto P_0c0a655e;
case 0x0c0a6560u: goto P_0c0a6560;
case 0x0c0a6562u: goto P_0c0a6562;
case 0x0c0a6564u: goto P_0c0a6564;
case 0x0c0a6566u: goto P_0c0a6566;
case 0x0c0a6568u: goto P_0c0a6568;
case 0x0c0a656au: goto P_0c0a656a;
case 0x0c0a656cu: goto P_0c0a656c;
case 0x0c0a656eu: goto P_0c0a656e;
case 0x0c0a6570u: goto P_0c0a6570;
case 0x0c0a6572u: goto P_0c0a6572;
case 0x0c0a6574u: goto P_0c0a6574;
case 0x0c0a6576u: goto P_0c0a6576;
case 0x0c0a6578u: goto P_0c0a6578;
case 0x0c0a657au: goto P_0c0a657a;
case 0x0c0a657cu: goto P_0c0a657c;
case 0x0c0a657eu: goto P_0c0a657e;
case 0x0c0a6580u: goto P_0c0a6580;
case 0x0c0a6582u: goto P_0c0a6582;
case 0x0c0a6584u: goto P_0c0a6584;
case 0x0c0a6586u: goto P_0c0a6586;
case 0x0c0a6588u: goto P_0c0a6588;
case 0x0c0a658au: goto P_0c0a658a;
case 0x0c0a658cu: goto P_0c0a658c;
case 0x0c0a658eu: goto P_0c0a658e;
case 0x0c0a6590u: goto P_0c0a6590;
case 0x0c0a6592u: goto P_0c0a6592;
case 0x0c0a6594u: goto P_0c0a6594;
case 0x0c0a6596u: goto P_0c0a6596;
case 0x0c0a6598u: goto P_0c0a6598;
case 0x0c0a659au: goto P_0c0a659a;
case 0x0c0a659cu: goto P_0c0a659c;
case 0x0c0a659eu: goto P_0c0a659e;
case 0x0c0a65a0u: goto P_0c0a65a0;
case 0x0c0a65a2u: goto P_0c0a65a2;
case 0x0c0a65a4u: goto P_0c0a65a4;
case 0x0c0a65a6u: goto P_0c0a65a6;
case 0x0c0a65a8u: goto P_0c0a65a8;
case 0x0c0a65aau: goto P_0c0a65aa;
case 0x0c0a65acu: goto P_0c0a65ac;
case 0x0c0a65aeu: goto P_0c0a65ae;
case 0x0c0a65b0u: goto P_0c0a65b0;
case 0x0c0a65b2u: goto P_0c0a65b2;
case 0x0c0a65b4u: goto P_0c0a65b4;
case 0x0c0a65b6u: goto P_0c0a65b6;
case 0x0c0a65b8u: goto P_0c0a65b8;
case 0x0c0a65bau: goto P_0c0a65ba;
case 0x0c0a65bcu: goto P_0c0a65bc;
case 0x0c0a65beu: goto P_0c0a65be;
case 0x0c0a65c0u: goto P_0c0a65c0;
case 0x0c0a65c2u: goto P_0c0a65c2;
case 0x0c0a65c4u: goto P_0c0a65c4;
case 0x0c0a65c6u: goto P_0c0a65c6;
case 0x0c0a65c8u: goto P_0c0a65c8;
case 0x0c0a65cau: goto P_0c0a65ca;
case 0x0c0a65ccu: goto P_0c0a65cc;
case 0x0c0a65ceu: goto P_0c0a65ce;
case 0x0c0a65d0u: goto P_0c0a65d0;
case 0x0c0a65d2u: goto P_0c0a65d2;
case 0x0c0a65d4u: goto P_0c0a65d4;
case 0x0c0a65d6u: goto P_0c0a65d6;
case 0x0c0a65d8u: goto P_0c0a65d8;
case 0x0c0a65dau: goto P_0c0a65da;
case 0x0c0a65dcu: goto P_0c0a65dc;
case 0x0c0a65deu: goto P_0c0a65de;
case 0x0c0a65e0u: goto P_0c0a65e0;
case 0x0c0a65e2u: goto P_0c0a65e2;
case 0x0c0a65e4u: goto P_0c0a65e4;
case 0x0c0a65e6u: goto P_0c0a65e6;
case 0x0c0a65e8u: goto P_0c0a65e8;
case 0x0c0a65eau: goto P_0c0a65ea;
case 0x0c0a65ecu: goto P_0c0a65ec;
case 0x0c0a65eeu: goto P_0c0a65ee;
case 0x0c0a65f0u: goto P_0c0a65f0;
case 0x0c0a65f2u: goto P_0c0a65f2;
case 0x0c0a65f4u: goto P_0c0a65f4;
case 0x0c0a65f6u: goto P_0c0a65f6;
case 0x0c0a65f8u: goto P_0c0a65f8;
case 0x0c0a65fau: goto P_0c0a65fa;
case 0x0c0a65fcu: goto P_0c0a65fc;
case 0x0c0a65feu: goto P_0c0a65fe;
case 0x0c0a6600u: goto P_0c0a6600;
case 0x0c0a6602u: goto P_0c0a6602;
case 0x0c0a6604u: goto P_0c0a6604;
case 0x0c0a6606u: goto P_0c0a6606;
case 0x0c0a6608u: goto P_0c0a6608;
case 0x0c0a660au: goto P_0c0a660a;
case 0x0c0a660cu: goto P_0c0a660c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a647c: /* original d064, guest PC 0x0c0a647c */
if(!s->budget--) { s->failed_pc=0x0c0a647cu; return 0; }
r[0]=read(ram,0x0c0a6610u,4);
goto P_0c0a647e;
P_0c0a647e: /* original 000b, guest PC 0x0c0a647e */
if(!s->budget--) { s->failed_pc=0x0c0a647eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a6480: /* original 0009, guest PC 0x0c0a6480 */
if(!s->budget--) { s->failed_pc=0x0c0a6480u; return 0; }
goto P_0c0a6482;
P_0c0a6482: /* original 2fe6, guest PC 0x0c0a6482 */
if(!s->budget--) { s->failed_pc=0x0c0a6482u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a6484;
P_0c0a6484: /* original 2fd6, guest PC 0x0c0a6484 */
if(!s->budget--) { s->failed_pc=0x0c0a6484u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a6486;
P_0c0a6486: /* original 2fc6, guest PC 0x0c0a6486 */
if(!s->budget--) { s->failed_pc=0x0c0a6486u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a6488;
P_0c0a6488: /* original 2fb6, guest PC 0x0c0a6488 */
if(!s->budget--) { s->failed_pc=0x0c0a6488u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a648a;
P_0c0a648a: /* original 2fa6, guest PC 0x0c0a648a */
if(!s->budget--) { s->failed_pc=0x0c0a648au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a648c;
P_0c0a648c: /* original 2f96, guest PC 0x0c0a648c */
if(!s->budget--) { s->failed_pc=0x0c0a648cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a648e;
P_0c0a648e: /* original 2f86, guest PC 0x0c0a648e */
if(!s->budget--) { s->failed_pc=0x0c0a648eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a6490;
P_0c0a6490: /* original fffb, guest PC 0x0c0a6490 */
if(!s->budget--) { s->failed_pc=0x0c0a6490u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a6492;
P_0c0a6492: /* original ffeb, guest PC 0x0c0a6492 */
if(!s->budget--) { s->failed_pc=0x0c0a6492u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a6494;
P_0c0a6494: /* original 4f22, guest PC 0x0c0a6494 */
if(!s->budget--) { s->failed_pc=0x0c0a6494u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a6496;
P_0c0a6496: /* original 7fb8, guest PC 0x0c0a6496 */
if(!s->budget--) { s->failed_pc=0x0c0a6496u; return 0; }
r[15]+=0xffffffb8u;
goto P_0c0a6498;
P_0c0a6498: /* original 2f42, guest PC 0x0c0a6498 */
if(!s->budget--) { s->failed_pc=0x0c0a6498u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a649a;
P_0c0a649a: /* original 1f52, guest PC 0x0c0a649a */
if(!s->budget--) { s->failed_pc=0x0c0a649au; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a649c;
P_0c0a649c: /* original 1f61, guest PC 0x0c0a649c */
if(!s->budget--) { s->failed_pc=0x0c0a649cu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a649e;
P_0c0a649e: /* original d35d, guest PC 0x0c0a649e */
if(!s->budget--) { s->failed_pc=0x0c0a649eu; return 0; }
r[3]=read(ram,0x0c0a6614u,4);
goto P_0c0a64a0;
P_0c0a64a0: /* original 430b, guest PC 0x0c0a64a0 */
if(!s->budget--) { s->failed_pc=0x0c0a64a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a64a4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a64a4u) { target=s->pc; goto dispatch; }
goto P_0c0a64a4;
P_0c0a64a2: /* original e400, guest PC 0x0c0a64a2 */
if(!s->budget--) { s->failed_pc=0x0c0a64a2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a64a4;
P_0c0a64a4: /* original 5cf1, guest PC 0x0c0a64a4 */
if(!s->budget--) { s->failed_pc=0x0c0a64a4u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c0a64a6;
P_0c0a64a6: /* original 6df2, guest PC 0x0c0a64a6 */
if(!s->budget--) { s->failed_pc=0x0c0a64a6u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0a64a8;
P_0c0a64a8: /* original 64c2, guest PC 0x0c0a64a8 */
if(!s->budget--) { s->failed_pc=0x0c0a64a8u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a64aa;
P_0c0a64aa: /* original 5ef2, guest PC 0x0c0a64aa */
if(!s->budget--) { s->failed_pc=0x0c0a64aau; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c0a64ac;
P_0c0a64ac: /* original 684c, guest PC 0x0c0a64ac */
if(!s->budget--) { s->failed_pc=0x0c0a64acu; return 0; }
r[8]=r[4]&255u;
goto P_0c0a64ae;
P_0c0a64ae: /* original 6b83, guest PC 0x0c0a64ae */
if(!s->budget--) { s->failed_pc=0x0c0a64aeu; return 0; }
r[11]=r[8];
goto P_0c0a64b0;
P_0c0a64b0: /* original 6383, guest PC 0x0c0a64b0 */
if(!s->budget--) { s->failed_pc=0x0c0a64b0u; return 0; }
r[3]=r[8];
goto P_0c0a64b2;
P_0c0a64b2: /* original 4b00, guest PC 0x0c0a64b2 */
if(!s->budget--) { s->failed_pc=0x0c0a64b2u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c0a64b4;
P_0c0a64b4: /* original 3b3c, guest PC 0x0c0a64b4 */
if(!s->budget--) { s->failed_pc=0x0c0a64b4u; return 0; }
r[11]+=r[3];
goto P_0c0a64b6;
P_0c0a64b6: /* original 4b08, guest PC 0x0c0a64b6 */
if(!s->budget--) { s->failed_pc=0x0c0a64b6u; return 0; }
r[11]<<=2;
goto P_0c0a64b8;
P_0c0a64b8: /* original 7b04, guest PC 0x0c0a64b8 */
if(!s->budget--) { s->failed_pc=0x0c0a64b8u; return 0; }
r[11]+=0x00000004u;
goto P_0c0a64ba;
P_0c0a64ba: /* original bfdf, guest PC 0x0c0a64ba */
if(!s->budget--) { s->failed_pc=0x0c0a64bau; return 0; }
target=code_base|0x0c0a647cu; r[16]=code_base|0x0c0a64beu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a64beu) { target=s->pc; goto dispatch; }
goto P_0c0a64be;
P_0c0a64bc: /* original 64b3, guest PC 0x0c0a64bc */
if(!s->budget--) { s->failed_pc=0x0c0a64bcu; return 0; }
r[4]=r[11];
goto P_0c0a64be;
P_0c0a64be: /* original 65c3, guest PC 0x0c0a64be */
if(!s->budget--) { s->failed_pc=0x0c0a64beu; return 0; }
r[5]=r[12];
goto P_0c0a64c0;
P_0c0a64c0: /* original 6603, guest PC 0x0c0a64c0 */
if(!s->budget--) { s->failed_pc=0x0c0a64c0u; return 0; }
r[6]=r[0];
goto P_0c0a64c2;
P_0c0a64c2: /* original 6b03, guest PC 0x0c0a64c2 */
if(!s->budget--) { s->failed_pc=0x0c0a64c2u; return 0; }
r[11]=r[0];
goto P_0c0a64c4;
P_0c0a64c4: /* original b080, guest PC 0x0c0a64c4 */
if(!s->budget--) { s->failed_pc=0x0c0a64c4u; return 0; }
target=code_base|0x0c0a65c8u; r[16]=code_base|0x0c0a64c8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a64c8u) { target=s->pc; goto dispatch; }
goto P_0c0a64c8;
P_0c0a64c6: /* original 64d3, guest PC 0x0c0a64c6 */
if(!s->budget--) { s->failed_pc=0x0c0a64c6u; return 0; }
r[4]=r[13];
goto P_0c0a64c8;
P_0c0a64c8: /* original f3e8, guest PC 0x0c0a64c8 */
if(!s->budget--) { s->failed_pc=0x0c0a64c8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0a64ca;
P_0c0a64ca: /* original e03c, guest PC 0x0c0a64ca */
if(!s->budget--) { s->failed_pc=0x0c0a64cau; return 0; }
r[0]=0x0000003cu;
goto P_0c0a64cc;
P_0c0a64cc: /* original f48d, guest PC 0x0c0a64cc */
if(!s->budget--) { s->failed_pc=0x0c0a64ccu; return 0; }
fr[4]=0;
goto P_0c0a64ce;
P_0c0a64ce: /* original ea00, guest PC 0x0c0a64ce */
if(!s->budget--) { s->failed_pc=0x0c0a64ceu; return 0; }
r[10]=0x00000000u;
goto P_0c0a64d0;
P_0c0a64d0: /* original ff4c, guest PC 0x0c0a64d0 */
if(!s->budget--) { s->failed_pc=0x0c0a64d0u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0a64d2;
P_0c0a64d2: /* original ff37, guest PC 0x0c0a64d2 */
if(!s->budget--) { s->failed_pc=0x0c0a64d2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64d4;
P_0c0a64d4: /* original e004, guest PC 0x0c0a64d4 */
if(!s->budget--) { s->failed_pc=0x0c0a64d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0a64d6;
P_0c0a64d6: /* original f3e6, guest PC 0x0c0a64d6 */
if(!s->budget--) { s->failed_pc=0x0c0a64d6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64d8;
P_0c0a64d8: /* original e040, guest PC 0x0c0a64d8 */
if(!s->budget--) { s->failed_pc=0x0c0a64d8u; return 0; }
r[0]=0x00000040u;
goto P_0c0a64da;
P_0c0a64da: /* original ff37, guest PC 0x0c0a64da */
if(!s->budget--) { s->failed_pc=0x0c0a64dau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64dc;
P_0c0a64dc: /* original e008, guest PC 0x0c0a64dc */
if(!s->budget--) { s->failed_pc=0x0c0a64dcu; return 0; }
r[0]=0x00000008u;
goto P_0c0a64de;
P_0c0a64de: /* original f3e6, guest PC 0x0c0a64de */
if(!s->budget--) { s->failed_pc=0x0c0a64deu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64e0;
P_0c0a64e0: /* original e044, guest PC 0x0c0a64e0 */
if(!s->budget--) { s->failed_pc=0x0c0a64e0u; return 0; }
r[0]=0x00000044u;
goto P_0c0a64e2;
P_0c0a64e2: /* original ff37, guest PC 0x0c0a64e2 */
if(!s->budget--) { s->failed_pc=0x0c0a64e2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64e4;
P_0c0a64e4: /* original e00c, guest PC 0x0c0a64e4 */
if(!s->budget--) { s->failed_pc=0x0c0a64e4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a64e6;
P_0c0a64e6: /* original f3e6, guest PC 0x0c0a64e6 */
if(!s->budget--) { s->failed_pc=0x0c0a64e6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64e8;
P_0c0a64e8: /* original e030, guest PC 0x0c0a64e8 */
if(!s->budget--) { s->failed_pc=0x0c0a64e8u; return 0; }
r[0]=0x00000030u;
goto P_0c0a64ea;
P_0c0a64ea: /* original ff37, guest PC 0x0c0a64ea */
if(!s->budget--) { s->failed_pc=0x0c0a64eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64ec;
P_0c0a64ec: /* original e010, guest PC 0x0c0a64ec */
if(!s->budget--) { s->failed_pc=0x0c0a64ecu; return 0; }
r[0]=0x00000010u;
goto P_0c0a64ee;
P_0c0a64ee: /* original f3e6, guest PC 0x0c0a64ee */
if(!s->budget--) { s->failed_pc=0x0c0a64eeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64f0;
P_0c0a64f0: /* original e034, guest PC 0x0c0a64f0 */
if(!s->budget--) { s->failed_pc=0x0c0a64f0u; return 0; }
r[0]=0x00000034u;
goto P_0c0a64f2;
P_0c0a64f2: /* original ff37, guest PC 0x0c0a64f2 */
if(!s->budget--) { s->failed_pc=0x0c0a64f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64f4;
P_0c0a64f4: /* original e014, guest PC 0x0c0a64f4 */
if(!s->budget--) { s->failed_pc=0x0c0a64f4u; return 0; }
r[0]=0x00000014u;
goto P_0c0a64f6;
P_0c0a64f6: /* original f3e6, guest PC 0x0c0a64f6 */
if(!s->budget--) { s->failed_pc=0x0c0a64f6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64f8;
P_0c0a64f8: /* original e038, guest PC 0x0c0a64f8 */
if(!s->budget--) { s->failed_pc=0x0c0a64f8u; return 0; }
r[0]=0x00000038u;
goto P_0c0a64fa;
P_0c0a64fa: /* original ff37, guest PC 0x0c0a64fa */
if(!s->budget--) { s->failed_pc=0x0c0a64fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64fc;
P_0c0a64fc: /* original e018, guest PC 0x0c0a64fc */
if(!s->budget--) { s->failed_pc=0x0c0a64fcu; return 0; }
r[0]=0x00000018u;
goto P_0c0a64fe;
P_0c0a64fe: /* original f3e6, guest PC 0x0c0a64fe */
if(!s->budget--) { s->failed_pc=0x0c0a64feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a6500;
P_0c0a6500: /* original e024, guest PC 0x0c0a6500 */
if(!s->budget--) { s->failed_pc=0x0c0a6500u; return 0; }
r[0]=0x00000024u;
goto P_0c0a6502;
P_0c0a6502: /* original ff37, guest PC 0x0c0a6502 */
if(!s->budget--) { s->failed_pc=0x0c0a6502u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6504;
P_0c0a6504: /* original e01c, guest PC 0x0c0a6504 */
if(!s->budget--) { s->failed_pc=0x0c0a6504u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a6506;
P_0c0a6506: /* original f3e6, guest PC 0x0c0a6506 */
if(!s->budget--) { s->failed_pc=0x0c0a6506u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a6508;
P_0c0a6508: /* original e028, guest PC 0x0c0a6508 */
if(!s->budget--) { s->failed_pc=0x0c0a6508u; return 0; }
r[0]=0x00000028u;
goto P_0c0a650a;
P_0c0a650a: /* original 69a3, guest PC 0x0c0a650a */
if(!s->budget--) { s->failed_pc=0x0c0a650au; return 0; }
r[9]=r[10];
goto P_0c0a650c;
P_0c0a650c: /* original ff37, guest PC 0x0c0a650c */
if(!s->budget--) { s->failed_pc=0x0c0a650cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a650e;
P_0c0a650e: /* original e020, guest PC 0x0c0a650e */
if(!s->budget--) { s->failed_pc=0x0c0a650eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a6510;
P_0c0a6510: /* original f3e6, guest PC 0x0c0a6510 */
if(!s->budget--) { s->failed_pc=0x0c0a6510u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a6512;
P_0c0a6512: /* original 6eb3, guest PC 0x0c0a6512 */
if(!s->budget--) { s->failed_pc=0x0c0a6512u; return 0; }
r[14]=r[11];
goto P_0c0a6514;
P_0c0a6514: /* original e02c, guest PC 0x0c0a6514 */
if(!s->budget--) { s->failed_pc=0x0c0a6514u; return 0; }
r[0]=0x0000002cu;
goto P_0c0a6516;
P_0c0a6516: /* original 7e04, guest PC 0x0c0a6516 */
if(!s->budget--) { s->failed_pc=0x0c0a6516u; return 0; }
r[14]+=0x00000004u;
goto P_0c0a6518;
P_0c0a6518: /* original ff37, guest PC 0x0c0a6518 */
if(!s->budget--) { s->failed_pc=0x0c0a6518u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a651a;
P_0c0a651a: /* original a029, guest PC 0x0c0a651a */
if(!s->budget--) { s->failed_pc=0x0c0a651au; return 0; }
r[11]=r[10];
goto P_0c0a6570;
P_0c0a651c: /* original 6ba3, guest PC 0x0c0a651c */
if(!s->budget--) { s->failed_pc=0x0c0a651cu; return 0; }
r[11]=r[10];
goto P_0c0a651e;
P_0c0a651e: /* original 66f3, guest PC 0x0c0a651e */
if(!s->budget--) { s->failed_pc=0x0c0a651eu; return 0; }
r[6]=r[15];
goto P_0c0a6520;
P_0c0a6520: /* original dc3d, guest PC 0x0c0a6520 */
if(!s->budget--) { s->failed_pc=0x0c0a6520u; return 0; }
r[12]=read(ram,0x0c0a6618u,4);
goto P_0c0a6522;
P_0c0a6522: /* original 64f3, guest PC 0x0c0a6522 */
if(!s->budget--) { s->failed_pc=0x0c0a6522u; return 0; }
r[4]=r[15];
goto P_0c0a6524;
P_0c0a6524: /* original 65e3, guest PC 0x0c0a6524 */
if(!s->budget--) { s->failed_pc=0x0c0a6524u; return 0; }
r[5]=r[14];
goto P_0c0a6526;
P_0c0a6526: /* original 7630, guest PC 0x0c0a6526 */
if(!s->budget--) { s->failed_pc=0x0c0a6526u; return 0; }
r[6]+=0x00000030u;
goto P_0c0a6528;
P_0c0a6528: /* original 4c0b, guest PC 0x0c0a6528 */
if(!s->budget--) { s->failed_pc=0x0c0a6528u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a652cu;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a652cu) { target=s->pc; goto dispatch; }
goto P_0c0a652c;
P_0c0a652a: /* original 7418, guest PC 0x0c0a652a */
if(!s->budget--) { s->failed_pc=0x0c0a652au; return 0; }
r[4]+=0x00000018u;
goto P_0c0a652c;
P_0c0a652c: /* original 66f3, guest PC 0x0c0a652c */
if(!s->budget--) { s->failed_pc=0x0c0a652cu; return 0; }
r[6]=r[15];
goto P_0c0a652e;
P_0c0a652e: /* original 64f3, guest PC 0x0c0a652e */
if(!s->budget--) { s->failed_pc=0x0c0a652eu; return 0; }
r[4]=r[15];
goto P_0c0a6530;
P_0c0a6530: /* original 65e3, guest PC 0x0c0a6530 */
if(!s->budget--) { s->failed_pc=0x0c0a6530u; return 0; }
r[5]=r[14];
goto P_0c0a6532;
P_0c0a6532: /* original 7624, guest PC 0x0c0a6532 */
if(!s->budget--) { s->failed_pc=0x0c0a6532u; return 0; }
r[6]+=0x00000024u;
goto P_0c0a6534;
P_0c0a6534: /* original 4c0b, guest PC 0x0c0a6534 */
if(!s->budget--) { s->failed_pc=0x0c0a6534u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a6538u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a6538u) { target=s->pc; goto dispatch; }
goto P_0c0a6538;
P_0c0a6536: /* original 740c, guest PC 0x0c0a6536 */
if(!s->budget--) { s->failed_pc=0x0c0a6536u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a6538;
P_0c0a6538: /* original 65f3, guest PC 0x0c0a6538 */
if(!s->budget--) { s->failed_pc=0x0c0a6538u; return 0; }
r[5]=r[15];
goto P_0c0a653a;
P_0c0a653a: /* original dc38, guest PC 0x0c0a653a */
if(!s->budget--) { s->failed_pc=0x0c0a653au; return 0; }
r[12]=read(ram,0x0c0a661cu,4);
goto P_0c0a653c;
P_0c0a653c: /* original 64f3, guest PC 0x0c0a653c */
if(!s->budget--) { s->failed_pc=0x0c0a653cu; return 0; }
r[4]=r[15];
goto P_0c0a653e;
P_0c0a653e: /* original 753c, guest PC 0x0c0a653e */
if(!s->budget--) { s->failed_pc=0x0c0a653eu; return 0; }
r[5]+=0x0000003cu;
goto P_0c0a6540;
P_0c0a6540: /* original 7e0c, guest PC 0x0c0a6540 */
if(!s->budget--) { s->failed_pc=0x0c0a6540u; return 0; }
r[14]+=0x0000000cu;
goto P_0c0a6542;
P_0c0a6542: /* original 4c0b, guest PC 0x0c0a6542 */
if(!s->budget--) { s->failed_pc=0x0c0a6542u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a6546u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a6546u) { target=s->pc; goto dispatch; }
goto P_0c0a6546;
P_0c0a6544: /* original 7418, guest PC 0x0c0a6544 */
if(!s->budget--) { s->failed_pc=0x0c0a6544u; return 0; }
r[4]+=0x00000018u;
goto P_0c0a6546;
P_0c0a6546: /* original 65f3, guest PC 0x0c0a6546 */
if(!s->budget--) { s->failed_pc=0x0c0a6546u; return 0; }
r[5]=r[15];
goto P_0c0a6548;
P_0c0a6548: /* original 64f3, guest PC 0x0c0a6548 */
if(!s->budget--) { s->failed_pc=0x0c0a6548u; return 0; }
r[4]=r[15];
goto P_0c0a654a;
P_0c0a654a: /* original 753c, guest PC 0x0c0a654a */
if(!s->budget--) { s->failed_pc=0x0c0a654au; return 0; }
r[5]+=0x0000003cu;
goto P_0c0a654c;
P_0c0a654c: /* original fe0c, guest PC 0x0c0a654c */
if(!s->budget--) { s->failed_pc=0x0c0a654cu; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c0a654e;
P_0c0a654e: /* original 4c0b, guest PC 0x0c0a654e */
if(!s->budget--) { s->failed_pc=0x0c0a654eu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a6552u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a6552u) { target=s->pc; goto dispatch; }
goto P_0c0a6552;
P_0c0a6550: /* original 740c, guest PC 0x0c0a6550 */
if(!s->budget--) { s->failed_pc=0x0c0a6550u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a6552;
P_0c0a6552: /* original f38d, guest PC 0x0c0a6552 */
if(!s->budget--) { s->failed_pc=0x0c0a6552u; return 0; }
fr[3]=0;
goto P_0c0a6554;
P_0c0a6554: /* original f3e5, guest PC 0x0c0a6554 */
if(!s->budget--) { s->failed_pc=0x0c0a6554u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c0a6556;
P_0c0a6556: /* original 8f03, guest PC 0x0c0a6556 */
if(!s->budget--) { s->failed_pc=0x0c0a6556u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,0);
if(!cond) { goto P_0c0a6560; }
goto P_0c0a655a;
P_0c0a6558: /* original f40c, guest PC 0x0c0a6558 */
if(!s->budget--) { s->failed_pc=0x0c0a6558u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0a655a;
P_0c0a655a: /* original e501, guest PC 0x0c0a655a */
if(!s->budget--) { s->failed_pc=0x0c0a655au; return 0; }
r[5]=0x00000001u;
goto P_0c0a655c;
P_0c0a655c: /* original a001, guest PC 0x0c0a655c */
if(!s->budget--) { s->failed_pc=0x0c0a655cu; return 0; }
r[4]=r[5];
goto P_0c0a6562;
P_0c0a655e: /* original 6453, guest PC 0x0c0a655e */
if(!s->budget--) { s->failed_pc=0x0c0a655eu; return 0; }
r[4]=r[5];
goto P_0c0a6560;
P_0c0a6560: /* original 6493, guest PC 0x0c0a6560 */
if(!s->budget--) { s->failed_pc=0x0c0a6560u; return 0; }
r[4]=r[9];
goto P_0c0a6562;
P_0c0a6562: /* original ff45, guest PC 0x0c0a6562 */
if(!s->budget--) { s->failed_pc=0x0c0a6562u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c0a6564;
P_0c0a6564: /* original 63bb, guest PC 0x0c0a6564 */
if(!s->budget--) { s->failed_pc=0x0c0a6564u; return 0; }
r[3]=0u-r[11];
goto P_0c0a6566;
P_0c0a6566: /* original 443d, guest PC 0x0c0a6566 */
if(!s->budget--) { s->failed_pc=0x0c0a6566u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0a6568;
P_0c0a6568: /* original 8f01, guest PC 0x0c0a6568 */
if(!s->budget--) { s->failed_pc=0x0c0a6568u; return 0; }
cond=r[17]&1u;
r[10]|=r[4];
if(!cond) { goto P_0c0a656e; }
goto P_0c0a656c;
P_0c0a656a: /* original 2a4b, guest PC 0x0c0a656a */
if(!s->budget--) { s->failed_pc=0x0c0a656au; return 0; }
r[10]|=r[4];
goto P_0c0a656c;
P_0c0a656c: /* original ff4c, guest PC 0x0c0a656c */
if(!s->budget--) { s->failed_pc=0x0c0a656cu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0a656e;
P_0c0a656e: /* original 7b01, guest PC 0x0c0a656e */
if(!s->budget--) { s->failed_pc=0x0c0a656eu; return 0; }
r[11]+=0x00000001u;
goto P_0c0a6570;
P_0c0a6570: /* original 3b83, guest PC 0x0c0a6570 */
if(!s->budget--) { s->failed_pc=0x0c0a6570u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[8])!=0);
goto P_0c0a6572;
P_0c0a6572: /* original 8bd4, guest PC 0x0c0a6572 */
if(!s->budget--) { s->failed_pc=0x0c0a6572u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a651e; }
goto P_0c0a6574;
P_0c0a6574: /* original e040, guest PC 0x0c0a6574 */
if(!s->budget--) { s->failed_pc=0x0c0a6574u; return 0; }
r[0]=0x00000040u;
goto P_0c0a6576;
P_0c0a6576: /* original ff5d, guest PC 0x0c0a6576 */
if(!s->budget--) { s->failed_pc=0x0c0a6576u; return 0; }
fr[15]&=0x7fffffffu;
goto P_0c0a6578;
P_0c0a6578: /* original f5d6, guest PC 0x0c0a6578 */
if(!s->budget--) { s->failed_pc=0x0c0a6578u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a657a;
P_0c0a657a: /* original e03c, guest PC 0x0c0a657a */
if(!s->budget--) { s->failed_pc=0x0c0a657au; return 0; }
r[0]=0x0000003cu;
goto P_0c0a657c;
P_0c0a657c: /* original f3f6, guest PC 0x0c0a657c */
if(!s->budget--) { s->failed_pc=0x0c0a657cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a657e;
P_0c0a657e: /* original e044, guest PC 0x0c0a657e */
if(!s->budget--) { s->failed_pc=0x0c0a657eu; return 0; }
r[0]=0x00000044u;
goto P_0c0a6580;
P_0c0a6580: /* original f6d6, guest PC 0x0c0a6580 */
if(!s->budget--) { s->failed_pc=0x0c0a6580u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c0a6582;
P_0c0a6582: /* original e040, guest PC 0x0c0a6582 */
if(!s->budget--) { s->failed_pc=0x0c0a6582u; return 0; }
r[0]=0x00000040u;
goto P_0c0a6584;
P_0c0a6584: /* original f0fc, guest PC 0x0c0a6584 */
if(!s->budget--) { s->failed_pc=0x0c0a6584u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0a6586;
P_0c0a6586: /* original f53e, guest PC 0x0c0a6586 */
if(!s->budget--) { s->failed_pc=0x0c0a6586u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[3],fr[5],r[18]);
goto P_0c0a6588;
P_0c0a6588: /* original f3f6, guest PC 0x0c0a6588 */
if(!s->budget--) { s->failed_pc=0x0c0a6588u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a658a;
P_0c0a658a: /* original e048, guest PC 0x0c0a658a */
if(!s->budget--) { s->failed_pc=0x0c0a658au; return 0; }
r[0]=0x00000048u;
goto P_0c0a658c;
P_0c0a658c: /* original f4fc, guest PC 0x0c0a658c */
if(!s->budget--) { s->failed_pc=0x0c0a658cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a658e;
P_0c0a658e: /* original f63e, guest PC 0x0c0a658e */
if(!s->budget--) { s->failed_pc=0x0c0a658eu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[3],fr[6],r[18]);
goto P_0c0a6590;
P_0c0a6590: /* original f3d6, guest PC 0x0c0a6590 */
if(!s->budget--) { s->failed_pc=0x0c0a6590u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a6592;
P_0c0a6592: /* original e044, guest PC 0x0c0a6592 */
if(!s->budget--) { s->failed_pc=0x0c0a6592u; return 0; }
r[0]=0x00000044u;
goto P_0c0a6594;
P_0c0a6594: /* original f2f6, guest PC 0x0c0a6594 */
if(!s->budget--) { s->failed_pc=0x0c0a6594u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6596;
P_0c0a6596: /* original e040, guest PC 0x0c0a6596 */
if(!s->budget--) { s->failed_pc=0x0c0a6596u; return 0; }
r[0]=0x00000040u;
goto P_0c0a6598;
P_0c0a6598: /* original f32e, guest PC 0x0c0a6598 */
if(!s->budget--) { s->failed_pc=0x0c0a6598u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0a659a;
P_0c0a659a: /* original f43c, guest PC 0x0c0a659a */
if(!s->budget--) { s->failed_pc=0x0c0a659au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a659c;
P_0c0a659c: /* original fd57, guest PC 0x0c0a659c */
if(!s->budget--) { s->failed_pc=0x0c0a659cu; return 0; }
vf3_matrix_store(s,ram,5,r[13]+r[0]);
goto P_0c0a659e;
P_0c0a659e: /* original e044, guest PC 0x0c0a659e */
if(!s->budget--) { s->failed_pc=0x0c0a659eu; return 0; }
r[0]=0x00000044u;
goto P_0c0a65a0;
P_0c0a65a0: /* original fd67, guest PC 0x0c0a65a0 */
if(!s->budget--) { s->failed_pc=0x0c0a65a0u; return 0; }
vf3_matrix_store(s,ram,6,r[13]+r[0]);
goto P_0c0a65a2;
P_0c0a65a2: /* original e048, guest PC 0x0c0a65a2 */
if(!s->budget--) { s->failed_pc=0x0c0a65a2u; return 0; }
r[0]=0x00000048u;
goto P_0c0a65a4;
P_0c0a65a4: /* original fd47, guest PC 0x0c0a65a4 */
if(!s->budget--) { s->failed_pc=0x0c0a65a4u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a65a6;
P_0c0a65a6: /* original 2fa2, guest PC 0x0c0a65a6 */
if(!s->budget--) { s->failed_pc=0x0c0a65a6u; return 0; }
write(ram,r[15],r[10],4);
goto P_0c0a65a8;
P_0c0a65a8: /* original d31d, guest PC 0x0c0a65a8 */
if(!s->budget--) { s->failed_pc=0x0c0a65a8u; return 0; }
r[3]=read(ram,0x0c0a6620u,4);
goto P_0c0a65aa;
P_0c0a65aa: /* original 430b, guest PC 0x0c0a65aa */
if(!s->budget--) { s->failed_pc=0x0c0a65aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a65aeu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a65aeu) { target=s->pc; goto dispatch; }
goto P_0c0a65ae;
P_0c0a65ac: /* original e401, guest PC 0x0c0a65ac */
if(!s->budget--) { s->failed_pc=0x0c0a65acu; return 0; }
r[4]=0x00000001u;
goto P_0c0a65ae;
P_0c0a65ae: /* original 60f2, guest PC 0x0c0a65ae */
if(!s->budget--) { s->failed_pc=0x0c0a65aeu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0a65b0;
P_0c0a65b0: /* original 7f48, guest PC 0x0c0a65b0 */
if(!s->budget--) { s->failed_pc=0x0c0a65b0u; return 0; }
r[15]+=0x00000048u;
goto P_0c0a65b2;
P_0c0a65b2: /* original 4f26, guest PC 0x0c0a65b2 */
if(!s->budget--) { s->failed_pc=0x0c0a65b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a65b4;
P_0c0a65b4: /* original fef9, guest PC 0x0c0a65b4 */
if(!s->budget--) { s->failed_pc=0x0c0a65b4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a65b6;
P_0c0a65b6: /* original fff9, guest PC 0x0c0a65b6 */
if(!s->budget--) { s->failed_pc=0x0c0a65b6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a65b8;
P_0c0a65b8: /* original 68f6, guest PC 0x0c0a65b8 */
if(!s->budget--) { s->failed_pc=0x0c0a65b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a65ba;
P_0c0a65ba: /* original 69f6, guest PC 0x0c0a65ba */
if(!s->budget--) { s->failed_pc=0x0c0a65bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a65bc;
P_0c0a65bc: /* original 6af6, guest PC 0x0c0a65bc */
if(!s->budget--) { s->failed_pc=0x0c0a65bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a65be;
P_0c0a65be: /* original 6bf6, guest PC 0x0c0a65be */
if(!s->budget--) { s->failed_pc=0x0c0a65beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a65c0;
P_0c0a65c0: /* original 6cf6, guest PC 0x0c0a65c0 */
if(!s->budget--) { s->failed_pc=0x0c0a65c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a65c2;
P_0c0a65c2: /* original 6df6, guest PC 0x0c0a65c2 */
if(!s->budget--) { s->failed_pc=0x0c0a65c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a65c4;
P_0c0a65c4: /* original 000b, guest PC 0x0c0a65c4 */
if(!s->budget--) { s->failed_pc=0x0c0a65c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a65c6: /* original 6ef6, guest PC 0x0c0a65c6 */
if(!s->budget--) { s->failed_pc=0x0c0a65c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a65c8;
P_0c0a65c8: /* original 2fe6, guest PC 0x0c0a65c8 */
if(!s->budget--) { s->failed_pc=0x0c0a65c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a65ca;
P_0c0a65ca: /* original 6e53, guest PC 0x0c0a65ca */
if(!s->budget--) { s->failed_pc=0x0c0a65cau; return 0; }
r[14]=r[5];
goto P_0c0a65cc;
P_0c0a65cc: /* original 2fd6, guest PC 0x0c0a65cc */
if(!s->budget--) { s->failed_pc=0x0c0a65ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a65ce;
P_0c0a65ce: /* original 2fc6, guest PC 0x0c0a65ce */
if(!s->budget--) { s->failed_pc=0x0c0a65ceu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a65d0;
P_0c0a65d0: /* original 6c63, guest PC 0x0c0a65d0 */
if(!s->budget--) { s->failed_pc=0x0c0a65d0u; return 0; }
r[12]=r[6];
goto P_0c0a65d2;
P_0c0a65d2: /* original 2fb6, guest PC 0x0c0a65d2 */
if(!s->budget--) { s->failed_pc=0x0c0a65d2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a65d4;
P_0c0a65d4: /* original 4f22, guest PC 0x0c0a65d4 */
if(!s->budget--) { s->failed_pc=0x0c0a65d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a65d6;
P_0c0a65d6: /* original 7ff0, guest PC 0x0c0a65d6 */
if(!s->budget--) { s->failed_pc=0x0c0a65d6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a65d8;
P_0c0a65d8: /* original 2f42, guest PC 0x0c0a65d8 */
if(!s->budget--) { s->failed_pc=0x0c0a65d8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a65da;
P_0c0a65da: /* original d312, guest PC 0x0c0a65da */
if(!s->budget--) { s->failed_pc=0x0c0a65dau; return 0; }
r[3]=read(ram,0x0c0a6624u,4);
goto P_0c0a65dc;
P_0c0a65dc: /* original 430b, guest PC 0x0c0a65dc */
if(!s->budget--) { s->failed_pc=0x0c0a65dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a65e0u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a65e0u) { target=s->pc; goto dispatch; }
goto P_0c0a65e0;
P_0c0a65de: /* original 7410, guest PC 0x0c0a65de */
if(!s->budget--) { s->failed_pc=0x0c0a65deu; return 0; }
r[4]+=0x00000010u;
goto P_0c0a65e0;
P_0c0a65e0: /* original 64e2, guest PC 0x0c0a65e0 */
if(!s->budget--) { s->failed_pc=0x0c0a65e0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a65e2;
P_0c0a65e2: /* original 6be3, guest PC 0x0c0a65e2 */
if(!s->budget--) { s->failed_pc=0x0c0a65e2u; return 0; }
r[11]=r[14];
goto P_0c0a65e4;
P_0c0a65e4: /* original 6ec3, guest PC 0x0c0a65e4 */
if(!s->budget--) { s->failed_pc=0x0c0a65e4u; return 0; }
r[14]=r[12];
goto P_0c0a65e6;
P_0c0a65e6: /* original 7e04, guest PC 0x0c0a65e6 */
if(!s->budget--) { s->failed_pc=0x0c0a65e6u; return 0; }
r[14]+=0x00000004u;
goto P_0c0a65e8;
P_0c0a65e8: /* original 6d4c, guest PC 0x0c0a65e8 */
if(!s->budget--) { s->failed_pc=0x0c0a65e8u; return 0; }
r[13]=r[4]&255u;
goto P_0c0a65ea;
P_0c0a65ea: /* original 2cd2, guest PC 0x0c0a65ea */
if(!s->budget--) { s->failed_pc=0x0c0a65eau; return 0; }
write(ram,r[12],r[13],4);
goto P_0c0a65ec;
P_0c0a65ec: /* original 7b04, guest PC 0x0c0a65ec */
if(!s->budget--) { s->failed_pc=0x0c0a65ecu; return 0; }
r[11]+=0x00000004u;
goto P_0c0a65ee;
P_0c0a65ee: /* original d20e, guest PC 0x0c0a65ee */
if(!s->budget--) { s->failed_pc=0x0c0a65eeu; return 0; }
r[2]=read(ram,0x0c0a6628u,4);
goto P_0c0a65f0;
P_0c0a65f0: /* original 65e3, guest PC 0x0c0a65f0 */
if(!s->budget--) { s->failed_pc=0x0c0a65f0u; return 0; }
r[5]=r[14];
goto P_0c0a65f2;
P_0c0a65f2: /* original 420b, guest PC 0x0c0a65f2 */
if(!s->budget--) { s->failed_pc=0x0c0a65f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a65f6u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a65f6u) { target=s->pc; goto dispatch; }
goto P_0c0a65f6;
P_0c0a65f4: /* original 64b3, guest PC 0x0c0a65f4 */
if(!s->budget--) { s->failed_pc=0x0c0a65f4u; return 0; }
r[4]=r[11];
goto P_0c0a65f6;
P_0c0a65f6: /* original 7dff, guest PC 0x0c0a65f6 */
if(!s->budget--) { s->failed_pc=0x0c0a65f6u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0a65f8;
P_0c0a65f8: /* original 4d15, guest PC 0x0c0a65f8 */
if(!s->budget--) { s->failed_pc=0x0c0a65f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c0a65fa;
P_0c0a65fa: /* original 7b0c, guest PC 0x0c0a65fa */
if(!s->budget--) { s->failed_pc=0x0c0a65fau; return 0; }
r[11]+=0x0000000cu;
goto P_0c0a65fc;
P_0c0a65fc: /* original 8df7, guest PC 0x0c0a65fc */
if(!s->budget--) { s->failed_pc=0x0c0a65fcu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000000cu;
if(cond) { goto P_0c0a65ee; }
goto P_0c0a6600;
P_0c0a65fe: /* original 7e0c, guest PC 0x0c0a65fe */
if(!s->budget--) { s->failed_pc=0x0c0a65feu; return 0; }
r[14]+=0x0000000cu;
goto P_0c0a6600;
P_0c0a6600: /* original 7f10, guest PC 0x0c0a6600 */
if(!s->budget--) { s->failed_pc=0x0c0a6600u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a6602;
P_0c0a6602: /* original 4f26, guest PC 0x0c0a6602 */
if(!s->budget--) { s->failed_pc=0x0c0a6602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a6604;
P_0c0a6604: /* original 6bf6, guest PC 0x0c0a6604 */
if(!s->budget--) { s->failed_pc=0x0c0a6604u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a6606;
P_0c0a6606: /* original 6cf6, guest PC 0x0c0a6606 */
if(!s->budget--) { s->failed_pc=0x0c0a6606u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a6608;
P_0c0a6608: /* original 6df6, guest PC 0x0c0a6608 */
if(!s->budget--) { s->failed_pc=0x0c0a6608u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a660a;
P_0c0a660a: /* original 000b, guest PC 0x0c0a660a */
if(!s->budget--) { s->failed_pc=0x0c0a660au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a660c: /* original 6ef6, guest PC 0x0c0a660c */
if(!s->budget--) { s->failed_pc=0x0c0a660cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a660eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a660eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
