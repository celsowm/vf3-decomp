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
int vf3_away_batch10_adapter_31(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07aaacu: goto P_0c07aaac;
case 0x0c07aaaeu: goto P_0c07aaae;
case 0x0c07aab0u: goto P_0c07aab0;
case 0x0c07aab2u: goto P_0c07aab2;
case 0x0c07aab4u: goto P_0c07aab4;
case 0x0c07aab6u: goto P_0c07aab6;
case 0x0c07aab8u: goto P_0c07aab8;
case 0x0c07aabau: goto P_0c07aaba;
case 0x0c07aabcu: goto P_0c07aabc;
case 0x0c07aabeu: goto P_0c07aabe;
case 0x0c07aac0u: goto P_0c07aac0;
case 0x0c07aac2u: goto P_0c07aac2;
case 0x0c07aac4u: goto P_0c07aac4;
case 0x0c07aac6u: goto P_0c07aac6;
case 0x0c07aac8u: goto P_0c07aac8;
case 0x0c07aacau: goto P_0c07aaca;
case 0x0c07aaccu: goto P_0c07aacc;
case 0x0c07aaceu: goto P_0c07aace;
case 0x0c07aad0u: goto P_0c07aad0;
case 0x0c07aad2u: goto P_0c07aad2;
case 0x0c07aad4u: goto P_0c07aad4;
case 0x0c07aad6u: goto P_0c07aad6;
case 0x0c07aad8u: goto P_0c07aad8;
case 0x0c07aadau: goto P_0c07aada;
case 0x0c07aadcu: goto P_0c07aadc;
case 0x0c07aadeu: goto P_0c07aade;
case 0x0c07aae0u: goto P_0c07aae0;
case 0x0c07aae2u: goto P_0c07aae2;
case 0x0c07aae4u: goto P_0c07aae4;
case 0x0c07aae6u: goto P_0c07aae6;
case 0x0c07aae8u: goto P_0c07aae8;
case 0x0c07aaeau: goto P_0c07aaea;
case 0x0c07aaecu: goto P_0c07aaec;
case 0x0c07aaeeu: goto P_0c07aaee;
case 0x0c07aaf0u: goto P_0c07aaf0;
case 0x0c07b204u: goto P_0c07b204;
case 0x0c07b206u: goto P_0c07b206;
case 0x0c07b208u: goto P_0c07b208;
case 0x0c07b20au: goto P_0c07b20a;
case 0x0c07b20cu: goto P_0c07b20c;
case 0x0c07b20eu: goto P_0c07b20e;
case 0x0c07b210u: goto P_0c07b210;
case 0x0c07b212u: goto P_0c07b212;
case 0x0c07b214u: goto P_0c07b214;
case 0x0c07b216u: goto P_0c07b216;
case 0x0c07b218u: goto P_0c07b218;
case 0x0c07b21au: goto P_0c07b21a;
case 0x0c07b21cu: goto P_0c07b21c;
case 0x0c07b21eu: goto P_0c07b21e;
case 0x0c07b220u: goto P_0c07b220;
case 0x0c07b222u: goto P_0c07b222;
case 0x0c07b224u: goto P_0c07b224;
case 0x0c07b226u: goto P_0c07b226;
case 0x0c07b228u: goto P_0c07b228;
case 0x0c07b22au: goto P_0c07b22a;
case 0x0c07b22cu: goto P_0c07b22c;
case 0x0c07b22eu: goto P_0c07b22e;
case 0x0c07b230u: goto P_0c07b230;
case 0x0c07b232u: goto P_0c07b232;
case 0x0c07b234u: goto P_0c07b234;
case 0x0c07b236u: goto P_0c07b236;
case 0x0c07b238u: goto P_0c07b238;
case 0x0c07b23au: goto P_0c07b23a;
case 0x0c07b23cu: goto P_0c07b23c;
case 0x0c07b23eu: goto P_0c07b23e;
case 0x0c07b240u: goto P_0c07b240;
case 0x0c07b242u: goto P_0c07b242;
case 0x0c07b244u: goto P_0c07b244;
case 0x0c07b246u: goto P_0c07b246;
case 0x0c07b248u: goto P_0c07b248;
case 0x0c07b24au: goto P_0c07b24a;
case 0x0c07b24cu: goto P_0c07b24c;
case 0x0c07b24eu: goto P_0c07b24e;
case 0x0c07b250u: goto P_0c07b250;
case 0x0c07b252u: goto P_0c07b252;
case 0x0c07b254u: goto P_0c07b254;
case 0x0c07b256u: goto P_0c07b256;
case 0x0c07b258u: goto P_0c07b258;
case 0x0c07b25au: goto P_0c07b25a;
case 0x0c07b25cu: goto P_0c07b25c;
case 0x0c07b25eu: goto P_0c07b25e;
case 0x0c07b260u: goto P_0c07b260;
case 0x0c07b262u: goto P_0c07b262;
case 0x0c07b264u: goto P_0c07b264;
case 0x0c07b266u: goto P_0c07b266;
case 0x0c07b268u: goto P_0c07b268;
case 0x0c07b26au: goto P_0c07b26a;
case 0x0c07b26cu: goto P_0c07b26c;
case 0x0c07b26eu: goto P_0c07b26e;
case 0x0c07b270u: goto P_0c07b270;
case 0x0c07b272u: goto P_0c07b272;
case 0x0c07b274u: goto P_0c07b274;
case 0x0c07b276u: goto P_0c07b276;
case 0x0c07b278u: goto P_0c07b278;
case 0x0c07b27au: goto P_0c07b27a;
case 0x0c07b27cu: goto P_0c07b27c;
case 0x0c07b27eu: goto P_0c07b27e;
case 0x0c07b280u: goto P_0c07b280;
case 0x0c07b282u: goto P_0c07b282;
case 0x0c07b284u: goto P_0c07b284;
case 0x0c07b286u: goto P_0c07b286;
case 0x0c07b288u: goto P_0c07b288;
case 0x0c07b28au: goto P_0c07b28a;
case 0x0c07b28cu: goto P_0c07b28c;
case 0x0c07b28eu: goto P_0c07b28e;
case 0x0c07b290u: goto P_0c07b290;
case 0x0c07b292u: goto P_0c07b292;
case 0x0c07b294u: goto P_0c07b294;
case 0x0c07b296u: goto P_0c07b296;
case 0x0c07b298u: goto P_0c07b298;
case 0x0c07b29au: goto P_0c07b29a;
case 0x0c07b29cu: goto P_0c07b29c;
case 0x0c07b29eu: goto P_0c07b29e;
case 0x0c07b2a0u: goto P_0c07b2a0;
case 0x0c07b2a2u: goto P_0c07b2a2;
case 0x0c07b2a4u: goto P_0c07b2a4;
case 0x0c07b2a6u: goto P_0c07b2a6;
case 0x0c07b2a8u: goto P_0c07b2a8;
case 0x0c07b2aau: goto P_0c07b2aa;
case 0x0c07b2acu: goto P_0c07b2ac;
case 0x0c07b2aeu: goto P_0c07b2ae;
case 0x0c07b2b0u: goto P_0c07b2b0;
case 0x0c07b2b2u: goto P_0c07b2b2;
case 0x0c07b2b4u: goto P_0c07b2b4;
case 0x0c07b2b6u: goto P_0c07b2b6;
case 0x0c07b2b8u: goto P_0c07b2b8;
case 0x0c07b2bau: goto P_0c07b2ba;
case 0x0c07b2bcu: goto P_0c07b2bc;
case 0x0c07b398u: goto P_0c07b398;
case 0x0c07b39au: goto P_0c07b39a;
case 0x0c07b39cu: goto P_0c07b39c;
case 0x0c07b39eu: goto P_0c07b39e;
case 0x0c07b3a0u: goto P_0c07b3a0;
case 0x0c07b3a2u: goto P_0c07b3a2;
case 0x0c07b3a4u: goto P_0c07b3a4;
case 0x0c07b3a6u: goto P_0c07b3a6;
case 0x0c07b3a8u: goto P_0c07b3a8;
case 0x0c07b3aau: goto P_0c07b3aa;
case 0x0c07b3acu: goto P_0c07b3ac;
case 0x0c07b3aeu: goto P_0c07b3ae;
case 0x0c07b3b0u: goto P_0c07b3b0;
case 0x0c07b3b2u: goto P_0c07b3b2;
case 0x0c07b3b4u: goto P_0c07b3b4;
case 0x0c07b3b6u: goto P_0c07b3b6;
case 0x0c07b3b8u: goto P_0c07b3b8;
case 0x0c07b3bau: goto P_0c07b3ba;
case 0x0c07b3bcu: goto P_0c07b3bc;
case 0x0c07b3beu: goto P_0c07b3be;
case 0x0c07b3c0u: goto P_0c07b3c0;
case 0x0c07b3c2u: goto P_0c07b3c2;
case 0x0c07b3c4u: goto P_0c07b3c4;
case 0x0c07b3c6u: goto P_0c07b3c6;
case 0x0c07b3c8u: goto P_0c07b3c8;
case 0x0c07b3cau: goto P_0c07b3ca;
case 0x0c07b3ccu: goto P_0c07b3cc;
case 0x0c07b3ceu: goto P_0c07b3ce;
case 0x0c07b3d0u: goto P_0c07b3d0;
case 0x0c07b4d4u: goto P_0c07b4d4;
case 0x0c07b4d6u: goto P_0c07b4d6;
case 0x0c07b4d8u: goto P_0c07b4d8;
case 0x0c07b4dau: goto P_0c07b4da;
case 0x0c07b4dcu: goto P_0c07b4dc;
case 0x0c07b4deu: goto P_0c07b4de;
case 0x0c07b4e0u: goto P_0c07b4e0;
case 0x0c07b4e2u: goto P_0c07b4e2;
case 0x0c07b4e4u: goto P_0c07b4e4;
case 0x0c07b4e6u: goto P_0c07b4e6;
case 0x0c07b4e8u: goto P_0c07b4e8;
case 0x0c07b4eau: goto P_0c07b4ea;
case 0x0c07b4ecu: goto P_0c07b4ec;
case 0x0c07b4eeu: goto P_0c07b4ee;
case 0x0c07b4f0u: goto P_0c07b4f0;
case 0x0c07b4f2u: goto P_0c07b4f2;
case 0x0c07b4f4u: goto P_0c07b4f4;
case 0x0c07b4f6u: goto P_0c07b4f6;
case 0x0c07b4f8u: goto P_0c07b4f8;
case 0x0c07b4fau: goto P_0c07b4fa;
case 0x0c07b4fcu: goto P_0c07b4fc;
case 0x0c07b4feu: goto P_0c07b4fe;
case 0x0c07b500u: goto P_0c07b500;
case 0x0c07b502u: goto P_0c07b502;
case 0x0c07b504u: goto P_0c07b504;
case 0x0c07b506u: goto P_0c07b506;
case 0x0c07b508u: goto P_0c07b508;
case 0x0c07b50au: goto P_0c07b50a;
case 0x0c07b50cu: goto P_0c07b50c;
case 0x0c07b50eu: goto P_0c07b50e;
case 0x0c07b510u: goto P_0c07b510;
case 0x0c07b512u: goto P_0c07b512;
case 0x0c07b514u: goto P_0c07b514;
case 0x0c07b516u: goto P_0c07b516;
case 0x0c07b518u: goto P_0c07b518;
case 0x0c07b51au: goto P_0c07b51a;
case 0x0c07b51cu: goto P_0c07b51c;
case 0x0c07b51eu: goto P_0c07b51e;
case 0x0c07b520u: goto P_0c07b520;
case 0x0c07b522u: goto P_0c07b522;
case 0x0c07b524u: goto P_0c07b524;
case 0x0c07b526u: goto P_0c07b526;
case 0x0c07b528u: goto P_0c07b528;
case 0x0c07b52au: goto P_0c07b52a;
case 0x0c07b52cu: goto P_0c07b52c;
case 0x0c07b52eu: goto P_0c07b52e;
case 0x0c07b530u: goto P_0c07b530;
case 0x0c07b532u: goto P_0c07b532;
case 0x0c07b534u: goto P_0c07b534;
case 0x0c07b536u: goto P_0c07b536;
case 0x0c07b538u: goto P_0c07b538;
case 0x0c07b53au: goto P_0c07b53a;
case 0x0c07b53cu: goto P_0c07b53c;
case 0x0c07b53eu: goto P_0c07b53e;
case 0x0c07b540u: goto P_0c07b540;
case 0x0c07b542u: goto P_0c07b542;
case 0x0c07b544u: goto P_0c07b544;
case 0x0c07b546u: goto P_0c07b546;
case 0x0c07b548u: goto P_0c07b548;
case 0x0c07b54au: goto P_0c07b54a;
case 0x0c07b54cu: goto P_0c07b54c;
case 0x0c07b54eu: goto P_0c07b54e;
case 0x0c07b550u: goto P_0c07b550;
case 0x0c07b552u: goto P_0c07b552;
case 0x0c07b554u: goto P_0c07b554;
case 0x0c07b556u: goto P_0c07b556;
case 0x0c07b558u: goto P_0c07b558;
case 0x0c07b55au: goto P_0c07b55a;
case 0x0c07b55cu: goto P_0c07b55c;
case 0x0c07b55eu: goto P_0c07b55e;
case 0x0c07b560u: goto P_0c07b560;
case 0x0c07b562u: goto P_0c07b562;
case 0x0c07b564u: goto P_0c07b564;
case 0x0c07b566u: goto P_0c07b566;
case 0x0c07b568u: goto P_0c07b568;
case 0x0c07b56au: goto P_0c07b56a;
case 0x0c07b56cu: goto P_0c07b56c;
case 0x0c07b56eu: goto P_0c07b56e;
case 0x0c07b570u: goto P_0c07b570;
case 0x0c07b572u: goto P_0c07b572;
case 0x0c07b574u: goto P_0c07b574;
case 0x0c07b576u: goto P_0c07b576;
case 0x0c07b578u: goto P_0c07b578;
case 0x0c07b57au: goto P_0c07b57a;
case 0x0c07b57cu: goto P_0c07b57c;
case 0x0c07b57eu: goto P_0c07b57e;
case 0x0c07b580u: goto P_0c07b580;
case 0x0c07b582u: goto P_0c07b582;
case 0x0c07b584u: goto P_0c07b584;
case 0x0c07b586u: goto P_0c07b586;
case 0x0c07b588u: goto P_0c07b588;
case 0x0c07b58au: goto P_0c07b58a;
case 0x0c07b58cu: goto P_0c07b58c;
case 0x0c07b58eu: goto P_0c07b58e;
case 0x0c07b590u: goto P_0c07b590;
case 0x0c07b592u: goto P_0c07b592;
case 0x0c07b594u: goto P_0c07b594;
case 0x0c07b596u: goto P_0c07b596;
case 0x0c07b598u: goto P_0c07b598;
case 0x0c07b59au: goto P_0c07b59a;
case 0x0c07b59cu: goto P_0c07b59c;
case 0x0c07b59eu: goto P_0c07b59e;
case 0x0c07b5a0u: goto P_0c07b5a0;
case 0x0c07b5a2u: goto P_0c07b5a2;
case 0x0c07b5a4u: goto P_0c07b5a4;
case 0x0c07b5a6u: goto P_0c07b5a6;
case 0x0c07b5a8u: goto P_0c07b5a8;
case 0x0c07b5aau: goto P_0c07b5aa;
case 0x0c07b5acu: goto P_0c07b5ac;
case 0x0c07b5aeu: goto P_0c07b5ae;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07aaac: /* original 2fe6, guest PC 0x0c07aaac */
if(!s->budget--) { s->failed_pc=0x0c07aaacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07aaae;
P_0c07aaae: /* original 2fd6, guest PC 0x0c07aaae */
if(!s->budget--) { s->failed_pc=0x0c07aaaeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07aab0;
P_0c07aab0: /* original 4f22, guest PC 0x0c07aab0 */
if(!s->budget--) { s->failed_pc=0x0c07aab0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07aab2;
P_0c07aab2: /* original d314, guest PC 0x0c07aab2 */
if(!s->budget--) { s->failed_pc=0x0c07aab2u; return 0; }
r[3]=read(ram,0x0c07ab04u,4);
goto P_0c07aab4;
P_0c07aab4: /* original b57c, guest PC 0x0c07aab4 */
if(!s->budget--) { s->failed_pc=0x0c07aab4u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07aab8u;
tmp=read(ram,r[3],4);
r[13]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aab8u) { target=s->pc; goto dispatch; }
goto P_0c07aab8;
P_0c07aab6: /* original 6d32, guest PC 0x0c07aab6 */
if(!s->budget--) { s->failed_pc=0x0c07aab6u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c07aab8;
P_0c07aab8: /* original 6e03, guest PC 0x0c07aab8 */
if(!s->budget--) { s->failed_pc=0x0c07aab8u; return 0; }
r[14]=r[0];
goto P_0c07aaba;
P_0c07aaba: /* original d00e, guest PC 0x0c07aaba */
if(!s->budget--) { s->failed_pc=0x0c07aabau; return 0; }
r[0]=read(ram,0x0c07aaf4u,4);
goto P_0c07aabc;
P_0c07aabc: /* original 64ed, guest PC 0x0c07aabc */
if(!s->budget--) { s->failed_pc=0x0c07aabcu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07aabe;
P_0c07aabe: /* original 4400, guest PC 0x0c07aabe */
if(!s->budget--) { s->failed_pc=0x0c07aabeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07aac0;
P_0c07aac0: /* original 044d, guest PC 0x0c07aac0 */
if(!s->budget--) { s->failed_pc=0x0c07aac0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07aac2;
P_0c07aac2: /* original 644d, guest PC 0x0c07aac2 */
if(!s->budget--) { s->failed_pc=0x0c07aac2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07aac4;
P_0c07aac4: /* original 2448, guest PC 0x0c07aac4 */
if(!s->budget--) { s->failed_pc=0x0c07aac4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07aac6;
P_0c07aac6: /* original 8902, guest PC 0x0c07aac6 */
if(!s->budget--) { s->failed_pc=0x0c07aac6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07aace; }
goto P_0c07aac8;
P_0c07aac8: /* original d20b, guest PC 0x0c07aac8 */
if(!s->budget--) { s->failed_pc=0x0c07aac8u; return 0; }
r[2]=read(ram,0x0c07aaf8u,4);
goto P_0c07aaca;
P_0c07aaca: /* original 3420, guest PC 0x0c07aaca */
if(!s->budget--) { s->failed_pc=0x0c07aacau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07aacc;
P_0c07aacc: /* original 8b0d, guest PC 0x0c07aacc */
if(!s->budget--) { s->failed_pc=0x0c07aaccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07aaea; }
goto P_0c07aace;
P_0c07aace: /* original 64ed, guest PC 0x0c07aace */
if(!s->budget--) { s->failed_pc=0x0c07aaceu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07aad0;
P_0c07aad0: /* original d00d, guest PC 0x0c07aad0 */
if(!s->budget--) { s->failed_pc=0x0c07aad0u; return 0; }
r[0]=read(ram,0x0c07ab08u,4);
goto P_0c07aad2;
P_0c07aad2: /* original d30f, guest PC 0x0c07aad2 */
if(!s->budget--) { s->failed_pc=0x0c07aad2u; return 0; }
r[3]=read(ram,0x0c07ab10u,4);
goto P_0c07aad4;
P_0c07aad4: /* original 74f8, guest PC 0x0c07aad4 */
if(!s->budget--) { s->failed_pc=0x0c07aad4u; return 0; }
r[4]+=0xfffffff8u;
goto P_0c07aad6;
P_0c07aad6: /* original 65d3, guest PC 0x0c07aad6 */
if(!s->budget--) { s->failed_pc=0x0c07aad6u; return 0; }
r[5]=r[13];
goto P_0c07aad8;
P_0c07aad8: /* original 4408, guest PC 0x0c07aad8 */
if(!s->budget--) { s->failed_pc=0x0c07aad8u; return 0; }
r[4]<<=2;
goto P_0c07aada;
P_0c07aada: /* original 430b, guest PC 0x0c07aada */
if(!s->budget--) { s->failed_pc=0x0c07aadau; return 0; }
target=r[3];
r[16]=code_base|0x0c07aadeu;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aadeu) { target=s->pc; goto dispatch; }
goto P_0c07aade;
P_0c07aadc: /* original 044e, guest PC 0x0c07aadc */
if(!s->budget--) { s->failed_pc=0x0c07aadcu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07aade;
P_0c07aade: /* original 4f26, guest PC 0x0c07aade */
if(!s->budget--) { s->failed_pc=0x0c07aadeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aae0;
P_0c07aae0: /* original 65d3, guest PC 0x0c07aae0 */
if(!s->budget--) { s->failed_pc=0x0c07aae0u; return 0; }
r[5]=r[13];
goto P_0c07aae2;
P_0c07aae2: /* original 64e3, guest PC 0x0c07aae2 */
if(!s->budget--) { s->failed_pc=0x0c07aae2u; return 0; }
r[4]=r[14];
goto P_0c07aae4;
P_0c07aae4: /* original 6df6, guest PC 0x0c07aae4 */
if(!s->budget--) { s->failed_pc=0x0c07aae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aae6;
P_0c07aae6: /* original aead, guest PC 0x0c07aae6 */
if(!s->budget--) { s->failed_pc=0x0c07aae6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07a844u,s,ram);
P_0c07aae8: /* original 6ef6, guest PC 0x0c07aae8 */
if(!s->budget--) { s->failed_pc=0x0c07aae8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07aaea;
P_0c07aaea: /* original 4f26, guest PC 0x0c07aaea */
if(!s->budget--) { s->failed_pc=0x0c07aaeau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aaec;
P_0c07aaec: /* original 6df6, guest PC 0x0c07aaec */
if(!s->budget--) { s->failed_pc=0x0c07aaecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aaee;
P_0c07aaee: /* original 000b, guest PC 0x0c07aaee */
if(!s->budget--) { s->failed_pc=0x0c07aaeeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07aaf0: /* original 6ef6, guest PC 0x0c07aaf0 */
if(!s->budget--) { s->failed_pc=0x0c07aaf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07aaf2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07aaf2u; return 0; } return 1;
P_0c07b204: /* original 2fe6, guest PC 0x0c07b204 */
if(!s->budget--) { s->failed_pc=0x0c07b204u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b206;
P_0c07b206: /* original e400, guest PC 0x0c07b206 */
if(!s->budget--) { s->failed_pc=0x0c07b206u; return 0; }
r[4]=0x00000000u;
goto P_0c07b208;
P_0c07b208: /* original 2fd6, guest PC 0x0c07b208 */
if(!s->budget--) { s->failed_pc=0x0c07b208u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b20a;
P_0c07b20a: /* original e654, guest PC 0x0c07b20a */
if(!s->budget--) { s->failed_pc=0x0c07b20au; return 0; }
r[6]=0x00000054u;
goto P_0c07b20c;
P_0c07b20c: /* original 2fc6, guest PC 0x0c07b20c */
if(!s->budget--) { s->failed_pc=0x0c07b20cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b20e;
P_0c07b20e: /* original 2fb6, guest PC 0x0c07b20e */
if(!s->budget--) { s->failed_pc=0x0c07b20eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b210;
P_0c07b210: /* original eb00, guest PC 0x0c07b210 */
if(!s->budget--) { s->failed_pc=0x0c07b210u; return 0; }
r[11]=0x00000000u;
goto P_0c07b212;
P_0c07b212: /* original 2fa6, guest PC 0x0c07b212 */
if(!s->budget--) { s->failed_pc=0x0c07b212u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b214;
P_0c07b214: /* original 65b3, guest PC 0x0c07b214 */
if(!s->budget--) { s->failed_pc=0x0c07b214u; return 0; }
r[5]=r[11];
goto P_0c07b216;
P_0c07b216: /* original 4f22, guest PC 0x0c07b216 */
if(!s->budget--) { s->failed_pc=0x0c07b216u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b218;
P_0c07b218: /* original d348, guest PC 0x0c07b218 */
if(!s->budget--) { s->failed_pc=0x0c07b218u; return 0; }
r[3]=read(ram,0x0c07b33cu,4);
goto P_0c07b21a;
P_0c07b21a: /* original d249, guest PC 0x0c07b21a */
if(!s->budget--) { s->failed_pc=0x0c07b21au; return 0; }
r[2]=read(ram,0x0c07b340u,4);
goto P_0c07b21c;
P_0c07b21c: /* original 6e32, guest PC 0x0c07b21c */
if(!s->budget--) { s->failed_pc=0x0c07b21cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c07b21e;
P_0c07b21e: /* original 7ffc, guest PC 0x0c07b21e */
if(!s->budget--) { s->failed_pc=0x0c07b21eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b220;
P_0c07b220: /* original 2f22, guest PC 0x0c07b220 */
if(!s->budget--) { s->failed_pc=0x0c07b220u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07b222;
P_0c07b222: /* original dd48, guest PC 0x0c07b222 */
if(!s->budget--) { s->failed_pc=0x0c07b222u; return 0; }
r[13]=read(ram,0x0c07b344u,4);
goto P_0c07b224;
P_0c07b224: /* original 34dc, guest PC 0x0c07b224 */
if(!s->budget--) { s->failed_pc=0x0c07b224u; return 0; }
r[4]+=r[13];
goto P_0c07b226;
P_0c07b226: /* original 7501, guest PC 0x0c07b226 */
if(!s->budget--) { s->failed_pc=0x0c07b226u; return 0; }
r[5]+=0x00000001u;
goto P_0c07b228;
P_0c07b228: /* original 24b1, guest PC 0x0c07b228 */
if(!s->budget--) { s->failed_pc=0x0c07b228u; return 0; }
write(ram,r[4],r[11],2);
goto P_0c07b22a;
P_0c07b22a: /* original 3563, guest PC 0x0c07b22a */
if(!s->budget--) { s->failed_pc=0x0c07b22au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c07b22c;
P_0c07b22c: /* original 8ffb, guest PC 0x0c07b22c */
if(!s->budget--) { s->failed_pc=0x0c07b22cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000002u;
if(!cond) { goto P_0c07b226; }
goto P_0c07b230;
P_0c07b22e: /* original 7402, guest PC 0x0c07b22e */
if(!s->budget--) { s->failed_pc=0x0c07b22eu; return 0; }
r[4]+=0x00000002u;
goto P_0c07b230;
P_0c07b230: /* original d245, guest PC 0x0c07b230 */
if(!s->budget--) { s->failed_pc=0x0c07b230u; return 0; }
r[2]=read(ram,0x0c07b348u,4);
goto P_0c07b232;
P_0c07b232: /* original 65e3, guest PC 0x0c07b232 */
if(!s->budget--) { s->failed_pc=0x0c07b232u; return 0; }
r[5]=r[14];
goto P_0c07b234;
P_0c07b234: /* original 420b, guest PC 0x0c07b234 */
if(!s->budget--) { s->failed_pc=0x0c07b234u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b238u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b238u) { target=s->pc; goto dispatch; }
goto P_0c07b238;
P_0c07b236: /* original e401, guest PC 0x0c07b236 */
if(!s->budget--) { s->failed_pc=0x0c07b236u; return 0; }
r[4]=0x00000001u;
goto P_0c07b238;
P_0c07b238: /* original dc44, guest PC 0x0c07b238 */
if(!s->budget--) { s->failed_pc=0x0c07b238u; return 0; }
r[12]=read(ram,0x0c07b34cu,4);
goto P_0c07b23a;
P_0c07b23a: /* original 4c0b, guest PC 0x0c07b23a */
if(!s->budget--) { s->failed_pc=0x0c07b23au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b23eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b23eu) { target=s->pc; goto dispatch; }
goto P_0c07b23e;
P_0c07b23c: /* original e400, guest PC 0x0c07b23c */
if(!s->budget--) { s->failed_pc=0x0c07b23cu; return 0; }
r[4]=0x00000000u;
goto P_0c07b23e;
P_0c07b23e: /* original da44, guest PC 0x0c07b23e */
if(!s->budget--) { s->failed_pc=0x0c07b23eu; return 0; }
r[10]=read(ram,0x0c07b350u,4);
goto P_0c07b240;
P_0c07b240: /* original 65e3, guest PC 0x0c07b240 */
if(!s->budget--) { s->failed_pc=0x0c07b240u; return 0; }
r[5]=r[14];
goto P_0c07b242;
P_0c07b242: /* original bad1, guest PC 0x0c07b242 */
if(!s->budget--) { s->failed_pc=0x0c07b242u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b246u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b246u) { target=s->pc; goto dispatch; }
goto P_0c07b246;
P_0c07b244: /* original 64a3, guest PC 0x0c07b244 */
if(!s->budget--) { s->failed_pc=0x0c07b244u; return 0; }
r[4]=r[10];
goto P_0c07b246;
P_0c07b246: /* original 4c0b, guest PC 0x0c07b246 */
if(!s->budget--) { s->failed_pc=0x0c07b246u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b24au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b24au) { target=s->pc; goto dispatch; }
goto P_0c07b24a;
P_0c07b248: /* original e401, guest PC 0x0c07b248 */
if(!s->budget--) { s->failed_pc=0x0c07b248u; return 0; }
r[4]=0x00000001u;
goto P_0c07b24a;
P_0c07b24a: /* original 64a3, guest PC 0x0c07b24a */
if(!s->budget--) { s->failed_pc=0x0c07b24au; return 0; }
r[4]=r[10];
goto P_0c07b24c;
P_0c07b24c: /* original 65e3, guest PC 0x0c07b24c */
if(!s->budget--) { s->failed_pc=0x0c07b24cu; return 0; }
r[5]=r[14];
goto P_0c07b24e;
P_0c07b24e: /* original bacb, guest PC 0x0c07b24e */
if(!s->budget--) { s->failed_pc=0x0c07b24eu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b252u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b252u) { target=s->pc; goto dispatch; }
goto P_0c07b252;
P_0c07b250: /* original 7410, guest PC 0x0c07b250 */
if(!s->budget--) { s->failed_pc=0x0c07b250u; return 0; }
r[4]+=0x00000010u;
goto P_0c07b252;
P_0c07b252: /* original 4c0b, guest PC 0x0c07b252 */
if(!s->budget--) { s->failed_pc=0x0c07b252u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b256u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b256u) { target=s->pc; goto dispatch; }
goto P_0c07b256;
P_0c07b254: /* original e402, guest PC 0x0c07b254 */
if(!s->budget--) { s->failed_pc=0x0c07b254u; return 0; }
r[4]=0x00000002u;
goto P_0c07b256;
P_0c07b256: /* original 64a3, guest PC 0x0c07b256 */
if(!s->budget--) { s->failed_pc=0x0c07b256u; return 0; }
r[4]=r[10];
goto P_0c07b258;
P_0c07b258: /* original 65e3, guest PC 0x0c07b258 */
if(!s->budget--) { s->failed_pc=0x0c07b258u; return 0; }
r[5]=r[14];
goto P_0c07b25a;
P_0c07b25a: /* original bac5, guest PC 0x0c07b25a */
if(!s->budget--) { s->failed_pc=0x0c07b25au; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b25eu;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b25eu) { target=s->pc; goto dispatch; }
goto P_0c07b25e;
P_0c07b25c: /* original 7420, guest PC 0x0c07b25c */
if(!s->budget--) { s->failed_pc=0x0c07b25cu; return 0; }
r[4]+=0x00000020u;
goto P_0c07b25e;
P_0c07b25e: /* original 4c0b, guest PC 0x0c07b25e */
if(!s->budget--) { s->failed_pc=0x0c07b25eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b262u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b262u) { target=s->pc; goto dispatch; }
goto P_0c07b262;
P_0c07b260: /* original e403, guest PC 0x0c07b260 */
if(!s->budget--) { s->failed_pc=0x0c07b260u; return 0; }
r[4]=0x00000003u;
goto P_0c07b262;
P_0c07b262: /* original 64a3, guest PC 0x0c07b262 */
if(!s->budget--) { s->failed_pc=0x0c07b262u; return 0; }
r[4]=r[10];
goto P_0c07b264;
P_0c07b264: /* original 65e3, guest PC 0x0c07b264 */
if(!s->budget--) { s->failed_pc=0x0c07b264u; return 0; }
r[5]=r[14];
goto P_0c07b266;
P_0c07b266: /* original babf, guest PC 0x0c07b266 */
if(!s->budget--) { s->failed_pc=0x0c07b266u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b26au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b26au) { target=s->pc; goto dispatch; }
goto P_0c07b26a;
P_0c07b268: /* original 7430, guest PC 0x0c07b268 */
if(!s->budget--) { s->failed_pc=0x0c07b268u; return 0; }
r[4]+=0x00000030u;
goto P_0c07b26a;
P_0c07b26a: /* original 4c0b, guest PC 0x0c07b26a */
if(!s->budget--) { s->failed_pc=0x0c07b26au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b26eu;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b26eu) { target=s->pc; goto dispatch; }
goto P_0c07b26e;
P_0c07b26c: /* original e404, guest PC 0x0c07b26c */
if(!s->budget--) { s->failed_pc=0x0c07b26cu; return 0; }
r[4]=0x00000004u;
goto P_0c07b26e;
P_0c07b26e: /* original 64a3, guest PC 0x0c07b26e */
if(!s->budget--) { s->failed_pc=0x0c07b26eu; return 0; }
r[4]=r[10];
goto P_0c07b270;
P_0c07b270: /* original 65e3, guest PC 0x0c07b270 */
if(!s->budget--) { s->failed_pc=0x0c07b270u; return 0; }
r[5]=r[14];
goto P_0c07b272;
P_0c07b272: /* original bab9, guest PC 0x0c07b272 */
if(!s->budget--) { s->failed_pc=0x0c07b272u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b276u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b276u) { target=s->pc; goto dispatch; }
goto P_0c07b276;
P_0c07b274: /* original 7440, guest PC 0x0c07b274 */
if(!s->budget--) { s->failed_pc=0x0c07b274u; return 0; }
r[4]+=0x00000040u;
goto P_0c07b276;
P_0c07b276: /* original 4c0b, guest PC 0x0c07b276 */
if(!s->budget--) { s->failed_pc=0x0c07b276u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b27au;
r[4]=0x00000053u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b27au) { target=s->pc; goto dispatch; }
goto P_0c07b27a;
P_0c07b278: /* original e453, guest PC 0x0c07b278 */
if(!s->budget--) { s->failed_pc=0x0c07b278u; return 0; }
r[4]=0x00000053u;
goto P_0c07b27a;
P_0c07b27a: /* original 64a3, guest PC 0x0c07b27a */
if(!s->budget--) { s->failed_pc=0x0c07b27au; return 0; }
r[4]=r[10];
goto P_0c07b27c;
P_0c07b27c: /* original 65e3, guest PC 0x0c07b27c */
if(!s->budget--) { s->failed_pc=0x0c07b27cu; return 0; }
r[5]=r[14];
goto P_0c07b27e;
P_0c07b27e: /* original bab3, guest PC 0x0c07b27e */
if(!s->budget--) { s->failed_pc=0x0c07b27eu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b282u;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b282u) { target=s->pc; goto dispatch; }
goto P_0c07b282;
P_0c07b280: /* original 7450, guest PC 0x0c07b280 */
if(!s->budget--) { s->failed_pc=0x0c07b280u; return 0; }
r[4]+=0x00000050u;
goto P_0c07b282;
P_0c07b282: /* original e001, guest PC 0x0c07b282 */
if(!s->budget--) { s->failed_pc=0x0c07b282u; return 0; }
r[0]=0x00000001u;
goto P_0c07b284;
P_0c07b284: /* original 2db1, guest PC 0x0c07b284 */
if(!s->budget--) { s->failed_pc=0x0c07b284u; return 0; }
write(ram,r[13],r[11],2);
goto P_0c07b286;
P_0c07b286: /* original 81d1, guest PC 0x0c07b286 */
if(!s->budget--) { s->failed_pc=0x0c07b286u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c07b288;
P_0c07b288: /* original e002, guest PC 0x0c07b288 */
if(!s->budget--) { s->failed_pc=0x0c07b288u; return 0; }
r[0]=0x00000002u;
goto P_0c07b28a;
P_0c07b28a: /* original 81d2, guest PC 0x0c07b28a */
if(!s->budget--) { s->failed_pc=0x0c07b28au; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c07b28c;
P_0c07b28c: /* original e003, guest PC 0x0c07b28c */
if(!s->budget--) { s->failed_pc=0x0c07b28cu; return 0; }
r[0]=0x00000003u;
goto P_0c07b28e;
P_0c07b28e: /* original 81d3, guest PC 0x0c07b28e */
if(!s->budget--) { s->failed_pc=0x0c07b28eu; return 0; }
write(ram,r[13]+6,r[0],2);
goto P_0c07b290;
P_0c07b290: /* original e004, guest PC 0x0c07b290 */
if(!s->budget--) { s->failed_pc=0x0c07b290u; return 0; }
r[0]=0x00000004u;
goto P_0c07b292;
P_0c07b292: /* original 81d4, guest PC 0x0c07b292 */
if(!s->budget--) { s->failed_pc=0x0c07b292u; return 0; }
write(ram,r[13]+8,r[0],2);
goto P_0c07b294;
P_0c07b294: /* original e353, guest PC 0x0c07b294 */
if(!s->budget--) { s->failed_pc=0x0c07b294u; return 0; }
r[3]=0x00000053u;
goto P_0c07b296;
P_0c07b296: /* original 904e, guest PC 0x0c07b296 */
if(!s->budget--) { s->failed_pc=0x0c07b296u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b336u,2);
goto P_0c07b298;
P_0c07b298: /* original 0d35, guest PC 0x0c07b298 */
if(!s->budget--) { s->failed_pc=0x0c07b298u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b29a;
P_0c07b29a: /* original d32e, guest PC 0x0c07b29a */
if(!s->budget--) { s->failed_pc=0x0c07b29au; return 0; }
r[3]=read(ram,0x0c07b354u,4);
goto P_0c07b29c;
P_0c07b29c: /* original 64f2, guest PC 0x0c07b29c */
if(!s->budget--) { s->failed_pc=0x0c07b29cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07b29e;
P_0c07b29e: /* original 430b, guest PC 0x0c07b29e */
if(!s->budget--) { s->failed_pc=0x0c07b29eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07b2a2u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b2a2u) { target=s->pc; goto dispatch; }
goto P_0c07b2a2;
P_0c07b2a0: /* original 7412, guest PC 0x0c07b2a0 */
if(!s->budget--) { s->failed_pc=0x0c07b2a0u; return 0; }
r[4]+=0x00000012u;
goto P_0c07b2a2;
P_0c07b2a2: /* original 600c, guest PC 0x0c07b2a2 */
if(!s->budget--) { s->failed_pc=0x0c07b2a2u; return 0; }
r[0]=r[0]&255u;
goto P_0c07b2a4;
P_0c07b2a4: /* original 2008, guest PC 0x0c07b2a4 */
if(!s->budget--) { s->failed_pc=0x0c07b2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b2a6;
P_0c07b2a6: /* original 8d02, guest PC 0x0c07b2a6 */
if(!s->budget--) { s->failed_pc=0x0c07b2a6u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c07b2ae; }
goto P_0c07b2aa;
P_0c07b2a8: /* original 7f04, guest PC 0x0c07b2a8 */
if(!s->budget--) { s->failed_pc=0x0c07b2a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07b2aa;
P_0c07b2aa: /* original a001, guest PC 0x0c07b2aa */
if(!s->budget--) { s->failed_pc=0x0c07b2aau; return 0; }
r[4]=0x00000008u;
goto P_0c07b2b0;
P_0c07b2ac: /* original e408, guest PC 0x0c07b2ac */
if(!s->budget--) { s->failed_pc=0x0c07b2acu; return 0; }
r[4]=0x00000008u;
goto P_0c07b2ae;
P_0c07b2ae: /* original e409, guest PC 0x0c07b2ae */
if(!s->budget--) { s->failed_pc=0x0c07b2aeu; return 0; }
r[4]=0x00000009u;
goto P_0c07b2b0;
P_0c07b2b0: /* original 4f26, guest PC 0x0c07b2b0 */
if(!s->budget--) { s->failed_pc=0x0c07b2b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b2b2;
P_0c07b2b2: /* original 6af6, guest PC 0x0c07b2b2 */
if(!s->budget--) { s->failed_pc=0x0c07b2b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07b2b4;
P_0c07b2b4: /* original 6bf6, guest PC 0x0c07b2b4 */
if(!s->budget--) { s->failed_pc=0x0c07b2b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b2b6;
P_0c07b2b6: /* original 6cf6, guest PC 0x0c07b2b6 */
if(!s->budget--) { s->failed_pc=0x0c07b2b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b2b8;
P_0c07b2b8: /* original 6df6, guest PC 0x0c07b2b8 */
if(!s->budget--) { s->failed_pc=0x0c07b2b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b2ba;
P_0c07b2ba: /* original abf7, guest PC 0x0c07b2ba */
if(!s->budget--) { s->failed_pc=0x0c07b2bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07aaac;
P_0c07b2bc: /* original 6ef6, guest PC 0x0c07b2bc */
if(!s->budget--) { s->failed_pc=0x0c07b2bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b2beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b2beu; return 0; } return 1;
P_0c07b398: /* original c748, guest PC 0x0c07b398 */
if(!s->budget--) { s->failed_pc=0x0c07b398u; return 0; }
r[0]=code_base|0x0007b4bcu;
goto P_0c07b39a;
P_0c07b39a: /* original f24c, guest PC 0x0c07b39a */
if(!s->budget--) { s->failed_pc=0x0c07b39au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b39c;
P_0c07b39c: /* original f308, guest PC 0x0c07b39c */
if(!s->budget--) { s->failed_pc=0x0c07b39cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b39e;
P_0c07b39e: /* original e018, guest PC 0x0c07b39e */
if(!s->budget--) { s->failed_pc=0x0c07b39eu; return 0; }
r[0]=0x00000018u;
goto P_0c07b3a0;
P_0c07b3a0: /* original f460, guest PC 0x0c07b3a0 */
if(!s->budget--) { s->failed_pc=0x0c07b3a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07b3a2;
P_0c07b3a2: /* original f230, guest PC 0x0c07b3a2 */
if(!s->budget--) { s->failed_pc=0x0c07b3a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c07b3a4;
P_0c07b3a4: /* original f282, guest PC 0x0c07b3a4 */
if(!s->budget--) { s->failed_pc=0x0c07b3a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c07b3a6;
P_0c07b3a6: /* original f427, guest PC 0x0c07b3a6 */
if(!s->budget--) { s->failed_pc=0x0c07b3a6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07b3a8;
P_0c07b3a8: /* original c745, guest PC 0x0c07b3a8 */
if(!s->budget--) { s->failed_pc=0x0c07b3a8u; return 0; }
r[0]=code_base|0x0007b4c0u;
goto P_0c07b3aa;
P_0c07b3aa: /* original f208, guest PC 0x0c07b3aa */
if(!s->budget--) { s->failed_pc=0x0c07b3aau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b3ac;
P_0c07b3ac: /* original e01c, guest PC 0x0c07b3ac */
if(!s->budget--) { s->failed_pc=0x0c07b3acu; return 0; }
r[0]=0x0000001cu;
goto P_0c07b3ae;
P_0c07b3ae: /* original f15c, guest PC 0x0c07b3ae */
if(!s->budget--) { s->failed_pc=0x0c07b3aeu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c07b3b0;
P_0c07b3b0: /* original f570, guest PC 0x0c07b3b0 */
if(!s->budget--) { s->failed_pc=0x0c07b3b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c07b3b2;
P_0c07b3b2: /* original f120, guest PC 0x0c07b3b2 */
if(!s->budget--) { s->failed_pc=0x0c07b3b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c07b3b4;
P_0c07b3b4: /* original f192, guest PC 0x0c07b3b4 */
if(!s->budget--) { s->failed_pc=0x0c07b3b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07b3b6;
P_0c07b3b6: /* original f417, guest PC 0x0c07b3b6 */
if(!s->budget--) { s->failed_pc=0x0c07b3b6u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c07b3b8;
P_0c07b3b8: /* original c742, guest PC 0x0c07b3b8 */
if(!s->budget--) { s->failed_pc=0x0c07b3b8u; return 0; }
r[0]=code_base|0x0007b4c4u;
goto P_0c07b3ba;
P_0c07b3ba: /* original f108, guest PC 0x0c07b3ba */
if(!s->budget--) { s->failed_pc=0x0c07b3bau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c07b3bc;
P_0c07b3bc: /* original e020, guest PC 0x0c07b3bc */
if(!s->budget--) { s->failed_pc=0x0c07b3bcu; return 0; }
r[0]=0x00000020u;
goto P_0c07b3be;
P_0c07b3be: /* original f410, guest PC 0x0c07b3be */
if(!s->budget--) { s->failed_pc=0x0c07b3beu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c07b3c0;
P_0c07b3c0: /* original f482, guest PC 0x0c07b3c0 */
if(!s->budget--) { s->failed_pc=0x0c07b3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c07b3c2;
P_0c07b3c2: /* original f447, guest PC 0x0c07b3c2 */
if(!s->budget--) { s->failed_pc=0x0c07b3c2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b3c4;
P_0c07b3c4: /* original c740, guest PC 0x0c07b3c4 */
if(!s->budget--) { s->failed_pc=0x0c07b3c4u; return 0; }
r[0]=code_base|0x0007b4c8u;
goto P_0c07b3c6;
P_0c07b3c6: /* original f308, guest PC 0x0c07b3c6 */
if(!s->budget--) { s->failed_pc=0x0c07b3c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b3c8;
P_0c07b3c8: /* original e024, guest PC 0x0c07b3c8 */
if(!s->budget--) { s->failed_pc=0x0c07b3c8u; return 0; }
r[0]=0x00000024u;
goto P_0c07b3ca;
P_0c07b3ca: /* original f530, guest PC 0x0c07b3ca */
if(!s->budget--) { s->failed_pc=0x0c07b3cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c07b3cc;
P_0c07b3cc: /* original f592, guest PC 0x0c07b3cc */
if(!s->budget--) { s->failed_pc=0x0c07b3ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b3ce;
P_0c07b3ce: /* original 000b, guest PC 0x0c07b3ce */
if(!s->budget--) { s->failed_pc=0x0c07b3ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c07b3d0: /* original f457, guest PC 0x0c07b3d0 */
if(!s->budget--) { s->failed_pc=0x0c07b3d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07b3d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b3d2u; return 0; } return 1;
P_0c07b4d4: /* original 654d, guest PC 0x0c07b4d4 */
if(!s->budget--) { s->failed_pc=0x0c07b4d4u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b4d6;
P_0c07b4d6: /* original 2fe6, guest PC 0x0c07b4d6 */
if(!s->budget--) { s->failed_pc=0x0c07b4d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4d8;
P_0c07b4d8: /* original 2fd6, guest PC 0x0c07b4d8 */
if(!s->budget--) { s->failed_pc=0x0c07b4d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4da;
P_0c07b4da: /* original 9378, guest PC 0x0c07b4da */
if(!s->budget--) { s->failed_pc=0x0c07b4dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b4dc;
P_0c07b4dc: /* original 2358, guest PC 0x0c07b4dc */
if(!s->budget--) { s->failed_pc=0x0c07b4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c07b4de;
P_0c07b4de: /* original 8912, guest PC 0x0c07b4de */
if(!s->budget--) { s->failed_pc=0x0c07b4deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b506; }
goto P_0c07b4e0;
P_0c07b4e0: /* original 9476, guest PC 0x0c07b4e0 */
if(!s->budget--) { s->failed_pc=0x0c07b4e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b4e2;
P_0c07b4e2: /* original d23c, guest PC 0x0c07b4e2 */
if(!s->budget--) { s->failed_pc=0x0c07b4e2u; return 0; }
r[2]=read(ram,0x0c07b5d4u,4);
goto P_0c07b4e4;
P_0c07b4e4: /* original 2459, guest PC 0x0c07b4e4 */
if(!s->budget--) { s->failed_pc=0x0c07b4e4u; return 0; }
r[4]&=r[5];
goto P_0c07b4e6;
P_0c07b4e6: /* original 6343, guest PC 0x0c07b4e6 */
if(!s->budget--) { s->failed_pc=0x0c07b4e6u; return 0; }
r[3]=r[4];
goto P_0c07b4e8;
P_0c07b4e8: /* original 6543, guest PC 0x0c07b4e8 */
if(!s->budget--) { s->failed_pc=0x0c07b4e8u; return 0; }
r[5]=r[4];
goto P_0c07b4ea;
P_0c07b4ea: /* original 4308, guest PC 0x0c07b4ea */
if(!s->budget--) { s->failed_pc=0x0c07b4eau; return 0; }
r[3]<<=2;
goto P_0c07b4ec;
P_0c07b4ec: /* original 4500, guest PC 0x0c07b4ec */
if(!s->budget--) { s->failed_pc=0x0c07b4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b4ee;
P_0c07b4ee: /* original 353c, guest PC 0x0c07b4ee */
if(!s->budget--) { s->failed_pc=0x0c07b4eeu; return 0; }
r[5]+=r[3];
goto P_0c07b4f0;
P_0c07b4f0: /* original 352c, guest PC 0x0c07b4f0 */
if(!s->budget--) { s->failed_pc=0x0c07b4f0u; return 0; }
r[5]+=r[2];
goto P_0c07b4f2;
P_0c07b4f2: /* original 8452, guest PC 0x0c07b4f2 */
if(!s->budget--) { s->failed_pc=0x0c07b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c07b4f4;
P_0c07b4f4: /* original 6451, guest PC 0x0c07b4f4 */
if(!s->budget--) { s->failed_pc=0x0c07b4f4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c07b4f6;
P_0c07b4f6: /* original 660c, guest PC 0x0c07b4f6 */
if(!s->budget--) { s->failed_pc=0x0c07b4f6u; return 0; }
r[6]=r[0]&255u;
goto P_0c07b4f8;
P_0c07b4f8: /* original 8453, guest PC 0x0c07b4f8 */
if(!s->budget--) { s->failed_pc=0x0c07b4f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c07b4fa;
P_0c07b4fa: /* original 670c, guest PC 0x0c07b4fa */
if(!s->budget--) { s->failed_pc=0x0c07b4fau; return 0; }
r[7]=r[0]&255u;
goto P_0c07b4fc;
P_0c07b4fc: /* original 8454, guest PC 0x0c07b4fc */
if(!s->budget--) { s->failed_pc=0x0c07b4fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c07b4fe;
P_0c07b4fe: /* original 6e0c, guest PC 0x0c07b4fe */
if(!s->budget--) { s->failed_pc=0x0c07b4feu; return 0; }
r[14]=r[0]&255u;
goto P_0c07b500;
P_0c07b500: /* original 8455, guest PC 0x0c07b500 */
if(!s->budget--) { s->failed_pc=0x0c07b500u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c07b502;
P_0c07b502: /* original a00a, guest PC 0x0c07b502 */
if(!s->budget--) { s->failed_pc=0x0c07b502u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b51a;
P_0c07b504: /* original 6d0c, guest PC 0x0c07b504 */
if(!s->budget--) { s->failed_pc=0x0c07b504u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b506;
P_0c07b506: /* original e500, guest PC 0x0c07b506 */
if(!s->budget--) { s->failed_pc=0x0c07b506u; return 0; }
r[5]=0x00000000u;
goto P_0c07b508;
P_0c07b508: /* original d333, guest PC 0x0c07b508 */
if(!s->budget--) { s->failed_pc=0x0c07b508u; return 0; }
r[3]=read(ram,0x0c07b5d8u,4);
goto P_0c07b50a;
P_0c07b50a: /* original 6753, guest PC 0x0c07b50a */
if(!s->budget--) { s->failed_pc=0x0c07b50au; return 0; }
r[7]=r[5];
goto P_0c07b50c;
P_0c07b50c: /* original 6653, guest PC 0x0c07b50c */
if(!s->budget--) { s->failed_pc=0x0c07b50cu; return 0; }
r[6]=r[5];
goto P_0c07b50e;
P_0c07b50e: /* original 654d, guest PC 0x0c07b50e */
if(!s->budget--) { s->failed_pc=0x0c07b50eu; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b510;
P_0c07b510: /* original 4508, guest PC 0x0c07b510 */
if(!s->budget--) { s->failed_pc=0x0c07b510u; return 0; }
r[5]<<=2;
goto P_0c07b512;
P_0c07b512: /* original 353c, guest PC 0x0c07b512 */
if(!s->budget--) { s->failed_pc=0x0c07b512u; return 0; }
r[5]+=r[3];
goto P_0c07b514;
P_0c07b514: /* original 8551, guest PC 0x0c07b514 */
if(!s->budget--) { s->failed_pc=0x0c07b514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b516;
P_0c07b516: /* original 6e51, guest PC 0x0c07b516 */
if(!s->budget--) { s->failed_pc=0x0c07b516u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[14]=tmp;
goto P_0c07b518;
P_0c07b518: /* original 6d03, guest PC 0x0c07b518 */
if(!s->budget--) { s->failed_pc=0x0c07b518u; return 0; }
r[13]=r[0];
goto P_0c07b51a;
P_0c07b51a: /* original 666d, guest PC 0x0c07b51a */
if(!s->budget--) { s->failed_pc=0x0c07b51au; return 0; }
r[6]=r[6]&65535u;
goto P_0c07b51c;
P_0c07b51c: /* original d22f, guest PC 0x0c07b51c */
if(!s->budget--) { s->failed_pc=0x0c07b51cu; return 0; }
r[2]=read(ram,0x0c07b5dcu,4);
goto P_0c07b51e;
P_0c07b51e: /* original 4608, guest PC 0x0c07b51e */
if(!s->budget--) { s->failed_pc=0x0c07b51eu; return 0; }
r[6]<<=2;
goto P_0c07b520;
P_0c07b520: /* original 4600, guest PC 0x0c07b520 */
if(!s->budget--) { s->failed_pc=0x0c07b520u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b522;
P_0c07b522: /* original 677d, guest PC 0x0c07b522 */
if(!s->budget--) { s->failed_pc=0x0c07b522u; return 0; }
r[7]=r[7]&65535u;
goto P_0c07b524;
P_0c07b524: /* original 4708, guest PC 0x0c07b524 */
if(!s->budget--) { s->failed_pc=0x0c07b524u; return 0; }
r[7]<<=2;
goto P_0c07b526;
P_0c07b526: /* original 634d, guest PC 0x0c07b526 */
if(!s->budget--) { s->failed_pc=0x0c07b526u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b528;
P_0c07b528: /* original 2232, guest PC 0x0c07b528 */
if(!s->budget--) { s->failed_pc=0x0c07b528u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07b52a;
P_0c07b52a: /* original 4700, guest PC 0x0c07b52a */
if(!s->budget--) { s->failed_pc=0x0c07b52au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c07b52c;
P_0c07b52c: /* original 465a, guest PC 0x0c07b52c */
if(!s->budget--) { s->failed_pc=0x0c07b52cu; return 0; }
r[53]=r[6];
goto P_0c07b52e;
P_0c07b52e: /* original 6eed, guest PC 0x0c07b52e */
if(!s->budget--) { s->failed_pc=0x0c07b52eu; return 0; }
r[14]=r[14]&65535u;
goto P_0c07b530;
P_0c07b530: /* original d32b, guest PC 0x0c07b530 */
if(!s->budget--) { s->failed_pc=0x0c07b530u; return 0; }
r[3]=read(ram,0x0c07b5e0u,4);
goto P_0c07b532;
P_0c07b532: /* original 4e08, guest PC 0x0c07b532 */
if(!s->budget--) { s->failed_pc=0x0c07b532u; return 0; }
r[14]<<=2;
goto P_0c07b534;
P_0c07b534: /* original 4e00, guest PC 0x0c07b534 */
if(!s->budget--) { s->failed_pc=0x0c07b534u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07b536;
P_0c07b536: /* original f32d, guest PC 0x0c07b536 */
if(!s->budget--) { s->failed_pc=0x0c07b536u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b538;
P_0c07b538: /* original 6ddd, guest PC 0x0c07b538 */
if(!s->budget--) { s->failed_pc=0x0c07b538u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b53a;
P_0c07b53a: /* original 4d08, guest PC 0x0c07b53a */
if(!s->budget--) { s->failed_pc=0x0c07b53au; return 0; }
r[13]<<=2;
goto P_0c07b53c;
P_0c07b53c: /* original 4d00, guest PC 0x0c07b53c */
if(!s->budget--) { s->failed_pc=0x0c07b53cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b53e;
P_0c07b53e: /* original 72e8, guest PC 0x0c07b53e */
if(!s->budget--) { s->failed_pc=0x0c07b53eu; return 0; }
r[2]+=0xffffffe8u;
goto P_0c07b540;
P_0c07b540: /* original 654d, guest PC 0x0c07b540 */
if(!s->budget--) { s->failed_pc=0x0c07b540u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b542;
P_0c07b542: /* original f33a, guest PC 0x0c07b542 */
if(!s->budget--) { s->failed_pc=0x0c07b542u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b544;
P_0c07b544: /* original 730c, guest PC 0x0c07b544 */
if(!s->budget--) { s->failed_pc=0x0c07b544u; return 0; }
r[3]+=0x0000000cu;
goto P_0c07b546;
P_0c07b546: /* original 475a, guest PC 0x0c07b546 */
if(!s->budget--) { s->failed_pc=0x0c07b546u; return 0; }
r[53]=r[7];
goto P_0c07b548;
P_0c07b548: /* original d126, guest PC 0x0c07b548 */
if(!s->budget--) { s->failed_pc=0x0c07b548u; return 0; }
r[1]=read(ram,0x0c07b5e4u,4);
goto P_0c07b54a;
P_0c07b54a: /* original f32d, guest PC 0x0c07b54a */
if(!s->budget--) { s->failed_pc=0x0c07b54au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b54c;
P_0c07b54c: /* original f13a, guest PC 0x0c07b54c */
if(!s->budget--) { s->failed_pc=0x0c07b54cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c07b54e;
P_0c07b54e: /* original 4e5a, guest PC 0x0c07b54e */
if(!s->budget--) { s->failed_pc=0x0c07b54eu; return 0; }
r[53]=r[14];
goto P_0c07b550;
P_0c07b550: /* original f32d, guest PC 0x0c07b550 */
if(!s->budget--) { s->failed_pc=0x0c07b550u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b552;
P_0c07b552: /* original f23a, guest PC 0x0c07b552 */
if(!s->budget--) { s->failed_pc=0x0c07b552u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c07b554;
P_0c07b554: /* original 4d5a, guest PC 0x0c07b554 */
if(!s->budget--) { s->failed_pc=0x0c07b554u; return 0; }
r[53]=r[13];
goto P_0c07b556;
P_0c07b556: /* original f32d, guest PC 0x0c07b556 */
if(!s->budget--) { s->failed_pc=0x0c07b556u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b558;
P_0c07b558: /* original f33a, guest PC 0x0c07b558 */
if(!s->budget--) { s->failed_pc=0x0c07b558u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b55a;
P_0c07b55a: /* original d11f, guest PC 0x0c07b55a */
if(!s->budget--) { s->failed_pc=0x0c07b55au; return 0; }
r[1]=read(ram,0x0c07b5d8u,4);
goto P_0c07b55c;
P_0c07b55c: /* original 4508, guest PC 0x0c07b55c */
if(!s->budget--) { s->failed_pc=0x0c07b55cu; return 0; }
r[5]<<=2;
goto P_0c07b55e;
P_0c07b55e: /* original f49d, guest PC 0x0c07b55e */
if(!s->budget--) { s->failed_pc=0x0c07b55eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c07b560;
P_0c07b560: /* original 7308, guest PC 0x0c07b560 */
if(!s->budget--) { s->failed_pc=0x0c07b560u; return 0; }
r[3]+=0x00000008u;
goto P_0c07b562;
P_0c07b562: /* original 351c, guest PC 0x0c07b562 */
if(!s->budget--) { s->failed_pc=0x0c07b562u; return 0; }
r[5]+=r[1];
goto P_0c07b564;
P_0c07b564: /* original f24c, guest PC 0x0c07b564 */
if(!s->budget--) { s->failed_pc=0x0c07b564u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b566;
P_0c07b566: /* original 6251, guest PC 0x0c07b566 */
if(!s->budget--) { s->failed_pc=0x0c07b566u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b568;
P_0c07b568: /* original 8551, guest PC 0x0c07b568 */
if(!s->budget--) { s->failed_pc=0x0c07b568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b56a;
P_0c07b56a: /* original 642d, guest PC 0x0c07b56a */
if(!s->budget--) { s->failed_pc=0x0c07b56au; return 0; }
r[4]=r[2]&65535u;
goto P_0c07b56c;
P_0c07b56c: /* original d21e, guest PC 0x0c07b56c */
if(!s->budget--) { s->failed_pc=0x0c07b56cu; return 0; }
r[2]=read(ram,0x0c07b5e8u,4);
goto P_0c07b56e;
P_0c07b56e: /* original 4408, guest PC 0x0c07b56e */
if(!s->budget--) { s->failed_pc=0x0c07b56eu; return 0; }
r[4]<<=2;
goto P_0c07b570;
P_0c07b570: /* original 4400, guest PC 0x0c07b570 */
if(!s->budget--) { s->failed_pc=0x0c07b570u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b572;
P_0c07b572: /* original 6123, guest PC 0x0c07b572 */
if(!s->budget--) { s->failed_pc=0x0c07b572u; return 0; }
r[1]=r[2];
goto P_0c07b574;
P_0c07b574: /* original 644d, guest PC 0x0c07b574 */
if(!s->budget--) { s->failed_pc=0x0c07b574u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b576;
P_0c07b576: /* original 445a, guest PC 0x0c07b576 */
if(!s->budget--) { s->failed_pc=0x0c07b576u; return 0; }
r[53]=r[4];
goto P_0c07b578;
P_0c07b578: /* original 650d, guest PC 0x0c07b578 */
if(!s->budget--) { s->failed_pc=0x0c07b578u; return 0; }
r[5]=r[0]&65535u;
goto P_0c07b57a;
P_0c07b57a: /* original 4508, guest PC 0x0c07b57a */
if(!s->budget--) { s->failed_pc=0x0c07b57au; return 0; }
r[5]<<=2;
goto P_0c07b57c;
P_0c07b57c: /* original 4500, guest PC 0x0c07b57c */
if(!s->budget--) { s->failed_pc=0x0c07b57cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b57e;
P_0c07b57e: /* original f32d, guest PC 0x0c07b57e */
if(!s->budget--) { s->failed_pc=0x0c07b57eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b580;
P_0c07b580: /* original 655d, guest PC 0x0c07b580 */
if(!s->budget--) { s->failed_pc=0x0c07b580u; return 0; }
r[5]=r[5]&65535u;
goto P_0c07b582;
P_0c07b582: /* original f233, guest PC 0x0c07b582 */
if(!s->budget--) { s->failed_pc=0x0c07b582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c07b584;
P_0c07b584: /* original f22a, guest PC 0x0c07b584 */
if(!s->budget--) { s->failed_pc=0x0c07b584u; return 0; }
vf3_matrix_store(s,ram,2,r[2]);
goto P_0c07b586;
P_0c07b586: /* original 72f8, guest PC 0x0c07b586 */
if(!s->budget--) { s->failed_pc=0x0c07b586u; return 0; }
r[2]+=0xfffffff8u;
goto P_0c07b588;
P_0c07b588: /* original 455a, guest PC 0x0c07b588 */
if(!s->budget--) { s->failed_pc=0x0c07b588u; return 0; }
r[53]=r[5];
goto P_0c07b58a;
P_0c07b58a: /* original f32d, guest PC 0x0c07b58a */
if(!s->budget--) { s->failed_pc=0x0c07b58au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b58c;
P_0c07b58c: /* original f433, guest PC 0x0c07b58c */
if(!s->budget--) { s->failed_pc=0x0c07b58cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c07b58e;
P_0c07b58e: /* original f34a, guest PC 0x0c07b58e */
if(!s->budget--) { s->failed_pc=0x0c07b58eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c07b590;
P_0c07b590: /* original 7304, guest PC 0x0c07b590 */
if(!s->budget--) { s->failed_pc=0x0c07b590u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b592;
P_0c07b592: /* original f318, guest PC 0x0c07b592 */
if(!s->budget--) { s->failed_pc=0x0c07b592u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c07b594;
P_0c07b594: /* original f228, guest PC 0x0c07b594 */
if(!s->budget--) { s->failed_pc=0x0c07b594u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c07b596;
P_0c07b596: /* original f232, guest PC 0x0c07b596 */
if(!s->budget--) { s->failed_pc=0x0c07b596u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b598;
P_0c07b598: /* original f32a, guest PC 0x0c07b598 */
if(!s->budget--) { s->failed_pc=0x0c07b598u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b59a;
P_0c07b59a: /* original d014, guest PC 0x0c07b59a */
if(!s->budget--) { s->failed_pc=0x0c07b59au; return 0; }
r[0]=read(ram,0x0c07b5ecu,4);
goto P_0c07b59c;
P_0c07b59c: /* original 720c, guest PC 0x0c07b59c */
if(!s->budget--) { s->failed_pc=0x0c07b59cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c07b59e;
P_0c07b59e: /* original f328, guest PC 0x0c07b59e */
if(!s->budget--) { s->failed_pc=0x0c07b59eu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07b5a0;
P_0c07b5a0: /* original 7304, guest PC 0x0c07b5a0 */
if(!s->budget--) { s->failed_pc=0x0c07b5a0u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b5a2;
P_0c07b5a2: /* original f208, guest PC 0x0c07b5a2 */
if(!s->budget--) { s->failed_pc=0x0c07b5a2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b5a4;
P_0c07b5a4: /* original 70f4, guest PC 0x0c07b5a4 */
if(!s->budget--) { s->failed_pc=0x0c07b5a4u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c07b5a6;
P_0c07b5a6: /* original f232, guest PC 0x0c07b5a6 */
if(!s->budget--) { s->failed_pc=0x0c07b5a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b5a8;
P_0c07b5a8: /* original f32a, guest PC 0x0c07b5a8 */
if(!s->budget--) { s->failed_pc=0x0c07b5a8u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b5aa;
P_0c07b5aa: /* original 6df6, guest PC 0x0c07b5aa */
if(!s->budget--) { s->failed_pc=0x0c07b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b5ac;
P_0c07b5ac: /* original 000b, guest PC 0x0c07b5ac */
if(!s->budget--) { s->failed_pc=0x0c07b5acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b5ae: /* original 6ef6, guest PC 0x0c07b5ae */
if(!s->budget--) { s->failed_pc=0x0c07b5aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07b5b0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
