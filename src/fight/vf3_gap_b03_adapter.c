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
int vf3_gap_b03_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0103bau: goto P_0c0103ba;
case 0x0c0103bcu: goto P_0c0103bc;
case 0x0c0103beu: goto P_0c0103be;
case 0x0c0103c0u: goto P_0c0103c0;
case 0x0c0103c2u: goto P_0c0103c2;
case 0x0c0103c4u: goto P_0c0103c4;
case 0x0c0103c6u: goto P_0c0103c6;
case 0x0c0103c8u: goto P_0c0103c8;
case 0x0c0103cau: goto P_0c0103ca;
case 0x0c0103ccu: goto P_0c0103cc;
case 0x0c0103ceu: goto P_0c0103ce;
case 0x0c0103d0u: goto P_0c0103d0;
case 0x0c0103d2u: goto P_0c0103d2;
case 0x0c0103d4u: goto P_0c0103d4;
case 0x0c0103d6u: goto P_0c0103d6;
case 0x0c0103d8u: goto P_0c0103d8;
case 0x0c0103dau: goto P_0c0103da;
case 0x0c0103dcu: goto P_0c0103dc;
case 0x0c0103deu: goto P_0c0103de;
case 0x0c0103e0u: goto P_0c0103e0;
case 0x0c0103e2u: goto P_0c0103e2;
case 0x0c0103e4u: goto P_0c0103e4;
case 0x0c0103e6u: goto P_0c0103e6;
case 0x0c0103e8u: goto P_0c0103e8;
case 0x0c0103eau: goto P_0c0103ea;
case 0x0c0103ecu: goto P_0c0103ec;
case 0x0c0103eeu: goto P_0c0103ee;
case 0x0c0103f0u: goto P_0c0103f0;
case 0x0c0103f2u: goto P_0c0103f2;
case 0x0c0103f4u: goto P_0c0103f4;
case 0x0c0103f6u: goto P_0c0103f6;
case 0x0c0103f8u: goto P_0c0103f8;
case 0x0c0103fau: goto P_0c0103fa;
case 0x0c0103fcu: goto P_0c0103fc;
case 0x0c0103feu: goto P_0c0103fe;
case 0x0c010400u: goto P_0c010400;
case 0x0c010630u: goto P_0c010630;
case 0x0c010632u: goto P_0c010632;
case 0x0c010634u: goto P_0c010634;
case 0x0c010636u: goto P_0c010636;
case 0x0c010638u: goto P_0c010638;
case 0x0c01063au: goto P_0c01063a;
case 0x0c01063cu: goto P_0c01063c;
case 0x0c01063eu: goto P_0c01063e;
case 0x0c010640u: goto P_0c010640;
case 0x0c010642u: goto P_0c010642;
case 0x0c010644u: goto P_0c010644;
case 0x0c010646u: goto P_0c010646;
case 0x0c010648u: goto P_0c010648;
case 0x0c01064au: goto P_0c01064a;
case 0x0c01064cu: goto P_0c01064c;
case 0x0c01064eu: goto P_0c01064e;
case 0x0c010650u: goto P_0c010650;
case 0x0c010652u: goto P_0c010652;
case 0x0c010654u: goto P_0c010654;
case 0x0c010656u: goto P_0c010656;
case 0x0c010658u: goto P_0c010658;
case 0x0c01065au: goto P_0c01065a;
case 0x0c01065cu: goto P_0c01065c;
case 0x0c01065eu: goto P_0c01065e;
case 0x0c010660u: goto P_0c010660;
case 0x0c010662u: goto P_0c010662;
case 0x0c010664u: goto P_0c010664;
case 0x0c010666u: goto P_0c010666;
case 0x0c010668u: goto P_0c010668;
case 0x0c01066au: goto P_0c01066a;
case 0x0c01066cu: goto P_0c01066c;
case 0x0c01066eu: goto P_0c01066e;
case 0x0c010670u: goto P_0c010670;
case 0x0c010672u: goto P_0c010672;
case 0x0c010674u: goto P_0c010674;
case 0x0c010676u: goto P_0c010676;
case 0x0c010678u: goto P_0c010678;
case 0x0c01067au: goto P_0c01067a;
case 0x0c01067cu: goto P_0c01067c;
case 0x0c01067eu: goto P_0c01067e;
case 0x0c010680u: goto P_0c010680;
case 0x0c010954u: goto P_0c010954;
case 0x0c010956u: goto P_0c010956;
case 0x0c010958u: goto P_0c010958;
case 0x0c01095au: goto P_0c01095a;
case 0x0c01095cu: goto P_0c01095c;
case 0x0c01095eu: goto P_0c01095e;
case 0x0c010960u: goto P_0c010960;
case 0x0c010962u: goto P_0c010962;
case 0x0c010964u: goto P_0c010964;
case 0x0c010966u: goto P_0c010966;
case 0x0c010968u: goto P_0c010968;
case 0x0c01096au: goto P_0c01096a;
case 0x0c01096cu: goto P_0c01096c;
case 0x0c01096eu: goto P_0c01096e;
case 0x0c010970u: goto P_0c010970;
case 0x0c010972u: goto P_0c010972;
case 0x0c010974u: goto P_0c010974;
case 0x0c010976u: goto P_0c010976;
case 0x0c010978u: goto P_0c010978;
case 0x0c01097au: goto P_0c01097a;
case 0x0c01097cu: goto P_0c01097c;
case 0x0c01097eu: goto P_0c01097e;
case 0x0c010980u: goto P_0c010980;
case 0x0c010982u: goto P_0c010982;
case 0x0c010984u: goto P_0c010984;
case 0x0c010986u: goto P_0c010986;
case 0x0c010988u: goto P_0c010988;
case 0x0c01098au: goto P_0c01098a;
case 0x0c010f3cu: goto P_0c010f3c;
case 0x0c010f3eu: goto P_0c010f3e;
case 0x0c010f40u: goto P_0c010f40;
case 0x0c0113b4u: goto P_0c0113b4;
case 0x0c0113b6u: goto P_0c0113b6;
case 0x0c0113b8u: goto P_0c0113b8;
case 0x0c0113bau: goto P_0c0113ba;
case 0x0c0113bcu: goto P_0c0113bc;
case 0x0c0113beu: goto P_0c0113be;
case 0x0c0113c0u: goto P_0c0113c0;
case 0x0c011a24u: goto P_0c011a24;
case 0x0c011a26u: goto P_0c011a26;
case 0x0c011a28u: goto P_0c011a28;
case 0x0c011a2au: goto P_0c011a2a;
case 0x0c011a2cu: goto P_0c011a2c;
case 0x0c011a2eu: goto P_0c011a2e;
case 0x0c011a30u: goto P_0c011a30;
case 0x0c011a32u: goto P_0c011a32;
case 0x0c011a34u: goto P_0c011a34;
case 0x0c011a36u: goto P_0c011a36;
case 0x0c011a38u: goto P_0c011a38;
case 0x0c011a3au: goto P_0c011a3a;
case 0x0c011a3cu: goto P_0c011a3c;
case 0x0c011a3eu: goto P_0c011a3e;
case 0x0c011a40u: goto P_0c011a40;
case 0x0c011a42u: goto P_0c011a42;
case 0x0c011a44u: goto P_0c011a44;
case 0x0c011a46u: goto P_0c011a46;
case 0x0c011a48u: goto P_0c011a48;
case 0x0c011a4au: goto P_0c011a4a;
case 0x0c011a4cu: goto P_0c011a4c;
case 0x0c011a4eu: goto P_0c011a4e;
case 0x0c011a50u: goto P_0c011a50;
case 0x0c011a52u: goto P_0c011a52;
case 0x0c011a54u: goto P_0c011a54;
case 0x0c011a56u: goto P_0c011a56;
case 0x0c011a58u: goto P_0c011a58;
case 0x0c011a5au: goto P_0c011a5a;
case 0x0c011a5cu: goto P_0c011a5c;
case 0x0c011a5eu: goto P_0c011a5e;
case 0x0c011a60u: goto P_0c011a60;
case 0x0c011a62u: goto P_0c011a62;
case 0x0c011a64u: goto P_0c011a64;
case 0x0c011a66u: goto P_0c011a66;
case 0x0c011a68u: goto P_0c011a68;
case 0x0c011a6au: goto P_0c011a6a;
case 0x0c035270u: goto P_0c035270;
case 0x0c035272u: goto P_0c035272;
case 0x0c035274u: goto P_0c035274;
case 0x0c035276u: goto P_0c035276;
case 0x0c035278u: goto P_0c035278;
case 0x0c03527au: goto P_0c03527a;
case 0x0c03527cu: goto P_0c03527c;
case 0x0c03527eu: goto P_0c03527e;
case 0x0c035280u: goto P_0c035280;
case 0x0c035282u: goto P_0c035282;
case 0x0c035284u: goto P_0c035284;
case 0x0c035286u: goto P_0c035286;
case 0x0c035288u: goto P_0c035288;
case 0x0c03528au: goto P_0c03528a;
case 0x0c03528cu: goto P_0c03528c;
case 0x0c03528eu: goto P_0c03528e;
case 0x0c035290u: goto P_0c035290;
case 0x0c035292u: goto P_0c035292;
case 0x0c035294u: goto P_0c035294;
case 0x0c035296u: goto P_0c035296;
case 0x0c035298u: goto P_0c035298;
case 0x0c03529au: goto P_0c03529a;
case 0x0c03529cu: goto P_0c03529c;
case 0x0c03529eu: goto P_0c03529e;
case 0x0c0352a0u: goto P_0c0352a0;
case 0x0c0352a2u: goto P_0c0352a2;
case 0x0c0352a4u: goto P_0c0352a4;
case 0x0c0352a6u: goto P_0c0352a6;
case 0x0c0352a8u: goto P_0c0352a8;
case 0x0c0352aau: goto P_0c0352aa;
case 0x0c0352acu: goto P_0c0352ac;
case 0x0c0352aeu: goto P_0c0352ae;
case 0x0c0352b0u: goto P_0c0352b0;
case 0x0c0352b2u: goto P_0c0352b2;
case 0x0c0352b4u: goto P_0c0352b4;
case 0x0c0352b6u: goto P_0c0352b6;
case 0x0c0352b8u: goto P_0c0352b8;
case 0x0c0352bau: goto P_0c0352ba;
case 0x0c0352bcu: goto P_0c0352bc;
case 0x0c0352beu: goto P_0c0352be;
case 0x0c0352c0u: goto P_0c0352c0;
case 0x0c0352c2u: goto P_0c0352c2;
case 0x0c0352c4u: goto P_0c0352c4;
case 0x0c0352c6u: goto P_0c0352c6;
case 0x0c0352c8u: goto P_0c0352c8;
case 0x0c0352cau: goto P_0c0352ca;
case 0x0c0352ccu: goto P_0c0352cc;
case 0x0c0352ceu: goto P_0c0352ce;
case 0x0c0352d0u: goto P_0c0352d0;
case 0x0c0352d2u: goto P_0c0352d2;
case 0x0c0352d4u: goto P_0c0352d4;
case 0x0c0352d6u: goto P_0c0352d6;
case 0x0c0352d8u: goto P_0c0352d8;
case 0x0c035306u: goto P_0c035306;
case 0x0c035308u: goto P_0c035308;
case 0x0c03530au: goto P_0c03530a;
case 0x0c03530cu: goto P_0c03530c;
case 0x0c03530eu: goto P_0c03530e;
case 0x0c035310u: goto P_0c035310;
case 0x0c035312u: goto P_0c035312;
case 0x0c035314u: goto P_0c035314;
case 0x0c035316u: goto P_0c035316;
case 0x0c035318u: goto P_0c035318;
case 0x0c03531au: goto P_0c03531a;
case 0x0c03531cu: goto P_0c03531c;
case 0x0c03531eu: goto P_0c03531e;
case 0x0c035320u: goto P_0c035320;
case 0x0c035322u: goto P_0c035322;
case 0x0c035324u: goto P_0c035324;
case 0x0c035326u: goto P_0c035326;
case 0x0c035328u: goto P_0c035328;
case 0x0c03532au: goto P_0c03532a;
case 0x0c03532cu: goto P_0c03532c;
case 0x0c03532eu: goto P_0c03532e;
case 0x0c035330u: goto P_0c035330;
case 0x0c035332u: goto P_0c035332;
case 0x0c035334u: goto P_0c035334;
case 0x0c035336u: goto P_0c035336;
case 0x0c035338u: goto P_0c035338;
case 0x0c03533au: goto P_0c03533a;
case 0x0c03533cu: goto P_0c03533c;
case 0x0c03533eu: goto P_0c03533e;
case 0x0c035340u: goto P_0c035340;
case 0x0c035342u: goto P_0c035342;
case 0x0c035344u: goto P_0c035344;
case 0x0c035346u: goto P_0c035346;
case 0x0c035348u: goto P_0c035348;
case 0x0c03534au: goto P_0c03534a;
case 0x0c03534cu: goto P_0c03534c;
case 0x0c03534eu: goto P_0c03534e;
case 0x0c035350u: goto P_0c035350;
case 0x0c035352u: goto P_0c035352;
case 0x0c035354u: goto P_0c035354;
case 0x0c035356u: goto P_0c035356;
case 0x0c035358u: goto P_0c035358;
case 0x0c03535au: goto P_0c03535a;
case 0x0c03535cu: goto P_0c03535c;
case 0x0c03535eu: goto P_0c03535e;
case 0x0c035360u: goto P_0c035360;
case 0x0c035362u: goto P_0c035362;
case 0x0c035364u: goto P_0c035364;
case 0x0c035366u: goto P_0c035366;
case 0x0c035368u: goto P_0c035368;
case 0x0c03536au: goto P_0c03536a;
case 0x0c035518u: goto P_0c035518;
case 0x0c03551au: goto P_0c03551a;
case 0x0c03551cu: goto P_0c03551c;
case 0x0c03551eu: goto P_0c03551e;
case 0x0c035520u: goto P_0c035520;
case 0x0c035522u: goto P_0c035522;
case 0x0c035524u: goto P_0c035524;
case 0x0c035526u: goto P_0c035526;
case 0x0c035528u: goto P_0c035528;
case 0x0c03552au: goto P_0c03552a;
case 0x0c03552cu: goto P_0c03552c;
case 0x0c03552eu: goto P_0c03552e;
case 0x0c035530u: goto P_0c035530;
case 0x0c035532u: goto P_0c035532;
case 0x0c035534u: goto P_0c035534;
case 0x0c035536u: goto P_0c035536;
case 0x0c035538u: goto P_0c035538;
case 0x0c03553au: goto P_0c03553a;
case 0x0c03553cu: goto P_0c03553c;
case 0x0c03553eu: goto P_0c03553e;
case 0x0c035540u: goto P_0c035540;
case 0x0c035542u: goto P_0c035542;
case 0x0c035544u: goto P_0c035544;
case 0x0c035546u: goto P_0c035546;
case 0x0c035548u: goto P_0c035548;
case 0x0c03554au: goto P_0c03554a;
case 0x0c03554cu: goto P_0c03554c;
case 0x0c03554eu: goto P_0c03554e;
case 0x0c035550u: goto P_0c035550;
case 0x0c035552u: goto P_0c035552;
case 0x0c035554u: goto P_0c035554;
case 0x0c035556u: goto P_0c035556;
case 0x0c035558u: goto P_0c035558;
case 0x0c03555au: goto P_0c03555a;
case 0x0c03555cu: goto P_0c03555c;
case 0x0c03555eu: goto P_0c03555e;
case 0x0c035560u: goto P_0c035560;
case 0x0c035562u: goto P_0c035562;
case 0x0c035564u: goto P_0c035564;
case 0x0c035566u: goto P_0c035566;
case 0x0c035568u: goto P_0c035568;
case 0x0c03556au: goto P_0c03556a;
case 0x0c03556cu: goto P_0c03556c;
case 0x0c03556eu: goto P_0c03556e;
case 0x0c035570u: goto P_0c035570;
case 0x0c035572u: goto P_0c035572;
case 0x0c035574u: goto P_0c035574;
case 0x0c035576u: goto P_0c035576;
case 0x0c035578u: goto P_0c035578;
case 0x0c03557au: goto P_0c03557a;
case 0x0c03557cu: goto P_0c03557c;
case 0x0c03557eu: goto P_0c03557e;
case 0x0c035580u: goto P_0c035580;
case 0x0c035582u: goto P_0c035582;
case 0x0c035584u: goto P_0c035584;
case 0x0c035586u: goto P_0c035586;
case 0x0c035588u: goto P_0c035588;
case 0x0c03558au: goto P_0c03558a;
case 0x0c03558cu: goto P_0c03558c;
case 0x0c039748u: goto P_0c039748;
case 0x0c03974au: goto P_0c03974a;
case 0x0c03974cu: goto P_0c03974c;
case 0x0c03974eu: goto P_0c03974e;
case 0x0c039750u: goto P_0c039750;
case 0x0c039752u: goto P_0c039752;
case 0x0c039754u: goto P_0c039754;
case 0x0c039756u: goto P_0c039756;
case 0x0c039758u: goto P_0c039758;
case 0x0c03975au: goto P_0c03975a;
case 0x0c03975cu: goto P_0c03975c;
case 0x0c03975eu: goto P_0c03975e;
case 0x0c039760u: goto P_0c039760;
case 0x0c039762u: goto P_0c039762;
case 0x0c039764u: goto P_0c039764;
case 0x0c039766u: goto P_0c039766;
case 0x0c039768u: goto P_0c039768;
case 0x0c03976au: goto P_0c03976a;
case 0x0c03976cu: goto P_0c03976c;
case 0x0c03976eu: goto P_0c03976e;
case 0x0c039770u: goto P_0c039770;
case 0x0c039772u: goto P_0c039772;
case 0x0c039774u: goto P_0c039774;
case 0x0c039776u: goto P_0c039776;
case 0x0c039778u: goto P_0c039778;
case 0x0c03977au: goto P_0c03977a;
case 0x0c03977cu: goto P_0c03977c;
case 0x0c03977eu: goto P_0c03977e;
case 0x0c039780u: goto P_0c039780;
case 0x0c039782u: goto P_0c039782;
case 0x0c039784u: goto P_0c039784;
case 0x0c039786u: goto P_0c039786;
case 0x0c039788u: goto P_0c039788;
case 0x0c03978au: goto P_0c03978a;
case 0x0c03978cu: goto P_0c03978c;
case 0x0c03978eu: goto P_0c03978e;
case 0x0c039790u: goto P_0c039790;
case 0x0c039792u: goto P_0c039792;
case 0x0c039794u: goto P_0c039794;
case 0x0c039cb4u: goto P_0c039cb4;
case 0x0c039cb6u: goto P_0c039cb6;
case 0x0c039cb8u: goto P_0c039cb8;
case 0x0c039cbau: goto P_0c039cba;
case 0x0c039cbcu: goto P_0c039cbc;
case 0x0c039cbeu: goto P_0c039cbe;
case 0x0c039cc0u: goto P_0c039cc0;
case 0x0c039cc2u: goto P_0c039cc2;
case 0x0c039cc4u: goto P_0c039cc4;
case 0x0c039cc6u: goto P_0c039cc6;
case 0x0c039cc8u: goto P_0c039cc8;
case 0x0c039ccau: goto P_0c039cca;
case 0x0c039cccu: goto P_0c039ccc;
case 0x0c039cceu: goto P_0c039cce;
case 0x0c039cd0u: goto P_0c039cd0;
case 0x0c039ce0u: goto P_0c039ce0;
case 0x0c039ce2u: goto P_0c039ce2;
case 0x0c039ce4u: goto P_0c039ce4;
case 0x0c039cf0u: goto P_0c039cf0;
case 0x0c039cf2u: goto P_0c039cf2;
case 0x0c039cf4u: goto P_0c039cf4;
case 0x0c039d00u: goto P_0c039d00;
case 0x0c039d02u: goto P_0c039d02;
case 0x0c039d04u: goto P_0c039d04;
case 0x0c039d70u: goto P_0c039d70;
case 0x0c039d72u: goto P_0c039d72;
case 0x0c039d74u: goto P_0c039d74;
case 0x0c039d76u: goto P_0c039d76;
case 0x0c039d78u: goto P_0c039d78;
case 0x0c039d7au: goto P_0c039d7a;
case 0x0c039d7cu: goto P_0c039d7c;
case 0x0c039d7eu: goto P_0c039d7e;
case 0x0c039d80u: goto P_0c039d80;
case 0x0c039d82u: goto P_0c039d82;
case 0x0c039d84u: goto P_0c039d84;
case 0x0c039d86u: goto P_0c039d86;
case 0x0c039d90u: goto P_0c039d90;
case 0x0c039d92u: goto P_0c039d92;
case 0x0c039d94u: goto P_0c039d94;
case 0x0c039d96u: goto P_0c039d96;
case 0x0c039d98u: goto P_0c039d98;
case 0x0c03aa9cu: goto P_0c03aa9c;
case 0x0c03aa9eu: goto P_0c03aa9e;
case 0x0c03aaa0u: goto P_0c03aaa0;
case 0x0c03aaa2u: goto P_0c03aaa2;
case 0x0c03aaa4u: goto P_0c03aaa4;
case 0x0c03aaa6u: goto P_0c03aaa6;
case 0x0c03aaa8u: goto P_0c03aaa8;
case 0x0c03aaaau: goto P_0c03aaaa;
case 0x0c03aaacu: goto P_0c03aaac;
case 0x0c03aaaeu: goto P_0c03aaae;
case 0x0c03aab0u: goto P_0c03aab0;
case 0x0c03aab2u: goto P_0c03aab2;
case 0x0c03aab4u: goto P_0c03aab4;
case 0x0c03aab6u: goto P_0c03aab6;
case 0x0c03aab8u: goto P_0c03aab8;
case 0x0c03aabau: goto P_0c03aaba;
case 0x0c03aabcu: goto P_0c03aabc;
case 0x0c03aabeu: goto P_0c03aabe;
case 0x0c03aac0u: goto P_0c03aac0;
case 0x0c03aac2u: goto P_0c03aac2;
case 0x0c03aac4u: goto P_0c03aac4;
case 0x0c03aac6u: goto P_0c03aac6;
case 0x0c03aac8u: goto P_0c03aac8;
case 0x0c03aacau: goto P_0c03aaca;
case 0x0c03aaccu: goto P_0c03aacc;
case 0x0c03aaceu: goto P_0c03aace;
case 0x0c03aad0u: goto P_0c03aad0;
case 0x0c03aad2u: goto P_0c03aad2;
case 0x0c03aad4u: goto P_0c03aad4;
case 0x0c03aad6u: goto P_0c03aad6;
case 0x0c03aad8u: goto P_0c03aad8;
case 0x0c03aadau: goto P_0c03aada;
case 0x0c03aadcu: goto P_0c03aadc;
case 0x0c03aadeu: goto P_0c03aade;
case 0x0c03aae0u: goto P_0c03aae0;
case 0x0c03aae2u: goto P_0c03aae2;
case 0x0c03aae4u: goto P_0c03aae4;
case 0x0c03aae6u: goto P_0c03aae6;
case 0x0c03aae8u: goto P_0c03aae8;
case 0x0c03aaeau: goto P_0c03aaea;
case 0x0c03aaecu: goto P_0c03aaec;
case 0x0c03aaeeu: goto P_0c03aaee;
case 0x0c03aaf0u: goto P_0c03aaf0;
case 0x0c03aaf2u: goto P_0c03aaf2;
case 0x0c03aaf4u: goto P_0c03aaf4;
case 0x0c03aaf6u: goto P_0c03aaf6;
case 0x0c03aaf8u: goto P_0c03aaf8;
case 0x0c03aafau: goto P_0c03aafa;
case 0x0c03aafcu: goto P_0c03aafc;
case 0x0c03aafeu: goto P_0c03aafe;
case 0x0c03ab00u: goto P_0c03ab00;
case 0x0c03ab02u: goto P_0c03ab02;
case 0x0c03ab04u: goto P_0c03ab04;
case 0x0c03ab06u: goto P_0c03ab06;
case 0x0c03ab08u: goto P_0c03ab08;
case 0x0c03ab0au: goto P_0c03ab0a;
case 0x0c03ab0cu: goto P_0c03ab0c;
case 0x0c03ab0eu: goto P_0c03ab0e;
case 0x0c03ab10u: goto P_0c03ab10;
case 0x0c03ab12u: goto P_0c03ab12;
case 0x0c03ab14u: goto P_0c03ab14;
case 0x0c0432e2u: goto P_0c0432e2;
case 0x0c0432e4u: goto P_0c0432e4;
case 0x0c0432e6u: goto P_0c0432e6;
case 0x0c0432e8u: goto P_0c0432e8;
case 0x0c0432eau: goto P_0c0432ea;
case 0x0c0432ecu: goto P_0c0432ec;
case 0x0c0432eeu: goto P_0c0432ee;
case 0x0c0432f0u: goto P_0c0432f0;
case 0x0c0432f2u: goto P_0c0432f2;
case 0x0c0432f4u: goto P_0c0432f4;
case 0x0c0432f6u: goto P_0c0432f6;
case 0x0c0432f8u: goto P_0c0432f8;
case 0x0c0432fau: goto P_0c0432fa;
case 0x0c0432fcu: goto P_0c0432fc;
case 0x0c0432feu: goto P_0c0432fe;
case 0x0c043300u: goto P_0c043300;
case 0x0c043302u: goto P_0c043302;
case 0x0c043304u: goto P_0c043304;
case 0x0c043306u: goto P_0c043306;
case 0x0c043308u: goto P_0c043308;
case 0x0c04330au: goto P_0c04330a;
case 0x0c04330cu: goto P_0c04330c;
case 0x0c04330eu: goto P_0c04330e;
case 0x0c043310u: goto P_0c043310;
case 0x0c043312u: goto P_0c043312;
case 0x0c043314u: goto P_0c043314;
case 0x0c043316u: goto P_0c043316;
case 0x0c043318u: goto P_0c043318;
case 0x0c04331au: goto P_0c04331a;
case 0x0c04331cu: goto P_0c04331c;
case 0x0c04331eu: goto P_0c04331e;
case 0x0c043320u: goto P_0c043320;
case 0x0c043322u: goto P_0c043322;
case 0x0c043324u: goto P_0c043324;
case 0x0c043344u: goto P_0c043344;
case 0x0c043346u: goto P_0c043346;
case 0x0c043348u: goto P_0c043348;
case 0x0c04334au: goto P_0c04334a;
case 0x0c04334cu: goto P_0c04334c;
case 0x0c04334eu: goto P_0c04334e;
case 0x0c043350u: goto P_0c043350;
case 0x0c043352u: goto P_0c043352;
case 0x0c043354u: goto P_0c043354;
case 0x0c043356u: goto P_0c043356;
case 0x0c043358u: goto P_0c043358;
case 0x0c04335au: goto P_0c04335a;
case 0x0c04335cu: goto P_0c04335c;
case 0x0c0433aeu: goto P_0c0433ae;
case 0x0c0433b0u: goto P_0c0433b0;
case 0x0c0433b2u: goto P_0c0433b2;
case 0x0c0433b4u: goto P_0c0433b4;
case 0x0c0433b6u: goto P_0c0433b6;
case 0x0c0433b8u: goto P_0c0433b8;
case 0x0c0433bau: goto P_0c0433ba;
case 0x0c047810u: goto P_0c047810;
case 0x0c047812u: goto P_0c047812;
case 0x0c047814u: goto P_0c047814;
case 0x0c047816u: goto P_0c047816;
case 0x0c047818u: goto P_0c047818;
case 0x0c04781au: goto P_0c04781a;
case 0x0c04781cu: goto P_0c04781c;
case 0x0c04781eu: goto P_0c04781e;
case 0x0c047820u: goto P_0c047820;
case 0x0c047822u: goto P_0c047822;
case 0x0c047824u: goto P_0c047824;
case 0x0c047826u: goto P_0c047826;
case 0x0c047828u: goto P_0c047828;
case 0x0c04782au: goto P_0c04782a;
case 0x0c04782cu: goto P_0c04782c;
case 0x0c04782eu: goto P_0c04782e;
case 0x0c047830u: goto P_0c047830;
case 0x0c047832u: goto P_0c047832;
case 0x0c047834u: goto P_0c047834;
case 0x0c047836u: goto P_0c047836;
case 0x0c047838u: goto P_0c047838;
case 0x0c04783au: goto P_0c04783a;
case 0x0c04783cu: goto P_0c04783c;
case 0x0c04783eu: goto P_0c04783e;
case 0x0c047840u: goto P_0c047840;
case 0x0c047842u: goto P_0c047842;
case 0x0c047844u: goto P_0c047844;
case 0x0c047846u: goto P_0c047846;
case 0x0c047848u: goto P_0c047848;
case 0x0c04784au: goto P_0c04784a;
case 0x0c04784cu: goto P_0c04784c;
case 0x0c04784eu: goto P_0c04784e;
case 0x0c047850u: goto P_0c047850;
case 0x0c047852u: goto P_0c047852;
case 0x0c047854u: goto P_0c047854;
case 0x0c047856u: goto P_0c047856;
case 0x0c047858u: goto P_0c047858;
case 0x0c04785au: goto P_0c04785a;
case 0x0c04785cu: goto P_0c04785c;
case 0x0c04785eu: goto P_0c04785e;
case 0x0c047860u: goto P_0c047860;
case 0x0c047862u: goto P_0c047862;
case 0x0c047864u: goto P_0c047864;
case 0x0c047866u: goto P_0c047866;
case 0x0c047868u: goto P_0c047868;
case 0x0c04786au: goto P_0c04786a;
case 0x0c04786cu: goto P_0c04786c;
case 0x0c04786eu: goto P_0c04786e;
case 0x0c047870u: goto P_0c047870;
case 0x0c047872u: goto P_0c047872;
case 0x0c047874u: goto P_0c047874;
case 0x0c047876u: goto P_0c047876;
case 0x0c047878u: goto P_0c047878;
case 0x0c04787au: goto P_0c04787a;
case 0x0c04787cu: goto P_0c04787c;
case 0x0c04787eu: goto P_0c04787e;
case 0x0c047880u: goto P_0c047880;
case 0x0c047882u: goto P_0c047882;
case 0x0c047884u: goto P_0c047884;
case 0x0c047886u: goto P_0c047886;
case 0x0c047888u: goto P_0c047888;
case 0x0c04788au: goto P_0c04788a;
case 0x0c04788cu: goto P_0c04788c;
case 0x0c04788eu: goto P_0c04788e;
case 0x0c047890u: goto P_0c047890;
case 0x0c047892u: goto P_0c047892;
case 0x0c047894u: goto P_0c047894;
case 0x0c047896u: goto P_0c047896;
case 0x0c047898u: goto P_0c047898;
case 0x0c04789au: goto P_0c04789a;
case 0x0c04789cu: goto P_0c04789c;
case 0x0c04789eu: goto P_0c04789e;
case 0x0c0478a0u: goto P_0c0478a0;
case 0x0c0478a2u: goto P_0c0478a2;
case 0x0c0478a4u: goto P_0c0478a4;
case 0x0c0478a6u: goto P_0c0478a6;
case 0x0c0478a8u: goto P_0c0478a8;
case 0x0c0478aau: goto P_0c0478aa;
case 0x0c0478acu: goto P_0c0478ac;
case 0x0c0478aeu: goto P_0c0478ae;
case 0x0c0478b0u: goto P_0c0478b0;
case 0x0c0478b2u: goto P_0c0478b2;
case 0x0c0478b4u: goto P_0c0478b4;
case 0x0c0478b6u: goto P_0c0478b6;
case 0x0c0478b8u: goto P_0c0478b8;
case 0x0c0478bau: goto P_0c0478ba;
case 0x0c0478bcu: goto P_0c0478bc;
case 0x0c0478c0u: goto P_0c0478c0;
case 0x0c0478c2u: goto P_0c0478c2;
case 0x0c0478c4u: goto P_0c0478c4;
case 0x0c0478c6u: goto P_0c0478c6;
case 0x0c0478c8u: goto P_0c0478c8;
case 0x0c0478cau: goto P_0c0478ca;
case 0x0c0478ccu: goto P_0c0478cc;
case 0x0c0478ceu: goto P_0c0478ce;
case 0x0c0478d0u: goto P_0c0478d0;
case 0x0c0478d2u: goto P_0c0478d2;
case 0x0c0478d4u: goto P_0c0478d4;
case 0x0c0478d6u: goto P_0c0478d6;
case 0x0c0478d8u: goto P_0c0478d8;
case 0x0c0478dau: goto P_0c0478da;
case 0x0c0478dcu: goto P_0c0478dc;
case 0x0c0478deu: goto P_0c0478de;
case 0x0c0478e0u: goto P_0c0478e0;
case 0x0c0478e2u: goto P_0c0478e2;
case 0x0c0478e4u: goto P_0c0478e4;
case 0x0c0478e6u: goto P_0c0478e6;
case 0x0c0478e8u: goto P_0c0478e8;
case 0x0c0478eau: goto P_0c0478ea;
case 0x0c0478ecu: goto P_0c0478ec;
case 0x0c0478eeu: goto P_0c0478ee;
case 0x0c0478f0u: goto P_0c0478f0;
case 0x0c0478f2u: goto P_0c0478f2;
case 0x0c0478f4u: goto P_0c0478f4;
case 0x0c0478f6u: goto P_0c0478f6;
case 0x0c0478f8u: goto P_0c0478f8;
case 0x0c0478fau: goto P_0c0478fa;
case 0x0c0478fcu: goto P_0c0478fc;
case 0x0c0478feu: goto P_0c0478fe;
case 0x0c047900u: goto P_0c047900;
case 0x0c047902u: goto P_0c047902;
case 0x0c047904u: goto P_0c047904;
case 0x0c047906u: goto P_0c047906;
case 0x0c047908u: goto P_0c047908;
case 0x0c04790au: goto P_0c04790a;
case 0x0c04790cu: goto P_0c04790c;
case 0x0c04790eu: goto P_0c04790e;
case 0x0c047910u: goto P_0c047910;
case 0x0c047912u: goto P_0c047912;
case 0x0c047914u: goto P_0c047914;
case 0x0c047916u: goto P_0c047916;
case 0x0c047918u: goto P_0c047918;
case 0x0c04791au: goto P_0c04791a;
case 0x0c04791cu: goto P_0c04791c;
case 0x0c04791eu: goto P_0c04791e;
case 0x0c047920u: goto P_0c047920;
case 0x0c047922u: goto P_0c047922;
case 0x0c047924u: goto P_0c047924;
case 0x0c047928u: goto P_0c047928;
case 0x0c04792au: goto P_0c04792a;
case 0x0c04792cu: goto P_0c04792c;
case 0x0c04792eu: goto P_0c04792e;
case 0x0c047930u: goto P_0c047930;
case 0x0c047932u: goto P_0c047932;
case 0x0c047934u: goto P_0c047934;
case 0x0c047936u: goto P_0c047936;
case 0x0c047938u: goto P_0c047938;
case 0x0c04793au: goto P_0c04793a;
case 0x0c04793cu: goto P_0c04793c;
case 0x0c04793eu: goto P_0c04793e;
case 0x0c047940u: goto P_0c047940;
case 0x0c047942u: goto P_0c047942;
case 0x0c047944u: goto P_0c047944;
case 0x0c047946u: goto P_0c047946;
case 0x0c047948u: goto P_0c047948;
case 0x0c04794au: goto P_0c04794a;
case 0x0c04794cu: goto P_0c04794c;
case 0x0c04794eu: goto P_0c04794e;
case 0x0c047950u: goto P_0c047950;
case 0x0c047952u: goto P_0c047952;
case 0x0c047954u: goto P_0c047954;
case 0x0c047956u: goto P_0c047956;
case 0x0c047958u: goto P_0c047958;
case 0x0c04795au: goto P_0c04795a;
case 0x0c04795cu: goto P_0c04795c;
case 0x0c04795eu: goto P_0c04795e;
case 0x0c047960u: goto P_0c047960;
case 0x0c047962u: goto P_0c047962;
case 0x0c047964u: goto P_0c047964;
case 0x0c047966u: goto P_0c047966;
case 0x0c047968u: goto P_0c047968;
case 0x0c04796au: goto P_0c04796a;
case 0x0c04796cu: goto P_0c04796c;
case 0x0c04796eu: goto P_0c04796e;
case 0x0c047970u: goto P_0c047970;
case 0x0c047972u: goto P_0c047972;
case 0x0c047974u: goto P_0c047974;
case 0x0c047976u: goto P_0c047976;
case 0x0c047978u: goto P_0c047978;
case 0x0c04797au: goto P_0c04797a;
case 0x0c04797cu: goto P_0c04797c;
case 0x0c04797eu: goto P_0c04797e;
case 0x0c047980u: goto P_0c047980;
case 0x0c047982u: goto P_0c047982;
case 0x0c047984u: goto P_0c047984;
case 0x0c047986u: goto P_0c047986;
case 0x0c047988u: goto P_0c047988;
case 0x0c04798au: goto P_0c04798a;
case 0x0c04798cu: goto P_0c04798c;
case 0x0c04798eu: goto P_0c04798e;
case 0x0c047990u: goto P_0c047990;
case 0x0c047992u: goto P_0c047992;
case 0x0c047994u: goto P_0c047994;
case 0x0c047996u: goto P_0c047996;
case 0x0c047998u: goto P_0c047998;
case 0x0c04799au: goto P_0c04799a;
case 0x0c04799cu: goto P_0c04799c;
case 0x0c04799eu: goto P_0c04799e;
case 0x0c0479a0u: goto P_0c0479a0;
case 0x0c0479a2u: goto P_0c0479a2;
case 0x0c0479a4u: goto P_0c0479a4;
case 0x0c0479a6u: goto P_0c0479a6;
case 0x0c0479a8u: goto P_0c0479a8;
case 0x0c0479aau: goto P_0c0479aa;
case 0x0c0479acu: goto P_0c0479ac;
case 0x0c0479aeu: goto P_0c0479ae;
case 0x0c0479b0u: goto P_0c0479b0;
case 0x0c0479b2u: goto P_0c0479b2;
case 0x0c0479b4u: goto P_0c0479b4;
case 0x0c0479b6u: goto P_0c0479b6;
case 0x0c0479b8u: goto P_0c0479b8;
case 0x0c0479bau: goto P_0c0479ba;
case 0x0c0479bcu: goto P_0c0479bc;
case 0x0c0479beu: goto P_0c0479be;
case 0x0c0479c0u: goto P_0c0479c0;
case 0x0c0479c2u: goto P_0c0479c2;
case 0x0c0479c4u: goto P_0c0479c4;
case 0x0c0479c8u: goto P_0c0479c8;
case 0x0c0479cau: goto P_0c0479ca;
case 0x0c0479ccu: goto P_0c0479cc;
case 0x0c0479ceu: goto P_0c0479ce;
case 0x0c0479d0u: goto P_0c0479d0;
case 0x0c0479d2u: goto P_0c0479d2;
case 0x0c0479d4u: goto P_0c0479d4;
case 0x0c0479d6u: goto P_0c0479d6;
case 0x0c0479d8u: goto P_0c0479d8;
case 0x0c0479dau: goto P_0c0479da;
case 0x0c0479dcu: goto P_0c0479dc;
case 0x0c0479deu: goto P_0c0479de;
case 0x0c0479e0u: goto P_0c0479e0;
case 0x0c0479e4u: goto P_0c0479e4;
case 0x0c0479e6u: goto P_0c0479e6;
case 0x0c0479e8u: goto P_0c0479e8;
case 0x0c0479eau: goto P_0c0479ea;
case 0x0c0479ecu: goto P_0c0479ec;
case 0x0c0479eeu: goto P_0c0479ee;
case 0x0c0479f0u: goto P_0c0479f0;
case 0x0c0479f2u: goto P_0c0479f2;
case 0x0c0479f4u: goto P_0c0479f4;
case 0x0c0479f6u: goto P_0c0479f6;
case 0x0c0479f8u: goto P_0c0479f8;
case 0x0c0479fau: goto P_0c0479fa;
case 0x0c0479fcu: goto P_0c0479fc;
case 0x0c0479feu: goto P_0c0479fe;
case 0x0c047a00u: goto P_0c047a00;
case 0x0c047a02u: goto P_0c047a02;
case 0x0c047a04u: goto P_0c047a04;
case 0x0c047a06u: goto P_0c047a06;
case 0x0c047a08u: goto P_0c047a08;
case 0x0c047a0au: goto P_0c047a0a;
case 0x0c047a0cu: goto P_0c047a0c;
case 0x0c047a0eu: goto P_0c047a0e;
case 0x0c047a10u: goto P_0c047a10;
case 0x0c047a14u: goto P_0c047a14;
case 0x0c047a16u: goto P_0c047a16;
case 0x0c047a18u: goto P_0c047a18;
case 0x0c047a1au: goto P_0c047a1a;
case 0x0c047a1cu: goto P_0c047a1c;
case 0x0c047a1eu: goto P_0c047a1e;
case 0x0c047a20u: goto P_0c047a20;
case 0x0c047a22u: goto P_0c047a22;
case 0x0c047a24u: goto P_0c047a24;
case 0x0c047a26u: goto P_0c047a26;
case 0x0c047a28u: goto P_0c047a28;
case 0x0c047a2au: goto P_0c047a2a;
case 0x0c047a2cu: goto P_0c047a2c;
case 0x0c047a2eu: goto P_0c047a2e;
case 0x0c047a30u: goto P_0c047a30;
case 0x0c047a32u: goto P_0c047a32;
case 0x0c047a34u: goto P_0c047a34;
case 0x0c047a36u: goto P_0c047a36;
case 0x0c047a38u: goto P_0c047a38;
case 0x0c047a3au: goto P_0c047a3a;
case 0x0c047a3cu: goto P_0c047a3c;
case 0x0c047a3eu: goto P_0c047a3e;
case 0x0c047a40u: goto P_0c047a40;
case 0x0c047a42u: goto P_0c047a42;
case 0x0c047a44u: goto P_0c047a44;
case 0x0c047a46u: goto P_0c047a46;
case 0x0c047a48u: goto P_0c047a48;
case 0x0c047a4au: goto P_0c047a4a;
case 0x0c047a4cu: goto P_0c047a4c;
case 0x0c047a4eu: goto P_0c047a4e;
case 0x0c047a50u: goto P_0c047a50;
case 0x0c047a52u: goto P_0c047a52;
case 0x0c047a54u: goto P_0c047a54;
case 0x0c047a56u: goto P_0c047a56;
case 0x0c047a58u: goto P_0c047a58;
case 0x0c047a5au: goto P_0c047a5a;
case 0x0c047a5cu: goto P_0c047a5c;
case 0x0c047a5eu: goto P_0c047a5e;
case 0x0c047a60u: goto P_0c047a60;
case 0x0c047a62u: goto P_0c047a62;
case 0x0c047a64u: goto P_0c047a64;
case 0x0c047a66u: goto P_0c047a66;
case 0x0c047a68u: goto P_0c047a68;
case 0x0c047a6au: goto P_0c047a6a;
case 0x0c047a6cu: goto P_0c047a6c;
case 0x0c047a6eu: goto P_0c047a6e;
case 0x0c047a70u: goto P_0c047a70;
case 0x0c047a72u: goto P_0c047a72;
case 0x0c047a74u: goto P_0c047a74;
case 0x0c047a76u: goto P_0c047a76;
case 0x0c047a78u: goto P_0c047a78;
case 0x0c047a7au: goto P_0c047a7a;
case 0x0c047a7cu: goto P_0c047a7c;
case 0x0c047a7eu: goto P_0c047a7e;
case 0x0c047a80u: goto P_0c047a80;
case 0x0c047a82u: goto P_0c047a82;
case 0x0c047a84u: goto P_0c047a84;
case 0x0c047a86u: goto P_0c047a86;
case 0x0c047a88u: goto P_0c047a88;
case 0x0c047a8au: goto P_0c047a8a;
case 0x0c047a8cu: goto P_0c047a8c;
case 0x0c047a8eu: goto P_0c047a8e;
case 0x0c047a90u: goto P_0c047a90;
case 0x0c047a92u: goto P_0c047a92;
case 0x0c047a94u: goto P_0c047a94;
case 0x0c047a96u: goto P_0c047a96;
case 0x0c047a98u: goto P_0c047a98;
case 0x0c047a9au: goto P_0c047a9a;
case 0x0c047a9cu: goto P_0c047a9c;
case 0x0c047a9eu: goto P_0c047a9e;
case 0x0c047aa0u: goto P_0c047aa0;
case 0x0c047aa2u: goto P_0c047aa2;
case 0x0c047aa4u: goto P_0c047aa4;
case 0x0c047aa6u: goto P_0c047aa6;
case 0x0c047aa8u: goto P_0c047aa8;
case 0x0c047aaau: goto P_0c047aaa;
case 0x0c047aacu: goto P_0c047aac;
case 0x0c047aaeu: goto P_0c047aae;
case 0x0c047ab0u: goto P_0c047ab0;
case 0x0c047ab4u: goto P_0c047ab4;
case 0x0c047ab6u: goto P_0c047ab6;
case 0x0c047ab8u: goto P_0c047ab8;
case 0x0c047abau: goto P_0c047aba;
case 0x0c047abcu: goto P_0c047abc;
case 0x0c047abeu: goto P_0c047abe;
case 0x0c047ac0u: goto P_0c047ac0;
case 0x0c047ac2u: goto P_0c047ac2;
case 0x0c047ac4u: goto P_0c047ac4;
case 0x0c047ac6u: goto P_0c047ac6;
case 0x0c047ac8u: goto P_0c047ac8;
case 0x0c047acau: goto P_0c047aca;
case 0x0c047accu: goto P_0c047acc;
case 0x0c047aceu: goto P_0c047ace;
case 0x0c047ad0u: goto P_0c047ad0;
case 0x0c047ad4u: goto P_0c047ad4;
case 0x0c047ad6u: goto P_0c047ad6;
case 0x0c0482f0u: goto P_0c0482f0;
case 0x0c0482f2u: goto P_0c0482f2;
case 0x0c0482f4u: goto P_0c0482f4;
case 0x0c0482f6u: goto P_0c0482f6;
case 0x0c0482f8u: goto P_0c0482f8;
case 0x0c0482fau: goto P_0c0482fa;
case 0x0c0482fcu: goto P_0c0482fc;
case 0x0c0482feu: goto P_0c0482fe;
case 0x0c048300u: goto P_0c048300;
case 0x0c048302u: goto P_0c048302;
case 0x0c048304u: goto P_0c048304;
case 0x0c048306u: goto P_0c048306;
case 0x0c048308u: goto P_0c048308;
case 0x0c04830au: goto P_0c04830a;
case 0x0c04830cu: goto P_0c04830c;
case 0x0c04830eu: goto P_0c04830e;
case 0x0c048310u: goto P_0c048310;
case 0x0c048312u: goto P_0c048312;
case 0x0c048314u: goto P_0c048314;
case 0x0c048316u: goto P_0c048316;
case 0x0c048318u: goto P_0c048318;
case 0x0c04831au: goto P_0c04831a;
case 0x0c04831cu: goto P_0c04831c;
case 0x0c04831eu: goto P_0c04831e;
case 0x0c048320u: goto P_0c048320;
case 0x0c048322u: goto P_0c048322;
case 0x0c048324u: goto P_0c048324;
case 0x0c048326u: goto P_0c048326;
case 0x0c048328u: goto P_0c048328;
case 0x0c04832au: goto P_0c04832a;
case 0x0c04832cu: goto P_0c04832c;
case 0x0c04832eu: goto P_0c04832e;
case 0x0c048330u: goto P_0c048330;
case 0x0c048332u: goto P_0c048332;
case 0x0c048334u: goto P_0c048334;
case 0x0c048336u: goto P_0c048336;
case 0x0c048338u: goto P_0c048338;
case 0x0c04833au: goto P_0c04833a;
case 0x0c04833cu: goto P_0c04833c;
case 0x0c04833eu: goto P_0c04833e;
case 0x0c048340u: goto P_0c048340;
case 0x0c048342u: goto P_0c048342;
case 0x0c048344u: goto P_0c048344;
case 0x0c048346u: goto P_0c048346;
case 0x0c048348u: goto P_0c048348;
case 0x0c04834au: goto P_0c04834a;
case 0x0c04834cu: goto P_0c04834c;
case 0x0c04834eu: goto P_0c04834e;
case 0x0c048350u: goto P_0c048350;
case 0x0c048352u: goto P_0c048352;
case 0x0c048354u: goto P_0c048354;
case 0x0c048356u: goto P_0c048356;
case 0x0c048358u: goto P_0c048358;
case 0x0c04835au: goto P_0c04835a;
case 0x0c04835cu: goto P_0c04835c;
case 0x0c04835eu: goto P_0c04835e;
case 0x0c048360u: goto P_0c048360;
case 0x0c048362u: goto P_0c048362;
case 0x0c048364u: goto P_0c048364;
case 0x0c048366u: goto P_0c048366;
case 0x0c048368u: goto P_0c048368;
case 0x0c04836au: goto P_0c04836a;
case 0x0c04836cu: goto P_0c04836c;
case 0x0c04836eu: goto P_0c04836e;
case 0x0c048370u: goto P_0c048370;
case 0x0c048372u: goto P_0c048372;
case 0x0c048374u: goto P_0c048374;
case 0x0c048376u: goto P_0c048376;
case 0x0c048378u: goto P_0c048378;
case 0x0c04837au: goto P_0c04837a;
case 0x0c04837cu: goto P_0c04837c;
case 0x0c04837eu: goto P_0c04837e;
case 0x0c048380u: goto P_0c048380;
case 0x0c048382u: goto P_0c048382;
case 0x0c048384u: goto P_0c048384;
case 0x0c048386u: goto P_0c048386;
case 0x0c048388u: goto P_0c048388;
case 0x0c04838au: goto P_0c04838a;
case 0x0c04838cu: goto P_0c04838c;
case 0x0c04838eu: goto P_0c04838e;
case 0x0c048390u: goto P_0c048390;
case 0x0c048392u: goto P_0c048392;
case 0x0c048394u: goto P_0c048394;
case 0x0c048396u: goto P_0c048396;
case 0x0c048398u: goto P_0c048398;
case 0x0c04839au: goto P_0c04839a;
case 0x0c04839cu: goto P_0c04839c;
case 0x0c0483a0u: goto P_0c0483a0;
case 0x0c0483a2u: goto P_0c0483a2;
case 0x0c0483a4u: goto P_0c0483a4;
case 0x0c0483a6u: goto P_0c0483a6;
case 0x0c0483a8u: goto P_0c0483a8;
case 0x0c0483aau: goto P_0c0483aa;
case 0x0c0483acu: goto P_0c0483ac;
case 0x0c0483aeu: goto P_0c0483ae;
case 0x0c0483b0u: goto P_0c0483b0;
case 0x0c0483b2u: goto P_0c0483b2;
case 0x0c0483b4u: goto P_0c0483b4;
case 0x0c0483b6u: goto P_0c0483b6;
case 0x0c0483b8u: goto P_0c0483b8;
case 0x0c0483bau: goto P_0c0483ba;
case 0x0c0483bcu: goto P_0c0483bc;
case 0x0c0483beu: goto P_0c0483be;
case 0x0c0483c0u: goto P_0c0483c0;
case 0x0c0483c2u: goto P_0c0483c2;
case 0x0c0483c4u: goto P_0c0483c4;
case 0x0c0483c6u: goto P_0c0483c6;
case 0x0c0483c8u: goto P_0c0483c8;
case 0x0c0483cau: goto P_0c0483ca;
case 0x0c0483ccu: goto P_0c0483cc;
case 0x0c0483ceu: goto P_0c0483ce;
case 0x0c0483d0u: goto P_0c0483d0;
case 0x0c0483d2u: goto P_0c0483d2;
case 0x0c0483d4u: goto P_0c0483d4;
case 0x0c0483d6u: goto P_0c0483d6;
case 0x0c0483d8u: goto P_0c0483d8;
case 0x0c0483dau: goto P_0c0483da;
case 0x0c0483dcu: goto P_0c0483dc;
case 0x0c0483deu: goto P_0c0483de;
case 0x0c0483e0u: goto P_0c0483e0;
case 0x0c0483e2u: goto P_0c0483e2;
case 0x0c0483e4u: goto P_0c0483e4;
case 0x0c0483e6u: goto P_0c0483e6;
case 0x0c0483e8u: goto P_0c0483e8;
case 0x0c0483eau: goto P_0c0483ea;
case 0x0c0483ecu: goto P_0c0483ec;
case 0x0c0483eeu: goto P_0c0483ee;
case 0x0c0483f0u: goto P_0c0483f0;
case 0x0c0483f2u: goto P_0c0483f2;
case 0x0c0483f4u: goto P_0c0483f4;
case 0x0c0483f6u: goto P_0c0483f6;
case 0x0c0483f8u: goto P_0c0483f8;
case 0x0c0483fau: goto P_0c0483fa;
case 0x0c0483fcu: goto P_0c0483fc;
case 0x0c0483feu: goto P_0c0483fe;
case 0x0c048400u: goto P_0c048400;
case 0x0c048402u: goto P_0c048402;
case 0x0c048404u: goto P_0c048404;
case 0x0c048408u: goto P_0c048408;
case 0x0c04840au: goto P_0c04840a;
case 0x0c04840cu: goto P_0c04840c;
case 0x0c04840eu: goto P_0c04840e;
case 0x0c048410u: goto P_0c048410;
case 0x0c048412u: goto P_0c048412;
case 0x0c048414u: goto P_0c048414;
case 0x0c048416u: goto P_0c048416;
case 0x0c048418u: goto P_0c048418;
case 0x0c04841au: goto P_0c04841a;
case 0x0c04841cu: goto P_0c04841c;
case 0x0c04841eu: goto P_0c04841e;
case 0x0c048420u: goto P_0c048420;
case 0x0c048422u: goto P_0c048422;
case 0x0c048424u: goto P_0c048424;
case 0x0c048426u: goto P_0c048426;
case 0x0c048428u: goto P_0c048428;
case 0x0c04842au: goto P_0c04842a;
case 0x0c04842cu: goto P_0c04842c;
case 0x0c04842eu: goto P_0c04842e;
case 0x0c048430u: goto P_0c048430;
case 0x0c048432u: goto P_0c048432;
case 0x0c048434u: goto P_0c048434;
case 0x0c048436u: goto P_0c048436;
case 0x0c048438u: goto P_0c048438;
case 0x0c04843au: goto P_0c04843a;
case 0x0c04843cu: goto P_0c04843c;
case 0x0c04843eu: goto P_0c04843e;
case 0x0c048440u: goto P_0c048440;
case 0x0c048442u: goto P_0c048442;
case 0x0c048444u: goto P_0c048444;
case 0x0c048446u: goto P_0c048446;
case 0x0c048448u: goto P_0c048448;
case 0x0c04844au: goto P_0c04844a;
case 0x0c04844cu: goto P_0c04844c;
case 0x0c04844eu: goto P_0c04844e;
case 0x0c048450u: goto P_0c048450;
case 0x0c048452u: goto P_0c048452;
case 0x0c048454u: goto P_0c048454;
case 0x0c048456u: goto P_0c048456;
case 0x0c048458u: goto P_0c048458;
case 0x0c04845au: goto P_0c04845a;
case 0x0c04845cu: goto P_0c04845c;
case 0x0c04845eu: goto P_0c04845e;
case 0x0c048460u: goto P_0c048460;
case 0x0c048462u: goto P_0c048462;
case 0x0c048464u: goto P_0c048464;
case 0x0c048466u: goto P_0c048466;
case 0x0c048468u: goto P_0c048468;
case 0x0c04846au: goto P_0c04846a;
case 0x0c04846cu: goto P_0c04846c;
case 0x0c04846eu: goto P_0c04846e;
case 0x0c048470u: goto P_0c048470;
case 0x0c048472u: goto P_0c048472;
case 0x0c048474u: goto P_0c048474;
case 0x0c048476u: goto P_0c048476;
case 0x0c048478u: goto P_0c048478;
case 0x0c04847au: goto P_0c04847a;
case 0x0c04847cu: goto P_0c04847c;
case 0x0c04847eu: goto P_0c04847e;
case 0x0c048480u: goto P_0c048480;
case 0x0c048482u: goto P_0c048482;
case 0x0c048484u: goto P_0c048484;
case 0x0c048486u: goto P_0c048486;
case 0x0c048488u: goto P_0c048488;
case 0x0c04848au: goto P_0c04848a;
case 0x0c04848cu: goto P_0c04848c;
case 0x0c04848eu: goto P_0c04848e;
case 0x0c048490u: goto P_0c048490;
case 0x0c048492u: goto P_0c048492;
case 0x0c048494u: goto P_0c048494;
case 0x0c048496u: goto P_0c048496;
case 0x0c048498u: goto P_0c048498;
case 0x0c04849au: goto P_0c04849a;
case 0x0c04849cu: goto P_0c04849c;
case 0x0c04849eu: goto P_0c04849e;
case 0x0c0484a0u: goto P_0c0484a0;
case 0x0c0484a2u: goto P_0c0484a2;
case 0x0c0484a4u: goto P_0c0484a4;
case 0x0c0484a8u: goto P_0c0484a8;
case 0x0c0484aau: goto P_0c0484aa;
case 0x0c0484acu: goto P_0c0484ac;
case 0x0c0484aeu: goto P_0c0484ae;
case 0x0c0484b0u: goto P_0c0484b0;
case 0x0c0484b2u: goto P_0c0484b2;
case 0x0c0484b4u: goto P_0c0484b4;
case 0x0c0484b6u: goto P_0c0484b6;
case 0x0c0484b8u: goto P_0c0484b8;
case 0x0c0484bau: goto P_0c0484ba;
case 0x0c0484bcu: goto P_0c0484bc;
case 0x0c0484beu: goto P_0c0484be;
case 0x0c0484c0u: goto P_0c0484c0;
case 0x0c0484c4u: goto P_0c0484c4;
case 0x0c0484c6u: goto P_0c0484c6;
case 0x0c0484c8u: goto P_0c0484c8;
case 0x0c0484cau: goto P_0c0484ca;
case 0x0c0484ccu: goto P_0c0484cc;
case 0x0c0484ceu: goto P_0c0484ce;
case 0x0c0484d0u: goto P_0c0484d0;
case 0x0c0484d2u: goto P_0c0484d2;
case 0x0c0484d4u: goto P_0c0484d4;
case 0x0c0484d6u: goto P_0c0484d6;
case 0x0c0484d8u: goto P_0c0484d8;
case 0x0c0484dau: goto P_0c0484da;
case 0x0c0484dcu: goto P_0c0484dc;
case 0x0c0484deu: goto P_0c0484de;
case 0x0c0484e0u: goto P_0c0484e0;
case 0x0c0484e2u: goto P_0c0484e2;
case 0x0c0484e4u: goto P_0c0484e4;
case 0x0c0484e6u: goto P_0c0484e6;
case 0x0c0484e8u: goto P_0c0484e8;
case 0x0c0484eau: goto P_0c0484ea;
case 0x0c0484ecu: goto P_0c0484ec;
case 0x0c0484eeu: goto P_0c0484ee;
case 0x0c0484f0u: goto P_0c0484f0;
case 0x0c0484f4u: goto P_0c0484f4;
case 0x0c0484f6u: goto P_0c0484f6;
case 0x0c0484f8u: goto P_0c0484f8;
case 0x0c0484fau: goto P_0c0484fa;
case 0x0c0484fcu: goto P_0c0484fc;
case 0x0c0484feu: goto P_0c0484fe;
case 0x0c048500u: goto P_0c048500;
case 0x0c048502u: goto P_0c048502;
case 0x0c048504u: goto P_0c048504;
case 0x0c048506u: goto P_0c048506;
case 0x0c048508u: goto P_0c048508;
case 0x0c04850au: goto P_0c04850a;
case 0x0c04850cu: goto P_0c04850c;
case 0x0c04850eu: goto P_0c04850e;
case 0x0c048510u: goto P_0c048510;
case 0x0c048512u: goto P_0c048512;
case 0x0c048514u: goto P_0c048514;
case 0x0c048516u: goto P_0c048516;
case 0x0c048518u: goto P_0c048518;
case 0x0c04851au: goto P_0c04851a;
case 0x0c04851cu: goto P_0c04851c;
case 0x0c04851eu: goto P_0c04851e;
case 0x0c048520u: goto P_0c048520;
case 0x0c048522u: goto P_0c048522;
case 0x0c048524u: goto P_0c048524;
case 0x0c048526u: goto P_0c048526;
case 0x0c048528u: goto P_0c048528;
case 0x0c04852au: goto P_0c04852a;
case 0x0c04852cu: goto P_0c04852c;
case 0x0c04852eu: goto P_0c04852e;
case 0x0c048530u: goto P_0c048530;
case 0x0c048532u: goto P_0c048532;
case 0x0c048534u: goto P_0c048534;
case 0x0c048536u: goto P_0c048536;
case 0x0c048538u: goto P_0c048538;
case 0x0c04853au: goto P_0c04853a;
case 0x0c04853cu: goto P_0c04853c;
case 0x0c04853eu: goto P_0c04853e;
case 0x0c048540u: goto P_0c048540;
case 0x0c048542u: goto P_0c048542;
case 0x0c048544u: goto P_0c048544;
case 0x0c048546u: goto P_0c048546;
case 0x0c048548u: goto P_0c048548;
case 0x0c04854au: goto P_0c04854a;
case 0x0c04854cu: goto P_0c04854c;
case 0x0c04854eu: goto P_0c04854e;
case 0x0c048550u: goto P_0c048550;
case 0x0c048552u: goto P_0c048552;
case 0x0c048554u: goto P_0c048554;
case 0x0c048556u: goto P_0c048556;
case 0x0c048558u: goto P_0c048558;
case 0x0c04855au: goto P_0c04855a;
case 0x0c04855cu: goto P_0c04855c;
case 0x0c04855eu: goto P_0c04855e;
case 0x0c048560u: goto P_0c048560;
case 0x0c04856cu: goto P_0c04856c;
case 0x0c04856eu: goto P_0c04856e;
case 0x0c048570u: goto P_0c048570;
case 0x0c048572u: goto P_0c048572;
case 0x0c048574u: goto P_0c048574;
case 0x0c048576u: goto P_0c048576;
case 0x0c048578u: goto P_0c048578;
case 0x0c04857au: goto P_0c04857a;
case 0x0c04857cu: goto P_0c04857c;
case 0x0c04857eu: goto P_0c04857e;
case 0x0c048580u: goto P_0c048580;
case 0x0c048582u: goto P_0c048582;
case 0x0c048584u: goto P_0c048584;
case 0x0c048586u: goto P_0c048586;
case 0x0c048588u: goto P_0c048588;
case 0x0c04858au: goto P_0c04858a;
case 0x0c04858cu: goto P_0c04858c;
case 0x0c04858eu: goto P_0c04858e;
case 0x0c048590u: goto P_0c048590;
case 0x0c048592u: goto P_0c048592;
case 0x0c048594u: goto P_0c048594;
case 0x0c048596u: goto P_0c048596;
case 0x0c048598u: goto P_0c048598;
case 0x0c04859cu: goto P_0c04859c;
case 0x0c04859eu: goto P_0c04859e;
case 0x0c0485a0u: goto P_0c0485a0;
case 0x0c0485a2u: goto P_0c0485a2;
case 0x0c0485a4u: goto P_0c0485a4;
case 0x0c0485a6u: goto P_0c0485a6;
case 0x0c0485a8u: goto P_0c0485a8;
case 0x0c0485aau: goto P_0c0485aa;
case 0x0c0485acu: goto P_0c0485ac;
case 0x0c0485aeu: goto P_0c0485ae;
case 0x0c0485b0u: goto P_0c0485b0;
case 0x0c0485b2u: goto P_0c0485b2;
case 0x0c0485b4u: goto P_0c0485b4;
case 0x0c0485b6u: goto P_0c0485b6;
case 0x0c0485b8u: goto P_0c0485b8;
case 0x0c0485bcu: goto P_0c0485bc;
case 0x0c0485beu: goto P_0c0485be;
case 0x0c0490e8u: goto P_0c0490e8;
case 0x0c0490eau: goto P_0c0490ea;
case 0x0c0490ecu: goto P_0c0490ec;
case 0x0c0490eeu: goto P_0c0490ee;
case 0x0c0490f0u: goto P_0c0490f0;
case 0x0c0490f2u: goto P_0c0490f2;
case 0x0c0490f4u: goto P_0c0490f4;
case 0x0c0490f6u: goto P_0c0490f6;
case 0x0c0490f8u: goto P_0c0490f8;
case 0x0c0490fau: goto P_0c0490fa;
case 0x0c0490fcu: goto P_0c0490fc;
case 0x0c0490feu: goto P_0c0490fe;
case 0x0c049100u: goto P_0c049100;
case 0x0c049102u: goto P_0c049102;
case 0x0c049104u: goto P_0c049104;
case 0x0c049106u: goto P_0c049106;
case 0x0c049108u: goto P_0c049108;
case 0x0c04910au: goto P_0c04910a;
case 0x0c04910cu: goto P_0c04910c;
case 0x0c049114u: goto P_0c049114;
case 0x0c049116u: goto P_0c049116;
case 0x0c049118u: goto P_0c049118;
case 0x0c04911au: goto P_0c04911a;
case 0x0c04911cu: goto P_0c04911c;
case 0x0c04911eu: goto P_0c04911e;
case 0x0c049120u: goto P_0c049120;
case 0x0c049122u: goto P_0c049122;
case 0x0c049124u: goto P_0c049124;
case 0x0c049126u: goto P_0c049126;
case 0x0c049128u: goto P_0c049128;
case 0x0c04912au: goto P_0c04912a;
case 0x0c04912cu: goto P_0c04912c;
case 0x0c04912eu: goto P_0c04912e;
case 0x0c049130u: goto P_0c049130;
case 0x0c049132u: goto P_0c049132;
case 0x0c049134u: goto P_0c049134;
case 0x0c049136u: goto P_0c049136;
case 0x0c049138u: goto P_0c049138;
case 0x0c04913au: goto P_0c04913a;
case 0x0c04913cu: goto P_0c04913c;
case 0x0c04913eu: goto P_0c04913e;
case 0x0c049140u: goto P_0c049140;
case 0x0c049142u: goto P_0c049142;
case 0x0c049144u: goto P_0c049144;
case 0x0c049146u: goto P_0c049146;
case 0x0c049148u: goto P_0c049148;
case 0x0c04914au: goto P_0c04914a;
case 0x0c04914cu: goto P_0c04914c;
case 0x0c04914eu: goto P_0c04914e;
case 0x0c049150u: goto P_0c049150;
case 0x0c049152u: goto P_0c049152;
case 0x0c049154u: goto P_0c049154;
case 0x0c049156u: goto P_0c049156;
case 0x0c049158u: goto P_0c049158;
case 0x0c04915au: goto P_0c04915a;
case 0x0c04915cu: goto P_0c04915c;
case 0x0c04915eu: goto P_0c04915e;
case 0x0c049160u: goto P_0c049160;
case 0x0c049162u: goto P_0c049162;
case 0x0c049164u: goto P_0c049164;
case 0x0c049168u: goto P_0c049168;
case 0x0c04916au: goto P_0c04916a;
case 0x0c04916cu: goto P_0c04916c;
case 0x0c04916eu: goto P_0c04916e;
case 0x0c049170u: goto P_0c049170;
case 0x0c049172u: goto P_0c049172;
case 0x0c049174u: goto P_0c049174;
case 0x0c049176u: goto P_0c049176;
case 0x0c049178u: goto P_0c049178;
case 0x0c04917au: goto P_0c04917a;
case 0x0c04917cu: goto P_0c04917c;
case 0x0c04917eu: goto P_0c04917e;
case 0x0c049180u: goto P_0c049180;
case 0x0c049182u: goto P_0c049182;
case 0x0c049184u: goto P_0c049184;
case 0x0c049188u: goto P_0c049188;
case 0x0c04918au: goto P_0c04918a;
case 0x0c049a16u: goto P_0c049a16;
case 0x0c049a18u: goto P_0c049a18;
case 0x0c049a1au: goto P_0c049a1a;
case 0x0c049a1cu: goto P_0c049a1c;
case 0x0c049a1eu: goto P_0c049a1e;
case 0x0c049a20u: goto P_0c049a20;
case 0x0c049a22u: goto P_0c049a22;
case 0x0c049a24u: goto P_0c049a24;
case 0x0c049a26u: goto P_0c049a26;
case 0x0c049a28u: goto P_0c049a28;
case 0x0c049a2au: goto P_0c049a2a;
case 0x0c049a2cu: goto P_0c049a2c;
case 0x0c049a2eu: goto P_0c049a2e;
case 0x0c049a30u: goto P_0c049a30;
case 0x0c049a32u: goto P_0c049a32;
case 0x0c049a34u: goto P_0c049a34;
case 0x0c049a36u: goto P_0c049a36;
case 0x0c049a38u: goto P_0c049a38;
case 0x0c049a3cu: goto P_0c049a3c;
case 0x0c049a3eu: goto P_0c049a3e;
case 0x0c049a40u: goto P_0c049a40;
case 0x0c049a42u: goto P_0c049a42;
case 0x0c049a44u: goto P_0c049a44;
case 0x0c049a46u: goto P_0c049a46;
case 0x0c049a48u: goto P_0c049a48;
case 0x0c049a4au: goto P_0c049a4a;
case 0x0c049a4cu: goto P_0c049a4c;
case 0x0c049a4eu: goto P_0c049a4e;
case 0x0c049a50u: goto P_0c049a50;
case 0x0c049a52u: goto P_0c049a52;
case 0x0c049a54u: goto P_0c049a54;
case 0x0c049a56u: goto P_0c049a56;
case 0x0c049a58u: goto P_0c049a58;
case 0x0c049a5au: goto P_0c049a5a;
case 0x0c049a5cu: goto P_0c049a5c;
case 0x0c049a5eu: goto P_0c049a5e;
case 0x0c049a60u: goto P_0c049a60;
case 0x0c049a62u: goto P_0c049a62;
case 0x0c049a64u: goto P_0c049a64;
case 0x0c049a66u: goto P_0c049a66;
case 0x0c049a68u: goto P_0c049a68;
case 0x0c049a6au: goto P_0c049a6a;
case 0x0c049a6cu: goto P_0c049a6c;
case 0x0c049a6eu: goto P_0c049a6e;
case 0x0c049a70u: goto P_0c049a70;
case 0x0c049a72u: goto P_0c049a72;
case 0x0c049a74u: goto P_0c049a74;
case 0x0c049a76u: goto P_0c049a76;
case 0x0c049a78u: goto P_0c049a78;
case 0x0c049a7au: goto P_0c049a7a;
case 0x0c049a7cu: goto P_0c049a7c;
case 0x0c049a7eu: goto P_0c049a7e;
case 0x0c049a80u: goto P_0c049a80;
case 0x0c049a82u: goto P_0c049a82;
case 0x0c049a84u: goto P_0c049a84;
case 0x0c049a86u: goto P_0c049a86;
case 0x0c049a88u: goto P_0c049a88;
case 0x0c049a8au: goto P_0c049a8a;
case 0x0c049a8cu: goto P_0c049a8c;
case 0x0c049a8eu: goto P_0c049a8e;
case 0x0c049a90u: goto P_0c049a90;
case 0x0c049a92u: goto P_0c049a92;
case 0x0c049a94u: goto P_0c049a94;
case 0x0c049a96u: goto P_0c049a96;
case 0x0c049a98u: goto P_0c049a98;
case 0x0c049a9au: goto P_0c049a9a;
case 0x0c049a9cu: goto P_0c049a9c;
case 0x0c049a9eu: goto P_0c049a9e;
case 0x0c049aa0u: goto P_0c049aa0;
case 0x0c049aa2u: goto P_0c049aa2;
case 0x0c049aa4u: goto P_0c049aa4;
case 0x0c049aa6u: goto P_0c049aa6;
case 0x0c049aa8u: goto P_0c049aa8;
case 0x0c049aaau: goto P_0c049aaa;
case 0x0c049aacu: goto P_0c049aac;
case 0x0c049aaeu: goto P_0c049aae;
case 0x0c049ab0u: goto P_0c049ab0;
case 0x0c049ab2u: goto P_0c049ab2;
case 0x0c049ab4u: goto P_0c049ab4;
case 0x0c049ab6u: goto P_0c049ab6;
case 0x0c049ab8u: goto P_0c049ab8;
case 0x0c049abcu: goto P_0c049abc;
case 0x0c049abeu: goto P_0c049abe;
case 0x0c055c96u: goto P_0c055c96;
case 0x0c055c98u: goto P_0c055c98;
case 0x0c055c9au: goto P_0c055c9a;
case 0x0c055c9cu: goto P_0c055c9c;
case 0x0c055c9eu: goto P_0c055c9e;
case 0x0c055ca0u: goto P_0c055ca0;
case 0x0c055ca2u: goto P_0c055ca2;
case 0x0c055ca4u: goto P_0c055ca4;
case 0x0c055ca6u: goto P_0c055ca6;
case 0x0c055ca8u: goto P_0c055ca8;
case 0x0c055caau: goto P_0c055caa;
case 0x0c055cacu: goto P_0c055cac;
case 0x0c055caeu: goto P_0c055cae;
case 0x0c055cb0u: goto P_0c055cb0;
case 0x0c055cb2u: goto P_0c055cb2;
case 0x0c055cb4u: goto P_0c055cb4;
case 0x0c055cb6u: goto P_0c055cb6;
case 0x0c055cb8u: goto P_0c055cb8;
case 0x0c055cbau: goto P_0c055cba;
case 0x0c055cbcu: goto P_0c055cbc;
case 0x0c055cbeu: goto P_0c055cbe;
case 0x0c055cc0u: goto P_0c055cc0;
case 0x0c055cc2u: goto P_0c055cc2;
case 0x0c055cc4u: goto P_0c055cc4;
case 0x0c055cc6u: goto P_0c055cc6;
case 0x0c055cc8u: goto P_0c055cc8;
case 0x0c055ccau: goto P_0c055cca;
case 0x0c055cccu: goto P_0c055ccc;
case 0x0c055cceu: goto P_0c055cce;
case 0x0c055cd0u: goto P_0c055cd0;
case 0x0c055cd2u: goto P_0c055cd2;
case 0x0c055cd4u: goto P_0c055cd4;
case 0x0c055cd6u: goto P_0c055cd6;
case 0x0c055cd8u: goto P_0c055cd8;
case 0x0c055cdau: goto P_0c055cda;
case 0x0c055cdcu: goto P_0c055cdc;
case 0x0c055cdeu: goto P_0c055cde;
case 0x0c055ce0u: goto P_0c055ce0;
case 0x0c055ce2u: goto P_0c055ce2;
case 0x0c058788u: goto P_0c058788;
case 0x0c05878au: goto P_0c05878a;
case 0x0c05878cu: goto P_0c05878c;
case 0x0c0587d8u: goto P_0c0587d8;
case 0x0c0587dau: goto P_0c0587da;
case 0x0c0587dcu: goto P_0c0587dc;
case 0x0c0587deu: goto P_0c0587de;
case 0x0c0587e0u: goto P_0c0587e0;
case 0x0c0587e2u: goto P_0c0587e2;
case 0x0c0587e4u: goto P_0c0587e4;
case 0x0c0587e6u: goto P_0c0587e6;
case 0x0c0587e8u: goto P_0c0587e8;
case 0x0c0587eau: goto P_0c0587ea;
case 0x0c0587ecu: goto P_0c0587ec;
case 0x0c0587eeu: goto P_0c0587ee;
case 0x0c0587f0u: goto P_0c0587f0;
case 0x0c0587f2u: goto P_0c0587f2;
case 0x0c0587f4u: goto P_0c0587f4;
case 0x0c0587f6u: goto P_0c0587f6;
case 0x0c0587f8u: goto P_0c0587f8;
case 0x0c0587fau: goto P_0c0587fa;
case 0x0c0587fcu: goto P_0c0587fc;
case 0x0c0587feu: goto P_0c0587fe;
case 0x0c058800u: goto P_0c058800;
case 0x0c058802u: goto P_0c058802;
case 0x0c058804u: goto P_0c058804;
case 0x0c058806u: goto P_0c058806;
case 0x0c058808u: goto P_0c058808;
case 0x0c05880au: goto P_0c05880a;
case 0x0c05880cu: goto P_0c05880c;
case 0x0c05880eu: goto P_0c05880e;
case 0x0c058810u: goto P_0c058810;
case 0x0c058812u: goto P_0c058812;
case 0x0c058814u: goto P_0c058814;
case 0x0c058852u: goto P_0c058852;
case 0x0c058854u: goto P_0c058854;
case 0x0c058856u: goto P_0c058856;
case 0x0c058858u: goto P_0c058858;
case 0x0c05885au: goto P_0c05885a;
case 0x0c05885cu: goto P_0c05885c;
case 0x0c05885eu: goto P_0c05885e;
case 0x0c058860u: goto P_0c058860;
case 0x0c058862u: goto P_0c058862;
case 0x0c058864u: goto P_0c058864;
case 0x0c058866u: goto P_0c058866;
case 0x0c058868u: goto P_0c058868;
case 0x0c05886au: goto P_0c05886a;
case 0x0c05886cu: goto P_0c05886c;
case 0x0c05886eu: goto P_0c05886e;
case 0x0c058870u: goto P_0c058870;
case 0x0c058872u: goto P_0c058872;
case 0x0c058874u: goto P_0c058874;
case 0x0c058876u: goto P_0c058876;
case 0x0c058878u: goto P_0c058878;
case 0x0c05887au: goto P_0c05887a;
case 0x0c05887cu: goto P_0c05887c;
case 0x0c05887eu: goto P_0c05887e;
case 0x0c058880u: goto P_0c058880;
case 0x0c058882u: goto P_0c058882;
case 0x0c058884u: goto P_0c058884;
case 0x0c058886u: goto P_0c058886;
case 0x0c058888u: goto P_0c058888;
case 0x0c05888au: goto P_0c05888a;
case 0x0c05888cu: goto P_0c05888c;
case 0x0c05888eu: goto P_0c05888e;
case 0x0c058890u: goto P_0c058890;
case 0x0c058892u: goto P_0c058892;
case 0x0c058894u: goto P_0c058894;
case 0x0c058896u: goto P_0c058896;
case 0x0c058898u: goto P_0c058898;
case 0x0c05889au: goto P_0c05889a;
case 0x0c05889cu: goto P_0c05889c;
case 0x0c05889eu: goto P_0c05889e;
case 0x0c0588a0u: goto P_0c0588a0;
case 0x0c0588a2u: goto P_0c0588a2;
case 0x0c0588a4u: goto P_0c0588a4;
case 0x0c0588a6u: goto P_0c0588a6;
case 0x0c0588a8u: goto P_0c0588a8;
case 0x0c0588aau: goto P_0c0588aa;
case 0x0c0588acu: goto P_0c0588ac;
case 0x0c0588aeu: goto P_0c0588ae;
case 0x0c0588b0u: goto P_0c0588b0;
case 0x0c0588b2u: goto P_0c0588b2;
case 0x0c0588b4u: goto P_0c0588b4;
case 0x0c0588b6u: goto P_0c0588b6;
case 0x0c0588b8u: goto P_0c0588b8;
case 0x0c0588bau: goto P_0c0588ba;
case 0x0c0588bcu: goto P_0c0588bc;
case 0x0c0588beu: goto P_0c0588be;
case 0x0c0588c0u: goto P_0c0588c0;
case 0x0c0588c2u: goto P_0c0588c2;
case 0x0c0588c4u: goto P_0c0588c4;
case 0x0c0588c6u: goto P_0c0588c6;
case 0x0c0588c8u: goto P_0c0588c8;
case 0x0c0588cau: goto P_0c0588ca;
case 0x0c0588ccu: goto P_0c0588cc;
case 0x0c0588ceu: goto P_0c0588ce;
case 0x0c0588d0u: goto P_0c0588d0;
case 0x0c0588d2u: goto P_0c0588d2;
case 0x0c0588d4u: goto P_0c0588d4;
case 0x0c0588d6u: goto P_0c0588d6;
case 0x0c0588d8u: goto P_0c0588d8;
case 0x0c0588dau: goto P_0c0588da;
case 0x0c0588dcu: goto P_0c0588dc;
case 0x0c0588deu: goto P_0c0588de;
case 0x0c0588e0u: goto P_0c0588e0;
case 0x0c0588e2u: goto P_0c0588e2;
case 0x0c0588e4u: goto P_0c0588e4;
case 0x0c0588e6u: goto P_0c0588e6;
case 0x0c0588e8u: goto P_0c0588e8;
case 0x0c0588eau: goto P_0c0588ea;
case 0x0c0588ecu: goto P_0c0588ec;
case 0x0c0588eeu: goto P_0c0588ee;
case 0x0c05df8au: goto P_0c05df8a;
case 0x0c05df8cu: goto P_0c05df8c;
case 0x0c05df8eu: goto P_0c05df8e;
case 0x0c05df90u: goto P_0c05df90;
case 0x0c05df92u: goto P_0c05df92;
case 0x0c05df94u: goto P_0c05df94;
case 0x0c05df96u: goto P_0c05df96;
case 0x0c05df98u: goto P_0c05df98;
case 0x0c05df9au: goto P_0c05df9a;
case 0x0c05df9cu: goto P_0c05df9c;
case 0x0c05df9eu: goto P_0c05df9e;
case 0x0c05dfa0u: goto P_0c05dfa0;
case 0x0c05dfa2u: goto P_0c05dfa2;
case 0x0c05dfa4u: goto P_0c05dfa4;
case 0x0c05dfa6u: goto P_0c05dfa6;
case 0x0c05dfa8u: goto P_0c05dfa8;
case 0x0c05dfaau: goto P_0c05dfaa;
case 0x0c05dfacu: goto P_0c05dfac;
case 0x0c05dfaeu: goto P_0c05dfae;
case 0x0c05dfb0u: goto P_0c05dfb0;
case 0x0c05dfb2u: goto P_0c05dfb2;
case 0x0c05dfb4u: goto P_0c05dfb4;
case 0x0c05dfb6u: goto P_0c05dfb6;
case 0x0c05dfb8u: goto P_0c05dfb8;
case 0x0c05dfbau: goto P_0c05dfba;
case 0x0c05dfbcu: goto P_0c05dfbc;
case 0x0c05dfbeu: goto P_0c05dfbe;
case 0x0c05dfc0u: goto P_0c05dfc0;
case 0x0c05dfc2u: goto P_0c05dfc2;
case 0x0c05dfc4u: goto P_0c05dfc4;
case 0x0c05dfc6u: goto P_0c05dfc6;
case 0x0c05dfc8u: goto P_0c05dfc8;
case 0x0c05dfcau: goto P_0c05dfca;
case 0x0c05dfccu: goto P_0c05dfcc;
case 0x0c05dfceu: goto P_0c05dfce;
case 0x0c05dfd0u: goto P_0c05dfd0;
case 0x0c05dfd2u: goto P_0c05dfd2;
case 0x0c05dfd4u: goto P_0c05dfd4;
case 0x0c05dfd6u: goto P_0c05dfd6;
case 0x0c05edd4u: goto P_0c05edd4;
case 0x0c05edd6u: goto P_0c05edd6;
case 0x0c05edd8u: goto P_0c05edd8;
case 0x0c05eddau: goto P_0c05edda;
case 0x0c05eddcu: goto P_0c05eddc;
case 0x0c05eddeu: goto P_0c05edde;
case 0x0c05ede0u: goto P_0c05ede0;
case 0x0c05ede2u: goto P_0c05ede2;
case 0x0c05ede4u: goto P_0c05ede4;
case 0x0c05ede6u: goto P_0c05ede6;
case 0x0c05ede8u: goto P_0c05ede8;
case 0x0c05edeau: goto P_0c05edea;
case 0x0c05edecu: goto P_0c05edec;
case 0x0c05edeeu: goto P_0c05edee;
case 0x0c05edf0u: goto P_0c05edf0;
case 0x0c05edf2u: goto P_0c05edf2;
case 0x0c05edf4u: goto P_0c05edf4;
case 0x0c05edf6u: goto P_0c05edf6;
case 0x0c05edf8u: goto P_0c05edf8;
case 0x0c05edfau: goto P_0c05edfa;
case 0x0c05edfcu: goto P_0c05edfc;
case 0x0c05edfeu: goto P_0c05edfe;
case 0x0c05ee00u: goto P_0c05ee00;
case 0x0c05ee02u: goto P_0c05ee02;
case 0x0c05ee04u: goto P_0c05ee04;
case 0x0c05ee06u: goto P_0c05ee06;
case 0x0c05ee08u: goto P_0c05ee08;
case 0x0c05ee0au: goto P_0c05ee0a;
case 0x0c05ee0cu: goto P_0c05ee0c;
case 0x0c05ee0eu: goto P_0c05ee0e;
case 0x0c05ee10u: goto P_0c05ee10;
case 0x0c05ee12u: goto P_0c05ee12;
case 0x0c05ee14u: goto P_0c05ee14;
case 0x0c05ee16u: goto P_0c05ee16;
case 0x0c05ee18u: goto P_0c05ee18;
case 0x0c05ee1au: goto P_0c05ee1a;
case 0x0c05ee1cu: goto P_0c05ee1c;
case 0x0c05ee1eu: goto P_0c05ee1e;
case 0x0c05ee20u: goto P_0c05ee20;
case 0x0c05ee22u: goto P_0c05ee22;
case 0x0c05ee24u: goto P_0c05ee24;
case 0x0c05ee26u: goto P_0c05ee26;
case 0x0c05ee28u: goto P_0c05ee28;
case 0x0c05ee2au: goto P_0c05ee2a;
case 0x0c05ee2cu: goto P_0c05ee2c;
case 0x0c05ee2eu: goto P_0c05ee2e;
case 0x0c05ee30u: goto P_0c05ee30;
case 0x0c05ee32u: goto P_0c05ee32;
case 0x0c05f33au: goto P_0c05f33a;
case 0x0c05f3deu: goto P_0c05f3de;
case 0x0c05f3e0u: goto P_0c05f3e0;
case 0x0c05f3e2u: goto P_0c05f3e2;
case 0x0c05f3e4u: goto P_0c05f3e4;
case 0x0c05f3e6u: goto P_0c05f3e6;
case 0x0c05f3e8u: goto P_0c05f3e8;
case 0x0c05fc32u: goto P_0c05fc32;
case 0x0c05fc34u: goto P_0c05fc34;
case 0x0c05fc36u: goto P_0c05fc36;
case 0x0c05fc38u: goto P_0c05fc38;
case 0x0c05fc3au: goto P_0c05fc3a;
case 0x0c05fc3cu: goto P_0c05fc3c;
case 0x0c05fc3eu: goto P_0c05fc3e;
case 0x0c05fc40u: goto P_0c05fc40;
case 0x0c05fc42u: goto P_0c05fc42;
case 0x0c05fc44u: goto P_0c05fc44;
case 0x0c05fc46u: goto P_0c05fc46;
case 0x0c05fc48u: goto P_0c05fc48;
case 0x0c05fc4au: goto P_0c05fc4a;
case 0x0c05fc4cu: goto P_0c05fc4c;
case 0x0c05fc4eu: goto P_0c05fc4e;
case 0x0c05fc50u: goto P_0c05fc50;
case 0x0c05fc52u: goto P_0c05fc52;
case 0x0c05fc54u: goto P_0c05fc54;
case 0x0c05fc56u: goto P_0c05fc56;
case 0x0c05fc58u: goto P_0c05fc58;
case 0x0c05fc5au: goto P_0c05fc5a;
case 0x0c05fc5cu: goto P_0c05fc5c;
case 0x0c05fc5eu: goto P_0c05fc5e;
case 0x0c05fc60u: goto P_0c05fc60;
case 0x0c05fc62u: goto P_0c05fc62;
case 0x0c05fc64u: goto P_0c05fc64;
case 0x0c05fc66u: goto P_0c05fc66;
case 0x0c05fc68u: goto P_0c05fc68;
case 0x0c05fc6au: goto P_0c05fc6a;
case 0x0c05fc6cu: goto P_0c05fc6c;
case 0x0c05fc6eu: goto P_0c05fc6e;
case 0x0c05fc70u: goto P_0c05fc70;
case 0x0c05fc72u: goto P_0c05fc72;
case 0x0c05fc74u: goto P_0c05fc74;
case 0x0c05fc76u: goto P_0c05fc76;
case 0x0c05fc78u: goto P_0c05fc78;
case 0x0c05fc7au: goto P_0c05fc7a;
case 0x0c05fc7cu: goto P_0c05fc7c;
case 0x0c05fc7eu: goto P_0c05fc7e;
case 0x0c05fc80u: goto P_0c05fc80;
case 0x0c05fc82u: goto P_0c05fc82;
case 0x0c05fc84u: goto P_0c05fc84;
case 0x0c05fc86u: goto P_0c05fc86;
case 0x0c05fc88u: goto P_0c05fc88;
case 0x0c05fc8au: goto P_0c05fc8a;
case 0x0c05fc8cu: goto P_0c05fc8c;
case 0x0c05fc8eu: goto P_0c05fc8e;
case 0x0c05fc90u: goto P_0c05fc90;
case 0x0c05fc92u: goto P_0c05fc92;
case 0x0c05fc94u: goto P_0c05fc94;
case 0x0c05fc96u: goto P_0c05fc96;
case 0x0c05fc98u: goto P_0c05fc98;
case 0x0c06256eu: goto P_0c06256e;
case 0x0c062570u: goto P_0c062570;
case 0x0c062572u: goto P_0c062572;
case 0x0c062574u: goto P_0c062574;
case 0x0c062576u: goto P_0c062576;
case 0x0c062578u: goto P_0c062578;
case 0x0c06257au: goto P_0c06257a;
case 0x0c06257cu: goto P_0c06257c;
case 0x0c06257eu: goto P_0c06257e;
case 0x0c062580u: goto P_0c062580;
case 0x0c062582u: goto P_0c062582;
case 0x0c062584u: goto P_0c062584;
case 0x0c062586u: goto P_0c062586;
case 0x0c062588u: goto P_0c062588;
case 0x0c0625a0u: goto P_0c0625a0;
case 0x0c0625a2u: goto P_0c0625a2;
case 0x0c0625a4u: goto P_0c0625a4;
case 0x0c0625a6u: goto P_0c0625a6;
case 0x0c0625a8u: goto P_0c0625a8;
case 0x0c0625aau: goto P_0c0625aa;
case 0x0c0625acu: goto P_0c0625ac;
case 0x0c0625aeu: goto P_0c0625ae;
case 0x0c0625b0u: goto P_0c0625b0;
case 0x0c0625b2u: goto P_0c0625b2;
case 0x0c0625b4u: goto P_0c0625b4;
case 0x0c0625b6u: goto P_0c0625b6;
case 0x0c0625b8u: goto P_0c0625b8;
case 0x0c0625bau: goto P_0c0625ba;
case 0x0c0625bcu: goto P_0c0625bc;
case 0x0c0625beu: goto P_0c0625be;
case 0x0c0625c0u: goto P_0c0625c0;
case 0x0c0625c2u: goto P_0c0625c2;
case 0x0c0625c4u: goto P_0c0625c4;
case 0x0c0625c6u: goto P_0c0625c6;
case 0x0c0625c8u: goto P_0c0625c8;
case 0x0c0625cau: goto P_0c0625ca;
case 0x0c0625ccu: goto P_0c0625cc;
case 0x0c0625ceu: goto P_0c0625ce;
case 0x0c0625d0u: goto P_0c0625d0;
case 0x0c0625d2u: goto P_0c0625d2;
case 0x0c0625d4u: goto P_0c0625d4;
case 0x0c0625d6u: goto P_0c0625d6;
case 0x0c0625d8u: goto P_0c0625d8;
case 0x0c0625dau: goto P_0c0625da;
case 0x0c0625dcu: goto P_0c0625dc;
case 0x0c0625deu: goto P_0c0625de;
case 0x0c0625e0u: goto P_0c0625e0;
case 0x0c0625e2u: goto P_0c0625e2;
case 0x0c0625e4u: goto P_0c0625e4;
case 0x0c0625e6u: goto P_0c0625e6;
case 0x0c0625e8u: goto P_0c0625e8;
case 0x0c0625eau: goto P_0c0625ea;
case 0x0c0625ecu: goto P_0c0625ec;
case 0x0c0625eeu: goto P_0c0625ee;
case 0x0c0625f0u: goto P_0c0625f0;
case 0x0c0625f2u: goto P_0c0625f2;
case 0x0c0625f4u: goto P_0c0625f4;
case 0x0c0625f6u: goto P_0c0625f6;
case 0x0c0625f8u: goto P_0c0625f8;
case 0x0c0625fau: goto P_0c0625fa;
case 0x0c0625fcu: goto P_0c0625fc;
case 0x0c0625feu: goto P_0c0625fe;
case 0x0c062600u: goto P_0c062600;
case 0x0c062602u: goto P_0c062602;
case 0x0c06da9cu: goto P_0c06da9c;
case 0x0c06da9eu: goto P_0c06da9e;
case 0x0c06daa0u: goto P_0c06daa0;
case 0x0c06daa2u: goto P_0c06daa2;
case 0x0c06daa4u: goto P_0c06daa4;
case 0x0c06daa6u: goto P_0c06daa6;
case 0x0c06daa8u: goto P_0c06daa8;
case 0x0c06daaau: goto P_0c06daaa;
case 0x0c06daacu: goto P_0c06daac;
case 0x0c06daaeu: goto P_0c06daae;
case 0x0c06dab0u: goto P_0c06dab0;
case 0x0c06dab2u: goto P_0c06dab2;
case 0x0c06dab4u: goto P_0c06dab4;
case 0x0c06dab6u: goto P_0c06dab6;
case 0x0c06dab8u: goto P_0c06dab8;
case 0x0c06dabau: goto P_0c06daba;
case 0x0c06dabcu: goto P_0c06dabc;
case 0x0c06dabeu: goto P_0c06dabe;
case 0x0c06dac0u: goto P_0c06dac0;
case 0x0c06dac2u: goto P_0c06dac2;
case 0x0c06dac4u: goto P_0c06dac4;
case 0x0c06dac6u: goto P_0c06dac6;
case 0x0c06dac8u: goto P_0c06dac8;
case 0x0c06dacau: goto P_0c06daca;
case 0x0c06daccu: goto P_0c06dacc;
case 0x0c06daceu: goto P_0c06dace;
case 0x0c06dad0u: goto P_0c06dad0;
case 0x0c06dad2u: goto P_0c06dad2;
case 0x0c06dad4u: goto P_0c06dad4;
case 0x0c06dad6u: goto P_0c06dad6;
case 0x0c06dad8u: goto P_0c06dad8;
case 0x0c06dadau: goto P_0c06dada;
case 0x0c06dadcu: goto P_0c06dadc;
case 0x0c06dadeu: goto P_0c06dade;
case 0x0c06dae0u: goto P_0c06dae0;
case 0x0c06dae2u: goto P_0c06dae2;
case 0x0c06dae4u: goto P_0c06dae4;
case 0x0c06dae6u: goto P_0c06dae6;
case 0x0c06db34u: goto P_0c06db34;
case 0x0c06db36u: goto P_0c06db36;
case 0x0c06db38u: goto P_0c06db38;
case 0x0c06db3au: goto P_0c06db3a;
case 0x0c06db3cu: goto P_0c06db3c;
case 0x0c06dc44u: goto P_0c06dc44;
case 0x0c07ba28u: goto P_0c07ba28;
case 0x0c07ba2au: goto P_0c07ba2a;
case 0x0c07ba2cu: goto P_0c07ba2c;
case 0x0c07ba2eu: goto P_0c07ba2e;
case 0x0c07ba30u: goto P_0c07ba30;
case 0x0c07ba32u: goto P_0c07ba32;
case 0x0c07ba34u: goto P_0c07ba34;
case 0x0c07ba36u: goto P_0c07ba36;
case 0x0c07ba38u: goto P_0c07ba38;
case 0x0c07ba3au: goto P_0c07ba3a;
case 0x0c07ba3cu: goto P_0c07ba3c;
case 0x0c07ba3eu: goto P_0c07ba3e;
case 0x0c07ba40u: goto P_0c07ba40;
case 0x0c07ba42u: goto P_0c07ba42;
case 0x0c07ba44u: goto P_0c07ba44;
case 0x0c07ba46u: goto P_0c07ba46;
case 0x0c07ba48u: goto P_0c07ba48;
case 0x0c07ba4au: goto P_0c07ba4a;
case 0x0c07ba4cu: goto P_0c07ba4c;
case 0x0c07ba4eu: goto P_0c07ba4e;
case 0x0c07ba50u: goto P_0c07ba50;
case 0x0c07ba52u: goto P_0c07ba52;
case 0x0c07ba54u: goto P_0c07ba54;
case 0x0c07ba56u: goto P_0c07ba56;
case 0x0c07ba58u: goto P_0c07ba58;
case 0x0c07ba5au: goto P_0c07ba5a;
case 0x0c07ba5cu: goto P_0c07ba5c;
case 0x0c07ba5eu: goto P_0c07ba5e;
case 0x0c07ba60u: goto P_0c07ba60;
case 0x0c07ba62u: goto P_0c07ba62;
case 0x0c07ba64u: goto P_0c07ba64;
case 0x0c07ba66u: goto P_0c07ba66;
case 0x0c07ba68u: goto P_0c07ba68;
case 0x0c07ba6au: goto P_0c07ba6a;
case 0x0c07ba6cu: goto P_0c07ba6c;
case 0x0c07ba6eu: goto P_0c07ba6e;
case 0x0c07ba70u: goto P_0c07ba70;
case 0x0c07ba72u: goto P_0c07ba72;
case 0x0c07ba74u: goto P_0c07ba74;
case 0x0c07ba76u: goto P_0c07ba76;
case 0x0c07ba78u: goto P_0c07ba78;
case 0x0c07ba7au: goto P_0c07ba7a;
case 0x0c07ba7cu: goto P_0c07ba7c;
case 0x0c07ba7eu: goto P_0c07ba7e;
case 0x0c07ba80u: goto P_0c07ba80;
case 0x0c07ba82u: goto P_0c07ba82;
case 0x0c07ba84u: goto P_0c07ba84;
case 0x0c07ba86u: goto P_0c07ba86;
case 0x0c07ba88u: goto P_0c07ba88;
case 0x0c07ba8au: goto P_0c07ba8a;
case 0x0c07ba8cu: goto P_0c07ba8c;
case 0x0c07ba8eu: goto P_0c07ba8e;
case 0x0c07ba90u: goto P_0c07ba90;
case 0x0c07ba92u: goto P_0c07ba92;
case 0x0c07ba94u: goto P_0c07ba94;
case 0x0c07ba96u: goto P_0c07ba96;
case 0x0c07ba98u: goto P_0c07ba98;
case 0x0c07ba9au: goto P_0c07ba9a;
case 0x0c07ba9cu: goto P_0c07ba9c;
case 0x0c07ba9eu: goto P_0c07ba9e;
case 0x0c07baa0u: goto P_0c07baa0;
case 0x0c07baa2u: goto P_0c07baa2;
case 0x0c07baa4u: goto P_0c07baa4;
case 0x0c07baa6u: goto P_0c07baa6;
case 0x0c07baa8u: goto P_0c07baa8;
case 0x0c07baaau: goto P_0c07baaa;
case 0x0c07baacu: goto P_0c07baac;
case 0x0c07baaeu: goto P_0c07baae;
case 0x0c07bab0u: goto P_0c07bab0;
case 0x0c07bab2u: goto P_0c07bab2;
case 0x0c07bab4u: goto P_0c07bab4;
case 0x0c07bab6u: goto P_0c07bab6;
case 0x0c07bab8u: goto P_0c07bab8;
case 0x0c07babau: goto P_0c07baba;
case 0x0c07babcu: goto P_0c07babc;
case 0x0c07babeu: goto P_0c07babe;
case 0x0c07bac0u: goto P_0c07bac0;
case 0x0c07bac2u: goto P_0c07bac2;
case 0x0c07bac4u: goto P_0c07bac4;
case 0x0c07bac6u: goto P_0c07bac6;
case 0x0c07bac8u: goto P_0c07bac8;
case 0x0c07bacau: goto P_0c07baca;
case 0x0c07baccu: goto P_0c07bacc;
case 0x0c07baceu: goto P_0c07bace;
case 0x0c07bad0u: goto P_0c07bad0;
case 0x0c07bad2u: goto P_0c07bad2;
case 0x0c07bad4u: goto P_0c07bad4;
case 0x0c07bad6u: goto P_0c07bad6;
case 0x0c07bad8u: goto P_0c07bad8;
case 0x0c07badau: goto P_0c07bada;
case 0x0c07badcu: goto P_0c07badc;
case 0x0c07badeu: goto P_0c07bade;
case 0x0c07bae0u: goto P_0c07bae0;
case 0x0c07bae2u: goto P_0c07bae2;
case 0x0c07bae4u: goto P_0c07bae4;
case 0x0c07bae6u: goto P_0c07bae6;
case 0x0c07bae8u: goto P_0c07bae8;
case 0x0c07baeau: goto P_0c07baea;
case 0x0c07baecu: goto P_0c07baec;
case 0x0c07baeeu: goto P_0c07baee;
case 0x0c07baf0u: goto P_0c07baf0;
case 0x0c07baf2u: goto P_0c07baf2;
case 0x0c07baf4u: goto P_0c07baf4;
case 0x0c07baf6u: goto P_0c07baf6;
case 0x0c07baf8u: goto P_0c07baf8;
case 0x0c07bafau: goto P_0c07bafa;
case 0x0c07bafcu: goto P_0c07bafc;
case 0x0c07bafeu: goto P_0c07bafe;
case 0x0c07bb00u: goto P_0c07bb00;
case 0x0c07bb02u: goto P_0c07bb02;
case 0x0c07bb04u: goto P_0c07bb04;
case 0x0c07bb06u: goto P_0c07bb06;
case 0x0c07bb08u: goto P_0c07bb08;
case 0x0c07bb0au: goto P_0c07bb0a;
case 0x0c07bb0cu: goto P_0c07bb0c;
case 0x0c07bb0eu: goto P_0c07bb0e;
case 0x0c07bb10u: goto P_0c07bb10;
case 0x0c07bb12u: goto P_0c07bb12;
case 0x0c07bb14u: goto P_0c07bb14;
case 0x0c07bb16u: goto P_0c07bb16;
case 0x0c07bb18u: goto P_0c07bb18;
case 0x0c07bb1au: goto P_0c07bb1a;
case 0x0c07bb1cu: goto P_0c07bb1c;
case 0x0c07bb1eu: goto P_0c07bb1e;
case 0x0c07bb20u: goto P_0c07bb20;
case 0x0c07bb22u: goto P_0c07bb22;
case 0x0c07bb24u: goto P_0c07bb24;
case 0x0c07bb26u: goto P_0c07bb26;
case 0x0c07bb28u: goto P_0c07bb28;
case 0x0c07bb2au: goto P_0c07bb2a;
case 0x0c07bb2cu: goto P_0c07bb2c;
case 0x0c07bb2eu: goto P_0c07bb2e;
case 0x0c07bb30u: goto P_0c07bb30;
case 0x0c07bb32u: goto P_0c07bb32;
case 0x0c07bb34u: goto P_0c07bb34;
case 0x0c07bb36u: goto P_0c07bb36;
case 0x0c07bb38u: goto P_0c07bb38;
case 0x0c07bb3au: goto P_0c07bb3a;
case 0x0c07bb3cu: goto P_0c07bb3c;
case 0x0c07bb3eu: goto P_0c07bb3e;
case 0x0c07bb40u: goto P_0c07bb40;
case 0x0c07bb42u: goto P_0c07bb42;
case 0x0c07bb44u: goto P_0c07bb44;
case 0x0c07bb46u: goto P_0c07bb46;
case 0x0c07bba0u: goto P_0c07bba0;
case 0x0c07bba2u: goto P_0c07bba2;
case 0x0c07bba4u: goto P_0c07bba4;
case 0x0c07bba6u: goto P_0c07bba6;
case 0x0c07bba8u: goto P_0c07bba8;
case 0x0c07bbaau: goto P_0c07bbaa;
case 0x0c07bbacu: goto P_0c07bbac;
case 0x0c07bbaeu: goto P_0c07bbae;
case 0x0c07bbb0u: goto P_0c07bbb0;
case 0x0c07bbb2u: goto P_0c07bbb2;
case 0x0c07bbb4u: goto P_0c07bbb4;
case 0x0c07bbb6u: goto P_0c07bbb6;
case 0x0c07bbb8u: goto P_0c07bbb8;
case 0x0c07bbbau: goto P_0c07bbba;
case 0x0c07bbbcu: goto P_0c07bbbc;
case 0x0c07bbbeu: goto P_0c07bbbe;
case 0x0c07bbc0u: goto P_0c07bbc0;
case 0x0c07bbc2u: goto P_0c07bbc2;
case 0x0c07bbc4u: goto P_0c07bbc4;
case 0x0c07bbc6u: goto P_0c07bbc6;
case 0x0c07bbc8u: goto P_0c07bbc8;
case 0x0c07bbcau: goto P_0c07bbca;
case 0x0c07bbccu: goto P_0c07bbcc;
case 0x0c07bbceu: goto P_0c07bbce;
case 0x0c07bbd0u: goto P_0c07bbd0;
case 0x0c07bbd2u: goto P_0c07bbd2;
case 0x0c07bbd4u: goto P_0c07bbd4;
case 0x0c07bbd6u: goto P_0c07bbd6;
case 0x0c07bbd8u: goto P_0c07bbd8;
case 0x0c07bbdau: goto P_0c07bbda;
case 0x0c07bbdcu: goto P_0c07bbdc;
case 0x0c07bbdeu: goto P_0c07bbde;
case 0x0c07bbe0u: goto P_0c07bbe0;
case 0x0c07bbe2u: goto P_0c07bbe2;
case 0x0c07bbe4u: goto P_0c07bbe4;
case 0x0c07bbe6u: goto P_0c07bbe6;
case 0x0c07bbe8u: goto P_0c07bbe8;
case 0x0c07bbeau: goto P_0c07bbea;
case 0x0c07bbecu: goto P_0c07bbec;
case 0x0c07bbeeu: goto P_0c07bbee;
case 0x0c07bbf0u: goto P_0c07bbf0;
case 0x0c07bbf2u: goto P_0c07bbf2;
case 0x0c07bbf4u: goto P_0c07bbf4;
case 0x0c07bbf6u: goto P_0c07bbf6;
case 0x0c07bbf8u: goto P_0c07bbf8;
case 0x0c07bbfau: goto P_0c07bbfa;
case 0x0c07bbfcu: goto P_0c07bbfc;
case 0x0c07bbfeu: goto P_0c07bbfe;
case 0x0c07bc00u: goto P_0c07bc00;
case 0x0c07bc02u: goto P_0c07bc02;
case 0x0c07bc04u: goto P_0c07bc04;
case 0x0c07bc06u: goto P_0c07bc06;
case 0x0c07bc08u: goto P_0c07bc08;
case 0x0c07bc0au: goto P_0c07bc0a;
case 0x0c07bc0cu: goto P_0c07bc0c;
case 0x0c07bc0eu: goto P_0c07bc0e;
case 0x0c07bc10u: goto P_0c07bc10;
case 0x0c07bc12u: goto P_0c07bc12;
case 0x0c07bc14u: goto P_0c07bc14;
case 0x0c07bc16u: goto P_0c07bc16;
case 0x0c07bc18u: goto P_0c07bc18;
case 0x0c07bc1au: goto P_0c07bc1a;
case 0x0c07bc1cu: goto P_0c07bc1c;
case 0x0c07bc1eu: goto P_0c07bc1e;
case 0x0c07bc20u: goto P_0c07bc20;
case 0x0c07bc22u: goto P_0c07bc22;
case 0x0c07bc24u: goto P_0c07bc24;
case 0x0c07bc26u: goto P_0c07bc26;
case 0x0c07bc28u: goto P_0c07bc28;
case 0x0c07bc2au: goto P_0c07bc2a;
case 0x0c07bc2cu: goto P_0c07bc2c;
case 0x0c07bc2eu: goto P_0c07bc2e;
case 0x0c07bc30u: goto P_0c07bc30;
case 0x0c07bc32u: goto P_0c07bc32;
case 0x0c07bc34u: goto P_0c07bc34;
case 0x0c07bc36u: goto P_0c07bc36;
case 0x0c07bc38u: goto P_0c07bc38;
case 0x0c07bc3au: goto P_0c07bc3a;
case 0x0c07bc3cu: goto P_0c07bc3c;
case 0x0c07bc3eu: goto P_0c07bc3e;
case 0x0c07bc40u: goto P_0c07bc40;
case 0x0c07bc42u: goto P_0c07bc42;
case 0x0c07bc44u: goto P_0c07bc44;
case 0x0c07bc46u: goto P_0c07bc46;
case 0x0c07bc48u: goto P_0c07bc48;
case 0x0c07bc4au: goto P_0c07bc4a;
case 0x0c07bc4cu: goto P_0c07bc4c;
case 0x0c07bc4eu: goto P_0c07bc4e;
case 0x0c07bc50u: goto P_0c07bc50;
case 0x0c07bc52u: goto P_0c07bc52;
case 0x0c07bc54u: goto P_0c07bc54;
case 0x0c07bc56u: goto P_0c07bc56;
case 0x0c07bc58u: goto P_0c07bc58;
case 0x0c07bc5au: goto P_0c07bc5a;
case 0x0c07bc5cu: goto P_0c07bc5c;
case 0x0c07bc5eu: goto P_0c07bc5e;
case 0x0c07bc60u: goto P_0c07bc60;
case 0x0c07bc62u: goto P_0c07bc62;
case 0x0c07bc64u: goto P_0c07bc64;
case 0x0c07bc66u: goto P_0c07bc66;
case 0x0c07bc68u: goto P_0c07bc68;
case 0x0c07bc6au: goto P_0c07bc6a;
case 0x0c07bc6cu: goto P_0c07bc6c;
case 0x0c07bc6eu: goto P_0c07bc6e;
case 0x0c07bc70u: goto P_0c07bc70;
case 0x0c07bc72u: goto P_0c07bc72;
case 0x0c07bc74u: goto P_0c07bc74;
case 0x0c07bc76u: goto P_0c07bc76;
case 0x0c07bc78u: goto P_0c07bc78;
case 0x0c07bc7au: goto P_0c07bc7a;
case 0x0c07bc7cu: goto P_0c07bc7c;
case 0x0c07bc7eu: goto P_0c07bc7e;
case 0x0c07bc80u: goto P_0c07bc80;
case 0x0c07bc82u: goto P_0c07bc82;
case 0x0c07bc84u: goto P_0c07bc84;
case 0x0c07bc86u: goto P_0c07bc86;
case 0x0c07bc88u: goto P_0c07bc88;
case 0x0c07bc8au: goto P_0c07bc8a;
case 0x0c07bc8cu: goto P_0c07bc8c;
case 0x0c07bc8eu: goto P_0c07bc8e;
case 0x0c07bc90u: goto P_0c07bc90;
case 0x0c07bc92u: goto P_0c07bc92;
case 0x0c07bc94u: goto P_0c07bc94;
case 0x0c07bc96u: goto P_0c07bc96;
case 0x0c07bc98u: goto P_0c07bc98;
case 0x0c07bc9au: goto P_0c07bc9a;
case 0x0c07bc9cu: goto P_0c07bc9c;
case 0x0c07bc9eu: goto P_0c07bc9e;
case 0x0c07bca0u: goto P_0c07bca0;
case 0x0c07bca2u: goto P_0c07bca2;
case 0x0c07bca4u: goto P_0c07bca4;
case 0x0c07bca6u: goto P_0c07bca6;
case 0x0c07bca8u: goto P_0c07bca8;
case 0x0c07bcaau: goto P_0c07bcaa;
case 0x0c07bcacu: goto P_0c07bcac;
case 0x0c07bcaeu: goto P_0c07bcae;
case 0x0c07bcb0u: goto P_0c07bcb0;
case 0x0c07bcb2u: goto P_0c07bcb2;
case 0x0c07bcb4u: goto P_0c07bcb4;
case 0x0c07bcb6u: goto P_0c07bcb6;
case 0x0c07bcb8u: goto P_0c07bcb8;
case 0x0c07bcbau: goto P_0c07bcba;
case 0x0c07bcbcu: goto P_0c07bcbc;
case 0x0c07bcbeu: goto P_0c07bcbe;
case 0x0c07bcc0u: goto P_0c07bcc0;
case 0x0c07bcc2u: goto P_0c07bcc2;
case 0x0c07bcc4u: goto P_0c07bcc4;
case 0x0c07bcc6u: goto P_0c07bcc6;
case 0x0c07bcc8u: goto P_0c07bcc8;
case 0x0c07bccau: goto P_0c07bcca;
case 0x0c07bcccu: goto P_0c07bccc;
case 0x0c07bcceu: goto P_0c07bcce;
case 0x0c07bcd0u: goto P_0c07bcd0;
case 0x0c07bcd2u: goto P_0c07bcd2;
case 0x0c07bcd4u: goto P_0c07bcd4;
case 0x0c07bcd6u: goto P_0c07bcd6;
case 0x0c07bcd8u: goto P_0c07bcd8;
case 0x0c07bcdau: goto P_0c07bcda;
case 0x0c07bcdcu: goto P_0c07bcdc;
case 0x0c07bcdeu: goto P_0c07bcde;
case 0x0c07bce0u: goto P_0c07bce0;
case 0x0c07bce2u: goto P_0c07bce2;
case 0x0c07bce4u: goto P_0c07bce4;
case 0x0c07bce6u: goto P_0c07bce6;
case 0x0c07bce8u: goto P_0c07bce8;
case 0x0c07bceau: goto P_0c07bcea;
case 0x0c07bcecu: goto P_0c07bcec;
case 0x0c07bceeu: goto P_0c07bcee;
case 0x0c07bcf0u: goto P_0c07bcf0;
case 0x0c07bcf2u: goto P_0c07bcf2;
case 0x0c07bcf4u: goto P_0c07bcf4;
case 0x0c07bcf6u: goto P_0c07bcf6;
case 0x0c07bcf8u: goto P_0c07bcf8;
case 0x0c07bd14u: goto P_0c07bd14;
case 0x0c07bd16u: goto P_0c07bd16;
case 0x0c07bd18u: goto P_0c07bd18;
case 0x0c07bd1au: goto P_0c07bd1a;
case 0x0c07bd1cu: goto P_0c07bd1c;
case 0x0c07bd1eu: goto P_0c07bd1e;
case 0x0c07bd20u: goto P_0c07bd20;
case 0x0c07bd22u: goto P_0c07bd22;
case 0x0c07bd24u: goto P_0c07bd24;
case 0x0c07bd26u: goto P_0c07bd26;
case 0x0c07bd28u: goto P_0c07bd28;
case 0x0c07bd2au: goto P_0c07bd2a;
case 0x0c07bd2cu: goto P_0c07bd2c;
case 0x0c07bd2eu: goto P_0c07bd2e;
case 0x0c07bd30u: goto P_0c07bd30;
case 0x0c07bd32u: goto P_0c07bd32;
case 0x0c07bd34u: goto P_0c07bd34;
case 0x0c07bd36u: goto P_0c07bd36;
case 0x0c07bd38u: goto P_0c07bd38;
case 0x0c07bd3au: goto P_0c07bd3a;
case 0x0c07bd3cu: goto P_0c07bd3c;
case 0x0c07bd3eu: goto P_0c07bd3e;
case 0x0c07bd40u: goto P_0c07bd40;
case 0x0c07bd42u: goto P_0c07bd42;
case 0x0c07bd44u: goto P_0c07bd44;
case 0x0c07bd46u: goto P_0c07bd46;
case 0x0c07bd48u: goto P_0c07bd48;
case 0x0c07bd4au: goto P_0c07bd4a;
case 0x0c07bd4cu: goto P_0c07bd4c;
case 0x0c07bd4eu: goto P_0c07bd4e;
case 0x0c07bd50u: goto P_0c07bd50;
case 0x0c07bd52u: goto P_0c07bd52;
case 0x0c07bd54u: goto P_0c07bd54;
case 0x0c07bd56u: goto P_0c07bd56;
case 0x0c07bd58u: goto P_0c07bd58;
case 0x0c07bd5au: goto P_0c07bd5a;
case 0x0c07bd5cu: goto P_0c07bd5c;
case 0x0c07bd5eu: goto P_0c07bd5e;
case 0x0c07bd60u: goto P_0c07bd60;
case 0x0c07bd62u: goto P_0c07bd62;
case 0x0c07bd64u: goto P_0c07bd64;
case 0x0c07bd66u: goto P_0c07bd66;
case 0x0c07bd68u: goto P_0c07bd68;
case 0x0c07bd6au: goto P_0c07bd6a;
case 0x0c07bd6cu: goto P_0c07bd6c;
case 0x0c07bd6eu: goto P_0c07bd6e;
case 0x0c07bd70u: goto P_0c07bd70;
case 0x0c07bd72u: goto P_0c07bd72;
case 0x0c07bd74u: goto P_0c07bd74;
case 0x0c07bd76u: goto P_0c07bd76;
case 0x0c07bd78u: goto P_0c07bd78;
case 0x0c07bd7au: goto P_0c07bd7a;
case 0x0c07bd7cu: goto P_0c07bd7c;
case 0x0c07bd7eu: goto P_0c07bd7e;
case 0x0c07bd80u: goto P_0c07bd80;
case 0x0c07bd82u: goto P_0c07bd82;
case 0x0c07bd84u: goto P_0c07bd84;
case 0x0c07bd86u: goto P_0c07bd86;
case 0x0c07bd88u: goto P_0c07bd88;
case 0x0c07bd8au: goto P_0c07bd8a;
case 0x0c07bd8cu: goto P_0c07bd8c;
case 0x0c07bd8eu: goto P_0c07bd8e;
case 0x0c07bd90u: goto P_0c07bd90;
case 0x0c07bd92u: goto P_0c07bd92;
case 0x0c07bd94u: goto P_0c07bd94;
case 0x0c07bd96u: goto P_0c07bd96;
case 0x0c07bd98u: goto P_0c07bd98;
case 0x0c07bd9au: goto P_0c07bd9a;
case 0x0c07bd9cu: goto P_0c07bd9c;
case 0x0c07bd9eu: goto P_0c07bd9e;
case 0x0c07bda0u: goto P_0c07bda0;
case 0x0c07bda2u: goto P_0c07bda2;
case 0x0c07bda4u: goto P_0c07bda4;
case 0x0c07bda6u: goto P_0c07bda6;
case 0x0c07bda8u: goto P_0c07bda8;
case 0x0c07bdaau: goto P_0c07bdaa;
case 0x0c07bdacu: goto P_0c07bdac;
case 0x0c07bdaeu: goto P_0c07bdae;
case 0x0c07bdb0u: goto P_0c07bdb0;
case 0x0c07bdb2u: goto P_0c07bdb2;
case 0x0c07bdb4u: goto P_0c07bdb4;
case 0x0c07bdb6u: goto P_0c07bdb6;
case 0x0c07bdb8u: goto P_0c07bdb8;
case 0x0c07bdbau: goto P_0c07bdba;
case 0x0c07bdbcu: goto P_0c07bdbc;
case 0x0c07bdbeu: goto P_0c07bdbe;
case 0x0c07bdc0u: goto P_0c07bdc0;
case 0x0c07bdc2u: goto P_0c07bdc2;
case 0x0c07bdc4u: goto P_0c07bdc4;
case 0x0c07bdc6u: goto P_0c07bdc6;
case 0x0c07bdc8u: goto P_0c07bdc8;
case 0x0c07bdcau: goto P_0c07bdca;
case 0x0c07bdccu: goto P_0c07bdcc;
case 0x0c07bdceu: goto P_0c07bdce;
case 0x0c07bdd0u: goto P_0c07bdd0;
case 0x0c07bdd2u: goto P_0c07bdd2;
case 0x0c07bdd4u: goto P_0c07bdd4;
case 0x0c07bdd6u: goto P_0c07bdd6;
case 0x0c07bdd8u: goto P_0c07bdd8;
case 0x0c07bddau: goto P_0c07bdda;
case 0x0c07bddcu: goto P_0c07bddc;
case 0x0c07bddeu: goto P_0c07bdde;
case 0x0c07bde0u: goto P_0c07bde0;
case 0x0c07bde2u: goto P_0c07bde2;
case 0x0c07bde4u: goto P_0c07bde4;
case 0x0c07bde6u: goto P_0c07bde6;
case 0x0c07bde8u: goto P_0c07bde8;
case 0x0c07bdeau: goto P_0c07bdea;
case 0x0c07bdecu: goto P_0c07bdec;
case 0x0c07bdeeu: goto P_0c07bdee;
case 0x0c07bdf0u: goto P_0c07bdf0;
case 0x0c07bdf2u: goto P_0c07bdf2;
case 0x0c07bdf4u: goto P_0c07bdf4;
case 0x0c07bdf6u: goto P_0c07bdf6;
case 0x0c07bdf8u: goto P_0c07bdf8;
case 0x0c07bdfau: goto P_0c07bdfa;
case 0x0c07bdfcu: goto P_0c07bdfc;
case 0x0c07bdfeu: goto P_0c07bdfe;
case 0x0c07be00u: goto P_0c07be00;
case 0x0c07be02u: goto P_0c07be02;
case 0x0c07be04u: goto P_0c07be04;
case 0x0c07be06u: goto P_0c07be06;
case 0x0c07be08u: goto P_0c07be08;
case 0x0c07be0au: goto P_0c07be0a;
case 0x0c07be0cu: goto P_0c07be0c;
case 0x0c07be0eu: goto P_0c07be0e;
case 0x0c07be10u: goto P_0c07be10;
case 0x0c07be12u: goto P_0c07be12;
case 0x0c07be14u: goto P_0c07be14;
case 0x0c07be16u: goto P_0c07be16;
case 0x0c07be18u: goto P_0c07be18;
case 0x0c07be1au: goto P_0c07be1a;
case 0x0c07be1cu: goto P_0c07be1c;
case 0x0c07be1eu: goto P_0c07be1e;
case 0x0c07be20u: goto P_0c07be20;
case 0x0c07be22u: goto P_0c07be22;
case 0x0c07be24u: goto P_0c07be24;
case 0x0c07be26u: goto P_0c07be26;
case 0x0c07be28u: goto P_0c07be28;
case 0x0c07be2au: goto P_0c07be2a;
case 0x0c07be2cu: goto P_0c07be2c;
case 0x0c07be2eu: goto P_0c07be2e;
case 0x0c07be30u: goto P_0c07be30;
case 0x0c07be32u: goto P_0c07be32;
case 0x0c07be34u: goto P_0c07be34;
case 0x0c07be36u: goto P_0c07be36;
case 0x0c07be38u: goto P_0c07be38;
case 0x0c07be3au: goto P_0c07be3a;
case 0x0c07be3cu: goto P_0c07be3c;
case 0x0c07be3eu: goto P_0c07be3e;
case 0x0c07be40u: goto P_0c07be40;
case 0x0c07be42u: goto P_0c07be42;
case 0x0c07be44u: goto P_0c07be44;
case 0x0c07be46u: goto P_0c07be46;
case 0x0c07be48u: goto P_0c07be48;
case 0x0c07be4au: goto P_0c07be4a;
case 0x0c07be4cu: goto P_0c07be4c;
case 0x0c07be4eu: goto P_0c07be4e;
case 0x0c07be50u: goto P_0c07be50;
case 0x0c07be52u: goto P_0c07be52;
case 0x0c07be54u: goto P_0c07be54;
case 0x0c07be56u: goto P_0c07be56;
case 0x0c07be58u: goto P_0c07be58;
case 0x0c07be5au: goto P_0c07be5a;
case 0x0c07be5cu: goto P_0c07be5c;
case 0x0c07be5eu: goto P_0c07be5e;
case 0x0c07be60u: goto P_0c07be60;
case 0x0c07be62u: goto P_0c07be62;
case 0x0c07be64u: goto P_0c07be64;
case 0x0c07be66u: goto P_0c07be66;
case 0x0c07be68u: goto P_0c07be68;
case 0x0c07be6au: goto P_0c07be6a;
case 0x0c07be6cu: goto P_0c07be6c;
case 0x0c07be6eu: goto P_0c07be6e;
case 0x0c07be70u: goto P_0c07be70;
case 0x0c07be72u: goto P_0c07be72;
case 0x0c07be74u: goto P_0c07be74;
case 0x0c07be76u: goto P_0c07be76;
case 0x0c07be78u: goto P_0c07be78;
case 0x0c07be7au: goto P_0c07be7a;
case 0x0c07be7cu: goto P_0c07be7c;
case 0x0c07be7eu: goto P_0c07be7e;
case 0x0c07be80u: goto P_0c07be80;
case 0x0c07be82u: goto P_0c07be82;
case 0x0c07be84u: goto P_0c07be84;
case 0x0c07be86u: goto P_0c07be86;
case 0x0c07be88u: goto P_0c07be88;
case 0x0c07be8au: goto P_0c07be8a;
case 0x0c07be8cu: goto P_0c07be8c;
case 0x0c07be8eu: goto P_0c07be8e;
case 0x0c07be90u: goto P_0c07be90;
case 0x0c07be92u: goto P_0c07be92;
case 0x0c07be94u: goto P_0c07be94;
case 0x0c07be96u: goto P_0c07be96;
case 0x0c07be98u: goto P_0c07be98;
case 0x0c07be9au: goto P_0c07be9a;
case 0x0c07beb0u: goto P_0c07beb0;
case 0x0c07beb2u: goto P_0c07beb2;
case 0x0c07beb4u: goto P_0c07beb4;
case 0x0c07beb6u: goto P_0c07beb6;
case 0x0c07beb8u: goto P_0c07beb8;
case 0x0c07bebau: goto P_0c07beba;
case 0x0c07bebcu: goto P_0c07bebc;
case 0x0c07bebeu: goto P_0c07bebe;
case 0x0c07bec0u: goto P_0c07bec0;
case 0x0c07bec2u: goto P_0c07bec2;
case 0x0c07bec4u: goto P_0c07bec4;
case 0x0c07bec6u: goto P_0c07bec6;
case 0x0c07bec8u: goto P_0c07bec8;
case 0x0c07becau: goto P_0c07beca;
case 0x0c07beccu: goto P_0c07becc;
case 0x0c07beceu: goto P_0c07bece;
case 0x0c07bed0u: goto P_0c07bed0;
case 0x0c07bed2u: goto P_0c07bed2;
case 0x0c07bed4u: goto P_0c07bed4;
case 0x0c07bed6u: goto P_0c07bed6;
case 0x0c07bed8u: goto P_0c07bed8;
case 0x0c07bedau: goto P_0c07beda;
case 0x0c07bedcu: goto P_0c07bedc;
case 0x0c07bedeu: goto P_0c07bede;
case 0x0c07bee0u: goto P_0c07bee0;
case 0x0c07bee2u: goto P_0c07bee2;
case 0x0c07bee4u: goto P_0c07bee4;
case 0x0c07bee6u: goto P_0c07bee6;
case 0x0c07bee8u: goto P_0c07bee8;
case 0x0c07beeau: goto P_0c07beea;
case 0x0c07beecu: goto P_0c07beec;
case 0x0c07beeeu: goto P_0c07beee;
case 0x0c07bef0u: goto P_0c07bef0;
case 0x0c07bef2u: goto P_0c07bef2;
case 0x0c07bef4u: goto P_0c07bef4;
case 0x0c07bef6u: goto P_0c07bef6;
case 0x0c07bef8u: goto P_0c07bef8;
case 0x0c07befau: goto P_0c07befa;
case 0x0c07befcu: goto P_0c07befc;
case 0x0c07befeu: goto P_0c07befe;
case 0x0c07bf00u: goto P_0c07bf00;
case 0x0c07bf02u: goto P_0c07bf02;
case 0x0c07bf04u: goto P_0c07bf04;
case 0x0c07bf06u: goto P_0c07bf06;
case 0x0c07bf08u: goto P_0c07bf08;
case 0x0c07bf0au: goto P_0c07bf0a;
case 0x0c07bf0cu: goto P_0c07bf0c;
case 0x0c07bf0eu: goto P_0c07bf0e;
case 0x0c07bf10u: goto P_0c07bf10;
case 0x0c07bf12u: goto P_0c07bf12;
case 0x0c07bf14u: goto P_0c07bf14;
case 0x0c07bf16u: goto P_0c07bf16;
case 0x0c07bf18u: goto P_0c07bf18;
case 0x0c07bf1au: goto P_0c07bf1a;
case 0x0c07bf1cu: goto P_0c07bf1c;
case 0x0c07bf1eu: goto P_0c07bf1e;
case 0x0c07bf20u: goto P_0c07bf20;
case 0x0c07bf22u: goto P_0c07bf22;
case 0x0c07bf24u: goto P_0c07bf24;
case 0x0c07bf26u: goto P_0c07bf26;
case 0x0c07bf28u: goto P_0c07bf28;
case 0x0c07bf2au: goto P_0c07bf2a;
case 0x0c07bf2cu: goto P_0c07bf2c;
case 0x0c07bf2eu: goto P_0c07bf2e;
case 0x0c07bf30u: goto P_0c07bf30;
case 0x0c07bf32u: goto P_0c07bf32;
case 0x0c07bf34u: goto P_0c07bf34;
case 0x0c07bf36u: goto P_0c07bf36;
case 0x0c07bf38u: goto P_0c07bf38;
case 0x0c07bf3au: goto P_0c07bf3a;
case 0x0c07bf3cu: goto P_0c07bf3c;
case 0x0c07bf3eu: goto P_0c07bf3e;
case 0x0c07bf40u: goto P_0c07bf40;
case 0x0c07bf42u: goto P_0c07bf42;
case 0x0c07bf44u: goto P_0c07bf44;
case 0x0c07bf46u: goto P_0c07bf46;
case 0x0c07bf48u: goto P_0c07bf48;
case 0x0c07bf4au: goto P_0c07bf4a;
case 0x0c07bf4cu: goto P_0c07bf4c;
case 0x0c07bf4eu: goto P_0c07bf4e;
case 0x0c07bf50u: goto P_0c07bf50;
case 0x0c07bf52u: goto P_0c07bf52;
case 0x0c07bf54u: goto P_0c07bf54;
case 0x0c07bf56u: goto P_0c07bf56;
case 0x0c07bf58u: goto P_0c07bf58;
case 0x0c07bf5au: goto P_0c07bf5a;
case 0x0c07bf5cu: goto P_0c07bf5c;
case 0x0c07bf5eu: goto P_0c07bf5e;
case 0x0c07bf60u: goto P_0c07bf60;
case 0x0c07bf62u: goto P_0c07bf62;
case 0x0c07bf64u: goto P_0c07bf64;
case 0x0c07bf66u: goto P_0c07bf66;
case 0x0c07bf68u: goto P_0c07bf68;
case 0x0c07bf6au: goto P_0c07bf6a;
case 0x0c07bf6cu: goto P_0c07bf6c;
case 0x0c07bf6eu: goto P_0c07bf6e;
case 0x0c07bf70u: goto P_0c07bf70;
case 0x0c07bf72u: goto P_0c07bf72;
case 0x0c07bf74u: goto P_0c07bf74;
case 0x0c07bf76u: goto P_0c07bf76;
case 0x0c07bf78u: goto P_0c07bf78;
case 0x0c07bf7au: goto P_0c07bf7a;
case 0x0c07bf7cu: goto P_0c07bf7c;
case 0x0c07bf7eu: goto P_0c07bf7e;
case 0x0c07bf80u: goto P_0c07bf80;
case 0x0c07bf82u: goto P_0c07bf82;
case 0x0c07bf84u: goto P_0c07bf84;
case 0x0c07bf86u: goto P_0c07bf86;
case 0x0c07bf88u: goto P_0c07bf88;
case 0x0c07bf8au: goto P_0c07bf8a;
case 0x0c07bf8cu: goto P_0c07bf8c;
case 0x0c07bf8eu: goto P_0c07bf8e;
case 0x0c07bf90u: goto P_0c07bf90;
case 0x0c07bf92u: goto P_0c07bf92;
case 0x0c07bf94u: goto P_0c07bf94;
case 0x0c07bf96u: goto P_0c07bf96;
case 0x0c07bf98u: goto P_0c07bf98;
case 0x0c07bf9au: goto P_0c07bf9a;
case 0x0c07bf9cu: goto P_0c07bf9c;
case 0x0c07bf9eu: goto P_0c07bf9e;
case 0x0c07bfa0u: goto P_0c07bfa0;
case 0x0c07bfa2u: goto P_0c07bfa2;
case 0x0c07bfa4u: goto P_0c07bfa4;
case 0x0c07bfa6u: goto P_0c07bfa6;
case 0x0c07bfa8u: goto P_0c07bfa8;
case 0x0c07bfaau: goto P_0c07bfaa;
case 0x0c07bfacu: goto P_0c07bfac;
case 0x0c07bfaeu: goto P_0c07bfae;
case 0x0c07bfb0u: goto P_0c07bfb0;
case 0x0c07bfb2u: goto P_0c07bfb2;
case 0x0c07bfb4u: goto P_0c07bfb4;
case 0x0c07bfb6u: goto P_0c07bfb6;
case 0x0c07bfb8u: goto P_0c07bfb8;
case 0x0c07bfbau: goto P_0c07bfba;
case 0x0c07bfbcu: goto P_0c07bfbc;
case 0x0c07bfbeu: goto P_0c07bfbe;
case 0x0c07bfc0u: goto P_0c07bfc0;
case 0x0c07bfc2u: goto P_0c07bfc2;
case 0x0c07bfc4u: goto P_0c07bfc4;
case 0x0c07bfc6u: goto P_0c07bfc6;
case 0x0c07bfc8u: goto P_0c07bfc8;
case 0x0c07bfcau: goto P_0c07bfca;
case 0x0c07bfccu: goto P_0c07bfcc;
case 0x0c07bfceu: goto P_0c07bfce;
case 0x0c07bfd0u: goto P_0c07bfd0;
case 0x0c07bfd2u: goto P_0c07bfd2;
case 0x0c07bfd4u: goto P_0c07bfd4;
case 0x0c07bfd6u: goto P_0c07bfd6;
case 0x0c07bfd8u: goto P_0c07bfd8;
case 0x0c07bfdau: goto P_0c07bfda;
case 0x0c07bfdcu: goto P_0c07bfdc;
case 0x0c07bfdeu: goto P_0c07bfde;
case 0x0c07bfe0u: goto P_0c07bfe0;
case 0x0c07bfe2u: goto P_0c07bfe2;
case 0x0c07bfe4u: goto P_0c07bfe4;
case 0x0c07bfe6u: goto P_0c07bfe6;
case 0x0c07bfe8u: goto P_0c07bfe8;
case 0x0c07bfeau: goto P_0c07bfea;
case 0x0c07bfecu: goto P_0c07bfec;
case 0x0c07bfeeu: goto P_0c07bfee;
case 0x0c07bff0u: goto P_0c07bff0;
case 0x0c07bff2u: goto P_0c07bff2;
case 0x0c07bff4u: goto P_0c07bff4;
case 0x0c07bff6u: goto P_0c07bff6;
case 0x0c07bff8u: goto P_0c07bff8;
case 0x0c07bffau: goto P_0c07bffa;
case 0x0c07bffcu: goto P_0c07bffc;
case 0x0c07bffeu: goto P_0c07bffe;
case 0x0c07c000u: goto P_0c07c000;
case 0x0c07c002u: goto P_0c07c002;
case 0x0c07c004u: goto P_0c07c004;
case 0x0c07c006u: goto P_0c07c006;
case 0x0c07c008u: goto P_0c07c008;
case 0x0c07c00au: goto P_0c07c00a;
case 0x0c07c00cu: goto P_0c07c00c;
case 0x0c07c00eu: goto P_0c07c00e;
case 0x0c07c010u: goto P_0c07c010;
case 0x0c07c012u: goto P_0c07c012;
case 0x0c07c014u: goto P_0c07c014;
case 0x0c07c016u: goto P_0c07c016;
case 0x0c07c018u: goto P_0c07c018;
case 0x0c07c01au: goto P_0c07c01a;
case 0x0c07c01cu: goto P_0c07c01c;
case 0x0c07c01eu: goto P_0c07c01e;
case 0x0c07c020u: goto P_0c07c020;
case 0x0c07c022u: goto P_0c07c022;
case 0x0c07c024u: goto P_0c07c024;
case 0x0c07c026u: goto P_0c07c026;
case 0x0c07c028u: goto P_0c07c028;
case 0x0c07c02au: goto P_0c07c02a;
case 0x0c07c02cu: goto P_0c07c02c;
case 0x0c07c02eu: goto P_0c07c02e;
case 0x0c07c030u: goto P_0c07c030;
case 0x0c07c032u: goto P_0c07c032;
case 0x0c07c034u: goto P_0c07c034;
case 0x0c07c036u: goto P_0c07c036;
case 0x0c07c038u: goto P_0c07c038;
case 0x0c07c03au: goto P_0c07c03a;
case 0x0c07c03cu: goto P_0c07c03c;
case 0x0c07c03eu: goto P_0c07c03e;
case 0x0c07c040u: goto P_0c07c040;
case 0x0c07c042u: goto P_0c07c042;
case 0x0c07c05cu: goto P_0c07c05c;
case 0x0c07c05eu: goto P_0c07c05e;
case 0x0c07c060u: goto P_0c07c060;
case 0x0c07c062u: goto P_0c07c062;
case 0x0c07c064u: goto P_0c07c064;
case 0x0c07c066u: goto P_0c07c066;
case 0x0c07c068u: goto P_0c07c068;
case 0x0c07c06au: goto P_0c07c06a;
case 0x0c07c06cu: goto P_0c07c06c;
case 0x0c07c06eu: goto P_0c07c06e;
case 0x0c07c070u: goto P_0c07c070;
case 0x0c07c072u: goto P_0c07c072;
case 0x0c07c074u: goto P_0c07c074;
case 0x0c07c076u: goto P_0c07c076;
case 0x0c07c078u: goto P_0c07c078;
case 0x0c07c07au: goto P_0c07c07a;
case 0x0c07c07cu: goto P_0c07c07c;
case 0x0c07c07eu: goto P_0c07c07e;
case 0x0c07c080u: goto P_0c07c080;
case 0x0c07c082u: goto P_0c07c082;
case 0x0c07c084u: goto P_0c07c084;
case 0x0c07c086u: goto P_0c07c086;
case 0x0c07c088u: goto P_0c07c088;
case 0x0c07c08au: goto P_0c07c08a;
case 0x0c07c08cu: goto P_0c07c08c;
case 0x0c07c08eu: goto P_0c07c08e;
case 0x0c07c090u: goto P_0c07c090;
case 0x0c07c092u: goto P_0c07c092;
case 0x0c07c094u: goto P_0c07c094;
case 0x0c07c096u: goto P_0c07c096;
case 0x0c07c098u: goto P_0c07c098;
case 0x0c07c09au: goto P_0c07c09a;
case 0x0c07c09cu: goto P_0c07c09c;
case 0x0c07c09eu: goto P_0c07c09e;
case 0x0c07c0a0u: goto P_0c07c0a0;
case 0x0c07c0a2u: goto P_0c07c0a2;
case 0x0c07c0a4u: goto P_0c07c0a4;
case 0x0c07c0a6u: goto P_0c07c0a6;
case 0x0c07c0a8u: goto P_0c07c0a8;
case 0x0c07c0aau: goto P_0c07c0aa;
case 0x0c07c0acu: goto P_0c07c0ac;
case 0x0c07c0aeu: goto P_0c07c0ae;
case 0x0c07c0b0u: goto P_0c07c0b0;
case 0x0c07c0b2u: goto P_0c07c0b2;
case 0x0c07c0b4u: goto P_0c07c0b4;
case 0x0c07c0b6u: goto P_0c07c0b6;
case 0x0c07c0b8u: goto P_0c07c0b8;
case 0x0c07c0bau: goto P_0c07c0ba;
case 0x0c07c0bcu: goto P_0c07c0bc;
case 0x0c07c0beu: goto P_0c07c0be;
case 0x0c07c0c0u: goto P_0c07c0c0;
case 0x0c07c0c2u: goto P_0c07c0c2;
case 0x0c07c0c4u: goto P_0c07c0c4;
case 0x0c07c0c6u: goto P_0c07c0c6;
case 0x0c07c0c8u: goto P_0c07c0c8;
case 0x0c07c0cau: goto P_0c07c0ca;
case 0x0c07c0ccu: goto P_0c07c0cc;
case 0x0c07c0ceu: goto P_0c07c0ce;
case 0x0c07c0d0u: goto P_0c07c0d0;
case 0x0c07c0d2u: goto P_0c07c0d2;
case 0x0c07c0d4u: goto P_0c07c0d4;
case 0x0c07c0d6u: goto P_0c07c0d6;
case 0x0c07c0d8u: goto P_0c07c0d8;
case 0x0c07c0dau: goto P_0c07c0da;
case 0x0c07c0dcu: goto P_0c07c0dc;
case 0x0c07c0deu: goto P_0c07c0de;
case 0x0c07c0e0u: goto P_0c07c0e0;
case 0x0c07c0e2u: goto P_0c07c0e2;
case 0x0c07c0e4u: goto P_0c07c0e4;
case 0x0c07c0e6u: goto P_0c07c0e6;
case 0x0c07c0e8u: goto P_0c07c0e8;
case 0x0c07c0eau: goto P_0c07c0ea;
case 0x0c07c0ecu: goto P_0c07c0ec;
case 0x0c07c0eeu: goto P_0c07c0ee;
case 0x0c07c0f0u: goto P_0c07c0f0;
case 0x0c07c0f2u: goto P_0c07c0f2;
case 0x0c07c0f4u: goto P_0c07c0f4;
case 0x0c07c0f6u: goto P_0c07c0f6;
case 0x0c07c0f8u: goto P_0c07c0f8;
case 0x0c07c0fau: goto P_0c07c0fa;
case 0x0c07c0fcu: goto P_0c07c0fc;
case 0x0c07c0feu: goto P_0c07c0fe;
case 0x0c07c100u: goto P_0c07c100;
case 0x0c07c102u: goto P_0c07c102;
case 0x0c07c12cu: goto P_0c07c12c;
case 0x0c07c12eu: goto P_0c07c12e;
case 0x0c07c130u: goto P_0c07c130;
case 0x0c07c132u: goto P_0c07c132;
case 0x0c07c134u: goto P_0c07c134;
case 0x0c07c136u: goto P_0c07c136;
case 0x0c07c138u: goto P_0c07c138;
case 0x0c07c13au: goto P_0c07c13a;
case 0x0c07c13cu: goto P_0c07c13c;
case 0x0c07c13eu: goto P_0c07c13e;
case 0x0c07c140u: goto P_0c07c140;
case 0x0c07c142u: goto P_0c07c142;
case 0x0c07c144u: goto P_0c07c144;
case 0x0c07c146u: goto P_0c07c146;
case 0x0c07c148u: goto P_0c07c148;
case 0x0c07c14au: goto P_0c07c14a;
case 0x0c07c14cu: goto P_0c07c14c;
case 0x0c07c14eu: goto P_0c07c14e;
case 0x0c07c150u: goto P_0c07c150;
case 0x0c07c152u: goto P_0c07c152;
case 0x0c07c154u: goto P_0c07c154;
case 0x0c07c156u: goto P_0c07c156;
case 0x0c07c158u: goto P_0c07c158;
case 0x0c07c15au: goto P_0c07c15a;
case 0x0c07c15cu: goto P_0c07c15c;
case 0x0c07c15eu: goto P_0c07c15e;
case 0x0c07c160u: goto P_0c07c160;
case 0x0c07c162u: goto P_0c07c162;
case 0x0c07c164u: goto P_0c07c164;
case 0x0c07c166u: goto P_0c07c166;
case 0x0c07c168u: goto P_0c07c168;
case 0x0c07c16au: goto P_0c07c16a;
case 0x0c07c16cu: goto P_0c07c16c;
case 0x0c07c16eu: goto P_0c07c16e;
case 0x0c07c170u: goto P_0c07c170;
case 0x0c07c172u: goto P_0c07c172;
case 0x0c07c174u: goto P_0c07c174;
case 0x0c07c176u: goto P_0c07c176;
case 0x0c07c178u: goto P_0c07c178;
case 0x0c07c17au: goto P_0c07c17a;
case 0x0c07c17cu: goto P_0c07c17c;
case 0x0c07c17eu: goto P_0c07c17e;
case 0x0c07c180u: goto P_0c07c180;
case 0x0c07c182u: goto P_0c07c182;
case 0x0c07c184u: goto P_0c07c184;
case 0x0c07c186u: goto P_0c07c186;
case 0x0c07c188u: goto P_0c07c188;
case 0x0c07c18au: goto P_0c07c18a;
case 0x0c07c18cu: goto P_0c07c18c;
case 0x0c07c18eu: goto P_0c07c18e;
case 0x0c07c190u: goto P_0c07c190;
case 0x0c07c192u: goto P_0c07c192;
case 0x0c07c194u: goto P_0c07c194;
case 0x0c07c196u: goto P_0c07c196;
case 0x0c07c198u: goto P_0c07c198;
case 0x0c07c19au: goto P_0c07c19a;
case 0x0c07c19cu: goto P_0c07c19c;
case 0x0c07c19eu: goto P_0c07c19e;
case 0x0c07c1a0u: goto P_0c07c1a0;
case 0x0c07c1a2u: goto P_0c07c1a2;
case 0x0c07c1a4u: goto P_0c07c1a4;
case 0x0c07c1a6u: goto P_0c07c1a6;
case 0x0c07c1a8u: goto P_0c07c1a8;
case 0x0c07c1aau: goto P_0c07c1aa;
case 0x0c07c1acu: goto P_0c07c1ac;
case 0x0c07c1aeu: goto P_0c07c1ae;
case 0x0c07c1b0u: goto P_0c07c1b0;
case 0x0c07c1b2u: goto P_0c07c1b2;
case 0x0c07c1b4u: goto P_0c07c1b4;
case 0x0c07c1b6u: goto P_0c07c1b6;
case 0x0c07c1b8u: goto P_0c07c1b8;
case 0x0c07c1bau: goto P_0c07c1ba;
case 0x0c07c1bcu: goto P_0c07c1bc;
case 0x0c07c1beu: goto P_0c07c1be;
case 0x0c07c1c0u: goto P_0c07c1c0;
case 0x0c07c1c2u: goto P_0c07c1c2;
case 0x0c07c1c4u: goto P_0c07c1c4;
case 0x0c07c1c6u: goto P_0c07c1c6;
case 0x0c07c1c8u: goto P_0c07c1c8;
case 0x0c07c1cau: goto P_0c07c1ca;
case 0x0c07c1ccu: goto P_0c07c1cc;
case 0x0c07c1ceu: goto P_0c07c1ce;
case 0x0c07c1d0u: goto P_0c07c1d0;
case 0x0c07c1d2u: goto P_0c07c1d2;
case 0x0c07c1d4u: goto P_0c07c1d4;
case 0x0c07c1d6u: goto P_0c07c1d6;
case 0x0c07c1d8u: goto P_0c07c1d8;
case 0x0c07c1dau: goto P_0c07c1da;
case 0x0c07c1dcu: goto P_0c07c1dc;
case 0x0c07c1deu: goto P_0c07c1de;
case 0x0c07c1e0u: goto P_0c07c1e0;
case 0x0c07c1e2u: goto P_0c07c1e2;
case 0x0c07c1e4u: goto P_0c07c1e4;
case 0x0c07c1e6u: goto P_0c07c1e6;
case 0x0c07c1e8u: goto P_0c07c1e8;
case 0x0c07c1eau: goto P_0c07c1ea;
case 0x0c07c1ecu: goto P_0c07c1ec;
case 0x0c07c1eeu: goto P_0c07c1ee;
case 0x0c07c1f0u: goto P_0c07c1f0;
case 0x0c07c1f2u: goto P_0c07c1f2;
case 0x0c07c1f4u: goto P_0c07c1f4;
case 0x0c07c1f6u: goto P_0c07c1f6;
case 0x0c07c1f8u: goto P_0c07c1f8;
case 0x0c07c1fau: goto P_0c07c1fa;
case 0x0c07c1fcu: goto P_0c07c1fc;
case 0x0c07c1feu: goto P_0c07c1fe;
case 0x0c07c200u: goto P_0c07c200;
case 0x0c07c202u: goto P_0c07c202;
case 0x0c07c204u: goto P_0c07c204;
case 0x0c07c206u: goto P_0c07c206;
case 0x0c07c208u: goto P_0c07c208;
case 0x0c07c20au: goto P_0c07c20a;
case 0x0c07c20cu: goto P_0c07c20c;
case 0x0c07c20eu: goto P_0c07c20e;
case 0x0c07c210u: goto P_0c07c210;
case 0x0c07c212u: goto P_0c07c212;
case 0x0c07c214u: goto P_0c07c214;
case 0x0c07c216u: goto P_0c07c216;
case 0x0c07c218u: goto P_0c07c218;
case 0x0c07c21au: goto P_0c07c21a;
case 0x0c07c21cu: goto P_0c07c21c;
case 0x0c07c21eu: goto P_0c07c21e;
case 0x0c07c220u: goto P_0c07c220;
case 0x0c07c222u: goto P_0c07c222;
case 0x0c07c224u: goto P_0c07c224;
case 0x0c07c226u: goto P_0c07c226;
case 0x0c07c228u: goto P_0c07c228;
case 0x0c07c22au: goto P_0c07c22a;
case 0x0c07c22cu: goto P_0c07c22c;
case 0x0c07c22eu: goto P_0c07c22e;
case 0x0c07c230u: goto P_0c07c230;
case 0x0c07c232u: goto P_0c07c232;
case 0x0c07c234u: goto P_0c07c234;
case 0x0c07c236u: goto P_0c07c236;
case 0x0c07c238u: goto P_0c07c238;
case 0x0c07c23au: goto P_0c07c23a;
case 0x0c07c23cu: goto P_0c07c23c;
case 0x0c07c23eu: goto P_0c07c23e;
case 0x0c07c240u: goto P_0c07c240;
case 0x0c07c242u: goto P_0c07c242;
case 0x0c07c244u: goto P_0c07c244;
case 0x0c07c246u: goto P_0c07c246;
case 0x0c07c248u: goto P_0c07c248;
case 0x0c07c24au: goto P_0c07c24a;
case 0x0c07c24cu: goto P_0c07c24c;
case 0x0c07c24eu: goto P_0c07c24e;
case 0x0c07c250u: goto P_0c07c250;
case 0x0c07c252u: goto P_0c07c252;
case 0x0c07c254u: goto P_0c07c254;
case 0x0c07c256u: goto P_0c07c256;
case 0x0c07c258u: goto P_0c07c258;
case 0x0c07c25au: goto P_0c07c25a;
case 0x0c07c25cu: goto P_0c07c25c;
case 0x0c07c25eu: goto P_0c07c25e;
case 0x0c07c260u: goto P_0c07c260;
case 0x0c07c262u: goto P_0c07c262;
case 0x0c07c264u: goto P_0c07c264;
case 0x0c07c266u: goto P_0c07c266;
case 0x0c07c268u: goto P_0c07c268;
case 0x0c07c26au: goto P_0c07c26a;
case 0x0c07c26cu: goto P_0c07c26c;
case 0x0c07c26eu: goto P_0c07c26e;
case 0x0c07c270u: goto P_0c07c270;
case 0x0c07c272u: goto P_0c07c272;
case 0x0c07c274u: goto P_0c07c274;
case 0x0c07c276u: goto P_0c07c276;
case 0x0c07c278u: goto P_0c07c278;
case 0x0c07c27au: goto P_0c07c27a;
case 0x0c07c27cu: goto P_0c07c27c;
case 0x0c07c27eu: goto P_0c07c27e;
case 0x0c07c280u: goto P_0c07c280;
case 0x0c07c282u: goto P_0c07c282;
case 0x0c07c284u: goto P_0c07c284;
case 0x0c07c286u: goto P_0c07c286;
case 0x0c07c288u: goto P_0c07c288;
case 0x0c07c28au: goto P_0c07c28a;
case 0x0c07c28cu: goto P_0c07c28c;
case 0x0c07c28eu: goto P_0c07c28e;
case 0x0c07c290u: goto P_0c07c290;
case 0x0c07c292u: goto P_0c07c292;
case 0x0c07c294u: goto P_0c07c294;
case 0x0c07c296u: goto P_0c07c296;
case 0x0c07c298u: goto P_0c07c298;
case 0x0c07c29au: goto P_0c07c29a;
case 0x0c07c29cu: goto P_0c07c29c;
case 0x0c07c29eu: goto P_0c07c29e;
case 0x0c07c2a0u: goto P_0c07c2a0;
case 0x0c07c2a2u: goto P_0c07c2a2;
case 0x0c07c2a4u: goto P_0c07c2a4;
case 0x0c07c2a6u: goto P_0c07c2a6;
case 0x0c07c2a8u: goto P_0c07c2a8;
case 0x0c07c2aau: goto P_0c07c2aa;
case 0x0c07c2acu: goto P_0c07c2ac;
case 0x0c07c2aeu: goto P_0c07c2ae;
case 0x0c07c2b0u: goto P_0c07c2b0;
case 0x0c07c2b2u: goto P_0c07c2b2;
case 0x0c07c2b4u: goto P_0c07c2b4;
case 0x0c07c2d0u: goto P_0c07c2d0;
case 0x0c07c2d2u: goto P_0c07c2d2;
case 0x0c07c2d4u: goto P_0c07c2d4;
case 0x0c07c2d6u: goto P_0c07c2d6;
case 0x0c07c2d8u: goto P_0c07c2d8;
case 0x0c07c2dau: goto P_0c07c2da;
case 0x0c07c2dcu: goto P_0c07c2dc;
case 0x0c07c2deu: goto P_0c07c2de;
case 0x0c07c2e0u: goto P_0c07c2e0;
case 0x0c07c2e2u: goto P_0c07c2e2;
case 0x0c07c2e4u: goto P_0c07c2e4;
case 0x0c07c2e6u: goto P_0c07c2e6;
case 0x0c07c2e8u: goto P_0c07c2e8;
case 0x0c07c2eau: goto P_0c07c2ea;
case 0x0c07c2ecu: goto P_0c07c2ec;
case 0x0c07c2eeu: goto P_0c07c2ee;
case 0x0c07c2f0u: goto P_0c07c2f0;
case 0x0c07c2f2u: goto P_0c07c2f2;
case 0x0c07c2f4u: goto P_0c07c2f4;
case 0x0c07c2f6u: goto P_0c07c2f6;
case 0x0c07c2f8u: goto P_0c07c2f8;
case 0x0c07c2fau: goto P_0c07c2fa;
case 0x0c07c2fcu: goto P_0c07c2fc;
case 0x0c07c2feu: goto P_0c07c2fe;
case 0x0c07c300u: goto P_0c07c300;
case 0x0c07c302u: goto P_0c07c302;
case 0x0c07c304u: goto P_0c07c304;
case 0x0c07c306u: goto P_0c07c306;
case 0x0c07c308u: goto P_0c07c308;
case 0x0c07c30au: goto P_0c07c30a;
case 0x0c07c30cu: goto P_0c07c30c;
case 0x0c07c30eu: goto P_0c07c30e;
case 0x0c07c310u: goto P_0c07c310;
case 0x0c07c312u: goto P_0c07c312;
case 0x0c07c314u: goto P_0c07c314;
case 0x0c07c316u: goto P_0c07c316;
case 0x0c07c318u: goto P_0c07c318;
case 0x0c07c31au: goto P_0c07c31a;
case 0x0c07c31cu: goto P_0c07c31c;
case 0x0c07c31eu: goto P_0c07c31e;
case 0x0c07c320u: goto P_0c07c320;
case 0x0c07c322u: goto P_0c07c322;
case 0x0c07c324u: goto P_0c07c324;
case 0x0c07c326u: goto P_0c07c326;
case 0x0c07c328u: goto P_0c07c328;
case 0x0c07c32au: goto P_0c07c32a;
case 0x0c07c32cu: goto P_0c07c32c;
case 0x0c07c32eu: goto P_0c07c32e;
case 0x0c07c330u: goto P_0c07c330;
case 0x0c07c332u: goto P_0c07c332;
case 0x0c07c446u: goto P_0c07c446;
case 0x0c07c448u: goto P_0c07c448;
case 0x0c07c44au: goto P_0c07c44a;
case 0x0c07c44cu: goto P_0c07c44c;
case 0x0c07c44eu: goto P_0c07c44e;
case 0x0c07c450u: goto P_0c07c450;
case 0x0c07c452u: goto P_0c07c452;
case 0x0c07c454u: goto P_0c07c454;
case 0x0c07c456u: goto P_0c07c456;
case 0x0c07c458u: goto P_0c07c458;
case 0x0c07c45au: goto P_0c07c45a;
case 0x0c07c45cu: goto P_0c07c45c;
case 0x0c07c45eu: goto P_0c07c45e;
case 0x0c07c460u: goto P_0c07c460;
case 0x0c07c462u: goto P_0c07c462;
case 0x0c07c464u: goto P_0c07c464;
case 0x0c07c466u: goto P_0c07c466;
case 0x0c07c468u: goto P_0c07c468;
case 0x0c07c46au: goto P_0c07c46a;
case 0x0c07c46cu: goto P_0c07c46c;
case 0x0c07c46eu: goto P_0c07c46e;
case 0x0c07c470u: goto P_0c07c470;
case 0x0c07c472u: goto P_0c07c472;
case 0x0c07c474u: goto P_0c07c474;
case 0x0c07c476u: goto P_0c07c476;
case 0x0c07c478u: goto P_0c07c478;
case 0x0c07c47au: goto P_0c07c47a;
case 0x0c07c47cu: goto P_0c07c47c;
case 0x0c07c47eu: goto P_0c07c47e;
case 0x0c07c480u: goto P_0c07c480;
case 0x0c07c482u: goto P_0c07c482;
case 0x0c07c484u: goto P_0c07c484;
case 0x0c07c486u: goto P_0c07c486;
case 0x0c07c488u: goto P_0c07c488;
case 0x0c07c48au: goto P_0c07c48a;
case 0x0c07c48cu: goto P_0c07c48c;
case 0x0c07c48eu: goto P_0c07c48e;
case 0x0c07c490u: goto P_0c07c490;
case 0x0c07c492u: goto P_0c07c492;
case 0x0c07c494u: goto P_0c07c494;
case 0x0c07c496u: goto P_0c07c496;
case 0x0c07c498u: goto P_0c07c498;
case 0x0c07c49au: goto P_0c07c49a;
case 0x0c07c49cu: goto P_0c07c49c;
case 0x0c07c49eu: goto P_0c07c49e;
case 0x0c07c4a0u: goto P_0c07c4a0;
case 0x0c07c4a6u: goto P_0c07c4a6;
case 0x0c07c4a8u: goto P_0c07c4a8;
case 0x0c07c4aau: goto P_0c07c4aa;
case 0x0c07c4acu: goto P_0c07c4ac;
case 0x0c07c4aeu: goto P_0c07c4ae;
case 0x0c07c4b0u: goto P_0c07c4b0;
case 0x0c07c4b2u: goto P_0c07c4b2;
case 0x0c07c4b4u: goto P_0c07c4b4;
case 0x0c07c4b6u: goto P_0c07c4b6;
case 0x0c07c4b8u: goto P_0c07c4b8;
case 0x0c07c4bau: goto P_0c07c4ba;
case 0x0c07c4bcu: goto P_0c07c4bc;
case 0x0c07c4beu: goto P_0c07c4be;
case 0x0c07c4c0u: goto P_0c07c4c0;
case 0x0c07c4c2u: goto P_0c07c4c2;
case 0x0c07c4c4u: goto P_0c07c4c4;
case 0x0c07c4c6u: goto P_0c07c4c6;
case 0x0c07c4c8u: goto P_0c07c4c8;
case 0x0c07c4cau: goto P_0c07c4ca;
case 0x0c07c4ccu: goto P_0c07c4cc;
case 0x0c07c4ceu: goto P_0c07c4ce;
case 0x0c07c4d0u: goto P_0c07c4d0;
case 0x0c07c4d2u: goto P_0c07c4d2;
case 0x0c07c4d4u: goto P_0c07c4d4;
case 0x0c07c4d6u: goto P_0c07c4d6;
case 0x0c07c4d8u: goto P_0c07c4d8;
case 0x0c07c4dau: goto P_0c07c4da;
case 0x0c07c4dcu: goto P_0c07c4dc;
case 0x0c07c4deu: goto P_0c07c4de;
case 0x0c07c4e0u: goto P_0c07c4e0;
case 0x0c07c4e2u: goto P_0c07c4e2;
case 0x0c07c4e4u: goto P_0c07c4e4;
case 0x0c07c4e6u: goto P_0c07c4e6;
case 0x0c07c4e8u: goto P_0c07c4e8;
case 0x0c07c4eau: goto P_0c07c4ea;
case 0x0c07c4ecu: goto P_0c07c4ec;
case 0x0c07c4eeu: goto P_0c07c4ee;
case 0x0c07c4f0u: goto P_0c07c4f0;
case 0x0c07c4f2u: goto P_0c07c4f2;
case 0x0c07c4f4u: goto P_0c07c4f4;
case 0x0c07c4f6u: goto P_0c07c4f6;
case 0x0c07c4f8u: goto P_0c07c4f8;
case 0x0c07c4fau: goto P_0c07c4fa;
case 0x0c07c4fcu: goto P_0c07c4fc;
case 0x0c07c4feu: goto P_0c07c4fe;
case 0x0c07c500u: goto P_0c07c500;
case 0x0c07c502u: goto P_0c07c502;
case 0x0c07c504u: goto P_0c07c504;
case 0x0c07c6b6u: goto P_0c07c6b6;
case 0x0c07c6b8u: goto P_0c07c6b8;
case 0x0c07c6bau: goto P_0c07c6ba;
case 0x0c07c6bcu: goto P_0c07c6bc;
case 0x0c07c6beu: goto P_0c07c6be;
case 0x0c07c6c0u: goto P_0c07c6c0;
case 0x0c07c6c2u: goto P_0c07c6c2;
case 0x0c07c6c4u: goto P_0c07c6c4;
case 0x0c07c6c6u: goto P_0c07c6c6;
case 0x0c07c6c8u: goto P_0c07c6c8;
case 0x0c07c6cau: goto P_0c07c6ca;
case 0x0c07c6ccu: goto P_0c07c6cc;
case 0x0c07c6ceu: goto P_0c07c6ce;
case 0x0c07c6d0u: goto P_0c07c6d0;
case 0x0c07c6d2u: goto P_0c07c6d2;
case 0x0c07c6d4u: goto P_0c07c6d4;
case 0x0c07c6d6u: goto P_0c07c6d6;
case 0x0c07c6d8u: goto P_0c07c6d8;
case 0x0c07c6dau: goto P_0c07c6da;
case 0x0c07c6dcu: goto P_0c07c6dc;
case 0x0c07c6deu: goto P_0c07c6de;
case 0x0c07c6e0u: goto P_0c07c6e0;
case 0x0c07c6e2u: goto P_0c07c6e2;
case 0x0c07c6e4u: goto P_0c07c6e4;
case 0x0c07c6e6u: goto P_0c07c6e6;
case 0x0c07c6e8u: goto P_0c07c6e8;
case 0x0c07c6eau: goto P_0c07c6ea;
case 0x0c07c6ecu: goto P_0c07c6ec;
case 0x0c07c6eeu: goto P_0c07c6ee;
case 0x0c07c6f0u: goto P_0c07c6f0;
case 0x0c07c6f2u: goto P_0c07c6f2;
case 0x0c07c6f4u: goto P_0c07c6f4;
case 0x0c07c6f6u: goto P_0c07c6f6;
case 0x0c07c6f8u: goto P_0c07c6f8;
case 0x0c07c6fau: goto P_0c07c6fa;
case 0x0c07c6fcu: goto P_0c07c6fc;
case 0x0c07c6feu: goto P_0c07c6fe;
case 0x0c07c700u: goto P_0c07c700;
case 0x0c07c702u: goto P_0c07c702;
case 0x0c07c704u: goto P_0c07c704;
case 0x0c07c706u: goto P_0c07c706;
case 0x0c07c708u: goto P_0c07c708;
case 0x0c07c70au: goto P_0c07c70a;
case 0x0c07c70cu: goto P_0c07c70c;
case 0x0c07c70eu: goto P_0c07c70e;
case 0x0c07c710u: goto P_0c07c710;
case 0x0c07c712u: goto P_0c07c712;
case 0x0c07c714u: goto P_0c07c714;
case 0x0c07c716u: goto P_0c07c716;
case 0x0c07c718u: goto P_0c07c718;
case 0x0c07c71au: goto P_0c07c71a;
case 0x0c07c71cu: goto P_0c07c71c;
case 0x0c07c71eu: goto P_0c07c71e;
case 0x0c07c720u: goto P_0c07c720;
case 0x0c07c722u: goto P_0c07c722;
case 0x0c07c724u: goto P_0c07c724;
case 0x0c07c726u: goto P_0c07c726;
case 0x0c07c728u: goto P_0c07c728;
case 0x0c07c72au: goto P_0c07c72a;
case 0x0c07c72cu: goto P_0c07c72c;
case 0x0c07c72eu: goto P_0c07c72e;
case 0x0c07c730u: goto P_0c07c730;
case 0x0c07c732u: goto P_0c07c732;
case 0x0c07c734u: goto P_0c07c734;
case 0x0c07c736u: goto P_0c07c736;
case 0x0c07c738u: goto P_0c07c738;
case 0x0c07c73au: goto P_0c07c73a;
case 0x0c07c73cu: goto P_0c07c73c;
case 0x0c07c73eu: goto P_0c07c73e;
case 0x0c07c740u: goto P_0c07c740;
case 0x0c07c742u: goto P_0c07c742;
case 0x0c07c744u: goto P_0c07c744;
case 0x0c07c746u: goto P_0c07c746;
case 0x0c07c748u: goto P_0c07c748;
case 0x0c07c74au: goto P_0c07c74a;
case 0x0c07c74cu: goto P_0c07c74c;
case 0x0c07c74eu: goto P_0c07c74e;
case 0x0c07c750u: goto P_0c07c750;
case 0x0c07c752u: goto P_0c07c752;
case 0x0c07c754u: goto P_0c07c754;
case 0x0c07c756u: goto P_0c07c756;
case 0x0c07c758u: goto P_0c07c758;
case 0x0c07c75au: goto P_0c07c75a;
case 0x0c07c75cu: goto P_0c07c75c;
case 0x0c07c75eu: goto P_0c07c75e;
case 0x0c07c760u: goto P_0c07c760;
case 0x0c07c762u: goto P_0c07c762;
case 0x0c07c764u: goto P_0c07c764;
case 0x0c07c766u: goto P_0c07c766;
case 0x0c07c768u: goto P_0c07c768;
case 0x0c07c76au: goto P_0c07c76a;
case 0x0c07c76cu: goto P_0c07c76c;
case 0x0c07c76eu: goto P_0c07c76e;
case 0x0c07c770u: goto P_0c07c770;
case 0x0c07fbecu: goto P_0c07fbec;
case 0x0c07fbeeu: goto P_0c07fbee;
case 0x0c07fbf0u: goto P_0c07fbf0;
case 0x0c07fbf2u: goto P_0c07fbf2;
case 0x0c07fbf4u: goto P_0c07fbf4;
case 0x0c07fbf6u: goto P_0c07fbf6;
case 0x0c07fbf8u: goto P_0c07fbf8;
case 0x0c07fbfau: goto P_0c07fbfa;
case 0x0c07fbfcu: goto P_0c07fbfc;
case 0x0c07fbfeu: goto P_0c07fbfe;
case 0x0c07fc00u: goto P_0c07fc00;
case 0x0c07fc02u: goto P_0c07fc02;
case 0x0c07fc04u: goto P_0c07fc04;
case 0x0c07fc06u: goto P_0c07fc06;
case 0x0c07fc08u: goto P_0c07fc08;
case 0x0c07fc0au: goto P_0c07fc0a;
case 0x0c07fc0cu: goto P_0c07fc0c;
case 0x0c07fc0eu: goto P_0c07fc0e;
case 0x0c07fc10u: goto P_0c07fc10;
case 0x0c07fc12u: goto P_0c07fc12;
case 0x0c07fc14u: goto P_0c07fc14;
case 0x0c07fc16u: goto P_0c07fc16;
case 0x0c07fc18u: goto P_0c07fc18;
case 0x0c07fc1au: goto P_0c07fc1a;
case 0x0c07fc1cu: goto P_0c07fc1c;
case 0x0c07fc1eu: goto P_0c07fc1e;
case 0x0c07fc20u: goto P_0c07fc20;
case 0x0c07fc22u: goto P_0c07fc22;
case 0x0c07fc24u: goto P_0c07fc24;
case 0x0c07fc26u: goto P_0c07fc26;
case 0x0c07fc28u: goto P_0c07fc28;
case 0x0c07fc2au: goto P_0c07fc2a;
case 0x0c07fc2cu: goto P_0c07fc2c;
case 0x0c07fc2eu: goto P_0c07fc2e;
case 0x0c07fc30u: goto P_0c07fc30;
case 0x0c07fc32u: goto P_0c07fc32;
case 0x0c07fc34u: goto P_0c07fc34;
case 0x0c07fc36u: goto P_0c07fc36;
case 0x0c07fc38u: goto P_0c07fc38;
case 0x0c07fc3au: goto P_0c07fc3a;
case 0x0c07fc3cu: goto P_0c07fc3c;
case 0x0c07fc3eu: goto P_0c07fc3e;
case 0x0c07fc40u: goto P_0c07fc40;
case 0x0c07fc42u: goto P_0c07fc42;
case 0x0c07fc44u: goto P_0c07fc44;
case 0x0c07fc46u: goto P_0c07fc46;
case 0x0c07fc48u: goto P_0c07fc48;
case 0x0c07fc4au: goto P_0c07fc4a;
case 0x0c07fc4cu: goto P_0c07fc4c;
case 0x0c07fc4eu: goto P_0c07fc4e;
case 0x0c07fc50u: goto P_0c07fc50;
case 0x0c07fc52u: goto P_0c07fc52;
case 0x0c08430eu: goto P_0c08430e;
case 0x0c084310u: goto P_0c084310;
case 0x0c084312u: goto P_0c084312;
case 0x0c084314u: goto P_0c084314;
case 0x0c084316u: goto P_0c084316;
case 0x0c084318u: goto P_0c084318;
case 0x0c08431au: goto P_0c08431a;
case 0x0c08431cu: goto P_0c08431c;
case 0x0c08431eu: goto P_0c08431e;
case 0x0c084320u: goto P_0c084320;
case 0x0c084322u: goto P_0c084322;
case 0x0c084324u: goto P_0c084324;
case 0x0c084326u: goto P_0c084326;
case 0x0c084328u: goto P_0c084328;
case 0x0c08432au: goto P_0c08432a;
case 0x0c08432cu: goto P_0c08432c;
case 0x0c08432eu: goto P_0c08432e;
case 0x0c084330u: goto P_0c084330;
case 0x0c084332u: goto P_0c084332;
case 0x0c084334u: goto P_0c084334;
case 0x0c084336u: goto P_0c084336;
case 0x0c084338u: goto P_0c084338;
case 0x0c08433au: goto P_0c08433a;
case 0x0c08433cu: goto P_0c08433c;
case 0x0c08433eu: goto P_0c08433e;
case 0x0c084340u: goto P_0c084340;
case 0x0c084342u: goto P_0c084342;
case 0x0c084344u: goto P_0c084344;
case 0x0c084346u: goto P_0c084346;
case 0x0c084348u: goto P_0c084348;
case 0x0c08434au: goto P_0c08434a;
case 0x0c08434cu: goto P_0c08434c;
case 0x0c08434eu: goto P_0c08434e;
case 0x0c084350u: goto P_0c084350;
case 0x0c084352u: goto P_0c084352;
case 0x0c084354u: goto P_0c084354;
case 0x0c084356u: goto P_0c084356;
case 0x0c084358u: goto P_0c084358;
case 0x0c08435au: goto P_0c08435a;
case 0x0c08435cu: goto P_0c08435c;
case 0x0c08435eu: goto P_0c08435e;
case 0x0c084360u: goto P_0c084360;
case 0x0c084362u: goto P_0c084362;
case 0x0c084364u: goto P_0c084364;
case 0x0c084366u: goto P_0c084366;
case 0x0c084368u: goto P_0c084368;
case 0x0c08436au: goto P_0c08436a;
case 0x0c08436cu: goto P_0c08436c;
case 0x0c08436eu: goto P_0c08436e;
case 0x0c084370u: goto P_0c084370;
case 0x0c084372u: goto P_0c084372;
case 0x0c084374u: goto P_0c084374;
case 0x0c084376u: goto P_0c084376;
case 0x0c084378u: goto P_0c084378;
case 0x0c08437au: goto P_0c08437a;
case 0x0c08437cu: goto P_0c08437c;
case 0x0c08437eu: goto P_0c08437e;
case 0x0c084380u: goto P_0c084380;
case 0x0c084382u: goto P_0c084382;
case 0x0c084384u: goto P_0c084384;
case 0x0c084386u: goto P_0c084386;
case 0x0c084388u: goto P_0c084388;
case 0x0c08438au: goto P_0c08438a;
case 0x0c08438cu: goto P_0c08438c;
case 0x0c08438eu: goto P_0c08438e;
case 0x0c084390u: goto P_0c084390;
case 0x0c084392u: goto P_0c084392;
case 0x0c084394u: goto P_0c084394;
case 0x0c084396u: goto P_0c084396;
case 0x0c084398u: goto P_0c084398;
case 0x0c08439au: goto P_0c08439a;
case 0x0c089348u: goto P_0c089348;
case 0x0c08934au: goto P_0c08934a;
case 0x0c08934cu: goto P_0c08934c;
case 0x0c08934eu: goto P_0c08934e;
case 0x0c089350u: goto P_0c089350;
case 0x0c089352u: goto P_0c089352;
case 0x0c089354u: goto P_0c089354;
case 0x0c089356u: goto P_0c089356;
case 0x0c089358u: goto P_0c089358;
case 0x0c0893c6u: goto P_0c0893c6;
case 0x0c0893c8u: goto P_0c0893c8;
case 0x0c0893cau: goto P_0c0893ca;
case 0x0c0893e4u: goto P_0c0893e4;
case 0x0c0893e6u: goto P_0c0893e6;
case 0x0c0893e8u: goto P_0c0893e8;
case 0x0c0893eau: goto P_0c0893ea;
case 0x0c0893ecu: goto P_0c0893ec;
case 0x0c0893eeu: goto P_0c0893ee;
case 0x0c0893f0u: goto P_0c0893f0;
case 0x0c0893f2u: goto P_0c0893f2;
case 0x0c0893f4u: goto P_0c0893f4;
case 0x0c0893f6u: goto P_0c0893f6;
case 0x0c0893f8u: goto P_0c0893f8;
case 0x0c0893fau: goto P_0c0893fa;
case 0x0c0893fcu: goto P_0c0893fc;
case 0x0c0893feu: goto P_0c0893fe;
case 0x0c089400u: goto P_0c089400;
case 0x0c089402u: goto P_0c089402;
case 0x0c089404u: goto P_0c089404;
case 0x0c089406u: goto P_0c089406;
case 0x0c089408u: goto P_0c089408;
case 0x0c08940au: goto P_0c08940a;
case 0x0c08940cu: goto P_0c08940c;
case 0x0c08940eu: goto P_0c08940e;
case 0x0c089410u: goto P_0c089410;
case 0x0c089412u: goto P_0c089412;
case 0x0c089414u: goto P_0c089414;
case 0x0c089416u: goto P_0c089416;
case 0x0c089418u: goto P_0c089418;
case 0x0c08941au: goto P_0c08941a;
case 0x0c08941cu: goto P_0c08941c;
case 0x0c08941eu: goto P_0c08941e;
case 0x0c089420u: goto P_0c089420;
case 0x0c089422u: goto P_0c089422;
case 0x0c089424u: goto P_0c089424;
case 0x0c090aa0u: goto P_0c090aa0;
case 0x0c090aa2u: goto P_0c090aa2;
case 0x0c090aa4u: goto P_0c090aa4;
case 0x0c090aa6u: goto P_0c090aa6;
case 0x0c090aa8u: goto P_0c090aa8;
case 0x0c090aaau: goto P_0c090aaa;
case 0x0c090aacu: goto P_0c090aac;
case 0x0c090aaeu: goto P_0c090aae;
case 0x0c0910beu: goto P_0c0910be;
case 0x0c0910c0u: goto P_0c0910c0;
case 0x0c0910c2u: goto P_0c0910c2;
case 0x0c0910c4u: goto P_0c0910c4;
case 0x0c0910c6u: goto P_0c0910c6;
case 0x0c0910c8u: goto P_0c0910c8;
case 0x0c0910cau: goto P_0c0910ca;
case 0x0c0910ccu: goto P_0c0910cc;
case 0x0c0910ceu: goto P_0c0910ce;
case 0x0c0910d0u: goto P_0c0910d0;
case 0x0c0910d2u: goto P_0c0910d2;
case 0x0c0910d4u: goto P_0c0910d4;
case 0x0c0910d6u: goto P_0c0910d6;
case 0x0c0910d8u: goto P_0c0910d8;
case 0x0c0910dau: goto P_0c0910da;
case 0x0c0910dcu: goto P_0c0910dc;
case 0x0c0910deu: goto P_0c0910de;
case 0x0c0910e0u: goto P_0c0910e0;
case 0x0c0910e2u: goto P_0c0910e2;
case 0x0c0910e4u: goto P_0c0910e4;
case 0x0c0910e6u: goto P_0c0910e6;
case 0x0c0910e8u: goto P_0c0910e8;
case 0x0c0910eau: goto P_0c0910ea;
case 0x0c0910ecu: goto P_0c0910ec;
case 0x0c0910eeu: goto P_0c0910ee;
case 0x0c0910f0u: goto P_0c0910f0;
case 0x0c0910f2u: goto P_0c0910f2;
case 0x0c0910f4u: goto P_0c0910f4;
case 0x0c0910f6u: goto P_0c0910f6;
case 0x0c0910f8u: goto P_0c0910f8;
case 0x0c0910fau: goto P_0c0910fa;
case 0x0c0910fcu: goto P_0c0910fc;
case 0x0c0910feu: goto P_0c0910fe;
case 0x0c091100u: goto P_0c091100;
case 0x0c091102u: goto P_0c091102;
case 0x0c091104u: goto P_0c091104;
case 0x0c091106u: goto P_0c091106;
case 0x0c091108u: goto P_0c091108;
case 0x0c09110au: goto P_0c09110a;
case 0x0c09110cu: goto P_0c09110c;
case 0x0c09110eu: goto P_0c09110e;
case 0x0c091110u: goto P_0c091110;
case 0x0c091112u: goto P_0c091112;
case 0x0c091114u: goto P_0c091114;
case 0x0c091116u: goto P_0c091116;
case 0x0c091118u: goto P_0c091118;
case 0x0c09111au: goto P_0c09111a;
case 0x0c09111cu: goto P_0c09111c;
case 0x0c09111eu: goto P_0c09111e;
case 0x0c091120u: goto P_0c091120;
case 0x0c091122u: goto P_0c091122;
case 0x0c091124u: goto P_0c091124;
case 0x0c091126u: goto P_0c091126;
case 0x0c091128u: goto P_0c091128;
case 0x0c09112au: goto P_0c09112a;
case 0x0c09112cu: goto P_0c09112c;
case 0x0c09112eu: goto P_0c09112e;
case 0x0c091130u: goto P_0c091130;
case 0x0c091132u: goto P_0c091132;
case 0x0c091134u: goto P_0c091134;
case 0x0c091136u: goto P_0c091136;
case 0x0c091138u: goto P_0c091138;
case 0x0c09113au: goto P_0c09113a;
case 0x0c09113cu: goto P_0c09113c;
case 0x0c09113eu: goto P_0c09113e;
case 0x0c091142u: goto P_0c091142;
case 0x0c091144u: goto P_0c091144;
case 0x0c091146u: goto P_0c091146;
case 0x0c091148u: goto P_0c091148;
case 0x0c09114au: goto P_0c09114a;
case 0x0c09114cu: goto P_0c09114c;
case 0x0c09114eu: goto P_0c09114e;
case 0x0c091150u: goto P_0c091150;
case 0x0c091152u: goto P_0c091152;
case 0x0c091154u: goto P_0c091154;
case 0x0c091156u: goto P_0c091156;
case 0x0c091158u: goto P_0c091158;
case 0x0c09115au: goto P_0c09115a;
case 0x0c09115cu: goto P_0c09115c;
case 0x0c09115eu: goto P_0c09115e;
case 0x0c091160u: goto P_0c091160;
case 0x0c091162u: goto P_0c091162;
case 0x0c091164u: goto P_0c091164;
case 0x0c091166u: goto P_0c091166;
case 0x0c091168u: goto P_0c091168;
case 0x0c09116au: goto P_0c09116a;
case 0x0c09116cu: goto P_0c09116c;
case 0x0c09116eu: goto P_0c09116e;
case 0x0c091170u: goto P_0c091170;
case 0x0c091172u: goto P_0c091172;
case 0x0c091174u: goto P_0c091174;
case 0x0c091176u: goto P_0c091176;
case 0x0c091178u: goto P_0c091178;
case 0x0c09117au: goto P_0c09117a;
case 0x0c09117cu: goto P_0c09117c;
case 0x0c09117eu: goto P_0c09117e;
case 0x0c091180u: goto P_0c091180;
case 0x0c091182u: goto P_0c091182;
case 0x0c091184u: goto P_0c091184;
case 0x0c091186u: goto P_0c091186;
case 0x0c091188u: goto P_0c091188;
case 0x0c09118au: goto P_0c09118a;
case 0x0c09118cu: goto P_0c09118c;
case 0x0c09118eu: goto P_0c09118e;
case 0x0c091190u: goto P_0c091190;
case 0x0c091192u: goto P_0c091192;
case 0x0c091194u: goto P_0c091194;
case 0x0c091196u: goto P_0c091196;
case 0x0c091198u: goto P_0c091198;
case 0x0c09119au: goto P_0c09119a;
case 0x0c09119cu: goto P_0c09119c;
case 0x0c09119eu: goto P_0c09119e;
case 0x0c0911a0u: goto P_0c0911a0;
case 0x0c0911a2u: goto P_0c0911a2;
case 0x0c0911a4u: goto P_0c0911a4;
case 0x0c0911a6u: goto P_0c0911a6;
case 0x0c0911a8u: goto P_0c0911a8;
case 0x0c0911aau: goto P_0c0911aa;
case 0x0c0911acu: goto P_0c0911ac;
case 0x0c0911aeu: goto P_0c0911ae;
case 0x0c0911b0u: goto P_0c0911b0;
case 0x0c0911b2u: goto P_0c0911b2;
case 0x0c0911b4u: goto P_0c0911b4;
case 0x0c0911b6u: goto P_0c0911b6;
case 0x0c0911f2u: goto P_0c0911f2;
case 0x0c0911f4u: goto P_0c0911f4;
case 0x0c0911f6u: goto P_0c0911f6;
case 0x0c0911f8u: goto P_0c0911f8;
case 0x0c0911fau: goto P_0c0911fa;
case 0x0c0911fcu: goto P_0c0911fc;
case 0x0c0911feu: goto P_0c0911fe;
case 0x0c091200u: goto P_0c091200;
case 0x0c091202u: goto P_0c091202;
case 0x0c091204u: goto P_0c091204;
case 0x0c091206u: goto P_0c091206;
case 0x0c091208u: goto P_0c091208;
case 0x0c09120au: goto P_0c09120a;
case 0x0c09120cu: goto P_0c09120c;
case 0x0c09120eu: goto P_0c09120e;
case 0x0c091210u: goto P_0c091210;
case 0x0c091212u: goto P_0c091212;
case 0x0c091214u: goto P_0c091214;
case 0x0c091216u: goto P_0c091216;
case 0x0c091218u: goto P_0c091218;
case 0x0c09121au: goto P_0c09121a;
case 0x0c09121cu: goto P_0c09121c;
case 0x0c09121eu: goto P_0c09121e;
case 0x0c091220u: goto P_0c091220;
case 0x0c091222u: goto P_0c091222;
case 0x0c091224u: goto P_0c091224;
case 0x0c091226u: goto P_0c091226;
case 0x0c091228u: goto P_0c091228;
case 0x0c09122au: goto P_0c09122a;
case 0x0c09122cu: goto P_0c09122c;
case 0x0c09122eu: goto P_0c09122e;
case 0x0c091230u: goto P_0c091230;
case 0x0c091232u: goto P_0c091232;
case 0x0c091234u: goto P_0c091234;
case 0x0c091236u: goto P_0c091236;
case 0x0c091238u: goto P_0c091238;
case 0x0c09123au: goto P_0c09123a;
case 0x0c09123cu: goto P_0c09123c;
case 0x0c09123eu: goto P_0c09123e;
case 0x0c091240u: goto P_0c091240;
case 0x0c091242u: goto P_0c091242;
case 0x0c091244u: goto P_0c091244;
case 0x0c091246u: goto P_0c091246;
case 0x0c091248u: goto P_0c091248;
case 0x0c09124au: goto P_0c09124a;
case 0x0c09124cu: goto P_0c09124c;
case 0x0c09124eu: goto P_0c09124e;
case 0x0c091250u: goto P_0c091250;
case 0x0c091252u: goto P_0c091252;
case 0x0c091254u: goto P_0c091254;
case 0x0c091256u: goto P_0c091256;
case 0x0c091258u: goto P_0c091258;
case 0x0c09125au: goto P_0c09125a;
case 0x0c09125cu: goto P_0c09125c;
case 0x0c09125eu: goto P_0c09125e;
case 0x0c091260u: goto P_0c091260;
case 0x0c091262u: goto P_0c091262;
case 0x0c091264u: goto P_0c091264;
case 0x0c091266u: goto P_0c091266;
case 0x0c091268u: goto P_0c091268;
case 0x0c09126au: goto P_0c09126a;
case 0x0c09126cu: goto P_0c09126c;
case 0x0c09126eu: goto P_0c09126e;
case 0x0c091270u: goto P_0c091270;
case 0x0c091272u: goto P_0c091272;
case 0x0c091274u: goto P_0c091274;
case 0x0c091276u: goto P_0c091276;
case 0x0c091278u: goto P_0c091278;
case 0x0c096866u: goto P_0c096866;
case 0x0c096868u: goto P_0c096868;
case 0x0c09686au: goto P_0c09686a;
case 0x0c09686cu: goto P_0c09686c;
case 0x0c09686eu: goto P_0c09686e;
case 0x0c096870u: goto P_0c096870;
case 0x0c096872u: goto P_0c096872;
case 0x0c096874u: goto P_0c096874;
case 0x0c096876u: goto P_0c096876;
case 0x0c096878u: goto P_0c096878;
case 0x0c09687au: goto P_0c09687a;
case 0x0c09687cu: goto P_0c09687c;
case 0x0c09687eu: goto P_0c09687e;
case 0x0c096880u: goto P_0c096880;
case 0x0c096882u: goto P_0c096882;
case 0x0c096884u: goto P_0c096884;
case 0x0c096886u: goto P_0c096886;
case 0x0c096888u: goto P_0c096888;
case 0x0c09688au: goto P_0c09688a;
case 0x0c09688cu: goto P_0c09688c;
case 0x0c09688eu: goto P_0c09688e;
case 0x0c096890u: goto P_0c096890;
case 0x0c096892u: goto P_0c096892;
case 0x0c096894u: goto P_0c096894;
case 0x0c096896u: goto P_0c096896;
case 0x0c096898u: goto P_0c096898;
case 0x0c09689au: goto P_0c09689a;
case 0x0c09689cu: goto P_0c09689c;
case 0x0c09689eu: goto P_0c09689e;
case 0x0c0968a0u: goto P_0c0968a0;
case 0x0c0968a2u: goto P_0c0968a2;
case 0x0c0968a4u: goto P_0c0968a4;
case 0x0c0968a6u: goto P_0c0968a6;
case 0x0c0968a8u: goto P_0c0968a8;
case 0x0c0968aau: goto P_0c0968aa;
case 0x0c0968acu: goto P_0c0968ac;
case 0x0c0968aeu: goto P_0c0968ae;
case 0x0c0968d0u: goto P_0c0968d0;
case 0x0c0968d2u: goto P_0c0968d2;
case 0x0c0968d4u: goto P_0c0968d4;
case 0x0c0968d6u: goto P_0c0968d6;
case 0x0c0968d8u: goto P_0c0968d8;
case 0x0c0968dau: goto P_0c0968da;
case 0x0c0968dcu: goto P_0c0968dc;
case 0x0c0968deu: goto P_0c0968de;
case 0x0c0968e0u: goto P_0c0968e0;
case 0x0c0968e2u: goto P_0c0968e2;
case 0x0c0968e4u: goto P_0c0968e4;
case 0x0c0968e6u: goto P_0c0968e6;
case 0x0c0968e8u: goto P_0c0968e8;
case 0x0c0968eau: goto P_0c0968ea;
case 0x0c0968ecu: goto P_0c0968ec;
case 0x0c0968eeu: goto P_0c0968ee;
case 0x0c0968f0u: goto P_0c0968f0;
case 0x0c0968f2u: goto P_0c0968f2;
case 0x0c0968f4u: goto P_0c0968f4;
case 0x0c0968f6u: goto P_0c0968f6;
case 0x0c096d5eu: goto P_0c096d5e;
case 0x0c096d60u: goto P_0c096d60;
case 0x0c096d62u: goto P_0c096d62;
case 0x0c096d64u: goto P_0c096d64;
case 0x0c096d66u: goto P_0c096d66;
case 0x0c096d68u: goto P_0c096d68;
case 0x0c096d6au: goto P_0c096d6a;
case 0x0c096d6cu: goto P_0c096d6c;
case 0x0c096d6eu: goto P_0c096d6e;
case 0x0c096d70u: goto P_0c096d70;
case 0x0c096d72u: goto P_0c096d72;
case 0x0c096d74u: goto P_0c096d74;
case 0x0c096d76u: goto P_0c096d76;
case 0x0c096d78u: goto P_0c096d78;
case 0x0c096d7au: goto P_0c096d7a;
case 0x0c096d7cu: goto P_0c096d7c;
case 0x0c096d7eu: goto P_0c096d7e;
case 0x0c096d80u: goto P_0c096d80;
case 0x0c096d82u: goto P_0c096d82;
case 0x0c096d84u: goto P_0c096d84;
case 0x0c096d86u: goto P_0c096d86;
case 0x0c096d88u: goto P_0c096d88;
case 0x0c096d8au: goto P_0c096d8a;
case 0x0c096d8cu: goto P_0c096d8c;
case 0x0c096d8eu: goto P_0c096d8e;
case 0x0c096d90u: goto P_0c096d90;
case 0x0c096d92u: goto P_0c096d92;
case 0x0c096d94u: goto P_0c096d94;
case 0x0c096d96u: goto P_0c096d96;
case 0x0c096d98u: goto P_0c096d98;
case 0x0c096d9au: goto P_0c096d9a;
case 0x0c096d9cu: goto P_0c096d9c;
case 0x0c096d9eu: goto P_0c096d9e;
case 0x0c096da0u: goto P_0c096da0;
case 0x0c096da2u: goto P_0c096da2;
case 0x0c096da4u: goto P_0c096da4;
case 0x0c096da6u: goto P_0c096da6;
case 0x0c096da8u: goto P_0c096da8;
case 0x0c096daau: goto P_0c096daa;
case 0x0c096dacu: goto P_0c096dac;
case 0x0c096daeu: goto P_0c096dae;
case 0x0c096db0u: goto P_0c096db0;
case 0x0c096db2u: goto P_0c096db2;
case 0x0c096db4u: goto P_0c096db4;
case 0x0c096db6u: goto P_0c096db6;
case 0x0c096db8u: goto P_0c096db8;
case 0x0c096dbau: goto P_0c096dba;
case 0x0c096dbcu: goto P_0c096dbc;
case 0x0c096dbeu: goto P_0c096dbe;
case 0x0c09713cu: goto P_0c09713c;
case 0x0c09713eu: goto P_0c09713e;
case 0x0c097140u: goto P_0c097140;
case 0x0c097142u: goto P_0c097142;
case 0x0c097144u: goto P_0c097144;
case 0x0c097146u: goto P_0c097146;
case 0x0c097148u: goto P_0c097148;
case 0x0c09714au: goto P_0c09714a;
case 0x0c09714cu: goto P_0c09714c;
case 0x0c09714eu: goto P_0c09714e;
case 0x0c097150u: goto P_0c097150;
case 0x0c097152u: goto P_0c097152;
case 0x0c097154u: goto P_0c097154;
case 0x0c097156u: goto P_0c097156;
case 0x0c097158u: goto P_0c097158;
case 0x0c09715au: goto P_0c09715a;
case 0x0c09715cu: goto P_0c09715c;
case 0x0c09715eu: goto P_0c09715e;
case 0x0c097160u: goto P_0c097160;
case 0x0c097162u: goto P_0c097162;
case 0x0c097164u: goto P_0c097164;
case 0x0c097166u: goto P_0c097166;
case 0x0c097168u: goto P_0c097168;
case 0x0c09716au: goto P_0c09716a;
case 0x0c09716cu: goto P_0c09716c;
case 0x0c09716eu: goto P_0c09716e;
case 0x0c097170u: goto P_0c097170;
case 0x0c097172u: goto P_0c097172;
case 0x0c097174u: goto P_0c097174;
case 0x0c097176u: goto P_0c097176;
case 0x0c097178u: goto P_0c097178;
case 0x0c09717au: goto P_0c09717a;
case 0x0c09717cu: goto P_0c09717c;
case 0x0c09717eu: goto P_0c09717e;
case 0x0c097180u: goto P_0c097180;
case 0x0c097182u: goto P_0c097182;
case 0x0c097184u: goto P_0c097184;
case 0x0c097186u: goto P_0c097186;
case 0x0c097188u: goto P_0c097188;
case 0x0c09718au: goto P_0c09718a;
case 0x0c09718cu: goto P_0c09718c;
case 0x0c09718eu: goto P_0c09718e;
case 0x0c097190u: goto P_0c097190;
case 0x0c097192u: goto P_0c097192;
case 0x0c097194u: goto P_0c097194;
case 0x0c097196u: goto P_0c097196;
case 0x0c097198u: goto P_0c097198;
case 0x0c09719au: goto P_0c09719a;
case 0x0c09719cu: goto P_0c09719c;
case 0x0c09719eu: goto P_0c09719e;
case 0x0c0971a0u: goto P_0c0971a0;
case 0x0c0971a2u: goto P_0c0971a2;
case 0x0c0971a4u: goto P_0c0971a4;
case 0x0c0971a6u: goto P_0c0971a6;
case 0x0c0971a8u: goto P_0c0971a8;
case 0x0c0971aau: goto P_0c0971aa;
case 0x0c0971acu: goto P_0c0971ac;
case 0x0c0971aeu: goto P_0c0971ae;
case 0x0c0971b0u: goto P_0c0971b0;
case 0x0c0971b2u: goto P_0c0971b2;
case 0x0c0971b4u: goto P_0c0971b4;
case 0x0c0971b6u: goto P_0c0971b6;
case 0x0c0971b8u: goto P_0c0971b8;
case 0x0c0971bau: goto P_0c0971ba;
case 0x0c0971bcu: goto P_0c0971bc;
case 0x0c0971beu: goto P_0c0971be;
case 0x0c0971c0u: goto P_0c0971c0;
case 0x0c0971c2u: goto P_0c0971c2;
case 0x0c0971c4u: goto P_0c0971c4;
case 0x0c0971c6u: goto P_0c0971c6;
case 0x0c0a2518u: goto P_0c0a2518;
case 0x0c0a251au: goto P_0c0a251a;
case 0x0c0a251cu: goto P_0c0a251c;
case 0x0c0a251eu: goto P_0c0a251e;
case 0x0c0a2520u: goto P_0c0a2520;
case 0x0c0a2522u: goto P_0c0a2522;
case 0x0c0a2524u: goto P_0c0a2524;
case 0x0c0a2526u: goto P_0c0a2526;
case 0x0c0a2528u: goto P_0c0a2528;
case 0x0c0a252au: goto P_0c0a252a;
case 0x0c0a252cu: goto P_0c0a252c;
case 0x0c0a252eu: goto P_0c0a252e;
case 0x0c0a2530u: goto P_0c0a2530;
case 0x0c0a2532u: goto P_0c0a2532;
case 0x0c0a2534u: goto P_0c0a2534;
case 0x0c0a2536u: goto P_0c0a2536;
case 0x0c0a2538u: goto P_0c0a2538;
case 0x0c0a253au: goto P_0c0a253a;
case 0x0c0a253cu: goto P_0c0a253c;
case 0x0c0a253eu: goto P_0c0a253e;
case 0x0c0a2540u: goto P_0c0a2540;
case 0x0c0a2542u: goto P_0c0a2542;
case 0x0c0a2544u: goto P_0c0a2544;
case 0x0c0a2546u: goto P_0c0a2546;
case 0x0c0a2548u: goto P_0c0a2548;
case 0x0c0a254au: goto P_0c0a254a;
case 0x0c0a254cu: goto P_0c0a254c;
case 0x0c0a254eu: goto P_0c0a254e;
case 0x0c0a2550u: goto P_0c0a2550;
case 0x0c0a2552u: goto P_0c0a2552;
case 0x0c0a2554u: goto P_0c0a2554;
case 0x0c0a2556u: goto P_0c0a2556;
case 0x0c0a2558u: goto P_0c0a2558;
case 0x0c0a255au: goto P_0c0a255a;
case 0x0c0a255cu: goto P_0c0a255c;
case 0x0c0a255eu: goto P_0c0a255e;
case 0x0c0a2560u: goto P_0c0a2560;
case 0x0c0a2562u: goto P_0c0a2562;
case 0x0c0a2564u: goto P_0c0a2564;
case 0x0c0a2566u: goto P_0c0a2566;
case 0x0c0a2568u: goto P_0c0a2568;
case 0x0c0a256au: goto P_0c0a256a;
case 0x0c0a256cu: goto P_0c0a256c;
case 0x0c0a256eu: goto P_0c0a256e;
case 0x0c0a2570u: goto P_0c0a2570;
case 0x0c0a2572u: goto P_0c0a2572;
case 0x0c0c27aeu: goto P_0c0c27ae;
case 0x0c0c27b0u: goto P_0c0c27b0;
case 0x0c0c27b2u: goto P_0c0c27b2;
case 0x0c0c27b4u: goto P_0c0c27b4;
case 0x0c0c27b6u: goto P_0c0c27b6;
case 0x0c0c27b8u: goto P_0c0c27b8;
case 0x0c0c27bau: goto P_0c0c27ba;
case 0x0c0c27bcu: goto P_0c0c27bc;
case 0x0c0c27beu: goto P_0c0c27be;
case 0x0c0c27c0u: goto P_0c0c27c0;
case 0x0c0c27c2u: goto P_0c0c27c2;
case 0x0c0c27c4u: goto P_0c0c27c4;
case 0x0c0c27c6u: goto P_0c0c27c6;
case 0x0c0c27c8u: goto P_0c0c27c8;
case 0x0c0c27cau: goto P_0c0c27ca;
case 0x0c0c27ccu: goto P_0c0c27cc;
case 0x0c0c27ceu: goto P_0c0c27ce;
case 0x0c0c27d0u: goto P_0c0c27d0;
case 0x0c0c27d2u: goto P_0c0c27d2;
case 0x0c0c27d4u: goto P_0c0c27d4;
case 0x0c0c27d6u: goto P_0c0c27d6;
case 0x0c0c27d8u: goto P_0c0c27d8;
case 0x0c0c27dau: goto P_0c0c27da;
case 0x0c0c27dcu: goto P_0c0c27dc;
case 0x0c0c27deu: goto P_0c0c27de;
case 0x0c0c27e0u: goto P_0c0c27e0;
case 0x0c0c27e2u: goto P_0c0c27e2;
case 0x0c0c27e4u: goto P_0c0c27e4;
case 0x0c0c27e6u: goto P_0c0c27e6;
case 0x0c0c27e8u: goto P_0c0c27e8;
case 0x0c0c27eau: goto P_0c0c27ea;
case 0x0c0c27ecu: goto P_0c0c27ec;
case 0x0c0c27eeu: goto P_0c0c27ee;
case 0x0c0c27f0u: goto P_0c0c27f0;
case 0x0c0c27f2u: goto P_0c0c27f2;
case 0x0c0c27f4u: goto P_0c0c27f4;
case 0x0c0c27f6u: goto P_0c0c27f6;
case 0x0c0c27f8u: goto P_0c0c27f8;
case 0x0c0c27fau: goto P_0c0c27fa;
case 0x0c0c27fcu: goto P_0c0c27fc;
case 0x0c0c27feu: goto P_0c0c27fe;
case 0x0c0c2800u: goto P_0c0c2800;
case 0x0c0c2802u: goto P_0c0c2802;
case 0x0c0c2804u: goto P_0c0c2804;
case 0x0c0c2806u: goto P_0c0c2806;
case 0x0c0c2808u: goto P_0c0c2808;
case 0x0c0c2ccau: goto P_0c0c2cca;
case 0x0c0c2cccu: goto P_0c0c2ccc;
case 0x0c0c664cu: goto P_0c0c664c;
case 0x0c0c664eu: goto P_0c0c664e;
case 0x0c0c6650u: goto P_0c0c6650;
case 0x0c0c6652u: goto P_0c0c6652;
case 0x0c0c6654u: goto P_0c0c6654;
case 0x0c0c6656u: goto P_0c0c6656;
case 0x0c0c6658u: goto P_0c0c6658;
case 0x0c0c665au: goto P_0c0c665a;
case 0x0c0c665cu: goto P_0c0c665c;
case 0x0c0c665eu: goto P_0c0c665e;
case 0x0c0c6660u: goto P_0c0c6660;
case 0x0c0c6662u: goto P_0c0c6662;
case 0x0c0c6664u: goto P_0c0c6664;
case 0x0c0c6666u: goto P_0c0c6666;
case 0x0c0c6668u: goto P_0c0c6668;
case 0x0c0c666au: goto P_0c0c666a;
case 0x0c0c666cu: goto P_0c0c666c;
case 0x0c0c666eu: goto P_0c0c666e;
case 0x0c0c6670u: goto P_0c0c6670;
case 0x0c0c6672u: goto P_0c0c6672;
case 0x0c0c6674u: goto P_0c0c6674;
case 0x0c0c6676u: goto P_0c0c6676;
case 0x0c0c6678u: goto P_0c0c6678;
case 0x0c0c667au: goto P_0c0c667a;
case 0x0c0c667cu: goto P_0c0c667c;
case 0x0c0c667eu: goto P_0c0c667e;
case 0x0c0c6680u: goto P_0c0c6680;
case 0x0c0c6682u: goto P_0c0c6682;
case 0x0c0c6684u: goto P_0c0c6684;
case 0x0c0c6686u: goto P_0c0c6686;
case 0x0c0c6688u: goto P_0c0c6688;
case 0x0c0c668au: goto P_0c0c668a;
case 0x0c0c668cu: goto P_0c0c668c;
case 0x0c0c668eu: goto P_0c0c668e;
case 0x0c0c6690u: goto P_0c0c6690;
case 0x0c0c74b8u: goto P_0c0c74b8;
case 0x0c0c74bau: goto P_0c0c74ba;
case 0x0c0c8d8eu: goto P_0c0c8d8e;
case 0x0c0c8d90u: goto P_0c0c8d90;
case 0x0c0c8d92u: goto P_0c0c8d92;
case 0x0c0c8d94u: goto P_0c0c8d94;
case 0x0c0c8d96u: goto P_0c0c8d96;
case 0x0c0c8d98u: goto P_0c0c8d98;
case 0x0c0c8d9au: goto P_0c0c8d9a;
case 0x0c0c8d9cu: goto P_0c0c8d9c;
case 0x0c0c8d9eu: goto P_0c0c8d9e;
case 0x0c0c8da0u: goto P_0c0c8da0;
case 0x0c0c8da2u: goto P_0c0c8da2;
case 0x0c0c8da4u: goto P_0c0c8da4;
case 0x0c0c8da6u: goto P_0c0c8da6;
case 0x0c0c8da8u: goto P_0c0c8da8;
case 0x0c0c8daau: goto P_0c0c8daa;
case 0x0c0c8dacu: goto P_0c0c8dac;
case 0x0c0c8daeu: goto P_0c0c8dae;
case 0x0c0c8db0u: goto P_0c0c8db0;
case 0x0c0c8db2u: goto P_0c0c8db2;
case 0x0c0c8db4u: goto P_0c0c8db4;
case 0x0c0c8db6u: goto P_0c0c8db6;
case 0x0c0c8db8u: goto P_0c0c8db8;
case 0x0c0c8dbau: goto P_0c0c8dba;
case 0x0c0c8dbcu: goto P_0c0c8dbc;
case 0x0c0c8dbeu: goto P_0c0c8dbe;
case 0x0c0c8dc0u: goto P_0c0c8dc0;
case 0x0c0c8dc2u: goto P_0c0c8dc2;
case 0x0c0c8dc4u: goto P_0c0c8dc4;
case 0x0c0c8dc6u: goto P_0c0c8dc6;
case 0x0c0c8dc8u: goto P_0c0c8dc8;
case 0x0c0c8dcau: goto P_0c0c8dca;
case 0x0c0c8dccu: goto P_0c0c8dcc;
case 0x0c0c8dceu: goto P_0c0c8dce;
case 0x0c0c8dd0u: goto P_0c0c8dd0;
case 0x0c0c8dd2u: goto P_0c0c8dd2;
case 0x0c0c8dd4u: goto P_0c0c8dd4;
case 0x0c0c8dd6u: goto P_0c0c8dd6;
case 0x0c0c8dd8u: goto P_0c0c8dd8;
case 0x0c0c8ddau: goto P_0c0c8dda;
case 0x0c0c8ddcu: goto P_0c0c8ddc;
case 0x0c0c8ddeu: goto P_0c0c8dde;
case 0x0c0c8de0u: goto P_0c0c8de0;
case 0x0c0c8de2u: goto P_0c0c8de2;
case 0x0c0c8de4u: goto P_0c0c8de4;
case 0x0c0c8de6u: goto P_0c0c8de6;
case 0x0c0c8de8u: goto P_0c0c8de8;
case 0x0c0c8f76u: goto P_0c0c8f76;
case 0x0c0c8f78u: goto P_0c0c8f78;
case 0x0c0c8f7au: goto P_0c0c8f7a;
case 0x0c0c8f7cu: goto P_0c0c8f7c;
case 0x0c0c8f7eu: goto P_0c0c8f7e;
case 0x0c0c8f80u: goto P_0c0c8f80;
case 0x0c0c8f82u: goto P_0c0c8f82;
case 0x0c0c8f84u: goto P_0c0c8f84;
case 0x0c0c8f86u: goto P_0c0c8f86;
case 0x0c0c8f88u: goto P_0c0c8f88;
case 0x0c0c8f8au: goto P_0c0c8f8a;
case 0x0c0c8f8cu: goto P_0c0c8f8c;
case 0x0c0c8f8eu: goto P_0c0c8f8e;
case 0x0c0c8f90u: goto P_0c0c8f90;
case 0x0c0c8f92u: goto P_0c0c8f92;
case 0x0c0c8f94u: goto P_0c0c8f94;
case 0x0c0c8f96u: goto P_0c0c8f96;
case 0x0c0c8f98u: goto P_0c0c8f98;
case 0x0c0c8f9au: goto P_0c0c8f9a;
case 0x0c0c8f9cu: goto P_0c0c8f9c;
case 0x0c0c8f9eu: goto P_0c0c8f9e;
case 0x0c0c8fa0u: goto P_0c0c8fa0;
case 0x0c0c8fa2u: goto P_0c0c8fa2;
case 0x0c0c8fa4u: goto P_0c0c8fa4;
case 0x0c0c8fa6u: goto P_0c0c8fa6;
case 0x0c0c8fa8u: goto P_0c0c8fa8;
case 0x0c0c8faau: goto P_0c0c8faa;
case 0x0c0c8facu: goto P_0c0c8fac;
case 0x0c0c8faeu: goto P_0c0c8fae;
case 0x0c0c8fb0u: goto P_0c0c8fb0;
case 0x0c0c8fb2u: goto P_0c0c8fb2;
case 0x0c0c8fb4u: goto P_0c0c8fb4;
case 0x0c0c8fb6u: goto P_0c0c8fb6;
case 0x0c0c8fb8u: goto P_0c0c8fb8;
case 0x0c0c8fbau: goto P_0c0c8fba;
case 0x0c0c8fbcu: goto P_0c0c8fbc;
case 0x0c0c8fbeu: goto P_0c0c8fbe;
case 0x0c0c8fc0u: goto P_0c0c8fc0;
case 0x0c0c8fc2u: goto P_0c0c8fc2;
case 0x0c0c8fcau: goto P_0c0c8fca;
case 0x0c0c8fccu: goto P_0c0c8fcc;
case 0x0c0c8fceu: goto P_0c0c8fce;
case 0x0c0c8fd0u: goto P_0c0c8fd0;
case 0x0c0c8fd2u: goto P_0c0c8fd2;
case 0x0c0c8fd4u: goto P_0c0c8fd4;
case 0x0c0c8fd6u: goto P_0c0c8fd6;
case 0x0c0c8fd8u: goto P_0c0c8fd8;
case 0x0c0c8fdau: goto P_0c0c8fda;
case 0x0c0c8fdcu: goto P_0c0c8fdc;
case 0x0c0c8fdeu: goto P_0c0c8fde;
case 0x0c0c8fe0u: goto P_0c0c8fe0;
case 0x0c0c8fe2u: goto P_0c0c8fe2;
case 0x0c0c8fe4u: goto P_0c0c8fe4;
case 0x0c0c8fe6u: goto P_0c0c8fe6;
case 0x0c0c8fe8u: goto P_0c0c8fe8;
case 0x0c0c8feau: goto P_0c0c8fea;
case 0x0c0c8fecu: goto P_0c0c8fec;
case 0x0c0c8feeu: goto P_0c0c8fee;
case 0x0c0c8ff0u: goto P_0c0c8ff0;
case 0x0c0c8ff2u: goto P_0c0c8ff2;
case 0x0c0c8ff4u: goto P_0c0c8ff4;
case 0x0c0c8ff6u: goto P_0c0c8ff6;
case 0x0c0c8ff8u: goto P_0c0c8ff8;
case 0x0c0c8ffau: goto P_0c0c8ffa;
case 0x0c0c8ffcu: goto P_0c0c8ffc;
case 0x0c0c8ffeu: goto P_0c0c8ffe;
case 0x0c0c9000u: goto P_0c0c9000;
case 0x0c0c9002u: goto P_0c0c9002;
case 0x0c0c9004u: goto P_0c0c9004;
case 0x0c0c9006u: goto P_0c0c9006;
case 0x0c0c9008u: goto P_0c0c9008;
case 0x0c0c900au: goto P_0c0c900a;
case 0x0c0c900cu: goto P_0c0c900c;
case 0x0c0c900eu: goto P_0c0c900e;
case 0x0c0c9010u: goto P_0c0c9010;
case 0x0c0c9012u: goto P_0c0c9012;
case 0x0c0c9014u: goto P_0c0c9014;
case 0x0c0c9016u: goto P_0c0c9016;
case 0x0c0c9052u: goto P_0c0c9052;
case 0x0c0c9054u: goto P_0c0c9054;
case 0x0c0c9056u: goto P_0c0c9056;
case 0x0c0c9058u: goto P_0c0c9058;
case 0x0c0c905au: goto P_0c0c905a;
case 0x0c0c905cu: goto P_0c0c905c;
case 0x0c0c905eu: goto P_0c0c905e;
case 0x0c0c9060u: goto P_0c0c9060;
case 0x0c0c9062u: goto P_0c0c9062;
case 0x0c0c9064u: goto P_0c0c9064;
case 0x0c0c9066u: goto P_0c0c9066;
case 0x0c0c9068u: goto P_0c0c9068;
case 0x0c0c906au: goto P_0c0c906a;
case 0x0c0c906cu: goto P_0c0c906c;
case 0x0c0c906eu: goto P_0c0c906e;
case 0x0c0c9070u: goto P_0c0c9070;
case 0x0c0c9072u: goto P_0c0c9072;
case 0x0c0c9074u: goto P_0c0c9074;
case 0x0c0c9076u: goto P_0c0c9076;
case 0x0c0c9078u: goto P_0c0c9078;
case 0x0c0c907au: goto P_0c0c907a;
case 0x0c0c907cu: goto P_0c0c907c;
case 0x0c0c907eu: goto P_0c0c907e;
case 0x0c0c9080u: goto P_0c0c9080;
case 0x0c0c9082u: goto P_0c0c9082;
case 0x0c0c9084u: goto P_0c0c9084;
case 0x0c0c9086u: goto P_0c0c9086;
case 0x0c0c9088u: goto P_0c0c9088;
case 0x0c0c908au: goto P_0c0c908a;
case 0x0c0c908cu: goto P_0c0c908c;
case 0x0c0c908eu: goto P_0c0c908e;
case 0x0c0c9090u: goto P_0c0c9090;
case 0x0c0c9092u: goto P_0c0c9092;
case 0x0c0c9094u: goto P_0c0c9094;
case 0x0c0c9096u: goto P_0c0c9096;
case 0x0c0c9098u: goto P_0c0c9098;
case 0x0c0c909au: goto P_0c0c909a;
case 0x0c0c909cu: goto P_0c0c909c;
case 0x0c0c909eu: goto P_0c0c909e;
case 0x0c0c90a0u: goto P_0c0c90a0;
case 0x0c0c90a2u: goto P_0c0c90a2;
case 0x0c0c90a4u: goto P_0c0c90a4;
case 0x0c0c90a6u: goto P_0c0c90a6;
case 0x0c0c90a8u: goto P_0c0c90a8;
case 0x0c0c90aau: goto P_0c0c90aa;
case 0x0c0c90acu: goto P_0c0c90ac;
case 0x0c0c90aeu: goto P_0c0c90ae;
case 0x0c0c90b0u: goto P_0c0c90b0;
case 0x0c0c90b2u: goto P_0c0c90b2;
case 0x0c0c90b4u: goto P_0c0c90b4;
case 0x0c0c90b6u: goto P_0c0c90b6;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
P_0c0103ba: /* original 4f22, guest PC 0x0c0103ba */
if(!s->budget--) { s->failed_pc=0x0c0103bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0103bc;
P_0c0103bc: /* original 2232, guest PC 0x0c0103bc */
if(!s->budget--) { s->failed_pc=0x0c0103bcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0103be;
P_0c0103be: /* original d32e, guest PC 0x0c0103be */
if(!s->budget--) { s->failed_pc=0x0c0103beu; return 0; }
r[3]=read(ram,0x0c010478u,4);
goto P_0c0103c0;
P_0c0103c0: /* original dc2c, guest PC 0x0c0103c0 */
if(!s->budget--) { s->failed_pc=0x0c0103c0u; return 0; }
r[12]=read(ram,0x0c010474u,4);
goto P_0c0103c2;
P_0c0103c2: /* original 330c, guest PC 0x0c0103c2 */
if(!s->budget--) { s->failed_pc=0x0c0103c2u; return 0; }
r[3]+=r[0];
goto P_0c0103c4;
P_0c0103c4: /* original 6133, guest PC 0x0c0103c4 */
if(!s->budget--) { s->failed_pc=0x0c0103c4u; return 0; }
r[1]=r[3];
goto P_0c0103c6;
P_0c0103c6: /* original 21cb, guest PC 0x0c0103c6 */
if(!s->budget--) { s->failed_pc=0x0c0103c6u; return 0; }
r[1]|=r[12];
goto P_0c0103c8;
P_0c0103c8: /* original 410b, guest PC 0x0c0103c8 */
if(!s->budget--) { s->failed_pc=0x0c0103c8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0103ccu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0103ccu) { target=s->pc; goto dispatch; }
goto P_0c0103cc;
P_0c0103ca: /* original 65d3, guest PC 0x0c0103ca */
if(!s->budget--) { s->failed_pc=0x0c0103cau; return 0; }
r[5]=r[13];
goto P_0c0103cc;
P_0c0103cc: /* original 2ee8, guest PC 0x0c0103cc */
if(!s->budget--) { s->failed_pc=0x0c0103ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0103ce;
P_0c0103ce: /* original 8b12, guest PC 0x0c0103ce */
if(!s->budget--) { s->failed_pc=0x0c0103ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0103f6; }
goto P_0c0103d0;
P_0c0103d0: /* original 60d0, guest PC 0x0c0103d0 */
if(!s->budget--) { s->failed_pc=0x0c0103d0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[0]=tmp;
goto P_0c0103d2;
P_0c0103d2: /* original 600c, guest PC 0x0c0103d2 */
if(!s->budget--) { s->failed_pc=0x0c0103d2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0103d4;
P_0c0103d4: /* original 8829, guest PC 0x0c0103d4 */
if(!s->budget--) { s->failed_pc=0x0c0103d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000029u)!=0);
goto P_0c0103d6;
P_0c0103d6: /* original 890e, guest PC 0x0c0103d6 */
if(!s->budget--) { s->failed_pc=0x0c0103d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0103f6; }
goto P_0c0103d8;
P_0c0103d8: /* original d228, guest PC 0x0c0103d8 */
if(!s->budget--) { s->failed_pc=0x0c0103d8u; return 0; }
r[2]=read(ram,0x0c01047cu,4);
goto P_0c0103da;
P_0c0103da: /* original c700, guest PC 0x0c0103da */
if(!s->budget--) { s->failed_pc=0x0c0103dau; return 0; }
r[0]=code_base|0x000103dcu;
goto P_0c0103dc;
P_0c0103dc: /* original 320c, guest PC 0x0c0103dc */
if(!s->budget--) { s->failed_pc=0x0c0103dcu; return 0; }
r[2]+=r[0];
goto P_0c0103de;
P_0c0103de: /* original 6323, guest PC 0x0c0103de */
if(!s->budget--) { s->failed_pc=0x0c0103deu; return 0; }
r[3]=r[2];
goto P_0c0103e0;
P_0c0103e0: /* original 23cb, guest PC 0x0c0103e0 */
if(!s->budget--) { s->failed_pc=0x0c0103e0u; return 0; }
r[3]|=r[12];
goto P_0c0103e2;
P_0c0103e2: /* original 430b, guest PC 0x0c0103e2 */
if(!s->budget--) { s->failed_pc=0x0c0103e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0103e6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0103e6u) { target=s->pc; goto dispatch; }
goto P_0c0103e6;
P_0c0103e4: /* original 64d3, guest PC 0x0c0103e4 */
if(!s->budget--) { s->failed_pc=0x0c0103e4u; return 0; }
r[4]=r[13];
goto P_0c0103e6;
P_0c0103e6: /* original d226, guest PC 0x0c0103e6 */
if(!s->budget--) { s->failed_pc=0x0c0103e6u; return 0; }
r[2]=read(ram,0x0c010480u,4);
goto P_0c0103e8;
P_0c0103e8: /* original c700, guest PC 0x0c0103e8 */
if(!s->budget--) { s->failed_pc=0x0c0103e8u; return 0; }
r[0]=code_base|0x000103ecu;
goto P_0c0103ea;
P_0c0103ea: /* original 320c, guest PC 0x0c0103ea */
if(!s->budget--) { s->failed_pc=0x0c0103eau; return 0; }
r[2]+=r[0];
goto P_0c0103ec;
P_0c0103ec: /* original 6323, guest PC 0x0c0103ec */
if(!s->budget--) { s->failed_pc=0x0c0103ecu; return 0; }
r[3]=r[2];
goto P_0c0103ee;
P_0c0103ee: /* original 2c3b, guest PC 0x0c0103ee */
if(!s->budget--) { s->failed_pc=0x0c0103eeu; return 0; }
r[12]|=r[3];
goto P_0c0103f0;
P_0c0103f0: /* original 4c0b, guest PC 0x0c0103f0 */
if(!s->budget--) { s->failed_pc=0x0c0103f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0103f4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0103f4u) { target=s->pc; goto dispatch; }
goto P_0c0103f4;
P_0c0103f2: /* original 0009, guest PC 0x0c0103f2 */
if(!s->budget--) { s->failed_pc=0x0c0103f2u; return 0; }
goto P_0c0103f4;
P_0c0103f4: /* original 9e2e, guest PC 0x0c0103f4 */
if(!s->budget--) { s->failed_pc=0x0c0103f4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c010454u,2);
goto P_0c0103f6;
P_0c0103f6: /* original 4f26, guest PC 0x0c0103f6 */
if(!s->budget--) { s->failed_pc=0x0c0103f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0103f8;
P_0c0103f8: /* original 60e3, guest PC 0x0c0103f8 */
if(!s->budget--) { s->failed_pc=0x0c0103f8u; return 0; }
r[0]=r[14];
goto P_0c0103fa;
P_0c0103fa: /* original 6cf6, guest PC 0x0c0103fa */
if(!s->budget--) { s->failed_pc=0x0c0103fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0103fc;
P_0c0103fc: /* original 6df6, guest PC 0x0c0103fc */
if(!s->budget--) { s->failed_pc=0x0c0103fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0103fe;
P_0c0103fe: /* original 000b, guest PC 0x0c0103fe */
if(!s->budget--) { s->failed_pc=0x0c0103feu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c010400: /* original 6ef6, guest PC 0x0c010400 */
if(!s->budget--) { s->failed_pc=0x0c010400u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c010402u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c010402u; return 0; } return 1;
P_0c010630: /* original 4f22, guest PC 0x0c010630 */
if(!s->budget--) { s->failed_pc=0x0c010630u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c010632;
P_0c010632: /* original d329, guest PC 0x0c010632 */
if(!s->budget--) { s->failed_pc=0x0c010632u; return 0; }
r[3]=read(ram,0x0c0106d8u,4);
goto P_0c010634;
P_0c010634: /* original e400, guest PC 0x0c010634 */
if(!s->budget--) { s->failed_pc=0x0c010634u; return 0; }
r[4]=0x00000000u;
goto P_0c010636;
P_0c010636: /* original 2342, guest PC 0x0c010636 */
if(!s->budget--) { s->failed_pc=0x0c010636u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c010638;
P_0c010638: /* original d228, guest PC 0x0c010638 */
if(!s->budget--) { s->failed_pc=0x0c010638u; return 0; }
r[2]=read(ram,0x0c0106dcu,4);
goto P_0c01063a;
P_0c01063a: /* original 2242, guest PC 0x0c01063a */
if(!s->budget--) { s->failed_pc=0x0c01063au; return 0; }
write(ram,r[2],r[4],4);
goto P_0c01063c;
P_0c01063c: /* original d128, guest PC 0x0c01063c */
if(!s->budget--) { s->failed_pc=0x0c01063cu; return 0; }
r[1]=read(ram,0x0c0106e0u,4);
goto P_0c01063e;
P_0c01063e: /* original 6012, guest PC 0x0c01063e */
if(!s->budget--) { s->failed_pc=0x0c01063eu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c010640;
P_0c010640: /* original c907, guest PC 0x0c010640 */
if(!s->budget--) { s->failed_pc=0x0c010640u; return 0; }
r[0]&=7u;
goto P_0c010642;
P_0c010642: /* original 8807, guest PC 0x0c010642 */
if(!s->budget--) { s->failed_pc=0x0c010642u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c010644;
P_0c010644: /* original 8d0c, guest PC 0x0c010644 */
if(!s->budget--) { s->failed_pc=0x0c010644u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c010660; }
goto P_0c010648;
P_0c010646: /* original 6403, guest PC 0x0c010646 */
if(!s->budget--) { s->failed_pc=0x0c010646u; return 0; }
r[4]=r[0];
goto P_0c010648;
P_0c010648: /* original d326, guest PC 0x0c010648 */
if(!s->budget--) { s->failed_pc=0x0c010648u; return 0; }
r[3]=read(ram,0x0c0106e4u,4);
goto P_0c01064a;
P_0c01064a: /* original c700, guest PC 0x0c01064a */
if(!s->budget--) { s->failed_pc=0x0c01064au; return 0; }
r[0]=code_base|0x0001064cu;
goto P_0c01064c;
P_0c01064c: /* original 330c, guest PC 0x0c01064c */
if(!s->budget--) { s->failed_pc=0x0c01064cu; return 0; }
r[3]+=r[0];
goto P_0c01064e;
P_0c01064e: /* original d021, guest PC 0x0c01064e */
if(!s->budget--) { s->failed_pc=0x0c01064eu; return 0; }
r[0]=read(ram,0x0c0106d4u,4);
goto P_0c010650;
P_0c010650: /* original 230b, guest PC 0x0c010650 */
if(!s->budget--) { s->failed_pc=0x0c010650u; return 0; }
r[3]|=r[0];
goto P_0c010652;
P_0c010652: /* original 430b, guest PC 0x0c010652 */
if(!s->budget--) { s->failed_pc=0x0c010652u; return 0; }
target=r[3];
r[16]=code_base|0x0c010656u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c010656u) { target=s->pc; goto dispatch; }
goto P_0c010656;
P_0c010654: /* original 0009, guest PC 0x0c010654 */
if(!s->budget--) { s->failed_pc=0x0c010654u; return 0; }
goto P_0c010656;
P_0c010656: /* original 2008, guest PC 0x0c010656 */
if(!s->budget--) { s->failed_pc=0x0c010656u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c010658;
P_0c010658: /* original 8b02, guest PC 0x0c010658 */
if(!s->budget--) { s->failed_pc=0x0c010658u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c010660; }
goto P_0c01065a;
P_0c01065a: /* original d21f, guest PC 0x0c01065a */
if(!s->budget--) { s->failed_pc=0x0c01065au; return 0; }
r[2]=read(ram,0x0c0106d8u,4);
goto P_0c01065c;
P_0c01065c: /* original e301, guest PC 0x0c01065c */
if(!s->budget--) { s->failed_pc=0x0c01065cu; return 0; }
r[3]=0x00000001u;
goto P_0c01065e;
P_0c01065e: /* original 2232, guest PC 0x0c01065e */
if(!s->budget--) { s->failed_pc=0x0c01065eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c010660;
P_0c010660: /* original d121, guest PC 0x0c010660 */
if(!s->budget--) { s->failed_pc=0x0c010660u; return 0; }
r[1]=read(ram,0x0c0106e8u,4);
goto P_0c010662;
P_0c010662: /* original c700, guest PC 0x0c010662 */
if(!s->budget--) { s->failed_pc=0x0c010662u; return 0; }
r[0]=code_base|0x00010664u;
goto P_0c010664;
P_0c010664: /* original d31b, guest PC 0x0c010664 */
if(!s->budget--) { s->failed_pc=0x0c010664u; return 0; }
r[3]=read(ram,0x0c0106d4u,4);
goto P_0c010666;
P_0c010666: /* original 310c, guest PC 0x0c010666 */
if(!s->budget--) { s->failed_pc=0x0c010666u; return 0; }
r[1]+=r[0];
goto P_0c010668;
P_0c010668: /* original d520, guest PC 0x0c010668 */
if(!s->budget--) { s->failed_pc=0x0c010668u; return 0; }
r[5]=read(ram,0x0c0106ecu,4);
goto P_0c01066a;
P_0c01066a: /* original 6213, guest PC 0x0c01066a */
if(!s->budget--) { s->failed_pc=0x0c01066au; return 0; }
r[2]=r[1];
goto P_0c01066c;
P_0c01066c: /* original 223b, guest PC 0x0c01066c */
if(!s->budget--) { s->failed_pc=0x0c01066cu; return 0; }
r[2]|=r[3];
goto P_0c01066e;
P_0c01066e: /* original 420b, guest PC 0x0c01066e */
if(!s->budget--) { s->failed_pc=0x0c01066eu; return 0; }
target=r[2];
r[16]=code_base|0x0c010672u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c010672u) { target=s->pc; goto dispatch; }
goto P_0c010672;
P_0c010670: /* original e400, guest PC 0x0c010670 */
if(!s->budget--) { s->failed_pc=0x0c010670u; return 0; }
r[4]=0x00000000u;
goto P_0c010672;
P_0c010672: /* original 2008, guest PC 0x0c010672 */
if(!s->budget--) { s->failed_pc=0x0c010672u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c010674;
P_0c010674: /* original 8b02, guest PC 0x0c010674 */
if(!s->budget--) { s->failed_pc=0x0c010674u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c01067c; }
goto P_0c010676;
P_0c010676: /* original d319, guest PC 0x0c010676 */
if(!s->budget--) { s->failed_pc=0x0c010676u; return 0; }
r[3]=read(ram,0x0c0106dcu,4);
goto P_0c010678;
P_0c010678: /* original e201, guest PC 0x0c010678 */
if(!s->budget--) { s->failed_pc=0x0c010678u; return 0; }
r[2]=0x00000001u;
goto P_0c01067a;
P_0c01067a: /* original 2322, guest PC 0x0c01067a */
if(!s->budget--) { s->failed_pc=0x0c01067au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c01067c;
P_0c01067c: /* original 4f26, guest PC 0x0c01067c */
if(!s->budget--) { s->failed_pc=0x0c01067cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c01067e;
P_0c01067e: /* original 000b, guest PC 0x0c01067e */
if(!s->budget--) { s->failed_pc=0x0c01067eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c010680: /* original 0009, guest PC 0x0c010680 */
if(!s->budget--) { s->failed_pc=0x0c010680u; return 0; }
if(!vf3_matrix_family(0x0c010682u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c010682u; return 0; } return 1;
P_0c010954: /* original 4f22, guest PC 0x0c010954 */
if(!s->budget--) { s->failed_pc=0x0c010954u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c010956;
P_0c010956: /* original 7ff4, guest PC 0x0c010956 */
if(!s->budget--) { s->failed_pc=0x0c010956u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c010958;
P_0c010958: /* original 1f42, guest PC 0x0c010958 */
if(!s->budget--) { s->failed_pc=0x0c010958u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c01095a;
P_0c01095a: /* original 1f51, guest PC 0x0c01095a */
if(!s->budget--) { s->failed_pc=0x0c01095au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c01095c;
P_0c01095c: /* original 2f62, guest PC 0x0c01095c */
if(!s->budget--) { s->failed_pc=0x0c01095cu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c01095e;
P_0c01095e: /* original 53f2, guest PC 0x0c01095e */
if(!s->budget--) { s->failed_pc=0x0c01095eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c010960;
P_0c010960: /* original 2338, guest PC 0x0c010960 */
if(!s->budget--) { s->failed_pc=0x0c010960u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c010962;
P_0c010962: /* original 8906, guest PC 0x0c010962 */
if(!s->budget--) { s->failed_pc=0x0c010962u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c010972; }
goto P_0c010964;
P_0c010964: /* original d33d, guest PC 0x0c010964 */
if(!s->budget--) { s->failed_pc=0x0c010964u; return 0; }
r[3]=read(ram,0x0c010a5cu,4);
goto P_0c010966;
P_0c010966: /* original c700, guest PC 0x0c010966 */
if(!s->budget--) { s->failed_pc=0x0c010966u; return 0; }
r[0]=code_base|0x00010968u;
goto P_0c010968;
P_0c010968: /* original d23b, guest PC 0x0c010968 */
if(!s->budget--) { s->failed_pc=0x0c010968u; return 0; }
r[2]=read(ram,0x0c010a58u,4);
goto P_0c01096a;
P_0c01096a: /* original 330c, guest PC 0x0c01096a */
if(!s->budget--) { s->failed_pc=0x0c01096au; return 0; }
r[3]+=r[0];
goto P_0c01096c;
P_0c01096c: /* original 6133, guest PC 0x0c01096c */
if(!s->budget--) { s->failed_pc=0x0c01096cu; return 0; }
r[1]=r[3];
goto P_0c01096e;
P_0c01096e: /* original a005, guest PC 0x0c01096e */
if(!s->budget--) { s->failed_pc=0x0c01096eu; return 0; }
goto P_0c01097c;
P_0c010970: /* original 0009, guest PC 0x0c010970 */
if(!s->budget--) { s->failed_pc=0x0c010970u; return 0; }
goto P_0c010972;
P_0c010972: /* original d33b, guest PC 0x0c010972 */
if(!s->budget--) { s->failed_pc=0x0c010972u; return 0; }
r[3]=read(ram,0x0c010a60u,4);
goto P_0c010974;
P_0c010974: /* original c700, guest PC 0x0c010974 */
if(!s->budget--) { s->failed_pc=0x0c010974u; return 0; }
r[0]=code_base|0x00010978u;
goto P_0c010976;
P_0c010976: /* original 330c, guest PC 0x0c010976 */
if(!s->budget--) { s->failed_pc=0x0c010976u; return 0; }
r[3]+=r[0];
goto P_0c010978;
P_0c010978: /* original d237, guest PC 0x0c010978 */
if(!s->budget--) { s->failed_pc=0x0c010978u; return 0; }
r[2]=read(ram,0x0c010a58u,4);
goto P_0c01097a;
P_0c01097a: /* original 6133, guest PC 0x0c01097a */
if(!s->budget--) { s->failed_pc=0x0c01097au; return 0; }
r[1]=r[3];
goto P_0c01097c;
P_0c01097c: /* original 65f2, guest PC 0x0c01097c */
if(!s->budget--) { s->failed_pc=0x0c01097cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c01097e;
P_0c01097e: /* original 212b, guest PC 0x0c01097e */
if(!s->budget--) { s->failed_pc=0x0c01097eu; return 0; }
r[1]|=r[2];
goto P_0c010980;
P_0c010980: /* original 410b, guest PC 0x0c010980 */
if(!s->budget--) { s->failed_pc=0x0c010980u; return 0; }
target=r[1];
r[16]=code_base|0x0c010984u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c010984u) { target=s->pc; goto dispatch; }
goto P_0c010984;
P_0c010982: /* original 54f1, guest PC 0x0c010982 */
if(!s->budget--) { s->failed_pc=0x0c010982u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c010984;
P_0c010984: /* original 7f0c, guest PC 0x0c010984 */
if(!s->budget--) { s->failed_pc=0x0c010984u; return 0; }
r[15]+=0x0000000cu;
goto P_0c010986;
P_0c010986: /* original 4f26, guest PC 0x0c010986 */
if(!s->budget--) { s->failed_pc=0x0c010986u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c010988;
P_0c010988: /* original 000b, guest PC 0x0c010988 */
if(!s->budget--) { s->failed_pc=0x0c010988u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c01098a: /* original 0009, guest PC 0x0c01098a */
if(!s->budget--) { s->failed_pc=0x0c01098au; return 0; }
if(!vf3_matrix_family(0x0c01098cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c01098cu; return 0; } return 1;
P_0c010f3c: /* original 2fe6, guest PC 0x0c010f3c */
if(!s->budget--) { s->failed_pc=0x0c010f3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c010f3e;
P_0c010f3e: /* original 2fd6, guest PC 0x0c010f3e */
if(!s->budget--) { s->failed_pc=0x0c010f3eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c010f40;
P_0c010f40: /* original d741, guest PC 0x0c010f40 */
if(!s->budget--) { s->failed_pc=0x0c010f40u; return 0; }
r[7]=read(ram,0x0c011048u,4);
if(!vf3_matrix_family(0x0c010f42u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c010f42u; return 0; } return 1;
P_0c0113b4: /* original 2fe6, guest PC 0x0c0113b4 */
if(!s->budget--) { s->failed_pc=0x0c0113b4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0113b6;
P_0c0113b6: /* original 2fd6, guest PC 0x0c0113b6 */
if(!s->budget--) { s->failed_pc=0x0c0113b6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0113b8;
P_0c0113b8: /* original 2fc6, guest PC 0x0c0113b8 */
if(!s->budget--) { s->failed_pc=0x0c0113b8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0113ba;
P_0c0113ba: /* original 2fb6, guest PC 0x0c0113ba */
if(!s->budget--) { s->failed_pc=0x0c0113bau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0113bc;
P_0c0113bc: /* original 2fa6, guest PC 0x0c0113bc */
if(!s->budget--) { s->failed_pc=0x0c0113bcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0113be;
P_0c0113be: /* original 2f96, guest PC 0x0c0113be */
if(!s->budget--) { s->failed_pc=0x0c0113beu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0113c0;
P_0c0113c0: /* original 2f86, guest PC 0x0c0113c0 */
if(!s->budget--) { s->failed_pc=0x0c0113c0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(0x0c0113c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0113c2u; return 0; } return 1;
P_0c011a24: /* original 4f22, guest PC 0x0c011a24 */
if(!s->budget--) { s->failed_pc=0x0c011a24u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c011a26;
P_0c011a26: /* original 7ffc, guest PC 0x0c011a26 */
if(!s->budget--) { s->failed_pc=0x0c011a26u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c011a28;
P_0c011a28: /* original dd13, guest PC 0x0c011a28 */
if(!s->budget--) { s->failed_pc=0x0c011a28u; return 0; }
r[13]=read(ram,0x0c011a78u,4);
goto P_0c011a2a;
P_0c011a2a: /* original 6b53, guest PC 0x0c011a2a */
if(!s->budget--) { s->failed_pc=0x0c011a2au; return 0; }
r[11]=r[5];
goto P_0c011a2c;
P_0c011a2c: /* original 4b15, guest PC 0x0c011a2c */
if(!s->budget--) { s->failed_pc=0x0c011a2cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c011a2e;
P_0c011a2e: /* original 2f42, guest PC 0x0c011a2e */
if(!s->budget--) { s->failed_pc=0x0c011a2eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c011a30;
P_0c011a30: /* original ee00, guest PC 0x0c011a30 */
if(!s->budget--) { s->failed_pc=0x0c011a30u; return 0; }
r[14]=0x00000000u;
goto P_0c011a32;
P_0c011a32: /* original 8f14, guest PC 0x0c011a32 */
if(!s->budget--) { s->failed_pc=0x0c011a32u; return 0; }
cond=r[17]&1u;
r[12]=0x0000000fu;
if(!cond) { goto P_0c011a5e; }
goto P_0c011a36;
P_0c011a34: /* original ec0f, guest PC 0x0c011a34 */
if(!s->budget--) { s->failed_pc=0x0c011a34u; return 0; }
r[12]=0x0000000fu;
goto P_0c011a36;
P_0c011a36: /* original 62e3, guest PC 0x0c011a36 */
if(!s->budget--) { s->failed_pc=0x0c011a36u; return 0; }
r[2]=r[14];
goto P_0c011a38;
P_0c011a38: /* original 22c8, guest PC 0x0c011a38 */
if(!s->budget--) { s->failed_pc=0x0c011a38u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c011a3a;
P_0c011a3a: /* original 8b06, guest PC 0x0c011a3a */
if(!s->budget--) { s->failed_pc=0x0c011a3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c011a4a; }
goto P_0c011a3c;
P_0c011a3c: /* original d111, guest PC 0x0c011a3c */
if(!s->budget--) { s->failed_pc=0x0c011a3cu; return 0; }
r[1]=read(ram,0x0c011a84u,4);
goto P_0c011a3e;
P_0c011a3e: /* original c700, guest PC 0x0c011a3e */
if(!s->budget--) { s->failed_pc=0x0c011a3eu; return 0; }
r[0]=code_base|0x00011a40u;
goto P_0c011a40;
P_0c011a40: /* original 310c, guest PC 0x0c011a40 */
if(!s->budget--) { s->failed_pc=0x0c011a40u; return 0; }
r[1]+=r[0];
goto P_0c011a42;
P_0c011a42: /* original 6313, guest PC 0x0c011a42 */
if(!s->budget--) { s->failed_pc=0x0c011a42u; return 0; }
r[3]=r[1];
goto P_0c011a44;
P_0c011a44: /* original 23db, guest PC 0x0c011a44 */
if(!s->budget--) { s->failed_pc=0x0c011a44u; return 0; }
r[3]|=r[13];
goto P_0c011a46;
P_0c011a46: /* original 430b, guest PC 0x0c011a46 */
if(!s->budget--) { s->failed_pc=0x0c011a46u; return 0; }
target=r[3];
r[16]=code_base|0x0c011a4au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c011a4au) { target=s->pc; goto dispatch; }
goto P_0c011a4a;
P_0c011a48: /* original 0009, guest PC 0x0c011a48 */
if(!s->budget--) { s->failed_pc=0x0c011a48u; return 0; }
goto P_0c011a4a;
P_0c011a4a: /* original d30f, guest PC 0x0c011a4a */
if(!s->budget--) { s->failed_pc=0x0c011a4au; return 0; }
r[3]=read(ram,0x0c011a88u,4);
goto P_0c011a4c;
P_0c011a4c: /* original c700, guest PC 0x0c011a4c */
if(!s->budget--) { s->failed_pc=0x0c011a4cu; return 0; }
r[0]=code_base|0x00011a50u;
goto P_0c011a4e;
P_0c011a4e: /* original 330c, guest PC 0x0c011a4e */
if(!s->budget--) { s->failed_pc=0x0c011a4eu; return 0; }
r[3]+=r[0];
goto P_0c011a50;
P_0c011a50: /* original 60f2, guest PC 0x0c011a50 */
if(!s->budget--) { s->failed_pc=0x0c011a50u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c011a52;
P_0c011a52: /* original 23db, guest PC 0x0c011a52 */
if(!s->budget--) { s->failed_pc=0x0c011a52u; return 0; }
r[3]|=r[13];
goto P_0c011a54;
P_0c011a54: /* original 430b, guest PC 0x0c011a54 */
if(!s->budget--) { s->failed_pc=0x0c011a54u; return 0; }
target=r[3];
r[16]=code_base|0x0c011a58u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c011a58u) { target=s->pc; goto dispatch; }
goto P_0c011a58;
P_0c011a56: /* original 04ec, guest PC 0x0c011a56 */
if(!s->budget--) { s->failed_pc=0x0c011a56u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c011a58;
P_0c011a58: /* original 7e01, guest PC 0x0c011a58 */
if(!s->budget--) { s->failed_pc=0x0c011a58u; return 0; }
r[14]+=0x00000001u;
goto P_0c011a5a;
P_0c011a5a: /* original 3eb3, guest PC 0x0c011a5a */
if(!s->budget--) { s->failed_pc=0x0c011a5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c011a5c;
P_0c011a5c: /* original 8beb, guest PC 0x0c011a5c */
if(!s->budget--) { s->failed_pc=0x0c011a5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c011a36; }
goto P_0c011a5e;
P_0c011a5e: /* original 7f04, guest PC 0x0c011a5e */
if(!s->budget--) { s->failed_pc=0x0c011a5eu; return 0; }
r[15]+=0x00000004u;
goto P_0c011a60;
P_0c011a60: /* original 4f26, guest PC 0x0c011a60 */
if(!s->budget--) { s->failed_pc=0x0c011a60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c011a62;
P_0c011a62: /* original 6bf6, guest PC 0x0c011a62 */
if(!s->budget--) { s->failed_pc=0x0c011a62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c011a64;
P_0c011a64: /* original 6cf6, guest PC 0x0c011a64 */
if(!s->budget--) { s->failed_pc=0x0c011a64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c011a66;
P_0c011a66: /* original 6df6, guest PC 0x0c011a66 */
if(!s->budget--) { s->failed_pc=0x0c011a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c011a68;
P_0c011a68: /* original 000b, guest PC 0x0c011a68 */
if(!s->budget--) { s->failed_pc=0x0c011a68u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c011a6a: /* original 6ef6, guest PC 0x0c011a6a */
if(!s->budget--) { s->failed_pc=0x0c011a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c011a6cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c011a6cu; return 0; } return 1;
P_0c035270: /* original 4f22, guest PC 0x0c035270 */
if(!s->budget--) { s->failed_pc=0x0c035270u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035272;
P_0c035272: /* original 6673, guest PC 0x0c035272 */
if(!s->budget--) { s->failed_pc=0x0c035272u; return 0; }
r[6]=r[7];
goto P_0c035274;
P_0c035274: /* original 7ff8, guest PC 0x0c035274 */
if(!s->budget--) { s->failed_pc=0x0c035274u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c035276;
P_0c035276: /* original 1f41, guest PC 0x0c035276 */
if(!s->budget--) { s->failed_pc=0x0c035276u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c035278;
P_0c035278: /* original 2f52, guest PC 0x0c035278 */
if(!s->budget--) { s->failed_pc=0x0c035278u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03527a;
P_0c03527a: /* original 6573, guest PC 0x0c03527a */
if(!s->budget--) { s->failed_pc=0x0c03527au; return 0; }
r[5]=r[7];
goto P_0c03527c;
P_0c03527c: /* original de83, guest PC 0x0c03527c */
if(!s->budget--) { s->failed_pc=0x0c03527cu; return 0; }
r[14]=read(ram,0x0c03548cu,4);
goto P_0c03527e;
P_0c03527e: /* original d384, guest PC 0x0c03527e */
if(!s->budget--) { s->failed_pc=0x0c03527eu; return 0; }
r[3]=read(ram,0x0c035490u,4);
goto P_0c035280;
P_0c035280: /* original 64e2, guest PC 0x0c035280 */
if(!s->budget--) { s->failed_pc=0x0c035280u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c035282;
P_0c035282: /* original 430b, guest PC 0x0c035282 */
if(!s->budget--) { s->failed_pc=0x0c035282u; return 0; }
target=r[3];
r[16]=code_base|0x0c035286u;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035286u) { target=s->pc; goto dispatch; }
goto P_0c035286;
P_0c035284: /* original 544b, guest PC 0x0c035284 */
if(!s->budget--) { s->failed_pc=0x0c035284u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c035286;
P_0c035286: /* original 2008, guest PC 0x0c035286 */
if(!s->budget--) { s->failed_pc=0x0c035286u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c035288;
P_0c035288: /* original 8908, guest PC 0x0c035288 */
if(!s->budget--) { s->failed_pc=0x0c035288u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03529c; }
goto P_0c03528a;
P_0c03528a: /* original 63e2, guest PC 0x0c03528a */
if(!s->budget--) { s->failed_pc=0x0c03528au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03528c;
P_0c03528c: /* original 65f2, guest PC 0x0c03528c */
if(!s->budget--) { s->failed_pc=0x0c03528cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03528e;
P_0c03528e: /* original 5235, guest PC 0x0c03528e */
if(!s->budget--) { s->failed_pc=0x0c03528eu; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c035290;
P_0c035290: /* original 512e, guest PC 0x0c035290 */
if(!s->budget--) { s->failed_pc=0x0c035290u; return 0; }
r[1]=read(ram,r[2]+56,4);
goto P_0c035292;
P_0c035292: /* original 410b, guest PC 0x0c035292 */
if(!s->budget--) { s->failed_pc=0x0c035292u; return 0; }
target=r[1];
r[16]=code_base|0x0c035296u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035296u) { target=s->pc; goto dispatch; }
goto P_0c035296;
P_0c035294: /* original 54f1, guest PC 0x0c035294 */
if(!s->budget--) { s->failed_pc=0x0c035294u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c035296;
P_0c035296: /* original 6403, guest PC 0x0c035296 */
if(!s->budget--) { s->failed_pc=0x0c035296u; return 0; }
r[4]=r[0];
goto P_0c035298;
P_0c035298: /* original 2448, guest PC 0x0c035298 */
if(!s->budget--) { s->failed_pc=0x0c035298u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03529a;
P_0c03529a: /* original 8b04, guest PC 0x0c03529a */
if(!s->budget--) { s->failed_pc=0x0c03529au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0352a6; }
goto P_0c03529c;
P_0c03529c: /* original 7f08, guest PC 0x0c03529c */
if(!s->budget--) { s->failed_pc=0x0c03529cu; return 0; }
r[15]+=0x00000008u;
goto P_0c03529e;
P_0c03529e: /* original 4f26, guest PC 0x0c03529e */
if(!s->budget--) { s->failed_pc=0x0c03529eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0352a0;
P_0c0352a0: /* original e0f3, guest PC 0x0c0352a0 */
if(!s->budget--) { s->failed_pc=0x0c0352a0u; return 0; }
r[0]=0xfffffff3u;
goto P_0c0352a2;
P_0c0352a2: /* original 000b, guest PC 0x0c0352a2 */
if(!s->budget--) { s->failed_pc=0x0c0352a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0352a4: /* original 6ef6, guest PC 0x0c0352a4 */
if(!s->budget--) { s->failed_pc=0x0c0352a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0352a6;
P_0c0352a6: /* original 62e2, guest PC 0x0c0352a6 */
if(!s->budget--) { s->failed_pc=0x0c0352a6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0352a8;
P_0c0352a8: /* original e04c, guest PC 0x0c0352a8 */
if(!s->budget--) { s->failed_pc=0x0c0352a8u; return 0; }
r[0]=0x0000004cu;
goto P_0c0352aa;
P_0c0352aa: /* original e104, guest PC 0x0c0352aa */
if(!s->budget--) { s->failed_pc=0x0c0352aau; return 0; }
r[1]=0x00000004u;
goto P_0c0352ac;
P_0c0352ac: /* original 532b, guest PC 0x0c0352ac */
if(!s->budget--) { s->failed_pc=0x0c0352acu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c0352ae;
P_0c0352ae: /* original 134f, guest PC 0x0c0352ae */
if(!s->budget--) { s->failed_pc=0x0c0352aeu; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c0352b0;
P_0c0352b0: /* original 62e2, guest PC 0x0c0352b0 */
if(!s->budget--) { s->failed_pc=0x0c0352b0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0352b2;
P_0c0352b2: /* original 532b, guest PC 0x0c0352b2 */
if(!s->budget--) { s->failed_pc=0x0c0352b2u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c0352b4;
P_0c0352b4: /* original 0315, guest PC 0x0c0352b4 */
if(!s->budget--) { s->failed_pc=0x0c0352b4u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0352b6;
P_0c0352b6: /* original 63e2, guest PC 0x0c0352b6 */
if(!s->budget--) { s->failed_pc=0x0c0352b6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0352b8;
P_0c0352b8: /* original 6233, guest PC 0x0c0352b8 */
if(!s->budget--) { s->failed_pc=0x0c0352b8u; return 0; }
r[2]=r[3];
goto P_0c0352ba;
P_0c0352ba: /* original 512b, guest PC 0x0c0352ba */
if(!s->budget--) { s->failed_pc=0x0c0352bau; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c0352bc;
P_0c0352bc: /* original 131a, guest PC 0x0c0352bc */
if(!s->budget--) { s->failed_pc=0x0c0352bcu; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c0352be;
P_0c0352be: /* original d376, guest PC 0x0c0352be */
if(!s->budget--) { s->failed_pc=0x0c0352beu; return 0; }
r[3]=read(ram,0x0c035498u,4);
goto P_0c0352c0;
P_0c0352c0: /* original 64e2, guest PC 0x0c0352c0 */
if(!s->budget--) { s->failed_pc=0x0c0352c0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0352c2;
P_0c0352c2: /* original 430b, guest PC 0x0c0352c2 */
if(!s->budget--) { s->failed_pc=0x0c0352c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0352c6u;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0352c6u) { target=s->pc; goto dispatch; }
goto P_0c0352c6;
P_0c0352c4: /* original 544b, guest PC 0x0c0352c4 */
if(!s->budget--) { s->failed_pc=0x0c0352c4u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0352c6;
P_0c0352c6: /* original 2f02, guest PC 0x0c0352c6 */
if(!s->budget--) { s->failed_pc=0x0c0352c6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0352c8;
P_0c0352c8: /* original d374, guest PC 0x0c0352c8 */
if(!s->budget--) { s->failed_pc=0x0c0352c8u; return 0; }
r[3]=read(ram,0x0c03549cu,4);
goto P_0c0352ca;
P_0c0352ca: /* original 64e2, guest PC 0x0c0352ca */
if(!s->budget--) { s->failed_pc=0x0c0352cau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0352cc;
P_0c0352cc: /* original 430b, guest PC 0x0c0352cc */
if(!s->budget--) { s->failed_pc=0x0c0352ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0352d0u;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0352d0u) { target=s->pc; goto dispatch; }
goto P_0c0352d0;
P_0c0352ce: /* original 544b, guest PC 0x0c0352ce */
if(!s->budget--) { s->failed_pc=0x0c0352ceu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0352d0;
P_0c0352d0: /* original 60f2, guest PC 0x0c0352d0 */
if(!s->budget--) { s->failed_pc=0x0c0352d0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0352d2;
P_0c0352d2: /* original 7f08, guest PC 0x0c0352d2 */
if(!s->budget--) { s->failed_pc=0x0c0352d2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0352d4;
P_0c0352d4: /* original 4f26, guest PC 0x0c0352d4 */
if(!s->budget--) { s->failed_pc=0x0c0352d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0352d6;
P_0c0352d6: /* original 000b, guest PC 0x0c0352d6 */
if(!s->budget--) { s->failed_pc=0x0c0352d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0352d8: /* original 6ef6, guest PC 0x0c0352d8 */
if(!s->budget--) { s->failed_pc=0x0c0352d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0352dau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0352dau; return 0; } return 1;
P_0c035306: /* original 4f22, guest PC 0x0c035306 */
if(!s->budget--) { s->failed_pc=0x0c035306u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035308;
P_0c035308: /* original 7ff4, guest PC 0x0c035308 */
if(!s->budget--) { s->failed_pc=0x0c035308u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c03530a;
P_0c03530a: /* original 1f41, guest PC 0x0c03530a */
if(!s->budget--) { s->failed_pc=0x0c03530au; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03530c;
P_0c03530c: /* original 2f52, guest PC 0x0c03530c */
if(!s->budget--) { s->failed_pc=0x0c03530cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03530e;
P_0c03530e: /* original 6573, guest PC 0x0c03530e */
if(!s->budget--) { s->failed_pc=0x0c03530eu; return 0; }
r[5]=r[7];
goto P_0c035310;
P_0c035310: /* original 1f62, guest PC 0x0c035310 */
if(!s->budget--) { s->failed_pc=0x0c035310u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c035312;
P_0c035312: /* original 6673, guest PC 0x0c035312 */
if(!s->budget--) { s->failed_pc=0x0c035312u; return 0; }
r[6]=r[7];
goto P_0c035314;
P_0c035314: /* original de5d, guest PC 0x0c035314 */
if(!s->budget--) { s->failed_pc=0x0c035314u; return 0; }
r[14]=read(ram,0x0c03548cu,4);
goto P_0c035316;
P_0c035316: /* original d35e, guest PC 0x0c035316 */
if(!s->budget--) { s->failed_pc=0x0c035316u; return 0; }
r[3]=read(ram,0x0c035490u,4);
goto P_0c035318;
P_0c035318: /* original 64e2, guest PC 0x0c035318 */
if(!s->budget--) { s->failed_pc=0x0c035318u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c03531a;
P_0c03531a: /* original 430b, guest PC 0x0c03531a */
if(!s->budget--) { s->failed_pc=0x0c03531au; return 0; }
target=r[3];
r[16]=code_base|0x0c03531eu;
r[4]=read(ram,r[4]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03531eu) { target=s->pc; goto dispatch; }
goto P_0c03531e;
P_0c03531c: /* original 544b, guest PC 0x0c03531c */
if(!s->budget--) { s->failed_pc=0x0c03531cu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c03531e;
P_0c03531e: /* original 2008, guest PC 0x0c03531e */
if(!s->budget--) { s->failed_pc=0x0c03531eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c035320;
P_0c035320: /* original 8909, guest PC 0x0c035320 */
if(!s->budget--) { s->failed_pc=0x0c035320u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035336; }
goto P_0c035322;
P_0c035322: /* original 63e2, guest PC 0x0c035322 */
if(!s->budget--) { s->failed_pc=0x0c035322u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035324;
P_0c035324: /* original 65f2, guest PC 0x0c035324 */
if(!s->budget--) { s->failed_pc=0x0c035324u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c035326;
P_0c035326: /* original 5235, guest PC 0x0c035326 */
if(!s->budget--) { s->failed_pc=0x0c035326u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c035328;
P_0c035328: /* original 56f2, guest PC 0x0c035328 */
if(!s->budget--) { s->failed_pc=0x0c035328u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c03532a;
P_0c03532a: /* original 512a, guest PC 0x0c03532a */
if(!s->budget--) { s->failed_pc=0x0c03532au; return 0; }
r[1]=read(ram,r[2]+40,4);
goto P_0c03532c;
P_0c03532c: /* original 410b, guest PC 0x0c03532c */
if(!s->budget--) { s->failed_pc=0x0c03532cu; return 0; }
target=r[1];
r[16]=code_base|0x0c035330u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035330u) { target=s->pc; goto dispatch; }
goto P_0c035330;
P_0c03532e: /* original 54f1, guest PC 0x0c03532e */
if(!s->budget--) { s->failed_pc=0x0c03532eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c035330;
P_0c035330: /* original 6403, guest PC 0x0c035330 */
if(!s->budget--) { s->failed_pc=0x0c035330u; return 0; }
r[4]=r[0];
goto P_0c035332;
P_0c035332: /* original 2448, guest PC 0x0c035332 */
if(!s->budget--) { s->failed_pc=0x0c035332u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c035334;
P_0c035334: /* original 8b04, guest PC 0x0c035334 */
if(!s->budget--) { s->failed_pc=0x0c035334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035340; }
goto P_0c035336;
P_0c035336: /* original 7f0c, guest PC 0x0c035336 */
if(!s->budget--) { s->failed_pc=0x0c035336u; return 0; }
r[15]+=0x0000000cu;
goto P_0c035338;
P_0c035338: /* original 4f26, guest PC 0x0c035338 */
if(!s->budget--) { s->failed_pc=0x0c035338u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03533a;
P_0c03533a: /* original e0f3, guest PC 0x0c03533a */
if(!s->budget--) { s->failed_pc=0x0c03533au; return 0; }
r[0]=0xfffffff3u;
goto P_0c03533c;
P_0c03533c: /* original 000b, guest PC 0x0c03533c */
if(!s->budget--) { s->failed_pc=0x0c03533cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03533e: /* original 6ef6, guest PC 0x0c03533e */
if(!s->budget--) { s->failed_pc=0x0c03533eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035340;
P_0c035340: /* original 62e2, guest PC 0x0c035340 */
if(!s->budget--) { s->failed_pc=0x0c035340u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c035342;
P_0c035342: /* original e04c, guest PC 0x0c035342 */
if(!s->budget--) { s->failed_pc=0x0c035342u; return 0; }
r[0]=0x0000004cu;
goto P_0c035344;
P_0c035344: /* original e104, guest PC 0x0c035344 */
if(!s->budget--) { s->failed_pc=0x0c035344u; return 0; }
r[1]=0x00000004u;
goto P_0c035346;
P_0c035346: /* original 532b, guest PC 0x0c035346 */
if(!s->budget--) { s->failed_pc=0x0c035346u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c035348;
P_0c035348: /* original 134f, guest PC 0x0c035348 */
if(!s->budget--) { s->failed_pc=0x0c035348u; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c03534a;
P_0c03534a: /* original 62e2, guest PC 0x0c03534a */
if(!s->budget--) { s->failed_pc=0x0c03534au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03534c;
P_0c03534c: /* original 532b, guest PC 0x0c03534c */
if(!s->budget--) { s->failed_pc=0x0c03534cu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c03534e;
P_0c03534e: /* original 0315, guest PC 0x0c03534e */
if(!s->budget--) { s->failed_pc=0x0c03534eu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c035350;
P_0c035350: /* original e044, guest PC 0x0c035350 */
if(!s->budget--) { s->failed_pc=0x0c035350u; return 0; }
r[0]=0x00000044u;
goto P_0c035352;
P_0c035352: /* original 63e2, guest PC 0x0c035352 */
if(!s->budget--) { s->failed_pc=0x0c035352u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035354;
P_0c035354: /* original e106, guest PC 0x0c035354 */
if(!s->budget--) { s->failed_pc=0x0c035354u; return 0; }
r[1]=0x00000006u;
goto P_0c035356;
P_0c035356: /* original 523b, guest PC 0x0c035356 */
if(!s->budget--) { s->failed_pc=0x0c035356u; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c035358;
P_0c035358: /* original 0215, guest PC 0x0c035358 */
if(!s->budget--) { s->failed_pc=0x0c035358u; return 0; }
write(ram,r[2]+r[0],r[1],2);
goto P_0c03535a;
P_0c03535a: /* original 63e2, guest PC 0x0c03535a */
if(!s->budget--) { s->failed_pc=0x0c03535au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03535c;
P_0c03535c: /* original 6233, guest PC 0x0c03535c */
if(!s->budget--) { s->failed_pc=0x0c03535cu; return 0; }
r[2]=r[3];
goto P_0c03535e;
P_0c03535e: /* original 512b, guest PC 0x0c03535e */
if(!s->budget--) { s->failed_pc=0x0c03535eu; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c035360;
P_0c035360: /* original 131a, guest PC 0x0c035360 */
if(!s->budget--) { s->failed_pc=0x0c035360u; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c035362;
P_0c035362: /* original e000, guest PC 0x0c035362 */
if(!s->budget--) { s->failed_pc=0x0c035362u; return 0; }
r[0]=0x00000000u;
goto P_0c035364;
P_0c035364: /* original 7f0c, guest PC 0x0c035364 */
if(!s->budget--) { s->failed_pc=0x0c035364u; return 0; }
r[15]+=0x0000000cu;
goto P_0c035366;
P_0c035366: /* original 4f26, guest PC 0x0c035366 */
if(!s->budget--) { s->failed_pc=0x0c035366u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035368;
P_0c035368: /* original 000b, guest PC 0x0c035368 */
if(!s->budget--) { s->failed_pc=0x0c035368u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03536a: /* original 6ef6, guest PC 0x0c03536a */
if(!s->budget--) { s->failed_pc=0x0c03536au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03536cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03536cu; return 0; } return 1;
P_0c035518: /* original 4f22, guest PC 0x0c035518 */
if(!s->budget--) { s->failed_pc=0x0c035518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03551a;
P_0c03551a: /* original d333, guest PC 0x0c03551a */
if(!s->budget--) { s->failed_pc=0x0c03551au; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c03551c;
P_0c03551c: /* original 6d32, guest PC 0x0c03551c */
if(!s->budget--) { s->failed_pc=0x0c03551cu; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c03551e;
P_0c03551e: /* original 9c61, guest PC 0x0c03551e */
if(!s->budget--) { s->failed_pc=0x0c03551eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0355e4u,2);
goto P_0c035520;
P_0c035520: /* original da32, guest PC 0x0c035520 */
if(!s->budget--) { s->failed_pc=0x0c035520u; return 0; }
r[10]=read(ram,0x0c0355ecu,4);
goto P_0c035522;
P_0c035522: /* original 5be6, guest PC 0x0c035522 */
if(!s->budget--) { s->failed_pc=0x0c035522u; return 0; }
r[11]=read(ram,r[14]+24,4);
goto P_0c035524;
P_0c035524: /* original 60e2, guest PC 0x0c035524 */
if(!s->budget--) { s->failed_pc=0x0c035524u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c035526;
P_0c035526: /* original 5009, guest PC 0x0c035526 */
if(!s->budget--) { s->failed_pc=0x0c035526u; return 0; }
r[0]=read(ram,r[0]+36,4);
goto P_0c035528;
P_0c035528: /* original 8802, guest PC 0x0c035528 */
if(!s->budget--) { s->failed_pc=0x0c035528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03552a;
P_0c03552a: /* original 8901, guest PC 0x0c03552a */
if(!s->budget--) { s->failed_pc=0x0c03552au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035530; }
goto P_0c03552c;
P_0c03552c: /* original 4a0b, guest PC 0x0c03552c */
if(!s->budget--) { s->failed_pc=0x0c03552cu; return 0; }
target=r[10];
r[16]=code_base|0x0c035530u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035530u) { target=s->pc; goto dispatch; }
goto P_0c035530;
P_0c03552e: /* original 0009, guest PC 0x0c03552e */
if(!s->budget--) { s->failed_pc=0x0c03552eu; return 0; }
goto P_0c035530;
P_0c035530: /* original b276, guest PC 0x0c035530 */
if(!s->budget--) { s->failed_pc=0x0c035530u; return 0; }
target=code_base|0x0c035a20u; r[16]=code_base|0x0c035534u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035534u) { target=s->pc; goto dispatch; }
goto P_0c035534;
P_0c035532: /* original 64e3, guest PC 0x0c035532 */
if(!s->budget--) { s->failed_pc=0x0c035532u; return 0; }
r[4]=r[14];
goto P_0c035534;
P_0c035534: /* original 8800, guest PC 0x0c035534 */
if(!s->budget--) { s->failed_pc=0x0c035534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c035536;
P_0c035536: /* original 8d0e, guest PC 0x0c035536 */
if(!s->budget--) { s->failed_pc=0x0c035536u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c035556; }
goto P_0c03553a;
P_0c035538: /* original 6403, guest PC 0x0c035538 */
if(!s->budget--) { s->failed_pc=0x0c035538u; return 0; }
r[4]=r[0];
goto P_0c03553a;
P_0c03553a: /* original 8801, guest PC 0x0c03553a */
if(!s->budget--) { s->failed_pc=0x0c03553au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03553c;
P_0c03553c: /* original 890d, guest PC 0x0c03553c */
if(!s->budget--) { s->failed_pc=0x0c03553cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555a; }
goto P_0c03553e;
P_0c03553e: /* original 8802, guest PC 0x0c03553e */
if(!s->budget--) { s->failed_pc=0x0c03553eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035540;
P_0c035540: /* original 890d, guest PC 0x0c035540 */
if(!s->budget--) { s->failed_pc=0x0c035540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035542;
P_0c035542: /* original 8803, guest PC 0x0c035542 */
if(!s->budget--) { s->failed_pc=0x0c035542u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c035544;
P_0c035544: /* original 890b, guest PC 0x0c035544 */
if(!s->budget--) { s->failed_pc=0x0c035544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035546;
P_0c035546: /* original 8804, guest PC 0x0c035546 */
if(!s->budget--) { s->failed_pc=0x0c035546u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c035548;
P_0c035548: /* original 8909, guest PC 0x0c035548 */
if(!s->budget--) { s->failed_pc=0x0c035548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c03554a;
P_0c03554a: /* original 8805, guest PC 0x0c03554a */
if(!s->budget--) { s->failed_pc=0x0c03554au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03554c;
P_0c03554c: /* original 890d, guest PC 0x0c03554c */
if(!s->budget--) { s->failed_pc=0x0c03554cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c03554e;
P_0c03554e: /* original 8806, guest PC 0x0c03554e */
if(!s->budget--) { s->failed_pc=0x0c03554eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c035550;
P_0c035550: /* original 890b, guest PC 0x0c035550 */
if(!s->budget--) { s->failed_pc=0x0c035550u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c035552;
P_0c035552: /* original a00d, guest PC 0x0c035552 */
if(!s->budget--) { s->failed_pc=0x0c035552u; return 0; }
goto P_0c035570;
P_0c035554: /* original 0009, guest PC 0x0c035554 */
if(!s->budget--) { s->failed_pc=0x0c035554u; return 0; }
goto P_0c035556;
P_0c035556: /* original a013, guest PC 0x0c035556 */
if(!s->budget--) { s->failed_pc=0x0c035556u; return 0; }
r[0]=0xffffffe0u;
goto P_0c035580;
P_0c035558: /* original e0e0, guest PC 0x0c035558 */
if(!s->budget--) { s->failed_pc=0x0c035558u; return 0; }
r[0]=0xffffffe0u;
goto P_0c03555a;
P_0c03555a: /* original a011, guest PC 0x0c03555a */
if(!s->budget--) { s->failed_pc=0x0c03555au; return 0; }
r[0]=0x00000000u;
goto P_0c035580;
P_0c03555c: /* original e000, guest PC 0x0c03555c */
if(!s->budget--) { s->failed_pc=0x0c03555cu; return 0; }
r[0]=0x00000000u;
goto P_0c03555e;
P_0c03555e: /* original 53e6, guest PC 0x0c03555e */
if(!s->budget--) { s->failed_pc=0x0c03555eu; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c035560;
P_0c035560: /* original 3b30, guest PC 0x0c035560 */
if(!s->budget--) { s->failed_pc=0x0c035560u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c035562;
P_0c035562: /* original 8907, guest PC 0x0c035562 */
if(!s->budget--) { s->failed_pc=0x0c035562u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035574; }
goto P_0c035564;
P_0c035564: /* original d120, guest PC 0x0c035564 */
if(!s->budget--) { s->failed_pc=0x0c035564u; return 0; }
r[1]=read(ram,0x0c0355e8u,4);
goto P_0c035566;
P_0c035566: /* original a005, guest PC 0x0c035566 */
if(!s->budget--) { s->failed_pc=0x0c035566u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c035574;
P_0c035568: /* original 6d12, guest PC 0x0c035568 */
if(!s->budget--) { s->failed_pc=0x0c035568u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c03556a;
P_0c03556a: /* original e04e, guest PC 0x0c03556a */
if(!s->budget--) { s->failed_pc=0x0c03556au; return 0; }
r[0]=0x0000004eu;
goto P_0c03556c;
P_0c03556c: /* original a008, guest PC 0x0c03556c */
if(!s->budget--) { s->failed_pc=0x0c03556cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035580;
P_0c03556e: /* original 00ed, guest PC 0x0c03556e */
if(!s->budget--) { s->failed_pc=0x0c03556eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035570;
P_0c035570: /* original a006, guest PC 0x0c035570 */
if(!s->budget--) { s->failed_pc=0x0c035570u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035580;
P_0c035572: /* original e0e7, guest PC 0x0c035572 */
if(!s->budget--) { s->failed_pc=0x0c035572u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035574;
P_0c035574: /* original d31c, guest PC 0x0c035574 */
if(!s->budget--) { s->failed_pc=0x0c035574u; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c035576;
P_0c035576: /* original 6432, guest PC 0x0c035576 */
if(!s->budget--) { s->failed_pc=0x0c035576u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c035578;
P_0c035578: /* original 34d8, guest PC 0x0c035578 */
if(!s->budget--) { s->failed_pc=0x0c035578u; return 0; }
r[4]-=r[13];
goto P_0c03557a;
P_0c03557a: /* original 34c6, guest PC 0x0c03557a */
if(!s->budget--) { s->failed_pc=0x0c03557au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[12])!=0);
goto P_0c03557c;
P_0c03557c: /* original 8bd2, guest PC 0x0c03557c */
if(!s->budget--) { s->failed_pc=0x0c03557cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035524; }
goto P_0c03557e;
P_0c03557e: /* original e0eb, guest PC 0x0c03557e */
if(!s->budget--) { s->failed_pc=0x0c03557eu; return 0; }
r[0]=0xffffffebu;
goto P_0c035580;
P_0c035580: /* original 4f26, guest PC 0x0c035580 */
if(!s->budget--) { s->failed_pc=0x0c035580u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035582;
P_0c035582: /* original 6af6, guest PC 0x0c035582 */
if(!s->budget--) { s->failed_pc=0x0c035582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035584;
P_0c035584: /* original 6bf6, guest PC 0x0c035584 */
if(!s->budget--) { s->failed_pc=0x0c035584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035586;
P_0c035586: /* original 6cf6, guest PC 0x0c035586 */
if(!s->budget--) { s->failed_pc=0x0c035586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035588;
P_0c035588: /* original 6df6, guest PC 0x0c035588 */
if(!s->budget--) { s->failed_pc=0x0c035588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03558a;
P_0c03558a: /* original 000b, guest PC 0x0c03558a */
if(!s->budget--) { s->failed_pc=0x0c03558au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03558c: /* original 6ef6, guest PC 0x0c03558c */
if(!s->budget--) { s->failed_pc=0x0c03558cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03558eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03558eu; return 0; } return 1;
P_0c039748: /* original 4f22, guest PC 0x0c039748 */
if(!s->budget--) { s->failed_pc=0x0c039748u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03974a;
P_0c03974a: /* original e600, guest PC 0x0c03974a */
if(!s->budget--) { s->failed_pc=0x0c03974au; return 0; }
r[6]=0x00000000u;
goto P_0c03974c;
P_0c03974c: /* original de43, guest PC 0x0c03974c */
if(!s->budget--) { s->failed_pc=0x0c03974cu; return 0; }
r[14]=read(ram,0x0c03985cu,4);
goto P_0c03974e;
P_0c03974e: /* original 2348, guest PC 0x0c03974e */
if(!s->budget--) { s->failed_pc=0x0c03974eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c039750;
P_0c039750: /* original 6063, guest PC 0x0c039750 */
if(!s->budget--) { s->failed_pc=0x0c039750u; return 0; }
r[0]=r[6];
goto P_0c039752;
P_0c039752: /* original 8d02, guest PC 0x0c039752 */
if(!s->budget--) { s->failed_pc=0x0c039752u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+8,r[0],2);
if(cond) { goto P_0c03975a; }
goto P_0c039756;
P_0c039754: /* original 81e4, guest PC 0x0c039754 */
if(!s->budget--) { s->failed_pc=0x0c039754u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c039756;
P_0c039756: /* original 6053, guest PC 0x0c039756 */
if(!s->budget--) { s->failed_pc=0x0c039756u; return 0; }
r[0]=r[5];
goto P_0c039758;
P_0c039758: /* original 81e4, guest PC 0x0c039758 */
if(!s->budget--) { s->failed_pc=0x0c039758u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c03975a;
P_0c03975a: /* original d341, guest PC 0x0c03975a */
if(!s->budget--) { s->failed_pc=0x0c03975au; return 0; }
r[3]=read(ram,0x0c039860u,4);
goto P_0c03975c;
P_0c03975c: /* original 6063, guest PC 0x0c03975c */
if(!s->budget--) { s->failed_pc=0x0c03975cu; return 0; }
r[0]=r[6];
goto P_0c03975e;
P_0c03975e: /* original 2438, guest PC 0x0c03975e */
if(!s->budget--) { s->failed_pc=0x0c03975eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c039760;
P_0c039760: /* original 8d02, guest PC 0x0c039760 */
if(!s->budget--) { s->failed_pc=0x0c039760u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+10,r[0],2);
if(cond) { goto P_0c039768; }
goto P_0c039764;
P_0c039762: /* original 81e5, guest PC 0x0c039762 */
if(!s->budget--) { s->failed_pc=0x0c039762u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c039764;
P_0c039764: /* original 6053, guest PC 0x0c039764 */
if(!s->budget--) { s->failed_pc=0x0c039764u; return 0; }
r[0]=r[5];
goto P_0c039766;
P_0c039766: /* original 81e5, guest PC 0x0c039766 */
if(!s->budget--) { s->failed_pc=0x0c039766u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c039768;
P_0c039768: /* original 85e5, guest PC 0x0c039768 */
if(!s->budget--) { s->failed_pc=0x0c039768u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c03976a;
P_0c03976a: /* original d33e, guest PC 0x0c03976a */
if(!s->budget--) { s->failed_pc=0x0c03976au; return 0; }
r[3]=read(ram,0x0c039864u,4);
goto P_0c03976c;
P_0c03976c: /* original 6503, guest PC 0x0c03976c */
if(!s->budget--) { s->failed_pc=0x0c03976cu; return 0; }
r[5]=r[0];
goto P_0c03976e;
P_0c03976e: /* original 85e4, guest PC 0x0c03976e */
if(!s->budget--) { s->failed_pc=0x0c03976eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c039770;
P_0c039770: /* original 430b, guest PC 0x0c039770 */
if(!s->budget--) { s->failed_pc=0x0c039770u; return 0; }
target=r[3];
r[16]=code_base|0x0c039774u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039774u) { target=s->pc; goto dispatch; }
goto P_0c039774;
P_0c039772: /* original 6403, guest PC 0x0c039772 */
if(!s->budget--) { s->failed_pc=0x0c039772u; return 0; }
r[4]=r[0];
goto P_0c039774;
P_0c039774: /* original de3c, guest PC 0x0c039774 */
if(!s->budget--) { s->failed_pc=0x0c039774u; return 0; }
r[14]=read(ram,0x0c039868u,4);
goto P_0c039776;
P_0c039776: /* original 55e1, guest PC 0x0c039776 */
if(!s->budget--) { s->failed_pc=0x0c039776u; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c039778;
P_0c039778: /* original 56e2, guest PC 0x0c039778 */
if(!s->budget--) { s->failed_pc=0x0c039778u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c03977a;
P_0c03977a: /* original bc31, guest PC 0x0c03977a */
if(!s->budget--) { s->failed_pc=0x0c03977au; return 0; }
target=code_base|0x0c038fe0u; r[16]=code_base|0x0c03977eu;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03977eu) { target=s->pc; goto dispatch; }
goto P_0c03977e;
P_0c03977c: /* original 64e2, guest PC 0x0c03977c */
if(!s->budget--) { s->failed_pc=0x0c03977cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c03977e;
P_0c03977e: /* original d33b, guest PC 0x0c03977e */
if(!s->budget--) { s->failed_pc=0x0c03977eu; return 0; }
r[3]=read(ram,0x0c03986cu,4);
goto P_0c039780;
P_0c039780: /* original d23b, guest PC 0x0c039780 */
if(!s->budget--) { s->failed_pc=0x0c039780u; return 0; }
r[2]=read(ram,0x0c039870u,4);
goto P_0c039782;
P_0c039782: /* original f738, guest PC 0x0c039782 */
if(!s->budget--) { s->failed_pc=0x0c039782u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
goto P_0c039784;
P_0c039784: /* original d33c, guest PC 0x0c039784 */
if(!s->budget--) { s->failed_pc=0x0c039784u; return 0; }
r[3]=read(ram,0x0c039878u,4);
goto P_0c039786;
P_0c039786: /* original d13b, guest PC 0x0c039786 */
if(!s->budget--) { s->failed_pc=0x0c039786u; return 0; }
r[1]=read(ram,0x0c039874u,4);
goto P_0c039788;
P_0c039788: /* original 4f26, guest PC 0x0c039788 */
if(!s->budget--) { s->failed_pc=0x0c039788u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03978a;
P_0c03978a: /* original f628, guest PC 0x0c03978a */
if(!s->budget--) { s->failed_pc=0x0c03978au; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c03978c;
P_0c03978c: /* original d23b, guest PC 0x0c03978c */
if(!s->budget--) { s->failed_pc=0x0c03978cu; return 0; }
r[2]=read(ram,0x0c03987cu,4);
goto P_0c03978e;
P_0c03978e: /* original f518, guest PC 0x0c03978e */
if(!s->budget--) { s->failed_pc=0x0c03978eu; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
goto P_0c039790;
P_0c039790: /* original f438, guest PC 0x0c039790 */
if(!s->budget--) { s->failed_pc=0x0c039790u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c039792;
P_0c039792: /* original 422b, guest PC 0x0c039792 */
if(!s->budget--) { s->failed_pc=0x0c039792u; return 0; }
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
P_0c039794: /* original 6ef6, guest PC 0x0c039794 */
if(!s->budget--) { s->failed_pc=0x0c039794u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c039796u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039796u; return 0; } return 1;
P_0c039cb4: /* original 4f22, guest PC 0x0c039cb4 */
if(!s->budget--) { s->failed_pc=0x0c039cb4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c039cb6;
P_0c039cb6: /* original 8801, guest PC 0x0c039cb6 */
if(!s->budget--) { s->failed_pc=0x0c039cb6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c039cb8;
P_0c039cb8: /* original 7ff8, guest PC 0x0c039cb8 */
if(!s->budget--) { s->failed_pc=0x0c039cb8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c039cba;
P_0c039cba: /* original 2f42, guest PC 0x0c039cba */
if(!s->budget--) { s->failed_pc=0x0c039cbau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c039cbc;
P_0c039cbc: /* original 6ef3, guest PC 0x0c039cbc */
if(!s->budget--) { s->failed_pc=0x0c039cbcu; return 0; }
r[14]=r[15];
goto P_0c039cbe;
P_0c039cbe: /* original 8d0f, guest PC 0x0c039cbe */
if(!s->budget--) { s->failed_pc=0x0c039cbeu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000004u;
if(cond) { goto P_0c039ce0; }
goto P_0c039cc2;
P_0c039cc0: /* original 7e04, guest PC 0x0c039cc0 */
if(!s->budget--) { s->failed_pc=0x0c039cc0u; return 0; }
r[14]+=0x00000004u;
goto P_0c039cc2;
P_0c039cc2: /* original 8802, guest PC 0x0c039cc2 */
if(!s->budget--) { s->failed_pc=0x0c039cc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c039cc4;
P_0c039cc4: /* original 8914, guest PC 0x0c039cc4 */
if(!s->budget--) { s->failed_pc=0x0c039cc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039cf0; }
goto P_0c039cc6;
P_0c039cc6: /* original 8803, guest PC 0x0c039cc6 */
if(!s->budget--) { s->failed_pc=0x0c039cc6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c039cc8;
P_0c039cc8: /* original 891a, guest PC 0x0c039cc8 */
if(!s->budget--) { s->failed_pc=0x0c039cc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039d00; }
goto P_0c039cca;
P_0c039cca: /* original 8804, guest PC 0x0c039cca */
if(!s->budget--) { s->failed_pc=0x0c039ccau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c039ccc;
P_0c039ccc: /* original 8950, guest PC 0x0c039ccc */
if(!s->budget--) { s->failed_pc=0x0c039cccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039d70; }
goto P_0c039cce;
P_0c039cce: /* original a051, guest PC 0x0c039cce */
if(!s->budget--) { s->failed_pc=0x0c039cceu; return 0; }
goto P_0c039d74;
P_0c039cd0: /* original 0009, guest PC 0x0c039cd0 */
if(!s->budget--) { s->failed_pc=0x0c039cd0u; return 0; }
if(!vf3_matrix_family(0x0c039cd2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039cd2u; return 0; } return 1;
P_0c039ce0: /* original d31f, guest PC 0x0c039ce0 */
if(!s->budget--) { s->failed_pc=0x0c039ce0u; return 0; }
r[3]=read(ram,0x0c039d60u,4);
goto P_0c039ce2;
P_0c039ce2: /* original a047, guest PC 0x0c039ce2 */
if(!s->budget--) { s->failed_pc=0x0c039ce2u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c039d74;
P_0c039ce4: /* original 2e32, guest PC 0x0c039ce4 */
if(!s->budget--) { s->failed_pc=0x0c039ce4u; return 0; }
write(ram,r[14],r[3],4);
if(!vf3_matrix_family(0x0c039ce6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039ce6u; return 0; } return 1;
P_0c039cf0: /* original d11c, guest PC 0x0c039cf0 */
if(!s->budget--) { s->failed_pc=0x0c039cf0u; return 0; }
r[1]=read(ram,0x0c039d64u,4);
goto P_0c039cf2;
P_0c039cf2: /* original a03e, guest PC 0x0c039cf2 */
if(!s->budget--) { s->failed_pc=0x0c039cf2u; return 0; }
goto P_0c039d72;
P_0c039cf4: /* original 0009, guest PC 0x0c039cf4 */
if(!s->budget--) { s->failed_pc=0x0c039cf4u; return 0; }
if(!vf3_matrix_family(0x0c039cf6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039cf6u; return 0; } return 1;
P_0c039d00: /* original d219, guest PC 0x0c039d00 */
if(!s->budget--) { s->failed_pc=0x0c039d00u; return 0; }
r[2]=read(ram,0x0c039d68u,4);
goto P_0c039d02;
P_0c039d02: /* original a037, guest PC 0x0c039d02 */
if(!s->budget--) { s->failed_pc=0x0c039d02u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c039d74;
P_0c039d04: /* original 2e22, guest PC 0x0c039d04 */
if(!s->budget--) { s->failed_pc=0x0c039d04u; return 0; }
write(ram,r[14],r[2],4);
if(!vf3_matrix_family(0x0c039d06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039d06u; return 0; } return 1;
P_0c039d70: /* original d115, guest PC 0x0c039d70 */
if(!s->budget--) { s->failed_pc=0x0c039d70u; return 0; }
r[1]=read(ram,0x0c039dc8u,4);
goto P_0c039d72;
P_0c039d72: /* original 2e12, guest PC 0x0c039d72 */
if(!s->budget--) { s->failed_pc=0x0c039d72u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c039d74;
P_0c039d74: /* original d315, guest PC 0x0c039d74 */
if(!s->budget--) { s->failed_pc=0x0c039d74u; return 0; }
r[3]=read(ram,0x0c039dccu,4);
goto P_0c039d76;
P_0c039d76: /* original 62e2, guest PC 0x0c039d76 */
if(!s->budget--) { s->failed_pc=0x0c039d76u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c039d78;
P_0c039d78: /* original 430b, guest PC 0x0c039d78 */
if(!s->budget--) { s->failed_pc=0x0c039d78u; return 0; }
target=r[3];
r[16]=code_base|0x0c039d7cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039d7cu) { target=s->pc; goto dispatch; }
goto P_0c039d7c;
P_0c039d7a: /* original 2f26, guest PC 0x0c039d7a */
if(!s->budget--) { s->failed_pc=0x0c039d7au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039d7c;
P_0c039d7c: /* original 7f04, guest PC 0x0c039d7c */
if(!s->budget--) { s->failed_pc=0x0c039d7cu; return 0; }
r[15]+=0x00000004u;
goto P_0c039d7e;
P_0c039d7e: /* original 60f2, guest PC 0x0c039d7e */
if(!s->budget--) { s->failed_pc=0x0c039d7eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c039d80;
P_0c039d80: /* original 8801, guest PC 0x0c039d80 */
if(!s->budget--) { s->failed_pc=0x0c039d80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c039d82;
P_0c039d82: /* original 8b05, guest PC 0x0c039d82 */
if(!s->budget--) { s->failed_pc=0x0c039d82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c039d90; }
goto P_0c039d84;
P_0c039d84: /* original affe, guest PC 0x0c039d84 */
if(!s->budget--) { s->failed_pc=0x0c039d84u; return 0; }
goto P_0c039d84;
P_0c039d86: /* original 0009, guest PC 0x0c039d86 */
if(!s->budget--) { s->failed_pc=0x0c039d86u; return 0; }
if(!vf3_matrix_family(0x0c039d88u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039d88u; return 0; } return 1;
P_0c039d90: /* original c330, guest PC 0x0c039d90 */
if(!s->budget--) { s->failed_pc=0x0c039d90u; return 0; }
s->failed_pc=0x0c039d90u; return 0;
goto P_0c039d92;
P_0c039d92: /* original 7f08, guest PC 0x0c039d92 */
if(!s->budget--) { s->failed_pc=0x0c039d92u; return 0; }
r[15]+=0x00000008u;
goto P_0c039d94;
P_0c039d94: /* original 4f26, guest PC 0x0c039d94 */
if(!s->budget--) { s->failed_pc=0x0c039d94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c039d96;
P_0c039d96: /* original 000b, guest PC 0x0c039d96 */
if(!s->budget--) { s->failed_pc=0x0c039d96u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c039d98: /* original 6ef6, guest PC 0x0c039d98 */
if(!s->budget--) { s->failed_pc=0x0c039d98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c039d9au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039d9au; return 0; } return 1;
P_0c03aa9c: /* original 4f22, guest PC 0x0c03aa9c */
if(!s->budget--) { s->failed_pc=0x0c03aa9cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03aa9e;
P_0c03aa9e: /* original 2252, guest PC 0x0c03aa9e */
if(!s->budget--) { s->failed_pc=0x0c03aa9eu; return 0; }
write(ram,r[2],r[5],4);
goto P_0c03aaa0;
P_0c03aaa0: /* original d143, guest PC 0x0c03aaa0 */
if(!s->budget--) { s->failed_pc=0x0c03aaa0u; return 0; }
r[1]=read(ram,0x0c03abb0u,4);
goto P_0c03aaa2;
P_0c03aaa2: /* original 7ffc, guest PC 0x0c03aaa2 */
if(!s->budget--) { s->failed_pc=0x0c03aaa2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03aaa4;
P_0c03aaa4: /* original 2152, guest PC 0x0c03aaa4 */
if(!s->budget--) { s->failed_pc=0x0c03aaa4u; return 0; }
write(ram,r[1],r[5],4);
goto P_0c03aaa6;
P_0c03aaa6: /* original d043, guest PC 0x0c03aaa6 */
if(!s->budget--) { s->failed_pc=0x0c03aaa6u; return 0; }
r[0]=read(ram,0x0c03abb4u,4);
goto P_0c03aaa8;
P_0c03aaa8: /* original 2032, guest PC 0x0c03aaa8 */
if(!s->budget--) { s->failed_pc=0x0c03aaa8u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c03aaaa;
P_0c03aaaa: /* original c74a, guest PC 0x0c03aaaa */
if(!s->budget--) { s->failed_pc=0x0c03aaaau; return 0; }
r[0]=code_base|0x0003abd4u;
goto P_0c03aaac;
P_0c03aaac: /* original d342, guest PC 0x0c03aaac */
if(!s->budget--) { s->failed_pc=0x0c03aaacu; return 0; }
r[3]=read(ram,0x0c03abb8u,4);
goto P_0c03aaae;
P_0c03aaae: /* original 2341, guest PC 0x0c03aaae */
if(!s->budget--) { s->failed_pc=0x0c03aaaeu; return 0; }
write(ram,r[3],r[4],2);
goto P_0c03aab0;
P_0c03aab0: /* original d242, guest PC 0x0c03aab0 */
if(!s->budget--) { s->failed_pc=0x0c03aab0u; return 0; }
r[2]=read(ram,0x0c03abbcu,4);
goto P_0c03aab2;
P_0c03aab2: /* original 2242, guest PC 0x0c03aab2 */
if(!s->budget--) { s->failed_pc=0x0c03aab2u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c03aab4;
P_0c03aab4: /* original d142, guest PC 0x0c03aab4 */
if(!s->budget--) { s->failed_pc=0x0c03aab4u; return 0; }
r[1]=read(ram,0x0c03abc0u,4);
goto P_0c03aab6;
P_0c03aab6: /* original 2142, guest PC 0x0c03aab6 */
if(!s->budget--) { s->failed_pc=0x0c03aab6u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c03aab8;
P_0c03aab8: /* original d342, guest PC 0x0c03aab8 */
if(!s->budget--) { s->failed_pc=0x0c03aab8u; return 0; }
r[3]=read(ram,0x0c03abc4u,4);
goto P_0c03aaba;
P_0c03aaba: /* original 2352, guest PC 0x0c03aaba */
if(!s->budget--) { s->failed_pc=0x0c03aabau; return 0; }
write(ram,r[3],r[5],4);
goto P_0c03aabc;
P_0c03aabc: /* original d242, guest PC 0x0c03aabc */
if(!s->budget--) { s->failed_pc=0x0c03aabcu; return 0; }
r[2]=read(ram,0x0c03abc8u,4);
goto P_0c03aabe;
P_0c03aabe: /* original f38d, guest PC 0x0c03aabe */
if(!s->budget--) { s->failed_pc=0x0c03aabeu; return 0; }
fr[3]=0;
goto P_0c03aac0;
P_0c03aac0: /* original f23a, guest PC 0x0c03aac0 */
if(!s->budget--) { s->failed_pc=0x0c03aac0u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c03aac2;
P_0c03aac2: /* original d142, guest PC 0x0c03aac2 */
if(!s->budget--) { s->failed_pc=0x0c03aac2u; return 0; }
r[1]=read(ram,0x0c03abccu,4);
goto P_0c03aac4;
P_0c03aac4: /* original f39d, guest PC 0x0c03aac4 */
if(!s->budget--) { s->failed_pc=0x0c03aac4u; return 0; }
fr[3]=0x3f800000u;
goto P_0c03aac6;
P_0c03aac6: /* original f13a, guest PC 0x0c03aac6 */
if(!s->budget--) { s->failed_pc=0x0c03aac6u; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c03aac8;
P_0c03aac8: /* original f308, guest PC 0x0c03aac8 */
if(!s->budget--) { s->failed_pc=0x0c03aac8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03aaca;
P_0c03aaca: /* original d741, guest PC 0x0c03aaca */
if(!s->budget--) { s->failed_pc=0x0c03aacau; return 0; }
r[7]=read(ram,0x0c03abd0u,4);
goto P_0c03aacc;
P_0c03aacc: /* original f73a, guest PC 0x0c03aacc */
if(!s->budget--) { s->failed_pc=0x0c03aaccu; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c03aace;
P_0c03aace: /* original d142, guest PC 0x0c03aace */
if(!s->budget--) { s->failed_pc=0x0c03aaceu; return 0; }
r[1]=read(ram,0x0c03abd8u,4);
goto P_0c03aad0;
P_0c03aad0: /* original 9667, guest PC 0x0c03aad0 */
if(!s->budget--) { s->failed_pc=0x0c03aad0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03aba2u,2);
goto P_0c03aad2;
P_0c03aad2: /* original 6453, guest PC 0x0c03aad2 */
if(!s->budget--) { s->failed_pc=0x0c03aad2u; return 0; }
r[4]=r[5];
goto P_0c03aad4;
P_0c03aad4: /* original 445a, guest PC 0x0c03aad4 */
if(!s->budget--) { s->failed_pc=0x0c03aad4u; return 0; }
r[53]=r[4];
goto P_0c03aad6;
P_0c03aad6: /* original 6043, guest PC 0x0c03aad6 */
if(!s->budget--) { s->failed_pc=0x0c03aad6u; return 0; }
r[0]=r[4];
goto P_0c03aad8;
P_0c03aad8: /* original f278, guest PC 0x0c03aad8 */
if(!s->budget--) { s->failed_pc=0x0c03aad8u; return 0; }
vf3_matrix_load(s,ram,2,r[7]);
goto P_0c03aada;
P_0c03aada: /* original 4000, guest PC 0x0c03aada */
if(!s->budget--) { s->failed_pc=0x0c03aadau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03aadc;
P_0c03aadc: /* original 63f3, guest PC 0x0c03aadc */
if(!s->budget--) { s->failed_pc=0x0c03aadcu; return 0; }
r[3]=r[15];
goto P_0c03aade;
P_0c03aade: /* original 6203, guest PC 0x0c03aade */
if(!s->budget--) { s->failed_pc=0x0c03aadeu; return 0; }
r[2]=r[0];
goto P_0c03aae0;
P_0c03aae0: /* original f32d, guest PC 0x0c03aae0 */
if(!s->budget--) { s->failed_pc=0x0c03aae0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03aae2;
P_0c03aae2: /* original 7401, guest PC 0x0c03aae2 */
if(!s->budget--) { s->failed_pc=0x0c03aae2u; return 0; }
r[4]+=0x00000001u;
goto P_0c03aae4;
P_0c03aae4: /* original 3463, guest PC 0x0c03aae4 */
if(!s->budget--) { s->failed_pc=0x0c03aae4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c03aae6;
P_0c03aae6: /* original 321c, guest PC 0x0c03aae6 */
if(!s->budget--) { s->failed_pc=0x0c03aae6u; return 0; }
r[2]+=r[1];
goto P_0c03aae8;
P_0c03aae8: /* original f322, guest PC 0x0c03aae8 */
if(!s->budget--) { s->failed_pc=0x0c03aae8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03aaea;
P_0c03aaea: /* original ff3a, guest PC 0x0c03aaea */
if(!s->budget--) { s->failed_pc=0x0c03aaeau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c03aaec;
P_0c03aaec: /* original 8531, guest PC 0x0c03aaec */
if(!s->budget--) { s->failed_pc=0x0c03aaecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+2,2);
goto P_0c03aaee;
P_0c03aaee: /* original 8ff1, guest PC 0x0c03aaee */
if(!s->budget--) { s->failed_pc=0x0c03aaeeu; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[0],2);
if(!cond) { goto P_0c03aad4; }
goto P_0c03aaf2;
P_0c03aaf0: /* original 2201, guest PC 0x0c03aaf0 */
if(!s->budget--) { s->failed_pc=0x0c03aaf0u; return 0; }
write(ram,r[2],r[0],2);
goto P_0c03aaf2;
P_0c03aaf2: /* original d43a, guest PC 0x0c03aaf2 */
if(!s->budget--) { s->failed_pc=0x0c03aaf2u; return 0; }
r[4]=read(ram,0x0c03abdcu,4);
goto P_0c03aaf4;
P_0c03aaf4: /* original d23a, guest PC 0x0c03aaf4 */
if(!s->budget--) { s->failed_pc=0x0c03aaf4u; return 0; }
r[2]=read(ram,0x0c03abe0u,4);
goto P_0c03aaf6;
P_0c03aaf6: /* original 9755, guest PC 0x0c03aaf6 */
if(!s->budget--) { s->failed_pc=0x0c03aaf6u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03aba4u,2);
goto P_0c03aaf8;
P_0c03aaf8: /* original 9655, guest PC 0x0c03aaf8 */
if(!s->budget--) { s->failed_pc=0x0c03aaf8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03aba6u,2);
goto P_0c03aafa;
P_0c03aafa: /* original 420b, guest PC 0x0c03aafa */
if(!s->budget--) { s->failed_pc=0x0c03aafau; return 0; }
target=r[2];
r[16]=code_base|0x0c03aafeu;
r[5]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03aafeu) { target=s->pc; goto dispatch; }
goto P_0c03aafe;
P_0c03aafc: /* original e508, guest PC 0x0c03aafc */
if(!s->budget--) { s->failed_pc=0x0c03aafcu; return 0; }
r[5]=0x00000008u;
goto P_0c03aafe;
P_0c03aafe: /* original d437, guest PC 0x0c03aafe */
if(!s->budget--) { s->failed_pc=0x0c03aafeu; return 0; }
r[4]=read(ram,0x0c03abdcu,4);
goto P_0c03ab00;
P_0c03ab00: /* original e700, guest PC 0x0c03ab00 */
if(!s->budget--) { s->failed_pc=0x0c03ab00u; return 0; }
r[7]=0x00000000u;
goto P_0c03ab02;
P_0c03ab02: /* original d339, guest PC 0x0c03ab02 */
if(!s->budget--) { s->failed_pc=0x0c03ab02u; return 0; }
r[3]=read(ram,0x0c03abe8u,4);
goto P_0c03ab04;
P_0c03ab04: /* original d537, guest PC 0x0c03ab04 */
if(!s->budget--) { s->failed_pc=0x0c03ab04u; return 0; }
r[5]=read(ram,0x0c03abe4u,4);
goto P_0c03ab06;
P_0c03ab06: /* original 430b, guest PC 0x0c03ab06 */
if(!s->budget--) { s->failed_pc=0x0c03ab06u; return 0; }
target=r[3];
r[16]=code_base|0x0c03ab0au;
r[6]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ab0au) { target=s->pc; goto dispatch; }
goto P_0c03ab0a;
P_0c03ab08: /* original 6673, guest PC 0x0c03ab08 */
if(!s->budget--) { s->failed_pc=0x0c03ab08u; return 0; }
r[6]=r[7];
goto P_0c03ab0a;
P_0c03ab0a: /* original b081, guest PC 0x0c03ab0a */
if(!s->budget--) { s->failed_pc=0x0c03ab0au; return 0; }
target=code_base|0x0c03ac10u; r[16]=code_base|0x0c03ab0eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ab0eu) { target=s->pc; goto dispatch; }
goto P_0c03ab0e;
P_0c03ab0c: /* original 0009, guest PC 0x0c03ab0c */
if(!s->budget--) { s->failed_pc=0x0c03ab0cu; return 0; }
goto P_0c03ab0e;
P_0c03ab0e: /* original 7f04, guest PC 0x0c03ab0e */
if(!s->budget--) { s->failed_pc=0x0c03ab0eu; return 0; }
r[15]+=0x00000004u;
goto P_0c03ab10;
P_0c03ab10: /* original 4f26, guest PC 0x0c03ab10 */
if(!s->budget--) { s->failed_pc=0x0c03ab10u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ab12;
P_0c03ab12: /* original 000b, guest PC 0x0c03ab12 */
if(!s->budget--) { s->failed_pc=0x0c03ab12u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03ab14: /* original 0009, guest PC 0x0c03ab14 */
if(!s->budget--) { s->failed_pc=0x0c03ab14u; return 0; }
if(!vf3_matrix_family(0x0c03ab16u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ab16u; return 0; } return 1;
P_0c0432e2: /* original 4f22, guest PC 0x0c0432e2 */
if(!s->budget--) { s->failed_pc=0x0c0432e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0432e4;
P_0c0432e4: /* original d316, guest PC 0x0c0432e4 */
if(!s->budget--) { s->failed_pc=0x0c0432e4u; return 0; }
r[3]=read(ram,0x0c043340u,4);
goto P_0c0432e6;
P_0c0432e6: /* original 7ff0, guest PC 0x0c0432e6 */
if(!s->budget--) { s->failed_pc=0x0c0432e6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0432e8;
P_0c0432e8: /* original 430b, guest PC 0x0c0432e8 */
if(!s->budget--) { s->failed_pc=0x0c0432e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0432ecu;
r[5]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0432ecu) { target=s->pc; goto dispatch; }
goto P_0c0432ec;
P_0c0432ea: /* original 65f3, guest PC 0x0c0432ea */
if(!s->budget--) { s->failed_pc=0x0c0432eau; return 0; }
r[5]=r[15];
goto P_0c0432ec;
P_0c0432ec: /* original 6403, guest PC 0x0c0432ec */
if(!s->budget--) { s->failed_pc=0x0c0432ecu; return 0; }
r[4]=r[0];
goto P_0c0432ee;
P_0c0432ee: /* original 6043, guest PC 0x0c0432ee */
if(!s->budget--) { s->failed_pc=0x0c0432eeu; return 0; }
r[0]=r[4];
goto P_0c0432f0;
P_0c0432f0: /* original 55f2, guest PC 0x0c0432f0 */
if(!s->budget--) { s->failed_pc=0x0c0432f0u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0432f2;
P_0c0432f2: /* original 88ff, guest PC 0x0c0432f2 */
if(!s->budget--) { s->failed_pc=0x0c0432f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0432f4;
P_0c0432f4: /* original 8d26, guest PC 0x0c0432f4 */
if(!s->budget--) { s->failed_pc=0x0c0432f4u; return 0; }
cond=r[17]&1u;
r[6]=0x00000004u;
if(cond) { goto P_0c043344; }
goto P_0c0432f8;
P_0c0432f6: /* original e604, guest PC 0x0c0432f6 */
if(!s->budget--) { s->failed_pc=0x0c0432f6u; return 0; }
r[6]=0x00000004u;
goto P_0c0432f8;
P_0c0432f8: /* original 8800, guest PC 0x0c0432f8 */
if(!s->budget--) { s->failed_pc=0x0c0432f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0432fa;
P_0c0432fa: /* original 8909, guest PC 0x0c0432fa */
if(!s->budget--) { s->failed_pc=0x0c0432fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043310; }
goto P_0c0432fc;
P_0c0432fc: /* original 8801, guest PC 0x0c0432fc */
if(!s->budget--) { s->failed_pc=0x0c0432fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0432fe;
P_0c0432fe: /* original 8909, guest PC 0x0c0432fe */
if(!s->budget--) { s->failed_pc=0x0c0432feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043314; }
goto P_0c043300;
P_0c043300: /* original 8802, guest PC 0x0c043300 */
if(!s->budget--) { s->failed_pc=0x0c043300u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c043302;
P_0c043302: /* original 8909, guest PC 0x0c043302 */
if(!s->budget--) { s->failed_pc=0x0c043302u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043318; }
goto P_0c043304;
P_0c043304: /* original 8803, guest PC 0x0c043304 */
if(!s->budget--) { s->failed_pc=0x0c043304u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c043306;
P_0c043306: /* original 890a, guest PC 0x0c043306 */
if(!s->budget--) { s->failed_pc=0x0c043306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04331e; }
goto P_0c043308;
P_0c043308: /* original 8804, guest PC 0x0c043308 */
if(!s->budget--) { s->failed_pc=0x0c043308u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c04330a;
P_0c04330a: /* original 890a, guest PC 0x0c04330a */
if(!s->budget--) { s->failed_pc=0x0c04330au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043322; }
goto P_0c04330c;
P_0c04330c: /* original a051, guest PC 0x0c04330c */
if(!s->budget--) { s->failed_pc=0x0c04330cu; return 0; }
goto P_0c0433b2;
P_0c04330e: /* original 0009, guest PC 0x0c04330e */
if(!s->budget--) { s->failed_pc=0x0c04330eu; return 0; }
goto P_0c043310;
P_0c043310: /* original a04f, guest PC 0x0c043310 */
if(!s->budget--) { s->failed_pc=0x0c043310u; return 0; }
r[4]=0x00000000u;
goto P_0c0433b2;
P_0c043312: /* original e400, guest PC 0x0c043312 */
if(!s->budget--) { s->failed_pc=0x0c043312u; return 0; }
r[4]=0x00000000u;
goto P_0c043314;
P_0c043314: /* original a001, guest PC 0x0c043314 */
if(!s->budget--) { s->failed_pc=0x0c043314u; return 0; }
r[4]=r[6];
goto P_0c04331a;
P_0c043316: /* original 6463, guest PC 0x0c043316 */
if(!s->budget--) { s->failed_pc=0x0c043316u; return 0; }
r[4]=r[6];
goto P_0c043318;
P_0c043318: /* original e401, guest PC 0x0c043318 */
if(!s->budget--) { s->failed_pc=0x0c043318u; return 0; }
r[4]=0x00000001u;
goto P_0c04331a;
P_0c04331a: /* original a04a, guest PC 0x0c04331a */
if(!s->budget--) { s->failed_pc=0x0c04331au; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0433b2;
P_0c04331c: /* original 2e52, guest PC 0x0c04331c */
if(!s->budget--) { s->failed_pc=0x0c04331cu; return 0; }
write(ram,r[14],r[5],4);
goto P_0c04331e;
P_0c04331e: /* original a048, guest PC 0x0c04331e */
if(!s->budget--) { s->failed_pc=0x0c04331eu; return 0; }
r[4]=0x00000007u;
goto P_0c0433b2;
P_0c043320: /* original e407, guest PC 0x0c043320 */
if(!s->budget--) { s->failed_pc=0x0c043320u; return 0; }
r[4]=0x00000007u;
goto P_0c043322;
P_0c043322: /* original a046, guest PC 0x0c043322 */
if(!s->budget--) { s->failed_pc=0x0c043322u; return 0; }
r[4]=r[6];
goto P_0c0433b2;
P_0c043324: /* original 6463, guest PC 0x0c043324 */
if(!s->budget--) { s->failed_pc=0x0c043324u; return 0; }
r[4]=r[6];
if(!vf3_matrix_family(0x0c043326u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043326u; return 0; } return 1;
P_0c043344: /* original 52f1, guest PC 0x0c043344 */
if(!s->budget--) { s->failed_pc=0x0c043344u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c043346;
P_0c043346: /* original e405, guest PC 0x0c043346 */
if(!s->budget--) { s->failed_pc=0x0c043346u; return 0; }
r[4]=0x00000005u;
goto P_0c043348;
P_0c043348: /* original 1e21, guest PC 0x0c043348 */
if(!s->budget--) { s->failed_pc=0x0c043348u; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c04334a;
P_0c04334a: /* original 60f2, guest PC 0x0c04334a */
if(!s->budget--) { s->failed_pc=0x0c04334au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04334c;
P_0c04334c: /* original e111, guest PC 0x0c04334c */
if(!s->budget--) { s->failed_pc=0x0c04334cu; return 0; }
r[1]=0x00000011u;
goto P_0c04334e;
P_0c04334e: /* original 3012, guest PC 0x0c04334e */
if(!s->budget--) { s->failed_pc=0x0c04334eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c043350;
P_0c043350: /* original 892d, guest PC 0x0c043350 */
if(!s->budget--) { s->failed_pc=0x0c043350u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0433ae; }
goto P_0c043352;
P_0c043352: /* original 4000, guest PC 0x0c043352 */
if(!s->budget--) { s->failed_pc=0x0c043352u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043354;
P_0c043354: /* original 6103, guest PC 0x0c043354 */
if(!s->budget--) { s->failed_pc=0x0c043354u; return 0; }
r[1]=r[0];
goto P_0c043356;
P_0c043356: /* original c702, guest PC 0x0c043356 */
if(!s->budget--) { s->failed_pc=0x0c043356u; return 0; }
r[0]=code_base|0x00043360u;
goto P_0c043358;
P_0c043358: /* original 001d, guest PC 0x0c043358 */
if(!s->budget--) { s->failed_pc=0x0c043358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c04335a;
P_0c04335a: /* original 0023, guest PC 0x0c04335a */
if(!s->budget--) { s->failed_pc=0x0c04335au; return 0; }
target=r[0]+0x0c04335eu;
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
P_0c04335c: /* original 0009, guest PC 0x0c04335c */
if(!s->budget--) { s->failed_pc=0x0c04335cu; return 0; }
if(!vf3_matrix_family(0x0c04335eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04335eu; return 0; } return 1;
P_0c0433ae: /* original e2e6, guest PC 0x0c0433ae */
if(!s->budget--) { s->failed_pc=0x0c0433aeu; return 0; }
r[2]=0xffffffe6u;
goto P_0c0433b0;
P_0c0433b0: /* original 2e22, guest PC 0x0c0433b0 */
if(!s->budget--) { s->failed_pc=0x0c0433b0u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0433b2;
P_0c0433b2: /* original 7f10, guest PC 0x0c0433b2 */
if(!s->budget--) { s->failed_pc=0x0c0433b2u; return 0; }
r[15]+=0x00000010u;
goto P_0c0433b4;
P_0c0433b4: /* original 6043, guest PC 0x0c0433b4 */
if(!s->budget--) { s->failed_pc=0x0c0433b4u; return 0; }
r[0]=r[4];
goto P_0c0433b6;
P_0c0433b6: /* original 4f26, guest PC 0x0c0433b6 */
if(!s->budget--) { s->failed_pc=0x0c0433b6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0433b8;
P_0c0433b8: /* original 000b, guest PC 0x0c0433b8 */
if(!s->budget--) { s->failed_pc=0x0c0433b8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0433ba: /* original 6ef6, guest PC 0x0c0433ba */
if(!s->budget--) { s->failed_pc=0x0c0433bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0433bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0433bcu; return 0; } return 1;
P_0c047810: /* original 63f3, guest PC 0x0c047810 */
if(!s->budget--) { s->failed_pc=0x0c047810u; return 0; }
r[3]=r[15];
goto P_0c047812;
P_0c047812: /* original fb39, guest PC 0x0c047812 */
if(!s->budget--) { s->failed_pc=0x0c047812u; return 0; }
vf3_matrix_load(s,ram,11,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c047814;
P_0c047814: /* original f79d, guest PC 0x0c047814 */
if(!s->budget--) { s->failed_pc=0x0c047814u; return 0; }
fr[7]=0x3f800000u;
goto P_0c047816;
P_0c047816: /* original f7b5, guest PC 0x0c047816 */
if(!s->budget--) { s->failed_pc=0x0c047816u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[11]))!=0);
goto P_0c047818;
P_0c047818: /* original 6043, guest PC 0x0c047818 */
if(!s->budget--) { s->failed_pc=0x0c047818u; return 0; }
r[0]=r[4];
goto P_0c04781a;
P_0c04781a: /* original 7030, guest PC 0x0c04781a */
if(!s->budget--) { s->failed_pc=0x0c04781au; return 0; }
r[0]+=0x00000030u;
goto P_0c04781c;
P_0c04781c: /* original 8f15, guest PC 0x0c04781c */
if(!s->budget--) { s->failed_pc=0x0c04781cu; return 0; }
cond=r[17]&1u;
if((r[0]&0xFC000000u)==0xE0000000u) pref(ram,r[0]);
if(!cond) { goto P_0c04784a; }
goto P_0c047820;
P_0c04781e: /* original 0083, guest PC 0x0c04781e */
if(!s->budget--) { s->failed_pc=0x0c04781eu; return 0; }
if((r[0]&0xFC000000u)==0xE0000000u) pref(ram,r[0]);
goto P_0c047820;
P_0c047820: /* original e202, guest PC 0x0c047820 */
if(!s->budget--) { s->failed_pc=0x0c047820u; return 0; }
r[2]=0x00000002u;
goto P_0c047822;
P_0c047822: /* original f21d, guest PC 0x0c047822 */
if(!s->budget--) { s->failed_pc=0x0c047822u; return 0; }
r[53]=fr[2];
goto P_0c047824;
P_0c047824: /* original 4228, guest PC 0x0c047824 */
if(!s->budget--) { s->failed_pc=0x0c047824u; return 0; }
r[2]<<=16;
goto P_0c047826;
P_0c047826: /* original 005a, guest PC 0x0c047826 */
if(!s->budget--) { s->failed_pc=0x0c047826u; return 0; }
r[0]=r[53];
goto P_0c047828;
P_0c047828: /* original 4218, guest PC 0x0c047828 */
if(!s->budget--) { s->failed_pc=0x0c047828u; return 0; }
r[2]<<=8;
goto P_0c04782a;
P_0c04782a: /* original d9b5, guest PC 0x0c04782a */
if(!s->budget--) { s->failed_pc=0x0c04782au; return 0; }
r[9]=read(ram,0x0c047b00u,4);
goto P_0c04782c;
P_0c04782c: /* original 282b, guest PC 0x0c04782c */
if(!s->budget--) { s->failed_pc=0x0c04782cu; return 0; }
r[8]|=r[2];
goto P_0c04782e;
P_0c04782e: /* original cbc0, guest PC 0x0c04782e */
if(!s->budget--) { s->failed_pc=0x0c04782eu; return 0; }
r[0]|=192u;
goto P_0c047830;
P_0c047830: /* original 6009, guest PC 0x0c047830 */
if(!s->budget--) { s->failed_pc=0x0c047830u; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c047832;
P_0c047832: /* original 6992, guest PC 0x0c047832 */
if(!s->budget--) { s->failed_pc=0x0c047832u; return 0; }
tmp=read(ram,r[9],4);
r[9]=tmp;
goto P_0c047834;
P_0c047834: /* original cb10, guest PC 0x0c047834 */
if(!s->budget--) { s->failed_pc=0x0c047834u; return 0; }
r[0]|=16u;
goto P_0c047836;
P_0c047836: /* original 6008, guest PC 0x0c047836 */
if(!s->budget--) { s->failed_pc=0x0c047836u; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c047838;
P_0c047838: /* original cbfc, guest PC 0x0c047838 */
if(!s->budget--) { s->failed_pc=0x0c047838u; return 0; }
r[0]|=252u;
goto P_0c04783a;
P_0c04783a: /* original 209a, guest PC 0x0c04783a */
if(!s->budget--) { s->failed_pc=0x0c04783au; return 0; }
r[0]^=r[9];
goto P_0c04783c;
P_0c04783c: /* original 6008, guest PC 0x0c04783c */
if(!s->budget--) { s->failed_pc=0x0c04783cu; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c04783e;
P_0c04783e: /* original 6009, guest PC 0x0c04783e */
if(!s->budget--) { s->failed_pc=0x0c04783eu; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c047840;
P_0c047840: /* original 322c, guest PC 0x0c047840 */
if(!s->budget--) { s->failed_pc=0x0c047840u; return 0; }
r[2]+=r[2];
goto P_0c047842;
P_0c047842: /* original 405a, guest PC 0x0c047842 */
if(!s->budget--) { s->failed_pc=0x0c047842u; return 0; }
r[53]=r[0];
goto P_0c047844;
P_0c047844: /* original 6227, guest PC 0x0c047844 */
if(!s->budget--) { s->failed_pc=0x0c047844u; return 0; }
r[2]=~r[2];
goto P_0c047846;
P_0c047846: /* original f20d, guest PC 0x0c047846 */
if(!s->budget--) { s->failed_pc=0x0c047846u; return 0; }
fr[2]=r[53];
goto P_0c047848;
P_0c047848: /* original 2829, guest PC 0x0c047848 */
if(!s->budget--) { s->failed_pc=0x0c047848u; return 0; }
r[8]&=r[2];
goto P_0c04784a;
P_0c04784a: /* original 6083, guest PC 0x0c04784a */
if(!s->budget--) { s->failed_pc=0x0c04784au; return 0; }
r[0]=r[8];
goto P_0c04784c;
P_0c04784c: /* original f449, guest PC 0x0c04784c */
if(!s->budget--) { s->failed_pc=0x0c04784cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04784e;
P_0c04784e: /* original 4029, guest PC 0x0c04784e */
if(!s->budget--) { s->failed_pc=0x0c04784eu; return 0; }
r[0]>>=16;
goto P_0c047850;
P_0c047850: /* original f549, guest PC 0x0c047850 */
if(!s->budget--) { s->failed_pc=0x0c047850u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047852;
P_0c047852: /* original 4019, guest PC 0x0c047852 */
if(!s->budget--) { s->failed_pc=0x0c047852u; return 0; }
r[0]>>=8;
goto P_0c047854;
P_0c047854: /* original f649, guest PC 0x0c047854 */
if(!s->budget--) { s->failed_pc=0x0c047854u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047856;
P_0c047856: /* original c907, guest PC 0x0c047856 */
if(!s->budget--) { s->failed_pc=0x0c047856u; return 0; }
r[0]&=7u;
goto P_0c047858;
P_0c047858: /* original e204, guest PC 0x0c047858 */
if(!s->budget--) { s->failed_pc=0x0c047858u; return 0; }
r[2]=0x00000004u;
goto P_0c04785a;
P_0c04785a: /* original 4008, guest PC 0x0c04785a */
if(!s->budget--) { s->failed_pc=0x0c04785au; return 0; }
r[0]<<=2;
goto P_0c04785c;
P_0c04785c: /* original f5fd, guest PC 0x0c04785c */
if(!s->budget--) { s->failed_pc=0x0c04785cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c04785e;
P_0c04785e: /* original f139, guest PC 0x0c04785e */
if(!s->budget--) { s->failed_pc=0x0c04785eu; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c047860;
P_0c047860: /* original 4218, guest PC 0x0c047860 */
if(!s->budget--) { s->failed_pc=0x0c047860u; return 0; }
r[2]<<=8;
goto P_0c047862;
P_0c047862: /* original f049, guest PC 0x0c047862 */
if(!s->budget--) { s->failed_pc=0x0c047862u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047864;
P_0c047864: /* original 3b00, guest PC 0x0c047864 */
if(!s->budget--) { s->failed_pc=0x0c047864u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[0])!=0);
goto P_0c047866;
P_0c047866: /* original 6b03, guest PC 0x0c047866 */
if(!s->budget--) { s->failed_pc=0x0c047866u; return 0; }
r[11]=r[0];
goto P_0c047868;
P_0c047868: /* original e6e0, guest PC 0x0c047868 */
if(!s->budget--) { s->failed_pc=0x0c047868u; return 0; }
r[6]=0xffffffe0u;
goto P_0c04786a;
P_0c04786a: /* original f012, guest PC 0x0c04786a */
if(!s->budget--) { s->failed_pc=0x0c04786au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c04786c;
P_0c04786c: /* original 4228, guest PC 0x0c04786c */
if(!s->budget--) { s->failed_pc=0x0c04786cu; return 0; }
r[2]<<=16;
goto P_0c04786e;
P_0c04786e: /* original 8d09, guest PC 0x0c04786e */
if(!s->budget--) { s->failed_pc=0x0c04786eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c047884; }
goto P_0c047872;
P_0c047870: /* original 05ae, guest PC 0x0c047870 */
if(!s->budget--) { s->failed_pc=0x0c047870u; return 0; }
r[5]=read(ram,r[10]+r[0],4);
goto P_0c047872;
P_0c047872: /* original e0ff, guest PC 0x0c047872 */
if(!s->budget--) { s->failed_pc=0x0c047872u; return 0; }
r[0]=0xffffffffu;
goto P_0c047874;
P_0c047874: /* original 4028, guest PC 0x0c047874 */
if(!s->budget--) { s->failed_pc=0x0c047874u; return 0; }
r[0]<<=16;
goto P_0c047876;
P_0c047876: /* original 4018, guest PC 0x0c047876 */
if(!s->budget--) { s->failed_pc=0x0c047876u; return 0; }
r[0]<<=8;
goto P_0c047878;
P_0c047878: /* original cb38, guest PC 0x0c047878 */
if(!s->budget--) { s->failed_pc=0x0c047878u; return 0; }
r[0]|=56u;
goto P_0c04787a;
P_0c04787a: /* original 6953, guest PC 0x0c04787a */
if(!s->budget--) { s->failed_pc=0x0c04787au; return 0; }
r[9]=r[5];
goto P_0c04787c;
P_0c04787c: /* original 4929, guest PC 0x0c04787c */
if(!s->budget--) { s->failed_pc=0x0c04787cu; return 0; }
r[9]>>=16;
goto P_0c04787e;
P_0c04787e: /* original 4919, guest PC 0x0c04787e */
if(!s->budget--) { s->failed_pc=0x0c04787eu; return 0; }
r[9]>>=8;
goto P_0c047880;
P_0c047880: /* original 2092, guest PC 0x0c047880 */
if(!s->budget--) { s->failed_pc=0x0c047880u; return 0; }
write(ram,r[0],r[9],4);
goto P_0c047882;
P_0c047882: /* original 1091, guest PC 0x0c047882 */
if(!s->budget--) { s->failed_pc=0x0c047882u; return 0; }
write(ram,r[0]+4,r[9],4);
goto P_0c047884;
P_0c047884: /* original 72ff, guest PC 0x0c047884 */
if(!s->budget--) { s->failed_pc=0x0c047884u; return 0; }
r[2]+=0xffffffffu;
goto P_0c047886;
P_0c047886: /* original 4c5a, guest PC 0x0c047886 */
if(!s->budget--) { s->failed_pc=0x0c047886u; return 0; }
r[53]=r[12];
goto P_0c047888;
P_0c047888: /* original e0fe, guest PC 0x0c047888 */
if(!s->budget--) { s->failed_pc=0x0c047888u; return 0; }
r[0]=0xfffffffeu;
goto P_0c04788a;
P_0c04788a: /* original f700, guest PC 0x0c04788a */
if(!s->budget--) { s->failed_pc=0x0c04788au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'+');
goto P_0c04788c;
P_0c04788c: /* original 2259, guest PC 0x0c04788c */
if(!s->budget--) { s->failed_pc=0x0c04788cu; return 0; }
r[2]&=r[5];
goto P_0c04788e;
P_0c04788e: /* original f10d, guest PC 0x0c04788e */
if(!s->budget--) { s->failed_pc=0x0c04788eu; return 0; }
fr[1]=r[53];
goto P_0c047890;
P_0c047890: /* original 4618, guest PC 0x0c047890 */
if(!s->budget--) { s->failed_pc=0x0c047890u; return 0; }
r[6]<<=8;
goto P_0c047892;
P_0c047892: /* original f715, guest PC 0x0c047892 */
if(!s->budget--) { s->failed_pc=0x0c047892u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c047894;
P_0c047894: /* original 4628, guest PC 0x0c047894 */
if(!s->budget--) { s->failed_pc=0x0c047894u; return 0; }
r[6]<<=16;
goto P_0c047896;
P_0c047896: /* original 262b, guest PC 0x0c047896 */
if(!s->budget--) { s->failed_pc=0x0c047896u; return 0; }
r[6]|=r[2];
goto P_0c047898;
P_0c047898: /* original f701, guest PC 0x0c047898 */
if(!s->budget--) { s->failed_pc=0x0c047898u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c04789a;
P_0c04789a: /* original 2c09, guest PC 0x0c04789a */
if(!s->budget--) { s->failed_pc=0x0c04789au; return 0; }
r[12]&=r[0];
goto P_0c04789c;
P_0c04789c: /* original 59f9, guest PC 0x0c04789c */
if(!s->budget--) { s->failed_pc=0x0c04789cu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c04789e;
P_0c04789e: /* original 8f43, guest PC 0x0c04789e */
if(!s->budget--) { s->failed_pc=0x0c04789eu; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
if(!cond) { goto P_0c047928; }
goto P_0c0478a2;
P_0c0478a0: /* original f701, guest PC 0x0c0478a0 */
if(!s->budget--) { s->failed_pc=0x0c0478a0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c0478a2;
P_0c0478a2: /* original f715, guest PC 0x0c0478a2 */
if(!s->budget--) { s->failed_pc=0x0c0478a2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c0478a4;
P_0c0478a4: /* original 8f40, guest PC 0x0c0478a4 */
if(!s->budget--) { s->failed_pc=0x0c0478a4u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c047928; }
goto P_0c0478a8;
P_0c0478a6: /* original 7c01, guest PC 0x0c0478a6 */
if(!s->budget--) { s->failed_pc=0x0c0478a6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0478a8;
P_0c0478a8: /* original 6243, guest PC 0x0c0478a8 */
if(!s->budget--) { s->failed_pc=0x0c0478a8u; return 0; }
r[2]=r[4];
goto P_0c0478aa;
P_0c0478aa: /* original 742c, guest PC 0x0c0478aa */
if(!s->budget--) { s->failed_pc=0x0c0478aau; return 0; }
r[4]+=0x0000002cu;
goto P_0c0478ac;
P_0c0478ac: /* original 6046, guest PC 0x0c0478ac */
if(!s->budget--) { s->failed_pc=0x0c0478acu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0478ae;
P_0c0478ae: /* original 2682, guest PC 0x0c0478ae */
if(!s->budget--) { s->failed_pc=0x0c0478aeu; return 0; }
write(ram,r[6],r[8],4);
goto P_0c0478b0;
P_0c0478b0: /* original 6183, guest PC 0x0c0478b0 */
if(!s->budget--) { s->failed_pc=0x0c0478b0u; return 0; }
r[1]=r[8];
goto P_0c0478b2;
P_0c0478b2: /* original 340c, guest PC 0x0c0478b2 */
if(!s->budget--) { s->failed_pc=0x0c0478b2u; return 0; }
r[4]+=r[0];
goto P_0c0478b4;
P_0c0478b4: /* original 6846, guest PC 0x0c0478b4 */
if(!s->budget--) { s->failed_pc=0x0c0478b4u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[8]=tmp;
goto P_0c0478b6;
P_0c0478b6: /* original 2888, guest PC 0x0c0478b6 */
if(!s->budget--) { s->failed_pc=0x0c0478b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0478b8;
P_0c0478b8: /* original 8b02, guest PC 0x0c0478b8 */
if(!s->budget--) { s->failed_pc=0x0c0478b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0478c0; }
goto P_0c0478ba;
P_0c0478ba: /* original a0eb, guest PC 0x0c0478ba */
if(!s->budget--) { s->failed_pc=0x0c0478bau; return 0; }
goto P_0c047a94;
P_0c0478bc: /* original 0009, guest PC 0x0c0478bc */
if(!s->budget--) { s->failed_pc=0x0c0478bcu; return 0; }
if(!vf3_matrix_family(0x0c0478beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0478beu; return 0; } return 1;
P_0c0478c0: /* original 69f3, guest PC 0x0c0478c0 */
if(!s->budget--) { s->failed_pc=0x0c0478c0u; return 0; }
r[9]=r[15];
goto P_0c0478c2;
P_0c0478c2: /* original 7918, guest PC 0x0c0478c2 */
if(!s->budget--) { s->failed_pc=0x0c0478c2u; return 0; }
r[9]+=0x00000018u;
goto P_0c0478c4;
P_0c0478c4: /* original f599, guest PC 0x0c0478c4 */
if(!s->budget--) { s->failed_pc=0x0c0478c4u; return 0; }
vf3_matrix_load(s,ram,5,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0478c6;
P_0c0478c6: /* original f699, guest PC 0x0c0478c6 */
if(!s->budget--) { s->failed_pc=0x0c0478c6u; return 0; }
vf3_matrix_load(s,ram,6,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0478c8;
P_0c0478c8: /* original 7208, guest PC 0x0c0478c8 */
if(!s->budget--) { s->failed_pc=0x0c0478c8u; return 0; }
r[2]+=0x00000008u;
goto P_0c0478ca;
P_0c0478ca: /* original f799, guest PC 0x0c0478ca */
if(!s->budget--) { s->failed_pc=0x0c0478cau; return 0; }
vf3_matrix_load(s,ram,7,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0478cc;
P_0c0478cc: /* original 6026, guest PC 0x0c0478cc */
if(!s->budget--) { s->failed_pc=0x0c0478ccu; return 0; }
tmp=read(ram,r[2],4);
r[2]+=4;
r[0]=tmp;
goto P_0c0478ce;
P_0c0478ce: /* original c801, guest PC 0x0c0478ce */
if(!s->budget--) { s->failed_pc=0x0c0478ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0478d0;
P_0c0478d0: /* original 6013, guest PC 0x0c0478d0 */
if(!s->budget--) { s->failed_pc=0x0c0478d0u; return 0; }
r[0]=r[1];
goto P_0c0478d2;
P_0c0478d2: /* original 8f24, guest PC 0x0c0478d2 */
if(!s->budget--) { s->failed_pc=0x0c0478d2u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!cond) { goto P_0c04791e; }
goto P_0c0478d6;
P_0c0478d4: /* original c820, guest PC 0x0c0478d4 */
if(!s->budget--) { s->failed_pc=0x0c0478d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0478d6;
P_0c0478d6: /* original 8922, guest PC 0x0c0478d6 */
if(!s->budget--) { s->failed_pc=0x0c0478d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04791e; }
goto P_0c0478d8;
P_0c0478d8: /* original f029, guest PC 0x0c0478d8 */
if(!s->budget--) { s->failed_pc=0x0c0478d8u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0478da;
P_0c0478da: /* original f129, guest PC 0x0c0478da */
if(!s->budget--) { s->failed_pc=0x0c0478dau; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0478dc;
P_0c0478dc: /* original f229, guest PC 0x0c0478dc */
if(!s->budget--) { s->failed_pc=0x0c0478dcu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0478de;
P_0c0478de: /* original f329, guest PC 0x0c0478de */
if(!s->budget--) { s->failed_pc=0x0c0478deu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0478e0;
P_0c0478e0: /* original f0b2, guest PC 0x0c0478e0 */
if(!s->budget--) { s->failed_pc=0x0c0478e0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c0478e2;
P_0c0478e2: /* original fb5c, guest PC 0x0c0478e2 */
if(!s->budget--) { s->failed_pc=0x0c0478e2u; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c0478e4;
P_0c0478e4: /* original f152, guest PC 0x0c0478e4 */
if(!s->budget--) { s->failed_pc=0x0c0478e4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c0478e6;
P_0c0478e6: /* original f429, guest PC 0x0c0478e6 */
if(!s->budget--) { s->failed_pc=0x0c0478e6u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0478e8;
P_0c0478e8: /* original f529, guest PC 0x0c0478e8 */
if(!s->budget--) { s->failed_pc=0x0c0478e8u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0478ea;
P_0c0478ea: /* original f5b2, guest PC 0x0c0478ea */
if(!s->budget--) { s->failed_pc=0x0c0478eau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c0478ec;
P_0c0478ec: /* original fb6c, guest PC 0x0c0478ec */
if(!s->budget--) { s->failed_pc=0x0c0478ecu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c0478ee;
P_0c0478ee: /* original f262, guest PC 0x0c0478ee */
if(!s->budget--) { s->failed_pc=0x0c0478eeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0478f0;
P_0c0478f0: /* original f629, guest PC 0x0c0478f0 */
if(!s->budget--) { s->failed_pc=0x0c0478f0u; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0478f2;
P_0c0478f2: /* original f6b2, guest PC 0x0c0478f2 */
if(!s->budget--) { s->failed_pc=0x0c0478f2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c0478f4;
P_0c0478f4: /* original fb7c, guest PC 0x0c0478f4 */
if(!s->budget--) { s->failed_pc=0x0c0478f4u; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c0478f6;
P_0c0478f6: /* original f372, guest PC 0x0c0478f6 */
if(!s->budget--) { s->failed_pc=0x0c0478f6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0478f8;
P_0c0478f8: /* original f729, guest PC 0x0c0478f8 */
if(!s->budget--) { s->failed_pc=0x0c0478f8u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0478fa;
P_0c0478fa: /* original f3fd, guest PC 0x0c0478fa */
if(!s->budget--) { s->failed_pc=0x0c0478fau; return 0; }
r[18]^=0x100000u;
goto P_0c0478fc;
P_0c0478fc: /* original f7b2, guest PC 0x0c0478fc */
if(!s->budget--) { s->failed_pc=0x0c0478fcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c0478fe;
P_0c0478fe: /* original e000, guest PC 0x0c0478fe */
if(!s->budget--) { s->failed_pc=0x0c0478feu; return 0; }
r[0]=0x00000000u;
goto P_0c047900;
P_0c047900: /* original 1601, guest PC 0x0c047900 */
if(!s->budget--) { s->failed_pc=0x0c047900u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c047902;
P_0c047902: /* original 1602, guest PC 0x0c047902 */
if(!s->budget--) { s->failed_pc=0x0c047902u; return 0; }
write(ram,r[6]+8,r[0],4);
goto P_0c047904;
P_0c047904: /* original 1603, guest PC 0x0c047904 */
if(!s->budget--) { s->failed_pc=0x0c047904u; return 0; }
write(ram,r[6]+12,r[0],4);
goto P_0c047906;
P_0c047906: /* original 0683, guest PC 0x0c047906 */
if(!s->budget--) { s->failed_pc=0x0c047906u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c047908;
P_0c047908: /* original 7640, guest PC 0x0c047908 */
if(!s->budget--) { s->failed_pc=0x0c047908u; return 0; }
r[6]+=0x00000040u;
goto P_0c04790a;
P_0c04790a: /* original f66b, guest PC 0x0c04790a */
if(!s->budget--) { s->failed_pc=0x0c04790au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04790c;
P_0c04790c: /* original f64b, guest PC 0x0c04790c */
if(!s->budget--) { s->failed_pc=0x0c04790cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04790e;
P_0c04790e: /* original 60b3, guest PC 0x0c04790e */
if(!s->budget--) { s->failed_pc=0x0c04790eu; return 0; }
r[0]=r[11];
goto P_0c047910;
P_0c047910: /* original f62b, guest PC 0x0c047910 */
if(!s->budget--) { s->failed_pc=0x0c047910u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c047912;
P_0c047912: /* original 7540, guest PC 0x0c047912 */
if(!s->budget--) { s->failed_pc=0x0c047912u; return 0; }
r[5]+=0x00000040u;
goto P_0c047914;
P_0c047914: /* original f60b, guest PC 0x0c047914 */
if(!s->budget--) { s->failed_pc=0x0c047914u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c047916;
P_0c047916: /* original f3fd, guest PC 0x0c047916 */
if(!s->budget--) { s->failed_pc=0x0c047916u; return 0; }
r[18]^=0x100000u;
goto P_0c047918;
P_0c047918: /* original 0683, guest PC 0x0c047918 */
if(!s->budget--) { s->failed_pc=0x0c047918u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04791a;
P_0c04791a: /* original 7620, guest PC 0x0c04791a */
if(!s->budget--) { s->failed_pc=0x0c04791au; return 0; }
r[6]+=0x00000020u;
goto P_0c04791c;
P_0c04791c: /* original 0a56, guest PC 0x0c04791c */
if(!s->budget--) { s->failed_pc=0x0c04791cu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c04791e;
P_0c04791e: /* original 6146, guest PC 0x0c04791e */
if(!s->budget--) { s->failed_pc=0x0c04791eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c047920;
P_0c047920: /* original f249, guest PC 0x0c047920 */
if(!s->budget--) { s->failed_pc=0x0c047920u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047922;
P_0c047922: /* original af75, guest PC 0x0c047922 */
if(!s->budget--) { s->failed_pc=0x0c047922u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047810;
P_0c047924: /* original f349, guest PC 0x0c047924 */
if(!s->budget--) { s->failed_pc=0x0c047924u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c047926u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c047926u; return 0; } return 1;
P_0c047928: /* original f139, guest PC 0x0c047928 */
if(!s->budget--) { s->failed_pc=0x0c047928u; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04792a;
P_0c04792a: /* original 7910, guest PC 0x0c04792a */
if(!s->budget--) { s->failed_pc=0x0c04792au; return 0; }
r[9]+=0x00000010u;
goto P_0c04792c;
P_0c04792c: /* original f04d, guest PC 0x0c04792c */
if(!s->budget--) { s->failed_pc=0x0c04792cu; return 0; }
fr[0]^=0x80000000u;
goto P_0c04792e;
P_0c04792e: /* original f102, guest PC 0x0c04792e */
if(!s->budget--) { s->failed_pc=0x0c04792eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c047930;
P_0c047930: /* original f93b, guest PC 0x0c047930 */
if(!s->budget--) { s->failed_pc=0x0c047930u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c047932;
P_0c047932: /* original 6243, guest PC 0x0c047932 */
if(!s->budget--) { s->failed_pc=0x0c047932u; return 0; }
r[2]=r[4];
goto P_0c047934;
P_0c047934: /* original f339, guest PC 0x0c047934 */
if(!s->budget--) { s->failed_pc=0x0c047934u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c047936;
P_0c047936: /* original f515, guest PC 0x0c047936 */
if(!s->budget--) { s->failed_pc=0x0c047936u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[1]))!=0);
goto P_0c047938;
P_0c047938: /* original f92b, guest PC 0x0c047938 */
if(!s->budget--) { s->failed_pc=0x0c047938u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[9]);
goto P_0c04793a;
P_0c04793a: /* original f302, guest PC 0x0c04793a */
if(!s->budget--) { s->failed_pc=0x0c04793au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c04793c;
P_0c04793c: /* original f039, guest PC 0x0c04793c */
if(!s->budget--) { s->failed_pc=0x0c04793cu; return 0; }
vf3_matrix_load(s,ram,0,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04793e;
P_0c04793e: /* original 8fb3, guest PC 0x0c04793e */
if(!s->budget--) { s->failed_pc=0x0c04793eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
if(!cond) { goto P_0c0478a8; }
goto P_0c047942;
P_0c047940: /* original f635, guest PC 0x0c047940 */
if(!s->budget--) { s->failed_pc=0x0c047940u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
goto P_0c047942;
P_0c047942: /* original f739, guest PC 0x0c047942 */
if(!s->budget--) { s->failed_pc=0x0c047942u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c047944;
P_0c047944: /* original f042, guest PC 0x0c047944 */
if(!s->budget--) { s->failed_pc=0x0c047944u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c047946;
P_0c047946: /* original 5022, guest PC 0x0c047946 */
if(!s->budget--) { s->failed_pc=0x0c047946u; return 0; }
r[0]=read(ram,r[2]+8,4);
goto P_0c047948;
P_0c047948: /* original f011, guest PC 0x0c047948 */
if(!s->budget--) { s->failed_pc=0x0c047948u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c04794a;
P_0c04794a: /* original 8fad, guest PC 0x0c04794a */
if(!s->budget--) { s->failed_pc=0x0c04794au; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
if(!cond) { goto P_0c0478a8; }
goto P_0c04794e;
P_0c04794c: /* original f505, guest PC 0x0c04794c */
if(!s->budget--) { s->failed_pc=0x0c04794cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
goto P_0c04794e;
P_0c04794e: /* original f539, guest PC 0x0c04794e */
if(!s->budget--) { s->failed_pc=0x0c04794eu; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c047950;
P_0c047950: /* original f742, guest PC 0x0c047950 */
if(!s->budget--) { s->failed_pc=0x0c047950u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c047952;
P_0c047952: /* original 8da9, guest PC 0x0c047952 */
if(!s->budget--) { s->failed_pc=0x0c047952u; return 0; }
cond=r[17]&1u;
tmp=r[1]; r[9]-=4; write(ram,r[9],tmp,4);
if(cond) { goto P_0c0478a8; }
goto P_0c047956;
P_0c047954: /* original 2916, guest PC 0x0c047954 */
if(!s->budget--) { s->failed_pc=0x0c047954u; return 0; }
tmp=r[1]; r[9]-=4; write(ram,r[9],tmp,4);
goto P_0c047956;
P_0c047956: /* original f731, guest PC 0x0c047956 */
if(!s->budget--) { s->failed_pc=0x0c047956u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c047958;
P_0c047958: /* original 2986, guest PC 0x0c047958 */
if(!s->budget--) { s->failed_pc=0x0c047958u; return 0; }
tmp=r[8]; r[9]-=4; write(ram,r[9],tmp,4);
goto P_0c04795a;
P_0c04795a: /* original e108, guest PC 0x0c04795a */
if(!s->budget--) { s->failed_pc=0x0c04795au; return 0; }
r[1]=0x00000008u;
goto P_0c04795c;
P_0c04795c: /* original f675, guest PC 0x0c04795c */
if(!s->budget--) { s->failed_pc=0x0c04795cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c04795e;
P_0c04795e: /* original f639, guest PC 0x0c04795e */
if(!s->budget--) { s->failed_pc=0x0c04795eu; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c047960;
P_0c047960: /* original 89a2, guest PC 0x0c047960 */
if(!s->budget--) { s->failed_pc=0x0c047960u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0478a8; }
goto P_0c047962;
P_0c047962: /* original c801, guest PC 0x0c047962 */
if(!s->budget--) { s->failed_pc=0x0c047962u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c047964;
P_0c047964: /* original 8424, guest PC 0x0c047964 */
if(!s->budget--) { s->failed_pc=0x0c047964u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+4,1);
goto P_0c047966;
P_0c047966: /* original 7208, guest PC 0x0c047966 */
if(!s->budget--) { s->failed_pc=0x0c047966u; return 0; }
r[2]+=0x00000008u;
goto P_0c047968;
P_0c047968: /* original f739, guest PC 0x0c047968 */
if(!s->budget--) { s->failed_pc=0x0c047968u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04796a;
P_0c04796a: /* original 6803, guest PC 0x0c04796a */
if(!s->budget--) { s->failed_pc=0x0c04796au; return 0; }
r[8]=r[0];
goto P_0c04796c;
P_0c04796c: /* original ff29, guest PC 0x0c04796c */
if(!s->budget--) { s->failed_pc=0x0c04796cu; return 0; }
vf3_matrix_load(s,ram,15,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04796e;
P_0c04796e: /* original 8f1a, guest PC 0x0c04796e */
if(!s->budget--) { s->failed_pc=0x0c04796eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000030u;
if(!cond) { goto P_0c0479a6; }
goto P_0c047972;
P_0c047970: /* original 7430, guest PC 0x0c047970 */
if(!s->budget--) { s->failed_pc=0x0c047970u; return 0; }
r[4]+=0x00000030u;
goto P_0c047972;
P_0c047972: /* original f029, guest PC 0x0c047972 */
if(!s->budget--) { s->failed_pc=0x0c047972u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c047974;
P_0c047974: /* original f129, guest PC 0x0c047974 */
if(!s->budget--) { s->failed_pc=0x0c047974u; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c047976;
P_0c047976: /* original f229, guest PC 0x0c047976 */
if(!s->budget--) { s->failed_pc=0x0c047976u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c047978;
P_0c047978: /* original f329, guest PC 0x0c047978 */
if(!s->budget--) { s->failed_pc=0x0c047978u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04797a;
P_0c04797a: /* original f0b2, guest PC 0x0c04797a */
if(!s->budget--) { s->failed_pc=0x0c04797au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c04797c;
P_0c04797c: /* original fb5c, guest PC 0x0c04797c */
if(!s->budget--) { s->failed_pc=0x0c04797cu; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c04797e;
P_0c04797e: /* original f152, guest PC 0x0c04797e */
if(!s->budget--) { s->failed_pc=0x0c04797eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c047980;
P_0c047980: /* original f429, guest PC 0x0c047980 */
if(!s->budget--) { s->failed_pc=0x0c047980u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c047982;
P_0c047982: /* original f529, guest PC 0x0c047982 */
if(!s->budget--) { s->failed_pc=0x0c047982u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c047984;
P_0c047984: /* original f5b2, guest PC 0x0c047984 */
if(!s->budget--) { s->failed_pc=0x0c047984u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c047986;
P_0c047986: /* original fb6c, guest PC 0x0c047986 */
if(!s->budget--) { s->failed_pc=0x0c047986u; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c047988;
P_0c047988: /* original f262, guest PC 0x0c047988 */
if(!s->budget--) { s->failed_pc=0x0c047988u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c04798a;
P_0c04798a: /* original f629, guest PC 0x0c04798a */
if(!s->budget--) { s->failed_pc=0x0c04798au; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04798c;
P_0c04798c: /* original f6b2, guest PC 0x0c04798c */
if(!s->budget--) { s->failed_pc=0x0c04798cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c04798e;
P_0c04798e: /* original fb7c, guest PC 0x0c04798e */
if(!s->budget--) { s->failed_pc=0x0c04798eu; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c047990;
P_0c047990: /* original f372, guest PC 0x0c047990 */
if(!s->budget--) { s->failed_pc=0x0c047990u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c047992;
P_0c047992: /* original f729, guest PC 0x0c047992 */
if(!s->budget--) { s->failed_pc=0x0c047992u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c047994;
P_0c047994: /* original 7640, guest PC 0x0c047994 */
if(!s->budget--) { s->failed_pc=0x0c047994u; return 0; }
r[6]+=0x00000040u;
goto P_0c047996;
P_0c047996: /* original f7b2, guest PC 0x0c047996 */
if(!s->budget--) { s->failed_pc=0x0c047996u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c047998;
P_0c047998: /* original f3fd, guest PC 0x0c047998 */
if(!s->budget--) { s->failed_pc=0x0c047998u; return 0; }
r[18]^=0x100000u;
goto P_0c04799a;
P_0c04799a: /* original f66b, guest PC 0x0c04799a */
if(!s->budget--) { s->failed_pc=0x0c04799au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04799c;
P_0c04799c: /* original f64b, guest PC 0x0c04799c */
if(!s->budget--) { s->failed_pc=0x0c04799cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04799e;
P_0c04799e: /* original f62b, guest PC 0x0c04799e */
if(!s->budget--) { s->failed_pc=0x0c04799eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0479a0;
P_0c0479a0: /* original f60b, guest PC 0x0c0479a0 */
if(!s->budget--) { s->failed_pc=0x0c0479a0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c0479a2;
P_0c0479a2: /* original f3fd, guest PC 0x0c0479a2 */
if(!s->budget--) { s->failed_pc=0x0c0479a2u; return 0; }
r[18]^=0x100000u;
goto P_0c0479a4;
P_0c0479a4: /* original 76e0, guest PC 0x0c0479a4 */
if(!s->budget--) { s->failed_pc=0x0c0479a4u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c0479a6;
P_0c0479a6: /* original 4811, guest PC 0x0c0479a6 */
if(!s->budget--) { s->failed_pc=0x0c0479a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=0)!=0);
goto P_0c0479a8;
P_0c0479a8: /* original 4d5a, guest PC 0x0c0479a8 */
if(!s->budget--) { s->failed_pc=0x0c0479a8u; return 0; }
r[53]=r[13];
goto P_0c0479aa;
P_0c0479aa: /* original 891b, guest PC 0x0c0479aa */
if(!s->budget--) { s->failed_pc=0x0c0479aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0479e4; }
goto P_0c0479ac;
P_0c0479ac: /* original 6083, guest PC 0x0c0479ac */
if(!s->budget--) { s->failed_pc=0x0c0479acu; return 0; }
r[0]=r[8];
goto P_0c0479ae;
P_0c0479ae: /* original 88ff, guest PC 0x0c0479ae */
if(!s->budget--) { s->failed_pc=0x0c0479aeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0479b0;
P_0c0479b0: /* original 8d14, guest PC 0x0c0479b0 */
if(!s->budget--) { s->failed_pc=0x0c0479b0u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
if(cond) { goto P_0c0479dc; }
goto P_0c0479b4;
P_0c0479b2: /* original 88fe, guest PC 0x0c0479b2 */
if(!s->budget--) { s->failed_pc=0x0c0479b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c0479b4;
P_0c0479b4: /* original 8b08, guest PC 0x0c0479b4 */
if(!s->budget--) { s->failed_pc=0x0c0479b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0479c8; }
goto P_0c0479b6;
P_0c0479b6: /* original d050, guest PC 0x0c0479b6 */
if(!s->budget--) { s->failed_pc=0x0c0479b6u; return 0; }
r[0]=read(ram,0x0c047af8u,4);
goto P_0c0479b8;
P_0c0479b8: /* original 400b, guest PC 0x0c0479b8 */
if(!s->budget--) { s->failed_pc=0x0c0479b8u; return 0; }
target=r[0];
r[16]=code_base|0x0c0479bcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0479bcu) { target=s->pc; goto dispatch; }
goto P_0c0479bc;
P_0c0479ba: /* original 0009, guest PC 0x0c0479ba */
if(!s->budget--) { s->failed_pc=0x0c0479bau; return 0; }
goto P_0c0479bc;
P_0c0479bc: /* original 896a, guest PC 0x0c0479bc */
if(!s->budget--) { s->failed_pc=0x0c0479bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047a94; }
goto P_0c0479be;
P_0c0479be: /* original 6146, guest PC 0x0c0479be */
if(!s->budget--) { s->failed_pc=0x0c0479beu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0479c0;
P_0c0479c0: /* original f249, guest PC 0x0c0479c0 */
if(!s->budget--) { s->failed_pc=0x0c0479c0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0479c2;
P_0c0479c2: /* original af25, guest PC 0x0c0479c2 */
if(!s->budget--) { s->failed_pc=0x0c0479c2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047810;
P_0c0479c4: /* original f349, guest PC 0x0c0479c4 */
if(!s->budget--) { s->failed_pc=0x0c0479c4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c0479c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0479c6u; return 0; } return 1;
P_0c0479c8: /* original 88fd, guest PC 0x0c0479c8 */
if(!s->budget--) { s->failed_pc=0x0c0479c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffdu)!=0);
goto P_0c0479ca;
P_0c0479ca: /* original 8b07, guest PC 0x0c0479ca */
if(!s->budget--) { s->failed_pc=0x0c0479cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0479dc; }
goto P_0c0479cc;
P_0c0479cc: /* original d04b, guest PC 0x0c0479cc */
if(!s->budget--) { s->failed_pc=0x0c0479ccu; return 0; }
r[0]=read(ram,0x0c047afcu,4);
goto P_0c0479ce;
P_0c0479ce: /* original 400b, guest PC 0x0c0479ce */
if(!s->budget--) { s->failed_pc=0x0c0479ceu; return 0; }
target=r[0];
r[16]=code_base|0x0c0479d2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0479d2u) { target=s->pc; goto dispatch; }
goto P_0c0479d2;
P_0c0479d0: /* original 0009, guest PC 0x0c0479d0 */
if(!s->budget--) { s->failed_pc=0x0c0479d0u; return 0; }
goto P_0c0479d2;
P_0c0479d2: /* original 895f, guest PC 0x0c0479d2 */
if(!s->budget--) { s->failed_pc=0x0c0479d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047a94; }
goto P_0c0479d4;
P_0c0479d4: /* original 6146, guest PC 0x0c0479d4 */
if(!s->budget--) { s->failed_pc=0x0c0479d4u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0479d6;
P_0c0479d6: /* original f249, guest PC 0x0c0479d6 */
if(!s->budget--) { s->failed_pc=0x0c0479d6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0479d8;
P_0c0479d8: /* original af1a, guest PC 0x0c0479d8 */
if(!s->budget--) { s->failed_pc=0x0c0479d8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047810;
P_0c0479da: /* original f349, guest PC 0x0c0479da */
if(!s->budget--) { s->failed_pc=0x0c0479dau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0479dc;
P_0c0479dc: /* original e800, guest PC 0x0c0479dc */
if(!s->budget--) { s->failed_pc=0x0c0479dcu; return 0; }
r[8]=0x00000000u;
goto P_0c0479de;
P_0c0479de: /* original a00b, guest PC 0x0c0479de */
if(!s->budget--) { s->failed_pc=0x0c0479deu; return 0; }
fr[15]=0x3f800000u;
goto P_0c0479f8;
P_0c0479e0: /* original ff9d, guest PC 0x0c0479e0 */
if(!s->budget--) { s->failed_pc=0x0c0479e0u; return 0; }
fr[15]=0x3f800000u;
if(!vf3_matrix_family(0x0c0479e2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0479e2u; return 0; } return 1;
P_0c0479e4: /* original 3817, guest PC 0x0c0479e4 */
if(!s->budget--) { s->failed_pc=0x0c0479e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>(int32_t)r[1])!=0);
goto P_0c0479e6;
P_0c0479e6: /* original f10d, guest PC 0x0c0479e6 */
if(!s->budget--) { s->failed_pc=0x0c0479e6u; return 0; }
fr[1]=r[53];
goto P_0c0479e8;
P_0c0479e8: /* original 4808, guest PC 0x0c0479e8 */
if(!s->budget--) { s->failed_pc=0x0c0479e8u; return 0; }
r[8]<<=2;
goto P_0c0479ea;
P_0c0479ea: /* original 8f05, guest PC 0x0c0479ea */
if(!s->budget--) { s->failed_pc=0x0c0479eau; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
if(!cond) { goto P_0c0479f8; }
goto P_0c0479ee;
P_0c0479ec: /* original ff12, guest PC 0x0c0479ec */
if(!s->budget--) { s->failed_pc=0x0c0479ecu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
goto P_0c0479ee;
P_0c0479ee: /* original 6083, guest PC 0x0c0479ee */
if(!s->budget--) { s->failed_pc=0x0c0479eeu; return 0; }
r[0]=r[8];
goto P_0c0479f0;
P_0c0479f0: /* original 8840, guest PC 0x0c0479f0 */
if(!s->budget--) { s->failed_pc=0x0c0479f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0479f2;
P_0c0479f2: /* original e824, guest PC 0x0c0479f2 */
if(!s->budget--) { s->failed_pc=0x0c0479f2u; return 0; }
r[8]=0x00000024u;
goto P_0c0479f4;
P_0c0479f4: /* original 8900, guest PC 0x0c0479f4 */
if(!s->budget--) { s->failed_pc=0x0c0479f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0479f8; }
goto P_0c0479f6;
P_0c0479f6: /* original e828, guest PC 0x0c0479f6 */
if(!s->budget--) { s->failed_pc=0x0c0479f6u; return 0; }
r[8]=0x00000028u;
goto P_0c0479f8;
P_0c0479f8: /* original 6046, guest PC 0x0c0479f8 */
if(!s->budget--) { s->failed_pc=0x0c0479f8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0479fa;
P_0c0479fa: /* original 4015, guest PC 0x0c0479fa */
if(!s->budget--) { s->failed_pc=0x0c0479fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0479fc;
P_0c0479fc: /* original 59f9, guest PC 0x0c0479fc */
if(!s->budget--) { s->failed_pc=0x0c0479fcu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c0479fe;
P_0c0479fe: /* original 8d09, guest PC 0x0c0479fe */
if(!s->budget--) { s->failed_pc=0x0c0479feu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
if(cond) { goto P_0c047a14; }
goto P_0c047a02;
P_0c047a00: /* original 4011, guest PC 0x0c047a00 */
if(!s->budget--) { s->failed_pc=0x0c047a00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c047a02;
P_0c047a02: /* original 6803, guest PC 0x0c047a02 */
if(!s->budget--) { s->failed_pc=0x0c047a02u; return 0; }
r[8]=r[0];
goto P_0c047a04;
P_0c047a04: /* original 60b3, guest PC 0x0c047a04 */
if(!s->budget--) { s->failed_pc=0x0c047a04u; return 0; }
r[0]=r[11];
goto P_0c047a06;
P_0c047a06: /* original 0a56, guest PC 0x0c047a06 */
if(!s->budget--) { s->failed_pc=0x0c047a06u; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c047a08;
P_0c047a08: /* original 8944, guest PC 0x0c047a08 */
if(!s->budget--) { s->failed_pc=0x0c047a08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047a94; }
goto P_0c047a0a;
P_0c047a0a: /* original 6146, guest PC 0x0c047a0a */
if(!s->budget--) { s->failed_pc=0x0c047a0au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c047a0c;
P_0c047a0c: /* original f249, guest PC 0x0c047a0c */
if(!s->budget--) { s->failed_pc=0x0c047a0cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047a0e;
P_0c047a0e: /* original aeff, guest PC 0x0c047a0e */
if(!s->budget--) { s->failed_pc=0x0c047a0eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c047810;
P_0c047a10: /* original f349, guest PC 0x0c047a10 */
if(!s->budget--) { s->failed_pc=0x0c047a10u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c047a12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c047a12u; return 0; } return 1;
P_0c047a14: /* original 6103, guest PC 0x0c047a14 */
if(!s->budget--) { s->failed_pc=0x0c047a14u; return 0; }
r[1]=r[0];
goto P_0c047a16;
P_0c047a16: /* original e2fb, guest PC 0x0c047a16 */
if(!s->budget--) { s->failed_pc=0x0c047a16u; return 0; }
r[2]=0xfffffffbu;
goto P_0c047a18;
P_0c047a18: /* original 6396, guest PC 0x0c047a18 */
if(!s->budget--) { s->failed_pc=0x0c047a18u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[3]=tmp;
goto P_0c047a1a;
P_0c047a1a: /* original c940, guest PC 0x0c047a1a */
if(!s->budget--) { s->failed_pc=0x0c047a1au; return 0; }
r[0]&=64u;
goto P_0c047a1c;
P_0c047a1c: /* original 402d, guest PC 0x0c047a1c */
if(!s->budget--) { s->failed_pc=0x0c047a1cu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c047a1e;
P_0c047a1e: /* original e2fd, guest PC 0x0c047a1e */
if(!s->budget--) { s->failed_pc=0x0c047a1eu; return 0; }
r[2]=0xfffffffdu;
goto P_0c047a20;
P_0c047a20: /* original 2329, guest PC 0x0c047a20 */
if(!s->budget--) { s->failed_pc=0x0c047a20u; return 0; }
r[3]&=r[2];
goto P_0c047a22;
P_0c047a22: /* original 203b, guest PC 0x0c047a22 */
if(!s->budget--) { s->failed_pc=0x0c047a22u; return 0; }
r[0]|=r[3];
goto P_0c047a24;
P_0c047a24: /* original c810, guest PC 0x0c047a24 */
if(!s->budget--) { s->failed_pc=0x0c047a24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c047a26;
P_0c047a26: /* original 7420, guest PC 0x0c047a26 */
if(!s->budget--) { s->failed_pc=0x0c047a26u; return 0; }
r[4]+=0x00000020u;
goto P_0c047a28;
P_0c047a28: /* original 8f03, guest PC 0x0c047a28 */
if(!s->budget--) { s->failed_pc=0x0c047a28u; return 0; }
cond=r[17]&1u;
r[53]=r[0];
if(!cond) { goto P_0c047a32; }
goto P_0c047a2c;
P_0c047a2a: /* original 405a, guest PC 0x0c047a2a */
if(!s->budget--) { s->failed_pc=0x0c047a2au; return 0; }
r[53]=r[0];
goto P_0c047a2c;
P_0c047a2c: /* original cb10, guest PC 0x0c047a2c */
if(!s->budget--) { s->failed_pc=0x0c047a2cu; return 0; }
r[0]|=16u;
goto P_0c047a2e;
P_0c047a2e: /* original 6293, guest PC 0x0c047a2e */
if(!s->budget--) { s->failed_pc=0x0c047a2eu; return 0; }
r[2]=r[9];
goto P_0c047a30;
P_0c047a30: /* original 2206, guest PC 0x0c047a30 */
if(!s->budget--) { s->failed_pc=0x0c047a30u; return 0; }
tmp=r[0]; r[2]-=4; write(ram,r[2],tmp,4);
goto P_0c047a32;
P_0c047a32: /* original 6013, guest PC 0x0c047a32 */
if(!s->budget--) { s->failed_pc=0x0c047a32u; return 0; }
r[0]=r[1];
goto P_0c047a34;
P_0c047a34: /* original e21b, guest PC 0x0c047a34 */
if(!s->budget--) { s->failed_pc=0x0c047a34u; return 0; }
r[2]=0x0000001bu;
goto P_0c047a36;
P_0c047a36: /* original c903, guest PC 0x0c047a36 */
if(!s->budget--) { s->failed_pc=0x0c047a36u; return 0; }
r[0]&=3u;
goto P_0c047a38;
P_0c047a38: /* original 402d, guest PC 0x0c047a38 */
if(!s->budget--) { s->failed_pc=0x0c047a38u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c047a3a;
P_0c047a3a: /* original e303, guest PC 0x0c047a3a */
if(!s->budget--) { s->failed_pc=0x0c047a3au; return 0; }
r[3]=0x00000003u;
goto P_0c047a3c;
P_0c047a3c: /* original f3fd, guest PC 0x0c047a3c */
if(!s->budget--) { s->failed_pc=0x0c047a3cu; return 0; }
r[18]^=0x100000u;
goto P_0c047a3e;
P_0c047a3e: /* original 432d, guest PC 0x0c047a3e */
if(!s->budget--) { s->failed_pc=0x0c047a3eu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c047a40;
P_0c047a40: /* original 0483, guest PC 0x0c047a40 */
if(!s->budget--) { s->failed_pc=0x0c047a40u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c047a42;
P_0c047a42: /* original 6337, guest PC 0x0c047a42 */
if(!s->budget--) { s->failed_pc=0x0c047a42u; return 0; }
r[3]=~r[3];
goto P_0c047a44;
P_0c047a44: /* original 6296, guest PC 0x0c047a44 */
if(!s->budget--) { s->failed_pc=0x0c047a44u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[2]=tmp;
goto P_0c047a46;
P_0c047a46: /* original 2239, guest PC 0x0c047a46 */
if(!s->budget--) { s->failed_pc=0x0c047a46u; return 0; }
r[2]&=r[3];
goto P_0c047a48;
P_0c047a48: /* original f00d, guest PC 0x0c047a48 */
if(!s->budget--) { s->failed_pc=0x0c047a48u; return 0; }
fr[0]=r[53];
goto P_0c047a4a;
P_0c047a4a: /* original 220b, guest PC 0x0c047a4a */
if(!s->budget--) { s->failed_pc=0x0c047a4au; return 0; }
r[2]|=r[0];
goto P_0c047a4c;
P_0c047a4c: /* original 425a, guest PC 0x0c047a4c */
if(!s->budget--) { s->failed_pc=0x0c047a4cu; return 0; }
r[53]=r[2];
goto P_0c047a4e;
P_0c047a4e: /* original 74e0, guest PC 0x0c047a4e */
if(!s->budget--) { s->failed_pc=0x0c047a4eu; return 0; }
r[4]+=0xffffffe0u;
goto P_0c047a50;
P_0c047a50: /* original f10d, guest PC 0x0c047a50 */
if(!s->budget--) { s->failed_pc=0x0c047a50u; return 0; }
fr[1]=r[53];
goto P_0c047a52;
P_0c047a52: /* original 7610, guest PC 0x0c047a52 */
if(!s->budget--) { s->failed_pc=0x0c047a52u; return 0; }
r[6]+=0x00000010u;
goto P_0c047a54;
P_0c047a54: /* original f299, guest PC 0x0c047a54 */
if(!s->budget--) { s->failed_pc=0x0c047a54u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c047a56;
P_0c047a56: /* original f62b, guest PC 0x0c047a56 */
if(!s->budget--) { s->failed_pc=0x0c047a56u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c047a58;
P_0c047a58: /* original 7520, guest PC 0x0c047a58 */
if(!s->budget--) { s->failed_pc=0x0c047a58u; return 0; }
r[5]+=0x00000020u;
goto P_0c047a5a;
P_0c047a5a: /* original f60b, guest PC 0x0c047a5a */
if(!s->budget--) { s->failed_pc=0x0c047a5au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c047a5c;
P_0c047a5c: /* original f3fd, guest PC 0x0c047a5c */
if(!s->budget--) { s->failed_pc=0x0c047a5cu; return 0; }
r[18]^=0x100000u;
goto P_0c047a5e;
P_0c047a5e: /* original 0683, guest PC 0x0c047a5e */
if(!s->budget--) { s->failed_pc=0x0c047a5eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c047a60;
P_0c047a60: /* original 8f03, guest PC 0x0c047a60 */
if(!s->budget--) { s->failed_pc=0x0c047a60u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000020u;
if(!cond) { goto P_0c047a6a; }
goto P_0c047a64;
P_0c047a62: /* original 7620, guest PC 0x0c047a62 */
if(!s->budget--) { s->failed_pc=0x0c047a62u; return 0; }
r[6]+=0x00000020u;
goto P_0c047a64;
P_0c047a64: /* original 0683, guest PC 0x0c047a64 */
if(!s->budget--) { s->failed_pc=0x0c047a64u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c047a66;
P_0c047a66: /* original 7620, guest PC 0x0c047a66 */
if(!s->budget--) { s->failed_pc=0x0c047a66u; return 0; }
r[6]+=0x00000020u;
goto P_0c047a68;
P_0c047a68: /* original 7520, guest PC 0x0c047a68 */
if(!s->budget--) { s->failed_pc=0x0c047a68u; return 0; }
r[5]+=0x00000020u;
goto P_0c047a6a;
P_0c047a6a: /* original 4c25, guest PC 0x0c047a6a */
if(!s->budget--) { s->failed_pc=0x0c047a6au; return 0; }
tmp=r[12]&1u; r[12]=(r[12]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c047a6c;
P_0c047a6c: /* original 6013, guest PC 0x0c047a6c */
if(!s->budget--) { s->failed_pc=0x0c047a6cu; return 0; }
r[0]=r[1];
goto P_0c047a6e;
P_0c047a6e: /* original 8d21, guest PC 0x0c047a6e */
if(!s->budget--) { s->failed_pc=0x0c047a6eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
if(cond) { goto P_0c047ab4; }
goto P_0c047a72;
P_0c047a70: /* original 4c00, guest PC 0x0c047a70 */
if(!s->budget--) { s->failed_pc=0x0c047a70u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c047a72;
P_0c047a72: /* original c808, guest PC 0x0c047a72 */
if(!s->budget--) { s->failed_pc=0x0c047a72u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c047a74;
P_0c047a74: /* original 8d04, guest PC 0x0c047a74 */
if(!s->budget--) { s->failed_pc=0x0c047a74u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
if(cond) { goto P_0c047a80; }
goto P_0c047a78;
P_0c047a76: /* original c804, guest PC 0x0c047a76 */
if(!s->budget--) { s->failed_pc=0x0c047a76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c047a78;
P_0c047a78: /* original b0c2, guest PC 0x0c047a78 */
if(!s->budget--) { s->failed_pc=0x0c047a78u; return 0; }
target=code_base|0x0c047c00u; r[16]=code_base|0x0c047a7cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c047a7cu) { target=s->pc; goto dispatch; }
goto P_0c047a7c;
P_0c047a7a: /* original 0009, guest PC 0x0c047a7a */
if(!s->budget--) { s->failed_pc=0x0c047a7au; return 0; }
goto P_0c047a7c;
P_0c047a7c: /* original afbd, guest PC 0x0c047a7c */
if(!s->budget--) { s->failed_pc=0x0c047a7cu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0479fa;
P_0c047a7e: /* original 6046, guest PC 0x0c047a7e */
if(!s->budget--) { s->failed_pc=0x0c047a7eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c047a80;
P_0c047a80: /* original 8d04, guest PC 0x0c047a80 */
if(!s->budget--) { s->failed_pc=0x0c047a80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047a8c; }
goto P_0c047a84;
P_0c047a82: /* original 0009, guest PC 0x0c047a82 */
if(!s->budget--) { s->failed_pc=0x0c047a82u; return 0; }
goto P_0c047a84;
P_0c047a84: /* original b5bc, guest PC 0x0c047a84 */
if(!s->budget--) { s->failed_pc=0x0c047a84u; return 0; }
target=code_base|0x0c048600u; r[16]=code_base|0x0c047a88u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c047a88u) { target=s->pc; goto dispatch; }
goto P_0c047a88;
P_0c047a86: /* original 0009, guest PC 0x0c047a86 */
if(!s->budget--) { s->failed_pc=0x0c047a86u; return 0; }
goto P_0c047a88;
P_0c047a88: /* original afb7, guest PC 0x0c047a88 */
if(!s->budget--) { s->failed_pc=0x0c047a88u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0479fa;
P_0c047a8a: /* original 6046, guest PC 0x0c047a8a */
if(!s->budget--) { s->failed_pc=0x0c047a8au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c047a8c;
P_0c047a8c: /* original b048, guest PC 0x0c047a8c */
if(!s->budget--) { s->failed_pc=0x0c047a8cu; return 0; }
target=code_base|0x0c047b20u; r[16]=code_base|0x0c047a90u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c047a90u) { target=s->pc; goto dispatch; }
goto P_0c047a90;
P_0c047a8e: /* original 0009, guest PC 0x0c047a8e */
if(!s->budget--) { s->failed_pc=0x0c047a8eu; return 0; }
goto P_0c047a90;
P_0c047a90: /* original afb3, guest PC 0x0c047a90 */
if(!s->budget--) { s->failed_pc=0x0c047a90u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0479fa;
P_0c047a92: /* original 6046, guest PC 0x0c047a92 */
if(!s->budget--) { s->failed_pc=0x0c047a92u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c047a94;
P_0c047a94: /* original 7f28, guest PC 0x0c047a94 */
if(!s->budget--) { s->failed_pc=0x0c047a94u; return 0; }
r[15]+=0x00000028u;
goto P_0c047a96;
P_0c047a96: /* original 4f26, guest PC 0x0c047a96 */
if(!s->budget--) { s->failed_pc=0x0c047a96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c047a98;
P_0c047a98: /* original 68f6, guest PC 0x0c047a98 */
if(!s->budget--) { s->failed_pc=0x0c047a98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c047a9a;
P_0c047a9a: /* original 69f6, guest PC 0x0c047a9a */
if(!s->budget--) { s->failed_pc=0x0c047a9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c047a9c;
P_0c047a9c: /* original 6af6, guest PC 0x0c047a9c */
if(!s->budget--) { s->failed_pc=0x0c047a9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c047a9e;
P_0c047a9e: /* original 6bf6, guest PC 0x0c047a9e */
if(!s->budget--) { s->failed_pc=0x0c047a9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c047aa0;
P_0c047aa0: /* original 6cf6, guest PC 0x0c047aa0 */
if(!s->budget--) { s->failed_pc=0x0c047aa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c047aa2;
P_0c047aa2: /* original 6df6, guest PC 0x0c047aa2 */
if(!s->budget--) { s->failed_pc=0x0c047aa2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c047aa4;
P_0c047aa4: /* original 6ef6, guest PC 0x0c047aa4 */
if(!s->budget--) { s->failed_pc=0x0c047aa4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c047aa6;
P_0c047aa6: /* original fcf9, guest PC 0x0c047aa6 */
if(!s->budget--) { s->failed_pc=0x0c047aa6u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c047aa8;
P_0c047aa8: /* original fdf9, guest PC 0x0c047aa8 */
if(!s->budget--) { s->failed_pc=0x0c047aa8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c047aaa;
P_0c047aaa: /* original fef9, guest PC 0x0c047aaa */
if(!s->budget--) { s->failed_pc=0x0c047aaau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c047aac;
P_0c047aac: /* original fff9, guest PC 0x0c047aac */
if(!s->budget--) { s->failed_pc=0x0c047aacu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c047aae;
P_0c047aae: /* original 000b, guest PC 0x0c047aae */
if(!s->budget--) { s->failed_pc=0x0c047aaeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c047ab0: /* original 0009, guest PC 0x0c047ab0 */
if(!s->budget--) { s->failed_pc=0x0c047ab0u; return 0; }
if(!vf3_matrix_family(0x0c047ab2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c047ab2u; return 0; } return 1;
P_0c047ab4: /* original e100, guest PC 0x0c047ab4 */
if(!s->budget--) { s->failed_pc=0x0c047ab4u; return 0; }
r[1]=0x00000000u;
goto P_0c047ab6;
P_0c047ab6: /* original c840, guest PC 0x0c047ab6 */
if(!s->budget--) { s->failed_pc=0x0c047ab6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c047ab8;
P_0c047ab8: /* original 3c1e, guest PC 0x0c047ab8 */
if(!s->budget--) { s->failed_pc=0x0c047ab8u; return 0; }
wide=(uint64_t)r[12]+r[1]+(r[17]&1u); r[12]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c047aba;
P_0c047aba: /* original c810, guest PC 0x0c047aba */
if(!s->budget--) { s->failed_pc=0x0c047abau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c047abc;
P_0c047abc: /* original 8d04, guest PC 0x0c047abc */
if(!s->budget--) { s->failed_pc=0x0c047abcu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
if(cond) { goto P_0c047ac8; }
goto P_0c047ac0;
P_0c047abe: /* original c808, guest PC 0x0c047abe */
if(!s->budget--) { s->failed_pc=0x0c047abeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c047ac0;
P_0c047ac0: /* original b10e, guest PC 0x0c047ac0 */
if(!s->budget--) { s->failed_pc=0x0c047ac0u; return 0; }
target=code_base|0x0c047ce0u; r[16]=code_base|0x0c047ac4u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c047ac4u) { target=s->pc; goto dispatch; }
goto P_0c047ac4;
P_0c047ac2: /* original c820, guest PC 0x0c047ac2 */
if(!s->budget--) { s->failed_pc=0x0c047ac2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c047ac4;
P_0c047ac4: /* original af99, guest PC 0x0c047ac4 */
if(!s->budget--) { s->failed_pc=0x0c047ac4u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0479fa;
P_0c047ac6: /* original 6046, guest PC 0x0c047ac6 */
if(!s->budget--) { s->failed_pc=0x0c047ac6u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c047ac8;
P_0c047ac8: /* original 8904, guest PC 0x0c047ac8 */
if(!s->budget--) { s->failed_pc=0x0c047ac8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047ad4; }
goto P_0c047aca;
P_0c047aca: /* original b2f9, guest PC 0x0c047aca */
if(!s->budget--) { s->failed_pc=0x0c047acau; return 0; }
target=code_base|0x0c0480c0u; r[16]=code_base|0x0c047aceu;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c047aceu) { target=s->pc; goto dispatch; }
goto P_0c047ace;
P_0c047acc: /* original c820, guest PC 0x0c047acc */
if(!s->budget--) { s->failed_pc=0x0c047accu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c047ace;
P_0c047ace: /* original af94, guest PC 0x0c047ace */
if(!s->budget--) { s->failed_pc=0x0c047aceu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0479fa;
P_0c047ad0: /* original 6046, guest PC 0x0c047ad0 */
if(!s->budget--) { s->failed_pc=0x0c047ad0u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
if(!vf3_matrix_family(0x0c047ad2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c047ad2u; return 0; } return 1;
P_0c047ad4: /* original affe, guest PC 0x0c047ad4 */
if(!s->budget--) { s->failed_pc=0x0c047ad4u; return 0; }
goto P_0c047ad4;
P_0c047ad6: /* original 0009, guest PC 0x0c047ad6 */
if(!s->budget--) { s->failed_pc=0x0c047ad6u; return 0; }
if(!vf3_matrix_family(0x0c047ad8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c047ad8u; return 0; } return 1;
P_0c0482f0: /* original 63f3, guest PC 0x0c0482f0 */
if(!s->budget--) { s->failed_pc=0x0c0482f0u; return 0; }
r[3]=r[15];
goto P_0c0482f2;
P_0c0482f2: /* original fb39, guest PC 0x0c0482f2 */
if(!s->budget--) { s->failed_pc=0x0c0482f2u; return 0; }
vf3_matrix_load(s,ram,11,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f4;
P_0c0482f4: /* original f79d, guest PC 0x0c0482f4 */
if(!s->budget--) { s->failed_pc=0x0c0482f4u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0482f6;
P_0c0482f6: /* original f7b5, guest PC 0x0c0482f6 */
if(!s->budget--) { s->failed_pc=0x0c0482f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[11]))!=0);
goto P_0c0482f8;
P_0c0482f8: /* original 6043, guest PC 0x0c0482f8 */
if(!s->budget--) { s->failed_pc=0x0c0482f8u; return 0; }
r[0]=r[4];
goto P_0c0482fa;
P_0c0482fa: /* original 7030, guest PC 0x0c0482fa */
if(!s->budget--) { s->failed_pc=0x0c0482fau; return 0; }
r[0]+=0x00000030u;
goto P_0c0482fc;
P_0c0482fc: /* original 8f15, guest PC 0x0c0482fc */
if(!s->budget--) { s->failed_pc=0x0c0482fcu; return 0; }
cond=r[17]&1u;
if((r[0]&0xFC000000u)==0xE0000000u) pref(ram,r[0]);
if(!cond) { goto P_0c04832a; }
goto P_0c048300;
P_0c0482fe: /* original 0083, guest PC 0x0c0482fe */
if(!s->budget--) { s->failed_pc=0x0c0482feu; return 0; }
if((r[0]&0xFC000000u)==0xE0000000u) pref(ram,r[0]);
goto P_0c048300;
P_0c048300: /* original e202, guest PC 0x0c048300 */
if(!s->budget--) { s->failed_pc=0x0c048300u; return 0; }
r[2]=0x00000002u;
goto P_0c048302;
P_0c048302: /* original f21d, guest PC 0x0c048302 */
if(!s->budget--) { s->failed_pc=0x0c048302u; return 0; }
r[53]=fr[2];
goto P_0c048304;
P_0c048304: /* original 4228, guest PC 0x0c048304 */
if(!s->budget--) { s->failed_pc=0x0c048304u; return 0; }
r[2]<<=16;
goto P_0c048306;
P_0c048306: /* original 005a, guest PC 0x0c048306 */
if(!s->budget--) { s->failed_pc=0x0c048306u; return 0; }
r[0]=r[53];
goto P_0c048308;
P_0c048308: /* original 4218, guest PC 0x0c048308 */
if(!s->budget--) { s->failed_pc=0x0c048308u; return 0; }
r[2]<<=8;
goto P_0c04830a;
P_0c04830a: /* original d9b7, guest PC 0x0c04830a */
if(!s->budget--) { s->failed_pc=0x0c04830au; return 0; }
r[9]=read(ram,0x0c0485e8u,4);
goto P_0c04830c;
P_0c04830c: /* original 282b, guest PC 0x0c04830c */
if(!s->budget--) { s->failed_pc=0x0c04830cu; return 0; }
r[8]|=r[2];
goto P_0c04830e;
P_0c04830e: /* original cbc0, guest PC 0x0c04830e */
if(!s->budget--) { s->failed_pc=0x0c04830eu; return 0; }
r[0]|=192u;
goto P_0c048310;
P_0c048310: /* original 6009, guest PC 0x0c048310 */
if(!s->budget--) { s->failed_pc=0x0c048310u; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c048312;
P_0c048312: /* original 6992, guest PC 0x0c048312 */
if(!s->budget--) { s->failed_pc=0x0c048312u; return 0; }
tmp=read(ram,r[9],4);
r[9]=tmp;
goto P_0c048314;
P_0c048314: /* original cb10, guest PC 0x0c048314 */
if(!s->budget--) { s->failed_pc=0x0c048314u; return 0; }
r[0]|=16u;
goto P_0c048316;
P_0c048316: /* original 6008, guest PC 0x0c048316 */
if(!s->budget--) { s->failed_pc=0x0c048316u; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c048318;
P_0c048318: /* original cbfc, guest PC 0x0c048318 */
if(!s->budget--) { s->failed_pc=0x0c048318u; return 0; }
r[0]|=252u;
goto P_0c04831a;
P_0c04831a: /* original 209a, guest PC 0x0c04831a */
if(!s->budget--) { s->failed_pc=0x0c04831au; return 0; }
r[0]^=r[9];
goto P_0c04831c;
P_0c04831c: /* original 6008, guest PC 0x0c04831c */
if(!s->budget--) { s->failed_pc=0x0c04831cu; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c04831e;
P_0c04831e: /* original 6009, guest PC 0x0c04831e */
if(!s->budget--) { s->failed_pc=0x0c04831eu; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c048320;
P_0c048320: /* original 322c, guest PC 0x0c048320 */
if(!s->budget--) { s->failed_pc=0x0c048320u; return 0; }
r[2]+=r[2];
goto P_0c048322;
P_0c048322: /* original 405a, guest PC 0x0c048322 */
if(!s->budget--) { s->failed_pc=0x0c048322u; return 0; }
r[53]=r[0];
goto P_0c048324;
P_0c048324: /* original 6227, guest PC 0x0c048324 */
if(!s->budget--) { s->failed_pc=0x0c048324u; return 0; }
r[2]=~r[2];
goto P_0c048326;
P_0c048326: /* original f20d, guest PC 0x0c048326 */
if(!s->budget--) { s->failed_pc=0x0c048326u; return 0; }
fr[2]=r[53];
goto P_0c048328;
P_0c048328: /* original 2829, guest PC 0x0c048328 */
if(!s->budget--) { s->failed_pc=0x0c048328u; return 0; }
r[8]&=r[2];
goto P_0c04832a;
P_0c04832a: /* original 6083, guest PC 0x0c04832a */
if(!s->budget--) { s->failed_pc=0x0c04832au; return 0; }
r[0]=r[8];
goto P_0c04832c;
P_0c04832c: /* original f449, guest PC 0x0c04832c */
if(!s->budget--) { s->failed_pc=0x0c04832cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04832e;
P_0c04832e: /* original 4029, guest PC 0x0c04832e */
if(!s->budget--) { s->failed_pc=0x0c04832eu; return 0; }
r[0]>>=16;
goto P_0c048330;
P_0c048330: /* original f549, guest PC 0x0c048330 */
if(!s->budget--) { s->failed_pc=0x0c048330u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048332;
P_0c048332: /* original 4019, guest PC 0x0c048332 */
if(!s->budget--) { s->failed_pc=0x0c048332u; return 0; }
r[0]>>=8;
goto P_0c048334;
P_0c048334: /* original f649, guest PC 0x0c048334 */
if(!s->budget--) { s->failed_pc=0x0c048334u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048336;
P_0c048336: /* original c907, guest PC 0x0c048336 */
if(!s->budget--) { s->failed_pc=0x0c048336u; return 0; }
r[0]&=7u;
goto P_0c048338;
P_0c048338: /* original e204, guest PC 0x0c048338 */
if(!s->budget--) { s->failed_pc=0x0c048338u; return 0; }
r[2]=0x00000004u;
goto P_0c04833a;
P_0c04833a: /* original 4008, guest PC 0x0c04833a */
if(!s->budget--) { s->failed_pc=0x0c04833au; return 0; }
r[0]<<=2;
goto P_0c04833c;
P_0c04833c: /* original f5fd, guest PC 0x0c04833c */
if(!s->budget--) { s->failed_pc=0x0c04833cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c04833e;
P_0c04833e: /* original f139, guest PC 0x0c04833e */
if(!s->budget--) { s->failed_pc=0x0c04833eu; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048340;
P_0c048340: /* original 4218, guest PC 0x0c048340 */
if(!s->budget--) { s->failed_pc=0x0c048340u; return 0; }
r[2]<<=8;
goto P_0c048342;
P_0c048342: /* original f049, guest PC 0x0c048342 */
if(!s->budget--) { s->failed_pc=0x0c048342u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048344;
P_0c048344: /* original 3b00, guest PC 0x0c048344 */
if(!s->budget--) { s->failed_pc=0x0c048344u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[0])!=0);
goto P_0c048346;
P_0c048346: /* original 6b03, guest PC 0x0c048346 */
if(!s->budget--) { s->failed_pc=0x0c048346u; return 0; }
r[11]=r[0];
goto P_0c048348;
P_0c048348: /* original e6e0, guest PC 0x0c048348 */
if(!s->budget--) { s->failed_pc=0x0c048348u; return 0; }
r[6]=0xffffffe0u;
goto P_0c04834a;
P_0c04834a: /* original f012, guest PC 0x0c04834a */
if(!s->budget--) { s->failed_pc=0x0c04834au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c04834c;
P_0c04834c: /* original 4228, guest PC 0x0c04834c */
if(!s->budget--) { s->failed_pc=0x0c04834cu; return 0; }
r[2]<<=16;
goto P_0c04834e;
P_0c04834e: /* original 8d09, guest PC 0x0c04834e */
if(!s->budget--) { s->failed_pc=0x0c04834eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c048364; }
goto P_0c048352;
P_0c048350: /* original 05ae, guest PC 0x0c048350 */
if(!s->budget--) { s->failed_pc=0x0c048350u; return 0; }
r[5]=read(ram,r[10]+r[0],4);
goto P_0c048352;
P_0c048352: /* original e0ff, guest PC 0x0c048352 */
if(!s->budget--) { s->failed_pc=0x0c048352u; return 0; }
r[0]=0xffffffffu;
goto P_0c048354;
P_0c048354: /* original 4028, guest PC 0x0c048354 */
if(!s->budget--) { s->failed_pc=0x0c048354u; return 0; }
r[0]<<=16;
goto P_0c048356;
P_0c048356: /* original 4018, guest PC 0x0c048356 */
if(!s->budget--) { s->failed_pc=0x0c048356u; return 0; }
r[0]<<=8;
goto P_0c048358;
P_0c048358: /* original cb38, guest PC 0x0c048358 */
if(!s->budget--) { s->failed_pc=0x0c048358u; return 0; }
r[0]|=56u;
goto P_0c04835a;
P_0c04835a: /* original 6953, guest PC 0x0c04835a */
if(!s->budget--) { s->failed_pc=0x0c04835au; return 0; }
r[9]=r[5];
goto P_0c04835c;
P_0c04835c: /* original 4929, guest PC 0x0c04835c */
if(!s->budget--) { s->failed_pc=0x0c04835cu; return 0; }
r[9]>>=16;
goto P_0c04835e;
P_0c04835e: /* original 4919, guest PC 0x0c04835e */
if(!s->budget--) { s->failed_pc=0x0c04835eu; return 0; }
r[9]>>=8;
goto P_0c048360;
P_0c048360: /* original 2092, guest PC 0x0c048360 */
if(!s->budget--) { s->failed_pc=0x0c048360u; return 0; }
write(ram,r[0],r[9],4);
goto P_0c048362;
P_0c048362: /* original 1091, guest PC 0x0c048362 */
if(!s->budget--) { s->failed_pc=0x0c048362u; return 0; }
write(ram,r[0]+4,r[9],4);
goto P_0c048364;
P_0c048364: /* original 72ff, guest PC 0x0c048364 */
if(!s->budget--) { s->failed_pc=0x0c048364u; return 0; }
r[2]+=0xffffffffu;
goto P_0c048366;
P_0c048366: /* original 4c5a, guest PC 0x0c048366 */
if(!s->budget--) { s->failed_pc=0x0c048366u; return 0; }
r[53]=r[12];
goto P_0c048368;
P_0c048368: /* original e0fe, guest PC 0x0c048368 */
if(!s->budget--) { s->failed_pc=0x0c048368u; return 0; }
r[0]=0xfffffffeu;
goto P_0c04836a;
P_0c04836a: /* original f700, guest PC 0x0c04836a */
if(!s->budget--) { s->failed_pc=0x0c04836au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'+');
goto P_0c04836c;
P_0c04836c: /* original 2259, guest PC 0x0c04836c */
if(!s->budget--) { s->failed_pc=0x0c04836cu; return 0; }
r[2]&=r[5];
goto P_0c04836e;
P_0c04836e: /* original f10d, guest PC 0x0c04836e */
if(!s->budget--) { s->failed_pc=0x0c04836eu; return 0; }
fr[1]=r[53];
goto P_0c048370;
P_0c048370: /* original 4618, guest PC 0x0c048370 */
if(!s->budget--) { s->failed_pc=0x0c048370u; return 0; }
r[6]<<=8;
goto P_0c048372;
P_0c048372: /* original f715, guest PC 0x0c048372 */
if(!s->budget--) { s->failed_pc=0x0c048372u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c048374;
P_0c048374: /* original 4628, guest PC 0x0c048374 */
if(!s->budget--) { s->failed_pc=0x0c048374u; return 0; }
r[6]<<=16;
goto P_0c048376;
P_0c048376: /* original 262b, guest PC 0x0c048376 */
if(!s->budget--) { s->failed_pc=0x0c048376u; return 0; }
r[6]|=r[2];
goto P_0c048378;
P_0c048378: /* original f701, guest PC 0x0c048378 */
if(!s->budget--) { s->failed_pc=0x0c048378u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c04837a;
P_0c04837a: /* original 2c09, guest PC 0x0c04837a */
if(!s->budget--) { s->failed_pc=0x0c04837au; return 0; }
r[12]&=r[0];
goto P_0c04837c;
P_0c04837c: /* original 59f9, guest PC 0x0c04837c */
if(!s->budget--) { s->failed_pc=0x0c04837cu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c04837e;
P_0c04837e: /* original 8f43, guest PC 0x0c04837e */
if(!s->budget--) { s->failed_pc=0x0c04837eu; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
if(!cond) { goto P_0c048408; }
goto P_0c048382;
P_0c048380: /* original f701, guest PC 0x0c048380 */
if(!s->budget--) { s->failed_pc=0x0c048380u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c048382;
P_0c048382: /* original f715, guest PC 0x0c048382 */
if(!s->budget--) { s->failed_pc=0x0c048382u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c048384;
P_0c048384: /* original 8f40, guest PC 0x0c048384 */
if(!s->budget--) { s->failed_pc=0x0c048384u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c048408; }
goto P_0c048388;
P_0c048386: /* original 7c01, guest PC 0x0c048386 */
if(!s->budget--) { s->failed_pc=0x0c048386u; return 0; }
r[12]+=0x00000001u;
goto P_0c048388;
P_0c048388: /* original 6243, guest PC 0x0c048388 */
if(!s->budget--) { s->failed_pc=0x0c048388u; return 0; }
r[2]=r[4];
goto P_0c04838a;
P_0c04838a: /* original 742c, guest PC 0x0c04838a */
if(!s->budget--) { s->failed_pc=0x0c04838au; return 0; }
r[4]+=0x0000002cu;
goto P_0c04838c;
P_0c04838c: /* original 6046, guest PC 0x0c04838c */
if(!s->budget--) { s->failed_pc=0x0c04838cu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04838e;
P_0c04838e: /* original 2682, guest PC 0x0c04838e */
if(!s->budget--) { s->failed_pc=0x0c04838eu; return 0; }
write(ram,r[6],r[8],4);
goto P_0c048390;
P_0c048390: /* original 6183, guest PC 0x0c048390 */
if(!s->budget--) { s->failed_pc=0x0c048390u; return 0; }
r[1]=r[8];
goto P_0c048392;
P_0c048392: /* original 340c, guest PC 0x0c048392 */
if(!s->budget--) { s->failed_pc=0x0c048392u; return 0; }
r[4]+=r[0];
goto P_0c048394;
P_0c048394: /* original 6846, guest PC 0x0c048394 */
if(!s->budget--) { s->failed_pc=0x0c048394u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[8]=tmp;
goto P_0c048396;
P_0c048396: /* original 2888, guest PC 0x0c048396 */
if(!s->budget--) { s->failed_pc=0x0c048396u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c048398;
P_0c048398: /* original 8b02, guest PC 0x0c048398 */
if(!s->budget--) { s->failed_pc=0x0c048398u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0483a0; }
goto P_0c04839a;
P_0c04839a: /* original a0ef, guest PC 0x0c04839a */
if(!s->budget--) { s->failed_pc=0x0c04839au; return 0; }
goto P_0c04857c;
P_0c04839c: /* original 0009, guest PC 0x0c04839c */
if(!s->budget--) { s->failed_pc=0x0c04839cu; return 0; }
if(!vf3_matrix_family(0x0c04839eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04839eu; return 0; } return 1;
P_0c0483a0: /* original 69f3, guest PC 0x0c0483a0 */
if(!s->budget--) { s->failed_pc=0x0c0483a0u; return 0; }
r[9]=r[15];
goto P_0c0483a2;
P_0c0483a2: /* original 7918, guest PC 0x0c0483a2 */
if(!s->budget--) { s->failed_pc=0x0c0483a2u; return 0; }
r[9]+=0x00000018u;
goto P_0c0483a4;
P_0c0483a4: /* original f599, guest PC 0x0c0483a4 */
if(!s->budget--) { s->failed_pc=0x0c0483a4u; return 0; }
vf3_matrix_load(s,ram,5,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483a6;
P_0c0483a6: /* original f699, guest PC 0x0c0483a6 */
if(!s->budget--) { s->failed_pc=0x0c0483a6u; return 0; }
vf3_matrix_load(s,ram,6,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483a8;
P_0c0483a8: /* original 7208, guest PC 0x0c0483a8 */
if(!s->budget--) { s->failed_pc=0x0c0483a8u; return 0; }
r[2]+=0x00000008u;
goto P_0c0483aa;
P_0c0483aa: /* original f799, guest PC 0x0c0483aa */
if(!s->budget--) { s->failed_pc=0x0c0483aau; return 0; }
vf3_matrix_load(s,ram,7,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ac;
P_0c0483ac: /* original 6026, guest PC 0x0c0483ac */
if(!s->budget--) { s->failed_pc=0x0c0483acu; return 0; }
tmp=read(ram,r[2],4);
r[2]+=4;
r[0]=tmp;
goto P_0c0483ae;
P_0c0483ae: /* original c801, guest PC 0x0c0483ae */
if(!s->budget--) { s->failed_pc=0x0c0483aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0483b0;
P_0c0483b0: /* original 6013, guest PC 0x0c0483b0 */
if(!s->budget--) { s->failed_pc=0x0c0483b0u; return 0; }
r[0]=r[1];
goto P_0c0483b2;
P_0c0483b2: /* original 8f24, guest PC 0x0c0483b2 */
if(!s->budget--) { s->failed_pc=0x0c0483b2u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!cond) { goto P_0c0483fe; }
goto P_0c0483b6;
P_0c0483b4: /* original c820, guest PC 0x0c0483b4 */
if(!s->budget--) { s->failed_pc=0x0c0483b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0483b6;
P_0c0483b6: /* original 8922, guest PC 0x0c0483b6 */
if(!s->budget--) { s->failed_pc=0x0c0483b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0483fe; }
goto P_0c0483b8;
P_0c0483b8: /* original f029, guest PC 0x0c0483b8 */
if(!s->budget--) { s->failed_pc=0x0c0483b8u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ba;
P_0c0483ba: /* original f129, guest PC 0x0c0483ba */
if(!s->budget--) { s->failed_pc=0x0c0483bau; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483bc;
P_0c0483bc: /* original f229, guest PC 0x0c0483bc */
if(!s->budget--) { s->failed_pc=0x0c0483bcu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483be;
P_0c0483be: /* original f329, guest PC 0x0c0483be */
if(!s->budget--) { s->failed_pc=0x0c0483beu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483c0;
P_0c0483c0: /* original f0b2, guest PC 0x0c0483c0 */
if(!s->budget--) { s->failed_pc=0x0c0483c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c0483c2;
P_0c0483c2: /* original fb5c, guest PC 0x0c0483c2 */
if(!s->budget--) { s->failed_pc=0x0c0483c2u; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c0483c4;
P_0c0483c4: /* original f152, guest PC 0x0c0483c4 */
if(!s->budget--) { s->failed_pc=0x0c0483c4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c0483c6;
P_0c0483c6: /* original f429, guest PC 0x0c0483c6 */
if(!s->budget--) { s->failed_pc=0x0c0483c6u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483c8;
P_0c0483c8: /* original f529, guest PC 0x0c0483c8 */
if(!s->budget--) { s->failed_pc=0x0c0483c8u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ca;
P_0c0483ca: /* original f5b2, guest PC 0x0c0483ca */
if(!s->budget--) { s->failed_pc=0x0c0483cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c0483cc;
P_0c0483cc: /* original fb6c, guest PC 0x0c0483cc */
if(!s->budget--) { s->failed_pc=0x0c0483ccu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c0483ce;
P_0c0483ce: /* original f262, guest PC 0x0c0483ce */
if(!s->budget--) { s->failed_pc=0x0c0483ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0483d0;
P_0c0483d0: /* original f629, guest PC 0x0c0483d0 */
if(!s->budget--) { s->failed_pc=0x0c0483d0u; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483d2;
P_0c0483d2: /* original f6b2, guest PC 0x0c0483d2 */
if(!s->budget--) { s->failed_pc=0x0c0483d2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c0483d4;
P_0c0483d4: /* original fb7c, guest PC 0x0c0483d4 */
if(!s->budget--) { s->failed_pc=0x0c0483d4u; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c0483d6;
P_0c0483d6: /* original f372, guest PC 0x0c0483d6 */
if(!s->budget--) { s->failed_pc=0x0c0483d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0483d8;
P_0c0483d8: /* original f729, guest PC 0x0c0483d8 */
if(!s->budget--) { s->failed_pc=0x0c0483d8u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483da;
P_0c0483da: /* original f3fd, guest PC 0x0c0483da */
if(!s->budget--) { s->failed_pc=0x0c0483dau; return 0; }
r[18]^=0x100000u;
goto P_0c0483dc;
P_0c0483dc: /* original f7b2, guest PC 0x0c0483dc */
if(!s->budget--) { s->failed_pc=0x0c0483dcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c0483de;
P_0c0483de: /* original e000, guest PC 0x0c0483de */
if(!s->budget--) { s->failed_pc=0x0c0483deu; return 0; }
r[0]=0x00000000u;
goto P_0c0483e0;
P_0c0483e0: /* original 1601, guest PC 0x0c0483e0 */
if(!s->budget--) { s->failed_pc=0x0c0483e0u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0483e2;
P_0c0483e2: /* original 1602, guest PC 0x0c0483e2 */
if(!s->budget--) { s->failed_pc=0x0c0483e2u; return 0; }
write(ram,r[6]+8,r[0],4);
goto P_0c0483e4;
P_0c0483e4: /* original 1603, guest PC 0x0c0483e4 */
if(!s->budget--) { s->failed_pc=0x0c0483e4u; return 0; }
write(ram,r[6]+12,r[0],4);
goto P_0c0483e6;
P_0c0483e6: /* original 0683, guest PC 0x0c0483e6 */
if(!s->budget--) { s->failed_pc=0x0c0483e6u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c0483e8;
P_0c0483e8: /* original 7640, guest PC 0x0c0483e8 */
if(!s->budget--) { s->failed_pc=0x0c0483e8u; return 0; }
r[6]+=0x00000040u;
goto P_0c0483ea;
P_0c0483ea: /* original f66b, guest PC 0x0c0483ea */
if(!s->budget--) { s->failed_pc=0x0c0483eau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c0483ec;
P_0c0483ec: /* original f64b, guest PC 0x0c0483ec */
if(!s->budget--) { s->failed_pc=0x0c0483ecu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0483ee;
P_0c0483ee: /* original 60b3, guest PC 0x0c0483ee */
if(!s->budget--) { s->failed_pc=0x0c0483eeu; return 0; }
r[0]=r[11];
goto P_0c0483f0;
P_0c0483f0: /* original f62b, guest PC 0x0c0483f0 */
if(!s->budget--) { s->failed_pc=0x0c0483f0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0483f2;
P_0c0483f2: /* original 7540, guest PC 0x0c0483f2 */
if(!s->budget--) { s->failed_pc=0x0c0483f2u; return 0; }
r[5]+=0x00000040u;
goto P_0c0483f4;
P_0c0483f4: /* original f60b, guest PC 0x0c0483f4 */
if(!s->budget--) { s->failed_pc=0x0c0483f4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c0483f6;
P_0c0483f6: /* original f3fd, guest PC 0x0c0483f6 */
if(!s->budget--) { s->failed_pc=0x0c0483f6u; return 0; }
r[18]^=0x100000u;
goto P_0c0483f8;
P_0c0483f8: /* original 0683, guest PC 0x0c0483f8 */
if(!s->budget--) { s->failed_pc=0x0c0483f8u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c0483fa;
P_0c0483fa: /* original 7620, guest PC 0x0c0483fa */
if(!s->budget--) { s->failed_pc=0x0c0483fau; return 0; }
r[6]+=0x00000020u;
goto P_0c0483fc;
P_0c0483fc: /* original 0a56, guest PC 0x0c0483fc */
if(!s->budget--) { s->failed_pc=0x0c0483fcu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0483fe;
P_0c0483fe: /* original 6146, guest PC 0x0c0483fe */
if(!s->budget--) { s->failed_pc=0x0c0483feu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c048400;
P_0c048400: /* original f249, guest PC 0x0c048400 */
if(!s->budget--) { s->failed_pc=0x0c048400u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048402;
P_0c048402: /* original af75, guest PC 0x0c048402 */
if(!s->budget--) { s->failed_pc=0x0c048402u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c048404: /* original f349, guest PC 0x0c048404 */
if(!s->budget--) { s->failed_pc=0x0c048404u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c048406u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c048406u; return 0; } return 1;
P_0c048408: /* original f139, guest PC 0x0c048408 */
if(!s->budget--) { s->failed_pc=0x0c048408u; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04840a;
P_0c04840a: /* original 7910, guest PC 0x0c04840a */
if(!s->budget--) { s->failed_pc=0x0c04840au; return 0; }
r[9]+=0x00000010u;
goto P_0c04840c;
P_0c04840c: /* original f04d, guest PC 0x0c04840c */
if(!s->budget--) { s->failed_pc=0x0c04840cu; return 0; }
fr[0]^=0x80000000u;
goto P_0c04840e;
P_0c04840e: /* original f102, guest PC 0x0c04840e */
if(!s->budget--) { s->failed_pc=0x0c04840eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c048410;
P_0c048410: /* original f93b, guest PC 0x0c048410 */
if(!s->budget--) { s->failed_pc=0x0c048410u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c048412;
P_0c048412: /* original 6243, guest PC 0x0c048412 */
if(!s->budget--) { s->failed_pc=0x0c048412u; return 0; }
r[2]=r[4];
goto P_0c048414;
P_0c048414: /* original f339, guest PC 0x0c048414 */
if(!s->budget--) { s->failed_pc=0x0c048414u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048416;
P_0c048416: /* original f515, guest PC 0x0c048416 */
if(!s->budget--) { s->failed_pc=0x0c048416u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[1]))!=0);
goto P_0c048418;
P_0c048418: /* original f92b, guest PC 0x0c048418 */
if(!s->budget--) { s->failed_pc=0x0c048418u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[9]);
goto P_0c04841a;
P_0c04841a: /* original f302, guest PC 0x0c04841a */
if(!s->budget--) { s->failed_pc=0x0c04841au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c04841c;
P_0c04841c: /* original f039, guest PC 0x0c04841c */
if(!s->budget--) { s->failed_pc=0x0c04841cu; return 0; }
vf3_matrix_load(s,ram,0,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04841e;
P_0c04841e: /* original 8fb3, guest PC 0x0c04841e */
if(!s->budget--) { s->failed_pc=0x0c04841eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
if(!cond) { goto P_0c048388; }
goto P_0c048422;
P_0c048420: /* original f635, guest PC 0x0c048420 */
if(!s->budget--) { s->failed_pc=0x0c048420u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
goto P_0c048422;
P_0c048422: /* original f739, guest PC 0x0c048422 */
if(!s->budget--) { s->failed_pc=0x0c048422u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048424;
P_0c048424: /* original f042, guest PC 0x0c048424 */
if(!s->budget--) { s->failed_pc=0x0c048424u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c048426;
P_0c048426: /* original 5022, guest PC 0x0c048426 */
if(!s->budget--) { s->failed_pc=0x0c048426u; return 0; }
r[0]=read(ram,r[2]+8,4);
goto P_0c048428;
P_0c048428: /* original f011, guest PC 0x0c048428 */
if(!s->budget--) { s->failed_pc=0x0c048428u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c04842a;
P_0c04842a: /* original 8fad, guest PC 0x0c04842a */
if(!s->budget--) { s->failed_pc=0x0c04842au; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
if(!cond) { goto P_0c048388; }
goto P_0c04842e;
P_0c04842c: /* original f505, guest PC 0x0c04842c */
if(!s->budget--) { s->failed_pc=0x0c04842cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
goto P_0c04842e;
P_0c04842e: /* original f539, guest PC 0x0c04842e */
if(!s->budget--) { s->failed_pc=0x0c04842eu; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048430;
P_0c048430: /* original f742, guest PC 0x0c048430 */
if(!s->budget--) { s->failed_pc=0x0c048430u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c048432;
P_0c048432: /* original 8da9, guest PC 0x0c048432 */
if(!s->budget--) { s->failed_pc=0x0c048432u; return 0; }
cond=r[17]&1u;
tmp=r[1]; r[9]-=4; write(ram,r[9],tmp,4);
if(cond) { goto P_0c048388; }
goto P_0c048436;
P_0c048434: /* original 2916, guest PC 0x0c048434 */
if(!s->budget--) { s->failed_pc=0x0c048434u; return 0; }
tmp=r[1]; r[9]-=4; write(ram,r[9],tmp,4);
goto P_0c048436;
P_0c048436: /* original f731, guest PC 0x0c048436 */
if(!s->budget--) { s->failed_pc=0x0c048436u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c048438;
P_0c048438: /* original 2986, guest PC 0x0c048438 */
if(!s->budget--) { s->failed_pc=0x0c048438u; return 0; }
tmp=r[8]; r[9]-=4; write(ram,r[9],tmp,4);
goto P_0c04843a;
P_0c04843a: /* original e108, guest PC 0x0c04843a */
if(!s->budget--) { s->failed_pc=0x0c04843au; return 0; }
r[1]=0x00000008u;
goto P_0c04843c;
P_0c04843c: /* original f675, guest PC 0x0c04843c */
if(!s->budget--) { s->failed_pc=0x0c04843cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c04843e;
P_0c04843e: /* original f639, guest PC 0x0c04843e */
if(!s->budget--) { s->failed_pc=0x0c04843eu; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048440;
P_0c048440: /* original 89a2, guest PC 0x0c048440 */
if(!s->budget--) { s->failed_pc=0x0c048440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c048388; }
goto P_0c048442;
P_0c048442: /* original c801, guest PC 0x0c048442 */
if(!s->budget--) { s->failed_pc=0x0c048442u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c048444;
P_0c048444: /* original 8424, guest PC 0x0c048444 */
if(!s->budget--) { s->failed_pc=0x0c048444u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+4,1);
goto P_0c048446;
P_0c048446: /* original 7208, guest PC 0x0c048446 */
if(!s->budget--) { s->failed_pc=0x0c048446u; return 0; }
r[2]+=0x00000008u;
goto P_0c048448;
P_0c048448: /* original f739, guest PC 0x0c048448 */
if(!s->budget--) { s->failed_pc=0x0c048448u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04844a;
P_0c04844a: /* original 6803, guest PC 0x0c04844a */
if(!s->budget--) { s->failed_pc=0x0c04844au; return 0; }
r[8]=r[0];
goto P_0c04844c;
P_0c04844c: /* original ff29, guest PC 0x0c04844c */
if(!s->budget--) { s->failed_pc=0x0c04844cu; return 0; }
vf3_matrix_load(s,ram,15,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04844e;
P_0c04844e: /* original 8f1a, guest PC 0x0c04844e */
if(!s->budget--) { s->failed_pc=0x0c04844eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000030u;
if(!cond) { goto P_0c048486; }
goto P_0c048452;
P_0c048450: /* original 7430, guest PC 0x0c048450 */
if(!s->budget--) { s->failed_pc=0x0c048450u; return 0; }
r[4]+=0x00000030u;
goto P_0c048452;
P_0c048452: /* original f029, guest PC 0x0c048452 */
if(!s->budget--) { s->failed_pc=0x0c048452u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048454;
P_0c048454: /* original f129, guest PC 0x0c048454 */
if(!s->budget--) { s->failed_pc=0x0c048454u; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048456;
P_0c048456: /* original f229, guest PC 0x0c048456 */
if(!s->budget--) { s->failed_pc=0x0c048456u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048458;
P_0c048458: /* original f329, guest PC 0x0c048458 */
if(!s->budget--) { s->failed_pc=0x0c048458u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04845a;
P_0c04845a: /* original f0b2, guest PC 0x0c04845a */
if(!s->budget--) { s->failed_pc=0x0c04845au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c04845c;
P_0c04845c: /* original fb5c, guest PC 0x0c04845c */
if(!s->budget--) { s->failed_pc=0x0c04845cu; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c04845e;
P_0c04845e: /* original f152, guest PC 0x0c04845e */
if(!s->budget--) { s->failed_pc=0x0c04845eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c048460;
P_0c048460: /* original f429, guest PC 0x0c048460 */
if(!s->budget--) { s->failed_pc=0x0c048460u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048462;
P_0c048462: /* original f529, guest PC 0x0c048462 */
if(!s->budget--) { s->failed_pc=0x0c048462u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048464;
P_0c048464: /* original f5b2, guest PC 0x0c048464 */
if(!s->budget--) { s->failed_pc=0x0c048464u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c048466;
P_0c048466: /* original fb6c, guest PC 0x0c048466 */
if(!s->budget--) { s->failed_pc=0x0c048466u; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c048468;
P_0c048468: /* original f262, guest PC 0x0c048468 */
if(!s->budget--) { s->failed_pc=0x0c048468u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c04846a;
P_0c04846a: /* original f629, guest PC 0x0c04846a */
if(!s->budget--) { s->failed_pc=0x0c04846au; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04846c;
P_0c04846c: /* original f6b2, guest PC 0x0c04846c */
if(!s->budget--) { s->failed_pc=0x0c04846cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c04846e;
P_0c04846e: /* original fb7c, guest PC 0x0c04846e */
if(!s->budget--) { s->failed_pc=0x0c04846eu; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c048470;
P_0c048470: /* original f372, guest PC 0x0c048470 */
if(!s->budget--) { s->failed_pc=0x0c048470u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c048472;
P_0c048472: /* original f729, guest PC 0x0c048472 */
if(!s->budget--) { s->failed_pc=0x0c048472u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048474;
P_0c048474: /* original 7640, guest PC 0x0c048474 */
if(!s->budget--) { s->failed_pc=0x0c048474u; return 0; }
r[6]+=0x00000040u;
goto P_0c048476;
P_0c048476: /* original f7b2, guest PC 0x0c048476 */
if(!s->budget--) { s->failed_pc=0x0c048476u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c048478;
P_0c048478: /* original f3fd, guest PC 0x0c048478 */
if(!s->budget--) { s->failed_pc=0x0c048478u; return 0; }
r[18]^=0x100000u;
goto P_0c04847a;
P_0c04847a: /* original f66b, guest PC 0x0c04847a */
if(!s->budget--) { s->failed_pc=0x0c04847au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04847c;
P_0c04847c: /* original f64b, guest PC 0x0c04847c */
if(!s->budget--) { s->failed_pc=0x0c04847cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04847e;
P_0c04847e: /* original f62b, guest PC 0x0c04847e */
if(!s->budget--) { s->failed_pc=0x0c04847eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048480;
P_0c048480: /* original f60b, guest PC 0x0c048480 */
if(!s->budget--) { s->failed_pc=0x0c048480u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c048482;
P_0c048482: /* original f3fd, guest PC 0x0c048482 */
if(!s->budget--) { s->failed_pc=0x0c048482u; return 0; }
r[18]^=0x100000u;
goto P_0c048484;
P_0c048484: /* original 76e0, guest PC 0x0c048484 */
if(!s->budget--) { s->failed_pc=0x0c048484u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c048486;
P_0c048486: /* original 4811, guest PC 0x0c048486 */
if(!s->budget--) { s->failed_pc=0x0c048486u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=0)!=0);
goto P_0c048488;
P_0c048488: /* original 4d5a, guest PC 0x0c048488 */
if(!s->budget--) { s->failed_pc=0x0c048488u; return 0; }
r[53]=r[13];
goto P_0c04848a;
P_0c04848a: /* original 891b, guest PC 0x0c04848a */
if(!s->budget--) { s->failed_pc=0x0c04848au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0484c4; }
goto P_0c04848c;
P_0c04848c: /* original 6083, guest PC 0x0c04848c */
if(!s->budget--) { s->failed_pc=0x0c04848cu; return 0; }
r[0]=r[8];
goto P_0c04848e;
P_0c04848e: /* original 88ff, guest PC 0x0c04848e */
if(!s->budget--) { s->failed_pc=0x0c04848eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c048490;
P_0c048490: /* original 8d14, guest PC 0x0c048490 */
if(!s->budget--) { s->failed_pc=0x0c048490u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
if(cond) { goto P_0c0484bc; }
goto P_0c048494;
P_0c048492: /* original 88fe, guest PC 0x0c048492 */
if(!s->budget--) { s->failed_pc=0x0c048492u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c048494;
P_0c048494: /* original 8b08, guest PC 0x0c048494 */
if(!s->budget--) { s->failed_pc=0x0c048494u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0484a8; }
goto P_0c048496;
P_0c048496: /* original d052, guest PC 0x0c048496 */
if(!s->budget--) { s->failed_pc=0x0c048496u; return 0; }
r[0]=read(ram,0x0c0485e0u,4);
goto P_0c048498;
P_0c048498: /* original 400b, guest PC 0x0c048498 */
if(!s->budget--) { s->failed_pc=0x0c048498u; return 0; }
target=r[0];
r[16]=code_base|0x0c04849cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04849cu) { target=s->pc; goto dispatch; }
goto P_0c04849c;
P_0c04849a: /* original 0009, guest PC 0x0c04849a */
if(!s->budget--) { s->failed_pc=0x0c04849au; return 0; }
goto P_0c04849c;
P_0c04849c: /* original 896e, guest PC 0x0c04849c */
if(!s->budget--) { s->failed_pc=0x0c04849cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c04849e;
P_0c04849e: /* original 6146, guest PC 0x0c04849e */
if(!s->budget--) { s->failed_pc=0x0c04849eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484a0;
P_0c0484a0: /* original f249, guest PC 0x0c0484a0 */
if(!s->budget--) { s->failed_pc=0x0c0484a0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484a2;
P_0c0484a2: /* original af25, guest PC 0x0c0484a2 */
if(!s->budget--) { s->failed_pc=0x0c0484a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484a4: /* original f349, guest PC 0x0c0484a4 */
if(!s->budget--) { s->failed_pc=0x0c0484a4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c0484a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0484a6u; return 0; } return 1;
P_0c0484a8: /* original 88fd, guest PC 0x0c0484a8 */
if(!s->budget--) { s->failed_pc=0x0c0484a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffdu)!=0);
goto P_0c0484aa;
P_0c0484aa: /* original 8b07, guest PC 0x0c0484aa */
if(!s->budget--) { s->failed_pc=0x0c0484aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0484bc; }
goto P_0c0484ac;
P_0c0484ac: /* original d04d, guest PC 0x0c0484ac */
if(!s->budget--) { s->failed_pc=0x0c0484acu; return 0; }
r[0]=read(ram,0x0c0485e4u,4);
goto P_0c0484ae;
P_0c0484ae: /* original 400b, guest PC 0x0c0484ae */
if(!s->budget--) { s->failed_pc=0x0c0484aeu; return 0; }
target=r[0];
r[16]=code_base|0x0c0484b2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0484b2u) { target=s->pc; goto dispatch; }
goto P_0c0484b2;
P_0c0484b0: /* original 0009, guest PC 0x0c0484b0 */
if(!s->budget--) { s->failed_pc=0x0c0484b0u; return 0; }
goto P_0c0484b2;
P_0c0484b2: /* original 8963, guest PC 0x0c0484b2 */
if(!s->budget--) { s->failed_pc=0x0c0484b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c0484b4;
P_0c0484b4: /* original 6146, guest PC 0x0c0484b4 */
if(!s->budget--) { s->failed_pc=0x0c0484b4u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484b6;
P_0c0484b6: /* original f249, guest PC 0x0c0484b6 */
if(!s->budget--) { s->failed_pc=0x0c0484b6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484b8;
P_0c0484b8: /* original af1a, guest PC 0x0c0484b8 */
if(!s->budget--) { s->failed_pc=0x0c0484b8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484ba: /* original f349, guest PC 0x0c0484ba */
if(!s->budget--) { s->failed_pc=0x0c0484bau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484bc;
P_0c0484bc: /* original e800, guest PC 0x0c0484bc */
if(!s->budget--) { s->failed_pc=0x0c0484bcu; return 0; }
r[8]=0x00000000u;
goto P_0c0484be;
P_0c0484be: /* original a00b, guest PC 0x0c0484be */
if(!s->budget--) { s->failed_pc=0x0c0484beu; return 0; }
fr[15]=0x3f800000u;
goto P_0c0484d8;
P_0c0484c0: /* original ff9d, guest PC 0x0c0484c0 */
if(!s->budget--) { s->failed_pc=0x0c0484c0u; return 0; }
fr[15]=0x3f800000u;
if(!vf3_matrix_family(0x0c0484c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0484c2u; return 0; } return 1;
P_0c0484c4: /* original 3817, guest PC 0x0c0484c4 */
if(!s->budget--) { s->failed_pc=0x0c0484c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>(int32_t)r[1])!=0);
goto P_0c0484c6;
P_0c0484c6: /* original f10d, guest PC 0x0c0484c6 */
if(!s->budget--) { s->failed_pc=0x0c0484c6u; return 0; }
fr[1]=r[53];
goto P_0c0484c8;
P_0c0484c8: /* original 4808, guest PC 0x0c0484c8 */
if(!s->budget--) { s->failed_pc=0x0c0484c8u; return 0; }
r[8]<<=2;
goto P_0c0484ca;
P_0c0484ca: /* original 8f05, guest PC 0x0c0484ca */
if(!s->budget--) { s->failed_pc=0x0c0484cau; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
if(!cond) { goto P_0c0484d8; }
goto P_0c0484ce;
P_0c0484cc: /* original ff12, guest PC 0x0c0484cc */
if(!s->budget--) { s->failed_pc=0x0c0484ccu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
goto P_0c0484ce;
P_0c0484ce: /* original 6083, guest PC 0x0c0484ce */
if(!s->budget--) { s->failed_pc=0x0c0484ceu; return 0; }
r[0]=r[8];
goto P_0c0484d0;
P_0c0484d0: /* original 8840, guest PC 0x0c0484d0 */
if(!s->budget--) { s->failed_pc=0x0c0484d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0484d2;
P_0c0484d2: /* original e824, guest PC 0x0c0484d2 */
if(!s->budget--) { s->failed_pc=0x0c0484d2u; return 0; }
r[8]=0x00000024u;
goto P_0c0484d4;
P_0c0484d4: /* original 8900, guest PC 0x0c0484d4 */
if(!s->budget--) { s->failed_pc=0x0c0484d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0484d8; }
goto P_0c0484d6;
P_0c0484d6: /* original e828, guest PC 0x0c0484d6 */
if(!s->budget--) { s->failed_pc=0x0c0484d6u; return 0; }
r[8]=0x00000028u;
goto P_0c0484d8;
P_0c0484d8: /* original 6046, guest PC 0x0c0484d8 */
if(!s->budget--) { s->failed_pc=0x0c0484d8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0484da: /* original 4015, guest PC 0x0c0484da */
if(!s->budget--) { s->failed_pc=0x0c0484dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0484dc;
P_0c0484dc: /* original 59f9, guest PC 0x0c0484dc */
if(!s->budget--) { s->failed_pc=0x0c0484dcu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c0484de;
P_0c0484de: /* original 8d09, guest PC 0x0c0484de */
if(!s->budget--) { s->failed_pc=0x0c0484deu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
if(cond) { goto P_0c0484f4; }
goto P_0c0484e2;
P_0c0484e0: /* original 4011, guest PC 0x0c0484e0 */
if(!s->budget--) { s->failed_pc=0x0c0484e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0484e2;
P_0c0484e2: /* original 6803, guest PC 0x0c0484e2 */
if(!s->budget--) { s->failed_pc=0x0c0484e2u; return 0; }
r[8]=r[0];
goto P_0c0484e4;
P_0c0484e4: /* original 60b3, guest PC 0x0c0484e4 */
if(!s->budget--) { s->failed_pc=0x0c0484e4u; return 0; }
r[0]=r[11];
goto P_0c0484e6;
P_0c0484e6: /* original 0a56, guest PC 0x0c0484e6 */
if(!s->budget--) { s->failed_pc=0x0c0484e6u; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0484e8;
P_0c0484e8: /* original 8948, guest PC 0x0c0484e8 */
if(!s->budget--) { s->failed_pc=0x0c0484e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c0484ea;
P_0c0484ea: /* original 6146, guest PC 0x0c0484ea */
if(!s->budget--) { s->failed_pc=0x0c0484eau; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484ec;
P_0c0484ec: /* original f249, guest PC 0x0c0484ec */
if(!s->budget--) { s->failed_pc=0x0c0484ecu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484ee;
P_0c0484ee: /* original aeff, guest PC 0x0c0484ee */
if(!s->budget--) { s->failed_pc=0x0c0484eeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484f0: /* original f349, guest PC 0x0c0484f0 */
if(!s->budget--) { s->failed_pc=0x0c0484f0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c0484f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0484f2u; return 0; } return 1;
P_0c0484f4: /* original 6103, guest PC 0x0c0484f4 */
if(!s->budget--) { s->failed_pc=0x0c0484f4u; return 0; }
r[1]=r[0];
goto P_0c0484f6;
P_0c0484f6: /* original e2fb, guest PC 0x0c0484f6 */
if(!s->budget--) { s->failed_pc=0x0c0484f6u; return 0; }
r[2]=0xfffffffbu;
goto P_0c0484f8;
P_0c0484f8: /* original 6396, guest PC 0x0c0484f8 */
if(!s->budget--) { s->failed_pc=0x0c0484f8u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[3]=tmp;
goto P_0c0484fa;
P_0c0484fa: /* original c940, guest PC 0x0c0484fa */
if(!s->budget--) { s->failed_pc=0x0c0484fau; return 0; }
r[0]&=64u;
goto P_0c0484fc;
P_0c0484fc: /* original 402d, guest PC 0x0c0484fc */
if(!s->budget--) { s->failed_pc=0x0c0484fcu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c0484fe;
P_0c0484fe: /* original e2fd, guest PC 0x0c0484fe */
if(!s->budget--) { s->failed_pc=0x0c0484feu; return 0; }
r[2]=0xfffffffdu;
goto P_0c048500;
P_0c048500: /* original 2329, guest PC 0x0c048500 */
if(!s->budget--) { s->failed_pc=0x0c048500u; return 0; }
r[3]&=r[2];
goto P_0c048502;
P_0c048502: /* original 203b, guest PC 0x0c048502 */
if(!s->budget--) { s->failed_pc=0x0c048502u; return 0; }
r[0]|=r[3];
goto P_0c048504;
P_0c048504: /* original c810, guest PC 0x0c048504 */
if(!s->budget--) { s->failed_pc=0x0c048504u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c048506;
P_0c048506: /* original 7420, guest PC 0x0c048506 */
if(!s->budget--) { s->failed_pc=0x0c048506u; return 0; }
r[4]+=0x00000020u;
goto P_0c048508;
P_0c048508: /* original 8f03, guest PC 0x0c048508 */
if(!s->budget--) { s->failed_pc=0x0c048508u; return 0; }
cond=r[17]&1u;
r[53]=r[0];
if(!cond) { goto P_0c048512; }
goto P_0c04850c;
P_0c04850a: /* original 405a, guest PC 0x0c04850a */
if(!s->budget--) { s->failed_pc=0x0c04850au; return 0; }
r[53]=r[0];
goto P_0c04850c;
P_0c04850c: /* original cb10, guest PC 0x0c04850c */
if(!s->budget--) { s->failed_pc=0x0c04850cu; return 0; }
r[0]|=16u;
goto P_0c04850e;
P_0c04850e: /* original 6293, guest PC 0x0c04850e */
if(!s->budget--) { s->failed_pc=0x0c04850eu; return 0; }
r[2]=r[9];
goto P_0c048510;
P_0c048510: /* original 2206, guest PC 0x0c048510 */
if(!s->budget--) { s->failed_pc=0x0c048510u; return 0; }
tmp=r[0]; r[2]-=4; write(ram,r[2],tmp,4);
goto P_0c048512;
P_0c048512: /* original 6013, guest PC 0x0c048512 */
if(!s->budget--) { s->failed_pc=0x0c048512u; return 0; }
r[0]=r[1];
goto P_0c048514;
P_0c048514: /* original e21b, guest PC 0x0c048514 */
if(!s->budget--) { s->failed_pc=0x0c048514u; return 0; }
r[2]=0x0000001bu;
goto P_0c048516;
P_0c048516: /* original c903, guest PC 0x0c048516 */
if(!s->budget--) { s->failed_pc=0x0c048516u; return 0; }
r[0]&=3u;
goto P_0c048518;
P_0c048518: /* original 402d, guest PC 0x0c048518 */
if(!s->budget--) { s->failed_pc=0x0c048518u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c04851a;
P_0c04851a: /* original e303, guest PC 0x0c04851a */
if(!s->budget--) { s->failed_pc=0x0c04851au; return 0; }
r[3]=0x00000003u;
goto P_0c04851c;
P_0c04851c: /* original f3fd, guest PC 0x0c04851c */
if(!s->budget--) { s->failed_pc=0x0c04851cu; return 0; }
r[18]^=0x100000u;
goto P_0c04851e;
P_0c04851e: /* original 432d, guest PC 0x0c04851e */
if(!s->budget--) { s->failed_pc=0x0c04851eu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c048520;
P_0c048520: /* original 0483, guest PC 0x0c048520 */
if(!s->budget--) { s->failed_pc=0x0c048520u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c048522;
P_0c048522: /* original 6337, guest PC 0x0c048522 */
if(!s->budget--) { s->failed_pc=0x0c048522u; return 0; }
r[3]=~r[3];
goto P_0c048524;
P_0c048524: /* original 6296, guest PC 0x0c048524 */
if(!s->budget--) { s->failed_pc=0x0c048524u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[2]=tmp;
goto P_0c048526;
P_0c048526: /* original 2239, guest PC 0x0c048526 */
if(!s->budget--) { s->failed_pc=0x0c048526u; return 0; }
r[2]&=r[3];
goto P_0c048528;
P_0c048528: /* original f00d, guest PC 0x0c048528 */
if(!s->budget--) { s->failed_pc=0x0c048528u; return 0; }
fr[0]=r[53];
goto P_0c04852a;
P_0c04852a: /* original 220b, guest PC 0x0c04852a */
if(!s->budget--) { s->failed_pc=0x0c04852au; return 0; }
r[2]|=r[0];
goto P_0c04852c;
P_0c04852c: /* original 425a, guest PC 0x0c04852c */
if(!s->budget--) { s->failed_pc=0x0c04852cu; return 0; }
r[53]=r[2];
goto P_0c04852e;
P_0c04852e: /* original 74e0, guest PC 0x0c04852e */
if(!s->budget--) { s->failed_pc=0x0c04852eu; return 0; }
r[4]+=0xffffffe0u;
goto P_0c048530;
P_0c048530: /* original f10d, guest PC 0x0c048530 */
if(!s->budget--) { s->failed_pc=0x0c048530u; return 0; }
fr[1]=r[53];
goto P_0c048532;
P_0c048532: /* original 7610, guest PC 0x0c048532 */
if(!s->budget--) { s->failed_pc=0x0c048532u; return 0; }
r[6]+=0x00000010u;
goto P_0c048534;
P_0c048534: /* original f299, guest PC 0x0c048534 */
if(!s->budget--) { s->failed_pc=0x0c048534u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c048536;
P_0c048536: /* original f62b, guest PC 0x0c048536 */
if(!s->budget--) { s->failed_pc=0x0c048536u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048538;
P_0c048538: /* original 7520, guest PC 0x0c048538 */
if(!s->budget--) { s->failed_pc=0x0c048538u; return 0; }
r[5]+=0x00000020u;
goto P_0c04853a;
P_0c04853a: /* original f60b, guest PC 0x0c04853a */
if(!s->budget--) { s->failed_pc=0x0c04853au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c04853c;
P_0c04853c: /* original f3fd, guest PC 0x0c04853c */
if(!s->budget--) { s->failed_pc=0x0c04853cu; return 0; }
r[18]^=0x100000u;
goto P_0c04853e;
P_0c04853e: /* original 0683, guest PC 0x0c04853e */
if(!s->budget--) { s->failed_pc=0x0c04853eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c048540;
P_0c048540: /* original 8f03, guest PC 0x0c048540 */
if(!s->budget--) { s->failed_pc=0x0c048540u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000020u;
if(!cond) { goto P_0c04854a; }
goto P_0c048544;
P_0c048542: /* original 7620, guest PC 0x0c048542 */
if(!s->budget--) { s->failed_pc=0x0c048542u; return 0; }
r[6]+=0x00000020u;
goto P_0c048544;
P_0c048544: /* original 0683, guest PC 0x0c048544 */
if(!s->budget--) { s->failed_pc=0x0c048544u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c048546;
P_0c048546: /* original 7620, guest PC 0x0c048546 */
if(!s->budget--) { s->failed_pc=0x0c048546u; return 0; }
r[6]+=0x00000020u;
goto P_0c048548;
P_0c048548: /* original 7520, guest PC 0x0c048548 */
if(!s->budget--) { s->failed_pc=0x0c048548u; return 0; }
r[5]+=0x00000020u;
goto P_0c04854a;
P_0c04854a: /* original 4c25, guest PC 0x0c04854a */
if(!s->budget--) { s->failed_pc=0x0c04854au; return 0; }
tmp=r[12]&1u; r[12]=(r[12]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04854c;
P_0c04854c: /* original 6013, guest PC 0x0c04854c */
if(!s->budget--) { s->failed_pc=0x0c04854cu; return 0; }
r[0]=r[1];
goto P_0c04854e;
P_0c04854e: /* original 8d25, guest PC 0x0c04854e */
if(!s->budget--) { s->failed_pc=0x0c04854eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
if(cond) { goto P_0c04859c; }
goto P_0c048552;
P_0c048550: /* original 4c00, guest PC 0x0c048550 */
if(!s->budget--) { s->failed_pc=0x0c048550u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c048552;
P_0c048552: /* original c808, guest PC 0x0c048552 */
if(!s->budget--) { s->failed_pc=0x0c048552u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c048554;
P_0c048554: /* original 8f0e, guest PC 0x0c048554 */
if(!s->budget--) { s->failed_pc=0x0c048554u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
if(!cond) { goto P_0c048574; }
goto P_0c048558;
P_0c048556: /* original c804, guest PC 0x0c048556 */
if(!s->budget--) { s->failed_pc=0x0c048556u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c048558;
P_0c048558: /* original 8b08, guest PC 0x0c048558 */
if(!s->budget--) { s->failed_pc=0x0c048558u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04856c; }
goto P_0c04855a;
P_0c04855a: /* original b121, guest PC 0x0c04855a */
if(!s->budget--) { s->failed_pc=0x0c04855au; return 0; }
target=code_base|0x0c0487a0u; r[16]=code_base|0x0c04855eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04855eu) { target=s->pc; goto dispatch; }
goto P_0c04855e;
P_0c04855c: /* original 0009, guest PC 0x0c04855c */
if(!s->budget--) { s->failed_pc=0x0c04855cu; return 0; }
goto P_0c04855e;
P_0c04855e: /* original afbc, guest PC 0x0c04855e */
if(!s->budget--) { s->failed_pc=0x0c04855eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c048560: /* original 6046, guest PC 0x0c048560 */
if(!s->budget--) { s->failed_pc=0x0c048560u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
if(!vf3_matrix_family(0x0c048562u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c048562u; return 0; } return 1;
P_0c04856c: /* original b048, guest PC 0x0c04856c */
if(!s->budget--) { s->failed_pc=0x0c04856cu; return 0; }
target=code_base|0x0c048600u; r[16]=code_base|0x0c048570u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c048570u) { target=s->pc; goto dispatch; }
goto P_0c048570;
P_0c04856e: /* original 0009, guest PC 0x0c04856e */
if(!s->budget--) { s->failed_pc=0x0c04856eu; return 0; }
goto P_0c048570;
P_0c048570: /* original afb3, guest PC 0x0c048570 */
if(!s->budget--) { s->failed_pc=0x0c048570u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c048572: /* original 6046, guest PC 0x0c048572 */
if(!s->budget--) { s->failed_pc=0x0c048572u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c048574;
P_0c048574: /* original b4f4, guest PC 0x0c048574 */
if(!s->budget--) { s->failed_pc=0x0c048574u; return 0; }
target=code_base|0x0c048f60u; r[16]=code_base|0x0c048578u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c048578u) { target=s->pc; goto dispatch; }
goto P_0c048578;
P_0c048576: /* original 0009, guest PC 0x0c048576 */
if(!s->budget--) { s->failed_pc=0x0c048576u; return 0; }
goto P_0c048578;
P_0c048578: /* original afaf, guest PC 0x0c048578 */
if(!s->budget--) { s->failed_pc=0x0c048578u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c04857a: /* original 6046, guest PC 0x0c04857a */
if(!s->budget--) { s->failed_pc=0x0c04857au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04857c;
P_0c04857c: /* original 7f28, guest PC 0x0c04857c */
if(!s->budget--) { s->failed_pc=0x0c04857cu; return 0; }
r[15]+=0x00000028u;
goto P_0c04857e;
P_0c04857e: /* original 4f26, guest PC 0x0c04857e */
if(!s->budget--) { s->failed_pc=0x0c04857eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c048580;
P_0c048580: /* original 68f6, guest PC 0x0c048580 */
if(!s->budget--) { s->failed_pc=0x0c048580u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c048582;
P_0c048582: /* original 69f6, guest PC 0x0c048582 */
if(!s->budget--) { s->failed_pc=0x0c048582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c048584;
P_0c048584: /* original 6af6, guest PC 0x0c048584 */
if(!s->budget--) { s->failed_pc=0x0c048584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c048586;
P_0c048586: /* original 6bf6, guest PC 0x0c048586 */
if(!s->budget--) { s->failed_pc=0x0c048586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c048588;
P_0c048588: /* original 6cf6, guest PC 0x0c048588 */
if(!s->budget--) { s->failed_pc=0x0c048588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04858a;
P_0c04858a: /* original 6df6, guest PC 0x0c04858a */
if(!s->budget--) { s->failed_pc=0x0c04858au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04858c;
P_0c04858c: /* original 6ef6, guest PC 0x0c04858c */
if(!s->budget--) { s->failed_pc=0x0c04858cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04858e;
P_0c04858e: /* original fcf9, guest PC 0x0c04858e */
if(!s->budget--) { s->failed_pc=0x0c04858eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048590;
P_0c048590: /* original fdf9, guest PC 0x0c048590 */
if(!s->budget--) { s->failed_pc=0x0c048590u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048592;
P_0c048592: /* original fef9, guest PC 0x0c048592 */
if(!s->budget--) { s->failed_pc=0x0c048592u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048594;
P_0c048594: /* original fff9, guest PC 0x0c048594 */
if(!s->budget--) { s->failed_pc=0x0c048594u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048596;
P_0c048596: /* original 000b, guest PC 0x0c048596 */
if(!s->budget--) { s->failed_pc=0x0c048596u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c048598: /* original 0009, guest PC 0x0c048598 */
if(!s->budget--) { s->failed_pc=0x0c048598u; return 0; }
if(!vf3_matrix_family(0x0c04859au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04859au; return 0; } return 1;
P_0c04859c: /* original e100, guest PC 0x0c04859c */
if(!s->budget--) { s->failed_pc=0x0c04859cu; return 0; }
r[1]=0x00000000u;
goto P_0c04859e;
P_0c04859e: /* original c840, guest PC 0x0c04859e */
if(!s->budget--) { s->failed_pc=0x0c04859eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0485a0;
P_0c0485a0: /* original 3c1e, guest PC 0x0c0485a0 */
if(!s->budget--) { s->failed_pc=0x0c0485a0u; return 0; }
wide=(uint64_t)r[12]+r[1]+(r[17]&1u); r[12]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0485a2;
P_0c0485a2: /* original c810, guest PC 0x0c0485a2 */
if(!s->budget--) { s->failed_pc=0x0c0485a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0485a4;
P_0c0485a4: /* original 8d04, guest PC 0x0c0485a4 */
if(!s->budget--) { s->failed_pc=0x0c0485a4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
if(cond) { goto P_0c0485b0; }
goto P_0c0485a8;
P_0c0485a6: /* original c808, guest PC 0x0c0485a6 */
if(!s->budget--) { s->failed_pc=0x0c0485a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0485a8;
P_0c0485a8: /* original b19a, guest PC 0x0c0485a8 */
if(!s->budget--) { s->failed_pc=0x0c0485a8u; return 0; }
target=code_base|0x0c0488e0u; r[16]=code_base|0x0c0485acu;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0485acu) { target=s->pc; goto dispatch; }
goto P_0c0485ac;
P_0c0485aa: /* original c820, guest PC 0x0c0485aa */
if(!s->budget--) { s->failed_pc=0x0c0485aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0485ac;
P_0c0485ac: /* original af95, guest PC 0x0c0485ac */
if(!s->budget--) { s->failed_pc=0x0c0485acu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0485ae: /* original 6046, guest PC 0x0c0485ae */
if(!s->budget--) { s->failed_pc=0x0c0485aeu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0485b0;
P_0c0485b0: /* original 8904, guest PC 0x0c0485b0 */
if(!s->budget--) { s->failed_pc=0x0c0485b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0485bc; }
goto P_0c0485b2;
P_0c0485b2: /* original b3d5, guest PC 0x0c0485b2 */
if(!s->budget--) { s->failed_pc=0x0c0485b2u; return 0; }
target=code_base|0x0c048d60u; r[16]=code_base|0x0c0485b6u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0485b6u) { target=s->pc; goto dispatch; }
goto P_0c0485b6;
P_0c0485b4: /* original c820, guest PC 0x0c0485b4 */
if(!s->budget--) { s->failed_pc=0x0c0485b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0485b6;
P_0c0485b6: /* original af90, guest PC 0x0c0485b6 */
if(!s->budget--) { s->failed_pc=0x0c0485b6u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0485b8: /* original 6046, guest PC 0x0c0485b8 */
if(!s->budget--) { s->failed_pc=0x0c0485b8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
if(!vf3_matrix_family(0x0c0485bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0485bau; return 0; } return 1;
P_0c0485bc: /* original affe, guest PC 0x0c0485bc */
if(!s->budget--) { s->failed_pc=0x0c0485bcu; return 0; }
goto P_0c0485bc;
P_0c0485be: /* original 0009, guest PC 0x0c0485be */
if(!s->budget--) { s->failed_pc=0x0c0485beu; return 0; }
if(!vf3_matrix_family(0x0c0485c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0485c0u; return 0; } return 1;
P_0c0490e8: /* original 4015, guest PC 0x0c0490e8 */
if(!s->budget--) { s->failed_pc=0x0c0490e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0490ea;
P_0c0490ea: /* original 59ff, guest PC 0x0c0490ea */
if(!s->budget--) { s->failed_pc=0x0c0490eau; return 0; }
r[9]=read(ram,r[15]+60,4);
goto P_0c0490ec;
P_0c0490ec: /* original 8d12, guest PC 0x0c0490ec */
if(!s->budget--) { s->failed_pc=0x0c0490ecu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
if(cond) { goto P_0c049114; }
goto P_0c0490f0;
P_0c0490ee: /* original 4011, guest PC 0x0c0490ee */
if(!s->budget--) { s->failed_pc=0x0c0490eeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0490f0;
P_0c0490f0: /* original 6803, guest PC 0x0c0490f0 */
if(!s->budget--) { s->failed_pc=0x0c0490f0u; return 0; }
r[8]=r[0];
goto P_0c0490f2;
P_0c0490f2: /* original 60b3, guest PC 0x0c0490f2 */
if(!s->budget--) { s->failed_pc=0x0c0490f2u; return 0; }
r[0]=r[11];
goto P_0c0490f4;
P_0c0490f4: /* original 0a56, guest PC 0x0c0490f4 */
if(!s->budget--) { s->failed_pc=0x0c0490f4u; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0490f6;
P_0c0490f6: /* original c706, guest PC 0x0c0490f6 */
if(!s->budget--) { s->failed_pc=0x0c0490f6u; return 0; }
r[0]=code_base|0x00049110u;
goto P_0c0490f8;
P_0c0490f8: /* original 4f26, guest PC 0x0c0490f8 */
if(!s->budget--) { s->failed_pc=0x0c0490f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0490fa;
P_0c0490fa: /* original f008, guest PC 0x0c0490fa */
if(!s->budget--) { s->failed_pc=0x0c0490fau; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c0490fc;
P_0c0490fc: /* original 6df6, guest PC 0x0c0490fc */
if(!s->budget--) { s->failed_pc=0x0c0490fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0490fe;
P_0c0490fe: /* original fc02, guest PC 0x0c0490fe */
if(!s->budget--) { s->failed_pc=0x0c0490feu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[0],r[18],'*');
goto P_0c049100;
P_0c049100: /* original f8f9, guest PC 0x0c049100 */
if(!s->budget--) { s->failed_pc=0x0c049100u; return 0; }
vf3_matrix_load(s,ram,8,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049102;
P_0c049102: /* original fd02, guest PC 0x0c049102 */
if(!s->budget--) { s->failed_pc=0x0c049102u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[0],r[18],'*');
goto P_0c049104;
P_0c049104: /* original f9f9, guest PC 0x0c049104 */
if(!s->budget--) { s->failed_pc=0x0c049104u; return 0; }
vf3_matrix_load(s,ram,9,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049106;
P_0c049106: /* original fe02, guest PC 0x0c049106 */
if(!s->budget--) { s->failed_pc=0x0c049106u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[0],r[18],'*');
goto P_0c049108;
P_0c049108: /* original faf9, guest PC 0x0c049108 */
if(!s->budget--) { s->failed_pc=0x0c049108u; return 0; }
vf3_matrix_load(s,ram,10,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c04910a;
P_0c04910a: /* original 000b, guest PC 0x0c04910a */
if(!s->budget--) { s->failed_pc=0x0c04910au; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c04910c: /* original fff9, guest PC 0x0c04910c */
if(!s->budget--) { s->failed_pc=0x0c04910cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c04910eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04910eu; return 0; } return 1;
P_0c049114: /* original 6103, guest PC 0x0c049114 */
if(!s->budget--) { s->failed_pc=0x0c049114u; return 0; }
r[1]=r[0];
goto P_0c049116;
P_0c049116: /* original 6396, guest PC 0x0c049116 */
if(!s->budget--) { s->failed_pc=0x0c049116u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[3]=tmp;
goto P_0c049118;
P_0c049118: /* original 7420, guest PC 0x0c049118 */
if(!s->budget--) { s->failed_pc=0x0c049118u; return 0; }
r[4]+=0x00000020u;
goto P_0c04911a;
P_0c04911a: /* original e21b, guest PC 0x0c04911a */
if(!s->budget--) { s->failed_pc=0x0c04911au; return 0; }
r[2]=0x0000001bu;
goto P_0c04911c;
P_0c04911c: /* original c903, guest PC 0x0c04911c */
if(!s->budget--) { s->failed_pc=0x0c04911cu; return 0; }
r[0]&=3u;
goto P_0c04911e;
P_0c04911e: /* original 435a, guest PC 0x0c04911e */
if(!s->budget--) { s->failed_pc=0x0c04911eu; return 0; }
r[53]=r[3];
goto P_0c049120;
P_0c049120: /* original 402d, guest PC 0x0c049120 */
if(!s->budget--) { s->failed_pc=0x0c049120u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c049122;
P_0c049122: /* original e303, guest PC 0x0c049122 */
if(!s->budget--) { s->failed_pc=0x0c049122u; return 0; }
r[3]=0x00000003u;
goto P_0c049124;
P_0c049124: /* original f3fd, guest PC 0x0c049124 */
if(!s->budget--) { s->failed_pc=0x0c049124u; return 0; }
r[18]^=0x100000u;
goto P_0c049126;
P_0c049126: /* original 432d, guest PC 0x0c049126 */
if(!s->budget--) { s->failed_pc=0x0c049126u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c049128;
P_0c049128: /* original 0483, guest PC 0x0c049128 */
if(!s->budget--) { s->failed_pc=0x0c049128u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c04912a;
P_0c04912a: /* original 6337, guest PC 0x0c04912a */
if(!s->budget--) { s->failed_pc=0x0c04912au; return 0; }
r[3]=~r[3];
goto P_0c04912c;
P_0c04912c: /* original 6296, guest PC 0x0c04912c */
if(!s->budget--) { s->failed_pc=0x0c04912cu; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[2]=tmp;
goto P_0c04912e;
P_0c04912e: /* original 2239, guest PC 0x0c04912e */
if(!s->budget--) { s->failed_pc=0x0c04912eu; return 0; }
r[2]&=r[3];
goto P_0c049130;
P_0c049130: /* original f00d, guest PC 0x0c049130 */
if(!s->budget--) { s->failed_pc=0x0c049130u; return 0; }
fr[0]=r[53];
goto P_0c049132;
P_0c049132: /* original 220b, guest PC 0x0c049132 */
if(!s->budget--) { s->failed_pc=0x0c049132u; return 0; }
r[2]|=r[0];
goto P_0c049134;
P_0c049134: /* original 425a, guest PC 0x0c049134 */
if(!s->budget--) { s->failed_pc=0x0c049134u; return 0; }
r[53]=r[2];
goto P_0c049136;
P_0c049136: /* original 74e0, guest PC 0x0c049136 */
if(!s->budget--) { s->failed_pc=0x0c049136u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c049138;
P_0c049138: /* original f10d, guest PC 0x0c049138 */
if(!s->budget--) { s->failed_pc=0x0c049138u; return 0; }
fr[1]=r[53];
goto P_0c04913a;
P_0c04913a: /* original 7610, guest PC 0x0c04913a */
if(!s->budget--) { s->failed_pc=0x0c04913au; return 0; }
r[6]+=0x00000010u;
goto P_0c04913c;
P_0c04913c: /* original f299, guest PC 0x0c04913c */
if(!s->budget--) { s->failed_pc=0x0c04913cu; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c04913e;
P_0c04913e: /* original f62b, guest PC 0x0c04913e */
if(!s->budget--) { s->failed_pc=0x0c04913eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c049140;
P_0c049140: /* original 7520, guest PC 0x0c049140 */
if(!s->budget--) { s->failed_pc=0x0c049140u; return 0; }
r[5]+=0x00000020u;
goto P_0c049142;
P_0c049142: /* original f60b, guest PC 0x0c049142 */
if(!s->budget--) { s->failed_pc=0x0c049142u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c049144;
P_0c049144: /* original f3fd, guest PC 0x0c049144 */
if(!s->budget--) { s->failed_pc=0x0c049144u; return 0; }
r[18]^=0x100000u;
goto P_0c049146;
P_0c049146: /* original 0683, guest PC 0x0c049146 */
if(!s->budget--) { s->failed_pc=0x0c049146u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c049148;
P_0c049148: /* original 7620, guest PC 0x0c049148 */
if(!s->budget--) { s->failed_pc=0x0c049148u; return 0; }
r[6]+=0x00000020u;
goto P_0c04914a;
P_0c04914a: /* original 4c25, guest PC 0x0c04914a */
if(!s->budget--) { s->failed_pc=0x0c04914au; return 0; }
tmp=r[12]&1u; r[12]=(r[12]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04914c;
P_0c04914c: /* original 6013, guest PC 0x0c04914c */
if(!s->budget--) { s->failed_pc=0x0c04914cu; return 0; }
r[0]=r[1];
goto P_0c04914e;
P_0c04914e: /* original 8d0b, guest PC 0x0c04914e */
if(!s->budget--) { s->failed_pc=0x0c04914eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
if(cond) { goto P_0c049168; }
goto P_0c049152;
P_0c049150: /* original 4c00, guest PC 0x0c049150 */
if(!s->budget--) { s->failed_pc=0x0c049150u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c049152;
P_0c049152: /* original c808, guest PC 0x0c049152 */
if(!s->budget--) { s->failed_pc=0x0c049152u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c049154;
P_0c049154: /* original 8903, guest PC 0x0c049154 */
if(!s->budget--) { s->failed_pc=0x0c049154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04915e; }
goto P_0c049156;
P_0c049156: /* original b0d3, guest PC 0x0c049156 */
if(!s->budget--) { s->failed_pc=0x0c049156u; return 0; }
target=code_base|0x0c049300u; r[16]=code_base|0x0c04915au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04915au) { target=s->pc; goto dispatch; }
goto P_0c04915a;
P_0c049158: /* original 0009, guest PC 0x0c049158 */
if(!s->budget--) { s->failed_pc=0x0c049158u; return 0; }
goto P_0c04915a;
P_0c04915a: /* original afc5, guest PC 0x0c04915a */
if(!s->budget--) { s->failed_pc=0x0c04915au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0490e8;
P_0c04915c: /* original 6046, guest PC 0x0c04915c */
if(!s->budget--) { s->failed_pc=0x0c04915cu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04915e;
P_0c04915e: /* original b01f, guest PC 0x0c04915e */
if(!s->budget--) { s->failed_pc=0x0c04915eu; return 0; }
target=code_base|0x0c0491a0u; r[16]=code_base|0x0c049162u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c049162u) { target=s->pc; goto dispatch; }
goto P_0c049162;
P_0c049160: /* original 0009, guest PC 0x0c049160 */
if(!s->budget--) { s->failed_pc=0x0c049160u; return 0; }
goto P_0c049162;
P_0c049162: /* original afc1, guest PC 0x0c049162 */
if(!s->budget--) { s->failed_pc=0x0c049162u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0490e8;
P_0c049164: /* original 6046, guest PC 0x0c049164 */
if(!s->budget--) { s->failed_pc=0x0c049164u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
if(!vf3_matrix_family(0x0c049166u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c049166u; return 0; } return 1;
P_0c049168: /* original e100, guest PC 0x0c049168 */
if(!s->budget--) { s->failed_pc=0x0c049168u; return 0; }
r[1]=0x00000000u;
goto P_0c04916a;
P_0c04916a: /* original c840, guest PC 0x0c04916a */
if(!s->budget--) { s->failed_pc=0x0c04916au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c04916c;
P_0c04916c: /* original 3c1e, guest PC 0x0c04916c */
if(!s->budget--) { s->failed_pc=0x0c04916cu; return 0; }
wide=(uint64_t)r[12]+r[1]+(r[17]&1u); r[12]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c04916e;
P_0c04916e: /* original c810, guest PC 0x0c04916e */
if(!s->budget--) { s->failed_pc=0x0c04916eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c049170;
P_0c049170: /* original 8d04, guest PC 0x0c049170 */
if(!s->budget--) { s->failed_pc=0x0c049170u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
if(cond) { goto P_0c04917c; }
goto P_0c049174;
P_0c049172: /* original c808, guest PC 0x0c049172 */
if(!s->budget--) { s->failed_pc=0x0c049172u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c049174;
P_0c049174: /* original b174, guest PC 0x0c049174 */
if(!s->budget--) { s->failed_pc=0x0c049174u; return 0; }
target=code_base|0x0c049460u; r[16]=code_base|0x0c049178u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c049178u) { target=s->pc; goto dispatch; }
goto P_0c049178;
P_0c049176: /* original 0009, guest PC 0x0c049176 */
if(!s->budget--) { s->failed_pc=0x0c049176u; return 0; }
goto P_0c049178;
P_0c049178: /* original afb6, guest PC 0x0c049178 */
if(!s->budget--) { s->failed_pc=0x0c049178u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0490e8;
P_0c04917a: /* original 6046, guest PC 0x0c04917a */
if(!s->budget--) { s->failed_pc=0x0c04917au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04917c;
P_0c04917c: /* original 8904, guest PC 0x0c04917c */
if(!s->budget--) { s->failed_pc=0x0c04917cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c049188; }
goto P_0c04917e;
P_0c04917e: /* original b35f, guest PC 0x0c04917e */
if(!s->budget--) { s->failed_pc=0x0c04917eu; return 0; }
target=code_base|0x0c049840u; r[16]=code_base|0x0c049182u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c049182u) { target=s->pc; goto dispatch; }
goto P_0c049182;
P_0c049180: /* original 0009, guest PC 0x0c049180 */
if(!s->budget--) { s->failed_pc=0x0c049180u; return 0; }
goto P_0c049182;
P_0c049182: /* original afb1, guest PC 0x0c049182 */
if(!s->budget--) { s->failed_pc=0x0c049182u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0490e8;
P_0c049184: /* original 6046, guest PC 0x0c049184 */
if(!s->budget--) { s->failed_pc=0x0c049184u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
if(!vf3_matrix_family(0x0c049186u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c049186u; return 0; } return 1;
P_0c049188: /* original affe, guest PC 0x0c049188 */
if(!s->budget--) { s->failed_pc=0x0c049188u; return 0; }
goto P_0c049188;
P_0c04918a: /* original 0009, guest PC 0x0c04918a */
if(!s->budget--) { s->failed_pc=0x0c04918au; return 0; }
if(!vf3_matrix_family(0x0c04918cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04918cu; return 0; } return 1;
P_0c049a16: /* original 4015, guest PC 0x0c049a16 */
if(!s->budget--) { s->failed_pc=0x0c049a16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c049a18;
P_0c049a18: /* original 69f2, guest PC 0x0c049a18 */
if(!s->budget--) { s->failed_pc=0x0c049a18u; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c049a1a;
P_0c049a1a: /* original 8d0f, guest PC 0x0c049a1a */
if(!s->budget--) { s->failed_pc=0x0c049a1au; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
if(cond) { goto P_0c049a3c; }
goto P_0c049a1e;
P_0c049a1c: /* original 4011, guest PC 0x0c049a1c */
if(!s->budget--) { s->failed_pc=0x0c049a1cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c049a1e;
P_0c049a1e: /* original 6803, guest PC 0x0c049a1e */
if(!s->budget--) { s->failed_pc=0x0c049a1eu; return 0; }
r[8]=r[0];
goto P_0c049a20;
P_0c049a20: /* original 60b3, guest PC 0x0c049a20 */
if(!s->budget--) { s->failed_pc=0x0c049a20u; return 0; }
r[0]=r[11];
goto P_0c049a22;
P_0c049a22: /* original 0a56, guest PC 0x0c049a22 */
if(!s->budget--) { s->failed_pc=0x0c049a22u; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c049a24;
P_0c049a24: /* original 7f04, guest PC 0x0c049a24 */
if(!s->budget--) { s->failed_pc=0x0c049a24u; return 0; }
r[15]+=0x00000004u;
goto P_0c049a26;
P_0c049a26: /* original 4f26, guest PC 0x0c049a26 */
if(!s->budget--) { s->failed_pc=0x0c049a26u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c049a28;
P_0c049a28: /* original f8f9, guest PC 0x0c049a28 */
if(!s->budget--) { s->failed_pc=0x0c049a28u; return 0; }
vf3_matrix_load(s,ram,8,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049a2a;
P_0c049a2a: /* original f9f9, guest PC 0x0c049a2a */
if(!s->budget--) { s->failed_pc=0x0c049a2au; return 0; }
vf3_matrix_load(s,ram,9,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049a2c;
P_0c049a2c: /* original faf9, guest PC 0x0c049a2c */
if(!s->budget--) { s->failed_pc=0x0c049a2cu; return 0; }
vf3_matrix_load(s,ram,10,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049a2e;
P_0c049a2e: /* original fbf9, guest PC 0x0c049a2e */
if(!s->budget--) { s->failed_pc=0x0c049a2eu; return 0; }
vf3_matrix_load(s,ram,11,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049a30;
P_0c049a30: /* original fcf9, guest PC 0x0c049a30 */
if(!s->budget--) { s->failed_pc=0x0c049a30u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049a32;
P_0c049a32: /* original fdf9, guest PC 0x0c049a32 */
if(!s->budget--) { s->failed_pc=0x0c049a32u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049a34;
P_0c049a34: /* original fef9, guest PC 0x0c049a34 */
if(!s->budget--) { s->failed_pc=0x0c049a34u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c049a36;
P_0c049a36: /* original 000b, guest PC 0x0c049a36 */
if(!s->budget--) { s->failed_pc=0x0c049a36u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c049a38: /* original fff9, guest PC 0x0c049a38 */
if(!s->budget--) { s->failed_pc=0x0c049a38u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c049a3au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c049a3au; return 0; } return 1;
P_0c049a3c: /* original 6103, guest PC 0x0c049a3c */
if(!s->budget--) { s->failed_pc=0x0c049a3cu; return 0; }
r[1]=r[0];
goto P_0c049a3e;
P_0c049a3e: /* original e2fb, guest PC 0x0c049a3e */
if(!s->budget--) { s->failed_pc=0x0c049a3eu; return 0; }
r[2]=0xfffffffbu;
goto P_0c049a40;
P_0c049a40: /* original 6396, guest PC 0x0c049a40 */
if(!s->budget--) { s->failed_pc=0x0c049a40u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[3]=tmp;
goto P_0c049a42;
P_0c049a42: /* original c940, guest PC 0x0c049a42 */
if(!s->budget--) { s->failed_pc=0x0c049a42u; return 0; }
r[0]&=64u;
goto P_0c049a44;
P_0c049a44: /* original 402d, guest PC 0x0c049a44 */
if(!s->budget--) { s->failed_pc=0x0c049a44u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c049a46;
P_0c049a46: /* original e2fd, guest PC 0x0c049a46 */
if(!s->budget--) { s->failed_pc=0x0c049a46u; return 0; }
r[2]=0xfffffffdu;
goto P_0c049a48;
P_0c049a48: /* original 2329, guest PC 0x0c049a48 */
if(!s->budget--) { s->failed_pc=0x0c049a48u; return 0; }
r[3]&=r[2];
goto P_0c049a4a;
P_0c049a4a: /* original 203b, guest PC 0x0c049a4a */
if(!s->budget--) { s->failed_pc=0x0c049a4au; return 0; }
r[0]|=r[3];
goto P_0c049a4c;
P_0c049a4c: /* original 7420, guest PC 0x0c049a4c */
if(!s->budget--) { s->failed_pc=0x0c049a4cu; return 0; }
r[4]+=0x00000020u;
goto P_0c049a4e;
P_0c049a4e: /* original 405a, guest PC 0x0c049a4e */
if(!s->budget--) { s->failed_pc=0x0c049a4eu; return 0; }
r[53]=r[0];
goto P_0c049a50;
P_0c049a50: /* original 6013, guest PC 0x0c049a50 */
if(!s->budget--) { s->failed_pc=0x0c049a50u; return 0; }
r[0]=r[1];
goto P_0c049a52;
P_0c049a52: /* original e21b, guest PC 0x0c049a52 */
if(!s->budget--) { s->failed_pc=0x0c049a52u; return 0; }
r[2]=0x0000001bu;
goto P_0c049a54;
P_0c049a54: /* original c903, guest PC 0x0c049a54 */
if(!s->budget--) { s->failed_pc=0x0c049a54u; return 0; }
r[0]&=3u;
goto P_0c049a56;
P_0c049a56: /* original 402d, guest PC 0x0c049a56 */
if(!s->budget--) { s->failed_pc=0x0c049a56u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c049a58;
P_0c049a58: /* original e303, guest PC 0x0c049a58 */
if(!s->budget--) { s->failed_pc=0x0c049a58u; return 0; }
r[3]=0x00000003u;
goto P_0c049a5a;
P_0c049a5a: /* original f3fd, guest PC 0x0c049a5a */
if(!s->budget--) { s->failed_pc=0x0c049a5au; return 0; }
r[18]^=0x100000u;
goto P_0c049a5c;
P_0c049a5c: /* original 432d, guest PC 0x0c049a5c */
if(!s->budget--) { s->failed_pc=0x0c049a5cu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c049a5e;
P_0c049a5e: /* original 0483, guest PC 0x0c049a5e */
if(!s->budget--) { s->failed_pc=0x0c049a5eu; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c049a60;
P_0c049a60: /* original 6337, guest PC 0x0c049a60 */
if(!s->budget--) { s->failed_pc=0x0c049a60u; return 0; }
r[3]=~r[3];
goto P_0c049a62;
P_0c049a62: /* original 6296, guest PC 0x0c049a62 */
if(!s->budget--) { s->failed_pc=0x0c049a62u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[2]=tmp;
goto P_0c049a64;
P_0c049a64: /* original 2239, guest PC 0x0c049a64 */
if(!s->budget--) { s->failed_pc=0x0c049a64u; return 0; }
r[2]&=r[3];
goto P_0c049a66;
P_0c049a66: /* original f00d, guest PC 0x0c049a66 */
if(!s->budget--) { s->failed_pc=0x0c049a66u; return 0; }
fr[0]=r[53];
goto P_0c049a68;
P_0c049a68: /* original 220b, guest PC 0x0c049a68 */
if(!s->budget--) { s->failed_pc=0x0c049a68u; return 0; }
r[2]|=r[0];
goto P_0c049a6a;
P_0c049a6a: /* original 425a, guest PC 0x0c049a6a */
if(!s->budget--) { s->failed_pc=0x0c049a6au; return 0; }
r[53]=r[2];
goto P_0c049a6c;
P_0c049a6c: /* original 74e0, guest PC 0x0c049a6c */
if(!s->budget--) { s->failed_pc=0x0c049a6cu; return 0; }
r[4]+=0xffffffe0u;
goto P_0c049a6e;
P_0c049a6e: /* original f10d, guest PC 0x0c049a6e */
if(!s->budget--) { s->failed_pc=0x0c049a6eu; return 0; }
fr[1]=r[53];
goto P_0c049a70;
P_0c049a70: /* original 7610, guest PC 0x0c049a70 */
if(!s->budget--) { s->failed_pc=0x0c049a70u; return 0; }
r[6]+=0x00000010u;
goto P_0c049a72;
P_0c049a72: /* original f299, guest PC 0x0c049a72 */
if(!s->budget--) { s->failed_pc=0x0c049a72u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c049a74;
P_0c049a74: /* original f62b, guest PC 0x0c049a74 */
if(!s->budget--) { s->failed_pc=0x0c049a74u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c049a76;
P_0c049a76: /* original 7520, guest PC 0x0c049a76 */
if(!s->budget--) { s->failed_pc=0x0c049a76u; return 0; }
r[5]+=0x00000020u;
goto P_0c049a78;
P_0c049a78: /* original f60b, guest PC 0x0c049a78 */
if(!s->budget--) { s->failed_pc=0x0c049a78u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c049a7a;
P_0c049a7a: /* original f3fd, guest PC 0x0c049a7a */
if(!s->budget--) { s->failed_pc=0x0c049a7au; return 0; }
r[18]^=0x100000u;
goto P_0c049a7c;
P_0c049a7c: /* original 0683, guest PC 0x0c049a7c */
if(!s->budget--) { s->failed_pc=0x0c049a7cu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c049a7e;
P_0c049a7e: /* original 7620, guest PC 0x0c049a7e */
if(!s->budget--) { s->failed_pc=0x0c049a7eu; return 0; }
r[6]+=0x00000020u;
goto P_0c049a80;
P_0c049a80: /* original 4c25, guest PC 0x0c049a80 */
if(!s->budget--) { s->failed_pc=0x0c049a80u; return 0; }
tmp=r[12]&1u; r[12]=(r[12]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c049a82;
P_0c049a82: /* original 6013, guest PC 0x0c049a82 */
if(!s->budget--) { s->failed_pc=0x0c049a82u; return 0; }
r[0]=r[1];
goto P_0c049a84;
P_0c049a84: /* original 8d0a, guest PC 0x0c049a84 */
if(!s->budget--) { s->failed_pc=0x0c049a84u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
if(cond) { goto P_0c049a9c; }
goto P_0c049a88;
P_0c049a86: /* original 4c00, guest PC 0x0c049a86 */
if(!s->budget--) { s->failed_pc=0x0c049a86u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c049a88;
P_0c049a88: /* original c808, guest PC 0x0c049a88 */
if(!s->budget--) { s->failed_pc=0x0c049a88u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c049a8a;
P_0c049a8a: /* original 8903, guest PC 0x0c049a8a */
if(!s->budget--) { s->failed_pc=0x0c049a8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c049a94; }
goto P_0c049a8c;
P_0c049a8c: /* original b078, guest PC 0x0c049a8c */
if(!s->budget--) { s->failed_pc=0x0c049a8cu; return 0; }
target=code_base|0x0c049b80u; r[16]=code_base|0x0c049a90u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c049a90u) { target=s->pc; goto dispatch; }
goto P_0c049a90;
P_0c049a8e: /* original 0009, guest PC 0x0c049a8e */
if(!s->budget--) { s->failed_pc=0x0c049a8eu; return 0; }
goto P_0c049a90;
P_0c049a90: /* original afc1, guest PC 0x0c049a90 */
if(!s->budget--) { s->failed_pc=0x0c049a90u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c049a16;
P_0c049a92: /* original 6046, guest PC 0x0c049a92 */
if(!s->budget--) { s->failed_pc=0x0c049a92u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c049a94;
P_0c049a94: /* original b024, guest PC 0x0c049a94 */
if(!s->budget--) { s->failed_pc=0x0c049a94u; return 0; }
target=code_base|0x0c049ae0u; r[16]=code_base|0x0c049a98u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c049a98u) { target=s->pc; goto dispatch; }
goto P_0c049a98;
P_0c049a96: /* original 0009, guest PC 0x0c049a96 */
if(!s->budget--) { s->failed_pc=0x0c049a96u; return 0; }
goto P_0c049a98;
P_0c049a98: /* original afbd, guest PC 0x0c049a98 */
if(!s->budget--) { s->failed_pc=0x0c049a98u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c049a16;
P_0c049a9a: /* original 6046, guest PC 0x0c049a9a */
if(!s->budget--) { s->failed_pc=0x0c049a9au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c049a9c;
P_0c049a9c: /* original e100, guest PC 0x0c049a9c */
if(!s->budget--) { s->failed_pc=0x0c049a9cu; return 0; }
r[1]=0x00000000u;
goto P_0c049a9e;
P_0c049a9e: /* original c840, guest PC 0x0c049a9e */
if(!s->budget--) { s->failed_pc=0x0c049a9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c049aa0;
P_0c049aa0: /* original 3c1e, guest PC 0x0c049aa0 */
if(!s->budget--) { s->failed_pc=0x0c049aa0u; return 0; }
wide=(uint64_t)r[12]+r[1]+(r[17]&1u); r[12]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c049aa2;
P_0c049aa2: /* original c810, guest PC 0x0c049aa2 */
if(!s->budget--) { s->failed_pc=0x0c049aa2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c049aa4;
P_0c049aa4: /* original 8d04, guest PC 0x0c049aa4 */
if(!s->budget--) { s->failed_pc=0x0c049aa4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
if(cond) { goto P_0c049ab0; }
goto P_0c049aa8;
P_0c049aa6: /* original c808, guest PC 0x0c049aa6 */
if(!s->budget--) { s->failed_pc=0x0c049aa6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c049aa8;
P_0c049aa8: /* original b0ba, guest PC 0x0c049aa8 */
if(!s->budget--) { s->failed_pc=0x0c049aa8u; return 0; }
target=code_base|0x0c049c20u; r[16]=code_base|0x0c049aacu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c049aacu) { target=s->pc; goto dispatch; }
goto P_0c049aac;
P_0c049aaa: /* original 0009, guest PC 0x0c049aaa */
if(!s->budget--) { s->failed_pc=0x0c049aaau; return 0; }
goto P_0c049aac;
P_0c049aac: /* original afb3, guest PC 0x0c049aac */
if(!s->budget--) { s->failed_pc=0x0c049aacu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c049a16;
P_0c049aae: /* original 6046, guest PC 0x0c049aae */
if(!s->budget--) { s->failed_pc=0x0c049aaeu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c049ab0;
P_0c049ab0: /* original 8904, guest PC 0x0c049ab0 */
if(!s->budget--) { s->failed_pc=0x0c049ab0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c049abc; }
goto P_0c049ab2;
P_0c049ab2: /* original b2a5, guest PC 0x0c049ab2 */
if(!s->budget--) { s->failed_pc=0x0c049ab2u; return 0; }
target=code_base|0x0c04a000u; r[16]=code_base|0x0c049ab6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c049ab6u) { target=s->pc; goto dispatch; }
goto P_0c049ab6;
P_0c049ab4: /* original 0009, guest PC 0x0c049ab4 */
if(!s->budget--) { s->failed_pc=0x0c049ab4u; return 0; }
goto P_0c049ab6;
P_0c049ab6: /* original afae, guest PC 0x0c049ab6 */
if(!s->budget--) { s->failed_pc=0x0c049ab6u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c049a16;
P_0c049ab8: /* original 6046, guest PC 0x0c049ab8 */
if(!s->budget--) { s->failed_pc=0x0c049ab8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
if(!vf3_matrix_family(0x0c049abau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c049abau; return 0; } return 1;
P_0c049abc: /* original affe, guest PC 0x0c049abc */
if(!s->budget--) { s->failed_pc=0x0c049abcu; return 0; }
goto P_0c049abc;
P_0c049abe: /* original 0009, guest PC 0x0c049abe */
if(!s->budget--) { s->failed_pc=0x0c049abeu; return 0; }
if(!vf3_matrix_family(0x0c049ac0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c049ac0u; return 0; } return 1;
P_0c055c96: /* original 4f22, guest PC 0x0c055c96 */
if(!s->budget--) { s->failed_pc=0x0c055c96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055c98;
P_0c055c98: /* original 6d43, guest PC 0x0c055c98 */
if(!s->budget--) { s->failed_pc=0x0c055c98u; return 0; }
r[13]=r[4];
goto P_0c055c9a;
P_0c055c9a: /* original d322, guest PC 0x0c055c9a */
if(!s->budget--) { s->failed_pc=0x0c055c9au; return 0; }
r[3]=read(ram,0x0c055d24u,4);
goto P_0c055c9c;
P_0c055c9c: /* original 430b, guest PC 0x0c055c9c */
if(!s->budget--) { s->failed_pc=0x0c055c9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c055ca0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055ca0u) { target=s->pc; goto dispatch; }
goto P_0c055ca0;
P_0c055c9e: /* original e400, guest PC 0x0c055c9e */
if(!s->budget--) { s->failed_pc=0x0c055c9eu; return 0; }
r[4]=0x00000000u;
goto P_0c055ca0;
P_0c055ca0: /* original d322, guest PC 0x0c055ca0 */
if(!s->budget--) { s->failed_pc=0x0c055ca0u; return 0; }
r[3]=read(ram,0x0c055d2cu,4);
goto P_0c055ca2;
P_0c055ca2: /* original c724, guest PC 0x0c055ca2 */
if(!s->budget--) { s->failed_pc=0x0c055ca2u; return 0; }
r[0]=code_base|0x00055d34u;
goto P_0c055ca4;
P_0c055ca4: /* original 6106, guest PC 0x0c055ca4 */
if(!s->budget--) { s->failed_pc=0x0c055ca4u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055ca6;
P_0c055ca6: /* original f418, guest PC 0x0c055ca6 */
if(!s->budget--) { s->failed_pc=0x0c055ca6u; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
goto P_0c055ca8;
P_0c055ca8: /* original 6106, guest PC 0x0c055ca8 */
if(!s->budget--) { s->failed_pc=0x0c055ca8u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055caa;
P_0c055caa: /* original 430b, guest PC 0x0c055caa */
if(!s->budget--) { s->failed_pc=0x0c055caau; return 0; }
target=r[3];
r[16]=code_base|0x0c055caeu;
vf3_matrix_load(s,ram,5,r[1]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055caeu) { target=s->pc; goto dispatch; }
goto P_0c055cae;
P_0c055cac: /* original f518, guest PC 0x0c055cac */
if(!s->budget--) { s->failed_pc=0x0c055cacu; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
goto P_0c055cae;
P_0c055cae: /* original 54d1, guest PC 0x0c055cae */
if(!s->budget--) { s->failed_pc=0x0c055caeu; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c055cb0;
P_0c055cb0: /* original c60b, guest PC 0x0c055cb0 */
if(!s->budget--) { s->failed_pc=0x0c055cb0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+44,4);
goto P_0c055cb2;
P_0c055cb2: /* original 6503, guest PC 0x0c055cb2 */
if(!s->budget--) { s->failed_pc=0x0c055cb2u; return 0; }
r[5]=r[0];
goto P_0c055cb4;
P_0c055cb4: /* original c604, guest PC 0x0c055cb4 */
if(!s->budget--) { s->failed_pc=0x0c055cb4u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+16,4);
goto P_0c055cb6;
P_0c055cb6: /* original 67d3, guest PC 0x0c055cb6 */
if(!s->budget--) { s->failed_pc=0x0c055cb6u; return 0; }
r[7]=r[13];
goto P_0c055cb8;
P_0c055cb8: /* original 400b, guest PC 0x0c055cb8 */
if(!s->budget--) { s->failed_pc=0x0c055cb8u; return 0; }
target=r[0];
r[16]=code_base|0x0c055cbcu;
r[6]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055cbcu) { target=s->pc; goto dispatch; }
goto P_0c055cbc;
P_0c055cba: /* original 56d2, guest PC 0x0c055cba */
if(!s->budget--) { s->failed_pc=0x0c055cbau; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c055cbc;
P_0c055cbc: /* original c60c, guest PC 0x0c055cbc */
if(!s->budget--) { s->failed_pc=0x0c055cbcu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+48,4);
goto P_0c055cbe;
P_0c055cbe: /* original c20b, guest PC 0x0c055cbe */
if(!s->budget--) { s->failed_pc=0x0c055cbeu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+44,r[0],4);
goto P_0c055cc0;
P_0c055cc0: /* original c60f, guest PC 0x0c055cc0 */
if(!s->budget--) { s->failed_pc=0x0c055cc0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+60,4);
goto P_0c055cc2;
P_0c055cc2: /* original c20e, guest PC 0x0c055cc2 */
if(!s->budget--) { s->failed_pc=0x0c055cc2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+56,r[0],4);
goto P_0c055cc4;
P_0c055cc4: /* original d318, guest PC 0x0c055cc4 */
if(!s->budget--) { s->failed_pc=0x0c055cc4u; return 0; }
r[3]=read(ram,0x0c055d28u,4);
goto P_0c055cc6;
P_0c055cc6: /* original 430b, guest PC 0x0c055cc6 */
if(!s->budget--) { s->failed_pc=0x0c055cc6u; return 0; }
target=r[3];
r[16]=code_base|0x0c055ccau;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055ccau) { target=s->pc; goto dispatch; }
goto P_0c055cca;
P_0c055cc8: /* original e401, guest PC 0x0c055cc8 */
if(!s->budget--) { s->failed_pc=0x0c055cc8u; return 0; }
r[4]=0x00000001u;
goto P_0c055cca;
P_0c055cca: /* original 4f26, guest PC 0x0c055cca */
if(!s->budget--) { s->failed_pc=0x0c055ccau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055ccc;
P_0c055ccc: /* original 68f6, guest PC 0x0c055ccc */
if(!s->budget--) { s->failed_pc=0x0c055cccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c055cce;
P_0c055cce: /* original 69f6, guest PC 0x0c055cce */
if(!s->budget--) { s->failed_pc=0x0c055cceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c055cd0;
P_0c055cd0: /* original 6af6, guest PC 0x0c055cd0 */
if(!s->budget--) { s->failed_pc=0x0c055cd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c055cd2;
P_0c055cd2: /* original 6bf6, guest PC 0x0c055cd2 */
if(!s->budget--) { s->failed_pc=0x0c055cd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c055cd4;
P_0c055cd4: /* original 6cf6, guest PC 0x0c055cd4 */
if(!s->budget--) { s->failed_pc=0x0c055cd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c055cd6;
P_0c055cd6: /* original 6df6, guest PC 0x0c055cd6 */
if(!s->budget--) { s->failed_pc=0x0c055cd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055cd8;
P_0c055cd8: /* original 6ef6, guest PC 0x0c055cd8 */
if(!s->budget--) { s->failed_pc=0x0c055cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055cda;
P_0c055cda: /* original fcf9, guest PC 0x0c055cda */
if(!s->budget--) { s->failed_pc=0x0c055cdau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055cdc;
P_0c055cdc: /* original fdf9, guest PC 0x0c055cdc */
if(!s->budget--) { s->failed_pc=0x0c055cdcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055cde;
P_0c055cde: /* original fef9, guest PC 0x0c055cde */
if(!s->budget--) { s->failed_pc=0x0c055cdeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055ce0;
P_0c055ce0: /* original 000b, guest PC 0x0c055ce0 */
if(!s->budget--) { s->failed_pc=0x0c055ce0u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c055ce2: /* original fff9, guest PC 0x0c055ce2 */
if(!s->budget--) { s->failed_pc=0x0c055ce2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c055ce4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055ce4u; return 0; } return 1;
P_0c058788: /* original 4f22, guest PC 0x0c058788 */
if(!s->budget--) { s->failed_pc=0x0c058788u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05878a;
P_0c05878a: /* original a025, guest PC 0x0c05878a */
if(!s->budget--) { s->failed_pc=0x0c05878au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0587d8;
P_0c05878c: /* original 4f22, guest PC 0x0c05878c */
if(!s->budget--) { s->failed_pc=0x0c05878cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
if(!vf3_matrix_family(0x0c05878eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05878eu; return 0; } return 1;
P_0c0587d8: /* original bf40, guest PC 0x0c0587d8 */
if(!s->budget--) { s->failed_pc=0x0c0587d8u; return 0; }
target=code_base|0x0c05865cu; r[16]=code_base|0x0c0587dcu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0587dcu) { target=s->pc; goto dispatch; }
goto P_0c0587dc;
P_0c0587da: /* original 65e3, guest PC 0x0c0587da */
if(!s->budget--) { s->failed_pc=0x0c0587dau; return 0; }
r[5]=r[14];
goto P_0c0587dc;
P_0c0587dc: /* original 2f06, guest PC 0x0c0587dc */
if(!s->budget--) { s->failed_pc=0x0c0587dcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0587de;
P_0c0587de: /* original e008, guest PC 0x0c0587de */
if(!s->budget--) { s->failed_pc=0x0c0587deu; return 0; }
r[0]=0x00000008u;
goto P_0c0587e0;
P_0c0587e0: /* original f096, guest PC 0x0c0587e0 */
if(!s->budget--) { s->failed_pc=0x0c0587e0u; return 0; }
vf3_matrix_load(s,ram,0,r[9]+r[0]);
goto P_0c0587e2;
P_0c0587e2: /* original 62e3, guest PC 0x0c0587e2 */
if(!s->budget--) { s->failed_pc=0x0c0587e2u; return 0; }
r[2]=r[14];
goto P_0c0587e4;
P_0c0587e4: /* original 72d0, guest PC 0x0c0587e4 */
if(!s->budget--) { s->failed_pc=0x0c0587e4u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c0587e6;
P_0c0587e6: /* original 6583, guest PC 0x0c0587e6 */
if(!s->budget--) { s->failed_pc=0x0c0587e6u; return 0; }
r[5]=r[8];
goto P_0c0587e8;
P_0c0587e8: /* original f79d, guest PC 0x0c0587e8 */
if(!s->budget--) { s->failed_pc=0x0c0587e8u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0587ea;
P_0c0587ea: /* original be89, guest PC 0x0c0587ea */
if(!s->budget--) { s->failed_pc=0x0c0587eau; return 0; }
target=code_base|0x0c058500u; r[16]=code_base|0x0c0587eeu;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0587eeu) { target=s->pc; goto dispatch; }
goto P_0c0587ee;
P_0c0587ec: /* original f703, guest PC 0x0c0587ec */
if(!s->budget--) { s->failed_pc=0x0c0587ecu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c0587ee;
P_0c0587ee: /* original 0c83, guest PC 0x0c0587ee */
if(!s->budget--) { s->failed_pc=0x0c0587eeu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0587f0;
P_0c0587f0: /* original 7c20, guest PC 0x0c0587f0 */
if(!s->budget--) { s->failed_pc=0x0c0587f0u; return 0; }
r[12]+=0x00000020u;
goto P_0c0587f2;
P_0c0587f2: /* original fa9d, guest PC 0x0c0587f2 */
if(!s->budget--) { s->failed_pc=0x0c0587f2u; return 0; }
fr[10]=0x3f800000u;
goto P_0c0587f4;
P_0c0587f4: /* original fa23, guest PC 0x0c0587f4 */
if(!s->budget--) { s->failed_pc=0x0c0587f4u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c0587f6;
P_0c0587f6: /* original f80c, guest PC 0x0c0587f6 */
if(!s->budget--) { s->failed_pc=0x0c0587f6u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c0587f8;
P_0c0587f8: /* original 62e3, guest PC 0x0c0587f8 */
if(!s->budget--) { s->failed_pc=0x0c0587f8u; return 0; }
r[2]=r[14];
goto P_0c0587fa;
P_0c0587fa: /* original fc4c, guest PC 0x0c0587fa */
if(!s->budget--) { s->failed_pc=0x0c0587fau; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0587fc;
P_0c0587fc: /* original be80, guest PC 0x0c0587fc */
if(!s->budget--) { s->failed_pc=0x0c0587fcu; return 0; }
target=code_base|0x0c058500u; r[16]=code_base|0x0c058800u;
r[5]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c058800u) { target=s->pc; goto dispatch; }
goto P_0c058800;
P_0c0587fe: /* original 6563, guest PC 0x0c0587fe */
if(!s->budget--) { s->failed_pc=0x0c0587feu; return 0; }
r[5]=r[6];
goto P_0c058800;
P_0c058800: /* original 0c83, guest PC 0x0c058800 */
if(!s->budget--) { s->failed_pc=0x0c058800u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058802;
P_0c058802: /* original fb9d, guest PC 0x0c058802 */
if(!s->budget--) { s->failed_pc=0x0c058802u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058804;
P_0c058804: /* original 62e3, guest PC 0x0c058804 */
if(!s->budget--) { s->failed_pc=0x0c058804u; return 0; }
r[2]=r[14];
goto P_0c058806;
P_0c058806: /* original fb23, guest PC 0x0c058806 */
if(!s->budget--) { s->failed_pc=0x0c058806u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c058808;
P_0c058808: /* original f298, guest PC 0x0c058808 */
if(!s->budget--) { s->failed_pc=0x0c058808u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
goto P_0c05880a;
P_0c05880a: /* original 72e8, guest PC 0x0c05880a */
if(!s->budget--) { s->failed_pc=0x0c05880au; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05880c;
P_0c05880c: /* original 6125, guest PC 0x0c05880c */
if(!s->budget--) { s->failed_pc=0x0c05880cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05880e;
P_0c05880e: /* original f3fd, guest PC 0x0c05880e */
if(!s->budget--) { s->failed_pc=0x0c05880eu; return 0; }
r[18]^=0x100000u;
goto P_0c058810;
P_0c058810: /* original 6221, guest PC 0x0c058810 */
if(!s->budget--) { s->failed_pc=0x0c058810u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058812;
P_0c058812: /* original a01e, guest PC 0x0c058812 */
if(!s->budget--) { s->failed_pc=0x0c058812u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c058814: /* original f60c, guest PC 0x0c058814 */
if(!s->budget--) { s->failed_pc=0x0c058814u; return 0; }
vf3_matrix_move(s,6,0);
if(!vf3_matrix_family(0x0c058816u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c058816u; return 0; } return 1;
P_0c058852: /* original c607, guest PC 0x0c058852 */
if(!s->budget--) { s->failed_pc=0x0c058852u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c058854;
P_0c058854: /* original f8a2, guest PC 0x0c058854 */
if(!s->budget--) { s->failed_pc=0x0c058854u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'*');
goto P_0c058856;
P_0c058856: /* original f9a2, guest PC 0x0c058856 */
if(!s->budget--) { s->failed_pc=0x0c058856u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c058858;
P_0c058858: /* original f272, guest PC 0x0c058858 */
if(!s->budget--) { s->failed_pc=0x0c058858u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c05885a;
P_0c05885a: /* original f372, guest PC 0x0c05885a */
if(!s->budget--) { s->failed_pc=0x0c05885au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c05885c;
P_0c05885c: /* original 405a, guest PC 0x0c05885c */
if(!s->budget--) { s->failed_pc=0x0c05885cu; return 0; }
r[53]=r[0];
goto P_0c05885e;
P_0c05885e: /* original fa71, guest PC 0x0c05885e */
if(!s->budget--) { s->failed_pc=0x0c05885eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'-');
goto P_0c058860;
P_0c058860: /* original f00d, guest PC 0x0c058860 */
if(!s->budget--) { s->failed_pc=0x0c058860u; return 0; }
fr[0]=r[53];
goto P_0c058862;
P_0c058862: /* original f071, guest PC 0x0c058862 */
if(!s->budget--) { s->failed_pc=0x0c058862u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[7],r[18],'-');
goto P_0c058864;
P_0c058864: /* original f6b2, guest PC 0x0c058864 */
if(!s->budget--) { s->failed_pc=0x0c058864u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c058866;
P_0c058866: /* original f1b2, guest PC 0x0c058866 */
if(!s->budget--) { s->failed_pc=0x0c058866u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'*');
goto P_0c058868;
P_0c058868: /* original fb71, guest PC 0x0c058868 */
if(!s->budget--) { s->failed_pc=0x0c058868u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'-');
goto P_0c05886a;
P_0c05886a: /* original ff0b, guest PC 0x0c05886a */
if(!s->budget--) { s->failed_pc=0x0c05886au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c05886c;
P_0c05886c: /* original f0a3, guest PC 0x0c05886c */
if(!s->budget--) { s->failed_pc=0x0c05886cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'/');
goto P_0c05886e;
P_0c05886e: /* original f821, guest PC 0x0c05886e */
if(!s->budget--) { s->failed_pc=0x0c05886eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[2],r[18],'-');
goto P_0c058870;
P_0c058870: /* original f931, guest PC 0x0c058870 */
if(!s->budget--) { s->failed_pc=0x0c058870u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c058872;
P_0c058872: /* original 425a, guest PC 0x0c058872 */
if(!s->budget--) { s->failed_pc=0x0c058872u; return 0; }
r[53]=r[2];
goto P_0c058874;
P_0c058874: /* original fe2d, guest PC 0x0c058874 */
if(!s->budget--) { s->failed_pc=0x0c058874u; return 0; }
fr[14]=vf3_fpu_float(r[53],r[18]);
goto P_0c058876;
P_0c058876: /* original 415a, guest PC 0x0c058876 */
if(!s->budget--) { s->failed_pc=0x0c058876u; return 0; }
r[53]=r[1];
goto P_0c058878;
P_0c058878: /* original fa2d, guest PC 0x0c058878 */
if(!s->budget--) { s->failed_pc=0x0c058878u; return 0; }
fr[10]=vf3_fpu_float(r[53],r[18]);
goto P_0c05887a;
P_0c05887a: /* original f621, guest PC 0x0c05887a */
if(!s->budget--) { s->failed_pc=0x0c05887au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c05887c;
P_0c05887c: /* original 60f6, guest PC 0x0c05887c */
if(!s->budget--) { s->failed_pc=0x0c05887cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c05887e;
P_0c05887e: /* original f131, guest PC 0x0c05887e */
if(!s->budget--) { s->failed_pc=0x0c05887eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c058880;
P_0c058880: /* original 61f6, guest PC 0x0c058880 */
if(!s->budget--) { s->failed_pc=0x0c058880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c058882;
P_0c058882: /* original fef2, guest PC 0x0c058882 */
if(!s->budget--) { s->failed_pc=0x0c058882u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c058884;
P_0c058884: /* original faf2, guest PC 0x0c058884 */
if(!s->budget--) { s->failed_pc=0x0c058884u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c058886;
P_0c058886: /* original 4f26, guest PC 0x0c058886 */
if(!s->budget--) { s->failed_pc=0x0c058886u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058888;
P_0c058888: /* original fde1, guest PC 0x0c058888 */
if(!s->budget--) { s->failed_pc=0x0c058888u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c05888a;
P_0c05888a: /* original fca1, guest PC 0x0c05888a */
if(!s->budget--) { s->failed_pc=0x0c05888au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[10],r[18],'-');
goto P_0c05888c;
P_0c05888c: /* original 405a, guest PC 0x0c05888c */
if(!s->budget--) { s->failed_pc=0x0c05888cu; return 0; }
r[53]=r[0];
goto P_0c05888e;
P_0c05888e: /* original f5e1, guest PC 0x0c05888e */
if(!s->budget--) { s->failed_pc=0x0c05888eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c058890;
P_0c058890: /* original 7c3c, guest PC 0x0c058890 */
if(!s->budget--) { s->failed_pc=0x0c058890u; return 0; }
r[12]+=0x0000003cu;
goto P_0c058892;
P_0c058892: /* original f4a1, guest PC 0x0c058892 */
if(!s->budget--) { s->failed_pc=0x0c058892u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'-');
goto P_0c058894;
P_0c058894: /* original ff3c, guest PC 0x0c058894 */
if(!s->budget--) { s->failed_pc=0x0c058894u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c058896;
P_0c058896: /* original ff9e, guest PC 0x0c058896 */
if(!s->budget--) { s->failed_pc=0x0c058896u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[9],fr[15],r[18]);
goto P_0c058898;
P_0c058898: /* original f92c, guest PC 0x0c058898 */
if(!s->budget--) { s->failed_pc=0x0c058898u; return 0; }
vf3_matrix_move(s,9,2);
goto P_0c05889a;
P_0c05889a: /* original f98e, guest PC 0x0c05889a */
if(!s->budget--) { s->failed_pc=0x0c05889au; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[8],fr[9],r[18]);
goto P_0c05889c;
P_0c05889c: /* original f8ec, guest PC 0x0c05889c */
if(!s->budget--) { s->failed_pc=0x0c05889cu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c05889e;
P_0c05889e: /* original f8de, guest PC 0x0c05889e */
if(!s->budget--) { s->failed_pc=0x0c05889eu; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[13],fr[8],r[18]);
goto P_0c0588a0;
P_0c0588a0: /* original fdac, guest PC 0x0c0588a0 */
if(!s->budget--) { s->failed_pc=0x0c0588a0u; return 0; }
vf3_matrix_move(s,13,10);
goto P_0c0588a2;
P_0c0588a2: /* original fdce, guest PC 0x0c0588a2 */
if(!s->budget--) { s->failed_pc=0x0c0588a2u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[12],fr[13],r[18]);
goto P_0c0588a4;
P_0c0588a4: /* original f00d, guest PC 0x0c0588a4 */
if(!s->budget--) { s->failed_pc=0x0c0588a4u; return 0; }
fr[0]=r[53];
goto P_0c0588a6;
P_0c0588a6: /* original f0b3, guest PC 0x0c0588a6 */
if(!s->budget--) { s->failed_pc=0x0c0588a6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
goto P_0c0588a8;
P_0c0588a8: /* original 4a5a, guest PC 0x0c0588a8 */
if(!s->budget--) { s->failed_pc=0x0c0588a8u; return 0; }
r[53]=r[10];
goto P_0c0588aa;
P_0c0588aa: /* original fc0d, guest PC 0x0c0588aa */
if(!s->budget--) { s->failed_pc=0x0c0588aau; return 0; }
fr[12]=r[53];
goto P_0c0588ac;
P_0c0588ac: /* original ffc2, guest PC 0x0c0588ac */
if(!s->budget--) { s->failed_pc=0x0c0588acu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0588ae;
P_0c0588ae: /* original c618, guest PC 0x0c0588ae */
if(!s->budget--) { s->failed_pc=0x0c0588aeu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+96,4);
goto P_0c0588b0;
P_0c0588b0: /* original f9c2, guest PC 0x0c0588b0 */
if(!s->budget--) { s->failed_pc=0x0c0588b0u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c0588b2;
P_0c0588b2: /* original 2c12, guest PC 0x0c0588b2 */
if(!s->budget--) { s->failed_pc=0x0c0588b2u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0588b4;
P_0c0588b4: /* original 2c06, guest PC 0x0c0588b4 */
if(!s->budget--) { s->failed_pc=0x0c0588b4u; return 0; }
tmp=r[0]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588b6;
P_0c0588b6: /* original fc8b, guest PC 0x0c0588b6 */
if(!s->budget--) { s->failed_pc=0x0c0588b6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0588b8;
P_0c0588b8: /* original fcdb, guest PC 0x0c0588b8 */
if(!s->budget--) { s->failed_pc=0x0c0588b8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c0588ba;
P_0c0588ba: /* original 2ca6, guest PC 0x0c0588ba */
if(!s->budget--) { s->failed_pc=0x0c0588bau; return 0; }
tmp=r[10]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588bc;
P_0c0588bc: /* original fcfb, guest PC 0x0c0588bc */
if(!s->budget--) { s->failed_pc=0x0c0588bcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c0588be;
P_0c0588be: /* original fc9b, guest PC 0x0c0588be */
if(!s->budget--) { s->failed_pc=0x0c0588beu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0588c0;
P_0c0588c0: /* original 2cc6, guest PC 0x0c0588c0 */
if(!s->budget--) { s->failed_pc=0x0c0588c0u; return 0; }
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588c2;
P_0c0588c2: /* original 0c83, guest PC 0x0c0588c2 */
if(!s->budget--) { s->failed_pc=0x0c0588c2u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0588c4;
P_0c0588c4: /* original 7c2c, guest PC 0x0c0588c4 */
if(!s->budget--) { s->failed_pc=0x0c0588c4u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0588c6;
P_0c0588c6: /* original f31e, guest PC 0x0c0588c6 */
if(!s->budget--) { s->failed_pc=0x0c0588c6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0588c8;
P_0c0588c8: /* original 2ca2, guest PC 0x0c0588c8 */
if(!s->budget--) { s->failed_pc=0x0c0588c8u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c0588ca;
P_0c0588ca: /* original f26e, guest PC 0x0c0588ca */
if(!s->budget--) { s->failed_pc=0x0c0588cau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0588cc;
P_0c0588cc: /* original 7c04, guest PC 0x0c0588cc */
if(!s->budget--) { s->failed_pc=0x0c0588ccu; return 0; }
r[12]+=0x00000004u;
goto P_0c0588ce;
P_0c0588ce: /* original fe5e, guest PC 0x0c0588ce */
if(!s->budget--) { s->failed_pc=0x0c0588ceu; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[5],fr[14],r[18]);
goto P_0c0588d0;
P_0c0588d0: /* original 1c02, guest PC 0x0c0588d0 */
if(!s->budget--) { s->failed_pc=0x0c0588d0u; return 0; }
write(ram,r[12]+8,r[0],4);
goto P_0c0588d2;
P_0c0588d2: /* original fa4e, guest PC 0x0c0588d2 */
if(!s->budget--) { s->failed_pc=0x0c0588d2u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[4],fr[10],r[18]);
goto P_0c0588d4;
P_0c0588d4: /* original e004, guest PC 0x0c0588d4 */
if(!s->budget--) { s->failed_pc=0x0c0588d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0588d6;
P_0c0588d6: /* original f3c2, guest PC 0x0c0588d6 */
if(!s->budget--) { s->failed_pc=0x0c0588d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0588d8;
P_0c0588d8: /* original 1c13, guest PC 0x0c0588d8 */
if(!s->budget--) { s->failed_pc=0x0c0588d8u; return 0; }
write(ram,r[12]+12,r[1],4);
goto P_0c0588da;
P_0c0588da: /* original f2c2, guest PC 0x0c0588da */
if(!s->budget--) { s->failed_pc=0x0c0588dau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[12],r[18],'*');
goto P_0c0588dc;
P_0c0588dc: /* original fce7, guest PC 0x0c0588dc */
if(!s->budget--) { s->failed_pc=0x0c0588dcu; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c0588de;
P_0c0588de: /* original fcaa, guest PC 0x0c0588de */
if(!s->budget--) { s->failed_pc=0x0c0588deu; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c0588e0;
P_0c0588e0: /* original 7cf8, guest PC 0x0c0588e0 */
if(!s->budget--) { s->failed_pc=0x0c0588e0u; return 0; }
r[12]+=0xfffffff8u;
goto P_0c0588e2;
P_0c0588e2: /* original fc3a, guest PC 0x0c0588e2 */
if(!s->budget--) { s->failed_pc=0x0c0588e2u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c0588e4;
P_0c0588e4: /* original fc2b, guest PC 0x0c0588e4 */
if(!s->budget--) { s->failed_pc=0x0c0588e4u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c0588e6;
P_0c0588e6: /* original f3fd, guest PC 0x0c0588e6 */
if(!s->budget--) { s->failed_pc=0x0c0588e6u; return 0; }
r[18]^=0x100000u;
goto P_0c0588e8;
P_0c0588e8: /* original 7cfc, guest PC 0x0c0588e8 */
if(!s->budget--) { s->failed_pc=0x0c0588e8u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c0588ea;
P_0c0588ea: /* original f498, guest PC 0x0c0588ea */
if(!s->budget--) { s->failed_pc=0x0c0588eau; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c0588ec;
P_0c0588ec: /* original 000b, guest PC 0x0c0588ec */
if(!s->budget--) { s->failed_pc=0x0c0588ecu; return 0; }
target=r[16];
vf3_matrix_load(s,ram,8,r[6]);
s->pc=target; return ram->oob==0;
P_0c0588ee: /* original f868, guest PC 0x0c0588ee */
if(!s->budget--) { s->failed_pc=0x0c0588eeu; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
if(!vf3_matrix_family(0x0c0588f0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0588f0u; return 0; } return 1;
P_0c05df8a: /* original 4f22, guest PC 0x0c05df8a */
if(!s->budget--) { s->failed_pc=0x0c05df8au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05df8c;
P_0c05df8c: /* original de3c, guest PC 0x0c05df8c */
if(!s->budget--) { s->failed_pc=0x0c05df8cu; return 0; }
r[14]=read(ram,0x0c05e080u,4);
goto P_0c05df8e;
P_0c05df8e: /* original 6522, guest PC 0x0c05df8e */
if(!s->budget--) { s->failed_pc=0x0c05df8eu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05df90;
P_0c05df90: /* original 2539, guest PC 0x0c05df90 */
if(!s->budget--) { s->failed_pc=0x0c05df90u; return 0; }
r[5]&=r[3];
goto P_0c05df92;
P_0c05df92: /* original 4e0b, guest PC 0x0c05df92 */
if(!s->budget--) { s->failed_pc=0x0c05df92u; return 0; }
target=r[14];
r[16]=code_base|0x0c05df96u;
r[4]=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05df96u) { target=s->pc; goto dispatch; }
goto P_0c05df96;
P_0c05df94: /* original e444, guest PC 0x0c05df94 */
if(!s->budget--) { s->failed_pc=0x0c05df94u; return 0; }
r[4]=0x00000044u;
goto P_0c05df96;
P_0c05df96: /* original d33c, guest PC 0x0c05df96 */
if(!s->budget--) { s->failed_pc=0x0c05df96u; return 0; }
r[3]=read(ram,0x0c05e088u,4);
goto P_0c05df98;
P_0c05df98: /* original 6032, guest PC 0x0c05df98 */
if(!s->budget--) { s->failed_pc=0x0c05df98u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05df9a;
P_0c05df9a: /* original cb08, guest PC 0x0c05df9a */
if(!s->budget--) { s->failed_pc=0x0c05df9au; return 0; }
r[0]|=8u;
goto P_0c05df9c;
P_0c05df9c: /* original 946d, guest PC 0x0c05df9c */
if(!s->budget--) { s->failed_pc=0x0c05df9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e07au,2);
goto P_0c05df9e;
P_0c05df9e: /* original 4e0b, guest PC 0x0c05df9e */
if(!s->budget--) { s->failed_pc=0x0c05df9eu; return 0; }
target=r[14];
r[16]=code_base|0x0c05dfa2u;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dfa2u) { target=s->pc; goto dispatch; }
goto P_0c05dfa2;
P_0c05dfa0: /* original 6503, guest PC 0x0c05dfa0 */
if(!s->budget--) { s->failed_pc=0x0c05dfa0u; return 0; }
r[5]=r[0];
goto P_0c05dfa2;
P_0c05dfa2: /* original d23a, guest PC 0x0c05dfa2 */
if(!s->budget--) { s->failed_pc=0x0c05dfa2u; return 0; }
r[2]=read(ram,0x0c05e08cu,4);
goto P_0c05dfa4;
P_0c05dfa4: /* original 420b, guest PC 0x0c05dfa4 */
if(!s->budget--) { s->failed_pc=0x0c05dfa4u; return 0; }
target=r[2];
r[16]=code_base|0x0c05dfa8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dfa8u) { target=s->pc; goto dispatch; }
goto P_0c05dfa8;
P_0c05dfa6: /* original 0009, guest PC 0x0c05dfa6 */
if(!s->budget--) { s->failed_pc=0x0c05dfa6u; return 0; }
goto P_0c05dfa8;
P_0c05dfa8: /* original d339, guest PC 0x0c05dfa8 */
if(!s->budget--) { s->failed_pc=0x0c05dfa8u; return 0; }
r[3]=read(ram,0x0c05e090u,4);
goto P_0c05dfaa;
P_0c05dfaa: /* original 430b, guest PC 0x0c05dfaa */
if(!s->budget--) { s->failed_pc=0x0c05dfaau; return 0; }
target=r[3];
r[16]=code_base|0x0c05dfaeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dfaeu) { target=s->pc; goto dispatch; }
goto P_0c05dfae;
P_0c05dfac: /* original 0009, guest PC 0x0c05dfac */
if(!s->budget--) { s->failed_pc=0x0c05dfacu; return 0; }
goto P_0c05dfae;
P_0c05dfae: /* original e3fe, guest PC 0x0c05dfae */
if(!s->budget--) { s->failed_pc=0x0c05dfaeu; return 0; }
r[3]=0xfffffffeu;
goto P_0c05dfb0;
P_0c05dfb0: /* original d234, guest PC 0x0c05dfb0 */
if(!s->budget--) { s->failed_pc=0x0c05dfb0u; return 0; }
r[2]=read(ram,0x0c05e084u,4);
goto P_0c05dfb2;
P_0c05dfb2: /* original 6522, guest PC 0x0c05dfb2 */
if(!s->budget--) { s->failed_pc=0x0c05dfb2u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05dfb4;
P_0c05dfb4: /* original 2539, guest PC 0x0c05dfb4 */
if(!s->budget--) { s->failed_pc=0x0c05dfb4u; return 0; }
r[5]&=r[3];
goto P_0c05dfb6;
P_0c05dfb6: /* original 4e0b, guest PC 0x0c05dfb6 */
if(!s->budget--) { s->failed_pc=0x0c05dfb6u; return 0; }
target=r[14];
r[16]=code_base|0x0c05dfbau;
r[4]=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dfbau) { target=s->pc; goto dispatch; }
goto P_0c05dfba;
P_0c05dfb8: /* original e444, guest PC 0x0c05dfb8 */
if(!s->budget--) { s->failed_pc=0x0c05dfb8u; return 0; }
r[4]=0x00000044u;
goto P_0c05dfba;
P_0c05dfba: /* original d333, guest PC 0x0c05dfba */
if(!s->budget--) { s->failed_pc=0x0c05dfbau; return 0; }
r[3]=read(ram,0x0c05e088u,4);
goto P_0c05dfbc;
P_0c05dfbc: /* original 6032, guest PC 0x0c05dfbc */
if(!s->budget--) { s->failed_pc=0x0c05dfbcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05dfbe;
P_0c05dfbe: /* original cb08, guest PC 0x0c05dfbe */
if(!s->budget--) { s->failed_pc=0x0c05dfbeu; return 0; }
r[0]|=8u;
goto P_0c05dfc0;
P_0c05dfc0: /* original 945b, guest PC 0x0c05dfc0 */
if(!s->budget--) { s->failed_pc=0x0c05dfc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e07au,2);
goto P_0c05dfc2;
P_0c05dfc2: /* original 4e0b, guest PC 0x0c05dfc2 */
if(!s->budget--) { s->failed_pc=0x0c05dfc2u; return 0; }
target=r[14];
r[16]=code_base|0x0c05dfc6u;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dfc6u) { target=s->pc; goto dispatch; }
goto P_0c05dfc6;
P_0c05dfc4: /* original 6503, guest PC 0x0c05dfc4 */
if(!s->budget--) { s->failed_pc=0x0c05dfc4u; return 0; }
r[5]=r[0];
goto P_0c05dfc6;
P_0c05dfc6: /* original bde9, guest PC 0x0c05dfc6 */
if(!s->budget--) { s->failed_pc=0x0c05dfc6u; return 0; }
target=code_base|0x0c05db9cu; r[16]=code_base|0x0c05dfcau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dfcau) { target=s->pc; goto dispatch; }
goto P_0c05dfca;
P_0c05dfc8: /* original 0009, guest PC 0x0c05dfc8 */
if(!s->budget--) { s->failed_pc=0x0c05dfc8u; return 0; }
goto P_0c05dfca;
P_0c05dfca: /* original e301, guest PC 0x0c05dfca */
if(!s->budget--) { s->failed_pc=0x0c05dfcau; return 0; }
r[3]=0x00000001u;
goto P_0c05dfcc;
P_0c05dfcc: /* original d231, guest PC 0x0c05dfcc */
if(!s->budget--) { s->failed_pc=0x0c05dfccu; return 0; }
r[2]=read(ram,0x0c05e094u,4);
goto P_0c05dfce;
P_0c05dfce: /* original 2232, guest PC 0x0c05dfce */
if(!s->budget--) { s->failed_pc=0x0c05dfceu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05dfd0;
P_0c05dfd0: /* original 4f26, guest PC 0x0c05dfd0 */
if(!s->budget--) { s->failed_pc=0x0c05dfd0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05dfd2;
P_0c05dfd2: /* original e000, guest PC 0x0c05dfd2 */
if(!s->budget--) { s->failed_pc=0x0c05dfd2u; return 0; }
r[0]=0x00000000u;
goto P_0c05dfd4;
P_0c05dfd4: /* original 000b, guest PC 0x0c05dfd4 */
if(!s->budget--) { s->failed_pc=0x0c05dfd4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05dfd6: /* original 6ef6, guest PC 0x0c05dfd6 */
if(!s->budget--) { s->failed_pc=0x0c05dfd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05dfd8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05dfd8u; return 0; } return 1;
P_0c05edd4: /* original 4f22, guest PC 0x0c05edd4 */
if(!s->budget--) { s->failed_pc=0x0c05edd4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05edd6;
P_0c05edd6: /* original 6e53, guest PC 0x0c05edd6 */
if(!s->budget--) { s->failed_pc=0x0c05edd6u; return 0; }
r[14]=r[5];
goto P_0c05edd8;
P_0c05edd8: /* original 60e2, guest PC 0x0c05edd8 */
if(!s->budget--) { s->failed_pc=0x0c05edd8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05edda;
P_0c05edda: /* original c903, guest PC 0x0c05edda */
if(!s->budget--) { s->failed_pc=0x0c05eddau; return 0; }
r[0]&=3u;
goto P_0c05eddc;
P_0c05eddc: /* original 8801, guest PC 0x0c05eddc */
if(!s->budget--) { s->failed_pc=0x0c05eddcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05edde;
P_0c05edde: /* original 8b05, guest PC 0x0c05edde */
if(!s->budget--) { s->failed_pc=0x0c05eddeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05edec; }
goto P_0c05ede0;
P_0c05ede0: /* original 56e5, guest PC 0x0c05ede0 */
if(!s->budget--) { s->failed_pc=0x0c05ede0u; return 0; }
r[6]=read(ram,r[14]+20,4);
goto P_0c05ede2;
P_0c05ede2: /* original d21c, guest PC 0x0c05ede2 */
if(!s->budget--) { s->failed_pc=0x0c05ede2u; return 0; }
r[2]=read(ram,0x0c05ee54u,4);
goto P_0c05ede4;
P_0c05ede4: /* original 420b, guest PC 0x0c05ede4 */
if(!s->budget--) { s->failed_pc=0x0c05ede4u; return 0; }
target=r[2];
r[16]=code_base|0x0c05ede8u;
r[5]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ede8u) { target=s->pc; goto dispatch; }
goto P_0c05ede8;
P_0c05ede6: /* original 55e7, guest PC 0x0c05ede6 */
if(!s->budget--) { s->failed_pc=0x0c05ede6u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c05ede8;
P_0c05ede8: /* original a020, guest PC 0x0c05ede8 */
if(!s->budget--) { s->failed_pc=0x0c05ede8u; return 0; }
goto P_0c05ee2c;
P_0c05edea: /* original 0009, guest PC 0x0c05edea */
if(!s->budget--) { s->failed_pc=0x0c05edeau; return 0; }
goto P_0c05edec;
P_0c05edec: /* original 60e2, guest PC 0x0c05edec */
if(!s->budget--) { s->failed_pc=0x0c05edecu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05edee;
P_0c05edee: /* original 600d, guest PC 0x0c05edee */
if(!s->budget--) { s->failed_pc=0x0c05edeeu; return 0; }
r[0]=r[0]&65535u;
goto P_0c05edf0;
P_0c05edf0: /* original 8803, guest PC 0x0c05edf0 */
if(!s->budget--) { s->failed_pc=0x0c05edf0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05edf2;
P_0c05edf2: /* original 8b05, guest PC 0x0c05edf2 */
if(!s->budget--) { s->failed_pc=0x0c05edf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ee00; }
goto P_0c05edf4;
P_0c05edf4: /* original 57e6, guest PC 0x0c05edf4 */
if(!s->budget--) { s->failed_pc=0x0c05edf4u; return 0; }
r[7]=read(ram,r[14]+24,4);
goto P_0c05edf6;
P_0c05edf6: /* original 56e3, guest PC 0x0c05edf6 */
if(!s->budget--) { s->failed_pc=0x0c05edf6u; return 0; }
r[6]=read(ram,r[14]+12,4);
goto P_0c05edf8;
P_0c05edf8: /* original b2f1, guest PC 0x0c05edf8 */
if(!s->budget--) { s->failed_pc=0x0c05edf8u; return 0; }
target=code_base|0x0c05f3deu; r[16]=code_base|0x0c05edfcu;
r[5]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05edfcu) { target=s->pc; goto dispatch; }
goto P_0c05edfc;
P_0c05edfa: /* original 55e7, guest PC 0x0c05edfa */
if(!s->budget--) { s->failed_pc=0x0c05edfau; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c05edfc;
P_0c05edfc: /* original a016, guest PC 0x0c05edfc */
if(!s->budget--) { s->failed_pc=0x0c05edfcu; return 0; }
goto P_0c05ee2c;
P_0c05edfe: /* original 0009, guest PC 0x0c05edfe */
if(!s->budget--) { s->failed_pc=0x0c05edfeu; return 0; }
goto P_0c05ee00;
P_0c05ee00: /* original 55e6, guest PC 0x0c05ee00 */
if(!s->budget--) { s->failed_pc=0x0c05ee00u; return 0; }
r[5]=read(ram,r[14]+24,4);
goto P_0c05ee02;
P_0c05ee02: /* original e204, guest PC 0x0c05ee02 */
if(!s->budget--) { s->failed_pc=0x0c05ee02u; return 0; }
r[2]=0x00000004u;
goto P_0c05ee04;
P_0c05ee04: /* original 2258, guest PC 0x0c05ee04 */
if(!s->budget--) { s->failed_pc=0x0c05ee04u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c05ee06;
P_0c05ee06: /* original 890d, guest PC 0x0c05ee06 */
if(!s->budget--) { s->failed_pc=0x0c05ee06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ee24; }
goto P_0c05ee08;
P_0c05ee08: /* original e101, guest PC 0x0c05ee08 */
if(!s->budget--) { s->failed_pc=0x0c05ee08u; return 0; }
r[1]=0x00000001u;
goto P_0c05ee0a;
P_0c05ee0a: /* original 2158, guest PC 0x0c05ee0a */
if(!s->budget--) { s->failed_pc=0x0c05ee0au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c05ee0c;
P_0c05ee0c: /* original 890a, guest PC 0x0c05ee0c */
if(!s->budget--) { s->failed_pc=0x0c05ee0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ee24; }
goto P_0c05ee0e;
P_0c05ee0e: /* original e208, guest PC 0x0c05ee0e */
if(!s->budget--) { s->failed_pc=0x0c05ee0eu; return 0; }
r[2]=0x00000008u;
goto P_0c05ee10;
P_0c05ee10: /* original 2258, guest PC 0x0c05ee10 */
if(!s->budget--) { s->failed_pc=0x0c05ee10u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c05ee12;
P_0c05ee12: /* original 8b07, guest PC 0x0c05ee12 */
if(!s->budget--) { s->failed_pc=0x0c05ee12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ee24; }
goto P_0c05ee14;
P_0c05ee14: /* original e120, guest PC 0x0c05ee14 */
if(!s->budget--) { s->failed_pc=0x0c05ee14u; return 0; }
r[1]=0x00000020u;
goto P_0c05ee16;
P_0c05ee16: /* original 2158, guest PC 0x0c05ee16 */
if(!s->budget--) { s->failed_pc=0x0c05ee16u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c05ee18;
P_0c05ee18: /* original 8b04, guest PC 0x0c05ee18 */
if(!s->budget--) { s->failed_pc=0x0c05ee18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ee24; }
goto P_0c05ee1a;
P_0c05ee1a: /* original 56e3, guest PC 0x0c05ee1a */
if(!s->budget--) { s->failed_pc=0x0c05ee1au; return 0; }
r[6]=read(ram,r[14]+12,4);
goto P_0c05ee1c;
P_0c05ee1c: /* original b28d, guest PC 0x0c05ee1c */
if(!s->budget--) { s->failed_pc=0x0c05ee1cu; return 0; }
target=code_base|0x0c05f33au; r[16]=code_base|0x0c05ee20u;
r[5]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ee20u) { target=s->pc; goto dispatch; }
goto P_0c05ee20;
P_0c05ee1e: /* original 55e7, guest PC 0x0c05ee1e */
if(!s->budget--) { s->failed_pc=0x0c05ee1eu; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c05ee20;
P_0c05ee20: /* original a004, guest PC 0x0c05ee20 */
if(!s->budget--) { s->failed_pc=0x0c05ee20u; return 0; }
goto P_0c05ee2c;
P_0c05ee22: /* original 0009, guest PC 0x0c05ee22 */
if(!s->budget--) { s->failed_pc=0x0c05ee22u; return 0; }
goto P_0c05ee24;
P_0c05ee24: /* original 56e5, guest PC 0x0c05ee24 */
if(!s->budget--) { s->failed_pc=0x0c05ee24u; return 0; }
r[6]=read(ram,r[14]+20,4);
goto P_0c05ee26;
P_0c05ee26: /* original d20c, guest PC 0x0c05ee26 */
if(!s->budget--) { s->failed_pc=0x0c05ee26u; return 0; }
r[2]=read(ram,0x0c05ee58u,4);
goto P_0c05ee28;
P_0c05ee28: /* original 420b, guest PC 0x0c05ee28 */
if(!s->budget--) { s->failed_pc=0x0c05ee28u; return 0; }
target=r[2];
r[16]=code_base|0x0c05ee2cu;
r[5]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ee2cu) { target=s->pc; goto dispatch; }
goto P_0c05ee2c;
P_0c05ee2a: /* original 55e7, guest PC 0x0c05ee2a */
if(!s->budget--) { s->failed_pc=0x0c05ee2au; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c05ee2c;
P_0c05ee2c: /* original 4f26, guest PC 0x0c05ee2c */
if(!s->budget--) { s->failed_pc=0x0c05ee2cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ee2e;
P_0c05ee2e: /* original e000, guest PC 0x0c05ee2e */
if(!s->budget--) { s->failed_pc=0x0c05ee2eu; return 0; }
r[0]=0x00000000u;
goto P_0c05ee30;
P_0c05ee30: /* original 000b, guest PC 0x0c05ee30 */
if(!s->budget--) { s->failed_pc=0x0c05ee30u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05ee32: /* original 6ef6, guest PC 0x0c05ee32 */
if(!s->budget--) { s->failed_pc=0x0c05ee32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05ee34u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05ee34u; return 0; } return 1;
P_0c05f33a: /* original 7504, guest PC 0x0c05f33a */
if(!s->budget--) { s->failed_pc=0x0c05f33au; return 0; }
r[5]+=0x00000004u;
if(!vf3_matrix_family(0x0c05f33cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05f33cu; return 0; } return 1;
P_0c05f3de: /* original 2fe6, guest PC 0x0c05f3de */
if(!s->budget--) { s->failed_pc=0x0c05f3deu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f3e0;
P_0c05f3e0: /* original 2fd6, guest PC 0x0c05f3e0 */
if(!s->budget--) { s->failed_pc=0x0c05f3e0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f3e2;
P_0c05f3e2: /* original 6e43, guest PC 0x0c05f3e2 */
if(!s->budget--) { s->failed_pc=0x0c05f3e2u; return 0; }
r[14]=r[4];
goto P_0c05f3e4;
P_0c05f3e4: /* original 2fc6, guest PC 0x0c05f3e4 */
if(!s->budget--) { s->failed_pc=0x0c05f3e4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f3e6;
P_0c05f3e6: /* original 6d53, guest PC 0x0c05f3e6 */
if(!s->budget--) { s->failed_pc=0x0c05f3e6u; return 0; }
r[13]=r[5];
goto P_0c05f3e8;
P_0c05f3e8: /* original 2fa6, guest PC 0x0c05f3e8 */
if(!s->budget--) { s->failed_pc=0x0c05f3e8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(0x0c05f3eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05f3eau; return 0; } return 1;
P_0c05fc32: /* original 4f22, guest PC 0x0c05fc32 */
if(!s->budget--) { s->failed_pc=0x0c05fc32u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05fc34;
P_0c05fc34: /* original d145, guest PC 0x0c05fc34 */
if(!s->budget--) { s->failed_pc=0x0c05fc34u; return 0; }
r[1]=read(ram,0x0c05fd4cu,4);
goto P_0c05fc36;
P_0c05fc36: /* original 410b, guest PC 0x0c05fc36 */
if(!s->budget--) { s->failed_pc=0x0c05fc36u; return 0; }
target=r[1];
r[16]=code_base|0x0c05fc3au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fc3au) { target=s->pc; goto dispatch; }
goto P_0c05fc3a;
P_0c05fc38: /* original 0009, guest PC 0x0c05fc38 */
if(!s->budget--) { s->failed_pc=0x0c05fc38u; return 0; }
goto P_0c05fc3a;
P_0c05fc3a: /* original d345, guest PC 0x0c05fc3a */
if(!s->budget--) { s->failed_pc=0x0c05fc3au; return 0; }
r[3]=read(ram,0x0c05fd50u,4);
goto P_0c05fc3c;
P_0c05fc3c: /* original 430b, guest PC 0x0c05fc3c */
if(!s->budget--) { s->failed_pc=0x0c05fc3cu; return 0; }
target=r[3];
r[16]=code_base|0x0c05fc40u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fc40u) { target=s->pc; goto dispatch; }
goto P_0c05fc40;
P_0c05fc3e: /* original 0009, guest PC 0x0c05fc3e */
if(!s->budget--) { s->failed_pc=0x0c05fc3eu; return 0; }
goto P_0c05fc40;
P_0c05fc40: /* original d144, guest PC 0x0c05fc40 */
if(!s->budget--) { s->failed_pc=0x0c05fc40u; return 0; }
r[1]=read(ram,0x0c05fd54u,4);
goto P_0c05fc42;
P_0c05fc42: /* original 410b, guest PC 0x0c05fc42 */
if(!s->budget--) { s->failed_pc=0x0c05fc42u; return 0; }
target=r[1];
r[16]=code_base|0x0c05fc46u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fc46u) { target=s->pc; goto dispatch; }
goto P_0c05fc46;
P_0c05fc44: /* original 0009, guest PC 0x0c05fc44 */
if(!s->budget--) { s->failed_pc=0x0c05fc44u; return 0; }
goto P_0c05fc46;
P_0c05fc46: /* original d344, guest PC 0x0c05fc46 */
if(!s->budget--) { s->failed_pc=0x0c05fc46u; return 0; }
r[3]=read(ram,0x0c05fd58u,4);
goto P_0c05fc48;
P_0c05fc48: /* original 430b, guest PC 0x0c05fc48 */
if(!s->budget--) { s->failed_pc=0x0c05fc48u; return 0; }
target=r[3];
r[16]=code_base|0x0c05fc4cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fc4cu) { target=s->pc; goto dispatch; }
goto P_0c05fc4c;
P_0c05fc4a: /* original 0009, guest PC 0x0c05fc4a */
if(!s->budget--) { s->failed_pc=0x0c05fc4au; return 0; }
goto P_0c05fc4c;
P_0c05fc4c: /* original d143, guest PC 0x0c05fc4c */
if(!s->budget--) { s->failed_pc=0x0c05fc4cu; return 0; }
r[1]=read(ram,0x0c05fd5cu,4);
goto P_0c05fc4e;
P_0c05fc4e: /* original 410b, guest PC 0x0c05fc4e */
if(!s->budget--) { s->failed_pc=0x0c05fc4eu; return 0; }
target=r[1];
r[16]=code_base|0x0c05fc52u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fc52u) { target=s->pc; goto dispatch; }
goto P_0c05fc52;
P_0c05fc50: /* original 0009, guest PC 0x0c05fc50 */
if(!s->budget--) { s->failed_pc=0x0c05fc50u; return 0; }
goto P_0c05fc52;
P_0c05fc52: /* original d343, guest PC 0x0c05fc52 */
if(!s->budget--) { s->failed_pc=0x0c05fc52u; return 0; }
r[3]=read(ram,0x0c05fd60u,4);
goto P_0c05fc54;
P_0c05fc54: /* original 430b, guest PC 0x0c05fc54 */
if(!s->budget--) { s->failed_pc=0x0c05fc54u; return 0; }
target=r[3];
r[16]=code_base|0x0c05fc58u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fc58u) { target=s->pc; goto dispatch; }
goto P_0c05fc58;
P_0c05fc56: /* original 0009, guest PC 0x0c05fc56 */
if(!s->budget--) { s->failed_pc=0x0c05fc56u; return 0; }
goto P_0c05fc58;
P_0c05fc58: /* original d142, guest PC 0x0c05fc58 */
if(!s->budget--) { s->failed_pc=0x0c05fc58u; return 0; }
r[1]=read(ram,0x0c05fd64u,4);
goto P_0c05fc5a;
P_0c05fc5a: /* original d043, guest PC 0x0c05fc5a */
if(!s->budget--) { s->failed_pc=0x0c05fc5au; return 0; }
r[0]=read(ram,0x0c05fd68u,4);
goto P_0c05fc5c;
P_0c05fc5c: /* original 2012, guest PC 0x0c05fc5c */
if(!s->budget--) { s->failed_pc=0x0c05fc5cu; return 0; }
write(ram,r[0],r[1],4);
goto P_0c05fc5e;
P_0c05fc5e: /* original ee00, guest PC 0x0c05fc5e */
if(!s->budget--) { s->failed_pc=0x0c05fc5eu; return 0; }
r[14]=0x00000000u;
goto P_0c05fc60;
P_0c05fc60: /* original d342, guest PC 0x0c05fc60 */
if(!s->budget--) { s->failed_pc=0x0c05fc60u; return 0; }
r[3]=read(ram,0x0c05fd6cu,4);
goto P_0c05fc62;
P_0c05fc62: /* original 23e2, guest PC 0x0c05fc62 */
if(!s->budget--) { s->failed_pc=0x0c05fc62u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05fc64;
P_0c05fc64: /* original d242, guest PC 0x0c05fc64 */
if(!s->budget--) { s->failed_pc=0x0c05fc64u; return 0; }
r[2]=read(ram,0x0c05fd70u,4);
goto P_0c05fc66;
P_0c05fc66: /* original 22e2, guest PC 0x0c05fc66 */
if(!s->budget--) { s->failed_pc=0x0c05fc66u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05fc68;
P_0c05fc68: /* original d142, guest PC 0x0c05fc68 */
if(!s->budget--) { s->failed_pc=0x0c05fc68u; return 0; }
r[1]=read(ram,0x0c05fd74u,4);
goto P_0c05fc6a;
P_0c05fc6a: /* original 21e2, guest PC 0x0c05fc6a */
if(!s->budget--) { s->failed_pc=0x0c05fc6au; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05fc6c;
P_0c05fc6c: /* original 2fe6, guest PC 0x0c05fc6c */
if(!s->budget--) { s->failed_pc=0x0c05fc6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05fc6e;
P_0c05fc6e: /* original d031, guest PC 0x0c05fc6e */
if(!s->budget--) { s->failed_pc=0x0c05fc6eu; return 0; }
r[0]=read(ram,0x0c05fd34u,4);
goto P_0c05fc70;
P_0c05fc70: /* original 6302, guest PC 0x0c05fc70 */
if(!s->budget--) { s->failed_pc=0x0c05fc70u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05fc72;
P_0c05fc72: /* original 2f36, guest PC 0x0c05fc72 */
if(!s->budget--) { s->failed_pc=0x0c05fc72u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05fc74;
P_0c05fc74: /* original d740, guest PC 0x0c05fc74 */
if(!s->budget--) { s->failed_pc=0x0c05fc74u; return 0; }
r[7]=read(ram,0x0c05fd78u,4);
goto P_0c05fc76;
P_0c05fc76: /* original 5773, guest PC 0x0c05fc76 */
if(!s->budget--) { s->failed_pc=0x0c05fc76u; return 0; }
r[7]=read(ram,r[7]+12,4);
goto P_0c05fc78;
P_0c05fc78: /* original e3f9, guest PC 0x0c05fc78 */
if(!s->budget--) { s->failed_pc=0x0c05fc78u; return 0; }
r[3]=0xfffffff9u;
goto P_0c05fc7a;
P_0c05fc7a: /* original 473d, guest PC 0x0c05fc7a */
if(!s->budget--) { s->failed_pc=0x0c05fc7au; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?r[7]>>((-r[3])&31u):0):r[7]<<(r[3]&31u);
goto P_0c05fc7c;
P_0c05fc7c: /* original d63e, guest PC 0x0c05fc7c */
if(!s->budget--) { s->failed_pc=0x0c05fc7cu; return 0; }
r[6]=read(ram,0x0c05fd78u,4);
goto P_0c05fc7e;
P_0c05fc7e: /* original 5662, guest PC 0x0c05fc7e */
if(!s->budget--) { s->failed_pc=0x0c05fc7eu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c05fc80;
P_0c05fc80: /* original 463d, guest PC 0x0c05fc80 */
if(!s->budget--) { s->failed_pc=0x0c05fc80u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?r[6]>>((-r[3])&31u):0):r[6]<<(r[3]&31u);
goto P_0c05fc82;
P_0c05fc82: /* original d53d, guest PC 0x0c05fc82 */
if(!s->budget--) { s->failed_pc=0x0c05fc82u; return 0; }
r[5]=read(ram,0x0c05fd78u,4);
goto P_0c05fc84;
P_0c05fc84: /* original 5551, guest PC 0x0c05fc84 */
if(!s->budget--) { s->failed_pc=0x0c05fc84u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c05fc86;
P_0c05fc86: /* original 453d, guest PC 0x0c05fc86 */
if(!s->budget--) { s->failed_pc=0x0c05fc86u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c05fc88;
P_0c05fc88: /* original d43b, guest PC 0x0c05fc88 */
if(!s->budget--) { s->failed_pc=0x0c05fc88u; return 0; }
r[4]=read(ram,0x0c05fd78u,4);
goto P_0c05fc8a;
P_0c05fc8a: /* original 6442, guest PC 0x0c05fc8a */
if(!s->budget--) { s->failed_pc=0x0c05fc8au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05fc8c;
P_0c05fc8c: /* original d23b, guest PC 0x0c05fc8c */
if(!s->budget--) { s->failed_pc=0x0c05fc8cu; return 0; }
r[2]=read(ram,0x0c05fd7cu,4);
goto P_0c05fc8e;
P_0c05fc8e: /* original 420b, guest PC 0x0c05fc8e */
if(!s->budget--) { s->failed_pc=0x0c05fc8eu; return 0; }
target=r[2];
r[16]=code_base|0x0c05fc92u;
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05fc92u) { target=s->pc; goto dispatch; }
goto P_0c05fc92;
P_0c05fc90: /* original 443d, guest PC 0x0c05fc90 */
if(!s->budget--) { s->failed_pc=0x0c05fc90u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c05fc92;
P_0c05fc92: /* original 7f08, guest PC 0x0c05fc92 */
if(!s->budget--) { s->failed_pc=0x0c05fc92u; return 0; }
r[15]+=0x00000008u;
goto P_0c05fc94;
P_0c05fc94: /* original 4f26, guest PC 0x0c05fc94 */
if(!s->budget--) { s->failed_pc=0x0c05fc94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05fc96;
P_0c05fc96: /* original 000b, guest PC 0x0c05fc96 */
if(!s->budget--) { s->failed_pc=0x0c05fc96u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05fc98: /* original 6ef6, guest PC 0x0c05fc98 */
if(!s->budget--) { s->failed_pc=0x0c05fc98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05fc9au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fc9au; return 0; } return 1;
P_0c06256e: /* original 4f22, guest PC 0x0c06256e */
if(!s->budget--) { s->failed_pc=0x0c06256eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c062570;
P_0c062570: /* original 3f0c, guest PC 0x0c062570 */
if(!s->budget--) { s->failed_pc=0x0c062570u; return 0; }
r[15]+=r[0];
goto P_0c062572;
P_0c062572: /* original 8f27, guest PC 0x0c062572 */
if(!s->budget--) { s->failed_pc=0x0c062572u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[5],4);
if(!cond) { goto P_0c0625c4; }
goto P_0c062576;
P_0c062574: /* original 2f52, guest PC 0x0c062574 */
if(!s->budget--) { s->failed_pc=0x0c062574u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062576;
P_0c062576: /* original 68f3, guest PC 0x0c062576 */
if(!s->budget--) { s->failed_pc=0x0c062576u; return 0; }
r[8]=r[15];
goto P_0c062578;
P_0c062578: /* original 7808, guest PC 0x0c062578 */
if(!s->budget--) { s->failed_pc=0x0c062578u; return 0; }
r[8]+=0x00000008u;
goto P_0c06257a;
P_0c06257a: /* original 66e3, guest PC 0x0c06257a */
if(!s->budget--) { s->failed_pc=0x0c06257au; return 0; }
r[6]=r[14];
goto P_0c06257c;
P_0c06257c: /* original 65f2, guest PC 0x0c06257c */
if(!s->budget--) { s->failed_pc=0x0c06257cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06257e;
P_0c06257e: /* original d307, guest PC 0x0c06257e */
if(!s->budget--) { s->failed_pc=0x0c06257eu; return 0; }
r[3]=read(ram,0x0c06259cu,4);
goto P_0c062580;
P_0c062580: /* original 430b, guest PC 0x0c062580 */
if(!s->budget--) { s->failed_pc=0x0c062580u; return 0; }
target=r[3];
r[16]=code_base|0x0c062584u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c062584u) { target=s->pc; goto dispatch; }
goto P_0c062584;
P_0c062582: /* original 6483, guest PC 0x0c062582 */
if(!s->budget--) { s->failed_pc=0x0c062582u; return 0; }
r[4]=r[8];
goto P_0c062584;
P_0c062584: /* original 6c83, guest PC 0x0c062584 */
if(!s->budget--) { s->failed_pc=0x0c062584u; return 0; }
r[12]=r[8];
goto P_0c062586;
P_0c062586: /* original a00f, guest PC 0x0c062586 */
if(!s->budget--) { s->failed_pc=0x0c062586u; return 0; }
r[11]=0x00000040u;
goto P_0c0625a8;
P_0c062588: /* original eb40, guest PC 0x0c062588 */
if(!s->budget--) { s->failed_pc=0x0c062588u; return 0; }
r[11]=0x00000040u;
if(!vf3_matrix_family(0x0c06258au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06258au; return 0; } return 1;
P_0c0625a0: /* original 4a0b, guest PC 0x0c0625a0 */
if(!s->budget--) { s->failed_pc=0x0c0625a0u; return 0; }
target=r[10];
r[16]=code_base|0x0c0625a4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625a4u) { target=s->pc; goto dispatch; }
goto P_0c0625a4;
P_0c0625a2: /* original 64c3, guest PC 0x0c0625a2 */
if(!s->budget--) { s->failed_pc=0x0c0625a2u; return 0; }
r[4]=r[12];
goto P_0c0625a4;
P_0c0625a4: /* original 7c20, guest PC 0x0c0625a4 */
if(!s->budget--) { s->failed_pc=0x0c0625a4u; return 0; }
r[12]+=0x00000020u;
goto P_0c0625a6;
P_0c0625a6: /* original 7bff, guest PC 0x0c0625a6 */
if(!s->budget--) { s->failed_pc=0x0c0625a6u; return 0; }
r[11]+=0xffffffffu;
goto P_0c0625a8;
P_0c0625a8: /* original 2bb8, guest PC 0x0c0625a8 */
if(!s->budget--) { s->failed_pc=0x0c0625a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0625aa;
P_0c0625aa: /* original 8bf9, guest PC 0x0c0625aa */
if(!s->budget--) { s->failed_pc=0x0c0625aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0625a0; }
goto P_0c0625ac;
P_0c0625ac: /* original d23e, guest PC 0x0c0625ac */
if(!s->budget--) { s->failed_pc=0x0c0625acu; return 0; }
r[2]=read(ram,0x0c0626a8u,4);
goto P_0c0625ae;
P_0c0625ae: /* original 66e3, guest PC 0x0c0625ae */
if(!s->budget--) { s->failed_pc=0x0c0625aeu; return 0; }
r[6]=r[14];
goto P_0c0625b0;
P_0c0625b0: /* original 6583, guest PC 0x0c0625b0 */
if(!s->budget--) { s->failed_pc=0x0c0625b0u; return 0; }
r[5]=r[8];
goto P_0c0625b2;
P_0c0625b2: /* original 420b, guest PC 0x0c0625b2 */
if(!s->budget--) { s->failed_pc=0x0c0625b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0625b6u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625b6u) { target=s->pc; goto dispatch; }
goto P_0c0625b6;
P_0c0625b4: /* original 6493, guest PC 0x0c0625b4 */
if(!s->budget--) { s->failed_pc=0x0c0625b4u; return 0; }
r[4]=r[9];
goto P_0c0625b6;
P_0c0625b6: /* original 3de8, guest PC 0x0c0625b6 */
if(!s->budget--) { s->failed_pc=0x0c0625b6u; return 0; }
r[13]-=r[14];
goto P_0c0625b8;
P_0c0625b8: /* original 63f2, guest PC 0x0c0625b8 */
if(!s->budget--) { s->failed_pc=0x0c0625b8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0625ba;
P_0c0625ba: /* original 3de6, guest PC 0x0c0625ba */
if(!s->budget--) { s->failed_pc=0x0c0625bau; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[14])!=0);
goto P_0c0625bc;
P_0c0625bc: /* original 33ec, guest PC 0x0c0625bc */
if(!s->budget--) { s->failed_pc=0x0c0625bcu; return 0; }
r[3]+=r[14];
goto P_0c0625be;
P_0c0625be: /* original 2f32, guest PC 0x0c0625be */
if(!s->budget--) { s->failed_pc=0x0c0625beu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0625c0;
P_0c0625c0: /* original 8ddb, guest PC 0x0c0625c0 */
if(!s->budget--) { s->failed_pc=0x0c0625c0u; return 0; }
cond=r[17]&1u;
r[9]+=r[14];
if(cond) { goto P_0c06257a; }
goto P_0c0625c4;
P_0c0625c2: /* original 39ec, guest PC 0x0c0625c2 */
if(!s->budget--) { s->failed_pc=0x0c0625c2u; return 0; }
r[9]+=r[14];
goto P_0c0625c4;
P_0c0625c4: /* original 65f2, guest PC 0x0c0625c4 */
if(!s->budget--) { s->failed_pc=0x0c0625c4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0625c6;
P_0c0625c6: /* original 64f3, guest PC 0x0c0625c6 */
if(!s->budget--) { s->failed_pc=0x0c0625c6u; return 0; }
r[4]=r[15];
goto P_0c0625c8;
P_0c0625c8: /* original d338, guest PC 0x0c0625c8 */
if(!s->budget--) { s->failed_pc=0x0c0625c8u; return 0; }
r[3]=read(ram,0x0c0626acu,4);
goto P_0c0625ca;
P_0c0625ca: /* original 66d3, guest PC 0x0c0625ca */
if(!s->budget--) { s->failed_pc=0x0c0625cau; return 0; }
r[6]=r[13];
goto P_0c0625cc;
P_0c0625cc: /* original 7408, guest PC 0x0c0625cc */
if(!s->budget--) { s->failed_pc=0x0c0625ccu; return 0; }
r[4]+=0x00000008u;
goto P_0c0625ce;
P_0c0625ce: /* original 430b, guest PC 0x0c0625ce */
if(!s->budget--) { s->failed_pc=0x0c0625ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0625d2u;
write(ram,r[15]+4,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625d2u) { target=s->pc; goto dispatch; }
goto P_0c0625d2;
P_0c0625d0: /* original 1f41, guest PC 0x0c0625d0 */
if(!s->budget--) { s->failed_pc=0x0c0625d0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0625d2;
P_0c0625d2: /* original 5ef1, guest PC 0x0c0625d2 */
if(!s->budget--) { s->failed_pc=0x0c0625d2u; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c0625d4;
P_0c0625d4: /* original a004, guest PC 0x0c0625d4 */
if(!s->budget--) { s->failed_pc=0x0c0625d4u; return 0; }
r[12]=0x00000040u;
goto P_0c0625e0;
P_0c0625d6: /* original ec40, guest PC 0x0c0625d6 */
if(!s->budget--) { s->failed_pc=0x0c0625d6u; return 0; }
r[12]=0x00000040u;
goto P_0c0625d8;
P_0c0625d8: /* original 4a0b, guest PC 0x0c0625d8 */
if(!s->budget--) { s->failed_pc=0x0c0625d8u; return 0; }
target=r[10];
r[16]=code_base|0x0c0625dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625dcu) { target=s->pc; goto dispatch; }
goto P_0c0625dc;
P_0c0625da: /* original 64e3, guest PC 0x0c0625da */
if(!s->budget--) { s->failed_pc=0x0c0625dau; return 0; }
r[4]=r[14];
goto P_0c0625dc;
P_0c0625dc: /* original 7e20, guest PC 0x0c0625dc */
if(!s->budget--) { s->failed_pc=0x0c0625dcu; return 0; }
r[14]+=0x00000020u;
goto P_0c0625de;
P_0c0625de: /* original 7cff, guest PC 0x0c0625de */
if(!s->budget--) { s->failed_pc=0x0c0625deu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0625e0;
P_0c0625e0: /* original 2cc8, guest PC 0x0c0625e0 */
if(!s->budget--) { s->failed_pc=0x0c0625e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0625e2;
P_0c0625e2: /* original 8bf9, guest PC 0x0c0625e2 */
if(!s->budget--) { s->failed_pc=0x0c0625e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0625d8; }
goto P_0c0625e4;
P_0c0625e4: /* original 55f1, guest PC 0x0c0625e4 */
if(!s->budget--) { s->failed_pc=0x0c0625e4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0625e6;
P_0c0625e6: /* original 66d3, guest PC 0x0c0625e6 */
if(!s->budget--) { s->failed_pc=0x0c0625e6u; return 0; }
r[6]=r[13];
goto P_0c0625e8;
P_0c0625e8: /* original d32f, guest PC 0x0c0625e8 */
if(!s->budget--) { s->failed_pc=0x0c0625e8u; return 0; }
r[3]=read(ram,0x0c0626a8u,4);
goto P_0c0625ea;
P_0c0625ea: /* original 430b, guest PC 0x0c0625ea */
if(!s->budget--) { s->failed_pc=0x0c0625eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0625eeu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0625eeu) { target=s->pc; goto dispatch; }
goto P_0c0625ee;
P_0c0625ec: /* original 6493, guest PC 0x0c0625ec */
if(!s->budget--) { s->failed_pc=0x0c0625ecu; return 0; }
r[4]=r[9];
goto P_0c0625ee;
P_0c0625ee: /* original 9159, guest PC 0x0c0625ee */
if(!s->budget--) { s->failed_pc=0x0c0625eeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0626a4u,2);
goto P_0c0625f0;
P_0c0625f0: /* original 3f1c, guest PC 0x0c0625f0 */
if(!s->budget--) { s->failed_pc=0x0c0625f0u; return 0; }
r[15]+=r[1];
goto P_0c0625f2;
P_0c0625f2: /* original 4f26, guest PC 0x0c0625f2 */
if(!s->budget--) { s->failed_pc=0x0c0625f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0625f4;
P_0c0625f4: /* original 68f6, guest PC 0x0c0625f4 */
if(!s->budget--) { s->failed_pc=0x0c0625f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0625f6;
P_0c0625f6: /* original 69f6, guest PC 0x0c0625f6 */
if(!s->budget--) { s->failed_pc=0x0c0625f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0625f8;
P_0c0625f8: /* original 6af6, guest PC 0x0c0625f8 */
if(!s->budget--) { s->failed_pc=0x0c0625f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0625fa;
P_0c0625fa: /* original 6bf6, guest PC 0x0c0625fa */
if(!s->budget--) { s->failed_pc=0x0c0625fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0625fc;
P_0c0625fc: /* original 6cf6, guest PC 0x0c0625fc */
if(!s->budget--) { s->failed_pc=0x0c0625fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0625fe;
P_0c0625fe: /* original 6df6, guest PC 0x0c0625fe */
if(!s->budget--) { s->failed_pc=0x0c0625feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062600;
P_0c062600: /* original 000b, guest PC 0x0c062600 */
if(!s->budget--) { s->failed_pc=0x0c062600u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c062602: /* original 6ef6, guest PC 0x0c062602 */
if(!s->budget--) { s->failed_pc=0x0c062602u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c062604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062604u; return 0; } return 1;
P_0c06da9c: /* original 2fe6, guest PC 0x0c06da9c */
if(!s->budget--) { s->failed_pc=0x0c06da9cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06da9e;
P_0c06da9e: /* original 2fd6, guest PC 0x0c06da9e */
if(!s->budget--) { s->failed_pc=0x0c06da9eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06daa0;
P_0c06daa0: /* original 2fc6, guest PC 0x0c06daa0 */
if(!s->budget--) { s->failed_pc=0x0c06daa0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06daa2;
P_0c06daa2: /* original 4f22, guest PC 0x0c06daa2 */
if(!s->budget--) { s->failed_pc=0x0c06daa2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06daa4;
P_0c06daa4: /* original d342, guest PC 0x0c06daa4 */
if(!s->budget--) { s->failed_pc=0x0c06daa4u; return 0; }
r[3]=read(ram,0x0c06dbb0u,4);
goto P_0c06daa6;
P_0c06daa6: /* original d441, guest PC 0x0c06daa6 */
if(!s->budget--) { s->failed_pc=0x0c06daa6u; return 0; }
r[4]=read(ram,0x0c06dbacu,4);
goto P_0c06daa8;
P_0c06daa8: /* original 430b, guest PC 0x0c06daa8 */
if(!s->budget--) { s->failed_pc=0x0c06daa8u; return 0; }
target=r[3];
r[16]=code_base|0x0c06daacu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06daacu) { target=s->pc; goto dispatch; }
goto P_0c06daac;
P_0c06daaa: /* original 0009, guest PC 0x0c06daaa */
if(!s->budget--) { s->failed_pc=0x0c06daaau; return 0; }
goto P_0c06daac;
P_0c06daac: /* original d242, guest PC 0x0c06daac */
if(!s->budget--) { s->failed_pc=0x0c06daacu; return 0; }
r[2]=read(ram,0x0c06dbb8u,4);
goto P_0c06daae;
P_0c06daae: /* original d541, guest PC 0x0c06daae */
if(!s->budget--) { s->failed_pc=0x0c06daaeu; return 0; }
r[5]=read(ram,0x0c06dbb4u,4);
goto P_0c06dab0;
P_0c06dab0: /* original 947a, guest PC 0x0c06dab0 */
if(!s->budget--) { s->failed_pc=0x0c06dab0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06dba8u,2);
goto P_0c06dab2;
P_0c06dab2: /* original 420b, guest PC 0x0c06dab2 */
if(!s->budget--) { s->failed_pc=0x0c06dab2u; return 0; }
target=r[2];
r[16]=code_base|0x0c06dab6u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06dab6u) { target=s->pc; goto dispatch; }
goto P_0c06dab6;
P_0c06dab4: /* original e601, guest PC 0x0c06dab4 */
if(!s->budget--) { s->failed_pc=0x0c06dab4u; return 0; }
r[6]=0x00000001u;
goto P_0c06dab6;
P_0c06dab6: /* original 9478, guest PC 0x0c06dab6 */
if(!s->budget--) { s->failed_pc=0x0c06dab6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06dbaau,2);
goto P_0c06dab8;
P_0c06dab8: /* original e301, guest PC 0x0c06dab8 */
if(!s->budget--) { s->failed_pc=0x0c06dab8u; return 0; }
r[3]=0x00000001u;
goto P_0c06daba;
P_0c06daba: /* original 2f36, guest PC 0x0c06daba */
if(!s->budget--) { s->failed_pc=0x0c06dabau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06dabc;
P_0c06dabc: /* original d140, guest PC 0x0c06dabc */
if(!s->budget--) { s->failed_pc=0x0c06dabcu; return 0; }
r[1]=read(ram,0x0c06dbc0u,4);
goto P_0c06dabe;
P_0c06dabe: /* original d23f, guest PC 0x0c06dabe */
if(!s->budget--) { s->failed_pc=0x0c06dabeu; return 0; }
r[2]=read(ram,0x0c06dbbcu,4);
goto P_0c06dac0;
P_0c06dac0: /* original 410b, guest PC 0x0c06dac0 */
if(!s->budget--) { s->failed_pc=0x0c06dac0u; return 0; }
target=r[1];
r[16]=code_base|0x0c06dac4u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06dac4u) { target=s->pc; goto dispatch; }
goto P_0c06dac4;
P_0c06dac2: /* original 2f26, guest PC 0x0c06dac2 */
if(!s->budget--) { s->failed_pc=0x0c06dac2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06dac4;
P_0c06dac4: /* original b036, guest PC 0x0c06dac4 */
if(!s->budget--) { s->failed_pc=0x0c06dac4u; return 0; }
target=code_base|0x0c06db34u; r[16]=code_base|0x0c06dac8u;
r[15]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06dac8u) { target=s->pc; goto dispatch; }
goto P_0c06dac8;
P_0c06dac6: /* original 7f08, guest PC 0x0c06dac6 */
if(!s->budget--) { s->failed_pc=0x0c06dac6u; return 0; }
r[15]+=0x00000008u;
goto P_0c06dac8;
P_0c06dac8: /* original de3f, guest PC 0x0c06dac8 */
if(!s->budget--) { s->failed_pc=0x0c06dac8u; return 0; }
r[14]=read(ram,0x0c06dbc8u,4);
goto P_0c06daca;
P_0c06daca: /* original ec14, guest PC 0x0c06daca */
if(!s->budget--) { s->failed_pc=0x0c06dacau; return 0; }
r[12]=0x00000014u;
goto P_0c06dacc;
P_0c06dacc: /* original dd3d, guest PC 0x0c06dacc */
if(!s->budget--) { s->failed_pc=0x0c06daccu; return 0; }
r[13]=read(ram,0x0c06dbc4u,4);
goto P_0c06dace;
P_0c06dace: /* original 65e5, guest PC 0x0c06dace */
if(!s->budget--) { s->failed_pc=0x0c06daceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[5]=tmp;
goto P_0c06dad0;
P_0c06dad0: /* original b008, guest PC 0x0c06dad0 */
if(!s->budget--) { s->failed_pc=0x0c06dad0u; return 0; }
target=code_base|0x0c06dae4u; r[16]=code_base|0x0c06dad4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06dad4u) { target=s->pc; goto dispatch; }
goto P_0c06dad4;
P_0c06dad2: /* original 64d3, guest PC 0x0c06dad2 */
if(!s->budget--) { s->failed_pc=0x0c06dad2u; return 0; }
r[4]=r[13];
goto P_0c06dad4;
P_0c06dad4: /* original 4c10, guest PC 0x0c06dad4 */
if(!s->budget--) { s->failed_pc=0x0c06dad4u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c06dad6;
P_0c06dad6: /* original 8ffa, guest PC 0x0c06dad6 */
if(!s->budget--) { s->failed_pc=0x0c06dad6u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000014u;
if(!cond) { goto P_0c06dace; }
goto P_0c06dada;
P_0c06dad8: /* original 7d14, guest PC 0x0c06dad8 */
if(!s->budget--) { s->failed_pc=0x0c06dad8u; return 0; }
r[13]+=0x00000014u;
goto P_0c06dada;
P_0c06dada: /* original 4f26, guest PC 0x0c06dada */
if(!s->budget--) { s->failed_pc=0x0c06dadau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06dadc;
P_0c06dadc: /* original 6cf6, guest PC 0x0c06dadc */
if(!s->budget--) { s->failed_pc=0x0c06dadcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06dade;
P_0c06dade: /* original 6df6, guest PC 0x0c06dade */
if(!s->budget--) { s->failed_pc=0x0c06dadeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06dae0;
P_0c06dae0: /* original a02a, guest PC 0x0c06dae0 */
if(!s->budget--) { s->failed_pc=0x0c06dae0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06db38;
P_0c06dae2: /* original 6ef6, guest PC 0x0c06dae2 */
if(!s->budget--) { s->failed_pc=0x0c06dae2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06dae4;
P_0c06dae4: /* original 2fe6, guest PC 0x0c06dae4 */
if(!s->budget--) { s->failed_pc=0x0c06dae4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06dae6;
P_0c06dae6: /* original 6e43, guest PC 0x0c06dae6 */
if(!s->budget--) { s->failed_pc=0x0c06dae6u; return 0; }
r[14]=r[4];
if(!vf3_matrix_family(0x0c06dae8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06dae8u; return 0; } return 1;
P_0c06db34: /* original 000b, guest PC 0x0c06db34 */
if(!s->budget--) { s->failed_pc=0x0c06db34u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06db36: /* original 0009, guest PC 0x0c06db36 */
if(!s->budget--) { s->failed_pc=0x0c06db36u; return 0; }
goto P_0c06db38;
P_0c06db38: /* original 000b, guest PC 0x0c06db38 */
if(!s->budget--) { s->failed_pc=0x0c06db38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06db3a: /* original 0009, guest PC 0x0c06db3a */
if(!s->budget--) { s->failed_pc=0x0c06db3au; return 0; }
goto P_0c06db3c;
P_0c06db3c: /* original 2fe6, guest PC 0x0c06db3c */
if(!s->budget--) { s->failed_pc=0x0c06db3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(0x0c06db3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06db3eu; return 0; } return 1;
P_0c06dc44: /* original 2fe6, guest PC 0x0c06dc44 */
if(!s->budget--) { s->failed_pc=0x0c06dc44u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(0x0c06dc46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06dc46u; return 0; } return 1;
P_0c07ba28: /* original 2fe6, guest PC 0x0c07ba28 */
if(!s->budget--) { s->failed_pc=0x0c07ba28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2a;
P_0c07ba2a: /* original 2fd6, guest PC 0x0c07ba2a */
if(!s->budget--) { s->failed_pc=0x0c07ba2au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2c;
P_0c07ba2c: /* original 2fc6, guest PC 0x0c07ba2c */
if(!s->budget--) { s->failed_pc=0x0c07ba2cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2e;
P_0c07ba2e: /* original 2fb6, guest PC 0x0c07ba2e */
if(!s->budget--) { s->failed_pc=0x0c07ba2eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba30;
P_0c07ba30: /* original 2fa6, guest PC 0x0c07ba30 */
if(!s->budget--) { s->failed_pc=0x0c07ba30u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba32;
P_0c07ba32: /* original 2f96, guest PC 0x0c07ba32 */
if(!s->budget--) { s->failed_pc=0x0c07ba32u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba34;
P_0c07ba34: /* original 2f86, guest PC 0x0c07ba34 */
if(!s->budget--) { s->failed_pc=0x0c07ba34u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba36;
P_0c07ba36: /* original fffb, guest PC 0x0c07ba36 */
if(!s->budget--) { s->failed_pc=0x0c07ba36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07ba38;
P_0c07ba38: /* original ffeb, guest PC 0x0c07ba38 */
if(!s->budget--) { s->failed_pc=0x0c07ba38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c07ba3a;
P_0c07ba3a: /* original 4f22, guest PC 0x0c07ba3a */
if(!s->budget--) { s->failed_pc=0x0c07ba3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ba3c;
P_0c07ba3c: /* original d24b, guest PC 0x0c07ba3c */
if(!s->budget--) { s->failed_pc=0x0c07ba3cu; return 0; }
r[2]=read(ram,0x0c07bb6cu,4);
goto P_0c07ba3e;
P_0c07ba3e: /* original 9083, guest PC 0x0c07ba3e */
if(!s->budget--) { s->failed_pc=0x0c07ba3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb48u,2);
goto P_0c07ba40;
P_0c07ba40: /* original 4f12, guest PC 0x0c07ba40 */
if(!s->budget--) { s->failed_pc=0x0c07ba40u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c07ba42;
P_0c07ba42: /* original 6322, guest PC 0x0c07ba42 */
if(!s->budget--) { s->failed_pc=0x0c07ba42u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07ba44;
P_0c07ba44: /* original dd48, guest PC 0x0c07ba44 */
if(!s->budget--) { s->failed_pc=0x0c07ba44u; return 0; }
r[13]=read(ram,0x0c07bb68u,4);
goto P_0c07ba46;
P_0c07ba46: /* original 3f0c, guest PC 0x0c07ba46 */
if(!s->budget--) { s->failed_pc=0x0c07ba46u; return 0; }
r[15]+=r[0];
goto P_0c07ba48;
P_0c07ba48: /* original 1f3d, guest PC 0x0c07ba48 */
if(!s->budget--) { s->failed_pc=0x0c07ba48u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c07ba4a;
P_0c07ba4a: /* original d349, guest PC 0x0c07ba4a */
if(!s->budget--) { s->failed_pc=0x0c07ba4au; return 0; }
r[3]=read(ram,0x0c07bb70u,4);
goto P_0c07ba4c;
P_0c07ba4c: /* original 6132, guest PC 0x0c07ba4c */
if(!s->budget--) { s->failed_pc=0x0c07ba4cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07ba4e;
P_0c07ba4e: /* original 1f1c, guest PC 0x0c07ba4e */
if(!s->budget--) { s->failed_pc=0x0c07ba4eu; return 0; }
write(ram,r[15]+48,r[1],4);
goto P_0c07ba50;
P_0c07ba50: /* original 50d2, guest PC 0x0c07ba50 */
if(!s->budget--) { s->failed_pc=0x0c07ba50u; return 0; }
r[0]=read(ram,r[13]+8,4);
goto P_0c07ba52;
P_0c07ba52: /* original d148, guest PC 0x0c07ba52 */
if(!s->budget--) { s->failed_pc=0x0c07ba52u; return 0; }
r[1]=read(ram,0x0c07bb74u,4);
goto P_0c07ba54;
P_0c07ba54: /* original 2018, guest PC 0x0c07ba54 */
if(!s->budget--) { s->failed_pc=0x0c07ba54u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c07ba56;
P_0c07ba56: /* original 8f1a, guest PC 0x0c07ba56 */
if(!s->budget--) { s->failed_pc=0x0c07ba56u; return 0; }
cond=r[17]&1u;
r[11]=0x00000020u;
if(!cond) { goto P_0c07ba8e; }
goto P_0c07ba5a;
P_0c07ba58: /* original eb20, guest PC 0x0c07ba58 */
if(!s->budget--) { s->failed_pc=0x0c07ba58u; return 0; }
r[11]=0x00000020u;
goto P_0c07ba5a;
P_0c07ba5a: /* original 53fd, guest PC 0x0c07ba5a */
if(!s->budget--) { s->failed_pc=0x0c07ba5au; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c07ba5c;
P_0c07ba5c: /* original 23b8, guest PC 0x0c07ba5c */
if(!s->budget--) { s->failed_pc=0x0c07ba5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c07ba5e;
P_0c07ba5e: /* original 8902, guest PC 0x0c07ba5e */
if(!s->budget--) { s->failed_pc=0x0c07ba5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba66; }
goto P_0c07ba60;
P_0c07ba60: /* original d145, guest PC 0x0c07ba60 */
if(!s->budget--) { s->failed_pc=0x0c07ba60u; return 0; }
r[1]=read(ram,0x0c07bb78u,4);
goto P_0c07ba62;
P_0c07ba62: /* original 410b, guest PC 0x0c07ba62 */
if(!s->budget--) { s->failed_pc=0x0c07ba62u; return 0; }
target=r[1];
r[16]=code_base|0x0c07ba66u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba66u) { target=s->pc; goto dispatch; }
goto P_0c07ba66;
P_0c07ba64: /* original 0009, guest PC 0x0c07ba64 */
if(!s->budget--) { s->failed_pc=0x0c07ba64u; return 0; }
goto P_0c07ba66;
P_0c07ba66: /* original 50fd, guest PC 0x0c07ba66 */
if(!s->budget--) { s->failed_pc=0x0c07ba66u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07ba68;
P_0c07ba68: /* original c880, guest PC 0x0c07ba68 */
if(!s->budget--) { s->failed_pc=0x0c07ba68u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c07ba6a;
P_0c07ba6a: /* original 8902, guest PC 0x0c07ba6a */
if(!s->budget--) { s->failed_pc=0x0c07ba6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba72; }
goto P_0c07ba6c;
P_0c07ba6c: /* original d243, guest PC 0x0c07ba6c */
if(!s->budget--) { s->failed_pc=0x0c07ba6cu; return 0; }
r[2]=read(ram,0x0c07bb7cu,4);
goto P_0c07ba6e;
P_0c07ba6e: /* original 420b, guest PC 0x0c07ba6e */
if(!s->budget--) { s->failed_pc=0x0c07ba6eu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba72u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba72u) { target=s->pc; goto dispatch; }
goto P_0c07ba72;
P_0c07ba70: /* original 0009, guest PC 0x0c07ba70 */
if(!s->budget--) { s->failed_pc=0x0c07ba70u; return 0; }
goto P_0c07ba72;
P_0c07ba72: /* original 52fd, guest PC 0x0c07ba72 */
if(!s->budget--) { s->failed_pc=0x0c07ba72u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c07ba74;
P_0c07ba74: /* original 9369, guest PC 0x0c07ba74 */
if(!s->budget--) { s->failed_pc=0x0c07ba74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4au,2);
goto P_0c07ba76;
P_0c07ba76: /* original 2238, guest PC 0x0c07ba76 */
if(!s->budget--) { s->failed_pc=0x0c07ba76u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07ba78;
P_0c07ba78: /* original 8902, guest PC 0x0c07ba78 */
if(!s->budget--) { s->failed_pc=0x0c07ba78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba80; }
goto P_0c07ba7a;
P_0c07ba7a: /* original d241, guest PC 0x0c07ba7a */
if(!s->budget--) { s->failed_pc=0x0c07ba7au; return 0; }
r[2]=read(ram,0x0c07bb80u,4);
goto P_0c07ba7c;
P_0c07ba7c: /* original 420b, guest PC 0x0c07ba7c */
if(!s->budget--) { s->failed_pc=0x0c07ba7cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba80u) { target=s->pc; goto dispatch; }
goto P_0c07ba80;
P_0c07ba7e: /* original 0009, guest PC 0x0c07ba7e */
if(!s->budget--) { s->failed_pc=0x0c07ba7eu; return 0; }
goto P_0c07ba80;
P_0c07ba80: /* original 51fd, guest PC 0x0c07ba80 */
if(!s->budget--) { s->failed_pc=0x0c07ba80u; return 0; }
r[1]=read(ram,r[15]+52,4);
goto P_0c07ba82;
P_0c07ba82: /* original 9363, guest PC 0x0c07ba82 */
if(!s->budget--) { s->failed_pc=0x0c07ba82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4cu,2);
goto P_0c07ba84;
P_0c07ba84: /* original 2138, guest PC 0x0c07ba84 */
if(!s->budget--) { s->failed_pc=0x0c07ba84u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07ba86;
P_0c07ba86: /* original 8902, guest PC 0x0c07ba86 */
if(!s->budget--) { s->failed_pc=0x0c07ba86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba8e; }
goto P_0c07ba88;
P_0c07ba88: /* original d23e, guest PC 0x0c07ba88 */
if(!s->budget--) { s->failed_pc=0x0c07ba88u; return 0; }
r[2]=read(ram,0x0c07bb84u,4);
goto P_0c07ba8a;
P_0c07ba8a: /* original 420b, guest PC 0x0c07ba8a */
if(!s->budget--) { s->failed_pc=0x0c07ba8au; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba8eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba8eu) { target=s->pc; goto dispatch; }
goto P_0c07ba8e;
P_0c07ba8c: /* original 0009, guest PC 0x0c07ba8c */
if(!s->budget--) { s->failed_pc=0x0c07ba8cu; return 0; }
goto P_0c07ba8e;
P_0c07ba8e: /* original 50fd, guest PC 0x0c07ba8e */
if(!s->budget--) { s->failed_pc=0x0c07ba8eu; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07ba90;
P_0c07ba90: /* original c801, guest PC 0x0c07ba90 */
if(!s->budget--) { s->failed_pc=0x0c07ba90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07ba92;
P_0c07ba92: /* original 8905, guest PC 0x0c07ba92 */
if(!s->budget--) { s->failed_pc=0x0c07ba92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07baa0; }
goto P_0c07ba94;
P_0c07ba94: /* original d13c, guest PC 0x0c07ba94 */
if(!s->budget--) { s->failed_pc=0x0c07ba94u; return 0; }
r[1]=read(ram,0x0c07bb88u,4);
goto P_0c07ba96;
P_0c07ba96: /* original 410b, guest PC 0x0c07ba96 */
if(!s->budget--) { s->failed_pc=0x0c07ba96u; return 0; }
target=r[1];
r[16]=code_base|0x0c07ba9au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba9au) { target=s->pc; goto dispatch; }
goto P_0c07ba9a;
P_0c07ba98: /* original 0009, guest PC 0x0c07ba98 */
if(!s->budget--) { s->failed_pc=0x0c07ba98u; return 0; }
goto P_0c07ba9a;
P_0c07ba9a: /* original 53fc, guest PC 0x0c07ba9a */
if(!s->budget--) { s->failed_pc=0x0c07ba9au; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07ba9c;
P_0c07ba9c: /* original 230b, guest PC 0x0c07ba9c */
if(!s->budget--) { s->failed_pc=0x0c07ba9cu; return 0; }
r[3]|=r[0];
goto P_0c07ba9e;
P_0c07ba9e: /* original 1f3c, guest PC 0x0c07ba9e */
if(!s->budget--) { s->failed_pc=0x0c07ba9eu; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c07baa0;
P_0c07baa0: /* original 53fd, guest PC 0x0c07baa0 */
if(!s->budget--) { s->failed_pc=0x0c07baa0u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c07baa2;
P_0c07baa2: /* original ee00, guest PC 0x0c07baa2 */
if(!s->budget--) { s->failed_pc=0x0c07baa2u; return 0; }
r[14]=0x00000000u;
goto P_0c07baa4;
P_0c07baa4: /* original 9453, guest PC 0x0c07baa4 */
if(!s->budget--) { s->failed_pc=0x0c07baa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4eu,2);
goto P_0c07baa6;
P_0c07baa6: /* original 52fc, guest PC 0x0c07baa6 */
if(!s->budget--) { s->failed_pc=0x0c07baa6u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c07baa8;
P_0c07baa8: /* original 2439, guest PC 0x0c07baa8 */
if(!s->budget--) { s->failed_pc=0x0c07baa8u; return 0; }
r[4]&=r[3];
goto P_0c07baaa;
P_0c07baaa: /* original 242b, guest PC 0x0c07baaa */
if(!s->budget--) { s->failed_pc=0x0c07baaau; return 0; }
r[4]|=r[2];
goto P_0c07baac;
P_0c07baac: /* original 6043, guest PC 0x0c07baac */
if(!s->budget--) { s->failed_pc=0x0c07baacu; return 0; }
r[0]=r[4];
goto P_0c07baae;
P_0c07baae: /* original 1f4c, guest PC 0x0c07baae */
if(!s->budget--) { s->failed_pc=0x0c07baaeu; return 0; }
write(ram,r[15]+48,r[4],4);
goto P_0c07bab0;
P_0c07bab0: /* original d330, guest PC 0x0c07bab0 */
if(!s->budget--) { s->failed_pc=0x0c07bab0u; return 0; }
r[3]=read(ram,0x0c07bb74u,4);
goto P_0c07bab2;
P_0c07bab2: /* original c904, guest PC 0x0c07bab2 */
if(!s->budget--) { s->failed_pc=0x0c07bab2u; return 0; }
r[0]&=4u;
goto P_0c07bab4;
P_0c07bab4: /* original 52d2, guest PC 0x0c07bab4 */
if(!s->budget--) { s->failed_pc=0x0c07bab4u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c07bab6;
P_0c07bab6: /* original 2238, guest PC 0x0c07bab6 */
if(!s->budget--) { s->failed_pc=0x0c07bab6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07bab8;
P_0c07bab8: /* original 8f02, guest PC 0x0c07bab8 */
if(!s->budget--) { s->failed_pc=0x0c07bab8u; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(!cond) { goto P_0c07bac0; }
goto P_0c07babc;
P_0c07baba: /* original 6c03, guest PC 0x0c07baba */
if(!s->budget--) { s->failed_pc=0x0c07babau; return 0; }
r[12]=r[0];
goto P_0c07babc;
P_0c07babc: /* original a408, guest PC 0x0c07babc */
if(!s->budget--) { s->failed_pc=0x0c07babcu; return 0; }
goto P_0c07c2d0;
P_0c07babe: /* original 0009, guest PC 0x0c07babe */
if(!s->budget--) { s->failed_pc=0x0c07babeu; return 0; }
goto P_0c07bac0;
P_0c07bac0: /* original 2cc8, guest PC 0x0c07bac0 */
if(!s->budget--) { s->failed_pc=0x0c07bac0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07bac2;
P_0c07bac2: /* original 8b01, guest PC 0x0c07bac2 */
if(!s->budget--) { s->failed_pc=0x0c07bac2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bac8; }
goto P_0c07bac4;
P_0c07bac4: /* original a415, guest PC 0x0c07bac4 */
if(!s->budget--) { s->failed_pc=0x0c07bac4u; return 0; }
goto P_0c07c2f2;
P_0c07bac6: /* original 0009, guest PC 0x0c07bac6 */
if(!s->budget--) { s->failed_pc=0x0c07bac6u; return 0; }
goto P_0c07bac8;
P_0c07bac8: /* original d231, guest PC 0x0c07bac8 */
if(!s->budget--) { s->failed_pc=0x0c07bac8u; return 0; }
r[2]=read(ram,0x0c07bb90u,4);
goto P_0c07baca;
P_0c07baca: /* original e026, guest PC 0x0c07baca */
if(!s->budget--) { s->failed_pc=0x0c07bacau; return 0; }
r[0]=0x00000026u;
goto P_0c07bacc;
P_0c07bacc: /* original dd2f, guest PC 0x0c07bacc */
if(!s->budget--) { s->failed_pc=0x0c07baccu; return 0; }
r[13]=read(ram,0x0c07bb8cu,4);
goto P_0c07bace;
P_0c07bace: /* original e553, guest PC 0x0c07bace */
if(!s->budget--) { s->failed_pc=0x0c07baceu; return 0; }
r[5]=0x00000053u;
goto P_0c07bad0;
P_0c07bad0: /* original 2f22, guest PC 0x0c07bad0 */
if(!s->budget--) { s->failed_pc=0x0c07bad0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07bad2;
P_0c07bad2: /* original e209, guest PC 0x0c07bad2 */
if(!s->budget--) { s->failed_pc=0x0c07bad2u; return 0; }
r[2]=0x00000009u;
goto P_0c07bad4;
P_0c07bad4: /* original 7d2c, guest PC 0x0c07bad4 */
if(!s->budget--) { s->failed_pc=0x0c07bad4u; return 0; }
r[13]+=0x0000002cu;
goto P_0c07bad6;
P_0c07bad6: /* original 0d25, guest PC 0x0c07bad6 */
if(!s->budget--) { s->failed_pc=0x0c07bad6u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07bad8;
P_0c07bad8: /* original e022, guest PC 0x0c07bad8 */
if(!s->budget--) { s->failed_pc=0x0c07bad8u; return 0; }
r[0]=0x00000022u;
goto P_0c07bada;
P_0c07bada: /* original 01dd, guest PC 0x0c07bada */
if(!s->budget--) { s->failed_pc=0x0c07badau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07badc;
P_0c07badc: /* original e202, guest PC 0x0c07badc */
if(!s->budget--) { s->failed_pc=0x0c07badcu; return 0; }
r[2]=0x00000002u;
goto P_0c07bade;
P_0c07bade: /* original 212b, guest PC 0x0c07bade */
if(!s->budget--) { s->failed_pc=0x0c07badeu; return 0; }
r[1]|=r[2];
goto P_0c07bae0;
P_0c07bae0: /* original 0d15, guest PC 0x0c07bae0 */
if(!s->budget--) { s->failed_pc=0x0c07bae0u; return 0; }
write(ram,r[13]+r[0],r[1],2);
goto P_0c07bae2;
P_0c07bae2: /* original d12c, guest PC 0x0c07bae2 */
if(!s->budget--) { s->failed_pc=0x0c07bae2u; return 0; }
r[1]=read(ram,0x0c07bb94u,4);
goto P_0c07bae4;
P_0c07bae4: /* original 410b, guest PC 0x0c07bae4 */
if(!s->budget--) { s->failed_pc=0x0c07bae4u; return 0; }
target=r[1];
r[16]=code_base|0x0c07bae8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bae8u) { target=s->pc; goto dispatch; }
goto P_0c07bae8;
P_0c07bae6: /* original 64d3, guest PC 0x0c07bae6 */
if(!s->budget--) { s->failed_pc=0x0c07bae6u; return 0; }
r[4]=r[13];
goto P_0c07bae8;
P_0c07bae8: /* original 9332, guest PC 0x0c07bae8 */
if(!s->budget--) { s->failed_pc=0x0c07bae8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb50u,2);
goto P_0c07baea;
P_0c07baea: /* original 33fc, guest PC 0x0c07baea */
if(!s->budget--) { s->failed_pc=0x0c07baeau; return 0; }
r[3]+=r[15];
goto P_0c07baec;
P_0c07baec: /* original 1f31, guest PC 0x0c07baec */
if(!s->budget--) { s->failed_pc=0x0c07baecu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07baee;
P_0c07baee: /* original 62f2, guest PC 0x0c07baee */
if(!s->budget--) { s->failed_pc=0x0c07baeeu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07baf0;
P_0c07baf0: /* original 902f, guest PC 0x0c07baf0 */
if(!s->budget--) { s->failed_pc=0x0c07baf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb52u,2);
goto P_0c07baf2;
P_0c07baf2: /* original 012d, guest PC 0x0c07baf2 */
if(!s->budget--) { s->failed_pc=0x0c07baf2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07baf4;
P_0c07baf4: /* original 611d, guest PC 0x0c07baf4 */
if(!s->budget--) { s->failed_pc=0x0c07baf4u; return 0; }
r[1]=r[1]&65535u;
goto P_0c07baf6;
P_0c07baf6: /* original 2312, guest PC 0x0c07baf6 */
if(!s->budget--) { s->failed_pc=0x0c07baf6u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c07baf8;
P_0c07baf8: /* original 902c, guest PC 0x0c07baf8 */
if(!s->budget--) { s->failed_pc=0x0c07baf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb54u,2);
goto P_0c07bafa;
P_0c07bafa: /* original 63f2, guest PC 0x0c07bafa */
if(!s->budget--) { s->failed_pc=0x0c07bafau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bafc;
P_0c07bafc: /* original 54f1, guest PC 0x0c07bafc */
if(!s->budget--) { s->failed_pc=0x0c07bafcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07bafe;
P_0c07bafe: /* original 023d, guest PC 0x0c07bafe */
if(!s->budget--) { s->failed_pc=0x0c07bafeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb00;
P_0c07bb00: /* original 7408, guest PC 0x0c07bb00 */
if(!s->budget--) { s->failed_pc=0x0c07bb00u; return 0; }
r[4]+=0x00000008u;
goto P_0c07bb02;
P_0c07bb02: /* original 622d, guest PC 0x0c07bb02 */
if(!s->budget--) { s->failed_pc=0x0c07bb02u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb04;
P_0c07bb04: /* original 2422, guest PC 0x0c07bb04 */
if(!s->budget--) { s->failed_pc=0x0c07bb04u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c07bb06;
P_0c07bb06: /* original 9026, guest PC 0x0c07bb06 */
if(!s->budget--) { s->failed_pc=0x0c07bb06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb56u,2);
goto P_0c07bb08;
P_0c07bb08: /* original 62f2, guest PC 0x0c07bb08 */
if(!s->budget--) { s->failed_pc=0x0c07bb08u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07bb0a;
P_0c07bb0a: /* original 53f1, guest PC 0x0c07bb0a */
if(!s->budget--) { s->failed_pc=0x0c07bb0au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bb0c;
P_0c07bb0c: /* original 012d, guest PC 0x0c07bb0c */
if(!s->budget--) { s->failed_pc=0x0c07bb0cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07bb0e;
P_0c07bb0e: /* original 611d, guest PC 0x0c07bb0e */
if(!s->budget--) { s->failed_pc=0x0c07bb0eu; return 0; }
r[1]=r[1]&65535u;
goto P_0c07bb10;
P_0c07bb10: /* original 1311, guest PC 0x0c07bb10 */
if(!s->budget--) { s->failed_pc=0x0c07bb10u; return 0; }
write(ram,r[3]+4,r[1],4);
goto P_0c07bb12;
P_0c07bb12: /* original 9021, guest PC 0x0c07bb12 */
if(!s->budget--) { s->failed_pc=0x0c07bb12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb58u,2);
goto P_0c07bb14;
P_0c07bb14: /* original 63f2, guest PC 0x0c07bb14 */
if(!s->budget--) { s->failed_pc=0x0c07bb14u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb16;
P_0c07bb16: /* original 023d, guest PC 0x0c07bb16 */
if(!s->budget--) { s->failed_pc=0x0c07bb16u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb18;
P_0c07bb18: /* original 622d, guest PC 0x0c07bb18 */
if(!s->budget--) { s->failed_pc=0x0c07bb18u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb1a;
P_0c07bb1a: /* original 1421, guest PC 0x0c07bb1a */
if(!s->budget--) { s->failed_pc=0x0c07bb1au; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c07bb1c;
P_0c07bb1c: /* original 63f2, guest PC 0x0c07bb1c */
if(!s->budget--) { s->failed_pc=0x0c07bb1cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb1e;
P_0c07bb1e: /* original 901c, guest PC 0x0c07bb1e */
if(!s->budget--) { s->failed_pc=0x0c07bb1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5au,2);
goto P_0c07bb20;
P_0c07bb20: /* original 023d, guest PC 0x0c07bb20 */
if(!s->budget--) { s->failed_pc=0x0c07bb20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb22;
P_0c07bb22: /* original e07c, guest PC 0x0c07bb22 */
if(!s->budget--) { s->failed_pc=0x0c07bb22u; return 0; }
r[0]=0x0000007cu;
goto P_0c07bb24;
P_0c07bb24: /* original 622d, guest PC 0x0c07bb24 */
if(!s->budget--) { s->failed_pc=0x0c07bb24u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb26;
P_0c07bb26: /* original 0f26, guest PC 0x0c07bb26 */
if(!s->budget--) { s->failed_pc=0x0c07bb26u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07bb28;
P_0c07bb28: /* original 9018, guest PC 0x0c07bb28 */
if(!s->budget--) { s->failed_pc=0x0c07bb28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5cu,2);
goto P_0c07bb2a;
P_0c07bb2a: /* original 63f2, guest PC 0x0c07bb2a */
if(!s->budget--) { s->failed_pc=0x0c07bb2au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb2c;
P_0c07bb2c: /* original 023d, guest PC 0x0c07bb2c */
if(!s->budget--) { s->failed_pc=0x0c07bb2cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb2e;
P_0c07bb2e: /* original 9016, guest PC 0x0c07bb2e */
if(!s->budget--) { s->failed_pc=0x0c07bb2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5eu,2);
goto P_0c07bb30;
P_0c07bb30: /* original 622d, guest PC 0x0c07bb30 */
if(!s->budget--) { s->failed_pc=0x0c07bb30u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb32;
P_0c07bb32: /* original 0f26, guest PC 0x0c07bb32 */
if(!s->budget--) { s->failed_pc=0x0c07bb32u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07bb34;
P_0c07bb34: /* original 9116, guest PC 0x0c07bb34 */
if(!s->budget--) { s->failed_pc=0x0c07bb34u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb64u,2);
goto P_0c07bb36;
P_0c07bb36: /* original 60f2, guest PC 0x0c07bb36 */
if(!s->budget--) { s->failed_pc=0x0c07bb36u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07bb38;
P_0c07bb38: /* original d918, guest PC 0x0c07bb38 */
if(!s->budget--) { s->failed_pc=0x0c07bb38u; return 0; }
r[9]=read(ram,0x0c07bb9cu,4);
goto P_0c07bb3a;
P_0c07bb3a: /* original 001c, guest PC 0x0c07bb3a */
if(!s->budget--) { s->failed_pc=0x0c07bb3au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07bb3c;
P_0c07bb3c: /* original 9a10, guest PC 0x0c07bb3c */
if(!s->budget--) { s->failed_pc=0x0c07bb3cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb60u,2);
goto P_0c07bb3e;
P_0c07bb3e: /* original 9c10, guest PC 0x0c07bb3e */
if(!s->budget--) { s->failed_pc=0x0c07bb3eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb62u,2);
goto P_0c07bb40;
P_0c07bb40: /* original 8802, guest PC 0x0c07bb40 */
if(!s->budget--) { s->failed_pc=0x0c07bb40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07bb42;
P_0c07bb42: /* original d815, guest PC 0x0c07bb42 */
if(!s->budget--) { s->failed_pc=0x0c07bb42u; return 0; }
r[8]=read(ram,0x0c07bb98u,4);
goto P_0c07bb44;
P_0c07bb44: /* original a02c, guest PC 0x0c07bb44 */
if(!s->budget--) { s->failed_pc=0x0c07bb44u; return 0; }
goto P_0c07bba0;
P_0c07bb46: /* original 0009, guest PC 0x0c07bb46 */
if(!s->budget--) { s->failed_pc=0x0c07bb46u; return 0; }
if(!vf3_matrix_family(0x0c07bb48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07bb48u; return 0; } return 1;
P_0c07bba0: /* original 8b3a, guest PC 0x0c07bba0 */
if(!s->budget--) { s->failed_pc=0x0c07bba0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bc18; }
goto P_0c07bba2;
P_0c07bba2: /* original 94aa, guest PC 0x0c07bba2 */
if(!s->budget--) { s->failed_pc=0x0c07bba2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfau,2);
goto P_0c07bba4;
P_0c07bba4: /* original 66d3, guest PC 0x0c07bba4 */
if(!s->budget--) { s->failed_pc=0x0c07bba4u; return 0; }
r[6]=r[13];
goto P_0c07bba6;
P_0c07bba6: /* original 2fe6, guest PC 0x0c07bba6 */
if(!s->budget--) { s->failed_pc=0x0c07bba6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bba8;
P_0c07bba8: /* original e700, guest PC 0x0c07bba8 */
if(!s->budget--) { s->failed_pc=0x0c07bba8u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbaa;
P_0c07bbaa: /* original d258, guest PC 0x0c07bbaa */
if(!s->budget--) { s->failed_pc=0x0c07bbaau; return 0; }
r[2]=read(ram,0x0c07bd0cu,4);
goto P_0c07bbac;
P_0c07bbac: /* original 420b, guest PC 0x0c07bbac */
if(!s->budget--) { s->failed_pc=0x0c07bbacu; return 0; }
target=r[2];
r[16]=code_base|0x0c07bbb0u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bbb0u) { target=s->pc; goto dispatch; }
goto P_0c07bbb0;
P_0c07bbae: /* original 65c3, guest PC 0x0c07bbae */
if(!s->budget--) { s->failed_pc=0x0c07bbaeu; return 0; }
r[5]=r[12];
goto P_0c07bbb0;
P_0c07bbb0: /* original 7f04, guest PC 0x0c07bbb0 */
if(!s->budget--) { s->failed_pc=0x0c07bbb0u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bbb2;
P_0c07bbb2: /* original 90a3, guest PC 0x0c07bbb2 */
if(!s->budget--) { s->failed_pc=0x0c07bbb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bbb4;
P_0c07bbb4: /* original 63f2, guest PC 0x0c07bbb4 */
if(!s->budget--) { s->failed_pc=0x0c07bbb4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bbb6;
P_0c07bbb6: /* original 023c, guest PC 0x0c07bbb6 */
if(!s->budget--) { s->failed_pc=0x0c07bbb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07bbb8;
P_0c07bbb8: /* original 7001, guest PC 0x0c07bbb8 */
if(!s->budget--) { s->failed_pc=0x0c07bbb8u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bbba;
P_0c07bbba: /* original 013c, guest PC 0x0c07bbba */
if(!s->budget--) { s->failed_pc=0x0c07bbbau; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07bbbc;
P_0c07bbbc: /* original 3210, guest PC 0x0c07bbbc */
if(!s->budget--) { s->failed_pc=0x0c07bbbcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c07bbbe;
P_0c07bbbe: /* original 8d0f, guest PC 0x0c07bbbe */
if(!s->budget--) { s->failed_pc=0x0c07bbbeu; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c07bbe0; }
goto P_0c07bbc2;
P_0c07bbc0: /* original 64a3, guest PC 0x0c07bbc0 */
if(!s->budget--) { s->failed_pc=0x0c07bbc0u; return 0; }
r[4]=r[10];
goto P_0c07bbc2;
P_0c07bbc2: /* original 2fe6, guest PC 0x0c07bbc2 */
if(!s->budget--) { s->failed_pc=0x0c07bbc2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbc4;
P_0c07bbc4: /* original e700, guest PC 0x0c07bbc4 */
if(!s->budget--) { s->failed_pc=0x0c07bbc4u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbc6;
P_0c07bbc6: /* original 5af1, guest PC 0x0c07bbc6 */
if(!s->budget--) { s->failed_pc=0x0c07bbc6u; return 0; }
r[10]=read(ram,r[15]+4,4);
goto P_0c07bbc8;
P_0c07bbc8: /* original 66d3, guest PC 0x0c07bbc8 */
if(!s->budget--) { s->failed_pc=0x0c07bbc8u; return 0; }
r[6]=r[13];
goto P_0c07bbca;
P_0c07bbca: /* original 9098, guest PC 0x0c07bbca */
if(!s->budget--) { s->failed_pc=0x0c07bbcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfeu,2);
goto P_0c07bbcc;
P_0c07bbcc: /* original d34f, guest PC 0x0c07bbcc */
if(!s->budget--) { s->failed_pc=0x0c07bbccu; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bbce;
P_0c07bbce: /* original 00ac, guest PC 0x0c07bbce */
if(!s->budget--) { s->failed_pc=0x0c07bbceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c07bbd0;
P_0c07bbd0: /* original 4008, guest PC 0x0c07bbd0 */
if(!s->budget--) { s->failed_pc=0x0c07bbd0u; return 0; }
r[0]<<=2;
goto P_0c07bbd2;
P_0c07bbd2: /* original 430b, guest PC 0x0c07bbd2 */
if(!s->budget--) { s->failed_pc=0x0c07bbd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bbd6u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bbd6u) { target=s->pc; goto dispatch; }
goto P_0c07bbd6;
P_0c07bbd4: /* original 059e, guest PC 0x0c07bbd4 */
if(!s->budget--) { s->failed_pc=0x0c07bbd4u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bbd6;
P_0c07bbd6: /* original 9091, guest PC 0x0c07bbd6 */
if(!s->budget--) { s->failed_pc=0x0c07bbd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bbd8;
P_0c07bbd8: /* original 7f04, guest PC 0x0c07bbd8 */
if(!s->budget--) { s->failed_pc=0x0c07bbd8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bbda;
P_0c07bbda: /* original 02ac, guest PC 0x0c07bbda */
if(!s->budget--) { s->failed_pc=0x0c07bbdau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c07bbdc;
P_0c07bbdc: /* original 7001, guest PC 0x0c07bbdc */
if(!s->budget--) { s->failed_pc=0x0c07bbdcu; return 0; }
r[0]+=0x00000001u;
goto P_0c07bbde;
P_0c07bbde: /* original 0a24, guest PC 0x0c07bbde */
if(!s->budget--) { s->failed_pc=0x0c07bbdeu; return 0; }
write(ram,r[10]+r[0],r[2],1);
goto P_0c07bbe0;
P_0c07bbe0: /* original 2fb6, guest PC 0x0c07bbe0 */
if(!s->budget--) { s->failed_pc=0x0c07bbe0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbe2;
P_0c07bbe2: /* original 66d3, guest PC 0x0c07bbe2 */
if(!s->budget--) { s->failed_pc=0x0c07bbe2u; return 0; }
r[6]=r[13];
goto P_0c07bbe4;
P_0c07bbe4: /* original 2fe6, guest PC 0x0c07bbe4 */
if(!s->budget--) { s->failed_pc=0x0c07bbe4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbe6;
P_0c07bbe6: /* original e700, guest PC 0x0c07bbe6 */
if(!s->budget--) { s->failed_pc=0x0c07bbe6u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbe8;
P_0c07bbe8: /* original 948a, guest PC 0x0c07bbe8 */
if(!s->budget--) { s->failed_pc=0x0c07bbe8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd00u,2);
goto P_0c07bbea;
P_0c07bbea: /* original 480b, guest PC 0x0c07bbea */
if(!s->budget--) { s->failed_pc=0x0c07bbeau; return 0; }
target=r[8];
r[16]=code_base|0x0c07bbeeu;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bbeeu) { target=s->pc; goto dispatch; }
goto P_0c07bbee;
P_0c07bbec: /* original 65c3, guest PC 0x0c07bbec */
if(!s->budget--) { s->failed_pc=0x0c07bbecu; return 0; }
r[5]=r[12];
goto P_0c07bbee;
P_0c07bbee: /* original 2fb6, guest PC 0x0c07bbee */
if(!s->budget--) { s->failed_pc=0x0c07bbeeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbf0;
P_0c07bbf0: /* original 66d3, guest PC 0x0c07bbf0 */
if(!s->budget--) { s->failed_pc=0x0c07bbf0u; return 0; }
r[6]=r[13];
goto P_0c07bbf2;
P_0c07bbf2: /* original 2fe6, guest PC 0x0c07bbf2 */
if(!s->budget--) { s->failed_pc=0x0c07bbf2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbf4;
P_0c07bbf4: /* original e700, guest PC 0x0c07bbf4 */
if(!s->budget--) { s->failed_pc=0x0c07bbf4u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbf6;
P_0c07bbf6: /* original 9484, guest PC 0x0c07bbf6 */
if(!s->budget--) { s->failed_pc=0x0c07bbf6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd02u,2);
goto P_0c07bbf8;
P_0c07bbf8: /* original 480b, guest PC 0x0c07bbf8 */
if(!s->budget--) { s->failed_pc=0x0c07bbf8u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bbfcu;
r[5]=read(ram,r[9]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bbfcu) { target=s->pc; goto dispatch; }
goto P_0c07bbfc;
P_0c07bbfa: /* original 559a, guest PC 0x0c07bbfa */
if(!s->budget--) { s->failed_pc=0x0c07bbfau; return 0; }
r[5]=read(ram,r[9]+40,4);
goto P_0c07bbfc;
P_0c07bbfc: /* original 2fb6, guest PC 0x0c07bbfc */
if(!s->budget--) { s->failed_pc=0x0c07bbfcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbfe;
P_0c07bbfe: /* original e700, guest PC 0x0c07bbfe */
if(!s->budget--) { s->failed_pc=0x0c07bbfeu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc00;
P_0c07bc00: /* original 2fe6, guest PC 0x0c07bc00 */
if(!s->budget--) { s->failed_pc=0x0c07bc00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc02;
P_0c07bc02: /* original 66d3, guest PC 0x0c07bc02 */
if(!s->budget--) { s->failed_pc=0x0c07bc02u; return 0; }
r[6]=r[13];
goto P_0c07bc04;
P_0c07bc04: /* original 55f6, guest PC 0x0c07bc04 */
if(!s->budget--) { s->failed_pc=0x0c07bc04u; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c07bc06;
P_0c07bc06: /* original 907d, guest PC 0x0c07bc06 */
if(!s->budget--) { s->failed_pc=0x0c07bc06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd04u,2);
goto P_0c07bc08;
P_0c07bc08: /* original 947d, guest PC 0x0c07bc08 */
if(!s->budget--) { s->failed_pc=0x0c07bc08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd06u,2);
goto P_0c07bc0a;
P_0c07bc0a: /* original 055c, guest PC 0x0c07bc0a */
if(!s->budget--) { s->failed_pc=0x0c07bc0au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07bc0c;
P_0c07bc0c: /* original 4508, guest PC 0x0c07bc0c */
if(!s->budget--) { s->failed_pc=0x0c07bc0cu; return 0; }
r[5]<<=2;
goto P_0c07bc0e;
P_0c07bc0e: /* original 359c, guest PC 0x0c07bc0e */
if(!s->budget--) { s->failed_pc=0x0c07bc0eu; return 0; }
r[5]+=r[9];
goto P_0c07bc10;
P_0c07bc10: /* original 480b, guest PC 0x0c07bc10 */
if(!s->budget--) { s->failed_pc=0x0c07bc10u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bc14u;
r[5]=read(ram,r[5]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc14u) { target=s->pc; goto dispatch; }
goto P_0c07bc14;
P_0c07bc12: /* original 5551, guest PC 0x0c07bc12 */
if(!s->budget--) { s->failed_pc=0x0c07bc12u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07bc14;
P_0c07bc14: /* original a045, guest PC 0x0c07bc14 */
if(!s->budget--) { s->failed_pc=0x0c07bc14u; return 0; }
r[15]+=0x00000018u;
goto P_0c07bca2;
P_0c07bc16: /* original 7f18, guest PC 0x0c07bc16 */
if(!s->budget--) { s->failed_pc=0x0c07bc16u; return 0; }
r[15]+=0x00000018u;
goto P_0c07bc18;
P_0c07bc18: /* original 9472, guest PC 0x0c07bc18 */
if(!s->budget--) { s->failed_pc=0x0c07bc18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd00u,2);
goto P_0c07bc1a;
P_0c07bc1a: /* original 66d3, guest PC 0x0c07bc1a */
if(!s->budget--) { s->failed_pc=0x0c07bc1au; return 0; }
r[6]=r[13];
goto P_0c07bc1c;
P_0c07bc1c: /* original 2fe6, guest PC 0x0c07bc1c */
if(!s->budget--) { s->failed_pc=0x0c07bc1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc1e;
P_0c07bc1e: /* original e700, guest PC 0x0c07bc1e */
if(!s->budget--) { s->failed_pc=0x0c07bc1eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc20;
P_0c07bc20: /* original d23a, guest PC 0x0c07bc20 */
if(!s->budget--) { s->failed_pc=0x0c07bc20u; return 0; }
r[2]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc22;
P_0c07bc22: /* original 420b, guest PC 0x0c07bc22 */
if(!s->budget--) { s->failed_pc=0x0c07bc22u; return 0; }
target=r[2];
r[16]=code_base|0x0c07bc26u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc26u) { target=s->pc; goto dispatch; }
goto P_0c07bc26;
P_0c07bc24: /* original 65c3, guest PC 0x0c07bc24 */
if(!s->budget--) { s->failed_pc=0x0c07bc24u; return 0; }
r[5]=r[12];
goto P_0c07bc26;
P_0c07bc26: /* original 946c, guest PC 0x0c07bc26 */
if(!s->budget--) { s->failed_pc=0x0c07bc26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd02u,2);
goto P_0c07bc28;
P_0c07bc28: /* original 66d3, guest PC 0x0c07bc28 */
if(!s->budget--) { s->failed_pc=0x0c07bc28u; return 0; }
r[6]=r[13];
goto P_0c07bc2a;
P_0c07bc2a: /* original 2fe6, guest PC 0x0c07bc2a */
if(!s->budget--) { s->failed_pc=0x0c07bc2au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc2c;
P_0c07bc2c: /* original e700, guest PC 0x0c07bc2c */
if(!s->budget--) { s->failed_pc=0x0c07bc2cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc2e;
P_0c07bc2e: /* original d337, guest PC 0x0c07bc2e */
if(!s->budget--) { s->failed_pc=0x0c07bc2eu; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc30;
P_0c07bc30: /* original 430b, guest PC 0x0c07bc30 */
if(!s->budget--) { s->failed_pc=0x0c07bc30u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc34u;
r[5]=read(ram,r[9]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc34u) { target=s->pc; goto dispatch; }
goto P_0c07bc34;
P_0c07bc32: /* original 559a, guest PC 0x0c07bc32 */
if(!s->budget--) { s->failed_pc=0x0c07bc32u; return 0; }
r[5]=read(ram,r[9]+40,4);
goto P_0c07bc34;
P_0c07bc34: /* original 9467, guest PC 0x0c07bc34 */
if(!s->budget--) { s->failed_pc=0x0c07bc34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd06u,2);
goto P_0c07bc36;
P_0c07bc36: /* original e700, guest PC 0x0c07bc36 */
if(!s->budget--) { s->failed_pc=0x0c07bc36u; return 0; }
r[7]=0x00000000u;
goto P_0c07bc38;
P_0c07bc38: /* original 2fe6, guest PC 0x0c07bc38 */
if(!s->budget--) { s->failed_pc=0x0c07bc38u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc3a;
P_0c07bc3a: /* original 66d3, guest PC 0x0c07bc3a */
if(!s->budget--) { s->failed_pc=0x0c07bc3au; return 0; }
r[6]=r[13];
goto P_0c07bc3c;
P_0c07bc3c: /* original 55f3, guest PC 0x0c07bc3c */
if(!s->budget--) { s->failed_pc=0x0c07bc3cu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07bc3e;
P_0c07bc3e: /* original 9061, guest PC 0x0c07bc3e */
if(!s->budget--) { s->failed_pc=0x0c07bc3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd04u,2);
goto P_0c07bc40;
P_0c07bc40: /* original d332, guest PC 0x0c07bc40 */
if(!s->budget--) { s->failed_pc=0x0c07bc40u; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc42;
P_0c07bc42: /* original 055c, guest PC 0x0c07bc42 */
if(!s->budget--) { s->failed_pc=0x0c07bc42u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07bc44;
P_0c07bc44: /* original 4508, guest PC 0x0c07bc44 */
if(!s->budget--) { s->failed_pc=0x0c07bc44u; return 0; }
r[5]<<=2;
goto P_0c07bc46;
P_0c07bc46: /* original 359c, guest PC 0x0c07bc46 */
if(!s->budget--) { s->failed_pc=0x0c07bc46u; return 0; }
r[5]+=r[9];
goto P_0c07bc48;
P_0c07bc48: /* original 430b, guest PC 0x0c07bc48 */
if(!s->budget--) { s->failed_pc=0x0c07bc48u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc4cu;
r[5]=read(ram,r[5]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc4cu) { target=s->pc; goto dispatch; }
goto P_0c07bc4c;
P_0c07bc4a: /* original 5551, guest PC 0x0c07bc4a */
if(!s->budget--) { s->failed_pc=0x0c07bc4au; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07bc4c;
P_0c07bc4c: /* original 2fb6, guest PC 0x0c07bc4c */
if(!s->budget--) { s->failed_pc=0x0c07bc4cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc4e;
P_0c07bc4e: /* original 66d3, guest PC 0x0c07bc4e */
if(!s->budget--) { s->failed_pc=0x0c07bc4eu; return 0; }
r[6]=r[13];
goto P_0c07bc50;
P_0c07bc50: /* original 2fe6, guest PC 0x0c07bc50 */
if(!s->budget--) { s->failed_pc=0x0c07bc50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc52;
P_0c07bc52: /* original e700, guest PC 0x0c07bc52 */
if(!s->budget--) { s->failed_pc=0x0c07bc52u; return 0; }
r[7]=0x00000000u;
goto P_0c07bc54;
P_0c07bc54: /* original 9451, guest PC 0x0c07bc54 */
if(!s->budget--) { s->failed_pc=0x0c07bc54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfau,2);
goto P_0c07bc56;
P_0c07bc56: /* original 480b, guest PC 0x0c07bc56 */
if(!s->budget--) { s->failed_pc=0x0c07bc56u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bc5au;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc5au) { target=s->pc; goto dispatch; }
goto P_0c07bc5a;
P_0c07bc58: /* original 65c3, guest PC 0x0c07bc58 */
if(!s->budget--) { s->failed_pc=0x0c07bc58u; return 0; }
r[5]=r[12];
goto P_0c07bc5a;
P_0c07bc5a: /* original 7f14, guest PC 0x0c07bc5a */
if(!s->budget--) { s->failed_pc=0x0c07bc5au; return 0; }
r[15]+=0x00000014u;
goto P_0c07bc5c;
P_0c07bc5c: /* original 904e, guest PC 0x0c07bc5c */
if(!s->budget--) { s->failed_pc=0x0c07bc5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc5e;
P_0c07bc5e: /* original 62f2, guest PC 0x0c07bc5e */
if(!s->budget--) { s->failed_pc=0x0c07bc5eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07bc60;
P_0c07bc60: /* original 032c, guest PC 0x0c07bc60 */
if(!s->budget--) { s->failed_pc=0x0c07bc60u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07bc62;
P_0c07bc62: /* original 7001, guest PC 0x0c07bc62 */
if(!s->budget--) { s->failed_pc=0x0c07bc62u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bc64;
P_0c07bc64: /* original 012c, guest PC 0x0c07bc64 */
if(!s->budget--) { s->failed_pc=0x0c07bc64u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07bc66;
P_0c07bc66: /* original 3310, guest PC 0x0c07bc66 */
if(!s->budget--) { s->failed_pc=0x0c07bc66u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c07bc68;
P_0c07bc68: /* original 8d0f, guest PC 0x0c07bc68 */
if(!s->budget--) { s->failed_pc=0x0c07bc68u; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c07bc8a; }
goto P_0c07bc6c;
P_0c07bc6a: /* original 64a3, guest PC 0x0c07bc6a */
if(!s->budget--) { s->failed_pc=0x0c07bc6au; return 0; }
r[4]=r[10];
goto P_0c07bc6c;
P_0c07bc6c: /* original 2fe6, guest PC 0x0c07bc6c */
if(!s->budget--) { s->failed_pc=0x0c07bc6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc6e;
P_0c07bc6e: /* original e700, guest PC 0x0c07bc6e */
if(!s->budget--) { s->failed_pc=0x0c07bc6eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc70;
P_0c07bc70: /* original 5cf1, guest PC 0x0c07bc70 */
if(!s->budget--) { s->failed_pc=0x0c07bc70u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07bc72;
P_0c07bc72: /* original 66d3, guest PC 0x0c07bc72 */
if(!s->budget--) { s->failed_pc=0x0c07bc72u; return 0; }
r[6]=r[13];
goto P_0c07bc74;
P_0c07bc74: /* original 9043, guest PC 0x0c07bc74 */
if(!s->budget--) { s->failed_pc=0x0c07bc74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfeu,2);
goto P_0c07bc76;
P_0c07bc76: /* original d325, guest PC 0x0c07bc76 */
if(!s->budget--) { s->failed_pc=0x0c07bc76u; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc78;
P_0c07bc78: /* original 00cc, guest PC 0x0c07bc78 */
if(!s->budget--) { s->failed_pc=0x0c07bc78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07bc7a;
P_0c07bc7a: /* original 4008, guest PC 0x0c07bc7a */
if(!s->budget--) { s->failed_pc=0x0c07bc7au; return 0; }
r[0]<<=2;
goto P_0c07bc7c;
P_0c07bc7c: /* original 430b, guest PC 0x0c07bc7c */
if(!s->budget--) { s->failed_pc=0x0c07bc7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc80u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc80u) { target=s->pc; goto dispatch; }
goto P_0c07bc80;
P_0c07bc7e: /* original 059e, guest PC 0x0c07bc7e */
if(!s->budget--) { s->failed_pc=0x0c07bc7eu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bc80;
P_0c07bc80: /* original 903c, guest PC 0x0c07bc80 */
if(!s->budget--) { s->failed_pc=0x0c07bc80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc82;
P_0c07bc82: /* original 7f04, guest PC 0x0c07bc82 */
if(!s->budget--) { s->failed_pc=0x0c07bc82u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bc84;
P_0c07bc84: /* original 02cc, guest PC 0x0c07bc84 */
if(!s->budget--) { s->failed_pc=0x0c07bc84u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07bc86;
P_0c07bc86: /* original 7001, guest PC 0x0c07bc86 */
if(!s->budget--) { s->failed_pc=0x0c07bc86u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bc88;
P_0c07bc88: /* original 0c24, guest PC 0x0c07bc88 */
if(!s->budget--) { s->failed_pc=0x0c07bc88u; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c07bc8a;
P_0c07bc8a: /* original 2fb6, guest PC 0x0c07bc8a */
if(!s->budget--) { s->failed_pc=0x0c07bc8au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc8c;
P_0c07bc8c: /* original e700, guest PC 0x0c07bc8c */
if(!s->budget--) { s->failed_pc=0x0c07bc8cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc8e;
P_0c07bc8e: /* original 2fe6, guest PC 0x0c07bc8e */
if(!s->budget--) { s->failed_pc=0x0c07bc8eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc90;
P_0c07bc90: /* original 66d3, guest PC 0x0c07bc90 */
if(!s->budget--) { s->failed_pc=0x0c07bc90u; return 0; }
r[6]=r[13];
goto P_0c07bc92;
P_0c07bc92: /* original 50f2, guest PC 0x0c07bc92 */
if(!s->budget--) { s->failed_pc=0x0c07bc92u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c07bc94;
P_0c07bc94: /* original 9132, guest PC 0x0c07bc94 */
if(!s->budget--) { s->failed_pc=0x0c07bc94u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc96;
P_0c07bc96: /* original 001c, guest PC 0x0c07bc96 */
if(!s->budget--) { s->failed_pc=0x0c07bc96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07bc98;
P_0c07bc98: /* original 4008, guest PC 0x0c07bc98 */
if(!s->budget--) { s->failed_pc=0x0c07bc98u; return 0; }
r[0]<<=2;
goto P_0c07bc9a;
P_0c07bc9a: /* original 059e, guest PC 0x0c07bc9a */
if(!s->budget--) { s->failed_pc=0x0c07bc9au; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bc9c;
P_0c07bc9c: /* original 480b, guest PC 0x0c07bc9c */
if(!s->budget--) { s->failed_pc=0x0c07bc9cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07bca0u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bca0u) { target=s->pc; goto dispatch; }
goto P_0c07bca0;
P_0c07bc9e: /* original 64a3, guest PC 0x0c07bc9e */
if(!s->budget--) { s->failed_pc=0x0c07bc9eu; return 0; }
r[4]=r[10];
goto P_0c07bca0;
P_0c07bca0: /* original 7f08, guest PC 0x0c07bca0 */
if(!s->budget--) { s->failed_pc=0x0c07bca0u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bca2;
P_0c07bca2: /* original d31b, guest PC 0x0c07bca2 */
if(!s->budget--) { s->failed_pc=0x0c07bca2u; return 0; }
r[3]=read(ram,0x0c07bd10u,4);
goto P_0c07bca4;
P_0c07bca4: /* original fe8d, guest PC 0x0c07bca4 */
if(!s->budget--) { s->failed_pc=0x0c07bca4u; return 0; }
fr[14]=0;
goto P_0c07bca6;
P_0c07bca6: /* original 6032, guest PC 0x0c07bca6 */
if(!s->budget--) { s->failed_pc=0x0c07bca6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bca8;
P_0c07bca8: /* original c801, guest PC 0x0c07bca8 */
if(!s->budget--) { s->failed_pc=0x0c07bca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07bcaa;
P_0c07bcaa: /* original 8d02, guest PC 0x0c07bcaa */
if(!s->budget--) { s->failed_pc=0x0c07bcaau; return 0; }
cond=r[17]&1u;
r[10]=0x00000064u;
if(cond) { goto P_0c07bcb2; }
goto P_0c07bcae;
P_0c07bcac: /* original ea64, guest PC 0x0c07bcac */
if(!s->budget--) { s->failed_pc=0x0c07bcacu; return 0; }
r[10]=0x00000064u;
goto P_0c07bcae;
P_0c07bcae: /* original a212, guest PC 0x0c07bcae */
if(!s->budget--) { s->failed_pc=0x0c07bcaeu; return 0; }
goto P_0c07c0d6;
P_0c07bcb0: /* original 0009, guest PC 0x0c07bcb0 */
if(!s->budget--) { s->failed_pc=0x0c07bcb0u; return 0; }
goto P_0c07bcb2;
P_0c07bcb2: /* original 6193, guest PC 0x0c07bcb2 */
if(!s->budget--) { s->failed_pc=0x0c07bcb2u; return 0; }
r[1]=r[9];
goto P_0c07bcb4;
P_0c07bcb4: /* original 1fe8, guest PC 0x0c07bcb4 */
if(!s->budget--) { s->failed_pc=0x0c07bcb4u; return 0; }
write(ram,r[15]+32,r[14],4);
goto P_0c07bcb6;
P_0c07bcb6: /* original 9227, guest PC 0x0c07bcb6 */
if(!s->budget--) { s->failed_pc=0x0c07bcb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd08u,2);
goto P_0c07bcb8;
P_0c07bcb8: /* original 32fc, guest PC 0x0c07bcb8 */
if(!s->budget--) { s->failed_pc=0x0c07bcb8u; return 0; }
r[2]+=r[15];
goto P_0c07bcba;
P_0c07bcba: /* original 1f2f, guest PC 0x0c07bcba */
if(!s->budget--) { s->failed_pc=0x0c07bcbau; return 0; }
write(ram,r[15]+60,r[2],4);
goto P_0c07bcbc;
P_0c07bcbc: /* original 1f1a, guest PC 0x0c07bcbc */
if(!s->budget--) { s->failed_pc=0x0c07bcbcu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c07bcbe;
P_0c07bcbe: /* original a196, guest PC 0x0c07bcbe */
if(!s->budget--) { s->failed_pc=0x0c07bcbeu; return 0; }
fr[15]=0x3f800000u;
goto P_0c07bfee;
P_0c07bcc0: /* original ff9d, guest PC 0x0c07bcc0 */
if(!s->budget--) { s->failed_pc=0x0c07bcc0u; return 0; }
fr[15]=0x3f800000u;
goto P_0c07bcc2;
P_0c07bcc2: /* original e122, guest PC 0x0c07bcc2 */
if(!s->budget--) { s->failed_pc=0x0c07bcc2u; return 0; }
r[1]=0x00000022u;
goto P_0c07bcc4;
P_0c07bcc4: /* original 53f8, guest PC 0x0c07bcc4 */
if(!s->budget--) { s->failed_pc=0x0c07bcc4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07bcc6;
P_0c07bcc6: /* original e007, guest PC 0x0c07bcc6 */
if(!s->budget--) { s->failed_pc=0x0c07bcc6u; return 0; }
r[0]=0x00000007u;
goto P_0c07bcc8;
P_0c07bcc8: /* original 6ce3, guest PC 0x0c07bcc8 */
if(!s->budget--) { s->failed_pc=0x0c07bcc8u; return 0; }
r[12]=r[14];
goto P_0c07bcca;
P_0c07bcca: /* original 4308, guest PC 0x0c07bcca */
if(!s->budget--) { s->failed_pc=0x0c07bccau; return 0; }
r[3]<<=2;
goto P_0c07bccc;
P_0c07bccc: /* original 4300, guest PC 0x0c07bccc */
if(!s->budget--) { s->failed_pc=0x0c07bcccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bcce;
P_0c07bcce: /* original 1f32, guest PC 0x0c07bcce */
if(!s->budget--) { s->failed_pc=0x0c07bcceu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07bcd0;
P_0c07bcd0: /* original 921a, guest PC 0x0c07bcd0 */
if(!s->budget--) { s->failed_pc=0x0c07bcd0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd08u,2);
goto P_0c07bcd2;
P_0c07bcd2: /* original 32fc, guest PC 0x0c07bcd2 */
if(!s->budget--) { s->failed_pc=0x0c07bcd2u; return 0; }
r[2]+=r[15];
goto P_0c07bcd4;
P_0c07bcd4: /* original 332c, guest PC 0x0c07bcd4 */
if(!s->budget--) { s->failed_pc=0x0c07bcd4u; return 0; }
r[3]+=r[2];
goto P_0c07bcd6;
P_0c07bcd6: /* original 1f34, guest PC 0x0c07bcd6 */
if(!s->budget--) { s->failed_pc=0x0c07bcd6u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07bcd8;
P_0c07bcd8: /* original 1f39, guest PC 0x0c07bcd8 */
if(!s->budget--) { s->failed_pc=0x0c07bcd8u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07bcda;
P_0c07bcda: /* original 1f1b, guest PC 0x0c07bcda */
if(!s->budget--) { s->failed_pc=0x0c07bcdau; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c07bcdc;
P_0c07bcdc: /* original e11e, guest PC 0x0c07bcdc */
if(!s->budget--) { s->failed_pc=0x0c07bcdcu; return 0; }
r[1]=0x0000001eu;
goto P_0c07bcde;
P_0c07bcde: /* original 1f17, guest PC 0x0c07bcde */
if(!s->budget--) { s->failed_pc=0x0c07bcdeu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07bce0;
P_0c07bce0: /* original 55f4, guest PC 0x0c07bce0 */
if(!s->budget--) { s->failed_pc=0x0c07bce0u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c07bce2;
P_0c07bce2: /* original 1f54, guest PC 0x0c07bce2 */
if(!s->budget--) { s->failed_pc=0x0c07bce2u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bce4;
P_0c07bce4: /* original 51f8, guest PC 0x0c07bce4 */
if(!s->budget--) { s->failed_pc=0x0c07bce4u; return 0; }
r[1]=read(ram,r[15]+32,4);
goto P_0c07bce6;
P_0c07bce6: /* original 4100, guest PC 0x0c07bce6 */
if(!s->budget--) { s->failed_pc=0x0c07bce6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07bce8;
P_0c07bce8: /* original 7102, guest PC 0x0c07bce8 */
if(!s->budget--) { s->failed_pc=0x0c07bce8u; return 0; }
r[1]+=0x00000002u;
goto P_0c07bcea;
P_0c07bcea: /* original 410c, guest PC 0x0c07bcea */
if(!s->budget--) { s->failed_pc=0x0c07bceau; return 0; }
r[1]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[1]>>((-r[0])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[0]&31u);
goto P_0c07bcec;
P_0c07bcec: /* original 1f11, guest PC 0x0c07bcec */
if(!s->budget--) { s->failed_pc=0x0c07bcecu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c07bcee;
P_0c07bcee: /* original 1f54, guest PC 0x0c07bcee */
if(!s->budget--) { s->failed_pc=0x0c07bceeu; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bcf0;
P_0c07bcf0: /* original 54f1, guest PC 0x0c07bcf0 */
if(!s->budget--) { s->failed_pc=0x0c07bcf0u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07bcf2;
P_0c07bcf2: /* original 1f41, guest PC 0x0c07bcf2 */
if(!s->budget--) { s->failed_pc=0x0c07bcf2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07bcf4;
P_0c07bcf4: /* original 1f54, guest PC 0x0c07bcf4 */
if(!s->budget--) { s->failed_pc=0x0c07bcf4u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bcf6;
P_0c07bcf6: /* original a172, guest PC 0x0c07bcf6 */
if(!s->budget--) { s->failed_pc=0x0c07bcf6u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07bfde;
P_0c07bcf8: /* original 1f41, guest PC 0x0c07bcf8 */
if(!s->budget--) { s->failed_pc=0x0c07bcf8u; return 0; }
write(ram,r[15]+4,r[4],4);
if(!vf3_matrix_family(0x0c07bcfau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07bcfau; return 0; } return 1;
P_0c07bd14: /* original 63c3, guest PC 0x0c07bd14 */
if(!s->budget--) { s->failed_pc=0x0c07bd14u; return 0; }
r[3]=r[12];
goto P_0c07bd16;
P_0c07bd16: /* original 4308, guest PC 0x0c07bd16 */
if(!s->budget--) { s->failed_pc=0x0c07bd16u; return 0; }
r[3]<<=2;
goto P_0c07bd18;
P_0c07bd18: /* original 62c3, guest PC 0x0c07bd18 */
if(!s->budget--) { s->failed_pc=0x0c07bd18u; return 0; }
r[2]=r[12];
goto P_0c07bd1a;
P_0c07bd1a: /* original 332c, guest PC 0x0c07bd1a */
if(!s->budget--) { s->failed_pc=0x0c07bd1au; return 0; }
r[3]+=r[2];
goto P_0c07bd1c;
P_0c07bd1c: /* original 64c3, guest PC 0x0c07bd1c */
if(!s->budget--) { s->failed_pc=0x0c07bd1cu; return 0; }
r[4]=r[12];
goto P_0c07bd1e;
P_0c07bd1e: /* original 61f3, guest PC 0x0c07bd1e */
if(!s->budget--) { s->failed_pc=0x0c07bd1eu; return 0; }
r[1]=r[15];
goto P_0c07bd20;
P_0c07bd20: /* original 4308, guest PC 0x0c07bd20 */
if(!s->budget--) { s->failed_pc=0x0c07bd20u; return 0; }
r[3]<<=2;
goto P_0c07bd22;
P_0c07bd22: /* original 4408, guest PC 0x0c07bd22 */
if(!s->budget--) { s->failed_pc=0x0c07bd22u; return 0; }
r[4]<<=2;
goto P_0c07bd24;
P_0c07bd24: /* original 717c, guest PC 0x0c07bd24 */
if(!s->budget--) { s->failed_pc=0x0c07bd24u; return 0; }
r[1]+=0x0000007cu;
goto P_0c07bd26;
P_0c07bd26: /* original 314c, guest PC 0x0c07bd26 */
if(!s->budget--) { s->failed_pc=0x0c07bd26u; return 0; }
r[1]+=r[4];
goto P_0c07bd28;
P_0c07bd28: /* original 4300, guest PC 0x0c07bd28 */
if(!s->budget--) { s->failed_pc=0x0c07bd28u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bd2a;
P_0c07bd2a: /* original 730f, guest PC 0x0c07bd2a */
if(!s->budget--) { s->failed_pc=0x0c07bd2au; return 0; }
r[3]+=0x0000000fu;
goto P_0c07bd2c;
P_0c07bd2c: /* original 4300, guest PC 0x0c07bd2c */
if(!s->budget--) { s->failed_pc=0x0c07bd2cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bd2e;
P_0c07bd2e: /* original 1f33, guest PC 0x0c07bd2e */
if(!s->budget--) { s->failed_pc=0x0c07bd2eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07bd30;
P_0c07bd30: /* original 52ff, guest PC 0x0c07bd30 */
if(!s->budget--) { s->failed_pc=0x0c07bd30u; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c07bd32;
P_0c07bd32: /* original 6112, guest PC 0x0c07bd32 */
if(!s->budget--) { s->failed_pc=0x0c07bd32u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bd34;
P_0c07bd34: /* original 324c, guest PC 0x0c07bd34 */
if(!s->budget--) { s->failed_pc=0x0c07bd34u; return 0; }
r[2]+=r[4];
goto P_0c07bd36;
P_0c07bd36: /* original 5222, guest PC 0x0c07bd36 */
if(!s->budget--) { s->failed_pc=0x0c07bd36u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c07bd38;
P_0c07bd38: /* original 3210, guest PC 0x0c07bd38 */
if(!s->budget--) { s->failed_pc=0x0c07bd38u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c07bd3a;
P_0c07bd3a: /* original 8b01, guest PC 0x0c07bd3a */
if(!s->budget--) { s->failed_pc=0x0c07bd3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bd40; }
goto P_0c07bd3c;
P_0c07bd3c: /* original a0a0, guest PC 0x0c07bd3c */
if(!s->budget--) { s->failed_pc=0x0c07bd3cu; return 0; }
goto P_0c07be80;
P_0c07bd3e: /* original 0009, guest PC 0x0c07bd3e */
if(!s->budget--) { s->failed_pc=0x0c07bd3eu; return 0; }
goto P_0c07bd40;
P_0c07bd40: /* original 50f8, guest PC 0x0c07bd40 */
if(!s->budget--) { s->failed_pc=0x0c07bd40u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c07bd42;
P_0c07bd42: /* original 8801, guest PC 0x0c07bd42 */
if(!s->budget--) { s->failed_pc=0x0c07bd42u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07bd44;
P_0c07bd44: /* original 8901, guest PC 0x0c07bd44 */
if(!s->budget--) { s->failed_pc=0x0c07bd44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bd4a; }
goto P_0c07bd46;
P_0c07bd46: /* original a09b, guest PC 0x0c07bd46 */
if(!s->budget--) { s->failed_pc=0x0c07bd46u; return 0; }
goto P_0c07be80;
P_0c07bd48: /* original 0009, guest PC 0x0c07bd48 */
if(!s->budget--) { s->failed_pc=0x0c07bd48u; return 0; }
goto P_0c07bd4a;
P_0c07bd4a: /* original 62f3, guest PC 0x0c07bd4a */
if(!s->budget--) { s->failed_pc=0x0c07bd4au; return 0; }
r[2]=r[15];
goto P_0c07bd4c;
P_0c07bd4c: /* original 63c3, guest PC 0x0c07bd4c */
if(!s->budget--) { s->failed_pc=0x0c07bd4cu; return 0; }
r[3]=r[12];
goto P_0c07bd4e;
P_0c07bd4e: /* original 727c, guest PC 0x0c07bd4e */
if(!s->budget--) { s->failed_pc=0x0c07bd4eu; return 0; }
r[2]+=0x0000007cu;
goto P_0c07bd50;
P_0c07bd50: /* original 4308, guest PC 0x0c07bd50 */
if(!s->budget--) { s->failed_pc=0x0c07bd50u; return 0; }
r[3]<<=2;
goto P_0c07bd52;
P_0c07bd52: /* original 332c, guest PC 0x0c07bd52 */
if(!s->budget--) { s->failed_pc=0x0c07bd52u; return 0; }
r[3]+=r[2];
goto P_0c07bd54;
P_0c07bd54: /* original 6132, guest PC 0x0c07bd54 */
if(!s->budget--) { s->failed_pc=0x0c07bd54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bd56;
P_0c07bd56: /* original 31a3, guest PC 0x0c07bd56 */
if(!s->budget--) { s->failed_pc=0x0c07bd56u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[10])!=0);
goto P_0c07bd58;
P_0c07bd58: /* original 8b3f, guest PC 0x0c07bd58 */
if(!s->budget--) { s->failed_pc=0x0c07bd58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bdda; }
goto P_0c07bd5a;
P_0c07bd5a: /* original 60c3, guest PC 0x0c07bd5a */
if(!s->budget--) { s->failed_pc=0x0c07bd5au; return 0; }
r[0]=r[12];
goto P_0c07bd5c;
P_0c07bd5c: /* original 63f3, guest PC 0x0c07bd5c */
if(!s->budget--) { s->failed_pc=0x0c07bd5cu; return 0; }
r[3]=r[15];
goto P_0c07bd5e;
P_0c07bd5e: /* original 4008, guest PC 0x0c07bd5e */
if(!s->budget--) { s->failed_pc=0x0c07bd5eu; return 0; }
r[0]<<=2;
goto P_0c07bd60;
P_0c07bd60: /* original 7374, guest PC 0x0c07bd60 */
if(!s->budget--) { s->failed_pc=0x0c07bd60u; return 0; }
r[3]+=0x00000074u;
goto P_0c07bd62;
P_0c07bd62: /* original 1f06, guest PC 0x0c07bd62 */
if(!s->budget--) { s->failed_pc=0x0c07bd62u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c07bd64;
P_0c07bd64: /* original 303c, guest PC 0x0c07bd64 */
if(!s->budget--) { s->failed_pc=0x0c07bd64u; return 0; }
r[0]+=r[3];
goto P_0c07bd66;
P_0c07bd66: /* original 1f05, guest PC 0x0c07bd66 */
if(!s->budget--) { s->failed_pc=0x0c07bd66u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c07bd68;
P_0c07bd68: /* original 2f06, guest PC 0x0c07bd68 */
if(!s->budget--) { s->failed_pc=0x0c07bd68u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bd6a;
P_0c07bd6a: /* original 9297, guest PC 0x0c07bd6a */
if(!s->budget--) { s->failed_pc=0x0c07bd6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9cu,2);
goto P_0c07bd6c;
P_0c07bd6c: /* original 51f7, guest PC 0x0c07bd6c */
if(!s->budget--) { s->failed_pc=0x0c07bd6cu; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c07bd6e;
P_0c07bd6e: /* original 32fc, guest PC 0x0c07bd6e */
if(!s->budget--) { s->failed_pc=0x0c07bd6eu; return 0; }
r[2]+=r[15];
goto P_0c07bd70;
P_0c07bd70: /* original 312c, guest PC 0x0c07bd70 */
if(!s->budget--) { s->failed_pc=0x0c07bd70u; return 0; }
r[1]+=r[2];
goto P_0c07bd72;
P_0c07bd72: /* original 1f1f, guest PC 0x0c07bd72 */
if(!s->budget--) { s->failed_pc=0x0c07bd72u; return 0; }
write(ram,r[15]+60,r[1],4);
goto P_0c07bd74;
P_0c07bd74: /* original d34c, guest PC 0x0c07bd74 */
if(!s->budget--) { s->failed_pc=0x0c07bd74u; return 0; }
r[3]=read(ram,0x0c07bea8u,4);
goto P_0c07bd76;
P_0c07bd76: /* original 6112, guest PC 0x0c07bd76 */
if(!s->budget--) { s->failed_pc=0x0c07bd76u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bd78;
P_0c07bd78: /* original 430b, guest PC 0x0c07bd78 */
if(!s->budget--) { s->failed_pc=0x0c07bd78u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bd7cu;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bd7cu) { target=s->pc; goto dispatch; }
goto P_0c07bd7c;
P_0c07bd7a: /* original 60a3, guest PC 0x0c07bd7a */
if(!s->budget--) { s->failed_pc=0x0c07bd7au; return 0; }
r[0]=r[10];
goto P_0c07bd7c;
P_0c07bd7c: /* original 64c3, guest PC 0x0c07bd7c */
if(!s->budget--) { s->failed_pc=0x0c07bd7cu; return 0; }
r[4]=r[12];
goto P_0c07bd7e;
P_0c07bd7e: /* original 61f6, guest PC 0x0c07bd7e */
if(!s->budget--) { s->failed_pc=0x0c07bd7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c07bd80;
P_0c07bd80: /* original 4408, guest PC 0x0c07bd80 */
if(!s->budget--) { s->failed_pc=0x0c07bd80u; return 0; }
r[4]<<=2;
goto P_0c07bd82;
P_0c07bd82: /* original 63c3, guest PC 0x0c07bd82 */
if(!s->budget--) { s->failed_pc=0x0c07bd82u; return 0; }
r[3]=r[12];
goto P_0c07bd84;
P_0c07bd84: /* original 343c, guest PC 0x0c07bd84 */
if(!s->budget--) { s->failed_pc=0x0c07bd84u; return 0; }
r[4]+=r[3];
goto P_0c07bd86;
P_0c07bd86: /* original 2102, guest PC 0x0c07bd86 */
if(!s->budget--) { s->failed_pc=0x0c07bd86u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07bd88;
P_0c07bd88: /* original 4408, guest PC 0x0c07bd88 */
if(!s->budget--) { s->failed_pc=0x0c07bd88u; return 0; }
r[4]<<=2;
goto P_0c07bd8a;
P_0c07bd8a: /* original 9188, guest PC 0x0c07bd8a */
if(!s->budget--) { s->failed_pc=0x0c07bd8au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07bd8c;
P_0c07bd8c: /* original 2fe6, guest PC 0x0c07bd8c */
if(!s->budget--) { s->failed_pc=0x0c07bd8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bd8e;
P_0c07bd8e: /* original 4400, guest PC 0x0c07bd8e */
if(!s->budget--) { s->failed_pc=0x0c07bd8eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07bd90;
P_0c07bd90: /* original 50f6, guest PC 0x0c07bd90 */
if(!s->budget--) { s->failed_pc=0x0c07bd90u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c07bd92;
P_0c07bd92: /* original 740d, guest PC 0x0c07bd92 */
if(!s->budget--) { s->failed_pc=0x0c07bd92u; return 0; }
r[4]+=0x0000000du;
goto P_0c07bd94;
P_0c07bd94: /* original d345, guest PC 0x0c07bd94 */
if(!s->budget--) { s->failed_pc=0x0c07bd94u; return 0; }
r[3]=read(ram,0x0c07beacu,4);
goto P_0c07bd96;
P_0c07bd96: /* original 4400, guest PC 0x0c07bd96 */
if(!s->budget--) { s->failed_pc=0x0c07bd96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07bd98;
P_0c07bd98: /* original 6002, guest PC 0x0c07bd98 */
if(!s->budget--) { s->failed_pc=0x0c07bd98u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bd9a;
P_0c07bd9a: /* original 241b, guest PC 0x0c07bd9a */
if(!s->budget--) { s->failed_pc=0x0c07bd9au; return 0; }
r[4]|=r[1];
goto P_0c07bd9c;
P_0c07bd9c: /* original 66d3, guest PC 0x0c07bd9c */
if(!s->budget--) { s->failed_pc=0x0c07bd9cu; return 0; }
r[6]=r[13];
goto P_0c07bd9e;
P_0c07bd9e: /* original e700, guest PC 0x0c07bd9e */
if(!s->budget--) { s->failed_pc=0x0c07bd9eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bda0;
P_0c07bda0: /* original 4008, guest PC 0x0c07bda0 */
if(!s->budget--) { s->failed_pc=0x0c07bda0u; return 0; }
r[0]<<=2;
goto P_0c07bda2;
P_0c07bda2: /* original 430b, guest PC 0x0c07bda2 */
if(!s->budget--) { s->failed_pc=0x0c07bda2u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bda6u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bda6u) { target=s->pc; goto dispatch; }
goto P_0c07bda6;
P_0c07bda4: /* original 059e, guest PC 0x0c07bda4 */
if(!s->budget--) { s->failed_pc=0x0c07bda4u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bda6;
P_0c07bda6: /* original 7f04, guest PC 0x0c07bda6 */
if(!s->budget--) { s->failed_pc=0x0c07bda6u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bda8;
P_0c07bda8: /* original 53f5, guest PC 0x0c07bda8 */
if(!s->budget--) { s->failed_pc=0x0c07bda8u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07bdaa;
P_0c07bdaa: /* original 52fe, guest PC 0x0c07bdaa */
if(!s->budget--) { s->failed_pc=0x0c07bdaau; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c07bdac;
P_0c07bdac: /* original 6132, guest PC 0x0c07bdac */
if(!s->budget--) { s->failed_pc=0x0c07bdacu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bdae;
P_0c07bdae: /* original 6322, guest PC 0x0c07bdae */
if(!s->budget--) { s->failed_pc=0x0c07bdaeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07bdb0;
P_0c07bdb0: /* original 01a7, guest PC 0x0c07bdb0 */
if(!s->budget--) { s->failed_pc=0x0c07bdb0u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07bdb2;
P_0c07bdb2: /* original 011a, guest PC 0x0c07bdb2 */
if(!s->budget--) { s->failed_pc=0x0c07bdb2u; return 0; }
r[1]=r[19];
goto P_0c07bdb4;
P_0c07bdb4: /* original 3318, guest PC 0x0c07bdb4 */
if(!s->budget--) { s->failed_pc=0x0c07bdb4u; return 0; }
r[3]-=r[1];
goto P_0c07bdb6;
P_0c07bdb6: /* original 2232, guest PC 0x0c07bdb6 */
if(!s->budget--) { s->failed_pc=0x0c07bdb6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07bdb8;
P_0c07bdb8: /* original e10a, guest PC 0x0c07bdb8 */
if(!s->budget--) { s->failed_pc=0x0c07bdb8u; return 0; }
r[1]=0x0000000au;
goto P_0c07bdba;
P_0c07bdba: /* original 50f4, guest PC 0x0c07bdba */
if(!s->budget--) { s->failed_pc=0x0c07bdbau; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07bdbc;
P_0c07bdbc: /* original 52f6, guest PC 0x0c07bdbc */
if(!s->budget--) { s->failed_pc=0x0c07bdbcu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c07bdbe;
P_0c07bdbe: /* original 032e, guest PC 0x0c07bdbe */
if(!s->budget--) { s->failed_pc=0x0c07bdbeu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c07bdc0;
P_0c07bdc0: /* original 3313, guest PC 0x0c07bdc0 */
if(!s->budget--) { s->failed_pc=0x0c07bdc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c07bdc2;
P_0c07bdc2: /* original 890a, guest PC 0x0c07bdc2 */
if(!s->budget--) { s->failed_pc=0x0c07bdc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bdda; }
goto P_0c07bdc4;
P_0c07bdc4: /* original 54f3, guest PC 0x0c07bdc4 */
if(!s->budget--) { s->failed_pc=0x0c07bdc4u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07bdc6;
P_0c07bdc6: /* original 66d3, guest PC 0x0c07bdc6 */
if(!s->budget--) { s->failed_pc=0x0c07bdc6u; return 0; }
r[6]=r[13];
goto P_0c07bdc8;
P_0c07bdc8: /* original 53f1, guest PC 0x0c07bdc8 */
if(!s->budget--) { s->failed_pc=0x0c07bdc8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bdca;
P_0c07bdca: /* original e700, guest PC 0x0c07bdca */
if(!s->budget--) { s->failed_pc=0x0c07bdcau; return 0; }
r[7]=0x00000000u;
goto P_0c07bdcc;
P_0c07bdcc: /* original 2fe6, guest PC 0x0c07bdcc */
if(!s->budget--) { s->failed_pc=0x0c07bdccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bdce;
P_0c07bdce: /* original 55fb, guest PC 0x0c07bdce */
if(!s->budget--) { s->failed_pc=0x0c07bdceu; return 0; }
r[5]=read(ram,r[15]+44,4);
goto P_0c07bdd0;
P_0c07bdd0: /* original 243b, guest PC 0x0c07bdd0 */
if(!s->budget--) { s->failed_pc=0x0c07bdd0u; return 0; }
r[4]|=r[3];
goto P_0c07bdd2;
P_0c07bdd2: /* original d236, guest PC 0x0c07bdd2 */
if(!s->budget--) { s->failed_pc=0x0c07bdd2u; return 0; }
r[2]=read(ram,0x0c07beacu,4);
goto P_0c07bdd4;
P_0c07bdd4: /* original 420b, guest PC 0x0c07bdd4 */
if(!s->budget--) { s->failed_pc=0x0c07bdd4u; return 0; }
target=r[2];
r[16]=code_base|0x0c07bdd8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bdd8u) { target=s->pc; goto dispatch; }
goto P_0c07bdd8;
P_0c07bdd6: /* original 6552, guest PC 0x0c07bdd6 */
if(!s->budget--) { s->failed_pc=0x0c07bdd6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c07bdd8;
P_0c07bdd8: /* original 7f04, guest PC 0x0c07bdd8 */
if(!s->budget--) { s->failed_pc=0x0c07bdd8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bdda;
P_0c07bdda: /* original 62f3, guest PC 0x0c07bdda */
if(!s->budget--) { s->failed_pc=0x0c07bddau; return 0; }
r[2]=r[15];
goto P_0c07bddc;
P_0c07bddc: /* original 63c3, guest PC 0x0c07bddc */
if(!s->budget--) { s->failed_pc=0x0c07bddcu; return 0; }
r[3]=r[12];
goto P_0c07bdde;
P_0c07bdde: /* original 727c, guest PC 0x0c07bdde */
if(!s->budget--) { s->failed_pc=0x0c07bddeu; return 0; }
r[2]+=0x0000007cu;
goto P_0c07bde0;
P_0c07bde0: /* original 4308, guest PC 0x0c07bde0 */
if(!s->budget--) { s->failed_pc=0x0c07bde0u; return 0; }
r[3]<<=2;
goto P_0c07bde2;
P_0c07bde2: /* original 332c, guest PC 0x0c07bde2 */
if(!s->budget--) { s->failed_pc=0x0c07bde2u; return 0; }
r[3]+=r[2];
goto P_0c07bde4;
P_0c07bde4: /* original 6032, guest PC 0x0c07bde4 */
if(!s->budget--) { s->failed_pc=0x0c07bde4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bde6;
P_0c07bde6: /* original e10a, guest PC 0x0c07bde6 */
if(!s->budget--) { s->failed_pc=0x0c07bde6u; return 0; }
r[1]=0x0000000au;
goto P_0c07bde8;
P_0c07bde8: /* original 3013, guest PC 0x0c07bde8 */
if(!s->budget--) { s->failed_pc=0x0c07bde8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[1])!=0);
goto P_0c07bdea;
P_0c07bdea: /* original 8b26, guest PC 0x0c07bdea */
if(!s->budget--) { s->failed_pc=0x0c07bdeau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07be3a; }
goto P_0c07bdec;
P_0c07bdec: /* original 61f3, guest PC 0x0c07bdec */
if(!s->budget--) { s->failed_pc=0x0c07bdecu; return 0; }
r[1]=r[15];
goto P_0c07bdee;
P_0c07bdee: /* original 64c3, guest PC 0x0c07bdee */
if(!s->budget--) { s->failed_pc=0x0c07bdeeu; return 0; }
r[4]=r[12];
goto P_0c07bdf0;
P_0c07bdf0: /* original 717c, guest PC 0x0c07bdf0 */
if(!s->budget--) { s->failed_pc=0x0c07bdf0u; return 0; }
r[1]+=0x0000007cu;
goto P_0c07bdf2;
P_0c07bdf2: /* original 60f3, guest PC 0x0c07bdf2 */
if(!s->budget--) { s->failed_pc=0x0c07bdf2u; return 0; }
r[0]=r[15];
goto P_0c07bdf4;
P_0c07bdf4: /* original 4408, guest PC 0x0c07bdf4 */
if(!s->budget--) { s->failed_pc=0x0c07bdf4u; return 0; }
r[4]<<=2;
goto P_0c07bdf6;
P_0c07bdf6: /* original 314c, guest PC 0x0c07bdf6 */
if(!s->budget--) { s->failed_pc=0x0c07bdf6u; return 0; }
r[1]+=r[4];
goto P_0c07bdf8;
P_0c07bdf8: /* original 7074, guest PC 0x0c07bdf8 */
if(!s->budget--) { s->failed_pc=0x0c07bdf8u; return 0; }
r[0]+=0x00000074u;
goto P_0c07bdfa;
P_0c07bdfa: /* original 304c, guest PC 0x0c07bdfa */
if(!s->budget--) { s->failed_pc=0x0c07bdfau; return 0; }
r[0]+=r[4];
goto P_0c07bdfc;
P_0c07bdfc: /* original 1f05, guest PC 0x0c07bdfc */
if(!s->budget--) { s->failed_pc=0x0c07bdfcu; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c07bdfe;
P_0c07bdfe: /* original 6203, guest PC 0x0c07bdfe */
if(!s->budget--) { s->failed_pc=0x0c07bdfeu; return 0; }
r[2]=r[0];
goto P_0c07be00;
P_0c07be00: /* original 1f16, guest PC 0x0c07be00 */
if(!s->budget--) { s->failed_pc=0x0c07be00u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07be02;
P_0c07be02: /* original d329, guest PC 0x0c07be02 */
if(!s->budget--) { s->failed_pc=0x0c07be02u; return 0; }
r[3]=read(ram,0x0c07bea8u,4);
goto P_0c07be04;
P_0c07be04: /* original 6112, guest PC 0x0c07be04 */
if(!s->budget--) { s->failed_pc=0x0c07be04u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07be06;
P_0c07be06: /* original 430b, guest PC 0x0c07be06 */
if(!s->budget--) { s->failed_pc=0x0c07be06u; return 0; }
target=r[3];
r[16]=code_base|0x0c07be0au;
r[0]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07be0au) { target=s->pc; goto dispatch; }
goto P_0c07be0a;
P_0c07be08: /* original e00a, guest PC 0x0c07be08 */
if(!s->budget--) { s->failed_pc=0x0c07be08u; return 0; }
r[0]=0x0000000au;
goto P_0c07be0a;
P_0c07be0a: /* original 2202, guest PC 0x0c07be0a */
if(!s->budget--) { s->failed_pc=0x0c07be0au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07be0c;
P_0c07be0c: /* original e700, guest PC 0x0c07be0c */
if(!s->budget--) { s->failed_pc=0x0c07be0cu; return 0; }
r[7]=0x00000000u;
goto P_0c07be0e;
P_0c07be0e: /* original 54f3, guest PC 0x0c07be0e */
if(!s->budget--) { s->failed_pc=0x0c07be0eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07be10;
P_0c07be10: /* original 66d3, guest PC 0x0c07be10 */
if(!s->budget--) { s->failed_pc=0x0c07be10u; return 0; }
r[6]=r[13];
goto P_0c07be12;
P_0c07be12: /* original 9344, guest PC 0x0c07be12 */
if(!s->budget--) { s->failed_pc=0x0c07be12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07be14;
P_0c07be14: /* original 2fe6, guest PC 0x0c07be14 */
if(!s->budget--) { s->failed_pc=0x0c07be14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07be16;
P_0c07be16: /* original 50f6, guest PC 0x0c07be16 */
if(!s->budget--) { s->failed_pc=0x0c07be16u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c07be18;
P_0c07be18: /* original 243b, guest PC 0x0c07be18 */
if(!s->budget--) { s->failed_pc=0x0c07be18u; return 0; }
r[4]|=r[3];
goto P_0c07be1a;
P_0c07be1a: /* original d224, guest PC 0x0c07be1a */
if(!s->budget--) { s->failed_pc=0x0c07be1au; return 0; }
r[2]=read(ram,0x0c07beacu,4);
goto P_0c07be1c;
P_0c07be1c: /* original 6002, guest PC 0x0c07be1c */
if(!s->budget--) { s->failed_pc=0x0c07be1cu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07be1e;
P_0c07be1e: /* original 4008, guest PC 0x0c07be1e */
if(!s->budget--) { s->failed_pc=0x0c07be1eu; return 0; }
r[0]<<=2;
goto P_0c07be20;
P_0c07be20: /* original 420b, guest PC 0x0c07be20 */
if(!s->budget--) { s->failed_pc=0x0c07be20u; return 0; }
target=r[2];
r[16]=code_base|0x0c07be24u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07be24u) { target=s->pc; goto dispatch; }
goto P_0c07be24;
P_0c07be22: /* original 059e, guest PC 0x0c07be22 */
if(!s->budget--) { s->failed_pc=0x0c07be22u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07be24;
P_0c07be24: /* original 7f04, guest PC 0x0c07be24 */
if(!s->budget--) { s->failed_pc=0x0c07be24u; return 0; }
r[15]+=0x00000004u;
goto P_0c07be26;
P_0c07be26: /* original 52f5, guest PC 0x0c07be26 */
if(!s->budget--) { s->failed_pc=0x0c07be26u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07be28;
P_0c07be28: /* original 53f6, guest PC 0x0c07be28 */
if(!s->budget--) { s->failed_pc=0x0c07be28u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07be2a;
P_0c07be2a: /* original 6222, guest PC 0x0c07be2a */
if(!s->budget--) { s->failed_pc=0x0c07be2au; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07be2c;
P_0c07be2c: /* original 6032, guest PC 0x0c07be2c */
if(!s->budget--) { s->failed_pc=0x0c07be2cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07be2e;
P_0c07be2e: /* original 6123, guest PC 0x0c07be2e */
if(!s->budget--) { s->failed_pc=0x0c07be2eu; return 0; }
r[1]=r[2];
goto P_0c07be30;
P_0c07be30: /* original 4208, guest PC 0x0c07be30 */
if(!s->budget--) { s->failed_pc=0x0c07be30u; return 0; }
r[2]<<=2;
goto P_0c07be32;
P_0c07be32: /* original 321c, guest PC 0x0c07be32 */
if(!s->budget--) { s->failed_pc=0x0c07be32u; return 0; }
r[2]+=r[1];
goto P_0c07be34;
P_0c07be34: /* original 4200, guest PC 0x0c07be34 */
if(!s->budget--) { s->failed_pc=0x0c07be34u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07be36;
P_0c07be36: /* original 3028, guest PC 0x0c07be36 */
if(!s->budget--) { s->failed_pc=0x0c07be36u; return 0; }
r[0]-=r[2];
goto P_0c07be38;
P_0c07be38: /* original 2302, guest PC 0x0c07be38 */
if(!s->budget--) { s->failed_pc=0x0c07be38u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07be3a;
P_0c07be3a: /* original 64c3, guest PC 0x0c07be3a */
if(!s->budget--) { s->failed_pc=0x0c07be3au; return 0; }
r[4]=r[12];
goto P_0c07be3c;
P_0c07be3c: /* original 4408, guest PC 0x0c07be3c */
if(!s->budget--) { s->failed_pc=0x0c07be3cu; return 0; }
r[4]<<=2;
goto P_0c07be3e;
P_0c07be3e: /* original 63c3, guest PC 0x0c07be3e */
if(!s->budget--) { s->failed_pc=0x0c07be3eu; return 0; }
r[3]=r[12];
goto P_0c07be40;
P_0c07be40: /* original 343c, guest PC 0x0c07be40 */
if(!s->budget--) { s->failed_pc=0x0c07be40u; return 0; }
r[4]+=r[3];
goto P_0c07be42;
P_0c07be42: /* original 60c3, guest PC 0x0c07be42 */
if(!s->budget--) { s->failed_pc=0x0c07be42u; return 0; }
r[0]=r[12];
goto P_0c07be44;
P_0c07be44: /* original 4408, guest PC 0x0c07be44 */
if(!s->budget--) { s->failed_pc=0x0c07be44u; return 0; }
r[4]<<=2;
goto P_0c07be46;
P_0c07be46: /* original 4008, guest PC 0x0c07be46 */
if(!s->budget--) { s->failed_pc=0x0c07be46u; return 0; }
r[0]<<=2;
goto P_0c07be48;
P_0c07be48: /* original 9229, guest PC 0x0c07be48 */
if(!s->budget--) { s->failed_pc=0x0c07be48u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07be4a;
P_0c07be4a: /* original 2fe6, guest PC 0x0c07be4a */
if(!s->budget--) { s->failed_pc=0x0c07be4au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07be4c;
P_0c07be4c: /* original 4400, guest PC 0x0c07be4c */
if(!s->budget--) { s->failed_pc=0x0c07be4cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be4e;
P_0c07be4e: /* original 9325, guest PC 0x0c07be4e */
if(!s->budget--) { s->failed_pc=0x0c07be4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9cu,2);
goto P_0c07be50;
P_0c07be50: /* original 7411, guest PC 0x0c07be50 */
if(!s->budget--) { s->failed_pc=0x0c07be50u; return 0; }
r[4]+=0x00000011u;
goto P_0c07be52;
P_0c07be52: /* original 4400, guest PC 0x0c07be52 */
if(!s->budget--) { s->failed_pc=0x0c07be52u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be54;
P_0c07be54: /* original d115, guest PC 0x0c07be54 */
if(!s->budget--) { s->failed_pc=0x0c07be54u; return 0; }
r[1]=read(ram,0x0c07beacu,4);
goto P_0c07be56;
P_0c07be56: /* original 33fc, guest PC 0x0c07be56 */
if(!s->budget--) { s->failed_pc=0x0c07be56u; return 0; }
r[3]+=r[15];
goto P_0c07be58;
P_0c07be58: /* original 66d3, guest PC 0x0c07be58 */
if(!s->budget--) { s->failed_pc=0x0c07be58u; return 0; }
r[6]=r[13];
goto P_0c07be5a;
P_0c07be5a: /* original 003e, guest PC 0x0c07be5a */
if(!s->budget--) { s->failed_pc=0x0c07be5au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c07be5c;
P_0c07be5c: /* original 242b, guest PC 0x0c07be5c */
if(!s->budget--) { s->failed_pc=0x0c07be5cu; return 0; }
r[4]|=r[2];
goto P_0c07be5e;
P_0c07be5e: /* original e700, guest PC 0x0c07be5e */
if(!s->budget--) { s->failed_pc=0x0c07be5eu; return 0; }
r[7]=0x00000000u;
goto P_0c07be60;
P_0c07be60: /* original 4008, guest PC 0x0c07be60 */
if(!s->budget--) { s->failed_pc=0x0c07be60u; return 0; }
r[0]<<=2;
goto P_0c07be62;
P_0c07be62: /* original 410b, guest PC 0x0c07be62 */
if(!s->budget--) { s->failed_pc=0x0c07be62u; return 0; }
target=r[1];
r[16]=code_base|0x0c07be66u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07be66u) { target=s->pc; goto dispatch; }
goto P_0c07be66;
P_0c07be64: /* original 059e, guest PC 0x0c07be64 */
if(!s->budget--) { s->failed_pc=0x0c07be64u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07be66;
P_0c07be66: /* original 7f04, guest PC 0x0c07be66 */
if(!s->budget--) { s->failed_pc=0x0c07be66u; return 0; }
r[15]+=0x00000004u;
goto P_0c07be68;
P_0c07be68: /* original 931a, guest PC 0x0c07be68 */
if(!s->budget--) { s->failed_pc=0x0c07be68u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea0u,2);
goto P_0c07be6a;
P_0c07be6a: /* original 60f2, guest PC 0x0c07be6a */
if(!s->budget--) { s->failed_pc=0x0c07be6au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07be6c;
P_0c07be6c: /* original 64c3, guest PC 0x0c07be6c */
if(!s->budget--) { s->failed_pc=0x0c07be6cu; return 0; }
r[4]=r[12];
goto P_0c07be6e;
P_0c07be6e: /* original 9218, guest PC 0x0c07be6e */
if(!s->budget--) { s->failed_pc=0x0c07be6eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea2u,2);
goto P_0c07be70;
P_0c07be70: /* original 4400, guest PC 0x0c07be70 */
if(!s->budget--) { s->failed_pc=0x0c07be70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be72;
P_0c07be72: /* original 330c, guest PC 0x0c07be72 */
if(!s->budget--) { s->failed_pc=0x0c07be72u; return 0; }
r[3]+=r[0];
goto P_0c07be74;
P_0c07be74: /* original 60f2, guest PC 0x0c07be74 */
if(!s->budget--) { s->failed_pc=0x0c07be74u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07be76;
P_0c07be76: /* original 334c, guest PC 0x0c07be76 */
if(!s->budget--) { s->failed_pc=0x0c07be76u; return 0; }
r[3]+=r[4];
goto P_0c07be78;
P_0c07be78: /* original 320c, guest PC 0x0c07be78 */
if(!s->budget--) { s->failed_pc=0x0c07be78u; return 0; }
r[2]+=r[0];
goto P_0c07be7a;
P_0c07be7a: /* original 324c, guest PC 0x0c07be7a */
if(!s->budget--) { s->failed_pc=0x0c07be7au; return 0; }
r[2]+=r[4];
goto P_0c07be7c;
P_0c07be7c: /* original 6121, guest PC 0x0c07be7c */
if(!s->budget--) { s->failed_pc=0x0c07be7cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c07be7e;
P_0c07be7e: /* original 2311, guest PC 0x0c07be7e */
if(!s->budget--) { s->failed_pc=0x0c07be7eu; return 0; }
write(ram,r[3],r[1],2);
goto P_0c07be80;
P_0c07be80: /* original 50f4, guest PC 0x0c07be80 */
if(!s->budget--) { s->failed_pc=0x0c07be80u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07be82;
P_0c07be82: /* original 63c3, guest PC 0x0c07be82 */
if(!s->budget--) { s->failed_pc=0x0c07be82u; return 0; }
r[3]=r[12];
goto P_0c07be84;
P_0c07be84: /* original 4308, guest PC 0x0c07be84 */
if(!s->budget--) { s->failed_pc=0x0c07be84u; return 0; }
r[3]<<=2;
goto P_0c07be86;
P_0c07be86: /* original 033e, guest PC 0x0c07be86 */
if(!s->budget--) { s->failed_pc=0x0c07be86u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07be88;
P_0c07be88: /* original 33a3, guest PC 0x0c07be88 */
if(!s->budget--) { s->failed_pc=0x0c07be88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c07be8a;
P_0c07be8a: /* original 8b54, guest PC 0x0c07be8a */
if(!s->budget--) { s->failed_pc=0x0c07be8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bf36; }
goto P_0c07be8c;
P_0c07be8c: /* original 930a, guest PC 0x0c07be8c */
if(!s->budget--) { s->failed_pc=0x0c07be8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea4u,2);
goto P_0c07be8e;
P_0c07be8e: /* original 64c3, guest PC 0x0c07be8e */
if(!s->budget--) { s->failed_pc=0x0c07be8eu; return 0; }
r[4]=r[12];
goto P_0c07be90;
P_0c07be90: /* original 52f2, guest PC 0x0c07be90 */
if(!s->budget--) { s->failed_pc=0x0c07be90u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07be92;
P_0c07be92: /* original 4408, guest PC 0x0c07be92 */
if(!s->budget--) { s->failed_pc=0x0c07be92u; return 0; }
r[4]<<=2;
goto P_0c07be94;
P_0c07be94: /* original 33fc, guest PC 0x0c07be94 */
if(!s->budget--) { s->failed_pc=0x0c07be94u; return 0; }
r[3]+=r[15];
goto P_0c07be96;
P_0c07be96: /* original 323c, guest PC 0x0c07be96 */
if(!s->budget--) { s->failed_pc=0x0c07be96u; return 0; }
r[2]+=r[3];
goto P_0c07be98;
P_0c07be98: /* original a00a, guest PC 0x0c07be98 */
if(!s->budget--) { s->failed_pc=0x0c07be98u; return 0; }
goto P_0c07beb0;
P_0c07be9a: /* original 0009, guest PC 0x0c07be9a */
if(!s->budget--) { s->failed_pc=0x0c07be9au; return 0; }
if(!vf3_matrix_family(0x0c07be9cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07be9cu; return 0; } return 1;
P_0c07beb0: /* original 324c, guest PC 0x0c07beb0 */
if(!s->budget--) { s->failed_pc=0x0c07beb0u; return 0; }
r[2]+=r[4];
goto P_0c07beb2;
P_0c07beb2: /* original 1f25, guest PC 0x0c07beb2 */
if(!s->budget--) { s->failed_pc=0x0c07beb2u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07beb4;
P_0c07beb4: /* original 90c6, guest PC 0x0c07beb4 */
if(!s->budget--) { s->failed_pc=0x0c07beb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c044u,2);
goto P_0c07beb6;
P_0c07beb6: /* original 51f2, guest PC 0x0c07beb6 */
if(!s->budget--) { s->failed_pc=0x0c07beb6u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07beb8;
P_0c07beb8: /* original 30fc, guest PC 0x0c07beb8 */
if(!s->budget--) { s->failed_pc=0x0c07beb8u; return 0; }
r[0]+=r[15];
goto P_0c07beba;
P_0c07beba: /* original 310c, guest PC 0x0c07beba */
if(!s->budget--) { s->failed_pc=0x0c07bebau; return 0; }
r[1]+=r[0];
goto P_0c07bebc;
P_0c07bebc: /* original 314c, guest PC 0x0c07bebc */
if(!s->budget--) { s->failed_pc=0x0c07bebcu; return 0; }
r[1]+=r[4];
goto P_0c07bebe;
P_0c07bebe: /* original 1f16, guest PC 0x0c07bebe */
if(!s->budget--) { s->failed_pc=0x0c07bebeu; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bec0;
P_0c07bec0: /* original 6112, guest PC 0x0c07bec0 */
if(!s->budget--) { s->failed_pc=0x0c07bec0u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bec2;
P_0c07bec2: /* original d365, guest PC 0x0c07bec2 */
if(!s->budget--) { s->failed_pc=0x0c07bec2u; return 0; }
r[3]=read(ram,0x0c07c058u,4);
goto P_0c07bec4;
P_0c07bec4: /* original 430b, guest PC 0x0c07bec4 */
if(!s->budget--) { s->failed_pc=0x0c07bec4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bec8u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bec8u) { target=s->pc; goto dispatch; }
goto P_0c07bec8;
P_0c07bec6: /* original 60a3, guest PC 0x0c07bec6 */
if(!s->budget--) { s->failed_pc=0x0c07bec6u; return 0; }
r[0]=r[10];
goto P_0c07bec8;
P_0c07bec8: /* original 2202, guest PC 0x0c07bec8 */
if(!s->budget--) { s->failed_pc=0x0c07bec8u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07beca;
P_0c07beca: /* original 62c3, guest PC 0x0c07beca */
if(!s->budget--) { s->failed_pc=0x0c07becau; return 0; }
r[2]=r[12];
goto P_0c07becc;
P_0c07becc: /* original 4208, guest PC 0x0c07becc */
if(!s->budget--) { s->failed_pc=0x0c07beccu; return 0; }
r[2]<<=2;
goto P_0c07bece;
P_0c07bece: /* original 63c3, guest PC 0x0c07bece */
if(!s->budget--) { s->failed_pc=0x0c07beceu; return 0; }
r[3]=r[12];
goto P_0c07bed0;
P_0c07bed0: /* original 323c, guest PC 0x0c07bed0 */
if(!s->budget--) { s->failed_pc=0x0c07bed0u; return 0; }
r[2]+=r[3];
goto P_0c07bed2;
P_0c07bed2: /* original 51f1, guest PC 0x0c07bed2 */
if(!s->budget--) { s->failed_pc=0x0c07bed2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07bed4;
P_0c07bed4: /* original 4208, guest PC 0x0c07bed4 */
if(!s->budget--) { s->failed_pc=0x0c07bed4u; return 0; }
r[2]<<=2;
goto P_0c07bed6;
P_0c07bed6: /* original 66d3, guest PC 0x0c07bed6 */
if(!s->budget--) { s->failed_pc=0x0c07bed6u; return 0; }
r[6]=r[13];
goto P_0c07bed8;
P_0c07bed8: /* original 4200, guest PC 0x0c07bed8 */
if(!s->budget--) { s->failed_pc=0x0c07bed8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07beda;
P_0c07beda: /* original 720d, guest PC 0x0c07beda */
if(!s->budget--) { s->failed_pc=0x0c07bedau; return 0; }
r[2]+=0x0000000du;
goto P_0c07bedc;
P_0c07bedc: /* original 4200, guest PC 0x0c07bedc */
if(!s->budget--) { s->failed_pc=0x0c07bedcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07bede;
P_0c07bede: /* original 221b, guest PC 0x0c07bede */
if(!s->budget--) { s->failed_pc=0x0c07bedeu; return 0; }
r[2]|=r[1];
goto P_0c07bee0;
P_0c07bee0: /* original 1f2e, guest PC 0x0c07bee0 */
if(!s->budget--) { s->failed_pc=0x0c07bee0u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c07bee2;
P_0c07bee2: /* original e700, guest PC 0x0c07bee2 */
if(!s->budget--) { s->failed_pc=0x0c07bee2u; return 0; }
r[7]=0x00000000u;
goto P_0c07bee4;
P_0c07bee4: /* original 2fb6, guest PC 0x0c07bee4 */
if(!s->budget--) { s->failed_pc=0x0c07bee4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bee6;
P_0c07bee6: /* original 2fe6, guest PC 0x0c07bee6 */
if(!s->budget--) { s->failed_pc=0x0c07bee6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bee8;
P_0c07bee8: /* original 50f7, guest PC 0x0c07bee8 */
if(!s->budget--) { s->failed_pc=0x0c07bee8u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c07beea;
P_0c07beea: /* original 6002, guest PC 0x0c07beea */
if(!s->budget--) { s->failed_pc=0x0c07beeau; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07beec;
P_0c07beec: /* original 4008, guest PC 0x0c07beec */
if(!s->budget--) { s->failed_pc=0x0c07beecu; return 0; }
r[0]<<=2;
goto P_0c07beee;
P_0c07beee: /* original 059e, guest PC 0x0c07beee */
if(!s->budget--) { s->failed_pc=0x0c07beeeu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bef0;
P_0c07bef0: /* original 480b, guest PC 0x0c07bef0 */
if(!s->budget--) { s->failed_pc=0x0c07bef0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bef4u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bef4u) { target=s->pc; goto dispatch; }
goto P_0c07bef4;
P_0c07bef2: /* original 6423, guest PC 0x0c07bef2 */
if(!s->budget--) { s->failed_pc=0x0c07bef2u; return 0; }
r[4]=r[2];
goto P_0c07bef4;
P_0c07bef4: /* original 7f08, guest PC 0x0c07bef4 */
if(!s->budget--) { s->failed_pc=0x0c07bef4u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bef6;
P_0c07bef6: /* original 6403, guest PC 0x0c07bef6 */
if(!s->budget--) { s->failed_pc=0x0c07bef6u; return 0; }
r[4]=r[0];
goto P_0c07bef8;
P_0c07bef8: /* original e030, guest PC 0x0c07bef8 */
if(!s->budget--) { s->failed_pc=0x0c07bef8u; return 0; }
r[0]=0x00000030u;
goto P_0c07befa;
P_0c07befa: /* original f4f7, guest PC 0x0c07befa */
if(!s->budget--) { s->failed_pc=0x0c07befau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07befc;
P_0c07befc: /* original 52f5, guest PC 0x0c07befc */
if(!s->budget--) { s->failed_pc=0x0c07befcu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07befe;
P_0c07befe: /* original 53f6, guest PC 0x0c07befe */
if(!s->budget--) { s->failed_pc=0x0c07befeu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07bf00;
P_0c07bf00: /* original 6122, guest PC 0x0c07bf00 */
if(!s->budget--) { s->failed_pc=0x0c07bf00u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07bf02;
P_0c07bf02: /* original 6232, guest PC 0x0c07bf02 */
if(!s->budget--) { s->failed_pc=0x0c07bf02u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07bf04;
P_0c07bf04: /* original 01a7, guest PC 0x0c07bf04 */
if(!s->budget--) { s->failed_pc=0x0c07bf04u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07bf06;
P_0c07bf06: /* original 011a, guest PC 0x0c07bf06 */
if(!s->budget--) { s->failed_pc=0x0c07bf06u; return 0; }
r[1]=r[19];
goto P_0c07bf08;
P_0c07bf08: /* original 3218, guest PC 0x0c07bf08 */
if(!s->budget--) { s->failed_pc=0x0c07bf08u; return 0; }
r[2]-=r[1];
goto P_0c07bf0a;
P_0c07bf0a: /* original 2322, guest PC 0x0c07bf0a */
if(!s->budget--) { s->failed_pc=0x0c07bf0au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07bf0c;
P_0c07bf0c: /* original e20a, guest PC 0x0c07bf0c */
if(!s->budget--) { s->failed_pc=0x0c07bf0cu; return 0; }
r[2]=0x0000000au;
goto P_0c07bf0e;
P_0c07bf0e: /* original 53f6, guest PC 0x0c07bf0e */
if(!s->budget--) { s->failed_pc=0x0c07bf0eu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07bf10;
P_0c07bf10: /* original 6132, guest PC 0x0c07bf10 */
if(!s->budget--) { s->failed_pc=0x0c07bf10u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bf12;
P_0c07bf12: /* original 3123, guest PC 0x0c07bf12 */
if(!s->budget--) { s->failed_pc=0x0c07bf12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07bf14;
P_0c07bf14: /* original 890f, guest PC 0x0c07bf14 */
if(!s->budget--) { s->failed_pc=0x0c07bf14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bf36; }
goto P_0c07bf16;
P_0c07bf16: /* original 50f3, guest PC 0x0c07bf16 */
if(!s->budget--) { s->failed_pc=0x0c07bf16u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c07bf18;
P_0c07bf18: /* original e700, guest PC 0x0c07bf18 */
if(!s->budget--) { s->failed_pc=0x0c07bf18u; return 0; }
r[7]=0x00000000u;
goto P_0c07bf1a;
P_0c07bf1a: /* original 53f1, guest PC 0x0c07bf1a */
if(!s->budget--) { s->failed_pc=0x0c07bf1au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bf1c;
P_0c07bf1c: /* original 66d3, guest PC 0x0c07bf1c */
if(!s->budget--) { s->failed_pc=0x0c07bf1cu; return 0; }
r[6]=r[13];
goto P_0c07bf1e;
P_0c07bf1e: /* original 203b, guest PC 0x0c07bf1e */
if(!s->budget--) { s->failed_pc=0x0c07bf1eu; return 0; }
r[0]|=r[3];
goto P_0c07bf20;
P_0c07bf20: /* original 1f03, guest PC 0x0c07bf20 */
if(!s->budget--) { s->failed_pc=0x0c07bf20u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c07bf22;
P_0c07bf22: /* original 2fb6, guest PC 0x0c07bf22 */
if(!s->budget--) { s->failed_pc=0x0c07bf22u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf24;
P_0c07bf24: /* original 2fe6, guest PC 0x0c07bf24 */
if(!s->budget--) { s->failed_pc=0x0c07bf24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf26;
P_0c07bf26: /* original 55fc, guest PC 0x0c07bf26 */
if(!s->budget--) { s->failed_pc=0x0c07bf26u; return 0; }
r[5]=read(ram,r[15]+48,4);
goto P_0c07bf28;
P_0c07bf28: /* original 6552, guest PC 0x0c07bf28 */
if(!s->budget--) { s->failed_pc=0x0c07bf28u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c07bf2a;
P_0c07bf2a: /* original 480b, guest PC 0x0c07bf2a */
if(!s->budget--) { s->failed_pc=0x0c07bf2au; return 0; }
target=r[8];
r[16]=code_base|0x0c07bf2eu;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bf2eu) { target=s->pc; goto dispatch; }
goto P_0c07bf2e;
P_0c07bf2c: /* original 54f5, guest PC 0x0c07bf2c */
if(!s->budget--) { s->failed_pc=0x0c07bf2cu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07bf2e;
P_0c07bf2e: /* original 6403, guest PC 0x0c07bf2e */
if(!s->budget--) { s->failed_pc=0x0c07bf2eu; return 0; }
r[4]=r[0];
goto P_0c07bf30;
P_0c07bf30: /* original e030, guest PC 0x0c07bf30 */
if(!s->budget--) { s->failed_pc=0x0c07bf30u; return 0; }
r[0]=0x00000030u;
goto P_0c07bf32;
P_0c07bf32: /* original f4f7, guest PC 0x0c07bf32 */
if(!s->budget--) { s->failed_pc=0x0c07bf32u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bf34;
P_0c07bf34: /* original 7f08, guest PC 0x0c07bf34 */
if(!s->budget--) { s->failed_pc=0x0c07bf34u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bf36;
P_0c07bf36: /* original 50f4, guest PC 0x0c07bf36 */
if(!s->budget--) { s->failed_pc=0x0c07bf36u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07bf38;
P_0c07bf38: /* original 63c3, guest PC 0x0c07bf38 */
if(!s->budget--) { s->failed_pc=0x0c07bf38u; return 0; }
r[3]=r[12];
goto P_0c07bf3a;
P_0c07bf3a: /* original 4308, guest PC 0x0c07bf3a */
if(!s->budget--) { s->failed_pc=0x0c07bf3au; return 0; }
r[3]<<=2;
goto P_0c07bf3c;
P_0c07bf3c: /* original 033e, guest PC 0x0c07bf3c */
if(!s->budget--) { s->failed_pc=0x0c07bf3cu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07bf3e;
P_0c07bf3e: /* original e20a, guest PC 0x0c07bf3e */
if(!s->budget--) { s->failed_pc=0x0c07bf3eu; return 0; }
r[2]=0x0000000au;
goto P_0c07bf40;
P_0c07bf40: /* original 3323, guest PC 0x0c07bf40 */
if(!s->budget--) { s->failed_pc=0x0c07bf40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07bf42;
P_0c07bf42: /* original 8b30, guest PC 0x0c07bf42 */
if(!s->budget--) { s->failed_pc=0x0c07bf42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bfa6; }
goto P_0c07bf44;
P_0c07bf44: /* original 937f, guest PC 0x0c07bf44 */
if(!s->budget--) { s->failed_pc=0x0c07bf44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c046u,2);
goto P_0c07bf46;
P_0c07bf46: /* original 64c3, guest PC 0x0c07bf46 */
if(!s->budget--) { s->failed_pc=0x0c07bf46u; return 0; }
r[4]=r[12];
goto P_0c07bf48;
P_0c07bf48: /* original 51f2, guest PC 0x0c07bf48 */
if(!s->budget--) { s->failed_pc=0x0c07bf48u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07bf4a;
P_0c07bf4a: /* original 4408, guest PC 0x0c07bf4a */
if(!s->budget--) { s->failed_pc=0x0c07bf4au; return 0; }
r[4]<<=2;
goto P_0c07bf4c;
P_0c07bf4c: /* original 33fc, guest PC 0x0c07bf4c */
if(!s->budget--) { s->failed_pc=0x0c07bf4cu; return 0; }
r[3]+=r[15];
goto P_0c07bf4e;
P_0c07bf4e: /* original 313c, guest PC 0x0c07bf4e */
if(!s->budget--) { s->failed_pc=0x0c07bf4eu; return 0; }
r[1]+=r[3];
goto P_0c07bf50;
P_0c07bf50: /* original 314c, guest PC 0x0c07bf50 */
if(!s->budget--) { s->failed_pc=0x0c07bf50u; return 0; }
r[1]+=r[4];
goto P_0c07bf52;
P_0c07bf52: /* original 1f13, guest PC 0x0c07bf52 */
if(!s->budget--) { s->failed_pc=0x0c07bf52u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07bf54;
P_0c07bf54: /* original 2f16, guest PC 0x0c07bf54 */
if(!s->budget--) { s->failed_pc=0x0c07bf54u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf56;
P_0c07bf56: /* original 9277, guest PC 0x0c07bf56 */
if(!s->budget--) { s->failed_pc=0x0c07bf56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c048u,2);
goto P_0c07bf58;
P_0c07bf58: /* original 51f3, guest PC 0x0c07bf58 */
if(!s->budget--) { s->failed_pc=0x0c07bf58u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07bf5a;
P_0c07bf5a: /* original 32fc, guest PC 0x0c07bf5a */
if(!s->budget--) { s->failed_pc=0x0c07bf5au; return 0; }
r[2]+=r[15];
goto P_0c07bf5c;
P_0c07bf5c: /* original 312c, guest PC 0x0c07bf5c */
if(!s->budget--) { s->failed_pc=0x0c07bf5cu; return 0; }
r[1]+=r[2];
goto P_0c07bf5e;
P_0c07bf5e: /* original 314c, guest PC 0x0c07bf5e */
if(!s->budget--) { s->failed_pc=0x0c07bf5eu; return 0; }
r[1]+=r[4];
goto P_0c07bf60;
P_0c07bf60: /* original 1f16, guest PC 0x0c07bf60 */
if(!s->budget--) { s->failed_pc=0x0c07bf60u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bf62;
P_0c07bf62: /* original d33d, guest PC 0x0c07bf62 */
if(!s->budget--) { s->failed_pc=0x0c07bf62u; return 0; }
r[3]=read(ram,0x0c07c058u,4);
goto P_0c07bf64;
P_0c07bf64: /* original 6112, guest PC 0x0c07bf64 */
if(!s->budget--) { s->failed_pc=0x0c07bf64u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bf66;
P_0c07bf66: /* original 430b, guest PC 0x0c07bf66 */
if(!s->budget--) { s->failed_pc=0x0c07bf66u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bf6au;
r[0]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bf6au) { target=s->pc; goto dispatch; }
goto P_0c07bf6a;
P_0c07bf68: /* original e00a, guest PC 0x0c07bf68 */
if(!s->budget--) { s->failed_pc=0x0c07bf68u; return 0; }
r[0]=0x0000000au;
goto P_0c07bf6a;
P_0c07bf6a: /* original 63f6, guest PC 0x0c07bf6a */
if(!s->budget--) { s->failed_pc=0x0c07bf6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c07bf6c;
P_0c07bf6c: /* original e700, guest PC 0x0c07bf6c */
if(!s->budget--) { s->failed_pc=0x0c07bf6cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bf6e;
P_0c07bf6e: /* original 66d3, guest PC 0x0c07bf6e */
if(!s->budget--) { s->failed_pc=0x0c07bf6eu; return 0; }
r[6]=r[13];
goto P_0c07bf70;
P_0c07bf70: /* original 2302, guest PC 0x0c07bf70 */
if(!s->budget--) { s->failed_pc=0x0c07bf70u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07bf72;
P_0c07bf72: /* original 51f1, guest PC 0x0c07bf72 */
if(!s->budget--) { s->failed_pc=0x0c07bf72u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07bf74;
P_0c07bf74: /* original 53f7, guest PC 0x0c07bf74 */
if(!s->budget--) { s->failed_pc=0x0c07bf74u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c07bf76;
P_0c07bf76: /* original 213b, guest PC 0x0c07bf76 */
if(!s->budget--) { s->failed_pc=0x0c07bf76u; return 0; }
r[1]|=r[3];
goto P_0c07bf78;
P_0c07bf78: /* original 1f16, guest PC 0x0c07bf78 */
if(!s->budget--) { s->failed_pc=0x0c07bf78u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bf7a;
P_0c07bf7a: /* original 2fb6, guest PC 0x0c07bf7a */
if(!s->budget--) { s->failed_pc=0x0c07bf7au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf7c;
P_0c07bf7c: /* original 2fe6, guest PC 0x0c07bf7c */
if(!s->budget--) { s->failed_pc=0x0c07bf7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf7e;
P_0c07bf7e: /* original 50f5, guest PC 0x0c07bf7e */
if(!s->budget--) { s->failed_pc=0x0c07bf7eu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c07bf80;
P_0c07bf80: /* original 6002, guest PC 0x0c07bf80 */
if(!s->budget--) { s->failed_pc=0x0c07bf80u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bf82;
P_0c07bf82: /* original 4008, guest PC 0x0c07bf82 */
if(!s->budget--) { s->failed_pc=0x0c07bf82u; return 0; }
r[0]<<=2;
goto P_0c07bf84;
P_0c07bf84: /* original 059e, guest PC 0x0c07bf84 */
if(!s->budget--) { s->failed_pc=0x0c07bf84u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bf86;
P_0c07bf86: /* original 480b, guest PC 0x0c07bf86 */
if(!s->budget--) { s->failed_pc=0x0c07bf86u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bf8au;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bf8au) { target=s->pc; goto dispatch; }
goto P_0c07bf8a;
P_0c07bf88: /* original 6413, guest PC 0x0c07bf88 */
if(!s->budget--) { s->failed_pc=0x0c07bf88u; return 0; }
r[4]=r[1];
goto P_0c07bf8a;
P_0c07bf8a: /* original 7f08, guest PC 0x0c07bf8a */
if(!s->budget--) { s->failed_pc=0x0c07bf8au; return 0; }
r[15]+=0x00000008u;
goto P_0c07bf8c;
P_0c07bf8c: /* original 6403, guest PC 0x0c07bf8c */
if(!s->budget--) { s->failed_pc=0x0c07bf8cu; return 0; }
r[4]=r[0];
goto P_0c07bf8e;
P_0c07bf8e: /* original e030, guest PC 0x0c07bf8e */
if(!s->budget--) { s->failed_pc=0x0c07bf8eu; return 0; }
r[0]=0x00000030u;
goto P_0c07bf90;
P_0c07bf90: /* original f4f7, guest PC 0x0c07bf90 */
if(!s->budget--) { s->failed_pc=0x0c07bf90u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bf92;
P_0c07bf92: /* original 52f3, guest PC 0x0c07bf92 */
if(!s->budget--) { s->failed_pc=0x0c07bf92u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c07bf94;
P_0c07bf94: /* original 53f5, guest PC 0x0c07bf94 */
if(!s->budget--) { s->failed_pc=0x0c07bf94u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07bf96;
P_0c07bf96: /* original 6222, guest PC 0x0c07bf96 */
if(!s->budget--) { s->failed_pc=0x0c07bf96u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07bf98;
P_0c07bf98: /* original 6032, guest PC 0x0c07bf98 */
if(!s->budget--) { s->failed_pc=0x0c07bf98u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bf9a;
P_0c07bf9a: /* original 6123, guest PC 0x0c07bf9a */
if(!s->budget--) { s->failed_pc=0x0c07bf9au; return 0; }
r[1]=r[2];
goto P_0c07bf9c;
P_0c07bf9c: /* original 4208, guest PC 0x0c07bf9c */
if(!s->budget--) { s->failed_pc=0x0c07bf9cu; return 0; }
r[2]<<=2;
goto P_0c07bf9e;
P_0c07bf9e: /* original 321c, guest PC 0x0c07bf9e */
if(!s->budget--) { s->failed_pc=0x0c07bf9eu; return 0; }
r[2]+=r[1];
goto P_0c07bfa0;
P_0c07bfa0: /* original 4200, guest PC 0x0c07bfa0 */
if(!s->budget--) { s->failed_pc=0x0c07bfa0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07bfa2;
P_0c07bfa2: /* original 3028, guest PC 0x0c07bfa2 */
if(!s->budget--) { s->failed_pc=0x0c07bfa2u; return 0; }
r[0]-=r[2];
goto P_0c07bfa4;
P_0c07bfa4: /* original 2302, guest PC 0x0c07bfa4 */
if(!s->budget--) { s->failed_pc=0x0c07bfa4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07bfa6;
P_0c07bfa6: /* original 52f1, guest PC 0x0c07bfa6 */
if(!s->budget--) { s->failed_pc=0x0c07bfa6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07bfa8;
P_0c07bfa8: /* original e700, guest PC 0x0c07bfa8 */
if(!s->budget--) { s->failed_pc=0x0c07bfa8u; return 0; }
r[7]=0x00000000u;
goto P_0c07bfaa;
P_0c07bfaa: /* original 53fb, guest PC 0x0c07bfaa */
if(!s->budget--) { s->failed_pc=0x0c07bfaau; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c07bfac;
P_0c07bfac: /* original 66d3, guest PC 0x0c07bfac */
if(!s->budget--) { s->failed_pc=0x0c07bfacu; return 0; }
r[6]=r[13];
goto P_0c07bfae;
P_0c07bfae: /* original 223b, guest PC 0x0c07bfae */
if(!s->budget--) { s->failed_pc=0x0c07bfaeu; return 0; }
r[2]|=r[3];
goto P_0c07bfb0;
P_0c07bfb0: /* original 1f23, guest PC 0x0c07bfb0 */
if(!s->budget--) { s->failed_pc=0x0c07bfb0u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c07bfb2;
P_0c07bfb2: /* original 2fb6, guest PC 0x0c07bfb2 */
if(!s->budget--) { s->failed_pc=0x0c07bfb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bfb4;
P_0c07bfb4: /* original 2fe6, guest PC 0x0c07bfb4 */
if(!s->budget--) { s->failed_pc=0x0c07bfb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bfb6;
P_0c07bfb6: /* original 50fb, guest PC 0x0c07bfb6 */
if(!s->budget--) { s->failed_pc=0x0c07bfb6u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c07bfb8;
P_0c07bfb8: /* original 6002, guest PC 0x0c07bfb8 */
if(!s->budget--) { s->failed_pc=0x0c07bfb8u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bfba;
P_0c07bfba: /* original 4008, guest PC 0x0c07bfba */
if(!s->budget--) { s->failed_pc=0x0c07bfbau; return 0; }
r[0]<<=2;
goto P_0c07bfbc;
P_0c07bfbc: /* original 059e, guest PC 0x0c07bfbc */
if(!s->budget--) { s->failed_pc=0x0c07bfbcu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bfbe;
P_0c07bfbe: /* original 480b, guest PC 0x0c07bfbe */
if(!s->budget--) { s->failed_pc=0x0c07bfbeu; return 0; }
target=r[8];
r[16]=code_base|0x0c07bfc2u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bfc2u) { target=s->pc; goto dispatch; }
goto P_0c07bfc2;
P_0c07bfc0: /* original 6423, guest PC 0x0c07bfc0 */
if(!s->budget--) { s->failed_pc=0x0c07bfc0u; return 0; }
r[4]=r[2];
goto P_0c07bfc2;
P_0c07bfc2: /* original 7f08, guest PC 0x0c07bfc2 */
if(!s->budget--) { s->failed_pc=0x0c07bfc2u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bfc4;
P_0c07bfc4: /* original 6403, guest PC 0x0c07bfc4 */
if(!s->budget--) { s->failed_pc=0x0c07bfc4u; return 0; }
r[4]=r[0];
goto P_0c07bfc6;
P_0c07bfc6: /* original e030, guest PC 0x0c07bfc6 */
if(!s->budget--) { s->failed_pc=0x0c07bfc6u; return 0; }
r[0]=0x00000030u;
goto P_0c07bfc8;
P_0c07bfc8: /* original f4f7, guest PC 0x0c07bfc8 */
if(!s->budget--) { s->failed_pc=0x0c07bfc8u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bfca;
P_0c07bfca: /* original 7c01, guest PC 0x0c07bfca */
if(!s->budget--) { s->failed_pc=0x0c07bfcau; return 0; }
r[12]+=0x00000001u;
goto P_0c07bfcc;
P_0c07bfcc: /* original 53f9, guest PC 0x0c07bfcc */
if(!s->budget--) { s->failed_pc=0x0c07bfccu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07bfce;
P_0c07bfce: /* original 7304, guest PC 0x0c07bfce */
if(!s->budget--) { s->failed_pc=0x0c07bfceu; return 0; }
r[3]+=0x00000004u;
goto P_0c07bfd0;
P_0c07bfd0: /* original 1f39, guest PC 0x0c07bfd0 */
if(!s->budget--) { s->failed_pc=0x0c07bfd0u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07bfd2;
P_0c07bfd2: /* original 52fb, guest PC 0x0c07bfd2 */
if(!s->budget--) { s->failed_pc=0x0c07bfd2u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c07bfd4;
P_0c07bfd4: /* original 7250, guest PC 0x0c07bfd4 */
if(!s->budget--) { s->failed_pc=0x0c07bfd4u; return 0; }
r[2]+=0x00000050u;
goto P_0c07bfd6;
P_0c07bfd6: /* original 1f2b, guest PC 0x0c07bfd6 */
if(!s->budget--) { s->failed_pc=0x0c07bfd6u; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c07bfd8;
P_0c07bfd8: /* original 51f7, guest PC 0x0c07bfd8 */
if(!s->budget--) { s->failed_pc=0x0c07bfd8u; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c07bfda;
P_0c07bfda: /* original 7150, guest PC 0x0c07bfda */
if(!s->budget--) { s->failed_pc=0x0c07bfdau; return 0; }
r[1]+=0x00000050u;
goto P_0c07bfdc;
P_0c07bfdc: /* original 1f17, guest PC 0x0c07bfdc */
if(!s->budget--) { s->failed_pc=0x0c07bfdcu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07bfde;
P_0c07bfde: /* original e302, guest PC 0x0c07bfde */
if(!s->budget--) { s->failed_pc=0x0c07bfdeu; return 0; }
r[3]=0x00000002u;
goto P_0c07bfe0;
P_0c07bfe0: /* original 3c33, guest PC 0x0c07bfe0 */
if(!s->budget--) { s->failed_pc=0x0c07bfe0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c07bfe2;
P_0c07bfe2: /* original 8901, guest PC 0x0c07bfe2 */
if(!s->budget--) { s->failed_pc=0x0c07bfe2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bfe8; }
goto P_0c07bfe4;
P_0c07bfe4: /* original ae96, guest PC 0x0c07bfe4 */
if(!s->budget--) { s->failed_pc=0x0c07bfe4u; return 0; }
goto P_0c07bd14;
P_0c07bfe6: /* original 0009, guest PC 0x0c07bfe6 */
if(!s->budget--) { s->failed_pc=0x0c07bfe6u; return 0; }
goto P_0c07bfe8;
P_0c07bfe8: /* original 51f8, guest PC 0x0c07bfe8 */
if(!s->budget--) { s->failed_pc=0x0c07bfe8u; return 0; }
r[1]=read(ram,r[15]+32,4);
goto P_0c07bfea;
P_0c07bfea: /* original 7101, guest PC 0x0c07bfea */
if(!s->budget--) { s->failed_pc=0x0c07bfeau; return 0; }
r[1]+=0x00000001u;
goto P_0c07bfec;
P_0c07bfec: /* original 1f18, guest PC 0x0c07bfec */
if(!s->budget--) { s->failed_pc=0x0c07bfecu; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c07bfee;
P_0c07bfee: /* original 52f8, guest PC 0x0c07bfee */
if(!s->budget--) { s->failed_pc=0x0c07bfeeu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c07bff0;
P_0c07bff0: /* original e302, guest PC 0x0c07bff0 */
if(!s->budget--) { s->failed_pc=0x0c07bff0u; return 0; }
r[3]=0x00000002u;
goto P_0c07bff2;
P_0c07bff2: /* original 3233, guest PC 0x0c07bff2 */
if(!s->budget--) { s->failed_pc=0x0c07bff2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c07bff4;
P_0c07bff4: /* original 8901, guest PC 0x0c07bff4 */
if(!s->budget--) { s->failed_pc=0x0c07bff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bffa; }
goto P_0c07bff6;
P_0c07bff6: /* original ae64, guest PC 0x0c07bff6 */
if(!s->budget--) { s->failed_pc=0x0c07bff6u; return 0; }
goto P_0c07bcc2;
P_0c07bff8: /* original 0009, guest PC 0x0c07bff8 */
if(!s->budget--) { s->failed_pc=0x0c07bff8u; return 0; }
goto P_0c07bffa;
P_0c07bffa: /* original 2fb6, guest PC 0x0c07bffa */
if(!s->budget--) { s->failed_pc=0x0c07bffau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bffc;
P_0c07bffc: /* original e700, guest PC 0x0c07bffc */
if(!s->budget--) { s->failed_pc=0x0c07bffcu; return 0; }
r[7]=0x00000000u;
goto P_0c07bffe;
P_0c07bffe: /* original 2fe6, guest PC 0x0c07bffe */
if(!s->budget--) { s->failed_pc=0x0c07bffeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c000;
P_0c07c000: /* original 9523, guest PC 0x0c07c000 */
if(!s->budget--) { s->failed_pc=0x0c07c000u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04au,2);
goto P_0c07c002;
P_0c07c002: /* original 9423, guest PC 0x0c07c002 */
if(!s->budget--) { s->failed_pc=0x0c07c002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04cu,2);
goto P_0c07c004;
P_0c07c004: /* original 480b, guest PC 0x0c07c004 */
if(!s->budget--) { s->failed_pc=0x0c07c004u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c008u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c008u) { target=s->pc; goto dispatch; }
goto P_0c07c008;
P_0c07c006: /* original 66d3, guest PC 0x0c07c006 */
if(!s->budget--) { s->failed_pc=0x0c07c006u; return 0; }
r[6]=r[13];
goto P_0c07c008;
P_0c07c008: /* original 6403, guest PC 0x0c07c008 */
if(!s->budget--) { s->failed_pc=0x0c07c008u; return 0; }
r[4]=r[0];
goto P_0c07c00a;
P_0c07c00a: /* original e030, guest PC 0x0c07c00a */
if(!s->budget--) { s->failed_pc=0x0c07c00au; return 0; }
r[0]=0x00000030u;
goto P_0c07c00c;
P_0c07c00c: /* original f4f7, guest PC 0x0c07c00c */
if(!s->budget--) { s->failed_pc=0x0c07c00cu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c00e;
P_0c07c00e: /* original e700, guest PC 0x0c07c00e */
if(!s->budget--) { s->failed_pc=0x0c07c00eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c010;
P_0c07c010: /* original 2fb6, guest PC 0x0c07c010 */
if(!s->budget--) { s->failed_pc=0x0c07c010u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c012;
P_0c07c012: /* original 2fe6, guest PC 0x0c07c012 */
if(!s->budget--) { s->failed_pc=0x0c07c012u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c014;
P_0c07c014: /* original 951b, guest PC 0x0c07c014 */
if(!s->budget--) { s->failed_pc=0x0c07c014u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04eu,2);
goto P_0c07c016;
P_0c07c016: /* original 941b, guest PC 0x0c07c016 */
if(!s->budget--) { s->failed_pc=0x0c07c016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c050u,2);
goto P_0c07c018;
P_0c07c018: /* original 480b, guest PC 0x0c07c018 */
if(!s->budget--) { s->failed_pc=0x0c07c018u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c01cu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c01cu) { target=s->pc; goto dispatch; }
goto P_0c07c01c;
P_0c07c01a: /* original 66d3, guest PC 0x0c07c01a */
if(!s->budget--) { s->failed_pc=0x0c07c01au; return 0; }
r[6]=r[13];
goto P_0c07c01c;
P_0c07c01c: /* original 6403, guest PC 0x0c07c01c */
if(!s->budget--) { s->failed_pc=0x0c07c01cu; return 0; }
r[4]=r[0];
goto P_0c07c01e;
P_0c07c01e: /* original e030, guest PC 0x0c07c01e */
if(!s->budget--) { s->failed_pc=0x0c07c01eu; return 0; }
r[0]=0x00000030u;
goto P_0c07c020;
P_0c07c020: /* original f4f7, guest PC 0x0c07c020 */
if(!s->budget--) { s->failed_pc=0x0c07c020u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c022;
P_0c07c022: /* original e700, guest PC 0x0c07c022 */
if(!s->budget--) { s->failed_pc=0x0c07c022u; return 0; }
r[7]=0x00000000u;
goto P_0c07c024;
P_0c07c024: /* original 2fb6, guest PC 0x0c07c024 */
if(!s->budget--) { s->failed_pc=0x0c07c024u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c026;
P_0c07c026: /* original 2fe6, guest PC 0x0c07c026 */
if(!s->budget--) { s->failed_pc=0x0c07c026u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c028;
P_0c07c028: /* original 950f, guest PC 0x0c07c028 */
if(!s->budget--) { s->failed_pc=0x0c07c028u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04au,2);
goto P_0c07c02a;
P_0c07c02a: /* original 9412, guest PC 0x0c07c02a */
if(!s->budget--) { s->failed_pc=0x0c07c02au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c052u,2);
goto P_0c07c02c;
P_0c07c02c: /* original 480b, guest PC 0x0c07c02c */
if(!s->budget--) { s->failed_pc=0x0c07c02cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c030u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c030u) { target=s->pc; goto dispatch; }
goto P_0c07c030;
P_0c07c02e: /* original 66d3, guest PC 0x0c07c02e */
if(!s->budget--) { s->failed_pc=0x0c07c02eu; return 0; }
r[6]=r[13];
goto P_0c07c030;
P_0c07c030: /* original 6403, guest PC 0x0c07c030 */
if(!s->budget--) { s->failed_pc=0x0c07c030u; return 0; }
r[4]=r[0];
goto P_0c07c032;
P_0c07c032: /* original e030, guest PC 0x0c07c032 */
if(!s->budget--) { s->failed_pc=0x0c07c032u; return 0; }
r[0]=0x00000030u;
goto P_0c07c034;
P_0c07c034: /* original f4f7, guest PC 0x0c07c034 */
if(!s->budget--) { s->failed_pc=0x0c07c034u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c036;
P_0c07c036: /* original e700, guest PC 0x0c07c036 */
if(!s->budget--) { s->failed_pc=0x0c07c036u; return 0; }
r[7]=0x00000000u;
goto P_0c07c038;
P_0c07c038: /* original 2fb6, guest PC 0x0c07c038 */
if(!s->budget--) { s->failed_pc=0x0c07c038u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c03a;
P_0c07c03a: /* original 2fe6, guest PC 0x0c07c03a */
if(!s->budget--) { s->failed_pc=0x0c07c03au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c03c;
P_0c07c03c: /* original 9507, guest PC 0x0c07c03c */
if(!s->budget--) { s->failed_pc=0x0c07c03cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04eu,2);
goto P_0c07c03e;
P_0c07c03e: /* original 9409, guest PC 0x0c07c03e */
if(!s->budget--) { s->failed_pc=0x0c07c03eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c054u,2);
goto P_0c07c040;
P_0c07c040: /* original a00c, guest PC 0x0c07c040 */
if(!s->budget--) { s->failed_pc=0x0c07c040u; return 0; }
r[6]=r[13];
goto P_0c07c05c;
P_0c07c042: /* original 66d3, guest PC 0x0c07c042 */
if(!s->budget--) { s->failed_pc=0x0c07c042u; return 0; }
r[6]=r[13];
if(!vf3_matrix_family(0x0c07c044u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c044u; return 0; } return 1;
P_0c07c05c: /* original 480b, guest PC 0x0c07c05c */
if(!s->budget--) { s->failed_pc=0x0c07c05cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c060u) { target=s->pc; goto dispatch; }
goto P_0c07c060;
P_0c07c05e: /* original 0009, guest PC 0x0c07c05e */
if(!s->budget--) { s->failed_pc=0x0c07c05eu; return 0; }
goto P_0c07c060;
P_0c07c060: /* original 6403, guest PC 0x0c07c060 */
if(!s->budget--) { s->failed_pc=0x0c07c060u; return 0; }
r[4]=r[0];
goto P_0c07c062;
P_0c07c062: /* original e030, guest PC 0x0c07c062 */
if(!s->budget--) { s->failed_pc=0x0c07c062u; return 0; }
r[0]=0x00000030u;
goto P_0c07c064;
P_0c07c064: /* original f4f7, guest PC 0x0c07c064 */
if(!s->budget--) { s->failed_pc=0x0c07c064u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c066;
P_0c07c066: /* original d329, guest PC 0x0c07c066 */
if(!s->budget--) { s->failed_pc=0x0c07c066u; return 0; }
r[3]=read(ram,0x0c07c10cu,4);
goto P_0c07c068;
P_0c07c068: /* original 944c, guest PC 0x0c07c068 */
if(!s->budget--) { s->failed_pc=0x0c07c068u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c104u,2);
goto P_0c07c06a;
P_0c07c06a: /* original 430b, guest PC 0x0c07c06a */
if(!s->budget--) { s->failed_pc=0x0c07c06au; return 0; }
target=r[3];
r[16]=code_base|0x0c07c06eu;
r[15]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c06eu) { target=s->pc; goto dispatch; }
goto P_0c07c06e;
P_0c07c06c: /* original 7f20, guest PC 0x0c07c06c */
if(!s->budget--) { s->failed_pc=0x0c07c06cu; return 0; }
r[15]+=0x00000020u;
goto P_0c07c06e;
P_0c07c06e: /* original 6d03, guest PC 0x0c07c06e */
if(!s->budget--) { s->failed_pc=0x0c07c06eu; return 0; }
r[13]=r[0];
goto P_0c07c070;
P_0c07c070: /* original 52d8, guest PC 0x0c07c070 */
if(!s->budget--) { s->failed_pc=0x0c07c070u; return 0; }
r[2]=read(ram,r[13]+32,4);
goto P_0c07c072;
P_0c07c072: /* original e040, guest PC 0x0c07c072 */
if(!s->budget--) { s->failed_pc=0x0c07c072u; return 0; }
r[0]=0x00000040u;
goto P_0c07c074;
P_0c07c074: /* original 64f3, guest PC 0x0c07c074 */
if(!s->budget--) { s->failed_pc=0x0c07c074u; return 0; }
r[4]=r[15];
goto P_0c07c076;
P_0c07c076: /* original 0f26, guest PC 0x0c07c076 */
if(!s->budget--) { s->failed_pc=0x0c07c076u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07c078;
P_0c07c078: /* original c725, guest PC 0x0c07c078 */
if(!s->budget--) { s->failed_pc=0x0c07c078u; return 0; }
r[0]=code_base|0x0007c110u;
goto P_0c07c07a;
P_0c07c07a: /* original f308, guest PC 0x0c07c07a */
if(!s->budget--) { s->failed_pc=0x0c07c07au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07c07c;
P_0c07c07c: /* original e018, guest PC 0x0c07c07c */
if(!s->budget--) { s->failed_pc=0x0c07c07cu; return 0; }
r[0]=0x00000018u;
goto P_0c07c07e;
P_0c07c07e: /* original f6d6, guest PC 0x0c07c07e */
if(!s->budget--) { s->failed_pc=0x0c07c07eu; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c07c080;
P_0c07c080: /* original c724, guest PC 0x0c07c080 */
if(!s->budget--) { s->failed_pc=0x0c07c080u; return 0; }
r[0]=code_base|0x0007c114u;
goto P_0c07c082;
P_0c07c082: /* original f208, guest PC 0x0c07c082 */
if(!s->budget--) { s->failed_pc=0x0c07c082u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07c084;
P_0c07c084: /* original e01c, guest PC 0x0c07c084 */
if(!s->budget--) { s->failed_pc=0x0c07c084u; return 0; }
r[0]=0x0000001cu;
goto P_0c07c086;
P_0c07c086: /* original f7d6, guest PC 0x0c07c086 */
if(!s->budget--) { s->failed_pc=0x0c07c086u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c07c088;
P_0c07c088: /* original f632, guest PC 0x0c07c088 */
if(!s->budget--) { s->failed_pc=0x0c07c088u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c07c08a;
P_0c07c08a: /* original c723, guest PC 0x0c07c08a */
if(!s->budget--) { s->failed_pc=0x0c07c08au; return 0; }
r[0]=code_base|0x0007c118u;
goto P_0c07c08c;
P_0c07c08c: /* original d323, guest PC 0x0c07c08c */
if(!s->budget--) { s->failed_pc=0x0c07c08cu; return 0; }
r[3]=read(ram,0x0c07c11cu,4);
goto P_0c07c08e;
P_0c07c08e: /* original f722, guest PC 0x0c07c08e */
if(!s->budget--) { s->failed_pc=0x0c07c08eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c07c090;
P_0c07c090: /* original f808, guest PC 0x0c07c090 */
if(!s->budget--) { s->failed_pc=0x0c07c090u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c07c092;
P_0c07c092: /* original f5ec, guest PC 0x0c07c092 */
if(!s->budget--) { s->failed_pc=0x0c07c092u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c07c094;
P_0c07c094: /* original f4ec, guest PC 0x0c07c094 */
if(!s->budget--) { s->failed_pc=0x0c07c094u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07c096;
P_0c07c096: /* original 430b, guest PC 0x0c07c096 */
if(!s->budget--) { s->failed_pc=0x0c07c096u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c09au;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c09au) { target=s->pc; goto dispatch; }
goto P_0c07c09a;
P_0c07c098: /* original 7440, guest PC 0x0c07c098 */
if(!s->budget--) { s->failed_pc=0x0c07c098u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c09a;
P_0c07c09a: /* original e014, guest PC 0x0c07c09a */
if(!s->budget--) { s->failed_pc=0x0c07c09au; return 0; }
r[0]=0x00000014u;
goto P_0c07c09c;
P_0c07c09c: /* original d320, guest PC 0x0c07c09c */
if(!s->budget--) { s->failed_pc=0x0c07c09cu; return 0; }
r[3]=read(ram,0x0c07c120u,4);
goto P_0c07c09e;
P_0c07c09e: /* original f9d6, guest PC 0x0c07c09e */
if(!s->budget--) { s->failed_pc=0x0c07c09eu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c07c0a0;
P_0c07c0a0: /* original e010, guest PC 0x0c07c0a0 */
if(!s->budget--) { s->failed_pc=0x0c07c0a0u; return 0; }
r[0]=0x00000010u;
goto P_0c07c0a2;
P_0c07c0a2: /* original f8d6, guest PC 0x0c07c0a2 */
if(!s->budget--) { s->failed_pc=0x0c07c0a2u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c07c0a4;
P_0c07c0a4: /* original e00c, guest PC 0x0c07c0a4 */
if(!s->budget--) { s->failed_pc=0x0c07c0a4u; return 0; }
r[0]=0x0000000cu;
goto P_0c07c0a6;
P_0c07c0a6: /* original f7d6, guest PC 0x0c07c0a6 */
if(!s->budget--) { s->failed_pc=0x0c07c0a6u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c07c0a8;
P_0c07c0a8: /* original e008, guest PC 0x0c07c0a8 */
if(!s->budget--) { s->failed_pc=0x0c07c0a8u; return 0; }
r[0]=0x00000008u;
goto P_0c07c0aa;
P_0c07c0aa: /* original f6d6, guest PC 0x0c07c0aa */
if(!s->budget--) { s->failed_pc=0x0c07c0aau; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c07c0ac;
P_0c07c0ac: /* original e004, guest PC 0x0c07c0ac */
if(!s->budget--) { s->failed_pc=0x0c07c0acu; return 0; }
r[0]=0x00000004u;
goto P_0c07c0ae;
P_0c07c0ae: /* original f4d8, guest PC 0x0c07c0ae */
if(!s->budget--) { s->failed_pc=0x0c07c0aeu; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c07c0b0;
P_0c07c0b0: /* original 64f3, guest PC 0x0c07c0b0 */
if(!s->budget--) { s->failed_pc=0x0c07c0b0u; return 0; }
r[4]=r[15];
goto P_0c07c0b2;
P_0c07c0b2: /* original f5d6, guest PC 0x0c07c0b2 */
if(!s->budget--) { s->failed_pc=0x0c07c0b2u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c07c0b4;
P_0c07c0b4: /* original 430b, guest PC 0x0c07c0b4 */
if(!s->budget--) { s->failed_pc=0x0c07c0b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c0b8u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c0b8u) { target=s->pc; goto dispatch; }
goto P_0c07c0b8;
P_0c07c0b6: /* original 7440, guest PC 0x0c07c0b6 */
if(!s->budget--) { s->failed_pc=0x0c07c0b6u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c0b8;
P_0c07c0b8: /* original e068, guest PC 0x0c07c0b8 */
if(!s->budget--) { s->failed_pc=0x0c07c0b8u; return 0; }
r[0]=0x00000068u;
goto P_0c07c0ba;
P_0c07c0ba: /* original 64f3, guest PC 0x0c07c0ba */
if(!s->budget--) { s->failed_pc=0x0c07c0bau; return 0; }
r[4]=r[15];
goto P_0c07c0bc;
P_0c07c0bc: /* original 0fe6, guest PC 0x0c07c0bc */
if(!s->budget--) { s->failed_pc=0x0c07c0bcu; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c07c0be;
P_0c07c0be: /* original e06c, guest PC 0x0c07c0be */
if(!s->budget--) { s->failed_pc=0x0c07c0beu; return 0; }
r[0]=0x0000006cu;
goto P_0c07c0c0;
P_0c07c0c0: /* original 9321, guest PC 0x0c07c0c0 */
if(!s->budget--) { s->failed_pc=0x0c07c0c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c106u,2);
goto P_0c07c0c2;
P_0c07c0c2: /* original 0f36, guest PC 0x0c07c0c2 */
if(!s->budget--) { s->failed_pc=0x0c07c0c2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07c0c4;
P_0c07c0c4: /* original c717, guest PC 0x0c07c0c4 */
if(!s->budget--) { s->failed_pc=0x0c07c0c4u; return 0; }
r[0]=code_base|0x0007c124u;
goto P_0c07c0c6;
P_0c07c0c6: /* original f308, guest PC 0x0c07c0c6 */
if(!s->budget--) { s->failed_pc=0x0c07c0c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07c0c8;
P_0c07c0c8: /* original e070, guest PC 0x0c07c0c8 */
if(!s->budget--) { s->failed_pc=0x0c07c0c8u; return 0; }
r[0]=0x00000070u;
goto P_0c07c0ca;
P_0c07c0ca: /* original ff37, guest PC 0x0c07c0ca */
if(!s->budget--) { s->failed_pc=0x0c07c0cau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c07c0cc;
P_0c07c0cc: /* original d316, guest PC 0x0c07c0cc */
if(!s->budget--) { s->failed_pc=0x0c07c0ccu; return 0; }
r[3]=read(ram,0x0c07c128u,4);
goto P_0c07c0ce;
P_0c07c0ce: /* original 430b, guest PC 0x0c07c0ce */
if(!s->budget--) { s->failed_pc=0x0c07c0ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c0d2u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c0d2u) { target=s->pc; goto dispatch; }
goto P_0c07c0d2;
P_0c07c0d0: /* original 7440, guest PC 0x0c07c0d0 */
if(!s->budget--) { s->failed_pc=0x0c07c0d0u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c0d2;
P_0c07c0d2: /* original a0eb, guest PC 0x0c07c0d2 */
if(!s->budget--) { s->failed_pc=0x0c07c0d2u; return 0; }
goto P_0c07c2ac;
P_0c07c0d4: /* original 0009, guest PC 0x0c07c0d4 */
if(!s->budget--) { s->failed_pc=0x0c07c0d4u; return 0; }
goto P_0c07c0d6;
P_0c07c0d6: /* original a0ba, guest PC 0x0c07c0d6 */
if(!s->budget--) { s->failed_pc=0x0c07c0d6u; return 0; }
write(ram,r[15]+36,r[14],4);
goto P_0c07c24e;
P_0c07c0d8: /* original 1fe9, guest PC 0x0c07c0d8 */
if(!s->budget--) { s->failed_pc=0x0c07c0d8u; return 0; }
write(ram,r[15]+36,r[14],4);
goto P_0c07c0da;
P_0c07c0da: /* original e122, guest PC 0x0c07c0da */
if(!s->budget--) { s->failed_pc=0x0c07c0dau; return 0; }
r[1]=0x00000022u;
goto P_0c07c0dc;
P_0c07c0dc: /* original 1fe2, guest PC 0x0c07c0dc */
if(!s->budget--) { s->failed_pc=0x0c07c0dcu; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c07c0de;
P_0c07c0de: /* original 53f9, guest PC 0x0c07c0de */
if(!s->budget--) { s->failed_pc=0x0c07c0deu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07c0e0;
P_0c07c0e0: /* original e007, guest PC 0x0c07c0e0 */
if(!s->budget--) { s->failed_pc=0x0c07c0e0u; return 0; }
r[0]=0x00000007u;
goto P_0c07c0e2;
P_0c07c0e2: /* original 4308, guest PC 0x0c07c0e2 */
if(!s->budget--) { s->failed_pc=0x0c07c0e2u; return 0; }
r[3]<<=2;
goto P_0c07c0e4;
P_0c07c0e4: /* original 4300, guest PC 0x0c07c0e4 */
if(!s->budget--) { s->failed_pc=0x0c07c0e4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07c0e6;
P_0c07c0e6: /* original 2f32, guest PC 0x0c07c0e6 */
if(!s->budget--) { s->failed_pc=0x0c07c0e6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07c0e8;
P_0c07c0e8: /* original 920e, guest PC 0x0c07c0e8 */
if(!s->budget--) { s->failed_pc=0x0c07c0e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c108u,2);
goto P_0c07c0ea;
P_0c07c0ea: /* original 32fc, guest PC 0x0c07c0ea */
if(!s->budget--) { s->failed_pc=0x0c07c0eau; return 0; }
r[2]+=r[15];
goto P_0c07c0ec;
P_0c07c0ec: /* original 332c, guest PC 0x0c07c0ec */
if(!s->budget--) { s->failed_pc=0x0c07c0ecu; return 0; }
r[3]+=r[2];
goto P_0c07c0ee;
P_0c07c0ee: /* original 1f34, guest PC 0x0c07c0ee */
if(!s->budget--) { s->failed_pc=0x0c07c0eeu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07c0f0;
P_0c07c0f0: /* original 1f3b, guest PC 0x0c07c0f0 */
if(!s->budget--) { s->failed_pc=0x0c07c0f0u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c07c0f2;
P_0c07c0f2: /* original 1f13, guest PC 0x0c07c0f2 */
if(!s->budget--) { s->failed_pc=0x0c07c0f2u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07c0f4;
P_0c07c0f4: /* original e11e, guest PC 0x0c07c0f4 */
if(!s->budget--) { s->failed_pc=0x0c07c0f4u; return 0; }
r[1]=0x0000001eu;
goto P_0c07c0f6;
P_0c07c0f6: /* original 1f18, guest PC 0x0c07c0f6 */
if(!s->budget--) { s->failed_pc=0x0c07c0f6u; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c07c0f8;
P_0c07c0f8: /* original 51f9, guest PC 0x0c07c0f8 */
if(!s->budget--) { s->failed_pc=0x0c07c0f8u; return 0; }
r[1]=read(ram,r[15]+36,4);
goto P_0c07c0fa;
P_0c07c0fa: /* original 4100, guest PC 0x0c07c0fa */
if(!s->budget--) { s->failed_pc=0x0c07c0fau; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07c0fc;
P_0c07c0fc: /* original 7102, guest PC 0x0c07c0fc */
if(!s->budget--) { s->failed_pc=0x0c07c0fcu; return 0; }
r[1]+=0x00000002u;
goto P_0c07c0fe;
P_0c07c0fe: /* original 410c, guest PC 0x0c07c0fe */
if(!s->budget--) { s->failed_pc=0x0c07c0feu; return 0; }
r[1]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[1]>>((-r[0])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[0]&31u);
goto P_0c07c100;
P_0c07c100: /* original a09c, guest PC 0x0c07c100 */
if(!s->budget--) { s->failed_pc=0x0c07c100u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c07c23c;
P_0c07c102: /* original 1f11, guest PC 0x0c07c102 */
if(!s->budget--) { s->failed_pc=0x0c07c102u; return 0; }
write(ram,r[15]+4,r[1],4);
if(!vf3_matrix_family(0x0c07c104u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c104u; return 0; } return 1;
P_0c07c12c: /* original 5cf2, guest PC 0x0c07c12c */
if(!s->budget--) { s->failed_pc=0x0c07c12cu; return 0; }
r[12]=read(ram,r[15]+8,4);
goto P_0c07c12e;
P_0c07c12e: /* original 50f4, guest PC 0x0c07c12e */
if(!s->budget--) { s->failed_pc=0x0c07c12eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07c130;
P_0c07c130: /* original 4c08, guest PC 0x0c07c130 */
if(!s->budget--) { s->failed_pc=0x0c07c130u; return 0; }
r[12]<<=2;
goto P_0c07c132;
P_0c07c132: /* original 03ce, guest PC 0x0c07c132 */
if(!s->budget--) { s->failed_pc=0x0c07c132u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c07c134;
P_0c07c134: /* original 33a3, guest PC 0x0c07c134 */
if(!s->budget--) { s->failed_pc=0x0c07c134u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c07c136;
P_0c07c136: /* original 8b31, guest PC 0x0c07c136 */
if(!s->budget--) { s->failed_pc=0x0c07c136u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c19c; }
goto P_0c07c138;
P_0c07c138: /* original 93bd, guest PC 0x0c07c138 */
if(!s->budget--) { s->failed_pc=0x0c07c138u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b6u,2);
goto P_0c07c13a;
P_0c07c13a: /* original 62f2, guest PC 0x0c07c13a */
if(!s->budget--) { s->failed_pc=0x0c07c13au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07c13c;
P_0c07c13c: /* original 33fc, guest PC 0x0c07c13c */
if(!s->budget--) { s->failed_pc=0x0c07c13cu; return 0; }
r[3]+=r[15];
goto P_0c07c13e;
P_0c07c13e: /* original 323c, guest PC 0x0c07c13e */
if(!s->budget--) { s->failed_pc=0x0c07c13eu; return 0; }
r[2]+=r[3];
goto P_0c07c140;
P_0c07c140: /* original 32cc, guest PC 0x0c07c140 */
if(!s->budget--) { s->failed_pc=0x0c07c140u; return 0; }
r[2]+=r[12];
goto P_0c07c142;
P_0c07c142: /* original 1f27, guest PC 0x0c07c142 */
if(!s->budget--) { s->failed_pc=0x0c07c142u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07c144;
P_0c07c144: /* original 90b8, guest PC 0x0c07c144 */
if(!s->budget--) { s->failed_pc=0x0c07c144u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b8u,2);
goto P_0c07c146;
P_0c07c146: /* original 61f2, guest PC 0x0c07c146 */
if(!s->budget--) { s->failed_pc=0x0c07c146u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07c148;
P_0c07c148: /* original 30fc, guest PC 0x0c07c148 */
if(!s->budget--) { s->failed_pc=0x0c07c148u; return 0; }
r[0]+=r[15];
goto P_0c07c14a;
P_0c07c14a: /* original 310c, guest PC 0x0c07c14a */
if(!s->budget--) { s->failed_pc=0x0c07c14au; return 0; }
r[1]+=r[0];
goto P_0c07c14c;
P_0c07c14c: /* original 31cc, guest PC 0x0c07c14c */
if(!s->budget--) { s->failed_pc=0x0c07c14cu; return 0; }
r[1]+=r[12];
goto P_0c07c14e;
P_0c07c14e: /* original 1f1a, guest PC 0x0c07c14e */
if(!s->budget--) { s->failed_pc=0x0c07c14eu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c07c150;
P_0c07c150: /* original 6112, guest PC 0x0c07c150 */
if(!s->budget--) { s->failed_pc=0x0c07c150u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07c152;
P_0c07c152: /* original d35d, guest PC 0x0c07c152 */
if(!s->budget--) { s->failed_pc=0x0c07c152u; return 0; }
r[3]=read(ram,0x0c07c2c8u,4);
goto P_0c07c154;
P_0c07c154: /* original 430b, guest PC 0x0c07c154 */
if(!s->budget--) { s->failed_pc=0x0c07c154u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c158u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c158u) { target=s->pc; goto dispatch; }
goto P_0c07c158;
P_0c07c156: /* original 60a3, guest PC 0x0c07c156 */
if(!s->budget--) { s->failed_pc=0x0c07c156u; return 0; }
r[0]=r[10];
goto P_0c07c158;
P_0c07c158: /* original 2202, guest PC 0x0c07c158 */
if(!s->budget--) { s->failed_pc=0x0c07c158u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07c15a;
P_0c07c15a: /* original e700, guest PC 0x0c07c15a */
if(!s->budget--) { s->failed_pc=0x0c07c15au; return 0; }
r[7]=0x00000000u;
goto P_0c07c15c;
P_0c07c15c: /* original 52f2, guest PC 0x0c07c15c */
if(!s->budget--) { s->failed_pc=0x0c07c15cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07c15e;
P_0c07c15e: /* original 66d3, guest PC 0x0c07c15e */
if(!s->budget--) { s->failed_pc=0x0c07c15eu; return 0; }
r[6]=r[13];
goto P_0c07c160;
P_0c07c160: /* original 6323, guest PC 0x0c07c160 */
if(!s->budget--) { s->failed_pc=0x0c07c160u; return 0; }
r[3]=r[2];
goto P_0c07c162;
P_0c07c162: /* original 4208, guest PC 0x0c07c162 */
if(!s->budget--) { s->failed_pc=0x0c07c162u; return 0; }
r[2]<<=2;
goto P_0c07c164;
P_0c07c164: /* original 323c, guest PC 0x0c07c164 */
if(!s->budget--) { s->failed_pc=0x0c07c164u; return 0; }
r[2]+=r[3];
goto P_0c07c166;
P_0c07c166: /* original 53f1, guest PC 0x0c07c166 */
if(!s->budget--) { s->failed_pc=0x0c07c166u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07c168;
P_0c07c168: /* original 4208, guest PC 0x0c07c168 */
if(!s->budget--) { s->failed_pc=0x0c07c168u; return 0; }
r[2]<<=2;
goto P_0c07c16a;
P_0c07c16a: /* original 4200, guest PC 0x0c07c16a */
if(!s->budget--) { s->failed_pc=0x0c07c16au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c16c;
P_0c07c16c: /* original 720d, guest PC 0x0c07c16c */
if(!s->budget--) { s->failed_pc=0x0c07c16cu; return 0; }
r[2]+=0x0000000du;
goto P_0c07c16e;
P_0c07c16e: /* original 4200, guest PC 0x0c07c16e */
if(!s->budget--) { s->failed_pc=0x0c07c16eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c170;
P_0c07c170: /* original 223b, guest PC 0x0c07c170 */
if(!s->budget--) { s->failed_pc=0x0c07c170u; return 0; }
r[2]|=r[3];
goto P_0c07c172;
P_0c07c172: /* original 1f25, guest PC 0x0c07c172 */
if(!s->budget--) { s->failed_pc=0x0c07c172u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07c174;
P_0c07c174: /* original 2fb6, guest PC 0x0c07c174 */
if(!s->budget--) { s->failed_pc=0x0c07c174u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c176;
P_0c07c176: /* original 2fe6, guest PC 0x0c07c176 */
if(!s->budget--) { s->failed_pc=0x0c07c176u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c178;
P_0c07c178: /* original 50f9, guest PC 0x0c07c178 */
if(!s->budget--) { s->failed_pc=0x0c07c178u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c07c17a;
P_0c07c17a: /* original 6002, guest PC 0x0c07c17a */
if(!s->budget--) { s->failed_pc=0x0c07c17au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c17c;
P_0c07c17c: /* original 4008, guest PC 0x0c07c17c */
if(!s->budget--) { s->failed_pc=0x0c07c17cu; return 0; }
r[0]<<=2;
goto P_0c07c17e;
P_0c07c17e: /* original 059e, guest PC 0x0c07c17e */
if(!s->budget--) { s->failed_pc=0x0c07c17eu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c180;
P_0c07c180: /* original 480b, guest PC 0x0c07c180 */
if(!s->budget--) { s->failed_pc=0x0c07c180u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c184u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c184u) { target=s->pc; goto dispatch; }
goto P_0c07c184;
P_0c07c182: /* original 6423, guest PC 0x0c07c182 */
if(!s->budget--) { s->failed_pc=0x0c07c182u; return 0; }
r[4]=r[2];
goto P_0c07c184;
P_0c07c184: /* original 7f08, guest PC 0x0c07c184 */
if(!s->budget--) { s->failed_pc=0x0c07c184u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c186;
P_0c07c186: /* original 6403, guest PC 0x0c07c186 */
if(!s->budget--) { s->failed_pc=0x0c07c186u; return 0; }
r[4]=r[0];
goto P_0c07c188;
P_0c07c188: /* original e030, guest PC 0x0c07c188 */
if(!s->budget--) { s->failed_pc=0x0c07c188u; return 0; }
r[0]=0x00000030u;
goto P_0c07c18a;
P_0c07c18a: /* original f4e7, guest PC 0x0c07c18a */
if(!s->budget--) { s->failed_pc=0x0c07c18au; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c18c;
P_0c07c18c: /* original 52f7, guest PC 0x0c07c18c */
if(!s->budget--) { s->failed_pc=0x0c07c18cu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07c18e;
P_0c07c18e: /* original 53fa, guest PC 0x0c07c18e */
if(!s->budget--) { s->failed_pc=0x0c07c18eu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c07c190;
P_0c07c190: /* original 6122, guest PC 0x0c07c190 */
if(!s->budget--) { s->failed_pc=0x0c07c190u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07c192;
P_0c07c192: /* original 6232, guest PC 0x0c07c192 */
if(!s->budget--) { s->failed_pc=0x0c07c192u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07c194;
P_0c07c194: /* original 01a7, guest PC 0x0c07c194 */
if(!s->budget--) { s->failed_pc=0x0c07c194u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07c196;
P_0c07c196: /* original 011a, guest PC 0x0c07c196 */
if(!s->budget--) { s->failed_pc=0x0c07c196u; return 0; }
r[1]=r[19];
goto P_0c07c198;
P_0c07c198: /* original 3218, guest PC 0x0c07c198 */
if(!s->budget--) { s->failed_pc=0x0c07c198u; return 0; }
r[2]-=r[1];
goto P_0c07c19a;
P_0c07c19a: /* original 2322, guest PC 0x0c07c19a */
if(!s->budget--) { s->failed_pc=0x0c07c19au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c19c;
P_0c07c19c: /* original 50f4, guest PC 0x0c07c19c */
if(!s->budget--) { s->failed_pc=0x0c07c19cu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07c19e;
P_0c07c19e: /* original e20a, guest PC 0x0c07c19e */
if(!s->budget--) { s->failed_pc=0x0c07c19eu; return 0; }
r[2]=0x0000000au;
goto P_0c07c1a0;
P_0c07c1a0: /* original 03ce, guest PC 0x0c07c1a0 */
if(!s->budget--) { s->failed_pc=0x0c07c1a0u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c07c1a2;
P_0c07c1a2: /* original 3323, guest PC 0x0c07c1a2 */
if(!s->budget--) { s->failed_pc=0x0c07c1a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07c1a4;
P_0c07c1a4: /* original 8b2d, guest PC 0x0c07c1a4 */
if(!s->budget--) { s->failed_pc=0x0c07c1a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c202; }
goto P_0c07c1a6;
P_0c07c1a6: /* original 9386, guest PC 0x0c07c1a6 */
if(!s->budget--) { s->failed_pc=0x0c07c1a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b6u,2);
goto P_0c07c1a8;
P_0c07c1a8: /* original 61f2, guest PC 0x0c07c1a8 */
if(!s->budget--) { s->failed_pc=0x0c07c1a8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07c1aa;
P_0c07c1aa: /* original 33fc, guest PC 0x0c07c1aa */
if(!s->budget--) { s->failed_pc=0x0c07c1aau; return 0; }
r[3]+=r[15];
goto P_0c07c1ac;
P_0c07c1ac: /* original 313c, guest PC 0x0c07c1ac */
if(!s->budget--) { s->failed_pc=0x0c07c1acu; return 0; }
r[1]+=r[3];
goto P_0c07c1ae;
P_0c07c1ae: /* original 31cc, guest PC 0x0c07c1ae */
if(!s->budget--) { s->failed_pc=0x0c07c1aeu; return 0; }
r[1]+=r[12];
goto P_0c07c1b0;
P_0c07c1b0: /* original 1f17, guest PC 0x0c07c1b0 */
if(!s->budget--) { s->failed_pc=0x0c07c1b0u; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07c1b2;
P_0c07c1b2: /* original 2f16, guest PC 0x0c07c1b2 */
if(!s->budget--) { s->failed_pc=0x0c07c1b2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1b4;
P_0c07c1b4: /* original 9281, guest PC 0x0c07c1b4 */
if(!s->budget--) { s->failed_pc=0x0c07c1b4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bau,2);
goto P_0c07c1b6;
P_0c07c1b6: /* original 51f1, guest PC 0x0c07c1b6 */
if(!s->budget--) { s->failed_pc=0x0c07c1b6u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07c1b8;
P_0c07c1b8: /* original 32fc, guest PC 0x0c07c1b8 */
if(!s->budget--) { s->failed_pc=0x0c07c1b8u; return 0; }
r[2]+=r[15];
goto P_0c07c1ba;
P_0c07c1ba: /* original 312c, guest PC 0x0c07c1ba */
if(!s->budget--) { s->failed_pc=0x0c07c1bau; return 0; }
r[1]+=r[2];
goto P_0c07c1bc;
P_0c07c1bc: /* original 31cc, guest PC 0x0c07c1bc */
if(!s->budget--) { s->failed_pc=0x0c07c1bcu; return 0; }
r[1]+=r[12];
goto P_0c07c1be;
P_0c07c1be: /* original 1f1b, guest PC 0x0c07c1be */
if(!s->budget--) { s->failed_pc=0x0c07c1beu; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c07c1c0;
P_0c07c1c0: /* original d341, guest PC 0x0c07c1c0 */
if(!s->budget--) { s->failed_pc=0x0c07c1c0u; return 0; }
r[3]=read(ram,0x0c07c2c8u,4);
goto P_0c07c1c2;
P_0c07c1c2: /* original 6112, guest PC 0x0c07c1c2 */
if(!s->budget--) { s->failed_pc=0x0c07c1c2u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07c1c4;
P_0c07c1c4: /* original 430b, guest PC 0x0c07c1c4 */
if(!s->budget--) { s->failed_pc=0x0c07c1c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c1c8u;
r[0]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c1c8u) { target=s->pc; goto dispatch; }
goto P_0c07c1c8;
P_0c07c1c6: /* original e00a, guest PC 0x0c07c1c6 */
if(!s->budget--) { s->failed_pc=0x0c07c1c6u; return 0; }
r[0]=0x0000000au;
goto P_0c07c1c8;
P_0c07c1c8: /* original 63f6, guest PC 0x0c07c1c8 */
if(!s->budget--) { s->failed_pc=0x0c07c1c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c07c1ca;
P_0c07c1ca: /* original e700, guest PC 0x0c07c1ca */
if(!s->budget--) { s->failed_pc=0x0c07c1cau; return 0; }
r[7]=0x00000000u;
goto P_0c07c1cc;
P_0c07c1cc: /* original 66d3, guest PC 0x0c07c1cc */
if(!s->budget--) { s->failed_pc=0x0c07c1ccu; return 0; }
r[6]=r[13];
goto P_0c07c1ce;
P_0c07c1ce: /* original 2302, guest PC 0x0c07c1ce */
if(!s->budget--) { s->failed_pc=0x0c07c1ceu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07c1d0;
P_0c07c1d0: /* original 5cf1, guest PC 0x0c07c1d0 */
if(!s->budget--) { s->failed_pc=0x0c07c1d0u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07c1d2;
P_0c07c1d2: /* original 53f8, guest PC 0x0c07c1d2 */
if(!s->budget--) { s->failed_pc=0x0c07c1d2u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07c1d4;
P_0c07c1d4: /* original 2fb6, guest PC 0x0c07c1d4 */
if(!s->budget--) { s->failed_pc=0x0c07c1d4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1d6;
P_0c07c1d6: /* original 2fe6, guest PC 0x0c07c1d6 */
if(!s->budget--) { s->failed_pc=0x0c07c1d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1d8;
P_0c07c1d8: /* original 2c3b, guest PC 0x0c07c1d8 */
if(!s->budget--) { s->failed_pc=0x0c07c1d8u; return 0; }
r[12]|=r[3];
goto P_0c07c1da;
P_0c07c1da: /* original 50f9, guest PC 0x0c07c1da */
if(!s->budget--) { s->failed_pc=0x0c07c1dau; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c07c1dc;
P_0c07c1dc: /* original 6002, guest PC 0x0c07c1dc */
if(!s->budget--) { s->failed_pc=0x0c07c1dcu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c1de;
P_0c07c1de: /* original 4008, guest PC 0x0c07c1de */
if(!s->budget--) { s->failed_pc=0x0c07c1deu; return 0; }
r[0]<<=2;
goto P_0c07c1e0;
P_0c07c1e0: /* original 059e, guest PC 0x0c07c1e0 */
if(!s->budget--) { s->failed_pc=0x0c07c1e0u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c1e2;
P_0c07c1e2: /* original 480b, guest PC 0x0c07c1e2 */
if(!s->budget--) { s->failed_pc=0x0c07c1e2u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c1e6u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c1e6u) { target=s->pc; goto dispatch; }
goto P_0c07c1e6;
P_0c07c1e4: /* original 64c3, guest PC 0x0c07c1e4 */
if(!s->budget--) { s->failed_pc=0x0c07c1e4u; return 0; }
r[4]=r[12];
goto P_0c07c1e6;
P_0c07c1e6: /* original 7f08, guest PC 0x0c07c1e6 */
if(!s->budget--) { s->failed_pc=0x0c07c1e6u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c1e8;
P_0c07c1e8: /* original 6403, guest PC 0x0c07c1e8 */
if(!s->budget--) { s->failed_pc=0x0c07c1e8u; return 0; }
r[4]=r[0];
goto P_0c07c1ea;
P_0c07c1ea: /* original e030, guest PC 0x0c07c1ea */
if(!s->budget--) { s->failed_pc=0x0c07c1eau; return 0; }
r[0]=0x00000030u;
goto P_0c07c1ec;
P_0c07c1ec: /* original f4e7, guest PC 0x0c07c1ec */
if(!s->budget--) { s->failed_pc=0x0c07c1ecu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c1ee;
P_0c07c1ee: /* original 52f7, guest PC 0x0c07c1ee */
if(!s->budget--) { s->failed_pc=0x0c07c1eeu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07c1f0;
P_0c07c1f0: /* original 53fa, guest PC 0x0c07c1f0 */
if(!s->budget--) { s->failed_pc=0x0c07c1f0u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c07c1f2;
P_0c07c1f2: /* original 6222, guest PC 0x0c07c1f2 */
if(!s->budget--) { s->failed_pc=0x0c07c1f2u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07c1f4;
P_0c07c1f4: /* original 6032, guest PC 0x0c07c1f4 */
if(!s->budget--) { s->failed_pc=0x0c07c1f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07c1f6;
P_0c07c1f6: /* original 6123, guest PC 0x0c07c1f6 */
if(!s->budget--) { s->failed_pc=0x0c07c1f6u; return 0; }
r[1]=r[2];
goto P_0c07c1f8;
P_0c07c1f8: /* original 4208, guest PC 0x0c07c1f8 */
if(!s->budget--) { s->failed_pc=0x0c07c1f8u; return 0; }
r[2]<<=2;
goto P_0c07c1fa;
P_0c07c1fa: /* original 321c, guest PC 0x0c07c1fa */
if(!s->budget--) { s->failed_pc=0x0c07c1fau; return 0; }
r[2]+=r[1];
goto P_0c07c1fc;
P_0c07c1fc: /* original 4200, guest PC 0x0c07c1fc */
if(!s->budget--) { s->failed_pc=0x0c07c1fcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c1fe;
P_0c07c1fe: /* original 3028, guest PC 0x0c07c1fe */
if(!s->budget--) { s->failed_pc=0x0c07c1feu; return 0; }
r[0]-=r[2];
goto P_0c07c200;
P_0c07c200: /* original 2302, guest PC 0x0c07c200 */
if(!s->budget--) { s->failed_pc=0x0c07c200u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07c202;
P_0c07c202: /* original 5cf1, guest PC 0x0c07c202 */
if(!s->budget--) { s->failed_pc=0x0c07c202u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07c204;
P_0c07c204: /* original e700, guest PC 0x0c07c204 */
if(!s->budget--) { s->failed_pc=0x0c07c204u; return 0; }
r[7]=0x00000000u;
goto P_0c07c206;
P_0c07c206: /* original 53f3, guest PC 0x0c07c206 */
if(!s->budget--) { s->failed_pc=0x0c07c206u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c07c208;
P_0c07c208: /* original 66d3, guest PC 0x0c07c208 */
if(!s->budget--) { s->failed_pc=0x0c07c208u; return 0; }
r[6]=r[13];
goto P_0c07c20a;
P_0c07c20a: /* original 2fb6, guest PC 0x0c07c20a */
if(!s->budget--) { s->failed_pc=0x0c07c20au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c20c;
P_0c07c20c: /* original 2fe6, guest PC 0x0c07c20c */
if(!s->budget--) { s->failed_pc=0x0c07c20cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c20e;
P_0c07c20e: /* original 2c3b, guest PC 0x0c07c20e */
if(!s->budget--) { s->failed_pc=0x0c07c20eu; return 0; }
r[12]|=r[3];
goto P_0c07c210;
P_0c07c210: /* original 50fd, guest PC 0x0c07c210 */
if(!s->budget--) { s->failed_pc=0x0c07c210u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07c212;
P_0c07c212: /* original 6002, guest PC 0x0c07c212 */
if(!s->budget--) { s->failed_pc=0x0c07c212u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c214;
P_0c07c214: /* original 4008, guest PC 0x0c07c214 */
if(!s->budget--) { s->failed_pc=0x0c07c214u; return 0; }
r[0]<<=2;
goto P_0c07c216;
P_0c07c216: /* original 059e, guest PC 0x0c07c216 */
if(!s->budget--) { s->failed_pc=0x0c07c216u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c218;
P_0c07c218: /* original 480b, guest PC 0x0c07c218 */
if(!s->budget--) { s->failed_pc=0x0c07c218u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c21cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c21cu) { target=s->pc; goto dispatch; }
goto P_0c07c21c;
P_0c07c21a: /* original 64c3, guest PC 0x0c07c21a */
if(!s->budget--) { s->failed_pc=0x0c07c21au; return 0; }
r[4]=r[12];
goto P_0c07c21c;
P_0c07c21c: /* original 7f08, guest PC 0x0c07c21c */
if(!s->budget--) { s->failed_pc=0x0c07c21cu; return 0; }
r[15]+=0x00000008u;
goto P_0c07c21e;
P_0c07c21e: /* original 6403, guest PC 0x0c07c21e */
if(!s->budget--) { s->failed_pc=0x0c07c21eu; return 0; }
r[4]=r[0];
goto P_0c07c220;
P_0c07c220: /* original e030, guest PC 0x0c07c220 */
if(!s->budget--) { s->failed_pc=0x0c07c220u; return 0; }
r[0]=0x00000030u;
goto P_0c07c222;
P_0c07c222: /* original f4e7, guest PC 0x0c07c222 */
if(!s->budget--) { s->failed_pc=0x0c07c222u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c224;
P_0c07c224: /* original 53f2, guest PC 0x0c07c224 */
if(!s->budget--) { s->failed_pc=0x0c07c224u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07c226;
P_0c07c226: /* original 7301, guest PC 0x0c07c226 */
if(!s->budget--) { s->failed_pc=0x0c07c226u; return 0; }
r[3]+=0x00000001u;
goto P_0c07c228;
P_0c07c228: /* original 1f32, guest PC 0x0c07c228 */
if(!s->budget--) { s->failed_pc=0x0c07c228u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07c22a;
P_0c07c22a: /* original 52fb, guest PC 0x0c07c22a */
if(!s->budget--) { s->failed_pc=0x0c07c22au; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c07c22c;
P_0c07c22c: /* original 7204, guest PC 0x0c07c22c */
if(!s->budget--) { s->failed_pc=0x0c07c22cu; return 0; }
r[2]+=0x00000004u;
goto P_0c07c22e;
P_0c07c22e: /* original 1f2b, guest PC 0x0c07c22e */
if(!s->budget--) { s->failed_pc=0x0c07c22eu; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c07c230;
P_0c07c230: /* original 51f3, guest PC 0x0c07c230 */
if(!s->budget--) { s->failed_pc=0x0c07c230u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07c232;
P_0c07c232: /* original 7150, guest PC 0x0c07c232 */
if(!s->budget--) { s->failed_pc=0x0c07c232u; return 0; }
r[1]+=0x00000050u;
goto P_0c07c234;
P_0c07c234: /* original 1f13, guest PC 0x0c07c234 */
if(!s->budget--) { s->failed_pc=0x0c07c234u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07c236;
P_0c07c236: /* original 53f8, guest PC 0x0c07c236 */
if(!s->budget--) { s->failed_pc=0x0c07c236u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07c238;
P_0c07c238: /* original 7350, guest PC 0x0c07c238 */
if(!s->budget--) { s->failed_pc=0x0c07c238u; return 0; }
r[3]+=0x00000050u;
goto P_0c07c23a;
P_0c07c23a: /* original 1f38, guest PC 0x0c07c23a */
if(!s->budget--) { s->failed_pc=0x0c07c23au; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c07c23c;
P_0c07c23c: /* original 51f2, guest PC 0x0c07c23c */
if(!s->budget--) { s->failed_pc=0x0c07c23cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07c23e;
P_0c07c23e: /* original e202, guest PC 0x0c07c23e */
if(!s->budget--) { s->failed_pc=0x0c07c23eu; return 0; }
r[2]=0x00000002u;
goto P_0c07c240;
P_0c07c240: /* original 3123, guest PC 0x0c07c240 */
if(!s->budget--) { s->failed_pc=0x0c07c240u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07c242;
P_0c07c242: /* original 8901, guest PC 0x0c07c242 */
if(!s->budget--) { s->failed_pc=0x0c07c242u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c248; }
goto P_0c07c244;
P_0c07c244: /* original af72, guest PC 0x0c07c244 */
if(!s->budget--) { s->failed_pc=0x0c07c244u; return 0; }
goto P_0c07c12c;
P_0c07c246: /* original 0009, guest PC 0x0c07c246 */
if(!s->budget--) { s->failed_pc=0x0c07c246u; return 0; }
goto P_0c07c248;
P_0c07c248: /* original 53f9, guest PC 0x0c07c248 */
if(!s->budget--) { s->failed_pc=0x0c07c248u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07c24a;
P_0c07c24a: /* original 7301, guest PC 0x0c07c24a */
if(!s->budget--) { s->failed_pc=0x0c07c24au; return 0; }
r[3]+=0x00000001u;
goto P_0c07c24c;
P_0c07c24c: /* original 1f39, guest PC 0x0c07c24c */
if(!s->budget--) { s->failed_pc=0x0c07c24cu; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07c24e;
P_0c07c24e: /* original 51f9, guest PC 0x0c07c24e */
if(!s->budget--) { s->failed_pc=0x0c07c24eu; return 0; }
r[1]=read(ram,r[15]+36,4);
goto P_0c07c250;
P_0c07c250: /* original e202, guest PC 0x0c07c250 */
if(!s->budget--) { s->failed_pc=0x0c07c250u; return 0; }
r[2]=0x00000002u;
goto P_0c07c252;
P_0c07c252: /* original 3123, guest PC 0x0c07c252 */
if(!s->budget--) { s->failed_pc=0x0c07c252u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07c254;
P_0c07c254: /* original 8901, guest PC 0x0c07c254 */
if(!s->budget--) { s->failed_pc=0x0c07c254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c25a; }
goto P_0c07c256;
P_0c07c256: /* original af40, guest PC 0x0c07c256 */
if(!s->budget--) { s->failed_pc=0x0c07c256u; return 0; }
goto P_0c07c0da;
P_0c07c258: /* original 0009, guest PC 0x0c07c258 */
if(!s->budget--) { s->failed_pc=0x0c07c258u; return 0; }
goto P_0c07c25a;
P_0c07c25a: /* original 2fb6, guest PC 0x0c07c25a */
if(!s->budget--) { s->failed_pc=0x0c07c25au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c25c;
P_0c07c25c: /* original e700, guest PC 0x0c07c25c */
if(!s->budget--) { s->failed_pc=0x0c07c25cu; return 0; }
r[7]=0x00000000u;
goto P_0c07c25e;
P_0c07c25e: /* original 2fe6, guest PC 0x0c07c25e */
if(!s->budget--) { s->failed_pc=0x0c07c25eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c260;
P_0c07c260: /* original 952c, guest PC 0x0c07c260 */
if(!s->budget--) { s->failed_pc=0x0c07c260u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bcu,2);
goto P_0c07c262;
P_0c07c262: /* original 942c, guest PC 0x0c07c262 */
if(!s->budget--) { s->failed_pc=0x0c07c262u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2beu,2);
goto P_0c07c264;
P_0c07c264: /* original 480b, guest PC 0x0c07c264 */
if(!s->budget--) { s->failed_pc=0x0c07c264u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c268u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c268u) { target=s->pc; goto dispatch; }
goto P_0c07c268;
P_0c07c266: /* original 66d3, guest PC 0x0c07c266 */
if(!s->budget--) { s->failed_pc=0x0c07c266u; return 0; }
r[6]=r[13];
goto P_0c07c268;
P_0c07c268: /* original 6403, guest PC 0x0c07c268 */
if(!s->budget--) { s->failed_pc=0x0c07c268u; return 0; }
r[4]=r[0];
goto P_0c07c26a;
P_0c07c26a: /* original e030, guest PC 0x0c07c26a */
if(!s->budget--) { s->failed_pc=0x0c07c26au; return 0; }
r[0]=0x00000030u;
goto P_0c07c26c;
P_0c07c26c: /* original f4e7, guest PC 0x0c07c26c */
if(!s->budget--) { s->failed_pc=0x0c07c26cu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c26e;
P_0c07c26e: /* original e700, guest PC 0x0c07c26e */
if(!s->budget--) { s->failed_pc=0x0c07c26eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c270;
P_0c07c270: /* original 2fb6, guest PC 0x0c07c270 */
if(!s->budget--) { s->failed_pc=0x0c07c270u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c272;
P_0c07c272: /* original 2fe6, guest PC 0x0c07c272 */
if(!s->budget--) { s->failed_pc=0x0c07c272u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c274;
P_0c07c274: /* original 9524, guest PC 0x0c07c274 */
if(!s->budget--) { s->failed_pc=0x0c07c274u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c0u,2);
goto P_0c07c276;
P_0c07c276: /* original 9424, guest PC 0x0c07c276 */
if(!s->budget--) { s->failed_pc=0x0c07c276u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c2u,2);
goto P_0c07c278;
P_0c07c278: /* original 480b, guest PC 0x0c07c278 */
if(!s->budget--) { s->failed_pc=0x0c07c278u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c27cu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c27cu) { target=s->pc; goto dispatch; }
goto P_0c07c27c;
P_0c07c27a: /* original 66d3, guest PC 0x0c07c27a */
if(!s->budget--) { s->failed_pc=0x0c07c27au; return 0; }
r[6]=r[13];
goto P_0c07c27c;
P_0c07c27c: /* original 6403, guest PC 0x0c07c27c */
if(!s->budget--) { s->failed_pc=0x0c07c27cu; return 0; }
r[4]=r[0];
goto P_0c07c27e;
P_0c07c27e: /* original e030, guest PC 0x0c07c27e */
if(!s->budget--) { s->failed_pc=0x0c07c27eu; return 0; }
r[0]=0x00000030u;
goto P_0c07c280;
P_0c07c280: /* original f4e7, guest PC 0x0c07c280 */
if(!s->budget--) { s->failed_pc=0x0c07c280u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c282;
P_0c07c282: /* original e700, guest PC 0x0c07c282 */
if(!s->budget--) { s->failed_pc=0x0c07c282u; return 0; }
r[7]=0x00000000u;
goto P_0c07c284;
P_0c07c284: /* original 2fb6, guest PC 0x0c07c284 */
if(!s->budget--) { s->failed_pc=0x0c07c284u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c286;
P_0c07c286: /* original 2fe6, guest PC 0x0c07c286 */
if(!s->budget--) { s->failed_pc=0x0c07c286u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c288;
P_0c07c288: /* original 9518, guest PC 0x0c07c288 */
if(!s->budget--) { s->failed_pc=0x0c07c288u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bcu,2);
goto P_0c07c28a;
P_0c07c28a: /* original 941b, guest PC 0x0c07c28a */
if(!s->budget--) { s->failed_pc=0x0c07c28au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c4u,2);
goto P_0c07c28c;
P_0c07c28c: /* original 480b, guest PC 0x0c07c28c */
if(!s->budget--) { s->failed_pc=0x0c07c28cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c290u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c290u) { target=s->pc; goto dispatch; }
goto P_0c07c290;
P_0c07c28e: /* original 66d3, guest PC 0x0c07c28e */
if(!s->budget--) { s->failed_pc=0x0c07c28eu; return 0; }
r[6]=r[13];
goto P_0c07c290;
P_0c07c290: /* original 6403, guest PC 0x0c07c290 */
if(!s->budget--) { s->failed_pc=0x0c07c290u; return 0; }
r[4]=r[0];
goto P_0c07c292;
P_0c07c292: /* original e030, guest PC 0x0c07c292 */
if(!s->budget--) { s->failed_pc=0x0c07c292u; return 0; }
r[0]=0x00000030u;
goto P_0c07c294;
P_0c07c294: /* original f4e7, guest PC 0x0c07c294 */
if(!s->budget--) { s->failed_pc=0x0c07c294u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c296;
P_0c07c296: /* original e700, guest PC 0x0c07c296 */
if(!s->budget--) { s->failed_pc=0x0c07c296u; return 0; }
r[7]=0x00000000u;
goto P_0c07c298;
P_0c07c298: /* original 2fb6, guest PC 0x0c07c298 */
if(!s->budget--) { s->failed_pc=0x0c07c298u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c29a;
P_0c07c29a: /* original 2fe6, guest PC 0x0c07c29a */
if(!s->budget--) { s->failed_pc=0x0c07c29au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c29c;
P_0c07c29c: /* original 9510, guest PC 0x0c07c29c */
if(!s->budget--) { s->failed_pc=0x0c07c29cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c0u,2);
goto P_0c07c29e;
P_0c07c29e: /* original 9412, guest PC 0x0c07c29e */
if(!s->budget--) { s->failed_pc=0x0c07c29eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c6u,2);
goto P_0c07c2a0;
P_0c07c2a0: /* original 480b, guest PC 0x0c07c2a0 */
if(!s->budget--) { s->failed_pc=0x0c07c2a0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c2a4u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2a4u) { target=s->pc; goto dispatch; }
goto P_0c07c2a4;
P_0c07c2a2: /* original 66d3, guest PC 0x0c07c2a2 */
if(!s->budget--) { s->failed_pc=0x0c07c2a2u; return 0; }
r[6]=r[13];
goto P_0c07c2a4;
P_0c07c2a4: /* original 6403, guest PC 0x0c07c2a4 */
if(!s->budget--) { s->failed_pc=0x0c07c2a4u; return 0; }
r[4]=r[0];
goto P_0c07c2a6;
P_0c07c2a6: /* original e030, guest PC 0x0c07c2a6 */
if(!s->budget--) { s->failed_pc=0x0c07c2a6u; return 0; }
r[0]=0x00000030u;
goto P_0c07c2a8;
P_0c07c2a8: /* original f4e7, guest PC 0x0c07c2a8 */
if(!s->budget--) { s->failed_pc=0x0c07c2a8u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c2aa;
P_0c07c2aa: /* original 7f20, guest PC 0x0c07c2aa */
if(!s->budget--) { s->failed_pc=0x0c07c2aau; return 0; }
r[15]+=0x00000020u;
goto P_0c07c2ac;
P_0c07c2ac: /* original d307, guest PC 0x0c07c2ac */
if(!s->budget--) { s->failed_pc=0x0c07c2acu; return 0; }
r[3]=read(ram,0x0c07c2ccu,4);
goto P_0c07c2ae;
P_0c07c2ae: /* original 430b, guest PC 0x0c07c2ae */
if(!s->budget--) { s->failed_pc=0x0c07c2aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c2b2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2b2u) { target=s->pc; goto dispatch; }
goto P_0c07c2b2;
P_0c07c2b0: /* original e400, guest PC 0x0c07c2b0 */
if(!s->budget--) { s->failed_pc=0x0c07c2b0u; return 0; }
r[4]=0x00000000u;
goto P_0c07c2b2;
P_0c07c2b2: /* original a01e, guest PC 0x0c07c2b2 */
if(!s->budget--) { s->failed_pc=0x0c07c2b2u; return 0; }
goto P_0c07c2f2;
P_0c07c2b4: /* original 0009, guest PC 0x0c07c2b4 */
if(!s->budget--) { s->failed_pc=0x0c07c2b4u; return 0; }
if(!vf3_matrix_family(0x0c07c2b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c2b6u; return 0; } return 1;
P_0c07c2d0: /* original 50fc, guest PC 0x0c07c2d0 */
if(!s->budget--) { s->failed_pc=0x0c07c2d0u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c07c2d2;
P_0c07c2d2: /* original c802, guest PC 0x0c07c2d2 */
if(!s->budget--) { s->failed_pc=0x0c07c2d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07c2d4;
P_0c07c2d4: /* original 8902, guest PC 0x0c07c2d4 */
if(!s->budget--) { s->failed_pc=0x0c07c2d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2dc; }
goto P_0c07c2d6;
P_0c07c2d6: /* original d243, guest PC 0x0c07c2d6 */
if(!s->budget--) { s->failed_pc=0x0c07c2d6u; return 0; }
r[2]=read(ram,0x0c07c3e4u,4);
goto P_0c07c2d8;
P_0c07c2d8: /* original 420b, guest PC 0x0c07c2d8 */
if(!s->budget--) { s->failed_pc=0x0c07c2d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c2dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2dcu) { target=s->pc; goto dispatch; }
goto P_0c07c2dc;
P_0c07c2da: /* original 0009, guest PC 0x0c07c2da */
if(!s->budget--) { s->failed_pc=0x0c07c2dau; return 0; }
goto P_0c07c2dc;
P_0c07c2dc: /* original 2cc8, guest PC 0x0c07c2dc */
if(!s->budget--) { s->failed_pc=0x0c07c2dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07c2de;
P_0c07c2de: /* original 8902, guest PC 0x0c07c2de */
if(!s->budget--) { s->failed_pc=0x0c07c2deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2e6; }
goto P_0c07c2e0;
P_0c07c2e0: /* original d241, guest PC 0x0c07c2e0 */
if(!s->budget--) { s->failed_pc=0x0c07c2e0u; return 0; }
r[2]=read(ram,0x0c07c3e8u,4);
goto P_0c07c2e2;
P_0c07c2e2: /* original 420b, guest PC 0x0c07c2e2 */
if(!s->budget--) { s->failed_pc=0x0c07c2e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c2e6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2e6u) { target=s->pc; goto dispatch; }
goto P_0c07c2e6;
P_0c07c2e4: /* original 0009, guest PC 0x0c07c2e4 */
if(!s->budget--) { s->failed_pc=0x0c07c2e4u; return 0; }
goto P_0c07c2e6;
P_0c07c2e6: /* original 50fc, guest PC 0x0c07c2e6 */
if(!s->budget--) { s->failed_pc=0x0c07c2e6u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c07c2e8;
P_0c07c2e8: /* original c808, guest PC 0x0c07c2e8 */
if(!s->budget--) { s->failed_pc=0x0c07c2e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c07c2ea;
P_0c07c2ea: /* original 8902, guest PC 0x0c07c2ea */
if(!s->budget--) { s->failed_pc=0x0c07c2eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2f2; }
goto P_0c07c2ec;
P_0c07c2ec: /* original d13f, guest PC 0x0c07c2ec */
if(!s->budget--) { s->failed_pc=0x0c07c2ecu; return 0; }
r[1]=read(ram,0x0c07c3ecu,4);
goto P_0c07c2ee;
P_0c07c2ee: /* original 410b, guest PC 0x0c07c2ee */
if(!s->budget--) { s->failed_pc=0x0c07c2eeu; return 0; }
target=r[1];
r[16]=code_base|0x0c07c2f2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2f2u) { target=s->pc; goto dispatch; }
goto P_0c07c2f2;
P_0c07c2f0: /* original 0009, guest PC 0x0c07c2f0 */
if(!s->budget--) { s->failed_pc=0x0c07c2f0u; return 0; }
goto P_0c07c2f2;
P_0c07c2f2: /* original 51fc, guest PC 0x0c07c2f2 */
if(!s->budget--) { s->failed_pc=0x0c07c2f2u; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c07c2f4;
P_0c07c2f4: /* original 9370, guest PC 0x0c07c2f4 */
if(!s->budget--) { s->failed_pc=0x0c07c2f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c3d8u,2);
goto P_0c07c2f6;
P_0c07c2f6: /* original 2138, guest PC 0x0c07c2f6 */
if(!s->budget--) { s->failed_pc=0x0c07c2f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07c2f8;
P_0c07c2f8: /* original 8902, guest PC 0x0c07c2f8 */
if(!s->budget--) { s->failed_pc=0x0c07c2f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c300; }
goto P_0c07c2fa;
P_0c07c2fa: /* original d23d, guest PC 0x0c07c2fa */
if(!s->budget--) { s->failed_pc=0x0c07c2fau; return 0; }
r[2]=read(ram,0x0c07c3f0u,4);
goto P_0c07c2fc;
P_0c07c2fc: /* original 420b, guest PC 0x0c07c2fc */
if(!s->budget--) { s->failed_pc=0x0c07c2fcu; return 0; }
target=r[2];
r[16]=code_base|0x0c07c300u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c300u) { target=s->pc; goto dispatch; }
goto P_0c07c300;
P_0c07c2fe: /* original 0009, guest PC 0x0c07c2fe */
if(!s->budget--) { s->failed_pc=0x0c07c2feu; return 0; }
goto P_0c07c300;
P_0c07c300: /* original 52fd, guest PC 0x0c07c300 */
if(!s->budget--) { s->failed_pc=0x0c07c300u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c07c302;
P_0c07c302: /* original 64e3, guest PC 0x0c07c302 */
if(!s->budget--) { s->failed_pc=0x0c07c302u; return 0; }
r[4]=r[14];
goto P_0c07c304;
P_0c07c304: /* original 53fc, guest PC 0x0c07c304 */
if(!s->budget--) { s->failed_pc=0x0c07c304u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07c306;
P_0c07c306: /* original 223b, guest PC 0x0c07c306 */
if(!s->budget--) { s->failed_pc=0x0c07c306u; return 0; }
r[2]|=r[3];
goto P_0c07c308;
P_0c07c308: /* original 1f2c, guest PC 0x0c07c308 */
if(!s->budget--) { s->failed_pc=0x0c07c308u; return 0; }
write(ram,r[15]+48,r[2],4);
goto P_0c07c30a;
P_0c07c30a: /* original d33a, guest PC 0x0c07c30a */
if(!s->budget--) { s->failed_pc=0x0c07c30au; return 0; }
r[3]=read(ram,0x0c07c3f4u,4);
goto P_0c07c30c;
P_0c07c30c: /* original 2322, guest PC 0x0c07c30c */
if(!s->budget--) { s->failed_pc=0x0c07c30cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c30e;
P_0c07c30e: /* original d23a, guest PC 0x0c07c30e */
if(!s->budget--) { s->failed_pc=0x0c07c30eu; return 0; }
r[2]=read(ram,0x0c07c3f8u,4);
goto P_0c07c310;
P_0c07c310: /* original 22e2, guest PC 0x0c07c310 */
if(!s->budget--) { s->failed_pc=0x0c07c310u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c07c312;
P_0c07c312: /* original d13a, guest PC 0x0c07c312 */
if(!s->budget--) { s->failed_pc=0x0c07c312u; return 0; }
r[1]=read(ram,0x0c07c3fcu,4);
goto P_0c07c314;
P_0c07c314: /* original 53fc, guest PC 0x0c07c314 */
if(!s->budget--) { s->failed_pc=0x0c07c314u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07c316;
P_0c07c316: /* original 2132, guest PC 0x0c07c316 */
if(!s->budget--) { s->failed_pc=0x0c07c316u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c07c318;
P_0c07c318: /* original 915f, guest PC 0x0c07c318 */
if(!s->budget--) { s->failed_pc=0x0c07c318u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c3dau,2);
goto P_0c07c31a;
P_0c07c31a: /* original 3f1c, guest PC 0x0c07c31a */
if(!s->budget--) { s->failed_pc=0x0c07c31au; return 0; }
r[15]+=r[1];
goto P_0c07c31c;
P_0c07c31c: /* original 4f16, guest PC 0x0c07c31c */
if(!s->budget--) { s->failed_pc=0x0c07c31cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c31e;
P_0c07c31e: /* original 4f26, guest PC 0x0c07c31e */
if(!s->budget--) { s->failed_pc=0x0c07c31eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c320;
P_0c07c320: /* original fef9, guest PC 0x0c07c320 */
if(!s->budget--) { s->failed_pc=0x0c07c320u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07c322;
P_0c07c322: /* original fff9, guest PC 0x0c07c322 */
if(!s->budget--) { s->failed_pc=0x0c07c322u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07c324;
P_0c07c324: /* original 68f6, guest PC 0x0c07c324 */
if(!s->budget--) { s->failed_pc=0x0c07c324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07c326;
P_0c07c326: /* original 69f6, guest PC 0x0c07c326 */
if(!s->budget--) { s->failed_pc=0x0c07c326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07c328;
P_0c07c328: /* original 6af6, guest PC 0x0c07c328 */
if(!s->budget--) { s->failed_pc=0x0c07c328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07c32a;
P_0c07c32a: /* original 6bf6, guest PC 0x0c07c32a */
if(!s->budget--) { s->failed_pc=0x0c07c32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07c32c;
P_0c07c32c: /* original 6cf6, guest PC 0x0c07c32c */
if(!s->budget--) { s->failed_pc=0x0c07c32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07c32e;
P_0c07c32e: /* original 6df6, guest PC 0x0c07c32e */
if(!s->budget--) { s->failed_pc=0x0c07c32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c330;
P_0c07c330: /* original 000b, guest PC 0x0c07c330 */
if(!s->budget--) { s->failed_pc=0x0c07c330u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07c332: /* original 6ef6, guest PC 0x0c07c332 */
if(!s->budget--) { s->failed_pc=0x0c07c332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07c334u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c334u; return 0; } return 1;
P_0c07c446: /* original 4f22, guest PC 0x0c07c446 */
if(!s->budget--) { s->failed_pc=0x0c07c446u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c448;
P_0c07c448: /* original 7ff8, guest PC 0x0c07c448 */
if(!s->budget--) { s->failed_pc=0x0c07c448u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07c44a;
P_0c07c44a: /* original 2f42, guest PC 0x0c07c44a */
if(!s->budget--) { s->failed_pc=0x0c07c44au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c44c;
P_0c07c44c: /* original 1f31, guest PC 0x0c07c44c */
if(!s->budget--) { s->failed_pc=0x0c07c44cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07c44e;
P_0c07c44e: /* original d330, guest PC 0x0c07c44e */
if(!s->budget--) { s->failed_pc=0x0c07c44eu; return 0; }
r[3]=read(ram,0x0c07c510u,4);
goto P_0c07c450;
P_0c07c450: /* original 430b, guest PC 0x0c07c450 */
if(!s->budget--) { s->failed_pc=0x0c07c450u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c454u;
r[4]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c454u) { target=s->pc; goto dispatch; }
goto P_0c07c454;
P_0c07c452: /* original e40a, guest PC 0x0c07c452 */
if(!s->budget--) { s->failed_pc=0x0c07c452u; return 0; }
r[4]=0x0000000au;
goto P_0c07c454;
P_0c07c454: /* original d22e, guest PC 0x0c07c454 */
if(!s->budget--) { s->failed_pc=0x0c07c454u; return 0; }
r[2]=read(ram,0x0c07c510u,4);
goto P_0c07c456;
P_0c07c456: /* original 420b, guest PC 0x0c07c456 */
if(!s->budget--) { s->failed_pc=0x0c07c456u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c45au;
r[4]=0x0000000bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c45au) { target=s->pc; goto dispatch; }
goto P_0c07c45a;
P_0c07c458: /* original e40b, guest PC 0x0c07c458 */
if(!s->budget--) { s->failed_pc=0x0c07c458u; return 0; }
r[4]=0x0000000bu;
goto P_0c07c45a;
P_0c07c45a: /* original d32e, guest PC 0x0c07c45a */
if(!s->budget--) { s->failed_pc=0x0c07c45au; return 0; }
r[3]=read(ram,0x0c07c514u,4);
goto P_0c07c45c;
P_0c07c45c: /* original 9453, guest PC 0x0c07c45c */
if(!s->budget--) { s->failed_pc=0x0c07c45cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c506u,2);
goto P_0c07c45e;
P_0c07c45e: /* original 430b, guest PC 0x0c07c45e */
if(!s->budget--) { s->failed_pc=0x0c07c45eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c462u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c462u) { target=s->pc; goto dispatch; }
goto P_0c07c462;
P_0c07c460: /* original 0009, guest PC 0x0c07c460 */
if(!s->budget--) { s->failed_pc=0x0c07c460u; return 0; }
goto P_0c07c462;
P_0c07c462: /* original d32d, guest PC 0x0c07c462 */
if(!s->budget--) { s->failed_pc=0x0c07c462u; return 0; }
r[3]=read(ram,0x0c07c518u,4);
goto P_0c07c464;
P_0c07c464: /* original e200, guest PC 0x0c07c464 */
if(!s->budget--) { s->failed_pc=0x0c07c464u; return 0; }
r[2]=0x00000000u;
goto P_0c07c466;
P_0c07c466: /* original d429, guest PC 0x0c07c466 */
if(!s->budget--) { s->failed_pc=0x0c07c466u; return 0; }
r[4]=read(ram,0x0c07c50cu,4);
goto P_0c07c468;
P_0c07c468: /* original 2322, guest PC 0x0c07c468 */
if(!s->budget--) { s->failed_pc=0x0c07c468u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c46a;
P_0c07c46a: /* original 6e43, guest PC 0x0c07c46a */
if(!s->budget--) { s->failed_pc=0x0c07c46au; return 0; }
r[14]=r[4];
goto P_0c07c46c;
P_0c07c46c: /* original 6643, guest PC 0x0c07c46c */
if(!s->budget--) { s->failed_pc=0x0c07c46cu; return 0; }
r[6]=r[4];
goto P_0c07c46e;
P_0c07c46e: /* original 944b, guest PC 0x0c07c46e */
if(!s->budget--) { s->failed_pc=0x0c07c46eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c508u,2);
goto P_0c07c470;
P_0c07c470: /* original 7658, guest PC 0x0c07c470 */
if(!s->budget--) { s->failed_pc=0x0c07c470u; return 0; }
r[6]+=0x00000058u;
goto P_0c07c472;
P_0c07c472: /* original d22a, guest PC 0x0c07c472 */
if(!s->budget--) { s->failed_pc=0x0c07c472u; return 0; }
r[2]=read(ram,0x0c07c51cu,4);
goto P_0c07c474;
P_0c07c474: /* original 420b, guest PC 0x0c07c474 */
if(!s->budget--) { s->failed_pc=0x0c07c474u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c478u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c478u) { target=s->pc; goto dispatch; }
goto P_0c07c478;
P_0c07c476: /* original 65e3, guest PC 0x0c07c476 */
if(!s->budget--) { s->failed_pc=0x0c07c476u; return 0; }
r[5]=r[14];
goto P_0c07c478;
P_0c07c478: /* original d229, guest PC 0x0c07c478 */
if(!s->budget--) { s->failed_pc=0x0c07c478u; return 0; }
r[2]=read(ram,0x0c07c520u,4);
goto P_0c07c47a;
P_0c07c47a: /* original 66e3, guest PC 0x0c07c47a */
if(!s->budget--) { s->failed_pc=0x0c07c47au; return 0; }
r[6]=r[14];
goto P_0c07c47c;
P_0c07c47c: /* original 53f1, guest PC 0x0c07c47c */
if(!s->budget--) { s->failed_pc=0x0c07c47cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07c47e;
P_0c07c47e: /* original e700, guest PC 0x0c07c47e */
if(!s->budget--) { s->failed_pc=0x0c07c47eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c480;
P_0c07c480: /* original 1324, guest PC 0x0c07c480 */
if(!s->budget--) { s->failed_pc=0x0c07c480u; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c07c482;
P_0c07c482: /* original d328, guest PC 0x0c07c482 */
if(!s->budget--) { s->failed_pc=0x0c07c482u; return 0; }
r[3]=read(ram,0x0c07c524u,4);
goto P_0c07c484;
P_0c07c484: /* original 6130, guest PC 0x0c07c484 */
if(!s->budget--) { s->failed_pc=0x0c07c484u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[1]=tmp;
goto P_0c07c486;
P_0c07c486: /* original 7101, guest PC 0x0c07c486 */
if(!s->budget--) { s->failed_pc=0x0c07c486u; return 0; }
r[1]+=0x00000001u;
goto P_0c07c488;
P_0c07c488: /* original 2310, guest PC 0x0c07c488 */
if(!s->budget--) { s->failed_pc=0x0c07c488u; return 0; }
write(ram,r[3],r[1],1);
goto P_0c07c48a;
P_0c07c48a: /* original e301, guest PC 0x0c07c48a */
if(!s->budget--) { s->failed_pc=0x0c07c48au; return 0; }
r[3]=0x00000001u;
goto P_0c07c48c;
P_0c07c48c: /* original 2f36, guest PC 0x0c07c48c */
if(!s->budget--) { s->failed_pc=0x0c07c48cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c48e;
P_0c07c48e: /* original 953a, guest PC 0x0c07c48e */
if(!s->budget--) { s->failed_pc=0x0c07c48eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c506u,2);
goto P_0c07c490;
P_0c07c490: /* original d225, guest PC 0x0c07c490 */
if(!s->budget--) { s->failed_pc=0x0c07c490u; return 0; }
r[2]=read(ram,0x0c07c528u,4);
goto P_0c07c492;
P_0c07c492: /* original 420b, guest PC 0x0c07c492 */
if(!s->budget--) { s->failed_pc=0x0c07c492u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c496u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c496u) { target=s->pc; goto dispatch; }
goto P_0c07c496;
P_0c07c494: /* original 6473, guest PC 0x0c07c494 */
if(!s->budget--) { s->failed_pc=0x0c07c494u; return 0; }
r[4]=r[7];
goto P_0c07c496;
P_0c07c496: /* original 54f1, guest PC 0x0c07c496 */
if(!s->budget--) { s->failed_pc=0x0c07c496u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07c498;
P_0c07c498: /* original 7f0c, guest PC 0x0c07c498 */
if(!s->budget--) { s->failed_pc=0x0c07c498u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07c49a;
P_0c07c49a: /* original 4f26, guest PC 0x0c07c49a */
if(!s->budget--) { s->failed_pc=0x0c07c49au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c49c;
P_0c07c49c: /* original e500, guest PC 0x0c07c49c */
if(!s->budget--) { s->failed_pc=0x0c07c49cu; return 0; }
r[5]=0x00000000u;
goto P_0c07c49e;
P_0c07c49e: /* original aac3, guest PC 0x0c07c49e */
if(!s->budget--) { s->failed_pc=0x0c07c49eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ba28;
P_0c07c4a0: /* original 6ef6, guest PC 0x0c07c4a0 */
if(!s->budget--) { s->failed_pc=0x0c07c4a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07c4a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c4a2u; return 0; } return 1;
P_0c07c4a6: /* original 4f22, guest PC 0x0c07c4a6 */
if(!s->budget--) { s->failed_pc=0x0c07c4a6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c4a8;
P_0c07c4a8: /* original 7ff8, guest PC 0x0c07c4a8 */
if(!s->budget--) { s->failed_pc=0x0c07c4a8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07c4aa;
P_0c07c4aa: /* original 2f42, guest PC 0x0c07c4aa */
if(!s->budget--) { s->failed_pc=0x0c07c4aau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c4ac;
P_0c07c4ac: /* original d319, guest PC 0x0c07c4ac */
if(!s->budget--) { s->failed_pc=0x0c07c4acu; return 0; }
r[3]=read(ram,0x0c07c514u,4);
goto P_0c07c4ae;
P_0c07c4ae: /* original 942c, guest PC 0x0c07c4ae */
if(!s->budget--) { s->failed_pc=0x0c07c4aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c50au,2);
goto P_0c07c4b0;
P_0c07c4b0: /* original 430b, guest PC 0x0c07c4b0 */
if(!s->budget--) { s->failed_pc=0x0c07c4b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c4b4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c4b4u) { target=s->pc; goto dispatch; }
goto P_0c07c4b4;
P_0c07c4b2: /* original 0009, guest PC 0x0c07c4b2 */
if(!s->budget--) { s->failed_pc=0x0c07c4b2u; return 0; }
goto P_0c07c4b4;
P_0c07c4b4: /* original 62f2, guest PC 0x0c07c4b4 */
if(!s->budget--) { s->failed_pc=0x0c07c4b4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07c4b6;
P_0c07c4b6: /* original 1f21, guest PC 0x0c07c4b6 */
if(!s->budget--) { s->failed_pc=0x0c07c4b6u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07c4b8;
P_0c07c4b8: /* original d414, guest PC 0x0c07c4b8 */
if(!s->budget--) { s->failed_pc=0x0c07c4b8u; return 0; }
r[4]=read(ram,0x0c07c50cu,4);
goto P_0c07c4ba;
P_0c07c4ba: /* original d31c, guest PC 0x0c07c4ba */
if(!s->budget--) { s->failed_pc=0x0c07c4bau; return 0; }
r[3]=read(ram,0x0c07c52cu,4);
goto P_0c07c4bc;
P_0c07c4bc: /* original 6d43, guest PC 0x0c07c4bc */
if(!s->budget--) { s->failed_pc=0x0c07c4bcu; return 0; }
r[13]=r[4];
goto P_0c07c4be;
P_0c07c4be: /* original 6e43, guest PC 0x0c07c4be */
if(!s->budget--) { s->failed_pc=0x0c07c4beu; return 0; }
r[14]=r[4];
goto P_0c07c4c0;
P_0c07c4c0: /* original 430b, guest PC 0x0c07c4c0 */
if(!s->budget--) { s->failed_pc=0x0c07c4c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c4c4u;
r[13]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c4c4u) { target=s->pc; goto dispatch; }
goto P_0c07c4c4;
P_0c07c4c2: /* original 7d58, guest PC 0x0c07c4c2 */
if(!s->budget--) { s->failed_pc=0x0c07c4c2u; return 0; }
r[13]+=0x00000058u;
goto P_0c07c4c4;
P_0c07c4c4: /* original d219, guest PC 0x0c07c4c4 */
if(!s->budget--) { s->failed_pc=0x0c07c4c4u; return 0; }
r[2]=read(ram,0x0c07c52cu,4);
goto P_0c07c4c6;
P_0c07c4c6: /* original 420b, guest PC 0x0c07c4c6 */
if(!s->budget--) { s->failed_pc=0x0c07c4c6u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c4cau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c4cau) { target=s->pc; goto dispatch; }
goto P_0c07c4ca;
P_0c07c4c8: /* original 64d3, guest PC 0x0c07c4c8 */
if(!s->budget--) { s->failed_pc=0x0c07c4c8u; return 0; }
r[4]=r[13];
goto P_0c07c4ca;
P_0c07c4ca: /* original d213, guest PC 0x0c07c4ca */
if(!s->budget--) { s->failed_pc=0x0c07c4cau; return 0; }
r[2]=read(ram,0x0c07c518u,4);
goto P_0c07c4cc;
P_0c07c4cc: /* original e300, guest PC 0x0c07c4cc */
if(!s->budget--) { s->failed_pc=0x0c07c4ccu; return 0; }
r[3]=0x00000000u;
goto P_0c07c4ce;
P_0c07c4ce: /* original 66d3, guest PC 0x0c07c4ce */
if(!s->budget--) { s->failed_pc=0x0c07c4ceu; return 0; }
r[6]=r[13];
goto P_0c07c4d0;
P_0c07c4d0: /* original 2232, guest PC 0x0c07c4d0 */
if(!s->budget--) { s->failed_pc=0x0c07c4d0u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07c4d2;
P_0c07c4d2: /* original d312, guest PC 0x0c07c4d2 */
if(!s->budget--) { s->failed_pc=0x0c07c4d2u; return 0; }
r[3]=read(ram,0x0c07c51cu,4);
goto P_0c07c4d4;
P_0c07c4d4: /* original 9418, guest PC 0x0c07c4d4 */
if(!s->budget--) { s->failed_pc=0x0c07c4d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c508u,2);
goto P_0c07c4d6;
P_0c07c4d6: /* original 430b, guest PC 0x0c07c4d6 */
if(!s->budget--) { s->failed_pc=0x0c07c4d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c4dau;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c4dau) { target=s->pc; goto dispatch; }
goto P_0c07c4da;
P_0c07c4d8: /* original 65e3, guest PC 0x0c07c4d8 */
if(!s->budget--) { s->failed_pc=0x0c07c4d8u; return 0; }
r[5]=r[14];
goto P_0c07c4da;
P_0c07c4da: /* original d315, guest PC 0x0c07c4da */
if(!s->budget--) { s->failed_pc=0x0c07c4dau; return 0; }
r[3]=read(ram,0x0c07c530u,4);
goto P_0c07c4dc;
P_0c07c4dc: /* original 66e3, guest PC 0x0c07c4dc */
if(!s->budget--) { s->failed_pc=0x0c07c4dcu; return 0; }
r[6]=r[14];
goto P_0c07c4de;
P_0c07c4de: /* original 52f1, guest PC 0x0c07c4de */
if(!s->budget--) { s->failed_pc=0x0c07c4deu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07c4e0;
P_0c07c4e0: /* original e700, guest PC 0x0c07c4e0 */
if(!s->budget--) { s->failed_pc=0x0c07c4e0u; return 0; }
r[7]=0x00000000u;
goto P_0c07c4e2;
P_0c07c4e2: /* original 1234, guest PC 0x0c07c4e2 */
if(!s->budget--) { s->failed_pc=0x0c07c4e2u; return 0; }
write(ram,r[2]+16,r[3],4);
goto P_0c07c4e4;
P_0c07c4e4: /* original e301, guest PC 0x0c07c4e4 */
if(!s->budget--) { s->failed_pc=0x0c07c4e4u; return 0; }
r[3]=0x00000001u;
goto P_0c07c4e6;
P_0c07c4e6: /* original d20f, guest PC 0x0c07c4e6 */
if(!s->budget--) { s->failed_pc=0x0c07c4e6u; return 0; }
r[2]=read(ram,0x0c07c524u,4);
goto P_0c07c4e8;
P_0c07c4e8: /* original 6120, guest PC 0x0c07c4e8 */
if(!s->budget--) { s->failed_pc=0x0c07c4e8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c07c4ea;
P_0c07c4ea: /* original 7101, guest PC 0x0c07c4ea */
if(!s->budget--) { s->failed_pc=0x0c07c4eau; return 0; }
r[1]+=0x00000001u;
goto P_0c07c4ec;
P_0c07c4ec: /* original 2210, guest PC 0x0c07c4ec */
if(!s->budget--) { s->failed_pc=0x0c07c4ecu; return 0; }
write(ram,r[2],r[1],1);
goto P_0c07c4ee;
P_0c07c4ee: /* original 2f36, guest PC 0x0c07c4ee */
if(!s->budget--) { s->failed_pc=0x0c07c4eeu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c4f0;
P_0c07c4f0: /* original 950b, guest PC 0x0c07c4f0 */
if(!s->budget--) { s->failed_pc=0x0c07c4f0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c50au,2);
goto P_0c07c4f2;
P_0c07c4f2: /* original d20d, guest PC 0x0c07c4f2 */
if(!s->budget--) { s->failed_pc=0x0c07c4f2u; return 0; }
r[2]=read(ram,0x0c07c528u,4);
goto P_0c07c4f4;
P_0c07c4f4: /* original 420b, guest PC 0x0c07c4f4 */
if(!s->budget--) { s->failed_pc=0x0c07c4f4u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c4f8u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c4f8u) { target=s->pc; goto dispatch; }
goto P_0c07c4f8;
P_0c07c4f6: /* original 6473, guest PC 0x0c07c4f6 */
if(!s->budget--) { s->failed_pc=0x0c07c4f6u; return 0; }
r[4]=r[7];
goto P_0c07c4f8;
P_0c07c4f8: /* original 54f1, guest PC 0x0c07c4f8 */
if(!s->budget--) { s->failed_pc=0x0c07c4f8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07c4fa;
P_0c07c4fa: /* original 7f0c, guest PC 0x0c07c4fa */
if(!s->budget--) { s->failed_pc=0x0c07c4fau; return 0; }
r[15]+=0x0000000cu;
goto P_0c07c4fc;
P_0c07c4fc: /* original 4f26, guest PC 0x0c07c4fc */
if(!s->budget--) { s->failed_pc=0x0c07c4fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c4fe;
P_0c07c4fe: /* original e500, guest PC 0x0c07c4fe */
if(!s->budget--) { s->failed_pc=0x0c07c4feu; return 0; }
r[5]=0x00000000u;
goto P_0c07c500;
P_0c07c500: /* original 6df6, guest PC 0x0c07c500 */
if(!s->budget--) { s->failed_pc=0x0c07c500u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c502;
P_0c07c502: /* original aa91, guest PC 0x0c07c502 */
if(!s->budget--) { s->failed_pc=0x0c07c502u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ba28;
P_0c07c504: /* original 6ef6, guest PC 0x0c07c504 */
if(!s->budget--) { s->failed_pc=0x0c07c504u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07c506u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c506u; return 0; } return 1;
P_0c07c6b6: /* original 4f22, guest PC 0x0c07c6b6 */
if(!s->budget--) { s->failed_pc=0x0c07c6b6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c6b8;
P_0c07c6b8: /* original 7ffc, guest PC 0x0c07c6b8 */
if(!s->budget--) { s->failed_pc=0x0c07c6b8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07c6ba;
P_0c07c6ba: /* original 2f42, guest PC 0x0c07c6ba */
if(!s->budget--) { s->failed_pc=0x0c07c6bau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c6bc;
P_0c07c6bc: /* original d349, guest PC 0x0c07c6bc */
if(!s->budget--) { s->failed_pc=0x0c07c6bcu; return 0; }
r[3]=read(ram,0x0c07c7e4u,4);
goto P_0c07c6be;
P_0c07c6be: /* original 9488, guest PC 0x0c07c6be */
if(!s->budget--) { s->failed_pc=0x0c07c6beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7d2u,2);
goto P_0c07c6c0;
P_0c07c6c0: /* original 430b, guest PC 0x0c07c6c0 */
if(!s->budget--) { s->failed_pc=0x0c07c6c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c6c4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6c4u) { target=s->pc; goto dispatch; }
goto P_0c07c6c4;
P_0c07c6c2: /* original 0009, guest PC 0x0c07c6c2 */
if(!s->budget--) { s->failed_pc=0x0c07c6c2u; return 0; }
goto P_0c07c6c4;
P_0c07c6c4: /* original de48, guest PC 0x0c07c6c4 */
if(!s->budget--) { s->failed_pc=0x0c07c6c4u; return 0; }
r[14]=read(ram,0x0c07c7e8u,4);
goto P_0c07c6c6;
P_0c07c6c6: /* original e200, guest PC 0x0c07c6c6 */
if(!s->budget--) { s->failed_pc=0x0c07c6c6u; return 0; }
r[2]=0x00000000u;
goto P_0c07c6c8;
P_0c07c6c8: /* original 1e26, guest PC 0x0c07c6c8 */
if(!s->budget--) { s->failed_pc=0x0c07c6c8u; return 0; }
write(ram,r[14]+24,r[2],4);
goto P_0c07c6ca;
P_0c07c6ca: /* original d249, guest PC 0x0c07c6ca */
if(!s->budget--) { s->failed_pc=0x0c07c6cau; return 0; }
r[2]=read(ram,0x0c07c7f0u,4);
goto P_0c07c6cc;
P_0c07c6cc: /* original 9482, guest PC 0x0c07c6cc */
if(!s->budget--) { s->failed_pc=0x0c07c6ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7d4u,2);
goto P_0c07c6ce;
P_0c07c6ce: /* original d347, guest PC 0x0c07c6ce */
if(!s->budget--) { s->failed_pc=0x0c07c6ceu; return 0; }
r[3]=read(ram,0x0c07c7ecu,4);
goto P_0c07c6d0;
P_0c07c6d0: /* original 420b, guest PC 0x0c07c6d0 */
if(!s->budget--) { s->failed_pc=0x0c07c6d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c6d4u;
write(ram,r[13]+16,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6d4u) { target=s->pc; goto dispatch; }
goto P_0c07c6d4;
P_0c07c6d2: /* original 1d34, guest PC 0x0c07c6d2 */
if(!s->budget--) { s->failed_pc=0x0c07c6d2u; return 0; }
write(ram,r[13]+16,r[3],4);
goto P_0c07c6d4;
P_0c07c6d4: /* original d348, guest PC 0x0c07c6d4 */
if(!s->budget--) { s->failed_pc=0x0c07c6d4u; return 0; }
r[3]=read(ram,0x0c07c7f8u,4);
goto P_0c07c6d6;
P_0c07c6d6: /* original db47, guest PC 0x0c07c6d6 */
if(!s->budget--) { s->failed_pc=0x0c07c6d6u; return 0; }
r[11]=read(ram,0x0c07c7f4u,4);
goto P_0c07c6d8;
P_0c07c6d8: /* original 430b, guest PC 0x0c07c6d8 */
if(!s->budget--) { s->failed_pc=0x0c07c6d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c6dcu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6dcu) { target=s->pc; goto dispatch; }
goto P_0c07c6dc;
P_0c07c6da: /* original 64b3, guest PC 0x0c07c6da */
if(!s->budget--) { s->failed_pc=0x0c07c6dau; return 0; }
r[4]=r[11];
goto P_0c07c6dc;
P_0c07c6dc: /* original d246, guest PC 0x0c07c6dc */
if(!s->budget--) { s->failed_pc=0x0c07c6dcu; return 0; }
r[2]=read(ram,0x0c07c7f8u,4);
goto P_0c07c6de;
P_0c07c6de: /* original 64b3, guest PC 0x0c07c6de */
if(!s->budget--) { s->failed_pc=0x0c07c6deu; return 0; }
r[4]=r[11];
goto P_0c07c6e0;
P_0c07c6e0: /* original 420b, guest PC 0x0c07c6e0 */
if(!s->budget--) { s->failed_pc=0x0c07c6e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c6e4u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6e4u) { target=s->pc; goto dispatch; }
goto P_0c07c6e4;
P_0c07c6e2: /* original 7458, guest PC 0x0c07c6e2 */
if(!s->budget--) { s->failed_pc=0x0c07c6e2u; return 0; }
r[4]+=0x00000058u;
goto P_0c07c6e4;
P_0c07c6e4: /* original d345, guest PC 0x0c07c6e4 */
if(!s->budget--) { s->failed_pc=0x0c07c6e4u; return 0; }
r[3]=read(ram,0x0c07c7fcu,4);
goto P_0c07c6e6;
P_0c07c6e6: /* original 430b, guest PC 0x0c07c6e6 */
if(!s->budget--) { s->failed_pc=0x0c07c6e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c6eau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6eau) { target=s->pc; goto dispatch; }
goto P_0c07c6ea;
P_0c07c6e8: /* original 0009, guest PC 0x0c07c6e8 */
if(!s->budget--) { s->failed_pc=0x0c07c6e8u; return 0; }
goto P_0c07c6ea;
P_0c07c6ea: /* original e210, guest PC 0x0c07c6ea */
if(!s->budget--) { s->failed_pc=0x0c07c6eau; return 0; }
r[2]=0x00000010u;
goto P_0c07c6ec;
P_0c07c6ec: /* original 66b3, guest PC 0x0c07c6ec */
if(!s->budget--) { s->failed_pc=0x0c07c6ecu; return 0; }
r[6]=r[11];
goto P_0c07c6ee;
P_0c07c6ee: /* original 1e25, guest PC 0x0c07c6ee */
if(!s->budget--) { s->failed_pc=0x0c07c6eeu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c07c6f0;
P_0c07c6f0: /* original e300, guest PC 0x0c07c6f0 */
if(!s->budget--) { s->failed_pc=0x0c07c6f0u; return 0; }
r[3]=0x00000000u;
goto P_0c07c6f2;
P_0c07c6f2: /* original 9c70, guest PC 0x0c07c6f2 */
if(!s->budget--) { s->failed_pc=0x0c07c6f2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7d6u,2);
goto P_0c07c6f4;
P_0c07c6f4: /* original 6733, guest PC 0x0c07c6f4 */
if(!s->budget--) { s->failed_pc=0x0c07c6f4u; return 0; }
r[7]=r[3];
goto P_0c07c6f6;
P_0c07c6f6: /* original 2f36, guest PC 0x0c07c6f6 */
if(!s->budget--) { s->failed_pc=0x0c07c6f6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c6f8;
P_0c07c6f8: /* original d241, guest PC 0x0c07c6f8 */
if(!s->budget--) { s->failed_pc=0x0c07c6f8u; return 0; }
r[2]=read(ram,0x0c07c800u,4);
goto P_0c07c6fa;
P_0c07c6fa: /* original 956d, guest PC 0x0c07c6fa */
if(!s->budget--) { s->failed_pc=0x0c07c6fau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7d8u,2);
goto P_0c07c6fc;
P_0c07c6fc: /* original 420b, guest PC 0x0c07c6fc */
if(!s->budget--) { s->failed_pc=0x0c07c6fcu; return 0; }
target=r[2];
r[16]=code_base|0x0c07c700u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c700u) { target=s->pc; goto dispatch; }
goto P_0c07c700;
P_0c07c6fe: /* original 64c3, guest PC 0x0c07c6fe */
if(!s->budget--) { s->failed_pc=0x0c07c6feu; return 0; }
r[4]=r[12];
goto P_0c07c700;
P_0c07c700: /* original e010, guest PC 0x0c07c700 */
if(!s->budget--) { s->failed_pc=0x0c07c700u; return 0; }
r[0]=0x00000010u;
goto P_0c07c702;
P_0c07c702: /* original 65c3, guest PC 0x0c07c702 */
if(!s->budget--) { s->failed_pc=0x0c07c702u; return 0; }
r[5]=r[12];
goto P_0c07c704;
P_0c07c704: /* original 03ec, guest PC 0x0c07c704 */
if(!s->budget--) { s->failed_pc=0x0c07c704u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07c706;
P_0c07c706: /* original e240, guest PC 0x0c07c706 */
if(!s->budget--) { s->failed_pc=0x0c07c706u; return 0; }
r[2]=0x00000040u;
goto P_0c07c708;
P_0c07c708: /* original 7301, guest PC 0x0c07c708 */
if(!s->budget--) { s->failed_pc=0x0c07c708u; return 0; }
r[3]+=0x00000001u;
goto P_0c07c70a;
P_0c07c70a: /* original 0e34, guest PC 0x0c07c70a */
if(!s->budget--) { s->failed_pc=0x0c07c70au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07c70c;
P_0c07c70c: /* original 9065, guest PC 0x0c07c70c */
if(!s->budget--) { s->failed_pc=0x0c07c70cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7dau,2);
goto P_0c07c70e;
P_0c07c70e: /* original 0d26, guest PC 0x0c07c70e */
if(!s->budget--) { s->failed_pc=0x0c07c70eu; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c07c710;
P_0c07c710: /* original 54f1, guest PC 0x0c07c710 */
if(!s->budget--) { s->failed_pc=0x0c07c710u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07c712;
P_0c07c712: /* original 7f08, guest PC 0x0c07c712 */
if(!s->budget--) { s->failed_pc=0x0c07c712u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c714;
P_0c07c714: /* original 4f26, guest PC 0x0c07c714 */
if(!s->budget--) { s->failed_pc=0x0c07c714u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c716;
P_0c07c716: /* original 6bf6, guest PC 0x0c07c716 */
if(!s->budget--) { s->failed_pc=0x0c07c716u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07c718;
P_0c07c718: /* original 6cf6, guest PC 0x0c07c718 */
if(!s->budget--) { s->failed_pc=0x0c07c718u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07c71a;
P_0c07c71a: /* original 6df6, guest PC 0x0c07c71a */
if(!s->budget--) { s->failed_pc=0x0c07c71au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c71c;
P_0c07c71c: /* original a000, guest PC 0x0c07c71c */
if(!s->budget--) { s->failed_pc=0x0c07c71cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07c720;
P_0c07c71e: /* original 6ef6, guest PC 0x0c07c71e */
if(!s->budget--) { s->failed_pc=0x0c07c71eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07c720;
P_0c07c720: /* original 2fe6, guest PC 0x0c07c720 */
if(!s->budget--) { s->failed_pc=0x0c07c720u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c722;
P_0c07c722: /* original 4f22, guest PC 0x0c07c722 */
if(!s->budget--) { s->failed_pc=0x0c07c722u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c724;
P_0c07c724: /* original 7ff4, guest PC 0x0c07c724 */
if(!s->budget--) { s->failed_pc=0x0c07c724u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07c726;
P_0c07c726: /* original 2f42, guest PC 0x0c07c726 */
if(!s->budget--) { s->failed_pc=0x0c07c726u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c728;
P_0c07c728: /* original 1f51, guest PC 0x0c07c728 */
if(!s->budget--) { s->failed_pc=0x0c07c728u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07c72a;
P_0c07c72a: /* original d336, guest PC 0x0c07c72a */
if(!s->budget--) { s->failed_pc=0x0c07c72au; return 0; }
r[3]=read(ram,0x0c07c804u,4);
goto P_0c07c72c;
P_0c07c72c: /* original 1f32, guest PC 0x0c07c72c */
if(!s->budget--) { s->failed_pc=0x0c07c72cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07c72e;
P_0c07c72e: /* original 6ef2, guest PC 0x0c07c72e */
if(!s->budget--) { s->failed_pc=0x0c07c72eu; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c07c730;
P_0c07c730: /* original 9053, guest PC 0x0c07c730 */
if(!s->budget--) { s->failed_pc=0x0c07c730u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7dau,2);
goto P_0c07c732;
P_0c07c732: /* original 03ee, guest PC 0x0c07c732 */
if(!s->budget--) { s->failed_pc=0x0c07c732u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c07c734;
P_0c07c734: /* original 2338, guest PC 0x0c07c734 */
if(!s->budget--) { s->failed_pc=0x0c07c734u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07c736;
P_0c07c736: /* original 8913, guest PC 0x0c07c736 */
if(!s->budget--) { s->failed_pc=0x0c07c736u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c760; }
goto P_0c07c738;
P_0c07c738: /* original 03ee, guest PC 0x0c07c738 */
if(!s->budget--) { s->failed_pc=0x0c07c738u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c07c73a;
P_0c07c73a: /* original 73ff, guest PC 0x0c07c73a */
if(!s->budget--) { s->failed_pc=0x0c07c73au; return 0; }
r[3]+=0xffffffffu;
goto P_0c07c73c;
P_0c07c73c: /* original 0e36, guest PC 0x0c07c73c */
if(!s->budget--) { s->failed_pc=0x0c07c73cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c07c73e;
P_0c07c73e: /* original 02ee, guest PC 0x0c07c73e */
if(!s->budget--) { s->failed_pc=0x0c07c73eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c07c740;
P_0c07c740: /* original 2228, guest PC 0x0c07c740 */
if(!s->budget--) { s->failed_pc=0x0c07c740u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07c742;
P_0c07c742: /* original 8b0d, guest PC 0x0c07c742 */
if(!s->budget--) { s->failed_pc=0x0c07c742u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c760; }
goto P_0c07c744;
P_0c07c744: /* original d330, guest PC 0x0c07c744 */
if(!s->budget--) { s->failed_pc=0x0c07c744u; return 0; }
r[3]=read(ram,0x0c07c808u,4);
goto P_0c07c746;
P_0c07c746: /* original 54f2, guest PC 0x0c07c746 */
if(!s->budget--) { s->failed_pc=0x0c07c746u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07c748;
P_0c07c748: /* original 430b, guest PC 0x0c07c748 */
if(!s->budget--) { s->failed_pc=0x0c07c748u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c74cu;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c74cu) { target=s->pc; goto dispatch; }
goto P_0c07c74c;
P_0c07c74a: /* original 7412, guest PC 0x0c07c74a */
if(!s->budget--) { s->failed_pc=0x0c07c74au; return 0; }
r[4]+=0x00000012u;
goto P_0c07c74c;
P_0c07c74c: /* original 600c, guest PC 0x0c07c74c */
if(!s->budget--) { s->failed_pc=0x0c07c74cu; return 0; }
r[0]=r[0]&255u;
goto P_0c07c74e;
P_0c07c74e: /* original 2008, guest PC 0x0c07c74e */
if(!s->budget--) { s->failed_pc=0x0c07c74eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07c750;
P_0c07c750: /* original 8b01, guest PC 0x0c07c750 */
if(!s->budget--) { s->failed_pc=0x0c07c750u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c756; }
goto P_0c07c752;
P_0c07c752: /* original a001, guest PC 0x0c07c752 */
if(!s->budget--) { s->failed_pc=0x0c07c752u; return 0; }
r[5]=0x0000000bu;
goto P_0c07c758;
P_0c07c754: /* original e50b, guest PC 0x0c07c754 */
if(!s->budget--) { s->failed_pc=0x0c07c754u; return 0; }
r[5]=0x0000000bu;
goto P_0c07c756;
P_0c07c756: /* original e50a, guest PC 0x0c07c756 */
if(!s->budget--) { s->failed_pc=0x0c07c756u; return 0; }
r[5]=0x0000000au;
goto P_0c07c758;
P_0c07c758: /* original d32c, guest PC 0x0c07c758 */
if(!s->budget--) { s->failed_pc=0x0c07c758u; return 0; }
r[3]=read(ram,0x0c07c80cu,4);
goto P_0c07c75a;
P_0c07c75a: /* original 943f, guest PC 0x0c07c75a */
if(!s->budget--) { s->failed_pc=0x0c07c75au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7dcu,2);
goto P_0c07c75c;
P_0c07c75c: /* original 430b, guest PC 0x0c07c75c */
if(!s->budget--) { s->failed_pc=0x0c07c75cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c760u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c760u) { target=s->pc; goto dispatch; }
goto P_0c07c760;
P_0c07c75e: /* original 34ec, guest PC 0x0c07c75e */
if(!s->budget--) { s->failed_pc=0x0c07c75eu; return 0; }
r[4]+=r[14];
goto P_0c07c760;
P_0c07c760: /* original d22b, guest PC 0x0c07c760 */
if(!s->budget--) { s->failed_pc=0x0c07c760u; return 0; }
r[2]=read(ram,0x0c07c810u,4);
goto P_0c07c762;
P_0c07c762: /* original 420b, guest PC 0x0c07c762 */
if(!s->budget--) { s->failed_pc=0x0c07c762u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c766u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c766u) { target=s->pc; goto dispatch; }
goto P_0c07c766;
P_0c07c764: /* original 0009, guest PC 0x0c07c764 */
if(!s->budget--) { s->failed_pc=0x0c07c764u; return 0; }
goto P_0c07c766;
P_0c07c766: /* original 64f2, guest PC 0x0c07c766 */
if(!s->budget--) { s->failed_pc=0x0c07c766u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07c768;
P_0c07c768: /* original 55f1, guest PC 0x0c07c768 */
if(!s->budget--) { s->failed_pc=0x0c07c768u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07c76a;
P_0c07c76a: /* original 7f0c, guest PC 0x0c07c76a */
if(!s->budget--) { s->failed_pc=0x0c07c76au; return 0; }
r[15]+=0x0000000cu;
goto P_0c07c76c;
P_0c07c76c: /* original 4f26, guest PC 0x0c07c76c */
if(!s->budget--) { s->failed_pc=0x0c07c76cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c76e;
P_0c07c76e: /* original a95b, guest PC 0x0c07c76e */
if(!s->budget--) { s->failed_pc=0x0c07c76eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ba28;
P_0c07c770: /* original 6ef6, guest PC 0x0c07c770 */
if(!s->budget--) { s->failed_pc=0x0c07c770u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07c772u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c772u; return 0; } return 1;
P_0c07fbec: /* original 4f22, guest PC 0x0c07fbec */
if(!s->budget--) { s->failed_pc=0x0c07fbecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07fbee;
P_0c07fbee: /* original 7ff4, guest PC 0x0c07fbee */
if(!s->budget--) { s->failed_pc=0x0c07fbeeu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07fbf0;
P_0c07fbf0: /* original 2f42, guest PC 0x0c07fbf0 */
if(!s->budget--) { s->failed_pc=0x0c07fbf0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07fbf2;
P_0c07fbf2: /* original 1f51, guest PC 0x0c07fbf2 */
if(!s->budget--) { s->failed_pc=0x0c07fbf2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07fbf4;
P_0c07fbf4: /* original 63f2, guest PC 0x0c07fbf4 */
if(!s->budget--) { s->failed_pc=0x0c07fbf4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07fbf6;
P_0c07fbf6: /* original 1f32, guest PC 0x0c07fbf6 */
if(!s->budget--) { s->failed_pc=0x0c07fbf6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07fbf8;
P_0c07fbf8: /* original e3ff, guest PC 0x0c07fbf8 */
if(!s->budget--) { s->failed_pc=0x0c07fbf8u; return 0; }
r[3]=0xffffffffu;
goto P_0c07fbfa;
P_0c07fbfa: /* original dd21, guest PC 0x0c07fbfa */
if(!s->budget--) { s->failed_pc=0x0c07fbfau; return 0; }
r[13]=read(ram,0x0c07fc80u,4);
goto P_0c07fbfc;
P_0c07fbfc: /* original 9039, guest PC 0x0c07fbfc */
if(!s->budget--) { s->failed_pc=0x0c07fbfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc72u,2);
goto P_0c07fbfe;
P_0c07fbfe: /* original 64d3, guest PC 0x0c07fbfe */
if(!s->budget--) { s->failed_pc=0x0c07fbfeu; return 0; }
r[4]=r[13];
goto P_0c07fc00;
P_0c07fc00: /* original 0d36, guest PC 0x0c07fc00 */
if(!s->budget--) { s->failed_pc=0x0c07fc00u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c07fc02;
P_0c07fc02: /* original 60e3, guest PC 0x0c07fc02 */
if(!s->budget--) { s->failed_pc=0x0c07fc02u; return 0; }
r[0]=r[14];
goto P_0c07fc04;
P_0c07fc04: /* original 814a, guest PC 0x0c07fc04 */
if(!s->budget--) { s->failed_pc=0x0c07fc04u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c07fc06;
P_0c07fc06: /* original 814b, guest PC 0x0c07fc06 */
if(!s->budget--) { s->failed_pc=0x0c07fc06u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c07fc08;
P_0c07fc08: /* original dc1e, guest PC 0x0c07fc08 */
if(!s->budget--) { s->failed_pc=0x0c07fc08u; return 0; }
r[12]=read(ram,0x0c07fc84u,4);
goto P_0c07fc0a;
P_0c07fc0a: /* original 1c06, guest PC 0x0c07fc0a */
if(!s->budget--) { s->failed_pc=0x0c07fc0au; return 0; }
write(ram,r[12]+24,r[0],4);
goto P_0c07fc0c;
P_0c07fc0c: /* original d21f, guest PC 0x0c07fc0c */
if(!s->budget--) { s->failed_pc=0x0c07fc0cu; return 0; }
r[2]=read(ram,0x0c07fc8cu,4);
goto P_0c07fc0e;
P_0c07fc0e: /* original d31e, guest PC 0x0c07fc0e */
if(!s->budget--) { s->failed_pc=0x0c07fc0eu; return 0; }
r[3]=read(ram,0x0c07fc88u,4);
goto P_0c07fc10;
P_0c07fc10: /* original 420b, guest PC 0x0c07fc10 */
if(!s->budget--) { s->failed_pc=0x0c07fc10u; return 0; }
target=r[2];
r[16]=code_base|0x0c07fc14u;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fc14u) { target=s->pc; goto dispatch; }
goto P_0c07fc14;
P_0c07fc12: /* original 6432, guest PC 0x0c07fc12 */
if(!s->budget--) { s->failed_pc=0x0c07fc12u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c07fc14;
P_0c07fc14: /* original 962e, guest PC 0x0c07fc14 */
if(!s->budget--) { s->failed_pc=0x0c07fc14u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc74u,2);
goto P_0c07fc16;
P_0c07fc16: /* original 942e, guest PC 0x0c07fc16 */
if(!s->budget--) { s->failed_pc=0x0c07fc16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc76u,2);
goto P_0c07fc18;
P_0c07fc18: /* original d31d, guest PC 0x0c07fc18 */
if(!s->budget--) { s->failed_pc=0x0c07fc18u; return 0; }
r[3]=read(ram,0x0c07fc90u,4);
goto P_0c07fc1a;
P_0c07fc1a: /* original 36dc, guest PC 0x0c07fc1a */
if(!s->budget--) { s->failed_pc=0x0c07fc1au; return 0; }
r[6]+=r[13];
goto P_0c07fc1c;
P_0c07fc1c: /* original 430b, guest PC 0x0c07fc1c */
if(!s->budget--) { s->failed_pc=0x0c07fc1cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07fc20u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fc20u) { target=s->pc; goto dispatch; }
goto P_0c07fc20;
P_0c07fc1e: /* original 65d3, guest PC 0x0c07fc1e */
if(!s->budget--) { s->failed_pc=0x0c07fc1eu; return 0; }
r[5]=r[13];
goto P_0c07fc20;
P_0c07fc20: /* original d21c, guest PC 0x0c07fc20 */
if(!s->budget--) { s->failed_pc=0x0c07fc20u; return 0; }
r[2]=read(ram,0x0c07fc94u,4);
goto P_0c07fc22;
P_0c07fc22: /* original 9427, guest PC 0x0c07fc22 */
if(!s->budget--) { s->failed_pc=0x0c07fc22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07fc74u,2);
goto P_0c07fc24;
P_0c07fc24: /* original 420b, guest PC 0x0c07fc24 */
if(!s->budget--) { s->failed_pc=0x0c07fc24u; return 0; }
target=r[2];
r[16]=code_base|0x0c07fc28u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fc28u) { target=s->pc; goto dispatch; }
goto P_0c07fc28;
P_0c07fc26: /* original 34dc, guest PC 0x0c07fc26 */
if(!s->budget--) { s->failed_pc=0x0c07fc26u; return 0; }
r[4]+=r[13];
goto P_0c07fc28;
P_0c07fc28: /* original e01c, guest PC 0x0c07fc28 */
if(!s->budget--) { s->failed_pc=0x0c07fc28u; return 0; }
r[0]=0x0000001cu;
goto P_0c07fc2a;
P_0c07fc2a: /* original 1ce6, guest PC 0x0c07fc2a */
if(!s->budget--) { s->failed_pc=0x0c07fc2au; return 0; }
write(ram,r[12]+24,r[14],4);
goto P_0c07fc2c;
P_0c07fc2c: /* original 0ce4, guest PC 0x0c07fc2c */
if(!s->budget--) { s->failed_pc=0x0c07fc2cu; return 0; }
write(ram,r[12]+r[0],r[14],1);
goto P_0c07fc2e;
P_0c07fc2e: /* original e010, guest PC 0x0c07fc2e */
if(!s->budget--) { s->failed_pc=0x0c07fc2eu; return 0; }
r[0]=0x00000010u;
goto P_0c07fc30;
P_0c07fc30: /* original 03cc, guest PC 0x0c07fc30 */
if(!s->budget--) { s->failed_pc=0x0c07fc30u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07fc32;
P_0c07fc32: /* original d419, guest PC 0x0c07fc32 */
if(!s->budget--) { s->failed_pc=0x0c07fc32u; return 0; }
r[4]=read(ram,0x0c07fc98u,4);
goto P_0c07fc34;
P_0c07fc34: /* original d219, guest PC 0x0c07fc34 */
if(!s->budget--) { s->failed_pc=0x0c07fc34u; return 0; }
r[2]=read(ram,0x0c07fc9cu,4);
goto P_0c07fc36;
P_0c07fc36: /* original 7301, guest PC 0x0c07fc36 */
if(!s->budget--) { s->failed_pc=0x0c07fc36u; return 0; }
r[3]+=0x00000001u;
goto P_0c07fc38;
P_0c07fc38: /* original 420b, guest PC 0x0c07fc38 */
if(!s->budget--) { s->failed_pc=0x0c07fc38u; return 0; }
target=r[2];
r[16]=code_base|0x0c07fc3cu;
write(ram,r[12]+r[0],r[3],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07fc3cu) { target=s->pc; goto dispatch; }
goto P_0c07fc3c;
P_0c07fc3a: /* original 0c34, guest PC 0x0c07fc3a */
if(!s->budget--) { s->failed_pc=0x0c07fc3au; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c07fc3c;
P_0c07fc3c: /* original 53f2, guest PC 0x0c07fc3c */
if(!s->budget--) { s->failed_pc=0x0c07fc3cu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07fc3e;
P_0c07fc3e: /* original d218, guest PC 0x0c07fc3e */
if(!s->budget--) { s->failed_pc=0x0c07fc3eu; return 0; }
r[2]=read(ram,0x0c07fca0u,4);
goto P_0c07fc40;
P_0c07fc40: /* original 1324, guest PC 0x0c07fc40 */
if(!s->budget--) { s->failed_pc=0x0c07fc40u; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c07fc42;
P_0c07fc42: /* original 55f1, guest PC 0x0c07fc42 */
if(!s->budget--) { s->failed_pc=0x0c07fc42u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07fc44;
P_0c07fc44: /* original 64f2, guest PC 0x0c07fc44 */
if(!s->budget--) { s->failed_pc=0x0c07fc44u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07fc46;
P_0c07fc46: /* original 7f0c, guest PC 0x0c07fc46 */
if(!s->budget--) { s->failed_pc=0x0c07fc46u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07fc48;
P_0c07fc48: /* original 4f26, guest PC 0x0c07fc48 */
if(!s->budget--) { s->failed_pc=0x0c07fc48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07fc4a;
P_0c07fc4a: /* original d30c, guest PC 0x0c07fc4a */
if(!s->budget--) { s->failed_pc=0x0c07fc4au; return 0; }
r[3]=read(ram,0x0c07fc7cu,4);
goto P_0c07fc4c;
P_0c07fc4c: /* original 6cf6, guest PC 0x0c07fc4c */
if(!s->budget--) { s->failed_pc=0x0c07fc4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07fc4e;
P_0c07fc4e: /* original 6df6, guest PC 0x0c07fc4e */
if(!s->budget--) { s->failed_pc=0x0c07fc4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07fc50;
P_0c07fc50: /* original 432b, guest PC 0x0c07fc50 */
if(!s->budget--) { s->failed_pc=0x0c07fc50u; return 0; }
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
P_0c07fc52: /* original 6ef6, guest PC 0x0c07fc52 */
if(!s->budget--) { s->failed_pc=0x0c07fc52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07fc54u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07fc54u; return 0; } return 1;
P_0c08430e: /* original 4f22, guest PC 0x0c08430e */
if(!s->budget--) { s->failed_pc=0x0c08430eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084310;
P_0c084310: /* original d335, guest PC 0x0c084310 */
if(!s->budget--) { s->failed_pc=0x0c084310u; return 0; }
r[3]=read(ram,0x0c0843e8u,4);
goto P_0c084312;
P_0c084312: /* original de34, guest PC 0x0c084312 */
if(!s->budget--) { s->failed_pc=0x0c084312u; return 0; }
r[14]=read(ram,0x0c0843e4u,4);
goto P_0c084314;
P_0c084314: /* original 430b, guest PC 0x0c084314 */
if(!s->budget--) { s->failed_pc=0x0c084314u; return 0; }
target=r[3];
r[16]=code_base|0x0c084318u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084318u) { target=s->pc; goto dispatch; }
goto P_0c084318;
P_0c084316: /* original 0009, guest PC 0x0c084316 */
if(!s->budget--) { s->failed_pc=0x0c084316u; return 0; }
goto P_0c084318;
P_0c084318: /* original d234, guest PC 0x0c084318 */
if(!s->budget--) { s->failed_pc=0x0c084318u; return 0; }
r[2]=read(ram,0x0c0843ecu,4);
goto P_0c08431a;
P_0c08431a: /* original 420b, guest PC 0x0c08431a */
if(!s->budget--) { s->failed_pc=0x0c08431au; return 0; }
target=r[2];
r[16]=code_base|0x0c08431eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08431eu) { target=s->pc; goto dispatch; }
goto P_0c08431e;
P_0c08431c: /* original e400, guest PC 0x0c08431c */
if(!s->budget--) { s->failed_pc=0x0c08431cu; return 0; }
r[4]=0x00000000u;
goto P_0c08431e;
P_0c08431e: /* original d334, guest PC 0x0c08431e */
if(!s->budget--) { s->failed_pc=0x0c08431eu; return 0; }
r[3]=read(ram,0x0c0843f0u,4);
goto P_0c084320;
P_0c084320: /* original 430b, guest PC 0x0c084320 */
if(!s->budget--) { s->failed_pc=0x0c084320u; return 0; }
target=r[3];
r[16]=code_base|0x0c084324u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084324u) { target=s->pc; goto dispatch; }
goto P_0c084324;
P_0c084322: /* original e401, guest PC 0x0c084322 */
if(!s->budget--) { s->failed_pc=0x0c084322u; return 0; }
r[4]=0x00000001u;
goto P_0c084324;
P_0c084324: /* original d233, guest PC 0x0c084324 */
if(!s->budget--) { s->failed_pc=0x0c084324u; return 0; }
r[2]=read(ram,0x0c0843f4u,4);
goto P_0c084326;
P_0c084326: /* original 420b, guest PC 0x0c084326 */
if(!s->budget--) { s->failed_pc=0x0c084326u; return 0; }
target=r[2];
r[16]=code_base|0x0c08432au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08432au) { target=s->pc; goto dispatch; }
goto P_0c08432a;
P_0c084328: /* original e400, guest PC 0x0c084328 */
if(!s->budget--) { s->failed_pc=0x0c084328u; return 0; }
r[4]=0x00000000u;
goto P_0c08432a;
P_0c08432a: /* original d333, guest PC 0x0c08432a */
if(!s->budget--) { s->failed_pc=0x0c08432au; return 0; }
r[3]=read(ram,0x0c0843f8u,4);
goto P_0c08432c;
P_0c08432c: /* original e502, guest PC 0x0c08432c */
if(!s->budget--) { s->failed_pc=0x0c08432cu; return 0; }
r[5]=0x00000002u;
goto P_0c08432e;
P_0c08432e: /* original 430b, guest PC 0x0c08432e */
if(!s->budget--) { s->failed_pc=0x0c08432eu; return 0; }
target=r[3];
r[16]=code_base|0x0c084332u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084332u) { target=s->pc; goto dispatch; }
goto P_0c084332;
P_0c084330: /* original e403, guest PC 0x0c084330 */
if(!s->budget--) { s->failed_pc=0x0c084330u; return 0; }
r[4]=0x00000003u;
goto P_0c084332;
P_0c084332: /* original d234, guest PC 0x0c084332 */
if(!s->budget--) { s->failed_pc=0x0c084332u; return 0; }
r[2]=read(ram,0x0c084404u,4);
goto P_0c084334;
P_0c084334: /* original e500, guest PC 0x0c084334 */
if(!s->budget--) { s->failed_pc=0x0c084334u; return 0; }
r[5]=0x00000000u;
goto P_0c084336;
P_0c084336: /* original d632, guest PC 0x0c084336 */
if(!s->budget--) { s->failed_pc=0x0c084336u; return 0; }
r[6]=read(ram,0x0c084400u,4);
goto P_0c084338;
P_0c084338: /* original d730, guest PC 0x0c084338 */
if(!s->budget--) { s->failed_pc=0x0c084338u; return 0; }
r[7]=read(ram,0x0c0843fcu,4);
goto P_0c08433a;
P_0c08433a: /* original 420b, guest PC 0x0c08433a */
if(!s->budget--) { s->failed_pc=0x0c08433au; return 0; }
target=r[2];
r[16]=code_base|0x0c08433eu;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08433eu) { target=s->pc; goto dispatch; }
goto P_0c08433e;
P_0c08433c: /* original 6453, guest PC 0x0c08433c */
if(!s->budget--) { s->failed_pc=0x0c08433cu; return 0; }
r[4]=r[5];
goto P_0c08433e;
P_0c08433e: /* original 954a, guest PC 0x0c08433e */
if(!s->budget--) { s->failed_pc=0x0c08433eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843d6u,2);
goto P_0c084340;
P_0c084340: /* original dc31, guest PC 0x0c084340 */
if(!s->budget--) { s->failed_pc=0x0c084340u; return 0; }
r[12]=read(ram,0x0c084408u,4);
goto P_0c084342;
P_0c084342: /* original 6453, guest PC 0x0c084342 */
if(!s->budget--) { s->failed_pc=0x0c084342u; return 0; }
r[4]=r[5];
goto P_0c084344;
P_0c084344: /* original 4c0b, guest PC 0x0c084344 */
if(!s->budget--) { s->failed_pc=0x0c084344u; return 0; }
target=r[12];
r[16]=code_base|0x0c084348u;
r[4]+=0xffffffe0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084348u) { target=s->pc; goto dispatch; }
goto P_0c084348;
P_0c084346: /* original 74e0, guest PC 0x0c084346 */
if(!s->budget--) { s->failed_pc=0x0c084346u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c084348;
P_0c084348: /* original d331, guest PC 0x0c084348 */
if(!s->budget--) { s->failed_pc=0x0c084348u; return 0; }
r[3]=read(ram,0x0c084410u,4);
goto P_0c08434a;
P_0c08434a: /* original dd30, guest PC 0x0c08434a */
if(!s->budget--) { s->failed_pc=0x0c08434au; return 0; }
r[13]=read(ram,0x0c08440cu,4);
goto P_0c08434c;
P_0c08434c: /* original 4d0b, guest PC 0x0c08434c */
if(!s->budget--) { s->failed_pc=0x0c08434cu; return 0; }
target=r[13];
r[16]=code_base|0x0c084350u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084350u) { target=s->pc; goto dispatch; }
goto P_0c084350;
P_0c08434e: /* original 2f36, guest PC 0x0c08434e */
if(!s->budget--) { s->failed_pc=0x0c08434eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084350;
P_0c084350: /* original 9542, guest PC 0x0c084350 */
if(!s->budget--) { s->failed_pc=0x0c084350u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843d8u,2);
goto P_0c084352;
P_0c084352: /* original 4c0b, guest PC 0x0c084352 */
if(!s->budget--) { s->failed_pc=0x0c084352u; return 0; }
target=r[12];
r[16]=code_base|0x0c084356u;
r[4]=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084356u) { target=s->pc; goto dispatch; }
goto P_0c084356;
P_0c084354: /* original e434, guest PC 0x0c084354 */
if(!s->budget--) { s->failed_pc=0x0c084354u; return 0; }
r[4]=0x00000034u;
goto P_0c084356;
P_0c084356: /* original d22f, guest PC 0x0c084356 */
if(!s->budget--) { s->failed_pc=0x0c084356u; return 0; }
r[2]=read(ram,0x0c084414u,4);
goto P_0c084358;
P_0c084358: /* original 4d0b, guest PC 0x0c084358 */
if(!s->budget--) { s->failed_pc=0x0c084358u; return 0; }
target=r[13];
r[16]=code_base|0x0c08435cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08435cu) { target=s->pc; goto dispatch; }
goto P_0c08435c;
P_0c08435a: /* original 2f26, guest PC 0x0c08435a */
if(!s->budget--) { s->failed_pc=0x0c08435au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08435c;
P_0c08435c: /* original 943e, guest PC 0x0c08435c */
if(!s->budget--) { s->failed_pc=0x0c08435cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843dcu,2);
goto P_0c08435e;
P_0c08435e: /* original 953c, guest PC 0x0c08435e */
if(!s->budget--) { s->failed_pc=0x0c08435eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843dau,2);
goto P_0c084360;
P_0c084360: /* original 4c0b, guest PC 0x0c084360 */
if(!s->budget--) { s->failed_pc=0x0c084360u; return 0; }
target=r[12];
r[16]=code_base|0x0c084364u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084364u) { target=s->pc; goto dispatch; }
goto P_0c084364;
P_0c084362: /* original 0009, guest PC 0x0c084362 */
if(!s->budget--) { s->failed_pc=0x0c084362u; return 0; }
goto P_0c084364;
P_0c084364: /* original d32c, guest PC 0x0c084364 */
if(!s->budget--) { s->failed_pc=0x0c084364u; return 0; }
r[3]=read(ram,0x0c084418u,4);
goto P_0c084366;
P_0c084366: /* original 4d0b, guest PC 0x0c084366 */
if(!s->budget--) { s->failed_pc=0x0c084366u; return 0; }
target=r[13];
r[16]=code_base|0x0c08436au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08436au) { target=s->pc; goto dispatch; }
goto P_0c08436a;
P_0c084368: /* original 2f36, guest PC 0x0c084368 */
if(!s->budget--) { s->failed_pc=0x0c084368u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08436a;
P_0c08436a: /* original d22c, guest PC 0x0c08436a */
if(!s->budget--) { s->failed_pc=0x0c08436au; return 0; }
r[2]=read(ram,0x0c08441cu,4);
goto P_0c08436c;
P_0c08436c: /* original 7f0c, guest PC 0x0c08436c */
if(!s->budget--) { s->failed_pc=0x0c08436cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c08436e;
P_0c08436e: /* original 420b, guest PC 0x0c08436e */
if(!s->budget--) { s->failed_pc=0x0c08436eu; return 0; }
target=r[2];
r[16]=code_base|0x0c084372u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084372u) { target=s->pc; goto dispatch; }
goto P_0c084372;
P_0c084370: /* original e403, guest PC 0x0c084370 */
if(!s->budget--) { s->failed_pc=0x0c084370u; return 0; }
r[4]=0x00000003u;
goto P_0c084372;
P_0c084372: /* original d32b, guest PC 0x0c084372 */
if(!s->budget--) { s->failed_pc=0x0c084372u; return 0; }
r[3]=read(ram,0x0c084420u,4);
goto P_0c084374;
P_0c084374: /* original 430b, guest PC 0x0c084374 */
if(!s->budget--) { s->failed_pc=0x0c084374u; return 0; }
target=r[3];
r[16]=code_base|0x0c084378u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084378u) { target=s->pc; goto dispatch; }
goto P_0c084378;
P_0c084376: /* original 0009, guest PC 0x0c084376 */
if(!s->budget--) { s->failed_pc=0x0c084376u; return 0; }
goto P_0c084378;
P_0c084378: /* original 9031, guest PC 0x0c084378 */
if(!s->budget--) { s->failed_pc=0x0c084378u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843deu,2);
goto P_0c08437a;
P_0c08437a: /* original e600, guest PC 0x0c08437a */
if(!s->budget--) { s->failed_pc=0x0c08437au; return 0; }
r[6]=0x00000000u;
goto P_0c08437c;
P_0c08437c: /* original e204, guest PC 0x0c08437c */
if(!s->budget--) { s->failed_pc=0x0c08437cu; return 0; }
r[2]=0x00000004u;
goto P_0c08437e;
P_0c08437e: /* original 6563, guest PC 0x0c08437e */
if(!s->budget--) { s->failed_pc=0x0c08437eu; return 0; }
r[5]=r[6];
goto P_0c084380;
P_0c084380: /* original 0e26, guest PC 0x0c084380 */
if(!s->budget--) { s->failed_pc=0x0c084380u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c084382;
P_0c084382: /* original d320, guest PC 0x0c084382 */
if(!s->budget--) { s->failed_pc=0x0c084382u; return 0; }
r[3]=read(ram,0x0c084404u,4);
goto P_0c084384;
P_0c084384: /* original d71d, guest PC 0x0c084384 */
if(!s->budget--) { s->failed_pc=0x0c084384u; return 0; }
r[7]=read(ram,0x0c0843fcu,4);
goto P_0c084386;
P_0c084386: /* original 430b, guest PC 0x0c084386 */
if(!s->budget--) { s->failed_pc=0x0c084386u; return 0; }
target=r[3];
r[16]=code_base|0x0c08438au;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08438au) { target=s->pc; goto dispatch; }
goto P_0c08438a;
P_0c084388: /* original 6463, guest PC 0x0c084388 */
if(!s->budget--) { s->failed_pc=0x0c084388u; return 0; }
r[4]=r[6];
goto P_0c08438a;
P_0c08438a: /* original 4f26, guest PC 0x0c08438a */
if(!s->budget--) { s->failed_pc=0x0c08438au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08438c;
P_0c08438c: /* original e010, guest PC 0x0c08438c */
if(!s->budget--) { s->failed_pc=0x0c08438cu; return 0; }
r[0]=0x00000010u;
goto P_0c08438e;
P_0c08438e: /* original 02ec, guest PC 0x0c08438e */
if(!s->budget--) { s->failed_pc=0x0c08438eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c084390;
P_0c084390: /* original 7201, guest PC 0x0c084390 */
if(!s->budget--) { s->failed_pc=0x0c084390u; return 0; }
r[2]+=0x00000001u;
goto P_0c084392;
P_0c084392: /* original 0e24, guest PC 0x0c084392 */
if(!s->budget--) { s->failed_pc=0x0c084392u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c084394;
P_0c084394: /* original 6cf6, guest PC 0x0c084394 */
if(!s->budget--) { s->failed_pc=0x0c084394u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084396;
P_0c084396: /* original 6df6, guest PC 0x0c084396 */
if(!s->budget--) { s->failed_pc=0x0c084396u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084398;
P_0c084398: /* original 000b, guest PC 0x0c084398 */
if(!s->budget--) { s->failed_pc=0x0c084398u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08439a: /* original 6ef6, guest PC 0x0c08439a */
if(!s->budget--) { s->failed_pc=0x0c08439au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08439cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08439cu; return 0; } return 1;
P_0c089348: /* original 2fe6, guest PC 0x0c089348 */
if(!s->budget--) { s->failed_pc=0x0c089348u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08934a;
P_0c08934a: /* original 2fd6, guest PC 0x0c08934a */
if(!s->budget--) { s->failed_pc=0x0c08934au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08934c;
P_0c08934c: /* original 2fc6, guest PC 0x0c08934c */
if(!s->budget--) { s->failed_pc=0x0c08934cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08934e;
P_0c08934e: /* original 2fb6, guest PC 0x0c08934e */
if(!s->budget--) { s->failed_pc=0x0c08934eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089350;
P_0c089350: /* original 2fa6, guest PC 0x0c089350 */
if(!s->budget--) { s->failed_pc=0x0c089350u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089352;
P_0c089352: /* original fffb, guest PC 0x0c089352 */
if(!s->budget--) { s->failed_pc=0x0c089352u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c089354;
P_0c089354: /* original ffeb, guest PC 0x0c089354 */
if(!s->budget--) { s->failed_pc=0x0c089354u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c089356;
P_0c089356: /* original ffdb, guest PC 0x0c089356 */
if(!s->budget--) { s->failed_pc=0x0c089356u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c089358;
P_0c089358: /* original ffcb, guest PC 0x0c089358 */
if(!s->budget--) { s->failed_pc=0x0c089358u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
if(!vf3_matrix_family(0x0c08935au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08935au; return 0; } return 1;
P_0c0893c6: /* original 4f22, guest PC 0x0c0893c6 */
if(!s->budget--) { s->failed_pc=0x0c0893c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0893c8;
P_0c0893c8: /* original a014, guest PC 0x0c0893c8 */
if(!s->budget--) { s->failed_pc=0x0c0893c8u; return 0; }
r[13]=0x00000005u;
goto P_0c0893f4;
P_0c0893ca: /* original ed05, guest PC 0x0c0893ca */
if(!s->budget--) { s->failed_pc=0x0c0893cau; return 0; }
r[13]=0x00000005u;
if(!vf3_matrix_family(0x0c0893ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0893ccu; return 0; } return 1;
P_0c0893e4: /* original 64d3, guest PC 0x0c0893e4 */
if(!s->budget--) { s->failed_pc=0x0c0893e4u; return 0; }
r[4]=r[13];
goto P_0c0893e6;
P_0c0893e6: /* original 74ff, guest PC 0x0c0893e6 */
if(!s->budget--) { s->failed_pc=0x0c0893e6u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0893e8;
P_0c0893e8: /* original 63e3, guest PC 0x0c0893e8 */
if(!s->budget--) { s->failed_pc=0x0c0893e8u; return 0; }
r[3]=r[14];
goto P_0c0893ea;
P_0c0893ea: /* original 4408, guest PC 0x0c0893ea */
if(!s->budget--) { s->failed_pc=0x0c0893eau; return 0; }
r[4]<<=2;
goto P_0c0893ec;
P_0c0893ec: /* original 343c, guest PC 0x0c0893ec */
if(!s->budget--) { s->failed_pc=0x0c0893ecu; return 0; }
r[4]+=r[3];
goto P_0c0893ee;
P_0c0893ee: /* original bfab, guest PC 0x0c0893ee */
if(!s->budget--) { s->failed_pc=0x0c0893eeu; return 0; }
target=code_base|0x0c089348u; r[16]=code_base|0x0c0893f2u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0893f2u) { target=s->pc; goto dispatch; }
goto P_0c0893f2;
P_0c0893f0: /* original 6442, guest PC 0x0c0893f0 */
if(!s->budget--) { s->failed_pc=0x0c0893f0u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0893f2;
P_0c0893f2: /* original 7dff, guest PC 0x0c0893f2 */
if(!s->budget--) { s->failed_pc=0x0c0893f2u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0893f4;
P_0c0893f4: /* original 2dd8, guest PC 0x0c0893f4 */
if(!s->budget--) { s->failed_pc=0x0c0893f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0893f6;
P_0c0893f6: /* original 8bf5, guest PC 0x0c0893f6 */
if(!s->budget--) { s->failed_pc=0x0c0893f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0893e4; }
goto P_0c0893f8;
P_0c0893f8: /* original d10d, guest PC 0x0c0893f8 */
if(!s->budget--) { s->failed_pc=0x0c0893f8u; return 0; }
r[1]=read(ram,0x0c089430u,4);
goto P_0c0893fa;
P_0c0893fa: /* original d30c, guest PC 0x0c0893fa */
if(!s->budget--) { s->failed_pc=0x0c0893fau; return 0; }
r[3]=read(ram,0x0c08942cu,4);
goto P_0c0893fc;
P_0c0893fc: /* original 6212, guest PC 0x0c0893fc */
if(!s->budget--) { s->failed_pc=0x0c0893fcu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0893fe;
P_0c0893fe: /* original 2238, guest PC 0x0c0893fe */
if(!s->budget--) { s->failed_pc=0x0c0893feu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c089400;
P_0c089400: /* original 8b02, guest PC 0x0c089400 */
if(!s->budget--) { s->failed_pc=0x0c089400u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089408; }
goto P_0c089402;
P_0c089402: /* original 50e5, guest PC 0x0c089402 */
if(!s->budget--) { s->failed_pc=0x0c089402u; return 0; }
r[0]=read(ram,r[14]+20,4);
goto P_0c089404;
P_0c089404: /* original 7001, guest PC 0x0c089404 */
if(!s->budget--) { s->failed_pc=0x0c089404u; return 0; }
r[0]+=0x00000001u;
goto P_0c089406;
P_0c089406: /* original 1e05, guest PC 0x0c089406 */
if(!s->budget--) { s->failed_pc=0x0c089406u; return 0; }
write(ram,r[14]+20,r[0],4);
goto P_0c089408;
P_0c089408: /* original 50e5, guest PC 0x0c089408 */
if(!s->budget--) { s->failed_pc=0x0c089408u; return 0; }
r[0]=read(ram,r[14]+20,4);
goto P_0c08940a;
P_0c08940a: /* original 940c, guest PC 0x0c08940a */
if(!s->budget--) { s->failed_pc=0x0c08940au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089426u,2);
goto P_0c08940c;
P_0c08940c: /* original d309, guest PC 0x0c08940c */
if(!s->budget--) { s->failed_pc=0x0c08940cu; return 0; }
r[3]=read(ram,0x0c089434u,4);
goto P_0c08940e;
P_0c08940e: /* original c93f, guest PC 0x0c08940e */
if(!s->budget--) { s->failed_pc=0x0c08940eu; return 0; }
r[0]&=63u;
goto P_0c089410;
P_0c089410: /* original 430b, guest PC 0x0c089410 */
if(!s->budget--) { s->failed_pc=0x0c089410u; return 0; }
target=r[3];
r[16]=code_base|0x0c089414u;
r[4]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089414u) { target=s->pc; goto dispatch; }
goto P_0c089414;
P_0c089412: /* original 340c, guest PC 0x0c089412 */
if(!s->budget--) { s->failed_pc=0x0c089412u; return 0; }
r[4]+=r[0];
goto P_0c089414;
P_0c089414: /* original 4f26, guest PC 0x0c089414 */
if(!s->budget--) { s->failed_pc=0x0c089414u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089416;
P_0c089416: /* original 50e5, guest PC 0x0c089416 */
if(!s->budget--) { s->failed_pc=0x0c089416u; return 0; }
r[0]=read(ram,r[14]+20,4);
goto P_0c089418;
P_0c089418: /* original 9406, guest PC 0x0c089418 */
if(!s->budget--) { s->failed_pc=0x0c089418u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089428u,2);
goto P_0c08941a;
P_0c08941a: /* original 6df6, guest PC 0x0c08941a */
if(!s->budget--) { s->failed_pc=0x0c08941au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08941c;
P_0c08941c: /* original c97f, guest PC 0x0c08941c */
if(!s->budget--) { s->failed_pc=0x0c08941cu; return 0; }
r[0]&=127u;
goto P_0c08941e;
P_0c08941e: /* original d205, guest PC 0x0c08941e */
if(!s->budget--) { s->failed_pc=0x0c08941eu; return 0; }
r[2]=read(ram,0x0c089434u,4);
goto P_0c089420;
P_0c089420: /* original 340c, guest PC 0x0c089420 */
if(!s->budget--) { s->failed_pc=0x0c089420u; return 0; }
r[4]+=r[0];
goto P_0c089422;
P_0c089422: /* original 422b, guest PC 0x0c089422 */
if(!s->budget--) { s->failed_pc=0x0c089422u; return 0; }
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
P_0c089424: /* original 6ef6, guest PC 0x0c089424 */
if(!s->budget--) { s->failed_pc=0x0c089424u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c089426u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c089426u; return 0; } return 1;
P_0c090aa0: /* original 2fe6, guest PC 0x0c090aa0 */
if(!s->budget--) { s->failed_pc=0x0c090aa0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c090aa2;
P_0c090aa2: /* original 6e63, guest PC 0x0c090aa2 */
if(!s->budget--) { s->failed_pc=0x0c090aa2u; return 0; }
r[14]=r[6];
goto P_0c090aa4;
P_0c090aa4: /* original 2fd6, guest PC 0x0c090aa4 */
if(!s->budget--) { s->failed_pc=0x0c090aa4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c090aa6;
P_0c090aa6: /* original 6d43, guest PC 0x0c090aa6 */
if(!s->budget--) { s->failed_pc=0x0c090aa6u; return 0; }
r[13]=r[4];
goto P_0c090aa8;
P_0c090aa8: /* original 2fc6, guest PC 0x0c090aa8 */
if(!s->budget--) { s->failed_pc=0x0c090aa8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c090aaa;
P_0c090aaa: /* original 2fb6, guest PC 0x0c090aaa */
if(!s->budget--) { s->failed_pc=0x0c090aaau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c090aac;
P_0c090aac: /* original 2fa6, guest PC 0x0c090aac */
if(!s->budget--) { s->failed_pc=0x0c090aacu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c090aae;
P_0c090aae: /* original 6a73, guest PC 0x0c090aae */
if(!s->budget--) { s->failed_pc=0x0c090aaeu; return 0; }
r[10]=r[7];
if(!vf3_matrix_family(0x0c090ab0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c090ab0u; return 0; } return 1;
P_0c0910be: /* original 4f22, guest PC 0x0c0910be */
if(!s->budget--) { s->failed_pc=0x0c0910beu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0910c0;
P_0c0910c0: /* original d33f, guest PC 0x0c0910c0 */
if(!s->budget--) { s->failed_pc=0x0c0910c0u; return 0; }
r[3]=read(ram,0x0c0911c0u,4);
goto P_0c0910c2;
P_0c0910c2: /* original 7ffc, guest PC 0x0c0910c2 */
if(!s->budget--) { s->failed_pc=0x0c0910c2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0910c4;
P_0c0910c4: /* original 430b, guest PC 0x0c0910c4 */
if(!s->budget--) { s->failed_pc=0x0c0910c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0910c8u;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0910c8u) { target=s->pc; goto dispatch; }
goto P_0c0910c8;
P_0c0910c6: /* original 6e43, guest PC 0x0c0910c6 */
if(!s->budget--) { s->failed_pc=0x0c0910c6u; return 0; }
r[14]=r[4];
goto P_0c0910c8;
P_0c0910c8: /* original 54ec, guest PC 0x0c0910c8 */
if(!s->budget--) { s->failed_pc=0x0c0910c8u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c0910ca;
P_0c0910ca: /* original e240, guest PC 0x0c0910ca */
if(!s->budget--) { s->failed_pc=0x0c0910cau; return 0; }
r[2]=0x00000040u;
goto P_0c0910cc;
P_0c0910cc: /* original 6723, guest PC 0x0c0910cc */
if(!s->budget--) { s->failed_pc=0x0c0910ccu; return 0; }
r[7]=r[2];
goto P_0c0910ce;
P_0c0910ce: /* original 242b, guest PC 0x0c0910ce */
if(!s->budget--) { s->failed_pc=0x0c0910ceu; return 0; }
r[4]|=r[2];
goto P_0c0910d0;
P_0c0910d0: /* original 1e4c, guest PC 0x0c0910d0 */
if(!s->budget--) { s->failed_pc=0x0c0910d0u; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c0910d2;
P_0c0910d2: /* original 9071, guest PC 0x0c0910d2 */
if(!s->budget--) { s->failed_pc=0x0c0910d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0911b8u,2);
goto P_0c0910d4;
P_0c0910d4: /* original d33b, guest PC 0x0c0910d4 */
if(!s->budget--) { s->failed_pc=0x0c0910d4u; return 0; }
r[3]=read(ram,0x0c0911c4u,4);
goto P_0c0910d6;
P_0c0910d6: /* original 04ee, guest PC 0x0c0910d6 */
if(!s->budget--) { s->failed_pc=0x0c0910d6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0910d8;
P_0c0910d8: /* original d03b, guest PC 0x0c0910d8 */
if(!s->budget--) { s->failed_pc=0x0c0910d8u; return 0; }
r[0]=read(ram,0x0c0911c8u,4);
goto P_0c0910da;
P_0c0910da: /* original 4409, guest PC 0x0c0910da */
if(!s->budget--) { s->failed_pc=0x0c0910dau; return 0; }
r[4]>>=2;
goto P_0c0910dc;
P_0c0910dc: /* original 6532, guest PC 0x0c0910dc */
if(!s->budget--) { s->failed_pc=0x0c0910dcu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0910de;
P_0c0910de: /* original 4408, guest PC 0x0c0910de */
if(!s->budget--) { s->failed_pc=0x0c0910deu; return 0; }
r[4]<<=2;
goto P_0c0910e0;
P_0c0910e0: /* original 044e, guest PC 0x0c0910e0 */
if(!s->budget--) { s->failed_pc=0x0c0910e0u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0910e2;
P_0c0910e2: /* original e061, guest PC 0x0c0910e2 */
if(!s->budget--) { s->failed_pc=0x0c0910e2u; return 0; }
r[0]=0x00000061u;
goto P_0c0910e4;
P_0c0910e4: /* original 005c, guest PC 0x0c0910e4 */
if(!s->budget--) { s->failed_pc=0x0c0910e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0910e6;
P_0c0910e6: /* original 600c, guest PC 0x0c0910e6 */
if(!s->budget--) { s->failed_pc=0x0c0910e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0910e8;
P_0c0910e8: /* original 4000, guest PC 0x0c0910e8 */
if(!s->budget--) { s->failed_pc=0x0c0910e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0910ea;
P_0c0910ea: /* original 064d, guest PC 0x0c0910ea */
if(!s->budget--) { s->failed_pc=0x0c0910eau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0910ec;
P_0c0910ec: /* original 666d, guest PC 0x0c0910ec */
if(!s->budget--) { s->failed_pc=0x0c0910ecu; return 0; }
r[6]=r[6]&65535u;
goto P_0c0910ee;
P_0c0910ee: /* original 3468, guest PC 0x0c0910ee */
if(!s->budget--) { s->failed_pc=0x0c0910eeu; return 0; }
r[4]-=r[6];
goto P_0c0910f0;
P_0c0910f0: /* original 6643, guest PC 0x0c0910f0 */
if(!s->budget--) { s->failed_pc=0x0c0910f0u; return 0; }
r[6]=r[4];
goto P_0c0910f2;
P_0c0910f2: /* original 2f42, guest PC 0x0c0910f2 */
if(!s->budget--) { s->failed_pc=0x0c0910f2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0910f4;
P_0c0910f4: /* original bcd4, guest PC 0x0c0910f4 */
if(!s->budget--) { s->failed_pc=0x0c0910f4u; return 0; }
target=code_base|0x0c090aa0u; r[16]=code_base|0x0c0910f8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0910f8u) { target=s->pc; goto dispatch; }
goto P_0c0910f8;
P_0c0910f6: /* original 64e3, guest PC 0x0c0910f6 */
if(!s->budget--) { s->failed_pc=0x0c0910f6u; return 0; }
r[4]=r[14];
goto P_0c0910f8;
P_0c0910f8: /* original 7f04, guest PC 0x0c0910f8 */
if(!s->budget--) { s->failed_pc=0x0c0910f8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0910fa;
P_0c0910fa: /* original 905e, guest PC 0x0c0910fa */
if(!s->budget--) { s->failed_pc=0x0c0910fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0911bau,2);
goto P_0c0910fc;
P_0c0910fc: /* original 4f26, guest PC 0x0c0910fc */
if(!s->budget--) { s->failed_pc=0x0c0910fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0910fe;
P_0c0910fe: /* original e309, guest PC 0x0c0910fe */
if(!s->budget--) { s->failed_pc=0x0c0910feu; return 0; }
r[3]=0x00000009u;
goto P_0c091100;
P_0c091100: /* original 64e3, guest PC 0x0c091100 */
if(!s->budget--) { s->failed_pc=0x0c091100u; return 0; }
r[4]=r[14];
goto P_0c091102;
P_0c091102: /* original 0e34, guest PC 0x0c091102 */
if(!s->budget--) { s->failed_pc=0x0c091102u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c091104;
P_0c091104: /* original a000, guest PC 0x0c091104 */
if(!s->budget--) { s->failed_pc=0x0c091104u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091108;
P_0c091106: /* original 6ef6, guest PC 0x0c091106 */
if(!s->budget--) { s->failed_pc=0x0c091106u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091108;
P_0c091108: /* original 2fe6, guest PC 0x0c091108 */
if(!s->budget--) { s->failed_pc=0x0c091108u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09110a;
P_0c09110a: /* original d131, guest PC 0x0c09110a */
if(!s->budget--) { s->failed_pc=0x0c09110au; return 0; }
r[1]=read(ram,0x0c0911d0u,4);
goto P_0c09110c;
P_0c09110c: /* original 4f22, guest PC 0x0c09110c */
if(!s->budget--) { s->failed_pc=0x0c09110cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09110e;
P_0c09110e: /* original 6212, guest PC 0x0c09110e */
if(!s->budget--) { s->failed_pc=0x0c09110eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091110;
P_0c091110: /* original d32e, guest PC 0x0c091110 */
if(!s->budget--) { s->failed_pc=0x0c091110u; return 0; }
r[3]=read(ram,0x0c0911ccu,4);
goto P_0c091112;
P_0c091112: /* original 2238, guest PC 0x0c091112 */
if(!s->budget--) { s->failed_pc=0x0c091112u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091114;
P_0c091114: /* original 8f11, guest PC 0x0c091114 */
if(!s->budget--) { s->failed_pc=0x0c091114u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c09113a; }
goto P_0c091118;
P_0c091116: /* original 6e43, guest PC 0x0c091116 */
if(!s->budget--) { s->failed_pc=0x0c091116u; return 0; }
r[14]=r[4];
goto P_0c091118;
P_0c091118: /* original d32e, guest PC 0x0c091118 */
if(!s->budget--) { s->failed_pc=0x0c091118u; return 0; }
r[3]=read(ram,0x0c0911d4u,4);
goto P_0c09111a;
P_0c09111a: /* original 430b, guest PC 0x0c09111a */
if(!s->budget--) { s->failed_pc=0x0c09111au; return 0; }
target=r[3];
r[16]=code_base|0x0c09111eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09111eu) { target=s->pc; goto dispatch; }
goto P_0c09111e;
P_0c09111c: /* original 64e3, guest PC 0x0c09111c */
if(!s->budget--) { s->failed_pc=0x0c09111cu; return 0; }
r[4]=r[14];
goto P_0c09111e;
P_0c09111e: /* original d22e, guest PC 0x0c09111e */
if(!s->budget--) { s->failed_pc=0x0c09111eu; return 0; }
r[2]=read(ram,0x0c0911d8u,4);
goto P_0c091120;
P_0c091120: /* original 420b, guest PC 0x0c091120 */
if(!s->budget--) { s->failed_pc=0x0c091120u; return 0; }
target=r[2];
r[16]=code_base|0x0c091124u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091124u) { target=s->pc; goto dispatch; }
goto P_0c091124;
P_0c091122: /* original 64e3, guest PC 0x0c091122 */
if(!s->budget--) { s->failed_pc=0x0c091122u; return 0; }
r[4]=r[14];
goto P_0c091124;
P_0c091124: /* original d32d, guest PC 0x0c091124 */
if(!s->budget--) { s->failed_pc=0x0c091124u; return 0; }
r[3]=read(ram,0x0c0911dcu,4);
goto P_0c091126;
P_0c091126: /* original 430b, guest PC 0x0c091126 */
if(!s->budget--) { s->failed_pc=0x0c091126u; return 0; }
target=r[3];
r[16]=code_base|0x0c09112au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09112au) { target=s->pc; goto dispatch; }
goto P_0c09112a;
P_0c091128: /* original 64e3, guest PC 0x0c091128 */
if(!s->budget--) { s->failed_pc=0x0c091128u; return 0; }
r[4]=r[14];
goto P_0c09112a;
P_0c09112a: /* original bb59, guest PC 0x0c09112a */
if(!s->budget--) { s->failed_pc=0x0c09112au; return 0; }
target=code_base|0x0c0907e0u; r[16]=code_base|0x0c09112eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09112eu) { target=s->pc; goto dispatch; }
goto P_0c09112e;
P_0c09112c: /* original 64e3, guest PC 0x0c09112c */
if(!s->budget--) { s->failed_pc=0x0c09112cu; return 0; }
r[4]=r[14];
goto P_0c09112e;
P_0c09112e: /* original d32c, guest PC 0x0c09112e */
if(!s->budget--) { s->failed_pc=0x0c09112eu; return 0; }
r[3]=read(ram,0x0c0911e0u,4);
goto P_0c091130;
P_0c091130: /* original 430b, guest PC 0x0c091130 */
if(!s->budget--) { s->failed_pc=0x0c091130u; return 0; }
target=r[3];
r[16]=code_base|0x0c091134u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091134u) { target=s->pc; goto dispatch; }
goto P_0c091134;
P_0c091132: /* original 64e3, guest PC 0x0c091132 */
if(!s->budget--) { s->failed_pc=0x0c091132u; return 0; }
r[4]=r[14];
goto P_0c091134;
P_0c091134: /* original d22b, guest PC 0x0c091134 */
if(!s->budget--) { s->failed_pc=0x0c091134u; return 0; }
r[2]=read(ram,0x0c0911e4u,4);
goto P_0c091136;
P_0c091136: /* original 420b, guest PC 0x0c091136 */
if(!s->budget--) { s->failed_pc=0x0c091136u; return 0; }
target=r[2];
r[16]=code_base|0x0c09113au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09113au) { target=s->pc; goto dispatch; }
goto P_0c09113a;
P_0c091138: /* original 64e3, guest PC 0x0c091138 */
if(!s->budget--) { s->failed_pc=0x0c091138u; return 0; }
r[4]=r[14];
goto P_0c09113a;
P_0c09113a: /* original 4f26, guest PC 0x0c09113a */
if(!s->budget--) { s->failed_pc=0x0c09113au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09113c;
P_0c09113c: /* original 000b, guest PC 0x0c09113c */
if(!s->budget--) { s->failed_pc=0x0c09113cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09113e: /* original 6ef6, guest PC 0x0c09113e */
if(!s->budget--) { s->failed_pc=0x0c09113eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c091140u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091140u; return 0; } return 1;
P_0c091142: /* original 4f22, guest PC 0x0c091142 */
if(!s->budget--) { s->failed_pc=0x0c091142u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091144;
P_0c091144: /* original d31e, guest PC 0x0c091144 */
if(!s->budget--) { s->failed_pc=0x0c091144u; return 0; }
r[3]=read(ram,0x0c0911c0u,4);
goto P_0c091146;
P_0c091146: /* original 7ffc, guest PC 0x0c091146 */
if(!s->budget--) { s->failed_pc=0x0c091146u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c091148;
P_0c091148: /* original 430b, guest PC 0x0c091148 */
if(!s->budget--) { s->failed_pc=0x0c091148u; return 0; }
target=r[3];
r[16]=code_base|0x0c09114cu;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09114cu) { target=s->pc; goto dispatch; }
goto P_0c09114c;
P_0c09114a: /* original 6e43, guest PC 0x0c09114a */
if(!s->budget--) { s->failed_pc=0x0c09114au; return 0; }
r[14]=r[4];
goto P_0c09114c;
P_0c09114c: /* original e061, guest PC 0x0c09114c */
if(!s->budget--) { s->failed_pc=0x0c09114cu; return 0; }
r[0]=0x00000061u;
goto P_0c09114e;
P_0c09114e: /* original 9235, guest PC 0x0c09114e */
if(!s->budget--) { s->failed_pc=0x0c09114eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0911bcu,2);
goto P_0c091150;
P_0c091150: /* original 54ec, guest PC 0x0c091150 */
if(!s->budget--) { s->failed_pc=0x0c091150u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c091152;
P_0c091152: /* original 6723, guest PC 0x0c091152 */
if(!s->budget--) { s->failed_pc=0x0c091152u; return 0; }
r[7]=r[2];
goto P_0c091154;
P_0c091154: /* original 242b, guest PC 0x0c091154 */
if(!s->budget--) { s->failed_pc=0x0c091154u; return 0; }
r[4]|=r[2];
goto P_0c091156;
P_0c091156: /* original 1e4c, guest PC 0x0c091156 */
if(!s->budget--) { s->failed_pc=0x0c091156u; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c091158;
P_0c091158: /* original d323, guest PC 0x0c091158 */
if(!s->budget--) { s->failed_pc=0x0c091158u; return 0; }
r[3]=read(ram,0x0c0911e8u,4);
goto P_0c09115a;
P_0c09115a: /* original d624, guest PC 0x0c09115a */
if(!s->budget--) { s->failed_pc=0x0c09115au; return 0; }
r[6]=read(ram,0x0c0911ecu,4);
goto P_0c09115c;
P_0c09115c: /* original 6532, guest PC 0x0c09115c */
if(!s->budget--) { s->failed_pc=0x0c09115cu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c09115e;
P_0c09115e: /* original 005c, guest PC 0x0c09115e */
if(!s->budget--) { s->failed_pc=0x0c09115eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c091160;
P_0c091160: /* original 600c, guest PC 0x0c091160 */
if(!s->budget--) { s->failed_pc=0x0c091160u; return 0; }
r[0]=r[0]&255u;
goto P_0c091162;
P_0c091162: /* original 4000, guest PC 0x0c091162 */
if(!s->budget--) { s->failed_pc=0x0c091162u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091164;
P_0c091164: /* original 046d, guest PC 0x0c091164 */
if(!s->budget--) { s->failed_pc=0x0c091164u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c091166;
P_0c091166: /* original 644d, guest PC 0x0c091166 */
if(!s->budget--) { s->failed_pc=0x0c091166u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091168;
P_0c091168: /* original 3648, guest PC 0x0c091168 */
if(!s->budget--) { s->failed_pc=0x0c091168u; return 0; }
r[6]-=r[4];
goto P_0c09116a;
P_0c09116a: /* original 2f62, guest PC 0x0c09116a */
if(!s->budget--) { s->failed_pc=0x0c09116au; return 0; }
write(ram,r[15],r[6],4);
goto P_0c09116c;
P_0c09116c: /* original bc98, guest PC 0x0c09116c */
if(!s->budget--) { s->failed_pc=0x0c09116cu; return 0; }
target=code_base|0x0c090aa0u; r[16]=code_base|0x0c091170u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091170u) { target=s->pc; goto dispatch; }
goto P_0c091170;
P_0c09116e: /* original 64e3, guest PC 0x0c09116e */
if(!s->budget--) { s->failed_pc=0x0c09116eu; return 0; }
r[4]=r[14];
goto P_0c091170;
P_0c091170: /* original 7f04, guest PC 0x0c091170 */
if(!s->budget--) { s->failed_pc=0x0c091170u; return 0; }
r[15]+=0x00000004u;
goto P_0c091172;
P_0c091172: /* original 9022, guest PC 0x0c091172 */
if(!s->budget--) { s->failed_pc=0x0c091172u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0911bau,2);
goto P_0c091174;
P_0c091174: /* original 4f26, guest PC 0x0c091174 */
if(!s->budget--) { s->failed_pc=0x0c091174u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091176;
P_0c091176: /* original e30b, guest PC 0x0c091176 */
if(!s->budget--) { s->failed_pc=0x0c091176u; return 0; }
r[3]=0x0000000bu;
goto P_0c091178;
P_0c091178: /* original 64e3, guest PC 0x0c091178 */
if(!s->budget--) { s->failed_pc=0x0c091178u; return 0; }
r[4]=r[14];
goto P_0c09117a;
P_0c09117a: /* original 0e34, guest PC 0x0c09117a */
if(!s->budget--) { s->failed_pc=0x0c09117au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09117c;
P_0c09117c: /* original a000, guest PC 0x0c09117c */
if(!s->budget--) { s->failed_pc=0x0c09117cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091180;
P_0c09117e: /* original 6ef6, guest PC 0x0c09117e */
if(!s->budget--) { s->failed_pc=0x0c09117eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091180;
P_0c091180: /* original 2fe6, guest PC 0x0c091180 */
if(!s->budget--) { s->failed_pc=0x0c091180u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091182;
P_0c091182: /* original d113, guest PC 0x0c091182 */
if(!s->budget--) { s->failed_pc=0x0c091182u; return 0; }
r[1]=read(ram,0x0c0911d0u,4);
goto P_0c091184;
P_0c091184: /* original 4f22, guest PC 0x0c091184 */
if(!s->budget--) { s->failed_pc=0x0c091184u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091186;
P_0c091186: /* original 6212, guest PC 0x0c091186 */
if(!s->budget--) { s->failed_pc=0x0c091186u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091188;
P_0c091188: /* original d310, guest PC 0x0c091188 */
if(!s->budget--) { s->failed_pc=0x0c091188u; return 0; }
r[3]=read(ram,0x0c0911ccu,4);
goto P_0c09118a;
P_0c09118a: /* original 2238, guest PC 0x0c09118a */
if(!s->budget--) { s->failed_pc=0x0c09118au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09118c;
P_0c09118c: /* original 8f11, guest PC 0x0c09118c */
if(!s->budget--) { s->failed_pc=0x0c09118cu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c0911b2; }
goto P_0c091190;
P_0c09118e: /* original 6e43, guest PC 0x0c09118e */
if(!s->budget--) { s->failed_pc=0x0c09118eu; return 0; }
r[14]=r[4];
goto P_0c091190;
P_0c091190: /* original d310, guest PC 0x0c091190 */
if(!s->budget--) { s->failed_pc=0x0c091190u; return 0; }
r[3]=read(ram,0x0c0911d4u,4);
goto P_0c091192;
P_0c091192: /* original 430b, guest PC 0x0c091192 */
if(!s->budget--) { s->failed_pc=0x0c091192u; return 0; }
target=r[3];
r[16]=code_base|0x0c091196u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091196u) { target=s->pc; goto dispatch; }
goto P_0c091196;
P_0c091194: /* original 64e3, guest PC 0x0c091194 */
if(!s->budget--) { s->failed_pc=0x0c091194u; return 0; }
r[4]=r[14];
goto P_0c091196;
P_0c091196: /* original d210, guest PC 0x0c091196 */
if(!s->budget--) { s->failed_pc=0x0c091196u; return 0; }
r[2]=read(ram,0x0c0911d8u,4);
goto P_0c091198;
P_0c091198: /* original 420b, guest PC 0x0c091198 */
if(!s->budget--) { s->failed_pc=0x0c091198u; return 0; }
target=r[2];
r[16]=code_base|0x0c09119cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09119cu) { target=s->pc; goto dispatch; }
goto P_0c09119c;
P_0c09119a: /* original 64e3, guest PC 0x0c09119a */
if(!s->budget--) { s->failed_pc=0x0c09119au; return 0; }
r[4]=r[14];
goto P_0c09119c;
P_0c09119c: /* original d30f, guest PC 0x0c09119c */
if(!s->budget--) { s->failed_pc=0x0c09119cu; return 0; }
r[3]=read(ram,0x0c0911dcu,4);
goto P_0c09119e;
P_0c09119e: /* original 430b, guest PC 0x0c09119e */
if(!s->budget--) { s->failed_pc=0x0c09119eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0911a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911a2u) { target=s->pc; goto dispatch; }
goto P_0c0911a2;
P_0c0911a0: /* original 64e3, guest PC 0x0c0911a0 */
if(!s->budget--) { s->failed_pc=0x0c0911a0u; return 0; }
r[4]=r[14];
goto P_0c0911a2;
P_0c0911a2: /* original bb1d, guest PC 0x0c0911a2 */
if(!s->budget--) { s->failed_pc=0x0c0911a2u; return 0; }
target=code_base|0x0c0907e0u; r[16]=code_base|0x0c0911a6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911a6u) { target=s->pc; goto dispatch; }
goto P_0c0911a6;
P_0c0911a4: /* original 64e3, guest PC 0x0c0911a4 */
if(!s->budget--) { s->failed_pc=0x0c0911a4u; return 0; }
r[4]=r[14];
goto P_0c0911a6;
P_0c0911a6: /* original d30e, guest PC 0x0c0911a6 */
if(!s->budget--) { s->failed_pc=0x0c0911a6u; return 0; }
r[3]=read(ram,0x0c0911e0u,4);
goto P_0c0911a8;
P_0c0911a8: /* original 430b, guest PC 0x0c0911a8 */
if(!s->budget--) { s->failed_pc=0x0c0911a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0911acu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911acu) { target=s->pc; goto dispatch; }
goto P_0c0911ac;
P_0c0911aa: /* original 64e3, guest PC 0x0c0911aa */
if(!s->budget--) { s->failed_pc=0x0c0911aau; return 0; }
r[4]=r[14];
goto P_0c0911ac;
P_0c0911ac: /* original d20d, guest PC 0x0c0911ac */
if(!s->budget--) { s->failed_pc=0x0c0911acu; return 0; }
r[2]=read(ram,0x0c0911e4u,4);
goto P_0c0911ae;
P_0c0911ae: /* original 420b, guest PC 0x0c0911ae */
if(!s->budget--) { s->failed_pc=0x0c0911aeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0911b2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911b2u) { target=s->pc; goto dispatch; }
goto P_0c0911b2;
P_0c0911b0: /* original 64e3, guest PC 0x0c0911b0 */
if(!s->budget--) { s->failed_pc=0x0c0911b0u; return 0; }
r[4]=r[14];
goto P_0c0911b2;
P_0c0911b2: /* original 4f26, guest PC 0x0c0911b2 */
if(!s->budget--) { s->failed_pc=0x0c0911b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0911b4;
P_0c0911b4: /* original 000b, guest PC 0x0c0911b4 */
if(!s->budget--) { s->failed_pc=0x0c0911b4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0911b6: /* original 6ef6, guest PC 0x0c0911b6 */
if(!s->budget--) { s->failed_pc=0x0c0911b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0911b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0911b8u; return 0; } return 1;
P_0c0911f2: /* original 4f22, guest PC 0x0c0911f2 */
if(!s->budget--) { s->failed_pc=0x0c0911f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0911f4;
P_0c0911f4: /* original d33d, guest PC 0x0c0911f4 */
if(!s->budget--) { s->failed_pc=0x0c0911f4u; return 0; }
r[3]=read(ram,0x0c0912ecu,4);
goto P_0c0911f6;
P_0c0911f6: /* original 430b, guest PC 0x0c0911f6 */
if(!s->budget--) { s->failed_pc=0x0c0911f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0911fau;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0911fau) { target=s->pc; goto dispatch; }
goto P_0c0911fa;
P_0c0911f8: /* original 6e43, guest PC 0x0c0911f8 */
if(!s->budget--) { s->failed_pc=0x0c0911f8u; return 0; }
r[14]=r[4];
goto P_0c0911fa;
P_0c0911fa: /* original d33d, guest PC 0x0c0911fa */
if(!s->budget--) { s->failed_pc=0x0c0911fau; return 0; }
r[3]=read(ram,0x0c0912f0u,4);
goto P_0c0911fc;
P_0c0911fc: /* original 9072, guest PC 0x0c0911fc */
if(!s->budget--) { s->failed_pc=0x0c0911fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0912e4u,2);
goto P_0c0911fe;
P_0c0911fe: /* original 6532, guest PC 0x0c0911fe */
if(!s->budget--) { s->failed_pc=0x0c0911feu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c091200;
P_0c091200: /* original 54ec, guest PC 0x0c091200 */
if(!s->budget--) { s->failed_pc=0x0c091200u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c091202;
P_0c091202: /* original 926e, guest PC 0x0c091202 */
if(!s->budget--) { s->failed_pc=0x0c091202u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0912e2u,2);
goto P_0c091204;
P_0c091204: /* original 065e, guest PC 0x0c091204 */
if(!s->budget--) { s->failed_pc=0x0c091204u; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c091206;
P_0c091206: /* original 242b, guest PC 0x0c091206 */
if(!s->budget--) { s->failed_pc=0x0c091206u; return 0; }
r[4]|=r[2];
goto P_0c091208;
P_0c091208: /* original e204, guest PC 0x0c091208 */
if(!s->budget--) { s->failed_pc=0x0c091208u; return 0; }
r[2]=0x00000004u;
goto P_0c09120a;
P_0c09120a: /* original 2628, guest PC 0x0c09120a */
if(!s->budget--) { s->failed_pc=0x0c09120au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c09120c;
P_0c09120c: /* original 8b01, guest PC 0x0c09120c */
if(!s->budget--) { s->failed_pc=0x0c09120cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091212; }
goto P_0c09120e;
P_0c09120e: /* original 936a, guest PC 0x0c09120e */
if(!s->budget--) { s->failed_pc=0x0c09120eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0912e6u,2);
goto P_0c091210;
P_0c091210: /* original 243b, guest PC 0x0c091210 */
if(!s->budget--) { s->failed_pc=0x0c091210u; return 0; }
r[4]|=r[3];
goto P_0c091212;
P_0c091212: /* original e60f, guest PC 0x0c091212 */
if(!s->budget--) { s->failed_pc=0x0c091212u; return 0; }
r[6]=0x0000000fu;
goto P_0c091214;
P_0c091214: /* original 1e4c, guest PC 0x0c091214 */
if(!s->budget--) { s->failed_pc=0x0c091214u; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c091216;
P_0c091216: /* original d337, guest PC 0x0c091216 */
if(!s->budget--) { s->failed_pc=0x0c091216u; return 0; }
r[3]=read(ram,0x0c0912f4u,4);
goto P_0c091218;
P_0c091218: /* original d437, guest PC 0x0c091218 */
if(!s->budget--) { s->failed_pc=0x0c091218u; return 0; }
r[4]=read(ram,0x0c0912f8u,4);
goto P_0c09121a;
P_0c09121a: /* original 6030, guest PC 0x0c09121a */
if(!s->budget--) { s->failed_pc=0x0c09121au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c09121c;
P_0c09121c: /* original 6143, guest PC 0x0c09121c */
if(!s->budget--) { s->failed_pc=0x0c09121cu; return 0; }
r[1]=r[4];
goto P_0c09121e;
P_0c09121e: /* original 9760, guest PC 0x0c09121e */
if(!s->budget--) { s->failed_pc=0x0c09121eu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0912e2u,2);
goto P_0c091220;
P_0c091220: /* original 600c, guest PC 0x0c091220 */
if(!s->budget--) { s->failed_pc=0x0c091220u; return 0; }
r[0]=r[0]&255u;
goto P_0c091222;
P_0c091222: /* original 2609, guest PC 0x0c091222 */
if(!s->budget--) { s->failed_pc=0x0c091222u; return 0; }
r[6]&=r[0];
goto P_0c091224;
P_0c091224: /* original 6063, guest PC 0x0c091224 */
if(!s->budget--) { s->failed_pc=0x0c091224u; return 0; }
r[0]=r[6];
goto P_0c091226;
P_0c091226: /* original 4000, guest PC 0x0c091226 */
if(!s->budget--) { s->failed_pc=0x0c091226u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091228;
P_0c091228: /* original 024d, guest PC 0x0c091228 */
if(!s->budget--) { s->failed_pc=0x0c091228u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09122a;
P_0c09122a: /* original 662d, guest PC 0x0c09122a */
if(!s->budget--) { s->failed_pc=0x0c09122au; return 0; }
r[6]=r[2]&65535u;
goto P_0c09122c;
P_0c09122c: /* original 3168, guest PC 0x0c09122c */
if(!s->budget--) { s->failed_pc=0x0c09122cu; return 0; }
r[1]-=r[6];
goto P_0c09122e;
P_0c09122e: /* original 6613, guest PC 0x0c09122e */
if(!s->budget--) { s->failed_pc=0x0c09122eu; return 0; }
r[6]=r[1];
goto P_0c091230;
P_0c091230: /* original bc36, guest PC 0x0c091230 */
if(!s->budget--) { s->failed_pc=0x0c091230u; return 0; }
target=code_base|0x0c090aa0u; r[16]=code_base|0x0c091234u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091234u) { target=s->pc; goto dispatch; }
goto P_0c091234;
P_0c091232: /* original 64e3, guest PC 0x0c091232 */
if(!s->budget--) { s->failed_pc=0x0c091232u; return 0; }
r[4]=r[14];
goto P_0c091234;
P_0c091234: /* original 4f26, guest PC 0x0c091234 */
if(!s->budget--) { s->failed_pc=0x0c091234u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091236;
P_0c091236: /* original 9057, guest PC 0x0c091236 */
if(!s->budget--) { s->failed_pc=0x0c091236u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0912e8u,2);
goto P_0c091238;
P_0c091238: /* original e30d, guest PC 0x0c091238 */
if(!s->budget--) { s->failed_pc=0x0c091238u; return 0; }
r[3]=0x0000000du;
goto P_0c09123a;
P_0c09123a: /* original 64e3, guest PC 0x0c09123a */
if(!s->budget--) { s->failed_pc=0x0c09123au; return 0; }
r[4]=r[14];
goto P_0c09123c;
P_0c09123c: /* original 0e34, guest PC 0x0c09123c */
if(!s->budget--) { s->failed_pc=0x0c09123cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09123e;
P_0c09123e: /* original a000, guest PC 0x0c09123e */
if(!s->budget--) { s->failed_pc=0x0c09123eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091242;
P_0c091240: /* original 6ef6, guest PC 0x0c091240 */
if(!s->budget--) { s->failed_pc=0x0c091240u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c091242;
P_0c091242: /* original 2fe6, guest PC 0x0c091242 */
if(!s->budget--) { s->failed_pc=0x0c091242u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091244;
P_0c091244: /* original d12e, guest PC 0x0c091244 */
if(!s->budget--) { s->failed_pc=0x0c091244u; return 0; }
r[1]=read(ram,0x0c091300u,4);
goto P_0c091246;
P_0c091246: /* original 4f22, guest PC 0x0c091246 */
if(!s->budget--) { s->failed_pc=0x0c091246u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091248;
P_0c091248: /* original 6212, guest PC 0x0c091248 */
if(!s->budget--) { s->failed_pc=0x0c091248u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09124a;
P_0c09124a: /* original d32c, guest PC 0x0c09124a */
if(!s->budget--) { s->failed_pc=0x0c09124au; return 0; }
r[3]=read(ram,0x0c0912fcu,4);
goto P_0c09124c;
P_0c09124c: /* original 2238, guest PC 0x0c09124c */
if(!s->budget--) { s->failed_pc=0x0c09124cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09124e;
P_0c09124e: /* original 8f11, guest PC 0x0c09124e */
if(!s->budget--) { s->failed_pc=0x0c09124eu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c091274; }
goto P_0c091252;
P_0c091250: /* original 6e43, guest PC 0x0c091250 */
if(!s->budget--) { s->failed_pc=0x0c091250u; return 0; }
r[14]=r[4];
goto P_0c091252;
P_0c091252: /* original d32c, guest PC 0x0c091252 */
if(!s->budget--) { s->failed_pc=0x0c091252u; return 0; }
r[3]=read(ram,0x0c091304u,4);
goto P_0c091254;
P_0c091254: /* original 430b, guest PC 0x0c091254 */
if(!s->budget--) { s->failed_pc=0x0c091254u; return 0; }
target=r[3];
r[16]=code_base|0x0c091258u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091258u) { target=s->pc; goto dispatch; }
goto P_0c091258;
P_0c091256: /* original 64e3, guest PC 0x0c091256 */
if(!s->budget--) { s->failed_pc=0x0c091256u; return 0; }
r[4]=r[14];
goto P_0c091258;
P_0c091258: /* original d22b, guest PC 0x0c091258 */
if(!s->budget--) { s->failed_pc=0x0c091258u; return 0; }
r[2]=read(ram,0x0c091308u,4);
goto P_0c09125a;
P_0c09125a: /* original 420b, guest PC 0x0c09125a */
if(!s->budget--) { s->failed_pc=0x0c09125au; return 0; }
target=r[2];
r[16]=code_base|0x0c09125eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09125eu) { target=s->pc; goto dispatch; }
goto P_0c09125e;
P_0c09125c: /* original 64e3, guest PC 0x0c09125c */
if(!s->budget--) { s->failed_pc=0x0c09125cu; return 0; }
r[4]=r[14];
goto P_0c09125e;
P_0c09125e: /* original d32b, guest PC 0x0c09125e */
if(!s->budget--) { s->failed_pc=0x0c09125eu; return 0; }
r[3]=read(ram,0x0c09130cu,4);
goto P_0c091260;
P_0c091260: /* original 430b, guest PC 0x0c091260 */
if(!s->budget--) { s->failed_pc=0x0c091260u; return 0; }
target=r[3];
r[16]=code_base|0x0c091264u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091264u) { target=s->pc; goto dispatch; }
goto P_0c091264;
P_0c091262: /* original 64e3, guest PC 0x0c091262 */
if(!s->budget--) { s->failed_pc=0x0c091262u; return 0; }
r[4]=r[14];
goto P_0c091264;
P_0c091264: /* original bb7c, guest PC 0x0c091264 */
if(!s->budget--) { s->failed_pc=0x0c091264u; return 0; }
target=code_base|0x0c090960u; r[16]=code_base|0x0c091268u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091268u) { target=s->pc; goto dispatch; }
goto P_0c091268;
P_0c091266: /* original 64e3, guest PC 0x0c091266 */
if(!s->budget--) { s->failed_pc=0x0c091266u; return 0; }
r[4]=r[14];
goto P_0c091268;
P_0c091268: /* original d329, guest PC 0x0c091268 */
if(!s->budget--) { s->failed_pc=0x0c091268u; return 0; }
r[3]=read(ram,0x0c091310u,4);
goto P_0c09126a;
P_0c09126a: /* original 430b, guest PC 0x0c09126a */
if(!s->budget--) { s->failed_pc=0x0c09126au; return 0; }
target=r[3];
r[16]=code_base|0x0c09126eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09126eu) { target=s->pc; goto dispatch; }
goto P_0c09126e;
P_0c09126c: /* original 64e3, guest PC 0x0c09126c */
if(!s->budget--) { s->failed_pc=0x0c09126cu; return 0; }
r[4]=r[14];
goto P_0c09126e;
P_0c09126e: /* original d229, guest PC 0x0c09126e */
if(!s->budget--) { s->failed_pc=0x0c09126eu; return 0; }
r[2]=read(ram,0x0c091314u,4);
goto P_0c091270;
P_0c091270: /* original 420b, guest PC 0x0c091270 */
if(!s->budget--) { s->failed_pc=0x0c091270u; return 0; }
target=r[2];
r[16]=code_base|0x0c091274u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091274u) { target=s->pc; goto dispatch; }
goto P_0c091274;
P_0c091272: /* original 64e3, guest PC 0x0c091272 */
if(!s->budget--) { s->failed_pc=0x0c091272u; return 0; }
r[4]=r[14];
goto P_0c091274;
P_0c091274: /* original 4f26, guest PC 0x0c091274 */
if(!s->budget--) { s->failed_pc=0x0c091274u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091276;
P_0c091276: /* original 000b, guest PC 0x0c091276 */
if(!s->budget--) { s->failed_pc=0x0c091276u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091278: /* original 6ef6, guest PC 0x0c091278 */
if(!s->budget--) { s->failed_pc=0x0c091278u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09127au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09127au; return 0; } return 1;
P_0c096866: /* original 4f22, guest PC 0x0c096866 */
if(!s->budget--) { s->failed_pc=0x0c096866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096868;
P_0c096868: /* original 7ff8, guest PC 0x0c096868 */
if(!s->budget--) { s->failed_pc=0x0c096868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09686a;
P_0c09686a: /* original 2f42, guest PC 0x0c09686a */
if(!s->budget--) { s->failed_pc=0x0c09686au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09686c;
P_0c09686c: /* original d311, guest PC 0x0c09686c */
if(!s->budget--) { s->failed_pc=0x0c09686cu; return 0; }
r[3]=read(ram,0x0c0968b4u,4);
goto P_0c09686e;
P_0c09686e: /* original 430b, guest PC 0x0c09686e */
if(!s->budget--) { s->failed_pc=0x0c09686eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096872u;
write(ram,r[15]+4,r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096872u) { target=s->pc; goto dispatch; }
goto P_0c096872;
P_0c096870: /* original 1f51, guest PC 0x0c096870 */
if(!s->budget--) { s->failed_pc=0x0c096870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c096872;
P_0c096872: /* original 6e03, guest PC 0x0c096872 */
if(!s->budget--) { s->failed_pc=0x0c096872u; return 0; }
r[14]=r[0];
goto P_0c096874;
P_0c096874: /* original 2ee8, guest PC 0x0c096874 */
if(!s->budget--) { s->failed_pc=0x0c096874u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c096876;
P_0c096876: /* original 8905, guest PC 0x0c096876 */
if(!s->budget--) { s->failed_pc=0x0c096876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096884; }
goto P_0c096878;
P_0c096878: /* original d30f, guest PC 0x0c096878 */
if(!s->budget--) { s->failed_pc=0x0c096878u; return 0; }
r[3]=read(ram,0x0c0968b8u,4);
goto P_0c09687a;
P_0c09687a: /* original 430b, guest PC 0x0c09687a */
if(!s->budget--) { s->failed_pc=0x0c09687au; return 0; }
target=r[3];
r[16]=code_base|0x0c09687eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09687eu) { target=s->pc; goto dispatch; }
goto P_0c09687e;
P_0c09687c: /* original 64e3, guest PC 0x0c09687c */
if(!s->budget--) { s->failed_pc=0x0c09687cu; return 0; }
r[4]=r[14];
goto P_0c09687e;
P_0c09687e: /* original d20f, guest PC 0x0c09687e */
if(!s->budget--) { s->failed_pc=0x0c09687eu; return 0; }
r[2]=read(ram,0x0c0968bcu,4);
goto P_0c096880;
P_0c096880: /* original 420b, guest PC 0x0c096880 */
if(!s->budget--) { s->failed_pc=0x0c096880u; return 0; }
target=r[2];
r[16]=code_base|0x0c096884u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096884u) { target=s->pc; goto dispatch; }
goto P_0c096884;
P_0c096882: /* original 64e3, guest PC 0x0c096882 */
if(!s->budget--) { s->failed_pc=0x0c096882u; return 0; }
r[4]=r[14];
goto P_0c096884;
P_0c096884: /* original 0002, guest PC 0x0c096884 */
if(!s->budget--) { s->failed_pc=0x0c096884u; return 0; }
r[0]=r[17];
goto P_0c096886;
P_0c096886: /* original 9313, guest PC 0x0c096886 */
if(!s->budget--) { s->failed_pc=0x0c096886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c096888;
P_0c096888: /* original 2039, guest PC 0x0c096888 */
if(!s->budget--) { s->failed_pc=0x0c096888u; return 0; }
r[0]&=r[3];
goto P_0c09688a;
P_0c09688a: /* original cbe0, guest PC 0x0c09688a */
if(!s->budget--) { s->failed_pc=0x0c09688au; return 0; }
r[0]|=224u;
goto P_0c09688c;
P_0c09688c: /* original 400e, guest PC 0x0c09688c */
if(!s->budget--) { s->failed_pc=0x0c09688cu; return 0; }
r[17]=r[0];
goto P_0c09688e;
P_0c09688e: /* original d20c, guest PC 0x0c09688e */
if(!s->budget--) { s->failed_pc=0x0c09688eu; return 0; }
r[2]=read(ram,0x0c0968c0u,4);
goto P_0c096890;
P_0c096890: /* original 420b, guest PC 0x0c096890 */
if(!s->budget--) { s->failed_pc=0x0c096890u; return 0; }
target=r[2];
r[16]=code_base|0x0c096894u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096894u) { target=s->pc; goto dispatch; }
goto P_0c096894;
P_0c096892: /* original 0009, guest PC 0x0c096892 */
if(!s->budget--) { s->failed_pc=0x0c096892u; return 0; }
goto P_0c096894;
P_0c096894: /* original d10b, guest PC 0x0c096894 */
if(!s->budget--) { s->failed_pc=0x0c096894u; return 0; }
r[1]=read(ram,0x0c0968c4u,4);
goto P_0c096896;
P_0c096896: /* original 410b, guest PC 0x0c096896 */
if(!s->budget--) { s->failed_pc=0x0c096896u; return 0; }
target=r[1];
r[16]=code_base|0x0c09689au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09689au) { target=s->pc; goto dispatch; }
goto P_0c09689a;
P_0c096898: /* original 0009, guest PC 0x0c096898 */
if(!s->budget--) { s->failed_pc=0x0c096898u; return 0; }
goto P_0c09689a;
P_0c09689a: /* original 0002, guest PC 0x0c09689a */
if(!s->budget--) { s->failed_pc=0x0c09689au; return 0; }
r[0]=r[17];
goto P_0c09689c;
P_0c09689c: /* original 9208, guest PC 0x0c09689c */
if(!s->budget--) { s->failed_pc=0x0c09689cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c09689e;
P_0c09689e: /* original 2029, guest PC 0x0c09689e */
if(!s->budget--) { s->failed_pc=0x0c09689eu; return 0; }
r[0]&=r[2];
goto P_0c0968a0;
P_0c0968a0: /* original 400e, guest PC 0x0c0968a0 */
if(!s->budget--) { s->failed_pc=0x0c0968a0u; return 0; }
r[17]=r[0];
goto P_0c0968a2;
P_0c0968a2: /* original 64f2, guest PC 0x0c0968a2 */
if(!s->budget--) { s->failed_pc=0x0c0968a2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0968a4;
P_0c0968a4: /* original 55f1, guest PC 0x0c0968a4 */
if(!s->budget--) { s->failed_pc=0x0c0968a4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0968a6;
P_0c0968a6: /* original 7f08, guest PC 0x0c0968a6 */
if(!s->budget--) { s->failed_pc=0x0c0968a6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0968a8;
P_0c0968a8: /* original 4f26, guest PC 0x0c0968a8 */
if(!s->budget--) { s->failed_pc=0x0c0968a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0968aa;
P_0c0968aa: /* original d307, guest PC 0x0c0968aa */
if(!s->budget--) { s->failed_pc=0x0c0968aau; return 0; }
r[3]=read(ram,0x0c0968c8u,4);
goto P_0c0968ac;
P_0c0968ac: /* original 432b, guest PC 0x0c0968ac */
if(!s->budget--) { s->failed_pc=0x0c0968acu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09571cu: if(!vf3_matrix_family(0x0c09571cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09571cu; return 0; } return 1;
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
P_0c0968ae: /* original 6ef6, guest PC 0x0c0968ae */
if(!s->budget--) { s->failed_pc=0x0c0968aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0968b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0968b0u; return 0; } return 1;
P_0c0968d0: /* original d418, guest PC 0x0c0968d0 */
if(!s->budget--) { s->failed_pc=0x0c0968d0u; return 0; }
r[4]=read(ram,0x0c096934u,4);
goto P_0c0968d2;
P_0c0968d2: /* original 7ffc, guest PC 0x0c0968d2 */
if(!s->budget--) { s->failed_pc=0x0c0968d2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0968d4;
P_0c0968d4: /* original 5343, guest PC 0x0c0968d4 */
if(!s->budget--) { s->failed_pc=0x0c0968d4u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0968d6;
P_0c0968d6: /* original 73ff, guest PC 0x0c0968d6 */
if(!s->budget--) { s->failed_pc=0x0c0968d6u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0968d8;
P_0c0968d8: /* original 1433, guest PC 0x0c0968d8 */
if(!s->budget--) { s->failed_pc=0x0c0968d8u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0968da;
P_0c0968da: /* original 844a, guest PC 0x0c0968da */
if(!s->budget--) { s->failed_pc=0x0c0968dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c0968dc;
P_0c0968dc: /* original 650c, guest PC 0x0c0968dc */
if(!s->budget--) { s->failed_pc=0x0c0968dcu; return 0; }
r[5]=r[0]&255u;
goto P_0c0968de;
P_0c0968de: /* original 6053, guest PC 0x0c0968de */
if(!s->budget--) { s->failed_pc=0x0c0968deu; return 0; }
r[0]=r[5];
goto P_0c0968e0;
P_0c0968e0: /* original 8048, guest PC 0x0c0968e0 */
if(!s->budget--) { s->failed_pc=0x0c0968e0u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0968e2;
P_0c0968e2: /* original d215, guest PC 0x0c0968e2 */
if(!s->budget--) { s->failed_pc=0x0c0968e2u; return 0; }
r[2]=read(ram,0x0c096938u,4);
goto P_0c0968e4;
P_0c0968e4: /* original 635b, guest PC 0x0c0968e4 */
if(!s->budget--) { s->failed_pc=0x0c0968e4u; return 0; }
r[3]=0u-r[5];
goto P_0c0968e6;
P_0c0968e6: /* original 4508, guest PC 0x0c0968e6 */
if(!s->budget--) { s->failed_pc=0x0c0968e6u; return 0; }
r[5]<<=2;
goto P_0c0968e8;
P_0c0968e8: /* original 423d, guest PC 0x0c0968e8 */
if(!s->budget--) { s->failed_pc=0x0c0968e8u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0968ea;
P_0c0968ea: /* original 2422, guest PC 0x0c0968ea */
if(!s->budget--) { s->failed_pc=0x0c0968eau; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0968ec;
P_0c0968ec: /* original d013, guest PC 0x0c0968ec */
if(!s->budget--) { s->failed_pc=0x0c0968ecu; return 0; }
r[0]=read(ram,0x0c09693cu,4);
goto P_0c0968ee;
P_0c0968ee: /* original 035e, guest PC 0x0c0968ee */
if(!s->budget--) { s->failed_pc=0x0c0968eeu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0968f0;
P_0c0968f0: /* original 6233, guest PC 0x0c0968f0 */
if(!s->budget--) { s->failed_pc=0x0c0968f0u; return 0; }
r[2]=r[3];
goto P_0c0968f2;
P_0c0968f2: /* original 2f32, guest PC 0x0c0968f2 */
if(!s->budget--) { s->failed_pc=0x0c0968f2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0968f4;
P_0c0968f4: /* original 422b, guest PC 0x0c0968f4 */
if(!s->budget--) { s->failed_pc=0x0c0968f4u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0968f6: /* original 7f04, guest PC 0x0c0968f6 */
if(!s->budget--) { s->failed_pc=0x0c0968f6u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0968f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0968f8u; return 0; } return 1;
P_0c096d5e: /* original 2fe6, guest PC 0x0c096d5e */
if(!s->budget--) { s->failed_pc=0x0c096d5eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096d60;
P_0c096d60: /* original 2fd6, guest PC 0x0c096d60 */
if(!s->budget--) { s->failed_pc=0x0c096d60u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096d62;
P_0c096d62: /* original 4f22, guest PC 0x0c096d62 */
if(!s->budget--) { s->failed_pc=0x0c096d62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096d64;
P_0c096d64: /* original d327, guest PC 0x0c096d64 */
if(!s->budget--) { s->failed_pc=0x0c096d64u; return 0; }
r[3]=read(ram,0x0c096e04u,4);
goto P_0c096d66;
P_0c096d66: /* original dd2a, guest PC 0x0c096d66 */
if(!s->budget--) { s->failed_pc=0x0c096d66u; return 0; }
r[13]=read(ram,0x0c096e10u,4);
goto P_0c096d68;
P_0c096d68: /* original 7ffc, guest PC 0x0c096d68 */
if(!s->budget--) { s->failed_pc=0x0c096d68u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096d6a;
P_0c096d6a: /* original 2f32, guest PC 0x0c096d6a */
if(!s->budget--) { s->failed_pc=0x0c096d6au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c096d6c;
P_0c096d6c: /* original 52d2, guest PC 0x0c096d6c */
if(!s->budget--) { s->failed_pc=0x0c096d6cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d6e;
P_0c096d6e: /* original d329, guest PC 0x0c096d6e */
if(!s->budget--) { s->failed_pc=0x0c096d6eu; return 0; }
r[3]=read(ram,0x0c096e14u,4);
goto P_0c096d70;
P_0c096d70: /* original 2238, guest PC 0x0c096d70 */
if(!s->budget--) { s->failed_pc=0x0c096d70u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c096d72;
P_0c096d72: /* original 8920, guest PC 0x0c096d72 */
if(!s->budget--) { s->failed_pc=0x0c096d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096db6; }
goto P_0c096d74;
P_0c096d74: /* original de28, guest PC 0x0c096d74 */
if(!s->budget--) { s->failed_pc=0x0c096d74u; return 0; }
r[14]=read(ram,0x0c096e18u,4);
goto P_0c096d76;
P_0c096d76: /* original bdc4, guest PC 0x0c096d76 */
if(!s->budget--) { s->failed_pc=0x0c096d76u; return 0; }
target=code_base|0x0c096902u; r[16]=code_base|0x0c096d7au;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d7au) { target=s->pc; goto dispatch; }
goto P_0c096d7a;
P_0c096d78: /* original 54e8, guest PC 0x0c096d78 */
if(!s->budget--) { s->failed_pc=0x0c096d78u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c096d7a;
P_0c096d7a: /* original e044, guest PC 0x0c096d7a */
if(!s->budget--) { s->failed_pc=0x0c096d7au; return 0; }
r[0]=0x00000044u;
goto P_0c096d7c;
P_0c096d7c: /* original bdc1, guest PC 0x0c096d7c */
if(!s->budget--) { s->failed_pc=0x0c096d7cu; return 0; }
target=code_base|0x0c096902u; r[16]=code_base|0x0c096d80u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d80u) { target=s->pc; goto dispatch; }
goto P_0c096d80;
P_0c096d7e: /* original 04ee, guest PC 0x0c096d7e */
if(!s->budget--) { s->failed_pc=0x0c096d7eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d80;
P_0c096d80: /* original 52d2, guest PC 0x0c096d80 */
if(!s->budget--) { s->failed_pc=0x0c096d80u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d82;
P_0c096d82: /* original e044, guest PC 0x0c096d82 */
if(!s->budget--) { s->failed_pc=0x0c096d82u; return 0; }
r[0]=0x00000044u;
goto P_0c096d84;
P_0c096d84: /* original d325, guest PC 0x0c096d84 */
if(!s->budget--) { s->failed_pc=0x0c096d84u; return 0; }
r[3]=read(ram,0x0c096e1cu,4);
goto P_0c096d86;
P_0c096d86: /* original 223b, guest PC 0x0c096d86 */
if(!s->budget--) { s->failed_pc=0x0c096d86u; return 0; }
r[2]|=r[3];
goto P_0c096d88;
P_0c096d88: /* original 1d22, guest PC 0x0c096d88 */
if(!s->budget--) { s->failed_pc=0x0c096d88u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c096d8a;
P_0c096d8a: /* original e201, guest PC 0x0c096d8a */
if(!s->budget--) { s->failed_pc=0x0c096d8au; return 0; }
r[2]=0x00000001u;
goto P_0c096d8c;
P_0c096d8c: /* original d124, guest PC 0x0c096d8c */
if(!s->budget--) { s->failed_pc=0x0c096d8cu; return 0; }
r[1]=read(ram,0x0c096e20u,4);
goto P_0c096d8e;
P_0c096d8e: /* original 04ee, guest PC 0x0c096d8e */
if(!s->budget--) { s->failed_pc=0x0c096d8eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d90;
P_0c096d90: /* original 410b, guest PC 0x0c096d90 */
if(!s->budget--) { s->failed_pc=0x0c096d90u; return 0; }
target=r[1];
r[16]=code_base|0x0c096d94u;
write(ram,r[4],r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096d94u) { target=s->pc; goto dispatch; }
goto P_0c096d94;
P_0c096d92: /* original 2422, guest PC 0x0c096d92 */
if(!s->budget--) { s->failed_pc=0x0c096d92u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c096d94;
P_0c096d94: /* original 55e5, guest PC 0x0c096d94 */
if(!s->budget--) { s->failed_pc=0x0c096d94u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c096d96;
P_0c096d96: /* original e400, guest PC 0x0c096d96 */
if(!s->budget--) { s->failed_pc=0x0c096d96u; return 0; }
r[4]=0x00000000u;
goto P_0c096d98;
P_0c096d98: /* original 56e4, guest PC 0x0c096d98 */
if(!s->budget--) { s->failed_pc=0x0c096d98u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c096d9a;
P_0c096d9a: /* original e061, guest PC 0x0c096d9a */
if(!s->budget--) { s->failed_pc=0x0c096d9au; return 0; }
r[0]=0x00000061u;
goto P_0c096d9c;
P_0c096d9c: /* original 0644, guest PC 0x0c096d9c */
if(!s->budget--) { s->failed_pc=0x0c096d9cu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096d9e;
P_0c096d9e: /* original 0544, guest PC 0x0c096d9e */
if(!s->budget--) { s->failed_pc=0x0c096d9eu; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da0;
P_0c096da0: /* original e060, guest PC 0x0c096da0 */
if(!s->budget--) { s->failed_pc=0x0c096da0u; return 0; }
r[0]=0x00000060u;
goto P_0c096da2;
P_0c096da2: /* original 0644, guest PC 0x0c096da2 */
if(!s->budget--) { s->failed_pc=0x0c096da2u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096da4;
P_0c096da4: /* original 0544, guest PC 0x0c096da4 */
if(!s->budget--) { s->failed_pc=0x0c096da4u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da6;
P_0c096da6: /* original e016, guest PC 0x0c096da6 */
if(!s->budget--) { s->failed_pc=0x0c096da6u; return 0; }
r[0]=0x00000016u;
goto P_0c096da8;
P_0c096da8: /* original 63f2, guest PC 0x0c096da8 */
if(!s->budget--) { s->failed_pc=0x0c096da8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c096daa;
P_0c096daa: /* original 7f04, guest PC 0x0c096daa */
if(!s->budget--) { s->failed_pc=0x0c096daau; return 0; }
r[15]+=0x00000004u;
goto P_0c096dac;
P_0c096dac: /* original 4f26, guest PC 0x0c096dac */
if(!s->budget--) { s->failed_pc=0x0c096dacu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dae;
P_0c096dae: /* original 803a, guest PC 0x0c096dae */
if(!s->budget--) { s->failed_pc=0x0c096daeu; return 0; }
write(ram,r[3]+10,r[0],1);
goto P_0c096db0;
P_0c096db0: /* original 6df6, guest PC 0x0c096db0 */
if(!s->budget--) { s->failed_pc=0x0c096db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096db2;
P_0c096db2: /* original ad8d, guest PC 0x0c096db2 */
if(!s->budget--) { s->failed_pc=0x0c096db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0968d0;
P_0c096db4: /* original 6ef6, guest PC 0x0c096db4 */
if(!s->budget--) { s->failed_pc=0x0c096db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096db6;
P_0c096db6: /* original 7f04, guest PC 0x0c096db6 */
if(!s->budget--) { s->failed_pc=0x0c096db6u; return 0; }
r[15]+=0x00000004u;
goto P_0c096db8;
P_0c096db8: /* original 4f26, guest PC 0x0c096db8 */
if(!s->budget--) { s->failed_pc=0x0c096db8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dba;
P_0c096dba: /* original 6df6, guest PC 0x0c096dba */
if(!s->budget--) { s->failed_pc=0x0c096dbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096dbc;
P_0c096dbc: /* original 000b, guest PC 0x0c096dbc */
if(!s->budget--) { s->failed_pc=0x0c096dbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096dbe: /* original 6ef6, guest PC 0x0c096dbe */
if(!s->budget--) { s->failed_pc=0x0c096dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096dc0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096dc0u; return 0; } return 1;
P_0c09713c: /* original 4f22, guest PC 0x0c09713c */
if(!s->budget--) { s->failed_pc=0x0c09713cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09713e;
P_0c09713e: /* original d335, guest PC 0x0c09713e */
if(!s->budget--) { s->failed_pc=0x0c09713eu; return 0; }
r[3]=read(ram,0x0c097214u,4);
goto P_0c097140;
P_0c097140: /* original dc33, guest PC 0x0c097140 */
if(!s->budget--) { s->failed_pc=0x0c097140u; return 0; }
r[12]=read(ram,0x0c097210u,4);
goto P_0c097142;
P_0c097142: /* original dd32, guest PC 0x0c097142 */
if(!s->budget--) { s->failed_pc=0x0c097142u; return 0; }
r[13]=read(ram,0x0c09720cu,4);
goto P_0c097144;
P_0c097144: /* original 430b, guest PC 0x0c097144 */
if(!s->budget--) { s->failed_pc=0x0c097144u; return 0; }
target=r[3];
r[16]=code_base|0x0c097148u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097148u) { target=s->pc; goto dispatch; }
goto P_0c097148;
P_0c097146: /* original 0009, guest PC 0x0c097146 */
if(!s->budget--) { s->failed_pc=0x0c097146u; return 0; }
goto P_0c097148;
P_0c097148: /* original c734, guest PC 0x0c097148 */
if(!s->budget--) { s->failed_pc=0x0c097148u; return 0; }
r[0]=code_base|0x0009721cu;
goto P_0c09714a;
P_0c09714a: /* original d335, guest PC 0x0c09714a */
if(!s->budget--) { s->failed_pc=0x0c09714au; return 0; }
r[3]=read(ram,0x0c097220u,4);
goto P_0c09714c;
P_0c09714c: /* original f408, guest PC 0x0c09714c */
if(!s->budget--) { s->failed_pc=0x0c09714cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09714e;
P_0c09714e: /* original ff8d, guest PC 0x0c09714e */
if(!s->budget--) { s->failed_pc=0x0c09714eu; return 0; }
fr[15]=0;
goto P_0c097150;
P_0c097150: /* original d531, guest PC 0x0c097150 */
if(!s->budget--) { s->failed_pc=0x0c097150u; return 0; }
r[5]=read(ram,0x0c097218u,4);
goto P_0c097152;
P_0c097152: /* original f6fc, guest PC 0x0c097152 */
if(!s->budget--) { s->failed_pc=0x0c097152u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c097154;
P_0c097154: /* original f5fc, guest PC 0x0c097154 */
if(!s->budget--) { s->failed_pc=0x0c097154u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097156;
P_0c097156: /* original 430b, guest PC 0x0c097156 */
if(!s->budget--) { s->failed_pc=0x0c097156u; return 0; }
target=r[3];
r[16]=code_base|0x0c09715au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09715au) { target=s->pc; goto dispatch; }
goto P_0c09715a;
P_0c097158: /* original e400, guest PC 0x0c097158 */
if(!s->budget--) { s->failed_pc=0x0c097158u; return 0; }
r[4]=0x00000000u;
goto P_0c09715a;
P_0c09715a: /* original d231, guest PC 0x0c09715a */
if(!s->budget--) { s->failed_pc=0x0c09715au; return 0; }
r[2]=read(ram,0x0c097220u,4);
goto P_0c09715c;
P_0c09715c: /* original 954e, guest PC 0x0c09715c */
if(!s->budget--) { s->failed_pc=0x0c09715cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0971fcu,2);
goto P_0c09715e;
P_0c09715e: /* original f49d, guest PC 0x0c09715e */
if(!s->budget--) { s->failed_pc=0x0c09715eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c097160;
P_0c097160: /* original f6fc, guest PC 0x0c097160 */
if(!s->budget--) { s->failed_pc=0x0c097160u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c097162;
P_0c097162: /* original f5fc, guest PC 0x0c097162 */
if(!s->budget--) { s->failed_pc=0x0c097162u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c097164;
P_0c097164: /* original 420b, guest PC 0x0c097164 */
if(!s->budget--) { s->failed_pc=0x0c097164u; return 0; }
target=r[2];
r[16]=code_base|0x0c097168u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097168u) { target=s->pc; goto dispatch; }
goto P_0c097168;
P_0c097166: /* original e401, guest PC 0x0c097166 */
if(!s->budget--) { s->failed_pc=0x0c097166u; return 0; }
r[4]=0x00000001u;
goto P_0c097168;
P_0c097168: /* original d52f, guest PC 0x0c097168 */
if(!s->budget--) { s->failed_pc=0x0c097168u; return 0; }
r[5]=read(ram,0x0c097228u,4);
goto P_0c09716a;
P_0c09716a: /* original de2e, guest PC 0x0c09716a */
if(!s->budget--) { s->failed_pc=0x0c09716au; return 0; }
r[14]=read(ram,0x0c097224u,4);
goto P_0c09716c;
P_0c09716c: /* original bbcd, guest PC 0x0c09716c */
if(!s->budget--) { s->failed_pc=0x0c09716cu; return 0; }
target=code_base|0x0c09690au; r[16]=code_base|0x0c097170u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097170u) { target=s->pc; goto dispatch; }
goto P_0c097170;
P_0c09716e: /* original 54e7, guest PC 0x0c09716e */
if(!s->budget--) { s->failed_pc=0x0c09716eu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c097170;
P_0c097170: /* original d52e, guest PC 0x0c097170 */
if(!s->budget--) { s->failed_pc=0x0c097170u; return 0; }
r[5]=read(ram,0x0c09722cu,4);
goto P_0c097172;
P_0c097172: /* original bbca, guest PC 0x0c097172 */
if(!s->budget--) { s->failed_pc=0x0c097172u; return 0; }
target=code_base|0x0c09690au; r[16]=code_base|0x0c097176u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097176u) { target=s->pc; goto dispatch; }
goto P_0c097176;
P_0c097174: /* original 54e6, guest PC 0x0c097174 */
if(!s->budget--) { s->failed_pc=0x0c097174u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c097176;
P_0c097176: /* original d52e, guest PC 0x0c097176 */
if(!s->budget--) { s->failed_pc=0x0c097176u; return 0; }
r[5]=read(ram,0x0c097230u,4);
goto P_0c097178;
P_0c097178: /* original bbc7, guest PC 0x0c097178 */
if(!s->budget--) { s->failed_pc=0x0c097178u; return 0; }
target=code_base|0x0c09690au; r[16]=code_base|0x0c09717cu;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09717cu) { target=s->pc; goto dispatch; }
goto P_0c09717c;
P_0c09717a: /* original 54ef, guest PC 0x0c09717a */
if(!s->budget--) { s->failed_pc=0x0c09717au; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c09717c;
P_0c09717c: /* original d52d, guest PC 0x0c09717c */
if(!s->budget--) { s->failed_pc=0x0c09717cu; return 0; }
r[5]=read(ram,0x0c097234u,4);
goto P_0c09717e;
P_0c09717e: /* original e040, guest PC 0x0c09717e */
if(!s->budget--) { s->failed_pc=0x0c09717eu; return 0; }
r[0]=0x00000040u;
goto P_0c097180;
P_0c097180: /* original bbc3, guest PC 0x0c097180 */
if(!s->budget--) { s->failed_pc=0x0c097180u; return 0; }
target=code_base|0x0c09690au; r[16]=code_base|0x0c097184u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097184u) { target=s->pc; goto dispatch; }
goto P_0c097184;
P_0c097182: /* original 04ee, guest PC 0x0c097182 */
if(!s->budget--) { s->failed_pc=0x0c097182u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c097184;
P_0c097184: /* original bbbd, guest PC 0x0c097184 */
if(!s->budget--) { s->failed_pc=0x0c097184u; return 0; }
target=code_base|0x0c096902u; r[16]=code_base|0x0c097188u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c097188u) { target=s->pc; goto dispatch; }
goto P_0c097188;
P_0c097186: /* original 54e8, guest PC 0x0c097186 */
if(!s->budget--) { s->failed_pc=0x0c097186u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c097188;
P_0c097188: /* original e044, guest PC 0x0c097188 */
if(!s->budget--) { s->failed_pc=0x0c097188u; return 0; }
r[0]=0x00000044u;
goto P_0c09718a;
P_0c09718a: /* original bbba, guest PC 0x0c09718a */
if(!s->budget--) { s->failed_pc=0x0c09718au; return 0; }
target=code_base|0x0c096902u; r[16]=code_base|0x0c09718eu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09718eu) { target=s->pc; goto dispatch; }
goto P_0c09718e;
P_0c09718c: /* original 04ee, guest PC 0x0c09718c */
if(!s->budget--) { s->failed_pc=0x0c09718cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09718e;
P_0c09718e: /* original 9036, guest PC 0x0c09718e */
if(!s->budget--) { s->failed_pc=0x0c09718eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0971feu,2);
goto P_0c097190;
P_0c097190: /* original e400, guest PC 0x0c097190 */
if(!s->budget--) { s->failed_pc=0x0c097190u; return 0; }
r[4]=0x00000000u;
goto P_0c097192;
P_0c097192: /* original 0c44, guest PC 0x0c097192 */
if(!s->budget--) { s->failed_pc=0x0c097192u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c097194;
P_0c097194: /* original 9034, guest PC 0x0c097194 */
if(!s->budget--) { s->failed_pc=0x0c097194u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097200u,2);
goto P_0c097196;
P_0c097196: /* original 0c45, guest PC 0x0c097196 */
if(!s->budget--) { s->failed_pc=0x0c097196u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c097198;
P_0c097198: /* original e044, guest PC 0x0c097198 */
if(!s->budget--) { s->failed_pc=0x0c097198u; return 0; }
r[0]=0x00000044u;
goto P_0c09719a;
P_0c09719a: /* original 9332, guest PC 0x0c09719a */
if(!s->budget--) { s->failed_pc=0x0c09719au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097202u,2);
goto P_0c09719c;
P_0c09719c: /* original 1d33, guest PC 0x0c09719c */
if(!s->budget--) { s->failed_pc=0x0c09719cu; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c09719e;
P_0c09719e: /* original e301, guest PC 0x0c09719e */
if(!s->budget--) { s->failed_pc=0x0c09719eu; return 0; }
r[3]=0x00000001u;
goto P_0c0971a0;
P_0c0971a0: /* original d225, guest PC 0x0c0971a0 */
if(!s->budget--) { s->failed_pc=0x0c0971a0u; return 0; }
r[2]=read(ram,0x0c097238u,4);
goto P_0c0971a2;
P_0c0971a2: /* original 04ee, guest PC 0x0c0971a2 */
if(!s->budget--) { s->failed_pc=0x0c0971a2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0971a4;
P_0c0971a4: /* original 420b, guest PC 0x0c0971a4 */
if(!s->budget--) { s->failed_pc=0x0c0971a4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0971a8u;
write(ram,r[4],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0971a8u) { target=s->pc; goto dispatch; }
goto P_0c0971a8;
P_0c0971a6: /* original 2432, guest PC 0x0c0971a6 */
if(!s->budget--) { s->failed_pc=0x0c0971a6u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0971a8;
P_0c0971a8: /* original 902c, guest PC 0x0c0971a8 */
if(!s->budget--) { s->failed_pc=0x0c0971a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097204u,2);
goto P_0c0971aa;
P_0c0971aa: /* original e306, guest PC 0x0c0971aa */
if(!s->budget--) { s->failed_pc=0x0c0971aau; return 0; }
r[3]=0x00000006u;
goto P_0c0971ac;
P_0c0971ac: /* original 54e8, guest PC 0x0c0971ac */
if(!s->budget--) { s->failed_pc=0x0c0971acu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c0971ae;
P_0c0971ae: /* original e20d, guest PC 0x0c0971ae */
if(!s->budget--) { s->failed_pc=0x0c0971aeu; return 0; }
r[2]=0x0000000du;
goto P_0c0971b0;
P_0c0971b0: /* original 4f26, guest PC 0x0c0971b0 */
if(!s->budget--) { s->failed_pc=0x0c0971b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0971b2;
P_0c0971b2: /* original 0434, guest PC 0x0c0971b2 */
if(!s->budget--) { s->failed_pc=0x0c0971b2u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0971b4;
P_0c0971b4: /* original e010, guest PC 0x0c0971b4 */
if(!s->budget--) { s->failed_pc=0x0c0971b4u; return 0; }
r[0]=0x00000010u;
goto P_0c0971b6;
P_0c0971b6: /* original 0d24, guest PC 0x0c0971b6 */
if(!s->budget--) { s->failed_pc=0x0c0971b6u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0971b8;
P_0c0971b8: /* original 84db, guest PC 0x0c0971b8 */
if(!s->budget--) { s->failed_pc=0x0c0971b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c0971ba;
P_0c0971ba: /* original 7001, guest PC 0x0c0971ba */
if(!s->budget--) { s->failed_pc=0x0c0971bau; return 0; }
r[0]+=0x00000001u;
goto P_0c0971bc;
P_0c0971bc: /* original 80db, guest PC 0x0c0971bc */
if(!s->budget--) { s->failed_pc=0x0c0971bcu; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c0971be;
P_0c0971be: /* original fff9, guest PC 0x0c0971be */
if(!s->budget--) { s->failed_pc=0x0c0971beu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0971c0;
P_0c0971c0: /* original 6cf6, guest PC 0x0c0971c0 */
if(!s->budget--) { s->failed_pc=0x0c0971c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0971c2;
P_0c0971c2: /* original 6df6, guest PC 0x0c0971c2 */
if(!s->budget--) { s->failed_pc=0x0c0971c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0971c4;
P_0c0971c4: /* original adcb, guest PC 0x0c0971c4 */
if(!s->budget--) { s->failed_pc=0x0c0971c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096d5e;
P_0c0971c6: /* original 6ef6, guest PC 0x0c0971c6 */
if(!s->budget--) { s->failed_pc=0x0c0971c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0971c8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0971c8u; return 0; } return 1;
P_0c0a2518: /* original 4f22, guest PC 0x0c0a2518 */
if(!s->budget--) { s->failed_pc=0x0c0a2518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a251a;
P_0c0a251a: /* original d341, guest PC 0x0c0a251a */
if(!s->budget--) { s->failed_pc=0x0c0a251au; return 0; }
r[3]=read(ram,0x0c0a2620u,4);
goto P_0c0a251c;
P_0c0a251c: /* original 430b, guest PC 0x0c0a251c */
if(!s->budget--) { s->failed_pc=0x0c0a251cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2520u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2520u) { target=s->pc; goto dispatch; }
goto P_0c0a2520;
P_0c0a251e: /* original 0009, guest PC 0x0c0a251e */
if(!s->budget--) { s->failed_pc=0x0c0a251eu; return 0; }
goto P_0c0a2520;
P_0c0a2520: /* original d240, guest PC 0x0c0a2520 */
if(!s->budget--) { s->failed_pc=0x0c0a2520u; return 0; }
r[2]=read(ram,0x0c0a2624u,4);
goto P_0c0a2522;
P_0c0a2522: /* original 420b, guest PC 0x0c0a2522 */
if(!s->budget--) { s->failed_pc=0x0c0a2522u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2526u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2526u) { target=s->pc; goto dispatch; }
goto P_0c0a2526;
P_0c0a2524: /* original e400, guest PC 0x0c0a2524 */
if(!s->budget--) { s->failed_pc=0x0c0a2524u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2526;
P_0c0a2526: /* original d340, guest PC 0x0c0a2526 */
if(!s->budget--) { s->failed_pc=0x0c0a2526u; return 0; }
r[3]=read(ram,0x0c0a2628u,4);
goto P_0c0a2528;
P_0c0a2528: /* original 430b, guest PC 0x0c0a2528 */
if(!s->budget--) { s->failed_pc=0x0c0a2528u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a252cu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a252cu) { target=s->pc; goto dispatch; }
goto P_0c0a252c;
P_0c0a252a: /* original e401, guest PC 0x0c0a252a */
if(!s->budget--) { s->failed_pc=0x0c0a252au; return 0; }
r[4]=0x00000001u;
goto P_0c0a252c;
P_0c0a252c: /* original d23f, guest PC 0x0c0a252c */
if(!s->budget--) { s->failed_pc=0x0c0a252cu; return 0; }
r[2]=read(ram,0x0c0a262cu,4);
goto P_0c0a252e;
P_0c0a252e: /* original 420b, guest PC 0x0c0a252e */
if(!s->budget--) { s->failed_pc=0x0c0a252eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2532u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2532u) { target=s->pc; goto dispatch; }
goto P_0c0a2532;
P_0c0a2530: /* original e400, guest PC 0x0c0a2530 */
if(!s->budget--) { s->failed_pc=0x0c0a2530u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2532;
P_0c0a2532: /* original d33f, guest PC 0x0c0a2532 */
if(!s->budget--) { s->failed_pc=0x0c0a2532u; return 0; }
r[3]=read(ram,0x0c0a2630u,4);
goto P_0c0a2534;
P_0c0a2534: /* original e500, guest PC 0x0c0a2534 */
if(!s->budget--) { s->failed_pc=0x0c0a2534u; return 0; }
r[5]=0x00000000u;
goto P_0c0a2536;
P_0c0a2536: /* original 430b, guest PC 0x0c0a2536 */
if(!s->budget--) { s->failed_pc=0x0c0a2536u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a253au;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a253au) { target=s->pc; goto dispatch; }
goto P_0c0a253a;
P_0c0a2538: /* original e403, guest PC 0x0c0a2538 */
if(!s->budget--) { s->failed_pc=0x0c0a2538u; return 0; }
r[4]=0x00000003u;
goto P_0c0a253a;
P_0c0a253a: /* original 9569, guest PC 0x0c0a253a */
if(!s->budget--) { s->failed_pc=0x0c0a253au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2610u,2);
goto P_0c0a253c;
P_0c0a253c: /* original de3d, guest PC 0x0c0a253c */
if(!s->budget--) { s->failed_pc=0x0c0a253cu; return 0; }
r[14]=read(ram,0x0c0a2634u,4);
goto P_0c0a253e;
P_0c0a253e: /* original 4e0b, guest PC 0x0c0a253e */
if(!s->budget--) { s->failed_pc=0x0c0a253eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2542u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2542u) { target=s->pc; goto dispatch; }
goto P_0c0a2542;
P_0c0a2540: /* original e410, guest PC 0x0c0a2540 */
if(!s->budget--) { s->failed_pc=0x0c0a2540u; return 0; }
r[4]=0x00000010u;
goto P_0c0a2542;
P_0c0a2542: /* original d23e, guest PC 0x0c0a2542 */
if(!s->budget--) { s->failed_pc=0x0c0a2542u; return 0; }
r[2]=read(ram,0x0c0a263cu,4);
goto P_0c0a2544;
P_0c0a2544: /* original dd3c, guest PC 0x0c0a2544 */
if(!s->budget--) { s->failed_pc=0x0c0a2544u; return 0; }
r[13]=read(ram,0x0c0a2638u,4);
goto P_0c0a2546;
P_0c0a2546: /* original 4d0b, guest PC 0x0c0a2546 */
if(!s->budget--) { s->failed_pc=0x0c0a2546u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a254au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a254au) { target=s->pc; goto dispatch; }
goto P_0c0a254a;
P_0c0a2548: /* original 2f26, guest PC 0x0c0a2548 */
if(!s->budget--) { s->failed_pc=0x0c0a2548u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a254a;
P_0c0a254a: /* original 9562, guest PC 0x0c0a254a */
if(!s->budget--) { s->failed_pc=0x0c0a254au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2612u,2);
goto P_0c0a254c;
P_0c0a254c: /* original 4e0b, guest PC 0x0c0a254c */
if(!s->budget--) { s->failed_pc=0x0c0a254cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2550u;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2550u) { target=s->pc; goto dispatch; }
goto P_0c0a2550;
P_0c0a254e: /* original e410, guest PC 0x0c0a254e */
if(!s->budget--) { s->failed_pc=0x0c0a254eu; return 0; }
r[4]=0x00000010u;
goto P_0c0a2550;
P_0c0a2550: /* original d33b, guest PC 0x0c0a2550 */
if(!s->budget--) { s->failed_pc=0x0c0a2550u; return 0; }
r[3]=read(ram,0x0c0a2640u,4);
goto P_0c0a2552;
P_0c0a2552: /* original 4d0b, guest PC 0x0c0a2552 */
if(!s->budget--) { s->failed_pc=0x0c0a2552u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2556u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2556u) { target=s->pc; goto dispatch; }
goto P_0c0a2556;
P_0c0a2554: /* original 2f36, guest PC 0x0c0a2554 */
if(!s->budget--) { s->failed_pc=0x0c0a2554u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2556;
P_0c0a2556: /* original 955c, guest PC 0x0c0a2556 */
if(!s->budget--) { s->failed_pc=0x0c0a2556u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2612u,2);
goto P_0c0a2558;
P_0c0a2558: /* original 4e0b, guest PC 0x0c0a2558 */
if(!s->budget--) { s->failed_pc=0x0c0a2558u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a255cu;
r[4]=0x00000011u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a255cu) { target=s->pc; goto dispatch; }
goto P_0c0a255c;
P_0c0a255a: /* original e411, guest PC 0x0c0a255a */
if(!s->budget--) { s->failed_pc=0x0c0a255au; return 0; }
r[4]=0x00000011u;
goto P_0c0a255c;
P_0c0a255c: /* original d239, guest PC 0x0c0a255c */
if(!s->budget--) { s->failed_pc=0x0c0a255cu; return 0; }
r[2]=read(ram,0x0c0a2644u,4);
goto P_0c0a255e;
P_0c0a255e: /* original 4d0b, guest PC 0x0c0a255e */
if(!s->budget--) { s->failed_pc=0x0c0a255eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2562u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2562u) { target=s->pc; goto dispatch; }
goto P_0c0a2562;
P_0c0a2560: /* original 2f26, guest PC 0x0c0a2560 */
if(!s->budget--) { s->failed_pc=0x0c0a2560u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2562;
P_0c0a2562: /* original d339, guest PC 0x0c0a2562 */
if(!s->budget--) { s->failed_pc=0x0c0a2562u; return 0; }
r[3]=read(ram,0x0c0a2648u,4);
goto P_0c0a2564;
P_0c0a2564: /* original 7f0c, guest PC 0x0c0a2564 */
if(!s->budget--) { s->failed_pc=0x0c0a2564u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2566;
P_0c0a2566: /* original 430b, guest PC 0x0c0a2566 */
if(!s->budget--) { s->failed_pc=0x0c0a2566u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a256au;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a256au) { target=s->pc; goto dispatch; }
goto P_0c0a256a;
P_0c0a2568: /* original e403, guest PC 0x0c0a2568 */
if(!s->budget--) { s->failed_pc=0x0c0a2568u; return 0; }
r[4]=0x00000003u;
goto P_0c0a256a;
P_0c0a256a: /* original 4f26, guest PC 0x0c0a256a */
if(!s->budget--) { s->failed_pc=0x0c0a256au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a256c;
P_0c0a256c: /* original d237, guest PC 0x0c0a256c */
if(!s->budget--) { s->failed_pc=0x0c0a256cu; return 0; }
r[2]=read(ram,0x0c0a264cu,4);
goto P_0c0a256e;
P_0c0a256e: /* original 6df6, guest PC 0x0c0a256e */
if(!s->budget--) { s->failed_pc=0x0c0a256eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2570;
P_0c0a2570: /* original 422b, guest PC 0x0c0a2570 */
if(!s->budget--) { s->failed_pc=0x0c0a2570u; return 0; }
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
P_0c0a2572: /* original 6ef6, guest PC 0x0c0a2572 */
if(!s->budget--) { s->failed_pc=0x0c0a2572u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2574u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2574u; return 0; } return 1;
P_0c0c27ae: /* original 4f22, guest PC 0x0c0c27ae */
if(!s->budget--) { s->failed_pc=0x0c0c27aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c27b0;
P_0c0c27b0: /* original d224, guest PC 0x0c0c27b0 */
if(!s->budget--) { s->failed_pc=0x0c0c27b0u; return 0; }
r[2]=read(ram,0x0c0c2844u,4);
goto P_0c0c27b2;
P_0c0c27b2: /* original 6532, guest PC 0x0c0c27b2 */
if(!s->budget--) { s->failed_pc=0x0c0c27b2u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c27b4;
P_0c0c27b4: /* original 420b, guest PC 0x0c0c27b4 */
if(!s->budget--) { s->failed_pc=0x0c0c27b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c27b8u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27b8u) { target=s->pc; goto dispatch; }
goto P_0c0c27b8;
P_0c0c27b6: /* original e41d, guest PC 0x0c0c27b6 */
if(!s->budget--) { s->failed_pc=0x0c0c27b6u; return 0; }
r[4]=0x0000001du;
goto P_0c0c27b8;
P_0c0c27b8: /* original de1c, guest PC 0x0c0c27b8 */
if(!s->budget--) { s->failed_pc=0x0c0c27b8u; return 0; }
r[14]=read(ram,0x0c0c282cu,4);
goto P_0c0c27ba;
P_0c0c27ba: /* original 942f, guest PC 0x0c0c27ba */
if(!s->budget--) { s->failed_pc=0x0c0c27bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c281cu,2);
goto P_0c0c27bc;
P_0c0c27bc: /* original d31c, guest PC 0x0c0c27bc */
if(!s->budget--) { s->failed_pc=0x0c0c27bcu; return 0; }
r[3]=read(ram,0x0c0c2830u,4);
goto P_0c0c27be;
P_0c0c27be: /* original 66e3, guest PC 0x0c0c27be */
if(!s->budget--) { s->failed_pc=0x0c0c27beu; return 0; }
r[6]=r[14];
goto P_0c0c27c0;
P_0c0c27c0: /* original 7658, guest PC 0x0c0c27c0 */
if(!s->budget--) { s->failed_pc=0x0c0c27c0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c27c2;
P_0c0c27c2: /* original 430b, guest PC 0x0c0c27c2 */
if(!s->budget--) { s->failed_pc=0x0c0c27c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27c6u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27c6u) { target=s->pc; goto dispatch; }
goto P_0c0c27c6;
P_0c0c27c4: /* original 65e3, guest PC 0x0c0c27c4 */
if(!s->budget--) { s->failed_pc=0x0c0c27c4u; return 0; }
r[5]=r[14];
goto P_0c0c27c6;
P_0c0c27c6: /* original d220, guest PC 0x0c0c27c6 */
if(!s->budget--) { s->failed_pc=0x0c0c27c6u; return 0; }
r[2]=read(ram,0x0c0c2848u,4);
goto P_0c0c27c8;
P_0c0c27c8: /* original 420b, guest PC 0x0c0c27c8 */
if(!s->budget--) { s->failed_pc=0x0c0c27c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c27ccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27ccu) { target=s->pc; goto dispatch; }
goto P_0c0c27cc;
P_0c0c27ca: /* original 64e3, guest PC 0x0c0c27ca */
if(!s->budget--) { s->failed_pc=0x0c0c27cau; return 0; }
r[4]=r[14];
goto P_0c0c27cc;
P_0c0c27cc: /* original e300, guest PC 0x0c0c27cc */
if(!s->budget--) { s->failed_pc=0x0c0c27ccu; return 0; }
r[3]=0x00000000u;
goto P_0c0c27ce;
P_0c0c27ce: /* original 64e3, guest PC 0x0c0c27ce */
if(!s->budget--) { s->failed_pc=0x0c0c27ceu; return 0; }
r[4]=r[14];
goto P_0c0c27d0;
P_0c0c27d0: /* original 6533, guest PC 0x0c0c27d0 */
if(!s->budget--) { s->failed_pc=0x0c0c27d0u; return 0; }
r[5]=r[3];
goto P_0c0c27d2;
P_0c0c27d2: /* original e63f, guest PC 0x0c0c27d2 */
if(!s->budget--) { s->failed_pc=0x0c0c27d2u; return 0; }
r[6]=0x0000003fu;
goto P_0c0c27d4;
P_0c0c27d4: /* original 2f36, guest PC 0x0c0c27d4 */
if(!s->budget--) { s->failed_pc=0x0c0c27d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c27d6;
P_0c0c27d6: /* original e731, guest PC 0x0c0c27d6 */
if(!s->budget--) { s->failed_pc=0x0c0c27d6u; return 0; }
r[7]=0x00000031u;
goto P_0c0c27d8;
P_0c0c27d8: /* original b82d, guest PC 0x0c0c27d8 */
if(!s->budget--) { s->failed_pc=0x0c0c27d8u; return 0; }
target=code_base|0x0c0c1836u; r[16]=code_base|0x0c0c27dcu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27dcu) { target=s->pc; goto dispatch; }
goto P_0c0c27dc;
P_0c0c27da: /* original 7458, guest PC 0x0c0c27da */
if(!s->budget--) { s->failed_pc=0x0c0c27dau; return 0; }
r[4]+=0x00000058u;
goto P_0c0c27dc;
P_0c0c27dc: /* original 901f, guest PC 0x0c0c27dc */
if(!s->budget--) { s->failed_pc=0x0c0c27dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c281eu,2);
goto P_0c0c27de;
P_0c0c27de: /* original e400, guest PC 0x0c0c27de */
if(!s->budget--) { s->failed_pc=0x0c0c27deu; return 0; }
r[4]=0x00000000u;
goto P_0c0c27e0;
P_0c0c27e0: /* original e32f, guest PC 0x0c0c27e0 */
if(!s->budget--) { s->failed_pc=0x0c0c27e0u; return 0; }
r[3]=0x0000002fu;
goto P_0c0c27e2;
P_0c0c27e2: /* original 0e46, guest PC 0x0c0c27e2 */
if(!s->budget--) { s->failed_pc=0x0c0c27e2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c27e4;
P_0c0c27e4: /* original 7f04, guest PC 0x0c0c27e4 */
if(!s->budget--) { s->failed_pc=0x0c0c27e4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c27e6;
P_0c0c27e6: /* original 901b, guest PC 0x0c0c27e6 */
if(!s->budget--) { s->failed_pc=0x0c0c27e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2820u,2);
goto P_0c0c27e8;
P_0c0c27e8: /* original 0e46, guest PC 0x0c0c27e8 */
if(!s->budget--) { s->failed_pc=0x0c0c27e8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c27ea;
P_0c0c27ea: /* original 901a, guest PC 0x0c0c27ea */
if(!s->budget--) { s->failed_pc=0x0c0c27eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2822u,2);
goto P_0c0c27ec;
P_0c0c27ec: /* original 0e35, guest PC 0x0c0c27ec */
if(!s->budget--) { s->failed_pc=0x0c0c27ecu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c27ee;
P_0c0c27ee: /* original d317, guest PC 0x0c0c27ee */
if(!s->budget--) { s->failed_pc=0x0c0c27eeu; return 0; }
r[3]=read(ram,0x0c0c284cu,4);
goto P_0c0c27f0;
P_0c0c27f0: /* original 430b, guest PC 0x0c0c27f0 */
if(!s->budget--) { s->failed_pc=0x0c0c27f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27f4u;
r[4]=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27f4u) { target=s->pc; goto dispatch; }
goto P_0c0c27f4;
P_0c0c27f2: /* original e415, guest PC 0x0c0c27f2 */
if(!s->budget--) { s->failed_pc=0x0c0c27f2u; return 0; }
r[4]=0x00000015u;
goto P_0c0c27f4;
P_0c0c27f4: /* original d317, guest PC 0x0c0c27f4 */
if(!s->budget--) { s->failed_pc=0x0c0c27f4u; return 0; }
r[3]=read(ram,0x0c0c2854u,4);
goto P_0c0c27f6;
P_0c0c27f6: /* original d416, guest PC 0x0c0c27f6 */
if(!s->budget--) { s->failed_pc=0x0c0c27f6u; return 0; }
r[4]=read(ram,0x0c0c2850u,4);
goto P_0c0c27f8;
P_0c0c27f8: /* original d211, guest PC 0x0c0c27f8 */
if(!s->budget--) { s->failed_pc=0x0c0c27f8u; return 0; }
r[2]=read(ram,0x0c0c2840u,4);
goto P_0c0c27fa;
P_0c0c27fa: /* original 430b, guest PC 0x0c0c27fa */
if(!s->budget--) { s->failed_pc=0x0c0c27fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27feu;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27feu) { target=s->pc; goto dispatch; }
goto P_0c0c27fe;
P_0c0c27fc: /* original 6522, guest PC 0x0c0c27fc */
if(!s->budget--) { s->failed_pc=0x0c0c27fcu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c27fe;
P_0c0c27fe: /* original 4f26, guest PC 0x0c0c27fe */
if(!s->budget--) { s->failed_pc=0x0c0c27feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2800;
P_0c0c2800: /* original d215, guest PC 0x0c0c2800 */
if(!s->budget--) { s->failed_pc=0x0c0c2800u; return 0; }
r[2]=read(ram,0x0c0c2858u,4);
goto P_0c0c2802;
P_0c0c2802: /* original e315, guest PC 0x0c0c2802 */
if(!s->budget--) { s->failed_pc=0x0c0c2802u; return 0; }
r[3]=0x00000015u;
goto P_0c0c2804;
P_0c0c2804: /* original 2231, guest PC 0x0c0c2804 */
if(!s->budget--) { s->failed_pc=0x0c0c2804u; return 0; }
write(ram,r[2],r[3],2);
goto P_0c0c2806;
P_0c0c2806: /* original 000b, guest PC 0x0c0c2806 */
if(!s->budget--) { s->failed_pc=0x0c0c2806u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2808: /* original 6ef6, guest PC 0x0c0c2808 */
if(!s->budget--) { s->failed_pc=0x0c0c2808u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c280au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c280au; return 0; } return 1;
P_0c0c2cca: /* original 2fe6, guest PC 0x0c0c2cca */
if(!s->budget--) { s->failed_pc=0x0c0c2ccau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2ccc;
P_0c0c2ccc: /* original e71f, guest PC 0x0c0c2ccc */
if(!s->budget--) { s->failed_pc=0x0c0c2cccu; return 0; }
r[7]=0x0000001fu;
if(!vf3_matrix_family(0x0c0c2cceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2cceu; return 0; } return 1;
P_0c0c664c: /* original 4f22, guest PC 0x0c0c664c */
if(!s->budget--) { s->failed_pc=0x0c0c664cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c664e;
P_0c0c664e: /* original 5341, guest PC 0x0c0c664e */
if(!s->budget--) { s->failed_pc=0x0c0c664eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0c6650;
P_0c0c6650: /* original 7ff8, guest PC 0x0c0c6650 */
if(!s->budget--) { s->failed_pc=0x0c0c6650u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c6652;
P_0c0c6652: /* original 1f31, guest PC 0x0c0c6652 */
if(!s->budget--) { s->failed_pc=0x0c0c6652u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c6654;
P_0c0c6654: /* original 5e46, guest PC 0x0c0c6654 */
if(!s->budget--) { s->failed_pc=0x0c0c6654u; return 0; }
r[14]=read(ram,r[4]+24,4);
goto P_0c0c6656;
P_0c0c6656: /* original d311, guest PC 0x0c0c6656 */
if(!s->budget--) { s->failed_pc=0x0c0c6656u; return 0; }
r[3]=read(ram,0x0c0c669cu,4);
goto P_0c0c6658;
P_0c0c6658: /* original 4e29, guest PC 0x0c0c6658 */
if(!s->budget--) { s->failed_pc=0x0c0c6658u; return 0; }
r[14]>>=16;
goto P_0c0c665a;
P_0c0c665a: /* original 4e19, guest PC 0x0c0c665a */
if(!s->budget--) { s->failed_pc=0x0c0c665au; return 0; }
r[14]>>=8;
goto P_0c0c665c;
P_0c0c665c: /* original 2f32, guest PC 0x0c0c665c */
if(!s->budget--) { s->failed_pc=0x0c0c665cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c665e;
P_0c0c665e: /* original d415, guest PC 0x0c0c665e */
if(!s->budget--) { s->failed_pc=0x0c0c665eu; return 0; }
r[4]=read(ram,0x0c0c66b4u,4);
goto P_0c0c6660;
P_0c0c6660: /* original 2e29, guest PC 0x0c0c6660 */
if(!s->budget--) { s->failed_pc=0x0c0c6660u; return 0; }
r[14]&=r[2];
goto P_0c0c6662;
P_0c0c6662: /* original bb17, guest PC 0x0c0c6662 */
if(!s->budget--) { s->failed_pc=0x0c0c6662u; return 0; }
target=code_base|0x0c0c5c94u; r[16]=code_base|0x0c0c6666u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6666u) { target=s->pc; goto dispatch; }
goto P_0c0c6666;
P_0c0c6664: /* original e500, guest PC 0x0c0c6664 */
if(!s->budget--) { s->failed_pc=0x0c0c6664u; return 0; }
r[5]=0x00000000u;
goto P_0c0c6666;
P_0c0c6666: /* original d20e, guest PC 0x0c0c6666 */
if(!s->budget--) { s->failed_pc=0x0c0c6666u; return 0; }
r[2]=read(ram,0x0c0c66a0u,4);
goto P_0c0c6668;
P_0c0c6668: /* original 420b, guest PC 0x0c0c6668 */
if(!s->budget--) { s->failed_pc=0x0c0c6668u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c666cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c666cu) { target=s->pc; goto dispatch; }
goto P_0c0c666c;
P_0c0c666a: /* original 64e3, guest PC 0x0c0c666a */
if(!s->budget--) { s->failed_pc=0x0c0c666au; return 0; }
r[4]=r[14];
goto P_0c0c666c;
P_0c0c666c: /* original d30d, guest PC 0x0c0c666c */
if(!s->budget--) { s->failed_pc=0x0c0c666cu; return 0; }
r[3]=read(ram,0x0c0c66a4u,4);
goto P_0c0c666e;
P_0c0c666e: /* original 65e3, guest PC 0x0c0c666e */
if(!s->budget--) { s->failed_pc=0x0c0c666eu; return 0; }
r[5]=r[14];
goto P_0c0c6670;
P_0c0c6670: /* original 430b, guest PC 0x0c0c6670 */
if(!s->budget--) { s->failed_pc=0x0c0c6670u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6674u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6674u) { target=s->pc; goto dispatch; }
goto P_0c0c6674;
P_0c0c6672: /* original 54f1, guest PC 0x0c0c6672 */
if(!s->budget--) { s->failed_pc=0x0c0c6672u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c6674;
P_0c0c6674: /* original 2008, guest PC 0x0c0c6674 */
if(!s->budget--) { s->failed_pc=0x0c0c6674u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c6676;
P_0c0c6676: /* original 8903, guest PC 0x0c0c6676 */
if(!s->budget--) { s->failed_pc=0x0c0c6676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6680; }
goto P_0c0c6678;
P_0c0c6678: /* original d30b, guest PC 0x0c0c6678 */
if(!s->budget--) { s->failed_pc=0x0c0c6678u; return 0; }
r[3]=read(ram,0x0c0c66a8u,4);
goto P_0c0c667a;
P_0c0c667a: /* original 950a, guest PC 0x0c0c667a */
if(!s->budget--) { s->failed_pc=0x0c0c667au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6692u,2);
goto P_0c0c667c;
P_0c0c667c: /* original 430b, guest PC 0x0c0c667c */
if(!s->budget--) { s->failed_pc=0x0c0c667cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6680u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6680u) { target=s->pc; goto dispatch; }
goto P_0c0c6680;
P_0c0c667e: /* original e401, guest PC 0x0c0c667e */
if(!s->budget--) { s->failed_pc=0x0c0c667eu; return 0; }
r[4]=0x00000001u;
goto P_0c0c6680;
P_0c0c6680: /* original 62f2, guest PC 0x0c0c6680 */
if(!s->budget--) { s->failed_pc=0x0c0c6680u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c6682;
P_0c0c6682: /* original 7f08, guest PC 0x0c0c6682 */
if(!s->budget--) { s->failed_pc=0x0c0c6682u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c6684;
P_0c0c6684: /* original 9006, guest PC 0x0c0c6684 */
if(!s->budget--) { s->failed_pc=0x0c0c6684u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6694u,2);
goto P_0c0c6686;
P_0c0c6686: /* original e3ff, guest PC 0x0c0c6686 */
if(!s->budget--) { s->failed_pc=0x0c0c6686u; return 0; }
r[3]=0xffffffffu;
goto P_0c0c6688;
P_0c0c6688: /* original 4f26, guest PC 0x0c0c6688 */
if(!s->budget--) { s->failed_pc=0x0c0c6688u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c668a;
P_0c0c668a: /* original 0236, guest PC 0x0c0c668a */
if(!s->budget--) { s->failed_pc=0x0c0c668au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c668c;
P_0c0c668c: /* original e000, guest PC 0x0c0c668c */
if(!s->budget--) { s->failed_pc=0x0c0c668cu; return 0; }
r[0]=0x00000000u;
goto P_0c0c668e;
P_0c0c668e: /* original 000b, guest PC 0x0c0c668e */
if(!s->budget--) { s->failed_pc=0x0c0c668eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6690: /* original 6ef6, guest PC 0x0c0c6690 */
if(!s->budget--) { s->failed_pc=0x0c0c6690u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c6692u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6692u; return 0; } return 1;
P_0c0c74b8: /* original 2fe6, guest PC 0x0c0c74b8 */
if(!s->budget--) { s->failed_pc=0x0c0c74b8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c74ba;
P_0c0c74ba: /* original 2fd6, guest PC 0x0c0c74ba */
if(!s->budget--) { s->failed_pc=0x0c0c74bau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(0x0c0c74bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c74bcu; return 0; } return 1;
P_0c0c8d8e: /* original 2fe6, guest PC 0x0c0c8d8e */
if(!s->budget--) { s->failed_pc=0x0c0c8d8eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8d90;
P_0c0c8d90: /* original 4f22, guest PC 0x0c0c8d90 */
if(!s->budget--) { s->failed_pc=0x0c0c8d90u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8d92;
P_0c0c8d92: /* original 9452, guest PC 0x0c0c8d92 */
if(!s->budget--) { s->failed_pc=0x0c0c8d92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8e3au,2);
goto P_0c0c8d94;
P_0c0c8d94: /* original d22d, guest PC 0x0c0c8d94 */
if(!s->budget--) { s->failed_pc=0x0c0c8d94u; return 0; }
r[2]=read(ram,0x0c0c8e4cu,4);
goto P_0c0c8d96;
P_0c0c8d96: /* original de2b, guest PC 0x0c0c8d96 */
if(!s->budget--) { s->failed_pc=0x0c0c8d96u; return 0; }
r[14]=read(ram,0x0c0c8e44u,4);
goto P_0c0c8d98;
P_0c0c8d98: /* original d32b, guest PC 0x0c0c8d98 */
if(!s->budget--) { s->failed_pc=0x0c0c8d98u; return 0; }
r[3]=read(ram,0x0c0c8e48u,4);
goto P_0c0c8d9a;
P_0c0c8d9a: /* original 420b, guest PC 0x0c0c8d9a */
if(!s->budget--) { s->failed_pc=0x0c0c8d9au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8d9eu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8d9eu) { target=s->pc; goto dispatch; }
goto P_0c0c8d9e;
P_0c0c8d9c: /* original 2f36, guest PC 0x0c0c8d9c */
if(!s->budget--) { s->failed_pc=0x0c0c8d9cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8d9e;
P_0c0c8d9e: /* original 7f04, guest PC 0x0c0c8d9e */
if(!s->budget--) { s->failed_pc=0x0c0c8d9eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8da0;
P_0c0c8da0: /* original d32b, guest PC 0x0c0c8da0 */
if(!s->budget--) { s->failed_pc=0x0c0c8da0u; return 0; }
r[3]=read(ram,0x0c0c8e50u,4);
goto P_0c0c8da2;
P_0c0c8da2: /* original 430b, guest PC 0x0c0c8da2 */
if(!s->budget--) { s->failed_pc=0x0c0c8da2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8da6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8da6u) { target=s->pc; goto dispatch; }
goto P_0c0c8da6;
P_0c0c8da4: /* original 0009, guest PC 0x0c0c8da4 */
if(!s->budget--) { s->failed_pc=0x0c0c8da4u; return 0; }
goto P_0c0c8da6;
P_0c0c8da6: /* original d22b, guest PC 0x0c0c8da6 */
if(!s->budget--) { s->failed_pc=0x0c0c8da6u; return 0; }
r[2]=read(ram,0x0c0c8e54u,4);
goto P_0c0c8da8;
P_0c0c8da8: /* original 420b, guest PC 0x0c0c8da8 */
if(!s->budget--) { s->failed_pc=0x0c0c8da8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8dacu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8dacu) { target=s->pc; goto dispatch; }
goto P_0c0c8dac;
P_0c0c8daa: /* original 0009, guest PC 0x0c0c8daa */
if(!s->budget--) { s->failed_pc=0x0c0c8daau; return 0; }
goto P_0c0c8dac;
P_0c0c8dac: /* original d32a, guest PC 0x0c0c8dac */
if(!s->budget--) { s->failed_pc=0x0c0c8dacu; return 0; }
r[3]=read(ram,0x0c0c8e58u,4);
goto P_0c0c8dae;
P_0c0c8dae: /* original 430b, guest PC 0x0c0c8dae */
if(!s->budget--) { s->failed_pc=0x0c0c8daeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8db2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8db2u) { target=s->pc; goto dispatch; }
goto P_0c0c8db2;
P_0c0c8db0: /* original 0009, guest PC 0x0c0c8db0 */
if(!s->budget--) { s->failed_pc=0x0c0c8db0u; return 0; }
goto P_0c0c8db2;
P_0c0c8db2: /* original 9043, guest PC 0x0c0c8db2 */
if(!s->budget--) { s->failed_pc=0x0c0c8db2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8e3cu,2);
goto P_0c0c8db4;
P_0c0c8db4: /* original e304, guest PC 0x0c0c8db4 */
if(!s->budget--) { s->failed_pc=0x0c0c8db4u; return 0; }
r[3]=0x00000004u;
goto P_0c0c8db6;
P_0c0c8db6: /* original 04ee, guest PC 0x0c0c8db6 */
if(!s->budget--) { s->failed_pc=0x0c0c8db6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c8db8;
P_0c0c8db8: /* original 2348, guest PC 0x0c0c8db8 */
if(!s->budget--) { s->failed_pc=0x0c0c8db8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c8dba;
P_0c0c8dba: /* original 8b02, guest PC 0x0c0c8dba */
if(!s->budget--) { s->failed_pc=0x0c0c8dbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8dc2; }
goto P_0c0c8dbc;
P_0c0c8dbc: /* original d227, guest PC 0x0c0c8dbc */
if(!s->budget--) { s->failed_pc=0x0c0c8dbcu; return 0; }
r[2]=read(ram,0x0c0c8e5cu,4);
goto P_0c0c8dbe;
P_0c0c8dbe: /* original 2428, guest PC 0x0c0c8dbe */
if(!s->budget--) { s->failed_pc=0x0c0c8dbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c8dc0;
P_0c0c8dc0: /* original 89ee, guest PC 0x0c0c8dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c8dc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8da0; }
goto P_0c0c8dc2;
P_0c0c8dc2: /* original d323, guest PC 0x0c0c8dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c8dc2u; return 0; }
r[3]=read(ram,0x0c0c8e50u,4);
goto P_0c0c8dc4;
P_0c0c8dc4: /* original 430b, guest PC 0x0c0c8dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c8dc4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8dc8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8dc8u) { target=s->pc; goto dispatch; }
goto P_0c0c8dc8;
P_0c0c8dc6: /* original 0009, guest PC 0x0c0c8dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c8dc6u; return 0; }
goto P_0c0c8dc8;
P_0c0c8dc8: /* original d122, guest PC 0x0c0c8dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c8dc8u; return 0; }
r[1]=read(ram,0x0c0c8e54u,4);
goto P_0c0c8dca;
P_0c0c8dca: /* original 410b, guest PC 0x0c0c8dca */
if(!s->budget--) { s->failed_pc=0x0c0c8dcau; return 0; }
target=r[1];
r[16]=code_base|0x0c0c8dceu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8dceu) { target=s->pc; goto dispatch; }
goto P_0c0c8dce;
P_0c0c8dcc: /* original 0009, guest PC 0x0c0c8dcc */
if(!s->budget--) { s->failed_pc=0x0c0c8dccu; return 0; }
goto P_0c0c8dce;
P_0c0c8dce: /* original d322, guest PC 0x0c0c8dce */
if(!s->budget--) { s->failed_pc=0x0c0c8dceu; return 0; }
r[3]=read(ram,0x0c0c8e58u,4);
goto P_0c0c8dd0;
P_0c0c8dd0: /* original 430b, guest PC 0x0c0c8dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c8dd0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8dd4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8dd4u) { target=s->pc; goto dispatch; }
goto P_0c0c8dd4;
P_0c0c8dd2: /* original 0009, guest PC 0x0c0c8dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c8dd2u; return 0; }
goto P_0c0c8dd4;
P_0c0c8dd4: /* original 9032, guest PC 0x0c0c8dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c8dd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8e3cu,2);
goto P_0c0c8dd6;
P_0c0c8dd6: /* original e304, guest PC 0x0c0c8dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c8dd6u; return 0; }
r[3]=0x00000004u;
goto P_0c0c8dd8;
P_0c0c8dd8: /* original 04ee, guest PC 0x0c0c8dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c8dd8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c8dda;
P_0c0c8dda: /* original 2348, guest PC 0x0c0c8dda */
if(!s->budget--) { s->failed_pc=0x0c0c8ddau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c8ddc;
P_0c0c8ddc: /* original 8bf1, guest PC 0x0c0c8ddc */
if(!s->budget--) { s->failed_pc=0x0c0c8ddcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8dc2; }
goto P_0c0c8dde;
P_0c0c8dde: /* original d21f, guest PC 0x0c0c8dde */
if(!s->budget--) { s->failed_pc=0x0c0c8ddeu; return 0; }
r[2]=read(ram,0x0c0c8e5cu,4);
goto P_0c0c8de0;
P_0c0c8de0: /* original 2428, guest PC 0x0c0c8de0 */
if(!s->budget--) { s->failed_pc=0x0c0c8de0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c8de2;
P_0c0c8de2: /* original 8bee, guest PC 0x0c0c8de2 */
if(!s->budget--) { s->failed_pc=0x0c0c8de2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8dc2; }
goto P_0c0c8de4;
P_0c0c8de4: /* original 4f26, guest PC 0x0c0c8de4 */
if(!s->budget--) { s->failed_pc=0x0c0c8de4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8de6;
P_0c0c8de6: /* original 000b, guest PC 0x0c0c8de6 */
if(!s->budget--) { s->failed_pc=0x0c0c8de6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c8de8: /* original 6ef6, guest PC 0x0c0c8de8 */
if(!s->budget--) { s->failed_pc=0x0c0c8de8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c8deau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8deau; return 0; } return 1;
P_0c0c8f76: /* original 4f22, guest PC 0x0c0c8f76 */
if(!s->budget--) { s->failed_pc=0x0c0c8f76u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8f78;
P_0c0c8f78: /* original d32a, guest PC 0x0c0c8f78 */
if(!s->budget--) { s->failed_pc=0x0c0c8f78u; return 0; }
r[3]=read(ram,0x0c0c9024u,4);
goto P_0c0c8f7a;
P_0c0c8f7a: /* original de29, guest PC 0x0c0c8f7a */
if(!s->budget--) { s->failed_pc=0x0c0c8f7au; return 0; }
r[14]=read(ram,0x0c0c9020u,4);
goto P_0c0c8f7c;
P_0c0c8f7c: /* original 430b, guest PC 0x0c0c8f7c */
if(!s->budget--) { s->failed_pc=0x0c0c8f7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8f80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8f80u) { target=s->pc; goto dispatch; }
goto P_0c0c8f80;
P_0c0c8f7e: /* original 0009, guest PC 0x0c0c8f7e */
if(!s->budget--) { s->failed_pc=0x0c0c8f7eu; return 0; }
goto P_0c0c8f80;
P_0c0c8f80: /* original bf05, guest PC 0x0c0c8f80 */
if(!s->budget--) { s->failed_pc=0x0c0c8f80u; return 0; }
target=code_base|0x0c0c8d8eu; r[16]=code_base|0x0c0c8f84u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8f84u) { target=s->pc; goto dispatch; }
goto P_0c0c8f84;
P_0c0c8f82: /* original 0009, guest PC 0x0c0c8f82 */
if(!s->budget--) { s->failed_pc=0x0c0c8f82u; return 0; }
goto P_0c0c8f84;
P_0c0c8f84: /* original d328, guest PC 0x0c0c8f84 */
if(!s->budget--) { s->failed_pc=0x0c0c8f84u; return 0; }
r[3]=read(ram,0x0c0c9028u,4);
goto P_0c0c8f86;
P_0c0c8f86: /* original 430b, guest PC 0x0c0c8f86 */
if(!s->budget--) { s->failed_pc=0x0c0c8f86u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8f8au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8f8au) { target=s->pc; goto dispatch; }
goto P_0c0c8f8a;
P_0c0c8f88: /* original 0009, guest PC 0x0c0c8f88 */
if(!s->budget--) { s->failed_pc=0x0c0c8f88u; return 0; }
goto P_0c0c8f8a;
P_0c0c8f8a: /* original d329, guest PC 0x0c0c8f8a */
if(!s->budget--) { s->failed_pc=0x0c0c8f8au; return 0; }
r[3]=read(ram,0x0c0c9030u,4);
goto P_0c0c8f8c;
P_0c0c8f8c: /* original 9446, guest PC 0x0c0c8f8c */
if(!s->budget--) { s->failed_pc=0x0c0c8f8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c901cu,2);
goto P_0c0c8f8e;
P_0c0c8f8e: /* original d227, guest PC 0x0c0c8f8e */
if(!s->budget--) { s->failed_pc=0x0c0c8f8eu; return 0; }
r[2]=read(ram,0x0c0c902cu,4);
goto P_0c0c8f90;
P_0c0c8f90: /* original 430b, guest PC 0x0c0c8f90 */
if(!s->budget--) { s->failed_pc=0x0c0c8f90u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8f94u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8f94u) { target=s->pc; goto dispatch; }
goto P_0c0c8f94;
P_0c0c8f92: /* original 2f26, guest PC 0x0c0c8f92 */
if(!s->budget--) { s->failed_pc=0x0c0c8f92u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8f94;
P_0c0c8f94: /* original 7f04, guest PC 0x0c0c8f94 */
if(!s->budget--) { s->failed_pc=0x0c0c8f94u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8f96;
P_0c0c8f96: /* original d227, guest PC 0x0c0c8f96 */
if(!s->budget--) { s->failed_pc=0x0c0c8f96u; return 0; }
r[2]=read(ram,0x0c0c9034u,4);
goto P_0c0c8f98;
P_0c0c8f98: /* original 420b, guest PC 0x0c0c8f98 */
if(!s->budget--) { s->failed_pc=0x0c0c8f98u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8f9cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8f9cu) { target=s->pc; goto dispatch; }
goto P_0c0c8f9c;
P_0c0c8f9a: /* original 0009, guest PC 0x0c0c8f9a */
if(!s->budget--) { s->failed_pc=0x0c0c8f9au; return 0; }
goto P_0c0c8f9c;
P_0c0c8f9c: /* original d326, guest PC 0x0c0c8f9c */
if(!s->budget--) { s->failed_pc=0x0c0c8f9cu; return 0; }
r[3]=read(ram,0x0c0c9038u,4);
goto P_0c0c8f9e;
P_0c0c8f9e: /* original 430b, guest PC 0x0c0c8f9e */
if(!s->budget--) { s->failed_pc=0x0c0c8f9eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8fa2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8fa2u) { target=s->pc; goto dispatch; }
goto P_0c0c8fa2;
P_0c0c8fa0: /* original 0009, guest PC 0x0c0c8fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c8fa0u; return 0; }
goto P_0c0c8fa2;
P_0c0c8fa2: /* original d226, guest PC 0x0c0c8fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c8fa2u; return 0; }
r[2]=read(ram,0x0c0c903cu,4);
goto P_0c0c8fa4;
P_0c0c8fa4: /* original 420b, guest PC 0x0c0c8fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c8fa4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8fa8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8fa8u) { target=s->pc; goto dispatch; }
goto P_0c0c8fa8;
P_0c0c8fa6: /* original 0009, guest PC 0x0c0c8fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c8fa6u; return 0; }
goto P_0c0c8fa8;
P_0c0c8fa8: /* original 9039, guest PC 0x0c0c8fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c8fa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c901eu,2);
goto P_0c0c8faa;
P_0c0c8faa: /* original e304, guest PC 0x0c0c8faa */
if(!s->budget--) { s->failed_pc=0x0c0c8faau; return 0; }
r[3]=0x00000004u;
goto P_0c0c8fac;
P_0c0c8fac: /* original 04ee, guest PC 0x0c0c8fac */
if(!s->budget--) { s->failed_pc=0x0c0c8facu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c8fae;
P_0c0c8fae: /* original 2348, guest PC 0x0c0c8fae */
if(!s->budget--) { s->failed_pc=0x0c0c8faeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c8fb0;
P_0c0c8fb0: /* original 8b02, guest PC 0x0c0c8fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c8fb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8fb8; }
goto P_0c0c8fb2;
P_0c0c8fb2: /* original d223, guest PC 0x0c0c8fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c8fb2u; return 0; }
r[2]=read(ram,0x0c0c9040u,4);
goto P_0c0c8fb4;
P_0c0c8fb4: /* original 2428, guest PC 0x0c0c8fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c8fb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c8fb6;
P_0c0c8fb6: /* original 89ee, guest PC 0x0c0c8fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c8fb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8f96; }
goto P_0c0c8fb8;
P_0c0c8fb8: /* original 4f26, guest PC 0x0c0c8fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c8fb8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8fba;
P_0c0c8fba: /* original e000, guest PC 0x0c0c8fba */
if(!s->budget--) { s->failed_pc=0x0c0c8fbau; return 0; }
r[0]=0x00000000u;
goto P_0c0c8fbc;
P_0c0c8fbc: /* original 80eb, guest PC 0x0c0c8fbc */
if(!s->budget--) { s->failed_pc=0x0c0c8fbcu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c8fbe;
P_0c0c8fbe: /* original d321, guest PC 0x0c0c8fbe */
if(!s->budget--) { s->failed_pc=0x0c0c8fbeu; return 0; }
r[3]=read(ram,0x0c0c9044u,4);
goto P_0c0c8fc0;
P_0c0c8fc0: /* original 432b, guest PC 0x0c0c8fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c8fc0u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: if(!vf3_matrix_family(0x0c09abc4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09abc4u; return 0; } return 1;
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
P_0c0c8fc2: /* original 6ef6, guest PC 0x0c0c8fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c8fc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c8fc4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c8fc4u; return 0; } return 1;
P_0c0c8fca: /* original 4f22, guest PC 0x0c0c8fca */
if(!s->budget--) { s->failed_pc=0x0c0c8fcau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8fcc;
P_0c0c8fcc: /* original d31e, guest PC 0x0c0c8fcc */
if(!s->budget--) { s->failed_pc=0x0c0c8fccu; return 0; }
r[3]=read(ram,0x0c0c9048u,4);
goto P_0c0c8fce;
P_0c0c8fce: /* original de14, guest PC 0x0c0c8fce */
if(!s->budget--) { s->failed_pc=0x0c0c8fceu; return 0; }
r[14]=read(ram,0x0c0c9020u,4);
goto P_0c0c8fd0;
P_0c0c8fd0: /* original 430b, guest PC 0x0c0c8fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c8fd0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8fd4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8fd4u) { target=s->pc; goto dispatch; }
goto P_0c0c8fd4;
P_0c0c8fd2: /* original 0009, guest PC 0x0c0c8fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c8fd2u; return 0; }
goto P_0c0c8fd4;
P_0c0c8fd4: /* original bedb, guest PC 0x0c0c8fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c8fd4u; return 0; }
target=code_base|0x0c0c8d8eu; r[16]=code_base|0x0c0c8fd8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8fd8u) { target=s->pc; goto dispatch; }
goto P_0c0c8fd8;
P_0c0c8fd6: /* original 0009, guest PC 0x0c0c8fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c8fd6u; return 0; }
goto P_0c0c8fd8;
P_0c0c8fd8: /* original d31c, guest PC 0x0c0c8fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c8fd8u; return 0; }
r[3]=read(ram,0x0c0c904cu,4);
goto P_0c0c8fda;
P_0c0c8fda: /* original 430b, guest PC 0x0c0c8fda */
if(!s->budget--) { s->failed_pc=0x0c0c8fdau; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8fdeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8fdeu) { target=s->pc; goto dispatch; }
goto P_0c0c8fde;
P_0c0c8fdc: /* original 0009, guest PC 0x0c0c8fdc */
if(!s->budget--) { s->failed_pc=0x0c0c8fdcu; return 0; }
goto P_0c0c8fde;
P_0c0c8fde: /* original d314, guest PC 0x0c0c8fde */
if(!s->budget--) { s->failed_pc=0x0c0c8fdeu; return 0; }
r[3]=read(ram,0x0c0c9030u,4);
goto P_0c0c8fe0;
P_0c0c8fe0: /* original 941c, guest PC 0x0c0c8fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c8fe0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c901cu,2);
goto P_0c0c8fe2;
P_0c0c8fe2: /* original d212, guest PC 0x0c0c8fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c8fe2u; return 0; }
r[2]=read(ram,0x0c0c902cu,4);
goto P_0c0c8fe4;
P_0c0c8fe4: /* original 430b, guest PC 0x0c0c8fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c8fe4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8fe8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8fe8u) { target=s->pc; goto dispatch; }
goto P_0c0c8fe8;
P_0c0c8fe6: /* original 2f26, guest PC 0x0c0c8fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c8fe6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8fe8;
P_0c0c8fe8: /* original 7f04, guest PC 0x0c0c8fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c8fe8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8fea;
P_0c0c8fea: /* original d212, guest PC 0x0c0c8fea */
if(!s->budget--) { s->failed_pc=0x0c0c8feau; return 0; }
r[2]=read(ram,0x0c0c9034u,4);
goto P_0c0c8fec;
P_0c0c8fec: /* original 420b, guest PC 0x0c0c8fec */
if(!s->budget--) { s->failed_pc=0x0c0c8fecu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8ff0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8ff0u) { target=s->pc; goto dispatch; }
goto P_0c0c8ff0;
P_0c0c8fee: /* original 0009, guest PC 0x0c0c8fee */
if(!s->budget--) { s->failed_pc=0x0c0c8feeu; return 0; }
goto P_0c0c8ff0;
P_0c0c8ff0: /* original d311, guest PC 0x0c0c8ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ff0u; return 0; }
r[3]=read(ram,0x0c0c9038u,4);
goto P_0c0c8ff2;
P_0c0c8ff2: /* original 430b, guest PC 0x0c0c8ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c8ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c8ff6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8ff6u) { target=s->pc; goto dispatch; }
goto P_0c0c8ff6;
P_0c0c8ff4: /* original 0009, guest PC 0x0c0c8ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c8ff4u; return 0; }
goto P_0c0c8ff6;
P_0c0c8ff6: /* original d211, guest PC 0x0c0c8ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c8ff6u; return 0; }
r[2]=read(ram,0x0c0c903cu,4);
goto P_0c0c8ff8;
P_0c0c8ff8: /* original 420b, guest PC 0x0c0c8ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c8ff8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c8ffcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c8ffcu) { target=s->pc; goto dispatch; }
goto P_0c0c8ffc;
P_0c0c8ffa: /* original 0009, guest PC 0x0c0c8ffa */
if(!s->budget--) { s->failed_pc=0x0c0c8ffau; return 0; }
goto P_0c0c8ffc;
P_0c0c8ffc: /* original 900f, guest PC 0x0c0c8ffc */
if(!s->budget--) { s->failed_pc=0x0c0c8ffcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c901eu,2);
goto P_0c0c8ffe;
P_0c0c8ffe: /* original e304, guest PC 0x0c0c8ffe */
if(!s->budget--) { s->failed_pc=0x0c0c8ffeu; return 0; }
r[3]=0x00000004u;
goto P_0c0c9000;
P_0c0c9000: /* original 04ee, guest PC 0x0c0c9000 */
if(!s->budget--) { s->failed_pc=0x0c0c9000u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c9002;
P_0c0c9002: /* original 2348, guest PC 0x0c0c9002 */
if(!s->budget--) { s->failed_pc=0x0c0c9002u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c9004;
P_0c0c9004: /* original 8b02, guest PC 0x0c0c9004 */
if(!s->budget--) { s->failed_pc=0x0c0c9004u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c900c; }
goto P_0c0c9006;
P_0c0c9006: /* original d20e, guest PC 0x0c0c9006 */
if(!s->budget--) { s->failed_pc=0x0c0c9006u; return 0; }
r[2]=read(ram,0x0c0c9040u,4);
goto P_0c0c9008;
P_0c0c9008: /* original 2428, guest PC 0x0c0c9008 */
if(!s->budget--) { s->failed_pc=0x0c0c9008u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c900a;
P_0c0c900a: /* original 89ee, guest PC 0x0c0c900a */
if(!s->budget--) { s->failed_pc=0x0c0c900au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8fea; }
goto P_0c0c900c;
P_0c0c900c: /* original 4f26, guest PC 0x0c0c900c */
if(!s->budget--) { s->failed_pc=0x0c0c900cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c900e;
P_0c0c900e: /* original e000, guest PC 0x0c0c900e */
if(!s->budget--) { s->failed_pc=0x0c0c900eu; return 0; }
r[0]=0x00000000u;
goto P_0c0c9010;
P_0c0c9010: /* original 80eb, guest PC 0x0c0c9010 */
if(!s->budget--) { s->failed_pc=0x0c0c9010u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c9012;
P_0c0c9012: /* original d30c, guest PC 0x0c0c9012 */
if(!s->budget--) { s->failed_pc=0x0c0c9012u; return 0; }
r[3]=read(ram,0x0c0c9044u,4);
goto P_0c0c9014;
P_0c0c9014: /* original 432b, guest PC 0x0c0c9014 */
if(!s->budget--) { s->failed_pc=0x0c0c9014u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: if(!vf3_matrix_family(0x0c09abc4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09abc4u; return 0; } return 1;
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
P_0c0c9016: /* original 6ef6, guest PC 0x0c0c9016 */
if(!s->budget--) { s->failed_pc=0x0c0c9016u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9018u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9018u; return 0; } return 1;
P_0c0c9052: /* original 4f22, guest PC 0x0c0c9052 */
if(!s->budget--) { s->failed_pc=0x0c0c9052u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9054;
P_0c0c9054: /* original d337, guest PC 0x0c0c9054 */
if(!s->budget--) { s->failed_pc=0x0c0c9054u; return 0; }
r[3]=read(ram,0x0c0c9134u,4);
goto P_0c0c9056;
P_0c0c9056: /* original de36, guest PC 0x0c0c9056 */
if(!s->budget--) { s->failed_pc=0x0c0c9056u; return 0; }
r[14]=read(ram,0x0c0c9130u,4);
goto P_0c0c9058;
P_0c0c9058: /* original 430b, guest PC 0x0c0c9058 */
if(!s->budget--) { s->failed_pc=0x0c0c9058u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c905cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c905cu) { target=s->pc; goto dispatch; }
goto P_0c0c905c;
P_0c0c905a: /* original 0009, guest PC 0x0c0c905a */
if(!s->budget--) { s->failed_pc=0x0c0c905au; return 0; }
goto P_0c0c905c;
P_0c0c905c: /* original d337, guest PC 0x0c0c905c */
if(!s->budget--) { s->failed_pc=0x0c0c905cu; return 0; }
r[3]=read(ram,0x0c0c913cu,4);
goto P_0c0c905e;
P_0c0c905e: /* original 9465, guest PC 0x0c0c905e */
if(!s->budget--) { s->failed_pc=0x0c0c905eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c912cu,2);
goto P_0c0c9060;
P_0c0c9060: /* original d235, guest PC 0x0c0c9060 */
if(!s->budget--) { s->failed_pc=0x0c0c9060u; return 0; }
r[2]=read(ram,0x0c0c9138u,4);
goto P_0c0c9062;
P_0c0c9062: /* original 430b, guest PC 0x0c0c9062 */
if(!s->budget--) { s->failed_pc=0x0c0c9062u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9066u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9066u) { target=s->pc; goto dispatch; }
goto P_0c0c9066;
P_0c0c9064: /* original 2f26, guest PC 0x0c0c9064 */
if(!s->budget--) { s->failed_pc=0x0c0c9064u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9066;
P_0c0c9066: /* original 7f04, guest PC 0x0c0c9066 */
if(!s->budget--) { s->failed_pc=0x0c0c9066u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c9068;
P_0c0c9068: /* original d235, guest PC 0x0c0c9068 */
if(!s->budget--) { s->failed_pc=0x0c0c9068u; return 0; }
r[2]=read(ram,0x0c0c9140u,4);
goto P_0c0c906a;
P_0c0c906a: /* original 420b, guest PC 0x0c0c906a */
if(!s->budget--) { s->failed_pc=0x0c0c906au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c906eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c906eu) { target=s->pc; goto dispatch; }
goto P_0c0c906e;
P_0c0c906c: /* original 0009, guest PC 0x0c0c906c */
if(!s->budget--) { s->failed_pc=0x0c0c906cu; return 0; }
goto P_0c0c906e;
P_0c0c906e: /* original d335, guest PC 0x0c0c906e */
if(!s->budget--) { s->failed_pc=0x0c0c906eu; return 0; }
r[3]=read(ram,0x0c0c9144u,4);
goto P_0c0c9070;
P_0c0c9070: /* original 430b, guest PC 0x0c0c9070 */
if(!s->budget--) { s->failed_pc=0x0c0c9070u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9074u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9074u) { target=s->pc; goto dispatch; }
goto P_0c0c9074;
P_0c0c9072: /* original 0009, guest PC 0x0c0c9072 */
if(!s->budget--) { s->failed_pc=0x0c0c9072u; return 0; }
goto P_0c0c9074;
P_0c0c9074: /* original d234, guest PC 0x0c0c9074 */
if(!s->budget--) { s->failed_pc=0x0c0c9074u; return 0; }
r[2]=read(ram,0x0c0c9148u,4);
goto P_0c0c9076;
P_0c0c9076: /* original 420b, guest PC 0x0c0c9076 */
if(!s->budget--) { s->failed_pc=0x0c0c9076u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c907au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c907au) { target=s->pc; goto dispatch; }
goto P_0c0c907a;
P_0c0c9078: /* original 0009, guest PC 0x0c0c9078 */
if(!s->budget--) { s->failed_pc=0x0c0c9078u; return 0; }
goto P_0c0c907a;
P_0c0c907a: /* original 9058, guest PC 0x0c0c907a */
if(!s->budget--) { s->failed_pc=0x0c0c907au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c912eu,2);
goto P_0c0c907c;
P_0c0c907c: /* original e304, guest PC 0x0c0c907c */
if(!s->budget--) { s->failed_pc=0x0c0c907cu; return 0; }
r[3]=0x00000004u;
goto P_0c0c907e;
P_0c0c907e: /* original 04ee, guest PC 0x0c0c907e */
if(!s->budget--) { s->failed_pc=0x0c0c907eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c9080;
P_0c0c9080: /* original 2348, guest PC 0x0c0c9080 */
if(!s->budget--) { s->failed_pc=0x0c0c9080u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c9082;
P_0c0c9082: /* original 8bf1, guest PC 0x0c0c9082 */
if(!s->budget--) { s->failed_pc=0x0c0c9082u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9068; }
goto P_0c0c9084;
P_0c0c9084: /* original d231, guest PC 0x0c0c9084 */
if(!s->budget--) { s->failed_pc=0x0c0c9084u; return 0; }
r[2]=read(ram,0x0c0c914cu,4);
goto P_0c0c9086;
P_0c0c9086: /* original 2428, guest PC 0x0c0c9086 */
if(!s->budget--) { s->failed_pc=0x0c0c9086u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c9088;
P_0c0c9088: /* original 8bee, guest PC 0x0c0c9088 */
if(!s->budget--) { s->failed_pc=0x0c0c9088u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9068; }
goto P_0c0c908a;
P_0c0c908a: /* original d32d, guest PC 0x0c0c908a */
if(!s->budget--) { s->failed_pc=0x0c0c908au; return 0; }
r[3]=read(ram,0x0c0c9140u,4);
goto P_0c0c908c;
P_0c0c908c: /* original 430b, guest PC 0x0c0c908c */
if(!s->budget--) { s->failed_pc=0x0c0c908cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9090u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9090u) { target=s->pc; goto dispatch; }
goto P_0c0c9090;
P_0c0c908e: /* original 0009, guest PC 0x0c0c908e */
if(!s->budget--) { s->failed_pc=0x0c0c908eu; return 0; }
goto P_0c0c9090;
P_0c0c9090: /* original d12c, guest PC 0x0c0c9090 */
if(!s->budget--) { s->failed_pc=0x0c0c9090u; return 0; }
r[1]=read(ram,0x0c0c9144u,4);
goto P_0c0c9092;
P_0c0c9092: /* original 410b, guest PC 0x0c0c9092 */
if(!s->budget--) { s->failed_pc=0x0c0c9092u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c9096u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9096u) { target=s->pc; goto dispatch; }
goto P_0c0c9096;
P_0c0c9094: /* original 0009, guest PC 0x0c0c9094 */
if(!s->budget--) { s->failed_pc=0x0c0c9094u; return 0; }
goto P_0c0c9096;
P_0c0c9096: /* original d32c, guest PC 0x0c0c9096 */
if(!s->budget--) { s->failed_pc=0x0c0c9096u; return 0; }
r[3]=read(ram,0x0c0c9148u,4);
goto P_0c0c9098;
P_0c0c9098: /* original 430b, guest PC 0x0c0c9098 */
if(!s->budget--) { s->failed_pc=0x0c0c9098u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c909cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c909cu) { target=s->pc; goto dispatch; }
goto P_0c0c909c;
P_0c0c909a: /* original 0009, guest PC 0x0c0c909a */
if(!s->budget--) { s->failed_pc=0x0c0c909au; return 0; }
goto P_0c0c909c;
P_0c0c909c: /* original 9047, guest PC 0x0c0c909c */
if(!s->budget--) { s->failed_pc=0x0c0c909cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c912eu,2);
goto P_0c0c909e;
P_0c0c909e: /* original e304, guest PC 0x0c0c909e */
if(!s->budget--) { s->failed_pc=0x0c0c909eu; return 0; }
r[3]=0x00000004u;
goto P_0c0c90a0;
P_0c0c90a0: /* original 04ee, guest PC 0x0c0c90a0 */
if(!s->budget--) { s->failed_pc=0x0c0c90a0u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c90a2;
P_0c0c90a2: /* original 2348, guest PC 0x0c0c90a2 */
if(!s->budget--) { s->failed_pc=0x0c0c90a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c90a4;
P_0c0c90a4: /* original 8b02, guest PC 0x0c0c90a4 */
if(!s->budget--) { s->failed_pc=0x0c0c90a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c90ac; }
goto P_0c0c90a6;
P_0c0c90a6: /* original d229, guest PC 0x0c0c90a6 */
if(!s->budget--) { s->failed_pc=0x0c0c90a6u; return 0; }
r[2]=read(ram,0x0c0c914cu,4);
goto P_0c0c90a8;
P_0c0c90a8: /* original 2428, guest PC 0x0c0c90a8 */
if(!s->budget--) { s->failed_pc=0x0c0c90a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c90aa;
P_0c0c90aa: /* original 89ee, guest PC 0x0c0c90aa */
if(!s->budget--) { s->failed_pc=0x0c0c90aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c908a; }
goto P_0c0c90ac;
P_0c0c90ac: /* original 4f26, guest PC 0x0c0c90ac */
if(!s->budget--) { s->failed_pc=0x0c0c90acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c90ae;
P_0c0c90ae: /* original e000, guest PC 0x0c0c90ae */
if(!s->budget--) { s->failed_pc=0x0c0c90aeu; return 0; }
r[0]=0x00000000u;
goto P_0c0c90b0;
P_0c0c90b0: /* original 80eb, guest PC 0x0c0c90b0 */
if(!s->budget--) { s->failed_pc=0x0c0c90b0u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c90b2;
P_0c0c90b2: /* original d327, guest PC 0x0c0c90b2 */
if(!s->budget--) { s->failed_pc=0x0c0c90b2u; return 0; }
r[3]=read(ram,0x0c0c9150u,4);
goto P_0c0c90b4;
P_0c0c90b4: /* original 432b, guest PC 0x0c0c90b4 */
if(!s->budget--) { s->failed_pc=0x0c0c90b4u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: if(!vf3_matrix_family(0x0c09abc4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09abc4u; return 0; } return 1;
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
P_0c0c90b6: /* original 6ef6, guest PC 0x0c0c90b6 */
if(!s->budget--) { s->failed_pc=0x0c0c90b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c90b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c90b8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0103bau,0x0c0103bcu,0x0c0103beu,0x0c0103c0u,0x0c0103c2u,0x0c0103c4u,0x0c0103c6u,0x0c0103c8u,0x0c0103cau,0x0c0103ccu,0x0c0103ceu,0x0c0103d0u,0x0c0103d2u,0x0c0103d4u,0x0c0103d6u,0x0c0103d8u,
0x0c0103dau,0x0c0103dcu,0x0c0103deu,0x0c0103e0u,0x0c0103e2u,0x0c0103e4u,0x0c0103e6u,0x0c0103e8u,0x0c0103eau,0x0c0103ecu,0x0c0103eeu,0x0c0103f0u,0x0c0103f2u,0x0c0103f4u,0x0c0103f6u,0x0c0103f8u,
0x0c0103fau,0x0c0103fcu,0x0c0103feu,0x0c010400u,0x0c010630u,0x0c010632u,0x0c010634u,0x0c010636u,0x0c010638u,0x0c01063au,0x0c01063cu,0x0c01063eu,0x0c010640u,0x0c010642u,0x0c010644u,0x0c010646u,
0x0c010648u,0x0c01064au,0x0c01064cu,0x0c01064eu,0x0c010650u,0x0c010652u,0x0c010654u,0x0c010656u,0x0c010658u,0x0c01065au,0x0c01065cu,0x0c01065eu,0x0c010660u,0x0c010662u,0x0c010664u,0x0c010666u,
0x0c010668u,0x0c01066au,0x0c01066cu,0x0c01066eu,0x0c010670u,0x0c010672u,0x0c010674u,0x0c010676u,0x0c010678u,0x0c01067au,0x0c01067cu,0x0c01067eu,0x0c010680u,0x0c010954u,0x0c010956u,0x0c010958u,
0x0c01095au,0x0c01095cu,0x0c01095eu,0x0c010960u,0x0c010962u,0x0c010964u,0x0c010966u,0x0c010968u,0x0c01096au,0x0c01096cu,0x0c01096eu,0x0c010970u,0x0c010972u,0x0c010974u,0x0c010976u,0x0c010978u,
0x0c01097au,0x0c01097cu,0x0c01097eu,0x0c010980u,0x0c010982u,0x0c010984u,0x0c010986u,0x0c010988u,0x0c01098au,0x0c010f3cu,0x0c010f3eu,0x0c010f40u,0x0c0113b4u,0x0c0113b6u,0x0c0113b8u,0x0c0113bau,
0x0c0113bcu,0x0c0113beu,0x0c0113c0u,0x0c011a24u,0x0c011a26u,0x0c011a28u,0x0c011a2au,0x0c011a2cu,0x0c011a2eu,0x0c011a30u,0x0c011a32u,0x0c011a34u,0x0c011a36u,0x0c011a38u,0x0c011a3au,0x0c011a3cu,
0x0c011a3eu,0x0c011a40u,0x0c011a42u,0x0c011a44u,0x0c011a46u,0x0c011a48u,0x0c011a4au,0x0c011a4cu,0x0c011a4eu,0x0c011a50u,0x0c011a52u,0x0c011a54u,0x0c011a56u,0x0c011a58u,0x0c011a5au,0x0c011a5cu,
0x0c011a5eu,0x0c011a60u,0x0c011a62u,0x0c011a64u,0x0c011a66u,0x0c011a68u,0x0c011a6au,0x0c035270u,0x0c035272u,0x0c035274u,0x0c035276u,0x0c035278u,0x0c03527au,0x0c03527cu,0x0c03527eu,0x0c035280u,
0x0c035282u,0x0c035284u,0x0c035286u,0x0c035288u,0x0c03528au,0x0c03528cu,0x0c03528eu,0x0c035290u,0x0c035292u,0x0c035294u,0x0c035296u,0x0c035298u,0x0c03529au,0x0c03529cu,0x0c03529eu,0x0c0352a0u,
0x0c0352a2u,0x0c0352a4u,0x0c0352a6u,0x0c0352a8u,0x0c0352aau,0x0c0352acu,0x0c0352aeu,0x0c0352b0u,0x0c0352b2u,0x0c0352b4u,0x0c0352b6u,0x0c0352b8u,0x0c0352bau,0x0c0352bcu,0x0c0352beu,0x0c0352c0u,
0x0c0352c2u,0x0c0352c4u,0x0c0352c6u,0x0c0352c8u,0x0c0352cau,0x0c0352ccu,0x0c0352ceu,0x0c0352d0u,0x0c0352d2u,0x0c0352d4u,0x0c0352d6u,0x0c0352d8u,0x0c035306u,0x0c035308u,0x0c03530au,0x0c03530cu,
0x0c03530eu,0x0c035310u,0x0c035312u,0x0c035314u,0x0c035316u,0x0c035318u,0x0c03531au,0x0c03531cu,0x0c03531eu,0x0c035320u,0x0c035322u,0x0c035324u,0x0c035326u,0x0c035328u,0x0c03532au,0x0c03532cu,
0x0c03532eu,0x0c035330u,0x0c035332u,0x0c035334u,0x0c035336u,0x0c035338u,0x0c03533au,0x0c03533cu,0x0c03533eu,0x0c035340u,0x0c035342u,0x0c035344u,0x0c035346u,0x0c035348u,0x0c03534au,0x0c03534cu,
0x0c03534eu,0x0c035350u,0x0c035352u,0x0c035354u,0x0c035356u,0x0c035358u,0x0c03535au,0x0c03535cu,0x0c03535eu,0x0c035360u,0x0c035362u,0x0c035364u,0x0c035366u,0x0c035368u,0x0c03536au,0x0c035518u,
0x0c03551au,0x0c03551cu,0x0c03551eu,0x0c035520u,0x0c035522u,0x0c035524u,0x0c035526u,0x0c035528u,0x0c03552au,0x0c03552cu,0x0c03552eu,0x0c035530u,0x0c035532u,0x0c035534u,0x0c035536u,0x0c035538u,
0x0c03553au,0x0c03553cu,0x0c03553eu,0x0c035540u,0x0c035542u,0x0c035544u,0x0c035546u,0x0c035548u,0x0c03554au,0x0c03554cu,0x0c03554eu,0x0c035550u,0x0c035552u,0x0c035554u,0x0c035556u,0x0c035558u,
0x0c03555au,0x0c03555cu,0x0c03555eu,0x0c035560u,0x0c035562u,0x0c035564u,0x0c035566u,0x0c035568u,0x0c03556au,0x0c03556cu,0x0c03556eu,0x0c035570u,0x0c035572u,0x0c035574u,0x0c035576u,0x0c035578u,
0x0c03557au,0x0c03557cu,0x0c03557eu,0x0c035580u,0x0c035582u,0x0c035584u,0x0c035586u,0x0c035588u,0x0c03558au,0x0c03558cu,0x0c039748u,0x0c03974au,0x0c03974cu,0x0c03974eu,0x0c039750u,0x0c039752u,
0x0c039754u,0x0c039756u,0x0c039758u,0x0c03975au,0x0c03975cu,0x0c03975eu,0x0c039760u,0x0c039762u,0x0c039764u,0x0c039766u,0x0c039768u,0x0c03976au,0x0c03976cu,0x0c03976eu,0x0c039770u,0x0c039772u,
0x0c039774u,0x0c039776u,0x0c039778u,0x0c03977au,0x0c03977cu,0x0c03977eu,0x0c039780u,0x0c039782u,0x0c039784u,0x0c039786u,0x0c039788u,0x0c03978au,0x0c03978cu,0x0c03978eu,0x0c039790u,0x0c039792u,
0x0c039794u,0x0c039cb4u,0x0c039cb6u,0x0c039cb8u,0x0c039cbau,0x0c039cbcu,0x0c039cbeu,0x0c039cc0u,0x0c039cc2u,0x0c039cc4u,0x0c039cc6u,0x0c039cc8u,0x0c039ccau,0x0c039cccu,0x0c039cceu,0x0c039cd0u,
0x0c039ce0u,0x0c039ce2u,0x0c039ce4u,0x0c039cf0u,0x0c039cf2u,0x0c039cf4u,0x0c039d00u,0x0c039d02u,0x0c039d04u,0x0c039d70u,0x0c039d72u,0x0c039d74u,0x0c039d76u,0x0c039d78u,0x0c039d7au,0x0c039d7cu,
0x0c039d7eu,0x0c039d80u,0x0c039d82u,0x0c039d84u,0x0c039d86u,0x0c039d90u,0x0c039d92u,0x0c039d94u,0x0c039d96u,0x0c039d98u,0x0c03aa9cu,0x0c03aa9eu,0x0c03aaa0u,0x0c03aaa2u,0x0c03aaa4u,0x0c03aaa6u,
0x0c03aaa8u,0x0c03aaaau,0x0c03aaacu,0x0c03aaaeu,0x0c03aab0u,0x0c03aab2u,0x0c03aab4u,0x0c03aab6u,0x0c03aab8u,0x0c03aabau,0x0c03aabcu,0x0c03aabeu,0x0c03aac0u,0x0c03aac2u,0x0c03aac4u,0x0c03aac6u,
0x0c03aac8u,0x0c03aacau,0x0c03aaccu,0x0c03aaceu,0x0c03aad0u,0x0c03aad2u,0x0c03aad4u,0x0c03aad6u,0x0c03aad8u,0x0c03aadau,0x0c03aadcu,0x0c03aadeu,0x0c03aae0u,0x0c03aae2u,0x0c03aae4u,0x0c03aae6u,
0x0c03aae8u,0x0c03aaeau,0x0c03aaecu,0x0c03aaeeu,0x0c03aaf0u,0x0c03aaf2u,0x0c03aaf4u,0x0c03aaf6u,0x0c03aaf8u,0x0c03aafau,0x0c03aafcu,0x0c03aafeu,0x0c03ab00u,0x0c03ab02u,0x0c03ab04u,0x0c03ab06u,
0x0c03ab08u,0x0c03ab0au,0x0c03ab0cu,0x0c03ab0eu,0x0c03ab10u,0x0c03ab12u,0x0c03ab14u,0x0c0432e2u,0x0c0432e4u,0x0c0432e6u,0x0c0432e8u,0x0c0432eau,0x0c0432ecu,0x0c0432eeu,0x0c0432f0u,0x0c0432f2u,
0x0c0432f4u,0x0c0432f6u,0x0c0432f8u,0x0c0432fau,0x0c0432fcu,0x0c0432feu,0x0c043300u,0x0c043302u,0x0c043304u,0x0c043306u,0x0c043308u,0x0c04330au,0x0c04330cu,0x0c04330eu,0x0c043310u,0x0c043312u,
0x0c043314u,0x0c043316u,0x0c043318u,0x0c04331au,0x0c04331cu,0x0c04331eu,0x0c043320u,0x0c043322u,0x0c043324u,0x0c043344u,0x0c043346u,0x0c043348u,0x0c04334au,0x0c04334cu,0x0c04334eu,0x0c043350u,
0x0c043352u,0x0c043354u,0x0c043356u,0x0c043358u,0x0c04335au,0x0c04335cu,0x0c0433aeu,0x0c0433b0u,0x0c0433b2u,0x0c0433b4u,0x0c0433b6u,0x0c0433b8u,0x0c0433bau,0x0c047810u,0x0c047812u,0x0c047814u,
0x0c047816u,0x0c047818u,0x0c04781au,0x0c04781cu,0x0c04781eu,0x0c047820u,0x0c047822u,0x0c047824u,0x0c047826u,0x0c047828u,0x0c04782au,0x0c04782cu,0x0c04782eu,0x0c047830u,0x0c047832u,0x0c047834u,
0x0c047836u,0x0c047838u,0x0c04783au,0x0c04783cu,0x0c04783eu,0x0c047840u,0x0c047842u,0x0c047844u,0x0c047846u,0x0c047848u,0x0c04784au,0x0c04784cu,0x0c04784eu,0x0c047850u,0x0c047852u,0x0c047854u,
0x0c047856u,0x0c047858u,0x0c04785au,0x0c04785cu,0x0c04785eu,0x0c047860u,0x0c047862u,0x0c047864u,0x0c047866u,0x0c047868u,0x0c04786au,0x0c04786cu,0x0c04786eu,0x0c047870u,0x0c047872u,0x0c047874u,
0x0c047876u,0x0c047878u,0x0c04787au,0x0c04787cu,0x0c04787eu,0x0c047880u,0x0c047882u,0x0c047884u,0x0c047886u,0x0c047888u,0x0c04788au,0x0c04788cu,0x0c04788eu,0x0c047890u,0x0c047892u,0x0c047894u,
0x0c047896u,0x0c047898u,0x0c04789au,0x0c04789cu,0x0c04789eu,0x0c0478a0u,0x0c0478a2u,0x0c0478a4u,0x0c0478a6u,0x0c0478a8u,0x0c0478aau,0x0c0478acu,0x0c0478aeu,0x0c0478b0u,0x0c0478b2u,0x0c0478b4u,
0x0c0478b6u,0x0c0478b8u,0x0c0478bau,0x0c0478bcu,0x0c0478c0u,0x0c0478c2u,0x0c0478c4u,0x0c0478c6u,0x0c0478c8u,0x0c0478cau,0x0c0478ccu,0x0c0478ceu,0x0c0478d0u,0x0c0478d2u,0x0c0478d4u,0x0c0478d6u,
0x0c0478d8u,0x0c0478dau,0x0c0478dcu,0x0c0478deu,0x0c0478e0u,0x0c0478e2u,0x0c0478e4u,0x0c0478e6u,0x0c0478e8u,0x0c0478eau,0x0c0478ecu,0x0c0478eeu,0x0c0478f0u,0x0c0478f2u,0x0c0478f4u,0x0c0478f6u,
0x0c0478f8u,0x0c0478fau,0x0c0478fcu,0x0c0478feu,0x0c047900u,0x0c047902u,0x0c047904u,0x0c047906u,0x0c047908u,0x0c04790au,0x0c04790cu,0x0c04790eu,0x0c047910u,0x0c047912u,0x0c047914u,0x0c047916u,
0x0c047918u,0x0c04791au,0x0c04791cu,0x0c04791eu,0x0c047920u,0x0c047922u,0x0c047924u,0x0c047928u,0x0c04792au,0x0c04792cu,0x0c04792eu,0x0c047930u,0x0c047932u,0x0c047934u,0x0c047936u,0x0c047938u,
0x0c04793au,0x0c04793cu,0x0c04793eu,0x0c047940u,0x0c047942u,0x0c047944u,0x0c047946u,0x0c047948u,0x0c04794au,0x0c04794cu,0x0c04794eu,0x0c047950u,0x0c047952u,0x0c047954u,0x0c047956u,0x0c047958u,
0x0c04795au,0x0c04795cu,0x0c04795eu,0x0c047960u,0x0c047962u,0x0c047964u,0x0c047966u,0x0c047968u,0x0c04796au,0x0c04796cu,0x0c04796eu,0x0c047970u,0x0c047972u,0x0c047974u,0x0c047976u,0x0c047978u,
0x0c04797au,0x0c04797cu,0x0c04797eu,0x0c047980u,0x0c047982u,0x0c047984u,0x0c047986u,0x0c047988u,0x0c04798au,0x0c04798cu,0x0c04798eu,0x0c047990u,0x0c047992u,0x0c047994u,0x0c047996u,0x0c047998u,
0x0c04799au,0x0c04799cu,0x0c04799eu,0x0c0479a0u,0x0c0479a2u,0x0c0479a4u,0x0c0479a6u,0x0c0479a8u,0x0c0479aau,0x0c0479acu,0x0c0479aeu,0x0c0479b0u,0x0c0479b2u,0x0c0479b4u,0x0c0479b6u,0x0c0479b8u,
0x0c0479bau,0x0c0479bcu,0x0c0479beu,0x0c0479c0u,0x0c0479c2u,0x0c0479c4u,0x0c0479c8u,0x0c0479cau,0x0c0479ccu,0x0c0479ceu,0x0c0479d0u,0x0c0479d2u,0x0c0479d4u,0x0c0479d6u,0x0c0479d8u,0x0c0479dau,
0x0c0479dcu,0x0c0479deu,0x0c0479e0u,0x0c0479e4u,0x0c0479e6u,0x0c0479e8u,0x0c0479eau,0x0c0479ecu,0x0c0479eeu,0x0c0479f0u,0x0c0479f2u,0x0c0479f4u,0x0c0479f6u,0x0c0479f8u,0x0c0479fau,0x0c0479fcu,
0x0c0479feu,0x0c047a00u,0x0c047a02u,0x0c047a04u,0x0c047a06u,0x0c047a08u,0x0c047a0au,0x0c047a0cu,0x0c047a0eu,0x0c047a10u,0x0c047a14u,0x0c047a16u,0x0c047a18u,0x0c047a1au,0x0c047a1cu,0x0c047a1eu,
0x0c047a20u,0x0c047a22u,0x0c047a24u,0x0c047a26u,0x0c047a28u,0x0c047a2au,0x0c047a2cu,0x0c047a2eu,0x0c047a30u,0x0c047a32u,0x0c047a34u,0x0c047a36u,0x0c047a38u,0x0c047a3au,0x0c047a3cu,0x0c047a3eu,
0x0c047a40u,0x0c047a42u,0x0c047a44u,0x0c047a46u,0x0c047a48u,0x0c047a4au,0x0c047a4cu,0x0c047a4eu,0x0c047a50u,0x0c047a52u,0x0c047a54u,0x0c047a56u,0x0c047a58u,0x0c047a5au,0x0c047a5cu,0x0c047a5eu,
0x0c047a60u,0x0c047a62u,0x0c047a64u,0x0c047a66u,0x0c047a68u,0x0c047a6au,0x0c047a6cu,0x0c047a6eu,0x0c047a70u,0x0c047a72u,0x0c047a74u,0x0c047a76u,0x0c047a78u,0x0c047a7au,0x0c047a7cu,0x0c047a7eu,
0x0c047a80u,0x0c047a82u,0x0c047a84u,0x0c047a86u,0x0c047a88u,0x0c047a8au,0x0c047a8cu,0x0c047a8eu,0x0c047a90u,0x0c047a92u,0x0c047a94u,0x0c047a96u,0x0c047a98u,0x0c047a9au,0x0c047a9cu,0x0c047a9eu,
0x0c047aa0u,0x0c047aa2u,0x0c047aa4u,0x0c047aa6u,0x0c047aa8u,0x0c047aaau,0x0c047aacu,0x0c047aaeu,0x0c047ab0u,0x0c047ab4u,0x0c047ab6u,0x0c047ab8u,0x0c047abau,0x0c047abcu,0x0c047abeu,0x0c047ac0u,
0x0c047ac2u,0x0c047ac4u,0x0c047ac6u,0x0c047ac8u,0x0c047acau,0x0c047accu,0x0c047aceu,0x0c047ad0u,0x0c047ad4u,0x0c047ad6u,0x0c0482f0u,0x0c0482f2u,0x0c0482f4u,0x0c0482f6u,0x0c0482f8u,0x0c0482fau,
0x0c0482fcu,0x0c0482feu,0x0c048300u,0x0c048302u,0x0c048304u,0x0c048306u,0x0c048308u,0x0c04830au,0x0c04830cu,0x0c04830eu,0x0c048310u,0x0c048312u,0x0c048314u,0x0c048316u,0x0c048318u,0x0c04831au,
0x0c04831cu,0x0c04831eu,0x0c048320u,0x0c048322u,0x0c048324u,0x0c048326u,0x0c048328u,0x0c04832au,0x0c04832cu,0x0c04832eu,0x0c048330u,0x0c048332u,0x0c048334u,0x0c048336u,0x0c048338u,0x0c04833au,
0x0c04833cu,0x0c04833eu,0x0c048340u,0x0c048342u,0x0c048344u,0x0c048346u,0x0c048348u,0x0c04834au,0x0c04834cu,0x0c04834eu,0x0c048350u,0x0c048352u,0x0c048354u,0x0c048356u,0x0c048358u,0x0c04835au,
0x0c04835cu,0x0c04835eu,0x0c048360u,0x0c048362u,0x0c048364u,0x0c048366u,0x0c048368u,0x0c04836au,0x0c04836cu,0x0c04836eu,0x0c048370u,0x0c048372u,0x0c048374u,0x0c048376u,0x0c048378u,0x0c04837au,
0x0c04837cu,0x0c04837eu,0x0c048380u,0x0c048382u,0x0c048384u,0x0c048386u,0x0c048388u,0x0c04838au,0x0c04838cu,0x0c04838eu,0x0c048390u,0x0c048392u,0x0c048394u,0x0c048396u,0x0c048398u,0x0c04839au,
0x0c04839cu,0x0c0483a0u,0x0c0483a2u,0x0c0483a4u,0x0c0483a6u,0x0c0483a8u,0x0c0483aau,0x0c0483acu,0x0c0483aeu,0x0c0483b0u,0x0c0483b2u,0x0c0483b4u,0x0c0483b6u,0x0c0483b8u,0x0c0483bau,0x0c0483bcu,
0x0c0483beu,0x0c0483c0u,0x0c0483c2u,0x0c0483c4u,0x0c0483c6u,0x0c0483c8u,0x0c0483cau,0x0c0483ccu,0x0c0483ceu,0x0c0483d0u,0x0c0483d2u,0x0c0483d4u,0x0c0483d6u,0x0c0483d8u,0x0c0483dau,0x0c0483dcu,
0x0c0483deu,0x0c0483e0u,0x0c0483e2u,0x0c0483e4u,0x0c0483e6u,0x0c0483e8u,0x0c0483eau,0x0c0483ecu,0x0c0483eeu,0x0c0483f0u,0x0c0483f2u,0x0c0483f4u,0x0c0483f6u,0x0c0483f8u,0x0c0483fau,0x0c0483fcu,
0x0c0483feu,0x0c048400u,0x0c048402u,0x0c048404u,0x0c048408u,0x0c04840au,0x0c04840cu,0x0c04840eu,0x0c048410u,0x0c048412u,0x0c048414u,0x0c048416u,0x0c048418u,0x0c04841au,0x0c04841cu,0x0c04841eu,
0x0c048420u,0x0c048422u,0x0c048424u,0x0c048426u,0x0c048428u,0x0c04842au,0x0c04842cu,0x0c04842eu,0x0c048430u,0x0c048432u,0x0c048434u,0x0c048436u,0x0c048438u,0x0c04843au,0x0c04843cu,0x0c04843eu,
0x0c048440u,0x0c048442u,0x0c048444u,0x0c048446u,0x0c048448u,0x0c04844au,0x0c04844cu,0x0c04844eu,0x0c048450u,0x0c048452u,0x0c048454u,0x0c048456u,0x0c048458u,0x0c04845au,0x0c04845cu,0x0c04845eu,
0x0c048460u,0x0c048462u,0x0c048464u,0x0c048466u,0x0c048468u,0x0c04846au,0x0c04846cu,0x0c04846eu,0x0c048470u,0x0c048472u,0x0c048474u,0x0c048476u,0x0c048478u,0x0c04847au,0x0c04847cu,0x0c04847eu,
0x0c048480u,0x0c048482u,0x0c048484u,0x0c048486u,0x0c048488u,0x0c04848au,0x0c04848cu,0x0c04848eu,0x0c048490u,0x0c048492u,0x0c048494u,0x0c048496u,0x0c048498u,0x0c04849au,0x0c04849cu,0x0c04849eu,
0x0c0484a0u,0x0c0484a2u,0x0c0484a4u,0x0c0484a8u,0x0c0484aau,0x0c0484acu,0x0c0484aeu,0x0c0484b0u,0x0c0484b2u,0x0c0484b4u,0x0c0484b6u,0x0c0484b8u,0x0c0484bau,0x0c0484bcu,0x0c0484beu,0x0c0484c0u,
0x0c0484c4u,0x0c0484c6u,0x0c0484c8u,0x0c0484cau,0x0c0484ccu,0x0c0484ceu,0x0c0484d0u,0x0c0484d2u,0x0c0484d4u,0x0c0484d6u,0x0c0484d8u,0x0c0484dau,0x0c0484dcu,0x0c0484deu,0x0c0484e0u,0x0c0484e2u,
0x0c0484e4u,0x0c0484e6u,0x0c0484e8u,0x0c0484eau,0x0c0484ecu,0x0c0484eeu,0x0c0484f0u,0x0c0484f4u,0x0c0484f6u,0x0c0484f8u,0x0c0484fau,0x0c0484fcu,0x0c0484feu,0x0c048500u,0x0c048502u,0x0c048504u,
0x0c048506u,0x0c048508u,0x0c04850au,0x0c04850cu,0x0c04850eu,0x0c048510u,0x0c048512u,0x0c048514u,0x0c048516u,0x0c048518u,0x0c04851au,0x0c04851cu,0x0c04851eu,0x0c048520u,0x0c048522u,0x0c048524u,
0x0c048526u,0x0c048528u,0x0c04852au,0x0c04852cu,0x0c04852eu,0x0c048530u,0x0c048532u,0x0c048534u,0x0c048536u,0x0c048538u,0x0c04853au,0x0c04853cu,0x0c04853eu,0x0c048540u,0x0c048542u,0x0c048544u,
0x0c048546u,0x0c048548u,0x0c04854au,0x0c04854cu,0x0c04854eu,0x0c048550u,0x0c048552u,0x0c048554u,0x0c048556u,0x0c048558u,0x0c04855au,0x0c04855cu,0x0c04855eu,0x0c048560u,0x0c04856cu,0x0c04856eu,
0x0c048570u,0x0c048572u,0x0c048574u,0x0c048576u,0x0c048578u,0x0c04857au,0x0c04857cu,0x0c04857eu,0x0c048580u,0x0c048582u,0x0c048584u,0x0c048586u,0x0c048588u,0x0c04858au,0x0c04858cu,0x0c04858eu,
0x0c048590u,0x0c048592u,0x0c048594u,0x0c048596u,0x0c048598u,0x0c04859cu,0x0c04859eu,0x0c0485a0u,0x0c0485a2u,0x0c0485a4u,0x0c0485a6u,0x0c0485a8u,0x0c0485aau,0x0c0485acu,0x0c0485aeu,0x0c0485b0u,
0x0c0485b2u,0x0c0485b4u,0x0c0485b6u,0x0c0485b8u,0x0c0485bcu,0x0c0485beu,0x0c0490e8u,0x0c0490eau,0x0c0490ecu,0x0c0490eeu,0x0c0490f0u,0x0c0490f2u,0x0c0490f4u,0x0c0490f6u,0x0c0490f8u,0x0c0490fau,
0x0c0490fcu,0x0c0490feu,0x0c049100u,0x0c049102u,0x0c049104u,0x0c049106u,0x0c049108u,0x0c04910au,0x0c04910cu,0x0c049114u,0x0c049116u,0x0c049118u,0x0c04911au,0x0c04911cu,0x0c04911eu,0x0c049120u,
0x0c049122u,0x0c049124u,0x0c049126u,0x0c049128u,0x0c04912au,0x0c04912cu,0x0c04912eu,0x0c049130u,0x0c049132u,0x0c049134u,0x0c049136u,0x0c049138u,0x0c04913au,0x0c04913cu,0x0c04913eu,0x0c049140u,
0x0c049142u,0x0c049144u,0x0c049146u,0x0c049148u,0x0c04914au,0x0c04914cu,0x0c04914eu,0x0c049150u,0x0c049152u,0x0c049154u,0x0c049156u,0x0c049158u,0x0c04915au,0x0c04915cu,0x0c04915eu,0x0c049160u,
0x0c049162u,0x0c049164u,0x0c049168u,0x0c04916au,0x0c04916cu,0x0c04916eu,0x0c049170u,0x0c049172u,0x0c049174u,0x0c049176u,0x0c049178u,0x0c04917au,0x0c04917cu,0x0c04917eu,0x0c049180u,0x0c049182u,
0x0c049184u,0x0c049188u,0x0c04918au,0x0c049a16u,0x0c049a18u,0x0c049a1au,0x0c049a1cu,0x0c049a1eu,0x0c049a20u,0x0c049a22u,0x0c049a24u,0x0c049a26u,0x0c049a28u,0x0c049a2au,0x0c049a2cu,0x0c049a2eu,
0x0c049a30u,0x0c049a32u,0x0c049a34u,0x0c049a36u,0x0c049a38u,0x0c049a3cu,0x0c049a3eu,0x0c049a40u,0x0c049a42u,0x0c049a44u,0x0c049a46u,0x0c049a48u,0x0c049a4au,0x0c049a4cu,0x0c049a4eu,0x0c049a50u,
0x0c049a52u,0x0c049a54u,0x0c049a56u,0x0c049a58u,0x0c049a5au,0x0c049a5cu,0x0c049a5eu,0x0c049a60u,0x0c049a62u,0x0c049a64u,0x0c049a66u,0x0c049a68u,0x0c049a6au,0x0c049a6cu,0x0c049a6eu,0x0c049a70u,
0x0c049a72u,0x0c049a74u,0x0c049a76u,0x0c049a78u,0x0c049a7au,0x0c049a7cu,0x0c049a7eu,0x0c049a80u,0x0c049a82u,0x0c049a84u,0x0c049a86u,0x0c049a88u,0x0c049a8au,0x0c049a8cu,0x0c049a8eu,0x0c049a90u,
0x0c049a92u,0x0c049a94u,0x0c049a96u,0x0c049a98u,0x0c049a9au,0x0c049a9cu,0x0c049a9eu,0x0c049aa0u,0x0c049aa2u,0x0c049aa4u,0x0c049aa6u,0x0c049aa8u,0x0c049aaau,0x0c049aacu,0x0c049aaeu,0x0c049ab0u,
0x0c049ab2u,0x0c049ab4u,0x0c049ab6u,0x0c049ab8u,0x0c049abcu,0x0c049abeu,0x0c055c96u,0x0c055c98u,0x0c055c9au,0x0c055c9cu,0x0c055c9eu,0x0c055ca0u,0x0c055ca2u,0x0c055ca4u,0x0c055ca6u,0x0c055ca8u,
0x0c055caau,0x0c055cacu,0x0c055caeu,0x0c055cb0u,0x0c055cb2u,0x0c055cb4u,0x0c055cb6u,0x0c055cb8u,0x0c055cbau,0x0c055cbcu,0x0c055cbeu,0x0c055cc0u,0x0c055cc2u,0x0c055cc4u,0x0c055cc6u,0x0c055cc8u,
0x0c055ccau,0x0c055cccu,0x0c055cceu,0x0c055cd0u,0x0c055cd2u,0x0c055cd4u,0x0c055cd6u,0x0c055cd8u,0x0c055cdau,0x0c055cdcu,0x0c055cdeu,0x0c055ce0u,0x0c055ce2u,0x0c058788u,0x0c05878au,0x0c05878cu,
0x0c0587d8u,0x0c0587dau,0x0c0587dcu,0x0c0587deu,0x0c0587e0u,0x0c0587e2u,0x0c0587e4u,0x0c0587e6u,0x0c0587e8u,0x0c0587eau,0x0c0587ecu,0x0c0587eeu,0x0c0587f0u,0x0c0587f2u,0x0c0587f4u,0x0c0587f6u,
0x0c0587f8u,0x0c0587fau,0x0c0587fcu,0x0c0587feu,0x0c058800u,0x0c058802u,0x0c058804u,0x0c058806u,0x0c058808u,0x0c05880au,0x0c05880cu,0x0c05880eu,0x0c058810u,0x0c058812u,0x0c058814u,0x0c058852u,
0x0c058854u,0x0c058856u,0x0c058858u,0x0c05885au,0x0c05885cu,0x0c05885eu,0x0c058860u,0x0c058862u,0x0c058864u,0x0c058866u,0x0c058868u,0x0c05886au,0x0c05886cu,0x0c05886eu,0x0c058870u,0x0c058872u,
0x0c058874u,0x0c058876u,0x0c058878u,0x0c05887au,0x0c05887cu,0x0c05887eu,0x0c058880u,0x0c058882u,0x0c058884u,0x0c058886u,0x0c058888u,0x0c05888au,0x0c05888cu,0x0c05888eu,0x0c058890u,0x0c058892u,
0x0c058894u,0x0c058896u,0x0c058898u,0x0c05889au,0x0c05889cu,0x0c05889eu,0x0c0588a0u,0x0c0588a2u,0x0c0588a4u,0x0c0588a6u,0x0c0588a8u,0x0c0588aau,0x0c0588acu,0x0c0588aeu,0x0c0588b0u,0x0c0588b2u,
0x0c0588b4u,0x0c0588b6u,0x0c0588b8u,0x0c0588bau,0x0c0588bcu,0x0c0588beu,0x0c0588c0u,0x0c0588c2u,0x0c0588c4u,0x0c0588c6u,0x0c0588c8u,0x0c0588cau,0x0c0588ccu,0x0c0588ceu,0x0c0588d0u,0x0c0588d2u,
0x0c0588d4u,0x0c0588d6u,0x0c0588d8u,0x0c0588dau,0x0c0588dcu,0x0c0588deu,0x0c0588e0u,0x0c0588e2u,0x0c0588e4u,0x0c0588e6u,0x0c0588e8u,0x0c0588eau,0x0c0588ecu,0x0c0588eeu,0x0c05df8au,0x0c05df8cu,
0x0c05df8eu,0x0c05df90u,0x0c05df92u,0x0c05df94u,0x0c05df96u,0x0c05df98u,0x0c05df9au,0x0c05df9cu,0x0c05df9eu,0x0c05dfa0u,0x0c05dfa2u,0x0c05dfa4u,0x0c05dfa6u,0x0c05dfa8u,0x0c05dfaau,0x0c05dfacu,
0x0c05dfaeu,0x0c05dfb0u,0x0c05dfb2u,0x0c05dfb4u,0x0c05dfb6u,0x0c05dfb8u,0x0c05dfbau,0x0c05dfbcu,0x0c05dfbeu,0x0c05dfc0u,0x0c05dfc2u,0x0c05dfc4u,0x0c05dfc6u,0x0c05dfc8u,0x0c05dfcau,0x0c05dfccu,
0x0c05dfceu,0x0c05dfd0u,0x0c05dfd2u,0x0c05dfd4u,0x0c05dfd6u,0x0c05edd4u,0x0c05edd6u,0x0c05edd8u,0x0c05eddau,0x0c05eddcu,0x0c05eddeu,0x0c05ede0u,0x0c05ede2u,0x0c05ede4u,0x0c05ede6u,0x0c05ede8u,
0x0c05edeau,0x0c05edecu,0x0c05edeeu,0x0c05edf0u,0x0c05edf2u,0x0c05edf4u,0x0c05edf6u,0x0c05edf8u,0x0c05edfau,0x0c05edfcu,0x0c05edfeu,0x0c05ee00u,0x0c05ee02u,0x0c05ee04u,0x0c05ee06u,0x0c05ee08u,
0x0c05ee0au,0x0c05ee0cu,0x0c05ee0eu,0x0c05ee10u,0x0c05ee12u,0x0c05ee14u,0x0c05ee16u,0x0c05ee18u,0x0c05ee1au,0x0c05ee1cu,0x0c05ee1eu,0x0c05ee20u,0x0c05ee22u,0x0c05ee24u,0x0c05ee26u,0x0c05ee28u,
0x0c05ee2au,0x0c05ee2cu,0x0c05ee2eu,0x0c05ee30u,0x0c05ee32u,0x0c05f33au,0x0c05f3deu,0x0c05f3e0u,0x0c05f3e2u,0x0c05f3e4u,0x0c05f3e6u,0x0c05f3e8u,0x0c05fc32u,0x0c05fc34u,0x0c05fc36u,0x0c05fc38u,
0x0c05fc3au,0x0c05fc3cu,0x0c05fc3eu,0x0c05fc40u,0x0c05fc42u,0x0c05fc44u,0x0c05fc46u,0x0c05fc48u,0x0c05fc4au,0x0c05fc4cu,0x0c05fc4eu,0x0c05fc50u,0x0c05fc52u,0x0c05fc54u,0x0c05fc56u,0x0c05fc58u,
0x0c05fc5au,0x0c05fc5cu,0x0c05fc5eu,0x0c05fc60u,0x0c05fc62u,0x0c05fc64u,0x0c05fc66u,0x0c05fc68u,0x0c05fc6au,0x0c05fc6cu,0x0c05fc6eu,0x0c05fc70u,0x0c05fc72u,0x0c05fc74u,0x0c05fc76u,0x0c05fc78u,
0x0c05fc7au,0x0c05fc7cu,0x0c05fc7eu,0x0c05fc80u,0x0c05fc82u,0x0c05fc84u,0x0c05fc86u,0x0c05fc88u,0x0c05fc8au,0x0c05fc8cu,0x0c05fc8eu,0x0c05fc90u,0x0c05fc92u,0x0c05fc94u,0x0c05fc96u,0x0c05fc98u,
0x0c06256eu,0x0c062570u,0x0c062572u,0x0c062574u,0x0c062576u,0x0c062578u,0x0c06257au,0x0c06257cu,0x0c06257eu,0x0c062580u,0x0c062582u,0x0c062584u,0x0c062586u,0x0c062588u,0x0c0625a0u,0x0c0625a2u,
0x0c0625a4u,0x0c0625a6u,0x0c0625a8u,0x0c0625aau,0x0c0625acu,0x0c0625aeu,0x0c0625b0u,0x0c0625b2u,0x0c0625b4u,0x0c0625b6u,0x0c0625b8u,0x0c0625bau,0x0c0625bcu,0x0c0625beu,0x0c0625c0u,0x0c0625c2u,
0x0c0625c4u,0x0c0625c6u,0x0c0625c8u,0x0c0625cau,0x0c0625ccu,0x0c0625ceu,0x0c0625d0u,0x0c0625d2u,0x0c0625d4u,0x0c0625d6u,0x0c0625d8u,0x0c0625dau,0x0c0625dcu,0x0c0625deu,0x0c0625e0u,0x0c0625e2u,
0x0c0625e4u,0x0c0625e6u,0x0c0625e8u,0x0c0625eau,0x0c0625ecu,0x0c0625eeu,0x0c0625f0u,0x0c0625f2u,0x0c0625f4u,0x0c0625f6u,0x0c0625f8u,0x0c0625fau,0x0c0625fcu,0x0c0625feu,0x0c062600u,0x0c062602u,
0x0c06da9cu,0x0c06da9eu,0x0c06daa0u,0x0c06daa2u,0x0c06daa4u,0x0c06daa6u,0x0c06daa8u,0x0c06daaau,0x0c06daacu,0x0c06daaeu,0x0c06dab0u,0x0c06dab2u,0x0c06dab4u,0x0c06dab6u,0x0c06dab8u,0x0c06dabau,
0x0c06dabcu,0x0c06dabeu,0x0c06dac0u,0x0c06dac2u,0x0c06dac4u,0x0c06dac6u,0x0c06dac8u,0x0c06dacau,0x0c06daccu,0x0c06daceu,0x0c06dad0u,0x0c06dad2u,0x0c06dad4u,0x0c06dad6u,0x0c06dad8u,0x0c06dadau,
0x0c06dadcu,0x0c06dadeu,0x0c06dae0u,0x0c06dae2u,0x0c06dae4u,0x0c06dae6u,0x0c06db34u,0x0c06db36u,0x0c06db38u,0x0c06db3au,0x0c06db3cu,0x0c06dc44u,0x0c07ba28u,0x0c07ba2au,0x0c07ba2cu,0x0c07ba2eu,
0x0c07ba30u,0x0c07ba32u,0x0c07ba34u,0x0c07ba36u,0x0c07ba38u,0x0c07ba3au,0x0c07ba3cu,0x0c07ba3eu,0x0c07ba40u,0x0c07ba42u,0x0c07ba44u,0x0c07ba46u,0x0c07ba48u,0x0c07ba4au,0x0c07ba4cu,0x0c07ba4eu,
0x0c07ba50u,0x0c07ba52u,0x0c07ba54u,0x0c07ba56u,0x0c07ba58u,0x0c07ba5au,0x0c07ba5cu,0x0c07ba5eu,0x0c07ba60u,0x0c07ba62u,0x0c07ba64u,0x0c07ba66u,0x0c07ba68u,0x0c07ba6au,0x0c07ba6cu,0x0c07ba6eu,
0x0c07ba70u,0x0c07ba72u,0x0c07ba74u,0x0c07ba76u,0x0c07ba78u,0x0c07ba7au,0x0c07ba7cu,0x0c07ba7eu,0x0c07ba80u,0x0c07ba82u,0x0c07ba84u,0x0c07ba86u,0x0c07ba88u,0x0c07ba8au,0x0c07ba8cu,0x0c07ba8eu,
0x0c07ba90u,0x0c07ba92u,0x0c07ba94u,0x0c07ba96u,0x0c07ba98u,0x0c07ba9au,0x0c07ba9cu,0x0c07ba9eu,0x0c07baa0u,0x0c07baa2u,0x0c07baa4u,0x0c07baa6u,0x0c07baa8u,0x0c07baaau,0x0c07baacu,0x0c07baaeu,
0x0c07bab0u,0x0c07bab2u,0x0c07bab4u,0x0c07bab6u,0x0c07bab8u,0x0c07babau,0x0c07babcu,0x0c07babeu,0x0c07bac0u,0x0c07bac2u,0x0c07bac4u,0x0c07bac6u,0x0c07bac8u,0x0c07bacau,0x0c07baccu,0x0c07baceu,
0x0c07bad0u,0x0c07bad2u,0x0c07bad4u,0x0c07bad6u,0x0c07bad8u,0x0c07badau,0x0c07badcu,0x0c07badeu,0x0c07bae0u,0x0c07bae2u,0x0c07bae4u,0x0c07bae6u,0x0c07bae8u,0x0c07baeau,0x0c07baecu,0x0c07baeeu,
0x0c07baf0u,0x0c07baf2u,0x0c07baf4u,0x0c07baf6u,0x0c07baf8u,0x0c07bafau,0x0c07bafcu,0x0c07bafeu,0x0c07bb00u,0x0c07bb02u,0x0c07bb04u,0x0c07bb06u,0x0c07bb08u,0x0c07bb0au,0x0c07bb0cu,0x0c07bb0eu,
0x0c07bb10u,0x0c07bb12u,0x0c07bb14u,0x0c07bb16u,0x0c07bb18u,0x0c07bb1au,0x0c07bb1cu,0x0c07bb1eu,0x0c07bb20u,0x0c07bb22u,0x0c07bb24u,0x0c07bb26u,0x0c07bb28u,0x0c07bb2au,0x0c07bb2cu,0x0c07bb2eu,
0x0c07bb30u,0x0c07bb32u,0x0c07bb34u,0x0c07bb36u,0x0c07bb38u,0x0c07bb3au,0x0c07bb3cu,0x0c07bb3eu,0x0c07bb40u,0x0c07bb42u,0x0c07bb44u,0x0c07bb46u,0x0c07bba0u,0x0c07bba2u,0x0c07bba4u,0x0c07bba6u,
0x0c07bba8u,0x0c07bbaau,0x0c07bbacu,0x0c07bbaeu,0x0c07bbb0u,0x0c07bbb2u,0x0c07bbb4u,0x0c07bbb6u,0x0c07bbb8u,0x0c07bbbau,0x0c07bbbcu,0x0c07bbbeu,0x0c07bbc0u,0x0c07bbc2u,0x0c07bbc4u,0x0c07bbc6u,
0x0c07bbc8u,0x0c07bbcau,0x0c07bbccu,0x0c07bbceu,0x0c07bbd0u,0x0c07bbd2u,0x0c07bbd4u,0x0c07bbd6u,0x0c07bbd8u,0x0c07bbdau,0x0c07bbdcu,0x0c07bbdeu,0x0c07bbe0u,0x0c07bbe2u,0x0c07bbe4u,0x0c07bbe6u,
0x0c07bbe8u,0x0c07bbeau,0x0c07bbecu,0x0c07bbeeu,0x0c07bbf0u,0x0c07bbf2u,0x0c07bbf4u,0x0c07bbf6u,0x0c07bbf8u,0x0c07bbfau,0x0c07bbfcu,0x0c07bbfeu,0x0c07bc00u,0x0c07bc02u,0x0c07bc04u,0x0c07bc06u,
0x0c07bc08u,0x0c07bc0au,0x0c07bc0cu,0x0c07bc0eu,0x0c07bc10u,0x0c07bc12u,0x0c07bc14u,0x0c07bc16u,0x0c07bc18u,0x0c07bc1au,0x0c07bc1cu,0x0c07bc1eu,0x0c07bc20u,0x0c07bc22u,0x0c07bc24u,0x0c07bc26u,
0x0c07bc28u,0x0c07bc2au,0x0c07bc2cu,0x0c07bc2eu,0x0c07bc30u,0x0c07bc32u,0x0c07bc34u,0x0c07bc36u,0x0c07bc38u,0x0c07bc3au,0x0c07bc3cu,0x0c07bc3eu,0x0c07bc40u,0x0c07bc42u,0x0c07bc44u,0x0c07bc46u,
0x0c07bc48u,0x0c07bc4au,0x0c07bc4cu,0x0c07bc4eu,0x0c07bc50u,0x0c07bc52u,0x0c07bc54u,0x0c07bc56u,0x0c07bc58u,0x0c07bc5au,0x0c07bc5cu,0x0c07bc5eu,0x0c07bc60u,0x0c07bc62u,0x0c07bc64u,0x0c07bc66u,
0x0c07bc68u,0x0c07bc6au,0x0c07bc6cu,0x0c07bc6eu,0x0c07bc70u,0x0c07bc72u,0x0c07bc74u,0x0c07bc76u,0x0c07bc78u,0x0c07bc7au,0x0c07bc7cu,0x0c07bc7eu,0x0c07bc80u,0x0c07bc82u,0x0c07bc84u,0x0c07bc86u,
0x0c07bc88u,0x0c07bc8au,0x0c07bc8cu,0x0c07bc8eu,0x0c07bc90u,0x0c07bc92u,0x0c07bc94u,0x0c07bc96u,0x0c07bc98u,0x0c07bc9au,0x0c07bc9cu,0x0c07bc9eu,0x0c07bca0u,0x0c07bca2u,0x0c07bca4u,0x0c07bca6u,
0x0c07bca8u,0x0c07bcaau,0x0c07bcacu,0x0c07bcaeu,0x0c07bcb0u,0x0c07bcb2u,0x0c07bcb4u,0x0c07bcb6u,0x0c07bcb8u,0x0c07bcbau,0x0c07bcbcu,0x0c07bcbeu,0x0c07bcc0u,0x0c07bcc2u,0x0c07bcc4u,0x0c07bcc6u,
0x0c07bcc8u,0x0c07bccau,0x0c07bcccu,0x0c07bcceu,0x0c07bcd0u,0x0c07bcd2u,0x0c07bcd4u,0x0c07bcd6u,0x0c07bcd8u,0x0c07bcdau,0x0c07bcdcu,0x0c07bcdeu,0x0c07bce0u,0x0c07bce2u,0x0c07bce4u,0x0c07bce6u,
0x0c07bce8u,0x0c07bceau,0x0c07bcecu,0x0c07bceeu,0x0c07bcf0u,0x0c07bcf2u,0x0c07bcf4u,0x0c07bcf6u,0x0c07bcf8u,0x0c07bd14u,0x0c07bd16u,0x0c07bd18u,0x0c07bd1au,0x0c07bd1cu,0x0c07bd1eu,0x0c07bd20u,
0x0c07bd22u,0x0c07bd24u,0x0c07bd26u,0x0c07bd28u,0x0c07bd2au,0x0c07bd2cu,0x0c07bd2eu,0x0c07bd30u,0x0c07bd32u,0x0c07bd34u,0x0c07bd36u,0x0c07bd38u,0x0c07bd3au,0x0c07bd3cu,0x0c07bd3eu,0x0c07bd40u,
0x0c07bd42u,0x0c07bd44u,0x0c07bd46u,0x0c07bd48u,0x0c07bd4au,0x0c07bd4cu,0x0c07bd4eu,0x0c07bd50u,0x0c07bd52u,0x0c07bd54u,0x0c07bd56u,0x0c07bd58u,0x0c07bd5au,0x0c07bd5cu,0x0c07bd5eu,0x0c07bd60u,
0x0c07bd62u,0x0c07bd64u,0x0c07bd66u,0x0c07bd68u,0x0c07bd6au,0x0c07bd6cu,0x0c07bd6eu,0x0c07bd70u,0x0c07bd72u,0x0c07bd74u,0x0c07bd76u,0x0c07bd78u,0x0c07bd7au,0x0c07bd7cu,0x0c07bd7eu,0x0c07bd80u,
0x0c07bd82u,0x0c07bd84u,0x0c07bd86u,0x0c07bd88u,0x0c07bd8au,0x0c07bd8cu,0x0c07bd8eu,0x0c07bd90u,0x0c07bd92u,0x0c07bd94u,0x0c07bd96u,0x0c07bd98u,0x0c07bd9au,0x0c07bd9cu,0x0c07bd9eu,0x0c07bda0u,
0x0c07bda2u,0x0c07bda4u,0x0c07bda6u,0x0c07bda8u,0x0c07bdaau,0x0c07bdacu,0x0c07bdaeu,0x0c07bdb0u,0x0c07bdb2u,0x0c07bdb4u,0x0c07bdb6u,0x0c07bdb8u,0x0c07bdbau,0x0c07bdbcu,0x0c07bdbeu,0x0c07bdc0u,
0x0c07bdc2u,0x0c07bdc4u,0x0c07bdc6u,0x0c07bdc8u,0x0c07bdcau,0x0c07bdccu,0x0c07bdceu,0x0c07bdd0u,0x0c07bdd2u,0x0c07bdd4u,0x0c07bdd6u,0x0c07bdd8u,0x0c07bddau,0x0c07bddcu,0x0c07bddeu,0x0c07bde0u,
0x0c07bde2u,0x0c07bde4u,0x0c07bde6u,0x0c07bde8u,0x0c07bdeau,0x0c07bdecu,0x0c07bdeeu,0x0c07bdf0u,0x0c07bdf2u,0x0c07bdf4u,0x0c07bdf6u,0x0c07bdf8u,0x0c07bdfau,0x0c07bdfcu,0x0c07bdfeu,0x0c07be00u,
0x0c07be02u,0x0c07be04u,0x0c07be06u,0x0c07be08u,0x0c07be0au,0x0c07be0cu,0x0c07be0eu,0x0c07be10u,0x0c07be12u,0x0c07be14u,0x0c07be16u,0x0c07be18u,0x0c07be1au,0x0c07be1cu,0x0c07be1eu,0x0c07be20u,
0x0c07be22u,0x0c07be24u,0x0c07be26u,0x0c07be28u,0x0c07be2au,0x0c07be2cu,0x0c07be2eu,0x0c07be30u,0x0c07be32u,0x0c07be34u,0x0c07be36u,0x0c07be38u,0x0c07be3au,0x0c07be3cu,0x0c07be3eu,0x0c07be40u,
0x0c07be42u,0x0c07be44u,0x0c07be46u,0x0c07be48u,0x0c07be4au,0x0c07be4cu,0x0c07be4eu,0x0c07be50u,0x0c07be52u,0x0c07be54u,0x0c07be56u,0x0c07be58u,0x0c07be5au,0x0c07be5cu,0x0c07be5eu,0x0c07be60u,
0x0c07be62u,0x0c07be64u,0x0c07be66u,0x0c07be68u,0x0c07be6au,0x0c07be6cu,0x0c07be6eu,0x0c07be70u,0x0c07be72u,0x0c07be74u,0x0c07be76u,0x0c07be78u,0x0c07be7au,0x0c07be7cu,0x0c07be7eu,0x0c07be80u,
0x0c07be82u,0x0c07be84u,0x0c07be86u,0x0c07be88u,0x0c07be8au,0x0c07be8cu,0x0c07be8eu,0x0c07be90u,0x0c07be92u,0x0c07be94u,0x0c07be96u,0x0c07be98u,0x0c07be9au,0x0c07beb0u,0x0c07beb2u,0x0c07beb4u,
0x0c07beb6u,0x0c07beb8u,0x0c07bebau,0x0c07bebcu,0x0c07bebeu,0x0c07bec0u,0x0c07bec2u,0x0c07bec4u,0x0c07bec6u,0x0c07bec8u,0x0c07becau,0x0c07beccu,0x0c07beceu,0x0c07bed0u,0x0c07bed2u,0x0c07bed4u,
0x0c07bed6u,0x0c07bed8u,0x0c07bedau,0x0c07bedcu,0x0c07bedeu,0x0c07bee0u,0x0c07bee2u,0x0c07bee4u,0x0c07bee6u,0x0c07bee8u,0x0c07beeau,0x0c07beecu,0x0c07beeeu,0x0c07bef0u,0x0c07bef2u,0x0c07bef4u,
0x0c07bef6u,0x0c07bef8u,0x0c07befau,0x0c07befcu,0x0c07befeu,0x0c07bf00u,0x0c07bf02u,0x0c07bf04u,0x0c07bf06u,0x0c07bf08u,0x0c07bf0au,0x0c07bf0cu,0x0c07bf0eu,0x0c07bf10u,0x0c07bf12u,0x0c07bf14u,
0x0c07bf16u,0x0c07bf18u,0x0c07bf1au,0x0c07bf1cu,0x0c07bf1eu,0x0c07bf20u,0x0c07bf22u,0x0c07bf24u,0x0c07bf26u,0x0c07bf28u,0x0c07bf2au,0x0c07bf2cu,0x0c07bf2eu,0x0c07bf30u,0x0c07bf32u,0x0c07bf34u,
0x0c07bf36u,0x0c07bf38u,0x0c07bf3au,0x0c07bf3cu,0x0c07bf3eu,0x0c07bf40u,0x0c07bf42u,0x0c07bf44u,0x0c07bf46u,0x0c07bf48u,0x0c07bf4au,0x0c07bf4cu,0x0c07bf4eu,0x0c07bf50u,0x0c07bf52u,0x0c07bf54u,
0x0c07bf56u,0x0c07bf58u,0x0c07bf5au,0x0c07bf5cu,0x0c07bf5eu,0x0c07bf60u,0x0c07bf62u,0x0c07bf64u,0x0c07bf66u,0x0c07bf68u,0x0c07bf6au,0x0c07bf6cu,0x0c07bf6eu,0x0c07bf70u,0x0c07bf72u,0x0c07bf74u,
0x0c07bf76u,0x0c07bf78u,0x0c07bf7au,0x0c07bf7cu,0x0c07bf7eu,0x0c07bf80u,0x0c07bf82u,0x0c07bf84u,0x0c07bf86u,0x0c07bf88u,0x0c07bf8au,0x0c07bf8cu,0x0c07bf8eu,0x0c07bf90u,0x0c07bf92u,0x0c07bf94u,
0x0c07bf96u,0x0c07bf98u,0x0c07bf9au,0x0c07bf9cu,0x0c07bf9eu,0x0c07bfa0u,0x0c07bfa2u,0x0c07bfa4u,0x0c07bfa6u,0x0c07bfa8u,0x0c07bfaau,0x0c07bfacu,0x0c07bfaeu,0x0c07bfb0u,0x0c07bfb2u,0x0c07bfb4u,
0x0c07bfb6u,0x0c07bfb8u,0x0c07bfbau,0x0c07bfbcu,0x0c07bfbeu,0x0c07bfc0u,0x0c07bfc2u,0x0c07bfc4u,0x0c07bfc6u,0x0c07bfc8u,0x0c07bfcau,0x0c07bfccu,0x0c07bfceu,0x0c07bfd0u,0x0c07bfd2u,0x0c07bfd4u,
0x0c07bfd6u,0x0c07bfd8u,0x0c07bfdau,0x0c07bfdcu,0x0c07bfdeu,0x0c07bfe0u,0x0c07bfe2u,0x0c07bfe4u,0x0c07bfe6u,0x0c07bfe8u,0x0c07bfeau,0x0c07bfecu,0x0c07bfeeu,0x0c07bff0u,0x0c07bff2u,0x0c07bff4u,
0x0c07bff6u,0x0c07bff8u,0x0c07bffau,0x0c07bffcu,0x0c07bffeu,0x0c07c000u,0x0c07c002u,0x0c07c004u,0x0c07c006u,0x0c07c008u,0x0c07c00au,0x0c07c00cu,0x0c07c00eu,0x0c07c010u,0x0c07c012u,0x0c07c014u,
0x0c07c016u,0x0c07c018u,0x0c07c01au,0x0c07c01cu,0x0c07c01eu,0x0c07c020u,0x0c07c022u,0x0c07c024u,0x0c07c026u,0x0c07c028u,0x0c07c02au,0x0c07c02cu,0x0c07c02eu,0x0c07c030u,0x0c07c032u,0x0c07c034u,
0x0c07c036u,0x0c07c038u,0x0c07c03au,0x0c07c03cu,0x0c07c03eu,0x0c07c040u,0x0c07c042u,0x0c07c05cu,0x0c07c05eu,0x0c07c060u,0x0c07c062u,0x0c07c064u,0x0c07c066u,0x0c07c068u,0x0c07c06au,0x0c07c06cu,
0x0c07c06eu,0x0c07c070u,0x0c07c072u,0x0c07c074u,0x0c07c076u,0x0c07c078u,0x0c07c07au,0x0c07c07cu,0x0c07c07eu,0x0c07c080u,0x0c07c082u,0x0c07c084u,0x0c07c086u,0x0c07c088u,0x0c07c08au,0x0c07c08cu,
0x0c07c08eu,0x0c07c090u,0x0c07c092u,0x0c07c094u,0x0c07c096u,0x0c07c098u,0x0c07c09au,0x0c07c09cu,0x0c07c09eu,0x0c07c0a0u,0x0c07c0a2u,0x0c07c0a4u,0x0c07c0a6u,0x0c07c0a8u,0x0c07c0aau,0x0c07c0acu,
0x0c07c0aeu,0x0c07c0b0u,0x0c07c0b2u,0x0c07c0b4u,0x0c07c0b6u,0x0c07c0b8u,0x0c07c0bau,0x0c07c0bcu,0x0c07c0beu,0x0c07c0c0u,0x0c07c0c2u,0x0c07c0c4u,0x0c07c0c6u,0x0c07c0c8u,0x0c07c0cau,0x0c07c0ccu,
0x0c07c0ceu,0x0c07c0d0u,0x0c07c0d2u,0x0c07c0d4u,0x0c07c0d6u,0x0c07c0d8u,0x0c07c0dau,0x0c07c0dcu,0x0c07c0deu,0x0c07c0e0u,0x0c07c0e2u,0x0c07c0e4u,0x0c07c0e6u,0x0c07c0e8u,0x0c07c0eau,0x0c07c0ecu,
0x0c07c0eeu,0x0c07c0f0u,0x0c07c0f2u,0x0c07c0f4u,0x0c07c0f6u,0x0c07c0f8u,0x0c07c0fau,0x0c07c0fcu,0x0c07c0feu,0x0c07c100u,0x0c07c102u,0x0c07c12cu,0x0c07c12eu,0x0c07c130u,0x0c07c132u,0x0c07c134u,
0x0c07c136u,0x0c07c138u,0x0c07c13au,0x0c07c13cu,0x0c07c13eu,0x0c07c140u,0x0c07c142u,0x0c07c144u,0x0c07c146u,0x0c07c148u,0x0c07c14au,0x0c07c14cu,0x0c07c14eu,0x0c07c150u,0x0c07c152u,0x0c07c154u,
0x0c07c156u,0x0c07c158u,0x0c07c15au,0x0c07c15cu,0x0c07c15eu,0x0c07c160u,0x0c07c162u,0x0c07c164u,0x0c07c166u,0x0c07c168u,0x0c07c16au,0x0c07c16cu,0x0c07c16eu,0x0c07c170u,0x0c07c172u,0x0c07c174u,
0x0c07c176u,0x0c07c178u,0x0c07c17au,0x0c07c17cu,0x0c07c17eu,0x0c07c180u,0x0c07c182u,0x0c07c184u,0x0c07c186u,0x0c07c188u,0x0c07c18au,0x0c07c18cu,0x0c07c18eu,0x0c07c190u,0x0c07c192u,0x0c07c194u,
0x0c07c196u,0x0c07c198u,0x0c07c19au,0x0c07c19cu,0x0c07c19eu,0x0c07c1a0u,0x0c07c1a2u,0x0c07c1a4u,0x0c07c1a6u,0x0c07c1a8u,0x0c07c1aau,0x0c07c1acu,0x0c07c1aeu,0x0c07c1b0u,0x0c07c1b2u,0x0c07c1b4u,
0x0c07c1b6u,0x0c07c1b8u,0x0c07c1bau,0x0c07c1bcu,0x0c07c1beu,0x0c07c1c0u,0x0c07c1c2u,0x0c07c1c4u,0x0c07c1c6u,0x0c07c1c8u,0x0c07c1cau,0x0c07c1ccu,0x0c07c1ceu,0x0c07c1d0u,0x0c07c1d2u,0x0c07c1d4u,
0x0c07c1d6u,0x0c07c1d8u,0x0c07c1dau,0x0c07c1dcu,0x0c07c1deu,0x0c07c1e0u,0x0c07c1e2u,0x0c07c1e4u,0x0c07c1e6u,0x0c07c1e8u,0x0c07c1eau,0x0c07c1ecu,0x0c07c1eeu,0x0c07c1f0u,0x0c07c1f2u,0x0c07c1f4u,
0x0c07c1f6u,0x0c07c1f8u,0x0c07c1fau,0x0c07c1fcu,0x0c07c1feu,0x0c07c200u,0x0c07c202u,0x0c07c204u,0x0c07c206u,0x0c07c208u,0x0c07c20au,0x0c07c20cu,0x0c07c20eu,0x0c07c210u,0x0c07c212u,0x0c07c214u,
0x0c07c216u,0x0c07c218u,0x0c07c21au,0x0c07c21cu,0x0c07c21eu,0x0c07c220u,0x0c07c222u,0x0c07c224u,0x0c07c226u,0x0c07c228u,0x0c07c22au,0x0c07c22cu,0x0c07c22eu,0x0c07c230u,0x0c07c232u,0x0c07c234u,
0x0c07c236u,0x0c07c238u,0x0c07c23au,0x0c07c23cu,0x0c07c23eu,0x0c07c240u,0x0c07c242u,0x0c07c244u,0x0c07c246u,0x0c07c248u,0x0c07c24au,0x0c07c24cu,0x0c07c24eu,0x0c07c250u,0x0c07c252u,0x0c07c254u,
0x0c07c256u,0x0c07c258u,0x0c07c25au,0x0c07c25cu,0x0c07c25eu,0x0c07c260u,0x0c07c262u,0x0c07c264u,0x0c07c266u,0x0c07c268u,0x0c07c26au,0x0c07c26cu,0x0c07c26eu,0x0c07c270u,0x0c07c272u,0x0c07c274u,
0x0c07c276u,0x0c07c278u,0x0c07c27au,0x0c07c27cu,0x0c07c27eu,0x0c07c280u,0x0c07c282u,0x0c07c284u,0x0c07c286u,0x0c07c288u,0x0c07c28au,0x0c07c28cu,0x0c07c28eu,0x0c07c290u,0x0c07c292u,0x0c07c294u,
0x0c07c296u,0x0c07c298u,0x0c07c29au,0x0c07c29cu,0x0c07c29eu,0x0c07c2a0u,0x0c07c2a2u,0x0c07c2a4u,0x0c07c2a6u,0x0c07c2a8u,0x0c07c2aau,0x0c07c2acu,0x0c07c2aeu,0x0c07c2b0u,0x0c07c2b2u,0x0c07c2b4u,
0x0c07c2d0u,0x0c07c2d2u,0x0c07c2d4u,0x0c07c2d6u,0x0c07c2d8u,0x0c07c2dau,0x0c07c2dcu,0x0c07c2deu,0x0c07c2e0u,0x0c07c2e2u,0x0c07c2e4u,0x0c07c2e6u,0x0c07c2e8u,0x0c07c2eau,0x0c07c2ecu,0x0c07c2eeu,
0x0c07c2f0u,0x0c07c2f2u,0x0c07c2f4u,0x0c07c2f6u,0x0c07c2f8u,0x0c07c2fau,0x0c07c2fcu,0x0c07c2feu,0x0c07c300u,0x0c07c302u,0x0c07c304u,0x0c07c306u,0x0c07c308u,0x0c07c30au,0x0c07c30cu,0x0c07c30eu,
0x0c07c310u,0x0c07c312u,0x0c07c314u,0x0c07c316u,0x0c07c318u,0x0c07c31au,0x0c07c31cu,0x0c07c31eu,0x0c07c320u,0x0c07c322u,0x0c07c324u,0x0c07c326u,0x0c07c328u,0x0c07c32au,0x0c07c32cu,0x0c07c32eu,
0x0c07c330u,0x0c07c332u,0x0c07c446u,0x0c07c448u,0x0c07c44au,0x0c07c44cu,0x0c07c44eu,0x0c07c450u,0x0c07c452u,0x0c07c454u,0x0c07c456u,0x0c07c458u,0x0c07c45au,0x0c07c45cu,0x0c07c45eu,0x0c07c460u,
0x0c07c462u,0x0c07c464u,0x0c07c466u,0x0c07c468u,0x0c07c46au,0x0c07c46cu,0x0c07c46eu,0x0c07c470u,0x0c07c472u,0x0c07c474u,0x0c07c476u,0x0c07c478u,0x0c07c47au,0x0c07c47cu,0x0c07c47eu,0x0c07c480u,
0x0c07c482u,0x0c07c484u,0x0c07c486u,0x0c07c488u,0x0c07c48au,0x0c07c48cu,0x0c07c48eu,0x0c07c490u,0x0c07c492u,0x0c07c494u,0x0c07c496u,0x0c07c498u,0x0c07c49au,0x0c07c49cu,0x0c07c49eu,0x0c07c4a0u,
0x0c07c4a6u,0x0c07c4a8u,0x0c07c4aau,0x0c07c4acu,0x0c07c4aeu,0x0c07c4b0u,0x0c07c4b2u,0x0c07c4b4u,0x0c07c4b6u,0x0c07c4b8u,0x0c07c4bau,0x0c07c4bcu,0x0c07c4beu,0x0c07c4c0u,0x0c07c4c2u,0x0c07c4c4u,
0x0c07c4c6u,0x0c07c4c8u,0x0c07c4cau,0x0c07c4ccu,0x0c07c4ceu,0x0c07c4d0u,0x0c07c4d2u,0x0c07c4d4u,0x0c07c4d6u,0x0c07c4d8u,0x0c07c4dau,0x0c07c4dcu,0x0c07c4deu,0x0c07c4e0u,0x0c07c4e2u,0x0c07c4e4u,
0x0c07c4e6u,0x0c07c4e8u,0x0c07c4eau,0x0c07c4ecu,0x0c07c4eeu,0x0c07c4f0u,0x0c07c4f2u,0x0c07c4f4u,0x0c07c4f6u,0x0c07c4f8u,0x0c07c4fau,0x0c07c4fcu,0x0c07c4feu,0x0c07c500u,0x0c07c502u,0x0c07c504u,
0x0c07c6b6u,0x0c07c6b8u,0x0c07c6bau,0x0c07c6bcu,0x0c07c6beu,0x0c07c6c0u,0x0c07c6c2u,0x0c07c6c4u,0x0c07c6c6u,0x0c07c6c8u,0x0c07c6cau,0x0c07c6ccu,0x0c07c6ceu,0x0c07c6d0u,0x0c07c6d2u,0x0c07c6d4u,
0x0c07c6d6u,0x0c07c6d8u,0x0c07c6dau,0x0c07c6dcu,0x0c07c6deu,0x0c07c6e0u,0x0c07c6e2u,0x0c07c6e4u,0x0c07c6e6u,0x0c07c6e8u,0x0c07c6eau,0x0c07c6ecu,0x0c07c6eeu,0x0c07c6f0u,0x0c07c6f2u,0x0c07c6f4u,
0x0c07c6f6u,0x0c07c6f8u,0x0c07c6fau,0x0c07c6fcu,0x0c07c6feu,0x0c07c700u,0x0c07c702u,0x0c07c704u,0x0c07c706u,0x0c07c708u,0x0c07c70au,0x0c07c70cu,0x0c07c70eu,0x0c07c710u,0x0c07c712u,0x0c07c714u,
0x0c07c716u,0x0c07c718u,0x0c07c71au,0x0c07c71cu,0x0c07c71eu,0x0c07c720u,0x0c07c722u,0x0c07c724u,0x0c07c726u,0x0c07c728u,0x0c07c72au,0x0c07c72cu,0x0c07c72eu,0x0c07c730u,0x0c07c732u,0x0c07c734u,
0x0c07c736u,0x0c07c738u,0x0c07c73au,0x0c07c73cu,0x0c07c73eu,0x0c07c740u,0x0c07c742u,0x0c07c744u,0x0c07c746u,0x0c07c748u,0x0c07c74au,0x0c07c74cu,0x0c07c74eu,0x0c07c750u,0x0c07c752u,0x0c07c754u,
0x0c07c756u,0x0c07c758u,0x0c07c75au,0x0c07c75cu,0x0c07c75eu,0x0c07c760u,0x0c07c762u,0x0c07c764u,0x0c07c766u,0x0c07c768u,0x0c07c76au,0x0c07c76cu,0x0c07c76eu,0x0c07c770u,0x0c07fbecu,0x0c07fbeeu,
0x0c07fbf0u,0x0c07fbf2u,0x0c07fbf4u,0x0c07fbf6u,0x0c07fbf8u,0x0c07fbfau,0x0c07fbfcu,0x0c07fbfeu,0x0c07fc00u,0x0c07fc02u,0x0c07fc04u,0x0c07fc06u,0x0c07fc08u,0x0c07fc0au,0x0c07fc0cu,0x0c07fc0eu,
0x0c07fc10u,0x0c07fc12u,0x0c07fc14u,0x0c07fc16u,0x0c07fc18u,0x0c07fc1au,0x0c07fc1cu,0x0c07fc1eu,0x0c07fc20u,0x0c07fc22u,0x0c07fc24u,0x0c07fc26u,0x0c07fc28u,0x0c07fc2au,0x0c07fc2cu,0x0c07fc2eu,
0x0c07fc30u,0x0c07fc32u,0x0c07fc34u,0x0c07fc36u,0x0c07fc38u,0x0c07fc3au,0x0c07fc3cu,0x0c07fc3eu,0x0c07fc40u,0x0c07fc42u,0x0c07fc44u,0x0c07fc46u,0x0c07fc48u,0x0c07fc4au,0x0c07fc4cu,0x0c07fc4eu,
0x0c07fc50u,0x0c07fc52u,0x0c08430eu,0x0c084310u,0x0c084312u,0x0c084314u,0x0c084316u,0x0c084318u,0x0c08431au,0x0c08431cu,0x0c08431eu,0x0c084320u,0x0c084322u,0x0c084324u,0x0c084326u,0x0c084328u,
0x0c08432au,0x0c08432cu,0x0c08432eu,0x0c084330u,0x0c084332u,0x0c084334u,0x0c084336u,0x0c084338u,0x0c08433au,0x0c08433cu,0x0c08433eu,0x0c084340u,0x0c084342u,0x0c084344u,0x0c084346u,0x0c084348u,
0x0c08434au,0x0c08434cu,0x0c08434eu,0x0c084350u,0x0c084352u,0x0c084354u,0x0c084356u,0x0c084358u,0x0c08435au,0x0c08435cu,0x0c08435eu,0x0c084360u,0x0c084362u,0x0c084364u,0x0c084366u,0x0c084368u,
0x0c08436au,0x0c08436cu,0x0c08436eu,0x0c084370u,0x0c084372u,0x0c084374u,0x0c084376u,0x0c084378u,0x0c08437au,0x0c08437cu,0x0c08437eu,0x0c084380u,0x0c084382u,0x0c084384u,0x0c084386u,0x0c084388u,
0x0c08438au,0x0c08438cu,0x0c08438eu,0x0c084390u,0x0c084392u,0x0c084394u,0x0c084396u,0x0c084398u,0x0c08439au,0x0c089348u,0x0c08934au,0x0c08934cu,0x0c08934eu,0x0c089350u,0x0c089352u,0x0c089354u,
0x0c089356u,0x0c089358u,0x0c0893c6u,0x0c0893c8u,0x0c0893cau,0x0c0893e4u,0x0c0893e6u,0x0c0893e8u,0x0c0893eau,0x0c0893ecu,0x0c0893eeu,0x0c0893f0u,0x0c0893f2u,0x0c0893f4u,0x0c0893f6u,0x0c0893f8u,
0x0c0893fau,0x0c0893fcu,0x0c0893feu,0x0c089400u,0x0c089402u,0x0c089404u,0x0c089406u,0x0c089408u,0x0c08940au,0x0c08940cu,0x0c08940eu,0x0c089410u,0x0c089412u,0x0c089414u,0x0c089416u,0x0c089418u,
0x0c08941au,0x0c08941cu,0x0c08941eu,0x0c089420u,0x0c089422u,0x0c089424u,0x0c090aa0u,0x0c090aa2u,0x0c090aa4u,0x0c090aa6u,0x0c090aa8u,0x0c090aaau,0x0c090aacu,0x0c090aaeu,0x0c0910beu,0x0c0910c0u,
0x0c0910c2u,0x0c0910c4u,0x0c0910c6u,0x0c0910c8u,0x0c0910cau,0x0c0910ccu,0x0c0910ceu,0x0c0910d0u,0x0c0910d2u,0x0c0910d4u,0x0c0910d6u,0x0c0910d8u,0x0c0910dau,0x0c0910dcu,0x0c0910deu,0x0c0910e0u,
0x0c0910e2u,0x0c0910e4u,0x0c0910e6u,0x0c0910e8u,0x0c0910eau,0x0c0910ecu,0x0c0910eeu,0x0c0910f0u,0x0c0910f2u,0x0c0910f4u,0x0c0910f6u,0x0c0910f8u,0x0c0910fau,0x0c0910fcu,0x0c0910feu,0x0c091100u,
0x0c091102u,0x0c091104u,0x0c091106u,0x0c091108u,0x0c09110au,0x0c09110cu,0x0c09110eu,0x0c091110u,0x0c091112u,0x0c091114u,0x0c091116u,0x0c091118u,0x0c09111au,0x0c09111cu,0x0c09111eu,0x0c091120u,
0x0c091122u,0x0c091124u,0x0c091126u,0x0c091128u,0x0c09112au,0x0c09112cu,0x0c09112eu,0x0c091130u,0x0c091132u,0x0c091134u,0x0c091136u,0x0c091138u,0x0c09113au,0x0c09113cu,0x0c09113eu,0x0c091142u,
0x0c091144u,0x0c091146u,0x0c091148u,0x0c09114au,0x0c09114cu,0x0c09114eu,0x0c091150u,0x0c091152u,0x0c091154u,0x0c091156u,0x0c091158u,0x0c09115au,0x0c09115cu,0x0c09115eu,0x0c091160u,0x0c091162u,
0x0c091164u,0x0c091166u,0x0c091168u,0x0c09116au,0x0c09116cu,0x0c09116eu,0x0c091170u,0x0c091172u,0x0c091174u,0x0c091176u,0x0c091178u,0x0c09117au,0x0c09117cu,0x0c09117eu,0x0c091180u,0x0c091182u,
0x0c091184u,0x0c091186u,0x0c091188u,0x0c09118au,0x0c09118cu,0x0c09118eu,0x0c091190u,0x0c091192u,0x0c091194u,0x0c091196u,0x0c091198u,0x0c09119au,0x0c09119cu,0x0c09119eu,0x0c0911a0u,0x0c0911a2u,
0x0c0911a4u,0x0c0911a6u,0x0c0911a8u,0x0c0911aau,0x0c0911acu,0x0c0911aeu,0x0c0911b0u,0x0c0911b2u,0x0c0911b4u,0x0c0911b6u,0x0c0911f2u,0x0c0911f4u,0x0c0911f6u,0x0c0911f8u,0x0c0911fau,0x0c0911fcu,
0x0c0911feu,0x0c091200u,0x0c091202u,0x0c091204u,0x0c091206u,0x0c091208u,0x0c09120au,0x0c09120cu,0x0c09120eu,0x0c091210u,0x0c091212u,0x0c091214u,0x0c091216u,0x0c091218u,0x0c09121au,0x0c09121cu,
0x0c09121eu,0x0c091220u,0x0c091222u,0x0c091224u,0x0c091226u,0x0c091228u,0x0c09122au,0x0c09122cu,0x0c09122eu,0x0c091230u,0x0c091232u,0x0c091234u,0x0c091236u,0x0c091238u,0x0c09123au,0x0c09123cu,
0x0c09123eu,0x0c091240u,0x0c091242u,0x0c091244u,0x0c091246u,0x0c091248u,0x0c09124au,0x0c09124cu,0x0c09124eu,0x0c091250u,0x0c091252u,0x0c091254u,0x0c091256u,0x0c091258u,0x0c09125au,0x0c09125cu,
0x0c09125eu,0x0c091260u,0x0c091262u,0x0c091264u,0x0c091266u,0x0c091268u,0x0c09126au,0x0c09126cu,0x0c09126eu,0x0c091270u,0x0c091272u,0x0c091274u,0x0c091276u,0x0c091278u,0x0c096866u,0x0c096868u,
0x0c09686au,0x0c09686cu,0x0c09686eu,0x0c096870u,0x0c096872u,0x0c096874u,0x0c096876u,0x0c096878u,0x0c09687au,0x0c09687cu,0x0c09687eu,0x0c096880u,0x0c096882u,0x0c096884u,0x0c096886u,0x0c096888u,
0x0c09688au,0x0c09688cu,0x0c09688eu,0x0c096890u,0x0c096892u,0x0c096894u,0x0c096896u,0x0c096898u,0x0c09689au,0x0c09689cu,0x0c09689eu,0x0c0968a0u,0x0c0968a2u,0x0c0968a4u,0x0c0968a6u,0x0c0968a8u,
0x0c0968aau,0x0c0968acu,0x0c0968aeu,0x0c0968d0u,0x0c0968d2u,0x0c0968d4u,0x0c0968d6u,0x0c0968d8u,0x0c0968dau,0x0c0968dcu,0x0c0968deu,0x0c0968e0u,0x0c0968e2u,0x0c0968e4u,0x0c0968e6u,0x0c0968e8u,
0x0c0968eau,0x0c0968ecu,0x0c0968eeu,0x0c0968f0u,0x0c0968f2u,0x0c0968f4u,0x0c0968f6u,0x0c096d5eu,0x0c096d60u,0x0c096d62u,0x0c096d64u,0x0c096d66u,0x0c096d68u,0x0c096d6au,0x0c096d6cu,0x0c096d6eu,
0x0c096d70u,0x0c096d72u,0x0c096d74u,0x0c096d76u,0x0c096d78u,0x0c096d7au,0x0c096d7cu,0x0c096d7eu,0x0c096d80u,0x0c096d82u,0x0c096d84u,0x0c096d86u,0x0c096d88u,0x0c096d8au,0x0c096d8cu,0x0c096d8eu,
0x0c096d90u,0x0c096d92u,0x0c096d94u,0x0c096d96u,0x0c096d98u,0x0c096d9au,0x0c096d9cu,0x0c096d9eu,0x0c096da0u,0x0c096da2u,0x0c096da4u,0x0c096da6u,0x0c096da8u,0x0c096daau,0x0c096dacu,0x0c096daeu,
0x0c096db0u,0x0c096db2u,0x0c096db4u,0x0c096db6u,0x0c096db8u,0x0c096dbau,0x0c096dbcu,0x0c096dbeu,0x0c09713cu,0x0c09713eu,0x0c097140u,0x0c097142u,0x0c097144u,0x0c097146u,0x0c097148u,0x0c09714au,
0x0c09714cu,0x0c09714eu,0x0c097150u,0x0c097152u,0x0c097154u,0x0c097156u,0x0c097158u,0x0c09715au,0x0c09715cu,0x0c09715eu,0x0c097160u,0x0c097162u,0x0c097164u,0x0c097166u,0x0c097168u,0x0c09716au,
0x0c09716cu,0x0c09716eu,0x0c097170u,0x0c097172u,0x0c097174u,0x0c097176u,0x0c097178u,0x0c09717au,0x0c09717cu,0x0c09717eu,0x0c097180u,0x0c097182u,0x0c097184u,0x0c097186u,0x0c097188u,0x0c09718au,
0x0c09718cu,0x0c09718eu,0x0c097190u,0x0c097192u,0x0c097194u,0x0c097196u,0x0c097198u,0x0c09719au,0x0c09719cu,0x0c09719eu,0x0c0971a0u,0x0c0971a2u,0x0c0971a4u,0x0c0971a6u,0x0c0971a8u,0x0c0971aau,
0x0c0971acu,0x0c0971aeu,0x0c0971b0u,0x0c0971b2u,0x0c0971b4u,0x0c0971b6u,0x0c0971b8u,0x0c0971bau,0x0c0971bcu,0x0c0971beu,0x0c0971c0u,0x0c0971c2u,0x0c0971c4u,0x0c0971c6u,0x0c0a2518u,0x0c0a251au,
0x0c0a251cu,0x0c0a251eu,0x0c0a2520u,0x0c0a2522u,0x0c0a2524u,0x0c0a2526u,0x0c0a2528u,0x0c0a252au,0x0c0a252cu,0x0c0a252eu,0x0c0a2530u,0x0c0a2532u,0x0c0a2534u,0x0c0a2536u,0x0c0a2538u,0x0c0a253au,
0x0c0a253cu,0x0c0a253eu,0x0c0a2540u,0x0c0a2542u,0x0c0a2544u,0x0c0a2546u,0x0c0a2548u,0x0c0a254au,0x0c0a254cu,0x0c0a254eu,0x0c0a2550u,0x0c0a2552u,0x0c0a2554u,0x0c0a2556u,0x0c0a2558u,0x0c0a255au,
0x0c0a255cu,0x0c0a255eu,0x0c0a2560u,0x0c0a2562u,0x0c0a2564u,0x0c0a2566u,0x0c0a2568u,0x0c0a256au,0x0c0a256cu,0x0c0a256eu,0x0c0a2570u,0x0c0a2572u,0x0c0c27aeu,0x0c0c27b0u,0x0c0c27b2u,0x0c0c27b4u,
0x0c0c27b6u,0x0c0c27b8u,0x0c0c27bau,0x0c0c27bcu,0x0c0c27beu,0x0c0c27c0u,0x0c0c27c2u,0x0c0c27c4u,0x0c0c27c6u,0x0c0c27c8u,0x0c0c27cau,0x0c0c27ccu,0x0c0c27ceu,0x0c0c27d0u,0x0c0c27d2u,0x0c0c27d4u,
0x0c0c27d6u,0x0c0c27d8u,0x0c0c27dau,0x0c0c27dcu,0x0c0c27deu,0x0c0c27e0u,0x0c0c27e2u,0x0c0c27e4u,0x0c0c27e6u,0x0c0c27e8u,0x0c0c27eau,0x0c0c27ecu,0x0c0c27eeu,0x0c0c27f0u,0x0c0c27f2u,0x0c0c27f4u,
0x0c0c27f6u,0x0c0c27f8u,0x0c0c27fau,0x0c0c27fcu,0x0c0c27feu,0x0c0c2800u,0x0c0c2802u,0x0c0c2804u,0x0c0c2806u,0x0c0c2808u,0x0c0c2ccau,0x0c0c2cccu,0x0c0c664cu,0x0c0c664eu,0x0c0c6650u,0x0c0c6652u,
0x0c0c6654u,0x0c0c6656u,0x0c0c6658u,0x0c0c665au,0x0c0c665cu,0x0c0c665eu,0x0c0c6660u,0x0c0c6662u,0x0c0c6664u,0x0c0c6666u,0x0c0c6668u,0x0c0c666au,0x0c0c666cu,0x0c0c666eu,0x0c0c6670u,0x0c0c6672u,
0x0c0c6674u,0x0c0c6676u,0x0c0c6678u,0x0c0c667au,0x0c0c667cu,0x0c0c667eu,0x0c0c6680u,0x0c0c6682u,0x0c0c6684u,0x0c0c6686u,0x0c0c6688u,0x0c0c668au,0x0c0c668cu,0x0c0c668eu,0x0c0c6690u,0x0c0c74b8u,
0x0c0c74bau,0x0c0c8d8eu,0x0c0c8d90u,0x0c0c8d92u,0x0c0c8d94u,0x0c0c8d96u,0x0c0c8d98u,0x0c0c8d9au,0x0c0c8d9cu,0x0c0c8d9eu,0x0c0c8da0u,0x0c0c8da2u,0x0c0c8da4u,0x0c0c8da6u,0x0c0c8da8u,0x0c0c8daau,
0x0c0c8dacu,0x0c0c8daeu,0x0c0c8db0u,0x0c0c8db2u,0x0c0c8db4u,0x0c0c8db6u,0x0c0c8db8u,0x0c0c8dbau,0x0c0c8dbcu,0x0c0c8dbeu,0x0c0c8dc0u,0x0c0c8dc2u,0x0c0c8dc4u,0x0c0c8dc6u,0x0c0c8dc8u,0x0c0c8dcau,
0x0c0c8dccu,0x0c0c8dceu,0x0c0c8dd0u,0x0c0c8dd2u,0x0c0c8dd4u,0x0c0c8dd6u,0x0c0c8dd8u,0x0c0c8ddau,0x0c0c8ddcu,0x0c0c8ddeu,0x0c0c8de0u,0x0c0c8de2u,0x0c0c8de4u,0x0c0c8de6u,0x0c0c8de8u,0x0c0c8f76u,
0x0c0c8f78u,0x0c0c8f7au,0x0c0c8f7cu,0x0c0c8f7eu,0x0c0c8f80u,0x0c0c8f82u,0x0c0c8f84u,0x0c0c8f86u,0x0c0c8f88u,0x0c0c8f8au,0x0c0c8f8cu,0x0c0c8f8eu,0x0c0c8f90u,0x0c0c8f92u,0x0c0c8f94u,0x0c0c8f96u,
0x0c0c8f98u,0x0c0c8f9au,0x0c0c8f9cu,0x0c0c8f9eu,0x0c0c8fa0u,0x0c0c8fa2u,0x0c0c8fa4u,0x0c0c8fa6u,0x0c0c8fa8u,0x0c0c8faau,0x0c0c8facu,0x0c0c8faeu,0x0c0c8fb0u,0x0c0c8fb2u,0x0c0c8fb4u,0x0c0c8fb6u,
0x0c0c8fb8u,0x0c0c8fbau,0x0c0c8fbcu,0x0c0c8fbeu,0x0c0c8fc0u,0x0c0c8fc2u,0x0c0c8fcau,0x0c0c8fccu,0x0c0c8fceu,0x0c0c8fd0u,0x0c0c8fd2u,0x0c0c8fd4u,0x0c0c8fd6u,0x0c0c8fd8u,0x0c0c8fdau,0x0c0c8fdcu,
0x0c0c8fdeu,0x0c0c8fe0u,0x0c0c8fe2u,0x0c0c8fe4u,0x0c0c8fe6u,0x0c0c8fe8u,0x0c0c8feau,0x0c0c8fecu,0x0c0c8feeu,0x0c0c8ff0u,0x0c0c8ff2u,0x0c0c8ff4u,0x0c0c8ff6u,0x0c0c8ff8u,0x0c0c8ffau,0x0c0c8ffcu,
0x0c0c8ffeu,0x0c0c9000u,0x0c0c9002u,0x0c0c9004u,0x0c0c9006u,0x0c0c9008u,0x0c0c900au,0x0c0c900cu,0x0c0c900eu,0x0c0c9010u,0x0c0c9012u,0x0c0c9014u,0x0c0c9016u,0x0c0c9052u,0x0c0c9054u,0x0c0c9056u,
0x0c0c9058u,0x0c0c905au,0x0c0c905cu,0x0c0c905eu,0x0c0c9060u,0x0c0c9062u,0x0c0c9064u,0x0c0c9066u,0x0c0c9068u,0x0c0c906au,0x0c0c906cu,0x0c0c906eu,0x0c0c9070u,0x0c0c9072u,0x0c0c9074u,0x0c0c9076u,
0x0c0c9078u,0x0c0c907au,0x0c0c907cu,0x0c0c907eu,0x0c0c9080u,0x0c0c9082u,0x0c0c9084u,0x0c0c9086u,0x0c0c9088u,0x0c0c908au,0x0c0c908cu,0x0c0c908eu,0x0c0c9090u,0x0c0c9092u,0x0c0c9094u,0x0c0c9096u,
0x0c0c9098u,0x0c0c909au,0x0c0c909cu,0x0c0c909eu,0x0c0c90a0u,0x0c0c90a2u,0x0c0c90a4u,0x0c0c90a6u,0x0c0c90a8u,0x0c0c90aau,0x0c0c90acu,0x0c0c90aeu,0x0c0c90b0u,0x0c0c90b2u,0x0c0c90b4u,0x0c0c90b6u,
};
static const uint32_t claim_pcs[]={
0x0c0103bau,0x0c0103bcu,0x0c0103beu,0x0c0103c0u,0x0c0103c2u,0x0c0103c4u,0x0c0103c6u,0x0c0103c8u,0x0c0103cau,0x0c0103ccu,0x0c0103ceu,0x0c0103d0u,0x0c0103d2u,0x0c0103d4u,0x0c0103d6u,0x0c0103d8u,
0x0c0103dau,0x0c0103dcu,0x0c0103deu,0x0c0103e0u,0x0c0103e2u,0x0c0103e4u,0x0c0103e6u,0x0c0103e8u,0x0c0103eau,0x0c0103ecu,0x0c0103eeu,0x0c0103f0u,0x0c0103f2u,0x0c0103f4u,0x0c0103f6u,0x0c0103f8u,
0x0c0103fau,0x0c0103fcu,0x0c0103feu,0x0c010400u,0x0c010630u,0x0c010632u,0x0c010634u,0x0c010636u,0x0c010638u,0x0c01063au,0x0c01063cu,0x0c01063eu,0x0c010640u,0x0c010642u,0x0c010644u,0x0c010646u,
0x0c010648u,0x0c01064au,0x0c01064cu,0x0c01064eu,0x0c010650u,0x0c010652u,0x0c010654u,0x0c010656u,0x0c010658u,0x0c01065au,0x0c01065cu,0x0c01065eu,0x0c010660u,0x0c010662u,0x0c010664u,0x0c010666u,
0x0c010668u,0x0c01066au,0x0c01066cu,0x0c01066eu,0x0c010670u,0x0c010672u,0x0c010674u,0x0c010676u,0x0c010678u,0x0c01067au,0x0c01067cu,0x0c01067eu,0x0c010680u,0x0c010954u,0x0c010f3cu,0x0c010f3eu,
0x0c010f40u,0x0c0113b4u,0x0c0113b6u,0x0c0113b8u,0x0c0113bau,0x0c0113bcu,0x0c0113beu,0x0c0113c0u,0x0c011a24u,0x0c035270u,0x0c035306u,0x0c035518u,0x0c039748u,0x0c03974au,0x0c03974cu,0x0c03974eu,
0x0c039750u,0x0c039752u,0x0c039754u,0x0c039756u,0x0c039758u,0x0c03975au,0x0c03975cu,0x0c03975eu,0x0c039760u,0x0c039762u,0x0c039764u,0x0c039766u,0x0c039768u,0x0c03976au,0x0c03976cu,0x0c03976eu,
0x0c039770u,0x0c039772u,0x0c039774u,0x0c039776u,0x0c039778u,0x0c03977au,0x0c03977cu,0x0c03977eu,0x0c039780u,0x0c039782u,0x0c039784u,0x0c039786u,0x0c039788u,0x0c03978au,0x0c03978cu,0x0c03978eu,
0x0c039790u,0x0c039792u,0x0c039794u,0x0c039cb4u,0x0c039cb6u,0x0c039cb8u,0x0c039cbau,0x0c039cbcu,0x0c039cbeu,0x0c039cc0u,0x0c039cc2u,0x0c039cc4u,0x0c039cc6u,0x0c039cc8u,0x0c039ccau,0x0c039cccu,
0x0c039cceu,0x0c039cd0u,0x0c039ce0u,0x0c039ce2u,0x0c039ce4u,0x0c039cf0u,0x0c039cf2u,0x0c039cf4u,0x0c039d00u,0x0c039d02u,0x0c039d04u,0x0c039d70u,0x0c039d72u,0x0c039d74u,0x0c039d76u,0x0c039d78u,
0x0c039d7au,0x0c039d7cu,0x0c039d7eu,0x0c039d80u,0x0c039d82u,0x0c039d84u,0x0c039d86u,0x0c039d90u,0x0c039d92u,0x0c039d94u,0x0c039d96u,0x0c039d98u,0x0c03aa9cu,0x0c0432e2u,0x0c047a5au,0x0c04853au,
0x0c049142u,0x0c049a78u,0x0c055c96u,0x0c055c98u,0x0c055c9au,0x0c055c9cu,0x0c055c9eu,0x0c055ca0u,0x0c055ca2u,0x0c055ca4u,0x0c055ca6u,0x0c055ca8u,0x0c055caau,0x0c055cacu,0x0c055caeu,0x0c055cb0u,
0x0c055cb2u,0x0c055cb4u,0x0c055cb6u,0x0c055cb8u,0x0c055cbau,0x0c055cbcu,0x0c055cbeu,0x0c055cc0u,0x0c055cc2u,0x0c055cc4u,0x0c055cc6u,0x0c055cc8u,0x0c055ccau,0x0c055cccu,0x0c055cceu,0x0c055cd0u,
0x0c055cd2u,0x0c055cd4u,0x0c055cd6u,0x0c055cd8u,0x0c055cdau,0x0c055cdcu,0x0c055cdeu,0x0c055ce0u,0x0c055ce2u,0x0c058788u,0x0c05df8au,0x0c05df8cu,0x0c05df8eu,0x0c05df90u,0x0c05df92u,0x0c05df94u,
0x0c05df96u,0x0c05df98u,0x0c05df9au,0x0c05df9cu,0x0c05df9eu,0x0c05dfa0u,0x0c05dfa2u,0x0c05dfa4u,0x0c05dfa6u,0x0c05dfa8u,0x0c05dfaau,0x0c05dfacu,0x0c05dfaeu,0x0c05dfb0u,0x0c05dfb2u,0x0c05dfb4u,
0x0c05dfb6u,0x0c05dfb8u,0x0c05dfbau,0x0c05dfbcu,0x0c05dfbeu,0x0c05dfc0u,0x0c05dfc2u,0x0c05dfc4u,0x0c05dfc6u,0x0c05dfc8u,0x0c05dfcau,0x0c05dfccu,0x0c05dfceu,0x0c05dfd0u,0x0c05dfd2u,0x0c05dfd4u,
0x0c05dfd6u,0x0c05edd4u,0x0c05edd6u,0x0c05edd8u,0x0c05eddau,0x0c05eddcu,0x0c05eddeu,0x0c05ede0u,0x0c05ede2u,0x0c05ede4u,0x0c05ede6u,0x0c05ede8u,0x0c05edeau,0x0c05edecu,0x0c05edeeu,0x0c05edf0u,
0x0c05edf2u,0x0c05edf4u,0x0c05edf6u,0x0c05edf8u,0x0c05edfau,0x0c05edfcu,0x0c05edfeu,0x0c05ee00u,0x0c05ee02u,0x0c05ee04u,0x0c05ee06u,0x0c05ee08u,0x0c05ee0au,0x0c05ee0cu,0x0c05ee0eu,0x0c05ee10u,
0x0c05ee12u,0x0c05ee14u,0x0c05ee16u,0x0c05ee18u,0x0c05ee1au,0x0c05ee1cu,0x0c05ee1eu,0x0c05ee20u,0x0c05ee22u,0x0c05ee24u,0x0c05ee26u,0x0c05ee28u,0x0c05ee2au,0x0c05ee2cu,0x0c05ee2eu,0x0c05ee30u,
0x0c05ee32u,0x0c05f33au,0x0c05f3deu,0x0c05f3e0u,0x0c05f3e2u,0x0c05f3e4u,0x0c05f3e6u,0x0c05f3e8u,0x0c05fc32u,0x0c06256eu,0x0c06da9cu,0x0c06da9eu,0x0c06daa0u,0x0c06daa2u,0x0c06daa4u,0x0c06daa6u,
0x0c06daa8u,0x0c06daaau,0x0c06daacu,0x0c06daaeu,0x0c06dab0u,0x0c06dab2u,0x0c06dab4u,0x0c06dab6u,0x0c06dab8u,0x0c06dabau,0x0c06dabcu,0x0c06dabeu,0x0c06dac0u,0x0c06dac2u,0x0c06dac4u,0x0c06dac6u,
0x0c06dac8u,0x0c06dacau,0x0c06daccu,0x0c06daceu,0x0c06dad0u,0x0c06dad2u,0x0c06dad4u,0x0c06dad6u,0x0c06dad8u,0x0c06dadau,0x0c06dadcu,0x0c06dadeu,0x0c06dae0u,0x0c06dae2u,0x0c06dae4u,0x0c06dae6u,
0x0c06db34u,0x0c06db36u,0x0c06db38u,0x0c06db3au,0x0c06db3cu,0x0c06dc44u,0x0c07c446u,0x0c07c448u,0x0c07c44au,0x0c07c44cu,0x0c07c44eu,0x0c07c450u,0x0c07c452u,0x0c07c454u,0x0c07c456u,0x0c07c458u,
0x0c07c45au,0x0c07c45cu,0x0c07c45eu,0x0c07c460u,0x0c07c462u,0x0c07c464u,0x0c07c466u,0x0c07c468u,0x0c07c46au,0x0c07c46cu,0x0c07c46eu,0x0c07c470u,0x0c07c472u,0x0c07c474u,0x0c07c476u,0x0c07c478u,
0x0c07c47au,0x0c07c47cu,0x0c07c47eu,0x0c07c480u,0x0c07c482u,0x0c07c484u,0x0c07c486u,0x0c07c488u,0x0c07c48au,0x0c07c48cu,0x0c07c48eu,0x0c07c490u,0x0c07c492u,0x0c07c494u,0x0c07c496u,0x0c07c498u,
0x0c07c49au,0x0c07c49cu,0x0c07c49eu,0x0c07c4a0u,0x0c07c4a6u,0x0c07c4a8u,0x0c07c4aau,0x0c07c4acu,0x0c07c4aeu,0x0c07c4b0u,0x0c07c4b2u,0x0c07c4b4u,0x0c07c4b6u,0x0c07c4b8u,0x0c07c4bau,0x0c07c4bcu,
0x0c07c4beu,0x0c07c4c0u,0x0c07c4c2u,0x0c07c4c4u,0x0c07c4c6u,0x0c07c4c8u,0x0c07c4cau,0x0c07c4ccu,0x0c07c4ceu,0x0c07c4d0u,0x0c07c4d2u,0x0c07c4d4u,0x0c07c4d6u,0x0c07c4d8u,0x0c07c4dau,0x0c07c4dcu,
0x0c07c4deu,0x0c07c4e0u,0x0c07c4e2u,0x0c07c4e4u,0x0c07c4e6u,0x0c07c4e8u,0x0c07c4eau,0x0c07c4ecu,0x0c07c4eeu,0x0c07c4f0u,0x0c07c4f2u,0x0c07c4f4u,0x0c07c4f6u,0x0c07c4f8u,0x0c07c4fau,0x0c07c4fcu,
0x0c07c4feu,0x0c07c500u,0x0c07c502u,0x0c07c504u,0x0c07c6b6u,0x0c07c6b8u,0x0c07c6bau,0x0c07c6bcu,0x0c07c6beu,0x0c07c6c0u,0x0c07c6c2u,0x0c07c6c4u,0x0c07c6c6u,0x0c07c6c8u,0x0c07c6cau,0x0c07c6ccu,
0x0c07c6ceu,0x0c07c6d0u,0x0c07c6d2u,0x0c07c6d4u,0x0c07c6d6u,0x0c07c6d8u,0x0c07c6dau,0x0c07c6dcu,0x0c07c6deu,0x0c07c6e0u,0x0c07c6e2u,0x0c07c6e4u,0x0c07c6e6u,0x0c07c6e8u,0x0c07c6eau,0x0c07c6ecu,
0x0c07c6eeu,0x0c07c6f0u,0x0c07c6f2u,0x0c07c6f4u,0x0c07c6f6u,0x0c07c6f8u,0x0c07c6fau,0x0c07c6fcu,0x0c07c6feu,0x0c07c700u,0x0c07c702u,0x0c07c704u,0x0c07c706u,0x0c07c708u,0x0c07c70au,0x0c07c70cu,
0x0c07c70eu,0x0c07c710u,0x0c07c712u,0x0c07c714u,0x0c07c716u,0x0c07c718u,0x0c07c71au,0x0c07c71cu,0x0c07c71eu,0x0c07c720u,0x0c07fbecu,0x0c07fbeeu,0x0c07fbf0u,0x0c07fbf2u,0x0c07fbf4u,0x0c07fbf6u,
0x0c07fbf8u,0x0c07fbfau,0x0c07fbfcu,0x0c07fbfeu,0x0c07fc00u,0x0c07fc02u,0x0c07fc04u,0x0c07fc06u,0x0c07fc08u,0x0c07fc0au,0x0c07fc0cu,0x0c07fc0eu,0x0c07fc10u,0x0c07fc12u,0x0c07fc14u,0x0c07fc16u,
0x0c07fc18u,0x0c07fc1au,0x0c07fc1cu,0x0c07fc1eu,0x0c07fc20u,0x0c07fc22u,0x0c07fc24u,0x0c07fc26u,0x0c07fc28u,0x0c07fc2au,0x0c07fc2cu,0x0c07fc2eu,0x0c07fc30u,0x0c07fc32u,0x0c07fc34u,0x0c07fc36u,
0x0c07fc38u,0x0c07fc3au,0x0c07fc3cu,0x0c07fc3eu,0x0c07fc40u,0x0c07fc42u,0x0c07fc44u,0x0c07fc46u,0x0c07fc48u,0x0c07fc4au,0x0c07fc4cu,0x0c07fc4eu,0x0c07fc50u,0x0c07fc52u,0x0c08430eu,0x0c084310u,
0x0c084312u,0x0c084314u,0x0c084316u,0x0c084318u,0x0c08431au,0x0c08431cu,0x0c08431eu,0x0c084320u,0x0c084322u,0x0c084324u,0x0c084326u,0x0c084328u,0x0c08432au,0x0c08432cu,0x0c08432eu,0x0c084330u,
0x0c084332u,0x0c084334u,0x0c084336u,0x0c084338u,0x0c08433au,0x0c08433cu,0x0c08433eu,0x0c084340u,0x0c084342u,0x0c084344u,0x0c084346u,0x0c084348u,0x0c08434au,0x0c08434cu,0x0c08434eu,0x0c084350u,
0x0c084352u,0x0c084354u,0x0c084356u,0x0c084358u,0x0c08435au,0x0c08435cu,0x0c08435eu,0x0c084360u,0x0c084362u,0x0c084364u,0x0c084366u,0x0c084368u,0x0c08436au,0x0c08436cu,0x0c08436eu,0x0c084370u,
0x0c084372u,0x0c084374u,0x0c084376u,0x0c084378u,0x0c08437au,0x0c08437cu,0x0c08437eu,0x0c084380u,0x0c084382u,0x0c084384u,0x0c084386u,0x0c084388u,0x0c08438au,0x0c08438cu,0x0c08438eu,0x0c084390u,
0x0c084392u,0x0c084394u,0x0c084396u,0x0c084398u,0x0c08439au,0x0c089348u,0x0c08934au,0x0c08934cu,0x0c08934eu,0x0c089350u,0x0c089352u,0x0c089354u,0x0c089356u,0x0c089358u,0x0c0893c6u,0x0c0893c8u,
0x0c0893cau,0x0c0893e4u,0x0c0893e6u,0x0c0893e8u,0x0c0893eau,0x0c0893ecu,0x0c0893eeu,0x0c0893f0u,0x0c0893f2u,0x0c0893f4u,0x0c0893f6u,0x0c0893f8u,0x0c0893fau,0x0c0893fcu,0x0c0893feu,0x0c089400u,
0x0c089402u,0x0c089404u,0x0c089406u,0x0c089408u,0x0c08940au,0x0c08940cu,0x0c08940eu,0x0c089410u,0x0c089412u,0x0c089414u,0x0c089416u,0x0c089418u,0x0c08941au,0x0c08941cu,0x0c08941eu,0x0c089420u,
0x0c089422u,0x0c089424u,0x0c090aa0u,0x0c090aa2u,0x0c090aa4u,0x0c090aa6u,0x0c090aa8u,0x0c090aaau,0x0c090aacu,0x0c090aaeu,0x0c0910beu,0x0c0910c0u,0x0c0910c2u,0x0c0910c4u,0x0c0910c6u,0x0c0910c8u,
0x0c0910cau,0x0c0910ccu,0x0c0910ceu,0x0c0910d0u,0x0c0910d2u,0x0c0910d4u,0x0c0910d6u,0x0c0910d8u,0x0c0910dau,0x0c0910dcu,0x0c0910deu,0x0c0910e0u,0x0c0910e2u,0x0c0910e4u,0x0c0910e6u,0x0c0910e8u,
0x0c0910eau,0x0c0910ecu,0x0c0910eeu,0x0c0910f0u,0x0c0910f2u,0x0c0910f4u,0x0c0910f6u,0x0c0910f8u,0x0c0910fau,0x0c0910fcu,0x0c0910feu,0x0c091100u,0x0c091102u,0x0c091104u,0x0c091106u,0x0c091142u,
0x0c091144u,0x0c091146u,0x0c091148u,0x0c09114au,0x0c09114cu,0x0c09114eu,0x0c091150u,0x0c091152u,0x0c091154u,0x0c091156u,0x0c091158u,0x0c09115au,0x0c09115cu,0x0c09115eu,0x0c091160u,0x0c091162u,
0x0c091164u,0x0c091166u,0x0c091168u,0x0c09116au,0x0c09116cu,0x0c09116eu,0x0c091170u,0x0c091172u,0x0c091174u,0x0c091176u,0x0c091178u,0x0c09117au,0x0c09117cu,0x0c09117eu,0x0c0911f2u,0x0c0911f4u,
0x0c0911f6u,0x0c0911f8u,0x0c0911fau,0x0c0911fcu,0x0c0911feu,0x0c091200u,0x0c091202u,0x0c091204u,0x0c091206u,0x0c091208u,0x0c09120au,0x0c09120cu,0x0c09120eu,0x0c091210u,0x0c091212u,0x0c091214u,
0x0c091216u,0x0c091218u,0x0c09121au,0x0c09121cu,0x0c09121eu,0x0c091220u,0x0c091222u,0x0c091224u,0x0c091226u,0x0c091228u,0x0c09122au,0x0c09122cu,0x0c09122eu,0x0c091230u,0x0c091232u,0x0c091234u,
0x0c091236u,0x0c091238u,0x0c09123au,0x0c09123cu,0x0c09123eu,0x0c091240u,0x0c096866u,0x0c09713cu,0x0c09713eu,0x0c097140u,0x0c097142u,0x0c097144u,0x0c097146u,0x0c097148u,0x0c09714au,0x0c09714cu,
0x0c09714eu,0x0c097150u,0x0c097152u,0x0c097154u,0x0c097156u,0x0c097158u,0x0c09715au,0x0c09715cu,0x0c09715eu,0x0c097160u,0x0c097162u,0x0c097164u,0x0c097166u,0x0c097168u,0x0c09716au,0x0c09716cu,
0x0c09716eu,0x0c097170u,0x0c097172u,0x0c097174u,0x0c097176u,0x0c097178u,0x0c09717au,0x0c09717cu,0x0c09717eu,0x0c097180u,0x0c097182u,0x0c097184u,0x0c097186u,0x0c097188u,0x0c09718au,0x0c09718cu,
0x0c09718eu,0x0c097190u,0x0c097192u,0x0c097194u,0x0c097196u,0x0c097198u,0x0c09719au,0x0c09719cu,0x0c09719eu,0x0c0971a0u,0x0c0971a2u,0x0c0971a4u,0x0c0971a6u,0x0c0971a8u,0x0c0971aau,0x0c0971acu,
0x0c0971aeu,0x0c0971b0u,0x0c0971b2u,0x0c0971b4u,0x0c0971b6u,0x0c0971b8u,0x0c0971bau,0x0c0971bcu,0x0c0971beu,0x0c0971c0u,0x0c0971c2u,0x0c0971c4u,0x0c0971c6u,0x0c0a2518u,0x0c0c27aeu,0x0c0c2ccau,
0x0c0c2cccu,0x0c0c664cu,0x0c0c664eu,0x0c0c6650u,0x0c0c6652u,0x0c0c6654u,0x0c0c6656u,0x0c0c6658u,0x0c0c665au,0x0c0c665cu,0x0c0c665eu,0x0c0c6660u,0x0c0c6662u,0x0c0c6664u,0x0c0c6666u,0x0c0c6668u,
0x0c0c666au,0x0c0c666cu,0x0c0c666eu,0x0c0c6670u,0x0c0c6672u,0x0c0c6674u,0x0c0c6676u,0x0c0c6678u,0x0c0c667au,0x0c0c667cu,0x0c0c667eu,0x0c0c6680u,0x0c0c6682u,0x0c0c6684u,0x0c0c6686u,0x0c0c6688u,
0x0c0c668au,0x0c0c668cu,0x0c0c668eu,0x0c0c6690u,0x0c0c74b8u,0x0c0c74bau,0x0c0c8d8eu,0x0c0c8d90u,0x0c0c8d92u,0x0c0c8d94u,0x0c0c8d96u,0x0c0c8d98u,0x0c0c8d9au,0x0c0c8d9cu,0x0c0c8d9eu,0x0c0c8da0u,
0x0c0c8da2u,0x0c0c8da4u,0x0c0c8da6u,0x0c0c8da8u,0x0c0c8daau,0x0c0c8dacu,0x0c0c8daeu,0x0c0c8db0u,0x0c0c8db2u,0x0c0c8db4u,0x0c0c8db6u,0x0c0c8db8u,0x0c0c8dbau,0x0c0c8dbcu,0x0c0c8dbeu,0x0c0c8dc0u,
0x0c0c8dc2u,0x0c0c8dc4u,0x0c0c8dc6u,0x0c0c8dc8u,0x0c0c8dcau,0x0c0c8dccu,0x0c0c8dceu,0x0c0c8dd0u,0x0c0c8dd2u,0x0c0c8dd4u,0x0c0c8dd6u,0x0c0c8dd8u,0x0c0c8ddau,0x0c0c8ddcu,0x0c0c8ddeu,0x0c0c8de0u,
0x0c0c8de2u,0x0c0c8de4u,0x0c0c8de6u,0x0c0c8de8u,0x0c0c8f76u,0x0c0c8f78u,0x0c0c8f7au,0x0c0c8f7cu,0x0c0c8f7eu,0x0c0c8f80u,0x0c0c8f82u,0x0c0c8f84u,0x0c0c8f86u,0x0c0c8f88u,0x0c0c8f8au,0x0c0c8f8cu,
0x0c0c8f8eu,0x0c0c8f90u,0x0c0c8f92u,0x0c0c8f94u,0x0c0c8f96u,0x0c0c8f98u,0x0c0c8f9au,0x0c0c8f9cu,0x0c0c8f9eu,0x0c0c8fa0u,0x0c0c8fa2u,0x0c0c8fa4u,0x0c0c8fa6u,0x0c0c8fa8u,0x0c0c8faau,0x0c0c8facu,
0x0c0c8faeu,0x0c0c8fb0u,0x0c0c8fb2u,0x0c0c8fb4u,0x0c0c8fb6u,0x0c0c8fb8u,0x0c0c8fbau,0x0c0c8fbcu,0x0c0c8fbeu,0x0c0c8fc0u,0x0c0c8fc2u,0x0c0c8fcau,0x0c0c8fccu,0x0c0c8fceu,0x0c0c8fd0u,0x0c0c8fd2u,
0x0c0c8fd4u,0x0c0c8fd6u,0x0c0c8fd8u,0x0c0c8fdau,0x0c0c8fdcu,0x0c0c8fdeu,0x0c0c8fe0u,0x0c0c8fe2u,0x0c0c8fe4u,0x0c0c8fe6u,0x0c0c8fe8u,0x0c0c8feau,0x0c0c8fecu,0x0c0c8feeu,0x0c0c8ff0u,0x0c0c8ff2u,
0x0c0c8ff4u,0x0c0c8ff6u,0x0c0c8ff8u,0x0c0c8ffau,0x0c0c8ffcu,0x0c0c8ffeu,0x0c0c9000u,0x0c0c9002u,0x0c0c9004u,0x0c0c9006u,0x0c0c9008u,0x0c0c900au,0x0c0c900cu,0x0c0c900eu,0x0c0c9010u,0x0c0c9012u,
0x0c0c9014u,0x0c0c9016u,0x0c0c9052u,0x0c0c9054u,0x0c0c9056u,0x0c0c9058u,0x0c0c905au,0x0c0c905cu,0x0c0c905eu,0x0c0c9060u,0x0c0c9062u,0x0c0c9064u,0x0c0c9066u,0x0c0c9068u,0x0c0c906au,0x0c0c906cu,
0x0c0c906eu,0x0c0c9070u,0x0c0c9072u,0x0c0c9074u,0x0c0c9076u,0x0c0c9078u,0x0c0c907au,0x0c0c907cu,0x0c0c907eu,0x0c0c9080u,0x0c0c9082u,0x0c0c9084u,0x0c0c9086u,0x0c0c9088u,0x0c0c908au,0x0c0c908cu,
0x0c0c908eu,0x0c0c9090u,0x0c0c9092u,0x0c0c9094u,0x0c0c9096u,0x0c0c9098u,0x0c0c909au,0x0c0c909cu,0x0c0c909eu,0x0c0c90a0u,0x0c0c90a2u,0x0c0c90a4u,0x0c0c90a6u,0x0c0c90a8u,0x0c0c90aau,0x0c0c90acu,
0x0c0c90aeu,0x0c0c90b0u,0x0c0c90b2u,0x0c0c90b4u,0x0c0c90b6u,
};
int vf3_gap_b03_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
