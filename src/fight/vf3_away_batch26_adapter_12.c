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
int vf3_away_batch26_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c8e6cu: goto P_0c0c8e6c;
case 0x0c0c8e6eu: goto P_0c0c8e6e;
case 0x0c0c8e70u: goto P_0c0c8e70;
case 0x0c0c8e72u: goto P_0c0c8e72;
case 0x0c0c8e74u: goto P_0c0c8e74;
case 0x0c0c8e76u: goto P_0c0c8e76;
case 0x0c0c8e78u: goto P_0c0c8e78;
case 0x0c0c8e7au: goto P_0c0c8e7a;
case 0x0c0c8e7cu: goto P_0c0c8e7c;
case 0x0c0c8e7eu: goto P_0c0c8e7e;
case 0x0c0c8e80u: goto P_0c0c8e80;
case 0x0c0c8e82u: goto P_0c0c8e82;
case 0x0c0c8e84u: goto P_0c0c8e84;
case 0x0c0c8e86u: goto P_0c0c8e86;
case 0x0c0c8e88u: goto P_0c0c8e88;
case 0x0c0c8e8au: goto P_0c0c8e8a;
case 0x0c0c8e8cu: goto P_0c0c8e8c;
case 0x0c0c8e8eu: goto P_0c0c8e8e;
case 0x0c0c8e90u: goto P_0c0c8e90;
case 0x0c0c8e92u: goto P_0c0c8e92;
case 0x0c0c8e94u: goto P_0c0c8e94;
case 0x0c0c8e96u: goto P_0c0c8e96;
case 0x0c0c8e98u: goto P_0c0c8e98;
case 0x0c0c8e9au: goto P_0c0c8e9a;
case 0x0c0c8e9cu: goto P_0c0c8e9c;
case 0x0c0c8e9eu: goto P_0c0c8e9e;
case 0x0c0c8ea0u: goto P_0c0c8ea0;
case 0x0c0c8ea2u: goto P_0c0c8ea2;
case 0x0c0c8ea4u: goto P_0c0c8ea4;
case 0x0c0c8ea6u: goto P_0c0c8ea6;
case 0x0c0c8ea8u: goto P_0c0c8ea8;
case 0x0c0c8eaau: goto P_0c0c8eaa;
case 0x0c0c8eacu: goto P_0c0c8eac;
case 0x0c0c8eaeu: goto P_0c0c8eae;
case 0x0c0c8eb0u: goto P_0c0c8eb0;
case 0x0c0c8eb2u: goto P_0c0c8eb2;
case 0x0c0c8eb4u: goto P_0c0c8eb4;
case 0x0c0c8eb6u: goto P_0c0c8eb6;
case 0x0c0c8eb8u: goto P_0c0c8eb8;
case 0x0c0c8ebau: goto P_0c0c8eba;
case 0x0c0c8ebcu: goto P_0c0c8ebc;
case 0x0c0c8ebeu: goto P_0c0c8ebe;
case 0x0c0c8ec0u: goto P_0c0c8ec0;
case 0x0c0c8ec2u: goto P_0c0c8ec2;
case 0x0c0c8ec4u: goto P_0c0c8ec4;
case 0x0c0c8ec6u: goto P_0c0c8ec6;
case 0x0c0c8ec8u: goto P_0c0c8ec8;
case 0x0c0c8ecau: goto P_0c0c8eca;
case 0x0c0c8eccu: goto P_0c0c8ecc;
case 0x0c0c8eceu: goto P_0c0c8ece;
case 0x0c0c8ed0u: goto P_0c0c8ed0;
case 0x0c0c8ed2u: goto P_0c0c8ed2;
case 0x0c0c8ed4u: goto P_0c0c8ed4;
case 0x0c0c8ed6u: goto P_0c0c8ed6;
case 0x0c0c8ed8u: goto P_0c0c8ed8;
case 0x0c0c8edau: goto P_0c0c8eda;
case 0x0c0c8edcu: goto P_0c0c8edc;
case 0x0c0c8edeu: goto P_0c0c8ede;
case 0x0c0c8ee0u: goto P_0c0c8ee0;
case 0x0c0c8ee2u: goto P_0c0c8ee2;
case 0x0c0c8ee4u: goto P_0c0c8ee4;
case 0x0c0c8ee6u: goto P_0c0c8ee6;
case 0x0c0c8ee8u: goto P_0c0c8ee8;
case 0x0c0c8eeau: goto P_0c0c8eea;
case 0x0c0c8eecu: goto P_0c0c8eec;
case 0x0c0c8eeeu: goto P_0c0c8eee;
case 0x0c0c8ef0u: goto P_0c0c8ef0;
case 0x0c0c8ef2u: goto P_0c0c8ef2;
case 0x0c0c8ef4u: goto P_0c0c8ef4;
case 0x0c0c8ef6u: goto P_0c0c8ef6;
case 0x0c0c8ef8u: goto P_0c0c8ef8;
case 0x0c0c8efau: goto P_0c0c8efa;
case 0x0c0c8efcu: goto P_0c0c8efc;
case 0x0c0c8efeu: goto P_0c0c8efe;
case 0x0c0c8f00u: goto P_0c0c8f00;
case 0x0c0c8f02u: goto P_0c0c8f02;
case 0x0c0c8f04u: goto P_0c0c8f04;
case 0x0c0c8f06u: goto P_0c0c8f06;
case 0x0c0c8f08u: goto P_0c0c8f08;
case 0x0c0c8f0au: goto P_0c0c8f0a;
case 0x0c0c8f0cu: goto P_0c0c8f0c;
case 0x0c0c8f0eu: goto P_0c0c8f0e;
case 0x0c0c8f10u: goto P_0c0c8f10;
case 0x0c0c8f12u: goto P_0c0c8f12;
case 0x0c0c8f14u: goto P_0c0c8f14;
case 0x0c0c8f16u: goto P_0c0c8f16;
case 0x0c0c8f18u: goto P_0c0c8f18;
case 0x0c0c8f1au: goto P_0c0c8f1a;
case 0x0c0c8f1cu: goto P_0c0c8f1c;
case 0x0c0c8f1eu: goto P_0c0c8f1e;
case 0x0c0c8f20u: goto P_0c0c8f20;
case 0x0c0c8f22u: goto P_0c0c8f22;
case 0x0c0c8f24u: goto P_0c0c8f24;
case 0x0c0c8f26u: goto P_0c0c8f26;
case 0x0c0c8f28u: goto P_0c0c8f28;
case 0x0c0c8f2au: goto P_0c0c8f2a;
case 0x0c0c8f2cu: goto P_0c0c8f2c;
case 0x0c0c8f2eu: goto P_0c0c8f2e;
case 0x0c0c8f30u: goto P_0c0c8f30;
case 0x0c0c8f32u: goto P_0c0c8f32;
case 0x0c0c8f34u: goto P_0c0c8f34;
case 0x0c0c927cu: goto P_0c0c927c;
case 0x0c0c927eu: goto P_0c0c927e;
case 0x0c0c9280u: goto P_0c0c9280;
case 0x0c0c9282u: goto P_0c0c9282;
case 0x0c0c9284u: goto P_0c0c9284;
case 0x0c0c9286u: goto P_0c0c9286;
case 0x0c0c9288u: goto P_0c0c9288;
case 0x0c0c928au: goto P_0c0c928a;
case 0x0c0c928cu: goto P_0c0c928c;
case 0x0c0c928eu: goto P_0c0c928e;
case 0x0c0c9290u: goto P_0c0c9290;
case 0x0c0c9292u: goto P_0c0c9292;
case 0x0c0c9294u: goto P_0c0c9294;
case 0x0c0c9296u: goto P_0c0c9296;
case 0x0c0c9298u: goto P_0c0c9298;
case 0x0c0c929au: goto P_0c0c929a;
case 0x0c0c929cu: goto P_0c0c929c;
case 0x0c0c929eu: goto P_0c0c929e;
case 0x0c0c92a0u: goto P_0c0c92a0;
case 0x0c0c92a2u: goto P_0c0c92a2;
case 0x0c0c92a4u: goto P_0c0c92a4;
case 0x0c0c92a6u: goto P_0c0c92a6;
case 0x0c0c92a8u: goto P_0c0c92a8;
case 0x0c0c92aau: goto P_0c0c92aa;
case 0x0c0c92acu: goto P_0c0c92ac;
case 0x0c0c92aeu: goto P_0c0c92ae;
case 0x0c0c92b0u: goto P_0c0c92b0;
case 0x0c0c950cu: goto P_0c0c950c;
case 0x0c0c950eu: goto P_0c0c950e;
case 0x0c0c9510u: goto P_0c0c9510;
case 0x0c0c9512u: goto P_0c0c9512;
case 0x0c0c9514u: goto P_0c0c9514;
case 0x0c0c9516u: goto P_0c0c9516;
case 0x0c0c9518u: goto P_0c0c9518;
case 0x0c0c951au: goto P_0c0c951a;
case 0x0c0c951cu: goto P_0c0c951c;
case 0x0c0c951eu: goto P_0c0c951e;
case 0x0c0c9520u: goto P_0c0c9520;
case 0x0c0c9522u: goto P_0c0c9522;
case 0x0c0c9524u: goto P_0c0c9524;
case 0x0c0c9526u: goto P_0c0c9526;
case 0x0c0c9528u: goto P_0c0c9528;
case 0x0c0c952au: goto P_0c0c952a;
case 0x0c0c952cu: goto P_0c0c952c;
case 0x0c0c952eu: goto P_0c0c952e;
case 0x0c0c9530u: goto P_0c0c9530;
case 0x0c0c9532u: goto P_0c0c9532;
case 0x0c0c9534u: goto P_0c0c9534;
case 0x0c0c9536u: goto P_0c0c9536;
case 0x0c0c9538u: goto P_0c0c9538;
case 0x0c0c953au: goto P_0c0c953a;
case 0x0c0c953cu: goto P_0c0c953c;
case 0x0c0c953eu: goto P_0c0c953e;
case 0x0c0c9540u: goto P_0c0c9540;
case 0x0c0c9542u: goto P_0c0c9542;
case 0x0c0c9544u: goto P_0c0c9544;
case 0x0c0c9546u: goto P_0c0c9546;
case 0x0c0c9548u: goto P_0c0c9548;
case 0x0c0c954au: goto P_0c0c954a;
case 0x0c0c954cu: goto P_0c0c954c;
case 0x0c0c954eu: goto P_0c0c954e;
case 0x0c0c9550u: goto P_0c0c9550;
case 0x0c0c9552u: goto P_0c0c9552;
case 0x0c0c9554u: goto P_0c0c9554;
case 0x0c0c9556u: goto P_0c0c9556;
case 0x0c0c9558u: goto P_0c0c9558;
case 0x0c0c955au: goto P_0c0c955a;
case 0x0c0c955cu: goto P_0c0c955c;
case 0x0c0c955eu: goto P_0c0c955e;
case 0x0c0c9560u: goto P_0c0c9560;
case 0x0c0c9562u: goto P_0c0c9562;
case 0x0c0c9564u: goto P_0c0c9564;
case 0x0c0c9566u: goto P_0c0c9566;
case 0x0c0c9568u: goto P_0c0c9568;
case 0x0c0c956au: goto P_0c0c956a;
case 0x0c0c956cu: goto P_0c0c956c;
case 0x0c0c956eu: goto P_0c0c956e;
case 0x0c0c9570u: goto P_0c0c9570;
case 0x0c0c9572u: goto P_0c0c9572;
case 0x0c0c9574u: goto P_0c0c9574;
case 0x0c0c9576u: goto P_0c0c9576;
case 0x0c0c9578u: goto P_0c0c9578;
case 0x0c0c957au: goto P_0c0c957a;
case 0x0c0c957cu: goto P_0c0c957c;
case 0x0c0c957eu: goto P_0c0c957e;
case 0x0c0c9580u: goto P_0c0c9580;
case 0x0c0c9582u: goto P_0c0c9582;
case 0x0c0c9584u: goto P_0c0c9584;
case 0x0c0c9586u: goto P_0c0c9586;
case 0x0c0c9588u: goto P_0c0c9588;
case 0x0c0c958au: goto P_0c0c958a;
case 0x0c0c958cu: goto P_0c0c958c;
case 0x0c0c958eu: goto P_0c0c958e;
case 0x0c0c9590u: goto P_0c0c9590;
case 0x0c0c9592u: goto P_0c0c9592;
case 0x0c0c9594u: goto P_0c0c9594;
case 0x0c0c9596u: goto P_0c0c9596;
case 0x0c0c9598u: goto P_0c0c9598;
case 0x0c0c959au: goto P_0c0c959a;
case 0x0c0c959cu: goto P_0c0c959c;
case 0x0c0c959eu: goto P_0c0c959e;
case 0x0c0c95f4u: goto P_0c0c95f4;
case 0x0c0c95f6u: goto P_0c0c95f6;
case 0x0c0c95f8u: goto P_0c0c95f8;
case 0x0c0c95fau: goto P_0c0c95fa;
case 0x0c0c95fcu: goto P_0c0c95fc;
case 0x0c0c95feu: goto P_0c0c95fe;
case 0x0c0c9600u: goto P_0c0c9600;
case 0x0c0c9602u: goto P_0c0c9602;
case 0x0c0c9604u: goto P_0c0c9604;
case 0x0c0c9606u: goto P_0c0c9606;
case 0x0c0c9608u: goto P_0c0c9608;
case 0x0c0c960au: goto P_0c0c960a;
case 0x0c0c960cu: goto P_0c0c960c;
case 0x0c0c960eu: goto P_0c0c960e;
case 0x0c0c9610u: goto P_0c0c9610;
case 0x0c0c9612u: goto P_0c0c9612;
case 0x0c0c9614u: goto P_0c0c9614;
case 0x0c0c9616u: goto P_0c0c9616;
case 0x0c0c9618u: goto P_0c0c9618;
case 0x0c0c961au: goto P_0c0c961a;
case 0x0c0c961cu: goto P_0c0c961c;
case 0x0c0c961eu: goto P_0c0c961e;
case 0x0c0c9620u: goto P_0c0c9620;
case 0x0c0c9622u: goto P_0c0c9622;
case 0x0c0c9624u: goto P_0c0c9624;
case 0x0c0c9626u: goto P_0c0c9626;
case 0x0c0c9628u: goto P_0c0c9628;
case 0x0c0c962au: goto P_0c0c962a;
case 0x0c0c962cu: goto P_0c0c962c;
case 0x0c0c962eu: goto P_0c0c962e;
case 0x0c0c9630u: goto P_0c0c9630;
case 0x0c0c9632u: goto P_0c0c9632;
case 0x0c0c9634u: goto P_0c0c9634;
case 0x0c0c9636u: goto P_0c0c9636;
case 0x0c0c9638u: goto P_0c0c9638;
case 0x0c0c963au: goto P_0c0c963a;
case 0x0c0c963cu: goto P_0c0c963c;
case 0x0c0c963eu: goto P_0c0c963e;
case 0x0c0c9640u: goto P_0c0c9640;
case 0x0c0c9642u: goto P_0c0c9642;
case 0x0c0c9644u: goto P_0c0c9644;
case 0x0c0c9646u: goto P_0c0c9646;
case 0x0c0c9648u: goto P_0c0c9648;
case 0x0c0c964au: goto P_0c0c964a;
case 0x0c0c964cu: goto P_0c0c964c;
case 0x0c0c964eu: goto P_0c0c964e;
case 0x0c0c9650u: goto P_0c0c9650;
case 0x0c0c9652u: goto P_0c0c9652;
case 0x0c0c9654u: goto P_0c0c9654;
case 0x0c0c9656u: goto P_0c0c9656;
case 0x0c0c9658u: goto P_0c0c9658;
case 0x0c0c965au: goto P_0c0c965a;
case 0x0c0c965cu: goto P_0c0c965c;
case 0x0c0c965eu: goto P_0c0c965e;
case 0x0c0c9660u: goto P_0c0c9660;
case 0x0c0c9662u: goto P_0c0c9662;
case 0x0c0c9664u: goto P_0c0c9664;
case 0x0c0c9666u: goto P_0c0c9666;
case 0x0c0c9668u: goto P_0c0c9668;
case 0x0c0c966au: goto P_0c0c966a;
case 0x0c0c966cu: goto P_0c0c966c;
case 0x0c0c966eu: goto P_0c0c966e;
case 0x0c0c9670u: goto P_0c0c9670;
case 0x0c0c9672u: goto P_0c0c9672;
case 0x0c0c9674u: goto P_0c0c9674;
case 0x0c0c9676u: goto P_0c0c9676;
case 0x0c0c9678u: goto P_0c0c9678;
case 0x0c0c967au: goto P_0c0c967a;
case 0x0c0c967cu: goto P_0c0c967c;
case 0x0c0c967eu: goto P_0c0c967e;
case 0x0c0c9680u: goto P_0c0c9680;
case 0x0c0c9682u: goto P_0c0c9682;
case 0x0c0c9684u: goto P_0c0c9684;
case 0x0c0c9686u: goto P_0c0c9686;
case 0x0c0c9688u: goto P_0c0c9688;
case 0x0c0c968au: goto P_0c0c968a;
case 0x0c0c968cu: goto P_0c0c968c;
case 0x0c0c968eu: goto P_0c0c968e;
case 0x0c0c9690u: goto P_0c0c9690;
case 0x0c0c9692u: goto P_0c0c9692;
case 0x0c0c9694u: goto P_0c0c9694;
case 0x0c0c9696u: goto P_0c0c9696;
case 0x0c0c9698u: goto P_0c0c9698;
case 0x0c0c969au: goto P_0c0c969a;
case 0x0c0c969cu: goto P_0c0c969c;
case 0x0c0c969eu: goto P_0c0c969e;
case 0x0c0c96a0u: goto P_0c0c96a0;
case 0x0c0c96a2u: goto P_0c0c96a2;
case 0x0c0c96a4u: goto P_0c0c96a4;
case 0x0c0c96a6u: goto P_0c0c96a6;
case 0x0c0c96a8u: goto P_0c0c96a8;
case 0x0c0c96aau: goto P_0c0c96aa;
case 0x0c0c96acu: goto P_0c0c96ac;
case 0x0c0c96aeu: goto P_0c0c96ae;
case 0x0c0c96b0u: goto P_0c0c96b0;
case 0x0c0c96b2u: goto P_0c0c96b2;
case 0x0c0c96b4u: goto P_0c0c96b4;
case 0x0c0c96b6u: goto P_0c0c96b6;
case 0x0c0c96b8u: goto P_0c0c96b8;
case 0x0c0c96bau: goto P_0c0c96ba;
case 0x0c0c96bcu: goto P_0c0c96bc;
case 0x0c0c96beu: goto P_0c0c96be;
case 0x0c0c96c0u: goto P_0c0c96c0;
case 0x0c0c96f0u: goto P_0c0c96f0;
case 0x0c0c96f2u: goto P_0c0c96f2;
case 0x0c0c96f4u: goto P_0c0c96f4;
case 0x0c0c96f6u: goto P_0c0c96f6;
case 0x0c0c96f8u: goto P_0c0c96f8;
case 0x0c0c96fau: goto P_0c0c96fa;
case 0x0c0c96fcu: goto P_0c0c96fc;
case 0x0c0c96feu: goto P_0c0c96fe;
case 0x0c0c9700u: goto P_0c0c9700;
case 0x0c0c9702u: goto P_0c0c9702;
case 0x0c0c9704u: goto P_0c0c9704;
case 0x0c0c9706u: goto P_0c0c9706;
case 0x0c0c9708u: goto P_0c0c9708;
case 0x0c0c970au: goto P_0c0c970a;
case 0x0c0c970cu: goto P_0c0c970c;
case 0x0c0c970eu: goto P_0c0c970e;
case 0x0c0c9710u: goto P_0c0c9710;
case 0x0c0c9712u: goto P_0c0c9712;
case 0x0c0c9714u: goto P_0c0c9714;
case 0x0c0c9716u: goto P_0c0c9716;
case 0x0c0c9718u: goto P_0c0c9718;
case 0x0c0c971au: goto P_0c0c971a;
case 0x0c0c971cu: goto P_0c0c971c;
case 0x0c0c971eu: goto P_0c0c971e;
case 0x0c0c9720u: goto P_0c0c9720;
case 0x0c0c9722u: goto P_0c0c9722;
case 0x0c0c9724u: goto P_0c0c9724;
case 0x0c0c9726u: goto P_0c0c9726;
case 0x0c0c9728u: goto P_0c0c9728;
case 0x0c0c972au: goto P_0c0c972a;
case 0x0c0c972cu: goto P_0c0c972c;
case 0x0c0c972eu: goto P_0c0c972e;
case 0x0c0c9730u: goto P_0c0c9730;
case 0x0c0c9732u: goto P_0c0c9732;
case 0x0c0c9734u: goto P_0c0c9734;
case 0x0c0c9736u: goto P_0c0c9736;
case 0x0c0c9738u: goto P_0c0c9738;
case 0x0c0c973au: goto P_0c0c973a;
case 0x0c0c973cu: goto P_0c0c973c;
case 0x0c0c973eu: goto P_0c0c973e;
case 0x0c0c9740u: goto P_0c0c9740;
case 0x0c0c9742u: goto P_0c0c9742;
case 0x0c0c9744u: goto P_0c0c9744;
case 0x0c0c9746u: goto P_0c0c9746;
case 0x0c0c9748u: goto P_0c0c9748;
case 0x0c0c974au: goto P_0c0c974a;
case 0x0c0c974cu: goto P_0c0c974c;
case 0x0c0c974eu: goto P_0c0c974e;
case 0x0c0c9750u: goto P_0c0c9750;
case 0x0c0c9752u: goto P_0c0c9752;
case 0x0c0c9754u: goto P_0c0c9754;
case 0x0c0c9756u: goto P_0c0c9756;
case 0x0c0c9758u: goto P_0c0c9758;
case 0x0c0c975au: goto P_0c0c975a;
case 0x0c0c975cu: goto P_0c0c975c;
case 0x0c0c975eu: goto P_0c0c975e;
case 0x0c0c9760u: goto P_0c0c9760;
case 0x0c0c9762u: goto P_0c0c9762;
case 0x0c0c9764u: goto P_0c0c9764;
case 0x0c0c9766u: goto P_0c0c9766;
case 0x0c0c9768u: goto P_0c0c9768;
case 0x0c0c976au: goto P_0c0c976a;
case 0x0c0c976cu: goto P_0c0c976c;
case 0x0c0c976eu: goto P_0c0c976e;
case 0x0c0c9770u: goto P_0c0c9770;
case 0x0c0c9772u: goto P_0c0c9772;
case 0x0c0c9774u: goto P_0c0c9774;
case 0x0c0c9776u: goto P_0c0c9776;
case 0x0c0c9778u: goto P_0c0c9778;
case 0x0c0c977au: goto P_0c0c977a;
case 0x0c0c977cu: goto P_0c0c977c;
case 0x0c0c977eu: goto P_0c0c977e;
case 0x0c0c9780u: goto P_0c0c9780;
case 0x0c0c9782u: goto P_0c0c9782;
case 0x0c0c9784u: goto P_0c0c9784;
case 0x0c0c9786u: goto P_0c0c9786;
case 0x0c0c9788u: goto P_0c0c9788;
case 0x0c0c978au: goto P_0c0c978a;
case 0x0c0c978cu: goto P_0c0c978c;
case 0x0c0c978eu: goto P_0c0c978e;
case 0x0c0c9790u: goto P_0c0c9790;
case 0x0c0c9792u: goto P_0c0c9792;
case 0x0c0c9794u: goto P_0c0c9794;
case 0x0c0c9796u: goto P_0c0c9796;
case 0x0c0c9798u: goto P_0c0c9798;
case 0x0c0c979au: goto P_0c0c979a;
case 0x0c0c97b0u: goto P_0c0c97b0;
case 0x0c0c97b2u: goto P_0c0c97b2;
case 0x0c0c97b4u: goto P_0c0c97b4;
case 0x0c0c97b6u: goto P_0c0c97b6;
case 0x0c0c97b8u: goto P_0c0c97b8;
case 0x0c0c97bau: goto P_0c0c97ba;
case 0x0c0c97bcu: goto P_0c0c97bc;
case 0x0c0c97beu: goto P_0c0c97be;
case 0x0c0c97c0u: goto P_0c0c97c0;
case 0x0c0c97c2u: goto P_0c0c97c2;
case 0x0c0c97c4u: goto P_0c0c97c4;
case 0x0c0c97c6u: goto P_0c0c97c6;
case 0x0c0c97c8u: goto P_0c0c97c8;
case 0x0c0c97cau: goto P_0c0c97ca;
case 0x0c0c97ccu: goto P_0c0c97cc;
case 0x0c0c97ceu: goto P_0c0c97ce;
case 0x0c0c97d0u: goto P_0c0c97d0;
case 0x0c0c97d2u: goto P_0c0c97d2;
case 0x0c0c97d4u: goto P_0c0c97d4;
case 0x0c0c97d6u: goto P_0c0c97d6;
case 0x0c0c97d8u: goto P_0c0c97d8;
case 0x0c0c97dau: goto P_0c0c97da;
case 0x0c0c97dcu: goto P_0c0c97dc;
case 0x0c0c97deu: goto P_0c0c97de;
case 0x0c0c97e0u: goto P_0c0c97e0;
case 0x0c0c97e2u: goto P_0c0c97e2;
case 0x0c0c97e4u: goto P_0c0c97e4;
case 0x0c0c97e6u: goto P_0c0c97e6;
case 0x0c0c97e8u: goto P_0c0c97e8;
case 0x0c0c97eau: goto P_0c0c97ea;
case 0x0c0c97ecu: goto P_0c0c97ec;
case 0x0c0c97eeu: goto P_0c0c97ee;
case 0x0c0c97f0u: goto P_0c0c97f0;
case 0x0c0c97f2u: goto P_0c0c97f2;
case 0x0c0c97f4u: goto P_0c0c97f4;
case 0x0c0c97f6u: goto P_0c0c97f6;
case 0x0c0c97f8u: goto P_0c0c97f8;
case 0x0c0c97fau: goto P_0c0c97fa;
case 0x0c0c97fcu: goto P_0c0c97fc;
case 0x0c0c97feu: goto P_0c0c97fe;
case 0x0c0c9800u: goto P_0c0c9800;
case 0x0c0c9802u: goto P_0c0c9802;
case 0x0c0c9804u: goto P_0c0c9804;
case 0x0c0c9806u: goto P_0c0c9806;
case 0x0c0c9808u: goto P_0c0c9808;
case 0x0c0c980au: goto P_0c0c980a;
case 0x0c0c980cu: goto P_0c0c980c;
case 0x0c0c980eu: goto P_0c0c980e;
case 0x0c0c9810u: goto P_0c0c9810;
case 0x0c0c9812u: goto P_0c0c9812;
case 0x0c0c9814u: goto P_0c0c9814;
case 0x0c0c9816u: goto P_0c0c9816;
case 0x0c0c9818u: goto P_0c0c9818;
case 0x0c0c981au: goto P_0c0c981a;
case 0x0c0c981cu: goto P_0c0c981c;
case 0x0c0c981eu: goto P_0c0c981e;
case 0x0c0c9820u: goto P_0c0c9820;
case 0x0c0c9822u: goto P_0c0c9822;
case 0x0c0c9824u: goto P_0c0c9824;
case 0x0c0c9826u: goto P_0c0c9826;
case 0x0c0c9828u: goto P_0c0c9828;
case 0x0c0c982au: goto P_0c0c982a;
case 0x0c0c982cu: goto P_0c0c982c;
case 0x0c0c982eu: goto P_0c0c982e;
case 0x0c0c9830u: goto P_0c0c9830;
case 0x0c0c9832u: goto P_0c0c9832;
case 0x0c0c9834u: goto P_0c0c9834;
case 0x0c0c9836u: goto P_0c0c9836;
case 0x0c0c9838u: goto P_0c0c9838;
case 0x0c0c983au: goto P_0c0c983a;
case 0x0c0c983cu: goto P_0c0c983c;
case 0x0c0c983eu: goto P_0c0c983e;
case 0x0c0c9840u: goto P_0c0c9840;
case 0x0c0c9842u: goto P_0c0c9842;
case 0x0c0c9844u: goto P_0c0c9844;
case 0x0c0c9846u: goto P_0c0c9846;
case 0x0c0c9848u: goto P_0c0c9848;
case 0x0c0c984au: goto P_0c0c984a;
case 0x0c0c984cu: goto P_0c0c984c;
case 0x0c0c984eu: goto P_0c0c984e;
case 0x0c0c9850u: goto P_0c0c9850;
case 0x0c0c9852u: goto P_0c0c9852;
case 0x0c0c9854u: goto P_0c0c9854;
case 0x0c0c9856u: goto P_0c0c9856;
case 0x0c0c9858u: goto P_0c0c9858;
case 0x0c0c985au: goto P_0c0c985a;
case 0x0c0c985cu: goto P_0c0c985c;
case 0x0c0c985eu: goto P_0c0c985e;
case 0x0c0c9860u: goto P_0c0c9860;
case 0x0c0c9862u: goto P_0c0c9862;
case 0x0c0c9864u: goto P_0c0c9864;
case 0x0c0c9866u: goto P_0c0c9866;
case 0x0c0c9868u: goto P_0c0c9868;
case 0x0c0c986au: goto P_0c0c986a;
case 0x0c0c986cu: goto P_0c0c986c;
case 0x0c0c986eu: goto P_0c0c986e;
case 0x0c0c9870u: goto P_0c0c9870;
case 0x0c0c9872u: goto P_0c0c9872;
case 0x0c0c9874u: goto P_0c0c9874;
case 0x0c0c9890u: goto P_0c0c9890;
case 0x0c0c9892u: goto P_0c0c9892;
case 0x0c0c9894u: goto P_0c0c9894;
case 0x0c0c9896u: goto P_0c0c9896;
case 0x0c0c9898u: goto P_0c0c9898;
case 0x0c0c989au: goto P_0c0c989a;
case 0x0c0c989cu: goto P_0c0c989c;
case 0x0c0c989eu: goto P_0c0c989e;
case 0x0c0c98a0u: goto P_0c0c98a0;
case 0x0c0c98a2u: goto P_0c0c98a2;
case 0x0c0c98a4u: goto P_0c0c98a4;
case 0x0c0c98a6u: goto P_0c0c98a6;
case 0x0c0c98a8u: goto P_0c0c98a8;
case 0x0c0c98aau: goto P_0c0c98aa;
case 0x0c0c98acu: goto P_0c0c98ac;
case 0x0c0c98aeu: goto P_0c0c98ae;
case 0x0c0c98b0u: goto P_0c0c98b0;
case 0x0c0c98b2u: goto P_0c0c98b2;
case 0x0c0c98b4u: goto P_0c0c98b4;
case 0x0c0c98b6u: goto P_0c0c98b6;
case 0x0c0c98b8u: goto P_0c0c98b8;
case 0x0c0c98bau: goto P_0c0c98ba;
case 0x0c0c98bcu: goto P_0c0c98bc;
case 0x0c0c98beu: goto P_0c0c98be;
case 0x0c0c98c0u: goto P_0c0c98c0;
case 0x0c0c98c2u: goto P_0c0c98c2;
case 0x0c0c98c4u: goto P_0c0c98c4;
case 0x0c0c98c6u: goto P_0c0c98c6;
case 0x0c0c98c8u: goto P_0c0c98c8;
case 0x0c0c98cau: goto P_0c0c98ca;
case 0x0c0c98ccu: goto P_0c0c98cc;
case 0x0c0c98ceu: goto P_0c0c98ce;
case 0x0c0c98d0u: goto P_0c0c98d0;
case 0x0c0c98d2u: goto P_0c0c98d2;
case 0x0c0c98d4u: goto P_0c0c98d4;
case 0x0c0c98d6u: goto P_0c0c98d6;
case 0x0c0c98d8u: goto P_0c0c98d8;
case 0x0c0c98dau: goto P_0c0c98da;
case 0x0c0c98dcu: goto P_0c0c98dc;
case 0x0c0c98deu: goto P_0c0c98de;
case 0x0c0c98e0u: goto P_0c0c98e0;
case 0x0c0c98e2u: goto P_0c0c98e2;
case 0x0c0c98e4u: goto P_0c0c98e4;
case 0x0c0c98e6u: goto P_0c0c98e6;
case 0x0c0c98e8u: goto P_0c0c98e8;
case 0x0c0c98eau: goto P_0c0c98ea;
case 0x0c0c9910u: goto P_0c0c9910;
case 0x0c0c9912u: goto P_0c0c9912;
case 0x0c0c9914u: goto P_0c0c9914;
case 0x0c0c9916u: goto P_0c0c9916;
case 0x0c0c9918u: goto P_0c0c9918;
case 0x0c0c991au: goto P_0c0c991a;
case 0x0c0c991cu: goto P_0c0c991c;
case 0x0c0c991eu: goto P_0c0c991e;
case 0x0c0c9920u: goto P_0c0c9920;
case 0x0c0c9922u: goto P_0c0c9922;
case 0x0c0c9924u: goto P_0c0c9924;
case 0x0c0c9926u: goto P_0c0c9926;
case 0x0c0c9928u: goto P_0c0c9928;
case 0x0c0c992au: goto P_0c0c992a;
case 0x0c0c992cu: goto P_0c0c992c;
case 0x0c0c992eu: goto P_0c0c992e;
case 0x0c0c9930u: goto P_0c0c9930;
case 0x0c0c9932u: goto P_0c0c9932;
case 0x0c0c9934u: goto P_0c0c9934;
case 0x0c0c9936u: goto P_0c0c9936;
case 0x0c0c9938u: goto P_0c0c9938;
case 0x0c0c993au: goto P_0c0c993a;
case 0x0c0c993cu: goto P_0c0c993c;
case 0x0c0c993eu: goto P_0c0c993e;
case 0x0c0c9940u: goto P_0c0c9940;
case 0x0c0c9942u: goto P_0c0c9942;
case 0x0c0c9944u: goto P_0c0c9944;
case 0x0c0c9946u: goto P_0c0c9946;
case 0x0c0c9948u: goto P_0c0c9948;
case 0x0c0c994au: goto P_0c0c994a;
case 0x0c0c994cu: goto P_0c0c994c;
case 0x0c0c994eu: goto P_0c0c994e;
case 0x0c0c9950u: goto P_0c0c9950;
case 0x0c0c9952u: goto P_0c0c9952;
case 0x0c0c9954u: goto P_0c0c9954;
case 0x0c0c9956u: goto P_0c0c9956;
case 0x0c0c9958u: goto P_0c0c9958;
case 0x0c0c995au: goto P_0c0c995a;
case 0x0c0c995cu: goto P_0c0c995c;
case 0x0c0c995eu: goto P_0c0c995e;
case 0x0c0c9960u: goto P_0c0c9960;
case 0x0c0c9962u: goto P_0c0c9962;
case 0x0c0c9964u: goto P_0c0c9964;
case 0x0c0c9966u: goto P_0c0c9966;
case 0x0c0c9968u: goto P_0c0c9968;
case 0x0c0c996au: goto P_0c0c996a;
case 0x0c0c996cu: goto P_0c0c996c;
case 0x0c0c996eu: goto P_0c0c996e;
case 0x0c0c9970u: goto P_0c0c9970;
case 0x0c0c9972u: goto P_0c0c9972;
case 0x0c0c9974u: goto P_0c0c9974;
case 0x0c0c9976u: goto P_0c0c9976;
case 0x0c0c9978u: goto P_0c0c9978;
case 0x0c0c997au: goto P_0c0c997a;
case 0x0c0c997cu: goto P_0c0c997c;
case 0x0c0c997eu: goto P_0c0c997e;
case 0x0c0c9980u: goto P_0c0c9980;
case 0x0c0c9982u: goto P_0c0c9982;
case 0x0c0c9984u: goto P_0c0c9984;
case 0x0c0c9986u: goto P_0c0c9986;
case 0x0c0c9988u: goto P_0c0c9988;
case 0x0c0c998au: goto P_0c0c998a;
case 0x0c0c998cu: goto P_0c0c998c;
case 0x0c0c99bcu: goto P_0c0c99bc;
case 0x0c0c99beu: goto P_0c0c99be;
case 0x0c0c99c0u: goto P_0c0c99c0;
case 0x0c0c99c2u: goto P_0c0c99c2;
case 0x0c0c99c4u: goto P_0c0c99c4;
case 0x0c0c99c6u: goto P_0c0c99c6;
case 0x0c0c99c8u: goto P_0c0c99c8;
case 0x0c0c99eeu: goto P_0c0c99ee;
case 0x0c0c99f0u: goto P_0c0c99f0;
case 0x0c0c99f2u: goto P_0c0c99f2;
case 0x0c0c99f4u: goto P_0c0c99f4;
case 0x0c0c99f6u: goto P_0c0c99f6;
case 0x0c0c99f8u: goto P_0c0c99f8;
case 0x0c0c99fau: goto P_0c0c99fa;
case 0x0c0c99fcu: goto P_0c0c99fc;
case 0x0c0c99feu: goto P_0c0c99fe;
case 0x0c0c9a00u: goto P_0c0c9a00;
case 0x0c0c9a02u: goto P_0c0c9a02;
case 0x0c0c9a04u: goto P_0c0c9a04;
case 0x0c0c9a06u: goto P_0c0c9a06;
case 0x0c0c9a08u: goto P_0c0c9a08;
case 0x0c0c9a0au: goto P_0c0c9a0a;
case 0x0c0c9a0cu: goto P_0c0c9a0c;
case 0x0c0c9a0eu: goto P_0c0c9a0e;
case 0x0c0c9a10u: goto P_0c0c9a10;
case 0x0c0c9a12u: goto P_0c0c9a12;
case 0x0c0c9a14u: goto P_0c0c9a14;
case 0x0c0c9a16u: goto P_0c0c9a16;
case 0x0c0c9a18u: goto P_0c0c9a18;
case 0x0c0c9a1au: goto P_0c0c9a1a;
case 0x0c0c9a1cu: goto P_0c0c9a1c;
case 0x0c0c9a1eu: goto P_0c0c9a1e;
case 0x0c0c9a20u: goto P_0c0c9a20;
case 0x0c0c9a22u: goto P_0c0c9a22;
case 0x0c0c9a24u: goto P_0c0c9a24;
case 0x0c0c9a26u: goto P_0c0c9a26;
case 0x0c0c9a28u: goto P_0c0c9a28;
case 0x0c0c9a2au: goto P_0c0c9a2a;
case 0x0c0c9a2cu: goto P_0c0c9a2c;
case 0x0c0c9a2eu: goto P_0c0c9a2e;
case 0x0c0c9a30u: goto P_0c0c9a30;
case 0x0c0c9a32u: goto P_0c0c9a32;
case 0x0c0c9a34u: goto P_0c0c9a34;
case 0x0c0c9a36u: goto P_0c0c9a36;
case 0x0c0c9a38u: goto P_0c0c9a38;
case 0x0c0c9a3au: goto P_0c0c9a3a;
case 0x0c0c9a3cu: goto P_0c0c9a3c;
case 0x0c0c9a3eu: goto P_0c0c9a3e;
case 0x0c0c9a40u: goto P_0c0c9a40;
case 0x0c0c9a42u: goto P_0c0c9a42;
case 0x0c0c9a44u: goto P_0c0c9a44;
case 0x0c0c9a46u: goto P_0c0c9a46;
case 0x0c0c9a48u: goto P_0c0c9a48;
case 0x0c0c9a4au: goto P_0c0c9a4a;
case 0x0c0c9a4cu: goto P_0c0c9a4c;
case 0x0c0c9a4eu: goto P_0c0c9a4e;
case 0x0c0c9a50u: goto P_0c0c9a50;
case 0x0c0c9a52u: goto P_0c0c9a52;
case 0x0c0c9a54u: goto P_0c0c9a54;
case 0x0c0c9a56u: goto P_0c0c9a56;
case 0x0c0c9a58u: goto P_0c0c9a58;
case 0x0c0c9a5au: goto P_0c0c9a5a;
case 0x0c0c9a5cu: goto P_0c0c9a5c;
case 0x0c0c9a5eu: goto P_0c0c9a5e;
case 0x0c0c9a60u: goto P_0c0c9a60;
case 0x0c0c9a62u: goto P_0c0c9a62;
case 0x0c0c9a64u: goto P_0c0c9a64;
case 0x0c0c9a66u: goto P_0c0c9a66;
case 0x0c0c9a68u: goto P_0c0c9a68;
case 0x0c0c9a6au: goto P_0c0c9a6a;
case 0x0c0c9a6cu: goto P_0c0c9a6c;
case 0x0c0c9a6eu: goto P_0c0c9a6e;
case 0x0c0c9a70u: goto P_0c0c9a70;
case 0x0c0c9a72u: goto P_0c0c9a72;
case 0x0c0c9a74u: goto P_0c0c9a74;
case 0x0c0c9a76u: goto P_0c0c9a76;
case 0x0c0c9a78u: goto P_0c0c9a78;
case 0x0c0c9ad0u: goto P_0c0c9ad0;
case 0x0c0c9ad2u: goto P_0c0c9ad2;
case 0x0c0c9ad4u: goto P_0c0c9ad4;
case 0x0c0c9ad6u: goto P_0c0c9ad6;
case 0x0c0c9ad8u: goto P_0c0c9ad8;
case 0x0c0c9adau: goto P_0c0c9ada;
case 0x0c0c9adcu: goto P_0c0c9adc;
case 0x0c0c9adeu: goto P_0c0c9ade;
case 0x0c0c9ae0u: goto P_0c0c9ae0;
case 0x0c0c9ae2u: goto P_0c0c9ae2;
case 0x0c0c9ae4u: goto P_0c0c9ae4;
case 0x0c0c9ae6u: goto P_0c0c9ae6;
case 0x0c0c9ae8u: goto P_0c0c9ae8;
case 0x0c0c9aeau: goto P_0c0c9aea;
case 0x0c0c9aecu: goto P_0c0c9aec;
case 0x0c0c9aeeu: goto P_0c0c9aee;
case 0x0c0c9af0u: goto P_0c0c9af0;
case 0x0c0c9af2u: goto P_0c0c9af2;
case 0x0c0c9af4u: goto P_0c0c9af4;
case 0x0c0c9af6u: goto P_0c0c9af6;
case 0x0c0c9af8u: goto P_0c0c9af8;
case 0x0c0c9afau: goto P_0c0c9afa;
case 0x0c0c9afcu: goto P_0c0c9afc;
case 0x0c0c9afeu: goto P_0c0c9afe;
case 0x0c0c9b00u: goto P_0c0c9b00;
case 0x0c0c9b02u: goto P_0c0c9b02;
case 0x0c0c9b04u: goto P_0c0c9b04;
case 0x0c0c9b06u: goto P_0c0c9b06;
case 0x0c0c9b08u: goto P_0c0c9b08;
case 0x0c0c9b0au: goto P_0c0c9b0a;
case 0x0c0c9b0cu: goto P_0c0c9b0c;
case 0x0c0c9b0eu: goto P_0c0c9b0e;
case 0x0c0c9b10u: goto P_0c0c9b10;
case 0x0c0c9b12u: goto P_0c0c9b12;
case 0x0c0c9b14u: goto P_0c0c9b14;
case 0x0c0c9b16u: goto P_0c0c9b16;
case 0x0c0c9b18u: goto P_0c0c9b18;
case 0x0c0c9b1au: goto P_0c0c9b1a;
case 0x0c0c9b1cu: goto P_0c0c9b1c;
case 0x0c0c9b1eu: goto P_0c0c9b1e;
case 0x0c0c9b20u: goto P_0c0c9b20;
case 0x0c0c9b22u: goto P_0c0c9b22;
case 0x0c0c9b24u: goto P_0c0c9b24;
case 0x0c0c9b26u: goto P_0c0c9b26;
case 0x0c0c9b28u: goto P_0c0c9b28;
case 0x0c0c9b2au: goto P_0c0c9b2a;
case 0x0c0c9b2cu: goto P_0c0c9b2c;
case 0x0c0c9b40u: goto P_0c0c9b40;
case 0x0c0c9b42u: goto P_0c0c9b42;
case 0x0c0c9b44u: goto P_0c0c9b44;
case 0x0c0c9b46u: goto P_0c0c9b46;
case 0x0c0c9b48u: goto P_0c0c9b48;
case 0x0c0c9b4au: goto P_0c0c9b4a;
case 0x0c0c9b4cu: goto P_0c0c9b4c;
case 0x0c0c9b4eu: goto P_0c0c9b4e;
case 0x0c0c9b50u: goto P_0c0c9b50;
case 0x0c0c9b52u: goto P_0c0c9b52;
case 0x0c0c9b54u: goto P_0c0c9b54;
case 0x0c0c9b56u: goto P_0c0c9b56;
case 0x0c0c9b58u: goto P_0c0c9b58;
case 0x0c0c9b5au: goto P_0c0c9b5a;
case 0x0c0c9b5cu: goto P_0c0c9b5c;
case 0x0c0c9b5eu: goto P_0c0c9b5e;
case 0x0c0c9b60u: goto P_0c0c9b60;
case 0x0c0c9b90u: goto P_0c0c9b90;
case 0x0c0c9b92u: goto P_0c0c9b92;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c8e6c: /* original 2fe6, guest PC 0x0c0c8e6c */
if(!s->budget--) { s->failed_pc=0x0c0c8e6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e6e;
P_0c0c8e6e: /* original e043, guest PC 0x0c0c8e6e */
if(!s->budget--) { s->failed_pc=0x0c0c8e6eu; return 0; }
r[0]=0x00000043u;
goto P_0c0c8e70;
P_0c0c8e70: /* original 2fd6, guest PC 0x0c0c8e70 */
if(!s->budget--) { s->failed_pc=0x0c0c8e70u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e72;
P_0c0c8e72: /* original e307, guest PC 0x0c0c8e72 */
if(!s->budget--) { s->failed_pc=0x0c0c8e72u; return 0; }
r[3]=0x00000007u;
goto P_0c0c8e74;
P_0c0c8e74: /* original 2fc6, guest PC 0x0c0c8e74 */
if(!s->budget--) { s->failed_pc=0x0c0c8e74u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e76;
P_0c0c8e76: /* original e228, guest PC 0x0c0c8e76 */
if(!s->budget--) { s->failed_pc=0x0c0c8e76u; return 0; }
r[2]=0x00000028u;
goto P_0c0c8e78;
P_0c0c8e78: /* original 2fb6, guest PC 0x0c0c8e78 */
if(!s->budget--) { s->failed_pc=0x0c0c8e78u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e7a;
P_0c0c8e7a: /* original dc33, guest PC 0x0c0c8e7a */
if(!s->budget--) { s->failed_pc=0x0c0c8e7au; return 0; }
r[12]=read(ram,0x0c0c8f48u,4);
goto P_0c0c8e7c;
P_0c0c8e7c: /* original 4f22, guest PC 0x0c0c8e7c */
if(!s->budget--) { s->failed_pc=0x0c0c8e7cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8e7e;
P_0c0c8e7e: /* original 0ecc, guest PC 0x0c0c8e7e */
if(!s->budget--) { s->failed_pc=0x0c0c8e7eu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c8e80;
P_0c0c8e80: /* original d032, guest PC 0x0c0c8e80 */
if(!s->budget--) { s->failed_pc=0x0c0c8e80u; return 0; }
r[0]=read(ram,0x0c0c8f4cu,4);
goto P_0c0c8e82;
P_0c0c8e82: /* original 7ffc, guest PC 0x0c0c8e82 */
if(!s->budget--) { s->failed_pc=0x0c0c8e82u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c8e84;
P_0c0c8e84: /* original db2f, guest PC 0x0c0c8e84 */
if(!s->budget--) { s->failed_pc=0x0c0c8e84u; return 0; }
r[11]=read(ram,0x0c0c8f44u,4);
goto P_0c0c8e86;
P_0c0c8e86: /* original 04ec, guest PC 0x0c0c8e86 */
if(!s->budget--) { s->failed_pc=0x0c0c8e86u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8e88;
P_0c0c8e88: /* original 644c, guest PC 0x0c0c8e88 */
if(!s->budget--) { s->failed_pc=0x0c0c8e88u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c8e8a;
P_0c0c8e8a: /* original 443c, guest PC 0x0c0c8e8a */
if(!s->budget--) { s->failed_pc=0x0c0c8e8au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0c8e8c;
P_0c0c8e8c: /* original 242b, guest PC 0x0c0c8e8c */
if(!s->budget--) { s->failed_pc=0x0c0c8e8cu; return 0; }
r[4]|=r[2];
goto P_0c0c8e8e;
P_0c0c8e8e: /* original 2f42, guest PC 0x0c0c8e8e */
if(!s->budget--) { s->failed_pc=0x0c0c8e8eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c8e90;
P_0c0c8e90: /* original d12f, guest PC 0x0c0c8e90 */
if(!s->budget--) { s->failed_pc=0x0c0c8e90u; return 0; }
r[1]=read(ram,0x0c0c8f50u,4);
goto P_0c0c8e92;
P_0c0c8e92: /* original 2f16, guest PC 0x0c0c8e92 */
if(!s->budget--) { s->failed_pc=0x0c0c8e92u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8e94;
P_0c0c8e94: /* original d32f, guest PC 0x0c0c8e94 */
if(!s->budget--) { s->failed_pc=0x0c0c8e94u; return 0; }
r[3]=read(ram,0x0c0c8f54u,4);
goto P_0c0c8e96;
P_0c0c8e96: /* original 430b, guest PC 0x0c0c8e96 */
if(!s->budget--) { s->failed_pc=0x0c0c8e96u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8e9au;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8e9au) { target=s->pc; goto dispatch; }
goto P_0c0c8e9a;
P_0c0c8e98: /* original 54f1, guest PC 0x0c0c8e98 */
if(!s->budget--) { s->failed_pc=0x0c0c8e98u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c8e9a;
P_0c0c8e9a: /* original 904e, guest PC 0x0c0c8e9a */
if(!s->budget--) { s->failed_pc=0x0c0c8e9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3au,2);
goto P_0c0c8e9c;
P_0c0c8e9c: /* original 7f04, guest PC 0x0c0c8e9c */
if(!s->budget--) { s->failed_pc=0x0c0c8e9cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8e9e;
P_0c0c8e9e: /* original 934d, guest PC 0x0c0c8e9e */
if(!s->budget--) { s->failed_pc=0x0c0c8e9eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3cu,2);
goto P_0c0c8ea0;
P_0c0c8ea0: /* original 0dbe, guest PC 0x0c0c8ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea0u; return 0; }
r[13]=read(ram,r[11]+r[0],4);
goto P_0c0c8ea2;
P_0c0c8ea2: /* original 23d8, guest PC 0x0c0c8ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8ea4;
P_0c0c8ea4: /* original 8f14, guest PC 0x0c0c8ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea4u; return 0; }
cond=r[17]&1u;
r[4]=0x0000000fu;
if(!cond) { goto P_0c0c8ed0; }
goto P_0c0c8ea8;
P_0c0c8ea6: /* original e40f, guest PC 0x0c0c8ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea6u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c8ea8;
P_0c0c8ea8: /* original 9249, guest PC 0x0c0c8ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ea8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f3eu,2);
goto P_0c0c8eaa;
P_0c0c8eaa: /* original 22d8, guest PC 0x0c0c8eaa */
if(!s->budget--) { s->failed_pc=0x0c0c8eaau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8eac;
P_0c0c8eac: /* original 8b15, guest PC 0x0c0c8eac */
if(!s->budget--) { s->failed_pc=0x0c0c8eacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eae;
P_0c0c8eae: /* original e308, guest PC 0x0c0c8eae */
if(!s->budget--) { s->failed_pc=0x0c0c8eaeu; return 0; }
r[3]=0x00000008u;
goto P_0c0c8eb0;
P_0c0c8eb0: /* original 23d8, guest PC 0x0c0c8eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8eb2;
P_0c0c8eb2: /* original 8b12, guest PC 0x0c0c8eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eb4;
P_0c0c8eb4: /* original d228, guest PC 0x0c0c8eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb4u; return 0; }
r[2]=read(ram,0x0c0c8f58u,4);
goto P_0c0c8eb6;
P_0c0c8eb6: /* original 22d8, guest PC 0x0c0c8eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8eb8;
P_0c0c8eb8: /* original 8b0f, guest PC 0x0c0c8eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c8eb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8eda; }
goto P_0c0c8eba;
P_0c0c8eba: /* original 9341, guest PC 0x0c0c8eba */
if(!s->budget--) { s->failed_pc=0x0c0c8ebau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8f40u,2);
goto P_0c0c8ebc;
P_0c0c8ebc: /* original 23d8, guest PC 0x0c0c8ebc */
if(!s->budget--) { s->failed_pc=0x0c0c8ebcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8ebe;
P_0c0c8ebe: /* original 8b11, guest PC 0x0c0c8ebe */
if(!s->budget--) { s->failed_pc=0x0c0c8ebeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ec0;
P_0c0c8ec0: /* original e204, guest PC 0x0c0c8ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec0u; return 0; }
r[2]=0x00000004u;
goto P_0c0c8ec2;
P_0c0c8ec2: /* original 22d8, guest PC 0x0c0c8ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c8ec4;
P_0c0c8ec4: /* original 8b0e, guest PC 0x0c0c8ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ec6;
P_0c0c8ec6: /* original d325, guest PC 0x0c0c8ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec6u; return 0; }
r[3]=read(ram,0x0c0c8f5cu,4);
goto P_0c0c8ec8;
P_0c0c8ec8: /* original 23d8, guest PC 0x0c0c8ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ec8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c8eca;
P_0c0c8eca: /* original 8b0b, guest PC 0x0c0c8eca */
if(!s->budget--) { s->failed_pc=0x0c0c8ecau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ee4; }
goto P_0c0c8ecc;
P_0c0c8ecc: /* original a014, guest PC 0x0c0c8ecc */
if(!s->budget--) { s->failed_pc=0x0c0c8eccu; return 0; }
goto P_0c0c8ef8;
P_0c0c8ece: /* original 0009, guest PC 0x0c0c8ece */
if(!s->budget--) { s->failed_pc=0x0c0c8eceu; return 0; }
goto P_0c0c8ed0;
P_0c0c8ed0: /* original 7eff, guest PC 0x0c0c8ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed0u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c8ed2;
P_0c0c8ed2: /* original 4e11, guest PC 0x0c0c8ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0c8ed4;
P_0c0c8ed4: /* original 8910, guest PC 0x0c0c8ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8ef8; }
goto P_0c0c8ed6;
P_0c0c8ed6: /* original a00f, guest PC 0x0c0c8ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed6u; return 0; }
r[14]=r[4];
goto P_0c0c8ef8;
P_0c0c8ed8: /* original 6e43, guest PC 0x0c0c8ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ed8u; return 0; }
r[14]=r[4];
goto P_0c0c8eda;
P_0c0c8eda: /* original 7e01, guest PC 0x0c0c8eda */
if(!s->budget--) { s->failed_pc=0x0c0c8edau; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8edc;
P_0c0c8edc: /* original 3e47, guest PC 0x0c0c8edc */
if(!s->budget--) { s->failed_pc=0x0c0c8edcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[4])!=0);
goto P_0c0c8ede;
P_0c0c8ede: /* original 8b0b, guest PC 0x0c0c8ede */
if(!s->budget--) { s->failed_pc=0x0c0c8edeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ef8; }
goto P_0c0c8ee0;
P_0c0c8ee0: /* original a00a, guest PC 0x0c0c8ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee0u; return 0; }
r[14]=0x00000000u;
goto P_0c0c8ef8;
P_0c0c8ee2: /* original ee00, guest PC 0x0c0c8ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee2u; return 0; }
r[14]=0x00000000u;
goto P_0c0c8ee4;
P_0c0c8ee4: /* original 60e3, guest PC 0x0c0c8ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee4u; return 0; }
r[0]=r[14];
goto P_0c0c8ee6;
P_0c0c8ee6: /* original 880f, guest PC 0x0c0c8ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0c8ee8;
P_0c0c8ee8: /* original 8b02, guest PC 0x0c0c8ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ee8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8ef0; }
goto P_0c0c8eea;
P_0c0c8eea: /* original d21d, guest PC 0x0c0c8eea */
if(!s->budget--) { s->failed_pc=0x0c0c8eeau; return 0; }
r[2]=read(ram,0x0c0c8f60u,4);
goto P_0c0c8eec;
P_0c0c8eec: /* original 420b, guest PC 0x0c0c8eec */
if(!s->budget--) { s->failed_pc=0x0c0c8eecu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8ef0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8ef0u) { target=s->pc; goto dispatch; }
goto P_0c0c8ef0;
P_0c0c8eee: /* original 0009, guest PC 0x0c0c8eee */
if(!s->budget--) { s->failed_pc=0x0c0c8eeeu; return 0; }
goto P_0c0c8ef0;
P_0c0c8ef0: /* original 60e3, guest PC 0x0c0c8ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef0u; return 0; }
r[0]=r[14];
goto P_0c0c8ef2;
P_0c0c8ef2: /* original 7001, guest PC 0x0c0c8ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c8ef4;
P_0c0c8ef4: /* original 4000, guest PC 0x0c0c8ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c8ef6;
P_0c0c8ef6: /* original 80bb, guest PC 0x0c0c8ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef6u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c0c8ef8;
P_0c0c8ef8: /* original 60e3, guest PC 0x0c0c8ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ef8u; return 0; }
r[0]=r[14];
goto P_0c0c8efa;
P_0c0c8efa: /* original 880e, guest PC 0x0c0c8efa */
if(!s->budget--) { s->failed_pc=0x0c0c8efau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0c8efc;
P_0c0c8efc: /* original 8b05, guest PC 0x0c0c8efc */
if(!s->budget--) { s->failed_pc=0x0c0c8efcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8f0a; }
goto P_0c0c8efe;
P_0c0c8efe: /* original d319, guest PC 0x0c0c8efe */
if(!s->budget--) { s->failed_pc=0x0c0c8efeu; return 0; }
r[3]=read(ram,0x0c0c8f64u,4);
goto P_0c0c8f00;
P_0c0c8f00: /* original 2d38, guest PC 0x0c0c8f00 */
if(!s->budget--) { s->failed_pc=0x0c0c8f00u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0c8f02;
P_0c0c8f02: /* original 8901, guest PC 0x0c0c8f02 */
if(!s->budget--) { s->failed_pc=0x0c0c8f02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8f08; }
goto P_0c0c8f04;
P_0c0c8f04: /* original a001, guest PC 0x0c0c8f04 */
if(!s->budget--) { s->failed_pc=0x0c0c8f04u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8f0a;
P_0c0c8f06: /* original 7e01, guest PC 0x0c0c8f06 */
if(!s->budget--) { s->failed_pc=0x0c0c8f06u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c8f08;
P_0c0c8f08: /* original 7eff, guest PC 0x0c0c8f08 */
if(!s->budget--) { s->failed_pc=0x0c0c8f08u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c8f0a;
P_0c0c8f0a: /* original e043, guest PC 0x0c0c8f0a */
if(!s->budget--) { s->failed_pc=0x0c0c8f0au; return 0; }
r[0]=0x00000043u;
goto P_0c0c8f0c;
P_0c0c8f0c: /* original 0ce4, guest PC 0x0c0c8f0c */
if(!s->budget--) { s->failed_pc=0x0c0c8f0cu; return 0; }
write(ram,r[12]+r[0],r[14],1);
goto P_0c0c8f0e;
P_0c0c8f0e: /* original e307, guest PC 0x0c0c8f0e */
if(!s->budget--) { s->failed_pc=0x0c0c8f0eu; return 0; }
r[3]=0x00000007u;
goto P_0c0c8f10;
P_0c0c8f10: /* original d00e, guest PC 0x0c0c8f10 */
if(!s->budget--) { s->failed_pc=0x0c0c8f10u; return 0; }
r[0]=read(ram,0x0c0c8f4cu,4);
goto P_0c0c8f12;
P_0c0c8f12: /* original e228, guest PC 0x0c0c8f12 */
if(!s->budget--) { s->failed_pc=0x0c0c8f12u; return 0; }
r[2]=0x00000028u;
goto P_0c0c8f14;
P_0c0c8f14: /* original 04ec, guest PC 0x0c0c8f14 */
if(!s->budget--) { s->failed_pc=0x0c0c8f14u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8f16;
P_0c0c8f16: /* original 644c, guest PC 0x0c0c8f16 */
if(!s->budget--) { s->failed_pc=0x0c0c8f16u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c8f18;
P_0c0c8f18: /* original 443c, guest PC 0x0c0c8f18 */
if(!s->budget--) { s->failed_pc=0x0c0c8f18u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0c8f1a;
P_0c0c8f1a: /* original 242b, guest PC 0x0c0c8f1a */
if(!s->budget--) { s->failed_pc=0x0c0c8f1au; return 0; }
r[4]|=r[2];
goto P_0c0c8f1c;
P_0c0c8f1c: /* original 2f42, guest PC 0x0c0c8f1c */
if(!s->budget--) { s->failed_pc=0x0c0c8f1cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c8f1e;
P_0c0c8f1e: /* original d512, guest PC 0x0c0c8f1e */
if(!s->budget--) { s->failed_pc=0x0c0c8f1eu; return 0; }
r[5]=read(ram,0x0c0c8f68u,4);
goto P_0c0c8f20;
P_0c0c8f20: /* original d112, guest PC 0x0c0c8f20 */
if(!s->budget--) { s->failed_pc=0x0c0c8f20u; return 0; }
r[1]=read(ram,0x0c0c8f6cu,4);
goto P_0c0c8f22;
P_0c0c8f22: /* original 410b, guest PC 0x0c0c8f22 */
if(!s->budget--) { s->failed_pc=0x0c0c8f22u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c8f26u;
r[6]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8f26u) { target=s->pc; goto dispatch; }
goto P_0c0c8f26;
P_0c0c8f24: /* original e600, guest PC 0x0c0c8f24 */
if(!s->budget--) { s->failed_pc=0x0c0c8f24u; return 0; }
r[6]=0x00000000u;
goto P_0c0c8f26;
P_0c0c8f26: /* original 7f04, guest PC 0x0c0c8f26 */
if(!s->budget--) { s->failed_pc=0x0c0c8f26u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8f28;
P_0c0c8f28: /* original d311, guest PC 0x0c0c8f28 */
if(!s->budget--) { s->failed_pc=0x0c0c8f28u; return 0; }
r[3]=read(ram,0x0c0c8f70u,4);
goto P_0c0c8f2a;
P_0c0c8f2a: /* original 4f26, guest PC 0x0c0c8f2a */
if(!s->budget--) { s->failed_pc=0x0c0c8f2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8f2c;
P_0c0c8f2c: /* original 6bf6, guest PC 0x0c0c8f2c */
if(!s->budget--) { s->failed_pc=0x0c0c8f2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c8f2e;
P_0c0c8f2e: /* original 6cf6, guest PC 0x0c0c8f2e */
if(!s->budget--) { s->failed_pc=0x0c0c8f2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c8f30;
P_0c0c8f30: /* original 6df6, guest PC 0x0c0c8f30 */
if(!s->budget--) { s->failed_pc=0x0c0c8f30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8f32;
P_0c0c8f32: /* original 432b, guest PC 0x0c0c8f32 */
if(!s->budget--) { s->failed_pc=0x0c0c8f32u; return 0; }
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
P_0c0c8f34: /* original 6ef6, guest PC 0x0c0c8f34 */
if(!s->budget--) { s->failed_pc=0x0c0c8f34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c8f36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8f36u; return 0; } return 1;
P_0c0c927c: /* original 2fe6, guest PC 0x0c0c927c */
if(!s->budget--) { s->failed_pc=0x0c0c927cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c927e;
P_0c0c927e: /* original 9033, guest PC 0x0c0c927e */
if(!s->budget--) { s->failed_pc=0x0c0c927eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c92e8u,2);
goto P_0c0c9280;
P_0c0c9280: /* original de1a, guest PC 0x0c0c9280 */
if(!s->budget--) { s->failed_pc=0x0c0c9280u; return 0; }
r[14]=read(ram,0x0c0c92ecu,4);
goto P_0c0c9282;
P_0c0c9282: /* original d51b, guest PC 0x0c0c9282 */
if(!s->budget--) { s->failed_pc=0x0c0c9282u; return 0; }
r[5]=read(ram,0x0c0c92f0u,4);
goto P_0c0c9284;
P_0c0c9284: /* original 04ee, guest PC 0x0c0c9284 */
if(!s->budget--) { s->failed_pc=0x0c0c9284u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c9286;
P_0c0c9286: /* original 4f22, guest PC 0x0c0c9286 */
if(!s->budget--) { s->failed_pc=0x0c0c9286u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9288;
P_0c0c9288: /* original 2458, guest PC 0x0c0c9288 */
if(!s->budget--) { s->failed_pc=0x0c0c9288u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c0c928a;
P_0c0c928a: /* original 890e, guest PC 0x0c0c928a */
if(!s->budget--) { s->failed_pc=0x0c0c928au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c92aa; }
goto P_0c0c928c;
P_0c0c928c: /* original e011, guest PC 0x0c0c928c */
if(!s->budget--) { s->failed_pc=0x0c0c928cu; return 0; }
r[0]=0x00000011u;
goto P_0c0c928e;
P_0c0c928e: /* original 04ec, guest PC 0x0c0c928e */
if(!s->budget--) { s->failed_pc=0x0c0c928eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9290;
P_0c0c9290: /* original 604c, guest PC 0x0c0c9290 */
if(!s->budget--) { s->failed_pc=0x0c0c9290u; return 0; }
r[0]=r[4]&255u;
goto P_0c0c9292;
P_0c0c9292: /* original 8848, guest PC 0x0c0c9292 */
if(!s->budget--) { s->failed_pc=0x0c0c9292u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000048u)!=0);
goto P_0c0c9294;
P_0c0c9294: /* original 8f04, guest PC 0x0c0c9294 */
if(!s->budget--) { s->failed_pc=0x0c0c9294u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c92a0; }
goto P_0c0c9298;
P_0c0c9296: /* original 6403, guest PC 0x0c0c9296 */
if(!s->budget--) { s->failed_pc=0x0c0c9296u; return 0; }
r[4]=r[0];
goto P_0c0c9298;
P_0c0c9298: /* original e010, guest PC 0x0c0c9298 */
if(!s->budget--) { s->failed_pc=0x0c0c9298u; return 0; }
r[0]=0x00000010u;
goto P_0c0c929a;
P_0c0c929a: /* original e349, guest PC 0x0c0c929a */
if(!s->budget--) { s->failed_pc=0x0c0c929au; return 0; }
r[3]=0x00000049u;
goto P_0c0c929c;
P_0c0c929c: /* original a005, guest PC 0x0c0c929c */
if(!s->budget--) { s->failed_pc=0x0c0c929cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c92aa;
P_0c0c929e: /* original 0e34, guest PC 0x0c0c929e */
if(!s->budget--) { s->failed_pc=0x0c0c929eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c92a0;
P_0c0c92a0: /* original d314, guest PC 0x0c0c92a0 */
if(!s->budget--) { s->failed_pc=0x0c0c92a0u; return 0; }
r[3]=read(ram,0x0c0c92f4u,4);
goto P_0c0c92a2;
P_0c0c92a2: /* original 430b, guest PC 0x0c0c92a2 */
if(!s->budget--) { s->failed_pc=0x0c0c92a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c92a6u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c92a6u) { target=s->pc; goto dispatch; }
goto P_0c0c92a6;
P_0c0c92a4: /* original e410, guest PC 0x0c0c92a4 */
if(!s->budget--) { s->failed_pc=0x0c0c92a4u; return 0; }
r[4]=0x00000010u;
goto P_0c0c92a6;
P_0c0c92a6: /* original e000, guest PC 0x0c0c92a6 */
if(!s->budget--) { s->failed_pc=0x0c0c92a6u; return 0; }
r[0]=0x00000000u;
goto P_0c0c92a8;
P_0c0c92a8: /* original 80eb, guest PC 0x0c0c92a8 */
if(!s->budget--) { s->failed_pc=0x0c0c92a8u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c92aa;
P_0c0c92aa: /* original 4f26, guest PC 0x0c0c92aa */
if(!s->budget--) { s->failed_pc=0x0c0c92aau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c92ac;
P_0c0c92ac: /* original d312, guest PC 0x0c0c92ac */
if(!s->budget--) { s->failed_pc=0x0c0c92acu; return 0; }
r[3]=read(ram,0x0c0c92f8u,4);
goto P_0c0c92ae;
P_0c0c92ae: /* original 432b, guest PC 0x0c0c92ae */
if(!s->budget--) { s->failed_pc=0x0c0c92aeu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: return vf3_matrix_family(0x0c09abc4u,s,ram);
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
P_0c0c92b0: /* original 6ef6, guest PC 0x0c0c92b0 */
if(!s->budget--) { s->failed_pc=0x0c0c92b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c92b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c92b2u; return 0; } return 1;
P_0c0c950c: /* original 2fe6, guest PC 0x0c0c950c */
if(!s->budget--) { s->failed_pc=0x0c0c950cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c950e;
P_0c0c950e: /* original 2fd6, guest PC 0x0c0c950e */
if(!s->budget--) { s->failed_pc=0x0c0c950eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9510;
P_0c0c9510: /* original d730, guest PC 0x0c0c9510 */
if(!s->budget--) { s->failed_pc=0x0c0c9510u; return 0; }
r[7]=read(ram,0x0c0c95d4u,4);
goto P_0c0c9512;
P_0c0c9512: /* original 9057, guest PC 0x0c0c9512 */
if(!s->budget--) { s->failed_pc=0x0c0c9512u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c4u,2);
goto P_0c0c9514;
P_0c0c9514: /* original de30, guest PC 0x0c0c9514 */
if(!s->budget--) { s->failed_pc=0x0c0c9514u; return 0; }
r[14]=read(ram,0x0c0c95d8u,4);
goto P_0c0c9516;
P_0c0c9516: /* original 067e, guest PC 0x0c0c9516 */
if(!s->budget--) { s->failed_pc=0x0c0c9516u; return 0; }
r[6]=read(ram,r[7]+r[0],4);
goto P_0c0c9518;
P_0c0c9518: /* original 9055, guest PC 0x0c0c9518 */
if(!s->budget--) { s->failed_pc=0x0c0c9518u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c6u,2);
goto P_0c0c951a;
P_0c0c951a: /* original 00ec, guest PC 0x0c0c951a */
if(!s->budget--) { s->failed_pc=0x0c0c951au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c951c;
P_0c0c951c: /* original 8802, guest PC 0x0c0c951c */
if(!s->budget--) { s->failed_pc=0x0c0c951cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c951e;
P_0c0c951e: /* original 8f23, guest PC 0x0c0c951e */
if(!s->budget--) { s->failed_pc=0x0c0c951eu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(!cond) { goto P_0c0c9568; }
goto P_0c0c9522;
P_0c0c9520: /* original 6503, guest PC 0x0c0c9520 */
if(!s->budget--) { s->failed_pc=0x0c0c9520u; return 0; }
r[5]=r[0];
goto P_0c0c9522;
P_0c0c9522: /* original 9051, guest PC 0x0c0c9522 */
if(!s->budget--) { s->failed_pc=0x0c0c9522u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c8u,2);
goto P_0c0c9524;
P_0c0c9524: /* original 9351, guest PC 0x0c0c9524 */
if(!s->budget--) { s->failed_pc=0x0c0c9524u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95cau,2);
goto P_0c0c9526;
P_0c0c9526: /* original 04ec, guest PC 0x0c0c9526 */
if(!s->budget--) { s->failed_pc=0x0c0c9526u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9528;
P_0c0c9528: /* original 2368, guest PC 0x0c0c9528 */
if(!s->budget--) { s->failed_pc=0x0c0c9528u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c952a;
P_0c0c952a: /* original 8f12, guest PC 0x0c0c952a */
if(!s->budget--) { s->failed_pc=0x0c0c952au; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c0c9552; }
goto P_0c0c952e;
P_0c0c952c: /* original 7401, guest PC 0x0c0c952c */
if(!s->budget--) { s->failed_pc=0x0c0c952cu; return 0; }
r[4]+=0x00000001u;
goto P_0c0c952e;
P_0c0c952e: /* original 924d, guest PC 0x0c0c952e */
if(!s->budget--) { s->failed_pc=0x0c0c952eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95ccu,2);
goto P_0c0c9530;
P_0c0c9530: /* original 2268, guest PC 0x0c0c9530 */
if(!s->budget--) { s->failed_pc=0x0c0c9530u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c9532;
P_0c0c9532: /* original 8b0d, guest PC 0x0c0c9532 */
if(!s->budget--) { s->failed_pc=0x0c0c9532u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9550; }
goto P_0c0c9534;
P_0c0c9534: /* original 904b, guest PC 0x0c0c9534 */
if(!s->budget--) { s->failed_pc=0x0c0c9534u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95ceu,2);
goto P_0c0c9536;
P_0c0c9536: /* original e308, guest PC 0x0c0c9536 */
if(!s->budget--) { s->failed_pc=0x0c0c9536u; return 0; }
r[3]=0x00000008u;
goto P_0c0c9538;
P_0c0c9538: /* original 0d7e, guest PC 0x0c0c9538 */
if(!s->budget--) { s->failed_pc=0x0c0c9538u; return 0; }
r[13]=read(ram,r[7]+r[0],4);
goto P_0c0c953a;
P_0c0c953a: /* original 23d8, guest PC 0x0c0c953a */
if(!s->budget--) { s->failed_pc=0x0c0c953au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c953c;
P_0c0c953c: /* original 8902, guest PC 0x0c0c953c */
if(!s->budget--) { s->failed_pc=0x0c0c953cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9544; }
goto P_0c0c953e;
P_0c0c953e: /* original e204, guest PC 0x0c0c953e */
if(!s->budget--) { s->failed_pc=0x0c0c953eu; return 0; }
r[2]=0x00000004u;
goto P_0c0c9540;
P_0c0c9540: /* original 2268, guest PC 0x0c0c9540 */
if(!s->budget--) { s->failed_pc=0x0c0c9540u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c9542;
P_0c0c9542: /* original 8b06, guest PC 0x0c0c9542 */
if(!s->budget--) { s->failed_pc=0x0c0c9542u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9552; }
goto P_0c0c9544;
P_0c0c9544: /* original d325, guest PC 0x0c0c9544 */
if(!s->budget--) { s->failed_pc=0x0c0c9544u; return 0; }
r[3]=read(ram,0x0c0c95dcu,4);
goto P_0c0c9546;
P_0c0c9546: /* original 2d38, guest PC 0x0c0c9546 */
if(!s->budget--) { s->failed_pc=0x0c0c9546u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0c9548;
P_0c0c9548: /* original 890e, guest PC 0x0c0c9548 */
if(!s->budget--) { s->failed_pc=0x0c0c9548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9568; }
goto P_0c0c954a;
P_0c0c954a: /* original d225, guest PC 0x0c0c954a */
if(!s->budget--) { s->failed_pc=0x0c0c954au; return 0; }
r[2]=read(ram,0x0c0c95e0u,4);
goto P_0c0c954c;
P_0c0c954c: /* original 2268, guest PC 0x0c0c954c */
if(!s->budget--) { s->failed_pc=0x0c0c954cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c954e;
P_0c0c954e: /* original 890b, guest PC 0x0c0c954e */
if(!s->budget--) { s->failed_pc=0x0c0c954eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9568; }
goto P_0c0c9550;
P_0c0c9550: /* original 74fe, guest PC 0x0c0c9550 */
if(!s->budget--) { s->failed_pc=0x0c0c9550u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c0c9552;
P_0c0c9552: /* original e30c, guest PC 0x0c0c9552 */
if(!s->budget--) { s->failed_pc=0x0c0c9552u; return 0; }
r[3]=0x0000000cu;
goto P_0c0c9554;
P_0c0c9554: /* original 3437, guest PC 0x0c0c9554 */
if(!s->budget--) { s->failed_pc=0x0c0c9554u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0c9556;
P_0c0c9556: /* original 8d03, guest PC 0x0c0c9556 */
if(!s->budget--) { s->failed_pc=0x0c0c9556u; return 0; }
cond=r[17]&1u;
r[6]=0xfffffff3u;
if(cond) { goto P_0c0c9560; }
goto P_0c0c955a;
P_0c0c9558: /* original e6f3, guest PC 0x0c0c9558 */
if(!s->budget--) { s->failed_pc=0x0c0c9558u; return 0; }
r[6]=0xfffffff3u;
goto P_0c0c955a;
P_0c0c955a: /* original 4411, guest PC 0x0c0c955a */
if(!s->budget--) { s->failed_pc=0x0c0c955au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c955c;
P_0c0c955c: /* original 8d01, guest PC 0x0c0c955c */
if(!s->budget--) { s->failed_pc=0x0c0c955cu; return 0; }
cond=r[17]&1u;
r[6]=0x0000000du;
if(cond) { goto P_0c0c9562; }
goto P_0c0c9560;
P_0c0c955e: /* original e60d, guest PC 0x0c0c955e */
if(!s->budget--) { s->failed_pc=0x0c0c955eu; return 0; }
r[6]=0x0000000du;
goto P_0c0c9560;
P_0c0c9560: /* original 346c, guest PC 0x0c0c9560 */
if(!s->budget--) { s->failed_pc=0x0c0c9560u; return 0; }
r[4]+=r[6];
goto P_0c0c9562;
P_0c0c9562: /* original 9031, guest PC 0x0c0c9562 */
if(!s->budget--) { s->failed_pc=0x0c0c9562u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c8u,2);
goto P_0c0c9564;
P_0c0c9564: /* original a00f, guest PC 0x0c0c9564 */
if(!s->budget--) { s->failed_pc=0x0c0c9564u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9586;
P_0c0c9566: /* original 0e44, guest PC 0x0c0c9566 */
if(!s->budget--) { s->failed_pc=0x0c0c9566u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9568;
P_0c0c9568: /* original d21e, guest PC 0x0c0c9568 */
if(!s->budget--) { s->failed_pc=0x0c0c9568u; return 0; }
r[2]=read(ram,0x0c0c95e4u,4);
goto P_0c0c956a;
P_0c0c956a: /* original 2268, guest PC 0x0c0c956a */
if(!s->budget--) { s->failed_pc=0x0c0c956au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c956c;
P_0c0c956c: /* original 8f07, guest PC 0x0c0c956c */
if(!s->budget--) { s->failed_pc=0x0c0c956cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c0c957e; }
goto P_0c0c9570;
P_0c0c956e: /* original 7501, guest PC 0x0c0c956e */
if(!s->budget--) { s->failed_pc=0x0c0c956eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c9570;
P_0c0c9570: /* original d31d, guest PC 0x0c0c9570 */
if(!s->budget--) { s->failed_pc=0x0c0c9570u; return 0; }
r[3]=read(ram,0x0c0c95e8u,4);
goto P_0c0c9572;
P_0c0c9572: /* original 2368, guest PC 0x0c0c9572 */
if(!s->budget--) { s->failed_pc=0x0c0c9572u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c9574;
P_0c0c9574: /* original 8b0e, guest PC 0x0c0c9574 */
if(!s->budget--) { s->failed_pc=0x0c0c9574u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9594; }
goto P_0c0c9576;
P_0c0c9576: /* original 922b, guest PC 0x0c0c9576 */
if(!s->budget--) { s->failed_pc=0x0c0c9576u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95d0u,2);
goto P_0c0c9578;
P_0c0c9578: /* original 2628, guest PC 0x0c0c9578 */
if(!s->budget--) { s->failed_pc=0x0c0c9578u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c957a;
P_0c0c957a: /* original 890d, guest PC 0x0c0c957a */
if(!s->budget--) { s->failed_pc=0x0c0c957au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9598; }
goto P_0c0c957c;
P_0c0c957c: /* original 75fe, guest PC 0x0c0c957c */
if(!s->budget--) { s->failed_pc=0x0c0c957cu; return 0; }
r[5]+=0xfffffffeu;
goto P_0c0c957e;
P_0c0c957e: /* original 9022, guest PC 0x0c0c957e */
if(!s->budget--) { s->failed_pc=0x0c0c957eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c6u,2);
goto P_0c0c9580;
P_0c0c9580: /* original e203, guest PC 0x0c0c9580 */
if(!s->budget--) { s->failed_pc=0x0c0c9580u; return 0; }
r[2]=0x00000003u;
goto P_0c0c9582;
P_0c0c9582: /* original 2529, guest PC 0x0c0c9582 */
if(!s->budget--) { s->failed_pc=0x0c0c9582u; return 0; }
r[5]&=r[2];
goto P_0c0c9584;
P_0c0c9584: /* original 0e54, guest PC 0x0c0c9584 */
if(!s->budget--) { s->failed_pc=0x0c0c9584u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c9586;
P_0c0c9586: /* original d019, guest PC 0x0c0c9586 */
if(!s->budget--) { s->failed_pc=0x0c0c9586u; return 0; }
r[0]=read(ram,0x0c0c95ecu,4);
goto P_0c0c9588;
P_0c0c9588: /* original e210, guest PC 0x0c0c9588 */
if(!s->budget--) { s->failed_pc=0x0c0c9588u; return 0; }
r[2]=0x00000010u;
goto P_0c0c958a;
P_0c0c958a: /* original 327c, guest PC 0x0c0c958a */
if(!s->budget--) { s->failed_pc=0x0c0c958au; return 0; }
r[2]+=r[7];
goto P_0c0c958c;
P_0c0c958c: /* original 035c, guest PC 0x0c0c958c */
if(!s->budget--) { s->failed_pc=0x0c0c958cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c958e;
P_0c0c958e: /* original 2230, guest PC 0x0c0c958e */
if(!s->budget--) { s->failed_pc=0x0c0c958eu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c0c9590;
P_0c0c9590: /* original a002, guest PC 0x0c0c9590 */
if(!s->budget--) { s->failed_pc=0x0c0c9590u; return 0; }
goto P_0c0c9598;
P_0c0c9592: /* original 0009, guest PC 0x0c0c9592 */
if(!s->budget--) { s->failed_pc=0x0c0c9592u; return 0; }
goto P_0c0c9594;
P_0c0c9594: /* original e000, guest PC 0x0c0c9594 */
if(!s->budget--) { s->failed_pc=0x0c0c9594u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9596;
P_0c0c9596: /* original 807b, guest PC 0x0c0c9596 */
if(!s->budget--) { s->failed_pc=0x0c0c9596u; return 0; }
write(ram,r[7]+11,r[0],1);
goto P_0c0c9598;
P_0c0c9598: /* original d315, guest PC 0x0c0c9598 */
if(!s->budget--) { s->failed_pc=0x0c0c9598u; return 0; }
r[3]=read(ram,0x0c0c95f0u,4);
goto P_0c0c959a;
P_0c0c959a: /* original 6df6, guest PC 0x0c0c959a */
if(!s->budget--) { s->failed_pc=0x0c0c959au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c959c;
P_0c0c959c: /* original 432b, guest PC 0x0c0c959c */
if(!s->budget--) { s->failed_pc=0x0c0c959cu; return 0; }
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
P_0c0c959e: /* original 6ef6, guest PC 0x0c0c959e */
if(!s->budget--) { s->failed_pc=0x0c0c959eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c95a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c95a0u; return 0; } return 1;
P_0c0c95f4: /* original 2fe6, guest PC 0x0c0c95f4 */
if(!s->budget--) { s->failed_pc=0x0c0c95f4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c95f6;
P_0c0c95f6: /* original e701, guest PC 0x0c0c95f6 */
if(!s->budget--) { s->failed_pc=0x0c0c95f6u; return 0; }
r[7]=0x00000001u;
goto P_0c0c95f8;
P_0c0c95f8: /* original 2fd6, guest PC 0x0c0c95f8 */
if(!s->budget--) { s->failed_pc=0x0c0c95f8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c95fa;
P_0c0c95fa: /* original e603, guest PC 0x0c0c95fa */
if(!s->budget--) { s->failed_pc=0x0c0c95fau; return 0; }
r[6]=0x00000003u;
goto P_0c0c95fc;
P_0c0c95fc: /* original 2fc6, guest PC 0x0c0c95fc */
if(!s->budget--) { s->failed_pc=0x0c0c95fcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c95fe;
P_0c0c95fe: /* original ec00, guest PC 0x0c0c95fe */
if(!s->budget--) { s->failed_pc=0x0c0c95feu; return 0; }
r[12]=0x00000000u;
goto P_0c0c9600;
P_0c0c9600: /* original 2fb6, guest PC 0x0c0c9600 */
if(!s->budget--) { s->failed_pc=0x0c0c9600u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9602;
P_0c0c9602: /* original 2fa6, guest PC 0x0c0c9602 */
if(!s->budget--) { s->failed_pc=0x0c0c9602u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9604;
P_0c0c9604: /* original 2f96, guest PC 0x0c0c9604 */
if(!s->budget--) { s->failed_pc=0x0c0c9604u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9606;
P_0c0c9606: /* original 905c, guest PC 0x0c0c9606 */
if(!s->budget--) { s->failed_pc=0x0c0c9606u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c2u,2);
goto P_0c0c9608;
P_0c0c9608: /* original dd31, guest PC 0x0c0c9608 */
if(!s->budget--) { s->failed_pc=0x0c0c9608u; return 0; }
r[13]=read(ram,0x0c0c96d0u,4);
goto P_0c0c960a;
P_0c0c960a: /* original de32, guest PC 0x0c0c960a */
if(!s->budget--) { s->failed_pc=0x0c0c960au; return 0; }
r[14]=read(ram,0x0c0c96d4u,4);
goto P_0c0c960c;
P_0c0c960c: /* original 05de, guest PC 0x0c0c960c */
if(!s->budget--) { s->failed_pc=0x0c0c960cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0c960e;
P_0c0c960e: /* original 905a, guest PC 0x0c0c960e */
if(!s->budget--) { s->failed_pc=0x0c0c960eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c6u,2);
goto P_0c0c9610;
P_0c0c9610: /* original 4f22, guest PC 0x0c0c9610 */
if(!s->budget--) { s->failed_pc=0x0c0c9610u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9612;
P_0c0c9612: /* original db32, guest PC 0x0c0c9612 */
if(!s->budget--) { s->failed_pc=0x0c0c9612u; return 0; }
r[11]=read(ram,0x0c0c96dcu,4);
goto P_0c0c9614;
P_0c0c9614: /* original d430, guest PC 0x0c0c9614 */
if(!s->budget--) { s->failed_pc=0x0c0c9614u; return 0; }
r[4]=read(ram,0x0c0c96d8u,4);
goto P_0c0c9616;
P_0c0c9616: /* original 00ec, guest PC 0x0c0c9616 */
if(!s->budget--) { s->failed_pc=0x0c0c9616u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9618;
P_0c0c9618: /* original 2b59, guest PC 0x0c0c9618 */
if(!s->budget--) { s->failed_pc=0x0c0c9618u; return 0; }
r[11]&=r[5];
goto P_0c0c961a;
P_0c0c961a: /* original 9a53, guest PC 0x0c0c961a */
if(!s->budget--) { s->failed_pc=0x0c0c961au; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c4u,2);
goto P_0c0c961c;
P_0c0c961c: /* original 7ff8, guest PC 0x0c0c961c */
if(!s->budget--) { s->failed_pc=0x0c0c961cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c961e;
P_0c0c961e: /* original 8801, guest PC 0x0c0c961e */
if(!s->budget--) { s->failed_pc=0x0c0c961eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9620;
P_0c0c9620: /* original 2459, guest PC 0x0c0c9620 */
if(!s->budget--) { s->failed_pc=0x0c0c9620u; return 0; }
r[4]&=r[5];
goto P_0c0c9622;
P_0c0c9622: /* original 8d29, guest PC 0x0c0c9622 */
if(!s->budget--) { s->failed_pc=0x0c0c9622u; return 0; }
cond=r[17]&1u;
r[10]&=r[5];
if(cond) { goto P_0c0c9678; }
goto P_0c0c9626;
P_0c0c9624: /* original 2a59, guest PC 0x0c0c9624 */
if(!s->budget--) { s->failed_pc=0x0c0c9624u; return 0; }
r[10]&=r[5];
goto P_0c0c9626;
P_0c0c9626: /* original 8802, guest PC 0x0c0c9626 */
if(!s->budget--) { s->failed_pc=0x0c0c9626u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c9628;
P_0c0c9628: /* original 8b01, guest PC 0x0c0c9628 */
if(!s->budget--) { s->failed_pc=0x0c0c9628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c962e; }
goto P_0c0c962a;
P_0c0c962a: /* original a115, guest PC 0x0c0c962a */
if(!s->budget--) { s->failed_pc=0x0c0c962au; return 0; }
goto P_0c0c9858;
P_0c0c962c: /* original 0009, guest PC 0x0c0c962c */
if(!s->budget--) { s->failed_pc=0x0c0c962cu; return 0; }
goto P_0c0c962e;
P_0c0c962e: /* original 8803, guest PC 0x0c0c962e */
if(!s->budget--) { s->failed_pc=0x0c0c962eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c9630;
P_0c0c9630: /* original 8b01, guest PC 0x0c0c9630 */
if(!s->budget--) { s->failed_pc=0x0c0c9630u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9636; }
goto P_0c0c9632;
P_0c0c9632: /* original a111, guest PC 0x0c0c9632 */
if(!s->budget--) { s->failed_pc=0x0c0c9632u; return 0; }
goto P_0c0c9858;
P_0c0c9634: /* original 0009, guest PC 0x0c0c9634 */
if(!s->budget--) { s->failed_pc=0x0c0c9634u; return 0; }
goto P_0c0c9636;
P_0c0c9636: /* original 9047, guest PC 0x0c0c9636 */
if(!s->budget--) { s->failed_pc=0x0c0c9636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c8u,2);
goto P_0c0c9638;
P_0c0c9638: /* original 2448, guest PC 0x0c0c9638 */
if(!s->budget--) { s->failed_pc=0x0c0c9638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c963a;
P_0c0c963a: /* original 8f0d, guest PC 0x0c0c963a */
if(!s->budget--) { s->failed_pc=0x0c0c963au; return 0; }
cond=r[17]&1u;
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
if(!cond) { goto P_0c0c9658; }
goto P_0c0c963e;
P_0c0c963c: /* original 05ec, guest PC 0x0c0c963c */
if(!s->budget--) { s->failed_pc=0x0c0c963cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c963e;
P_0c0c963e: /* original 2bb8, guest PC 0x0c0c963e */
if(!s->budget--) { s->failed_pc=0x0c0c963eu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c9640;
P_0c0c9640: /* original 8b04, guest PC 0x0c0c9640 */
if(!s->budget--) { s->failed_pc=0x0c0c9640u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c964c; }
goto P_0c0c9642;
P_0c0c9642: /* original 2aa8, guest PC 0x0c0c9642 */
if(!s->budget--) { s->failed_pc=0x0c0c9642u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c9644;
P_0c0c9644: /* original 8f02, guest PC 0x0c0c9644 */
if(!s->budget--) { s->failed_pc=0x0c0c9644u; return 0; }
cond=r[17]&1u;
r[7]=0xffffffffu;
if(!cond) { goto P_0c0c964c; }
goto P_0c0c9648;
P_0c0c9646: /* original e7ff, guest PC 0x0c0c9646 */
if(!s->budget--) { s->failed_pc=0x0c0c9646u; return 0; }
r[7]=0xffffffffu;
goto P_0c0c9648;
P_0c0c9648: /* original a146, guest PC 0x0c0c9648 */
if(!s->budget--) { s->failed_pc=0x0c0c9648u; return 0; }
goto P_0c0c98d8;
P_0c0c964a: /* original 0009, guest PC 0x0c0c964a */
if(!s->budget--) { s->failed_pc=0x0c0c964au; return 0; }
goto P_0c0c964c;
P_0c0c964c: /* original 903d, guest PC 0x0c0c964c */
if(!s->budget--) { s->failed_pc=0x0c0c964cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96cau,2);
goto P_0c0c964e;
P_0c0c964e: /* original 6453, guest PC 0x0c0c964e */
if(!s->budget--) { s->failed_pc=0x0c0c964eu; return 0; }
r[4]=r[5];
goto P_0c0c9650;
P_0c0c9650: /* original 347c, guest PC 0x0c0c9650 */
if(!s->budget--) { s->failed_pc=0x0c0c9650u; return 0; }
r[4]+=r[7];
goto P_0c0c9652;
P_0c0c9652: /* original 0e54, guest PC 0x0c0c9652 */
if(!s->budget--) { s->failed_pc=0x0c0c9652u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c9654;
P_0c0c9654: /* original a0bd, guest PC 0x0c0c9654 */
if(!s->budget--) { s->failed_pc=0x0c0c9654u; return 0; }
r[4]&=r[6];
goto P_0c0c97d2;
P_0c0c9656: /* original 2469, guest PC 0x0c0c9656 */
if(!s->budget--) { s->failed_pc=0x0c0c9656u; return 0; }
r[4]&=r[6];
goto P_0c0c9658;
P_0c0c9658: /* original 6053, guest PC 0x0c0c9658 */
if(!s->budget--) { s->failed_pc=0x0c0c9658u; return 0; }
r[0]=r[5];
goto P_0c0c965a;
P_0c0c965a: /* original 8800, guest PC 0x0c0c965a */
if(!s->budget--) { s->failed_pc=0x0c0c965au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c965c;
P_0c0c965c: /* original 8f02, guest PC 0x0c0c965c */
if(!s->budget--) { s->failed_pc=0x0c0c965cu; return 0; }
cond=r[17]&1u;
r[4]=0x00000061u;
if(!cond) { goto P_0c0c9664; }
goto P_0c0c9660;
P_0c0c965e: /* original e461, guest PC 0x0c0c965e */
if(!s->budget--) { s->failed_pc=0x0c0c965eu; return 0; }
r[4]=0x00000061u;
goto P_0c0c9660;
P_0c0c9660: /* original a116, guest PC 0x0c0c9660 */
if(!s->budget--) { s->failed_pc=0x0c0c9660u; return 0; }
goto P_0c0c9890;
P_0c0c9662: /* original 0009, guest PC 0x0c0c9662 */
if(!s->budget--) { s->failed_pc=0x0c0c9662u; return 0; }
goto P_0c0c9664;
P_0c0c9664: /* original 8801, guest PC 0x0c0c9664 */
if(!s->budget--) { s->failed_pc=0x0c0c9664u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9666;
P_0c0c9666: /* original 8b01, guest PC 0x0c0c9666 */
if(!s->budget--) { s->failed_pc=0x0c0c9666u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c966c; }
goto P_0c0c9668;
P_0c0c9668: /* original a128, guest PC 0x0c0c9668 */
if(!s->budget--) { s->failed_pc=0x0c0c9668u; return 0; }
goto P_0c0c98bc;
P_0c0c966a: /* original 0009, guest PC 0x0c0c966a */
if(!s->budget--) { s->failed_pc=0x0c0c966au; return 0; }
goto P_0c0c966c;
P_0c0c966c: /* original 8802, guest PC 0x0c0c966c */
if(!s->budget--) { s->failed_pc=0x0c0c966cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c966e;
P_0c0c966e: /* original 8b01, guest PC 0x0c0c966e */
if(!s->budget--) { s->failed_pc=0x0c0c966eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9674; }
goto P_0c0c9670;
P_0c0c9670: /* original a12a, guest PC 0x0c0c9670 */
if(!s->budget--) { s->failed_pc=0x0c0c9670u; return 0; }
goto P_0c0c98c8;
P_0c0c9672: /* original 0009, guest PC 0x0c0c9672 */
if(!s->budget--) { s->failed_pc=0x0c0c9672u; return 0; }
goto P_0c0c9674;
P_0c0c9674: /* original a12e, guest PC 0x0c0c9674 */
if(!s->budget--) { s->failed_pc=0x0c0c9674u; return 0; }
goto P_0c0c98d4;
P_0c0c9676: /* original 0009, guest PC 0x0c0c9676 */
if(!s->budget--) { s->failed_pc=0x0c0c9676u; return 0; }
goto P_0c0c9678;
P_0c0c9678: /* original e310, guest PC 0x0c0c9678 */
if(!s->budget--) { s->failed_pc=0x0c0c9678u; return 0; }
r[3]=0x00000010u;
goto P_0c0c967a;
P_0c0c967a: /* original 9025, guest PC 0x0c0c967a */
if(!s->budget--) { s->failed_pc=0x0c0c967au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c8u,2);
goto P_0c0c967c;
P_0c0c967c: /* original 2358, guest PC 0x0c0c967c */
if(!s->budget--) { s->failed_pc=0x0c0c967cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c967e;
P_0c0c967e: /* original 8d02, guest PC 0x0c0c967e */
if(!s->budget--) { s->failed_pc=0x0c0c967eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
if(cond) { goto P_0c0c9686; }
goto P_0c0c9682;
P_0c0c9680: /* original 04ec, guest PC 0x0c0c9680 */
if(!s->budget--) { s->failed_pc=0x0c0c9680u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9682;
P_0c0c9682: /* original a0eb, guest PC 0x0c0c9682 */
if(!s->budget--) { s->failed_pc=0x0c0c9682u; return 0; }
goto P_0c0c985c;
P_0c0c9684: /* original 0009, guest PC 0x0c0c9684 */
if(!s->budget--) { s->failed_pc=0x0c0c9684u; return 0; }
goto P_0c0c9686;
P_0c0c9686: /* original 2bb8, guest PC 0x0c0c9686 */
if(!s->budget--) { s->failed_pc=0x0c0c9686u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c9688;
P_0c0c9688: /* original 8f32, guest PC 0x0c0c9688 */
if(!s->budget--) { s->failed_pc=0x0c0c9688u; return 0; }
cond=r[17]&1u;
r[9]=r[7];
if(!cond) { goto P_0c0c96f0; }
goto P_0c0c968c;
P_0c0c968a: /* original 6973, guest PC 0x0c0c968a */
if(!s->budget--) { s->failed_pc=0x0c0c968au; return 0; }
r[9]=r[7];
goto P_0c0c968c;
P_0c0c968c: /* original 2aa8, guest PC 0x0c0c968c */
if(!s->budget--) { s->failed_pc=0x0c0c968cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c968e;
P_0c0c968e: /* original 8f2f, guest PC 0x0c0c968e */
if(!s->budget--) { s->failed_pc=0x0c0c968eu; return 0; }
cond=r[17]&1u;
r[9]=0xffffffffu;
if(!cond) { goto P_0c0c96f0; }
goto P_0c0c9692;
P_0c0c9690: /* original e9ff, guest PC 0x0c0c9690 */
if(!s->budget--) { s->failed_pc=0x0c0c9690u; return 0; }
r[9]=0xffffffffu;
goto P_0c0c9692;
P_0c0c9692: /* original 901b, guest PC 0x0c0c9692 */
if(!s->budget--) { s->failed_pc=0x0c0c9692u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96ccu,2);
goto P_0c0c9694;
P_0c0c9694: /* original d312, guest PC 0x0c0c9694 */
if(!s->budget--) { s->failed_pc=0x0c0c9694u; return 0; }
r[3]=read(ram,0x0c0c96e0u,4);
goto P_0c0c9696;
P_0c0c9696: /* original 06de, guest PC 0x0c0c9696 */
if(!s->budget--) { s->failed_pc=0x0c0c9696u; return 0; }
r[6]=read(ram,r[13]+r[0],4);
goto P_0c0c9698;
P_0c0c9698: /* original 2638, guest PC 0x0c0c9698 */
if(!s->budget--) { s->failed_pc=0x0c0c9698u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0c969a;
P_0c0c969a: /* original 8b0b, guest PC 0x0c0c969a */
if(!s->budget--) { s->failed_pc=0x0c0c969au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c96b4; }
goto P_0c0c969c;
P_0c0c969c: /* original d211, guest PC 0x0c0c969c */
if(!s->budget--) { s->failed_pc=0x0c0c969cu; return 0; }
r[2]=read(ram,0x0c0c96e4u,4);
goto P_0c0c969e;
P_0c0c969e: /* original 2258, guest PC 0x0c0c969e */
if(!s->budget--) { s->failed_pc=0x0c0c969eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c96a0;
P_0c0c96a0: /* original 8901, guest PC 0x0c0c96a0 */
if(!s->budget--) { s->failed_pc=0x0c0c96a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c96a6; }
goto P_0c0c96a2;
P_0c0c96a2: /* original a099, guest PC 0x0c0c96a2 */
if(!s->budget--) { s->failed_pc=0x0c0c96a2u; return 0; }
goto P_0c0c97d8;
P_0c0c96a4: /* original 0009, guest PC 0x0c0c96a4 */
if(!s->budget--) { s->failed_pc=0x0c0c96a4u; return 0; }
goto P_0c0c96a6;
P_0c0c96a6: /* original d310, guest PC 0x0c0c96a6 */
if(!s->budget--) { s->failed_pc=0x0c0c96a6u; return 0; }
r[3]=read(ram,0x0c0c96e8u,4);
goto P_0c0c96a8;
P_0c0c96a8: /* original 2538, guest PC 0x0c0c96a8 */
if(!s->budget--) { s->failed_pc=0x0c0c96a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c96aa;
P_0c0c96aa: /* original 8901, guest PC 0x0c0c96aa */
if(!s->budget--) { s->failed_pc=0x0c0c96aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c96b0; }
goto P_0c0c96ac;
P_0c0c96ac: /* original a08c, guest PC 0x0c0c96ac */
if(!s->budget--) { s->failed_pc=0x0c0c96acu; return 0; }
goto P_0c0c97c8;
P_0c0c96ae: /* original 0009, guest PC 0x0c0c96ae */
if(!s->budget--) { s->failed_pc=0x0c0c96aeu; return 0; }
goto P_0c0c96b0;
P_0c0c96b0: /* original a112, guest PC 0x0c0c96b0 */
if(!s->budget--) { s->failed_pc=0x0c0c96b0u; return 0; }
goto P_0c0c98d8;
P_0c0c96b2: /* original 0009, guest PC 0x0c0c96b2 */
if(!s->budget--) { s->failed_pc=0x0c0c96b2u; return 0; }
goto P_0c0c96b4;
P_0c0c96b4: /* original d10d, guest PC 0x0c0c96b4 */
if(!s->budget--) { s->failed_pc=0x0c0c96b4u; return 0; }
r[1]=read(ram,0x0c0c96ecu,4);
goto P_0c0c96b6;
P_0c0c96b6: /* original 2518, guest PC 0x0c0c96b6 */
if(!s->budget--) { s->failed_pc=0x0c0c96b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0c96b8;
P_0c0c96b8: /* original 8901, guest PC 0x0c0c96b8 */
if(!s->budget--) { s->failed_pc=0x0c0c96b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c96be; }
goto P_0c0c96ba;
P_0c0c96ba: /* original a0cf, guest PC 0x0c0c96ba */
if(!s->budget--) { s->failed_pc=0x0c0c96bau; return 0; }
goto P_0c0c985c;
P_0c0c96bc: /* original 0009, guest PC 0x0c0c96bc */
if(!s->budget--) { s->failed_pc=0x0c0c96bcu; return 0; }
goto P_0c0c96be;
P_0c0c96be: /* original a10b, guest PC 0x0c0c96be */
if(!s->budget--) { s->failed_pc=0x0c0c96beu; return 0; }
goto P_0c0c98d8;
P_0c0c96c0: /* original 0009, guest PC 0x0c0c96c0 */
if(!s->budget--) { s->failed_pc=0x0c0c96c0u; return 0; }
if(!vf3_matrix_family(0x0c0c96c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c96c2u; return 0; } return 1;
P_0c0c96f0: /* original 6043, guest PC 0x0c0c96f0 */
if(!s->budget--) { s->failed_pc=0x0c0c96f0u; return 0; }
r[0]=r[4];
goto P_0c0c96f2;
P_0c0c96f2: /* original 8800, guest PC 0x0c0c96f2 */
if(!s->budget--) { s->failed_pc=0x0c0c96f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c96f4;
P_0c0c96f4: /* original 890b, guest PC 0x0c0c96f4 */
if(!s->budget--) { s->failed_pc=0x0c0c96f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c970e; }
goto P_0c0c96f6;
P_0c0c96f6: /* original 8801, guest PC 0x0c0c96f6 */
if(!s->budget--) { s->failed_pc=0x0c0c96f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c96f8;
P_0c0c96f8: /* original 890c, guest PC 0x0c0c96f8 */
if(!s->budget--) { s->failed_pc=0x0c0c96f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9714; }
goto P_0c0c96fa;
P_0c0c96fa: /* original 8802, guest PC 0x0c0c96fa */
if(!s->budget--) { s->failed_pc=0x0c0c96fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c96fc;
P_0c0c96fc: /* original 890d, guest PC 0x0c0c96fc */
if(!s->budget--) { s->failed_pc=0x0c0c96fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c971a; }
goto P_0c0c96fe;
P_0c0c96fe: /* original 8803, guest PC 0x0c0c96fe */
if(!s->budget--) { s->failed_pc=0x0c0c96feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c9700;
P_0c0c9700: /* original 890e, guest PC 0x0c0c9700 */
if(!s->budget--) { s->failed_pc=0x0c0c9700u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9720; }
goto P_0c0c9702;
P_0c0c9702: /* original 8804, guest PC 0x0c0c9702 */
if(!s->budget--) { s->failed_pc=0x0c0c9702u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c9704;
P_0c0c9704: /* original 890f, guest PC 0x0c0c9704 */
if(!s->budget--) { s->failed_pc=0x0c0c9704u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9726; }
goto P_0c0c9706;
P_0c0c9706: /* original 8805, guest PC 0x0c0c9706 */
if(!s->budget--) { s->failed_pc=0x0c0c9706u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c9708;
P_0c0c9708: /* original 8910, guest PC 0x0c0c9708 */
if(!s->budget--) { s->failed_pc=0x0c0c9708u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c972c; }
goto P_0c0c970a;
P_0c0c970a: /* original a011, guest PC 0x0c0c970a */
if(!s->budget--) { s->failed_pc=0x0c0c970au; return 0; }
goto P_0c0c9730;
P_0c0c970c: /* original 0009, guest PC 0x0c0c970c */
if(!s->budget--) { s->failed_pc=0x0c0c970cu; return 0; }
goto P_0c0c970e;
P_0c0c970e: /* original 9045, guest PC 0x0c0c970e */
if(!s->budget--) { s->failed_pc=0x0c0c970eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979cu,2);
goto P_0c0c9710;
P_0c0c9710: /* original a00d, guest PC 0x0c0c9710 */
if(!s->budget--) { s->failed_pc=0x0c0c9710u; return 0; }
goto P_0c0c972e;
P_0c0c9712: /* original 0009, guest PC 0x0c0c9712 */
if(!s->budget--) { s->failed_pc=0x0c0c9712u; return 0; }
goto P_0c0c9714;
P_0c0c9714: /* original 9043, guest PC 0x0c0c9714 */
if(!s->budget--) { s->failed_pc=0x0c0c9714u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979eu,2);
goto P_0c0c9716;
P_0c0c9716: /* original a00a, guest PC 0x0c0c9716 */
if(!s->budget--) { s->failed_pc=0x0c0c9716u; return 0; }
goto P_0c0c972e;
P_0c0c9718: /* original 0009, guest PC 0x0c0c9718 */
if(!s->budget--) { s->failed_pc=0x0c0c9718u; return 0; }
goto P_0c0c971a;
P_0c0c971a: /* original 9041, guest PC 0x0c0c971a */
if(!s->budget--) { s->failed_pc=0x0c0c971au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c97a0u,2);
goto P_0c0c971c;
P_0c0c971c: /* original a007, guest PC 0x0c0c971c */
if(!s->budget--) { s->failed_pc=0x0c0c971cu; return 0; }
goto P_0c0c972e;
P_0c0c971e: /* original 0009, guest PC 0x0c0c971e */
if(!s->budget--) { s->failed_pc=0x0c0c971eu; return 0; }
goto P_0c0c9720;
P_0c0c9720: /* original 903f, guest PC 0x0c0c9720 */
if(!s->budget--) { s->failed_pc=0x0c0c9720u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c97a2u,2);
goto P_0c0c9722;
P_0c0c9722: /* original a004, guest PC 0x0c0c9722 */
if(!s->budget--) { s->failed_pc=0x0c0c9722u; return 0; }
goto P_0c0c972e;
P_0c0c9724: /* original 0009, guest PC 0x0c0c9724 */
if(!s->budget--) { s->failed_pc=0x0c0c9724u; return 0; }
goto P_0c0c9726;
P_0c0c9726: /* original 903d, guest PC 0x0c0c9726 */
if(!s->budget--) { s->failed_pc=0x0c0c9726u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c97a4u,2);
goto P_0c0c9728;
P_0c0c9728: /* original a001, guest PC 0x0c0c9728 */
if(!s->budget--) { s->failed_pc=0x0c0c9728u; return 0; }
goto P_0c0c972e;
P_0c0c972a: /* original 0009, guest PC 0x0c0c972a */
if(!s->budget--) { s->failed_pc=0x0c0c972au; return 0; }
goto P_0c0c972c;
P_0c0c972c: /* original 903b, guest PC 0x0c0c972c */
if(!s->budget--) { s->failed_pc=0x0c0c972cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c97a6u,2);
goto P_0c0c972e;
P_0c0c972e: /* original 05ec, guest PC 0x0c0c972e */
if(!s->budget--) { s->failed_pc=0x0c0c972eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9730;
P_0c0c9730: /* original 6d43, guest PC 0x0c0c9730 */
if(!s->budget--) { s->failed_pc=0x0c0c9730u; return 0; }
r[13]=r[4];
goto P_0c0c9732;
P_0c0c9732: /* original 4d08, guest PC 0x0c0c9732 */
if(!s->budget--) { s->failed_pc=0x0c0c9732u; return 0; }
r[13]<<=2;
goto P_0c0c9734;
P_0c0c9734: /* original 2fd2, guest PC 0x0c0c9734 */
if(!s->budget--) { s->failed_pc=0x0c0c9734u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0c9736;
P_0c0c9736: /* original d01c, guest PC 0x0c0c9736 */
if(!s->budget--) { s->failed_pc=0x0c0c9736u; return 0; }
r[0]=read(ram,0x0c0c97a8u,4);
goto P_0c0c9738;
P_0c0c9738: /* original 0dde, guest PC 0x0c0c9738 */
if(!s->budget--) { s->failed_pc=0x0c0c9738u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c0c973a;
P_0c0c973a: /* original 6043, guest PC 0x0c0c973a */
if(!s->budget--) { s->failed_pc=0x0c0c973au; return 0; }
r[0]=r[4];
goto P_0c0c973c;
P_0c0c973c: /* original 8802, guest PC 0x0c0c973c */
if(!s->budget--) { s->failed_pc=0x0c0c973cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c973e;
P_0c0c973e: /* original 8b0c, guest PC 0x0c0c973e */
if(!s->budget--) { s->failed_pc=0x0c0c973eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c975a; }
goto P_0c0c9740;
P_0c0c9740: /* original 902d, guest PC 0x0c0c9740 */
if(!s->budget--) { s->failed_pc=0x0c0c9740u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979eu,2);
goto P_0c0c9742;
P_0c0c9742: /* original 00ec, guest PC 0x0c0c9742 */
if(!s->budget--) { s->failed_pc=0x0c0c9742u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9744;
P_0c0c9744: /* original 80f4, guest PC 0x0c0c9744 */
if(!s->budget--) { s->failed_pc=0x0c0c9744u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c0c9746;
P_0c0c9746: /* original 07dc, guest PC 0x0c0c9746 */
if(!s->budget--) { s->failed_pc=0x0c0c9746u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c9748;
P_0c0c9748: /* original 84f4, guest PC 0x0c0c9748 */
if(!s->budget--) { s->failed_pc=0x0c0c9748u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0c974a;
P_0c0c974a: /* original 8802, guest PC 0x0c0c974a */
if(!s->budget--) { s->failed_pc=0x0c0c974au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c974c;
P_0c0c974c: /* original 8b06, guest PC 0x0c0c974c */
if(!s->budget--) { s->failed_pc=0x0c0c974cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c975c; }
goto P_0c0c974e;
P_0c0c974e: /* original 9025, guest PC 0x0c0c974e */
if(!s->budget--) { s->failed_pc=0x0c0c974eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979cu,2);
goto P_0c0c9750;
P_0c0c9750: /* original 03ec, guest PC 0x0c0c9750 */
if(!s->budget--) { s->failed_pc=0x0c0c9750u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9752;
P_0c0c9752: /* original 2368, guest PC 0x0c0c9752 */
if(!s->budget--) { s->failed_pc=0x0c0c9752u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c9754;
P_0c0c9754: /* original 8b02, guest PC 0x0c0c9754 */
if(!s->budget--) { s->failed_pc=0x0c0c9754u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c975c; }
goto P_0c0c9756;
P_0c0c9756: /* original a001, guest PC 0x0c0c9756 */
if(!s->budget--) { s->failed_pc=0x0c0c9756u; return 0; }
r[7]+=0x00000001u;
goto P_0c0c975c;
P_0c0c9758: /* original 7701, guest PC 0x0c0c9758 */
if(!s->budget--) { s->failed_pc=0x0c0c9758u; return 0; }
r[7]+=0x00000001u;
goto P_0c0c975a;
P_0c0c975a: /* original 67d0, guest PC 0x0c0c975a */
if(!s->budget--) { s->failed_pc=0x0c0c975au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[7]=tmp;
goto P_0c0c975c;
P_0c0c975c: /* original d013, guest PC 0x0c0c975c */
if(!s->budget--) { s->failed_pc=0x0c0c975cu; return 0; }
r[0]=read(ram,0x0c0c97acu,4);
goto P_0c0c975e;
P_0c0c975e: /* original 359c, guest PC 0x0c0c975e */
if(!s->budget--) { s->failed_pc=0x0c0c975eu; return 0; }
r[5]+=r[9];
goto P_0c0c9760;
P_0c0c9760: /* original 62f2, guest PC 0x0c0c9760 */
if(!s->budget--) { s->failed_pc=0x0c0c9760u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c9762;
P_0c0c9762: /* original 3577, guest PC 0x0c0c9762 */
if(!s->budget--) { s->failed_pc=0x0c0c9762u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[7])!=0);
goto P_0c0c9764;
P_0c0c9764: /* original 062e, guest PC 0x0c0c9764 */
if(!s->budget--) { s->failed_pc=0x0c0c9764u; return 0; }
r[6]=read(ram,r[2]+r[0],4);
goto P_0c0c9766;
P_0c0c9766: /* original 8f01, guest PC 0x0c0c9766 */
if(!s->budget--) { s->failed_pc=0x0c0c9766u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
if(!cond) { goto P_0c0c976c; }
goto P_0c0c976a;
P_0c0c9768: /* original 6660, guest PC 0x0c0c9768 */
if(!s->budget--) { s->failed_pc=0x0c0c9768u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c0c976a;
P_0c0c976a: /* original 6563, guest PC 0x0c0c976a */
if(!s->budget--) { s->failed_pc=0x0c0c976au; return 0; }
r[5]=r[6];
goto P_0c0c976c;
P_0c0c976c: /* original 3563, guest PC 0x0c0c976c */
if(!s->budget--) { s->failed_pc=0x0c0c976cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0c976e;
P_0c0c976e: /* original 8d01, guest PC 0x0c0c976e */
if(!s->budget--) { s->failed_pc=0x0c0c976eu; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c0c9774; }
goto P_0c0c9772;
P_0c0c9770: /* original 6043, guest PC 0x0c0c9770 */
if(!s->budget--) { s->failed_pc=0x0c0c9770u; return 0; }
r[0]=r[4];
goto P_0c0c9772;
P_0c0c9772: /* original 6573, guest PC 0x0c0c9772 */
if(!s->budget--) { s->failed_pc=0x0c0c9772u; return 0; }
r[5]=r[7];
goto P_0c0c9774;
P_0c0c9774: /* original 8800, guest PC 0x0c0c9774 */
if(!s->budget--) { s->failed_pc=0x0c0c9774u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c9776;
P_0c0c9776: /* original 890b, guest PC 0x0c0c9776 */
if(!s->budget--) { s->failed_pc=0x0c0c9776u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9790; }
goto P_0c0c9778;
P_0c0c9778: /* original 8801, guest PC 0x0c0c9778 */
if(!s->budget--) { s->failed_pc=0x0c0c9778u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c977a;
P_0c0c977a: /* original 890c, guest PC 0x0c0c977a */
if(!s->budget--) { s->failed_pc=0x0c0c977au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9796; }
goto P_0c0c977c;
P_0c0c977c: /* original 8802, guest PC 0x0c0c977c */
if(!s->budget--) { s->failed_pc=0x0c0c977cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c977e;
P_0c0c977e: /* original 8917, guest PC 0x0c0c977e */
if(!s->budget--) { s->failed_pc=0x0c0c977eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c97b0; }
goto P_0c0c9780;
P_0c0c9780: /* original 8803, guest PC 0x0c0c9780 */
if(!s->budget--) { s->failed_pc=0x0c0c9780u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c9782;
P_0c0c9782: /* original 8918, guest PC 0x0c0c9782 */
if(!s->budget--) { s->failed_pc=0x0c0c9782u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c97b6; }
goto P_0c0c9784;
P_0c0c9784: /* original 8804, guest PC 0x0c0c9784 */
if(!s->budget--) { s->failed_pc=0x0c0c9784u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c9786;
P_0c0c9786: /* original 8919, guest PC 0x0c0c9786 */
if(!s->budget--) { s->failed_pc=0x0c0c9786u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c97bc; }
goto P_0c0c9788;
P_0c0c9788: /* original 8805, guest PC 0x0c0c9788 */
if(!s->budget--) { s->failed_pc=0x0c0c9788u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c978a;
P_0c0c978a: /* original 891a, guest PC 0x0c0c978a */
if(!s->budget--) { s->failed_pc=0x0c0c978au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c97c2; }
goto P_0c0c978c;
P_0c0c978c: /* original a0a4, guest PC 0x0c0c978c */
if(!s->budget--) { s->failed_pc=0x0c0c978cu; return 0; }
goto P_0c0c98d8;
P_0c0c978e: /* original 0009, guest PC 0x0c0c978e */
if(!s->budget--) { s->failed_pc=0x0c0c978eu; return 0; }
goto P_0c0c9790;
P_0c0c9790: /* original 9004, guest PC 0x0c0c9790 */
if(!s->budget--) { s->failed_pc=0x0c0c9790u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979cu,2);
goto P_0c0c9792;
P_0c0c9792: /* original a017, guest PC 0x0c0c9792 */
if(!s->budget--) { s->failed_pc=0x0c0c9792u; return 0; }
goto P_0c0c97c4;
P_0c0c9794: /* original 0009, guest PC 0x0c0c9794 */
if(!s->budget--) { s->failed_pc=0x0c0c9794u; return 0; }
goto P_0c0c9796;
P_0c0c9796: /* original 9002, guest PC 0x0c0c9796 */
if(!s->budget--) { s->failed_pc=0x0c0c9796u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979eu,2);
goto P_0c0c9798;
P_0c0c9798: /* original a014, guest PC 0x0c0c9798 */
if(!s->budget--) { s->failed_pc=0x0c0c9798u; return 0; }
goto P_0c0c97c4;
P_0c0c979a: /* original 0009, guest PC 0x0c0c979a */
if(!s->budget--) { s->failed_pc=0x0c0c979au; return 0; }
if(!vf3_matrix_family(0x0c0c979cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c979cu; return 0; } return 1;
P_0c0c97b0: /* original 9061, guest PC 0x0c0c97b0 */
if(!s->budget--) { s->failed_pc=0x0c0c97b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9876u,2);
goto P_0c0c97b2;
P_0c0c97b2: /* original a007, guest PC 0x0c0c97b2 */
if(!s->budget--) { s->failed_pc=0x0c0c97b2u; return 0; }
goto P_0c0c97c4;
P_0c0c97b4: /* original 0009, guest PC 0x0c0c97b4 */
if(!s->budget--) { s->failed_pc=0x0c0c97b4u; return 0; }
goto P_0c0c97b6;
P_0c0c97b6: /* original 905f, guest PC 0x0c0c97b6 */
if(!s->budget--) { s->failed_pc=0x0c0c97b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9878u,2);
goto P_0c0c97b8;
P_0c0c97b8: /* original a004, guest PC 0x0c0c97b8 */
if(!s->budget--) { s->failed_pc=0x0c0c97b8u; return 0; }
goto P_0c0c97c4;
P_0c0c97ba: /* original 0009, guest PC 0x0c0c97ba */
if(!s->budget--) { s->failed_pc=0x0c0c97bau; return 0; }
goto P_0c0c97bc;
P_0c0c97bc: /* original 905d, guest PC 0x0c0c97bc */
if(!s->budget--) { s->failed_pc=0x0c0c97bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987au,2);
goto P_0c0c97be;
P_0c0c97be: /* original a001, guest PC 0x0c0c97be */
if(!s->budget--) { s->failed_pc=0x0c0c97beu; return 0; }
goto P_0c0c97c4;
P_0c0c97c0: /* original 0009, guest PC 0x0c0c97c0 */
if(!s->budget--) { s->failed_pc=0x0c0c97c0u; return 0; }
goto P_0c0c97c2;
P_0c0c97c2: /* original 905b, guest PC 0x0c0c97c2 */
if(!s->budget--) { s->failed_pc=0x0c0c97c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987cu,2);
goto P_0c0c97c4;
P_0c0c97c4: /* original a088, guest PC 0x0c0c97c4 */
if(!s->budget--) { s->failed_pc=0x0c0c97c4u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c98d8;
P_0c0c97c6: /* original 0e54, guest PC 0x0c0c97c6 */
if(!s->budget--) { s->failed_pc=0x0c0c97c6u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c97c8;
P_0c0c97c8: /* original 9059, guest PC 0x0c0c97c8 */
if(!s->budget--) { s->failed_pc=0x0c0c97c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987eu,2);
goto P_0c0c97ca;
P_0c0c97ca: /* original 4415, guest PC 0x0c0c97ca */
if(!s->budget--) { s->failed_pc=0x0c0c97cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c97cc;
P_0c0c97cc: /* original 8f46, guest PC 0x0c0c97cc */
if(!s->budget--) { s->failed_pc=0x0c0c97ccu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],1);
if(!cond) { goto P_0c0c985c; }
goto P_0c0c97d0;
P_0c0c97ce: /* original 0e44, guest PC 0x0c0c97ce */
if(!s->budget--) { s->failed_pc=0x0c0c97ceu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c97d0;
P_0c0c97d0: /* original 74ff, guest PC 0x0c0c97d0 */
if(!s->budget--) { s->failed_pc=0x0c0c97d0u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c97d2;
P_0c0c97d2: /* original 9055, guest PC 0x0c0c97d2 */
if(!s->budget--) { s->failed_pc=0x0c0c97d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9880u,2);
goto P_0c0c97d4;
P_0c0c97d4: /* original a080, guest PC 0x0c0c97d4 */
if(!s->budget--) { s->failed_pc=0x0c0c97d4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c98d8;
P_0c0c97d6: /* original 0e44, guest PC 0x0c0c97d6 */
if(!s->budget--) { s->failed_pc=0x0c0c97d6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c97d8;
P_0c0c97d8: /* original e305, guest PC 0x0c0c97d8 */
if(!s->budget--) { s->failed_pc=0x0c0c97d8u; return 0; }
r[3]=0x00000005u;
goto P_0c0c97da;
P_0c0c97da: /* original 9050, guest PC 0x0c0c97da */
if(!s->budget--) { s->failed_pc=0x0c0c97dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987eu,2);
goto P_0c0c97dc;
P_0c0c97dc: /* original 3433, guest PC 0x0c0c97dc */
if(!s->budget--) { s->failed_pc=0x0c0c97dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c97de;
P_0c0c97de: /* original 8d29, guest PC 0x0c0c97de */
if(!s->budget--) { s->failed_pc=0x0c0c97deu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],1);
if(cond) { goto P_0c0c9834; }
goto P_0c0c97e2;
P_0c0c97e0: /* original 0e44, guest PC 0x0c0c97e0 */
if(!s->budget--) { s->failed_pc=0x0c0c97e0u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c97e2;
P_0c0c97e2: /* original 904d, guest PC 0x0c0c97e2 */
if(!s->budget--) { s->failed_pc=0x0c0c97e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9880u,2);
goto P_0c0c97e4;
P_0c0c97e4: /* original 7401, guest PC 0x0c0c97e4 */
if(!s->budget--) { s->failed_pc=0x0c0c97e4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c97e6;
P_0c0c97e6: /* original 6543, guest PC 0x0c0c97e6 */
if(!s->budget--) { s->failed_pc=0x0c0c97e6u; return 0; }
r[5]=r[4];
goto P_0c0c97e8;
P_0c0c97e8: /* original 4508, guest PC 0x0c0c97e8 */
if(!s->budget--) { s->failed_pc=0x0c0c97e8u; return 0; }
r[5]<<=2;
goto P_0c0c97ea;
P_0c0c97ea: /* original 0e44, guest PC 0x0c0c97ea */
if(!s->budget--) { s->failed_pc=0x0c0c97eau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c97ec;
P_0c0c97ec: /* original d026, guest PC 0x0c0c97ec */
if(!s->budget--) { s->failed_pc=0x0c0c97ecu; return 0; }
r[0]=read(ram,0x0c0c9888u,4);
goto P_0c0c97ee;
P_0c0c97ee: /* original 055e, guest PC 0x0c0c97ee */
if(!s->budget--) { s->failed_pc=0x0c0c97eeu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0c97f0;
P_0c0c97f0: /* original 6043, guest PC 0x0c0c97f0 */
if(!s->budget--) { s->failed_pc=0x0c0c97f0u; return 0; }
r[0]=r[4];
goto P_0c0c97f2;
P_0c0c97f2: /* original 8800, guest PC 0x0c0c97f2 */
if(!s->budget--) { s->failed_pc=0x0c0c97f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c97f4;
P_0c0c97f4: /* original 8d0c, guest PC 0x0c0c97f4 */
if(!s->budget--) { s->failed_pc=0x0c0c97f4u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
if(cond) { goto P_0c0c9810; }
goto P_0c0c97f8;
P_0c0c97f6: /* original 6550, guest PC 0x0c0c97f6 */
if(!s->budget--) { s->failed_pc=0x0c0c97f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c0c97f8;
P_0c0c97f8: /* original 8801, guest PC 0x0c0c97f8 */
if(!s->budget--) { s->failed_pc=0x0c0c97f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c97fa;
P_0c0c97fa: /* original 890c, guest PC 0x0c0c97fa */
if(!s->budget--) { s->failed_pc=0x0c0c97fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9816; }
goto P_0c0c97fc;
P_0c0c97fc: /* original 8802, guest PC 0x0c0c97fc */
if(!s->budget--) { s->failed_pc=0x0c0c97fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c97fe;
P_0c0c97fe: /* original 890d, guest PC 0x0c0c97fe */
if(!s->budget--) { s->failed_pc=0x0c0c97feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c981c; }
goto P_0c0c9800;
P_0c0c9800: /* original 8803, guest PC 0x0c0c9800 */
if(!s->budget--) { s->failed_pc=0x0c0c9800u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c9802;
P_0c0c9802: /* original 890e, guest PC 0x0c0c9802 */
if(!s->budget--) { s->failed_pc=0x0c0c9802u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9822; }
goto P_0c0c9804;
P_0c0c9804: /* original 8804, guest PC 0x0c0c9804 */
if(!s->budget--) { s->failed_pc=0x0c0c9804u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c9806;
P_0c0c9806: /* original 890f, guest PC 0x0c0c9806 */
if(!s->budget--) { s->failed_pc=0x0c0c9806u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9828; }
goto P_0c0c9808;
P_0c0c9808: /* original 8805, guest PC 0x0c0c9808 */
if(!s->budget--) { s->failed_pc=0x0c0c9808u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c980a;
P_0c0c980a: /* original 8910, guest PC 0x0c0c980a */
if(!s->budget--) { s->failed_pc=0x0c0c980au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c982e; }
goto P_0c0c980c;
P_0c0c980c: /* original a064, guest PC 0x0c0c980c */
if(!s->budget--) { s->failed_pc=0x0c0c980cu; return 0; }
goto P_0c0c98d8;
P_0c0c980e: /* original 0009, guest PC 0x0c0c980e */
if(!s->budget--) { s->failed_pc=0x0c0c980eu; return 0; }
goto P_0c0c9810;
P_0c0c9810: /* original 9037, guest PC 0x0c0c9810 */
if(!s->budget--) { s->failed_pc=0x0c0c9810u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9882u,2);
goto P_0c0c9812;
P_0c0c9812: /* original a00d, guest PC 0x0c0c9812 */
if(!s->budget--) { s->failed_pc=0x0c0c9812u; return 0; }
goto P_0c0c9830;
P_0c0c9814: /* original 0009, guest PC 0x0c0c9814 */
if(!s->budget--) { s->failed_pc=0x0c0c9814u; return 0; }
goto P_0c0c9816;
P_0c0c9816: /* original 9035, guest PC 0x0c0c9816 */
if(!s->budget--) { s->failed_pc=0x0c0c9816u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9884u,2);
goto P_0c0c9818;
P_0c0c9818: /* original a00a, guest PC 0x0c0c9818 */
if(!s->budget--) { s->failed_pc=0x0c0c9818u; return 0; }
goto P_0c0c9830;
P_0c0c981a: /* original 0009, guest PC 0x0c0c981a */
if(!s->budget--) { s->failed_pc=0x0c0c981au; return 0; }
goto P_0c0c981c;
P_0c0c981c: /* original 902b, guest PC 0x0c0c981c */
if(!s->budget--) { s->failed_pc=0x0c0c981cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9876u,2);
goto P_0c0c981e;
P_0c0c981e: /* original a007, guest PC 0x0c0c981e */
if(!s->budget--) { s->failed_pc=0x0c0c981eu; return 0; }
goto P_0c0c9830;
P_0c0c9820: /* original 0009, guest PC 0x0c0c9820 */
if(!s->budget--) { s->failed_pc=0x0c0c9820u; return 0; }
goto P_0c0c9822;
P_0c0c9822: /* original 9029, guest PC 0x0c0c9822 */
if(!s->budget--) { s->failed_pc=0x0c0c9822u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9878u,2);
goto P_0c0c9824;
P_0c0c9824: /* original a004, guest PC 0x0c0c9824 */
if(!s->budget--) { s->failed_pc=0x0c0c9824u; return 0; }
goto P_0c0c9830;
P_0c0c9826: /* original 0009, guest PC 0x0c0c9826 */
if(!s->budget--) { s->failed_pc=0x0c0c9826u; return 0; }
goto P_0c0c9828;
P_0c0c9828: /* original 9027, guest PC 0x0c0c9828 */
if(!s->budget--) { s->failed_pc=0x0c0c9828u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987au,2);
goto P_0c0c982a;
P_0c0c982a: /* original a001, guest PC 0x0c0c982a */
if(!s->budget--) { s->failed_pc=0x0c0c982au; return 0; }
goto P_0c0c9830;
P_0c0c982c: /* original 0009, guest PC 0x0c0c982c */
if(!s->budget--) { s->failed_pc=0x0c0c982cu; return 0; }
goto P_0c0c982e;
P_0c0c982e: /* original 9025, guest PC 0x0c0c982e */
if(!s->budget--) { s->failed_pc=0x0c0c982eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987cu,2);
goto P_0c0c9830;
P_0c0c9830: /* original a052, guest PC 0x0c0c9830 */
if(!s->budget--) { s->failed_pc=0x0c0c9830u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c98d8;
P_0c0c9832: /* original 0e54, guest PC 0x0c0c9832 */
if(!s->budget--) { s->failed_pc=0x0c0c9832u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c9834;
P_0c0c9834: /* original 9022, guest PC 0x0c0c9834 */
if(!s->budget--) { s->failed_pc=0x0c0c9834u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987cu,2);
goto P_0c0c9836;
P_0c0c9836: /* original 03ec, guest PC 0x0c0c9836 */
if(!s->budget--) { s->failed_pc=0x0c0c9836u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9838;
P_0c0c9838: /* original 70ff, guest PC 0x0c0c9838 */
if(!s->budget--) { s->failed_pc=0x0c0c9838u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c983a;
P_0c0c983a: /* original 2f36, guest PC 0x0c0c983a */
if(!s->budget--) { s->failed_pc=0x0c0c983au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c983c;
P_0c0c983c: /* original 02ec, guest PC 0x0c0c983c */
if(!s->budget--) { s->failed_pc=0x0c0c983cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c983e;
P_0c0c983e: /* original 70ff, guest PC 0x0c0c983e */
if(!s->budget--) { s->failed_pc=0x0c0c983eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9840;
P_0c0c9840: /* original 2f26, guest PC 0x0c0c9840 */
if(!s->budget--) { s->failed_pc=0x0c0c9840u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9842;
P_0c0c9842: /* original 07ec, guest PC 0x0c0c9842 */
if(!s->budget--) { s->failed_pc=0x0c0c9842u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9844;
P_0c0c9844: /* original 70ff, guest PC 0x0c0c9844 */
if(!s->budget--) { s->failed_pc=0x0c0c9844u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9846;
P_0c0c9846: /* original 06ec, guest PC 0x0c0c9846 */
if(!s->budget--) { s->failed_pc=0x0c0c9846u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9848;
P_0c0c9848: /* original 70ff, guest PC 0x0c0c9848 */
if(!s->budget--) { s->failed_pc=0x0c0c9848u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c984a;
P_0c0c984a: /* original d310, guest PC 0x0c0c984a */
if(!s->budget--) { s->failed_pc=0x0c0c984au; return 0; }
r[3]=read(ram,0x0c0c988cu,4);
goto P_0c0c984c;
P_0c0c984c: /* original 05ec, guest PC 0x0c0c984c */
if(!s->budget--) { s->failed_pc=0x0c0c984cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c984e;
P_0c0c984e: /* original 70ff, guest PC 0x0c0c984e */
if(!s->budget--) { s->failed_pc=0x0c0c984eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9850;
P_0c0c9850: /* original 430b, guest PC 0x0c0c9850 */
if(!s->budget--) { s->failed_pc=0x0c0c9850u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9854u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9854u) { target=s->pc; goto dispatch; }
goto P_0c0c9854;
P_0c0c9852: /* original 04ec, guest PC 0x0c0c9852 */
if(!s->budget--) { s->failed_pc=0x0c0c9852u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9854;
P_0c0c9854: /* original a002, guest PC 0x0c0c9854 */
if(!s->budget--) { s->failed_pc=0x0c0c9854u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c985c;
P_0c0c9856: /* original 7f08, guest PC 0x0c0c9856 */
if(!s->budget--) { s->failed_pc=0x0c0c9856u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c9858;
P_0c0c9858: /* original 2448, guest PC 0x0c0c9858 */
if(!s->budget--) { s->failed_pc=0x0c0c9858u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c985a;
P_0c0c985a: /* original 893d, guest PC 0x0c0c985a */
if(!s->budget--) { s->failed_pc=0x0c0c985au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c98d8; }
goto P_0c0c985c;
P_0c0c985c: /* original 9013, guest PC 0x0c0c985c */
if(!s->budget--) { s->failed_pc=0x0c0c985cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9886u,2);
goto P_0c0c985e;
P_0c0c985e: /* original e35d, guest PC 0x0c0c985e */
if(!s->budget--) { s->failed_pc=0x0c0c985eu; return 0; }
r[3]=0x0000005du;
goto P_0c0c9860;
P_0c0c9860: /* original 04ec, guest PC 0x0c0c9860 */
if(!s->budget--) { s->failed_pc=0x0c0c9860u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9862;
P_0c0c9862: /* original 7002, guest PC 0x0c0c9862 */
if(!s->budget--) { s->failed_pc=0x0c0c9862u; return 0; }
r[0]+=0x00000002u;
goto P_0c0c9864;
P_0c0c9864: /* original 74ff, guest PC 0x0c0c9864 */
if(!s->budget--) { s->failed_pc=0x0c0c9864u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c9866;
P_0c0c9866: /* original 0e44, guest PC 0x0c0c9866 */
if(!s->budget--) { s->failed_pc=0x0c0c9866u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9868;
P_0c0c9868: /* original 7001, guest PC 0x0c0c9868 */
if(!s->budget--) { s->failed_pc=0x0c0c9868u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c986a;
P_0c0c986a: /* original 0e44, guest PC 0x0c0c986a */
if(!s->budget--) { s->failed_pc=0x0c0c986au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c986c;
P_0c0c986c: /* original 70fd, guest PC 0x0c0c986c */
if(!s->budget--) { s->failed_pc=0x0c0c986cu; return 0; }
r[0]+=0xfffffffdu;
goto P_0c0c986e;
P_0c0c986e: /* original 0ec4, guest PC 0x0c0c986e */
if(!s->budget--) { s->failed_pc=0x0c0c986eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c9870;
P_0c0c9870: /* original e010, guest PC 0x0c0c9870 */
if(!s->budget--) { s->failed_pc=0x0c0c9870u; return 0; }
r[0]=0x00000010u;
goto P_0c0c9872;
P_0c0c9872: /* original a031, guest PC 0x0c0c9872 */
if(!s->budget--) { s->failed_pc=0x0c0c9872u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98d8;
P_0c0c9874: /* original 0d34, guest PC 0x0c0c9874 */
if(!s->budget--) { s->failed_pc=0x0c0c9874u; return 0; }
write(ram,r[13]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c0c9876u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9876u; return 0; } return 1;
P_0c0c9890: /* original 907d, guest PC 0x0c0c9890 */
if(!s->budget--) { s->failed_pc=0x0c0c9890u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c998eu,2);
goto P_0c0c9892;
P_0c0c9892: /* original e35f, guest PC 0x0c0c9892 */
if(!s->budget--) { s->failed_pc=0x0c0c9892u; return 0; }
r[3]=0x0000005fu;
goto P_0c0c9894;
P_0c0c9894: /* original 0e44, guest PC 0x0c0c9894 */
if(!s->budget--) { s->failed_pc=0x0c0c9894u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9896;
P_0c0c9896: /* original 7001, guest PC 0x0c0c9896 */
if(!s->budget--) { s->failed_pc=0x0c0c9896u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c9898;
P_0c0c9898: /* original 0e74, guest PC 0x0c0c9898 */
if(!s->budget--) { s->failed_pc=0x0c0c9898u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0c989a;
P_0c0c989a: /* original 7001, guest PC 0x0c0c989a */
if(!s->budget--) { s->failed_pc=0x0c0c989au; return 0; }
r[0]+=0x00000001u;
goto P_0c0c989c;
P_0c0c989c: /* original 0e74, guest PC 0x0c0c989c */
if(!s->budget--) { s->failed_pc=0x0c0c989cu; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0c989e;
P_0c0c989e: /* original 7001, guest PC 0x0c0c989e */
if(!s->budget--) { s->failed_pc=0x0c0c989eu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c98a0;
P_0c0c98a0: /* original 0ec4, guest PC 0x0c0c98a0 */
if(!s->budget--) { s->failed_pc=0x0c0c98a0u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98a2;
P_0c0c98a2: /* original 7001, guest PC 0x0c0c98a2 */
if(!s->budget--) { s->failed_pc=0x0c0c98a2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c98a4;
P_0c0c98a4: /* original 0ec4, guest PC 0x0c0c98a4 */
if(!s->budget--) { s->failed_pc=0x0c0c98a4u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98a6;
P_0c0c98a6: /* original 7001, guest PC 0x0c0c98a6 */
if(!s->budget--) { s->failed_pc=0x0c0c98a6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c98a8;
P_0c0c98a8: /* original 0ec4, guest PC 0x0c0c98a8 */
if(!s->budget--) { s->failed_pc=0x0c0c98a8u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98aa;
P_0c0c98aa: /* original 70c1, guest PC 0x0c0c98aa */
if(!s->budget--) { s->failed_pc=0x0c0c98aau; return 0; }
r[0]+=0xffffffc1u;
goto P_0c0c98ac;
P_0c0c98ac: /* original 0ec4, guest PC 0x0c0c98ac */
if(!s->budget--) { s->failed_pc=0x0c0c98acu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98ae;
P_0c0c98ae: /* original 7001, guest PC 0x0c0c98ae */
if(!s->budget--) { s->failed_pc=0x0c0c98aeu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c98b0;
P_0c0c98b0: /* original 0ec4, guest PC 0x0c0c98b0 */
if(!s->budget--) { s->failed_pc=0x0c0c98b0u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98b2;
P_0c0c98b2: /* original 70fd, guest PC 0x0c0c98b2 */
if(!s->budget--) { s->failed_pc=0x0c0c98b2u; return 0; }
r[0]+=0xfffffffdu;
goto P_0c0c98b4;
P_0c0c98b4: /* original 0e74, guest PC 0x0c0c98b4 */
if(!s->budget--) { s->failed_pc=0x0c0c98b4u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0c98b6;
P_0c0c98b6: /* original e010, guest PC 0x0c0c98b6 */
if(!s->budget--) { s->failed_pc=0x0c0c98b6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c98b8;
P_0c0c98b8: /* original a00e, guest PC 0x0c0c98b8 */
if(!s->budget--) { s->failed_pc=0x0c0c98b8u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98d8;
P_0c0c98ba: /* original 0d34, guest PC 0x0c0c98ba */
if(!s->budget--) { s->failed_pc=0x0c0c98bau; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98bc;
P_0c0c98bc: /* original 9068, guest PC 0x0c0c98bc */
if(!s->budget--) { s->failed_pc=0x0c0c98bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9990u,2);
goto P_0c0c98be;
P_0c0c98be: /* original e102, guest PC 0x0c0c98be */
if(!s->budget--) { s->failed_pc=0x0c0c98beu; return 0; }
r[1]=0x00000002u;
goto P_0c0c98c0;
P_0c0c98c0: /* original 0e14, guest PC 0x0c0c98c0 */
if(!s->budget--) { s->failed_pc=0x0c0c98c0u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0c98c2;
P_0c0c98c2: /* original e010, guest PC 0x0c0c98c2 */
if(!s->budget--) { s->failed_pc=0x0c0c98c2u; return 0; }
r[0]=0x00000010u;
goto P_0c0c98c4;
P_0c0c98c4: /* original a008, guest PC 0x0c0c98c4 */
if(!s->budget--) { s->failed_pc=0x0c0c98c4u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0c98d8;
P_0c0c98c6: /* original 0d44, guest PC 0x0c0c98c6 */
if(!s->budget--) { s->failed_pc=0x0c0c98c6u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0c98c8;
P_0c0c98c8: /* original 9062, guest PC 0x0c0c98c8 */
if(!s->budget--) { s->failed_pc=0x0c0c98c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9990u,2);
goto P_0c0c98ca;
P_0c0c98ca: /* original e363, guest PC 0x0c0c98ca */
if(!s->budget--) { s->failed_pc=0x0c0c98cau; return 0; }
r[3]=0x00000063u;
goto P_0c0c98cc;
P_0c0c98cc: /* original 0e64, guest PC 0x0c0c98cc */
if(!s->budget--) { s->failed_pc=0x0c0c98ccu; return 0; }
write(ram,r[14]+r[0],r[6],1);
goto P_0c0c98ce;
P_0c0c98ce: /* original e010, guest PC 0x0c0c98ce */
if(!s->budget--) { s->failed_pc=0x0c0c98ceu; return 0; }
r[0]=0x00000010u;
goto P_0c0c98d0;
P_0c0c98d0: /* original a002, guest PC 0x0c0c98d0 */
if(!s->budget--) { s->failed_pc=0x0c0c98d0u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98d8;
P_0c0c98d2: /* original 0d34, guest PC 0x0c0c98d2 */
if(!s->budget--) { s->failed_pc=0x0c0c98d2u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98d4;
P_0c0c98d4: /* original 60c3, guest PC 0x0c0c98d4 */
if(!s->budget--) { s->failed_pc=0x0c0c98d4u; return 0; }
r[0]=r[12];
goto P_0c0c98d6;
P_0c0c98d6: /* original 80db, guest PC 0x0c0c98d6 */
if(!s->budget--) { s->failed_pc=0x0c0c98d6u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c0c98d8;
P_0c0c98d8: /* original 7f08, guest PC 0x0c0c98d8 */
if(!s->budget--) { s->failed_pc=0x0c0c98d8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c98da;
P_0c0c98da: /* original d330, guest PC 0x0c0c98da */
if(!s->budget--) { s->failed_pc=0x0c0c98dau; return 0; }
r[3]=read(ram,0x0c0c999cu,4);
goto P_0c0c98dc;
P_0c0c98dc: /* original 4f26, guest PC 0x0c0c98dc */
if(!s->budget--) { s->failed_pc=0x0c0c98dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c98de;
P_0c0c98de: /* original 69f6, guest PC 0x0c0c98de */
if(!s->budget--) { s->failed_pc=0x0c0c98deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c98e0;
P_0c0c98e0: /* original 6af6, guest PC 0x0c0c98e0 */
if(!s->budget--) { s->failed_pc=0x0c0c98e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c98e2;
P_0c0c98e2: /* original 6bf6, guest PC 0x0c0c98e2 */
if(!s->budget--) { s->failed_pc=0x0c0c98e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c98e4;
P_0c0c98e4: /* original 6cf6, guest PC 0x0c0c98e4 */
if(!s->budget--) { s->failed_pc=0x0c0c98e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c98e6;
P_0c0c98e6: /* original 6df6, guest PC 0x0c0c98e6 */
if(!s->budget--) { s->failed_pc=0x0c0c98e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c98e8;
P_0c0c98e8: /* original 432b, guest PC 0x0c0c98e8 */
if(!s->budget--) { s->failed_pc=0x0c0c98e8u; return 0; }
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
P_0c0c98ea: /* original 6ef6, guest PC 0x0c0c98ea */
if(!s->budget--) { s->failed_pc=0x0c0c98eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c98ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c98ecu; return 0; } return 1;
P_0c0c9910: /* original 2fe6, guest PC 0x0c0c9910 */
if(!s->budget--) { s->failed_pc=0x0c0c9910u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9912;
P_0c0c9912: /* original 903f, guest PC 0x0c0c9912 */
if(!s->budget--) { s->failed_pc=0x0c0c9912u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9994u,2);
goto P_0c0c9914;
P_0c0c9914: /* original de22, guest PC 0x0c0c9914 */
if(!s->budget--) { s->failed_pc=0x0c0c9914u; return 0; }
r[14]=read(ram,0x0c0c99a0u,4);
goto P_0c0c9916;
P_0c0c9916: /* original d623, guest PC 0x0c0c9916 */
if(!s->budget--) { s->failed_pc=0x0c0c9916u; return 0; }
r[6]=read(ram,0x0c0c99a4u,4);
goto P_0c0c9918;
P_0c0c9918: /* original 05ee, guest PC 0x0c0c9918 */
if(!s->budget--) { s->failed_pc=0x0c0c9918u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c991a;
P_0c0c991a: /* original 903a, guest PC 0x0c0c991a */
if(!s->budget--) { s->failed_pc=0x0c0c991au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9992u,2);
goto P_0c0c991c;
P_0c0c991c: /* original d322, guest PC 0x0c0c991c */
if(!s->budget--) { s->failed_pc=0x0c0c991cu; return 0; }
r[3]=read(ram,0x0c0c99a8u,4);
goto P_0c0c991e;
P_0c0c991e: /* original 4f22, guest PC 0x0c0c991e */
if(!s->budget--) { s->failed_pc=0x0c0c991eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9920;
P_0c0c9920: /* original 046c, guest PC 0x0c0c9920 */
if(!s->budget--) { s->failed_pc=0x0c0c9920u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c9922;
P_0c0c9922: /* original 2358, guest PC 0x0c0c9922 */
if(!s->budget--) { s->failed_pc=0x0c0c9922u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c9924;
P_0c0c9924: /* original 8f0f, guest PC 0x0c0c9924 */
if(!s->budget--) { s->failed_pc=0x0c0c9924u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(!cond) { goto P_0c0c9946; }
goto P_0c0c9928;
P_0c0c9926: /* original e701, guest PC 0x0c0c9926 */
if(!s->budget--) { s->failed_pc=0x0c0c9926u; return 0; }
r[7]=0x00000001u;
goto P_0c0c9928;
P_0c0c9928: /* original d220, guest PC 0x0c0c9928 */
if(!s->budget--) { s->failed_pc=0x0c0c9928u; return 0; }
r[2]=read(ram,0x0c0c99acu,4);
goto P_0c0c992a;
P_0c0c992a: /* original 2258, guest PC 0x0c0c992a */
if(!s->budget--) { s->failed_pc=0x0c0c992au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c992c;
P_0c0c992c: /* original 8b03, guest PC 0x0c0c992c */
if(!s->budget--) { s->failed_pc=0x0c0c992cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9936; }
goto P_0c0c992e;
P_0c0c992e: /* original 9332, guest PC 0x0c0c992e */
if(!s->budget--) { s->failed_pc=0x0c0c992eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9996u,2);
goto P_0c0c9930;
P_0c0c9930: /* original 2538, guest PC 0x0c0c9930 */
if(!s->budget--) { s->failed_pc=0x0c0c9930u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c9932;
P_0c0c9932: /* original 8d46, guest PC 0x0c0c9932 */
if(!s->budget--) { s->failed_pc=0x0c0c9932u; return 0; }
cond=r[17]&1u;
r[7]=0xffffffffu;
if(cond) { goto P_0c0c99c2; }
goto P_0c0c9936;
P_0c0c9934: /* original e7ff, guest PC 0x0c0c9934 */
if(!s->budget--) { s->failed_pc=0x0c0c9934u; return 0; }
r[7]=0xffffffffu;
goto P_0c0c9936;
P_0c0c9936: /* original 902f, guest PC 0x0c0c9936 */
if(!s->budget--) { s->failed_pc=0x0c0c9936u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9998u,2);
goto P_0c0c9938;
P_0c0c9938: /* original e303, guest PC 0x0c0c9938 */
if(!s->budget--) { s->failed_pc=0x0c0c9938u; return 0; }
r[3]=0x00000003u;
goto P_0c0c993a;
P_0c0c993a: /* original 0644, guest PC 0x0c0c993a */
if(!s->budget--) { s->failed_pc=0x0c0c993au; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c993c;
P_0c0c993c: /* original 347c, guest PC 0x0c0c993c */
if(!s->budget--) { s->failed_pc=0x0c0c993cu; return 0; }
r[4]+=r[7];
goto P_0c0c993e;
P_0c0c993e: /* original 70ff, guest PC 0x0c0c993e */
if(!s->budget--) { s->failed_pc=0x0c0c993eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9940;
P_0c0c9940: /* original 2439, guest PC 0x0c0c9940 */
if(!s->budget--) { s->failed_pc=0x0c0c9940u; return 0; }
r[4]&=r[3];
goto P_0c0c9942;
P_0c0c9942: /* original a03e, guest PC 0x0c0c9942 */
if(!s->budget--) { s->failed_pc=0x0c0c9942u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c99c2;
P_0c0c9944: /* original 0644, guest PC 0x0c0c9944 */
if(!s->budget--) { s->failed_pc=0x0c0c9944u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c9946;
P_0c0c9946: /* original 3473, guest PC 0x0c0c9946 */
if(!s->budget--) { s->failed_pc=0x0c0c9946u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c0c9948;
P_0c0c9948: /* original 8f0e, guest PC 0x0c0c9948 */
if(!s->budget--) { s->failed_pc=0x0c0c9948u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c0c9968; }
goto P_0c0c994c;
P_0c0c994a: /* original e500, guest PC 0x0c0c994a */
if(!s->budget--) { s->failed_pc=0x0c0c994au; return 0; }
r[5]=0x00000000u;
goto P_0c0c994c;
P_0c0c994c: /* original 6043, guest PC 0x0c0c994c */
if(!s->budget--) { s->failed_pc=0x0c0c994cu; return 0; }
r[0]=r[4];
goto P_0c0c994e;
P_0c0c994e: /* original 8801, guest PC 0x0c0c994e */
if(!s->budget--) { s->failed_pc=0x0c0c994eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9950;
P_0c0c9950: /* original 8d0a, guest PC 0x0c0c9950 */
if(!s->budget--) { s->failed_pc=0x0c0c9950u; return 0; }
cond=r[17]&1u;
r[5]=r[7];
if(cond) { goto P_0c0c9968; }
goto P_0c0c9954;
P_0c0c9952: /* original 6573, guest PC 0x0c0c9952 */
if(!s->budget--) { s->failed_pc=0x0c0c9952u; return 0; }
r[5]=r[7];
goto P_0c0c9954;
P_0c0c9954: /* original 6043, guest PC 0x0c0c9954 */
if(!s->budget--) { s->failed_pc=0x0c0c9954u; return 0; }
r[0]=r[4];
goto P_0c0c9956;
P_0c0c9956: /* original 8802, guest PC 0x0c0c9956 */
if(!s->budget--) { s->failed_pc=0x0c0c9956u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c9958;
P_0c0c9958: /* original 8d06, guest PC 0x0c0c9958 */
if(!s->budget--) { s->failed_pc=0x0c0c9958u; return 0; }
cond=r[17]&1u;
r[5]=0x00000002u;
if(cond) { goto P_0c0c9968; }
goto P_0c0c995c;
P_0c0c995a: /* original e502, guest PC 0x0c0c995a */
if(!s->budget--) { s->failed_pc=0x0c0c995au; return 0; }
r[5]=0x00000002u;
goto P_0c0c995c;
P_0c0c995c: /* original d314, guest PC 0x0c0c995c */
if(!s->budget--) { s->failed_pc=0x0c0c995cu; return 0; }
r[3]=read(ram,0x0c0c99b0u,4);
goto P_0c0c995e;
P_0c0c995e: /* original 430b, guest PC 0x0c0c995e */
if(!s->budget--) { s->failed_pc=0x0c0c995eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9962u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9962u) { target=s->pc; goto dispatch; }
goto P_0c0c9962;
P_0c0c9960: /* original 0009, guest PC 0x0c0c9960 */
if(!s->budget--) { s->failed_pc=0x0c0c9960u; return 0; }
goto P_0c0c9962;
P_0c0c9962: /* original e000, guest PC 0x0c0c9962 */
if(!s->budget--) { s->failed_pc=0x0c0c9962u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9964;
P_0c0c9964: /* original a02d, guest PC 0x0c0c9964 */
if(!s->budget--) { s->failed_pc=0x0c0c9964u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c99c2;
P_0c0c9966: /* original 80eb, guest PC 0x0c0c9966 */
if(!s->budget--) { s->failed_pc=0x0c0c9966u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c9968;
P_0c0c9968: /* original 6053, guest PC 0x0c0c9968 */
if(!s->budget--) { s->failed_pc=0x0c0c9968u; return 0; }
r[0]=r[5];
goto P_0c0c996a;
P_0c0c996a: /* original 8800, guest PC 0x0c0c996a */
if(!s->budget--) { s->failed_pc=0x0c0c996au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c996c;
P_0c0c996c: /* original 8905, guest PC 0x0c0c996c */
if(!s->budget--) { s->failed_pc=0x0c0c996cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c997a; }
goto P_0c0c996e;
P_0c0c996e: /* original 8801, guest PC 0x0c0c996e */
if(!s->budget--) { s->failed_pc=0x0c0c996eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9970;
P_0c0c9970: /* original 8908, guest PC 0x0c0c9970 */
if(!s->budget--) { s->failed_pc=0x0c0c9970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9984; }
goto P_0c0c9972;
P_0c0c9972: /* original 8802, guest PC 0x0c0c9972 */
if(!s->budget--) { s->failed_pc=0x0c0c9972u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c9974;
P_0c0c9974: /* original 8922, guest PC 0x0c0c9974 */
if(!s->budget--) { s->failed_pc=0x0c0c9974u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c99bc; }
goto P_0c0c9976;
P_0c0c9976: /* original a024, guest PC 0x0c0c9976 */
if(!s->budget--) { s->failed_pc=0x0c0c9976u; return 0; }
goto P_0c0c99c2;
P_0c0c9978: /* original 0009, guest PC 0x0c0c9978 */
if(!s->budget--) { s->failed_pc=0x0c0c9978u; return 0; }
goto P_0c0c997a;
P_0c0c997a: /* original d20e, guest PC 0x0c0c997a */
if(!s->budget--) { s->failed_pc=0x0c0c997au; return 0; }
r[2]=read(ram,0x0c0c99b4u,4);
goto P_0c0c997c;
P_0c0c997c: /* original 420b, guest PC 0x0c0c997c */
if(!s->budget--) { s->failed_pc=0x0c0c997cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9980u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9980u) { target=s->pc; goto dispatch; }
goto P_0c0c9980;
P_0c0c997e: /* original 0009, guest PC 0x0c0c997e */
if(!s->budget--) { s->failed_pc=0x0c0c997eu; return 0; }
goto P_0c0c9980;
P_0c0c9980: /* original a01f, guest PC 0x0c0c9980 */
if(!s->budget--) { s->failed_pc=0x0c0c9980u; return 0; }
goto P_0c0c99c2;
P_0c0c9982: /* original 0009, guest PC 0x0c0c9982 */
if(!s->budget--) { s->failed_pc=0x0c0c9982u; return 0; }
goto P_0c0c9984;
P_0c0c9984: /* original d20c, guest PC 0x0c0c9984 */
if(!s->budget--) { s->failed_pc=0x0c0c9984u; return 0; }
r[2]=read(ram,0x0c0c99b8u,4);
goto P_0c0c9986;
P_0c0c9986: /* original 420b, guest PC 0x0c0c9986 */
if(!s->budget--) { s->failed_pc=0x0c0c9986u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c998au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c998au) { target=s->pc; goto dispatch; }
goto P_0c0c998a;
P_0c0c9988: /* original 0009, guest PC 0x0c0c9988 */
if(!s->budget--) { s->failed_pc=0x0c0c9988u; return 0; }
goto P_0c0c998a;
P_0c0c998a: /* original a01a, guest PC 0x0c0c998a */
if(!s->budget--) { s->failed_pc=0x0c0c998au; return 0; }
goto P_0c0c99c2;
P_0c0c998c: /* original 0009, guest PC 0x0c0c998c */
if(!s->budget--) { s->failed_pc=0x0c0c998cu; return 0; }
if(!vf3_matrix_family(0x0c0c998eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c998eu; return 0; } return 1;
P_0c0c99bc: /* original d23a, guest PC 0x0c0c99bc */
if(!s->budget--) { s->failed_pc=0x0c0c99bcu; return 0; }
r[2]=read(ram,0x0c0c9aa8u,4);
goto P_0c0c99be;
P_0c0c99be: /* original 420b, guest PC 0x0c0c99be */
if(!s->budget--) { s->failed_pc=0x0c0c99beu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c99c2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c99c2u) { target=s->pc; goto dispatch; }
goto P_0c0c99c2;
P_0c0c99c0: /* original 0009, guest PC 0x0c0c99c0 */
if(!s->budget--) { s->failed_pc=0x0c0c99c0u; return 0; }
goto P_0c0c99c2;
P_0c0c99c2: /* original 4f26, guest PC 0x0c0c99c2 */
if(!s->budget--) { s->failed_pc=0x0c0c99c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c99c4;
P_0c0c99c4: /* original d239, guest PC 0x0c0c99c4 */
if(!s->budget--) { s->failed_pc=0x0c0c99c4u; return 0; }
r[2]=read(ram,0x0c0c9aacu,4);
goto P_0c0c99c6;
P_0c0c99c6: /* original 422b, guest PC 0x0c0c99c6 */
if(!s->budget--) { s->failed_pc=0x0c0c99c6u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: return vf3_matrix_family(0x0c09abc4u,s,ram);
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
P_0c0c99c8: /* original 6ef6, guest PC 0x0c0c99c8 */
if(!s->budget--) { s->failed_pc=0x0c0c99c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c99cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c99cau; return 0; } return 1;
P_0c0c99ee: /* original 2fe6, guest PC 0x0c0c99ee */
if(!s->budget--) { s->failed_pc=0x0c0c99eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f0;
P_0c0c99f0: /* original 2fd6, guest PC 0x0c0c99f0 */
if(!s->budget--) { s->failed_pc=0x0c0c99f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f2;
P_0c0c99f2: /* original ed00, guest PC 0x0c0c99f2 */
if(!s->budget--) { s->failed_pc=0x0c0c99f2u; return 0; }
r[13]=0x00000000u;
goto P_0c0c99f4;
P_0c0c99f4: /* original 2fc6, guest PC 0x0c0c99f4 */
if(!s->budget--) { s->failed_pc=0x0c0c99f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f6;
P_0c0c99f6: /* original de2f, guest PC 0x0c0c99f6 */
if(!s->budget--) { s->failed_pc=0x0c0c99f6u; return 0; }
r[14]=read(ram,0x0c0c9ab4u,4);
goto P_0c0c99f8;
P_0c0c99f8: /* original 9052, guest PC 0x0c0c99f8 */
if(!s->budget--) { s->failed_pc=0x0c0c99f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa0u,2);
goto P_0c0c99fa;
P_0c0c99fa: /* original d52d, guest PC 0x0c0c99fa */
if(!s->budget--) { s->failed_pc=0x0c0c99fau; return 0; }
r[5]=read(ram,0x0c0c9ab0u,4);
goto P_0c0c99fc;
P_0c0c99fc: /* original 03ec, guest PC 0x0c0c99fc */
if(!s->budget--) { s->failed_pc=0x0c0c99fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c99fe;
P_0c0c99fe: /* original 4f22, guest PC 0x0c0c99fe */
if(!s->budget--) { s->failed_pc=0x0c0c99feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9a00;
P_0c0c9a00: /* original dc2d, guest PC 0x0c0c9a00 */
if(!s->budget--) { s->failed_pc=0x0c0c9a00u; return 0; }
r[12]=read(ram,0x0c0c9ab8u,4);
goto P_0c0c9a02;
P_0c0c9a02: /* original 2338, guest PC 0x0c0c9a02 */
if(!s->budget--) { s->failed_pc=0x0c0c9a02u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9a04;
P_0c0c9a04: /* original 7ffc, guest PC 0x0c0c9a04 */
if(!s->budget--) { s->failed_pc=0x0c0c9a04u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c9a06;
P_0c0c9a06: /* original 2f32, guest PC 0x0c0c9a06 */
if(!s->budget--) { s->failed_pc=0x0c0c9a06u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9a08;
P_0c0c9a08: /* original 904b, guest PC 0x0c0c9a08 */
if(!s->budget--) { s->failed_pc=0x0c0c9a08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa2u,2);
goto P_0c0c9a0a;
P_0c0c9a0a: /* original d62c, guest PC 0x0c0c9a0a */
if(!s->budget--) { s->failed_pc=0x0c0c9a0au; return 0; }
r[6]=read(ram,0x0c0c9abcu,4);
goto P_0c0c9a0c;
P_0c0c9a0c: /* original 075e, guest PC 0x0c0c9a0c */
if(!s->budget--) { s->failed_pc=0x0c0c9a0cu; return 0; }
r[7]=read(ram,r[5]+r[0],4);
goto P_0c0c9a0e;
P_0c0c9a0e: /* original 9046, guest PC 0x0c0c9a0e */
if(!s->budget--) { s->failed_pc=0x0c0c9a0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9a9eu,2);
goto P_0c0c9a10;
P_0c0c9a10: /* original 04ec, guest PC 0x0c0c9a10 */
if(!s->budget--) { s->failed_pc=0x0c0c9a10u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9a12;
P_0c0c9a12: /* original 8f27, guest PC 0x0c0c9a12 */
if(!s->budget--) { s->failed_pc=0x0c0c9a12u; return 0; }
cond=r[17]&1u;
r[6]&=r[7];
if(!cond) { goto P_0c0c9a64; }
goto P_0c0c9a16;
P_0c0c9a14: /* original 2679, guest PC 0x0c0c9a14 */
if(!s->budget--) { s->failed_pc=0x0c0c9a14u; return 0; }
r[6]&=r[7];
goto P_0c0c9a16;
P_0c0c9a16: /* original 2668, guest PC 0x0c0c9a16 */
if(!s->budget--) { s->failed_pc=0x0c0c9a16u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9a18;
P_0c0c9a18: /* original 8b09, guest PC 0x0c0c9a18 */
if(!s->budget--) { s->failed_pc=0x0c0c9a18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9a2e; }
goto P_0c0c9a1a;
P_0c0c9a1a: /* original d229, guest PC 0x0c0c9a1a */
if(!s->budget--) { s->failed_pc=0x0c0c9a1au; return 0; }
r[2]=read(ram,0x0c0c9ac0u,4);
goto P_0c0c9a1c;
P_0c0c9a1c: /* original 2728, guest PC 0x0c0c9a1c */
if(!s->budget--) { s->failed_pc=0x0c0c9a1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0c9a1e;
P_0c0c9a1e: /* original 8925, guest PC 0x0c0c9a1e */
if(!s->budget--) { s->failed_pc=0x0c0c9a1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9a6c; }
goto P_0c0c9a20;
P_0c0c9a20: /* original 9040, guest PC 0x0c0c9a20 */
if(!s->budget--) { s->failed_pc=0x0c0c9a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa4u,2);
goto P_0c0c9a22;
P_0c0c9a22: /* original e301, guest PC 0x0c0c9a22 */
if(!s->budget--) { s->failed_pc=0x0c0c9a22u; return 0; }
r[3]=0x00000001u;
goto P_0c0c9a24;
P_0c0c9a24: /* original 0e44, guest PC 0x0c0c9a24 */
if(!s->budget--) { s->failed_pc=0x0c0c9a24u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a26;
P_0c0c9a26: /* original 70ff, guest PC 0x0c0c9a26 */
if(!s->budget--) { s->failed_pc=0x0c0c9a26u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9a28;
P_0c0c9a28: /* original 243a, guest PC 0x0c0c9a28 */
if(!s->budget--) { s->failed_pc=0x0c0c9a28u; return 0; }
r[4]^=r[3];
goto P_0c0c9a2a;
P_0c0c9a2a: /* original a01f, guest PC 0x0c0c9a2a */
if(!s->budget--) { s->failed_pc=0x0c0c9a2au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a6c;
P_0c0c9a2c: /* original 0e44, guest PC 0x0c0c9a2c */
if(!s->budget--) { s->failed_pc=0x0c0c9a2cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a2e;
P_0c0c9a2e: /* original 2448, guest PC 0x0c0c9a2e */
if(!s->budget--) { s->failed_pc=0x0c0c9a2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9a30;
P_0c0c9a30: /* original 8b1a, guest PC 0x0c0c9a30 */
if(!s->budget--) { s->failed_pc=0x0c0c9a30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9a68; }
goto P_0c0c9a32;
P_0c0c9a32: /* original d224, guest PC 0x0c0c9a32 */
if(!s->budget--) { s->failed_pc=0x0c0c9a32u; return 0; }
r[2]=read(ram,0x0c0c9ac4u,4);
goto P_0c0c9a34;
P_0c0c9a34: /* original 420b, guest PC 0x0c0c9a34 */
if(!s->budget--) { s->failed_pc=0x0c0c9a34u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9a38u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a38u) { target=s->pc; goto dispatch; }
goto P_0c0c9a38;
P_0c0c9a36: /* original 0009, guest PC 0x0c0c9a36 */
if(!s->budget--) { s->failed_pc=0x0c0c9a36u; return 0; }
goto P_0c0c9a38;
P_0c0c9a38: /* original d323, guest PC 0x0c0c9a38 */
if(!s->budget--) { s->failed_pc=0x0c0c9a38u; return 0; }
r[3]=read(ram,0x0c0c9ac8u,4);
goto P_0c0c9a3a;
P_0c0c9a3a: /* original 430b, guest PC 0x0c0c9a3a */
if(!s->budget--) { s->failed_pc=0x0c0c9a3au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9a3eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a3eu) { target=s->pc; goto dispatch; }
goto P_0c0c9a3e;
P_0c0c9a3c: /* original 0009, guest PC 0x0c0c9a3c */
if(!s->budget--) { s->failed_pc=0x0c0c9a3cu; return 0; }
goto P_0c0c9a3e;
P_0c0c9a3e: /* original 9032, guest PC 0x0c0c9a3e */
if(!s->budget--) { s->failed_pc=0x0c0c9a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa6u,2);
goto P_0c0c9a40;
P_0c0c9a40: /* original 64c3, guest PC 0x0c0c9a40 */
if(!s->budget--) { s->failed_pc=0x0c0c9a40u; return 0; }
r[4]=r[12];
goto P_0c0c9a42;
P_0c0c9a42: /* original e500, guest PC 0x0c0c9a42 */
if(!s->budget--) { s->failed_pc=0x0c0c9a42u; return 0; }
r[5]=0x00000000u;
goto P_0c0c9a44;
P_0c0c9a44: /* original 0ed4, guest PC 0x0c0c9a44 */
if(!s->budget--) { s->failed_pc=0x0c0c9a44u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c9a46;
P_0c0c9a46: /* original 7004, guest PC 0x0c0c9a46 */
if(!s->budget--) { s->failed_pc=0x0c0c9a46u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c9a48;
P_0c0c9a48: /* original 0ed4, guest PC 0x0c0c9a48 */
if(!s->budget--) { s->failed_pc=0x0c0c9a48u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c9a4a;
P_0c0c9a4a: /* original d320, guest PC 0x0c0c9a4a */
if(!s->budget--) { s->failed_pc=0x0c0c9a4au; return 0; }
r[3]=read(ram,0x0c0c9accu,4);
goto P_0c0c9a4c;
P_0c0c9a4c: /* original 430b, guest PC 0x0c0c9a4c */
if(!s->budget--) { s->failed_pc=0x0c0c9a4cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9a50u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a50u) { target=s->pc; goto dispatch; }
goto P_0c0c9a50;
P_0c0c9a4e: /* original 7426, guest PC 0x0c0c9a4e */
if(!s->budget--) { s->failed_pc=0x0c0c9a4eu; return 0; }
r[4]+=0x00000026u;
goto P_0c0c9a50;
P_0c0c9a50: /* original d21e, guest PC 0x0c0c9a50 */
if(!s->budget--) { s->failed_pc=0x0c0c9a50u; return 0; }
r[2]=read(ram,0x0c0c9accu,4);
goto P_0c0c9a52;
P_0c0c9a52: /* original 64c3, guest PC 0x0c0c9a52 */
if(!s->budget--) { s->failed_pc=0x0c0c9a52u; return 0; }
r[4]=r[12];
goto P_0c0c9a54;
P_0c0c9a54: /* original e500, guest PC 0x0c0c9a54 */
if(!s->budget--) { s->failed_pc=0x0c0c9a54u; return 0; }
r[5]=0x00000000u;
goto P_0c0c9a56;
P_0c0c9a56: /* original 420b, guest PC 0x0c0c9a56 */
if(!s->budget--) { s->failed_pc=0x0c0c9a56u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9a5au;
r[4]+=0x00000029u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a5au) { target=s->pc; goto dispatch; }
goto P_0c0c9a5a;
P_0c0c9a58: /* original 7429, guest PC 0x0c0c9a58 */
if(!s->budget--) { s->failed_pc=0x0c0c9a58u; return 0; }
r[4]+=0x00000029u;
goto P_0c0c9a5a;
P_0c0c9a5a: /* original 9021, guest PC 0x0c0c9a5a */
if(!s->budget--) { s->failed_pc=0x0c0c9a5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa0u,2);
goto P_0c0c9a5c;
P_0c0c9a5c: /* original 03ec, guest PC 0x0c0c9a5c */
if(!s->budget--) { s->failed_pc=0x0c0c9a5cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9a5e;
P_0c0c9a5e: /* original 7301, guest PC 0x0c0c9a5e */
if(!s->budget--) { s->failed_pc=0x0c0c9a5eu; return 0; }
r[3]+=0x00000001u;
goto P_0c0c9a60;
P_0c0c9a60: /* original a004, guest PC 0x0c0c9a60 */
if(!s->budget--) { s->failed_pc=0x0c0c9a60u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9a6c;
P_0c0c9a62: /* original 0e34, guest PC 0x0c0c9a62 */
if(!s->budget--) { s->failed_pc=0x0c0c9a62u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9a64;
P_0c0c9a64: /* original 2668, guest PC 0x0c0c9a64 */
if(!s->budget--) { s->failed_pc=0x0c0c9a64u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9a66;
P_0c0c9a66: /* original 8901, guest PC 0x0c0c9a66 */
if(!s->budget--) { s->failed_pc=0x0c0c9a66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9a6c; }
goto P_0c0c9a68;
P_0c0c9a68: /* original 60d3, guest PC 0x0c0c9a68 */
if(!s->budget--) { s->failed_pc=0x0c0c9a68u; return 0; }
r[0]=r[13];
goto P_0c0c9a6a;
P_0c0c9a6a: /* original 805b, guest PC 0x0c0c9a6a */
if(!s->budget--) { s->failed_pc=0x0c0c9a6au; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c0c9a6c;
P_0c0c9a6c: /* original 7f04, guest PC 0x0c0c9a6c */
if(!s->budget--) { s->failed_pc=0x0c0c9a6cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c9a6e;
P_0c0c9a6e: /* original d30f, guest PC 0x0c0c9a6e */
if(!s->budget--) { s->failed_pc=0x0c0c9a6eu; return 0; }
r[3]=read(ram,0x0c0c9aacu,4);
goto P_0c0c9a70;
P_0c0c9a70: /* original 4f26, guest PC 0x0c0c9a70 */
if(!s->budget--) { s->failed_pc=0x0c0c9a70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9a72;
P_0c0c9a72: /* original 6cf6, guest PC 0x0c0c9a72 */
if(!s->budget--) { s->failed_pc=0x0c0c9a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c9a74;
P_0c0c9a74: /* original 6df6, guest PC 0x0c0c9a74 */
if(!s->budget--) { s->failed_pc=0x0c0c9a74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c9a76;
P_0c0c9a76: /* original 432b, guest PC 0x0c0c9a76 */
if(!s->budget--) { s->failed_pc=0x0c0c9a76u; return 0; }
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
P_0c0c9a78: /* original 6ef6, guest PC 0x0c0c9a78 */
if(!s->budget--) { s->failed_pc=0x0c0c9a78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9a7au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9a7au; return 0; } return 1;
P_0c0c9ad0: /* original 2fe6, guest PC 0x0c0c9ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9ad2;
P_0c0c9ad2: /* original 9046, guest PC 0x0c0c9ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b62u,2);
goto P_0c0c9ad4;
P_0c0c9ad4: /* original de26, guest PC 0x0c0c9ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad4u; return 0; }
r[14]=read(ram,0x0c0c9b70u,4);
goto P_0c0c9ad6;
P_0c0c9ad6: /* original d525, guest PC 0x0c0c9ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad6u; return 0; }
r[5]=read(ram,0x0c0c9b6cu,4);
goto P_0c0c9ad8;
P_0c0c9ad8: /* original 03ec, guest PC 0x0c0c9ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9ada;
P_0c0c9ada: /* original 4f22, guest PC 0x0c0c9ada */
if(!s->budget--) { s->failed_pc=0x0c0c9adau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9adc;
P_0c0c9adc: /* original 2338, guest PC 0x0c0c9adc */
if(!s->budget--) { s->failed_pc=0x0c0c9adcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9ade;
P_0c0c9ade: /* original 7ffc, guest PC 0x0c0c9ade */
if(!s->budget--) { s->failed_pc=0x0c0c9adeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c9ae0;
P_0c0c9ae0: /* original 2f32, guest PC 0x0c0c9ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9ae2;
P_0c0c9ae2: /* original 903f, guest PC 0x0c0c9ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b64u,2);
goto P_0c0c9ae4;
P_0c0c9ae4: /* original d723, guest PC 0x0c0c9ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae4u; return 0; }
r[7]=read(ram,0x0c0c9b74u,4);
goto P_0c0c9ae6;
P_0c0c9ae6: /* original 065e, guest PC 0x0c0c9ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae6u; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c0c9ae8;
P_0c0c9ae8: /* original 903d, guest PC 0x0c0c9ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b66u,2);
goto P_0c0c9aea;
P_0c0c9aea: /* original 04ec, guest PC 0x0c0c9aea */
if(!s->budget--) { s->failed_pc=0x0c0c9aeau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9aec;
P_0c0c9aec: /* original 8f16, guest PC 0x0c0c9aec */
if(!s->budget--) { s->failed_pc=0x0c0c9aecu; return 0; }
cond=r[17]&1u;
r[7]&=r[6];
if(!cond) { goto P_0c0c9b1c; }
goto P_0c0c9af0;
P_0c0c9aee: /* original 2769, guest PC 0x0c0c9aee */
if(!s->budget--) { s->failed_pc=0x0c0c9aeeu; return 0; }
r[7]&=r[6];
goto P_0c0c9af0;
P_0c0c9af0: /* original 2778, guest PC 0x0c0c9af0 */
if(!s->budget--) { s->failed_pc=0x0c0c9af0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9af2;
P_0c0c9af2: /* original 8b09, guest PC 0x0c0c9af2 */
if(!s->budget--) { s->failed_pc=0x0c0c9af2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9b08; }
goto P_0c0c9af4;
P_0c0c9af4: /* original d220, guest PC 0x0c0c9af4 */
if(!s->budget--) { s->failed_pc=0x0c0c9af4u; return 0; }
r[2]=read(ram,0x0c0c9b78u,4);
goto P_0c0c9af6;
P_0c0c9af6: /* original 2628, guest PC 0x0c0c9af6 */
if(!s->budget--) { s->failed_pc=0x0c0c9af6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c9af8;
P_0c0c9af8: /* original 8914, guest PC 0x0c0c9af8 */
if(!s->budget--) { s->failed_pc=0x0c0c9af8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b24; }
goto P_0c0c9afa;
P_0c0c9afa: /* original 9035, guest PC 0x0c0c9afa */
if(!s->budget--) { s->failed_pc=0x0c0c9afau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b68u,2);
goto P_0c0c9afc;
P_0c0c9afc: /* original e301, guest PC 0x0c0c9afc */
if(!s->budget--) { s->failed_pc=0x0c0c9afcu; return 0; }
r[3]=0x00000001u;
goto P_0c0c9afe;
P_0c0c9afe: /* original 0e44, guest PC 0x0c0c9afe */
if(!s->budget--) { s->failed_pc=0x0c0c9afeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b00;
P_0c0c9b00: /* original 70ff, guest PC 0x0c0c9b00 */
if(!s->budget--) { s->failed_pc=0x0c0c9b00u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9b02;
P_0c0c9b02: /* original 243a, guest PC 0x0c0c9b02 */
if(!s->budget--) { s->failed_pc=0x0c0c9b02u; return 0; }
r[4]^=r[3];
goto P_0c0c9b04;
P_0c0c9b04: /* original a00e, guest PC 0x0c0c9b04 */
if(!s->budget--) { s->failed_pc=0x0c0c9b04u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b24;
P_0c0c9b06: /* original 0e44, guest PC 0x0c0c9b06 */
if(!s->budget--) { s->failed_pc=0x0c0c9b06u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b08;
P_0c0c9b08: /* original 2448, guest PC 0x0c0c9b08 */
if(!s->budget--) { s->failed_pc=0x0c0c9b08u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9b0a;
P_0c0c9b0a: /* original 8b09, guest PC 0x0c0c9b0a */
if(!s->budget--) { s->failed_pc=0x0c0c9b0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9b20; }
goto P_0c0c9b0c;
P_0c0c9b0c: /* original d21b, guest PC 0x0c0c9b0c */
if(!s->budget--) { s->failed_pc=0x0c0c9b0cu; return 0; }
r[2]=read(ram,0x0c0c9b7cu,4);
goto P_0c0c9b0e;
P_0c0c9b0e: /* original 420b, guest PC 0x0c0c9b0e */
if(!s->budget--) { s->failed_pc=0x0c0c9b0eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9b12u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9b12u) { target=s->pc; goto dispatch; }
goto P_0c0c9b12;
P_0c0c9b10: /* original 0009, guest PC 0x0c0c9b10 */
if(!s->budget--) { s->failed_pc=0x0c0c9b10u; return 0; }
goto P_0c0c9b12;
P_0c0c9b12: /* original 9026, guest PC 0x0c0c9b12 */
if(!s->budget--) { s->failed_pc=0x0c0c9b12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b62u,2);
goto P_0c0c9b14;
P_0c0c9b14: /* original 03ec, guest PC 0x0c0c9b14 */
if(!s->budget--) { s->failed_pc=0x0c0c9b14u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9b16;
P_0c0c9b16: /* original 7301, guest PC 0x0c0c9b16 */
if(!s->budget--) { s->failed_pc=0x0c0c9b16u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c9b18;
P_0c0c9b18: /* original a004, guest PC 0x0c0c9b18 */
if(!s->budget--) { s->failed_pc=0x0c0c9b18u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9b24;
P_0c0c9b1a: /* original 0e34, guest PC 0x0c0c9b1a */
if(!s->budget--) { s->failed_pc=0x0c0c9b1au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9b1c;
P_0c0c9b1c: /* original 2778, guest PC 0x0c0c9b1c */
if(!s->budget--) { s->failed_pc=0x0c0c9b1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9b1e;
P_0c0c9b1e: /* original 8901, guest PC 0x0c0c9b1e */
if(!s->budget--) { s->failed_pc=0x0c0c9b1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b24; }
goto P_0c0c9b20;
P_0c0c9b20: /* original e000, guest PC 0x0c0c9b20 */
if(!s->budget--) { s->failed_pc=0x0c0c9b20u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9b22;
P_0c0c9b22: /* original 805b, guest PC 0x0c0c9b22 */
if(!s->budget--) { s->failed_pc=0x0c0c9b22u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c0c9b24;
P_0c0c9b24: /* original 7f04, guest PC 0x0c0c9b24 */
if(!s->budget--) { s->failed_pc=0x0c0c9b24u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c9b26;
P_0c0c9b26: /* original d316, guest PC 0x0c0c9b26 */
if(!s->budget--) { s->failed_pc=0x0c0c9b26u; return 0; }
r[3]=read(ram,0x0c0c9b80u,4);
goto P_0c0c9b28;
P_0c0c9b28: /* original 4f26, guest PC 0x0c0c9b28 */
if(!s->budget--) { s->failed_pc=0x0c0c9b28u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9b2a;
P_0c0c9b2a: /* original 432b, guest PC 0x0c0c9b2a */
if(!s->budget--) { s->failed_pc=0x0c0c9b2au; return 0; }
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
P_0c0c9b2c: /* original 6ef6, guest PC 0x0c0c9b2c */
if(!s->budget--) { s->failed_pc=0x0c0c9b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9b2eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b2eu; return 0; } return 1;
P_0c0c9b40: /* original 2fe6, guest PC 0x0c0c9b40 */
if(!s->budget--) { s->failed_pc=0x0c0c9b40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9b42;
P_0c0c9b42: /* original 900f, guest PC 0x0c0c9b42 */
if(!s->budget--) { s->failed_pc=0x0c0c9b42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b64u,2);
goto P_0c0c9b44;
P_0c0c9b44: /* original de09, guest PC 0x0c0c9b44 */
if(!s->budget--) { s->failed_pc=0x0c0c9b44u; return 0; }
r[14]=read(ram,0x0c0c9b6cu,4);
goto P_0c0c9b46;
P_0c0c9b46: /* original d30b, guest PC 0x0c0c9b46 */
if(!s->budget--) { s->failed_pc=0x0c0c9b46u; return 0; }
r[3]=read(ram,0x0c0c9b74u,4);
goto P_0c0c9b48;
P_0c0c9b48: /* original 04ee, guest PC 0x0c0c9b48 */
if(!s->budget--) { s->failed_pc=0x0c0c9b48u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c9b4a;
P_0c0c9b4a: /* original 4f22, guest PC 0x0c0c9b4a */
if(!s->budget--) { s->failed_pc=0x0c0c9b4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9b4c;
P_0c0c9b4c: /* original 2438, guest PC 0x0c0c9b4c */
if(!s->budget--) { s->failed_pc=0x0c0c9b4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c9b4e;
P_0c0c9b4e: /* original 8904, guest PC 0x0c0c9b4e */
if(!s->budget--) { s->failed_pc=0x0c0c9b4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b5a; }
goto P_0c0c9b50;
P_0c0c9b50: /* original d20c, guest PC 0x0c0c9b50 */
if(!s->budget--) { s->failed_pc=0x0c0c9b50u; return 0; }
r[2]=read(ram,0x0c0c9b84u,4);
goto P_0c0c9b52;
P_0c0c9b52: /* original 420b, guest PC 0x0c0c9b52 */
if(!s->budget--) { s->failed_pc=0x0c0c9b52u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9b56u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9b56u) { target=s->pc; goto dispatch; }
goto P_0c0c9b56;
P_0c0c9b54: /* original 0009, guest PC 0x0c0c9b54 */
if(!s->budget--) { s->failed_pc=0x0c0c9b54u; return 0; }
goto P_0c0c9b56;
P_0c0c9b56: /* original e000, guest PC 0x0c0c9b56 */
if(!s->budget--) { s->failed_pc=0x0c0c9b56u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9b58;
P_0c0c9b58: /* original 80eb, guest PC 0x0c0c9b58 */
if(!s->budget--) { s->failed_pc=0x0c0c9b58u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c9b5a;
P_0c0c9b5a: /* original 4f26, guest PC 0x0c0c9b5a */
if(!s->budget--) { s->failed_pc=0x0c0c9b5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9b5c;
P_0c0c9b5c: /* original d308, guest PC 0x0c0c9b5c */
if(!s->budget--) { s->failed_pc=0x0c0c9b5cu; return 0; }
r[3]=read(ram,0x0c0c9b80u,4);
goto P_0c0c9b5e;
P_0c0c9b5e: /* original 432b, guest PC 0x0c0c9b5e */
if(!s->budget--) { s->failed_pc=0x0c0c9b5eu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: return vf3_matrix_family(0x0c09abc4u,s,ram);
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
P_0c0c9b60: /* original 6ef6, guest PC 0x0c0c9b60 */
if(!s->budget--) { s->failed_pc=0x0c0c9b60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9b62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b62u; return 0; } return 1;
P_0c0c9b90: /* original 000b, guest PC 0x0c0c9b90 */
if(!s->budget--) { s->failed_pc=0x0c0c9b90u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9b92: /* original 0009, guest PC 0x0c0c9b92 */
if(!s->budget--) { s->failed_pc=0x0c0c9b92u; return 0; }
if(!vf3_matrix_family(0x0c0c9b94u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b94u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
