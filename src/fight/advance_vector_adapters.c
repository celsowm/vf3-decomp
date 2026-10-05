/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_advance_vector_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c090000u: goto P_0c090000;
case 0x0c090002u: goto P_0c090002;
case 0x0c090004u: goto P_0c090004;
case 0x0c090006u: goto P_0c090006;
case 0x0c090008u: goto P_0c090008;
case 0x0c09000au: goto P_0c09000a;
case 0x0c09000cu: goto P_0c09000c;
case 0x0c09000eu: goto P_0c09000e;
case 0x0c090010u: goto P_0c090010;
case 0x0c090012u: goto P_0c090012;
case 0x0c090014u: goto P_0c090014;
case 0x0c090016u: goto P_0c090016;
case 0x0c090018u: goto P_0c090018;
case 0x0c09001au: goto P_0c09001a;
case 0x0c09001cu: goto P_0c09001c;
case 0x0c09001eu: goto P_0c09001e;
case 0x0c090020u: goto P_0c090020;
case 0x0c090022u: goto P_0c090022;
case 0x0c090024u: goto P_0c090024;
case 0x0c090026u: goto P_0c090026;
case 0x0c090028u: goto P_0c090028;
case 0x0c09002au: goto P_0c09002a;
case 0x0c09002cu: goto P_0c09002c;
case 0x0c09002eu: goto P_0c09002e;
case 0x0c090030u: goto P_0c090030;
case 0x0c090032u: goto P_0c090032;
case 0x0c090034u: goto P_0c090034;
case 0x0c090036u: goto P_0c090036;
case 0x0c090038u: goto P_0c090038;
case 0x0c09003au: goto P_0c09003a;
case 0x0c09003cu: goto P_0c09003c;
case 0x0c09003eu: goto P_0c09003e;
case 0x0c090040u: goto P_0c090040;
case 0x0c090042u: goto P_0c090042;
case 0x0c090044u: goto P_0c090044;
case 0x0c090046u: goto P_0c090046;
case 0x0c090048u: goto P_0c090048;
case 0x0c09004au: goto P_0c09004a;
case 0x0c09004cu: goto P_0c09004c;
case 0x0c09004eu: goto P_0c09004e;
case 0x0c090050u: goto P_0c090050;
case 0x0c090052u: goto P_0c090052;
case 0x0c090054u: goto P_0c090054;
case 0x0c090056u: goto P_0c090056;
case 0x0c090058u: goto P_0c090058;
case 0x0c09005au: goto P_0c09005a;
case 0x0c09005cu: goto P_0c09005c;
case 0x0c09005eu: goto P_0c09005e;
case 0x0c090060u: goto P_0c090060;
case 0x0c090062u: goto P_0c090062;
case 0x0c090064u: goto P_0c090064;
case 0x0c090066u: goto P_0c090066;
case 0x0c090068u: goto P_0c090068;
case 0x0c09006au: goto P_0c09006a;
case 0x0c09006cu: goto P_0c09006c;
case 0x0c09006eu: goto P_0c09006e;
case 0x0c090070u: goto P_0c090070;
case 0x0c090072u: goto P_0c090072;
case 0x0c090074u: goto P_0c090074;
case 0x0c090076u: goto P_0c090076;
case 0x0c090078u: goto P_0c090078;
case 0x0c09007au: goto P_0c09007a;
case 0x0c09007cu: goto P_0c09007c;
case 0x0c09007eu: goto P_0c09007e;
case 0x0c090080u: goto P_0c090080;
case 0x0c090082u: goto P_0c090082;
case 0x0c090084u: goto P_0c090084;
case 0x0c090086u: goto P_0c090086;
case 0x0c090088u: goto P_0c090088;
case 0x0c09008au: goto P_0c09008a;
case 0x0c09008cu: goto P_0c09008c;
case 0x0c09008eu: goto P_0c09008e;
case 0x0c090090u: goto P_0c090090;
case 0x0c090092u: goto P_0c090092;
case 0x0c090094u: goto P_0c090094;
case 0x0c090096u: goto P_0c090096;
case 0x0c090098u: goto P_0c090098;
case 0x0c09009au: goto P_0c09009a;
case 0x0c09009cu: goto P_0c09009c;
case 0x0c09009eu: goto P_0c09009e;
case 0x0c0900a0u: goto P_0c0900a0;
case 0x0c0900a2u: goto P_0c0900a2;
case 0x0c0900a4u: goto P_0c0900a4;
case 0x0c0900a6u: goto P_0c0900a6;
case 0x0c0900a8u: goto P_0c0900a8;
case 0x0c0900aau: goto P_0c0900aa;
case 0x0c0900acu: goto P_0c0900ac;
case 0x0c0900aeu: goto P_0c0900ae;
case 0x0c0900b0u: goto P_0c0900b0;
case 0x0c0900b2u: goto P_0c0900b2;
case 0x0c0900b4u: goto P_0c0900b4;
case 0x0c0900b6u: goto P_0c0900b6;
case 0x0c0900b8u: goto P_0c0900b8;
case 0x0c0900bau: goto P_0c0900ba;
case 0x0c0900bcu: goto P_0c0900bc;
case 0x0c0900beu: goto P_0c0900be;
case 0x0c0900c0u: goto P_0c0900c0;
case 0x0c0900c2u: goto P_0c0900c2;
case 0x0c0900c4u: goto P_0c0900c4;
case 0x0c0900c6u: goto P_0c0900c6;
case 0x0c0900c8u: goto P_0c0900c8;
case 0x0c0900cau: goto P_0c0900ca;
case 0x0c0900ccu: goto P_0c0900cc;
case 0x0c0900ceu: goto P_0c0900ce;
case 0x0c0900d0u: goto P_0c0900d0;
case 0x0c0900d2u: goto P_0c0900d2;
case 0x0c0900d4u: goto P_0c0900d4;
case 0x0c0900d6u: goto P_0c0900d6;
case 0x0c0900d8u: goto P_0c0900d8;
case 0x0c0900dau: goto P_0c0900da;
case 0x0c0900f4u: goto P_0c0900f4;
case 0x0c0900f6u: goto P_0c0900f6;
case 0x0c0900f8u: goto P_0c0900f8;
case 0x0c0900fau: goto P_0c0900fa;
case 0x0c0900fcu: goto P_0c0900fc;
case 0x0c0900feu: goto P_0c0900fe;
case 0x0c090100u: goto P_0c090100;
case 0x0c090102u: goto P_0c090102;
case 0x0c090104u: goto P_0c090104;
case 0x0c090106u: goto P_0c090106;
case 0x0c090108u: goto P_0c090108;
case 0x0c09010au: goto P_0c09010a;
case 0x0c09010cu: goto P_0c09010c;
case 0x0c09010eu: goto P_0c09010e;
case 0x0c090110u: goto P_0c090110;
case 0x0c090112u: goto P_0c090112;
case 0x0c090114u: goto P_0c090114;
case 0x0c090116u: goto P_0c090116;
case 0x0c090118u: goto P_0c090118;
case 0x0c09011au: goto P_0c09011a;
case 0x0c09011cu: goto P_0c09011c;
case 0x0c09011eu: goto P_0c09011e;
case 0x0c090120u: goto P_0c090120;
case 0x0c090122u: goto P_0c090122;
case 0x0c090124u: goto P_0c090124;
case 0x0c090126u: goto P_0c090126;
case 0x0c090128u: goto P_0c090128;
case 0x0c09012au: goto P_0c09012a;
case 0x0c09012cu: goto P_0c09012c;
case 0x0c09012eu: goto P_0c09012e;
case 0x0c090130u: goto P_0c090130;
case 0x0c090132u: goto P_0c090132;
case 0x0c090134u: goto P_0c090134;
case 0x0c090136u: goto P_0c090136;
case 0x0c090138u: goto P_0c090138;
case 0x0c09013au: goto P_0c09013a;
case 0x0c09013cu: goto P_0c09013c;
case 0x0c09013eu: goto P_0c09013e;
case 0x0c090140u: goto P_0c090140;
case 0x0c090142u: goto P_0c090142;
case 0x0c090144u: goto P_0c090144;
case 0x0c090146u: goto P_0c090146;
case 0x0c090148u: goto P_0c090148;
case 0x0c09014au: goto P_0c09014a;
case 0x0c09014cu: goto P_0c09014c;
case 0x0c09014eu: goto P_0c09014e;
case 0x0c090150u: goto P_0c090150;
case 0x0c090152u: goto P_0c090152;
case 0x0c090154u: goto P_0c090154;
case 0x0c090156u: goto P_0c090156;
case 0x0c090158u: goto P_0c090158;
case 0x0c09015au: goto P_0c09015a;
case 0x0c09015cu: goto P_0c09015c;
case 0x0c09015eu: goto P_0c09015e;
case 0x0c090160u: goto P_0c090160;
case 0x0c090162u: goto P_0c090162;
case 0x0c090164u: goto P_0c090164;
case 0x0c090166u: goto P_0c090166;
case 0x0c090168u: goto P_0c090168;
case 0x0c09016au: goto P_0c09016a;
case 0x0c09016cu: goto P_0c09016c;
case 0x0c09016eu: goto P_0c09016e;
case 0x0c090170u: goto P_0c090170;
case 0x0c090172u: goto P_0c090172;
case 0x0c090174u: goto P_0c090174;
case 0x0c090176u: goto P_0c090176;
case 0x0c090178u: goto P_0c090178;
case 0x0c09017au: goto P_0c09017a;
case 0x0c09017cu: goto P_0c09017c;
case 0x0c09017eu: goto P_0c09017e;
case 0x0c090180u: goto P_0c090180;
case 0x0c090182u: goto P_0c090182;
case 0x0c090184u: goto P_0c090184;
case 0x0c090186u: goto P_0c090186;
case 0x0c090188u: goto P_0c090188;
case 0x0c09018au: goto P_0c09018a;
case 0x0c09018cu: goto P_0c09018c;
case 0x0c09018eu: goto P_0c09018e;
case 0x0c090190u: goto P_0c090190;
case 0x0c090192u: goto P_0c090192;
case 0x0c090194u: goto P_0c090194;
case 0x0c090196u: goto P_0c090196;
case 0x0c090198u: goto P_0c090198;
case 0x0c0901a4u: goto P_0c0901a4;
case 0x0c0901a6u: goto P_0c0901a6;
case 0x0c0901a8u: goto P_0c0901a8;
case 0x0c0901aau: goto P_0c0901aa;
case 0x0c0901acu: goto P_0c0901ac;
case 0x0c0901aeu: goto P_0c0901ae;
case 0x0c0901b0u: goto P_0c0901b0;
case 0x0c0901b2u: goto P_0c0901b2;
case 0x0c0901b4u: goto P_0c0901b4;
case 0x0c0901b6u: goto P_0c0901b6;
case 0x0c0901b8u: goto P_0c0901b8;
case 0x0c0901bau: goto P_0c0901ba;
case 0x0c0901bcu: goto P_0c0901bc;
case 0x0c0901beu: goto P_0c0901be;
case 0x0c0901c0u: goto P_0c0901c0;
case 0x0c0901c2u: goto P_0c0901c2;
case 0x0c0901c4u: goto P_0c0901c4;
case 0x0c0901c6u: goto P_0c0901c6;
case 0x0c0901c8u: goto P_0c0901c8;
case 0x0c0901cau: goto P_0c0901ca;
case 0x0c0901ccu: goto P_0c0901cc;
case 0x0c0901ceu: goto P_0c0901ce;
case 0x0c0901d0u: goto P_0c0901d0;
case 0x0c0901d2u: goto P_0c0901d2;
case 0x0c0901d4u: goto P_0c0901d4;
case 0x0c0901d6u: goto P_0c0901d6;
case 0x0c0901d8u: goto P_0c0901d8;
case 0x0c0901dau: goto P_0c0901da;
case 0x0c0901dcu: goto P_0c0901dc;
case 0x0c0901deu: goto P_0c0901de;
case 0x0c0901e0u: goto P_0c0901e0;
case 0x0c0901e2u: goto P_0c0901e2;
case 0x0c0901e4u: goto P_0c0901e4;
case 0x0c0901e6u: goto P_0c0901e6;
case 0x0c0901e8u: goto P_0c0901e8;
case 0x0c0901eau: goto P_0c0901ea;
case 0x0c0901ecu: goto P_0c0901ec;
case 0x0c0901eeu: goto P_0c0901ee;
case 0x0c0901f0u: goto P_0c0901f0;
case 0x0c0901f2u: goto P_0c0901f2;
case 0x0c0901f4u: goto P_0c0901f4;
case 0x0c0901f6u: goto P_0c0901f6;
case 0x0c0901f8u: goto P_0c0901f8;
case 0x0c0901fau: goto P_0c0901fa;
case 0x0c0901fcu: goto P_0c0901fc;
case 0x0c0901feu: goto P_0c0901fe;
case 0x0c090200u: goto P_0c090200;
case 0x0c090202u: goto P_0c090202;
case 0x0c090204u: goto P_0c090204;
case 0x0c090206u: goto P_0c090206;
case 0x0c090208u: goto P_0c090208;
case 0x0c09020au: goto P_0c09020a;
case 0x0c09020cu: goto P_0c09020c;
case 0x0c09020eu: goto P_0c09020e;
case 0x0c090210u: goto P_0c090210;
case 0x0c090212u: goto P_0c090212;
case 0x0c090214u: goto P_0c090214;
case 0x0c090216u: goto P_0c090216;
case 0x0c090218u: goto P_0c090218;
case 0x0c09021au: goto P_0c09021a;
case 0x0c09021cu: goto P_0c09021c;
case 0x0c09021eu: goto P_0c09021e;
case 0x0c090220u: goto P_0c090220;
case 0x0c090222u: goto P_0c090222;
case 0x0c090224u: goto P_0c090224;
case 0x0c090226u: goto P_0c090226;
case 0x0c090228u: goto P_0c090228;
case 0x0c09022au: goto P_0c09022a;
case 0x0c09022cu: goto P_0c09022c;
case 0x0c09022eu: goto P_0c09022e;
case 0x0c090230u: goto P_0c090230;
case 0x0c090232u: goto P_0c090232;
case 0x0c090234u: goto P_0c090234;
case 0x0c090236u: goto P_0c090236;
case 0x0c090238u: goto P_0c090238;
case 0x0c09023au: goto P_0c09023a;
case 0x0c09023cu: goto P_0c09023c;
case 0x0c09023eu: goto P_0c09023e;
case 0x0c090240u: goto P_0c090240;
case 0x0c090242u: goto P_0c090242;
case 0x0c090244u: goto P_0c090244;
case 0x0c090246u: goto P_0c090246;
case 0x0c090248u: goto P_0c090248;
case 0x0c09024au: goto P_0c09024a;
case 0x0c09024cu: goto P_0c09024c;
case 0x0c09024eu: goto P_0c09024e;
case 0x0c090250u: goto P_0c090250;
case 0x0c090252u: goto P_0c090252;
case 0x0c090254u: goto P_0c090254;
case 0x0c090256u: goto P_0c090256;
case 0x0c090258u: goto P_0c090258;
case 0x0c09025au: goto P_0c09025a;
case 0x0c09025cu: goto P_0c09025c;
case 0x0c09025eu: goto P_0c09025e;
case 0x0c090260u: goto P_0c090260;
case 0x0c090262u: goto P_0c090262;
case 0x0c090264u: goto P_0c090264;
case 0x0c090266u: goto P_0c090266;
case 0x0c090268u: goto P_0c090268;
case 0x0c09026au: goto P_0c09026a;
case 0x0c09026cu: goto P_0c09026c;
case 0x0c09026eu: goto P_0c09026e;
case 0x0c090270u: goto P_0c090270;
case 0x0c090272u: goto P_0c090272;
case 0x0c090274u: goto P_0c090274;
case 0x0c090276u: goto P_0c090276;
case 0x0c090278u: goto P_0c090278;
case 0x0c09027au: goto P_0c09027a;
case 0x0c09027cu: goto P_0c09027c;
case 0x0c09027eu: goto P_0c09027e;
case 0x0c090280u: goto P_0c090280;
case 0x0c090282u: goto P_0c090282;
case 0x0c090284u: goto P_0c090284;
case 0x0c090286u: goto P_0c090286;
case 0x0c090288u: goto P_0c090288;
case 0x0c09028au: goto P_0c09028a;
case 0x0c09028cu: goto P_0c09028c;
case 0x0c09028eu: goto P_0c09028e;
case 0x0c090290u: goto P_0c090290;
case 0x0c090292u: goto P_0c090292;
case 0x0c090294u: goto P_0c090294;
case 0x0c090296u: goto P_0c090296;
case 0x0c090298u: goto P_0c090298;
case 0x0c09029au: goto P_0c09029a;
case 0x0c09029cu: goto P_0c09029c;
case 0x0c09029eu: goto P_0c09029e;
case 0x0c0902a0u: goto P_0c0902a0;
case 0x0c0902a2u: goto P_0c0902a2;
case 0x0c0902a4u: goto P_0c0902a4;
case 0x0c0902a6u: goto P_0c0902a6;
case 0x0c0902a8u: goto P_0c0902a8;
case 0x0c0902aau: goto P_0c0902aa;
case 0x0c0902acu: goto P_0c0902ac;
case 0x0c0902aeu: goto P_0c0902ae;
case 0x0c0902b0u: goto P_0c0902b0;
case 0x0c0902b2u: goto P_0c0902b2;
case 0x0c0902b4u: goto P_0c0902b4;
case 0x0c0902b6u: goto P_0c0902b6;
case 0x0c0902b8u: goto P_0c0902b8;
case 0x0c0902bau: goto P_0c0902ba;
case 0x0c0902bcu: goto P_0c0902bc;
case 0x0c0902beu: goto P_0c0902be;
case 0x0c0902c0u: goto P_0c0902c0;
case 0x0c0902c2u: goto P_0c0902c2;
case 0x0c0902c4u: goto P_0c0902c4;
case 0x0c0902c6u: goto P_0c0902c6;
case 0x0c0902c8u: goto P_0c0902c8;
case 0x0c0902cau: goto P_0c0902ca;
case 0x0c0902ccu: goto P_0c0902cc;
case 0x0c0902ceu: goto P_0c0902ce;
case 0x0c0902d0u: goto P_0c0902d0;
case 0x0c0902d2u: goto P_0c0902d2;
case 0x0c0902d4u: goto P_0c0902d4;
case 0x0c0902d6u: goto P_0c0902d6;
case 0x0c0902d8u: goto P_0c0902d8;
case 0x0c0902dau: goto P_0c0902da;
case 0x0c0902dcu: goto P_0c0902dc;
case 0x0c0902deu: goto P_0c0902de;
case 0x0c0902fcu: goto P_0c0902fc;
case 0x0c0902feu: goto P_0c0902fe;
case 0x0c090300u: goto P_0c090300;
case 0x0c090302u: goto P_0c090302;
case 0x0c090304u: goto P_0c090304;
case 0x0c090306u: goto P_0c090306;
case 0x0c090308u: goto P_0c090308;
case 0x0c09030au: goto P_0c09030a;
case 0x0c09030cu: goto P_0c09030c;
case 0x0c09030eu: goto P_0c09030e;
case 0x0c090310u: goto P_0c090310;
case 0x0c090312u: goto P_0c090312;
case 0x0c090314u: goto P_0c090314;
case 0x0c090316u: goto P_0c090316;
case 0x0c090318u: goto P_0c090318;
case 0x0c09031au: goto P_0c09031a;
case 0x0c09031cu: goto P_0c09031c;
case 0x0c09031eu: goto P_0c09031e;
case 0x0c090320u: goto P_0c090320;
case 0x0c090322u: goto P_0c090322;
case 0x0c090324u: goto P_0c090324;
case 0x0c090326u: goto P_0c090326;
case 0x0c090328u: goto P_0c090328;
case 0x0c09032au: goto P_0c09032a;
case 0x0c09032cu: goto P_0c09032c;
case 0x0c09032eu: goto P_0c09032e;
case 0x0c090330u: goto P_0c090330;
case 0x0c090332u: goto P_0c090332;
case 0x0c090334u: goto P_0c090334;
case 0x0c090336u: goto P_0c090336;
case 0x0c090338u: goto P_0c090338;
case 0x0c09033au: goto P_0c09033a;
case 0x0c09033cu: goto P_0c09033c;
case 0x0c09033eu: goto P_0c09033e;
case 0x0c090340u: goto P_0c090340;
case 0x0c090342u: goto P_0c090342;
case 0x0c090344u: goto P_0c090344;
case 0x0c090346u: goto P_0c090346;
case 0x0c090348u: goto P_0c090348;
case 0x0c09034au: goto P_0c09034a;
case 0x0c09034cu: goto P_0c09034c;
case 0x0c09034eu: goto P_0c09034e;
case 0x0c090350u: goto P_0c090350;
case 0x0c090352u: goto P_0c090352;
case 0x0c090354u: goto P_0c090354;
case 0x0c090356u: goto P_0c090356;
case 0x0c090358u: goto P_0c090358;
case 0x0c09035au: goto P_0c09035a;
case 0x0c09035cu: goto P_0c09035c;
case 0x0c09035eu: goto P_0c09035e;
case 0x0c090360u: goto P_0c090360;
case 0x0c090362u: goto P_0c090362;
case 0x0c090364u: goto P_0c090364;
case 0x0c090366u: goto P_0c090366;
case 0x0c090368u: goto P_0c090368;
case 0x0c09036au: goto P_0c09036a;
case 0x0c09036cu: goto P_0c09036c;
case 0x0c09036eu: goto P_0c09036e;
case 0x0c090370u: goto P_0c090370;
case 0x0c090372u: goto P_0c090372;
case 0x0c090374u: goto P_0c090374;
case 0x0c090376u: goto P_0c090376;
case 0x0c090378u: goto P_0c090378;
case 0x0c09037au: goto P_0c09037a;
case 0x0c09037cu: goto P_0c09037c;
case 0x0c09037eu: goto P_0c09037e;
case 0x0c090380u: goto P_0c090380;
case 0x0c090382u: goto P_0c090382;
case 0x0c090384u: goto P_0c090384;
case 0x0c090386u: goto P_0c090386;
case 0x0c090388u: goto P_0c090388;
case 0x0c09038au: goto P_0c09038a;
case 0x0c09038cu: goto P_0c09038c;
case 0x0c09038eu: goto P_0c09038e;
case 0x0c090390u: goto P_0c090390;
case 0x0c090392u: goto P_0c090392;
case 0x0c090394u: goto P_0c090394;
case 0x0c090396u: goto P_0c090396;
case 0x0c090398u: goto P_0c090398;
case 0x0c09039au: goto P_0c09039a;
case 0x0c09039cu: goto P_0c09039c;
case 0x0c09039eu: goto P_0c09039e;
case 0x0c0903a0u: goto P_0c0903a0;
case 0x0c0903a2u: goto P_0c0903a2;
case 0x0c0903a4u: goto P_0c0903a4;
case 0x0c0903a6u: goto P_0c0903a6;
case 0x0c0903a8u: goto P_0c0903a8;
case 0x0c0903aau: goto P_0c0903aa;
case 0x0c0903acu: goto P_0c0903ac;
case 0x0c0903aeu: goto P_0c0903ae;
case 0x0c0903b0u: goto P_0c0903b0;
case 0x0c0903b2u: goto P_0c0903b2;
case 0x0c0903b4u: goto P_0c0903b4;
case 0x0c0903b6u: goto P_0c0903b6;
case 0x0c0903b8u: goto P_0c0903b8;
case 0x0c0903bau: goto P_0c0903ba;
case 0x0c0903bcu: goto P_0c0903bc;
case 0x0c0903beu: goto P_0c0903be;
case 0x0c0903c0u: goto P_0c0903c0;
case 0x0c0903c2u: goto P_0c0903c2;
case 0x0c0903c4u: goto P_0c0903c4;
case 0x0c0903c6u: goto P_0c0903c6;
case 0x0c0903c8u: goto P_0c0903c8;
case 0x0c0903cau: goto P_0c0903ca;
case 0x0c0903ccu: goto P_0c0903cc;
case 0x0c0903ceu: goto P_0c0903ce;
case 0x0c0903d0u: goto P_0c0903d0;
case 0x0c0903d2u: goto P_0c0903d2;
case 0x0c0903d4u: goto P_0c0903d4;
case 0x0c0903d6u: goto P_0c0903d6;
case 0x0c0903d8u: goto P_0c0903d8;
case 0x0c0903dau: goto P_0c0903da;
case 0x0c0903dcu: goto P_0c0903dc;
case 0x0c0903deu: goto P_0c0903de;
case 0x0c0903e0u: goto P_0c0903e0;
case 0x0c0903e2u: goto P_0c0903e2;
case 0x0c0903e4u: goto P_0c0903e4;
case 0x0c0903e6u: goto P_0c0903e6;
case 0x0c0903e8u: goto P_0c0903e8;
case 0x0c0903eau: goto P_0c0903ea;
case 0x0c0903ecu: goto P_0c0903ec;
case 0x0c0903eeu: goto P_0c0903ee;
case 0x0c0903f0u: goto P_0c0903f0;
case 0x0c0903f2u: goto P_0c0903f2;
case 0x0c0903f4u: goto P_0c0903f4;
case 0x0c0903f6u: goto P_0c0903f6;
case 0x0c0903f8u: goto P_0c0903f8;
case 0x0c0903fau: goto P_0c0903fa;
case 0x0c0903fcu: goto P_0c0903fc;
case 0x0c0903feu: goto P_0c0903fe;
case 0x0c090400u: goto P_0c090400;
case 0x0c090402u: goto P_0c090402;
case 0x0c090404u: goto P_0c090404;
case 0x0c090406u: goto P_0c090406;
case 0x0c090408u: goto P_0c090408;
case 0x0c09040au: goto P_0c09040a;
case 0x0c09040cu: goto P_0c09040c;
case 0x0c09040eu: goto P_0c09040e;
case 0x0c090410u: goto P_0c090410;
case 0x0c090412u: goto P_0c090412;
case 0x0c090414u: goto P_0c090414;
case 0x0c090416u: goto P_0c090416;
case 0x0c090418u: goto P_0c090418;
case 0x0c09041au: goto P_0c09041a;
case 0x0c09041cu: goto P_0c09041c;
case 0x0c09041eu: goto P_0c09041e;
case 0x0c090420u: goto P_0c090420;
case 0x0c090422u: goto P_0c090422;
case 0x0c090424u: goto P_0c090424;
case 0x0c090426u: goto P_0c090426;
case 0x0c090428u: goto P_0c090428;
case 0x0c09042au: goto P_0c09042a;
case 0x0c090450u: goto P_0c090450;
case 0x0c090452u: goto P_0c090452;
case 0x0c090454u: goto P_0c090454;
case 0x0c090456u: goto P_0c090456;
case 0x0c090458u: goto P_0c090458;
case 0x0c09045au: goto P_0c09045a;
case 0x0c09045cu: goto P_0c09045c;
case 0x0c09045eu: goto P_0c09045e;
case 0x0c090460u: goto P_0c090460;
case 0x0c090462u: goto P_0c090462;
case 0x0c090464u: goto P_0c090464;
case 0x0c090466u: goto P_0c090466;
case 0x0c090468u: goto P_0c090468;
case 0x0c09046au: goto P_0c09046a;
case 0x0c09046cu: goto P_0c09046c;
case 0x0c09046eu: goto P_0c09046e;
case 0x0c090470u: goto P_0c090470;
case 0x0c090472u: goto P_0c090472;
case 0x0c090474u: goto P_0c090474;
case 0x0c090476u: goto P_0c090476;
case 0x0c090478u: goto P_0c090478;
case 0x0c09047au: goto P_0c09047a;
case 0x0c09047cu: goto P_0c09047c;
case 0x0c09047eu: goto P_0c09047e;
case 0x0c090480u: goto P_0c090480;
case 0x0c090482u: goto P_0c090482;
case 0x0c090484u: goto P_0c090484;
case 0x0c090486u: goto P_0c090486;
case 0x0c090488u: goto P_0c090488;
case 0x0c09048au: goto P_0c09048a;
case 0x0c09048cu: goto P_0c09048c;
case 0x0c09048eu: goto P_0c09048e;
case 0x0c090490u: goto P_0c090490;
case 0x0c090492u: goto P_0c090492;
case 0x0c090494u: goto P_0c090494;
case 0x0c090496u: goto P_0c090496;
case 0x0c090498u: goto P_0c090498;
case 0x0c09049au: goto P_0c09049a;
case 0x0c09049cu: goto P_0c09049c;
case 0x0c09049eu: goto P_0c09049e;
case 0x0c0904a0u: goto P_0c0904a0;
case 0x0c0904a2u: goto P_0c0904a2;
case 0x0c0904a4u: goto P_0c0904a4;
case 0x0c0904a6u: goto P_0c0904a6;
case 0x0c0904a8u: goto P_0c0904a8;
case 0x0c0904aau: goto P_0c0904aa;
case 0x0c0904acu: goto P_0c0904ac;
case 0x0c0904aeu: goto P_0c0904ae;
case 0x0c0904b0u: goto P_0c0904b0;
case 0x0c0904b2u: goto P_0c0904b2;
case 0x0c0904bcu: goto P_0c0904bc;
case 0x0c0904beu: goto P_0c0904be;
case 0x0c0904c0u: goto P_0c0904c0;
case 0x0c0904c2u: goto P_0c0904c2;
case 0x0c0904c4u: goto P_0c0904c4;
case 0x0c0904c6u: goto P_0c0904c6;
case 0x0c0904c8u: goto P_0c0904c8;
case 0x0c0904cau: goto P_0c0904ca;
case 0x0c0904ccu: goto P_0c0904cc;
case 0x0c0904ceu: goto P_0c0904ce;
case 0x0c0904d0u: goto P_0c0904d0;
case 0x0c0904d2u: goto P_0c0904d2;
case 0x0c0904d4u: goto P_0c0904d4;
case 0x0c0904d6u: goto P_0c0904d6;
case 0x0c0904d8u: goto P_0c0904d8;
case 0x0c0904dau: goto P_0c0904da;
case 0x0c0904dcu: goto P_0c0904dc;
case 0x0c0904deu: goto P_0c0904de;
case 0x0c0904e0u: goto P_0c0904e0;
case 0x0c0904e2u: goto P_0c0904e2;
case 0x0c0904e4u: goto P_0c0904e4;
case 0x0c0904e6u: goto P_0c0904e6;
case 0x0c0904e8u: goto P_0c0904e8;
case 0x0c0904eau: goto P_0c0904ea;
case 0x0c0904ecu: goto P_0c0904ec;
case 0x0c0904eeu: goto P_0c0904ee;
case 0x0c0904f0u: goto P_0c0904f0;
case 0x0c0904f2u: goto P_0c0904f2;
case 0x0c0904f4u: goto P_0c0904f4;
case 0x0c0904f6u: goto P_0c0904f6;
case 0x0c0904f8u: goto P_0c0904f8;
case 0x0c0904fau: goto P_0c0904fa;
case 0x0c0904fcu: goto P_0c0904fc;
case 0x0c0904feu: goto P_0c0904fe;
case 0x0c090500u: goto P_0c090500;
case 0x0c090502u: goto P_0c090502;
case 0x0c090504u: goto P_0c090504;
case 0x0c090506u: goto P_0c090506;
case 0x0c090508u: goto P_0c090508;
case 0x0c09050au: goto P_0c09050a;
case 0x0c09050cu: goto P_0c09050c;
case 0x0c09050eu: goto P_0c09050e;
case 0x0c090510u: goto P_0c090510;
case 0x0c090512u: goto P_0c090512;
case 0x0c090514u: goto P_0c090514;
case 0x0c090516u: goto P_0c090516;
case 0x0c090518u: goto P_0c090518;
case 0x0c09051au: goto P_0c09051a;
case 0x0c09051cu: goto P_0c09051c;
case 0x0c09051eu: goto P_0c09051e;
case 0x0c090520u: goto P_0c090520;
case 0x0c090522u: goto P_0c090522;
case 0x0c090524u: goto P_0c090524;
case 0x0c090526u: goto P_0c090526;
case 0x0c090528u: goto P_0c090528;
case 0x0c09052au: goto P_0c09052a;
case 0x0c09052cu: goto P_0c09052c;
case 0x0c09052eu: goto P_0c09052e;
case 0x0c090530u: goto P_0c090530;
case 0x0c090532u: goto P_0c090532;
case 0x0c090534u: goto P_0c090534;
case 0x0c090536u: goto P_0c090536;
case 0x0c090538u: goto P_0c090538;
case 0x0c09053au: goto P_0c09053a;
case 0x0c09053cu: goto P_0c09053c;
case 0x0c09053eu: goto P_0c09053e;
case 0x0c090540u: goto P_0c090540;
case 0x0c090542u: goto P_0c090542;
case 0x0c090544u: goto P_0c090544;
case 0x0c090546u: goto P_0c090546;
case 0x0c090548u: goto P_0c090548;
case 0x0c09054au: goto P_0c09054a;
case 0x0c09054cu: goto P_0c09054c;
case 0x0c09054eu: goto P_0c09054e;
case 0x0c090550u: goto P_0c090550;
case 0x0c090552u: goto P_0c090552;
case 0x0c090554u: goto P_0c090554;
case 0x0c090556u: goto P_0c090556;
case 0x0c090558u: goto P_0c090558;
case 0x0c09055au: goto P_0c09055a;
case 0x0c09055cu: goto P_0c09055c;
case 0x0c09055eu: goto P_0c09055e;
case 0x0c090560u: goto P_0c090560;
case 0x0c090562u: goto P_0c090562;
case 0x0c090564u: goto P_0c090564;
case 0x0c090566u: goto P_0c090566;
case 0x0c090568u: goto P_0c090568;
case 0x0c09056au: goto P_0c09056a;
case 0x0c09056cu: goto P_0c09056c;
case 0x0c09056eu: goto P_0c09056e;
case 0x0c090570u: goto P_0c090570;
case 0x0c090572u: goto P_0c090572;
case 0x0c090574u: goto P_0c090574;
case 0x0c090576u: goto P_0c090576;
case 0x0c090578u: goto P_0c090578;
case 0x0c09057au: goto P_0c09057a;
case 0x0c09057cu: goto P_0c09057c;
case 0x0c09057eu: goto P_0c09057e;
case 0x0c090580u: goto P_0c090580;
case 0x0c090582u: goto P_0c090582;
case 0x0c090584u: goto P_0c090584;
case 0x0c090586u: goto P_0c090586;
case 0x0c090588u: goto P_0c090588;
case 0x0c09058au: goto P_0c09058a;
case 0x0c09058cu: goto P_0c09058c;
case 0x0c09058eu: goto P_0c09058e;
case 0x0c090590u: goto P_0c090590;
case 0x0c090592u: goto P_0c090592;
case 0x0c090594u: goto P_0c090594;
case 0x0c090596u: goto P_0c090596;
case 0x0c090598u: goto P_0c090598;
case 0x0c09059au: goto P_0c09059a;
case 0x0c09059cu: goto P_0c09059c;
case 0x0c09059eu: goto P_0c09059e;
case 0x0c0905a0u: goto P_0c0905a0;
case 0x0c0905a2u: goto P_0c0905a2;
case 0x0c0905a4u: goto P_0c0905a4;
case 0x0c0905a6u: goto P_0c0905a6;
case 0x0c0905a8u: goto P_0c0905a8;
case 0x0c0905aau: goto P_0c0905aa;
case 0x0c0905acu: goto P_0c0905ac;
case 0x0c0905aeu: goto P_0c0905ae;
case 0x0c0905b0u: goto P_0c0905b0;
case 0x0c0905b2u: goto P_0c0905b2;
case 0x0c0905b4u: goto P_0c0905b4;
case 0x0c0905b6u: goto P_0c0905b6;
case 0x0c0905b8u: goto P_0c0905b8;
case 0x0c0905bau: goto P_0c0905ba;
case 0x0c0905bcu: goto P_0c0905bc;
case 0x0c0905beu: goto P_0c0905be;
case 0x0c0905c0u: goto P_0c0905c0;
case 0x0c0905c2u: goto P_0c0905c2;
case 0x0c0905c4u: goto P_0c0905c4;
case 0x0c0905c6u: goto P_0c0905c6;
case 0x0c0905c8u: goto P_0c0905c8;
case 0x0c0905cau: goto P_0c0905ca;
case 0x0c0905ccu: goto P_0c0905cc;
case 0x0c0905ceu: goto P_0c0905ce;
case 0x0c0905d0u: goto P_0c0905d0;
case 0x0c0905d2u: goto P_0c0905d2;
case 0x0c0905d4u: goto P_0c0905d4;
case 0x0c0905d6u: goto P_0c0905d6;
case 0x0c0905d8u: goto P_0c0905d8;
case 0x0c0905dau: goto P_0c0905da;
case 0x0c0905dcu: goto P_0c0905dc;
case 0x0c0905deu: goto P_0c0905de;
case 0x0c0905e0u: goto P_0c0905e0;
case 0x0c0905e2u: goto P_0c0905e2;
case 0x0c0905e4u: goto P_0c0905e4;
case 0x0c0905e6u: goto P_0c0905e6;
case 0x0c0905e8u: goto P_0c0905e8;
case 0x0c0905eau: goto P_0c0905ea;
case 0x0c0905ecu: goto P_0c0905ec;
case 0x0c0905eeu: goto P_0c0905ee;
case 0x0c0905f0u: goto P_0c0905f0;
case 0x0c0905f2u: goto P_0c0905f2;
case 0x0c0905f4u: goto P_0c0905f4;
case 0x0c0905f6u: goto P_0c0905f6;
case 0x0c0905f8u: goto P_0c0905f8;
case 0x0c0905fau: goto P_0c0905fa;
case 0x0c0905fcu: goto P_0c0905fc;
case 0x0c0905feu: goto P_0c0905fe;
case 0x0c090600u: goto P_0c090600;
case 0x0c09061cu: goto P_0c09061c;
case 0x0c09061eu: goto P_0c09061e;
case 0x0c090620u: goto P_0c090620;
case 0x0c090622u: goto P_0c090622;
case 0x0c090624u: goto P_0c090624;
case 0x0c090626u: goto P_0c090626;
case 0x0c090628u: goto P_0c090628;
case 0x0c09062au: goto P_0c09062a;
case 0x0c09062cu: goto P_0c09062c;
case 0x0c09062eu: goto P_0c09062e;
case 0x0c090630u: goto P_0c090630;
case 0x0c090632u: goto P_0c090632;
case 0x0c090634u: goto P_0c090634;
case 0x0c090636u: goto P_0c090636;
case 0x0c090638u: goto P_0c090638;
case 0x0c09063au: goto P_0c09063a;
case 0x0c09063cu: goto P_0c09063c;
case 0x0c09063eu: goto P_0c09063e;
case 0x0c090640u: goto P_0c090640;
case 0x0c090642u: goto P_0c090642;
case 0x0c090644u: goto P_0c090644;
case 0x0c090646u: goto P_0c090646;
case 0x0c090648u: goto P_0c090648;
case 0x0c09064au: goto P_0c09064a;
case 0x0c09064cu: goto P_0c09064c;
case 0x0c09064eu: goto P_0c09064e;
case 0x0c090650u: goto P_0c090650;
case 0x0c090652u: goto P_0c090652;
case 0x0c090654u: goto P_0c090654;
case 0x0c090656u: goto P_0c090656;
case 0x0c090658u: goto P_0c090658;
case 0x0c09065au: goto P_0c09065a;
case 0x0c09065cu: goto P_0c09065c;
case 0x0c09065eu: goto P_0c09065e;
case 0x0c090660u: goto P_0c090660;
case 0x0c090662u: goto P_0c090662;
case 0x0c090664u: goto P_0c090664;
case 0x0c090666u: goto P_0c090666;
case 0x0c090668u: goto P_0c090668;
case 0x0c09066au: goto P_0c09066a;
case 0x0c09066cu: goto P_0c09066c;
case 0x0c09066eu: goto P_0c09066e;
case 0x0c090670u: goto P_0c090670;
case 0x0c090672u: goto P_0c090672;
case 0x0c090674u: goto P_0c090674;
case 0x0c090676u: goto P_0c090676;
case 0x0c090678u: goto P_0c090678;
case 0x0c09067au: goto P_0c09067a;
case 0x0c09067cu: goto P_0c09067c;
case 0x0c09067eu: goto P_0c09067e;
case 0x0c090680u: goto P_0c090680;
case 0x0c090682u: goto P_0c090682;
case 0x0c090684u: goto P_0c090684;
case 0x0c090686u: goto P_0c090686;
case 0x0c090688u: goto P_0c090688;
case 0x0c09068au: goto P_0c09068a;
case 0x0c09068cu: goto P_0c09068c;
case 0x0c09068eu: goto P_0c09068e;
case 0x0c090690u: goto P_0c090690;
case 0x0c090692u: goto P_0c090692;
case 0x0c090694u: goto P_0c090694;
case 0x0c090696u: goto P_0c090696;
case 0x0c090698u: goto P_0c090698;
case 0x0c09069au: goto P_0c09069a;
case 0x0c09069cu: goto P_0c09069c;
case 0x0c09069eu: goto P_0c09069e;
case 0x0c0906a0u: goto P_0c0906a0;
case 0x0c0906a2u: goto P_0c0906a2;
case 0x0c0906a4u: goto P_0c0906a4;
case 0x0c0906a6u: goto P_0c0906a6;
case 0x0c0906a8u: goto P_0c0906a8;
case 0x0c0906aau: goto P_0c0906aa;
case 0x0c0906acu: goto P_0c0906ac;
case 0x0c0906aeu: goto P_0c0906ae;
case 0x0c0906b0u: goto P_0c0906b0;
case 0x0c0906b2u: goto P_0c0906b2;
case 0x0c0906b4u: goto P_0c0906b4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c090000: /* original 4f22, guest PC 0x0c090000 */
if(!s->budget--) { s->failed_pc=0x0c090000u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c090002;
P_0c090002: /* original 2459, guest PC 0x0c090002 */
if(!s->budget--) { s->failed_pc=0x0c090002u; return 0; }
r[4]&=r[5];
goto P_0c090004;
P_0c090004: /* original f3e6, guest PC 0x0c090004 */
if(!s->budget--) { s->failed_pc=0x0c090004u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090006;
P_0c090006: /* original 55ef, guest PC 0x0c090006 */
if(!s->budget--) { s->failed_pc=0x0c090006u; return 0; }
r[5]=read(ram,r[14]+60,4);
goto P_0c090008;
P_0c090008: /* original e050, guest PC 0x0c090008 */
if(!s->budget--) { s->failed_pc=0x0c090008u; return 0; }
r[0]=0x00000050u;
goto P_0c09000a;
P_0c09000a: /* original 7fa8, guest PC 0x0c09000a */
if(!s->budget--) { s->failed_pc=0x0c09000au; return 0; }
r[15]+=0xffffffa8u;
goto P_0c09000c;
P_0c09000c: /* original ff37, guest PC 0x0c09000c */
if(!s->budget--) { s->failed_pc=0x0c09000cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09000e;
P_0c09000e: /* original 256b, guest PC 0x0c09000e */
if(!s->budget--) { s->failed_pc=0x0c09000eu; return 0; }
r[5]|=r[6];
goto P_0c090010;
P_0c090010: /* original 9064, guest PC 0x0c090010 */
if(!s->budget--) { s->failed_pc=0x0c090010u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0900dcu,2);
goto P_0c090012;
P_0c090012: /* original ea04, guest PC 0x0c090012 */
if(!s->budget--) { s->failed_pc=0x0c090012u; return 0; }
r[10]=0x00000004u;
goto P_0c090014;
P_0c090014: /* original 2a49, guest PC 0x0c090014 */
if(!s->budget--) { s->failed_pc=0x0c090014u; return 0; }
r[10]&=r[4];
goto P_0c090016;
P_0c090016: /* original fce6, guest PC 0x0c090016 */
if(!s->budget--) { s->failed_pc=0x0c090016u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c090018;
P_0c090018: /* original 7040, guest PC 0x0c090018 */
if(!s->budget--) { s->failed_pc=0x0c090018u; return 0; }
r[0]+=0x00000040u;
goto P_0c09001a;
P_0c09001a: /* original f3e6, guest PC 0x0c09001a */
if(!s->budget--) { s->failed_pc=0x0c09001au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09001c;
P_0c09001c: /* original e01c, guest PC 0x0c09001c */
if(!s->budget--) { s->failed_pc=0x0c09001cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09001e;
P_0c09001e: /* original 2aa8, guest PC 0x0c09001e */
if(!s->budget--) { s->failed_pc=0x0c09001eu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c090020;
P_0c090020: /* original ff37, guest PC 0x0c090020 */
if(!s->budget--) { s->failed_pc=0x0c090020u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090022;
P_0c090022: /* original 905c, guest PC 0x0c090022 */
if(!s->budget--) { s->failed_pc=0x0c090022u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0900deu,2);
goto P_0c090024;
P_0c090024: /* original f3e6, guest PC 0x0c090024 */
if(!s->budget--) { s->failed_pc=0x0c090024u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090026;
P_0c090026: /* original e054, guest PC 0x0c090026 */
if(!s->budget--) { s->failed_pc=0x0c090026u; return 0; }
r[0]=0x00000054u;
goto P_0c090028;
P_0c090028: /* original ff37, guest PC 0x0c090028 */
if(!s->budget--) { s->failed_pc=0x0c090028u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09002a;
P_0c09002a: /* original 9059, guest PC 0x0c09002a */
if(!s->budget--) { s->failed_pc=0x0c09002au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0900e0u,2);
goto P_0c09002c;
P_0c09002c: /* original f3e6, guest PC 0x0c09002c */
if(!s->budget--) { s->failed_pc=0x0c09002cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09002e;
P_0c09002e: /* original e020, guest PC 0x0c09002e */
if(!s->budget--) { s->failed_pc=0x0c09002eu; return 0; }
r[0]=0x00000020u;
goto P_0c090030;
P_0c090030: /* original ff37, guest PC 0x0c090030 */
if(!s->budget--) { s->failed_pc=0x0c090030u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090032;
P_0c090032: /* original dc2e, guest PC 0x0c090032 */
if(!s->budget--) { s->failed_pc=0x0c090032u; return 0; }
r[12]=read(ram,0x0c0900ecu,4);
goto P_0c090034;
P_0c090034: /* original 9955, guest PC 0x0c090034 */
if(!s->budget--) { s->failed_pc=0x0c090034u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0900e2u,2);
goto P_0c090036;
P_0c090036: /* original f48d, guest PC 0x0c090036 */
if(!s->budget--) { s->failed_pc=0x0c090036u; return 0; }
fr[4]=0;
goto P_0c090038;
P_0c090038: /* original ff9d, guest PC 0x0c090038 */
if(!s->budget--) { s->failed_pc=0x0c090038u; return 0; }
fr[15]=0x3f800000u;
goto P_0c09003a;
P_0c09003a: /* original 8f02, guest PC 0x0c09003a */
if(!s->budget--) { s->failed_pc=0x0c09003au; return 0; }
cond=r[17]&1u;
r[9]&=r[5];
if(!cond) { goto P_0c090042; }
goto P_0c09003e;
P_0c09003c: /* original 2959, guest PC 0x0c09003c */
if(!s->budget--) { s->failed_pc=0x0c09003cu; return 0; }
r[9]&=r[5];
goto P_0c09003e;
P_0c09003e: /* original a0b2, guest PC 0x0c09003e */
if(!s->budget--) { s->failed_pc=0x0c09003eu; return 0; }
goto P_0c0901a6;
P_0c090040: /* original 0009, guest PC 0x0c090040 */
if(!s->budget--) { s->failed_pc=0x0c090040u; return 0; }
goto P_0c090042;
P_0c090042: /* original 2998, guest PC 0x0c090042 */
if(!s->budget--) { s->failed_pc=0x0c090042u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c090044;
P_0c090044: /* original 8901, guest PC 0x0c090044 */
if(!s->budget--) { s->failed_pc=0x0c090044u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09004a; }
goto P_0c090046;
P_0c090046: /* original a0ae, guest PC 0x0c090046 */
if(!s->budget--) { s->failed_pc=0x0c090046u; return 0; }
goto P_0c0901a6;
P_0c090048: /* original 0009, guest PC 0x0c090048 */
if(!s->budget--) { s->failed_pc=0x0c090048u; return 0; }
goto P_0c09004a;
P_0c09004a: /* original 66f3, guest PC 0x0c09004a */
if(!s->budget--) { s->failed_pc=0x0c09004au; return 0; }
r[6]=r[15];
goto P_0c09004c;
P_0c09004c: /* original 65f3, guest PC 0x0c09004c */
if(!s->budget--) { s->failed_pc=0x0c09004cu; return 0; }
r[5]=r[15];
goto P_0c09004e;
P_0c09004e: /* original 67f3, guest PC 0x0c09004e */
if(!s->budget--) { s->failed_pc=0x0c09004eu; return 0; }
r[7]=r[15];
goto P_0c090050;
P_0c090050: /* original 64f3, guest PC 0x0c090050 */
if(!s->budget--) { s->failed_pc=0x0c090050u; return 0; }
r[4]=r[15];
goto P_0c090052;
P_0c090052: /* original f5cc, guest PC 0x0c090052 */
if(!s->budget--) { s->failed_pc=0x0c090052u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c090054;
P_0c090054: /* original 7504, guest PC 0x0c090054 */
if(!s->budget--) { s->failed_pc=0x0c090054u; return 0; }
r[5]+=0x00000004u;
goto P_0c090056;
P_0c090056: /* original 7718, guest PC 0x0c090056 */
if(!s->budget--) { s->failed_pc=0x0c090056u; return 0; }
r[7]+=0x00000018u;
goto P_0c090058;
P_0c090058: /* original 7624, guest PC 0x0c090058 */
if(!s->budget--) { s->failed_pc=0x0c090058u; return 0; }
r[6]+=0x00000024u;
goto P_0c09005a;
P_0c09005a: /* original 4c0b, guest PC 0x0c09005a */
if(!s->budget--) { s->failed_pc=0x0c09005au; return 0; }
target=r[12];
r[16]=0x0c09005eu;
vf3_matrix_move(s,4,13);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09005eu) { target=s->pc; goto dispatch; }
goto P_0c09005e;
P_0c09005c: /* original f4dc, guest PC 0x0c09005c */
if(!s->budget--) { s->failed_pc=0x0c09005cu; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c09005e;
P_0c09005e: /* original f4f8, guest PC 0x0c09005e */
if(!s->budget--) { s->failed_pc=0x0c09005eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c090060;
P_0c090060: /* original e004, guest PC 0x0c090060 */
if(!s->budget--) { s->failed_pc=0x0c090060u; return 0; }
r[0]=0x00000004u;
goto P_0c090062;
P_0c090062: /* original f5f6, guest PC 0x0c090062 */
if(!s->budget--) { s->failed_pc=0x0c090062u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c090064;
P_0c090064: /* original c722, guest PC 0x0c090064 */
if(!s->budget--) { s->failed_pc=0x0c090064u; return 0; }
r[0]=0x0c0900f0u;
goto P_0c090066;
P_0c090066: /* original f4d1, guest PC 0x0c090066 */
if(!s->budget--) { s->failed_pc=0x0c090066u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c090068;
P_0c090068: /* original f208, guest PC 0x0c090068 */
if(!s->budget--) { s->failed_pc=0x0c090068u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c09006a;
P_0c09006a: /* original f5c1, guest PC 0x0c09006a */
if(!s->budget--) { s->failed_pc=0x0c09006au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[12],r[18],'-');
goto P_0c09006c;
P_0c09006c: /* original f34c, guest PC 0x0c09006c */
if(!s->budget--) { s->failed_pc=0x0c09006cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09006e;
P_0c09006e: /* original f432, guest PC 0x0c09006e */
if(!s->budget--) { s->failed_pc=0x0c09006eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c090070;
P_0c090070: /* original f05c, guest PC 0x0c090070 */
if(!s->budget--) { s->failed_pc=0x0c090070u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c090072;
P_0c090072: /* original f45e, guest PC 0x0c090072 */
if(!s->budget--) { s->failed_pc=0x0c090072u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c090074;
P_0c090074: /* original fe4c, guest PC 0x0c090074 */
if(!s->budget--) { s->failed_pc=0x0c090074u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c090076;
P_0c090076: /* original f2e5, guest PC 0x0c090076 */
if(!s->budget--) { s->failed_pc=0x0c090076u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[14]))!=0);
goto P_0c090078;
P_0c090078: /* original 8b01, guest PC 0x0c090078 */
if(!s->budget--) { s->failed_pc=0x0c090078u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09007e; }
goto P_0c09007a;
P_0c09007a: /* original a002, guest PC 0x0c09007a */
if(!s->budget--) { s->failed_pc=0x0c09007au; return 0; }
fr[3]=0;
goto P_0c090082;
P_0c09007c: /* original f38d, guest PC 0x0c09007c */
if(!s->budget--) { s->failed_pc=0x0c09007cu; return 0; }
fr[3]=0;
goto P_0c09007e;
P_0c09007e: /* original f3ec, guest PC 0x0c09007e */
if(!s->budget--) { s->failed_pc=0x0c09007eu; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c090080;
P_0c090080: /* original f37d, guest PC 0x0c090080 */
if(!s->budget--) { s->failed_pc=0x0c090080u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c090082;
P_0c090082: /* original fe32, guest PC 0x0c090082 */
if(!s->budget--) { s->failed_pc=0x0c090082u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c090084;
P_0c090084: /* original e020, guest PC 0x0c090084 */
if(!s->budget--) { s->failed_pc=0x0c090084u; return 0; }
r[0]=0x00000020u;
goto P_0c090086;
P_0c090086: /* original 65f3, guest PC 0x0c090086 */
if(!s->budget--) { s->failed_pc=0x0c090086u; return 0; }
r[5]=r[15];
goto P_0c090088;
P_0c090088: /* original f5f6, guest PC 0x0c090088 */
if(!s->budget--) { s->failed_pc=0x0c090088u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c09008a;
P_0c09008a: /* original 67f3, guest PC 0x0c09008a */
if(!s->budget--) { s->failed_pc=0x0c09008au; return 0; }
r[7]=r[15];
goto P_0c09008c;
P_0c09008c: /* original 66f3, guest PC 0x0c09008c */
if(!s->budget--) { s->failed_pc=0x0c09008cu; return 0; }
r[6]=r[15];
goto P_0c09008e;
P_0c09008e: /* original 7718, guest PC 0x0c09008e */
if(!s->budget--) { s->failed_pc=0x0c09008eu; return 0; }
r[7]+=0x00000018u;
goto P_0c090090;
P_0c090090: /* original 64f3, guest PC 0x0c090090 */
if(!s->budget--) { s->failed_pc=0x0c090090u; return 0; }
r[4]=r[15];
goto P_0c090092;
P_0c090092: /* original e01c, guest PC 0x0c090092 */
if(!s->budget--) { s->failed_pc=0x0c090092u; return 0; }
r[0]=0x0000001cu;
goto P_0c090094;
P_0c090094: /* original 7624, guest PC 0x0c090094 */
if(!s->budget--) { s->failed_pc=0x0c090094u; return 0; }
r[6]+=0x00000024u;
goto P_0c090096;
P_0c090096: /* original 7504, guest PC 0x0c090096 */
if(!s->budget--) { s->failed_pc=0x0c090096u; return 0; }
r[5]+=0x00000004u;
goto P_0c090098;
P_0c090098: /* original 4c0b, guest PC 0x0c090098 */
if(!s->budget--) { s->failed_pc=0x0c090098u; return 0; }
target=r[12];
r[16]=0x0c09009cu;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09009cu) { target=s->pc; goto dispatch; }
goto P_0c09009c;
P_0c09009a: /* original f4f6, guest PC 0x0c09009a */
if(!s->budget--) { s->failed_pc=0x0c09009au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c09009c;
P_0c09009c: /* original e01c, guest PC 0x0c09009c */
if(!s->budget--) { s->failed_pc=0x0c09009cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09009e;
P_0c09009e: /* original f4f8, guest PC 0x0c09009e */
if(!s->budget--) { s->failed_pc=0x0c09009eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0900a0;
P_0c0900a0: /* original f3f6, guest PC 0x0c0900a0 */
if(!s->budget--) { s->failed_pc=0x0c0900a0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0900a2;
P_0c0900a2: /* original e020, guest PC 0x0c0900a2 */
if(!s->budget--) { s->failed_pc=0x0c0900a2u; return 0; }
r[0]=0x00000020u;
goto P_0c0900a4;
P_0c0900a4: /* original f431, guest PC 0x0c0900a4 */
if(!s->budget--) { s->failed_pc=0x0c0900a4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0900a6;
P_0c0900a6: /* original f24c, guest PC 0x0c0900a6 */
if(!s->budget--) { s->failed_pc=0x0c0900a6u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0900a8;
P_0c0900a8: /* original f422, guest PC 0x0c0900a8 */
if(!s->budget--) { s->failed_pc=0x0c0900a8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c0900aa;
P_0c0900aa: /* original f2f6, guest PC 0x0c0900aa */
if(!s->budget--) { s->failed_pc=0x0c0900aau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0900ac;
P_0c0900ac: /* original e004, guest PC 0x0c0900ac */
if(!s->budget--) { s->failed_pc=0x0c0900acu; return 0; }
r[0]=0x00000004u;
goto P_0c0900ae;
P_0c0900ae: /* original f5f6, guest PC 0x0c0900ae */
if(!s->budget--) { s->failed_pc=0x0c0900aeu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0900b0;
P_0c0900b0: /* original c70f, guest PC 0x0c0900b0 */
if(!s->budget--) { s->failed_pc=0x0c0900b0u; return 0; }
r[0]=0x0c0900f0u;
goto P_0c0900b2;
P_0c0900b2: /* original f521, guest PC 0x0c0900b2 */
if(!s->budget--) { s->failed_pc=0x0c0900b2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0900b4;
P_0c0900b4: /* original f05c, guest PC 0x0c0900b4 */
if(!s->budget--) { s->failed_pc=0x0c0900b4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0900b6;
P_0c0900b6: /* original f45e, guest PC 0x0c0900b6 */
if(!s->budget--) { s->failed_pc=0x0c0900b6u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c0900b8;
P_0c0900b8: /* original f008, guest PC 0x0c0900b8 */
if(!s->budget--) { s->failed_pc=0x0c0900b8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c0900ba;
P_0c0900ba: /* original f045, guest PC 0x0c0900ba */
if(!s->budget--) { s->failed_pc=0x0c0900bau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[4]))!=0);
goto P_0c0900bc;
P_0c0900bc: /* original 8b01, guest PC 0x0c0900bc */
if(!s->budget--) { s->failed_pc=0x0c0900bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0900c2; }
goto P_0c0900be;
P_0c0900be: /* original a002, guest PC 0x0c0900be */
if(!s->budget--) { s->failed_pc=0x0c0900beu; return 0; }
fr[1]=0;
goto P_0c0900c6;
P_0c0900c0: /* original f18d, guest PC 0x0c0900c0 */
if(!s->budget--) { s->failed_pc=0x0c0900c0u; return 0; }
fr[1]=0;
goto P_0c0900c2;
P_0c0900c2: /* original f14c, guest PC 0x0c0900c2 */
if(!s->budget--) { s->failed_pc=0x0c0900c2u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0900c4;
P_0c0900c4: /* original f17d, guest PC 0x0c0900c4 */
if(!s->budget--) { s->failed_pc=0x0c0900c4u; return 0; }
if(!vf3_fpu_fsrra(fr[1],r[18],&fr[1])) goto unsupported;
goto P_0c0900c6;
P_0c0900c6: /* original 900d, guest PC 0x0c0900c6 */
if(!s->budget--) { s->failed_pc=0x0c0900c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0900e4u,2);
goto P_0c0900c8;
P_0c0900c8: /* original f412, guest PC 0x0c0900c8 */
if(!s->budget--) { s->failed_pc=0x0c0900c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'*');
goto P_0c0900ca;
P_0c0900ca: /* original f2ec, guest PC 0x0c0900ca */
if(!s->budget--) { s->failed_pc=0x0c0900cau; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0900cc;
P_0c0900cc: /* original f3e6, guest PC 0x0c0900cc */
if(!s->budget--) { s->failed_pc=0x0c0900ccu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0900ce;
P_0c0900ce: /* original f18d, guest PC 0x0c0900ce */
if(!s->budget--) { s->failed_pc=0x0c0900ceu; return 0; }
fr[1]=0;
goto P_0c0900d0;
P_0c0900d0: /* original f231, guest PC 0x0c0900d0 */
if(!s->budget--) { s->failed_pc=0x0c0900d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0900d2;
P_0c0900d2: /* original f125, guest PC 0x0c0900d2 */
if(!s->budget--) { s->failed_pc=0x0c0900d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c0900d4;
P_0c0900d4: /* original 8d0e, guest PC 0x0c0900d4 */
if(!s->budget--) { s->failed_pc=0x0c0900d4u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]);
if(cond) { goto P_0c0900f4; }
goto P_0c0900d8;
P_0c0900d6: /* original ff3a, guest PC 0x0c0900d6 */
if(!s->budget--) { s->failed_pc=0x0c0900d6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0900d8;
P_0c0900d8: /* original a00d, guest PC 0x0c0900d8 */
if(!s->budget--) { s->failed_pc=0x0c0900d8u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0900f6;
P_0c0900da: /* original f53c, guest PC 0x0c0900da */
if(!s->budget--) { s->failed_pc=0x0c0900dau; return 0; }
vf3_matrix_move(s,5,3);
return vf3_matrix_family(0x0c0900dcu,s,ram);
P_0c0900f4: /* original f5ec, guest PC 0x0c0900f4 */
if(!s->budget--) { s->failed_pc=0x0c0900f4u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0900f6;
P_0c0900f6: /* original f3f8, guest PC 0x0c0900f6 */
if(!s->budget--) { s->failed_pc=0x0c0900f6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0900f8;
P_0c0900f8: /* original f24c, guest PC 0x0c0900f8 */
if(!s->budget--) { s->failed_pc=0x0c0900f8u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0900fa;
P_0c0900fa: /* original f231, guest PC 0x0c0900fa */
if(!s->budget--) { s->failed_pc=0x0c0900fau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0900fc;
P_0c0900fc: /* original f18d, guest PC 0x0c0900fc */
if(!s->budget--) { s->failed_pc=0x0c0900fcu; return 0; }
fr[1]=0;
goto P_0c0900fe;
P_0c0900fe: /* original f125, guest PC 0x0c0900fe */
if(!s->budget--) { s->failed_pc=0x0c0900feu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c090100;
P_0c090100: /* original 8900, guest PC 0x0c090100 */
if(!s->budget--) { s->failed_pc=0x0c090100u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c090104; }
goto P_0c090102;
P_0c090102: /* original f43c, guest PC 0x0c090102 */
if(!s->budget--) { s->failed_pc=0x0c090102u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c090104;
P_0c090104: /* original f35c, guest PC 0x0c090104 */
if(!s->budget--) { s->failed_pc=0x0c090104u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c090106;
P_0c090106: /* original f5f8, guest PC 0x0c090106 */
if(!s->budget--) { s->failed_pc=0x0c090106u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c090108;
P_0c090108: /* original f531, guest PC 0x0c090108 */
if(!s->budget--) { s->failed_pc=0x0c090108u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c09010a;
P_0c09010a: /* original f34c, guest PC 0x0c09010a */
if(!s->budget--) { s->failed_pc=0x0c09010au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09010c;
P_0c09010c: /* original f4f8, guest PC 0x0c09010c */
if(!s->budget--) { s->failed_pc=0x0c09010cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c09010e;
P_0c09010e: /* original f431, guest PC 0x0c09010e */
if(!s->budget--) { s->failed_pc=0x0c09010eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c090110;
P_0c090110: /* original f38d, guest PC 0x0c090110 */
if(!s->budget--) { s->failed_pc=0x0c090110u; return 0; }
fr[3]=0;
goto P_0c090112;
P_0c090112: /* original f64c, guest PC 0x0c090112 */
if(!s->budget--) { s->failed_pc=0x0c090112u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c090114;
P_0c090114: /* original f651, guest PC 0x0c090114 */
if(!s->budget--) { s->failed_pc=0x0c090114u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'-');
goto P_0c090116;
P_0c090116: /* original f365, guest PC 0x0c090116 */
if(!s->budget--) { s->failed_pc=0x0c090116u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c090118;
P_0c090118: /* original 8d01, guest PC 0x0c090118 */
if(!s->budget--) { s->failed_pc=0x0c090118u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,3,6);
if(cond) { goto P_0c09011e; }
goto P_0c09011c;
P_0c09011a: /* original f36c, guest PC 0x0c09011a */
if(!s->budget--) { s->failed_pc=0x0c09011au; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c09011c;
P_0c09011c: /* original f45c, guest PC 0x0c09011c */
if(!s->budget--) { s->failed_pc=0x0c09011cu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c09011e;
P_0c09011e: /* original e004, guest PC 0x0c09011e */
if(!s->budget--) { s->failed_pc=0x0c09011eu; return 0; }
r[0]=0x00000004u;
goto P_0c090120;
P_0c090120: /* original f35d, guest PC 0x0c090120 */
if(!s->budget--) { s->failed_pc=0x0c090120u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c090122;
P_0c090122: /* original f432, guest PC 0x0c090122 */
if(!s->budget--) { s->failed_pc=0x0c090122u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c090124;
P_0c090124: /* original ff37, guest PC 0x0c090124 */
if(!s->budget--) { s->failed_pc=0x0c090124u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090126;
P_0c090126: /* original f3f8, guest PC 0x0c090126 */
if(!s->budget--) { s->failed_pc=0x0c090126u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c090128;
P_0c090128: /* original f23c, guest PC 0x0c090128 */
if(!s->budget--) { s->failed_pc=0x0c090128u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c09012a;
P_0c09012a: /* original f230, guest PC 0x0c09012a */
if(!s->budget--) { s->failed_pc=0x0c09012au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09012c;
P_0c09012c: /* original ff2a, guest PC 0x0c09012c */
if(!s->budget--) { s->failed_pc=0x0c09012cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c09012e;
P_0c09012e: /* original f2f1, guest PC 0x0c09012e */
if(!s->budget--) { s->failed_pc=0x0c09012eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'-');
goto P_0c090130;
P_0c090130: /* original f18d, guest PC 0x0c090130 */
if(!s->budget--) { s->failed_pc=0x0c090130u; return 0; }
fr[1]=0;
goto P_0c090132;
P_0c090132: /* original f125, guest PC 0x0c090132 */
if(!s->budget--) { s->failed_pc=0x0c090132u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c090134;
P_0c090134: /* original 8901, guest PC 0x0c090134 */
if(!s->budget--) { s->failed_pc=0x0c090134u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09013a; }
goto P_0c090136;
P_0c090136: /* original a001, guest PC 0x0c090136 */
if(!s->budget--) { s->failed_pc=0x0c090136u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c09013c;
P_0c090138: /* original f3f8, guest PC 0x0c090138 */
if(!s->budget--) { s->failed_pc=0x0c090138u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c09013a;
P_0c09013a: /* original f3fc, guest PC 0x0c09013a */
if(!s->budget--) { s->failed_pc=0x0c09013au; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c09013c;
P_0c09013c: /* original f433, guest PC 0x0c09013c */
if(!s->budget--) { s->failed_pc=0x0c09013cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c09013e;
P_0c09013e: /* original e01c, guest PC 0x0c09013e */
if(!s->budget--) { s->failed_pc=0x0c09013eu; return 0; }
r[0]=0x0000001cu;
goto P_0c090140;
P_0c090140: /* original ff4a, guest PC 0x0c090140 */
if(!s->budget--) { s->failed_pc=0x0c090140u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c090142;
P_0c090142: /* original f4f6, guest PC 0x0c090142 */
if(!s->budget--) { s->failed_pc=0x0c090142u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c090144;
P_0c090144: /* original e020, guest PC 0x0c090144 */
if(!s->budget--) { s->failed_pc=0x0c090144u; return 0; }
r[0]=0x00000020u;
goto P_0c090146;
P_0c090146: /* original f5f6, guest PC 0x0c090146 */
if(!s->budget--) { s->failed_pc=0x0c090146u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c090148;
P_0c090148: /* original c714, guest PC 0x0c090148 */
if(!s->budget--) { s->failed_pc=0x0c090148u; return 0; }
r[0]=0x0c09019cu;
goto P_0c09014a;
P_0c09014a: /* original f4d1, guest PC 0x0c09014a */
if(!s->budget--) { s->failed_pc=0x0c09014au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c09014c;
P_0c09014c: /* original f208, guest PC 0x0c09014c */
if(!s->budget--) { s->failed_pc=0x0c09014cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c09014e;
P_0c09014e: /* original f5c1, guest PC 0x0c09014e */
if(!s->budget--) { s->failed_pc=0x0c09014eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[12],r[18],'-');
goto P_0c090150;
P_0c090150: /* original f34c, guest PC 0x0c090150 */
if(!s->budget--) { s->failed_pc=0x0c090150u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c090152;
P_0c090152: /* original f432, guest PC 0x0c090152 */
if(!s->budget--) { s->failed_pc=0x0c090152u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c090154;
P_0c090154: /* original f05c, guest PC 0x0c090154 */
if(!s->budget--) { s->failed_pc=0x0c090154u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c090156;
P_0c090156: /* original f45e, guest PC 0x0c090156 */
if(!s->budget--) { s->failed_pc=0x0c090156u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c090158;
P_0c090158: /* original f245, guest PC 0x0c090158 */
if(!s->budget--) { s->failed_pc=0x0c090158u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c09015a;
P_0c09015a: /* original 8b01, guest PC 0x0c09015a */
if(!s->budget--) { s->failed_pc=0x0c09015au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c090160; }
goto P_0c09015c;
P_0c09015c: /* original a002, guest PC 0x0c09015c */
if(!s->budget--) { s->failed_pc=0x0c09015cu; return 0; }
fr[3]=0;
goto P_0c090164;
P_0c09015e: /* original f38d, guest PC 0x0c09015e */
if(!s->budget--) { s->failed_pc=0x0c09015eu; return 0; }
fr[3]=0;
goto P_0c090160;
P_0c090160: /* original f34c, guest PC 0x0c090160 */
if(!s->budget--) { s->failed_pc=0x0c090160u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c090162;
P_0c090162: /* original f37d, guest PC 0x0c090162 */
if(!s->budget--) { s->failed_pc=0x0c090162u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c090164;
P_0c090164: /* original f432, guest PC 0x0c090164 */
if(!s->budget--) { s->failed_pc=0x0c090164u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c090166;
P_0c090166: /* original f28d, guest PC 0x0c090166 */
if(!s->budget--) { s->failed_pc=0x0c090166u; return 0; }
fr[2]=0;
goto P_0c090168;
P_0c090168: /* original f34c, guest PC 0x0c090168 */
if(!s->budget--) { s->failed_pc=0x0c090168u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09016a;
P_0c09016a: /* original f3f1, guest PC 0x0c09016a */
if(!s->budget--) { s->failed_pc=0x0c09016au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'-');
goto P_0c09016c;
P_0c09016c: /* original f235, guest PC 0x0c09016c */
if(!s->budget--) { s->failed_pc=0x0c09016cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c09016e;
P_0c09016e: /* original 8b00, guest PC 0x0c09016e */
if(!s->budget--) { s->failed_pc=0x0c09016eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c090172; }
goto P_0c090170;
P_0c090170: /* original f4fc, guest PC 0x0c090170 */
if(!s->budget--) { s->failed_pc=0x0c090170u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c090172;
P_0c090172: /* original f3f8, guest PC 0x0c090172 */
if(!s->budget--) { s->failed_pc=0x0c090172u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c090174;
P_0c090174: /* original c70a, guest PC 0x0c090174 */
if(!s->budget--) { s->failed_pc=0x0c090174u; return 0; }
r[0]=0x0c0901a0u;
goto P_0c090176;
P_0c090176: /* original f343, guest PC 0x0c090176 */
if(!s->budget--) { s->failed_pc=0x0c090176u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c090178;
P_0c090178: /* original ff3a, guest PC 0x0c090178 */
if(!s->budget--) { s->failed_pc=0x0c090178u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09017a;
P_0c09017a: /* original f408, guest PC 0x0c09017a */
if(!s->budget--) { s->failed_pc=0x0c09017au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09017c;
P_0c09017c: /* original f18d, guest PC 0x0c09017c */
if(!s->budget--) { s->failed_pc=0x0c09017cu; return 0; }
fr[1]=0;
goto P_0c09017e;
P_0c09017e: /* original f341, guest PC 0x0c09017e */
if(!s->budget--) { s->failed_pc=0x0c09017eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c090180;
P_0c090180: /* original f135, guest PC 0x0c090180 */
if(!s->budget--) { s->failed_pc=0x0c090180u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[3]))!=0);
goto P_0c090182;
P_0c090182: /* original 8901, guest PC 0x0c090182 */
if(!s->budget--) { s->failed_pc=0x0c090182u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c090188; }
goto P_0c090184;
P_0c090184: /* original a001, guest PC 0x0c090184 */
if(!s->budget--) { s->failed_pc=0x0c090184u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c09018a;
P_0c090186: /* original f24c, guest PC 0x0c090186 */
if(!s->budget--) { s->failed_pc=0x0c090186u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c090188;
P_0c090188: /* original f2f8, guest PC 0x0c090188 */
if(!s->budget--) { s->failed_pc=0x0c090188u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c09018a;
P_0c09018a: /* original ff2a, guest PC 0x0c09018a */
if(!s->budget--) { s->failed_pc=0x0c09018au; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c09018c;
P_0c09018c: /* original f38d, guest PC 0x0c09018c */
if(!s->budget--) { s->failed_pc=0x0c09018cu; return 0; }
fr[3]=0;
goto P_0c09018e;
P_0c09018e: /* original f365, guest PC 0x0c09018e */
if(!s->budget--) { s->failed_pc=0x0c09018eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c090190;
P_0c090190: /* original f52c, guest PC 0x0c090190 */
if(!s->budget--) { s->failed_pc=0x0c090190u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c090192;
P_0c090192: /* original 8d07, guest PC 0x0c090192 */
if(!s->budget--) { s->failed_pc=0x0c090192u; return 0; }
cond=r[17]&1u;
fr[5]^=0x80000000u;
if(cond) { goto P_0c0901a4; }
goto P_0c090196;
P_0c090194: /* original f54d, guest PC 0x0c090194 */
if(!s->budget--) { s->failed_pc=0x0c090194u; return 0; }
fr[5]^=0x80000000u;
goto P_0c090196;
P_0c090196: /* original a006, guest PC 0x0c090196 */
if(!s->budget--) { s->failed_pc=0x0c090196u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0901a6;
P_0c090198: /* original f4f8, guest PC 0x0c090198 */
if(!s->budget--) { s->failed_pc=0x0c090198u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
return vf3_matrix_family(0x0c09019au,s,ram);
P_0c0901a4: /* original f45c, guest PC 0x0c0901a4 */
if(!s->budget--) { s->failed_pc=0x0c0901a4u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0901a6;
P_0c0901a6: /* original 909b, guest PC 0x0c0901a6 */
if(!s->budget--) { s->failed_pc=0x0c0901a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0902e0u,2);
goto P_0c0901a8;
P_0c0901a8: /* original f3e6, guest PC 0x0c0901a8 */
if(!s->budget--) { s->failed_pc=0x0c0901a8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0901aa;
P_0c0901aa: /* original ff3a, guest PC 0x0c0901aa */
if(!s->budget--) { s->failed_pc=0x0c0901aau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0901ac;
P_0c0901ac: /* original 9099, guest PC 0x0c0901ac */
if(!s->budget--) { s->failed_pc=0x0c0901acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0902e2u,2);
goto P_0c0901ae;
P_0c0901ae: /* original f5e6, guest PC 0x0c0901ae */
if(!s->budget--) { s->failed_pc=0x0c0901aeu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0901b0;
P_0c0901b0: /* original 7004, guest PC 0x0c0901b0 */
if(!s->budget--) { s->failed_pc=0x0c0901b0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0901b2;
P_0c0901b2: /* original f3e6, guest PC 0x0c0901b2 */
if(!s->budget--) { s->failed_pc=0x0c0901b2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0901b4;
P_0c0901b4: /* original e004, guest PC 0x0c0901b4 */
if(!s->budget--) { s->failed_pc=0x0c0901b4u; return 0; }
r[0]=0x00000004u;
goto P_0c0901b6;
P_0c0901b6: /* original ff37, guest PC 0x0c0901b6 */
if(!s->budget--) { s->failed_pc=0x0c0901b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0901b8;
P_0c0901b8: /* original e004, guest PC 0x0c0901b8 */
if(!s->budget--) { s->failed_pc=0x0c0901b8u; return 0; }
r[0]=0x00000004u;
goto P_0c0901ba;
P_0c0901ba: /* original f3f8, guest PC 0x0c0901ba */
if(!s->budget--) { s->failed_pc=0x0c0901bau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0901bc;
P_0c0901bc: /* original f0f6, guest PC 0x0c0901bc */
if(!s->budget--) { s->failed_pc=0x0c0901bcu; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0901be;
P_0c0901be: /* original f531, guest PC 0x0c0901be */
if(!s->budget--) { s->failed_pc=0x0c0901beu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0901c0;
P_0c0901c0: /* original f35e, guest PC 0x0c0901c0 */
if(!s->budget--) { s->failed_pc=0x0c0901c0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0901c2;
P_0c0901c2: /* original ff3a, guest PC 0x0c0901c2 */
if(!s->budget--) { s->failed_pc=0x0c0901c2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0901c4;
P_0c0901c4: /* original 908c, guest PC 0x0c0901c4 */
if(!s->budget--) { s->failed_pc=0x0c0901c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0902e0u,2);
goto P_0c0901c6;
P_0c0901c6: /* original fe37, guest PC 0x0c0901c6 */
if(!s->budget--) { s->failed_pc=0x0c0901c6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0901c8;
P_0c0901c8: /* original e050, guest PC 0x0c0901c8 */
if(!s->budget--) { s->failed_pc=0x0c0901c8u; return 0; }
r[0]=0x00000050u;
goto P_0c0901ca;
P_0c0901ca: /* original f3f8, guest PC 0x0c0901ca */
if(!s->budget--) { s->failed_pc=0x0c0901cau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0901cc;
P_0c0901cc: /* original f24c, guest PC 0x0c0901cc */
if(!s->budget--) { s->failed_pc=0x0c0901ccu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0901ce;
P_0c0901ce: /* original f230, guest PC 0x0c0901ce */
if(!s->budget--) { s->failed_pc=0x0c0901ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0901d0;
P_0c0901d0: /* original ff2a, guest PC 0x0c0901d0 */
if(!s->budget--) { s->failed_pc=0x0c0901d0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0901d2;
P_0c0901d2: /* original f5fc, guest PC 0x0c0901d2 */
if(!s->budget--) { s->failed_pc=0x0c0901d2u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0901d4;
P_0c0901d4: /* original f521, guest PC 0x0c0901d4 */
if(!s->budget--) { s->failed_pc=0x0c0901d4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0901d6;
P_0c0901d6: /* original f3dc, guest PC 0x0c0901d6 */
if(!s->budget--) { s->failed_pc=0x0c0901d6u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0901d8;
P_0c0901d8: /* original fd5c, guest PC 0x0c0901d8 */
if(!s->budget--) { s->failed_pc=0x0c0901d8u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0901da;
P_0c0901da: /* original fd32, guest PC 0x0c0901da */
if(!s->budget--) { s->failed_pc=0x0c0901dau; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'*');
goto P_0c0901dc;
P_0c0901dc: /* original f3f6, guest PC 0x0c0901dc */
if(!s->budget--) { s->failed_pc=0x0c0901dcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0901de;
P_0c0901de: /* original e010, guest PC 0x0c0901de */
if(!s->budget--) { s->failed_pc=0x0c0901deu; return 0; }
r[0]=0x00000010u;
goto P_0c0901e0;
P_0c0901e0: /* original f25c, guest PC 0x0c0901e0 */
if(!s->budget--) { s->failed_pc=0x0c0901e0u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0901e2;
P_0c0901e2: /* original f232, guest PC 0x0c0901e2 */
if(!s->budget--) { s->failed_pc=0x0c0901e2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0901e4;
P_0c0901e4: /* original ff27, guest PC 0x0c0901e4 */
if(!s->budget--) { s->failed_pc=0x0c0901e4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0901e6;
P_0c0901e6: /* original e01c, guest PC 0x0c0901e6 */
if(!s->budget--) { s->failed_pc=0x0c0901e6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0901e8;
P_0c0901e8: /* original f0f8, guest PC 0x0c0901e8 */
if(!s->budget--) { s->failed_pc=0x0c0901e8u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c0901ea;
P_0c0901ea: /* original f3f6, guest PC 0x0c0901ea */
if(!s->budget--) { s->failed_pc=0x0c0901eau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0901ec;
P_0c0901ec: /* original e054, guest PC 0x0c0901ec */
if(!s->budget--) { s->failed_pc=0x0c0901ecu; return 0; }
r[0]=0x00000054u;
goto P_0c0901ee;
P_0c0901ee: /* original f1dc, guest PC 0x0c0901ee */
if(!s->budget--) { s->failed_pc=0x0c0901eeu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c0901f0;
P_0c0901f0: /* original f13e, guest PC 0x0c0901f0 */
if(!s->budget--) { s->failed_pc=0x0c0901f0u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0901f2;
P_0c0901f2: /* original f3f6, guest PC 0x0c0901f2 */
if(!s->budget--) { s->failed_pc=0x0c0901f2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0901f4;
P_0c0901f4: /* original fe5c, guest PC 0x0c0901f4 */
if(!s->budget--) { s->failed_pc=0x0c0901f4u; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c0901f6;
P_0c0901f6: /* original e010, guest PC 0x0c0901f6 */
if(!s->budget--) { s->failed_pc=0x0c0901f6u; return 0; }
r[0]=0x00000010u;
goto P_0c0901f8;
P_0c0901f8: /* original f23e, guest PC 0x0c0901f8 */
if(!s->budget--) { s->failed_pc=0x0c0901f8u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c0901fa;
P_0c0901fa: /* original fec2, guest PC 0x0c0901fa */
if(!s->budget--) { s->failed_pc=0x0c0901fau; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[12],r[18],'*');
goto P_0c0901fc;
P_0c0901fc: /* original ff27, guest PC 0x0c0901fc */
if(!s->budget--) { s->failed_pc=0x0c0901fcu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0901fe;
P_0c0901fe: /* original e020, guest PC 0x0c0901fe */
if(!s->budget--) { s->failed_pc=0x0c0901feu; return 0; }
r[0]=0x00000020u;
goto P_0c090200;
P_0c090200: /* original f0f8, guest PC 0x0c090200 */
if(!s->budget--) { s->failed_pc=0x0c090200u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c090202;
P_0c090202: /* original f2f6, guest PC 0x0c090202 */
if(!s->budget--) { s->failed_pc=0x0c090202u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c090204;
P_0c090204: /* original f3ec, guest PC 0x0c090204 */
if(!s->budget--) { s->failed_pc=0x0c090204u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c090206;
P_0c090206: /* original f32e, guest PC 0x0c090206 */
if(!s->budget--) { s->failed_pc=0x0c090206u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c090208;
P_0c090208: /* original 906c, guest PC 0x0c090208 */
if(!s->budget--) { s->failed_pc=0x0c090208u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0902e4u,2);
goto P_0c09020a;
P_0c09020a: /* original fe3c, guest PC 0x0c09020a */
if(!s->budget--) { s->failed_pc=0x0c09020au; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c09020c;
P_0c09020c: /* original f34c, guest PC 0x0c09020c */
if(!s->budget--) { s->failed_pc=0x0c09020cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09020e;
P_0c09020e: /* original f430, guest PC 0x0c09020e */
if(!s->budget--) { s->failed_pc=0x0c09020eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c090210;
P_0c090210: /* original fe47, guest PC 0x0c090210 */
if(!s->budget--) { s->failed_pc=0x0c090210u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c090212;
P_0c090212: /* original 9068, guest PC 0x0c090212 */
if(!s->budget--) { s->failed_pc=0x0c090212u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0902e6u,2);
goto P_0c090214;
P_0c090214: /* original f4e6, guest PC 0x0c090214 */
if(!s->budget--) { s->failed_pc=0x0c090214u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c090216;
P_0c090216: /* original 7004, guest PC 0x0c090216 */
if(!s->budget--) { s->failed_pc=0x0c090216u; return 0; }
r[0]+=0x00000004u;
goto P_0c090218;
P_0c090218: /* original f3e6, guest PC 0x0c090218 */
if(!s->budget--) { s->failed_pc=0x0c090218u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09021a;
P_0c09021a: /* original e03c, guest PC 0x0c09021a */
if(!s->budget--) { s->failed_pc=0x0c09021au; return 0; }
r[0]=0x0000003cu;
goto P_0c09021c;
P_0c09021c: /* original ff37, guest PC 0x0c09021c */
if(!s->budget--) { s->failed_pc=0x0c09021cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09021e;
P_0c09021e: /* original 9063, guest PC 0x0c09021e */
if(!s->budget--) { s->failed_pc=0x0c09021eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0902e8u,2);
goto P_0c090220;
P_0c090220: /* original f5e6, guest PC 0x0c090220 */
if(!s->budget--) { s->failed_pc=0x0c090220u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c090222;
P_0c090222: /* original 7040, guest PC 0x0c090222 */
if(!s->budget--) { s->failed_pc=0x0c090222u; return 0; }
r[0]+=0x00000040u;
goto P_0c090224;
P_0c090224: /* original f3e6, guest PC 0x0c090224 */
if(!s->budget--) { s->failed_pc=0x0c090224u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090226;
P_0c090226: /* original e034, guest PC 0x0c090226 */
if(!s->budget--) { s->failed_pc=0x0c090226u; return 0; }
r[0]=0x00000034u;
goto P_0c090228;
P_0c090228: /* original ff37, guest PC 0x0c090228 */
if(!s->budget--) { s->failed_pc=0x0c090228u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09022a;
P_0c09022a: /* original 905e, guest PC 0x0c09022a */
if(!s->budget--) { s->failed_pc=0x0c09022au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0902eau,2);
goto P_0c09022c;
P_0c09022c: /* original f3e6, guest PC 0x0c09022c */
if(!s->budget--) { s->failed_pc=0x0c09022cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09022e;
P_0c09022e: /* original e038, guest PC 0x0c09022e */
if(!s->budget--) { s->failed_pc=0x0c09022eu; return 0; }
r[0]=0x00000038u;
goto P_0c090230;
P_0c090230: /* original ff37, guest PC 0x0c090230 */
if(!s->budget--) { s->failed_pc=0x0c090230u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090232;
P_0c090232: /* original 905b, guest PC 0x0c090232 */
if(!s->budget--) { s->failed_pc=0x0c090232u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0902ecu,2);
goto P_0c090234;
P_0c090234: /* original f3e6, guest PC 0x0c090234 */
if(!s->budget--) { s->failed_pc=0x0c090234u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090236;
P_0c090236: /* original e030, guest PC 0x0c090236 */
if(!s->budget--) { s->failed_pc=0x0c090236u; return 0; }
r[0]=0x00000030u;
goto P_0c090238;
P_0c090238: /* original ff37, guest PC 0x0c090238 */
if(!s->budget--) { s->failed_pc=0x0c090238u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09023a;
P_0c09023a: /* original e034, guest PC 0x0c09023a */
if(!s->budget--) { s->failed_pc=0x0c09023au; return 0; }
r[0]=0x00000034u;
goto P_0c09023c;
P_0c09023c: /* original f6f6, guest PC 0x0c09023c */
if(!s->budget--) { s->failed_pc=0x0c09023cu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09023e;
P_0c09023e: /* original e030, guest PC 0x0c09023e */
if(!s->budget--) { s->failed_pc=0x0c09023eu; return 0; }
r[0]=0x00000030u;
goto P_0c090240;
P_0c090240: /* original f7f6, guest PC 0x0c090240 */
if(!s->budget--) { s->failed_pc=0x0c090240u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c090242;
P_0c090242: /* original c72b, guest PC 0x0c090242 */
if(!s->budget--) { s->failed_pc=0x0c090242u; return 0; }
r[0]=0x0c0902f0u;
goto P_0c090244;
P_0c090244: /* original f641, guest PC 0x0c090244 */
if(!s->budget--) { s->failed_pc=0x0c090244u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c090246;
P_0c090246: /* original f208, guest PC 0x0c090246 */
if(!s->budget--) { s->failed_pc=0x0c090246u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c090248;
P_0c090248: /* original f751, guest PC 0x0c090248 */
if(!s->budget--) { s->failed_pc=0x0c090248u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'-');
goto P_0c09024a;
P_0c09024a: /* original f36c, guest PC 0x0c09024a */
if(!s->budget--) { s->failed_pc=0x0c09024au; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c09024c;
P_0c09024c: /* original f632, guest PC 0x0c09024c */
if(!s->budget--) { s->failed_pc=0x0c09024cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c09024e;
P_0c09024e: /* original f07c, guest PC 0x0c09024e */
if(!s->budget--) { s->failed_pc=0x0c09024eu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c090250;
P_0c090250: /* original f67e, guest PC 0x0c090250 */
if(!s->budget--) { s->failed_pc=0x0c090250u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[7],fr[6],r[18]);
goto P_0c090252;
P_0c090252: /* original ff6c, guest PC 0x0c090252 */
if(!s->budget--) { s->failed_pc=0x0c090252u; return 0; }
vf3_matrix_move(s,15,6);
goto P_0c090254;
P_0c090254: /* original f2f5, guest PC 0x0c090254 */
if(!s->budget--) { s->failed_pc=0x0c090254u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c090256;
P_0c090256: /* original 8f02, guest PC 0x0c090256 */
if(!s->budget--) { s->failed_pc=0x0c090256u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,1);
if(!cond) { goto P_0c09025e; }
goto P_0c09025a;
P_0c090258: /* original fd1c, guest PC 0x0c090258 */
if(!s->budget--) { s->failed_pc=0x0c090258u; return 0; }
vf3_matrix_move(s,13,1);
goto P_0c09025a;
P_0c09025a: /* original a002, guest PC 0x0c09025a */
if(!s->budget--) { s->failed_pc=0x0c09025au; return 0; }
fr[3]=0;
goto P_0c090262;
P_0c09025c: /* original f38d, guest PC 0x0c09025c */
if(!s->budget--) { s->failed_pc=0x0c09025cu; return 0; }
fr[3]=0;
goto P_0c09025e;
P_0c09025e: /* original f3fc, guest PC 0x0c09025e */
if(!s->budget--) { s->failed_pc=0x0c09025eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c090260;
P_0c090260: /* original f37d, guest PC 0x0c090260 */
if(!s->budget--) { s->failed_pc=0x0c090260u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c090262;
P_0c090262: /* original 6db3, guest PC 0x0c090262 */
if(!s->budget--) { s->failed_pc=0x0c090262u; return 0; }
r[13]=r[11];
goto P_0c090264;
P_0c090264: /* original ff32, guest PC 0x0c090264 */
if(!s->budget--) { s->failed_pc=0x0c090264u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c090266;
P_0c090266: /* original d023, guest PC 0x0c090266 */
if(!s->budget--) { s->failed_pc=0x0c090266u; return 0; }
r[0]=read(ram,0x0c0902f4u,4);
goto P_0c090268;
P_0c090268: /* original 4d08, guest PC 0x0c090268 */
if(!s->budget--) { s->failed_pc=0x0c090268u; return 0; }
r[13]<<=2;
goto P_0c09026a;
P_0c09026a: /* original d323, guest PC 0x0c09026a */
if(!s->budget--) { s->failed_pc=0x0c09026au; return 0; }
r[3]=read(ram,0x0c0902f8u,4);
goto P_0c09026c;
P_0c09026c: /* original 4d08, guest PC 0x0c09026c */
if(!s->budget--) { s->failed_pc=0x0c09026cu; return 0; }
r[13]<<=2;
goto P_0c09026e;
P_0c09026e: /* original 3d0c, guest PC 0x0c09026e */
if(!s->budget--) { s->failed_pc=0x0c09026eu; return 0; }
r[13]+=r[0];
goto P_0c090270;
P_0c090270: /* original 430b, guest PC 0x0c090270 */
if(!s->budget--) { s->failed_pc=0x0c090270u; return 0; }
target=r[3];
r[16]=0x0c090274u;
vf3_matrix_load(s,ram,12,r[13]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090274u) { target=s->pc; goto dispatch; }
goto P_0c090274;
P_0c090272: /* original fcd8, guest PC 0x0c090272 */
if(!s->budget--) { s->failed_pc=0x0c090272u; return 0; }
vf3_matrix_load(s,ram,12,r[13]);
goto P_0c090274;
P_0c090274: /* original e02c, guest PC 0x0c090274 */
if(!s->budget--) { s->failed_pc=0x0c090274u; return 0; }
r[0]=0x0000002cu;
goto P_0c090276;
P_0c090276: /* original ff07, guest PC 0x0c090276 */
if(!s->budget--) { s->failed_pc=0x0c090276u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c090278;
P_0c090278: /* original e030, guest PC 0x0c090278 */
if(!s->budget--) { s->failed_pc=0x0c090278u; return 0; }
r[0]=0x00000030u;
goto P_0c09027a;
P_0c09027a: /* original d31f, guest PC 0x0c09027a */
if(!s->budget--) { s->failed_pc=0x0c09027au; return 0; }
r[3]=read(ram,0x0c0902f8u,4);
goto P_0c09027c;
P_0c09027c: /* original f5f6, guest PC 0x0c09027c */
if(!s->budget--) { s->failed_pc=0x0c09027cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c09027e;
P_0c09027e: /* original e034, guest PC 0x0c09027e */
if(!s->budget--) { s->failed_pc=0x0c09027eu; return 0; }
r[0]=0x00000034u;
goto P_0c090280;
P_0c090280: /* original 430b, guest PC 0x0c090280 */
if(!s->budget--) { s->failed_pc=0x0c090280u; return 0; }
target=r[3];
r[16]=0x0c090284u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090284u) { target=s->pc; goto dispatch; }
goto P_0c090284;
P_0c090282: /* original f4f6, guest PC 0x0c090282 */
if(!s->budget--) { s->failed_pc=0x0c090282u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c090284;
P_0c090284: /* original e02c, guest PC 0x0c090284 */
if(!s->budget--) { s->failed_pc=0x0c090284u; return 0; }
r[0]=0x0000002cu;
goto P_0c090286;
P_0c090286: /* original f28d, guest PC 0x0c090286 */
if(!s->budget--) { s->failed_pc=0x0c090286u; return 0; }
fr[2]=0;
goto P_0c090288;
P_0c090288: /* original f3f6, guest PC 0x0c090288 */
if(!s->budget--) { s->failed_pc=0x0c090288u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09028a;
P_0c09028a: /* original f3c1, guest PC 0x0c09028a */
if(!s->budget--) { s->failed_pc=0x0c09028au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'-');
goto P_0c09028c;
P_0c09028c: /* original f235, guest PC 0x0c09028c */
if(!s->budget--) { s->failed_pc=0x0c09028cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c09028e;
P_0c09028e: /* original 8d03, guest PC 0x0c09028e */
if(!s->budget--) { s->failed_pc=0x0c09028eu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,0);
if(cond) { goto P_0c090298; }
goto P_0c090292;
P_0c090290: /* original f40c, guest PC 0x0c090290 */
if(!s->budget--) { s->failed_pc=0x0c090290u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c090292;
P_0c090292: /* original e02c, guest PC 0x0c090292 */
if(!s->budget--) { s->failed_pc=0x0c090292u; return 0; }
r[0]=0x0000002cu;
goto P_0c090294;
P_0c090294: /* original a001, guest PC 0x0c090294 */
if(!s->budget--) { s->failed_pc=0x0c090294u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09029a;
P_0c090296: /* original f6f6, guest PC 0x0c090296 */
if(!s->budget--) { s->failed_pc=0x0c090296u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c090298;
P_0c090298: /* original f6cc, guest PC 0x0c090298 */
if(!s->budget--) { s->failed_pc=0x0c090298u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c09029a;
P_0c09029a: /* original f34c, guest PC 0x0c09029a */
if(!s->budget--) { s->failed_pc=0x0c09029au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09029c;
P_0c09029c: /* original f3c1, guest PC 0x0c09029c */
if(!s->budget--) { s->failed_pc=0x0c09029cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'-');
goto P_0c09029e;
P_0c09029e: /* original f28d, guest PC 0x0c09029e */
if(!s->budget--) { s->failed_pc=0x0c09029eu; return 0; }
fr[2]=0;
goto P_0c0902a0;
P_0c0902a0: /* original f235, guest PC 0x0c0902a0 */
if(!s->budget--) { s->failed_pc=0x0c0902a0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0902a2;
P_0c0902a2: /* original 8901, guest PC 0x0c0902a2 */
if(!s->budget--) { s->failed_pc=0x0c0902a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0902a8; }
goto P_0c0902a4;
P_0c0902a4: /* original a001, guest PC 0x0c0902a4 */
if(!s->budget--) { s->failed_pc=0x0c0902a4u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0902aa;
P_0c0902a6: /* original f54c, guest PC 0x0c0902a6 */
if(!s->budget--) { s->failed_pc=0x0c0902a6u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0902a8;
P_0c0902a8: /* original f5cc, guest PC 0x0c0902a8 */
if(!s->budget--) { s->failed_pc=0x0c0902a8u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0902aa;
P_0c0902aa: /* original e038, guest PC 0x0c0902aa */
if(!s->budget--) { s->failed_pc=0x0c0902aau; return 0; }
r[0]=0x00000038u;
goto P_0c0902ac;
P_0c0902ac: /* original f28d, guest PC 0x0c0902ac */
if(!s->budget--) { s->failed_pc=0x0c0902acu; return 0; }
fr[2]=0;
goto P_0c0902ae;
P_0c0902ae: /* original f3f6, guest PC 0x0c0902ae */
if(!s->budget--) { s->failed_pc=0x0c0902aeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0902b0;
P_0c0902b0: /* original e03c, guest PC 0x0c0902b0 */
if(!s->budget--) { s->failed_pc=0x0c0902b0u; return 0; }
r[0]=0x0000003cu;
goto P_0c0902b2;
P_0c0902b2: /* original f4f6, guest PC 0x0c0902b2 */
if(!s->budget--) { s->failed_pc=0x0c0902b2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0902b4;
P_0c0902b4: /* original f431, guest PC 0x0c0902b4 */
if(!s->budget--) { s->failed_pc=0x0c0902b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0902b6;
P_0c0902b6: /* original f245, guest PC 0x0c0902b6 */
if(!s->budget--) { s->failed_pc=0x0c0902b6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0902b8;
P_0c0902b8: /* original 8f01, guest PC 0x0c0902b8 */
if(!s->budget--) { s->failed_pc=0x0c0902b8u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c0902be; }
goto P_0c0902bc;
P_0c0902ba: /* original f38d, guest PC 0x0c0902ba */
if(!s->budget--) { s->failed_pc=0x0c0902bau; return 0; }
fr[3]=0;
goto P_0c0902bc;
P_0c0902bc: /* original f65c, guest PC 0x0c0902bc */
if(!s->budget--) { s->failed_pc=0x0c0902bcu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0902be;
P_0c0902be: /* original f345, guest PC 0x0c0902be */
if(!s->budget--) { s->failed_pc=0x0c0902beu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0902c0;
P_0c0902c0: /* original 8902, guest PC 0x0c0902c0 */
if(!s->budget--) { s->failed_pc=0x0c0902c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0902c8; }
goto P_0c0902c2;
P_0c0902c2: /* original e03c, guest PC 0x0c0902c2 */
if(!s->budget--) { s->failed_pc=0x0c0902c2u; return 0; }
r[0]=0x0000003cu;
goto P_0c0902c4;
P_0c0902c4: /* original a002, guest PC 0x0c0902c4 */
if(!s->budget--) { s->failed_pc=0x0c0902c4u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0902cc;
P_0c0902c6: /* original f5f6, guest PC 0x0c0902c6 */
if(!s->budget--) { s->failed_pc=0x0c0902c6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0902c8;
P_0c0902c8: /* original e038, guest PC 0x0c0902c8 */
if(!s->budget--) { s->failed_pc=0x0c0902c8u; return 0; }
r[0]=0x00000038u;
goto P_0c0902ca;
P_0c0902ca: /* original f5f6, guest PC 0x0c0902ca */
if(!s->budget--) { s->failed_pc=0x0c0902cau; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0902cc;
P_0c0902cc: /* original f561, guest PC 0x0c0902cc */
if(!s->budget--) { s->failed_pc=0x0c0902ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0902ce;
P_0c0902ce: /* original f45d, guest PC 0x0c0902ce */
if(!s->budget--) { s->failed_pc=0x0c0902ceu; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c0902d0;
P_0c0902d0: /* original f24c, guest PC 0x0c0902d0 */
if(!s->budget--) { s->failed_pc=0x0c0902d0u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0902d2;
P_0c0902d2: /* original f38d, guest PC 0x0c0902d2 */
if(!s->budget--) { s->failed_pc=0x0c0902d2u; return 0; }
fr[3]=0;
goto P_0c0902d4;
P_0c0902d4: /* original f55d, guest PC 0x0c0902d4 */
if(!s->budget--) { s->failed_pc=0x0c0902d4u; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c0902d6;
P_0c0902d6: /* original f251, guest PC 0x0c0902d6 */
if(!s->budget--) { s->failed_pc=0x0c0902d6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0902d8;
P_0c0902d8: /* original f325, guest PC 0x0c0902d8 */
if(!s->budget--) { s->failed_pc=0x0c0902d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0902da;
P_0c0902da: /* original 890f, guest PC 0x0c0902da */
if(!s->budget--) { s->failed_pc=0x0c0902dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0902fc; }
goto P_0c0902dc;
P_0c0902dc: /* original a00f, guest PC 0x0c0902dc */
if(!s->budget--) { s->failed_pc=0x0c0902dcu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0902fe;
P_0c0902de: /* original f34c, guest PC 0x0c0902de */
if(!s->budget--) { s->failed_pc=0x0c0902deu; return 0; }
vf3_matrix_move(s,3,4);
return vf3_matrix_family(0x0c0902e0u,s,ram);
P_0c0902fc: /* original f35c, guest PC 0x0c0902fc */
if(!s->budget--) { s->failed_pc=0x0c0902fcu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0902fe;
P_0c0902fe: /* original e028, guest PC 0x0c0902fe */
if(!s->budget--) { s->failed_pc=0x0c0902feu; return 0; }
r[0]=0x00000028u;
goto P_0c090300;
P_0c090300: /* original ff37, guest PC 0x0c090300 */
if(!s->budget--) { s->failed_pc=0x0c090300u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090302;
P_0c090302: /* original 9093, guest PC 0x0c090302 */
if(!s->budget--) { s->failed_pc=0x0c090302u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09042cu,2);
goto P_0c090304;
P_0c090304: /* original 03ed, guest PC 0x0c090304 */
if(!s->budget--) { s->failed_pc=0x0c090304u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c090306;
P_0c090306: /* original c74c, guest PC 0x0c090306 */
if(!s->budget--) { s->failed_pc=0x0c090306u; return 0; }
r[0]=0x0c090438u;
goto P_0c090308;
P_0c090308: /* original f208, guest PC 0x0c090308 */
if(!s->budget--) { s->failed_pc=0x0c090308u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c09030a;
P_0c09030a: /* original 4321, guest PC 0x0c09030a */
if(!s->budget--) { s->failed_pc=0x0c09030au; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c09030c;
P_0c09030c: /* original 908f, guest PC 0x0c09030c */
if(!s->budget--) { s->failed_pc=0x0c09030cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09042eu,2);
goto P_0c09030e;
P_0c09030e: /* original 435a, guest PC 0x0c09030e */
if(!s->budget--) { s->failed_pc=0x0c09030eu; return 0; }
r[53]=r[3];
goto P_0c090310;
P_0c090310: /* original f32d, guest PC 0x0c090310 */
if(!s->budget--) { s->failed_pc=0x0c090310u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c090312;
P_0c090312: /* original f43c, guest PC 0x0c090312 */
if(!s->budget--) { s->failed_pc=0x0c090312u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c090314;
P_0c090314: /* original f422, guest PC 0x0c090314 */
if(!s->budget--) { s->failed_pc=0x0c090314u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c090316;
P_0c090316: /* original f3e6, guest PC 0x0c090316 */
if(!s->budget--) { s->failed_pc=0x0c090316u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090318;
P_0c090318: /* original ff3a, guest PC 0x0c090318 */
if(!s->budget--) { s->failed_pc=0x0c090318u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09031a;
P_0c09031a: /* original 9089, guest PC 0x0c09031a */
if(!s->budget--) { s->failed_pc=0x0c09031au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090430u,2);
goto P_0c09031c;
P_0c09031c: /* original f6e6, guest PC 0x0c09031c */
if(!s->budget--) { s->failed_pc=0x0c09031cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c09031e;
P_0c09031e: /* original 7008, guest PC 0x0c09031e */
if(!s->budget--) { s->failed_pc=0x0c09031eu; return 0; }
r[0]+=0x00000008u;
goto P_0c090320;
P_0c090320: /* original f3e6, guest PC 0x0c090320 */
if(!s->budget--) { s->failed_pc=0x0c090320u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090322;
P_0c090322: /* original e004, guest PC 0x0c090322 */
if(!s->budget--) { s->failed_pc=0x0c090322u; return 0; }
r[0]=0x00000004u;
goto P_0c090324;
P_0c090324: /* original ff37, guest PC 0x0c090324 */
if(!s->budget--) { s->failed_pc=0x0c090324u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090326;
P_0c090326: /* original f0f8, guest PC 0x0c090326 */
if(!s->budget--) { s->failed_pc=0x0c090326u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c090328;
P_0c090328: /* original f3fe, guest PC 0x0c090328 */
if(!s->budget--) { s->failed_pc=0x0c090328u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[15],fr[3],r[18]);
goto P_0c09032a;
P_0c09032a: /* original ff3a, guest PC 0x0c09032a */
if(!s->budget--) { s->failed_pc=0x0c09032au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09032c;
P_0c09032c: /* original f361, guest PC 0x0c09032c */
if(!s->budget--) { s->failed_pc=0x0c09032cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c09032e;
P_0c09032e: /* original f08d, guest PC 0x0c09032e */
if(!s->budget--) { s->failed_pc=0x0c09032eu; return 0; }
fr[0]=0;
goto P_0c090330;
P_0c090330: /* original f035, guest PC 0x0c090330 */
if(!s->budget--) { s->failed_pc=0x0c090330u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c090332;
P_0c090332: /* original 8d02, guest PC 0x0c090332 */
if(!s->budget--) { s->failed_pc=0x0c090332u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,4);
if(cond) { goto P_0c09033a; }
goto P_0c090336;
P_0c090334: /* original f54c, guest PC 0x0c090334 */
if(!s->budget--) { s->failed_pc=0x0c090334u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c090336;
P_0c090336: /* original a001, guest PC 0x0c090336 */
if(!s->budget--) { s->failed_pc=0x0c090336u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c09033c;
P_0c090338: /* original f16c, guest PC 0x0c090338 */
if(!s->budget--) { s->failed_pc=0x0c090338u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c09033a;
P_0c09033a: /* original f1f8, guest PC 0x0c09033a */
if(!s->budget--) { s->failed_pc=0x0c09033au; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c09033c;
P_0c09033c: /* original ff1a, guest PC 0x0c09033c */
if(!s->budget--) { s->failed_pc=0x0c09033cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c09033e;
P_0c09033e: /* original 9078, guest PC 0x0c09033e */
if(!s->budget--) { s->failed_pc=0x0c09033eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090432u,2);
goto P_0c090340;
P_0c090340: /* original f31c, guest PC 0x0c090340 */
if(!s->budget--) { s->failed_pc=0x0c090340u; return 0; }
vf3_matrix_move(s,3,1);
goto P_0c090342;
P_0c090342: /* original f432, guest PC 0x0c090342 */
if(!s->budget--) { s->failed_pc=0x0c090342u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c090344;
P_0c090344: /* original f3e6, guest PC 0x0c090344 */
if(!s->budget--) { s->failed_pc=0x0c090344u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090346;
P_0c090346: /* original ff3a, guest PC 0x0c090346 */
if(!s->budget--) { s->failed_pc=0x0c090346u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c090348;
P_0c090348: /* original 9074, guest PC 0x0c090348 */
if(!s->budget--) { s->failed_pc=0x0c090348u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090434u,2);
goto P_0c09034a;
P_0c09034a: /* original f6e6, guest PC 0x0c09034a */
if(!s->budget--) { s->failed_pc=0x0c09034au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c09034c;
P_0c09034c: /* original 7008, guest PC 0x0c09034c */
if(!s->budget--) { s->failed_pc=0x0c09034cu; return 0; }
r[0]+=0x00000008u;
goto P_0c09034e;
P_0c09034e: /* original f3e6, guest PC 0x0c09034e */
if(!s->budget--) { s->failed_pc=0x0c09034eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090350;
P_0c090350: /* original e004, guest PC 0x0c090350 */
if(!s->budget--) { s->failed_pc=0x0c090350u; return 0; }
r[0]=0x00000004u;
goto P_0c090352;
P_0c090352: /* original ff37, guest PC 0x0c090352 */
if(!s->budget--) { s->failed_pc=0x0c090352u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090354;
P_0c090354: /* original e028, guest PC 0x0c090354 */
if(!s->budget--) { s->failed_pc=0x0c090354u; return 0; }
r[0]=0x00000028u;
goto P_0c090356;
P_0c090356: /* original f2f6, guest PC 0x0c090356 */
if(!s->budget--) { s->failed_pc=0x0c090356u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c090358;
P_0c090358: /* original f0f8, guest PC 0x0c090358 */
if(!s->budget--) { s->failed_pc=0x0c090358u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c09035a;
P_0c09035a: /* original f32e, guest PC 0x0c09035a */
if(!s->budget--) { s->failed_pc=0x0c09035au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09035c;
P_0c09035c: /* original ff3a, guest PC 0x0c09035c */
if(!s->budget--) { s->failed_pc=0x0c09035cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09035e;
P_0c09035e: /* original f361, guest PC 0x0c09035e */
if(!s->budget--) { s->failed_pc=0x0c09035eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c090360;
P_0c090360: /* original f18d, guest PC 0x0c090360 */
if(!s->budget--) { s->failed_pc=0x0c090360u; return 0; }
fr[1]=0;
goto P_0c090362;
P_0c090362: /* original f135, guest PC 0x0c090362 */
if(!s->budget--) { s->failed_pc=0x0c090362u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[3]))!=0);
goto P_0c090364;
P_0c090364: /* original 8901, guest PC 0x0c090364 */
if(!s->budget--) { s->failed_pc=0x0c090364u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09036a; }
goto P_0c090366;
P_0c090366: /* original a001, guest PC 0x0c090366 */
if(!s->budget--) { s->failed_pc=0x0c090366u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c09036c;
P_0c090368: /* original f26c, guest PC 0x0c090368 */
if(!s->budget--) { s->failed_pc=0x0c090368u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c09036a;
P_0c09036a: /* original f2f8, guest PC 0x0c09036a */
if(!s->budget--) { s->failed_pc=0x0c09036au; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c09036c;
P_0c09036c: /* original c733, guest PC 0x0c09036c */
if(!s->budget--) { s->failed_pc=0x0c09036cu; return 0; }
r[0]=0x0c09043cu;
goto P_0c09036e;
P_0c09036e: /* original ff2a, guest PC 0x0c09036e */
if(!s->budget--) { s->failed_pc=0x0c09036eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c090370;
P_0c090370: /* original f32c, guest PC 0x0c090370 */
if(!s->budget--) { s->failed_pc=0x0c090370u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c090372;
P_0c090372: /* original f532, guest PC 0x0c090372 */
if(!s->budget--) { s->failed_pc=0x0c090372u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c090374;
P_0c090374: /* original f208, guest PC 0x0c090374 */
if(!s->budget--) { s->failed_pc=0x0c090374u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c090376;
P_0c090376: /* original e028, guest PC 0x0c090376 */
if(!s->budget--) { s->failed_pc=0x0c090376u; return 0; }
r[0]=0x00000028u;
goto P_0c090378;
P_0c090378: /* original ff2a, guest PC 0x0c090378 */
if(!s->budget--) { s->failed_pc=0x0c090378u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c09037a;
P_0c09037a: /* original f32c, guest PC 0x0c09037a */
if(!s->budget--) { s->failed_pc=0x0c09037au; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c09037c;
P_0c09037c: /* original ff32, guest PC 0x0c09037c */
if(!s->budget--) { s->failed_pc=0x0c09037cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c09037e;
P_0c09037e: /* original f2f6, guest PC 0x0c09037e */
if(!s->budget--) { s->failed_pc=0x0c09037eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c090380;
P_0c090380: /* original e028, guest PC 0x0c090380 */
if(!s->budget--) { s->failed_pc=0x0c090380u; return 0; }
r[0]=0x00000028u;
goto P_0c090382;
P_0c090382: /* original f232, guest PC 0x0c090382 */
if(!s->budget--) { s->failed_pc=0x0c090382u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c090384;
P_0c090384: /* original ff27, guest PC 0x0c090384 */
if(!s->budget--) { s->failed_pc=0x0c090384u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c090386;
P_0c090386: /* original c72e, guest PC 0x0c090386 */
if(!s->budget--) { s->failed_pc=0x0c090386u; return 0; }
r[0]=0x0c090440u;
goto P_0c090388;
P_0c090388: /* original f308, guest PC 0x0c090388 */
if(!s->budget--) { s->failed_pc=0x0c090388u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09038a;
P_0c09038a: /* original e04c, guest PC 0x0c09038a */
if(!s->budget--) { s->failed_pc=0x0c09038au; return 0; }
r[0]=0x0000004cu;
goto P_0c09038c;
P_0c09038c: /* original f432, guest PC 0x0c09038c */
if(!s->budget--) { s->failed_pc=0x0c09038cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c09038e;
P_0c09038e: /* original f532, guest PC 0x0c09038e */
if(!s->budget--) { s->failed_pc=0x0c09038eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c090390;
P_0c090390: /* original f43d, guest PC 0x0c090390 */
if(!s->budget--) { s->failed_pc=0x0c090390u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c090392;
P_0c090392: /* original 035a, guest PC 0x0c090392 */
if(!s->budget--) { s->failed_pc=0x0c090392u; return 0; }
r[3]=r[53];
goto P_0c090394;
P_0c090394: /* original f53d, guest PC 0x0c090394 */
if(!s->budget--) { s->failed_pc=0x0c090394u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c090396;
P_0c090396: /* original 0f35, guest PC 0x0c090396 */
if(!s->budget--) { s->failed_pc=0x0c090396u; return 0; }
write(ram,r[15]+r[0],r[3],2);
goto P_0c090398;
P_0c090398: /* original e048, guest PC 0x0c090398 */
if(!s->budget--) { s->failed_pc=0x0c090398u; return 0; }
r[0]=0x00000048u;
goto P_0c09039a;
P_0c09039a: /* original 025a, guest PC 0x0c09039a */
if(!s->budget--) { s->failed_pc=0x0c09039au; return 0; }
r[2]=r[53];
goto P_0c09039c;
P_0c09039c: /* original 0f25, guest PC 0x0c09039c */
if(!s->budget--) { s->failed_pc=0x0c09039cu; return 0; }
write(ram,r[15]+r[0],r[2],2);
goto P_0c09039e;
P_0c09039e: /* original d229, guest PC 0x0c09039e */
if(!s->budget--) { s->failed_pc=0x0c09039eu; return 0; }
r[2]=read(ram,0x0c090444u,4);
goto P_0c0903a0;
P_0c0903a0: /* original 420b, guest PC 0x0c0903a0 */
if(!s->budget--) { s->failed_pc=0x0c0903a0u; return 0; }
target=r[2];
r[16]=0x0c0903a4u;
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0903a4u) { target=s->pc; goto dispatch; }
goto P_0c0903a4;
P_0c0903a2: /* original 643f, guest PC 0x0c0903a2 */
if(!s->budget--) { s->failed_pc=0x0c0903a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0903a4;
P_0c0903a4: /* original e044, guest PC 0x0c0903a4 */
if(!s->budget--) { s->failed_pc=0x0c0903a4u; return 0; }
r[0]=0x00000044u;
goto P_0c0903a6;
P_0c0903a6: /* original ff07, guest PC 0x0c0903a6 */
if(!s->budget--) { s->failed_pc=0x0c0903a6u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0903a8;
P_0c0903a8: /* original e048, guest PC 0x0c0903a8 */
if(!s->budget--) { s->failed_pc=0x0c0903a8u; return 0; }
r[0]=0x00000048u;
goto P_0c0903aa;
P_0c0903aa: /* original d326, guest PC 0x0c0903aa */
if(!s->budget--) { s->failed_pc=0x0c0903aau; return 0; }
r[3]=read(ram,0x0c090444u,4);
goto P_0c0903ac;
P_0c0903ac: /* original 430b, guest PC 0x0c0903ac */
if(!s->budget--) { s->failed_pc=0x0c0903acu; return 0; }
target=r[3];
r[16]=0x0c0903b0u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0903b0u) { target=s->pc; goto dispatch; }
goto P_0c0903b0;
P_0c0903ae: /* original 04fd, guest PC 0x0c0903ae */
if(!s->budget--) { s->failed_pc=0x0c0903aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0903b0;
P_0c0903b0: /* original e044, guest PC 0x0c0903b0 */
if(!s->budget--) { s->failed_pc=0x0c0903b0u; return 0; }
r[0]=0x00000044u;
goto P_0c0903b2;
P_0c0903b2: /* original f40c, guest PC 0x0c0903b2 */
if(!s->budget--) { s->failed_pc=0x0c0903b2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0903b4;
P_0c0903b4: /* original f3f6, guest PC 0x0c0903b4 */
if(!s->budget--) { s->failed_pc=0x0c0903b4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0903b6;
P_0c0903b6: /* original e028, guest PC 0x0c0903b6 */
if(!s->budget--) { s->failed_pc=0x0c0903b6u; return 0; }
r[0]=0x00000028u;
goto P_0c0903b8;
P_0c0903b8: /* original ff33, guest PC 0x0c0903b8 */
if(!s->budget--) { s->failed_pc=0x0c0903b8u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'/');
goto P_0c0903ba;
P_0c0903ba: /* original fffa, guest PC 0x0c0903ba */
if(!s->budget--) { s->failed_pc=0x0c0903bau; return 0; }
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0903bc;
P_0c0903bc: /* original f24c, guest PC 0x0c0903bc */
if(!s->budget--) { s->failed_pc=0x0c0903bcu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0903be;
P_0c0903be: /* original f4f6, guest PC 0x0c0903be */
if(!s->budget--) { s->failed_pc=0x0c0903beu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0903c0;
P_0c0903c0: /* original e008, guest PC 0x0c0903c0 */
if(!s->budget--) { s->failed_pc=0x0c0903c0u; return 0; }
r[0]=0x00000008u;
goto P_0c0903c2;
P_0c0903c2: /* original f08d, guest PC 0x0c0903c2 */
if(!s->budget--) { s->failed_pc=0x0c0903c2u; return 0; }
fr[0]=0;
goto P_0c0903c4;
P_0c0903c4: /* original f423, guest PC 0x0c0903c4 */
if(!s->budget--) { s->failed_pc=0x0c0903c4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0903c6;
P_0c0903c6: /* original f2d6, guest PC 0x0c0903c6 */
if(!s->budget--) { s->failed_pc=0x0c0903c6u; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c0903c8;
P_0c0903c8: /* original e004, guest PC 0x0c0903c8 */
if(!s->budget--) { s->failed_pc=0x0c0903c8u; return 0; }
r[0]=0x00000004u;
goto P_0c0903ca;
P_0c0903ca: /* original f14c, guest PC 0x0c0903ca */
if(!s->budget--) { s->failed_pc=0x0c0903cau; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0903cc;
P_0c0903cc: /* original f121, guest PC 0x0c0903cc */
if(!s->budget--) { s->failed_pc=0x0c0903ccu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c0903ce;
P_0c0903ce: /* original f015, guest PC 0x0c0903ce */
if(!s->budget--) { s->failed_pc=0x0c0903ceu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[1]))!=0);
goto P_0c0903d0;
P_0c0903d0: /* original 8d01, guest PC 0x0c0903d0 */
if(!s->budget--) { s->failed_pc=0x0c0903d0u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[15]+r[0]);
if(cond) { goto P_0c0903d6; }
goto P_0c0903d4;
P_0c0903d2: /* original ff27, guest PC 0x0c0903d2 */
if(!s->budget--) { s->failed_pc=0x0c0903d2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0903d4;
P_0c0903d4: /* original f42c, guest PC 0x0c0903d4 */
if(!s->budget--) { s->failed_pc=0x0c0903d4u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0903d6;
P_0c0903d6: /* original 902e, guest PC 0x0c0903d6 */
if(!s->budget--) { s->failed_pc=0x0c0903d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090436u,2);
goto P_0c0903d8;
P_0c0903d8: /* original f3e6, guest PC 0x0c0903d8 */
if(!s->budget--) { s->failed_pc=0x0c0903d8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0903da;
P_0c0903da: /* original e004, guest PC 0x0c0903da */
if(!s->budget--) { s->failed_pc=0x0c0903dau; return 0; }
r[0]=0x00000004u;
goto P_0c0903dc;
P_0c0903dc: /* original ff37, guest PC 0x0c0903dc */
if(!s->budget--) { s->failed_pc=0x0c0903dcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0903de;
P_0c0903de: /* original e061, guest PC 0x0c0903de */
if(!s->budget--) { s->failed_pc=0x0c0903deu; return 0; }
r[0]=0x00000061u;
goto P_0c0903e0;
P_0c0903e0: /* original d519, guest PC 0x0c0903e0 */
if(!s->budget--) { s->failed_pc=0x0c0903e0u; return 0; }
r[5]=read(ram,0x0c090448u,4);
goto P_0c0903e2;
P_0c0903e2: /* original 5454, guest PC 0x0c0903e2 */
if(!s->budget--) { s->failed_pc=0x0c0903e2u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0903e4;
P_0c0903e4: /* original 004c, guest PC 0x0c0903e4 */
if(!s->budget--) { s->failed_pc=0x0c0903e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0903e6;
P_0c0903e6: /* original 600c, guest PC 0x0c0903e6 */
if(!s->budget--) { s->failed_pc=0x0c0903e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0903e8;
P_0c0903e8: /* original 880c, guest PC 0x0c0903e8 */
if(!s->budget--) { s->failed_pc=0x0c0903e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0903ea;
P_0c0903ea: /* original 8905, guest PC 0x0c0903ea */
if(!s->budget--) { s->failed_pc=0x0c0903eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0903f8; }
goto P_0c0903ec;
P_0c0903ec: /* original 5455, guest PC 0x0c0903ec */
if(!s->budget--) { s->failed_pc=0x0c0903ecu; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0903ee;
P_0c0903ee: /* original e061, guest PC 0x0c0903ee */
if(!s->budget--) { s->failed_pc=0x0c0903eeu; return 0; }
r[0]=0x00000061u;
goto P_0c0903f0;
P_0c0903f0: /* original 004c, guest PC 0x0c0903f0 */
if(!s->budget--) { s->failed_pc=0x0c0903f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0903f2;
P_0c0903f2: /* original 600c, guest PC 0x0c0903f2 */
if(!s->budget--) { s->failed_pc=0x0c0903f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0903f4;
P_0c0903f4: /* original 880c, guest PC 0x0c0903f4 */
if(!s->budget--) { s->failed_pc=0x0c0903f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0903f6;
P_0c0903f6: /* original 8b06, guest PC 0x0c0903f6 */
if(!s->budget--) { s->failed_pc=0x0c0903f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c090406; }
goto P_0c0903f8;
P_0c0903f8: /* original c714, guest PC 0x0c0903f8 */
if(!s->budget--) { s->failed_pc=0x0c0903f8u; return 0; }
r[0]=0x0c09044cu;
goto P_0c0903fa;
P_0c0903fa: /* original f308, guest PC 0x0c0903fa */
if(!s->budget--) { s->failed_pc=0x0c0903fau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0903fc;
P_0c0903fc: /* original e004, guest PC 0x0c0903fc */
if(!s->budget--) { s->failed_pc=0x0c0903fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0903fe;
P_0c0903fe: /* original f2f6, guest PC 0x0c0903fe */
if(!s->budget--) { s->failed_pc=0x0c0903feu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c090400;
P_0c090400: /* original e004, guest PC 0x0c090400 */
if(!s->budget--) { s->failed_pc=0x0c090400u; return 0; }
r[0]=0x00000004u;
goto P_0c090402;
P_0c090402: /* original f230, guest PC 0x0c090402 */
if(!s->budget--) { s->failed_pc=0x0c090402u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c090404;
P_0c090404: /* original ff27, guest PC 0x0c090404 */
if(!s->budget--) { s->failed_pc=0x0c090404u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c090406;
P_0c090406: /* original f2f8, guest PC 0x0c090406 */
if(!s->budget--) { s->failed_pc=0x0c090406u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c090408;
P_0c090408: /* original f38d, guest PC 0x0c090408 */
if(!s->budget--) { s->failed_pc=0x0c090408u; return 0; }
fr[3]=0;
goto P_0c09040a;
P_0c09040a: /* original f241, guest PC 0x0c09040a */
if(!s->budget--) { s->failed_pc=0x0c09040au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c09040c;
P_0c09040c: /* original f325, guest PC 0x0c09040c */
if(!s->budget--) { s->failed_pc=0x0c09040cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c09040e;
P_0c09040e: /* original 8901, guest PC 0x0c09040e */
if(!s->budget--) { s->failed_pc=0x0c09040eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c090414; }
goto P_0c090410;
P_0c090410: /* original a001, guest PC 0x0c090410 */
if(!s->budget--) { s->failed_pc=0x0c090410u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c090416;
P_0c090412: /* original f3f8, guest PC 0x0c090412 */
if(!s->budget--) { s->failed_pc=0x0c090412u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c090414;
P_0c090414: /* original f34c, guest PC 0x0c090414 */
if(!s->budget--) { s->failed_pc=0x0c090414u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c090416;
P_0c090416: /* original e00c, guest PC 0x0c090416 */
if(!s->budget--) { s->failed_pc=0x0c090416u; return 0; }
r[0]=0x0000000cu;
goto P_0c090418;
P_0c090418: /* original ff37, guest PC 0x0c090418 */
if(!s->budget--) { s->failed_pc=0x0c090418u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09041a;
P_0c09041a: /* original e004, guest PC 0x0c09041a */
if(!s->budget--) { s->failed_pc=0x0c09041au; return 0; }
r[0]=0x00000004u;
goto P_0c09041c;
P_0c09041c: /* original f2f6, guest PC 0x0c09041c */
if(!s->budget--) { s->failed_pc=0x0c09041cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09041e;
P_0c09041e: /* original f321, guest PC 0x0c09041e */
if(!s->budget--) { s->failed_pc=0x0c09041eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'-');
goto P_0c090420;
P_0c090420: /* original f28d, guest PC 0x0c090420 */
if(!s->budget--) { s->failed_pc=0x0c090420u; return 0; }
fr[2]=0;
goto P_0c090422;
P_0c090422: /* original f235, guest PC 0x0c090422 */
if(!s->budget--) { s->failed_pc=0x0c090422u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c090424;
P_0c090424: /* original 8914, guest PC 0x0c090424 */
if(!s->budget--) { s->failed_pc=0x0c090424u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c090450; }
goto P_0c090426;
P_0c090426: /* original e00c, guest PC 0x0c090426 */
if(!s->budget--) { s->failed_pc=0x0c090426u; return 0; }
r[0]=0x0000000cu;
goto P_0c090428;
P_0c090428: /* original a014, guest PC 0x0c090428 */
if(!s->budget--) { s->failed_pc=0x0c090428u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c090454;
P_0c09042a: /* original f2f6, guest PC 0x0c09042a */
if(!s->budget--) { s->failed_pc=0x0c09042au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
return vf3_matrix_family(0x0c09042cu,s,ram);
P_0c090450: /* original e004, guest PC 0x0c090450 */
if(!s->budget--) { s->failed_pc=0x0c090450u; return 0; }
r[0]=0x00000004u;
goto P_0c090452;
P_0c090452: /* original f2f6, guest PC 0x0c090452 */
if(!s->budget--) { s->failed_pc=0x0c090452u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c090454;
P_0c090454: /* original 66f3, guest PC 0x0c090454 */
if(!s->budget--) { s->failed_pc=0x0c090454u; return 0; }
r[6]=r[15];
goto P_0c090456;
P_0c090456: /* original 65f3, guest PC 0x0c090456 */
if(!s->budget--) { s->failed_pc=0x0c090456u; return 0; }
r[5]=r[15];
goto P_0c090458;
P_0c090458: /* original 67f3, guest PC 0x0c090458 */
if(!s->budget--) { s->failed_pc=0x0c090458u; return 0; }
r[7]=r[15];
goto P_0c09045a;
P_0c09045a: /* original e00c, guest PC 0x0c09045a */
if(!s->budget--) { s->failed_pc=0x0c09045au; return 0; }
r[0]=0x0000000cu;
goto P_0c09045c;
P_0c09045c: /* original 7504, guest PC 0x0c09045c */
if(!s->budget--) { s->failed_pc=0x0c09045cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09045e;
P_0c09045e: /* original 64f3, guest PC 0x0c09045e */
if(!s->budget--) { s->failed_pc=0x0c09045eu; return 0; }
r[4]=r[15];
goto P_0c090460;
P_0c090460: /* original ff27, guest PC 0x0c090460 */
if(!s->budget--) { s->failed_pc=0x0c090460u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c090462;
P_0c090462: /* original 7624, guest PC 0x0c090462 */
if(!s->budget--) { s->failed_pc=0x0c090462u; return 0; }
r[6]+=0x00000024u;
goto P_0c090464;
P_0c090464: /* original f5ec, guest PC 0x0c090464 */
if(!s->budget--) { s->failed_pc=0x0c090464u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c090466;
P_0c090466: /* original 7718, guest PC 0x0c090466 */
if(!s->budget--) { s->failed_pc=0x0c090466u; return 0; }
r[7]+=0x00000018u;
goto P_0c090468;
P_0c090468: /* original 4c0b, guest PC 0x0c090468 */
if(!s->budget--) { s->failed_pc=0x0c090468u; return 0; }
target=r[12];
r[16]=0x0c09046cu;
vf3_matrix_move(s,4,13);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09046cu) { target=s->pc; goto dispatch; }
goto P_0c09046c;
P_0c09046a: /* original f4dc, guest PC 0x0c09046a */
if(!s->budget--) { s->failed_pc=0x0c09046au; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c09046c;
P_0c09046c: /* original f4f8, guest PC 0x0c09046c */
if(!s->budget--) { s->failed_pc=0x0c09046cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c09046e;
P_0c09046e: /* original e004, guest PC 0x0c09046e */
if(!s->budget--) { s->failed_pc=0x0c09046eu; return 0; }
r[0]=0x00000004u;
goto P_0c090470;
P_0c090470: /* original f5f6, guest PC 0x0c090470 */
if(!s->budget--) { s->failed_pc=0x0c090470u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c090472;
P_0c090472: /* original c711, guest PC 0x0c090472 */
if(!s->budget--) { s->failed_pc=0x0c090472u; return 0; }
r[0]=0x0c0904b8u;
goto P_0c090474;
P_0c090474: /* original f4d1, guest PC 0x0c090474 */
if(!s->budget--) { s->failed_pc=0x0c090474u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c090476;
P_0c090476: /* original f208, guest PC 0x0c090476 */
if(!s->budget--) { s->failed_pc=0x0c090476u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c090478;
P_0c090478: /* original f5e1, guest PC 0x0c090478 */
if(!s->budget--) { s->failed_pc=0x0c090478u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c09047a;
P_0c09047a: /* original f34c, guest PC 0x0c09047a */
if(!s->budget--) { s->failed_pc=0x0c09047au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09047c;
P_0c09047c: /* original f432, guest PC 0x0c09047c */
if(!s->budget--) { s->failed_pc=0x0c09047cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c09047e;
P_0c09047e: /* original f05c, guest PC 0x0c09047e */
if(!s->budget--) { s->failed_pc=0x0c09047eu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c090480;
P_0c090480: /* original f45e, guest PC 0x0c090480 */
if(!s->budget--) { s->failed_pc=0x0c090480u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c090482;
P_0c090482: /* original f245, guest PC 0x0c090482 */
if(!s->budget--) { s->failed_pc=0x0c090482u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c090484;
P_0c090484: /* original 8b01, guest PC 0x0c090484 */
if(!s->budget--) { s->failed_pc=0x0c090484u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09048a; }
goto P_0c090486;
P_0c090486: /* original a002, guest PC 0x0c090486 */
if(!s->budget--) { s->failed_pc=0x0c090486u; return 0; }
fr[3]=0;
goto P_0c09048e;
P_0c090488: /* original f38d, guest PC 0x0c090488 */
if(!s->budget--) { s->failed_pc=0x0c090488u; return 0; }
fr[3]=0;
goto P_0c09048a;
P_0c09048a: /* original f34c, guest PC 0x0c09048a */
if(!s->budget--) { s->failed_pc=0x0c09048au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09048c;
P_0c09048c: /* original f37d, guest PC 0x0c09048c */
if(!s->budget--) { s->failed_pc=0x0c09048cu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c09048e;
P_0c09048e: /* original 9011, guest PC 0x0c09048e */
if(!s->budget--) { s->failed_pc=0x0c09048eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0904b4u,2);
goto P_0c090490;
P_0c090490: /* original f432, guest PC 0x0c090490 */
if(!s->budget--) { s->failed_pc=0x0c090490u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c090492;
P_0c090492: /* original f3e6, guest PC 0x0c090492 */
if(!s->budget--) { s->failed_pc=0x0c090492u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090494;
P_0c090494: /* original ff3a, guest PC 0x0c090494 */
if(!s->budget--) { s->failed_pc=0x0c090494u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c090496;
P_0c090496: /* original 900e, guest PC 0x0c090496 */
if(!s->budget--) { s->failed_pc=0x0c090496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0904b6u,2);
goto P_0c090498;
P_0c090498: /* original f5e6, guest PC 0x0c090498 */
if(!s->budget--) { s->failed_pc=0x0c090498u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c09049a;
P_0c09049a: /* original 7004, guest PC 0x0c09049a */
if(!s->budget--) { s->failed_pc=0x0c09049au; return 0; }
r[0]+=0x00000004u;
goto P_0c09049c;
P_0c09049c: /* original f3e6, guest PC 0x0c09049c */
if(!s->budget--) { s->failed_pc=0x0c09049cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09049e;
P_0c09049e: /* original e004, guest PC 0x0c09049e */
if(!s->budget--) { s->failed_pc=0x0c09049eu; return 0; }
r[0]=0x00000004u;
goto P_0c0904a0;
P_0c0904a0: /* original f35d, guest PC 0x0c0904a0 */
if(!s->budget--) { s->failed_pc=0x0c0904a0u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c0904a2;
P_0c0904a2: /* original f532, guest PC 0x0c0904a2 */
if(!s->budget--) { s->failed_pc=0x0c0904a2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0904a4;
P_0c0904a4: /* original ff37, guest PC 0x0c0904a4 */
if(!s->budget--) { s->failed_pc=0x0c0904a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0904a6;
P_0c0904a6: /* original f2f8, guest PC 0x0c0904a6 */
if(!s->budget--) { s->failed_pc=0x0c0904a6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0904a8;
P_0c0904a8: /* original f38d, guest PC 0x0c0904a8 */
if(!s->budget--) { s->failed_pc=0x0c0904a8u; return 0; }
fr[3]=0;
goto P_0c0904aa;
P_0c0904aa: /* original f241, guest PC 0x0c0904aa */
if(!s->budget--) { s->failed_pc=0x0c0904aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c0904ac;
P_0c0904ac: /* original f325, guest PC 0x0c0904ac */
if(!s->budget--) { s->failed_pc=0x0c0904acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0904ae;
P_0c0904ae: /* original 8905, guest PC 0x0c0904ae */
if(!s->budget--) { s->failed_pc=0x0c0904aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0904bc; }
goto P_0c0904b0;
P_0c0904b0: /* original a005, guest PC 0x0c0904b0 */
if(!s->budget--) { s->failed_pc=0x0c0904b0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0904be;
P_0c0904b2: /* original f34c, guest PC 0x0c0904b2 */
if(!s->budget--) { s->failed_pc=0x0c0904b2u; return 0; }
vf3_matrix_move(s,3,4);
return vf3_matrix_family(0x0c0904b4u,s,ram);
P_0c0904bc: /* original f3f8, guest PC 0x0c0904bc */
if(!s->budget--) { s->failed_pc=0x0c0904bcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0904be;
P_0c0904be: /* original e004, guest PC 0x0c0904be */
if(!s->budget--) { s->failed_pc=0x0c0904beu; return 0; }
r[0]=0x00000004u;
goto P_0c0904c0;
P_0c0904c0: /* original ff37, guest PC 0x0c0904c0 */
if(!s->budget--) { s->failed_pc=0x0c0904c0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0904c2;
P_0c0904c2: /* original e004, guest PC 0x0c0904c2 */
if(!s->budget--) { s->failed_pc=0x0c0904c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0904c4;
P_0c0904c4: /* original f2f8, guest PC 0x0c0904c4 */
if(!s->budget--) { s->failed_pc=0x0c0904c4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0904c6;
P_0c0904c6: /* original e304, guest PC 0x0c0904c6 */
if(!s->budget--) { s->failed_pc=0x0c0904c6u; return 0; }
r[3]=0x00000004u;
goto P_0c0904c8;
P_0c0904c8: /* original f231, guest PC 0x0c0904c8 */
if(!s->budget--) { s->failed_pc=0x0c0904c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0904ca;
P_0c0904ca: /* original ff27, guest PC 0x0c0904ca */
if(!s->budget--) { s->failed_pc=0x0c0904cau; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0904cc;
P_0c0904cc: /* original e00c, guest PC 0x0c0904cc */
if(!s->budget--) { s->failed_pc=0x0c0904ccu; return 0; }
r[0]=0x0000000cu;
goto P_0c0904ce;
P_0c0904ce: /* original f3f6, guest PC 0x0c0904ce */
if(!s->budget--) { s->failed_pc=0x0c0904ceu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0904d0;
P_0c0904d0: /* original e00c, guest PC 0x0c0904d0 */
if(!s->budget--) { s->failed_pc=0x0c0904d0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0904d2;
P_0c0904d2: /* original f02c, guest PC 0x0c0904d2 */
if(!s->budget--) { s->failed_pc=0x0c0904d2u; return 0; }
vf3_matrix_move(s,0,2);
goto P_0c0904d4;
P_0c0904d4: /* original f35e, guest PC 0x0c0904d4 */
if(!s->budget--) { s->failed_pc=0x0c0904d4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0904d6;
P_0c0904d6: /* original ff37, guest PC 0x0c0904d6 */
if(!s->budget--) { s->failed_pc=0x0c0904d6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0904d8;
P_0c0904d8: /* original 5cec, guest PC 0x0c0904d8 */
if(!s->budget--) { s->failed_pc=0x0c0904d8u; return 0; }
r[12]=read(ram,r[14]+48,4);
goto P_0c0904da;
P_0c0904da: /* original 23c8, guest PC 0x0c0904da */
if(!s->budget--) { s->failed_pc=0x0c0904dau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0904dc;
P_0c0904dc: /* original 8b02, guest PC 0x0c0904dc */
if(!s->budget--) { s->failed_pc=0x0c0904dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0904e4; }
goto P_0c0904de;
P_0c0904de: /* original e202, guest PC 0x0c0904de */
if(!s->budget--) { s->failed_pc=0x0c0904deu; return 0; }
r[2]=0x00000002u;
goto P_0c0904e0;
P_0c0904e0: /* original 22c8, guest PC 0x0c0904e0 */
if(!s->budget--) { s->failed_pc=0x0c0904e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c0904e2;
P_0c0904e2: /* original 8b07, guest PC 0x0c0904e2 */
if(!s->budget--) { s->failed_pc=0x0c0904e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0904f4; }
goto P_0c0904e4;
P_0c0904e4: /* original bbf1, guest PC 0x0c0904e4 */
if(!s->budget--) { s->failed_pc=0x0c0904e4u; return 0; }
target=0x0c08fccau; r[16]=0x0c0904e8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0904e8u) { target=s->pc; goto dispatch; }
goto P_0c0904e8;
P_0c0904e6: /* original 64e3, guest PC 0x0c0904e6 */
if(!s->budget--) { s->failed_pc=0x0c0904e6u; return 0; }
r[4]=r[14];
goto P_0c0904e8;
P_0c0904e8: /* original e00c, guest PC 0x0c0904e8 */
if(!s->budget--) { s->failed_pc=0x0c0904e8u; return 0; }
r[0]=0x0000000cu;
goto P_0c0904ea;
P_0c0904ea: /* original f40c, guest PC 0x0c0904ea */
if(!s->budget--) { s->failed_pc=0x0c0904eau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0904ec;
P_0c0904ec: /* original f3f6, guest PC 0x0c0904ec */
if(!s->budget--) { s->failed_pc=0x0c0904ecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0904ee;
P_0c0904ee: /* original e00c, guest PC 0x0c0904ee */
if(!s->budget--) { s->failed_pc=0x0c0904eeu; return 0; }
r[0]=0x0000000cu;
goto P_0c0904f0;
P_0c0904f0: /* original f432, guest PC 0x0c0904f0 */
if(!s->budget--) { s->failed_pc=0x0c0904f0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0904f2;
P_0c0904f2: /* original ff47, guest PC 0x0c0904f2 */
if(!s->budget--) { s->failed_pc=0x0c0904f2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0904f4;
P_0c0904f4: /* original 9085, guest PC 0x0c0904f4 */
if(!s->budget--) { s->failed_pc=0x0c0904f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090602u,2);
goto P_0c0904f6;
P_0c0904f6: /* original f3e6, guest PC 0x0c0904f6 */
if(!s->budget--) { s->failed_pc=0x0c0904f6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0904f8;
P_0c0904f8: /* original ff3a, guest PC 0x0c0904f8 */
if(!s->budget--) { s->failed_pc=0x0c0904f8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0904fa;
P_0c0904fa: /* original 9083, guest PC 0x0c0904fa */
if(!s->budget--) { s->failed_pc=0x0c0904fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090604u,2);
goto P_0c0904fc;
P_0c0904fc: /* original f4e6, guest PC 0x0c0904fc */
if(!s->budget--) { s->failed_pc=0x0c0904fcu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0904fe;
P_0c0904fe: /* original e004, guest PC 0x0c0904fe */
if(!s->budget--) { s->failed_pc=0x0c0904feu; return 0; }
r[0]=0x00000004u;
goto P_0c090500;
P_0c090500: /* original f3d6, guest PC 0x0c090500 */
if(!s->budget--) { s->failed_pc=0x0c090500u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c090502;
P_0c090502: /* original e004, guest PC 0x0c090502 */
if(!s->budget--) { s->failed_pc=0x0c090502u; return 0; }
r[0]=0x00000004u;
goto P_0c090504;
P_0c090504: /* original ff37, guest PC 0x0c090504 */
if(!s->budget--) { s->failed_pc=0x0c090504u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090506;
P_0c090506: /* original e00c, guest PC 0x0c090506 */
if(!s->budget--) { s->failed_pc=0x0c090506u; return 0; }
r[0]=0x0000000cu;
goto P_0c090508;
P_0c090508: /* original f2f6, guest PC 0x0c090508 */
if(!s->budget--) { s->failed_pc=0x0c090508u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09050a;
P_0c09050a: /* original f18d, guest PC 0x0c09050a */
if(!s->budget--) { s->failed_pc=0x0c09050au; return 0; }
fr[1]=0;
goto P_0c09050c;
P_0c09050c: /* original f231, guest PC 0x0c09050c */
if(!s->budget--) { s->failed_pc=0x0c09050cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c09050e;
P_0c09050e: /* original f125, guest PC 0x0c09050e */
if(!s->budget--) { s->failed_pc=0x0c09050eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c090510;
P_0c090510: /* original 8b01, guest PC 0x0c090510 */
if(!s->budget--) { s->failed_pc=0x0c090510u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c090516; }
goto P_0c090512;
P_0c090512: /* original e00c, guest PC 0x0c090512 */
if(!s->budget--) { s->failed_pc=0x0c090512u; return 0; }
r[0]=0x0000000cu;
goto P_0c090514;
P_0c090514: /* original f3f6, guest PC 0x0c090514 */
if(!s->budget--) { s->failed_pc=0x0c090514u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c090516;
P_0c090516: /* original e00c, guest PC 0x0c090516 */
if(!s->budget--) { s->failed_pc=0x0c090516u; return 0; }
r[0]=0x0000000cu;
goto P_0c090518;
P_0c090518: /* original ff37, guest PC 0x0c090518 */
if(!s->budget--) { s->failed_pc=0x0c090518u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09051a;
P_0c09051a: /* original e008, guest PC 0x0c09051a */
if(!s->budget--) { s->failed_pc=0x0c09051au; return 0; }
r[0]=0x00000008u;
goto P_0c09051c;
P_0c09051c: /* original f03c, guest PC 0x0c09051c */
if(!s->budget--) { s->failed_pc=0x0c09051cu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c09051e;
P_0c09051e: /* original e308, guest PC 0x0c09051e */
if(!s->budget--) { s->failed_pc=0x0c09051eu; return 0; }
r[3]=0x00000008u;
goto P_0c090520;
P_0c090520: /* original f3f8, guest PC 0x0c090520 */
if(!s->budget--) { s->failed_pc=0x0c090520u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c090522;
P_0c090522: /* original 23c8, guest PC 0x0c090522 */
if(!s->budget--) { s->failed_pc=0x0c090522u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c090524;
P_0c090524: /* original f43e, guest PC 0x0c090524 */
if(!s->budget--) { s->failed_pc=0x0c090524u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[3],fr[4],r[18]);
goto P_0c090526;
P_0c090526: /* original ff47, guest PC 0x0c090526 */
if(!s->budget--) { s->failed_pc=0x0c090526u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c090528;
P_0c090528: /* original e014, guest PC 0x0c090528 */
if(!s->budget--) { s->failed_pc=0x0c090528u; return 0; }
r[0]=0x00000014u;
goto P_0c09052a;
P_0c09052a: /* original f38d, guest PC 0x0c09052a */
if(!s->budget--) { s->failed_pc=0x0c09052au; return 0; }
fr[3]=0;
goto P_0c09052c;
P_0c09052c: /* original ff37, guest PC 0x0c09052c */
if(!s->budget--) { s->failed_pc=0x0c09052cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09052e;
P_0c09052e: /* original 906a, guest PC 0x0c09052e */
if(!s->budget--) { s->failed_pc=0x0c09052eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090606u,2);
goto P_0c090530;
P_0c090530: /* original f3e6, guest PC 0x0c090530 */
if(!s->budget--) { s->failed_pc=0x0c090530u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090532;
P_0c090532: /* original ff3a, guest PC 0x0c090532 */
if(!s->budget--) { s->failed_pc=0x0c090532u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c090534;
P_0c090534: /* original 9068, guest PC 0x0c090534 */
if(!s->budget--) { s->failed_pc=0x0c090534u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090608u,2);
goto P_0c090536;
P_0c090536: /* original f4e6, guest PC 0x0c090536 */
if(!s->budget--) { s->failed_pc=0x0c090536u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c090538;
P_0c090538: /* original 7064, guest PC 0x0c090538 */
if(!s->budget--) { s->failed_pc=0x0c090538u; return 0; }
r[0]+=0x00000064u;
goto P_0c09053a;
P_0c09053a: /* original f3e6, guest PC 0x0c09053a */
if(!s->budget--) { s->failed_pc=0x0c09053au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09053c;
P_0c09053c: /* original e004, guest PC 0x0c09053c */
if(!s->budget--) { s->failed_pc=0x0c09053cu; return 0; }
r[0]=0x00000004u;
goto P_0c09053e;
P_0c09053e: /* original ff37, guest PC 0x0c09053e */
if(!s->budget--) { s->failed_pc=0x0c09053eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090540;
P_0c090540: /* original c734, guest PC 0x0c090540 */
if(!s->budget--) { s->failed_pc=0x0c090540u; return 0; }
r[0]=0x0c090614u;
goto P_0c090542;
P_0c090542: /* original f1f8, guest PC 0x0c090542 */
if(!s->budget--) { s->failed_pc=0x0c090542u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c090544;
P_0c090544: /* original f432, guest PC 0x0c090544 */
if(!s->budget--) { s->failed_pc=0x0c090544u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c090546;
P_0c090546: /* original f208, guest PC 0x0c090546 */
if(!s->budget--) { s->failed_pc=0x0c090546u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c090548;
P_0c090548: /* original f122, guest PC 0x0c090548 */
if(!s->budget--) { s->failed_pc=0x0c090548u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c09054a;
P_0c09054a: /* original f13d, guest PC 0x0c09054a */
if(!s->budget--) { s->failed_pc=0x0c09054au; return 0; }
r[53]=truncate_float(fr[1]);
goto P_0c09054c;
P_0c09054c: /* original f14c, guest PC 0x0c09054c */
if(!s->budget--) { s->failed_pc=0x0c09054cu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c09054e;
P_0c09054e: /* original f122, guest PC 0x0c09054e */
if(!s->budget--) { s->failed_pc=0x0c09054eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c090550;
P_0c090550: /* original 085a, guest PC 0x0c090550 */
if(!s->budget--) { s->failed_pc=0x0c090550u; return 0; }
r[8]=r[53];
goto P_0c090552;
P_0c090552: /* original f13d, guest PC 0x0c090552 */
if(!s->budget--) { s->failed_pc=0x0c090552u; return 0; }
r[53]=truncate_float(fr[1]);
goto P_0c090554;
P_0c090554: /* original 8f01, guest PC 0x0c090554 */
if(!s->budget--) { s->failed_pc=0x0c090554u; return 0; }
cond=r[17]&1u;
r[4]=r[53];
if(!cond) { goto P_0c09055a; }
goto P_0c090558;
P_0c090556: /* original 045a, guest PC 0x0c090556 */
if(!s->budget--) { s->failed_pc=0x0c090556u; return 0; }
r[4]=r[53];
goto P_0c090558;
P_0c090558: /* original 644b, guest PC 0x0c090558 */
if(!s->budget--) { s->failed_pc=0x0c090558u; return 0; }
r[4]=0u-r[4];
goto P_0c09055a;
P_0c09055a: /* original e010, guest PC 0x0c09055a */
if(!s->budget--) { s->failed_pc=0x0c09055au; return 0; }
r[0]=0x00000010u;
goto P_0c09055c;
P_0c09055c: /* original 9355, guest PC 0x0c09055c */
if(!s->budget--) { s->failed_pc=0x0c09055cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09060au,2);
goto P_0c09055e;
P_0c09055e: /* original f3f6, guest PC 0x0c09055e */
if(!s->budget--) { s->failed_pc=0x0c09055eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c090560;
P_0c090560: /* original e040, guest PC 0x0c090560 */
if(!s->budget--) { s->failed_pc=0x0c090560u; return 0; }
r[0]=0x00000040u;
goto P_0c090562;
P_0c090562: /* original 384c, guest PC 0x0c090562 */
if(!s->budget--) { s->failed_pc=0x0c090562u; return 0; }
r[8]+=r[4];
goto P_0c090564;
P_0c090564: /* original 66f3, guest PC 0x0c090564 */
if(!s->budget--) { s->failed_pc=0x0c090564u; return 0; }
r[6]=r[15];
goto P_0c090566;
P_0c090566: /* original ff37, guest PC 0x0c090566 */
if(!s->budget--) { s->failed_pc=0x0c090566u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090568;
P_0c090568: /* original e008, guest PC 0x0c090568 */
if(!s->budget--) { s->failed_pc=0x0c090568u; return 0; }
r[0]=0x00000008u;
goto P_0c09056a;
P_0c09056a: /* original f3f6, guest PC 0x0c09056a */
if(!s->budget--) { s->failed_pc=0x0c09056au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09056c;
P_0c09056c: /* original 65f3, guest PC 0x0c09056c */
if(!s->budget--) { s->failed_pc=0x0c09056cu; return 0; }
r[5]=r[15];
goto P_0c09056e;
P_0c09056e: /* original e010, guest PC 0x0c09056e */
if(!s->budget--) { s->failed_pc=0x0c09056eu; return 0; }
r[0]=0x00000010u;
goto P_0c090570;
P_0c090570: /* original 283a, guest PC 0x0c090570 */
if(!s->budget--) { s->failed_pc=0x0c090570u; return 0; }
r[8]^=r[3];
goto P_0c090572;
P_0c090572: /* original ff37, guest PC 0x0c090572 */
if(!s->budget--) { s->failed_pc=0x0c090572u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090574;
P_0c090574: /* original d228, guest PC 0x0c090574 */
if(!s->budget--) { s->failed_pc=0x0c090574u; return 0; }
r[2]=read(ram,0x0c090618u,4);
goto P_0c090576;
P_0c090576: /* original 648f, guest PC 0x0c090576 */
if(!s->budget--) { s->failed_pc=0x0c090576u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[8];
goto P_0c090578;
P_0c090578: /* original 760c, guest PC 0x0c090578 */
if(!s->budget--) { s->failed_pc=0x0c090578u; return 0; }
r[6]+=0x0000000cu;
goto P_0c09057a;
P_0c09057a: /* original 7514, guest PC 0x0c09057a */
if(!s->budget--) { s->failed_pc=0x0c09057au; return 0; }
r[5]+=0x00000014u;
goto P_0c09057c;
P_0c09057c: /* original 420b, guest PC 0x0c09057c */
if(!s->budget--) { s->failed_pc=0x0c09057cu; return 0; }
target=r[2];
r[16]=0x0c090580u;
r[4]=0u-r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090580u) { target=s->pc; goto dispatch; }
goto P_0c090580;
P_0c09057e: /* original 644b, guest PC 0x0c09057e */
if(!s->budget--) { s->failed_pc=0x0c09057eu; return 0; }
r[4]=0u-r[4];
goto P_0c090580;
P_0c090580: /* original 9044, guest PC 0x0c090580 */
if(!s->budget--) { s->failed_pc=0x0c090580u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09060cu,2);
goto P_0c090582;
P_0c090582: /* original 2998, guest PC 0x0c090582 */
if(!s->budget--) { s->failed_pc=0x0c090582u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c090584;
P_0c090584: /* original f3e6, guest PC 0x0c090584 */
if(!s->budget--) { s->failed_pc=0x0c090584u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090586;
P_0c090586: /* original e008, guest PC 0x0c090586 */
if(!s->budget--) { s->failed_pc=0x0c090586u; return 0; }
r[0]=0x00000008u;
goto P_0c090588;
P_0c090588: /* original 8f0c, guest PC 0x0c090588 */
if(!s->budget--) { s->failed_pc=0x0c090588u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c0905a4; }
goto P_0c09058c;
P_0c09058a: /* original ff37, guest PC 0x0c09058a */
if(!s->budget--) { s->failed_pc=0x0c09058au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09058c;
P_0c09058c: /* original 903f, guest PC 0x0c09058c */
if(!s->budget--) { s->failed_pc=0x0c09058cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09060eu,2);
goto P_0c09058e;
P_0c09058e: /* original f3e6, guest PC 0x0c09058e */
if(!s->budget--) { s->failed_pc=0x0c09058eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c090590;
P_0c090590: /* original ff3a, guest PC 0x0c090590 */
if(!s->budget--) { s->failed_pc=0x0c090590u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c090592;
P_0c090592: /* original 903d, guest PC 0x0c090592 */
if(!s->budget--) { s->failed_pc=0x0c090592u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090610u,2);
goto P_0c090594;
P_0c090594: /* original f2f8, guest PC 0x0c090594 */
if(!s->budget--) { s->failed_pc=0x0c090594u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c090596;
P_0c090596: /* original f4e6, guest PC 0x0c090596 */
if(!s->budget--) { s->failed_pc=0x0c090596u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c090598;
P_0c090598: /* original e008, guest PC 0x0c090598 */
if(!s->budget--) { s->failed_pc=0x0c090598u; return 0; }
r[0]=0x00000008u;
goto P_0c09059a;
P_0c09059a: /* original f3f6, guest PC 0x0c09059a */
if(!s->budget--) { s->failed_pc=0x0c09059au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09059c;
P_0c09059c: /* original e008, guest PC 0x0c09059c */
if(!s->budget--) { s->failed_pc=0x0c09059cu; return 0; }
r[0]=0x00000008u;
goto P_0c09059e;
P_0c09059e: /* original f04c, guest PC 0x0c09059e */
if(!s->budget--) { s->failed_pc=0x0c09059eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0905a0;
P_0c0905a0: /* original f32e, guest PC 0x0c0905a0 */
if(!s->budget--) { s->failed_pc=0x0c0905a0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0905a2;
P_0c0905a2: /* original ff37, guest PC 0x0c0905a2 */
if(!s->budget--) { s->failed_pc=0x0c0905a2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0905a4;
P_0c0905a4: /* original e014, guest PC 0x0c0905a4 */
if(!s->budget--) { s->failed_pc=0x0c0905a4u; return 0; }
r[0]=0x00000014u;
goto P_0c0905a6;
P_0c0905a6: /* original 65f3, guest PC 0x0c0905a6 */
if(!s->budget--) { s->failed_pc=0x0c0905a6u; return 0; }
r[5]=r[15];
goto P_0c0905a8;
P_0c0905a8: /* original f3f6, guest PC 0x0c0905a8 */
if(!s->budget--) { s->failed_pc=0x0c0905a8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0905aa;
P_0c0905aa: /* original e014, guest PC 0x0c0905aa */
if(!s->budget--) { s->failed_pc=0x0c0905aau; return 0; }
r[0]=0x00000014u;
goto P_0c0905ac;
P_0c0905ac: /* original 66f3, guest PC 0x0c0905ac */
if(!s->budget--) { s->failed_pc=0x0c0905acu; return 0; }
r[6]=r[15];
goto P_0c0905ae;
P_0c0905ae: /* original 7508, guest PC 0x0c0905ae */
if(!s->budget--) { s->failed_pc=0x0c0905aeu; return 0; }
r[5]+=0x00000008u;
goto P_0c0905b0;
P_0c0905b0: /* original f3d0, guest PC 0x0c0905b0 */
if(!s->budget--) { s->failed_pc=0x0c0905b0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'+');
goto P_0c0905b2;
P_0c0905b2: /* original 7610, guest PC 0x0c0905b2 */
if(!s->budget--) { s->failed_pc=0x0c0905b2u; return 0; }
r[6]+=0x00000010u;
goto P_0c0905b4;
P_0c0905b4: /* original ff37, guest PC 0x0c0905b4 */
if(!s->budget--) { s->failed_pc=0x0c0905b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0905b6;
P_0c0905b6: /* original e010, guest PC 0x0c0905b6 */
if(!s->budget--) { s->failed_pc=0x0c0905b6u; return 0; }
r[0]=0x00000010u;
goto P_0c0905b8;
P_0c0905b8: /* original f2f6, guest PC 0x0c0905b8 */
if(!s->budget--) { s->failed_pc=0x0c0905b8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0905ba;
P_0c0905ba: /* original e008, guest PC 0x0c0905ba */
if(!s->budget--) { s->failed_pc=0x0c0905bau; return 0; }
r[0]=0x00000008u;
goto P_0c0905bc;
P_0c0905bc: /* original f1f6, guest PC 0x0c0905bc */
if(!s->budget--) { s->failed_pc=0x0c0905bcu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0905be;
P_0c0905be: /* original e008, guest PC 0x0c0905be */
if(!s->budget--) { s->failed_pc=0x0c0905beu; return 0; }
r[0]=0x00000008u;
goto P_0c0905c0;
P_0c0905c0: /* original f120, guest PC 0x0c0905c0 */
if(!s->budget--) { s->failed_pc=0x0c0905c0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c0905c2;
P_0c0905c2: /* original ff17, guest PC 0x0c0905c2 */
if(!s->budget--) { s->failed_pc=0x0c0905c2u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0905c4;
P_0c0905c4: /* original e00c, guest PC 0x0c0905c4 */
if(!s->budget--) { s->failed_pc=0x0c0905c4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0905c6;
P_0c0905c6: /* original f3f6, guest PC 0x0c0905c6 */
if(!s->budget--) { s->failed_pc=0x0c0905c6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0905c8;
P_0c0905c8: /* original e00c, guest PC 0x0c0905c8 */
if(!s->budget--) { s->failed_pc=0x0c0905c8u; return 0; }
r[0]=0x0000000cu;
goto P_0c0905ca;
P_0c0905ca: /* original f3e0, guest PC 0x0c0905ca */
if(!s->budget--) { s->failed_pc=0x0c0905cau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c0905cc;
P_0c0905cc: /* original ff37, guest PC 0x0c0905cc */
if(!s->budget--) { s->failed_pc=0x0c0905ccu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0905ce;
P_0c0905ce: /* original e014, guest PC 0x0c0905ce */
if(!s->budget--) { s->failed_pc=0x0c0905ceu; return 0; }
r[0]=0x00000014u;
goto P_0c0905d0;
P_0c0905d0: /* original f4f6, guest PC 0x0c0905d0 */
if(!s->budget--) { s->failed_pc=0x0c0905d0u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0905d2;
P_0c0905d2: /* original f53c, guest PC 0x0c0905d2 */
if(!s->budget--) { s->failed_pc=0x0c0905d2u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0905d4;
P_0c0905d4: /* original f7ec, guest PC 0x0c0905d4 */
if(!s->budget--) { s->failed_pc=0x0c0905d4u; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c0905d6;
P_0c0905d6: /* original f8cc, guest PC 0x0c0905d6 */
if(!s->budget--) { s->failed_pc=0x0c0905d6u; return 0; }
vf3_matrix_move(s,8,12);
goto P_0c0905d8;
P_0c0905d8: /* original f6dc, guest PC 0x0c0905d8 */
if(!s->budget--) { s->failed_pc=0x0c0905d8u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0905da;
P_0c0905da: /* original bc3a, guest PC 0x0c0905da */
if(!s->budget--) { s->failed_pc=0x0c0905dau; return 0; }
target=0x0c08fe52u; r[16]=0x0c0905deu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0905deu) { target=s->pc; goto dispatch; }
goto P_0c0905de;
P_0c0905dc: /* original 64e3, guest PC 0x0c0905dc */
if(!s->budget--) { s->failed_pc=0x0c0905dcu; return 0; }
r[4]=r[14];
goto P_0c0905de;
P_0c0905de: /* original e310, guest PC 0x0c0905de */
if(!s->budget--) { s->failed_pc=0x0c0905deu; return 0; }
r[3]=0x00000010u;
goto P_0c0905e0;
P_0c0905e0: /* original 23c8, guest PC 0x0c0905e0 */
if(!s->budget--) { s->failed_pc=0x0c0905e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0905e2;
P_0c0905e2: /* original 8f24, guest PC 0x0c0905e2 */
if(!s->budget--) { s->failed_pc=0x0c0905e2u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+24,r[0],4);
if(!cond) { goto P_0c09062e; }
goto P_0c0905e6;
P_0c0905e4: /* original 1f06, guest PC 0x0c0905e4 */
if(!s->budget--) { s->failed_pc=0x0c0905e4u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c0905e6;
P_0c0905e6: /* original 9011, guest PC 0x0c0905e6 */
if(!s->budget--) { s->failed_pc=0x0c0905e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09060cu,2);
goto P_0c0905e8;
P_0c0905e8: /* original f18d, guest PC 0x0c0905e8 */
if(!s->budget--) { s->failed_pc=0x0c0905e8u; return 0; }
fr[1]=0;
goto P_0c0905ea;
P_0c0905ea: /* original f5e6, guest PC 0x0c0905ea */
if(!s->budget--) { s->failed_pc=0x0c0905eau; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0905ec;
P_0c0905ec: /* original e010, guest PC 0x0c0905ec */
if(!s->budget--) { s->failed_pc=0x0c0905ecu; return 0; }
r[0]=0x00000010u;
goto P_0c0905ee;
P_0c0905ee: /* original f3f6, guest PC 0x0c0905ee */
if(!s->budget--) { s->failed_pc=0x0c0905eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0905f0;
P_0c0905f0: /* original e008, guest PC 0x0c0905f0 */
if(!s->budget--) { s->failed_pc=0x0c0905f0u; return 0; }
r[0]=0x00000008u;
goto P_0c0905f2;
P_0c0905f2: /* original f2f6, guest PC 0x0c0905f2 */
if(!s->budget--) { s->failed_pc=0x0c0905f2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0905f4;
P_0c0905f4: /* original f231, guest PC 0x0c0905f4 */
if(!s->budget--) { s->failed_pc=0x0c0905f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0905f6;
P_0c0905f6: /* original f125, guest PC 0x0c0905f6 */
if(!s->budget--) { s->failed_pc=0x0c0905f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c0905f8;
P_0c0905f8: /* original 8d10, guest PC 0x0c0905f8 */
if(!s->budget--) { s->failed_pc=0x0c0905f8u; return 0; }
cond=r[17]&1u;
fr[2]=0;
if(cond) { goto P_0c09061c; }
goto P_0c0905fc;
P_0c0905fa: /* original f28d, guest PC 0x0c0905fa */
if(!s->budget--) { s->failed_pc=0x0c0905fau; return 0; }
fr[2]=0;
goto P_0c0905fc;
P_0c0905fc: /* original e008, guest PC 0x0c0905fc */
if(!s->budget--) { s->failed_pc=0x0c0905fcu; return 0; }
r[0]=0x00000008u;
goto P_0c0905fe;
P_0c0905fe: /* original a00e, guest PC 0x0c0905fe */
if(!s->budget--) { s->failed_pc=0x0c0905feu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c09061e;
P_0c090600: /* original f4f6, guest PC 0x0c090600 */
if(!s->budget--) { s->failed_pc=0x0c090600u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
return vf3_matrix_family(0x0c090602u,s,ram);
P_0c09061c: /* original f43c, guest PC 0x0c09061c */
if(!s->budget--) { s->failed_pc=0x0c09061cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09061e;
P_0c09061e: /* original f255, guest PC 0x0c09061e */
if(!s->budget--) { s->failed_pc=0x0c09061eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[5]))!=0);
goto P_0c090620;
P_0c090620: /* original 8901, guest PC 0x0c090620 */
if(!s->budget--) { s->failed_pc=0x0c090620u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c090626; }
goto P_0c090622;
P_0c090622: /* original a002, guest PC 0x0c090622 */
if(!s->budget--) { s->failed_pc=0x0c090622u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09062a;
P_0c090624: /* original f34c, guest PC 0x0c090624 */
if(!s->budget--) { s->failed_pc=0x0c090624u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c090626;
P_0c090626: /* original e008, guest PC 0x0c090626 */
if(!s->budget--) { s->failed_pc=0x0c090626u; return 0; }
r[0]=0x00000008u;
goto P_0c090628;
P_0c090628: /* original f3f6, guest PC 0x0c090628 */
if(!s->budget--) { s->failed_pc=0x0c090628u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09062a;
P_0c09062a: /* original e008, guest PC 0x0c09062a */
if(!s->budget--) { s->failed_pc=0x0c09062au; return 0; }
r[0]=0x00000008u;
goto P_0c09062c;
P_0c09062c: /* original ff37, guest PC 0x0c09062c */
if(!s->budget--) { s->failed_pc=0x0c09062cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09062e;
P_0c09062e: /* original e301, guest PC 0x0c09062e */
if(!s->budget--) { s->failed_pc=0x0c09062eu; return 0; }
r[3]=0x00000001u;
goto P_0c090630;
P_0c090630: /* original 2c38, guest PC 0x0c090630 */
if(!s->budget--) { s->failed_pc=0x0c090630u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c090632;
P_0c090632: /* original 8b0b, guest PC 0x0c090632 */
if(!s->budget--) { s->failed_pc=0x0c090632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09064c; }
goto P_0c090634;
P_0c090634: /* original 2aa8, guest PC 0x0c090634 */
if(!s->budget--) { s->failed_pc=0x0c090634u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c090636;
P_0c090636: /* original 8b09, guest PC 0x0c090636 */
if(!s->budget--) { s->failed_pc=0x0c090636u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09064c; }
goto P_0c090638;
P_0c090638: /* original 60b3, guest PC 0x0c090638 */
if(!s->budget--) { s->failed_pc=0x0c090638u; return 0; }
r[0]=r[11];
goto P_0c09063a;
P_0c09063a: /* original 8804, guest PC 0x0c09063a */
if(!s->budget--) { s->failed_pc=0x0c09063au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c09063c;
P_0c09063c: /* original 8906, guest PC 0x0c09063c */
if(!s->budget--) { s->failed_pc=0x0c09063cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09064c; }
goto P_0c09063e;
P_0c09063e: /* original 60b3, guest PC 0x0c09063e */
if(!s->budget--) { s->failed_pc=0x0c09063eu; return 0; }
r[0]=r[11];
goto P_0c090640;
P_0c090640: /* original 8807, guest PC 0x0c090640 */
if(!s->budget--) { s->failed_pc=0x0c090640u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c090642;
P_0c090642: /* original 8903, guest PC 0x0c090642 */
if(!s->budget--) { s->failed_pc=0x0c090642u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09064c; }
goto P_0c090644;
P_0c090644: /* original e040, guest PC 0x0c090644 */
if(!s->budget--) { s->failed_pc=0x0c090644u; return 0; }
r[0]=0x00000040u;
goto P_0c090646;
P_0c090646: /* original f3f6, guest PC 0x0c090646 */
if(!s->budget--) { s->failed_pc=0x0c090646u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c090648;
P_0c090648: /* original e010, guest PC 0x0c090648 */
if(!s->budget--) { s->failed_pc=0x0c090648u; return 0; }
r[0]=0x00000010u;
goto P_0c09064a;
P_0c09064a: /* original ff37, guest PC 0x0c09064a */
if(!s->budget--) { s->failed_pc=0x0c09064au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09064c;
P_0c09064c: /* original e010, guest PC 0x0c09064c */
if(!s->budget--) { s->failed_pc=0x0c09064cu; return 0; }
r[0]=0x00000010u;
goto P_0c09064e;
P_0c09064e: /* original f3f6, guest PC 0x0c09064e */
if(!s->budget--) { s->failed_pc=0x0c09064eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c090650;
P_0c090650: /* original e008, guest PC 0x0c090650 */
if(!s->budget--) { s->failed_pc=0x0c090650u; return 0; }
r[0]=0x00000008u;
goto P_0c090652;
P_0c090652: /* original f2f6, guest PC 0x0c090652 */
if(!s->budget--) { s->failed_pc=0x0c090652u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c090654;
P_0c090654: /* original e00c, guest PC 0x0c090654 */
if(!s->budget--) { s->failed_pc=0x0c090654u; return 0; }
r[0]=0x0000000cu;
goto P_0c090656;
P_0c090656: /* original f231, guest PC 0x0c090656 */
if(!s->budget--) { s->failed_pc=0x0c090656u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c090658;
P_0c090658: /* original ff2a, guest PC 0x0c090658 */
if(!s->budget--) { s->failed_pc=0x0c090658u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c09065a;
P_0c09065a: /* original f4d6, guest PC 0x0c09065a */
if(!s->budget--) { s->failed_pc=0x0c09065au; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c09065c;
P_0c09065c: /* original f14c, guest PC 0x0c09065c */
if(!s->budget--) { s->failed_pc=0x0c09065cu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c09065e;
P_0c09065e: /* original f121, guest PC 0x0c09065e */
if(!s->budget--) { s->failed_pc=0x0c09065eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c090660;
P_0c090660: /* original f28d, guest PC 0x0c090660 */
if(!s->budget--) { s->failed_pc=0x0c090660u; return 0; }
fr[2]=0;
goto P_0c090662;
P_0c090662: /* original f215, guest PC 0x0c090662 */
if(!s->budget--) { s->failed_pc=0x0c090662u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[1]))!=0);
goto P_0c090664;
P_0c090664: /* original 8900, guest PC 0x0c090664 */
if(!s->budget--) { s->failed_pc=0x0c090664u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c090668; }
goto P_0c090666;
P_0c090666: /* original f4f8, guest PC 0x0c090666 */
if(!s->budget--) { s->failed_pc=0x0c090666u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c090668;
P_0c090668: /* original e008, guest PC 0x0c090668 */
if(!s->budget--) { s->failed_pc=0x0c090668u; return 0; }
r[0]=0x00000008u;
goto P_0c09066a;
P_0c09066a: /* original f3f6, guest PC 0x0c09066a */
if(!s->budget--) { s->failed_pc=0x0c09066au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09066c;
P_0c09066c: /* original e010, guest PC 0x0c09066c */
if(!s->budget--) { s->failed_pc=0x0c09066cu; return 0; }
r[0]=0x00000010u;
goto P_0c09066e;
P_0c09066e: /* original f341, guest PC 0x0c09066e */
if(!s->budget--) { s->failed_pc=0x0c09066eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c090670;
P_0c090670: /* original ff37, guest PC 0x0c090670 */
if(!s->budget--) { s->failed_pc=0x0c090670u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c090672;
P_0c090672: /* original e014, guest PC 0x0c090672 */
if(!s->budget--) { s->failed_pc=0x0c090672u; return 0; }
r[0]=0x00000014u;
goto P_0c090674;
P_0c090674: /* original f3f6, guest PC 0x0c090674 */
if(!s->budget--) { s->failed_pc=0x0c090674u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c090676;
P_0c090676: /* original 905c, guest PC 0x0c090676 */
if(!s->budget--) { s->failed_pc=0x0c090676u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090732u,2);
goto P_0c090678;
P_0c090678: /* original fe37, guest PC 0x0c090678 */
if(!s->budget--) { s->failed_pc=0x0c090678u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09067a;
P_0c09067a: /* original e008, guest PC 0x0c09067a */
if(!s->budget--) { s->failed_pc=0x0c09067au; return 0; }
r[0]=0x00000008u;
goto P_0c09067c;
P_0c09067c: /* original f3f6, guest PC 0x0c09067c */
if(!s->budget--) { s->failed_pc=0x0c09067cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09067e;
P_0c09067e: /* original 9059, guest PC 0x0c09067e */
if(!s->budget--) { s->failed_pc=0x0c09067eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090734u,2);
goto P_0c090680;
P_0c090680: /* original fe37, guest PC 0x0c090680 */
if(!s->budget--) { s->failed_pc=0x0c090680u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c090682;
P_0c090682: /* original e00c, guest PC 0x0c090682 */
if(!s->budget--) { s->failed_pc=0x0c090682u; return 0; }
r[0]=0x0000000cu;
goto P_0c090684;
P_0c090684: /* original f3f6, guest PC 0x0c090684 */
if(!s->budget--) { s->failed_pc=0x0c090684u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c090686;
P_0c090686: /* original 9056, guest PC 0x0c090686 */
if(!s->budget--) { s->failed_pc=0x0c090686u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090736u,2);
goto P_0c090688;
P_0c090688: /* original fe37, guest PC 0x0c090688 */
if(!s->budget--) { s->failed_pc=0x0c090688u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09068a;
P_0c09068a: /* original 7040, guest PC 0x0c09068a */
if(!s->budget--) { s->failed_pc=0x0c09068au; return 0; }
r[0]+=0x00000040u;
goto P_0c09068c;
P_0c09068c: /* original fed7, guest PC 0x0c09068c */
if(!s->budget--) { s->failed_pc=0x0c09068cu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c09068e;
P_0c09068e: /* original e010, guest PC 0x0c09068e */
if(!s->budget--) { s->failed_pc=0x0c09068eu; return 0; }
r[0]=0x00000010u;
goto P_0c090690;
P_0c090690: /* original f3f6, guest PC 0x0c090690 */
if(!s->budget--) { s->failed_pc=0x0c090690u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c090692;
P_0c090692: /* original 7f58, guest PC 0x0c090692 */
if(!s->budget--) { s->failed_pc=0x0c090692u; return 0; }
r[15]+=0x00000058u;
goto P_0c090694;
P_0c090694: /* original 4f26, guest PC 0x0c090694 */
if(!s->budget--) { s->failed_pc=0x0c090694u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c090696;
P_0c090696: /* original 904f, guest PC 0x0c090696 */
if(!s->budget--) { s->failed_pc=0x0c090696u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c090738u,2);
goto P_0c090698;
P_0c090698: /* original fe37, guest PC 0x0c090698 */
if(!s->budget--) { s->failed_pc=0x0c090698u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09069a;
P_0c09069a: /* original 7004, guest PC 0x0c09069a */
if(!s->budget--) { s->failed_pc=0x0c09069au; return 0; }
r[0]+=0x00000004u;
goto P_0c09069c;
P_0c09069c: /* original fee7, guest PC 0x0c09069c */
if(!s->budget--) { s->failed_pc=0x0c09069cu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c09069e;
P_0c09069e: /* original fcf9, guest PC 0x0c09069e */
if(!s->budget--) { s->failed_pc=0x0c09069eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0906a0;
P_0c0906a0: /* original fdf9, guest PC 0x0c0906a0 */
if(!s->budget--) { s->failed_pc=0x0c0906a0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0906a2;
P_0c0906a2: /* original fef9, guest PC 0x0c0906a2 */
if(!s->budget--) { s->failed_pc=0x0c0906a2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0906a4;
P_0c0906a4: /* original fff9, guest PC 0x0c0906a4 */
if(!s->budget--) { s->failed_pc=0x0c0906a4u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0906a6;
P_0c0906a6: /* original 68f6, guest PC 0x0c0906a6 */
if(!s->budget--) { s->failed_pc=0x0c0906a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0906a8;
P_0c0906a8: /* original 69f6, guest PC 0x0c0906a8 */
if(!s->budget--) { s->failed_pc=0x0c0906a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0906aa;
P_0c0906aa: /* original 6af6, guest PC 0x0c0906aa */
if(!s->budget--) { s->failed_pc=0x0c0906aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0906ac;
P_0c0906ac: /* original 6bf6, guest PC 0x0c0906ac */
if(!s->budget--) { s->failed_pc=0x0c0906acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0906ae;
P_0c0906ae: /* original 6cf6, guest PC 0x0c0906ae */
if(!s->budget--) { s->failed_pc=0x0c0906aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0906b0;
P_0c0906b0: /* original 6df6, guest PC 0x0c0906b0 */
if(!s->budget--) { s->failed_pc=0x0c0906b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0906b2;
P_0c0906b2: /* original 000b, guest PC 0x0c0906b2 */
if(!s->budget--) { s->failed_pc=0x0c0906b2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0906b4: /* original 6ef6, guest PC 0x0c0906b4 */
if(!s->budget--) { s->failed_pc=0x0c0906b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0906b6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c090000u,0x0c090002u,0x0c090004u,0x0c090006u,0x0c090008u,0x0c09000au,0x0c09000cu,0x0c09000eu,0x0c090010u,0x0c090012u,0x0c090014u,0x0c090016u,0x0c090018u,0x0c09001au,0x0c09001cu,0x0c09001eu,
0x0c090020u,0x0c090022u,0x0c090024u,0x0c090026u,0x0c090028u,0x0c09002au,0x0c09002cu,0x0c09002eu,0x0c090030u,0x0c090032u,0x0c090034u,0x0c090036u,0x0c090038u,0x0c09003au,0x0c09003cu,0x0c09003eu,
0x0c090040u,0x0c090042u,0x0c090044u,0x0c090046u,0x0c090048u,0x0c09004au,0x0c09004cu,0x0c09004eu,0x0c090050u,0x0c090052u,0x0c090054u,0x0c090056u,0x0c090058u,0x0c09005au,0x0c09005cu,0x0c09005eu,
0x0c090060u,0x0c090062u,0x0c090064u,0x0c090066u,0x0c090068u,0x0c09006au,0x0c09006cu,0x0c09006eu,0x0c090070u,0x0c090072u,0x0c090074u,0x0c090076u,0x0c090078u,0x0c09007au,0x0c09007cu,0x0c09007eu,
0x0c090080u,0x0c090082u,0x0c090084u,0x0c090086u,0x0c090088u,0x0c09008au,0x0c09008cu,0x0c09008eu,0x0c090090u,0x0c090092u,0x0c090094u,0x0c090096u,0x0c090098u,0x0c09009au,0x0c09009cu,0x0c09009eu,
0x0c0900a0u,0x0c0900a2u,0x0c0900a4u,0x0c0900a6u,0x0c0900a8u,0x0c0900aau,0x0c0900acu,0x0c0900aeu,0x0c0900b0u,0x0c0900b2u,0x0c0900b4u,0x0c0900b6u,0x0c0900b8u,0x0c0900bau,0x0c0900bcu,0x0c0900beu,
0x0c0900c0u,0x0c0900c2u,0x0c0900c4u,0x0c0900c6u,0x0c0900c8u,0x0c0900cau,0x0c0900ccu,0x0c0900ceu,0x0c0900d0u,0x0c0900d2u,0x0c0900d4u,0x0c0900d6u,0x0c0900d8u,0x0c0900dau,0x0c0900f4u,0x0c0900f6u,
0x0c0900f8u,0x0c0900fau,0x0c0900fcu,0x0c0900feu,0x0c090100u,0x0c090102u,0x0c090104u,0x0c090106u,0x0c090108u,0x0c09010au,0x0c09010cu,0x0c09010eu,0x0c090110u,0x0c090112u,0x0c090114u,0x0c090116u,
0x0c090118u,0x0c09011au,0x0c09011cu,0x0c09011eu,0x0c090120u,0x0c090122u,0x0c090124u,0x0c090126u,0x0c090128u,0x0c09012au,0x0c09012cu,0x0c09012eu,0x0c090130u,0x0c090132u,0x0c090134u,0x0c090136u,
0x0c090138u,0x0c09013au,0x0c09013cu,0x0c09013eu,0x0c090140u,0x0c090142u,0x0c090144u,0x0c090146u,0x0c090148u,0x0c09014au,0x0c09014cu,0x0c09014eu,0x0c090150u,0x0c090152u,0x0c090154u,0x0c090156u,
0x0c090158u,0x0c09015au,0x0c09015cu,0x0c09015eu,0x0c090160u,0x0c090162u,0x0c090164u,0x0c090166u,0x0c090168u,0x0c09016au,0x0c09016cu,0x0c09016eu,0x0c090170u,0x0c090172u,0x0c090174u,0x0c090176u,
0x0c090178u,0x0c09017au,0x0c09017cu,0x0c09017eu,0x0c090180u,0x0c090182u,0x0c090184u,0x0c090186u,0x0c090188u,0x0c09018au,0x0c09018cu,0x0c09018eu,0x0c090190u,0x0c090192u,0x0c090194u,0x0c090196u,
0x0c090198u,0x0c0901a4u,0x0c0901a6u,0x0c0901a8u,0x0c0901aau,0x0c0901acu,0x0c0901aeu,0x0c0901b0u,0x0c0901b2u,0x0c0901b4u,0x0c0901b6u,0x0c0901b8u,0x0c0901bau,0x0c0901bcu,0x0c0901beu,0x0c0901c0u,
0x0c0901c2u,0x0c0901c4u,0x0c0901c6u,0x0c0901c8u,0x0c0901cau,0x0c0901ccu,0x0c0901ceu,0x0c0901d0u,0x0c0901d2u,0x0c0901d4u,0x0c0901d6u,0x0c0901d8u,0x0c0901dau,0x0c0901dcu,0x0c0901deu,0x0c0901e0u,
0x0c0901e2u,0x0c0901e4u,0x0c0901e6u,0x0c0901e8u,0x0c0901eau,0x0c0901ecu,0x0c0901eeu,0x0c0901f0u,0x0c0901f2u,0x0c0901f4u,0x0c0901f6u,0x0c0901f8u,0x0c0901fau,0x0c0901fcu,0x0c0901feu,0x0c090200u,
0x0c090202u,0x0c090204u,0x0c090206u,0x0c090208u,0x0c09020au,0x0c09020cu,0x0c09020eu,0x0c090210u,0x0c090212u,0x0c090214u,0x0c090216u,0x0c090218u,0x0c09021au,0x0c09021cu,0x0c09021eu,0x0c090220u,
0x0c090222u,0x0c090224u,0x0c090226u,0x0c090228u,0x0c09022au,0x0c09022cu,0x0c09022eu,0x0c090230u,0x0c090232u,0x0c090234u,0x0c090236u,0x0c090238u,0x0c09023au,0x0c09023cu,0x0c09023eu,0x0c090240u,
0x0c090242u,0x0c090244u,0x0c090246u,0x0c090248u,0x0c09024au,0x0c09024cu,0x0c09024eu,0x0c090250u,0x0c090252u,0x0c090254u,0x0c090256u,0x0c090258u,0x0c09025au,0x0c09025cu,0x0c09025eu,0x0c090260u,
0x0c090262u,0x0c090264u,0x0c090266u,0x0c090268u,0x0c09026au,0x0c09026cu,0x0c09026eu,0x0c090270u,0x0c090272u,0x0c090274u,0x0c090276u,0x0c090278u,0x0c09027au,0x0c09027cu,0x0c09027eu,0x0c090280u,
0x0c090282u,0x0c090284u,0x0c090286u,0x0c090288u,0x0c09028au,0x0c09028cu,0x0c09028eu,0x0c090290u,0x0c090292u,0x0c090294u,0x0c090296u,0x0c090298u,0x0c09029au,0x0c09029cu,0x0c09029eu,0x0c0902a0u,
0x0c0902a2u,0x0c0902a4u,0x0c0902a6u,0x0c0902a8u,0x0c0902aau,0x0c0902acu,0x0c0902aeu,0x0c0902b0u,0x0c0902b2u,0x0c0902b4u,0x0c0902b6u,0x0c0902b8u,0x0c0902bau,0x0c0902bcu,0x0c0902beu,0x0c0902c0u,
0x0c0902c2u,0x0c0902c4u,0x0c0902c6u,0x0c0902c8u,0x0c0902cau,0x0c0902ccu,0x0c0902ceu,0x0c0902d0u,0x0c0902d2u,0x0c0902d4u,0x0c0902d6u,0x0c0902d8u,0x0c0902dau,0x0c0902dcu,0x0c0902deu,0x0c0902fcu,
0x0c0902feu,0x0c090300u,0x0c090302u,0x0c090304u,0x0c090306u,0x0c090308u,0x0c09030au,0x0c09030cu,0x0c09030eu,0x0c090310u,0x0c090312u,0x0c090314u,0x0c090316u,0x0c090318u,0x0c09031au,0x0c09031cu,
0x0c09031eu,0x0c090320u,0x0c090322u,0x0c090324u,0x0c090326u,0x0c090328u,0x0c09032au,0x0c09032cu,0x0c09032eu,0x0c090330u,0x0c090332u,0x0c090334u,0x0c090336u,0x0c090338u,0x0c09033au,0x0c09033cu,
0x0c09033eu,0x0c090340u,0x0c090342u,0x0c090344u,0x0c090346u,0x0c090348u,0x0c09034au,0x0c09034cu,0x0c09034eu,0x0c090350u,0x0c090352u,0x0c090354u,0x0c090356u,0x0c090358u,0x0c09035au,0x0c09035cu,
0x0c09035eu,0x0c090360u,0x0c090362u,0x0c090364u,0x0c090366u,0x0c090368u,0x0c09036au,0x0c09036cu,0x0c09036eu,0x0c090370u,0x0c090372u,0x0c090374u,0x0c090376u,0x0c090378u,0x0c09037au,0x0c09037cu,
0x0c09037eu,0x0c090380u,0x0c090382u,0x0c090384u,0x0c090386u,0x0c090388u,0x0c09038au,0x0c09038cu,0x0c09038eu,0x0c090390u,0x0c090392u,0x0c090394u,0x0c090396u,0x0c090398u,0x0c09039au,0x0c09039cu,
0x0c09039eu,0x0c0903a0u,0x0c0903a2u,0x0c0903a4u,0x0c0903a6u,0x0c0903a8u,0x0c0903aau,0x0c0903acu,0x0c0903aeu,0x0c0903b0u,0x0c0903b2u,0x0c0903b4u,0x0c0903b6u,0x0c0903b8u,0x0c0903bau,0x0c0903bcu,
0x0c0903beu,0x0c0903c0u,0x0c0903c2u,0x0c0903c4u,0x0c0903c6u,0x0c0903c8u,0x0c0903cau,0x0c0903ccu,0x0c0903ceu,0x0c0903d0u,0x0c0903d2u,0x0c0903d4u,0x0c0903d6u,0x0c0903d8u,0x0c0903dau,0x0c0903dcu,
0x0c0903deu,0x0c0903e0u,0x0c0903e2u,0x0c0903e4u,0x0c0903e6u,0x0c0903e8u,0x0c0903eau,0x0c0903ecu,0x0c0903eeu,0x0c0903f0u,0x0c0903f2u,0x0c0903f4u,0x0c0903f6u,0x0c0903f8u,0x0c0903fau,0x0c0903fcu,
0x0c0903feu,0x0c090400u,0x0c090402u,0x0c090404u,0x0c090406u,0x0c090408u,0x0c09040au,0x0c09040cu,0x0c09040eu,0x0c090410u,0x0c090412u,0x0c090414u,0x0c090416u,0x0c090418u,0x0c09041au,0x0c09041cu,
0x0c09041eu,0x0c090420u,0x0c090422u,0x0c090424u,0x0c090426u,0x0c090428u,0x0c09042au,0x0c090450u,0x0c090452u,0x0c090454u,0x0c090456u,0x0c090458u,0x0c09045au,0x0c09045cu,0x0c09045eu,0x0c090460u,
0x0c090462u,0x0c090464u,0x0c090466u,0x0c090468u,0x0c09046au,0x0c09046cu,0x0c09046eu,0x0c090470u,0x0c090472u,0x0c090474u,0x0c090476u,0x0c090478u,0x0c09047au,0x0c09047cu,0x0c09047eu,0x0c090480u,
0x0c090482u,0x0c090484u,0x0c090486u,0x0c090488u,0x0c09048au,0x0c09048cu,0x0c09048eu,0x0c090490u,0x0c090492u,0x0c090494u,0x0c090496u,0x0c090498u,0x0c09049au,0x0c09049cu,0x0c09049eu,0x0c0904a0u,
0x0c0904a2u,0x0c0904a4u,0x0c0904a6u,0x0c0904a8u,0x0c0904aau,0x0c0904acu,0x0c0904aeu,0x0c0904b0u,0x0c0904b2u,0x0c0904bcu,0x0c0904beu,0x0c0904c0u,0x0c0904c2u,0x0c0904c4u,0x0c0904c6u,0x0c0904c8u,
0x0c0904cau,0x0c0904ccu,0x0c0904ceu,0x0c0904d0u,0x0c0904d2u,0x0c0904d4u,0x0c0904d6u,0x0c0904d8u,0x0c0904dau,0x0c0904dcu,0x0c0904deu,0x0c0904e0u,0x0c0904e2u,0x0c0904e4u,0x0c0904e6u,0x0c0904e8u,
0x0c0904eau,0x0c0904ecu,0x0c0904eeu,0x0c0904f0u,0x0c0904f2u,0x0c0904f4u,0x0c0904f6u,0x0c0904f8u,0x0c0904fau,0x0c0904fcu,0x0c0904feu,0x0c090500u,0x0c090502u,0x0c090504u,0x0c090506u,0x0c090508u,
0x0c09050au,0x0c09050cu,0x0c09050eu,0x0c090510u,0x0c090512u,0x0c090514u,0x0c090516u,0x0c090518u,0x0c09051au,0x0c09051cu,0x0c09051eu,0x0c090520u,0x0c090522u,0x0c090524u,0x0c090526u,0x0c090528u,
0x0c09052au,0x0c09052cu,0x0c09052eu,0x0c090530u,0x0c090532u,0x0c090534u,0x0c090536u,0x0c090538u,0x0c09053au,0x0c09053cu,0x0c09053eu,0x0c090540u,0x0c090542u,0x0c090544u,0x0c090546u,0x0c090548u,
0x0c09054au,0x0c09054cu,0x0c09054eu,0x0c090550u,0x0c090552u,0x0c090554u,0x0c090556u,0x0c090558u,0x0c09055au,0x0c09055cu,0x0c09055eu,0x0c090560u,0x0c090562u,0x0c090564u,0x0c090566u,0x0c090568u,
0x0c09056au,0x0c09056cu,0x0c09056eu,0x0c090570u,0x0c090572u,0x0c090574u,0x0c090576u,0x0c090578u,0x0c09057au,0x0c09057cu,0x0c09057eu,0x0c090580u,0x0c090582u,0x0c090584u,0x0c090586u,0x0c090588u,
0x0c09058au,0x0c09058cu,0x0c09058eu,0x0c090590u,0x0c090592u,0x0c090594u,0x0c090596u,0x0c090598u,0x0c09059au,0x0c09059cu,0x0c09059eu,0x0c0905a0u,0x0c0905a2u,0x0c0905a4u,0x0c0905a6u,0x0c0905a8u,
0x0c0905aau,0x0c0905acu,0x0c0905aeu,0x0c0905b0u,0x0c0905b2u,0x0c0905b4u,0x0c0905b6u,0x0c0905b8u,0x0c0905bau,0x0c0905bcu,0x0c0905beu,0x0c0905c0u,0x0c0905c2u,0x0c0905c4u,0x0c0905c6u,0x0c0905c8u,
0x0c0905cau,0x0c0905ccu,0x0c0905ceu,0x0c0905d0u,0x0c0905d2u,0x0c0905d4u,0x0c0905d6u,0x0c0905d8u,0x0c0905dau,0x0c0905dcu,0x0c0905deu,0x0c0905e0u,0x0c0905e2u,0x0c0905e4u,0x0c0905e6u,0x0c0905e8u,
0x0c0905eau,0x0c0905ecu,0x0c0905eeu,0x0c0905f0u,0x0c0905f2u,0x0c0905f4u,0x0c0905f6u,0x0c0905f8u,0x0c0905fau,0x0c0905fcu,0x0c0905feu,0x0c090600u,0x0c09061cu,0x0c09061eu,0x0c090620u,0x0c090622u,
0x0c090624u,0x0c090626u,0x0c090628u,0x0c09062au,0x0c09062cu,0x0c09062eu,0x0c090630u,0x0c090632u,0x0c090634u,0x0c090636u,0x0c090638u,0x0c09063au,0x0c09063cu,0x0c09063eu,0x0c090640u,0x0c090642u,
0x0c090644u,0x0c090646u,0x0c090648u,0x0c09064au,0x0c09064cu,0x0c09064eu,0x0c090650u,0x0c090652u,0x0c090654u,0x0c090656u,0x0c090658u,0x0c09065au,0x0c09065cu,0x0c09065eu,0x0c090660u,0x0c090662u,
0x0c090664u,0x0c090666u,0x0c090668u,0x0c09066au,0x0c09066cu,0x0c09066eu,0x0c090670u,0x0c090672u,0x0c090674u,0x0c090676u,0x0c090678u,0x0c09067au,0x0c09067cu,0x0c09067eu,0x0c090680u,0x0c090682u,
0x0c090684u,0x0c090686u,0x0c090688u,0x0c09068au,0x0c09068cu,0x0c09068eu,0x0c090690u,0x0c090692u,0x0c090694u,0x0c090696u,0x0c090698u,0x0c09069au,0x0c09069cu,0x0c09069eu,0x0c0906a0u,0x0c0906a2u,
0x0c0906a4u,0x0c0906a6u,0x0c0906a8u,0x0c0906aau,0x0c0906acu,0x0c0906aeu,0x0c0906b0u,0x0c0906b2u,0x0c0906b4u,
};
int vf3_advance_vector_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
