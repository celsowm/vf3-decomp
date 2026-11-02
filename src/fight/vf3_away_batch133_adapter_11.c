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
int vf3_away_batch133_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f036u: goto P_0c09f036;
case 0x0c09f038u: goto P_0c09f038;
case 0x0c09f03au: goto P_0c09f03a;
case 0x0c09f03cu: goto P_0c09f03c;
case 0x0c09f03eu: goto P_0c09f03e;
case 0x0c09f040u: goto P_0c09f040;
case 0x0c09f042u: goto P_0c09f042;
case 0x0c09f044u: goto P_0c09f044;
case 0x0c09f046u: goto P_0c09f046;
case 0x0c09f432u: goto P_0c09f432;
case 0x0c09f434u: goto P_0c09f434;
case 0x0c09f436u: goto P_0c09f436;
case 0x0c09f438u: goto P_0c09f438;
case 0x0c09f43au: goto P_0c09f43a;
case 0x0c09f43cu: goto P_0c09f43c;
case 0x0c09f43eu: goto P_0c09f43e;
case 0x0c09f440u: goto P_0c09f440;
case 0x0c09f442u: goto P_0c09f442;
case 0x0c09f444u: goto P_0c09f444;
case 0x0c09f446u: goto P_0c09f446;
case 0x0c09f448u: goto P_0c09f448;
case 0x0c09f44au: goto P_0c09f44a;
case 0x0c09f44cu: goto P_0c09f44c;
case 0x0c09f44eu: goto P_0c09f44e;
case 0x0c09f450u: goto P_0c09f450;
case 0x0c09f452u: goto P_0c09f452;
case 0x0c09f454u: goto P_0c09f454;
case 0x0c09f456u: goto P_0c09f456;
case 0x0c09f458u: goto P_0c09f458;
case 0x0c09f45au: goto P_0c09f45a;
case 0x0c09f45cu: goto P_0c09f45c;
case 0x0c09f45eu: goto P_0c09f45e;
case 0x0c09f460u: goto P_0c09f460;
case 0x0c09f462u: goto P_0c09f462;
case 0x0c09f464u: goto P_0c09f464;
case 0x0c09f466u: goto P_0c09f466;
case 0x0c09f468u: goto P_0c09f468;
case 0x0c09f46au: goto P_0c09f46a;
case 0x0c09f46cu: goto P_0c09f46c;
case 0x0c09f46eu: goto P_0c09f46e;
case 0x0c09f470u: goto P_0c09f470;
case 0x0c09f472u: goto P_0c09f472;
case 0x0c09f474u: goto P_0c09f474;
case 0x0c09f476u: goto P_0c09f476;
case 0x0c09f478u: goto P_0c09f478;
case 0x0c09f47au: goto P_0c09f47a;
case 0x0c09f47cu: goto P_0c09f47c;
case 0x0c09f47eu: goto P_0c09f47e;
case 0x0c09f480u: goto P_0c09f480;
case 0x0c09f482u: goto P_0c09f482;
case 0x0c09f484u: goto P_0c09f484;
case 0x0c09f486u: goto P_0c09f486;
case 0x0c09f488u: goto P_0c09f488;
case 0x0c09f48au: goto P_0c09f48a;
case 0x0c09f48cu: goto P_0c09f48c;
case 0x0c09f48eu: goto P_0c09f48e;
case 0x0c09f490u: goto P_0c09f490;
case 0x0c09f492u: goto P_0c09f492;
case 0x0c09f494u: goto P_0c09f494;
case 0x0c09f496u: goto P_0c09f496;
case 0x0c09f498u: goto P_0c09f498;
case 0x0c09f49au: goto P_0c09f49a;
case 0x0c09f49cu: goto P_0c09f49c;
case 0x0c09f49eu: goto P_0c09f49e;
case 0x0c09f4a0u: goto P_0c09f4a0;
case 0x0c09f4a2u: goto P_0c09f4a2;
case 0x0c09f4a4u: goto P_0c09f4a4;
case 0x0c09f4a6u: goto P_0c09f4a6;
case 0x0c09f4a8u: goto P_0c09f4a8;
case 0x0c09f4aau: goto P_0c09f4aa;
case 0x0c09f4acu: goto P_0c09f4ac;
case 0x0c09f4aeu: goto P_0c09f4ae;
case 0x0c09f4b0u: goto P_0c09f4b0;
case 0x0c09f4b2u: goto P_0c09f4b2;
case 0x0c09f4b4u: goto P_0c09f4b4;
case 0x0c09f4b6u: goto P_0c09f4b6;
case 0x0c09f4b8u: goto P_0c09f4b8;
case 0x0c09f4bau: goto P_0c09f4ba;
case 0x0c09f4bcu: goto P_0c09f4bc;
case 0x0c09f4beu: goto P_0c09f4be;
case 0x0c09f4c0u: goto P_0c09f4c0;
case 0x0c09f4c2u: goto P_0c09f4c2;
case 0x0c09f4c4u: goto P_0c09f4c4;
case 0x0c09f4c6u: goto P_0c09f4c6;
case 0x0c09f4c8u: goto P_0c09f4c8;
case 0x0c09f4cau: goto P_0c09f4ca;
case 0x0c09f4ccu: goto P_0c09f4cc;
case 0x0c09f4ceu: goto P_0c09f4ce;
case 0x0c09f4d0u: goto P_0c09f4d0;
case 0x0c09f4d2u: goto P_0c09f4d2;
case 0x0c09f4d4u: goto P_0c09f4d4;
case 0x0c09f4d6u: goto P_0c09f4d6;
case 0x0c09f4d8u: goto P_0c09f4d8;
case 0x0c09f4dau: goto P_0c09f4da;
case 0x0c09f4dcu: goto P_0c09f4dc;
case 0x0c09f4deu: goto P_0c09f4de;
case 0x0c09f4e0u: goto P_0c09f4e0;
case 0x0c09f4e2u: goto P_0c09f4e2;
case 0x0c09f4e4u: goto P_0c09f4e4;
case 0x0c09f500u: goto P_0c09f500;
case 0x0c09f502u: goto P_0c09f502;
case 0x0c09f504u: goto P_0c09f504;
case 0x0c09f506u: goto P_0c09f506;
case 0x0c09f508u: goto P_0c09f508;
case 0x0c09f50au: goto P_0c09f50a;
case 0x0c09f50cu: goto P_0c09f50c;
case 0x0c09f50eu: goto P_0c09f50e;
case 0x0c09f510u: goto P_0c09f510;
case 0x0c09f512u: goto P_0c09f512;
case 0x0c09f514u: goto P_0c09f514;
case 0x0c09f516u: goto P_0c09f516;
case 0x0c09f518u: goto P_0c09f518;
case 0x0c09f51au: goto P_0c09f51a;
case 0x0c09f51cu: goto P_0c09f51c;
case 0x0c09f51eu: goto P_0c09f51e;
case 0x0c09f520u: goto P_0c09f520;
case 0x0c09f522u: goto P_0c09f522;
case 0x0c09f524u: goto P_0c09f524;
case 0x0c09f526u: goto P_0c09f526;
case 0x0c09f528u: goto P_0c09f528;
case 0x0c09f52au: goto P_0c09f52a;
case 0x0c09f52cu: goto P_0c09f52c;
case 0x0c09f52eu: goto P_0c09f52e;
case 0x0c09f530u: goto P_0c09f530;
case 0x0c09f532u: goto P_0c09f532;
case 0x0c09f534u: goto P_0c09f534;
case 0x0c09f536u: goto P_0c09f536;
case 0x0c09f538u: goto P_0c09f538;
case 0x0c09f53au: goto P_0c09f53a;
case 0x0c09f53cu: goto P_0c09f53c;
case 0x0c09f53eu: goto P_0c09f53e;
case 0x0c09f540u: goto P_0c09f540;
case 0x0c09f542u: goto P_0c09f542;
case 0x0c09f544u: goto P_0c09f544;
case 0x0c09f546u: goto P_0c09f546;
case 0x0c09f548u: goto P_0c09f548;
case 0x0c09f54au: goto P_0c09f54a;
case 0x0c09f54cu: goto P_0c09f54c;
case 0x0c09f54eu: goto P_0c09f54e;
case 0x0c09f550u: goto P_0c09f550;
case 0x0c09f552u: goto P_0c09f552;
case 0x0c09f554u: goto P_0c09f554;
case 0x0c09f556u: goto P_0c09f556;
case 0x0c09f558u: goto P_0c09f558;
case 0x0c09f55au: goto P_0c09f55a;
case 0x0c09f55cu: goto P_0c09f55c;
case 0x0c09f55eu: goto P_0c09f55e;
case 0x0c09f560u: goto P_0c09f560;
case 0x0c09f562u: goto P_0c09f562;
case 0x0c09f564u: goto P_0c09f564;
case 0x0c09f566u: goto P_0c09f566;
case 0x0c09f568u: goto P_0c09f568;
case 0x0c09f56au: goto P_0c09f56a;
case 0x0c09f56cu: goto P_0c09f56c;
case 0x0c09f56eu: goto P_0c09f56e;
case 0x0c09f570u: goto P_0c09f570;
case 0x0c09f572u: goto P_0c09f572;
case 0x0c09f574u: goto P_0c09f574;
case 0x0c09f576u: goto P_0c09f576;
case 0x0c09f578u: goto P_0c09f578;
case 0x0c09f57au: goto P_0c09f57a;
case 0x0c09f57cu: goto P_0c09f57c;
case 0x0c09f57eu: goto P_0c09f57e;
case 0x0c09f580u: goto P_0c09f580;
case 0x0c09f582u: goto P_0c09f582;
case 0x0c09f584u: goto P_0c09f584;
case 0x0c09f586u: goto P_0c09f586;
case 0x0c09f588u: goto P_0c09f588;
case 0x0c09f58au: goto P_0c09f58a;
case 0x0c09f58cu: goto P_0c09f58c;
case 0x0c09f58eu: goto P_0c09f58e;
case 0x0c09f590u: goto P_0c09f590;
case 0x0c09f592u: goto P_0c09f592;
case 0x0c09f594u: goto P_0c09f594;
case 0x0c09f596u: goto P_0c09f596;
case 0x0c09f598u: goto P_0c09f598;
case 0x0c09f59au: goto P_0c09f59a;
case 0x0c09f59cu: goto P_0c09f59c;
case 0x0c09f59eu: goto P_0c09f59e;
case 0x0c09f5a0u: goto P_0c09f5a0;
case 0x0c09f5a2u: goto P_0c09f5a2;
case 0x0c09f5a4u: goto P_0c09f5a4;
case 0x0c09f5a6u: goto P_0c09f5a6;
case 0x0c09f5a8u: goto P_0c09f5a8;
case 0x0c09f5aau: goto P_0c09f5aa;
case 0x0c09f5acu: goto P_0c09f5ac;
case 0x0c09f5aeu: goto P_0c09f5ae;
case 0x0c09f5b0u: goto P_0c09f5b0;
case 0x0c09f5b2u: goto P_0c09f5b2;
case 0x0c09f5b4u: goto P_0c09f5b4;
case 0x0c09f5b6u: goto P_0c09f5b6;
case 0x0c09f5b8u: goto P_0c09f5b8;
case 0x0c09f5bau: goto P_0c09f5ba;
case 0x0c09f5bcu: goto P_0c09f5bc;
case 0x0c09f5beu: goto P_0c09f5be;
case 0x0c09f5c0u: goto P_0c09f5c0;
case 0x0c09f5c2u: goto P_0c09f5c2;
case 0x0c09f5c4u: goto P_0c09f5c4;
case 0x0c09f5c6u: goto P_0c09f5c6;
case 0x0c09f5c8u: goto P_0c09f5c8;
case 0x0c09f5cau: goto P_0c09f5ca;
case 0x0c09f5ccu: goto P_0c09f5cc;
case 0x0c09f5ceu: goto P_0c09f5ce;
case 0x0c09f5d0u: goto P_0c09f5d0;
case 0x0c09f5d2u: goto P_0c09f5d2;
case 0x0c09f5d4u: goto P_0c09f5d4;
case 0x0c09f5d6u: goto P_0c09f5d6;
case 0x0c09f5d8u: goto P_0c09f5d8;
case 0x0c09f5dau: goto P_0c09f5da;
case 0x0c09f5dcu: goto P_0c09f5dc;
case 0x0c09f5deu: goto P_0c09f5de;
case 0x0c09f5e0u: goto P_0c09f5e0;
case 0x0c09f5e2u: goto P_0c09f5e2;
case 0x0c09f5e4u: goto P_0c09f5e4;
case 0x0c09f5e6u: goto P_0c09f5e6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f036: /* original 4f22, guest PC 0x0c09f036 */
if(!s->budget--) { s->failed_pc=0x0c09f036u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f038;
P_0c09f038: /* original 7ffc, guest PC 0x0c09f038 */
if(!s->budget--) { s->failed_pc=0x0c09f038u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09f03a;
P_0c09f03a: /* original bfd4, guest PC 0x0c09f03a */
if(!s->budget--) { s->failed_pc=0x0c09f03au; return 0; }
target=code_base|0x0c09efe6u; r[16]=code_base|0x0c09f03eu;
write(ram,r[15],r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f03eu) { target=s->pc; goto dispatch; }
goto P_0c09f03e;
P_0c09f03c: /* original 2f42, guest PC 0x0c09f03c */
if(!s->budget--) { s->failed_pc=0x0c09f03cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09f03e;
P_0c09f03e: /* original 64f2, guest PC 0x0c09f03e */
if(!s->budget--) { s->failed_pc=0x0c09f03eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09f040;
P_0c09f040: /* original 7f04, guest PC 0x0c09f040 */
if(!s->budget--) { s->failed_pc=0x0c09f040u; return 0; }
r[15]+=0x00000004u;
goto P_0c09f042;
P_0c09f042: /* original 6503, guest PC 0x0c09f042 */
if(!s->budget--) { s->failed_pc=0x0c09f042u; return 0; }
r[5]=r[0];
goto P_0c09f044;
P_0c09f044: /* original aee8, guest PC 0x0c09f044 */
if(!s->budget--) { s->failed_pc=0x0c09f044u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c09ee18u,s,ram);
P_0c09f046: /* original 4f26, guest PC 0x0c09f046 */
if(!s->budget--) { s->failed_pc=0x0c09f046u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c09f048u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f048u; return 0; } return 1;
P_0c09f432: /* original 2fe6, guest PC 0x0c09f432 */
if(!s->budget--) { s->failed_pc=0x0c09f432u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f434;
P_0c09f434: /* original c72d, guest PC 0x0c09f434 */
if(!s->budget--) { s->failed_pc=0x0c09f434u; return 0; }
r[0]=code_base|0x0009f4ecu;
goto P_0c09f436;
P_0c09f436: /* original fffb, guest PC 0x0c09f436 */
if(!s->budget--) { s->failed_pc=0x0c09f436u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09f438;
P_0c09f438: /* original 6e43, guest PC 0x0c09f438 */
if(!s->budget--) { s->failed_pc=0x0c09f438u; return 0; }
r[14]=r[4];
goto P_0c09f43a;
P_0c09f43a: /* original ffeb, guest PC 0x0c09f43a */
if(!s->budget--) { s->failed_pc=0x0c09f43au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09f43c;
P_0c09f43c: /* original ffdb, guest PC 0x0c09f43c */
if(!s->budget--) { s->failed_pc=0x0c09f43cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09f43e;
P_0c09f43e: /* original ffcb, guest PC 0x0c09f43e */
if(!s->budget--) { s->failed_pc=0x0c09f43eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c09f440;
P_0c09f440: /* original 4f22, guest PC 0x0c09f440 */
if(!s->budget--) { s->failed_pc=0x0c09f440u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f442;
P_0c09f442: /* original f308, guest PC 0x0c09f442 */
if(!s->budget--) { s->failed_pc=0x0c09f442u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09f444;
P_0c09f444: /* original c72a, guest PC 0x0c09f444 */
if(!s->budget--) { s->failed_pc=0x0c09f444u; return 0; }
r[0]=code_base|0x0009f4f0u;
goto P_0c09f446;
P_0c09f446: /* original 944e, guest PC 0x0c09f446 */
if(!s->budget--) { s->failed_pc=0x0c09f446u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4e6u,2);
goto P_0c09f448;
P_0c09f448: /* original 7ff4, guest PC 0x0c09f448 */
if(!s->budget--) { s->failed_pc=0x0c09f448u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f44a;
P_0c09f44a: /* original ff3a, guest PC 0x0c09f44a */
if(!s->budget--) { s->failed_pc=0x0c09f44au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f44c;
P_0c09f44c: /* original 34ec, guest PC 0x0c09f44c */
if(!s->budget--) { s->failed_pc=0x0c09f44cu; return 0; }
r[4]+=r[14];
goto P_0c09f44e;
P_0c09f44e: /* original ff08, guest PC 0x0c09f44e */
if(!s->budget--) { s->failed_pc=0x0c09f44eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09f450;
P_0c09f450: /* original c728, guest PC 0x0c09f450 */
if(!s->budget--) { s->failed_pc=0x0c09f450u; return 0; }
r[0]=code_base|0x0009f4f4u;
goto P_0c09f452;
P_0c09f452: /* original f308, guest PC 0x0c09f452 */
if(!s->budget--) { s->failed_pc=0x0c09f452u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09f454;
P_0c09f454: /* original e004, guest PC 0x0c09f454 */
if(!s->budget--) { s->failed_pc=0x0c09f454u; return 0; }
r[0]=0x00000004u;
goto P_0c09f456;
P_0c09f456: /* original ff37, guest PC 0x0c09f456 */
if(!s->budget--) { s->failed_pc=0x0c09f456u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f458;
P_0c09f458: /* original c727, guest PC 0x0c09f458 */
if(!s->budget--) { s->failed_pc=0x0c09f458u; return 0; }
r[0]=code_base|0x0009f4f8u;
goto P_0c09f45a;
P_0c09f45a: /* original fc08, guest PC 0x0c09f45a */
if(!s->budget--) { s->failed_pc=0x0c09f45au; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c09f45c;
P_0c09f45c: /* original c727, guest PC 0x0c09f45c */
if(!s->budget--) { s->failed_pc=0x0c09f45cu; return 0; }
r[0]=code_base|0x0009f4fcu;
goto P_0c09f45e;
P_0c09f45e: /* original fe08, guest PC 0x0c09f45e */
if(!s->budget--) { s->failed_pc=0x0c09f45eu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c09f460;
P_0c09f460: /* original f5f8, guest PC 0x0c09f460 */
if(!s->budget--) { s->failed_pc=0x0c09f460u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f462;
P_0c09f462: /* original fd8d, guest PC 0x0c09f462 */
if(!s->budget--) { s->failed_pc=0x0c09f462u; return 0; }
fr[13]=0;
goto P_0c09f464;
P_0c09f464: /* original f7cc, guest PC 0x0c09f464 */
if(!s->budget--) { s->failed_pc=0x0c09f464u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f466;
P_0c09f466: /* original f63c, guest PC 0x0c09f466 */
if(!s->budget--) { s->failed_pc=0x0c09f466u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c09f468;
P_0c09f468: /* original f9ec, guest PC 0x0c09f468 */
if(!s->budget--) { s->failed_pc=0x0c09f468u; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f46a;
P_0c09f46a: /* original f8dc, guest PC 0x0c09f46a */
if(!s->budget--) { s->failed_pc=0x0c09f46au; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f46c;
P_0c09f46c: /* original b0c4, guest PC 0x0c09f46c */
if(!s->budget--) { s->failed_pc=0x0c09f46cu; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f470u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f470u) { target=s->pc; goto dispatch; }
goto P_0c09f470;
P_0c09f46e: /* original f4fc, guest PC 0x0c09f46e */
if(!s->budget--) { s->failed_pc=0x0c09f46eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f470;
P_0c09f470: /* original 6403, guest PC 0x0c09f470 */
if(!s->budget--) { s->failed_pc=0x0c09f470u; return 0; }
r[4]=r[0];
goto P_0c09f472;
P_0c09f472: /* original e004, guest PC 0x0c09f472 */
if(!s->budget--) { s->failed_pc=0x0c09f472u; return 0; }
r[0]=0x00000004u;
goto P_0c09f474;
P_0c09f474: /* original f6f6, guest PC 0x0c09f474 */
if(!s->budget--) { s->failed_pc=0x0c09f474u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f476;
P_0c09f476: /* original f5f8, guest PC 0x0c09f476 */
if(!s->budget--) { s->failed_pc=0x0c09f476u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f478;
P_0c09f478: /* original f9ec, guest PC 0x0c09f478 */
if(!s->budget--) { s->failed_pc=0x0c09f478u; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f47a;
P_0c09f47a: /* original f8dc, guest PC 0x0c09f47a */
if(!s->budget--) { s->failed_pc=0x0c09f47au; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f47c;
P_0c09f47c: /* original f7cc, guest PC 0x0c09f47c */
if(!s->budget--) { s->failed_pc=0x0c09f47cu; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f47e;
P_0c09f47e: /* original b0bb, guest PC 0x0c09f47e */
if(!s->budget--) { s->failed_pc=0x0c09f47eu; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f482u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f482u) { target=s->pc; goto dispatch; }
goto P_0c09f482;
P_0c09f480: /* original f4fc, guest PC 0x0c09f480 */
if(!s->budget--) { s->failed_pc=0x0c09f480u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f482;
P_0c09f482: /* original 6403, guest PC 0x0c09f482 */
if(!s->budget--) { s->failed_pc=0x0c09f482u; return 0; }
r[4]=r[0];
goto P_0c09f484;
P_0c09f484: /* original e004, guest PC 0x0c09f484 */
if(!s->budget--) { s->failed_pc=0x0c09f484u; return 0; }
r[0]=0x00000004u;
goto P_0c09f486;
P_0c09f486: /* original f6f6, guest PC 0x0c09f486 */
if(!s->budget--) { s->failed_pc=0x0c09f486u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f488;
P_0c09f488: /* original 7454, guest PC 0x0c09f488 */
if(!s->budget--) { s->failed_pc=0x0c09f488u; return 0; }
r[4]+=0x00000054u;
goto P_0c09f48a;
P_0c09f48a: /* original f5f8, guest PC 0x0c09f48a */
if(!s->budget--) { s->failed_pc=0x0c09f48au; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f48c;
P_0c09f48c: /* original f7cc, guest PC 0x0c09f48c */
if(!s->budget--) { s->failed_pc=0x0c09f48cu; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f48e;
P_0c09f48e: /* original f9ec, guest PC 0x0c09f48e */
if(!s->budget--) { s->failed_pc=0x0c09f48eu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f490;
P_0c09f490: /* original f8dc, guest PC 0x0c09f490 */
if(!s->budget--) { s->failed_pc=0x0c09f490u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f492;
P_0c09f492: /* original b0b1, guest PC 0x0c09f492 */
if(!s->budget--) { s->failed_pc=0x0c09f492u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f496u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f496u) { target=s->pc; goto dispatch; }
goto P_0c09f496;
P_0c09f494: /* original f4fc, guest PC 0x0c09f494 */
if(!s->budget--) { s->failed_pc=0x0c09f494u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f496;
P_0c09f496: /* original 6403, guest PC 0x0c09f496 */
if(!s->budget--) { s->failed_pc=0x0c09f496u; return 0; }
r[4]=r[0];
goto P_0c09f498;
P_0c09f498: /* original e004, guest PC 0x0c09f498 */
if(!s->budget--) { s->failed_pc=0x0c09f498u; return 0; }
r[0]=0x00000004u;
goto P_0c09f49a;
P_0c09f49a: /* original f6f6, guest PC 0x0c09f49a */
if(!s->budget--) { s->failed_pc=0x0c09f49au; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f49c;
P_0c09f49c: /* original f5f8, guest PC 0x0c09f49c */
if(!s->budget--) { s->failed_pc=0x0c09f49cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f49e;
P_0c09f49e: /* original f9ec, guest PC 0x0c09f49e */
if(!s->budget--) { s->failed_pc=0x0c09f49eu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f4a0;
P_0c09f4a0: /* original f8dc, guest PC 0x0c09f4a0 */
if(!s->budget--) { s->failed_pc=0x0c09f4a0u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f4a2;
P_0c09f4a2: /* original f7cc, guest PC 0x0c09f4a2 */
if(!s->budget--) { s->failed_pc=0x0c09f4a2u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f4a4;
P_0c09f4a4: /* original b0a8, guest PC 0x0c09f4a4 */
if(!s->budget--) { s->failed_pc=0x0c09f4a4u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f4a8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4a8u) { target=s->pc; goto dispatch; }
goto P_0c09f4a8;
P_0c09f4a6: /* original f4fc, guest PC 0x0c09f4a6 */
if(!s->budget--) { s->failed_pc=0x0c09f4a6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f4a8;
P_0c09f4a8: /* original 921e, guest PC 0x0c09f4a8 */
if(!s->budget--) { s->failed_pc=0x0c09f4a8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4e8u,2);
goto P_0c09f4aa;
P_0c09f4aa: /* original 6503, guest PC 0x0c09f4aa */
if(!s->budget--) { s->failed_pc=0x0c09f4aau; return 0; }
r[5]=r[0];
goto P_0c09f4ac;
P_0c09f4ac: /* original 32ec, guest PC 0x0c09f4ac */
if(!s->budget--) { s->failed_pc=0x0c09f4acu; return 0; }
r[2]+=r[14];
goto P_0c09f4ae;
P_0c09f4ae: /* original 6623, guest PC 0x0c09f4ae */
if(!s->budget--) { s->failed_pc=0x0c09f4aeu; return 0; }
r[6]=r[2];
goto P_0c09f4b0;
P_0c09f4b0: /* original 1f22, guest PC 0x0c09f4b0 */
if(!s->budget--) { s->failed_pc=0x0c09f4b0u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09f4b2;
P_0c09f4b2: /* original b025, guest PC 0x0c09f4b2 */
if(!s->budget--) { s->failed_pc=0x0c09f4b2u; return 0; }
target=code_base|0x0c09f500u; r[16]=code_base|0x0c09f4b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4b6u) { target=s->pc; goto dispatch; }
goto P_0c09f4b6;
P_0c09f4b4: /* original 64e3, guest PC 0x0c09f4b4 */
if(!s->budget--) { s->failed_pc=0x0c09f4b4u; return 0; }
r[4]=r[14];
goto P_0c09f4b6;
P_0c09f4b6: /* original 6403, guest PC 0x0c09f4b6 */
if(!s->budget--) { s->failed_pc=0x0c09f4b6u; return 0; }
r[4]=r[0];
goto P_0c09f4b8;
P_0c09f4b8: /* original e004, guest PC 0x0c09f4b8 */
if(!s->budget--) { s->failed_pc=0x0c09f4b8u; return 0; }
r[0]=0x00000004u;
goto P_0c09f4ba;
P_0c09f4ba: /* original f6f6, guest PC 0x0c09f4ba */
if(!s->budget--) { s->failed_pc=0x0c09f4bau; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f4bc;
P_0c09f4bc: /* original f5f8, guest PC 0x0c09f4bc */
if(!s->budget--) { s->failed_pc=0x0c09f4bcu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f4be;
P_0c09f4be: /* original f9ec, guest PC 0x0c09f4be */
if(!s->budget--) { s->failed_pc=0x0c09f4beu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f4c0;
P_0c09f4c0: /* original f8dc, guest PC 0x0c09f4c0 */
if(!s->budget--) { s->failed_pc=0x0c09f4c0u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f4c2;
P_0c09f4c2: /* original f7cc, guest PC 0x0c09f4c2 */
if(!s->budget--) { s->failed_pc=0x0c09f4c2u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f4c4;
P_0c09f4c4: /* original b098, guest PC 0x0c09f4c4 */
if(!s->budget--) { s->failed_pc=0x0c09f4c4u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f4c8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4c8u) { target=s->pc; goto dispatch; }
goto P_0c09f4c8;
P_0c09f4c6: /* original f4fc, guest PC 0x0c09f4c6 */
if(!s->budget--) { s->failed_pc=0x0c09f4c6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f4c8;
P_0c09f4c8: /* original 920f, guest PC 0x0c09f4c8 */
if(!s->budget--) { s->failed_pc=0x0c09f4c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4eau,2);
goto P_0c09f4ca;
P_0c09f4ca: /* original 6503, guest PC 0x0c09f4ca */
if(!s->budget--) { s->failed_pc=0x0c09f4cau; return 0; }
r[5]=r[0];
goto P_0c09f4cc;
P_0c09f4cc: /* original 32ec, guest PC 0x0c09f4cc */
if(!s->budget--) { s->failed_pc=0x0c09f4ccu; return 0; }
r[2]+=r[14];
goto P_0c09f4ce;
P_0c09f4ce: /* original 6623, guest PC 0x0c09f4ce */
if(!s->budget--) { s->failed_pc=0x0c09f4ceu; return 0; }
r[6]=r[2];
goto P_0c09f4d0;
P_0c09f4d0: /* original 1f22, guest PC 0x0c09f4d0 */
if(!s->budget--) { s->failed_pc=0x0c09f4d0u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09f4d2;
P_0c09f4d2: /* original b015, guest PC 0x0c09f4d2 */
if(!s->budget--) { s->failed_pc=0x0c09f4d2u; return 0; }
target=code_base|0x0c09f500u; r[16]=code_base|0x0c09f4d6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4d6u) { target=s->pc; goto dispatch; }
goto P_0c09f4d6;
P_0c09f4d4: /* original 64e3, guest PC 0x0c09f4d4 */
if(!s->budget--) { s->failed_pc=0x0c09f4d4u; return 0; }
r[4]=r[14];
goto P_0c09f4d6;
P_0c09f4d6: /* original 7f0c, guest PC 0x0c09f4d6 */
if(!s->budget--) { s->failed_pc=0x0c09f4d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f4d8;
P_0c09f4d8: /* original 4f26, guest PC 0x0c09f4d8 */
if(!s->budget--) { s->failed_pc=0x0c09f4d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f4da;
P_0c09f4da: /* original fcf9, guest PC 0x0c09f4da */
if(!s->budget--) { s->failed_pc=0x0c09f4dau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4dc;
P_0c09f4dc: /* original fdf9, guest PC 0x0c09f4dc */
if(!s->budget--) { s->failed_pc=0x0c09f4dcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4de;
P_0c09f4de: /* original fef9, guest PC 0x0c09f4de */
if(!s->budget--) { s->failed_pc=0x0c09f4deu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4e0;
P_0c09f4e0: /* original fff9, guest PC 0x0c09f4e0 */
if(!s->budget--) { s->failed_pc=0x0c09f4e0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4e2;
P_0c09f4e2: /* original 000b, guest PC 0x0c09f4e2 */
if(!s->budget--) { s->failed_pc=0x0c09f4e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f4e4: /* original 6ef6, guest PC 0x0c09f4e4 */
if(!s->budget--) { s->failed_pc=0x0c09f4e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f4e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f4e6u; return 0; } return 1;
P_0c09f500: /* original 2fe6, guest PC 0x0c09f500 */
if(!s->budget--) { s->failed_pc=0x0c09f500u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f502;
P_0c09f502: /* original 6353, guest PC 0x0c09f502 */
if(!s->budget--) { s->failed_pc=0x0c09f502u; return 0; }
r[3]=r[5];
goto P_0c09f504;
P_0c09f504: /* original 2fd6, guest PC 0x0c09f504 */
if(!s->budget--) { s->failed_pc=0x0c09f504u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f506;
P_0c09f506: /* original 7304, guest PC 0x0c09f506 */
if(!s->budget--) { s->failed_pc=0x0c09f506u; return 0; }
r[3]+=0x00000004u;
goto P_0c09f508;
P_0c09f508: /* original 2fc6, guest PC 0x0c09f508 */
if(!s->budget--) { s->failed_pc=0x0c09f508u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f50a;
P_0c09f50a: /* original 6c53, guest PC 0x0c09f50a */
if(!s->budget--) { s->failed_pc=0x0c09f50au; return 0; }
r[12]=r[5];
goto P_0c09f50c;
P_0c09f50c: /* original 62c3, guest PC 0x0c09f50c */
if(!s->budget--) { s->failed_pc=0x0c09f50cu; return 0; }
r[2]=r[12];
goto P_0c09f50e;
P_0c09f50e: /* original 7208, guest PC 0x0c09f50e */
if(!s->budget--) { s->failed_pc=0x0c09f50eu; return 0; }
r[2]+=0x00000008u;
goto P_0c09f510;
P_0c09f510: /* original 2fb6, guest PC 0x0c09f510 */
if(!s->budget--) { s->failed_pc=0x0c09f510u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f512;
P_0c09f512: /* original 2fa6, guest PC 0x0c09f512 */
if(!s->budget--) { s->failed_pc=0x0c09f512u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f514;
P_0c09f514: /* original 2f96, guest PC 0x0c09f514 */
if(!s->budget--) { s->failed_pc=0x0c09f514u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f516;
P_0c09f516: /* original 2f86, guest PC 0x0c09f516 */
if(!s->budget--) { s->failed_pc=0x0c09f516u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f518;
P_0c09f518: /* original f6c8, guest PC 0x0c09f518 */
if(!s->budget--) { s->failed_pc=0x0c09f518u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c09f51a;
P_0c09f51a: /* original 7ff4, guest PC 0x0c09f51a */
if(!s->budget--) { s->failed_pc=0x0c09f51au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f51c;
P_0c09f51c: /* original 1f32, guest PC 0x0c09f51c */
if(!s->budget--) { s->failed_pc=0x0c09f51cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c09f51e;
P_0c09f51e: /* original f63d, guest PC 0x0c09f51e */
if(!s->budget--) { s->failed_pc=0x0c09f51eu; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c09f520;
P_0c09f520: /* original f438, guest PC 0x0c09f520 */
if(!s->budget--) { s->failed_pc=0x0c09f520u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c09f522;
P_0c09f522: /* original 1f21, guest PC 0x0c09f522 */
if(!s->budget--) { s->failed_pc=0x0c09f522u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c09f524;
P_0c09f524: /* original f528, guest PC 0x0c09f524 */
if(!s->budget--) { s->failed_pc=0x0c09f524u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
goto P_0c09f526;
P_0c09f526: /* original 075a, guest PC 0x0c09f526 */
if(!s->budget--) { s->failed_pc=0x0c09f526u; return 0; }
r[7]=r[53];
goto P_0c09f528;
P_0c09f528: /* original f43d, guest PC 0x0c09f528 */
if(!s->budget--) { s->failed_pc=0x0c09f528u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c09f52a;
P_0c09f52a: /* original 677d, guest PC 0x0c09f52a */
if(!s->budget--) { s->failed_pc=0x0c09f52au; return 0; }
r[7]=r[7]&65535u;
goto P_0c09f52c;
P_0c09f52c: /* original 0d5a, guest PC 0x0c09f52c */
if(!s->budget--) { s->failed_pc=0x0c09f52cu; return 0; }
r[13]=r[53];
goto P_0c09f52e;
P_0c09f52e: /* original f53d, guest PC 0x0c09f52e */
if(!s->budget--) { s->failed_pc=0x0c09f52eu; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c09f530;
P_0c09f530: /* original 677f, guest PC 0x0c09f530 */
if(!s->budget--) { s->failed_pc=0x0c09f530u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c09f532;
P_0c09f532: /* original 015a, guest PC 0x0c09f532 */
if(!s->budget--) { s->failed_pc=0x0c09f532u; return 0; }
r[1]=r[53];
goto P_0c09f534;
P_0c09f534: /* original 2f12, guest PC 0x0c09f534 */
if(!s->budget--) { s->failed_pc=0x0c09f534u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c09f536;
P_0c09f536: /* original 9357, guest PC 0x0c09f536 */
if(!s->budget--) { s->failed_pc=0x0c09f536u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5e8u,2);
goto P_0c09f538;
P_0c09f538: /* original de2e, guest PC 0x0c09f538 */
if(!s->budget--) { s->failed_pc=0x0c09f538u; return 0; }
r[14]=read(ram,0x0c09f5f4u,4);
goto P_0c09f53a;
P_0c09f53a: /* original 3737, guest PC 0x0c09f53a */
if(!s->budget--) { s->failed_pc=0x0c09f53au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[3])!=0);
goto P_0c09f53c;
P_0c09f53c: /* original 8d03, guest PC 0x0c09f53c */
if(!s->budget--) { s->failed_pc=0x0c09f53cu; return 0; }
cond=r[17]&1u;
r[11]=r[1]&65535u;
if(cond) { goto P_0c09f546; }
goto P_0c09f540;
P_0c09f53e: /* original 6b1d, guest PC 0x0c09f53e */
if(!s->budget--) { s->failed_pc=0x0c09f53eu; return 0; }
r[11]=r[1]&65535u;
goto P_0c09f540;
P_0c09f540: /* original 9053, guest PC 0x0c09f540 */
if(!s->budget--) { s->failed_pc=0x0c09f540u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5eau,2);
goto P_0c09f542;
P_0c09f542: /* original 3703, guest PC 0x0c09f542 */
if(!s->budget--) { s->failed_pc=0x0c09f542u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c09f544;
P_0c09f544: /* original 8904, guest PC 0x0c09f544 */
if(!s->budget--) { s->failed_pc=0x0c09f544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f550; }
goto P_0c09f546;
P_0c09f546: /* original 63e3, guest PC 0x0c09f546 */
if(!s->budget--) { s->failed_pc=0x0c09f546u; return 0; }
r[3]=r[14];
goto P_0c09f548;
P_0c09f548: /* original 33d8, guest PC 0x0c09f548 */
if(!s->budget--) { s->failed_pc=0x0c09f548u; return 0; }
r[3]-=r[13];
goto P_0c09f54a;
P_0c09f54a: /* original 6d33, guest PC 0x0c09f54a */
if(!s->budget--) { s->failed_pc=0x0c09f54au; return 0; }
r[13]=r[3];
goto P_0c09f54c;
P_0c09f54c: /* original 3bec, guest PC 0x0c09f54c */
if(!s->budget--) { s->failed_pc=0x0c09f54cu; return 0; }
r[11]+=r[14];
goto P_0c09f54e;
P_0c09f54e: /* original 37ec, guest PC 0x0c09f54e */
if(!s->budget--) { s->failed_pc=0x0c09f54eu; return 0; }
r[7]+=r[14];
goto P_0c09f550;
P_0c09f550: /* original 677d, guest PC 0x0c09f550 */
if(!s->budget--) { s->failed_pc=0x0c09f550u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09f552;
P_0c09f552: /* original e03e, guest PC 0x0c09f552 */
if(!s->budget--) { s->failed_pc=0x0c09f552u; return 0; }
r[0]=0x0000003eu;
goto P_0c09f554;
P_0c09f554: /* original 697f, guest PC 0x0c09f554 */
if(!s->budget--) { s->failed_pc=0x0c09f554u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c09f556;
P_0c09f556: /* original 6bbd, guest PC 0x0c09f556 */
if(!s->budget--) { s->failed_pc=0x0c09f556u; return 0; }
r[11]=r[11]&65535u;
goto P_0c09f558;
P_0c09f558: /* original 6ebf, guest PC 0x0c09f558 */
if(!s->budget--) { s->failed_pc=0x0c09f558u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c09f55a;
P_0c09f55a: /* original 2fb2, guest PC 0x0c09f55a */
if(!s->budget--) { s->failed_pc=0x0c09f55au; return 0; }
write(ram,r[15],r[11],4);
goto P_0c09f55c;
P_0c09f55c: /* original 074d, guest PC 0x0c09f55c */
if(!s->budget--) { s->failed_pc=0x0c09f55cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f55e;
P_0c09f55e: /* original 9045, guest PC 0x0c09f55e */
if(!s->budget--) { s->failed_pc=0x0c09f55eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5ecu,2);
goto P_0c09f560;
P_0c09f560: /* original 677d, guest PC 0x0c09f560 */
if(!s->budget--) { s->failed_pc=0x0c09f560u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09f562;
P_0c09f562: /* original 0a4d, guest PC 0x0c09f562 */
if(!s->budget--) { s->failed_pc=0x0c09f562u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f564;
P_0c09f564: /* original 70fc, guest PC 0x0c09f564 */
if(!s->budget--) { s->failed_pc=0x0c09f564u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09f566;
P_0c09f566: /* original 084d, guest PC 0x0c09f566 */
if(!s->budget--) { s->failed_pc=0x0c09f566u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f568;
P_0c09f568: /* original 9041, guest PC 0x0c09f568 */
if(!s->budget--) { s->failed_pc=0x0c09f568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5eeu,2);
goto P_0c09f56a;
P_0c09f56a: /* original 6aad, guest PC 0x0c09f56a */
if(!s->budget--) { s->failed_pc=0x0c09f56au; return 0; }
r[10]=r[10]&65535u;
goto P_0c09f56c;
P_0c09f56c: /* original 7a01, guest PC 0x0c09f56c */
if(!s->budget--) { s->failed_pc=0x0c09f56cu; return 0; }
r[10]+=0x00000001u;
goto P_0c09f56e;
P_0c09f56e: /* original 0b4d, guest PC 0x0c09f56e */
if(!s->budget--) { s->failed_pc=0x0c09f56eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f570;
P_0c09f570: /* original 37a0, guest PC 0x0c09f570 */
if(!s->budget--) { s->failed_pc=0x0c09f570u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[10])!=0);
goto P_0c09f572;
P_0c09f572: /* original 7801, guest PC 0x0c09f572 */
if(!s->budget--) { s->failed_pc=0x0c09f572u; return 0; }
r[8]+=0x00000001u;
goto P_0c09f574;
P_0c09f574: /* original 6bbd, guest PC 0x0c09f574 */
if(!s->budget--) { s->failed_pc=0x0c09f574u; return 0; }
r[11]=r[11]&65535u;
goto P_0c09f576;
P_0c09f576: /* original 63b3, guest PC 0x0c09f576 */
if(!s->budget--) { s->failed_pc=0x0c09f576u; return 0; }
r[3]=r[11];
goto P_0c09f578;
P_0c09f578: /* original 73f8, guest PC 0x0c09f578 */
if(!s->budget--) { s->failed_pc=0x0c09f578u; return 0; }
r[3]+=0xfffffff8u;
goto P_0c09f57a;
P_0c09f57a: /* original 2f32, guest PC 0x0c09f57a */
if(!s->budget--) { s->failed_pc=0x0c09f57au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f57c;
P_0c09f57c: /* original 8d02, guest PC 0x0c09f57c */
if(!s->budget--) { s->failed_pc=0x0c09f57cu; return 0; }
cond=r[17]&1u;
r[11]+=0x00000001u;
if(cond) { goto P_0c09f584; }
goto P_0c09f580;
P_0c09f57e: /* original 7b01, guest PC 0x0c09f57e */
if(!s->budget--) { s->failed_pc=0x0c09f57eu; return 0; }
r[11]+=0x00000001u;
goto P_0c09f580;
P_0c09f580: /* original 3730, guest PC 0x0c09f580 */
if(!s->budget--) { s->failed_pc=0x0c09f580u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c09f582;
P_0c09f582: /* original 8b04, guest PC 0x0c09f582 */
if(!s->budget--) { s->failed_pc=0x0c09f582u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f58e; }
goto P_0c09f584;
P_0c09f584: /* original 60d3, guest PC 0x0c09f584 */
if(!s->budget--) { s->failed_pc=0x0c09f584u; return 0; }
r[0]=r[13];
goto P_0c09f586;
P_0c09f586: /* original 2691, guest PC 0x0c09f586 */
if(!s->budget--) { s->failed_pc=0x0c09f586u; return 0; }
write(ram,r[6],r[9],2);
goto P_0c09f588;
P_0c09f588: /* original 8161, guest PC 0x0c09f588 */
if(!s->budget--) { s->failed_pc=0x0c09f588u; return 0; }
write(ram,r[6]+2,r[0],2);
goto P_0c09f58a;
P_0c09f58a: /* original 60e3, guest PC 0x0c09f58a */
if(!s->budget--) { s->failed_pc=0x0c09f58au; return 0; }
r[0]=r[14];
goto P_0c09f58c;
P_0c09f58c: /* original 8162, guest PC 0x0c09f58c */
if(!s->budget--) { s->failed_pc=0x0c09f58cu; return 0; }
write(ram,r[6]+4,r[0],2);
goto P_0c09f58e;
P_0c09f58e: /* original 37a7, guest PC 0x0c09f58e */
if(!s->budget--) { s->failed_pc=0x0c09f58eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[10])!=0);
goto P_0c09f590;
P_0c09f590: /* original 8b01, guest PC 0x0c09f590 */
if(!s->budget--) { s->failed_pc=0x0c09f590u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f596; }
goto P_0c09f592;
P_0c09f592: /* original 3783, guest PC 0x0c09f592 */
if(!s->budget--) { s->failed_pc=0x0c09f592u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[8])!=0);
goto P_0c09f594;
P_0c09f594: /* original 8b04, guest PC 0x0c09f594 */
if(!s->budget--) { s->failed_pc=0x0c09f594u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f5a0; }
goto P_0c09f596;
P_0c09f596: /* original 63f2, guest PC 0x0c09f596 */
if(!s->budget--) { s->failed_pc=0x0c09f596u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09f598;
P_0c09f598: /* original 3737, guest PC 0x0c09f598 */
if(!s->budget--) { s->failed_pc=0x0c09f598u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[3])!=0);
goto P_0c09f59a;
P_0c09f59a: /* original 8b0f, guest PC 0x0c09f59a */
if(!s->budget--) { s->failed_pc=0x0c09f59au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f5bc; }
goto P_0c09f59c;
P_0c09f59c: /* original 37b3, guest PC 0x0c09f59c */
if(!s->budget--) { s->failed_pc=0x0c09f59cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[11])!=0);
goto P_0c09f59e;
P_0c09f59e: /* original 890d, guest PC 0x0c09f59e */
if(!s->budget--) { s->failed_pc=0x0c09f59eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f5bc; }
goto P_0c09f5a0;
P_0c09f5a0: /* original e061, guest PC 0x0c09f5a0 */
if(!s->budget--) { s->failed_pc=0x0c09f5a0u; return 0; }
r[0]=0x00000061u;
goto P_0c09f5a2;
P_0c09f5a2: /* original 004c, guest PC 0x0c09f5a2 */
if(!s->budget--) { s->failed_pc=0x0c09f5a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f5a4;
P_0c09f5a4: /* original 600c, guest PC 0x0c09f5a4 */
if(!s->budget--) { s->failed_pc=0x0c09f5a4u; return 0; }
r[0]=r[0]&255u;
goto P_0c09f5a6;
P_0c09f5a6: /* original 8803, guest PC 0x0c09f5a6 */
if(!s->budget--) { s->failed_pc=0x0c09f5a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09f5a8;
P_0c09f5a8: /* original 8b08, guest PC 0x0c09f5a8 */
if(!s->budget--) { s->failed_pc=0x0c09f5a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f5bc; }
goto P_0c09f5aa;
P_0c09f5aa: /* original 64e3, guest PC 0x0c09f5aa */
if(!s->budget--) { s->failed_pc=0x0c09f5aau; return 0; }
r[4]=r[14];
goto P_0c09f5ac;
P_0c09f5ac: /* original 4411, guest PC 0x0c09f5ac */
if(!s->budget--) { s->failed_pc=0x0c09f5acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c09f5ae;
P_0c09f5ae: /* original 8d01, guest PC 0x0c09f5ae */
if(!s->budget--) { s->failed_pc=0x0c09f5aeu; return 0; }
cond=r[17]&1u;
r[6]=0u-r[14];
if(cond) { goto P_0c09f5b4; }
goto P_0c09f5b2;
P_0c09f5b0: /* original 66eb, guest PC 0x0c09f5b0 */
if(!s->budget--) { s->failed_pc=0x0c09f5b0u; return 0; }
r[6]=0u-r[14];
goto P_0c09f5b2;
P_0c09f5b2: /* original 6463, guest PC 0x0c09f5b2 */
if(!s->budget--) { s->failed_pc=0x0c09f5b2u; return 0; }
r[4]=r[6];
goto P_0c09f5b4;
P_0c09f5b4: /* original 931c, guest PC 0x0c09f5b4 */
if(!s->budget--) { s->failed_pc=0x0c09f5b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f5f0u,2);
goto P_0c09f5b6;
P_0c09f5b6: /* original 3437, guest PC 0x0c09f5b6 */
if(!s->budget--) { s->failed_pc=0x0c09f5b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c09f5b8;
P_0c09f5b8: /* original 8b00, guest PC 0x0c09f5b8 */
if(!s->budget--) { s->failed_pc=0x0c09f5b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f5bc; }
goto P_0c09f5ba;
P_0c09f5ba: /* original 6e63, guest PC 0x0c09f5ba */
if(!s->budget--) { s->failed_pc=0x0c09f5bau; return 0; }
r[14]=r[6];
goto P_0c09f5bc;
P_0c09f5bc: /* original 495a, guest PC 0x0c09f5bc */
if(!s->budget--) { s->failed_pc=0x0c09f5bcu; return 0; }
r[53]=r[9];
goto P_0c09f5be;
P_0c09f5be: /* original 750c, guest PC 0x0c09f5be */
if(!s->budget--) { s->failed_pc=0x0c09f5beu; return 0; }
r[5]+=0x0000000cu;
goto P_0c09f5c0;
P_0c09f5c0: /* original 6053, guest PC 0x0c09f5c0 */
if(!s->budget--) { s->failed_pc=0x0c09f5c0u; return 0; }
r[0]=r[5];
goto P_0c09f5c2;
P_0c09f5c2: /* original f32d, guest PC 0x0c09f5c2 */
if(!s->budget--) { s->failed_pc=0x0c09f5c2u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f5c4;
P_0c09f5c4: /* original fc3a, guest PC 0x0c09f5c4 */
if(!s->budget--) { s->failed_pc=0x0c09f5c4u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c09f5c6;
P_0c09f5c6: /* original 4d5a, guest PC 0x0c09f5c6 */
if(!s->budget--) { s->failed_pc=0x0c09f5c6u; return 0; }
r[53]=r[13];
goto P_0c09f5c8;
P_0c09f5c8: /* original 53f2, guest PC 0x0c09f5c8 */
if(!s->budget--) { s->failed_pc=0x0c09f5c8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f5ca;
P_0c09f5ca: /* original f32d, guest PC 0x0c09f5ca */
if(!s->budget--) { s->failed_pc=0x0c09f5cau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f5cc;
P_0c09f5cc: /* original f33a, guest PC 0x0c09f5cc */
if(!s->budget--) { s->failed_pc=0x0c09f5ccu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c09f5ce;
P_0c09f5ce: /* original 53f1, guest PC 0x0c09f5ce */
if(!s->budget--) { s->failed_pc=0x0c09f5ceu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f5d0;
P_0c09f5d0: /* original 7f0c, guest PC 0x0c09f5d0 */
if(!s->budget--) { s->failed_pc=0x0c09f5d0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f5d2;
P_0c09f5d2: /* original 4e5a, guest PC 0x0c09f5d2 */
if(!s->budget--) { s->failed_pc=0x0c09f5d2u; return 0; }
r[53]=r[14];
goto P_0c09f5d4;
P_0c09f5d4: /* original f32d, guest PC 0x0c09f5d4 */
if(!s->budget--) { s->failed_pc=0x0c09f5d4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f5d6;
P_0c09f5d6: /* original f33a, guest PC 0x0c09f5d6 */
if(!s->budget--) { s->failed_pc=0x0c09f5d6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c09f5d8;
P_0c09f5d8: /* original 68f6, guest PC 0x0c09f5d8 */
if(!s->budget--) { s->failed_pc=0x0c09f5d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09f5da;
P_0c09f5da: /* original 69f6, guest PC 0x0c09f5da */
if(!s->budget--) { s->failed_pc=0x0c09f5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09f5dc;
P_0c09f5dc: /* original 6af6, guest PC 0x0c09f5dc */
if(!s->budget--) { s->failed_pc=0x0c09f5dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09f5de;
P_0c09f5de: /* original 6bf6, guest PC 0x0c09f5de */
if(!s->budget--) { s->failed_pc=0x0c09f5deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09f5e0;
P_0c09f5e0: /* original 6cf6, guest PC 0x0c09f5e0 */
if(!s->budget--) { s->failed_pc=0x0c09f5e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f5e2;
P_0c09f5e2: /* original 6df6, guest PC 0x0c09f5e2 */
if(!s->budget--) { s->failed_pc=0x0c09f5e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f5e4;
P_0c09f5e4: /* original 000b, guest PC 0x0c09f5e4 */
if(!s->budget--) { s->failed_pc=0x0c09f5e4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f5e6: /* original 6ef6, guest PC 0x0c09f5e6 */
if(!s->budget--) { s->failed_pc=0x0c09f5e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f5e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f5e8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
