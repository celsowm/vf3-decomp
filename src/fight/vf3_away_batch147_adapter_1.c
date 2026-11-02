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
int vf3_away_batch147_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0aff76u: goto P_0c0aff76;
case 0x0c0aff78u: goto P_0c0aff78;
case 0x0c0aff7au: goto P_0c0aff7a;
case 0x0c0aff7cu: goto P_0c0aff7c;
case 0x0c0aff7eu: goto P_0c0aff7e;
case 0x0c0aff80u: goto P_0c0aff80;
case 0x0c0aff82u: goto P_0c0aff82;
case 0x0c0aff84u: goto P_0c0aff84;
case 0x0c0aff86u: goto P_0c0aff86;
case 0x0c0aff88u: goto P_0c0aff88;
case 0x0c0aff8au: goto P_0c0aff8a;
case 0x0c0aff8cu: goto P_0c0aff8c;
case 0x0c0aff8eu: goto P_0c0aff8e;
case 0x0c0aff90u: goto P_0c0aff90;
case 0x0c0aff92u: goto P_0c0aff92;
case 0x0c0aff94u: goto P_0c0aff94;
case 0x0c0aff96u: goto P_0c0aff96;
case 0x0c0aff98u: goto P_0c0aff98;
case 0x0c0aff9au: goto P_0c0aff9a;
case 0x0c0aff9cu: goto P_0c0aff9c;
case 0x0c0aff9eu: goto P_0c0aff9e;
case 0x0c0affa0u: goto P_0c0affa0;
case 0x0c0affa2u: goto P_0c0affa2;
case 0x0c0affa4u: goto P_0c0affa4;
case 0x0c0affa6u: goto P_0c0affa6;
case 0x0c0affa8u: goto P_0c0affa8;
case 0x0c0affaau: goto P_0c0affaa;
case 0x0c0affacu: goto P_0c0affac;
case 0x0c0affaeu: goto P_0c0affae;
case 0x0c0affb0u: goto P_0c0affb0;
case 0x0c0affb2u: goto P_0c0affb2;
case 0x0c0affb4u: goto P_0c0affb4;
case 0x0c0affb6u: goto P_0c0affb6;
case 0x0c0affb8u: goto P_0c0affb8;
case 0x0c0affbau: goto P_0c0affba;
case 0x0c0affbcu: goto P_0c0affbc;
case 0x0c0affbeu: goto P_0c0affbe;
case 0x0c0affc0u: goto P_0c0affc0;
case 0x0c0affc2u: goto P_0c0affc2;
case 0x0c0affc4u: goto P_0c0affc4;
case 0x0c0affc6u: goto P_0c0affc6;
case 0x0c0affc8u: goto P_0c0affc8;
case 0x0c0affcau: goto P_0c0affca;
case 0x0c0affccu: goto P_0c0affcc;
case 0x0c0affceu: goto P_0c0affce;
case 0x0c0affd0u: goto P_0c0affd0;
case 0x0c0affd2u: goto P_0c0affd2;
case 0x0c0affd4u: goto P_0c0affd4;
case 0x0c0b001cu: goto P_0c0b001c;
case 0x0c0b001eu: goto P_0c0b001e;
case 0x0c0b0020u: goto P_0c0b0020;
case 0x0c0b0022u: goto P_0c0b0022;
case 0x0c0b0024u: goto P_0c0b0024;
case 0x0c0b0026u: goto P_0c0b0026;
case 0x0c0b0028u: goto P_0c0b0028;
case 0x0c0b002au: goto P_0c0b002a;
case 0x0c0b002cu: goto P_0c0b002c;
case 0x0c0b002eu: goto P_0c0b002e;
case 0x0c0b0030u: goto P_0c0b0030;
case 0x0c0b0032u: goto P_0c0b0032;
case 0x0c0b0034u: goto P_0c0b0034;
case 0x0c0b0036u: goto P_0c0b0036;
case 0x0c0b0038u: goto P_0c0b0038;
case 0x0c0b003au: goto P_0c0b003a;
case 0x0c0b003cu: goto P_0c0b003c;
case 0x0c0b003eu: goto P_0c0b003e;
case 0x0c0b0040u: goto P_0c0b0040;
case 0x0c0b0042u: goto P_0c0b0042;
case 0x0c0b0044u: goto P_0c0b0044;
case 0x0c0b0046u: goto P_0c0b0046;
case 0x0c0b0048u: goto P_0c0b0048;
case 0x0c0b004au: goto P_0c0b004a;
case 0x0c0b004cu: goto P_0c0b004c;
case 0x0c0b004eu: goto P_0c0b004e;
case 0x0c0b0050u: goto P_0c0b0050;
case 0x0c0b0052u: goto P_0c0b0052;
case 0x0c0b0054u: goto P_0c0b0054;
case 0x0c0b0056u: goto P_0c0b0056;
case 0x0c0b0058u: goto P_0c0b0058;
case 0x0c0b005au: goto P_0c0b005a;
case 0x0c0b005cu: goto P_0c0b005c;
case 0x0c0b005eu: goto P_0c0b005e;
case 0x0c0b0060u: goto P_0c0b0060;
case 0x0c0b0062u: goto P_0c0b0062;
case 0x0c0b0064u: goto P_0c0b0064;
case 0x0c0b0066u: goto P_0c0b0066;
case 0x0c0b0068u: goto P_0c0b0068;
case 0x0c0b006au: goto P_0c0b006a;
case 0x0c0b006cu: goto P_0c0b006c;
case 0x0c0b006eu: goto P_0c0b006e;
case 0x0c0b0070u: goto P_0c0b0070;
case 0x0c0b0072u: goto P_0c0b0072;
case 0x0c0b0074u: goto P_0c0b0074;
case 0x0c0b0076u: goto P_0c0b0076;
case 0x0c0b0078u: goto P_0c0b0078;
case 0x0c0b007au: goto P_0c0b007a;
case 0x0c0b007cu: goto P_0c0b007c;
case 0x0c0b007eu: goto P_0c0b007e;
case 0x0c0b0080u: goto P_0c0b0080;
case 0x0c0b0082u: goto P_0c0b0082;
case 0x0c0b0084u: goto P_0c0b0084;
case 0x0c0b0086u: goto P_0c0b0086;
case 0x0c0b0088u: goto P_0c0b0088;
case 0x0c0b008au: goto P_0c0b008a;
case 0x0c0b008cu: goto P_0c0b008c;
case 0x0c0b008eu: goto P_0c0b008e;
case 0x0c0b0090u: goto P_0c0b0090;
case 0x0c0b0092u: goto P_0c0b0092;
case 0x0c0b0094u: goto P_0c0b0094;
case 0x0c0b0096u: goto P_0c0b0096;
case 0x0c0b0098u: goto P_0c0b0098;
case 0x0c0b009au: goto P_0c0b009a;
case 0x0c0b009cu: goto P_0c0b009c;
case 0x0c0b009eu: goto P_0c0b009e;
case 0x0c0b00a0u: goto P_0c0b00a0;
case 0x0c0b00a2u: goto P_0c0b00a2;
case 0x0c0b00a4u: goto P_0c0b00a4;
case 0x0c0b00a6u: goto P_0c0b00a6;
case 0x0c0b00a8u: goto P_0c0b00a8;
case 0x0c0b00aau: goto P_0c0b00aa;
case 0x0c0b00acu: goto P_0c0b00ac;
case 0x0c0b00aeu: goto P_0c0b00ae;
case 0x0c0b00b0u: goto P_0c0b00b0;
case 0x0c0b00b2u: goto P_0c0b00b2;
case 0x0c0b00b4u: goto P_0c0b00b4;
case 0x0c0b00b6u: goto P_0c0b00b6;
case 0x0c0b00b8u: goto P_0c0b00b8;
case 0x0c0b00bau: goto P_0c0b00ba;
case 0x0c0b00bcu: goto P_0c0b00bc;
case 0x0c0b00beu: goto P_0c0b00be;
case 0x0c0b00c0u: goto P_0c0b00c0;
case 0x0c0b00c2u: goto P_0c0b00c2;
case 0x0c0b00c4u: goto P_0c0b00c4;
case 0x0c0b00c6u: goto P_0c0b00c6;
case 0x0c0b00c8u: goto P_0c0b00c8;
case 0x0c0b00cau: goto P_0c0b00ca;
case 0x0c0b00ccu: goto P_0c0b00cc;
case 0x0c0b00ceu: goto P_0c0b00ce;
case 0x0c0b00d0u: goto P_0c0b00d0;
case 0x0c0b00d2u: goto P_0c0b00d2;
case 0x0c0b00d4u: goto P_0c0b00d4;
case 0x0c0b1464u: goto P_0c0b1464;
case 0x0c0b1466u: goto P_0c0b1466;
case 0x0c0b1468u: goto P_0c0b1468;
case 0x0c0b146au: goto P_0c0b146a;
case 0x0c0b146cu: goto P_0c0b146c;
case 0x0c0b146eu: goto P_0c0b146e;
case 0x0c0b1470u: goto P_0c0b1470;
case 0x0c0b1472u: goto P_0c0b1472;
case 0x0c0b1474u: goto P_0c0b1474;
case 0x0c0b1476u: goto P_0c0b1476;
case 0x0c0b1478u: goto P_0c0b1478;
case 0x0c0b147au: goto P_0c0b147a;
case 0x0c0b147cu: goto P_0c0b147c;
case 0x0c0b147eu: goto P_0c0b147e;
case 0x0c0b1480u: goto P_0c0b1480;
case 0x0c0b1482u: goto P_0c0b1482;
case 0x0c0b1484u: goto P_0c0b1484;
case 0x0c0b1486u: goto P_0c0b1486;
case 0x0c0b1488u: goto P_0c0b1488;
case 0x0c0b148au: goto P_0c0b148a;
case 0x0c0b148cu: goto P_0c0b148c;
case 0x0c0b148eu: goto P_0c0b148e;
case 0x0c0b1490u: goto P_0c0b1490;
case 0x0c0b1492u: goto P_0c0b1492;
case 0x0c0b1494u: goto P_0c0b1494;
case 0x0c0b1496u: goto P_0c0b1496;
case 0x0c0b1498u: goto P_0c0b1498;
case 0x0c0b149au: goto P_0c0b149a;
case 0x0c0b149cu: goto P_0c0b149c;
case 0x0c0b149eu: goto P_0c0b149e;
case 0x0c0b14a0u: goto P_0c0b14a0;
case 0x0c0b14a2u: goto P_0c0b14a2;
case 0x0c0b14a4u: goto P_0c0b14a4;
case 0x0c0b14a6u: goto P_0c0b14a6;
case 0x0c0b14a8u: goto P_0c0b14a8;
case 0x0c0b14aau: goto P_0c0b14aa;
case 0x0c0b14acu: goto P_0c0b14ac;
case 0x0c0b14aeu: goto P_0c0b14ae;
case 0x0c0b14b0u: goto P_0c0b14b0;
case 0x0c0b14b2u: goto P_0c0b14b2;
case 0x0c0b14b4u: goto P_0c0b14b4;
case 0x0c0b14b6u: goto P_0c0b14b6;
case 0x0c0b14b8u: goto P_0c0b14b8;
case 0x0c0b14bau: goto P_0c0b14ba;
case 0x0c0b14bcu: goto P_0c0b14bc;
case 0x0c0b14beu: goto P_0c0b14be;
case 0x0c0b14c0u: goto P_0c0b14c0;
case 0x0c0b14c2u: goto P_0c0b14c2;
case 0x0c0b14c4u: goto P_0c0b14c4;
case 0x0c0b14c6u: goto P_0c0b14c6;
case 0x0c0b14c8u: goto P_0c0b14c8;
case 0x0c0b14cau: goto P_0c0b14ca;
case 0x0c0b14ccu: goto P_0c0b14cc;
case 0x0c0b14ceu: goto P_0c0b14ce;
case 0x0c0b14d0u: goto P_0c0b14d0;
case 0x0c0b14d2u: goto P_0c0b14d2;
case 0x0c0b14d4u: goto P_0c0b14d4;
case 0x0c0b14d6u: goto P_0c0b14d6;
case 0x0c0b14d8u: goto P_0c0b14d8;
case 0x0c0b14dau: goto P_0c0b14da;
case 0x0c0b14dcu: goto P_0c0b14dc;
case 0x0c0b14deu: goto P_0c0b14de;
case 0x0c0b14e0u: goto P_0c0b14e0;
case 0x0c0b14e2u: goto P_0c0b14e2;
case 0x0c0b14e4u: goto P_0c0b14e4;
case 0x0c0b14e6u: goto P_0c0b14e6;
case 0x0c0b14e8u: goto P_0c0b14e8;
case 0x0c0b14eau: goto P_0c0b14ea;
case 0x0c0b14ecu: goto P_0c0b14ec;
case 0x0c0b14eeu: goto P_0c0b14ee;
case 0x0c0b14f0u: goto P_0c0b14f0;
case 0x0c0b14f2u: goto P_0c0b14f2;
case 0x0c0b14f4u: goto P_0c0b14f4;
case 0x0c0b14f6u: goto P_0c0b14f6;
case 0x0c0b14f8u: goto P_0c0b14f8;
case 0x0c0b14fau: goto P_0c0b14fa;
case 0x0c0b14fcu: goto P_0c0b14fc;
case 0x0c0b14feu: goto P_0c0b14fe;
case 0x0c0b1500u: goto P_0c0b1500;
case 0x0c0b1502u: goto P_0c0b1502;
case 0x0c0b1504u: goto P_0c0b1504;
case 0x0c0b1506u: goto P_0c0b1506;
case 0x0c0b1508u: goto P_0c0b1508;
case 0x0c0b150au: goto P_0c0b150a;
case 0x0c0b150cu: goto P_0c0b150c;
case 0x0c0b150eu: goto P_0c0b150e;
case 0x0c0b1510u: goto P_0c0b1510;
case 0x0c0b1512u: goto P_0c0b1512;
case 0x0c0b1514u: goto P_0c0b1514;
case 0x0c0b1516u: goto P_0c0b1516;
case 0x0c0b1518u: goto P_0c0b1518;
case 0x0c0b151au: goto P_0c0b151a;
case 0x0c0b151cu: goto P_0c0b151c;
case 0x0c0b151eu: goto P_0c0b151e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0aff76: /* original 2fe6, guest PC 0x0c0aff76 */
if(!s->budget--) { s->failed_pc=0x0c0aff76u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aff78;
P_0c0aff78: /* original e048, guest PC 0x0c0aff78 */
if(!s->budget--) { s->failed_pc=0x0c0aff78u; return 0; }
r[0]=0x00000048u;
goto P_0c0aff7a;
P_0c0aff7a: /* original 2fd6, guest PC 0x0c0aff7a */
if(!s->budget--) { s->failed_pc=0x0c0aff7au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aff7c;
P_0c0aff7c: /* original 2fc6, guest PC 0x0c0aff7c */
if(!s->budget--) { s->failed_pc=0x0c0aff7cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aff7e;
P_0c0aff7e: /* original 2fb6, guest PC 0x0c0aff7e */
if(!s->budget--) { s->failed_pc=0x0c0aff7eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aff80;
P_0c0aff80: /* original 054e, guest PC 0x0c0aff80 */
if(!s->budget--) { s->failed_pc=0x0c0aff80u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0aff82;
P_0c0aff82: /* original 7ff0, guest PC 0x0c0aff82 */
if(!s->budget--) { s->failed_pc=0x0c0aff82u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0aff84;
P_0c0aff84: /* original d321, guest PC 0x0c0aff84 */
if(!s->budget--) { s->failed_pc=0x0c0aff84u; return 0; }
r[3]=read(ram,0x0c0b000cu,4);
goto P_0c0aff86;
P_0c0aff86: /* original 854f, guest PC 0x0c0aff86 */
if(!s->budget--) { s->failed_pc=0x0c0aff86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0aff88;
P_0c0aff88: /* original 6642, guest PC 0x0c0aff88 */
if(!s->budget--) { s->failed_pc=0x0c0aff88u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c0aff8a;
P_0c0aff8a: /* original 2358, guest PC 0x0c0aff8a */
if(!s->budget--) { s->failed_pc=0x0c0aff8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0aff8c;
P_0c0aff8c: /* original 8d04, guest PC 0x0c0aff8c */
if(!s->budget--) { s->failed_pc=0x0c0aff8cu; return 0; }
cond=r[17]&1u;
r[7]=r[0]&65535u;
if(cond) { goto P_0c0aff98; }
goto P_0c0aff90;
P_0c0aff8e: /* original 670d, guest PC 0x0c0aff8e */
if(!s->budget--) { s->failed_pc=0x0c0aff8eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0aff90;
P_0c0aff90: /* original 9023, guest PC 0x0c0aff90 */
if(!s->budget--) { s->failed_pc=0x0c0aff90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affdau,2);
goto P_0c0aff92;
P_0c0aff92: /* original 024d, guest PC 0x0c0aff92 */
if(!s->budget--) { s->failed_pc=0x0c0aff92u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aff94;
P_0c0aff94: /* original 622d, guest PC 0x0c0aff94 */
if(!s->budget--) { s->failed_pc=0x0c0aff94u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aff96;
P_0c0aff96: /* original 372c, guest PC 0x0c0aff96 */
if(!s->budget--) { s->failed_pc=0x0c0aff96u; return 0; }
r[7]+=r[2];
goto P_0c0aff98;
P_0c0aff98: /* original 9020, guest PC 0x0c0aff98 */
if(!s->budget--) { s->failed_pc=0x0c0aff98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affdcu,2);
goto P_0c0aff9a;
P_0c0aff9a: /* original 6b43, guest PC 0x0c0aff9a */
if(!s->budget--) { s->failed_pc=0x0c0aff9au; return 0; }
r[11]=r[4];
goto P_0c0aff9c;
P_0c0aff9c: /* original 7b38, guest PC 0x0c0aff9c */
if(!s->budget--) { s->failed_pc=0x0c0aff9cu; return 0; }
r[11]+=0x00000038u;
goto P_0c0aff9e;
P_0c0aff9e: /* original 0475, guest PC 0x0c0aff9e */
if(!s->budget--) { s->failed_pc=0x0c0aff9eu; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0affa0;
P_0c0affa0: /* original 901d, guest PC 0x0c0affa0 */
if(!s->budget--) { s->failed_pc=0x0c0affa0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affdeu,2);
goto P_0c0affa2;
P_0c0affa2: /* original d31c, guest PC 0x0c0affa2 */
if(!s->budget--) { s->failed_pc=0x0c0affa2u; return 0; }
r[3]=read(ram,0x0c0b0014u,4);
goto P_0c0affa4;
P_0c0affa4: /* original 0e4d, guest PC 0x0c0affa4 */
if(!s->budget--) { s->failed_pc=0x0c0affa4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0affa6;
P_0c0affa6: /* original e03e, guest PC 0x0c0affa6 */
if(!s->budget--) { s->failed_pc=0x0c0affa6u; return 0; }
r[0]=0x0000003eu;
goto P_0c0affa8;
P_0c0affa8: /* original 0d4d, guest PC 0x0c0affa8 */
if(!s->budget--) { s->failed_pc=0x0c0affa8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0affaa;
P_0c0affaa: /* original 9019, guest PC 0x0c0affaa */
if(!s->budget--) { s->failed_pc=0x0c0affaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affe0u,2);
goto P_0c0affac;
P_0c0affac: /* original 6eed, guest PC 0x0c0affac */
if(!s->budget--) { s->failed_pc=0x0c0affacu; return 0; }
r[14]=r[14]&65535u;
goto P_0c0affae;
P_0c0affae: /* original d718, guest PC 0x0c0affae */
if(!s->budget--) { s->failed_pc=0x0c0affaeu; return 0; }
r[7]=read(ram,0x0c0b0010u,4);
goto P_0c0affb0;
P_0c0affb0: /* original 6ddd, guest PC 0x0c0affb0 */
if(!s->budget--) { s->failed_pc=0x0c0affb0u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0affb2;
P_0c0affb2: /* original 0c4d, guest PC 0x0c0affb2 */
if(!s->budget--) { s->failed_pc=0x0c0affb2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0affb4;
P_0c0affb4: /* original 84b3, guest PC 0x0c0affb4 */
if(!s->budget--) { s->failed_pc=0x0c0affb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+3,1);
goto P_0c0affb6;
P_0c0affb6: /* original 6ccd, guest PC 0x0c0affb6 */
if(!s->budget--) { s->failed_pc=0x0c0affb6u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0affb8;
P_0c0affb8: /* original 4c01, guest PC 0x0c0affb8 */
if(!s->budget--) { s->failed_pc=0x0c0affb8u; return 0; }
r[17]=(r[17]&~1u)|((r[12]&1)!=0);
r[12]>>=1;
goto P_0c0affba;
P_0c0affba: /* original 2358, guest PC 0x0c0affba */
if(!s->budget--) { s->failed_pc=0x0c0affbau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0affbc;
P_0c0affbc: /* original 8f2e, guest PC 0x0c0affbc */
if(!s->budget--) { s->failed_pc=0x0c0affbcu; return 0; }
cond=r[17]&1u;
r[11]=r[0]&255u;
if(!cond) { goto P_0c0b001c; }
goto P_0c0affc0;
P_0c0affbe: /* original 6b0c, guest PC 0x0c0affbe */
if(!s->budget--) { s->failed_pc=0x0c0affbeu; return 0; }
r[11]=r[0]&255u;
goto P_0c0affc0;
P_0c0affc0: /* original 60b3, guest PC 0x0c0affc0 */
if(!s->budget--) { s->failed_pc=0x0c0affc0u; return 0; }
r[0]=r[11];
goto P_0c0affc2;
P_0c0affc2: /* original 8812, guest PC 0x0c0affc2 */
if(!s->budget--) { s->failed_pc=0x0c0affc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0affc4;
P_0c0affc4: /* original 8904, guest PC 0x0c0affc4 */
if(!s->budget--) { s->failed_pc=0x0c0affc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0affd0; }
goto P_0c0affc6;
P_0c0affc6: /* original 920c, guest PC 0x0c0affc6 */
if(!s->budget--) { s->failed_pc=0x0c0affc6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0affe2u,2);
goto P_0c0affc8;
P_0c0affc8: /* original 2e28, guest PC 0x0c0affc8 */
if(!s->budget--) { s->failed_pc=0x0c0affc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[2])==0)!=0);
goto P_0c0affca;
P_0c0affca: /* original 8901, guest PC 0x0c0affca */
if(!s->budget--) { s->failed_pc=0x0c0affcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0affd0; }
goto P_0c0affcc;
P_0c0affcc: /* original 3dc6, guest PC 0x0c0affcc */
if(!s->budget--) { s->failed_pc=0x0c0affccu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[12])!=0);
goto P_0c0affce;
P_0c0affce: /* original 8b36, guest PC 0x0c0affce */
if(!s->budget--) { s->failed_pc=0x0c0affceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b003e; }
goto P_0c0affd0;
P_0c0affd0: /* original d311, guest PC 0x0c0affd0 */
if(!s->budget--) { s->failed_pc=0x0c0affd0u; return 0; }
r[3]=read(ram,0x0c0b0018u,4);
goto P_0c0affd2;
P_0c0affd2: /* original a035, guest PC 0x0c0affd2 */
if(!s->budget--) { s->failed_pc=0x0c0affd2u; return 0; }
r[6]&=r[3];
goto P_0c0b0040;
P_0c0affd4: /* original 2639, guest PC 0x0c0affd4 */
if(!s->budget--) { s->failed_pc=0x0c0affd4u; return 0; }
r[6]&=r[3];
if(!vf3_matrix_family(0x0c0affd6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0affd6u; return 0; } return 1;
P_0c0b001c: /* original 905b, guest PC 0x0c0b001c */
if(!s->budget--) { s->failed_pc=0x0c0b001cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d6u,2);
goto P_0c0b001e;
P_0c0b001e: /* original 014e, guest PC 0x0c0b001e */
if(!s->budget--) { s->failed_pc=0x0c0b001eu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0b0020;
P_0c0b0020: /* original 2178, guest PC 0x0c0b0020 */
if(!s->budget--) { s->failed_pc=0x0c0b0020u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[7])==0)!=0);
goto P_0c0b0022;
P_0c0b0022: /* original 8b0c, guest PC 0x0c0b0022 */
if(!s->budget--) { s->failed_pc=0x0c0b0022u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b003e; }
goto P_0c0b0024;
P_0c0b0024: /* original 60b3, guest PC 0x0c0b0024 */
if(!s->budget--) { s->failed_pc=0x0c0b0024u; return 0; }
r[0]=r[11];
goto P_0c0b0026;
P_0c0b0026: /* original 8812, guest PC 0x0c0b0026 */
if(!s->budget--) { s->failed_pc=0x0c0b0026u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0b0028;
P_0c0b0028: /* original 8b04, guest PC 0x0c0b0028 */
if(!s->budget--) { s->failed_pc=0x0c0b0028u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b0034; }
goto P_0c0b002a;
P_0c0b002a: /* original 9355, guest PC 0x0c0b002a */
if(!s->budget--) { s->failed_pc=0x0c0b002au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d8u,2);
goto P_0c0b002c;
P_0c0b002c: /* original 9055, guest PC 0x0c0b002c */
if(!s->budget--) { s->failed_pc=0x0c0b002cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00dau,2);
goto P_0c0b002e;
P_0c0b002e: /* original 2e3b, guest PC 0x0c0b002e */
if(!s->budget--) { s->failed_pc=0x0c0b002eu; return 0; }
r[14]|=r[3];
goto P_0c0b0030;
P_0c0b0030: /* original a005, guest PC 0x0c0b0030 */
if(!s->budget--) { s->failed_pc=0x0c0b0030u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0b003e;
P_0c0b0032: /* original 04e5, guest PC 0x0c0b0032 */
if(!s->budget--) { s->failed_pc=0x0c0b0032u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0b0034;
P_0c0b0034: /* original 9350, guest PC 0x0c0b0034 */
if(!s->budget--) { s->failed_pc=0x0c0b0034u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d8u,2);
goto P_0c0b0036;
P_0c0b0036: /* original 2e38, guest PC 0x0c0b0036 */
if(!s->budget--) { s->failed_pc=0x0c0b0036u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[3])==0)!=0);
goto P_0c0b0038;
P_0c0b0038: /* original 8b01, guest PC 0x0c0b0038 */
if(!s->budget--) { s->failed_pc=0x0c0b0038u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b003e; }
goto P_0c0b003a;
P_0c0b003a: /* original 3dc6, guest PC 0x0c0b003a */
if(!s->budget--) { s->failed_pc=0x0c0b003au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[12])!=0);
goto P_0c0b003c;
P_0c0b003c: /* original 8bc8, guest PC 0x0c0b003c */
if(!s->budget--) { s->failed_pc=0x0c0b003cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0affd0; }
goto P_0c0b003e;
P_0c0b003e: /* original 267b, guest PC 0x0c0b003e */
if(!s->budget--) { s->failed_pc=0x0c0b003eu; return 0; }
r[6]|=r[7];
goto P_0c0b0040;
P_0c0b0040: /* original e04c, guest PC 0x0c0b0040 */
if(!s->budget--) { s->failed_pc=0x0c0b0040u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b0042;
P_0c0b0042: /* original 034e, guest PC 0x0c0b0042 */
if(!s->budget--) { s->failed_pc=0x0c0b0042u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0b0044;
P_0c0b0044: /* original 2f32, guest PC 0x0c0b0044 */
if(!s->budget--) { s->failed_pc=0x0c0b0044u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0b0046;
P_0c0b0046: /* original 62f2, guest PC 0x0c0b0046 */
if(!s->budget--) { s->failed_pc=0x0c0b0046u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0b0048;
P_0c0b0048: /* original d327, guest PC 0x0c0b0048 */
if(!s->budget--) { s->failed_pc=0x0c0b0048u; return 0; }
r[3]=read(ram,0x0c0b00e8u,4);
goto P_0c0b004a;
P_0c0b004a: /* original 2238, guest PC 0x0c0b004a */
if(!s->budget--) { s->failed_pc=0x0c0b004au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0b004c;
P_0c0b004c: /* original 8b26, guest PC 0x0c0b004c */
if(!s->budget--) { s->failed_pc=0x0c0b004cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b009c; }
goto P_0c0b004e;
P_0c0b004e: /* original d127, guest PC 0x0c0b004e */
if(!s->budget--) { s->failed_pc=0x0c0b004eu; return 0; }
r[1]=read(ram,0x0c0b00ecu,4);
goto P_0c0b0050;
P_0c0b0050: /* original 2158, guest PC 0x0c0b0050 */
if(!s->budget--) { s->failed_pc=0x0c0b0050u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c0b0052;
P_0c0b0052: /* original 8b23, guest PC 0x0c0b0052 */
if(!s->budget--) { s->failed_pc=0x0c0b0052u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b009c; }
goto P_0c0b0054;
P_0c0b0054: /* original d326, guest PC 0x0c0b0054 */
if(!s->budget--) { s->failed_pc=0x0c0b0054u; return 0; }
r[3]=read(ram,0x0c0b00f0u,4);
goto P_0c0b0056;
P_0c0b0056: /* original 2358, guest PC 0x0c0b0056 */
if(!s->budget--) { s->failed_pc=0x0c0b0056u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0b0058;
P_0c0b0058: /* original 8b29, guest PC 0x0c0b0058 */
if(!s->budget--) { s->failed_pc=0x0c0b0058u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b00ae; }
goto P_0c0b005a;
P_0c0b005a: /* original d226, guest PC 0x0c0b005a */
if(!s->budget--) { s->failed_pc=0x0c0b005au; return 0; }
r[2]=read(ram,0x0c0b00f4u,4);
goto P_0c0b005c;
P_0c0b005c: /* original 2268, guest PC 0x0c0b005c */
if(!s->budget--) { s->failed_pc=0x0c0b005cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0b005e;
P_0c0b005e: /* original 8b26, guest PC 0x0c0b005e */
if(!s->budget--) { s->failed_pc=0x0c0b005eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b00ae; }
goto P_0c0b0060;
P_0c0b0060: /* original e066, guest PC 0x0c0b0060 */
if(!s->budget--) { s->failed_pc=0x0c0b0060u; return 0; }
r[0]=0x00000066u;
goto P_0c0b0062;
P_0c0b0062: /* original 034d, guest PC 0x0c0b0062 */
if(!s->budget--) { s->failed_pc=0x0c0b0062u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b0064;
P_0c0b0064: /* original 4315, guest PC 0x0c0b0064 */
if(!s->budget--) { s->failed_pc=0x0c0b0064u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0b0066;
P_0c0b0066: /* original 8922, guest PC 0x0c0b0066 */
if(!s->budget--) { s->failed_pc=0x0c0b0066u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00ae; }
goto P_0c0b0068;
P_0c0b0068: /* original e03e, guest PC 0x0c0b0068 */
if(!s->budget--) { s->failed_pc=0x0c0b0068u; return 0; }
r[0]=0x0000003eu;
goto P_0c0b006a;
P_0c0b006a: /* original 034d, guest PC 0x0c0b006a */
if(!s->budget--) { s->failed_pc=0x0c0b006au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b006c;
P_0c0b006c: /* original 633d, guest PC 0x0c0b006c */
if(!s->budget--) { s->failed_pc=0x0c0b006cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0b006e;
P_0c0b006e: /* original 1f32, guest PC 0x0c0b006e */
if(!s->budget--) { s->failed_pc=0x0c0b006eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0b0070;
P_0c0b0070: /* original 9034, guest PC 0x0c0b0070 */
if(!s->budget--) { s->failed_pc=0x0c0b0070u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00dcu,2);
goto P_0c0b0072;
P_0c0b0072: /* original 024d, guest PC 0x0c0b0072 */
if(!s->budget--) { s->failed_pc=0x0c0b0072u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b0074;
P_0c0b0074: /* original 2f22, guest PC 0x0c0b0074 */
if(!s->budget--) { s->failed_pc=0x0c0b0074u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b0076;
P_0c0b0076: /* original 902e, guest PC 0x0c0b0076 */
if(!s->budget--) { s->failed_pc=0x0c0b0076u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d6u,2);
goto P_0c0b0078;
P_0c0b0078: /* original 034e, guest PC 0x0c0b0078 */
if(!s->budget--) { s->failed_pc=0x0c0b0078u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0b007a;
P_0c0b007a: /* original 1f33, guest PC 0x0c0b007a */
if(!s->budget--) { s->failed_pc=0x0c0b007au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0b007c;
P_0c0b007c: /* original e300, guest PC 0x0c0b007c */
if(!s->budget--) { s->failed_pc=0x0c0b007cu; return 0; }
r[3]=0x00000000u;
goto P_0c0b007e;
P_0c0b007e: /* original 902e, guest PC 0x0c0b007e */
if(!s->budget--) { s->failed_pc=0x0c0b007eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00deu,2);
goto P_0c0b0080;
P_0c0b0080: /* original 024d, guest PC 0x0c0b0080 */
if(!s->budget--) { s->failed_pc=0x0c0b0080u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b0082;
P_0c0b0082: /* original 622d, guest PC 0x0c0b0082 */
if(!s->budget--) { s->failed_pc=0x0c0b0082u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0b0084;
P_0c0b0084: /* original 1f21, guest PC 0x0c0b0084 */
if(!s->budget--) { s->failed_pc=0x0c0b0084u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0b0086;
P_0c0b0086: /* original 61f2, guest PC 0x0c0b0086 */
if(!s->budget--) { s->failed_pc=0x0c0b0086u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0b0088;
P_0c0b0088: /* original 3136, guest PC 0x0c0b0088 */
if(!s->budget--) { s->failed_pc=0x0c0b0088u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c0b008a;
P_0c0b008a: /* original 8910, guest PC 0x0c0b008a */
if(!s->budget--) { s->failed_pc=0x0c0b008au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00ae; }
goto P_0c0b008c;
P_0c0b008c: /* original 52f3, guest PC 0x0c0b008c */
if(!s->budget--) { s->failed_pc=0x0c0b008cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0b008e;
P_0c0b008e: /* original d318, guest PC 0x0c0b008e */
if(!s->budget--) { s->failed_pc=0x0c0b008eu; return 0; }
r[3]=read(ram,0x0c0b00f0u,4);
goto P_0c0b0090;
P_0c0b0090: /* original 2238, guest PC 0x0c0b0090 */
if(!s->budget--) { s->failed_pc=0x0c0b0090u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0b0092;
P_0c0b0092: /* original 8b03, guest PC 0x0c0b0092 */
if(!s->budget--) { s->failed_pc=0x0c0b0092u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b009c; }
goto P_0c0b0094;
P_0c0b0094: /* original 53f2, guest PC 0x0c0b0094 */
if(!s->budget--) { s->failed_pc=0x0c0b0094u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0b0096;
P_0c0b0096: /* original 51f1, guest PC 0x0c0b0096 */
if(!s->budget--) { s->failed_pc=0x0c0b0096u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0b0098;
P_0c0b0098: /* original 3310, guest PC 0x0c0b0098 */
if(!s->budget--) { s->failed_pc=0x0c0b0098u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0b009a;
P_0c0b009a: /* original 8908, guest PC 0x0c0b009a */
if(!s->budget--) { s->failed_pc=0x0c0b009au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00ae; }
goto P_0c0b009c;
P_0c0b009c: /* original 9020, guest PC 0x0c0b009c */
if(!s->budget--) { s->failed_pc=0x0c0b009cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00e0u,2);
goto P_0c0b009e;
P_0c0b009e: /* original ee00, guest PC 0x0c0b009e */
if(!s->budget--) { s->failed_pc=0x0c0b009eu; return 0; }
r[14]=0x00000000u;
goto P_0c0b00a0;
P_0c0b00a0: /* original 04e4, guest PC 0x0c0b00a0 */
if(!s->budget--) { s->failed_pc=0x0c0b00a0u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0b00a2;
P_0c0b00a2: /* original 901e, guest PC 0x0c0b00a2 */
if(!s->budget--) { s->failed_pc=0x0c0b00a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00e2u,2);
goto P_0c0b00a4;
P_0c0b00a4: /* original 04e4, guest PC 0x0c0b00a4 */
if(!s->budget--) { s->failed_pc=0x0c0b00a4u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0b00a6;
P_0c0b00a6: /* original 703f, guest PC 0x0c0b00a6 */
if(!s->budget--) { s->failed_pc=0x0c0b00a6u; return 0; }
r[0]+=0x0000003fu;
goto P_0c0b00a8;
P_0c0b00a8: /* original 04e4, guest PC 0x0c0b00a8 */
if(!s->budget--) { s->failed_pc=0x0c0b00a8u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0b00aa;
P_0c0b00aa: /* original 901b, guest PC 0x0c0b00aa */
if(!s->budget--) { s->failed_pc=0x0c0b00aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00e4u,2);
goto P_0c0b00ac;
P_0c0b00ac: /* original 04e4, guest PC 0x0c0b00ac */
if(!s->budget--) { s->failed_pc=0x0c0b00acu; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0b00ae;
P_0c0b00ae: /* original 9012, guest PC 0x0c0b00ae */
if(!s->budget--) { s->failed_pc=0x0c0b00aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b00d6u,2);
goto P_0c0b00b0;
P_0c0b00b0: /* original 034e, guest PC 0x0c0b00b0 */
if(!s->budget--) { s->failed_pc=0x0c0b00b0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0b00b2;
P_0c0b00b2: /* original 2378, guest PC 0x0c0b00b2 */
if(!s->budget--) { s->failed_pc=0x0c0b00b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0b00b4;
P_0c0b00b4: /* original 8908, guest PC 0x0c0b00b4 */
if(!s->budget--) { s->failed_pc=0x0c0b00b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00c8; }
goto P_0c0b00b6;
P_0c0b00b6: /* original d210, guest PC 0x0c0b00b6 */
if(!s->budget--) { s->failed_pc=0x0c0b00b6u; return 0; }
r[2]=read(ram,0x0c0b00f8u,4);
goto P_0c0b00b8;
P_0c0b00b8: /* original 2258, guest PC 0x0c0b00b8 */
if(!s->budget--) { s->failed_pc=0x0c0b00b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0b00ba;
P_0c0b00ba: /* original 8905, guest PC 0x0c0b00ba */
if(!s->budget--) { s->failed_pc=0x0c0b00bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b00c8; }
goto P_0c0b00bc;
P_0c0b00bc: /* original 2758, guest PC 0x0c0b00bc */
if(!s->budget--) { s->failed_pc=0x0c0b00bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[5])==0)!=0);
goto P_0c0b00be;
P_0c0b00be: /* original 8b03, guest PC 0x0c0b00be */
if(!s->budget--) { s->failed_pc=0x0c0b00beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b00c8; }
goto P_0c0b00c0;
P_0c0b00c0: /* original d30e, guest PC 0x0c0b00c0 */
if(!s->budget--) { s->failed_pc=0x0c0b00c0u; return 0; }
r[3]=read(ram,0x0c0b00fcu,4);
goto P_0c0b00c2;
P_0c0b00c2: /* original e048, guest PC 0x0c0b00c2 */
if(!s->budget--) { s->failed_pc=0x0c0b00c2u; return 0; }
r[0]=0x00000048u;
goto P_0c0b00c4;
P_0c0b00c4: /* original 2539, guest PC 0x0c0b00c4 */
if(!s->budget--) { s->failed_pc=0x0c0b00c4u; return 0; }
r[5]&=r[3];
goto P_0c0b00c6;
P_0c0b00c6: /* original 0456, guest PC 0x0c0b00c6 */
if(!s->budget--) { s->failed_pc=0x0c0b00c6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0b00c8;
P_0c0b00c8: /* original 7f10, guest PC 0x0c0b00c8 */
if(!s->budget--) { s->failed_pc=0x0c0b00c8u; return 0; }
r[15]+=0x00000010u;
goto P_0c0b00ca;
P_0c0b00ca: /* original 2462, guest PC 0x0c0b00ca */
if(!s->budget--) { s->failed_pc=0x0c0b00cau; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0b00cc;
P_0c0b00cc: /* original 6bf6, guest PC 0x0c0b00cc */
if(!s->budget--) { s->failed_pc=0x0c0b00ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b00ce;
P_0c0b00ce: /* original 6cf6, guest PC 0x0c0b00ce */
if(!s->budget--) { s->failed_pc=0x0c0b00ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b00d0;
P_0c0b00d0: /* original 6df6, guest PC 0x0c0b00d0 */
if(!s->budget--) { s->failed_pc=0x0c0b00d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b00d2;
P_0c0b00d2: /* original 000b, guest PC 0x0c0b00d2 */
if(!s->budget--) { s->failed_pc=0x0c0b00d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b00d4: /* original 6ef6, guest PC 0x0c0b00d4 */
if(!s->budget--) { s->failed_pc=0x0c0b00d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b00d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b00d6u; return 0; } return 1;
P_0c0b1464: /* original 2fe6, guest PC 0x0c0b1464 */
if(!s->budget--) { s->failed_pc=0x0c0b1464u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1466;
P_0c0b1466: /* original 6e53, guest PC 0x0c0b1466 */
if(!s->budget--) { s->failed_pc=0x0c0b1466u; return 0; }
r[14]=r[5];
goto P_0c0b1468;
P_0c0b1468: /* original 2fd6, guest PC 0x0c0b1468 */
if(!s->budget--) { s->failed_pc=0x0c0b1468u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b146a;
P_0c0b146a: /* original ed01, guest PC 0x0c0b146a */
if(!s->budget--) { s->failed_pc=0x0c0b146au; return 0; }
r[13]=0x00000001u;
goto P_0c0b146c;
P_0c0b146c: /* original 2fc6, guest PC 0x0c0b146c */
if(!s->budget--) { s->failed_pc=0x0c0b146cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b146e;
P_0c0b146e: /* original 905a, guest PC 0x0c0b146e */
if(!s->budget--) { s->failed_pc=0x0c0b146eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1526u,2);
goto P_0c0b1470;
P_0c0b1470: /* original 4f22, guest PC 0x0c0b1470 */
if(!s->budget--) { s->failed_pc=0x0c0b1470u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1472;
P_0c0b1472: /* original 034c, guest PC 0x0c0b1472 */
if(!s->budget--) { s->failed_pc=0x0c0b1472u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b1474;
P_0c0b1474: /* original dc2f, guest PC 0x0c0b1474 */
if(!s->budget--) { s->failed_pc=0x0c0b1474u; return 0; }
r[12]=read(ram,0x0c0b1534u,4);
goto P_0c0b1476;
P_0c0b1476: /* original 633c, guest PC 0x0c0b1476 */
if(!s->budget--) { s->failed_pc=0x0c0b1476u; return 0; }
r[3]=r[3]&255u;
goto P_0c0b1478;
P_0c0b1478: /* original 33d3, guest PC 0x0c0b1478 */
if(!s->budget--) { s->failed_pc=0x0c0b1478u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[13])!=0);
goto P_0c0b147a;
P_0c0b147a: /* original 8d07, guest PC 0x0c0b147a */
if(!s->budget--) { s->failed_pc=0x0c0b147au; return 0; }
cond=r[17]&1u;
r[5]=r[6];
if(cond) { goto P_0c0b148c; }
goto P_0c0b147e;
P_0c0b147c: /* original 6563, guest PC 0x0c0b147c */
if(!s->budget--) { s->failed_pc=0x0c0b147cu; return 0; }
r[5]=r[6];
goto P_0c0b147e;
P_0c0b147e: /* original 9053, guest PC 0x0c0b147e */
if(!s->budget--) { s->failed_pc=0x0c0b147eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1528u,2);
goto P_0c0b1480;
P_0c0b1480: /* original 034c, guest PC 0x0c0b1480 */
if(!s->budget--) { s->failed_pc=0x0c0b1480u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b1482;
P_0c0b1482: /* original 633c, guest PC 0x0c0b1482 */
if(!s->budget--) { s->failed_pc=0x0c0b1482u; return 0; }
r[3]=r[3]&255u;
goto P_0c0b1484;
P_0c0b1484: /* original 33d3, guest PC 0x0c0b1484 */
if(!s->budget--) { s->failed_pc=0x0c0b1484u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[13])!=0);
goto P_0c0b1486;
P_0c0b1486: /* original 8901, guest PC 0x0c0b1486 */
if(!s->budget--) { s->failed_pc=0x0c0b1486u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b148c; }
goto P_0c0b1488;
P_0c0b1488: /* original 37d6, guest PC 0x0c0b1488 */
if(!s->budget--) { s->failed_pc=0x0c0b1488u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[13])!=0);
goto P_0c0b148a;
P_0c0b148a: /* original 8b03, guest PC 0x0c0b148a */
if(!s->budget--) { s->failed_pc=0x0c0b148au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1494; }
goto P_0c0b148c;
P_0c0b148c: /* original 904d, guest PC 0x0c0b148c */
if(!s->budget--) { s->failed_pc=0x0c0b148cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152au,2);
goto P_0c0b148e;
P_0c0b148e: /* original 05ed, guest PC 0x0c0b148e */
if(!s->budget--) { s->failed_pc=0x0c0b148eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0b1490;
P_0c0b1490: /* original 655d, guest PC 0x0c0b1490 */
if(!s->budget--) { s->failed_pc=0x0c0b1490u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0b1492;
P_0c0b1492: /* original 356c, guest PC 0x0c0b1492 */
if(!s->budget--) { s->failed_pc=0x0c0b1492u; return 0; }
r[5]+=r[6];
goto P_0c0b1494;
P_0c0b1494: /* original 9049, guest PC 0x0c0b1494 */
if(!s->budget--) { s->failed_pc=0x0c0b1494u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152au,2);
goto P_0c0b1496;
P_0c0b1496: /* original 0e55, guest PC 0x0c0b1496 */
if(!s->budget--) { s->failed_pc=0x0c0b1496u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0b1498;
P_0c0b1498: /* original 67c2, guest PC 0x0c0b1498 */
if(!s->budget--) { s->failed_pc=0x0c0b1498u; return 0; }
tmp=read(ram,r[12],4);
r[7]=tmp;
goto P_0c0b149a;
P_0c0b149a: /* original 9347, guest PC 0x0c0b149a */
if(!s->budget--) { s->failed_pc=0x0c0b149au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152cu,2);
goto P_0c0b149c;
P_0c0b149c: /* original 2378, guest PC 0x0c0b149c */
if(!s->budget--) { s->failed_pc=0x0c0b149cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0b149e;
P_0c0b149e: /* original 8f3a, guest PC 0x0c0b149e */
if(!s->budget--) { s->failed_pc=0x0c0b149eu; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[12]+4,4);
if(!cond) { goto P_0c0b1516; }
goto P_0c0b14a2;
P_0c0b14a0: /* original 56c1, guest PC 0x0c0b14a0 */
if(!s->budget--) { s->failed_pc=0x0c0b14a0u; return 0; }
r[6]=read(ram,r[12]+4,4);
goto P_0c0b14a2;
P_0c0b14a2: /* original d125, guest PC 0x0c0b14a2 */
if(!s->budget--) { s->failed_pc=0x0c0b14a2u; return 0; }
r[1]=read(ram,0x0c0b1538u,4);
goto P_0c0b14a4;
P_0c0b14a4: /* original 2718, guest PC 0x0c0b14a4 */
if(!s->budget--) { s->failed_pc=0x0c0b14a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[1])==0)!=0);
goto P_0c0b14a6;
P_0c0b14a6: /* original 8936, guest PC 0x0c0b14a6 */
if(!s->budget--) { s->failed_pc=0x0c0b14a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1516; }
goto P_0c0b14a8;
P_0c0b14a8: /* original d324, guest PC 0x0c0b14a8 */
if(!s->budget--) { s->failed_pc=0x0c0b14a8u; return 0; }
r[3]=read(ram,0x0c0b153cu,4);
goto P_0c0b14aa;
P_0c0b14aa: /* original 2638, guest PC 0x0c0b14aa */
if(!s->budget--) { s->failed_pc=0x0c0b14aau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0b14ac;
P_0c0b14ac: /* original 8933, guest PC 0x0c0b14ac */
if(!s->budget--) { s->failed_pc=0x0c0b14acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1516; }
goto P_0c0b14ae;
P_0c0b14ae: /* original d224, guest PC 0x0c0b14ae */
if(!s->budget--) { s->failed_pc=0x0c0b14aeu; return 0; }
r[2]=read(ram,0x0c0b1540u,4);
goto P_0c0b14b0;
P_0c0b14b0: /* original 6020, guest PC 0x0c0b14b0 */
if(!s->budget--) { s->failed_pc=0x0c0b14b0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0b14b2;
P_0c0b14b2: /* original 600c, guest PC 0x0c0b14b2 */
if(!s->budget--) { s->failed_pc=0x0c0b14b2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0b14b4;
P_0c0b14b4: /* original 8803, guest PC 0x0c0b14b4 */
if(!s->budget--) { s->failed_pc=0x0c0b14b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0b14b6;
P_0c0b14b6: /* original 8b2e, guest PC 0x0c0b14b6 */
if(!s->budget--) { s->failed_pc=0x0c0b14b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1516; }
goto P_0c0b14b8;
P_0c0b14b8: /* original e061, guest PC 0x0c0b14b8 */
if(!s->budget--) { s->failed_pc=0x0c0b14b8u; return 0; }
r[0]=0x00000061u;
goto P_0c0b14ba;
P_0c0b14ba: /* original 9338, guest PC 0x0c0b14ba */
if(!s->budget--) { s->failed_pc=0x0c0b14bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152eu,2);
goto P_0c0b14bc;
P_0c0b14bc: /* original 06ec, guest PC 0x0c0b14bc */
if(!s->budget--) { s->failed_pc=0x0c0b14bcu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b14be;
P_0c0b14be: /* original dd21, guest PC 0x0c0b14be */
if(!s->budget--) { s->failed_pc=0x0c0b14beu; return 0; }
r[13]=read(ram,0x0c0b1544u,4);
goto P_0c0b14c0;
P_0c0b14c0: /* original 666c, guest PC 0x0c0b14c0 */
if(!s->budget--) { s->failed_pc=0x0c0b14c0u; return 0; }
r[6]=r[6]&255u;
goto P_0c0b14c2;
P_0c0b14c2: /* original 33dc, guest PC 0x0c0b14c2 */
if(!s->budget--) { s->failed_pc=0x0c0b14c2u; return 0; }
r[3]+=r[13];
goto P_0c0b14c4;
P_0c0b14c4: /* original 4608, guest PC 0x0c0b14c4 */
if(!s->budget--) { s->failed_pc=0x0c0b14c4u; return 0; }
r[6]<<=2;
goto P_0c0b14c6;
P_0c0b14c6: /* original 363c, guest PC 0x0c0b14c6 */
if(!s->budget--) { s->failed_pc=0x0c0b14c6u; return 0; }
r[6]+=r[3];
goto P_0c0b14c8;
P_0c0b14c8: /* original 6662, guest PC 0x0c0b14c8 */
if(!s->budget--) { s->failed_pc=0x0c0b14c8u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0b14ca;
P_0c0b14ca: /* original 3653, guest PC 0x0c0b14ca */
if(!s->budget--) { s->failed_pc=0x0c0b14cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c0b14cc;
P_0c0b14cc: /* original 8906, guest PC 0x0c0b14cc */
if(!s->budget--) { s->failed_pc=0x0c0b14ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b14dc; }
goto P_0c0b14ce;
P_0c0b14ce: /* original 02ec, guest PC 0x0c0b14ce */
if(!s->budget--) { s->failed_pc=0x0c0b14ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b14d0;
P_0c0b14d0: /* original 932d, guest PC 0x0c0b14d0 */
if(!s->budget--) { s->failed_pc=0x0c0b14d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152eu,2);
goto P_0c0b14d2;
P_0c0b14d2: /* original 622c, guest PC 0x0c0b14d2 */
if(!s->budget--) { s->failed_pc=0x0c0b14d2u; return 0; }
r[2]=r[2]&255u;
goto P_0c0b14d4;
P_0c0b14d4: /* original 33dc, guest PC 0x0c0b14d4 */
if(!s->budget--) { s->failed_pc=0x0c0b14d4u; return 0; }
r[3]+=r[13];
goto P_0c0b14d6;
P_0c0b14d6: /* original 4208, guest PC 0x0c0b14d6 */
if(!s->budget--) { s->failed_pc=0x0c0b14d6u; return 0; }
r[2]<<=2;
goto P_0c0b14d8;
P_0c0b14d8: /* original 323c, guest PC 0x0c0b14d8 */
if(!s->budget--) { s->failed_pc=0x0c0b14d8u; return 0; }
r[2]+=r[3];
goto P_0c0b14da;
P_0c0b14da: /* original 2252, guest PC 0x0c0b14da */
if(!s->budget--) { s->failed_pc=0x0c0b14dau; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0b14dc;
P_0c0b14dc: /* original 9023, guest PC 0x0c0b14dc */
if(!s->budget--) { s->failed_pc=0x0c0b14dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1526u,2);
goto P_0c0b14de;
P_0c0b14de: /* original 9328, guest PC 0x0c0b14de */
if(!s->budget--) { s->failed_pc=0x0c0b14deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1532u,2);
goto P_0c0b14e0;
P_0c0b14e0: /* original 0c4c, guest PC 0x0c0b14e0 */
if(!s->budget--) { s->failed_pc=0x0c0b14e0u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b14e2;
P_0c0b14e2: /* original 9025, guest PC 0x0c0b14e2 */
if(!s->budget--) { s->failed_pc=0x0c0b14e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1530u,2);
goto P_0c0b14e4;
P_0c0b14e4: /* original 33dc, guest PC 0x0c0b14e4 */
if(!s->budget--) { s->failed_pc=0x0c0b14e4u; return 0; }
r[3]+=r[13];
goto P_0c0b14e6;
P_0c0b14e6: /* original 6ccc, guest PC 0x0c0b14e6 */
if(!s->budget--) { s->failed_pc=0x0c0b14e6u; return 0; }
r[12]=r[12]&255u;
goto P_0c0b14e8;
P_0c0b14e8: /* original d217, guest PC 0x0c0b14e8 */
if(!s->budget--) { s->failed_pc=0x0c0b14e8u; return 0; }
r[2]=read(ram,0x0c0b1548u,4);
goto P_0c0b14ea;
P_0c0b14ea: /* original 044c, guest PC 0x0c0b14ea */
if(!s->budget--) { s->failed_pc=0x0c0b14eau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b14ec;
P_0c0b14ec: /* original e061, guest PC 0x0c0b14ec */
if(!s->budget--) { s->failed_pc=0x0c0b14ecu; return 0; }
r[0]=0x00000061u;
goto P_0c0b14ee;
P_0c0b14ee: /* original 644c, guest PC 0x0c0b14ee */
if(!s->budget--) { s->failed_pc=0x0c0b14eeu; return 0; }
r[4]=r[4]&255u;
goto P_0c0b14f0;
P_0c0b14f0: /* original 3c4c, guest PC 0x0c0b14f0 */
if(!s->budget--) { s->failed_pc=0x0c0b14f0u; return 0; }
r[12]+=r[4];
goto P_0c0b14f2;
P_0c0b14f2: /* original 04ec, guest PC 0x0c0b14f2 */
if(!s->budget--) { s->failed_pc=0x0c0b14f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b14f4;
P_0c0b14f4: /* original 644c, guest PC 0x0c0b14f4 */
if(!s->budget--) { s->failed_pc=0x0c0b14f4u; return 0; }
r[4]=r[4]&255u;
goto P_0c0b14f6;
P_0c0b14f6: /* original 4408, guest PC 0x0c0b14f6 */
if(!s->budget--) { s->failed_pc=0x0c0b14f6u; return 0; }
r[4]<<=2;
goto P_0c0b14f8;
P_0c0b14f8: /* original 420b, guest PC 0x0c0b14f8 */
if(!s->budget--) { s->failed_pc=0x0c0b14f8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b14fcu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b14fcu) { target=s->pc; goto dispatch; }
goto P_0c0b14fc;
P_0c0b14fa: /* original 343c, guest PC 0x0c0b14fa */
if(!s->budget--) { s->failed_pc=0x0c0b14fau; return 0; }
r[4]+=r[3];
goto P_0c0b14fc;
P_0c0b14fc: /* original 6403, guest PC 0x0c0b14fc */
if(!s->budget--) { s->failed_pc=0x0c0b14fcu; return 0; }
r[4]=r[0];
goto P_0c0b14fe;
P_0c0b14fe: /* original 34c3, guest PC 0x0c0b14fe */
if(!s->budget--) { s->failed_pc=0x0c0b14feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c0b1500;
P_0c0b1500: /* original 8909, guest PC 0x0c0b1500 */
if(!s->budget--) { s->failed_pc=0x0c0b1500u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1516; }
goto P_0c0b1502;
P_0c0b1502: /* original e061, guest PC 0x0c0b1502 */
if(!s->budget--) { s->failed_pc=0x0c0b1502u; return 0; }
r[0]=0x00000061u;
goto P_0c0b1504;
P_0c0b1504: /* original 9315, guest PC 0x0c0b1504 */
if(!s->budget--) { s->failed_pc=0x0c0b1504u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1532u,2);
goto P_0c0b1506;
P_0c0b1506: /* original 04ec, guest PC 0x0c0b1506 */
if(!s->budget--) { s->failed_pc=0x0c0b1506u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b1508;
P_0c0b1508: /* original 65c3, guest PC 0x0c0b1508 */
if(!s->budget--) { s->failed_pc=0x0c0b1508u; return 0; }
r[5]=r[12];
goto P_0c0b150a;
P_0c0b150a: /* original d210, guest PC 0x0c0b150a */
if(!s->budget--) { s->failed_pc=0x0c0b150au; return 0; }
r[2]=read(ram,0x0c0b154cu,4);
goto P_0c0b150c;
P_0c0b150c: /* original 33dc, guest PC 0x0c0b150c */
if(!s->budget--) { s->failed_pc=0x0c0b150cu; return 0; }
r[3]+=r[13];
goto P_0c0b150e;
P_0c0b150e: /* original 644c, guest PC 0x0c0b150e */
if(!s->budget--) { s->failed_pc=0x0c0b150eu; return 0; }
r[4]=r[4]&255u;
goto P_0c0b1510;
P_0c0b1510: /* original 4408, guest PC 0x0c0b1510 */
if(!s->budget--) { s->failed_pc=0x0c0b1510u; return 0; }
r[4]<<=2;
goto P_0c0b1512;
P_0c0b1512: /* original 420b, guest PC 0x0c0b1512 */
if(!s->budget--) { s->failed_pc=0x0c0b1512u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1516u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1516u) { target=s->pc; goto dispatch; }
goto P_0c0b1516;
P_0c0b1514: /* original 343c, guest PC 0x0c0b1514 */
if(!s->budget--) { s->failed_pc=0x0c0b1514u; return 0; }
r[4]+=r[3];
goto P_0c0b1516;
P_0c0b1516: /* original 4f26, guest PC 0x0c0b1516 */
if(!s->budget--) { s->failed_pc=0x0c0b1516u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1518;
P_0c0b1518: /* original 6cf6, guest PC 0x0c0b1518 */
if(!s->budget--) { s->failed_pc=0x0c0b1518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b151a;
P_0c0b151a: /* original 6df6, guest PC 0x0c0b151a */
if(!s->budget--) { s->failed_pc=0x0c0b151au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b151c;
P_0c0b151c: /* original 000b, guest PC 0x0c0b151c */
if(!s->budget--) { s->failed_pc=0x0c0b151cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b151e: /* original 6ef6, guest PC 0x0c0b151e */
if(!s->budget--) { s->failed_pc=0x0c0b151eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1520u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1520u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
