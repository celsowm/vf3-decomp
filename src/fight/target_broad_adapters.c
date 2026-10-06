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
int vf3_target_broad_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b02cu: goto P_0c07b02c;
case 0x0c07b02eu: goto P_0c07b02e;
case 0x0c07b030u: goto P_0c07b030;
case 0x0c07b032u: goto P_0c07b032;
case 0x0c07b034u: goto P_0c07b034;
case 0x0c07b036u: goto P_0c07b036;
case 0x0c07b038u: goto P_0c07b038;
case 0x0c07b03au: goto P_0c07b03a;
case 0x0c07b03cu: goto P_0c07b03c;
case 0x0c07b03eu: goto P_0c07b03e;
case 0x0c07b040u: goto P_0c07b040;
case 0x0c07b042u: goto P_0c07b042;
case 0x0c07b044u: goto P_0c07b044;
case 0x0c07b046u: goto P_0c07b046;
case 0x0c07b048u: goto P_0c07b048;
case 0x0c07b04au: goto P_0c07b04a;
case 0x0c07b04cu: goto P_0c07b04c;
case 0x0c07b04eu: goto P_0c07b04e;
case 0x0c07b050u: goto P_0c07b050;
case 0x0c07b052u: goto P_0c07b052;
case 0x0c07b054u: goto P_0c07b054;
case 0x0c07b056u: goto P_0c07b056;
case 0x0c07b058u: goto P_0c07b058;
case 0x0c07b05au: goto P_0c07b05a;
case 0x0c07b05cu: goto P_0c07b05c;
case 0x0c07b05eu: goto P_0c07b05e;
case 0x0c07b060u: goto P_0c07b060;
case 0x0c07b062u: goto P_0c07b062;
case 0x0c07b064u: goto P_0c07b064;
case 0x0c07b066u: goto P_0c07b066;
case 0x0c07b068u: goto P_0c07b068;
case 0x0c07b06au: goto P_0c07b06a;
case 0x0c07b06cu: goto P_0c07b06c;
case 0x0c07b06eu: goto P_0c07b06e;
case 0x0c07b070u: goto P_0c07b070;
case 0x0c07b072u: goto P_0c07b072;
case 0x0c07b074u: goto P_0c07b074;
case 0x0c07b076u: goto P_0c07b076;
case 0x0c07b078u: goto P_0c07b078;
case 0x0c07b07au: goto P_0c07b07a;
case 0x0c07b07cu: goto P_0c07b07c;
case 0x0c07b07eu: goto P_0c07b07e;
case 0x0c07b080u: goto P_0c07b080;
case 0x0c07b082u: goto P_0c07b082;
case 0x0c07b084u: goto P_0c07b084;
case 0x0c07b086u: goto P_0c07b086;
case 0x0c07b088u: goto P_0c07b088;
case 0x0c07b08au: goto P_0c07b08a;
case 0x0c07b08cu: goto P_0c07b08c;
case 0x0c07b08eu: goto P_0c07b08e;
case 0x0c07b090u: goto P_0c07b090;
case 0x0c07b092u: goto P_0c07b092;
case 0x0c07b094u: goto P_0c07b094;
case 0x0c07b096u: goto P_0c07b096;
case 0x0c07b098u: goto P_0c07b098;
case 0x0c07b09au: goto P_0c07b09a;
case 0x0c07b09cu: goto P_0c07b09c;
case 0x0c07b09eu: goto P_0c07b09e;
case 0x0c07b0a0u: goto P_0c07b0a0;
case 0x0c07b0a2u: goto P_0c07b0a2;
case 0x0c07b0a4u: goto P_0c07b0a4;
case 0x0c07b0a6u: goto P_0c07b0a6;
case 0x0c07b0a8u: goto P_0c07b0a8;
case 0x0c07b0aau: goto P_0c07b0aa;
case 0x0c07b0acu: goto P_0c07b0ac;
case 0x0c07b0aeu: goto P_0c07b0ae;
case 0x0c07b0b0u: goto P_0c07b0b0;
case 0x0c07b0b2u: goto P_0c07b0b2;
case 0x0c07b0b4u: goto P_0c07b0b4;
case 0x0c07b0b6u: goto P_0c07b0b6;
case 0x0c07b0b8u: goto P_0c07b0b8;
case 0x0c07b0bau: goto P_0c07b0ba;
case 0x0c07b0bcu: goto P_0c07b0bc;
case 0x0c07b0beu: goto P_0c07b0be;
case 0x0c07b0c0u: goto P_0c07b0c0;
case 0x0c07b0c2u: goto P_0c07b0c2;
case 0x0c087534u: goto P_0c087534;
case 0x0c087536u: goto P_0c087536;
case 0x0c087538u: goto P_0c087538;
case 0x0c08753au: goto P_0c08753a;
case 0x0c08753cu: goto P_0c08753c;
case 0x0c08753eu: goto P_0c08753e;
case 0x0c087540u: goto P_0c087540;
case 0x0c087542u: goto P_0c087542;
case 0x0c087544u: goto P_0c087544;
case 0x0c087546u: goto P_0c087546;
case 0x0c087548u: goto P_0c087548;
case 0x0c08754au: goto P_0c08754a;
case 0x0c08754cu: goto P_0c08754c;
case 0x0c08754eu: goto P_0c08754e;
case 0x0c087550u: goto P_0c087550;
case 0x0c087552u: goto P_0c087552;
case 0x0c087554u: goto P_0c087554;
case 0x0c087556u: goto P_0c087556;
case 0x0c087558u: goto P_0c087558;
case 0x0c08755au: goto P_0c08755a;
case 0x0c08755cu: goto P_0c08755c;
case 0x0c08755eu: goto P_0c08755e;
case 0x0c087560u: goto P_0c087560;
case 0x0c087562u: goto P_0c087562;
case 0x0c087564u: goto P_0c087564;
case 0x0c087566u: goto P_0c087566;
case 0x0c087568u: goto P_0c087568;
case 0x0c08756au: goto P_0c08756a;
case 0x0c08756cu: goto P_0c08756c;
case 0x0c08756eu: goto P_0c08756e;
case 0x0c087570u: goto P_0c087570;
case 0x0c087572u: goto P_0c087572;
case 0x0c087574u: goto P_0c087574;
case 0x0c087576u: goto P_0c087576;
case 0x0c087578u: goto P_0c087578;
case 0x0c08757au: goto P_0c08757a;
case 0x0c08757cu: goto P_0c08757c;
case 0x0c08757eu: goto P_0c08757e;
case 0x0c087580u: goto P_0c087580;
case 0x0c087582u: goto P_0c087582;
case 0x0c087584u: goto P_0c087584;
case 0x0c087586u: goto P_0c087586;
case 0x0c087588u: goto P_0c087588;
case 0x0c08758au: goto P_0c08758a;
case 0x0c08758cu: goto P_0c08758c;
case 0x0c08758eu: goto P_0c08758e;
case 0x0c087590u: goto P_0c087590;
case 0x0c087592u: goto P_0c087592;
case 0x0c087594u: goto P_0c087594;
case 0x0c087596u: goto P_0c087596;
case 0x0c087598u: goto P_0c087598;
case 0x0c08759au: goto P_0c08759a;
case 0x0c08759cu: goto P_0c08759c;
case 0x0c08759eu: goto P_0c08759e;
case 0x0c0875a0u: goto P_0c0875a0;
case 0x0c0875a2u: goto P_0c0875a2;
case 0x0c0875a4u: goto P_0c0875a4;
case 0x0c0875a6u: goto P_0c0875a6;
case 0x0c0875a8u: goto P_0c0875a8;
case 0x0c0875aau: goto P_0c0875aa;
case 0x0c0875acu: goto P_0c0875ac;
case 0x0c0875aeu: goto P_0c0875ae;
case 0x0c0875ceu: goto P_0c0875ce;
case 0x0c0875d0u: goto P_0c0875d0;
case 0x0c0875d2u: goto P_0c0875d2;
case 0x0c0875d4u: goto P_0c0875d4;
case 0x0c0875d6u: goto P_0c0875d6;
case 0x0c0875d8u: goto P_0c0875d8;
case 0x0c0875dau: goto P_0c0875da;
case 0x0c0875dcu: goto P_0c0875dc;
case 0x0c0875deu: goto P_0c0875de;
case 0x0c0875e0u: goto P_0c0875e0;
case 0x0c0875e2u: goto P_0c0875e2;
case 0x0c0875e4u: goto P_0c0875e4;
case 0x0c0875e6u: goto P_0c0875e6;
case 0x0c0875e8u: goto P_0c0875e8;
case 0x0c0875eau: goto P_0c0875ea;
case 0x0c0875ecu: goto P_0c0875ec;
case 0x0c0875eeu: goto P_0c0875ee;
case 0x0c0881ccu: goto P_0c0881cc;
case 0x0c0881ceu: goto P_0c0881ce;
case 0x0c0881d0u: goto P_0c0881d0;
case 0x0c0881d2u: goto P_0c0881d2;
case 0x0c0881d4u: goto P_0c0881d4;
case 0x0c0881d6u: goto P_0c0881d6;
case 0x0c0881d8u: goto P_0c0881d8;
case 0x0c0881dau: goto P_0c0881da;
case 0x0c0881fau: goto P_0c0881fa;
case 0x0c0881fcu: goto P_0c0881fc;
case 0x0c0881feu: goto P_0c0881fe;
case 0x0c088200u: goto P_0c088200;
case 0x0c088202u: goto P_0c088202;
case 0x0c088204u: goto P_0c088204;
case 0x0c088206u: goto P_0c088206;
case 0x0c088208u: goto P_0c088208;
case 0x0c08820au: goto P_0c08820a;
case 0x0c08820cu: goto P_0c08820c;
case 0x0c08820eu: goto P_0c08820e;
case 0x0c088210u: goto P_0c088210;
case 0x0c088212u: goto P_0c088212;
case 0x0c088214u: goto P_0c088214;
case 0x0c088216u: goto P_0c088216;
case 0x0c088218u: goto P_0c088218;
case 0x0c08821au: goto P_0c08821a;
case 0x0c08821cu: goto P_0c08821c;
case 0x0c08821eu: goto P_0c08821e;
case 0x0c088220u: goto P_0c088220;
case 0x0c088222u: goto P_0c088222;
case 0x0c088224u: goto P_0c088224;
case 0x0c088226u: goto P_0c088226;
case 0x0c088228u: goto P_0c088228;
case 0x0c08822au: goto P_0c08822a;
case 0x0c08822cu: goto P_0c08822c;
case 0x0c08822eu: goto P_0c08822e;
case 0x0c088230u: goto P_0c088230;
case 0x0c088232u: goto P_0c088232;
case 0x0c088234u: goto P_0c088234;
case 0x0c088236u: goto P_0c088236;
case 0x0c088238u: goto P_0c088238;
case 0x0c08823au: goto P_0c08823a;
case 0x0c08823cu: goto P_0c08823c;
case 0x0c08823eu: goto P_0c08823e;
case 0x0c088240u: goto P_0c088240;
case 0x0c088242u: goto P_0c088242;
case 0x0c088244u: goto P_0c088244;
case 0x0c088246u: goto P_0c088246;
case 0x0c088248u: goto P_0c088248;
case 0x0c08824au: goto P_0c08824a;
case 0x0c08824cu: goto P_0c08824c;
case 0x0c08824eu: goto P_0c08824e;
case 0x0c088250u: goto P_0c088250;
case 0x0c088252u: goto P_0c088252;
case 0x0c088254u: goto P_0c088254;
case 0x0c088256u: goto P_0c088256;
case 0x0c088258u: goto P_0c088258;
case 0x0c08825au: goto P_0c08825a;
case 0x0c08825cu: goto P_0c08825c;
case 0x0c08825eu: goto P_0c08825e;
case 0x0c088260u: goto P_0c088260;
case 0x0c088262u: goto P_0c088262;
case 0x0c088264u: goto P_0c088264;
case 0x0c088266u: goto P_0c088266;
case 0x0c088268u: goto P_0c088268;
case 0x0c08826au: goto P_0c08826a;
case 0x0c08826cu: goto P_0c08826c;
case 0x0c08826eu: goto P_0c08826e;
case 0x0c088270u: goto P_0c088270;
case 0x0c088272u: goto P_0c088272;
case 0x0c088274u: goto P_0c088274;
case 0x0c088276u: goto P_0c088276;
case 0x0c088278u: goto P_0c088278;
case 0x0c08827au: goto P_0c08827a;
case 0x0c08827cu: goto P_0c08827c;
case 0x0c08827eu: goto P_0c08827e;
case 0x0c088280u: goto P_0c088280;
case 0x0c088282u: goto P_0c088282;
case 0x0c088284u: goto P_0c088284;
case 0x0c088286u: goto P_0c088286;
case 0x0c088288u: goto P_0c088288;
case 0x0c08828au: goto P_0c08828a;
case 0x0c08828cu: goto P_0c08828c;
case 0x0c08828eu: goto P_0c08828e;
case 0x0c088290u: goto P_0c088290;
case 0x0c088292u: goto P_0c088292;
case 0x0c088294u: goto P_0c088294;
case 0x0c088296u: goto P_0c088296;
case 0x0c088298u: goto P_0c088298;
case 0x0c08829au: goto P_0c08829a;
case 0x0c08829cu: goto P_0c08829c;
case 0x0c08829eu: goto P_0c08829e;
case 0x0c0882a0u: goto P_0c0882a0;
case 0x0c0887ecu: goto P_0c0887ec;
case 0x0c0887eeu: goto P_0c0887ee;
case 0x0c0887f0u: goto P_0c0887f0;
case 0x0c0887f2u: goto P_0c0887f2;
case 0x0c0887f4u: goto P_0c0887f4;
case 0x0c0887f6u: goto P_0c0887f6;
case 0x0c0887f8u: goto P_0c0887f8;
case 0x0c0887fau: goto P_0c0887fa;
case 0x0c0887fcu: goto P_0c0887fc;
case 0x0c0887feu: goto P_0c0887fe;
case 0x0c088800u: goto P_0c088800;
case 0x0c088802u: goto P_0c088802;
case 0x0c088804u: goto P_0c088804;
case 0x0c088806u: goto P_0c088806;
case 0x0c088808u: goto P_0c088808;
case 0x0c08880au: goto P_0c08880a;
case 0x0c08880cu: goto P_0c08880c;
case 0x0c08880eu: goto P_0c08880e;
case 0x0c088810u: goto P_0c088810;
case 0x0c088812u: goto P_0c088812;
case 0x0c088814u: goto P_0c088814;
case 0x0c088816u: goto P_0c088816;
case 0x0c088818u: goto P_0c088818;
case 0x0c08881au: goto P_0c08881a;
case 0x0c08881cu: goto P_0c08881c;
case 0x0c08881eu: goto P_0c08881e;
case 0x0c088820u: goto P_0c088820;
case 0x0c088822u: goto P_0c088822;
case 0x0c088824u: goto P_0c088824;
case 0x0c088826u: goto P_0c088826;
case 0x0c088828u: goto P_0c088828;
case 0x0c08882au: goto P_0c08882a;
case 0x0c08882cu: goto P_0c08882c;
case 0x0c08882eu: goto P_0c08882e;
case 0x0c088830u: goto P_0c088830;
case 0x0c088832u: goto P_0c088832;
case 0x0c088834u: goto P_0c088834;
case 0x0c088836u: goto P_0c088836;
case 0x0c088838u: goto P_0c088838;
case 0x0c08883au: goto P_0c08883a;
case 0x0c08883cu: goto P_0c08883c;
case 0x0c088ef0u: goto P_0c088ef0;
case 0x0c088ef2u: goto P_0c088ef2;
case 0x0c088ef4u: goto P_0c088ef4;
case 0x0c088ef6u: goto P_0c088ef6;
case 0x0c088ef8u: goto P_0c088ef8;
case 0x0c088efau: goto P_0c088efa;
case 0x0c088efcu: goto P_0c088efc;
case 0x0c088efeu: goto P_0c088efe;
case 0x0c088f00u: goto P_0c088f00;
case 0x0c088f02u: goto P_0c088f02;
case 0x0c088f04u: goto P_0c088f04;
case 0x0c088f06u: goto P_0c088f06;
case 0x0c088f08u: goto P_0c088f08;
case 0x0c088f0au: goto P_0c088f0a;
case 0x0c088f0cu: goto P_0c088f0c;
case 0x0c088f0eu: goto P_0c088f0e;
case 0x0c088f10u: goto P_0c088f10;
case 0x0c088f12u: goto P_0c088f12;
case 0x0c088f14u: goto P_0c088f14;
case 0x0c088f16u: goto P_0c088f16;
case 0x0c088f18u: goto P_0c088f18;
case 0x0c088f1au: goto P_0c088f1a;
case 0x0c088f1cu: goto P_0c088f1c;
case 0x0c088f1eu: goto P_0c088f1e;
case 0x0c088f20u: goto P_0c088f20;
case 0x0c088f22u: goto P_0c088f22;
case 0x0c088f24u: goto P_0c088f24;
case 0x0c088f26u: goto P_0c088f26;
case 0x0c088f28u: goto P_0c088f28;
case 0x0c088f2au: goto P_0c088f2a;
case 0x0c088f2cu: goto P_0c088f2c;
case 0x0c088f2eu: goto P_0c088f2e;
case 0x0c088f30u: goto P_0c088f30;
case 0x0c088f32u: goto P_0c088f32;
case 0x0c088f34u: goto P_0c088f34;
case 0x0c088f36u: goto P_0c088f36;
case 0x0c088f38u: goto P_0c088f38;
case 0x0c088f3au: goto P_0c088f3a;
case 0x0c088f3cu: goto P_0c088f3c;
case 0x0c088f3eu: goto P_0c088f3e;
case 0x0c088f40u: goto P_0c088f40;
case 0x0c088f42u: goto P_0c088f42;
case 0x0c088f44u: goto P_0c088f44;
case 0x0c088f46u: goto P_0c088f46;
case 0x0c088f48u: goto P_0c088f48;
case 0x0c088f4au: goto P_0c088f4a;
case 0x0c088f4cu: goto P_0c088f4c;
case 0x0c088f4eu: goto P_0c088f4e;
case 0x0c088f50u: goto P_0c088f50;
case 0x0c088f52u: goto P_0c088f52;
case 0x0c088f54u: goto P_0c088f54;
case 0x0c088f56u: goto P_0c088f56;
case 0x0c088f58u: goto P_0c088f58;
case 0x0c088f5au: goto P_0c088f5a;
case 0x0c088f5cu: goto P_0c088f5c;
case 0x0c088f5eu: goto P_0c088f5e;
case 0x0c088f60u: goto P_0c088f60;
case 0x0c088f62u: goto P_0c088f62;
case 0x0c088f64u: goto P_0c088f64;
case 0x0c088f66u: goto P_0c088f66;
case 0x0c088f68u: goto P_0c088f68;
case 0x0c088f6au: goto P_0c088f6a;
case 0x0c088f6cu: goto P_0c088f6c;
case 0x0c088f6eu: goto P_0c088f6e;
case 0x0c088f70u: goto P_0c088f70;
case 0x0c088f72u: goto P_0c088f72;
case 0x0c088f74u: goto P_0c088f74;
case 0x0c088f76u: goto P_0c088f76;
case 0x0c088f78u: goto P_0c088f78;
case 0x0c088f7au: goto P_0c088f7a;
case 0x0c088f7cu: goto P_0c088f7c;
case 0x0c088f7eu: goto P_0c088f7e;
case 0x0c088f80u: goto P_0c088f80;
case 0x0c088f82u: goto P_0c088f82;
case 0x0c088f84u: goto P_0c088f84;
case 0x0c088f86u: goto P_0c088f86;
case 0x0c088f88u: goto P_0c088f88;
case 0x0c088f8au: goto P_0c088f8a;
case 0x0c088f8cu: goto P_0c088f8c;
case 0x0c088f8eu: goto P_0c088f8e;
case 0x0c088f90u: goto P_0c088f90;
case 0x0c088f92u: goto P_0c088f92;
case 0x0c088f94u: goto P_0c088f94;
case 0x0c088f96u: goto P_0c088f96;
case 0x0c088f98u: goto P_0c088f98;
case 0x0c088f9au: goto P_0c088f9a;
case 0x0c088f9cu: goto P_0c088f9c;
case 0x0c088f9eu: goto P_0c088f9e;
case 0x0c088fa0u: goto P_0c088fa0;
case 0x0c088fa2u: goto P_0c088fa2;
case 0x0c088fa4u: goto P_0c088fa4;
case 0x0c088fa6u: goto P_0c088fa6;
case 0x0c088fa8u: goto P_0c088fa8;
case 0x0c088faau: goto P_0c088faa;
case 0x0c088facu: goto P_0c088fac;
case 0x0c088faeu: goto P_0c088fae;
case 0x0c088fb0u: goto P_0c088fb0;
case 0x0c088fb2u: goto P_0c088fb2;
case 0x0c088fb4u: goto P_0c088fb4;
case 0x0c088fb6u: goto P_0c088fb6;
case 0x0c088fb8u: goto P_0c088fb8;
case 0x0c088fbau: goto P_0c088fba;
case 0x0c088fbcu: goto P_0c088fbc;
case 0x0c088fbeu: goto P_0c088fbe;
case 0x0c088fc0u: goto P_0c088fc0;
case 0x0c088fc2u: goto P_0c088fc2;
case 0x0c088fc4u: goto P_0c088fc4;
case 0x0c088fc6u: goto P_0c088fc6;
case 0x0c088fc8u: goto P_0c088fc8;
case 0x0c088fcau: goto P_0c088fca;
case 0x0c088fccu: goto P_0c088fcc;
case 0x0c088fceu: goto P_0c088fce;
case 0x0c088fe0u: goto P_0c088fe0;
case 0x0c088fe2u: goto P_0c088fe2;
case 0x0c088fe4u: goto P_0c088fe4;
case 0x0c088fe6u: goto P_0c088fe6;
case 0x0c088fe8u: goto P_0c088fe8;
case 0x0c088feau: goto P_0c088fea;
case 0x0c088fecu: goto P_0c088fec;
case 0x0c088feeu: goto P_0c088fee;
case 0x0c088ff0u: goto P_0c088ff0;
case 0x0c088ff2u: goto P_0c088ff2;
case 0x0c088ff4u: goto P_0c088ff4;
case 0x0c088ff6u: goto P_0c088ff6;
case 0x0c088ff8u: goto P_0c088ff8;
case 0x0c088ffau: goto P_0c088ffa;
case 0x0c088ffcu: goto P_0c088ffc;
case 0x0c088ffeu: goto P_0c088ffe;
case 0x0c089000u: goto P_0c089000;
case 0x0c089002u: goto P_0c089002;
case 0x0c089004u: goto P_0c089004;
case 0x0c089006u: goto P_0c089006;
case 0x0c089008u: goto P_0c089008;
case 0x0c08900au: goto P_0c08900a;
case 0x0c08900cu: goto P_0c08900c;
case 0x0c08900eu: goto P_0c08900e;
case 0x0c089010u: goto P_0c089010;
case 0x0c089012u: goto P_0c089012;
case 0x0c089014u: goto P_0c089014;
case 0x0c089016u: goto P_0c089016;
case 0x0c089018u: goto P_0c089018;
case 0x0c08901au: goto P_0c08901a;
case 0x0c08901cu: goto P_0c08901c;
case 0x0c08901eu: goto P_0c08901e;
case 0x0c089020u: goto P_0c089020;
case 0x0c089022u: goto P_0c089022;
case 0x0c089024u: goto P_0c089024;
case 0x0c089026u: goto P_0c089026;
case 0x0c089028u: goto P_0c089028;
case 0x0c08902au: goto P_0c08902a;
case 0x0c08902cu: goto P_0c08902c;
case 0x0c08902eu: goto P_0c08902e;
case 0x0c089030u: goto P_0c089030;
case 0x0c089032u: goto P_0c089032;
case 0x0c089034u: goto P_0c089034;
case 0x0c089036u: goto P_0c089036;
case 0x0c089038u: goto P_0c089038;
case 0x0c08903au: goto P_0c08903a;
case 0x0c08903cu: goto P_0c08903c;
case 0x0c08903eu: goto P_0c08903e;
case 0x0c089040u: goto P_0c089040;
case 0x0c089042u: goto P_0c089042;
case 0x0c089044u: goto P_0c089044;
case 0x0c089046u: goto P_0c089046;
case 0x0c089048u: goto P_0c089048;
case 0x0c08904au: goto P_0c08904a;
case 0x0c08904cu: goto P_0c08904c;
case 0x0c08904eu: goto P_0c08904e;
case 0x0c089050u: goto P_0c089050;
case 0x0c089052u: goto P_0c089052;
case 0x0c089054u: goto P_0c089054;
case 0x0c089056u: goto P_0c089056;
case 0x0c089058u: goto P_0c089058;
case 0x0c08905au: goto P_0c08905a;
case 0x0c08905cu: goto P_0c08905c;
case 0x0c08905eu: goto P_0c08905e;
case 0x0c089060u: goto P_0c089060;
case 0x0c089062u: goto P_0c089062;
case 0x0c089064u: goto P_0c089064;
case 0x0c089066u: goto P_0c089066;
case 0x0c089068u: goto P_0c089068;
case 0x0c08906au: goto P_0c08906a;
case 0x0c08906cu: goto P_0c08906c;
case 0x0c08906eu: goto P_0c08906e;
case 0x0c089070u: goto P_0c089070;
case 0x0c089072u: goto P_0c089072;
case 0x0c089074u: goto P_0c089074;
case 0x0c089076u: goto P_0c089076;
case 0x0c089078u: goto P_0c089078;
case 0x0c08907au: goto P_0c08907a;
case 0x0c08907cu: goto P_0c08907c;
case 0x0c08907eu: goto P_0c08907e;
case 0x0c089080u: goto P_0c089080;
case 0x0c089082u: goto P_0c089082;
case 0x0c089084u: goto P_0c089084;
case 0x0c089086u: goto P_0c089086;
case 0x0c089088u: goto P_0c089088;
case 0x0c08908au: goto P_0c08908a;
case 0x0c08908cu: goto P_0c08908c;
case 0x0c08908eu: goto P_0c08908e;
case 0x0c089090u: goto P_0c089090;
case 0x0c089092u: goto P_0c089092;
case 0x0c089094u: goto P_0c089094;
case 0x0c089096u: goto P_0c089096;
case 0x0c089098u: goto P_0c089098;
case 0x0c08909au: goto P_0c08909a;
case 0x0c08909cu: goto P_0c08909c;
case 0x0c08909eu: goto P_0c08909e;
case 0x0c0890a0u: goto P_0c0890a0;
case 0x0c0890a2u: goto P_0c0890a2;
case 0x0c0890a4u: goto P_0c0890a4;
case 0x0c0890a6u: goto P_0c0890a6;
case 0x0c0890a8u: goto P_0c0890a8;
case 0x0c0890aau: goto P_0c0890aa;
case 0x0c0890acu: goto P_0c0890ac;
case 0x0c0890aeu: goto P_0c0890ae;
case 0x0c0890b0u: goto P_0c0890b0;
case 0x0c0890b2u: goto P_0c0890b2;
case 0x0c0890b4u: goto P_0c0890b4;
case 0x0c0890b6u: goto P_0c0890b6;
case 0x0c0890b8u: goto P_0c0890b8;
case 0x0c0890bau: goto P_0c0890ba;
case 0x0c0890bcu: goto P_0c0890bc;
case 0x0c0890beu: goto P_0c0890be;
case 0x0c0890c0u: goto P_0c0890c0;
case 0x0c0890c2u: goto P_0c0890c2;
case 0x0c0890c4u: goto P_0c0890c4;
case 0x0c0890c6u: goto P_0c0890c6;
case 0x0c0890c8u: goto P_0c0890c8;
case 0x0c0890cau: goto P_0c0890ca;
case 0x0c0890ccu: goto P_0c0890cc;
case 0x0c0890ceu: goto P_0c0890ce;
case 0x0c0890d0u: goto P_0c0890d0;
case 0x0c0890d2u: goto P_0c0890d2;
case 0x0c0890d4u: goto P_0c0890d4;
case 0x0c0890d6u: goto P_0c0890d6;
case 0x0c0890d8u: goto P_0c0890d8;
case 0x0c0890dau: goto P_0c0890da;
case 0x0c0890dcu: goto P_0c0890dc;
case 0x0c0890deu: goto P_0c0890de;
case 0x0c0890e0u: goto P_0c0890e0;
case 0x0c0890e2u: goto P_0c0890e2;
case 0x0c0890e4u: goto P_0c0890e4;
case 0x0c0890e6u: goto P_0c0890e6;
case 0x0c0890e8u: goto P_0c0890e8;
case 0x0c0890eau: goto P_0c0890ea;
case 0x0c0890ecu: goto P_0c0890ec;
case 0x0c0890eeu: goto P_0c0890ee;
case 0x0c0890f0u: goto P_0c0890f0;
case 0x0c0890f2u: goto P_0c0890f2;
case 0x0c0890f4u: goto P_0c0890f4;
case 0x0c0890f6u: goto P_0c0890f6;
case 0x0c0890f8u: goto P_0c0890f8;
case 0x0c0890fau: goto P_0c0890fa;
case 0x0c0890fcu: goto P_0c0890fc;
case 0x0c0890feu: goto P_0c0890fe;
case 0x0c089100u: goto P_0c089100;
case 0x0c089102u: goto P_0c089102;
case 0x0c089104u: goto P_0c089104;
case 0x0c089106u: goto P_0c089106;
case 0x0c089108u: goto P_0c089108;
case 0x0c08910au: goto P_0c08910a;
case 0x0c08910cu: goto P_0c08910c;
case 0x0c08910eu: goto P_0c08910e;
case 0x0c089110u: goto P_0c089110;
case 0x0c089112u: goto P_0c089112;
case 0x0c089114u: goto P_0c089114;
case 0x0c089116u: goto P_0c089116;
case 0x0c089118u: goto P_0c089118;
case 0x0c08911au: goto P_0c08911a;
case 0x0c08911cu: goto P_0c08911c;
case 0x0c08911eu: goto P_0c08911e;
case 0x0c089120u: goto P_0c089120;
case 0x0c089122u: goto P_0c089122;
case 0x0c089124u: goto P_0c089124;
case 0x0c089126u: goto P_0c089126;
case 0x0c089128u: goto P_0c089128;
case 0x0c08912au: goto P_0c08912a;
case 0x0c08912cu: goto P_0c08912c;
case 0x0c08912eu: goto P_0c08912e;
case 0x0c089130u: goto P_0c089130;
case 0x0c089132u: goto P_0c089132;
case 0x0c089134u: goto P_0c089134;
case 0x0c089136u: goto P_0c089136;
case 0x0c089138u: goto P_0c089138;
case 0x0c08913au: goto P_0c08913a;
case 0x0c08913cu: goto P_0c08913c;
case 0x0c08913eu: goto P_0c08913e;
case 0x0c089140u: goto P_0c089140;
case 0x0c089142u: goto P_0c089142;
case 0x0c089144u: goto P_0c089144;
case 0x0c089174u: goto P_0c089174;
case 0x0c089176u: goto P_0c089176;
case 0x0c089178u: goto P_0c089178;
case 0x0c08917au: goto P_0c08917a;
case 0x0c08917cu: goto P_0c08917c;
case 0x0c08917eu: goto P_0c08917e;
case 0x0c089180u: goto P_0c089180;
case 0x0c089182u: goto P_0c089182;
case 0x0c089184u: goto P_0c089184;
case 0x0c08927eu: goto P_0c08927e;
case 0x0c089280u: goto P_0c089280;
case 0x0c089282u: goto P_0c089282;
case 0x0c089284u: goto P_0c089284;
case 0x0c089286u: goto P_0c089286;
case 0x0c089288u: goto P_0c089288;
case 0x0c08928au: goto P_0c08928a;
case 0x0c08928cu: goto P_0c08928c;
case 0x0c08928eu: goto P_0c08928e;
case 0x0c089290u: goto P_0c089290;
case 0x0c089292u: goto P_0c089292;
case 0x0c089294u: goto P_0c089294;
case 0x0c089296u: goto P_0c089296;
case 0x0c089298u: goto P_0c089298;
case 0x0c0892b8u: goto P_0c0892b8;
case 0x0c0892bau: goto P_0c0892ba;
case 0x0c0892bcu: goto P_0c0892bc;
case 0x0c0892beu: goto P_0c0892be;
case 0x0c0892c0u: goto P_0c0892c0;
case 0x0c0892c2u: goto P_0c0892c2;
case 0x0c0892c4u: goto P_0c0892c4;
case 0x0c0892c6u: goto P_0c0892c6;
case 0x0c0892c8u: goto P_0c0892c8;
case 0x0c0892cau: goto P_0c0892ca;
case 0x0c0892ccu: goto P_0c0892cc;
case 0x0c0892ceu: goto P_0c0892ce;
case 0x0c0892d0u: goto P_0c0892d0;
case 0x0c0892d2u: goto P_0c0892d2;
case 0x0c0892d4u: goto P_0c0892d4;
case 0x0c0892d6u: goto P_0c0892d6;
case 0x0c0892d8u: goto P_0c0892d8;
case 0x0c0892dau: goto P_0c0892da;
case 0x0c0892dcu: goto P_0c0892dc;
case 0x0c0892deu: goto P_0c0892de;
case 0x0c0892e0u: goto P_0c0892e0;
case 0x0c0892e2u: goto P_0c0892e2;
case 0x0c0892e4u: goto P_0c0892e4;
case 0x0c0892e6u: goto P_0c0892e6;
case 0x0c0892e8u: goto P_0c0892e8;
case 0x0c0892eau: goto P_0c0892ea;
case 0x0c0892ecu: goto P_0c0892ec;
case 0x0c0892eeu: goto P_0c0892ee;
case 0x0c0892f0u: goto P_0c0892f0;
case 0x0c0892f2u: goto P_0c0892f2;
case 0x0c0892f4u: goto P_0c0892f4;
case 0x0c0892f6u: goto P_0c0892f6;
case 0x0c0892f8u: goto P_0c0892f8;
case 0x0c0892fau: goto P_0c0892fa;
case 0x0c0892fcu: goto P_0c0892fc;
case 0x0c0892feu: goto P_0c0892fe;
case 0x0c089300u: goto P_0c089300;
case 0x0c089302u: goto P_0c089302;
case 0x0c089304u: goto P_0c089304;
case 0x0c089306u: goto P_0c089306;
case 0x0c089308u: goto P_0c089308;
case 0x0c08930au: goto P_0c08930a;
case 0x0c08930cu: goto P_0c08930c;
case 0x0c08930eu: goto P_0c08930e;
case 0x0c089310u: goto P_0c089310;
case 0x0c089312u: goto P_0c089312;
case 0x0c089314u: goto P_0c089314;
case 0x0c089316u: goto P_0c089316;
case 0x0c089318u: goto P_0c089318;
case 0x0c08931au: goto P_0c08931a;
case 0x0c08931cu: goto P_0c08931c;
case 0x0c08931eu: goto P_0c08931e;
case 0x0c089320u: goto P_0c089320;
case 0x0c089322u: goto P_0c089322;
case 0x0c089324u: goto P_0c089324;
case 0x0c089326u: goto P_0c089326;
case 0x0c089328u: goto P_0c089328;
case 0x0c08932au: goto P_0c08932a;
case 0x0c08932cu: goto P_0c08932c;
case 0x0c08932eu: goto P_0c08932e;
case 0x0c089330u: goto P_0c089330;
case 0x0c089332u: goto P_0c089332;
case 0x0c089334u: goto P_0c089334;
case 0x0c089336u: goto P_0c089336;
case 0x0c089338u: goto P_0c089338;
case 0x0c08933au: goto P_0c08933a;
case 0x0c08933cu: goto P_0c08933c;
case 0x0c08933eu: goto P_0c08933e;
case 0x0c089340u: goto P_0c089340;
case 0x0c089342u: goto P_0c089342;
case 0x0c089344u: goto P_0c089344;
case 0x0c089346u: goto P_0c089346;
case 0x0c089b50u: goto P_0c089b50;
case 0x0c089b52u: goto P_0c089b52;
case 0x0c089b54u: goto P_0c089b54;
case 0x0c089b56u: goto P_0c089b56;
case 0x0c089b58u: goto P_0c089b58;
case 0x0c089b5au: goto P_0c089b5a;
case 0x0c089b5cu: goto P_0c089b5c;
case 0x0c089b5eu: goto P_0c089b5e;
case 0x0c089b60u: goto P_0c089b60;
case 0x0c089b62u: goto P_0c089b62;
case 0x0c089b64u: goto P_0c089b64;
case 0x0c089b66u: goto P_0c089b66;
case 0x0c089b68u: goto P_0c089b68;
case 0x0c089b6au: goto P_0c089b6a;
case 0x0c089b6cu: goto P_0c089b6c;
case 0x0c089b6eu: goto P_0c089b6e;
case 0x0c089b70u: goto P_0c089b70;
case 0x0c089b72u: goto P_0c089b72;
case 0x0c089b74u: goto P_0c089b74;
case 0x0c089b76u: goto P_0c089b76;
case 0x0c089b78u: goto P_0c089b78;
case 0x0c089b7au: goto P_0c089b7a;
case 0x0c089b7cu: goto P_0c089b7c;
case 0x0c089b7eu: goto P_0c089b7e;
case 0x0c089b80u: goto P_0c089b80;
case 0x0c089b82u: goto P_0c089b82;
case 0x0c089b84u: goto P_0c089b84;
case 0x0c089b86u: goto P_0c089b86;
case 0x0c089b88u: goto P_0c089b88;
case 0x0c089b8au: goto P_0c089b8a;
case 0x0c089b8cu: goto P_0c089b8c;
case 0x0c089b8eu: goto P_0c089b8e;
case 0x0c089b90u: goto P_0c089b90;
case 0x0c089b92u: goto P_0c089b92;
case 0x0c089b94u: goto P_0c089b94;
case 0x0c089b96u: goto P_0c089b96;
case 0x0c089b98u: goto P_0c089b98;
case 0x0c089b9au: goto P_0c089b9a;
case 0x0c089b9cu: goto P_0c089b9c;
case 0x0c089b9eu: goto P_0c089b9e;
case 0x0c089ba0u: goto P_0c089ba0;
case 0x0c089ba2u: goto P_0c089ba2;
case 0x0c089ba4u: goto P_0c089ba4;
case 0x0c089ba6u: goto P_0c089ba6;
case 0x0c089ba8u: goto P_0c089ba8;
case 0x0c089baau: goto P_0c089baa;
case 0x0c089bacu: goto P_0c089bac;
case 0x0c089baeu: goto P_0c089bae;
case 0x0c089bb0u: goto P_0c089bb0;
case 0x0c089bb2u: goto P_0c089bb2;
case 0x0c089bb4u: goto P_0c089bb4;
case 0x0c089bb6u: goto P_0c089bb6;
case 0x0c089bb8u: goto P_0c089bb8;
case 0x0c089bbau: goto P_0c089bba;
case 0x0c089bbcu: goto P_0c089bbc;
case 0x0c089bbeu: goto P_0c089bbe;
case 0x0c089bc0u: goto P_0c089bc0;
case 0x0c089bc2u: goto P_0c089bc2;
case 0x0c089bc4u: goto P_0c089bc4;
case 0x0c089bc6u: goto P_0c089bc6;
case 0x0c089bc8u: goto P_0c089bc8;
case 0x0c089bcau: goto P_0c089bca;
case 0x0c089bccu: goto P_0c089bcc;
case 0x0c089bceu: goto P_0c089bce;
case 0x0c089bd0u: goto P_0c089bd0;
case 0x0c089bd2u: goto P_0c089bd2;
case 0x0c089bd4u: goto P_0c089bd4;
case 0x0c089bd6u: goto P_0c089bd6;
case 0x0c089bd8u: goto P_0c089bd8;
case 0x0c089bdau: goto P_0c089bda;
case 0x0c089bdcu: goto P_0c089bdc;
case 0x0c089bdeu: goto P_0c089bde;
case 0x0c089be0u: goto P_0c089be0;
case 0x0c089be2u: goto P_0c089be2;
case 0x0c089be4u: goto P_0c089be4;
case 0x0c089be6u: goto P_0c089be6;
case 0x0c089be8u: goto P_0c089be8;
case 0x0c089beau: goto P_0c089bea;
case 0x0c089becu: goto P_0c089bec;
case 0x0c089beeu: goto P_0c089bee;
case 0x0c089bf0u: goto P_0c089bf0;
case 0x0c089bf2u: goto P_0c089bf2;
case 0x0c089bf4u: goto P_0c089bf4;
case 0x0c089bf6u: goto P_0c089bf6;
case 0x0c089bf8u: goto P_0c089bf8;
case 0x0c089bfau: goto P_0c089bfa;
case 0x0c089bfcu: goto P_0c089bfc;
case 0x0c089bfeu: goto P_0c089bfe;
case 0x0c089c00u: goto P_0c089c00;
case 0x0c089c02u: goto P_0c089c02;
case 0x0c089c04u: goto P_0c089c04;
case 0x0c089c38u: goto P_0c089c38;
case 0x0c089c3au: goto P_0c089c3a;
case 0x0c089c3cu: goto P_0c089c3c;
case 0x0c089c3eu: goto P_0c089c3e;
case 0x0c089c40u: goto P_0c089c40;
case 0x0c089c42u: goto P_0c089c42;
case 0x0c089c44u: goto P_0c089c44;
case 0x0c089c46u: goto P_0c089c46;
case 0x0c089c48u: goto P_0c089c48;
case 0x0c089c4au: goto P_0c089c4a;
case 0x0c089c4cu: goto P_0c089c4c;
case 0x0c089c4eu: goto P_0c089c4e;
case 0x0c089c50u: goto P_0c089c50;
case 0x0c089c52u: goto P_0c089c52;
case 0x0c089c54u: goto P_0c089c54;
case 0x0c089c56u: goto P_0c089c56;
case 0x0c089c58u: goto P_0c089c58;
case 0x0c089c5au: goto P_0c089c5a;
case 0x0c089c5cu: goto P_0c089c5c;
case 0x0c089c5eu: goto P_0c089c5e;
case 0x0c089c60u: goto P_0c089c60;
case 0x0c089c62u: goto P_0c089c62;
case 0x0c089c64u: goto P_0c089c64;
case 0x0c089c66u: goto P_0c089c66;
case 0x0c089c68u: goto P_0c089c68;
case 0x0c089c6au: goto P_0c089c6a;
case 0x0c089c6cu: goto P_0c089c6c;
case 0x0c089c6eu: goto P_0c089c6e;
case 0x0c089c70u: goto P_0c089c70;
case 0x0c089c72u: goto P_0c089c72;
case 0x0c089c74u: goto P_0c089c74;
case 0x0c089c76u: goto P_0c089c76;
case 0x0c089c78u: goto P_0c089c78;
case 0x0c089c7au: goto P_0c089c7a;
case 0x0c089c7cu: goto P_0c089c7c;
case 0x0c089c7eu: goto P_0c089c7e;
case 0x0c089c80u: goto P_0c089c80;
case 0x0c089c82u: goto P_0c089c82;
case 0x0c089c84u: goto P_0c089c84;
case 0x0c089c86u: goto P_0c089c86;
case 0x0c089c88u: goto P_0c089c88;
case 0x0c089c8au: goto P_0c089c8a;
case 0x0c089c8cu: goto P_0c089c8c;
case 0x0c089c8eu: goto P_0c089c8e;
case 0x0c089c90u: goto P_0c089c90;
case 0x0c089c92u: goto P_0c089c92;
case 0x0c089c94u: goto P_0c089c94;
case 0x0c089c96u: goto P_0c089c96;
case 0x0c089c98u: goto P_0c089c98;
case 0x0c089c9au: goto P_0c089c9a;
case 0x0c089c9cu: goto P_0c089c9c;
case 0x0c089c9eu: goto P_0c089c9e;
case 0x0c089ca0u: goto P_0c089ca0;
case 0x0c089ca2u: goto P_0c089ca2;
case 0x0c089ca4u: goto P_0c089ca4;
case 0x0c089ca6u: goto P_0c089ca6;
case 0x0c089ca8u: goto P_0c089ca8;
case 0x0c089caau: goto P_0c089caa;
case 0x0c089cacu: goto P_0c089cac;
case 0x0c089caeu: goto P_0c089cae;
case 0x0c089cb0u: goto P_0c089cb0;
case 0x0c089cb2u: goto P_0c089cb2;
case 0x0c089cb4u: goto P_0c089cb4;
case 0x0c089cb6u: goto P_0c089cb6;
case 0x0c089cb8u: goto P_0c089cb8;
case 0x0c089cbau: goto P_0c089cba;
case 0x0c089cbcu: goto P_0c089cbc;
case 0x0c089cbeu: goto P_0c089cbe;
case 0x0c089cc0u: goto P_0c089cc0;
case 0x0c089cc2u: goto P_0c089cc2;
case 0x0c089cc4u: goto P_0c089cc4;
case 0x0c089cc6u: goto P_0c089cc6;
case 0x0c089cc8u: goto P_0c089cc8;
case 0x0c089ccau: goto P_0c089cca;
case 0x0c089cccu: goto P_0c089ccc;
case 0x0c089cceu: goto P_0c089cce;
case 0x0c089cd0u: goto P_0c089cd0;
case 0x0c089cd2u: goto P_0c089cd2;
case 0x0c089cd4u: goto P_0c089cd4;
case 0x0c089cd6u: goto P_0c089cd6;
case 0x0c089cd8u: goto P_0c089cd8;
case 0x0c089cdau: goto P_0c089cda;
case 0x0c089cdcu: goto P_0c089cdc;
case 0x0c089cdeu: goto P_0c089cde;
case 0x0c089ce0u: goto P_0c089ce0;
case 0x0c089ce2u: goto P_0c089ce2;
case 0x0c089ce4u: goto P_0c089ce4;
case 0x0c089ce6u: goto P_0c089ce6;
case 0x0c089ce8u: goto P_0c089ce8;
case 0x0c089ceau: goto P_0c089cea;
case 0x0c089cecu: goto P_0c089cec;
case 0x0c089ceeu: goto P_0c089cee;
case 0x0c089cf0u: goto P_0c089cf0;
case 0x0c089cf2u: goto P_0c089cf2;
case 0x0c089cf4u: goto P_0c089cf4;
case 0x0c089cf6u: goto P_0c089cf6;
case 0x0c089cf8u: goto P_0c089cf8;
case 0x0c089cfau: goto P_0c089cfa;
case 0x0c089cfcu: goto P_0c089cfc;
case 0x0c089cfeu: goto P_0c089cfe;
case 0x0c089d00u: goto P_0c089d00;
case 0x0c089d02u: goto P_0c089d02;
case 0x0c089d04u: goto P_0c089d04;
case 0x0c089d06u: goto P_0c089d06;
case 0x0c089d08u: goto P_0c089d08;
case 0x0c089d0au: goto P_0c089d0a;
case 0x0c089d0cu: goto P_0c089d0c;
case 0x0c089d0eu: goto P_0c089d0e;
case 0x0c089d10u: goto P_0c089d10;
case 0x0c089d12u: goto P_0c089d12;
case 0x0c089d14u: goto P_0c089d14;
case 0x0c089d16u: goto P_0c089d16;
case 0x0c089d18u: goto P_0c089d18;
case 0x0c089d1au: goto P_0c089d1a;
case 0x0c089d1cu: goto P_0c089d1c;
case 0x0c089d1eu: goto P_0c089d1e;
case 0x0c089d20u: goto P_0c089d20;
case 0x0c089d22u: goto P_0c089d22;
case 0x0c089d24u: goto P_0c089d24;
case 0x0c089d26u: goto P_0c089d26;
case 0x0c089d66u: goto P_0c089d66;
case 0x0c089d68u: goto P_0c089d68;
case 0x0c089d6au: goto P_0c089d6a;
case 0x0c089d6cu: goto P_0c089d6c;
case 0x0c089d6eu: goto P_0c089d6e;
case 0x0c089d70u: goto P_0c089d70;
case 0x0c089d72u: goto P_0c089d72;
case 0x0c089d74u: goto P_0c089d74;
case 0x0c089d76u: goto P_0c089d76;
case 0x0c089d78u: goto P_0c089d78;
case 0x0c089d7au: goto P_0c089d7a;
case 0x0c089d7cu: goto P_0c089d7c;
case 0x0c089d7eu: goto P_0c089d7e;
case 0x0c089d80u: goto P_0c089d80;
case 0x0c089d82u: goto P_0c089d82;
case 0x0c089d84u: goto P_0c089d84;
case 0x0c089d86u: goto P_0c089d86;
case 0x0c089d88u: goto P_0c089d88;
case 0x0c089d8au: goto P_0c089d8a;
case 0x0c089d8cu: goto P_0c089d8c;
case 0x0c089d8eu: goto P_0c089d8e;
case 0x0c089d90u: goto P_0c089d90;
case 0x0c089d92u: goto P_0c089d92;
case 0x0c089d94u: goto P_0c089d94;
case 0x0c089d96u: goto P_0c089d96;
case 0x0c089d98u: goto P_0c089d98;
case 0x0c089d9au: goto P_0c089d9a;
case 0x0c089d9cu: goto P_0c089d9c;
case 0x0c089d9eu: goto P_0c089d9e;
case 0x0c089da0u: goto P_0c089da0;
case 0x0c089da2u: goto P_0c089da2;
case 0x0c089da4u: goto P_0c089da4;
case 0x0c089da6u: goto P_0c089da6;
case 0x0c089da8u: goto P_0c089da8;
case 0x0c089daau: goto P_0c089daa;
case 0x0c089dacu: goto P_0c089dac;
case 0x0c089daeu: goto P_0c089dae;
case 0x0c089db0u: goto P_0c089db0;
case 0x0c089db2u: goto P_0c089db2;
case 0x0c089db4u: goto P_0c089db4;
case 0x0c089db6u: goto P_0c089db6;
case 0x0c089db8u: goto P_0c089db8;
case 0x0c089dbau: goto P_0c089dba;
case 0x0c089dbcu: goto P_0c089dbc;
case 0x0c089dbeu: goto P_0c089dbe;
case 0x0c089dc0u: goto P_0c089dc0;
case 0x0c089dc2u: goto P_0c089dc2;
case 0x0c089dc4u: goto P_0c089dc4;
case 0x0c089dc6u: goto P_0c089dc6;
case 0x0c089dc8u: goto P_0c089dc8;
case 0x0c089dcau: goto P_0c089dca;
case 0x0c089dccu: goto P_0c089dcc;
case 0x0c089dceu: goto P_0c089dce;
case 0x0c089dd0u: goto P_0c089dd0;
case 0x0c089dd2u: goto P_0c089dd2;
case 0x0c089dd4u: goto P_0c089dd4;
case 0x0c089dd6u: goto P_0c089dd6;
case 0x0c089dd8u: goto P_0c089dd8;
case 0x0c089ddau: goto P_0c089dda;
case 0x0c089ddcu: goto P_0c089ddc;
case 0x0c089ddeu: goto P_0c089dde;
case 0x0c089de0u: goto P_0c089de0;
case 0x0c089de2u: goto P_0c089de2;
case 0x0c089de4u: goto P_0c089de4;
case 0x0c089de6u: goto P_0c089de6;
case 0x0c089de8u: goto P_0c089de8;
case 0x0c089deau: goto P_0c089dea;
case 0x0c089decu: goto P_0c089dec;
case 0x0c089deeu: goto P_0c089dee;
case 0x0c089df0u: goto P_0c089df0;
case 0x0c089df2u: goto P_0c089df2;
case 0x0c089df4u: goto P_0c089df4;
case 0x0c089df6u: goto P_0c089df6;
case 0x0c089df8u: goto P_0c089df8;
case 0x0c089dfau: goto P_0c089dfa;
case 0x0c089dfcu: goto P_0c089dfc;
case 0x0c089dfeu: goto P_0c089dfe;
case 0x0c089e00u: goto P_0c089e00;
case 0x0c089e02u: goto P_0c089e02;
case 0x0c089e04u: goto P_0c089e04;
case 0x0c089e06u: goto P_0c089e06;
case 0x0c089e08u: goto P_0c089e08;
case 0x0c089e0au: goto P_0c089e0a;
case 0x0c089e0cu: goto P_0c089e0c;
case 0x0c089e0eu: goto P_0c089e0e;
case 0x0c089e10u: goto P_0c089e10;
case 0x0c089e12u: goto P_0c089e12;
case 0x0c089e14u: goto P_0c089e14;
case 0x0c089e16u: goto P_0c089e16;
case 0x0c089e18u: goto P_0c089e18;
case 0x0c089e1au: goto P_0c089e1a;
case 0x0c089e1cu: goto P_0c089e1c;
case 0x0c089e1eu: goto P_0c089e1e;
case 0x0c089e20u: goto P_0c089e20;
case 0x0c089e22u: goto P_0c089e22;
case 0x0c089e24u: goto P_0c089e24;
case 0x0c089e26u: goto P_0c089e26;
case 0x0c089e28u: goto P_0c089e28;
case 0x0c089e2au: goto P_0c089e2a;
case 0x0c089e2cu: goto P_0c089e2c;
case 0x0c089e2eu: goto P_0c089e2e;
case 0x0c089e40u: goto P_0c089e40;
case 0x0c089e42u: goto P_0c089e42;
case 0x0c089e44u: goto P_0c089e44;
case 0x0c089e46u: goto P_0c089e46;
case 0x0c089e48u: goto P_0c089e48;
case 0x0c089e4au: goto P_0c089e4a;
case 0x0c089e4cu: goto P_0c089e4c;
case 0x0c089e4eu: goto P_0c089e4e;
case 0x0c089e50u: goto P_0c089e50;
case 0x0c089e52u: goto P_0c089e52;
case 0x0c089e54u: goto P_0c089e54;
case 0x0c089e56u: goto P_0c089e56;
case 0x0c089e58u: goto P_0c089e58;
case 0x0c089e5au: goto P_0c089e5a;
case 0x0c089e5cu: goto P_0c089e5c;
case 0x0c089e5eu: goto P_0c089e5e;
case 0x0c089e60u: goto P_0c089e60;
case 0x0c089e62u: goto P_0c089e62;
case 0x0c089e64u: goto P_0c089e64;
case 0x0c089e66u: goto P_0c089e66;
case 0x0c089e68u: goto P_0c089e68;
case 0x0c089e6au: goto P_0c089e6a;
case 0x0c089e6cu: goto P_0c089e6c;
case 0x0c089e6eu: goto P_0c089e6e;
case 0x0c089e84u: goto P_0c089e84;
case 0x0c089e86u: goto P_0c089e86;
case 0x0c089e88u: goto P_0c089e88;
case 0x0c089e8au: goto P_0c089e8a;
case 0x0c089e8cu: goto P_0c089e8c;
case 0x0c089e8eu: goto P_0c089e8e;
case 0x0c089e90u: goto P_0c089e90;
case 0x0c089e92u: goto P_0c089e92;
case 0x0c089e94u: goto P_0c089e94;
case 0x0c089e96u: goto P_0c089e96;
case 0x0c089e98u: goto P_0c089e98;
case 0x0c089e9au: goto P_0c089e9a;
case 0x0c089e9cu: goto P_0c089e9c;
case 0x0c089e9eu: goto P_0c089e9e;
case 0x0c089ea0u: goto P_0c089ea0;
case 0x0c089ea2u: goto P_0c089ea2;
case 0x0c089ea4u: goto P_0c089ea4;
case 0x0c089ea6u: goto P_0c089ea6;
case 0x0c089ea8u: goto P_0c089ea8;
case 0x0c089eaau: goto P_0c089eaa;
case 0x0c089eacu: goto P_0c089eac;
case 0x0c089eaeu: goto P_0c089eae;
case 0x0c089eb0u: goto P_0c089eb0;
case 0x0c089eb2u: goto P_0c089eb2;
case 0x0c089eb4u: goto P_0c089eb4;
case 0x0c089eb6u: goto P_0c089eb6;
case 0x0c089eb8u: goto P_0c089eb8;
case 0x0c089ebau: goto P_0c089eba;
case 0x0c089ebcu: goto P_0c089ebc;
case 0x0c089ebeu: goto P_0c089ebe;
case 0x0c089ec0u: goto P_0c089ec0;
case 0x0c089ec2u: goto P_0c089ec2;
case 0x0c089ec4u: goto P_0c089ec4;
case 0x0c089ec6u: goto P_0c089ec6;
case 0x0c089ec8u: goto P_0c089ec8;
case 0x0c089ecau: goto P_0c089eca;
case 0x0c089eccu: goto P_0c089ecc;
case 0x0c089eceu: goto P_0c089ece;
case 0x0c089ed0u: goto P_0c089ed0;
case 0x0c089ed2u: goto P_0c089ed2;
case 0x0c089ed4u: goto P_0c089ed4;
case 0x0c089ed6u: goto P_0c089ed6;
case 0x0c089ed8u: goto P_0c089ed8;
case 0x0c089edau: goto P_0c089eda;
case 0x0c089edcu: goto P_0c089edc;
case 0x0c089edeu: goto P_0c089ede;
case 0x0c089ee0u: goto P_0c089ee0;
case 0x0c089ee2u: goto P_0c089ee2;
case 0x0c089ee4u: goto P_0c089ee4;
case 0x0c089ee6u: goto P_0c089ee6;
case 0x0c089ee8u: goto P_0c089ee8;
case 0x0c089eeau: goto P_0c089eea;
case 0x0c089eecu: goto P_0c089eec;
case 0x0c089eeeu: goto P_0c089eee;
case 0x0c089ef0u: goto P_0c089ef0;
case 0x0c089ef2u: goto P_0c089ef2;
case 0x0c089ef4u: goto P_0c089ef4;
case 0x0c089ef6u: goto P_0c089ef6;
case 0x0c089ef8u: goto P_0c089ef8;
case 0x0c089efau: goto P_0c089efa;
case 0x0c089efcu: goto P_0c089efc;
case 0x0c089efeu: goto P_0c089efe;
case 0x0c089f00u: goto P_0c089f00;
case 0x0c089f02u: goto P_0c089f02;
case 0x0c089f04u: goto P_0c089f04;
case 0x0c089f06u: goto P_0c089f06;
case 0x0c089f08u: goto P_0c089f08;
case 0x0c089f0au: goto P_0c089f0a;
case 0x0c089f0cu: goto P_0c089f0c;
case 0x0c089f0eu: goto P_0c089f0e;
case 0x0c089f10u: goto P_0c089f10;
case 0x0c089f12u: goto P_0c089f12;
case 0x0c089f14u: goto P_0c089f14;
case 0x0c089f16u: goto P_0c089f16;
case 0x0c089f18u: goto P_0c089f18;
case 0x0c089f1au: goto P_0c089f1a;
case 0x0c089f1cu: goto P_0c089f1c;
case 0x0c089f1eu: goto P_0c089f1e;
case 0x0c089f20u: goto P_0c089f20;
case 0x0c089f22u: goto P_0c089f22;
case 0x0c089f24u: goto P_0c089f24;
case 0x0c089f26u: goto P_0c089f26;
case 0x0c089f28u: goto P_0c089f28;
case 0x0c089f2au: goto P_0c089f2a;
case 0x0c089f2cu: goto P_0c089f2c;
case 0x0c089f2eu: goto P_0c089f2e;
case 0x0c089f30u: goto P_0c089f30;
case 0x0c089f32u: goto P_0c089f32;
case 0x0c089f34u: goto P_0c089f34;
case 0x0c089f36u: goto P_0c089f36;
case 0x0c089f38u: goto P_0c089f38;
case 0x0c089f3au: goto P_0c089f3a;
case 0x0c089f3cu: goto P_0c089f3c;
case 0x0c089f3eu: goto P_0c089f3e;
case 0x0c089f40u: goto P_0c089f40;
case 0x0c089f42u: goto P_0c089f42;
case 0x0c089f44u: goto P_0c089f44;
case 0x0c089f46u: goto P_0c089f46;
case 0x0c089f48u: goto P_0c089f48;
case 0x0c089f4au: goto P_0c089f4a;
case 0x0c089f4cu: goto P_0c089f4c;
case 0x0c089f4eu: goto P_0c089f4e;
case 0x0c089f50u: goto P_0c089f50;
case 0x0c089f52u: goto P_0c089f52;
case 0x0c089f54u: goto P_0c089f54;
case 0x0c089f56u: goto P_0c089f56;
case 0x0c089f58u: goto P_0c089f58;
case 0x0c089f5au: goto P_0c089f5a;
case 0x0c089f5cu: goto P_0c089f5c;
case 0x0c089f5eu: goto P_0c089f5e;
case 0x0c089f60u: goto P_0c089f60;
case 0x0c089f62u: goto P_0c089f62;
case 0x0c089f64u: goto P_0c089f64;
case 0x0c089f66u: goto P_0c089f66;
case 0x0c089f68u: goto P_0c089f68;
case 0x0c089f6au: goto P_0c089f6a;
case 0x0c089f6cu: goto P_0c089f6c;
case 0x0c089f6eu: goto P_0c089f6e;
case 0x0c089f70u: goto P_0c089f70;
case 0x0c089f72u: goto P_0c089f72;
case 0x0c089f74u: goto P_0c089f74;
case 0x0c089f76u: goto P_0c089f76;
case 0x0c089f78u: goto P_0c089f78;
case 0x0c089f7au: goto P_0c089f7a;
case 0x0c089f7cu: goto P_0c089f7c;
case 0x0c089f7eu: goto P_0c089f7e;
case 0x0c089f80u: goto P_0c089f80;
case 0x0c089f82u: goto P_0c089f82;
case 0x0c089f84u: goto P_0c089f84;
case 0x0c089f86u: goto P_0c089f86;
case 0x0c089f88u: goto P_0c089f88;
case 0x0c089f8au: goto P_0c089f8a;
case 0x0c089f8cu: goto P_0c089f8c;
case 0x0c093390u: goto P_0c093390;
case 0x0c093392u: goto P_0c093392;
case 0x0c093394u: goto P_0c093394;
case 0x0c093396u: goto P_0c093396;
case 0x0c093398u: goto P_0c093398;
case 0x0c09339au: goto P_0c09339a;
case 0x0c09339cu: goto P_0c09339c;
case 0x0c09339eu: goto P_0c09339e;
case 0x0c0933a0u: goto P_0c0933a0;
case 0x0c0933a2u: goto P_0c0933a2;
case 0x0c0933a4u: goto P_0c0933a4;
case 0x0c0933a6u: goto P_0c0933a6;
case 0x0c0933a8u: goto P_0c0933a8;
case 0x0c0933aau: goto P_0c0933aa;
case 0x0c0933acu: goto P_0c0933ac;
case 0x0c0933aeu: goto P_0c0933ae;
case 0x0c0933b0u: goto P_0c0933b0;
case 0x0c0933b2u: goto P_0c0933b2;
case 0x0c0933b4u: goto P_0c0933b4;
case 0x0c0933b6u: goto P_0c0933b6;
case 0x0c0933b8u: goto P_0c0933b8;
case 0x0c0933bau: goto P_0c0933ba;
case 0x0c0933bcu: goto P_0c0933bc;
case 0x0c0933beu: goto P_0c0933be;
case 0x0c0933c0u: goto P_0c0933c0;
case 0x0c0933c2u: goto P_0c0933c2;
case 0x0c0933c4u: goto P_0c0933c4;
case 0x0c0933c6u: goto P_0c0933c6;
case 0x0c0933c8u: goto P_0c0933c8;
case 0x0c0933cau: goto P_0c0933ca;
case 0x0c0933ccu: goto P_0c0933cc;
case 0x0c0933ceu: goto P_0c0933ce;
case 0x0c0933d0u: goto P_0c0933d0;
case 0x0c0933d2u: goto P_0c0933d2;
case 0x0c0933d4u: goto P_0c0933d4;
case 0x0c0933d6u: goto P_0c0933d6;
case 0x0c0933d8u: goto P_0c0933d8;
case 0x0c0933dau: goto P_0c0933da;
case 0x0c0933dcu: goto P_0c0933dc;
case 0x0c0933deu: goto P_0c0933de;
case 0x0c0933e0u: goto P_0c0933e0;
case 0x0c0933e2u: goto P_0c0933e2;
case 0x0c0933e4u: goto P_0c0933e4;
case 0x0c0933e6u: goto P_0c0933e6;
case 0x0c0933e8u: goto P_0c0933e8;
case 0x0c0933eau: goto P_0c0933ea;
case 0x0c0933ecu: goto P_0c0933ec;
case 0x0c0933eeu: goto P_0c0933ee;
case 0x0c0933f0u: goto P_0c0933f0;
case 0x0c0933f2u: goto P_0c0933f2;
case 0x0c0933f4u: goto P_0c0933f4;
case 0x0c0933f6u: goto P_0c0933f6;
case 0x0c0933f8u: goto P_0c0933f8;
case 0x0c0933fau: goto P_0c0933fa;
case 0x0c0933fcu: goto P_0c0933fc;
case 0x0c0933feu: goto P_0c0933fe;
case 0x0c093400u: goto P_0c093400;
case 0x0c093402u: goto P_0c093402;
case 0x0c093404u: goto P_0c093404;
case 0x0c093406u: goto P_0c093406;
case 0x0c093408u: goto P_0c093408;
case 0x0c09340au: goto P_0c09340a;
case 0x0c09340cu: goto P_0c09340c;
case 0x0c09340eu: goto P_0c09340e;
case 0x0c093410u: goto P_0c093410;
case 0x0c09abc4u: goto P_0c09abc4;
case 0x0c09abc6u: goto P_0c09abc6;
case 0x0c09abc8u: goto P_0c09abc8;
case 0x0c09abcau: goto P_0c09abca;
case 0x0c09abccu: goto P_0c09abcc;
case 0x0c09abceu: goto P_0c09abce;
case 0x0c09abd0u: goto P_0c09abd0;
case 0x0c09abd2u: goto P_0c09abd2;
case 0x0c09abd4u: goto P_0c09abd4;
case 0x0c09abd6u: goto P_0c09abd6;
case 0x0c09abd8u: goto P_0c09abd8;
case 0x0c09abdau: goto P_0c09abda;
case 0x0c09abdcu: goto P_0c09abdc;
case 0x0c09abdeu: goto P_0c09abde;
case 0x0c09abe0u: goto P_0c09abe0;
case 0x0c09abe2u: goto P_0c09abe2;
case 0x0c09abe4u: goto P_0c09abe4;
case 0x0c09abe6u: goto P_0c09abe6;
case 0x0c09abe8u: goto P_0c09abe8;
case 0x0c09abeau: goto P_0c09abea;
case 0x0c09abecu: goto P_0c09abec;
case 0x0c09abeeu: goto P_0c09abee;
case 0x0c09abf0u: goto P_0c09abf0;
case 0x0c09abf2u: goto P_0c09abf2;
case 0x0c09abf4u: goto P_0c09abf4;
case 0x0c09abf6u: goto P_0c09abf6;
case 0x0c09abf8u: goto P_0c09abf8;
case 0x0c09abfau: goto P_0c09abfa;
case 0x0c09abfcu: goto P_0c09abfc;
case 0x0c09abfeu: goto P_0c09abfe;
case 0x0c09ac00u: goto P_0c09ac00;
case 0x0c09ac02u: goto P_0c09ac02;
case 0x0c09ac04u: goto P_0c09ac04;
case 0x0c09d844u: goto P_0c09d844;
case 0x0c09d846u: goto P_0c09d846;
case 0x0c09d848u: goto P_0c09d848;
case 0x0c09d84au: goto P_0c09d84a;
case 0x0c09d84cu: goto P_0c09d84c;
case 0x0c09d84eu: goto P_0c09d84e;
case 0x0c09d850u: goto P_0c09d850;
case 0x0c09d852u: goto P_0c09d852;
case 0x0c09d854u: goto P_0c09d854;
case 0x0c09d856u: goto P_0c09d856;
case 0x0c09d858u: goto P_0c09d858;
case 0x0c09d85au: goto P_0c09d85a;
case 0x0c09d85cu: goto P_0c09d85c;
case 0x0c09d85eu: goto P_0c09d85e;
case 0x0c09d860u: goto P_0c09d860;
case 0x0c09d862u: goto P_0c09d862;
case 0x0c09d864u: goto P_0c09d864;
case 0x0c09d866u: goto P_0c09d866;
case 0x0c09d868u: goto P_0c09d868;
case 0x0c09d86au: goto P_0c09d86a;
case 0x0c09d86cu: goto P_0c09d86c;
case 0x0c09d86eu: goto P_0c09d86e;
case 0x0c09d870u: goto P_0c09d870;
case 0x0c09d872u: goto P_0c09d872;
case 0x0c09d874u: goto P_0c09d874;
case 0x0c09d876u: goto P_0c09d876;
case 0x0c09d878u: goto P_0c09d878;
case 0x0c09d87au: goto P_0c09d87a;
case 0x0c09d87cu: goto P_0c09d87c;
case 0x0c09d87eu: goto P_0c09d87e;
case 0x0c09d880u: goto P_0c09d880;
case 0x0c09d882u: goto P_0c09d882;
case 0x0c09d884u: goto P_0c09d884;
case 0x0c09d886u: goto P_0c09d886;
case 0x0c09d888u: goto P_0c09d888;
case 0x0c09d88au: goto P_0c09d88a;
case 0x0c09d88cu: goto P_0c09d88c;
case 0x0c09d88eu: goto P_0c09d88e;
case 0x0c09d890u: goto P_0c09d890;
case 0x0c09d892u: goto P_0c09d892;
case 0x0c09d894u: goto P_0c09d894;
case 0x0c09d896u: goto P_0c09d896;
case 0x0c09d898u: goto P_0c09d898;
case 0x0c09d89au: goto P_0c09d89a;
case 0x0c09d89cu: goto P_0c09d89c;
case 0x0c09d89eu: goto P_0c09d89e;
case 0x0c09d8a0u: goto P_0c09d8a0;
case 0x0c09d8a2u: goto P_0c09d8a2;
case 0x0c09d8a4u: goto P_0c09d8a4;
case 0x0c09d8a6u: goto P_0c09d8a6;
case 0x0c09d8a8u: goto P_0c09d8a8;
case 0x0c09d8aau: goto P_0c09d8aa;
case 0x0c09d8acu: goto P_0c09d8ac;
case 0x0c09d8aeu: goto P_0c09d8ae;
case 0x0c09d8b0u: goto P_0c09d8b0;
case 0x0c09d8b2u: goto P_0c09d8b2;
case 0x0c09d8b4u: goto P_0c09d8b4;
case 0x0c09d8b6u: goto P_0c09d8b6;
case 0x0c09d8b8u: goto P_0c09d8b8;
case 0x0c09d8bau: goto P_0c09d8ba;
case 0x0c09d8bcu: goto P_0c09d8bc;
case 0x0c09d8beu: goto P_0c09d8be;
case 0x0c09d8c0u: goto P_0c09d8c0;
case 0x0c09d8c2u: goto P_0c09d8c2;
case 0x0c09d8c4u: goto P_0c09d8c4;
case 0x0c09d8c6u: goto P_0c09d8c6;
case 0x0c09d8c8u: goto P_0c09d8c8;
case 0x0c09d8cau: goto P_0c09d8ca;
case 0x0c09d8ccu: goto P_0c09d8cc;
case 0x0c09d8ceu: goto P_0c09d8ce;
case 0x0c09d8d0u: goto P_0c09d8d0;
case 0x0c09d8d2u: goto P_0c09d8d2;
case 0x0c09d8d4u: goto P_0c09d8d4;
case 0x0c09d8d6u: goto P_0c09d8d6;
case 0x0c09d8d8u: goto P_0c09d8d8;
case 0x0c09d8dau: goto P_0c09d8da;
case 0x0c09d8dcu: goto P_0c09d8dc;
case 0x0c09d8deu: goto P_0c09d8de;
case 0x0c09d8e0u: goto P_0c09d8e0;
case 0x0c09d8e2u: goto P_0c09d8e2;
case 0x0c09d8e4u: goto P_0c09d8e4;
case 0x0c09d8e6u: goto P_0c09d8e6;
case 0x0c09d8e8u: goto P_0c09d8e8;
case 0x0c09d8eau: goto P_0c09d8ea;
case 0x0c09d8ecu: goto P_0c09d8ec;
case 0x0c09d8eeu: goto P_0c09d8ee;
case 0x0c09d8f0u: goto P_0c09d8f0;
case 0x0c09d8f2u: goto P_0c09d8f2;
case 0x0c09d8f4u: goto P_0c09d8f4;
case 0x0c09d8f6u: goto P_0c09d8f6;
case 0x0c09d8f8u: goto P_0c09d8f8;
case 0x0c09d8fau: goto P_0c09d8fa;
case 0x0c09d8fcu: goto P_0c09d8fc;
case 0x0c09d8feu: goto P_0c09d8fe;
case 0x0c09d900u: goto P_0c09d900;
case 0x0c09d902u: goto P_0c09d902;
case 0x0c09d904u: goto P_0c09d904;
case 0x0c09d906u: goto P_0c09d906;
case 0x0c09d908u: goto P_0c09d908;
case 0x0c09d90au: goto P_0c09d90a;
case 0x0c09d90cu: goto P_0c09d90c;
case 0x0c09d90eu: goto P_0c09d90e;
case 0x0c09d910u: goto P_0c09d910;
case 0x0c09d912u: goto P_0c09d912;
case 0x0c09d914u: goto P_0c09d914;
case 0x0c09d916u: goto P_0c09d916;
case 0x0c09d918u: goto P_0c09d918;
case 0x0c09d91au: goto P_0c09d91a;
case 0x0c09d91cu: goto P_0c09d91c;
case 0x0c09d91eu: goto P_0c09d91e;
case 0x0c09d920u: goto P_0c09d920;
case 0x0c09d922u: goto P_0c09d922;
case 0x0c09d924u: goto P_0c09d924;
case 0x0c09d926u: goto P_0c09d926;
case 0x0c09d928u: goto P_0c09d928;
case 0x0c09d92au: goto P_0c09d92a;
case 0x0c09d92cu: goto P_0c09d92c;
case 0x0c09d92eu: goto P_0c09d92e;
case 0x0c09d930u: goto P_0c09d930;
case 0x0c09d932u: goto P_0c09d932;
case 0x0c09d934u: goto P_0c09d934;
case 0x0c09d936u: goto P_0c09d936;
case 0x0c09d938u: goto P_0c09d938;
case 0x0c09d93au: goto P_0c09d93a;
case 0x0c09d93cu: goto P_0c09d93c;
case 0x0c09d93eu: goto P_0c09d93e;
case 0x0c09d940u: goto P_0c09d940;
case 0x0c09d942u: goto P_0c09d942;
case 0x0c09d944u: goto P_0c09d944;
case 0x0c09d946u: goto P_0c09d946;
case 0x0c09d948u: goto P_0c09d948;
case 0x0c09d94au: goto P_0c09d94a;
case 0x0c09d94cu: goto P_0c09d94c;
case 0x0c09d94eu: goto P_0c09d94e;
case 0x0c09d950u: goto P_0c09d950;
case 0x0c09d952u: goto P_0c09d952;
case 0x0c09d954u: goto P_0c09d954;
case 0x0c09d956u: goto P_0c09d956;
case 0x0c09d958u: goto P_0c09d958;
case 0x0c09d95au: goto P_0c09d95a;
case 0x0c09d95cu: goto P_0c09d95c;
case 0x0c09d95eu: goto P_0c09d95e;
case 0x0c09d960u: goto P_0c09d960;
case 0x0c09d962u: goto P_0c09d962;
case 0x0c09d964u: goto P_0c09d964;
case 0x0c09d966u: goto P_0c09d966;
case 0x0c09d968u: goto P_0c09d968;
case 0x0c09d96au: goto P_0c09d96a;
case 0x0c09d96cu: goto P_0c09d96c;
case 0x0c09d96eu: goto P_0c09d96e;
case 0x0c09d970u: goto P_0c09d970;
case 0x0c09d972u: goto P_0c09d972;
case 0x0c09d974u: goto P_0c09d974;
case 0x0c09d976u: goto P_0c09d976;
case 0x0c09d978u: goto P_0c09d978;
case 0x0c09d98cu: goto P_0c09d98c;
case 0x0c09d98eu: goto P_0c09d98e;
case 0x0c09d990u: goto P_0c09d990;
case 0x0c09d992u: goto P_0c09d992;
case 0x0c09d994u: goto P_0c09d994;
case 0x0c09d996u: goto P_0c09d996;
case 0x0c09d998u: goto P_0c09d998;
case 0x0c09d99au: goto P_0c09d99a;
case 0x0c09d99cu: goto P_0c09d99c;
case 0x0c09d99eu: goto P_0c09d99e;
case 0x0c09d9a0u: goto P_0c09d9a0;
case 0x0c09d9a2u: goto P_0c09d9a2;
case 0x0c09d9a4u: goto P_0c09d9a4;
case 0x0c09d9a6u: goto P_0c09d9a6;
case 0x0c09d9a8u: goto P_0c09d9a8;
case 0x0c09d9aau: goto P_0c09d9aa;
case 0x0c09d9acu: goto P_0c09d9ac;
case 0x0c09d9aeu: goto P_0c09d9ae;
case 0x0c09d9b0u: goto P_0c09d9b0;
case 0x0c09d9b2u: goto P_0c09d9b2;
case 0x0c09d9b4u: goto P_0c09d9b4;
case 0x0c09d9b6u: goto P_0c09d9b6;
case 0x0c09d9b8u: goto P_0c09d9b8;
case 0x0c09d9bau: goto P_0c09d9ba;
case 0x0c09d9bcu: goto P_0c09d9bc;
case 0x0c09d9beu: goto P_0c09d9be;
case 0x0c09d9c0u: goto P_0c09d9c0;
case 0x0c09d9c2u: goto P_0c09d9c2;
case 0x0c09d9c4u: goto P_0c09d9c4;
case 0x0c09d9c6u: goto P_0c09d9c6;
case 0x0c09d9c8u: goto P_0c09d9c8;
case 0x0c09d9cau: goto P_0c09d9ca;
case 0x0c09d9ccu: goto P_0c09d9cc;
case 0x0c09d9ceu: goto P_0c09d9ce;
case 0x0c09d9d0u: goto P_0c09d9d0;
case 0x0c09d9d2u: goto P_0c09d9d2;
case 0x0c09d9d4u: goto P_0c09d9d4;
case 0x0c09d9d6u: goto P_0c09d9d6;
case 0x0c09d9d8u: goto P_0c09d9d8;
case 0x0c09d9dau: goto P_0c09d9da;
case 0x0c09d9dcu: goto P_0c09d9dc;
case 0x0c09d9deu: goto P_0c09d9de;
case 0x0c09d9e0u: goto P_0c09d9e0;
case 0x0c09d9e2u: goto P_0c09d9e2;
case 0x0c09d9e4u: goto P_0c09d9e4;
case 0x0c09d9e6u: goto P_0c09d9e6;
case 0x0c09d9e8u: goto P_0c09d9e8;
case 0x0c0a2f90u: goto P_0c0a2f90;
case 0x0c0a2f92u: goto P_0c0a2f92;
case 0x0c0a2f94u: goto P_0c0a2f94;
case 0x0c0a2f96u: goto P_0c0a2f96;
case 0x0c0a2f98u: goto P_0c0a2f98;
case 0x0c0a2f9au: goto P_0c0a2f9a;
case 0x0c0a2f9cu: goto P_0c0a2f9c;
case 0x0c0a2f9eu: goto P_0c0a2f9e;
case 0x0c0a2fa0u: goto P_0c0a2fa0;
case 0x0c0a2fa2u: goto P_0c0a2fa2;
case 0x0c0a2fa4u: goto P_0c0a2fa4;
case 0x0c0a2fa6u: goto P_0c0a2fa6;
case 0x0c0a2fa8u: goto P_0c0a2fa8;
case 0x0c0a2faau: goto P_0c0a2faa;
case 0x0c0a2facu: goto P_0c0a2fac;
case 0x0c0a2faeu: goto P_0c0a2fae;
case 0x0c0a2fb0u: goto P_0c0a2fb0;
case 0x0c0a2fb2u: goto P_0c0a2fb2;
case 0x0c0a2fb4u: goto P_0c0a2fb4;
case 0x0c0a2fb6u: goto P_0c0a2fb6;
case 0x0c0a2fb8u: goto P_0c0a2fb8;
case 0x0c0a2fbau: goto P_0c0a2fba;
case 0x0c0a2fbcu: goto P_0c0a2fbc;
case 0x0c0a2fbeu: goto P_0c0a2fbe;
case 0x0c0a2fc0u: goto P_0c0a2fc0;
case 0x0c0a2fc2u: goto P_0c0a2fc2;
case 0x0c0a2fc4u: goto P_0c0a2fc4;
case 0x0c0a2fc6u: goto P_0c0a2fc6;
case 0x0c0a2fc8u: goto P_0c0a2fc8;
case 0x0c0a2fcau: goto P_0c0a2fca;
case 0x0c0a2fccu: goto P_0c0a2fcc;
case 0x0c0a2fceu: goto P_0c0a2fce;
case 0x0c0a2fd0u: goto P_0c0a2fd0;
case 0x0c0a2fd2u: goto P_0c0a2fd2;
case 0x0c0a2fd4u: goto P_0c0a2fd4;
case 0x0c0a2fd6u: goto P_0c0a2fd6;
case 0x0c0a2fd8u: goto P_0c0a2fd8;
case 0x0c0a2fdau: goto P_0c0a2fda;
case 0x0c0a2fdcu: goto P_0c0a2fdc;
case 0x0c0a2fdeu: goto P_0c0a2fde;
case 0x0c0a2fe0u: goto P_0c0a2fe0;
case 0x0c0a2fe2u: goto P_0c0a2fe2;
case 0x0c0a2fe4u: goto P_0c0a2fe4;
case 0x0c0a2fe6u: goto P_0c0a2fe6;
case 0x0c0a2fe8u: goto P_0c0a2fe8;
case 0x0c0a2feau: goto P_0c0a2fea;
case 0x0c0a2fecu: goto P_0c0a2fec;
case 0x0c0a2feeu: goto P_0c0a2fee;
case 0x0c0a2ff0u: goto P_0c0a2ff0;
case 0x0c0a2ff2u: goto P_0c0a2ff2;
case 0x0c0a2ff4u: goto P_0c0a2ff4;
case 0x0c0a2ff6u: goto P_0c0a2ff6;
case 0x0c0a2ff8u: goto P_0c0a2ff8;
case 0x0c0a2ffau: goto P_0c0a2ffa;
case 0x0c0a2ffcu: goto P_0c0a2ffc;
case 0x0c0a2ffeu: goto P_0c0a2ffe;
case 0x0c0a3000u: goto P_0c0a3000;
case 0x0c0a3002u: goto P_0c0a3002;
case 0x0c0a3004u: goto P_0c0a3004;
case 0x0c0a3006u: goto P_0c0a3006;
case 0x0c0a3008u: goto P_0c0a3008;
case 0x0c0a300au: goto P_0c0a300a;
case 0x0c0a300cu: goto P_0c0a300c;
case 0x0c0a300eu: goto P_0c0a300e;
case 0x0c0a3010u: goto P_0c0a3010;
case 0x0c0a3012u: goto P_0c0a3012;
case 0x0c0a3014u: goto P_0c0a3014;
case 0x0c0a3016u: goto P_0c0a3016;
case 0x0c0a3018u: goto P_0c0a3018;
case 0x0c0a301au: goto P_0c0a301a;
case 0x0c0a301cu: goto P_0c0a301c;
case 0x0c0a301eu: goto P_0c0a301e;
case 0x0c0a3020u: goto P_0c0a3020;
case 0x0c0a3022u: goto P_0c0a3022;
case 0x0c0a3024u: goto P_0c0a3024;
case 0x0c0a3026u: goto P_0c0a3026;
case 0x0c0a3028u: goto P_0c0a3028;
case 0x0c0ace3eu: goto P_0c0ace3e;
case 0x0c0ace40u: goto P_0c0ace40;
case 0x0c0ace42u: goto P_0c0ace42;
case 0x0c0ace44u: goto P_0c0ace44;
case 0x0c0ace46u: goto P_0c0ace46;
case 0x0c0ace48u: goto P_0c0ace48;
case 0x0c0ace4au: goto P_0c0ace4a;
case 0x0c0ace4cu: goto P_0c0ace4c;
case 0x0c0ace4eu: goto P_0c0ace4e;
case 0x0c0ace50u: goto P_0c0ace50;
case 0x0c0ace52u: goto P_0c0ace52;
case 0x0c0ace54u: goto P_0c0ace54;
case 0x0c0ace56u: goto P_0c0ace56;
case 0x0c0ace58u: goto P_0c0ace58;
case 0x0c0ace5au: goto P_0c0ace5a;
case 0x0c0ace5cu: goto P_0c0ace5c;
case 0x0c0ace5eu: goto P_0c0ace5e;
case 0x0c0ace60u: goto P_0c0ace60;
case 0x0c0ace62u: goto P_0c0ace62;
case 0x0c0ace64u: goto P_0c0ace64;
case 0x0c0ace66u: goto P_0c0ace66;
case 0x0c0ace68u: goto P_0c0ace68;
case 0x0c0ace6au: goto P_0c0ace6a;
case 0x0c0ace6cu: goto P_0c0ace6c;
case 0x0c0ace6eu: goto P_0c0ace6e;
case 0x0c0ace70u: goto P_0c0ace70;
case 0x0c0ace72u: goto P_0c0ace72;
case 0x0c0ace74u: goto P_0c0ace74;
case 0x0c0ace76u: goto P_0c0ace76;
case 0x0c0ace78u: goto P_0c0ace78;
case 0x0c0ace7au: goto P_0c0ace7a;
case 0x0c0ace7cu: goto P_0c0ace7c;
case 0x0c0ace7eu: goto P_0c0ace7e;
case 0x0c0ace80u: goto P_0c0ace80;
case 0x0c0ace82u: goto P_0c0ace82;
case 0x0c0ace84u: goto P_0c0ace84;
case 0x0c0ace86u: goto P_0c0ace86;
case 0x0c0ace88u: goto P_0c0ace88;
case 0x0c0ace8au: goto P_0c0ace8a;
case 0x0c0ace8cu: goto P_0c0ace8c;
case 0x0c0ace8eu: goto P_0c0ace8e;
case 0x0c0ace90u: goto P_0c0ace90;
case 0x0c0ace92u: goto P_0c0ace92;
case 0x0c0ace94u: goto P_0c0ace94;
case 0x0c0ace96u: goto P_0c0ace96;
case 0x0c0ace98u: goto P_0c0ace98;
case 0x0c0ace9au: goto P_0c0ace9a;
case 0x0c0ace9cu: goto P_0c0ace9c;
case 0x0c0ace9eu: goto P_0c0ace9e;
case 0x0c0acea0u: goto P_0c0acea0;
case 0x0c0acea2u: goto P_0c0acea2;
case 0x0c0acea4u: goto P_0c0acea4;
case 0x0c0acea6u: goto P_0c0acea6;
case 0x0c0acea8u: goto P_0c0acea8;
case 0x0c0aceaau: goto P_0c0aceaa;
case 0x0c0aceacu: goto P_0c0aceac;
case 0x0c0aceaeu: goto P_0c0aceae;
case 0x0c0aceb0u: goto P_0c0aceb0;
case 0x0c0aceb2u: goto P_0c0aceb2;
case 0x0c0aceb4u: goto P_0c0aceb4;
case 0x0c0aceb6u: goto P_0c0aceb6;
case 0x0c0aceb8u: goto P_0c0aceb8;
case 0x0c0acebau: goto P_0c0aceba;
case 0x0c0acebcu: goto P_0c0acebc;
case 0x0c0acebeu: goto P_0c0acebe;
case 0x0c0acec0u: goto P_0c0acec0;
case 0x0c0acec2u: goto P_0c0acec2;
case 0x0c0acec4u: goto P_0c0acec4;
case 0x0c0acec6u: goto P_0c0acec6;
case 0x0c0acec8u: goto P_0c0acec8;
case 0x0c0acecau: goto P_0c0aceca;
case 0x0c0aceccu: goto P_0c0acecc;
case 0x0c0aceceu: goto P_0c0acece;
case 0x0c0aced0u: goto P_0c0aced0;
case 0x0c0aced2u: goto P_0c0aced2;
case 0x0c0aced4u: goto P_0c0aced4;
case 0x0c0aced6u: goto P_0c0aced6;
case 0x0c0aced8u: goto P_0c0aced8;
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
case 0x0c0c6482u: goto P_0c0c6482;
case 0x0c0c6484u: goto P_0c0c6484;
case 0x0c0c6486u: goto P_0c0c6486;
case 0x0c0c6488u: goto P_0c0c6488;
case 0x0c0c648au: goto P_0c0c648a;
case 0x0c0c648cu: goto P_0c0c648c;
case 0x0c0c648eu: goto P_0c0c648e;
case 0x0c0c6490u: goto P_0c0c6490;
case 0x0c0c6492u: goto P_0c0c6492;
case 0x0c0c6494u: goto P_0c0c6494;
case 0x0c0c6496u: goto P_0c0c6496;
case 0x0c0c6498u: goto P_0c0c6498;
case 0x0c0c649au: goto P_0c0c649a;
case 0x0c0c649cu: goto P_0c0c649c;
case 0x0c0c649eu: goto P_0c0c649e;
case 0x0c0c64a0u: goto P_0c0c64a0;
case 0x0c0c64a2u: goto P_0c0c64a2;
case 0x0c0c64a4u: goto P_0c0c64a4;
case 0x0c0c64a6u: goto P_0c0c64a6;
case 0x0c0c64a8u: goto P_0c0c64a8;
case 0x0c0c64aau: goto P_0c0c64aa;
case 0x0c0c64acu: goto P_0c0c64ac;
case 0x0c0c64aeu: goto P_0c0c64ae;
case 0x0c0c64b0u: goto P_0c0c64b0;
case 0x0c0c64b2u: goto P_0c0c64b2;
case 0x0c0c64b4u: goto P_0c0c64b4;
case 0x0c0c64b6u: goto P_0c0c64b6;
case 0x0c0c64e0u: goto P_0c0c64e0;
case 0x0c0c64e2u: goto P_0c0c64e2;
case 0x0c0c64e4u: goto P_0c0c64e4;
case 0x0c0c64e6u: goto P_0c0c64e6;
case 0x0c0c64e8u: goto P_0c0c64e8;
case 0x0c0c64eau: goto P_0c0c64ea;
case 0x0c0c64ecu: goto P_0c0c64ec;
case 0x0c0c64eeu: goto P_0c0c64ee;
case 0x0c0c64f0u: goto P_0c0c64f0;
case 0x0c0c64f2u: goto P_0c0c64f2;
case 0x0c0c64f4u: goto P_0c0c64f4;
case 0x0c0c64f6u: goto P_0c0c64f6;
case 0x0c0c64f8u: goto P_0c0c64f8;
case 0x0c0c64fau: goto P_0c0c64fa;
case 0x0c0c64fcu: goto P_0c0c64fc;
case 0x0c0c64feu: goto P_0c0c64fe;
case 0x0c0c6500u: goto P_0c0c6500;
case 0x0c0c6502u: goto P_0c0c6502;
case 0x0c0c6504u: goto P_0c0c6504;
case 0x0c0c6506u: goto P_0c0c6506;
case 0x0c0c6508u: goto P_0c0c6508;
case 0x0c0c650au: goto P_0c0c650a;
case 0x0c0c650cu: goto P_0c0c650c;
case 0x0c0c650eu: goto P_0c0c650e;
case 0x0c0c6510u: goto P_0c0c6510;
case 0x0c0c6512u: goto P_0c0c6512;
case 0x0c0c6514u: goto P_0c0c6514;
case 0x0c0c6516u: goto P_0c0c6516;
case 0x0c0c6518u: goto P_0c0c6518;
case 0x0c0c651au: goto P_0c0c651a;
case 0x0c0c651cu: goto P_0c0c651c;
case 0x0c0c651eu: goto P_0c0c651e;
case 0x0c0c6520u: goto P_0c0c6520;
case 0x0c0c6522u: goto P_0c0c6522;
case 0x0c0c6524u: goto P_0c0c6524;
case 0x0c0c6526u: goto P_0c0c6526;
case 0x0c0c6528u: goto P_0c0c6528;
case 0x0c0c652au: goto P_0c0c652a;
case 0x0c0c652cu: goto P_0c0c652c;
case 0x0c0c652eu: goto P_0c0c652e;
case 0x0c0c6530u: goto P_0c0c6530;
case 0x0c0c6532u: goto P_0c0c6532;
case 0x0c0c6534u: goto P_0c0c6534;
case 0x0c0c6536u: goto P_0c0c6536;
case 0x0c0c6538u: goto P_0c0c6538;
case 0x0c0c653au: goto P_0c0c653a;
case 0x0c0c653cu: goto P_0c0c653c;
case 0x0c0c653eu: goto P_0c0c653e;
case 0x0c0c6540u: goto P_0c0c6540;
case 0x0c0c6542u: goto P_0c0c6542;
case 0x0c0c6544u: goto P_0c0c6544;
case 0x0c0c6546u: goto P_0c0c6546;
case 0x0c0c6548u: goto P_0c0c6548;
case 0x0c0c654au: goto P_0c0c654a;
case 0x0c0c654cu: goto P_0c0c654c;
case 0x0c0c654eu: goto P_0c0c654e;
case 0x0c0c6550u: goto P_0c0c6550;
case 0x0c0c6552u: goto P_0c0c6552;
case 0x0c0c6554u: goto P_0c0c6554;
case 0x0c0c6556u: goto P_0c0c6556;
case 0x0c0c6558u: goto P_0c0c6558;
case 0x0c0c655au: goto P_0c0c655a;
case 0x0c0c655cu: goto P_0c0c655c;
case 0x0c0c655eu: goto P_0c0c655e;
case 0x0c0c6560u: goto P_0c0c6560;
case 0x0c0c6562u: goto P_0c0c6562;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b02c: /* original 4f22, guest PC 0x0c07b02c */
if(!s->budget--) { s->failed_pc=0x0c07b02cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b02e;
P_0c07b02e: /* original 03ed, guest PC 0x0c07b02e */
if(!s->budget--) { s->failed_pc=0x0c07b02eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07b030;
P_0c07b030: /* original db26, guest PC 0x0c07b030 */
if(!s->budget--) { s->failed_pc=0x0c07b030u; return 0; }
r[11]=read(ram,0x0c07b0ccu,4);
goto P_0c07b032;
P_0c07b032: /* original 4311, guest PC 0x0c07b032 */
if(!s->budget--) { s->failed_pc=0x0c07b032u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c07b034;
P_0c07b034: /* original 8f0f, guest PC 0x0c07b034 */
if(!s->budget--) { s->failed_pc=0x0c07b034u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(!cond) { goto P_0c07b056; }
goto P_0c07b038;
P_0c07b036: /* original 6c43, guest PC 0x0c07b036 */
if(!s->budget--) { s->failed_pc=0x0c07b036u; return 0; }
r[12]=r[4];
goto P_0c07b038;
P_0c07b038: /* original b2ba, guest PC 0x0c07b038 */
if(!s->budget--) { s->failed_pc=0x0c07b038u; return 0; }
target=0x0c07b5b0u; r[16]=0x0c07b03cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b03cu) { target=s->pc; goto dispatch; }
goto P_0c07b03c;
P_0c07b03a: /* original 04ed, guest PC 0x0c07b03a */
if(!s->budget--) { s->failed_pc=0x0c07b03au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07b03c;
P_0c07b03c: /* original 6d03, guest PC 0x0c07b03c */
if(!s->budget--) { s->failed_pc=0x0c07b03cu; return 0; }
r[13]=r[0];
goto P_0c07b03e;
P_0c07b03e: /* original b2d7, guest PC 0x0c07b03e */
if(!s->budget--) { s->failed_pc=0x0c07b03eu; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07b042u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b042u) { target=s->pc; goto dispatch; }
goto P_0c07b042;
P_0c07b040: /* original 6403, guest PC 0x0c07b040 */
if(!s->budget--) { s->failed_pc=0x0c07b040u; return 0; }
r[4]=r[0];
goto P_0c07b042;
P_0c07b042: /* original 64dd, guest PC 0x0c07b042 */
if(!s->budget--) { s->failed_pc=0x0c07b042u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b044;
P_0c07b044: /* original 6043, guest PC 0x0c07b044 */
if(!s->budget--) { s->failed_pc=0x0c07b044u; return 0; }
r[0]=r[4];
goto P_0c07b046;
P_0c07b046: /* original 882c, guest PC 0x0c07b046 */
if(!s->budget--) { s->failed_pc=0x0c07b046u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07b048;
P_0c07b048: /* original 8902, guest PC 0x0c07b048 */
if(!s->budget--) { s->failed_pc=0x0c07b048u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b050; }
goto P_0c07b04a;
P_0c07b04a: /* original 6043, guest PC 0x0c07b04a */
if(!s->budget--) { s->failed_pc=0x0c07b04au; return 0; }
r[0]=r[4];
goto P_0c07b04c;
P_0c07b04c: /* original 8834, guest PC 0x0c07b04c */
if(!s->budget--) { s->failed_pc=0x0c07b04cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07b04e;
P_0c07b04e: /* original 8b02, guest PC 0x0c07b04e */
if(!s->budget--) { s->failed_pc=0x0c07b04eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b056; }
goto P_0c07b050;
P_0c07b050: /* original 64d3, guest PC 0x0c07b050 */
if(!s->budget--) { s->failed_pc=0x0c07b050u; return 0; }
r[4]=r[13];
goto P_0c07b052;
P_0c07b052: /* original b2cd, guest PC 0x0c07b052 */
if(!s->budget--) { s->failed_pc=0x0c07b052u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07b056u;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b056u) { target=s->pc; goto dispatch; }
goto P_0c07b056;
P_0c07b054: /* original 7401, guest PC 0x0c07b054 */
if(!s->budget--) { s->failed_pc=0x0c07b054u; return 0; }
r[4]+=0x00000001u;
goto P_0c07b056;
P_0c07b056: /* original 9035, guest PC 0x0c07b056 */
if(!s->budget--) { s->failed_pc=0x0c07b056u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b0c4u,2);
goto P_0c07b058;
P_0c07b058: /* original e2ff, guest PC 0x0c07b058 */
if(!s->budget--) { s->failed_pc=0x0c07b058u; return 0; }
r[2]=0xffffffffu;
goto P_0c07b05a;
P_0c07b05a: /* original 0e25, guest PC 0x0c07b05a */
if(!s->budget--) { s->failed_pc=0x0c07b05au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07b05c;
P_0c07b05c: /* original d21b, guest PC 0x0c07b05c */
if(!s->budget--) { s->failed_pc=0x0c07b05cu; return 0; }
r[2]=read(ram,0x0c07b0ccu,4);
goto P_0c07b05e;
P_0c07b05e: /* original d31d, guest PC 0x0c07b05e */
if(!s->budget--) { s->failed_pc=0x0c07b05eu; return 0; }
r[3]=read(ram,0x0c07b0d4u,4);
goto P_0c07b060;
P_0c07b060: /* original 6122, guest PC 0x0c07b060 */
if(!s->budget--) { s->failed_pc=0x0c07b060u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07b062;
P_0c07b062: /* original 2138, guest PC 0x0c07b062 */
if(!s->budget--) { s->failed_pc=0x0c07b062u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07b064;
P_0c07b064: /* original 8b25, guest PC 0x0c07b064 */
if(!s->budget--) { s->failed_pc=0x0c07b064u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b0b2; }
goto P_0c07b066;
P_0c07b066: /* original d21c, guest PC 0x0c07b066 */
if(!s->budget--) { s->failed_pc=0x0c07b066u; return 0; }
r[2]=read(ram,0x0c07b0d8u,4);
goto P_0c07b068;
P_0c07b068: /* original 63cd, guest PC 0x0c07b068 */
if(!s->budget--) { s->failed_pc=0x0c07b068u; return 0; }
r[3]=r[12]&65535u;
goto P_0c07b06a;
P_0c07b06a: /* original 902b, guest PC 0x0c07b06a */
if(!s->budget--) { s->failed_pc=0x0c07b06au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b0c4u,2);
goto P_0c07b06c;
P_0c07b06c: /* original 3320, guest PC 0x0c07b06c */
if(!s->budget--) { s->failed_pc=0x0c07b06cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07b06e;
P_0c07b06e: /* original 8d20, guest PC 0x0c07b06e */
if(!s->budget--) { s->failed_pc=0x0c07b06eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[12],2);
if(cond) { goto P_0c07b0b2; }
goto P_0c07b072;
P_0c07b070: /* original 0ec5, guest PC 0x0c07b070 */
if(!s->budget--) { s->failed_pc=0x0c07b070u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c07b072;
P_0c07b072: /* original b29d, guest PC 0x0c07b072 */
if(!s->budget--) { s->failed_pc=0x0c07b072u; return 0; }
target=0x0c07b5b0u; r[16]=0x0c07b076u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b076u) { target=s->pc; goto dispatch; }
goto P_0c07b076;
P_0c07b074: /* original 64c3, guest PC 0x0c07b074 */
if(!s->budget--) { s->failed_pc=0x0c07b074u; return 0; }
r[4]=r[12];
goto P_0c07b076;
P_0c07b076: /* original 6e03, guest PC 0x0c07b076 */
if(!s->budget--) { s->failed_pc=0x0c07b076u; return 0; }
r[14]=r[0];
goto P_0c07b078;
P_0c07b078: /* original d318, guest PC 0x0c07b078 */
if(!s->budget--) { s->failed_pc=0x0c07b078u; return 0; }
r[3]=read(ram,0x0c07b0dcu,4);
goto P_0c07b07a;
P_0c07b07a: /* original 6ded, guest PC 0x0c07b07a */
if(!s->budget--) { s->failed_pc=0x0c07b07au; return 0; }
r[13]=r[14]&65535u;
goto P_0c07b07c;
P_0c07b07c: /* original 7ddb, guest PC 0x0c07b07c */
if(!s->budget--) { s->failed_pc=0x0c07b07cu; return 0; }
r[13]+=0xffffffdbu;
goto P_0c07b07e;
P_0c07b07e: /* original 3d3c, guest PC 0x0c07b07e */
if(!s->budget--) { s->failed_pc=0x0c07b07eu; return 0; }
r[13]+=r[3];
goto P_0c07b080;
P_0c07b080: /* original 62d0, guest PC 0x0c07b080 */
if(!s->budget--) { s->failed_pc=0x0c07b080u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[2]=tmp;
goto P_0c07b082;
P_0c07b082: /* original 2228, guest PC 0x0c07b082 */
if(!s->budget--) { s->failed_pc=0x0c07b082u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07b084;
P_0c07b084: /* original 8915, guest PC 0x0c07b084 */
if(!s->budget--) { s->failed_pc=0x0c07b084u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b0b2; }
goto P_0c07b086;
P_0c07b086: /* original 901e, guest PC 0x0c07b086 */
if(!s->budget--) { s->failed_pc=0x0c07b086u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b0c6u,2);
goto P_0c07b088;
P_0c07b088: /* original 63ed, guest PC 0x0c07b088 */
if(!s->budget--) { s->failed_pc=0x0c07b088u; return 0; }
r[3]=r[14]&65535u;
goto P_0c07b08a;
P_0c07b08a: /* original 2f06, guest PC 0x0c07b08a */
if(!s->budget--) { s->failed_pc=0x0c07b08au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b08c;
P_0c07b08c: /* original d214, guest PC 0x0c07b08c */
if(!s->budget--) { s->failed_pc=0x0c07b08cu; return 0; }
r[2]=read(ram,0x0c07b0e0u,4);
goto P_0c07b08e;
P_0c07b08e: /* original 2f26, guest PC 0x0c07b08e */
if(!s->budget--) { s->failed_pc=0x0c07b08eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b090;
P_0c07b090: /* original 2f36, guest PC 0x0c07b090 */
if(!s->budget--) { s->failed_pc=0x0c07b090u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b092;
P_0c07b092: /* original 9619, guest PC 0x0c07b092 */
if(!s->budget--) { s->failed_pc=0x0c07b092u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b0c8u,2);
goto P_0c07b094;
P_0c07b094: /* original d114, guest PC 0x0c07b094 */
if(!s->budget--) { s->failed_pc=0x0c07b094u; return 0; }
r[1]=read(ram,0x0c07b0e8u,4);
goto P_0c07b096;
P_0c07b096: /* original d315, guest PC 0x0c07b096 */
if(!s->budget--) { s->failed_pc=0x0c07b096u; return 0; }
r[3]=read(ram,0x0c07b0ecu,4);
goto P_0c07b098;
P_0c07b098: /* original 36bc, guest PC 0x0c07b098 */
if(!s->budget--) { s->failed_pc=0x0c07b098u; return 0; }
r[6]+=r[11];
goto P_0c07b09a;
P_0c07b09a: /* original 6512, guest PC 0x0c07b09a */
if(!s->budget--) { s->failed_pc=0x0c07b09au; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c07b09c;
P_0c07b09c: /* original 7610, guest PC 0x0c07b09c */
if(!s->budget--) { s->failed_pc=0x0c07b09cu; return 0; }
r[6]+=0x00000010u;
goto P_0c07b09e;
P_0c07b09e: /* original d711, guest PC 0x0c07b09e */
if(!s->budget--) { s->failed_pc=0x0c07b09eu; return 0; }
r[7]=read(ram,0x0c07b0e4u,4);
goto P_0c07b0a0;
P_0c07b0a0: /* original 430b, guest PC 0x0c07b0a0 */
if(!s->budget--) { s->failed_pc=0x0c07b0a0u; return 0; }
target=r[3];
r[16]=0x0c07b0a4u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b0a4u) { target=s->pc; goto dispatch; }
goto P_0c07b0a4;
P_0c07b0a2: /* original 64d0, guest PC 0x0c07b0a2 */
if(!s->budget--) { s->failed_pc=0x0c07b0a2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[4]=tmp;
goto P_0c07b0a4;
P_0c07b0a4: /* original d012, guest PC 0x0c07b0a4 */
if(!s->budget--) { s->failed_pc=0x0c07b0a4u; return 0; }
r[0]=read(ram,0x0c07b0f0u,4);
goto P_0c07b0a6;
P_0c07b0a6: /* original 6eed, guest PC 0x0c07b0a6 */
if(!s->budget--) { s->failed_pc=0x0c07b0a6u; return 0; }
r[14]=r[14]&65535u;
goto P_0c07b0a8;
P_0c07b0a8: /* original d20b, guest PC 0x0c07b0a8 */
if(!s->budget--) { s->failed_pc=0x0c07b0a8u; return 0; }
r[2]=read(ram,0x0c07b0d8u,4);
goto P_0c07b0aa;
P_0c07b0aa: /* original 7f0c, guest PC 0x0c07b0aa */
if(!s->budget--) { s->failed_pc=0x0c07b0aau; return 0; }
r[15]+=0x0000000cu;
goto P_0c07b0ac;
P_0c07b0ac: /* original 4e00, guest PC 0x0c07b0ac */
if(!s->budget--) { s->failed_pc=0x0c07b0acu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07b0ae;
P_0c07b0ae: /* original a003, guest PC 0x0c07b0ae */
if(!s->budget--) { s->failed_pc=0x0c07b0aeu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07b0b8;
P_0c07b0b0: /* original 0e25, guest PC 0x0c07b0b0 */
if(!s->budget--) { s->failed_pc=0x0c07b0b0u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07b0b2;
P_0c07b0b2: /* original 900a, guest PC 0x0c07b0b2 */
if(!s->budget--) { s->failed_pc=0x0c07b0b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b0cau,2);
goto P_0c07b0b4;
P_0c07b0b4: /* original e1ff, guest PC 0x0c07b0b4 */
if(!s->budget--) { s->failed_pc=0x0c07b0b4u; return 0; }
r[1]=0xffffffffu;
goto P_0c07b0b6;
P_0c07b0b6: /* original 0b16, guest PC 0x0c07b0b6 */
if(!s->budget--) { s->failed_pc=0x0c07b0b6u; return 0; }
write(ram,r[11]+r[0],r[1],4);
goto P_0c07b0b8;
P_0c07b0b8: /* original 4f26, guest PC 0x0c07b0b8 */
if(!s->budget--) { s->failed_pc=0x0c07b0b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b0ba;
P_0c07b0ba: /* original 6bf6, guest PC 0x0c07b0ba */
if(!s->budget--) { s->failed_pc=0x0c07b0bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b0bc;
P_0c07b0bc: /* original 6cf6, guest PC 0x0c07b0bc */
if(!s->budget--) { s->failed_pc=0x0c07b0bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b0be;
P_0c07b0be: /* original 6df6, guest PC 0x0c07b0be */
if(!s->budget--) { s->failed_pc=0x0c07b0beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b0c0;
P_0c07b0c0: /* original 000b, guest PC 0x0c07b0c0 */
if(!s->budget--) { s->failed_pc=0x0c07b0c0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b0c2: /* original 6ef6, guest PC 0x0c07b0c2 */
if(!s->budget--) { s->failed_pc=0x0c07b0c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07b0c4u,s,ram);
P_0c087534: /* original 8551, guest PC 0x0c087534 */
if(!s->budget--) { s->failed_pc=0x0c087534u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c087536;
P_0c087536: /* original 8145, guest PC 0x0c087536 */
if(!s->budget--) { s->failed_pc=0x0c087536u; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c087538;
P_0c087538: /* original 6050, guest PC 0x0c087538 */
if(!s->budget--) { s->failed_pc=0x0c087538u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c08753a;
P_0c08753a: /* original 8048, guest PC 0x0c08753a */
if(!s->budget--) { s->failed_pc=0x0c08753au; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c08753c;
P_0c08753c: /* original e000, guest PC 0x0c08753c */
if(!s->budget--) { s->failed_pc=0x0c08753cu; return 0; }
r[0]=0x00000000u;
goto P_0c08753e;
P_0c08753e: /* original 000b, guest PC 0x0c08753e */
if(!s->budget--) { s->failed_pc=0x0c08753eu; return 0; }
target=r[16];
write(ram,r[4]+9,r[0],1);
s->pc=target; return ram->oob==0;
P_0c087540: /* original 8049, guest PC 0x0c087540 */
if(!s->budget--) { s->failed_pc=0x0c087540u; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c087542;
P_0c087542: /* original 5041, guest PC 0x0c087542 */
if(!s->budget--) { s->failed_pc=0x0c087542u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c087544;
P_0c087544: /* original 88ff, guest PC 0x0c087544 */
if(!s->budget--) { s->failed_pc=0x0c087544u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087546;
P_0c087546: /* original 8d0a, guest PC 0x0c087546 */
if(!s->budget--) { s->failed_pc=0x0c087546u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c08755e; }
goto P_0c08754a;
P_0c087548: /* original 6503, guest PC 0x0c087548 */
if(!s->budget--) { s->failed_pc=0x0c087548u; return 0; }
r[5]=r[0];
goto P_0c08754a;
P_0c08754a: /* original 6252, guest PC 0x0c08754a */
if(!s->budget--) { s->failed_pc=0x0c08754au; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c08754c;
P_0c08754c: /* original 1421, guest PC 0x0c08754c */
if(!s->budget--) { s->failed_pc=0x0c08754cu; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c08754e;
P_0c08754e: /* original 6642, guest PC 0x0c08754e */
if(!s->budget--) { s->failed_pc=0x0c08754eu; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c087550;
P_0c087550: /* original 6063, guest PC 0x0c087550 */
if(!s->budget--) { s->failed_pc=0x0c087550u; return 0; }
r[0]=r[6];
goto P_0c087552;
P_0c087552: /* original 88ff, guest PC 0x0c087552 */
if(!s->budget--) { s->failed_pc=0x0c087552u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087554;
P_0c087554: /* original 2562, guest PC 0x0c087554 */
if(!s->budget--) { s->failed_pc=0x0c087554u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c087556;
P_0c087556: /* original 2452, guest PC 0x0c087556 */
if(!s->budget--) { s->failed_pc=0x0c087556u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c087558;
P_0c087558: /* original 8d01, guest PC 0x0c087558 */
if(!s->budget--) { s->failed_pc=0x0c087558u; return 0; }
cond=r[17]&1u;
write(ram,r[5]+4,r[4],4);
if(cond) { goto P_0c08755e; }
goto P_0c08755c;
P_0c08755a: /* original 1541, guest PC 0x0c08755a */
if(!s->budget--) { s->failed_pc=0x0c08755au; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c08755c;
P_0c08755c: /* original 1651, guest PC 0x0c08755c */
if(!s->budget--) { s->failed_pc=0x0c08755cu; return 0; }
write(ram,r[6]+4,r[5],4);
goto P_0c08755e;
P_0c08755e: /* original 000b, guest PC 0x0c08755e */
if(!s->budget--) { s->failed_pc=0x0c08755eu; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c087560: /* original 6053, guest PC 0x0c087560 */
if(!s->budget--) { s->failed_pc=0x0c087560u; return 0; }
r[0]=r[5];
goto P_0c087562;
P_0c087562: /* original 8448, guest PC 0x0c087562 */
if(!s->budget--) { s->failed_pc=0x0c087562u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c087564;
P_0c087564: /* original 6603, guest PC 0x0c087564 */
if(!s->budget--) { s->failed_pc=0x0c087564u; return 0; }
r[6]=r[0];
goto P_0c087566;
P_0c087566: /* original 606e, guest PC 0x0c087566 */
if(!s->budget--) { s->failed_pc=0x0c087566u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c087568;
P_0c087568: /* original 88ff, guest PC 0x0c087568 */
if(!s->budget--) { s->failed_pc=0x0c087568u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c08756a;
P_0c08756a: /* original 891f, guest PC 0x0c08756a */
if(!s->budget--) { s->failed_pc=0x0c08756au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0875ac; }
goto P_0c08756c;
P_0c08756c: /* original 76ff, guest PC 0x0c08756c */
if(!s->budget--) { s->failed_pc=0x0c08756cu; return 0; }
r[6]+=0xffffffffu;
goto P_0c08756e;
P_0c08756e: /* original 6063, guest PC 0x0c08756e */
if(!s->budget--) { s->failed_pc=0x0c08756eu; return 0; }
r[0]=r[6];
goto P_0c087570;
P_0c087570: /* original 666e, guest PC 0x0c087570 */
if(!s->budget--) { s->failed_pc=0x0c087570u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c087572;
P_0c087572: /* original 2668, guest PC 0x0c087572 */
if(!s->budget--) { s->failed_pc=0x0c087572u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c087574;
P_0c087574: /* original 8f1a, guest PC 0x0c087574 */
if(!s->budget--) { s->failed_pc=0x0c087574u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+8,r[0],1);
if(!cond) { goto P_0c0875ac; }
goto P_0c087578;
P_0c087576: /* original 8048, guest PC 0x0c087576 */
if(!s->budget--) { s->failed_pc=0x0c087576u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c087578;
P_0c087578: /* original 8449, guest PC 0x0c087578 */
if(!s->budget--) { s->failed_pc=0x0c087578u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c08757a;
P_0c08757a: /* original 6703, guest PC 0x0c08757a */
if(!s->budget--) { s->failed_pc=0x0c08757au; return 0; }
r[7]=r[0];
goto P_0c08757c;
P_0c08757c: /* original 4708, guest PC 0x0c08757c */
if(!s->budget--) { s->failed_pc=0x0c08757cu; return 0; }
r[7]<<=2;
goto P_0c08757e;
P_0c08757e: /* original 375c, guest PC 0x0c08757e */
if(!s->budget--) { s->failed_pc=0x0c08757eu; return 0; }
r[7]+=r[5];
goto P_0c087580;
P_0c087580: /* original 6603, guest PC 0x0c087580 */
if(!s->budget--) { s->failed_pc=0x0c087580u; return 0; }
r[6]=r[0];
goto P_0c087582;
P_0c087582: /* original 8471, guest PC 0x0c087582 */
if(!s->budget--) { s->failed_pc=0x0c087582u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c087584;
P_0c087584: /* original 6703, guest PC 0x0c087584 */
if(!s->budget--) { s->failed_pc=0x0c087584u; return 0; }
r[7]=r[0];
goto P_0c087586;
P_0c087586: /* original 617e, guest PC 0x0c087586 */
if(!s->budget--) { s->failed_pc=0x0c087586u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c087588;
P_0c087588: /* original 6013, guest PC 0x0c087588 */
if(!s->budget--) { s->failed_pc=0x0c087588u; return 0; }
r[0]=r[1];
goto P_0c08758a;
P_0c08758a: /* original 88ff, guest PC 0x0c08758a */
if(!s->budget--) { s->failed_pc=0x0c08758au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c08758c;
P_0c08758c: /* original 8f03, guest PC 0x0c08758c */
if(!s->budget--) { s->failed_pc=0x0c08758cu; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c087596; }
goto P_0c087590;
P_0c08758e: /* original 7601, guest PC 0x0c08758e */
if(!s->budget--) { s->failed_pc=0x0c08758eu; return 0; }
r[6]+=0x00000001u;
goto P_0c087590;
P_0c087590: /* original 6073, guest PC 0x0c087590 */
if(!s->budget--) { s->failed_pc=0x0c087590u; return 0; }
r[0]=r[7];
goto P_0c087592;
P_0c087592: /* original 000b, guest PC 0x0c087592 */
if(!s->budget--) { s->failed_pc=0x0c087592u; return 0; }
target=r[16];
write(ram,r[4]+8,r[0],1);
s->pc=target; return ram->oob==0;
P_0c087594: /* original 8048, guest PC 0x0c087594 */
if(!s->budget--) { s->failed_pc=0x0c087594u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c087596;
P_0c087596: /* original 2118, guest PC 0x0c087596 */
if(!s->budget--) { s->failed_pc=0x0c087596u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c087598;
P_0c087598: /* original 8900, guest PC 0x0c087598 */
if(!s->budget--) { s->failed_pc=0x0c087598u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08759c; }
goto P_0c08759a;
P_0c08759a: /* original e600, guest PC 0x0c08759a */
if(!s->budget--) { s->failed_pc=0x0c08759au; return 0; }
r[6]=0x00000000u;
goto P_0c08759c;
P_0c08759c: /* original 6063, guest PC 0x0c08759c */
if(!s->budget--) { s->failed_pc=0x0c08759cu; return 0; }
r[0]=r[6];
goto P_0c08759e;
P_0c08759e: /* original 4608, guest PC 0x0c08759e */
if(!s->budget--) { s->failed_pc=0x0c08759eu; return 0; }
r[6]<<=2;
goto P_0c0875a0;
P_0c0875a0: /* original 356c, guest PC 0x0c0875a0 */
if(!s->budget--) { s->failed_pc=0x0c0875a0u; return 0; }
r[5]+=r[6];
goto P_0c0875a2;
P_0c0875a2: /* original 8049, guest PC 0x0c0875a2 */
if(!s->budget--) { s->failed_pc=0x0c0875a2u; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c0875a4;
P_0c0875a4: /* original 6050, guest PC 0x0c0875a4 */
if(!s->budget--) { s->failed_pc=0x0c0875a4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0875a6;
P_0c0875a6: /* original 8048, guest PC 0x0c0875a6 */
if(!s->budget--) { s->failed_pc=0x0c0875a6u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0875a8;
P_0c0875a8: /* original 8551, guest PC 0x0c0875a8 */
if(!s->budget--) { s->failed_pc=0x0c0875a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c0875aa;
P_0c0875aa: /* original 8145, guest PC 0x0c0875aa */
if(!s->budget--) { s->failed_pc=0x0c0875aau; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c0875ac;
P_0c0875ac: /* original 000b, guest PC 0x0c0875ac */
if(!s->budget--) { s->failed_pc=0x0c0875acu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0875ae: /* original 0009, guest PC 0x0c0875ae */
if(!s->budget--) { s->failed_pc=0x0c0875aeu; return 0; }
return vf3_matrix_family(0x0c0875b0u,s,ram);
P_0c0875ce: /* original 5341, guest PC 0x0c0875ce */
if(!s->budget--) { s->failed_pc=0x0c0875ceu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0875d0;
P_0c0875d0: /* original 7ff8, guest PC 0x0c0875d0 */
if(!s->budget--) { s->failed_pc=0x0c0875d0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0875d2;
P_0c0875d2: /* original 2f32, guest PC 0x0c0875d2 */
if(!s->budget--) { s->failed_pc=0x0c0875d2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0875d4;
P_0c0875d4: /* original 6752, guest PC 0x0c0875d4 */
if(!s->budget--) { s->failed_pc=0x0c0875d4u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c0875d6;
P_0c0875d6: /* original 5651, guest PC 0x0c0875d6 */
if(!s->budget--) { s->failed_pc=0x0c0875d6u; return 0; }
r[6]=read(ram,r[5]+4,4);
goto P_0c0875d8;
P_0c0875d8: /* original 6073, guest PC 0x0c0875d8 */
if(!s->budget--) { s->failed_pc=0x0c0875d8u; return 0; }
r[0]=r[7];
goto P_0c0875da;
P_0c0875da: /* original 88ff, guest PC 0x0c0875da */
if(!s->budget--) { s->failed_pc=0x0c0875dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0875dc;
P_0c0875dc: /* original 1f71, guest PC 0x0c0875dc */
if(!s->budget--) { s->failed_pc=0x0c0875dcu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0875de;
P_0c0875de: /* original 8900, guest PC 0x0c0875de */
if(!s->budget--) { s->failed_pc=0x0c0875deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0875e2; }
goto P_0c0875e0;
P_0c0875e0: /* original 1761, guest PC 0x0c0875e0 */
if(!s->budget--) { s->failed_pc=0x0c0875e0u; return 0; }
write(ram,r[7]+4,r[6],4);
goto P_0c0875e2;
P_0c0875e2: /* original 6063, guest PC 0x0c0875e2 */
if(!s->budget--) { s->failed_pc=0x0c0875e2u; return 0; }
r[0]=r[6];
goto P_0c0875e4;
P_0c0875e4: /* original 2672, guest PC 0x0c0875e4 */
if(!s->budget--) { s->failed_pc=0x0c0875e4u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c0875e6;
P_0c0875e6: /* original 62f2, guest PC 0x0c0875e6 */
if(!s->budget--) { s->failed_pc=0x0c0875e6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0875e8;
P_0c0875e8: /* original 2522, guest PC 0x0c0875e8 */
if(!s->budget--) { s->failed_pc=0x0c0875e8u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0875ea;
P_0c0875ea: /* original 1451, guest PC 0x0c0875ea */
if(!s->budget--) { s->failed_pc=0x0c0875eau; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c0875ec;
P_0c0875ec: /* original 000b, guest PC 0x0c0875ec */
if(!s->budget--) { s->failed_pc=0x0c0875ecu; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c0875ee: /* original 7f08, guest PC 0x0c0875ee */
if(!s->budget--) { s->failed_pc=0x0c0875eeu; return 0; }
r[15]+=0x00000008u;
return vf3_matrix_family(0x0c0875f0u,s,ram);
P_0c0881cc: /* original 9588, guest PC 0x0c0881cc */
if(!s->budget--) { s->failed_pc=0x0c0881ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0882e0u,2);
goto P_0c0881ce;
P_0c0881ce: /* original e600, guest PC 0x0c0881ce */
if(!s->budget--) { s->failed_pc=0x0c0881ceu; return 0; }
r[6]=0x00000000u;
goto P_0c0881d0;
P_0c0881d0: /* original 4510, guest PC 0x0c0881d0 */
if(!s->budget--) { s->failed_pc=0x0c0881d0u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c0881d2;
P_0c0881d2: /* original 2462, guest PC 0x0c0881d2 */
if(!s->budget--) { s->failed_pc=0x0c0881d2u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0881d4;
P_0c0881d4: /* original 8ffc, guest PC 0x0c0881d4 */
if(!s->budget--) { s->failed_pc=0x0c0881d4u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c0881d0; }
goto P_0c0881d8;
P_0c0881d6: /* original 7404, guest PC 0x0c0881d6 */
if(!s->budget--) { s->failed_pc=0x0c0881d6u; return 0; }
r[4]+=0x00000004u;
goto P_0c0881d8;
P_0c0881d8: /* original 000b, guest PC 0x0c0881d8 */
if(!s->budget--) { s->failed_pc=0x0c0881d8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0881da: /* original 0009, guest PC 0x0c0881da */
if(!s->budget--) { s->failed_pc=0x0c0881dau; return 0; }
return vf3_matrix_family(0x0c0881dcu,s,ram);
P_0c0881fa: /* original 2fe6, guest PC 0x0c0881fa */
if(!s->budget--) { s->failed_pc=0x0c0881fau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0881fc;
P_0c0881fc: /* original c73b, guest PC 0x0c0881fc */
if(!s->budget--) { s->failed_pc=0x0c0881fcu; return 0; }
r[0]=0x0c0882ecu;
goto P_0c0881fe;
P_0c0881fe: /* original 2fd6, guest PC 0x0c0881fe */
if(!s->budget--) { s->failed_pc=0x0c0881feu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088200;
P_0c088200: /* original 6e53, guest PC 0x0c088200 */
if(!s->budget--) { s->failed_pc=0x0c088200u; return 0; }
r[14]=r[5];
goto P_0c088202;
P_0c088202: /* original 2fc6, guest PC 0x0c088202 */
if(!s->budget--) { s->failed_pc=0x0c088202u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088204;
P_0c088204: /* original 2fb6, guest PC 0x0c088204 */
if(!s->budget--) { s->failed_pc=0x0c088204u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088206;
P_0c088206: /* original 2fa6, guest PC 0x0c088206 */
if(!s->budget--) { s->failed_pc=0x0c088206u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088208;
P_0c088208: /* original 6a43, guest PC 0x0c088208 */
if(!s->budget--) { s->failed_pc=0x0c088208u; return 0; }
r[10]=r[4];
goto P_0c08820a;
P_0c08820a: /* original 2f96, guest PC 0x0c08820a */
if(!s->budget--) { s->failed_pc=0x0c08820au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08820c;
P_0c08820c: /* original e902, guest PC 0x0c08820c */
if(!s->budget--) { s->failed_pc=0x0c08820cu; return 0; }
r[9]=0x00000002u;
goto P_0c08820e;
P_0c08820e: /* original 2f86, guest PC 0x0c08820e */
if(!s->budget--) { s->failed_pc=0x0c08820eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088210;
P_0c088210: /* original e80f, guest PC 0x0c088210 */
if(!s->budget--) { s->failed_pc=0x0c088210u; return 0; }
r[8]=0x0000000fu;
goto P_0c088212;
P_0c088212: /* original fffb, guest PC 0x0c088212 */
if(!s->budget--) { s->failed_pc=0x0c088212u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088214;
P_0c088214: /* original ffeb, guest PC 0x0c088214 */
if(!s->budget--) { s->failed_pc=0x0c088214u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c088216;
P_0c088216: /* original ffdb, guest PC 0x0c088216 */
if(!s->budget--) { s->failed_pc=0x0c088216u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c088218;
P_0c088218: /* original ffcb, guest PC 0x0c088218 */
if(!s->budget--) { s->failed_pc=0x0c088218u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08821a;
P_0c08821a: /* original fd08, guest PC 0x0c08821a */
if(!s->budget--) { s->failed_pc=0x0c08821au; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c08821c;
P_0c08821c: /* original c734, guest PC 0x0c08821c */
if(!s->budget--) { s->failed_pc=0x0c08821cu; return 0; }
r[0]=0x0c0882f0u;
goto P_0c08821e;
P_0c08821e: /* original f308, guest PC 0x0c08821e */
if(!s->budget--) { s->failed_pc=0x0c08821eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c088220;
P_0c088220: /* original e024, guest PC 0x0c088220 */
if(!s->budget--) { s->failed_pc=0x0c088220u; return 0; }
r[0]=0x00000024u;
goto P_0c088222;
P_0c088222: /* original 4f22, guest PC 0x0c088222 */
if(!s->budget--) { s->failed_pc=0x0c088222u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088224;
P_0c088224: /* original fa37, guest PC 0x0c088224 */
if(!s->budget--) { s->failed_pc=0x0c088224u; return 0; }
vf3_matrix_store(s,ram,3,r[10]+r[0]);
goto P_0c088226;
P_0c088226: /* original c733, guest PC 0x0c088226 */
if(!s->budget--) { s->failed_pc=0x0c088226u; return 0; }
r[0]=0x0c0882f4u;
goto P_0c088228;
P_0c088228: /* original 5baa, guest PC 0x0c088228 */
if(!s->budget--) { s->failed_pc=0x0c088228u; return 0; }
r[11]=read(ram,r[10]+40,4);
goto P_0c08822a;
P_0c08822a: /* original fc08, guest PC 0x0c08822a */
if(!s->budget--) { s->failed_pc=0x0c08822au; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c08822c;
P_0c08822c: /* original a02a, guest PC 0x0c08822c */
if(!s->budget--) { s->failed_pc=0x0c08822cu; return 0; }
r[12]=0x0000003fu;
goto P_0c088284;
P_0c08822e: /* original ec3f, guest PC 0x0c08822e */
if(!s->budget--) { s->failed_pc=0x0c08822eu; return 0; }
r[12]=0x0000003fu;
goto P_0c088230;
P_0c088230: /* original bfd4, guest PC 0x0c088230 */
if(!s->budget--) { s->failed_pc=0x0c088230u; return 0; }
target=0x0c0881dcu; r[16]=0x0c088234u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088234u) { target=s->pc; goto dispatch; }
goto P_0c088234;
P_0c088232: /* original 64a3, guest PC 0x0c088232 */
if(!s->budget--) { s->failed_pc=0x0c088232u; return 0; }
r[4]=r[10];
goto P_0c088234;
P_0c088234: /* original 6403, guest PC 0x0c088234 */
if(!s->budget--) { s->failed_pc=0x0c088234u; return 0; }
r[4]=r[0];
goto P_0c088236;
P_0c088236: /* original 24c9, guest PC 0x0c088236 */
if(!s->budget--) { s->failed_pc=0x0c088236u; return 0; }
r[4]&=r[12];
goto P_0c088238;
P_0c088238: /* original 74e1, guest PC 0x0c088238 */
if(!s->budget--) { s->failed_pc=0x0c088238u; return 0; }
r[4]+=0xffffffe1u;
goto P_0c08823a;
P_0c08823a: /* original 6d03, guest PC 0x0c08823a */
if(!s->budget--) { s->failed_pc=0x0c08823au; return 0; }
r[13]=r[0];
goto P_0c08823c;
P_0c08823c: /* original 445a, guest PC 0x0c08823c */
if(!s->budget--) { s->failed_pc=0x0c08823cu; return 0; }
r[53]=r[4];
goto P_0c08823e;
P_0c08823e: /* original e3fa, guest PC 0x0c08823e */
if(!s->budget--) { s->failed_pc=0x0c08823eu; return 0; }
r[3]=0xfffffffau;
goto P_0c088240;
P_0c088240: /* original 6403, guest PC 0x0c088240 */
if(!s->budget--) { s->failed_pc=0x0c088240u; return 0; }
r[4]=r[0];
goto P_0c088242;
P_0c088242: /* original 443c, guest PC 0x0c088242 */
if(!s->budget--) { s->failed_pc=0x0c088242u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c088244;
P_0c088244: /* original 24c9, guest PC 0x0c088244 */
if(!s->budget--) { s->failed_pc=0x0c088244u; return 0; }
r[4]&=r[12];
goto P_0c088246;
P_0c088246: /* original d32d, guest PC 0x0c088246 */
if(!s->budget--) { s->failed_pc=0x0c088246u; return 0; }
r[3]=read(ram,0x0c0882fcu,4);
goto P_0c088248;
P_0c088248: /* original f32d, guest PC 0x0c088248 */
if(!s->budget--) { s->failed_pc=0x0c088248u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08824a;
P_0c08824a: /* original 74e1, guest PC 0x0c08824a */
if(!s->budget--) { s->failed_pc=0x0c08824au; return 0; }
r[4]+=0xffffffe1u;
goto P_0c08824c;
P_0c08824c: /* original 445a, guest PC 0x0c08824c */
if(!s->budget--) { s->failed_pc=0x0c08824cu; return 0; }
r[53]=r[4];
goto P_0c08824e;
P_0c08824e: /* original c72a, guest PC 0x0c08824e */
if(!s->budget--) { s->failed_pc=0x0c08824eu; return 0; }
r[0]=0x0c0882f8u;
goto P_0c088250;
P_0c088250: /* original fe3c, guest PC 0x0c088250 */
if(!s->budget--) { s->failed_pc=0x0c088250u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c088252;
P_0c088252: /* original f32d, guest PC 0x0c088252 */
if(!s->budget--) { s->failed_pc=0x0c088252u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c088254;
P_0c088254: /* original fed2, guest PC 0x0c088254 */
if(!s->budget--) { s->failed_pc=0x0c088254u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[13],r[18],'*');
goto P_0c088256;
P_0c088256: /* original ff3c, guest PC 0x0c088256 */
if(!s->budget--) { s->failed_pc=0x0c088256u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c088258;
P_0c088258: /* original ffd2, guest PC 0x0c088258 */
if(!s->budget--) { s->failed_pc=0x0c088258u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[13],r[18],'*');
goto P_0c08825a;
P_0c08825a: /* original f308, guest PC 0x0c08825a */
if(!s->budget--) { s->failed_pc=0x0c08825au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08825c;
P_0c08825c: /* original fec2, guest PC 0x0c08825c */
if(!s->budget--) { s->failed_pc=0x0c08825cu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[12],r[18],'*');
goto P_0c08825e;
P_0c08825e: /* original ff31, guest PC 0x0c08825e */
if(!s->budget--) { s->failed_pc=0x0c08825eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c088260;
P_0c088260: /* original f5fc, guest PC 0x0c088260 */
if(!s->budget--) { s->failed_pc=0x0c088260u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c088262;
P_0c088262: /* original 430b, guest PC 0x0c088262 */
if(!s->budget--) { s->failed_pc=0x0c088262u; return 0; }
target=r[3];
r[16]=0x0c088266u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088266u) { target=s->pc; goto dispatch; }
goto P_0c088266;
P_0c088264: /* original f4ec, guest PC 0x0c088264 */
if(!s->budget--) { s->failed_pc=0x0c088264u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088266;
P_0c088266: /* original e004, guest PC 0x0c088266 */
if(!s->budget--) { s->failed_pc=0x0c088266u; return 0; }
r[0]=0x00000004u;
goto P_0c088268;
P_0c088268: /* original f40c, guest PC 0x0c088268 */
if(!s->budget--) { s->failed_pc=0x0c088268u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08826a;
P_0c08826a: /* original 64d3, guest PC 0x0c08826a */
if(!s->budget--) { s->failed_pc=0x0c08826au; return 0; }
r[4]=r[13];
goto P_0c08826c;
P_0c08826c: /* original 2489, guest PC 0x0c08826c */
if(!s->budget--) { s->failed_pc=0x0c08826cu; return 0; }
r[4]&=r[8];
goto P_0c08826e;
P_0c08826e: /* original feea, guest PC 0x0c08826e */
if(!s->budget--) { s->failed_pc=0x0c08826eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]);
goto P_0c088270;
P_0c088270: /* original 7bff, guest PC 0x0c088270 */
if(!s->budget--) { s->failed_pc=0x0c088270u; return 0; }
r[11]+=0xffffffffu;
goto P_0c088272;
P_0c088272: /* original fe47, guest PC 0x0c088272 */
if(!s->budget--) { s->failed_pc=0x0c088272u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c088274;
P_0c088274: /* original e008, guest PC 0x0c088274 */
if(!s->budget--) { s->failed_pc=0x0c088274u; return 0; }
r[0]=0x00000008u;
goto P_0c088276;
P_0c088276: /* original ff4d, guest PC 0x0c088276 */
if(!s->budget--) { s->failed_pc=0x0c088276u; return 0; }
fr[15]^=0x80000000u;
goto P_0c088278;
P_0c088278: /* original fef7, guest PC 0x0c088278 */
if(!s->budget--) { s->failed_pc=0x0c088278u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08827a;
P_0c08827a: /* original e020, guest PC 0x0c08827a */
if(!s->budget--) { s->failed_pc=0x0c08827au; return 0; }
r[0]=0x00000020u;
goto P_0c08827c;
P_0c08827c: /* original 0e44, guest PC 0x0c08827c */
if(!s->budget--) { s->failed_pc=0x0c08827cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08827e;
P_0c08827e: /* original e023, guest PC 0x0c08827e */
if(!s->budget--) { s->failed_pc=0x0c08827eu; return 0; }
r[0]=0x00000023u;
goto P_0c088280;
P_0c088280: /* original 0e94, guest PC 0x0c088280 */
if(!s->budget--) { s->failed_pc=0x0c088280u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c088282;
P_0c088282: /* original 7e24, guest PC 0x0c088282 */
if(!s->budget--) { s->failed_pc=0x0c088282u; return 0; }
r[14]+=0x00000024u;
goto P_0c088284;
P_0c088284: /* original 2bb8, guest PC 0x0c088284 */
if(!s->budget--) { s->failed_pc=0x0c088284u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c088286;
P_0c088286: /* original 8bd3, guest PC 0x0c088286 */
if(!s->budget--) { s->failed_pc=0x0c088286u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088230; }
goto P_0c088288;
P_0c088288: /* original 4f26, guest PC 0x0c088288 */
if(!s->budget--) { s->failed_pc=0x0c088288u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08828a;
P_0c08828a: /* original fcf9, guest PC 0x0c08828a */
if(!s->budget--) { s->failed_pc=0x0c08828au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08828c;
P_0c08828c: /* original fdf9, guest PC 0x0c08828c */
if(!s->budget--) { s->failed_pc=0x0c08828cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08828e;
P_0c08828e: /* original fef9, guest PC 0x0c08828e */
if(!s->budget--) { s->failed_pc=0x0c08828eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088290;
P_0c088290: /* original fff9, guest PC 0x0c088290 */
if(!s->budget--) { s->failed_pc=0x0c088290u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088292;
P_0c088292: /* original 68f6, guest PC 0x0c088292 */
if(!s->budget--) { s->failed_pc=0x0c088292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088294;
P_0c088294: /* original 69f6, guest PC 0x0c088294 */
if(!s->budget--) { s->failed_pc=0x0c088294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c088296;
P_0c088296: /* original 6af6, guest PC 0x0c088296 */
if(!s->budget--) { s->failed_pc=0x0c088296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088298;
P_0c088298: /* original 6bf6, guest PC 0x0c088298 */
if(!s->budget--) { s->failed_pc=0x0c088298u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08829a;
P_0c08829a: /* original 6cf6, guest PC 0x0c08829a */
if(!s->budget--) { s->failed_pc=0x0c08829au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08829c;
P_0c08829c: /* original 6df6, guest PC 0x0c08829c */
if(!s->budget--) { s->failed_pc=0x0c08829cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08829e;
P_0c08829e: /* original 000b, guest PC 0x0c08829e */
if(!s->budget--) { s->failed_pc=0x0c08829eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0882a0: /* original 6ef6, guest PC 0x0c0882a0 */
if(!s->budget--) { s->failed_pc=0x0c0882a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0882a2u,s,ram);
P_0c0887ec: /* original 4f22, guest PC 0x0c0887ec */
if(!s->budget--) { s->failed_pc=0x0c0887ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0887ee;
P_0c0887ee: /* original 938f, guest PC 0x0c0887ee */
if(!s->budget--) { s->failed_pc=0x0c0887eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088910u,2);
goto P_0c0887f0;
P_0c0887f0: /* original 33ec, guest PC 0x0c0887f0 */
if(!s->budget--) { s->failed_pc=0x0c0887f0u; return 0; }
r[3]+=r[14];
goto P_0c0887f2;
P_0c0887f2: /* original 7ffc, guest PC 0x0c0887f2 */
if(!s->budget--) { s->failed_pc=0x0c0887f2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0887f4;
P_0c0887f4: /* original 2f32, guest PC 0x0c0887f4 */
if(!s->budget--) { s->failed_pc=0x0c0887f4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0887f6;
P_0c0887f6: /* original bce9, guest PC 0x0c0887f6 */
if(!s->budget--) { s->failed_pc=0x0c0887f6u; return 0; }
target=0x0c0881ccu; r[16]=0x0c0887fau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0887fau) { target=s->pc; goto dispatch; }
goto P_0c0887fa;
P_0c0887f8: /* original 64e3, guest PC 0x0c0887f8 */
if(!s->budget--) { s->failed_pc=0x0c0887f8u; return 0; }
r[4]=r[14];
goto P_0c0887fa;
P_0c0887fa: /* original e01e, guest PC 0x0c0887fa */
if(!s->budget--) { s->failed_pc=0x0c0887fau; return 0; }
r[0]=0x0000001eu;
goto P_0c0887fc;
P_0c0887fc: /* original e301, guest PC 0x0c0887fc */
if(!s->budget--) { s->failed_pc=0x0c0887fcu; return 0; }
r[3]=0x00000001u;
goto P_0c0887fe;
P_0c0887fe: /* original 1e31, guest PC 0x0c0887fe */
if(!s->budget--) { s->failed_pc=0x0c0887feu; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c088800;
P_0c088800: /* original 80e1, guest PC 0x0c088800 */
if(!s->budget--) { s->failed_pc=0x0c088800u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c088802;
P_0c088802: /* original e060, guest PC 0x0c088802 */
if(!s->budget--) { s->failed_pc=0x0c088802u; return 0; }
r[0]=0x00000060u;
goto P_0c088804;
P_0c088804: /* original d544, guest PC 0x0c088804 */
if(!s->budget--) { s->failed_pc=0x0c088804u; return 0; }
r[5]=read(ram,0x0c088918u,4);
goto P_0c088806;
P_0c088806: /* original 9784, guest PC 0x0c088806 */
if(!s->budget--) { s->failed_pc=0x0c088806u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088912u,2);
goto P_0c088808;
P_0c088808: /* original 5454, guest PC 0x0c088808 */
if(!s->budget--) { s->failed_pc=0x0c088808u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c08880a;
P_0c08880a: /* original 5655, guest PC 0x0c08880a */
if(!s->budget--) { s->failed_pc=0x0c08880au; return 0; }
r[6]=read(ram,r[5]+20,4);
goto P_0c08880c;
P_0c08880c: /* original 054c, guest PC 0x0c08880c */
if(!s->budget--) { s->failed_pc=0x0c08880cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08880e;
P_0c08880e: /* original 066c, guest PC 0x0c08880e */
if(!s->budget--) { s->failed_pc=0x0c08880eu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c088810;
P_0c088810: /* original 655c, guest PC 0x0c088810 */
if(!s->budget--) { s->failed_pc=0x0c088810u; return 0; }
r[5]=r[5]&255u;
goto P_0c088812;
P_0c088812: /* original d442, guest PC 0x0c088812 */
if(!s->budget--) { s->failed_pc=0x0c088812u; return 0; }
r[4]=read(ram,0x0c08891cu,4);
goto P_0c088814;
P_0c088814: /* original 6053, guest PC 0x0c088814 */
if(!s->budget--) { s->failed_pc=0x0c088814u; return 0; }
r[0]=r[5];
goto P_0c088816;
P_0c088816: /* original 4000, guest PC 0x0c088816 */
if(!s->budget--) { s->failed_pc=0x0c088816u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c088818;
P_0c088818: /* original 054d, guest PC 0x0c088818 */
if(!s->budget--) { s->failed_pc=0x0c088818u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08881a;
P_0c08881a: /* original 666c, guest PC 0x0c08881a */
if(!s->budget--) { s->failed_pc=0x0c08881au; return 0; }
r[6]=r[6]&255u;
goto P_0c08881c;
P_0c08881c: /* original 6063, guest PC 0x0c08881c */
if(!s->budget--) { s->failed_pc=0x0c08881cu; return 0; }
r[0]=r[6];
goto P_0c08881e;
P_0c08881e: /* original 4000, guest PC 0x0c08881e */
if(!s->budget--) { s->failed_pc=0x0c08881eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c088820;
P_0c088820: /* original 3758, guest PC 0x0c088820 */
if(!s->budget--) { s->failed_pc=0x0c088820u; return 0; }
r[7]-=r[5];
goto P_0c088822;
P_0c088822: /* original 034d, guest PC 0x0c088822 */
if(!s->budget--) { s->failed_pc=0x0c088822u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c088824;
P_0c088824: /* original 6273, guest PC 0x0c088824 */
if(!s->budget--) { s->failed_pc=0x0c088824u; return 0; }
r[2]=r[7];
goto P_0c088826;
P_0c088826: /* original 3238, guest PC 0x0c088826 */
if(!s->budget--) { s->failed_pc=0x0c088826u; return 0; }
r[2]-=r[3];
goto P_0c088828;
P_0c088828: /* original 6423, guest PC 0x0c088828 */
if(!s->budget--) { s->failed_pc=0x0c088828u; return 0; }
r[4]=r[2];
goto P_0c08882a;
P_0c08882a: /* original 4411, guest PC 0x0c08882a */
if(!s->budget--) { s->failed_pc=0x0c08882au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c08882c;
P_0c08882c: /* original 8900, guest PC 0x0c08882c */
if(!s->budget--) { s->failed_pc=0x0c08882cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088830; }
goto P_0c08882e;
P_0c08882e: /* original e400, guest PC 0x0c08882e */
if(!s->budget--) { s->failed_pc=0x0c08882eu; return 0; }
r[4]=0x00000000u;
goto P_0c088830;
P_0c088830: /* original 1e4a, guest PC 0x0c088830 */
if(!s->budget--) { s->failed_pc=0x0c088830u; return 0; }
write(ram,r[14]+40,r[4],4);
goto P_0c088832;
P_0c088832: /* original 64e3, guest PC 0x0c088832 */
if(!s->budget--) { s->failed_pc=0x0c088832u; return 0; }
r[4]=r[14];
goto P_0c088834;
P_0c088834: /* original 65f2, guest PC 0x0c088834 */
if(!s->budget--) { s->failed_pc=0x0c088834u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c088836;
P_0c088836: /* original 7f04, guest PC 0x0c088836 */
if(!s->budget--) { s->failed_pc=0x0c088836u; return 0; }
r[15]+=0x00000004u;
goto P_0c088838;
P_0c088838: /* original 4f26, guest PC 0x0c088838 */
if(!s->budget--) { s->failed_pc=0x0c088838u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08883a;
P_0c08883a: /* original acde, guest PC 0x0c08883a */
if(!s->budget--) { s->failed_pc=0x0c08883au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0881fa;
P_0c08883c: /* original 6ef6, guest PC 0x0c08883c */
if(!s->budget--) { s->failed_pc=0x0c08883cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08883eu,s,ram);
P_0c088ef0: /* original 2fe6, guest PC 0x0c088ef0 */
if(!s->budget--) { s->failed_pc=0x0c088ef0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088ef2;
P_0c088ef2: /* original 2fd6, guest PC 0x0c088ef2 */
if(!s->budget--) { s->failed_pc=0x0c088ef2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088ef4;
P_0c088ef4: /* original 6d43, guest PC 0x0c088ef4 */
if(!s->budget--) { s->failed_pc=0x0c088ef4u; return 0; }
r[13]=r[4];
goto P_0c088ef6;
P_0c088ef6: /* original fffb, guest PC 0x0c088ef6 */
if(!s->budget--) { s->failed_pc=0x0c088ef6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088ef8;
P_0c088ef8: /* original 4f22, guest PC 0x0c088ef8 */
if(!s->budget--) { s->failed_pc=0x0c088ef8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088efa;
P_0c088efa: /* original 60d2, guest PC 0x0c088efa */
if(!s->budget--) { s->failed_pc=0x0c088efau; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c088efc;
P_0c088efc: /* original 88ff, guest PC 0x0c088efc */
if(!s->budget--) { s->failed_pc=0x0c088efcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c088efe;
P_0c088efe: /* original 7ffc, guest PC 0x0c088efe */
if(!s->budget--) { s->failed_pc=0x0c088efeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c088f00;
P_0c088f00: /* original 8d60, guest PC 0x0c088f00 */
if(!s->budget--) { s->failed_pc=0x0c088f00u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c088fc4; }
goto P_0c088f04;
P_0c088f02: /* original 6403, guest PC 0x0c088f02 */
if(!s->budget--) { s->failed_pc=0x0c088f02u; return 0; }
r[4]=r[0];
goto P_0c088f04;
P_0c088f04: /* original c732, guest PC 0x0c088f04 */
if(!s->budget--) { s->failed_pc=0x0c088f04u; return 0; }
r[0]=0x0c088fd0u;
goto P_0c088f06;
P_0c088f06: /* original 6e43, guest PC 0x0c088f06 */
if(!s->budget--) { s->failed_pc=0x0c088f06u; return 0; }
r[14]=r[4];
goto P_0c088f08;
P_0c088f08: /* original ff08, guest PC 0x0c088f08 */
if(!s->budget--) { s->failed_pc=0x0c088f08u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c088f0a;
P_0c088f0a: /* original c732, guest PC 0x0c088f0a */
if(!s->budget--) { s->failed_pc=0x0c088f0au; return 0; }
r[0]=0x0c088fd4u;
goto P_0c088f0c;
P_0c088f0c: /* original f308, guest PC 0x0c088f0c */
if(!s->budget--) { s->failed_pc=0x0c088f0cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c088f0e;
P_0c088f0e: /* original ff3a, guest PC 0x0c088f0e */
if(!s->budget--) { s->failed_pc=0x0c088f0eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c088f10;
P_0c088f10: /* original e024, guest PC 0x0c088f10 */
if(!s->budget--) { s->failed_pc=0x0c088f10u; return 0; }
r[0]=0x00000024u;
goto P_0c088f12;
P_0c088f12: /* original 04ed, guest PC 0x0c088f12 */
if(!s->budget--) { s->failed_pc=0x0c088f12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c088f14;
P_0c088f14: /* original 74ff, guest PC 0x0c088f14 */
if(!s->budget--) { s->failed_pc=0x0c088f14u; return 0; }
r[4]+=0xffffffffu;
goto P_0c088f16;
P_0c088f16: /* original 4415, guest PC 0x0c088f16 */
if(!s->budget--) { s->failed_pc=0x0c088f16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c088f18;
P_0c088f18: /* original 8905, guest PC 0x0c088f18 */
if(!s->budget--) { s->failed_pc=0x0c088f18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088f26; }
goto P_0c088f1a;
P_0c088f1a: /* original d22f, guest PC 0x0c088f1a */
if(!s->budget--) { s->failed_pc=0x0c088f1au; return 0; }
r[2]=read(ram,0x0c088fd8u,4);
goto P_0c088f1c;
P_0c088f1c: /* original 65e3, guest PC 0x0c088f1c */
if(!s->budget--) { s->failed_pc=0x0c088f1cu; return 0; }
r[5]=r[14];
goto P_0c088f1e;
P_0c088f1e: /* original 420b, guest PC 0x0c088f1e */
if(!s->budget--) { s->failed_pc=0x0c088f1eu; return 0; }
target=r[2];
r[16]=0x0c088f22u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088f22u) { target=s->pc; goto dispatch; }
goto P_0c088f22;
P_0c088f20: /* original 64d3, guest PC 0x0c088f20 */
if(!s->budget--) { s->failed_pc=0x0c088f20u; return 0; }
r[4]=r[13];
goto P_0c088f22;
P_0c088f22: /* original a049, guest PC 0x0c088f22 */
if(!s->budget--) { s->failed_pc=0x0c088f22u; return 0; }
r[14]=r[0];
goto P_0c088fb8;
P_0c088f24: /* original 6e03, guest PC 0x0c088f24 */
if(!s->budget--) { s->failed_pc=0x0c088f24u; return 0; }
r[14]=r[0];
goto P_0c088f26;
P_0c088f26: /* original 0e45, guest PC 0x0c088f26 */
if(!s->budget--) { s->failed_pc=0x0c088f26u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c088f28;
P_0c088f28: /* original e026, guest PC 0x0c088f28 */
if(!s->budget--) { s->failed_pc=0x0c088f28u; return 0; }
r[0]=0x00000026u;
goto P_0c088f2a;
P_0c088f2a: /* original 00ec, guest PC 0x0c088f2a */
if(!s->budget--) { s->failed_pc=0x0c088f2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c088f2c;
P_0c088f2c: /* original c880, guest PC 0x0c088f2c */
if(!s->budget--) { s->failed_pc=0x0c088f2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c088f2e;
P_0c088f2e: /* original 8912, guest PC 0x0c088f2e */
if(!s->budget--) { s->failed_pc=0x0c088f2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088f56; }
goto P_0c088f30;
P_0c088f30: /* original d32a, guest PC 0x0c088f30 */
if(!s->budget--) { s->failed_pc=0x0c088f30u; return 0; }
r[3]=read(ram,0x0c088fdcu,4);
goto P_0c088f32;
P_0c088f32: /* original 55da, guest PC 0x0c088f32 */
if(!s->budget--) { s->failed_pc=0x0c088f32u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c088f34;
P_0c088f34: /* original 430b, guest PC 0x0c088f34 */
if(!s->budget--) { s->failed_pc=0x0c088f34u; return 0; }
target=r[3];
r[16]=0x0c088f38u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088f38u) { target=s->pc; goto dispatch; }
goto P_0c088f38;
P_0c088f36: /* original 64e3, guest PC 0x0c088f36 */
if(!s->budget--) { s->failed_pc=0x0c088f36u; return 0; }
r[4]=r[14];
goto P_0c088f38;
P_0c088f38: /* original e118, guest PC 0x0c088f38 */
if(!s->budget--) { s->failed_pc=0x0c088f38u; return 0; }
r[1]=0x00000018u;
goto P_0c088f3a;
P_0c088f3a: /* original 31ec, guest PC 0x0c088f3a */
if(!s->budget--) { s->failed_pc=0x0c088f3au; return 0; }
r[1]+=r[14];
goto P_0c088f3c;
P_0c088f3c: /* original e00c, guest PC 0x0c088f3c */
if(!s->budget--) { s->failed_pc=0x0c088f3cu; return 0; }
r[0]=0x0000000cu;
goto P_0c088f3e;
P_0c088f3e: /* original f318, guest PC 0x0c088f3e */
if(!s->budget--) { s->failed_pc=0x0c088f3eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c088f40;
P_0c088f40: /* original f2e6, guest PC 0x0c088f40 */
if(!s->budget--) { s->failed_pc=0x0c088f40u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c088f42;
P_0c088f42: /* original e120, guest PC 0x0c088f42 */
if(!s->budget--) { s->failed_pc=0x0c088f42u; return 0; }
r[1]=0x00000020u;
goto P_0c088f44;
P_0c088f44: /* original 31ec, guest PC 0x0c088f44 */
if(!s->budget--) { s->failed_pc=0x0c088f44u; return 0; }
r[1]+=r[14];
goto P_0c088f46;
P_0c088f46: /* original f230, guest PC 0x0c088f46 */
if(!s->budget--) { s->failed_pc=0x0c088f46u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c088f48;
P_0c088f48: /* original fe27, guest PC 0x0c088f48 */
if(!s->budget--) { s->failed_pc=0x0c088f48u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c088f4a;
P_0c088f4a: /* original e014, guest PC 0x0c088f4a */
if(!s->budget--) { s->failed_pc=0x0c088f4au; return 0; }
r[0]=0x00000014u;
goto P_0c088f4c;
P_0c088f4c: /* original f2e6, guest PC 0x0c088f4c */
if(!s->budget--) { s->failed_pc=0x0c088f4cu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c088f4e;
P_0c088f4e: /* original f318, guest PC 0x0c088f4e */
if(!s->budget--) { s->failed_pc=0x0c088f4eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c088f50;
P_0c088f50: /* original f230, guest PC 0x0c088f50 */
if(!s->budget--) { s->failed_pc=0x0c088f50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c088f52;
P_0c088f52: /* original a031, guest PC 0x0c088f52 */
if(!s->budget--) { s->failed_pc=0x0c088f52u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c088fb8;
P_0c088f54: /* original fe27, guest PC 0x0c088f54 */
if(!s->budget--) { s->failed_pc=0x0c088f54u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c088f56;
P_0c088f56: /* original d221, guest PC 0x0c088f56 */
if(!s->budget--) { s->failed_pc=0x0c088f56u; return 0; }
r[2]=read(ram,0x0c088fdcu,4);
goto P_0c088f58;
P_0c088f58: /* original 55d9, guest PC 0x0c088f58 */
if(!s->budget--) { s->failed_pc=0x0c088f58u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c088f5a;
P_0c088f5a: /* original 420b, guest PC 0x0c088f5a */
if(!s->budget--) { s->failed_pc=0x0c088f5au; return 0; }
target=r[2];
r[16]=0x0c088f5eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088f5eu) { target=s->pc; goto dispatch; }
goto P_0c088f5e;
P_0c088f5c: /* original 64e3, guest PC 0x0c088f5c */
if(!s->budget--) { s->failed_pc=0x0c088f5cu; return 0; }
r[4]=r[14];
goto P_0c088f5e;
P_0c088f5e: /* original e020, guest PC 0x0c088f5e */
if(!s->budget--) { s->failed_pc=0x0c088f5eu; return 0; }
r[0]=0x00000020u;
goto P_0c088f60;
P_0c088f60: /* original f38d, guest PC 0x0c088f60 */
if(!s->budget--) { s->failed_pc=0x0c088f60u; return 0; }
fr[3]=0;
goto P_0c088f62;
P_0c088f62: /* original f5d6, guest PC 0x0c088f62 */
if(!s->budget--) { s->failed_pc=0x0c088f62u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c088f64;
P_0c088f64: /* original e00c, guest PC 0x0c088f64 */
if(!s->budget--) { s->failed_pc=0x0c088f64u; return 0; }
r[0]=0x0000000cu;
goto P_0c088f66;
P_0c088f66: /* original f6e6, guest PC 0x0c088f66 */
if(!s->budget--) { s->failed_pc=0x0c088f66u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c088f68;
P_0c088f68: /* original e018, guest PC 0x0c088f68 */
if(!s->budget--) { s->failed_pc=0x0c088f68u; return 0; }
r[0]=0x00000018u;
goto P_0c088f6a;
P_0c088f6a: /* original f4e6, guest PC 0x0c088f6a */
if(!s->budget--) { s->failed_pc=0x0c088f6au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c088f6c;
P_0c088f6c: /* original f345, guest PC 0x0c088f6c */
if(!s->budget--) { s->failed_pc=0x0c088f6cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c088f6e;
P_0c088f6e: /* original 8d01, guest PC 0x0c088f6e */
if(!s->budget--) { s->failed_pc=0x0c088f6eu; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
if(cond) { goto P_0c088f74; }
goto P_0c088f72;
P_0c088f70: /* original f640, guest PC 0x0c088f70 */
if(!s->budget--) { s->failed_pc=0x0c088f70u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c088f72;
P_0c088f72: /* original f54d, guest PC 0x0c088f72 */
if(!s->budget--) { s->failed_pc=0x0c088f72u; return 0; }
fr[5]^=0x80000000u;
goto P_0c088f74;
P_0c088f74: /* original f450, guest PC 0x0c088f74 */
if(!s->budget--) { s->failed_pc=0x0c088f74u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c088f76;
P_0c088f76: /* original e00c, guest PC 0x0c088f76 */
if(!s->budget--) { s->failed_pc=0x0c088f76u; return 0; }
r[0]=0x0000000cu;
goto P_0c088f78;
P_0c088f78: /* original fe67, guest PC 0x0c088f78 */
if(!s->budget--) { s->failed_pc=0x0c088f78u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c088f7a;
P_0c088f7a: /* original e018, guest PC 0x0c088f7a */
if(!s->budget--) { s->failed_pc=0x0c088f7au; return 0; }
r[0]=0x00000018u;
goto P_0c088f7c;
P_0c088f7c: /* original fe47, guest PC 0x0c088f7c */
if(!s->budget--) { s->failed_pc=0x0c088f7cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c088f7e;
P_0c088f7e: /* original e020, guest PC 0x0c088f7e */
if(!s->budget--) { s->failed_pc=0x0c088f7eu; return 0; }
r[0]=0x00000020u;
goto P_0c088f80;
P_0c088f80: /* original f5d6, guest PC 0x0c088f80 */
if(!s->budget--) { s->failed_pc=0x0c088f80u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c088f82;
P_0c088f82: /* original e014, guest PC 0x0c088f82 */
if(!s->budget--) { s->failed_pc=0x0c088f82u; return 0; }
r[0]=0x00000014u;
goto P_0c088f84;
P_0c088f84: /* original f6e6, guest PC 0x0c088f84 */
if(!s->budget--) { s->failed_pc=0x0c088f84u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c088f86;
P_0c088f86: /* original e020, guest PC 0x0c088f86 */
if(!s->budget--) { s->failed_pc=0x0c088f86u; return 0; }
r[0]=0x00000020u;
goto P_0c088f88;
P_0c088f88: /* original f4e6, guest PC 0x0c088f88 */
if(!s->budget--) { s->failed_pc=0x0c088f88u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c088f8a;
P_0c088f8a: /* original f38d, guest PC 0x0c088f8a */
if(!s->budget--) { s->failed_pc=0x0c088f8au; return 0; }
fr[3]=0;
goto P_0c088f8c;
P_0c088f8c: /* original f345, guest PC 0x0c088f8c */
if(!s->budget--) { s->failed_pc=0x0c088f8cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c088f8e;
P_0c088f8e: /* original 8d01, guest PC 0x0c088f8e */
if(!s->budget--) { s->failed_pc=0x0c088f8eu; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
if(cond) { goto P_0c088f94; }
goto P_0c088f92;
P_0c088f90: /* original f640, guest PC 0x0c088f90 */
if(!s->budget--) { s->failed_pc=0x0c088f90u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c088f92;
P_0c088f92: /* original f54d, guest PC 0x0c088f92 */
if(!s->budget--) { s->failed_pc=0x0c088f92u; return 0; }
fr[5]^=0x80000000u;
goto P_0c088f94;
P_0c088f94: /* original f450, guest PC 0x0c088f94 */
if(!s->budget--) { s->failed_pc=0x0c088f94u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c088f96;
P_0c088f96: /* original e014, guest PC 0x0c088f96 */
if(!s->budget--) { s->failed_pc=0x0c088f96u; return 0; }
r[0]=0x00000014u;
goto P_0c088f98;
P_0c088f98: /* original fe67, guest PC 0x0c088f98 */
if(!s->budget--) { s->failed_pc=0x0c088f98u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c088f9a;
P_0c088f9a: /* original e020, guest PC 0x0c088f9a */
if(!s->budget--) { s->failed_pc=0x0c088f9au; return 0; }
r[0]=0x00000020u;
goto P_0c088f9c;
P_0c088f9c: /* original fe47, guest PC 0x0c088f9c */
if(!s->budget--) { s->failed_pc=0x0c088f9cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c088f9e;
P_0c088f9e: /* original e01c, guest PC 0x0c088f9e */
if(!s->budget--) { s->failed_pc=0x0c088f9eu; return 0; }
r[0]=0x0000001cu;
goto P_0c088fa0;
P_0c088fa0: /* original f4e6, guest PC 0x0c088fa0 */
if(!s->budget--) { s->failed_pc=0x0c088fa0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c088fa2;
P_0c088fa2: /* original e010, guest PC 0x0c088fa2 */
if(!s->budget--) { s->failed_pc=0x0c088fa2u; return 0; }
r[0]=0x00000010u;
goto P_0c088fa4;
P_0c088fa4: /* original f5e6, guest PC 0x0c088fa4 */
if(!s->budget--) { s->failed_pc=0x0c088fa4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c088fa6;
P_0c088fa6: /* original f540, guest PC 0x0c088fa6 */
if(!s->budget--) { s->failed_pc=0x0c088fa6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c088fa8;
P_0c088fa8: /* original f4f0, guest PC 0x0c088fa8 */
if(!s->budget--) { s->failed_pc=0x0c088fa8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c088faa;
P_0c088faa: /* original fe57, guest PC 0x0c088faa */
if(!s->budget--) { s->failed_pc=0x0c088faau; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c088fac;
P_0c088fac: /* original f3f8, guest PC 0x0c088fac */
if(!s->budget--) { s->failed_pc=0x0c088facu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c088fae;
P_0c088fae: /* original f435, guest PC 0x0c088fae */
if(!s->budget--) { s->failed_pc=0x0c088faeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c088fb0;
P_0c088fb0: /* original 8d01, guest PC 0x0c088fb0 */
if(!s->budget--) { s->failed_pc=0x0c088fb0u; return 0; }
cond=r[17]&1u;
r[0]=0x0000001cu;
if(cond) { goto P_0c088fb6; }
goto P_0c088fb4;
P_0c088fb2: /* original e01c, guest PC 0x0c088fb2 */
if(!s->budget--) { s->failed_pc=0x0c088fb2u; return 0; }
r[0]=0x0000001cu;
goto P_0c088fb4;
P_0c088fb4: /* original f4f1, guest PC 0x0c088fb4 */
if(!s->budget--) { s->failed_pc=0x0c088fb4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c088fb6;
P_0c088fb6: /* original fe47, guest PC 0x0c088fb6 */
if(!s->budget--) { s->failed_pc=0x0c088fb6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c088fb8;
P_0c088fb8: /* original 60e2, guest PC 0x0c088fb8 */
if(!s->budget--) { s->failed_pc=0x0c088fb8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c088fba;
P_0c088fba: /* original 88ff, guest PC 0x0c088fba */
if(!s->budget--) { s->failed_pc=0x0c088fbau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c088fbc;
P_0c088fbc: /* original 8d02, guest PC 0x0c088fbc */
if(!s->budget--) { s->failed_pc=0x0c088fbcu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c088fc4; }
goto P_0c088fc0;
P_0c088fbe: /* original 6403, guest PC 0x0c088fbe */
if(!s->budget--) { s->failed_pc=0x0c088fbeu; return 0; }
r[4]=r[0];
goto P_0c088fc0;
P_0c088fc0: /* original afa6, guest PC 0x0c088fc0 */
if(!s->budget--) { s->failed_pc=0x0c088fc0u; return 0; }
r[14]=r[4];
goto P_0c088f10;
P_0c088fc2: /* original 6e43, guest PC 0x0c088fc2 */
if(!s->budget--) { s->failed_pc=0x0c088fc2u; return 0; }
r[14]=r[4];
goto P_0c088fc4;
P_0c088fc4: /* original 7f04, guest PC 0x0c088fc4 */
if(!s->budget--) { s->failed_pc=0x0c088fc4u; return 0; }
r[15]+=0x00000004u;
goto P_0c088fc6;
P_0c088fc6: /* original 4f26, guest PC 0x0c088fc6 */
if(!s->budget--) { s->failed_pc=0x0c088fc6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088fc8;
P_0c088fc8: /* original fff9, guest PC 0x0c088fc8 */
if(!s->budget--) { s->failed_pc=0x0c088fc8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088fca;
P_0c088fca: /* original 6df6, guest PC 0x0c088fca */
if(!s->budget--) { s->failed_pc=0x0c088fcau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088fcc;
P_0c088fcc: /* original 000b, guest PC 0x0c088fcc */
if(!s->budget--) { s->failed_pc=0x0c088fccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088fce: /* original 6ef6, guest PC 0x0c088fce */
if(!s->budget--) { s->failed_pc=0x0c088fceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c088fd0u,s,ram);
P_0c088fe0: /* original 2fe6, guest PC 0x0c088fe0 */
if(!s->budget--) { s->failed_pc=0x0c088fe0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088fe2;
P_0c088fe2: /* original c759, guest PC 0x0c088fe2 */
if(!s->budget--) { s->failed_pc=0x0c088fe2u; return 0; }
r[0]=0x0c089148u;
goto P_0c088fe4;
P_0c088fe4: /* original 2fd6, guest PC 0x0c088fe4 */
if(!s->budget--) { s->failed_pc=0x0c088fe4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088fe6;
P_0c088fe6: /* original 6d43, guest PC 0x0c088fe6 */
if(!s->budget--) { s->failed_pc=0x0c088fe6u; return 0; }
r[13]=r[4];
goto P_0c088fe8;
P_0c088fe8: /* original 4f22, guest PC 0x0c088fe8 */
if(!s->budget--) { s->failed_pc=0x0c088fe8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088fea;
P_0c088fea: /* original 7ff8, guest PC 0x0c088fea */
if(!s->budget--) { s->failed_pc=0x0c088feau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c088fec;
P_0c088fec: /* original 2f52, guest PC 0x0c088fec */
if(!s->budget--) { s->failed_pc=0x0c088fecu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c088fee;
P_0c088fee: /* original f308, guest PC 0x0c088fee */
if(!s->budget--) { s->failed_pc=0x0c088feeu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c088ff0;
P_0c088ff0: /* original e004, guest PC 0x0c088ff0 */
if(!s->budget--) { s->failed_pc=0x0c088ff0u; return 0; }
r[0]=0x00000004u;
goto P_0c088ff2;
P_0c088ff2: /* original ff37, guest PC 0x0c088ff2 */
if(!s->budget--) { s->failed_pc=0x0c088ff2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088ff4;
P_0c088ff4: /* original d355, guest PC 0x0c088ff4 */
if(!s->budget--) { s->failed_pc=0x0c088ff4u; return 0; }
r[3]=read(ram,0x0c08914cu,4);
goto P_0c088ff6;
P_0c088ff6: /* original 430b, guest PC 0x0c088ff6 */
if(!s->budget--) { s->failed_pc=0x0c088ff6u; return 0; }
target=r[3];
r[16]=0x0c088ffau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088ffau) { target=s->pc; goto dispatch; }
goto P_0c088ffa;
P_0c088ff8: /* original 64d3, guest PC 0x0c088ff8 */
if(!s->budget--) { s->failed_pc=0x0c088ff8u; return 0; }
r[4]=r[13];
goto P_0c088ffa;
P_0c088ffa: /* original 88ff, guest PC 0x0c088ffa */
if(!s->budget--) { s->failed_pc=0x0c088ffau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c088ffc;
P_0c088ffc: /* original 8d3f, guest PC 0x0c088ffc */
if(!s->budget--) { s->failed_pc=0x0c088ffcu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c08907e; }
goto P_0c089000;
P_0c088ffe: /* original 6403, guest PC 0x0c088ffe */
if(!s->budget--) { s->failed_pc=0x0c088ffeu; return 0; }
r[4]=r[0];
goto P_0c089000;
P_0c089000: /* original 93a1, guest PC 0x0c089000 */
if(!s->budget--) { s->failed_pc=0x0c089000u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089146u,2);
goto P_0c089002;
P_0c089002: /* original 6e43, guest PC 0x0c089002 */
if(!s->budget--) { s->failed_pc=0x0c089002u; return 0; }
r[14]=r[4];
goto P_0c089004;
P_0c089004: /* original e024, guest PC 0x0c089004 */
if(!s->budget--) { s->failed_pc=0x0c089004u; return 0; }
r[0]=0x00000024u;
goto P_0c089006;
P_0c089006: /* original 0e35, guest PC 0x0c089006 */
if(!s->budget--) { s->failed_pc=0x0c089006u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c089008;
P_0c089008: /* original e388, guest PC 0x0c089008 */
if(!s->budget--) { s->failed_pc=0x0c089008u; return 0; }
r[3]=0xffffff88u;
goto P_0c08900a;
P_0c08900a: /* original 64f2, guest PC 0x0c08900a */
if(!s->budget--) { s->failed_pc=0x0c08900au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08900c;
P_0c08900c: /* original d050, guest PC 0x0c08900c */
if(!s->budget--) { s->failed_pc=0x0c08900cu; return 0; }
r[0]=read(ram,0x0c089150u,4);
goto P_0c08900e;
P_0c08900e: /* original 74ff, guest PC 0x0c08900e */
if(!s->budget--) { s->failed_pc=0x0c08900eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c089010;
P_0c089010: /* original f38d, guest PC 0x0c089010 */
if(!s->budget--) { s->failed_pc=0x0c089010u; return 0; }
fr[3]=0;
goto P_0c089012;
P_0c089012: /* original 4408, guest PC 0x0c089012 */
if(!s->budget--) { s->failed_pc=0x0c089012u; return 0; }
r[4]<<=2;
goto P_0c089014;
P_0c089014: /* original 044e, guest PC 0x0c089014 */
if(!s->budget--) { s->failed_pc=0x0c089014u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c089016;
P_0c089016: /* original e008, guest PC 0x0c089016 */
if(!s->budget--) { s->failed_pc=0x0c089016u; return 0; }
r[0]=0x00000008u;
goto P_0c089018;
P_0c089018: /* original f548, guest PC 0x0c089018 */
if(!s->budget--) { s->failed_pc=0x0c089018u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c08901a;
P_0c08901a: /* original f446, guest PC 0x0c08901a */
if(!s->budget--) { s->failed_pc=0x0c08901au; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c08901c;
P_0c08901c: /* original c74d, guest PC 0x0c08901c */
if(!s->budget--) { s->failed_pc=0x0c08901cu; return 0; }
r[0]=0x0c089154u;
goto P_0c08901e;
P_0c08901e: /* original f530, guest PC 0x0c08901e */
if(!s->budget--) { s->failed_pc=0x0c08901eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c089020;
P_0c089020: /* original f208, guest PC 0x0c089020 */
if(!s->budget--) { s->failed_pc=0x0c089020u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c089022;
P_0c089022: /* original e00c, guest PC 0x0c089022 */
if(!s->budget--) { s->failed_pc=0x0c089022u; return 0; }
r[0]=0x0000000cu;
goto P_0c089024;
P_0c089024: /* original f420, guest PC 0x0c089024 */
if(!s->budget--) { s->failed_pc=0x0c089024u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c089026;
P_0c089026: /* original fe57, guest PC 0x0c089026 */
if(!s->budget--) { s->failed_pc=0x0c089026u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c089028;
P_0c089028: /* original e004, guest PC 0x0c089028 */
if(!s->budget--) { s->failed_pc=0x0c089028u; return 0; }
r[0]=0x00000004u;
goto P_0c08902a;
P_0c08902a: /* original f1f6, guest PC 0x0c08902a */
if(!s->budget--) { s->failed_pc=0x0c08902au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08902c;
P_0c08902c: /* original e010, guest PC 0x0c08902c */
if(!s->budget--) { s->failed_pc=0x0c08902cu; return 0; }
r[0]=0x00000010u;
goto P_0c08902e;
P_0c08902e: /* original fe17, guest PC 0x0c08902e */
if(!s->budget--) { s->failed_pc=0x0c08902eu; return 0; }
vf3_matrix_store(s,ram,1,r[14]+r[0]);
goto P_0c089030;
P_0c089030: /* original e014, guest PC 0x0c089030 */
if(!s->budget--) { s->failed_pc=0x0c089030u; return 0; }
r[0]=0x00000014u;
goto P_0c089032;
P_0c089032: /* original fe47, guest PC 0x0c089032 */
if(!s->budget--) { s->failed_pc=0x0c089032u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c089034;
P_0c089034: /* original e026, guest PC 0x0c089034 */
if(!s->budget--) { s->failed_pc=0x0c089034u; return 0; }
r[0]=0x00000026u;
goto P_0c089036;
P_0c089036: /* original d248, guest PC 0x0c089036 */
if(!s->budget--) { s->failed_pc=0x0c089036u; return 0; }
r[2]=read(ram,0x0c089158u,4);
goto P_0c089038;
P_0c089038: /* original 420b, guest PC 0x0c089038 */
if(!s->budget--) { s->failed_pc=0x0c089038u; return 0; }
target=r[2];
r[16]=0x0c08903cu;
write(ram,r[14]+r[0],r[3],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08903cu) { target=s->pc; goto dispatch; }
goto P_0c08903c;
P_0c08903a: /* original 0e34, guest PC 0x0c08903a */
if(!s->budget--) { s->failed_pc=0x0c08903au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08903c;
P_0c08903c: /* original e307, guest PC 0x0c08903c */
if(!s->budget--) { s->failed_pc=0x0c08903cu; return 0; }
r[3]=0x00000007u;
goto P_0c08903e;
P_0c08903e: /* original 6403, guest PC 0x0c08903e */
if(!s->budget--) { s->failed_pc=0x0c08903eu; return 0; }
r[4]=r[0];
goto P_0c089040;
P_0c089040: /* original 2439, guest PC 0x0c089040 */
if(!s->budget--) { s->failed_pc=0x0c089040u; return 0; }
r[4]&=r[3];
goto P_0c089042;
P_0c089042: /* original 445a, guest PC 0x0c089042 */
if(!s->budget--) { s->failed_pc=0x0c089042u; return 0; }
r[53]=r[4];
goto P_0c089044;
P_0c089044: /* original c745, guest PC 0x0c089044 */
if(!s->budget--) { s->failed_pc=0x0c089044u; return 0; }
r[0]=0x0c08915cu;
goto P_0c089046;
P_0c089046: /* original e201, guest PC 0x0c089046 */
if(!s->budget--) { s->failed_pc=0x0c089046u; return 0; }
r[2]=0x00000001u;
goto P_0c089048;
P_0c089048: /* original 2428, guest PC 0x0c089048 */
if(!s->budget--) { s->failed_pc=0x0c089048u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08904a;
P_0c08904a: /* original f32d, guest PC 0x0c08904a */
if(!s->budget--) { s->failed_pc=0x0c08904au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08904c;
P_0c08904c: /* original f43c, guest PC 0x0c08904c */
if(!s->budget--) { s->failed_pc=0x0c08904cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08904e;
P_0c08904e: /* original f308, guest PC 0x0c08904e */
if(!s->budget--) { s->failed_pc=0x0c08904eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089050;
P_0c089050: /* original 8d01, guest PC 0x0c089050 */
if(!s->budget--) { s->failed_pc=0x0c089050u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
if(cond) { goto P_0c089056; }
goto P_0c089054;
P_0c089052: /* original f432, guest PC 0x0c089052 */
if(!s->budget--) { s->failed_pc=0x0c089052u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c089054;
P_0c089054: /* original f44d, guest PC 0x0c089054 */
if(!s->budget--) { s->failed_pc=0x0c089054u; return 0; }
fr[4]^=0x80000000u;
goto P_0c089056;
P_0c089056: /* original e01c, guest PC 0x0c089056 */
if(!s->budget--) { s->failed_pc=0x0c089056u; return 0; }
r[0]=0x0000001cu;
goto P_0c089058;
P_0c089058: /* original 64e3, guest PC 0x0c089058 */
if(!s->budget--) { s->failed_pc=0x0c089058u; return 0; }
r[4]=r[14];
goto P_0c08905a;
P_0c08905a: /* original f5d6, guest PC 0x0c08905a */
if(!s->budget--) { s->failed_pc=0x0c08905au; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c08905c;
P_0c08905c: /* original e018, guest PC 0x0c08905c */
if(!s->budget--) { s->failed_pc=0x0c08905cu; return 0; }
r[0]=0x00000018u;
goto P_0c08905e;
P_0c08905e: /* original 7f08, guest PC 0x0c08905e */
if(!s->budget--) { s->failed_pc=0x0c08905eu; return 0; }
r[15]+=0x00000008u;
goto P_0c089060;
P_0c089060: /* original f540, guest PC 0x0c089060 */
if(!s->budget--) { s->failed_pc=0x0c089060u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c089062;
P_0c089062: /* original 4f26, guest PC 0x0c089062 */
if(!s->budget--) { s->failed_pc=0x0c089062u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089064;
P_0c089064: /* original fe57, guest PC 0x0c089064 */
if(!s->budget--) { s->failed_pc=0x0c089064u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c089066;
P_0c089066: /* original e01c, guest PC 0x0c089066 */
if(!s->budget--) { s->failed_pc=0x0c089066u; return 0; }
r[0]=0x0000001cu;
goto P_0c089068;
P_0c089068: /* original f38d, guest PC 0x0c089068 */
if(!s->budget--) { s->failed_pc=0x0c089068u; return 0; }
fr[3]=0;
goto P_0c08906a;
P_0c08906a: /* original fe37, guest PC 0x0c08906a */
if(!s->budget--) { s->failed_pc=0x0c08906au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08906c;
P_0c08906c: /* original c73c, guest PC 0x0c08906c */
if(!s->budget--) { s->failed_pc=0x0c08906cu; return 0; }
r[0]=0x0c089160u;
goto P_0c08906e;
P_0c08906e: /* original f308, guest PC 0x0c08906e */
if(!s->budget--) { s->failed_pc=0x0c08906eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089070;
P_0c089070: /* original e020, guest PC 0x0c089070 */
if(!s->budget--) { s->failed_pc=0x0c089070u; return 0; }
r[0]=0x00000020u;
goto P_0c089072;
P_0c089072: /* original fe37, guest PC 0x0c089072 */
if(!s->budget--) { s->failed_pc=0x0c089072u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089074;
P_0c089074: /* original 55da, guest PC 0x0c089074 */
if(!s->budget--) { s->failed_pc=0x0c089074u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c089076;
P_0c089076: /* original d33b, guest PC 0x0c089076 */
if(!s->budget--) { s->failed_pc=0x0c089076u; return 0; }
r[3]=read(ram,0x0c089164u,4);
goto P_0c089078;
P_0c089078: /* original 6df6, guest PC 0x0c089078 */
if(!s->budget--) { s->failed_pc=0x0c089078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08907a;
P_0c08907a: /* original 432b, guest PC 0x0c08907a */
if(!s->budget--) { s->failed_pc=0x0c08907au; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c08907c: /* original 6ef6, guest PC 0x0c08907c */
if(!s->budget--) { s->failed_pc=0x0c08907cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08907e;
P_0c08907e: /* original 7f08, guest PC 0x0c08907e */
if(!s->budget--) { s->failed_pc=0x0c08907eu; return 0; }
r[15]+=0x00000008u;
goto P_0c089080;
P_0c089080: /* original 4f26, guest PC 0x0c089080 */
if(!s->budget--) { s->failed_pc=0x0c089080u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089082;
P_0c089082: /* original 6df6, guest PC 0x0c089082 */
if(!s->budget--) { s->failed_pc=0x0c089082u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089084;
P_0c089084: /* original 000b, guest PC 0x0c089084 */
if(!s->budget--) { s->failed_pc=0x0c089084u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089086: /* original 6ef6, guest PC 0x0c089086 */
if(!s->budget--) { s->failed_pc=0x0c089086u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c089088;
P_0c089088: /* original 2fe6, guest PC 0x0c089088 */
if(!s->budget--) { s->failed_pc=0x0c089088u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08908a;
P_0c08908a: /* original 2fd6, guest PC 0x0c08908a */
if(!s->budget--) { s->failed_pc=0x0c08908au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08908c;
P_0c08908c: /* original 6d43, guest PC 0x0c08908c */
if(!s->budget--) { s->failed_pc=0x0c08908cu; return 0; }
r[13]=r[4];
goto P_0c08908e;
P_0c08908e: /* original fffb, guest PC 0x0c08908e */
if(!s->budget--) { s->failed_pc=0x0c08908eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c089090;
P_0c089090: /* original ffeb, guest PC 0x0c089090 */
if(!s->budget--) { s->failed_pc=0x0c089090u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c089092;
P_0c089092: /* original ffdb, guest PC 0x0c089092 */
if(!s->budget--) { s->failed_pc=0x0c089092u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c089094;
P_0c089094: /* original ffcb, guest PC 0x0c089094 */
if(!s->budget--) { s->failed_pc=0x0c089094u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c089096;
P_0c089096: /* original 4f22, guest PC 0x0c089096 */
if(!s->budget--) { s->failed_pc=0x0c089096u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089098;
P_0c089098: /* original 7ff4, guest PC 0x0c089098 */
if(!s->budget--) { s->failed_pc=0x0c089098u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08909a;
P_0c08909a: /* original 1f51, guest PC 0x0c08909a */
if(!s->budget--) { s->failed_pc=0x0c08909au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c08909c;
P_0c08909c: /* original d32b, guest PC 0x0c08909c */
if(!s->budget--) { s->failed_pc=0x0c08909cu; return 0; }
r[3]=read(ram,0x0c08914cu,4);
goto P_0c08909e;
P_0c08909e: /* original 430b, guest PC 0x0c08909e */
if(!s->budget--) { s->failed_pc=0x0c08909eu; return 0; }
target=r[3];
r[16]=0x0c0890a2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0890a2u) { target=s->pc; goto dispatch; }
goto P_0c0890a2;
P_0c0890a0: /* original 64d3, guest PC 0x0c0890a0 */
if(!s->budget--) { s->failed_pc=0x0c0890a0u; return 0; }
r[4]=r[13];
goto P_0c0890a2;
P_0c0890a2: /* original 88ff, guest PC 0x0c0890a2 */
if(!s->budget--) { s->failed_pc=0x0c0890a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0890a4;
P_0c0890a4: /* original 8d66, guest PC 0x0c0890a4 */
if(!s->budget--) { s->failed_pc=0x0c0890a4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c089174; }
goto P_0c0890a8;
P_0c0890a6: /* original 6403, guest PC 0x0c0890a6 */
if(!s->budget--) { s->failed_pc=0x0c0890a6u; return 0; }
r[4]=r[0];
goto P_0c0890a8;
P_0c0890a8: /* original c72f, guest PC 0x0c0890a8 */
if(!s->budget--) { s->failed_pc=0x0c0890a8u; return 0; }
r[0]=0x0c089168u;
goto P_0c0890aa;
P_0c0890aa: /* original d330, guest PC 0x0c0890aa */
if(!s->budget--) { s->failed_pc=0x0c0890aau; return 0; }
r[3]=read(ram,0x0c08916cu,4);
goto P_0c0890ac;
P_0c0890ac: /* original fd08, guest PC 0x0c0890ac */
if(!s->budget--) { s->failed_pc=0x0c0890acu; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c0890ae;
P_0c0890ae: /* original 6e43, guest PC 0x0c0890ae */
if(!s->budget--) { s->failed_pc=0x0c0890aeu; return 0; }
r[14]=r[4];
goto P_0c0890b0;
P_0c0890b0: /* original e02e, guest PC 0x0c0890b0 */
if(!s->budget--) { s->failed_pc=0x0c0890b0u; return 0; }
r[0]=0x0000002eu;
goto P_0c0890b2;
P_0c0890b2: /* original 430b, guest PC 0x0c0890b2 */
if(!s->budget--) { s->failed_pc=0x0c0890b2u; return 0; }
target=r[3];
r[16]=0x0c0890b6u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0890b6u) { target=s->pc; goto dispatch; }
goto P_0c0890b6;
P_0c0890b4: /* original 04dd, guest PC 0x0c0890b4 */
if(!s->budget--) { s->failed_pc=0x0c0890b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0890b6;
P_0c0890b6: /* original e02d, guest PC 0x0c0890b6 */
if(!s->budget--) { s->failed_pc=0x0c0890b6u; return 0; }
r[0]=0x0000002du;
goto P_0c0890b8;
P_0c0890b8: /* original f40c, guest PC 0x0c0890b8 */
if(!s->budget--) { s->failed_pc=0x0c0890b8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0890ba;
P_0c0890ba: /* original 02dc, guest PC 0x0c0890ba */
if(!s->budget--) { s->failed_pc=0x0c0890bau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0890bc;
P_0c0890bc: /* original e024, guest PC 0x0c0890bc */
if(!s->budget--) { s->failed_pc=0x0c0890bcu; return 0; }
r[0]=0x00000024u;
goto P_0c0890be;
P_0c0890be: /* original fd42, guest PC 0x0c0890be */
if(!s->budget--) { s->failed_pc=0x0c0890beu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c0890c0;
P_0c0890c0: /* original 0e25, guest PC 0x0c0890c0 */
if(!s->budget--) { s->failed_pc=0x0c0890c0u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0890c2;
P_0c0890c2: /* original 54f1, guest PC 0x0c0890c2 */
if(!s->budget--) { s->failed_pc=0x0c0890c2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0890c4;
P_0c0890c4: /* original d022, guest PC 0x0c0890c4 */
if(!s->budget--) { s->failed_pc=0x0c0890c4u; return 0; }
r[0]=read(ram,0x0c089150u,4);
goto P_0c0890c6;
P_0c0890c6: /* original 74ff, guest PC 0x0c0890c6 */
if(!s->budget--) { s->failed_pc=0x0c0890c6u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0890c8;
P_0c0890c8: /* original 4408, guest PC 0x0c0890c8 */
if(!s->budget--) { s->failed_pc=0x0c0890c8u; return 0; }
r[4]<<=2;
goto P_0c0890ca;
P_0c0890ca: /* original 044e, guest PC 0x0c0890ca */
if(!s->budget--) { s->failed_pc=0x0c0890cau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0890cc;
P_0c0890cc: /* original e004, guest PC 0x0c0890cc */
if(!s->budget--) { s->failed_pc=0x0c0890ccu; return 0; }
r[0]=0x00000004u;
goto P_0c0890ce;
P_0c0890ce: /* original f346, guest PC 0x0c0890ce */
if(!s->budget--) { s->failed_pc=0x0c0890ceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0890d0;
P_0c0890d0: /* original e008, guest PC 0x0c0890d0 */
if(!s->budget--) { s->failed_pc=0x0c0890d0u; return 0; }
r[0]=0x00000008u;
goto P_0c0890d2;
P_0c0890d2: /* original ff48, guest PC 0x0c0890d2 */
if(!s->budget--) { s->failed_pc=0x0c0890d2u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
goto P_0c0890d4;
P_0c0890d4: /* original ff37, guest PC 0x0c0890d4 */
if(!s->budget--) { s->failed_pc=0x0c0890d4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0890d6;
P_0c0890d6: /* original e008, guest PC 0x0c0890d6 */
if(!s->budget--) { s->failed_pc=0x0c0890d6u; return 0; }
r[0]=0x00000008u;
goto P_0c0890d8;
P_0c0890d8: /* original fc46, guest PC 0x0c0890d8 */
if(!s->budget--) { s->failed_pc=0x0c0890d8u; return 0; }
vf3_matrix_load(s,ram,12,r[4]+r[0]);
goto P_0c0890da;
P_0c0890da: /* original e00c, guest PC 0x0c0890da */
if(!s->budget--) { s->failed_pc=0x0c0890dau; return 0; }
r[0]=0x0000000cu;
goto P_0c0890dc;
P_0c0890dc: /* original f346, guest PC 0x0c0890dc */
if(!s->budget--) { s->failed_pc=0x0c0890dcu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0890de;
P_0c0890de: /* original e010, guest PC 0x0c0890de */
if(!s->budget--) { s->failed_pc=0x0c0890deu; return 0; }
r[0]=0x00000010u;
goto P_0c0890e0;
P_0c0890e0: /* original ff3a, guest PC 0x0c0890e0 */
if(!s->budget--) { s->failed_pc=0x0c0890e0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0890e2;
P_0c0890e2: /* original d31d, guest PC 0x0c0890e2 */
if(!s->budget--) { s->failed_pc=0x0c0890e2u; return 0; }
r[3]=read(ram,0x0c089158u,4);
goto P_0c0890e4;
P_0c0890e4: /* original 430b, guest PC 0x0c0890e4 */
if(!s->budget--) { s->failed_pc=0x0c0890e4u; return 0; }
target=r[3];
r[16]=0x0c0890e8u;
vf3_matrix_load(s,ram,14,r[4]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0890e8u) { target=s->pc; goto dispatch; }
goto P_0c0890e8;
P_0c0890e6: /* original fe46, guest PC 0x0c0890e6 */
if(!s->budget--) { s->failed_pc=0x0c0890e6u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c0890e8;
P_0c0890e8: /* original e207, guest PC 0x0c0890e8 */
if(!s->budget--) { s->failed_pc=0x0c0890e8u; return 0; }
r[2]=0x00000007u;
goto P_0c0890ea;
P_0c0890ea: /* original 6403, guest PC 0x0c0890ea */
if(!s->budget--) { s->failed_pc=0x0c0890eau; return 0; }
r[4]=r[0];
goto P_0c0890ec;
P_0c0890ec: /* original 2429, guest PC 0x0c0890ec */
if(!s->budget--) { s->failed_pc=0x0c0890ecu; return 0; }
r[4]&=r[2];
goto P_0c0890ee;
P_0c0890ee: /* original fed0, guest PC 0x0c0890ee */
if(!s->budget--) { s->failed_pc=0x0c0890eeu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[13],r[18],'+');
goto P_0c0890f0;
P_0c0890f0: /* original 445a, guest PC 0x0c0890f0 */
if(!s->budget--) { s->failed_pc=0x0c0890f0u; return 0; }
r[53]=r[4];
goto P_0c0890f2;
P_0c0890f2: /* original c71f, guest PC 0x0c0890f2 */
if(!s->budget--) { s->failed_pc=0x0c0890f2u; return 0; }
r[0]=0x0c089170u;
goto P_0c0890f4;
P_0c0890f4: /* original f408, guest PC 0x0c0890f4 */
if(!s->budget--) { s->failed_pc=0x0c0890f4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0890f6;
P_0c0890f6: /* original e00c, guest PC 0x0c0890f6 */
if(!s->budget--) { s->failed_pc=0x0c0890f6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0890f8;
P_0c0890f8: /* original f32d, guest PC 0x0c0890f8 */
if(!s->budget--) { s->failed_pc=0x0c0890f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0890fa;
P_0c0890fa: /* original f04c, guest PC 0x0c0890fa */
if(!s->budget--) { s->failed_pc=0x0c0890fau; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0890fc;
P_0c0890fc: /* original fce0, guest PC 0x0c0890fc */
if(!s->budget--) { s->failed_pc=0x0c0890fcu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[14],r[18],'+');
goto P_0c0890fe;
P_0c0890fe: /* original f53c, guest PC 0x0c0890fe */
if(!s->budget--) { s->failed_pc=0x0c0890feu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c089100;
P_0c089100: /* original f3fc, guest PC 0x0c089100 */
if(!s->budget--) { s->failed_pc=0x0c089100u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c089102;
P_0c089102: /* original f35e, guest PC 0x0c089102 */
if(!s->budget--) { s->failed_pc=0x0c089102u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c089104;
P_0c089104: /* original ff3c, guest PC 0x0c089104 */
if(!s->budget--) { s->failed_pc=0x0c089104u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c089106;
P_0c089106: /* original fef7, guest PC 0x0c089106 */
if(!s->budget--) { s->failed_pc=0x0c089106u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089108;
P_0c089108: /* original e008, guest PC 0x0c089108 */
if(!s->budget--) { s->failed_pc=0x0c089108u; return 0; }
r[0]=0x00000008u;
goto P_0c08910a;
P_0c08910a: /* original f3f6, guest PC 0x0c08910a */
if(!s->budget--) { s->failed_pc=0x0c08910au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08910c;
P_0c08910c: /* original e010, guest PC 0x0c08910c */
if(!s->budget--) { s->failed_pc=0x0c08910cu; return 0; }
r[0]=0x00000010u;
goto P_0c08910e;
P_0c08910e: /* original fe37, guest PC 0x0c08910e */
if(!s->budget--) { s->failed_pc=0x0c08910eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089110;
P_0c089110: /* original e014, guest PC 0x0c089110 */
if(!s->budget--) { s->failed_pc=0x0c089110u; return 0; }
r[0]=0x00000014u;
goto P_0c089112;
P_0c089112: /* original fec7, guest PC 0x0c089112 */
if(!s->budget--) { s->failed_pc=0x0c089112u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c089114;
P_0c089114: /* original e018, guest PC 0x0c089114 */
if(!s->budget--) { s->failed_pc=0x0c089114u; return 0; }
r[0]=0x00000018u;
goto P_0c089116;
P_0c089116: /* original f3f8, guest PC 0x0c089116 */
if(!s->budget--) { s->failed_pc=0x0c089116u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089118;
P_0c089118: /* original f342, guest PC 0x0c089118 */
if(!s->budget--) { s->failed_pc=0x0c089118u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c08911a;
P_0c08911a: /* original ff3a, guest PC 0x0c08911a */
if(!s->budget--) { s->failed_pc=0x0c08911au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08911c;
P_0c08911c: /* original fe37, guest PC 0x0c08911c */
if(!s->budget--) { s->failed_pc=0x0c08911cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08911e;
P_0c08911e: /* original e01c, guest PC 0x0c08911e */
if(!s->budget--) { s->failed_pc=0x0c08911eu; return 0; }
r[0]=0x0000001cu;
goto P_0c089120;
P_0c089120: /* original f38d, guest PC 0x0c089120 */
if(!s->budget--) { s->failed_pc=0x0c089120u; return 0; }
fr[3]=0;
goto P_0c089122;
P_0c089122: /* original fe37, guest PC 0x0c089122 */
if(!s->budget--) { s->failed_pc=0x0c089122u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089124;
P_0c089124: /* original e020, guest PC 0x0c089124 */
if(!s->budget--) { s->failed_pc=0x0c089124u; return 0; }
r[0]=0x00000020u;
goto P_0c089126;
P_0c089126: /* original fee7, guest PC 0x0c089126 */
if(!s->budget--) { s->failed_pc=0x0c089126u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c089128;
P_0c089128: /* original 7f0c, guest PC 0x0c089128 */
if(!s->budget--) { s->failed_pc=0x0c089128u; return 0; }
r[15]+=0x0000000cu;
goto P_0c08912a;
P_0c08912a: /* original 64e3, guest PC 0x0c08912a */
if(!s->budget--) { s->failed_pc=0x0c08912au; return 0; }
r[4]=r[14];
goto P_0c08912c;
P_0c08912c: /* original 4f26, guest PC 0x0c08912c */
if(!s->budget--) { s->failed_pc=0x0c08912cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08912e;
P_0c08912e: /* original e300, guest PC 0x0c08912e */
if(!s->budget--) { s->failed_pc=0x0c08912eu; return 0; }
r[3]=0x00000000u;
goto P_0c089130;
P_0c089130: /* original e026, guest PC 0x0c089130 */
if(!s->budget--) { s->failed_pc=0x0c089130u; return 0; }
r[0]=0x00000026u;
goto P_0c089132;
P_0c089132: /* original 0e34, guest PC 0x0c089132 */
if(!s->budget--) { s->failed_pc=0x0c089132u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c089134;
P_0c089134: /* original fcf9, guest PC 0x0c089134 */
if(!s->budget--) { s->failed_pc=0x0c089134u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089136;
P_0c089136: /* original 55d9, guest PC 0x0c089136 */
if(!s->budget--) { s->failed_pc=0x0c089136u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c089138;
P_0c089138: /* original fdf9, guest PC 0x0c089138 */
if(!s->budget--) { s->failed_pc=0x0c089138u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08913a;
P_0c08913a: /* original d30a, guest PC 0x0c08913a */
if(!s->budget--) { s->failed_pc=0x0c08913au; return 0; }
r[3]=read(ram,0x0c089164u,4);
goto P_0c08913c;
P_0c08913c: /* original fef9, guest PC 0x0c08913c */
if(!s->budget--) { s->failed_pc=0x0c08913cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08913e;
P_0c08913e: /* original fff9, guest PC 0x0c08913e */
if(!s->budget--) { s->failed_pc=0x0c08913eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089140;
P_0c089140: /* original 6df6, guest PC 0x0c089140 */
if(!s->budget--) { s->failed_pc=0x0c089140u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089142;
P_0c089142: /* original 432b, guest PC 0x0c089142 */
if(!s->budget--) { s->failed_pc=0x0c089142u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c089144: /* original 6ef6, guest PC 0x0c089144 */
if(!s->budget--) { s->failed_pc=0x0c089144u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089146u,s,ram);
P_0c089174: /* original 7f0c, guest PC 0x0c089174 */
if(!s->budget--) { s->failed_pc=0x0c089174u; return 0; }
r[15]+=0x0000000cu;
goto P_0c089176;
P_0c089176: /* original 4f26, guest PC 0x0c089176 */
if(!s->budget--) { s->failed_pc=0x0c089176u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089178;
P_0c089178: /* original fcf9, guest PC 0x0c089178 */
if(!s->budget--) { s->failed_pc=0x0c089178u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08917a;
P_0c08917a: /* original fdf9, guest PC 0x0c08917a */
if(!s->budget--) { s->failed_pc=0x0c08917au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08917c;
P_0c08917c: /* original fef9, guest PC 0x0c08917c */
if(!s->budget--) { s->failed_pc=0x0c08917cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08917e;
P_0c08917e: /* original fff9, guest PC 0x0c08917e */
if(!s->budget--) { s->failed_pc=0x0c08917eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089180;
P_0c089180: /* original 6df6, guest PC 0x0c089180 */
if(!s->budget--) { s->failed_pc=0x0c089180u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089182;
P_0c089182: /* original 000b, guest PC 0x0c089182 */
if(!s->budget--) { s->failed_pc=0x0c089182u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089184: /* original 6ef6, guest PC 0x0c089184 */
if(!s->budget--) { s->failed_pc=0x0c089184u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089186u,s,ram);
P_0c08927e: /* original 4f22, guest PC 0x0c08927e */
if(!s->budget--) { s->failed_pc=0x0c08927eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089280;
P_0c089280: /* original 7ffc, guest PC 0x0c089280 */
if(!s->budget--) { s->failed_pc=0x0c089280u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c089282;
P_0c089282: /* original 2f42, guest PC 0x0c089282 */
if(!s->budget--) { s->failed_pc=0x0c089282u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c089284;
P_0c089284: /* original d106, guest PC 0x0c089284 */
if(!s->budget--) { s->failed_pc=0x0c089284u; return 0; }
r[1]=read(ram,0x0c0892a0u,4);
goto P_0c089286;
P_0c089286: /* original d305, guest PC 0x0c089286 */
if(!s->budget--) { s->failed_pc=0x0c089286u; return 0; }
r[3]=read(ram,0x0c08929cu,4);
goto P_0c089288;
P_0c089288: /* original 6212, guest PC 0x0c089288 */
if(!s->budget--) { s->failed_pc=0x0c089288u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08928a;
P_0c08928a: /* original 2238, guest PC 0x0c08928a */
if(!s->budget--) { s->failed_pc=0x0c08928au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08928c;
P_0c08928c: /* original 8b52, guest PC 0x0c08928c */
if(!s->budget--) { s->failed_pc=0x0c08928cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089334; }
goto P_0c08928e;
P_0c08928e: /* original 9904, guest PC 0x0c08928e */
if(!s->budget--) { s->failed_pc=0x0c08928eu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08929au,2);
goto P_0c089290;
P_0c089290: /* original eb00, guest PC 0x0c089290 */
if(!s->budget--) { s->failed_pc=0x0c089290u; return 0; }
r[11]=0x00000000u;
goto P_0c089292;
P_0c089292: /* original ea1a, guest PC 0x0c089292 */
if(!s->budget--) { s->failed_pc=0x0c089292u; return 0; }
r[10]=0x0000001au;
goto P_0c089294;
P_0c089294: /* original e802, guest PC 0x0c089294 */
if(!s->budget--) { s->failed_pc=0x0c089294u; return 0; }
r[8]=0x00000002u;
goto P_0c089296;
P_0c089296: /* original a04b, guest PC 0x0c089296 */
if(!s->budget--) { s->failed_pc=0x0c089296u; return 0; }
r[12]=0x00000005u;
goto P_0c089330;
P_0c089298: /* original ec05, guest PC 0x0c089298 */
if(!s->budget--) { s->failed_pc=0x0c089298u; return 0; }
r[12]=0x00000005u;
return vf3_matrix_family(0x0c08929au,s,ram);
P_0c0892b8: /* original 64c3, guest PC 0x0c0892b8 */
if(!s->budget--) { s->failed_pc=0x0c0892b8u; return 0; }
r[4]=r[12];
goto P_0c0892ba;
P_0c0892ba: /* original 74ff, guest PC 0x0c0892ba */
if(!s->budget--) { s->failed_pc=0x0c0892bau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0892bc;
P_0c0892bc: /* original 6e43, guest PC 0x0c0892bc */
if(!s->budget--) { s->failed_pc=0x0c0892bcu; return 0; }
r[14]=r[4];
goto P_0c0892be;
P_0c0892be: /* original 60f2, guest PC 0x0c0892be */
if(!s->budget--) { s->failed_pc=0x0c0892beu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0892c0;
P_0c0892c0: /* original 4e08, guest PC 0x0c0892c0 */
if(!s->budget--) { s->failed_pc=0x0c0892c0u; return 0; }
r[14]<<=2;
goto P_0c0892c2;
P_0c0892c2: /* original 0eee, guest PC 0x0c0892c2 */
if(!s->budget--) { s->failed_pc=0x0c0892c2u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0892c4;
P_0c0892c4: /* original e032, guest PC 0x0c0892c4 */
if(!s->budget--) { s->failed_pc=0x0c0892c4u; return 0; }
r[0]=0x00000032u;
goto P_0c0892c6;
P_0c0892c6: /* original 04ec, guest PC 0x0c0892c6 */
if(!s->budget--) { s->failed_pc=0x0c0892c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0892c8;
P_0c0892c8: /* original 2448, guest PC 0x0c0892c8 */
if(!s->budget--) { s->failed_pc=0x0c0892c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0892ca;
P_0c0892ca: /* original 6d43, guest PC 0x0c0892ca */
if(!s->budget--) { s->failed_pc=0x0c0892cau; return 0; }
r[13]=r[4];
goto P_0c0892cc;
P_0c0892cc: /* original 8f09, guest PC 0x0c0892cc */
if(!s->budget--) { s->failed_pc=0x0c0892ccu; return 0; }
cond=r[17]&1u;
r[13]+=0xffffffffu;
if(!cond) { goto P_0c0892e2; }
goto P_0c0892d0;
P_0c0892ce: /* original 7dff, guest PC 0x0c0892ce */
if(!s->budget--) { s->failed_pc=0x0c0892ceu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0892d0;
P_0c0892d0: /* original d23e, guest PC 0x0c0892d0 */
if(!s->budget--) { s->failed_pc=0x0c0892d0u; return 0; }
r[2]=read(ram,0x0c0893ccu,4);
goto P_0c0892d2;
P_0c0892d2: /* original 420b, guest PC 0x0c0892d2 */
if(!s->budget--) { s->failed_pc=0x0c0892d2u; return 0; }
target=r[2];
r[16]=0x0c0892d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0892d6u) { target=s->pc; goto dispatch; }
goto P_0c0892d6;
P_0c0892d4: /* original 0009, guest PC 0x0c0892d4 */
if(!s->budget--) { s->failed_pc=0x0c0892d4u; return 0; }
goto P_0c0892d6;
P_0c0892d6: /* original ed7f, guest PC 0x0c0892d6 */
if(!s->budget--) { s->failed_pc=0x0c0892d6u; return 0; }
r[13]=0x0000007fu;
goto P_0c0892d8;
P_0c0892d8: /* original 6403, guest PC 0x0c0892d8 */
if(!s->budget--) { s->failed_pc=0x0c0892d8u; return 0; }
r[4]=r[0];
goto P_0c0892da;
P_0c0892da: /* original 2d49, guest PC 0x0c0892da */
if(!s->budget--) { s->failed_pc=0x0c0892dau; return 0; }
r[13]&=r[4];
goto P_0c0892dc;
P_0c0892dc: /* original e030, guest PC 0x0c0892dc */
if(!s->budget--) { s->failed_pc=0x0c0892dcu; return 0; }
r[0]=0x00000030u;
goto P_0c0892de;
P_0c0892de: /* original 2499, guest PC 0x0c0892de */
if(!s->budget--) { s->failed_pc=0x0c0892deu; return 0; }
r[4]&=r[9];
goto P_0c0892e0;
P_0c0892e0: /* original 0e45, guest PC 0x0c0892e0 */
if(!s->budget--) { s->failed_pc=0x0c0892e0u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0892e2;
P_0c0892e2: /* original e032, guest PC 0x0c0892e2 */
if(!s->budget--) { s->failed_pc=0x0c0892e2u; return 0; }
r[0]=0x00000032u;
goto P_0c0892e4;
P_0c0892e4: /* original e330, guest PC 0x0c0892e4 */
if(!s->budget--) { s->failed_pc=0x0c0892e4u; return 0; }
r[3]=0x00000030u;
goto P_0c0892e6;
P_0c0892e6: /* original 0ed4, guest PC 0x0c0892e6 */
if(!s->budget--) { s->failed_pc=0x0c0892e6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0892e8;
P_0c0892e8: /* original 33ec, guest PC 0x0c0892e8 */
if(!s->budget--) { s->failed_pc=0x0c0892e8u; return 0; }
r[3]+=r[14];
goto P_0c0892ea;
P_0c0892ea: /* original e02e, guest PC 0x0c0892ea */
if(!s->budget--) { s->failed_pc=0x0c0892eau; return 0; }
r[0]=0x0000002eu;
goto P_0c0892ec;
P_0c0892ec: /* original 6331, guest PC 0x0c0892ec */
if(!s->budget--) { s->failed_pc=0x0c0892ecu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0892ee;
P_0c0892ee: /* original 02ed, guest PC 0x0c0892ee */
if(!s->budget--) { s->failed_pc=0x0c0892eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0892f0;
P_0c0892f0: /* original 323c, guest PC 0x0c0892f0 */
if(!s->budget--) { s->failed_pc=0x0c0892f0u; return 0; }
r[2]+=r[3];
goto P_0c0892f2;
P_0c0892f2: /* original 0e25, guest PC 0x0c0892f2 */
if(!s->budget--) { s->failed_pc=0x0c0892f2u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0892f4;
P_0c0892f4: /* original bdfc, guest PC 0x0c0892f4 */
if(!s->budget--) { s->failed_pc=0x0c0892f4u; return 0; }
target=0x0c088ef0u; r[16]=0x0c0892f8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0892f8u) { target=s->pc; goto dispatch; }
goto P_0c0892f8;
P_0c0892f6: /* original 64e3, guest PC 0x0c0892f6 */
if(!s->budget--) { s->failed_pc=0x0c0892f6u; return 0; }
r[4]=r[14];
goto P_0c0892f8;
P_0c0892f8: /* original 3c87, guest PC 0x0c0892f8 */
if(!s->budget--) { s->failed_pc=0x0c0892f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[8])!=0);
goto P_0c0892fa;
P_0c0892fa: /* original 8b08, guest PC 0x0c0892fa */
if(!s->budget--) { s->failed_pc=0x0c0892fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08930e; }
goto P_0c0892fc;
P_0c0892fc: /* original 85e5, guest PC 0x0c0892fc */
if(!s->budget--) { s->failed_pc=0x0c0892fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c0892fe;
P_0c0892fe: /* original 6d03, guest PC 0x0c0892fe */
if(!s->budget--) { s->failed_pc=0x0c0892feu; return 0; }
r[13]=r[0];
goto P_0c089300;
P_0c089300: /* original 7d01, guest PC 0x0c089300 */
if(!s->budget--) { s->failed_pc=0x0c089300u; return 0; }
r[13]+=0x00000001u;
goto P_0c089302;
P_0c089302: /* original 3da3, guest PC 0x0c089302 */
if(!s->budget--) { s->failed_pc=0x0c089302u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[10])!=0);
goto P_0c089304;
P_0c089304: /* original 8b03, guest PC 0x0c089304 */
if(!s->budget--) { s->failed_pc=0x0c089304u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08930e; }
goto P_0c089306;
P_0c089306: /* original 65c3, guest PC 0x0c089306 */
if(!s->budget--) { s->failed_pc=0x0c089306u; return 0; }
r[5]=r[12];
goto P_0c089308;
P_0c089308: /* original be6a, guest PC 0x0c089308 */
if(!s->budget--) { s->failed_pc=0x0c089308u; return 0; }
target=0x0c088fe0u; r[16]=0x0c08930cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08930cu) { target=s->pc; goto dispatch; }
goto P_0c08930c;
P_0c08930a: /* original 64e3, guest PC 0x0c08930a */
if(!s->budget--) { s->failed_pc=0x0c08930au; return 0; }
r[4]=r[14];
goto P_0c08930c;
P_0c08930c: /* original 6db3, guest PC 0x0c08930c */
if(!s->budget--) { s->failed_pc=0x0c08930cu; return 0; }
r[13]=r[11];
goto P_0c08930e;
P_0c08930e: /* original 60d3, guest PC 0x0c08930e */
if(!s->budget--) { s->failed_pc=0x0c08930eu; return 0; }
r[0]=r[13];
goto P_0c089310;
P_0c089310: /* original 81e5, guest PC 0x0c089310 */
if(!s->budget--) { s->failed_pc=0x0c089310u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c089312;
P_0c089312: /* original 85e4, guest PC 0x0c089312 */
if(!s->budget--) { s->failed_pc=0x0c089312u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c089314;
P_0c089314: /* original 6403, guest PC 0x0c089314 */
if(!s->budget--) { s->failed_pc=0x0c089314u; return 0; }
r[4]=r[0];
goto P_0c089316;
P_0c089316: /* original e02c, guest PC 0x0c089316 */
if(!s->budget--) { s->failed_pc=0x0c089316u; return 0; }
r[0]=0x0000002cu;
goto P_0c089318;
P_0c089318: /* original 05ec, guest PC 0x0c089318 */
if(!s->budget--) { s->failed_pc=0x0c089318u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08931a;
P_0c08931a: /* original 3453, guest PC 0x0c08931a */
if(!s->budget--) { s->failed_pc=0x0c08931au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c08931c;
P_0c08931c: /* original 8b04, guest PC 0x0c08931c */
if(!s->budget--) { s->failed_pc=0x0c08931cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089328; }
goto P_0c08931e;
P_0c08931e: /* original 65c3, guest PC 0x0c08931e */
if(!s->budget--) { s->failed_pc=0x0c08931eu; return 0; }
r[5]=r[12];
goto P_0c089320;
P_0c089320: /* original beb2, guest PC 0x0c089320 */
if(!s->budget--) { s->failed_pc=0x0c089320u; return 0; }
target=0x0c089088u; r[16]=0x0c089324u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089324u) { target=s->pc; goto dispatch; }
goto P_0c089324;
P_0c089322: /* original 64e3, guest PC 0x0c089322 */
if(!s->budget--) { s->failed_pc=0x0c089322u; return 0; }
r[4]=r[14];
goto P_0c089324;
P_0c089324: /* original a001, guest PC 0x0c089324 */
if(!s->budget--) { s->failed_pc=0x0c089324u; return 0; }
r[4]=r[11];
goto P_0c08932a;
P_0c089326: /* original 64b3, guest PC 0x0c089326 */
if(!s->budget--) { s->failed_pc=0x0c089326u; return 0; }
r[4]=r[11];
goto P_0c089328;
P_0c089328: /* original 7401, guest PC 0x0c089328 */
if(!s->budget--) { s->failed_pc=0x0c089328u; return 0; }
r[4]+=0x00000001u;
goto P_0c08932a;
P_0c08932a: /* original 6043, guest PC 0x0c08932a */
if(!s->budget--) { s->failed_pc=0x0c08932au; return 0; }
r[0]=r[4];
goto P_0c08932c;
P_0c08932c: /* original 7cff, guest PC 0x0c08932c */
if(!s->budget--) { s->failed_pc=0x0c08932cu; return 0; }
r[12]+=0xffffffffu;
goto P_0c08932e;
P_0c08932e: /* original 81e4, guest PC 0x0c08932e */
if(!s->budget--) { s->failed_pc=0x0c08932eu; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c089330;
P_0c089330: /* original 2cc8, guest PC 0x0c089330 */
if(!s->budget--) { s->failed_pc=0x0c089330u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c089332;
P_0c089332: /* original 8bc1, guest PC 0x0c089332 */
if(!s->budget--) { s->failed_pc=0x0c089332u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0892b8; }
goto P_0c089334;
P_0c089334: /* original 7f04, guest PC 0x0c089334 */
if(!s->budget--) { s->failed_pc=0x0c089334u; return 0; }
r[15]+=0x00000004u;
goto P_0c089336;
P_0c089336: /* original 4f26, guest PC 0x0c089336 */
if(!s->budget--) { s->failed_pc=0x0c089336u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089338;
P_0c089338: /* original 68f6, guest PC 0x0c089338 */
if(!s->budget--) { s->failed_pc=0x0c089338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08933a;
P_0c08933a: /* original 69f6, guest PC 0x0c08933a */
if(!s->budget--) { s->failed_pc=0x0c08933au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08933c;
P_0c08933c: /* original 6af6, guest PC 0x0c08933c */
if(!s->budget--) { s->failed_pc=0x0c08933cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08933e;
P_0c08933e: /* original 6bf6, guest PC 0x0c08933e */
if(!s->budget--) { s->failed_pc=0x0c08933eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089340;
P_0c089340: /* original 6cf6, guest PC 0x0c089340 */
if(!s->budget--) { s->failed_pc=0x0c089340u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089342;
P_0c089342: /* original 6df6, guest PC 0x0c089342 */
if(!s->budget--) { s->failed_pc=0x0c089342u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089344;
P_0c089344: /* original 000b, guest PC 0x0c089344 */
if(!s->budget--) { s->failed_pc=0x0c089344u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089346: /* original 6ef6, guest PC 0x0c089346 */
if(!s->budget--) { s->failed_pc=0x0c089346u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089348u,s,ram);
P_0c089b50: /* original e031, guest PC 0x0c089b50 */
if(!s->budget--) { s->failed_pc=0x0c089b50u; return 0; }
r[0]=0x00000031u;
goto P_0c089b52;
P_0c089b52: /* original 61f2, guest PC 0x0c089b52 */
if(!s->budget--) { s->failed_pc=0x0c089b52u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c089b54;
P_0c089b54: /* original e300, guest PC 0x0c089b54 */
if(!s->budget--) { s->failed_pc=0x0c089b54u; return 0; }
r[3]=0x00000000u;
goto P_0c089b56;
P_0c089b56: /* original 0434, guest PC 0x0c089b56 */
if(!s->budget--) { s->failed_pc=0x0c089b56u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c089b58;
P_0c089b58: /* original c72c, guest PC 0x0c089b58 */
if(!s->budget--) { s->failed_pc=0x0c089b58u; return 0; }
r[0]=0x0c089c0cu;
goto P_0c089b5a;
P_0c089b5a: /* original f408, guest PC 0x0c089b5a */
if(!s->budget--) { s->failed_pc=0x0c089b5au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c089b5c;
P_0c089b5c: /* original c72c, guest PC 0x0c089b5c */
if(!s->budget--) { s->failed_pc=0x0c089b5cu; return 0; }
r[0]=0x0c089c10u;
goto P_0c089b5e;
P_0c089b5e: /* original f208, guest PC 0x0c089b5e */
if(!s->budget--) { s->failed_pc=0x0c089b5eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c089b60;
P_0c089b60: /* original f368, guest PC 0x0c089b60 */
if(!s->budget--) { s->failed_pc=0x0c089b60u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c089b62;
P_0c089b62: /* original f235, guest PC 0x0c089b62 */
if(!s->budget--) { s->failed_pc=0x0c089b62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c089b64;
P_0c089b64: /* original 8902, guest PC 0x0c089b64 */
if(!s->budget--) { s->failed_pc=0x0c089b64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089b6c; }
goto P_0c089b66;
P_0c089b66: /* original f368, guest PC 0x0c089b66 */
if(!s->budget--) { s->failed_pc=0x0c089b66u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c089b68;
P_0c089b68: /* original a006, guest PC 0x0c089b68 */
if(!s->budget--) { s->failed_pc=0x0c089b68u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c089b78;
P_0c089b6a: /* original f341, guest PC 0x0c089b6a */
if(!s->budget--) { s->failed_pc=0x0c089b6au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c089b6c;
P_0c089b6c: /* original c729, guest PC 0x0c089b6c */
if(!s->budget--) { s->failed_pc=0x0c089b6cu; return 0; }
r[0]=0x0c089c14u;
goto P_0c089b6e;
P_0c089b6e: /* original f108, guest PC 0x0c089b6e */
if(!s->budget--) { s->failed_pc=0x0c089b6eu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c089b70;
P_0c089b70: /* original f315, guest PC 0x0c089b70 */
if(!s->budget--) { s->failed_pc=0x0c089b70u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c089b72;
P_0c089b72: /* original 8905, guest PC 0x0c089b72 */
if(!s->budget--) { s->failed_pc=0x0c089b72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089b80; }
goto P_0c089b74;
P_0c089b74: /* original f368, guest PC 0x0c089b74 */
if(!s->budget--) { s->failed_pc=0x0c089b74u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c089b76;
P_0c089b76: /* original f340, guest PC 0x0c089b76 */
if(!s->budget--) { s->failed_pc=0x0c089b76u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c089b78;
P_0c089b78: /* original e031, guest PC 0x0c089b78 */
if(!s->budget--) { s->failed_pc=0x0c089b78u; return 0; }
r[0]=0x00000031u;
goto P_0c089b7a;
P_0c089b7a: /* original f63a, guest PC 0x0c089b7a */
if(!s->budget--) { s->failed_pc=0x0c089b7au; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c089b7c;
P_0c089b7c: /* original e303, guest PC 0x0c089b7c */
if(!s->budget--) { s->failed_pc=0x0c089b7cu; return 0; }
r[3]=0x00000003u;
goto P_0c089b7e;
P_0c089b7e: /* original 0434, guest PC 0x0c089b7e */
if(!s->budget--) { s->failed_pc=0x0c089b7eu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c089b80;
P_0c089b80: /* original f318, guest PC 0x0c089b80 */
if(!s->budget--) { s->failed_pc=0x0c089b80u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c089b82;
P_0c089b82: /* original f28d, guest PC 0x0c089b82 */
if(!s->budget--) { s->failed_pc=0x0c089b82u; return 0; }
fr[2]=0;
goto P_0c089b84;
P_0c089b84: /* original f235, guest PC 0x0c089b84 */
if(!s->budget--) { s->failed_pc=0x0c089b84u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c089b86;
P_0c089b86: /* original 8902, guest PC 0x0c089b86 */
if(!s->budget--) { s->failed_pc=0x0c089b86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089b8e; }
goto P_0c089b88;
P_0c089b88: /* original f318, guest PC 0x0c089b88 */
if(!s->budget--) { s->failed_pc=0x0c089b88u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c089b8a;
P_0c089b8a: /* original a006, guest PC 0x0c089b8a */
if(!s->budget--) { s->failed_pc=0x0c089b8au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c089b9a;
P_0c089b8c: /* original f341, guest PC 0x0c089b8c */
if(!s->budget--) { s->failed_pc=0x0c089b8cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c089b8e;
P_0c089b8e: /* original c722, guest PC 0x0c089b8e */
if(!s->budget--) { s->failed_pc=0x0c089b8eu; return 0; }
r[0]=0x0c089c18u;
goto P_0c089b90;
P_0c089b90: /* original f108, guest PC 0x0c089b90 */
if(!s->budget--) { s->failed_pc=0x0c089b90u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c089b92;
P_0c089b92: /* original f315, guest PC 0x0c089b92 */
if(!s->budget--) { s->failed_pc=0x0c089b92u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c089b94;
P_0c089b94: /* original 8905, guest PC 0x0c089b94 */
if(!s->budget--) { s->failed_pc=0x0c089b94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089ba2; }
goto P_0c089b96;
P_0c089b96: /* original f318, guest PC 0x0c089b96 */
if(!s->budget--) { s->failed_pc=0x0c089b96u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c089b98;
P_0c089b98: /* original f340, guest PC 0x0c089b98 */
if(!s->budget--) { s->failed_pc=0x0c089b98u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c089b9a;
P_0c089b9a: /* original e031, guest PC 0x0c089b9a */
if(!s->budget--) { s->failed_pc=0x0c089b9au; return 0; }
r[0]=0x00000031u;
goto P_0c089b9c;
P_0c089b9c: /* original f13a, guest PC 0x0c089b9c */
if(!s->budget--) { s->failed_pc=0x0c089b9cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c089b9e;
P_0c089b9e: /* original e303, guest PC 0x0c089b9e */
if(!s->budget--) { s->failed_pc=0x0c089b9eu; return 0; }
r[3]=0x00000003u;
goto P_0c089ba0;
P_0c089ba0: /* original 0434, guest PC 0x0c089ba0 */
if(!s->budget--) { s->failed_pc=0x0c089ba0u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c089ba2;
P_0c089ba2: /* original c71e, guest PC 0x0c089ba2 */
if(!s->budget--) { s->failed_pc=0x0c089ba2u; return 0; }
r[0]=0x0c089c1cu;
goto P_0c089ba4;
P_0c089ba4: /* original f378, guest PC 0x0c089ba4 */
if(!s->budget--) { s->failed_pc=0x0c089ba4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c089ba6;
P_0c089ba6: /* original f408, guest PC 0x0c089ba6 */
if(!s->budget--) { s->failed_pc=0x0c089ba6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c089ba8;
P_0c089ba8: /* original c71d, guest PC 0x0c089ba8 */
if(!s->budget--) { s->failed_pc=0x0c089ba8u; return 0; }
r[0]=0x0c089c20u;
goto P_0c089baa;
P_0c089baa: /* original f208, guest PC 0x0c089baa */
if(!s->budget--) { s->failed_pc=0x0c089baau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c089bac;
P_0c089bac: /* original f235, guest PC 0x0c089bac */
if(!s->budget--) { s->failed_pc=0x0c089bacu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c089bae;
P_0c089bae: /* original 890b, guest PC 0x0c089bae */
if(!s->budget--) { s->failed_pc=0x0c089baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089bc8; }
goto P_0c089bb0;
P_0c089bb0: /* original c71c, guest PC 0x0c089bb0 */
if(!s->budget--) { s->failed_pc=0x0c089bb0u; return 0; }
r[0]=0x0c089c24u;
goto P_0c089bb2;
P_0c089bb2: /* original f158, guest PC 0x0c089bb2 */
if(!s->budget--) { s->failed_pc=0x0c089bb2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
goto P_0c089bb4;
P_0c089bb4: /* original f308, guest PC 0x0c089bb4 */
if(!s->budget--) { s->failed_pc=0x0c089bb4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089bb6;
P_0c089bb6: /* original c71c, guest PC 0x0c089bb6 */
if(!s->budget--) { s->failed_pc=0x0c089bb6u; return 0; }
r[0]=0x0c089c28u;
goto P_0c089bb8;
P_0c089bb8: /* original f131, guest PC 0x0c089bb8 */
if(!s->budget--) { s->failed_pc=0x0c089bb8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c089bba;
P_0c089bba: /* original f51a, guest PC 0x0c089bba */
if(!s->budget--) { s->failed_pc=0x0c089bbau; return 0; }
vf3_matrix_store(s,ram,1,r[5]);
goto P_0c089bbc;
P_0c089bbc: /* original f058, guest PC 0x0c089bbc */
if(!s->budget--) { s->failed_pc=0x0c089bbcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
goto P_0c089bbe;
P_0c089bbe: /* original f108, guest PC 0x0c089bbe */
if(!s->budget--) { s->failed_pc=0x0c089bbeu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c089bc0;
P_0c089bc0: /* original f105, guest PC 0x0c089bc0 */
if(!s->budget--) { s->failed_pc=0x0c089bc0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[0]))!=0);
goto P_0c089bc2;
P_0c089bc2: /* original 8b0d, guest PC 0x0c089bc2 */
if(!s->budget--) { s->failed_pc=0x0c089bc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089be0; }
goto P_0c089bc4;
P_0c089bc4: /* original a00f, guest PC 0x0c089bc4 */
if(!s->budget--) { s->failed_pc=0x0c089bc4u; return 0; }
goto P_0c089be6;
P_0c089bc6: /* original 0009, guest PC 0x0c089bc6 */
if(!s->budget--) { s->failed_pc=0x0c089bc6u; return 0; }
goto P_0c089bc8;
P_0c089bc8: /* original f345, guest PC 0x0c089bc8 */
if(!s->budget--) { s->failed_pc=0x0c089bc8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c089bca;
P_0c089bca: /* original 890c, guest PC 0x0c089bca */
if(!s->budget--) { s->failed_pc=0x0c089bcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089be6; }
goto P_0c089bcc;
P_0c089bcc: /* original c717, guest PC 0x0c089bcc */
if(!s->budget--) { s->failed_pc=0x0c089bccu; return 0; }
r[0]=0x0c089c2cu;
goto P_0c089bce;
P_0c089bce: /* original f158, guest PC 0x0c089bce */
if(!s->budget--) { s->failed_pc=0x0c089bceu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
goto P_0c089bd0;
P_0c089bd0: /* original f308, guest PC 0x0c089bd0 */
if(!s->budget--) { s->failed_pc=0x0c089bd0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089bd2;
P_0c089bd2: /* original c717, guest PC 0x0c089bd2 */
if(!s->budget--) { s->failed_pc=0x0c089bd2u; return 0; }
r[0]=0x0c089c30u;
goto P_0c089bd4;
P_0c089bd4: /* original f130, guest PC 0x0c089bd4 */
if(!s->budget--) { s->failed_pc=0x0c089bd4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c089bd6;
P_0c089bd6: /* original f51a, guest PC 0x0c089bd6 */
if(!s->budget--) { s->failed_pc=0x0c089bd6u; return 0; }
vf3_matrix_store(s,ram,1,r[5]);
goto P_0c089bd8;
P_0c089bd8: /* original f058, guest PC 0x0c089bd8 */
if(!s->budget--) { s->failed_pc=0x0c089bd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
goto P_0c089bda;
P_0c089bda: /* original f108, guest PC 0x0c089bda */
if(!s->budget--) { s->failed_pc=0x0c089bdau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c089bdc;
P_0c089bdc: /* original f015, guest PC 0x0c089bdc */
if(!s->budget--) { s->failed_pc=0x0c089bdcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[1]))!=0);
goto P_0c089bde;
P_0c089bde: /* original 8902, guest PC 0x0c089bde */
if(!s->budget--) { s->failed_pc=0x0c089bdeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089be6; }
goto P_0c089be0;
P_0c089be0: /* original f358, guest PC 0x0c089be0 */
if(!s->budget--) { s->failed_pc=0x0c089be0u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c089be2;
P_0c089be2: /* original e01c, guest PC 0x0c089be2 */
if(!s->budget--) { s->failed_pc=0x0c089be2u; return 0; }
r[0]=0x0000001cu;
goto P_0c089be4;
P_0c089be4: /* original f437, guest PC 0x0c089be4 */
if(!s->budget--) { s->failed_pc=0x0c089be4u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c089be6;
P_0c089be6: /* original 000b, guest PC 0x0c089be6 */
if(!s->budget--) { s->failed_pc=0x0c089be6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c089be8: /* original 0009, guest PC 0x0c089be8 */
if(!s->budget--) { s->failed_pc=0x0c089be8u; return 0; }
goto P_0c089bea;
P_0c089bea: /* original f38d, guest PC 0x0c089bea */
if(!s->budget--) { s->failed_pc=0x0c089beau; return 0; }
fr[3]=0;
goto P_0c089bec;
P_0c089bec: /* original f345, guest PC 0x0c089bec */
if(!s->budget--) { s->failed_pc=0x0c089becu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c089bee;
P_0c089bee: /* original d711, guest PC 0x0c089bee */
if(!s->budget--) { s->failed_pc=0x0c089beeu; return 0; }
r[7]=read(ram,0x0c089c34u,4);
goto P_0c089bf0;
P_0c089bf0: /* original 7ff8, guest PC 0x0c089bf0 */
if(!s->budget--) { s->failed_pc=0x0c089bf0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c089bf2;
P_0c089bf2: /* original e034, guest PC 0x0c089bf2 */
if(!s->budget--) { s->failed_pc=0x0c089bf2u; return 0; }
r[0]=0x00000034u;
goto P_0c089bf4;
P_0c089bf4: /* original 8d20, guest PC 0x0c089bf4 */
if(!s->budget--) { s->failed_pc=0x0c089bf4u; return 0; }
cond=r[17]&1u;
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(cond) { goto P_0c089c38; }
goto P_0c089bf8;
P_0c089bf6: /* original 064d, guest PC 0x0c089bf6 */
if(!s->budget--) { s->failed_pc=0x0c089bf6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c089bf8;
P_0c089bf8: /* original 9205, guest PC 0x0c089bf8 */
if(!s->budget--) { s->failed_pc=0x0c089bf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089c06u,2);
goto P_0c089bfa;
P_0c089bfa: /* original 9305, guest PC 0x0c089bfa */
if(!s->budget--) { s->failed_pc=0x0c089bfau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089c08u,2);
goto P_0c089bfc;
P_0c089bfc: /* original 362c, guest PC 0x0c089bfc */
if(!s->budget--) { s->failed_pc=0x0c089bfcu; return 0; }
r[6]+=r[2];
goto P_0c089bfe;
P_0c089bfe: /* original 3633, guest PC 0x0c089bfe */
if(!s->budget--) { s->failed_pc=0x0c089bfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c089c00;
P_0c089c00: /* original 8923, guest PC 0x0c089c00 */
if(!s->budget--) { s->failed_pc=0x0c089c00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089c4a; }
goto P_0c089c02;
P_0c089c02: /* original a024, guest PC 0x0c089c02 */
if(!s->budget--) { s->failed_pc=0x0c089c02u; return 0; }
goto P_0c089c4e;
P_0c089c04: /* original 0009, guest PC 0x0c089c04 */
if(!s->budget--) { s->failed_pc=0x0c089c04u; return 0; }
return vf3_matrix_family(0x0c089c06u,s,ram);
P_0c089c38: /* original 9176, guest PC 0x0c089c38 */
if(!s->budget--) { s->failed_pc=0x0c089c38u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089d28u,2);
goto P_0c089c3a;
P_0c089c3a: /* original 6373, guest PC 0x0c089c3a */
if(!s->budget--) { s->failed_pc=0x0c089c3au; return 0; }
r[3]=r[7];
goto P_0c089c3c;
P_0c089c3c: /* original 3618, guest PC 0x0c089c3c */
if(!s->budget--) { s->failed_pc=0x0c089c3cu; return 0; }
r[6]-=r[1];
goto P_0c089c3e;
P_0c089c3e: /* original 2369, guest PC 0x0c089c3e */
if(!s->budget--) { s->failed_pc=0x0c089c3eu; return 0; }
r[3]&=r[6];
goto P_0c089c40;
P_0c089c40: /* original 2f32, guest PC 0x0c089c40 */
if(!s->budget--) { s->failed_pc=0x0c089c40u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c089c42;
P_0c089c42: /* original d23a, guest PC 0x0c089c42 */
if(!s->budget--) { s->failed_pc=0x0c089c42u; return 0; }
r[2]=read(ram,0x0c089d2cu,4);
goto P_0c089c44;
P_0c089c44: /* original 3320, guest PC 0x0c089c44 */
if(!s->budget--) { s->failed_pc=0x0c089c44u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c089c46;
P_0c089c46: /* original 1f21, guest PC 0x0c089c46 */
if(!s->budget--) { s->failed_pc=0x0c089c46u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c089c48;
P_0c089c48: /* original 8901, guest PC 0x0c089c48 */
if(!s->budget--) { s->failed_pc=0x0c089c48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089c4e; }
goto P_0c089c4a;
P_0c089c4a: /* original e034, guest PC 0x0c089c4a */
if(!s->budget--) { s->failed_pc=0x0c089c4au; return 0; }
r[0]=0x00000034u;
goto P_0c089c4c;
P_0c089c4c: /* original 0465, guest PC 0x0c089c4c */
if(!s->budget--) { s->failed_pc=0x0c089c4cu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c089c4e;
P_0c089c4e: /* original 2558, guest PC 0x0c089c4e */
if(!s->budget--) { s->failed_pc=0x0c089c4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c089c50;
P_0c089c50: /* original e036, guest PC 0x0c089c50 */
if(!s->budget--) { s->failed_pc=0x0c089c50u; return 0; }
r[0]=0x00000036u;
goto P_0c089c52;
P_0c089c52: /* original 8d06, guest PC 0x0c089c52 */
if(!s->budget--) { s->failed_pc=0x0c089c52u; return 0; }
cond=r[17]&1u;
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(cond) { goto P_0c089c62; }
goto P_0c089c56;
P_0c089c54: /* original 064d, guest PC 0x0c089c54 */
if(!s->budget--) { s->failed_pc=0x0c089c54u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c089c56;
P_0c089c56: /* original 6053, guest PC 0x0c089c56 */
if(!s->budget--) { s->failed_pc=0x0c089c56u; return 0; }
r[0]=r[5];
goto P_0c089c58;
P_0c089c58: /* original 8802, guest PC 0x0c089c58 */
if(!s->budget--) { s->failed_pc=0x0c089c58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c089c5a;
P_0c089c5a: /* original 8902, guest PC 0x0c089c5a */
if(!s->budget--) { s->failed_pc=0x0c089c5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089c62; }
goto P_0c089c5c;
P_0c089c5c: /* original 6053, guest PC 0x0c089c5c */
if(!s->budget--) { s->failed_pc=0x0c089c5cu; return 0; }
r[0]=r[5];
goto P_0c089c5e;
P_0c089c5e: /* original 8804, guest PC 0x0c089c5e */
if(!s->budget--) { s->failed_pc=0x0c089c5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c089c60;
P_0c089c60: /* original 8b09, guest PC 0x0c089c60 */
if(!s->budget--) { s->failed_pc=0x0c089c60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089c76; }
goto P_0c089c62;
P_0c089c62: /* original d233, guest PC 0x0c089c62 */
if(!s->budget--) { s->failed_pc=0x0c089c62u; return 0; }
r[2]=read(ram,0x0c089d30u,4);
goto P_0c089c64;
P_0c089c64: /* original 76e0, guest PC 0x0c089c64 */
if(!s->budget--) { s->failed_pc=0x0c089c64u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c089c66;
P_0c089c66: /* original 6573, guest PC 0x0c089c66 */
if(!s->budget--) { s->failed_pc=0x0c089c66u; return 0; }
r[5]=r[7];
goto P_0c089c68;
P_0c089c68: /* original 2569, guest PC 0x0c089c68 */
if(!s->budget--) { s->failed_pc=0x0c089c68u; return 0; }
r[5]&=r[6];
goto P_0c089c6a;
P_0c089c6a: /* original 6323, guest PC 0x0c089c6a */
if(!s->budget--) { s->failed_pc=0x0c089c6au; return 0; }
r[3]=r[2];
goto P_0c089c6c;
P_0c089c6c: /* original 3530, guest PC 0x0c089c6c */
if(!s->budget--) { s->failed_pc=0x0c089c6cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c089c6e;
P_0c089c6e: /* original 2f22, guest PC 0x0c089c6e */
if(!s->budget--) { s->failed_pc=0x0c089c6eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c089c70;
P_0c089c70: /* original 8b05, guest PC 0x0c089c70 */
if(!s->budget--) { s->failed_pc=0x0c089c70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089c7e; }
goto P_0c089c72;
P_0c089c72: /* original a006, guest PC 0x0c089c72 */
if(!s->budget--) { s->failed_pc=0x0c089c72u; return 0; }
goto P_0c089c82;
P_0c089c74: /* original 0009, guest PC 0x0c089c74 */
if(!s->budget--) { s->failed_pc=0x0c089c74u; return 0; }
goto P_0c089c76;
P_0c089c76: /* original 9358, guest PC 0x0c089c76 */
if(!s->budget--) { s->failed_pc=0x0c089c76u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089d2au,2);
goto P_0c089c78;
P_0c089c78: /* original 7620, guest PC 0x0c089c78 */
if(!s->budget--) { s->failed_pc=0x0c089c78u; return 0; }
r[6]+=0x00000020u;
goto P_0c089c7a;
P_0c089c7a: /* original 3633, guest PC 0x0c089c7a */
if(!s->budget--) { s->failed_pc=0x0c089c7au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c089c7c;
P_0c089c7c: /* original 8b01, guest PC 0x0c089c7c */
if(!s->budget--) { s->failed_pc=0x0c089c7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089c82; }
goto P_0c089c7e;
P_0c089c7e: /* original e036, guest PC 0x0c089c7e */
if(!s->budget--) { s->failed_pc=0x0c089c7eu; return 0; }
r[0]=0x00000036u;
goto P_0c089c80;
P_0c089c80: /* original 0465, guest PC 0x0c089c80 */
if(!s->budget--) { s->failed_pc=0x0c089c80u; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c089c82;
P_0c089c82: /* original 000b, guest PC 0x0c089c82 */
if(!s->budget--) { s->failed_pc=0x0c089c82u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c089c84: /* original 7f08, guest PC 0x0c089c84 */
if(!s->budget--) { s->failed_pc=0x0c089c84u; return 0; }
r[15]+=0x00000008u;
goto P_0c089c86;
P_0c089c86: /* original 2fe6, guest PC 0x0c089c86 */
if(!s->budget--) { s->failed_pc=0x0c089c86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c88;
P_0c089c88: /* original e301, guest PC 0x0c089c88 */
if(!s->budget--) { s->failed_pc=0x0c089c88u; return 0; }
r[3]=0x00000001u;
goto P_0c089c8a;
P_0c089c8a: /* original 2fd6, guest PC 0x0c089c8a */
if(!s->budget--) { s->failed_pc=0x0c089c8au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c8c;
P_0c089c8c: /* original e02c, guest PC 0x0c089c8c */
if(!s->budget--) { s->failed_pc=0x0c089c8cu; return 0; }
r[0]=0x0000002cu;
goto P_0c089c8e;
P_0c089c8e: /* original 2fc6, guest PC 0x0c089c8e */
if(!s->budget--) { s->failed_pc=0x0c089c8eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c90;
P_0c089c90: /* original 6d43, guest PC 0x0c089c90 */
if(!s->budget--) { s->failed_pc=0x0c089c90u; return 0; }
r[13]=r[4];
goto P_0c089c92;
P_0c089c92: /* original 2fb6, guest PC 0x0c089c92 */
if(!s->budget--) { s->failed_pc=0x0c089c92u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c94;
P_0c089c94: /* original 2fa6, guest PC 0x0c089c94 */
if(!s->budget--) { s->failed_pc=0x0c089c94u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c96;
P_0c089c96: /* original 6a53, guest PC 0x0c089c96 */
if(!s->budget--) { s->failed_pc=0x0c089c96u; return 0; }
r[10]=r[5];
goto P_0c089c98;
P_0c089c98: /* original 2f96, guest PC 0x0c089c98 */
if(!s->budget--) { s->failed_pc=0x0c089c98u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089c9a;
P_0c089c9a: /* original 6963, guest PC 0x0c089c9a */
if(!s->budget--) { s->failed_pc=0x0c089c9au; return 0; }
r[9]=r[6];
goto P_0c089c9c;
P_0c089c9c: /* original 4f22, guest PC 0x0c089c9c */
if(!s->budget--) { s->failed_pc=0x0c089c9cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089c9e;
P_0c089c9e: /* original 7ff8, guest PC 0x0c089c9e */
if(!s->budget--) { s->failed_pc=0x0c089c9eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c089ca0;
P_0c089ca0: /* original 5cf9, guest PC 0x0c089ca0 */
if(!s->budget--) { s->failed_pc=0x0c089ca0u; return 0; }
r[12]=read(ram,r[15]+36,4);
goto P_0c089ca2;
P_0c089ca2: /* original 0d35, guest PC 0x0c089ca2 */
if(!s->budget--) { s->failed_pc=0x0c089ca2u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c089ca4;
P_0c089ca4: /* original e031, guest PC 0x0c089ca4 */
if(!s->budget--) { s->failed_pc=0x0c089ca4u; return 0; }
r[0]=0x00000031u;
goto P_0c089ca6;
P_0c089ca6: /* original 0edc, guest PC 0x0c089ca6 */
if(!s->budget--) { s->failed_pc=0x0c089ca6u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c089ca8;
P_0c089ca8: /* original 2ee8, guest PC 0x0c089ca8 */
if(!s->budget--) { s->failed_pc=0x0c089ca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c089caa;
P_0c089caa: /* original 8f05, guest PC 0x0c089caa */
if(!s->budget--) { s->failed_pc=0x0c089caau; return 0; }
cond=r[17]&1u;
r[11]=r[7];
if(!cond) { goto P_0c089cb8; }
goto P_0c089cae;
P_0c089cac: /* original 6b73, guest PC 0x0c089cac */
if(!s->budget--) { s->failed_pc=0x0c089cacu; return 0; }
r[11]=r[7];
goto P_0c089cae;
P_0c089cae: /* original d221, guest PC 0x0c089cae */
if(!s->budget--) { s->failed_pc=0x0c089caeu; return 0; }
r[2]=read(ram,0x0c089d34u,4);
goto P_0c089cb0;
P_0c089cb0: /* original 420b, guest PC 0x0c089cb0 */
if(!s->budget--) { s->failed_pc=0x0c089cb0u; return 0; }
target=r[2];
r[16]=0x0c089cb4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089cb4u) { target=s->pc; goto dispatch; }
goto P_0c089cb4;
P_0c089cb2: /* original 0009, guest PC 0x0c089cb2 */
if(!s->budget--) { s->failed_pc=0x0c089cb2u; return 0; }
goto P_0c089cb4;
P_0c089cb4: /* original ee07, guest PC 0x0c089cb4 */
if(!s->budget--) { s->failed_pc=0x0c089cb4u; return 0; }
r[14]=0x00000007u;
goto P_0c089cb6;
P_0c089cb6: /* original 2e09, guest PC 0x0c089cb6 */
if(!s->budget--) { s->failed_pc=0x0c089cb6u; return 0; }
r[14]&=r[0];
goto P_0c089cb8;
P_0c089cb8: /* original e030, guest PC 0x0c089cb8 */
if(!s->budget--) { s->failed_pc=0x0c089cb8u; return 0; }
r[0]=0x00000030u;
goto P_0c089cba;
P_0c089cba: /* original 0de4, guest PC 0x0c089cba */
if(!s->budget--) { s->failed_pc=0x0c089cbau; return 0; }
write(ram,r[13]+r[0],r[14],1);
goto P_0c089cbc;
P_0c089cbc: /* original e038, guest PC 0x0c089cbc */
if(!s->budget--) { s->failed_pc=0x0c089cbcu; return 0; }
r[0]=0x00000038u;
goto P_0c089cbe;
P_0c089cbe: /* original 03dd, guest PC 0x0c089cbe */
if(!s->budget--) { s->failed_pc=0x0c089cbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c089cc0;
P_0c089cc0: /* original c71d, guest PC 0x0c089cc0 */
if(!s->budget--) { s->failed_pc=0x0c089cc0u; return 0; }
r[0]=0x0c089d38u;
goto P_0c089cc2;
P_0c089cc2: /* original 2c32, guest PC 0x0c089cc2 */
if(!s->budget--) { s->failed_pc=0x0c089cc2u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089cc4;
P_0c089cc4: /* original e301, guest PC 0x0c089cc4 */
if(!s->budget--) { s->failed_pc=0x0c089cc4u; return 0; }
r[3]=0x00000001u;
goto P_0c089cc6;
P_0c089cc6: /* original f48d, guest PC 0x0c089cc6 */
if(!s->budget--) { s->failed_pc=0x0c089cc6u; return 0; }
fr[4]=0;
goto P_0c089cc8;
P_0c089cc8: /* original 23e8, guest PC 0x0c089cc8 */
if(!s->budget--) { s->failed_pc=0x0c089cc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c089cca;
P_0c089cca: /* original fb4a, guest PC 0x0c089cca */
if(!s->budget--) { s->failed_pc=0x0c089ccau; return 0; }
vf3_matrix_store(s,ram,4,r[11]);
goto P_0c089ccc;
P_0c089ccc: /* original f308, guest PC 0x0c089ccc */
if(!s->budget--) { s->failed_pc=0x0c089cccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cce;
P_0c089cce: /* original fa3a, guest PC 0x0c089cce */
if(!s->budget--) { s->failed_pc=0x0c089cceu; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089cd0;
P_0c089cd0: /* original f3b8, guest PC 0x0c089cd0 */
if(!s->budget--) { s->failed_pc=0x0c089cd0u; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
goto P_0c089cd2;
P_0c089cd2: /* original 8d19, guest PC 0x0c089cd2 */
if(!s->budget--) { s->failed_pc=0x0c089cd2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[9]);
if(cond) { goto P_0c089d08; }
goto P_0c089cd6;
P_0c089cd4: /* original f93a, guest PC 0x0c089cd4 */
if(!s->budget--) { s->failed_pc=0x0c089cd4u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c089cd6;
P_0c089cd6: /* original 60e3, guest PC 0x0c089cd6 */
if(!s->budget--) { s->failed_pc=0x0c089cd6u; return 0; }
r[0]=r[14];
goto P_0c089cd8;
P_0c089cd8: /* original 8803, guest PC 0x0c089cd8 */
if(!s->budget--) { s->failed_pc=0x0c089cd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c089cda;
P_0c089cda: /* original 891b, guest PC 0x0c089cda */
if(!s->budget--) { s->failed_pc=0x0c089cdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089d14; }
goto P_0c089cdc;
P_0c089cdc: /* original e028, guest PC 0x0c089cdc */
if(!s->budget--) { s->failed_pc=0x0c089cdcu; return 0; }
r[0]=0x00000028u;
goto P_0c089cde;
P_0c089cde: /* original 6693, guest PC 0x0c089cde */
if(!s->budget--) { s->failed_pc=0x0c089cdeu; return 0; }
r[6]=r[9];
goto P_0c089ce0;
P_0c089ce0: /* original 02dd, guest PC 0x0c089ce0 */
if(!s->budget--) { s->failed_pc=0x0c089ce0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c089ce2;
P_0c089ce2: /* original c716, guest PC 0x0c089ce2 */
if(!s->budget--) { s->failed_pc=0x0c089ce2u; return 0; }
r[0]=0x0c089d3cu;
goto P_0c089ce4;
P_0c089ce4: /* original e300, guest PC 0x0c089ce4 */
if(!s->budget--) { s->failed_pc=0x0c089ce4u; return 0; }
r[3]=0x00000000u;
goto P_0c089ce6;
P_0c089ce6: /* original 65f3, guest PC 0x0c089ce6 */
if(!s->budget--) { s->failed_pc=0x0c089ce6u; return 0; }
r[5]=r[15];
goto P_0c089ce8;
P_0c089ce8: /* original 2c22, guest PC 0x0c089ce8 */
if(!s->budget--) { s->failed_pc=0x0c089ce8u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c089cea;
P_0c089cea: /* original 1f31, guest PC 0x0c089cea */
if(!s->budget--) { s->failed_pc=0x0c089ceau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c089cec;
P_0c089cec: /* original f308, guest PC 0x0c089cec */
if(!s->budget--) { s->failed_pc=0x0c089cecu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cee;
P_0c089cee: /* original c714, guest PC 0x0c089cee */
if(!s->budget--) { s->failed_pc=0x0c089ceeu; return 0; }
r[0]=0x0c089d40u;
goto P_0c089cf0;
P_0c089cf0: /* original f93a, guest PC 0x0c089cf0 */
if(!s->budget--) { s->failed_pc=0x0c089cf0u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c089cf2;
P_0c089cf2: /* original ff4a, guest PC 0x0c089cf2 */
if(!s->budget--) { s->failed_pc=0x0c089cf2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c089cf4;
P_0c089cf4: /* original f308, guest PC 0x0c089cf4 */
if(!s->budget--) { s->failed_pc=0x0c089cf4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cf6;
P_0c089cf6: /* original fa3a, guest PC 0x0c089cf6 */
if(!s->budget--) { s->failed_pc=0x0c089cf6u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089cf8;
P_0c089cf8: /* original d312, guest PC 0x0c089cf8 */
if(!s->budget--) { s->failed_pc=0x0c089cf8u; return 0; }
r[3]=read(ram,0x0c089d44u,4);
goto P_0c089cfa;
P_0c089cfa: /* original 430b, guest PC 0x0c089cfa */
if(!s->budget--) { s->failed_pc=0x0c089cfau; return 0; }
target=r[3];
r[16]=0x0c089cfeu;
tmp=read(ram,r[12],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089cfeu) { target=s->pc; goto dispatch; }
goto P_0c089cfe;
P_0c089cfc: /* original 64c2, guest PC 0x0c089cfc */
if(!s->budget--) { s->failed_pc=0x0c089cfcu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c089cfe;
P_0c089cfe: /* original f3f8, guest PC 0x0c089cfe */
if(!s->budget--) { s->failed_pc=0x0c089cfeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089d00;
P_0c089d00: /* original fb3a, guest PC 0x0c089d00 */
if(!s->budget--) { s->failed_pc=0x0c089d00u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c089d02;
P_0c089d02: /* original 53f1, guest PC 0x0c089d02 */
if(!s->budget--) { s->failed_pc=0x0c089d02u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c089d04;
P_0c089d04: /* original a006, guest PC 0x0c089d04 */
if(!s->budget--) { s->failed_pc=0x0c089d04u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089d14;
P_0c089d06: /* original 2c32, guest PC 0x0c089d06 */
if(!s->budget--) { s->failed_pc=0x0c089d06u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089d08;
P_0c089d08: /* original 60e3, guest PC 0x0c089d08 */
if(!s->budget--) { s->failed_pc=0x0c089d08u; return 0; }
r[0]=r[14];
goto P_0c089d0a;
P_0c089d0a: /* original 8802, guest PC 0x0c089d0a */
if(!s->budget--) { s->failed_pc=0x0c089d0au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c089d0c;
P_0c089d0c: /* original 8b02, guest PC 0x0c089d0c */
if(!s->budget--) { s->failed_pc=0x0c089d0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089d14; }
goto P_0c089d0e;
P_0c089d0e: /* original c70e, guest PC 0x0c089d0e */
if(!s->budget--) { s->failed_pc=0x0c089d0eu; return 0; }
r[0]=0x0c089d48u;
goto P_0c089d10;
P_0c089d10: /* original f308, guest PC 0x0c089d10 */
if(!s->budget--) { s->failed_pc=0x0c089d10u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089d12;
P_0c089d12: /* original fa3a, guest PC 0x0c089d12 */
if(!s->budget--) { s->failed_pc=0x0c089d12u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089d14;
P_0c089d14: /* original 7f08, guest PC 0x0c089d14 */
if(!s->budget--) { s->failed_pc=0x0c089d14u; return 0; }
r[15]+=0x00000008u;
goto P_0c089d16;
P_0c089d16: /* original 60e3, guest PC 0x0c089d16 */
if(!s->budget--) { s->failed_pc=0x0c089d16u; return 0; }
r[0]=r[14];
goto P_0c089d18;
P_0c089d18: /* original 4f26, guest PC 0x0c089d18 */
if(!s->budget--) { s->failed_pc=0x0c089d18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089d1a;
P_0c089d1a: /* original 69f6, guest PC 0x0c089d1a */
if(!s->budget--) { s->failed_pc=0x0c089d1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089d1c;
P_0c089d1c: /* original 6af6, guest PC 0x0c089d1c */
if(!s->budget--) { s->failed_pc=0x0c089d1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089d1e;
P_0c089d1e: /* original 6bf6, guest PC 0x0c089d1e */
if(!s->budget--) { s->failed_pc=0x0c089d1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089d20;
P_0c089d20: /* original 6cf6, guest PC 0x0c089d20 */
if(!s->budget--) { s->failed_pc=0x0c089d20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089d22;
P_0c089d22: /* original 6df6, guest PC 0x0c089d22 */
if(!s->budget--) { s->failed_pc=0x0c089d22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089d24;
P_0c089d24: /* original 000b, guest PC 0x0c089d24 */
if(!s->budget--) { s->failed_pc=0x0c089d24u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089d26: /* original 6ef6, guest PC 0x0c089d26 */
if(!s->budget--) { s->failed_pc=0x0c089d26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089d28u,s,ram);
P_0c089d66: /* original 4f22, guest PC 0x0c089d66 */
if(!s->budget--) { s->failed_pc=0x0c089d66u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089d68;
P_0c089d68: /* original 9b82, guest PC 0x0c089d68 */
if(!s->budget--) { s->failed_pc=0x0c089d68u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089e70u,2);
goto P_0c089d6a;
P_0c089d6a: /* original dc42, guest PC 0x0c089d6a */
if(!s->budget--) { s->failed_pc=0x0c089d6au; return 0; }
r[12]=read(ram,0x0c089e74u,4);
goto P_0c089d6c;
P_0c089d6c: /* original 7fe8, guest PC 0x0c089d6c */
if(!s->budget--) { s->failed_pc=0x0c089d6cu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c089d6e;
P_0c089d6e: /* original e004, guest PC 0x0c089d6e */
if(!s->budget--) { s->failed_pc=0x0c089d6eu; return 0; }
r[0]=0x00000004u;
goto P_0c089d70;
P_0c089d70: /* original ffc8, guest PC 0x0c089d70 */
if(!s->budget--) { s->failed_pc=0x0c089d70u; return 0; }
vf3_matrix_load(s,ram,15,r[12]);
goto P_0c089d72;
P_0c089d72: /* original fec6, guest PC 0x0c089d72 */
if(!s->budget--) { s->failed_pc=0x0c089d72u; return 0; }
vf3_matrix_load(s,ram,14,r[12]+r[0]);
goto P_0c089d74;
P_0c089d74: /* original e008, guest PC 0x0c089d74 */
if(!s->budget--) { s->failed_pc=0x0c089d74u; return 0; }
r[0]=0x00000008u;
goto P_0c089d76;
P_0c089d76: /* original fdc6, guest PC 0x0c089d76 */
if(!s->budget--) { s->failed_pc=0x0c089d76u; return 0; }
vf3_matrix_load(s,ram,13,r[12]+r[0]);
goto P_0c089d78;
P_0c089d78: /* original e00c, guest PC 0x0c089d78 */
if(!s->budget--) { s->failed_pc=0x0c089d78u; return 0; }
r[0]=0x0000000cu;
goto P_0c089d7a;
P_0c089d7a: /* original fcc6, guest PC 0x0c089d7a */
if(!s->budget--) { s->failed_pc=0x0c089d7au; return 0; }
vf3_matrix_load(s,ram,12,r[12]+r[0]);
goto P_0c089d7c;
P_0c089d7c: /* original e010, guest PC 0x0c089d7c */
if(!s->budget--) { s->failed_pc=0x0c089d7cu; return 0; }
r[0]=0x00000010u;
goto P_0c089d7e;
P_0c089d7e: /* original f3c6, guest PC 0x0c089d7e */
if(!s->budget--) { s->failed_pc=0x0c089d7eu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089d80;
P_0c089d80: /* original e014, guest PC 0x0c089d80 */
if(!s->budget--) { s->failed_pc=0x0c089d80u; return 0; }
r[0]=0x00000014u;
goto P_0c089d82;
P_0c089d82: /* original ff37, guest PC 0x0c089d82 */
if(!s->budget--) { s->failed_pc=0x0c089d82u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089d84;
P_0c089d84: /* original e014, guest PC 0x0c089d84 */
if(!s->budget--) { s->failed_pc=0x0c089d84u; return 0; }
r[0]=0x00000014u;
goto P_0c089d86;
P_0c089d86: /* original f3c6, guest PC 0x0c089d86 */
if(!s->budget--) { s->failed_pc=0x0c089d86u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089d88;
P_0c089d88: /* original e010, guest PC 0x0c089d88 */
if(!s->budget--) { s->failed_pc=0x0c089d88u; return 0; }
r[0]=0x00000010u;
goto P_0c089d8a;
P_0c089d8a: /* original ff37, guest PC 0x0c089d8a */
if(!s->budget--) { s->failed_pc=0x0c089d8au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089d8c;
P_0c089d8c: /* original e032, guest PC 0x0c089d8c */
if(!s->budget--) { s->failed_pc=0x0c089d8cu; return 0; }
r[0]=0x00000032u;
goto P_0c089d8e;
P_0c089d8e: /* original 53c6, guest PC 0x0c089d8e */
if(!s->budget--) { s->failed_pc=0x0c089d8eu; return 0; }
r[3]=read(ram,r[12]+24,4);
goto P_0c089d90;
P_0c089d90: /* original 7c1c, guest PC 0x0c089d90 */
if(!s->budget--) { s->failed_pc=0x0c089d90u; return 0; }
r[12]+=0x0000001cu;
goto P_0c089d92;
P_0c089d92: /* original 2f32, guest PC 0x0c089d92 */
if(!s->budget--) { s->failed_pc=0x0c089d92u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c089d94;
P_0c089d94: /* original 63f3, guest PC 0x0c089d94 */
if(!s->budget--) { s->failed_pc=0x0c089d94u; return 0; }
r[3]=r[15];
goto P_0c089d96;
P_0c089d96: /* original 0ed4, guest PC 0x0c089d96 */
if(!s->budget--) { s->failed_pc=0x0c089d96u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c089d98;
P_0c089d98: /* original e028, guest PC 0x0c089d98 */
if(!s->budget--) { s->failed_pc=0x0c089d98u; return 0; }
r[0]=0x00000028u;
goto P_0c089d9a;
P_0c089d9a: /* original 0ed5, guest PC 0x0c089d9a */
if(!s->budget--) { s->failed_pc=0x0c089d9au; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c089d9c;
P_0c089d9c: /* original e034, guest PC 0x0c089d9c */
if(!s->budget--) { s->failed_pc=0x0c089d9cu; return 0; }
r[0]=0x00000034u;
goto P_0c089d9e;
P_0c089d9e: /* original 0ed5, guest PC 0x0c089d9e */
if(!s->budget--) { s->failed_pc=0x0c089d9eu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c089da0;
P_0c089da0: /* original e036, guest PC 0x0c089da0 */
if(!s->budget--) { s->failed_pc=0x0c089da0u; return 0; }
r[0]=0x00000036u;
goto P_0c089da2;
P_0c089da2: /* original 0ed5, guest PC 0x0c089da2 */
if(!s->budget--) { s->failed_pc=0x0c089da2u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c089da4;
P_0c089da4: /* original e031, guest PC 0x0c089da4 */
if(!s->budget--) { s->failed_pc=0x0c089da4u; return 0; }
r[0]=0x00000031u;
goto P_0c089da6;
P_0c089da6: /* original 0ed4, guest PC 0x0c089da6 */
if(!s->budget--) { s->failed_pc=0x0c089da6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c089da8;
P_0c089da8: /* original e038, guest PC 0x0c089da8 */
if(!s->budget--) { s->failed_pc=0x0c089da8u; return 0; }
r[0]=0x00000038u;
goto P_0c089daa;
P_0c089daa: /* original 0eb5, guest PC 0x0c089daa */
if(!s->budget--) { s->failed_pc=0x0c089daau; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c089dac;
P_0c089dac: /* original 2f36, guest PC 0x0c089dac */
if(!s->budget--) { s->failed_pc=0x0c089dacu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089dae;
P_0c089dae: /* original 66f3, guest PC 0x0c089dae */
if(!s->budget--) { s->failed_pc=0x0c089daeu; return 0; }
r[6]=r[15];
goto P_0c089db0;
P_0c089db0: /* original 65f3, guest PC 0x0c089db0 */
if(!s->budget--) { s->failed_pc=0x0c089db0u; return 0; }
r[5]=r[15];
goto P_0c089db2;
P_0c089db2: /* original 67f3, guest PC 0x0c089db2 */
if(!s->budget--) { s->failed_pc=0x0c089db2u; return 0; }
r[7]=r[15];
goto P_0c089db4;
P_0c089db4: /* original 7508, guest PC 0x0c089db4 */
if(!s->budget--) { s->failed_pc=0x0c089db4u; return 0; }
r[5]+=0x00000008u;
goto P_0c089db6;
P_0c089db6: /* original 7710, guest PC 0x0c089db6 */
if(!s->budget--) { s->failed_pc=0x0c089db6u; return 0; }
r[7]+=0x00000010u;
goto P_0c089db8;
P_0c089db8: /* original 760c, guest PC 0x0c089db8 */
if(!s->budget--) { s->failed_pc=0x0c089db8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c089dba;
P_0c089dba: /* original bf64, guest PC 0x0c089dba */
if(!s->budget--) { s->failed_pc=0x0c089dbau; return 0; }
target=0x0c089c86u; r[16]=0x0c089dbeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089dbeu) { target=s->pc; goto dispatch; }
goto P_0c089dbe;
P_0c089dbc: /* original 64e3, guest PC 0x0c089dbc */
if(!s->budget--) { s->failed_pc=0x0c089dbcu; return 0; }
r[4]=r[14];
goto P_0c089dbe;
P_0c089dbe: /* original 7f04, guest PC 0x0c089dbe */
if(!s->budget--) { s->failed_pc=0x0c089dbeu; return 0; }
r[15]+=0x00000004u;
goto P_0c089dc0;
P_0c089dc0: /* original 6403, guest PC 0x0c089dc0 */
if(!s->budget--) { s->failed_pc=0x0c089dc0u; return 0; }
r[4]=r[0];
goto P_0c089dc2;
P_0c089dc2: /* original 63f2, guest PC 0x0c089dc2 */
if(!s->budget--) { s->failed_pc=0x0c089dc2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c089dc4;
P_0c089dc4: /* original e02a, guest PC 0x0c089dc4 */
if(!s->budget--) { s->failed_pc=0x0c089dc4u; return 0; }
r[0]=0x0000002au;
goto P_0c089dc6;
P_0c089dc6: /* original 0e35, guest PC 0x0c089dc6 */
if(!s->budget--) { s->failed_pc=0x0c089dc6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c089dc8;
P_0c089dc8: /* original e00c, guest PC 0x0c089dc8 */
if(!s->budget--) { s->failed_pc=0x0c089dc8u; return 0; }
r[0]=0x0000000cu;
goto P_0c089dca;
P_0c089dca: /* original f3f6, guest PC 0x0c089dca */
if(!s->budget--) { s->failed_pc=0x0c089dcau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089dcc;
P_0c089dcc: /* original e018, guest PC 0x0c089dcc */
if(!s->budget--) { s->failed_pc=0x0c089dccu; return 0; }
r[0]=0x00000018u;
goto P_0c089dce;
P_0c089dce: /* original fe37, guest PC 0x0c089dce */
if(!s->budget--) { s->failed_pc=0x0c089dceu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089dd0;
P_0c089dd0: /* original e004, guest PC 0x0c089dd0 */
if(!s->budget--) { s->failed_pc=0x0c089dd0u; return 0; }
r[0]=0x00000004u;
goto P_0c089dd2;
P_0c089dd2: /* original f3f6, guest PC 0x0c089dd2 */
if(!s->budget--) { s->failed_pc=0x0c089dd2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089dd4;
P_0c089dd4: /* original e024, guest PC 0x0c089dd4 */
if(!s->budget--) { s->failed_pc=0x0c089dd4u; return 0; }
r[0]=0x00000024u;
goto P_0c089dd6;
P_0c089dd6: /* original fe37, guest PC 0x0c089dd6 */
if(!s->budget--) { s->failed_pc=0x0c089dd6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089dd8;
P_0c089dd8: /* original e01c, guest PC 0x0c089dd8 */
if(!s->budget--) { s->failed_pc=0x0c089dd8u; return 0; }
r[0]=0x0000001cu;
goto P_0c089dda;
P_0c089dda: /* original f38d, guest PC 0x0c089dda */
if(!s->budget--) { s->failed_pc=0x0c089ddau; return 0; }
fr[3]=0;
goto P_0c089ddc;
P_0c089ddc: /* original fe37, guest PC 0x0c089ddc */
if(!s->budget--) { s->failed_pc=0x0c089ddcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089dde;
P_0c089dde: /* original e008, guest PC 0x0c089dde */
if(!s->budget--) { s->failed_pc=0x0c089ddeu; return 0; }
r[0]=0x00000008u;
goto P_0c089de0;
P_0c089de0: /* original f3f6, guest PC 0x0c089de0 */
if(!s->budget--) { s->failed_pc=0x0c089de0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089de2;
P_0c089de2: /* original e020, guest PC 0x0c089de2 */
if(!s->budget--) { s->failed_pc=0x0c089de2u; return 0; }
r[0]=0x00000020u;
goto P_0c089de4;
P_0c089de4: /* original fe37, guest PC 0x0c089de4 */
if(!s->budget--) { s->failed_pc=0x0c089de4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089de6;
P_0c089de6: /* original e02c, guest PC 0x0c089de6 */
if(!s->budget--) { s->failed_pc=0x0c089de6u; return 0; }
r[0]=0x0000002cu;
goto P_0c089de8;
P_0c089de8: /* original 0eb5, guest PC 0x0c089de8 */
if(!s->budget--) { s->failed_pc=0x0c089de8u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c089dea;
P_0c089dea: /* original e030, guest PC 0x0c089dea */
if(!s->budget--) { s->failed_pc=0x0c089deau; return 0; }
r[0]=0x00000030u;
goto P_0c089dec;
P_0c089dec: /* original 0e44, guest PC 0x0c089dec */
if(!s->budget--) { s->failed_pc=0x0c089decu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c089dee;
P_0c089dee: /* original e00c, guest PC 0x0c089dee */
if(!s->budget--) { s->failed_pc=0x0c089deeu; return 0; }
r[0]=0x0000000cu;
goto P_0c089df0;
P_0c089df0: /* original fef7, guest PC 0x0c089df0 */
if(!s->budget--) { s->failed_pc=0x0c089df0u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089df2;
P_0c089df2: /* original e010, guest PC 0x0c089df2 */
if(!s->budget--) { s->failed_pc=0x0c089df2u; return 0; }
r[0]=0x00000010u;
goto P_0c089df4;
P_0c089df4: /* original fee7, guest PC 0x0c089df4 */
if(!s->budget--) { s->failed_pc=0x0c089df4u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c089df6;
P_0c089df6: /* original e014, guest PC 0x0c089df6 */
if(!s->budget--) { s->failed_pc=0x0c089df6u; return 0; }
r[0]=0x00000014u;
goto P_0c089df8;
P_0c089df8: /* original fed7, guest PC 0x0c089df8 */
if(!s->budget--) { s->failed_pc=0x0c089df8u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c089dfa;
P_0c089dfa: /* original e014, guest PC 0x0c089dfa */
if(!s->budget--) { s->failed_pc=0x0c089dfau; return 0; }
r[0]=0x00000014u;
goto P_0c089dfc;
P_0c089dfc: /* original feca, guest PC 0x0c089dfc */
if(!s->budget--) { s->failed_pc=0x0c089dfcu; return 0; }
vf3_matrix_store(s,ram,12,r[14]);
goto P_0c089dfe;
P_0c089dfe: /* original f3f6, guest PC 0x0c089dfe */
if(!s->budget--) { s->failed_pc=0x0c089dfeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089e00;
P_0c089e00: /* original e004, guest PC 0x0c089e00 */
if(!s->budget--) { s->failed_pc=0x0c089e00u; return 0; }
r[0]=0x00000004u;
goto P_0c089e02;
P_0c089e02: /* original 4a10, guest PC 0x0c089e02 */
if(!s->budget--) { s->failed_pc=0x0c089e02u; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c089e04;
P_0c089e04: /* original fe37, guest PC 0x0c089e04 */
if(!s->budget--) { s->failed_pc=0x0c089e04u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089e06;
P_0c089e06: /* original e010, guest PC 0x0c089e06 */
if(!s->budget--) { s->failed_pc=0x0c089e06u; return 0; }
r[0]=0x00000010u;
goto P_0c089e08;
P_0c089e08: /* original f3f6, guest PC 0x0c089e08 */
if(!s->budget--) { s->failed_pc=0x0c089e08u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089e0a;
P_0c089e0a: /* original e008, guest PC 0x0c089e0a */
if(!s->budget--) { s->failed_pc=0x0c089e0au; return 0; }
r[0]=0x00000008u;
goto P_0c089e0c;
P_0c089e0c: /* original fe37, guest PC 0x0c089e0c */
if(!s->budget--) { s->failed_pc=0x0c089e0cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089e0e;
P_0c089e0e: /* original e02a, guest PC 0x0c089e0e */
if(!s->budget--) { s->failed_pc=0x0c089e0eu; return 0; }
r[0]=0x0000002au;
goto P_0c089e10;
P_0c089e10: /* original 63f2, guest PC 0x0c089e10 */
if(!s->budget--) { s->failed_pc=0x0c089e10u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c089e12;
P_0c089e12: /* original 0e35, guest PC 0x0c089e12 */
if(!s->budget--) { s->failed_pc=0x0c089e12u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c089e14;
P_0c089e14: /* original 8fab, guest PC 0x0c089e14 */
if(!s->budget--) { s->failed_pc=0x0c089e14u; return 0; }
cond=r[17]&1u;
r[14]+=0x0000003cu;
if(!cond) { goto P_0c089d6e; }
goto P_0c089e18;
P_0c089e16: /* original 7e3c, guest PC 0x0c089e16 */
if(!s->budget--) { s->failed_pc=0x0c089e16u; return 0; }
r[14]+=0x0000003cu;
goto P_0c089e18;
P_0c089e18: /* original 7f18, guest PC 0x0c089e18 */
if(!s->budget--) { s->failed_pc=0x0c089e18u; return 0; }
r[15]+=0x00000018u;
goto P_0c089e1a;
P_0c089e1a: /* original 4f26, guest PC 0x0c089e1a */
if(!s->budget--) { s->failed_pc=0x0c089e1au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089e1c;
P_0c089e1c: /* original fcf9, guest PC 0x0c089e1c */
if(!s->budget--) { s->failed_pc=0x0c089e1cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089e1e;
P_0c089e1e: /* original fdf9, guest PC 0x0c089e1e */
if(!s->budget--) { s->failed_pc=0x0c089e1eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089e20;
P_0c089e20: /* original fef9, guest PC 0x0c089e20 */
if(!s->budget--) { s->failed_pc=0x0c089e20u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089e22;
P_0c089e22: /* original fff9, guest PC 0x0c089e22 */
if(!s->budget--) { s->failed_pc=0x0c089e22u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089e24;
P_0c089e24: /* original 6af6, guest PC 0x0c089e24 */
if(!s->budget--) { s->failed_pc=0x0c089e24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089e26;
P_0c089e26: /* original 6bf6, guest PC 0x0c089e26 */
if(!s->budget--) { s->failed_pc=0x0c089e26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089e28;
P_0c089e28: /* original 6cf6, guest PC 0x0c089e28 */
if(!s->budget--) { s->failed_pc=0x0c089e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089e2a;
P_0c089e2a: /* original 6df6, guest PC 0x0c089e2a */
if(!s->budget--) { s->failed_pc=0x0c089e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089e2c;
P_0c089e2c: /* original 000b, guest PC 0x0c089e2c */
if(!s->budget--) { s->failed_pc=0x0c089e2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089e2e: /* original 6ef6, guest PC 0x0c089e2e */
if(!s->budget--) { s->failed_pc=0x0c089e2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089e30u,s,ram);
P_0c089e40: /* original 4f22, guest PC 0x0c089e40 */
if(!s->budget--) { s->failed_pc=0x0c089e40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089e42;
P_0c089e42: /* original 6212, guest PC 0x0c089e42 */
if(!s->budget--) { s->failed_pc=0x0c089e42u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c089e44;
P_0c089e44: /* original d30c, guest PC 0x0c089e44 */
if(!s->budget--) { s->failed_pc=0x0c089e44u; return 0; }
r[3]=read(ram,0x0c089e78u,4);
goto P_0c089e46;
P_0c089e46: /* original 7fe4, guest PC 0x0c089e46 */
if(!s->budget--) { s->failed_pc=0x0c089e46u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c089e48;
P_0c089e48: /* original 2238, guest PC 0x0c089e48 */
if(!s->budget--) { s->failed_pc=0x0c089e48u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c089e4a;
P_0c089e4a: /* original 8901, guest PC 0x0c089e4a */
if(!s->budget--) { s->failed_pc=0x0c089e4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089e50; }
goto P_0c089e4c;
P_0c089e4c: /* original a095, guest PC 0x0c089e4c */
if(!s->budget--) { s->failed_pc=0x0c089e4cu; return 0; }
goto P_0c089f7a;
P_0c089e4e: /* original 0009, guest PC 0x0c089e4e */
if(!s->budget--) { s->failed_pc=0x0c089e4eu; return 0; }
goto P_0c089e50;
P_0c089e50: /* original 6543, guest PC 0x0c089e50 */
if(!s->budget--) { s->failed_pc=0x0c089e50u; return 0; }
r[5]=r[4];
goto P_0c089e52;
P_0c089e52: /* original 8558, guest PC 0x0c089e52 */
if(!s->budget--) { s->failed_pc=0x0c089e52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+16,2);
goto P_0c089e54;
P_0c089e54: /* original 6e43, guest PC 0x0c089e54 */
if(!s->budget--) { s->failed_pc=0x0c089e54u; return 0; }
r[14]=r[4];
goto P_0c089e56;
P_0c089e56: /* original e402, guest PC 0x0c089e56 */
if(!s->budget--) { s->failed_pc=0x0c089e56u; return 0; }
r[4]=0x00000002u;
goto P_0c089e58;
P_0c089e58: /* original 6b03, guest PC 0x0c089e58 */
if(!s->budget--) { s->failed_pc=0x0c089e58u; return 0; }
r[11]=r[0];
goto P_0c089e5a;
P_0c089e5a: /* original 2b49, guest PC 0x0c089e5a */
if(!s->budget--) { s->failed_pc=0x0c089e5au; return 0; }
r[11]&=r[4];
goto P_0c089e5c;
P_0c089e5c: /* original 7b01, guest PC 0x0c089e5c */
if(!s->budget--) { s->failed_pc=0x0c089e5cu; return 0; }
r[11]+=0x00000001u;
goto P_0c089e5e;
P_0c089e5e: /* original e301, guest PC 0x0c089e5e */
if(!s->budget--) { s->failed_pc=0x0c089e5eu; return 0; }
r[3]=0x00000001u;
goto P_0c089e60;
P_0c089e60: /* original 60b3, guest PC 0x0c089e60 */
if(!s->budget--) { s->failed_pc=0x0c089e60u; return 0; }
r[0]=r[11];
goto P_0c089e62;
P_0c089e62: /* original ec3f, guest PC 0x0c089e62 */
if(!s->budget--) { s->failed_pc=0x0c089e62u; return 0; }
r[12]=0x0000003fu;
goto P_0c089e64;
P_0c089e64: /* original 8158, guest PC 0x0c089e64 */
if(!s->budget--) { s->failed_pc=0x0c089e64u; return 0; }
write(ram,r[5]+16,r[0],2);
goto P_0c089e66;
P_0c089e66: /* original d806, guest PC 0x0c089e66 */
if(!s->budget--) { s->failed_pc=0x0c089e66u; return 0; }
r[8]=read(ram,0x0c089e80u,4);
goto P_0c089e68;
P_0c089e68: /* original 2b39, guest PC 0x0c089e68 */
if(!s->budget--) { s->failed_pc=0x0c089e68u; return 0; }
r[11]&=r[3];
goto P_0c089e6a;
P_0c089e6a: /* original 7e14, guest PC 0x0c089e6a */
if(!s->budget--) { s->failed_pc=0x0c089e6au; return 0; }
r[14]+=0x00000014u;
goto P_0c089e6c;
P_0c089e6c: /* original a083, guest PC 0x0c089e6c */
if(!s->budget--) { s->failed_pc=0x0c089e6cu; return 0; }
r[10]=r[4];
goto P_0c089f76;
P_0c089e6e: /* original 6a43, guest PC 0x0c089e6e */
if(!s->budget--) { s->failed_pc=0x0c089e6eu; return 0; }
r[10]=r[4];
return vf3_matrix_family(0x0c089e70u,s,ram);
P_0c089e84: /* original e02a, guest PC 0x0c089e84 */
if(!s->budget--) { s->failed_pc=0x0c089e84u; return 0; }
r[0]=0x0000002au;
goto P_0c089e86;
P_0c089e86: /* original 04ed, guest PC 0x0c089e86 */
if(!s->budget--) { s->failed_pc=0x0c089e86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c089e88;
P_0c089e88: /* original e028, guest PC 0x0c089e88 */
if(!s->budget--) { s->failed_pc=0x0c089e88u; return 0; }
r[0]=0x00000028u;
goto P_0c089e8a;
P_0c089e8a: /* original 03ed, guest PC 0x0c089e8a */
if(!s->budget--) { s->failed_pc=0x0c089e8au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c089e8c;
P_0c089e8c: /* original e02c, guest PC 0x0c089e8c */
if(!s->budget--) { s->failed_pc=0x0c089e8cu; return 0; }
r[0]=0x0000002cu;
goto P_0c089e8e;
P_0c089e8e: /* original 1f31, guest PC 0x0c089e8e */
if(!s->budget--) { s->failed_pc=0x0c089e8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c089e90;
P_0c089e90: /* original 0ded, guest PC 0x0c089e90 */
if(!s->budget--) { s->failed_pc=0x0c089e90u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c089e92;
P_0c089e92: /* original e030, guest PC 0x0c089e92 */
if(!s->budget--) { s->failed_pc=0x0c089e92u; return 0; }
r[0]=0x00000030u;
goto P_0c089e94;
P_0c089e94: /* original 09ec, guest PC 0x0c089e94 */
if(!s->budget--) { s->failed_pc=0x0c089e94u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c089e96;
P_0c089e96: /* original e018, guest PC 0x0c089e96 */
if(!s->budget--) { s->failed_pc=0x0c089e96u; return 0; }
r[0]=0x00000018u;
goto P_0c089e98;
P_0c089e98: /* original f3e6, guest PC 0x0c089e98 */
if(!s->budget--) { s->failed_pc=0x0c089e98u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089e9a;
P_0c089e9a: /* original e00c, guest PC 0x0c089e9a */
if(!s->budget--) { s->failed_pc=0x0c089e9au; return 0; }
r[0]=0x0000000cu;
goto P_0c089e9c;
P_0c089e9c: /* original 3dbc, guest PC 0x0c089e9c */
if(!s->budget--) { s->failed_pc=0x0c089e9cu; return 0; }
r[13]+=r[11];
goto P_0c089e9e;
P_0c089e9e: /* original ff37, guest PC 0x0c089e9e */
if(!s->budget--) { s->failed_pc=0x0c089e9eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089ea0;
P_0c089ea0: /* original e01c, guest PC 0x0c089ea0 */
if(!s->budget--) { s->failed_pc=0x0c089ea0u; return 0; }
r[0]=0x0000001cu;
goto P_0c089ea2;
P_0c089ea2: /* original f3e6, guest PC 0x0c089ea2 */
if(!s->budget--) { s->failed_pc=0x0c089ea2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089ea4;
P_0c089ea4: /* original e024, guest PC 0x0c089ea4 */
if(!s->budget--) { s->failed_pc=0x0c089ea4u; return 0; }
r[0]=0x00000024u;
goto P_0c089ea6;
P_0c089ea6: /* original ff3a, guest PC 0x0c089ea6 */
if(!s->budget--) { s->failed_pc=0x0c089ea6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c089ea8;
P_0c089ea8: /* original f4e6, guest PC 0x0c089ea8 */
if(!s->budget--) { s->failed_pc=0x0c089ea8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c089eaa;
P_0c089eaa: /* original e020, guest PC 0x0c089eaa */
if(!s->budget--) { s->failed_pc=0x0c089eaau; return 0; }
r[0]=0x00000020u;
goto P_0c089eac;
P_0c089eac: /* original f3e6, guest PC 0x0c089eac */
if(!s->budget--) { s->failed_pc=0x0c089eacu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089eae;
P_0c089eae: /* original e008, guest PC 0x0c089eae */
if(!s->budget--) { s->failed_pc=0x0c089eaeu; return 0; }
r[0]=0x00000008u;
goto P_0c089eb0;
P_0c089eb0: /* original ff37, guest PC 0x0c089eb0 */
if(!s->budget--) { s->failed_pc=0x0c089eb0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089eb2;
P_0c089eb2: /* original e00c, guest PC 0x0c089eb2 */
if(!s->budget--) { s->failed_pc=0x0c089eb2u; return 0; }
r[0]=0x0000000cu;
goto P_0c089eb4;
P_0c089eb4: /* original f3f8, guest PC 0x0c089eb4 */
if(!s->budget--) { s->failed_pc=0x0c089eb4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089eb6;
P_0c089eb6: /* original f430, guest PC 0x0c089eb6 */
if(!s->budget--) { s->failed_pc=0x0c089eb6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c089eb8;
P_0c089eb8: /* original ff4a, guest PC 0x0c089eb8 */
if(!s->budget--) { s->failed_pc=0x0c089eb8u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c089eba;
P_0c089eba: /* original f3f6, guest PC 0x0c089eba */
if(!s->budget--) { s->failed_pc=0x0c089ebau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089ebc;
P_0c089ebc: /* original e00c, guest PC 0x0c089ebc */
if(!s->budget--) { s->failed_pc=0x0c089ebcu; return 0; }
r[0]=0x0000000cu;
goto P_0c089ebe;
P_0c089ebe: /* original f2e6, guest PC 0x0c089ebe */
if(!s->budget--) { s->failed_pc=0x0c089ebeu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c089ec0;
P_0c089ec0: /* original e018, guest PC 0x0c089ec0 */
if(!s->budget--) { s->failed_pc=0x0c089ec0u; return 0; }
r[0]=0x00000018u;
goto P_0c089ec2;
P_0c089ec2: /* original f230, guest PC 0x0c089ec2 */
if(!s->budget--) { s->failed_pc=0x0c089ec2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c089ec4;
P_0c089ec4: /* original ff27, guest PC 0x0c089ec4 */
if(!s->budget--) { s->failed_pc=0x0c089ec4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c089ec6;
P_0c089ec6: /* original e010, guest PC 0x0c089ec6 */
if(!s->budget--) { s->failed_pc=0x0c089ec6u; return 0; }
r[0]=0x00000010u;
goto P_0c089ec8;
P_0c089ec8: /* original f2e6, guest PC 0x0c089ec8 */
if(!s->budget--) { s->failed_pc=0x0c089ec8u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c089eca;
P_0c089eca: /* original e014, guest PC 0x0c089eca */
if(!s->budget--) { s->failed_pc=0x0c089ecau; return 0; }
r[0]=0x00000014u;
goto P_0c089ecc;
P_0c089ecc: /* original f3f8, guest PC 0x0c089ecc */
if(!s->budget--) { s->failed_pc=0x0c089eccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089ece;
P_0c089ece: /* original 6593, guest PC 0x0c089ece */
if(!s->budget--) { s->failed_pc=0x0c089eceu; return 0; }
r[5]=r[9];
goto P_0c089ed0;
P_0c089ed0: /* original f230, guest PC 0x0c089ed0 */
if(!s->budget--) { s->failed_pc=0x0c089ed0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c089ed2;
P_0c089ed2: /* original ff27, guest PC 0x0c089ed2 */
if(!s->budget--) { s->failed_pc=0x0c089ed2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c089ed4;
P_0c089ed4: /* original e008, guest PC 0x0c089ed4 */
if(!s->budget--) { s->failed_pc=0x0c089ed4u; return 0; }
r[0]=0x00000008u;
goto P_0c089ed6;
P_0c089ed6: /* original f3f6, guest PC 0x0c089ed6 */
if(!s->budget--) { s->failed_pc=0x0c089ed6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089ed8;
P_0c089ed8: /* original e014, guest PC 0x0c089ed8 */
if(!s->budget--) { s->failed_pc=0x0c089ed8u; return 0; }
r[0]=0x00000014u;
goto P_0c089eda;
P_0c089eda: /* original f2e6, guest PC 0x0c089eda */
if(!s->budget--) { s->failed_pc=0x0c089edau; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c089edc;
P_0c089edc: /* original e010, guest PC 0x0c089edc */
if(!s->budget--) { s->failed_pc=0x0c089edcu; return 0; }
r[0]=0x00000010u;
goto P_0c089ede;
P_0c089ede: /* original f230, guest PC 0x0c089ede */
if(!s->budget--) { s->failed_pc=0x0c089edeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c089ee0;
P_0c089ee0: /* original ff27, guest PC 0x0c089ee0 */
if(!s->budget--) { s->failed_pc=0x0c089ee0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c089ee2;
P_0c089ee2: /* original e028, guest PC 0x0c089ee2 */
if(!s->budget--) { s->failed_pc=0x0c089ee2u; return 0; }
r[0]=0x00000028u;
goto P_0c089ee4;
P_0c089ee4: /* original 53f1, guest PC 0x0c089ee4 */
if(!s->budget--) { s->failed_pc=0x0c089ee4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c089ee6;
P_0c089ee6: /* original 334c, guest PC 0x0c089ee6 */
if(!s->budget--) { s->failed_pc=0x0c089ee6u; return 0; }
r[3]+=r[4];
goto P_0c089ee8;
P_0c089ee8: /* original 6233, guest PC 0x0c089ee8 */
if(!s->budget--) { s->failed_pc=0x0c089ee8u; return 0; }
r[2]=r[3];
goto P_0c089eea;
P_0c089eea: /* original 1f31, guest PC 0x0c089eea */
if(!s->budget--) { s->failed_pc=0x0c089eeau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c089eec;
P_0c089eec: /* original 0e25, guest PC 0x0c089eec */
if(!s->budget--) { s->failed_pc=0x0c089eecu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c089eee;
P_0c089eee: /* original f4f8, guest PC 0x0c089eee */
if(!s->budget--) { s->failed_pc=0x0c089eeeu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c089ef0;
P_0c089ef0: /* original be7b, guest PC 0x0c089ef0 */
if(!s->budget--) { s->failed_pc=0x0c089ef0u; return 0; }
target=0x0c089beau; r[16]=0x0c089ef4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089ef4u) { target=s->pc; goto dispatch; }
goto P_0c089ef4;
P_0c089ef2: /* original 64e3, guest PC 0x0c089ef2 */
if(!s->budget--) { s->failed_pc=0x0c089ef2u; return 0; }
r[4]=r[14];
goto P_0c089ef4;
P_0c089ef4: /* original 62f3, guest PC 0x0c089ef4 */
if(!s->budget--) { s->failed_pc=0x0c089ef4u; return 0; }
r[2]=r[15];
goto P_0c089ef6;
P_0c089ef6: /* original 7210, guest PC 0x0c089ef6 */
if(!s->budget--) { s->failed_pc=0x0c089ef6u; return 0; }
r[2]+=0x00000010u;
goto P_0c089ef8;
P_0c089ef8: /* original 2f26, guest PC 0x0c089ef8 */
if(!s->budget--) { s->failed_pc=0x0c089ef8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089efa;
P_0c089efa: /* original 66f3, guest PC 0x0c089efa */
if(!s->budget--) { s->failed_pc=0x0c089efau; return 0; }
r[6]=r[15];
goto P_0c089efc;
P_0c089efc: /* original 65f3, guest PC 0x0c089efc */
if(!s->budget--) { s->failed_pc=0x0c089efcu; return 0; }
r[5]=r[15];
goto P_0c089efe;
P_0c089efe: /* original 67f3, guest PC 0x0c089efe */
if(!s->budget--) { s->failed_pc=0x0c089efeu; return 0; }
r[7]=r[15];
goto P_0c089f00;
P_0c089f00: /* original 7504, guest PC 0x0c089f00 */
if(!s->budget--) { s->failed_pc=0x0c089f00u; return 0; }
r[5]+=0x00000004u;
goto P_0c089f02;
P_0c089f02: /* original 7718, guest PC 0x0c089f02 */
if(!s->budget--) { s->failed_pc=0x0c089f02u; return 0; }
r[7]+=0x00000018u;
goto P_0c089f04;
P_0c089f04: /* original 761c, guest PC 0x0c089f04 */
if(!s->budget--) { s->failed_pc=0x0c089f04u; return 0; }
r[6]+=0x0000001cu;
goto P_0c089f06;
P_0c089f06: /* original be23, guest PC 0x0c089f06 */
if(!s->budget--) { s->failed_pc=0x0c089f06u; return 0; }
target=0x0c089b50u; r[16]=0x0c089f0au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089f0au) { target=s->pc; goto dispatch; }
goto P_0c089f0a;
P_0c089f08: /* original 64e3, guest PC 0x0c089f08 */
if(!s->budget--) { s->failed_pc=0x0c089f08u; return 0; }
r[4]=r[14];
goto P_0c089f0a;
P_0c089f0a: /* original e018, guest PC 0x0c089f0a */
if(!s->budget--) { s->failed_pc=0x0c089f0au; return 0; }
r[0]=0x00000018u;
goto P_0c089f0c;
P_0c089f0c: /* original 3dc7, guest PC 0x0c089f0c */
if(!s->budget--) { s->failed_pc=0x0c089f0cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[12])!=0);
goto P_0c089f0e;
P_0c089f0e: /* original 7f04, guest PC 0x0c089f0e */
if(!s->budget--) { s->failed_pc=0x0c089f0eu; return 0; }
r[15]+=0x00000004u;
goto P_0c089f10;
P_0c089f10: /* original f3f6, guest PC 0x0c089f10 */
if(!s->budget--) { s->failed_pc=0x0c089f10u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f12;
P_0c089f12: /* original e00c, guest PC 0x0c089f12 */
if(!s->budget--) { s->failed_pc=0x0c089f12u; return 0; }
r[0]=0x0000000cu;
goto P_0c089f14;
P_0c089f14: /* original fe37, guest PC 0x0c089f14 */
if(!s->budget--) { s->failed_pc=0x0c089f14u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f16;
P_0c089f16: /* original e014, guest PC 0x0c089f16 */
if(!s->budget--) { s->failed_pc=0x0c089f16u; return 0; }
r[0]=0x00000014u;
goto P_0c089f18;
P_0c089f18: /* original f3f6, guest PC 0x0c089f18 */
if(!s->budget--) { s->failed_pc=0x0c089f18u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f1a;
P_0c089f1a: /* original e010, guest PC 0x0c089f1a */
if(!s->budget--) { s->failed_pc=0x0c089f1au; return 0; }
r[0]=0x00000010u;
goto P_0c089f1c;
P_0c089f1c: /* original fe37, guest PC 0x0c089f1c */
if(!s->budget--) { s->failed_pc=0x0c089f1cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f1e;
P_0c089f1e: /* original e010, guest PC 0x0c089f1e */
if(!s->budget--) { s->failed_pc=0x0c089f1eu; return 0; }
r[0]=0x00000010u;
goto P_0c089f20;
P_0c089f20: /* original f3f6, guest PC 0x0c089f20 */
if(!s->budget--) { s->failed_pc=0x0c089f20u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f22;
P_0c089f22: /* original e014, guest PC 0x0c089f22 */
if(!s->budget--) { s->failed_pc=0x0c089f22u; return 0; }
r[0]=0x00000014u;
goto P_0c089f24;
P_0c089f24: /* original 8f1a, guest PC 0x0c089f24 */
if(!s->budget--) { s->failed_pc=0x0c089f24u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[14]+r[0]);
if(!cond) { goto P_0c089f5c; }
goto P_0c089f28;
P_0c089f26: /* original fe37, guest PC 0x0c089f26 */
if(!s->budget--) { s->failed_pc=0x0c089f26u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f28;
P_0c089f28: /* original 62f3, guest PC 0x0c089f28 */
if(!s->budget--) { s->failed_pc=0x0c089f28u; return 0; }
r[2]=r[15];
goto P_0c089f2a;
P_0c089f2a: /* original 7204, guest PC 0x0c089f2a */
if(!s->budget--) { s->failed_pc=0x0c089f2au; return 0; }
r[2]+=0x00000004u;
goto P_0c089f2c;
P_0c089f2c: /* original 2f26, guest PC 0x0c089f2c */
if(!s->budget--) { s->failed_pc=0x0c089f2cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089f2e;
P_0c089f2e: /* original 66f3, guest PC 0x0c089f2e */
if(!s->budget--) { s->failed_pc=0x0c089f2eu; return 0; }
r[6]=r[15];
goto P_0c089f30;
P_0c089f30: /* original 65f3, guest PC 0x0c089f30 */
if(!s->budget--) { s->failed_pc=0x0c089f30u; return 0; }
r[5]=r[15];
goto P_0c089f32;
P_0c089f32: /* original 67f3, guest PC 0x0c089f32 */
if(!s->budget--) { s->failed_pc=0x0c089f32u; return 0; }
r[7]=r[15];
goto P_0c089f34;
P_0c089f34: /* original 7504, guest PC 0x0c089f34 */
if(!s->budget--) { s->failed_pc=0x0c089f34u; return 0; }
r[5]+=0x00000004u;
goto P_0c089f36;
P_0c089f36: /* original 7710, guest PC 0x0c089f36 */
if(!s->budget--) { s->failed_pc=0x0c089f36u; return 0; }
r[7]+=0x00000010u;
goto P_0c089f38;
P_0c089f38: /* original 760c, guest PC 0x0c089f38 */
if(!s->budget--) { s->failed_pc=0x0c089f38u; return 0; }
r[6]+=0x0000000cu;
goto P_0c089f3a;
P_0c089f3a: /* original bea4, guest PC 0x0c089f3a */
if(!s->budget--) { s->failed_pc=0x0c089f3au; return 0; }
target=0x0c089c86u; r[16]=0x0c089f3eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089f3eu) { target=s->pc; goto dispatch; }
goto P_0c089f3e;
P_0c089f3c: /* original 64e3, guest PC 0x0c089f3c */
if(!s->budget--) { s->failed_pc=0x0c089f3cu; return 0; }
r[4]=r[14];
goto P_0c089f3e;
P_0c089f3e: /* original 7f04, guest PC 0x0c089f3e */
if(!s->budget--) { s->failed_pc=0x0c089f3eu; return 0; }
r[15]+=0x00000004u;
goto P_0c089f40;
P_0c089f40: /* original 52f1, guest PC 0x0c089f40 */
if(!s->budget--) { s->failed_pc=0x0c089f40u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c089f42;
P_0c089f42: /* original e02a, guest PC 0x0c089f42 */
if(!s->budget--) { s->failed_pc=0x0c089f42u; return 0; }
r[0]=0x0000002au;
goto P_0c089f44;
P_0c089f44: /* original 0e25, guest PC 0x0c089f44 */
if(!s->budget--) { s->failed_pc=0x0c089f44u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c089f46;
P_0c089f46: /* original e00c, guest PC 0x0c089f46 */
if(!s->budget--) { s->failed_pc=0x0c089f46u; return 0; }
r[0]=0x0000000cu;
goto P_0c089f48;
P_0c089f48: /* original f3f6, guest PC 0x0c089f48 */
if(!s->budget--) { s->failed_pc=0x0c089f48u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f4a;
P_0c089f4a: /* original e018, guest PC 0x0c089f4a */
if(!s->budget--) { s->failed_pc=0x0c089f4au; return 0; }
r[0]=0x00000018u;
goto P_0c089f4c;
P_0c089f4c: /* original fe37, guest PC 0x0c089f4c */
if(!s->budget--) { s->failed_pc=0x0c089f4cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f4e;
P_0c089f4e: /* original e024, guest PC 0x0c089f4e */
if(!s->budget--) { s->failed_pc=0x0c089f4eu; return 0; }
r[0]=0x00000024u;
goto P_0c089f50;
P_0c089f50: /* original f3f8, guest PC 0x0c089f50 */
if(!s->budget--) { s->failed_pc=0x0c089f50u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089f52;
P_0c089f52: /* original fe37, guest PC 0x0c089f52 */
if(!s->budget--) { s->failed_pc=0x0c089f52u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f54;
P_0c089f54: /* original e008, guest PC 0x0c089f54 */
if(!s->budget--) { s->failed_pc=0x0c089f54u; return 0; }
r[0]=0x00000008u;
goto P_0c089f56;
P_0c089f56: /* original f3f6, guest PC 0x0c089f56 */
if(!s->budget--) { s->failed_pc=0x0c089f56u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f58;
P_0c089f58: /* original e020, guest PC 0x0c089f58 */
if(!s->budget--) { s->failed_pc=0x0c089f58u; return 0; }
r[0]=0x00000020u;
goto P_0c089f5a;
P_0c089f5a: /* original fe37, guest PC 0x0c089f5a */
if(!s->budget--) { s->failed_pc=0x0c089f5au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f5c;
P_0c089f5c: /* original e02c, guest PC 0x0c089f5c */
if(!s->budget--) { s->failed_pc=0x0c089f5cu; return 0; }
r[0]=0x0000002cu;
goto P_0c089f5e;
P_0c089f5e: /* original 2dc9, guest PC 0x0c089f5e */
if(!s->budget--) { s->failed_pc=0x0c089f5eu; return 0; }
r[13]&=r[12];
goto P_0c089f60;
P_0c089f60: /* original 0ed5, guest PC 0x0c089f60 */
if(!s->budget--) { s->failed_pc=0x0c089f60u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c089f62;
P_0c089f62: /* original 6093, guest PC 0x0c089f62 */
if(!s->budget--) { s->failed_pc=0x0c089f62u; return 0; }
r[0]=r[9];
goto P_0c089f64;
P_0c089f64: /* original 4008, guest PC 0x0c089f64 */
if(!s->budget--) { s->failed_pc=0x0c089f64u; return 0; }
r[0]<<=2;
goto P_0c089f66;
P_0c089f66: /* original 048e, guest PC 0x0c089f66 */
if(!s->budget--) { s->failed_pc=0x0c089f66u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c089f68;
P_0c089f68: /* original 60d3, guest PC 0x0c089f68 */
if(!s->budget--) { s->failed_pc=0x0c089f68u; return 0; }
r[0]=r[13];
goto P_0c089f6a;
P_0c089f6a: /* original 4000, guest PC 0x0c089f6a */
if(!s->budget--) { s->failed_pc=0x0c089f6au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c089f6c;
P_0c089f6c: /* original 034d, guest PC 0x0c089f6c */
if(!s->budget--) { s->failed_pc=0x0c089f6cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c089f6e;
P_0c089f6e: /* original e02e, guest PC 0x0c089f6e */
if(!s->budget--) { s->failed_pc=0x0c089f6eu; return 0; }
r[0]=0x0000002eu;
goto P_0c089f70;
P_0c089f70: /* original 7aff, guest PC 0x0c089f70 */
if(!s->budget--) { s->failed_pc=0x0c089f70u; return 0; }
r[10]+=0xffffffffu;
goto P_0c089f72;
P_0c089f72: /* original 0e35, guest PC 0x0c089f72 */
if(!s->budget--) { s->failed_pc=0x0c089f72u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c089f74;
P_0c089f74: /* original 7e3c, guest PC 0x0c089f74 */
if(!s->budget--) { s->failed_pc=0x0c089f74u; return 0; }
r[14]+=0x0000003cu;
goto P_0c089f76;
P_0c089f76: /* original 2aa8, guest PC 0x0c089f76 */
if(!s->budget--) { s->failed_pc=0x0c089f76u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c089f78;
P_0c089f78: /* original 8b84, guest PC 0x0c089f78 */
if(!s->budget--) { s->failed_pc=0x0c089f78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089e84; }
goto P_0c089f7a;
P_0c089f7a: /* original 7f1c, guest PC 0x0c089f7a */
if(!s->budget--) { s->failed_pc=0x0c089f7au; return 0; }
r[15]+=0x0000001cu;
goto P_0c089f7c;
P_0c089f7c: /* original 4f26, guest PC 0x0c089f7c */
if(!s->budget--) { s->failed_pc=0x0c089f7cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089f7e;
P_0c089f7e: /* original 68f6, guest PC 0x0c089f7e */
if(!s->budget--) { s->failed_pc=0x0c089f7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c089f80;
P_0c089f80: /* original 69f6, guest PC 0x0c089f80 */
if(!s->budget--) { s->failed_pc=0x0c089f80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089f82;
P_0c089f82: /* original 6af6, guest PC 0x0c089f82 */
if(!s->budget--) { s->failed_pc=0x0c089f82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089f84;
P_0c089f84: /* original 6bf6, guest PC 0x0c089f84 */
if(!s->budget--) { s->failed_pc=0x0c089f84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089f86;
P_0c089f86: /* original 6cf6, guest PC 0x0c089f86 */
if(!s->budget--) { s->failed_pc=0x0c089f86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089f88;
P_0c089f88: /* original 6df6, guest PC 0x0c089f88 */
if(!s->budget--) { s->failed_pc=0x0c089f88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089f8a;
P_0c089f8a: /* original 000b, guest PC 0x0c089f8a */
if(!s->budget--) { s->failed_pc=0x0c089f8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089f8c: /* original 6ef6, guest PC 0x0c089f8c */
if(!s->budget--) { s->failed_pc=0x0c089f8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089f8eu,s,ram);
P_0c093390: /* original f40b, guest PC 0x0c093390 */
if(!s->budget--) { s->failed_pc=0x0c093390u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093392;
P_0c093392: /* original 0009, guest PC 0x0c093392 */
if(!s->budget--) { s->failed_pc=0x0c093392u; return 0; }
goto P_0c093394;
P_0c093394: /* original 63f3, guest PC 0x0c093394 */
if(!s->budget--) { s->failed_pc=0x0c093394u; return 0; }
r[3]=r[15];
goto P_0c093396;
P_0c093396: /* original e044, guest PC 0x0c093396 */
if(!s->budget--) { s->failed_pc=0x0c093396u; return 0; }
r[0]=0x00000044u;
goto P_0c093398;
P_0c093398: /* original 2f36, guest PC 0x0c093398 */
if(!s->budget--) { s->failed_pc=0x0c093398u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09339a;
P_0c09339a: /* original 65e3, guest PC 0x0c09339a */
if(!s->budget--) { s->failed_pc=0x0c09339au; return 0; }
r[5]=r[14];
goto P_0c09339c;
P_0c09339c: /* original 02fe, guest PC 0x0c09339c */
if(!s->budget--) { s->failed_pc=0x0c09339cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09339e;
P_0c09339e: /* original 2f26, guest PC 0x0c09339e */
if(!s->budget--) { s->failed_pc=0x0c09339eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0933a0;
P_0c0933a0: /* original 53f4, guest PC 0x0c0933a0 */
if(!s->budget--) { s->failed_pc=0x0c0933a0u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0933a2;
P_0c0933a2: /* original 2f36, guest PC 0x0c0933a2 */
if(!s->budget--) { s->failed_pc=0x0c0933a2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0933a4;
P_0c0933a4: /* original 66f3, guest PC 0x0c0933a4 */
if(!s->budget--) { s->failed_pc=0x0c0933a4u; return 0; }
r[6]=r[15];
goto P_0c0933a6;
P_0c0933a6: /* original d352, guest PC 0x0c0933a6 */
if(!s->budget--) { s->failed_pc=0x0c0933a6u; return 0; }
r[3]=read(ram,0x0c0934f0u,4);
goto P_0c0933a8;
P_0c0933a8: /* original 67f3, guest PC 0x0c0933a8 */
if(!s->budget--) { s->failed_pc=0x0c0933a8u; return 0; }
r[7]=r[15];
goto P_0c0933aa;
P_0c0933aa: /* original 7730, guest PC 0x0c0933aa */
if(!s->budget--) { s->failed_pc=0x0c0933aau; return 0; }
r[7]+=0x00000030u;
goto P_0c0933ac;
P_0c0933ac: /* original 7624, guest PC 0x0c0933ac */
if(!s->budget--) { s->failed_pc=0x0c0933acu; return 0; }
r[6]+=0x00000024u;
goto P_0c0933ae;
P_0c0933ae: /* original 430b, guest PC 0x0c0933ae */
if(!s->budget--) { s->failed_pc=0x0c0933aeu; return 0; }
target=r[3];
r[16]=0x0c0933b2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0933b2u) { target=s->pc; goto dispatch; }
goto P_0c0933b2;
P_0c0933b0: /* original 64d3, guest PC 0x0c0933b0 */
if(!s->budget--) { s->failed_pc=0x0c0933b0u; return 0; }
r[4]=r[13];
goto P_0c0933b2;
P_0c0933b2: /* original 7f0c, guest PC 0x0c0933b2 */
if(!s->budget--) { s->failed_pc=0x0c0933b2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0933b4;
P_0c0933b4: /* original d24f, guest PC 0x0c0933b4 */
if(!s->budget--) { s->failed_pc=0x0c0933b4u; return 0; }
r[2]=read(ram,0x0c0934f4u,4);
goto P_0c0933b6;
P_0c0933b6: /* original 65f3, guest PC 0x0c0933b6 */
if(!s->budget--) { s->failed_pc=0x0c0933b6u; return 0; }
r[5]=r[15];
goto P_0c0933b8;
P_0c0933b8: /* original 66f3, guest PC 0x0c0933b8 */
if(!s->budget--) { s->failed_pc=0x0c0933b8u; return 0; }
r[6]=r[15];
goto P_0c0933ba;
P_0c0933ba: /* original 67f3, guest PC 0x0c0933ba */
if(!s->budget--) { s->failed_pc=0x0c0933bau; return 0; }
r[7]=r[15];
goto P_0c0933bc;
P_0c0933bc: /* original 7518, guest PC 0x0c0933bc */
if(!s->budget--) { s->failed_pc=0x0c0933bcu; return 0; }
r[5]+=0x00000018u;
goto P_0c0933be;
P_0c0933be: /* original 7624, guest PC 0x0c0933be */
if(!s->budget--) { s->failed_pc=0x0c0933beu; return 0; }
r[6]+=0x00000024u;
goto P_0c0933c0;
P_0c0933c0: /* original 770c, guest PC 0x0c0933c0 */
if(!s->budget--) { s->failed_pc=0x0c0933c0u; return 0; }
r[7]+=0x0000000cu;
goto P_0c0933c2;
P_0c0933c2: /* original 420b, guest PC 0x0c0933c2 */
if(!s->budget--) { s->failed_pc=0x0c0933c2u; return 0; }
target=r[2];
r[16]=0x0c0933c6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0933c6u) { target=s->pc; goto dispatch; }
goto P_0c0933c6;
P_0c0933c4: /* original 64e3, guest PC 0x0c0933c4 */
if(!s->budget--) { s->failed_pc=0x0c0933c4u; return 0; }
r[4]=r[14];
goto P_0c0933c6;
P_0c0933c6: /* original e018, guest PC 0x0c0933c6 */
if(!s->budget--) { s->failed_pc=0x0c0933c6u; return 0; }
r[0]=0x00000018u;
goto P_0c0933c8;
P_0c0933c8: /* original f3f6, guest PC 0x0c0933c8 */
if(!s->budget--) { s->failed_pc=0x0c0933c8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933ca;
P_0c0933ca: /* original e01c, guest PC 0x0c0933ca */
if(!s->budget--) { s->failed_pc=0x0c0933cau; return 0; }
r[0]=0x0000001cu;
goto P_0c0933cc;
P_0c0933cc: /* original fe3a, guest PC 0x0c0933cc */
if(!s->budget--) { s->failed_pc=0x0c0933ccu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0933ce;
P_0c0933ce: /* original f3f6, guest PC 0x0c0933ce */
if(!s->budget--) { s->failed_pc=0x0c0933ceu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933d0;
P_0c0933d0: /* original e004, guest PC 0x0c0933d0 */
if(!s->budget--) { s->failed_pc=0x0c0933d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0933d2;
P_0c0933d2: /* original fe37, guest PC 0x0c0933d2 */
if(!s->budget--) { s->failed_pc=0x0c0933d2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933d4;
P_0c0933d4: /* original e020, guest PC 0x0c0933d4 */
if(!s->budget--) { s->failed_pc=0x0c0933d4u; return 0; }
r[0]=0x00000020u;
goto P_0c0933d6;
P_0c0933d6: /* original f3f6, guest PC 0x0c0933d6 */
if(!s->budget--) { s->failed_pc=0x0c0933d6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933d8;
P_0c0933d8: /* original e008, guest PC 0x0c0933d8 */
if(!s->budget--) { s->failed_pc=0x0c0933d8u; return 0; }
r[0]=0x00000008u;
goto P_0c0933da;
P_0c0933da: /* original fe37, guest PC 0x0c0933da */
if(!s->budget--) { s->failed_pc=0x0c0933dau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933dc;
P_0c0933dc: /* original e024, guest PC 0x0c0933dc */
if(!s->budget--) { s->failed_pc=0x0c0933dcu; return 0; }
r[0]=0x00000024u;
goto P_0c0933de;
P_0c0933de: /* original f3f6, guest PC 0x0c0933de */
if(!s->budget--) { s->failed_pc=0x0c0933deu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933e0;
P_0c0933e0: /* original e00c, guest PC 0x0c0933e0 */
if(!s->budget--) { s->failed_pc=0x0c0933e0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0933e2;
P_0c0933e2: /* original fe37, guest PC 0x0c0933e2 */
if(!s->budget--) { s->failed_pc=0x0c0933e2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933e4;
P_0c0933e4: /* original e028, guest PC 0x0c0933e4 */
if(!s->budget--) { s->failed_pc=0x0c0933e4u; return 0; }
r[0]=0x00000028u;
goto P_0c0933e6;
P_0c0933e6: /* original f3f6, guest PC 0x0c0933e6 */
if(!s->budget--) { s->failed_pc=0x0c0933e6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933e8;
P_0c0933e8: /* original e010, guest PC 0x0c0933e8 */
if(!s->budget--) { s->failed_pc=0x0c0933e8u; return 0; }
r[0]=0x00000010u;
goto P_0c0933ea;
P_0c0933ea: /* original fe37, guest PC 0x0c0933ea */
if(!s->budget--) { s->failed_pc=0x0c0933eau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933ec;
P_0c0933ec: /* original e02c, guest PC 0x0c0933ec */
if(!s->budget--) { s->failed_pc=0x0c0933ecu; return 0; }
r[0]=0x0000002cu;
goto P_0c0933ee;
P_0c0933ee: /* original f3f6, guest PC 0x0c0933ee */
if(!s->budget--) { s->failed_pc=0x0c0933eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933f0;
P_0c0933f0: /* original e014, guest PC 0x0c0933f0 */
if(!s->budget--) { s->failed_pc=0x0c0933f0u; return 0; }
r[0]=0x00000014u;
goto P_0c0933f2;
P_0c0933f2: /* original fe37, guest PC 0x0c0933f2 */
if(!s->budget--) { s->failed_pc=0x0c0933f2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0933f4;
P_0c0933f4: /* original e018, guest PC 0x0c0933f4 */
if(!s->budget--) { s->failed_pc=0x0c0933f4u; return 0; }
r[0]=0x00000018u;
goto P_0c0933f6;
P_0c0933f6: /* original f3f6, guest PC 0x0c0933f6 */
if(!s->budget--) { s->failed_pc=0x0c0933f6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0933f8;
P_0c0933f8: /* original e024, guest PC 0x0c0933f8 */
if(!s->budget--) { s->failed_pc=0x0c0933f8u; return 0; }
r[0]=0x00000024u;
goto P_0c0933fa;
P_0c0933fa: /* original ff37, guest PC 0x0c0933fa */
if(!s->budget--) { s->failed_pc=0x0c0933fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0933fc;
P_0c0933fc: /* original e01c, guest PC 0x0c0933fc */
if(!s->budget--) { s->failed_pc=0x0c0933fcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0933fe;
P_0c0933fe: /* original f3f6, guest PC 0x0c0933fe */
if(!s->budget--) { s->failed_pc=0x0c0933feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093400;
P_0c093400: /* original e028, guest PC 0x0c093400 */
if(!s->budget--) { s->failed_pc=0x0c093400u; return 0; }
r[0]=0x00000028u;
goto P_0c093402;
P_0c093402: /* original ff37, guest PC 0x0c093402 */
if(!s->budget--) { s->failed_pc=0x0c093402u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093404;
P_0c093404: /* original e020, guest PC 0x0c093404 */
if(!s->budget--) { s->failed_pc=0x0c093404u; return 0; }
r[0]=0x00000020u;
goto P_0c093406;
P_0c093406: /* original f3f6, guest PC 0x0c093406 */
if(!s->budget--) { s->failed_pc=0x0c093406u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093408;
P_0c093408: /* original e02c, guest PC 0x0c093408 */
if(!s->budget--) { s->failed_pc=0x0c093408u; return 0; }
r[0]=0x0000002cu;
goto P_0c09340a;
P_0c09340a: /* original ff37, guest PC 0x0c09340a */
if(!s->budget--) { s->failed_pc=0x0c09340au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09340c;
P_0c09340c: /* original d33a, guest PC 0x0c09340c */
if(!s->budget--) { s->failed_pc=0x0c09340cu; return 0; }
r[3]=read(ram,0x0c0934f8u,4);
goto P_0c09340e;
P_0c09340e: /* original 432b, guest PC 0x0c09340e */
if(!s->budget--) { s->failed_pc=0x0c09340eu; return 0; }
target=r[3];
r[14]+=r[12];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c093410: /* original 3ecc, guest PC 0x0c093410 */
if(!s->budget--) { s->failed_pc=0x0c093410u; return 0; }
r[14]+=r[12];
return vf3_matrix_family(0x0c093412u,s,ram);
P_0c09abc4: /* original d512, guest PC 0x0c09abc4 */
if(!s->budget--) { s->failed_pc=0x0c09abc4u; return 0; }
r[5]=read(ram,0x0c09ac10u,4);
goto P_0c09abc6;
P_0c09abc6: /* original e620, guest PC 0x0c09abc6 */
if(!s->budget--) { s->failed_pc=0x0c09abc6u; return 0; }
r[6]=0x00000020u;
goto P_0c09abc8;
P_0c09abc8: /* original 845b, guest PC 0x0c09abc8 */
if(!s->budget--) { s->failed_pc=0x0c09abc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+11,1);
goto P_0c09abca;
P_0c09abca: /* original 640c, guest PC 0x0c09abca */
if(!s->budget--) { s->failed_pc=0x0c09abcau; return 0; }
r[4]=r[0]&255u;
goto P_0c09abcc;
P_0c09abcc: /* original 3463, guest PC 0x0c09abcc */
if(!s->budget--) { s->failed_pc=0x0c09abccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abce;
P_0c09abce: /* original 8b18, guest PC 0x0c09abce */
if(!s->budget--) { s->failed_pc=0x0c09abceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ac02; }
goto P_0c09abd0;
P_0c09abd0: /* original 9019, guest PC 0x0c09abd0 */
if(!s->budget--) { s->failed_pc=0x0c09abd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac06u,2);
goto P_0c09abd2;
P_0c09abd2: /* original 035e, guest PC 0x0c09abd2 */
if(!s->budget--) { s->failed_pc=0x0c09abd2u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c09abd4;
P_0c09abd4: /* original 2368, guest PC 0x0c09abd4 */
if(!s->budget--) { s->failed_pc=0x0c09abd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c09abd6;
P_0c09abd6: /* original 8914, guest PC 0x0c09abd6 */
if(!s->budget--) { s->failed_pc=0x0c09abd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abd8;
P_0c09abd8: /* original 9017, guest PC 0x0c09abd8 */
if(!s->budget--) { s->failed_pc=0x0c09abd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0au,2);
goto P_0c09abda;
P_0c09abda: /* original 9315, guest PC 0x0c09abda */
if(!s->budget--) { s->failed_pc=0x0c09abdau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac08u,2);
goto P_0c09abdc;
P_0c09abdc: /* original 025e, guest PC 0x0c09abdc */
if(!s->budget--) { s->failed_pc=0x0c09abdcu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abde;
P_0c09abde: /* original 2238, guest PC 0x0c09abde */
if(!s->budget--) { s->failed_pc=0x0c09abdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abe0;
P_0c09abe0: /* original 8f05, guest PC 0x0c09abe0 */
if(!s->budget--) { s->failed_pc=0x0c09abe0u; return 0; }
cond=r[17]&1u;
r[7]=0x00000032u;
if(!cond) { goto P_0c09abee; }
goto P_0c09abe4;
P_0c09abe2: /* original e732, guest PC 0x0c09abe2 */
if(!s->budget--) { s->failed_pc=0x0c09abe2u; return 0; }
r[7]=0x00000032u;
goto P_0c09abe4;
P_0c09abe4: /* original 7401, guest PC 0x0c09abe4 */
if(!s->budget--) { s->failed_pc=0x0c09abe4u; return 0; }
r[4]+=0x00000001u;
goto P_0c09abe6;
P_0c09abe6: /* original 3477, guest PC 0x0c09abe6 */
if(!s->budget--) { s->failed_pc=0x0c09abe6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[7])!=0);
goto P_0c09abe8;
P_0c09abe8: /* original 8b09, guest PC 0x0c09abe8 */
if(!s->budget--) { s->failed_pc=0x0c09abe8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09abfe; }
goto P_0c09abea;
P_0c09abea: /* original a008, guest PC 0x0c09abea */
if(!s->budget--) { s->failed_pc=0x0c09abeau; return 0; }
r[4]=r[6];
goto P_0c09abfe;
P_0c09abec: /* original 6463, guest PC 0x0c09abec */
if(!s->budget--) { s->failed_pc=0x0c09abecu; return 0; }
r[4]=r[6];
goto P_0c09abee;
P_0c09abee: /* original 025e, guest PC 0x0c09abee */
if(!s->budget--) { s->failed_pc=0x0c09abeeu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abf0;
P_0c09abf0: /* original 930c, guest PC 0x0c09abf0 */
if(!s->budget--) { s->failed_pc=0x0c09abf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0cu,2);
goto P_0c09abf2;
P_0c09abf2: /* original 2238, guest PC 0x0c09abf2 */
if(!s->budget--) { s->failed_pc=0x0c09abf2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abf4;
P_0c09abf4: /* original 8905, guest PC 0x0c09abf4 */
if(!s->budget--) { s->failed_pc=0x0c09abf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abf6;
P_0c09abf6: /* original 74fd, guest PC 0x0c09abf6 */
if(!s->budget--) { s->failed_pc=0x0c09abf6u; return 0; }
r[4]+=0xfffffffdu;
goto P_0c09abf8;
P_0c09abf8: /* original 3463, guest PC 0x0c09abf8 */
if(!s->budget--) { s->failed_pc=0x0c09abf8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abfa;
P_0c09abfa: /* original 8900, guest PC 0x0c09abfa */
if(!s->budget--) { s->failed_pc=0x0c09abfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09abfe; }
goto P_0c09abfc;
P_0c09abfc: /* original 6473, guest PC 0x0c09abfc */
if(!s->budget--) { s->failed_pc=0x0c09abfcu; return 0; }
r[4]=r[7];
goto P_0c09abfe;
P_0c09abfe: /* original 6043, guest PC 0x0c09abfe */
if(!s->budget--) { s->failed_pc=0x0c09abfeu; return 0; }
r[0]=r[4];
goto P_0c09ac00;
P_0c09ac00: /* original 805b, guest PC 0x0c09ac00 */
if(!s->budget--) { s->failed_pc=0x0c09ac00u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c09ac02;
P_0c09ac02: /* original 000b, guest PC 0x0c09ac02 */
if(!s->budget--) { s->failed_pc=0x0c09ac02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09ac04: /* original 0009, guest PC 0x0c09ac04 */
if(!s->budget--) { s->failed_pc=0x0c09ac04u; return 0; }
return vf3_matrix_family(0x0c09ac06u,s,ram);
P_0c09d844: /* original 4f22, guest PC 0x0c09d844 */
if(!s->budget--) { s->failed_pc=0x0c09d844u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d846;
P_0c09d846: /* original 7fec, guest PC 0x0c09d846 */
if(!s->budget--) { s->failed_pc=0x0c09d846u; return 0; }
r[15]+=0xffffffecu;
goto P_0c09d848;
P_0c09d848: /* original 2f52, guest PC 0x0c09d848 */
if(!s->budget--) { s->failed_pc=0x0c09d848u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09d84a;
P_0c09d84a: /* original 9096, guest PC 0x0c09d84a */
if(!s->budget--) { s->failed_pc=0x0c09d84au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d97au,2);
goto P_0c09d84c;
P_0c09d84c: /* original 084e, guest PC 0x0c09d84c */
if(!s->budget--) { s->failed_pc=0x0c09d84cu; return 0; }
r[8]=read(ram,r[4]+r[0],4);
goto P_0c09d84e;
P_0c09d84e: /* original 6382, guest PC 0x0c09d84e */
if(!s->budget--) { s->failed_pc=0x0c09d84eu; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c09d850;
P_0c09d850: /* original 1f34, guest PC 0x0c09d850 */
if(!s->budget--) { s->failed_pc=0x0c09d850u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c09d852;
P_0c09d852: /* original 63f2, guest PC 0x0c09d852 */
if(!s->budget--) { s->failed_pc=0x0c09d852u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09d854;
P_0c09d854: /* original 5e82, guest PC 0x0c09d854 */
if(!s->budget--) { s->failed_pc=0x0c09d854u; return 0; }
r[14]=read(ram,r[8]+8,4);
goto P_0c09d856;
P_0c09d856: /* original 6232, guest PC 0x0c09d856 */
if(!s->budget--) { s->failed_pc=0x0c09d856u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09d858;
P_0c09d858: /* original 5c81, guest PC 0x0c09d858 */
if(!s->budget--) { s->failed_pc=0x0c09d858u; return 0; }
r[12]=read(ram,r[8]+4,4);
goto P_0c09d85a;
P_0c09d85a: /* original 1f21, guest PC 0x0c09d85a */
if(!s->budget--) { s->failed_pc=0x0c09d85au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c09d85c;
P_0c09d85c: /* original a0b1, guest PC 0x0c09d85c */
if(!s->budget--) { s->failed_pc=0x0c09d85cu; return 0; }
r[9]=0x00000000u;
goto P_0c09d9c2;
P_0c09d85e: /* original e900, guest PC 0x0c09d85e */
if(!s->budget--) { s->failed_pc=0x0c09d85eu; return 0; }
r[9]=0x00000000u;
goto P_0c09d860;
P_0c09d860: /* original 6583, guest PC 0x0c09d860 */
if(!s->budget--) { s->failed_pc=0x0c09d860u; return 0; }
r[5]=r[8];
goto P_0c09d862;
P_0c09d862: /* original 750c, guest PC 0x0c09d862 */
if(!s->budget--) { s->failed_pc=0x0c09d862u; return 0; }
r[5]+=0x0000000cu;
goto P_0c09d864;
P_0c09d864: /* original 359c, guest PC 0x0c09d864 */
if(!s->budget--) { s->failed_pc=0x0c09d864u; return 0; }
r[5]+=r[9];
goto P_0c09d866;
P_0c09d866: /* original 9789, guest PC 0x0c09d866 */
if(!s->budget--) { s->failed_pc=0x0c09d866u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d97cu,2);
goto P_0c09d868;
P_0c09d868: /* original 6550, guest PC 0x0c09d868 */
if(!s->budget--) { s->failed_pc=0x0c09d868u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09d86a;
P_0c09d86a: /* original 6053, guest PC 0x0c09d86a */
if(!s->budget--) { s->failed_pc=0x0c09d86au; return 0; }
r[0]=r[5];
goto P_0c09d86c;
P_0c09d86c: /* original 307c, guest PC 0x0c09d86c */
if(!s->budget--) { s->failed_pc=0x0c09d86cu; return 0; }
r[0]+=r[7];
goto P_0c09d86e;
P_0c09d86e: /* original 675c, guest PC 0x0c09d86e */
if(!s->budget--) { s->failed_pc=0x0c09d86eu; return 0; }
r[7]=r[5]&255u;
goto P_0c09d870;
P_0c09d870: /* original 80f8, guest PC 0x0c09d870 */
if(!s->budget--) { s->failed_pc=0x0c09d870u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c09d872;
P_0c09d872: /* original 6073, guest PC 0x0c09d872 */
if(!s->budget--) { s->failed_pc=0x0c09d872u; return 0; }
r[0]=r[7];
goto P_0c09d874;
P_0c09d874: /* original 8801, guest PC 0x0c09d874 */
if(!s->budget--) { s->failed_pc=0x0c09d874u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09d876;
P_0c09d876: /* original 8f02, guest PC 0x0c09d876 */
if(!s->budget--) { s->failed_pc=0x0c09d876u; return 0; }
cond=r[17]&1u;
fr[4]=0;
if(!cond) { goto P_0c09d87e; }
goto P_0c09d87a;
P_0c09d878: /* original f48d, guest PC 0x0c09d878 */
if(!s->budget--) { s->failed_pc=0x0c09d878u; return 0; }
fr[4]=0;
goto P_0c09d87a;
P_0c09d87a: /* original a09c, guest PC 0x0c09d87a */
if(!s->budget--) { s->failed_pc=0x0c09d87au; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c09d9b6;
P_0c09d87c: /* original f4e9, guest PC 0x0c09d87c */
if(!s->budget--) { s->failed_pc=0x0c09d87cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c09d87e;
P_0c09d87e: /* original e501, guest PC 0x0c09d87e */
if(!s->budget--) { s->failed_pc=0x0c09d87eu; return 0; }
r[5]=0x00000001u;
goto P_0c09d880;
P_0c09d880: /* original 3753, guest PC 0x0c09d880 */
if(!s->budget--) { s->failed_pc=0x0c09d880u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[5])!=0);
goto P_0c09d882;
P_0c09d882: /* original 8901, guest PC 0x0c09d882 */
if(!s->budget--) { s->failed_pc=0x0c09d882u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d888; }
goto P_0c09d884;
P_0c09d884: /* original a097, guest PC 0x0c09d884 */
if(!s->budget--) { s->failed_pc=0x0c09d884u; return 0; }
goto P_0c09d9b6;
P_0c09d886: /* original 0009, guest PC 0x0c09d886 */
if(!s->budget--) { s->failed_pc=0x0c09d886u; return 0; }
goto P_0c09d888;
P_0c09d888: /* original 55f4, guest PC 0x0c09d888 */
if(!s->budget--) { s->failed_pc=0x0c09d888u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c09d88a;
P_0c09d88a: /* original ed00, guest PC 0x0c09d88a */
if(!s->budget--) { s->failed_pc=0x0c09d88au; return 0; }
r[13]=0x00000000u;
goto P_0c09d88c;
P_0c09d88c: /* original 7501, guest PC 0x0c09d88c */
if(!s->budget--) { s->failed_pc=0x0c09d88cu; return 0; }
r[5]+=0x00000001u;
goto P_0c09d88e;
P_0c09d88e: /* original 1f54, guest PC 0x0c09d88e */
if(!s->budget--) { s->failed_pc=0x0c09d88eu; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c09d890;
P_0c09d890: /* original 9775, guest PC 0x0c09d890 */
if(!s->budget--) { s->failed_pc=0x0c09d890u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d97eu,2);
goto P_0c09d892;
P_0c09d892: /* original 6550, guest PC 0x0c09d892 */
if(!s->budget--) { s->failed_pc=0x0c09d892u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09d894;
P_0c09d894: /* original 1f73, guest PC 0x0c09d894 */
if(!s->budget--) { s->failed_pc=0x0c09d894u; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d896;
P_0c09d896: /* original 9073, guest PC 0x0c09d896 */
if(!s->budget--) { s->failed_pc=0x0c09d896u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d980u,2);
goto P_0c09d898;
P_0c09d898: /* original 655c, guest PC 0x0c09d898 */
if(!s->budget--) { s->failed_pc=0x0c09d898u; return 0; }
r[5]=r[5]&255u;
goto P_0c09d89a;
P_0c09d89a: /* original 2558, guest PC 0x0c09d89a */
if(!s->budget--) { s->failed_pc=0x0c09d89au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09d89c;
P_0c09d89c: /* original 074d, guest PC 0x0c09d89c */
if(!s->budget--) { s->failed_pc=0x0c09d89cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09d89e;
P_0c09d89e: /* original 677d, guest PC 0x0c09d89e */
if(!s->budget--) { s->failed_pc=0x0c09d89eu; return 0; }
r[7]=r[7]&65535u;
goto P_0c09d8a0;
P_0c09d8a0: /* original 8d29, guest PC 0x0c09d8a0 */
if(!s->budget--) { s->failed_pc=0x0c09d8a0u; return 0; }
cond=r[17]&1u;
r[7]<<=8;
if(cond) { goto P_0c09d8f6; }
goto P_0c09d8a4;
P_0c09d8a2: /* original 4718, guest PC 0x0c09d8a2 */
if(!s->budget--) { s->failed_pc=0x0c09d8a2u; return 0; }
r[7]<<=8;
goto P_0c09d8a4;
P_0c09d8a4: /* original 67d3, guest PC 0x0c09d8a4 */
if(!s->budget--) { s->failed_pc=0x0c09d8a4u; return 0; }
r[7]=r[13];
goto P_0c09d8a6;
P_0c09d8a6: /* original 4700, guest PC 0x0c09d8a6 */
if(!s->budget--) { s->failed_pc=0x0c09d8a6u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c09d8a8;
P_0c09d8a8: /* original 37cc, guest PC 0x0c09d8a8 */
if(!s->budget--) { s->failed_pc=0x0c09d8a8u; return 0; }
r[7]+=r[12];
goto P_0c09d8aa;
P_0c09d8aa: /* original 35d7, guest PC 0x0c09d8aa */
if(!s->budget--) { s->failed_pc=0x0c09d8aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[13])!=0);
goto P_0c09d8ac;
P_0c09d8ac: /* original 6771, guest PC 0x0c09d8ac */
if(!s->budget--) { s->failed_pc=0x0c09d8acu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c09d8ae;
P_0c09d8ae: /* original 677d, guest PC 0x0c09d8ae */
if(!s->budget--) { s->failed_pc=0x0c09d8aeu; return 0; }
r[7]=r[7]&65535u;
goto P_0c09d8b0;
P_0c09d8b0: /* original 8f1d, guest PC 0x0c09d8b0 */
if(!s->budget--) { s->failed_pc=0x0c09d8b0u; return 0; }
cond=r[17]&1u;
r[7]<<=8;
if(!cond) { goto P_0c09d8ee; }
goto P_0c09d8b4;
P_0c09d8b2: /* original 4718, guest PC 0x0c09d8b2 */
if(!s->budget--) { s->failed_pc=0x0c09d8b2u; return 0; }
r[7]<<=8;
goto P_0c09d8b4;
P_0c09d8b4: /* original 3767, guest PC 0x0c09d8b4 */
if(!s->budget--) { s->failed_pc=0x0c09d8b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[6])!=0);
goto P_0c09d8b6;
P_0c09d8b6: /* original 891e, guest PC 0x0c09d8b6 */
if(!s->budget--) { s->failed_pc=0x0c09d8b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d8f6; }
goto P_0c09d8b8;
P_0c09d8b8: /* original 3670, guest PC 0x0c09d8b8 */
if(!s->budget--) { s->failed_pc=0x0c09d8b8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[7])!=0);
goto P_0c09d8ba;
P_0c09d8ba: /* original 8902, guest PC 0x0c09d8ba */
if(!s->budget--) { s->failed_pc=0x0c09d8bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d8c2; }
goto P_0c09d8bc;
P_0c09d8bc: /* original 7d01, guest PC 0x0c09d8bc */
if(!s->budget--) { s->failed_pc=0x0c09d8bcu; return 0; }
r[13]+=0x00000001u;
goto P_0c09d8be;
P_0c09d8be: /* original aff1, guest PC 0x0c09d8be */
if(!s->budget--) { s->failed_pc=0x0c09d8beu; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d8a4;
P_0c09d8c0: /* original 1f73, guest PC 0x0c09d8c0 */
if(!s->budget--) { s->failed_pc=0x0c09d8c0u; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d8c2;
P_0c09d8c2: /* original 84f8, guest PC 0x0c09d8c2 */
if(!s->budget--) { s->failed_pc=0x0c09d8c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c09d8c4;
P_0c09d8c4: /* original 6253, guest PC 0x0c09d8c4 */
if(!s->budget--) { s->failed_pc=0x0c09d8c4u; return 0; }
r[2]=r[5];
goto P_0c09d8c6;
P_0c09d8c6: /* original 4200, guest PC 0x0c09d8c6 */
if(!s->budget--) { s->failed_pc=0x0c09d8c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09d8c8;
P_0c09d8c8: /* original 67d3, guest PC 0x0c09d8c8 */
if(!s->budget--) { s->failed_pc=0x0c09d8c8u; return 0; }
r[7]=r[13];
goto P_0c09d8ca;
P_0c09d8ca: /* original 2008, guest PC 0x0c09d8ca */
if(!s->budget--) { s->failed_pc=0x0c09d8cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09d8cc;
P_0c09d8cc: /* original 3c2c, guest PC 0x0c09d8cc */
if(!s->budget--) { s->failed_pc=0x0c09d8ccu; return 0; }
r[12]+=r[2];
goto P_0c09d8ce;
P_0c09d8ce: /* original 8d07, guest PC 0x0c09d8ce */
if(!s->budget--) { s->failed_pc=0x0c09d8ceu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(cond) { goto P_0c09d8e0; }
goto P_0c09d8d2;
P_0c09d8d0: /* original 7701, guest PC 0x0c09d8d0 */
if(!s->budget--) { s->failed_pc=0x0c09d8d0u; return 0; }
r[7]+=0x00000001u;
goto P_0c09d8d2;
P_0c09d8d2: /* original 6d53, guest PC 0x0c09d8d2 */
if(!s->budget--) { s->failed_pc=0x0c09d8d2u; return 0; }
r[13]=r[5];
goto P_0c09d8d4;
P_0c09d8d4: /* original 6b73, guest PC 0x0c09d8d4 */
if(!s->budget--) { s->failed_pc=0x0c09d8d4u; return 0; }
r[11]=r[7];
goto P_0c09d8d6;
P_0c09d8d6: /* original 3d5c, guest PC 0x0c09d8d6 */
if(!s->budget--) { s->failed_pc=0x0c09d8d6u; return 0; }
r[13]+=r[5];
goto P_0c09d8d8;
P_0c09d8d8: /* original 35dc, guest PC 0x0c09d8d8 */
if(!s->budget--) { s->failed_pc=0x0c09d8d8u; return 0; }
r[5]+=r[13];
goto P_0c09d8da;
P_0c09d8da: /* original 4b00, guest PC 0x0c09d8da */
if(!s->budget--) { s->failed_pc=0x0c09d8dau; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c09d8dc;
P_0c09d8dc: /* original 7502, guest PC 0x0c09d8dc */
if(!s->budget--) { s->failed_pc=0x0c09d8dcu; return 0; }
r[5]+=0x00000002u;
goto P_0c09d8de;
P_0c09d8de: /* original 37bc, guest PC 0x0c09d8de */
if(!s->budget--) { s->failed_pc=0x0c09d8deu; return 0; }
r[7]+=r[11];
goto P_0c09d8e0;
P_0c09d8e0: /* original 4708, guest PC 0x0c09d8e0 */
if(!s->budget--) { s->failed_pc=0x0c09d8e0u; return 0; }
r[7]<<=2;
goto P_0c09d8e2;
P_0c09d8e2: /* original 37ec, guest PC 0x0c09d8e2 */
if(!s->budget--) { s->failed_pc=0x0c09d8e2u; return 0; }
r[7]+=r[14];
goto P_0c09d8e4;
P_0c09d8e4: /* original f478, guest PC 0x0c09d8e4 */
if(!s->budget--) { s->failed_pc=0x0c09d8e4u; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
goto P_0c09d8e6;
P_0c09d8e6: /* original 7502, guest PC 0x0c09d8e6 */
if(!s->budget--) { s->failed_pc=0x0c09d8e6u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d8e8;
P_0c09d8e8: /* original 4508, guest PC 0x0c09d8e8 */
if(!s->budget--) { s->failed_pc=0x0c09d8e8u; return 0; }
r[5]<<=2;
goto P_0c09d8ea;
P_0c09d8ea: /* original a064, guest PC 0x0c09d8ea */
if(!s->budget--) { s->failed_pc=0x0c09d8eau; return 0; }
r[14]+=r[5];
goto P_0c09d9b6;
P_0c09d8ec: /* original 3e5c, guest PC 0x0c09d8ec */
if(!s->budget--) { s->failed_pc=0x0c09d8ecu; return 0; }
r[14]+=r[5];
goto P_0c09d8ee;
P_0c09d8ee: /* original 9047, guest PC 0x0c09d8ee */
if(!s->budget--) { s->failed_pc=0x0c09d8eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d980u,2);
goto P_0c09d8f0;
P_0c09d8f0: /* original 074d, guest PC 0x0c09d8f0 */
if(!s->budget--) { s->failed_pc=0x0c09d8f0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09d8f2;
P_0c09d8f2: /* original 677d, guest PC 0x0c09d8f2 */
if(!s->budget--) { s->failed_pc=0x0c09d8f2u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09d8f4;
P_0c09d8f4: /* original 4718, guest PC 0x0c09d8f4 */
if(!s->budget--) { s->failed_pc=0x0c09d8f4u; return 0; }
r[7]<<=8;
goto P_0c09d8f6;
P_0c09d8f6: /* original 84f8, guest PC 0x0c09d8f6 */
if(!s->budget--) { s->failed_pc=0x0c09d8f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c09d8f8;
P_0c09d8f8: /* original 6b73, guest PC 0x0c09d8f8 */
if(!s->budget--) { s->failed_pc=0x0c09d8f8u; return 0; }
r[11]=r[7];
goto P_0c09d8fa;
P_0c09d8fa: /* original 53f3, guest PC 0x0c09d8fa */
if(!s->budget--) { s->failed_pc=0x0c09d8fau; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c09d8fc;
P_0c09d8fc: /* original 6163, guest PC 0x0c09d8fc */
if(!s->budget--) { s->failed_pc=0x0c09d8fcu; return 0; }
r[1]=r[6];
goto P_0c09d8fe;
P_0c09d8fe: /* original 2008, guest PC 0x0c09d8fe */
if(!s->budget--) { s->failed_pc=0x0c09d8feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09d900;
P_0c09d900: /* original 3b38, guest PC 0x0c09d900 */
if(!s->budget--) { s->failed_pc=0x0c09d900u; return 0; }
r[11]-=r[3];
goto P_0c09d902;
P_0c09d902: /* original 8d43, guest PC 0x0c09d902 */
if(!s->budget--) { s->failed_pc=0x0c09d902u; return 0; }
cond=r[17]&1u;
r[1]-=r[3];
if(cond) { goto P_0c09d98c; }
goto P_0c09d906;
P_0c09d904: /* original 3138, guest PC 0x0c09d904 */
if(!s->budget--) { s->failed_pc=0x0c09d904u; return 0; }
r[1]-=r[3];
goto P_0c09d906;
P_0c09d906: /* original 415a, guest PC 0x0c09d906 */
if(!s->budget--) { s->failed_pc=0x0c09d906u; return 0; }
r[53]=r[1];
goto P_0c09d908;
P_0c09d908: /* original 67d3, guest PC 0x0c09d908 */
if(!s->budget--) { s->failed_pc=0x0c09d908u; return 0; }
r[7]=r[13];
goto P_0c09d90a;
P_0c09d90a: /* original 4700, guest PC 0x0c09d90a */
if(!s->budget--) { s->failed_pc=0x0c09d90au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c09d90c;
P_0c09d90c: /* original 62d3, guest PC 0x0c09d90c */
if(!s->budget--) { s->failed_pc=0x0c09d90cu; return 0; }
r[2]=r[13];
goto P_0c09d90e;
P_0c09d90e: /* original 372c, guest PC 0x0c09d90e */
if(!s->budget--) { s->failed_pc=0x0c09d90eu; return 0; }
r[7]+=r[2];
goto P_0c09d910;
P_0c09d910: /* original f32d, guest PC 0x0c09d910 */
if(!s->budget--) { s->failed_pc=0x0c09d910u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d912;
P_0c09d912: /* original 4b5a, guest PC 0x0c09d912 */
if(!s->budget--) { s->failed_pc=0x0c09d912u; return 0; }
r[53]=r[11];
goto P_0c09d914;
P_0c09d914: /* original 4708, guest PC 0x0c09d914 */
if(!s->budget--) { s->failed_pc=0x0c09d914u; return 0; }
r[7]<<=2;
goto P_0c09d916;
P_0c09d916: /* original 37ec, guest PC 0x0c09d916 */
if(!s->budget--) { s->failed_pc=0x0c09d916u; return 0; }
r[7]+=r[14];
goto P_0c09d918;
P_0c09d918: /* original f22d, guest PC 0x0c09d918 */
if(!s->budget--) { s->failed_pc=0x0c09d918u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d91a;
P_0c09d91a: /* original e004, guest PC 0x0c09d91a */
if(!s->budget--) { s->failed_pc=0x0c09d91au; return 0; }
r[0]=0x00000004u;
goto P_0c09d91c;
P_0c09d91c: /* original f876, guest PC 0x0c09d91c */
if(!s->budget--) { s->failed_pc=0x0c09d91cu; return 0; }
vf3_matrix_load(s,ram,8,r[7]+r[0]);
goto P_0c09d91e;
P_0c09d91e: /* original e008, guest PC 0x0c09d91e */
if(!s->budget--) { s->failed_pc=0x0c09d91eu; return 0; }
r[0]=0x00000008u;
goto P_0c09d920;
P_0c09d920: /* original f53c, guest PC 0x0c09d920 */
if(!s->budget--) { s->failed_pc=0x0c09d920u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c09d922;
P_0c09d922: /* original f976, guest PC 0x0c09d922 */
if(!s->budget--) { s->failed_pc=0x0c09d922u; return 0; }
vf3_matrix_load(s,ram,9,r[7]+r[0]);
goto P_0c09d924;
P_0c09d924: /* original e00c, guest PC 0x0c09d924 */
if(!s->budget--) { s->failed_pc=0x0c09d924u; return 0; }
r[0]=0x0000000cu;
goto P_0c09d926;
P_0c09d926: /* original f176, guest PC 0x0c09d926 */
if(!s->budget--) { s->failed_pc=0x0c09d926u; return 0; }
vf3_matrix_load(s,ram,1,r[7]+r[0]);
goto P_0c09d928;
P_0c09d928: /* original c716, guest PC 0x0c09d928 */
if(!s->budget--) { s->failed_pc=0x0c09d928u; return 0; }
r[0]=0x0c09d984u;
goto P_0c09d92a;
P_0c09d92a: /* original f523, guest PC 0x0c09d92a */
if(!s->budget--) { s->failed_pc=0x0c09d92au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c09d92c;
P_0c09d92c: /* original f408, guest PC 0x0c09d92c */
if(!s->budget--) { s->failed_pc=0x0c09d92cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09d92e;
P_0c09d92e: /* original c716, guest PC 0x0c09d92e */
if(!s->budget--) { s->failed_pc=0x0c09d92eu; return 0; }
r[0]=0x0c09d988u;
goto P_0c09d930;
P_0c09d930: /* original fa3c, guest PC 0x0c09d930 */
if(!s->budget--) { s->failed_pc=0x0c09d930u; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c09d932;
P_0c09d932: /* original f942, guest PC 0x0c09d932 */
if(!s->budget--) { s->failed_pc=0x0c09d932u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'*');
goto P_0c09d934;
P_0c09d934: /* original f708, guest PC 0x0c09d934 */
if(!s->budget--) { s->failed_pc=0x0c09d934u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c09d936;
P_0c09d936: /* original f842, guest PC 0x0c09d936 */
if(!s->budget--) { s->failed_pc=0x0c09d936u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c09d938;
P_0c09d938: /* original fb78, guest PC 0x0c09d938 */
if(!s->budget--) { s->failed_pc=0x0c09d938u; return 0; }
vf3_matrix_load(s,ram,11,r[7]);
goto P_0c09d93a;
P_0c09d93a: /* original f49c, guest PC 0x0c09d93a */
if(!s->budget--) { s->failed_pc=0x0c09d93au; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c09d93c;
P_0c09d93c: /* original f08c, guest PC 0x0c09d93c */
if(!s->budget--) { s->failed_pc=0x0c09d93cu; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c09d93e;
P_0c09d93e: /* original f65c, guest PC 0x0c09d93e */
if(!s->budget--) { s->failed_pc=0x0c09d93eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09d940;
P_0c09d940: /* original f452, guest PC 0x0c09d940 */
if(!s->budget--) { s->failed_pc=0x0c09d940u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09d942;
P_0c09d942: /* original f670, guest PC 0x0c09d942 */
if(!s->budget--) { s->failed_pc=0x0c09d942u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c09d944;
P_0c09d944: /* original f34c, guest PC 0x0c09d944 */
if(!s->budget--) { s->failed_pc=0x0c09d944u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09d946;
P_0c09d946: /* original f36e, guest PC 0x0c09d946 */
if(!s->budget--) { s->failed_pc=0x0c09d946u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c09d948;
P_0c09d948: /* original f0ac, guest PC 0x0c09d948 */
if(!s->budget--) { s->failed_pc=0x0c09d948u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c09d94a;
P_0c09d94a: /* original f8bc, guest PC 0x0c09d94a */
if(!s->budget--) { s->failed_pc=0x0c09d94au; return 0; }
vf3_matrix_move(s,8,11);
goto P_0c09d94c;
P_0c09d94c: /* original 6253, guest PC 0x0c09d94c */
if(!s->budget--) { s->failed_pc=0x0c09d94cu; return 0; }
r[2]=r[5];
goto P_0c09d94e;
P_0c09d94e: /* original 4200, guest PC 0x0c09d94e */
if(!s->budget--) { s->failed_pc=0x0c09d94eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09d950;
P_0c09d950: /* original 6153, guest PC 0x0c09d950 */
if(!s->budget--) { s->failed_pc=0x0c09d950u; return 0; }
r[1]=r[5];
goto P_0c09d952;
P_0c09d952: /* original 3c2c, guest PC 0x0c09d952 */
if(!s->budget--) { s->failed_pc=0x0c09d952u; return 0; }
r[12]+=r[2];
goto P_0c09d954;
P_0c09d954: /* original 6253, guest PC 0x0c09d954 */
if(!s->budget--) { s->failed_pc=0x0c09d954u; return 0; }
r[2]=r[5];
goto P_0c09d956;
P_0c09d956: /* original f43c, guest PC 0x0c09d956 */
if(!s->budget--) { s->failed_pc=0x0c09d956u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09d958;
P_0c09d958: /* original f462, guest PC 0x0c09d958 */
if(!s->budget--) { s->failed_pc=0x0c09d958u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c09d95a;
P_0c09d95a: /* original 4100, guest PC 0x0c09d95a */
if(!s->budget--) { s->failed_pc=0x0c09d95au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c09d95c;
P_0c09d95c: /* original 312c, guest PC 0x0c09d95c */
if(!s->budget--) { s->failed_pc=0x0c09d95cu; return 0; }
r[1]+=r[2];
goto P_0c09d95e;
P_0c09d95e: /* original 6513, guest PC 0x0c09d95e */
if(!s->budget--) { s->failed_pc=0x0c09d95eu; return 0; }
r[5]=r[1];
goto P_0c09d960;
P_0c09d960: /* original f84e, guest PC 0x0c09d960 */
if(!s->budget--) { s->failed_pc=0x0c09d960u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[4],fr[8],r[18]);
goto P_0c09d962;
P_0c09d962: /* original f46c, guest PC 0x0c09d962 */
if(!s->budget--) { s->failed_pc=0x0c09d962u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c09d964;
P_0c09d964: /* original f460, guest PC 0x0c09d964 */
if(!s->budget--) { s->failed_pc=0x0c09d964u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c09d966;
P_0c09d966: /* original f6bc, guest PC 0x0c09d966 */
if(!s->budget--) { s->failed_pc=0x0c09d966u; return 0; }
vf3_matrix_move(s,6,11);
goto P_0c09d968;
P_0c09d968: /* original f611, guest PC 0x0c09d968 */
if(!s->budget--) { s->failed_pc=0x0c09d968u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'-');
goto P_0c09d96a;
P_0c09d96a: /* original f05c, guest PC 0x0c09d96a */
if(!s->budget--) { s->failed_pc=0x0c09d96au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09d96c;
P_0c09d96c: /* original f470, guest PC 0x0c09d96c */
if(!s->budget--) { s->failed_pc=0x0c09d96cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c09d96e;
P_0c09d96e: /* original f462, guest PC 0x0c09d96e */
if(!s->budget--) { s->failed_pc=0x0c09d96eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c09d970;
P_0c09d970: /* original f452, guest PC 0x0c09d970 */
if(!s->budget--) { s->failed_pc=0x0c09d970u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09d972;
P_0c09d972: /* original f84e, guest PC 0x0c09d972 */
if(!s->budget--) { s->failed_pc=0x0c09d972u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[4],fr[8],r[18]);
goto P_0c09d974;
P_0c09d974: /* original f48c, guest PC 0x0c09d974 */
if(!s->budget--) { s->failed_pc=0x0c09d974u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c09d976;
P_0c09d976: /* original a01b, guest PC 0x0c09d976 */
if(!s->budget--) { s->failed_pc=0x0c09d976u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d9b0;
P_0c09d978: /* original 7502, guest PC 0x0c09d978 */
if(!s->budget--) { s->failed_pc=0x0c09d978u; return 0; }
r[5]+=0x00000002u;
return vf3_matrix_family(0x0c09d97au,s,ram);
P_0c09d98c: /* original 4b5a, guest PC 0x0c09d98c */
if(!s->budget--) { s->failed_pc=0x0c09d98cu; return 0; }
r[53]=r[11];
goto P_0c09d98e;
P_0c09d98e: /* original 67d3, guest PC 0x0c09d98e */
if(!s->budget--) { s->failed_pc=0x0c09d98eu; return 0; }
r[7]=r[13];
goto P_0c09d990;
P_0c09d990: /* original 4708, guest PC 0x0c09d990 */
if(!s->budget--) { s->failed_pc=0x0c09d990u; return 0; }
r[7]<<=2;
goto P_0c09d992;
P_0c09d992: /* original 6253, guest PC 0x0c09d992 */
if(!s->budget--) { s->failed_pc=0x0c09d992u; return 0; }
r[2]=r[5];
goto P_0c09d994;
P_0c09d994: /* original 37ec, guest PC 0x0c09d994 */
if(!s->budget--) { s->failed_pc=0x0c09d994u; return 0; }
r[7]+=r[14];
goto P_0c09d996;
P_0c09d996: /* original f32d, guest PC 0x0c09d996 */
if(!s->budget--) { s->failed_pc=0x0c09d996u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d998;
P_0c09d998: /* original 415a, guest PC 0x0c09d998 */
if(!s->budget--) { s->failed_pc=0x0c09d998u; return 0; }
r[53]=r[1];
goto P_0c09d99a;
P_0c09d99a: /* original f479, guest PC 0x0c09d99a */
if(!s->budget--) { s->failed_pc=0x0c09d99au; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c09d99c;
P_0c09d99c: /* original 4200, guest PC 0x0c09d99c */
if(!s->budget--) { s->failed_pc=0x0c09d99cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09d99e;
P_0c09d99e: /* original 3c2c, guest PC 0x0c09d99e */
if(!s->budget--) { s->failed_pc=0x0c09d99eu; return 0; }
r[12]+=r[2];
goto P_0c09d9a0;
P_0c09d9a0: /* original f22d, guest PC 0x0c09d9a0 */
if(!s->budget--) { s->failed_pc=0x0c09d9a0u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d9a2;
P_0c09d9a2: /* original f578, guest PC 0x0c09d9a2 */
if(!s->budget--) { s->failed_pc=0x0c09d9a2u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c09d9a4;
P_0c09d9a4: /* original f541, guest PC 0x0c09d9a4 */
if(!s->budget--) { s->failed_pc=0x0c09d9a4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c09d9a6;
P_0c09d9a6: /* original f62c, guest PC 0x0c09d9a6 */
if(!s->budget--) { s->failed_pc=0x0c09d9a6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c09d9a8;
P_0c09d9a8: /* original f633, guest PC 0x0c09d9a8 */
if(!s->budget--) { s->failed_pc=0x0c09d9a8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'/');
goto P_0c09d9aa;
P_0c09d9aa: /* original f05c, guest PC 0x0c09d9aa */
if(!s->budget--) { s->failed_pc=0x0c09d9aau; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09d9ac;
P_0c09d9ac: /* original f72c, guest PC 0x0c09d9ac */
if(!s->budget--) { s->failed_pc=0x0c09d9acu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c09d9ae;
P_0c09d9ae: /* original f46e, guest PC 0x0c09d9ae */
if(!s->budget--) { s->failed_pc=0x0c09d9aeu; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[6],fr[4],r[18]);
goto P_0c09d9b0;
P_0c09d9b0: /* original 7502, guest PC 0x0c09d9b0 */
if(!s->budget--) { s->failed_pc=0x0c09d9b0u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d9b2;
P_0c09d9b2: /* original 4508, guest PC 0x0c09d9b2 */
if(!s->budget--) { s->failed_pc=0x0c09d9b2u; return 0; }
r[5]<<=2;
goto P_0c09d9b4;
P_0c09d9b4: /* original 3e5c, guest PC 0x0c09d9b4 */
if(!s->budget--) { s->failed_pc=0x0c09d9b4u; return 0; }
r[14]+=r[5];
goto P_0c09d9b6;
P_0c09d9b6: /* original 53f1, guest PC 0x0c09d9b6 */
if(!s->budget--) { s->failed_pc=0x0c09d9b6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d9b8;
P_0c09d9b8: /* original 7901, guest PC 0x0c09d9b8 */
if(!s->budget--) { s->failed_pc=0x0c09d9b8u; return 0; }
r[9]+=0x00000001u;
goto P_0c09d9ba;
P_0c09d9ba: /* original f34a, guest PC 0x0c09d9ba */
if(!s->budget--) { s->failed_pc=0x0c09d9bau; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c09d9bc;
P_0c09d9bc: /* original 53f1, guest PC 0x0c09d9bc */
if(!s->budget--) { s->failed_pc=0x0c09d9bcu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d9be;
P_0c09d9be: /* original 7304, guest PC 0x0c09d9be */
if(!s->budget--) { s->failed_pc=0x0c09d9beu; return 0; }
r[3]+=0x00000004u;
goto P_0c09d9c0;
P_0c09d9c0: /* original 1f31, guest PC 0x0c09d9c0 */
if(!s->budget--) { s->failed_pc=0x0c09d9c0u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09d9c2;
P_0c09d9c2: /* original e53f, guest PC 0x0c09d9c2 */
if(!s->budget--) { s->failed_pc=0x0c09d9c2u; return 0; }
r[5]=0x0000003fu;
goto P_0c09d9c4;
P_0c09d9c4: /* original 3952, guest PC 0x0c09d9c4 */
if(!s->budget--) { s->failed_pc=0x0c09d9c4u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[5])!=0);
goto P_0c09d9c6;
P_0c09d9c6: /* original 8901, guest PC 0x0c09d9c6 */
if(!s->budget--) { s->failed_pc=0x0c09d9c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d9cc; }
goto P_0c09d9c8;
P_0c09d9c8: /* original af4a, guest PC 0x0c09d9c8 */
if(!s->budget--) { s->failed_pc=0x0c09d9c8u; return 0; }
goto P_0c09d860;
P_0c09d9ca: /* original 0009, guest PC 0x0c09d9ca */
if(!s->budget--) { s->failed_pc=0x0c09d9cau; return 0; }
goto P_0c09d9cc;
P_0c09d9cc: /* original 64f2, guest PC 0x0c09d9cc */
if(!s->budget--) { s->failed_pc=0x0c09d9ccu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09d9ce;
P_0c09d9ce: /* original bd1b, guest PC 0x0c09d9ce */
if(!s->budget--) { s->failed_pc=0x0c09d9ceu; return 0; }
target=0x0c09d408u; r[16]=0x0c09d9d2u;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d9d2u) { target=s->pc; goto dispatch; }
goto P_0c09d9d2;
P_0c09d9d0: /* original 6442, guest PC 0x0c09d9d0 */
if(!s->budget--) { s->failed_pc=0x0c09d9d0u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c09d9d2;
P_0c09d9d2: /* original 53f1, guest PC 0x0c09d9d2 */
if(!s->budget--) { s->failed_pc=0x0c09d9d2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d9d4;
P_0c09d9d4: /* original 62f2, guest PC 0x0c09d9d4 */
if(!s->budget--) { s->failed_pc=0x0c09d9d4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09d9d6;
P_0c09d9d6: /* original 7f14, guest PC 0x0c09d9d6 */
if(!s->budget--) { s->failed_pc=0x0c09d9d6u; return 0; }
r[15]+=0x00000014u;
goto P_0c09d9d8;
P_0c09d9d8: /* original 4f26, guest PC 0x0c09d9d8 */
if(!s->budget--) { s->failed_pc=0x0c09d9d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d9da;
P_0c09d9da: /* original 2232, guest PC 0x0c09d9da */
if(!s->budget--) { s->failed_pc=0x0c09d9dau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c09d9dc;
P_0c09d9dc: /* original 68f6, guest PC 0x0c09d9dc */
if(!s->budget--) { s->failed_pc=0x0c09d9dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09d9de;
P_0c09d9de: /* original 69f6, guest PC 0x0c09d9de */
if(!s->budget--) { s->failed_pc=0x0c09d9deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09d9e0;
P_0c09d9e0: /* original 6bf6, guest PC 0x0c09d9e0 */
if(!s->budget--) { s->failed_pc=0x0c09d9e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09d9e2;
P_0c09d9e2: /* original 6cf6, guest PC 0x0c09d9e2 */
if(!s->budget--) { s->failed_pc=0x0c09d9e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09d9e4;
P_0c09d9e4: /* original 6df6, guest PC 0x0c09d9e4 */
if(!s->budget--) { s->failed_pc=0x0c09d9e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d9e6;
P_0c09d9e6: /* original 000b, guest PC 0x0c09d9e6 */
if(!s->budget--) { s->failed_pc=0x0c09d9e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d9e8: /* original 6ef6, guest PC 0x0c09d9e8 */
if(!s->budget--) { s->failed_pc=0x0c09d9e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09d9eau,s,ram);
P_0c0a2f90: /* original 4f22, guest PC 0x0c0a2f90 */
if(!s->budget--) { s->failed_pc=0x0c0a2f90u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2f92;
P_0c0a2f92: /* original 7ff8, guest PC 0x0c0a2f92 */
if(!s->budget--) { s->failed_pc=0x0c0a2f92u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2f94;
P_0c0a2f94: /* original 2f52, guest PC 0x0c0a2f94 */
if(!s->budget--) { s->failed_pc=0x0c0a2f94u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a2f96;
P_0c0a2f96: /* original 8f42, guest PC 0x0c0a2f96 */
if(!s->budget--) { s->failed_pc=0x0c0a2f96u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[6],4);
if(!cond) { goto P_0c0a301e; }
goto P_0c0a2f9a;
P_0c0a2f98: /* original 1f61, guest PC 0x0c0a2f98 */
if(!s->budget--) { s->failed_pc=0x0c0a2f98u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a2f9a;
P_0c0a2f9a: /* original e21a, guest PC 0x0c0a2f9a */
if(!s->budget--) { s->failed_pc=0x0c0a2f9au; return 0; }
r[2]=0x0000001au;
goto P_0c0a2f9c;
P_0c0a2f9c: /* original 3e23, guest PC 0x0c0a2f9c */
if(!s->budget--) { s->failed_pc=0x0c0a2f9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0a2f9e;
P_0c0a2f9e: /* original 893e, guest PC 0x0c0a2f9e */
if(!s->budget--) { s->failed_pc=0x0c0a2f9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a301e; }
goto P_0c0a2fa0;
P_0c0a2fa0: /* original 6de3, guest PC 0x0c0a2fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a2fa0u; return 0; }
r[13]=r[14];
goto P_0c0a2fa2;
P_0c0a2fa2: /* original 4d08, guest PC 0x0c0a2fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a2fa2u; return 0; }
r[13]<<=2;
goto P_0c0a2fa4;
P_0c0a2fa4: /* original 4d00, guest PC 0x0c0a2fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a2fa4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0a2fa6;
P_0c0a2fa6: /* original 63e3, guest PC 0x0c0a2fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a2fa6u; return 0; }
r[3]=r[14];
goto P_0c0a2fa8;
P_0c0a2fa8: /* original 3d3c, guest PC 0x0c0a2fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a2fa8u; return 0; }
r[13]+=r[3];
goto P_0c0a2faa;
P_0c0a2faa: /* original d23a, guest PC 0x0c0a2faa */
if(!s->budget--) { s->failed_pc=0x0c0a2faau; return 0; }
r[2]=read(ram,0x0c0a3094u,4);
goto P_0c0a2fac;
P_0c0a2fac: /* original 4d08, guest PC 0x0c0a2fac */
if(!s->budget--) { s->failed_pc=0x0c0a2facu; return 0; }
r[13]<<=2;
goto P_0c0a2fae;
P_0c0a2fae: /* original 6ddf, guest PC 0x0c0a2fae */
if(!s->budget--) { s->failed_pc=0x0c0a2faeu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a2fb0;
P_0c0a2fb0: /* original 3d2c, guest PC 0x0c0a2fb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2fb0u; return 0; }
r[13]+=r[2];
goto P_0c0a2fb2;
P_0c0a2fb2: /* original 53d6, guest PC 0x0c0a2fb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2fb2u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c0a2fb4;
P_0c0a2fb4: /* original 2338, guest PC 0x0c0a2fb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2fb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2fb6;
P_0c0a2fb6: /* original 8932, guest PC 0x0c0a2fb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2fb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a301e; }
goto P_0c0a2fb8;
P_0c0a2fb8: /* original d337, guest PC 0x0c0a2fb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2fb8u; return 0; }
r[3]=read(ram,0x0c0a3098u,4);
goto P_0c0a2fba;
P_0c0a2fba: /* original 54d6, guest PC 0x0c0a2fba */
if(!s->budget--) { s->failed_pc=0x0c0a2fbau; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0a2fbc;
P_0c0a2fbc: /* original 243b, guest PC 0x0c0a2fbc */
if(!s->budget--) { s->failed_pc=0x0c0a2fbcu; return 0; }
r[4]|=r[3];
goto P_0c0a2fbe;
P_0c0a2fbe: /* original 6042, guest PC 0x0c0a2fbe */
if(!s->budget--) { s->failed_pc=0x0c0a2fbeu; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0a2fc0;
P_0c0a2fc0: /* original c880, guest PC 0x0c0a2fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2fc0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2fc2;
P_0c0a2fc2: /* original 8b27, guest PC 0x0c0a2fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2fc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a3014; }
goto P_0c0a2fc4;
P_0c0a2fc4: /* original 6242, guest PC 0x0c0a2fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2fc4u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0a2fc6;
P_0c0a2fc6: /* original 935f, guest PC 0x0c0a2fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2fc6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3088u,2);
goto P_0c0a2fc8;
P_0c0a2fc8: /* original 3230, guest PC 0x0c0a2fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2fc8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0a2fca;
P_0c0a2fca: /* original 8923, guest PC 0x0c0a2fca */
if(!s->budget--) { s->failed_pc=0x0c0a2fcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a3014; }
goto P_0c0a2fcc;
P_0c0a2fcc: /* original 935d, guest PC 0x0c0a2fcc */
if(!s->budget--) { s->failed_pc=0x0c0a2fccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a308au,2);
goto P_0c0a2fce;
P_0c0a2fce: /* original 55d6, guest PC 0x0c0a2fce */
if(!s->budget--) { s->failed_pc=0x0c0a2fceu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0a2fd0;
P_0c0a2fd0: /* original 2f36, guest PC 0x0c0a2fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2fd0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2fd2;
P_0c0a2fd2: /* original d232, guest PC 0x0c0a2fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2fd2u; return 0; }
r[2]=read(ram,0x0c0a309cu,4);
goto P_0c0a2fd4;
P_0c0a2fd4: /* original 2f26, guest PC 0x0c0a2fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2fd4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2fd6;
P_0c0a2fd6: /* original 2fe6, guest PC 0x0c0a2fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2fd6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2fd8;
P_0c0a2fd8: /* original 56f3, guest PC 0x0c0a2fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2fd8u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0a2fda;
P_0c0a2fda: /* original d132, guest PC 0x0c0a2fda */
if(!s->budget--) { s->failed_pc=0x0c0a2fdau; return 0; }
r[1]=read(ram,0x0c0a30a4u,4);
goto P_0c0a2fdc;
P_0c0a2fdc: /* original d730, guest PC 0x0c0a2fdc */
if(!s->budget--) { s->failed_pc=0x0c0a2fdcu; return 0; }
r[7]=read(ram,0x0c0a30a0u,4);
goto P_0c0a2fde;
P_0c0a2fde: /* original 410b, guest PC 0x0c0a2fde */
if(!s->budget--) { s->failed_pc=0x0c0a2fdeu; return 0; }
target=r[1];
r[16]=0x0c0a2fe2u;
r[4]=read(ram,r[13]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2fe2u) { target=s->pc; goto dispatch; }
goto P_0c0a2fe2;
P_0c0a2fe0: /* original 54d4, guest PC 0x0c0a2fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a2fe0u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c0a2fe2;
P_0c0a2fe2: /* original 6403, guest PC 0x0c0a2fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a2fe2u; return 0; }
r[4]=r[0];
goto P_0c0a2fe4;
P_0c0a2fe4: /* original 4411, guest PC 0x0c0a2fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a2fe4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a2fe6;
P_0c0a2fe6: /* original 8f1a, guest PC 0x0c0a2fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a2fe6u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(!cond) { goto P_0c0a301e; }
goto P_0c0a2fea;
P_0c0a2fe8: /* original 7f0c, guest PC 0x0c0a2fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a2fe8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2fea;
P_0c0a2fea: /* original 924f, guest PC 0x0c0a2fea */
if(!s->budget--) { s->failed_pc=0x0c0a2feau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a308cu,2);
goto P_0c0a2fec;
P_0c0a2fec: /* original 64e3, guest PC 0x0c0a2fec */
if(!s->budget--) { s->failed_pc=0x0c0a2fecu; return 0; }
r[4]=r[14];
goto P_0c0a2fee;
P_0c0a2fee: /* original 4408, guest PC 0x0c0a2fee */
if(!s->budget--) { s->failed_pc=0x0c0a2feeu; return 0; }
r[4]<<=2;
goto P_0c0a2ff0;
P_0c0a2ff0: /* original 61e3, guest PC 0x0c0a2ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ff0u; return 0; }
r[1]=r[14];
goto P_0c0a2ff2;
P_0c0a2ff2: /* original 2f26, guest PC 0x0c0a2ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ff2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ff4;
P_0c0a2ff4: /* original 4400, guest PC 0x0c0a2ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ff4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a2ff6;
P_0c0a2ff6: /* original d329, guest PC 0x0c0a2ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ff6u; return 0; }
r[3]=read(ram,0x0c0a309cu,4);
goto P_0c0a2ff8;
P_0c0a2ff8: /* original 341c, guest PC 0x0c0a2ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ff8u; return 0; }
r[4]+=r[1];
goto P_0c0a2ffa;
P_0c0a2ffa: /* original 4408, guest PC 0x0c0a2ffa */
if(!s->budget--) { s->failed_pc=0x0c0a2ffau; return 0; }
r[4]<<=2;
goto P_0c0a2ffc;
P_0c0a2ffc: /* original 2f36, guest PC 0x0c0a2ffc */
if(!s->budget--) { s->failed_pc=0x0c0a2ffcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ffe;
P_0c0a2ffe: /* original 644f, guest PC 0x0c0a2ffe */
if(!s->budget--) { s->failed_pc=0x0c0a2ffeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a3000;
P_0c0a3000: /* original 2fe6, guest PC 0x0c0a3000 */
if(!s->budget--) { s->failed_pc=0x0c0a3000u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a3002;
P_0c0a3002: /* original d02b, guest PC 0x0c0a3002 */
if(!s->budget--) { s->failed_pc=0x0c0a3002u; return 0; }
r[0]=read(ram,0x0c0a30b0u,4);
goto P_0c0a3004;
P_0c0a3004: /* original d327, guest PC 0x0c0a3004 */
if(!s->budget--) { s->failed_pc=0x0c0a3004u; return 0; }
r[3]=read(ram,0x0c0a30a4u,4);
goto P_0c0a3006;
P_0c0a3006: /* original d529, guest PC 0x0c0a3006 */
if(!s->budget--) { s->failed_pc=0x0c0a3006u; return 0; }
r[5]=read(ram,0x0c0a30acu,4);
goto P_0c0a3008;
P_0c0a3008: /* original d727, guest PC 0x0c0a3008 */
if(!s->budget--) { s->failed_pc=0x0c0a3008u; return 0; }
r[7]=read(ram,0x0c0a30a8u,4);
goto P_0c0a300a;
P_0c0a300a: /* original 56f4, guest PC 0x0c0a300a */
if(!s->budget--) { s->failed_pc=0x0c0a300au; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c0a300c;
P_0c0a300c: /* original 430b, guest PC 0x0c0a300c */
if(!s->budget--) { s->failed_pc=0x0c0a300cu; return 0; }
target=r[3];
r[16]=0x0c0a3010u;
r[4]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3010u) { target=s->pc; goto dispatch; }
goto P_0c0a3010;
P_0c0a300e: /* original 044e, guest PC 0x0c0a300e */
if(!s->budget--) { s->failed_pc=0x0c0a300eu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0a3010;
P_0c0a3010: /* original a005, guest PC 0x0c0a3010 */
if(!s->budget--) { s->failed_pc=0x0c0a3010u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a301e;
P_0c0a3012: /* original 7f0c, guest PC 0x0c0a3012 */
if(!s->budget--) { s->failed_pc=0x0c0a3012u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a3014;
P_0c0a3014: /* original 63f2, guest PC 0x0c0a3014 */
if(!s->budget--) { s->failed_pc=0x0c0a3014u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a3016;
P_0c0a3016: /* original e401, guest PC 0x0c0a3016 */
if(!s->budget--) { s->failed_pc=0x0c0a3016u; return 0; }
r[4]=0x00000001u;
goto P_0c0a3018;
P_0c0a3018: /* original 2342, guest PC 0x0c0a3018 */
if(!s->budget--) { s->failed_pc=0x0c0a3018u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0a301a;
P_0c0a301a: /* original 53f1, guest PC 0x0c0a301a */
if(!s->budget--) { s->failed_pc=0x0c0a301au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a301c;
P_0c0a301c: /* original 2342, guest PC 0x0c0a301c */
if(!s->budget--) { s->failed_pc=0x0c0a301cu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0a301e;
P_0c0a301e: /* original 7f08, guest PC 0x0c0a301e */
if(!s->budget--) { s->failed_pc=0x0c0a301eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a3020;
P_0c0a3020: /* original 4f26, guest PC 0x0c0a3020 */
if(!s->budget--) { s->failed_pc=0x0c0a3020u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a3022;
P_0c0a3022: /* original e000, guest PC 0x0c0a3022 */
if(!s->budget--) { s->failed_pc=0x0c0a3022u; return 0; }
r[0]=0x00000000u;
goto P_0c0a3024;
P_0c0a3024: /* original 6df6, guest PC 0x0c0a3024 */
if(!s->budget--) { s->failed_pc=0x0c0a3024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a3026;
P_0c0a3026: /* original 000b, guest PC 0x0c0a3026 */
if(!s->budget--) { s->failed_pc=0x0c0a3026u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a3028: /* original 6ef6, guest PC 0x0c0a3028 */
if(!s->budget--) { s->failed_pc=0x0c0a3028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a302au,s,ram);
P_0c0ace3e: /* original 4f22, guest PC 0x0c0ace3e */
if(!s->budget--) { s->failed_pc=0x0c0ace3eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ace40;
P_0c0ace40: /* original 3352, guest PC 0x0c0ace40 */
if(!s->budget--) { s->failed_pc=0x0c0ace40u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[5])!=0);
goto P_0c0ace42;
P_0c0ace42: /* original 8f06, guest PC 0x0c0ace42 */
if(!s->budget--) { s->failed_pc=0x0c0ace42u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c0ace52; }
goto P_0c0ace46;
P_0c0ace44: /* original 6e43, guest PC 0x0c0ace44 */
if(!s->budget--) { s->failed_pc=0x0c0ace44u; return 0; }
r[14]=r[4];
goto P_0c0ace46;
P_0c0ace46: /* original 50d1, guest PC 0x0c0ace46 */
if(!s->budget--) { s->failed_pc=0x0c0ace46u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0ace48;
P_0c0ace48: /* original 8801, guest PC 0x0c0ace48 */
if(!s->budget--) { s->failed_pc=0x0c0ace48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ace4a;
P_0c0ace4a: /* original 8921, guest PC 0x0c0ace4a */
if(!s->budget--) { s->failed_pc=0x0c0ace4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ace90; }
goto P_0c0ace4c;
P_0c0ace4c: /* original 53d1, guest PC 0x0c0ace4c */
if(!s->budget--) { s->failed_pc=0x0c0ace4cu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ace4e;
P_0c0ace4e: /* original 3356, guest PC 0x0c0ace4e */
if(!s->budget--) { s->failed_pc=0x0c0ace4eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[5])!=0);
goto P_0c0ace50;
P_0c0ace50: /* original 892f, guest PC 0x0c0ace50 */
if(!s->budget--) { s->failed_pc=0x0c0ace50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aceb2; }
goto P_0c0ace52;
P_0c0ace52: /* original 65d2, guest PC 0x0c0ace52 */
if(!s->budget--) { s->failed_pc=0x0c0ace52u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0ace54;
P_0c0ace54: /* original 655d, guest PC 0x0c0ace54 */
if(!s->budget--) { s->failed_pc=0x0c0ace54u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ace56;
P_0c0ace56: /* original b18f, guest PC 0x0c0ace56 */
if(!s->budget--) { s->failed_pc=0x0c0ace56u; return 0; }
target=0x0c0ad178u; r[16]=0x0c0ace5au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ace5au) { target=s->pc; goto dispatch; }
goto P_0c0ace5a;
P_0c0ace58: /* original 64e3, guest PC 0x0c0ace58 */
if(!s->budget--) { s->failed_pc=0x0c0ace58u; return 0; }
r[4]=r[14];
goto P_0c0ace5a;
P_0c0ace5a: /* original e048, guest PC 0x0c0ace5a */
if(!s->budget--) { s->failed_pc=0x0c0ace5au; return 0; }
r[0]=0x00000048u;
goto P_0c0ace5c;
P_0c0ace5c: /* original 9241, guest PC 0x0c0ace5c */
if(!s->budget--) { s->failed_pc=0x0c0ace5cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acee2u,2);
goto P_0c0ace5e;
P_0c0ace5e: /* original 04ee, guest PC 0x0c0ace5e */
if(!s->budget--) { s->failed_pc=0x0c0ace5eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ace60;
P_0c0ace60: /* original 9040, guest PC 0x0c0ace60 */
if(!s->budget--) { s->failed_pc=0x0c0ace60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acee4u,2);
goto P_0c0ace62;
P_0c0ace62: /* original 933d, guest PC 0x0c0ace62 */
if(!s->budget--) { s->failed_pc=0x0c0ace62u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acee0u,2);
goto P_0c0ace64;
P_0c0ace64: /* original 01ee, guest PC 0x0c0ace64 */
if(!s->budget--) { s->failed_pc=0x0c0ace64u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0ace66;
P_0c0ace66: /* original d626, guest PC 0x0c0ace66 */
if(!s->budget--) { s->failed_pc=0x0c0ace66u; return 0; }
r[6]=read(ram,0x0c0acf00u,4);
goto P_0c0ace68;
P_0c0ace68: /* original 2439, guest PC 0x0c0ace68 */
if(!s->budget--) { s->failed_pc=0x0c0ace68u; return 0; }
r[4]&=r[3];
goto P_0c0ace6a;
P_0c0ace6a: /* original 2128, guest PC 0x0c0ace6a */
if(!s->budget--) { s->failed_pc=0x0c0ace6au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ace6c;
P_0c0ace6c: /* original 8d03, guest PC 0x0c0ace6c */
if(!s->budget--) { s->failed_pc=0x0c0ace6cu; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(cond) { goto P_0c0ace76; }
goto P_0c0ace70;
P_0c0ace6e: /* original e500, guest PC 0x0c0ace6e */
if(!s->budget--) { s->failed_pc=0x0c0ace6eu; return 0; }
r[5]=0x00000000u;
goto P_0c0ace70;
P_0c0ace70: /* original d324, guest PC 0x0c0ace70 */
if(!s->budget--) { s->failed_pc=0x0c0ace70u; return 0; }
r[3]=read(ram,0x0c0acf04u,4);
goto P_0c0ace72;
P_0c0ace72: /* original 6563, guest PC 0x0c0ace72 */
if(!s->budget--) { s->failed_pc=0x0c0ace72u; return 0; }
r[5]=r[6];
goto P_0c0ace74;
P_0c0ace74: /* original 243b, guest PC 0x0c0ace74 */
if(!s->budget--) { s->failed_pc=0x0c0ace74u; return 0; }
r[4]|=r[3];
goto P_0c0ace76;
P_0c0ace76: /* original 9036, guest PC 0x0c0ace76 */
if(!s->budget--) { s->failed_pc=0x0c0ace76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acee6u,2);
goto P_0c0ace78;
P_0c0ace78: /* original 0e55, guest PC 0x0c0ace78 */
if(!s->budget--) { s->failed_pc=0x0c0ace78u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0ace7a;
P_0c0ace7a: /* original e048, guest PC 0x0c0ace7a */
if(!s->budget--) { s->failed_pc=0x0c0ace7au; return 0; }
r[0]=0x00000048u;
goto P_0c0ace7c;
P_0c0ace7c: /* original 0e46, guest PC 0x0c0ace7c */
if(!s->budget--) { s->failed_pc=0x0c0ace7cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0ace7e;
P_0c0ace7e: /* original 9033, guest PC 0x0c0ace7e */
if(!s->budget--) { s->failed_pc=0x0c0ace7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acee8u,2);
goto P_0c0ace80;
P_0c0ace80: /* original 0e66, guest PC 0x0c0ace80 */
if(!s->budget--) { s->failed_pc=0x0c0ace80u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0ace82;
P_0c0ace82: /* original e062, guest PC 0x0c0ace82 */
if(!s->budget--) { s->failed_pc=0x0c0ace82u; return 0; }
r[0]=0x00000062u;
goto P_0c0ace84;
P_0c0ace84: /* original 53d1, guest PC 0x0c0ace84 */
if(!s->budget--) { s->failed_pc=0x0c0ace84u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ace86;
P_0c0ace86: /* original 7301, guest PC 0x0c0ace86 */
if(!s->budget--) { s->failed_pc=0x0c0ace86u; return 0; }
r[3]+=0x00000001u;
goto P_0c0ace88;
P_0c0ace88: /* original 6233, guest PC 0x0c0ace88 */
if(!s->budget--) { s->failed_pc=0x0c0ace88u; return 0; }
r[2]=r[3];
goto P_0c0ace8a;
P_0c0ace8a: /* original 1d31, guest PC 0x0c0ace8a */
if(!s->budget--) { s->failed_pc=0x0c0ace8au; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0ace8c;
P_0c0ace8c: /* original a021, guest PC 0x0c0ace8c */
if(!s->budget--) { s->failed_pc=0x0c0ace8cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aced2;
P_0c0ace8e: /* original 0e24, guest PC 0x0c0ace8e */
if(!s->budget--) { s->failed_pc=0x0c0ace8eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ace90;
P_0c0ace90: /* original e03e, guest PC 0x0c0ace90 */
if(!s->budget--) { s->failed_pc=0x0c0ace90u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ace92;
P_0c0ace92: /* original 03ed, guest PC 0x0c0ace92 */
if(!s->budget--) { s->failed_pc=0x0c0ace92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ace94;
P_0c0ace94: /* original e214, guest PC 0x0c0ace94 */
if(!s->budget--) { s->failed_pc=0x0c0ace94u; return 0; }
r[2]=0x00000014u;
goto P_0c0ace96;
P_0c0ace96: /* original 633d, guest PC 0x0c0ace96 */
if(!s->budget--) { s->failed_pc=0x0c0ace96u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ace98;
P_0c0ace98: /* original 3327, guest PC 0x0c0ace98 */
if(!s->budget--) { s->failed_pc=0x0c0ace98u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c0ace9a;
P_0c0ace9a: /* original 8b1a, guest PC 0x0c0ace9a */
if(!s->budget--) { s->failed_pc=0x0c0ace9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aced2; }
goto P_0c0ace9c;
P_0c0ace9c: /* original e048, guest PC 0x0c0ace9c */
if(!s->budget--) { s->failed_pc=0x0c0ace9cu; return 0; }
r[0]=0x00000048u;
goto P_0c0ace9e;
P_0c0ace9e: /* original d31a, guest PC 0x0c0ace9e */
if(!s->budget--) { s->failed_pc=0x0c0ace9eu; return 0; }
r[3]=read(ram,0x0c0acf08u,4);
goto P_0c0acea0;
P_0c0acea0: /* original 02ee, guest PC 0x0c0acea0 */
if(!s->budget--) { s->failed_pc=0x0c0acea0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acea2;
P_0c0acea2: /* original 223b, guest PC 0x0c0acea2 */
if(!s->budget--) { s->failed_pc=0x0c0acea2u; return 0; }
r[2]|=r[3];
goto P_0c0acea4;
P_0c0acea4: /* original 0e26, guest PC 0x0c0acea4 */
if(!s->budget--) { s->failed_pc=0x0c0acea4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0acea6;
P_0c0acea6: /* original e062, guest PC 0x0c0acea6 */
if(!s->budget--) { s->failed_pc=0x0c0acea6u; return 0; }
r[0]=0x00000062u;
goto P_0c0acea8;
P_0c0acea8: /* original 51d1, guest PC 0x0c0acea8 */
if(!s->budget--) { s->failed_pc=0x0c0acea8u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0aceaa;
P_0c0aceaa: /* original 7101, guest PC 0x0c0aceaa */
if(!s->budget--) { s->failed_pc=0x0c0aceaau; return 0; }
r[1]+=0x00000001u;
goto P_0c0aceac;
P_0c0aceac: /* original 6213, guest PC 0x0c0aceac */
if(!s->budget--) { s->failed_pc=0x0c0aceacu; return 0; }
r[2]=r[1];
goto P_0c0aceae;
P_0c0aceae: /* original 1d11, guest PC 0x0c0aceae */
if(!s->budget--) { s->failed_pc=0x0c0aceaeu; return 0; }
write(ram,r[13]+4,r[1],4);
goto P_0c0aceb0;
P_0c0aceb0: /* original 0e24, guest PC 0x0c0aceb0 */
if(!s->budget--) { s->failed_pc=0x0c0aceb0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aceb2;
P_0c0aceb2: /* original e03e, guest PC 0x0c0aceb2 */
if(!s->budget--) { s->failed_pc=0x0c0aceb2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aceb4;
P_0c0aceb4: /* original 04ed, guest PC 0x0c0aceb4 */
if(!s->budget--) { s->failed_pc=0x0c0aceb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aceb6;
P_0c0aceb6: /* original 644d, guest PC 0x0c0aceb6 */
if(!s->budget--) { s->failed_pc=0x0c0aceb6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aceb8;
P_0c0aceb8: /* original 74fe, guest PC 0x0c0aceb8 */
if(!s->budget--) { s->failed_pc=0x0c0aceb8u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c0aceba;
P_0c0aceba: /* original 3457, guest PC 0x0c0aceba */
if(!s->budget--) { s->failed_pc=0x0c0acebau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c0acebc;
P_0c0acebc: /* original 8d09, guest PC 0x0c0acebc */
if(!s->budget--) { s->failed_pc=0x0c0acebcu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0aced2; }
goto P_0c0acec0;
P_0c0acebe: /* original 0e45, guest PC 0x0c0acebe */
if(!s->budget--) { s->failed_pc=0x0c0acebeu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0acec0;
P_0c0acec0: /* original e048, guest PC 0x0c0acec0 */
if(!s->budget--) { s->failed_pc=0x0c0acec0u; return 0; }
r[0]=0x00000048u;
goto P_0c0acec2;
P_0c0acec2: /* original d312, guest PC 0x0c0acec2 */
if(!s->budget--) { s->failed_pc=0x0c0acec2u; return 0; }
r[3]=read(ram,0x0c0acf0cu,4);
goto P_0c0acec4;
P_0c0acec4: /* original 02ee, guest PC 0x0c0acec4 */
if(!s->budget--) { s->failed_pc=0x0c0acec4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acec6;
P_0c0acec6: /* original e100, guest PC 0x0c0acec6 */
if(!s->budget--) { s->failed_pc=0x0c0acec6u; return 0; }
r[1]=0x00000000u;
goto P_0c0acec8;
P_0c0acec8: /* original 2239, guest PC 0x0c0acec8 */
if(!s->budget--) { s->failed_pc=0x0c0acec8u; return 0; }
r[2]&=r[3];
goto P_0c0aceca;
P_0c0aceca: /* original 0e26, guest PC 0x0c0aceca */
if(!s->budget--) { s->failed_pc=0x0c0acecau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0acecc;
P_0c0acecc: /* original 1e1e, guest PC 0x0c0acecc */
if(!s->budget--) { s->failed_pc=0x0c0aceccu; return 0; }
write(ram,r[14]+56,r[1],4);
goto P_0c0acece;
P_0c0acece: /* original 9004, guest PC 0x0c0acece */
if(!s->budget--) { s->failed_pc=0x0c0aceceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acedau,2);
goto P_0c0aced0;
P_0c0aced0: /* original 0e55, guest PC 0x0c0aced0 */
if(!s->budget--) { s->failed_pc=0x0c0aced0u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0aced2;
P_0c0aced2: /* original 4f26, guest PC 0x0c0aced2 */
if(!s->budget--) { s->failed_pc=0x0c0aced2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aced4;
P_0c0aced4: /* original 6df6, guest PC 0x0c0aced4 */
if(!s->budget--) { s->failed_pc=0x0c0aced4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aced6;
P_0c0aced6: /* original 000b, guest PC 0x0c0aced6 */
if(!s->budget--) { s->failed_pc=0x0c0aced6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aced8: /* original 6ef6, guest PC 0x0c0aced8 */
if(!s->budget--) { s->failed_pc=0x0c0aced8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0acedau,s,ram);
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
r[16]=0x0c0b2588u;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b2588u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c0b2594u,s,ram);
P_0c0c6482: /* original 4f22, guest PC 0x0c0c6482 */
if(!s->budget--) { s->failed_pc=0x0c0c6482u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c6484;
P_0c0c6484: /* original d613, guest PC 0x0c0c6484 */
if(!s->budget--) { s->failed_pc=0x0c0c6484u; return 0; }
r[6]=read(ram,0x0c0c64d4u,4);
goto P_0c0c6486;
P_0c0c6486: /* original 8b00, guest PC 0x0c0c6486 */
if(!s->budget--) { s->failed_pc=0x0c0c6486u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c648a; }
goto P_0c0c6488;
P_0c0c6488: /* original 3538, guest PC 0x0c0c6488 */
if(!s->budget--) { s->failed_pc=0x0c0c6488u; return 0; }
r[5]-=r[3];
goto P_0c0c648a;
P_0c0c648a: /* original dc14, guest PC 0x0c0c648a */
if(!s->budget--) { s->failed_pc=0x0c0c648au; return 0; }
r[12]=read(ram,0x0c0c64dcu,4);
goto P_0c0c648c;
P_0c0c648c: /* original 2448, guest PC 0x0c0c648c */
if(!s->budget--) { s->failed_pc=0x0c0c648cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c648e;
P_0c0c648e: /* original d712, guest PC 0x0c0c648e */
if(!s->budget--) { s->failed_pc=0x0c0c648eu; return 0; }
r[7]=read(ram,0x0c0c64d8u,4);
goto P_0c0c6490;
P_0c0c6490: /* original 6e43, guest PC 0x0c0c6490 */
if(!s->budget--) { s->failed_pc=0x0c0c6490u; return 0; }
r[14]=r[4];
goto P_0c0c6492;
P_0c0c6492: /* original 8f02, guest PC 0x0c0c6492 */
if(!s->budget--) { s->failed_pc=0x0c0c6492u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000005u;
if(!cond) { goto P_0c0c649a; }
goto P_0c0c6496;
P_0c0c6494: /* original 7e05, guest PC 0x0c0c6494 */
if(!s->budget--) { s->failed_pc=0x0c0c6494u; return 0; }
r[14]+=0x00000005u;
goto P_0c0c6496;
P_0c0c6496: /* original a023, guest PC 0x0c0c6496 */
if(!s->budget--) { s->failed_pc=0x0c0c6496u; return 0; }
write(ram,r[7],r[5],4);
goto P_0c0c64e0;
P_0c0c6498: /* original 2752, guest PC 0x0c0c6498 */
if(!s->budget--) { s->failed_pc=0x0c0c6498u; return 0; }
write(ram,r[7],r[5],4);
goto P_0c0c649a;
P_0c0c649a: /* original 6372, guest PC 0x0c0c649a */
if(!s->budget--) { s->failed_pc=0x0c0c649au; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c0c649c;
P_0c0c649c: /* original 3530, guest PC 0x0c0c649c */
if(!s->budget--) { s->failed_pc=0x0c0c649cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c0c649e;
P_0c0c649e: /* original 8b1f, guest PC 0x0c0c649e */
if(!s->budget--) { s->failed_pc=0x0c0c649eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c64e0; }
goto P_0c0c64a0;
P_0c0c64a0: /* original 60e3, guest PC 0x0c0c64a0 */
if(!s->budget--) { s->failed_pc=0x0c0c64a0u; return 0; }
r[0]=r[14];
goto P_0c0c64a2;
P_0c0c64a2: /* original 7406, guest PC 0x0c0c64a2 */
if(!s->budget--) { s->failed_pc=0x0c0c64a2u; return 0; }
r[4]+=0x00000006u;
goto P_0c0c64a4;
P_0c0c64a4: /* original 4008, guest PC 0x0c0c64a4 */
if(!s->budget--) { s->failed_pc=0x0c0c64a4u; return 0; }
r[0]<<=2;
goto P_0c0c64a6;
P_0c0c64a6: /* original e300, guest PC 0x0c0c64a6 */
if(!s->budget--) { s->failed_pc=0x0c0c64a6u; return 0; }
r[3]=0x00000000u;
goto P_0c0c64a8;
P_0c0c64a8: /* original 0c36, guest PC 0x0c0c64a8 */
if(!s->budget--) { s->failed_pc=0x0c0c64a8u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c0c64aa;
P_0c0c64aa: /* original 4408, guest PC 0x0c0c64aa */
if(!s->budget--) { s->failed_pc=0x0c0c64aau; return 0; }
r[4]<<=2;
goto P_0c0c64ac;
P_0c0c64ac: /* original 9205, guest PC 0x0c0c64ac */
if(!s->budget--) { s->failed_pc=0x0c0c64acu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c64bau,2);
goto P_0c0c64ae;
P_0c0c64ae: /* original e3ff, guest PC 0x0c0c64ae */
if(!s->budget--) { s->failed_pc=0x0c0c64aeu; return 0; }
r[3]=0xffffffffu;
goto P_0c0c64b0;
P_0c0c64b0: /* original 326c, guest PC 0x0c0c64b0 */
if(!s->budget--) { s->failed_pc=0x0c0c64b0u; return 0; }
r[2]+=r[6];
goto P_0c0c64b2;
P_0c0c64b2: /* original 342c, guest PC 0x0c0c64b2 */
if(!s->budget--) { s->failed_pc=0x0c0c64b2u; return 0; }
r[4]+=r[2];
goto P_0c0c64b4;
P_0c0c64b4: /* original a051, guest PC 0x0c0c64b4 */
if(!s->budget--) { s->failed_pc=0x0c0c64b4u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0c655a;
P_0c0c64b6: /* original 2432, guest PC 0x0c0c64b6 */
if(!s->budget--) { s->failed_pc=0x0c0c64b6u; return 0; }
write(ram,r[4],r[3],4);
return vf3_matrix_family(0x0c0c64b8u,s,ram);
P_0c0c64e0: /* original e01c, guest PC 0x0c0c64e0 */
if(!s->budget--) { s->failed_pc=0x0c0c64e0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c64e2;
P_0c0c64e2: /* original 006c, guest PC 0x0c0c64e2 */
if(!s->budget--) { s->failed_pc=0x0c0c64e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c64e4;
P_0c0c64e4: /* original e40f, guest PC 0x0c0c64e4 */
if(!s->budget--) { s->failed_pc=0x0c0c64e4u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c64e6;
P_0c0c64e6: /* original 600c, guest PC 0x0c0c64e6 */
if(!s->budget--) { s->failed_pc=0x0c0c64e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c64e8;
P_0c0c64e8: /* original 2409, guest PC 0x0c0c64e8 */
if(!s->budget--) { s->failed_pc=0x0c0c64e8u; return 0; }
r[4]&=r[0];
goto P_0c0c64ea;
P_0c0c64ea: /* original 6043, guest PC 0x0c0c64ea */
if(!s->budget--) { s->failed_pc=0x0c0c64eau; return 0; }
r[0]=r[4];
goto P_0c0c64ec;
P_0c0c64ec: /* original 8802, guest PC 0x0c0c64ec */
if(!s->budget--) { s->failed_pc=0x0c0c64ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c64ee;
P_0c0c64ee: /* original 890b, guest PC 0x0c0c64ee */
if(!s->budget--) { s->failed_pc=0x0c0c64eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6508; }
goto P_0c0c64f0;
P_0c0c64f0: /* original 6043, guest PC 0x0c0c64f0 */
if(!s->budget--) { s->failed_pc=0x0c0c64f0u; return 0; }
r[0]=r[4];
goto P_0c0c64f2;
P_0c0c64f2: /* original 8804, guest PC 0x0c0c64f2 */
if(!s->budget--) { s->failed_pc=0x0c0c64f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c64f4;
P_0c0c64f4: /* original 8908, guest PC 0x0c0c64f4 */
if(!s->budget--) { s->failed_pc=0x0c0c64f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6508; }
goto P_0c0c64f6;
P_0c0c64f6: /* original 6043, guest PC 0x0c0c64f6 */
if(!s->budget--) { s->failed_pc=0x0c0c64f6u; return 0; }
r[0]=r[4];
goto P_0c0c64f8;
P_0c0c64f8: /* original 8807, guest PC 0x0c0c64f8 */
if(!s->budget--) { s->failed_pc=0x0c0c64f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c64fa;
P_0c0c64fa: /* original 8905, guest PC 0x0c0c64fa */
if(!s->budget--) { s->failed_pc=0x0c0c64fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6508; }
goto P_0c0c64fc;
P_0c0c64fc: /* original 6043, guest PC 0x0c0c64fc */
if(!s->budget--) { s->failed_pc=0x0c0c64fcu; return 0; }
r[0]=r[4];
goto P_0c0c64fe;
P_0c0c64fe: /* original 8808, guest PC 0x0c0c64fe */
if(!s->budget--) { s->failed_pc=0x0c0c64feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c6500;
P_0c0c6500: /* original 8902, guest PC 0x0c0c6500 */
if(!s->budget--) { s->failed_pc=0x0c0c6500u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6508; }
goto P_0c0c6502;
P_0c0c6502: /* original 6043, guest PC 0x0c0c6502 */
if(!s->budget--) { s->failed_pc=0x0c0c6502u; return 0; }
r[0]=r[4];
goto P_0c0c6504;
P_0c0c6504: /* original 880e, guest PC 0x0c0c6504 */
if(!s->budget--) { s->failed_pc=0x0c0c6504u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0c6506;
P_0c0c6506: /* original 8b00, guest PC 0x0c0c6506 */
if(!s->budget--) { s->failed_pc=0x0c0c6506u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c650a; }
goto P_0c0c6508;
P_0c0c6508: /* original 750d, guest PC 0x0c0c6508 */
if(!s->budget--) { s->failed_pc=0x0c0c6508u; return 0; }
r[5]+=0x0000000du;
goto P_0c0c650a;
P_0c0c650a: /* original d32d, guest PC 0x0c0c650a */
if(!s->budget--) { s->failed_pc=0x0c0c650au; return 0; }
r[3]=read(ram,0x0c0c65c0u,4);
goto P_0c0c650c;
P_0c0c650c: /* original 6d53, guest PC 0x0c0c650c */
if(!s->budget--) { s->failed_pc=0x0c0c650cu; return 0; }
r[13]=r[5];
goto P_0c0c650e;
P_0c0c650e: /* original 4d08, guest PC 0x0c0c650e */
if(!s->budget--) { s->failed_pc=0x0c0c650eu; return 0; }
r[13]<<=2;
goto P_0c0c6510;
P_0c0c6510: /* original 3d3c, guest PC 0x0c0c6510 */
if(!s->budget--) { s->failed_pc=0x0c0c6510u; return 0; }
r[13]+=r[3];
goto P_0c0c6512;
P_0c0c6512: /* original 62d2, guest PC 0x0c0c6512 */
if(!s->budget--) { s->failed_pc=0x0c0c6512u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0c6514;
P_0c0c6514: /* original 2228, guest PC 0x0c0c6514 */
if(!s->budget--) { s->failed_pc=0x0c0c6514u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c6516;
P_0c0c6516: /* original 8919, guest PC 0x0c0c6516 */
if(!s->budget--) { s->failed_pc=0x0c0c6516u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c654c; }
goto P_0c0c6518;
P_0c0c6518: /* original 60e3, guest PC 0x0c0c6518 */
if(!s->budget--) { s->failed_pc=0x0c0c6518u; return 0; }
r[0]=r[14];
goto P_0c0c651a;
P_0c0c651a: /* original 4008, guest PC 0x0c0c651a */
if(!s->budget--) { s->failed_pc=0x0c0c651au; return 0; }
r[0]<<=2;
goto P_0c0c651c;
P_0c0c651c: /* original 61d2, guest PC 0x0c0c651c */
if(!s->budget--) { s->failed_pc=0x0c0c651cu; return 0; }
tmp=read(ram,r[13],4);
r[1]=tmp;
goto P_0c0c651e;
P_0c0c651e: /* original 02ce, guest PC 0x0c0c651e */
if(!s->budget--) { s->failed_pc=0x0c0c651eu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c6520;
P_0c0c6520: /* original 3210, guest PC 0x0c0c6520 */
if(!s->budget--) { s->failed_pc=0x0c0c6520u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0c6522;
P_0c0c6522: /* original 891a, guest PC 0x0c0c6522 */
if(!s->budget--) { s->failed_pc=0x0c0c6522u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c655a; }
goto P_0c0c6524;
P_0c0c6524: /* original 9048, guest PC 0x0c0c6524 */
if(!s->budget--) { s->failed_pc=0x0c0c6524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c65b8u,2);
goto P_0c0c6526;
P_0c0c6526: /* original 2f06, guest PC 0x0c0c6526 */
if(!s->budget--) { s->failed_pc=0x0c0c6526u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6528;
P_0c0c6528: /* original d226, guest PC 0x0c0c6528 */
if(!s->budget--) { s->failed_pc=0x0c0c6528u; return 0; }
r[2]=read(ram,0x0c0c65c4u,4);
goto P_0c0c652a;
P_0c0c652a: /* original 2f26, guest PC 0x0c0c652a */
if(!s->budget--) { s->failed_pc=0x0c0c652au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c652c;
P_0c0c652c: /* original 2fe6, guest PC 0x0c0c652c */
if(!s->budget--) { s->failed_pc=0x0c0c652cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c652e;
P_0c0c652e: /* original d229, guest PC 0x0c0c652e */
if(!s->budget--) { s->failed_pc=0x0c0c652eu; return 0; }
r[2]=read(ram,0x0c0c65d4u,4);
goto P_0c0c6530;
P_0c0c6530: /* original d327, guest PC 0x0c0c6530 */
if(!s->budget--) { s->failed_pc=0x0c0c6530u; return 0; }
r[3]=read(ram,0x0c0c65d0u,4);
goto P_0c0c6532;
P_0c0c6532: /* original 6522, guest PC 0x0c0c6532 */
if(!s->budget--) { s->failed_pc=0x0c0c6532u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c6534;
P_0c0c6534: /* original d128, guest PC 0x0c0c6534 */
if(!s->budget--) { s->failed_pc=0x0c0c6534u; return 0; }
r[1]=read(ram,0x0c0c65d8u,4);
goto P_0c0c6536;
P_0c0c6536: /* original d724, guest PC 0x0c0c6536 */
if(!s->budget--) { s->failed_pc=0x0c0c6536u; return 0; }
r[7]=read(ram,0x0c0c65c8u,4);
goto P_0c0c6538;
P_0c0c6538: /* original 353c, guest PC 0x0c0c6538 */
if(!s->budget--) { s->failed_pc=0x0c0c6538u; return 0; }
r[5]+=r[3];
goto P_0c0c653a;
P_0c0c653a: /* original d624, guest PC 0x0c0c653a */
if(!s->budget--) { s->failed_pc=0x0c0c653au; return 0; }
r[6]=read(ram,0x0c0c65ccu,4);
goto P_0c0c653c;
P_0c0c653c: /* original 410b, guest PC 0x0c0c653c */
if(!s->budget--) { s->failed_pc=0x0c0c653cu; return 0; }
target=r[1];
r[16]=0x0c0c6540u;
tmp=read(ram,r[13],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6540u) { target=s->pc; goto dispatch; }
goto P_0c0c6540;
P_0c0c653e: /* original 64d2, guest PC 0x0c0c653e */
if(!s->budget--) { s->failed_pc=0x0c0c653eu; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0c6540;
P_0c0c6540: /* original 63d2, guest PC 0x0c0c6540 */
if(!s->budget--) { s->failed_pc=0x0c0c6540u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0c6542;
P_0c0c6542: /* original 60e3, guest PC 0x0c0c6542 */
if(!s->budget--) { s->failed_pc=0x0c0c6542u; return 0; }
r[0]=r[14];
goto P_0c0c6544;
P_0c0c6544: /* original 7f0c, guest PC 0x0c0c6544 */
if(!s->budget--) { s->failed_pc=0x0c0c6544u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c6546;
P_0c0c6546: /* original 4008, guest PC 0x0c0c6546 */
if(!s->budget--) { s->failed_pc=0x0c0c6546u; return 0; }
r[0]<<=2;
goto P_0c0c6548;
P_0c0c6548: /* original a007, guest PC 0x0c0c6548 */
if(!s->budget--) { s->failed_pc=0x0c0c6548u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c0c655a;
P_0c0c654a: /* original 0c36, guest PC 0x0c0c654a */
if(!s->budget--) { s->failed_pc=0x0c0c654au; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c0c654c;
P_0c0c654c: /* original 4f26, guest PC 0x0c0c654c */
if(!s->budget--) { s->failed_pc=0x0c0c654cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c654e;
P_0c0c654e: /* original d123, guest PC 0x0c0c654e */
if(!s->budget--) { s->failed_pc=0x0c0c654eu; return 0; }
r[1]=read(ram,0x0c0c65dcu,4);
goto P_0c0c6550;
P_0c0c6550: /* original 64e3, guest PC 0x0c0c6550 */
if(!s->budget--) { s->failed_pc=0x0c0c6550u; return 0; }
r[4]=r[14];
goto P_0c0c6552;
P_0c0c6552: /* original 6cf6, guest PC 0x0c0c6552 */
if(!s->budget--) { s->failed_pc=0x0c0c6552u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6554;
P_0c0c6554: /* original 6df6, guest PC 0x0c0c6554 */
if(!s->budget--) { s->failed_pc=0x0c0c6554u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6556;
P_0c0c6556: /* original 412b, guest PC 0x0c0c6556 */
if(!s->budget--) { s->failed_pc=0x0c0c6556u; return 0; }
target=r[1];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0c6558: /* original 6ef6, guest PC 0x0c0c6558 */
if(!s->budget--) { s->failed_pc=0x0c0c6558u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c655a;
P_0c0c655a: /* original 4f26, guest PC 0x0c0c655a */
if(!s->budget--) { s->failed_pc=0x0c0c655au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c655c;
P_0c0c655c: /* original 6cf6, guest PC 0x0c0c655c */
if(!s->budget--) { s->failed_pc=0x0c0c655cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c655e;
P_0c0c655e: /* original 6df6, guest PC 0x0c0c655e */
if(!s->budget--) { s->failed_pc=0x0c0c655eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6560;
P_0c0c6560: /* original 000b, guest PC 0x0c0c6560 */
if(!s->budget--) { s->failed_pc=0x0c0c6560u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6562: /* original 6ef6, guest PC 0x0c0c6562 */
if(!s->budget--) { s->failed_pc=0x0c0c6562u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c6564u,s,ram);
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
r[16]=0x0c0c9a38u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9a38u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c0c9a3eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9a3eu) { target=s->pc; goto dispatch; }
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
r[16]=0x0c0c9a50u;
r[4]+=0x00000026u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9a50u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c0c9a5au;
r[4]+=0x00000029u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9a5au) { target=s->pc; goto dispatch; }
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
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0c9a78: /* original 6ef6, guest PC 0x0c0c9a78 */
if(!s->budget--) { s->failed_pc=0x0c0c9a78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c9a7au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c07b02cu,0x0c07b02eu,0x0c07b030u,0x0c07b032u,0x0c07b034u,0x0c07b036u,0x0c07b038u,0x0c07b03au,0x0c07b03cu,0x0c07b03eu,0x0c07b040u,0x0c07b042u,0x0c07b044u,0x0c07b046u,0x0c07b048u,0x0c07b04au,
0x0c07b04cu,0x0c07b04eu,0x0c07b050u,0x0c07b052u,0x0c07b054u,0x0c07b056u,0x0c07b058u,0x0c07b05au,0x0c07b05cu,0x0c07b05eu,0x0c07b060u,0x0c07b062u,0x0c07b064u,0x0c07b066u,0x0c07b068u,0x0c07b06au,
0x0c07b06cu,0x0c07b06eu,0x0c07b070u,0x0c07b072u,0x0c07b074u,0x0c07b076u,0x0c07b078u,0x0c07b07au,0x0c07b07cu,0x0c07b07eu,0x0c07b080u,0x0c07b082u,0x0c07b084u,0x0c07b086u,0x0c07b088u,0x0c07b08au,
0x0c07b08cu,0x0c07b08eu,0x0c07b090u,0x0c07b092u,0x0c07b094u,0x0c07b096u,0x0c07b098u,0x0c07b09au,0x0c07b09cu,0x0c07b09eu,0x0c07b0a0u,0x0c07b0a2u,0x0c07b0a4u,0x0c07b0a6u,0x0c07b0a8u,0x0c07b0aau,
0x0c07b0acu,0x0c07b0aeu,0x0c07b0b0u,0x0c07b0b2u,0x0c07b0b4u,0x0c07b0b6u,0x0c07b0b8u,0x0c07b0bau,0x0c07b0bcu,0x0c07b0beu,0x0c07b0c0u,0x0c07b0c2u,0x0c087534u,0x0c087536u,0x0c087538u,0x0c08753au,
0x0c08753cu,0x0c08753eu,0x0c087540u,0x0c087542u,0x0c087544u,0x0c087546u,0x0c087548u,0x0c08754au,0x0c08754cu,0x0c08754eu,0x0c087550u,0x0c087552u,0x0c087554u,0x0c087556u,0x0c087558u,0x0c08755au,
0x0c08755cu,0x0c08755eu,0x0c087560u,0x0c087562u,0x0c087564u,0x0c087566u,0x0c087568u,0x0c08756au,0x0c08756cu,0x0c08756eu,0x0c087570u,0x0c087572u,0x0c087574u,0x0c087576u,0x0c087578u,0x0c08757au,
0x0c08757cu,0x0c08757eu,0x0c087580u,0x0c087582u,0x0c087584u,0x0c087586u,0x0c087588u,0x0c08758au,0x0c08758cu,0x0c08758eu,0x0c087590u,0x0c087592u,0x0c087594u,0x0c087596u,0x0c087598u,0x0c08759au,
0x0c08759cu,0x0c08759eu,0x0c0875a0u,0x0c0875a2u,0x0c0875a4u,0x0c0875a6u,0x0c0875a8u,0x0c0875aau,0x0c0875acu,0x0c0875aeu,0x0c0875ceu,0x0c0875d0u,0x0c0875d2u,0x0c0875d4u,0x0c0875d6u,0x0c0875d8u,
0x0c0875dau,0x0c0875dcu,0x0c0875deu,0x0c0875e0u,0x0c0875e2u,0x0c0875e4u,0x0c0875e6u,0x0c0875e8u,0x0c0875eau,0x0c0875ecu,0x0c0875eeu,0x0c0881ccu,0x0c0881ceu,0x0c0881d0u,0x0c0881d2u,0x0c0881d4u,
0x0c0881d6u,0x0c0881d8u,0x0c0881dau,0x0c0881fau,0x0c0881fcu,0x0c0881feu,0x0c088200u,0x0c088202u,0x0c088204u,0x0c088206u,0x0c088208u,0x0c08820au,0x0c08820cu,0x0c08820eu,0x0c088210u,0x0c088212u,
0x0c088214u,0x0c088216u,0x0c088218u,0x0c08821au,0x0c08821cu,0x0c08821eu,0x0c088220u,0x0c088222u,0x0c088224u,0x0c088226u,0x0c088228u,0x0c08822au,0x0c08822cu,0x0c08822eu,0x0c088230u,0x0c088232u,
0x0c088234u,0x0c088236u,0x0c088238u,0x0c08823au,0x0c08823cu,0x0c08823eu,0x0c088240u,0x0c088242u,0x0c088244u,0x0c088246u,0x0c088248u,0x0c08824au,0x0c08824cu,0x0c08824eu,0x0c088250u,0x0c088252u,
0x0c088254u,0x0c088256u,0x0c088258u,0x0c08825au,0x0c08825cu,0x0c08825eu,0x0c088260u,0x0c088262u,0x0c088264u,0x0c088266u,0x0c088268u,0x0c08826au,0x0c08826cu,0x0c08826eu,0x0c088270u,0x0c088272u,
0x0c088274u,0x0c088276u,0x0c088278u,0x0c08827au,0x0c08827cu,0x0c08827eu,0x0c088280u,0x0c088282u,0x0c088284u,0x0c088286u,0x0c088288u,0x0c08828au,0x0c08828cu,0x0c08828eu,0x0c088290u,0x0c088292u,
0x0c088294u,0x0c088296u,0x0c088298u,0x0c08829au,0x0c08829cu,0x0c08829eu,0x0c0882a0u,0x0c0887ecu,0x0c0887eeu,0x0c0887f0u,0x0c0887f2u,0x0c0887f4u,0x0c0887f6u,0x0c0887f8u,0x0c0887fau,0x0c0887fcu,
0x0c0887feu,0x0c088800u,0x0c088802u,0x0c088804u,0x0c088806u,0x0c088808u,0x0c08880au,0x0c08880cu,0x0c08880eu,0x0c088810u,0x0c088812u,0x0c088814u,0x0c088816u,0x0c088818u,0x0c08881au,0x0c08881cu,
0x0c08881eu,0x0c088820u,0x0c088822u,0x0c088824u,0x0c088826u,0x0c088828u,0x0c08882au,0x0c08882cu,0x0c08882eu,0x0c088830u,0x0c088832u,0x0c088834u,0x0c088836u,0x0c088838u,0x0c08883au,0x0c08883cu,
0x0c088ef0u,0x0c088ef2u,0x0c088ef4u,0x0c088ef6u,0x0c088ef8u,0x0c088efau,0x0c088efcu,0x0c088efeu,0x0c088f00u,0x0c088f02u,0x0c088f04u,0x0c088f06u,0x0c088f08u,0x0c088f0au,0x0c088f0cu,0x0c088f0eu,
0x0c088f10u,0x0c088f12u,0x0c088f14u,0x0c088f16u,0x0c088f18u,0x0c088f1au,0x0c088f1cu,0x0c088f1eu,0x0c088f20u,0x0c088f22u,0x0c088f24u,0x0c088f26u,0x0c088f28u,0x0c088f2au,0x0c088f2cu,0x0c088f2eu,
0x0c088f30u,0x0c088f32u,0x0c088f34u,0x0c088f36u,0x0c088f38u,0x0c088f3au,0x0c088f3cu,0x0c088f3eu,0x0c088f40u,0x0c088f42u,0x0c088f44u,0x0c088f46u,0x0c088f48u,0x0c088f4au,0x0c088f4cu,0x0c088f4eu,
0x0c088f50u,0x0c088f52u,0x0c088f54u,0x0c088f56u,0x0c088f58u,0x0c088f5au,0x0c088f5cu,0x0c088f5eu,0x0c088f60u,0x0c088f62u,0x0c088f64u,0x0c088f66u,0x0c088f68u,0x0c088f6au,0x0c088f6cu,0x0c088f6eu,
0x0c088f70u,0x0c088f72u,0x0c088f74u,0x0c088f76u,0x0c088f78u,0x0c088f7au,0x0c088f7cu,0x0c088f7eu,0x0c088f80u,0x0c088f82u,0x0c088f84u,0x0c088f86u,0x0c088f88u,0x0c088f8au,0x0c088f8cu,0x0c088f8eu,
0x0c088f90u,0x0c088f92u,0x0c088f94u,0x0c088f96u,0x0c088f98u,0x0c088f9au,0x0c088f9cu,0x0c088f9eu,0x0c088fa0u,0x0c088fa2u,0x0c088fa4u,0x0c088fa6u,0x0c088fa8u,0x0c088faau,0x0c088facu,0x0c088faeu,
0x0c088fb0u,0x0c088fb2u,0x0c088fb4u,0x0c088fb6u,0x0c088fb8u,0x0c088fbau,0x0c088fbcu,0x0c088fbeu,0x0c088fc0u,0x0c088fc2u,0x0c088fc4u,0x0c088fc6u,0x0c088fc8u,0x0c088fcau,0x0c088fccu,0x0c088fceu,
0x0c088fe0u,0x0c088fe2u,0x0c088fe4u,0x0c088fe6u,0x0c088fe8u,0x0c088feau,0x0c088fecu,0x0c088feeu,0x0c088ff0u,0x0c088ff2u,0x0c088ff4u,0x0c088ff6u,0x0c088ff8u,0x0c088ffau,0x0c088ffcu,0x0c088ffeu,
0x0c089000u,0x0c089002u,0x0c089004u,0x0c089006u,0x0c089008u,0x0c08900au,0x0c08900cu,0x0c08900eu,0x0c089010u,0x0c089012u,0x0c089014u,0x0c089016u,0x0c089018u,0x0c08901au,0x0c08901cu,0x0c08901eu,
0x0c089020u,0x0c089022u,0x0c089024u,0x0c089026u,0x0c089028u,0x0c08902au,0x0c08902cu,0x0c08902eu,0x0c089030u,0x0c089032u,0x0c089034u,0x0c089036u,0x0c089038u,0x0c08903au,0x0c08903cu,0x0c08903eu,
0x0c089040u,0x0c089042u,0x0c089044u,0x0c089046u,0x0c089048u,0x0c08904au,0x0c08904cu,0x0c08904eu,0x0c089050u,0x0c089052u,0x0c089054u,0x0c089056u,0x0c089058u,0x0c08905au,0x0c08905cu,0x0c08905eu,
0x0c089060u,0x0c089062u,0x0c089064u,0x0c089066u,0x0c089068u,0x0c08906au,0x0c08906cu,0x0c08906eu,0x0c089070u,0x0c089072u,0x0c089074u,0x0c089076u,0x0c089078u,0x0c08907au,0x0c08907cu,0x0c08907eu,
0x0c089080u,0x0c089082u,0x0c089084u,0x0c089086u,0x0c089088u,0x0c08908au,0x0c08908cu,0x0c08908eu,0x0c089090u,0x0c089092u,0x0c089094u,0x0c089096u,0x0c089098u,0x0c08909au,0x0c08909cu,0x0c08909eu,
0x0c0890a0u,0x0c0890a2u,0x0c0890a4u,0x0c0890a6u,0x0c0890a8u,0x0c0890aau,0x0c0890acu,0x0c0890aeu,0x0c0890b0u,0x0c0890b2u,0x0c0890b4u,0x0c0890b6u,0x0c0890b8u,0x0c0890bau,0x0c0890bcu,0x0c0890beu,
0x0c0890c0u,0x0c0890c2u,0x0c0890c4u,0x0c0890c6u,0x0c0890c8u,0x0c0890cau,0x0c0890ccu,0x0c0890ceu,0x0c0890d0u,0x0c0890d2u,0x0c0890d4u,0x0c0890d6u,0x0c0890d8u,0x0c0890dau,0x0c0890dcu,0x0c0890deu,
0x0c0890e0u,0x0c0890e2u,0x0c0890e4u,0x0c0890e6u,0x0c0890e8u,0x0c0890eau,0x0c0890ecu,0x0c0890eeu,0x0c0890f0u,0x0c0890f2u,0x0c0890f4u,0x0c0890f6u,0x0c0890f8u,0x0c0890fau,0x0c0890fcu,0x0c0890feu,
0x0c089100u,0x0c089102u,0x0c089104u,0x0c089106u,0x0c089108u,0x0c08910au,0x0c08910cu,0x0c08910eu,0x0c089110u,0x0c089112u,0x0c089114u,0x0c089116u,0x0c089118u,0x0c08911au,0x0c08911cu,0x0c08911eu,
0x0c089120u,0x0c089122u,0x0c089124u,0x0c089126u,0x0c089128u,0x0c08912au,0x0c08912cu,0x0c08912eu,0x0c089130u,0x0c089132u,0x0c089134u,0x0c089136u,0x0c089138u,0x0c08913au,0x0c08913cu,0x0c08913eu,
0x0c089140u,0x0c089142u,0x0c089144u,0x0c089174u,0x0c089176u,0x0c089178u,0x0c08917au,0x0c08917cu,0x0c08917eu,0x0c089180u,0x0c089182u,0x0c089184u,0x0c08927eu,0x0c089280u,0x0c089282u,0x0c089284u,
0x0c089286u,0x0c089288u,0x0c08928au,0x0c08928cu,0x0c08928eu,0x0c089290u,0x0c089292u,0x0c089294u,0x0c089296u,0x0c089298u,0x0c0892b8u,0x0c0892bau,0x0c0892bcu,0x0c0892beu,0x0c0892c0u,0x0c0892c2u,
0x0c0892c4u,0x0c0892c6u,0x0c0892c8u,0x0c0892cau,0x0c0892ccu,0x0c0892ceu,0x0c0892d0u,0x0c0892d2u,0x0c0892d4u,0x0c0892d6u,0x0c0892d8u,0x0c0892dau,0x0c0892dcu,0x0c0892deu,0x0c0892e0u,0x0c0892e2u,
0x0c0892e4u,0x0c0892e6u,0x0c0892e8u,0x0c0892eau,0x0c0892ecu,0x0c0892eeu,0x0c0892f0u,0x0c0892f2u,0x0c0892f4u,0x0c0892f6u,0x0c0892f8u,0x0c0892fau,0x0c0892fcu,0x0c0892feu,0x0c089300u,0x0c089302u,
0x0c089304u,0x0c089306u,0x0c089308u,0x0c08930au,0x0c08930cu,0x0c08930eu,0x0c089310u,0x0c089312u,0x0c089314u,0x0c089316u,0x0c089318u,0x0c08931au,0x0c08931cu,0x0c08931eu,0x0c089320u,0x0c089322u,
0x0c089324u,0x0c089326u,0x0c089328u,0x0c08932au,0x0c08932cu,0x0c08932eu,0x0c089330u,0x0c089332u,0x0c089334u,0x0c089336u,0x0c089338u,0x0c08933au,0x0c08933cu,0x0c08933eu,0x0c089340u,0x0c089342u,
0x0c089344u,0x0c089346u,0x0c089b50u,0x0c089b52u,0x0c089b54u,0x0c089b56u,0x0c089b58u,0x0c089b5au,0x0c089b5cu,0x0c089b5eu,0x0c089b60u,0x0c089b62u,0x0c089b64u,0x0c089b66u,0x0c089b68u,0x0c089b6au,
0x0c089b6cu,0x0c089b6eu,0x0c089b70u,0x0c089b72u,0x0c089b74u,0x0c089b76u,0x0c089b78u,0x0c089b7au,0x0c089b7cu,0x0c089b7eu,0x0c089b80u,0x0c089b82u,0x0c089b84u,0x0c089b86u,0x0c089b88u,0x0c089b8au,
0x0c089b8cu,0x0c089b8eu,0x0c089b90u,0x0c089b92u,0x0c089b94u,0x0c089b96u,0x0c089b98u,0x0c089b9au,0x0c089b9cu,0x0c089b9eu,0x0c089ba0u,0x0c089ba2u,0x0c089ba4u,0x0c089ba6u,0x0c089ba8u,0x0c089baau,
0x0c089bacu,0x0c089baeu,0x0c089bb0u,0x0c089bb2u,0x0c089bb4u,0x0c089bb6u,0x0c089bb8u,0x0c089bbau,0x0c089bbcu,0x0c089bbeu,0x0c089bc0u,0x0c089bc2u,0x0c089bc4u,0x0c089bc6u,0x0c089bc8u,0x0c089bcau,
0x0c089bccu,0x0c089bceu,0x0c089bd0u,0x0c089bd2u,0x0c089bd4u,0x0c089bd6u,0x0c089bd8u,0x0c089bdau,0x0c089bdcu,0x0c089bdeu,0x0c089be0u,0x0c089be2u,0x0c089be4u,0x0c089be6u,0x0c089be8u,0x0c089beau,
0x0c089becu,0x0c089beeu,0x0c089bf0u,0x0c089bf2u,0x0c089bf4u,0x0c089bf6u,0x0c089bf8u,0x0c089bfau,0x0c089bfcu,0x0c089bfeu,0x0c089c00u,0x0c089c02u,0x0c089c04u,0x0c089c38u,0x0c089c3au,0x0c089c3cu,
0x0c089c3eu,0x0c089c40u,0x0c089c42u,0x0c089c44u,0x0c089c46u,0x0c089c48u,0x0c089c4au,0x0c089c4cu,0x0c089c4eu,0x0c089c50u,0x0c089c52u,0x0c089c54u,0x0c089c56u,0x0c089c58u,0x0c089c5au,0x0c089c5cu,
0x0c089c5eu,0x0c089c60u,0x0c089c62u,0x0c089c64u,0x0c089c66u,0x0c089c68u,0x0c089c6au,0x0c089c6cu,0x0c089c6eu,0x0c089c70u,0x0c089c72u,0x0c089c74u,0x0c089c76u,0x0c089c78u,0x0c089c7au,0x0c089c7cu,
0x0c089c7eu,0x0c089c80u,0x0c089c82u,0x0c089c84u,0x0c089c86u,0x0c089c88u,0x0c089c8au,0x0c089c8cu,0x0c089c8eu,0x0c089c90u,0x0c089c92u,0x0c089c94u,0x0c089c96u,0x0c089c98u,0x0c089c9au,0x0c089c9cu,
0x0c089c9eu,0x0c089ca0u,0x0c089ca2u,0x0c089ca4u,0x0c089ca6u,0x0c089ca8u,0x0c089caau,0x0c089cacu,0x0c089caeu,0x0c089cb0u,0x0c089cb2u,0x0c089cb4u,0x0c089cb6u,0x0c089cb8u,0x0c089cbau,0x0c089cbcu,
0x0c089cbeu,0x0c089cc0u,0x0c089cc2u,0x0c089cc4u,0x0c089cc6u,0x0c089cc8u,0x0c089ccau,0x0c089cccu,0x0c089cceu,0x0c089cd0u,0x0c089cd2u,0x0c089cd4u,0x0c089cd6u,0x0c089cd8u,0x0c089cdau,0x0c089cdcu,
0x0c089cdeu,0x0c089ce0u,0x0c089ce2u,0x0c089ce4u,0x0c089ce6u,0x0c089ce8u,0x0c089ceau,0x0c089cecu,0x0c089ceeu,0x0c089cf0u,0x0c089cf2u,0x0c089cf4u,0x0c089cf6u,0x0c089cf8u,0x0c089cfau,0x0c089cfcu,
0x0c089cfeu,0x0c089d00u,0x0c089d02u,0x0c089d04u,0x0c089d06u,0x0c089d08u,0x0c089d0au,0x0c089d0cu,0x0c089d0eu,0x0c089d10u,0x0c089d12u,0x0c089d14u,0x0c089d16u,0x0c089d18u,0x0c089d1au,0x0c089d1cu,
0x0c089d1eu,0x0c089d20u,0x0c089d22u,0x0c089d24u,0x0c089d26u,0x0c089d66u,0x0c089d68u,0x0c089d6au,0x0c089d6cu,0x0c089d6eu,0x0c089d70u,0x0c089d72u,0x0c089d74u,0x0c089d76u,0x0c089d78u,0x0c089d7au,
0x0c089d7cu,0x0c089d7eu,0x0c089d80u,0x0c089d82u,0x0c089d84u,0x0c089d86u,0x0c089d88u,0x0c089d8au,0x0c089d8cu,0x0c089d8eu,0x0c089d90u,0x0c089d92u,0x0c089d94u,0x0c089d96u,0x0c089d98u,0x0c089d9au,
0x0c089d9cu,0x0c089d9eu,0x0c089da0u,0x0c089da2u,0x0c089da4u,0x0c089da6u,0x0c089da8u,0x0c089daau,0x0c089dacu,0x0c089daeu,0x0c089db0u,0x0c089db2u,0x0c089db4u,0x0c089db6u,0x0c089db8u,0x0c089dbau,
0x0c089dbcu,0x0c089dbeu,0x0c089dc0u,0x0c089dc2u,0x0c089dc4u,0x0c089dc6u,0x0c089dc8u,0x0c089dcau,0x0c089dccu,0x0c089dceu,0x0c089dd0u,0x0c089dd2u,0x0c089dd4u,0x0c089dd6u,0x0c089dd8u,0x0c089ddau,
0x0c089ddcu,0x0c089ddeu,0x0c089de0u,0x0c089de2u,0x0c089de4u,0x0c089de6u,0x0c089de8u,0x0c089deau,0x0c089decu,0x0c089deeu,0x0c089df0u,0x0c089df2u,0x0c089df4u,0x0c089df6u,0x0c089df8u,0x0c089dfau,
0x0c089dfcu,0x0c089dfeu,0x0c089e00u,0x0c089e02u,0x0c089e04u,0x0c089e06u,0x0c089e08u,0x0c089e0au,0x0c089e0cu,0x0c089e0eu,0x0c089e10u,0x0c089e12u,0x0c089e14u,0x0c089e16u,0x0c089e18u,0x0c089e1au,
0x0c089e1cu,0x0c089e1eu,0x0c089e20u,0x0c089e22u,0x0c089e24u,0x0c089e26u,0x0c089e28u,0x0c089e2au,0x0c089e2cu,0x0c089e2eu,0x0c089e40u,0x0c089e42u,0x0c089e44u,0x0c089e46u,0x0c089e48u,0x0c089e4au,
0x0c089e4cu,0x0c089e4eu,0x0c089e50u,0x0c089e52u,0x0c089e54u,0x0c089e56u,0x0c089e58u,0x0c089e5au,0x0c089e5cu,0x0c089e5eu,0x0c089e60u,0x0c089e62u,0x0c089e64u,0x0c089e66u,0x0c089e68u,0x0c089e6au,
0x0c089e6cu,0x0c089e6eu,0x0c089e84u,0x0c089e86u,0x0c089e88u,0x0c089e8au,0x0c089e8cu,0x0c089e8eu,0x0c089e90u,0x0c089e92u,0x0c089e94u,0x0c089e96u,0x0c089e98u,0x0c089e9au,0x0c089e9cu,0x0c089e9eu,
0x0c089ea0u,0x0c089ea2u,0x0c089ea4u,0x0c089ea6u,0x0c089ea8u,0x0c089eaau,0x0c089eacu,0x0c089eaeu,0x0c089eb0u,0x0c089eb2u,0x0c089eb4u,0x0c089eb6u,0x0c089eb8u,0x0c089ebau,0x0c089ebcu,0x0c089ebeu,
0x0c089ec0u,0x0c089ec2u,0x0c089ec4u,0x0c089ec6u,0x0c089ec8u,0x0c089ecau,0x0c089eccu,0x0c089eceu,0x0c089ed0u,0x0c089ed2u,0x0c089ed4u,0x0c089ed6u,0x0c089ed8u,0x0c089edau,0x0c089edcu,0x0c089edeu,
0x0c089ee0u,0x0c089ee2u,0x0c089ee4u,0x0c089ee6u,0x0c089ee8u,0x0c089eeau,0x0c089eecu,0x0c089eeeu,0x0c089ef0u,0x0c089ef2u,0x0c089ef4u,0x0c089ef6u,0x0c089ef8u,0x0c089efau,0x0c089efcu,0x0c089efeu,
0x0c089f00u,0x0c089f02u,0x0c089f04u,0x0c089f06u,0x0c089f08u,0x0c089f0au,0x0c089f0cu,0x0c089f0eu,0x0c089f10u,0x0c089f12u,0x0c089f14u,0x0c089f16u,0x0c089f18u,0x0c089f1au,0x0c089f1cu,0x0c089f1eu,
0x0c089f20u,0x0c089f22u,0x0c089f24u,0x0c089f26u,0x0c089f28u,0x0c089f2au,0x0c089f2cu,0x0c089f2eu,0x0c089f30u,0x0c089f32u,0x0c089f34u,0x0c089f36u,0x0c089f38u,0x0c089f3au,0x0c089f3cu,0x0c089f3eu,
0x0c089f40u,0x0c089f42u,0x0c089f44u,0x0c089f46u,0x0c089f48u,0x0c089f4au,0x0c089f4cu,0x0c089f4eu,0x0c089f50u,0x0c089f52u,0x0c089f54u,0x0c089f56u,0x0c089f58u,0x0c089f5au,0x0c089f5cu,0x0c089f5eu,
0x0c089f60u,0x0c089f62u,0x0c089f64u,0x0c089f66u,0x0c089f68u,0x0c089f6au,0x0c089f6cu,0x0c089f6eu,0x0c089f70u,0x0c089f72u,0x0c089f74u,0x0c089f76u,0x0c089f78u,0x0c089f7au,0x0c089f7cu,0x0c089f7eu,
0x0c089f80u,0x0c089f82u,0x0c089f84u,0x0c089f86u,0x0c089f88u,0x0c089f8au,0x0c089f8cu,0x0c093390u,0x0c093392u,0x0c093394u,0x0c093396u,0x0c093398u,0x0c09339au,0x0c09339cu,0x0c09339eu,0x0c0933a0u,
0x0c0933a2u,0x0c0933a4u,0x0c0933a6u,0x0c0933a8u,0x0c0933aau,0x0c0933acu,0x0c0933aeu,0x0c0933b0u,0x0c0933b2u,0x0c0933b4u,0x0c0933b6u,0x0c0933b8u,0x0c0933bau,0x0c0933bcu,0x0c0933beu,0x0c0933c0u,
0x0c0933c2u,0x0c0933c4u,0x0c0933c6u,0x0c0933c8u,0x0c0933cau,0x0c0933ccu,0x0c0933ceu,0x0c0933d0u,0x0c0933d2u,0x0c0933d4u,0x0c0933d6u,0x0c0933d8u,0x0c0933dau,0x0c0933dcu,0x0c0933deu,0x0c0933e0u,
0x0c0933e2u,0x0c0933e4u,0x0c0933e6u,0x0c0933e8u,0x0c0933eau,0x0c0933ecu,0x0c0933eeu,0x0c0933f0u,0x0c0933f2u,0x0c0933f4u,0x0c0933f6u,0x0c0933f8u,0x0c0933fau,0x0c0933fcu,0x0c0933feu,0x0c093400u,
0x0c093402u,0x0c093404u,0x0c093406u,0x0c093408u,0x0c09340au,0x0c09340cu,0x0c09340eu,0x0c093410u,0x0c09abc4u,0x0c09abc6u,0x0c09abc8u,0x0c09abcau,0x0c09abccu,0x0c09abceu,0x0c09abd0u,0x0c09abd2u,
0x0c09abd4u,0x0c09abd6u,0x0c09abd8u,0x0c09abdau,0x0c09abdcu,0x0c09abdeu,0x0c09abe0u,0x0c09abe2u,0x0c09abe4u,0x0c09abe6u,0x0c09abe8u,0x0c09abeau,0x0c09abecu,0x0c09abeeu,0x0c09abf0u,0x0c09abf2u,
0x0c09abf4u,0x0c09abf6u,0x0c09abf8u,0x0c09abfau,0x0c09abfcu,0x0c09abfeu,0x0c09ac00u,0x0c09ac02u,0x0c09ac04u,0x0c09d844u,0x0c09d846u,0x0c09d848u,0x0c09d84au,0x0c09d84cu,0x0c09d84eu,0x0c09d850u,
0x0c09d852u,0x0c09d854u,0x0c09d856u,0x0c09d858u,0x0c09d85au,0x0c09d85cu,0x0c09d85eu,0x0c09d860u,0x0c09d862u,0x0c09d864u,0x0c09d866u,0x0c09d868u,0x0c09d86au,0x0c09d86cu,0x0c09d86eu,0x0c09d870u,
0x0c09d872u,0x0c09d874u,0x0c09d876u,0x0c09d878u,0x0c09d87au,0x0c09d87cu,0x0c09d87eu,0x0c09d880u,0x0c09d882u,0x0c09d884u,0x0c09d886u,0x0c09d888u,0x0c09d88au,0x0c09d88cu,0x0c09d88eu,0x0c09d890u,
0x0c09d892u,0x0c09d894u,0x0c09d896u,0x0c09d898u,0x0c09d89au,0x0c09d89cu,0x0c09d89eu,0x0c09d8a0u,0x0c09d8a2u,0x0c09d8a4u,0x0c09d8a6u,0x0c09d8a8u,0x0c09d8aau,0x0c09d8acu,0x0c09d8aeu,0x0c09d8b0u,
0x0c09d8b2u,0x0c09d8b4u,0x0c09d8b6u,0x0c09d8b8u,0x0c09d8bau,0x0c09d8bcu,0x0c09d8beu,0x0c09d8c0u,0x0c09d8c2u,0x0c09d8c4u,0x0c09d8c6u,0x0c09d8c8u,0x0c09d8cau,0x0c09d8ccu,0x0c09d8ceu,0x0c09d8d0u,
0x0c09d8d2u,0x0c09d8d4u,0x0c09d8d6u,0x0c09d8d8u,0x0c09d8dau,0x0c09d8dcu,0x0c09d8deu,0x0c09d8e0u,0x0c09d8e2u,0x0c09d8e4u,0x0c09d8e6u,0x0c09d8e8u,0x0c09d8eau,0x0c09d8ecu,0x0c09d8eeu,0x0c09d8f0u,
0x0c09d8f2u,0x0c09d8f4u,0x0c09d8f6u,0x0c09d8f8u,0x0c09d8fau,0x0c09d8fcu,0x0c09d8feu,0x0c09d900u,0x0c09d902u,0x0c09d904u,0x0c09d906u,0x0c09d908u,0x0c09d90au,0x0c09d90cu,0x0c09d90eu,0x0c09d910u,
0x0c09d912u,0x0c09d914u,0x0c09d916u,0x0c09d918u,0x0c09d91au,0x0c09d91cu,0x0c09d91eu,0x0c09d920u,0x0c09d922u,0x0c09d924u,0x0c09d926u,0x0c09d928u,0x0c09d92au,0x0c09d92cu,0x0c09d92eu,0x0c09d930u,
0x0c09d932u,0x0c09d934u,0x0c09d936u,0x0c09d938u,0x0c09d93au,0x0c09d93cu,0x0c09d93eu,0x0c09d940u,0x0c09d942u,0x0c09d944u,0x0c09d946u,0x0c09d948u,0x0c09d94au,0x0c09d94cu,0x0c09d94eu,0x0c09d950u,
0x0c09d952u,0x0c09d954u,0x0c09d956u,0x0c09d958u,0x0c09d95au,0x0c09d95cu,0x0c09d95eu,0x0c09d960u,0x0c09d962u,0x0c09d964u,0x0c09d966u,0x0c09d968u,0x0c09d96au,0x0c09d96cu,0x0c09d96eu,0x0c09d970u,
0x0c09d972u,0x0c09d974u,0x0c09d976u,0x0c09d978u,0x0c09d98cu,0x0c09d98eu,0x0c09d990u,0x0c09d992u,0x0c09d994u,0x0c09d996u,0x0c09d998u,0x0c09d99au,0x0c09d99cu,0x0c09d99eu,0x0c09d9a0u,0x0c09d9a2u,
0x0c09d9a4u,0x0c09d9a6u,0x0c09d9a8u,0x0c09d9aau,0x0c09d9acu,0x0c09d9aeu,0x0c09d9b0u,0x0c09d9b2u,0x0c09d9b4u,0x0c09d9b6u,0x0c09d9b8u,0x0c09d9bau,0x0c09d9bcu,0x0c09d9beu,0x0c09d9c0u,0x0c09d9c2u,
0x0c09d9c4u,0x0c09d9c6u,0x0c09d9c8u,0x0c09d9cau,0x0c09d9ccu,0x0c09d9ceu,0x0c09d9d0u,0x0c09d9d2u,0x0c09d9d4u,0x0c09d9d6u,0x0c09d9d8u,0x0c09d9dau,0x0c09d9dcu,0x0c09d9deu,0x0c09d9e0u,0x0c09d9e2u,
0x0c09d9e4u,0x0c09d9e6u,0x0c09d9e8u,0x0c0a2f90u,0x0c0a2f92u,0x0c0a2f94u,0x0c0a2f96u,0x0c0a2f98u,0x0c0a2f9au,0x0c0a2f9cu,0x0c0a2f9eu,0x0c0a2fa0u,0x0c0a2fa2u,0x0c0a2fa4u,0x0c0a2fa6u,0x0c0a2fa8u,
0x0c0a2faau,0x0c0a2facu,0x0c0a2faeu,0x0c0a2fb0u,0x0c0a2fb2u,0x0c0a2fb4u,0x0c0a2fb6u,0x0c0a2fb8u,0x0c0a2fbau,0x0c0a2fbcu,0x0c0a2fbeu,0x0c0a2fc0u,0x0c0a2fc2u,0x0c0a2fc4u,0x0c0a2fc6u,0x0c0a2fc8u,
0x0c0a2fcau,0x0c0a2fccu,0x0c0a2fceu,0x0c0a2fd0u,0x0c0a2fd2u,0x0c0a2fd4u,0x0c0a2fd6u,0x0c0a2fd8u,0x0c0a2fdau,0x0c0a2fdcu,0x0c0a2fdeu,0x0c0a2fe0u,0x0c0a2fe2u,0x0c0a2fe4u,0x0c0a2fe6u,0x0c0a2fe8u,
0x0c0a2feau,0x0c0a2fecu,0x0c0a2feeu,0x0c0a2ff0u,0x0c0a2ff2u,0x0c0a2ff4u,0x0c0a2ff6u,0x0c0a2ff8u,0x0c0a2ffau,0x0c0a2ffcu,0x0c0a2ffeu,0x0c0a3000u,0x0c0a3002u,0x0c0a3004u,0x0c0a3006u,0x0c0a3008u,
0x0c0a300au,0x0c0a300cu,0x0c0a300eu,0x0c0a3010u,0x0c0a3012u,0x0c0a3014u,0x0c0a3016u,0x0c0a3018u,0x0c0a301au,0x0c0a301cu,0x0c0a301eu,0x0c0a3020u,0x0c0a3022u,0x0c0a3024u,0x0c0a3026u,0x0c0a3028u,
0x0c0ace3eu,0x0c0ace40u,0x0c0ace42u,0x0c0ace44u,0x0c0ace46u,0x0c0ace48u,0x0c0ace4au,0x0c0ace4cu,0x0c0ace4eu,0x0c0ace50u,0x0c0ace52u,0x0c0ace54u,0x0c0ace56u,0x0c0ace58u,0x0c0ace5au,0x0c0ace5cu,
0x0c0ace5eu,0x0c0ace60u,0x0c0ace62u,0x0c0ace64u,0x0c0ace66u,0x0c0ace68u,0x0c0ace6au,0x0c0ace6cu,0x0c0ace6eu,0x0c0ace70u,0x0c0ace72u,0x0c0ace74u,0x0c0ace76u,0x0c0ace78u,0x0c0ace7au,0x0c0ace7cu,
0x0c0ace7eu,0x0c0ace80u,0x0c0ace82u,0x0c0ace84u,0x0c0ace86u,0x0c0ace88u,0x0c0ace8au,0x0c0ace8cu,0x0c0ace8eu,0x0c0ace90u,0x0c0ace92u,0x0c0ace94u,0x0c0ace96u,0x0c0ace98u,0x0c0ace9au,0x0c0ace9cu,
0x0c0ace9eu,0x0c0acea0u,0x0c0acea2u,0x0c0acea4u,0x0c0acea6u,0x0c0acea8u,0x0c0aceaau,0x0c0aceacu,0x0c0aceaeu,0x0c0aceb0u,0x0c0aceb2u,0x0c0aceb4u,0x0c0aceb6u,0x0c0aceb8u,0x0c0acebau,0x0c0acebcu,
0x0c0acebeu,0x0c0acec0u,0x0c0acec2u,0x0c0acec4u,0x0c0acec6u,0x0c0acec8u,0x0c0acecau,0x0c0aceccu,0x0c0aceceu,0x0c0aced0u,0x0c0aced2u,0x0c0aced4u,0x0c0aced6u,0x0c0aced8u,0x0c0b2518u,0x0c0b251au,
0x0c0b251cu,0x0c0b251eu,0x0c0b2520u,0x0c0b2522u,0x0c0b2524u,0x0c0b2526u,0x0c0b2528u,0x0c0b252au,0x0c0b252cu,0x0c0b252eu,0x0c0b2530u,0x0c0b2532u,0x0c0b2534u,0x0c0b2536u,0x0c0b2538u,0x0c0b253au,
0x0c0b253cu,0x0c0b253eu,0x0c0b2540u,0x0c0b2542u,0x0c0b2544u,0x0c0b2546u,0x0c0b2548u,0x0c0b254au,0x0c0b254cu,0x0c0b254eu,0x0c0b2550u,0x0c0b2552u,0x0c0b2554u,0x0c0b2556u,0x0c0b2558u,0x0c0b255au,
0x0c0b255cu,0x0c0b255eu,0x0c0b2560u,0x0c0b2562u,0x0c0b2564u,0x0c0b2566u,0x0c0b2568u,0x0c0b256au,0x0c0b256cu,0x0c0b256eu,0x0c0b2570u,0x0c0b2572u,0x0c0b2574u,0x0c0b2576u,0x0c0b2578u,0x0c0b257au,
0x0c0b257cu,0x0c0b257eu,0x0c0b2580u,0x0c0b2582u,0x0c0b2584u,0x0c0b2586u,0x0c0b2588u,0x0c0b258au,0x0c0b258cu,0x0c0b258eu,0x0c0b2590u,0x0c0b2592u,0x0c0c6482u,0x0c0c6484u,0x0c0c6486u,0x0c0c6488u,
0x0c0c648au,0x0c0c648cu,0x0c0c648eu,0x0c0c6490u,0x0c0c6492u,0x0c0c6494u,0x0c0c6496u,0x0c0c6498u,0x0c0c649au,0x0c0c649cu,0x0c0c649eu,0x0c0c64a0u,0x0c0c64a2u,0x0c0c64a4u,0x0c0c64a6u,0x0c0c64a8u,
0x0c0c64aau,0x0c0c64acu,0x0c0c64aeu,0x0c0c64b0u,0x0c0c64b2u,0x0c0c64b4u,0x0c0c64b6u,0x0c0c64e0u,0x0c0c64e2u,0x0c0c64e4u,0x0c0c64e6u,0x0c0c64e8u,0x0c0c64eau,0x0c0c64ecu,0x0c0c64eeu,0x0c0c64f0u,
0x0c0c64f2u,0x0c0c64f4u,0x0c0c64f6u,0x0c0c64f8u,0x0c0c64fau,0x0c0c64fcu,0x0c0c64feu,0x0c0c6500u,0x0c0c6502u,0x0c0c6504u,0x0c0c6506u,0x0c0c6508u,0x0c0c650au,0x0c0c650cu,0x0c0c650eu,0x0c0c6510u,
0x0c0c6512u,0x0c0c6514u,0x0c0c6516u,0x0c0c6518u,0x0c0c651au,0x0c0c651cu,0x0c0c651eu,0x0c0c6520u,0x0c0c6522u,0x0c0c6524u,0x0c0c6526u,0x0c0c6528u,0x0c0c652au,0x0c0c652cu,0x0c0c652eu,0x0c0c6530u,
0x0c0c6532u,0x0c0c6534u,0x0c0c6536u,0x0c0c6538u,0x0c0c653au,0x0c0c653cu,0x0c0c653eu,0x0c0c6540u,0x0c0c6542u,0x0c0c6544u,0x0c0c6546u,0x0c0c6548u,0x0c0c654au,0x0c0c654cu,0x0c0c654eu,0x0c0c6550u,
0x0c0c6552u,0x0c0c6554u,0x0c0c6556u,0x0c0c6558u,0x0c0c655au,0x0c0c655cu,0x0c0c655eu,0x0c0c6560u,0x0c0c6562u,0x0c0c99feu,0x0c0c9a00u,0x0c0c9a02u,0x0c0c9a04u,0x0c0c9a06u,0x0c0c9a08u,0x0c0c9a0au,
0x0c0c9a0cu,0x0c0c9a0eu,0x0c0c9a10u,0x0c0c9a12u,0x0c0c9a14u,0x0c0c9a16u,0x0c0c9a18u,0x0c0c9a1au,0x0c0c9a1cu,0x0c0c9a1eu,0x0c0c9a20u,0x0c0c9a22u,0x0c0c9a24u,0x0c0c9a26u,0x0c0c9a28u,0x0c0c9a2au,
0x0c0c9a2cu,0x0c0c9a2eu,0x0c0c9a30u,0x0c0c9a32u,0x0c0c9a34u,0x0c0c9a36u,0x0c0c9a38u,0x0c0c9a3au,0x0c0c9a3cu,0x0c0c9a3eu,0x0c0c9a40u,0x0c0c9a42u,0x0c0c9a44u,0x0c0c9a46u,0x0c0c9a48u,0x0c0c9a4au,
0x0c0c9a4cu,0x0c0c9a4eu,0x0c0c9a50u,0x0c0c9a52u,0x0c0c9a54u,0x0c0c9a56u,0x0c0c9a58u,0x0c0c9a5au,0x0c0c9a5cu,0x0c0c9a5eu,0x0c0c9a60u,0x0c0c9a62u,0x0c0c9a64u,0x0c0c9a66u,0x0c0c9a68u,0x0c0c9a6au,
0x0c0c9a6cu,0x0c0c9a6eu,0x0c0c9a70u,0x0c0c9a72u,0x0c0c9a74u,0x0c0c9a76u,0x0c0c9a78u,
};
int vf3_target_broad_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
