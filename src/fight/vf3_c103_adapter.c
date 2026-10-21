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
int vf3_c103_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c058348u: goto P_0c058348;
case 0x0c05834au: goto P_0c05834a;
case 0x0c05834cu: goto P_0c05834c;
case 0x0c05834eu: goto P_0c05834e;
case 0x0c058350u: goto P_0c058350;
case 0x0c058352u: goto P_0c058352;
case 0x0c058354u: goto P_0c058354;
case 0x0c058356u: goto P_0c058356;
case 0x0c058358u: goto P_0c058358;
case 0x0c05835au: goto P_0c05835a;
case 0x0c05835cu: goto P_0c05835c;
case 0x0c05835eu: goto P_0c05835e;
case 0x0c058360u: goto P_0c058360;
case 0x0c058362u: goto P_0c058362;
case 0x0c058364u: goto P_0c058364;
case 0x0c058366u: goto P_0c058366;
case 0x0c058368u: goto P_0c058368;
case 0x0c05836au: goto P_0c05836a;
case 0x0c05836cu: goto P_0c05836c;
case 0x0c05836eu: goto P_0c05836e;
case 0x0c058370u: goto P_0c058370;
case 0x0c058372u: goto P_0c058372;
case 0x0c058374u: goto P_0c058374;
case 0x0c058376u: goto P_0c058376;
case 0x0c058378u: goto P_0c058378;
case 0x0c05837au: goto P_0c05837a;
case 0x0c05837cu: goto P_0c05837c;
case 0x0c05837eu: goto P_0c05837e;
case 0x0c058380u: goto P_0c058380;
case 0x0c058382u: goto P_0c058382;
case 0x0c058384u: goto P_0c058384;
case 0x0c058386u: goto P_0c058386;
case 0x0c058388u: goto P_0c058388;
case 0x0c05838au: goto P_0c05838a;
case 0x0c05838cu: goto P_0c05838c;
case 0x0c05838eu: goto P_0c05838e;
case 0x0c058390u: goto P_0c058390;
case 0x0c058392u: goto P_0c058392;
case 0x0c058394u: goto P_0c058394;
case 0x0c058396u: goto P_0c058396;
case 0x0c058398u: goto P_0c058398;
case 0x0c05839au: goto P_0c05839a;
case 0x0c05839cu: goto P_0c05839c;
case 0x0c05839eu: goto P_0c05839e;
case 0x0c0583a0u: goto P_0c0583a0;
case 0x0c0583a2u: goto P_0c0583a2;
case 0x0c0583a4u: goto P_0c0583a4;
case 0x0c0583a6u: goto P_0c0583a6;
case 0x0c0583a8u: goto P_0c0583a8;
case 0x0c0583aau: goto P_0c0583aa;
case 0x0c0583acu: goto P_0c0583ac;
case 0x0c0583aeu: goto P_0c0583ae;
case 0x0c0583b0u: goto P_0c0583b0;
case 0x0c0583b2u: goto P_0c0583b2;
case 0x0c0583b4u: goto P_0c0583b4;
case 0x0c0583b6u: goto P_0c0583b6;
case 0x0c0583b8u: goto P_0c0583b8;
case 0x0c0583bau: goto P_0c0583ba;
case 0x0c0583bcu: goto P_0c0583bc;
case 0x0c0583beu: goto P_0c0583be;
case 0x0c0583c0u: goto P_0c0583c0;
case 0x0c0583c2u: goto P_0c0583c2;
case 0x0c0583c4u: goto P_0c0583c4;
case 0x0c0583c6u: goto P_0c0583c6;
case 0x0c0583c8u: goto P_0c0583c8;
case 0x0c0583cau: goto P_0c0583ca;
case 0x0c0583ccu: goto P_0c0583cc;
case 0x0c0583ceu: goto P_0c0583ce;
case 0x0c0583d0u: goto P_0c0583d0;
case 0x0c0583d2u: goto P_0c0583d2;
case 0x0c0583d4u: goto P_0c0583d4;
case 0x0c0583d6u: goto P_0c0583d6;
case 0x0c0583d8u: goto P_0c0583d8;
case 0x0c0583dau: goto P_0c0583da;
case 0x0c0583dcu: goto P_0c0583dc;
case 0x0c0583deu: goto P_0c0583de;
case 0x0c0583e0u: goto P_0c0583e0;
case 0x0c0583e2u: goto P_0c0583e2;
case 0x0c0583e4u: goto P_0c0583e4;
case 0x0c0583e6u: goto P_0c0583e6;
case 0x0c0583e8u: goto P_0c0583e8;
case 0x0c0583eau: goto P_0c0583ea;
case 0x0c0583ecu: goto P_0c0583ec;
case 0x0c0583eeu: goto P_0c0583ee;
case 0x0c0583f0u: goto P_0c0583f0;
case 0x0c0583f2u: goto P_0c0583f2;
case 0x0c0583f4u: goto P_0c0583f4;
case 0x0c0583f6u: goto P_0c0583f6;
case 0x0c0583f8u: goto P_0c0583f8;
case 0x0c0583fau: goto P_0c0583fa;
case 0x0c0583fcu: goto P_0c0583fc;
case 0x0c0583feu: goto P_0c0583fe;
case 0x0c058400u: goto P_0c058400;
case 0x0c058402u: goto P_0c058402;
case 0x0c058404u: goto P_0c058404;
case 0x0c058406u: goto P_0c058406;
case 0x0c058408u: goto P_0c058408;
case 0x0c05840au: goto P_0c05840a;
case 0x0c05840cu: goto P_0c05840c;
case 0x0c05840eu: goto P_0c05840e;
case 0x0c058410u: goto P_0c058410;
case 0x0c058412u: goto P_0c058412;
case 0x0c058414u: goto P_0c058414;
case 0x0c058416u: goto P_0c058416;
case 0x0c058418u: goto P_0c058418;
case 0x0c05841au: goto P_0c05841a;
case 0x0c05841cu: goto P_0c05841c;
case 0x0c05841eu: goto P_0c05841e;
case 0x0c058420u: goto P_0c058420;
case 0x0c058422u: goto P_0c058422;
case 0x0c058424u: goto P_0c058424;
case 0x0c058426u: goto P_0c058426;
case 0x0c058428u: goto P_0c058428;
case 0x0c05842au: goto P_0c05842a;
case 0x0c05842cu: goto P_0c05842c;
case 0x0c05842eu: goto P_0c05842e;
case 0x0c058430u: goto P_0c058430;
case 0x0c058432u: goto P_0c058432;
case 0x0c058434u: goto P_0c058434;
case 0x0c058436u: goto P_0c058436;
case 0x0c058438u: goto P_0c058438;
case 0x0c05843au: goto P_0c05843a;
case 0x0c05843cu: goto P_0c05843c;
case 0x0c05843eu: goto P_0c05843e;
case 0x0c058440u: goto P_0c058440;
case 0x0c058442u: goto P_0c058442;
case 0x0c058444u: goto P_0c058444;
case 0x0c058446u: goto P_0c058446;
case 0x0c058448u: goto P_0c058448;
case 0x0c05844au: goto P_0c05844a;
case 0x0c05844cu: goto P_0c05844c;
case 0x0c05844eu: goto P_0c05844e;
case 0x0c058450u: goto P_0c058450;
case 0x0c058452u: goto P_0c058452;
case 0x0c058454u: goto P_0c058454;
case 0x0c058456u: goto P_0c058456;
case 0x0c058458u: goto P_0c058458;
case 0x0c05845au: goto P_0c05845a;
case 0x0c05845cu: goto P_0c05845c;
case 0x0c05845eu: goto P_0c05845e;
case 0x0c058460u: goto P_0c058460;
case 0x0c058462u: goto P_0c058462;
case 0x0c058464u: goto P_0c058464;
case 0x0c058466u: goto P_0c058466;
case 0x0c058468u: goto P_0c058468;
case 0x0c05846au: goto P_0c05846a;
case 0x0c05846cu: goto P_0c05846c;
case 0x0c05846eu: goto P_0c05846e;
case 0x0c058470u: goto P_0c058470;
case 0x0c058472u: goto P_0c058472;
case 0x0c058474u: goto P_0c058474;
case 0x0c058476u: goto P_0c058476;
case 0x0c058478u: goto P_0c058478;
case 0x0c05847au: goto P_0c05847a;
case 0x0c05847cu: goto P_0c05847c;
case 0x0c05847eu: goto P_0c05847e;
case 0x0c058480u: goto P_0c058480;
case 0x0c058482u: goto P_0c058482;
case 0x0c058484u: goto P_0c058484;
case 0x0c058486u: goto P_0c058486;
case 0x0c058488u: goto P_0c058488;
case 0x0c05848au: goto P_0c05848a;
case 0x0c05848cu: goto P_0c05848c;
case 0x0c05848eu: goto P_0c05848e;
case 0x0c058490u: goto P_0c058490;
case 0x0c058492u: goto P_0c058492;
case 0x0c058494u: goto P_0c058494;
case 0x0c058496u: goto P_0c058496;
case 0x0c058498u: goto P_0c058498;
case 0x0c05849au: goto P_0c05849a;
case 0x0c05849cu: goto P_0c05849c;
case 0x0c05849eu: goto P_0c05849e;
case 0x0c0584a0u: goto P_0c0584a0;
case 0x0c0584a2u: goto P_0c0584a2;
case 0x0c0584a4u: goto P_0c0584a4;
case 0x0c0584a6u: goto P_0c0584a6;
case 0x0c0584a8u: goto P_0c0584a8;
case 0x0c0584aau: goto P_0c0584aa;
case 0x0c0584acu: goto P_0c0584ac;
case 0x0c0584aeu: goto P_0c0584ae;
case 0x0c0584b0u: goto P_0c0584b0;
case 0x0c0584b2u: goto P_0c0584b2;
case 0x0c0584b4u: goto P_0c0584b4;
case 0x0c0584b6u: goto P_0c0584b6;
case 0x0c0584b8u: goto P_0c0584b8;
case 0x0c0584bau: goto P_0c0584ba;
case 0x0c0584bcu: goto P_0c0584bc;
case 0x0c0584beu: goto P_0c0584be;
case 0x0c0584c0u: goto P_0c0584c0;
case 0x0c0584c2u: goto P_0c0584c2;
case 0x0c0584c4u: goto P_0c0584c4;
case 0x0c0584c6u: goto P_0c0584c6;
case 0x0c0584c8u: goto P_0c0584c8;
case 0x0c0584cau: goto P_0c0584ca;
case 0x0c0584ccu: goto P_0c0584cc;
case 0x0c0584ceu: goto P_0c0584ce;
case 0x0c0584d0u: goto P_0c0584d0;
case 0x0c0584d2u: goto P_0c0584d2;
case 0x0c0584d4u: goto P_0c0584d4;
case 0x0c0584d6u: goto P_0c0584d6;
case 0x0c0584d8u: goto P_0c0584d8;
case 0x0c0584dau: goto P_0c0584da;
case 0x0c0584dcu: goto P_0c0584dc;
case 0x0c0584deu: goto P_0c0584de;
case 0x0c0584e0u: goto P_0c0584e0;
case 0x0c09457eu: goto P_0c09457e;
case 0x0c094580u: goto P_0c094580;
case 0x0c094582u: goto P_0c094582;
case 0x0c094584u: goto P_0c094584;
case 0x0c094586u: goto P_0c094586;
case 0x0c094588u: goto P_0c094588;
case 0x0c09458au: goto P_0c09458a;
case 0x0c09458cu: goto P_0c09458c;
case 0x0c09458eu: goto P_0c09458e;
case 0x0c094590u: goto P_0c094590;
case 0x0c094592u: goto P_0c094592;
case 0x0c094594u: goto P_0c094594;
case 0x0c094596u: goto P_0c094596;
case 0x0c094598u: goto P_0c094598;
case 0x0c09459au: goto P_0c09459a;
case 0x0c09459cu: goto P_0c09459c;
case 0x0c09459eu: goto P_0c09459e;
case 0x0c0945a0u: goto P_0c0945a0;
case 0x0c0945a2u: goto P_0c0945a2;
case 0x0c0945a4u: goto P_0c0945a4;
case 0x0c0945a6u: goto P_0c0945a6;
case 0x0c0945a8u: goto P_0c0945a8;
case 0x0c0945aau: goto P_0c0945aa;
case 0x0c0945acu: goto P_0c0945ac;
case 0x0c0945aeu: goto P_0c0945ae;
case 0x0c0945b0u: goto P_0c0945b0;
case 0x0c0945b2u: goto P_0c0945b2;
case 0x0c0945b4u: goto P_0c0945b4;
case 0x0c0945b6u: goto P_0c0945b6;
case 0x0c0945b8u: goto P_0c0945b8;
case 0x0c0945bau: goto P_0c0945ba;
case 0x0c0945bcu: goto P_0c0945bc;
case 0x0c0945beu: goto P_0c0945be;
case 0x0c0945c0u: goto P_0c0945c0;
case 0x0c0945c2u: goto P_0c0945c2;
case 0x0c0945c4u: goto P_0c0945c4;
case 0x0c0945c6u: goto P_0c0945c6;
case 0x0c0945c8u: goto P_0c0945c8;
case 0x0c0945cau: goto P_0c0945ca;
case 0x0c0945ccu: goto P_0c0945cc;
case 0x0c0945ceu: goto P_0c0945ce;
case 0x0c0945d0u: goto P_0c0945d0;
case 0x0c0945d2u: goto P_0c0945d2;
case 0x0c0945d4u: goto P_0c0945d4;
case 0x0c0945d6u: goto P_0c0945d6;
case 0x0c0945d8u: goto P_0c0945d8;
case 0x0c0945dau: goto P_0c0945da;
case 0x0c0945dcu: goto P_0c0945dc;
case 0x0c0945deu: goto P_0c0945de;
case 0x0c0945e0u: goto P_0c0945e0;
case 0x0c0945e2u: goto P_0c0945e2;
case 0x0c0945e4u: goto P_0c0945e4;
case 0x0c0945e6u: goto P_0c0945e6;
case 0x0c0945e8u: goto P_0c0945e8;
case 0x0c0945eau: goto P_0c0945ea;
case 0x0c0945ecu: goto P_0c0945ec;
case 0x0c0945eeu: goto P_0c0945ee;
case 0x0c0945f0u: goto P_0c0945f0;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
P_0c058348: /* original 4f22, guest PC 0x0c058348 */
if(!s->budget--) { s->failed_pc=0x0c058348u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05834a;
P_0c05834a: /* original f31d, guest PC 0x0c05834a */
if(!s->budget--) { s->failed_pc=0x0c05834au; return 0; }
r[53]=fr[3];
goto P_0c05834c;
P_0c05834c: /* original 7e04, guest PC 0x0c05834c */
if(!s->budget--) { s->failed_pc=0x0c05834cu; return 0; }
r[14]+=0x00000004u;
goto P_0c05834e;
P_0c05834e: /* original 5222, guest PC 0x0c05834e */
if(!s->budget--) { s->failed_pc=0x0c05834eu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c058350;
P_0c058350: /* original 6be5, guest PC 0x0c058350 */
if(!s->budget--) { s->failed_pc=0x0c058350u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[11]=tmp;
goto P_0c058352;
P_0c058352: /* original fbfd, guest PC 0x0c058352 */
if(!s->budget--) { s->failed_pc=0x0c058352u; return 0; }
vf3_matrix_swap(s);
goto P_0c058354;
P_0c058354: /* original 72e0, guest PC 0x0c058354 */
if(!s->budget--) { s->failed_pc=0x0c058354u; return 0; }
r[2]+=0xffffffe0u;
goto P_0c058356;
P_0c058356: /* original f829, guest PC 0x0c058356 */
if(!s->budget--) { s->failed_pc=0x0c058356u; return 0; }
vf3_matrix_load(s,ram,8,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058358;
P_0c058358: /* original f929, guest PC 0x0c058358 */
if(!s->budget--) { s->failed_pc=0x0c058358u; return 0; }
vf3_matrix_load(s,ram,9,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c05835a;
P_0c05835a: /* original fa28, guest PC 0x0c05835a */
if(!s->budget--) { s->failed_pc=0x0c05835au; return 0; }
vf3_matrix_load(s,ram,10,r[2]);
goto P_0c05835c;
P_0c05835c: /* original 72d8, guest PC 0x0c05835c */
if(!s->budget--) { s->failed_pc=0x0c05835cu; return 0; }
r[2]+=0xffffffd8u;
goto P_0c05835e;
P_0c05835e: /* original f029, guest PC 0x0c05835e */
if(!s->budget--) { s->failed_pc=0x0c05835eu; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058360;
P_0c058360: /* original f129, guest PC 0x0c058360 */
if(!s->budget--) { s->failed_pc=0x0c058360u; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058362;
P_0c058362: /* original f228, guest PC 0x0c058362 */
if(!s->budget--) { s->failed_pc=0x0c058362u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c058364;
P_0c058364: /* original 7208, guest PC 0x0c058364 */
if(!s->budget--) { s->failed_pc=0x0c058364u; return 0; }
r[2]+=0x00000008u;
goto P_0c058366;
P_0c058366: /* original f429, guest PC 0x0c058366 */
if(!s->budget--) { s->failed_pc=0x0c058366u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058368;
P_0c058368: /* original f529, guest PC 0x0c058368 */
if(!s->budget--) { s->failed_pc=0x0c058368u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c05836a;
P_0c05836a: /* original 7140, guest PC 0x0c05836a */
if(!s->budget--) { s->failed_pc=0x0c05836au; return 0; }
r[1]+=0x00000040u;
goto P_0c05836c;
P_0c05836c: /* original f628, guest PC 0x0c05836c */
if(!s->budget--) { s->failed_pc=0x0c05836cu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c05836e;
P_0c05836e: /* original fc19, guest PC 0x0c05836e */
if(!s->budget--) { s->failed_pc=0x0c05836eu; return 0; }
vf3_matrix_load(s,ram,12,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c058370;
P_0c058370: /* original fd19, guest PC 0x0c058370 */
if(!s->budget--) { s->failed_pc=0x0c058370u; return 0; }
vf3_matrix_load(s,ram,13,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c058372;
P_0c058372: /* original fe18, guest PC 0x0c058372 */
if(!s->budget--) { s->failed_pc=0x0c058372u; return 0; }
vf3_matrix_load(s,ram,14,r[1]);
goto P_0c058374;
P_0c058374: /* original f3fd, guest PC 0x0c058374 */
if(!s->budget--) { s->failed_pc=0x0c058374u; return 0; }
r[18]^=0x100000u;
goto P_0c058376;
P_0c058376: /* original ff0d, guest PC 0x0c058376 */
if(!s->budget--) { s->failed_pc=0x0c058376u; return 0; }
fr[15]=r[53];
goto P_0c058378;
P_0c058378: /* original fbfd, guest PC 0x0c058378 */
if(!s->budget--) { s->failed_pc=0x0c058378u; return 0; }
vf3_matrix_swap(s);
goto P_0c05837a;
P_0c05837a: /* original 67e5, guest PC 0x0c05837a */
if(!s->budget--) { s->failed_pc=0x0c05837au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c05837c;
P_0c05837c: /* original 68e1, guest PC 0x0c05837c */
if(!s->budget--) { s->failed_pc=0x0c05837cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[8]=tmp;
goto P_0c05837e;
P_0c05837e: /* original e104, guest PC 0x0c05837e */
if(!s->budget--) { s->failed_pc=0x0c05837eu; return 0; }
r[1]=0x00000004u;
goto P_0c058380;
P_0c058380: /* original 85ec, guest PC 0x0c058380 */
if(!s->budget--) { s->failed_pc=0x0c058380u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c058382;
P_0c058382: /* original e500, guest PC 0x0c058382 */
if(!s->budget--) { s->failed_pc=0x0c058382u; return 0; }
r[5]=0x00000000u;
goto P_0c058384;
P_0c058384: /* original 4711, guest PC 0x0c058384 */
if(!s->budget--) { s->failed_pc=0x0c058384u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c058386;
P_0c058386: /* original 481d, guest PC 0x0c058386 */
if(!s->budget--) { s->failed_pc=0x0c058386u; return 0; }
r[8]=(r[1]&0x80000000u)?((r[1]&31u)?r[8]>>((-r[1])&31u):0):r[8]<<(r[1]&31u);
goto P_0c058388;
P_0c058388: /* original 8900, guest PC 0x0c058388 */
if(!s->budget--) { s->failed_pc=0x0c058388u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05838c; }
goto P_0c05838a;
P_0c05838a: /* original 677b, guest PC 0x0c05838a */
if(!s->budget--) { s->failed_pc=0x0c05838au; return 0; }
r[7]=0u-r[7];
goto P_0c05838c;
P_0c05838c: /* original 0329, guest PC 0x0c05838c */
if(!s->budget--) { s->failed_pc=0x0c05838cu; return 0; }
r[3]=r[17]&1u;
goto P_0c05838e;
P_0c05838e: /* original 401d, guest PC 0x0c05838e */
if(!s->budget--) { s->failed_pc=0x0c05838eu; return 0; }
r[0]=(r[1]&0x80000000u)?((r[1]&31u)?r[0]>>((-r[1])&31u):0):r[0]<<(r[1]&31u);
goto P_0c058390;
P_0c058390: /* original 38dc, guest PC 0x0c058390 */
if(!s->budget--) { s->failed_pc=0x0c058390u; return 0; }
r[8]+=r[13];
goto P_0c058392;
P_0c058392: /* original 6903, guest PC 0x0c058392 */
if(!s->budget--) { s->failed_pc=0x0c058392u; return 0; }
r[9]=r[0];
goto P_0c058394;
P_0c058394: /* original f088, guest PC 0x0c058394 */
if(!s->budget--) { s->failed_pc=0x0c058394u; return 0; }
vf3_matrix_load(s,ram,0,r[8]);
goto P_0c058396;
P_0c058396: /* original 39dc, guest PC 0x0c058396 */
if(!s->budget--) { s->failed_pc=0x0c058396u; return 0; }
r[9]+=r[13];
goto P_0c058398;
P_0c058398: /* original 5282, guest PC 0x0c058398 */
if(!s->budget--) { s->failed_pc=0x0c058398u; return 0; }
r[2]=read(ram,r[8]+8,4);
goto P_0c05839a;
P_0c05839a: /* original f498, guest PC 0x0c05839a */
if(!s->budget--) { s->failed_pc=0x0c05839au; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c05839c;
P_0c05839c: /* original 7e30, guest PC 0x0c05839c */
if(!s->budget--) { s->failed_pc=0x0c05839cu; return 0; }
r[14]+=0x00000030u;
goto P_0c05839e;
P_0c05839e: /* original 5192, guest PC 0x0c05839e */
if(!s->budget--) { s->failed_pc=0x0c05839eu; return 0; }
r[1]=read(ram,r[9]+8,4);
goto P_0c0583a0;
P_0c0583a0: /* original 32a6, guest PC 0x0c0583a0 */
if(!s->budget--) { s->failed_pc=0x0c0583a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c0583a2;
P_0c0583a2: /* original 77fe, guest PC 0x0c0583a2 */
if(!s->budget--) { s->failed_pc=0x0c0583a2u; return 0; }
r[7]+=0xfffffffeu;
goto P_0c0583a4;
P_0c0583a4: /* original 0429, guest PC 0x0c0583a4 */
if(!s->budget--) { s->failed_pc=0x0c0583a4u; return 0; }
r[4]=r[17]&1u;
goto P_0c0583a6;
P_0c0583a6: /* original 4215, guest PC 0x0c0583a6 */
if(!s->budget--) { s->failed_pc=0x0c0583a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0583a8;
P_0c0583a8: /* original 344e, guest PC 0x0c0583a8 */
if(!s->budget--) { s->failed_pc=0x0c0583a8u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583aa;
P_0c0583aa: /* original 234a, guest PC 0x0c0583aa */
if(!s->budget--) { s->failed_pc=0x0c0583aau; return 0; }
r[3]^=r[4];
goto P_0c0583ac;
P_0c0583ac: /* original 31a6, guest PC 0x0c0583ac */
if(!s->budget--) { s->failed_pc=0x0c0583acu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[10])!=0);
goto P_0c0583ae;
P_0c0583ae: /* original 66e5, guest PC 0x0c0583ae */
if(!s->budget--) { s->failed_pc=0x0c0583aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c0583b0;
P_0c0583b0: /* original 344e, guest PC 0x0c0583b0 */
if(!s->budget--) { s->failed_pc=0x0c0583b0u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583b2;
P_0c0583b2: /* original 4115, guest PC 0x0c0583b2 */
if(!s->budget--) { s->failed_pc=0x0c0583b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0583b4;
P_0c0583b4: /* original 344e, guest PC 0x0c0583b4 */
if(!s->budget--) { s->failed_pc=0x0c0583b4u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583b6;
P_0c0583b6: /* original 234a, guest PC 0x0c0583b6 */
if(!s->budget--) { s->failed_pc=0x0c0583b6u; return 0; }
r[3]^=r[4];
goto P_0c0583b8;
P_0c0583b8: /* original 4608, guest PC 0x0c0583b8 */
if(!s->budget--) { s->failed_pc=0x0c0583b8u; return 0; }
r[6]<<=2;
goto P_0c0583ba;
P_0c0583ba: /* original 4608, guest PC 0x0c0583ba */
if(!s->budget--) { s->failed_pc=0x0c0583bau; return 0; }
r[6]<<=2;
goto P_0c0583bc;
P_0c0583bc: /* original 36dc, guest PC 0x0c0583bc */
if(!s->budget--) { s->failed_pc=0x0c0583bcu; return 0; }
r[6]+=r[13];
goto P_0c0583be;
P_0c0583be: /* original 5262, guest PC 0x0c0583be */
if(!s->budget--) { s->failed_pc=0x0c0583beu; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c0583c0;
P_0c0583c0: /* original f868, guest PC 0x0c0583c0 */
if(!s->budget--) { s->failed_pc=0x0c0583c0u; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
goto P_0c0583c2;
P_0c0583c2: /* original 32a6, guest PC 0x0c0583c2 */
if(!s->budget--) { s->failed_pc=0x0c0583c2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c0583c4;
P_0c0583c4: /* original 344e, guest PC 0x0c0583c4 */
if(!s->budget--) { s->failed_pc=0x0c0583c4u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583c6;
P_0c0583c6: /* original 4215, guest PC 0x0c0583c6 */
if(!s->budget--) { s->failed_pc=0x0c0583c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0583c8;
P_0c0583c8: /* original 344e, guest PC 0x0c0583c8 */
if(!s->budget--) { s->failed_pc=0x0c0583c8u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583ca;
P_0c0583ca: /* original 234a, guest PC 0x0c0583ca */
if(!s->budget--) { s->failed_pc=0x0c0583cau; return 0; }
r[3]^=r[4];
goto P_0c0583cc;
P_0c0583cc: /* original 6043, guest PC 0x0c0583cc */
if(!s->budget--) { s->failed_pc=0x0c0583ccu; return 0; }
r[0]=r[4];
goto P_0c0583ce;
P_0c0583ce: /* original c810, guest PC 0x0c0583ce */
if(!s->budget--) { s->failed_pc=0x0c0583ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0583d0;
P_0c0583d0: /* original 0229, guest PC 0x0c0583d0 */
if(!s->budget--) { s->failed_pc=0x0c0583d0u; return 0; }
r[2]=r[17]&1u;
goto P_0c0583d2;
P_0c0583d2: /* original c92a, guest PC 0x0c0583d2 */
if(!s->budget--) { s->failed_pc=0x0c0583d2u; return 0; }
r[0]&=42u;
goto P_0c0583d4;
P_0c0583d4: /* original 882a, guest PC 0x0c0583d4 */
if(!s->budget--) { s->failed_pc=0x0c0583d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002au)!=0);
goto P_0c0583d6;
P_0c0583d6: /* original f64c, guest PC 0x0c0583d6 */
if(!s->budget--) { s->failed_pc=0x0c0583d6u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0583d8;
P_0c0583d8: /* original 8d54, guest PC 0x0c0583d8 */
if(!s->budget--) { s->failed_pc=0x0c0583d8u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
if(cond) { goto P_0c058484; }
goto P_0c0583dc;
P_0c0583da: /* original f681, guest PC 0x0c0583da */
if(!s->budget--) { s->failed_pc=0x0c0583dau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c0583dc;
P_0c0583dc: /* original f191, guest PC 0x0c0583dc */
if(!s->budget--) { s->failed_pc=0x0c0583dcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'-');
goto P_0c0583de;
P_0c0583de: /* original f791, guest PC 0x0c0583de */
if(!s->budget--) { s->failed_pc=0x0c0583deu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c0583e0;
P_0c0583e0: /* original f081, guest PC 0x0c0583e0 */
if(!s->budget--) { s->failed_pc=0x0c0583e0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c0583e2;
P_0c0583e2: /* original f64d, guest PC 0x0c0583e2 */
if(!s->budget--) { s->failed_pc=0x0c0583e2u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0583e4;
P_0c0583e4: /* original f612, guest PC 0x0c0583e4 */
if(!s->budget--) { s->failed_pc=0x0c0583e4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'*');
goto P_0c0583e6;
P_0c0583e6: /* original e101, guest PC 0x0c0583e6 */
if(!s->budget--) { s->failed_pc=0x0c0583e6u; return 0; }
r[1]=0x00000001u;
goto P_0c0583e8;
P_0c0583e8: /* original f67e, guest PC 0x0c0583e8 */
if(!s->budget--) { s->failed_pc=0x0c0583e8u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[7],fr[6],r[18]);
goto P_0c0583ea;
P_0c0583ea: /* original 2318, guest PC 0x0c0583ea */
if(!s->budget--) { s->failed_pc=0x0c0583eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c0583ec;
P_0c0583ec: /* original f08d, guest PC 0x0c0583ec */
if(!s->budget--) { s->failed_pc=0x0c0583ecu; return 0; }
fr[0]=0;
goto P_0c0583ee;
P_0c0583ee: /* original 8900, guest PC 0x0c0583ee */
if(!s->budget--) { s->failed_pc=0x0c0583eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0583f2; }
goto P_0c0583f0;
P_0c0583f0: /* original f64d, guest PC 0x0c0583f0 */
if(!s->budget--) { s->failed_pc=0x0c0583f0u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0583f2;
P_0c0583f2: /* original f605, guest PC 0x0c0583f2 */
if(!s->budget--) { s->failed_pc=0x0c0583f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[0]))!=0);
goto P_0c0583f4;
P_0c0583f4: /* original 8d46, guest PC 0x0c0583f4 */
if(!s->budget--) { s->failed_pc=0x0c0583f4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&42u)==0)!=0);
if(cond) { goto P_0c058484; }
goto P_0c0583f8;
P_0c0583f6: /* original c82a, guest PC 0x0c0583f6 */
if(!s->budget--) { s->failed_pc=0x0c0583f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&42u)==0)!=0);
goto P_0c0583f8;
P_0c0583f8: /* original 232a, guest PC 0x0c0583f8 */
if(!s->budget--) { s->failed_pc=0x0c0583f8u; return 0; }
r[3]^=r[2];
goto P_0c0583fa;
P_0c0583fa: /* original 8b3a, guest PC 0x0c0583fa */
if(!s->budget--) { s->failed_pc=0x0c0583fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058472; }
goto P_0c0583fc;
P_0c0583fc: /* original 62e3, guest PC 0x0c0583fc */
if(!s->budget--) { s->failed_pc=0x0c0583fcu; return 0; }
r[2]=r[14];
goto P_0c0583fe;
P_0c0583fe: /* original 72d0, guest PC 0x0c0583fe */
if(!s->budget--) { s->failed_pc=0x0c0583feu; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058400;
P_0c058400: /* original b07e, guest PC 0x0c058400 */
if(!s->budget--) { s->failed_pc=0x0c058400u; return 0; }
target=code_base|0x0c058500u; r[16]=code_base|0x0c058404u;
r[5]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c058404u) { target=s->pc; goto dispatch; }
goto P_0c058404;
P_0c058402: /* original 6583, guest PC 0x0c058402 */
if(!s->budget--) { s->failed_pc=0x0c058402u; return 0; }
r[5]=r[8];
goto P_0c058404;
P_0c058404: /* original 0c83, guest PC 0x0c058404 */
if(!s->budget--) { s->failed_pc=0x0c058404u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058406;
P_0c058406: /* original 7c20, guest PC 0x0c058406 */
if(!s->budget--) { s->failed_pc=0x0c058406u; return 0; }
r[12]+=0x00000020u;
goto P_0c058408;
P_0c058408: /* original 62e3, guest PC 0x0c058408 */
if(!s->budget--) { s->failed_pc=0x0c058408u; return 0; }
r[2]=r[14];
goto P_0c05840a;
P_0c05840a: /* original 72e8, guest PC 0x0c05840a */
if(!s->budget--) { s->failed_pc=0x0c05840au; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05840c;
P_0c05840c: /* original b078, guest PC 0x0c05840c */
if(!s->budget--) { s->failed_pc=0x0c05840cu; return 0; }
target=code_base|0x0c058500u; r[16]=code_base|0x0c058410u;
r[5]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c058410u) { target=s->pc; goto dispatch; }
goto P_0c058410;
P_0c05840e: /* original 6593, guest PC 0x0c05840e */
if(!s->budget--) { s->failed_pc=0x0c05840eu; return 0; }
r[5]=r[9];
goto P_0c058410;
P_0c058410: /* original 6893, guest PC 0x0c058410 */
if(!s->budget--) { s->failed_pc=0x0c058410u; return 0; }
r[8]=r[9];
goto P_0c058412;
P_0c058412: /* original b095, guest PC 0x0c058412 */
if(!s->budget--) { s->failed_pc=0x0c058412u; return 0; }
target=code_base|0x0c058540u; r[16]=code_base|0x0c058416u;
r[9]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c058416u) { target=s->pc; goto dispatch; }
goto P_0c058416;
P_0c058414: /* original 6963, guest PC 0x0c058414 */
if(!s->budget--) { s->failed_pc=0x0c058414u; return 0; }
r[9]=r[6];
goto P_0c058416;
P_0c058416: /* original 4710, guest PC 0x0c058416 */
if(!s->budget--) { s->failed_pc=0x0c058416u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c058418;
P_0c058418: /* original 60e1, guest PC 0x0c058418 */
if(!s->budget--) { s->failed_pc=0x0c058418u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c05841a;
P_0c05841a: /* original 894f, guest PC 0x0c05841a */
if(!s->budget--) { s->failed_pc=0x0c05841au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584bc; }
goto P_0c05841c;
P_0c05841c: /* original 7e02, guest PC 0x0c05841c */
if(!s->budget--) { s->failed_pc=0x0c05841cu; return 0; }
r[14]+=0x00000002u;
goto P_0c05841e;
P_0c05841e: /* original 4008, guest PC 0x0c05841e */
if(!s->budget--) { s->failed_pc=0x0c05841eu; return 0; }
r[0]<<=2;
goto P_0c058420;
P_0c058420: /* original 4008, guest PC 0x0c058420 */
if(!s->budget--) { s->failed_pc=0x0c058420u; return 0; }
r[0]<<=2;
goto P_0c058422;
P_0c058422: /* original 6603, guest PC 0x0c058422 */
if(!s->budget--) { s->failed_pc=0x0c058422u; return 0; }
r[6]=r[0];
goto P_0c058424;
P_0c058424: /* original f8d6, guest PC 0x0c058424 */
if(!s->budget--) { s->failed_pc=0x0c058424u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c058426;
P_0c058426: /* original 36dc, guest PC 0x0c058426 */
if(!s->budget--) { s->failed_pc=0x0c058426u; return 0; }
r[6]+=r[13];
goto P_0c058428;
P_0c058428: /* original 5262, guest PC 0x0c058428 */
if(!s->budget--) { s->failed_pc=0x0c058428u; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c05842a;
P_0c05842a: /* original f498, guest PC 0x0c05842a */
if(!s->budget--) { s->failed_pc=0x0c05842au; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c05842c;
P_0c05842c: /* original f088, guest PC 0x0c05842c */
if(!s->budget--) { s->failed_pc=0x0c05842cu; return 0; }
vf3_matrix_load(s,ram,0,r[8]);
goto P_0c05842e;
P_0c05842e: /* original 32a6, guest PC 0x0c05842e */
if(!s->budget--) { s->failed_pc=0x0c05842eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c058430;
P_0c058430: /* original 344e, guest PC 0x0c058430 */
if(!s->budget--) { s->failed_pc=0x0c058430u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c058432;
P_0c058432: /* original f64c, guest PC 0x0c058432 */
if(!s->budget--) { s->failed_pc=0x0c058432u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c058434;
P_0c058434: /* original f681, guest PC 0x0c058434 */
if(!s->budget--) { s->failed_pc=0x0c058434u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c058436;
P_0c058436: /* original 4215, guest PC 0x0c058436 */
if(!s->budget--) { s->failed_pc=0x0c058436u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c058438;
P_0c058438: /* original 344e, guest PC 0x0c058438 */
if(!s->budget--) { s->failed_pc=0x0c058438u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c05843a;
P_0c05843a: /* original 234a, guest PC 0x0c05843a */
if(!s->budget--) { s->failed_pc=0x0c05843au; return 0; }
r[3]^=r[4];
goto P_0c05843c;
P_0c05843c: /* original 6043, guest PC 0x0c05843c */
if(!s->budget--) { s->failed_pc=0x0c05843cu; return 0; }
r[0]=r[4];
goto P_0c05843e;
P_0c05843e: /* original f191, guest PC 0x0c05843e */
if(!s->budget--) { s->failed_pc=0x0c05843eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'-');
goto P_0c058440;
P_0c058440: /* original c810, guest PC 0x0c058440 */
if(!s->budget--) { s->failed_pc=0x0c058440u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c058442;
P_0c058442: /* original f791, guest PC 0x0c058442 */
if(!s->budget--) { s->failed_pc=0x0c058442u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c058444;
P_0c058444: /* original 0229, guest PC 0x0c058444 */
if(!s->budget--) { s->failed_pc=0x0c058444u; return 0; }
r[2]=r[17]&1u;
goto P_0c058446;
P_0c058446: /* original f081, guest PC 0x0c058446 */
if(!s->budget--) { s->failed_pc=0x0c058446u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c058448;
P_0c058448: /* original f64d, guest PC 0x0c058448 */
if(!s->budget--) { s->failed_pc=0x0c058448u; return 0; }
fr[6]^=0x80000000u;
goto P_0c05844a;
P_0c05844a: /* original f612, guest PC 0x0c05844a */
if(!s->budget--) { s->failed_pc=0x0c05844au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'*');
goto P_0c05844c;
P_0c05844c: /* original e101, guest PC 0x0c05844c */
if(!s->budget--) { s->failed_pc=0x0c05844cu; return 0; }
r[1]=0x00000001u;
goto P_0c05844e;
P_0c05844e: /* original f67e, guest PC 0x0c05844e */
if(!s->budget--) { s->failed_pc=0x0c05844eu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[7],fr[6],r[18]);
goto P_0c058450;
P_0c058450: /* original 2318, guest PC 0x0c058450 */
if(!s->budget--) { s->failed_pc=0x0c058450u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c058452;
P_0c058452: /* original f08d, guest PC 0x0c058452 */
if(!s->budget--) { s->failed_pc=0x0c058452u; return 0; }
fr[0]=0;
goto P_0c058454;
P_0c058454: /* original 8900, guest PC 0x0c058454 */
if(!s->budget--) { s->failed_pc=0x0c058454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058458; }
goto P_0c058456;
P_0c058456: /* original f64d, guest PC 0x0c058456 */
if(!s->budget--) { s->failed_pc=0x0c058456u; return 0; }
fr[6]^=0x80000000u;
goto P_0c058458;
P_0c058458: /* original f605, guest PC 0x0c058458 */
if(!s->budget--) { s->failed_pc=0x0c058458u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[0]))!=0);
goto P_0c05845a;
P_0c05845a: /* original 232a, guest PC 0x0c05845a */
if(!s->budget--) { s->failed_pc=0x0c05845au; return 0; }
r[3]^=r[2];
goto P_0c05845c;
P_0c05845c: /* original 8d1f, guest PC 0x0c05845c */
if(!s->budget--) { s->failed_pc=0x0c05845cu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
if(cond) { goto P_0c05849e; }
goto P_0c058460;
P_0c05845e: /* original c802, guest PC 0x0c05845e */
if(!s->budget--) { s->failed_pc=0x0c05845eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c058460;
P_0c058460: /* original 8b1b, guest PC 0x0c058460 */
if(!s->budget--) { s->failed_pc=0x0c058460u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05849a; }
goto P_0c058462;
P_0c058462: /* original 6893, guest PC 0x0c058462 */
if(!s->budget--) { s->failed_pc=0x0c058462u; return 0; }
r[8]=r[9];
goto P_0c058464;
P_0c058464: /* original b06c, guest PC 0x0c058464 */
if(!s->budget--) { s->failed_pc=0x0c058464u; return 0; }
target=code_base|0x0c058540u; r[16]=code_base|0x0c058468u;
r[9]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c058468u) { target=s->pc; goto dispatch; }
goto P_0c058468;
P_0c058466: /* original 6963, guest PC 0x0c058466 */
if(!s->budget--) { s->failed_pc=0x0c058466u; return 0; }
r[9]=r[6];
goto P_0c058468;
P_0c058468: /* original 4710, guest PC 0x0c058468 */
if(!s->budget--) { s->failed_pc=0x0c058468u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c05846a;
P_0c05846a: /* original 60e1, guest PC 0x0c05846a */
if(!s->budget--) { s->failed_pc=0x0c05846au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c05846c;
P_0c05846c: /* original 8bd6, guest PC 0x0c05846c */
if(!s->budget--) { s->failed_pc=0x0c05846cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05841c; }
goto P_0c05846e;
P_0c05846e: /* original a025, guest PC 0x0c05846e */
if(!s->budget--) { s->failed_pc=0x0c05846eu; return 0; }
goto P_0c0584bc;
P_0c058470: /* original 0009, guest PC 0x0c058470 */
if(!s->budget--) { s->failed_pc=0x0c058470u; return 0; }
goto P_0c058472;
P_0c058472: /* original b179, guest PC 0x0c058472 */
if(!s->budget--) { s->failed_pc=0x0c058472u; return 0; }
target=code_base|0x0c058768u; r[16]=code_base|0x0c058476u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c058476u) { target=s->pc; goto dispatch; }
goto P_0c058476;
P_0c058474: /* original 0009, guest PC 0x0c058474 */
if(!s->budget--) { s->failed_pc=0x0c058474u; return 0; }
goto P_0c058476;
P_0c058476: /* original 60c3, guest PC 0x0c058476 */
if(!s->budget--) { s->failed_pc=0x0c058476u; return 0; }
r[0]=r[12];
goto P_0c058478;
P_0c058478: /* original 4021, guest PC 0x0c058478 */
if(!s->budget--) { s->failed_pc=0x0c058478u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c05847a;
P_0c05847a: /* original e200, guest PC 0x0c05847a */
if(!s->budget--) { s->failed_pc=0x0c05847au; return 0; }
r[2]=0x00000000u;
goto P_0c05847c;
P_0c05847c: /* original 2c02, guest PC 0x0c05847c */
if(!s->budget--) { s->failed_pc=0x0c05847cu; return 0; }
write(ram,r[12],r[0],4);
goto P_0c05847e;
P_0c05847e: /* original e500, guest PC 0x0c05847e */
if(!s->budget--) { s->failed_pc=0x0c05847eu; return 0; }
r[5]=0x00000000u;
goto P_0c058480;
P_0c058480: /* original 0c83, guest PC 0x0c058480 */
if(!s->budget--) { s->failed_pc=0x0c058480u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058482;
P_0c058482: /* original 7c20, guest PC 0x0c058482 */
if(!s->budget--) { s->failed_pc=0x0c058482u; return 0; }
r[12]+=0x00000020u;
goto P_0c058484;
P_0c058484: /* original 232a, guest PC 0x0c058484 */
if(!s->budget--) { s->failed_pc=0x0c058484u; return 0; }
r[3]^=r[2];
goto P_0c058486;
P_0c058486: /* original f04c, guest PC 0x0c058486 */
if(!s->budget--) { s->failed_pc=0x0c058486u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c058488;
P_0c058488: /* original 6893, guest PC 0x0c058488 */
if(!s->budget--) { s->failed_pc=0x0c058488u; return 0; }
r[8]=r[9];
goto P_0c05848a;
P_0c05848a: /* original f48c, guest PC 0x0c05848a */
if(!s->budget--) { s->failed_pc=0x0c05848au; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c05848c;
P_0c05848c: /* original 4710, guest PC 0x0c05848c */
if(!s->budget--) { s->failed_pc=0x0c05848cu; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c05848e;
P_0c05848e: /* original 7e16, guest PC 0x0c05848e */
if(!s->budget--) { s->failed_pc=0x0c05848eu; return 0; }
r[14]+=0x00000016u;
goto P_0c058490;
P_0c058490: /* original 6963, guest PC 0x0c058490 */
if(!s->budget--) { s->failed_pc=0x0c058490u; return 0; }
r[9]=r[6];
goto P_0c058492;
P_0c058492: /* original 66e5, guest PC 0x0c058492 */
if(!s->budget--) { s->failed_pc=0x0c058492u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c058494;
P_0c058494: /* original 8b90, guest PC 0x0c058494 */
if(!s->budget--) { s->failed_pc=0x0c058494u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0583b8; }
goto P_0c058496;
P_0c058496: /* original a011, guest PC 0x0c058496 */
if(!s->budget--) { s->failed_pc=0x0c058496u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584bc;
P_0c058498: /* original 7efe, guest PC 0x0c058498 */
if(!s->budget--) { s->failed_pc=0x0c058498u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c05849a;
P_0c05849a: /* original b2df, guest PC 0x0c05849a */
if(!s->budget--) { s->failed_pc=0x0c05849au; return 0; }
target=code_base|0x0c058a5cu; r[16]=code_base|0x0c05849eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05849eu) { target=s->pc; goto dispatch; }
goto P_0c05849e;
P_0c05849c: /* original 0009, guest PC 0x0c05849c */
if(!s->budget--) { s->failed_pc=0x0c05849cu; return 0; }
goto P_0c05849e;
P_0c05849e: /* original 61c3, guest PC 0x0c05849e */
if(!s->budget--) { s->failed_pc=0x0c05849eu; return 0; }
r[1]=r[12];
goto P_0c0584a0;
P_0c0584a0: /* original 4121, guest PC 0x0c0584a0 */
if(!s->budget--) { s->failed_pc=0x0c0584a0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c0584a2;
P_0c0584a2: /* original f04c, guest PC 0x0c0584a2 */
if(!s->budget--) { s->failed_pc=0x0c0584a2u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0584a4;
P_0c0584a4: /* original 6893, guest PC 0x0c0584a4 */
if(!s->budget--) { s->failed_pc=0x0c0584a4u; return 0; }
r[8]=r[9];
goto P_0c0584a6;
P_0c0584a6: /* original f48c, guest PC 0x0c0584a6 */
if(!s->budget--) { s->failed_pc=0x0c0584a6u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0584a8;
P_0c0584a8: /* original 2c12, guest PC 0x0c0584a8 */
if(!s->budget--) { s->failed_pc=0x0c0584a8u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0584aa;
P_0c0584aa: /* original 7e16, guest PC 0x0c0584aa */
if(!s->budget--) { s->failed_pc=0x0c0584aau; return 0; }
r[14]+=0x00000016u;
goto P_0c0584ac;
P_0c0584ac: /* original 0c83, guest PC 0x0c0584ac */
if(!s->budget--) { s->failed_pc=0x0c0584acu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0584ae;
P_0c0584ae: /* original 4710, guest PC 0x0c0584ae */
if(!s->budget--) { s->failed_pc=0x0c0584aeu; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c0584b0;
P_0c0584b0: /* original 6963, guest PC 0x0c0584b0 */
if(!s->budget--) { s->failed_pc=0x0c0584b0u; return 0; }
r[9]=r[6];
goto P_0c0584b2;
P_0c0584b2: /* original 7c20, guest PC 0x0c0584b2 */
if(!s->budget--) { s->failed_pc=0x0c0584b2u; return 0; }
r[12]+=0x00000020u;
goto P_0c0584b4;
P_0c0584b4: /* original 8f80, guest PC 0x0c0584b4 */
if(!s->budget--) { s->failed_pc=0x0c0584b4u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
if(!cond) { goto P_0c0583b8; }
goto P_0c0584b8;
P_0c0584b6: /* original 66e5, guest PC 0x0c0584b6 */
if(!s->budget--) { s->failed_pc=0x0c0584b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c0584b8;
P_0c0584b8: /* original a007, guest PC 0x0c0584b8 */
if(!s->budget--) { s->failed_pc=0x0c0584b8u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584ca;
P_0c0584ba: /* original 7efe, guest PC 0x0c0584ba */
if(!s->budget--) { s->failed_pc=0x0c0584bau; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584bc;
P_0c0584bc: /* original 2558, guest PC 0x0c0584bc */
if(!s->budget--) { s->failed_pc=0x0c0584bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0584be;
P_0c0584be: /* original 8904, guest PC 0x0c0584be */
if(!s->budget--) { s->failed_pc=0x0c0584beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584ca; }
goto P_0c0584c0;
P_0c0584c0: /* original 60c3, guest PC 0x0c0584c0 */
if(!s->budget--) { s->failed_pc=0x0c0584c0u; return 0; }
r[0]=r[12];
goto P_0c0584c2;
P_0c0584c2: /* original 4021, guest PC 0x0c0584c2 */
if(!s->budget--) { s->failed_pc=0x0c0584c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c0584c4;
P_0c0584c4: /* original 2c02, guest PC 0x0c0584c4 */
if(!s->budget--) { s->failed_pc=0x0c0584c4u; return 0; }
write(ram,r[12],r[0],4);
goto P_0c0584c6;
P_0c0584c6: /* original 0c83, guest PC 0x0c0584c6 */
if(!s->budget--) { s->failed_pc=0x0c0584c6u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0584c8;
P_0c0584c8: /* original 7c20, guest PC 0x0c0584c8 */
if(!s->budget--) { s->failed_pc=0x0c0584c8u; return 0; }
r[12]+=0x00000020u;
goto P_0c0584ca;
P_0c0584ca: /* original 4b10, guest PC 0x0c0584ca */
if(!s->budget--) { s->failed_pc=0x0c0584cau; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0584cc;
P_0c0584cc: /* original 8901, guest PC 0x0c0584cc */
if(!s->budget--) { s->failed_pc=0x0c0584ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584d2; }
goto P_0c0584ce;
P_0c0584ce: /* original af55, guest PC 0x0c0584ce */
if(!s->budget--) { s->failed_pc=0x0c0584ceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c05837c;
P_0c0584d0: /* original 67e5, guest PC 0x0c0584d0 */
if(!s->budget--) { s->failed_pc=0x0c0584d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c0584d2;
P_0c0584d2: /* original 01b2, guest PC 0x0c0584d2 */
if(!s->budget--) { s->failed_pc=0x0c0584d2u; return 0; }
if(!s->bank_known) goto unsupported;
r[1]=s->bank[3];
goto P_0c0584d4;
P_0c0584d4: /* original 21c2, guest PC 0x0c0584d4 */
if(!s->budget--) { s->failed_pc=0x0c0584d4u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c0584d6;
P_0c0584d6: /* original f2fc, guest PC 0x0c0584d6 */
if(!s->budget--) { s->failed_pc=0x0c0584d6u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0584d8;
P_0c0584d8: /* original f3fd, guest PC 0x0c0584d8 */
if(!s->budget--) { s->failed_pc=0x0c0584d8u; return 0; }
r[18]^=0x100000u;
goto P_0c0584da;
P_0c0584da: /* original 64e3, guest PC 0x0c0584da */
if(!s->budget--) { s->failed_pc=0x0c0584dau; return 0; }
r[4]=r[14];
goto P_0c0584dc;
P_0c0584dc: /* original 4f26, guest PC 0x0c0584dc */
if(!s->budget--) { s->failed_pc=0x0c0584dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0584de;
P_0c0584de: /* original 000b, guest PC 0x0c0584de */
if(!s->budget--) { s->failed_pc=0x0c0584deu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0584e0: /* original 6ef6, guest PC 0x0c0584e0 */
if(!s->budget--) { s->failed_pc=0x0c0584e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0584e2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0584e2u; return 0; } return 1;
P_0c09457e: /* original 4f22, guest PC 0x0c09457e */
if(!s->budget--) { s->failed_pc=0x0c09457eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094580;
P_0c094580: /* original fd08, guest PC 0x0c094580 */
if(!s->budget--) { s->failed_pc=0x0c094580u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c094582;
P_0c094582: /* original dc39, guest PC 0x0c094582 */
if(!s->budget--) { s->failed_pc=0x0c094582u; return 0; }
r[12]=read(ram,0x0c094668u,4);
goto P_0c094584;
P_0c094584: /* original dd39, guest PC 0x0c094584 */
if(!s->budget--) { s->failed_pc=0x0c094584u; return 0; }
r[13]=read(ram,0x0c09466cu,4);
goto P_0c094586;
P_0c094586: /* original fc8d, guest PC 0x0c094586 */
if(!s->budget--) { s->failed_pc=0x0c094586u; return 0; }
fr[12]=0;
goto P_0c094588;
P_0c094588: /* original c739, guest PC 0x0c094588 */
if(!s->budget--) { s->failed_pc=0x0c094588u; return 0; }
r[0]=code_base|0x00094670u;
goto P_0c09458a;
P_0c09458a: /* original ff08, guest PC 0x0c09458a */
if(!s->budget--) { s->failed_pc=0x0c09458au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09458c;
P_0c09458c: /* original c739, guest PC 0x0c09458c */
if(!s->budget--) { s->failed_pc=0x0c09458cu; return 0; }
r[0]=code_base|0x00094674u;
goto P_0c09458e;
P_0c09458e: /* original 4d0b, guest PC 0x0c09458e */
if(!s->budget--) { s->failed_pc=0x0c09458eu; return 0; }
target=r[13];
r[16]=code_base|0x0c094592u;
vf3_matrix_load(s,ram,14,r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094592u) { target=s->pc; goto dispatch; }
goto P_0c094592;
P_0c094590: /* original fe08, guest PC 0x0c094590 */
if(!s->budget--) { s->failed_pc=0x0c094590u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c094592;
P_0c094592: /* original f0f2, guest PC 0x0c094592 */
if(!s->budget--) { s->failed_pc=0x0c094592u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c094594;
P_0c094594: /* original f0e1, guest PC 0x0c094594 */
if(!s->budget--) { s->failed_pc=0x0c094594u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'-');
goto P_0c094596;
P_0c094596: /* original 4d0b, guest PC 0x0c094596 */
if(!s->budget--) { s->failed_pc=0x0c094596u; return 0; }
target=r[13];
r[16]=code_base|0x0c09459au;
vf3_matrix_store(s,ram,0,r[14]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09459au) { target=s->pc; goto dispatch; }
goto P_0c09459a;
P_0c094598: /* original fe0a, guest PC 0x0c094598 */
if(!s->budget--) { s->failed_pc=0x0c094598u; return 0; }
vf3_matrix_store(s,ram,0,r[14]);
goto P_0c09459a;
P_0c09459a: /* original f0f2, guest PC 0x0c09459a */
if(!s->budget--) { s->failed_pc=0x0c09459au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c09459c;
P_0c09459c: /* original e008, guest PC 0x0c09459c */
if(!s->budget--) { s->failed_pc=0x0c09459cu; return 0; }
r[0]=0x00000008u;
goto P_0c09459e;
P_0c09459e: /* original f0e1, guest PC 0x0c09459e */
if(!s->budget--) { s->failed_pc=0x0c09459eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'-');
goto P_0c0945a0;
P_0c0945a0: /* original fe07, guest PC 0x0c0945a0 */
if(!s->budget--) { s->failed_pc=0x0c0945a0u; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c0945a2;
P_0c0945a2: /* original c735, guest PC 0x0c0945a2 */
if(!s->budget--) { s->failed_pc=0x0c0945a2u; return 0; }
r[0]=code_base|0x00094678u;
goto P_0c0945a4;
P_0c0945a4: /* original fe08, guest PC 0x0c0945a4 */
if(!s->budget--) { s->failed_pc=0x0c0945a4u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0945a6;
P_0c0945a6: /* original 4d0b, guest PC 0x0c0945a6 */
if(!s->budget--) { s->failed_pc=0x0c0945a6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0945aau;
vf3_matrix_move(s,15,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0945aau) { target=s->pc; goto dispatch; }
goto P_0c0945aa;
P_0c0945a8: /* original ffdc, guest PC 0x0c0945a8 */
if(!s->budget--) { s->failed_pc=0x0c0945a8u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0945aa;
P_0c0945aa: /* original f30c, guest PC 0x0c0945aa */
if(!s->budget--) { s->failed_pc=0x0c0945aau; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0945ac;
P_0c0945ac: /* original e004, guest PC 0x0c0945ac */
if(!s->budget--) { s->failed_pc=0x0c0945acu; return 0; }
r[0]=0x00000004u;
goto P_0c0945ae;
P_0c0945ae: /* original f0ec, guest PC 0x0c0945ae */
if(!s->budget--) { s->failed_pc=0x0c0945aeu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0945b0;
P_0c0945b0: /* original ff3e, guest PC 0x0c0945b0 */
if(!s->budget--) { s->failed_pc=0x0c0945b0u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[3],fr[15],r[18]);
goto P_0c0945b2;
P_0c0945b2: /* original fef7, guest PC 0x0c0945b2 */
if(!s->budget--) { s->failed_pc=0x0c0945b2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0945b4;
P_0c0945b4: /* original e00c, guest PC 0x0c0945b4 */
if(!s->budget--) { s->failed_pc=0x0c0945b4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0945b6;
P_0c0945b6: /* original 4c0b, guest PC 0x0c0945b6 */
if(!s->budget--) { s->failed_pc=0x0c0945b6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945bau;
vf3_matrix_store(s,ram,12,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0945bau) { target=s->pc; goto dispatch; }
goto P_0c0945ba;
P_0c0945b8: /* original fec7, guest PC 0x0c0945b8 */
if(!s->budget--) { s->failed_pc=0x0c0945b8u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0945ba;
P_0c0945ba: /* original e116, guest PC 0x0c0945ba */
if(!s->budget--) { s->failed_pc=0x0c0945bau; return 0; }
r[1]=0x00000016u;
goto P_0c0945bc;
P_0c0945bc: /* original 31ec, guest PC 0x0c0945bc */
if(!s->budget--) { s->failed_pc=0x0c0945bcu; return 0; }
r[1]+=r[14];
goto P_0c0945be;
P_0c0945be: /* original c90f, guest PC 0x0c0945be */
if(!s->budget--) { s->failed_pc=0x0c0945beu; return 0; }
r[0]&=15u;
goto P_0c0945c0;
P_0c0945c0: /* original 4c0b, guest PC 0x0c0945c0 */
if(!s->budget--) { s->failed_pc=0x0c0945c0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945c4u;
write(ram,r[1],r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0945c4u) { target=s->pc; goto dispatch; }
goto P_0c0945c4;
P_0c0945c2: /* original 2100, guest PC 0x0c0945c2 */
if(!s->budget--) { s->failed_pc=0x0c0945c2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0945c4;
P_0c0945c4: /* original 4c0b, guest PC 0x0c0945c4 */
if(!s->budget--) { s->failed_pc=0x0c0945c4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945c8u;
write(ram,r[14]+16,r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0945c8u) { target=s->pc; goto dispatch; }
goto P_0c0945c8;
P_0c0945c6: /* original 81e8, guest PC 0x0c0945c6 */
if(!s->budget--) { s->failed_pc=0x0c0945c6u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c0945c8;
P_0c0945c8: /* original c9f0, guest PC 0x0c0945c8 */
if(!s->budget--) { s->failed_pc=0x0c0945c8u; return 0; }
r[0]&=240u;
goto P_0c0945ca;
P_0c0945ca: /* original 81ea, guest PC 0x0c0945ca */
if(!s->budget--) { s->failed_pc=0x0c0945cau; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c0945cc;
P_0c0945cc: /* original 60a3, guest PC 0x0c0945cc */
if(!s->budget--) { s->failed_pc=0x0c0945ccu; return 0; }
r[0]=r[10];
goto P_0c0945ce;
P_0c0945ce: /* original 81e9, guest PC 0x0c0945ce */
if(!s->budget--) { s->failed_pc=0x0c0945ceu; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c0945d0;
P_0c0945d0: /* original e017, guest PC 0x0c0945d0 */
if(!s->budget--) { s->failed_pc=0x0c0945d0u; return 0; }
r[0]=0x00000017u;
goto P_0c0945d2;
P_0c0945d2: /* original 4b10, guest PC 0x0c0945d2 */
if(!s->budget--) { s->failed_pc=0x0c0945d2u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0945d4;
P_0c0945d4: /* original 0e94, guest PC 0x0c0945d4 */
if(!s->budget--) { s->failed_pc=0x0c0945d4u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c0945d6;
P_0c0945d6: /* original 8fd7, guest PC 0x0c0945d6 */
if(!s->budget--) { s->failed_pc=0x0c0945d6u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c094588; }
goto P_0c0945da;
P_0c0945d8: /* original 7e18, guest PC 0x0c0945d8 */
if(!s->budget--) { s->failed_pc=0x0c0945d8u; return 0; }
r[14]+=0x00000018u;
goto P_0c0945da;
P_0c0945da: /* original 4f26, guest PC 0x0c0945da */
if(!s->budget--) { s->failed_pc=0x0c0945dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0945dc;
P_0c0945dc: /* original fcf9, guest PC 0x0c0945dc */
if(!s->budget--) { s->failed_pc=0x0c0945dcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945de;
P_0c0945de: /* original fdf9, guest PC 0x0c0945de */
if(!s->budget--) { s->failed_pc=0x0c0945deu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e0;
P_0c0945e0: /* original fef9, guest PC 0x0c0945e0 */
if(!s->budget--) { s->failed_pc=0x0c0945e0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e2;
P_0c0945e2: /* original fff9, guest PC 0x0c0945e2 */
if(!s->budget--) { s->failed_pc=0x0c0945e2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e4;
P_0c0945e4: /* original 69f6, guest PC 0x0c0945e4 */
if(!s->budget--) { s->failed_pc=0x0c0945e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0945e6;
P_0c0945e6: /* original 6af6, guest PC 0x0c0945e6 */
if(!s->budget--) { s->failed_pc=0x0c0945e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0945e8;
P_0c0945e8: /* original 6bf6, guest PC 0x0c0945e8 */
if(!s->budget--) { s->failed_pc=0x0c0945e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0945ea;
P_0c0945ea: /* original 6cf6, guest PC 0x0c0945ea */
if(!s->budget--) { s->failed_pc=0x0c0945eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0945ec;
P_0c0945ec: /* original 6df6, guest PC 0x0c0945ec */
if(!s->budget--) { s->failed_pc=0x0c0945ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0945ee;
P_0c0945ee: /* original 000b, guest PC 0x0c0945ee */
if(!s->budget--) { s->failed_pc=0x0c0945eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0945f0: /* original 6ef6, guest PC 0x0c0945f0 */
if(!s->budget--) { s->failed_pc=0x0c0945f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0945f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0945f2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c058348u,0x0c05834au,0x0c05834cu,0x0c05834eu,0x0c058350u,0x0c058352u,0x0c058354u,0x0c058356u,0x0c058358u,0x0c05835au,0x0c05835cu,0x0c05835eu,0x0c058360u,0x0c058362u,0x0c058364u,0x0c058366u,
0x0c058368u,0x0c05836au,0x0c05836cu,0x0c05836eu,0x0c058370u,0x0c058372u,0x0c058374u,0x0c058376u,0x0c058378u,0x0c05837au,0x0c05837cu,0x0c05837eu,0x0c058380u,0x0c058382u,0x0c058384u,0x0c058386u,
0x0c058388u,0x0c05838au,0x0c05838cu,0x0c05838eu,0x0c058390u,0x0c058392u,0x0c058394u,0x0c058396u,0x0c058398u,0x0c05839au,0x0c05839cu,0x0c05839eu,0x0c0583a0u,0x0c0583a2u,0x0c0583a4u,0x0c0583a6u,
0x0c0583a8u,0x0c0583aau,0x0c0583acu,0x0c0583aeu,0x0c0583b0u,0x0c0583b2u,0x0c0583b4u,0x0c0583b6u,0x0c0583b8u,0x0c0583bau,0x0c0583bcu,0x0c0583beu,0x0c0583c0u,0x0c0583c2u,0x0c0583c4u,0x0c0583c6u,
0x0c0583c8u,0x0c0583cau,0x0c0583ccu,0x0c0583ceu,0x0c0583d0u,0x0c0583d2u,0x0c0583d4u,0x0c0583d6u,0x0c0583d8u,0x0c0583dau,0x0c0583dcu,0x0c0583deu,0x0c0583e0u,0x0c0583e2u,0x0c0583e4u,0x0c0583e6u,
0x0c0583e8u,0x0c0583eau,0x0c0583ecu,0x0c0583eeu,0x0c0583f0u,0x0c0583f2u,0x0c0583f4u,0x0c0583f6u,0x0c0583f8u,0x0c0583fau,0x0c0583fcu,0x0c0583feu,0x0c058400u,0x0c058402u,0x0c058404u,0x0c058406u,
0x0c058408u,0x0c05840au,0x0c05840cu,0x0c05840eu,0x0c058410u,0x0c058412u,0x0c058414u,0x0c058416u,0x0c058418u,0x0c05841au,0x0c05841cu,0x0c05841eu,0x0c058420u,0x0c058422u,0x0c058424u,0x0c058426u,
0x0c058428u,0x0c05842au,0x0c05842cu,0x0c05842eu,0x0c058430u,0x0c058432u,0x0c058434u,0x0c058436u,0x0c058438u,0x0c05843au,0x0c05843cu,0x0c05843eu,0x0c058440u,0x0c058442u,0x0c058444u,0x0c058446u,
0x0c058448u,0x0c05844au,0x0c05844cu,0x0c05844eu,0x0c058450u,0x0c058452u,0x0c058454u,0x0c058456u,0x0c058458u,0x0c05845au,0x0c05845cu,0x0c05845eu,0x0c058460u,0x0c058462u,0x0c058464u,0x0c058466u,
0x0c058468u,0x0c05846au,0x0c05846cu,0x0c05846eu,0x0c058470u,0x0c058472u,0x0c058474u,0x0c058476u,0x0c058478u,0x0c05847au,0x0c05847cu,0x0c05847eu,0x0c058480u,0x0c058482u,0x0c058484u,0x0c058486u,
0x0c058488u,0x0c05848au,0x0c05848cu,0x0c05848eu,0x0c058490u,0x0c058492u,0x0c058494u,0x0c058496u,0x0c058498u,0x0c05849au,0x0c05849cu,0x0c05849eu,0x0c0584a0u,0x0c0584a2u,0x0c0584a4u,0x0c0584a6u,
0x0c0584a8u,0x0c0584aau,0x0c0584acu,0x0c0584aeu,0x0c0584b0u,0x0c0584b2u,0x0c0584b4u,0x0c0584b6u,0x0c0584b8u,0x0c0584bau,0x0c0584bcu,0x0c0584beu,0x0c0584c0u,0x0c0584c2u,0x0c0584c4u,0x0c0584c6u,
0x0c0584c8u,0x0c0584cau,0x0c0584ccu,0x0c0584ceu,0x0c0584d0u,0x0c0584d2u,0x0c0584d4u,0x0c0584d6u,0x0c0584d8u,0x0c0584dau,0x0c0584dcu,0x0c0584deu,0x0c0584e0u,0x0c09457eu,0x0c094580u,0x0c094582u,
0x0c094584u,0x0c094586u,0x0c094588u,0x0c09458au,0x0c09458cu,0x0c09458eu,0x0c094590u,0x0c094592u,0x0c094594u,0x0c094596u,0x0c094598u,0x0c09459au,0x0c09459cu,0x0c09459eu,0x0c0945a0u,0x0c0945a2u,
0x0c0945a4u,0x0c0945a6u,0x0c0945a8u,0x0c0945aau,0x0c0945acu,0x0c0945aeu,0x0c0945b0u,0x0c0945b2u,0x0c0945b4u,0x0c0945b6u,0x0c0945b8u,0x0c0945bau,0x0c0945bcu,0x0c0945beu,0x0c0945c0u,0x0c0945c2u,
0x0c0945c4u,0x0c0945c6u,0x0c0945c8u,0x0c0945cau,0x0c0945ccu,0x0c0945ceu,0x0c0945d0u,0x0c0945d2u,0x0c0945d4u,0x0c0945d6u,0x0c0945d8u,0x0c0945dau,0x0c0945dcu,0x0c0945deu,0x0c0945e0u,0x0c0945e2u,
0x0c0945e4u,0x0c0945e6u,0x0c0945e8u,0x0c0945eau,0x0c0945ecu,0x0c0945eeu,0x0c0945f0u,
};
static const uint32_t claim_pcs[]={
0x0c058348u,0x0c09457eu,
};
int vf3_c103_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
