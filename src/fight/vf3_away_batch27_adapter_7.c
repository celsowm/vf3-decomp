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
int vf3_away_batch27_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062490u: goto P_0c062490;
case 0x0c062492u: goto P_0c062492;
case 0x0c062494u: goto P_0c062494;
case 0x0c062496u: goto P_0c062496;
case 0x0c062498u: goto P_0c062498;
case 0x0c06249au: goto P_0c06249a;
case 0x0c06249cu: goto P_0c06249c;
case 0x0c06249eu: goto P_0c06249e;
case 0x0c0624a0u: goto P_0c0624a0;
case 0x0c0624a2u: goto P_0c0624a2;
case 0x0c0624a4u: goto P_0c0624a4;
case 0x0c0624a6u: goto P_0c0624a6;
case 0x0c0624a8u: goto P_0c0624a8;
case 0x0c0624aau: goto P_0c0624aa;
case 0x0c0624acu: goto P_0c0624ac;
case 0x0c0624aeu: goto P_0c0624ae;
case 0x0c0624b0u: goto P_0c0624b0;
case 0x0c0624b2u: goto P_0c0624b2;
case 0x0c0624b4u: goto P_0c0624b4;
case 0x0c0624b6u: goto P_0c0624b6;
case 0x0c0624b8u: goto P_0c0624b8;
case 0x0c0624e4u: goto P_0c0624e4;
case 0x0c0624e6u: goto P_0c0624e6;
case 0x0c0624e8u: goto P_0c0624e8;
case 0x0c0624eau: goto P_0c0624ea;
case 0x0c0624ecu: goto P_0c0624ec;
case 0x0c0624eeu: goto P_0c0624ee;
case 0x0c0624f0u: goto P_0c0624f0;
case 0x0c0624f2u: goto P_0c0624f2;
case 0x0c0624f4u: goto P_0c0624f4;
case 0x0c0624f6u: goto P_0c0624f6;
case 0x0c0624f8u: goto P_0c0624f8;
case 0x0c0624fau: goto P_0c0624fa;
case 0x0c0624fcu: goto P_0c0624fc;
case 0x0c0624feu: goto P_0c0624fe;
case 0x0c062500u: goto P_0c062500;
case 0x0c062502u: goto P_0c062502;
case 0x0c062504u: goto P_0c062504;
case 0x0c062506u: goto P_0c062506;
case 0x0c062524u: goto P_0c062524;
case 0x0c062526u: goto P_0c062526;
case 0x0c062528u: goto P_0c062528;
case 0x0c06252au: goto P_0c06252a;
case 0x0c06252cu: goto P_0c06252c;
case 0x0c06252eu: goto P_0c06252e;
case 0x0c062530u: goto P_0c062530;
case 0x0c062532u: goto P_0c062532;
case 0x0c062534u: goto P_0c062534;
case 0x0c062536u: goto P_0c062536;
case 0x0c062538u: goto P_0c062538;
case 0x0c06253au: goto P_0c06253a;
case 0x0c06253cu: goto P_0c06253c;
case 0x0c06253eu: goto P_0c06253e;
case 0x0c062540u: goto P_0c062540;
case 0x0c062542u: goto P_0c062542;
case 0x0c062544u: goto P_0c062544;
case 0x0c062546u: goto P_0c062546;
case 0x0c062548u: goto P_0c062548;
case 0x0c06254au: goto P_0c06254a;
case 0x0c06254cu: goto P_0c06254c;
case 0x0c06254eu: goto P_0c06254e;
case 0x0c062550u: goto P_0c062550;
case 0x0c062552u: goto P_0c062552;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062490: /* original d53f, guest PC 0x0c062490 */
if(!s->budget--) { s->failed_pc=0x0c062490u; return 0; }
r[5]=read(ram,0x0c062590u,4);
goto P_0c062492;
P_0c062492: /* original e700, guest PC 0x0c062492 */
if(!s->budget--) { s->failed_pc=0x0c062492u; return 0; }
r[7]=0x00000000u;
goto P_0c062494;
P_0c062494: /* original 9079, guest PC 0x0c062494 */
if(!s->budget--) { s->failed_pc=0x0c062494u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06258au,2);
goto P_0c062496;
P_0c062496: /* original 6453, guest PC 0x0c062496 */
if(!s->budget--) { s->failed_pc=0x0c062496u; return 0; }
r[4]=r[5];
goto P_0c062498;
P_0c062498: /* original 6653, guest PC 0x0c062498 */
if(!s->budget--) { s->failed_pc=0x0c062498u; return 0; }
r[6]=r[5];
goto P_0c06249a;
P_0c06249a: /* original e501, guest PC 0x0c06249a */
if(!s->budget--) { s->failed_pc=0x0c06249au; return 0; }
r[5]=0x00000001u;
goto P_0c06249c;
P_0c06249c: /* original 6361, guest PC 0x0c06249c */
if(!s->budget--) { s->failed_pc=0x0c06249cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c06249e;
P_0c06249e: /* original 633d, guest PC 0x0c06249e */
if(!s->budget--) { s->failed_pc=0x0c06249eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0624a0;
P_0c0624a0: /* original 2358, guest PC 0x0c0624a0 */
if(!s->budget--) { s->failed_pc=0x0c0624a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0624a2;
P_0c0624a2: /* original 8b02, guest PC 0x0c0624a2 */
if(!s->budget--) { s->failed_pc=0x0c0624a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0624aa; }
goto P_0c0624a4;
P_0c0624a4: /* original 2451, guest PC 0x0c0624a4 */
if(!s->budget--) { s->failed_pc=0x0c0624a4u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0624a6;
P_0c0624a6: /* original 000b, guest PC 0x0c0624a6 */
if(!s->budget--) { s->failed_pc=0x0c0624a6u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0624a8: /* original 6043, guest PC 0x0c0624a8 */
if(!s->budget--) { s->failed_pc=0x0c0624a8u; return 0; }
r[0]=r[4];
goto P_0c0624aa;
P_0c0624aa: /* original 7701, guest PC 0x0c0624aa */
if(!s->budget--) { s->failed_pc=0x0c0624aau; return 0; }
r[7]+=0x00000001u;
goto P_0c0624ac;
P_0c0624ac: /* original 7418, guest PC 0x0c0624ac */
if(!s->budget--) { s->failed_pc=0x0c0624acu; return 0; }
r[4]+=0x00000018u;
goto P_0c0624ae;
P_0c0624ae: /* original 3703, guest PC 0x0c0624ae */
if(!s->budget--) { s->failed_pc=0x0c0624aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c0624b0;
P_0c0624b0: /* original 8ff4, guest PC 0x0c0624b0 */
if(!s->budget--) { s->failed_pc=0x0c0624b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000018u;
if(!cond) { goto P_0c06249c; }
goto P_0c0624b4;
P_0c0624b2: /* original 7618, guest PC 0x0c0624b2 */
if(!s->budget--) { s->failed_pc=0x0c0624b2u; return 0; }
r[6]+=0x00000018u;
goto P_0c0624b4;
P_0c0624b4: /* original e000, guest PC 0x0c0624b4 */
if(!s->budget--) { s->failed_pc=0x0c0624b4u; return 0; }
r[0]=0x00000000u;
goto P_0c0624b6;
P_0c0624b6: /* original 000b, guest PC 0x0c0624b6 */
if(!s->budget--) { s->failed_pc=0x0c0624b6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0624b8: /* original 0009, guest PC 0x0c0624b8 */
if(!s->budget--) { s->failed_pc=0x0c0624b8u; return 0; }
if(!vf3_matrix_family(0x0c0624bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0624bau; return 0; } return 1;
P_0c0624e4: /* original 6342, guest PC 0x0c0624e4 */
if(!s->budget--) { s->failed_pc=0x0c0624e4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0624e6;
P_0c0624e6: /* original 2338, guest PC 0x0c0624e6 */
if(!s->budget--) { s->failed_pc=0x0c0624e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0624e8;
P_0c0624e8: /* original 8b05, guest PC 0x0c0624e8 */
if(!s->budget--) { s->failed_pc=0x0c0624e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0624f6; }
goto P_0c0624ea;
P_0c0624ea: /* original e700, guest PC 0x0c0624ea */
if(!s->budget--) { s->failed_pc=0x0c0624eau; return 0; }
r[7]=0x00000000u;
goto P_0c0624ec;
P_0c0624ec: /* original 1671, guest PC 0x0c0624ec */
if(!s->budget--) { s->failed_pc=0x0c0624ecu; return 0; }
write(ram,r[6]+4,r[7],4);
goto P_0c0624ee;
P_0c0624ee: /* original 1672, guest PC 0x0c0624ee */
if(!s->budget--) { s->failed_pc=0x0c0624eeu; return 0; }
write(ram,r[6]+8,r[7],4);
goto P_0c0624f0;
P_0c0624f0: /* original 2462, guest PC 0x0c0624f0 */
if(!s->budget--) { s->failed_pc=0x0c0624f0u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0624f2;
P_0c0624f2: /* original a007, guest PC 0x0c0624f2 */
if(!s->budget--) { s->failed_pc=0x0c0624f2u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c062504;
P_0c0624f4: /* original 2562, guest PC 0x0c0624f4 */
if(!s->budget--) { s->failed_pc=0x0c0624f4u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0624f6;
P_0c0624f6: /* original 6542, guest PC 0x0c0624f6 */
if(!s->budget--) { s->failed_pc=0x0c0624f6u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0624f8;
P_0c0624f8: /* original 5251, guest PC 0x0c0624f8 */
if(!s->budget--) { s->failed_pc=0x0c0624f8u; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c0624fa;
P_0c0624fa: /* original 1621, guest PC 0x0c0624fa */
if(!s->budget--) { s->failed_pc=0x0c0624fau; return 0; }
write(ram,r[6]+4,r[2],4);
goto P_0c0624fc;
P_0c0624fc: /* original 6342, guest PC 0x0c0624fc */
if(!s->budget--) { s->failed_pc=0x0c0624fcu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0624fe;
P_0c0624fe: /* original 1632, guest PC 0x0c0624fe */
if(!s->budget--) { s->failed_pc=0x0c0624feu; return 0; }
write(ram,r[6]+8,r[3],4);
goto P_0c062500;
P_0c062500: /* original 1561, guest PC 0x0c062500 */
if(!s->budget--) { s->failed_pc=0x0c062500u; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c062502;
P_0c062502: /* original 2462, guest PC 0x0c062502 */
if(!s->budget--) { s->failed_pc=0x0c062502u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c062504;
P_0c062504: /* original 000b, guest PC 0x0c062504 */
if(!s->budget--) { s->failed_pc=0x0c062504u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062506: /* original 0009, guest PC 0x0c062506 */
if(!s->budget--) { s->failed_pc=0x0c062506u; return 0; }
if(!vf3_matrix_family(0x0c062508u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062508u; return 0; } return 1;
P_0c062524: /* original 7ff8, guest PC 0x0c062524 */
if(!s->budget--) { s->failed_pc=0x0c062524u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c062526;
P_0c062526: /* original 5761, guest PC 0x0c062526 */
if(!s->budget--) { s->failed_pc=0x0c062526u; return 0; }
r[7]=read(ram,r[6]+4,4);
goto P_0c062528;
P_0c062528: /* original 2f72, guest PC 0x0c062528 */
if(!s->budget--) { s->failed_pc=0x0c062528u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c06252a;
P_0c06252a: /* original 2778, guest PC 0x0c06252a */
if(!s->budget--) { s->failed_pc=0x0c06252au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06252c;
P_0c06252c: /* original 5362, guest PC 0x0c06252c */
if(!s->budget--) { s->failed_pc=0x0c06252cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06252e;
P_0c06252e: /* original 8f03, guest PC 0x0c06252e */
if(!s->budget--) { s->failed_pc=0x0c06252eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c062538; }
goto P_0c062532;
P_0c062530: /* original 1f31, guest PC 0x0c062530 */
if(!s->budget--) { s->failed_pc=0x0c062530u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c062532;
P_0c062532: /* original 5162, guest PC 0x0c062532 */
if(!s->budget--) { s->failed_pc=0x0c062532u; return 0; }
r[1]=read(ram,r[6]+8,4);
goto P_0c062534;
P_0c062534: /* original a003, guest PC 0x0c062534 */
if(!s->budget--) { s->failed_pc=0x0c062534u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c06253e;
P_0c062536: /* original 2412, guest PC 0x0c062536 */
if(!s->budget--) { s->failed_pc=0x0c062536u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c062538;
P_0c062538: /* original 62f2, guest PC 0x0c062538 */
if(!s->budget--) { s->failed_pc=0x0c062538u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06253a;
P_0c06253a: /* original 5362, guest PC 0x0c06253a */
if(!s->budget--) { s->failed_pc=0x0c06253au; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c06253c;
P_0c06253c: /* original 1232, guest PC 0x0c06253c */
if(!s->budget--) { s->failed_pc=0x0c06253cu; return 0; }
write(ram,r[2]+8,r[3],4);
goto P_0c06253e;
P_0c06253e: /* original 5262, guest PC 0x0c06253e */
if(!s->budget--) { s->failed_pc=0x0c06253eu; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c062540;
P_0c062540: /* original 2228, guest PC 0x0c062540 */
if(!s->budget--) { s->failed_pc=0x0c062540u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c062542;
P_0c062542: /* original 8b02, guest PC 0x0c062542 */
if(!s->budget--) { s->failed_pc=0x0c062542u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06254a; }
goto P_0c062544;
P_0c062544: /* original 5261, guest PC 0x0c062544 */
if(!s->budget--) { s->failed_pc=0x0c062544u; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c062546;
P_0c062546: /* original a003, guest PC 0x0c062546 */
if(!s->budget--) { s->failed_pc=0x0c062546u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c062550;
P_0c062548: /* original 2522, guest PC 0x0c062548 */
if(!s->budget--) { s->failed_pc=0x0c062548u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c06254a;
P_0c06254a: /* original 51f1, guest PC 0x0c06254a */
if(!s->budget--) { s->failed_pc=0x0c06254au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06254c;
P_0c06254c: /* original 5361, guest PC 0x0c06254c */
if(!s->budget--) { s->failed_pc=0x0c06254cu; return 0; }
r[3]=read(ram,r[6]+4,4);
goto P_0c06254e;
P_0c06254e: /* original 1131, guest PC 0x0c06254e */
if(!s->budget--) { s->failed_pc=0x0c06254eu; return 0; }
write(ram,r[1]+4,r[3],4);
goto P_0c062550;
P_0c062550: /* original 000b, guest PC 0x0c062550 */
if(!s->budget--) { s->failed_pc=0x0c062550u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c062552: /* original 7f08, guest PC 0x0c062552 */
if(!s->budget--) { s->failed_pc=0x0c062552u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c062554u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062554u; return 0; } return 1;
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
