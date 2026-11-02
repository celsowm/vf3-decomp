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
int vf3_away_batch133_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c091afeu: goto P_0c091afe;
case 0x0c091b00u: goto P_0c091b00;
case 0x0c091b02u: goto P_0c091b02;
case 0x0c091b04u: goto P_0c091b04;
case 0x0c091b06u: goto P_0c091b06;
case 0x0c091b08u: goto P_0c091b08;
case 0x0c091b0au: goto P_0c091b0a;
case 0x0c091b0cu: goto P_0c091b0c;
case 0x0c091b0eu: goto P_0c091b0e;
case 0x0c091b10u: goto P_0c091b10;
case 0x0c091b12u: goto P_0c091b12;
case 0x0c091b14u: goto P_0c091b14;
case 0x0c091b16u: goto P_0c091b16;
case 0x0c091b18u: goto P_0c091b18;
case 0x0c091b1au: goto P_0c091b1a;
case 0x0c091b1cu: goto P_0c091b1c;
case 0x0c091b1eu: goto P_0c091b1e;
case 0x0c091b20u: goto P_0c091b20;
case 0x0c091b22u: goto P_0c091b22;
case 0x0c091b24u: goto P_0c091b24;
case 0x0c091b26u: goto P_0c091b26;
case 0x0c091b28u: goto P_0c091b28;
case 0x0c091b2au: goto P_0c091b2a;
case 0x0c091b2cu: goto P_0c091b2c;
case 0x0c091b2eu: goto P_0c091b2e;
case 0x0c091b30u: goto P_0c091b30;
case 0x0c091b32u: goto P_0c091b32;
case 0x0c091b34u: goto P_0c091b34;
case 0x0c091b36u: goto P_0c091b36;
case 0x0c091b38u: goto P_0c091b38;
case 0x0c091b3au: goto P_0c091b3a;
case 0x0c091b3cu: goto P_0c091b3c;
case 0x0c091b3eu: goto P_0c091b3e;
case 0x0c091b40u: goto P_0c091b40;
case 0x0c091b42u: goto P_0c091b42;
case 0x0c091b44u: goto P_0c091b44;
case 0x0c09d408u: goto P_0c09d408;
case 0x0c09d40au: goto P_0c09d40a;
case 0x0c09d40cu: goto P_0c09d40c;
case 0x0c09d40eu: goto P_0c09d40e;
case 0x0c09d410u: goto P_0c09d410;
case 0x0c09d412u: goto P_0c09d412;
case 0x0c09d414u: goto P_0c09d414;
case 0x0c09d416u: goto P_0c09d416;
case 0x0c09d418u: goto P_0c09d418;
case 0x0c09d41au: goto P_0c09d41a;
case 0x0c09d41cu: goto P_0c09d41c;
case 0x0c09d41eu: goto P_0c09d41e;
case 0x0c09d420u: goto P_0c09d420;
case 0x0c09d422u: goto P_0c09d422;
case 0x0c09d424u: goto P_0c09d424;
case 0x0c09d426u: goto P_0c09d426;
case 0x0c09d428u: goto P_0c09d428;
case 0x0c09d42au: goto P_0c09d42a;
case 0x0c09d42cu: goto P_0c09d42c;
case 0x0c09d42eu: goto P_0c09d42e;
case 0x0c09d430u: goto P_0c09d430;
case 0x0c09d432u: goto P_0c09d432;
case 0x0c09d434u: goto P_0c09d434;
case 0x0c09d436u: goto P_0c09d436;
case 0x0c09d438u: goto P_0c09d438;
case 0x0c09d43au: goto P_0c09d43a;
case 0x0c09d43cu: goto P_0c09d43c;
case 0x0c09d43eu: goto P_0c09d43e;
case 0x0c09d440u: goto P_0c09d440;
case 0x0c09d442u: goto P_0c09d442;
case 0x0c09d444u: goto P_0c09d444;
case 0x0c09d446u: goto P_0c09d446;
case 0x0c09d448u: goto P_0c09d448;
case 0x0c09d44au: goto P_0c09d44a;
case 0x0c09d44cu: goto P_0c09d44c;
case 0x0c09d44eu: goto P_0c09d44e;
case 0x0c09d450u: goto P_0c09d450;
case 0x0c09d452u: goto P_0c09d452;
case 0x0c09d454u: goto P_0c09d454;
case 0x0c09d456u: goto P_0c09d456;
case 0x0c09d458u: goto P_0c09d458;
case 0x0c09d45au: goto P_0c09d45a;
case 0x0c09d45cu: goto P_0c09d45c;
case 0x0c09d45eu: goto P_0c09d45e;
case 0x0c09d460u: goto P_0c09d460;
case 0x0c09d462u: goto P_0c09d462;
case 0x0c09d464u: goto P_0c09d464;
case 0x0c09d466u: goto P_0c09d466;
case 0x0c09d468u: goto P_0c09d468;
case 0x0c09d46au: goto P_0c09d46a;
case 0x0c09d46cu: goto P_0c09d46c;
case 0x0c09d46eu: goto P_0c09d46e;
case 0x0c09d470u: goto P_0c09d470;
case 0x0c09d472u: goto P_0c09d472;
case 0x0c09d474u: goto P_0c09d474;
case 0x0c09d476u: goto P_0c09d476;
case 0x0c09d478u: goto P_0c09d478;
case 0x0c09d47au: goto P_0c09d47a;
case 0x0c09d47cu: goto P_0c09d47c;
case 0x0c09d47eu: goto P_0c09d47e;
case 0x0c09d480u: goto P_0c09d480;
case 0x0c09d482u: goto P_0c09d482;
case 0x0c09d484u: goto P_0c09d484;
case 0x0c09d486u: goto P_0c09d486;
case 0x0c09d488u: goto P_0c09d488;
case 0x0c09d48au: goto P_0c09d48a;
case 0x0c09d48cu: goto P_0c09d48c;
case 0x0c09d48eu: goto P_0c09d48e;
case 0x0c09d490u: goto P_0c09d490;
case 0x0c09d492u: goto P_0c09d492;
case 0x0c09d494u: goto P_0c09d494;
case 0x0c09d496u: goto P_0c09d496;
case 0x0c09d498u: goto P_0c09d498;
case 0x0c09d49au: goto P_0c09d49a;
case 0x0c09d49cu: goto P_0c09d49c;
case 0x0c09d49eu: goto P_0c09d49e;
case 0x0c09d4a0u: goto P_0c09d4a0;
case 0x0c09d4a2u: goto P_0c09d4a2;
case 0x0c09d4a4u: goto P_0c09d4a4;
case 0x0c09d4a6u: goto P_0c09d4a6;
case 0x0c09d4a8u: goto P_0c09d4a8;
case 0x0c09d4aau: goto P_0c09d4aa;
case 0x0c09d4acu: goto P_0c09d4ac;
case 0x0c09d4aeu: goto P_0c09d4ae;
case 0x0c09d4b0u: goto P_0c09d4b0;
case 0x0c09d4b2u: goto P_0c09d4b2;
case 0x0c09d4b4u: goto P_0c09d4b4;
case 0x0c09d4b6u: goto P_0c09d4b6;
case 0x0c09d4b8u: goto P_0c09d4b8;
case 0x0c09d4bau: goto P_0c09d4ba;
case 0x0c09d4bcu: goto P_0c09d4bc;
case 0x0c09d4beu: goto P_0c09d4be;
case 0x0c09d4c0u: goto P_0c09d4c0;
case 0x0c09d4c2u: goto P_0c09d4c2;
case 0x0c09d4c4u: goto P_0c09d4c4;
case 0x0c09d4c6u: goto P_0c09d4c6;
case 0x0c09d4c8u: goto P_0c09d4c8;
case 0x0c09d4cau: goto P_0c09d4ca;
case 0x0c09d4ccu: goto P_0c09d4cc;
case 0x0c09d4ceu: goto P_0c09d4ce;
case 0x0c09d4d0u: goto P_0c09d4d0;
case 0x0c09d4d2u: goto P_0c09d4d2;
case 0x0c09d4d4u: goto P_0c09d4d4;
case 0x0c09d4d6u: goto P_0c09d4d6;
case 0x0c09d4d8u: goto P_0c09d4d8;
case 0x0c09d4dau: goto P_0c09d4da;
case 0x0c09d4dcu: goto P_0c09d4dc;
case 0x0c09d4deu: goto P_0c09d4de;
case 0x0c09d4e0u: goto P_0c09d4e0;
case 0x0c09d4e2u: goto P_0c09d4e2;
case 0x0c09d4e4u: goto P_0c09d4e4;
case 0x0c09d4e6u: goto P_0c09d4e6;
case 0x0c09d4e8u: goto P_0c09d4e8;
case 0x0c09d4eau: goto P_0c09d4ea;
case 0x0c09d4ecu: goto P_0c09d4ec;
case 0x0c09d4eeu: goto P_0c09d4ee;
case 0x0c09d4f0u: goto P_0c09d4f0;
case 0x0c09d4f2u: goto P_0c09d4f2;
case 0x0c09d4f4u: goto P_0c09d4f4;
case 0x0c09d4f6u: goto P_0c09d4f6;
case 0x0c09d4f8u: goto P_0c09d4f8;
case 0x0c09d4fau: goto P_0c09d4fa;
case 0x0c09d4fcu: goto P_0c09d4fc;
case 0x0c09d4feu: goto P_0c09d4fe;
case 0x0c09d500u: goto P_0c09d500;
case 0x0c09d502u: goto P_0c09d502;
case 0x0c09d504u: goto P_0c09d504;
case 0x0c09d506u: goto P_0c09d506;
case 0x0c09d508u: goto P_0c09d508;
case 0x0c09d50au: goto P_0c09d50a;
case 0x0c09d50cu: goto P_0c09d50c;
case 0x0c09d50eu: goto P_0c09d50e;
case 0x0c09d510u: goto P_0c09d510;
case 0x0c09d512u: goto P_0c09d512;
case 0x0c09d514u: goto P_0c09d514;
case 0x0c09d516u: goto P_0c09d516;
case 0x0c09d518u: goto P_0c09d518;
case 0x0c09d51au: goto P_0c09d51a;
case 0x0c09d51cu: goto P_0c09d51c;
case 0x0c09d51eu: goto P_0c09d51e;
case 0x0c09d520u: goto P_0c09d520;
case 0x0c09d522u: goto P_0c09d522;
case 0x0c09d524u: goto P_0c09d524;
case 0x0c09d526u: goto P_0c09d526;
case 0x0c09d528u: goto P_0c09d528;
case 0x0c09d52au: goto P_0c09d52a;
case 0x0c09d52cu: goto P_0c09d52c;
case 0x0c09d52eu: goto P_0c09d52e;
case 0x0c09d530u: goto P_0c09d530;
case 0x0c09d532u: goto P_0c09d532;
case 0x0c09d534u: goto P_0c09d534;
case 0x0c09d536u: goto P_0c09d536;
case 0x0c09d538u: goto P_0c09d538;
case 0x0c09d53au: goto P_0c09d53a;
case 0x0c09d53cu: goto P_0c09d53c;
case 0x0c09d53eu: goto P_0c09d53e;
case 0x0c09d540u: goto P_0c09d540;
case 0x0c09d542u: goto P_0c09d542;
case 0x0c09d544u: goto P_0c09d544;
case 0x0c09d546u: goto P_0c09d546;
case 0x0c09d548u: goto P_0c09d548;
case 0x0c09d54au: goto P_0c09d54a;
case 0x0c09d54cu: goto P_0c09d54c;
case 0x0c09d54eu: goto P_0c09d54e;
case 0x0c09d550u: goto P_0c09d550;
case 0x0c09d552u: goto P_0c09d552;
default: return vf3_matrix_family(target,s,ram);
}
P_0c091afe: /* original d313, guest PC 0x0c091afe */
if(!s->budget--) { s->failed_pc=0x0c091afeu; return 0; }
r[3]=read(ram,0x0c091b4cu,4);
goto P_0c091b00;
P_0c091b00: /* original 7ff4, guest PC 0x0c091b00 */
if(!s->budget--) { s->failed_pc=0x0c091b00u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c091b02;
P_0c091b02: /* original d513, guest PC 0x0c091b02 */
if(!s->budget--) { s->failed_pc=0x0c091b02u; return 0; }
r[5]=read(ram,0x0c091b50u,4);
goto P_0c091b04;
P_0c091b04: /* original e201, guest PC 0x0c091b04 */
if(!s->budget--) { s->failed_pc=0x0c091b04u; return 0; }
r[2]=0x00000001u;
goto P_0c091b06;
P_0c091b06: /* original 6632, guest PC 0x0c091b06 */
if(!s->budget--) { s->failed_pc=0x0c091b06u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c091b08;
P_0c091b08: /* original 1f21, guest PC 0x0c091b08 */
if(!s->budget--) { s->failed_pc=0x0c091b08u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c091b0a;
P_0c091b0a: /* original 7614, guest PC 0x0c091b0a */
if(!s->budget--) { s->failed_pc=0x0c091b0au; return 0; }
r[6]+=0x00000014u;
goto P_0c091b0c;
P_0c091b0c: /* original 6152, guest PC 0x0c091b0c */
if(!s->budget--) { s->failed_pc=0x0c091b0cu; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c091b0e;
P_0c091b0e: /* original 1f12, guest PC 0x0c091b0e */
if(!s->budget--) { s->failed_pc=0x0c091b0eu; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c091b10;
P_0c091b10: /* original 6462, guest PC 0x0c091b10 */
if(!s->budget--) { s->failed_pc=0x0c091b10u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c091b12;
P_0c091b12: /* original 2448, guest PC 0x0c091b12 */
if(!s->budget--) { s->failed_pc=0x0c091b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c091b14;
P_0c091b14: /* original 8d15, guest PC 0x0c091b14 */
if(!s->budget--) { s->failed_pc=0x0c091b14u; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c091b42; }
goto P_0c091b18;
P_0c091b16: /* original e700, guest PC 0x0c091b16 */
if(!s->budget--) { s->failed_pc=0x0c091b16u; return 0; }
r[7]=0x00000000u;
goto P_0c091b18;
P_0c091b18: /* original 6543, guest PC 0x0c091b18 */
if(!s->budget--) { s->failed_pc=0x0c091b18u; return 0; }
r[5]=r[4];
goto P_0c091b1a;
P_0c091b1a: /* original 6363, guest PC 0x0c091b1a */
if(!s->budget--) { s->failed_pc=0x0c091b1au; return 0; }
r[3]=r[6];
goto P_0c091b1c;
P_0c091b1c: /* original 6473, guest PC 0x0c091b1c */
if(!s->budget--) { s->failed_pc=0x0c091b1cu; return 0; }
r[4]=r[7];
goto P_0c091b1e;
P_0c091b1e: /* original 7304, guest PC 0x0c091b1e */
if(!s->budget--) { s->failed_pc=0x0c091b1eu; return 0; }
r[3]+=0x00000004u;
goto P_0c091b20;
P_0c091b20: /* original 4408, guest PC 0x0c091b20 */
if(!s->budget--) { s->failed_pc=0x0c091b20u; return 0; }
r[4]<<=2;
goto P_0c091b22;
P_0c091b22: /* original 343c, guest PC 0x0c091b22 */
if(!s->budget--) { s->failed_pc=0x0c091b22u; return 0; }
r[4]+=r[3];
goto P_0c091b24;
P_0c091b24: /* original 6442, guest PC 0x0c091b24 */
if(!s->budget--) { s->failed_pc=0x0c091b24u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c091b26;
P_0c091b26: /* original 5248, guest PC 0x0c091b26 */
if(!s->budget--) { s->failed_pc=0x0c091b26u; return 0; }
r[2]=read(ram,r[4]+32,4);
goto P_0c091b28;
P_0c091b28: /* original 6323, guest PC 0x0c091b28 */
if(!s->budget--) { s->failed_pc=0x0c091b28u; return 0; }
r[3]=r[2];
goto P_0c091b2a;
P_0c091b2a: /* original 2f22, guest PC 0x0c091b2a */
if(!s->budget--) { s->failed_pc=0x0c091b2au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c091b2c;
P_0c091b2c: /* original 51f2, guest PC 0x0c091b2c */
if(!s->budget--) { s->failed_pc=0x0c091b2cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c091b2e;
P_0c091b2e: /* original 3138, guest PC 0x0c091b2e */
if(!s->budget--) { s->failed_pc=0x0c091b2eu; return 0; }
r[1]-=r[3];
goto P_0c091b30;
P_0c091b30: /* original 2f12, guest PC 0x0c091b30 */
if(!s->budget--) { s->failed_pc=0x0c091b30u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c091b32;
P_0c091b32: /* original 9208, guest PC 0x0c091b32 */
if(!s->budget--) { s->failed_pc=0x0c091b32u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091b46u,2);
goto P_0c091b34;
P_0c091b34: /* original 3126, guest PC 0x0c091b34 */
if(!s->budget--) { s->failed_pc=0x0c091b34u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c091b36;
P_0c091b36: /* original 8d02, guest PC 0x0c091b36 */
if(!s->budget--) { s->failed_pc=0x0c091b36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(cond) { goto P_0c091b3e; }
goto P_0c091b3a;
P_0c091b38: /* original 7701, guest PC 0x0c091b38 */
if(!s->budget--) { s->failed_pc=0x0c091b38u; return 0; }
r[7]+=0x00000001u;
goto P_0c091b3a;
P_0c091b3a: /* original 53f1, guest PC 0x0c091b3a */
if(!s->budget--) { s->failed_pc=0x0c091b3au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c091b3c;
P_0c091b3c: /* original 2432, guest PC 0x0c091b3c */
if(!s->budget--) { s->failed_pc=0x0c091b3cu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c091b3e;
P_0c091b3e: /* original 4510, guest PC 0x0c091b3e */
if(!s->budget--) { s->failed_pc=0x0c091b3eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c091b40;
P_0c091b40: /* original 8beb, guest PC 0x0c091b40 */
if(!s->budget--) { s->failed_pc=0x0c091b40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091b1a; }
goto P_0c091b42;
P_0c091b42: /* original 000b, guest PC 0x0c091b42 */
if(!s->budget--) { s->failed_pc=0x0c091b42u; return 0; }
target=r[16];
r[15]+=0x0000000cu;
s->pc=target; return ram->oob==0;
P_0c091b44: /* original 7f0c, guest PC 0x0c091b44 */
if(!s->budget--) { s->failed_pc=0x0c091b44u; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c091b46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091b46u; return 0; } return 1;
P_0c09d408: /* original e507, guest PC 0x0c09d408 */
if(!s->budget--) { s->failed_pc=0x0c09d408u; return 0; }
r[5]=0x00000007u;
goto P_0c09d40a;
P_0c09d40a: /* original 7408, guest PC 0x0c09d40a */
if(!s->budget--) { s->failed_pc=0x0c09d40au; return 0; }
r[4]+=0x00000008u;
goto P_0c09d40c;
P_0c09d40c: /* original f348, guest PC 0x0c09d40c */
if(!s->budget--) { s->failed_pc=0x0c09d40cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09d40e;
P_0c09d40e: /* original 4510, guest PC 0x0c09d40e */
if(!s->budget--) { s->failed_pc=0x0c09d40eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09d410;
P_0c09d410: /* original f34d, guest PC 0x0c09d410 */
if(!s->budget--) { s->failed_pc=0x0c09d410u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09d412;
P_0c09d412: /* original f43a, guest PC 0x0c09d412 */
if(!s->budget--) { s->failed_pc=0x0c09d412u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09d414;
P_0c09d414: /* original 8ffa, guest PC 0x0c09d414 */
if(!s->budget--) { s->failed_pc=0x0c09d414u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09d40c; }
goto P_0c09d418;
P_0c09d416: /* original 740c, guest PC 0x0c09d416 */
if(!s->budget--) { s->failed_pc=0x0c09d416u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09d418;
P_0c09d418: /* original e50e, guest PC 0x0c09d418 */
if(!s->budget--) { s->failed_pc=0x0c09d418u; return 0; }
r[5]=0x0000000eu;
goto P_0c09d41a;
P_0c09d41a: /* original 74f8, guest PC 0x0c09d41a */
if(!s->budget--) { s->failed_pc=0x0c09d41au; return 0; }
r[4]+=0xfffffff8u;
goto P_0c09d41c;
P_0c09d41c: /* original f348, guest PC 0x0c09d41c */
if(!s->budget--) { s->failed_pc=0x0c09d41cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09d41e;
P_0c09d41e: /* original 4510, guest PC 0x0c09d41e */
if(!s->budget--) { s->failed_pc=0x0c09d41eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09d420;
P_0c09d420: /* original f34d, guest PC 0x0c09d420 */
if(!s->budget--) { s->failed_pc=0x0c09d420u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09d422;
P_0c09d422: /* original f43a, guest PC 0x0c09d422 */
if(!s->budget--) { s->failed_pc=0x0c09d422u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09d424;
P_0c09d424: /* original 8ffa, guest PC 0x0c09d424 */
if(!s->budget--) { s->failed_pc=0x0c09d424u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09d41c; }
goto P_0c09d428;
P_0c09d426: /* original 740c, guest PC 0x0c09d426 */
if(!s->budget--) { s->failed_pc=0x0c09d426u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09d428;
P_0c09d428: /* original 000b, guest PC 0x0c09d428 */
if(!s->budget--) { s->failed_pc=0x0c09d428u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d42a: /* original 0009, guest PC 0x0c09d42a */
if(!s->budget--) { s->failed_pc=0x0c09d42au; return 0; }
goto P_0c09d42c;
P_0c09d42c: /* original 4f22, guest PC 0x0c09d42c */
if(!s->budget--) { s->failed_pc=0x0c09d42cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d42e;
P_0c09d42e: /* original e004, guest PC 0x0c09d42e */
if(!s->budget--) { s->failed_pc=0x0c09d42eu; return 0; }
r[0]=0x00000004u;
goto P_0c09d430;
P_0c09d430: /* original 7ff0, guest PC 0x0c09d430 */
if(!s->budget--) { s->failed_pc=0x0c09d430u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d432;
P_0c09d432: /* original 2f42, guest PC 0x0c09d432 */
if(!s->budget--) { s->failed_pc=0x0c09d432u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d434;
P_0c09d434: /* original 64f3, guest PC 0x0c09d434 */
if(!s->budget--) { s->failed_pc=0x0c09d434u; return 0; }
r[4]=r[15];
goto P_0c09d436;
P_0c09d436: /* original ff47, guest PC 0x0c09d436 */
if(!s->budget--) { s->failed_pc=0x0c09d436u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d438;
P_0c09d438: /* original e008, guest PC 0x0c09d438 */
if(!s->budget--) { s->failed_pc=0x0c09d438u; return 0; }
r[0]=0x00000008u;
goto P_0c09d43a;
P_0c09d43a: /* original f38d, guest PC 0x0c09d43a */
if(!s->budget--) { s->failed_pc=0x0c09d43au; return 0; }
fr[3]=0;
goto P_0c09d43c;
P_0c09d43c: /* original ff37, guest PC 0x0c09d43c */
if(!s->budget--) { s->failed_pc=0x0c09d43cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09d43e;
P_0c09d43e: /* original e00c, guest PC 0x0c09d43e */
if(!s->budget--) { s->failed_pc=0x0c09d43eu; return 0; }
r[0]=0x0000000cu;
goto P_0c09d440;
P_0c09d440: /* original ff57, guest PC 0x0c09d440 */
if(!s->budget--) { s->failed_pc=0x0c09d440u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d442;
P_0c09d442: /* original d34e, guest PC 0x0c09d442 */
if(!s->budget--) { s->failed_pc=0x0c09d442u; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d444;
P_0c09d444: /* original 65f2, guest PC 0x0c09d444 */
if(!s->budget--) { s->failed_pc=0x0c09d444u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d446;
P_0c09d446: /* original 430b, guest PC 0x0c09d446 */
if(!s->budget--) { s->failed_pc=0x0c09d446u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d44au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d44au) { target=s->pc; goto dispatch; }
goto P_0c09d44a;
P_0c09d448: /* original 7404, guest PC 0x0c09d448 */
if(!s->budget--) { s->failed_pc=0x0c09d448u; return 0; }
r[4]+=0x00000004u;
goto P_0c09d44a;
P_0c09d44a: /* original 7f10, guest PC 0x0c09d44a */
if(!s->budget--) { s->failed_pc=0x0c09d44au; return 0; }
r[15]+=0x00000010u;
goto P_0c09d44c;
P_0c09d44c: /* original 4f26, guest PC 0x0c09d44c */
if(!s->budget--) { s->failed_pc=0x0c09d44cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d44e;
P_0c09d44e: /* original 000b, guest PC 0x0c09d44e */
if(!s->budget--) { s->failed_pc=0x0c09d44eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d450: /* original 0009, guest PC 0x0c09d450 */
if(!s->budget--) { s->failed_pc=0x0c09d450u; return 0; }
goto P_0c09d452;
P_0c09d452: /* original 4f22, guest PC 0x0c09d452 */
if(!s->budget--) { s->failed_pc=0x0c09d452u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d454;
P_0c09d454: /* original 6053, guest PC 0x0c09d454 */
if(!s->budget--) { s->failed_pc=0x0c09d454u; return 0; }
r[0]=r[5];
goto P_0c09d456;
P_0c09d456: /* original 7ff4, guest PC 0x0c09d456 */
if(!s->budget--) { s->failed_pc=0x0c09d456u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d458;
P_0c09d458: /* original 2f41, guest PC 0x0c09d458 */
if(!s->budget--) { s->failed_pc=0x0c09d458u; return 0; }
write(ram,r[15],r[4],2);
goto P_0c09d45a;
P_0c09d45a: /* original 81f2, guest PC 0x0c09d45a */
if(!s->budget--) { s->failed_pc=0x0c09d45au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d45c;
P_0c09d45c: /* original 6063, guest PC 0x0c09d45c */
if(!s->budget--) { s->failed_pc=0x0c09d45cu; return 0; }
r[0]=r[6];
goto P_0c09d45e;
P_0c09d45e: /* original 81f4, guest PC 0x0c09d45e */
if(!s->budget--) { s->failed_pc=0x0c09d45eu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d460;
P_0c09d460: /* original 85f4, guest PC 0x0c09d460 */
if(!s->budget--) { s->failed_pc=0x0c09d460u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d462;
P_0c09d462: /* original d347, guest PC 0x0c09d462 */
if(!s->budget--) { s->failed_pc=0x0c09d462u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d464;
P_0c09d464: /* original 6403, guest PC 0x0c09d464 */
if(!s->budget--) { s->failed_pc=0x0c09d464u; return 0; }
r[4]=r[0];
goto P_0c09d466;
P_0c09d466: /* original 430b, guest PC 0x0c09d466 */
if(!s->budget--) { s->failed_pc=0x0c09d466u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d46au;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d46au) { target=s->pc; goto dispatch; }
goto P_0c09d46a;
P_0c09d468: /* original 644d, guest PC 0x0c09d468 */
if(!s->budget--) { s->failed_pc=0x0c09d468u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d46a;
P_0c09d46a: /* original 85f2, guest PC 0x0c09d46a */
if(!s->budget--) { s->failed_pc=0x0c09d46au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d46c;
P_0c09d46c: /* original d345, guest PC 0x0c09d46c */
if(!s->budget--) { s->failed_pc=0x0c09d46cu; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d46e;
P_0c09d46e: /* original 6403, guest PC 0x0c09d46e */
if(!s->budget--) { s->failed_pc=0x0c09d46eu; return 0; }
r[4]=r[0];
goto P_0c09d470;
P_0c09d470: /* original 430b, guest PC 0x0c09d470 */
if(!s->budget--) { s->failed_pc=0x0c09d470u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d474u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d474u) { target=s->pc; goto dispatch; }
goto P_0c09d474;
P_0c09d472: /* original 644d, guest PC 0x0c09d472 */
if(!s->budget--) { s->failed_pc=0x0c09d472u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d474;
P_0c09d474: /* original 64f1, guest PC 0x0c09d474 */
if(!s->budget--) { s->failed_pc=0x0c09d474u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d476;
P_0c09d476: /* original 7f0c, guest PC 0x0c09d476 */
if(!s->budget--) { s->failed_pc=0x0c09d476u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d478;
P_0c09d478: /* original d343, guest PC 0x0c09d478 */
if(!s->budget--) { s->failed_pc=0x0c09d478u; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d47a;
P_0c09d47a: /* original 644d, guest PC 0x0c09d47a */
if(!s->budget--) { s->failed_pc=0x0c09d47au; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d47c;
P_0c09d47c: /* original 432b, guest PC 0x0c09d47c */
if(!s->budget--) { s->failed_pc=0x0c09d47cu; return 0; }
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
P_0c09d47e: /* original 4f26, guest PC 0x0c09d47e */
if(!s->budget--) { s->failed_pc=0x0c09d47eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d480;
P_0c09d480: /* original 4f22, guest PC 0x0c09d480 */
if(!s->budget--) { s->failed_pc=0x0c09d480u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d482;
P_0c09d482: /* original 6041, guest PC 0x0c09d482 */
if(!s->budget--) { s->failed_pc=0x0c09d482u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c09d484;
P_0c09d484: /* original 7ff4, guest PC 0x0c09d484 */
if(!s->budget--) { s->failed_pc=0x0c09d484u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d486;
P_0c09d486: /* original 81f4, guest PC 0x0c09d486 */
if(!s->budget--) { s->failed_pc=0x0c09d486u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d488;
P_0c09d488: /* original 8541, guest PC 0x0c09d488 */
if(!s->budget--) { s->failed_pc=0x0c09d488u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09d48a;
P_0c09d48a: /* original 81f2, guest PC 0x0c09d48a */
if(!s->budget--) { s->failed_pc=0x0c09d48au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d48c;
P_0c09d48c: /* original 8542, guest PC 0x0c09d48c */
if(!s->budget--) { s->failed_pc=0x0c09d48cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c09d48e;
P_0c09d48e: /* original 2f01, guest PC 0x0c09d48e */
if(!s->budget--) { s->failed_pc=0x0c09d48eu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c09d490;
P_0c09d490: /* original 85f4, guest PC 0x0c09d490 */
if(!s->budget--) { s->failed_pc=0x0c09d490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d492;
P_0c09d492: /* original d33b, guest PC 0x0c09d492 */
if(!s->budget--) { s->failed_pc=0x0c09d492u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d494;
P_0c09d494: /* original 6403, guest PC 0x0c09d494 */
if(!s->budget--) { s->failed_pc=0x0c09d494u; return 0; }
r[4]=r[0];
goto P_0c09d496;
P_0c09d496: /* original 430b, guest PC 0x0c09d496 */
if(!s->budget--) { s->failed_pc=0x0c09d496u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d49au;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d49au) { target=s->pc; goto dispatch; }
goto P_0c09d49a;
P_0c09d498: /* original 644d, guest PC 0x0c09d498 */
if(!s->budget--) { s->failed_pc=0x0c09d498u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d49a;
P_0c09d49a: /* original 85f2, guest PC 0x0c09d49a */
if(!s->budget--) { s->failed_pc=0x0c09d49au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d49c;
P_0c09d49c: /* original d339, guest PC 0x0c09d49c */
if(!s->budget--) { s->failed_pc=0x0c09d49cu; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d49e;
P_0c09d49e: /* original 6403, guest PC 0x0c09d49e */
if(!s->budget--) { s->failed_pc=0x0c09d49eu; return 0; }
r[4]=r[0];
goto P_0c09d4a0;
P_0c09d4a0: /* original 430b, guest PC 0x0c09d4a0 */
if(!s->budget--) { s->failed_pc=0x0c09d4a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4a4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4a4u) { target=s->pc; goto dispatch; }
goto P_0c09d4a4;
P_0c09d4a2: /* original 644d, guest PC 0x0c09d4a2 */
if(!s->budget--) { s->failed_pc=0x0c09d4a2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4a4;
P_0c09d4a4: /* original 64f1, guest PC 0x0c09d4a4 */
if(!s->budget--) { s->failed_pc=0x0c09d4a4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d4a6;
P_0c09d4a6: /* original 7f0c, guest PC 0x0c09d4a6 */
if(!s->budget--) { s->failed_pc=0x0c09d4a6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d4a8;
P_0c09d4a8: /* original d337, guest PC 0x0c09d4a8 */
if(!s->budget--) { s->failed_pc=0x0c09d4a8u; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d4aa;
P_0c09d4aa: /* original 644d, guest PC 0x0c09d4aa */
if(!s->budget--) { s->failed_pc=0x0c09d4aau; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4ac;
P_0c09d4ac: /* original 432b, guest PC 0x0c09d4ac */
if(!s->budget--) { s->failed_pc=0x0c09d4acu; return 0; }
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
P_0c09d4ae: /* original 4f26, guest PC 0x0c09d4ae */
if(!s->budget--) { s->failed_pc=0x0c09d4aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d4b0;
P_0c09d4b0: /* original 4f22, guest PC 0x0c09d4b0 */
if(!s->budget--) { s->failed_pc=0x0c09d4b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d4b2;
P_0c09d4b2: /* original 7ff0, guest PC 0x0c09d4b2 */
if(!s->budget--) { s->failed_pc=0x0c09d4b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d4b4;
P_0c09d4b4: /* original 2f51, guest PC 0x0c09d4b4 */
if(!s->budget--) { s->failed_pc=0x0c09d4b4u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c09d4b6;
P_0c09d4b6: /* original 6041, guest PC 0x0c09d4b6 */
if(!s->budget--) { s->failed_pc=0x0c09d4b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c09d4b8;
P_0c09d4b8: /* original 81f4, guest PC 0x0c09d4b8 */
if(!s->budget--) { s->failed_pc=0x0c09d4b8u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d4ba;
P_0c09d4ba: /* original 8541, guest PC 0x0c09d4ba */
if(!s->budget--) { s->failed_pc=0x0c09d4bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09d4bc;
P_0c09d4bc: /* original 81f2, guest PC 0x0c09d4bc */
if(!s->budget--) { s->failed_pc=0x0c09d4bcu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d4be;
P_0c09d4be: /* original 8542, guest PC 0x0c09d4be */
if(!s->budget--) { s->failed_pc=0x0c09d4beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c09d4c0;
P_0c09d4c0: /* original 81f6, guest PC 0x0c09d4c0 */
if(!s->budget--) { s->failed_pc=0x0c09d4c0u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c09d4c2;
P_0c09d4c2: /* original 85f4, guest PC 0x0c09d4c2 */
if(!s->budget--) { s->failed_pc=0x0c09d4c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d4c4;
P_0c09d4c4: /* original d32e, guest PC 0x0c09d4c4 */
if(!s->budget--) { s->failed_pc=0x0c09d4c4u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d4c6;
P_0c09d4c6: /* original 6403, guest PC 0x0c09d4c6 */
if(!s->budget--) { s->failed_pc=0x0c09d4c6u; return 0; }
r[4]=r[0];
goto P_0c09d4c8;
P_0c09d4c8: /* original 430b, guest PC 0x0c09d4c8 */
if(!s->budget--) { s->failed_pc=0x0c09d4c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4ccu;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4ccu) { target=s->pc; goto dispatch; }
goto P_0c09d4cc;
P_0c09d4ca: /* original 644d, guest PC 0x0c09d4ca */
if(!s->budget--) { s->failed_pc=0x0c09d4cau; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4cc;
P_0c09d4cc: /* original 85f2, guest PC 0x0c09d4cc */
if(!s->budget--) { s->failed_pc=0x0c09d4ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d4ce;
P_0c09d4ce: /* original 64f1, guest PC 0x0c09d4ce */
if(!s->budget--) { s->failed_pc=0x0c09d4ceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d4d0;
P_0c09d4d0: /* original d32c, guest PC 0x0c09d4d0 */
if(!s->budget--) { s->failed_pc=0x0c09d4d0u; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d4d2;
P_0c09d4d2: /* original 600d, guest PC 0x0c09d4d2 */
if(!s->budget--) { s->failed_pc=0x0c09d4d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c09d4d4;
P_0c09d4d4: /* original 430b, guest PC 0x0c09d4d4 */
if(!s->budget--) { s->failed_pc=0x0c09d4d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4d8u;
r[4]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4d8u) { target=s->pc; goto dispatch; }
goto P_0c09d4d8;
P_0c09d4d6: /* original 340c, guest PC 0x0c09d4d6 */
if(!s->budget--) { s->failed_pc=0x0c09d4d6u; return 0; }
r[4]+=r[0];
goto P_0c09d4d8;
P_0c09d4d8: /* original 85f6, guest PC 0x0c09d4d8 */
if(!s->budget--) { s->failed_pc=0x0c09d4d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c09d4da;
P_0c09d4da: /* original 7f10, guest PC 0x0c09d4da */
if(!s->budget--) { s->failed_pc=0x0c09d4dau; return 0; }
r[15]+=0x00000010u;
goto P_0c09d4dc;
P_0c09d4dc: /* original d32a, guest PC 0x0c09d4dc */
if(!s->budget--) { s->failed_pc=0x0c09d4dcu; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d4de;
P_0c09d4de: /* original 6403, guest PC 0x0c09d4de */
if(!s->budget--) { s->failed_pc=0x0c09d4deu; return 0; }
r[4]=r[0];
goto P_0c09d4e0;
P_0c09d4e0: /* original 644d, guest PC 0x0c09d4e0 */
if(!s->budget--) { s->failed_pc=0x0c09d4e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4e2;
P_0c09d4e2: /* original 432b, guest PC 0x0c09d4e2 */
if(!s->budget--) { s->failed_pc=0x0c09d4e2u; return 0; }
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
P_0c09d4e4: /* original 4f26, guest PC 0x0c09d4e4 */
if(!s->budget--) { s->failed_pc=0x0c09d4e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d4e6;
P_0c09d4e6: /* original 2fe6, guest PC 0x0c09d4e6 */
if(!s->budget--) { s->failed_pc=0x0c09d4e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d4e8;
P_0c09d4e8: /* original e030, guest PC 0x0c09d4e8 */
if(!s->budget--) { s->failed_pc=0x0c09d4e8u; return 0; }
r[0]=0x00000030u;
goto P_0c09d4ea;
P_0c09d4ea: /* original 2fd6, guest PC 0x0c09d4ea */
if(!s->budget--) { s->failed_pc=0x0c09d4eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d4ec;
P_0c09d4ec: /* original 6e43, guest PC 0x0c09d4ec */
if(!s->budget--) { s->failed_pc=0x0c09d4ecu; return 0; }
r[14]=r[4];
goto P_0c09d4ee;
P_0c09d4ee: /* original 4f22, guest PC 0x0c09d4ee */
if(!s->budget--) { s->failed_pc=0x0c09d4eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d4f0;
P_0c09d4f0: /* original f3e6, guest PC 0x0c09d4f0 */
if(!s->budget--) { s->failed_pc=0x0c09d4f0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d4f2;
P_0c09d4f2: /* original e034, guest PC 0x0c09d4f2 */
if(!s->budget--) { s->failed_pc=0x0c09d4f2u; return 0; }
r[0]=0x00000034u;
goto P_0c09d4f4;
P_0c09d4f4: /* original 7ff4, guest PC 0x0c09d4f4 */
if(!s->budget--) { s->failed_pc=0x0c09d4f4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d4f6;
P_0c09d4f6: /* original 6df3, guest PC 0x0c09d4f6 */
if(!s->budget--) { s->failed_pc=0x0c09d4f6u; return 0; }
r[13]=r[15];
goto P_0c09d4f8;
P_0c09d4f8: /* original fd3a, guest PC 0x0c09d4f8 */
if(!s->budget--) { s->failed_pc=0x0c09d4f8u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c09d4fa;
P_0c09d4fa: /* original f3e6, guest PC 0x0c09d4fa */
if(!s->budget--) { s->failed_pc=0x0c09d4fau; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d4fc;
P_0c09d4fc: /* original e004, guest PC 0x0c09d4fc */
if(!s->budget--) { s->failed_pc=0x0c09d4fcu; return 0; }
r[0]=0x00000004u;
goto P_0c09d4fe;
P_0c09d4fe: /* original fd37, guest PC 0x0c09d4fe */
if(!s->budget--) { s->failed_pc=0x0c09d4feu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09d500;
P_0c09d500: /* original e038, guest PC 0x0c09d500 */
if(!s->budget--) { s->failed_pc=0x0c09d500u; return 0; }
r[0]=0x00000038u;
goto P_0c09d502;
P_0c09d502: /* original f3e6, guest PC 0x0c09d502 */
if(!s->budget--) { s->failed_pc=0x0c09d502u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d504;
P_0c09d504: /* original e008, guest PC 0x0c09d504 */
if(!s->budget--) { s->failed_pc=0x0c09d504u; return 0; }
r[0]=0x00000008u;
goto P_0c09d506;
P_0c09d506: /* original fd37, guest PC 0x0c09d506 */
if(!s->budget--) { s->failed_pc=0x0c09d506u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09d508;
P_0c09d508: /* original d320, guest PC 0x0c09d508 */
if(!s->budget--) { s->failed_pc=0x0c09d508u; return 0; }
r[3]=read(ram,0x0c09d58cu,4);
goto P_0c09d50a;
P_0c09d50a: /* original 430b, guest PC 0x0c09d50a */
if(!s->budget--) { s->failed_pc=0x0c09d50au; return 0; }
target=r[3];
r[16]=code_base|0x0c09d50eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d50eu) { target=s->pc; goto dispatch; }
goto P_0c09d50e;
P_0c09d50c: /* original 64e3, guest PC 0x0c09d50c */
if(!s->budget--) { s->failed_pc=0x0c09d50cu; return 0; }
r[4]=r[14];
goto P_0c09d50e;
P_0c09d50e: /* original f3d8, guest PC 0x0c09d50e */
if(!s->budget--) { s->failed_pc=0x0c09d50eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c09d510;
P_0c09d510: /* original e030, guest PC 0x0c09d510 */
if(!s->budget--) { s->failed_pc=0x0c09d510u; return 0; }
r[0]=0x00000030u;
goto P_0c09d512;
P_0c09d512: /* original 7f0c, guest PC 0x0c09d512 */
if(!s->budget--) { s->failed_pc=0x0c09d512u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d514;
P_0c09d514: /* original fe37, guest PC 0x0c09d514 */
if(!s->budget--) { s->failed_pc=0x0c09d514u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d516;
P_0c09d516: /* original e004, guest PC 0x0c09d516 */
if(!s->budget--) { s->failed_pc=0x0c09d516u; return 0; }
r[0]=0x00000004u;
goto P_0c09d518;
P_0c09d518: /* original f3d6, guest PC 0x0c09d518 */
if(!s->budget--) { s->failed_pc=0x0c09d518u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09d51a;
P_0c09d51a: /* original e034, guest PC 0x0c09d51a */
if(!s->budget--) { s->failed_pc=0x0c09d51au; return 0; }
r[0]=0x00000034u;
goto P_0c09d51c;
P_0c09d51c: /* original 4f26, guest PC 0x0c09d51c */
if(!s->budget--) { s->failed_pc=0x0c09d51cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d51e;
P_0c09d51e: /* original fe37, guest PC 0x0c09d51e */
if(!s->budget--) { s->failed_pc=0x0c09d51eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d520;
P_0c09d520: /* original e008, guest PC 0x0c09d520 */
if(!s->budget--) { s->failed_pc=0x0c09d520u; return 0; }
r[0]=0x00000008u;
goto P_0c09d522;
P_0c09d522: /* original f3d6, guest PC 0x0c09d522 */
if(!s->budget--) { s->failed_pc=0x0c09d522u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09d524;
P_0c09d524: /* original e038, guest PC 0x0c09d524 */
if(!s->budget--) { s->failed_pc=0x0c09d524u; return 0; }
r[0]=0x00000038u;
goto P_0c09d526;
P_0c09d526: /* original fe37, guest PC 0x0c09d526 */
if(!s->budget--) { s->failed_pc=0x0c09d526u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d528;
P_0c09d528: /* original 6df6, guest PC 0x0c09d528 */
if(!s->budget--) { s->failed_pc=0x0c09d528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d52a;
P_0c09d52a: /* original 000b, guest PC 0x0c09d52a */
if(!s->budget--) { s->failed_pc=0x0c09d52au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d52c: /* original 6ef6, guest PC 0x0c09d52c */
if(!s->budget--) { s->failed_pc=0x0c09d52cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09d52e;
P_0c09d52e: /* original 4f22, guest PC 0x0c09d52e */
if(!s->budget--) { s->failed_pc=0x0c09d52eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d530;
P_0c09d530: /* original e004, guest PC 0x0c09d530 */
if(!s->budget--) { s->failed_pc=0x0c09d530u; return 0; }
r[0]=0x00000004u;
goto P_0c09d532;
P_0c09d532: /* original 7ff0, guest PC 0x0c09d532 */
if(!s->budget--) { s->failed_pc=0x0c09d532u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d534;
P_0c09d534: /* original 2f42, guest PC 0x0c09d534 */
if(!s->budget--) { s->failed_pc=0x0c09d534u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d536;
P_0c09d536: /* original 64f3, guest PC 0x0c09d536 */
if(!s->budget--) { s->failed_pc=0x0c09d536u; return 0; }
r[4]=r[15];
goto P_0c09d538;
P_0c09d538: /* original ff47, guest PC 0x0c09d538 */
if(!s->budget--) { s->failed_pc=0x0c09d538u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d53a;
P_0c09d53a: /* original e008, guest PC 0x0c09d53a */
if(!s->budget--) { s->failed_pc=0x0c09d53au; return 0; }
r[0]=0x00000008u;
goto P_0c09d53c;
P_0c09d53c: /* original f48d, guest PC 0x0c09d53c */
if(!s->budget--) { s->failed_pc=0x0c09d53cu; return 0; }
fr[4]=0;
goto P_0c09d53e;
P_0c09d53e: /* original ff47, guest PC 0x0c09d53e */
if(!s->budget--) { s->failed_pc=0x0c09d53eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d540;
P_0c09d540: /* original e00c, guest PC 0x0c09d540 */
if(!s->budget--) { s->failed_pc=0x0c09d540u; return 0; }
r[0]=0x0000000cu;
goto P_0c09d542;
P_0c09d542: /* original ff47, guest PC 0x0c09d542 */
if(!s->budget--) { s->failed_pc=0x0c09d542u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d544;
P_0c09d544: /* original d30d, guest PC 0x0c09d544 */
if(!s->budget--) { s->failed_pc=0x0c09d544u; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d546;
P_0c09d546: /* original 65f2, guest PC 0x0c09d546 */
if(!s->budget--) { s->failed_pc=0x0c09d546u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d548;
P_0c09d548: /* original 430b, guest PC 0x0c09d548 */
if(!s->budget--) { s->failed_pc=0x0c09d548u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d54cu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d54cu) { target=s->pc; goto dispatch; }
goto P_0c09d54c;
P_0c09d54a: /* original 7404, guest PC 0x0c09d54a */
if(!s->budget--) { s->failed_pc=0x0c09d54au; return 0; }
r[4]+=0x00000004u;
goto P_0c09d54c;
P_0c09d54c: /* original 7f10, guest PC 0x0c09d54c */
if(!s->budget--) { s->failed_pc=0x0c09d54cu; return 0; }
r[15]+=0x00000010u;
goto P_0c09d54e;
P_0c09d54e: /* original 4f26, guest PC 0x0c09d54e */
if(!s->budget--) { s->failed_pc=0x0c09d54eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d550;
P_0c09d550: /* original 000b, guest PC 0x0c09d550 */
if(!s->budget--) { s->failed_pc=0x0c09d550u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d552: /* original 0009, guest PC 0x0c09d552 */
if(!s->budget--) { s->failed_pc=0x0c09d552u; return 0; }
return vf3_matrix_family(0x0c09d554u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
