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
int vf3_away_batch57_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06938cu: goto P_0c06938c;
case 0x0c06938eu: goto P_0c06938e;
case 0x0c069390u: goto P_0c069390;
case 0x0c069392u: goto P_0c069392;
case 0x0c069394u: goto P_0c069394;
case 0x0c069396u: goto P_0c069396;
case 0x0c069398u: goto P_0c069398;
case 0x0c06939au: goto P_0c06939a;
case 0x0c06939cu: goto P_0c06939c;
case 0x0c06939eu: goto P_0c06939e;
case 0x0c0693a0u: goto P_0c0693a0;
case 0x0c0693a2u: goto P_0c0693a2;
case 0x0c0693a4u: goto P_0c0693a4;
case 0x0c0693a6u: goto P_0c0693a6;
case 0x0c0693a8u: goto P_0c0693a8;
case 0x0c0693aau: goto P_0c0693aa;
case 0x0c0693acu: goto P_0c0693ac;
case 0x0c0693aeu: goto P_0c0693ae;
case 0x0c0693b0u: goto P_0c0693b0;
case 0x0c0693b2u: goto P_0c0693b2;
case 0x0c0693b4u: goto P_0c0693b4;
case 0x0c0693b6u: goto P_0c0693b6;
case 0x0c0693b8u: goto P_0c0693b8;
case 0x0c0693bau: goto P_0c0693ba;
case 0x0c0693bcu: goto P_0c0693bc;
case 0x0c0693beu: goto P_0c0693be;
case 0x0c0693c0u: goto P_0c0693c0;
case 0x0c0693c2u: goto P_0c0693c2;
case 0x0c0693c4u: goto P_0c0693c4;
case 0x0c0693c6u: goto P_0c0693c6;
case 0x0c0693c8u: goto P_0c0693c8;
case 0x0c0693cau: goto P_0c0693ca;
case 0x0c0693ccu: goto P_0c0693cc;
case 0x0c0693ceu: goto P_0c0693ce;
case 0x0c0693d0u: goto P_0c0693d0;
case 0x0c0693d2u: goto P_0c0693d2;
case 0x0c0693d4u: goto P_0c0693d4;
case 0x0c0693d6u: goto P_0c0693d6;
case 0x0c0693d8u: goto P_0c0693d8;
case 0x0c0693dau: goto P_0c0693da;
case 0x0c0693dcu: goto P_0c0693dc;
case 0x0c0693deu: goto P_0c0693de;
case 0x0c0693e0u: goto P_0c0693e0;
case 0x0c0693e2u: goto P_0c0693e2;
case 0x0c0693e4u: goto P_0c0693e4;
case 0x0c0693e6u: goto P_0c0693e6;
case 0x0c0693e8u: goto P_0c0693e8;
case 0x0c0693eau: goto P_0c0693ea;
case 0x0c0693ecu: goto P_0c0693ec;
case 0x0c0693eeu: goto P_0c0693ee;
case 0x0c0693f0u: goto P_0c0693f0;
case 0x0c0693f2u: goto P_0c0693f2;
case 0x0c0693f4u: goto P_0c0693f4;
case 0x0c0693f6u: goto P_0c0693f6;
case 0x0c0693f8u: goto P_0c0693f8;
case 0x0c0693fau: goto P_0c0693fa;
case 0x0c0693fcu: goto P_0c0693fc;
case 0x0c0693feu: goto P_0c0693fe;
case 0x0c069400u: goto P_0c069400;
case 0x0c069402u: goto P_0c069402;
case 0x0c069404u: goto P_0c069404;
case 0x0c069406u: goto P_0c069406;
case 0x0c069408u: goto P_0c069408;
case 0x0c06940au: goto P_0c06940a;
case 0x0c06940cu: goto P_0c06940c;
case 0x0c06940eu: goto P_0c06940e;
case 0x0c069410u: goto P_0c069410;
case 0x0c069412u: goto P_0c069412;
case 0x0c069414u: goto P_0c069414;
case 0x0c069416u: goto P_0c069416;
case 0x0c069418u: goto P_0c069418;
case 0x0c06941au: goto P_0c06941a;
case 0x0c06941cu: goto P_0c06941c;
case 0x0c06941eu: goto P_0c06941e;
case 0x0c069420u: goto P_0c069420;
case 0x0c069422u: goto P_0c069422;
case 0x0c069424u: goto P_0c069424;
case 0x0c069426u: goto P_0c069426;
case 0x0c069428u: goto P_0c069428;
case 0x0c06942au: goto P_0c06942a;
case 0x0c06942cu: goto P_0c06942c;
case 0x0c06942eu: goto P_0c06942e;
case 0x0c069430u: goto P_0c069430;
case 0x0c069432u: goto P_0c069432;
case 0x0c069434u: goto P_0c069434;
case 0x0c069436u: goto P_0c069436;
case 0x0c069438u: goto P_0c069438;
case 0x0c06943au: goto P_0c06943a;
case 0x0c06943cu: goto P_0c06943c;
case 0x0c06943eu: goto P_0c06943e;
case 0x0c069440u: goto P_0c069440;
case 0x0c069442u: goto P_0c069442;
case 0x0c069444u: goto P_0c069444;
case 0x0c069446u: goto P_0c069446;
case 0x0c069448u: goto P_0c069448;
case 0x0c06944au: goto P_0c06944a;
case 0x0c06944cu: goto P_0c06944c;
case 0x0c06944eu: goto P_0c06944e;
case 0x0c069450u: goto P_0c069450;
case 0x0c069452u: goto P_0c069452;
case 0x0c069454u: goto P_0c069454;
case 0x0c069456u: goto P_0c069456;
case 0x0c069458u: goto P_0c069458;
case 0x0c06945au: goto P_0c06945a;
case 0x0c06945cu: goto P_0c06945c;
case 0x0c06945eu: goto P_0c06945e;
case 0x0c069460u: goto P_0c069460;
case 0x0c069462u: goto P_0c069462;
case 0x0c069464u: goto P_0c069464;
case 0x0c069466u: goto P_0c069466;
case 0x0c069468u: goto P_0c069468;
case 0x0c06946au: goto P_0c06946a;
case 0x0c06946cu: goto P_0c06946c;
case 0x0c06946eu: goto P_0c06946e;
case 0x0c069470u: goto P_0c069470;
case 0x0c069472u: goto P_0c069472;
case 0x0c069474u: goto P_0c069474;
case 0x0c069476u: goto P_0c069476;
case 0x0c069478u: goto P_0c069478;
case 0x0c06947au: goto P_0c06947a;
case 0x0c06947cu: goto P_0c06947c;
case 0x0c06947eu: goto P_0c06947e;
case 0x0c069480u: goto P_0c069480;
case 0x0c069482u: goto P_0c069482;
case 0x0c069484u: goto P_0c069484;
case 0x0c069486u: goto P_0c069486;
case 0x0c069488u: goto P_0c069488;
case 0x0c06948au: goto P_0c06948a;
case 0x0c06948cu: goto P_0c06948c;
case 0x0c06948eu: goto P_0c06948e;
case 0x0c069490u: goto P_0c069490;
case 0x0c069492u: goto P_0c069492;
case 0x0c069494u: goto P_0c069494;
case 0x0c0694b0u: goto P_0c0694b0;
case 0x0c0694b2u: goto P_0c0694b2;
case 0x0c0694b4u: goto P_0c0694b4;
case 0x0c0694b6u: goto P_0c0694b6;
case 0x0c0694b8u: goto P_0c0694b8;
case 0x0c0694bau: goto P_0c0694ba;
case 0x0c0694bcu: goto P_0c0694bc;
case 0x0c0694beu: goto P_0c0694be;
case 0x0c0694c0u: goto P_0c0694c0;
case 0x0c0694c2u: goto P_0c0694c2;
case 0x0c0694c4u: goto P_0c0694c4;
case 0x0c0694c6u: goto P_0c0694c6;
case 0x0c0694c8u: goto P_0c0694c8;
case 0x0c0694cau: goto P_0c0694ca;
case 0x0c0694ccu: goto P_0c0694cc;
case 0x0c0694ceu: goto P_0c0694ce;
case 0x0c0694d0u: goto P_0c0694d0;
case 0x0c0694d2u: goto P_0c0694d2;
case 0x0c0694d4u: goto P_0c0694d4;
case 0x0c0694d6u: goto P_0c0694d6;
case 0x0c0694d8u: goto P_0c0694d8;
case 0x0c0694dau: goto P_0c0694da;
case 0x0c0694dcu: goto P_0c0694dc;
case 0x0c0694deu: goto P_0c0694de;
case 0x0c0694e0u: goto P_0c0694e0;
case 0x0c0694e2u: goto P_0c0694e2;
case 0x0c0694e4u: goto P_0c0694e4;
case 0x0c0694e6u: goto P_0c0694e6;
case 0x0c0694e8u: goto P_0c0694e8;
case 0x0c0694eau: goto P_0c0694ea;
case 0x0c0694ecu: goto P_0c0694ec;
case 0x0c0694eeu: goto P_0c0694ee;
case 0x0c0694f0u: goto P_0c0694f0;
case 0x0c0694f2u: goto P_0c0694f2;
case 0x0c0694f4u: goto P_0c0694f4;
case 0x0c0694f6u: goto P_0c0694f6;
case 0x0c0694f8u: goto P_0c0694f8;
case 0x0c0694fau: goto P_0c0694fa;
case 0x0c0694fcu: goto P_0c0694fc;
case 0x0c0694feu: goto P_0c0694fe;
case 0x0c069500u: goto P_0c069500;
case 0x0c069502u: goto P_0c069502;
case 0x0c069504u: goto P_0c069504;
case 0x0c069506u: goto P_0c069506;
case 0x0c069508u: goto P_0c069508;
case 0x0c06950au: goto P_0c06950a;
case 0x0c06950cu: goto P_0c06950c;
case 0x0c06950eu: goto P_0c06950e;
case 0x0c069510u: goto P_0c069510;
case 0x0c069512u: goto P_0c069512;
case 0x0c069514u: goto P_0c069514;
case 0x0c069516u: goto P_0c069516;
case 0x0c069518u: goto P_0c069518;
case 0x0c08a068u: goto P_0c08a068;
case 0x0c08a06au: goto P_0c08a06a;
case 0x0c08a06cu: goto P_0c08a06c;
case 0x0c08a06eu: goto P_0c08a06e;
case 0x0c08a070u: goto P_0c08a070;
case 0x0c08a072u: goto P_0c08a072;
case 0x0c08a074u: goto P_0c08a074;
case 0x0c08a076u: goto P_0c08a076;
case 0x0c08a078u: goto P_0c08a078;
case 0x0c08a07au: goto P_0c08a07a;
case 0x0c08a07cu: goto P_0c08a07c;
case 0x0c08a07eu: goto P_0c08a07e;
case 0x0c08a080u: goto P_0c08a080;
case 0x0c08a082u: goto P_0c08a082;
case 0x0c08a084u: goto P_0c08a084;
case 0x0c08a086u: goto P_0c08a086;
case 0x0c08a088u: goto P_0c08a088;
case 0x0c08a08au: goto P_0c08a08a;
case 0x0c08a08cu: goto P_0c08a08c;
case 0x0c08a08eu: goto P_0c08a08e;
case 0x0c08a090u: goto P_0c08a090;
case 0x0c08a092u: goto P_0c08a092;
case 0x0c08a094u: goto P_0c08a094;
case 0x0c08a096u: goto P_0c08a096;
case 0x0c08a098u: goto P_0c08a098;
case 0x0c08a09au: goto P_0c08a09a;
case 0x0c08a09cu: goto P_0c08a09c;
case 0x0c08a09eu: goto P_0c08a09e;
case 0x0c08a0a0u: goto P_0c08a0a0;
case 0x0c08a0a2u: goto P_0c08a0a2;
case 0x0c08a0a4u: goto P_0c08a0a4;
case 0x0c08a0a6u: goto P_0c08a0a6;
case 0x0c08a0a8u: goto P_0c08a0a8;
case 0x0c08a0aau: goto P_0c08a0aa;
case 0x0c08a0acu: goto P_0c08a0ac;
case 0x0c08a0aeu: goto P_0c08a0ae;
case 0x0c08a0b0u: goto P_0c08a0b0;
case 0x0c08a0b2u: goto P_0c08a0b2;
case 0x0c08a0b4u: goto P_0c08a0b4;
case 0x0c08a0b6u: goto P_0c08a0b6;
case 0x0c08a0b8u: goto P_0c08a0b8;
case 0x0c08a0bau: goto P_0c08a0ba;
case 0x0c08a0bcu: goto P_0c08a0bc;
case 0x0c08a0beu: goto P_0c08a0be;
case 0x0c08a0c0u: goto P_0c08a0c0;
case 0x0c08a0c2u: goto P_0c08a0c2;
case 0x0c08a0c4u: goto P_0c08a0c4;
case 0x0c08a0c6u: goto P_0c08a0c6;
case 0x0c08a0c8u: goto P_0c08a0c8;
case 0x0c08a0cau: goto P_0c08a0ca;
case 0x0c08a0ccu: goto P_0c08a0cc;
case 0x0c08a0ceu: goto P_0c08a0ce;
case 0x0c08a0d0u: goto P_0c08a0d0;
case 0x0c08a0d2u: goto P_0c08a0d2;
case 0x0c08a0d4u: goto P_0c08a0d4;
case 0x0c08a0d6u: goto P_0c08a0d6;
case 0x0c08a0d8u: goto P_0c08a0d8;
case 0x0c08a0dau: goto P_0c08a0da;
case 0x0c08a0dcu: goto P_0c08a0dc;
case 0x0c08a0deu: goto P_0c08a0de;
case 0x0c08a0e0u: goto P_0c08a0e0;
case 0x0c08a0e2u: goto P_0c08a0e2;
case 0x0c08a0e4u: goto P_0c08a0e4;
case 0x0c08a0e6u: goto P_0c08a0e6;
case 0x0c08a0e8u: goto P_0c08a0e8;
case 0x0c08a0eau: goto P_0c08a0ea;
case 0x0c08a0ecu: goto P_0c08a0ec;
case 0x0c08a0eeu: goto P_0c08a0ee;
case 0x0c08a0f0u: goto P_0c08a0f0;
case 0x0c08a0f2u: goto P_0c08a0f2;
case 0x0c08a0f4u: goto P_0c08a0f4;
case 0x0c08a0f6u: goto P_0c08a0f6;
case 0x0c08a0f8u: goto P_0c08a0f8;
case 0x0c08a0fau: goto P_0c08a0fa;
case 0x0c08a0fcu: goto P_0c08a0fc;
case 0x0c08a0feu: goto P_0c08a0fe;
case 0x0c08a100u: goto P_0c08a100;
case 0x0c08a102u: goto P_0c08a102;
case 0x0c08a104u: goto P_0c08a104;
case 0x0c08a106u: goto P_0c08a106;
case 0x0c08a108u: goto P_0c08a108;
case 0x0c08a10au: goto P_0c08a10a;
case 0x0c08a10cu: goto P_0c08a10c;
case 0x0c08a10eu: goto P_0c08a10e;
case 0x0c08a110u: goto P_0c08a110;
case 0x0c08a112u: goto P_0c08a112;
case 0x0c08a114u: goto P_0c08a114;
case 0x0c08a116u: goto P_0c08a116;
case 0x0c08a118u: goto P_0c08a118;
case 0x0c08a11au: goto P_0c08a11a;
case 0x0c08a11cu: goto P_0c08a11c;
case 0x0c08a11eu: goto P_0c08a11e;
case 0x0c08a120u: goto P_0c08a120;
case 0x0c08a122u: goto P_0c08a122;
case 0x0c08a124u: goto P_0c08a124;
case 0x0c08a126u: goto P_0c08a126;
case 0x0c08a128u: goto P_0c08a128;
case 0x0c08a12au: goto P_0c08a12a;
case 0x0c08a12cu: goto P_0c08a12c;
case 0x0c08a12eu: goto P_0c08a12e;
case 0x0c08a130u: goto P_0c08a130;
case 0x0c08a132u: goto P_0c08a132;
case 0x0c08a134u: goto P_0c08a134;
case 0x0c08a136u: goto P_0c08a136;
case 0x0c08a138u: goto P_0c08a138;
case 0x0c08a13au: goto P_0c08a13a;
case 0x0c08a13cu: goto P_0c08a13c;
case 0x0c08a13eu: goto P_0c08a13e;
case 0x0c08a140u: goto P_0c08a140;
case 0x0c08a142u: goto P_0c08a142;
case 0x0c08a144u: goto P_0c08a144;
case 0x0c08a146u: goto P_0c08a146;
case 0x0c08a148u: goto P_0c08a148;
case 0x0c08a14au: goto P_0c08a14a;
case 0x0c08a14cu: goto P_0c08a14c;
case 0x0c08a14eu: goto P_0c08a14e;
case 0x0c08a150u: goto P_0c08a150;
case 0x0c08a152u: goto P_0c08a152;
case 0x0c08a154u: goto P_0c08a154;
case 0x0c08a156u: goto P_0c08a156;
case 0x0c08a158u: goto P_0c08a158;
case 0x0c08a15au: goto P_0c08a15a;
case 0x0c08a15cu: goto P_0c08a15c;
case 0x0c08a15eu: goto P_0c08a15e;
case 0x0c08a160u: goto P_0c08a160;
case 0x0c08a162u: goto P_0c08a162;
case 0x0c08a164u: goto P_0c08a164;
case 0x0c08a166u: goto P_0c08a166;
case 0x0c08a168u: goto P_0c08a168;
case 0x0c08a16au: goto P_0c08a16a;
case 0x0c08a16cu: goto P_0c08a16c;
case 0x0c08a16eu: goto P_0c08a16e;
case 0x0c08a170u: goto P_0c08a170;
case 0x0c08a172u: goto P_0c08a172;
case 0x0c08a174u: goto P_0c08a174;
case 0x0c08a176u: goto P_0c08a176;
case 0x0c08a178u: goto P_0c08a178;
case 0x0c08a17au: goto P_0c08a17a;
case 0x0c08a17cu: goto P_0c08a17c;
case 0x0c08a17eu: goto P_0c08a17e;
case 0x0c08a180u: goto P_0c08a180;
case 0x0c08a182u: goto P_0c08a182;
case 0x0c08a184u: goto P_0c08a184;
case 0x0c08a186u: goto P_0c08a186;
case 0x0c08a188u: goto P_0c08a188;
case 0x0c08a18au: goto P_0c08a18a;
case 0x0c08a18cu: goto P_0c08a18c;
case 0x0c08a18eu: goto P_0c08a18e;
case 0x0c08a190u: goto P_0c08a190;
case 0x0c08a192u: goto P_0c08a192;
case 0x0c08a194u: goto P_0c08a194;
case 0x0c08a196u: goto P_0c08a196;
case 0x0c08a198u: goto P_0c08a198;
case 0x0c08a19au: goto P_0c08a19a;
case 0x0c08a19cu: goto P_0c08a19c;
case 0x0c08a19eu: goto P_0c08a19e;
case 0x0c08a1a0u: goto P_0c08a1a0;
case 0x0c08a1a2u: goto P_0c08a1a2;
case 0x0c08a1a4u: goto P_0c08a1a4;
case 0x0c08a1a6u: goto P_0c08a1a6;
case 0x0c08a1a8u: goto P_0c08a1a8;
case 0x0c08a1aau: goto P_0c08a1aa;
case 0x0c08a1acu: goto P_0c08a1ac;
case 0x0c08a1aeu: goto P_0c08a1ae;
case 0x0c08a1b0u: goto P_0c08a1b0;
case 0x0c08a1b2u: goto P_0c08a1b2;
case 0x0c08a1b4u: goto P_0c08a1b4;
case 0x0c08a1b6u: goto P_0c08a1b6;
case 0x0c08a1b8u: goto P_0c08a1b8;
case 0x0c08a1bau: goto P_0c08a1ba;
case 0x0c08a1bcu: goto P_0c08a1bc;
case 0x0c08a1beu: goto P_0c08a1be;
case 0x0c08a1c0u: goto P_0c08a1c0;
case 0x0c08a1c2u: goto P_0c08a1c2;
case 0x0c08a1c4u: goto P_0c08a1c4;
case 0x0c08a1c6u: goto P_0c08a1c6;
case 0x0c08a1c8u: goto P_0c08a1c8;
case 0x0c08a1cau: goto P_0c08a1ca;
case 0x0c08a1ccu: goto P_0c08a1cc;
case 0x0c08a1ceu: goto P_0c08a1ce;
case 0x0c08a1d0u: goto P_0c08a1d0;
case 0x0c08a1d2u: goto P_0c08a1d2;
case 0x0c08a1d4u: goto P_0c08a1d4;
case 0x0c08a1d6u: goto P_0c08a1d6;
case 0x0c08a1d8u: goto P_0c08a1d8;
case 0x0c08a1dau: goto P_0c08a1da;
case 0x0c08a1dcu: goto P_0c08a1dc;
case 0x0c08a23cu: goto P_0c08a23c;
case 0x0c08a23eu: goto P_0c08a23e;
case 0x0c08a240u: goto P_0c08a240;
case 0x0c08a242u: goto P_0c08a242;
case 0x0c08a244u: goto P_0c08a244;
case 0x0c08a246u: goto P_0c08a246;
case 0x0c08a248u: goto P_0c08a248;
case 0x0c08a24au: goto P_0c08a24a;
case 0x0c08a24cu: goto P_0c08a24c;
case 0x0c08a24eu: goto P_0c08a24e;
case 0x0c08a250u: goto P_0c08a250;
case 0x0c08a252u: goto P_0c08a252;
case 0x0c08a254u: goto P_0c08a254;
case 0x0c08a256u: goto P_0c08a256;
case 0x0c08a258u: goto P_0c08a258;
case 0x0c08a25au: goto P_0c08a25a;
case 0x0c08a25cu: goto P_0c08a25c;
case 0x0c08a25eu: goto P_0c08a25e;
case 0x0c08a260u: goto P_0c08a260;
case 0x0c08a262u: goto P_0c08a262;
case 0x0c08a264u: goto P_0c08a264;
case 0x0c08a266u: goto P_0c08a266;
case 0x0c08a268u: goto P_0c08a268;
case 0x0c08a26au: goto P_0c08a26a;
case 0x0c08a26cu: goto P_0c08a26c;
case 0x0c08a26eu: goto P_0c08a26e;
case 0x0c08a270u: goto P_0c08a270;
case 0x0c08a272u: goto P_0c08a272;
case 0x0c08a274u: goto P_0c08a274;
case 0x0c08a276u: goto P_0c08a276;
case 0x0c08a278u: goto P_0c08a278;
case 0x0c08a27au: goto P_0c08a27a;
case 0x0c08a27cu: goto P_0c08a27c;
case 0x0c08a27eu: goto P_0c08a27e;
case 0x0c08a280u: goto P_0c08a280;
case 0x0c08a282u: goto P_0c08a282;
case 0x0c08a284u: goto P_0c08a284;
case 0x0c08a286u: goto P_0c08a286;
case 0x0c08a288u: goto P_0c08a288;
case 0x0c08a28au: goto P_0c08a28a;
case 0x0c08a28cu: goto P_0c08a28c;
case 0x0c08a28eu: goto P_0c08a28e;
case 0x0c08a290u: goto P_0c08a290;
case 0x0c08a292u: goto P_0c08a292;
case 0x0c08a294u: goto P_0c08a294;
case 0x0c08a296u: goto P_0c08a296;
case 0x0c08a298u: goto P_0c08a298;
case 0x0c08a29au: goto P_0c08a29a;
case 0x0c08a29cu: goto P_0c08a29c;
case 0x0c08a29eu: goto P_0c08a29e;
case 0x0c08a2a0u: goto P_0c08a2a0;
case 0x0c08a2a2u: goto P_0c08a2a2;
case 0x0c08a2a4u: goto P_0c08a2a4;
case 0x0c08a2a6u: goto P_0c08a2a6;
case 0x0c08a2a8u: goto P_0c08a2a8;
case 0x0c08a2aau: goto P_0c08a2aa;
case 0x0c08a2acu: goto P_0c08a2ac;
case 0x0c08a2aeu: goto P_0c08a2ae;
case 0x0c08a2b0u: goto P_0c08a2b0;
case 0x0c08a2b2u: goto P_0c08a2b2;
case 0x0c08a2b4u: goto P_0c08a2b4;
case 0x0c08a2b6u: goto P_0c08a2b6;
case 0x0c08a2b8u: goto P_0c08a2b8;
case 0x0c08a2bau: goto P_0c08a2ba;
case 0x0c08a2bcu: goto P_0c08a2bc;
case 0x0c08a2beu: goto P_0c08a2be;
case 0x0c08a2c0u: goto P_0c08a2c0;
case 0x0c08a2c2u: goto P_0c08a2c2;
case 0x0c08a2c4u: goto P_0c08a2c4;
case 0x0c08a2c6u: goto P_0c08a2c6;
case 0x0c08a2c8u: goto P_0c08a2c8;
case 0x0c08a2cau: goto P_0c08a2ca;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06938c: /* original 2fe6, guest PC 0x0c06938c */
if(!s->budget--) { s->failed_pc=0x0c06938cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06938e;
P_0c06938e: /* original e004, guest PC 0x0c06938e */
if(!s->budget--) { s->failed_pc=0x0c06938eu; return 0; }
r[0]=0x00000004u;
goto P_0c069390;
P_0c069390: /* original 2fd6, guest PC 0x0c069390 */
if(!s->budget--) { s->failed_pc=0x0c069390u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069392;
P_0c069392: /* original 6d43, guest PC 0x0c069392 */
if(!s->budget--) { s->failed_pc=0x0c069392u; return 0; }
r[13]=r[4];
goto P_0c069394;
P_0c069394: /* original 2fc6, guest PC 0x0c069394 */
if(!s->budget--) { s->failed_pc=0x0c069394u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069396;
P_0c069396: /* original ec0f, guest PC 0x0c069396 */
if(!s->budget--) { s->failed_pc=0x0c069396u; return 0; }
r[12]=0x0000000fu;
goto P_0c069398;
P_0c069398: /* original 2fb6, guest PC 0x0c069398 */
if(!s->budget--) { s->failed_pc=0x0c069398u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06939a;
P_0c06939a: /* original 6b53, guest PC 0x0c06939a */
if(!s->budget--) { s->failed_pc=0x0c06939au; return 0; }
r[11]=r[5];
goto P_0c06939c;
P_0c06939c: /* original fffb, guest PC 0x0c06939c */
if(!s->budget--) { s->failed_pc=0x0c06939cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06939e;
P_0c06939e: /* original 4f22, guest PC 0x0c06939e */
if(!s->budget--) { s->failed_pc=0x0c06939eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0693a0;
P_0c0693a0: /* original 7fd8, guest PC 0x0c0693a0 */
if(!s->budget--) { s->failed_pc=0x0c0693a0u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0693a2;
P_0c0693a2: /* original 66f3, guest PC 0x0c0693a2 */
if(!s->budget--) { s->failed_pc=0x0c0693a2u; return 0; }
r[6]=r[15];
goto P_0c0693a4;
P_0c0693a4: /* original 65f3, guest PC 0x0c0693a4 */
if(!s->budget--) { s->failed_pc=0x0c0693a4u; return 0; }
r[5]=r[15];
goto P_0c0693a6;
P_0c0693a6: /* original 7604, guest PC 0x0c0693a6 */
if(!s->budget--) { s->failed_pc=0x0c0693a6u; return 0; }
r[6]+=0x00000004u;
goto P_0c0693a8;
P_0c0693a8: /* original ff4a, guest PC 0x0c0693a8 */
if(!s->budget--) { s->failed_pc=0x0c0693a8u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0693aa;
P_0c0693aa: /* original ff57, guest PC 0x0c0693aa */
if(!s->budget--) { s->failed_pc=0x0c0693aau; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0693ac;
P_0c0693ac: /* original d33a, guest PC 0x0c0693ac */
if(!s->budget--) { s->failed_pc=0x0c0693acu; return 0; }
r[3]=read(ram,0x0c069498u,4);
goto P_0c0693ae;
P_0c0693ae: /* original 6030, guest PC 0x0c0693ae */
if(!s->budget--) { s->failed_pc=0x0c0693aeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0693b0;
P_0c0693b0: /* original 600c, guest PC 0x0c0693b0 */
if(!s->budget--) { s->failed_pc=0x0c0693b0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0693b2;
P_0c0693b2: /* original 2c09, guest PC 0x0c0693b2 */
if(!s->budget--) { s->failed_pc=0x0c0693b2u; return 0; }
r[12]&=r[0];
goto P_0c0693b4;
P_0c0693b4: /* original bcce, guest PC 0x0c0693b4 */
if(!s->budget--) { s->failed_pc=0x0c0693b4u; return 0; }
target=code_base|0x0c068d54u; r[16]=code_base|0x0c0693b8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0693b8u) { target=s->pc; goto dispatch; }
goto P_0c0693b8;
P_0c0693b6: /* original 64c3, guest PC 0x0c0693b6 */
if(!s->budget--) { s->failed_pc=0x0c0693b6u; return 0; }
r[4]=r[12];
goto P_0c0693b8;
P_0c0693b8: /* original 906d, guest PC 0x0c0693b8 */
if(!s->budget--) { s->failed_pc=0x0c0693b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069496u,2);
goto P_0c0693ba;
P_0c0693ba: /* original d538, guest PC 0x0c0693ba */
if(!s->budget--) { s->failed_pc=0x0c0693bau; return 0; }
r[5]=read(ram,0x0c06949cu,4);
goto P_0c0693bc;
P_0c0693bc: /* original 035e, guest PC 0x0c0693bc */
if(!s->budget--) { s->failed_pc=0x0c0693bcu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0693be;
P_0c0693be: /* original 2338, guest PC 0x0c0693be */
if(!s->budget--) { s->failed_pc=0x0c0693beu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0693c0;
P_0c0693c0: /* original 8b07, guest PC 0x0c0693c0 */
if(!s->budget--) { s->failed_pc=0x0c0693c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693d2; }
goto P_0c0693c2;
P_0c0693c2: /* original e004, guest PC 0x0c0693c2 */
if(!s->budget--) { s->failed_pc=0x0c0693c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0693c4;
P_0c0693c4: /* original 64b3, guest PC 0x0c0693c4 */
if(!s->budget--) { s->failed_pc=0x0c0693c4u; return 0; }
r[4]=r[11];
goto P_0c0693c6;
P_0c0693c6: /* original f5f6, guest PC 0x0c0693c6 */
if(!s->budget--) { s->failed_pc=0x0c0693c6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0693c8;
P_0c0693c8: /* original bd0c, guest PC 0x0c0693c8 */
if(!s->budget--) { s->failed_pc=0x0c0693c8u; return 0; }
target=code_base|0x0c068de4u; r[16]=code_base|0x0c0693ccu;
vf3_matrix_load(s,ram,4,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0693ccu) { target=s->pc; goto dispatch; }
goto P_0c0693cc;
P_0c0693ca: /* original f4f8, guest PC 0x0c0693ca */
if(!s->budget--) { s->failed_pc=0x0c0693cau; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0693cc;
P_0c0693cc: /* original fd0a, guest PC 0x0c0693cc */
if(!s->budget--) { s->failed_pc=0x0c0693ccu; return 0; }
vf3_matrix_store(s,ram,0,r[13]);
goto P_0c0693ce;
P_0c0693ce: /* original a09c, guest PC 0x0c0693ce */
if(!s->budget--) { s->failed_pc=0x0c0693ceu; return 0; }
r[0]=0x00000000u;
goto P_0c06950a;
P_0c0693d0: /* original e000, guest PC 0x0c0693d0 */
if(!s->budget--) { s->failed_pc=0x0c0693d0u; return 0; }
r[0]=0x00000000u;
goto P_0c0693d2;
P_0c0693d2: /* original c733, guest PC 0x0c0693d2 */
if(!s->budget--) { s->failed_pc=0x0c0693d2u; return 0; }
r[0]=code_base|0x000694a0u;
goto P_0c0693d4;
P_0c0693d4: /* original f3f8, guest PC 0x0c0693d4 */
if(!s->budget--) { s->failed_pc=0x0c0693d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0693d6;
P_0c0693d6: /* original f408, guest PC 0x0c0693d6 */
if(!s->budget--) { s->failed_pc=0x0c0693d6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0693d8;
P_0c0693d8: /* original f435, guest PC 0x0c0693d8 */
if(!s->budget--) { s->failed_pc=0x0c0693d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0693da;
P_0c0693da: /* original 8f0c, guest PC 0x0c0693da */
if(!s->budget--) { s->failed_pc=0x0c0693dau; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693de;
P_0c0693dc: /* original ff8d, guest PC 0x0c0693dc */
if(!s->budget--) { s->failed_pc=0x0c0693dcu; return 0; }
fr[15]=0;
goto P_0c0693de;
P_0c0693de: /* original e004, guest PC 0x0c0693de */
if(!s->budget--) { s->failed_pc=0x0c0693deu; return 0; }
r[0]=0x00000004u;
goto P_0c0693e0;
P_0c0693e0: /* original f2f6, guest PC 0x0c0693e0 */
if(!s->budget--) { s->failed_pc=0x0c0693e0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0693e2;
P_0c0693e2: /* original f425, guest PC 0x0c0693e2 */
if(!s->budget--) { s->failed_pc=0x0c0693e2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c0693e4;
P_0c0693e4: /* original 8b07, guest PC 0x0c0693e4 */
if(!s->budget--) { s->failed_pc=0x0c0693e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693e6;
P_0c0693e6: /* original c72f, guest PC 0x0c0693e6 */
if(!s->budget--) { s->failed_pc=0x0c0693e6u; return 0; }
r[0]=code_base|0x000694a4u;
goto P_0c0693e8;
P_0c0693e8: /* original f108, guest PC 0x0c0693e8 */
if(!s->budget--) { s->failed_pc=0x0c0693e8u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0693ea;
P_0c0693ea: /* original f315, guest PC 0x0c0693ea */
if(!s->budget--) { s->failed_pc=0x0c0693eau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c0693ec;
P_0c0693ec: /* original 8b03, guest PC 0x0c0693ec */
if(!s->budget--) { s->failed_pc=0x0c0693ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693ee;
P_0c0693ee: /* original c72d, guest PC 0x0c0693ee */
if(!s->budget--) { s->failed_pc=0x0c0693eeu; return 0; }
r[0]=code_base|0x000694a4u;
goto P_0c0693f0;
P_0c0693f0: /* original f308, guest PC 0x0c0693f0 */
if(!s->budget--) { s->failed_pc=0x0c0693f0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0693f2;
P_0c0693f2: /* original f235, guest PC 0x0c0693f2 */
if(!s->budget--) { s->failed_pc=0x0c0693f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0693f4;
P_0c0693f4: /* original 8902, guest PC 0x0c0693f4 */
if(!s->budget--) { s->failed_pc=0x0c0693f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0693fc; }
goto P_0c0693f6;
P_0c0693f6: /* original fdfa, guest PC 0x0c0693f6 */
if(!s->budget--) { s->failed_pc=0x0c0693f6u; return 0; }
vf3_matrix_store(s,ram,15,r[13]);
goto P_0c0693f8;
P_0c0693f8: /* original a05c, guest PC 0x0c0693f8 */
if(!s->budget--) { s->failed_pc=0x0c0693f8u; return 0; }
r[14]=0x00000001u;
goto P_0c0694b4;
P_0c0693fa: /* original ee01, guest PC 0x0c0693fa */
if(!s->budget--) { s->failed_pc=0x0c0693fau; return 0; }
r[14]=0x00000001u;
goto P_0c0693fc;
P_0c0693fc: /* original c72a, guest PC 0x0c0693fc */
if(!s->budget--) { s->failed_pc=0x0c0693fcu; return 0; }
r[0]=code_base|0x000694a8u;
goto P_0c0693fe;
P_0c0693fe: /* original f3f8, guest PC 0x0c0693fe */
if(!s->budget--) { s->failed_pc=0x0c0693feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c069400;
P_0c069400: /* original f408, guest PC 0x0c069400 */
if(!s->budget--) { s->failed_pc=0x0c069400u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c069402;
P_0c069402: /* original e00c, guest PC 0x0c069402 */
if(!s->budget--) { s->failed_pc=0x0c069402u; return 0; }
r[0]=0x0000000cu;
goto P_0c069404;
P_0c069404: /* original ff37, guest PC 0x0c069404 */
if(!s->budget--) { s->failed_pc=0x0c069404u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069406;
P_0c069406: /* original e004, guest PC 0x0c069406 */
if(!s->budget--) { s->failed_pc=0x0c069406u; return 0; }
r[0]=0x00000004u;
goto P_0c069408;
P_0c069408: /* original f3f6, guest PC 0x0c069408 */
if(!s->budget--) { s->failed_pc=0x0c069408u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06940a;
P_0c06940a: /* original e008, guest PC 0x0c06940a */
if(!s->budget--) { s->failed_pc=0x0c06940au; return 0; }
r[0]=0x00000008u;
goto P_0c06940c;
P_0c06940c: /* original e71f, guest PC 0x0c06940c */
if(!s->budget--) { s->failed_pc=0x0c06940cu; return 0; }
r[7]=0x0000001fu;
goto P_0c06940e;
P_0c06940e: /* original ff37, guest PC 0x0c06940e */
if(!s->budget--) { s->failed_pc=0x0c06940eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069410;
P_0c069410: /* original e00c, guest PC 0x0c069410 */
if(!s->budget--) { s->failed_pc=0x0c069410u; return 0; }
r[0]=0x0000000cu;
goto P_0c069412;
P_0c069412: /* original f5f6, guest PC 0x0c069412 */
if(!s->budget--) { s->failed_pc=0x0c069412u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c069414;
P_0c069414: /* original e008, guest PC 0x0c069414 */
if(!s->budget--) { s->failed_pc=0x0c069414u; return 0; }
r[0]=0x00000008u;
goto P_0c069416;
P_0c069416: /* original f34c, guest PC 0x0c069416 */
if(!s->budget--) { s->failed_pc=0x0c069416u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c069418;
P_0c069418: /* original f540, guest PC 0x0c069418 */
if(!s->budget--) { s->failed_pc=0x0c069418u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c06941a;
P_0c06941a: /* original f4f6, guest PC 0x0c06941a */
if(!s->budget--) { s->failed_pc=0x0c06941au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06941c;
P_0c06941c: /* original 903b, guest PC 0x0c06941c */
if(!s->budget--) { s->failed_pc=0x0c06941cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069496u,2);
goto P_0c06941e;
P_0c06941e: /* original f430, guest PC 0x0c06941e */
if(!s->budget--) { s->failed_pc=0x0c06941eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c069420;
P_0c069420: /* original 035e, guest PC 0x0c069420 */
if(!s->budget--) { s->failed_pc=0x0c069420u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c069422;
P_0c069422: /* original f53d, guest PC 0x0c069422 */
if(!s->budget--) { s->failed_pc=0x0c069422u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c069424;
P_0c069424: /* original 045a, guest PC 0x0c069424 */
if(!s->budget--) { s->failed_pc=0x0c069424u; return 0; }
r[4]=r[53];
goto P_0c069426;
P_0c069426: /* original f43d, guest PC 0x0c069426 */
if(!s->budget--) { s->failed_pc=0x0c069426u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c069428;
P_0c069428: /* original 2479, guest PC 0x0c069428 */
if(!s->budget--) { s->failed_pc=0x0c069428u; return 0; }
r[4]&=r[7];
goto P_0c06942a;
P_0c06942a: /* original 065a, guest PC 0x0c06942a */
if(!s->budget--) { s->failed_pc=0x0c06942au; return 0; }
r[6]=r[53];
goto P_0c06942c;
P_0c06942c: /* original 2679, guest PC 0x0c06942c */
if(!s->budget--) { s->failed_pc=0x0c06942cu; return 0; }
r[6]&=r[7];
goto P_0c06942e;
P_0c06942e: /* original 4608, guest PC 0x0c06942e */
if(!s->budget--) { s->failed_pc=0x0c06942eu; return 0; }
r[6]<<=2;
goto P_0c069430;
P_0c069430: /* original 4608, guest PC 0x0c069430 */
if(!s->budget--) { s->failed_pc=0x0c069430u; return 0; }
r[6]<<=2;
goto P_0c069432;
P_0c069432: /* original 4600, guest PC 0x0c069432 */
if(!s->budget--) { s->failed_pc=0x0c069432u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c069434;
P_0c069434: /* original 246b, guest PC 0x0c069434 */
if(!s->budget--) { s->failed_pc=0x0c069434u; return 0; }
r[4]|=r[6];
goto P_0c069436;
P_0c069436: /* original 4408, guest PC 0x0c069436 */
if(!s->budget--) { s->failed_pc=0x0c069436u; return 0; }
r[4]<<=2;
goto P_0c069438;
P_0c069438: /* original 343c, guest PC 0x0c069438 */
if(!s->budget--) { s->failed_pc=0x0c069438u; return 0; }
r[4]+=r[3];
goto P_0c06943a;
P_0c06943a: /* original 6442, guest PC 0x0c06943a */
if(!s->budget--) { s->failed_pc=0x0c06943au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c06943c;
P_0c06943c: /* original 6043, guest PC 0x0c06943c */
if(!s->budget--) { s->failed_pc=0x0c06943cu; return 0; }
r[0]=r[4];
goto P_0c06943e;
P_0c06943e: /* original 88ff, guest PC 0x0c06943e */
if(!s->budget--) { s->failed_pc=0x0c06943eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c069440;
P_0c069440: /* original 8936, guest PC 0x0c069440 */
if(!s->budget--) { s->failed_pc=0x0c069440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0694b0; }
goto P_0c069442;
P_0c069442: /* original d21a, guest PC 0x0c069442 */
if(!s->budget--) { s->failed_pc=0x0c069442u; return 0; }
r[2]=read(ram,0x0c0694acu,4);
goto P_0c069444;
P_0c069444: /* original 6322, guest PC 0x0c069444 */
if(!s->budget--) { s->failed_pc=0x0c069444u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c069446;
P_0c069446: /* original 343c, guest PC 0x0c069446 */
if(!s->budget--) { s->failed_pc=0x0c069446u; return 0; }
r[4]+=r[3];
goto P_0c069448;
P_0c069448: /* original 6e43, guest PC 0x0c069448 */
if(!s->budget--) { s->failed_pc=0x0c069448u; return 0; }
r[14]=r[4];
goto P_0c06944a;
P_0c06944a: /* original 60e2, guest PC 0x0c06944a */
if(!s->budget--) { s->failed_pc=0x0c06944au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c06944c;
P_0c06944c: /* original 88ff, guest PC 0x0c06944c */
if(!s->budget--) { s->failed_pc=0x0c06944cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c06944e;
P_0c06944e: /* original 8d2f, guest PC 0x0c06944e */
if(!s->budget--) { s->failed_pc=0x0c06944eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0694b0; }
goto P_0c069452;
P_0c069450: /* original 6403, guest PC 0x0c069450 */
if(!s->budget--) { s->failed_pc=0x0c069450u; return 0; }
r[4]=r[0];
goto P_0c069452;
P_0c069452: /* original e008, guest PC 0x0c069452 */
if(!s->budget--) { s->failed_pc=0x0c069452u; return 0; }
r[0]=0x00000008u;
goto P_0c069454;
P_0c069454: /* original f5f6, guest PC 0x0c069454 */
if(!s->budget--) { s->failed_pc=0x0c069454u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c069456;
P_0c069456: /* original e00c, guest PC 0x0c069456 */
if(!s->budget--) { s->failed_pc=0x0c069456u; return 0; }
r[0]=0x0000000cu;
goto P_0c069458;
P_0c069458: /* original f4f6, guest PC 0x0c069458 */
if(!s->budget--) { s->failed_pc=0x0c069458u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06945a;
P_0c06945a: /* original bdc3, guest PC 0x0c06945a */
if(!s->budget--) { s->failed_pc=0x0c06945au; return 0; }
target=code_base|0x0c068fe4u; r[16]=code_base|0x0c06945eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06945eu) { target=s->pc; goto dispatch; }
goto P_0c06945e;
P_0c06945c: /* original 64e3, guest PC 0x0c06945c */
if(!s->budget--) { s->failed_pc=0x0c06945cu; return 0; }
r[4]=r[14];
goto P_0c06945e;
P_0c06945e: /* original 6703, guest PC 0x0c06945e */
if(!s->budget--) { s->failed_pc=0x0c06945eu; return 0; }
r[7]=r[0];
goto P_0c069460;
P_0c069460: /* original 2778, guest PC 0x0c069460 */
if(!s->budget--) { s->failed_pc=0x0c069460u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c069462;
P_0c069462: /* original 8916, guest PC 0x0c069462 */
if(!s->budget--) { s->failed_pc=0x0c069462u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069492; }
goto P_0c069464;
P_0c069464: /* original e008, guest PC 0x0c069464 */
if(!s->budget--) { s->failed_pc=0x0c069464u; return 0; }
r[0]=0x00000008u;
goto P_0c069466;
P_0c069466: /* original 66f3, guest PC 0x0c069466 */
if(!s->budget--) { s->failed_pc=0x0c069466u; return 0; }
r[6]=r[15];
goto P_0c069468;
P_0c069468: /* original f5f6, guest PC 0x0c069468 */
if(!s->budget--) { s->failed_pc=0x0c069468u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c06946a;
P_0c06946a: /* original e00c, guest PC 0x0c06946a */
if(!s->budget--) { s->failed_pc=0x0c06946au; return 0; }
r[0]=0x0000000cu;
goto P_0c06946c;
P_0c06946c: /* original f4f6, guest PC 0x0c06946c */
if(!s->budget--) { s->failed_pc=0x0c06946cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06946e;
P_0c06946e: /* original 761c, guest PC 0x0c06946e */
if(!s->budget--) { s->failed_pc=0x0c06946eu; return 0; }
r[6]+=0x0000001cu;
goto P_0c069470;
P_0c069470: /* original 65d3, guest PC 0x0c069470 */
if(!s->budget--) { s->failed_pc=0x0c069470u; return 0; }
r[5]=r[13];
goto P_0c069472;
P_0c069472: /* original bf18, guest PC 0x0c069472 */
if(!s->budget--) { s->failed_pc=0x0c069472u; return 0; }
target=code_base|0x0c0692a6u; r[16]=code_base|0x0c069476u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069476u) { target=s->pc; goto dispatch; }
goto P_0c069476;
P_0c069474: /* original 64e3, guest PC 0x0c069474 */
if(!s->budget--) { s->failed_pc=0x0c069474u; return 0; }
r[4]=r[14];
goto P_0c069476;
P_0c069476: /* original 6e03, guest PC 0x0c069476 */
if(!s->budget--) { s->failed_pc=0x0c069476u; return 0; }
r[14]=r[0];
goto P_0c069478;
P_0c069478: /* original e01c, guest PC 0x0c069478 */
if(!s->budget--) { s->failed_pc=0x0c069478u; return 0; }
r[0]=0x0000001cu;
goto P_0c06947a;
P_0c06947a: /* original f3f6, guest PC 0x0c06947a */
if(!s->budget--) { s->failed_pc=0x0c06947au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06947c;
P_0c06947c: /* original e014, guest PC 0x0c06947c */
if(!s->budget--) { s->failed_pc=0x0c06947cu; return 0; }
r[0]=0x00000014u;
goto P_0c06947e;
P_0c06947e: /* original ff37, guest PC 0x0c06947e */
if(!s->budget--) { s->failed_pc=0x0c06947eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069480;
P_0c069480: /* original e020, guest PC 0x0c069480 */
if(!s->budget--) { s->failed_pc=0x0c069480u; return 0; }
r[0]=0x00000020u;
goto P_0c069482;
P_0c069482: /* original f3f6, guest PC 0x0c069482 */
if(!s->budget--) { s->failed_pc=0x0c069482u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069484;
P_0c069484: /* original e018, guest PC 0x0c069484 */
if(!s->budget--) { s->failed_pc=0x0c069484u; return 0; }
r[0]=0x00000018u;
goto P_0c069486;
P_0c069486: /* original ff37, guest PC 0x0c069486 */
if(!s->budget--) { s->failed_pc=0x0c069486u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069488;
P_0c069488: /* original e024, guest PC 0x0c069488 */
if(!s->budget--) { s->failed_pc=0x0c069488u; return 0; }
r[0]=0x00000024u;
goto P_0c06948a;
P_0c06948a: /* original f3f6, guest PC 0x0c06948a */
if(!s->budget--) { s->failed_pc=0x0c06948au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06948c;
P_0c06948c: /* original e010, guest PC 0x0c06948c */
if(!s->budget--) { s->failed_pc=0x0c06948cu; return 0; }
r[0]=0x00000010u;
goto P_0c06948e;
P_0c06948e: /* original a018, guest PC 0x0c06948e */
if(!s->budget--) { s->failed_pc=0x0c06948eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0694c2;
P_0c069490: /* original ff37, guest PC 0x0c069490 */
if(!s->budget--) { s->failed_pc=0x0c069490u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069492;
P_0c069492: /* original afda, guest PC 0x0c069492 */
if(!s->budget--) { s->failed_pc=0x0c069492u; return 0; }
r[14]+=0x00000008u;
goto P_0c06944a;
P_0c069494: /* original 7e08, guest PC 0x0c069494 */
if(!s->budget--) { s->failed_pc=0x0c069494u; return 0; }
r[14]+=0x00000008u;
if(!vf3_matrix_family(0x0c069496u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069496u; return 0; } return 1;
P_0c0694b0: /* original fdfa, guest PC 0x0c0694b0 */
if(!s->budget--) { s->failed_pc=0x0c0694b0u; return 0; }
vf3_matrix_store(s,ram,15,r[13]);
goto P_0c0694b2;
P_0c0694b2: /* original ee02, guest PC 0x0c0694b2 */
if(!s->budget--) { s->failed_pc=0x0c0694b2u; return 0; }
r[14]=0x00000002u;
goto P_0c0694b4;
P_0c0694b4: /* original e018, guest PC 0x0c0694b4 */
if(!s->budget--) { s->failed_pc=0x0c0694b4u; return 0; }
r[0]=0x00000018u;
goto P_0c0694b6;
P_0c0694b6: /* original f39d, guest PC 0x0c0694b6 */
if(!s->budget--) { s->failed_pc=0x0c0694b6u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0694b8;
P_0c0694b8: /* original ff37, guest PC 0x0c0694b8 */
if(!s->budget--) { s->failed_pc=0x0c0694b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0694ba;
P_0c0694ba: /* original e010, guest PC 0x0c0694ba */
if(!s->budget--) { s->failed_pc=0x0c0694bau; return 0; }
r[0]=0x00000010u;
goto P_0c0694bc;
P_0c0694bc: /* original fff7, guest PC 0x0c0694bc */
if(!s->budget--) { s->failed_pc=0x0c0694bcu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0694be;
P_0c0694be: /* original e014, guest PC 0x0c0694be */
if(!s->budget--) { s->failed_pc=0x0c0694beu; return 0; }
r[0]=0x00000014u;
goto P_0c0694c0;
P_0c0694c0: /* original fff7, guest PC 0x0c0694c0 */
if(!s->budget--) { s->failed_pc=0x0c0694c0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0694c2;
P_0c0694c2: /* original 60c3, guest PC 0x0c0694c2 */
if(!s->budget--) { s->failed_pc=0x0c0694c2u; return 0; }
r[0]=r[12];
goto P_0c0694c4;
P_0c0694c4: /* original 880d, guest PC 0x0c0694c4 */
if(!s->budget--) { s->failed_pc=0x0c0694c4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0694c6;
P_0c0694c6: /* original 8b02, guest PC 0x0c0694c6 */
if(!s->budget--) { s->failed_pc=0x0c0694c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0694ce; }
goto P_0c0694c8;
P_0c0694c8: /* original e204, guest PC 0x0c0694c8 */
if(!s->budget--) { s->failed_pc=0x0c0694c8u; return 0; }
r[2]=0x00000004u;
goto P_0c0694ca;
P_0c0694ca: /* original a012, guest PC 0x0c0694ca */
if(!s->budget--) { s->failed_pc=0x0c0694cau; return 0; }
r[14]|=r[2];
goto P_0c0694f2;
P_0c0694cc: /* original 2e2b, guest PC 0x0c0694cc */
if(!s->budget--) { s->failed_pc=0x0c0694ccu; return 0; }
r[14]|=r[2];
goto P_0c0694ce;
P_0c0694ce: /* original 880b, guest PC 0x0c0694ce */
if(!s->budget--) { s->failed_pc=0x0c0694ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0694d0;
P_0c0694d0: /* original 8b0f, guest PC 0x0c0694d0 */
if(!s->budget--) { s->failed_pc=0x0c0694d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0694f2; }
goto P_0c0694d2;
P_0c0694d2: /* original 63f3, guest PC 0x0c0694d2 */
if(!s->budget--) { s->failed_pc=0x0c0694d2u; return 0; }
r[3]=r[15];
goto P_0c0694d4;
P_0c0694d4: /* original 7310, guest PC 0x0c0694d4 */
if(!s->budget--) { s->failed_pc=0x0c0694d4u; return 0; }
r[3]+=0x00000010u;
goto P_0c0694d6;
P_0c0694d6: /* original 2f36, guest PC 0x0c0694d6 */
if(!s->budget--) { s->failed_pc=0x0c0694d6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0694d8;
P_0c0694d8: /* original 65d3, guest PC 0x0c0694d8 */
if(!s->budget--) { s->failed_pc=0x0c0694d8u; return 0; }
r[5]=r[13];
goto P_0c0694da;
P_0c0694da: /* original 62f3, guest PC 0x0c0694da */
if(!s->budget--) { s->failed_pc=0x0c0694dau; return 0; }
r[2]=r[15];
goto P_0c0694dc;
P_0c0694dc: /* original 721c, guest PC 0x0c0694dc */
if(!s->budget--) { s->failed_pc=0x0c0694dcu; return 0; }
r[2]+=0x0000001cu;
goto P_0c0694de;
P_0c0694de: /* original 2f26, guest PC 0x0c0694de */
if(!s->budget--) { s->failed_pc=0x0c0694deu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0694e0;
P_0c0694e0: /* original 66f3, guest PC 0x0c0694e0 */
if(!s->budget--) { s->failed_pc=0x0c0694e0u; return 0; }
r[6]=r[15];
goto P_0c0694e2;
P_0c0694e2: /* original d348, guest PC 0x0c0694e2 */
if(!s->budget--) { s->failed_pc=0x0c0694e2u; return 0; }
r[3]=read(ram,0x0c069604u,4);
goto P_0c0694e4;
P_0c0694e4: /* original 67f3, guest PC 0x0c0694e4 */
if(!s->budget--) { s->failed_pc=0x0c0694e4u; return 0; }
r[7]=r[15];
goto P_0c0694e6;
P_0c0694e6: /* original 64f3, guest PC 0x0c0694e6 */
if(!s->budget--) { s->failed_pc=0x0c0694e6u; return 0; }
r[4]=r[15];
goto P_0c0694e8;
P_0c0694e8: /* original 771c, guest PC 0x0c0694e8 */
if(!s->budget--) { s->failed_pc=0x0c0694e8u; return 0; }
r[7]+=0x0000001cu;
goto P_0c0694ea;
P_0c0694ea: /* original 7610, guest PC 0x0c0694ea */
if(!s->budget--) { s->failed_pc=0x0c0694eau; return 0; }
r[6]+=0x00000010u;
goto P_0c0694ec;
P_0c0694ec: /* original 430b, guest PC 0x0c0694ec */
if(!s->budget--) { s->failed_pc=0x0c0694ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0694f0u;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0694f0u) { target=s->pc; goto dispatch; }
goto P_0c0694f0;
P_0c0694ee: /* original 7414, guest PC 0x0c0694ee */
if(!s->budget--) { s->failed_pc=0x0c0694eeu; return 0; }
r[4]+=0x00000014u;
goto P_0c0694f0;
P_0c0694f0: /* original 7f08, guest PC 0x0c0694f0 */
if(!s->budget--) { s->failed_pc=0x0c0694f0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0694f2;
P_0c0694f2: /* original e014, guest PC 0x0c0694f2 */
if(!s->budget--) { s->failed_pc=0x0c0694f2u; return 0; }
r[0]=0x00000014u;
goto P_0c0694f4;
P_0c0694f4: /* original f3f6, guest PC 0x0c0694f4 */
if(!s->budget--) { s->failed_pc=0x0c0694f4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0694f6;
P_0c0694f6: /* original e018, guest PC 0x0c0694f6 */
if(!s->budget--) { s->failed_pc=0x0c0694f6u; return 0; }
r[0]=0x00000018u;
goto P_0c0694f8;
P_0c0694f8: /* original fb3a, guest PC 0x0c0694f8 */
if(!s->budget--) { s->failed_pc=0x0c0694f8u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c0694fa;
P_0c0694fa: /* original f3f6, guest PC 0x0c0694fa */
if(!s->budget--) { s->failed_pc=0x0c0694fau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0694fc;
P_0c0694fc: /* original e004, guest PC 0x0c0694fc */
if(!s->budget--) { s->failed_pc=0x0c0694fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0694fe;
P_0c0694fe: /* original fb37, guest PC 0x0c0694fe */
if(!s->budget--) { s->failed_pc=0x0c0694feu; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c069500;
P_0c069500: /* original e010, guest PC 0x0c069500 */
if(!s->budget--) { s->failed_pc=0x0c069500u; return 0; }
r[0]=0x00000010u;
goto P_0c069502;
P_0c069502: /* original f3f6, guest PC 0x0c069502 */
if(!s->budget--) { s->failed_pc=0x0c069502u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069504;
P_0c069504: /* original e008, guest PC 0x0c069504 */
if(!s->budget--) { s->failed_pc=0x0c069504u; return 0; }
r[0]=0x00000008u;
goto P_0c069506;
P_0c069506: /* original fb37, guest PC 0x0c069506 */
if(!s->budget--) { s->failed_pc=0x0c069506u; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c069508;
P_0c069508: /* original 60e3, guest PC 0x0c069508 */
if(!s->budget--) { s->failed_pc=0x0c069508u; return 0; }
r[0]=r[14];
goto P_0c06950a;
P_0c06950a: /* original 7f28, guest PC 0x0c06950a */
if(!s->budget--) { s->failed_pc=0x0c06950au; return 0; }
r[15]+=0x00000028u;
goto P_0c06950c;
P_0c06950c: /* original 4f26, guest PC 0x0c06950c */
if(!s->budget--) { s->failed_pc=0x0c06950cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06950e;
P_0c06950e: /* original fff9, guest PC 0x0c06950e */
if(!s->budget--) { s->failed_pc=0x0c06950eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069510;
P_0c069510: /* original 6bf6, guest PC 0x0c069510 */
if(!s->budget--) { s->failed_pc=0x0c069510u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c069512;
P_0c069512: /* original 6cf6, guest PC 0x0c069512 */
if(!s->budget--) { s->failed_pc=0x0c069512u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c069514;
P_0c069514: /* original 6df6, guest PC 0x0c069514 */
if(!s->budget--) { s->failed_pc=0x0c069514u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c069516;
P_0c069516: /* original 000b, guest PC 0x0c069516 */
if(!s->budget--) { s->failed_pc=0x0c069516u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c069518: /* original 6ef6, guest PC 0x0c069518 */
if(!s->budget--) { s->failed_pc=0x0c069518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06951au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06951au; return 0; } return 1;
P_0c08a068: /* original 2fe6, guest PC 0x0c08a068 */
if(!s->budget--) { s->failed_pc=0x0c08a068u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a06a;
P_0c08a06a: /* original e200, guest PC 0x0c08a06a */
if(!s->budget--) { s->failed_pc=0x0c08a06au; return 0; }
r[2]=0x00000000u;
goto P_0c08a06c;
P_0c08a06c: /* original 2fd6, guest PC 0x0c08a06c */
if(!s->budget--) { s->failed_pc=0x0c08a06cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a06e;
P_0c08a06e: /* original 2fc6, guest PC 0x0c08a06e */
if(!s->budget--) { s->failed_pc=0x0c08a06eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a070;
P_0c08a070: /* original 2fb6, guest PC 0x0c08a070 */
if(!s->budget--) { s->failed_pc=0x0c08a070u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a072;
P_0c08a072: /* original fffb, guest PC 0x0c08a072 */
if(!s->budget--) { s->failed_pc=0x0c08a072u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08a074;
P_0c08a074: /* original d35f, guest PC 0x0c08a074 */
if(!s->budget--) { s->failed_pc=0x0c08a074u; return 0; }
r[3]=read(ram,0x0c08a1f4u,4);
goto P_0c08a076;
P_0c08a076: /* original 4f22, guest PC 0x0c08a076 */
if(!s->budget--) { s->failed_pc=0x0c08a076u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a078;
P_0c08a078: /* original 6432, guest PC 0x0c08a078 */
if(!s->budget--) { s->failed_pc=0x0c08a078u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c08a07a;
P_0c08a07a: /* original dd5d, guest PC 0x0c08a07a */
if(!s->budget--) { s->failed_pc=0x0c08a07au; return 0; }
r[13]=read(ram,0x0c08a1f0u,4);
goto P_0c08a07c;
P_0c08a07c: /* original 1425, guest PC 0x0c08a07c */
if(!s->budget--) { s->failed_pc=0x0c08a07cu; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c08a07e;
P_0c08a07e: /* original 7fc0, guest PC 0x0c08a07e */
if(!s->budget--) { s->failed_pc=0x0c08a07eu; return 0; }
r[15]+=0xffffffc0u;
goto P_0c08a080;
P_0c08a080: /* original d15d, guest PC 0x0c08a080 */
if(!s->budget--) { s->failed_pc=0x0c08a080u; return 0; }
r[1]=read(ram,0x0c08a1f8u,4);
goto P_0c08a082;
P_0c08a082: /* original 410b, guest PC 0x0c08a082 */
if(!s->budget--) { s->failed_pc=0x0c08a082u; return 0; }
target=r[1];
r[16]=code_base|0x0c08a086u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a086u) { target=s->pc; goto dispatch; }
goto P_0c08a086;
P_0c08a084: /* original 6423, guest PC 0x0c08a084 */
if(!s->budget--) { s->failed_pc=0x0c08a084u; return 0; }
r[4]=r[2];
goto P_0c08a086;
P_0c08a086: /* original 90aa, guest PC 0x0c08a086 */
if(!s->budget--) { s->failed_pc=0x0c08a086u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1deu,2);
goto P_0c08a088;
P_0c08a088: /* original e302, guest PC 0x0c08a088 */
if(!s->budget--) { s->failed_pc=0x0c08a088u; return 0; }
r[3]=0x00000002u;
goto P_0c08a08a;
P_0c08a08a: /* original 0d34, guest PC 0x0c08a08a */
if(!s->budget--) { s->failed_pc=0x0c08a08au; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08a08c;
P_0c08a08c: /* original d25b, guest PC 0x0c08a08c */
if(!s->budget--) { s->failed_pc=0x0c08a08cu; return 0; }
r[2]=read(ram,0x0c08a1fcu,4);
goto P_0c08a08e;
P_0c08a08e: /* original 90a7, guest PC 0x0c08a08e */
if(!s->budget--) { s->failed_pc=0x0c08a08eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e0u,2);
goto P_0c08a090;
P_0c08a090: /* original 6422, guest PC 0x0c08a090 */
if(!s->budget--) { s->failed_pc=0x0c08a090u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c08a092;
P_0c08a092: /* original 95a8, guest PC 0x0c08a092 */
if(!s->budget--) { s->failed_pc=0x0c08a092u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e6u,2);
goto P_0c08a094;
P_0c08a094: /* original 044e, guest PC 0x0c08a094 */
if(!s->budget--) { s->failed_pc=0x0c08a094u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08a096;
P_0c08a096: /* original 90a5, guest PC 0x0c08a096 */
if(!s->budget--) { s->failed_pc=0x0c08a096u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e4u,2);
goto P_0c08a098;
P_0c08a098: /* original 9ea3, guest PC 0x0c08a098 */
if(!s->budget--) { s->failed_pc=0x0c08a098u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e2u,2);
goto P_0c08a09a;
P_0c08a09a: /* original 6c43, guest PC 0x0c08a09a */
if(!s->budget--) { s->failed_pc=0x0c08a09au; return 0; }
r[12]=r[4];
goto P_0c08a09c;
P_0c08a09c: /* original 0bde, guest PC 0x0c08a09c */
if(!s->budget--) { s->failed_pc=0x0c08a09cu; return 0; }
r[11]=read(ram,r[13]+r[0],4);
goto P_0c08a09e;
P_0c08a09e: /* original d358, guest PC 0x0c08a09e */
if(!s->budget--) { s->failed_pc=0x0c08a09eu; return 0; }
r[3]=read(ram,0x0c08a200u,4);
goto P_0c08a0a0;
P_0c08a0a0: /* original 3e4c, guest PC 0x0c08a0a0 */
if(!s->budget--) { s->failed_pc=0x0c08a0a0u; return 0; }
r[14]+=r[4];
goto P_0c08a0a2;
P_0c08a0a2: /* original 35bc, guest PC 0x0c08a0a2 */
if(!s->budget--) { s->failed_pc=0x0c08a0a2u; return 0; }
r[5]+=r[11];
goto P_0c08a0a4;
P_0c08a0a4: /* original 430b, guest PC 0x0c08a0a4 */
if(!s->budget--) { s->failed_pc=0x0c08a0a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a0a8u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a0a8u) { target=s->pc; goto dispatch; }
goto P_0c08a0a8;
P_0c08a0a6: /* original 64f3, guest PC 0x0c08a0a6 */
if(!s->budget--) { s->failed_pc=0x0c08a0a6u; return 0; }
r[4]=r[15];
goto P_0c08a0a8;
P_0c08a0a8: /* original c756, guest PC 0x0c08a0a8 */
if(!s->budget--) { s->failed_pc=0x0c08a0a8u; return 0; }
r[0]=code_base|0x0008a204u;
goto P_0c08a0aa;
P_0c08a0aa: /* original 64e3, guest PC 0x0c08a0aa */
if(!s->budget--) { s->failed_pc=0x0c08a0aau; return 0; }
r[4]=r[14];
goto P_0c08a0ac;
P_0c08a0ac: /* original f408, guest PC 0x0c08a0ac */
if(!s->budget--) { s->failed_pc=0x0c08a0acu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a0ae;
P_0c08a0ae: /* original 65f3, guest PC 0x0c08a0ae */
if(!s->budget--) { s->failed_pc=0x0c08a0aeu; return 0; }
r[5]=r[15];
goto P_0c08a0b0;
P_0c08a0b0: /* original 909a, guest PC 0x0c08a0b0 */
if(!s->budget--) { s->failed_pc=0x0c08a0b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e8u,2);
goto P_0c08a0b2;
P_0c08a0b2: /* original f3b6, guest PC 0x0c08a0b2 */
if(!s->budget--) { s->failed_pc=0x0c08a0b2u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c08a0b4;
P_0c08a0b4: /* original e034, guest PC 0x0c08a0b4 */
if(!s->budget--) { s->failed_pc=0x0c08a0b4u; return 0; }
r[0]=0x00000034u;
goto P_0c08a0b6;
P_0c08a0b6: /* original f340, guest PC 0x0c08a0b6 */
if(!s->budget--) { s->failed_pc=0x0c08a0b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08a0b8;
P_0c08a0b8: /* original ff37, guest PC 0x0c08a0b8 */
if(!s->budget--) { s->failed_pc=0x0c08a0b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a0ba;
P_0c08a0ba: /* original e004, guest PC 0x0c08a0ba */
if(!s->budget--) { s->failed_pc=0x0c08a0bau; return 0; }
r[0]=0x00000004u;
goto P_0c08a0bc;
P_0c08a0bc: /* original f49d, guest PC 0x0c08a0bc */
if(!s->budget--) { s->failed_pc=0x0c08a0bcu; return 0; }
fr[4]=0x3f800000u;
goto P_0c08a0be;
P_0c08a0be: /* original ff4a, guest PC 0x0c08a0be */
if(!s->budget--) { s->failed_pc=0x0c08a0beu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c08a0c0;
P_0c08a0c0: /* original ff8d, guest PC 0x0c08a0c0 */
if(!s->budget--) { s->failed_pc=0x0c08a0c0u; return 0; }
fr[15]=0;
goto P_0c08a0c2;
P_0c08a0c2: /* original fff7, guest PC 0x0c08a0c2 */
if(!s->budget--) { s->failed_pc=0x0c08a0c2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0c4;
P_0c08a0c4: /* original e008, guest PC 0x0c08a0c4 */
if(!s->budget--) { s->failed_pc=0x0c08a0c4u; return 0; }
r[0]=0x00000008u;
goto P_0c08a0c6;
P_0c08a0c6: /* original fff7, guest PC 0x0c08a0c6 */
if(!s->budget--) { s->failed_pc=0x0c08a0c6u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0c8;
P_0c08a0c8: /* original e010, guest PC 0x0c08a0c8 */
if(!s->budget--) { s->failed_pc=0x0c08a0c8u; return 0; }
r[0]=0x00000010u;
goto P_0c08a0ca;
P_0c08a0ca: /* original fff7, guest PC 0x0c08a0ca */
if(!s->budget--) { s->failed_pc=0x0c08a0cau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0cc;
P_0c08a0cc: /* original e014, guest PC 0x0c08a0cc */
if(!s->budget--) { s->failed_pc=0x0c08a0ccu; return 0; }
r[0]=0x00000014u;
goto P_0c08a0ce;
P_0c08a0ce: /* original ff47, guest PC 0x0c08a0ce */
if(!s->budget--) { s->failed_pc=0x0c08a0ceu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08a0d0;
P_0c08a0d0: /* original e018, guest PC 0x0c08a0d0 */
if(!s->budget--) { s->failed_pc=0x0c08a0d0u; return 0; }
r[0]=0x00000018u;
goto P_0c08a0d2;
P_0c08a0d2: /* original fff7, guest PC 0x0c08a0d2 */
if(!s->budget--) { s->failed_pc=0x0c08a0d2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0d4;
P_0c08a0d4: /* original e020, guest PC 0x0c08a0d4 */
if(!s->budget--) { s->failed_pc=0x0c08a0d4u; return 0; }
r[0]=0x00000020u;
goto P_0c08a0d6;
P_0c08a0d6: /* original fff7, guest PC 0x0c08a0d6 */
if(!s->budget--) { s->failed_pc=0x0c08a0d6u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0d8;
P_0c08a0d8: /* original e024, guest PC 0x0c08a0d8 */
if(!s->budget--) { s->failed_pc=0x0c08a0d8u; return 0; }
r[0]=0x00000024u;
goto P_0c08a0da;
P_0c08a0da: /* original fff7, guest PC 0x0c08a0da */
if(!s->budget--) { s->failed_pc=0x0c08a0dau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0dc;
P_0c08a0dc: /* original e028, guest PC 0x0c08a0dc */
if(!s->budget--) { s->failed_pc=0x0c08a0dcu; return 0; }
r[0]=0x00000028u;
goto P_0c08a0de;
P_0c08a0de: /* original ff47, guest PC 0x0c08a0de */
if(!s->budget--) { s->failed_pc=0x0c08a0deu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08a0e0;
P_0c08a0e0: /* original d347, guest PC 0x0c08a0e0 */
if(!s->budget--) { s->failed_pc=0x0c08a0e0u; return 0; }
r[3]=read(ram,0x0c08a200u,4);
goto P_0c08a0e2;
P_0c08a0e2: /* original 430b, guest PC 0x0c08a0e2 */
if(!s->budget--) { s->failed_pc=0x0c08a0e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a0e6u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a0e6u) { target=s->pc; goto dispatch; }
goto P_0c08a0e6;
P_0c08a0e4: /* original 7410, guest PC 0x0c08a0e4 */
if(!s->budget--) { s->failed_pc=0x0c08a0e4u; return 0; }
r[4]+=0x00000010u;
goto P_0c08a0e6;
P_0c08a0e6: /* original c748, guest PC 0x0c08a0e6 */
if(!s->budget--) { s->failed_pc=0x0c08a0e6u; return 0; }
r[0]=code_base|0x0008a208u;
goto P_0c08a0e8;
P_0c08a0e8: /* original f5d8, guest PC 0x0c08a0e8 */
if(!s->budget--) { s->failed_pc=0x0c08a0e8u; return 0; }
vf3_matrix_load(s,ram,5,r[13]);
goto P_0c08a0ea;
P_0c08a0ea: /* original f708, guest PC 0x0c08a0ea */
if(!s->budget--) { s->failed_pc=0x0c08a0eau; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a0ec;
P_0c08a0ec: /* original c747, guest PC 0x0c08a0ec */
if(!s->budget--) { s->failed_pc=0x0c08a0ecu; return 0; }
r[0]=code_base|0x0008a20cu;
goto P_0c08a0ee;
P_0c08a0ee: /* original fb08, guest PC 0x0c08a0ee */
if(!s->budget--) { s->failed_pc=0x0c08a0eeu; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c08a0f0;
P_0c08a0f0: /* original c747, guest PC 0x0c08a0f0 */
if(!s->budget--) { s->failed_pc=0x0c08a0f0u; return 0; }
r[0]=code_base|0x0008a210u;
goto P_0c08a0f2;
P_0c08a0f2: /* original f808, guest PC 0x0c08a0f2 */
if(!s->budget--) { s->failed_pc=0x0c08a0f2u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08a0f4;
P_0c08a0f4: /* original c747, guest PC 0x0c08a0f4 */
if(!s->budget--) { s->failed_pc=0x0c08a0f4u; return 0; }
r[0]=code_base|0x0008a214u;
goto P_0c08a0f6;
P_0c08a0f6: /* original f908, guest PC 0x0c08a0f6 */
if(!s->budget--) { s->failed_pc=0x0c08a0f6u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a0f8;
P_0c08a0f8: /* original e300, guest PC 0x0c08a0f8 */
if(!s->budget--) { s->failed_pc=0x0c08a0f8u; return 0; }
r[3]=0x00000000u;
goto P_0c08a0fa;
P_0c08a0fa: /* original 9076, guest PC 0x0c08a0fa */
if(!s->budget--) { s->failed_pc=0x0c08a0fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1eau,2);
goto P_0c08a0fc;
P_0c08a0fc: /* original fa8c, guest PC 0x0c08a0fc */
if(!s->budget--) { s->failed_pc=0x0c08a0fcu; return 0; }
vf3_matrix_move(s,10,8);
goto P_0c08a0fe;
P_0c08a0fe: /* original f4fc, guest PC 0x0c08a0fe */
if(!s->budget--) { s->failed_pc=0x0c08a0feu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08a100;
P_0c08a100: /* original f54d, guest PC 0x0c08a100 */
if(!s->budget--) { s->failed_pc=0x0c08a100u; return 0; }
fr[5]^=0x80000000u;
goto P_0c08a102;
P_0c08a102: /* original f67c, guest PC 0x0c08a102 */
if(!s->budget--) { s->failed_pc=0x0c08a102u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c08a104;
P_0c08a104: /* original 0e35, guest PC 0x0c08a104 */
if(!s->budget--) { s->failed_pc=0x0c08a104u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08a106;
P_0c08a106: /* original e004, guest PC 0x0c08a106 */
if(!s->budget--) { s->failed_pc=0x0c08a106u; return 0; }
r[0]=0x00000004u;
goto P_0c08a108;
P_0c08a108: /* original feba, guest PC 0x0c08a108 */
if(!s->budget--) { s->failed_pc=0x0c08a108u; return 0; }
vf3_matrix_store(s,ram,11,r[14]);
goto P_0c08a10a;
P_0c08a10a: /* original fea7, guest PC 0x0c08a10a */
if(!s->budget--) { s->failed_pc=0x0c08a10au; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c08a10c;
P_0c08a10c: /* original e008, guest PC 0x0c08a10c */
if(!s->budget--) { s->failed_pc=0x0c08a10cu; return 0; }
r[0]=0x00000008u;
goto P_0c08a10e;
P_0c08a10e: /* original fe97, guest PC 0x0c08a10e */
if(!s->budget--) { s->failed_pc=0x0c08a10eu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c08a110;
P_0c08a110: /* original e00c, guest PC 0x0c08a110 */
if(!s->budget--) { s->failed_pc=0x0c08a110u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a112;
P_0c08a112: /* original fea7, guest PC 0x0c08a112 */
if(!s->budget--) { s->failed_pc=0x0c08a112u; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c08a114;
P_0c08a114: /* original e068, guest PC 0x0c08a114 */
if(!s->budget--) { s->failed_pc=0x0c08a114u; return 0; }
r[0]=0x00000068u;
goto P_0c08a116;
P_0c08a116: /* original fe47, guest PC 0x0c08a116 */
if(!s->budget--) { s->failed_pc=0x0c08a116u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a118;
P_0c08a118: /* original e06c, guest PC 0x0c08a118 */
if(!s->budget--) { s->failed_pc=0x0c08a118u; return 0; }
r[0]=0x0000006cu;
goto P_0c08a11a;
P_0c08a11a: /* original fe57, guest PC 0x0c08a11a */
if(!s->budget--) { s->failed_pc=0x0c08a11au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08a11c;
P_0c08a11c: /* original e070, guest PC 0x0c08a11c */
if(!s->budget--) { s->failed_pc=0x0c08a11cu; return 0; }
r[0]=0x00000070u;
goto P_0c08a11e;
P_0c08a11e: /* original fe47, guest PC 0x0c08a11e */
if(!s->budget--) { s->failed_pc=0x0c08a11eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a120;
P_0c08a120: /* original e074, guest PC 0x0c08a120 */
if(!s->budget--) { s->failed_pc=0x0c08a120u; return 0; }
r[0]=0x00000074u;
goto P_0c08a122;
P_0c08a122: /* original fe67, guest PC 0x0c08a122 */
if(!s->budget--) { s->failed_pc=0x0c08a122u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a124;
P_0c08a124: /* original e078, guest PC 0x0c08a124 */
if(!s->budget--) { s->failed_pc=0x0c08a124u; return 0; }
r[0]=0x00000078u;
goto P_0c08a126;
P_0c08a126: /* original fe67, guest PC 0x0c08a126 */
if(!s->budget--) { s->failed_pc=0x0c08a126u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a128;
P_0c08a128: /* original c73b, guest PC 0x0c08a128 */
if(!s->budget--) { s->failed_pc=0x0c08a128u; return 0; }
r[0]=code_base|0x0008a218u;
goto P_0c08a12a;
P_0c08a12a: /* original f508, guest PC 0x0c08a12a */
if(!s->budget--) { s->failed_pc=0x0c08a12au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08a12c;
P_0c08a12c: /* original c73b, guest PC 0x0c08a12c */
if(!s->budget--) { s->failed_pc=0x0c08a12cu; return 0; }
r[0]=code_base|0x0008a21cu;
goto P_0c08a12e;
P_0c08a12e: /* original f608, guest PC 0x0c08a12e */
if(!s->budget--) { s->failed_pc=0x0c08a12eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a130;
P_0c08a130: /* original c73b, guest PC 0x0c08a130 */
if(!s->budget--) { s->failed_pc=0x0c08a130u; return 0; }
r[0]=code_base|0x0008a220u;
goto P_0c08a132;
P_0c08a132: /* original f708, guest PC 0x0c08a132 */
if(!s->budget--) { s->failed_pc=0x0c08a132u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a134;
P_0c08a134: /* original e05c, guest PC 0x0c08a134 */
if(!s->budget--) { s->failed_pc=0x0c08a134u; return 0; }
r[0]=0x0000005cu;
goto P_0c08a136;
P_0c08a136: /* original fe47, guest PC 0x0c08a136 */
if(!s->budget--) { s->failed_pc=0x0c08a136u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a138;
P_0c08a138: /* original e060, guest PC 0x0c08a138 */
if(!s->budget--) { s->failed_pc=0x0c08a138u; return 0; }
r[0]=0x00000060u;
goto P_0c08a13a;
P_0c08a13a: /* original fe47, guest PC 0x0c08a13a */
if(!s->budget--) { s->failed_pc=0x0c08a13au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a13c;
P_0c08a13c: /* original e064, guest PC 0x0c08a13c */
if(!s->budget--) { s->failed_pc=0x0c08a13cu; return 0; }
r[0]=0x00000064u;
goto P_0c08a13e;
P_0c08a13e: /* original fe47, guest PC 0x0c08a13e */
if(!s->budget--) { s->failed_pc=0x0c08a13eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a140;
P_0c08a140: /* original e050, guest PC 0x0c08a140 */
if(!s->budget--) { s->failed_pc=0x0c08a140u; return 0; }
r[0]=0x00000050u;
goto P_0c08a142;
P_0c08a142: /* original fe57, guest PC 0x0c08a142 */
if(!s->budget--) { s->failed_pc=0x0c08a142u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08a144;
P_0c08a144: /* original e054, guest PC 0x0c08a144 */
if(!s->budget--) { s->failed_pc=0x0c08a144u; return 0; }
r[0]=0x00000054u;
goto P_0c08a146;
P_0c08a146: /* original fe67, guest PC 0x0c08a146 */
if(!s->budget--) { s->failed_pc=0x0c08a146u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a148;
P_0c08a148: /* original e058, guest PC 0x0c08a148 */
if(!s->budget--) { s->failed_pc=0x0c08a148u; return 0; }
r[0]=0x00000058u;
goto P_0c08a14a;
P_0c08a14a: /* original fe77, guest PC 0x0c08a14a */
if(!s->budget--) { s->failed_pc=0x0c08a14au; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08a14c;
P_0c08a14c: /* original e07c, guest PC 0x0c08a14c */
if(!s->budget--) { s->failed_pc=0x0c08a14cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08a14e;
P_0c08a14e: /* original fe47, guest PC 0x0c08a14e */
if(!s->budget--) { s->failed_pc=0x0c08a14eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a150;
P_0c08a150: /* original 7004, guest PC 0x0c08a150 */
if(!s->budget--) { s->failed_pc=0x0c08a150u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a152;
P_0c08a152: /* original fe47, guest PC 0x0c08a152 */
if(!s->budget--) { s->failed_pc=0x0c08a152u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a154;
P_0c08a154: /* original 7004, guest PC 0x0c08a154 */
if(!s->budget--) { s->failed_pc=0x0c08a154u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a156;
P_0c08a156: /* original fe47, guest PC 0x0c08a156 */
if(!s->budget--) { s->failed_pc=0x0c08a156u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a158;
P_0c08a158: /* original 7004, guest PC 0x0c08a158 */
if(!s->budget--) { s->failed_pc=0x0c08a158u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a15a;
P_0c08a15a: /* original fe47, guest PC 0x0c08a15a */
if(!s->budget--) { s->failed_pc=0x0c08a15au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a15c;
P_0c08a15c: /* original c731, guest PC 0x0c08a15c */
if(!s->budget--) { s->failed_pc=0x0c08a15cu; return 0; }
r[0]=code_base|0x0008a224u;
goto P_0c08a15e;
P_0c08a15e: /* original f808, guest PC 0x0c08a15e */
if(!s->budget--) { s->failed_pc=0x0c08a15eu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08a160;
P_0c08a160: /* original 9044, guest PC 0x0c08a160 */
if(!s->budget--) { s->failed_pc=0x0c08a160u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1ecu,2);
goto P_0c08a162;
P_0c08a162: /* original fe87, guest PC 0x0c08a162 */
if(!s->budget--) { s->failed_pc=0x0c08a162u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c08a164;
P_0c08a164: /* original 7004, guest PC 0x0c08a164 */
if(!s->budget--) { s->failed_pc=0x0c08a164u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a166;
P_0c08a166: /* original fe47, guest PC 0x0c08a166 */
if(!s->budget--) { s->failed_pc=0x0c08a166u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a168;
P_0c08a168: /* original c72f, guest PC 0x0c08a168 */
if(!s->budget--) { s->failed_pc=0x0c08a168u; return 0; }
r[0]=code_base|0x0008a228u;
goto P_0c08a16a;
P_0c08a16a: /* original 64c3, guest PC 0x0c08a16a */
if(!s->budget--) { s->failed_pc=0x0c08a16au; return 0; }
r[4]=r[12];
goto P_0c08a16c;
P_0c08a16c: /* original 7404, guest PC 0x0c08a16c */
if(!s->budget--) { s->failed_pc=0x0c08a16cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08a16e;
P_0c08a16e: /* original e310, guest PC 0x0c08a16e */
if(!s->budget--) { s->failed_pc=0x0c08a16eu; return 0; }
r[3]=0x00000010u;
goto P_0c08a170;
P_0c08a170: /* original 2c32, guest PC 0x0c08a170 */
if(!s->budget--) { s->failed_pc=0x0c08a170u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c08a172;
P_0c08a172: /* original f908, guest PC 0x0c08a172 */
if(!s->budget--) { s->failed_pc=0x0c08a172u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a174;
P_0c08a174: /* original c72d, guest PC 0x0c08a174 */
if(!s->budget--) { s->failed_pc=0x0c08a174u; return 0; }
r[0]=code_base|0x0008a22cu;
goto P_0c08a176;
P_0c08a176: /* original fa08, guest PC 0x0c08a176 */
if(!s->budget--) { s->failed_pc=0x0c08a176u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a178;
P_0c08a178: /* original c72d, guest PC 0x0c08a178 */
if(!s->budget--) { s->failed_pc=0x0c08a178u; return 0; }
r[0]=code_base|0x0008a230u;
goto P_0c08a17a;
P_0c08a17a: /* original f608, guest PC 0x0c08a17a */
if(!s->budget--) { s->failed_pc=0x0c08a17au; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a17c;
P_0c08a17c: /* original c72d, guest PC 0x0c08a17c */
if(!s->budget--) { s->failed_pc=0x0c08a17cu; return 0; }
r[0]=code_base|0x0008a234u;
goto P_0c08a17e;
P_0c08a17e: /* original f708, guest PC 0x0c08a17e */
if(!s->budget--) { s->failed_pc=0x0c08a17eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a180;
P_0c08a180: /* original c72d, guest PC 0x0c08a180 */
if(!s->budget--) { s->failed_pc=0x0c08a180u; return 0; }
r[0]=code_base|0x0008a238u;
goto P_0c08a182;
P_0c08a182: /* original f508, guest PC 0x0c08a182 */
if(!s->budget--) { s->failed_pc=0x0c08a182u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08a184;
P_0c08a184: /* original e004, guest PC 0x0c08a184 */
if(!s->budget--) { s->failed_pc=0x0c08a184u; return 0; }
r[0]=0x00000004u;
goto P_0c08a186;
P_0c08a186: /* original f49a, guest PC 0x0c08a186 */
if(!s->budget--) { s->failed_pc=0x0c08a186u; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c08a188;
P_0c08a188: /* original f457, guest PC 0x0c08a188 */
if(!s->budget--) { s->failed_pc=0x0c08a188u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a18a;
P_0c08a18a: /* original e008, guest PC 0x0c08a18a */
if(!s->budget--) { s->failed_pc=0x0c08a18au; return 0; }
r[0]=0x00000008u;
goto P_0c08a18c;
P_0c08a18c: /* original f447, guest PC 0x0c08a18c */
if(!s->budget--) { s->failed_pc=0x0c08a18cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a18e;
P_0c08a18e: /* original 740c, guest PC 0x0c08a18e */
if(!s->budget--) { s->failed_pc=0x0c08a18eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a190;
P_0c08a190: /* original e004, guest PC 0x0c08a190 */
if(!s->budget--) { s->failed_pc=0x0c08a190u; return 0; }
r[0]=0x00000004u;
goto P_0c08a192;
P_0c08a192: /* original f46a, guest PC 0x0c08a192 */
if(!s->budget--) { s->failed_pc=0x0c08a192u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a194;
P_0c08a194: /* original f457, guest PC 0x0c08a194 */
if(!s->budget--) { s->failed_pc=0x0c08a194u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a196;
P_0c08a196: /* original e008, guest PC 0x0c08a196 */
if(!s->budget--) { s->failed_pc=0x0c08a196u; return 0; }
r[0]=0x00000008u;
goto P_0c08a198;
P_0c08a198: /* original f467, guest PC 0x0c08a198 */
if(!s->budget--) { s->failed_pc=0x0c08a198u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a19a;
P_0c08a19a: /* original 740c, guest PC 0x0c08a19a */
if(!s->budget--) { s->failed_pc=0x0c08a19au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a19c;
P_0c08a19c: /* original e004, guest PC 0x0c08a19c */
if(!s->budget--) { s->failed_pc=0x0c08a19cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a19e;
P_0c08a19e: /* original f44a, guest PC 0x0c08a19e */
if(!s->budget--) { s->failed_pc=0x0c08a19eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a1a0;
P_0c08a1a0: /* original f457, guest PC 0x0c08a1a0 */
if(!s->budget--) { s->failed_pc=0x0c08a1a0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1a2;
P_0c08a1a2: /* original e008, guest PC 0x0c08a1a2 */
if(!s->budget--) { s->failed_pc=0x0c08a1a2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1a4;
P_0c08a1a4: /* original f497, guest PC 0x0c08a1a4 */
if(!s->budget--) { s->failed_pc=0x0c08a1a4u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08a1a6;
P_0c08a1a6: /* original e004, guest PC 0x0c08a1a6 */
if(!s->budget--) { s->failed_pc=0x0c08a1a6u; return 0; }
r[0]=0x00000004u;
goto P_0c08a1a8;
P_0c08a1a8: /* original 740c, guest PC 0x0c08a1a8 */
if(!s->budget--) { s->failed_pc=0x0c08a1a8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1aa;
P_0c08a1aa: /* original f47a, guest PC 0x0c08a1aa */
if(!s->budget--) { s->failed_pc=0x0c08a1aau; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a1ac;
P_0c08a1ac: /* original f457, guest PC 0x0c08a1ac */
if(!s->budget--) { s->failed_pc=0x0c08a1acu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1ae;
P_0c08a1ae: /* original e008, guest PC 0x0c08a1ae */
if(!s->budget--) { s->failed_pc=0x0c08a1aeu; return 0; }
r[0]=0x00000008u;
goto P_0c08a1b0;
P_0c08a1b0: /* original f467, guest PC 0x0c08a1b0 */
if(!s->budget--) { s->failed_pc=0x0c08a1b0u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a1b2;
P_0c08a1b2: /* original e004, guest PC 0x0c08a1b2 */
if(!s->budget--) { s->failed_pc=0x0c08a1b2u; return 0; }
r[0]=0x00000004u;
goto P_0c08a1b4;
P_0c08a1b4: /* original 740c, guest PC 0x0c08a1b4 */
if(!s->budget--) { s->failed_pc=0x0c08a1b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1b6;
P_0c08a1b6: /* original f4aa, guest PC 0x0c08a1b6 */
if(!s->budget--) { s->failed_pc=0x0c08a1b6u; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c08a1b8;
P_0c08a1b8: /* original f457, guest PC 0x0c08a1b8 */
if(!s->budget--) { s->failed_pc=0x0c08a1b8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1ba;
P_0c08a1ba: /* original e008, guest PC 0x0c08a1ba */
if(!s->budget--) { s->failed_pc=0x0c08a1bau; return 0; }
r[0]=0x00000008u;
goto P_0c08a1bc;
P_0c08a1bc: /* original f447, guest PC 0x0c08a1bc */
if(!s->budget--) { s->failed_pc=0x0c08a1bcu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a1be;
P_0c08a1be: /* original e004, guest PC 0x0c08a1be */
if(!s->budget--) { s->failed_pc=0x0c08a1beu; return 0; }
r[0]=0x00000004u;
goto P_0c08a1c0;
P_0c08a1c0: /* original 740c, guest PC 0x0c08a1c0 */
if(!s->budget--) { s->failed_pc=0x0c08a1c0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1c2;
P_0c08a1c2: /* original f47a, guest PC 0x0c08a1c2 */
if(!s->budget--) { s->failed_pc=0x0c08a1c2u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a1c4;
P_0c08a1c4: /* original f457, guest PC 0x0c08a1c4 */
if(!s->budget--) { s->failed_pc=0x0c08a1c4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1c6;
P_0c08a1c6: /* original e008, guest PC 0x0c08a1c6 */
if(!s->budget--) { s->failed_pc=0x0c08a1c6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1c8;
P_0c08a1c8: /* original f477, guest PC 0x0c08a1c8 */
if(!s->budget--) { s->failed_pc=0x0c08a1c8u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a1ca;
P_0c08a1ca: /* original e004, guest PC 0x0c08a1ca */
if(!s->budget--) { s->failed_pc=0x0c08a1cau; return 0; }
r[0]=0x00000004u;
goto P_0c08a1cc;
P_0c08a1cc: /* original 740c, guest PC 0x0c08a1cc */
if(!s->budget--) { s->failed_pc=0x0c08a1ccu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1ce;
P_0c08a1ce: /* original f44a, guest PC 0x0c08a1ce */
if(!s->budget--) { s->failed_pc=0x0c08a1ceu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a1d0;
P_0c08a1d0: /* original f457, guest PC 0x0c08a1d0 */
if(!s->budget--) { s->failed_pc=0x0c08a1d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1d2;
P_0c08a1d2: /* original e008, guest PC 0x0c08a1d2 */
if(!s->budget--) { s->failed_pc=0x0c08a1d2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1d4;
P_0c08a1d4: /* original f4a7, guest PC 0x0c08a1d4 */
if(!s->budget--) { s->failed_pc=0x0c08a1d4u; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08a1d6;
P_0c08a1d6: /* original 740c, guest PC 0x0c08a1d6 */
if(!s->budget--) { s->failed_pc=0x0c08a1d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1d8;
P_0c08a1d8: /* original f46a, guest PC 0x0c08a1d8 */
if(!s->budget--) { s->failed_pc=0x0c08a1d8u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a1da;
P_0c08a1da: /* original a02f, guest PC 0x0c08a1da */
if(!s->budget--) { s->failed_pc=0x0c08a1dau; return 0; }
goto P_0c08a23c;
P_0c08a1dc: /* original 0009, guest PC 0x0c08a1dc */
if(!s->budget--) { s->failed_pc=0x0c08a1dcu; return 0; }
if(!vf3_matrix_family(0x0c08a1deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a1deu; return 0; } return 1;
P_0c08a23c: /* original e004, guest PC 0x0c08a23c */
if(!s->budget--) { s->failed_pc=0x0c08a23cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a23e;
P_0c08a23e: /* original f457, guest PC 0x0c08a23e */
if(!s->budget--) { s->failed_pc=0x0c08a23eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a240;
P_0c08a240: /* original e008, guest PC 0x0c08a240 */
if(!s->budget--) { s->failed_pc=0x0c08a240u; return 0; }
r[0]=0x00000008u;
goto P_0c08a242;
P_0c08a242: /* original f477, guest PC 0x0c08a242 */
if(!s->budget--) { s->failed_pc=0x0c08a242u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a244;
P_0c08a244: /* original c751, guest PC 0x0c08a244 */
if(!s->budget--) { s->failed_pc=0x0c08a244u; return 0; }
r[0]=code_base|0x0008a38cu;
goto P_0c08a246;
P_0c08a246: /* original fa08, guest PC 0x0c08a246 */
if(!s->budget--) { s->failed_pc=0x0c08a246u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a248;
P_0c08a248: /* original c751, guest PC 0x0c08a248 */
if(!s->budget--) { s->failed_pc=0x0c08a248u; return 0; }
r[0]=code_base|0x0008a390u;
goto P_0c08a24a;
P_0c08a24a: /* original f908, guest PC 0x0c08a24a */
if(!s->budget--) { s->failed_pc=0x0c08a24au; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a24c;
P_0c08a24c: /* original c751, guest PC 0x0c08a24c */
if(!s->budget--) { s->failed_pc=0x0c08a24cu; return 0; }
r[0]=code_base|0x0008a394u;
goto P_0c08a24e;
P_0c08a24e: /* original f708, guest PC 0x0c08a24e */
if(!s->budget--) { s->failed_pc=0x0c08a24eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a250;
P_0c08a250: /* original c751, guest PC 0x0c08a250 */
if(!s->budget--) { s->failed_pc=0x0c08a250u; return 0; }
r[0]=code_base|0x0008a398u;
goto P_0c08a252;
P_0c08a252: /* original f608, guest PC 0x0c08a252 */
if(!s->budget--) { s->failed_pc=0x0c08a252u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a254;
P_0c08a254: /* original e004, guest PC 0x0c08a254 */
if(!s->budget--) { s->failed_pc=0x0c08a254u; return 0; }
r[0]=0x00000004u;
goto P_0c08a256;
P_0c08a256: /* original 740c, guest PC 0x0c08a256 */
if(!s->budget--) { s->failed_pc=0x0c08a256u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a258;
P_0c08a258: /* original f58c, guest PC 0x0c08a258 */
if(!s->budget--) { s->failed_pc=0x0c08a258u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c08a25a;
P_0c08a25a: /* original f4aa, guest PC 0x0c08a25a */
if(!s->budget--) { s->failed_pc=0x0c08a25au; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c08a25c;
P_0c08a25c: /* original f457, guest PC 0x0c08a25c */
if(!s->budget--) { s->failed_pc=0x0c08a25cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a25e;
P_0c08a25e: /* original e008, guest PC 0x0c08a25e */
if(!s->budget--) { s->failed_pc=0x0c08a25eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a260;
P_0c08a260: /* original f447, guest PC 0x0c08a260 */
if(!s->budget--) { s->failed_pc=0x0c08a260u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a262;
P_0c08a262: /* original e004, guest PC 0x0c08a262 */
if(!s->budget--) { s->failed_pc=0x0c08a262u; return 0; }
r[0]=0x00000004u;
goto P_0c08a264;
P_0c08a264: /* original 740c, guest PC 0x0c08a264 */
if(!s->budget--) { s->failed_pc=0x0c08a264u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a266;
P_0c08a266: /* original f47a, guest PC 0x0c08a266 */
if(!s->budget--) { s->failed_pc=0x0c08a266u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a268;
P_0c08a268: /* original f457, guest PC 0x0c08a268 */
if(!s->budget--) { s->failed_pc=0x0c08a268u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a26a;
P_0c08a26a: /* original e008, guest PC 0x0c08a26a */
if(!s->budget--) { s->failed_pc=0x0c08a26au; return 0; }
r[0]=0x00000008u;
goto P_0c08a26c;
P_0c08a26c: /* original f477, guest PC 0x0c08a26c */
if(!s->budget--) { s->failed_pc=0x0c08a26cu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a26e;
P_0c08a26e: /* original e004, guest PC 0x0c08a26e */
if(!s->budget--) { s->failed_pc=0x0c08a26eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a270;
P_0c08a270: /* original 740c, guest PC 0x0c08a270 */
if(!s->budget--) { s->failed_pc=0x0c08a270u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a272;
P_0c08a272: /* original f44a, guest PC 0x0c08a272 */
if(!s->budget--) { s->failed_pc=0x0c08a272u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a274;
P_0c08a274: /* original f457, guest PC 0x0c08a274 */
if(!s->budget--) { s->failed_pc=0x0c08a274u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a276;
P_0c08a276: /* original e008, guest PC 0x0c08a276 */
if(!s->budget--) { s->failed_pc=0x0c08a276u; return 0; }
r[0]=0x00000008u;
goto P_0c08a278;
P_0c08a278: /* original f4a7, guest PC 0x0c08a278 */
if(!s->budget--) { s->failed_pc=0x0c08a278u; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08a27a;
P_0c08a27a: /* original 740c, guest PC 0x0c08a27a */
if(!s->budget--) { s->failed_pc=0x0c08a27au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a27c;
P_0c08a27c: /* original e004, guest PC 0x0c08a27c */
if(!s->budget--) { s->failed_pc=0x0c08a27cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a27e;
P_0c08a27e: /* original f46a, guest PC 0x0c08a27e */
if(!s->budget--) { s->failed_pc=0x0c08a27eu; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a280;
P_0c08a280: /* original f457, guest PC 0x0c08a280 */
if(!s->budget--) { s->failed_pc=0x0c08a280u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a282;
P_0c08a282: /* original e008, guest PC 0x0c08a282 */
if(!s->budget--) { s->failed_pc=0x0c08a282u; return 0; }
r[0]=0x00000008u;
goto P_0c08a284;
P_0c08a284: /* original f477, guest PC 0x0c08a284 */
if(!s->budget--) { s->failed_pc=0x0c08a284u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a286;
P_0c08a286: /* original e004, guest PC 0x0c08a286 */
if(!s->budget--) { s->failed_pc=0x0c08a286u; return 0; }
r[0]=0x00000004u;
goto P_0c08a288;
P_0c08a288: /* original 740c, guest PC 0x0c08a288 */
if(!s->budget--) { s->failed_pc=0x0c08a288u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a28a;
P_0c08a28a: /* original f49a, guest PC 0x0c08a28a */
if(!s->budget--) { s->failed_pc=0x0c08a28au; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c08a28c;
P_0c08a28c: /* original f457, guest PC 0x0c08a28c */
if(!s->budget--) { s->failed_pc=0x0c08a28cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a28e;
P_0c08a28e: /* original e008, guest PC 0x0c08a28e */
if(!s->budget--) { s->failed_pc=0x0c08a28eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a290;
P_0c08a290: /* original f447, guest PC 0x0c08a290 */
if(!s->budget--) { s->failed_pc=0x0c08a290u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a292;
P_0c08a292: /* original e004, guest PC 0x0c08a292 */
if(!s->budget--) { s->failed_pc=0x0c08a292u; return 0; }
r[0]=0x00000004u;
goto P_0c08a294;
P_0c08a294: /* original 740c, guest PC 0x0c08a294 */
if(!s->budget--) { s->failed_pc=0x0c08a294u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a296;
P_0c08a296: /* original f46a, guest PC 0x0c08a296 */
if(!s->budget--) { s->failed_pc=0x0c08a296u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a298;
P_0c08a298: /* original f457, guest PC 0x0c08a298 */
if(!s->budget--) { s->failed_pc=0x0c08a298u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a29a;
P_0c08a29a: /* original e008, guest PC 0x0c08a29a */
if(!s->budget--) { s->failed_pc=0x0c08a29au; return 0; }
r[0]=0x00000008u;
goto P_0c08a29c;
P_0c08a29c: /* original f467, guest PC 0x0c08a29c */
if(!s->budget--) { s->failed_pc=0x0c08a29cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a29e;
P_0c08a29e: /* original e004, guest PC 0x0c08a29e */
if(!s->budget--) { s->failed_pc=0x0c08a29eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a2a0;
P_0c08a2a0: /* original 740c, guest PC 0x0c08a2a0 */
if(!s->budget--) { s->failed_pc=0x0c08a2a0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a2a2;
P_0c08a2a2: /* original f44a, guest PC 0x0c08a2a2 */
if(!s->budget--) { s->failed_pc=0x0c08a2a2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a2a4;
P_0c08a2a4: /* original f457, guest PC 0x0c08a2a4 */
if(!s->budget--) { s->failed_pc=0x0c08a2a4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a2a6;
P_0c08a2a6: /* original e008, guest PC 0x0c08a2a6 */
if(!s->budget--) { s->failed_pc=0x0c08a2a6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a2a8;
P_0c08a2a8: /* original f497, guest PC 0x0c08a2a8 */
if(!s->budget--) { s->failed_pc=0x0c08a2a8u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08a2aa;
P_0c08a2aa: /* original e004, guest PC 0x0c08a2aa */
if(!s->budget--) { s->failed_pc=0x0c08a2aau; return 0; }
r[0]=0x00000004u;
goto P_0c08a2ac;
P_0c08a2ac: /* original 740c, guest PC 0x0c08a2ac */
if(!s->budget--) { s->failed_pc=0x0c08a2acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a2ae;
P_0c08a2ae: /* original f47a, guest PC 0x0c08a2ae */
if(!s->budget--) { s->failed_pc=0x0c08a2aeu; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a2b0;
P_0c08a2b0: /* original f457, guest PC 0x0c08a2b0 */
if(!s->budget--) { s->failed_pc=0x0c08a2b0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a2b2;
P_0c08a2b2: /* original e008, guest PC 0x0c08a2b2 */
if(!s->budget--) { s->failed_pc=0x0c08a2b2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a2b4;
P_0c08a2b4: /* original f467, guest PC 0x0c08a2b4 */
if(!s->budget--) { s->failed_pc=0x0c08a2b4u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a2b6;
P_0c08a2b6: /* original d339, guest PC 0x0c08a2b6 */
if(!s->budget--) { s->failed_pc=0x0c08a2b6u; return 0; }
r[3]=read(ram,0x0c08a39cu,4);
goto P_0c08a2b8;
P_0c08a2b8: /* original 430b, guest PC 0x0c08a2b8 */
if(!s->budget--) { s->failed_pc=0x0c08a2b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a2bcu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a2bcu) { target=s->pc; goto dispatch; }
goto P_0c08a2bc;
P_0c08a2ba: /* original e401, guest PC 0x0c08a2ba */
if(!s->budget--) { s->failed_pc=0x0c08a2bau; return 0; }
r[4]=0x00000001u;
goto P_0c08a2bc;
P_0c08a2bc: /* original 7f40, guest PC 0x0c08a2bc */
if(!s->budget--) { s->failed_pc=0x0c08a2bcu; return 0; }
r[15]+=0x00000040u;
goto P_0c08a2be;
P_0c08a2be: /* original 4f26, guest PC 0x0c08a2be */
if(!s->budget--) { s->failed_pc=0x0c08a2beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a2c0;
P_0c08a2c0: /* original fff9, guest PC 0x0c08a2c0 */
if(!s->budget--) { s->failed_pc=0x0c08a2c0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a2c2;
P_0c08a2c2: /* original 6bf6, guest PC 0x0c08a2c2 */
if(!s->budget--) { s->failed_pc=0x0c08a2c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a2c4;
P_0c08a2c4: /* original 6cf6, guest PC 0x0c08a2c4 */
if(!s->budget--) { s->failed_pc=0x0c08a2c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a2c6;
P_0c08a2c6: /* original 6df6, guest PC 0x0c08a2c6 */
if(!s->budget--) { s->failed_pc=0x0c08a2c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a2c8;
P_0c08a2c8: /* original 000b, guest PC 0x0c08a2c8 */
if(!s->budget--) { s->failed_pc=0x0c08a2c8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a2ca: /* original 6ef6, guest PC 0x0c08a2ca */
if(!s->budget--) { s->failed_pc=0x0c08a2cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08a2ccu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
