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
int vf3_away_batch202_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0a95b4u: goto P_0c0a95b4;
case 0x0c0a95b6u: goto P_0c0a95b6;
case 0x0c0a95b8u: goto P_0c0a95b8;
case 0x0c0a95bau: goto P_0c0a95ba;
case 0x0c0a95bcu: goto P_0c0a95bc;
case 0x0c0a95beu: goto P_0c0a95be;
case 0x0c0a95c0u: goto P_0c0a95c0;
case 0x0c0a95c2u: goto P_0c0a95c2;
case 0x0c0a95c4u: goto P_0c0a95c4;
case 0x0c0a95c6u: goto P_0c0a95c6;
case 0x0c0a95c8u: goto P_0c0a95c8;
case 0x0c0a95cau: goto P_0c0a95ca;
case 0x0c0a95ccu: goto P_0c0a95cc;
case 0x0c0a95ceu: goto P_0c0a95ce;
case 0x0c0a95d0u: goto P_0c0a95d0;
case 0x0c0a95d2u: goto P_0c0a95d2;
case 0x0c0a95d4u: goto P_0c0a95d4;
case 0x0c0a95d6u: goto P_0c0a95d6;
case 0x0c0a95d8u: goto P_0c0a95d8;
case 0x0c0a95dau: goto P_0c0a95da;
case 0x0c0a95dcu: goto P_0c0a95dc;
case 0x0c0a95deu: goto P_0c0a95de;
case 0x0c0a95e0u: goto P_0c0a95e0;
case 0x0c0a95e2u: goto P_0c0a95e2;
case 0x0c0a95e4u: goto P_0c0a95e4;
case 0x0c0a95e6u: goto P_0c0a95e6;
case 0x0c0a95e8u: goto P_0c0a95e8;
case 0x0c0a95eau: goto P_0c0a95ea;
case 0x0c0a95ecu: goto P_0c0a95ec;
case 0x0c0a95eeu: goto P_0c0a95ee;
case 0x0c0a95f0u: goto P_0c0a95f0;
case 0x0c0a95f2u: goto P_0c0a95f2;
case 0x0c0a95f4u: goto P_0c0a95f4;
case 0x0c0a95f6u: goto P_0c0a95f6;
case 0x0c0a95f8u: goto P_0c0a95f8;
case 0x0c0a95fau: goto P_0c0a95fa;
case 0x0c0a95fcu: goto P_0c0a95fc;
case 0x0c0a95feu: goto P_0c0a95fe;
case 0x0c0a9600u: goto P_0c0a9600;
case 0x0c0a9602u: goto P_0c0a9602;
case 0x0c0a9604u: goto P_0c0a9604;
case 0x0c0a9606u: goto P_0c0a9606;
case 0x0c0a9608u: goto P_0c0a9608;
case 0x0c0a960au: goto P_0c0a960a;
case 0x0c0a960cu: goto P_0c0a960c;
case 0x0c0a960eu: goto P_0c0a960e;
case 0x0c0a9610u: goto P_0c0a9610;
case 0x0c0a9612u: goto P_0c0a9612;
case 0x0c0a9614u: goto P_0c0a9614;
case 0x0c0a9616u: goto P_0c0a9616;
case 0x0c0a9618u: goto P_0c0a9618;
case 0x0c0a961au: goto P_0c0a961a;
case 0x0c0a961cu: goto P_0c0a961c;
case 0x0c0a961eu: goto P_0c0a961e;
case 0x0c0a9620u: goto P_0c0a9620;
case 0x0c0a9622u: goto P_0c0a9622;
case 0x0c0a9624u: goto P_0c0a9624;
case 0x0c0a9626u: goto P_0c0a9626;
case 0x0c0a9628u: goto P_0c0a9628;
case 0x0c0a962au: goto P_0c0a962a;
case 0x0c0a962cu: goto P_0c0a962c;
case 0x0c0a962eu: goto P_0c0a962e;
case 0x0c0a9630u: goto P_0c0a9630;
case 0x0c0a9632u: goto P_0c0a9632;
case 0x0c0a9634u: goto P_0c0a9634;
case 0x0c0a9636u: goto P_0c0a9636;
case 0x0c0a9638u: goto P_0c0a9638;
case 0x0c0a963au: goto P_0c0a963a;
case 0x0c0a963cu: goto P_0c0a963c;
case 0x0c0a963eu: goto P_0c0a963e;
case 0x0c0a9640u: goto P_0c0a9640;
case 0x0c0a9642u: goto P_0c0a9642;
case 0x0c0a9644u: goto P_0c0a9644;
case 0x0c0a9646u: goto P_0c0a9646;
case 0x0c0a9648u: goto P_0c0a9648;
case 0x0c0a964au: goto P_0c0a964a;
case 0x0c0a964cu: goto P_0c0a964c;
case 0x0c0a964eu: goto P_0c0a964e;
case 0x0c0a9650u: goto P_0c0a9650;
case 0x0c0a9652u: goto P_0c0a9652;
case 0x0c0a9654u: goto P_0c0a9654;
case 0x0c0a9656u: goto P_0c0a9656;
case 0x0c0a9658u: goto P_0c0a9658;
case 0x0c0a965au: goto P_0c0a965a;
case 0x0c0a965cu: goto P_0c0a965c;
case 0x0c0a965eu: goto P_0c0a965e;
case 0x0c0a9660u: goto P_0c0a9660;
case 0x0c0a9662u: goto P_0c0a9662;
case 0x0c0a9664u: goto P_0c0a9664;
case 0x0c0a9666u: goto P_0c0a9666;
case 0x0c0a9668u: goto P_0c0a9668;
case 0x0c0a966au: goto P_0c0a966a;
case 0x0c0a966cu: goto P_0c0a966c;
case 0x0c0a966eu: goto P_0c0a966e;
case 0x0c0a9670u: goto P_0c0a9670;
case 0x0c0a9672u: goto P_0c0a9672;
case 0x0c0a9674u: goto P_0c0a9674;
case 0x0c0a9676u: goto P_0c0a9676;
case 0x0c0a9678u: goto P_0c0a9678;
case 0x0c0a967au: goto P_0c0a967a;
case 0x0c0a967cu: goto P_0c0a967c;
case 0x0c0a967eu: goto P_0c0a967e;
case 0x0c0a9680u: goto P_0c0a9680;
case 0x0c0a9682u: goto P_0c0a9682;
case 0x0c0a9684u: goto P_0c0a9684;
case 0x0c0a9686u: goto P_0c0a9686;
case 0x0c0a9688u: goto P_0c0a9688;
case 0x0c0a968au: goto P_0c0a968a;
case 0x0c0a968cu: goto P_0c0a968c;
case 0x0c0a968eu: goto P_0c0a968e;
case 0x0c0a9690u: goto P_0c0a9690;
case 0x0c0a9692u: goto P_0c0a9692;
case 0x0c0a9694u: goto P_0c0a9694;
case 0x0c0a9696u: goto P_0c0a9696;
case 0x0c0a9698u: goto P_0c0a9698;
case 0x0c0a969au: goto P_0c0a969a;
case 0x0c0a969cu: goto P_0c0a969c;
case 0x0c0a969eu: goto P_0c0a969e;
case 0x0c0a96a0u: goto P_0c0a96a0;
case 0x0c0a96a2u: goto P_0c0a96a2;
case 0x0c0a96a4u: goto P_0c0a96a4;
case 0x0c0a96a6u: goto P_0c0a96a6;
case 0x0c0a96a8u: goto P_0c0a96a8;
case 0x0c0a96aau: goto P_0c0a96aa;
case 0x0c0a96acu: goto P_0c0a96ac;
case 0x0c0a96aeu: goto P_0c0a96ae;
case 0x0c0a96b0u: goto P_0c0a96b0;
case 0x0c0a96b2u: goto P_0c0a96b2;
case 0x0c0a96b4u: goto P_0c0a96b4;
case 0x0c0a96b6u: goto P_0c0a96b6;
case 0x0c0a96b8u: goto P_0c0a96b8;
case 0x0c0a96bau: goto P_0c0a96ba;
case 0x0c0a96bcu: goto P_0c0a96bc;
case 0x0c0a96beu: goto P_0c0a96be;
case 0x0c0a96c0u: goto P_0c0a96c0;
case 0x0c0a96c2u: goto P_0c0a96c2;
case 0x0c0a96c4u: goto P_0c0a96c4;
case 0x0c0a96c6u: goto P_0c0a96c6;
case 0x0c0a96c8u: goto P_0c0a96c8;
case 0x0c0a96cau: goto P_0c0a96ca;
case 0x0c0a96ccu: goto P_0c0a96cc;
case 0x0c0a96ceu: goto P_0c0a96ce;
case 0x0c0a96d0u: goto P_0c0a96d0;
case 0x0c0a96d2u: goto P_0c0a96d2;
case 0x0c0a96d4u: goto P_0c0a96d4;
case 0x0c0a96d6u: goto P_0c0a96d6;
case 0x0c0a96d8u: goto P_0c0a96d8;
case 0x0c0a96dau: goto P_0c0a96da;
case 0x0c0a96dcu: goto P_0c0a96dc;
case 0x0c0a96deu: goto P_0c0a96de;
case 0x0c0a96e0u: goto P_0c0a96e0;
case 0x0c0a96e2u: goto P_0c0a96e2;
case 0x0c0a96e4u: goto P_0c0a96e4;
case 0x0c0a96e6u: goto P_0c0a96e6;
case 0x0c0a96e8u: goto P_0c0a96e8;
case 0x0c0a96eau: goto P_0c0a96ea;
case 0x0c0a96ecu: goto P_0c0a96ec;
case 0x0c0a96eeu: goto P_0c0a96ee;
case 0x0c0a96f0u: goto P_0c0a96f0;
case 0x0c0a96f2u: goto P_0c0a96f2;
case 0x0c0a96f4u: goto P_0c0a96f4;
case 0x0c0a96f6u: goto P_0c0a96f6;
case 0x0c0a96f8u: goto P_0c0a96f8;
case 0x0c0a96fau: goto P_0c0a96fa;
case 0x0c0a96fcu: goto P_0c0a96fc;
case 0x0c0a96feu: goto P_0c0a96fe;
case 0x0c0a9700u: goto P_0c0a9700;
case 0x0c0a9702u: goto P_0c0a9702;
case 0x0c0a9704u: goto P_0c0a9704;
case 0x0c0a9706u: goto P_0c0a9706;
case 0x0c0a9708u: goto P_0c0a9708;
case 0x0c0a970au: goto P_0c0a970a;
case 0x0c0a970cu: goto P_0c0a970c;
case 0x0c0a970eu: goto P_0c0a970e;
case 0x0c0a9710u: goto P_0c0a9710;
case 0x0c0a9712u: goto P_0c0a9712;
case 0x0c0a9714u: goto P_0c0a9714;
case 0x0c0a9716u: goto P_0c0a9716;
case 0x0c0a9718u: goto P_0c0a9718;
case 0x0c0a971au: goto P_0c0a971a;
case 0x0c0a971cu: goto P_0c0a971c;
case 0x0c0a971eu: goto P_0c0a971e;
case 0x0c0a9720u: goto P_0c0a9720;
case 0x0c0a9722u: goto P_0c0a9722;
case 0x0c0a9724u: goto P_0c0a9724;
case 0x0c0a9726u: goto P_0c0a9726;
case 0x0c0a9780u: goto P_0c0a9780;
case 0x0c0a9782u: goto P_0c0a9782;
case 0x0c0a9784u: goto P_0c0a9784;
case 0x0c0a9786u: goto P_0c0a9786;
case 0x0c0a9788u: goto P_0c0a9788;
case 0x0c0a978au: goto P_0c0a978a;
case 0x0c0a978cu: goto P_0c0a978c;
case 0x0c0a978eu: goto P_0c0a978e;
case 0x0c0a9790u: goto P_0c0a9790;
case 0x0c0a9792u: goto P_0c0a9792;
case 0x0c0a9794u: goto P_0c0a9794;
case 0x0c0a9796u: goto P_0c0a9796;
case 0x0c0a9798u: goto P_0c0a9798;
case 0x0c0a979au: goto P_0c0a979a;
case 0x0c0a979cu: goto P_0c0a979c;
case 0x0c0a979eu: goto P_0c0a979e;
case 0x0c0a97a0u: goto P_0c0a97a0;
case 0x0c0a97a2u: goto P_0c0a97a2;
case 0x0c0a97a4u: goto P_0c0a97a4;
case 0x0c0a97a6u: goto P_0c0a97a6;
case 0x0c0a97a8u: goto P_0c0a97a8;
case 0x0c0a97aau: goto P_0c0a97aa;
case 0x0c0a97acu: goto P_0c0a97ac;
case 0x0c0a97aeu: goto P_0c0a97ae;
case 0x0c0a97b0u: goto P_0c0a97b0;
case 0x0c0a97b2u: goto P_0c0a97b2;
case 0x0c0a97b4u: goto P_0c0a97b4;
case 0x0c0a97b6u: goto P_0c0a97b6;
case 0x0c0a97b8u: goto P_0c0a97b8;
case 0x0c0a97bau: goto P_0c0a97ba;
case 0x0c0a97bcu: goto P_0c0a97bc;
case 0x0c0a97beu: goto P_0c0a97be;
case 0x0c0a97c0u: goto P_0c0a97c0;
case 0x0c0a97c2u: goto P_0c0a97c2;
case 0x0c0a97c4u: goto P_0c0a97c4;
case 0x0c0a97c6u: goto P_0c0a97c6;
case 0x0c0a97c8u: goto P_0c0a97c8;
case 0x0c0a97cau: goto P_0c0a97ca;
case 0x0c0a97ccu: goto P_0c0a97cc;
case 0x0c0a97ceu: goto P_0c0a97ce;
case 0x0c0a97d0u: goto P_0c0a97d0;
case 0x0c0a97d2u: goto P_0c0a97d2;
case 0x0c0a97d4u: goto P_0c0a97d4;
case 0x0c0a97d6u: goto P_0c0a97d6;
case 0x0c0a97d8u: goto P_0c0a97d8;
case 0x0c0a97dau: goto P_0c0a97da;
case 0x0c0a97dcu: goto P_0c0a97dc;
case 0x0c0a97deu: goto P_0c0a97de;
case 0x0c0a97e0u: goto P_0c0a97e0;
case 0x0c0a97e2u: goto P_0c0a97e2;
case 0x0c0a97e4u: goto P_0c0a97e4;
case 0x0c0a97e6u: goto P_0c0a97e6;
case 0x0c0a97f8u: goto P_0c0a97f8;
case 0x0c0a97fau: goto P_0c0a97fa;
case 0x0c0a97fcu: goto P_0c0a97fc;
case 0x0c0a97feu: goto P_0c0a97fe;
case 0x0c0a9800u: goto P_0c0a9800;
case 0x0c0a9802u: goto P_0c0a9802;
case 0x0c0a9804u: goto P_0c0a9804;
case 0x0c0a9806u: goto P_0c0a9806;
case 0x0c0a9808u: goto P_0c0a9808;
case 0x0c0a980au: goto P_0c0a980a;
case 0x0c0a980cu: goto P_0c0a980c;
case 0x0c0a980eu: goto P_0c0a980e;
case 0x0c0a9810u: goto P_0c0a9810;
case 0x0c0a9812u: goto P_0c0a9812;
case 0x0c0a9814u: goto P_0c0a9814;
case 0x0c0a9816u: goto P_0c0a9816;
case 0x0c0a9818u: goto P_0c0a9818;
case 0x0c0a981au: goto P_0c0a981a;
case 0x0c0a981cu: goto P_0c0a981c;
case 0x0c0a981eu: goto P_0c0a981e;
case 0x0c0a9820u: goto P_0c0a9820;
case 0x0c0a9822u: goto P_0c0a9822;
case 0x0c0a9824u: goto P_0c0a9824;
case 0x0c0a9826u: goto P_0c0a9826;
case 0x0c0a9828u: goto P_0c0a9828;
case 0x0c0a982au: goto P_0c0a982a;
case 0x0c0a982cu: goto P_0c0a982c;
case 0x0c0a982eu: goto P_0c0a982e;
case 0x0c0a9830u: goto P_0c0a9830;
case 0x0c0a9832u: goto P_0c0a9832;
case 0x0c0a9834u: goto P_0c0a9834;
case 0x0c0a9836u: goto P_0c0a9836;
case 0x0c0a9838u: goto P_0c0a9838;
case 0x0c0a983au: goto P_0c0a983a;
case 0x0c0a983cu: goto P_0c0a983c;
case 0x0c0a983eu: goto P_0c0a983e;
case 0x0c0a9840u: goto P_0c0a9840;
case 0x0c0a9842u: goto P_0c0a9842;
case 0x0c0a9844u: goto P_0c0a9844;
case 0x0c0a9846u: goto P_0c0a9846;
case 0x0c0a9848u: goto P_0c0a9848;
case 0x0c0a984au: goto P_0c0a984a;
case 0x0c0a984cu: goto P_0c0a984c;
case 0x0c0a984eu: goto P_0c0a984e;
case 0x0c0a9850u: goto P_0c0a9850;
case 0x0c0a9852u: goto P_0c0a9852;
case 0x0c0a9854u: goto P_0c0a9854;
case 0x0c0a9856u: goto P_0c0a9856;
case 0x0c0a9858u: goto P_0c0a9858;
case 0x0c0a985au: goto P_0c0a985a;
case 0x0c0a985cu: goto P_0c0a985c;
case 0x0c0a985eu: goto P_0c0a985e;
case 0x0c0a9860u: goto P_0c0a9860;
case 0x0c0a9862u: goto P_0c0a9862;
case 0x0c0a9864u: goto P_0c0a9864;
case 0x0c0a9866u: goto P_0c0a9866;
case 0x0c0a9868u: goto P_0c0a9868;
case 0x0c0a986au: goto P_0c0a986a;
case 0x0c0a986cu: goto P_0c0a986c;
case 0x0c0a986eu: goto P_0c0a986e;
case 0x0c0a9870u: goto P_0c0a9870;
case 0x0c0a9872u: goto P_0c0a9872;
case 0x0c0a9874u: goto P_0c0a9874;
case 0x0c0a9876u: goto P_0c0a9876;
case 0x0c0a9878u: goto P_0c0a9878;
case 0x0c0a987au: goto P_0c0a987a;
case 0x0c0a987cu: goto P_0c0a987c;
case 0x0c0a987eu: goto P_0c0a987e;
case 0x0c0a9880u: goto P_0c0a9880;
case 0x0c0a9882u: goto P_0c0a9882;
case 0x0c0a9884u: goto P_0c0a9884;
case 0x0c0a9886u: goto P_0c0a9886;
case 0x0c0a9888u: goto P_0c0a9888;
case 0x0c0a988au: goto P_0c0a988a;
case 0x0c0a988cu: goto P_0c0a988c;
case 0x0c0a988eu: goto P_0c0a988e;
case 0x0c0a9890u: goto P_0c0a9890;
case 0x0c0a9892u: goto P_0c0a9892;
case 0x0c0a9894u: goto P_0c0a9894;
case 0x0c0a9896u: goto P_0c0a9896;
case 0x0c0a9898u: goto P_0c0a9898;
case 0x0c0a989au: goto P_0c0a989a;
case 0x0c0a989cu: goto P_0c0a989c;
case 0x0c0a989eu: goto P_0c0a989e;
case 0x0c0a98a0u: goto P_0c0a98a0;
case 0x0c0a98a2u: goto P_0c0a98a2;
case 0x0c0a98a4u: goto P_0c0a98a4;
case 0x0c0a98a6u: goto P_0c0a98a6;
case 0x0c0a98a8u: goto P_0c0a98a8;
case 0x0c0a98aau: goto P_0c0a98aa;
case 0x0c0a98acu: goto P_0c0a98ac;
case 0x0c0a98aeu: goto P_0c0a98ae;
case 0x0c0a98b0u: goto P_0c0a98b0;
case 0x0c0a98b2u: goto P_0c0a98b2;
case 0x0c0a98b4u: goto P_0c0a98b4;
case 0x0c0a98b6u: goto P_0c0a98b6;
case 0x0c0a98b8u: goto P_0c0a98b8;
case 0x0c0a98bau: goto P_0c0a98ba;
case 0x0c0a98bcu: goto P_0c0a98bc;
case 0x0c0a98beu: goto P_0c0a98be;
case 0x0c0a98c0u: goto P_0c0a98c0;
case 0x0c0a98c2u: goto P_0c0a98c2;
case 0x0c0a98c4u: goto P_0c0a98c4;
case 0x0c0a98c6u: goto P_0c0a98c6;
case 0x0c0a98c8u: goto P_0c0a98c8;
case 0x0c0a98cau: goto P_0c0a98ca;
case 0x0c0a98ccu: goto P_0c0a98cc;
case 0x0c0a98ceu: goto P_0c0a98ce;
case 0x0c0a98d0u: goto P_0c0a98d0;
case 0x0c0a98d2u: goto P_0c0a98d2;
case 0x0c0a98d4u: goto P_0c0a98d4;
case 0x0c0a98d6u: goto P_0c0a98d6;
case 0x0c0a98d8u: goto P_0c0a98d8;
case 0x0c0a98dau: goto P_0c0a98da;
case 0x0c0a98dcu: goto P_0c0a98dc;
case 0x0c0a98deu: goto P_0c0a98de;
case 0x0c0a98e0u: goto P_0c0a98e0;
case 0x0c0a98e2u: goto P_0c0a98e2;
case 0x0c0a98e4u: goto P_0c0a98e4;
case 0x0c0a98e6u: goto P_0c0a98e6;
case 0x0c0a98e8u: goto P_0c0a98e8;
case 0x0c0a98eau: goto P_0c0a98ea;
case 0x0c0a98ecu: goto P_0c0a98ec;
case 0x0c0a98eeu: goto P_0c0a98ee;
case 0x0c0a98f0u: goto P_0c0a98f0;
case 0x0c0a98f2u: goto P_0c0a98f2;
case 0x0c0a98f4u: goto P_0c0a98f4;
case 0x0c0a98f6u: goto P_0c0a98f6;
case 0x0c0a98f8u: goto P_0c0a98f8;
case 0x0c0a9928u: goto P_0c0a9928;
case 0x0c0a992au: goto P_0c0a992a;
case 0x0c0a992cu: goto P_0c0a992c;
case 0x0c0a992eu: goto P_0c0a992e;
case 0x0c0a9930u: goto P_0c0a9930;
case 0x0c0a9932u: goto P_0c0a9932;
case 0x0c0a9934u: goto P_0c0a9934;
case 0x0c0a9936u: goto P_0c0a9936;
case 0x0c0a9938u: goto P_0c0a9938;
case 0x0c0a993au: goto P_0c0a993a;
case 0x0c0a993cu: goto P_0c0a993c;
case 0x0c0a993eu: goto P_0c0a993e;
case 0x0c0a9940u: goto P_0c0a9940;
case 0x0c0a9942u: goto P_0c0a9942;
case 0x0c0a9944u: goto P_0c0a9944;
case 0x0c0a9946u: goto P_0c0a9946;
case 0x0c0a9948u: goto P_0c0a9948;
case 0x0c0a994au: goto P_0c0a994a;
case 0x0c0a994cu: goto P_0c0a994c;
case 0x0c0a994eu: goto P_0c0a994e;
case 0x0c0a9950u: goto P_0c0a9950;
case 0x0c0a9952u: goto P_0c0a9952;
case 0x0c0a9954u: goto P_0c0a9954;
case 0x0c0a9956u: goto P_0c0a9956;
case 0x0c0a9958u: goto P_0c0a9958;
case 0x0c0a995au: goto P_0c0a995a;
case 0x0c0a995cu: goto P_0c0a995c;
case 0x0c0a995eu: goto P_0c0a995e;
case 0x0c0a9960u: goto P_0c0a9960;
case 0x0c0a9962u: goto P_0c0a9962;
case 0x0c0a9964u: goto P_0c0a9964;
case 0x0c0a9966u: goto P_0c0a9966;
case 0x0c0a9968u: goto P_0c0a9968;
case 0x0c0a996au: goto P_0c0a996a;
case 0x0c0a996cu: goto P_0c0a996c;
case 0x0c0a996eu: goto P_0c0a996e;
case 0x0c0a9970u: goto P_0c0a9970;
case 0x0c0a9972u: goto P_0c0a9972;
case 0x0c0a9974u: goto P_0c0a9974;
case 0x0c0a9976u: goto P_0c0a9976;
case 0x0c0a9978u: goto P_0c0a9978;
case 0x0c0a997au: goto P_0c0a997a;
case 0x0c0a997cu: goto P_0c0a997c;
case 0x0c0a997eu: goto P_0c0a997e;
case 0x0c0a9980u: goto P_0c0a9980;
case 0x0c0a9982u: goto P_0c0a9982;
case 0x0c0a9984u: goto P_0c0a9984;
case 0x0c0a9986u: goto P_0c0a9986;
case 0x0c0a9988u: goto P_0c0a9988;
case 0x0c0a998au: goto P_0c0a998a;
case 0x0c0a998cu: goto P_0c0a998c;
case 0x0c0a998eu: goto P_0c0a998e;
case 0x0c0a9990u: goto P_0c0a9990;
case 0x0c0a9992u: goto P_0c0a9992;
case 0x0c0a9994u: goto P_0c0a9994;
case 0x0c0a9996u: goto P_0c0a9996;
case 0x0c0a9998u: goto P_0c0a9998;
case 0x0c0a999au: goto P_0c0a999a;
case 0x0c0a999cu: goto P_0c0a999c;
case 0x0c0a999eu: goto P_0c0a999e;
case 0x0c0a99a0u: goto P_0c0a99a0;
case 0x0c0a99a2u: goto P_0c0a99a2;
case 0x0c0a99a4u: goto P_0c0a99a4;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0a95b4: /* original 2fe6, guest PC 0x0c0a95b4 */
if(!s->budget--) { s->failed_pc=0x0c0a95b4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a95b6;
P_0c0a95b6: /* original 2fd6, guest PC 0x0c0a95b6 */
if(!s->budget--) { s->failed_pc=0x0c0a95b6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a95b8;
P_0c0a95b8: /* original 2fc6, guest PC 0x0c0a95b8 */
if(!s->budget--) { s->failed_pc=0x0c0a95b8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a95ba;
P_0c0a95ba: /* original 2fb6, guest PC 0x0c0a95ba */
if(!s->budget--) { s->failed_pc=0x0c0a95bau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a95bc;
P_0c0a95bc: /* original 2fa6, guest PC 0x0c0a95bc */
if(!s->budget--) { s->failed_pc=0x0c0a95bcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a95be;
P_0c0a95be: /* original 2f96, guest PC 0x0c0a95be */
if(!s->budget--) { s->failed_pc=0x0c0a95beu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a95c0;
P_0c0a95c0: /* original 4f22, guest PC 0x0c0a95c0 */
if(!s->budget--) { s->failed_pc=0x0c0a95c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a95c2;
P_0c0a95c2: /* original 7ff8, guest PC 0x0c0a95c2 */
if(!s->budget--) { s->failed_pc=0x0c0a95c2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a95c4;
P_0c0a95c4: /* original 1f41, guest PC 0x0c0a95c4 */
if(!s->budget--) { s->failed_pc=0x0c0a95c4u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a95c6;
P_0c0a95c6: /* original d36a, guest PC 0x0c0a95c6 */
if(!s->budget--) { s->failed_pc=0x0c0a95c6u; return 0; }
r[3]=read(ram,0x0c0a9770u,4);
goto P_0c0a95c8;
P_0c0a95c8: /* original db68, guest PC 0x0c0a95c8 */
if(!s->budget--) { s->failed_pc=0x0c0a95c8u; return 0; }
r[11]=read(ram,0x0c0a976cu,4);
goto P_0c0a95ca;
P_0c0a95ca: /* original d967, guest PC 0x0c0a95ca */
if(!s->budget--) { s->failed_pc=0x0c0a95cau; return 0; }
r[9]=read(ram,0x0c0a9768u,4);
goto P_0c0a95cc;
P_0c0a95cc: /* original 2f32, guest PC 0x0c0a95cc */
if(!s->budget--) { s->failed_pc=0x0c0a95ccu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a95ce;
P_0c0a95ce: /* original 5ef1, guest PC 0x0c0a95ce */
if(!s->budget--) { s->failed_pc=0x0c0a95ceu; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c0a95d0;
P_0c0a95d0: /* original dc68, guest PC 0x0c0a95d0 */
if(!s->budget--) { s->failed_pc=0x0c0a95d0u; return 0; }
r[12]=read(ram,0x0c0a9774u,4);
goto P_0c0a95d2;
P_0c0a95d2: /* original d369, guest PC 0x0c0a95d2 */
if(!s->budget--) { s->failed_pc=0x0c0a95d2u; return 0; }
r[3]=read(ram,0x0c0a9778u,4);
goto P_0c0a95d4;
P_0c0a95d4: /* original d269, guest PC 0x0c0a95d4 */
if(!s->budget--) { s->failed_pc=0x0c0a95d4u; return 0; }
r[2]=read(ram,0x0c0a977cu,4);
goto P_0c0a95d6;
P_0c0a95d6: /* original 420b, guest PC 0x0c0a95d6 */
if(!s->budget--) { s->failed_pc=0x0c0a95d6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a95dau;
write(ram,r[14]+12,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a95dau) { target=s->pc; goto dispatch; }
goto P_0c0a95da;
P_0c0a95d8: /* original 1e33, guest PC 0x0c0a95d8 */
if(!s->budget--) { s->failed_pc=0x0c0a95d8u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0a95da;
P_0c0a95da: /* original 2008, guest PC 0x0c0a95da */
if(!s->budget--) { s->failed_pc=0x0c0a95dau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a95dc;
P_0c0a95dc: /* original 8b01, guest PC 0x0c0a95dc */
if(!s->budget--) { s->failed_pc=0x0c0a95dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a95e2; }
goto P_0c0a95de;
P_0c0a95de: /* original a1d9, guest PC 0x0c0a95de */
if(!s->budget--) { s->failed_pc=0x0c0a95deu; return 0; }
goto P_0c0a9994;
P_0c0a95e0: /* original 0009, guest PC 0x0c0a95e0 */
if(!s->budget--) { s->failed_pc=0x0c0a95e0u; return 0; }
goto P_0c0a95e2;
P_0c0a95e2: /* original e400, guest PC 0x0c0a95e2 */
if(!s->budget--) { s->failed_pc=0x0c0a95e2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a95e4;
P_0c0a95e4: /* original 1e4e, guest PC 0x0c0a95e4 */
if(!s->budget--) { s->failed_pc=0x0c0a95e4u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c0a95e6;
P_0c0a95e6: /* original 1e4d, guest PC 0x0c0a95e6 */
if(!s->budget--) { s->failed_pc=0x0c0a95e6u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c0a95e8;
P_0c0a95e8: /* original 909e, guest PC 0x0c0a95e8 */
if(!s->budget--) { s->failed_pc=0x0c0a95e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9728u,2);
goto P_0c0a95ea;
P_0c0a95ea: /* original 0e46, guest PC 0x0c0a95ea */
if(!s->budget--) { s->failed_pc=0x0c0a95eau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a95ec;
P_0c0a95ec: /* original e048, guest PC 0x0c0a95ec */
if(!s->budget--) { s->failed_pc=0x0c0a95ecu; return 0; }
r[0]=0x00000048u;
goto P_0c0a95ee;
P_0c0a95ee: /* original 0e46, guest PC 0x0c0a95ee */
if(!s->budget--) { s->failed_pc=0x0c0a95eeu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a95f0;
P_0c0a95f0: /* original e04c, guest PC 0x0c0a95f0 */
if(!s->budget--) { s->failed_pc=0x0c0a95f0u; return 0; }
r[0]=0x0000004cu;
goto P_0c0a95f2;
P_0c0a95f2: /* original 0e46, guest PC 0x0c0a95f2 */
if(!s->budget--) { s->failed_pc=0x0c0a95f2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a95f4;
P_0c0a95f4: /* original e024, guest PC 0x0c0a95f4 */
if(!s->budget--) { s->failed_pc=0x0c0a95f4u; return 0; }
r[0]=0x00000024u;
goto P_0c0a95f6;
P_0c0a95f6: /* original f48d, guest PC 0x0c0a95f6 */
if(!s->budget--) { s->failed_pc=0x0c0a95f6u; return 0; }
fr[4]=0;
goto P_0c0a95f8;
P_0c0a95f8: /* original fe47, guest PC 0x0c0a95f8 */
if(!s->budget--) { s->failed_pc=0x0c0a95f8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a95fa;
P_0c0a95fa: /* original e028, guest PC 0x0c0a95fa */
if(!s->budget--) { s->failed_pc=0x0c0a95fau; return 0; }
r[0]=0x00000028u;
goto P_0c0a95fc;
P_0c0a95fc: /* original fe47, guest PC 0x0c0a95fc */
if(!s->budget--) { s->failed_pc=0x0c0a95fcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a95fe;
P_0c0a95fe: /* original e02c, guest PC 0x0c0a95fe */
if(!s->budget--) { s->failed_pc=0x0c0a95feu; return 0; }
r[0]=0x0000002cu;
goto P_0c0a9600;
P_0c0a9600: /* original fe47, guest PC 0x0c0a9600 */
if(!s->budget--) { s->failed_pc=0x0c0a9600u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9602;
P_0c0a9602: /* original 9092, guest PC 0x0c0a9602 */
if(!s->budget--) { s->failed_pc=0x0c0a9602u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a972au,2);
goto P_0c0a9604;
P_0c0a9604: /* original fe47, guest PC 0x0c0a9604 */
if(!s->budget--) { s->failed_pc=0x0c0a9604u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9606;
P_0c0a9606: /* original 7004, guest PC 0x0c0a9606 */
if(!s->budget--) { s->failed_pc=0x0c0a9606u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a9608;
P_0c0a9608: /* original fe47, guest PC 0x0c0a9608 */
if(!s->budget--) { s->failed_pc=0x0c0a9608u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a960a;
P_0c0a960a: /* original 7004, guest PC 0x0c0a960a */
if(!s->budget--) { s->failed_pc=0x0c0a960au; return 0; }
r[0]+=0x00000004u;
goto P_0c0a960c;
P_0c0a960c: /* original fe47, guest PC 0x0c0a960c */
if(!s->budget--) { s->failed_pc=0x0c0a960cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a960e;
P_0c0a960e: /* original 70f4, guest PC 0x0c0a960e */
if(!s->budget--) { s->failed_pc=0x0c0a960eu; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0a9610;
P_0c0a9610: /* original fe47, guest PC 0x0c0a9610 */
if(!s->budget--) { s->failed_pc=0x0c0a9610u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9612;
P_0c0a9612: /* original 908b, guest PC 0x0c0a9612 */
if(!s->budget--) { s->failed_pc=0x0c0a9612u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a972cu,2);
goto P_0c0a9614;
P_0c0a9614: /* original 0e45, guest PC 0x0c0a9614 */
if(!s->budget--) { s->failed_pc=0x0c0a9614u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9616;
P_0c0a9616: /* original 908a, guest PC 0x0c0a9616 */
if(!s->budget--) { s->failed_pc=0x0c0a9616u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a972eu,2);
goto P_0c0a9618;
P_0c0a9618: /* original 0e46, guest PC 0x0c0a9618 */
if(!s->budget--) { s->failed_pc=0x0c0a9618u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a961a;
P_0c0a961a: /* original 702a, guest PC 0x0c0a961a */
if(!s->budget--) { s->failed_pc=0x0c0a961au; return 0; }
r[0]+=0x0000002au;
goto P_0c0a961c;
P_0c0a961c: /* original 0e45, guest PC 0x0c0a961c */
if(!s->budget--) { s->failed_pc=0x0c0a961cu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a961e;
P_0c0a961e: /* original 7002, guest PC 0x0c0a961e */
if(!s->budget--) { s->failed_pc=0x0c0a961eu; return 0; }
r[0]+=0x00000002u;
goto P_0c0a9620;
P_0c0a9620: /* original 0e45, guest PC 0x0c0a9620 */
if(!s->budget--) { s->failed_pc=0x0c0a9620u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9622;
P_0c0a9622: /* original 7002, guest PC 0x0c0a9622 */
if(!s->budget--) { s->failed_pc=0x0c0a9622u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a9624;
P_0c0a9624: /* original 0e45, guest PC 0x0c0a9624 */
if(!s->budget--) { s->failed_pc=0x0c0a9624u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9626;
P_0c0a9626: /* original 7012, guest PC 0x0c0a9626 */
if(!s->budget--) { s->failed_pc=0x0c0a9626u; return 0; }
r[0]+=0x00000012u;
goto P_0c0a9628;
P_0c0a9628: /* original 0e46, guest PC 0x0c0a9628 */
if(!s->budget--) { s->failed_pc=0x0c0a9628u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a962a;
P_0c0a962a: /* original 9081, guest PC 0x0c0a962a */
if(!s->budget--) { s->failed_pc=0x0c0a962au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9730u,2);
goto P_0c0a962c;
P_0c0a962c: /* original fe47, guest PC 0x0c0a962c */
if(!s->budget--) { s->failed_pc=0x0c0a962cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a962e;
P_0c0a962e: /* original 9080, guest PC 0x0c0a962e */
if(!s->budget--) { s->failed_pc=0x0c0a962eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9732u,2);
goto P_0c0a9630;
P_0c0a9630: /* original 0e44, guest PC 0x0c0a9630 */
if(!s->budget--) { s->failed_pc=0x0c0a9630u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9632;
P_0c0a9632: /* original 7001, guest PC 0x0c0a9632 */
if(!s->budget--) { s->failed_pc=0x0c0a9632u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a9634;
P_0c0a9634: /* original 0e44, guest PC 0x0c0a9634 */
if(!s->budget--) { s->failed_pc=0x0c0a9634u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9636;
P_0c0a9636: /* original 907d, guest PC 0x0c0a9636 */
if(!s->budget--) { s->failed_pc=0x0c0a9636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9734u,2);
goto P_0c0a9638;
P_0c0a9638: /* original 0e44, guest PC 0x0c0a9638 */
if(!s->budget--) { s->failed_pc=0x0c0a9638u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a963a;
P_0c0a963a: /* original 703f, guest PC 0x0c0a963a */
if(!s->budget--) { s->failed_pc=0x0c0a963au; return 0; }
r[0]+=0x0000003fu;
goto P_0c0a963c;
P_0c0a963c: /* original 0e44, guest PC 0x0c0a963c */
if(!s->budget--) { s->failed_pc=0x0c0a963cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a963e;
P_0c0a963e: /* original e066, guest PC 0x0c0a963e */
if(!s->budget--) { s->failed_pc=0x0c0a963eu; return 0; }
r[0]=0x00000066u;
goto P_0c0a9640;
P_0c0a9640: /* original 0e45, guest PC 0x0c0a9640 */
if(!s->budget--) { s->failed_pc=0x0c0a9640u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9642;
P_0c0a9642: /* original 9078, guest PC 0x0c0a9642 */
if(!s->budget--) { s->failed_pc=0x0c0a9642u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9736u,2);
goto P_0c0a9644;
P_0c0a9644: /* original 0e45, guest PC 0x0c0a9644 */
if(!s->budget--) { s->failed_pc=0x0c0a9644u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9646;
P_0c0a9646: /* original 9077, guest PC 0x0c0a9646 */
if(!s->budget--) { s->failed_pc=0x0c0a9646u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9738u,2);
goto P_0c0a9648;
P_0c0a9648: /* original 0e45, guest PC 0x0c0a9648 */
if(!s->budget--) { s->failed_pc=0x0c0a9648u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a964a;
P_0c0a964a: /* original 9076, guest PC 0x0c0a964a */
if(!s->budget--) { s->failed_pc=0x0c0a964au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a973au,2);
goto P_0c0a964c;
P_0c0a964c: /* original 0e44, guest PC 0x0c0a964c */
if(!s->budget--) { s->failed_pc=0x0c0a964cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a964e;
P_0c0a964e: /* original 703c, guest PC 0x0c0a964e */
if(!s->budget--) { s->failed_pc=0x0c0a964eu; return 0; }
r[0]+=0x0000003cu;
goto P_0c0a9650;
P_0c0a9650: /* original 0e46, guest PC 0x0c0a9650 */
if(!s->budget--) { s->failed_pc=0x0c0a9650u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a9652;
P_0c0a9652: /* original 0e46, guest PC 0x0c0a9652 */
if(!s->budget--) { s->failed_pc=0x0c0a9652u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a9654;
P_0c0a9654: /* original 70c5, guest PC 0x0c0a9654 */
if(!s->budget--) { s->failed_pc=0x0c0a9654u; return 0; }
r[0]+=0xffffffc5u;
goto P_0c0a9656;
P_0c0a9656: /* original 0e44, guest PC 0x0c0a9656 */
if(!s->budget--) { s->failed_pc=0x0c0a9656u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9658;
P_0c0a9658: /* original 9070, guest PC 0x0c0a9658 */
if(!s->budget--) { s->failed_pc=0x0c0a9658u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a973cu,2);
goto P_0c0a965a;
P_0c0a965a: /* original fe47, guest PC 0x0c0a965a */
if(!s->budget--) { s->failed_pc=0x0c0a965au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a965c;
P_0c0a965c: /* original 7004, guest PC 0x0c0a965c */
if(!s->budget--) { s->failed_pc=0x0c0a965cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0a965e;
P_0c0a965e: /* original fe47, guest PC 0x0c0a965e */
if(!s->budget--) { s->failed_pc=0x0c0a965eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9660;
P_0c0a9660: /* original 7004, guest PC 0x0c0a9660 */
if(!s->budget--) { s->failed_pc=0x0c0a9660u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a9662;
P_0c0a9662: /* original fe47, guest PC 0x0c0a9662 */
if(!s->budget--) { s->failed_pc=0x0c0a9662u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9664;
P_0c0a9664: /* original 906b, guest PC 0x0c0a9664 */
if(!s->budget--) { s->failed_pc=0x0c0a9664u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a973eu,2);
goto P_0c0a9666;
P_0c0a9666: /* original fe47, guest PC 0x0c0a9666 */
if(!s->budget--) { s->failed_pc=0x0c0a9666u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9668;
P_0c0a9668: /* original 7004, guest PC 0x0c0a9668 */
if(!s->budget--) { s->failed_pc=0x0c0a9668u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a966a;
P_0c0a966a: /* original fe47, guest PC 0x0c0a966a */
if(!s->budget--) { s->failed_pc=0x0c0a966au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a966c;
P_0c0a966c: /* original 7004, guest PC 0x0c0a966c */
if(!s->budget--) { s->failed_pc=0x0c0a966cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0a966e;
P_0c0a966e: /* original fe47, guest PC 0x0c0a966e */
if(!s->budget--) { s->failed_pc=0x0c0a966eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9670;
P_0c0a9670: /* original 9066, guest PC 0x0c0a9670 */
if(!s->budget--) { s->failed_pc=0x0c0a9670u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9740u,2);
goto P_0c0a9672;
P_0c0a9672: /* original 0e45, guest PC 0x0c0a9672 */
if(!s->budget--) { s->failed_pc=0x0c0a9672u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9674;
P_0c0a9674: /* original 9065, guest PC 0x0c0a9674 */
if(!s->budget--) { s->failed_pc=0x0c0a9674u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9742u,2);
goto P_0c0a9676;
P_0c0a9676: /* original 0e44, guest PC 0x0c0a9676 */
if(!s->budget--) { s->failed_pc=0x0c0a9676u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9678;
P_0c0a9678: /* original 7004, guest PC 0x0c0a9678 */
if(!s->budget--) { s->failed_pc=0x0c0a9678u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a967a;
P_0c0a967a: /* original 0e45, guest PC 0x0c0a967a */
if(!s->budget--) { s->failed_pc=0x0c0a967au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a967c;
P_0c0a967c: /* original 7002, guest PC 0x0c0a967c */
if(!s->budget--) { s->failed_pc=0x0c0a967cu; return 0; }
r[0]+=0x00000002u;
goto P_0c0a967e;
P_0c0a967e: /* original 0e45, guest PC 0x0c0a967e */
if(!s->budget--) { s->failed_pc=0x0c0a967eu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9680;
P_0c0a9680: /* original 7002, guest PC 0x0c0a9680 */
if(!s->budget--) { s->failed_pc=0x0c0a9680u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a9682;
P_0c0a9682: /* original 0e45, guest PC 0x0c0a9682 */
if(!s->budget--) { s->failed_pc=0x0c0a9682u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9684;
P_0c0a9684: /* original 7002, guest PC 0x0c0a9684 */
if(!s->budget--) { s->failed_pc=0x0c0a9684u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a9686;
P_0c0a9686: /* original 0e45, guest PC 0x0c0a9686 */
if(!s->budget--) { s->failed_pc=0x0c0a9686u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9688;
P_0c0a9688: /* original 7002, guest PC 0x0c0a9688 */
if(!s->budget--) { s->failed_pc=0x0c0a9688u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a968a;
P_0c0a968a: /* original 0e45, guest PC 0x0c0a968a */
if(!s->budget--) { s->failed_pc=0x0c0a968au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a968c;
P_0c0a968c: /* original 7002, guest PC 0x0c0a968c */
if(!s->budget--) { s->failed_pc=0x0c0a968cu; return 0; }
r[0]+=0x00000002u;
goto P_0c0a968e;
P_0c0a968e: /* original 0e45, guest PC 0x0c0a968e */
if(!s->budget--) { s->failed_pc=0x0c0a968eu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9690;
P_0c0a9690: /* original 7002, guest PC 0x0c0a9690 */
if(!s->budget--) { s->failed_pc=0x0c0a9690u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a9692;
P_0c0a9692: /* original 0e45, guest PC 0x0c0a9692 */
if(!s->budget--) { s->failed_pc=0x0c0a9692u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9694;
P_0c0a9694: /* original 7002, guest PC 0x0c0a9694 */
if(!s->budget--) { s->failed_pc=0x0c0a9694u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a9696;
P_0c0a9696: /* original 0e45, guest PC 0x0c0a9696 */
if(!s->budget--) { s->failed_pc=0x0c0a9696u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9698;
P_0c0a9698: /* original 7002, guest PC 0x0c0a9698 */
if(!s->budget--) { s->failed_pc=0x0c0a9698u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a969a;
P_0c0a969a: /* original 0e45, guest PC 0x0c0a969a */
if(!s->budget--) { s->failed_pc=0x0c0a969au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a969c;
P_0c0a969c: /* original 70ef, guest PC 0x0c0a969c */
if(!s->budget--) { s->failed_pc=0x0c0a969cu; return 0; }
r[0]+=0xffffffefu;
goto P_0c0a969e;
P_0c0a969e: /* original 0e44, guest PC 0x0c0a969e */
if(!s->budget--) { s->failed_pc=0x0c0a969eu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a96a0;
P_0c0a96a0: /* original 70ff, guest PC 0x0c0a96a0 */
if(!s->budget--) { s->failed_pc=0x0c0a96a0u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a96a2;
P_0c0a96a2: /* original 0e44, guest PC 0x0c0a96a2 */
if(!s->budget--) { s->failed_pc=0x0c0a96a2u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a96a4;
P_0c0a96a4: /* original 702a, guest PC 0x0c0a96a4 */
if(!s->budget--) { s->failed_pc=0x0c0a96a4u; return 0; }
r[0]+=0x0000002au;
goto P_0c0a96a6;
P_0c0a96a6: /* original 0e45, guest PC 0x0c0a96a6 */
if(!s->budget--) { s->failed_pc=0x0c0a96a6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96a8;
P_0c0a96a8: /* original 701a, guest PC 0x0c0a96a8 */
if(!s->budget--) { s->failed_pc=0x0c0a96a8u; return 0; }
r[0]+=0x0000001au;
goto P_0c0a96aa;
P_0c0a96aa: /* original 0e45, guest PC 0x0c0a96aa */
if(!s->budget--) { s->failed_pc=0x0c0a96aau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96ac;
P_0c0a96ac: /* original 904a, guest PC 0x0c0a96ac */
if(!s->budget--) { s->failed_pc=0x0c0a96acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9744u,2);
goto P_0c0a96ae;
P_0c0a96ae: /* original 0e44, guest PC 0x0c0a96ae */
if(!s->budget--) { s->failed_pc=0x0c0a96aeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a96b0;
P_0c0a96b0: /* original 9049, guest PC 0x0c0a96b0 */
if(!s->budget--) { s->failed_pc=0x0c0a96b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9746u,2);
goto P_0c0a96b2;
P_0c0a96b2: /* original 0e46, guest PC 0x0c0a96b2 */
if(!s->budget--) { s->failed_pc=0x0c0a96b2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a96b4;
P_0c0a96b4: /* original 9048, guest PC 0x0c0a96b4 */
if(!s->budget--) { s->failed_pc=0x0c0a96b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9748u,2);
goto P_0c0a96b6;
P_0c0a96b6: /* original 0e46, guest PC 0x0c0a96b6 */
if(!s->budget--) { s->failed_pc=0x0c0a96b6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a96b8;
P_0c0a96b8: /* original 7004, guest PC 0x0c0a96b8 */
if(!s->budget--) { s->failed_pc=0x0c0a96b8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a96ba;
P_0c0a96ba: /* original 0e46, guest PC 0x0c0a96ba */
if(!s->budget--) { s->failed_pc=0x0c0a96bau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a96bc;
P_0c0a96bc: /* original 9045, guest PC 0x0c0a96bc */
if(!s->budget--) { s->failed_pc=0x0c0a96bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a974au,2);
goto P_0c0a96be;
P_0c0a96be: /* original 0e45, guest PC 0x0c0a96be */
if(!s->budget--) { s->failed_pc=0x0c0a96beu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96c0;
P_0c0a96c0: /* original 9044, guest PC 0x0c0a96c0 */
if(!s->budget--) { s->failed_pc=0x0c0a96c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a974cu,2);
goto P_0c0a96c2;
P_0c0a96c2: /* original 0e45, guest PC 0x0c0a96c2 */
if(!s->budget--) { s->failed_pc=0x0c0a96c2u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96c4;
P_0c0a96c4: /* original 70fe, guest PC 0x0c0a96c4 */
if(!s->budget--) { s->failed_pc=0x0c0a96c4u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0a96c6;
P_0c0a96c6: /* original 0e45, guest PC 0x0c0a96c6 */
if(!s->budget--) { s->failed_pc=0x0c0a96c6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96c8;
P_0c0a96c8: /* original 70fe, guest PC 0x0c0a96c8 */
if(!s->budget--) { s->failed_pc=0x0c0a96c8u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0a96ca;
P_0c0a96ca: /* original 0e45, guest PC 0x0c0a96ca */
if(!s->budget--) { s->failed_pc=0x0c0a96cau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96cc;
P_0c0a96cc: /* original 903f, guest PC 0x0c0a96cc */
if(!s->budget--) { s->failed_pc=0x0c0a96ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a974eu,2);
goto P_0c0a96ce;
P_0c0a96ce: /* original 0e45, guest PC 0x0c0a96ce */
if(!s->budget--) { s->failed_pc=0x0c0a96ceu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96d0;
P_0c0a96d0: /* original 903e, guest PC 0x0c0a96d0 */
if(!s->budget--) { s->failed_pc=0x0c0a96d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9750u,2);
goto P_0c0a96d2;
P_0c0a96d2: /* original 0e45, guest PC 0x0c0a96d2 */
if(!s->budget--) { s->failed_pc=0x0c0a96d2u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96d4;
P_0c0a96d4: /* original 903d, guest PC 0x0c0a96d4 */
if(!s->budget--) { s->failed_pc=0x0c0a96d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9752u,2);
goto P_0c0a96d6;
P_0c0a96d6: /* original 0e44, guest PC 0x0c0a96d6 */
if(!s->budget--) { s->failed_pc=0x0c0a96d6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a96d8;
P_0c0a96d8: /* original 7001, guest PC 0x0c0a96d8 */
if(!s->budget--) { s->failed_pc=0x0c0a96d8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a96da;
P_0c0a96da: /* original 0e44, guest PC 0x0c0a96da */
if(!s->budget--) { s->failed_pc=0x0c0a96dau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a96dc;
P_0c0a96dc: /* original 7001, guest PC 0x0c0a96dc */
if(!s->budget--) { s->failed_pc=0x0c0a96dcu; return 0; }
r[0]+=0x00000001u;
goto P_0c0a96de;
P_0c0a96de: /* original 0e45, guest PC 0x0c0a96de */
if(!s->budget--) { s->failed_pc=0x0c0a96deu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96e0;
P_0c0a96e0: /* original 7002, guest PC 0x0c0a96e0 */
if(!s->budget--) { s->failed_pc=0x0c0a96e0u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a96e2;
P_0c0a96e2: /* original 0e45, guest PC 0x0c0a96e2 */
if(!s->budget--) { s->failed_pc=0x0c0a96e2u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96e4;
P_0c0a96e4: /* original 7002, guest PC 0x0c0a96e4 */
if(!s->budget--) { s->failed_pc=0x0c0a96e4u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a96e6;
P_0c0a96e6: /* original 0e44, guest PC 0x0c0a96e6 */
if(!s->budget--) { s->failed_pc=0x0c0a96e6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a96e8;
P_0c0a96e8: /* original 9034, guest PC 0x0c0a96e8 */
if(!s->budget--) { s->failed_pc=0x0c0a96e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9754u,2);
goto P_0c0a96ea;
P_0c0a96ea: /* original 0e45, guest PC 0x0c0a96ea */
if(!s->budget--) { s->failed_pc=0x0c0a96eau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96ec;
P_0c0a96ec: /* original 7002, guest PC 0x0c0a96ec */
if(!s->budget--) { s->failed_pc=0x0c0a96ecu; return 0; }
r[0]+=0x00000002u;
goto P_0c0a96ee;
P_0c0a96ee: /* original 0e45, guest PC 0x0c0a96ee */
if(!s->budget--) { s->failed_pc=0x0c0a96eeu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96f0;
P_0c0a96f0: /* original 7002, guest PC 0x0c0a96f0 */
if(!s->budget--) { s->failed_pc=0x0c0a96f0u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a96f2;
P_0c0a96f2: /* original 0e44, guest PC 0x0c0a96f2 */
if(!s->budget--) { s->failed_pc=0x0c0a96f2u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a96f4;
P_0c0a96f4: /* original 902f, guest PC 0x0c0a96f4 */
if(!s->budget--) { s->failed_pc=0x0c0a96f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9756u,2);
goto P_0c0a96f6;
P_0c0a96f6: /* original 0e45, guest PC 0x0c0a96f6 */
if(!s->budget--) { s->failed_pc=0x0c0a96f6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96f8;
P_0c0a96f8: /* original 7002, guest PC 0x0c0a96f8 */
if(!s->budget--) { s->failed_pc=0x0c0a96f8u; return 0; }
r[0]+=0x00000002u;
goto P_0c0a96fa;
P_0c0a96fa: /* original 0e45, guest PC 0x0c0a96fa */
if(!s->budget--) { s->failed_pc=0x0c0a96fau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a96fc;
P_0c0a96fc: /* original 7002, guest PC 0x0c0a96fc */
if(!s->budget--) { s->failed_pc=0x0c0a96fcu; return 0; }
r[0]+=0x00000002u;
goto P_0c0a96fe;
P_0c0a96fe: /* original 0e44, guest PC 0x0c0a96fe */
if(!s->budget--) { s->failed_pc=0x0c0a96feu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9700;
P_0c0a9700: /* original 902a, guest PC 0x0c0a9700 */
if(!s->budget--) { s->failed_pc=0x0c0a9700u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9758u,2);
goto P_0c0a9702;
P_0c0a9702: /* original 0e45, guest PC 0x0c0a9702 */
if(!s->budget--) { s->failed_pc=0x0c0a9702u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9704;
P_0c0a9704: /* original 9029, guest PC 0x0c0a9704 */
if(!s->budget--) { s->failed_pc=0x0c0a9704u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a975au,2);
goto P_0c0a9706;
P_0c0a9706: /* original 0e45, guest PC 0x0c0a9706 */
if(!s->budget--) { s->failed_pc=0x0c0a9706u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9708;
P_0c0a9708: /* original 9028, guest PC 0x0c0a9708 */
if(!s->budget--) { s->failed_pc=0x0c0a9708u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a975cu,2);
goto P_0c0a970a;
P_0c0a970a: /* original 0e45, guest PC 0x0c0a970a */
if(!s->budget--) { s->failed_pc=0x0c0a970au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a970c;
P_0c0a970c: /* original 9027, guest PC 0x0c0a970c */
if(!s->budget--) { s->failed_pc=0x0c0a970cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a975eu,2);
goto P_0c0a970e;
P_0c0a970e: /* original 0e45, guest PC 0x0c0a970e */
if(!s->budget--) { s->failed_pc=0x0c0a970eu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9710;
P_0c0a9710: /* original 9026, guest PC 0x0c0a9710 */
if(!s->budget--) { s->failed_pc=0x0c0a9710u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9760u,2);
goto P_0c0a9712;
P_0c0a9712: /* original 0e46, guest PC 0x0c0a9712 */
if(!s->budget--) { s->failed_pc=0x0c0a9712u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a9714;
P_0c0a9714: /* original 70ad, guest PC 0x0c0a9714 */
if(!s->budget--) { s->failed_pc=0x0c0a9714u; return 0; }
r[0]+=0xffffffadu;
goto P_0c0a9716;
P_0c0a9716: /* original 0e44, guest PC 0x0c0a9716 */
if(!s->budget--) { s->failed_pc=0x0c0a9716u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9718;
P_0c0a9718: /* original 70f3, guest PC 0x0c0a9718 */
if(!s->budget--) { s->failed_pc=0x0c0a9718u; return 0; }
r[0]+=0xfffffff3u;
goto P_0c0a971a;
P_0c0a971a: /* original fe47, guest PC 0x0c0a971a */
if(!s->budget--) { s->failed_pc=0x0c0a971au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a971c;
P_0c0a971c: /* original 9021, guest PC 0x0c0a971c */
if(!s->budget--) { s->failed_pc=0x0c0a971cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9762u,2);
goto P_0c0a971e;
P_0c0a971e: /* original fe47, guest PC 0x0c0a971e */
if(!s->budget--) { s->failed_pc=0x0c0a971eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9720;
P_0c0a9720: /* original 9020, guest PC 0x0c0a9720 */
if(!s->budget--) { s->failed_pc=0x0c0a9720u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9764u,2);
goto P_0c0a9722;
P_0c0a9722: /* original 0e44, guest PC 0x0c0a9722 */
if(!s->budget--) { s->failed_pc=0x0c0a9722u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9724;
P_0c0a9724: /* original a02c, guest PC 0x0c0a9724 */
if(!s->budget--) { s->failed_pc=0x0c0a9724u; return 0; }
goto P_0c0a9780;
P_0c0a9726: /* original 0009, guest PC 0x0c0a9726 */
if(!s->budget--) { s->failed_pc=0x0c0a9726u; return 0; }
if(!vf3_matrix_family(0x0c0a9728u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9728u; return 0; } return 1;
P_0c0a9780: /* original d31a, guest PC 0x0c0a9780 */
if(!s->budget--) { s->failed_pc=0x0c0a9780u; return 0; }
r[3]=read(ram,0x0c0a97ecu,4);
goto P_0c0a9782;
P_0c0a9782: /* original 5492, guest PC 0x0c0a9782 */
if(!s->budget--) { s->failed_pc=0x0c0a9782u; return 0; }
r[4]=read(ram,r[9]+8,4);
goto P_0c0a9784;
P_0c0a9784: /* original 9030, guest PC 0x0c0a9784 */
if(!s->budget--) { s->failed_pc=0x0c0a9784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a97e8u,2);
goto P_0c0a9786;
P_0c0a9786: /* original 2348, guest PC 0x0c0a9786 */
if(!s->budget--) { s->failed_pc=0x0c0a9786u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a9788;
P_0c0a9788: /* original 8d02, guest PC 0x0c0a9788 */
if(!s->budget--) { s->failed_pc=0x0c0a9788u; return 0; }
cond=r[17]&1u;
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(cond) { goto P_0c0a9790; }
goto P_0c0a978c;
P_0c0a978a: /* original 0ded, guest PC 0x0c0a978a */
if(!s->budget--) { s->failed_pc=0x0c0a978au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a978c;
P_0c0a978c: /* original a03f, guest PC 0x0c0a978c */
if(!s->budget--) { s->failed_pc=0x0c0a978cu; return 0; }
r[13]=0x0000000fu;
goto P_0c0a980e;
P_0c0a978e: /* original ed0f, guest PC 0x0c0a978e */
if(!s->budget--) { s->failed_pc=0x0c0a978eu; return 0; }
r[13]=0x0000000fu;
goto P_0c0a9790;
P_0c0a9790: /* original e204, guest PC 0x0c0a9790 */
if(!s->budget--) { s->failed_pc=0x0c0a9790u; return 0; }
r[2]=0x00000004u;
goto P_0c0a9792;
P_0c0a9792: /* original 2428, guest PC 0x0c0a9792 */
if(!s->budget--) { s->failed_pc=0x0c0a9792u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0a9794;
P_0c0a9794: /* original 893b, guest PC 0x0c0a9794 */
if(!s->budget--) { s->failed_pc=0x0c0a9794u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a980e; }
goto P_0c0a9796;
P_0c0a9796: /* original e01c, guest PC 0x0c0a9796 */
if(!s->budget--) { s->failed_pc=0x0c0a9796u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a9798;
P_0c0a9798: /* original 009c, guest PC 0x0c0a9798 */
if(!s->budget--) { s->failed_pc=0x0c0a9798u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0a979a;
P_0c0a979a: /* original 600c, guest PC 0x0c0a979a */
if(!s->budget--) { s->failed_pc=0x0c0a979au; return 0; }
r[0]=r[0]&255u;
goto P_0c0a979c;
P_0c0a979c: /* original 8801, guest PC 0x0c0a979c */
if(!s->budget--) { s->failed_pc=0x0c0a979cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a979e;
P_0c0a979e: /* original 8936, guest PC 0x0c0a979e */
if(!s->budget--) { s->failed_pc=0x0c0a979eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a980e; }
goto P_0c0a97a0;
P_0c0a97a0: /* original e319, guest PC 0x0c0a97a0 */
if(!s->budget--) { s->failed_pc=0x0c0a97a0u; return 0; }
r[3]=0x00000019u;
goto P_0c0a97a2;
P_0c0a97a2: /* original 84e4, guest PC 0x0c0a97a2 */
if(!s->budget--) { s->failed_pc=0x0c0a97a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0a97a4;
P_0c0a97a4: /* original 339c, guest PC 0x0c0a97a4 */
if(!s->budget--) { s->failed_pc=0x0c0a97a4u; return 0; }
r[3]+=r[9];
goto P_0c0a97a6;
P_0c0a97a6: /* original 6330, guest PC 0x0c0a97a6 */
if(!s->budget--) { s->failed_pc=0x0c0a97a6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c0a97a8;
P_0c0a97a8: /* original 3030, guest PC 0x0c0a97a8 */
if(!s->budget--) { s->failed_pc=0x0c0a97a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c0a97aa;
P_0c0a97aa: /* original 8b30, guest PC 0x0c0a97aa */
if(!s->budget--) { s->failed_pc=0x0c0a97aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a980e; }
goto P_0c0a97ac;
P_0c0a97ac: /* original d310, guest PC 0x0c0a97ac */
if(!s->budget--) { s->failed_pc=0x0c0a97acu; return 0; }
r[3]=read(ram,0x0c0a97f0u,4);
goto P_0c0a97ae;
P_0c0a97ae: /* original 6af2, guest PC 0x0c0a97ae */
if(!s->budget--) { s->failed_pc=0x0c0a97aeu; return 0; }
tmp=read(ram,r[15],4);
r[10]=tmp;
goto P_0c0a97b0;
P_0c0a97b0: /* original 6433, guest PC 0x0c0a97b0 */
if(!s->budget--) { s->failed_pc=0x0c0a97b0u; return 0; }
r[4]=r[3];
goto P_0c0a97b2;
P_0c0a97b2: /* original 85a1, guest PC 0x0c0a97b2 */
if(!s->budget--) { s->failed_pc=0x0c0a97b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+2,2);
goto P_0c0a97b4;
P_0c0a97b4: /* original 2f32, guest PC 0x0c0a97b4 */
if(!s->budget--) { s->failed_pc=0x0c0a97b4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a97b6;
P_0c0a97b6: /* original d30f, guest PC 0x0c0a97b6 */
if(!s->budget--) { s->failed_pc=0x0c0a97b6u; return 0; }
r[3]=read(ram,0x0c0a97f4u,4);
goto P_0c0a97b8;
P_0c0a97b8: /* original 6a03, guest PC 0x0c0a97b8 */
if(!s->budget--) { s->failed_pc=0x0c0a97b8u; return 0; }
r[10]=r[0];
goto P_0c0a97ba;
P_0c0a97ba: /* original 430b, guest PC 0x0c0a97ba */
if(!s->budget--) { s->failed_pc=0x0c0a97bau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a97beu;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a97beu) { target=s->pc; goto dispatch; }
goto P_0c0a97be;
P_0c0a97bc: /* original 7414, guest PC 0x0c0a97bc */
if(!s->budget--) { s->failed_pc=0x0c0a97bcu; return 0; }
r[4]+=0x00000014u;
goto P_0c0a97be;
P_0c0a97be: /* original 640c, guest PC 0x0c0a97be */
if(!s->budget--) { s->failed_pc=0x0c0a97beu; return 0; }
r[4]=r[0]&255u;
goto P_0c0a97c0;
P_0c0a97c0: /* original 6043, guest PC 0x0c0a97c0 */
if(!s->budget--) { s->failed_pc=0x0c0a97c0u; return 0; }
r[0]=r[4];
goto P_0c0a97c2;
P_0c0a97c2: /* original 8801, guest PC 0x0c0a97c2 */
if(!s->budget--) { s->failed_pc=0x0c0a97c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a97c4;
P_0c0a97c4: /* original 8923, guest PC 0x0c0a97c4 */
if(!s->budget--) { s->failed_pc=0x0c0a97c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a980e; }
goto P_0c0a97c6;
P_0c0a97c6: /* original 6043, guest PC 0x0c0a97c6 */
if(!s->budget--) { s->failed_pc=0x0c0a97c6u; return 0; }
r[0]=r[4];
goto P_0c0a97c8;
P_0c0a97c8: /* original 8802, guest PC 0x0c0a97c8 */
if(!s->budget--) { s->failed_pc=0x0c0a97c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a97ca;
P_0c0a97ca: /* original 8b03, guest PC 0x0c0a97ca */
if(!s->budget--) { s->failed_pc=0x0c0a97cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a97d4; }
goto P_0c0a97cc;
P_0c0a97cc: /* original e046, guest PC 0x0c0a97cc */
if(!s->budget--) { s->failed_pc=0x0c0a97ccu; return 0; }
r[0]=0x00000046u;
goto P_0c0a97ce;
P_0c0a97ce: /* original 0ded, guest PC 0x0c0a97ce */
if(!s->budget--) { s->failed_pc=0x0c0a97ceu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a97d0;
P_0c0a97d0: /* original a01d, guest PC 0x0c0a97d0 */
if(!s->budget--) { s->failed_pc=0x0c0a97d0u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0a980e;
P_0c0a97d2: /* original 6ddd, guest PC 0x0c0a97d2 */
if(!s->budget--) { s->failed_pc=0x0c0a97d2u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0a97d4;
P_0c0a97d4: /* original 2448, guest PC 0x0c0a97d4 */
if(!s->budget--) { s->failed_pc=0x0c0a97d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a97d6;
P_0c0a97d6: /* original 8b1a, guest PC 0x0c0a97d6 */
if(!s->budget--) { s->failed_pc=0x0c0a97d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a980e; }
goto P_0c0a97d8;
P_0c0a97d8: /* original 9007, guest PC 0x0c0a97d8 */
if(!s->budget--) { s->failed_pc=0x0c0a97d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a97eau,2);
goto P_0c0a97da;
P_0c0a97da: /* original 049e, guest PC 0x0c0a97da */
if(!s->budget--) { s->failed_pc=0x0c0a97dau; return 0; }
r[4]=read(ram,r[9]+r[0],4);
goto P_0c0a97dc;
P_0c0a97dc: /* original e018, guest PC 0x0c0a97dc */
if(!s->budget--) { s->failed_pc=0x0c0a97dcu; return 0; }
r[0]=0x00000018u;
goto P_0c0a97de;
P_0c0a97de: /* original 039c, guest PC 0x0c0a97de */
if(!s->budget--) { s->failed_pc=0x0c0a97deu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0a97e0;
P_0c0a97e0: /* original 2338, guest PC 0x0c0a97e0 */
if(!s->budget--) { s->failed_pc=0x0c0a97e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a97e2;
P_0c0a97e2: /* original 8b09, guest PC 0x0c0a97e2 */
if(!s->budget--) { s->failed_pc=0x0c0a97e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a97f8; }
goto P_0c0a97e4;
P_0c0a97e4: /* original a00c, guest PC 0x0c0a97e4 */
if(!s->budget--) { s->failed_pc=0x0c0a97e4u; return 0; }
r[5]=0x0000001eu;
goto P_0c0a9800;
P_0c0a97e6: /* original e51e, guest PC 0x0c0a97e6 */
if(!s->budget--) { s->failed_pc=0x0c0a97e6u; return 0; }
r[5]=0x0000001eu;
if(!vf3_matrix_family(0x0c0a97e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a97e8u; return 0; } return 1;
P_0c0a97f8: /* original 009c, guest PC 0x0c0a97f8 */
if(!s->budget--) { s->failed_pc=0x0c0a97f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0a97fa;
P_0c0a97fa: /* original e514, guest PC 0x0c0a97fa */
if(!s->budget--) { s->failed_pc=0x0c0a97fau; return 0; }
r[5]=0x00000014u;
goto P_0c0a97fc;
P_0c0a97fc: /* original 600c, guest PC 0x0c0a97fc */
if(!s->budget--) { s->failed_pc=0x0c0a97fcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0a97fe;
P_0c0a97fe: /* original 8801, guest PC 0x0c0a97fe */
if(!s->budget--) { s->failed_pc=0x0c0a97feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9800;
P_0c0a9800: /* original e3fa, guest PC 0x0c0a9800 */
if(!s->budget--) { s->failed_pc=0x0c0a9800u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a9802;
P_0c0a9802: /* original 443c, guest PC 0x0c0a9802 */
if(!s->budget--) { s->failed_pc=0x0c0a9802u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a9804;
P_0c0a9804: /* original 345c, guest PC 0x0c0a9804 */
if(!s->budget--) { s->failed_pc=0x0c0a9804u; return 0; }
r[4]+=r[5];
goto P_0c0a9806;
P_0c0a9806: /* original 3a4c, guest PC 0x0c0a9806 */
if(!s->budget--) { s->failed_pc=0x0c0a9806u; return 0; }
r[10]+=r[4];
goto P_0c0a9808;
P_0c0a9808: /* original 3ad3, guest PC 0x0c0a9808 */
if(!s->budget--) { s->failed_pc=0x0c0a9808u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[13])!=0);
goto P_0c0a980a;
P_0c0a980a: /* original 8900, guest PC 0x0c0a980a */
if(!s->budget--) { s->failed_pc=0x0c0a980au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a980e; }
goto P_0c0a980c;
P_0c0a980c: /* original 6da3, guest PC 0x0c0a980c */
if(!s->budget--) { s->failed_pc=0x0c0a980cu; return 0; }
r[13]=r[10];
goto P_0c0a980e;
P_0c0a980e: /* original e046, guest PC 0x0c0a980e */
if(!s->budget--) { s->failed_pc=0x0c0a980eu; return 0; }
r[0]=0x00000046u;
goto P_0c0a9810;
P_0c0a9810: /* original 0ed5, guest PC 0x0c0a9810 */
if(!s->budget--) { s->failed_pc=0x0c0a9810u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0a9812;
P_0c0a9812: /* original 9072, guest PC 0x0c0a9812 */
if(!s->budget--) { s->failed_pc=0x0c0a9812u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a98fau,2);
goto P_0c0a9814;
P_0c0a9814: /* original 0ed5, guest PC 0x0c0a9814 */
if(!s->budget--) { s->failed_pc=0x0c0a9814u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0a9816;
P_0c0a9816: /* original e060, guest PC 0x0c0a9816 */
if(!s->budget--) { s->failed_pc=0x0c0a9816u; return 0; }
r[0]=0x00000060u;
goto P_0c0a9818;
P_0c0a9818: /* original 04ec, guest PC 0x0c0a9818 */
if(!s->budget--) { s->failed_pc=0x0c0a9818u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a981a;
P_0c0a981a: /* original 604c, guest PC 0x0c0a981a */
if(!s->budget--) { s->failed_pc=0x0c0a981au; return 0; }
r[0]=r[4]&255u;
goto P_0c0a981c;
P_0c0a981c: /* original 880c, guest PC 0x0c0a981c */
if(!s->budget--) { s->failed_pc=0x0c0a981cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a981e;
P_0c0a981e: /* original 8f05, guest PC 0x0c0a981e */
if(!s->budget--) { s->failed_pc=0x0c0a981eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0a982c; }
goto P_0c0a9822;
P_0c0a9820: /* original 6403, guest PC 0x0c0a9820 */
if(!s->budget--) { s->failed_pc=0x0c0a9820u; return 0; }
r[4]=r[0];
goto P_0c0a9822;
P_0c0a9822: /* original 906b, guest PC 0x0c0a9822 */
if(!s->budget--) { s->failed_pc=0x0c0a9822u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a98fcu,2);
goto P_0c0a9824;
P_0c0a9824: /* original 02bc, guest PC 0x0c0a9824 */
if(!s->budget--) { s->failed_pc=0x0c0a9824u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0a9826;
P_0c0a9826: /* original 2228, guest PC 0x0c0a9826 */
if(!s->budget--) { s->failed_pc=0x0c0a9826u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a9828;
P_0c0a9828: /* original 8900, guest PC 0x0c0a9828 */
if(!s->budget--) { s->failed_pc=0x0c0a9828u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a982c; }
goto P_0c0a982a;
P_0c0a982a: /* original e41a, guest PC 0x0c0a982a */
if(!s->budget--) { s->failed_pc=0x0c0a982au; return 0; }
r[4]=0x0000001au;
goto P_0c0a982c;
P_0c0a982c: /* original d039, guest PC 0x0c0a982c */
if(!s->budget--) { s->failed_pc=0x0c0a982cu; return 0; }
r[0]=read(ram,0x0c0a9914u,4);
goto P_0c0a982e;
P_0c0a982e: /* original 4408, guest PC 0x0c0a982e */
if(!s->budget--) { s->failed_pc=0x0c0a982eu; return 0; }
r[4]<<=2;
goto P_0c0a9830;
P_0c0a9830: /* original 044e, guest PC 0x0c0a9830 */
if(!s->budget--) { s->failed_pc=0x0c0a9830u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0a9832;
P_0c0a9832: /* original e054, guest PC 0x0c0a9832 */
if(!s->budget--) { s->failed_pc=0x0c0a9832u; return 0; }
r[0]=0x00000054u;
goto P_0c0a9834;
P_0c0a9834: /* original 0e46, guest PC 0x0c0a9834 */
if(!s->budget--) { s->failed_pc=0x0c0a9834u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a9836;
P_0c0a9836: /* original e058, guest PC 0x0c0a9836 */
if(!s->budget--) { s->failed_pc=0x0c0a9836u; return 0; }
r[0]=0x00000058u;
goto P_0c0a9838;
P_0c0a9838: /* original 5342, guest PC 0x0c0a9838 */
if(!s->budget--) { s->failed_pc=0x0c0a9838u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0a983a;
P_0c0a983a: /* original 0e36, guest PC 0x0c0a983a */
if(!s->budget--) { s->failed_pc=0x0c0a983au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0a983c;
P_0c0a983c: /* original e00c, guest PC 0x0c0a983c */
if(!s->budget--) { s->failed_pc=0x0c0a983cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a983e;
P_0c0a983e: /* original f346, guest PC 0x0c0a983e */
if(!s->budget--) { s->failed_pc=0x0c0a983eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a9840;
P_0c0a9840: /* original 905d, guest PC 0x0c0a9840 */
if(!s->budget--) { s->failed_pc=0x0c0a9840u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a98feu,2);
goto P_0c0a9842;
P_0c0a9842: /* original fe37, guest PC 0x0c0a9842 */
if(!s->budget--) { s->failed_pc=0x0c0a9842u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a9844;
P_0c0a9844: /* original e010, guest PC 0x0c0a9844 */
if(!s->budget--) { s->failed_pc=0x0c0a9844u; return 0; }
r[0]=0x00000010u;
goto P_0c0a9846;
P_0c0a9846: /* original f346, guest PC 0x0c0a9846 */
if(!s->budget--) { s->failed_pc=0x0c0a9846u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a9848;
P_0c0a9848: /* original 905a, guest PC 0x0c0a9848 */
if(!s->budget--) { s->failed_pc=0x0c0a9848u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9900u,2);
goto P_0c0a984a;
P_0c0a984a: /* original fe37, guest PC 0x0c0a984a */
if(!s->budget--) { s->failed_pc=0x0c0a984au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a984c;
P_0c0a984c: /* original e014, guest PC 0x0c0a984c */
if(!s->budget--) { s->failed_pc=0x0c0a984cu; return 0; }
r[0]=0x00000014u;
goto P_0c0a984e;
P_0c0a984e: /* original f346, guest PC 0x0c0a984e */
if(!s->budget--) { s->failed_pc=0x0c0a984eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a9850;
P_0c0a9850: /* original 9057, guest PC 0x0c0a9850 */
if(!s->budget--) { s->failed_pc=0x0c0a9850u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9902u,2);
goto P_0c0a9852;
P_0c0a9852: /* original fe37, guest PC 0x0c0a9852 */
if(!s->budget--) { s->failed_pc=0x0c0a9852u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a9854;
P_0c0a9854: /* original e018, guest PC 0x0c0a9854 */
if(!s->budget--) { s->failed_pc=0x0c0a9854u; return 0; }
r[0]=0x00000018u;
goto P_0c0a9856;
P_0c0a9856: /* original f346, guest PC 0x0c0a9856 */
if(!s->budget--) { s->failed_pc=0x0c0a9856u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a9858;
P_0c0a9858: /* original 9054, guest PC 0x0c0a9858 */
if(!s->budget--) { s->failed_pc=0x0c0a9858u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9904u,2);
goto P_0c0a985a;
P_0c0a985a: /* original fe37, guest PC 0x0c0a985a */
if(!s->budget--) { s->failed_pc=0x0c0a985au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a985c;
P_0c0a985c: /* original e01c, guest PC 0x0c0a985c */
if(!s->budget--) { s->failed_pc=0x0c0a985cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0a985e;
P_0c0a985e: /* original f346, guest PC 0x0c0a985e */
if(!s->budget--) { s->failed_pc=0x0c0a985eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a9860;
P_0c0a9860: /* original 9051, guest PC 0x0c0a9860 */
if(!s->budget--) { s->failed_pc=0x0c0a9860u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9906u,2);
goto P_0c0a9862;
P_0c0a9862: /* original fe37, guest PC 0x0c0a9862 */
if(!s->budget--) { s->failed_pc=0x0c0a9862u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a9864;
P_0c0a9864: /* original e022, guest PC 0x0c0a9864 */
if(!s->budget--) { s->failed_pc=0x0c0a9864u; return 0; }
r[0]=0x00000022u;
goto P_0c0a9866;
P_0c0a9866: /* original 034d, guest PC 0x0c0a9866 */
if(!s->budget--) { s->failed_pc=0x0c0a9866u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a9868;
P_0c0a9868: /* original 904e, guest PC 0x0c0a9868 */
if(!s->budget--) { s->failed_pc=0x0c0a9868u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9908u,2);
goto P_0c0a986a;
P_0c0a986a: /* original 0e35, guest PC 0x0c0a986a */
if(!s->budget--) { s->failed_pc=0x0c0a986au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a986c;
P_0c0a986c: /* original 62b2, guest PC 0x0c0a986c */
if(!s->budget--) { s->failed_pc=0x0c0a986cu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0a986e;
P_0c0a986e: /* original d32a, guest PC 0x0c0a986e */
if(!s->budget--) { s->failed_pc=0x0c0a986eu; return 0; }
r[3]=read(ram,0x0c0a9918u,4);
goto P_0c0a9870;
P_0c0a9870: /* original 2238, guest PC 0x0c0a9870 */
if(!s->budget--) { s->failed_pc=0x0c0a9870u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a9872;
P_0c0a9872: /* original 8908, guest PC 0x0c0a9872 */
if(!s->budget--) { s->failed_pc=0x0c0a9872u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9886; }
goto P_0c0a9874;
P_0c0a9874: /* original 51b1, guest PC 0x0c0a9874 */
if(!s->budget--) { s->failed_pc=0x0c0a9874u; return 0; }
r[1]=read(ram,r[11]+4,4);
goto P_0c0a9876;
P_0c0a9876: /* original d229, guest PC 0x0c0a9876 */
if(!s->budget--) { s->failed_pc=0x0c0a9876u; return 0; }
r[2]=read(ram,0x0c0a991cu,4);
goto P_0c0a9878;
P_0c0a9878: /* original 2128, guest PC 0x0c0a9878 */
if(!s->budget--) { s->failed_pc=0x0c0a9878u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0a987a;
P_0c0a987a: /* original 8904, guest PC 0x0c0a987a */
if(!s->budget--) { s->failed_pc=0x0c0a987au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9886; }
goto P_0c0a987c;
P_0c0a987c: /* original e022, guest PC 0x0c0a987c */
if(!s->budget--) { s->failed_pc=0x0c0a987cu; return 0; }
r[0]=0x00000022u;
goto P_0c0a987e;
P_0c0a987e: /* original 034d, guest PC 0x0c0a987e */
if(!s->budget--) { s->failed_pc=0x0c0a987eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a9880;
P_0c0a9880: /* original 9042, guest PC 0x0c0a9880 */
if(!s->budget--) { s->failed_pc=0x0c0a9880u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9908u,2);
goto P_0c0a9882;
P_0c0a9882: /* original 7301, guest PC 0x0c0a9882 */
if(!s->budget--) { s->failed_pc=0x0c0a9882u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a9884;
P_0c0a9884: /* original 0e35, guest PC 0x0c0a9884 */
if(!s->budget--) { s->failed_pc=0x0c0a9884u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a9886;
P_0c0a9886: /* original 9040, guest PC 0x0c0a9886 */
if(!s->budget--) { s->failed_pc=0x0c0a9886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a990au,2);
goto P_0c0a9888;
P_0c0a9888: /* original 03bc, guest PC 0x0c0a9888 */
if(!s->budget--) { s->failed_pc=0x0c0a9888u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0a988a;
P_0c0a988a: /* original 2338, guest PC 0x0c0a988a */
if(!s->budget--) { s->failed_pc=0x0c0a988au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a988c;
P_0c0a988c: /* original 8d0b, guest PC 0x0c0a988c */
if(!s->budget--) { s->failed_pc=0x0c0a988cu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[5]=tmp;
if(cond) { goto P_0c0a98a6; }
goto P_0c0a9890;
P_0c0a988e: /* original 6542, guest PC 0x0c0a988e */
if(!s->budget--) { s->failed_pc=0x0c0a988eu; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0a9890;
P_0c0a9890: /* original e060, guest PC 0x0c0a9890 */
if(!s->budget--) { s->failed_pc=0x0c0a9890u; return 0; }
r[0]=0x00000060u;
goto P_0c0a9892;
P_0c0a9892: /* original 00ec, guest PC 0x0c0a9892 */
if(!s->budget--) { s->failed_pc=0x0c0a9892u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a9894;
P_0c0a9894: /* original 600c, guest PC 0x0c0a9894 */
if(!s->budget--) { s->failed_pc=0x0c0a9894u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9896;
P_0c0a9896: /* original 880b, guest PC 0x0c0a9896 */
if(!s->budget--) { s->failed_pc=0x0c0a9896u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0a9898;
P_0c0a9898: /* original 8b02, guest PC 0x0c0a9898 */
if(!s->budget--) { s->failed_pc=0x0c0a9898u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a98a0; }
goto P_0c0a989a;
P_0c0a989a: /* original d521, guest PC 0x0c0a989a */
if(!s->budget--) { s->failed_pc=0x0c0a989au; return 0; }
r[5]=read(ram,0x0c0a9920u,4);
goto P_0c0a989c;
P_0c0a989c: /* original a003, guest PC 0x0c0a989c */
if(!s->budget--) { s->failed_pc=0x0c0a989cu; return 0; }
goto P_0c0a98a6;
P_0c0a989e: /* original 0009, guest PC 0x0c0a989e */
if(!s->budget--) { s->failed_pc=0x0c0a989eu; return 0; }
goto P_0c0a98a0;
P_0c0a98a0: /* original 8818, guest PC 0x0c0a98a0 */
if(!s->budget--) { s->failed_pc=0x0c0a98a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c0a98a2;
P_0c0a98a2: /* original 8b00, guest PC 0x0c0a98a2 */
if(!s->budget--) { s->failed_pc=0x0c0a98a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a98a6; }
goto P_0c0a98a4;
P_0c0a98a4: /* original d51f, guest PC 0x0c0a98a4 */
if(!s->budget--) { s->failed_pc=0x0c0a98a4u; return 0; }
r[5]=read(ram,0x0c0a9924u,4);
goto P_0c0a98a6;
P_0c0a98a6: /* original 67e3, guest PC 0x0c0a98a6 */
if(!s->budget--) { s->failed_pc=0x0c0a98a6u; return 0; }
r[7]=r[14];
goto P_0c0a98a8;
P_0c0a98a8: /* original e612, guest PC 0x0c0a98a8 */
if(!s->budget--) { s->failed_pc=0x0c0a98a8u; return 0; }
r[6]=0x00000012u;
goto P_0c0a98aa;
P_0c0a98aa: /* original 776c, guest PC 0x0c0a98aa */
if(!s->budget--) { s->failed_pc=0x0c0a98aau; return 0; }
r[7]+=0x0000006cu;
goto P_0c0a98ac;
P_0c0a98ac: /* original 7504, guest PC 0x0c0a98ac */
if(!s->budget--) { s->failed_pc=0x0c0a98acu; return 0; }
r[5]+=0x00000004u;
goto P_0c0a98ae;
P_0c0a98ae: /* original 6352, guest PC 0x0c0a98ae */
if(!s->budget--) { s->failed_pc=0x0c0a98aeu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0a98b0;
P_0c0a98b0: /* original 4610, guest PC 0x0c0a98b0 */
if(!s->budget--) { s->failed_pc=0x0c0a98b0u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0a98b2;
P_0c0a98b2: /* original 2732, guest PC 0x0c0a98b2 */
if(!s->budget--) { s->failed_pc=0x0c0a98b2u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0a98b4;
P_0c0a98b4: /* original 8ffa, guest PC 0x0c0a98b4 */
if(!s->budget--) { s->failed_pc=0x0c0a98b4u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c0a98ac; }
goto P_0c0a98b8;
P_0c0a98b6: /* original 7704, guest PC 0x0c0a98b6 */
if(!s->budget--) { s->failed_pc=0x0c0a98b6u; return 0; }
r[7]+=0x00000004u;
goto P_0c0a98b8;
P_0c0a98b8: /* original 9728, guest PC 0x0c0a98b8 */
if(!s->budget--) { s->failed_pc=0x0c0a98b8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a990cu,2);
goto P_0c0a98ba;
P_0c0a98ba: /* original e60f, guest PC 0x0c0a98ba */
if(!s->budget--) { s->failed_pc=0x0c0a98bau; return 0; }
r[6]=0x0000000fu;
goto P_0c0a98bc;
P_0c0a98bc: /* original 554d, guest PC 0x0c0a98bc */
if(!s->budget--) { s->failed_pc=0x0c0a98bcu; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c0a98be;
P_0c0a98be: /* original 37ec, guest PC 0x0c0a98be */
if(!s->budget--) { s->failed_pc=0x0c0a98beu; return 0; }
r[7]+=r[14];
goto P_0c0a98c0;
P_0c0a98c0: /* original 77fc, guest PC 0x0c0a98c0 */
if(!s->budget--) { s->failed_pc=0x0c0a98c0u; return 0; }
r[7]+=0xfffffffcu;
goto P_0c0a98c2;
P_0c0a98c2: /* original 7504, guest PC 0x0c0a98c2 */
if(!s->budget--) { s->failed_pc=0x0c0a98c2u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a98c4;
P_0c0a98c4: /* original 6352, guest PC 0x0c0a98c4 */
if(!s->budget--) { s->failed_pc=0x0c0a98c4u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0a98c6;
P_0c0a98c6: /* original 4610, guest PC 0x0c0a98c6 */
if(!s->budget--) { s->failed_pc=0x0c0a98c6u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0a98c8;
P_0c0a98c8: /* original 7704, guest PC 0x0c0a98c8 */
if(!s->budget--) { s->failed_pc=0x0c0a98c8u; return 0; }
r[7]+=0x00000004u;
goto P_0c0a98ca;
P_0c0a98ca: /* original 8ffa, guest PC 0x0c0a98ca */
if(!s->budget--) { s->failed_pc=0x0c0a98cau; return 0; }
cond=r[17]&1u;
write(ram,r[7],r[3],4);
if(!cond) { goto P_0c0a98c2; }
goto P_0c0a98ce;
P_0c0a98cc: /* original 2732, guest PC 0x0c0a98cc */
if(!s->budget--) { s->failed_pc=0x0c0a98ccu; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0a98ce;
P_0c0a98ce: /* original 951e, guest PC 0x0c0a98ce */
if(!s->budget--) { s->failed_pc=0x0c0a98ceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a990eu,2);
goto P_0c0a98d0;
P_0c0a98d0: /* original 5641, guest PC 0x0c0a98d0 */
if(!s->budget--) { s->failed_pc=0x0c0a98d0u; return 0; }
r[6]=read(ram,r[4]+4,4);
goto P_0c0a98d2;
P_0c0a98d2: /* original 35ec, guest PC 0x0c0a98d2 */
if(!s->budget--) { s->failed_pc=0x0c0a98d2u; return 0; }
r[5]+=r[14];
goto P_0c0a98d4;
P_0c0a98d4: /* original a005, guest PC 0x0c0a98d4 */
if(!s->budget--) { s->failed_pc=0x0c0a98d4u; return 0; }
r[4]=0x00000033u;
goto P_0c0a98e2;
P_0c0a98d6: /* original e433, guest PC 0x0c0a98d6 */
if(!s->budget--) { s->failed_pc=0x0c0a98d6u; return 0; }
r[4]=0x00000033u;
goto P_0c0a98d8;
P_0c0a98d8: /* original 7604, guest PC 0x0c0a98d8 */
if(!s->budget--) { s->failed_pc=0x0c0a98d8u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a98da;
P_0c0a98da: /* original 6262, guest PC 0x0c0a98da */
if(!s->budget--) { s->failed_pc=0x0c0a98dau; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a98dc;
P_0c0a98dc: /* original 74ff, guest PC 0x0c0a98dc */
if(!s->budget--) { s->failed_pc=0x0c0a98dcu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a98de;
P_0c0a98de: /* original 2522, guest PC 0x0c0a98de */
if(!s->budget--) { s->failed_pc=0x0c0a98deu; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0a98e0;
P_0c0a98e0: /* original 7504, guest PC 0x0c0a98e0 */
if(!s->budget--) { s->failed_pc=0x0c0a98e0u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a98e2;
P_0c0a98e2: /* original 2448, guest PC 0x0c0a98e2 */
if(!s->budget--) { s->failed_pc=0x0c0a98e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a98e4;
P_0c0a98e4: /* original 8bf8, guest PC 0x0c0a98e4 */
if(!s->budget--) { s->failed_pc=0x0c0a98e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a98d8; }
goto P_0c0a98e6;
P_0c0a98e6: /* original 9013, guest PC 0x0c0a98e6 */
if(!s->budget--) { s->failed_pc=0x0c0a98e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9910u,2);
goto P_0c0a98e8;
P_0c0a98e8: /* original e201, guest PC 0x0c0a98e8 */
if(!s->budget--) { s->failed_pc=0x0c0a98e8u; return 0; }
r[2]=0x00000001u;
goto P_0c0a98ea;
P_0c0a98ea: /* original 0e24, guest PC 0x0c0a98ea */
if(!s->budget--) { s->failed_pc=0x0c0a98eau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0a98ec;
P_0c0a98ec: /* original 84e4, guest PC 0x0c0a98ec */
if(!s->budget--) { s->failed_pc=0x0c0a98ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0a98ee;
P_0c0a98ee: /* original 600c, guest PC 0x0c0a98ee */
if(!s->budget--) { s->failed_pc=0x0c0a98eeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0a98f0;
P_0c0a98f0: /* original 8801, guest PC 0x0c0a98f0 */
if(!s->budget--) { s->failed_pc=0x0c0a98f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a98f2;
P_0c0a98f2: /* original 8b19, guest PC 0x0c0a98f2 */
if(!s->budget--) { s->failed_pc=0x0c0a98f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9928; }
goto P_0c0a98f4;
P_0c0a98f4: /* original 940d, guest PC 0x0c0a98f4 */
if(!s->budget--) { s->failed_pc=0x0c0a98f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9912u,2);
goto P_0c0a98f6;
P_0c0a98f6: /* original a018, guest PC 0x0c0a98f6 */
if(!s->budget--) { s->failed_pc=0x0c0a98f6u; return 0; }
r[4]+=r[12];
goto P_0c0a992a;
P_0c0a98f8: /* original 34cc, guest PC 0x0c0a98f8 */
if(!s->budget--) { s->failed_pc=0x0c0a98f8u; return 0; }
r[4]+=r[12];
if(!vf3_matrix_family(0x0c0a98fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a98fau; return 0; } return 1;
P_0c0a9928: /* original 64c3, guest PC 0x0c0a9928 */
if(!s->budget--) { s->failed_pc=0x0c0a9928u; return 0; }
r[4]=r[12];
goto P_0c0a992a;
P_0c0a992a: /* original 904f, guest PC 0x0c0a992a */
if(!s->budget--) { s->failed_pc=0x0c0a992au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a99ccu,2);
goto P_0c0a992c;
P_0c0a992c: /* original 0e46, guest PC 0x0c0a992c */
if(!s->budget--) { s->failed_pc=0x0c0a992cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a992e;
P_0c0a992e: /* original 934e, guest PC 0x0c0a992e */
if(!s->budget--) { s->failed_pc=0x0c0a992eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a99ceu,2);
goto P_0c0a9930;
P_0c0a9930: /* original 904e, guest PC 0x0c0a9930 */
if(!s->budget--) { s->failed_pc=0x0c0a9930u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a99d0u,2);
goto P_0c0a9932;
P_0c0a9932: /* original 33ec, guest PC 0x0c0a9932 */
if(!s->budget--) { s->failed_pc=0x0c0a9932u; return 0; }
r[3]+=r[14];
goto P_0c0a9934;
P_0c0a9934: /* original 0e36, guest PC 0x0c0a9934 */
if(!s->budget--) { s->failed_pc=0x0c0a9934u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0a9936;
P_0c0a9936: /* original 7004, guest PC 0x0c0a9936 */
if(!s->budget--) { s->failed_pc=0x0c0a9936u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a9938;
P_0c0a9938: /* original 924b, guest PC 0x0c0a9938 */
if(!s->budget--) { s->failed_pc=0x0c0a9938u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a99d2u,2);
goto P_0c0a993a;
P_0c0a993a: /* original 32ec, guest PC 0x0c0a993a */
if(!s->budget--) { s->failed_pc=0x0c0a993au; return 0; }
r[2]+=r[14];
goto P_0c0a993c;
P_0c0a993c: /* original 0e26, guest PC 0x0c0a993c */
if(!s->budget--) { s->failed_pc=0x0c0a993cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0a993e;
P_0c0a993e: /* original d327, guest PC 0x0c0a993e */
if(!s->budget--) { s->failed_pc=0x0c0a993eu; return 0; }
r[3]=read(ram,0x0c0a99dcu,4);
goto P_0c0a9940;
P_0c0a9940: /* original 430b, guest PC 0x0c0a9940 */
if(!s->budget--) { s->failed_pc=0x0c0a9940u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9944u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9944u) { target=s->pc; goto dispatch; }
goto P_0c0a9944;
P_0c0a9942: /* original 64e3, guest PC 0x0c0a9942 */
if(!s->budget--) { s->failed_pc=0x0c0a9942u; return 0; }
r[4]=r[14];
goto P_0c0a9944;
P_0c0a9944: /* original e058, guest PC 0x0c0a9944 */
if(!s->budget--) { s->failed_pc=0x0c0a9944u; return 0; }
r[0]=0x00000058u;
goto P_0c0a9946;
P_0c0a9946: /* original 62e2, guest PC 0x0c0a9946 */
if(!s->budget--) { s->failed_pc=0x0c0a9946u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a9948;
P_0c0a9948: /* original 9344, guest PC 0x0c0a9948 */
if(!s->budget--) { s->failed_pc=0x0c0a9948u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a99d4u,2);
goto P_0c0a994a;
P_0c0a994a: /* original 223b, guest PC 0x0c0a994a */
if(!s->budget--) { s->failed_pc=0x0c0a994au; return 0; }
r[2]|=r[3];
goto P_0c0a994c;
P_0c0a994c: /* original 2e22, guest PC 0x0c0a994c */
if(!s->budget--) { s->failed_pc=0x0c0a994cu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a994e;
P_0c0a994e: /* original 05ee, guest PC 0x0c0a994e */
if(!s->budget--) { s->failed_pc=0x0c0a994eu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a9950;
P_0c0a9950: /* original d223, guest PC 0x0c0a9950 */
if(!s->budget--) { s->failed_pc=0x0c0a9950u; return 0; }
r[2]=read(ram,0x0c0a99e0u,4);
goto P_0c0a9952;
P_0c0a9952: /* original 6551, guest PC 0x0c0a9952 */
if(!s->budget--) { s->failed_pc=0x0c0a9952u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0a9954;
P_0c0a9954: /* original 655d, guest PC 0x0c0a9954 */
if(!s->budget--) { s->failed_pc=0x0c0a9954u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0a9956;
P_0c0a9956: /* original 420b, guest PC 0x0c0a9956 */
if(!s->budget--) { s->failed_pc=0x0c0a9956u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a995au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a995au) { target=s->pc; goto dispatch; }
goto P_0c0a995a;
P_0c0a9958: /* original 64e3, guest PC 0x0c0a9958 */
if(!s->budget--) { s->failed_pc=0x0c0a9958u; return 0; }
r[4]=r[14];
goto P_0c0a995a;
P_0c0a995a: /* original d322, guest PC 0x0c0a995a */
if(!s->budget--) { s->failed_pc=0x0c0a995au; return 0; }
r[3]=read(ram,0x0c0a99e4u,4);
goto P_0c0a995c;
P_0c0a995c: /* original 430b, guest PC 0x0c0a995c */
if(!s->budget--) { s->failed_pc=0x0c0a995cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9960u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9960u) { target=s->pc; goto dispatch; }
goto P_0c0a9960;
P_0c0a995e: /* original 64e3, guest PC 0x0c0a995e */
if(!s->budget--) { s->failed_pc=0x0c0a995eu; return 0; }
r[4]=r[14];
goto P_0c0a9960;
P_0c0a9960: /* original d221, guest PC 0x0c0a9960 */
if(!s->budget--) { s->failed_pc=0x0c0a9960u; return 0; }
r[2]=read(ram,0x0c0a99e8u,4);
goto P_0c0a9962;
P_0c0a9962: /* original 1e23, guest PC 0x0c0a9962 */
if(!s->budget--) { s->failed_pc=0x0c0a9962u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0a9964;
P_0c0a9964: /* original d321, guest PC 0x0c0a9964 */
if(!s->budget--) { s->failed_pc=0x0c0a9964u; return 0; }
r[3]=read(ram,0x0c0a99ecu,4);
goto P_0c0a9966;
P_0c0a9966: /* original 430b, guest PC 0x0c0a9966 */
if(!s->budget--) { s->failed_pc=0x0c0a9966u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a996au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a996au) { target=s->pc; goto dispatch; }
goto P_0c0a996a;
P_0c0a9968: /* original 64e3, guest PC 0x0c0a9968 */
if(!s->budget--) { s->failed_pc=0x0c0a9968u; return 0; }
r[4]=r[14];
goto P_0c0a996a;
P_0c0a996a: /* original d221, guest PC 0x0c0a996a */
if(!s->budget--) { s->failed_pc=0x0c0a996au; return 0; }
r[2]=read(ram,0x0c0a99f0u,4);
goto P_0c0a996c;
P_0c0a996c: /* original 420b, guest PC 0x0c0a996c */
if(!s->budget--) { s->failed_pc=0x0c0a996cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9970u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9970u) { target=s->pc; goto dispatch; }
goto P_0c0a9970;
P_0c0a996e: /* original 64e3, guest PC 0x0c0a996e */
if(!s->budget--) { s->failed_pc=0x0c0a996eu; return 0; }
r[4]=r[14];
goto P_0c0a9970;
P_0c0a9970: /* original e010, guest PC 0x0c0a9970 */
if(!s->budget--) { s->failed_pc=0x0c0a9970u; return 0; }
r[0]=0x00000010u;
goto P_0c0a9972;
P_0c0a9972: /* original f3e6, guest PC 0x0c0a9972 */
if(!s->budget--) { s->failed_pc=0x0c0a9972u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a9974;
P_0c0a9974: /* original 902f, guest PC 0x0c0a9974 */
if(!s->budget--) { s->failed_pc=0x0c0a9974u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a99d6u,2);
goto P_0c0a9976;
P_0c0a9976: /* original fe37, guest PC 0x0c0a9976 */
if(!s->budget--) { s->failed_pc=0x0c0a9976u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a9978;
P_0c0a9978: /* original e018, guest PC 0x0c0a9978 */
if(!s->budget--) { s->failed_pc=0x0c0a9978u; return 0; }
r[0]=0x00000018u;
goto P_0c0a997a;
P_0c0a997a: /* original f3e6, guest PC 0x0c0a997a */
if(!s->budget--) { s->failed_pc=0x0c0a997au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a997c;
P_0c0a997c: /* original 902c, guest PC 0x0c0a997c */
if(!s->budget--) { s->failed_pc=0x0c0a997cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a99d8u,2);
goto P_0c0a997e;
P_0c0a997e: /* original fe37, guest PC 0x0c0a997e */
if(!s->budget--) { s->failed_pc=0x0c0a997eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a9980;
P_0c0a9980: /* original 54f1, guest PC 0x0c0a9980 */
if(!s->budget--) { s->failed_pc=0x0c0a9980u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a9982;
P_0c0a9982: /* original 7f08, guest PC 0x0c0a9982 */
if(!s->budget--) { s->failed_pc=0x0c0a9982u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a9984;
P_0c0a9984: /* original 4f26, guest PC 0x0c0a9984 */
if(!s->budget--) { s->failed_pc=0x0c0a9984u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9986;
P_0c0a9986: /* original 69f6, guest PC 0x0c0a9986 */
if(!s->budget--) { s->failed_pc=0x0c0a9986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a9988;
P_0c0a9988: /* original 6af6, guest PC 0x0c0a9988 */
if(!s->budget--) { s->failed_pc=0x0c0a9988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a998a;
P_0c0a998a: /* original 6bf6, guest PC 0x0c0a998a */
if(!s->budget--) { s->failed_pc=0x0c0a998au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a998c;
P_0c0a998c: /* original 6cf6, guest PC 0x0c0a998c */
if(!s->budget--) { s->failed_pc=0x0c0a998cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a998e;
P_0c0a998e: /* original 6df6, guest PC 0x0c0a998e */
if(!s->budget--) { s->failed_pc=0x0c0a998eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9990;
P_0c0a9990: /* original a009, guest PC 0x0c0a9990 */
if(!s->budget--) { s->failed_pc=0x0c0a9990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a99a6u,s,ram);
P_0c0a9992: /* original 6ef6, guest PC 0x0c0a9992 */
if(!s->budget--) { s->failed_pc=0x0c0a9992u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9994;
P_0c0a9994: /* original 7f08, guest PC 0x0c0a9994 */
if(!s->budget--) { s->failed_pc=0x0c0a9994u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a9996;
P_0c0a9996: /* original 4f26, guest PC 0x0c0a9996 */
if(!s->budget--) { s->failed_pc=0x0c0a9996u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9998;
P_0c0a9998: /* original 69f6, guest PC 0x0c0a9998 */
if(!s->budget--) { s->failed_pc=0x0c0a9998u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a999a;
P_0c0a999a: /* original 6af6, guest PC 0x0c0a999a */
if(!s->budget--) { s->failed_pc=0x0c0a999au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a999c;
P_0c0a999c: /* original 6bf6, guest PC 0x0c0a999c */
if(!s->budget--) { s->failed_pc=0x0c0a999cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a999e;
P_0c0a999e: /* original 6cf6, guest PC 0x0c0a999e */
if(!s->budget--) { s->failed_pc=0x0c0a999eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a99a0;
P_0c0a99a0: /* original 6df6, guest PC 0x0c0a99a0 */
if(!s->budget--) { s->failed_pc=0x0c0a99a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a99a2;
P_0c0a99a2: /* original 000b, guest PC 0x0c0a99a2 */
if(!s->budget--) { s->failed_pc=0x0c0a99a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a99a4: /* original 6ef6, guest PC 0x0c0a99a4 */
if(!s->budget--) { s->failed_pc=0x0c0a99a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a99a6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
