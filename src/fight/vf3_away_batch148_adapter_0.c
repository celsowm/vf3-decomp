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
int vf3_away_batch148_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038570u: goto P_0c038570;
case 0x0c038572u: goto P_0c038572;
case 0x0c038574u: goto P_0c038574;
case 0x0c038576u: goto P_0c038576;
case 0x0c038578u: goto P_0c038578;
case 0x0c03857au: goto P_0c03857a;
case 0x0c03857cu: goto P_0c03857c;
case 0x0c03857eu: goto P_0c03857e;
case 0x0c038580u: goto P_0c038580;
case 0x0c038582u: goto P_0c038582;
case 0x0c038584u: goto P_0c038584;
case 0x0c038586u: goto P_0c038586;
case 0x0c038590u: goto P_0c038590;
case 0x0c038592u: goto P_0c038592;
case 0x0c038594u: goto P_0c038594;
case 0x0c038596u: goto P_0c038596;
case 0x0c038598u: goto P_0c038598;
case 0x0c03859au: goto P_0c03859a;
case 0x0c03859cu: goto P_0c03859c;
case 0x0c03859eu: goto P_0c03859e;
case 0x0c0385a0u: goto P_0c0385a0;
case 0x0c0385a2u: goto P_0c0385a2;
case 0x0c0385a4u: goto P_0c0385a4;
case 0x0c0385a6u: goto P_0c0385a6;
case 0x0c0385a8u: goto P_0c0385a8;
case 0x0c0385aau: goto P_0c0385aa;
case 0x0c0385acu: goto P_0c0385ac;
case 0x0c0385aeu: goto P_0c0385ae;
case 0x0c0385b0u: goto P_0c0385b0;
case 0x0c0385b2u: goto P_0c0385b2;
case 0x0c0385b4u: goto P_0c0385b4;
case 0x0c0385b6u: goto P_0c0385b6;
case 0x0c0385b8u: goto P_0c0385b8;
case 0x0c0385c0u: goto P_0c0385c0;
case 0x0c0385c2u: goto P_0c0385c2;
case 0x0c0385c4u: goto P_0c0385c4;
case 0x0c0385c6u: goto P_0c0385c6;
case 0x0c0385c8u: goto P_0c0385c8;
case 0x0c0385cau: goto P_0c0385ca;
case 0x0c0385ccu: goto P_0c0385cc;
case 0x0c0385ceu: goto P_0c0385ce;
case 0x0c0385d0u: goto P_0c0385d0;
case 0x0c0385d2u: goto P_0c0385d2;
case 0x0c0385d4u: goto P_0c0385d4;
case 0x0c0385d6u: goto P_0c0385d6;
case 0x0c0385d8u: goto P_0c0385d8;
case 0x0c0385dau: goto P_0c0385da;
case 0x0c0385dcu: goto P_0c0385dc;
case 0x0c0385deu: goto P_0c0385de;
case 0x0c0385e0u: goto P_0c0385e0;
case 0x0c0385e2u: goto P_0c0385e2;
case 0x0c0385e4u: goto P_0c0385e4;
case 0x0c0385e6u: goto P_0c0385e6;
case 0x0c03b5c0u: goto P_0c03b5c0;
case 0x0c03b5c2u: goto P_0c03b5c2;
case 0x0c03b5c4u: goto P_0c03b5c4;
case 0x0c03b5c6u: goto P_0c03b5c6;
case 0x0c03b5c8u: goto P_0c03b5c8;
case 0x0c03b5cau: goto P_0c03b5ca;
case 0x0c03b5ccu: goto P_0c03b5cc;
case 0x0c03b5ceu: goto P_0c03b5ce;
case 0x0c03b5d0u: goto P_0c03b5d0;
case 0x0c03b5d2u: goto P_0c03b5d2;
case 0x0c03b5d4u: goto P_0c03b5d4;
case 0x0c03b5d6u: goto P_0c03b5d6;
case 0x0c03b5d8u: goto P_0c03b5d8;
case 0x0c03b5dau: goto P_0c03b5da;
case 0x0c03b5dcu: goto P_0c03b5dc;
case 0x0c03b5deu: goto P_0c03b5de;
case 0x0c03b5e0u: goto P_0c03b5e0;
case 0x0c03b5e2u: goto P_0c03b5e2;
case 0x0c03b5e4u: goto P_0c03b5e4;
case 0x0c03b5e6u: goto P_0c03b5e6;
case 0x0c03b5e8u: goto P_0c03b5e8;
case 0x0c03b5eau: goto P_0c03b5ea;
case 0x0c03b5ecu: goto P_0c03b5ec;
case 0x0c03b5eeu: goto P_0c03b5ee;
case 0x0c03b5f0u: goto P_0c03b5f0;
case 0x0c03b5f2u: goto P_0c03b5f2;
case 0x0c03b5f4u: goto P_0c03b5f4;
case 0x0c03b5f6u: goto P_0c03b5f6;
case 0x0c03b5f8u: goto P_0c03b5f8;
case 0x0c03b5fau: goto P_0c03b5fa;
case 0x0c03b5fcu: goto P_0c03b5fc;
case 0x0c03b5feu: goto P_0c03b5fe;
case 0x0c03b600u: goto P_0c03b600;
case 0x0c03b602u: goto P_0c03b602;
case 0x0c03b604u: goto P_0c03b604;
case 0x0c03b606u: goto P_0c03b606;
case 0x0c03b608u: goto P_0c03b608;
case 0x0c03b60au: goto P_0c03b60a;
case 0x0c03b60cu: goto P_0c03b60c;
case 0x0c03b60eu: goto P_0c03b60e;
case 0x0c03b610u: goto P_0c03b610;
case 0x0c03b612u: goto P_0c03b612;
case 0x0c03b614u: goto P_0c03b614;
case 0x0c03b616u: goto P_0c03b616;
case 0x0c03b618u: goto P_0c03b618;
case 0x0c03b61au: goto P_0c03b61a;
case 0x0c03c1c0u: goto P_0c03c1c0;
case 0x0c03c1c2u: goto P_0c03c1c2;
case 0x0c03c1c4u: goto P_0c03c1c4;
case 0x0c03c1c6u: goto P_0c03c1c6;
case 0x0c03c1c8u: goto P_0c03c1c8;
case 0x0c03c1cau: goto P_0c03c1ca;
case 0x0c03c1ccu: goto P_0c03c1cc;
case 0x0c03c1ceu: goto P_0c03c1ce;
case 0x0c03c1d0u: goto P_0c03c1d0;
case 0x0c03c1d2u: goto P_0c03c1d2;
case 0x0c03c1d4u: goto P_0c03c1d4;
case 0x0c03c1d6u: goto P_0c03c1d6;
case 0x0c03c1d8u: goto P_0c03c1d8;
case 0x0c03c1dau: goto P_0c03c1da;
case 0x0c03c1dcu: goto P_0c03c1dc;
case 0x0c03c1deu: goto P_0c03c1de;
case 0x0c03c1e0u: goto P_0c03c1e0;
case 0x0c03c1e2u: goto P_0c03c1e2;
case 0x0c03c1e4u: goto P_0c03c1e4;
case 0x0c03c1e6u: goto P_0c03c1e6;
case 0x0c03c1e8u: goto P_0c03c1e8;
case 0x0c03c1eau: goto P_0c03c1ea;
case 0x0c03c1ecu: goto P_0c03c1ec;
case 0x0c03c1eeu: goto P_0c03c1ee;
case 0x0c03c1f0u: goto P_0c03c1f0;
case 0x0c03c1f2u: goto P_0c03c1f2;
case 0x0c03c1f4u: goto P_0c03c1f4;
case 0x0c03c1f6u: goto P_0c03c1f6;
case 0x0c03c1f8u: goto P_0c03c1f8;
case 0x0c03c1fau: goto P_0c03c1fa;
case 0x0c03c1fcu: goto P_0c03c1fc;
case 0x0c03c1feu: goto P_0c03c1fe;
case 0x0c03c200u: goto P_0c03c200;
case 0x0c03c202u: goto P_0c03c202;
case 0x0c03c204u: goto P_0c03c204;
case 0x0c03c206u: goto P_0c03c206;
case 0x0c03c208u: goto P_0c03c208;
case 0x0c03d260u: goto P_0c03d260;
case 0x0c03d262u: goto P_0c03d262;
case 0x0c03d264u: goto P_0c03d264;
case 0x0c03d266u: goto P_0c03d266;
case 0x0c03d268u: goto P_0c03d268;
case 0x0c03d26au: goto P_0c03d26a;
case 0x0c03d26cu: goto P_0c03d26c;
case 0x0c03d26eu: goto P_0c03d26e;
case 0x0c03d270u: goto P_0c03d270;
case 0x0c03d272u: goto P_0c03d272;
case 0x0c03d274u: goto P_0c03d274;
case 0x0c03d276u: goto P_0c03d276;
case 0x0c03d278u: goto P_0c03d278;
case 0x0c03d27au: goto P_0c03d27a;
case 0x0c03d27cu: goto P_0c03d27c;
case 0x0c03d27eu: goto P_0c03d27e;
case 0x0c03dd00u: goto P_0c03dd00;
case 0x0c03dd02u: goto P_0c03dd02;
case 0x0c03dd04u: goto P_0c03dd04;
case 0x0c03dd06u: goto P_0c03dd06;
case 0x0c03dd08u: goto P_0c03dd08;
case 0x0c03dd30u: goto P_0c03dd30;
case 0x0c03dd32u: goto P_0c03dd32;
case 0x0c03dd34u: goto P_0c03dd34;
case 0x0c03dd36u: goto P_0c03dd36;
case 0x0c03dd38u: goto P_0c03dd38;
case 0x0c03dd3au: goto P_0c03dd3a;
case 0x0c03dd3cu: goto P_0c03dd3c;
case 0x0c03dd3eu: goto P_0c03dd3e;
case 0x0c03dd40u: goto P_0c03dd40;
case 0x0c03dd42u: goto P_0c03dd42;
case 0x0c03dd44u: goto P_0c03dd44;
case 0x0c03dd46u: goto P_0c03dd46;
case 0x0c03dd48u: goto P_0c03dd48;
case 0x0c03dd4au: goto P_0c03dd4a;
case 0x0c03dd4cu: goto P_0c03dd4c;
case 0x0c03dd4eu: goto P_0c03dd4e;
case 0x0c03dd50u: goto P_0c03dd50;
case 0x0c03dd52u: goto P_0c03dd52;
case 0x0c03dd54u: goto P_0c03dd54;
case 0x0c03dd56u: goto P_0c03dd56;
case 0x0c03dd58u: goto P_0c03dd58;
case 0x0c03dd5au: goto P_0c03dd5a;
case 0x0c03dd5cu: goto P_0c03dd5c;
case 0x0c03dd5eu: goto P_0c03dd5e;
case 0x0c03dd60u: goto P_0c03dd60;
case 0x0c03dd62u: goto P_0c03dd62;
case 0x0c03dd64u: goto P_0c03dd64;
case 0x0c03dd66u: goto P_0c03dd66;
case 0x0c03dd68u: goto P_0c03dd68;
case 0x0c03dd6au: goto P_0c03dd6a;
case 0x0c03dd6cu: goto P_0c03dd6c;
case 0x0c03dd6eu: goto P_0c03dd6e;
case 0x0c03dd70u: goto P_0c03dd70;
case 0x0c03dd72u: goto P_0c03dd72;
case 0x0c03dd74u: goto P_0c03dd74;
case 0x0c03dd76u: goto P_0c03dd76;
case 0x0c03dd78u: goto P_0c03dd78;
case 0x0c03dd7au: goto P_0c03dd7a;
case 0x0c03dd7cu: goto P_0c03dd7c;
case 0x0c03dd7eu: goto P_0c03dd7e;
case 0x0c03dd80u: goto P_0c03dd80;
case 0x0c03dd82u: goto P_0c03dd82;
case 0x0c03dd84u: goto P_0c03dd84;
case 0x0c03dd86u: goto P_0c03dd86;
case 0x0c03dd88u: goto P_0c03dd88;
case 0x0c03dd8au: goto P_0c03dd8a;
case 0x0c03dd8cu: goto P_0c03dd8c;
case 0x0c03dd8eu: goto P_0c03dd8e;
case 0x0c03dd90u: goto P_0c03dd90;
case 0x0c03dd92u: goto P_0c03dd92;
case 0x0c03dd94u: goto P_0c03dd94;
case 0x0c03dd96u: goto P_0c03dd96;
default: return vf3_matrix_family(target,s,ram);
}
P_0c038570: /* original d41f, guest PC 0x0c038570 */
if(!s->budget--) { s->failed_pc=0x0c038570u; return 0; }
r[4]=read(ram,0x0c0385f0u,4);
goto P_0c038572;
P_0c038572: /* original e000, guest PC 0x0c038572 */
if(!s->budget--) { s->failed_pc=0x0c038572u; return 0; }
r[0]=0x00000000u;
goto P_0c038574;
P_0c038574: /* original 8143, guest PC 0x0c038574 */
if(!s->budget--) { s->failed_pc=0x0c038574u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c038576;
P_0c038576: /* original d51f, guest PC 0x0c038576 */
if(!s->budget--) { s->failed_pc=0x0c038576u; return 0; }
r[5]=read(ram,0x0c0385f4u,4);
goto P_0c038578;
P_0c038578: /* original 6552, guest PC 0x0c038578 */
if(!s->budget--) { s->failed_pc=0x0c038578u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c03857a;
P_0c03857a: /* original 145b, guest PC 0x0c03857a */
if(!s->budget--) { s->failed_pc=0x0c03857au; return 0; }
write(ram,r[4]+44,r[5],4);
goto P_0c03857c;
P_0c03857c: /* original 145c, guest PC 0x0c03857c */
if(!s->budget--) { s->failed_pc=0x0c03857cu; return 0; }
write(ram,r[4]+48,r[5],4);
goto P_0c03857e;
P_0c03857e: /* original d51e, guest PC 0x0c03857e */
if(!s->budget--) { s->failed_pc=0x0c03857eu; return 0; }
r[5]=read(ram,0x0c0385f8u,4);
goto P_0c038580;
P_0c038580: /* original 6552, guest PC 0x0c038580 */
if(!s->budget--) { s->failed_pc=0x0c038580u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c038582;
P_0c038582: /* original 145e, guest PC 0x0c038582 */
if(!s->budget--) { s->failed_pc=0x0c038582u; return 0; }
write(ram,r[4]+56,r[5],4);
goto P_0c038584;
P_0c038584: /* original 000b, guest PC 0x0c038584 */
if(!s->budget--) { s->failed_pc=0x0c038584u; return 0; }
target=r[16];
write(ram,r[4]+60,r[5],4);
s->pc=target; return ram->oob==0;
P_0c038586: /* original 145f, guest PC 0x0c038586 */
if(!s->budget--) { s->failed_pc=0x0c038586u; return 0; }
write(ram,r[4]+60,r[5],4);
if(!vf3_matrix_family(0x0c038588u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038588u; return 0; } return 1;
P_0c038590: /* original d417, guest PC 0x0c038590 */
if(!s->budget--) { s->failed_pc=0x0c038590u; return 0; }
r[4]=read(ram,0x0c0385f0u,4);
goto P_0c038592;
P_0c038592: /* original e330, guest PC 0x0c038592 */
if(!s->budget--) { s->failed_pc=0x0c038592u; return 0; }
r[3]=0x00000030u;
goto P_0c038594;
P_0c038594: /* original 8543, guest PC 0x0c038594 */
if(!s->budget--) { s->failed_pc=0x0c038594u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c038596;
P_0c038596: /* original 6503, guest PC 0x0c038596 */
if(!s->budget--) { s->failed_pc=0x0c038596u; return 0; }
r[5]=r[0];
goto P_0c038598;
P_0c038598: /* original 3533, guest PC 0x0c038598 */
if(!s->budget--) { s->failed_pc=0x0c038598u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c03859a;
P_0c03859a: /* original 8d0c, guest PC 0x0c03859a */
if(!s->budget--) { s->failed_pc=0x0c03859au; return 0; }
cond=r[17]&1u;
r[6]=0xffffffffu;
if(cond) { goto P_0c0385b6; }
goto P_0c03859e;
P_0c03859c: /* original e6ff, guest PC 0x0c03859c */
if(!s->budget--) { s->failed_pc=0x0c03859cu; return 0; }
r[6]=0xffffffffu;
goto P_0c03859e;
P_0c03859e: /* original 7501, guest PC 0x0c03859e */
if(!s->budget--) { s->failed_pc=0x0c03859eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0385a0;
P_0c0385a0: /* original 6053, guest PC 0x0c0385a0 */
if(!s->budget--) { s->failed_pc=0x0c0385a0u; return 0; }
r[0]=r[5];
goto P_0c0385a2;
P_0c0385a2: /* original 8143, guest PC 0x0c0385a2 */
if(!s->budget--) { s->failed_pc=0x0c0385a2u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0385a4;
P_0c0385a4: /* original d013, guest PC 0x0c0385a4 */
if(!s->budget--) { s->failed_pc=0x0c0385a4u; return 0; }
r[0]=read(ram,0x0c0385f4u,4);
goto P_0c0385a6;
P_0c0385a6: /* original 4508, guest PC 0x0c0385a6 */
if(!s->budget--) { s->failed_pc=0x0c0385a6u; return 0; }
r[5]<<=2;
goto P_0c0385a8;
P_0c0385a8: /* original 524b, guest PC 0x0c0385a8 */
if(!s->budget--) { s->failed_pc=0x0c0385a8u; return 0; }
r[2]=read(ram,r[4]+44,4);
goto P_0c0385aa;
P_0c0385aa: /* original 6653, guest PC 0x0c0385aa */
if(!s->budget--) { s->failed_pc=0x0c0385aau; return 0; }
r[6]=r[5];
goto P_0c0385ac;
P_0c0385ac: /* original 0526, guest PC 0x0c0385ac */
if(!s->budget--) { s->failed_pc=0x0c0385acu; return 0; }
write(ram,r[5]+r[0],r[2],4);
goto P_0c0385ae;
P_0c0385ae: /* original 524e, guest PC 0x0c0385ae */
if(!s->budget--) { s->failed_pc=0x0c0385aeu; return 0; }
r[2]=read(ram,r[4]+56,4);
goto P_0c0385b0;
P_0c0385b0: /* original d011, guest PC 0x0c0385b0 */
if(!s->budget--) { s->failed_pc=0x0c0385b0u; return 0; }
r[0]=read(ram,0x0c0385f8u,4);
goto P_0c0385b2;
P_0c0385b2: /* original 0626, guest PC 0x0c0385b2 */
if(!s->budget--) { s->failed_pc=0x0c0385b2u; return 0; }
write(ram,r[6]+r[0],r[2],4);
goto P_0c0385b4;
P_0c0385b4: /* original e600, guest PC 0x0c0385b4 */
if(!s->budget--) { s->failed_pc=0x0c0385b4u; return 0; }
r[6]=0x00000000u;
goto P_0c0385b6;
P_0c0385b6: /* original 000b, guest PC 0x0c0385b6 */
if(!s->budget--) { s->failed_pc=0x0c0385b6u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c0385b8: /* original 6063, guest PC 0x0c0385b8 */
if(!s->budget--) { s->failed_pc=0x0c0385b8u; return 0; }
r[0]=r[6];
if(!vf3_matrix_family(0x0c0385bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0385bau; return 0; } return 1;
P_0c0385c0: /* original d40b, guest PC 0x0c0385c0 */
if(!s->budget--) { s->failed_pc=0x0c0385c0u; return 0; }
r[4]=read(ram,0x0c0385f0u,4);
goto P_0c0385c2;
P_0c0385c2: /* original 8543, guest PC 0x0c0385c2 */
if(!s->budget--) { s->failed_pc=0x0c0385c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c0385c4;
P_0c0385c4: /* original 6103, guest PC 0x0c0385c4 */
if(!s->budget--) { s->failed_pc=0x0c0385c4u; return 0; }
r[1]=r[0];
goto P_0c0385c6;
P_0c0385c6: /* original 4115, guest PC 0x0c0385c6 */
if(!s->budget--) { s->failed_pc=0x0c0385c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0385c8;
P_0c0385c8: /* original 8f0c, guest PC 0x0c0385c8 */
if(!s->budget--) { s->failed_pc=0x0c0385c8u; return 0; }
cond=r[17]&1u;
r[5]=0xffffffffu;
if(!cond) { goto P_0c0385e4; }
goto P_0c0385cc;
P_0c0385ca: /* original e5ff, guest PC 0x0c0385ca */
if(!s->budget--) { s->failed_pc=0x0c0385cau; return 0; }
r[5]=0xffffffffu;
goto P_0c0385cc;
P_0c0385cc: /* original d00a, guest PC 0x0c0385cc */
if(!s->budget--) { s->failed_pc=0x0c0385ccu; return 0; }
r[0]=read(ram,0x0c0385f8u,4);
goto P_0c0385ce;
P_0c0385ce: /* original 6513, guest PC 0x0c0385ce */
if(!s->budget--) { s->failed_pc=0x0c0385ceu; return 0; }
r[5]=r[1];
goto P_0c0385d0;
P_0c0385d0: /* original 4508, guest PC 0x0c0385d0 */
if(!s->budget--) { s->failed_pc=0x0c0385d0u; return 0; }
r[5]<<=2;
goto P_0c0385d2;
P_0c0385d2: /* original 035e, guest PC 0x0c0385d2 */
if(!s->budget--) { s->failed_pc=0x0c0385d2u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0385d4;
P_0c0385d4: /* original 143e, guest PC 0x0c0385d4 */
if(!s->budget--) { s->failed_pc=0x0c0385d4u; return 0; }
write(ram,r[4]+56,r[3],4);
goto P_0c0385d6;
P_0c0385d6: /* original d007, guest PC 0x0c0385d6 */
if(!s->budget--) { s->failed_pc=0x0c0385d6u; return 0; }
r[0]=read(ram,0x0c0385f4u,4);
goto P_0c0385d8;
P_0c0385d8: /* original 035e, guest PC 0x0c0385d8 */
if(!s->budget--) { s->failed_pc=0x0c0385d8u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0385da;
P_0c0385da: /* original 6013, guest PC 0x0c0385da */
if(!s->budget--) { s->failed_pc=0x0c0385dau; return 0; }
r[0]=r[1];
goto P_0c0385dc;
P_0c0385dc: /* original 70ff, guest PC 0x0c0385dc */
if(!s->budget--) { s->failed_pc=0x0c0385dcu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0385de;
P_0c0385de: /* original e500, guest PC 0x0c0385de */
if(!s->budget--) { s->failed_pc=0x0c0385deu; return 0; }
r[5]=0x00000000u;
goto P_0c0385e0;
P_0c0385e0: /* original 143b, guest PC 0x0c0385e0 */
if(!s->budget--) { s->failed_pc=0x0c0385e0u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0385e2;
P_0c0385e2: /* original 8143, guest PC 0x0c0385e2 */
if(!s->budget--) { s->failed_pc=0x0c0385e2u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0385e4;
P_0c0385e4: /* original 000b, guest PC 0x0c0385e4 */
if(!s->budget--) { s->failed_pc=0x0c0385e4u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c0385e6: /* original 6053, guest PC 0x0c0385e6 */
if(!s->budget--) { s->failed_pc=0x0c0385e6u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c0385e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0385e8u; return 0; } return 1;
P_0c03b5c0: /* original fbfd, guest PC 0x0c03b5c0 */
if(!s->budget--) { s->failed_pc=0x0c03b5c0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03b5c2;
P_0c03b5c2: /* original f3ed, guest PC 0x0c03b5c2 */
if(!s->budget--) { s->failed_pc=0x0c03b5c2u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03b5c4;
P_0c03b5c4: /* original f7ed, guest PC 0x0c03b5c4 */
if(!s->budget--) { s->failed_pc=0x0c03b5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03b5c6;
P_0c03b5c6: /* original fbed, guest PC 0x0c03b5c6 */
if(!s->budget--) { s->failed_pc=0x0c03b5c6u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03b5c8;
P_0c03b5c8: /* original fc3c, guest PC 0x0c03b5c8 */
if(!s->budget--) { s->failed_pc=0x0c03b5c8u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c03b5ca;
P_0c03b5ca: /* original f331, guest PC 0x0c03b5ca */
if(!s->budget--) { s->failed_pc=0x0c03b5cau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03b5cc;
P_0c03b5cc: /* original fd7c, guest PC 0x0c03b5cc */
if(!s->budget--) { s->failed_pc=0x0c03b5ccu; return 0; }
vf3_matrix_move(s,13,7);
goto P_0c03b5ce;
P_0c03b5ce: /* original f771, guest PC 0x0c03b5ce */
if(!s->budget--) { s->failed_pc=0x0c03b5ceu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03b5d0;
P_0c03b5d0: /* original febc, guest PC 0x0c03b5d0 */
if(!s->budget--) { s->failed_pc=0x0c03b5d0u; return 0; }
vf3_matrix_move(s,14,11);
goto P_0c03b5d2;
P_0c03b5d2: /* original fbb1, guest PC 0x0c03b5d2 */
if(!s->budget--) { s->failed_pc=0x0c03b5d2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03b5d4;
P_0c03b5d4: /* original f0ed, guest PC 0x0c03b5d4 */
if(!s->budget--) { s->failed_pc=0x0c03b5d4u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03b5d6;
P_0c03b5d6: /* original fc4d, guest PC 0x0c03b5d6 */
if(!s->budget--) { s->failed_pc=0x0c03b5d6u; return 0; }
fr[12]^=0x80000000u;
goto P_0c03b5d8;
P_0c03b5d8: /* original f5ed, guest PC 0x0c03b5d8 */
if(!s->budget--) { s->failed_pc=0x0c03b5d8u; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03b5da;
P_0c03b5da: /* original fd4d, guest PC 0x0c03b5da */
if(!s->budget--) { s->failed_pc=0x0c03b5dau; return 0; }
fr[13]^=0x80000000u;
goto P_0c03b5dc;
P_0c03b5dc: /* original faed, guest PC 0x0c03b5dc */
if(!s->budget--) { s->failed_pc=0x0c03b5dcu; return 0; }
if(!vf3_fpu_fipr(fr+8,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03b5de;
P_0c03b5de: /* original fe4d, guest PC 0x0c03b5de */
if(!s->budget--) { s->failed_pc=0x0c03b5deu; return 0; }
fr[14]^=0x80000000u;
goto P_0c03b5e0;
P_0c03b5e0: /* original f37d, guest PC 0x0c03b5e0 */
if(!s->budget--) { s->failed_pc=0x0c03b5e0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c03b5e2;
P_0c03b5e2: /* original f77d, guest PC 0x0c03b5e2 */
if(!s->budget--) { s->failed_pc=0x0c03b5e2u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03b5e4;
P_0c03b5e4: /* original fb7d, guest PC 0x0c03b5e4 */
if(!s->budget--) { s->failed_pc=0x0c03b5e4u; return 0; }
if(!vf3_fpu_fsrra(fr[11],r[18],&fr[11])) goto unsupported;
goto P_0c03b5e6;
P_0c03b5e6: /* original f132, guest PC 0x0c03b5e6 */
if(!s->budget--) { s->failed_pc=0x0c03b5e6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c03b5e8;
P_0c03b5e8: /* original f472, guest PC 0x0c03b5e8 */
if(!s->budget--) { s->failed_pc=0x0c03b5e8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03b5ea;
P_0c03b5ea: /* original f232, guest PC 0x0c03b5ea */
if(!s->budget--) { s->failed_pc=0x0c03b5eau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03b5ec;
P_0c03b5ec: /* original f11d, guest PC 0x0c03b5ec */
if(!s->budget--) { s->failed_pc=0x0c03b5ecu; return 0; }
r[53]=fr[1];
goto P_0c03b5ee;
P_0c03b5ee: /* original f8b2, guest PC 0x0c03b5ee */
if(!s->budget--) { s->failed_pc=0x0c03b5eeu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'*');
goto P_0c03b5f0;
P_0c03b5f0: /* original f14c, guest PC 0x0c03b5f0 */
if(!s->budget--) { s->failed_pc=0x0c03b5f0u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03b5f2;
P_0c03b5f2: /* original f672, guest PC 0x0c03b5f2 */
if(!s->budget--) { s->failed_pc=0x0c03b5f2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03b5f4;
P_0c03b5f4: /* original f40d, guest PC 0x0c03b5f4 */
if(!s->budget--) { s->failed_pc=0x0c03b5f4u; return 0; }
fr[4]=r[53];
goto P_0c03b5f6;
P_0c03b5f6: /* original f9b2, guest PC 0x0c03b5f6 */
if(!s->budget--) { s->failed_pc=0x0c03b5f6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[11],r[18],'*');
goto P_0c03b5f8;
P_0c03b5f8: /* original f21d, guest PC 0x0c03b5f8 */
if(!s->budget--) { s->failed_pc=0x0c03b5f8u; return 0; }
r[53]=fr[2];
goto P_0c03b5fa;
P_0c03b5fa: /* original f032, guest PC 0x0c03b5fa */
if(!s->budget--) { s->failed_pc=0x0c03b5fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c03b5fc;
P_0c03b5fc: /* original f28c, guest PC 0x0c03b5fc */
if(!s->budget--) { s->failed_pc=0x0c03b5fcu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03b5fe;
P_0c03b5fe: /* original f572, guest PC 0x0c03b5fe */
if(!s->budget--) { s->failed_pc=0x0c03b5feu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03b600;
P_0c03b600: /* original f80d, guest PC 0x0c03b600 */
if(!s->budget--) { s->failed_pc=0x0c03b600u; return 0; }
fr[8]=r[53];
goto P_0c03b602;
P_0c03b602: /* original fab2, guest PC 0x0c03b602 */
if(!s->budget--) { s->failed_pc=0x0c03b602u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c03b604;
P_0c03b604: /* original f61d, guest PC 0x0c03b604 */
if(!s->budget--) { s->failed_pc=0x0c03b604u; return 0; }
r[53]=fr[6];
goto P_0c03b606;
P_0c03b606: /* original fc32, guest PC 0x0c03b606 */
if(!s->budget--) { s->failed_pc=0x0c03b606u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'*');
goto P_0c03b608;
P_0c03b608: /* original f69c, guest PC 0x0c03b608 */
if(!s->budget--) { s->failed_pc=0x0c03b608u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03b60a;
P_0c03b60a: /* original fd72, guest PC 0x0c03b60a */
if(!s->budget--) { s->failed_pc=0x0c03b60au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'*');
goto P_0c03b60c;
P_0c03b60c: /* original f90d, guest PC 0x0c03b60c */
if(!s->budget--) { s->failed_pc=0x0c03b60cu; return 0; }
fr[9]=r[53];
goto P_0c03b60e;
P_0c03b60e: /* original feb2, guest PC 0x0c03b60e */
if(!s->budget--) { s->failed_pc=0x0c03b60eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'*');
goto P_0c03b610;
P_0c03b610: /* original f38d, guest PC 0x0c03b610 */
if(!s->budget--) { s->failed_pc=0x0c03b610u; return 0; }
fr[3]=0;
goto P_0c03b612;
P_0c03b612: /* original f771, guest PC 0x0c03b612 */
if(!s->budget--) { s->failed_pc=0x0c03b612u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03b614;
P_0c03b614: /* original fb8d, guest PC 0x0c03b614 */
if(!s->budget--) { s->failed_pc=0x0c03b614u; return 0; }
fr[11]=0;
goto P_0c03b616;
P_0c03b616: /* original fbfd, guest PC 0x0c03b616 */
if(!s->budget--) { s->failed_pc=0x0c03b616u; return 0; }
vf3_matrix_swap(s);
goto P_0c03b618;
P_0c03b618: /* original 000b, guest PC 0x0c03b618 */
if(!s->budget--) { s->failed_pc=0x0c03b618u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03b61a: /* original 0009, guest PC 0x0c03b61a */
if(!s->budget--) { s->failed_pc=0x0c03b61au; return 0; }
if(!vf3_matrix_family(0x0c03b61cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b61cu; return 0; } return 1;
P_0c03c1c0: /* original fffb, guest PC 0x0c03c1c0 */
if(!s->budget--) { s->failed_pc=0x0c03c1c0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03c1c2;
P_0c03c1c2: /* original ffeb, guest PC 0x0c03c1c2 */
if(!s->budget--) { s->failed_pc=0x0c03c1c2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03c1c4;
P_0c03c1c4: /* original ffdb, guest PC 0x0c03c1c4 */
if(!s->budget--) { s->failed_pc=0x0c03c1c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03c1c6;
P_0c03c1c6: /* original ffcb, guest PC 0x0c03c1c6 */
if(!s->budget--) { s->failed_pc=0x0c03c1c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c03c1c8;
P_0c03c1c8: /* original f049, guest PC 0x0c03c1c8 */
if(!s->budget--) { s->failed_pc=0x0c03c1c8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1ca;
P_0c03c1ca: /* original f149, guest PC 0x0c03c1ca */
if(!s->budget--) { s->failed_pc=0x0c03c1cau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1cc;
P_0c03c1cc: /* original f249, guest PC 0x0c03c1cc */
if(!s->budget--) { s->failed_pc=0x0c03c1ccu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1ce;
P_0c03c1ce: /* original f349, guest PC 0x0c03c1ce */
if(!s->budget--) { s->failed_pc=0x0c03c1ceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d0;
P_0c03c1d0: /* original f449, guest PC 0x0c03c1d0 */
if(!s->budget--) { s->failed_pc=0x0c03c1d0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d2;
P_0c03c1d2: /* original f549, guest PC 0x0c03c1d2 */
if(!s->budget--) { s->failed_pc=0x0c03c1d2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d4;
P_0c03c1d4: /* original f649, guest PC 0x0c03c1d4 */
if(!s->budget--) { s->failed_pc=0x0c03c1d4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d6;
P_0c03c1d6: /* original f749, guest PC 0x0c03c1d6 */
if(!s->budget--) { s->failed_pc=0x0c03c1d6u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d8;
P_0c03c1d8: /* original f849, guest PC 0x0c03c1d8 */
if(!s->budget--) { s->failed_pc=0x0c03c1d8u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1da;
P_0c03c1da: /* original f949, guest PC 0x0c03c1da */
if(!s->budget--) { s->failed_pc=0x0c03c1dau; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1dc;
P_0c03c1dc: /* original fa49, guest PC 0x0c03c1dc */
if(!s->budget--) { s->failed_pc=0x0c03c1dcu; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1de;
P_0c03c1de: /* original fb49, guest PC 0x0c03c1de */
if(!s->budget--) { s->failed_pc=0x0c03c1deu; return 0; }
vf3_matrix_load(s,ram,11,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e0;
P_0c03c1e0: /* original fc49, guest PC 0x0c03c1e0 */
if(!s->budget--) { s->failed_pc=0x0c03c1e0u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e2;
P_0c03c1e2: /* original fd49, guest PC 0x0c03c1e2 */
if(!s->budget--) { s->failed_pc=0x0c03c1e2u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e4;
P_0c03c1e4: /* original fe49, guest PC 0x0c03c1e4 */
if(!s->budget--) { s->failed_pc=0x0c03c1e4u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e6;
P_0c03c1e6: /* original ff49, guest PC 0x0c03c1e6 */
if(!s->budget--) { s->failed_pc=0x0c03c1e6u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e8;
P_0c03c1e8: /* original fbfd, guest PC 0x0c03c1e8 */
if(!s->budget--) { s->failed_pc=0x0c03c1e8u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c1ea;
P_0c03c1ea: /* original f1fd, guest PC 0x0c03c1ea */
if(!s->budget--) { s->failed_pc=0x0c03c1eau; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03c1ec;
P_0c03c1ec: /* original f5fd, guest PC 0x0c03c1ec */
if(!s->budget--) { s->failed_pc=0x0c03c1ecu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03c1ee;
P_0c03c1ee: /* original f9fd, guest PC 0x0c03c1ee */
if(!s->budget--) { s->failed_pc=0x0c03c1eeu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03c1f0;
P_0c03c1f0: /* original fdfd, guest PC 0x0c03c1f0 */
if(!s->budget--) { s->failed_pc=0x0c03c1f0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03c1f2;
P_0c03c1f2: /* original fbfd, guest PC 0x0c03c1f2 */
if(!s->budget--) { s->failed_pc=0x0c03c1f2u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c1f4;
P_0c03c1f4: /* original fcf9, guest PC 0x0c03c1f4 */
if(!s->budget--) { s->failed_pc=0x0c03c1f4u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1f6;
P_0c03c1f6: /* original fdf9, guest PC 0x0c03c1f6 */
if(!s->budget--) { s->failed_pc=0x0c03c1f6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1f8;
P_0c03c1f8: /* original fef9, guest PC 0x0c03c1f8 */
if(!s->budget--) { s->failed_pc=0x0c03c1f8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1fa;
P_0c03c1fa: /* original fff9, guest PC 0x0c03c1fa */
if(!s->budget--) { s->failed_pc=0x0c03c1fau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1fc;
P_0c03c1fc: /* original 000b, guest PC 0x0c03c1fc */
if(!s->budget--) { s->failed_pc=0x0c03c1fcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c1fe: /* original 0009, guest PC 0x0c03c1fe */
if(!s->budget--) { s->failed_pc=0x0c03c1feu; return 0; }
goto P_0c03c200;
P_0c03c200: /* original d491, guest PC 0x0c03c200 */
if(!s->budget--) { s->failed_pc=0x0c03c200u; return 0; }
r[4]=read(ram,0x0c03c448u,4);
goto P_0c03c202;
P_0c03c202: /* original d392, guest PC 0x0c03c202 */
if(!s->budget--) { s->failed_pc=0x0c03c202u; return 0; }
r[3]=read(ram,0x0c03c44cu,4);
goto P_0c03c204;
P_0c03c204: /* original 5442, guest PC 0x0c03c204 */
if(!s->budget--) { s->failed_pc=0x0c03c204u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03c206;
P_0c03c206: /* original 432b, guest PC 0x0c03c206 */
if(!s->budget--) { s->failed_pc=0x0c03c206u; return 0; }
target=r[3];
r[4]+=0xffffffc0u;
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
P_0c03c208: /* original 74c0, guest PC 0x0c03c208 */
if(!s->budget--) { s->failed_pc=0x0c03c208u; return 0; }
r[4]+=0xffffffc0u;
if(!vf3_matrix_family(0x0c03c20au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c20au; return 0; } return 1;
P_0c03d260: /* original 4f22, guest PC 0x0c03d260 */
if(!s->budget--) { s->failed_pc=0x0c03d260u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03d262;
P_0c03d262: /* original d347, guest PC 0x0c03d262 */
if(!s->budget--) { s->failed_pc=0x0c03d262u; return 0; }
r[3]=read(ram,0x0c03d380u,4);
goto P_0c03d264;
P_0c03d264: /* original d445, guest PC 0x0c03d264 */
if(!s->budget--) { s->failed_pc=0x0c03d264u; return 0; }
r[4]=read(ram,0x0c03d37cu,4);
goto P_0c03d266;
P_0c03d266: /* original 430b, guest PC 0x0c03d266 */
if(!s->budget--) { s->failed_pc=0x0c03d266u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d26au;
r[4]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d26au) { target=s->pc; goto dispatch; }
goto P_0c03d26a;
P_0c03d268: /* original 5442, guest PC 0x0c03d268 */
if(!s->budget--) { s->failed_pc=0x0c03d268u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03d26a;
P_0c03d26a: /* original d246, guest PC 0x0c03d26a */
if(!s->budget--) { s->failed_pc=0x0c03d26au; return 0; }
r[2]=read(ram,0x0c03d384u,4);
goto P_0c03d26c;
P_0c03d26c: /* original 420b, guest PC 0x0c03d26c */
if(!s->budget--) { s->failed_pc=0x0c03d26cu; return 0; }
target=r[2];
r[16]=code_base|0x0c03d270u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d270u) { target=s->pc; goto dispatch; }
goto P_0c03d270;
P_0c03d26e: /* original 0009, guest PC 0x0c03d26e */
if(!s->budget--) { s->failed_pc=0x0c03d26eu; return 0; }
goto P_0c03d270;
P_0c03d270: /* original d346, guest PC 0x0c03d270 */
if(!s->budget--) { s->failed_pc=0x0c03d270u; return 0; }
r[3]=read(ram,0x0c03d38cu,4);
goto P_0c03d272;
P_0c03d272: /* original d445, guest PC 0x0c03d272 */
if(!s->budget--) { s->failed_pc=0x0c03d272u; return 0; }
r[4]=read(ram,0x0c03d388u,4);
goto P_0c03d274;
P_0c03d274: /* original 430b, guest PC 0x0c03d274 */
if(!s->budget--) { s->failed_pc=0x0c03d274u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d278u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d278u) { target=s->pc; goto dispatch; }
goto P_0c03d278;
P_0c03d276: /* original 0009, guest PC 0x0c03d276 */
if(!s->budget--) { s->failed_pc=0x0c03d276u; return 0; }
goto P_0c03d278;
P_0c03d278: /* original d245, guest PC 0x0c03d278 */
if(!s->budget--) { s->failed_pc=0x0c03d278u; return 0; }
r[2]=read(ram,0x0c03d390u,4);
goto P_0c03d27a;
P_0c03d27a: /* original e401, guest PC 0x0c03d27a */
if(!s->budget--) { s->failed_pc=0x0c03d27au; return 0; }
r[4]=0x00000001u;
goto P_0c03d27c;
P_0c03d27c: /* original 422b, guest PC 0x0c03d27c */
if(!s->budget--) { s->failed_pc=0x0c03d27cu; return 0; }
target=r[2];
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
P_0c03d27e: /* original 4f26, guest PC 0x0c03d27e */
if(!s->budget--) { s->failed_pc=0x0c03d27eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03d280u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d280u; return 0; } return 1;
P_0c03dd00: /* original d407, guest PC 0x0c03dd00 */
if(!s->budget--) { s->failed_pc=0x0c03dd00u; return 0; }
r[4]=read(ram,0x0c03dd20u,4);
goto P_0c03dd02;
P_0c03dd02: /* original d502, guest PC 0x0c03dd02 */
if(!s->budget--) { s->failed_pc=0x0c03dd02u; return 0; }
r[5]=read(ram,0x0c03dd0cu,4);
goto P_0c03dd04;
P_0c03dd04: /* original 5442, guest PC 0x0c03dd04 */
if(!s->budget--) { s->failed_pc=0x0c03dd04u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03dd06;
P_0c03dd06: /* original a013, guest PC 0x0c03dd06 */
if(!s->budget--) { s->failed_pc=0x0c03dd06u; return 0; }
goto P_0c03dd30;
P_0c03dd08: /* original 0009, guest PC 0x0c03dd08 */
if(!s->budget--) { s->failed_pc=0x0c03dd08u; return 0; }
if(!vf3_matrix_family(0x0c03dd0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03dd0au; return 0; } return 1;
P_0c03dd30: /* original fffb, guest PC 0x0c03dd30 */
if(!s->budget--) { s->failed_pc=0x0c03dd30u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03dd32;
P_0c03dd32: /* original ffeb, guest PC 0x0c03dd32 */
if(!s->budget--) { s->failed_pc=0x0c03dd32u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03dd34;
P_0c03dd34: /* original ffdb, guest PC 0x0c03dd34 */
if(!s->budget--) { s->failed_pc=0x0c03dd34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03dd36;
P_0c03dd36: /* original ffcb, guest PC 0x0c03dd36 */
if(!s->budget--) { s->failed_pc=0x0c03dd36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c03dd38;
P_0c03dd38: /* original f3fd, guest PC 0x0c03dd38 */
if(!s->budget--) { s->failed_pc=0x0c03dd38u; return 0; }
r[18]^=0x100000u;
goto P_0c03dd3a;
P_0c03dd3a: /* original f049, guest PC 0x0c03dd3a */
if(!s->budget--) { s->failed_pc=0x0c03dd3au; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd3c;
P_0c03dd3c: /* original f249, guest PC 0x0c03dd3c */
if(!s->budget--) { s->failed_pc=0x0c03dd3cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd3e;
P_0c03dd3e: /* original f449, guest PC 0x0c03dd3e */
if(!s->budget--) { s->failed_pc=0x0c03dd3eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd40;
P_0c03dd40: /* original f649, guest PC 0x0c03dd40 */
if(!s->budget--) { s->failed_pc=0x0c03dd40u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd42;
P_0c03dd42: /* original f849, guest PC 0x0c03dd42 */
if(!s->budget--) { s->failed_pc=0x0c03dd42u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd44;
P_0c03dd44: /* original fa49, guest PC 0x0c03dd44 */
if(!s->budget--) { s->failed_pc=0x0c03dd44u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd46;
P_0c03dd46: /* original fc49, guest PC 0x0c03dd46 */
if(!s->budget--) { s->failed_pc=0x0c03dd46u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd48;
P_0c03dd48: /* original fe49, guest PC 0x0c03dd48 */
if(!s->budget--) { s->failed_pc=0x0c03dd48u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd4a;
P_0c03dd4a: /* original f3fd, guest PC 0x0c03dd4a */
if(!s->budget--) { s->failed_pc=0x0c03dd4au; return 0; }
r[18]^=0x100000u;
goto P_0c03dd4c;
P_0c03dd4c: /* original fbfd, guest PC 0x0c03dd4c */
if(!s->budget--) { s->failed_pc=0x0c03dd4cu; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd4e;
P_0c03dd4e: /* original 6453, guest PC 0x0c03dd4e */
if(!s->budget--) { s->failed_pc=0x0c03dd4eu; return 0; }
r[4]=r[5];
goto P_0c03dd50;
P_0c03dd50: /* original 0483, guest PC 0x0c03dd50 */
if(!s->budget--) { s->failed_pc=0x0c03dd50u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03dd52;
P_0c03dd52: /* original f1fd, guest PC 0x0c03dd52 */
if(!s->budget--) { s->failed_pc=0x0c03dd52u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03dd54;
P_0c03dd54: /* original 7420, guest PC 0x0c03dd54 */
if(!s->budget--) { s->failed_pc=0x0c03dd54u; return 0; }
r[4]+=0x00000020u;
goto P_0c03dd56;
P_0c03dd56: /* original f5fd, guest PC 0x0c03dd56 */
if(!s->budget--) { s->failed_pc=0x0c03dd56u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03dd58;
P_0c03dd58: /* original f9fd, guest PC 0x0c03dd58 */
if(!s->budget--) { s->failed_pc=0x0c03dd58u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03dd5a;
P_0c03dd5a: /* original fdfd, guest PC 0x0c03dd5a */
if(!s->budget--) { s->failed_pc=0x0c03dd5au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03dd5c;
P_0c03dd5c: /* original 0483, guest PC 0x0c03dd5c */
if(!s->budget--) { s->failed_pc=0x0c03dd5cu; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03dd5e;
P_0c03dd5e: /* original fbfd, guest PC 0x0c03dd5e */
if(!s->budget--) { s->failed_pc=0x0c03dd5eu; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd60;
P_0c03dd60: /* original f059, guest PC 0x0c03dd60 */
if(!s->budget--) { s->failed_pc=0x0c03dd60u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd62;
P_0c03dd62: /* original f159, guest PC 0x0c03dd62 */
if(!s->budget--) { s->failed_pc=0x0c03dd62u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd64;
P_0c03dd64: /* original f259, guest PC 0x0c03dd64 */
if(!s->budget--) { s->failed_pc=0x0c03dd64u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd66;
P_0c03dd66: /* original f359, guest PC 0x0c03dd66 */
if(!s->budget--) { s->failed_pc=0x0c03dd66u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd68;
P_0c03dd68: /* original f459, guest PC 0x0c03dd68 */
if(!s->budget--) { s->failed_pc=0x0c03dd68u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6a;
P_0c03dd6a: /* original f559, guest PC 0x0c03dd6a */
if(!s->budget--) { s->failed_pc=0x0c03dd6au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6c;
P_0c03dd6c: /* original f659, guest PC 0x0c03dd6c */
if(!s->budget--) { s->failed_pc=0x0c03dd6cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6e;
P_0c03dd6e: /* original f759, guest PC 0x0c03dd6e */
if(!s->budget--) { s->failed_pc=0x0c03dd6eu; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd70;
P_0c03dd70: /* original f859, guest PC 0x0c03dd70 */
if(!s->budget--) { s->failed_pc=0x0c03dd70u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd72;
P_0c03dd72: /* original f959, guest PC 0x0c03dd72 */
if(!s->budget--) { s->failed_pc=0x0c03dd72u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd74;
P_0c03dd74: /* original fa59, guest PC 0x0c03dd74 */
if(!s->budget--) { s->failed_pc=0x0c03dd74u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd76;
P_0c03dd76: /* original fb59, guest PC 0x0c03dd76 */
if(!s->budget--) { s->failed_pc=0x0c03dd76u; return 0; }
vf3_matrix_load(s,ram,11,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd78;
P_0c03dd78: /* original fc59, guest PC 0x0c03dd78 */
if(!s->budget--) { s->failed_pc=0x0c03dd78u; return 0; }
vf3_matrix_load(s,ram,12,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7a;
P_0c03dd7a: /* original fd59, guest PC 0x0c03dd7a */
if(!s->budget--) { s->failed_pc=0x0c03dd7au; return 0; }
vf3_matrix_load(s,ram,13,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7c;
P_0c03dd7c: /* original fe59, guest PC 0x0c03dd7c */
if(!s->budget--) { s->failed_pc=0x0c03dd7cu; return 0; }
vf3_matrix_load(s,ram,14,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7e;
P_0c03dd7e: /* original ff59, guest PC 0x0c03dd7e */
if(!s->budget--) { s->failed_pc=0x0c03dd7eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd80;
P_0c03dd80: /* original fbfd, guest PC 0x0c03dd80 */
if(!s->budget--) { s->failed_pc=0x0c03dd80u; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd82;
P_0c03dd82: /* original f1fd, guest PC 0x0c03dd82 */
if(!s->budget--) { s->failed_pc=0x0c03dd82u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03dd84;
P_0c03dd84: /* original f5fd, guest PC 0x0c03dd84 */
if(!s->budget--) { s->failed_pc=0x0c03dd84u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03dd86;
P_0c03dd86: /* original f9fd, guest PC 0x0c03dd86 */
if(!s->budget--) { s->failed_pc=0x0c03dd86u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03dd88;
P_0c03dd88: /* original fdfd, guest PC 0x0c03dd88 */
if(!s->budget--) { s->failed_pc=0x0c03dd88u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03dd8a;
P_0c03dd8a: /* original fbfd, guest PC 0x0c03dd8a */
if(!s->budget--) { s->failed_pc=0x0c03dd8au; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd8c;
P_0c03dd8c: /* original fcf9, guest PC 0x0c03dd8c */
if(!s->budget--) { s->failed_pc=0x0c03dd8cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd8e;
P_0c03dd8e: /* original fdf9, guest PC 0x0c03dd8e */
if(!s->budget--) { s->failed_pc=0x0c03dd8eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd90;
P_0c03dd90: /* original fef9, guest PC 0x0c03dd90 */
if(!s->budget--) { s->failed_pc=0x0c03dd90u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd92;
P_0c03dd92: /* original fff9, guest PC 0x0c03dd92 */
if(!s->budget--) { s->failed_pc=0x0c03dd92u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd94;
P_0c03dd94: /* original 000b, guest PC 0x0c03dd94 */
if(!s->budget--) { s->failed_pc=0x0c03dd94u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03dd96: /* original 0009, guest PC 0x0c03dd96 */
if(!s->budget--) { s->failed_pc=0x0c03dd96u; return 0; }
if(!vf3_matrix_family(0x0c03dd98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03dd98u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
