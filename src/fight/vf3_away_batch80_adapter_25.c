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
int vf3_away_batch80_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b2510u: goto P_0c0b2510;
case 0x0c0b2512u: goto P_0c0b2512;
case 0x0c0b2514u: goto P_0c0b2514;
case 0x0c0b2516u: goto P_0c0b2516;
case 0x0c0b2518u: goto P_0c0b2518;
case 0x0c0b251au: goto P_0c0b251a;
case 0x0c0b251cu: goto P_0c0b251c;
case 0x0c0b251eu: goto P_0c0b251e;
case 0x0c0b2520u: goto P_0c0b2520;
case 0x0c0b2522u: goto P_0c0b2522;
case 0x0c0b2524u: goto P_0c0b2524;
case 0x0c0b2526u: goto P_0c0b2526;
case 0x0c0b2528u: goto P_0c0b2528;
case 0x0c0b252au: goto P_0c0b252a;
case 0x0c0b252cu: goto P_0c0b252c;
case 0x0c0b252eu: goto P_0c0b252e;
case 0x0c0b2530u: goto P_0c0b2530;
case 0x0c0b2532u: goto P_0c0b2532;
case 0x0c0b2534u: goto P_0c0b2534;
case 0x0c0b2536u: goto P_0c0b2536;
case 0x0c0b2538u: goto P_0c0b2538;
case 0x0c0b253au: goto P_0c0b253a;
case 0x0c0b253cu: goto P_0c0b253c;
case 0x0c0b253eu: goto P_0c0b253e;
case 0x0c0b2540u: goto P_0c0b2540;
case 0x0c0b2542u: goto P_0c0b2542;
case 0x0c0b2544u: goto P_0c0b2544;
case 0x0c0b2546u: goto P_0c0b2546;
case 0x0c0b2548u: goto P_0c0b2548;
case 0x0c0b254au: goto P_0c0b254a;
case 0x0c0b254cu: goto P_0c0b254c;
case 0x0c0b254eu: goto P_0c0b254e;
case 0x0c0b2550u: goto P_0c0b2550;
case 0x0c0b2552u: goto P_0c0b2552;
case 0x0c0b2554u: goto P_0c0b2554;
case 0x0c0b2556u: goto P_0c0b2556;
case 0x0c0b2558u: goto P_0c0b2558;
case 0x0c0b255au: goto P_0c0b255a;
case 0x0c0b255cu: goto P_0c0b255c;
case 0x0c0b255eu: goto P_0c0b255e;
case 0x0c0b2560u: goto P_0c0b2560;
case 0x0c0b2562u: goto P_0c0b2562;
case 0x0c0b2564u: goto P_0c0b2564;
case 0x0c0b2566u: goto P_0c0b2566;
case 0x0c0b2568u: goto P_0c0b2568;
case 0x0c0b256au: goto P_0c0b256a;
case 0x0c0b256cu: goto P_0c0b256c;
case 0x0c0b256eu: goto P_0c0b256e;
case 0x0c0b2570u: goto P_0c0b2570;
case 0x0c0b2572u: goto P_0c0b2572;
case 0x0c0b2574u: goto P_0c0b2574;
case 0x0c0b2576u: goto P_0c0b2576;
case 0x0c0b2578u: goto P_0c0b2578;
case 0x0c0b257au: goto P_0c0b257a;
case 0x0c0b257cu: goto P_0c0b257c;
case 0x0c0b257eu: goto P_0c0b257e;
case 0x0c0b2580u: goto P_0c0b2580;
case 0x0c0b2582u: goto P_0c0b2582;
case 0x0c0b2584u: goto P_0c0b2584;
case 0x0c0b2586u: goto P_0c0b2586;
case 0x0c0b2588u: goto P_0c0b2588;
case 0x0c0b258au: goto P_0c0b258a;
case 0x0c0b258cu: goto P_0c0b258c;
case 0x0c0b258eu: goto P_0c0b258e;
case 0x0c0b2590u: goto P_0c0b2590;
case 0x0c0b2592u: goto P_0c0b2592;
case 0x0c0becf8u: goto P_0c0becf8;
case 0x0c0becfau: goto P_0c0becfa;
case 0x0c0becfcu: goto P_0c0becfc;
case 0x0c0becfeu: goto P_0c0becfe;
case 0x0c0bed00u: goto P_0c0bed00;
case 0x0c0bed02u: goto P_0c0bed02;
case 0x0c0bed04u: goto P_0c0bed04;
case 0x0c0bed06u: goto P_0c0bed06;
case 0x0c0bed08u: goto P_0c0bed08;
case 0x0c0bed0au: goto P_0c0bed0a;
case 0x0c0bed0cu: goto P_0c0bed0c;
case 0x0c0bed0eu: goto P_0c0bed0e;
case 0x0c0bed10u: goto P_0c0bed10;
case 0x0c0bed12u: goto P_0c0bed12;
case 0x0c0bed14u: goto P_0c0bed14;
case 0x0c0bed16u: goto P_0c0bed16;
case 0x0c0bed18u: goto P_0c0bed18;
case 0x0c0bed1au: goto P_0c0bed1a;
case 0x0c0bed1cu: goto P_0c0bed1c;
case 0x0c0bed1eu: goto P_0c0bed1e;
case 0x0c0bed20u: goto P_0c0bed20;
case 0x0c0bed22u: goto P_0c0bed22;
case 0x0c0bed24u: goto P_0c0bed24;
case 0x0c0bed26u: goto P_0c0bed26;
case 0x0c0bed28u: goto P_0c0bed28;
case 0x0c0bed2au: goto P_0c0bed2a;
case 0x0c0bed2cu: goto P_0c0bed2c;
case 0x0c0bed2eu: goto P_0c0bed2e;
case 0x0c0bed30u: goto P_0c0bed30;
case 0x0c0bed32u: goto P_0c0bed32;
case 0x0c0bed34u: goto P_0c0bed34;
case 0x0c0bed36u: goto P_0c0bed36;
case 0x0c0bed84u: goto P_0c0bed84;
case 0x0c0bed86u: goto P_0c0bed86;
case 0x0c0bed88u: goto P_0c0bed88;
case 0x0c0bed8au: goto P_0c0bed8a;
case 0x0c0bed8cu: goto P_0c0bed8c;
case 0x0c0bed8eu: goto P_0c0bed8e;
case 0x0c0bed90u: goto P_0c0bed90;
case 0x0c0bed92u: goto P_0c0bed92;
case 0x0c0bed94u: goto P_0c0bed94;
case 0x0c0bed96u: goto P_0c0bed96;
case 0x0c0bed98u: goto P_0c0bed98;
case 0x0c0bed9au: goto P_0c0bed9a;
case 0x0c0bed9cu: goto P_0c0bed9c;
case 0x0c0bed9eu: goto P_0c0bed9e;
case 0x0c0beda0u: goto P_0c0beda0;
case 0x0c0beda2u: goto P_0c0beda2;
case 0x0c0beda4u: goto P_0c0beda4;
case 0x0c0beda6u: goto P_0c0beda6;
case 0x0c0beda8u: goto P_0c0beda8;
case 0x0c0bedaau: goto P_0c0bedaa;
case 0x0c0bedacu: goto P_0c0bedac;
case 0x0c0bedaeu: goto P_0c0bedae;
case 0x0c0bedb0u: goto P_0c0bedb0;
case 0x0c0bedb2u: goto P_0c0bedb2;
case 0x0c0bedb4u: goto P_0c0bedb4;
case 0x0c0bedb6u: goto P_0c0bedb6;
case 0x0c0bedb8u: goto P_0c0bedb8;
case 0x0c0bedbau: goto P_0c0bedba;
case 0x0c0bedbcu: goto P_0c0bedbc;
case 0x0c0bedbeu: goto P_0c0bedbe;
case 0x0c0bedc0u: goto P_0c0bedc0;
case 0x0c0bedc2u: goto P_0c0bedc2;
case 0x0c0bedc4u: goto P_0c0bedc4;
case 0x0c0bedc6u: goto P_0c0bedc6;
case 0x0c0bedc8u: goto P_0c0bedc8;
case 0x0c0bedcau: goto P_0c0bedca;
case 0x0c0bedccu: goto P_0c0bedcc;
case 0x0c0bedceu: goto P_0c0bedce;
case 0x0c0bedd0u: goto P_0c0bedd0;
case 0x0c0bedd2u: goto P_0c0bedd2;
case 0x0c0bedd4u: goto P_0c0bedd4;
case 0x0c0bedd6u: goto P_0c0bedd6;
case 0x0c0bedd8u: goto P_0c0bedd8;
case 0x0c0beddau: goto P_0c0bedda;
case 0x0c0beddcu: goto P_0c0beddc;
case 0x0c0beddeu: goto P_0c0bedde;
case 0x0c0bede0u: goto P_0c0bede0;
case 0x0c0bede2u: goto P_0c0bede2;
case 0x0c0bede4u: goto P_0c0bede4;
case 0x0c0bede6u: goto P_0c0bede6;
case 0x0c0bede8u: goto P_0c0bede8;
case 0x0c0bedeau: goto P_0c0bedea;
case 0x0c0bedecu: goto P_0c0bedec;
case 0x0c0bedeeu: goto P_0c0bedee;
case 0x0c0bedf0u: goto P_0c0bedf0;
case 0x0c0bedf2u: goto P_0c0bedf2;
case 0x0c0bedf4u: goto P_0c0bedf4;
case 0x0c0bedf6u: goto P_0c0bedf6;
case 0x0c0bedf8u: goto P_0c0bedf8;
case 0x0c0bedfau: goto P_0c0bedfa;
case 0x0c0bedfcu: goto P_0c0bedfc;
case 0x0c0bedfeu: goto P_0c0bedfe;
case 0x0c0bee00u: goto P_0c0bee00;
case 0x0c0bee02u: goto P_0c0bee02;
case 0x0c0bee04u: goto P_0c0bee04;
case 0x0c0bee06u: goto P_0c0bee06;
case 0x0c0bee08u: goto P_0c0bee08;
case 0x0c0bee0au: goto P_0c0bee0a;
case 0x0c0bee0cu: goto P_0c0bee0c;
case 0x0c0bee0eu: goto P_0c0bee0e;
case 0x0c0bee10u: goto P_0c0bee10;
case 0x0c0bee12u: goto P_0c0bee12;
case 0x0c0bee14u: goto P_0c0bee14;
case 0x0c0bee16u: goto P_0c0bee16;
case 0x0c0bee18u: goto P_0c0bee18;
case 0x0c0bee1au: goto P_0c0bee1a;
case 0x0c0bee1cu: goto P_0c0bee1c;
case 0x0c0bee1eu: goto P_0c0bee1e;
case 0x0c0bee20u: goto P_0c0bee20;
case 0x0c0bee22u: goto P_0c0bee22;
case 0x0c0bee24u: goto P_0c0bee24;
case 0x0c0bee26u: goto P_0c0bee26;
case 0x0c0bee28u: goto P_0c0bee28;
case 0x0c0bee2au: goto P_0c0bee2a;
case 0x0c0bee2cu: goto P_0c0bee2c;
case 0x0c0bee2eu: goto P_0c0bee2e;
case 0x0c0bee30u: goto P_0c0bee30;
case 0x0c0bee32u: goto P_0c0bee32;
case 0x0c0bee34u: goto P_0c0bee34;
case 0x0c0bee36u: goto P_0c0bee36;
case 0x0c0bee38u: goto P_0c0bee38;
case 0x0c0bee3au: goto P_0c0bee3a;
case 0x0c0bee3cu: goto P_0c0bee3c;
case 0x0c0bee3eu: goto P_0c0bee3e;
case 0x0c0bee40u: goto P_0c0bee40;
case 0x0c0bee42u: goto P_0c0bee42;
case 0x0c0bee44u: goto P_0c0bee44;
case 0x0c0bee46u: goto P_0c0bee46;
case 0x0c0bee48u: goto P_0c0bee48;
case 0x0c0bee4au: goto P_0c0bee4a;
case 0x0c0bee4cu: goto P_0c0bee4c;
case 0x0c0bee4eu: goto P_0c0bee4e;
case 0x0c0bee50u: goto P_0c0bee50;
case 0x0c0bee52u: goto P_0c0bee52;
case 0x0c0bee54u: goto P_0c0bee54;
case 0x0c0bee56u: goto P_0c0bee56;
case 0x0c0bee58u: goto P_0c0bee58;
case 0x0c0bee5au: goto P_0c0bee5a;
case 0x0c0bee5cu: goto P_0c0bee5c;
case 0x0c0bee5eu: goto P_0c0bee5e;
case 0x0c0bee60u: goto P_0c0bee60;
case 0x0c0bee62u: goto P_0c0bee62;
case 0x0c0bee64u: goto P_0c0bee64;
case 0x0c0bee66u: goto P_0c0bee66;
case 0x0c0bee68u: goto P_0c0bee68;
case 0x0c0bee6au: goto P_0c0bee6a;
case 0x0c0bee6cu: goto P_0c0bee6c;
case 0x0c0bee6eu: goto P_0c0bee6e;
case 0x0c0bee70u: goto P_0c0bee70;
case 0x0c0bee72u: goto P_0c0bee72;
case 0x0c0bee74u: goto P_0c0bee74;
case 0x0c0bee76u: goto P_0c0bee76;
case 0x0c0bee78u: goto P_0c0bee78;
case 0x0c0bee7au: goto P_0c0bee7a;
case 0x0c0bee7cu: goto P_0c0bee7c;
case 0x0c0bee7eu: goto P_0c0bee7e;
case 0x0c0bee80u: goto P_0c0bee80;
case 0x0c0bee82u: goto P_0c0bee82;
case 0x0c0bee84u: goto P_0c0bee84;
case 0x0c0bee86u: goto P_0c0bee86;
case 0x0c0bee88u: goto P_0c0bee88;
case 0x0c0bee8au: goto P_0c0bee8a;
case 0x0c0bee8cu: goto P_0c0bee8c;
case 0x0c0bee8eu: goto P_0c0bee8e;
case 0x0c0bee90u: goto P_0c0bee90;
case 0x0c0bee92u: goto P_0c0bee92;
case 0x0c0bee94u: goto P_0c0bee94;
case 0x0c0bee96u: goto P_0c0bee96;
case 0x0c0bee98u: goto P_0c0bee98;
case 0x0c0bee9au: goto P_0c0bee9a;
case 0x0c0bee9cu: goto P_0c0bee9c;
case 0x0c0bee9eu: goto P_0c0bee9e;
case 0x0c0beea0u: goto P_0c0beea0;
case 0x0c0beea2u: goto P_0c0beea2;
case 0x0c0beea4u: goto P_0c0beea4;
case 0x0c0beea6u: goto P_0c0beea6;
case 0x0c0beea8u: goto P_0c0beea8;
case 0x0c0beeaau: goto P_0c0beeaa;
case 0x0c0beeacu: goto P_0c0beeac;
case 0x0c0beeaeu: goto P_0c0beeae;
case 0x0c0beeb0u: goto P_0c0beeb0;
case 0x0c0beeb2u: goto P_0c0beeb2;
case 0x0c0beeb4u: goto P_0c0beeb4;
case 0x0c0beeb6u: goto P_0c0beeb6;
case 0x0c0beeb8u: goto P_0c0beeb8;
case 0x0c0beebau: goto P_0c0beeba;
case 0x0c0beebcu: goto P_0c0beebc;
case 0x0c0beebeu: goto P_0c0beebe;
case 0x0c0beec0u: goto P_0c0beec0;
case 0x0c0beec2u: goto P_0c0beec2;
case 0x0c0beec4u: goto P_0c0beec4;
case 0x0c0beec6u: goto P_0c0beec6;
case 0x0c0beec8u: goto P_0c0beec8;
case 0x0c0beecau: goto P_0c0beeca;
case 0x0c0beef8u: goto P_0c0beef8;
case 0x0c0beefau: goto P_0c0beefa;
case 0x0c0beefcu: goto P_0c0beefc;
case 0x0c0beefeu: goto P_0c0beefe;
case 0x0c0bef00u: goto P_0c0bef00;
case 0x0c0bef02u: goto P_0c0bef02;
case 0x0c0bef04u: goto P_0c0bef04;
case 0x0c0bef06u: goto P_0c0bef06;
case 0x0c0bef08u: goto P_0c0bef08;
case 0x0c0bef0au: goto P_0c0bef0a;
case 0x0c0bef0cu: goto P_0c0bef0c;
case 0x0c0bef0eu: goto P_0c0bef0e;
case 0x0c0bef10u: goto P_0c0bef10;
case 0x0c0bef12u: goto P_0c0bef12;
case 0x0c0bef14u: goto P_0c0bef14;
case 0x0c0bef16u: goto P_0c0bef16;
case 0x0c0bef18u: goto P_0c0bef18;
case 0x0c0bef1au: goto P_0c0bef1a;
case 0x0c0bef1cu: goto P_0c0bef1c;
case 0x0c0bef1eu: goto P_0c0bef1e;
case 0x0c0bef20u: goto P_0c0bef20;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b2510: /* original 2fe6, guest PC 0x0c0b2510 */
if(!s->budget--) { s->failed_pc=0x0c0b2510u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2512;
P_0c0b2512: /* original e061, guest PC 0x0c0b2512 */
if(!s->budget--) { s->failed_pc=0x0c0b2512u; return 0; }
r[0]=0x00000061u;
goto P_0c0b2514;
P_0c0b2514: /* original d53a, guest PC 0x0c0b2514 */
if(!s->budget--) { s->failed_pc=0x0c0b2514u; return 0; }
r[5]=read(ram,0x0c0b2600u,4);
goto P_0c0b2516;
P_0c0b2516: /* original e661, guest PC 0x0c0b2516 */
if(!s->budget--) { s->failed_pc=0x0c0b2516u; return 0; }
r[6]=0x00000061u;
goto P_0c0b2518;
P_0c0b2518: /* original 4f22, guest PC 0x0c0b2518 */
if(!s->budget--) { s->failed_pc=0x0c0b2518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b251a;
P_0c0b251a: /* original 5454, guest PC 0x0c0b251a */
if(!s->budget--) { s->failed_pc=0x0c0b251au; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0b251c;
P_0c0b251c: /* original 5755, guest PC 0x0c0b251c */
if(!s->budget--) { s->failed_pc=0x0c0b251cu; return 0; }
r[7]=read(ram,r[5]+20,4);
goto P_0c0b251e;
P_0c0b251e: /* original d239, guest PC 0x0c0b251e */
if(!s->budget--) { s->failed_pc=0x0c0b251eu; return 0; }
r[2]=read(ram,0x0c0b2604u,4);
goto P_0c0b2520;
P_0c0b2520: /* original 4f12, guest PC 0x0c0b2520 */
if(!s->budget--) { s->failed_pc=0x0c0b2520u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0b2522;
P_0c0b2522: /* original 6322, guest PC 0x0c0b2522 */
if(!s->budget--) { s->failed_pc=0x0c0b2522u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0b2524;
P_0c0b2524: /* original e234, guest PC 0x0c0b2524 */
if(!s->budget--) { s->failed_pc=0x0c0b2524u; return 0; }
r[2]=0x00000034u;
goto P_0c0b2526;
P_0c0b2526: /* original 367c, guest PC 0x0c0b2526 */
if(!s->budget--) { s->failed_pc=0x0c0b2526u; return 0; }
r[6]+=r[7];
goto P_0c0b2528;
P_0c0b2528: /* original de34, guest PC 0x0c0b2528 */
if(!s->budget--) { s->failed_pc=0x0c0b2528u; return 0; }
r[14]=read(ram,0x0c0b25fcu,4);
goto P_0c0b252a;
P_0c0b252a: /* original 7ff8, guest PC 0x0c0b252a */
if(!s->budget--) { s->failed_pc=0x0c0b252au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b252c;
P_0c0b252c: /* original 1f31, guest PC 0x0c0b252c */
if(!s->budget--) { s->failed_pc=0x0c0b252cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0b252e;
P_0c0b252e: /* original d336, guest PC 0x0c0b252e */
if(!s->budget--) { s->failed_pc=0x0c0b252eu; return 0; }
r[3]=read(ram,0x0c0b2608u,4);
goto P_0c0b2530;
P_0c0b2530: /* original 6132, guest PC 0x0c0b2530 */
if(!s->budget--) { s->failed_pc=0x0c0b2530u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0b2532;
P_0c0b2532: /* original 2f12, guest PC 0x0c0b2532 */
if(!s->budget--) { s->failed_pc=0x0c0b2532u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0b2534;
P_0c0b2534: /* original 054c, guest PC 0x0c0b2534 */
if(!s->budget--) { s->failed_pc=0x0c0b2534u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b2536;
P_0c0b2536: /* original 6660, guest PC 0x0c0b2536 */
if(!s->budget--) { s->failed_pc=0x0c0b2536u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c0b2538;
P_0c0b2538: /* original 605c, guest PC 0x0c0b2538 */
if(!s->budget--) { s->failed_pc=0x0c0b2538u; return 0; }
r[0]=r[5]&255u;
goto P_0c0b253a;
P_0c0b253a: /* original d334, guest PC 0x0c0b253a */
if(!s->budget--) { s->failed_pc=0x0c0b253au; return 0; }
r[3]=read(ram,0x0c0b260cu,4);
goto P_0c0b253c;
P_0c0b253c: /* original 202f, guest PC 0x0c0b253c */
if(!s->budget--) { s->failed_pc=0x0c0b253cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[2]);
goto P_0c0b253e;
P_0c0b253e: /* original 616c, guest PC 0x0c0b253e */
if(!s->budget--) { s->failed_pc=0x0c0b253eu; return 0; }
r[1]=r[6]&255u;
goto P_0c0b2540;
P_0c0b2540: /* original 675c, guest PC 0x0c0b2540 */
if(!s->budget--) { s->failed_pc=0x0c0b2540u; return 0; }
r[7]=r[5]&255u;
goto P_0c0b2542;
P_0c0b2542: /* original 4108, guest PC 0x0c0b2542 */
if(!s->budget--) { s->failed_pc=0x0c0b2542u; return 0; }
r[1]<<=2;
goto P_0c0b2544;
P_0c0b2544: /* original 001a, guest PC 0x0c0b2544 */
if(!s->budget--) { s->failed_pc=0x0c0b2544u; return 0; }
r[0]=r[19];
goto P_0c0b2546;
P_0c0b2546: /* original 4708, guest PC 0x0c0b2546 */
if(!s->budget--) { s->failed_pc=0x0c0b2546u; return 0; }
r[7]<<=2;
goto P_0c0b2548;
P_0c0b2548: /* original 4708, guest PC 0x0c0b2548 */
if(!s->budget--) { s->failed_pc=0x0c0b2548u; return 0; }
r[7]<<=2;
goto P_0c0b254a;
P_0c0b254a: /* original 600f, guest PC 0x0c0b254a */
if(!s->budget--) { s->failed_pc=0x0c0b254au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0b254c;
P_0c0b254c: /* original 303c, guest PC 0x0c0b254c */
if(!s->budget--) { s->failed_pc=0x0c0b254cu; return 0; }
r[0]+=r[3];
goto P_0c0b254e;
P_0c0b254e: /* original 041e, guest PC 0x0c0b254e */
if(!s->budget--) { s->failed_pc=0x0c0b254eu; return 0; }
r[4]=read(ram,r[1]+r[0],4);
goto P_0c0b2550;
P_0c0b2550: /* original 904e, guest PC 0x0c0b2550 */
if(!s->budget--) { s->failed_pc=0x0c0b2550u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b25f0u,2);
goto P_0c0b2552;
P_0c0b2552: /* original 666c, guest PC 0x0c0b2552 */
if(!s->budget--) { s->failed_pc=0x0c0b2552u; return 0; }
r[6]=r[6]&255u;
goto P_0c0b2554;
P_0c0b2554: /* original 276b, guest PC 0x0c0b2554 */
if(!s->budget--) { s->failed_pc=0x0c0b2554u; return 0; }
r[7]|=r[6];
goto P_0c0b2556;
P_0c0b2556: /* original 01ee, guest PC 0x0c0b2556 */
if(!s->budget--) { s->failed_pc=0x0c0b2556u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0b2558;
P_0c0b2558: /* original 3710, guest PC 0x0c0b2558 */
if(!s->budget--) { s->failed_pc=0x0c0b2558u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[1])!=0);
goto P_0c0b255a;
P_0c0b255a: /* original 8916, guest PC 0x0c0b255a */
if(!s->budget--) { s->failed_pc=0x0c0b255au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b258a; }
goto P_0c0b255c;
P_0c0b255c: /* original 9049, guest PC 0x0c0b255c */
if(!s->budget--) { s->failed_pc=0x0c0b255cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b25f2u,2);
goto P_0c0b255e;
P_0c0b255e: /* original 52f1, guest PC 0x0c0b255e */
if(!s->budget--) { s->failed_pc=0x0c0b255eu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0b2560;
P_0c0b2560: /* original 0e26, guest PC 0x0c0b2560 */
if(!s->budget--) { s->failed_pc=0x0c0b2560u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0b2562;
P_0c0b2562: /* original 9047, guest PC 0x0c0b2562 */
if(!s->budget--) { s->failed_pc=0x0c0b2562u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b25f4u,2);
goto P_0c0b2564;
P_0c0b2564: /* original 63f2, guest PC 0x0c0b2564 */
if(!s->budget--) { s->failed_pc=0x0c0b2564u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0b2566;
P_0c0b2566: /* original 0e36, guest PC 0x0c0b2566 */
if(!s->budget--) { s->failed_pc=0x0c0b2566u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0b2568;
P_0c0b2568: /* original 7004, guest PC 0x0c0b2568 */
if(!s->budget--) { s->failed_pc=0x0c0b2568u; return 0; }
r[0]+=0x00000004u;
goto P_0c0b256a;
P_0c0b256a: /* original 0e46, guest PC 0x0c0b256a */
if(!s->budget--) { s->failed_pc=0x0c0b256au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0b256c;
P_0c0b256c: /* original 701c, guest PC 0x0c0b256c */
if(!s->budget--) { s->failed_pc=0x0c0b256cu; return 0; }
r[0]+=0x0000001cu;
goto P_0c0b256e;
P_0c0b256e: /* original e300, guest PC 0x0c0b256e */
if(!s->budget--) { s->failed_pc=0x0c0b256eu; return 0; }
r[3]=0x00000000u;
goto P_0c0b2570;
P_0c0b2570: /* original 0e36, guest PC 0x0c0b2570 */
if(!s->budget--) { s->failed_pc=0x0c0b2570u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0b2572;
P_0c0b2572: /* original 70e0, guest PC 0x0c0b2572 */
if(!s->budget--) { s->failed_pc=0x0c0b2572u; return 0; }
r[0]+=0xffffffe0u;
goto P_0c0b2574;
P_0c0b2574: /* original 923f, guest PC 0x0c0b2574 */
if(!s->budget--) { s->failed_pc=0x0c0b2574u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b25f6u,2);
goto P_0c0b2576;
P_0c0b2576: /* original 2f26, guest PC 0x0c0b2576 */
if(!s->budget--) { s->failed_pc=0x0c0b2576u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b2578;
P_0c0b2578: /* original d325, guest PC 0x0c0b2578 */
if(!s->budget--) { s->failed_pc=0x0c0b2578u; return 0; }
r[3]=read(ram,0x0c0b2610u,4);
goto P_0c0b257a;
P_0c0b257a: /* original 2f36, guest PC 0x0c0b257a */
if(!s->budget--) { s->failed_pc=0x0c0b257au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b257c;
P_0c0b257c: /* original 2f76, guest PC 0x0c0b257c */
if(!s->budget--) { s->failed_pc=0x0c0b257cu; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b257e;
P_0c0b257e: /* original d327, guest PC 0x0c0b257e */
if(!s->budget--) { s->failed_pc=0x0c0b257eu; return 0; }
r[3]=read(ram,0x0c0b261cu,4);
goto P_0c0b2580;
P_0c0b2580: /* original d625, guest PC 0x0c0b2580 */
if(!s->budget--) { s->failed_pc=0x0c0b2580u; return 0; }
r[6]=read(ram,0x0c0b2618u,4);
goto P_0c0b2582;
P_0c0b2582: /* original d724, guest PC 0x0c0b2582 */
if(!s->budget--) { s->failed_pc=0x0c0b2582u; return 0; }
r[7]=read(ram,0x0c0b2614u,4);
goto P_0c0b2584;
P_0c0b2584: /* original 430b, guest PC 0x0c0b2584 */
if(!s->budget--) { s->failed_pc=0x0c0b2584u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b2588u;
r[5]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2588u) { target=s->pc; goto dispatch; }
goto P_0c0b2588;
P_0c0b2586: /* original 05ee, guest PC 0x0c0b2586 */
if(!s->budget--) { s->failed_pc=0x0c0b2586u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0b2588;
P_0c0b2588: /* original 7f0c, guest PC 0x0c0b2588 */
if(!s->budget--) { s->failed_pc=0x0c0b2588u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0b258a;
P_0c0b258a: /* original 7f08, guest PC 0x0c0b258a */
if(!s->budget--) { s->failed_pc=0x0c0b258au; return 0; }
r[15]+=0x00000008u;
goto P_0c0b258c;
P_0c0b258c: /* original 4f16, guest PC 0x0c0b258c */
if(!s->budget--) { s->failed_pc=0x0c0b258cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b258e;
P_0c0b258e: /* original 4f26, guest PC 0x0c0b258e */
if(!s->budget--) { s->failed_pc=0x0c0b258eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b2590;
P_0c0b2590: /* original 000b, guest PC 0x0c0b2590 */
if(!s->budget--) { s->failed_pc=0x0c0b2590u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b2592: /* original 6ef6, guest PC 0x0c0b2592 */
if(!s->budget--) { s->failed_pc=0x0c0b2592u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b2594u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b2594u; return 0; } return 1;
P_0c0becf8: /* original 2fe6, guest PC 0x0c0becf8 */
if(!s->budget--) { s->failed_pc=0x0c0becf8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0becfa;
P_0c0becfa: /* original 2fd6, guest PC 0x0c0becfa */
if(!s->budget--) { s->failed_pc=0x0c0becfau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0becfc;
P_0c0becfc: /* original 2fc6, guest PC 0x0c0becfc */
if(!s->budget--) { s->failed_pc=0x0c0becfcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0becfe;
P_0c0becfe: /* original 6c43, guest PC 0x0c0becfe */
if(!s->budget--) { s->failed_pc=0x0c0becfeu; return 0; }
r[12]=r[4];
goto P_0c0bed00;
P_0c0bed00: /* original 2fb6, guest PC 0x0c0bed00 */
if(!s->budget--) { s->failed_pc=0x0c0bed00u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bed02;
P_0c0bed02: /* original 2fa6, guest PC 0x0c0bed02 */
if(!s->budget--) { s->failed_pc=0x0c0bed02u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bed04;
P_0c0bed04: /* original 2f96, guest PC 0x0c0bed04 */
if(!s->budget--) { s->failed_pc=0x0c0bed04u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bed06;
P_0c0bed06: /* original 2f86, guest PC 0x0c0bed06 */
if(!s->budget--) { s->failed_pc=0x0c0bed06u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bed08;
P_0c0bed08: /* original 4f22, guest PC 0x0c0bed08 */
if(!s->budget--) { s->failed_pc=0x0c0bed08u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bed0a;
P_0c0bed0a: /* original 7ff8, guest PC 0x0c0bed0a */
if(!s->budget--) { s->failed_pc=0x0c0bed0au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0bed0c;
P_0c0bed0c: /* original 2f42, guest PC 0x0c0bed0c */
if(!s->budget--) { s->failed_pc=0x0c0bed0cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0bed0e;
P_0c0bed0e: /* original 84c4, guest PC 0x0c0bed0e */
if(!s->budget--) { s->failed_pc=0x0c0bed0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+4,1);
goto P_0c0bed10;
P_0c0bed10: /* original de1b, guest PC 0x0c0bed10 */
if(!s->budget--) { s->failed_pc=0x0c0bed10u; return 0; }
r[14]=read(ram,0x0c0bed80u,4);
goto P_0c0bed12;
P_0c0bed12: /* original 6c0c, guest PC 0x0c0bed12 */
if(!s->budget--) { s->failed_pc=0x0c0bed12u; return 0; }
r[12]=r[0]&255u;
goto P_0c0bed14;
P_0c0bed14: /* original 9330, guest PC 0x0c0bed14 */
if(!s->budget--) { s->failed_pc=0x0c0bed14u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bed78u,2);
goto P_0c0bed16;
P_0c0bed16: /* original 6dc3, guest PC 0x0c0bed16 */
if(!s->budget--) { s->failed_pc=0x0c0bed16u; return 0; }
r[13]=r[12];
goto P_0c0bed18;
P_0c0bed18: /* original e060, guest PC 0x0c0bed18 */
if(!s->budget--) { s->failed_pc=0x0c0bed18u; return 0; }
r[0]=0x00000060u;
goto P_0c0bed1a;
P_0c0bed1a: /* original 33ec, guest PC 0x0c0bed1a */
if(!s->budget--) { s->failed_pc=0x0c0bed1au; return 0; }
r[3]+=r[14];
goto P_0c0bed1c;
P_0c0bed1c: /* original 044c, guest PC 0x0c0bed1c */
if(!s->budget--) { s->failed_pc=0x0c0bed1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0bed1e;
P_0c0bed1e: /* original 4d08, guest PC 0x0c0bed1e */
if(!s->budget--) { s->failed_pc=0x0c0bed1eu; return 0; }
r[13]<<=2;
goto P_0c0bed20;
P_0c0bed20: /* original 33dc, guest PC 0x0c0bed20 */
if(!s->budget--) { s->failed_pc=0x0c0bed20u; return 0; }
r[3]+=r[13];
goto P_0c0bed22;
P_0c0bed22: /* original 6232, guest PC 0x0c0bed22 */
if(!s->budget--) { s->failed_pc=0x0c0bed22u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0bed24;
P_0c0bed24: /* original 684c, guest PC 0x0c0bed24 */
if(!s->budget--) { s->failed_pc=0x0c0bed24u; return 0; }
r[8]=r[4]&255u;
goto P_0c0bed26;
P_0c0bed26: /* original 644c, guest PC 0x0c0bed26 */
if(!s->budget--) { s->failed_pc=0x0c0bed26u; return 0; }
r[4]=r[4]&255u;
goto P_0c0bed28;
P_0c0bed28: /* original 3420, guest PC 0x0c0bed28 */
if(!s->budget--) { s->failed_pc=0x0c0bed28u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0bed2a;
P_0c0bed2a: /* original 8b2b, guest PC 0x0c0bed2a */
if(!s->budget--) { s->failed_pc=0x0c0bed2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bed84; }
goto P_0c0bed2c;
P_0c0bed2c: /* original 9125, guest PC 0x0c0bed2c */
if(!s->budget--) { s->failed_pc=0x0c0bed2cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bed7au,2);
goto P_0c0bed2e;
P_0c0bed2e: /* original e3ff, guest PC 0x0c0bed2e */
if(!s->budget--) { s->failed_pc=0x0c0bed2eu; return 0; }
r[3]=0xffffffffu;
goto P_0c0bed30;
P_0c0bed30: /* original 31ec, guest PC 0x0c0bed30 */
if(!s->budget--) { s->failed_pc=0x0c0bed30u; return 0; }
r[1]+=r[14];
goto P_0c0bed32;
P_0c0bed32: /* original 31dc, guest PC 0x0c0bed32 */
if(!s->budget--) { s->failed_pc=0x0c0bed32u; return 0; }
r[1]+=r[13];
goto P_0c0bed34;
P_0c0bed34: /* original a0eb, guest PC 0x0c0bed34 */
if(!s->budget--) { s->failed_pc=0x0c0bed34u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0bef0e;
P_0c0bed36: /* original 2132, guest PC 0x0c0bed36 */
if(!s->budget--) { s->failed_pc=0x0c0bed36u; return 0; }
write(ram,r[1],r[3],4);
if(!vf3_matrix_family(0x0c0bed38u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bed38u; return 0; } return 1;
P_0c0bed84: /* original 93a2, guest PC 0x0c0bed84 */
if(!s->budget--) { s->failed_pc=0x0c0bed84u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beeccu,2);
goto P_0c0bed86;
P_0c0bed86: /* original e21a, guest PC 0x0c0bed86 */
if(!s->budget--) { s->failed_pc=0x0c0bed86u; return 0; }
r[2]=0x0000001au;
goto P_0c0bed88;
P_0c0bed88: /* original db55, guest PC 0x0c0bed88 */
if(!s->budget--) { s->failed_pc=0x0c0bed88u; return 0; }
r[11]=read(ram,0x0c0beee0u,4);
goto P_0c0bed8a;
P_0c0bed8a: /* original 33ec, guest PC 0x0c0bed8a */
if(!s->budget--) { s->failed_pc=0x0c0bed8au; return 0; }
r[3]+=r[14];
goto P_0c0bed8c;
P_0c0bed8c: /* original 33dc, guest PC 0x0c0bed8c */
if(!s->budget--) { s->failed_pc=0x0c0bed8cu; return 0; }
r[3]+=r[13];
goto P_0c0bed8e;
P_0c0bed8e: /* original 6132, guest PC 0x0c0bed8e */
if(!s->budget--) { s->failed_pc=0x0c0bed8eu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0bed90;
P_0c0bed90: /* original 3126, guest PC 0x0c0bed90 */
if(!s->budget--) { s->failed_pc=0x0c0bed90u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c0bed92;
P_0c0bed92: /* original 8d6d, guest PC 0x0c0bed92 */
if(!s->budget--) { s->failed_pc=0x0c0bed92u; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(cond) { goto P_0c0bee70; }
goto P_0c0bed96;
P_0c0bed94: /* original ea00, guest PC 0x0c0bed94 */
if(!s->budget--) { s->failed_pc=0x0c0bed94u; return 0; }
r[10]=0x00000000u;
goto P_0c0bed96;
P_0c0bed96: /* original 9399, guest PC 0x0c0bed96 */
if(!s->budget--) { s->failed_pc=0x0c0bed96u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beeccu,2);
goto P_0c0bed98;
P_0c0bed98: /* original 33ec, guest PC 0x0c0bed98 */
if(!s->budget--) { s->failed_pc=0x0c0bed98u; return 0; }
r[3]+=r[14];
goto P_0c0bed9a;
P_0c0bed9a: /* original 33dc, guest PC 0x0c0bed9a */
if(!s->budget--) { s->failed_pc=0x0c0bed9au; return 0; }
r[3]+=r[13];
goto P_0c0bed9c;
P_0c0bed9c: /* original 6332, guest PC 0x0c0bed9c */
if(!s->budget--) { s->failed_pc=0x0c0bed9cu; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c0bed9e;
P_0c0bed9e: /* original 6233, guest PC 0x0c0bed9e */
if(!s->budget--) { s->failed_pc=0x0c0bed9eu; return 0; }
r[2]=r[3];
goto P_0c0beda0;
P_0c0beda0: /* original 4308, guest PC 0x0c0beda0 */
if(!s->budget--) { s->failed_pc=0x0c0beda0u; return 0; }
r[3]<<=2;
goto P_0c0beda2;
P_0c0beda2: /* original 4300, guest PC 0x0c0beda2 */
if(!s->budget--) { s->failed_pc=0x0c0beda2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0beda4;
P_0c0beda4: /* original 332c, guest PC 0x0c0beda4 */
if(!s->budget--) { s->failed_pc=0x0c0beda4u; return 0; }
r[3]+=r[2];
goto P_0c0beda6;
P_0c0beda6: /* original 4308, guest PC 0x0c0beda6 */
if(!s->budget--) { s->failed_pc=0x0c0beda6u; return 0; }
r[3]<<=2;
goto P_0c0beda8;
P_0c0beda8: /* original 33bc, guest PC 0x0c0beda8 */
if(!s->budget--) { s->failed_pc=0x0c0beda8u; return 0; }
r[3]+=r[11];
goto P_0c0bedaa;
P_0c0bedaa: /* original 5133, guest PC 0x0c0bedaa */
if(!s->budget--) { s->failed_pc=0x0c0bedaau; return 0; }
r[1]=read(ram,r[3]+12,4);
goto P_0c0bedac;
P_0c0bedac: /* original 6313, guest PC 0x0c0bedac */
if(!s->budget--) { s->failed_pc=0x0c0bedacu; return 0; }
r[3]=r[1];
goto P_0c0bedae;
P_0c0bedae: /* original 430b, guest PC 0x0c0bedae */
if(!s->budget--) { s->failed_pc=0x0c0bedaeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0bedb2u;
write(ram,r[15]+4,r[1],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bedb2u) { target=s->pc; goto dispatch; }
goto P_0c0bedb2;
P_0c0bedb0: /* original 1f11, guest PC 0x0c0bedb0 */
if(!s->budget--) { s->failed_pc=0x0c0bedb0u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0bedb2;
P_0c0bedb2: /* original 998b, guest PC 0x0c0bedb2 */
if(!s->budget--) { s->failed_pc=0x0c0bedb2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beeccu,2);
goto P_0c0bedb4;
P_0c0bedb4: /* original 39ec, guest PC 0x0c0bedb4 */
if(!s->budget--) { s->failed_pc=0x0c0bedb4u; return 0; }
r[9]+=r[14];
goto P_0c0bedb6;
P_0c0bedb6: /* original 39dc, guest PC 0x0c0bedb6 */
if(!s->budget--) { s->failed_pc=0x0c0bedb6u; return 0; }
r[9]+=r[13];
goto P_0c0bedb8;
P_0c0bedb8: /* original 6992, guest PC 0x0c0bedb8 */
if(!s->budget--) { s->failed_pc=0x0c0bedb8u; return 0; }
tmp=read(ram,r[9],4);
r[9]=tmp;
goto P_0c0bedba;
P_0c0bedba: /* original 6393, guest PC 0x0c0bedba */
if(!s->budget--) { s->failed_pc=0x0c0bedbau; return 0; }
r[3]=r[9];
goto P_0c0bedbc;
P_0c0bedbc: /* original 4908, guest PC 0x0c0bedbc */
if(!s->budget--) { s->failed_pc=0x0c0bedbcu; return 0; }
r[9]<<=2;
goto P_0c0bedbe;
P_0c0bedbe: /* original 4900, guest PC 0x0c0bedbe */
if(!s->budget--) { s->failed_pc=0x0c0bedbeu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0bedc0;
P_0c0bedc0: /* original 393c, guest PC 0x0c0bedc0 */
if(!s->budget--) { s->failed_pc=0x0c0bedc0u; return 0; }
r[9]+=r[3];
goto P_0c0bedc2;
P_0c0bedc2: /* original 4908, guest PC 0x0c0bedc2 */
if(!s->budget--) { s->failed_pc=0x0c0bedc2u; return 0; }
r[9]<<=2;
goto P_0c0bedc4;
P_0c0bedc4: /* original 39bc, guest PC 0x0c0bedc4 */
if(!s->budget--) { s->failed_pc=0x0c0bedc4u; return 0; }
r[9]+=r[11];
goto P_0c0bedc6;
P_0c0bedc6: /* original 5998, guest PC 0x0c0bedc6 */
if(!s->budget--) { s->failed_pc=0x0c0bedc6u; return 0; }
r[9]=read(ram,r[9]+32,4);
goto P_0c0bedc8;
P_0c0bedc8: /* original 2998, guest PC 0x0c0bedc8 */
if(!s->budget--) { s->failed_pc=0x0c0bedc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0bedca;
P_0c0bedca: /* original 8901, guest PC 0x0c0bedca */
if(!s->budget--) { s->failed_pc=0x0c0bedcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bedd0; }
goto P_0c0bedcc;
P_0c0bedcc: /* original 490b, guest PC 0x0c0bedcc */
if(!s->budget--) { s->failed_pc=0x0c0bedccu; return 0; }
target=r[9];
r[16]=code_base|0x0c0bedd0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bedd0u) { target=s->pc; goto dispatch; }
goto P_0c0bedd0;
P_0c0bedce: /* original 0009, guest PC 0x0c0bedce */
if(!s->budget--) { s->failed_pc=0x0c0bedceu; return 0; }
goto P_0c0bedd0;
P_0c0bedd0: /* original d944, guest PC 0x0c0bedd0 */
if(!s->budget--) { s->failed_pc=0x0c0bedd0u; return 0; }
r[9]=read(ram,0x0c0beee4u,4);
goto P_0c0bedd2;
P_0c0bedd2: /* original 2cc8, guest PC 0x0c0bedd2 */
if(!s->budget--) { s->failed_pc=0x0c0bedd2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0bedd4;
P_0c0bedd4: /* original 8b36, guest PC 0x0c0bedd4 */
if(!s->budget--) { s->failed_pc=0x0c0bedd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bee44; }
goto P_0c0bedd6;
P_0c0bedd6: /* original 62f2, guest PC 0x0c0bedd6 */
if(!s->budget--) { s->failed_pc=0x0c0bedd6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0bedd8;
P_0c0bedd8: /* original e060, guest PC 0x0c0bedd8 */
if(!s->budget--) { s->failed_pc=0x0c0bedd8u; return 0; }
r[0]=0x00000060u;
goto P_0c0bedda;
P_0c0bedda: /* original 032c, guest PC 0x0c0bedda */
if(!s->budget--) { s->failed_pc=0x0c0beddau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0beddc;
P_0c0beddc: /* original 9077, guest PC 0x0c0beddc */
if(!s->budget--) { s->failed_pc=0x0c0beddcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beeceu,2);
goto P_0c0bedde;
P_0c0bedde: /* original 633c, guest PC 0x0c0bedde */
if(!s->budget--) { s->failed_pc=0x0c0beddeu; return 0; }
r[3]=r[3]&255u;
goto P_0c0bede0;
P_0c0bede0: /* original 02ee, guest PC 0x0c0bede0 */
if(!s->budget--) { s->failed_pc=0x0c0bede0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0bede2;
P_0c0bede2: /* original 3320, guest PC 0x0c0bede2 */
if(!s->budget--) { s->failed_pc=0x0c0bede2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0bede4;
P_0c0bede4: /* original 8b2e, guest PC 0x0c0bede4 */
if(!s->budget--) { s->failed_pc=0x0c0bede4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bee44; }
goto P_0c0bede6;
P_0c0bede6: /* original 01ee, guest PC 0x0c0bede6 */
if(!s->budget--) { s->failed_pc=0x0c0bede6u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0bede8;
P_0c0bede8: /* original 6313, guest PC 0x0c0bede8 */
if(!s->budget--) { s->failed_pc=0x0c0bede8u; return 0; }
r[3]=r[1];
goto P_0c0bedea;
P_0c0bedea: /* original 4108, guest PC 0x0c0bedea */
if(!s->budget--) { s->failed_pc=0x0c0bedeau; return 0; }
r[1]<<=2;
goto P_0c0bedec;
P_0c0bedec: /* original 4100, guest PC 0x0c0bedec */
if(!s->budget--) { s->failed_pc=0x0c0bedecu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0bedee;
P_0c0bedee: /* original 313c, guest PC 0x0c0bedee */
if(!s->budget--) { s->failed_pc=0x0c0bedeeu; return 0; }
r[1]+=r[3];
goto P_0c0bedf0;
P_0c0bedf0: /* original 4108, guest PC 0x0c0bedf0 */
if(!s->budget--) { s->failed_pc=0x0c0bedf0u; return 0; }
r[1]<<=2;
goto P_0c0bedf2;
P_0c0bedf2: /* original 31bc, guest PC 0x0c0bedf2 */
if(!s->budget--) { s->failed_pc=0x0c0bedf2u; return 0; }
r[1]+=r[11];
goto P_0c0bedf4;
P_0c0bedf4: /* original 5313, guest PC 0x0c0bedf4 */
if(!s->budget--) { s->failed_pc=0x0c0bedf4u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0bedf6;
P_0c0bedf6: /* original 6233, guest PC 0x0c0bedf6 */
if(!s->budget--) { s->failed_pc=0x0c0bedf6u; return 0; }
r[2]=r[3];
goto P_0c0bedf8;
P_0c0bedf8: /* original 420b, guest PC 0x0c0bedf8 */
if(!s->budget--) { s->failed_pc=0x0c0bedf8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0bedfcu;
write(ram,r[15],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bedfcu) { target=s->pc; goto dispatch; }
goto P_0c0bedfc;
P_0c0bedfa: /* original 2f32, guest PC 0x0c0bedfa */
if(!s->budget--) { s->failed_pc=0x0c0bedfau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0bedfc;
P_0c0bedfc: /* original 9067, guest PC 0x0c0bedfc */
if(!s->budget--) { s->failed_pc=0x0c0bedfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beeceu,2);
goto P_0c0bedfe;
P_0c0bedfe: /* original 03ee, guest PC 0x0c0bedfe */
if(!s->budget--) { s->failed_pc=0x0c0bedfeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0bee00;
P_0c0bee00: /* original 6233, guest PC 0x0c0bee00 */
if(!s->budget--) { s->failed_pc=0x0c0bee00u; return 0; }
r[2]=r[3];
goto P_0c0bee02;
P_0c0bee02: /* original 4308, guest PC 0x0c0bee02 */
if(!s->budget--) { s->failed_pc=0x0c0bee02u; return 0; }
r[3]<<=2;
goto P_0c0bee04;
P_0c0bee04: /* original 4300, guest PC 0x0c0bee04 */
if(!s->budget--) { s->failed_pc=0x0c0bee04u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0bee06;
P_0c0bee06: /* original 332c, guest PC 0x0c0bee06 */
if(!s->budget--) { s->failed_pc=0x0c0bee06u; return 0; }
r[3]+=r[2];
goto P_0c0bee08;
P_0c0bee08: /* original 4308, guest PC 0x0c0bee08 */
if(!s->budget--) { s->failed_pc=0x0c0bee08u; return 0; }
r[3]<<=2;
goto P_0c0bee0a;
P_0c0bee0a: /* original 33bc, guest PC 0x0c0bee0a */
if(!s->budget--) { s->failed_pc=0x0c0bee0au; return 0; }
r[3]+=r[11];
goto P_0c0bee0c;
P_0c0bee0c: /* original 5238, guest PC 0x0c0bee0c */
if(!s->budget--) { s->failed_pc=0x0c0bee0cu; return 0; }
r[2]=read(ram,r[3]+32,4);
goto P_0c0bee0e;
P_0c0bee0e: /* original 6323, guest PC 0x0c0bee0e */
if(!s->budget--) { s->failed_pc=0x0c0bee0eu; return 0; }
r[3]=r[2];
goto P_0c0bee10;
P_0c0bee10: /* original 2338, guest PC 0x0c0bee10 */
if(!s->budget--) { s->failed_pc=0x0c0bee10u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0bee12;
P_0c0bee12: /* original 8d03, guest PC 0x0c0bee12 */
if(!s->budget--) { s->failed_pc=0x0c0bee12u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(cond) { goto P_0c0bee1c; }
goto P_0c0bee16;
P_0c0bee14: /* original 2f22, guest PC 0x0c0bee14 */
if(!s->budget--) { s->failed_pc=0x0c0bee14u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0bee16;
P_0c0bee16: /* original 63f2, guest PC 0x0c0bee16 */
if(!s->budget--) { s->failed_pc=0x0c0bee16u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0bee18;
P_0c0bee18: /* original 430b, guest PC 0x0c0bee18 */
if(!s->budget--) { s->failed_pc=0x0c0bee18u; return 0; }
target=r[3];
r[16]=code_base|0x0c0bee1cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bee1cu) { target=s->pc; goto dispatch; }
goto P_0c0bee1c;
P_0c0bee1a: /* original 0009, guest PC 0x0c0bee1a */
if(!s->budget--) { s->failed_pc=0x0c0bee1au; return 0; }
goto P_0c0bee1c;
P_0c0bee1c: /* original 9057, guest PC 0x0c0bee1c */
if(!s->budget--) { s->failed_pc=0x0c0bee1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beeceu,2);
goto P_0c0bee1e;
P_0c0bee1e: /* original e2ff, guest PC 0x0c0bee1e */
if(!s->budget--) { s->failed_pc=0x0c0bee1eu; return 0; }
r[2]=0xffffffffu;
goto P_0c0bee20;
P_0c0bee20: /* original 0e26, guest PC 0x0c0bee20 */
if(!s->budget--) { s->failed_pc=0x0c0bee20u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0bee22;
P_0c0bee22: /* original 7008, guest PC 0x0c0bee22 */
if(!s->budget--) { s->failed_pc=0x0c0bee22u; return 0; }
r[0]+=0x00000008u;
goto P_0c0bee24;
P_0c0bee24: /* original 03ee, guest PC 0x0c0bee24 */
if(!s->budget--) { s->failed_pc=0x0c0bee24u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0bee26;
P_0c0bee26: /* original 2338, guest PC 0x0c0bee26 */
if(!s->budget--) { s->failed_pc=0x0c0bee26u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0bee28;
P_0c0bee28: /* original 8902, guest PC 0x0c0bee28 */
if(!s->budget--) { s->failed_pc=0x0c0bee28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bee30; }
goto P_0c0bee2a;
P_0c0bee2a: /* original 9051, guest PC 0x0c0bee2a */
if(!s->budget--) { s->failed_pc=0x0c0bee2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed0u,2);
goto P_0c0bee2c;
P_0c0bee2c: /* original 490b, guest PC 0x0c0bee2c */
if(!s->budget--) { s->failed_pc=0x0c0bee2cu; return 0; }
target=r[9];
r[16]=code_base|0x0c0bee30u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bee30u) { target=s->pc; goto dispatch; }
goto P_0c0bee30;
P_0c0bee2e: /* original 04ee, guest PC 0x0c0bee2e */
if(!s->budget--) { s->failed_pc=0x0c0bee2eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0bee30;
P_0c0bee30: /* original 904f, guest PC 0x0c0bee30 */
if(!s->budget--) { s->failed_pc=0x0c0bee30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed2u,2);
goto P_0c0bee32;
P_0c0bee32: /* original 03ee, guest PC 0x0c0bee32 */
if(!s->budget--) { s->failed_pc=0x0c0bee32u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0bee34;
P_0c0bee34: /* original 2338, guest PC 0x0c0bee34 */
if(!s->budget--) { s->failed_pc=0x0c0bee34u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0bee36;
P_0c0bee36: /* original 8901, guest PC 0x0c0bee36 */
if(!s->budget--) { s->failed_pc=0x0c0bee36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bee3c; }
goto P_0c0bee38;
P_0c0bee38: /* original 490b, guest PC 0x0c0bee38 */
if(!s->budget--) { s->failed_pc=0x0c0bee38u; return 0; }
target=r[9];
r[16]=code_base|0x0c0bee3cu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bee3cu) { target=s->pc; goto dispatch; }
goto P_0c0bee3c;
P_0c0bee3a: /* original 04ee, guest PC 0x0c0bee3a */
if(!s->budget--) { s->failed_pc=0x0c0bee3au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0bee3c;
P_0c0bee3c: /* original 9049, guest PC 0x0c0bee3c */
if(!s->budget--) { s->failed_pc=0x0c0bee3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed2u,2);
goto P_0c0bee3e;
P_0c0bee3e: /* original 0ea6, guest PC 0x0c0bee3e */
if(!s->budget--) { s->failed_pc=0x0c0bee3eu; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0bee40;
P_0c0bee40: /* original 70f8, guest PC 0x0c0bee40 */
if(!s->budget--) { s->failed_pc=0x0c0bee40u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0bee42;
P_0c0bee42: /* original 0ea6, guest PC 0x0c0bee42 */
if(!s->budget--) { s->failed_pc=0x0c0bee42u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0bee44;
P_0c0bee44: /* original 9346, guest PC 0x0c0bee44 */
if(!s->budget--) { s->failed_pc=0x0c0bee44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed4u,2);
goto P_0c0bee46;
P_0c0bee46: /* original 33ec, guest PC 0x0c0bee46 */
if(!s->budget--) { s->failed_pc=0x0c0bee46u; return 0; }
r[3]+=r[14];
goto P_0c0bee48;
P_0c0bee48: /* original 33dc, guest PC 0x0c0bee48 */
if(!s->budget--) { s->failed_pc=0x0c0bee48u; return 0; }
r[3]+=r[13];
goto P_0c0bee4a;
P_0c0bee4a: /* original 6232, guest PC 0x0c0bee4a */
if(!s->budget--) { s->failed_pc=0x0c0bee4au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0bee4c;
P_0c0bee4c: /* original 2228, guest PC 0x0c0bee4c */
if(!s->budget--) { s->failed_pc=0x0c0bee4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0bee4e;
P_0c0bee4e: /* original 8904, guest PC 0x0c0bee4e */
if(!s->budget--) { s->failed_pc=0x0c0bee4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bee5a; }
goto P_0c0bee50;
P_0c0bee50: /* original 9440, guest PC 0x0c0bee50 */
if(!s->budget--) { s->failed_pc=0x0c0bee50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed4u,2);
goto P_0c0bee52;
P_0c0bee52: /* original 34ec, guest PC 0x0c0bee52 */
if(!s->budget--) { s->failed_pc=0x0c0bee52u; return 0; }
r[4]+=r[14];
goto P_0c0bee54;
P_0c0bee54: /* original 34dc, guest PC 0x0c0bee54 */
if(!s->budget--) { s->failed_pc=0x0c0bee54u; return 0; }
r[4]+=r[13];
goto P_0c0bee56;
P_0c0bee56: /* original 490b, guest PC 0x0c0bee56 */
if(!s->budget--) { s->failed_pc=0x0c0bee56u; return 0; }
target=r[9];
r[16]=code_base|0x0c0bee5au;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bee5au) { target=s->pc; goto dispatch; }
goto P_0c0bee5a;
P_0c0bee58: /* original 6442, guest PC 0x0c0bee58 */
if(!s->budget--) { s->failed_pc=0x0c0bee58u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0bee5a;
P_0c0bee5a: /* original 933c, guest PC 0x0c0bee5a */
if(!s->budget--) { s->failed_pc=0x0c0bee5au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed6u,2);
goto P_0c0bee5c;
P_0c0bee5c: /* original 33ec, guest PC 0x0c0bee5c */
if(!s->budget--) { s->failed_pc=0x0c0bee5cu; return 0; }
r[3]+=r[14];
goto P_0c0bee5e;
P_0c0bee5e: /* original 33dc, guest PC 0x0c0bee5e */
if(!s->budget--) { s->failed_pc=0x0c0bee5eu; return 0; }
r[3]+=r[13];
goto P_0c0bee60;
P_0c0bee60: /* original 6232, guest PC 0x0c0bee60 */
if(!s->budget--) { s->failed_pc=0x0c0bee60u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0bee62;
P_0c0bee62: /* original 2228, guest PC 0x0c0bee62 */
if(!s->budget--) { s->failed_pc=0x0c0bee62u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0bee64;
P_0c0bee64: /* original 8904, guest PC 0x0c0bee64 */
if(!s->budget--) { s->failed_pc=0x0c0bee64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bee70; }
goto P_0c0bee66;
P_0c0bee66: /* original 9436, guest PC 0x0c0bee66 */
if(!s->budget--) { s->failed_pc=0x0c0bee66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed6u,2);
goto P_0c0bee68;
P_0c0bee68: /* original 34ec, guest PC 0x0c0bee68 */
if(!s->budget--) { s->failed_pc=0x0c0bee68u; return 0; }
r[4]+=r[14];
goto P_0c0bee6a;
P_0c0bee6a: /* original 34dc, guest PC 0x0c0bee6a */
if(!s->budget--) { s->failed_pc=0x0c0bee6au; return 0; }
r[4]+=r[13];
goto P_0c0bee6c;
P_0c0bee6c: /* original 490b, guest PC 0x0c0bee6c */
if(!s->budget--) { s->failed_pc=0x0c0bee6cu; return 0; }
target=r[9];
r[16]=code_base|0x0c0bee70u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bee70u) { target=s->pc; goto dispatch; }
goto P_0c0bee70;
P_0c0bee6e: /* original 6442, guest PC 0x0c0bee6e */
if(!s->budget--) { s->failed_pc=0x0c0bee6eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0bee70;
P_0c0bee70: /* original 9330, guest PC 0x0c0bee70 */
if(!s->budget--) { s->failed_pc=0x0c0bee70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed4u,2);
goto P_0c0bee72;
P_0c0bee72: /* original e700, guest PC 0x0c0bee72 */
if(!s->budget--) { s->failed_pc=0x0c0bee72u; return 0; }
r[7]=0x00000000u;
goto P_0c0bee74;
P_0c0bee74: /* original 922f, guest PC 0x0c0bee74 */
if(!s->budget--) { s->failed_pc=0x0c0bee74u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed6u,2);
goto P_0c0bee76;
P_0c0bee76: /* original 33ec, guest PC 0x0c0bee76 */
if(!s->budget--) { s->failed_pc=0x0c0bee76u; return 0; }
r[3]+=r[14];
goto P_0c0bee78;
P_0c0bee78: /* original 33dc, guest PC 0x0c0bee78 */
if(!s->budget--) { s->failed_pc=0x0c0bee78u; return 0; }
r[3]+=r[13];
goto P_0c0bee7a;
P_0c0bee7a: /* original 32ec, guest PC 0x0c0bee7a */
if(!s->budget--) { s->failed_pc=0x0c0bee7au; return 0; }
r[2]+=r[14];
goto P_0c0bee7c;
P_0c0bee7c: /* original 32dc, guest PC 0x0c0bee7c */
if(!s->budget--) { s->failed_pc=0x0c0bee7cu; return 0; }
r[2]+=r[13];
goto P_0c0bee7e;
P_0c0bee7e: /* original 22a2, guest PC 0x0c0bee7e */
if(!s->budget--) { s->failed_pc=0x0c0bee7eu; return 0; }
write(ram,r[2],r[10],4);
goto P_0c0bee80;
P_0c0bee80: /* original 23a2, guest PC 0x0c0bee80 */
if(!s->budget--) { s->failed_pc=0x0c0bee80u; return 0; }
write(ram,r[3],r[10],4);
goto P_0c0bee82;
P_0c0bee82: /* original 9323, guest PC 0x0c0bee82 */
if(!s->budget--) { s->failed_pc=0x0c0bee82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beeccu,2);
goto P_0c0bee84;
P_0c0bee84: /* original 33ec, guest PC 0x0c0bee84 */
if(!s->budget--) { s->failed_pc=0x0c0bee84u; return 0; }
r[3]+=r[14];
goto P_0c0bee86;
P_0c0bee86: /* original 33dc, guest PC 0x0c0bee86 */
if(!s->budget--) { s->failed_pc=0x0c0bee86u; return 0; }
r[3]+=r[13];
goto P_0c0bee88;
P_0c0bee88: /* original 2382, guest PC 0x0c0bee88 */
if(!s->budget--) { s->failed_pc=0x0c0bee88u; return 0; }
write(ram,r[3],r[8],4);
goto P_0c0bee8a;
P_0c0bee8a: /* original 9223, guest PC 0x0c0bee8a */
if(!s->budget--) { s->failed_pc=0x0c0bee8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed4u,2);
goto P_0c0bee8c;
P_0c0bee8c: /* original 32ec, guest PC 0x0c0bee8c */
if(!s->budget--) { s->failed_pc=0x0c0bee8cu; return 0; }
r[2]+=r[14];
goto P_0c0bee8e;
P_0c0bee8e: /* original 32dc, guest PC 0x0c0bee8e */
if(!s->budget--) { s->failed_pc=0x0c0bee8eu; return 0; }
r[2]+=r[13];
goto P_0c0bee90;
P_0c0bee90: /* original 22a2, guest PC 0x0c0bee90 */
if(!s->budget--) { s->failed_pc=0x0c0bee90u; return 0; }
write(ram,r[2],r[10],4);
goto P_0c0bee92;
P_0c0bee92: /* original 9321, guest PC 0x0c0bee92 */
if(!s->budget--) { s->failed_pc=0x0c0bee92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beed8u,2);
goto P_0c0bee94;
P_0c0bee94: /* original 33ec, guest PC 0x0c0bee94 */
if(!s->budget--) { s->failed_pc=0x0c0bee94u; return 0; }
r[3]+=r[14];
goto P_0c0bee96;
P_0c0bee96: /* original 33dc, guest PC 0x0c0bee96 */
if(!s->budget--) { s->failed_pc=0x0c0bee96u; return 0; }
r[3]+=r[13];
goto P_0c0bee98;
P_0c0bee98: /* original 23a2, guest PC 0x0c0bee98 */
if(!s->budget--) { s->failed_pc=0x0c0bee98u; return 0; }
write(ram,r[3],r[10],4);
goto P_0c0bee9a;
P_0c0bee9a: /* original 931e, guest PC 0x0c0bee9a */
if(!s->budget--) { s->failed_pc=0x0c0bee9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beedau,2);
goto P_0c0bee9c;
P_0c0bee9c: /* original 2f36, guest PC 0x0c0bee9c */
if(!s->budget--) { s->failed_pc=0x0c0bee9cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bee9e;
P_0c0bee9e: /* original 6383, guest PC 0x0c0bee9e */
if(!s->budget--) { s->failed_pc=0x0c0bee9eu; return 0; }
r[3]=r[8];
goto P_0c0beea0;
P_0c0beea0: /* original d211, guest PC 0x0c0beea0 */
if(!s->budget--) { s->failed_pc=0x0c0beea0u; return 0; }
r[2]=read(ram,0x0c0beee8u,4);
goto P_0c0beea2;
P_0c0beea2: /* original 4808, guest PC 0x0c0beea2 */
if(!s->budget--) { s->failed_pc=0x0c0beea2u; return 0; }
r[8]<<=2;
goto P_0c0beea4;
P_0c0beea4: /* original 4800, guest PC 0x0c0beea4 */
if(!s->budget--) { s->failed_pc=0x0c0beea4u; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c0beea6;
P_0c0beea6: /* original 2f26, guest PC 0x0c0beea6 */
if(!s->budget--) { s->failed_pc=0x0c0beea6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0beea8;
P_0c0beea8: /* original 2fc6, guest PC 0x0c0beea8 */
if(!s->budget--) { s->failed_pc=0x0c0beea8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0beeaa;
P_0c0beeaa: /* original d011, guest PC 0x0c0beeaa */
if(!s->budget--) { s->failed_pc=0x0c0beeaau; return 0; }
r[0]=read(ram,0x0c0beef0u,4);
goto P_0c0beeac;
P_0c0beeac: /* original d60f, guest PC 0x0c0beeac */
if(!s->budget--) { s->failed_pc=0x0c0beeacu; return 0; }
r[6]=read(ram,0x0c0beeecu,4);
goto P_0c0beeae;
P_0c0beeae: /* original 05de, guest PC 0x0c0beeae */
if(!s->budget--) { s->failed_pc=0x0c0beeaeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0beeb0;
P_0c0beeb0: /* original 383c, guest PC 0x0c0beeb0 */
if(!s->budget--) { s->failed_pc=0x0c0beeb0u; return 0; }
r[8]+=r[3];
goto P_0c0beeb2;
P_0c0beeb2: /* original 4808, guest PC 0x0c0beeb2 */
if(!s->budget--) { s->failed_pc=0x0c0beeb2u; return 0; }
r[8]<<=2;
goto P_0c0beeb4;
P_0c0beeb4: /* original 38bc, guest PC 0x0c0beeb4 */
if(!s->budget--) { s->failed_pc=0x0c0beeb4u; return 0; }
r[8]+=r[11];
goto P_0c0beeb6;
P_0c0beeb6: /* original 1f83, guest PC 0x0c0beeb6 */
if(!s->budget--) { s->failed_pc=0x0c0beeb6u; return 0; }
write(ram,r[15]+12,r[8],4);
goto P_0c0beeb8;
P_0c0beeb8: /* original d30e, guest PC 0x0c0beeb8 */
if(!s->budget--) { s->failed_pc=0x0c0beeb8u; return 0; }
r[3]=read(ram,0x0c0beef4u,4);
goto P_0c0beeba;
P_0c0beeba: /* original 430b, guest PC 0x0c0beeba */
if(!s->budget--) { s->failed_pc=0x0c0beebau; return 0; }
target=r[3];
r[16]=code_base|0x0c0beebeu;
tmp=read(ram,r[8],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0beebeu) { target=s->pc; goto dispatch; }
goto P_0c0beebe;
P_0c0beebc: /* original 6482, guest PC 0x0c0beebc */
if(!s->budget--) { s->failed_pc=0x0c0beebcu; return 0; }
tmp=read(ram,r[8],4);
r[4]=tmp;
goto P_0c0beebe;
P_0c0beebe: /* original 920d, guest PC 0x0c0beebe */
if(!s->budget--) { s->failed_pc=0x0c0beebeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0beedcu,2);
goto P_0c0beec0;
P_0c0beec0: /* original 2f26, guest PC 0x0c0beec0 */
if(!s->budget--) { s->failed_pc=0x0c0beec0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0beec2;
P_0c0beec2: /* original d309, guest PC 0x0c0beec2 */
if(!s->budget--) { s->failed_pc=0x0c0beec2u; return 0; }
r[3]=read(ram,0x0c0beee8u,4);
goto P_0c0beec4;
P_0c0beec4: /* original 2f36, guest PC 0x0c0beec4 */
if(!s->budget--) { s->failed_pc=0x0c0beec4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0beec6;
P_0c0beec6: /* original 2fc6, guest PC 0x0c0beec6 */
if(!s->budget--) { s->failed_pc=0x0c0beec6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0beec8;
P_0c0beec8: /* original a016, guest PC 0x0c0beec8 */
if(!s->budget--) { s->failed_pc=0x0c0beec8u; return 0; }
goto P_0c0beef8;
P_0c0beeca: /* original 0009, guest PC 0x0c0beeca */
if(!s->budget--) { s->failed_pc=0x0c0beecau; return 0; }
if(!vf3_matrix_family(0x0c0beeccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0beeccu; return 0; } return 1;
P_0c0beef8: /* original d354, guest PC 0x0c0beef8 */
if(!s->budget--) { s->failed_pc=0x0c0beef8u; return 0; }
r[3]=read(ram,0x0c0bf04cu,4);
goto P_0c0beefa;
P_0c0beefa: /* original d153, guest PC 0x0c0beefa */
if(!s->budget--) { s->failed_pc=0x0c0beefau; return 0; }
r[1]=read(ram,0x0c0bf048u,4);
goto P_0c0beefc;
P_0c0beefc: /* original 6532, guest PC 0x0c0beefc */
if(!s->budget--) { s->failed_pc=0x0c0beefcu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0beefe;
P_0c0beefe: /* original d354, guest PC 0x0c0beefe */
if(!s->budget--) { s->failed_pc=0x0c0beefeu; return 0; }
r[3]=read(ram,0x0c0bf050u,4);
goto P_0c0bef00;
P_0c0bef00: /* original 54f6, guest PC 0x0c0bef00 */
if(!s->budget--) { s->failed_pc=0x0c0bef00u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0bef02;
P_0c0bef02: /* original 351c, guest PC 0x0c0bef02 */
if(!s->budget--) { s->failed_pc=0x0c0bef02u; return 0; }
r[5]+=r[1];
goto P_0c0bef04;
P_0c0bef04: /* original d74e, guest PC 0x0c0bef04 */
if(!s->budget--) { s->failed_pc=0x0c0bef04u; return 0; }
r[7]=read(ram,0x0c0bf040u,4);
goto P_0c0bef06;
P_0c0bef06: /* original d64f, guest PC 0x0c0bef06 */
if(!s->budget--) { s->failed_pc=0x0c0bef06u; return 0; }
r[6]=read(ram,0x0c0bf044u,4);
goto P_0c0bef08;
P_0c0bef08: /* original 430b, guest PC 0x0c0bef08 */
if(!s->budget--) { s->failed_pc=0x0c0bef08u; return 0; }
target=r[3];
r[16]=code_base|0x0c0bef0cu;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bef0cu) { target=s->pc; goto dispatch; }
goto P_0c0bef0c;
P_0c0bef0a: /* original 5441, guest PC 0x0c0bef0a */
if(!s->budget--) { s->failed_pc=0x0c0bef0au; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0bef0c;
P_0c0bef0c: /* original 7f18, guest PC 0x0c0bef0c */
if(!s->budget--) { s->failed_pc=0x0c0bef0cu; return 0; }
r[15]+=0x00000018u;
goto P_0c0bef0e;
P_0c0bef0e: /* original 7f08, guest PC 0x0c0bef0e */
if(!s->budget--) { s->failed_pc=0x0c0bef0eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0bef10;
P_0c0bef10: /* original 4f26, guest PC 0x0c0bef10 */
if(!s->budget--) { s->failed_pc=0x0c0bef10u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bef12;
P_0c0bef12: /* original 68f6, guest PC 0x0c0bef12 */
if(!s->budget--) { s->failed_pc=0x0c0bef12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0bef14;
P_0c0bef14: /* original 69f6, guest PC 0x0c0bef14 */
if(!s->budget--) { s->failed_pc=0x0c0bef14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bef16;
P_0c0bef16: /* original 6af6, guest PC 0x0c0bef16 */
if(!s->budget--) { s->failed_pc=0x0c0bef16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bef18;
P_0c0bef18: /* original 6bf6, guest PC 0x0c0bef18 */
if(!s->budget--) { s->failed_pc=0x0c0bef18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bef1a;
P_0c0bef1a: /* original 6cf6, guest PC 0x0c0bef1a */
if(!s->budget--) { s->failed_pc=0x0c0bef1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bef1c;
P_0c0bef1c: /* original 6df6, guest PC 0x0c0bef1c */
if(!s->budget--) { s->failed_pc=0x0c0bef1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bef1e;
P_0c0bef1e: /* original 000b, guest PC 0x0c0bef1e */
if(!s->budget--) { s->failed_pc=0x0c0bef1eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bef20: /* original 6ef6, guest PC 0x0c0bef20 */
if(!s->budget--) { s->failed_pc=0x0c0bef20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0bef22u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bef22u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
