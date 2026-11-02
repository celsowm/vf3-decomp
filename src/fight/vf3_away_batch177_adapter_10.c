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
int vf3_away_batch177_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a91dau: goto P_0c0a91da;
case 0x0c0a91dcu: goto P_0c0a91dc;
case 0x0c0a91deu: goto P_0c0a91de;
case 0x0c0a91e0u: goto P_0c0a91e0;
case 0x0c0a91e2u: goto P_0c0a91e2;
case 0x0c0a91e4u: goto P_0c0a91e4;
case 0x0c0a91e6u: goto P_0c0a91e6;
case 0x0c0a91e8u: goto P_0c0a91e8;
case 0x0c0a91eau: goto P_0c0a91ea;
case 0x0c0a91ecu: goto P_0c0a91ec;
case 0x0c0a91eeu: goto P_0c0a91ee;
case 0x0c0a91f0u: goto P_0c0a91f0;
case 0x0c0a91f2u: goto P_0c0a91f2;
case 0x0c0a91f4u: goto P_0c0a91f4;
case 0x0c0a91f6u: goto P_0c0a91f6;
case 0x0c0a91f8u: goto P_0c0a91f8;
case 0x0c0a91fau: goto P_0c0a91fa;
case 0x0c0a91fcu: goto P_0c0a91fc;
case 0x0c0a91feu: goto P_0c0a91fe;
case 0x0c0a9200u: goto P_0c0a9200;
case 0x0c0a9202u: goto P_0c0a9202;
case 0x0c0a9204u: goto P_0c0a9204;
case 0x0c0a9206u: goto P_0c0a9206;
case 0x0c0a9208u: goto P_0c0a9208;
case 0x0c0a920au: goto P_0c0a920a;
case 0x0c0a920cu: goto P_0c0a920c;
case 0x0c0a920eu: goto P_0c0a920e;
case 0x0c0a9210u: goto P_0c0a9210;
case 0x0c0a9212u: goto P_0c0a9212;
case 0x0c0a9214u: goto P_0c0a9214;
case 0x0c0a9216u: goto P_0c0a9216;
case 0x0c0a9218u: goto P_0c0a9218;
case 0x0c0a921au: goto P_0c0a921a;
case 0x0c0a921cu: goto P_0c0a921c;
case 0x0c0a921eu: goto P_0c0a921e;
case 0x0c0a9220u: goto P_0c0a9220;
case 0x0c0a9222u: goto P_0c0a9222;
case 0x0c0a9224u: goto P_0c0a9224;
case 0x0c0a9226u: goto P_0c0a9226;
case 0x0c0a9228u: goto P_0c0a9228;
case 0x0c0a922au: goto P_0c0a922a;
case 0x0c0a922cu: goto P_0c0a922c;
case 0x0c0a922eu: goto P_0c0a922e;
case 0x0c0a9230u: goto P_0c0a9230;
case 0x0c0a9232u: goto P_0c0a9232;
case 0x0c0a9234u: goto P_0c0a9234;
case 0x0c0a9236u: goto P_0c0a9236;
case 0x0c0a9238u: goto P_0c0a9238;
case 0x0c0a923au: goto P_0c0a923a;
case 0x0c0a923cu: goto P_0c0a923c;
case 0x0c0a923eu: goto P_0c0a923e;
case 0x0c0a9240u: goto P_0c0a9240;
case 0x0c0a9242u: goto P_0c0a9242;
case 0x0c0a926au: goto P_0c0a926a;
case 0x0c0a926cu: goto P_0c0a926c;
case 0x0c0a926eu: goto P_0c0a926e;
case 0x0c0a9270u: goto P_0c0a9270;
case 0x0c0a9272u: goto P_0c0a9272;
case 0x0c0a9274u: goto P_0c0a9274;
case 0x0c0a9276u: goto P_0c0a9276;
case 0x0c0a9278u: goto P_0c0a9278;
case 0x0c0a927au: goto P_0c0a927a;
case 0x0c0a927cu: goto P_0c0a927c;
case 0x0c0a927eu: goto P_0c0a927e;
case 0x0c0a9280u: goto P_0c0a9280;
case 0x0c0a9282u: goto P_0c0a9282;
case 0x0c0a9284u: goto P_0c0a9284;
case 0x0c0a9286u: goto P_0c0a9286;
case 0x0c0a9288u: goto P_0c0a9288;
case 0x0c0a928au: goto P_0c0a928a;
case 0x0c0a928cu: goto P_0c0a928c;
case 0x0c0a928eu: goto P_0c0a928e;
case 0x0c0a9290u: goto P_0c0a9290;
case 0x0c0a9444u: goto P_0c0a9444;
case 0x0c0a9446u: goto P_0c0a9446;
case 0x0c0a9448u: goto P_0c0a9448;
case 0x0c0a944au: goto P_0c0a944a;
case 0x0c0a944cu: goto P_0c0a944c;
case 0x0c0a944eu: goto P_0c0a944e;
case 0x0c0a9450u: goto P_0c0a9450;
case 0x0c0a9452u: goto P_0c0a9452;
case 0x0c0a9454u: goto P_0c0a9454;
case 0x0c0a9456u: goto P_0c0a9456;
case 0x0c0a9458u: goto P_0c0a9458;
case 0x0c0a945au: goto P_0c0a945a;
case 0x0c0a945cu: goto P_0c0a945c;
case 0x0c0a945eu: goto P_0c0a945e;
case 0x0c0a9460u: goto P_0c0a9460;
case 0x0c0a9462u: goto P_0c0a9462;
case 0x0c0a9464u: goto P_0c0a9464;
case 0x0c0a9466u: goto P_0c0a9466;
case 0x0c0a9468u: goto P_0c0a9468;
case 0x0c0a946au: goto P_0c0a946a;
case 0x0c0a946cu: goto P_0c0a946c;
case 0x0c0a946eu: goto P_0c0a946e;
case 0x0c0a9470u: goto P_0c0a9470;
case 0x0c0a9472u: goto P_0c0a9472;
case 0x0c0a9474u: goto P_0c0a9474;
case 0x0c0a9476u: goto P_0c0a9476;
case 0x0c0a9478u: goto P_0c0a9478;
case 0x0c0a947au: goto P_0c0a947a;
case 0x0c0a947cu: goto P_0c0a947c;
case 0x0c0a947eu: goto P_0c0a947e;
case 0x0c0a9480u: goto P_0c0a9480;
case 0x0c0a9482u: goto P_0c0a9482;
case 0x0c0a9484u: goto P_0c0a9484;
case 0x0c0a9486u: goto P_0c0a9486;
case 0x0c0a9488u: goto P_0c0a9488;
case 0x0c0a948au: goto P_0c0a948a;
case 0x0c0a948cu: goto P_0c0a948c;
case 0x0c0a948eu: goto P_0c0a948e;
case 0x0c0a9490u: goto P_0c0a9490;
case 0x0c0a9492u: goto P_0c0a9492;
case 0x0c0a9494u: goto P_0c0a9494;
case 0x0c0a9496u: goto P_0c0a9496;
case 0x0c0a9498u: goto P_0c0a9498;
case 0x0c0a949au: goto P_0c0a949a;
case 0x0c0a949cu: goto P_0c0a949c;
case 0x0c0a949eu: goto P_0c0a949e;
case 0x0c0a94a0u: goto P_0c0a94a0;
case 0x0c0a94a2u: goto P_0c0a94a2;
case 0x0c0a94a4u: goto P_0c0a94a4;
case 0x0c0a94d0u: goto P_0c0a94d0;
case 0x0c0a94d2u: goto P_0c0a94d2;
case 0x0c0a94d4u: goto P_0c0a94d4;
case 0x0c0a94d6u: goto P_0c0a94d6;
case 0x0c0a94d8u: goto P_0c0a94d8;
case 0x0c0a94dau: goto P_0c0a94da;
case 0x0c0a94dcu: goto P_0c0a94dc;
case 0x0c0a94deu: goto P_0c0a94de;
case 0x0c0a94e0u: goto P_0c0a94e0;
case 0x0c0a94e2u: goto P_0c0a94e2;
case 0x0c0a94e4u: goto P_0c0a94e4;
case 0x0c0a94e6u: goto P_0c0a94e6;
case 0x0c0a94e8u: goto P_0c0a94e8;
case 0x0c0a94eau: goto P_0c0a94ea;
case 0x0c0a94ecu: goto P_0c0a94ec;
case 0x0c0a94eeu: goto P_0c0a94ee;
case 0x0c0a94f0u: goto P_0c0a94f0;
case 0x0c0a94f2u: goto P_0c0a94f2;
case 0x0c0a94f4u: goto P_0c0a94f4;
case 0x0c0a94f6u: goto P_0c0a94f6;
case 0x0c0a94f8u: goto P_0c0a94f8;
case 0x0c0a94fau: goto P_0c0a94fa;
case 0x0c0a94fcu: goto P_0c0a94fc;
case 0x0c0a94feu: goto P_0c0a94fe;
case 0x0c0a9500u: goto P_0c0a9500;
case 0x0c0a9502u: goto P_0c0a9502;
case 0x0c0a9504u: goto P_0c0a9504;
case 0x0c0a9506u: goto P_0c0a9506;
case 0x0c0a9508u: goto P_0c0a9508;
case 0x0c0a950au: goto P_0c0a950a;
case 0x0c0a950cu: goto P_0c0a950c;
case 0x0c0a950eu: goto P_0c0a950e;
case 0x0c0a9510u: goto P_0c0a9510;
case 0x0c0a9512u: goto P_0c0a9512;
case 0x0c0a9514u: goto P_0c0a9514;
case 0x0c0a9516u: goto P_0c0a9516;
case 0x0c0a9518u: goto P_0c0a9518;
case 0x0c0a951au: goto P_0c0a951a;
case 0x0c0a951cu: goto P_0c0a951c;
case 0x0c0a951eu: goto P_0c0a951e;
case 0x0c0a9520u: goto P_0c0a9520;
case 0x0c0a9522u: goto P_0c0a9522;
case 0x0c0a9524u: goto P_0c0a9524;
case 0x0c0a9526u: goto P_0c0a9526;
case 0x0c0a9528u: goto P_0c0a9528;
case 0x0c0a952au: goto P_0c0a952a;
case 0x0c0a952cu: goto P_0c0a952c;
case 0x0c0a952eu: goto P_0c0a952e;
case 0x0c0a9530u: goto P_0c0a9530;
case 0x0c0a9532u: goto P_0c0a9532;
case 0x0c0a9534u: goto P_0c0a9534;
case 0x0c0a9536u: goto P_0c0a9536;
case 0x0c0a9538u: goto P_0c0a9538;
case 0x0c0a953au: goto P_0c0a953a;
case 0x0c0a953cu: goto P_0c0a953c;
case 0x0c0a953eu: goto P_0c0a953e;
case 0x0c0a9540u: goto P_0c0a9540;
case 0x0c0a9542u: goto P_0c0a9542;
case 0x0c0a9544u: goto P_0c0a9544;
case 0x0c0a9546u: goto P_0c0a9546;
case 0x0c0a9548u: goto P_0c0a9548;
case 0x0c0a954au: goto P_0c0a954a;
case 0x0c0a954cu: goto P_0c0a954c;
case 0x0c0a954eu: goto P_0c0a954e;
case 0x0c0a9550u: goto P_0c0a9550;
case 0x0c0a9552u: goto P_0c0a9552;
case 0x0c0a9554u: goto P_0c0a9554;
case 0x0c0a9556u: goto P_0c0a9556;
case 0x0c0a9558u: goto P_0c0a9558;
case 0x0c0a955au: goto P_0c0a955a;
case 0x0c0a955cu: goto P_0c0a955c;
case 0x0c0a955eu: goto P_0c0a955e;
case 0x0c0a9560u: goto P_0c0a9560;
case 0x0c0a9562u: goto P_0c0a9562;
case 0x0c0a9564u: goto P_0c0a9564;
case 0x0c0a9566u: goto P_0c0a9566;
case 0x0c0a9568u: goto P_0c0a9568;
case 0x0c0a956au: goto P_0c0a956a;
case 0x0c0a956cu: goto P_0c0a956c;
case 0x0c0a956eu: goto P_0c0a956e;
case 0x0c0a9570u: goto P_0c0a9570;
case 0x0c0a9572u: goto P_0c0a9572;
case 0x0c0a9574u: goto P_0c0a9574;
case 0x0c0a9576u: goto P_0c0a9576;
case 0x0c0a9578u: goto P_0c0a9578;
case 0x0c0a957au: goto P_0c0a957a;
case 0x0c0a957cu: goto P_0c0a957c;
case 0x0c0a957eu: goto P_0c0a957e;
case 0x0c0a9580u: goto P_0c0a9580;
case 0x0c0a9582u: goto P_0c0a9582;
case 0x0c0a9584u: goto P_0c0a9584;
case 0x0c0a9586u: goto P_0c0a9586;
case 0x0c0a9588u: goto P_0c0a9588;
case 0x0c0a958au: goto P_0c0a958a;
case 0x0c0a958cu: goto P_0c0a958c;
case 0x0c0a958eu: goto P_0c0a958e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a91da: /* original 2fe6, guest PC 0x0c0a91da */
if(!s->budget--) { s->failed_pc=0x0c0a91dau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91dc;
P_0c0a91dc: /* original e054, guest PC 0x0c0a91dc */
if(!s->budget--) { s->failed_pc=0x0c0a91dcu; return 0; }
r[0]=0x00000054u;
goto P_0c0a91de;
P_0c0a91de: /* original 2fd6, guest PC 0x0c0a91de */
if(!s->budget--) { s->failed_pc=0x0c0a91deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e0;
P_0c0a91e0: /* original 2fc6, guest PC 0x0c0a91e0 */
if(!s->budget--) { s->failed_pc=0x0c0a91e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e2;
P_0c0a91e2: /* original 2fb6, guest PC 0x0c0a91e2 */
if(!s->budget--) { s->failed_pc=0x0c0a91e2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e4;
P_0c0a91e4: /* original de2e, guest PC 0x0c0a91e4 */
if(!s->budget--) { s->failed_pc=0x0c0a91e4u; return 0; }
r[14]=read(ram,0x0c0a92a0u,4);
goto P_0c0a91e6;
P_0c0a91e6: /* original 4f22, guest PC 0x0c0a91e6 */
if(!s->budget--) { s->failed_pc=0x0c0a91e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a91e8;
P_0c0a91e8: /* original 04ee, guest PC 0x0c0a91e8 */
if(!s->budget--) { s->failed_pc=0x0c0a91e8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a91ea;
P_0c0a91ea: /* original 5de4, guest PC 0x0c0a91ea */
if(!s->budget--) { s->failed_pc=0x0c0a91eau; return 0; }
r[13]=read(ram,r[14]+16,4);
goto P_0c0a91ec;
P_0c0a91ec: /* original 5445, guest PC 0x0c0a91ec */
if(!s->budget--) { s->failed_pc=0x0c0a91ecu; return 0; }
r[4]=read(ram,r[4]+20,4);
goto P_0c0a91ee;
P_0c0a91ee: /* original 74ff, guest PC 0x0c0a91ee */
if(!s->budget--) { s->failed_pc=0x0c0a91eeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a91f0;
P_0c0a91f0: /* original 4411, guest PC 0x0c0a91f0 */
if(!s->budget--) { s->failed_pc=0x0c0a91f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a91f2;
P_0c0a91f2: /* original 8d01, guest PC 0x0c0a91f2 */
if(!s->budget--) { s->failed_pc=0x0c0a91f2u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[14]+20,4);
if(cond) { goto P_0c0a91f8; }
goto P_0c0a91f6;
P_0c0a91f4: /* original 5be5, guest PC 0x0c0a91f4 */
if(!s->budget--) { s->failed_pc=0x0c0a91f4u; return 0; }
r[11]=read(ram,r[14]+20,4);
goto P_0c0a91f6;
P_0c0a91f6: /* original 944c, guest PC 0x0c0a91f6 */
if(!s->budget--) { s->failed_pc=0x0c0a91f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9292u,2);
goto P_0c0a91f8;
P_0c0a91f8: /* original 4408, guest PC 0x0c0a91f8 */
if(!s->budget--) { s->failed_pc=0x0c0a91f8u; return 0; }
r[4]<<=2;
goto P_0c0a91fa;
P_0c0a91fa: /* original dc2a, guest PC 0x0c0a91fa */
if(!s->budget--) { s->failed_pc=0x0c0a91fau; return 0; }
r[12]=read(ram,0x0c0a92a4u,4);
goto P_0c0a91fc;
P_0c0a91fc: /* original 4408, guest PC 0x0c0a91fc */
if(!s->budget--) { s->failed_pc=0x0c0a91fcu; return 0; }
r[4]<<=2;
goto P_0c0a91fe;
P_0c0a91fe: /* original 65d3, guest PC 0x0c0a91fe */
if(!s->budget--) { s->failed_pc=0x0c0a91feu; return 0; }
r[5]=r[13];
goto P_0c0a9200;
P_0c0a9200: /* original 4408, guest PC 0x0c0a9200 */
if(!s->budget--) { s->failed_pc=0x0c0a9200u; return 0; }
r[4]<<=2;
goto P_0c0a9202;
P_0c0a9202: /* original 66b3, guest PC 0x0c0a9202 */
if(!s->budget--) { s->failed_pc=0x0c0a9202u; return 0; }
r[6]=r[11];
goto P_0c0a9204;
P_0c0a9204: /* original 4400, guest PC 0x0c0a9204 */
if(!s->budget--) { s->failed_pc=0x0c0a9204u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a9206;
P_0c0a9206: /* original 3c4c, guest PC 0x0c0a9206 */
if(!s->budget--) { s->failed_pc=0x0c0a9206u; return 0; }
r[12]+=r[4];
goto P_0c0a9208;
P_0c0a9208: /* original b162, guest PC 0x0c0a9208 */
if(!s->budget--) { s->failed_pc=0x0c0a9208u; return 0; }
target=code_base|0x0c0a94d0u; r[16]=code_base|0x0c0a920cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a920cu) { target=s->pc; goto dispatch; }
goto P_0c0a920c;
P_0c0a920a: /* original 64c3, guest PC 0x0c0a920a */
if(!s->budget--) { s->failed_pc=0x0c0a920au; return 0; }
r[4]=r[12];
goto P_0c0a920c;
P_0c0a920c: /* original d326, guest PC 0x0c0a920c */
if(!s->budget--) { s->failed_pc=0x0c0a920cu; return 0; }
r[3]=read(ram,0x0c0a92a8u,4);
goto P_0c0a920e;
P_0c0a920e: /* original e028, guest PC 0x0c0a920e */
if(!s->budget--) { s->failed_pc=0x0c0a920eu; return 0; }
r[0]=0x00000028u;
goto P_0c0a9210;
P_0c0a9210: /* original 66d3, guest PC 0x0c0a9210 */
if(!s->budget--) { s->failed_pc=0x0c0a9210u; return 0; }
r[6]=r[13];
goto P_0c0a9212;
P_0c0a9212: /* original 65b3, guest PC 0x0c0a9212 */
if(!s->budget--) { s->failed_pc=0x0c0a9212u; return 0; }
r[5]=r[11];
goto P_0c0a9214;
P_0c0a9214: /* original f438, guest PC 0x0c0a9214 */
if(!s->budget--) { s->failed_pc=0x0c0a9214u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0a9216;
P_0c0a9216: /* original 7c40, guest PC 0x0c0a9216 */
if(!s->budget--) { s->failed_pc=0x0c0a9216u; return 0; }
r[12]+=0x00000040u;
goto P_0c0a9218;
P_0c0a9218: /* original fd47, guest PC 0x0c0a9218 */
if(!s->budget--) { s->failed_pc=0x0c0a9218u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a921a;
P_0c0a921a: /* original b159, guest PC 0x0c0a921a */
if(!s->budget--) { s->failed_pc=0x0c0a921au; return 0; }
target=code_base|0x0c0a94d0u; r[16]=code_base|0x0c0a921eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a921eu) { target=s->pc; goto dispatch; }
goto P_0c0a921e;
P_0c0a921c: /* original 64c3, guest PC 0x0c0a921c */
if(!s->budget--) { s->failed_pc=0x0c0a921cu; return 0; }
r[4]=r[12];
goto P_0c0a921e;
P_0c0a921e: /* original d323, guest PC 0x0c0a921e */
if(!s->budget--) { s->failed_pc=0x0c0a921eu; return 0; }
r[3]=read(ram,0x0c0a92acu,4);
goto P_0c0a9220;
P_0c0a9220: /* original e028, guest PC 0x0c0a9220 */
if(!s->budget--) { s->failed_pc=0x0c0a9220u; return 0; }
r[0]=0x00000028u;
goto P_0c0a9222;
P_0c0a9222: /* original f438, guest PC 0x0c0a9222 */
if(!s->budget--) { s->failed_pc=0x0c0a9222u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0a9224;
P_0c0a9224: /* original fd47, guest PC 0x0c0a9224 */
if(!s->budget--) { s->failed_pc=0x0c0a9224u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a9226;
P_0c0a9226: /* original 5de4, guest PC 0x0c0a9226 */
if(!s->budget--) { s->failed_pc=0x0c0a9226u; return 0; }
r[13]=read(ram,r[14]+16,4);
goto P_0c0a9228;
P_0c0a9228: /* original 5ee5, guest PC 0x0c0a9228 */
if(!s->budget--) { s->failed_pc=0x0c0a9228u; return 0; }
r[14]=read(ram,r[14]+20,4);
goto P_0c0a922a;
P_0c0a922a: /* original d221, guest PC 0x0c0a922a */
if(!s->budget--) { s->failed_pc=0x0c0a922au; return 0; }
r[2]=read(ram,0x0c0a92b0u,4);
goto P_0c0a922c;
P_0c0a922c: /* original 65e3, guest PC 0x0c0a922c */
if(!s->budget--) { s->failed_pc=0x0c0a922cu; return 0; }
r[5]=r[14];
goto P_0c0a922e;
P_0c0a922e: /* original 420b, guest PC 0x0c0a922e */
if(!s->budget--) { s->failed_pc=0x0c0a922eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9232u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9232u) { target=s->pc; goto dispatch; }
goto P_0c0a9232;
P_0c0a9230: /* original 64d3, guest PC 0x0c0a9230 */
if(!s->budget--) { s->failed_pc=0x0c0a9230u; return 0; }
r[4]=r[13];
goto P_0c0a9232;
P_0c0a9232: /* original 4f26, guest PC 0x0c0a9232 */
if(!s->budget--) { s->failed_pc=0x0c0a9232u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9234;
P_0c0a9234: /* original 65d3, guest PC 0x0c0a9234 */
if(!s->budget--) { s->failed_pc=0x0c0a9234u; return 0; }
r[5]=r[13];
goto P_0c0a9236;
P_0c0a9236: /* original d31e, guest PC 0x0c0a9236 */
if(!s->budget--) { s->failed_pc=0x0c0a9236u; return 0; }
r[3]=read(ram,0x0c0a92b0u,4);
goto P_0c0a9238;
P_0c0a9238: /* original 64e3, guest PC 0x0c0a9238 */
if(!s->budget--) { s->failed_pc=0x0c0a9238u; return 0; }
r[4]=r[14];
goto P_0c0a923a;
P_0c0a923a: /* original 6bf6, guest PC 0x0c0a923a */
if(!s->budget--) { s->failed_pc=0x0c0a923au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a923c;
P_0c0a923c: /* original 6cf6, guest PC 0x0c0a923c */
if(!s->budget--) { s->failed_pc=0x0c0a923cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a923e;
P_0c0a923e: /* original 6df6, guest PC 0x0c0a923e */
if(!s->budget--) { s->failed_pc=0x0c0a923eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9240;
P_0c0a9240: /* original 432b, guest PC 0x0c0a9240 */
if(!s->budget--) { s->failed_pc=0x0c0a9240u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0a9242: /* original 6ef6, guest PC 0x0c0a9242 */
if(!s->budget--) { s->failed_pc=0x0c0a9242u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a9244u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9244u; return 0; } return 1;
P_0c0a926a: /* original 9013, guest PC 0x0c0a926a */
if(!s->budget--) { s->failed_pc=0x0c0a926au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9294u,2);
goto P_0c0a926c;
P_0c0a926c: /* original e601, guest PC 0x0c0a926c */
if(!s->budget--) { s->failed_pc=0x0c0a926cu; return 0; }
r[6]=0x00000001u;
goto P_0c0a926e;
P_0c0a926e: /* original d715, guest PC 0x0c0a926e */
if(!s->budget--) { s->failed_pc=0x0c0a926eu; return 0; }
r[7]=read(ram,0x0c0a92c4u,4);
goto P_0c0a9270;
P_0c0a9270: /* original 0764, guest PC 0x0c0a9270 */
if(!s->budget--) { s->failed_pc=0x0c0a9270u; return 0; }
write(ram,r[7]+r[0],r[6],1);
goto P_0c0a9272;
P_0c0a9272: /* original 6542, guest PC 0x0c0a9272 */
if(!s->budget--) { s->failed_pc=0x0c0a9272u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0a9274;
P_0c0a9274: /* original d310, guest PC 0x0c0a9274 */
if(!s->budget--) { s->failed_pc=0x0c0a9274u; return 0; }
r[3]=read(ram,0x0c0a92b8u,4);
goto P_0c0a9276;
P_0c0a9276: /* original 2538, guest PC 0x0c0a9276 */
if(!s->budget--) { s->failed_pc=0x0c0a9276u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0a9278;
P_0c0a9278: /* original 8b07, guest PC 0x0c0a9278 */
if(!s->budget--) { s->failed_pc=0x0c0a9278u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928a; }
goto P_0c0a927a;
P_0c0a927a: /* original e048, guest PC 0x0c0a927a */
if(!s->budget--) { s->failed_pc=0x0c0a927au; return 0; }
r[0]=0x00000048u;
goto P_0c0a927c;
P_0c0a927c: /* original d30f, guest PC 0x0c0a927c */
if(!s->budget--) { s->failed_pc=0x0c0a927cu; return 0; }
r[3]=read(ram,0x0c0a92bcu,4);
goto P_0c0a927e;
P_0c0a927e: /* original 044e, guest PC 0x0c0a927e */
if(!s->budget--) { s->failed_pc=0x0c0a927eu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0a9280;
P_0c0a9280: /* original 2348, guest PC 0x0c0a9280 */
if(!s->budget--) { s->failed_pc=0x0c0a9280u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a9282;
P_0c0a9282: /* original 8b02, guest PC 0x0c0a9282 */
if(!s->budget--) { s->failed_pc=0x0c0a9282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928a; }
goto P_0c0a9284;
P_0c0a9284: /* original d50e, guest PC 0x0c0a9284 */
if(!s->budget--) { s->failed_pc=0x0c0a9284u; return 0; }
r[5]=read(ram,0x0c0a92c0u,4);
goto P_0c0a9286;
P_0c0a9286: /* original 2548, guest PC 0x0c0a9286 */
if(!s->budget--) { s->failed_pc=0x0c0a9286u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c0a9288;
P_0c0a9288: /* original 8b01, guest PC 0x0c0a9288 */
if(!s->budget--) { s->failed_pc=0x0c0a9288u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928e; }
goto P_0c0a928a;
P_0c0a928a: /* original 9003, guest PC 0x0c0a928a */
if(!s->budget--) { s->failed_pc=0x0c0a928au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9294u,2);
goto P_0c0a928c;
P_0c0a928c: /* original 0764, guest PC 0x0c0a928c */
if(!s->budget--) { s->failed_pc=0x0c0a928cu; return 0; }
write(ram,r[7]+r[0],r[6],1);
goto P_0c0a928e;
P_0c0a928e: /* original 000b, guest PC 0x0c0a928e */
if(!s->budget--) { s->failed_pc=0x0c0a928eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9290: /* original 0009, guest PC 0x0c0a9290 */
if(!s->budget--) { s->failed_pc=0x0c0a9290u; return 0; }
if(!vf3_matrix_family(0x0c0a9292u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9292u; return 0; } return 1;
P_0c0a9444: /* original 2fe6, guest PC 0x0c0a9444 */
if(!s->budget--) { s->failed_pc=0x0c0a9444u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9446;
P_0c0a9446: /* original 6e43, guest PC 0x0c0a9446 */
if(!s->budget--) { s->failed_pc=0x0c0a9446u; return 0; }
r[14]=r[4];
goto P_0c0a9448;
P_0c0a9448: /* original d41e, guest PC 0x0c0a9448 */
if(!s->budget--) { s->failed_pc=0x0c0a9448u; return 0; }
r[4]=read(ram,0x0c0a94c4u,4);
goto P_0c0a944a;
P_0c0a944a: /* original 902e, guest PC 0x0c0a944a */
if(!s->budget--) { s->failed_pc=0x0c0a944au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94aau,2);
goto P_0c0a944c;
P_0c0a944c: /* original 5645, guest PC 0x0c0a944c */
if(!s->budget--) { s->failed_pc=0x0c0a944cu; return 0; }
r[6]=read(ram,r[4]+20,4);
goto P_0c0a944e;
P_0c0a944e: /* original 5544, guest PC 0x0c0a944e */
if(!s->budget--) { s->failed_pc=0x0c0a944eu; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c0a9450;
P_0c0a9450: /* original e401, guest PC 0x0c0a9450 */
if(!s->budget--) { s->failed_pc=0x0c0a9450u; return 0; }
r[4]=0x00000001u;
goto P_0c0a9452;
P_0c0a9452: /* original 4f22, guest PC 0x0c0a9452 */
if(!s->budget--) { s->failed_pc=0x0c0a9452u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9454;
P_0c0a9454: /* original 0544, guest PC 0x0c0a9454 */
if(!s->budget--) { s->failed_pc=0x0c0a9454u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c0a9456;
P_0c0a9456: /* original 0644, guest PC 0x0c0a9456 */
if(!s->budget--) { s->failed_pc=0x0c0a9456u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0a9458;
P_0c0a9458: /* original d31b, guest PC 0x0c0a9458 */
if(!s->budget--) { s->failed_pc=0x0c0a9458u; return 0; }
r[3]=read(ram,0x0c0a94c8u,4);
goto P_0c0a945a;
P_0c0a945a: /* original 6530, guest PC 0x0c0a945a */
if(!s->budget--) { s->failed_pc=0x0c0a945au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c0a945c;
P_0c0a945c: /* original 605e, guest PC 0x0c0a945c */
if(!s->budget--) { s->failed_pc=0x0c0a945cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0a945e;
P_0c0a945e: /* original 8802, guest PC 0x0c0a945e */
if(!s->budget--) { s->failed_pc=0x0c0a945eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a9460;
P_0c0a9460: /* original 8b1e, guest PC 0x0c0a9460 */
if(!s->budget--) { s->failed_pc=0x0c0a9460u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a94a0; }
goto P_0c0a9462;
P_0c0a9462: /* original e061, guest PC 0x0c0a9462 */
if(!s->budget--) { s->failed_pc=0x0c0a9462u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9464;
P_0c0a9464: /* original 05ec, guest PC 0x0c0a9464 */
if(!s->budget--) { s->failed_pc=0x0c0a9464u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a9466;
P_0c0a9466: /* original d019, guest PC 0x0c0a9466 */
if(!s->budget--) { s->failed_pc=0x0c0a9466u; return 0; }
r[0]=read(ram,0x0c0a94ccu,4);
goto P_0c0a9468;
P_0c0a9468: /* original 4508, guest PC 0x0c0a9468 */
if(!s->budget--) { s->failed_pc=0x0c0a9468u; return 0; }
r[5]<<=2;
goto P_0c0a946a;
P_0c0a946a: /* original 4509, guest PC 0x0c0a946a */
if(!s->budget--) { s->failed_pc=0x0c0a946au; return 0; }
r[5]>>=2;
goto P_0c0a946c;
P_0c0a946c: /* original 4508, guest PC 0x0c0a946c */
if(!s->budget--) { s->failed_pc=0x0c0a946cu; return 0; }
r[5]<<=2;
goto P_0c0a946e;
P_0c0a946e: /* original 055e, guest PC 0x0c0a946e */
if(!s->budget--) { s->failed_pc=0x0c0a946eu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0a9470;
P_0c0a9470: /* original e03c, guest PC 0x0c0a9470 */
if(!s->budget--) { s->failed_pc=0x0c0a9470u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9472;
P_0c0a9472: /* original 0e55, guest PC 0x0c0a9472 */
if(!s->budget--) { s->failed_pc=0x0c0a9472u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0a9474;
P_0c0a9474: /* original e03e, guest PC 0x0c0a9474 */
if(!s->budget--) { s->failed_pc=0x0c0a9474u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9476;
P_0c0a9476: /* original 1e5d, guest PC 0x0c0a9476 */
if(!s->budget--) { s->failed_pc=0x0c0a9476u; return 0; }
write(ram,r[14]+52,r[5],4);
goto P_0c0a9478;
P_0c0a9478: /* original 0e45, guest PC 0x0c0a9478 */
if(!s->budget--) { s->failed_pc=0x0c0a9478u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a947a;
P_0c0a947a: /* original e010, guest PC 0x0c0a947a */
if(!s->budget--) { s->failed_pc=0x0c0a947au; return 0; }
r[0]=0x00000010u;
goto P_0c0a947c;
P_0c0a947c: /* original f4e6, guest PC 0x0c0a947c */
if(!s->budget--) { s->failed_pc=0x0c0a947cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a947e;
P_0c0a947e: /* original e018, guest PC 0x0c0a947e */
if(!s->budget--) { s->failed_pc=0x0c0a947eu; return 0; }
r[0]=0x00000018u;
goto P_0c0a9480;
P_0c0a9480: /* original d30f, guest PC 0x0c0a9480 */
if(!s->budget--) { s->failed_pc=0x0c0a9480u; return 0; }
r[3]=read(ram,0x0c0a94c0u,4);
goto P_0c0a9482;
P_0c0a9482: /* original f5e6, guest PC 0x0c0a9482 */
if(!s->budget--) { s->failed_pc=0x0c0a9482u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a9484;
P_0c0a9484: /* original 430b, guest PC 0x0c0a9484 */
if(!s->budget--) { s->failed_pc=0x0c0a9484u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9488u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9488u) { target=s->pc; goto dispatch; }
goto P_0c0a9488;
P_0c0a9486: /* original f54d, guest PC 0x0c0a9486 */
if(!s->budget--) { s->failed_pc=0x0c0a9486u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0a9488;
P_0c0a9488: /* original e024, guest PC 0x0c0a9488 */
if(!s->budget--) { s->failed_pc=0x0c0a9488u; return 0; }
r[0]=0x00000024u;
goto P_0c0a948a;
P_0c0a948a: /* original f48d, guest PC 0x0c0a948a */
if(!s->budget--) { s->failed_pc=0x0c0a948au; return 0; }
fr[4]=0;
goto P_0c0a948c;
P_0c0a948c: /* original f50c, guest PC 0x0c0a948c */
if(!s->budget--) { s->failed_pc=0x0c0a948cu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0a948e;
P_0c0a948e: /* original fe47, guest PC 0x0c0a948e */
if(!s->budget--) { s->failed_pc=0x0c0a948eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9490;
P_0c0a9490: /* original e028, guest PC 0x0c0a9490 */
if(!s->budget--) { s->failed_pc=0x0c0a9490u; return 0; }
r[0]=0x00000028u;
goto P_0c0a9492;
P_0c0a9492: /* original fe47, guest PC 0x0c0a9492 */
if(!s->budget--) { s->failed_pc=0x0c0a9492u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9494;
P_0c0a9494: /* original e02c, guest PC 0x0c0a9494 */
if(!s->budget--) { s->failed_pc=0x0c0a9494u; return 0; }
r[0]=0x0000002cu;
goto P_0c0a9496;
P_0c0a9496: /* original fe47, guest PC 0x0c0a9496 */
if(!s->budget--) { s->failed_pc=0x0c0a9496u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9498;
P_0c0a9498: /* original e014, guest PC 0x0c0a9498 */
if(!s->budget--) { s->failed_pc=0x0c0a9498u; return 0; }
r[0]=0x00000014u;
goto P_0c0a949a;
P_0c0a949a: /* original fe57, guest PC 0x0c0a949a */
if(!s->budget--) { s->failed_pc=0x0c0a949au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a949c;
P_0c0a949c: /* original 9006, guest PC 0x0c0a949c */
if(!s->budget--) { s->failed_pc=0x0c0a949cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94acu,2);
goto P_0c0a949e;
P_0c0a949e: /* original fe57, guest PC 0x0c0a949e */
if(!s->budget--) { s->failed_pc=0x0c0a949eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a94a0;
P_0c0a94a0: /* original 4f26, guest PC 0x0c0a94a0 */
if(!s->budget--) { s->failed_pc=0x0c0a94a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a94a2;
P_0c0a94a2: /* original 000b, guest PC 0x0c0a94a2 */
if(!s->budget--) { s->failed_pc=0x0c0a94a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a94a4: /* original 6ef6, guest PC 0x0c0a94a4 */
if(!s->budget--) { s->failed_pc=0x0c0a94a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a94a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a94a6u; return 0; } return 1;
P_0c0a94d0: /* original e004, guest PC 0x0c0a94d0 */
if(!s->budget--) { s->failed_pc=0x0c0a94d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0a94d2;
P_0c0a94d2: /* original 2fe6, guest PC 0x0c0a94d2 */
if(!s->budget--) { s->failed_pc=0x0c0a94d2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a94d4;
P_0c0a94d4: /* original 4f22, guest PC 0x0c0a94d4 */
if(!s->budget--) { s->failed_pc=0x0c0a94d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a94d6;
P_0c0a94d6: /* original 6e53, guest PC 0x0c0a94d6 */
if(!s->budget--) { s->failed_pc=0x0c0a94d6u; return 0; }
r[14]=r[5];
goto P_0c0a94d8;
P_0c0a94d8: /* original 7fec, guest PC 0x0c0a94d8 */
if(!s->budget--) { s->failed_pc=0x0c0a94d8u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0a94da;
P_0c0a94da: /* original 1f61, guest PC 0x0c0a94da */
if(!s->budget--) { s->failed_pc=0x0c0a94dau; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a94dc;
P_0c0a94dc: /* original f446, guest PC 0x0c0a94dc */
if(!s->budget--) { s->failed_pc=0x0c0a94dcu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0a94de;
P_0c0a94de: /* original e008, guest PC 0x0c0a94de */
if(!s->budget--) { s->failed_pc=0x0c0a94deu; return 0; }
r[0]=0x00000008u;
goto P_0c0a94e0;
P_0c0a94e0: /* original f546, guest PC 0x0c0a94e0 */
if(!s->budget--) { s->failed_pc=0x0c0a94e0u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0a94e2;
P_0c0a94e2: /* original e00c, guest PC 0x0c0a94e2 */
if(!s->budget--) { s->failed_pc=0x0c0a94e2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a94e4;
P_0c0a94e4: /* original f646, guest PC 0x0c0a94e4 */
if(!s->budget--) { s->failed_pc=0x0c0a94e4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0a94e6;
P_0c0a94e6: /* original e020, guest PC 0x0c0a94e6 */
if(!s->budget--) { s->failed_pc=0x0c0a94e6u; return 0; }
r[0]=0x00000020u;
goto P_0c0a94e8;
P_0c0a94e8: /* original 064d, guest PC 0x0c0a94e8 */
if(!s->budget--) { s->failed_pc=0x0c0a94e8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a94ea;
P_0c0a94ea: /* original e024, guest PC 0x0c0a94ea */
if(!s->budget--) { s->failed_pc=0x0c0a94eau; return 0; }
r[0]=0x00000024u;
goto P_0c0a94ec;
P_0c0a94ec: /* original 074d, guest PC 0x0c0a94ec */
if(!s->budget--) { s->failed_pc=0x0c0a94ecu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a94ee;
P_0c0a94ee: /* original e038, guest PC 0x0c0a94ee */
if(!s->budget--) { s->failed_pc=0x0c0a94eeu; return 0; }
r[0]=0x00000038u;
goto P_0c0a94f0;
P_0c0a94f0: /* original 5344, guest PC 0x0c0a94f0 */
if(!s->budget--) { s->failed_pc=0x0c0a94f0u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c0a94f2;
P_0c0a94f2: /* original 6542, guest PC 0x0c0a94f2 */
if(!s->budget--) { s->failed_pc=0x0c0a94f2u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0a94f4;
P_0c0a94f4: /* original 2f32, guest PC 0x0c0a94f4 */
if(!s->budget--) { s->failed_pc=0x0c0a94f4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a94f6;
P_0c0a94f6: /* original 524b, guest PC 0x0c0a94f6 */
if(!s->budget--) { s->failed_pc=0x0c0a94f6u; return 0; }
r[2]=read(ram,r[4]+44,4);
goto P_0c0a94f8;
P_0c0a94f8: /* original 1f24, guest PC 0x0c0a94f8 */
if(!s->budget--) { s->failed_pc=0x0c0a94f8u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0a94fa;
P_0c0a94fa: /* original 534c, guest PC 0x0c0a94fa */
if(!s->budget--) { s->failed_pc=0x0c0a94fau; return 0; }
r[3]=read(ram,r[4]+48,4);
goto P_0c0a94fc;
P_0c0a94fc: /* original 1f33, guest PC 0x0c0a94fc */
if(!s->budget--) { s->failed_pc=0x0c0a94fcu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a94fe;
P_0c0a94fe: /* original 004c, guest PC 0x0c0a94fe */
if(!s->budget--) { s->failed_pc=0x0c0a94feu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a9500;
P_0c0a9500: /* original 80f8, guest PC 0x0c0a9500 */
if(!s->budget--) { s->failed_pc=0x0c0a9500u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0a9502;
P_0c0a9502: /* original e010, guest PC 0x0c0a9502 */
if(!s->budget--) { s->failed_pc=0x0c0a9502u; return 0; }
r[0]=0x00000010u;
goto P_0c0a9504;
P_0c0a9504: /* original 2e52, guest PC 0x0c0a9504 */
if(!s->budget--) { s->failed_pc=0x0c0a9504u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0a9506;
P_0c0a9506: /* original fe47, guest PC 0x0c0a9506 */
if(!s->budget--) { s->failed_pc=0x0c0a9506u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9508;
P_0c0a9508: /* original e014, guest PC 0x0c0a9508 */
if(!s->budget--) { s->failed_pc=0x0c0a9508u; return 0; }
r[0]=0x00000014u;
goto P_0c0a950a;
P_0c0a950a: /* original fe57, guest PC 0x0c0a950a */
if(!s->budget--) { s->failed_pc=0x0c0a950au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a950c;
P_0c0a950c: /* original e018, guest PC 0x0c0a950c */
if(!s->budget--) { s->failed_pc=0x0c0a950cu; return 0; }
r[0]=0x00000018u;
goto P_0c0a950e;
P_0c0a950e: /* original fe67, guest PC 0x0c0a950e */
if(!s->budget--) { s->failed_pc=0x0c0a950eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a9510;
P_0c0a9510: /* original 6063, guest PC 0x0c0a9510 */
if(!s->budget--) { s->failed_pc=0x0c0a9510u; return 0; }
r[0]=r[6];
goto P_0c0a9512;
P_0c0a9512: /* original 81ef, guest PC 0x0c0a9512 */
if(!s->budget--) { s->failed_pc=0x0c0a9512u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a9514;
P_0c0a9514: /* original e03e, guest PC 0x0c0a9514 */
if(!s->budget--) { s->failed_pc=0x0c0a9514u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9516;
P_0c0a9516: /* original 0e75, guest PC 0x0c0a9516 */
if(!s->budget--) { s->failed_pc=0x0c0a9516u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0a9518;
P_0c0a9518: /* original e048, guest PC 0x0c0a9518 */
if(!s->budget--) { s->failed_pc=0x0c0a9518u; return 0; }
r[0]=0x00000048u;
goto P_0c0a951a;
P_0c0a951a: /* original 63f2, guest PC 0x0c0a951a */
if(!s->budget--) { s->failed_pc=0x0c0a951au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a951c;
P_0c0a951c: /* original 0e36, guest PC 0x0c0a951c */
if(!s->budget--) { s->failed_pc=0x0c0a951cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0a951e;
P_0c0a951e: /* original 9037, guest PC 0x0c0a951e */
if(!s->budget--) { s->failed_pc=0x0c0a951eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9590u,2);
goto P_0c0a9520;
P_0c0a9520: /* original 52f4, guest PC 0x0c0a9520 */
if(!s->budget--) { s->failed_pc=0x0c0a9520u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0a9522;
P_0c0a9522: /* original 0e26, guest PC 0x0c0a9522 */
if(!s->budget--) { s->failed_pc=0x0c0a9522u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0a9524;
P_0c0a9524: /* original 9035, guest PC 0x0c0a9524 */
if(!s->budget--) { s->failed_pc=0x0c0a9524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9592u,2);
goto P_0c0a9526;
P_0c0a9526: /* original 53f3, guest PC 0x0c0a9526 */
if(!s->budget--) { s->failed_pc=0x0c0a9526u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a9528;
P_0c0a9528: /* original 0e36, guest PC 0x0c0a9528 */
if(!s->budget--) { s->failed_pc=0x0c0a9528u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0a952a;
P_0c0a952a: /* original 9133, guest PC 0x0c0a952a */
if(!s->budget--) { s->failed_pc=0x0c0a952au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9594u,2);
goto P_0c0a952c;
P_0c0a952c: /* original 84f8, guest PC 0x0c0a952c */
if(!s->budget--) { s->failed_pc=0x0c0a952cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c0a952e;
P_0c0a952e: /* original 31ec, guest PC 0x0c0a952e */
if(!s->budget--) { s->failed_pc=0x0c0a952eu; return 0; }
r[1]+=r[14];
goto P_0c0a9530;
P_0c0a9530: /* original 2100, guest PC 0x0c0a9530 */
if(!s->budget--) { s->failed_pc=0x0c0a9530u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a9532;
P_0c0a9532: /* original e03c, guest PC 0x0c0a9532 */
if(!s->budget--) { s->failed_pc=0x0c0a9532u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9534;
P_0c0a9534: /* original 06ed, guest PC 0x0c0a9534 */
if(!s->budget--) { s->failed_pc=0x0c0a9534u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9536;
P_0c0a9536: /* original e022, guest PC 0x0c0a9536 */
if(!s->budget--) { s->failed_pc=0x0c0a9536u; return 0; }
r[0]=0x00000022u;
goto P_0c0a9538;
P_0c0a9538: /* original 044d, guest PC 0x0c0a9538 */
if(!s->budget--) { s->failed_pc=0x0c0a9538u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a953a;
P_0c0a953a: /* original e03c, guest PC 0x0c0a953a */
if(!s->budget--) { s->failed_pc=0x0c0a953au; return 0; }
r[0]=0x0000003cu;
goto P_0c0a953c;
P_0c0a953c: /* original 654f, guest PC 0x0c0a953c */
if(!s->budget--) { s->failed_pc=0x0c0a953cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a953e;
P_0c0a953e: /* original 2558, guest PC 0x0c0a953e */
if(!s->budget--) { s->failed_pc=0x0c0a953eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a9540;
P_0c0a9540: /* original 8d22, guest PC 0x0c0a9540 */
if(!s->budget--) { s->failed_pc=0x0c0a9540u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0a9588; }
goto P_0c0a9544;
P_0c0a9542: /* original 0e45, guest PC 0x0c0a9542 */
if(!s->budget--) { s->failed_pc=0x0c0a9542u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9544;
P_0c0a9544: /* original 666f, guest PC 0x0c0a9544 */
if(!s->budget--) { s->failed_pc=0x0c0a9544u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0a9546;
P_0c0a9546: /* original 3650, guest PC 0x0c0a9546 */
if(!s->budget--) { s->failed_pc=0x0c0a9546u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[5])!=0);
goto P_0c0a9548;
P_0c0a9548: /* original 8b06, guest PC 0x0c0a9548 */
if(!s->budget--) { s->failed_pc=0x0c0a9548u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9558; }
goto P_0c0a954a;
P_0c0a954a: /* original e03e, guest PC 0x0c0a954a */
if(!s->budget--) { s->failed_pc=0x0c0a954au; return 0; }
r[0]=0x0000003eu;
goto P_0c0a954c;
P_0c0a954c: /* original 04ed, guest PC 0x0c0a954c */
if(!s->budget--) { s->failed_pc=0x0c0a954cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a954e;
P_0c0a954e: /* original 604f, guest PC 0x0c0a954e */
if(!s->budget--) { s->failed_pc=0x0c0a954eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a9550;
P_0c0a9550: /* original 8801, guest PC 0x0c0a9550 */
if(!s->budget--) { s->failed_pc=0x0c0a9550u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9552;
P_0c0a9552: /* original 890b, guest PC 0x0c0a9552 */
if(!s->budget--) { s->failed_pc=0x0c0a9552u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a956c; }
goto P_0c0a9554;
P_0c0a9554: /* original a00f, guest PC 0x0c0a9554 */
if(!s->budget--) { s->failed_pc=0x0c0a9554u; return 0; }
goto P_0c0a9576;
P_0c0a9556: /* original 0009, guest PC 0x0c0a9556 */
if(!s->budget--) { s->failed_pc=0x0c0a9556u; return 0; }
goto P_0c0a9558;
P_0c0a9558: /* original 02ed, guest PC 0x0c0a9558 */
if(!s->budget--) { s->failed_pc=0x0c0a9558u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a955a;
P_0c0a955a: /* original 2f21, guest PC 0x0c0a955a */
if(!s->budget--) { s->failed_pc=0x0c0a955au; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0a955c;
P_0c0a955c: /* original 55f1, guest PC 0x0c0a955c */
if(!s->budget--) { s->failed_pc=0x0c0a955cu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0a955e;
P_0c0a955e: /* original d30e, guest PC 0x0c0a955e */
if(!s->budget--) { s->failed_pc=0x0c0a955eu; return 0; }
r[3]=read(ram,0x0c0a9598u,4);
goto P_0c0a9560;
P_0c0a9560: /* original 66f1, guest PC 0x0c0a9560 */
if(!s->budget--) { s->failed_pc=0x0c0a9560u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a9562;
P_0c0a9562: /* original 430b, guest PC 0x0c0a9562 */
if(!s->budget--) { s->failed_pc=0x0c0a9562u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9566u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9566u) { target=s->pc; goto dispatch; }
goto P_0c0a9566;
P_0c0a9564: /* original 64e3, guest PC 0x0c0a9564 */
if(!s->budget--) { s->failed_pc=0x0c0a9564u; return 0; }
r[4]=r[14];
goto P_0c0a9566;
P_0c0a9566: /* original d20d, guest PC 0x0c0a9566 */
if(!s->budget--) { s->failed_pc=0x0c0a9566u; return 0; }
r[2]=read(ram,0x0c0a959cu,4);
goto P_0c0a9568;
P_0c0a9568: /* original 420b, guest PC 0x0c0a9568 */
if(!s->budget--) { s->failed_pc=0x0c0a9568u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a956cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a956cu) { target=s->pc; goto dispatch; }
goto P_0c0a956c;
P_0c0a956a: /* original 64e3, guest PC 0x0c0a956a */
if(!s->budget--) { s->failed_pc=0x0c0a956au; return 0; }
r[4]=r[14];
goto P_0c0a956c;
P_0c0a956c: /* original d30c, guest PC 0x0c0a956c */
if(!s->budget--) { s->failed_pc=0x0c0a956cu; return 0; }
r[3]=read(ram,0x0c0a95a0u,4);
goto P_0c0a956e;
P_0c0a956e: /* original 430b, guest PC 0x0c0a956e */
if(!s->budget--) { s->failed_pc=0x0c0a956eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9572u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9572u) { target=s->pc; goto dispatch; }
goto P_0c0a9572;
P_0c0a9570: /* original 64e3, guest PC 0x0c0a9570 */
if(!s->budget--) { s->failed_pc=0x0c0a9570u; return 0; }
r[4]=r[14];
goto P_0c0a9572;
P_0c0a9572: /* original a003, guest PC 0x0c0a9572 */
if(!s->budget--) { s->failed_pc=0x0c0a9572u; return 0; }
goto P_0c0a957c;
P_0c0a9574: /* original 0009, guest PC 0x0c0a9574 */
if(!s->budget--) { s->failed_pc=0x0c0a9574u; return 0; }
goto P_0c0a9576;
P_0c0a9576: /* original d30b, guest PC 0x0c0a9576 */
if(!s->budget--) { s->failed_pc=0x0c0a9576u; return 0; }
r[3]=read(ram,0x0c0a95a4u,4);
goto P_0c0a9578;
P_0c0a9578: /* original 430b, guest PC 0x0c0a9578 */
if(!s->budget--) { s->failed_pc=0x0c0a9578u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a957cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a957cu) { target=s->pc; goto dispatch; }
goto P_0c0a957c;
P_0c0a957a: /* original 64e3, guest PC 0x0c0a957a */
if(!s->budget--) { s->failed_pc=0x0c0a957au; return 0; }
r[4]=r[14];
goto P_0c0a957c;
P_0c0a957c: /* original 7f14, guest PC 0x0c0a957c */
if(!s->budget--) { s->failed_pc=0x0c0a957cu; return 0; }
r[15]+=0x00000014u;
goto P_0c0a957e;
P_0c0a957e: /* original d20a, guest PC 0x0c0a957e */
if(!s->budget--) { s->failed_pc=0x0c0a957eu; return 0; }
r[2]=read(ram,0x0c0a95a8u,4);
goto P_0c0a9580;
P_0c0a9580: /* original 4f26, guest PC 0x0c0a9580 */
if(!s->budget--) { s->failed_pc=0x0c0a9580u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9582;
P_0c0a9582: /* original 64e3, guest PC 0x0c0a9582 */
if(!s->budget--) { s->failed_pc=0x0c0a9582u; return 0; }
r[4]=r[14];
goto P_0c0a9584;
P_0c0a9584: /* original 422b, guest PC 0x0c0a9584 */
if(!s->budget--) { s->failed_pc=0x0c0a9584u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0a9586: /* original 6ef6, guest PC 0x0c0a9586 */
if(!s->budget--) { s->failed_pc=0x0c0a9586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9588;
P_0c0a9588: /* original 7f14, guest PC 0x0c0a9588 */
if(!s->budget--) { s->failed_pc=0x0c0a9588u; return 0; }
r[15]+=0x00000014u;
goto P_0c0a958a;
P_0c0a958a: /* original 4f26, guest PC 0x0c0a958a */
if(!s->budget--) { s->failed_pc=0x0c0a958au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a958c;
P_0c0a958c: /* original 000b, guest PC 0x0c0a958c */
if(!s->budget--) { s->failed_pc=0x0c0a958cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a958e: /* original 6ef6, guest PC 0x0c0a958e */
if(!s->budget--) { s->failed_pc=0x0c0a958eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a9590u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9590u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
