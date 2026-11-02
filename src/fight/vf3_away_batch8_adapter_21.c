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
int vf3_away_batch8_adapter_21(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06534cu: goto P_0c06534c;
case 0x0c06534eu: goto P_0c06534e;
case 0x0c065350u: goto P_0c065350;
case 0x0c065352u: goto P_0c065352;
case 0x0c065354u: goto P_0c065354;
case 0x0c065356u: goto P_0c065356;
case 0x0c065358u: goto P_0c065358;
case 0x0c06535au: goto P_0c06535a;
case 0x0c06535cu: goto P_0c06535c;
case 0x0c06535eu: goto P_0c06535e;
case 0x0c065360u: goto P_0c065360;
case 0x0c065362u: goto P_0c065362;
case 0x0c065364u: goto P_0c065364;
case 0x0c065366u: goto P_0c065366;
case 0x0c065368u: goto P_0c065368;
case 0x0c06536au: goto P_0c06536a;
case 0x0c06536cu: goto P_0c06536c;
case 0x0c06536eu: goto P_0c06536e;
case 0x0c065370u: goto P_0c065370;
case 0x0c065372u: goto P_0c065372;
case 0x0c065374u: goto P_0c065374;
case 0x0c065376u: goto P_0c065376;
case 0x0c065378u: goto P_0c065378;
case 0x0c06537au: goto P_0c06537a;
case 0x0c06537cu: goto P_0c06537c;
case 0x0c06537eu: goto P_0c06537e;
case 0x0c065380u: goto P_0c065380;
case 0x0c065382u: goto P_0c065382;
case 0x0c065384u: goto P_0c065384;
case 0x0c065386u: goto P_0c065386;
case 0x0c065388u: goto P_0c065388;
case 0x0c06538au: goto P_0c06538a;
case 0x0c06538cu: goto P_0c06538c;
case 0x0c06538eu: goto P_0c06538e;
case 0x0c065390u: goto P_0c065390;
case 0x0c065392u: goto P_0c065392;
case 0x0c065394u: goto P_0c065394;
case 0x0c065396u: goto P_0c065396;
case 0x0c065398u: goto P_0c065398;
case 0x0c06539au: goto P_0c06539a;
case 0x0c06539cu: goto P_0c06539c;
case 0x0c06539eu: goto P_0c06539e;
case 0x0c0653a0u: goto P_0c0653a0;
case 0x0c0653a2u: goto P_0c0653a2;
case 0x0c0653a4u: goto P_0c0653a4;
case 0x0c0653a6u: goto P_0c0653a6;
case 0x0c0653a8u: goto P_0c0653a8;
case 0x0c0653aau: goto P_0c0653aa;
case 0x0c0653acu: goto P_0c0653ac;
case 0x0c0653aeu: goto P_0c0653ae;
case 0x0c0653b0u: goto P_0c0653b0;
case 0x0c0653b2u: goto P_0c0653b2;
case 0x0c0653b4u: goto P_0c0653b4;
case 0x0c0653b6u: goto P_0c0653b6;
case 0x0c0653b8u: goto P_0c0653b8;
case 0x0c0653bau: goto P_0c0653ba;
case 0x0c0653bcu: goto P_0c0653bc;
case 0x0c0653beu: goto P_0c0653be;
case 0x0c0653c0u: goto P_0c0653c0;
case 0x0c0653c2u: goto P_0c0653c2;
case 0x0c0653c4u: goto P_0c0653c4;
case 0x0c0653c6u: goto P_0c0653c6;
case 0x0c0653c8u: goto P_0c0653c8;
case 0x0c0653cau: goto P_0c0653ca;
case 0x0c0653ccu: goto P_0c0653cc;
case 0x0c0653ceu: goto P_0c0653ce;
case 0x0c0653d0u: goto P_0c0653d0;
case 0x0c0653d2u: goto P_0c0653d2;
case 0x0c0653d4u: goto P_0c0653d4;
case 0x0c0653d6u: goto P_0c0653d6;
case 0x0c0653d8u: goto P_0c0653d8;
case 0x0c0653dau: goto P_0c0653da;
case 0x0c0653dcu: goto P_0c0653dc;
case 0x0c0653deu: goto P_0c0653de;
case 0x0c0653e0u: goto P_0c0653e0;
case 0x0c0653e2u: goto P_0c0653e2;
case 0x0c0653e4u: goto P_0c0653e4;
case 0x0c0653e6u: goto P_0c0653e6;
case 0x0c0653e8u: goto P_0c0653e8;
case 0x0c0653eau: goto P_0c0653ea;
case 0x0c0653ecu: goto P_0c0653ec;
case 0x0c0653eeu: goto P_0c0653ee;
case 0x0c0653f0u: goto P_0c0653f0;
case 0x0c0653f2u: goto P_0c0653f2;
case 0x0c0653f4u: goto P_0c0653f4;
case 0x0c0653f6u: goto P_0c0653f6;
case 0x0c0653f8u: goto P_0c0653f8;
case 0x0c0653fau: goto P_0c0653fa;
case 0x0c0653fcu: goto P_0c0653fc;
case 0x0c0653feu: goto P_0c0653fe;
case 0x0c065400u: goto P_0c065400;
case 0x0c065402u: goto P_0c065402;
case 0x0c065404u: goto P_0c065404;
case 0x0c065406u: goto P_0c065406;
case 0x0c065408u: goto P_0c065408;
case 0x0c06540au: goto P_0c06540a;
case 0x0c06540cu: goto P_0c06540c;
case 0x0c06540eu: goto P_0c06540e;
case 0x0c065410u: goto P_0c065410;
case 0x0c065412u: goto P_0c065412;
case 0x0c065414u: goto P_0c065414;
case 0x0c065416u: goto P_0c065416;
case 0x0c065418u: goto P_0c065418;
case 0x0c06541au: goto P_0c06541a;
case 0x0c06541cu: goto P_0c06541c;
case 0x0c06541eu: goto P_0c06541e;
case 0x0c065420u: goto P_0c065420;
case 0x0c065422u: goto P_0c065422;
case 0x0c065424u: goto P_0c065424;
case 0x0c065426u: goto P_0c065426;
case 0x0c065428u: goto P_0c065428;
case 0x0c06542au: goto P_0c06542a;
case 0x0c06542cu: goto P_0c06542c;
case 0x0c06542eu: goto P_0c06542e;
case 0x0c065430u: goto P_0c065430;
case 0x0c065432u: goto P_0c065432;
case 0x0c065434u: goto P_0c065434;
case 0x0c065436u: goto P_0c065436;
case 0x0c065438u: goto P_0c065438;
case 0x0c06543au: goto P_0c06543a;
case 0x0c06543cu: goto P_0c06543c;
case 0x0c06543eu: goto P_0c06543e;
case 0x0c065440u: goto P_0c065440;
case 0x0c065442u: goto P_0c065442;
case 0x0c065444u: goto P_0c065444;
case 0x0c065446u: goto P_0c065446;
case 0x0c065448u: goto P_0c065448;
case 0x0c06544au: goto P_0c06544a;
case 0x0c06544cu: goto P_0c06544c;
case 0x0c06544eu: goto P_0c06544e;
case 0x0c065450u: goto P_0c065450;
case 0x0c065452u: goto P_0c065452;
case 0x0c065454u: goto P_0c065454;
case 0x0c065456u: goto P_0c065456;
case 0x0c065458u: goto P_0c065458;
case 0x0c06545au: goto P_0c06545a;
case 0x0c06545cu: goto P_0c06545c;
case 0x0c06545eu: goto P_0c06545e;
case 0x0c065460u: goto P_0c065460;
case 0x0c065462u: goto P_0c065462;
case 0x0c065464u: goto P_0c065464;
case 0x0c065466u: goto P_0c065466;
case 0x0c065468u: goto P_0c065468;
case 0x0c06546au: goto P_0c06546a;
case 0x0c06546cu: goto P_0c06546c;
case 0x0c06546eu: goto P_0c06546e;
case 0x0c065470u: goto P_0c065470;
case 0x0c065472u: goto P_0c065472;
case 0x0c065474u: goto P_0c065474;
case 0x0c065476u: goto P_0c065476;
case 0x0c065478u: goto P_0c065478;
case 0x0c06547au: goto P_0c06547a;
case 0x0c06547cu: goto P_0c06547c;
case 0x0c06547eu: goto P_0c06547e;
case 0x0c065480u: goto P_0c065480;
case 0x0c065482u: goto P_0c065482;
case 0x0c065484u: goto P_0c065484;
case 0x0c065486u: goto P_0c065486;
case 0x0c065488u: goto P_0c065488;
case 0x0c06548au: goto P_0c06548a;
case 0x0c06548cu: goto P_0c06548c;
case 0x0c06548eu: goto P_0c06548e;
case 0x0c065490u: goto P_0c065490;
case 0x0c065492u: goto P_0c065492;
case 0x0c065494u: goto P_0c065494;
case 0x0c065496u: goto P_0c065496;
case 0x0c065498u: goto P_0c065498;
case 0x0c06549au: goto P_0c06549a;
case 0x0c06549cu: goto P_0c06549c;
case 0x0c06549eu: goto P_0c06549e;
case 0x0c0654a0u: goto P_0c0654a0;
case 0x0c0654a2u: goto P_0c0654a2;
case 0x0c0654a4u: goto P_0c0654a4;
case 0x0c0654a6u: goto P_0c0654a6;
case 0x0c0654a8u: goto P_0c0654a8;
case 0x0c0654aau: goto P_0c0654aa;
case 0x0c0654acu: goto P_0c0654ac;
case 0x0c0654aeu: goto P_0c0654ae;
case 0x0c0654b0u: goto P_0c0654b0;
case 0x0c0654b2u: goto P_0c0654b2;
case 0x0c0654b4u: goto P_0c0654b4;
case 0x0c0654b6u: goto P_0c0654b6;
case 0x0c0654b8u: goto P_0c0654b8;
case 0x0c0654bau: goto P_0c0654ba;
case 0x0c0654bcu: goto P_0c0654bc;
case 0x0c0654beu: goto P_0c0654be;
case 0x0c0654c0u: goto P_0c0654c0;
case 0x0c0654c2u: goto P_0c0654c2;
case 0x0c0654c4u: goto P_0c0654c4;
case 0x0c0654c6u: goto P_0c0654c6;
case 0x0c0654c8u: goto P_0c0654c8;
case 0x0c0654cau: goto P_0c0654ca;
case 0x0c0654ccu: goto P_0c0654cc;
case 0x0c0654ceu: goto P_0c0654ce;
case 0x0c0654d0u: goto P_0c0654d0;
case 0x0c0654d2u: goto P_0c0654d2;
case 0x0c0654d4u: goto P_0c0654d4;
case 0x0c0654d6u: goto P_0c0654d6;
case 0x0c0654d8u: goto P_0c0654d8;
case 0x0c0654dau: goto P_0c0654da;
case 0x0c0654dcu: goto P_0c0654dc;
case 0x0c0654deu: goto P_0c0654de;
case 0x0c0654e0u: goto P_0c0654e0;
case 0x0c0654e2u: goto P_0c0654e2;
case 0x0c0654e4u: goto P_0c0654e4;
case 0x0c0654e6u: goto P_0c0654e6;
case 0x0c0654e8u: goto P_0c0654e8;
case 0x0c0654eau: goto P_0c0654ea;
case 0x0c0654ecu: goto P_0c0654ec;
case 0x0c0654eeu: goto P_0c0654ee;
case 0x0c0654f0u: goto P_0c0654f0;
case 0x0c0654f2u: goto P_0c0654f2;
case 0x0c0654f4u: goto P_0c0654f4;
case 0x0c0654f6u: goto P_0c0654f6;
case 0x0c0654f8u: goto P_0c0654f8;
case 0x0c0654fau: goto P_0c0654fa;
case 0x0c0654fcu: goto P_0c0654fc;
case 0x0c0654feu: goto P_0c0654fe;
case 0x0c065500u: goto P_0c065500;
case 0x0c065502u: goto P_0c065502;
case 0x0c065504u: goto P_0c065504;
case 0x0c065506u: goto P_0c065506;
case 0x0c065508u: goto P_0c065508;
case 0x0c06550au: goto P_0c06550a;
case 0x0c06550cu: goto P_0c06550c;
case 0x0c06550eu: goto P_0c06550e;
case 0x0c065510u: goto P_0c065510;
case 0x0c065512u: goto P_0c065512;
case 0x0c065514u: goto P_0c065514;
case 0x0c065516u: goto P_0c065516;
case 0x0c065518u: goto P_0c065518;
case 0x0c06551au: goto P_0c06551a;
case 0x0c06551cu: goto P_0c06551c;
case 0x0c06551eu: goto P_0c06551e;
case 0x0c065520u: goto P_0c065520;
case 0x0c065522u: goto P_0c065522;
case 0x0c065524u: goto P_0c065524;
case 0x0c065526u: goto P_0c065526;
case 0x0c065528u: goto P_0c065528;
case 0x0c06552au: goto P_0c06552a;
case 0x0c06552cu: goto P_0c06552c;
case 0x0c06552eu: goto P_0c06552e;
case 0x0c065530u: goto P_0c065530;
case 0x0c065532u: goto P_0c065532;
case 0x0c065534u: goto P_0c065534;
case 0x0c065536u: goto P_0c065536;
case 0x0c065538u: goto P_0c065538;
case 0x0c06553au: goto P_0c06553a;
case 0x0c06553cu: goto P_0c06553c;
case 0x0c06553eu: goto P_0c06553e;
case 0x0c065540u: goto P_0c065540;
case 0x0c065542u: goto P_0c065542;
case 0x0c065544u: goto P_0c065544;
case 0x0c065546u: goto P_0c065546;
case 0x0c065548u: goto P_0c065548;
case 0x0c06554au: goto P_0c06554a;
case 0x0c06554cu: goto P_0c06554c;
case 0x0c06554eu: goto P_0c06554e;
case 0x0c065550u: goto P_0c065550;
case 0x0c065552u: goto P_0c065552;
case 0x0c065554u: goto P_0c065554;
case 0x0c065556u: goto P_0c065556;
case 0x0c065558u: goto P_0c065558;
case 0x0c06555au: goto P_0c06555a;
case 0x0c06555cu: goto P_0c06555c;
case 0x0c06555eu: goto P_0c06555e;
case 0x0c065560u: goto P_0c065560;
case 0x0c065562u: goto P_0c065562;
case 0x0c065564u: goto P_0c065564;
case 0x0c065566u: goto P_0c065566;
case 0x0c065568u: goto P_0c065568;
case 0x0c06556au: goto P_0c06556a;
case 0x0c06556cu: goto P_0c06556c;
case 0x0c06556eu: goto P_0c06556e;
case 0x0c065570u: goto P_0c065570;
case 0x0c065572u: goto P_0c065572;
case 0x0c065574u: goto P_0c065574;
case 0x0c065576u: goto P_0c065576;
case 0x0c065578u: goto P_0c065578;
case 0x0c06557au: goto P_0c06557a;
case 0x0c06557cu: goto P_0c06557c;
case 0x0c06557eu: goto P_0c06557e;
case 0x0c065580u: goto P_0c065580;
case 0x0c065582u: goto P_0c065582;
case 0x0c065584u: goto P_0c065584;
case 0x0c065586u: goto P_0c065586;
case 0x0c065588u: goto P_0c065588;
case 0x0c06558au: goto P_0c06558a;
case 0x0c06558cu: goto P_0c06558c;
case 0x0c06558eu: goto P_0c06558e;
case 0x0c065590u: goto P_0c065590;
case 0x0c065592u: goto P_0c065592;
case 0x0c065594u: goto P_0c065594;
case 0x0c065596u: goto P_0c065596;
case 0x0c065598u: goto P_0c065598;
case 0x0c06559au: goto P_0c06559a;
case 0x0c06559cu: goto P_0c06559c;
case 0x0c06559eu: goto P_0c06559e;
case 0x0c0655a0u: goto P_0c0655a0;
case 0x0c0655a2u: goto P_0c0655a2;
case 0x0c0655a4u: goto P_0c0655a4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06534c: /* original 2fe6, guest PC 0x0c06534c */
if(!s->budget--) { s->failed_pc=0x0c06534cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06534e;
P_0c06534e: /* original 2fd6, guest PC 0x0c06534e */
if(!s->budget--) { s->failed_pc=0x0c06534eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065350;
P_0c065350: /* original 2fc6, guest PC 0x0c065350 */
if(!s->budget--) { s->failed_pc=0x0c065350u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065352;
P_0c065352: /* original ec00, guest PC 0x0c065352 */
if(!s->budget--) { s->failed_pc=0x0c065352u; return 0; }
r[12]=0x00000000u;
goto P_0c065354;
P_0c065354: /* original 2fb6, guest PC 0x0c065354 */
if(!s->budget--) { s->failed_pc=0x0c065354u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065356;
P_0c065356: /* original 2fa6, guest PC 0x0c065356 */
if(!s->budget--) { s->failed_pc=0x0c065356u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065358;
P_0c065358: /* original 2f96, guest PC 0x0c065358 */
if(!s->budget--) { s->failed_pc=0x0c065358u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06535a;
P_0c06535a: /* original fffb, guest PC 0x0c06535a */
if(!s->budget--) { s->failed_pc=0x0c06535au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06535c;
P_0c06535c: /* original 4f22, guest PC 0x0c06535c */
if(!s->budget--) { s->failed_pc=0x0c06535cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06535e;
P_0c06535e: /* original 7ff0, guest PC 0x0c06535e */
if(!s->budget--) { s->failed_pc=0x0c06535eu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065360;
P_0c065360: /* original 6342, guest PC 0x0c065360 */
if(!s->budget--) { s->failed_pc=0x0c065360u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065362;
P_0c065362: /* original 65f3, guest PC 0x0c065362 */
if(!s->budget--) { s->failed_pc=0x0c065362u; return 0; }
r[5]=r[15];
goto P_0c065364;
P_0c065364: /* original 7504, guest PC 0x0c065364 */
if(!s->budget--) { s->failed_pc=0x0c065364u; return 0; }
r[5]+=0x00000004u;
goto P_0c065366;
P_0c065366: /* original 6e53, guest PC 0x0c065366 */
if(!s->budget--) { s->failed_pc=0x0c065366u; return 0; }
r[14]=r[5];
goto P_0c065368;
P_0c065368: /* original 2e32, guest PC 0x0c065368 */
if(!s->budget--) { s->failed_pc=0x0c065368u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06536a;
P_0c06536a: /* original 6be3, guest PC 0x0c06536a */
if(!s->budget--) { s->failed_pc=0x0c06536au; return 0; }
r[11]=r[14];
goto P_0c06536c;
P_0c06536c: /* original 5241, guest PC 0x0c06536c */
if(!s->budget--) { s->failed_pc=0x0c06536cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06536e;
P_0c06536e: /* original 6ae3, guest PC 0x0c06536e */
if(!s->budget--) { s->failed_pc=0x0c06536eu; return 0; }
r[10]=r[14];
goto P_0c065370;
P_0c065370: /* original 7b04, guest PC 0x0c065370 */
if(!s->budget--) { s->failed_pc=0x0c065370u; return 0; }
r[11]+=0x00000004u;
goto P_0c065372;
P_0c065372: /* original 7a08, guest PC 0x0c065372 */
if(!s->budget--) { s->failed_pc=0x0c065372u; return 0; }
r[10]+=0x00000008u;
goto P_0c065374;
P_0c065374: /* original 2b22, guest PC 0x0c065374 */
if(!s->budget--) { s->failed_pc=0x0c065374u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c065376;
P_0c065376: /* original 5342, guest PC 0x0c065376 */
if(!s->budget--) { s->failed_pc=0x0c065376u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065378;
P_0c065378: /* original d28b, guest PC 0x0c065378 */
if(!s->budget--) { s->failed_pc=0x0c065378u; return 0; }
r[2]=read(ram,0x0c0655a8u,4);
goto P_0c06537a;
P_0c06537a: /* original 2a32, guest PC 0x0c06537a */
if(!s->budget--) { s->failed_pc=0x0c06537au; return 0; }
write(ram,r[10],r[3],4);
goto P_0c06537c;
P_0c06537c: /* original 6d22, guest PC 0x0c06537c */
if(!s->budget--) { s->failed_pc=0x0c06537cu; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c06537e;
P_0c06537e: /* original d38b, guest PC 0x0c06537e */
if(!s->budget--) { s->failed_pc=0x0c06537eu; return 0; }
r[3]=read(ram,0x0c0655acu,4);
goto P_0c065380;
P_0c065380: /* original 6532, guest PC 0x0c065380 */
if(!s->budget--) { s->failed_pc=0x0c065380u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c065382;
P_0c065382: /* original d18b, guest PC 0x0c065382 */
if(!s->budget--) { s->failed_pc=0x0c065382u; return 0; }
r[1]=read(ram,0x0c0655b0u,4);
goto P_0c065384;
P_0c065384: /* original 6412, guest PC 0x0c065384 */
if(!s->budget--) { s->failed_pc=0x0c065384u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c065386;
P_0c065386: /* original d08b, guest PC 0x0c065386 */
if(!s->budget--) { s->failed_pc=0x0c065386u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c065388;
P_0c065388: /* original 62c3, guest PC 0x0c065388 */
if(!s->budget--) { s->failed_pc=0x0c065388u; return 0; }
r[2]=r[12];
goto P_0c06538a;
P_0c06538a: /* original 7c01, guest PC 0x0c06538a */
if(!s->budget--) { s->failed_pc=0x0c06538au; return 0; }
r[12]+=0x00000001u;
goto P_0c06538c;
P_0c06538c: /* original 4208, guest PC 0x0c06538c */
if(!s->budget--) { s->failed_pc=0x0c06538cu; return 0; }
r[2]<<=2;
goto P_0c06538e;
P_0c06538e: /* original 02d6, guest PC 0x0c06538e */
if(!s->budget--) { s->failed_pc=0x0c06538eu; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065390;
P_0c065390: /* original 63c3, guest PC 0x0c065390 */
if(!s->budget--) { s->failed_pc=0x0c065390u; return 0; }
r[3]=r[12];
goto P_0c065392;
P_0c065392: /* original 7c01, guest PC 0x0c065392 */
if(!s->budget--) { s->failed_pc=0x0c065392u; return 0; }
r[12]+=0x00000001u;
goto P_0c065394;
P_0c065394: /* original 4308, guest PC 0x0c065394 */
if(!s->budget--) { s->failed_pc=0x0c065394u; return 0; }
r[3]<<=2;
goto P_0c065396;
P_0c065396: /* original 0356, guest PC 0x0c065396 */
if(!s->budget--) { s->failed_pc=0x0c065396u; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c065398;
P_0c065398: /* original 62c3, guest PC 0x0c065398 */
if(!s->budget--) { s->failed_pc=0x0c065398u; return 0; }
r[2]=r[12];
goto P_0c06539a;
P_0c06539a: /* original 7c01, guest PC 0x0c06539a */
if(!s->budget--) { s->failed_pc=0x0c06539au; return 0; }
r[12]+=0x00000001u;
goto P_0c06539c;
P_0c06539c: /* original 4208, guest PC 0x0c06539c */
if(!s->budget--) { s->failed_pc=0x0c06539cu; return 0; }
r[2]<<=2;
goto P_0c06539e;
P_0c06539e: /* original 0246, guest PC 0x0c06539e */
if(!s->budget--) { s->failed_pc=0x0c06539eu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c0653a0;
P_0c0653a0: /* original 62e2, guest PC 0x0c0653a0 */
if(!s->budget--) { s->failed_pc=0x0c0653a0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0653a2;
P_0c0653a2: /* original 63c3, guest PC 0x0c0653a2 */
if(!s->budget--) { s->failed_pc=0x0c0653a2u; return 0; }
r[3]=r[12];
goto P_0c0653a4;
P_0c0653a4: /* original 5221, guest PC 0x0c0653a4 */
if(!s->budget--) { s->failed_pc=0x0c0653a4u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c0653a6;
P_0c0653a6: /* original 7c01, guest PC 0x0c0653a6 */
if(!s->budget--) { s->failed_pc=0x0c0653a6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0653a8;
P_0c0653a8: /* original 4308, guest PC 0x0c0653a8 */
if(!s->budget--) { s->failed_pc=0x0c0653a8u; return 0; }
r[3]<<=2;
goto P_0c0653aa;
P_0c0653aa: /* original 0326, guest PC 0x0c0653aa */
if(!s->budget--) { s->failed_pc=0x0c0653aau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0653ac;
P_0c0653ac: /* original 62e2, guest PC 0x0c0653ac */
if(!s->budget--) { s->failed_pc=0x0c0653acu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0653ae;
P_0c0653ae: /* original 63c3, guest PC 0x0c0653ae */
if(!s->budget--) { s->failed_pc=0x0c0653aeu; return 0; }
r[3]=r[12];
goto P_0c0653b0;
P_0c0653b0: /* original 5222, guest PC 0x0c0653b0 */
if(!s->budget--) { s->failed_pc=0x0c0653b0u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c0653b2;
P_0c0653b2: /* original 7c01, guest PC 0x0c0653b2 */
if(!s->budget--) { s->failed_pc=0x0c0653b2u; return 0; }
r[12]+=0x00000001u;
goto P_0c0653b4;
P_0c0653b4: /* original 4308, guest PC 0x0c0653b4 */
if(!s->budget--) { s->failed_pc=0x0c0653b4u; return 0; }
r[3]<<=2;
goto P_0c0653b6;
P_0c0653b6: /* original 0326, guest PC 0x0c0653b6 */
if(!s->budget--) { s->failed_pc=0x0c0653b6u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0653b8;
P_0c0653b8: /* original 62e2, guest PC 0x0c0653b8 */
if(!s->budget--) { s->failed_pc=0x0c0653b8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0653ba;
P_0c0653ba: /* original 63c3, guest PC 0x0c0653ba */
if(!s->budget--) { s->failed_pc=0x0c0653bau; return 0; }
r[3]=r[12];
goto P_0c0653bc;
P_0c0653bc: /* original 5223, guest PC 0x0c0653bc */
if(!s->budget--) { s->failed_pc=0x0c0653bcu; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c0653be;
P_0c0653be: /* original 7c01, guest PC 0x0c0653be */
if(!s->budget--) { s->failed_pc=0x0c0653beu; return 0; }
r[12]+=0x00000001u;
goto P_0c0653c0;
P_0c0653c0: /* original 4308, guest PC 0x0c0653c0 */
if(!s->budget--) { s->failed_pc=0x0c0653c0u; return 0; }
r[3]<<=2;
goto P_0c0653c2;
P_0c0653c2: /* original 0326, guest PC 0x0c0653c2 */
if(!s->budget--) { s->failed_pc=0x0c0653c2u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0653c4;
P_0c0653c4: /* original 67e2, guest PC 0x0c0653c4 */
if(!s->budget--) { s->failed_pc=0x0c0653c4u; return 0; }
tmp=read(ram,r[14],4);
r[7]=tmp;
goto P_0c0653c6;
P_0c0653c6: /* original 2f72, guest PC 0x0c0653c6 */
if(!s->budget--) { s->failed_pc=0x0c0653c6u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0653c8;
P_0c0653c8: /* original 5775, guest PC 0x0c0653c8 */
if(!s->budget--) { s->failed_pc=0x0c0653c8u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c0653ca;
P_0c0653ca: /* original 65c3, guest PC 0x0c0653ca */
if(!s->budget--) { s->failed_pc=0x0c0653cau; return 0; }
r[5]=r[12];
goto P_0c0653cc;
P_0c0653cc: /* original 66f2, guest PC 0x0c0653cc */
if(!s->budget--) { s->failed_pc=0x0c0653ccu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0653ce;
P_0c0653ce: /* original 5664, guest PC 0x0c0653ce */
if(!s->budget--) { s->failed_pc=0x0c0653ceu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0653d0;
P_0c0653d0: /* original b8d2, guest PC 0x0c0653d0 */
if(!s->budget--) { s->failed_pc=0x0c0653d0u; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c0653d4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0653d4u) { target=s->pc; goto dispatch; }
goto P_0c0653d4;
P_0c0653d2: /* original 64d3, guest PC 0x0c0653d2 */
if(!s->budget--) { s->failed_pc=0x0c0653d2u; return 0; }
r[4]=r[13];
goto P_0c0653d4;
P_0c0653d4: /* original 64e2, guest PC 0x0c0653d4 */
if(!s->budget--) { s->failed_pc=0x0c0653d4u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0653d6;
P_0c0653d6: /* original e118, guest PC 0x0c0653d6 */
if(!s->budget--) { s->failed_pc=0x0c0653d6u; return 0; }
r[1]=0x00000018u;
goto P_0c0653d8;
P_0c0653d8: /* original 6903, guest PC 0x0c0653d8 */
if(!s->budget--) { s->failed_pc=0x0c0653d8u; return 0; }
r[9]=r[0];
goto P_0c0653da;
P_0c0653da: /* original 6393, guest PC 0x0c0653da */
if(!s->budget--) { s->failed_pc=0x0c0653dau; return 0; }
r[3]=r[9];
goto P_0c0653dc;
P_0c0653dc: /* original c776, guest PC 0x0c0653dc */
if(!s->budget--) { s->failed_pc=0x0c0653dcu; return 0; }
r[0]=code_base|0x000655b8u;
goto P_0c0653de;
P_0c0653de: /* original 314c, guest PC 0x0c0653de */
if(!s->budget--) { s->failed_pc=0x0c0653deu; return 0; }
r[1]+=r[4];
goto P_0c0653e0;
P_0c0653e0: /* original ff08, guest PC 0x0c0653e0 */
if(!s->budget--) { s->failed_pc=0x0c0653e0u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0653e2;
P_0c0653e2: /* original 7901, guest PC 0x0c0653e2 */
if(!s->budget--) { s->failed_pc=0x0c0653e2u; return 0; }
r[9]+=0x00000001u;
goto P_0c0653e4;
P_0c0653e4: /* original f318, guest PC 0x0c0653e4 */
if(!s->budget--) { s->failed_pc=0x0c0653e4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0653e6;
P_0c0653e6: /* original 4308, guest PC 0x0c0653e6 */
if(!s->budget--) { s->failed_pc=0x0c0653e6u; return 0; }
r[3]<<=2;
goto P_0c0653e8;
P_0c0653e8: /* original d072, guest PC 0x0c0653e8 */
if(!s->budget--) { s->failed_pc=0x0c0653e8u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c0653ea;
P_0c0653ea: /* original f3f2, guest PC 0x0c0653ea */
if(!s->budget--) { s->failed_pc=0x0c0653eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0653ec;
P_0c0653ec: /* original f33d, guest PC 0x0c0653ec */
if(!s->budget--) { s->failed_pc=0x0c0653ecu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0653ee;
P_0c0653ee: /* original 045a, guest PC 0x0c0653ee */
if(!s->budget--) { s->failed_pc=0x0c0653eeu; return 0; }
r[4]=r[53];
goto P_0c0653f0;
P_0c0653f0: /* original 6243, guest PC 0x0c0653f0 */
if(!s->budget--) { s->failed_pc=0x0c0653f0u; return 0; }
r[2]=r[4];
goto P_0c0653f2;
P_0c0653f2: /* original 4228, guest PC 0x0c0653f2 */
if(!s->budget--) { s->failed_pc=0x0c0653f2u; return 0; }
r[2]<<=16;
goto P_0c0653f4;
P_0c0653f4: /* original 4218, guest PC 0x0c0653f4 */
if(!s->budget--) { s->failed_pc=0x0c0653f4u; return 0; }
r[2]<<=8;
goto P_0c0653f6;
P_0c0653f6: /* original 6143, guest PC 0x0c0653f6 */
if(!s->budget--) { s->failed_pc=0x0c0653f6u; return 0; }
r[1]=r[4];
goto P_0c0653f8;
P_0c0653f8: /* original 4128, guest PC 0x0c0653f8 */
if(!s->budget--) { s->failed_pc=0x0c0653f8u; return 0; }
r[1]<<=16;
goto P_0c0653fa;
P_0c0653fa: /* original 221b, guest PC 0x0c0653fa */
if(!s->budget--) { s->failed_pc=0x0c0653fau; return 0; }
r[2]|=r[1];
goto P_0c0653fc;
P_0c0653fc: /* original 6143, guest PC 0x0c0653fc */
if(!s->budget--) { s->failed_pc=0x0c0653fcu; return 0; }
r[1]=r[4];
goto P_0c0653fe;
P_0c0653fe: /* original 4118, guest PC 0x0c0653fe */
if(!s->budget--) { s->failed_pc=0x0c0653feu; return 0; }
r[1]<<=8;
goto P_0c065400;
P_0c065400: /* original 221b, guest PC 0x0c065400 */
if(!s->budget--) { s->failed_pc=0x0c065400u; return 0; }
r[2]|=r[1];
goto P_0c065402;
P_0c065402: /* original 224b, guest PC 0x0c065402 */
if(!s->budget--) { s->failed_pc=0x0c065402u; return 0; }
r[2]|=r[4];
goto P_0c065404;
P_0c065404: /* original 0326, guest PC 0x0c065404 */
if(!s->budget--) { s->failed_pc=0x0c065404u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065406;
P_0c065406: /* original e01c, guest PC 0x0c065406 */
if(!s->budget--) { s->failed_pc=0x0c065406u; return 0; }
r[0]=0x0000001cu;
goto P_0c065408;
P_0c065408: /* original 6ce2, guest PC 0x0c065408 */
if(!s->budget--) { s->failed_pc=0x0c065408u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c06540a;
P_0c06540a: /* original f3c6, guest PC 0x0c06540a */
if(!s->budget--) { s->failed_pc=0x0c06540au; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06540c;
P_0c06540c: /* original f3f2, guest PC 0x0c06540c */
if(!s->budget--) { s->failed_pc=0x0c06540cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06540e;
P_0c06540e: /* original f33d, guest PC 0x0c06540e */
if(!s->budget--) { s->failed_pc=0x0c06540eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065410;
P_0c065410: /* original 0c5a, guest PC 0x0c065410 */
if(!s->budget--) { s->failed_pc=0x0c065410u; return 0; }
r[12]=r[53];
goto P_0c065412;
P_0c065412: /* original 66c3, guest PC 0x0c065412 */
if(!s->budget--) { s->failed_pc=0x0c065412u; return 0; }
r[6]=r[12];
goto P_0c065414;
P_0c065414: /* original 4628, guest PC 0x0c065414 */
if(!s->budget--) { s->failed_pc=0x0c065414u; return 0; }
r[6]<<=16;
goto P_0c065416;
P_0c065416: /* original 4618, guest PC 0x0c065416 */
if(!s->budget--) { s->failed_pc=0x0c065416u; return 0; }
r[6]<<=8;
goto P_0c065418;
P_0c065418: /* original 63c3, guest PC 0x0c065418 */
if(!s->budget--) { s->failed_pc=0x0c065418u; return 0; }
r[3]=r[12];
goto P_0c06541a;
P_0c06541a: /* original 4328, guest PC 0x0c06541a */
if(!s->budget--) { s->failed_pc=0x0c06541au; return 0; }
r[3]<<=16;
goto P_0c06541c;
P_0c06541c: /* original 263b, guest PC 0x0c06541c */
if(!s->budget--) { s->failed_pc=0x0c06541cu; return 0; }
r[6]|=r[3];
goto P_0c06541e;
P_0c06541e: /* original 62c3, guest PC 0x0c06541e */
if(!s->budget--) { s->failed_pc=0x0c06541eu; return 0; }
r[2]=r[12];
goto P_0c065420;
P_0c065420: /* original 4218, guest PC 0x0c065420 */
if(!s->budget--) { s->failed_pc=0x0c065420u; return 0; }
r[2]<<=8;
goto P_0c065422;
P_0c065422: /* original 262b, guest PC 0x0c065422 */
if(!s->budget--) { s->failed_pc=0x0c065422u; return 0; }
r[6]|=r[2];
goto P_0c065424;
P_0c065424: /* original 26cb, guest PC 0x0c065424 */
if(!s->budget--) { s->failed_pc=0x0c065424u; return 0; }
r[6]|=r[12];
goto P_0c065426;
P_0c065426: /* original 6593, guest PC 0x0c065426 */
if(!s->budget--) { s->failed_pc=0x0c065426u; return 0; }
r[5]=r[9];
goto P_0c065428;
P_0c065428: /* original b882, guest PC 0x0c065428 */
if(!s->budget--) { s->failed_pc=0x0c065428u; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c06542cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06542cu) { target=s->pc; goto dispatch; }
goto P_0c06542c;
P_0c06542a: /* original 64d3, guest PC 0x0c06542a */
if(!s->budget--) { s->failed_pc=0x0c06542au; return 0; }
r[4]=r[13];
goto P_0c06542c;
P_0c06542c: /* original 64e2, guest PC 0x0c06542c */
if(!s->budget--) { s->failed_pc=0x0c06542cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c06542e;
P_0c06542e: /* original e11c, guest PC 0x0c06542e */
if(!s->budget--) { s->failed_pc=0x0c06542eu; return 0; }
r[1]=0x0000001cu;
goto P_0c065430;
P_0c065430: /* original 6c03, guest PC 0x0c065430 */
if(!s->budget--) { s->failed_pc=0x0c065430u; return 0; }
r[12]=r[0];
goto P_0c065432;
P_0c065432: /* original 62c3, guest PC 0x0c065432 */
if(!s->budget--) { s->failed_pc=0x0c065432u; return 0; }
r[2]=r[12];
goto P_0c065434;
P_0c065434: /* original d05f, guest PC 0x0c065434 */
if(!s->budget--) { s->failed_pc=0x0c065434u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c065436;
P_0c065436: /* original 314c, guest PC 0x0c065436 */
if(!s->budget--) { s->failed_pc=0x0c065436u; return 0; }
r[1]+=r[4];
goto P_0c065438;
P_0c065438: /* original f318, guest PC 0x0c065438 */
if(!s->budget--) { s->failed_pc=0x0c065438u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06543a;
P_0c06543a: /* original 7c01, guest PC 0x0c06543a */
if(!s->budget--) { s->failed_pc=0x0c06543au; return 0; }
r[12]+=0x00000001u;
goto P_0c06543c;
P_0c06543c: /* original 4208, guest PC 0x0c06543c */
if(!s->budget--) { s->failed_pc=0x0c06543cu; return 0; }
r[2]<<=2;
goto P_0c06543e;
P_0c06543e: /* original f3f2, guest PC 0x0c06543e */
if(!s->budget--) { s->failed_pc=0x0c06543eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065440;
P_0c065440: /* original f33d, guest PC 0x0c065440 */
if(!s->budget--) { s->failed_pc=0x0c065440u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065442;
P_0c065442: /* original 045a, guest PC 0x0c065442 */
if(!s->budget--) { s->failed_pc=0x0c065442u; return 0; }
r[4]=r[53];
goto P_0c065444;
P_0c065444: /* original 6343, guest PC 0x0c065444 */
if(!s->budget--) { s->failed_pc=0x0c065444u; return 0; }
r[3]=r[4];
goto P_0c065446;
P_0c065446: /* original 4328, guest PC 0x0c065446 */
if(!s->budget--) { s->failed_pc=0x0c065446u; return 0; }
r[3]<<=16;
goto P_0c065448;
P_0c065448: /* original 4318, guest PC 0x0c065448 */
if(!s->budget--) { s->failed_pc=0x0c065448u; return 0; }
r[3]<<=8;
goto P_0c06544a;
P_0c06544a: /* original 6143, guest PC 0x0c06544a */
if(!s->budget--) { s->failed_pc=0x0c06544au; return 0; }
r[1]=r[4];
goto P_0c06544c;
P_0c06544c: /* original 4128, guest PC 0x0c06544c */
if(!s->budget--) { s->failed_pc=0x0c06544cu; return 0; }
r[1]<<=16;
goto P_0c06544e;
P_0c06544e: /* original 231b, guest PC 0x0c06544e */
if(!s->budget--) { s->failed_pc=0x0c06544eu; return 0; }
r[3]|=r[1];
goto P_0c065450;
P_0c065450: /* original 6143, guest PC 0x0c065450 */
if(!s->budget--) { s->failed_pc=0x0c065450u; return 0; }
r[1]=r[4];
goto P_0c065452;
P_0c065452: /* original 4118, guest PC 0x0c065452 */
if(!s->budget--) { s->failed_pc=0x0c065452u; return 0; }
r[1]<<=8;
goto P_0c065454;
P_0c065454: /* original 231b, guest PC 0x0c065454 */
if(!s->budget--) { s->failed_pc=0x0c065454u; return 0; }
r[3]|=r[1];
goto P_0c065456;
P_0c065456: /* original 234b, guest PC 0x0c065456 */
if(!s->budget--) { s->failed_pc=0x0c065456u; return 0; }
r[3]|=r[4];
goto P_0c065458;
P_0c065458: /* original 0236, guest PC 0x0c065458 */
if(!s->budget--) { s->failed_pc=0x0c065458u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06545a;
P_0c06545a: /* original 62c3, guest PC 0x0c06545a */
if(!s->budget--) { s->failed_pc=0x0c06545au; return 0; }
r[2]=r[12];
goto P_0c06545c;
P_0c06545c: /* original 61b2, guest PC 0x0c06545c */
if(!s->budget--) { s->failed_pc=0x0c06545cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c06545e;
P_0c06545e: /* original 7c01, guest PC 0x0c06545e */
if(!s->budget--) { s->failed_pc=0x0c06545eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065460;
P_0c065460: /* original 5311, guest PC 0x0c065460 */
if(!s->budget--) { s->failed_pc=0x0c065460u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065462;
P_0c065462: /* original 4208, guest PC 0x0c065462 */
if(!s->budget--) { s->failed_pc=0x0c065462u; return 0; }
r[2]<<=2;
goto P_0c065464;
P_0c065464: /* original 0236, guest PC 0x0c065464 */
if(!s->budget--) { s->failed_pc=0x0c065464u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065466;
P_0c065466: /* original 62c3, guest PC 0x0c065466 */
if(!s->budget--) { s->failed_pc=0x0c065466u; return 0; }
r[2]=r[12];
goto P_0c065468;
P_0c065468: /* original 7c01, guest PC 0x0c065468 */
if(!s->budget--) { s->failed_pc=0x0c065468u; return 0; }
r[12]+=0x00000001u;
goto P_0c06546a;
P_0c06546a: /* original 4208, guest PC 0x0c06546a */
if(!s->budget--) { s->failed_pc=0x0c06546au; return 0; }
r[2]<<=2;
goto P_0c06546c;
P_0c06546c: /* original 61b2, guest PC 0x0c06546c */
if(!s->budget--) { s->failed_pc=0x0c06546cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c06546e;
P_0c06546e: /* original 5312, guest PC 0x0c06546e */
if(!s->budget--) { s->failed_pc=0x0c06546eu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065470;
P_0c065470: /* original 0236, guest PC 0x0c065470 */
if(!s->budget--) { s->failed_pc=0x0c065470u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065472;
P_0c065472: /* original 62c3, guest PC 0x0c065472 */
if(!s->budget--) { s->failed_pc=0x0c065472u; return 0; }
r[2]=r[12];
goto P_0c065474;
P_0c065474: /* original 61b2, guest PC 0x0c065474 */
if(!s->budget--) { s->failed_pc=0x0c065474u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065476;
P_0c065476: /* original 7c01, guest PC 0x0c065476 */
if(!s->budget--) { s->failed_pc=0x0c065476u; return 0; }
r[12]+=0x00000001u;
goto P_0c065478;
P_0c065478: /* original 5313, guest PC 0x0c065478 */
if(!s->budget--) { s->failed_pc=0x0c065478u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c06547a;
P_0c06547a: /* original 4208, guest PC 0x0c06547a */
if(!s->budget--) { s->failed_pc=0x0c06547au; return 0; }
r[2]<<=2;
goto P_0c06547c;
P_0c06547c: /* original 0236, guest PC 0x0c06547c */
if(!s->budget--) { s->failed_pc=0x0c06547cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06547e;
P_0c06547e: /* original 65c3, guest PC 0x0c06547e */
if(!s->budget--) { s->failed_pc=0x0c06547eu; return 0; }
r[5]=r[12];
goto P_0c065480;
P_0c065480: /* original 67b2, guest PC 0x0c065480 */
if(!s->budget--) { s->failed_pc=0x0c065480u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c065482;
P_0c065482: /* original 2f72, guest PC 0x0c065482 */
if(!s->budget--) { s->failed_pc=0x0c065482u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065484;
P_0c065484: /* original 5775, guest PC 0x0c065484 */
if(!s->budget--) { s->failed_pc=0x0c065484u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065486;
P_0c065486: /* original 66f2, guest PC 0x0c065486 */
if(!s->budget--) { s->failed_pc=0x0c065486u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065488;
P_0c065488: /* original 5664, guest PC 0x0c065488 */
if(!s->budget--) { s->failed_pc=0x0c065488u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c06548a;
P_0c06548a: /* original b875, guest PC 0x0c06548a */
if(!s->budget--) { s->failed_pc=0x0c06548au; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c06548eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06548eu) { target=s->pc; goto dispatch; }
goto P_0c06548e;
P_0c06548c: /* original 64d3, guest PC 0x0c06548c */
if(!s->budget--) { s->failed_pc=0x0c06548cu; return 0; }
r[4]=r[13];
goto P_0c06548e;
P_0c06548e: /* original 6c03, guest PC 0x0c06548e */
if(!s->budget--) { s->failed_pc=0x0c06548eu; return 0; }
r[12]=r[0];
goto P_0c065490;
P_0c065490: /* original 64b2, guest PC 0x0c065490 */
if(!s->budget--) { s->failed_pc=0x0c065490u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c065492;
P_0c065492: /* original e118, guest PC 0x0c065492 */
if(!s->budget--) { s->failed_pc=0x0c065492u; return 0; }
r[1]=0x00000018u;
goto P_0c065494;
P_0c065494: /* original d047, guest PC 0x0c065494 */
if(!s->budget--) { s->failed_pc=0x0c065494u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c065496;
P_0c065496: /* original 62c3, guest PC 0x0c065496 */
if(!s->budget--) { s->failed_pc=0x0c065496u; return 0; }
r[2]=r[12];
goto P_0c065498;
P_0c065498: /* original 7c01, guest PC 0x0c065498 */
if(!s->budget--) { s->failed_pc=0x0c065498u; return 0; }
r[12]+=0x00000001u;
goto P_0c06549a;
P_0c06549a: /* original 4208, guest PC 0x0c06549a */
if(!s->budget--) { s->failed_pc=0x0c06549au; return 0; }
r[2]<<=2;
goto P_0c06549c;
P_0c06549c: /* original 314c, guest PC 0x0c06549c */
if(!s->budget--) { s->failed_pc=0x0c06549cu; return 0; }
r[1]+=r[4];
goto P_0c06549e;
P_0c06549e: /* original f318, guest PC 0x0c06549e */
if(!s->budget--) { s->failed_pc=0x0c06549eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0654a0;
P_0c0654a0: /* original f3f2, guest PC 0x0c0654a0 */
if(!s->budget--) { s->failed_pc=0x0c0654a0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0654a2;
P_0c0654a2: /* original f33d, guest PC 0x0c0654a2 */
if(!s->budget--) { s->failed_pc=0x0c0654a2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0654a4;
P_0c0654a4: /* original 045a, guest PC 0x0c0654a4 */
if(!s->budget--) { s->failed_pc=0x0c0654a4u; return 0; }
r[4]=r[53];
goto P_0c0654a6;
P_0c0654a6: /* original 6343, guest PC 0x0c0654a6 */
if(!s->budget--) { s->failed_pc=0x0c0654a6u; return 0; }
r[3]=r[4];
goto P_0c0654a8;
P_0c0654a8: /* original 4328, guest PC 0x0c0654a8 */
if(!s->budget--) { s->failed_pc=0x0c0654a8u; return 0; }
r[3]<<=16;
goto P_0c0654aa;
P_0c0654aa: /* original 4318, guest PC 0x0c0654aa */
if(!s->budget--) { s->failed_pc=0x0c0654aau; return 0; }
r[3]<<=8;
goto P_0c0654ac;
P_0c0654ac: /* original 6143, guest PC 0x0c0654ac */
if(!s->budget--) { s->failed_pc=0x0c0654acu; return 0; }
r[1]=r[4];
goto P_0c0654ae;
P_0c0654ae: /* original 4128, guest PC 0x0c0654ae */
if(!s->budget--) { s->failed_pc=0x0c0654aeu; return 0; }
r[1]<<=16;
goto P_0c0654b0;
P_0c0654b0: /* original 231b, guest PC 0x0c0654b0 */
if(!s->budget--) { s->failed_pc=0x0c0654b0u; return 0; }
r[3]|=r[1];
goto P_0c0654b2;
P_0c0654b2: /* original 6143, guest PC 0x0c0654b2 */
if(!s->budget--) { s->failed_pc=0x0c0654b2u; return 0; }
r[1]=r[4];
goto P_0c0654b4;
P_0c0654b4: /* original 4118, guest PC 0x0c0654b4 */
if(!s->budget--) { s->failed_pc=0x0c0654b4u; return 0; }
r[1]<<=8;
goto P_0c0654b6;
P_0c0654b6: /* original 231b, guest PC 0x0c0654b6 */
if(!s->budget--) { s->failed_pc=0x0c0654b6u; return 0; }
r[3]|=r[1];
goto P_0c0654b8;
P_0c0654b8: /* original 234b, guest PC 0x0c0654b8 */
if(!s->budget--) { s->failed_pc=0x0c0654b8u; return 0; }
r[3]|=r[4];
goto P_0c0654ba;
P_0c0654ba: /* original 0236, guest PC 0x0c0654ba */
if(!s->budget--) { s->failed_pc=0x0c0654bau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0654bc;
P_0c0654bc: /* original 69b2, guest PC 0x0c0654bc */
if(!s->budget--) { s->failed_pc=0x0c0654bcu; return 0; }
tmp=read(ram,r[11],4);
r[9]=tmp;
goto P_0c0654be;
P_0c0654be: /* original e01c, guest PC 0x0c0654be */
if(!s->budget--) { s->failed_pc=0x0c0654beu; return 0; }
r[0]=0x0000001cu;
goto P_0c0654c0;
P_0c0654c0: /* original f396, guest PC 0x0c0654c0 */
if(!s->budget--) { s->failed_pc=0x0c0654c0u; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c0654c2;
P_0c0654c2: /* original f3f2, guest PC 0x0c0654c2 */
if(!s->budget--) { s->failed_pc=0x0c0654c2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0654c4;
P_0c0654c4: /* original f33d, guest PC 0x0c0654c4 */
if(!s->budget--) { s->failed_pc=0x0c0654c4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0654c6;
P_0c0654c6: /* original 095a, guest PC 0x0c0654c6 */
if(!s->budget--) { s->failed_pc=0x0c0654c6u; return 0; }
r[9]=r[53];
goto P_0c0654c8;
P_0c0654c8: /* original 6693, guest PC 0x0c0654c8 */
if(!s->budget--) { s->failed_pc=0x0c0654c8u; return 0; }
r[6]=r[9];
goto P_0c0654ca;
P_0c0654ca: /* original 4628, guest PC 0x0c0654ca */
if(!s->budget--) { s->failed_pc=0x0c0654cau; return 0; }
r[6]<<=16;
goto P_0c0654cc;
P_0c0654cc: /* original 4618, guest PC 0x0c0654cc */
if(!s->budget--) { s->failed_pc=0x0c0654ccu; return 0; }
r[6]<<=8;
goto P_0c0654ce;
P_0c0654ce: /* original 6393, guest PC 0x0c0654ce */
if(!s->budget--) { s->failed_pc=0x0c0654ceu; return 0; }
r[3]=r[9];
goto P_0c0654d0;
P_0c0654d0: /* original 4328, guest PC 0x0c0654d0 */
if(!s->budget--) { s->failed_pc=0x0c0654d0u; return 0; }
r[3]<<=16;
goto P_0c0654d2;
P_0c0654d2: /* original 263b, guest PC 0x0c0654d2 */
if(!s->budget--) { s->failed_pc=0x0c0654d2u; return 0; }
r[6]|=r[3];
goto P_0c0654d4;
P_0c0654d4: /* original 6293, guest PC 0x0c0654d4 */
if(!s->budget--) { s->failed_pc=0x0c0654d4u; return 0; }
r[2]=r[9];
goto P_0c0654d6;
P_0c0654d6: /* original 4218, guest PC 0x0c0654d6 */
if(!s->budget--) { s->failed_pc=0x0c0654d6u; return 0; }
r[2]<<=8;
goto P_0c0654d8;
P_0c0654d8: /* original 262b, guest PC 0x0c0654d8 */
if(!s->budget--) { s->failed_pc=0x0c0654d8u; return 0; }
r[6]|=r[2];
goto P_0c0654da;
P_0c0654da: /* original 269b, guest PC 0x0c0654da */
if(!s->budget--) { s->failed_pc=0x0c0654dau; return 0; }
r[6]|=r[9];
goto P_0c0654dc;
P_0c0654dc: /* original 65c3, guest PC 0x0c0654dc */
if(!s->budget--) { s->failed_pc=0x0c0654dcu; return 0; }
r[5]=r[12];
goto P_0c0654de;
P_0c0654de: /* original b827, guest PC 0x0c0654de */
if(!s->budget--) { s->failed_pc=0x0c0654deu; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c0654e2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0654e2u) { target=s->pc; goto dispatch; }
goto P_0c0654e2;
P_0c0654e0: /* original 64d3, guest PC 0x0c0654e0 */
if(!s->budget--) { s->failed_pc=0x0c0654e0u; return 0; }
r[4]=r[13];
goto P_0c0654e2;
P_0c0654e2: /* original 6c03, guest PC 0x0c0654e2 */
if(!s->budget--) { s->failed_pc=0x0c0654e2u; return 0; }
r[12]=r[0];
goto P_0c0654e4;
P_0c0654e4: /* original 61a2, guest PC 0x0c0654e4 */
if(!s->budget--) { s->failed_pc=0x0c0654e4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0654e6;
P_0c0654e6: /* original 62c3, guest PC 0x0c0654e6 */
if(!s->budget--) { s->failed_pc=0x0c0654e6u; return 0; }
r[2]=r[12];
goto P_0c0654e8;
P_0c0654e8: /* original d032, guest PC 0x0c0654e8 */
if(!s->budget--) { s->failed_pc=0x0c0654e8u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c0654ea;
P_0c0654ea: /* original 7c01, guest PC 0x0c0654ea */
if(!s->budget--) { s->failed_pc=0x0c0654eau; return 0; }
r[12]+=0x00000001u;
goto P_0c0654ec;
P_0c0654ec: /* original 5311, guest PC 0x0c0654ec */
if(!s->budget--) { s->failed_pc=0x0c0654ecu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0654ee;
P_0c0654ee: /* original 4208, guest PC 0x0c0654ee */
if(!s->budget--) { s->failed_pc=0x0c0654eeu; return 0; }
r[2]<<=2;
goto P_0c0654f0;
P_0c0654f0: /* original 0236, guest PC 0x0c0654f0 */
if(!s->budget--) { s->failed_pc=0x0c0654f0u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0654f2;
P_0c0654f2: /* original 62c3, guest PC 0x0c0654f2 */
if(!s->budget--) { s->failed_pc=0x0c0654f2u; return 0; }
r[2]=r[12];
goto P_0c0654f4;
P_0c0654f4: /* original 61a2, guest PC 0x0c0654f4 */
if(!s->budget--) { s->failed_pc=0x0c0654f4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0654f6;
P_0c0654f6: /* original 7c01, guest PC 0x0c0654f6 */
if(!s->budget--) { s->failed_pc=0x0c0654f6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0654f8;
P_0c0654f8: /* original 5312, guest PC 0x0c0654f8 */
if(!s->budget--) { s->failed_pc=0x0c0654f8u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0654fa;
P_0c0654fa: /* original 4208, guest PC 0x0c0654fa */
if(!s->budget--) { s->failed_pc=0x0c0654fau; return 0; }
r[2]<<=2;
goto P_0c0654fc;
P_0c0654fc: /* original 0236, guest PC 0x0c0654fc */
if(!s->budget--) { s->failed_pc=0x0c0654fcu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0654fe;
P_0c0654fe: /* original 62c3, guest PC 0x0c0654fe */
if(!s->budget--) { s->failed_pc=0x0c0654feu; return 0; }
r[2]=r[12];
goto P_0c065500;
P_0c065500: /* original 61a2, guest PC 0x0c065500 */
if(!s->budget--) { s->failed_pc=0x0c065500u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065502;
P_0c065502: /* original 7c01, guest PC 0x0c065502 */
if(!s->budget--) { s->failed_pc=0x0c065502u; return 0; }
r[12]+=0x00000001u;
goto P_0c065504;
P_0c065504: /* original 5313, guest PC 0x0c065504 */
if(!s->budget--) { s->failed_pc=0x0c065504u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065506;
P_0c065506: /* original 4208, guest PC 0x0c065506 */
if(!s->budget--) { s->failed_pc=0x0c065506u; return 0; }
r[2]<<=2;
goto P_0c065508;
P_0c065508: /* original 0236, guest PC 0x0c065508 */
if(!s->budget--) { s->failed_pc=0x0c065508u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06550a;
P_0c06550a: /* original 65c3, guest PC 0x0c06550a */
if(!s->budget--) { s->failed_pc=0x0c06550au; return 0; }
r[5]=r[12];
goto P_0c06550c;
P_0c06550c: /* original 67a2, guest PC 0x0c06550c */
if(!s->budget--) { s->failed_pc=0x0c06550cu; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c06550e;
P_0c06550e: /* original 2f72, guest PC 0x0c06550e */
if(!s->budget--) { s->failed_pc=0x0c06550eu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065510;
P_0c065510: /* original 5775, guest PC 0x0c065510 */
if(!s->budget--) { s->failed_pc=0x0c065510u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065512;
P_0c065512: /* original 66f2, guest PC 0x0c065512 */
if(!s->budget--) { s->failed_pc=0x0c065512u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065514;
P_0c065514: /* original 5664, guest PC 0x0c065514 */
if(!s->budget--) { s->failed_pc=0x0c065514u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065516;
P_0c065516: /* original b82f, guest PC 0x0c065516 */
if(!s->budget--) { s->failed_pc=0x0c065516u; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c06551au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06551au) { target=s->pc; goto dispatch; }
goto P_0c06551a;
P_0c065518: /* original 64d3, guest PC 0x0c065518 */
if(!s->budget--) { s->failed_pc=0x0c065518u; return 0; }
r[4]=r[13];
goto P_0c06551a;
P_0c06551a: /* original 6c03, guest PC 0x0c06551a */
if(!s->budget--) { s->failed_pc=0x0c06551au; return 0; }
r[12]=r[0];
goto P_0c06551c;
P_0c06551c: /* original 64a2, guest PC 0x0c06551c */
if(!s->budget--) { s->failed_pc=0x0c06551cu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c06551e;
P_0c06551e: /* original e118, guest PC 0x0c06551e */
if(!s->budget--) { s->failed_pc=0x0c06551eu; return 0; }
r[1]=0x00000018u;
goto P_0c065520;
P_0c065520: /* original d024, guest PC 0x0c065520 */
if(!s->budget--) { s->failed_pc=0x0c065520u; return 0; }
r[0]=read(ram,0x0c0655b4u,4);
goto P_0c065522;
P_0c065522: /* original 62c3, guest PC 0x0c065522 */
if(!s->budget--) { s->failed_pc=0x0c065522u; return 0; }
r[2]=r[12];
goto P_0c065524;
P_0c065524: /* original 7c01, guest PC 0x0c065524 */
if(!s->budget--) { s->failed_pc=0x0c065524u; return 0; }
r[12]+=0x00000001u;
goto P_0c065526;
P_0c065526: /* original 4208, guest PC 0x0c065526 */
if(!s->budget--) { s->failed_pc=0x0c065526u; return 0; }
r[2]<<=2;
goto P_0c065528;
P_0c065528: /* original 314c, guest PC 0x0c065528 */
if(!s->budget--) { s->failed_pc=0x0c065528u; return 0; }
r[1]+=r[4];
goto P_0c06552a;
P_0c06552a: /* original f318, guest PC 0x0c06552a */
if(!s->budget--) { s->failed_pc=0x0c06552au; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06552c;
P_0c06552c: /* original f3f2, guest PC 0x0c06552c */
if(!s->budget--) { s->failed_pc=0x0c06552cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06552e;
P_0c06552e: /* original f33d, guest PC 0x0c06552e */
if(!s->budget--) { s->failed_pc=0x0c06552eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065530;
P_0c065530: /* original 045a, guest PC 0x0c065530 */
if(!s->budget--) { s->failed_pc=0x0c065530u; return 0; }
r[4]=r[53];
goto P_0c065532;
P_0c065532: /* original 6343, guest PC 0x0c065532 */
if(!s->budget--) { s->failed_pc=0x0c065532u; return 0; }
r[3]=r[4];
goto P_0c065534;
P_0c065534: /* original 4328, guest PC 0x0c065534 */
if(!s->budget--) { s->failed_pc=0x0c065534u; return 0; }
r[3]<<=16;
goto P_0c065536;
P_0c065536: /* original 4318, guest PC 0x0c065536 */
if(!s->budget--) { s->failed_pc=0x0c065536u; return 0; }
r[3]<<=8;
goto P_0c065538;
P_0c065538: /* original 6143, guest PC 0x0c065538 */
if(!s->budget--) { s->failed_pc=0x0c065538u; return 0; }
r[1]=r[4];
goto P_0c06553a;
P_0c06553a: /* original 4128, guest PC 0x0c06553a */
if(!s->budget--) { s->failed_pc=0x0c06553au; return 0; }
r[1]<<=16;
goto P_0c06553c;
P_0c06553c: /* original 231b, guest PC 0x0c06553c */
if(!s->budget--) { s->failed_pc=0x0c06553cu; return 0; }
r[3]|=r[1];
goto P_0c06553e;
P_0c06553e: /* original 6143, guest PC 0x0c06553e */
if(!s->budget--) { s->failed_pc=0x0c06553eu; return 0; }
r[1]=r[4];
goto P_0c065540;
P_0c065540: /* original 4118, guest PC 0x0c065540 */
if(!s->budget--) { s->failed_pc=0x0c065540u; return 0; }
r[1]<<=8;
goto P_0c065542;
P_0c065542: /* original 231b, guest PC 0x0c065542 */
if(!s->budget--) { s->failed_pc=0x0c065542u; return 0; }
r[3]|=r[1];
goto P_0c065544;
P_0c065544: /* original 234b, guest PC 0x0c065544 */
if(!s->budget--) { s->failed_pc=0x0c065544u; return 0; }
r[3]|=r[4];
goto P_0c065546;
P_0c065546: /* original 0236, guest PC 0x0c065546 */
if(!s->budget--) { s->failed_pc=0x0c065546u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065548;
P_0c065548: /* original 6ba2, guest PC 0x0c065548 */
if(!s->budget--) { s->failed_pc=0x0c065548u; return 0; }
tmp=read(ram,r[10],4);
r[11]=tmp;
goto P_0c06554a;
P_0c06554a: /* original e01c, guest PC 0x0c06554a */
if(!s->budget--) { s->failed_pc=0x0c06554au; return 0; }
r[0]=0x0000001cu;
goto P_0c06554c;
P_0c06554c: /* original f3b6, guest PC 0x0c06554c */
if(!s->budget--) { s->failed_pc=0x0c06554cu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c06554e;
P_0c06554e: /* original f3f2, guest PC 0x0c06554e */
if(!s->budget--) { s->failed_pc=0x0c06554eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065550;
P_0c065550: /* original f33d, guest PC 0x0c065550 */
if(!s->budget--) { s->failed_pc=0x0c065550u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065552;
P_0c065552: /* original 0b5a, guest PC 0x0c065552 */
if(!s->budget--) { s->failed_pc=0x0c065552u; return 0; }
r[11]=r[53];
goto P_0c065554;
P_0c065554: /* original 66b3, guest PC 0x0c065554 */
if(!s->budget--) { s->failed_pc=0x0c065554u; return 0; }
r[6]=r[11];
goto P_0c065556;
P_0c065556: /* original 4628, guest PC 0x0c065556 */
if(!s->budget--) { s->failed_pc=0x0c065556u; return 0; }
r[6]<<=16;
goto P_0c065558;
P_0c065558: /* original 4618, guest PC 0x0c065558 */
if(!s->budget--) { s->failed_pc=0x0c065558u; return 0; }
r[6]<<=8;
goto P_0c06555a;
P_0c06555a: /* original 63b3, guest PC 0x0c06555a */
if(!s->budget--) { s->failed_pc=0x0c06555au; return 0; }
r[3]=r[11];
goto P_0c06555c;
P_0c06555c: /* original 4328, guest PC 0x0c06555c */
if(!s->budget--) { s->failed_pc=0x0c06555cu; return 0; }
r[3]<<=16;
goto P_0c06555e;
P_0c06555e: /* original 263b, guest PC 0x0c06555e */
if(!s->budget--) { s->failed_pc=0x0c06555eu; return 0; }
r[6]|=r[3];
goto P_0c065560;
P_0c065560: /* original d316, guest PC 0x0c065560 */
if(!s->budget--) { s->failed_pc=0x0c065560u; return 0; }
r[3]=read(ram,0x0c0655bcu,4);
goto P_0c065562;
P_0c065562: /* original 62b3, guest PC 0x0c065562 */
if(!s->budget--) { s->failed_pc=0x0c065562u; return 0; }
r[2]=r[11];
goto P_0c065564;
P_0c065564: /* original 4218, guest PC 0x0c065564 */
if(!s->budget--) { s->failed_pc=0x0c065564u; return 0; }
r[2]<<=8;
goto P_0c065566;
P_0c065566: /* original 262b, guest PC 0x0c065566 */
if(!s->budget--) { s->failed_pc=0x0c065566u; return 0; }
r[6]|=r[2];
goto P_0c065568;
P_0c065568: /* original 26bb, guest PC 0x0c065568 */
if(!s->budget--) { s->failed_pc=0x0c065568u; return 0; }
r[6]|=r[11];
goto P_0c06556a;
P_0c06556a: /* original 65c3, guest PC 0x0c06556a */
if(!s->budget--) { s->failed_pc=0x0c06556au; return 0; }
r[5]=r[12];
goto P_0c06556c;
P_0c06556c: /* original 430b, guest PC 0x0c06556c */
if(!s->budget--) { s->failed_pc=0x0c06556cu; return 0; }
target=r[3];
r[16]=code_base|0x0c065570u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065570u) { target=s->pc; goto dispatch; }
goto P_0c065570;
P_0c06556e: /* original 64d3, guest PC 0x0c06556e */
if(!s->budget--) { s->failed_pc=0x0c06556eu; return 0; }
r[4]=r[13];
goto P_0c065570;
P_0c065570: /* original d213, guest PC 0x0c065570 */
if(!s->budget--) { s->failed_pc=0x0c065570u; return 0; }
r[2]=read(ram,0x0c0655c0u,4);
goto P_0c065572;
P_0c065572: /* original 6403, guest PC 0x0c065572 */
if(!s->budget--) { s->failed_pc=0x0c065572u; return 0; }
r[4]=r[0];
goto P_0c065574;
P_0c065574: /* original 4408, guest PC 0x0c065574 */
if(!s->budget--) { s->failed_pc=0x0c065574u; return 0; }
r[4]<<=2;
goto P_0c065576;
P_0c065576: /* original 2242, guest PC 0x0c065576 */
if(!s->budget--) { s->failed_pc=0x0c065576u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c065578;
P_0c065578: /* original d312, guest PC 0x0c065578 */
if(!s->budget--) { s->failed_pc=0x0c065578u; return 0; }
r[3]=read(ram,0x0c0655c4u,4);
goto P_0c06557a;
P_0c06557a: /* original 430b, guest PC 0x0c06557a */
if(!s->budget--) { s->failed_pc=0x0c06557au; return 0; }
target=r[3];
r[16]=code_base|0x0c06557eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06557eu) { target=s->pc; goto dispatch; }
goto P_0c06557e;
P_0c06557c: /* original 64d3, guest PC 0x0c06557c */
if(!s->budget--) { s->failed_pc=0x0c06557cu; return 0; }
r[4]=r[13];
goto P_0c06557e;
P_0c06557e: /* original 6403, guest PC 0x0c06557e */
if(!s->budget--) { s->failed_pc=0x0c06557eu; return 0; }
r[4]=r[0];
goto P_0c065580;
P_0c065580: /* original d211, guest PC 0x0c065580 */
if(!s->budget--) { s->failed_pc=0x0c065580u; return 0; }
r[2]=read(ram,0x0c0655c8u,4);
goto P_0c065582;
P_0c065582: /* original e500, guest PC 0x0c065582 */
if(!s->budget--) { s->failed_pc=0x0c065582u; return 0; }
r[5]=0x00000000u;
goto P_0c065584;
P_0c065584: /* original 420b, guest PC 0x0c065584 */
if(!s->budget--) { s->failed_pc=0x0c065584u; return 0; }
target=r[2];
r[16]=code_base|0x0c065588u;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065588u) { target=s->pc; goto dispatch; }
goto P_0c065588;
P_0c065586: /* original 6653, guest PC 0x0c065586 */
if(!s->budget--) { s->failed_pc=0x0c065586u; return 0; }
r[6]=r[5];
goto P_0c065588;
P_0c065588: /* original 62e2, guest PC 0x0c065588 */
if(!s->budget--) { s->failed_pc=0x0c065588u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06558a;
P_0c06558a: /* original 5323, guest PC 0x0c06558a */
if(!s->budget--) { s->failed_pc=0x0c06558au; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c06558c;
P_0c06558c: /* original d10f, guest PC 0x0c06558c */
if(!s->budget--) { s->failed_pc=0x0c06558cu; return 0; }
r[1]=read(ram,0x0c0655ccu,4);
goto P_0c06558e;
P_0c06558e: /* original 2132, guest PC 0x0c06558e */
if(!s->budget--) { s->failed_pc=0x0c06558eu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c065590;
P_0c065590: /* original e000, guest PC 0x0c065590 */
if(!s->budget--) { s->failed_pc=0x0c065590u; return 0; }
r[0]=0x00000000u;
goto P_0c065592;
P_0c065592: /* original 7f10, guest PC 0x0c065592 */
if(!s->budget--) { s->failed_pc=0x0c065592u; return 0; }
r[15]+=0x00000010u;
goto P_0c065594;
P_0c065594: /* original 4f26, guest PC 0x0c065594 */
if(!s->budget--) { s->failed_pc=0x0c065594u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065596;
P_0c065596: /* original fff9, guest PC 0x0c065596 */
if(!s->budget--) { s->failed_pc=0x0c065596u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c065598;
P_0c065598: /* original 69f6, guest PC 0x0c065598 */
if(!s->budget--) { s->failed_pc=0x0c065598u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06559a;
P_0c06559a: /* original 6af6, guest PC 0x0c06559a */
if(!s->budget--) { s->failed_pc=0x0c06559au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06559c;
P_0c06559c: /* original 6bf6, guest PC 0x0c06559c */
if(!s->budget--) { s->failed_pc=0x0c06559cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06559e;
P_0c06559e: /* original 6cf6, guest PC 0x0c06559e */
if(!s->budget--) { s->failed_pc=0x0c06559eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0655a0;
P_0c0655a0: /* original 6df6, guest PC 0x0c0655a0 */
if(!s->budget--) { s->failed_pc=0x0c0655a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0655a2;
P_0c0655a2: /* original 000b, guest PC 0x0c0655a2 */
if(!s->budget--) { s->failed_pc=0x0c0655a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0655a4: /* original 6ef6, guest PC 0x0c0655a4 */
if(!s->budget--) { s->failed_pc=0x0c0655a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0655a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0655a6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
