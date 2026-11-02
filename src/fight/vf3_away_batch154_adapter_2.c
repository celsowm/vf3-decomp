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
int vf3_away_batch154_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b94e6u: goto P_0c0b94e6;
case 0x0c0b94e8u: goto P_0c0b94e8;
case 0x0c0b94eau: goto P_0c0b94ea;
case 0x0c0b94ecu: goto P_0c0b94ec;
case 0x0c0b94eeu: goto P_0c0b94ee;
case 0x0c0b94f0u: goto P_0c0b94f0;
case 0x0c0b94f2u: goto P_0c0b94f2;
case 0x0c0b94f4u: goto P_0c0b94f4;
case 0x0c0b94f6u: goto P_0c0b94f6;
case 0x0c0b94f8u: goto P_0c0b94f8;
case 0x0c0b94fau: goto P_0c0b94fa;
case 0x0c0b94fcu: goto P_0c0b94fc;
case 0x0c0b94feu: goto P_0c0b94fe;
case 0x0c0b9500u: goto P_0c0b9500;
case 0x0c0b9502u: goto P_0c0b9502;
case 0x0c0b9504u: goto P_0c0b9504;
case 0x0c0b9506u: goto P_0c0b9506;
case 0x0c0b9508u: goto P_0c0b9508;
case 0x0c0b950au: goto P_0c0b950a;
case 0x0c0b950cu: goto P_0c0b950c;
case 0x0c0b950eu: goto P_0c0b950e;
case 0x0c0b9510u: goto P_0c0b9510;
case 0x0c0b9512u: goto P_0c0b9512;
case 0x0c0b9514u: goto P_0c0b9514;
case 0x0c0b9516u: goto P_0c0b9516;
case 0x0c0b9518u: goto P_0c0b9518;
case 0x0c0b951au: goto P_0c0b951a;
case 0x0c0b951cu: goto P_0c0b951c;
case 0x0c0b951eu: goto P_0c0b951e;
case 0x0c0b9520u: goto P_0c0b9520;
case 0x0c0b9522u: goto P_0c0b9522;
case 0x0c0b9524u: goto P_0c0b9524;
case 0x0c0b9526u: goto P_0c0b9526;
case 0x0c0b9528u: goto P_0c0b9528;
case 0x0c0b952au: goto P_0c0b952a;
case 0x0c0b952cu: goto P_0c0b952c;
case 0x0c0b952eu: goto P_0c0b952e;
case 0x0c0b9530u: goto P_0c0b9530;
case 0x0c0b9532u: goto P_0c0b9532;
case 0x0c0b9534u: goto P_0c0b9534;
case 0x0c0b9536u: goto P_0c0b9536;
case 0x0c0b9538u: goto P_0c0b9538;
case 0x0c0b953au: goto P_0c0b953a;
case 0x0c0b953cu: goto P_0c0b953c;
case 0x0c0b953eu: goto P_0c0b953e;
case 0x0c0b9540u: goto P_0c0b9540;
case 0x0c0b9542u: goto P_0c0b9542;
case 0x0c0b9544u: goto P_0c0b9544;
case 0x0c0b9546u: goto P_0c0b9546;
case 0x0c0b9548u: goto P_0c0b9548;
case 0x0c0b954au: goto P_0c0b954a;
case 0x0c0b954cu: goto P_0c0b954c;
case 0x0c0b954eu: goto P_0c0b954e;
case 0x0c0b9550u: goto P_0c0b9550;
case 0x0c0b9552u: goto P_0c0b9552;
case 0x0c0b9554u: goto P_0c0b9554;
case 0x0c0b9556u: goto P_0c0b9556;
case 0x0c0b9558u: goto P_0c0b9558;
case 0x0c0b955au: goto P_0c0b955a;
case 0x0c0b955cu: goto P_0c0b955c;
case 0x0c0b955eu: goto P_0c0b955e;
case 0x0c0b9560u: goto P_0c0b9560;
case 0x0c0b9562u: goto P_0c0b9562;
case 0x0c0b9564u: goto P_0c0b9564;
case 0x0c0b9566u: goto P_0c0b9566;
case 0x0c0b9568u: goto P_0c0b9568;
case 0x0c0b956au: goto P_0c0b956a;
case 0x0c0b956cu: goto P_0c0b956c;
case 0x0c0b956eu: goto P_0c0b956e;
case 0x0c0b9570u: goto P_0c0b9570;
case 0x0c0b9572u: goto P_0c0b9572;
case 0x0c0b9574u: goto P_0c0b9574;
case 0x0c0b9576u: goto P_0c0b9576;
case 0x0c0b9578u: goto P_0c0b9578;
case 0x0c0b957au: goto P_0c0b957a;
case 0x0c0b957cu: goto P_0c0b957c;
case 0x0c0b957eu: goto P_0c0b957e;
case 0x0c0b9580u: goto P_0c0b9580;
case 0x0c0b9582u: goto P_0c0b9582;
case 0x0c0b9584u: goto P_0c0b9584;
case 0x0c0b9586u: goto P_0c0b9586;
case 0x0c0b9588u: goto P_0c0b9588;
case 0x0c0b958au: goto P_0c0b958a;
case 0x0c0b958cu: goto P_0c0b958c;
case 0x0c0b958eu: goto P_0c0b958e;
case 0x0c0b9590u: goto P_0c0b9590;
case 0x0c0b9592u: goto P_0c0b9592;
case 0x0c0b9594u: goto P_0c0b9594;
case 0x0c0b9596u: goto P_0c0b9596;
case 0x0c0b9598u: goto P_0c0b9598;
case 0x0c0b959au: goto P_0c0b959a;
case 0x0c0b959cu: goto P_0c0b959c;
case 0x0c0b959eu: goto P_0c0b959e;
case 0x0c0b95a0u: goto P_0c0b95a0;
case 0x0c0b95a2u: goto P_0c0b95a2;
case 0x0c0b95a4u: goto P_0c0b95a4;
case 0x0c0b95a6u: goto P_0c0b95a6;
case 0x0c0b95a8u: goto P_0c0b95a8;
case 0x0c0b95aau: goto P_0c0b95aa;
case 0x0c0b95acu: goto P_0c0b95ac;
case 0x0c0b95aeu: goto P_0c0b95ae;
case 0x0c0b95b0u: goto P_0c0b95b0;
case 0x0c0b95b2u: goto P_0c0b95b2;
case 0x0c0b95b4u: goto P_0c0b95b4;
case 0x0c0b95b6u: goto P_0c0b95b6;
case 0x0c0b95b8u: goto P_0c0b95b8;
case 0x0c0b95bau: goto P_0c0b95ba;
case 0x0c0b95bcu: goto P_0c0b95bc;
case 0x0c0b95beu: goto P_0c0b95be;
case 0x0c0b95c0u: goto P_0c0b95c0;
case 0x0c0b95c2u: goto P_0c0b95c2;
case 0x0c0b95c4u: goto P_0c0b95c4;
case 0x0c0b95c6u: goto P_0c0b95c6;
case 0x0c0b95c8u: goto P_0c0b95c8;
case 0x0c0b95cau: goto P_0c0b95ca;
case 0x0c0b95ccu: goto P_0c0b95cc;
case 0x0c0b95ceu: goto P_0c0b95ce;
case 0x0c0b95d0u: goto P_0c0b95d0;
case 0x0c0b95d2u: goto P_0c0b95d2;
case 0x0c0b95d4u: goto P_0c0b95d4;
case 0x0c0b95d6u: goto P_0c0b95d6;
case 0x0c0b95d8u: goto P_0c0b95d8;
case 0x0c0b95dau: goto P_0c0b95da;
case 0x0c0b95dcu: goto P_0c0b95dc;
case 0x0c0b95deu: goto P_0c0b95de;
case 0x0c0b95e0u: goto P_0c0b95e0;
case 0x0c0b95e2u: goto P_0c0b95e2;
case 0x0c0b95e4u: goto P_0c0b95e4;
case 0x0c0b95e6u: goto P_0c0b95e6;
case 0x0c0b95e8u: goto P_0c0b95e8;
case 0x0c0b95eau: goto P_0c0b95ea;
case 0x0c0b95ecu: goto P_0c0b95ec;
case 0x0c0b95eeu: goto P_0c0b95ee;
case 0x0c0b95f0u: goto P_0c0b95f0;
case 0x0c0b95f2u: goto P_0c0b95f2;
case 0x0c0b95f4u: goto P_0c0b95f4;
case 0x0c0b95f6u: goto P_0c0b95f6;
case 0x0c0b95f8u: goto P_0c0b95f8;
case 0x0c0b95fau: goto P_0c0b95fa;
case 0x0c0b95fcu: goto P_0c0b95fc;
case 0x0c0b95feu: goto P_0c0b95fe;
case 0x0c0b9600u: goto P_0c0b9600;
case 0x0c0b9602u: goto P_0c0b9602;
case 0x0c0b9604u: goto P_0c0b9604;
case 0x0c0b9606u: goto P_0c0b9606;
case 0x0c0b9608u: goto P_0c0b9608;
case 0x0c0b960au: goto P_0c0b960a;
case 0x0c0b960cu: goto P_0c0b960c;
case 0x0c0b960eu: goto P_0c0b960e;
case 0x0c0b9610u: goto P_0c0b9610;
case 0x0c0b9612u: goto P_0c0b9612;
case 0x0c0b9614u: goto P_0c0b9614;
case 0x0c0b9616u: goto P_0c0b9616;
case 0x0c0b9618u: goto P_0c0b9618;
case 0x0c0b961au: goto P_0c0b961a;
case 0x0c0b961cu: goto P_0c0b961c;
case 0x0c0b961eu: goto P_0c0b961e;
case 0x0c0b9620u: goto P_0c0b9620;
case 0x0c0b9622u: goto P_0c0b9622;
case 0x0c0b9624u: goto P_0c0b9624;
case 0x0c0b9626u: goto P_0c0b9626;
case 0x0c0b9628u: goto P_0c0b9628;
case 0x0c0b962au: goto P_0c0b962a;
case 0x0c0b962cu: goto P_0c0b962c;
case 0x0c0b962eu: goto P_0c0b962e;
case 0x0c0b9630u: goto P_0c0b9630;
case 0x0c0b9632u: goto P_0c0b9632;
case 0x0c0b9634u: goto P_0c0b9634;
case 0x0c0b9636u: goto P_0c0b9636;
case 0x0c0b9638u: goto P_0c0b9638;
case 0x0c0b963au: goto P_0c0b963a;
case 0x0c0b963cu: goto P_0c0b963c;
case 0x0c0b963eu: goto P_0c0b963e;
case 0x0c0b9640u: goto P_0c0b9640;
case 0x0c0b9642u: goto P_0c0b9642;
case 0x0c0b9644u: goto P_0c0b9644;
case 0x0c0b9646u: goto P_0c0b9646;
case 0x0c0b9648u: goto P_0c0b9648;
case 0x0c0b964au: goto P_0c0b964a;
case 0x0c0b964cu: goto P_0c0b964c;
case 0x0c0b964eu: goto P_0c0b964e;
case 0x0c0b96b8u: goto P_0c0b96b8;
case 0x0c0b96bau: goto P_0c0b96ba;
case 0x0c0b96bcu: goto P_0c0b96bc;
case 0x0c0b96beu: goto P_0c0b96be;
case 0x0c0b96c0u: goto P_0c0b96c0;
case 0x0c0b96c2u: goto P_0c0b96c2;
case 0x0c0b96c4u: goto P_0c0b96c4;
case 0x0c0b96c6u: goto P_0c0b96c6;
case 0x0c0b96c8u: goto P_0c0b96c8;
case 0x0c0b96cau: goto P_0c0b96ca;
case 0x0c0b96ccu: goto P_0c0b96cc;
case 0x0c0b96ceu: goto P_0c0b96ce;
case 0x0c0b96d0u: goto P_0c0b96d0;
case 0x0c0b96d2u: goto P_0c0b96d2;
case 0x0c0b96d4u: goto P_0c0b96d4;
case 0x0c0b96d6u: goto P_0c0b96d6;
case 0x0c0b96d8u: goto P_0c0b96d8;
case 0x0c0b96dau: goto P_0c0b96da;
case 0x0c0b96dcu: goto P_0c0b96dc;
case 0x0c0b96deu: goto P_0c0b96de;
case 0x0c0b96e0u: goto P_0c0b96e0;
case 0x0c0b96e2u: goto P_0c0b96e2;
case 0x0c0b96e4u: goto P_0c0b96e4;
case 0x0c0b96e6u: goto P_0c0b96e6;
case 0x0c0b96e8u: goto P_0c0b96e8;
case 0x0c0b96eau: goto P_0c0b96ea;
case 0x0c0b96ecu: goto P_0c0b96ec;
case 0x0c0b96eeu: goto P_0c0b96ee;
case 0x0c0b96f0u: goto P_0c0b96f0;
case 0x0c0b96f2u: goto P_0c0b96f2;
case 0x0c0b96f4u: goto P_0c0b96f4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b94e6: /* original 2fe6, guest PC 0x0c0b94e6 */
if(!s->budget--) { s->failed_pc=0x0c0b94e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b94e8;
P_0c0b94e8: /* original 2fd6, guest PC 0x0c0b94e8 */
if(!s->budget--) { s->failed_pc=0x0c0b94e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b94ea;
P_0c0b94ea: /* original 2fc6, guest PC 0x0c0b94ea */
if(!s->budget--) { s->failed_pc=0x0c0b94eau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b94ec;
P_0c0b94ec: /* original 2fb6, guest PC 0x0c0b94ec */
if(!s->budget--) { s->failed_pc=0x0c0b94ecu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b94ee;
P_0c0b94ee: /* original 2fa6, guest PC 0x0c0b94ee */
if(!s->budget--) { s->failed_pc=0x0c0b94eeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b94f0;
P_0c0b94f0: /* original 2f96, guest PC 0x0c0b94f0 */
if(!s->budget--) { s->failed_pc=0x0c0b94f0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b94f2;
P_0c0b94f2: /* original 4f22, guest PC 0x0c0b94f2 */
if(!s->budget--) { s->failed_pc=0x0c0b94f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b94f4;
P_0c0b94f4: /* original 5d44, guest PC 0x0c0b94f4 */
if(!s->budget--) { s->failed_pc=0x0c0b94f4u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b94f6;
P_0c0b94f6: /* original 94ab, guest PC 0x0c0b94f6 */
if(!s->budget--) { s->failed_pc=0x0c0b94f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9650u,2);
goto P_0c0b94f8;
P_0c0b94f8: /* original de6e, guest PC 0x0c0b94f8 */
if(!s->budget--) { s->failed_pc=0x0c0b94f8u; return 0; }
r[14]=read(ram,0x0c0b96b4u,4);
goto P_0c0b94fa;
P_0c0b94fa: /* original 7ffc, guest PC 0x0c0b94fa */
if(!s->budget--) { s->failed_pc=0x0c0b94fau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0b94fc;
P_0c0b94fc: /* original 4e0b, guest PC 0x0c0b94fc */
if(!s->budget--) { s->failed_pc=0x0c0b94fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9500u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9500u) { target=s->pc; goto dispatch; }
goto P_0c0b9500;
P_0c0b94fe: /* original 65d2, guest PC 0x0c0b94fe */
if(!s->budget--) { s->failed_pc=0x0c0b94feu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b9500;
P_0c0b9500: /* original 94a7, guest PC 0x0c0b9500 */
if(!s->budget--) { s->failed_pc=0x0c0b9500u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9652u,2);
goto P_0c0b9502;
P_0c0b9502: /* original 4e0b, guest PC 0x0c0b9502 */
if(!s->budget--) { s->failed_pc=0x0c0b9502u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9506u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9506u) { target=s->pc; goto dispatch; }
goto P_0c0b9506;
P_0c0b9504: /* original 55d1, guest PC 0x0c0b9504 */
if(!s->budget--) { s->failed_pc=0x0c0b9504u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b9506;
P_0c0b9506: /* original 94a5, guest PC 0x0c0b9506 */
if(!s->budget--) { s->failed_pc=0x0c0b9506u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9654u,2);
goto P_0c0b9508;
P_0c0b9508: /* original 4e0b, guest PC 0x0c0b9508 */
if(!s->budget--) { s->failed_pc=0x0c0b9508u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b950cu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b950cu) { target=s->pc; goto dispatch; }
goto P_0c0b950c;
P_0c0b950a: /* original 55d2, guest PC 0x0c0b950a */
if(!s->budget--) { s->failed_pc=0x0c0b950au; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b950c;
P_0c0b950c: /* original 94a3, guest PC 0x0c0b950c */
if(!s->budget--) { s->failed_pc=0x0c0b950cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9656u,2);
goto P_0c0b950e;
P_0c0b950e: /* original 4e0b, guest PC 0x0c0b950e */
if(!s->budget--) { s->failed_pc=0x0c0b950eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9512u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9512u) { target=s->pc; goto dispatch; }
goto P_0c0b9512;
P_0c0b9510: /* original 55d3, guest PC 0x0c0b9510 */
if(!s->budget--) { s->failed_pc=0x0c0b9510u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b9512;
P_0c0b9512: /* original 94a1, guest PC 0x0c0b9512 */
if(!s->budget--) { s->failed_pc=0x0c0b9512u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9658u,2);
goto P_0c0b9514;
P_0c0b9514: /* original 4e0b, guest PC 0x0c0b9514 */
if(!s->budget--) { s->failed_pc=0x0c0b9514u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9518u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9518u) { target=s->pc; goto dispatch; }
goto P_0c0b9518;
P_0c0b9516: /* original 55d4, guest PC 0x0c0b9516 */
if(!s->budget--) { s->failed_pc=0x0c0b9516u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b9518;
P_0c0b9518: /* original 949f, guest PC 0x0c0b9518 */
if(!s->budget--) { s->failed_pc=0x0c0b9518u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b965au,2);
goto P_0c0b951a;
P_0c0b951a: /* original 4e0b, guest PC 0x0c0b951a */
if(!s->budget--) { s->failed_pc=0x0c0b951au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b951eu;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b951eu) { target=s->pc; goto dispatch; }
goto P_0c0b951e;
P_0c0b951c: /* original 55d5, guest PC 0x0c0b951c */
if(!s->budget--) { s->failed_pc=0x0c0b951cu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b951e;
P_0c0b951e: /* original 949d, guest PC 0x0c0b951e */
if(!s->budget--) { s->failed_pc=0x0c0b951eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b965cu,2);
goto P_0c0b9520;
P_0c0b9520: /* original 69d3, guest PC 0x0c0b9520 */
if(!s->budget--) { s->failed_pc=0x0c0b9520u; return 0; }
r[9]=r[13];
goto P_0c0b9522;
P_0c0b9522: /* original 7918, guest PC 0x0c0b9522 */
if(!s->budget--) { s->failed_pc=0x0c0b9522u; return 0; }
r[9]+=0x00000018u;
goto P_0c0b9524;
P_0c0b9524: /* original 4e0b, guest PC 0x0c0b9524 */
if(!s->budget--) { s->failed_pc=0x0c0b9524u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9528u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9528u) { target=s->pc; goto dispatch; }
goto P_0c0b9528;
P_0c0b9526: /* original 6592, guest PC 0x0c0b9526 */
if(!s->budget--) { s->failed_pc=0x0c0b9526u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b9528;
P_0c0b9528: /* original 9499, guest PC 0x0c0b9528 */
if(!s->budget--) { s->failed_pc=0x0c0b9528u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b965eu,2);
goto P_0c0b952a;
P_0c0b952a: /* original 4e0b, guest PC 0x0c0b952a */
if(!s->budget--) { s->failed_pc=0x0c0b952au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b952eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b952eu) { target=s->pc; goto dispatch; }
goto P_0c0b952e;
P_0c0b952c: /* original 6592, guest PC 0x0c0b952c */
if(!s->budget--) { s->failed_pc=0x0c0b952cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b952e;
P_0c0b952e: /* original 9497, guest PC 0x0c0b952e */
if(!s->budget--) { s->failed_pc=0x0c0b952eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9660u,2);
goto P_0c0b9530;
P_0c0b9530: /* original 4e0b, guest PC 0x0c0b9530 */
if(!s->budget--) { s->failed_pc=0x0c0b9530u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9534u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9534u) { target=s->pc; goto dispatch; }
goto P_0c0b9534;
P_0c0b9532: /* original 6592, guest PC 0x0c0b9532 */
if(!s->budget--) { s->failed_pc=0x0c0b9532u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b9534;
P_0c0b9534: /* original 9495, guest PC 0x0c0b9534 */
if(!s->budget--) { s->failed_pc=0x0c0b9534u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9662u,2);
goto P_0c0b9536;
P_0c0b9536: /* original 4e0b, guest PC 0x0c0b9536 */
if(!s->budget--) { s->failed_pc=0x0c0b9536u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b953au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b953au) { target=s->pc; goto dispatch; }
goto P_0c0b953a;
P_0c0b9538: /* original 6592, guest PC 0x0c0b9538 */
if(!s->budget--) { s->failed_pc=0x0c0b9538u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b953a;
P_0c0b953a: /* original 9493, guest PC 0x0c0b953a */
if(!s->budget--) { s->failed_pc=0x0c0b953au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9664u,2);
goto P_0c0b953c;
P_0c0b953c: /* original 6cd3, guest PC 0x0c0b953c */
if(!s->budget--) { s->failed_pc=0x0c0b953cu; return 0; }
r[12]=r[13];
goto P_0c0b953e;
P_0c0b953e: /* original 7c1c, guest PC 0x0c0b953e */
if(!s->budget--) { s->failed_pc=0x0c0b953eu; return 0; }
r[12]+=0x0000001cu;
goto P_0c0b9540;
P_0c0b9540: /* original 4e0b, guest PC 0x0c0b9540 */
if(!s->budget--) { s->failed_pc=0x0c0b9540u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9544u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9544u) { target=s->pc; goto dispatch; }
goto P_0c0b9544;
P_0c0b9542: /* original 65c2, guest PC 0x0c0b9542 */
if(!s->budget--) { s->failed_pc=0x0c0b9542u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9544;
P_0c0b9544: /* original 948f, guest PC 0x0c0b9544 */
if(!s->budget--) { s->failed_pc=0x0c0b9544u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9666u,2);
goto P_0c0b9546;
P_0c0b9546: /* original 4e0b, guest PC 0x0c0b9546 */
if(!s->budget--) { s->failed_pc=0x0c0b9546u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b954au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b954au) { target=s->pc; goto dispatch; }
goto P_0c0b954a;
P_0c0b9548: /* original 65c2, guest PC 0x0c0b9548 */
if(!s->budget--) { s->failed_pc=0x0c0b9548u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b954a;
P_0c0b954a: /* original 948d, guest PC 0x0c0b954a */
if(!s->budget--) { s->failed_pc=0x0c0b954au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9668u,2);
goto P_0c0b954c;
P_0c0b954c: /* original 4e0b, guest PC 0x0c0b954c */
if(!s->budget--) { s->failed_pc=0x0c0b954cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9550u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9550u) { target=s->pc; goto dispatch; }
goto P_0c0b9550;
P_0c0b954e: /* original 65c2, guest PC 0x0c0b954e */
if(!s->budget--) { s->failed_pc=0x0c0b954eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9550;
P_0c0b9550: /* original 948b, guest PC 0x0c0b9550 */
if(!s->budget--) { s->failed_pc=0x0c0b9550u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b966au,2);
goto P_0c0b9552;
P_0c0b9552: /* original 4e0b, guest PC 0x0c0b9552 */
if(!s->budget--) { s->failed_pc=0x0c0b9552u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9556u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9556u) { target=s->pc; goto dispatch; }
goto P_0c0b9556;
P_0c0b9554: /* original 65c2, guest PC 0x0c0b9554 */
if(!s->budget--) { s->failed_pc=0x0c0b9554u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b9556;
P_0c0b9556: /* original 9489, guest PC 0x0c0b9556 */
if(!s->budget--) { s->failed_pc=0x0c0b9556u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b966cu,2);
goto P_0c0b9558;
P_0c0b9558: /* original 6bd3, guest PC 0x0c0b9558 */
if(!s->budget--) { s->failed_pc=0x0c0b9558u; return 0; }
r[11]=r[13];
goto P_0c0b955a;
P_0c0b955a: /* original 7b20, guest PC 0x0c0b955a */
if(!s->budget--) { s->failed_pc=0x0c0b955au; return 0; }
r[11]+=0x00000020u;
goto P_0c0b955c;
P_0c0b955c: /* original 4e0b, guest PC 0x0c0b955c */
if(!s->budget--) { s->failed_pc=0x0c0b955cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9560u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9560u) { target=s->pc; goto dispatch; }
goto P_0c0b9560;
P_0c0b955e: /* original 65b2, guest PC 0x0c0b955e */
if(!s->budget--) { s->failed_pc=0x0c0b955eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9560;
P_0c0b9560: /* original 9485, guest PC 0x0c0b9560 */
if(!s->budget--) { s->failed_pc=0x0c0b9560u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b966eu,2);
goto P_0c0b9562;
P_0c0b9562: /* original 4e0b, guest PC 0x0c0b9562 */
if(!s->budget--) { s->failed_pc=0x0c0b9562u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9566u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9566u) { target=s->pc; goto dispatch; }
goto P_0c0b9566;
P_0c0b9564: /* original 65b2, guest PC 0x0c0b9564 */
if(!s->budget--) { s->failed_pc=0x0c0b9564u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9566;
P_0c0b9566: /* original 9483, guest PC 0x0c0b9566 */
if(!s->budget--) { s->failed_pc=0x0c0b9566u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9670u,2);
goto P_0c0b9568;
P_0c0b9568: /* original 4e0b, guest PC 0x0c0b9568 */
if(!s->budget--) { s->failed_pc=0x0c0b9568u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b956cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b956cu) { target=s->pc; goto dispatch; }
goto P_0c0b956c;
P_0c0b956a: /* original 65b2, guest PC 0x0c0b956a */
if(!s->budget--) { s->failed_pc=0x0c0b956au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b956c;
P_0c0b956c: /* original 9481, guest PC 0x0c0b956c */
if(!s->budget--) { s->failed_pc=0x0c0b956cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9672u,2);
goto P_0c0b956e;
P_0c0b956e: /* original 4e0b, guest PC 0x0c0b956e */
if(!s->budget--) { s->failed_pc=0x0c0b956eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9572u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9572u) { target=s->pc; goto dispatch; }
goto P_0c0b9572;
P_0c0b9570: /* original 65b2, guest PC 0x0c0b9570 */
if(!s->budget--) { s->failed_pc=0x0c0b9570u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b9572;
P_0c0b9572: /* original 947f, guest PC 0x0c0b9572 */
if(!s->budget--) { s->failed_pc=0x0c0b9572u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9674u,2);
goto P_0c0b9574;
P_0c0b9574: /* original 6ad3, guest PC 0x0c0b9574 */
if(!s->budget--) { s->failed_pc=0x0c0b9574u; return 0; }
r[10]=r[13];
goto P_0c0b9576;
P_0c0b9576: /* original 7a24, guest PC 0x0c0b9576 */
if(!s->budget--) { s->failed_pc=0x0c0b9576u; return 0; }
r[10]+=0x00000024u;
goto P_0c0b9578;
P_0c0b9578: /* original 4e0b, guest PC 0x0c0b9578 */
if(!s->budget--) { s->failed_pc=0x0c0b9578u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b957cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b957cu) { target=s->pc; goto dispatch; }
goto P_0c0b957c;
P_0c0b957a: /* original 65a2, guest PC 0x0c0b957a */
if(!s->budget--) { s->failed_pc=0x0c0b957au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b957c;
P_0c0b957c: /* original 947b, guest PC 0x0c0b957c */
if(!s->budget--) { s->failed_pc=0x0c0b957cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9676u,2);
goto P_0c0b957e;
P_0c0b957e: /* original 4e0b, guest PC 0x0c0b957e */
if(!s->budget--) { s->failed_pc=0x0c0b957eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9582u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9582u) { target=s->pc; goto dispatch; }
goto P_0c0b9582;
P_0c0b9580: /* original 65a2, guest PC 0x0c0b9580 */
if(!s->budget--) { s->failed_pc=0x0c0b9580u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9582;
P_0c0b9582: /* original 9479, guest PC 0x0c0b9582 */
if(!s->budget--) { s->failed_pc=0x0c0b9582u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9678u,2);
goto P_0c0b9584;
P_0c0b9584: /* original 4e0b, guest PC 0x0c0b9584 */
if(!s->budget--) { s->failed_pc=0x0c0b9584u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9588u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9588u) { target=s->pc; goto dispatch; }
goto P_0c0b9588;
P_0c0b9586: /* original 65a2, guest PC 0x0c0b9586 */
if(!s->budget--) { s->failed_pc=0x0c0b9586u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b9588;
P_0c0b9588: /* original 9477, guest PC 0x0c0b9588 */
if(!s->budget--) { s->failed_pc=0x0c0b9588u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b967au,2);
goto P_0c0b958a;
P_0c0b958a: /* original 4e0b, guest PC 0x0c0b958a */
if(!s->budget--) { s->failed_pc=0x0c0b958au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b958eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b958eu) { target=s->pc; goto dispatch; }
goto P_0c0b958e;
P_0c0b958c: /* original 65a2, guest PC 0x0c0b958c */
if(!s->budget--) { s->failed_pc=0x0c0b958cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b958e;
P_0c0b958e: /* original 9475, guest PC 0x0c0b958e */
if(!s->budget--) { s->failed_pc=0x0c0b958eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b967cu,2);
goto P_0c0b9590;
P_0c0b9590: /* original 4e0b, guest PC 0x0c0b9590 */
if(!s->budget--) { s->failed_pc=0x0c0b9590u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9594u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9594u) { target=s->pc; goto dispatch; }
goto P_0c0b9594;
P_0c0b9592: /* original 6592, guest PC 0x0c0b9592 */
if(!s->budget--) { s->failed_pc=0x0c0b9592u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b9594;
P_0c0b9594: /* original 9473, guest PC 0x0c0b9594 */
if(!s->budget--) { s->failed_pc=0x0c0b9594u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b967eu,2);
goto P_0c0b9596;
P_0c0b9596: /* original 4e0b, guest PC 0x0c0b9596 */
if(!s->budget--) { s->failed_pc=0x0c0b9596u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b959au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b959au) { target=s->pc; goto dispatch; }
goto P_0c0b959a;
P_0c0b9598: /* original 6592, guest PC 0x0c0b9598 */
if(!s->budget--) { s->failed_pc=0x0c0b9598u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b959a;
P_0c0b959a: /* original 9471, guest PC 0x0c0b959a */
if(!s->budget--) { s->failed_pc=0x0c0b959au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9680u,2);
goto P_0c0b959c;
P_0c0b959c: /* original 4e0b, guest PC 0x0c0b959c */
if(!s->budget--) { s->failed_pc=0x0c0b959cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95a0u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95a0u) { target=s->pc; goto dispatch; }
goto P_0c0b95a0;
P_0c0b959e: /* original 6592, guest PC 0x0c0b959e */
if(!s->budget--) { s->failed_pc=0x0c0b959eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b95a0;
P_0c0b95a0: /* original 946f, guest PC 0x0c0b95a0 */
if(!s->budget--) { s->failed_pc=0x0c0b95a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9682u,2);
goto P_0c0b95a2;
P_0c0b95a2: /* original 4e0b, guest PC 0x0c0b95a2 */
if(!s->budget--) { s->failed_pc=0x0c0b95a2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95a6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95a6u) { target=s->pc; goto dispatch; }
goto P_0c0b95a6;
P_0c0b95a4: /* original 6592, guest PC 0x0c0b95a4 */
if(!s->budget--) { s->failed_pc=0x0c0b95a4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b95a6;
P_0c0b95a6: /* original 946d, guest PC 0x0c0b95a6 */
if(!s->budget--) { s->failed_pc=0x0c0b95a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9684u,2);
goto P_0c0b95a8;
P_0c0b95a8: /* original 4e0b, guest PC 0x0c0b95a8 */
if(!s->budget--) { s->failed_pc=0x0c0b95a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95acu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95acu) { target=s->pc; goto dispatch; }
goto P_0c0b95ac;
P_0c0b95aa: /* original 65c2, guest PC 0x0c0b95aa */
if(!s->budget--) { s->failed_pc=0x0c0b95aau; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b95ac;
P_0c0b95ac: /* original 946b, guest PC 0x0c0b95ac */
if(!s->budget--) { s->failed_pc=0x0c0b95acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9686u,2);
goto P_0c0b95ae;
P_0c0b95ae: /* original 4e0b, guest PC 0x0c0b95ae */
if(!s->budget--) { s->failed_pc=0x0c0b95aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95b2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95b2u) { target=s->pc; goto dispatch; }
goto P_0c0b95b2;
P_0c0b95b0: /* original 65c2, guest PC 0x0c0b95b0 */
if(!s->budget--) { s->failed_pc=0x0c0b95b0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b95b2;
P_0c0b95b2: /* original 9469, guest PC 0x0c0b95b2 */
if(!s->budget--) { s->failed_pc=0x0c0b95b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9688u,2);
goto P_0c0b95b4;
P_0c0b95b4: /* original 4e0b, guest PC 0x0c0b95b4 */
if(!s->budget--) { s->failed_pc=0x0c0b95b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95b8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95b8u) { target=s->pc; goto dispatch; }
goto P_0c0b95b8;
P_0c0b95b6: /* original 65c2, guest PC 0x0c0b95b6 */
if(!s->budget--) { s->failed_pc=0x0c0b95b6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b95b8;
P_0c0b95b8: /* original 9467, guest PC 0x0c0b95b8 */
if(!s->budget--) { s->failed_pc=0x0c0b95b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b968au,2);
goto P_0c0b95ba;
P_0c0b95ba: /* original 4e0b, guest PC 0x0c0b95ba */
if(!s->budget--) { s->failed_pc=0x0c0b95bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95beu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95beu) { target=s->pc; goto dispatch; }
goto P_0c0b95be;
P_0c0b95bc: /* original 65c2, guest PC 0x0c0b95bc */
if(!s->budget--) { s->failed_pc=0x0c0b95bcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b95be;
P_0c0b95be: /* original 9465, guest PC 0x0c0b95be */
if(!s->budget--) { s->failed_pc=0x0c0b95beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b968cu,2);
goto P_0c0b95c0;
P_0c0b95c0: /* original 4e0b, guest PC 0x0c0b95c0 */
if(!s->budget--) { s->failed_pc=0x0c0b95c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95c4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95c4u) { target=s->pc; goto dispatch; }
goto P_0c0b95c4;
P_0c0b95c2: /* original 65b2, guest PC 0x0c0b95c2 */
if(!s->budget--) { s->failed_pc=0x0c0b95c2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b95c4;
P_0c0b95c4: /* original 9463, guest PC 0x0c0b95c4 */
if(!s->budget--) { s->failed_pc=0x0c0b95c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b968eu,2);
goto P_0c0b95c6;
P_0c0b95c6: /* original 4e0b, guest PC 0x0c0b95c6 */
if(!s->budget--) { s->failed_pc=0x0c0b95c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95cau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95cau) { target=s->pc; goto dispatch; }
goto P_0c0b95ca;
P_0c0b95c8: /* original 65b2, guest PC 0x0c0b95c8 */
if(!s->budget--) { s->failed_pc=0x0c0b95c8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b95ca;
P_0c0b95ca: /* original 9461, guest PC 0x0c0b95ca */
if(!s->budget--) { s->failed_pc=0x0c0b95cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9690u,2);
goto P_0c0b95cc;
P_0c0b95cc: /* original 4e0b, guest PC 0x0c0b95cc */
if(!s->budget--) { s->failed_pc=0x0c0b95ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95d0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95d0u) { target=s->pc; goto dispatch; }
goto P_0c0b95d0;
P_0c0b95ce: /* original 65b2, guest PC 0x0c0b95ce */
if(!s->budget--) { s->failed_pc=0x0c0b95ceu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b95d0;
P_0c0b95d0: /* original 945f, guest PC 0x0c0b95d0 */
if(!s->budget--) { s->failed_pc=0x0c0b95d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9692u,2);
goto P_0c0b95d2;
P_0c0b95d2: /* original 4e0b, guest PC 0x0c0b95d2 */
if(!s->budget--) { s->failed_pc=0x0c0b95d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95d6u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95d6u) { target=s->pc; goto dispatch; }
goto P_0c0b95d6;
P_0c0b95d4: /* original 65b2, guest PC 0x0c0b95d4 */
if(!s->budget--) { s->failed_pc=0x0c0b95d4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b95d6;
P_0c0b95d6: /* original 945d, guest PC 0x0c0b95d6 */
if(!s->budget--) { s->failed_pc=0x0c0b95d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9694u,2);
goto P_0c0b95d8;
P_0c0b95d8: /* original 4e0b, guest PC 0x0c0b95d8 */
if(!s->budget--) { s->failed_pc=0x0c0b95d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95dcu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95dcu) { target=s->pc; goto dispatch; }
goto P_0c0b95dc;
P_0c0b95da: /* original 65a2, guest PC 0x0c0b95da */
if(!s->budget--) { s->failed_pc=0x0c0b95dau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b95dc;
P_0c0b95dc: /* original 945b, guest PC 0x0c0b95dc */
if(!s->budget--) { s->failed_pc=0x0c0b95dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9696u,2);
goto P_0c0b95de;
P_0c0b95de: /* original 4e0b, guest PC 0x0c0b95de */
if(!s->budget--) { s->failed_pc=0x0c0b95deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95e2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95e2u) { target=s->pc; goto dispatch; }
goto P_0c0b95e2;
P_0c0b95e0: /* original 65a2, guest PC 0x0c0b95e0 */
if(!s->budget--) { s->failed_pc=0x0c0b95e0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b95e2;
P_0c0b95e2: /* original 9459, guest PC 0x0c0b95e2 */
if(!s->budget--) { s->failed_pc=0x0c0b95e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9698u,2);
goto P_0c0b95e4;
P_0c0b95e4: /* original 4e0b, guest PC 0x0c0b95e4 */
if(!s->budget--) { s->failed_pc=0x0c0b95e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95e8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95e8u) { target=s->pc; goto dispatch; }
goto P_0c0b95e8;
P_0c0b95e6: /* original 65a2, guest PC 0x0c0b95e6 */
if(!s->budget--) { s->failed_pc=0x0c0b95e6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b95e8;
P_0c0b95e8: /* original 9457, guest PC 0x0c0b95e8 */
if(!s->budget--) { s->failed_pc=0x0c0b95e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b969au,2);
goto P_0c0b95ea;
P_0c0b95ea: /* original 4e0b, guest PC 0x0c0b95ea */
if(!s->budget--) { s->failed_pc=0x0c0b95eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95eeu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95eeu) { target=s->pc; goto dispatch; }
goto P_0c0b95ee;
P_0c0b95ec: /* original 65a2, guest PC 0x0c0b95ec */
if(!s->budget--) { s->failed_pc=0x0c0b95ecu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b95ee;
P_0c0b95ee: /* original 65d3, guest PC 0x0c0b95ee */
if(!s->budget--) { s->failed_pc=0x0c0b95eeu; return 0; }
r[5]=r[13];
goto P_0c0b95f0;
P_0c0b95f0: /* original 7548, guest PC 0x0c0b95f0 */
if(!s->budget--) { s->failed_pc=0x0c0b95f0u; return 0; }
r[5]+=0x00000048u;
goto P_0c0b95f2;
P_0c0b95f2: /* original 2f52, guest PC 0x0c0b95f2 */
if(!s->budget--) { s->failed_pc=0x0c0b95f2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b95f4;
P_0c0b95f4: /* original 9452, guest PC 0x0c0b95f4 */
if(!s->budget--) { s->failed_pc=0x0c0b95f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b969cu,2);
goto P_0c0b95f6;
P_0c0b95f6: /* original 4e0b, guest PC 0x0c0b95f6 */
if(!s->budget--) { s->failed_pc=0x0c0b95f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b95fau;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b95fau) { target=s->pc; goto dispatch; }
goto P_0c0b95fa;
P_0c0b95f8: /* original 6552, guest PC 0x0c0b95f8 */
if(!s->budget--) { s->failed_pc=0x0c0b95f8u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b95fa;
P_0c0b95fa: /* original 9450, guest PC 0x0c0b95fa */
if(!s->budget--) { s->failed_pc=0x0c0b95fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b969eu,2);
goto P_0c0b95fc;
P_0c0b95fc: /* original 65f2, guest PC 0x0c0b95fc */
if(!s->budget--) { s->failed_pc=0x0c0b95fcu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b95fe;
P_0c0b95fe: /* original 4e0b, guest PC 0x0c0b95fe */
if(!s->budget--) { s->failed_pc=0x0c0b95feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9602u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9602u) { target=s->pc; goto dispatch; }
goto P_0c0b9602;
P_0c0b9600: /* original 6552, guest PC 0x0c0b9600 */
if(!s->budget--) { s->failed_pc=0x0c0b9600u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9602;
P_0c0b9602: /* original 65d3, guest PC 0x0c0b9602 */
if(!s->budget--) { s->failed_pc=0x0c0b9602u; return 0; }
r[5]=r[13];
goto P_0c0b9604;
P_0c0b9604: /* original 7544, guest PC 0x0c0b9604 */
if(!s->budget--) { s->failed_pc=0x0c0b9604u; return 0; }
r[5]+=0x00000044u;
goto P_0c0b9606;
P_0c0b9606: /* original 2f52, guest PC 0x0c0b9606 */
if(!s->budget--) { s->failed_pc=0x0c0b9606u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b9608;
P_0c0b9608: /* original 944a, guest PC 0x0c0b9608 */
if(!s->budget--) { s->failed_pc=0x0c0b9608u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96a0u,2);
goto P_0c0b960a;
P_0c0b960a: /* original 4e0b, guest PC 0x0c0b960a */
if(!s->budget--) { s->failed_pc=0x0c0b960au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b960eu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b960eu) { target=s->pc; goto dispatch; }
goto P_0c0b960e;
P_0c0b960c: /* original 6552, guest PC 0x0c0b960c */
if(!s->budget--) { s->failed_pc=0x0c0b960cu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b960e;
P_0c0b960e: /* original 9448, guest PC 0x0c0b960e */
if(!s->budget--) { s->failed_pc=0x0c0b960eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96a2u,2);
goto P_0c0b9610;
P_0c0b9610: /* original 65f2, guest PC 0x0c0b9610 */
if(!s->budget--) { s->failed_pc=0x0c0b9610u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9612;
P_0c0b9612: /* original 4e0b, guest PC 0x0c0b9612 */
if(!s->budget--) { s->failed_pc=0x0c0b9612u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9616u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9616u) { target=s->pc; goto dispatch; }
goto P_0c0b9616;
P_0c0b9614: /* original 6552, guest PC 0x0c0b9614 */
if(!s->budget--) { s->failed_pc=0x0c0b9614u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9616;
P_0c0b9616: /* original 9445, guest PC 0x0c0b9616 */
if(!s->budget--) { s->failed_pc=0x0c0b9616u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96a4u,2);
goto P_0c0b9618;
P_0c0b9618: /* original 4e0b, guest PC 0x0c0b9618 */
if(!s->budget--) { s->failed_pc=0x0c0b9618u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b961cu;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b961cu) { target=s->pc; goto dispatch; }
goto P_0c0b961c;
P_0c0b961a: /* original 55db, guest PC 0x0c0b961a */
if(!s->budget--) { s->failed_pc=0x0c0b961au; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b961c;
P_0c0b961c: /* original 65d3, guest PC 0x0c0b961c */
if(!s->budget--) { s->failed_pc=0x0c0b961cu; return 0; }
r[5]=r[13];
goto P_0c0b961e;
P_0c0b961e: /* original 7530, guest PC 0x0c0b961e */
if(!s->budget--) { s->failed_pc=0x0c0b961eu; return 0; }
r[5]+=0x00000030u;
goto P_0c0b9620;
P_0c0b9620: /* original 2f52, guest PC 0x0c0b9620 */
if(!s->budget--) { s->failed_pc=0x0c0b9620u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b9622;
P_0c0b9622: /* original 9440, guest PC 0x0c0b9622 */
if(!s->budget--) { s->failed_pc=0x0c0b9622u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96a6u,2);
goto P_0c0b9624;
P_0c0b9624: /* original 4e0b, guest PC 0x0c0b9624 */
if(!s->budget--) { s->failed_pc=0x0c0b9624u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9628u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9628u) { target=s->pc; goto dispatch; }
goto P_0c0b9628;
P_0c0b9626: /* original 6552, guest PC 0x0c0b9626 */
if(!s->budget--) { s->failed_pc=0x0c0b9626u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9628;
P_0c0b9628: /* original 943e, guest PC 0x0c0b9628 */
if(!s->budget--) { s->failed_pc=0x0c0b9628u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96a8u,2);
goto P_0c0b962a;
P_0c0b962a: /* original 65f2, guest PC 0x0c0b962a */
if(!s->budget--) { s->failed_pc=0x0c0b962au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b962c;
P_0c0b962c: /* original 4e0b, guest PC 0x0c0b962c */
if(!s->budget--) { s->failed_pc=0x0c0b962cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9630u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9630u) { target=s->pc; goto dispatch; }
goto P_0c0b9630;
P_0c0b962e: /* original 6552, guest PC 0x0c0b962e */
if(!s->budget--) { s->failed_pc=0x0c0b962eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9630;
P_0c0b9630: /* original 943b, guest PC 0x0c0b9630 */
if(!s->budget--) { s->failed_pc=0x0c0b9630u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96aau,2);
goto P_0c0b9632;
P_0c0b9632: /* original 4e0b, guest PC 0x0c0b9632 */
if(!s->budget--) { s->failed_pc=0x0c0b9632u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9636u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9636u) { target=s->pc; goto dispatch; }
goto P_0c0b9636;
P_0c0b9634: /* original 55df, guest PC 0x0c0b9634 */
if(!s->budget--) { s->failed_pc=0x0c0b9634u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b9636;
P_0c0b9636: /* original 65d3, guest PC 0x0c0b9636 */
if(!s->budget--) { s->failed_pc=0x0c0b9636u; return 0; }
r[5]=r[13];
goto P_0c0b9638;
P_0c0b9638: /* original 7540, guest PC 0x0c0b9638 */
if(!s->budget--) { s->failed_pc=0x0c0b9638u; return 0; }
r[5]+=0x00000040u;
goto P_0c0b963a;
P_0c0b963a: /* original 2f52, guest PC 0x0c0b963a */
if(!s->budget--) { s->failed_pc=0x0c0b963au; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b963c;
P_0c0b963c: /* original 9436, guest PC 0x0c0b963c */
if(!s->budget--) { s->failed_pc=0x0c0b963cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96acu,2);
goto P_0c0b963e;
P_0c0b963e: /* original 4e0b, guest PC 0x0c0b963e */
if(!s->budget--) { s->failed_pc=0x0c0b963eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9642u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9642u) { target=s->pc; goto dispatch; }
goto P_0c0b9642;
P_0c0b9640: /* original 6552, guest PC 0x0c0b9640 */
if(!s->budget--) { s->failed_pc=0x0c0b9640u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b9642;
P_0c0b9642: /* original 9434, guest PC 0x0c0b9642 */
if(!s->budget--) { s->failed_pc=0x0c0b9642u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96aeu,2);
goto P_0c0b9644;
P_0c0b9644: /* original 65f2, guest PC 0x0c0b9644 */
if(!s->budget--) { s->failed_pc=0x0c0b9644u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b9646;
P_0c0b9646: /* original 4e0b, guest PC 0x0c0b9646 */
if(!s->budget--) { s->failed_pc=0x0c0b9646u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b964au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b964au) { target=s->pc; goto dispatch; }
goto P_0c0b964a;
P_0c0b9648: /* original 6552, guest PC 0x0c0b9648 */
if(!s->budget--) { s->failed_pc=0x0c0b9648u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b964a;
P_0c0b964a: /* original 9431, guest PC 0x0c0b964a */
if(!s->budget--) { s->failed_pc=0x0c0b964au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96b0u,2);
goto P_0c0b964c;
P_0c0b964c: /* original a034, guest PC 0x0c0b964c */
if(!s->budget--) { s->failed_pc=0x0c0b964cu; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b96b8;
P_0c0b964e: /* original 55da, guest PC 0x0c0b964e */
if(!s->budget--) { s->failed_pc=0x0c0b964eu; return 0; }
r[5]=read(ram,r[13]+40,4);
if(!vf3_matrix_family(0x0c0b9650u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b9650u; return 0; } return 1;
P_0c0b96b8: /* original 4e0b, guest PC 0x0c0b96b8 */
if(!s->budget--) { s->failed_pc=0x0c0b96b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b96bcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b96bcu) { target=s->pc; goto dispatch; }
goto P_0c0b96bc;
P_0c0b96ba: /* original 0009, guest PC 0x0c0b96ba */
if(!s->budget--) { s->failed_pc=0x0c0b96bau; return 0; }
goto P_0c0b96bc;
P_0c0b96bc: /* original 65d3, guest PC 0x0c0b96bc */
if(!s->budget--) { s->failed_pc=0x0c0b96bcu; return 0; }
r[5]=r[13];
goto P_0c0b96be;
P_0c0b96be: /* original 7538, guest PC 0x0c0b96be */
if(!s->budget--) { s->failed_pc=0x0c0b96beu; return 0; }
r[5]+=0x00000038u;
goto P_0c0b96c0;
P_0c0b96c0: /* original 2f52, guest PC 0x0c0b96c0 */
if(!s->budget--) { s->failed_pc=0x0c0b96c0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b96c2;
P_0c0b96c2: /* original 9418, guest PC 0x0c0b96c2 */
if(!s->budget--) { s->failed_pc=0x0c0b96c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96f6u,2);
goto P_0c0b96c4;
P_0c0b96c4: /* original 4e0b, guest PC 0x0c0b96c4 */
if(!s->budget--) { s->failed_pc=0x0c0b96c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b96c8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b96c8u) { target=s->pc; goto dispatch; }
goto P_0c0b96c8;
P_0c0b96c6: /* original 6552, guest PC 0x0c0b96c6 */
if(!s->budget--) { s->failed_pc=0x0c0b96c6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b96c8;
P_0c0b96c8: /* original 9416, guest PC 0x0c0b96c8 */
if(!s->budget--) { s->failed_pc=0x0c0b96c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96f8u,2);
goto P_0c0b96ca;
P_0c0b96ca: /* original 65f2, guest PC 0x0c0b96ca */
if(!s->budget--) { s->failed_pc=0x0c0b96cau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b96cc;
P_0c0b96cc: /* original 4e0b, guest PC 0x0c0b96cc */
if(!s->budget--) { s->failed_pc=0x0c0b96ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b96d0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b96d0u) { target=s->pc; goto dispatch; }
goto P_0c0b96d0;
P_0c0b96ce: /* original 6552, guest PC 0x0c0b96ce */
if(!s->budget--) { s->failed_pc=0x0c0b96ceu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b96d0;
P_0c0b96d0: /* original 65d3, guest PC 0x0c0b96d0 */
if(!s->budget--) { s->failed_pc=0x0c0b96d0u; return 0; }
r[5]=r[13];
goto P_0c0b96d2;
P_0c0b96d2: /* original 7534, guest PC 0x0c0b96d2 */
if(!s->budget--) { s->failed_pc=0x0c0b96d2u; return 0; }
r[5]+=0x00000034u;
goto P_0c0b96d4;
P_0c0b96d4: /* original 2f52, guest PC 0x0c0b96d4 */
if(!s->budget--) { s->failed_pc=0x0c0b96d4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b96d6;
P_0c0b96d6: /* original 9410, guest PC 0x0c0b96d6 */
if(!s->budget--) { s->failed_pc=0x0c0b96d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96fau,2);
goto P_0c0b96d8;
P_0c0b96d8: /* original 4e0b, guest PC 0x0c0b96d8 */
if(!s->budget--) { s->failed_pc=0x0c0b96d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b96dcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b96dcu) { target=s->pc; goto dispatch; }
goto P_0c0b96dc;
P_0c0b96da: /* original 6552, guest PC 0x0c0b96da */
if(!s->budget--) { s->failed_pc=0x0c0b96dau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b96dc;
P_0c0b96dc: /* original 940e, guest PC 0x0c0b96dc */
if(!s->budget--) { s->failed_pc=0x0c0b96dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b96fcu,2);
goto P_0c0b96de;
P_0c0b96de: /* original 65f2, guest PC 0x0c0b96de */
if(!s->budget--) { s->failed_pc=0x0c0b96deu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b96e0;
P_0c0b96e0: /* original 4e0b, guest PC 0x0c0b96e0 */
if(!s->budget--) { s->failed_pc=0x0c0b96e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b96e4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b96e4u) { target=s->pc; goto dispatch; }
goto P_0c0b96e4;
P_0c0b96e2: /* original 6552, guest PC 0x0c0b96e2 */
if(!s->budget--) { s->failed_pc=0x0c0b96e2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b96e4;
P_0c0b96e4: /* original 7f04, guest PC 0x0c0b96e4 */
if(!s->budget--) { s->failed_pc=0x0c0b96e4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0b96e6;
P_0c0b96e6: /* original 4f26, guest PC 0x0c0b96e6 */
if(!s->budget--) { s->failed_pc=0x0c0b96e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b96e8;
P_0c0b96e8: /* original 69f6, guest PC 0x0c0b96e8 */
if(!s->budget--) { s->failed_pc=0x0c0b96e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b96ea;
P_0c0b96ea: /* original 6af6, guest PC 0x0c0b96ea */
if(!s->budget--) { s->failed_pc=0x0c0b96eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b96ec;
P_0c0b96ec: /* original 6bf6, guest PC 0x0c0b96ec */
if(!s->budget--) { s->failed_pc=0x0c0b96ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b96ee;
P_0c0b96ee: /* original 6cf6, guest PC 0x0c0b96ee */
if(!s->budget--) { s->failed_pc=0x0c0b96eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b96f0;
P_0c0b96f0: /* original 6df6, guest PC 0x0c0b96f0 */
if(!s->budget--) { s->failed_pc=0x0c0b96f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b96f2;
P_0c0b96f2: /* original 000b, guest PC 0x0c0b96f2 */
if(!s->budget--) { s->failed_pc=0x0c0b96f2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b96f4: /* original 6ef6, guest PC 0x0c0b96f4 */
if(!s->budget--) { s->failed_pc=0x0c0b96f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b96f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b96f6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
