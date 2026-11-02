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
int vf3_away_batch3_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03fda0u: goto P_0c03fda0;
case 0x0c03fda2u: goto P_0c03fda2;
case 0x0c03fda4u: goto P_0c03fda4;
case 0x0c03fda6u: goto P_0c03fda6;
case 0x0c03fda8u: goto P_0c03fda8;
case 0x0c03fdaau: goto P_0c03fdaa;
case 0x0c03fdacu: goto P_0c03fdac;
case 0x0c03fdaeu: goto P_0c03fdae;
case 0x0c03fdb0u: goto P_0c03fdb0;
case 0x0c03fdb2u: goto P_0c03fdb2;
case 0x0c03fdb4u: goto P_0c03fdb4;
case 0x0c03fdb6u: goto P_0c03fdb6;
case 0x0c03fdb8u: goto P_0c03fdb8;
case 0x0c03fdbau: goto P_0c03fdba;
case 0x0c03fdbcu: goto P_0c03fdbc;
case 0x0c03fdd0u: goto P_0c03fdd0;
case 0x0c03fdd2u: goto P_0c03fdd2;
case 0x0c03fdd4u: goto P_0c03fdd4;
case 0x0c03fdd6u: goto P_0c03fdd6;
case 0x0c03fdd8u: goto P_0c03fdd8;
case 0x0c03fddau: goto P_0c03fdda;
case 0x0c03fddcu: goto P_0c03fddc;
case 0x0c03fddeu: goto P_0c03fdde;
case 0x0c03fde0u: goto P_0c03fde0;
case 0x0c03fde2u: goto P_0c03fde2;
case 0x0c03fde4u: goto P_0c03fde4;
case 0x0c03fde6u: goto P_0c03fde6;
case 0x0c03fde8u: goto P_0c03fde8;
case 0x0c03fdeau: goto P_0c03fdea;
case 0x0c03fdecu: goto P_0c03fdec;
case 0x0c03fdf0u: goto P_0c03fdf0;
case 0x0c03fdf2u: goto P_0c03fdf2;
case 0x0c03fe30u: goto P_0c03fe30;
case 0x0c03fe32u: goto P_0c03fe32;
case 0x0c03fe34u: goto P_0c03fe34;
case 0x0c03fe36u: goto P_0c03fe36;
case 0x0c03fe38u: goto P_0c03fe38;
case 0x0c03fe3au: goto P_0c03fe3a;
case 0x0c03fe3cu: goto P_0c03fe3c;
case 0x0c03fe3eu: goto P_0c03fe3e;
case 0x0c03fe40u: goto P_0c03fe40;
case 0x0c03fe42u: goto P_0c03fe42;
case 0x0c03fe44u: goto P_0c03fe44;
case 0x0c03fe46u: goto P_0c03fe46;
case 0x0c03fe48u: goto P_0c03fe48;
case 0x0c03fe4au: goto P_0c03fe4a;
case 0x0c03fe4cu: goto P_0c03fe4c;
case 0x0c03fe4eu: goto P_0c03fe4e;
case 0x0c03fe50u: goto P_0c03fe50;
case 0x0c03fe52u: goto P_0c03fe52;
case 0x0c03fe54u: goto P_0c03fe54;
case 0x0c040498u: goto P_0c040498;
case 0x0c04049au: goto P_0c04049a;
case 0x0c04049cu: goto P_0c04049c;
case 0x0c04049eu: goto P_0c04049e;
case 0x0c0404a0u: goto P_0c0404a0;
case 0x0c0404a2u: goto P_0c0404a2;
case 0x0c0404a4u: goto P_0c0404a4;
case 0x0c0404a6u: goto P_0c0404a6;
case 0x0c0404a8u: goto P_0c0404a8;
case 0x0c0404aau: goto P_0c0404aa;
case 0x0c0404acu: goto P_0c0404ac;
case 0x0c0404aeu: goto P_0c0404ae;
case 0x0c0404b0u: goto P_0c0404b0;
case 0x0c0404b2u: goto P_0c0404b2;
case 0x0c0404b4u: goto P_0c0404b4;
case 0x0c0404b6u: goto P_0c0404b6;
case 0x0c0404b8u: goto P_0c0404b8;
case 0x0c0404bau: goto P_0c0404ba;
case 0x0c0404bcu: goto P_0c0404bc;
case 0x0c0404beu: goto P_0c0404be;
case 0x0c0404c0u: goto P_0c0404c0;
case 0x0c0404c2u: goto P_0c0404c2;
case 0x0c0404c4u: goto P_0c0404c4;
case 0x0c0404c6u: goto P_0c0404c6;
case 0x0c0404c8u: goto P_0c0404c8;
case 0x0c0404cau: goto P_0c0404ca;
case 0x0c0404ccu: goto P_0c0404cc;
case 0x0c0404ceu: goto P_0c0404ce;
case 0x0c0404d0u: goto P_0c0404d0;
case 0x0c0404d2u: goto P_0c0404d2;
case 0x0c0404d4u: goto P_0c0404d4;
case 0x0c0404d6u: goto P_0c0404d6;
case 0x0c0404d8u: goto P_0c0404d8;
case 0x0c0404dau: goto P_0c0404da;
case 0x0c0404dcu: goto P_0c0404dc;
case 0x0c0404deu: goto P_0c0404de;
case 0x0c0404e0u: goto P_0c0404e0;
case 0x0c0404e2u: goto P_0c0404e2;
case 0x0c0404e4u: goto P_0c0404e4;
case 0x0c0404e6u: goto P_0c0404e6;
case 0x0c0404e8u: goto P_0c0404e8;
case 0x0c0404eau: goto P_0c0404ea;
case 0x0c0404ecu: goto P_0c0404ec;
case 0x0c0404eeu: goto P_0c0404ee;
case 0x0c0404f0u: goto P_0c0404f0;
case 0x0c0404f2u: goto P_0c0404f2;
case 0x0c0404f4u: goto P_0c0404f4;
case 0x0c0404f6u: goto P_0c0404f6;
case 0x0c0404f8u: goto P_0c0404f8;
case 0x0c0404fau: goto P_0c0404fa;
case 0x0c0404fcu: goto P_0c0404fc;
case 0x0c0404feu: goto P_0c0404fe;
case 0x0c040500u: goto P_0c040500;
case 0x0c040502u: goto P_0c040502;
case 0x0c040504u: goto P_0c040504;
case 0x0c040506u: goto P_0c040506;
case 0x0c040508u: goto P_0c040508;
case 0x0c04050au: goto P_0c04050a;
case 0x0c04050cu: goto P_0c04050c;
case 0x0c04050eu: goto P_0c04050e;
case 0x0c040510u: goto P_0c040510;
case 0x0c040512u: goto P_0c040512;
case 0x0c040514u: goto P_0c040514;
case 0x0c040516u: goto P_0c040516;
case 0x0c040518u: goto P_0c040518;
case 0x0c04051au: goto P_0c04051a;
case 0x0c04051cu: goto P_0c04051c;
case 0x0c04051eu: goto P_0c04051e;
case 0x0c040520u: goto P_0c040520;
case 0x0c040522u: goto P_0c040522;
case 0x0c040524u: goto P_0c040524;
case 0x0c040526u: goto P_0c040526;
case 0x0c040528u: goto P_0c040528;
case 0x0c040558u: goto P_0c040558;
case 0x0c04055au: goto P_0c04055a;
case 0x0c04055cu: goto P_0c04055c;
case 0x0c04055eu: goto P_0c04055e;
case 0x0c040560u: goto P_0c040560;
case 0x0c040562u: goto P_0c040562;
case 0x0c040564u: goto P_0c040564;
case 0x0c040566u: goto P_0c040566;
case 0x0c040568u: goto P_0c040568;
case 0x0c04056au: goto P_0c04056a;
case 0x0c04056cu: goto P_0c04056c;
case 0x0c04056eu: goto P_0c04056e;
case 0x0c040570u: goto P_0c040570;
case 0x0c040572u: goto P_0c040572;
case 0x0c040574u: goto P_0c040574;
case 0x0c040576u: goto P_0c040576;
case 0x0c040578u: goto P_0c040578;
case 0x0c04057au: goto P_0c04057a;
case 0x0c04057cu: goto P_0c04057c;
case 0x0c04057eu: goto P_0c04057e;
case 0x0c040580u: goto P_0c040580;
case 0x0c040582u: goto P_0c040582;
case 0x0c040584u: goto P_0c040584;
case 0x0c040586u: goto P_0c040586;
case 0x0c040588u: goto P_0c040588;
case 0x0c04058au: goto P_0c04058a;
case 0x0c04058cu: goto P_0c04058c;
case 0x0c04058eu: goto P_0c04058e;
case 0x0c040590u: goto P_0c040590;
case 0x0c040592u: goto P_0c040592;
case 0x0c040594u: goto P_0c040594;
case 0x0c040596u: goto P_0c040596;
case 0x0c040598u: goto P_0c040598;
case 0x0c04059au: goto P_0c04059a;
case 0x0c04059cu: goto P_0c04059c;
case 0x0c04059eu: goto P_0c04059e;
case 0x0c0405a0u: goto P_0c0405a0;
case 0x0c0405a2u: goto P_0c0405a2;
case 0x0c0405a4u: goto P_0c0405a4;
case 0x0c0405a6u: goto P_0c0405a6;
case 0x0c0405a8u: goto P_0c0405a8;
case 0x0c0405aau: goto P_0c0405aa;
case 0x0c0405acu: goto P_0c0405ac;
case 0x0c0405aeu: goto P_0c0405ae;
case 0x0c0405b0u: goto P_0c0405b0;
case 0x0c0405b2u: goto P_0c0405b2;
case 0x0c0405b4u: goto P_0c0405b4;
case 0x0c0405b6u: goto P_0c0405b6;
case 0x0c0405b8u: goto P_0c0405b8;
case 0x0c0405bau: goto P_0c0405ba;
case 0x0c0405bcu: goto P_0c0405bc;
case 0x0c0405beu: goto P_0c0405be;
case 0x0c0405c0u: goto P_0c0405c0;
case 0x0c0405c2u: goto P_0c0405c2;
case 0x0c0405c4u: goto P_0c0405c4;
case 0x0c0405c6u: goto P_0c0405c6;
case 0x0c0405c8u: goto P_0c0405c8;
case 0x0c0405cau: goto P_0c0405ca;
case 0x0c0405ccu: goto P_0c0405cc;
case 0x0c0405ceu: goto P_0c0405ce;
case 0x0c0405d0u: goto P_0c0405d0;
case 0x0c0405d2u: goto P_0c0405d2;
case 0x0c0405d4u: goto P_0c0405d4;
case 0x0c0405d6u: goto P_0c0405d6;
case 0x0c0405d8u: goto P_0c0405d8;
case 0x0c0405dau: goto P_0c0405da;
case 0x0c0405dcu: goto P_0c0405dc;
case 0x0c0405deu: goto P_0c0405de;
case 0x0c0405e0u: goto P_0c0405e0;
case 0x0c0405e2u: goto P_0c0405e2;
case 0x0c0405e4u: goto P_0c0405e4;
case 0x0c0405e6u: goto P_0c0405e6;
case 0x0c0405e8u: goto P_0c0405e8;
case 0x0c0405eau: goto P_0c0405ea;
case 0x0c0405ecu: goto P_0c0405ec;
case 0x0c0405eeu: goto P_0c0405ee;
case 0x0c0405f0u: goto P_0c0405f0;
case 0x0c0405f2u: goto P_0c0405f2;
case 0x0c0405f4u: goto P_0c0405f4;
case 0x0c0405f6u: goto P_0c0405f6;
case 0x0c0405f8u: goto P_0c0405f8;
case 0x0c0405fau: goto P_0c0405fa;
case 0x0c0405fcu: goto P_0c0405fc;
case 0x0c0405feu: goto P_0c0405fe;
case 0x0c040600u: goto P_0c040600;
case 0x0c040602u: goto P_0c040602;
case 0x0c040604u: goto P_0c040604;
case 0x0c040606u: goto P_0c040606;
case 0x0c040608u: goto P_0c040608;
case 0x0c04060au: goto P_0c04060a;
case 0x0c04060cu: goto P_0c04060c;
case 0x0c04060eu: goto P_0c04060e;
case 0x0c040610u: goto P_0c040610;
case 0x0c040612u: goto P_0c040612;
case 0x0c040614u: goto P_0c040614;
case 0x0c040616u: goto P_0c040616;
case 0x0c040618u: goto P_0c040618;
case 0x0c04061au: goto P_0c04061a;
case 0x0c04061cu: goto P_0c04061c;
case 0x0c04061eu: goto P_0c04061e;
case 0x0c040620u: goto P_0c040620;
case 0x0c040622u: goto P_0c040622;
case 0x0c040624u: goto P_0c040624;
case 0x0c040626u: goto P_0c040626;
case 0x0c040628u: goto P_0c040628;
case 0x0c04062au: goto P_0c04062a;
case 0x0c04062cu: goto P_0c04062c;
case 0x0c04062eu: goto P_0c04062e;
case 0x0c040630u: goto P_0c040630;
case 0x0c040632u: goto P_0c040632;
case 0x0c040634u: goto P_0c040634;
case 0x0c040636u: goto P_0c040636;
case 0x0c040638u: goto P_0c040638;
case 0x0c04063au: goto P_0c04063a;
case 0x0c04063cu: goto P_0c04063c;
case 0x0c04063eu: goto P_0c04063e;
case 0x0c040640u: goto P_0c040640;
case 0x0c040642u: goto P_0c040642;
case 0x0c040644u: goto P_0c040644;
case 0x0c040646u: goto P_0c040646;
case 0x0c040648u: goto P_0c040648;
case 0x0c04064au: goto P_0c04064a;
case 0x0c04064cu: goto P_0c04064c;
case 0x0c04064eu: goto P_0c04064e;
case 0x0c040650u: goto P_0c040650;
case 0x0c040652u: goto P_0c040652;
case 0x0c040654u: goto P_0c040654;
case 0x0c040656u: goto P_0c040656;
case 0x0c040658u: goto P_0c040658;
case 0x0c04065au: goto P_0c04065a;
case 0x0c04065cu: goto P_0c04065c;
case 0x0c04065eu: goto P_0c04065e;
case 0x0c040660u: goto P_0c040660;
case 0x0c040662u: goto P_0c040662;
case 0x0c0406a4u: goto P_0c0406a4;
case 0x0c0406a6u: goto P_0c0406a6;
case 0x0c0406a8u: goto P_0c0406a8;
case 0x0c0406aau: goto P_0c0406aa;
case 0x0c0406acu: goto P_0c0406ac;
case 0x0c0406aeu: goto P_0c0406ae;
case 0x0c0406b0u: goto P_0c0406b0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03fda0: /* original e31f, guest PC 0x0c03fda0 */
if(!s->budget--) { s->failed_pc=0x0c03fda0u; return 0; }
r[3]=0x0000001fu;
goto P_0c03fda2;
P_0c03fda2: /* original d208, guest PC 0x0c03fda2 */
if(!s->budget--) { s->failed_pc=0x0c03fda2u; return 0; }
r[2]=read(ram,0x0c03fdc4u,4);
goto P_0c03fda4;
P_0c03fda4: /* original e501, guest PC 0x0c03fda4 */
if(!s->budget--) { s->failed_pc=0x0c03fda4u; return 0; }
r[5]=0x00000001u;
goto P_0c03fda6;
P_0c03fda6: /* original 2349, guest PC 0x0c03fda6 */
if(!s->budget--) { s->failed_pc=0x0c03fda6u; return 0; }
r[3]&=r[4];
goto P_0c03fda8;
P_0c03fda8: /* original 6022, guest PC 0x0c03fda8 */
if(!s->budget--) { s->failed_pc=0x0c03fda8u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c03fdaa;
P_0c03fdaa: /* original 453c, guest PC 0x0c03fdaa */
if(!s->budget--) { s->failed_pc=0x0c03fdaau; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c03fdac;
P_0c03fdac: /* original e3fb, guest PC 0x0c03fdac */
if(!s->budget--) { s->failed_pc=0x0c03fdacu; return 0; }
r[3]=0xfffffffbu;
goto P_0c03fdae;
P_0c03fdae: /* original 443c, guest PC 0x0c03fdae */
if(!s->budget--) { s->failed_pc=0x0c03fdaeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c03fdb0;
P_0c03fdb0: /* original 6343, guest PC 0x0c03fdb0 */
if(!s->budget--) { s->failed_pc=0x0c03fdb0u; return 0; }
r[3]=r[4];
goto P_0c03fdb2;
P_0c03fdb2: /* original 4308, guest PC 0x0c03fdb2 */
if(!s->budget--) { s->failed_pc=0x0c03fdb2u; return 0; }
r[3]<<=2;
goto P_0c03fdb4;
P_0c03fdb4: /* original 013e, guest PC 0x0c03fdb4 */
if(!s->budget--) { s->failed_pc=0x0c03fdb4u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c03fdb6;
P_0c03fdb6: /* original 6557, guest PC 0x0c03fdb6 */
if(!s->budget--) { s->failed_pc=0x0c03fdb6u; return 0; }
r[5]=~r[5];
goto P_0c03fdb8;
P_0c03fdb8: /* original 2159, guest PC 0x0c03fdb8 */
if(!s->budget--) { s->failed_pc=0x0c03fdb8u; return 0; }
r[1]&=r[5];
goto P_0c03fdba;
P_0c03fdba: /* original 000b, guest PC 0x0c03fdba */
if(!s->budget--) { s->failed_pc=0x0c03fdbau; return 0; }
target=r[16];
write(ram,r[3]+r[0],r[1],4);
s->pc=target; return ram->oob==0;
P_0c03fdbc: /* original 0316, guest PC 0x0c03fdbc */
if(!s->budget--) { s->failed_pc=0x0c03fdbcu; return 0; }
write(ram,r[3]+r[0],r[1],4);
if(!vf3_matrix_family(0x0c03fdbeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fdbeu; return 0; } return 1;
P_0c03fdd0: /* original 2fe6, guest PC 0x0c03fdd0 */
if(!s->budget--) { s->failed_pc=0x0c03fdd0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fdd2;
P_0c03fdd2: /* original 6e43, guest PC 0x0c03fdd2 */
if(!s->budget--) { s->failed_pc=0x0c03fdd2u; return 0; }
r[14]=r[4];
goto P_0c03fdd4;
P_0c03fdd4: /* original 63e2, guest PC 0x0c03fdd4 */
if(!s->budget--) { s->failed_pc=0x0c03fdd4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03fdd6;
P_0c03fdd6: /* original 4311, guest PC 0x0c03fdd6 */
if(!s->budget--) { s->failed_pc=0x0c03fdd6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c03fdd8;
P_0c03fdd8: /* original 8b0a, guest PC 0x0c03fdd8 */
if(!s->budget--) { s->failed_pc=0x0c03fdd8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fdf0; }
goto P_0c03fdda;
P_0c03fdda: /* original 51e6, guest PC 0x0c03fdda */
if(!s->budget--) { s->failed_pc=0x0c03fddau; return 0; }
r[1]=read(ram,r[14]+24,4);
goto P_0c03fddc;
P_0c03fddc: /* original 2118, guest PC 0x0c03fddc */
if(!s->budget--) { s->failed_pc=0x0c03fddcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03fdde;
P_0c03fdde: /* original 8907, guest PC 0x0c03fdde */
if(!s->budget--) { s->failed_pc=0x0c03fddeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03fdf0; }
goto P_0c03fde0;
P_0c03fde0: /* original 9661, guest PC 0x0c03fde0 */
if(!s->budget--) { s->failed_pc=0x0c03fde0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03fea6u,2);
goto P_0c03fde2;
P_0c03fde2: /* original 64e3, guest PC 0x0c03fde2 */
if(!s->budget--) { s->failed_pc=0x0c03fde2u; return 0; }
r[4]=r[14];
goto P_0c03fde4;
P_0c03fde4: /* original 7418, guest PC 0x0c03fde4 */
if(!s->budget--) { s->failed_pc=0x0c03fde4u; return 0; }
r[4]+=0x00000018u;
goto P_0c03fde6;
P_0c03fde6: /* original 6563, guest PC 0x0c03fde6 */
if(!s->budget--) { s->failed_pc=0x0c03fde6u; return 0; }
r[5]=r[6];
goto P_0c03fde8;
P_0c03fde8: /* original 7540, guest PC 0x0c03fde8 */
if(!s->budget--) { s->failed_pc=0x0c03fde8u; return 0; }
r[5]+=0x00000040u;
goto P_0c03fdea;
P_0c03fdea: /* original a021, guest PC 0x0c03fdea */
if(!s->budget--) { s->failed_pc=0x0c03fdeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03fe30;
P_0c03fdec: /* original 6ef6, guest PC 0x0c03fdec */
if(!s->budget--) { s->failed_pc=0x0c03fdecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fdeeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fdeeu; return 0; } return 1;
P_0c03fdf0: /* original 000b, guest PC 0x0c03fdf0 */
if(!s->budget--) { s->failed_pc=0x0c03fdf0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fdf2: /* original 6ef6, guest PC 0x0c03fdf2 */
if(!s->budget--) { s->failed_pc=0x0c03fdf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fdf4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fdf4u; return 0; } return 1;
P_0c03fe30: /* original 6157, guest PC 0x0c03fe30 */
if(!s->budget--) { s->failed_pc=0x0c03fe30u; return 0; }
r[1]=~r[5];
goto P_0c03fe32;
P_0c03fe32: /* original 6743, guest PC 0x0c03fe32 */
if(!s->budget--) { s->failed_pc=0x0c03fe32u; return 0; }
r[7]=r[4];
goto P_0c03fe34;
P_0c03fe34: /* original 6272, guest PC 0x0c03fe34 */
if(!s->budget--) { s->failed_pc=0x0c03fe34u; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c03fe36;
P_0c03fe36: /* original 2259, guest PC 0x0c03fe36 */
if(!s->budget--) { s->failed_pc=0x0c03fe36u; return 0; }
r[2]&=r[5];
goto P_0c03fe38;
P_0c03fe38: /* original 3250, guest PC 0x0c03fe38 */
if(!s->budget--) { s->failed_pc=0x0c03fe38u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[5])!=0);
goto P_0c03fe3a;
P_0c03fe3a: /* original 8d04, guest PC 0x0c03fe3a */
if(!s->budget--) { s->failed_pc=0x0c03fe3au; return 0; }
cond=r[17]&1u;
r[4]+=0x00000050u;
if(cond) { goto P_0c03fe46; }
goto P_0c03fe3e;
P_0c03fe3c: /* original 7450, guest PC 0x0c03fe3c */
if(!s->budget--) { s->failed_pc=0x0c03fe3cu; return 0; }
r[4]+=0x00000050u;
goto P_0c03fe3e;
P_0c03fe3e: /* original 6272, guest PC 0x0c03fe3e */
if(!s->budget--) { s->failed_pc=0x0c03fe3eu; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c03fe40;
P_0c03fe40: /* original 2219, guest PC 0x0c03fe40 */
if(!s->budget--) { s->failed_pc=0x0c03fe40u; return 0; }
r[2]&=r[1];
goto P_0c03fe42;
P_0c03fe42: /* original 226b, guest PC 0x0c03fe42 */
if(!s->budget--) { s->failed_pc=0x0c03fe42u; return 0; }
r[2]|=r[6];
goto P_0c03fe44;
P_0c03fe44: /* original 2722, guest PC 0x0c03fe44 */
if(!s->budget--) { s->failed_pc=0x0c03fe44u; return 0; }
write(ram,r[7],r[2],4);
goto P_0c03fe46;
P_0c03fe46: /* original e04c, guest PC 0x0c03fe46 */
if(!s->budget--) { s->failed_pc=0x0c03fe46u; return 0; }
r[0]=0x0000004cu;
goto P_0c03fe48;
P_0c03fe48: /* original 037e, guest PC 0x0c03fe48 */
if(!s->budget--) { s->failed_pc=0x0c03fe48u; return 0; }
r[3]=read(ram,r[7]+r[0],4);
goto P_0c03fe4a;
P_0c03fe4a: /* original 343c, guest PC 0x0c03fe4a */
if(!s->budget--) { s->failed_pc=0x0c03fe4au; return 0; }
r[4]+=r[3];
goto P_0c03fe4c;
P_0c03fe4c: /* original 6742, guest PC 0x0c03fe4c */
if(!s->budget--) { s->failed_pc=0x0c03fe4cu; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c03fe4e;
P_0c03fe4e: /* original 2778, guest PC 0x0c03fe4e */
if(!s->budget--) { s->failed_pc=0x0c03fe4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c03fe50;
P_0c03fe50: /* original 8bef, guest PC 0x0c03fe50 */
if(!s->budget--) { s->failed_pc=0x0c03fe50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fe32; }
goto P_0c03fe52;
P_0c03fe52: /* original 000b, guest PC 0x0c03fe52 */
if(!s->budget--) { s->failed_pc=0x0c03fe52u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03fe54: /* original 0009, guest PC 0x0c03fe54 */
if(!s->budget--) { s->failed_pc=0x0c03fe54u; return 0; }
if(!vf3_matrix_family(0x0c03fe56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fe56u; return 0; } return 1;
P_0c040498: /* original 2fe6, guest PC 0x0c040498 */
if(!s->budget--) { s->failed_pc=0x0c040498u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04049a;
P_0c04049a: /* original 2fd6, guest PC 0x0c04049a */
if(!s->budget--) { s->failed_pc=0x0c04049au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04049c;
P_0c04049c: /* original 2fc6, guest PC 0x0c04049c */
if(!s->budget--) { s->failed_pc=0x0c04049cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04049e;
P_0c04049e: /* original 2fb6, guest PC 0x0c04049e */
if(!s->budget--) { s->failed_pc=0x0c04049eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0404a0;
P_0c0404a0: /* original 7ff0, guest PC 0x0c0404a0 */
if(!s->budget--) { s->failed_pc=0x0c0404a0u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0404a2;
P_0c0404a2: /* original 1f43, guest PC 0x0c0404a2 */
if(!s->budget--) { s->failed_pc=0x0c0404a2u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c0404a4;
P_0c0404a4: /* original 1f52, guest PC 0x0c0404a4 */
if(!s->budget--) { s->failed_pc=0x0c0404a4u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0404a6;
P_0c0404a6: /* original 53f3, guest PC 0x0c0404a6 */
if(!s->budget--) { s->failed_pc=0x0c0404a6u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0404a8;
P_0c0404a8: /* original 903f, guest PC 0x0c0404a8 */
if(!s->budget--) { s->failed_pc=0x0c0404a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04052au,2);
goto P_0c0404aa;
P_0c0404aa: /* original 023e, guest PC 0x0c0404aa */
if(!s->budget--) { s->failed_pc=0x0c0404aau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0404ac;
P_0c0404ac: /* original d120, guest PC 0x0c0404ac */
if(!s->budget--) { s->failed_pc=0x0c0404acu; return 0; }
r[1]=read(ram,0x0c040530u,4);
goto P_0c0404ae;
P_0c0404ae: /* original 2122, guest PC 0x0c0404ae */
if(!s->budget--) { s->failed_pc=0x0c0404aeu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0404b0;
P_0c0404b0: /* original 933c, guest PC 0x0c0404b0 */
if(!s->budget--) { s->failed_pc=0x0c0404b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04052cu,2);
goto P_0c0404b2;
P_0c0404b2: /* original 6212, guest PC 0x0c0404b2 */
if(!s->budget--) { s->failed_pc=0x0c0404b2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0404b4;
P_0c0404b4: /* original 3232, guest PC 0x0c0404b4 */
if(!s->budget--) { s->failed_pc=0x0c0404b4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0404b6;
P_0c0404b6: /* original 8902, guest PC 0x0c0404b6 */
if(!s->budget--) { s->failed_pc=0x0c0404b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0404be; }
goto P_0c0404b8;
P_0c0404b8: /* original e0ff, guest PC 0x0c0404b8 */
if(!s->budget--) { s->failed_pc=0x0c0404b8u; return 0; }
r[0]=0xffffffffu;
goto P_0c0404ba;
P_0c0404ba: /* original a0f3, guest PC 0x0c0404ba */
if(!s->budget--) { s->failed_pc=0x0c0404bau; return 0; }
goto P_0c0406a4;
P_0c0404bc: /* original 0009, guest PC 0x0c0404bc */
if(!s->budget--) { s->failed_pc=0x0c0404bcu; return 0; }
goto P_0c0404be;
P_0c0404be: /* original 52f2, guest PC 0x0c0404be */
if(!s->budget--) { s->failed_pc=0x0c0404beu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0404c0;
P_0c0404c0: /* original 2228, guest PC 0x0c0404c0 */
if(!s->budget--) { s->failed_pc=0x0c0404c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0404c2;
P_0c0404c2: /* original 8b04, guest PC 0x0c0404c2 */
if(!s->budget--) { s->failed_pc=0x0c0404c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0404ce; }
goto P_0c0404c4;
P_0c0404c4: /* original d31b, guest PC 0x0c0404c4 */
if(!s->budget--) { s->failed_pc=0x0c0404c4u; return 0; }
r[3]=read(ram,0x0c040534u,4);
goto P_0c0404c6;
P_0c0404c6: /* original d21c, guest PC 0x0c0404c6 */
if(!s->budget--) { s->failed_pc=0x0c0404c6u; return 0; }
r[2]=read(ram,0x0c040538u,4);
goto P_0c0404c8;
P_0c0404c8: /* original 2232, guest PC 0x0c0404c8 */
if(!s->budget--) { s->failed_pc=0x0c0404c8u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0404ca;
P_0c0404ca: /* original a00c, guest PC 0x0c0404ca */
if(!s->budget--) { s->failed_pc=0x0c0404cau; return 0; }
goto P_0c0404e6;
P_0c0404cc: /* original 0009, guest PC 0x0c0404cc */
if(!s->budget--) { s->failed_pc=0x0c0404ccu; return 0; }
goto P_0c0404ce;
P_0c0404ce: /* original 902e, guest PC 0x0c0404ce */
if(!s->budget--) { s->failed_pc=0x0c0404ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04052eu,2);
goto P_0c0404d0;
P_0c0404d0: /* original 51f2, guest PC 0x0c0404d0 */
if(!s->budget--) { s->failed_pc=0x0c0404d0u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0404d2;
P_0c0404d2: /* original 3100, guest PC 0x0c0404d2 */
if(!s->budget--) { s->failed_pc=0x0c0404d2u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[0])!=0);
goto P_0c0404d4;
P_0c0404d4: /* original 8b04, guest PC 0x0c0404d4 */
if(!s->budget--) { s->failed_pc=0x0c0404d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0404e0; }
goto P_0c0404d6;
P_0c0404d6: /* original d219, guest PC 0x0c0404d6 */
if(!s->budget--) { s->failed_pc=0x0c0404d6u; return 0; }
r[2]=read(ram,0x0c04053cu,4);
goto P_0c0404d8;
P_0c0404d8: /* original d317, guest PC 0x0c0404d8 */
if(!s->budget--) { s->failed_pc=0x0c0404d8u; return 0; }
r[3]=read(ram,0x0c040538u,4);
goto P_0c0404da;
P_0c0404da: /* original 2322, guest PC 0x0c0404da */
if(!s->budget--) { s->failed_pc=0x0c0404dau; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0404dc;
P_0c0404dc: /* original a003, guest PC 0x0c0404dc */
if(!s->budget--) { s->failed_pc=0x0c0404dcu; return 0; }
goto P_0c0404e6;
P_0c0404de: /* original 0009, guest PC 0x0c0404de */
if(!s->budget--) { s->failed_pc=0x0c0404deu; return 0; }
goto P_0c0404e0;
P_0c0404e0: /* original e0fe, guest PC 0x0c0404e0 */
if(!s->budget--) { s->failed_pc=0x0c0404e0u; return 0; }
r[0]=0xfffffffeu;
goto P_0c0404e2;
P_0c0404e2: /* original a0df, guest PC 0x0c0404e2 */
if(!s->budget--) { s->failed_pc=0x0c0404e2u; return 0; }
goto P_0c0406a4;
P_0c0404e4: /* original 0009, guest PC 0x0c0404e4 */
if(!s->budget--) { s->failed_pc=0x0c0404e4u; return 0; }
goto P_0c0404e6;
P_0c0404e6: /* original 53f2, guest PC 0x0c0404e6 */
if(!s->budget--) { s->failed_pc=0x0c0404e6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0404e8;
P_0c0404e8: /* original d215, guest PC 0x0c0404e8 */
if(!s->budget--) { s->failed_pc=0x0c0404e8u; return 0; }
r[2]=read(ram,0x0c040540u,4);
goto P_0c0404ea;
P_0c0404ea: /* original 2232, guest PC 0x0c0404ea */
if(!s->budget--) { s->failed_pc=0x0c0404eau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0404ec;
P_0c0404ec: /* original d115, guest PC 0x0c0404ec */
if(!s->budget--) { s->failed_pc=0x0c0404ecu; return 0; }
r[1]=read(ram,0x0c040544u,4);
goto P_0c0404ee;
P_0c0404ee: /* original 6d12, guest PC 0x0c0404ee */
if(!s->budget--) { s->failed_pc=0x0c0404eeu; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c0404f0;
P_0c0404f0: /* original d015, guest PC 0x0c0404f0 */
if(!s->budget--) { s->failed_pc=0x0c0404f0u; return 0; }
r[0]=read(ram,0x0c040548u,4);
goto P_0c0404f2;
P_0c0404f2: /* original 20d9, guest PC 0x0c0404f2 */
if(!s->budget--) { s->failed_pc=0x0c0404f2u; return 0; }
r[0]&=r[13];
goto P_0c0404f4;
P_0c0404f4: /* original ed01, guest PC 0x0c0404f4 */
if(!s->budget--) { s->failed_pc=0x0c0404f4u; return 0; }
r[13]=0x00000001u;
goto P_0c0404f6;
P_0c0404f6: /* original 2d0b, guest PC 0x0c0404f6 */
if(!s->budget--) { s->failed_pc=0x0c0404f6u; return 0; }
r[13]|=r[0];
goto P_0c0404f8;
P_0c0404f8: /* original 21d2, guest PC 0x0c0404f8 */
if(!s->budget--) { s->failed_pc=0x0c0404f8u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c0404fa;
P_0c0404fa: /* original 5cf3, guest PC 0x0c0404fa */
if(!s->budget--) { s->failed_pc=0x0c0404fau; return 0; }
r[12]=read(ram,r[15]+12,4);
goto P_0c0404fc;
P_0c0404fc: /* original db13, guest PC 0x0c0404fc */
if(!s->budget--) { s->failed_pc=0x0c0404fcu; return 0; }
r[11]=read(ram,0x0c04054cu,4);
goto P_0c0404fe;
P_0c0404fe: /* original 5df3, guest PC 0x0c0404fe */
if(!s->budget--) { s->failed_pc=0x0c0404feu; return 0; }
r[13]=read(ram,r[15]+12,4);
goto P_0c040500;
P_0c040500: /* original 7d54, guest PC 0x0c040500 */
if(!s->budget--) { s->failed_pc=0x0c040500u; return 0; }
r[13]+=0x00000054u;
goto P_0c040502;
P_0c040502: /* original 6dd2, guest PC 0x0c040502 */
if(!s->budget--) { s->failed_pc=0x0c040502u; return 0; }
tmp=read(ram,r[13],4);
r[13]=tmp;
goto P_0c040504;
P_0c040504: /* original ee00, guest PC 0x0c040504 */
if(!s->budget--) { s->failed_pc=0x0c040504u; return 0; }
r[14]=0x00000000u;
goto P_0c040506;
P_0c040506: /* original a005, guest PC 0x0c040506 */
if(!s->budget--) { s->failed_pc=0x0c040506u; return 0; }
goto P_0c040514;
P_0c040508: /* original 0009, guest PC 0x0c040508 */
if(!s->budget--) { s->failed_pc=0x0c040508u; return 0; }
goto P_0c04050a;
P_0c04050a: /* original 62b3, guest PC 0x0c04050a */
if(!s->budget--) { s->failed_pc=0x0c04050au; return 0; }
r[2]=r[11];
goto P_0c04050c;
P_0c04050c: /* original 7b04, guest PC 0x0c04050c */
if(!s->budget--) { s->failed_pc=0x0c04050cu; return 0; }
r[11]+=0x00000004u;
goto P_0c04050e;
P_0c04050e: /* original 63c6, guest PC 0x0c04050e */
if(!s->budget--) { s->failed_pc=0x0c04050eu; return 0; }
tmp=read(ram,r[12],4);
r[12]+=4;
r[3]=tmp;
goto P_0c040510;
P_0c040510: /* original 2232, guest PC 0x0c040510 */
if(!s->budget--) { s->failed_pc=0x0c040510u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040512;
P_0c040512: /* original 7e01, guest PC 0x0c040512 */
if(!s->budget--) { s->failed_pc=0x0c040512u; return 0; }
r[14]+=0x00000001u;
goto P_0c040514;
P_0c040514: /* original 62d3, guest PC 0x0c040514 */
if(!s->budget--) { s->failed_pc=0x0c040514u; return 0; }
r[2]=r[13];
goto P_0c040516;
P_0c040516: /* original 4209, guest PC 0x0c040516 */
if(!s->budget--) { s->failed_pc=0x0c040516u; return 0; }
r[2]>>=2;
goto P_0c040518;
P_0c040518: /* original 3e22, guest PC 0x0c040518 */
if(!s->budget--) { s->failed_pc=0x0c040518u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c04051a;
P_0c04051a: /* original 8bf6, guest PC 0x0c04051a */
if(!s->budget--) { s->failed_pc=0x0c04051au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04050a; }
goto P_0c04051c;
P_0c04051c: /* original 52f2, guest PC 0x0c04051c */
if(!s->budget--) { s->failed_pc=0x0c04051cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04051e;
P_0c04051e: /* original d30c, guest PC 0x0c04051e */
if(!s->budget--) { s->failed_pc=0x0c04051eu; return 0; }
r[3]=read(ram,0x0c040550u,4);
goto P_0c040520;
P_0c040520: /* original 2322, guest PC 0x0c040520 */
if(!s->budget--) { s->failed_pc=0x0c040520u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040522;
P_0c040522: /* original db0c, guest PC 0x0c040522 */
if(!s->budget--) { s->failed_pc=0x0c040522u; return 0; }
r[11]=read(ram,0x0c040554u,4);
goto P_0c040524;
P_0c040524: /* original ee00, guest PC 0x0c040524 */
if(!s->budget--) { s->failed_pc=0x0c040524u; return 0; }
r[14]=0x00000000u;
goto P_0c040526;
P_0c040526: /* original a01e, guest PC 0x0c040526 */
if(!s->budget--) { s->failed_pc=0x0c040526u; return 0; }
goto P_0c040566;
P_0c040528: /* original 0009, guest PC 0x0c040528 */
if(!s->budget--) { s->failed_pc=0x0c040528u; return 0; }
if(!vf3_matrix_family(0x0c04052au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04052au; return 0; } return 1;
P_0c040558: /* original e3ff, guest PC 0x0c040558 */
if(!s->budget--) { s->failed_pc=0x0c040558u; return 0; }
r[3]=0xffffffffu;
goto P_0c04055a;
P_0c04055a: /* original 2b32, guest PC 0x0c04055a */
if(!s->budget--) { s->failed_pc=0x0c04055au; return 0; }
write(ram,r[11],r[3],4);
goto P_0c04055c;
P_0c04055c: /* original 60b2, guest PC 0x0c04055c */
if(!s->budget--) { s->failed_pc=0x0c04055cu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c04055e;
P_0c04055e: /* original 88ff, guest PC 0x0c04055e */
if(!s->budget--) { s->failed_pc=0x0c04055eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c040560;
P_0c040560: /* original 8bfa, guest PC 0x0c040560 */
if(!s->budget--) { s->failed_pc=0x0c040560u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040558; }
goto P_0c040562;
P_0c040562: /* original 7b04, guest PC 0x0c040562 */
if(!s->budget--) { s->failed_pc=0x0c040562u; return 0; }
r[11]+=0x00000004u;
goto P_0c040564;
P_0c040564: /* original 7e01, guest PC 0x0c040564 */
if(!s->budget--) { s->failed_pc=0x0c040564u; return 0; }
r[14]+=0x00000001u;
goto P_0c040566;
P_0c040566: /* original e308, guest PC 0x0c040566 */
if(!s->budget--) { s->failed_pc=0x0c040566u; return 0; }
r[3]=0x00000008u;
goto P_0c040568;
P_0c040568: /* original 3e32, guest PC 0x0c040568 */
if(!s->budget--) { s->failed_pc=0x0c040568u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c04056a;
P_0c04056a: /* original 8bf5, guest PC 0x0c04056a */
if(!s->budget--) { s->failed_pc=0x0c04056au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040558; }
goto P_0c04056c;
P_0c04056c: /* original d13e, guest PC 0x0c04056c */
if(!s->budget--) { s->failed_pc=0x0c04056cu; return 0; }
r[1]=read(ram,0x0c040668u,4);
goto P_0c04056e;
P_0c04056e: /* original 6d12, guest PC 0x0c04056e */
if(!s->budget--) { s->failed_pc=0x0c04056eu; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c040570;
P_0c040570: /* original d33e, guest PC 0x0c040570 */
if(!s->budget--) { s->failed_pc=0x0c040570u; return 0; }
r[3]=read(ram,0x0c04066cu,4);
goto P_0c040572;
P_0c040572: /* original 2d39, guest PC 0x0c040572 */
if(!s->budget--) { s->failed_pc=0x0c040572u; return 0; }
r[13]&=r[3];
goto P_0c040574;
P_0c040574: /* original 21d2, guest PC 0x0c040574 */
if(!s->budget--) { s->failed_pc=0x0c040574u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c040576;
P_0c040576: /* original ee00, guest PC 0x0c040576 */
if(!s->budget--) { s->failed_pc=0x0c040576u; return 0; }
r[14]=0x00000000u;
goto P_0c040578;
P_0c040578: /* original a01e, guest PC 0x0c040578 */
if(!s->budget--) { s->failed_pc=0x0c040578u; return 0; }
goto P_0c0405b8;
P_0c04057a: /* original 0009, guest PC 0x0c04057a */
if(!s->budget--) { s->failed_pc=0x0c04057au; return 0; }
goto P_0c04057c;
P_0c04057c: /* original 63e3, guest PC 0x0c04057c */
if(!s->budget--) { s->failed_pc=0x0c04057cu; return 0; }
r[3]=r[14];
goto P_0c04057e;
P_0c04057e: /* original 6233, guest PC 0x0c04057e */
if(!s->budget--) { s->failed_pc=0x0c04057eu; return 0; }
r[2]=r[3];
goto P_0c040580;
P_0c040580: /* original 4300, guest PC 0x0c040580 */
if(!s->budget--) { s->failed_pc=0x0c040580u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040582;
P_0c040582: /* original 332c, guest PC 0x0c040582 */
if(!s->budget--) { s->failed_pc=0x0c040582u; return 0; }
r[3]+=r[2];
goto P_0c040584;
P_0c040584: /* original 4308, guest PC 0x0c040584 */
if(!s->budget--) { s->failed_pc=0x0c040584u; return 0; }
r[3]<<=2;
goto P_0c040586;
P_0c040586: /* original 633e, guest PC 0x0c040586 */
if(!s->budget--) { s->failed_pc=0x0c040586u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040588;
P_0c040588: /* original e1ff, guest PC 0x0c040588 */
if(!s->budget--) { s->failed_pc=0x0c040588u; return 0; }
r[1]=0xffffffffu;
goto P_0c04058a;
P_0c04058a: /* original d039, guest PC 0x0c04058a */
if(!s->budget--) { s->failed_pc=0x0c04058au; return 0; }
r[0]=read(ram,0x0c040670u,4);
goto P_0c04058c;
P_0c04058c: /* original 0316, guest PC 0x0c04058c */
if(!s->budget--) { s->failed_pc=0x0c04058cu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c04058e;
P_0c04058e: /* original 63e3, guest PC 0x0c04058e */
if(!s->budget--) { s->failed_pc=0x0c04058eu; return 0; }
r[3]=r[14];
goto P_0c040590;
P_0c040590: /* original 6233, guest PC 0x0c040590 */
if(!s->budget--) { s->failed_pc=0x0c040590u; return 0; }
r[2]=r[3];
goto P_0c040592;
P_0c040592: /* original 4300, guest PC 0x0c040592 */
if(!s->budget--) { s->failed_pc=0x0c040592u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040594;
P_0c040594: /* original 332c, guest PC 0x0c040594 */
if(!s->budget--) { s->failed_pc=0x0c040594u; return 0; }
r[3]+=r[2];
goto P_0c040596;
P_0c040596: /* original 4308, guest PC 0x0c040596 */
if(!s->budget--) { s->failed_pc=0x0c040596u; return 0; }
r[3]<<=2;
goto P_0c040598;
P_0c040598: /* original 633e, guest PC 0x0c040598 */
if(!s->budget--) { s->failed_pc=0x0c040598u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c04059a;
P_0c04059a: /* original 6103, guest PC 0x0c04059a */
if(!s->budget--) { s->failed_pc=0x0c04059au; return 0; }
r[1]=r[0];
goto P_0c04059c;
P_0c04059c: /* original 331c, guest PC 0x0c04059c */
if(!s->budget--) { s->failed_pc=0x0c04059cu; return 0; }
r[3]+=r[1];
goto P_0c04059e;
P_0c04059e: /* original e200, guest PC 0x0c04059e */
if(!s->budget--) { s->failed_pc=0x0c04059eu; return 0; }
r[2]=0x00000000u;
goto P_0c0405a0;
P_0c0405a0: /* original 1321, guest PC 0x0c0405a0 */
if(!s->budget--) { s->failed_pc=0x0c0405a0u; return 0; }
write(ram,r[3]+4,r[2],4);
goto P_0c0405a2;
P_0c0405a2: /* original 63e3, guest PC 0x0c0405a2 */
if(!s->budget--) { s->failed_pc=0x0c0405a2u; return 0; }
r[3]=r[14];
goto P_0c0405a4;
P_0c0405a4: /* original 6233, guest PC 0x0c0405a4 */
if(!s->budget--) { s->failed_pc=0x0c0405a4u; return 0; }
r[2]=r[3];
goto P_0c0405a6;
P_0c0405a6: /* original 4300, guest PC 0x0c0405a6 */
if(!s->budget--) { s->failed_pc=0x0c0405a6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0405a8;
P_0c0405a8: /* original 332c, guest PC 0x0c0405a8 */
if(!s->budget--) { s->failed_pc=0x0c0405a8u; return 0; }
r[3]+=r[2];
goto P_0c0405aa;
P_0c0405aa: /* original 4308, guest PC 0x0c0405aa */
if(!s->budget--) { s->failed_pc=0x0c0405aau; return 0; }
r[3]<<=2;
goto P_0c0405ac;
P_0c0405ac: /* original 633e, guest PC 0x0c0405ac */
if(!s->budget--) { s->failed_pc=0x0c0405acu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c0405ae;
P_0c0405ae: /* original 6103, guest PC 0x0c0405ae */
if(!s->budget--) { s->failed_pc=0x0c0405aeu; return 0; }
r[1]=r[0];
goto P_0c0405b0;
P_0c0405b0: /* original 331c, guest PC 0x0c0405b0 */
if(!s->budget--) { s->failed_pc=0x0c0405b0u; return 0; }
r[3]+=r[1];
goto P_0c0405b2;
P_0c0405b2: /* original e200, guest PC 0x0c0405b2 */
if(!s->budget--) { s->failed_pc=0x0c0405b2u; return 0; }
r[2]=0x00000000u;
goto P_0c0405b4;
P_0c0405b4: /* original 1322, guest PC 0x0c0405b4 */
if(!s->budget--) { s->failed_pc=0x0c0405b4u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0405b6;
P_0c0405b6: /* original 7e01, guest PC 0x0c0405b6 */
if(!s->budget--) { s->failed_pc=0x0c0405b6u; return 0; }
r[14]+=0x00000001u;
goto P_0c0405b8;
P_0c0405b8: /* original e308, guest PC 0x0c0405b8 */
if(!s->budget--) { s->failed_pc=0x0c0405b8u; return 0; }
r[3]=0x00000008u;
goto P_0c0405ba;
P_0c0405ba: /* original 3e32, guest PC 0x0c0405ba */
if(!s->budget--) { s->failed_pc=0x0c0405bau; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c0405bc;
P_0c0405bc: /* original 8bde, guest PC 0x0c0405bc */
if(!s->budget--) { s->failed_pc=0x0c0405bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04057c; }
goto P_0c0405be;
P_0c0405be: /* original ee00, guest PC 0x0c0405be */
if(!s->budget--) { s->failed_pc=0x0c0405beu; return 0; }
r[14]=0x00000000u;
goto P_0c0405c0;
P_0c0405c0: /* original a02b, guest PC 0x0c0405c0 */
if(!s->budget--) { s->failed_pc=0x0c0405c0u; return 0; }
goto P_0c04061a;
P_0c0405c2: /* original 0009, guest PC 0x0c0405c2 */
if(!s->budget--) { s->failed_pc=0x0c0405c2u; return 0; }
goto P_0c0405c4;
P_0c0405c4: /* original 62e3, guest PC 0x0c0405c4 */
if(!s->budget--) { s->failed_pc=0x0c0405c4u; return 0; }
r[2]=r[14];
goto P_0c0405c6;
P_0c0405c6: /* original 6323, guest PC 0x0c0405c6 */
if(!s->budget--) { s->failed_pc=0x0c0405c6u; return 0; }
r[3]=r[2];
goto P_0c0405c8;
P_0c0405c8: /* original 4200, guest PC 0x0c0405c8 */
if(!s->budget--) { s->failed_pc=0x0c0405c8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0405ca;
P_0c0405ca: /* original 323c, guest PC 0x0c0405ca */
if(!s->budget--) { s->failed_pc=0x0c0405cau; return 0; }
r[2]+=r[3];
goto P_0c0405cc;
P_0c0405cc: /* original 4208, guest PC 0x0c0405cc */
if(!s->budget--) { s->failed_pc=0x0c0405ccu; return 0; }
r[2]<<=2;
goto P_0c0405ce;
P_0c0405ce: /* original 4200, guest PC 0x0c0405ce */
if(!s->budget--) { s->failed_pc=0x0c0405ceu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0405d0;
P_0c0405d0: /* original 622c, guest PC 0x0c0405d0 */
if(!s->budget--) { s->failed_pc=0x0c0405d0u; return 0; }
r[2]=r[2]&255u;
goto P_0c0405d2;
P_0c0405d2: /* original e1ff, guest PC 0x0c0405d2 */
if(!s->budget--) { s->failed_pc=0x0c0405d2u; return 0; }
r[1]=0xffffffffu;
goto P_0c0405d4;
P_0c0405d4: /* original d027, guest PC 0x0c0405d4 */
if(!s->budget--) { s->failed_pc=0x0c0405d4u; return 0; }
r[0]=read(ram,0x0c040674u,4);
goto P_0c0405d6;
P_0c0405d6: /* original 0214, guest PC 0x0c0405d6 */
if(!s->budget--) { s->failed_pc=0x0c0405d6u; return 0; }
write(ram,r[2]+r[0],r[1],1);
goto P_0c0405d8;
P_0c0405d8: /* original 63e3, guest PC 0x0c0405d8 */
if(!s->budget--) { s->failed_pc=0x0c0405d8u; return 0; }
r[3]=r[14];
goto P_0c0405da;
P_0c0405da: /* original 6233, guest PC 0x0c0405da */
if(!s->budget--) { s->failed_pc=0x0c0405dau; return 0; }
r[2]=r[3];
goto P_0c0405dc;
P_0c0405dc: /* original 4300, guest PC 0x0c0405dc */
if(!s->budget--) { s->failed_pc=0x0c0405dcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0405de;
P_0c0405de: /* original 332c, guest PC 0x0c0405de */
if(!s->budget--) { s->failed_pc=0x0c0405deu; return 0; }
r[3]+=r[2];
goto P_0c0405e0;
P_0c0405e0: /* original 4308, guest PC 0x0c0405e0 */
if(!s->budget--) { s->failed_pc=0x0c0405e0u; return 0; }
r[3]<<=2;
goto P_0c0405e2;
P_0c0405e2: /* original 4300, guest PC 0x0c0405e2 */
if(!s->budget--) { s->failed_pc=0x0c0405e2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0405e4;
P_0c0405e4: /* original 633c, guest PC 0x0c0405e4 */
if(!s->budget--) { s->failed_pc=0x0c0405e4u; return 0; }
r[3]=r[3]&255u;
goto P_0c0405e6;
P_0c0405e6: /* original 6103, guest PC 0x0c0405e6 */
if(!s->budget--) { s->failed_pc=0x0c0405e6u; return 0; }
r[1]=r[0];
goto P_0c0405e8;
P_0c0405e8: /* original 331c, guest PC 0x0c0405e8 */
if(!s->budget--) { s->failed_pc=0x0c0405e8u; return 0; }
r[3]+=r[1];
goto P_0c0405ea;
P_0c0405ea: /* original e000, guest PC 0x0c0405ea */
if(!s->budget--) { s->failed_pc=0x0c0405eau; return 0; }
r[0]=0x00000000u;
goto P_0c0405ec;
P_0c0405ec: /* original 8031, guest PC 0x0c0405ec */
if(!s->budget--) { s->failed_pc=0x0c0405ecu; return 0; }
write(ram,r[3]+1,r[0],1);
goto P_0c0405ee;
P_0c0405ee: /* original 63e3, guest PC 0x0c0405ee */
if(!s->budget--) { s->failed_pc=0x0c0405eeu; return 0; }
r[3]=r[14];
goto P_0c0405f0;
P_0c0405f0: /* original 6233, guest PC 0x0c0405f0 */
if(!s->budget--) { s->failed_pc=0x0c0405f0u; return 0; }
r[2]=r[3];
goto P_0c0405f2;
P_0c0405f2: /* original 4300, guest PC 0x0c0405f2 */
if(!s->budget--) { s->failed_pc=0x0c0405f2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0405f4;
P_0c0405f4: /* original 332c, guest PC 0x0c0405f4 */
if(!s->budget--) { s->failed_pc=0x0c0405f4u; return 0; }
r[3]+=r[2];
goto P_0c0405f6;
P_0c0405f6: /* original 4308, guest PC 0x0c0405f6 */
if(!s->budget--) { s->failed_pc=0x0c0405f6u; return 0; }
r[3]<<=2;
goto P_0c0405f8;
P_0c0405f8: /* original 4300, guest PC 0x0c0405f8 */
if(!s->budget--) { s->failed_pc=0x0c0405f8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0405fa;
P_0c0405fa: /* original 633c, guest PC 0x0c0405fa */
if(!s->budget--) { s->failed_pc=0x0c0405fau; return 0; }
r[3]=r[3]&255u;
goto P_0c0405fc;
P_0c0405fc: /* original 61e3, guest PC 0x0c0405fc */
if(!s->budget--) { s->failed_pc=0x0c0405fcu; return 0; }
r[1]=r[14];
goto P_0c0405fe;
P_0c0405fe: /* original 6213, guest PC 0x0c0405fe */
if(!s->budget--) { s->failed_pc=0x0c0405feu; return 0; }
r[2]=r[1];
goto P_0c040600;
P_0c040600: /* original 4100, guest PC 0x0c040600 */
if(!s->budget--) { s->failed_pc=0x0c040600u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c040602;
P_0c040602: /* original 312c, guest PC 0x0c040602 */
if(!s->budget--) { s->failed_pc=0x0c040602u; return 0; }
r[1]+=r[2];
goto P_0c040604;
P_0c040604: /* original 4108, guest PC 0x0c040604 */
if(!s->budget--) { s->failed_pc=0x0c040604u; return 0; }
r[1]<<=2;
goto P_0c040606;
P_0c040606: /* original 4100, guest PC 0x0c040606 */
if(!s->budget--) { s->failed_pc=0x0c040606u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c040608;
P_0c040608: /* original 611c, guest PC 0x0c040608 */
if(!s->budget--) { s->failed_pc=0x0c040608u; return 0; }
r[1]=r[1]&255u;
goto P_0c04060a;
P_0c04060a: /* original e0ff, guest PC 0x0c04060a */
if(!s->budget--) { s->failed_pc=0x0c04060au; return 0; }
r[0]=0xffffffffu;
goto P_0c04060c;
P_0c04060c: /* original d21a, guest PC 0x0c04060c */
if(!s->budget--) { s->failed_pc=0x0c04060cu; return 0; }
r[2]=read(ram,0x0c040678u,4);
goto P_0c04060e;
P_0c04060e: /* original 321c, guest PC 0x0c04060e */
if(!s->budget--) { s->failed_pc=0x0c04060eu; return 0; }
r[2]+=r[1];
goto P_0c040610;
P_0c040610: /* original 2202, guest PC 0x0c040610 */
if(!s->budget--) { s->failed_pc=0x0c040610u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c040612;
P_0c040612: /* original d11a, guest PC 0x0c040612 */
if(!s->budget--) { s->failed_pc=0x0c040612u; return 0; }
r[1]=read(ram,0x0c04067cu,4);
goto P_0c040614;
P_0c040614: /* original 313c, guest PC 0x0c040614 */
if(!s->budget--) { s->failed_pc=0x0c040614u; return 0; }
r[1]+=r[3];
goto P_0c040616;
P_0c040616: /* original 2102, guest PC 0x0c040616 */
if(!s->budget--) { s->failed_pc=0x0c040616u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c040618;
P_0c040618: /* original 7e01, guest PC 0x0c040618 */
if(!s->budget--) { s->failed_pc=0x0c040618u; return 0; }
r[14]+=0x00000001u;
goto P_0c04061a;
P_0c04061a: /* original e308, guest PC 0x0c04061a */
if(!s->budget--) { s->failed_pc=0x0c04061au; return 0; }
r[3]=0x00000008u;
goto P_0c04061c;
P_0c04061c: /* original 3e32, guest PC 0x0c04061c */
if(!s->budget--) { s->failed_pc=0x0c04061cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c04061e;
P_0c04061e: /* original 8bd1, guest PC 0x0c04061e */
if(!s->budget--) { s->failed_pc=0x0c04061eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0405c4; }
goto P_0c040620;
P_0c040620: /* original 9320, guest PC 0x0c040620 */
if(!s->budget--) { s->failed_pc=0x0c040620u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040664u,2);
goto P_0c040622;
P_0c040622: /* original 52f3, guest PC 0x0c040622 */
if(!s->budget--) { s->failed_pc=0x0c040622u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040624;
P_0c040624: /* original 323c, guest PC 0x0c040624 */
if(!s->budget--) { s->failed_pc=0x0c040624u; return 0; }
r[2]+=r[3];
goto P_0c040626;
P_0c040626: /* original d116, guest PC 0x0c040626 */
if(!s->budget--) { s->failed_pc=0x0c040626u; return 0; }
r[1]=read(ram,0x0c040680u,4);
goto P_0c040628;
P_0c040628: /* original 6222, guest PC 0x0c040628 */
if(!s->budget--) { s->failed_pc=0x0c040628u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c04062a;
P_0c04062a: /* original 321c, guest PC 0x0c04062a */
if(!s->budget--) { s->failed_pc=0x0c04062au; return 0; }
r[2]+=r[1];
goto P_0c04062c;
P_0c04062c: /* original d015, guest PC 0x0c04062c */
if(!s->budget--) { s->failed_pc=0x0c04062cu; return 0; }
r[0]=read(ram,0x0c040684u,4);
goto P_0c04062e;
P_0c04062e: /* original 2022, guest PC 0x0c04062e */
if(!s->budget--) { s->failed_pc=0x0c04062eu; return 0; }
write(ram,r[0],r[2],4);
goto P_0c040630;
P_0c040630: /* original 9319, guest PC 0x0c040630 */
if(!s->budget--) { s->failed_pc=0x0c040630u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040666u,2);
goto P_0c040632;
P_0c040632: /* original 51f3, guest PC 0x0c040632 */
if(!s->budget--) { s->failed_pc=0x0c040632u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c040634;
P_0c040634: /* original 313c, guest PC 0x0c040634 */
if(!s->budget--) { s->failed_pc=0x0c040634u; return 0; }
r[1]+=r[3];
goto P_0c040636;
P_0c040636: /* original d214, guest PC 0x0c040636 */
if(!s->budget--) { s->failed_pc=0x0c040636u; return 0; }
r[2]=read(ram,0x0c040688u,4);
goto P_0c040638;
P_0c040638: /* original 6112, guest PC 0x0c040638 */
if(!s->budget--) { s->failed_pc=0x0c040638u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c04063a;
P_0c04063a: /* original 312c, guest PC 0x0c04063a */
if(!s->budget--) { s->failed_pc=0x0c04063au; return 0; }
r[1]+=r[2];
goto P_0c04063c;
P_0c04063c: /* original d013, guest PC 0x0c04063c */
if(!s->budget--) { s->failed_pc=0x0c04063cu; return 0; }
r[0]=read(ram,0x0c04068cu,4);
goto P_0c04063e;
P_0c04063e: /* original 2012, guest PC 0x0c04063e */
if(!s->budget--) { s->failed_pc=0x0c04063eu; return 0; }
write(ram,r[0],r[1],4);
goto P_0c040640;
P_0c040640: /* original d313, guest PC 0x0c040640 */
if(!s->budget--) { s->failed_pc=0x0c040640u; return 0; }
r[3]=read(ram,0x0c040690u,4);
goto P_0c040642;
P_0c040642: /* original d214, guest PC 0x0c040642 */
if(!s->budget--) { s->failed_pc=0x0c040642u; return 0; }
r[2]=read(ram,0x0c040694u,4);
goto P_0c040644;
P_0c040644: /* original 2232, guest PC 0x0c040644 */
if(!s->budget--) { s->failed_pc=0x0c040644u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040646;
P_0c040646: /* original e100, guest PC 0x0c040646 */
if(!s->budget--) { s->failed_pc=0x0c040646u; return 0; }
r[1]=0x00000000u;
goto P_0c040648;
P_0c040648: /* original d313, guest PC 0x0c040648 */
if(!s->budget--) { s->failed_pc=0x0c040648u; return 0; }
r[3]=read(ram,0x0c040698u,4);
goto P_0c04064a;
P_0c04064a: /* original 2312, guest PC 0x0c04064a */
if(!s->budget--) { s->failed_pc=0x0c04064au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c04064c;
P_0c04064c: /* original e000, guest PC 0x0c04064c */
if(!s->budget--) { s->failed_pc=0x0c04064cu; return 0; }
r[0]=0x00000000u;
goto P_0c04064e;
P_0c04064e: /* original d113, guest PC 0x0c04064e */
if(!s->budget--) { s->failed_pc=0x0c04064eu; return 0; }
r[1]=read(ram,0x0c04069cu,4);
goto P_0c040650;
P_0c040650: /* original 2102, guest PC 0x0c040650 */
if(!s->budget--) { s->failed_pc=0x0c040650u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c040652;
P_0c040652: /* original a000, guest PC 0x0c040652 */
if(!s->budget--) { s->failed_pc=0x0c040652u; return 0; }
goto P_0c040656;
P_0c040654: /* original 0009, guest PC 0x0c040654 */
if(!s->budget--) { s->failed_pc=0x0c040654u; return 0; }
goto P_0c040656;
P_0c040656: /* original d212, guest PC 0x0c040656 */
if(!s->budget--) { s->failed_pc=0x0c040656u; return 0; }
r[2]=read(ram,0x0c0406a0u,4);
goto P_0c040658;
P_0c040658: /* original 6322, guest PC 0x0c040658 */
if(!s->budget--) { s->failed_pc=0x0c040658u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04065a;
P_0c04065a: /* original 2338, guest PC 0x0c04065a */
if(!s->budget--) { s->failed_pc=0x0c04065au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04065c;
P_0c04065c: /* original 89fb, guest PC 0x0c04065c */
if(!s->budget--) { s->failed_pc=0x0c04065cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040656; }
goto P_0c04065e;
P_0c04065e: /* original e000, guest PC 0x0c04065e */
if(!s->budget--) { s->failed_pc=0x0c04065eu; return 0; }
r[0]=0x00000000u;
goto P_0c040660;
P_0c040660: /* original a020, guest PC 0x0c040660 */
if(!s->budget--) { s->failed_pc=0x0c040660u; return 0; }
goto P_0c0406a4;
P_0c040662: /* original 0009, guest PC 0x0c040662 */
if(!s->budget--) { s->failed_pc=0x0c040662u; return 0; }
if(!vf3_matrix_family(0x0c040664u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040664u; return 0; } return 1;
P_0c0406a4: /* original 7f10, guest PC 0x0c0406a4 */
if(!s->budget--) { s->failed_pc=0x0c0406a4u; return 0; }
r[15]+=0x00000010u;
goto P_0c0406a6;
P_0c0406a6: /* original 6bf6, guest PC 0x0c0406a6 */
if(!s->budget--) { s->failed_pc=0x0c0406a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0406a8;
P_0c0406a8: /* original 6cf6, guest PC 0x0c0406a8 */
if(!s->budget--) { s->failed_pc=0x0c0406a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0406aa;
P_0c0406aa: /* original 6df6, guest PC 0x0c0406aa */
if(!s->budget--) { s->failed_pc=0x0c0406aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0406ac;
P_0c0406ac: /* original 6ef6, guest PC 0x0c0406ac */
if(!s->budget--) { s->failed_pc=0x0c0406acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0406ae;
P_0c0406ae: /* original 000b, guest PC 0x0c0406ae */
if(!s->budget--) { s->failed_pc=0x0c0406aeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0406b0: /* original 0009, guest PC 0x0c0406b0 */
if(!s->budget--) { s->failed_pc=0x0c0406b0u; return 0; }
if(!vf3_matrix_family(0x0c0406b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0406b2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
