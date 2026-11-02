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
int vf3_away_batch168_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c8268u: goto P_0c0c8268;
case 0x0c0c826au: goto P_0c0c826a;
case 0x0c0c826cu: goto P_0c0c826c;
case 0x0c0c826eu: goto P_0c0c826e;
case 0x0c0c8270u: goto P_0c0c8270;
case 0x0c0c8272u: goto P_0c0c8272;
case 0x0c0c8274u: goto P_0c0c8274;
case 0x0c0c8276u: goto P_0c0c8276;
case 0x0c0c8278u: goto P_0c0c8278;
case 0x0c0c827au: goto P_0c0c827a;
case 0x0c0c827cu: goto P_0c0c827c;
case 0x0c0c827eu: goto P_0c0c827e;
case 0x0c0c8280u: goto P_0c0c8280;
case 0x0c0c8282u: goto P_0c0c8282;
case 0x0c0c8284u: goto P_0c0c8284;
case 0x0c0c8286u: goto P_0c0c8286;
case 0x0c0c8288u: goto P_0c0c8288;
case 0x0c0c828au: goto P_0c0c828a;
case 0x0c0c828cu: goto P_0c0c828c;
case 0x0c0c828eu: goto P_0c0c828e;
case 0x0c0c8290u: goto P_0c0c8290;
case 0x0c0c8292u: goto P_0c0c8292;
case 0x0c0c8294u: goto P_0c0c8294;
case 0x0c0c8296u: goto P_0c0c8296;
case 0x0c0c8298u: goto P_0c0c8298;
case 0x0c0c829au: goto P_0c0c829a;
case 0x0c0c829cu: goto P_0c0c829c;
case 0x0c0c829eu: goto P_0c0c829e;
case 0x0c0c82a0u: goto P_0c0c82a0;
case 0x0c0c82a2u: goto P_0c0c82a2;
case 0x0c0c82a4u: goto P_0c0c82a4;
case 0x0c0c82a6u: goto P_0c0c82a6;
case 0x0c0c82a8u: goto P_0c0c82a8;
case 0x0c0c82aau: goto P_0c0c82aa;
case 0x0c0c82acu: goto P_0c0c82ac;
case 0x0c0c82aeu: goto P_0c0c82ae;
case 0x0c0c82b0u: goto P_0c0c82b0;
case 0x0c0c82b2u: goto P_0c0c82b2;
case 0x0c0c82b4u: goto P_0c0c82b4;
case 0x0c0c82b6u: goto P_0c0c82b6;
case 0x0c0c82b8u: goto P_0c0c82b8;
case 0x0c0c82bau: goto P_0c0c82ba;
case 0x0c0c82bcu: goto P_0c0c82bc;
case 0x0c0c82beu: goto P_0c0c82be;
case 0x0c0c82c0u: goto P_0c0c82c0;
case 0x0c0c82c2u: goto P_0c0c82c2;
case 0x0c0c82c4u: goto P_0c0c82c4;
case 0x0c0c82c6u: goto P_0c0c82c6;
case 0x0c0c82c8u: goto P_0c0c82c8;
case 0x0c0c82cau: goto P_0c0c82ca;
case 0x0c0c82ccu: goto P_0c0c82cc;
case 0x0c0c82ceu: goto P_0c0c82ce;
case 0x0c0c82d0u: goto P_0c0c82d0;
case 0x0c0c82d2u: goto P_0c0c82d2;
case 0x0c0c82d4u: goto P_0c0c82d4;
case 0x0c0c82d6u: goto P_0c0c82d6;
case 0x0c0c82d8u: goto P_0c0c82d8;
case 0x0c0c82dau: goto P_0c0c82da;
case 0x0c0c82dcu: goto P_0c0c82dc;
case 0x0c0c82deu: goto P_0c0c82de;
case 0x0c0c82e0u: goto P_0c0c82e0;
case 0x0c0c82e2u: goto P_0c0c82e2;
case 0x0c0c8324u: goto P_0c0c8324;
case 0x0c0c8326u: goto P_0c0c8326;
case 0x0c0c8328u: goto P_0c0c8328;
case 0x0c0c832au: goto P_0c0c832a;
case 0x0c0c832cu: goto P_0c0c832c;
case 0x0c0c832eu: goto P_0c0c832e;
case 0x0c0c8330u: goto P_0c0c8330;
case 0x0c0c8332u: goto P_0c0c8332;
case 0x0c0c8334u: goto P_0c0c8334;
case 0x0c0c8336u: goto P_0c0c8336;
case 0x0c0c8338u: goto P_0c0c8338;
case 0x0c0c833au: goto P_0c0c833a;
case 0x0c0c833cu: goto P_0c0c833c;
case 0x0c0c833eu: goto P_0c0c833e;
case 0x0c0c8340u: goto P_0c0c8340;
case 0x0c0c8342u: goto P_0c0c8342;
case 0x0c0c8344u: goto P_0c0c8344;
case 0x0c0c8346u: goto P_0c0c8346;
case 0x0c0c8348u: goto P_0c0c8348;
case 0x0c0c834au: goto P_0c0c834a;
case 0x0c0c834cu: goto P_0c0c834c;
case 0x0c0c834eu: goto P_0c0c834e;
case 0x0c0c8350u: goto P_0c0c8350;
case 0x0c0c8352u: goto P_0c0c8352;
case 0x0c0c8354u: goto P_0c0c8354;
case 0x0c0c8356u: goto P_0c0c8356;
case 0x0c0c8358u: goto P_0c0c8358;
case 0x0c0c835au: goto P_0c0c835a;
case 0x0c0c835cu: goto P_0c0c835c;
case 0x0c0c835eu: goto P_0c0c835e;
case 0x0c0c8394u: goto P_0c0c8394;
case 0x0c0c8396u: goto P_0c0c8396;
case 0x0c0c8398u: goto P_0c0c8398;
case 0x0c0c839au: goto P_0c0c839a;
case 0x0c0c839cu: goto P_0c0c839c;
case 0x0c0c839eu: goto P_0c0c839e;
case 0x0c0c83a0u: goto P_0c0c83a0;
case 0x0c0c83a2u: goto P_0c0c83a2;
case 0x0c0c83a4u: goto P_0c0c83a4;
case 0x0c0c83a6u: goto P_0c0c83a6;
case 0x0c0c83a8u: goto P_0c0c83a8;
case 0x0c0c83aau: goto P_0c0c83aa;
case 0x0c0c83acu: goto P_0c0c83ac;
case 0x0c0c83aeu: goto P_0c0c83ae;
case 0x0c0c83b0u: goto P_0c0c83b0;
case 0x0c0c83b2u: goto P_0c0c83b2;
case 0x0c0c83b4u: goto P_0c0c83b4;
case 0x0c0c83b6u: goto P_0c0c83b6;
case 0x0c0c83b8u: goto P_0c0c83b8;
case 0x0c0c83bau: goto P_0c0c83ba;
case 0x0c0c83bcu: goto P_0c0c83bc;
case 0x0c0c83beu: goto P_0c0c83be;
case 0x0c0c83c0u: goto P_0c0c83c0;
case 0x0c0c83c2u: goto P_0c0c83c2;
case 0x0c0c83c4u: goto P_0c0c83c4;
case 0x0c0c83c6u: goto P_0c0c83c6;
case 0x0c0c83c8u: goto P_0c0c83c8;
case 0x0c0c83cau: goto P_0c0c83ca;
case 0x0c0c83ccu: goto P_0c0c83cc;
case 0x0c0c83ceu: goto P_0c0c83ce;
case 0x0c0c83d0u: goto P_0c0c83d0;
case 0x0c0c83d2u: goto P_0c0c83d2;
case 0x0c0c83d4u: goto P_0c0c83d4;
case 0x0c0c83d6u: goto P_0c0c83d6;
case 0x0c0c83d8u: goto P_0c0c83d8;
case 0x0c0c83dau: goto P_0c0c83da;
case 0x0c0c83dcu: goto P_0c0c83dc;
case 0x0c0c83deu: goto P_0c0c83de;
case 0x0c0c83e0u: goto P_0c0c83e0;
case 0x0c0c83e2u: goto P_0c0c83e2;
case 0x0c0c83e4u: goto P_0c0c83e4;
case 0x0c0c83e6u: goto P_0c0c83e6;
case 0x0c0c83e8u: goto P_0c0c83e8;
case 0x0c0c83eau: goto P_0c0c83ea;
case 0x0c0c83ecu: goto P_0c0c83ec;
case 0x0c0c83eeu: goto P_0c0c83ee;
case 0x0c0c83f0u: goto P_0c0c83f0;
case 0x0c0c83f2u: goto P_0c0c83f2;
case 0x0c0c83f4u: goto P_0c0c83f4;
case 0x0c0c83f6u: goto P_0c0c83f6;
case 0x0c0c83f8u: goto P_0c0c83f8;
case 0x0c0c83fau: goto P_0c0c83fa;
case 0x0c0c83fcu: goto P_0c0c83fc;
case 0x0c0c83feu: goto P_0c0c83fe;
case 0x0c0c8400u: goto P_0c0c8400;
case 0x0c0c8402u: goto P_0c0c8402;
case 0x0c0c8404u: goto P_0c0c8404;
case 0x0c0c8406u: goto P_0c0c8406;
case 0x0c0c8408u: goto P_0c0c8408;
case 0x0c0c840au: goto P_0c0c840a;
case 0x0c0c840cu: goto P_0c0c840c;
case 0x0c0c840eu: goto P_0c0c840e;
case 0x0c0c8410u: goto P_0c0c8410;
case 0x0c0c8412u: goto P_0c0c8412;
case 0x0c0c8414u: goto P_0c0c8414;
case 0x0c0c8416u: goto P_0c0c8416;
case 0x0c0c8418u: goto P_0c0c8418;
case 0x0c0c841au: goto P_0c0c841a;
case 0x0c0c841cu: goto P_0c0c841c;
case 0x0c0c841eu: goto P_0c0c841e;
case 0x0c0c8420u: goto P_0c0c8420;
case 0x0c0c8422u: goto P_0c0c8422;
case 0x0c0c8424u: goto P_0c0c8424;
case 0x0c0c8426u: goto P_0c0c8426;
case 0x0c0c8428u: goto P_0c0c8428;
case 0x0c0c842au: goto P_0c0c842a;
case 0x0c0c842cu: goto P_0c0c842c;
case 0x0c0c842eu: goto P_0c0c842e;
case 0x0c0c8430u: goto P_0c0c8430;
case 0x0c0c8432u: goto P_0c0c8432;
case 0x0c0c8434u: goto P_0c0c8434;
case 0x0c0c8436u: goto P_0c0c8436;
case 0x0c0c8438u: goto P_0c0c8438;
case 0x0c0c843au: goto P_0c0c843a;
case 0x0c0c843cu: goto P_0c0c843c;
case 0x0c0c843eu: goto P_0c0c843e;
case 0x0c0c8440u: goto P_0c0c8440;
case 0x0c0c8442u: goto P_0c0c8442;
case 0x0c0c8444u: goto P_0c0c8444;
case 0x0c0c8446u: goto P_0c0c8446;
case 0x0c0c8448u: goto P_0c0c8448;
case 0x0c0c844au: goto P_0c0c844a;
case 0x0c0c844cu: goto P_0c0c844c;
case 0x0c0c844eu: goto P_0c0c844e;
case 0x0c0c8450u: goto P_0c0c8450;
case 0x0c0c8452u: goto P_0c0c8452;
case 0x0c0c8454u: goto P_0c0c8454;
case 0x0c0c8456u: goto P_0c0c8456;
case 0x0c0c8458u: goto P_0c0c8458;
case 0x0c0c845au: goto P_0c0c845a;
case 0x0c0c845cu: goto P_0c0c845c;
case 0x0c0c845eu: goto P_0c0c845e;
case 0x0c0c8460u: goto P_0c0c8460;
case 0x0c0c8462u: goto P_0c0c8462;
case 0x0c0c8464u: goto P_0c0c8464;
case 0x0c0c8466u: goto P_0c0c8466;
case 0x0c0c8468u: goto P_0c0c8468;
case 0x0c0c846au: goto P_0c0c846a;
case 0x0c0c846cu: goto P_0c0c846c;
case 0x0c0c846eu: goto P_0c0c846e;
case 0x0c0c8470u: goto P_0c0c8470;
case 0x0c0c8472u: goto P_0c0c8472;
case 0x0c0c8494u: goto P_0c0c8494;
case 0x0c0c8496u: goto P_0c0c8496;
case 0x0c0c8498u: goto P_0c0c8498;
case 0x0c0c849au: goto P_0c0c849a;
case 0x0c0c849cu: goto P_0c0c849c;
case 0x0c0c849eu: goto P_0c0c849e;
case 0x0c0c84a0u: goto P_0c0c84a0;
case 0x0c0c84a2u: goto P_0c0c84a2;
case 0x0c0c84a4u: goto P_0c0c84a4;
case 0x0c0c84a6u: goto P_0c0c84a6;
case 0x0c0c84a8u: goto P_0c0c84a8;
case 0x0c0c84aau: goto P_0c0c84aa;
case 0x0c0c84acu: goto P_0c0c84ac;
case 0x0c0c84aeu: goto P_0c0c84ae;
case 0x0c0c84b0u: goto P_0c0c84b0;
case 0x0c0c84b2u: goto P_0c0c84b2;
case 0x0c0c84b4u: goto P_0c0c84b4;
case 0x0c0c84b6u: goto P_0c0c84b6;
case 0x0c0c84b8u: goto P_0c0c84b8;
case 0x0c0c84bau: goto P_0c0c84ba;
case 0x0c0c84bcu: goto P_0c0c84bc;
case 0x0c0c84beu: goto P_0c0c84be;
case 0x0c0c84c0u: goto P_0c0c84c0;
case 0x0c0c84c2u: goto P_0c0c84c2;
case 0x0c0c84c4u: goto P_0c0c84c4;
case 0x0c0c84c6u: goto P_0c0c84c6;
case 0x0c0c84c8u: goto P_0c0c84c8;
case 0x0c0c84cau: goto P_0c0c84ca;
case 0x0c0c84ccu: goto P_0c0c84cc;
case 0x0c0c84ceu: goto P_0c0c84ce;
case 0x0c0c84d0u: goto P_0c0c84d0;
case 0x0c0c84d2u: goto P_0c0c84d2;
case 0x0c0c84d4u: goto P_0c0c84d4;
case 0x0c0c84d6u: goto P_0c0c84d6;
case 0x0c0c84d8u: goto P_0c0c84d8;
case 0x0c0c84dau: goto P_0c0c84da;
case 0x0c0c84dcu: goto P_0c0c84dc;
case 0x0c0c84deu: goto P_0c0c84de;
case 0x0c0c84e0u: goto P_0c0c84e0;
case 0x0c0c84e2u: goto P_0c0c84e2;
case 0x0c0c84e4u: goto P_0c0c84e4;
case 0x0c0c84e6u: goto P_0c0c84e6;
case 0x0c0c84e8u: goto P_0c0c84e8;
case 0x0c0c84eau: goto P_0c0c84ea;
case 0x0c0c84ecu: goto P_0c0c84ec;
case 0x0c0c84eeu: goto P_0c0c84ee;
case 0x0c0c84f0u: goto P_0c0c84f0;
case 0x0c0c84f2u: goto P_0c0c84f2;
case 0x0c0c84f4u: goto P_0c0c84f4;
case 0x0c0c84f6u: goto P_0c0c84f6;
case 0x0c0c84f8u: goto P_0c0c84f8;
case 0x0c0c84fau: goto P_0c0c84fa;
case 0x0c0c84fcu: goto P_0c0c84fc;
case 0x0c0c84feu: goto P_0c0c84fe;
case 0x0c0c8500u: goto P_0c0c8500;
case 0x0c0c8502u: goto P_0c0c8502;
case 0x0c0c8504u: goto P_0c0c8504;
case 0x0c0c8506u: goto P_0c0c8506;
case 0x0c0c8508u: goto P_0c0c8508;
case 0x0c0c850au: goto P_0c0c850a;
case 0x0c0c850cu: goto P_0c0c850c;
case 0x0c0c850eu: goto P_0c0c850e;
case 0x0c0c8510u: goto P_0c0c8510;
case 0x0c0c8512u: goto P_0c0c8512;
case 0x0c0c8514u: goto P_0c0c8514;
case 0x0c0c8516u: goto P_0c0c8516;
case 0x0c0c8518u: goto P_0c0c8518;
case 0x0c0c851au: goto P_0c0c851a;
case 0x0c0c851cu: goto P_0c0c851c;
case 0x0c0c851eu: goto P_0c0c851e;
case 0x0c0c8520u: goto P_0c0c8520;
case 0x0c0c8522u: goto P_0c0c8522;
case 0x0c0c8524u: goto P_0c0c8524;
case 0x0c0c8526u: goto P_0c0c8526;
case 0x0c0c8528u: goto P_0c0c8528;
case 0x0c0c852au: goto P_0c0c852a;
case 0x0c0c852cu: goto P_0c0c852c;
case 0x0c0c852eu: goto P_0c0c852e;
case 0x0c0c8530u: goto P_0c0c8530;
case 0x0c0c8532u: goto P_0c0c8532;
case 0x0c0c8534u: goto P_0c0c8534;
case 0x0c0c8536u: goto P_0c0c8536;
case 0x0c0c8538u: goto P_0c0c8538;
case 0x0c0c853au: goto P_0c0c853a;
case 0x0c0c853cu: goto P_0c0c853c;
case 0x0c0c853eu: goto P_0c0c853e;
case 0x0c0c8540u: goto P_0c0c8540;
case 0x0c0c8542u: goto P_0c0c8542;
case 0x0c0c8544u: goto P_0c0c8544;
case 0x0c0c8546u: goto P_0c0c8546;
case 0x0c0c8548u: goto P_0c0c8548;
case 0x0c0c854au: goto P_0c0c854a;
case 0x0c0c854cu: goto P_0c0c854c;
case 0x0c0c854eu: goto P_0c0c854e;
case 0x0c0c8550u: goto P_0c0c8550;
case 0x0c0c8552u: goto P_0c0c8552;
case 0x0c0c8554u: goto P_0c0c8554;
case 0x0c0c8574u: goto P_0c0c8574;
case 0x0c0c8576u: goto P_0c0c8576;
case 0x0c0c8578u: goto P_0c0c8578;
case 0x0c0c857au: goto P_0c0c857a;
case 0x0c0c857cu: goto P_0c0c857c;
case 0x0c0c857eu: goto P_0c0c857e;
case 0x0c0c8580u: goto P_0c0c8580;
case 0x0c0c8582u: goto P_0c0c8582;
case 0x0c0c8584u: goto P_0c0c8584;
case 0x0c0c8586u: goto P_0c0c8586;
case 0x0c0c8588u: goto P_0c0c8588;
case 0x0c0c858au: goto P_0c0c858a;
case 0x0c0c858cu: goto P_0c0c858c;
case 0x0c0c858eu: goto P_0c0c858e;
case 0x0c0c8590u: goto P_0c0c8590;
case 0x0c0c8592u: goto P_0c0c8592;
case 0x0c0c8594u: goto P_0c0c8594;
case 0x0c0c8596u: goto P_0c0c8596;
case 0x0c0c8598u: goto P_0c0c8598;
case 0x0c0c859au: goto P_0c0c859a;
case 0x0c0c859cu: goto P_0c0c859c;
case 0x0c0c859eu: goto P_0c0c859e;
case 0x0c0c85a0u: goto P_0c0c85a0;
case 0x0c0c85a2u: goto P_0c0c85a2;
case 0x0c0c85a4u: goto P_0c0c85a4;
case 0x0c0c85a6u: goto P_0c0c85a6;
case 0x0c0c85a8u: goto P_0c0c85a8;
case 0x0c0c85aau: goto P_0c0c85aa;
case 0x0c0c85acu: goto P_0c0c85ac;
case 0x0c0c85aeu: goto P_0c0c85ae;
case 0x0c0c85b0u: goto P_0c0c85b0;
case 0x0c0c85b2u: goto P_0c0c85b2;
case 0x0c0c85b4u: goto P_0c0c85b4;
case 0x0c0c85b6u: goto P_0c0c85b6;
case 0x0c0c85b8u: goto P_0c0c85b8;
case 0x0c0c85bau: goto P_0c0c85ba;
case 0x0c0c85bcu: goto P_0c0c85bc;
case 0x0c0c85beu: goto P_0c0c85be;
case 0x0c0c85c0u: goto P_0c0c85c0;
case 0x0c0c85c2u: goto P_0c0c85c2;
case 0x0c0c85c4u: goto P_0c0c85c4;
case 0x0c0c85c6u: goto P_0c0c85c6;
case 0x0c0c85c8u: goto P_0c0c85c8;
case 0x0c0c85cau: goto P_0c0c85ca;
case 0x0c0c85ccu: goto P_0c0c85cc;
case 0x0c0c85ceu: goto P_0c0c85ce;
case 0x0c0c85d0u: goto P_0c0c85d0;
case 0x0c0c85d2u: goto P_0c0c85d2;
case 0x0c0c85d4u: goto P_0c0c85d4;
case 0x0c0c85d6u: goto P_0c0c85d6;
case 0x0c0c85d8u: goto P_0c0c85d8;
case 0x0c0c85dau: goto P_0c0c85da;
case 0x0c0c85dcu: goto P_0c0c85dc;
case 0x0c0c85deu: goto P_0c0c85de;
case 0x0c0c85e0u: goto P_0c0c85e0;
case 0x0c0c85e2u: goto P_0c0c85e2;
case 0x0c0c85e4u: goto P_0c0c85e4;
case 0x0c0c85e6u: goto P_0c0c85e6;
case 0x0c0c85e8u: goto P_0c0c85e8;
case 0x0c0c85eau: goto P_0c0c85ea;
case 0x0c0c85ecu: goto P_0c0c85ec;
case 0x0c0c85eeu: goto P_0c0c85ee;
case 0x0c0c85f0u: goto P_0c0c85f0;
case 0x0c0c85f2u: goto P_0c0c85f2;
case 0x0c0c85f4u: goto P_0c0c85f4;
case 0x0c0c85f6u: goto P_0c0c85f6;
case 0x0c0c85f8u: goto P_0c0c85f8;
case 0x0c0c85fau: goto P_0c0c85fa;
case 0x0c0c85fcu: goto P_0c0c85fc;
case 0x0c0c85feu: goto P_0c0c85fe;
case 0x0c0c8600u: goto P_0c0c8600;
case 0x0c0c8602u: goto P_0c0c8602;
case 0x0c0c8604u: goto P_0c0c8604;
case 0x0c0c8606u: goto P_0c0c8606;
case 0x0c0c8608u: goto P_0c0c8608;
case 0x0c0c860au: goto P_0c0c860a;
case 0x0c0c860cu: goto P_0c0c860c;
case 0x0c0c860eu: goto P_0c0c860e;
case 0x0c0c8610u: goto P_0c0c8610;
case 0x0c0c8612u: goto P_0c0c8612;
case 0x0c0c8614u: goto P_0c0c8614;
case 0x0c0c8616u: goto P_0c0c8616;
case 0x0c0c8618u: goto P_0c0c8618;
case 0x0c0c861au: goto P_0c0c861a;
case 0x0c0c861cu: goto P_0c0c861c;
case 0x0c0c861eu: goto P_0c0c861e;
case 0x0c0c8620u: goto P_0c0c8620;
case 0x0c0c8622u: goto P_0c0c8622;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c8268: /* original 2fe6, guest PC 0x0c0c8268 */
if(!s->budget--) { s->failed_pc=0x0c0c8268u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c826a;
P_0c0c826a: /* original e061, guest PC 0x0c0c826a */
if(!s->budget--) { s->failed_pc=0x0c0c826au; return 0; }
r[0]=0x00000061u;
goto P_0c0c826c;
P_0c0c826c: /* original 2fd6, guest PC 0x0c0c826c */
if(!s->budget--) { s->failed_pc=0x0c0c826cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c826e;
P_0c0c826e: /* original 2fc6, guest PC 0x0c0c826e */
if(!s->budget--) { s->failed_pc=0x0c0c826eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8270;
P_0c0c8270: /* original 2fb6, guest PC 0x0c0c8270 */
if(!s->budget--) { s->failed_pc=0x0c0c8270u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8272;
P_0c0c8272: /* original eb00, guest PC 0x0c0c8272 */
if(!s->budget--) { s->failed_pc=0x0c0c8272u; return 0; }
r[11]=0x00000000u;
goto P_0c0c8274;
P_0c0c8274: /* original 4f22, guest PC 0x0c0c8274 */
if(!s->budget--) { s->failed_pc=0x0c0c8274u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8276;
P_0c0c8276: /* original d340, guest PC 0x0c0c8276 */
if(!s->budget--) { s->failed_pc=0x0c0c8276u; return 0; }
r[3]=read(ram,0x0c0c8378u,4);
goto P_0c0c8278;
P_0c0c8278: /* original 67b3, guest PC 0x0c0c8278 */
if(!s->budget--) { s->failed_pc=0x0c0c8278u; return 0; }
r[7]=r[11];
goto P_0c0c827a;
P_0c0c827a: /* original de3e, guest PC 0x0c0c827a */
if(!s->budget--) { s->failed_pc=0x0c0c827au; return 0; }
r[14]=read(ram,0x0c0c8374u,4);
goto P_0c0c827c;
P_0c0c827c: /* original 7ff4, guest PC 0x0c0c827c */
if(!s->budget--) { s->failed_pc=0x0c0c827cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c827e;
P_0c0c827e: /* original 1f32, guest PC 0x0c0c827e */
if(!s->budget--) { s->failed_pc=0x0c0c827eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c8280;
P_0c0c8280: /* original 66e3, guest PC 0x0c0c8280 */
if(!s->budget--) { s->failed_pc=0x0c0c8280u; return 0; }
r[6]=r[14];
goto P_0c0c8282;
P_0c0c8282: /* original d53e, guest PC 0x0c0c8282 */
if(!s->budget--) { s->failed_pc=0x0c0c8282u; return 0; }
r[5]=read(ram,0x0c0c837cu,4);
goto P_0c0c8284;
P_0c0c8284: /* original 7658, guest PC 0x0c0c8284 */
if(!s->budget--) { s->failed_pc=0x0c0c8284u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c8286;
P_0c0c8286: /* original 5454, guest PC 0x0c0c8286 */
if(!s->budget--) { s->failed_pc=0x0c0c8286u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c8288;
P_0c0c8288: /* original 034c, guest PC 0x0c0c8288 */
if(!s->budget--) { s->failed_pc=0x0c0c8288u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c828a;
P_0c0c828a: /* original e061, guest PC 0x0c0c828a */
if(!s->budget--) { s->failed_pc=0x0c0c828au; return 0; }
r[0]=0x00000061u;
goto P_0c0c828c;
P_0c0c828c: /* original 633c, guest PC 0x0c0c828c */
if(!s->budget--) { s->failed_pc=0x0c0c828cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c828e;
P_0c0c828e: /* original 2f32, guest PC 0x0c0c828e */
if(!s->budget--) { s->failed_pc=0x0c0c828eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c8290;
P_0c0c8290: /* original 5455, guest PC 0x0c0c8290 */
if(!s->budget--) { s->failed_pc=0x0c0c8290u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0c8292;
P_0c0c8292: /* original 034c, guest PC 0x0c0c8292 */
if(!s->budget--) { s->failed_pc=0x0c0c8292u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c8294;
P_0c0c8294: /* original 633c, guest PC 0x0c0c8294 */
if(!s->budget--) { s->failed_pc=0x0c0c8294u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c8296;
P_0c0c8296: /* original 1f31, guest PC 0x0c0c8296 */
if(!s->budget--) { s->failed_pc=0x0c0c8296u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c8298;
P_0c0c8298: /* original dc39, guest PC 0x0c0c8298 */
if(!s->budget--) { s->failed_pc=0x0c0c8298u; return 0; }
r[12]=read(ram,0x0c0c8380u,4);
goto P_0c0c829a;
P_0c0c829a: /* original 2fb6, guest PC 0x0c0c829a */
if(!s->budget--) { s->failed_pc=0x0c0c829au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c829c;
P_0c0c829c: /* original 9360, guest PC 0x0c0c829c */
if(!s->budget--) { s->failed_pc=0x0c0c829cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8360u,2);
goto P_0c0c829e;
P_0c0c829e: /* original 55f1, guest PC 0x0c0c829e */
if(!s->budget--) { s->failed_pc=0x0c0c829eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c82a0;
P_0c0c82a0: /* original 945f, guest PC 0x0c0c82a0 */
if(!s->budget--) { s->failed_pc=0x0c0c82a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8362u,2);
goto P_0c0c82a2;
P_0c0c82a2: /* original 4c0b, guest PC 0x0c0c82a2 */
if(!s->budget--) { s->failed_pc=0x0c0c82a2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c82a6u;
r[5]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c82a6u) { target=s->pc; goto dispatch; }
goto P_0c0c82a6;
P_0c0c82a4: /* original 353c, guest PC 0x0c0c82a4 */
if(!s->budget--) { s->failed_pc=0x0c0c82a4u; return 0; }
r[5]+=r[3];
goto P_0c0c82a6;
P_0c0c82a6: /* original 2fb6, guest PC 0x0c0c82a6 */
if(!s->budget--) { s->failed_pc=0x0c0c82a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c82a8;
P_0c0c82a8: /* original 66e3, guest PC 0x0c0c82a8 */
if(!s->budget--) { s->failed_pc=0x0c0c82a8u; return 0; }
r[6]=r[14];
goto P_0c0c82aa;
P_0c0c82aa: /* original 55f3, guest PC 0x0c0c82aa */
if(!s->budget--) { s->failed_pc=0x0c0c82aau; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c0c82ac;
P_0c0c82ac: /* original 67b3, guest PC 0x0c0c82ac */
if(!s->budget--) { s->failed_pc=0x0c0c82acu; return 0; }
r[7]=r[11];
goto P_0c0c82ae;
P_0c0c82ae: /* original 9357, guest PC 0x0c0c82ae */
if(!s->budget--) { s->failed_pc=0x0c0c82aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8360u,2);
goto P_0c0c82b0;
P_0c0c82b0: /* original 7658, guest PC 0x0c0c82b0 */
if(!s->budget--) { s->failed_pc=0x0c0c82b0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c82b2;
P_0c0c82b2: /* original 9457, guest PC 0x0c0c82b2 */
if(!s->budget--) { s->failed_pc=0x0c0c82b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8364u,2);
goto P_0c0c82b4;
P_0c0c82b4: /* original 4c0b, guest PC 0x0c0c82b4 */
if(!s->budget--) { s->failed_pc=0x0c0c82b4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c82b8u;
r[5]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c82b8u) { target=s->pc; goto dispatch; }
goto P_0c0c82b8;
P_0c0c82b6: /* original 353c, guest PC 0x0c0c82b6 */
if(!s->budget--) { s->failed_pc=0x0c0c82b6u; return 0; }
r[5]+=r[3];
goto P_0c0c82b8;
P_0c0c82b8: /* original 7f08, guest PC 0x0c0c82b8 */
if(!s->budget--) { s->failed_pc=0x0c0c82b8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c82ba;
P_0c0c82ba: /* original 9155, guest PC 0x0c0c82ba */
if(!s->budget--) { s->failed_pc=0x0c0c82bau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8368u,2);
goto P_0c0c82bc;
P_0c0c82bc: /* original 50f2, guest PC 0x0c0c82bc */
if(!s->budget--) { s->failed_pc=0x0c0c82bcu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c0c82be;
P_0c0c82be: /* original 9d52, guest PC 0x0c0c82be */
if(!s->budget--) { s->failed_pc=0x0c0c82beu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8366u,2);
goto P_0c0c82c0;
P_0c0c82c0: /* original 001c, guest PC 0x0c0c82c0 */
if(!s->budget--) { s->failed_pc=0x0c0c82c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c82c2;
P_0c0c82c2: /* original 8801, guest PC 0x0c0c82c2 */
if(!s->budget--) { s->failed_pc=0x0c0c82c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c82c4;
P_0c0c82c4: /* original 8f01, guest PC 0x0c0c82c4 */
if(!s->budget--) { s->failed_pc=0x0c0c82c4u; return 0; }
cond=r[17]&1u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(!cond) { goto P_0c0c82ca; }
goto P_0c0c82c8;
P_0c0c82c6: /* original 2fb6, guest PC 0x0c0c82c6 */
if(!s->budget--) { s->failed_pc=0x0c0c82c6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c82c8;
P_0c0c82c8: /* original 9d4f, guest PC 0x0c0c82c8 */
if(!s->budget--) { s->failed_pc=0x0c0c82c8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c836au,2);
goto P_0c0c82ca;
P_0c0c82ca: /* original 954f, guest PC 0x0c0c82ca */
if(!s->budget--) { s->failed_pc=0x0c0c82cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c836cu,2);
goto P_0c0c82cc;
P_0c0c82cc: /* original 66e3, guest PC 0x0c0c82cc */
if(!s->budget--) { s->failed_pc=0x0c0c82ccu; return 0; }
r[6]=r[14];
goto P_0c0c82ce;
P_0c0c82ce: /* original e700, guest PC 0x0c0c82ce */
if(!s->budget--) { s->failed_pc=0x0c0c82ceu; return 0; }
r[7]=0x00000000u;
goto P_0c0c82d0;
P_0c0c82d0: /* original 4c0b, guest PC 0x0c0c82d0 */
if(!s->budget--) { s->failed_pc=0x0c0c82d0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0c82d4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c82d4u) { target=s->pc; goto dispatch; }
goto P_0c0c82d4;
P_0c0c82d2: /* original 64d3, guest PC 0x0c0c82d2 */
if(!s->budget--) { s->failed_pc=0x0c0c82d2u; return 0; }
r[4]=r[13];
goto P_0c0c82d4;
P_0c0c82d4: /* original 7f10, guest PC 0x0c0c82d4 */
if(!s->budget--) { s->failed_pc=0x0c0c82d4u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c82d6;
P_0c0c82d6: /* original 64d3, guest PC 0x0c0c82d6 */
if(!s->budget--) { s->failed_pc=0x0c0c82d6u; return 0; }
r[4]=r[13];
goto P_0c0c82d8;
P_0c0c82d8: /* original 4f26, guest PC 0x0c0c82d8 */
if(!s->budget--) { s->failed_pc=0x0c0c82d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c82da;
P_0c0c82da: /* original 6bf6, guest PC 0x0c0c82da */
if(!s->budget--) { s->failed_pc=0x0c0c82dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c82dc;
P_0c0c82dc: /* original 6cf6, guest PC 0x0c0c82dc */
if(!s->budget--) { s->failed_pc=0x0c0c82dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c82de;
P_0c0c82de: /* original 6df6, guest PC 0x0c0c82de */
if(!s->budget--) { s->failed_pc=0x0c0c82deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c82e0;
P_0c0c82e0: /* original a020, guest PC 0x0c0c82e0 */
if(!s->budget--) { s->failed_pc=0x0c0c82e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c82e2: /* original 6ef6, guest PC 0x0c0c82e2 */
if(!s->budget--) { s->failed_pc=0x0c0c82e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c82e4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c82e4u; return 0; } return 1;
P_0c0c8324: /* original 2fe6, guest PC 0x0c0c8324 */
if(!s->budget--) { s->failed_pc=0x0c0c8324u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8326;
P_0c0c8326: /* original 2fd6, guest PC 0x0c0c8326 */
if(!s->budget--) { s->failed_pc=0x0c0c8326u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8328;
P_0c0c8328: /* original 2fc6, guest PC 0x0c0c8328 */
if(!s->budget--) { s->failed_pc=0x0c0c8328u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832a;
P_0c0c832a: /* original 2fb6, guest PC 0x0c0c832a */
if(!s->budget--) { s->failed_pc=0x0c0c832au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832c;
P_0c0c832c: /* original 2fa6, guest PC 0x0c0c832c */
if(!s->budget--) { s->failed_pc=0x0c0c832cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832e;
P_0c0c832e: /* original 2f96, guest PC 0x0c0c832e */
if(!s->budget--) { s->failed_pc=0x0c0c832eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8330;
P_0c0c8330: /* original 2f86, guest PC 0x0c0c8330 */
if(!s->budget--) { s->failed_pc=0x0c0c8330u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8332;
P_0c0c8332: /* original de14, guest PC 0x0c0c8332 */
if(!s->budget--) { s->failed_pc=0x0c0c8332u; return 0; }
r[14]=read(ram,0x0c0c8384u,4);
goto P_0c0c8334;
P_0c0c8334: /* original 4f22, guest PC 0x0c0c8334 */
if(!s->budget--) { s->failed_pc=0x0c0c8334u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8336;
P_0c0c8336: /* original d310, guest PC 0x0c0c8336 */
if(!s->budget--) { s->failed_pc=0x0c0c8336u; return 0; }
r[3]=read(ram,0x0c0c8378u,4);
goto P_0c0c8338;
P_0c0c8338: /* original dd0e, guest PC 0x0c0c8338 */
if(!s->budget--) { s->failed_pc=0x0c0c8338u; return 0; }
r[13]=read(ram,0x0c0c8374u,4);
goto P_0c0c833a;
P_0c0c833a: /* original 7fe8, guest PC 0x0c0c833a */
if(!s->budget--) { s->failed_pc=0x0c0c833au; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0c833c;
P_0c0c833c: /* original 1f35, guest PC 0x0c0c833c */
if(!s->budget--) { s->failed_pc=0x0c0c833cu; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0c833e;
P_0c0c833e: /* original d213, guest PC 0x0c0c833e */
if(!s->budget--) { s->failed_pc=0x0c0c833eu; return 0; }
r[2]=read(ram,0x0c0c838cu,4);
goto P_0c0c8340;
P_0c0c8340: /* original 1f24, guest PC 0x0c0c8340 */
if(!s->budget--) { s->failed_pc=0x0c0c8340u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0c8342;
P_0c0c8342: /* original 9016, guest PC 0x0c0c8342 */
if(!s->budget--) { s->failed_pc=0x0c0c8342u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8372u,2);
goto P_0c0c8344;
P_0c0c8344: /* original d912, guest PC 0x0c0c8344 */
if(!s->budget--) { s->failed_pc=0x0c0c8344u; return 0; }
r[9]=read(ram,0x0c0c8390u,4);
goto P_0c0c8346;
P_0c0c8346: /* original 04ec, guest PC 0x0c0c8346 */
if(!s->budget--) { s->failed_pc=0x0c0c8346u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8348;
P_0c0c8348: /* original 7001, guest PC 0x0c0c8348 */
if(!s->budget--) { s->failed_pc=0x0c0c8348u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c834a;
P_0c0c834a: /* original 06ec, guest PC 0x0c0c834a */
if(!s->budget--) { s->failed_pc=0x0c0c834au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c834c;
P_0c0c834c: /* original 644c, guest PC 0x0c0c834c */
if(!s->budget--) { s->failed_pc=0x0c0c834cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c834e;
P_0c0c834e: /* original 666c, guest PC 0x0c0c834e */
if(!s->budget--) { s->failed_pc=0x0c0c834eu; return 0; }
r[6]=r[6]&255u;
goto P_0c0c8350;
P_0c0c8350: /* original 6763, guest PC 0x0c0c8350 */
if(!s->budget--) { s->failed_pc=0x0c0c8350u; return 0; }
r[7]=r[6];
goto P_0c0c8352;
P_0c0c8352: /* original 4708, guest PC 0x0c0c8352 */
if(!s->budget--) { s->failed_pc=0x0c0c8352u; return 0; }
r[7]<<=2;
goto P_0c0c8354;
P_0c0c8354: /* original 4700, guest PC 0x0c0c8354 */
if(!s->budget--) { s->failed_pc=0x0c0c8354u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c8356;
P_0c0c8356: /* original 2448, guest PC 0x0c0c8356 */
if(!s->budget--) { s->failed_pc=0x0c0c8356u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c8358;
P_0c0c8358: /* original 891c, guest PC 0x0c0c8358 */
if(!s->budget--) { s->failed_pc=0x0c0c8358u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8394; }
goto P_0c0c835a;
P_0c0c835a: /* original 6573, guest PC 0x0c0c835a */
if(!s->budget--) { s->failed_pc=0x0c0c835au; return 0; }
r[5]=r[7];
goto P_0c0c835c;
P_0c0c835c: /* original a01c, guest PC 0x0c0c835c */
if(!s->budget--) { s->failed_pc=0x0c0c835cu; return 0; }
r[5]+=0x00000003u;
goto P_0c0c8398;
P_0c0c835e: /* original 7503, guest PC 0x0c0c835e */
if(!s->budget--) { s->failed_pc=0x0c0c835eu; return 0; }
r[5]+=0x00000003u;
if(!vf3_matrix_family(0x0c0c8360u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8360u; return 0; } return 1;
P_0c0c8394: /* original 6573, guest PC 0x0c0c8394 */
if(!s->budget--) { s->failed_pc=0x0c0c8394u; return 0; }
r[5]=r[7];
goto P_0c0c8396;
P_0c0c8396: /* original 7507, guest PC 0x0c0c8396 */
if(!s->budget--) { s->failed_pc=0x0c0c8396u; return 0; }
r[5]+=0x00000007u;
goto P_0c0c8398;
P_0c0c8398: /* original 6243, guest PC 0x0c0c8398 */
if(!s->budget--) { s->failed_pc=0x0c0c8398u; return 0; }
r[2]=r[4];
goto P_0c0c839a;
P_0c0c839a: /* original 6343, guest PC 0x0c0c839a */
if(!s->budget--) { s->failed_pc=0x0c0c839au; return 0; }
r[3]=r[4];
goto P_0c0c839c;
P_0c0c839c: /* original 6743, guest PC 0x0c0c839c */
if(!s->budget--) { s->failed_pc=0x0c0c839cu; return 0; }
r[7]=r[4];
goto P_0c0c839e;
P_0c0c839e: /* original 4208, guest PC 0x0c0c839e */
if(!s->budget--) { s->failed_pc=0x0c0c839eu; return 0; }
r[2]<<=2;
goto P_0c0c83a0;
P_0c0c83a0: /* original 4708, guest PC 0x0c0c83a0 */
if(!s->budget--) { s->failed_pc=0x0c0c83a0u; return 0; }
r[7]<<=2;
goto P_0c0c83a2;
P_0c0c83a2: /* original 4700, guest PC 0x0c0c83a2 */
if(!s->budget--) { s->failed_pc=0x0c0c83a2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c83a4;
P_0c0c83a4: /* original 4400, guest PC 0x0c0c83a4 */
if(!s->budget--) { s->failed_pc=0x0c0c83a4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c83a6;
P_0c0c83a6: /* original 342c, guest PC 0x0c0c83a6 */
if(!s->budget--) { s->failed_pc=0x0c0c83a6u; return 0; }
r[4]+=r[2];
goto P_0c0c83a8;
P_0c0c83a8: /* original 3738, guest PC 0x0c0c83a8 */
if(!s->budget--) { s->failed_pc=0x0c0c83a8u; return 0; }
r[7]-=r[3];
goto P_0c0c83aa;
P_0c0c83aa: /* original 346c, guest PC 0x0c0c83aa */
if(!s->budget--) { s->failed_pc=0x0c0c83aau; return 0; }
r[4]+=r[6];
goto P_0c0c83ac;
P_0c0c83ac: /* original 6343, guest PC 0x0c0c83ac */
if(!s->budget--) { s->failed_pc=0x0c0c83acu; return 0; }
r[3]=r[4];
goto P_0c0c83ae;
P_0c0c83ae: /* original 4300, guest PC 0x0c0c83ae */
if(!s->budget--) { s->failed_pc=0x0c0c83aeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c83b0;
P_0c0c83b0: /* original e107, guest PC 0x0c0c83b0 */
if(!s->budget--) { s->failed_pc=0x0c0c83b0u; return 0; }
r[1]=0x00000007u;
goto P_0c0c83b2;
P_0c0c83b2: /* original 1f42, guest PC 0x0c0c83b2 */
if(!s->budget--) { s->failed_pc=0x0c0c83b2u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0c83b4;
P_0c0c83b4: /* original 4500, guest PC 0x0c0c83b4 */
if(!s->budget--) { s->failed_pc=0x0c0c83b4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c83b6;
P_0c0c83b6: /* original 1f31, guest PC 0x0c0c83b6 */
if(!s->budget--) { s->failed_pc=0x0c0c83b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c83b8;
P_0c0c83b8: /* original d031, guest PC 0x0c0c83b8 */
if(!s->budget--) { s->failed_pc=0x0c0c83b8u; return 0; }
r[0]=read(ram,0x0c0c8480u,4);
goto P_0c0c83ba;
P_0c0c83ba: /* original 7721, guest PC 0x0c0c83ba */
if(!s->budget--) { s->failed_pc=0x0c0c83bau; return 0; }
r[7]+=0x00000021u;
goto P_0c0c83bc;
P_0c0c83bc: /* original 6a53, guest PC 0x0c0c83bc */
if(!s->budget--) { s->failed_pc=0x0c0c83bcu; return 0; }
r[10]=r[5];
goto P_0c0c83be;
P_0c0c83be: /* original 471c, guest PC 0x0c0c83be */
if(!s->budget--) { s->failed_pc=0x0c0c83beu; return 0; }
r[7]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[7]>>((-r[1])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[1]&31u);
goto P_0c0c83c0;
P_0c0c83c0: /* original 023d, guest PC 0x0c0c83c0 */
if(!s->budget--) { s->failed_pc=0x0c0c83c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c83c2;
P_0c0c83c2: /* original 2a7b, guest PC 0x0c0c83c2 */
if(!s->budget--) { s->failed_pc=0x0c0c83c2u; return 0; }
r[10]|=r[7];
goto P_0c0c83c4;
P_0c0c83c4: /* original 622d, guest PC 0x0c0c83c4 */
if(!s->budget--) { s->failed_pc=0x0c0c83c4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c83c6;
P_0c0c83c6: /* original 1f23, guest PC 0x0c0c83c6 */
if(!s->budget--) { s->failed_pc=0x0c0c83c6u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c83c8;
P_0c0c83c8: /* original 9054, guest PC 0x0c0c83c8 */
if(!s->budget--) { s->failed_pc=0x0c0c83c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8474u,2);
goto P_0c0c83ca;
P_0c0c83ca: /* original 0ea6, guest PC 0x0c0c83ca */
if(!s->budget--) { s->failed_pc=0x0c0c83cau; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0c83cc;
P_0c0c83cc: /* original 9353, guest PC 0x0c0c83cc */
if(!s->budget--) { s->failed_pc=0x0c0c83ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8476u,2);
goto P_0c0c83ce;
P_0c0c83ce: /* original 2f32, guest PC 0x0c0c83ce */
if(!s->budget--) { s->failed_pc=0x0c0c83ceu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c83d0;
P_0c0c83d0: /* original 50f5, guest PC 0x0c0c83d0 */
if(!s->budget--) { s->failed_pc=0x0c0c83d0u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c0c83d2;
P_0c0c83d2: /* original 9251, guest PC 0x0c0c83d2 */
if(!s->budget--) { s->failed_pc=0x0c0c83d2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8478u,2);
goto P_0c0c83d4;
P_0c0c83d4: /* original 002c, guest PC 0x0c0c83d4 */
if(!s->budget--) { s->failed_pc=0x0c0c83d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0c83d6;
P_0c0c83d6: /* original 8801, guest PC 0x0c0c83d6 */
if(!s->budget--) { s->failed_pc=0x0c0c83d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c83d8;
P_0c0c83d8: /* original 8b01, guest PC 0x0c0c83d8 */
if(!s->budget--) { s->failed_pc=0x0c0c83d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c83de; }
goto P_0c0c83da;
P_0c0c83da: /* original 904e, guest PC 0x0c0c83da */
if(!s->budget--) { s->failed_pc=0x0c0c83dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847au,2);
goto P_0c0c83dc;
P_0c0c83dc: /* original 2f02, guest PC 0x0c0c83dc */
if(!s->budget--) { s->failed_pc=0x0c0c83dcu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c83de;
P_0c0c83de: /* original 904d, guest PC 0x0c0c83de */
if(!s->budget--) { s->failed_pc=0x0c0c83deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847cu,2);
goto P_0c0c83e0;
P_0c0c83e0: /* original db29, guest PC 0x0c0c83e0 */
if(!s->budget--) { s->failed_pc=0x0c0c83e0u; return 0; }
r[11]=read(ram,0x0c0c8488u,4);
goto P_0c0c83e2;
P_0c0c83e2: /* original 00ec, guest PC 0x0c0c83e2 */
if(!s->budget--) { s->failed_pc=0x0c0c83e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c83e4;
P_0c0c83e4: /* original d827, guest PC 0x0c0c83e4 */
if(!s->budget--) { s->failed_pc=0x0c0c83e4u; return 0; }
r[8]=read(ram,0x0c0c8484u,4);
goto P_0c0c83e6;
P_0c0c83e6: /* original 600c, guest PC 0x0c0c83e6 */
if(!s->budget--) { s->failed_pc=0x0c0c83e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c83e8;
P_0c0c83e8: /* original 8801, guest PC 0x0c0c83e8 */
if(!s->budget--) { s->failed_pc=0x0c0c83e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c83ea;
P_0c0c83ea: /* original 8d04, guest PC 0x0c0c83ea */
if(!s->budget--) { s->failed_pc=0x0c0c83eau; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c0c83f6; }
goto P_0c0c83ee;
P_0c0c83ec: /* original ec00, guest PC 0x0c0c83ec */
if(!s->budget--) { s->failed_pc=0x0c0c83ecu; return 0; }
r[12]=0x00000000u;
goto P_0c0c83ee;
P_0c0c83ee: /* original 50f4, guest PC 0x0c0c83ee */
if(!s->budget--) { s->failed_pc=0x0c0c83eeu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c83f0;
P_0c0c83f0: /* original 6002, guest PC 0x0c0c83f0 */
if(!s->budget--) { s->failed_pc=0x0c0c83f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0c83f2;
P_0c0c83f2: /* original c808, guest PC 0x0c0c83f2 */
if(!s->budget--) { s->failed_pc=0x0c0c83f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0c83f4;
P_0c0c83f4: /* original 8b0d, guest PC 0x0c0c83f4 */
if(!s->budget--) { s->failed_pc=0x0c0c83f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8412; }
goto P_0c0c83f6;
P_0c0c83f6: /* original 2fc6, guest PC 0x0c0c83f6 */
if(!s->budget--) { s->failed_pc=0x0c0c83f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c83f8;
P_0c0c83f8: /* original 66d3, guest PC 0x0c0c83f8 */
if(!s->budget--) { s->failed_pc=0x0c0c83f8u; return 0; }
r[6]=r[13];
goto P_0c0c83fa;
P_0c0c83fa: /* original 55f1, guest PC 0x0c0c83fa */
if(!s->budget--) { s->failed_pc=0x0c0c83fau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c83fc;
P_0c0c83fc: /* original e700, guest PC 0x0c0c83fc */
if(!s->budget--) { s->failed_pc=0x0c0c83fcu; return 0; }
r[7]=0x00000000u;
goto P_0c0c83fe;
P_0c0c83fe: /* original 4b0b, guest PC 0x0c0c83fe */
if(!s->budget--) { s->failed_pc=0x0c0c83feu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c8402u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8402u) { target=s->pc; goto dispatch; }
goto P_0c0c8402;
P_0c0c8400: /* original 64a3, guest PC 0x0c0c8400 */
if(!s->budget--) { s->failed_pc=0x0c0c8400u; return 0; }
r[4]=r[10];
goto P_0c0c8402;
P_0c0c8402: /* original 2fc6, guest PC 0x0c0c8402 */
if(!s->budget--) { s->failed_pc=0x0c0c8402u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8404;
P_0c0c8404: /* original 66d3, guest PC 0x0c0c8404 */
if(!s->budget--) { s->failed_pc=0x0c0c8404u; return 0; }
r[6]=r[13];
goto P_0c0c8406;
P_0c0c8406: /* original 55f5, guest PC 0x0c0c8406 */
if(!s->budget--) { s->failed_pc=0x0c0c8406u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0c8408;
P_0c0c8408: /* original e700, guest PC 0x0c0c8408 */
if(!s->budget--) { s->failed_pc=0x0c0c8408u; return 0; }
r[7]=0x00000000u;
goto P_0c0c840a;
P_0c0c840a: /* original 480b, guest PC 0x0c0c840a */
if(!s->budget--) { s->failed_pc=0x0c0c840au; return 0; }
target=r[8];
r[16]=code_base|0x0c0c840eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c840eu) { target=s->pc; goto dispatch; }
goto P_0c0c840e;
P_0c0c840c: /* original 64a3, guest PC 0x0c0c840c */
if(!s->budget--) { s->failed_pc=0x0c0c840cu; return 0; }
r[4]=r[10];
goto P_0c0c840e;
P_0c0c840e: /* original a00c, guest PC 0x0c0c840e */
if(!s->budget--) { s->failed_pc=0x0c0c840eu; return 0; }
goto P_0c0c842a;
P_0c0c8410: /* original 0009, guest PC 0x0c0c8410 */
if(!s->budget--) { s->failed_pc=0x0c0c8410u; return 0; }
goto P_0c0c8412;
P_0c0c8412: /* original 2fc6, guest PC 0x0c0c8412 */
if(!s->budget--) { s->failed_pc=0x0c0c8412u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8414;
P_0c0c8414: /* original 66d3, guest PC 0x0c0c8414 */
if(!s->budget--) { s->failed_pc=0x0c0c8414u; return 0; }
r[6]=r[13];
goto P_0c0c8416;
P_0c0c8416: /* original 55f1, guest PC 0x0c0c8416 */
if(!s->budget--) { s->failed_pc=0x0c0c8416u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c8418;
P_0c0c8418: /* original e700, guest PC 0x0c0c8418 */
if(!s->budget--) { s->failed_pc=0x0c0c8418u; return 0; }
r[7]=0x00000000u;
goto P_0c0c841a;
P_0c0c841a: /* original 480b, guest PC 0x0c0c841a */
if(!s->budget--) { s->failed_pc=0x0c0c841au; return 0; }
target=r[8];
r[16]=code_base|0x0c0c841eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c841eu) { target=s->pc; goto dispatch; }
goto P_0c0c841e;
P_0c0c841c: /* original 64a3, guest PC 0x0c0c841c */
if(!s->budget--) { s->failed_pc=0x0c0c841cu; return 0; }
r[4]=r[10];
goto P_0c0c841e;
P_0c0c841e: /* original 2fc6, guest PC 0x0c0c841e */
if(!s->budget--) { s->failed_pc=0x0c0c841eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8420;
P_0c0c8420: /* original 66d3, guest PC 0x0c0c8420 */
if(!s->budget--) { s->failed_pc=0x0c0c8420u; return 0; }
r[6]=r[13];
goto P_0c0c8422;
P_0c0c8422: /* original 55f5, guest PC 0x0c0c8422 */
if(!s->budget--) { s->failed_pc=0x0c0c8422u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0c8424;
P_0c0c8424: /* original e700, guest PC 0x0c0c8424 */
if(!s->budget--) { s->failed_pc=0x0c0c8424u; return 0; }
r[7]=0x00000000u;
goto P_0c0c8426;
P_0c0c8426: /* original 4b0b, guest PC 0x0c0c8426 */
if(!s->budget--) { s->failed_pc=0x0c0c8426u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c842au;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c842au) { target=s->pc; goto dispatch; }
goto P_0c0c842a;
P_0c0c8428: /* original 64a3, guest PC 0x0c0c8428 */
if(!s->budget--) { s->failed_pc=0x0c0c8428u; return 0; }
r[4]=r[10];
goto P_0c0c842a;
P_0c0c842a: /* original 7f08, guest PC 0x0c0c842a */
if(!s->budget--) { s->failed_pc=0x0c0c842au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c842c;
P_0c0c842c: /* original d017, guest PC 0x0c0c842c */
if(!s->budget--) { s->failed_pc=0x0c0c842cu; return 0; }
r[0]=read(ram,0x0c0c848cu,4);
goto P_0c0c842e;
P_0c0c842e: /* original 53f1, guest PC 0x0c0c842e */
if(!s->budget--) { s->failed_pc=0x0c0c842eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c8430;
P_0c0c8430: /* original 6a93, guest PC 0x0c0c8430 */
if(!s->budget--) { s->failed_pc=0x0c0c8430u; return 0; }
r[10]=r[9];
goto P_0c0c8432;
P_0c0c8432: /* original 003d, guest PC 0x0c0c8432 */
if(!s->budget--) { s->failed_pc=0x0c0c8432u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c8434;
P_0c0c8434: /* original 88ff, guest PC 0x0c0c8434 */
if(!s->budget--) { s->failed_pc=0x0c0c8434u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c8436;
P_0c0c8436: /* original 8d0f, guest PC 0x0c0c8436 */
if(!s->budget--) { s->failed_pc=0x0c0c8436u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000040u;
if(cond) { goto P_0c0c8458; }
goto P_0c0c843a;
P_0c0c8438: /* original 7a40, guest PC 0x0c0c8438 */
if(!s->budget--) { s->failed_pc=0x0c0c8438u; return 0; }
r[10]+=0x00000040u;
goto P_0c0c843a;
P_0c0c843a: /* original 51f2, guest PC 0x0c0c843a */
if(!s->budget--) { s->failed_pc=0x0c0c843au; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0c843c;
P_0c0c843c: /* original 4108, guest PC 0x0c0c843c */
if(!s->budget--) { s->failed_pc=0x0c0c843cu; return 0; }
r[1]<<=2;
goto P_0c0c843e;
P_0c0c843e: /* original 319c, guest PC 0x0c0c843e */
if(!s->budget--) { s->failed_pc=0x0c0c843eu; return 0; }
r[1]+=r[9];
goto P_0c0c8440;
P_0c0c8440: /* original 2f12, guest PC 0x0c0c8440 */
if(!s->budget--) { s->failed_pc=0x0c0c8440u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c8442;
P_0c0c8442: /* original 2a12, guest PC 0x0c0c8442 */
if(!s->budget--) { s->failed_pc=0x0c0c8442u; return 0; }
write(ram,r[10],r[1],4);
goto P_0c0c8444;
P_0c0c8444: /* original 65f2, guest PC 0x0c0c8444 */
if(!s->budget--) { s->failed_pc=0x0c0c8444u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c8446;
P_0c0c8446: /* original 53f1, guest PC 0x0c0c8446 */
if(!s->budget--) { s->failed_pc=0x0c0c8446u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c8448;
P_0c0c8448: /* original d010, guest PC 0x0c0c8448 */
if(!s->budget--) { s->failed_pc=0x0c0c8448u; return 0; }
r[0]=read(ram,0x0c0c848cu,4);
goto P_0c0c844a;
P_0c0c844a: /* original d211, guest PC 0x0c0c844a */
if(!s->budget--) { s->failed_pc=0x0c0c844au; return 0; }
r[2]=read(ram,0x0c0c8490u,4);
goto P_0c0c844c;
P_0c0c844c: /* original 420b, guest PC 0x0c0c844c */
if(!s->budget--) { s->failed_pc=0x0c0c844cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8450u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8450u) { target=s->pc; goto dispatch; }
goto P_0c0c8450;
P_0c0c844e: /* original 043d, guest PC 0x0c0c844e */
if(!s->budget--) { s->failed_pc=0x0c0c844eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c8450;
P_0c0c8450: /* original 63f2, guest PC 0x0c0c8450 */
if(!s->budget--) { s->failed_pc=0x0c0c8450u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c8452;
P_0c0c8452: /* original 6232, guest PC 0x0c0c8452 */
if(!s->budget--) { s->failed_pc=0x0c0c8452u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0c8454;
P_0c0c8454: /* original 2228, guest PC 0x0c0c8454 */
if(!s->budget--) { s->failed_pc=0x0c0c8454u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c8456;
P_0c0c8456: /* original 891d, guest PC 0x0c0c8456 */
if(!s->budget--) { s->failed_pc=0x0c0c8456u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8494; }
goto P_0c0c8458;
P_0c0c8458: /* original 61a2, guest PC 0x0c0c8458 */
if(!s->budget--) { s->failed_pc=0x0c0c8458u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0c845a;
P_0c0c845a: /* original 2118, guest PC 0x0c0c845a */
if(!s->budget--) { s->failed_pc=0x0c0c845au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c845c;
P_0c0c845c: /* original 891a, guest PC 0x0c0c845c */
if(!s->budget--) { s->failed_pc=0x0c0c845cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8494; }
goto P_0c0c845e;
P_0c0c845e: /* original 64a2, guest PC 0x0c0c845e */
if(!s->budget--) { s->failed_pc=0x0c0c845eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c8460;
P_0c0c8460: /* original 6342, guest PC 0x0c0c8460 */
if(!s->budget--) { s->failed_pc=0x0c0c8460u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0c8462;
P_0c0c8462: /* original 2338, guest PC 0x0c0c8462 */
if(!s->budget--) { s->failed_pc=0x0c0c8462u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c8464;
P_0c0c8464: /* original 8901, guest PC 0x0c0c8464 */
if(!s->budget--) { s->failed_pc=0x0c0c8464u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c846a; }
goto P_0c0c8466;
P_0c0c8466: /* original a015, guest PC 0x0c0c8466 */
if(!s->budget--) { s->failed_pc=0x0c0c8466u; return 0; }
write(ram,r[10],r[12],4);
goto P_0c0c8494;
P_0c0c8468: /* original 2ac2, guest PC 0x0c0c8468 */
if(!s->budget--) { s->failed_pc=0x0c0c8468u; return 0; }
write(ram,r[10],r[12],4);
goto P_0c0c846a;
P_0c0c846a: /* original 9308, guest PC 0x0c0c846a */
if(!s->budget--) { s->failed_pc=0x0c0c846au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847eu,2);
goto P_0c0c846c;
P_0c0c846c: /* original 6033, guest PC 0x0c0c846c */
if(!s->budget--) { s->failed_pc=0x0c0c846cu; return 0; }
r[0]=r[3];
goto P_0c0c846e;
P_0c0c846e: /* original 70d0, guest PC 0x0c0c846e */
if(!s->budget--) { s->failed_pc=0x0c0c846eu; return 0; }
r[0]+=0xffffffd0u;
goto P_0c0c8470;
P_0c0c8470: /* original a0b7, guest PC 0x0c0c8470 */
if(!s->budget--) { s->failed_pc=0x0c0c8470u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c85e2;
P_0c0c8472: /* original 0e34, guest PC 0x0c0c8472 */
if(!s->budget--) { s->failed_pc=0x0c0c8472u; return 0; }
write(ram,r[14]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c0c8474u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8474u; return 0; } return 1;
P_0c0c8494: /* original 905f, guest PC 0x0c0c8494 */
if(!s->budget--) { s->failed_pc=0x0c0c8494u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8556u,2);
goto P_0c0c8496;
P_0c0c8496: /* original 01ec, guest PC 0x0c0c8496 */
if(!s->budget--) { s->failed_pc=0x0c0c8496u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8498;
P_0c0c8498: /* original 70f8, guest PC 0x0c0c8498 */
if(!s->budget--) { s->failed_pc=0x0c0c8498u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c849a;
P_0c0c849a: /* original 03ec, guest PC 0x0c0c849a */
if(!s->budget--) { s->failed_pc=0x0c0c849au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c849c;
P_0c0c849c: /* original 3130, guest PC 0x0c0c849c */
if(!s->budget--) { s->failed_pc=0x0c0c849cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0c849e;
P_0c0c849e: /* original 8939, guest PC 0x0c0c849e */
if(!s->budget--) { s->failed_pc=0x0c0c849eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8514; }
goto P_0c0c84a0;
P_0c0c84a0: /* original 905a, guest PC 0x0c0c84a0 */
if(!s->budget--) { s->failed_pc=0x0c0c84a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c84a2;
P_0c0c84a2: /* original 00ed, guest PC 0x0c0c84a2 */
if(!s->budget--) { s->failed_pc=0x0c0c84a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c84a4;
P_0c0c84a4: /* original 88ff, guest PC 0x0c0c84a4 */
if(!s->budget--) { s->failed_pc=0x0c0c84a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c84a6;
P_0c0c84a6: /* original 8d18, guest PC 0x0c0c84a6 */
if(!s->budget--) { s->failed_pc=0x0c0c84a6u; return 0; }
cond=r[17]&1u;
r[10]=r[0];
if(cond) { goto P_0c0c84da; }
goto P_0c0c84aa;
P_0c0c84a8: /* original 6a03, guest PC 0x0c0c84a8 */
if(!s->budget--) { s->failed_pc=0x0c0c84a8u; return 0; }
r[10]=r[0];
goto P_0c0c84aa;
P_0c0c84aa: /* original e220, guest PC 0x0c0c84aa */
if(!s->budget--) { s->failed_pc=0x0c0c84aau; return 0; }
r[2]=0x00000020u;
goto P_0c0c84ac;
P_0c0c84ac: /* original 64d3, guest PC 0x0c0c84ac */
if(!s->budget--) { s->failed_pc=0x0c0c84acu; return 0; }
r[4]=r[13];
goto P_0c0c84ae;
P_0c0c84ae: /* original 2f26, guest PC 0x0c0c84ae */
if(!s->budget--) { s->failed_pc=0x0c0c84aeu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c84b0;
P_0c0c84b0: /* original 6723, guest PC 0x0c0c84b0 */
if(!s->budget--) { s->failed_pc=0x0c0c84b0u; return 0; }
r[7]=r[2];
goto P_0c0c84b2;
P_0c0c84b2: /* original 9552, guest PC 0x0c0c84b2 */
if(!s->budget--) { s->failed_pc=0x0c0c84b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c84b4;
P_0c0c84b4: /* original e63e, guest PC 0x0c0c84b4 */
if(!s->budget--) { s->failed_pc=0x0c0c84b4u; return 0; }
r[6]=0x0000003eu;
goto P_0c0c84b6;
P_0c0c84b6: /* original d32a, guest PC 0x0c0c84b6 */
if(!s->budget--) { s->failed_pc=0x0c0c84b6u; return 0; }
r[3]=read(ram,0x0c0c8560u,4);
goto P_0c0c84b8;
P_0c0c84b8: /* original 430b, guest PC 0x0c0c84b8 */
if(!s->budget--) { s->failed_pc=0x0c0c84b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c84bcu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84bcu) { target=s->pc; goto dispatch; }
goto P_0c0c84bc;
P_0c0c84ba: /* original 7458, guest PC 0x0c0c84ba */
if(!s->budget--) { s->failed_pc=0x0c0c84bau; return 0; }
r[4]+=0x00000058u;
goto P_0c0c84bc;
P_0c0c84bc: /* original d229, guest PC 0x0c0c84bc */
if(!s->budget--) { s->failed_pc=0x0c0c84bcu; return 0; }
r[2]=read(ram,0x0c0c8564u,4);
goto P_0c0c84be;
P_0c0c84be: /* original 7f04, guest PC 0x0c0c84be */
if(!s->budget--) { s->failed_pc=0x0c0c84beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c84c0;
P_0c0c84c0: /* original 420b, guest PC 0x0c0c84c0 */
if(!s->budget--) { s->failed_pc=0x0c0c84c0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c84c4u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84c4u) { target=s->pc; goto dispatch; }
goto P_0c0c84c4;
P_0c0c84c2: /* original 64a3, guest PC 0x0c0c84c2 */
if(!s->budget--) { s->failed_pc=0x0c0c84c2u; return 0; }
r[4]=r[10];
goto P_0c0c84c4;
P_0c0c84c4: /* original 600d, guest PC 0x0c0c84c4 */
if(!s->budget--) { s->failed_pc=0x0c0c84c4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c84c6;
P_0c0c84c6: /* original 2008, guest PC 0x0c0c84c6 */
if(!s->budget--) { s->failed_pc=0x0c0c84c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c84c8;
P_0c0c84c8: /* original 8907, guest PC 0x0c0c84c8 */
if(!s->budget--) { s->failed_pc=0x0c0c84c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c84da; }
goto P_0c0c84ca;
P_0c0c84ca: /* original 66d3, guest PC 0x0c0c84ca */
if(!s->budget--) { s->failed_pc=0x0c0c84cau; return 0; }
r[6]=r[13];
goto P_0c0c84cc;
P_0c0c84cc: /* original 2fc6, guest PC 0x0c0c84cc */
if(!s->budget--) { s->failed_pc=0x0c0c84ccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c84ce;
P_0c0c84ce: /* original 9444, guest PC 0x0c0c84ce */
if(!s->budget--) { s->failed_pc=0x0c0c84ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c84d0;
P_0c0c84d0: /* original 7658, guest PC 0x0c0c84d0 */
if(!s->budget--) { s->failed_pc=0x0c0c84d0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c84d2;
P_0c0c84d2: /* original e700, guest PC 0x0c0c84d2 */
if(!s->budget--) { s->failed_pc=0x0c0c84d2u; return 0; }
r[7]=0x00000000u;
goto P_0c0c84d4;
P_0c0c84d4: /* original 4b0b, guest PC 0x0c0c84d4 */
if(!s->budget--) { s->failed_pc=0x0c0c84d4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c84d8u;
r[5]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84d8u) { target=s->pc; goto dispatch; }
goto P_0c0c84d8;
P_0c0c84d6: /* original 65a3, guest PC 0x0c0c84d6 */
if(!s->budget--) { s->failed_pc=0x0c0c84d6u; return 0; }
r[5]=r[10];
goto P_0c0c84d8;
P_0c0c84d8: /* original 7f04, guest PC 0x0c0c84d8 */
if(!s->budget--) { s->failed_pc=0x0c0c84d8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c84da;
P_0c0c84da: /* original d023, guest PC 0x0c0c84da */
if(!s->budget--) { s->failed_pc=0x0c0c84dau; return 0; }
r[0]=read(ram,0x0c0c8568u,4);
goto P_0c0c84dc;
P_0c0c84dc: /* original 65d3, guest PC 0x0c0c84dc */
if(!s->budget--) { s->failed_pc=0x0c0c84dcu; return 0; }
r[5]=r[13];
goto P_0c0c84de;
P_0c0c84de: /* original 52f1, guest PC 0x0c0c84de */
if(!s->budget--) { s->failed_pc=0x0c0c84deu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c84e0;
P_0c0c84e0: /* original 7558, guest PC 0x0c0c84e0 */
if(!s->budget--) { s->failed_pc=0x0c0c84e0u; return 0; }
r[5]+=0x00000058u;
goto P_0c0c84e2;
P_0c0c84e2: /* original 032d, guest PC 0x0c0c84e2 */
if(!s->budget--) { s->failed_pc=0x0c0c84e2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0c84e4;
P_0c0c84e4: /* original 9038, guest PC 0x0c0c84e4 */
if(!s->budget--) { s->failed_pc=0x0c0c84e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c84e6;
P_0c0c84e6: /* original 0e35, guest PC 0x0c0c84e6 */
if(!s->budget--) { s->failed_pc=0x0c0c84e6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c84e8;
P_0c0c84e8: /* original e307, guest PC 0x0c0c84e8 */
if(!s->budget--) { s->failed_pc=0x0c0c84e8u; return 0; }
r[3]=0x00000007u;
goto P_0c0c84ea;
P_0c0c84ea: /* original 0aed, guest PC 0x0c0c84ea */
if(!s->budget--) { s->failed_pc=0x0c0c84eau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c84ec;
P_0c0c84ec: /* original 7002, guest PC 0x0c0c84ec */
if(!s->budget--) { s->failed_pc=0x0c0c84ecu; return 0; }
r[0]+=0x00000002u;
goto P_0c0c84ee;
P_0c0c84ee: /* original 0e34, guest PC 0x0c0c84ee */
if(!s->budget--) { s->failed_pc=0x0c0c84eeu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c84f0;
P_0c0c84f0: /* original d31e, guest PC 0x0c0c84f0 */
if(!s->budget--) { s->failed_pc=0x0c0c84f0u; return 0; }
r[3]=read(ram,0x0c0c856cu,4);
goto P_0c0c84f2;
P_0c0c84f2: /* original 430b, guest PC 0x0c0c84f2 */
if(!s->budget--) { s->failed_pc=0x0c0c84f2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c84f6u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84f6u) { target=s->pc; goto dispatch; }
goto P_0c0c84f6;
P_0c0c84f4: /* original 64a3, guest PC 0x0c0c84f4 */
if(!s->budget--) { s->failed_pc=0x0c0c84f4u; return 0; }
r[4]=r[10];
goto P_0c0c84f6;
P_0c0c84f6: /* original d21b, guest PC 0x0c0c84f6 */
if(!s->budget--) { s->failed_pc=0x0c0c84f6u; return 0; }
r[2]=read(ram,0x0c0c8564u,4);
goto P_0c0c84f8;
P_0c0c84f8: /* original 420b, guest PC 0x0c0c84f8 */
if(!s->budget--) { s->failed_pc=0x0c0c84f8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c84fcu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c84fcu) { target=s->pc; goto dispatch; }
goto P_0c0c84fc;
P_0c0c84fa: /* original 64a3, guest PC 0x0c0c84fa */
if(!s->budget--) { s->failed_pc=0x0c0c84fau; return 0; }
r[4]=r[10];
goto P_0c0c84fc;
P_0c0c84fc: /* original 600d, guest PC 0x0c0c84fc */
if(!s->budget--) { s->failed_pc=0x0c0c84fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c84fe;
P_0c0c84fe: /* original 2008, guest PC 0x0c0c84fe */
if(!s->budget--) { s->failed_pc=0x0c0c84feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c8500;
P_0c0c8500: /* original 896f, guest PC 0x0c0c8500 */
if(!s->budget--) { s->failed_pc=0x0c0c8500u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c8502;
P_0c0c8502: /* original 66d3, guest PC 0x0c0c8502 */
if(!s->budget--) { s->failed_pc=0x0c0c8502u; return 0; }
r[6]=r[13];
goto P_0c0c8504;
P_0c0c8504: /* original 2fc6, guest PC 0x0c0c8504 */
if(!s->budget--) { s->failed_pc=0x0c0c8504u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8506;
P_0c0c8506: /* original 9429, guest PC 0x0c0c8506 */
if(!s->budget--) { s->failed_pc=0x0c0c8506u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855cu,2);
goto P_0c0c8508;
P_0c0c8508: /* original 7658, guest PC 0x0c0c8508 */
if(!s->budget--) { s->failed_pc=0x0c0c8508u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c850a;
P_0c0c850a: /* original d719, guest PC 0x0c0c850a */
if(!s->budget--) { s->failed_pc=0x0c0c850au; return 0; }
r[7]=read(ram,0x0c0c8570u,4);
goto P_0c0c850c;
P_0c0c850c: /* original 4b0b, guest PC 0x0c0c850c */
if(!s->budget--) { s->failed_pc=0x0c0c850cu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c8510u;
r[5]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8510u) { target=s->pc; goto dispatch; }
goto P_0c0c8510;
P_0c0c850e: /* original 65a3, guest PC 0x0c0c850e */
if(!s->budget--) { s->failed_pc=0x0c0c850eu; return 0; }
r[5]=r[10];
goto P_0c0c8510;
P_0c0c8510: /* original a067, guest PC 0x0c0c8510 */
if(!s->budget--) { s->failed_pc=0x0c0c8510u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c85e2;
P_0c0c8512: /* original 7f04, guest PC 0x0c0c8512 */
if(!s->budget--) { s->failed_pc=0x0c0c8512u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8514;
P_0c0c8514: /* original 9023, guest PC 0x0c0c8514 */
if(!s->budget--) { s->failed_pc=0x0c0c8514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855eu,2);
goto P_0c0c8516;
P_0c0c8516: /* original 04ec, guest PC 0x0c0c8516 */
if(!s->budget--) { s->failed_pc=0x0c0c8516u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8518;
P_0c0c8518: /* original 4415, guest PC 0x0c0c8518 */
if(!s->budget--) { s->failed_pc=0x0c0c8518u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c851a;
P_0c0c851a: /* original 892b, guest PC 0x0c0c851a */
if(!s->budget--) { s->failed_pc=0x0c0c851au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8574; }
goto P_0c0c851c;
P_0c0c851c: /* original 6a93, guest PC 0x0c0c851c */
if(!s->budget--) { s->failed_pc=0x0c0c851cu; return 0; }
r[10]=r[9];
goto P_0c0c851e;
P_0c0c851e: /* original 7a44, guest PC 0x0c0c851e */
if(!s->budget--) { s->failed_pc=0x0c0c851eu; return 0; }
r[10]+=0x00000044u;
goto P_0c0c8520;
P_0c0c8520: /* original 62a2, guest PC 0x0c0c8520 */
if(!s->budget--) { s->failed_pc=0x0c0c8520u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0c8522;
P_0c0c8522: /* original 2228, guest PC 0x0c0c8522 */
if(!s->budget--) { s->failed_pc=0x0c0c8522u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c8524;
P_0c0c8524: /* original 8904, guest PC 0x0c0c8524 */
if(!s->budget--) { s->failed_pc=0x0c0c8524u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8530; }
goto P_0c0c8526;
P_0c0c8526: /* original d311, guest PC 0x0c0c8526 */
if(!s->budget--) { s->failed_pc=0x0c0c8526u; return 0; }
r[3]=read(ram,0x0c0c856cu,4);
goto P_0c0c8528;
P_0c0c8528: /* original 65d3, guest PC 0x0c0c8528 */
if(!s->budget--) { s->failed_pc=0x0c0c8528u; return 0; }
r[5]=r[13];
goto P_0c0c852a;
P_0c0c852a: /* original 7558, guest PC 0x0c0c852a */
if(!s->budget--) { s->failed_pc=0x0c0c852au; return 0; }
r[5]+=0x00000058u;
goto P_0c0c852c;
P_0c0c852c: /* original 430b, guest PC 0x0c0c852c */
if(!s->budget--) { s->failed_pc=0x0c0c852cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8530u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8530u) { target=s->pc; goto dispatch; }
goto P_0c0c8530;
P_0c0c852e: /* original 64a2, guest PC 0x0c0c852e */
if(!s->budget--) { s->failed_pc=0x0c0c852eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c8530;
P_0c0c8530: /* original 9012, guest PC 0x0c0c8530 */
if(!s->budget--) { s->failed_pc=0x0c0c8530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c8532;
P_0c0c8532: /* original 02ed, guest PC 0x0c0c8532 */
if(!s->budget--) { s->failed_pc=0x0c0c8532u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8534;
P_0c0c8534: /* original 2a22, guest PC 0x0c0c8534 */
if(!s->budget--) { s->failed_pc=0x0c0c8534u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c0c8536;
P_0c0c8536: /* original d30b, guest PC 0x0c0c8536 */
if(!s->budget--) { s->failed_pc=0x0c0c8536u; return 0; }
r[3]=read(ram,0x0c0c8564u,4);
goto P_0c0c8538;
P_0c0c8538: /* original 430b, guest PC 0x0c0c8538 */
if(!s->budget--) { s->failed_pc=0x0c0c8538u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c853cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c853cu) { target=s->pc; goto dispatch; }
goto P_0c0c853c;
P_0c0c853a: /* original 04ed, guest PC 0x0c0c853a */
if(!s->budget--) { s->failed_pc=0x0c0c853au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c853c;
P_0c0c853c: /* original 600d, guest PC 0x0c0c853c */
if(!s->budget--) { s->failed_pc=0x0c0c853cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c853e;
P_0c0c853e: /* original 2008, guest PC 0x0c0c853e */
if(!s->budget--) { s->failed_pc=0x0c0c853eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c8540;
P_0c0c8540: /* original 894f, guest PC 0x0c0c8540 */
if(!s->budget--) { s->failed_pc=0x0c0c8540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c8542;
P_0c0c8542: /* original 66d3, guest PC 0x0c0c8542 */
if(!s->budget--) { s->failed_pc=0x0c0c8542u; return 0; }
r[6]=r[13];
goto P_0c0c8544;
P_0c0c8544: /* original 2fc6, guest PC 0x0c0c8544 */
if(!s->budget--) { s->failed_pc=0x0c0c8544u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8546;
P_0c0c8546: /* original 9007, guest PC 0x0c0c8546 */
if(!s->budget--) { s->failed_pc=0x0c0c8546u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c8548;
P_0c0c8548: /* original e700, guest PC 0x0c0c8548 */
if(!s->budget--) { s->failed_pc=0x0c0c8548u; return 0; }
r[7]=0x00000000u;
goto P_0c0c854a;
P_0c0c854a: /* original 9406, guest PC 0x0c0c854a */
if(!s->budget--) { s->failed_pc=0x0c0c854au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c854c;
P_0c0c854c: /* original 7658, guest PC 0x0c0c854c */
if(!s->budget--) { s->failed_pc=0x0c0c854cu; return 0; }
r[6]+=0x00000058u;
goto P_0c0c854e;
P_0c0c854e: /* original 4b0b, guest PC 0x0c0c854e */
if(!s->budget--) { s->failed_pc=0x0c0c854eu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c8552u;
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8552u) { target=s->pc; goto dispatch; }
goto P_0c0c8552;
P_0c0c8550: /* original 05ed, guest PC 0x0c0c8550 */
if(!s->budget--) { s->failed_pc=0x0c0c8550u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8552;
P_0c0c8552: /* original a046, guest PC 0x0c0c8552 */
if(!s->budget--) { s->failed_pc=0x0c0c8552u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c85e2;
P_0c0c8554: /* original 7f04, guest PC 0x0c0c8554 */
if(!s->budget--) { s->failed_pc=0x0c0c8554u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0c8556u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8556u; return 0; } return 1;
P_0c0c8574: /* original e306, guest PC 0x0c0c8574 */
if(!s->budget--) { s->failed_pc=0x0c0c8574u; return 0; }
r[3]=0x00000006u;
goto P_0c0c8576;
P_0c0c8576: /* original 74ff, guest PC 0x0c0c8576 */
if(!s->budget--) { s->failed_pc=0x0c0c8576u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c8578;
P_0c0c8578: /* original 3348, guest PC 0x0c0c8578 */
if(!s->budget--) { s->failed_pc=0x0c0c8578u; return 0; }
r[3]-=r[4];
goto P_0c0c857a;
P_0c0c857a: /* original 0e44, guest PC 0x0c0c857a */
if(!s->budget--) { s->failed_pc=0x0c0c857au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c857c;
P_0c0c857c: /* original 6433, guest PC 0x0c0c857c */
if(!s->budget--) { s->failed_pc=0x0c0c857cu; return 0; }
r[4]=r[3];
goto P_0c0c857e;
P_0c0c857e: /* original 4408, guest PC 0x0c0c857e */
if(!s->budget--) { s->failed_pc=0x0c0c857eu; return 0; }
r[4]<<=2;
goto P_0c0c8580;
P_0c0c8580: /* original e91b, guest PC 0x0c0c8580 */
if(!s->budget--) { s->failed_pc=0x0c0c8580u; return 0; }
r[9]=0x0000001bu;
goto P_0c0c8582;
P_0c0c8582: /* original 6543, guest PC 0x0c0c8582 */
if(!s->budget--) { s->failed_pc=0x0c0c8582u; return 0; }
r[5]=r[4];
goto P_0c0c8584;
P_0c0c8584: /* original 3948, guest PC 0x0c0c8584 */
if(!s->budget--) { s->failed_pc=0x0c0c8584u; return 0; }
r[9]-=r[4];
goto P_0c0c8586;
P_0c0c8586: /* original d72a, guest PC 0x0c0c8586 */
if(!s->budget--) { s->failed_pc=0x0c0c8586u; return 0; }
r[7]=read(ram,0x0c0c8630u,4);
goto P_0c0c8588;
P_0c0c8588: /* original 7504, guest PC 0x0c0c8588 */
if(!s->budget--) { s->failed_pc=0x0c0c8588u; return 0; }
r[5]+=0x00000004u;
goto P_0c0c858a;
P_0c0c858a: /* original 6693, guest PC 0x0c0c858a */
if(!s->budget--) { s->failed_pc=0x0c0c858au; return 0; }
r[6]=r[9];
goto P_0c0c858c;
P_0c0c858c: /* original 70fe, guest PC 0x0c0c858c */
if(!s->budget--) { s->failed_pc=0x0c0c858cu; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c858e;
P_0c0c858e: /* original 0aed, guest PC 0x0c0c858e */
if(!s->budget--) { s->failed_pc=0x0c0c858eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8590;
P_0c0c8590: /* original 4518, guest PC 0x0c0c8590 */
if(!s->budget--) { s->failed_pc=0x0c0c8590u; return 0; }
r[5]<<=8;
goto P_0c0c8592;
P_0c0c8592: /* original 4628, guest PC 0x0c0c8592 */
if(!s->budget--) { s->failed_pc=0x0c0c8592u; return 0; }
r[6]<<=16;
goto P_0c0c8594;
P_0c0c8594: /* original 6053, guest PC 0x0c0c8594 */
if(!s->budget--) { s->failed_pc=0x0c0c8594u; return 0; }
r[0]=r[5];
goto P_0c0c8596;
P_0c0c8596: /* original 4618, guest PC 0x0c0c8596 */
if(!s->budget--) { s->failed_pc=0x0c0c8596u; return 0; }
r[6]<<=8;
goto P_0c0c8598;
P_0c0c8598: /* original 206b, guest PC 0x0c0c8598 */
if(!s->budget--) { s->failed_pc=0x0c0c8598u; return 0; }
r[0]|=r[6];
goto P_0c0c859a;
P_0c0c859a: /* original cb18, guest PC 0x0c0c859a */
if(!s->budget--) { s->failed_pc=0x0c0c859au; return 0; }
r[0]|=24u;
goto P_0c0c859c;
P_0c0c859c: /* original 2f02, guest PC 0x0c0c859c */
if(!s->budget--) { s->failed_pc=0x0c0c859cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c859e;
P_0c0c859e: /* original 6053, guest PC 0x0c0c859e */
if(!s->budget--) { s->failed_pc=0x0c0c859eu; return 0; }
r[0]=r[5];
goto P_0c0c85a0;
P_0c0c85a0: /* original 207b, guest PC 0x0c0c85a0 */
if(!s->budget--) { s->failed_pc=0x0c0c85a0u; return 0; }
r[0]|=r[7];
goto P_0c0c85a2;
P_0c0c85a2: /* original cb18, guest PC 0x0c0c85a2 */
if(!s->budget--) { s->failed_pc=0x0c0c85a2u; return 0; }
r[0]|=24u;
goto P_0c0c85a4;
P_0c0c85a4: /* original 1f01, guest PC 0x0c0c85a4 */
if(!s->budget--) { s->failed_pc=0x0c0c85a4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0c85a6;
P_0c0c85a6: /* original d323, guest PC 0x0c0c85a6 */
if(!s->budget--) { s->failed_pc=0x0c0c85a6u; return 0; }
r[3]=read(ram,0x0c0c8634u,4);
goto P_0c0c85a8;
P_0c0c85a8: /* original 430b, guest PC 0x0c0c85a8 */
if(!s->budget--) { s->failed_pc=0x0c0c85a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c85acu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c85acu) { target=s->pc; goto dispatch; }
goto P_0c0c85ac;
P_0c0c85aa: /* original 64a3, guest PC 0x0c0c85aa */
if(!s->budget--) { s->failed_pc=0x0c0c85aau; return 0; }
r[4]=r[10];
goto P_0c0c85ac;
P_0c0c85ac: /* original 600d, guest PC 0x0c0c85ac */
if(!s->budget--) { s->failed_pc=0x0c0c85acu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c85ae;
P_0c0c85ae: /* original 2008, guest PC 0x0c0c85ae */
if(!s->budget--) { s->failed_pc=0x0c0c85aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c85b0;
P_0c0c85b0: /* original 8917, guest PC 0x0c0c85b0 */
if(!s->budget--) { s->failed_pc=0x0c0c85b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c85b2;
P_0c0c85b2: /* original d321, guest PC 0x0c0c85b2 */
if(!s->budget--) { s->failed_pc=0x0c0c85b2u; return 0; }
r[3]=read(ram,0x0c0c8638u,4);
goto P_0c0c85b4;
P_0c0c85b4: /* original 65d3, guest PC 0x0c0c85b4 */
if(!s->budget--) { s->failed_pc=0x0c0c85b4u; return 0; }
r[5]=r[13];
goto P_0c0c85b6;
P_0c0c85b6: /* original 7558, guest PC 0x0c0c85b6 */
if(!s->budget--) { s->failed_pc=0x0c0c85b6u; return 0; }
r[5]+=0x00000058u;
goto P_0c0c85b8;
P_0c0c85b8: /* original 430b, guest PC 0x0c0c85b8 */
if(!s->budget--) { s->failed_pc=0x0c0c85b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c85bcu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c85bcu) { target=s->pc; goto dispatch; }
goto P_0c0c85bc;
P_0c0c85ba: /* original 64a3, guest PC 0x0c0c85ba */
if(!s->budget--) { s->failed_pc=0x0c0c85bau; return 0; }
r[4]=r[10];
goto P_0c0c85bc;
P_0c0c85bc: /* original 9232, guest PC 0x0c0c85bc */
if(!s->budget--) { s->failed_pc=0x0c0c85bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8624u,2);
goto P_0c0c85be;
P_0c0c85be: /* original 4900, guest PC 0x0c0c85be */
if(!s->budget--) { s->failed_pc=0x0c0c85beu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0c85c0;
P_0c0c85c0: /* original 66d3, guest PC 0x0c0c85c0 */
if(!s->budget--) { s->failed_pc=0x0c0c85c0u; return 0; }
r[6]=r[13];
goto P_0c0c85c2;
P_0c0c85c2: /* original 65a3, guest PC 0x0c0c85c2 */
if(!s->budget--) { s->failed_pc=0x0c0c85c2u; return 0; }
r[5]=r[10];
goto P_0c0c85c4;
P_0c0c85c4: /* original 292b, guest PC 0x0c0c85c4 */
if(!s->budget--) { s->failed_pc=0x0c0c85c4u; return 0; }
r[9]|=r[2];
goto P_0c0c85c6;
P_0c0c85c6: /* original 1f92, guest PC 0x0c0c85c6 */
if(!s->budget--) { s->failed_pc=0x0c0c85c6u; return 0; }
write(ram,r[15]+8,r[9],4);
goto P_0c0c85c8;
P_0c0c85c8: /* original 7658, guest PC 0x0c0c85c8 */
if(!s->budget--) { s->failed_pc=0x0c0c85c8u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c85ca;
P_0c0c85ca: /* original 2fc6, guest PC 0x0c0c85ca */
if(!s->budget--) { s->failed_pc=0x0c0c85cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85cc;
P_0c0c85cc: /* original 57f1, guest PC 0x0c0c85cc */
if(!s->budget--) { s->failed_pc=0x0c0c85ccu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0c85ce;
P_0c0c85ce: /* original 4b0b, guest PC 0x0c0c85ce */
if(!s->budget--) { s->failed_pc=0x0c0c85ceu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c85d2u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c85d2u) { target=s->pc; goto dispatch; }
goto P_0c0c85d2;
P_0c0c85d0: /* original 54f3, guest PC 0x0c0c85d0 */
if(!s->budget--) { s->failed_pc=0x0c0c85d0u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0c85d2;
P_0c0c85d2: /* original 2fc6, guest PC 0x0c0c85d2 */
if(!s->budget--) { s->failed_pc=0x0c0c85d2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85d4;
P_0c0c85d4: /* original 66d3, guest PC 0x0c0c85d4 */
if(!s->budget--) { s->failed_pc=0x0c0c85d4u; return 0; }
r[6]=r[13];
goto P_0c0c85d6;
P_0c0c85d6: /* original 9426, guest PC 0x0c0c85d6 */
if(!s->budget--) { s->failed_pc=0x0c0c85d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8626u,2);
goto P_0c0c85d8;
P_0c0c85d8: /* original 7658, guest PC 0x0c0c85d8 */
if(!s->budget--) { s->failed_pc=0x0c0c85d8u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c85da;
P_0c0c85da: /* original 57f3, guest PC 0x0c0c85da */
if(!s->budget--) { s->failed_pc=0x0c0c85dau; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c0c85dc;
P_0c0c85dc: /* original 4b0b, guest PC 0x0c0c85dc */
if(!s->budget--) { s->failed_pc=0x0c0c85dcu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c85e0u;
r[5]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c85e0u) { target=s->pc; goto dispatch; }
goto P_0c0c85e0;
P_0c0c85de: /* original 65a3, guest PC 0x0c0c85de */
if(!s->budget--) { s->failed_pc=0x0c0c85deu; return 0; }
r[5]=r[10];
goto P_0c0c85e0;
P_0c0c85e0: /* original 7f08, guest PC 0x0c0c85e0 */
if(!s->budget--) { s->failed_pc=0x0c0c85e0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c85e2;
P_0c0c85e2: /* original 9022, guest PC 0x0c0c85e2 */
if(!s->budget--) { s->failed_pc=0x0c0c85e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862au,2);
goto P_0c0c85e4;
P_0c0c85e4: /* original 9420, guest PC 0x0c0c85e4 */
if(!s->budget--) { s->failed_pc=0x0c0c85e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8628u,2);
goto P_0c0c85e6;
P_0c0c85e6: /* original 00ec, guest PC 0x0c0c85e6 */
if(!s->budget--) { s->failed_pc=0x0c0c85e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c85e8;
P_0c0c85e8: /* original 600c, guest PC 0x0c0c85e8 */
if(!s->budget--) { s->failed_pc=0x0c0c85e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c85ea;
P_0c0c85ea: /* original 8801, guest PC 0x0c0c85ea */
if(!s->budget--) { s->failed_pc=0x0c0c85eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c85ec;
P_0c0c85ec: /* original 8903, guest PC 0x0c0c85ec */
if(!s->budget--) { s->failed_pc=0x0c0c85ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85f6; }
goto P_0c0c85ee;
P_0c0c85ee: /* original 50f4, guest PC 0x0c0c85ee */
if(!s->budget--) { s->failed_pc=0x0c0c85eeu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c85f0;
P_0c0c85f0: /* original 6002, guest PC 0x0c0c85f0 */
if(!s->budget--) { s->failed_pc=0x0c0c85f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0c85f2;
P_0c0c85f2: /* original c810, guest PC 0x0c0c85f2 */
if(!s->budget--) { s->failed_pc=0x0c0c85f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0c85f4;
P_0c0c85f4: /* original 8b07, guest PC 0x0c0c85f4 */
if(!s->budget--) { s->failed_pc=0x0c0c85f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8606; }
goto P_0c0c85f6;
P_0c0c85f6: /* original 2fc6, guest PC 0x0c0c85f6 */
if(!s->budget--) { s->failed_pc=0x0c0c85f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85f8;
P_0c0c85f8: /* original e700, guest PC 0x0c0c85f8 */
if(!s->budget--) { s->failed_pc=0x0c0c85f8u; return 0; }
r[7]=0x00000000u;
goto P_0c0c85fa;
P_0c0c85fa: /* original 9517, guest PC 0x0c0c85fa */
if(!s->budget--) { s->failed_pc=0x0c0c85fau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862cu,2);
goto P_0c0c85fc;
P_0c0c85fc: /* original 9414, guest PC 0x0c0c85fc */
if(!s->budget--) { s->failed_pc=0x0c0c85fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8628u,2);
goto P_0c0c85fe;
P_0c0c85fe: /* original 4b0b, guest PC 0x0c0c85fe */
if(!s->budget--) { s->failed_pc=0x0c0c85feu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c8602u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8602u) { target=s->pc; goto dispatch; }
goto P_0c0c8602;
P_0c0c8600: /* original 66d3, guest PC 0x0c0c8600 */
if(!s->budget--) { s->failed_pc=0x0c0c8600u; return 0; }
r[6]=r[13];
goto P_0c0c8602;
P_0c0c8602: /* original a005, guest PC 0x0c0c8602 */
if(!s->budget--) { s->failed_pc=0x0c0c8602u; return 0; }
goto P_0c0c8610;
P_0c0c8604: /* original 0009, guest PC 0x0c0c8604 */
if(!s->budget--) { s->failed_pc=0x0c0c8604u; return 0; }
goto P_0c0c8606;
P_0c0c8606: /* original e700, guest PC 0x0c0c8606 */
if(!s->budget--) { s->failed_pc=0x0c0c8606u; return 0; }
r[7]=0x00000000u;
goto P_0c0c8608;
P_0c0c8608: /* original 2fc6, guest PC 0x0c0c8608 */
if(!s->budget--) { s->failed_pc=0x0c0c8608u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c860a;
P_0c0c860a: /* original 950f, guest PC 0x0c0c860a */
if(!s->budget--) { s->failed_pc=0x0c0c860au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862cu,2);
goto P_0c0c860c;
P_0c0c860c: /* original 480b, guest PC 0x0c0c860c */
if(!s->budget--) { s->failed_pc=0x0c0c860cu; return 0; }
target=r[8];
r[16]=code_base|0x0c0c8610u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8610u) { target=s->pc; goto dispatch; }
goto P_0c0c8610;
P_0c0c860e: /* original 66d3, guest PC 0x0c0c860e */
if(!s->budget--) { s->failed_pc=0x0c0c860eu; return 0; }
r[6]=r[13];
goto P_0c0c8610;
P_0c0c8610: /* original 7f1c, guest PC 0x0c0c8610 */
if(!s->budget--) { s->failed_pc=0x0c0c8610u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0c8612;
P_0c0c8612: /* original 4f26, guest PC 0x0c0c8612 */
if(!s->budget--) { s->failed_pc=0x0c0c8612u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8614;
P_0c0c8614: /* original 68f6, guest PC 0x0c0c8614 */
if(!s->budget--) { s->failed_pc=0x0c0c8614u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c8616;
P_0c0c8616: /* original 69f6, guest PC 0x0c0c8616 */
if(!s->budget--) { s->failed_pc=0x0c0c8616u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c8618;
P_0c0c8618: /* original 6af6, guest PC 0x0c0c8618 */
if(!s->budget--) { s->failed_pc=0x0c0c8618u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c861a;
P_0c0c861a: /* original 6bf6, guest PC 0x0c0c861a */
if(!s->budget--) { s->failed_pc=0x0c0c861au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c861c;
P_0c0c861c: /* original 6cf6, guest PC 0x0c0c861c */
if(!s->budget--) { s->failed_pc=0x0c0c861cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c861e;
P_0c0c861e: /* original 6df6, guest PC 0x0c0c861e */
if(!s->budget--) { s->failed_pc=0x0c0c861eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8620;
P_0c0c8620: /* original 000b, guest PC 0x0c0c8620 */
if(!s->budget--) { s->failed_pc=0x0c0c8620u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c8622: /* original 6ef6, guest PC 0x0c0c8622 */
if(!s->budget--) { s->failed_pc=0x0c0c8622u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c8624u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8624u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
